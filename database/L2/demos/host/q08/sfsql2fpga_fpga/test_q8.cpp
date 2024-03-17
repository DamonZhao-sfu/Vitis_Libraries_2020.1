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

#include "cfgFunc_q8.hpp" 
#include "q8.hpp" 

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
    std::cout << "NOTE:running query #8\n."; 
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
    Table tbl_Sort_TD_027_output("tbl_Sort_TD_027_output", 183000000, 2, "");
    tbl_Sort_TD_027_output.allocateHost();
    Table tbl_Aggregate_TD_1108_output("tbl_Aggregate_TD_1108_output", 183000000, 2, "");
    tbl_Aggregate_TD_1108_output.allocateHost();
    Table tbl_Project_TD_2953_output("tbl_Project_TD_2953_output", 183000000, 3, "");
    tbl_Project_TD_2953_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3467_output("tbl_JOIN_INNER_TD_3467_output", 183000000, 4, "");
    tbl_JOIN_INNER_TD_3467_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4178_output("tbl_JOIN_INNER_TD_4178_output", 2539, 5, "");
    tbl_JOIN_INNER_TD_4178_output.allocateHost(1.2, hpTimes_join);
    Table tbl_SerializeFromObject_TD_4614_input;
    tbl_SerializeFromObject_TD_4614_input = Table("nation", nation_n, 2, in_dir);
    tbl_SerializeFromObject_TD_4614_input.addCol("n_nationkey", 4);
    tbl_SerializeFromObject_TD_4614_input.addCol("n_name", TPCH_READ_NATION_LEN+1);
    tbl_SerializeFromObject_TD_4614_input.allocateHost();
    tbl_SerializeFromObject_TD_4614_input.loadHost();
    Table tbl_JOIN_INNER_TD_5622_output("tbl_JOIN_INNER_TD_5622_output", 12215, 5, "");
    tbl_JOIN_INNER_TD_5622_output.allocateHost(1.2, hpTimes_join);
    Table tbl_Filter_TD_4155_output("tbl_Filter_TD_4155_output", 183000000, 1, "");
    tbl_Filter_TD_4155_output.allocateHost();
    Table tbl_Filter_TD_4155_output_partition("tbl_Filter_TD_4155_output_partition", 183000000, 1, "");
    tbl_Filter_TD_4155_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_Filter_TD_4155_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_Filter_TD_4155_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_4155_output_partition_array[i] = tbl_Filter_TD_4155_output_partition.createSubTable(i);
    }
    Table tbl_JOIN_INNER_TD_6380_output("tbl_JOIN_INNER_TD_6380_output", 12215, 5, "");
    tbl_JOIN_INNER_TD_6380_output.allocateHost(1.2, hpTimes_join);
    Table tbl_SerializeFromObject_TD_6254_input;
    tbl_SerializeFromObject_TD_6254_input = Table("nation", nation_n, 2, in_dir);
    tbl_SerializeFromObject_TD_6254_input.addCol("n_nationkey", 4);
    tbl_SerializeFromObject_TD_6254_input.addCol("n_regionkey", 4);
    tbl_SerializeFromObject_TD_6254_input.allocateHost();
    tbl_SerializeFromObject_TD_6254_input.loadHost();
    Table tbl_SerializeFromObject_TD_6254_input_partition("tbl_SerializeFromObject_TD_6254_input_partition", nation_n, 2, "");
    tbl_SerializeFromObject_TD_6254_input_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_6254_input_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_6254_input_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_6254_input_partition_array[i] = tbl_SerializeFromObject_TD_6254_input_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_5297_input;
    tbl_SerializeFromObject_TD_5297_input = Table("region", region_n, 2, in_dir);
    tbl_SerializeFromObject_TD_5297_input.addCol("r_regionkey", 4);
    tbl_SerializeFromObject_TD_5297_input.addCol("r_name", TPCH_READ_REGION_LEN+1);
    tbl_SerializeFromObject_TD_5297_input.allocateHost();
    tbl_SerializeFromObject_TD_5297_input.loadHost();
    Table tbl_JOIN_INNER_TD_7371_output("tbl_JOIN_INNER_TD_7371_output", 12215, 5, "");
    tbl_JOIN_INNER_TD_7371_output.allocateHost(1.2, hpTimes_join);
    Table tbl_SerializeFromObject_TD_7418_input;
    tbl_SerializeFromObject_TD_7418_input = Table("customer", customer_n, 2, in_dir);
    tbl_SerializeFromObject_TD_7418_input.addCol("c_custkey", 4);
    tbl_SerializeFromObject_TD_7418_input.addCol("c_nationkey", 4);
    tbl_SerializeFromObject_TD_7418_input.allocateHost();
    tbl_SerializeFromObject_TD_7418_input.loadHost();
    Table tbl_SerializeFromObject_TD_7418_input_partition("tbl_SerializeFromObject_TD_7418_input_partition", customer_n, 2, "");
    tbl_SerializeFromObject_TD_7418_input_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_7418_input_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_7418_input_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_7418_input_partition_array[i] = tbl_SerializeFromObject_TD_7418_input_partition.createSubTable(i);
    }
    Table tbl_JOIN_INNER_TD_863_output("tbl_JOIN_INNER_TD_863_output", 39720, 4, "");
    tbl_JOIN_INNER_TD_863_output.allocateHost(1.2, hpTimes_join);
    Table tbl_Filter_TD_8923_output("tbl_Filter_TD_8923_output", 183000000, 3, "");
    tbl_Filter_TD_8923_output.allocateHost();
    Table tbl_Filter_TD_8923_output_partition("tbl_Filter_TD_8923_output_partition", 183000000, 3, "");
    tbl_Filter_TD_8923_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_Filter_TD_8923_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_Filter_TD_8923_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_8923_output_partition_array[i] = tbl_Filter_TD_8923_output_partition.createSubTable(i);
    }
    Table tbl_JOIN_INNER_TD_9757_output("tbl_JOIN_INNER_TD_9757_output", 39720, 4, "");
    tbl_JOIN_INNER_TD_9757_output.allocateHost(1.2, hpTimes_join);
    Table tbl_SerializeFromObject_TD_9913_input;
    tbl_SerializeFromObject_TD_9913_input = Table("supplier", supplier_n, 2, in_dir);
    tbl_SerializeFromObject_TD_9913_input.addCol("s_suppkey", 4);
    tbl_SerializeFromObject_TD_9913_input.addCol("s_nationkey", 4);
    tbl_SerializeFromObject_TD_9913_input.allocateHost();
    tbl_SerializeFromObject_TD_9913_input.loadHost();
    Table tbl_SerializeFromObject_TD_9913_input_partition("tbl_SerializeFromObject_TD_9913_input_partition", supplier_n, 2, "");
    tbl_SerializeFromObject_TD_9913_input_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_9913_input_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_9913_input_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_9913_input_partition_array[i] = tbl_SerializeFromObject_TD_9913_input_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_9538_input;
    tbl_SerializeFromObject_TD_9538_input = Table("order", order_n, 3, in_dir);
    tbl_SerializeFromObject_TD_9538_input.addCol("o_orderkey", 4);
    tbl_SerializeFromObject_TD_9538_input.addCol("o_custkey", 4);
    tbl_SerializeFromObject_TD_9538_input.addCol("o_orderdate", 4);
    tbl_SerializeFromObject_TD_9538_input.allocateHost();
    tbl_SerializeFromObject_TD_9538_input.loadHost();
    Table tbl_Filter_TD_10213_output("tbl_Filter_TD_10213_output", 183000000, 1, "");
    tbl_Filter_TD_10213_output.allocateHost();
    Table tbl_Filter_TD_10213_output_partition("tbl_Filter_TD_10213_output_partition", 183000000, 1, "");
    tbl_Filter_TD_10213_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_Filter_TD_10213_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_Filter_TD_10213_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_10213_output_partition_array[i] = tbl_Filter_TD_10213_output_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_10580_input;
    tbl_SerializeFromObject_TD_10580_input = Table("lineitem", lineitem_n, 5, in_dir);
    tbl_SerializeFromObject_TD_10580_input.addCol("l_orderkey", 4);
    tbl_SerializeFromObject_TD_10580_input.addCol("l_partkey", 4);
    tbl_SerializeFromObject_TD_10580_input.addCol("l_suppkey", 4);
    tbl_SerializeFromObject_TD_10580_input.addCol("l_extendedprice", 4);
    tbl_SerializeFromObject_TD_10580_input.addCol("l_discount", 4);
    tbl_SerializeFromObject_TD_10580_input.allocateHost();
    tbl_SerializeFromObject_TD_10580_input.loadHost();
    Table tbl_SerializeFromObject_TD_10580_input_partition("tbl_SerializeFromObject_TD_10580_input_partition", lineitem_n, 5, "");
    tbl_SerializeFromObject_TD_10580_input_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_10580_input_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_10580_input_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_10580_input_partition_array[i] = tbl_SerializeFromObject_TD_10580_input_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_11625_input;
    tbl_SerializeFromObject_TD_11625_input = Table("part", part_n, 2, in_dir);
    tbl_SerializeFromObject_TD_11625_input.addCol("p_partkey", 4);
    tbl_SerializeFromObject_TD_11625_input.addCol("p_type", TPCH_READ_P_TYPE_LEN+1);
    tbl_SerializeFromObject_TD_11625_input.allocateHost();
    tbl_SerializeFromObject_TD_11625_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_4178_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_4178_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_4178_output_partition_array[i] = tbl_JOIN_INNER_TD_4178_output.createSubTable(i);
    }
    tbl_JOIN_INNER_TD_5622_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_5622_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_5622_output_partition_array[i] = tbl_JOIN_INNER_TD_5622_output.createSubTable(i);
    }
    tbl_Filter_TD_4155_output.allocateDevBuffer(context_h, 33);
    tbl_JOIN_INNER_TD_6380_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_6380_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_6380_output_partition_array[i] = tbl_JOIN_INNER_TD_6380_output.createSubTable(i);
    }
    tbl_SerializeFromObject_TD_6254_input.allocateDevBuffer(context_h, 33);
    tbl_JOIN_INNER_TD_7371_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_7371_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_7371_output_partition_array[i] = tbl_JOIN_INNER_TD_7371_output.createSubTable(i);
    }
    tbl_SerializeFromObject_TD_7418_input.allocateDevBuffer(context_h, 33);
    tbl_JOIN_INNER_TD_863_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_863_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_863_output_partition_array[i] = tbl_JOIN_INNER_TD_863_output.createSubTable(i);
    }
    tbl_Filter_TD_8923_output.allocateDevBuffer(context_h, 33);
    tbl_JOIN_INNER_TD_9757_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_9757_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_9757_output_partition_array[i] = tbl_JOIN_INNER_TD_9757_output.createSubTable(i);
    }
    tbl_SerializeFromObject_TD_9913_input.allocateDevBuffer(context_h, 33);
    tbl_Filter_TD_10213_output.allocateDevBuffer(context_h, 33);
    tbl_SerializeFromObject_TD_10580_input.allocateDevBuffer(context_h, 33);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_4178_cmds;
    cfg_JOIN_INNER_TD_4178_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_4178_gqe_join (cfg_JOIN_INNER_TD_4178_cmds.cmd);
    cfg_JOIN_INNER_TD_4178_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_4178_cmds_part;
    cfg_JOIN_INNER_TD_4178_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_4178_gqe_join_part (cfg_JOIN_INNER_TD_4178_cmds_part.cmd);
    cfg_JOIN_INNER_TD_4178_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_5622_cmds;
    cfg_JOIN_INNER_TD_5622_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_5622_gqe_join (cfg_JOIN_INNER_TD_5622_cmds.cmd);
    cfg_JOIN_INNER_TD_5622_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_5622_cmds_part;
    cfg_JOIN_INNER_TD_5622_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_5622_gqe_join_part (cfg_JOIN_INNER_TD_5622_cmds_part.cmd);
    cfg_JOIN_INNER_TD_5622_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_6380_cmds;
    cfg_JOIN_INNER_TD_6380_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_6380_gqe_join (cfg_JOIN_INNER_TD_6380_cmds.cmd);
    cfg_JOIN_INNER_TD_6380_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_6380_cmds_part;
    cfg_JOIN_INNER_TD_6380_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_6380_gqe_join_part (cfg_JOIN_INNER_TD_6380_cmds_part.cmd);
    cfg_JOIN_INNER_TD_6380_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7371_cmds;
    cfg_JOIN_INNER_TD_7371_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7371_gqe_join (cfg_JOIN_INNER_TD_7371_cmds.cmd);
    cfg_JOIN_INNER_TD_7371_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7371_cmds_part;
    cfg_JOIN_INNER_TD_7371_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7371_gqe_join_part (cfg_JOIN_INNER_TD_7371_cmds_part.cmd);
    cfg_JOIN_INNER_TD_7371_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_863_cmds;
    cfg_JOIN_INNER_TD_863_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_863_gqe_join (cfg_JOIN_INNER_TD_863_cmds.cmd);
    cfg_JOIN_INNER_TD_863_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_863_cmds_part;
    cfg_JOIN_INNER_TD_863_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_863_gqe_join_part (cfg_JOIN_INNER_TD_863_cmds_part.cmd);
    cfg_JOIN_INNER_TD_863_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_9757_cmds;
    cfg_JOIN_INNER_TD_9757_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_9757_gqe_join (cfg_JOIN_INNER_TD_9757_cmds.cmd);
    cfg_JOIN_INNER_TD_9757_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_9757_cmds_part;
    cfg_JOIN_INNER_TD_9757_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_9757_gqe_join_part (cfg_JOIN_INNER_TD_9757_cmds_part.cmd);
    cfg_JOIN_INNER_TD_9757_cmds_part.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_4178_part_left;
    krnl_JOIN_INNER_TD_4178_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_4178_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_Filter_TD_4155_output, tbl_Filter_TD_4155_output_partition, cfg_JOIN_INNER_TD_4178_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_4178[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_4178[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_4178[i].setup(tbl_Filter_TD_4155_output_partition_array[i], tbl_JOIN_INNER_TD_5622_output_partition_array[i], tbl_JOIN_INNER_TD_4178_output_partition_array[i], cfg_JOIN_INNER_TD_4178_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_INNER_TD_5622_part_left;
    krnl_JOIN_INNER_TD_5622_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_5622_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_SerializeFromObject_TD_6254_input, tbl_SerializeFromObject_TD_6254_input_partition, cfg_JOIN_INNER_TD_5622_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_5622[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_5622[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_5622[i].setup(tbl_SerializeFromObject_TD_6254_input_partition_array[i], tbl_JOIN_INNER_TD_6380_output_partition_array[i], tbl_JOIN_INNER_TD_5622_output_partition_array[i], cfg_JOIN_INNER_TD_5622_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_INNER_TD_6380_part_right;
    krnl_JOIN_INNER_TD_6380_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_6380_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_SerializeFromObject_TD_7418_input, tbl_SerializeFromObject_TD_7418_input_partition, cfg_JOIN_INNER_TD_6380_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_6380[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_6380[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_6380[i].setup(tbl_JOIN_INNER_TD_7371_output_partition_array[i], tbl_SerializeFromObject_TD_7418_input_partition_array[i], tbl_JOIN_INNER_TD_6380_output_partition_array[i], cfg_JOIN_INNER_TD_6380_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_INNER_TD_7371_part_right;
    krnl_JOIN_INNER_TD_7371_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_7371_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_Filter_TD_8923_output, tbl_Filter_TD_8923_output_partition, cfg_JOIN_INNER_TD_7371_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_7371[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_7371[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_7371[i].setup(tbl_JOIN_INNER_TD_863_output_partition_array[i], tbl_Filter_TD_8923_output_partition_array[i], tbl_JOIN_INNER_TD_7371_output_partition_array[i], cfg_JOIN_INNER_TD_7371_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_INNER_TD_863_part_left;
    krnl_JOIN_INNER_TD_863_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_863_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_SerializeFromObject_TD_9913_input, tbl_SerializeFromObject_TD_9913_input_partition, cfg_JOIN_INNER_TD_863_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_863[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_863[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_863[i].setup(tbl_SerializeFromObject_TD_9913_input_partition_array[i], tbl_JOIN_INNER_TD_9757_output_partition_array[i], tbl_JOIN_INNER_TD_863_output_partition_array[i], cfg_JOIN_INNER_TD_863_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_INNER_TD_9757_part_left;
    krnl_JOIN_INNER_TD_9757_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_9757_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_Filter_TD_10213_output, tbl_Filter_TD_10213_output_partition, cfg_JOIN_INNER_TD_9757_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_9757_part_right;
    krnl_JOIN_INNER_TD_9757_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_9757_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_SerializeFromObject_TD_10580_input, tbl_SerializeFromObject_TD_10580_input_partition, cfg_JOIN_INNER_TD_9757_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_9757[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_9757[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_9757[i].setup(tbl_Filter_TD_10213_output_partition_array[i], tbl_SerializeFromObject_TD_10580_input_partition_array[i], tbl_JOIN_INNER_TD_9757_output_partition_array[i], cfg_JOIN_INNER_TD_9757_cmds, buftmp_h);
    }
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_4178;
    trans_JOIN_INNER_TD_4178.setq(q_h);
    trans_JOIN_INNER_TD_4178.add(&(cfg_JOIN_INNER_TD_4178_cmds_part));
    trans_JOIN_INNER_TD_4178.add(&(cfg_JOIN_INNER_TD_4178_cmds));
    transEngine trans_JOIN_INNER_TD_4178_out;
    trans_JOIN_INNER_TD_4178_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_5622;
    trans_JOIN_INNER_TD_5622.setq(q_h);
    trans_JOIN_INNER_TD_5622.add(&(cfg_JOIN_INNER_TD_5622_cmds));
    trans_JOIN_INNER_TD_5622.add(&(tbl_SerializeFromObject_TD_6254_input));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_6380;
    trans_JOIN_INNER_TD_6380.setq(q_h);
    trans_JOIN_INNER_TD_6380.add(&(cfg_JOIN_INNER_TD_6380_cmds));
    trans_JOIN_INNER_TD_6380.add(&(tbl_SerializeFromObject_TD_7418_input));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_7371;
    trans_JOIN_INNER_TD_7371.setq(q_h);
    trans_JOIN_INNER_TD_7371.add(&(cfg_JOIN_INNER_TD_7371_cmds_part));
    trans_JOIN_INNER_TD_7371.add(&(cfg_JOIN_INNER_TD_7371_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_863;
    trans_JOIN_INNER_TD_863.setq(q_h);
    trans_JOIN_INNER_TD_863.add(&(cfg_JOIN_INNER_TD_863_cmds));
    trans_JOIN_INNER_TD_863.add(&(tbl_SerializeFromObject_TD_9913_input));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_9757;
    trans_JOIN_INNER_TD_9757.setq(q_h);
    trans_JOIN_INNER_TD_9757.add(&(cfg_JOIN_INNER_TD_9757_cmds_part));
    trans_JOIN_INNER_TD_9757.add(&(cfg_JOIN_INNER_TD_9757_cmds));
    trans_JOIN_INNER_TD_9757.add(&(tbl_SerializeFromObject_TD_10580_input));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_4178;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_4178;
    std::vector<cl::Event> events_JOIN_INNER_TD_4178[2];
    events_h2d_wr_JOIN_INNER_TD_4178.resize(1);
    events_d2h_rd_JOIN_INNER_TD_4178.resize(1);
    events_JOIN_INNER_TD_4178[0].resize(1);
    events_JOIN_INNER_TD_4178[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_4178;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_4178;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_5622;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_5622;
    std::vector<cl::Event> events_JOIN_INNER_TD_5622[2];
    events_h2d_wr_JOIN_INNER_TD_5622.resize(1);
    events_d2h_rd_JOIN_INNER_TD_5622.resize(1);
    events_JOIN_INNER_TD_5622[0].resize(1);
    events_JOIN_INNER_TD_5622[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_5622;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_5622;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_6380;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_6380;
    std::vector<cl::Event> events_JOIN_INNER_TD_6380[2];
    events_h2d_wr_JOIN_INNER_TD_6380.resize(1);
    events_d2h_rd_JOIN_INNER_TD_6380.resize(1);
    events_JOIN_INNER_TD_6380[0].resize(1);
    events_JOIN_INNER_TD_6380[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_6380;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_6380;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7371;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7371;
    std::vector<cl::Event> events_JOIN_INNER_TD_7371[2];
    events_h2d_wr_JOIN_INNER_TD_7371.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7371.resize(1);
    events_JOIN_INNER_TD_7371[0].resize(1);
    events_JOIN_INNER_TD_7371[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7371;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7371;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_863;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_863;
    std::vector<cl::Event> events_JOIN_INNER_TD_863[2];
    events_h2d_wr_JOIN_INNER_TD_863.resize(1);
    events_d2h_rd_JOIN_INNER_TD_863.resize(1);
    events_JOIN_INNER_TD_863[0].resize(1);
    events_JOIN_INNER_TD_863[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_863;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_863;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_9757;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_9757;
    std::vector<cl::Event> events_JOIN_INNER_TD_9757[2];
    events_h2d_wr_JOIN_INNER_TD_9757.resize(1);
    events_d2h_rd_JOIN_INNER_TD_9757.resize(1);
    events_JOIN_INNER_TD_9757[0].resize(2);
    events_JOIN_INNER_TD_9757[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_9757;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_9757;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_10_833_s, tv_r_Filter_10_833_e;
    gettimeofday(&tv_r_Filter_10_833_s, 0);
    SW_Filter_TD_10213(tbl_SerializeFromObject_TD_11625_input, tbl_Filter_TD_10213_output);
    gettimeofday(&tv_r_Filter_10_833_e, 0);

    struct timeval tv_r_JOIN_INNER_9_581_s, tv_r_JOIN_INNER_9_581_e;
    gettimeofday(&tv_r_JOIN_INNER_9_581_s, 0);
    trans_JOIN_INNER_TD_9757.add(&(tbl_Filter_TD_10213_output));
    trans_JOIN_INNER_TD_9757.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_9757), &(events_h2d_wr_JOIN_INNER_TD_9757[0]));
    events_grp_JOIN_INNER_TD_9757.push_back(events_h2d_wr_JOIN_INNER_TD_9757[0]);
    krnl_JOIN_INNER_TD_9757_part_left.run(0, &(events_grp_JOIN_INNER_TD_9757), &(events_JOIN_INNER_TD_9757[0][0]));
    krnl_JOIN_INNER_TD_9757_part_right.run(0, &(events_grp_JOIN_INNER_TD_9757), &(events_JOIN_INNER_TD_9757[0][1]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_9757[i].run(0, &(events_JOIN_INNER_TD_9757[0]), &(events_JOIN_INNER_TD_9757[1][i]));
    }
    gettimeofday(&tv_r_JOIN_INNER_9_581_e, 0);

    struct timeval tv_r_Filter_8_584_s, tv_r_Filter_8_584_e;
    gettimeofday(&tv_r_Filter_8_584_s, 0);
    SW_Filter_TD_8923(tbl_SerializeFromObject_TD_9538_input, tbl_Filter_TD_8923_output);
    gettimeofday(&tv_r_Filter_8_584_e, 0);

    struct timeval tv_r_JOIN_INNER_8_611_s, tv_r_JOIN_INNER_8_611_e;
    gettimeofday(&tv_r_JOIN_INNER_8_611_s, 0);
    prev_events_grp_JOIN_INNER_TD_863.push_back(events_h2d_wr_JOIN_INNER_TD_9757[0]);
    trans_JOIN_INNER_TD_863.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_863), &(events_h2d_wr_JOIN_INNER_TD_863[0]));
    events_grp_JOIN_INNER_TD_863.push_back(events_h2d_wr_JOIN_INNER_TD_863[0]);
    events_grp_JOIN_INNER_TD_863.insert(std::end(events_grp_JOIN_INNER_TD_863), std::begin(events_JOIN_INNER_TD_9757[0]), std::end(events_JOIN_INNER_TD_9757[0]));
    events_grp_JOIN_INNER_TD_863.insert(std::end(events_grp_JOIN_INNER_TD_863), std::begin(events_JOIN_INNER_TD_9757[1]), std::end(events_JOIN_INNER_TD_9757[1]));
    krnl_JOIN_INNER_TD_863_part_left.run(0, &(events_grp_JOIN_INNER_TD_863), &(events_JOIN_INNER_TD_863[0][0]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_863[i].run(0, &(events_JOIN_INNER_TD_863[0]), &(events_JOIN_INNER_TD_863[1][i]));
    }
    gettimeofday(&tv_r_JOIN_INNER_8_611_e, 0);

    struct timeval tv_r_JOIN_INNER_7_949_s, tv_r_JOIN_INNER_7_949_e;
    gettimeofday(&tv_r_JOIN_INNER_7_949_s, 0);
    prev_events_grp_JOIN_INNER_TD_7371.push_back(events_h2d_wr_JOIN_INNER_TD_863[0]);
    trans_JOIN_INNER_TD_7371.add(&(tbl_Filter_TD_8923_output));
    trans_JOIN_INNER_TD_7371.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7371), &(events_h2d_wr_JOIN_INNER_TD_7371[0]));
    events_grp_JOIN_INNER_TD_7371.push_back(events_h2d_wr_JOIN_INNER_TD_7371[0]);
    events_grp_JOIN_INNER_TD_7371.insert(std::end(events_grp_JOIN_INNER_TD_7371), std::begin(events_JOIN_INNER_TD_863[0]), std::end(events_JOIN_INNER_TD_863[0]));
    events_grp_JOIN_INNER_TD_7371.insert(std::end(events_grp_JOIN_INNER_TD_7371), std::begin(events_JOIN_INNER_TD_863[1]), std::end(events_JOIN_INNER_TD_863[1]));
    krnl_JOIN_INNER_TD_7371_part_right.run(0, &(events_grp_JOIN_INNER_TD_7371), &(events_JOIN_INNER_TD_7371[0][0]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_7371[i].run(0, &(events_grp_JOIN_INNER_TD_7371), &(events_JOIN_INNER_TD_7371[1][i]));
    }
    gettimeofday(&tv_r_JOIN_INNER_7_949_e, 0);

    struct timeval tv_r_JOIN_INNER_6_511_s, tv_r_JOIN_INNER_6_511_e;
    gettimeofday(&tv_r_JOIN_INNER_6_511_s, 0);
    prev_events_grp_JOIN_INNER_TD_6380.push_back(events_h2d_wr_JOIN_INNER_TD_7371[0]);
    trans_JOIN_INNER_TD_6380.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_6380), &(events_h2d_wr_JOIN_INNER_TD_6380[0]));
    events_grp_JOIN_INNER_TD_6380.push_back(events_h2d_wr_JOIN_INNER_TD_6380[0]);
    events_grp_JOIN_INNER_TD_6380.insert(std::end(events_grp_JOIN_INNER_TD_6380), std::begin(events_JOIN_INNER_TD_7371[0]), std::end(events_JOIN_INNER_TD_7371[0]));
    events_grp_JOIN_INNER_TD_6380.insert(std::end(events_grp_JOIN_INNER_TD_6380), std::begin(events_JOIN_INNER_TD_7371[1]), std::end(events_JOIN_INNER_TD_7371[1]));
    krnl_JOIN_INNER_TD_6380_part_right.run(0, &(events_grp_JOIN_INNER_TD_6380), &(events_JOIN_INNER_TD_6380[0][0]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_6380[i].run(0, &(events_grp_JOIN_INNER_TD_6380), &(events_JOIN_INNER_TD_6380[1][i]));
    }
    gettimeofday(&tv_r_JOIN_INNER_6_511_e, 0);

    struct timeval tv_r_Filter_4_375_s, tv_r_Filter_4_375_e;
    gettimeofday(&tv_r_Filter_4_375_s, 0);
    SW_Filter_TD_4155(tbl_SerializeFromObject_TD_5297_input, tbl_Filter_TD_4155_output);
    gettimeofday(&tv_r_Filter_4_375_e, 0);

    struct timeval tv_r_JOIN_INNER_5_879_s, tv_r_JOIN_INNER_5_879_e;
    gettimeofday(&tv_r_JOIN_INNER_5_879_s, 0);
    prev_events_grp_JOIN_INNER_TD_5622.push_back(events_h2d_wr_JOIN_INNER_TD_6380[0]);
    trans_JOIN_INNER_TD_5622.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_5622), &(events_h2d_wr_JOIN_INNER_TD_5622[0]));
    events_grp_JOIN_INNER_TD_5622.push_back(events_h2d_wr_JOIN_INNER_TD_5622[0]);
    events_grp_JOIN_INNER_TD_5622.insert(std::end(events_grp_JOIN_INNER_TD_5622), std::begin(events_JOIN_INNER_TD_6380[0]), std::end(events_JOIN_INNER_TD_6380[0]));
    events_grp_JOIN_INNER_TD_5622.insert(std::end(events_grp_JOIN_INNER_TD_5622), std::begin(events_JOIN_INNER_TD_6380[1]), std::end(events_JOIN_INNER_TD_6380[1]));
    krnl_JOIN_INNER_TD_5622_part_left.run(0, &(events_grp_JOIN_INNER_TD_5622), &(events_JOIN_INNER_TD_5622[0][0]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_5622[i].run(0, &(events_JOIN_INNER_TD_5622[0]), &(events_JOIN_INNER_TD_5622[1][i]));
    }
    gettimeofday(&tv_r_JOIN_INNER_5_879_e, 0);

    struct timeval tv_r_JOIN_INNER_4_175_s, tv_r_JOIN_INNER_4_175_e;
    gettimeofday(&tv_r_JOIN_INNER_4_175_s, 0);
    prev_events_grp_JOIN_INNER_TD_4178.push_back(events_h2d_wr_JOIN_INNER_TD_5622[0]);
    trans_JOIN_INNER_TD_4178.add(&(tbl_Filter_TD_4155_output));
    trans_JOIN_INNER_TD_4178.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_4178), &(events_h2d_wr_JOIN_INNER_TD_4178[0]));
    events_grp_JOIN_INNER_TD_4178.push_back(events_h2d_wr_JOIN_INNER_TD_4178[0]);
    events_grp_JOIN_INNER_TD_4178.insert(std::end(events_grp_JOIN_INNER_TD_4178), std::begin(events_JOIN_INNER_TD_5622[0]), std::end(events_JOIN_INNER_TD_5622[0]));
    events_grp_JOIN_INNER_TD_4178.insert(std::end(events_grp_JOIN_INNER_TD_4178), std::begin(events_JOIN_INNER_TD_5622[1]), std::end(events_JOIN_INNER_TD_5622[1]));
    krnl_JOIN_INNER_TD_4178_part_left.run(0, &(events_grp_JOIN_INNER_TD_4178), &(events_JOIN_INNER_TD_4178[0][0]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_4178[i].run(0, &(events_JOIN_INNER_TD_4178[0]), &(events_JOIN_INNER_TD_4178[1][i]));
    }
    
    for (int i(0); i < hpTimes_join; ++i) {
        trans_JOIN_INNER_TD_4178_out.add(&(tbl_JOIN_INNER_TD_4178_output_partition_array[i]));
    }
    trans_JOIN_INNER_TD_4178_out.dev2host(0, &(events_JOIN_INNER_TD_4178[1]), &(events_d2h_rd_JOIN_INNER_TD_4178[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_4_175_e, 0);

    struct timeval tv_r_JOIN_INNER_3_625_s, tv_r_JOIN_INNER_3_625_e;
    gettimeofday(&tv_r_JOIN_INNER_3_625_s, 0);
    SW_JOIN_INNER_TD_3467(tbl_JOIN_INNER_TD_4178_output_partition_array, tbl_SerializeFromObject_TD_4614_input, tbl_JOIN_INNER_TD_3467_output, hpTimes_join);
    gettimeofday(&tv_r_JOIN_INNER_3_625_e, 0);

    struct timeval tv_r_Project_2_558_s, tv_r_Project_2_558_e;
    gettimeofday(&tv_r_Project_2_558_s, 0);
    SW_Project_TD_2953(tbl_JOIN_INNER_TD_3467_output, tbl_Project_TD_2953_output);
    gettimeofday(&tv_r_Project_2_558_e, 0);

    struct timeval tv_r_Aggregate_1_623_s, tv_r_Aggregate_1_623_e;
    gettimeofday(&tv_r_Aggregate_1_623_s, 0);
    SW_Aggregate_TD_1108(tbl_Project_TD_2953_output, tbl_Aggregate_TD_1108_output);
    gettimeofday(&tv_r_Aggregate_1_623_e, 0);

    struct timeval tv_r_Sort_0_313_s, tv_r_Sort_0_313_e;
    gettimeofday(&tv_r_Sort_0_313_s, 0);
    SW_Sort_TD_027(tbl_Aggregate_TD_1108_output, tbl_Sort_TD_027_output);
    gettimeofday(&tv_r_Sort_0_313_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_833_s, &tv_r_Filter_10_833_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11625_input: " << tbl_SerializeFromObject_TD_11625_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_581_s, &tv_r_JOIN_INNER_9_581_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10213_output: " << tbl_Filter_TD_10213_output.getNumRow() << " " << "tbl_SerializeFromObject_TD_10580_input: " << tbl_SerializeFromObject_TD_10580_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_584_s, &tv_r_Filter_8_584_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9538_input: " << tbl_SerializeFromObject_TD_9538_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_611_s, &tv_r_JOIN_INNER_8_611_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9757_output: " << tbl_JOIN_INNER_TD_9757_output.getNumRow() << " " << "tbl_SerializeFromObject_TD_9913_input: " << tbl_SerializeFromObject_TD_9913_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_949_s, &tv_r_JOIN_INNER_7_949_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_863_output: " << tbl_JOIN_INNER_TD_863_output.getNumRow() << " " << "tbl_Filter_TD_8923_output: " << tbl_Filter_TD_8923_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_511_s, &tv_r_JOIN_INNER_6_511_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7371_output: " << tbl_JOIN_INNER_TD_7371_output.getNumRow() << " " << "tbl_SerializeFromObject_TD_7418_input: " << tbl_SerializeFromObject_TD_7418_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_375_s, &tv_r_Filter_4_375_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5297_input: " << tbl_SerializeFromObject_TD_5297_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_879_s, &tv_r_JOIN_INNER_5_879_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6380_output: " << tbl_JOIN_INNER_TD_6380_output.getNumRow() << " " << "tbl_SerializeFromObject_TD_6254_input: " << tbl_SerializeFromObject_TD_6254_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_175_s, &tv_r_JOIN_INNER_4_175_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5622_output: " << tbl_JOIN_INNER_TD_5622_output.getNumRow() << " " << "tbl_Filter_TD_4155_output: " << tbl_Filter_TD_4155_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_625_s, &tv_r_JOIN_INNER_3_625_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4178_output: " << tbl_JOIN_INNER_TD_4178_output.getNumRow() << " " << "tbl_SerializeFromObject_TD_4614_input: " << tbl_SerializeFromObject_TD_4614_input.getNumRow() << " " << std::endl; 

    std::cout << "Project_2: " << tvdiff(&tv_r_Project_2_558_s, &tv_r_Project_2_558_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3467_output: " << tbl_JOIN_INNER_TD_3467_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_623_s, &tv_r_Aggregate_1_623_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_2953_output: " << tbl_Project_TD_2953_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_313_s, &tv_r_Sort_0_313_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_1108_output: " << tbl_Aggregate_TD_1108_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1057.5762 * 1000 << "ms" << std::endl; 
    return 0; 
}
