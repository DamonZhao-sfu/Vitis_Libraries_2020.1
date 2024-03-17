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

#include "cfgFunc_q21.hpp" 
#include "q21.hpp" 

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
    std::cout << "NOTE:running query #21\n."; 
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
    Table tbl_Sort_TD_0354_output("tbl_Sort_TD_0354_output", 183000000, 2, "");
    tbl_Sort_TD_0354_output.allocateHost();
    Table tbl_Aggregate_TD_1327_output("tbl_Aggregate_TD_1327_output", 183000000, 2, "");
    tbl_Aggregate_TD_1327_output.allocateHost();
    Table tbl_JOIN_INNER_TD_2550_output("tbl_JOIN_INNER_TD_2550_output", 25255, 1, "");
    tbl_JOIN_INNER_TD_2550_output.allocateHost(1.2, hpTimes_join);
    Table tbl_Filter_TD_3939_output("tbl_Filter_TD_3939_output", 183000000, 1, "");
    tbl_Filter_TD_3939_output.allocateHost();
    Table tbl_Filter_TD_3939_output_partition("tbl_Filter_TD_3939_output_partition", 183000000, 1, "");
    tbl_Filter_TD_3939_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_Filter_TD_3939_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_Filter_TD_3939_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_3939_output_partition_array[i] = tbl_Filter_TD_3939_output_partition.createSubTable(i);
    }
    Table tbl_JOIN_INNER_TD_4630_output("tbl_JOIN_INNER_TD_4630_output", 52212, 2, "");
    tbl_JOIN_INNER_TD_4630_output.allocateHost(1.2, hpTimes_join);
    Table tbl_SerializeFromObject_TD_5636_input;
    tbl_SerializeFromObject_TD_5636_input = Table("order", order_n, 2, in_dir);
    tbl_SerializeFromObject_TD_5636_input.addCol("o_orderkey", 4);
    tbl_SerializeFromObject_TD_5636_input.addCol("o_orderstatus", 4);
    tbl_SerializeFromObject_TD_5636_input.allocateHost();
    tbl_SerializeFromObject_TD_5636_input.loadHost();
    Table tbl_JOIN_INNER_TD_3576_output("tbl_JOIN_INNER_TD_3576_output", 377, 2, "");
    tbl_JOIN_INNER_TD_3576_output.allocateHost(1.2, hpTimes_join);
    Table tbl_JOIN_LEFTANTI_TD_5594_output("tbl_JOIN_LEFTANTI_TD_5594_output", 1375555, 2, "");
    tbl_JOIN_LEFTANTI_TD_5594_output.allocateHost(1.2, hpTimes_join);
    Table tbl_SerializeFromObject_TD_5610_input_stringRowIDSubstitute;
    tbl_SerializeFromObject_TD_5610_input_stringRowIDSubstitute = Table("supplier", supplier_n, 3, in_dir);
    tbl_SerializeFromObject_TD_5610_input_stringRowIDSubstitute.addCol("s_suppkey", 4);
    tbl_SerializeFromObject_TD_5610_input_stringRowIDSubstitute.addCol("s_name", 4, 1, 0);
    tbl_SerializeFromObject_TD_5610_input_stringRowIDSubstitute.addCol("s_nationkey", 4);
    tbl_SerializeFromObject_TD_5610_input_stringRowIDSubstitute.allocateHost();
    tbl_SerializeFromObject_TD_5610_input_stringRowIDSubstitute.loadHost();
    Table tbl_SerializeFromObject_TD_5610_input_stringRowIDSubstitute_partition("tbl_SerializeFromObject_TD_5610_input_stringRowIDSubstitute_partition", supplier_n, 3, "");
    tbl_SerializeFromObject_TD_5610_input_stringRowIDSubstitute_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_5610_input_stringRowIDSubstitute_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_5610_input_stringRowIDSubstitute_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_5610_input_stringRowIDSubstitute_partition_array[i] = tbl_SerializeFromObject_TD_5610_input_stringRowIDSubstitute_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_5610_input;
    tbl_SerializeFromObject_TD_5610_input = Table("supplier", supplier_n, 3, in_dir);
    tbl_SerializeFromObject_TD_5610_input.addCol("s_suppkey", 4);
    tbl_SerializeFromObject_TD_5610_input.addCol("s_name", TPCH_READ_S_NAME_LEN+1);
    tbl_SerializeFromObject_TD_5610_input.addCol("s_nationkey", 4);
    tbl_SerializeFromObject_TD_5610_input.allocateHost();
    tbl_SerializeFromObject_TD_5610_input.loadHost();
    Table tbl_Filter_TD_3318_output("tbl_Filter_TD_3318_output", 183000000, 1, "");
    tbl_Filter_TD_3318_output.allocateHost();
    Table tbl_Filter_TD_3318_output_partition("tbl_Filter_TD_3318_output_partition", 183000000, 1, "");
    tbl_Filter_TD_3318_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_Filter_TD_3318_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_Filter_TD_3318_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_3318_output_partition_array[i] = tbl_Filter_TD_3318_output_partition.createSubTable(i);
    }
    Table tbl_JOIN_LEFTSEMI_TD_6859_output("tbl_JOIN_LEFTSEMI_TD_6859_output", 2417632, 2, "");
    tbl_JOIN_LEFTSEMI_TD_6859_output.allocateHost(1.2, hpTimes_join);
    Table tbl_SerializeFromObject_TD_4429_input;
    tbl_SerializeFromObject_TD_4429_input = Table("nation", nation_n, 2, in_dir);
    tbl_SerializeFromObject_TD_4429_input.addCol("n_nationkey", 4);
    tbl_SerializeFromObject_TD_4429_input.addCol("n_name", TPCH_READ_NATION_LEN+1);
    tbl_SerializeFromObject_TD_4429_input.allocateHost();
    tbl_SerializeFromObject_TD_4429_input.loadHost();
    Table tbl_JOIN_LEFTSEMI_TD_7172_output("tbl_JOIN_LEFTSEMI_TD_7172_output", 2844584, 2, "");
    tbl_JOIN_LEFTSEMI_TD_7172_output.allocateHost(1.2, hpTimes_join);
    Table tbl_Filter_TD_7542_output("tbl_Filter_TD_7542_output", 183000000, 2, "");
    tbl_Filter_TD_7542_output.allocateHost();
    Table tbl_Filter_TD_7542_output_partition("tbl_Filter_TD_7542_output_partition", 183000000, 2, "");
    tbl_Filter_TD_7542_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_Filter_TD_7542_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_Filter_TD_7542_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_7542_output_partition_array[i] = tbl_Filter_TD_7542_output_partition.createSubTable(i);
    }
    Table tbl_Filter_TD_8663_output("tbl_Filter_TD_8663_output", 183000000, 2, "");
    tbl_Filter_TD_8663_output.allocateHost();
    Table tbl_Filter_TD_8663_output_partition("tbl_Filter_TD_8663_output_partition", 183000000, 2, "");
    tbl_Filter_TD_8663_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_Filter_TD_8663_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_Filter_TD_8663_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_8663_output_partition_array[i] = tbl_Filter_TD_8663_output_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_8189_input;
    tbl_SerializeFromObject_TD_8189_input = Table("lineitem", lineitem_n, 2, in_dir);
    tbl_SerializeFromObject_TD_8189_input.addCol("l_orderkey", 4);
    tbl_SerializeFromObject_TD_8189_input.addCol("l_suppkey", 4);
    tbl_SerializeFromObject_TD_8189_input.allocateHost();
    tbl_SerializeFromObject_TD_8189_input.loadHost();
    Table tbl_SerializeFromObject_TD_8189_input_partition("tbl_SerializeFromObject_TD_8189_input_partition", lineitem_n, 2, "");
    tbl_SerializeFromObject_TD_8189_input_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_8189_input_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_8189_input_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_8189_input_partition_array[i] = tbl_SerializeFromObject_TD_8189_input_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_9185_input;
    tbl_SerializeFromObject_TD_9185_input = Table("lineitem", lineitem_n, 4, in_dir);
    tbl_SerializeFromObject_TD_9185_input.addCol("l_orderkey", 4);
    tbl_SerializeFromObject_TD_9185_input.addCol("l_suppkey", 4);
    tbl_SerializeFromObject_TD_9185_input.addCol("l_receiptdate", 4);
    tbl_SerializeFromObject_TD_9185_input.addCol("l_commitdate", 4);
    tbl_SerializeFromObject_TD_9185_input.allocateHost();
    tbl_SerializeFromObject_TD_9185_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_2550_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_2550_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_2550_output_partition_array[i] = tbl_JOIN_INNER_TD_2550_output.createSubTable(i);
    }
    tbl_Filter_TD_3939_output.allocateDevBuffer(context_h, 33);
    tbl_JOIN_INNER_TD_4630_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_4630_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_4630_output_partition_array[i] = tbl_JOIN_INNER_TD_4630_output.createSubTable(i);
    }
    tbl_JOIN_INNER_TD_3576_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_3576_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_3576_output_partition_array[i] = tbl_JOIN_INNER_TD_3576_output.createSubTable(i);
    }
    tbl_JOIN_LEFTANTI_TD_5594_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_LEFTANTI_TD_5594_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_LEFTANTI_TD_5594_output_partition_array[i] = tbl_JOIN_LEFTANTI_TD_5594_output.createSubTable(i);
    }
    tbl_SerializeFromObject_TD_5610_input_stringRowIDSubstitute.allocateDevBuffer(context_h, 33);
    tbl_Filter_TD_3318_output.allocateDevBuffer(context_h, 33);
    tbl_JOIN_LEFTSEMI_TD_6859_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_LEFTSEMI_TD_6859_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_LEFTSEMI_TD_6859_output_partition_array[i] = tbl_JOIN_LEFTSEMI_TD_6859_output.createSubTable(i);
    }
    tbl_JOIN_LEFTSEMI_TD_7172_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_LEFTSEMI_TD_7172_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_LEFTSEMI_TD_7172_output_partition_array[i] = tbl_JOIN_LEFTSEMI_TD_7172_output.createSubTable(i);
    }
    tbl_Filter_TD_7542_output.allocateDevBuffer(context_h, 33);
    tbl_Filter_TD_8663_output.allocateDevBuffer(context_h, 33);
    tbl_SerializeFromObject_TD_8189_input.allocateDevBuffer(context_h, 33);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_2550_cmds;
    cfg_JOIN_INNER_TD_2550_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_2550_gqe_join (cfg_JOIN_INNER_TD_2550_cmds.cmd);
    cfg_JOIN_INNER_TD_2550_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_2550_cmds_part;
    cfg_JOIN_INNER_TD_2550_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_2550_gqe_join_part (cfg_JOIN_INNER_TD_2550_cmds_part.cmd);
    cfg_JOIN_INNER_TD_2550_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_4630_cmds;
    cfg_JOIN_INNER_TD_4630_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_4630_gqe_join (cfg_JOIN_INNER_TD_4630_cmds.cmd);
    cfg_JOIN_INNER_TD_4630_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_3576_cmds;
    cfg_JOIN_INNER_TD_3576_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_3576_gqe_join (cfg_JOIN_INNER_TD_3576_cmds.cmd);
    cfg_JOIN_INNER_TD_3576_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_3576_cmds_part;
    cfg_JOIN_INNER_TD_3576_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_3576_gqe_join_part (cfg_JOIN_INNER_TD_3576_cmds_part.cmd);
    cfg_JOIN_INNER_TD_3576_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTANTI_TD_5594_cmds;
    cfg_JOIN_LEFTANTI_TD_5594_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTANTI_TD_5594_gqe_join (cfg_JOIN_LEFTANTI_TD_5594_cmds.cmd);
    cfg_JOIN_LEFTANTI_TD_5594_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTANTI_TD_5594_cmds_part;
    cfg_JOIN_LEFTANTI_TD_5594_cmds_part.allocateHost();
    get_cfg_dat_JOIN_LEFTANTI_TD_5594_gqe_join_part (cfg_JOIN_LEFTANTI_TD_5594_cmds_part.cmd);
    cfg_JOIN_LEFTANTI_TD_5594_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_6859_cmds;
    cfg_JOIN_LEFTSEMI_TD_6859_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_6859_gqe_join (cfg_JOIN_LEFTSEMI_TD_6859_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_6859_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_6859_cmds_part;
    cfg_JOIN_LEFTSEMI_TD_6859_cmds_part.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_6859_gqe_join_part (cfg_JOIN_LEFTSEMI_TD_6859_cmds_part.cmd);
    cfg_JOIN_LEFTSEMI_TD_6859_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_7172_cmds;
    cfg_JOIN_LEFTSEMI_TD_7172_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_7172_gqe_join (cfg_JOIN_LEFTSEMI_TD_7172_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_7172_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_7172_cmds_part;
    cfg_JOIN_LEFTSEMI_TD_7172_cmds_part.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_7172_gqe_join_part (cfg_JOIN_LEFTSEMI_TD_7172_cmds_part.cmd);
    cfg_JOIN_LEFTSEMI_TD_7172_cmds_part.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_2550_part_right;
    krnl_JOIN_INNER_TD_2550_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_2550_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_Filter_TD_3939_output, tbl_Filter_TD_3939_output_partition, cfg_JOIN_INNER_TD_2550_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_2550[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_2550[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_2550[i].setup(tbl_JOIN_INNER_TD_4630_output_partition_array[i], tbl_Filter_TD_3939_output_partition_array[i], tbl_JOIN_INNER_TD_2550_output_partition_array[i], cfg_JOIN_INNER_TD_2550_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_INNER_TD_4630[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_4630[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_4630[i].setup(tbl_JOIN_INNER_TD_3576_output_partition_array[i], tbl_JOIN_LEFTANTI_TD_5594_output_partition_array[i], tbl_JOIN_INNER_TD_4630_output_partition_array[i], cfg_JOIN_INNER_TD_4630_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_INNER_TD_3576_part_left;
    krnl_JOIN_INNER_TD_3576_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_3576_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_SerializeFromObject_TD_5610_input_stringRowIDSubstitute, tbl_SerializeFromObject_TD_5610_input_stringRowIDSubstitute_partition, cfg_JOIN_INNER_TD_3576_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_3576_part_right;
    krnl_JOIN_INNER_TD_3576_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_3576_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_Filter_TD_3318_output, tbl_Filter_TD_3318_output_partition, cfg_JOIN_INNER_TD_3576_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_3576[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_3576[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_3576[i].setup(tbl_SerializeFromObject_TD_5610_input_stringRowIDSubstitute_partition_array[i], tbl_Filter_TD_3318_output_partition_array[i], tbl_JOIN_INNER_TD_3576_output_partition_array[i], cfg_JOIN_INNER_TD_3576_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_LEFTANTI_TD_5594_part_right;
    krnl_JOIN_LEFTANTI_TD_5594_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_LEFTANTI_TD_5594_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_Filter_TD_7542_output, tbl_Filter_TD_7542_output_partition, cfg_JOIN_LEFTANTI_TD_5594_cmds_part);
    krnlEngine krnl_JOIN_LEFTANTI_TD_5594[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_LEFTANTI_TD_5594[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_LEFTANTI_TD_5594[i].setup(tbl_JOIN_LEFTSEMI_TD_6859_output_partition_array[i], tbl_Filter_TD_7542_output_partition_array[i], tbl_JOIN_LEFTANTI_TD_5594_output_partition_array[i], cfg_JOIN_LEFTANTI_TD_5594_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_LEFTSEMI_TD_6859_part_left;
    krnl_JOIN_LEFTSEMI_TD_6859_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_LEFTSEMI_TD_6859_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_Filter_TD_7542_output, tbl_Filter_TD_7542_output_partition, cfg_JOIN_LEFTSEMI_TD_6859_cmds_part);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_6859[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_LEFTSEMI_TD_6859[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_LEFTSEMI_TD_6859[i].setup(tbl_Filter_TD_7542_output_partition_array[i], tbl_JOIN_LEFTSEMI_TD_7172_output_partition_array[i], tbl_JOIN_LEFTSEMI_TD_6859_output_partition_array[i], cfg_JOIN_LEFTSEMI_TD_6859_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_LEFTSEMI_TD_7172_part_left;
    krnl_JOIN_LEFTSEMI_TD_7172_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_LEFTSEMI_TD_7172_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_SerializeFromObject_TD_8189_input, tbl_SerializeFromObject_TD_8189_input_partition, cfg_JOIN_LEFTSEMI_TD_7172_cmds_part);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_7172_part_right;
    krnl_JOIN_LEFTSEMI_TD_7172_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_LEFTSEMI_TD_7172_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_Filter_TD_8663_output, tbl_Filter_TD_8663_output_partition, cfg_JOIN_LEFTSEMI_TD_7172_cmds_part);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_7172[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_LEFTSEMI_TD_7172[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_LEFTSEMI_TD_7172[i].setup(tbl_SerializeFromObject_TD_8189_input_partition_array[i], tbl_Filter_TD_8663_output_partition_array[i], tbl_JOIN_LEFTSEMI_TD_7172_output_partition_array[i], cfg_JOIN_LEFTSEMI_TD_7172_cmds, buftmp_h);
    }
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_2550;
    trans_JOIN_INNER_TD_2550.setq(q_h);
    trans_JOIN_INNER_TD_2550.add(&(cfg_JOIN_INNER_TD_2550_cmds_part));
    trans_JOIN_INNER_TD_2550.add(&(cfg_JOIN_INNER_TD_2550_cmds));
    transEngine trans_JOIN_INNER_TD_2550_out;
    trans_JOIN_INNER_TD_2550_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_4630;
    trans_JOIN_INNER_TD_4630.setq(q_h);
    trans_JOIN_INNER_TD_4630.add(&(cfg_JOIN_INNER_TD_4630_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_3576;
    trans_JOIN_INNER_TD_3576.setq(q_h);
    trans_JOIN_INNER_TD_3576.add(&(cfg_JOIN_INNER_TD_3576_cmds_part));
    trans_JOIN_INNER_TD_3576.add(&(cfg_JOIN_INNER_TD_3576_cmds));
    trans_JOIN_INNER_TD_3576.add(&(tbl_SerializeFromObject_TD_5610_input_stringRowIDSubstitute));
    q_h.finish();
    transEngine trans_JOIN_LEFTANTI_TD_5594;
    trans_JOIN_LEFTANTI_TD_5594.setq(q_h);
    trans_JOIN_LEFTANTI_TD_5594.add(&(cfg_JOIN_LEFTANTI_TD_5594_cmds_part));
    trans_JOIN_LEFTANTI_TD_5594.add(&(cfg_JOIN_LEFTANTI_TD_5594_cmds));
    q_h.finish();
    transEngine trans_JOIN_LEFTSEMI_TD_6859;
    trans_JOIN_LEFTSEMI_TD_6859.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_6859.add(&(cfg_JOIN_LEFTSEMI_TD_6859_cmds_part));
    trans_JOIN_LEFTSEMI_TD_6859.add(&(cfg_JOIN_LEFTSEMI_TD_6859_cmds));
    q_h.finish();
    transEngine trans_JOIN_LEFTSEMI_TD_7172;
    trans_JOIN_LEFTSEMI_TD_7172.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_7172.add(&(cfg_JOIN_LEFTSEMI_TD_7172_cmds_part));
    trans_JOIN_LEFTSEMI_TD_7172.add(&(cfg_JOIN_LEFTSEMI_TD_7172_cmds));
    trans_JOIN_LEFTSEMI_TD_7172.add(&(tbl_SerializeFromObject_TD_8189_input));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_2550;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_2550;
    std::vector<cl::Event> events_JOIN_INNER_TD_2550[2];
    events_h2d_wr_JOIN_INNER_TD_2550.resize(1);
    events_d2h_rd_JOIN_INNER_TD_2550.resize(1);
    events_JOIN_INNER_TD_2550[0].resize(1);
    events_JOIN_INNER_TD_2550[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_2550;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_2550;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_4630;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_4630;
    std::vector<cl::Event> events_JOIN_INNER_TD_4630[2];
    events_h2d_wr_JOIN_INNER_TD_4630.resize(1);
    events_d2h_rd_JOIN_INNER_TD_4630.resize(1);
    events_JOIN_INNER_TD_4630[0].resize(0);
    events_JOIN_INNER_TD_4630[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_4630;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_4630;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_3576;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_3576;
    std::vector<cl::Event> events_JOIN_INNER_TD_3576[2];
    events_h2d_wr_JOIN_INNER_TD_3576.resize(1);
    events_d2h_rd_JOIN_INNER_TD_3576.resize(1);
    events_JOIN_INNER_TD_3576[0].resize(2);
    events_JOIN_INNER_TD_3576[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_3576;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_3576;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTANTI_TD_5594;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTANTI_TD_5594;
    std::vector<cl::Event> events_JOIN_LEFTANTI_TD_5594[2];
    events_h2d_wr_JOIN_LEFTANTI_TD_5594.resize(1);
    events_d2h_rd_JOIN_LEFTANTI_TD_5594.resize(1);
    events_JOIN_LEFTANTI_TD_5594[0].resize(1);
    events_JOIN_LEFTANTI_TD_5594[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_LEFTANTI_TD_5594;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTANTI_TD_5594;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_6859;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_6859;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_6859[2];
    events_h2d_wr_JOIN_LEFTSEMI_TD_6859.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_6859.resize(1);
    events_JOIN_LEFTSEMI_TD_6859[0].resize(1);
    events_JOIN_LEFTSEMI_TD_6859[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_6859;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_6859;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_7172;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_7172;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_7172[2];
    events_h2d_wr_JOIN_LEFTSEMI_TD_7172.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_7172.resize(1);
    events_JOIN_LEFTSEMI_TD_7172[0].resize(2);
    events_JOIN_LEFTSEMI_TD_7172[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_7172;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_7172;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_8_837_s, tv_r_Filter_8_837_e;
    gettimeofday(&tv_r_Filter_8_837_s, 0);
    SW_Filter_TD_8663(tbl_SerializeFromObject_TD_9185_input, tbl_Filter_TD_8663_output);
    gettimeofday(&tv_r_Filter_8_837_e, 0);

    struct timeval tv_r_Filter_7_630_s, tv_r_Filter_7_630_e;
    gettimeofday(&tv_r_Filter_7_630_s, 0);
    SW_Filter_TD_7542(tbl_SerializeFromObject_TD_9185_input, tbl_Filter_TD_7542_output);
    gettimeofday(&tv_r_Filter_7_630_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_7_722_s, tv_r_JOIN_LEFTSEMI_7_722_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_722_s, 0);
    trans_JOIN_LEFTSEMI_TD_7172.add(&(tbl_Filter_TD_8663_output));
    trans_JOIN_LEFTSEMI_TD_7172.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_7172), &(events_h2d_wr_JOIN_LEFTSEMI_TD_7172[0]));
    events_grp_JOIN_LEFTSEMI_TD_7172.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_7172[0]);
    krnl_JOIN_LEFTSEMI_TD_7172_part_left.run(0, &(events_grp_JOIN_LEFTSEMI_TD_7172), &(events_JOIN_LEFTSEMI_TD_7172[0][0]));
    krnl_JOIN_LEFTSEMI_TD_7172_part_right.run(0, &(events_grp_JOIN_LEFTSEMI_TD_7172), &(events_JOIN_LEFTSEMI_TD_7172[0][1]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_LEFTSEMI_TD_7172[i].run(0, &(events_JOIN_LEFTSEMI_TD_7172[0]), &(events_JOIN_LEFTSEMI_TD_7172[1][i]));
    }
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_722_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_6_445_s, tv_r_JOIN_LEFTSEMI_6_445_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_6_445_s, 0);
    prev_events_grp_JOIN_LEFTSEMI_TD_6859.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_7172[0]);
    trans_JOIN_LEFTSEMI_TD_6859.add(&(tbl_Filter_TD_7542_output));
    trans_JOIN_LEFTSEMI_TD_6859.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_6859), &(events_h2d_wr_JOIN_LEFTSEMI_TD_6859[0]));
    events_grp_JOIN_LEFTSEMI_TD_6859.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_6859[0]);
    events_grp_JOIN_LEFTSEMI_TD_6859.insert(std::end(events_grp_JOIN_LEFTSEMI_TD_6859), std::begin(events_JOIN_LEFTSEMI_TD_7172[0]), std::end(events_JOIN_LEFTSEMI_TD_7172[0]));
    events_grp_JOIN_LEFTSEMI_TD_6859.insert(std::end(events_grp_JOIN_LEFTSEMI_TD_6859), std::begin(events_JOIN_LEFTSEMI_TD_7172[1]), std::end(events_JOIN_LEFTSEMI_TD_7172[1]));
    krnl_JOIN_LEFTSEMI_TD_6859_part_left.run(0, &(events_grp_JOIN_LEFTSEMI_TD_6859), &(events_JOIN_LEFTSEMI_TD_6859[0][0]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_LEFTSEMI_TD_6859[i].run(0, &(events_JOIN_LEFTSEMI_TD_6859[0]), &(events_JOIN_LEFTSEMI_TD_6859[1][i]));
    }
    gettimeofday(&tv_r_JOIN_LEFTSEMI_6_445_e, 0);

    struct timeval tv_r_Filter_3_328_s, tv_r_Filter_3_328_e;
    gettimeofday(&tv_r_Filter_3_328_s, 0);
    SW_Filter_TD_3318(tbl_SerializeFromObject_TD_4429_input, tbl_Filter_TD_3318_output);
    gettimeofday(&tv_r_Filter_3_328_e, 0);

    struct timeval tv_r_JOIN_LEFTANTI_5_707_s, tv_r_JOIN_LEFTANTI_5_707_e;
    gettimeofday(&tv_r_JOIN_LEFTANTI_5_707_s, 0);
    prev_events_grp_JOIN_LEFTANTI_TD_5594.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_6859[0]);
    trans_JOIN_LEFTANTI_TD_5594.add(&(tbl_Filter_TD_7542_output));
    trans_JOIN_LEFTANTI_TD_5594.host2dev(0, &(prev_events_grp_JOIN_LEFTANTI_TD_5594), &(events_h2d_wr_JOIN_LEFTANTI_TD_5594[0]));
    events_grp_JOIN_LEFTANTI_TD_5594.push_back(events_h2d_wr_JOIN_LEFTANTI_TD_5594[0]);
    events_grp_JOIN_LEFTANTI_TD_5594.insert(std::end(events_grp_JOIN_LEFTANTI_TD_5594), std::begin(events_JOIN_LEFTSEMI_TD_6859[0]), std::end(events_JOIN_LEFTSEMI_TD_6859[0]));
    events_grp_JOIN_LEFTANTI_TD_5594.insert(std::end(events_grp_JOIN_LEFTANTI_TD_5594), std::begin(events_JOIN_LEFTSEMI_TD_6859[1]), std::end(events_JOIN_LEFTSEMI_TD_6859[1]));
    krnl_JOIN_LEFTANTI_TD_5594_part_right.run(0, &(events_grp_JOIN_LEFTANTI_TD_5594), &(events_JOIN_LEFTANTI_TD_5594[0][0]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_LEFTANTI_TD_5594[i].run(0, &(events_grp_JOIN_LEFTANTI_TD_5594), &(events_JOIN_LEFTANTI_TD_5594[1][i]));
    }
    gettimeofday(&tv_r_JOIN_LEFTANTI_5_707_e, 0);

    struct timeval tv_r_JOIN_INNER_3_851_s, tv_r_JOIN_INNER_3_851_e;
    gettimeofday(&tv_r_JOIN_INNER_3_851_s, 0);
    trans_JOIN_INNER_TD_3576.add(&(tbl_Filter_TD_3318_output));
    trans_JOIN_INNER_TD_3576.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_3576), &(events_h2d_wr_JOIN_INNER_TD_3576[0]));
    events_grp_JOIN_INNER_TD_3576.push_back(events_h2d_wr_JOIN_INNER_TD_3576[0]);
    krnl_JOIN_INNER_TD_3576_part_left.run(0, &(events_grp_JOIN_INNER_TD_3576), &(events_JOIN_INNER_TD_3576[0][0]));
    krnl_JOIN_INNER_TD_3576_part_right.run(0, &(events_grp_JOIN_INNER_TD_3576), &(events_JOIN_INNER_TD_3576[0][1]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_3576[i].run(0, &(events_JOIN_INNER_TD_3576[0]), &(events_JOIN_INNER_TD_3576[1][i]));
    }
    gettimeofday(&tv_r_JOIN_INNER_3_851_e, 0);

    struct timeval tv_r_JOIN_INNER_4_135_s, tv_r_JOIN_INNER_4_135_e;
    gettimeofday(&tv_r_JOIN_INNER_4_135_s, 0);
    prev_events_grp_JOIN_INNER_TD_4630.push_back(events_h2d_wr_JOIN_INNER_TD_3576[0]);
    prev_events_grp_JOIN_INNER_TD_4630.push_back(events_h2d_wr_JOIN_LEFTANTI_TD_5594[0]);
    trans_JOIN_INNER_TD_4630.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_4630), &(events_h2d_wr_JOIN_INNER_TD_4630[0]));
    events_grp_JOIN_INNER_TD_4630.push_back(events_h2d_wr_JOIN_INNER_TD_4630[0]);
    events_grp_JOIN_INNER_TD_4630.insert(std::end(events_grp_JOIN_INNER_TD_4630), std::begin(events_JOIN_INNER_TD_3576[0]), std::end(events_JOIN_INNER_TD_3576[0]));
    events_grp_JOIN_INNER_TD_4630.insert(std::end(events_grp_JOIN_INNER_TD_4630), std::begin(events_JOIN_INNER_TD_3576[1]), std::end(events_JOIN_INNER_TD_3576[1]));
    events_grp_JOIN_INNER_TD_4630.insert(std::end(events_grp_JOIN_INNER_TD_4630), std::begin(events_JOIN_LEFTANTI_TD_5594[0]), std::end(events_JOIN_LEFTANTI_TD_5594[0]));
    events_grp_JOIN_INNER_TD_4630.insert(std::end(events_grp_JOIN_INNER_TD_4630), std::begin(events_JOIN_LEFTANTI_TD_5594[1]), std::end(events_JOIN_LEFTANTI_TD_5594[1]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_4630[i].run(0, &(events_grp_JOIN_INNER_TD_4630), &(events_JOIN_INNER_TD_4630[1][i]));
    }
    gettimeofday(&tv_r_JOIN_INNER_4_135_e, 0);

    struct timeval tv_r_Filter_3_119_s, tv_r_Filter_3_119_e;
    gettimeofday(&tv_r_Filter_3_119_s, 0);
    SW_Filter_TD_3939(tbl_SerializeFromObject_TD_5636_input, tbl_Filter_TD_3939_output);
    gettimeofday(&tv_r_Filter_3_119_e, 0);

    struct timeval tv_r_JOIN_INNER_2_760_s, tv_r_JOIN_INNER_2_760_e;
    gettimeofday(&tv_r_JOIN_INNER_2_760_s, 0);
    prev_events_grp_JOIN_INNER_TD_2550.push_back(events_h2d_wr_JOIN_INNER_TD_4630[0]);
    trans_JOIN_INNER_TD_2550.add(&(tbl_Filter_TD_3939_output));
    trans_JOIN_INNER_TD_2550.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_2550), &(events_h2d_wr_JOIN_INNER_TD_2550[0]));
    events_grp_JOIN_INNER_TD_2550.push_back(events_h2d_wr_JOIN_INNER_TD_2550[0]);
    events_grp_JOIN_INNER_TD_2550.insert(std::end(events_grp_JOIN_INNER_TD_2550), std::begin(events_JOIN_INNER_TD_4630[0]), std::end(events_JOIN_INNER_TD_4630[0]));
    events_grp_JOIN_INNER_TD_2550.insert(std::end(events_grp_JOIN_INNER_TD_2550), std::begin(events_JOIN_INNER_TD_4630[1]), std::end(events_JOIN_INNER_TD_4630[1]));
    krnl_JOIN_INNER_TD_2550_part_right.run(0, &(events_grp_JOIN_INNER_TD_2550), &(events_JOIN_INNER_TD_2550[0][0]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_2550[i].run(0, &(events_grp_JOIN_INNER_TD_2550), &(events_JOIN_INNER_TD_2550[1][i]));
    }
    
    for (int i(0); i < hpTimes_join; ++i) {
        trans_JOIN_INNER_TD_2550_out.add(&(tbl_JOIN_INNER_TD_2550_output_partition_array[i]));
    }
    trans_JOIN_INNER_TD_2550_out.dev2host(0, &(events_JOIN_INNER_TD_2550[1]), &(events_d2h_rd_JOIN_INNER_TD_2550[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_2_760_e, 0);

    struct timeval tv_r_Aggregate_1_633_s, tv_r_Aggregate_1_633_e;
    gettimeofday(&tv_r_Aggregate_1_633_s, 0);
    SW_Aggregate_TD_1327(tbl_JOIN_INNER_TD_2550_output_partition_array, tbl_SerializeFromObject_TD_5636_input, tbl_SerializeFromObject_TD_5610_input, tbl_SerializeFromObject_TD_4429_input, tbl_Aggregate_TD_1327_output, hpTimes_join);
    gettimeofday(&tv_r_Aggregate_1_633_e, 0);

    struct timeval tv_r_Sort_0_841_s, tv_r_Sort_0_841_e;
    gettimeofday(&tv_r_Sort_0_841_s, 0);
    SW_Sort_TD_0354(tbl_Aggregate_TD_1327_output, tbl_Sort_TD_0354_output);
    gettimeofday(&tv_r_Sort_0_841_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_837_s, &tv_r_Filter_8_837_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9185_input: " << tbl_SerializeFromObject_TD_9185_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_630_s, &tv_r_Filter_7_630_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9185_input: " << tbl_SerializeFromObject_TD_9185_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_7: " << tvdiff(&tv_r_JOIN_LEFTSEMI_7_722_s, &tv_r_JOIN_LEFTSEMI_7_722_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8663_output: " << tbl_Filter_TD_8663_output.getNumRow() << " " << "tbl_SerializeFromObject_TD_8189_input: " << tbl_SerializeFromObject_TD_8189_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_6: " << tvdiff(&tv_r_JOIN_LEFTSEMI_6_445_s, &tv_r_JOIN_LEFTSEMI_6_445_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTSEMI_TD_7172_output: " << tbl_JOIN_LEFTSEMI_TD_7172_output.getNumRow() << " " << "tbl_Filter_TD_7542_output: " << tbl_Filter_TD_7542_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_328_s, &tv_r_Filter_3_328_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_4429_input: " << tbl_SerializeFromObject_TD_4429_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTANTI_5: " << tvdiff(&tv_r_JOIN_LEFTANTI_5_707_s, &tv_r_JOIN_LEFTANTI_5_707_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_7542_output: " << tbl_Filter_TD_7542_output.getNumRow() << " " << "tbl_JOIN_LEFTSEMI_TD_6859_output: " << tbl_JOIN_LEFTSEMI_TD_6859_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_851_s, &tv_r_JOIN_INNER_3_851_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5610_input_stringRowIDSubstitute: " << tbl_SerializeFromObject_TD_5610_input_stringRowIDSubstitute.getNumRow() << " " << "tbl_Filter_TD_3318_output: " << tbl_Filter_TD_3318_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_135_s, &tv_r_JOIN_INNER_4_135_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3576_output: " << tbl_JOIN_INNER_TD_3576_output.getNumRow() << " " << "tbl_JOIN_LEFTANTI_TD_5594_output: " << tbl_JOIN_LEFTANTI_TD_5594_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_119_s, &tv_r_Filter_3_119_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5636_input: " << tbl_SerializeFromObject_TD_5636_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_2: " << tvdiff(&tv_r_JOIN_INNER_2_760_s, &tv_r_JOIN_INNER_2_760_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_3939_output: " << tbl_Filter_TD_3939_output.getNumRow() << " " << "tbl_JOIN_INNER_TD_4630_output: " << tbl_JOIN_INNER_TD_4630_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_633_s, &tv_r_Aggregate_1_633_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_2550_output: " << tbl_JOIN_INNER_TD_2550_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_841_s, &tv_r_Sort_0_841_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_1327_output: " << tbl_Aggregate_TD_1327_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2167.2058 * 1000 << "ms" << std::endl; 
    return 0; 
}
