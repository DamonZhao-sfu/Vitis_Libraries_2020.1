// number of overlays (w/o fusion): 8 
// number of overlays (w/ fusion): 8 
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

#include "cfgFunc_q2.hpp" 
#include "q2.hpp" 

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
    std::cout << "NOTE:running query #2\n."; 
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
    // *********************** Partition Infomation ********************* // 
    int hpTimes_join = 32; 
    int power_of_hpTimes_join = log2(hpTimes_join); 
    std::cout << "Number of partition (gqeJoin) is: " << hpTimes_join << std::endl; 
    int hpTimes_aggr = 256; 
    int power_of_hpTimes_aggr = log2(hpTimes_aggr); 
    std::cout << "Number of partition (gqeAggr) is: " << hpTimes_aggr << std::endl; 
    // ****************************** Tables **************************** // 
    Table tbl_Sort_TD_0435_output("tbl_Sort_TD_0435_output", 183000000, 8, "");
    tbl_Sort_TD_0435_output.allocateHost();
    Table tbl_JOIN_INNER_TD_1293_output("tbl_JOIN_INNER_TD_1293_output", 183000000, 8, "");
    tbl_JOIN_INNER_TD_1293_output.allocateHost();
    Table tbl_JOIN_INNER_TD_2303_output("tbl_JOIN_INNER_TD_2303_output", 183000000, 9, "");
    tbl_JOIN_INNER_TD_2303_output.allocateHost();
    Table tbl_JOIN_INNER_TD_391_output("tbl_JOIN_INNER_TD_391_output", 183000000, 8, "");
    tbl_JOIN_INNER_TD_391_output.allocateHost();
    Table tbl_SerializeFromObject_TD_3496_input_stringRowIDSubstitute;
    tbl_SerializeFromObject_TD_3496_input_stringRowIDSubstitute = Table("nation", nation_n, 3, in_dir);
    tbl_SerializeFromObject_TD_3496_input_stringRowIDSubstitute.addCol("n_nationkey", 4);
    tbl_SerializeFromObject_TD_3496_input_stringRowIDSubstitute.addCol("n_name", 4, 1, 0);
    tbl_SerializeFromObject_TD_3496_input_stringRowIDSubstitute.addCol("n_regionkey", 4);
    tbl_SerializeFromObject_TD_3496_input_stringRowIDSubstitute.allocateHost();
    tbl_SerializeFromObject_TD_3496_input_stringRowIDSubstitute.loadHost();
    Table tbl_SerializeFromObject_TD_3496_input;
    tbl_SerializeFromObject_TD_3496_input = Table("nation", nation_n, 3, in_dir);
    tbl_SerializeFromObject_TD_3496_input.addCol("n_nationkey", 4);
    tbl_SerializeFromObject_TD_3496_input.addCol("n_name", TPCH_READ_NATION_LEN+1);
    tbl_SerializeFromObject_TD_3496_input.addCol("n_regionkey", 4);
    tbl_SerializeFromObject_TD_3496_input.allocateHost();
    tbl_SerializeFromObject_TD_3496_input.loadHost();
    Table tbl_JOIN_INNER_TD_4801_output("tbl_JOIN_INNER_TD_4801_output", 183000000, 3, "");
    tbl_JOIN_INNER_TD_4801_output.allocateHost();
    Table tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute;
    tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute = Table("supplier", supplier_n, 7, in_dir);
    tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.addCol("s_suppkey", 4);
    tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.addCol("s_name", 4, 1, 0);
    tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.addCol("s_address", 4, 1, 0);
    tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.addCol("s_nationkey", 4);
    tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.addCol("s_phone", 4, 1, 0);
    tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.addCol("s_acctbal", 4);
    tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.addCol("s_comment", 4, 1, 0);
    tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.allocateHost();
    tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.loadHost();
    Table tbl_SerializeFromObject_TD_4939_input;
    tbl_SerializeFromObject_TD_4939_input = Table("supplier", supplier_n, 7, in_dir);
    tbl_SerializeFromObject_TD_4939_input.addCol("s_suppkey", 4);
    tbl_SerializeFromObject_TD_4939_input.addCol("s_name", TPCH_READ_S_NAME_LEN+1);
    tbl_SerializeFromObject_TD_4939_input.addCol("s_address", TPCH_READ_S_ADDR_MAX+1);
    tbl_SerializeFromObject_TD_4939_input.addCol("s_nationkey", 4);
    tbl_SerializeFromObject_TD_4939_input.addCol("s_phone", TPCH_READ_PHONE_LEN+1);
    tbl_SerializeFromObject_TD_4939_input.addCol("s_acctbal", 4);
    tbl_SerializeFromObject_TD_4939_input.addCol("s_comment", TPCH_READ_S_CMNT_MAX+1);
    tbl_SerializeFromObject_TD_4939_input.allocateHost();
    tbl_SerializeFromObject_TD_4939_input.loadHost();
    Table tbl_Aggregate_TD_6211_output("tbl_Aggregate_TD_6211_output", 183000000, 2, "");
    tbl_Aggregate_TD_6211_output.allocateHost();
    Table tbl_JOIN_INNER_TD_586_output("tbl_JOIN_INNER_TD_586_output", 628, 5, "");
    tbl_JOIN_INNER_TD_586_output.allocateHost(1.2, hpTimes_join);
    Table tbl_Filter_TD_616_output("tbl_Filter_TD_616_output", 183000000, 2, "");
    tbl_Filter_TD_616_output.allocateHost();
    Table tbl_Filter_TD_616_output_partition("tbl_Filter_TD_616_output_partition", 183000000, 2, "");
    tbl_Filter_TD_616_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_Filter_TD_616_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_Filter_TD_616_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_616_output_partition_array[i] = tbl_Filter_TD_616_output_partition.createSubTable(i);
    }
    Table tbl_JOIN_INNER_TD_9665_output("tbl_JOIN_INNER_TD_9665_output", 162880, 3, "");
    tbl_JOIN_INNER_TD_9665_output.allocateHost(1.2, hpTimes_join);
    Table tbl_SerializeFromObject_TD_7652_input;
    tbl_SerializeFromObject_TD_7652_input = Table("part", part_n, 4, in_dir);
    tbl_SerializeFromObject_TD_7652_input.addCol("p_partkey", 4);
    tbl_SerializeFromObject_TD_7652_input.addCol("p_mfgr", TPCH_READ_P_MFG_LEN+1);
    tbl_SerializeFromObject_TD_7652_input.addCol("p_type", TPCH_READ_P_TYPE_LEN+1);
    tbl_SerializeFromObject_TD_7652_input.addCol("p_size", 4);
    tbl_SerializeFromObject_TD_7652_input.allocateHost();
    tbl_SerializeFromObject_TD_7652_input.loadHost();
    Table tbl_JOIN_INNER_TD_8484_output("tbl_JOIN_INNER_TD_8484_output", 2036, 1, "");
    tbl_JOIN_INNER_TD_8484_output.allocateHost(1.2, hpTimes_join);
    Table tbl_SerializeFromObject_TD_10268_input;
    tbl_SerializeFromObject_TD_10268_input = Table("partsupp", partsupp_n, 3, in_dir);
    tbl_SerializeFromObject_TD_10268_input.addCol("ps_partkey", 4);
    tbl_SerializeFromObject_TD_10268_input.addCol("ps_suppkey", 4);
    tbl_SerializeFromObject_TD_10268_input.addCol("ps_supplycost", 4);
    tbl_SerializeFromObject_TD_10268_input.allocateHost();
    tbl_SerializeFromObject_TD_10268_input.loadHost();
    Table tbl_SerializeFromObject_TD_10268_input_partition("tbl_SerializeFromObject_TD_10268_input_partition", partsupp_n, 3, "");
    tbl_SerializeFromObject_TD_10268_input_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_10268_input_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_10268_input_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_10268_input_partition_array[i] = tbl_SerializeFromObject_TD_10268_input_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_10678_input;
    tbl_SerializeFromObject_TD_10678_input = Table("supplier", supplier_n, 2, in_dir);
    tbl_SerializeFromObject_TD_10678_input.addCol("s_suppkey", 4);
    tbl_SerializeFromObject_TD_10678_input.addCol("s_nationkey", 4);
    tbl_SerializeFromObject_TD_10678_input.allocateHost();
    tbl_SerializeFromObject_TD_10678_input.loadHost();
    Table tbl_SerializeFromObject_TD_10678_input_partition("tbl_SerializeFromObject_TD_10678_input_partition", supplier_n, 2, "");
    tbl_SerializeFromObject_TD_10678_input_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_10678_input_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_10678_input_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_10678_input_partition_array[i] = tbl_SerializeFromObject_TD_10678_input_partition.createSubTable(i);
    }
    Table tbl_JOIN_INNER_TD_7889_output("tbl_JOIN_INNER_TD_7889_output", 5, 1, "");
    tbl_JOIN_INNER_TD_7889_output.allocateHost(1.2, hpTimes_join);
    Table tbl_SerializeFromObject_TD_96_input;
    tbl_SerializeFromObject_TD_96_input = Table("nation", nation_n, 2, in_dir);
    tbl_SerializeFromObject_TD_96_input.addCol("n_nationkey", 4);
    tbl_SerializeFromObject_TD_96_input.addCol("n_regionkey", 4);
    tbl_SerializeFromObject_TD_96_input.allocateHost();
    tbl_SerializeFromObject_TD_96_input.loadHost();
    Table tbl_SerializeFromObject_TD_96_input_partition("tbl_SerializeFromObject_TD_96_input_partition", nation_n, 2, "");
    tbl_SerializeFromObject_TD_96_input_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_96_input_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_96_input_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_96_input_partition_array[i] = tbl_SerializeFromObject_TD_96_input_partition.createSubTable(i);
    }
    Table tbl_Filter_TD_8820_output("tbl_Filter_TD_8820_output", 183000000, 1, "");
    tbl_Filter_TD_8820_output.allocateHost();
    Table tbl_Filter_TD_8820_output_partition("tbl_Filter_TD_8820_output_partition", 183000000, 1, "");
    tbl_Filter_TD_8820_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_Filter_TD_8820_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_Filter_TD_8820_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_8820_output_partition_array[i] = tbl_Filter_TD_8820_output_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_9414_input;
    tbl_SerializeFromObject_TD_9414_input = Table("region", region_n, 2, in_dir);
    tbl_SerializeFromObject_TD_9414_input.addCol("r_regionkey", 4);
    tbl_SerializeFromObject_TD_9414_input.addCol("r_name", TPCH_READ_REGION_LEN+1);
    tbl_SerializeFromObject_TD_9414_input.allocateHost();
    tbl_SerializeFromObject_TD_9414_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_586_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_586_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_586_output_partition_array[i] = tbl_JOIN_INNER_TD_586_output.createSubTable(i);
    }
    tbl_Filter_TD_616_output.allocateDevBuffer(context_h, 33);
    tbl_JOIN_INNER_TD_9665_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_9665_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_9665_output_partition_array[i] = tbl_JOIN_INNER_TD_9665_output.createSubTable(i);
    }
    tbl_JOIN_INNER_TD_8484_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_8484_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_8484_output_partition_array[i] = tbl_JOIN_INNER_TD_8484_output.createSubTable(i);
    }
    tbl_SerializeFromObject_TD_10268_input.allocateDevBuffer(context_h, 33);
    tbl_SerializeFromObject_TD_10678_input.allocateDevBuffer(context_h, 33);
    tbl_JOIN_INNER_TD_7889_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_7889_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_7889_output_partition_array[i] = tbl_JOIN_INNER_TD_7889_output.createSubTable(i);
    }
    tbl_SerializeFromObject_TD_96_input.allocateDevBuffer(context_h, 33);
    tbl_Filter_TD_8820_output.allocateDevBuffer(context_h, 33);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_586_cmds;
    cfg_JOIN_INNER_TD_586_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_586_gqe_join (cfg_JOIN_INNER_TD_586_cmds.cmd);
    cfg_JOIN_INNER_TD_586_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_586_cmds_part;
    cfg_JOIN_INNER_TD_586_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_586_gqe_join_part (cfg_JOIN_INNER_TD_586_cmds_part.cmd);
    cfg_JOIN_INNER_TD_586_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_9665_cmds;
    cfg_JOIN_INNER_TD_9665_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_9665_gqe_join (cfg_JOIN_INNER_TD_9665_cmds.cmd);
    cfg_JOIN_INNER_TD_9665_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_9665_cmds_part;
    cfg_JOIN_INNER_TD_9665_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_9665_gqe_join_part (cfg_JOIN_INNER_TD_9665_cmds_part.cmd);
    cfg_JOIN_INNER_TD_9665_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8484_cmds;
    cfg_JOIN_INNER_TD_8484_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8484_gqe_join (cfg_JOIN_INNER_TD_8484_cmds.cmd);
    cfg_JOIN_INNER_TD_8484_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8484_cmds_part;
    cfg_JOIN_INNER_TD_8484_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8484_gqe_join_part (cfg_JOIN_INNER_TD_8484_cmds_part.cmd);
    cfg_JOIN_INNER_TD_8484_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7889_cmds;
    cfg_JOIN_INNER_TD_7889_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7889_gqe_join (cfg_JOIN_INNER_TD_7889_cmds.cmd);
    cfg_JOIN_INNER_TD_7889_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7889_cmds_part;
    cfg_JOIN_INNER_TD_7889_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7889_gqe_join_part (cfg_JOIN_INNER_TD_7889_cmds_part.cmd);
    cfg_JOIN_INNER_TD_7889_cmds_part.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_586_part_right;
    krnl_JOIN_INNER_TD_586_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_586_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_Filter_TD_616_output, tbl_Filter_TD_616_output_partition, cfg_JOIN_INNER_TD_586_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_586[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_586[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_586[i].setup(tbl_JOIN_INNER_TD_9665_output_partition_array[i], tbl_Filter_TD_616_output_partition_array[i], tbl_JOIN_INNER_TD_586_output_partition_array[i], cfg_JOIN_INNER_TD_586_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_INNER_TD_9665_part_right;
    krnl_JOIN_INNER_TD_9665_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_9665_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_SerializeFromObject_TD_10268_input, tbl_SerializeFromObject_TD_10268_input_partition, cfg_JOIN_INNER_TD_9665_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_9665[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_9665[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_9665[i].setup(tbl_JOIN_INNER_TD_8484_output_partition_array[i], tbl_SerializeFromObject_TD_10268_input_partition_array[i], tbl_JOIN_INNER_TD_9665_output_partition_array[i], cfg_JOIN_INNER_TD_9665_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_INNER_TD_8484_part_left;
    krnl_JOIN_INNER_TD_8484_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_8484_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_SerializeFromObject_TD_10678_input, tbl_SerializeFromObject_TD_10678_input_partition, cfg_JOIN_INNER_TD_8484_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_8484[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_8484[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_8484[i].setup(tbl_SerializeFromObject_TD_10678_input_partition_array[i], tbl_JOIN_INNER_TD_7889_output_partition_array[i], tbl_JOIN_INNER_TD_8484_output_partition_array[i], cfg_JOIN_INNER_TD_8484_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_INNER_TD_7889_part_left;
    krnl_JOIN_INNER_TD_7889_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_7889_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_SerializeFromObject_TD_96_input, tbl_SerializeFromObject_TD_96_input_partition, cfg_JOIN_INNER_TD_7889_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_7889_part_right;
    krnl_JOIN_INNER_TD_7889_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_7889_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_Filter_TD_8820_output, tbl_Filter_TD_8820_output_partition, cfg_JOIN_INNER_TD_7889_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_7889[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_7889[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_7889[i].setup(tbl_SerializeFromObject_TD_96_input_partition_array[i], tbl_Filter_TD_8820_output_partition_array[i], tbl_JOIN_INNER_TD_7889_output_partition_array[i], cfg_JOIN_INNER_TD_7889_cmds, buftmp_h);
    }
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_586;
    trans_JOIN_INNER_TD_586.setq(q_h);
    trans_JOIN_INNER_TD_586.add(&(cfg_JOIN_INNER_TD_586_cmds_part));
    trans_JOIN_INNER_TD_586.add(&(cfg_JOIN_INNER_TD_586_cmds));
    transEngine trans_JOIN_INNER_TD_586_out;
    trans_JOIN_INNER_TD_586_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_9665;
    trans_JOIN_INNER_TD_9665.setq(q_h);
    trans_JOIN_INNER_TD_9665.add(&(cfg_JOIN_INNER_TD_9665_cmds));
    trans_JOIN_INNER_TD_9665.add(&(tbl_SerializeFromObject_TD_10268_input));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_8484;
    trans_JOIN_INNER_TD_8484.setq(q_h);
    trans_JOIN_INNER_TD_8484.add(&(cfg_JOIN_INNER_TD_8484_cmds));
    trans_JOIN_INNER_TD_8484.add(&(tbl_SerializeFromObject_TD_10678_input));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_7889;
    trans_JOIN_INNER_TD_7889.setq(q_h);
    trans_JOIN_INNER_TD_7889.add(&(cfg_JOIN_INNER_TD_7889_cmds_part));
    trans_JOIN_INNER_TD_7889.add(&(cfg_JOIN_INNER_TD_7889_cmds));
    trans_JOIN_INNER_TD_7889.add(&(tbl_SerializeFromObject_TD_96_input));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_586;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_586;
    std::vector<cl::Event> events_JOIN_INNER_TD_586[2];
    events_h2d_wr_JOIN_INNER_TD_586.resize(1);
    events_d2h_rd_JOIN_INNER_TD_586.resize(1);
    events_JOIN_INNER_TD_586[0].resize(1);
    events_JOIN_INNER_TD_586[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_586;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_586;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_9665;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_9665;
    std::vector<cl::Event> events_JOIN_INNER_TD_9665[2];
    events_h2d_wr_JOIN_INNER_TD_9665.resize(1);
    events_d2h_rd_JOIN_INNER_TD_9665.resize(1);
    events_JOIN_INNER_TD_9665[0].resize(1);
    events_JOIN_INNER_TD_9665[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_9665;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_9665;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8484;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8484;
    std::vector<cl::Event> events_JOIN_INNER_TD_8484[2];
    events_h2d_wr_JOIN_INNER_TD_8484.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8484.resize(1);
    events_JOIN_INNER_TD_8484[0].resize(1);
    events_JOIN_INNER_TD_8484[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8484;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8484;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7889;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7889;
    std::vector<cl::Event> events_JOIN_INNER_TD_7889[2];
    events_h2d_wr_JOIN_INNER_TD_7889.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7889.resize(1);
    events_JOIN_INNER_TD_7889[0].resize(2);
    events_JOIN_INNER_TD_7889[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7889;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7889;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_8_519_s, tv_r_Filter_8_519_e;
    gettimeofday(&tv_r_Filter_8_519_s, 0);
    SW_Filter_TD_8820(tbl_SerializeFromObject_TD_9414_input, tbl_Filter_TD_8820_output);
    gettimeofday(&tv_r_Filter_8_519_e, 0);

    struct timeval tv_r_JOIN_INNER_7_490_s, tv_r_JOIN_INNER_7_490_e;
    gettimeofday(&tv_r_JOIN_INNER_7_490_s, 0);
    trans_JOIN_INNER_TD_7889.add(&(tbl_Filter_TD_8820_output));
    trans_JOIN_INNER_TD_7889.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7889), &(events_h2d_wr_JOIN_INNER_TD_7889[0]));
    events_grp_JOIN_INNER_TD_7889.push_back(events_h2d_wr_JOIN_INNER_TD_7889[0]);
    krnl_JOIN_INNER_TD_7889_part_left.run(0, &(events_grp_JOIN_INNER_TD_7889), &(events_JOIN_INNER_TD_7889[0][0]));
    krnl_JOIN_INNER_TD_7889_part_right.run(0, &(events_grp_JOIN_INNER_TD_7889), &(events_JOIN_INNER_TD_7889[0][1]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_7889[i].run(0, &(events_JOIN_INNER_TD_7889[0]), &(events_JOIN_INNER_TD_7889[1][i]));
    }
    gettimeofday(&tv_r_JOIN_INNER_7_490_e, 0);

    struct timeval tv_r_JOIN_INNER_8_356_s, tv_r_JOIN_INNER_8_356_e;
    gettimeofday(&tv_r_JOIN_INNER_8_356_s, 0);
    prev_events_grp_JOIN_INNER_TD_8484.push_back(events_h2d_wr_JOIN_INNER_TD_7889[0]);
    trans_JOIN_INNER_TD_8484.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8484), &(events_h2d_wr_JOIN_INNER_TD_8484[0]));
    events_grp_JOIN_INNER_TD_8484.push_back(events_h2d_wr_JOIN_INNER_TD_8484[0]);
    events_grp_JOIN_INNER_TD_8484.insert(std::end(events_grp_JOIN_INNER_TD_8484), std::begin(events_JOIN_INNER_TD_7889[0]), std::end(events_JOIN_INNER_TD_7889[0]));
    events_grp_JOIN_INNER_TD_8484.insert(std::end(events_grp_JOIN_INNER_TD_8484), std::begin(events_JOIN_INNER_TD_7889[1]), std::end(events_JOIN_INNER_TD_7889[1]));
    krnl_JOIN_INNER_TD_8484_part_left.run(0, &(events_grp_JOIN_INNER_TD_8484), &(events_JOIN_INNER_TD_8484[0][0]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_8484[i].run(0, &(events_JOIN_INNER_TD_8484[0]), &(events_JOIN_INNER_TD_8484[1][i]));
    }
    gettimeofday(&tv_r_JOIN_INNER_8_356_e, 0);

    struct timeval tv_r_JOIN_INNER_9_342_s, tv_r_JOIN_INNER_9_342_e;
    gettimeofday(&tv_r_JOIN_INNER_9_342_s, 0);
    prev_events_grp_JOIN_INNER_TD_9665.push_back(events_h2d_wr_JOIN_INNER_TD_8484[0]);
    trans_JOIN_INNER_TD_9665.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_9665), &(events_h2d_wr_JOIN_INNER_TD_9665[0]));
    events_grp_JOIN_INNER_TD_9665.push_back(events_h2d_wr_JOIN_INNER_TD_9665[0]);
    events_grp_JOIN_INNER_TD_9665.insert(std::end(events_grp_JOIN_INNER_TD_9665), std::begin(events_JOIN_INNER_TD_8484[0]), std::end(events_JOIN_INNER_TD_8484[0]));
    events_grp_JOIN_INNER_TD_9665.insert(std::end(events_grp_JOIN_INNER_TD_9665), std::begin(events_JOIN_INNER_TD_8484[1]), std::end(events_JOIN_INNER_TD_8484[1]));
    krnl_JOIN_INNER_TD_9665_part_right.run(0, &(events_grp_JOIN_INNER_TD_9665), &(events_JOIN_INNER_TD_9665[0][0]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_9665[i].run(0, &(events_grp_JOIN_INNER_TD_9665), &(events_JOIN_INNER_TD_9665[1][i]));
    }
    gettimeofday(&tv_r_JOIN_INNER_9_342_e, 0);

    struct timeval tv_r_Filter_6_242_s, tv_r_Filter_6_242_e;
    gettimeofday(&tv_r_Filter_6_242_s, 0);
    SW_Filter_TD_616(tbl_SerializeFromObject_TD_7652_input, tbl_Filter_TD_616_output);
    gettimeofday(&tv_r_Filter_6_242_e, 0);

    struct timeval tv_r_JOIN_INNER_5_440_s, tv_r_JOIN_INNER_5_440_e;
    gettimeofday(&tv_r_JOIN_INNER_5_440_s, 0);
    prev_events_grp_JOIN_INNER_TD_586.push_back(events_h2d_wr_JOIN_INNER_TD_9665[0]);
    trans_JOIN_INNER_TD_586.add(&(tbl_Filter_TD_616_output));
    trans_JOIN_INNER_TD_586.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_586), &(events_h2d_wr_JOIN_INNER_TD_586[0]));
    events_grp_JOIN_INNER_TD_586.push_back(events_h2d_wr_JOIN_INNER_TD_586[0]);
    events_grp_JOIN_INNER_TD_586.insert(std::end(events_grp_JOIN_INNER_TD_586), std::begin(events_JOIN_INNER_TD_9665[0]), std::end(events_JOIN_INNER_TD_9665[0]));
    events_grp_JOIN_INNER_TD_586.insert(std::end(events_grp_JOIN_INNER_TD_586), std::begin(events_JOIN_INNER_TD_9665[1]), std::end(events_JOIN_INNER_TD_9665[1]));
    krnl_JOIN_INNER_TD_586_part_right.run(0, &(events_grp_JOIN_INNER_TD_586), &(events_JOIN_INNER_TD_586[0][0]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_586[i].run(0, &(events_grp_JOIN_INNER_TD_586), &(events_JOIN_INNER_TD_586[1][i]));
    }
    
    for (int i(0); i < hpTimes_join; ++i) {
        trans_JOIN_INNER_TD_586_out.add(&(tbl_JOIN_INNER_TD_586_output_partition_array[i]));
    }
    trans_JOIN_INNER_TD_586_out.dev2host(0, &(events_JOIN_INNER_TD_586[1]), &(events_d2h_rd_JOIN_INNER_TD_586[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_5_440_e, 0);

    struct timeval tv_r_Aggregate_6_140_s, tv_r_Aggregate_6_140_e;
    gettimeofday(&tv_r_Aggregate_6_140_s, 0);
    SW_Aggregate_TD_6211(tbl_JOIN_INNER_TD_586_output_partition_array, tbl_Aggregate_TD_6211_output, hpTimes_join);
    gettimeofday(&tv_r_Aggregate_6_140_e, 0);

    struct timeval tv_r_JOIN_INNER_4_436_s, tv_r_JOIN_INNER_4_436_e;
    gettimeofday(&tv_r_JOIN_INNER_4_436_s, 0);
    SW_JOIN_INNER_TD_4801(tbl_JOIN_INNER_TD_586_output_partition_array, tbl_Aggregate_TD_6211_output, tbl_JOIN_INNER_TD_4801_output, hpTimes_join);
    gettimeofday(&tv_r_JOIN_INNER_4_436_e, 0);

    struct timeval tv_r_JOIN_INNER_3_966_s, tv_r_JOIN_INNER_3_966_e;
    gettimeofday(&tv_r_JOIN_INNER_3_966_s, 0);
    SW_JOIN_INNER_TD_391(tbl_JOIN_INNER_TD_4801_output, tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute, tbl_JOIN_INNER_TD_391_output);
    gettimeofday(&tv_r_JOIN_INNER_3_966_e, 0);

    struct timeval tv_r_JOIN_INNER_2_357_s, tv_r_JOIN_INNER_2_357_e;
    gettimeofday(&tv_r_JOIN_INNER_2_357_s, 0);
    SW_JOIN_INNER_TD_2303(tbl_JOIN_INNER_TD_391_output, tbl_SerializeFromObject_TD_3496_input_stringRowIDSubstitute, tbl_JOIN_INNER_TD_2303_output);
    gettimeofday(&tv_r_JOIN_INNER_2_357_e, 0);

    struct timeval tv_r_JOIN_INNER_1_284_s, tv_r_JOIN_INNER_1_284_e;
    gettimeofday(&tv_r_JOIN_INNER_1_284_s, 0);
    SW_JOIN_INNER_TD_1293(tbl_JOIN_INNER_TD_2303_output, tbl_Filter_TD_8820_output, tbl_JOIN_INNER_TD_1293_output);
    gettimeofday(&tv_r_JOIN_INNER_1_284_e, 0);

    struct timeval tv_r_Sort_0_26_s, tv_r_Sort_0_26_e;
    gettimeofday(&tv_r_Sort_0_26_s, 0);
    SW_Sort_TD_0435(tbl_JOIN_INNER_TD_1293_output, tbl_SerializeFromObject_TD_7652_input, tbl_SerializeFromObject_TD_4939_input, tbl_SerializeFromObject_TD_3496_input, tbl_Sort_TD_0435_output);
    gettimeofday(&tv_r_Sort_0_26_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_519_s, &tv_r_Filter_8_519_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9414_input: " << tbl_SerializeFromObject_TD_9414_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_490_s, &tv_r_JOIN_INNER_7_490_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_96_input: " << tbl_SerializeFromObject_TD_96_input.getNumRow() << " " << "tbl_Filter_TD_8820_output: " << tbl_Filter_TD_8820_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_356_s, &tv_r_JOIN_INNER_8_356_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10678_input: " << tbl_SerializeFromObject_TD_10678_input.getNumRow() << " " << "tbl_JOIN_INNER_TD_7889_output: " << tbl_JOIN_INNER_TD_7889_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_342_s, &tv_r_JOIN_INNER_9_342_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8484_output: " << tbl_JOIN_INNER_TD_8484_output.getNumRow() << " " << "tbl_SerializeFromObject_TD_10268_input: " << tbl_SerializeFromObject_TD_10268_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_242_s, &tv_r_Filter_6_242_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7652_input: " << tbl_SerializeFromObject_TD_7652_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_440_s, &tv_r_JOIN_INNER_5_440_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_616_output: " << tbl_Filter_TD_616_output.getNumRow() << " " << "tbl_JOIN_INNER_TD_9665_output: " << tbl_JOIN_INNER_TD_9665_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_6: " << tvdiff(&tv_r_Aggregate_6_140_s, &tv_r_Aggregate_6_140_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_586_output: " << tbl_JOIN_INNER_TD_586_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_436_s, &tv_r_JOIN_INNER_4_436_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_586_output: " << tbl_JOIN_INNER_TD_586_output.getNumRow() << " " << "tbl_Aggregate_TD_6211_output: " << tbl_Aggregate_TD_6211_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_966_s, &tv_r_JOIN_INNER_3_966_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4801_output: " << tbl_JOIN_INNER_TD_4801_output.getNumRow() << " " << "tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute: " << tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_2: " << tvdiff(&tv_r_JOIN_INNER_2_357_s, &tv_r_JOIN_INNER_2_357_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_391_output: " << tbl_JOIN_INNER_TD_391_output.getNumRow() << " " << "tbl_SerializeFromObject_TD_3496_input_stringRowIDSubstitute: " << tbl_SerializeFromObject_TD_3496_input_stringRowIDSubstitute.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_1: " << tvdiff(&tv_r_JOIN_INNER_1_284_s, &tv_r_JOIN_INNER_1_284_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_2303_output: " << tbl_JOIN_INNER_TD_2303_output.getNumRow() << " " << "tbl_Filter_TD_8820_output: " << tbl_Filter_TD_8820_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_26_s, &tv_r_Sort_0_26_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_1293_output: " << tbl_JOIN_INNER_TD_1293_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 101.16047 * 1000 << "ms" << std::endl; 
    return 0; 
}
