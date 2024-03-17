// number of overlays (w/o fusion): 3 
// number of overlays (w/ fusion): 3 
#include <sys/time.h> 
#include <algorithm> 
#include <cstring> 
#include <fstream> 
#include <iomanip> 
#include <iostream> 
#include <sstream> 
#include <climits> 
#include <unordered_map> 
const int PU_NM = 8; 

#include "table_dt.hpp" 
#include "utils.hpp" 
#include "tpch_read_2.hpp" 
#include "gqe_api.hpp" 

#include "cfgFunc_q3.hpp" 
#include "q3.hpp" 

int main(int argc, const char* argv[]) { 
    std::cout << "\n------------ TPC-H Query Test -------------\n"; 
    ArgParser parser(argc, argv); 
    std::string xclbin_path; 
    if (!parser.getCmdOption("-xclbin", xclbin_path)) { 
        std::cout << "ERROR: xclbin path is not set!\n"; 
        return 1; 
    } 
    std::string xclbin_path_h; 
    if (!parser.getCmdOption("-xclbin_h", xclbin_path_h)) { 
        std::cout << "ERROR: xclbin_h path is not set!\n"; 
        return 1; 
    } 
    std::string xclbin_path_a; 
    if (!parser.getCmdOption("-xclbin_a", xclbin_path_a)) { 
        std::cout << "ERROR: xclbin_a path is not set!\n"; 
        return 1; 
    } 
    std::string in_dir; 
    if (!parser.getCmdOption("-in", in_dir) || !is_dir(in_dir)) { 
        std::cout << "ERROR: input dir is not specified or not valid.\n"; 
        return 1; 
    } 
    int num_rep = 1; 
    std::string num_str; 
    if (parser.getCmdOption("-rep", num_str)) { 
        try { 
            num_rep = std::stoi(num_str); 
        } catch (...) { 
            num_rep = 1; 
        } 
    } 
    if (num_rep > 20) { 
        num_rep = 20; 
        std::cout << "WARNING: limited repeat to " << num_rep << " times\n."; 
    } 
    int scale = 1; 
    std::string scale_str; 
    if (parser.getCmdOption("-c", scale_str)) { 
        try { 
            scale = std::stoi(scale_str); 
        } catch (...) { 
            scale = 1; 
        } 
    } 
    std::cout << "NOTE:running query #3\n."; 
    std::cout << "NOTE:running in sf" << scale << " data\n"; 

    int32_t lineitem_n = SF1_LINEITEM; 
    int32_t supplier_n = SF1_SUPPLIER; 
    int32_t nation_n = SF1_NATION; 
    int32_t order_n = SF1_ORDERS; 
    int32_t customer_n = SF1_CUSTOMER; 
    int32_t region_n = SF1_REGION; 
    int32_t part_n = SF1_PART; 
    int32_t partsupp_n = SF1_PARTSUPP; 
    if (scale == 30) { 
        lineitem_n = SF30_LINEITEM; 
        supplier_n = SF30_SUPPLIER; 
        nation_n = SF30_NATION; 
        order_n = SF30_ORDERS; 
        customer_n = SF30_CUSTOMER; 
        region_n = SF30_REGION; 
        part_n = SF30_PART; 
        partsupp_n = SF30_PARTSUPP; 
    } 
    // ********************************************************** // 
    // Get CL devices. 
    std::vector<cl::Device> devices = xcl::get_xil_devices(); 
    cl::Device device_h = devices[0]; 
    // Create context_h and command queue for selected device 
    cl::Context context_h(device_h); 
    cl::CommandQueue q_h(context_h, device_h, CL_QUEUE_PROFILING_ENABLE | CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE); 
    std::string devName_h = device_h.getInfo<CL_DEVICE_NAME>(); 
    std::cout << "Selected Device " << devName_h << "\n"; 
    cl::Program::Binaries xclBins_h = xcl::import_binary_file(xclbin_path_h); 
    std::vector<cl::Device> devices_h; 
    devices_h.push_back(device_h); 
    cl::Program program_h(context_h, devices_h, xclBins_h); 
    cl::Device device_a = devices[1]; 
    // Create context_a and command queue for selected device 
    cl::Context context_a(device_a); 
    cl::CommandQueue q_a(context_a, device_a, CL_QUEUE_PROFILING_ENABLE | CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE); 
    std::string devName_a = device_a.getInfo<CL_DEVICE_NAME>(); 
    std::cout << "Selected Device " << devName_a << "\n"; 
    cl::Program::Binaries xclBins_a = xcl::import_binary_file(xclbin_path_a); 
    std::vector<cl::Device> devices_a; 
    devices_a.push_back(device_a); 
    cl::Program program_a(context_a, devices_a, xclBins_a); 
    // *********************** Partition Infomation ********************* // 
    int hpTimes_join = 32; 
    int power_of_hpTimes_join = log2(hpTimes_join); 
    std::cout << "Number of partition (gqeJoin) is: " << hpTimes_join << std::endl; 
    int hpTimes_aggr = 256; 
    int power_of_hpTimes_aggr = log2(hpTimes_aggr); 
    std::cout << "Number of partition (gqeAggr) is: " << hpTimes_aggr << std::endl; 
    // ****************************** Tables **************************** // 
    Table tbl_Sort_TD_055_output("tbl_Sort_TD_055_output", 183000000, 4, "");
    tbl_Sort_TD_055_output.allocateHost();
    Table tbl_Aggregate_TD_148_output_preprocess("tbl_Aggregate_TD_148_output_preprocess", 24000, 16, "");
    tbl_Aggregate_TD_148_output_preprocess.allocateHost(1.2, hpTimes_aggr);
    
    Table tbl_Aggregate_TD_148_output("tbl_Aggregate_TD_148_output", 24000, 4, "");
    tbl_Aggregate_TD_148_output.allocateHost(1.2, hpTimes_aggr);

    Table tbl_Aggregate_TD_148_output_partition_array[hpTimes_aggr];
    for (int i(0); i < hpTimes_aggr; ++i) {
        tbl_Aggregate_TD_148_output_partition_array[i] = tbl_Aggregate_TD_148_output.createSubTable(i);
    }
    
    Table tbl_JOIN_INNER_TD_2844_output_preprocess("tbl_JOIN_INNER_TD_2844_output_preprocess", 30000, 5, "");
    tbl_JOIN_INNER_TD_2844_output_preprocess.allocateHost(1.2, hpTimes_join);
    

    Table tbl_JOIN_INNER_TD_2844_output("tbl_JOIN_INNER_TD_2844_output", 30000, 5, "");
    tbl_JOIN_INNER_TD_2844_output.allocateHost();

    Table tbl_JOIN_INNER_TD_2844_output_partition("tbl_JOIN_INNER_TD_2844_output_partition", 30000, 5, "");
    tbl_JOIN_INNER_TD_2844_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_JOIN_INNER_TD_2844_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_2844_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_2844_output_partition_array[i] = tbl_JOIN_INNER_TD_2844_output_partition.createSubTable(i);
    }


    Table tbl_Filter_TD_3339_output("tbl_Filter_TD_3339_output", 183000000, 3, "");
    tbl_Filter_TD_3339_output.allocateHost();

    Table tbl_Filter_TD_3339_output_partition("tbl_Filter_TD_3339_output_partition", 183000000, 3, "");
    tbl_Filter_TD_3339_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_Filter_TD_3339_output_partition.allocateDevBuffer(context_h, 32);

    Table tbl_Filter_TD_3339_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_3339_output_partition_array[i] = tbl_Filter_TD_3339_output_partition.createSubTable(i);
    }

    Table tbl_JOIN_INNER_TD_399_output("tbl_JOIN_INNER_TD_399_output", 150000, 3, "");
    tbl_JOIN_INNER_TD_399_output.allocateHost(1.2, hpTimes_join);

    Table tbl_SerializeFromObject_TD_4203_input;
    tbl_SerializeFromObject_TD_4203_input = Table("lineitem", lineitem_n, 4, in_dir);
    tbl_SerializeFromObject_TD_4203_input.addCol("l_orderkey", 4);
    tbl_SerializeFromObject_TD_4203_input.addCol("l_extendedprice", 4);
    tbl_SerializeFromObject_TD_4203_input.addCol("l_discount", 4);
    tbl_SerializeFromObject_TD_4203_input.addCol("l_shipdate", 4);
    tbl_SerializeFromObject_TD_4203_input.allocateHost();
    tbl_SerializeFromObject_TD_4203_input.loadHost();
    Table tbl_Filter_TD_4885_output("tbl_Filter_TD_4885_output", 183000000, 1, "");
    tbl_Filter_TD_4885_output.allocateHost();
    Table tbl_Filter_TD_4885_output_partition("tbl_Filter_TD_4885_output_partition", 183000000, 1, "");
    tbl_Filter_TD_4885_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_Filter_TD_4885_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_Filter_TD_4885_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_4885_output_partition_array[i] = tbl_Filter_TD_4885_output_partition.createSubTable(i);
    }
    Table tbl_Filter_TD_4223_output("tbl_Filter_TD_4223_output", 183000000, 4, "");
    tbl_Filter_TD_4223_output.allocateHost();
    Table tbl_Filter_TD_4223_output_partition("tbl_Filter_TD_4223_output_partition", 183000000, 4, "");
    tbl_Filter_TD_4223_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_Filter_TD_4223_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_Filter_TD_4223_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_4223_output_partition_array[i] = tbl_Filter_TD_4223_output_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_5464_input;
    tbl_SerializeFromObject_TD_5464_input = Table("customer", customer_n, 2, in_dir);
    tbl_SerializeFromObject_TD_5464_input.addCol("c_custkey", 4);
    tbl_SerializeFromObject_TD_5464_input.addCol("c_mktsegment", TPCH_READ_MAXAGG_LEN+1);
    tbl_SerializeFromObject_TD_5464_input.allocateHost();
    tbl_SerializeFromObject_TD_5464_input.loadHost();
    Table tbl_SerializeFromObject_TD_5776_input;
    tbl_SerializeFromObject_TD_5776_input = Table("order", order_n, 4, in_dir);
    tbl_SerializeFromObject_TD_5776_input.addCol("o_orderkey", 4);
    tbl_SerializeFromObject_TD_5776_input.addCol("o_custkey", 4);
    tbl_SerializeFromObject_TD_5776_input.addCol("o_orderdate", 4);
    tbl_SerializeFromObject_TD_5776_input.addCol("o_shippriority", 4);
    tbl_SerializeFromObject_TD_5776_input.allocateHost();
    tbl_SerializeFromObject_TD_5776_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_2844_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_148_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_JOIN_INNER_TD_2844_output_preprocess.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_2844_output_preprocess_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_2844_output_preprocess_partition_array[i] = tbl_JOIN_INNER_TD_2844_output_preprocess.createSubTable(i);
    }
    
    tbl_Filter_TD_3339_output.allocateDevBuffer(context_h, 33);
    tbl_JOIN_INNER_TD_399_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_399_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_399_output_partition_array[i] = tbl_JOIN_INNER_TD_399_output.createSubTable(i);
    }
    tbl_Filter_TD_4885_output.allocateDevBuffer(context_h, 33);
    tbl_Filter_TD_4223_output.allocateDevBuffer(context_h, 33);
    // ****************************** Config **************************** // 
    AggrCfgCmd cfg_Aggregate_TD_148_cmds;
    cfg_Aggregate_TD_148_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_148_gqe_aggr(cfg_Aggregate_TD_148_cmds.cmd);
    cfg_Aggregate_TD_148_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_148_cmds_out;
    cfg_Aggregate_TD_148_cmds_out.allocateHost();
    cfg_Aggregate_TD_148_cmds_out.allocateDevBuffer(context_a, 33);
    cfgCmd cfg_JOIN_INNER_TD_2844_cmds;
    cfg_JOIN_INNER_TD_2844_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_2844_gqe_join (cfg_JOIN_INNER_TD_2844_cmds.cmd);
    cfg_JOIN_INNER_TD_2844_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_2844_cmds_part;
    cfg_JOIN_INNER_TD_2844_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_2844_gqe_join_part (cfg_JOIN_INNER_TD_2844_cmds_part.cmd);
    cfg_JOIN_INNER_TD_2844_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_399_cmds;
    cfg_JOIN_INNER_TD_399_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_399_gqe_join (cfg_JOIN_INNER_TD_399_cmds.cmd);
    cfg_JOIN_INNER_TD_399_cmds.allocateDevBuffer(context_h, 32);

    cfgCmd cfg_Aggregate_TD_148_cmds_part;
    cfg_Aggregate_TD_148_cmds_part.allocateHost();
    get_cfg_dat_Aggregate_TD_148_gqe_aggr_part (cfg_Aggregate_TD_148_cmds_part.cmd);

    cfg_Aggregate_TD_148_cmds_part.allocateDevBuffer(context_a, 32);

    cfgCmd cfg_JOIN_INNER_TD_399_cmds_part;
    cfg_JOIN_INNER_TD_399_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_399_gqe_join_part (cfg_JOIN_INNER_TD_399_cmds_part.cmd);
    cfg_JOIN_INNER_TD_399_cmds_part.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    AggrBufferTmp buftmp_a(context_a); 
    buftmp_a.BufferInitial(q_a); 
    std::cout << std::endl; 
    AggrKrnlEngine krnl_Aggregate_TD_148_part;
    krnl_Aggregate_TD_148_part = AggrKrnlEngine(program_a, q_a, "gqePart");
    krnl_Aggregate_TD_148_part.setup_hp(512, 0, power_of_hpTimes_aggr, tbl_JOIN_INNER_TD_2844_output, tbl_JOIN_INNER_TD_2844_output_partition, cfg_Aggregate_TD_148_cmds_part);
    AggrKrnlEngine krnl_Aggregate_TD_148[hpTimes_aggr];
    for (int i = 0; i < hpTimes_aggr; i++) {
        krnl_Aggregate_TD_148[i] = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    }
    for (int i = 0; i < hpTimes_aggr; i++) {
        krnl_Aggregate_TD_148[i].setup(tbl_JOIN_INNER_TD_2844_output_partition_array[i], tbl_Aggregate_TD_148_output_partition_array[i], cfg_Aggregate_TD_148_cmds, cfg_Aggregate_TD_148_cmds_out, buftmp_a);
    }
    krnlEngine krnl_JOIN_INNER_TD_2844_part_right;
    krnl_JOIN_INNER_TD_2844_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_2844_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_Filter_TD_3339_output, tbl_Filter_TD_3339_output_partition, cfg_JOIN_INNER_TD_2844_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_2844[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_2844[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_2844[i].setup(tbl_JOIN_INNER_TD_399_output_partition_array[i], tbl_Filter_TD_3339_output_partition_array[i], tbl_JOIN_INNER_TD_2844_output_preprocess_partition_array[i], cfg_JOIN_INNER_TD_2844_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_INNER_TD_399_part_left;
    krnl_JOIN_INNER_TD_399_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_399_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_Filter_TD_4885_output, tbl_Filter_TD_4885_output_partition, cfg_JOIN_INNER_TD_399_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_399_part_right;
    krnl_JOIN_INNER_TD_399_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_399_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_Filter_TD_4223_output, tbl_Filter_TD_4223_output_partition, cfg_JOIN_INNER_TD_399_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_399[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_399[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_399[i].setup(tbl_Filter_TD_4885_output_partition_array[i], tbl_Filter_TD_4223_output_partition_array[i], tbl_JOIN_INNER_TD_399_output_partition_array[i], cfg_JOIN_INNER_TD_399_cmds, buftmp_h);
    }
    // ************************** Transfer Engine *********************** // 
    transEngine trans_Aggregate_TD_148;
    trans_Aggregate_TD_148.setq(q_a);
    trans_Aggregate_TD_148.add(&(cfg_Aggregate_TD_148_cmds_part));
    trans_Aggregate_TD_148.add(&(cfg_Aggregate_TD_148_cmds));
    transEngine trans_Aggregate_TD_148_out;
    trans_Aggregate_TD_148_out.setq(q_a);
    q_a.finish();
    transEngine trans_JOIN_INNER_TD_2844;
    trans_JOIN_INNER_TD_2844.setq(q_h);
    trans_JOIN_INNER_TD_2844.add(&(cfg_JOIN_INNER_TD_2844_cmds_part));
    trans_JOIN_INNER_TD_2844.add(&(cfg_JOIN_INNER_TD_2844_cmds));
    transEngine trans_JOIN_INNER_TD_2844_out;
    trans_JOIN_INNER_TD_2844_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_399;
    trans_JOIN_INNER_TD_399.setq(q_h);
    trans_JOIN_INNER_TD_399.add(&(cfg_JOIN_INNER_TD_399_cmds_part));
    trans_JOIN_INNER_TD_399.add(&(cfg_JOIN_INNER_TD_399_cmds));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_148;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_148;
    std::vector<cl::Event> events_Aggregate_TD_148[2];
    events_h2d_wr_Aggregate_TD_148.resize(1);
    events_d2h_rd_Aggregate_TD_148.resize(1);
    events_Aggregate_TD_148[0].resize(1);
    events_Aggregate_TD_148[1].resize(hpTimes_aggr);
    std::vector<cl::Event> events_grp_Aggregate_TD_148;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_148;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_2844;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_2844;
    std::vector<cl::Event> events_JOIN_INNER_TD_2844[2];
    events_h2d_wr_JOIN_INNER_TD_2844.resize(1);
    events_d2h_rd_JOIN_INNER_TD_2844.resize(1);
    events_JOIN_INNER_TD_2844[0].resize(1);
    events_JOIN_INNER_TD_2844[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_2844;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_2844;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_399;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_399;
    std::vector<cl::Event> events_JOIN_INNER_TD_399[2];
    events_h2d_wr_JOIN_INNER_TD_399.resize(1);
    events_d2h_rd_JOIN_INNER_TD_399.resize(1);
    events_JOIN_INNER_TD_399[0].resize(2);
    events_JOIN_INNER_TD_399[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_399;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_399;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_4_167_s, tv_r_Filter_4_167_e;
    gettimeofday(&tv_r_Filter_4_167_s, 0);
    SW_Filter_TD_4223(tbl_SerializeFromObject_TD_5776_input, tbl_Filter_TD_4223_output);
    gettimeofday(&tv_r_Filter_4_167_e, 0);

    struct timeval tv_r_Filter_4_746_s, tv_r_Filter_4_746_e;
    gettimeofday(&tv_r_Filter_4_746_s, 0);
    SW_Filter_TD_4885(tbl_SerializeFromObject_TD_5464_input, tbl_Filter_TD_4885_output);
    gettimeofday(&tv_r_Filter_4_746_e, 0);

    struct timeval tv_r_JOIN_INNER_3_381_s, tv_r_JOIN_INNER_3_381_e;
    gettimeofday(&tv_r_JOIN_INNER_3_381_s, 0);
    trans_JOIN_INNER_TD_399.add(&(tbl_Filter_TD_4885_output));
    trans_JOIN_INNER_TD_399.add(&(tbl_Filter_TD_4223_output));
    trans_JOIN_INNER_TD_399.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_399), &(events_h2d_wr_JOIN_INNER_TD_399[0]));
    events_grp_JOIN_INNER_TD_399.push_back(events_h2d_wr_JOIN_INNER_TD_399[0]);
    krnl_JOIN_INNER_TD_399_part_left.run(0, &(events_grp_JOIN_INNER_TD_399), &(events_JOIN_INNER_TD_399[0][0]));
    krnl_JOIN_INNER_TD_399_part_right.run(0, &(events_grp_JOIN_INNER_TD_399), &(events_JOIN_INNER_TD_399[0][1]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_399[i].run(0, &(events_JOIN_INNER_TD_399[0]), &(events_JOIN_INNER_TD_399[1][i]));
    }
    gettimeofday(&tv_r_JOIN_INNER_3_381_e, 0);

    struct timeval tv_r_Filter_3_607_s, tv_r_Filter_3_607_e;
    gettimeofday(&tv_r_Filter_3_607_s, 0);
    SW_Filter_TD_3339(tbl_SerializeFromObject_TD_4203_input, tbl_Filter_TD_3339_output);
    gettimeofday(&tv_r_Filter_3_607_e, 0);

    struct timeval tv_r_JOIN_INNER_2_139_s, tv_r_JOIN_INNER_2_139_e;
    gettimeofday(&tv_r_JOIN_INNER_2_139_s, 0);
    prev_events_grp_JOIN_INNER_TD_2844.push_back(events_h2d_wr_JOIN_INNER_TD_399[0]);
    trans_JOIN_INNER_TD_2844.add(&(tbl_Filter_TD_3339_output));
    trans_JOIN_INNER_TD_2844.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_2844), &(events_h2d_wr_JOIN_INNER_TD_2844[0]));
    events_grp_JOIN_INNER_TD_2844.push_back(events_h2d_wr_JOIN_INNER_TD_2844[0]);
    events_grp_JOIN_INNER_TD_2844.insert(std::end(events_grp_JOIN_INNER_TD_2844), std::begin(events_JOIN_INNER_TD_399[0]), std::end(events_JOIN_INNER_TD_399[0]));
    events_grp_JOIN_INNER_TD_2844.insert(std::end(events_grp_JOIN_INNER_TD_2844), std::begin(events_JOIN_INNER_TD_399[1]), std::end(events_JOIN_INNER_TD_399[1]));
    krnl_JOIN_INNER_TD_2844_part_right.run(0, &(events_grp_JOIN_INNER_TD_2844), &(events_JOIN_INNER_TD_2844[0][0]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_2844[i].run(0, &(events_grp_JOIN_INNER_TD_2844), &(events_JOIN_INNER_TD_2844[1][i]));
    }
    
    for (int i(0); i < hpTimes_join; ++i) {
        trans_JOIN_INNER_TD_2844_out.add(&(tbl_JOIN_INNER_TD_2844_output_preprocess_partition_array[i]));
    }
    trans_JOIN_INNER_TD_2844_out.dev2host(0, &(events_JOIN_INNER_TD_2844[1]), &(events_d2h_rd_JOIN_INNER_TD_2844[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_2844);
    tbl_JOIN_INNER_TD_2844_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_2844_output));
    gettimeofday(&tv_r_JOIN_INNER_2_139_e, 0);

    struct timeval tv_r_Aggregate_1_800_s, tv_r_Aggregate_1_800_e;
    gettimeofday(&tv_r_Aggregate_1_800_s, 0);
    trans_Aggregate_TD_148.add(&(tbl_JOIN_INNER_TD_2844_output));
    trans_Aggregate_TD_148.host2dev(0, &(prev_events_grp_Aggregate_TD_148), &(events_h2d_wr_Aggregate_TD_148[0]));
    events_grp_Aggregate_TD_148.push_back(events_h2d_wr_Aggregate_TD_148[0]);
    krnl_Aggregate_TD_148_part.run(0, &(events_grp_Aggregate_TD_148), &(events_Aggregate_TD_148[0][0]));
    for (int i(0); i < hpTimes_aggr; ++i) {
        krnl_Aggregate_TD_148[i].run(0, &(events_Aggregate_TD_148[0]), &(events_Aggregate_TD_148[1][i]));
    }
    
    for (int i(0); i < hpTimes_aggr; ++i) {
        trans_Aggregate_TD_148_out.add(&(tbl_Aggregate_TD_148_output_partition_array[i]));
    }
    trans_Aggregate_TD_148_out.dev2host(0, &(events_Aggregate_TD_148[1]), &(events_d2h_rd_Aggregate_TD_148[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_148_consolidate(tbl_Aggregate_TD_148_output_partition_array, tbl_Aggregate_TD_148_output, hpTimes_aggr);
    gettimeofday(&tv_r_Aggregate_1_800_e, 0);

    struct timeval tv_r_Sort_0_823_s, tv_r_Sort_0_823_e;
    gettimeofday(&tv_r_Sort_0_823_s, 0);
    SW_Sort_TD_055(tbl_Aggregate_TD_148_output, tbl_Sort_TD_055_output);
    gettimeofday(&tv_r_Sort_0_823_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_167_s, &tv_r_Filter_4_167_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5776_input: " << tbl_SerializeFromObject_TD_5776_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_746_s, &tv_r_Filter_4_746_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5464_input: " << tbl_SerializeFromObject_TD_5464_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_381_s, &tv_r_JOIN_INNER_3_381_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_4885_output: " << tbl_Filter_TD_4885_output.getNumRow() << " " << "tbl_Filter_TD_4223_output: " << tbl_Filter_TD_4223_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_607_s, &tv_r_Filter_3_607_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_4203_input: " << tbl_SerializeFromObject_TD_4203_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_2: " << tvdiff(&tv_r_JOIN_INNER_2_139_s, &tv_r_JOIN_INNER_2_139_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_3339_output: " << tbl_Filter_TD_3339_output.getNumRow() << " " << "tbl_JOIN_INNER_TD_399_output: " << tbl_JOIN_INNER_TD_399_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_800_s, &tv_r_Aggregate_1_800_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_2844_output: " << tbl_JOIN_INNER_TD_2844_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_823_s, &tv_r_Sort_0_823_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_148_output: " << tbl_Aggregate_TD_148_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 742.4076 * 1000 << "ms" << std::endl; 
    return 0; 
}
