// number of overlays (w/o fusion): 4 
// number of overlays (w/ fusion): 4 
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

#include "cfgFunc_q13.hpp" 
#include "q13.hpp" 

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
    std::cout << "NOTE:running query #13\n."; 
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
    Table tbl_Sort_TD_0399_output("tbl_Sort_TD_0399_output", 183000000, 2, "");
    tbl_Sort_TD_0399_output.allocateHost();

    Table tbl_Aggregate_TD_1543_output_preprocess("tbl_Aggregate_TD_1543_output_preprocess", -1, 16, "");
    tbl_Aggregate_TD_1543_output_preprocess.allocateHost(1.2, hpTimes_aggr);
    
    Table tbl_Aggregate_TD_1543_output("tbl_Aggregate_TD_1543_output", -1, 2, "");
    tbl_Aggregate_TD_1543_output.allocateHost();

    Table tbl_Aggregate_TD_1543_output_partition_array[hpTimes_aggr];
    for (int i(0); i < hpTimes_aggr; ++i) {
        tbl_Aggregate_TD_1543_output_partition_array[i] = tbl_Aggregate_TD_1543_output_preprocess.createSubTable(i);
    }

    Table tbl_Aggregate_TD_212_output_preprocess("tbl_Aggregate_TD_212_output_preprocess", -1, 16, "");
    tbl_Aggregate_TD_212_output_preprocess.allocateHost();
    
    Table tbl_Aggregate_TD_212_output("tbl_Aggregate_TD_212_output", -1, 1, "");
    tbl_Aggregate_TD_212_output.allocateHost();
    
    Table tbl_Aggregate_TD_212_output_partition("tbl_Aggregate_TD_212_output_partition", -1, 16, "");
    tbl_Aggregate_TD_212_output_partition.allocateHost(1.2, hpTimes_aggr);

    Table tbl_Aggregate_TD_212_output_partition_array[hpTimes_aggr];
    for (int i(0); i < hpTimes_aggr; ++i) {
        tbl_Aggregate_TD_212_output_partition_array[i] = tbl_Aggregate_TD_212_output_partition.createSubTable(i);
    }

    Table tbl_JOIN_INNER_TD_0152_output("tbl_JOIN_INNER_TD_0152_output", 1480133, 3, "");
    tbl_JOIN_INNER_TD_0152_output.allocateHost(1.2, hpTimes_join);
    
    Table tbl_JOIN_INNER_TD_0152_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_0152_output_partition_array[i] = tbl_JOIN_INNER_TD_0152_output.createSubTable(i);
    }

    Table tbl_JOIN_LEFTANTI_TD_3550_output_preprocess("tbl_JOIN_LEFTANTI_TD_3550_output_preprocess", 1531000, 2, "");
    tbl_JOIN_LEFTANTI_TD_3550_output_preprocess.allocateHost();
    Table tbl_JOIN_LEFTANTI_TD_3550_output_preprocess_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_LEFTANTI_TD_3550_output_preprocess_partition_array[i] = tbl_JOIN_LEFTANTI_TD_3550_output_preprocess.createSubTable(i);
    }

    Table tbl_JOIN_LEFTANTI_TD_3550_output("tbl_JOIN_LEFTANTI_TD_3550_output", 1531000, 2, "");
    tbl_JOIN_LEFTANTI_TD_3550_output.allocateHost();
    
    Table tbl_JOIN_LEFTANTI_TD_3550_output_partition("tbl_JOIN_LEFTANTI_TD_3550_output_partition", 1531000, 2, "");
    tbl_JOIN_LEFTANTI_TD_3550_output_partition.allocateHost(1.2, hpTimes_join);
    
    Table tbl_JOIN_LEFTANTI_TD_3550_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_LEFTANTI_TD_3550_output_partition_array[i] = tbl_JOIN_LEFTANTI_TD_3550_output_partition.createSubTable(i);
    }


    Table tbl_SerializeFromObject_TD_4109_input;
    tbl_SerializeFromObject_TD_4109_input = Table("customer", customer_n, 1, in_dir);
    tbl_SerializeFromObject_TD_4109_input.addCol("c_custkey", 4);
    tbl_SerializeFromObject_TD_4109_input.allocateHost();
    tbl_SerializeFromObject_TD_4109_input.loadHost();

    Table tbl_SerializeFromObject_TD_4109_input_partition("tbl_SerializeFromObject_TD_4109_input_partition", customer_n, 1, "");
    tbl_SerializeFromObject_TD_4109_input_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_4109_input_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_4109_input_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_4109_input_partition_array[i] = tbl_SerializeFromObject_TD_4109_input_partition.createSubTable(i);
    }

    Table tbl_Filter_TD_4876_output("tbl_Filter_TD_4876_output", 183000000, 2, "");
    tbl_Filter_TD_4876_output.allocateHost();
    
    Table tbl_Filter_TD_4876_output_partition("tbl_Filter_TD_4876_output_partition", 183000000, 2, "");
    tbl_Filter_TD_4876_output_partition.allocateHost(1.2, hpTimes_join);
    
    Table tbl_Filter_TD_4876_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_4876_output_partition_array[i] = tbl_Filter_TD_4876_output_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_5101_input;
    tbl_SerializeFromObject_TD_5101_input = Table("order", order_n, 3, in_dir);
    tbl_SerializeFromObject_TD_5101_input.addCol("o_orderkey", 4);
    tbl_SerializeFromObject_TD_5101_input.addCol("o_custkey", 4);
    tbl_SerializeFromObject_TD_5101_input.addCol("o_comment", TPCH_READ_O_CMNT_MAX+1);
    tbl_SerializeFromObject_TD_5101_input.allocateHost();
    tbl_SerializeFromObject_TD_5101_input.loadHost();


    // ********************** Allocate Device Buffer ******************** // 
    tbl_Sort_TD_0399_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTANTI_TD_3550_output_partition.allocateDevBuffer(context_h, 32);
    tbl_Aggregate_TD_1543_output_preprocess.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_212_output_preprocess.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_212_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_212_output_partition.allocateDevBuffer(context_a, 32);
    tbl_JOIN_LEFTANTI_TD_3550_output.allocateDevBuffer(context_a, 32);        
    tbl_JOIN_LEFTANTI_TD_3550_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_0152_output.allocateDevBuffer(context_h, 32);
    tbl_SerializeFromObject_TD_5101_input.allocateDevBuffer(context_h, 33);
    tbl_SerializeFromObject_TD_4109_input.allocateDevBuffer(context_h, 33);
    tbl_SerializeFromObject_TD_4109_input_partition.allocateDevBuffer(context_h, 33);
    tbl_Filter_TD_4876_output.allocateDevBuffer(context_h, 33);
    tbl_Filter_TD_4876_output_partition.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    AggrCfgCmd cfg_Aggregate_TD_1543_cmds;
    cfg_Aggregate_TD_1543_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_1543_gqe_aggr(cfg_Aggregate_TD_1543_cmds.cmd);
    cfg_Aggregate_TD_1543_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_1543_cmds_out;
    cfg_Aggregate_TD_1543_cmds_out.allocateHost();
    cfg_Aggregate_TD_1543_cmds_out.allocateDevBuffer(context_a, 33);
    AggrCfgCmd cfg_Aggregate_TD_212_cmds;
    cfg_Aggregate_TD_212_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_212_gqe_aggr(cfg_Aggregate_TD_212_cmds.cmd);
    cfg_Aggregate_TD_212_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_212_cmds_out;
    cfg_Aggregate_TD_212_cmds_out.allocateHost();
    cfg_Aggregate_TD_212_cmds_out.allocateDevBuffer(context_a, 33);
    cfgCmd cfg_JOIN_LEFTANTI_TD_3550_cmds;
    cfg_JOIN_LEFTANTI_TD_3550_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTANTI_TD_3550_gqe_join (cfg_JOIN_LEFTANTI_TD_3550_cmds.cmd);
    cfg_JOIN_LEFTANTI_TD_3550_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTANTI_TD_3550_cmds_part;
    cfg_JOIN_LEFTANTI_TD_3550_cmds_part.allocateHost();
    get_cfg_dat_JOIN_LEFTANTI_TD_3550_gqe_join_part (cfg_JOIN_LEFTANTI_TD_3550_cmds_part.cmd);
    cfg_JOIN_LEFTANTI_TD_3550_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_0152_cmds;
    cfg_JOIN_INNER_TD_0152_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_0152_gqe_join (cfg_JOIN_INNER_TD_0152_cmds.cmd);
    cfg_JOIN_INNER_TD_0152_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_0152_cmds_part;
    cfg_JOIN_INNER_TD_0152_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_0152_gqe_join_part (cfg_JOIN_INNER_TD_0152_cmds_part.cmd);
    cfg_JOIN_INNER_TD_0152_cmds_part.allocateDevBuffer(context_h, 32);

    cfgCmd cfg_Aggregate_TD_212_cmds_part;
    cfg_Aggregate_TD_212_cmds_part.allocateHost();
    get_cfg_dat_Aggregate_TD_212_gqe_aggr_part (cfg_Aggregate_TD_212_cmds_part.cmd);
    cfg_Aggregate_TD_212_cmds_part.allocateDevBuffer(context_a, 32);

    cfgCmd cfg_Aggregate_TD_1543_cmds_part;
    cfg_Aggregate_TD_1543_cmds_part.allocateHost();
    get_cfg_dat_Aggregate_TD_1543_gqe_aggr_part (cfg_Aggregate_TD_1543_cmds_part.cmd);
    cfg_Aggregate_TD_1543_cmds_part.allocateDevBuffer(context_a, 32);


    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    AggrBufferTmp buftmp_a(context_a); 
    buftmp_a.BufferInitial(q_a); 
    std::cout << std::endl; 
    AggrKrnlEngine krnl_Aggregate_TD_1543_part;
    krnl_Aggregate_TD_1543_part = AggrKrnlEngine(program_a, q_a, "gqePart");
    krnl_Aggregate_TD_1543_part.setup_hp(512, 0, power_of_hpTimes_aggr, tbl_Aggregate_TD_212_output, tbl_Aggregate_TD_212_output_partition, cfg_Aggregate_TD_1543_cmds_part);
    AggrKrnlEngine krnl_Aggregate_TD_1543[hpTimes_aggr];
    for (int i = 0; i < hpTimes_aggr; i++) {
        krnl_Aggregate_TD_1543[i] = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    }
    for (int i = 0; i < hpTimes_aggr; i++) {
        krnl_Aggregate_TD_1543[i].setup(tbl_Aggregate_TD_212_output_partition_array[i], tbl_Aggregate_TD_1543_output_partition_array[i], cfg_Aggregate_TD_1543_cmds, cfg_Aggregate_TD_1543_cmds_out, buftmp_a);
    }
    AggrKrnlEngine krnl_Aggregate_TD_212_part;
    krnl_Aggregate_TD_212_part = AggrKrnlEngine(program_a, q_a, "gqePart");
    krnl_Aggregate_TD_212_part.setup_hp(512, 0, power_of_hpTimes_aggr, tbl_JOIN_LEFTANTI_TD_3550_output, tbl_JOIN_LEFTANTI_TD_3550_output_partition, cfg_Aggregate_TD_212_cmds_part);
    AggrKrnlEngine krnl_Aggregate_TD_212[hpTimes_aggr];
    for (int i = 0; i < hpTimes_aggr; i++) {
        krnl_Aggregate_TD_212[i] = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    }
    for (int i = 0; i < hpTimes_aggr; i++) {
        krnl_Aggregate_TD_212[i].setup(tbl_JOIN_LEFTANTI_TD_3550_output_partition_array[i], tbl_Aggregate_TD_212_output_partition_array[i], cfg_Aggregate_TD_212_cmds, cfg_Aggregate_TD_212_cmds_out, buftmp_a);
    }
    krnlEngine krnl_JOIN_LEFTANTI_TD_3550_part_left;
    krnl_JOIN_LEFTANTI_TD_3550_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_LEFTANTI_TD_3550_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_SerializeFromObject_TD_4109_input, tbl_SerializeFromObject_TD_4109_input_partition, cfg_JOIN_LEFTANTI_TD_3550_cmds_part);
    krnlEngine krnl_JOIN_LEFTANTI_TD_3550[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_LEFTANTI_TD_3550[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_LEFTANTI_TD_3550[i].setup(tbl_SerializeFromObject_TD_4109_input_partition_array[i], tbl_JOIN_INNER_TD_0152_output_partition_array[i], tbl_JOIN_LEFTANTI_TD_3550_output_preprocess_partition_array[i], cfg_JOIN_LEFTANTI_TD_3550_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_INNER_TD_0152_part_left;
    krnl_JOIN_INNER_TD_0152_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_0152_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_SerializeFromObject_TD_4109_input, tbl_SerializeFromObject_TD_4109_input_partition, cfg_JOIN_INNER_TD_0152_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_0152_part_right;
    krnl_JOIN_INNER_TD_0152_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_0152_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_Filter_TD_4876_output, tbl_Filter_TD_4876_output_partition, cfg_JOIN_INNER_TD_0152_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_0152[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_0152[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_0152[i].setup(tbl_SerializeFromObject_TD_4109_input_partition_array[i], tbl_Filter_TD_4876_output_partition_array[i], tbl_JOIN_INNER_TD_0152_output_partition_array[i], cfg_JOIN_INNER_TD_0152_cmds, buftmp_h);
    }
    // ************************** Transfer Engine *********************** // 
    transEngine trans_Aggregate_TD_1543;
    trans_Aggregate_TD_1543.setq(q_a);
    trans_Aggregate_TD_1543.add(&(cfg_Aggregate_TD_1543_cmds_part));
    trans_Aggregate_TD_1543.add(&(cfg_Aggregate_TD_1543_cmds));
    transEngine trans_Aggregate_TD_1543_out;
    trans_Aggregate_TD_1543_out.setq(q_a);
    q_a.finish();
    transEngine trans_Aggregate_TD_212;
    trans_Aggregate_TD_212.setq(q_a);
    trans_Aggregate_TD_212.add(&(cfg_Aggregate_TD_212_cmds_part));
    trans_Aggregate_TD_212.add(&(cfg_Aggregate_TD_212_cmds));
    transEngine trans_Aggregate_TD_212_out;
    trans_Aggregate_TD_212_out.setq(q_a);
    q_a.finish();
    transEngine trans_JOIN_LEFTANTI_TD_3550;
    trans_JOIN_LEFTANTI_TD_3550.setq(q_h);
    trans_JOIN_LEFTANTI_TD_3550.add(&(cfg_JOIN_LEFTANTI_TD_3550_cmds));
    trans_JOIN_LEFTANTI_TD_3550.add(&(tbl_SerializeFromObject_TD_4109_input));
    transEngine trans_JOIN_LEFTANTI_TD_3550_out;
    trans_JOIN_LEFTANTI_TD_3550_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_0152;
    trans_JOIN_INNER_TD_0152.setq(q_h);
    trans_JOIN_INNER_TD_0152.add(&(cfg_JOIN_INNER_TD_0152_cmds_part));
    trans_JOIN_INNER_TD_0152.add(&(cfg_JOIN_INNER_TD_0152_cmds));
    trans_JOIN_INNER_TD_0152.add(&(tbl_SerializeFromObject_TD_4109_input));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_1543;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_1543;
    std::vector<cl::Event> events_Aggregate_TD_1543[2];
    events_h2d_wr_Aggregate_TD_1543.resize(1);
    events_d2h_rd_Aggregate_TD_1543.resize(1);
    events_Aggregate_TD_1543[0].resize(1);
    events_Aggregate_TD_1543[1].resize(hpTimes_aggr);
    std::vector<cl::Event> events_grp_Aggregate_TD_1543;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_1543;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_212;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_212;
    std::vector<cl::Event> events_Aggregate_TD_212[2];
    events_h2d_wr_Aggregate_TD_212.resize(1);
    events_d2h_rd_Aggregate_TD_212.resize(1);
    events_Aggregate_TD_212[0].resize(1);
    events_Aggregate_TD_212[1].resize(hpTimes_aggr);
    std::vector<cl::Event> events_grp_Aggregate_TD_212;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_212;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTANTI_TD_3550;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTANTI_TD_3550;
    std::vector<cl::Event> events_JOIN_LEFTANTI_TD_3550[2];
    events_h2d_wr_JOIN_LEFTANTI_TD_3550.resize(1);
    events_d2h_rd_JOIN_LEFTANTI_TD_3550.resize(1);
    events_JOIN_LEFTANTI_TD_3550[0].resize(1);
    events_JOIN_LEFTANTI_TD_3550[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_LEFTANTI_TD_3550;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTANTI_TD_3550;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_0152;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_0152;
    std::vector<cl::Event> events_JOIN_INNER_TD_0152[2];
    events_h2d_wr_JOIN_INNER_TD_0152.resize(1);
    events_d2h_rd_JOIN_INNER_TD_0152.resize(1);
    events_JOIN_INNER_TD_0152[0].resize(2);
    events_JOIN_INNER_TD_0152[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_0152;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_0152;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_4_801_s, tv_r_Filter_4_801_e;
    gettimeofday(&tv_r_Filter_4_801_s, 0);
    SW_Filter_TD_4876(tbl_SerializeFromObject_TD_5101_input, tbl_Filter_TD_4876_output);
    gettimeofday(&tv_r_Filter_4_801_e, 0);

    struct timeval tv_r_JOIN_INNER_0_22_s, tv_r_JOIN_INNER_0_22_e;
    gettimeofday(&tv_r_JOIN_INNER_0_22_s, 0);
    trans_JOIN_INNER_TD_0152.add(&(tbl_Filter_TD_4876_output));
    trans_JOIN_INNER_TD_0152.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_0152), &(events_h2d_wr_JOIN_INNER_TD_0152[0]));
    events_grp_JOIN_INNER_TD_0152.push_back(events_h2d_wr_JOIN_INNER_TD_0152[0]);
    krnl_JOIN_INNER_TD_0152_part_left.run(0, &(events_grp_JOIN_INNER_TD_0152), &(events_JOIN_INNER_TD_0152[0][0]));
    krnl_JOIN_INNER_TD_0152_part_right.run(0, &(events_grp_JOIN_INNER_TD_0152), &(events_JOIN_INNER_TD_0152[0][1]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_0152[i].run(0, &(events_JOIN_INNER_TD_0152[0]), &(events_JOIN_INNER_TD_0152[1][i]));
    }
    gettimeofday(&tv_r_JOIN_INNER_0_22_e, 0);

    struct timeval tv_r_JOIN_LEFTANTI_3_548_s, tv_r_JOIN_LEFTANTI_3_548_e;
    gettimeofday(&tv_r_JOIN_LEFTANTI_3_548_s, 0);
    prev_events_grp_JOIN_LEFTANTI_TD_3550.push_back(events_h2d_wr_JOIN_INNER_TD_0152[0]);
    trans_JOIN_LEFTANTI_TD_3550.host2dev(0, &(prev_events_grp_JOIN_LEFTANTI_TD_3550), &(events_h2d_wr_JOIN_LEFTANTI_TD_3550[0]));
    events_grp_JOIN_LEFTANTI_TD_3550.push_back(events_h2d_wr_JOIN_LEFTANTI_TD_3550[0]);
    events_grp_JOIN_LEFTANTI_TD_3550.insert(std::end(events_grp_JOIN_LEFTANTI_TD_3550), std::begin(events_JOIN_INNER_TD_0152[0]), std::end(events_JOIN_INNER_TD_0152[0]));
    events_grp_JOIN_LEFTANTI_TD_3550.insert(std::end(events_grp_JOIN_LEFTANTI_TD_3550), std::begin(events_JOIN_INNER_TD_0152[1]), std::end(events_JOIN_INNER_TD_0152[1]));
    krnl_JOIN_LEFTANTI_TD_3550_part_left.run(0, &(events_grp_JOIN_LEFTANTI_TD_3550), &(events_JOIN_LEFTANTI_TD_3550[0][0]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_LEFTANTI_TD_3550[i].run(0, &(events_JOIN_LEFTANTI_TD_3550[0]), &(events_JOIN_LEFTANTI_TD_3550[1][i]));
    }
    
    for (int i(0); i < hpTimes_join; ++i) {
        trans_JOIN_LEFTANTI_TD_3550_out.add(&(tbl_JOIN_LEFTANTI_TD_3550_output_preprocess_partition_array[i]));
        trans_JOIN_LEFTANTI_TD_3550_out.add(&(tbl_JOIN_INNER_TD_0152_output_partition_array[i]));
    }
    trans_JOIN_LEFTANTI_TD_3550_out.dev2host(0, &(events_JOIN_LEFTANTI_TD_3550[1]), &(events_d2h_rd_JOIN_LEFTANTI_TD_3550[0]));
    q_h.flush();
    q_h.finish();
    SW_JOIN_LEFTANTI_TD_3550_concatenate(tbl_JOIN_LEFTANTI_TD_3550_output_preprocess, tbl_JOIN_INNER_TD_0152_output);
    tbl_JOIN_LEFTANTI_TD_3550_output_preprocess.copyTableData(&(tbl_JOIN_LEFTANTI_TD_3550_output));
    gettimeofday(&tv_r_JOIN_LEFTANTI_3_548_e, 0);

    struct timeval tv_r_Aggregate_2_546_s, tv_r_Aggregate_2_546_e;
    gettimeofday(&tv_r_Aggregate_2_546_s, 0);
    trans_Aggregate_TD_212.add(&(tbl_JOIN_LEFTANTI_TD_3550_output));
    trans_Aggregate_TD_212.host2dev(0, &(prev_events_grp_Aggregate_TD_212), &(events_h2d_wr_Aggregate_TD_212[0]));
    events_grp_Aggregate_TD_212.push_back(events_h2d_wr_Aggregate_TD_212[0]);
    krnl_Aggregate_TD_212_part.run(0, &(events_grp_Aggregate_TD_212), &(events_Aggregate_TD_212[0][0]));
    for (int i(0); i < hpTimes_aggr; ++i) {
        krnl_Aggregate_TD_212[i].run(0, &(events_Aggregate_TD_212[0]), &(events_Aggregate_TD_212[1][i]));
    }
    
    for (int i(0); i < hpTimes_aggr; ++i) {
        trans_Aggregate_TD_212_out.add(&(tbl_Aggregate_TD_212_output_partition_array[i]));
    }
    trans_Aggregate_TD_212_out.dev2host(0, &(events_Aggregate_TD_212[1]), &(events_d2h_rd_Aggregate_TD_212[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_212_consolidate(tbl_Aggregate_TD_212_output_partition_array, tbl_Aggregate_TD_212_output, hpTimes_aggr);
    gettimeofday(&tv_r_Aggregate_2_546_e, 0);

    struct timeval tv_r_Aggregate_1_525_s, tv_r_Aggregate_1_525_e;
    gettimeofday(&tv_r_Aggregate_1_525_s, 0);
    prev_events_grp_Aggregate_TD_1543.push_back(events_h2d_wr_Aggregate_TD_212[0]);
    trans_Aggregate_TD_1543.add(&(tbl_Aggregate_TD_212_output));
    trans_Aggregate_TD_1543.host2dev(0, &(prev_events_grp_Aggregate_TD_1543), &(events_h2d_wr_Aggregate_TD_1543[0]));
    events_grp_Aggregate_TD_1543.push_back(events_h2d_wr_Aggregate_TD_1543[0]);
    events_grp_Aggregate_TD_1543.insert(std::end(events_grp_Aggregate_TD_1543), std::begin(events_Aggregate_TD_212[0]), std::end(events_Aggregate_TD_212[0]));
    events_grp_Aggregate_TD_1543.insert(std::end(events_grp_Aggregate_TD_1543), std::begin(events_Aggregate_TD_212[1]), std::end(events_Aggregate_TD_212[1]));
    krnl_Aggregate_TD_1543_part.run(0, &(events_grp_Aggregate_TD_1543), &(events_Aggregate_TD_1543[0][0]));
    for (int i(0); i < hpTimes_aggr; ++i) {
        krnl_Aggregate_TD_1543[i].run(0, &(events_Aggregate_TD_1543[0]), &(events_Aggregate_TD_1543[1][i]));
    }
    
    for (int i(0); i < hpTimes_aggr; ++i) {
        trans_Aggregate_TD_1543_out.add(&(tbl_Aggregate_TD_1543_output_partition_array[i]));
    }
    trans_Aggregate_TD_1543_out.dev2host(0, &(events_Aggregate_TD_1543[1]), &(events_d2h_rd_Aggregate_TD_1543[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_1543_consolidate(tbl_Aggregate_TD_1543_output_partition_array, tbl_Aggregate_TD_1543_output, hpTimes_aggr);
    gettimeofday(&tv_r_Aggregate_1_525_e, 0);

    struct timeval tv_r_Sort_0_728_s, tv_r_Sort_0_728_e;
    gettimeofday(&tv_r_Sort_0_728_s, 0);
    SW_Sort_TD_0399(tbl_Aggregate_TD_1543_output, tbl_Sort_TD_0399_output);
    gettimeofday(&tv_r_Sort_0_728_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_801_s, &tv_r_Filter_4_801_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5101_input: " << tbl_SerializeFromObject_TD_5101_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_0: " << tvdiff(&tv_r_JOIN_INNER_0_22_s, &tv_r_JOIN_INNER_0_22_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_4109_input: " << tbl_SerializeFromObject_TD_4109_input.getNumRow() << " " << "tbl_Filter_TD_4876_output: " << tbl_Filter_TD_4876_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTANTI_3: " << tvdiff(&tv_r_JOIN_LEFTANTI_3_548_s, &tv_r_JOIN_LEFTANTI_3_548_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_0152_output: " << tbl_JOIN_INNER_TD_0152_output.getNumRow() << " " << "tbl_SerializeFromObject_TD_4109_input: " << tbl_SerializeFromObject_TD_4109_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_2: " << tvdiff(&tv_r_Aggregate_2_546_s, &tv_r_Aggregate_2_546_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTANTI_TD_3550_output: " << tbl_JOIN_LEFTANTI_TD_3550_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_525_s, &tv_r_Aggregate_1_525_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_212_output: " << tbl_Aggregate_TD_212_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_728_s, &tv_r_Sort_0_728_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_1543_output: " << tbl_Aggregate_TD_1543_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 248.86205 * 1000 << "ms" << std::endl; 
    return 0; 
}
