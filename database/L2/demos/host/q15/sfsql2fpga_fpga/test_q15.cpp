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

#include "cfgFunc_q15.hpp" 
#include "q15.hpp" 

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
    std::cout << "NOTE:running query #15\n."; 
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
    Table tbl_Sort_TD_0471_output("tbl_Sort_TD_0471_output", 183000000, 5, "");
    tbl_Sort_TD_0471_output.allocateHost();
    
    Table tbl_JOIN_INNER_TD_191_output("tbl_JOIN_INNER_TD_191_output", -1, 5, "");
    tbl_JOIN_INNER_TD_191_output.allocateHost(1.2, hpTimes_join);
    Table tbl_SerializeFromObject_TD_2243_input_stringRowIDSubstitute;
    tbl_SerializeFromObject_TD_2243_input_stringRowIDSubstitute = Table("supplier", supplier_n, 4, in_dir);
    tbl_SerializeFromObject_TD_2243_input_stringRowIDSubstitute.addCol("s_suppkey", 4);
    tbl_SerializeFromObject_TD_2243_input_stringRowIDSubstitute.addCol("s_name", 4, 1, 0);
    tbl_SerializeFromObject_TD_2243_input_stringRowIDSubstitute.addCol("s_address", 4, 1, 0);
    tbl_SerializeFromObject_TD_2243_input_stringRowIDSubstitute.addCol("s_phone", 4, 1, 0);
    tbl_SerializeFromObject_TD_2243_input_stringRowIDSubstitute.allocateHost();
    tbl_SerializeFromObject_TD_2243_input_stringRowIDSubstitute.loadHost();
    Table tbl_SerializeFromObject_TD_2243_input_stringRowIDSubstitute_partition("tbl_SerializeFromObject_TD_2243_input_stringRowIDSubstitute_partition", supplier_n, 4, "");
    tbl_SerializeFromObject_TD_2243_input_stringRowIDSubstitute_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_2243_input_stringRowIDSubstitute_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_2243_input_stringRowIDSubstitute_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_2243_input_stringRowIDSubstitute_partition_array[i] = tbl_SerializeFromObject_TD_2243_input_stringRowIDSubstitute_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_2243_input;
    tbl_SerializeFromObject_TD_2243_input = Table("supplier", supplier_n, 4, in_dir);
    tbl_SerializeFromObject_TD_2243_input.addCol("s_suppkey", 4);
    tbl_SerializeFromObject_TD_2243_input.addCol("s_name", TPCH_READ_S_NAME_LEN+1);
    tbl_SerializeFromObject_TD_2243_input.addCol("s_address", TPCH_READ_S_ADDR_MAX+1);
    tbl_SerializeFromObject_TD_2243_input.addCol("s_phone", TPCH_READ_PHONE_LEN+1);
    tbl_SerializeFromObject_TD_2243_input.allocateHost();
    tbl_SerializeFromObject_TD_2243_input.loadHost();
    Table tbl_Filter_TD_2964_output("tbl_Filter_TD_2964_output", 183000000, 2, "");
    tbl_Filter_TD_2964_output.allocateHost();
    Table tbl_Filter_TD_2964_output_partition("tbl_Filter_TD_2964_output_partition", 183000000, 2, "");
    tbl_Filter_TD_2964_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_Filter_TD_2964_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_Filter_TD_2964_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_2964_output_partition_array[i] = tbl_Filter_TD_2964_output_partition.createSubTable(i);
    }
    Table tbl_Aggregate_TD_4225_output_preprocess("tbl_Aggregate_TD_4225_output_preprocess", -1, 16, "");
    tbl_Aggregate_TD_4225_output_preprocess.allocateHost(1.2, hpTimes_aggr);
    
    Table tbl_Aggregate_TD_4225_output("tbl_Aggregate_TD_4225_output", -1, 2, "");
    tbl_Aggregate_TD_4225_output.allocateHost();

    Table tbl_Aggregate_TD_4652_output("tbl_Aggregate_TD_4652_output", 183000000, 1, "");
    tbl_Aggregate_TD_4652_output.allocateHost();

    Table tbl_Aggregate_TD_5138_output_preprocess("tbl_Aggregate_TD_5138_output_preprocess", -1, 16, "");
    tbl_Aggregate_TD_5138_output_preprocess.allocateHost(1.2, hpTimes_aggr);

    Table tbl_Aggregate_TD_5138_output("tbl_Aggregate_TD_5138_output", -1, 1, "");
    tbl_Aggregate_TD_5138_output.allocateHost();

    Table tbl_Filter_TD_665_output("tbl_Filter_TD_665_output", 183000000, 3, "");
    tbl_Filter_TD_665_output.allocateHost();

    Table tbl_Filter_TD_665_output_partition("tbl_Filter_TD_665_output_partition", 183000000, 3, "");
    tbl_Filter_TD_665_output_partition.allocateHost(1.2, hpTimes_aggr);
    tbl_Filter_TD_665_output_partition.allocateDevBuffer(context_a, 32);
    Table tbl_Filter_TD_665_output_partition_array[hpTimes_aggr];
    for (int i(0); i < hpTimes_aggr; ++i) {
        tbl_Filter_TD_665_output_partition_array[i] = tbl_Filter_TD_665_output_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_7265_input;
    tbl_SerializeFromObject_TD_7265_input = Table("lineitem", lineitem_n, 4, in_dir);
    tbl_SerializeFromObject_TD_7265_input.addCol("l_suppkey", 4);
    tbl_SerializeFromObject_TD_7265_input.addCol("l_extendedprice", 4);
    tbl_SerializeFromObject_TD_7265_input.addCol("l_discount", 4);
    tbl_SerializeFromObject_TD_7265_input.addCol("l_shipdate", 4);
    tbl_SerializeFromObject_TD_7265_input.allocateHost();
    tbl_SerializeFromObject_TD_7265_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_191_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_191_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_191_output_partition_array[i] = tbl_JOIN_INNER_TD_191_output.createSubTable(i);
    }
    tbl_SerializeFromObject_TD_2243_input_stringRowIDSubstitute.allocateDevBuffer(context_h, 33);
    tbl_Filter_TD_2964_output.allocateDevBuffer(context_h, 33);
    tbl_Aggregate_TD_4225_output_preprocess.allocateDevBuffer(context_a, 33);
    Table tbl_Aggregate_TD_4225_output_partition_array[hpTimes_aggr];
    for (int i(0); i < hpTimes_aggr; ++i) {
        tbl_Aggregate_TD_4225_output_partition_array[i] = tbl_Aggregate_TD_4225_output_preprocess.createSubTable(i);
    }
    tbl_Aggregate_TD_5138_output_preprocess.allocateDevBuffer(context_a, 33);
    Table tbl_Aggregate_TD_5138_output_partition_array[hpTimes_aggr];
    for (int i(0); i < hpTimes_aggr; ++i) {
        tbl_Aggregate_TD_5138_output_partition_array[i] = tbl_Aggregate_TD_5138_output_preprocess.createSubTable(i);
    }
    tbl_Filter_TD_665_output.allocateDevBuffer(context_a, 33);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_191_cmds;
    cfg_JOIN_INNER_TD_191_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_191_gqe_join (cfg_JOIN_INNER_TD_191_cmds.cmd);
    cfg_JOIN_INNER_TD_191_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_191_cmds_part;
    cfg_JOIN_INNER_TD_191_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_191_gqe_join_part (cfg_JOIN_INNER_TD_191_cmds_part.cmd);
    cfg_JOIN_INNER_TD_191_cmds_part.allocateDevBuffer(context_h, 32);
    AggrCfgCmd cfg_Aggregate_TD_4225_cmds;
    cfg_Aggregate_TD_4225_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_4225_gqe_aggr(cfg_Aggregate_TD_4225_cmds.cmd);
    cfg_Aggregate_TD_4225_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_4225_cmds_out;
    cfg_Aggregate_TD_4225_cmds_out.allocateHost();
    cfg_Aggregate_TD_4225_cmds_out.allocateDevBuffer(context_a, 33);
    cfgCmd cfg_Aggregate_TD_4225_cmds_part;
    cfg_Aggregate_TD_4225_cmds_part.allocateHost();
    get_cfg_dat_Aggregate_TD_4225_gqe_aggr_part (cfg_Aggregate_TD_4225_cmds_part.cmd);
    cfg_Aggregate_TD_4225_cmds_part.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_5138_cmds;
    cfg_Aggregate_TD_5138_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_5138_gqe_aggr(cfg_Aggregate_TD_5138_cmds.cmd);
    cfg_Aggregate_TD_5138_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_5138_cmds_out;
    cfg_Aggregate_TD_5138_cmds_out.allocateHost();
    cfg_Aggregate_TD_5138_cmds_out.allocateDevBuffer(context_a, 33);
    cfgCmd cfg_Aggregate_TD_5138_cmds_part;
    cfg_Aggregate_TD_5138_cmds_part.allocateHost();
    get_cfg_dat_Aggregate_TD_5138_gqe_aggr_part (cfg_Aggregate_TD_5138_cmds_part.cmd);
    cfg_Aggregate_TD_5138_cmds_part.allocateDevBuffer(context_a, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    AggrBufferTmp buftmp_a(context_a); 
    buftmp_a.BufferInitial(q_a); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_191_part_left;
    krnl_JOIN_INNER_TD_191_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_191_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_SerializeFromObject_TD_2243_input_stringRowIDSubstitute, tbl_SerializeFromObject_TD_2243_input_stringRowIDSubstitute_partition, cfg_JOIN_INNER_TD_191_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_191_part_right;
    krnl_JOIN_INNER_TD_191_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_191_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_Filter_TD_2964_output, tbl_Filter_TD_2964_output_partition, cfg_JOIN_INNER_TD_191_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_191[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_191[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_191[i].setup(tbl_SerializeFromObject_TD_2243_input_stringRowIDSubstitute_partition_array[i], tbl_Filter_TD_2964_output_partition_array[i], tbl_JOIN_INNER_TD_191_output_partition_array[i], cfg_JOIN_INNER_TD_191_cmds, buftmp_h);
    }
    AggrKrnlEngine krnl_Aggregate_TD_4225_part;
    krnl_Aggregate_TD_4225_part = AggrKrnlEngine(program_a, q_a, "gqePart");
    krnl_Aggregate_TD_4225_part.setup_hp(512, 0, power_of_hpTimes_aggr, tbl_Filter_TD_665_output, tbl_Filter_TD_665_output_partition, cfg_Aggregate_TD_4225_cmds_part);
    AggrKrnlEngine krnl_Aggregate_TD_4225[hpTimes_aggr];
    for (int i = 0; i < hpTimes_aggr; i++) {
        krnl_Aggregate_TD_4225[i] = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    }
    for (int i = 0; i < hpTimes_aggr; i++) {
        krnl_Aggregate_TD_4225[i].setup(tbl_Filter_TD_665_output_partition_array[i], tbl_Aggregate_TD_4225_output_partition_array[i], cfg_Aggregate_TD_4225_cmds, cfg_Aggregate_TD_4225_cmds_out, buftmp_a);
    }
    AggrKrnlEngine krnl_Aggregate_TD_5138_part;
    krnl_Aggregate_TD_5138_part = AggrKrnlEngine(program_a, q_a, "gqePart");
    krnl_Aggregate_TD_5138_part.setup_hp(512, 0, power_of_hpTimes_aggr, tbl_Filter_TD_665_output, tbl_Filter_TD_665_output_partition, cfg_Aggregate_TD_5138_cmds_part);
    AggrKrnlEngine krnl_Aggregate_TD_5138[hpTimes_aggr];
    for (int i = 0; i < hpTimes_aggr; i++) {
        krnl_Aggregate_TD_5138[i] = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    }
    for (int i = 0; i < hpTimes_aggr; i++) {
        krnl_Aggregate_TD_5138[i].setup(tbl_Filter_TD_665_output_partition_array[i], tbl_Aggregate_TD_5138_output_partition_array[i], cfg_Aggregate_TD_5138_cmds, cfg_Aggregate_TD_5138_cmds_out, buftmp_a);
    }
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_191;
    trans_JOIN_INNER_TD_191.setq(q_h);
    trans_JOIN_INNER_TD_191.add(&(cfg_JOIN_INNER_TD_191_cmds_part));
    trans_JOIN_INNER_TD_191.add(&(cfg_JOIN_INNER_TD_191_cmds));
    trans_JOIN_INNER_TD_191.add(&(tbl_SerializeFromObject_TD_2243_input_stringRowIDSubstitute));
    transEngine trans_JOIN_INNER_TD_191_out;
    trans_JOIN_INNER_TD_191_out.setq(q_h);
    q_h.finish();
    transEngine trans_Aggregate_TD_4225;
    trans_Aggregate_TD_4225.setq(q_a);
    trans_Aggregate_TD_4225.add(&(cfg_Aggregate_TD_4225_cmds_part));
    trans_Aggregate_TD_4225.add(&(cfg_Aggregate_TD_4225_cmds));
    transEngine trans_Aggregate_TD_4225_out;
    trans_Aggregate_TD_4225_out.setq(q_a);
    q_a.finish();
    transEngine trans_Aggregate_TD_5138;
    trans_Aggregate_TD_5138.setq(q_a);
    trans_Aggregate_TD_5138.add(&(cfg_Aggregate_TD_5138_cmds_part));
    trans_Aggregate_TD_5138.add(&(cfg_Aggregate_TD_5138_cmds));
    transEngine trans_Aggregate_TD_5138_out;
    trans_Aggregate_TD_5138_out.setq(q_a);
    q_a.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_191;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_191;
    std::vector<cl::Event> events_JOIN_INNER_TD_191[2];
    events_h2d_wr_JOIN_INNER_TD_191.resize(1);
    events_d2h_rd_JOIN_INNER_TD_191.resize(1);
    events_JOIN_INNER_TD_191[0].resize(2);
    events_JOIN_INNER_TD_191[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_191;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_191;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_4225;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_4225;
    std::vector<cl::Event> events_Aggregate_TD_4225[2];
    events_h2d_wr_Aggregate_TD_4225.resize(1);
    events_d2h_rd_Aggregate_TD_4225.resize(1);
    events_Aggregate_TD_4225[0].resize(1);
    events_Aggregate_TD_4225[1].resize(hpTimes_aggr);
    std::vector<cl::Event> events_grp_Aggregate_TD_4225;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_4225;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_5138;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_5138;
    std::vector<cl::Event> events_Aggregate_TD_5138[2];
    events_h2d_wr_Aggregate_TD_5138.resize(1);
    events_d2h_rd_Aggregate_TD_5138.resize(1);
    events_Aggregate_TD_5138[0].resize(1);
    events_Aggregate_TD_5138[1].resize(hpTimes_aggr);
    std::vector<cl::Event> events_grp_Aggregate_TD_5138;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_5138;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_6_786_s, tv_r_Filter_6_786_e;
    gettimeofday(&tv_r_Filter_6_786_s, 0);
    SW_Filter_TD_665(tbl_SerializeFromObject_TD_7265_input, tbl_Filter_TD_665_output);
    gettimeofday(&tv_r_Filter_6_786_e, 0);

    struct timeval tv_r_Aggregate_5_895_s, tv_r_Aggregate_5_895_e;
    gettimeofday(&tv_r_Aggregate_5_895_s, 0);
    trans_Aggregate_TD_5138.add(&(tbl_Filter_TD_665_output));
    trans_Aggregate_TD_5138.host2dev(0, &(prev_events_grp_Aggregate_TD_5138), &(events_h2d_wr_Aggregate_TD_5138[0]));
    events_grp_Aggregate_TD_5138.push_back(events_h2d_wr_Aggregate_TD_5138[0]);
    krnl_Aggregate_TD_5138_part.run(0, &(events_grp_Aggregate_TD_5138), &(events_Aggregate_TD_5138[0][0]));
    for (int i(0); i < hpTimes_aggr; ++i) {
        krnl_Aggregate_TD_5138[i].run(0, &(events_Aggregate_TD_5138[0]), &(events_Aggregate_TD_5138[1][i]));
    }
    
    for (int i(0); i < hpTimes_aggr; ++i) {
        trans_Aggregate_TD_5138_out.add(&(tbl_Aggregate_TD_5138_output_partition_array[i]));
    }
    trans_Aggregate_TD_5138_out.dev2host(0, &(events_Aggregate_TD_5138[1]), &(events_d2h_rd_Aggregate_TD_5138[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_5138_consolidate(tbl_Aggregate_TD_5138_output_partition_array, tbl_Aggregate_TD_5138_output, hpTimes_aggr);
    gettimeofday(&tv_r_Aggregate_5_895_e, 0);

    struct timeval tv_r_Aggregate_4_716_s, tv_r_Aggregate_4_716_e;
    gettimeofday(&tv_r_Aggregate_4_716_s, 0);
    SW_Aggregate_TD_4652(tbl_Aggregate_TD_5138_output, tbl_Aggregate_TD_4652_output);
    gettimeofday(&tv_r_Aggregate_4_716_e, 0);

    struct timeval tv_r_Aggregate_4_923_s, tv_r_Aggregate_4_923_e;
    gettimeofday(&tv_r_Aggregate_4_923_s, 0);
    trans_Aggregate_TD_4225.add(&(tbl_Filter_TD_665_output));
    trans_Aggregate_TD_4225.host2dev(0, &(prev_events_grp_Aggregate_TD_4225), &(events_h2d_wr_Aggregate_TD_4225[0]));
    events_grp_Aggregate_TD_4225.push_back(events_h2d_wr_Aggregate_TD_4225[0]);
    krnl_Aggregate_TD_4225_part.run(0, &(events_grp_Aggregate_TD_4225), &(events_Aggregate_TD_4225[0][0]));
    for (int i(0); i < hpTimes_aggr; ++i) {
        krnl_Aggregate_TD_4225[i].run(0, &(events_Aggregate_TD_4225[0]), &(events_Aggregate_TD_4225[1][i]));
    }
    
    for (int i(0); i < hpTimes_aggr; ++i) {
        trans_Aggregate_TD_4225_out.add(&(tbl_Aggregate_TD_4225_output_partition_array[i]));
    }
    trans_Aggregate_TD_4225_out.dev2host(0, &(events_Aggregate_TD_4225[1]), &(events_d2h_rd_Aggregate_TD_4225[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_4225_consolidate(tbl_Aggregate_TD_4225_output_partition_array, tbl_Aggregate_TD_4225_output, hpTimes_aggr);
    gettimeofday(&tv_r_Aggregate_4_923_e, 0);

    struct timeval tv_r_Filter_2_451_s, tv_r_Filter_2_451_e;
    gettimeofday(&tv_r_Filter_2_451_s, 0);
    SW_Filter_TD_2964(tbl_Aggregate_TD_4225_output, tbl_Aggregate_TD_4652_output, tbl_Filter_TD_2964_output);
    gettimeofday(&tv_r_Filter_2_451_e, 0);

    struct timeval tv_r_JOIN_INNER_1_367_s, tv_r_JOIN_INNER_1_367_e;
    gettimeofday(&tv_r_JOIN_INNER_1_367_s, 0);
    trans_JOIN_INNER_TD_191.add(&(tbl_Filter_TD_2964_output));
    trans_JOIN_INNER_TD_191.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_191), &(events_h2d_wr_JOIN_INNER_TD_191[0]));
    events_grp_JOIN_INNER_TD_191.push_back(events_h2d_wr_JOIN_INNER_TD_191[0]);
    krnl_JOIN_INNER_TD_191_part_left.run(0, &(events_grp_JOIN_INNER_TD_191), &(events_JOIN_INNER_TD_191[0][0]));
    krnl_JOIN_INNER_TD_191_part_right.run(0, &(events_grp_JOIN_INNER_TD_191), &(events_JOIN_INNER_TD_191[0][1]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_191[i].run(0, &(events_JOIN_INNER_TD_191[0]), &(events_JOIN_INNER_TD_191[1][i]));
    }
    
    for (int i(0); i < hpTimes_join; ++i) {
        trans_JOIN_INNER_TD_191_out.add(&(tbl_JOIN_INNER_TD_191_output_partition_array[i]));
    }
    trans_JOIN_INNER_TD_191_out.dev2host(0, &(events_JOIN_INNER_TD_191[1]), &(events_d2h_rd_JOIN_INNER_TD_191[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_1_367_e, 0);

    struct timeval tv_r_Sort_0_716_s, tv_r_Sort_0_716_e;
    gettimeofday(&tv_r_Sort_0_716_s, 0);
    SW_Sort_TD_0471(tbl_JOIN_INNER_TD_191_output_partition_array, tbl_SerializeFromObject_TD_2243_input, tbl_Sort_TD_0471_output, hpTimes_join);
    gettimeofday(&tv_r_Sort_0_716_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_786_s, &tv_r_Filter_6_786_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7265_input: " << tbl_SerializeFromObject_TD_7265_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_895_s, &tv_r_Aggregate_5_895_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_665_output: " << tbl_Filter_TD_665_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_4: " << tvdiff(&tv_r_Aggregate_4_716_s, &tv_r_Aggregate_4_716_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_5138_output: " << tbl_Aggregate_TD_5138_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_4: " << tvdiff(&tv_r_Aggregate_4_923_s, &tv_r_Aggregate_4_923_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_665_output: " << tbl_Filter_TD_665_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_451_s, &tv_r_Filter_2_451_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_4225_output: " << tbl_Aggregate_TD_4225_output.getNumRow() << " " << "tbl_Aggregate_TD_4652_output: " << tbl_Aggregate_TD_4652_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_1: " << tvdiff(&tv_r_JOIN_INNER_1_367_s, &tv_r_JOIN_INNER_1_367_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_2243_input_stringRowIDSubstitute: " << tbl_SerializeFromObject_TD_2243_input_stringRowIDSubstitute.getNumRow() << " " << "tbl_Filter_TD_2964_output: " << tbl_Filter_TD_2964_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_716_s, &tv_r_Sort_0_716_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_191_output: " << tbl_JOIN_INNER_TD_191_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 602.79846 * 1000 << "ms" << std::endl; 
    return 0; 
}
