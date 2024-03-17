// number of overlays (w/o fusion): 6 
// number of overlays (w/ fusion): 6 
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

#include "cfgFunc_q18.hpp" 
#include "q18.hpp" 

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
    std::cout << "NOTE:running query #18\n."; 
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
    Table tbl_Sort_TD_0312_output("tbl_Sort_TD_0312_output", 183000000, 6, "");
    tbl_Sort_TD_0312_output.allocateHost();
    Table tbl_Aggregate_TD_1769_output("tbl_Aggregate_TD_1769_output", 183000000, 6, "");
    tbl_Aggregate_TD_1769_output.allocateHost();
    Table tbl_JOIN_INNER_TD_2223_output("tbl_JOIN_INNER_TD_2223_output", 100, 6, "");
    tbl_JOIN_INNER_TD_2223_output.allocateHost(1.2, hpTimes_join);
    Table tbl_JOIN_INNER_TD_3745_output("tbl_JOIN_INNER_TD_3745_output", 100, 5, "");
    tbl_JOIN_INNER_TD_3745_output.allocateHost(1.2, hpTimes_join);
    Table tbl_JOIN_LEFTSEMI_TD_3569_output("tbl_JOIN_LEFTSEMI_TD_3569_output", 100, 2, "");
    tbl_JOIN_LEFTSEMI_TD_3569_output.allocateHost(1.2, hpTimes_join);
    Table tbl_SerializeFromObject_TD_4686_input_stringRowIDSubstitute;
    tbl_SerializeFromObject_TD_4686_input_stringRowIDSubstitute = Table("customer", customer_n, 2, in_dir);
    tbl_SerializeFromObject_TD_4686_input_stringRowIDSubstitute.addCol("c_custkey", 4);
    tbl_SerializeFromObject_TD_4686_input_stringRowIDSubstitute.addCol("c_name", 4, 1, 0);
    tbl_SerializeFromObject_TD_4686_input_stringRowIDSubstitute.allocateHost();
    tbl_SerializeFromObject_TD_4686_input_stringRowIDSubstitute.loadHost();
    Table tbl_SerializeFromObject_TD_4686_input_stringRowIDSubstitute_partition("tbl_SerializeFromObject_TD_4686_input_stringRowIDSubstitute_partition", customer_n, 2, "");
    tbl_SerializeFromObject_TD_4686_input_stringRowIDSubstitute_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_4686_input_stringRowIDSubstitute_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_4686_input_stringRowIDSubstitute_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_4686_input_stringRowIDSubstitute_partition_array[i] = tbl_SerializeFromObject_TD_4686_input_stringRowIDSubstitute_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_4686_input;
    tbl_SerializeFromObject_TD_4686_input = Table("customer", customer_n, 2, in_dir);
    tbl_SerializeFromObject_TD_4686_input.addCol("c_custkey", 4);
    tbl_SerializeFromObject_TD_4686_input.addCol("c_name", TPCH_READ_C_NAME_LEN+1);
    tbl_SerializeFromObject_TD_4686_input.allocateHost();
    tbl_SerializeFromObject_TD_4686_input.loadHost();
    Table tbl_JOIN_LEFTSEMI_TD_4975_output("tbl_JOIN_LEFTSEMI_TD_4975_output", 100, 4, "");
    tbl_JOIN_LEFTSEMI_TD_4975_output.allocateHost(1.2, hpTimes_join);
    Table tbl_SerializeFromObject_TD_4720_input;
    tbl_SerializeFromObject_TD_4720_input = Table("lineitem", lineitem_n, 2, in_dir);
    tbl_SerializeFromObject_TD_4720_input.addCol("l_orderkey", 4);
    tbl_SerializeFromObject_TD_4720_input.addCol("l_quantity", 4);
    tbl_SerializeFromObject_TD_4720_input.allocateHost();
    tbl_SerializeFromObject_TD_4720_input.loadHost();
    Table tbl_SerializeFromObject_TD_4720_input_partition("tbl_SerializeFromObject_TD_4720_input_partition", lineitem_n, 2, "");
    tbl_SerializeFromObject_TD_4720_input_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_4720_input_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_4720_input_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_4720_input_partition_array[i] = tbl_SerializeFromObject_TD_4720_input_partition.createSubTable(i);
    }
    Table tbl_Filter_TD_4903_output("tbl_Filter_TD_4903_output", 183000000, 1, "");
    tbl_Filter_TD_4903_output.allocateHost();
    Table tbl_Filter_TD_4903_output_partition("tbl_Filter_TD_4903_output_partition", 183000000, 1, "");
    tbl_Filter_TD_4903_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_Filter_TD_4903_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_Filter_TD_4903_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_4903_output_partition_array[i] = tbl_Filter_TD_4903_output_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_5583_input;
    tbl_SerializeFromObject_TD_5583_input = Table("order", order_n, 4, in_dir);
    tbl_SerializeFromObject_TD_5583_input.addCol("o_orderkey", 4);
    tbl_SerializeFromObject_TD_5583_input.addCol("o_custkey", 4);
    tbl_SerializeFromObject_TD_5583_input.addCol("o_totalprice", 4);
    tbl_SerializeFromObject_TD_5583_input.addCol("o_orderdate", 4);
    tbl_SerializeFromObject_TD_5583_input.allocateHost();
    tbl_SerializeFromObject_TD_5583_input.loadHost();
    Table tbl_SerializeFromObject_TD_5583_input_partition("tbl_SerializeFromObject_TD_5583_input_partition", order_n, 4, "");
    tbl_SerializeFromObject_TD_5583_input_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_5583_input_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_5583_input_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_5583_input_partition_array[i] = tbl_SerializeFromObject_TD_5583_input_partition.createSubTable(i);
    }
    Table tbl_Filter_TD_5290_output("tbl_Filter_TD_5290_output", 183000000, 1, "");
    tbl_Filter_TD_5290_output.allocateHost();
    Table tbl_Filter_TD_5290_output_partition("tbl_Filter_TD_5290_output_partition", 183000000, 1, "");
    tbl_Filter_TD_5290_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_Filter_TD_5290_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_Filter_TD_5290_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_5290_output_partition_array[i] = tbl_Filter_TD_5290_output_partition.createSubTable(i);
    }
    Table tbl_Aggregate_TD_6796_output_preprocess("tbl_Aggregate_TD_6796_output_preprocess", 3000000, 16, "");
    tbl_Aggregate_TD_6796_output_preprocess.allocateHost(1.2, hpTimes_aggr);
    Table tbl_Aggregate_TD_6796_output("tbl_Aggregate_TD_6796_output", 3000000, 2, "");
    Table tbl_SerializeFromObject_TD_7784_input;
    tbl_SerializeFromObject_TD_7784_input = Table("lineitem", lineitem_n, 2, in_dir);
    tbl_SerializeFromObject_TD_7784_input.addCol("l_orderkey", 4);
    tbl_SerializeFromObject_TD_7784_input.addCol("l_quantity", 4);
    tbl_SerializeFromObject_TD_7784_input.allocateHost();
    tbl_SerializeFromObject_TD_7784_input.loadHost();
    Table tbl_SerializeFromObject_TD_7784_input_partition("tbl_SerializeFromObject_TD_7784_input_partition", lineitem_n, 2, "");
    tbl_SerializeFromObject_TD_7784_input_partition.allocateHost(1.2, hpTimes_aggr);
    tbl_SerializeFromObject_TD_7784_input_partition.allocateDevBuffer(context_a, 32);
    Table tbl_SerializeFromObject_TD_7784_input_partition_array[hpTimes_aggr];
    for (int i(0); i < hpTimes_aggr; ++i) {
        tbl_SerializeFromObject_TD_7784_input_partition_array[i] = tbl_SerializeFromObject_TD_7784_input_partition.createSubTable(i);
    }
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_2223_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_2223_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_2223_output_partition_array[i] = tbl_JOIN_INNER_TD_2223_output.createSubTable(i);
    }
    tbl_JOIN_INNER_TD_3745_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_3745_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_3745_output_partition_array[i] = tbl_JOIN_INNER_TD_3745_output.createSubTable(i);
    }
    tbl_JOIN_LEFTSEMI_TD_3569_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_LEFTSEMI_TD_3569_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_LEFTSEMI_TD_3569_output_partition_array[i] = tbl_JOIN_LEFTSEMI_TD_3569_output.createSubTable(i);
    }
    tbl_SerializeFromObject_TD_4686_input_stringRowIDSubstitute.allocateDevBuffer(context_h, 33);
    tbl_JOIN_LEFTSEMI_TD_4975_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_LEFTSEMI_TD_4975_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_LEFTSEMI_TD_4975_output_partition_array[i] = tbl_JOIN_LEFTSEMI_TD_4975_output.createSubTable(i);
    }
    tbl_SerializeFromObject_TD_4720_input.allocateDevBuffer(context_h, 33);
    tbl_Filter_TD_4903_output.allocateDevBuffer(context_h, 33);
    tbl_SerializeFromObject_TD_5583_input.allocateDevBuffer(context_h, 33);
    tbl_Filter_TD_5290_output.allocateDevBuffer(context_h, 33);
    tbl_Aggregate_TD_6796_output_preprocess.allocateDevBuffer(context_a, 33);
    Table tbl_Aggregate_TD_6796_output_partition_array[hpTimes_aggr];
    for (int i(0); i < hpTimes_aggr; ++i) {
        tbl_Aggregate_TD_6796_output_partition_array[i] = tbl_Aggregate_TD_6796_output_preprocess.createSubTable(i);
    }
    tbl_SerializeFromObject_TD_7784_input.allocateDevBuffer(context_a, 33);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_2223_cmds;
    cfg_JOIN_INNER_TD_2223_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_2223_gqe_join (cfg_JOIN_INNER_TD_2223_cmds.cmd);
    cfg_JOIN_INNER_TD_2223_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_3745_cmds;
    cfg_JOIN_INNER_TD_3745_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_3745_gqe_join (cfg_JOIN_INNER_TD_3745_cmds.cmd);
    cfg_JOIN_INNER_TD_3745_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_3745_cmds_part;
    cfg_JOIN_INNER_TD_3745_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_3745_gqe_join_part (cfg_JOIN_INNER_TD_3745_cmds_part.cmd);
    cfg_JOIN_INNER_TD_3745_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_3569_cmds;
    cfg_JOIN_LEFTSEMI_TD_3569_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_3569_gqe_join (cfg_JOIN_LEFTSEMI_TD_3569_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_3569_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_3569_cmds_part;
    cfg_JOIN_LEFTSEMI_TD_3569_cmds_part.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_3569_gqe_join_part (cfg_JOIN_LEFTSEMI_TD_3569_cmds_part.cmd);
    cfg_JOIN_LEFTSEMI_TD_3569_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_4975_cmds;
    cfg_JOIN_LEFTSEMI_TD_4975_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_4975_gqe_join (cfg_JOIN_LEFTSEMI_TD_4975_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_4975_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_4975_cmds_part;
    cfg_JOIN_LEFTSEMI_TD_4975_cmds_part.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_4975_gqe_join_part (cfg_JOIN_LEFTSEMI_TD_4975_cmds_part.cmd);
    cfg_JOIN_LEFTSEMI_TD_4975_cmds_part.allocateDevBuffer(context_h, 32);
    AggrCfgCmd cfg_Aggregate_TD_6796_cmds;
    cfg_Aggregate_TD_6796_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_6796_gqe_aggr(cfg_Aggregate_TD_6796_cmds.cmd);
    cfg_Aggregate_TD_6796_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_6796_cmds_out;
    cfg_Aggregate_TD_6796_cmds_out.allocateHost();
    cfg_Aggregate_TD_6796_cmds_out.allocateDevBuffer(context_a, 33);
    cfgCmd cfg_Aggregate_TD_6796_cmds_part;
    cfg_Aggregate_TD_6796_cmds_part.allocateHost();
    get_cfg_dat_Aggregate_TD_6796_gqe_aggr_part (cfg_Aggregate_TD_6796_cmds_part.cmd);
    cfg_Aggregate_TD_6796_cmds_part.allocateDevBuffer(context_a, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    AggrBufferTmp buftmp_a(context_a); 
    buftmp_a.BufferInitial(q_a); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_2223[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_2223[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_2223[i].setup(tbl_JOIN_INNER_TD_3745_output_partition_array[i], tbl_JOIN_LEFTSEMI_TD_3569_output_partition_array[i], tbl_JOIN_INNER_TD_2223_output_partition_array[i], cfg_JOIN_INNER_TD_2223_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_INNER_TD_3745_part_left;
    krnl_JOIN_INNER_TD_3745_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_3745_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_SerializeFromObject_TD_4686_input_stringRowIDSubstitute, tbl_SerializeFromObject_TD_4686_input_stringRowIDSubstitute_partition, cfg_JOIN_INNER_TD_3745_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_3745[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_3745[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_3745[i].setup(tbl_SerializeFromObject_TD_4686_input_stringRowIDSubstitute_partition_array[i], tbl_JOIN_LEFTSEMI_TD_4975_output_partition_array[i], tbl_JOIN_INNER_TD_3745_output_partition_array[i], cfg_JOIN_INNER_TD_3745_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_LEFTSEMI_TD_3569_part_left;
    krnl_JOIN_LEFTSEMI_TD_3569_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_LEFTSEMI_TD_3569_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_Filter_TD_4903_output, tbl_Filter_TD_4903_output_partition, cfg_JOIN_LEFTSEMI_TD_3569_cmds_part);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_3569_part_right;
    krnl_JOIN_LEFTSEMI_TD_3569_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_LEFTSEMI_TD_3569_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_SerializeFromObject_TD_4720_input, tbl_SerializeFromObject_TD_4720_input_partition, cfg_JOIN_LEFTSEMI_TD_3569_cmds_part);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_3569[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_LEFTSEMI_TD_3569[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_LEFTSEMI_TD_3569[i].setup(tbl_Filter_TD_4903_output_partition_array[i], tbl_SerializeFromObject_TD_4720_input_partition_array[i], tbl_JOIN_LEFTSEMI_TD_3569_output_partition_array[i], cfg_JOIN_LEFTSEMI_TD_3569_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_LEFTSEMI_TD_4975_part_left;
    krnl_JOIN_LEFTSEMI_TD_4975_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_LEFTSEMI_TD_4975_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_Filter_TD_5290_output, tbl_Filter_TD_5290_output_partition, cfg_JOIN_LEFTSEMI_TD_4975_cmds_part);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_4975_part_right;
    krnl_JOIN_LEFTSEMI_TD_4975_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_LEFTSEMI_TD_4975_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_SerializeFromObject_TD_5583_input, tbl_SerializeFromObject_TD_5583_input_partition, cfg_JOIN_LEFTSEMI_TD_4975_cmds_part);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_4975[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_LEFTSEMI_TD_4975[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_LEFTSEMI_TD_4975[i].setup(tbl_Filter_TD_5290_output_partition_array[i], tbl_SerializeFromObject_TD_5583_input_partition_array[i], tbl_JOIN_LEFTSEMI_TD_4975_output_partition_array[i], cfg_JOIN_LEFTSEMI_TD_4975_cmds, buftmp_h);
    }
    AggrKrnlEngine krnl_Aggregate_TD_6796_part;
    krnl_Aggregate_TD_6796_part = AggrKrnlEngine(program_a, q_a, "gqePart");
    krnl_Aggregate_TD_6796_part.setup_hp(512, 0, power_of_hpTimes_aggr, tbl_SerializeFromObject_TD_7784_input, tbl_SerializeFromObject_TD_7784_input_partition, cfg_Aggregate_TD_6796_cmds_part);
    AggrKrnlEngine krnl_Aggregate_TD_6796[hpTimes_aggr];
    for (int i = 0; i < hpTimes_aggr; i++) {
        krnl_Aggregate_TD_6796[i] = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    }
    for (int i = 0; i < hpTimes_aggr; i++) {
        krnl_Aggregate_TD_6796[i].setup(tbl_SerializeFromObject_TD_7784_input_partition_array[i], tbl_Aggregate_TD_6796_output_partition_array[i], cfg_Aggregate_TD_6796_cmds, cfg_Aggregate_TD_6796_cmds_out, buftmp_a);
    }
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_2223;
    trans_JOIN_INNER_TD_2223.setq(q_h);
    trans_JOIN_INNER_TD_2223.add(&(cfg_JOIN_INNER_TD_2223_cmds));
    transEngine trans_JOIN_INNER_TD_2223_out;
    trans_JOIN_INNER_TD_2223_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_3745;
    trans_JOIN_INNER_TD_3745.setq(q_h);
    trans_JOIN_INNER_TD_3745.add(&(cfg_JOIN_INNER_TD_3745_cmds));
    trans_JOIN_INNER_TD_3745.add(&(tbl_SerializeFromObject_TD_4686_input_stringRowIDSubstitute));
    q_h.finish();
    transEngine trans_JOIN_LEFTSEMI_TD_3569;
    trans_JOIN_LEFTSEMI_TD_3569.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_3569.add(&(cfg_JOIN_LEFTSEMI_TD_3569_cmds_part));
    trans_JOIN_LEFTSEMI_TD_3569.add(&(cfg_JOIN_LEFTSEMI_TD_3569_cmds));
    trans_JOIN_LEFTSEMI_TD_3569.add(&(tbl_SerializeFromObject_TD_4720_input));
    q_h.finish();
    transEngine trans_JOIN_LEFTSEMI_TD_4975;
    trans_JOIN_LEFTSEMI_TD_4975.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_4975.add(&(cfg_JOIN_LEFTSEMI_TD_4975_cmds_part));
    trans_JOIN_LEFTSEMI_TD_4975.add(&(cfg_JOIN_LEFTSEMI_TD_4975_cmds));
    trans_JOIN_LEFTSEMI_TD_4975.add(&(tbl_SerializeFromObject_TD_5583_input));
    q_h.finish();
    transEngine trans_Aggregate_TD_6796;
    trans_Aggregate_TD_6796.setq(q_a);
    trans_Aggregate_TD_6796.add(&(cfg_Aggregate_TD_6796_cmds_part));
    trans_Aggregate_TD_6796.add(&(cfg_Aggregate_TD_6796_cmds));
    trans_Aggregate_TD_6796.add(&(tbl_SerializeFromObject_TD_7784_input));
    transEngine trans_Aggregate_TD_6796_out;
    trans_Aggregate_TD_6796_out.setq(q_a);
    q_a.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_2223;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_2223;
    std::vector<cl::Event> events_JOIN_INNER_TD_2223[2];
    events_h2d_wr_JOIN_INNER_TD_2223.resize(1);
    events_d2h_rd_JOIN_INNER_TD_2223.resize(1);
    events_JOIN_INNER_TD_2223[0].resize(0);
    events_JOIN_INNER_TD_2223[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_2223;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_2223;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_3745;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_3745;
    std::vector<cl::Event> events_JOIN_INNER_TD_3745[2];
    events_h2d_wr_JOIN_INNER_TD_3745.resize(1);
    events_d2h_rd_JOIN_INNER_TD_3745.resize(1);
    events_JOIN_INNER_TD_3745[0].resize(1);
    events_JOIN_INNER_TD_3745[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_3745;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_3745;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_3569;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_3569;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_3569[2];
    events_h2d_wr_JOIN_LEFTSEMI_TD_3569.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_3569.resize(1);
    events_JOIN_LEFTSEMI_TD_3569[0].resize(2);
    events_JOIN_LEFTSEMI_TD_3569[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_3569;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_3569;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_4975;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_4975;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_4975[2];
    events_h2d_wr_JOIN_LEFTSEMI_TD_4975.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_4975.resize(1);
    events_JOIN_LEFTSEMI_TD_4975[0].resize(2);
    events_JOIN_LEFTSEMI_TD_4975[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_4975;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_4975;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_6796;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_6796;
    std::vector<cl::Event> events_Aggregate_TD_6796[2];
    events_h2d_wr_Aggregate_TD_6796.resize(1);
    events_d2h_rd_Aggregate_TD_6796.resize(1);
    events_Aggregate_TD_6796[0].resize(1);
    events_Aggregate_TD_6796[1].resize(hpTimes_aggr);
    std::vector<cl::Event> events_grp_Aggregate_TD_6796;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_6796;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Aggregate_6_46_s, tv_r_Aggregate_6_46_e;
    gettimeofday(&tv_r_Aggregate_6_46_s, 0);
    trans_Aggregate_TD_6796.host2dev(0, &(prev_events_grp_Aggregate_TD_6796), &(events_h2d_wr_Aggregate_TD_6796[0]));
    events_grp_Aggregate_TD_6796.push_back(events_h2d_wr_Aggregate_TD_6796[0]);
    krnl_Aggregate_TD_6796_part.run(0, &(events_grp_Aggregate_TD_6796), &(events_Aggregate_TD_6796[0][0]));
    for (int i(0); i < hpTimes_aggr; ++i) {
        krnl_Aggregate_TD_6796[i].run(0, &(events_Aggregate_TD_6796[0]), &(events_Aggregate_TD_6796[1][i]));
    }
    
    for (int i(0); i < hpTimes_aggr; ++i) {
        trans_Aggregate_TD_6796_out.add(&(tbl_Aggregate_TD_6796_output_partition_array[i]));
    }
    trans_Aggregate_TD_6796_out.dev2host(0, &(events_Aggregate_TD_6796[1]), &(events_d2h_rd_Aggregate_TD_6796[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_6796_consolidate(tbl_Aggregate_TD_6796_output_partition_array, tbl_Aggregate_TD_6796_output, hpTimes_aggr);
    gettimeofday(&tv_r_Aggregate_6_46_e, 0);

    struct timeval tv_r_Filter_5_361_s, tv_r_Filter_5_361_e;
    gettimeofday(&tv_r_Filter_5_361_s, 0);
    SW_Filter_TD_5290(tbl_Aggregate_TD_6796_output, tbl_Filter_TD_5290_output);
    gettimeofday(&tv_r_Filter_5_361_e, 0);

    struct timeval tv_r_Filter_4_199_s, tv_r_Filter_4_199_e;
    gettimeofday(&tv_r_Filter_4_199_s, 0);
    SW_Filter_TD_4903(tbl_Aggregate_TD_6796_output, tbl_Filter_TD_4903_output);
    gettimeofday(&tv_r_Filter_4_199_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_4_937_s, tv_r_JOIN_LEFTSEMI_4_937_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_4_937_s, 0);
    trans_JOIN_LEFTSEMI_TD_4975.add(&(tbl_Filter_TD_5290_output));
    trans_JOIN_LEFTSEMI_TD_4975.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_4975), &(events_h2d_wr_JOIN_LEFTSEMI_TD_4975[0]));
    events_grp_JOIN_LEFTSEMI_TD_4975.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_4975[0]);
    krnl_JOIN_LEFTSEMI_TD_4975_part_left.run(0, &(events_grp_JOIN_LEFTSEMI_TD_4975), &(events_JOIN_LEFTSEMI_TD_4975[0][0]));
    krnl_JOIN_LEFTSEMI_TD_4975_part_right.run(0, &(events_grp_JOIN_LEFTSEMI_TD_4975), &(events_JOIN_LEFTSEMI_TD_4975[0][1]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_LEFTSEMI_TD_4975[i].run(0, &(events_JOIN_LEFTSEMI_TD_4975[0]), &(events_JOIN_LEFTSEMI_TD_4975[1][i]));
    }
    gettimeofday(&tv_r_JOIN_LEFTSEMI_4_937_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_3_923_s, tv_r_JOIN_LEFTSEMI_3_923_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_3_923_s, 0);
    trans_JOIN_LEFTSEMI_TD_3569.add(&(tbl_Filter_TD_4903_output));
    trans_JOIN_LEFTSEMI_TD_3569.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_3569), &(events_h2d_wr_JOIN_LEFTSEMI_TD_3569[0]));
    events_grp_JOIN_LEFTSEMI_TD_3569.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_3569[0]);
    krnl_JOIN_LEFTSEMI_TD_3569_part_left.run(0, &(events_grp_JOIN_LEFTSEMI_TD_3569), &(events_JOIN_LEFTSEMI_TD_3569[0][0]));
    krnl_JOIN_LEFTSEMI_TD_3569_part_right.run(0, &(events_grp_JOIN_LEFTSEMI_TD_3569), &(events_JOIN_LEFTSEMI_TD_3569[0][1]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_LEFTSEMI_TD_3569[i].run(0, &(events_JOIN_LEFTSEMI_TD_3569[0]), &(events_JOIN_LEFTSEMI_TD_3569[1][i]));
    }
    gettimeofday(&tv_r_JOIN_LEFTSEMI_3_923_e, 0);

    struct timeval tv_r_JOIN_INNER_3_685_s, tv_r_JOIN_INNER_3_685_e;
    gettimeofday(&tv_r_JOIN_INNER_3_685_s, 0);
    prev_events_grp_JOIN_INNER_TD_3745.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_4975[0]);
    trans_JOIN_INNER_TD_3745.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_3745), &(events_h2d_wr_JOIN_INNER_TD_3745[0]));
    events_grp_JOIN_INNER_TD_3745.push_back(events_h2d_wr_JOIN_INNER_TD_3745[0]);
    events_grp_JOIN_INNER_TD_3745.insert(std::end(events_grp_JOIN_INNER_TD_3745), std::begin(events_JOIN_LEFTSEMI_TD_4975[0]), std::end(events_JOIN_LEFTSEMI_TD_4975[0]));
    events_grp_JOIN_INNER_TD_3745.insert(std::end(events_grp_JOIN_INNER_TD_3745), std::begin(events_JOIN_LEFTSEMI_TD_4975[1]), std::end(events_JOIN_LEFTSEMI_TD_4975[1]));
    krnl_JOIN_INNER_TD_3745_part_left.run(0, &(events_grp_JOIN_INNER_TD_3745), &(events_JOIN_INNER_TD_3745[0][0]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_3745[i].run(0, &(events_JOIN_INNER_TD_3745[0]), &(events_JOIN_INNER_TD_3745[1][i]));
    }
    gettimeofday(&tv_r_JOIN_INNER_3_685_e, 0);

    struct timeval tv_r_JOIN_INNER_2_644_s, tv_r_JOIN_INNER_2_644_e;
    gettimeofday(&tv_r_JOIN_INNER_2_644_s, 0);
    prev_events_grp_JOIN_INNER_TD_2223.push_back(events_h2d_wr_JOIN_INNER_TD_3745[0]);
    prev_events_grp_JOIN_INNER_TD_2223.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_3569[0]);
    trans_JOIN_INNER_TD_2223.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_2223), &(events_h2d_wr_JOIN_INNER_TD_2223[0]));
    events_grp_JOIN_INNER_TD_2223.push_back(events_h2d_wr_JOIN_INNER_TD_2223[0]);
    events_grp_JOIN_INNER_TD_2223.insert(std::end(events_grp_JOIN_INNER_TD_2223), std::begin(events_JOIN_INNER_TD_3745[0]), std::end(events_JOIN_INNER_TD_3745[0]));
    events_grp_JOIN_INNER_TD_2223.insert(std::end(events_grp_JOIN_INNER_TD_2223), std::begin(events_JOIN_INNER_TD_3745[1]), std::end(events_JOIN_INNER_TD_3745[1]));
    events_grp_JOIN_INNER_TD_2223.insert(std::end(events_grp_JOIN_INNER_TD_2223), std::begin(events_JOIN_LEFTSEMI_TD_3569[0]), std::end(events_JOIN_LEFTSEMI_TD_3569[0]));
    events_grp_JOIN_INNER_TD_2223.insert(std::end(events_grp_JOIN_INNER_TD_2223), std::begin(events_JOIN_LEFTSEMI_TD_3569[1]), std::end(events_JOIN_LEFTSEMI_TD_3569[1]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_2223[i].run(0, &(events_grp_JOIN_INNER_TD_2223), &(events_JOIN_INNER_TD_2223[1][i]));
    }
    
    for (int i(0); i < hpTimes_join; ++i) {
        trans_JOIN_INNER_TD_2223_out.add(&(tbl_JOIN_INNER_TD_2223_output_partition_array[i]));
    }
    trans_JOIN_INNER_TD_2223_out.dev2host(0, &(events_JOIN_INNER_TD_2223[1]), &(events_d2h_rd_JOIN_INNER_TD_2223[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_2_644_e, 0);

    struct timeval tv_r_Aggregate_1_592_s, tv_r_Aggregate_1_592_e;
    gettimeofday(&tv_r_Aggregate_1_592_s, 0);
    SW_Aggregate_TD_1769(tbl_JOIN_INNER_TD_2223_output_partition_array, tbl_SerializeFromObject_TD_4686_input, tbl_Aggregate_TD_1769_output, hpTimes_join);
    gettimeofday(&tv_r_Aggregate_1_592_e, 0);

    struct timeval tv_r_Sort_0_33_s, tv_r_Sort_0_33_e;
    gettimeofday(&tv_r_Sort_0_33_s, 0);
    SW_Sort_TD_0312(tbl_Aggregate_TD_1769_output, tbl_Sort_TD_0312_output);
    gettimeofday(&tv_r_Sort_0_33_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Aggregate_6: " << tvdiff(&tv_r_Aggregate_6_46_s, &tv_r_Aggregate_6_46_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7784_input: " << tbl_SerializeFromObject_TD_7784_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_361_s, &tv_r_Filter_5_361_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_6796_output: " << tbl_Aggregate_TD_6796_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_199_s, &tv_r_Filter_4_199_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_6796_output: " << tbl_Aggregate_TD_6796_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_4: " << tvdiff(&tv_r_JOIN_LEFTSEMI_4_937_s, &tv_r_JOIN_LEFTSEMI_4_937_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5583_input: " << tbl_SerializeFromObject_TD_5583_input.getNumRow() << " " << "tbl_Filter_TD_5290_output: " << tbl_Filter_TD_5290_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_3: " << tvdiff(&tv_r_JOIN_LEFTSEMI_3_923_s, &tv_r_JOIN_LEFTSEMI_3_923_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_4720_input: " << tbl_SerializeFromObject_TD_4720_input.getNumRow() << " " << "tbl_Filter_TD_4903_output: " << tbl_Filter_TD_4903_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_685_s, &tv_r_JOIN_INNER_3_685_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_4686_input_stringRowIDSubstitute: " << tbl_SerializeFromObject_TD_4686_input_stringRowIDSubstitute.getNumRow() << " " << "tbl_JOIN_LEFTSEMI_TD_4975_output: " << tbl_JOIN_LEFTSEMI_TD_4975_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_2: " << tvdiff(&tv_r_JOIN_INNER_2_644_s, &tv_r_JOIN_INNER_2_644_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3745_output: " << tbl_JOIN_INNER_TD_3745_output.getNumRow() << " " << "tbl_JOIN_LEFTSEMI_TD_3569_output: " << tbl_JOIN_LEFTSEMI_TD_3569_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_592_s, &tv_r_Aggregate_1_592_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_2223_output: " << tbl_JOIN_INNER_TD_2223_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_33_s, &tv_r_Sort_0_33_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_1769_output: " << tbl_Aggregate_TD_1769_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1738.238 * 1000 << "ms" << std::endl; 
    return 0; 
}
