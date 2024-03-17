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

#include "cfgFunc_q9.hpp" 
#include "q9.hpp" 

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
    std::cout << "NOTE:running query #9\n."; 
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
    Table tbl_Sort_TD_0706_output("tbl_Sort_TD_0706_output", 183000000, 3, "");
    tbl_Sort_TD_0706_output.allocateHost();
    Table tbl_Aggregate_TD_1479_output("tbl_Aggregate_TD_1479_output", 183000000, 3, "");
    tbl_Aggregate_TD_1479_output.allocateHost();
    Table tbl_Project_TD_2289_output("tbl_Project_TD_2289_output", 183000000, 3, "");
    tbl_Project_TD_2289_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3174_output("tbl_JOIN_INNER_TD_3174_output", 183000000, 6, "");
    tbl_JOIN_INNER_TD_3174_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4550_output("tbl_JOIN_INNER_TD_4550_output", 319287, 6, "");
    tbl_JOIN_INNER_TD_4550_output.allocateHost(1.2, hpTimes_join);
    Table tbl_SerializeFromObject_TD_4433_input;
    tbl_SerializeFromObject_TD_4433_input = Table("nation", nation_n, 2, in_dir);
    tbl_SerializeFromObject_TD_4433_input.addCol("n_nationkey", 4);
    tbl_SerializeFromObject_TD_4433_input.addCol("n_name", TPCH_READ_NATION_LEN+1);
    tbl_SerializeFromObject_TD_4433_input.allocateHost();
    tbl_SerializeFromObject_TD_4433_input.loadHost();
    Table tbl_JOIN_INNER_TD_5936_output("tbl_JOIN_INNER_TD_5936_output", 319287, 6, "");
    tbl_JOIN_INNER_TD_5936_output.allocateHost(1.2, hpTimes_join);
    Table tbl_SerializeFromObject_TD_568_input;
    tbl_SerializeFromObject_TD_568_input = Table("order", order_n, 2, in_dir);
    tbl_SerializeFromObject_TD_568_input.addCol("o_orderkey", 4);
    tbl_SerializeFromObject_TD_568_input.addCol("o_orderdate", 4);
    tbl_SerializeFromObject_TD_568_input.allocateHost();
    tbl_SerializeFromObject_TD_568_input.loadHost();
    Table tbl_SerializeFromObject_TD_568_input_partition("tbl_SerializeFromObject_TD_568_input_partition", order_n, 2, "");
    tbl_SerializeFromObject_TD_568_input_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_568_input_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_568_input_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_568_input_partition_array[i] = tbl_SerializeFromObject_TD_568_input_partition.createSubTable(i);
    }
    Table tbl_JOIN_INNER_TD_6822_output("tbl_JOIN_INNER_TD_6822_output", 319287, 7, "");
    tbl_JOIN_INNER_TD_6822_output.allocateHost(1.2, hpTimes_join);
    Table tbl_SerializeFromObject_TD_6711_input;
    tbl_SerializeFromObject_TD_6711_input = Table("partsupp", partsupp_n, 3, in_dir);
    tbl_SerializeFromObject_TD_6711_input.addCol("ps_partkey", 4);
    tbl_SerializeFromObject_TD_6711_input.addCol("ps_suppkey", 4);
    tbl_SerializeFromObject_TD_6711_input.addCol("ps_supplycost", 4);
    tbl_SerializeFromObject_TD_6711_input.allocateHost();
    tbl_SerializeFromObject_TD_6711_input.loadHost();
    Table tbl_SerializeFromObject_TD_6711_input_partition("tbl_SerializeFromObject_TD_6711_input_partition", partsupp_n, 3, "");
    tbl_SerializeFromObject_TD_6711_input_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_6711_input_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_6711_input_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_6711_input_partition_array[i] = tbl_SerializeFromObject_TD_6711_input_partition.createSubTable(i);
    }
    Table tbl_JOIN_INNER_TD_7954_output("tbl_JOIN_INNER_TD_7954_output", 319287, 6, "");
    tbl_JOIN_INNER_TD_7954_output.allocateHost(1.2, hpTimes_join);
    Table tbl_SerializeFromObject_TD_7149_input;
    tbl_SerializeFromObject_TD_7149_input = Table("supplier", supplier_n, 2, in_dir);
    tbl_SerializeFromObject_TD_7149_input.addCol("s_suppkey", 4);
    tbl_SerializeFromObject_TD_7149_input.addCol("s_nationkey", 4);
    tbl_SerializeFromObject_TD_7149_input.allocateHost();
    tbl_SerializeFromObject_TD_7149_input.loadHost();
    Table tbl_SerializeFromObject_TD_7149_input_partition("tbl_SerializeFromObject_TD_7149_input_partition", supplier_n, 2, "");
    tbl_SerializeFromObject_TD_7149_input_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_7149_input_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_7149_input_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_7149_input_partition_array[i] = tbl_SerializeFromObject_TD_7149_input_partition.createSubTable(i);
    }
    Table tbl_Filter_TD_865_output("tbl_Filter_TD_865_output", 183000000, 1, "");
    tbl_Filter_TD_865_output.allocateHost();
    Table tbl_Filter_TD_865_output_partition("tbl_Filter_TD_865_output_partition", 183000000, 1, "");
    tbl_Filter_TD_865_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_Filter_TD_865_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_Filter_TD_865_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_865_output_partition_array[i] = tbl_Filter_TD_865_output_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_8891_input;
    tbl_SerializeFromObject_TD_8891_input = Table("lineitem", lineitem_n, 6, in_dir);
    tbl_SerializeFromObject_TD_8891_input.addCol("l_orderkey", 4);
    tbl_SerializeFromObject_TD_8891_input.addCol("l_partkey", 4);
    tbl_SerializeFromObject_TD_8891_input.addCol("l_suppkey", 4);
    tbl_SerializeFromObject_TD_8891_input.addCol("l_quantity", 4);
    tbl_SerializeFromObject_TD_8891_input.addCol("l_extendedprice", 4);
    tbl_SerializeFromObject_TD_8891_input.addCol("l_discount", 4);
    tbl_SerializeFromObject_TD_8891_input.allocateHost();
    tbl_SerializeFromObject_TD_8891_input.loadHost();
    Table tbl_SerializeFromObject_TD_8891_input_partition("tbl_SerializeFromObject_TD_8891_input_partition", lineitem_n, 6, "");
    tbl_SerializeFromObject_TD_8891_input_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_8891_input_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_8891_input_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_8891_input_partition_array[i] = tbl_SerializeFromObject_TD_8891_input_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_9775_input;
    tbl_SerializeFromObject_TD_9775_input = Table("part", part_n, 2, in_dir);
    tbl_SerializeFromObject_TD_9775_input.addCol("p_partkey", 4);
    tbl_SerializeFromObject_TD_9775_input.addCol("p_name", TPCH_READ_P_NAME_LEN+1);
    tbl_SerializeFromObject_TD_9775_input.allocateHost();
    tbl_SerializeFromObject_TD_9775_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_4550_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_4550_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_4550_output_partition_array[i] = tbl_JOIN_INNER_TD_4550_output.createSubTable(i);
    }
    tbl_JOIN_INNER_TD_5936_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_5936_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_5936_output_partition_array[i] = tbl_JOIN_INNER_TD_5936_output.createSubTable(i);
    }
    tbl_SerializeFromObject_TD_568_input.allocateDevBuffer(context_h, 33);
    tbl_JOIN_INNER_TD_6822_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_6822_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_6822_output_partition_array[i] = tbl_JOIN_INNER_TD_6822_output.createSubTable(i);
    }
    tbl_SerializeFromObject_TD_6711_input.allocateDevBuffer(context_h, 33);
    tbl_JOIN_INNER_TD_7954_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_7954_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_7954_output_partition_array[i] = tbl_JOIN_INNER_TD_7954_output.createSubTable(i);
    }
    tbl_SerializeFromObject_TD_7149_input.allocateDevBuffer(context_h, 33);
    tbl_Filter_TD_865_output.allocateDevBuffer(context_h, 33);
    tbl_SerializeFromObject_TD_8891_input.allocateDevBuffer(context_h, 33);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_4550_cmds;
    cfg_JOIN_INNER_TD_4550_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_4550_gqe_join (cfg_JOIN_INNER_TD_4550_cmds.cmd);
    cfg_JOIN_INNER_TD_4550_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_4550_cmds_part;
    cfg_JOIN_INNER_TD_4550_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_4550_gqe_join_part (cfg_JOIN_INNER_TD_4550_cmds_part.cmd);
    cfg_JOIN_INNER_TD_4550_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_5936_cmds;
    cfg_JOIN_INNER_TD_5936_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_5936_gqe_join (cfg_JOIN_INNER_TD_5936_cmds.cmd);
    cfg_JOIN_INNER_TD_5936_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_5936_cmds_part;
    cfg_JOIN_INNER_TD_5936_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_5936_gqe_join_part (cfg_JOIN_INNER_TD_5936_cmds_part.cmd);
    cfg_JOIN_INNER_TD_5936_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_6822_cmds;
    cfg_JOIN_INNER_TD_6822_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_6822_gqe_join (cfg_JOIN_INNER_TD_6822_cmds.cmd);
    cfg_JOIN_INNER_TD_6822_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_6822_cmds_part;
    cfg_JOIN_INNER_TD_6822_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_6822_gqe_join_part (cfg_JOIN_INNER_TD_6822_cmds_part.cmd);
    cfg_JOIN_INNER_TD_6822_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7954_cmds;
    cfg_JOIN_INNER_TD_7954_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7954_gqe_join (cfg_JOIN_INNER_TD_7954_cmds.cmd);
    cfg_JOIN_INNER_TD_7954_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7954_cmds_part;
    cfg_JOIN_INNER_TD_7954_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7954_gqe_join_part (cfg_JOIN_INNER_TD_7954_cmds_part.cmd);
    cfg_JOIN_INNER_TD_7954_cmds_part.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_4550_part_right;
    krnl_JOIN_INNER_TD_4550_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_4550_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_SerializeFromObject_TD_568_input, tbl_SerializeFromObject_TD_568_input_partition, cfg_JOIN_INNER_TD_4550_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_4550[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_4550[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_4550[i].setup(tbl_JOIN_INNER_TD_5936_output_partition_array[i], tbl_SerializeFromObject_TD_568_input_partition_array[i], tbl_JOIN_INNER_TD_4550_output_partition_array[i], cfg_JOIN_INNER_TD_4550_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_INNER_TD_5936_part_right;
    krnl_JOIN_INNER_TD_5936_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_5936_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_SerializeFromObject_TD_6711_input, tbl_SerializeFromObject_TD_6711_input_partition, cfg_JOIN_INNER_TD_5936_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_5936[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_5936[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_5936[i].setup(tbl_JOIN_INNER_TD_6822_output_partition_array[i], tbl_SerializeFromObject_TD_6711_input_partition_array[i], tbl_JOIN_INNER_TD_5936_output_partition_array[i], cfg_JOIN_INNER_TD_5936_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_INNER_TD_6822_part_left;
    krnl_JOIN_INNER_TD_6822_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_6822_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_SerializeFromObject_TD_7149_input, tbl_SerializeFromObject_TD_7149_input_partition, cfg_JOIN_INNER_TD_6822_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_6822[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_6822[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_6822[i].setup(tbl_SerializeFromObject_TD_7149_input_partition_array[i], tbl_JOIN_INNER_TD_7954_output_partition_array[i], tbl_JOIN_INNER_TD_6822_output_partition_array[i], cfg_JOIN_INNER_TD_6822_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_INNER_TD_7954_part_left;
    krnl_JOIN_INNER_TD_7954_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_7954_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_Filter_TD_865_output, tbl_Filter_TD_865_output_partition, cfg_JOIN_INNER_TD_7954_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_7954_part_right;
    krnl_JOIN_INNER_TD_7954_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_7954_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_SerializeFromObject_TD_8891_input, tbl_SerializeFromObject_TD_8891_input_partition, cfg_JOIN_INNER_TD_7954_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_7954[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_7954[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_7954[i].setup(tbl_Filter_TD_865_output_partition_array[i], tbl_SerializeFromObject_TD_8891_input_partition_array[i], tbl_JOIN_INNER_TD_7954_output_partition_array[i], cfg_JOIN_INNER_TD_7954_cmds, buftmp_h);
    }
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_4550;
    trans_JOIN_INNER_TD_4550.setq(q_h);
    trans_JOIN_INNER_TD_4550.add(&(cfg_JOIN_INNER_TD_4550_cmds));
    trans_JOIN_INNER_TD_4550.add(&(tbl_SerializeFromObject_TD_568_input));
    transEngine trans_JOIN_INNER_TD_4550_out;
    trans_JOIN_INNER_TD_4550_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_5936;
    trans_JOIN_INNER_TD_5936.setq(q_h);
    trans_JOIN_INNER_TD_5936.add(&(cfg_JOIN_INNER_TD_5936_cmds));
    trans_JOIN_INNER_TD_5936.add(&(tbl_SerializeFromObject_TD_6711_input));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_6822;
    trans_JOIN_INNER_TD_6822.setq(q_h);
    trans_JOIN_INNER_TD_6822.add(&(cfg_JOIN_INNER_TD_6822_cmds));
    trans_JOIN_INNER_TD_6822.add(&(tbl_SerializeFromObject_TD_7149_input));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_7954;
    trans_JOIN_INNER_TD_7954.setq(q_h);
    trans_JOIN_INNER_TD_7954.add(&(cfg_JOIN_INNER_TD_7954_cmds_part));
    trans_JOIN_INNER_TD_7954.add(&(cfg_JOIN_INNER_TD_7954_cmds));
    trans_JOIN_INNER_TD_7954.add(&(tbl_SerializeFromObject_TD_8891_input));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_4550;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_4550;
    std::vector<cl::Event> events_JOIN_INNER_TD_4550[2];
    events_h2d_wr_JOIN_INNER_TD_4550.resize(1);
    events_d2h_rd_JOIN_INNER_TD_4550.resize(1);
    events_JOIN_INNER_TD_4550[0].resize(1);
    events_JOIN_INNER_TD_4550[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_4550;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_4550;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_5936;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_5936;
    std::vector<cl::Event> events_JOIN_INNER_TD_5936[2];
    events_h2d_wr_JOIN_INNER_TD_5936.resize(1);
    events_d2h_rd_JOIN_INNER_TD_5936.resize(1);
    events_JOIN_INNER_TD_5936[0].resize(1);
    events_JOIN_INNER_TD_5936[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_5936;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_5936;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_6822;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_6822;
    std::vector<cl::Event> events_JOIN_INNER_TD_6822[2];
    events_h2d_wr_JOIN_INNER_TD_6822.resize(1);
    events_d2h_rd_JOIN_INNER_TD_6822.resize(1);
    events_JOIN_INNER_TD_6822[0].resize(1);
    events_JOIN_INNER_TD_6822[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_6822;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_6822;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7954;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7954;
    std::vector<cl::Event> events_JOIN_INNER_TD_7954[2];
    events_h2d_wr_JOIN_INNER_TD_7954.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7954.resize(1);
    events_JOIN_INNER_TD_7954[0].resize(2);
    events_JOIN_INNER_TD_7954[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7954;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7954;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_8_749_s, tv_r_Filter_8_749_e;
    gettimeofday(&tv_r_Filter_8_749_s, 0);
    SW_Filter_TD_865(tbl_SerializeFromObject_TD_9775_input, tbl_Filter_TD_865_output);
    gettimeofday(&tv_r_Filter_8_749_e, 0);

    struct timeval tv_r_JOIN_INNER_7_554_s, tv_r_JOIN_INNER_7_554_e;
    gettimeofday(&tv_r_JOIN_INNER_7_554_s, 0);
    trans_JOIN_INNER_TD_7954.add(&(tbl_Filter_TD_865_output));
    trans_JOIN_INNER_TD_7954.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7954), &(events_h2d_wr_JOIN_INNER_TD_7954[0]));
    events_grp_JOIN_INNER_TD_7954.push_back(events_h2d_wr_JOIN_INNER_TD_7954[0]);
    krnl_JOIN_INNER_TD_7954_part_left.run(0, &(events_grp_JOIN_INNER_TD_7954), &(events_JOIN_INNER_TD_7954[0][0]));
    krnl_JOIN_INNER_TD_7954_part_right.run(0, &(events_grp_JOIN_INNER_TD_7954), &(events_JOIN_INNER_TD_7954[0][1]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_7954[i].run(0, &(events_JOIN_INNER_TD_7954[0]), &(events_JOIN_INNER_TD_7954[1][i]));
    }
    gettimeofday(&tv_r_JOIN_INNER_7_554_e, 0);

    struct timeval tv_r_JOIN_INNER_6_452_s, tv_r_JOIN_INNER_6_452_e;
    gettimeofday(&tv_r_JOIN_INNER_6_452_s, 0);
    prev_events_grp_JOIN_INNER_TD_6822.push_back(events_h2d_wr_JOIN_INNER_TD_7954[0]);
    trans_JOIN_INNER_TD_6822.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_6822), &(events_h2d_wr_JOIN_INNER_TD_6822[0]));
    events_grp_JOIN_INNER_TD_6822.push_back(events_h2d_wr_JOIN_INNER_TD_6822[0]);
    events_grp_JOIN_INNER_TD_6822.insert(std::end(events_grp_JOIN_INNER_TD_6822), std::begin(events_JOIN_INNER_TD_7954[0]), std::end(events_JOIN_INNER_TD_7954[0]));
    events_grp_JOIN_INNER_TD_6822.insert(std::end(events_grp_JOIN_INNER_TD_6822), std::begin(events_JOIN_INNER_TD_7954[1]), std::end(events_JOIN_INNER_TD_7954[1]));
    krnl_JOIN_INNER_TD_6822_part_left.run(0, &(events_grp_JOIN_INNER_TD_6822), &(events_JOIN_INNER_TD_6822[0][0]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_6822[i].run(0, &(events_JOIN_INNER_TD_6822[0]), &(events_JOIN_INNER_TD_6822[1][i]));
    }
    gettimeofday(&tv_r_JOIN_INNER_6_452_e, 0);

    struct timeval tv_r_JOIN_INNER_5_679_s, tv_r_JOIN_INNER_5_679_e;
    gettimeofday(&tv_r_JOIN_INNER_5_679_s, 0);
    prev_events_grp_JOIN_INNER_TD_5936.push_back(events_h2d_wr_JOIN_INNER_TD_6822[0]);
    trans_JOIN_INNER_TD_5936.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_5936), &(events_h2d_wr_JOIN_INNER_TD_5936[0]));
    events_grp_JOIN_INNER_TD_5936.push_back(events_h2d_wr_JOIN_INNER_TD_5936[0]);
    events_grp_JOIN_INNER_TD_5936.insert(std::end(events_grp_JOIN_INNER_TD_5936), std::begin(events_JOIN_INNER_TD_6822[0]), std::end(events_JOIN_INNER_TD_6822[0]));
    events_grp_JOIN_INNER_TD_5936.insert(std::end(events_grp_JOIN_INNER_TD_5936), std::begin(events_JOIN_INNER_TD_6822[1]), std::end(events_JOIN_INNER_TD_6822[1]));
    krnl_JOIN_INNER_TD_5936_part_right.run(0, &(events_grp_JOIN_INNER_TD_5936), &(events_JOIN_INNER_TD_5936[0][0]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_5936[i].run(0, &(events_grp_JOIN_INNER_TD_5936), &(events_JOIN_INNER_TD_5936[1][i]));
    }
    gettimeofday(&tv_r_JOIN_INNER_5_679_e, 0);

    struct timeval tv_r_JOIN_INNER_4_863_s, tv_r_JOIN_INNER_4_863_e;
    gettimeofday(&tv_r_JOIN_INNER_4_863_s, 0);
    prev_events_grp_JOIN_INNER_TD_4550.push_back(events_h2d_wr_JOIN_INNER_TD_5936[0]);
    trans_JOIN_INNER_TD_4550.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_4550), &(events_h2d_wr_JOIN_INNER_TD_4550[0]));
    events_grp_JOIN_INNER_TD_4550.push_back(events_h2d_wr_JOIN_INNER_TD_4550[0]);
    events_grp_JOIN_INNER_TD_4550.insert(std::end(events_grp_JOIN_INNER_TD_4550), std::begin(events_JOIN_INNER_TD_5936[0]), std::end(events_JOIN_INNER_TD_5936[0]));
    events_grp_JOIN_INNER_TD_4550.insert(std::end(events_grp_JOIN_INNER_TD_4550), std::begin(events_JOIN_INNER_TD_5936[1]), std::end(events_JOIN_INNER_TD_5936[1]));
    krnl_JOIN_INNER_TD_4550_part_right.run(0, &(events_grp_JOIN_INNER_TD_4550), &(events_JOIN_INNER_TD_4550[0][0]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_4550[i].run(0, &(events_grp_JOIN_INNER_TD_4550), &(events_JOIN_INNER_TD_4550[1][i]));
    }
    
    for (int i(0); i < hpTimes_join; ++i) {
        trans_JOIN_INNER_TD_4550_out.add(&(tbl_JOIN_INNER_TD_4550_output_partition_array[i]));
    }
    trans_JOIN_INNER_TD_4550_out.dev2host(0, &(events_JOIN_INNER_TD_4550[1]), &(events_d2h_rd_JOIN_INNER_TD_4550[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_4_863_e, 0);

    struct timeval tv_r_JOIN_INNER_3_166_s, tv_r_JOIN_INNER_3_166_e;
    gettimeofday(&tv_r_JOIN_INNER_3_166_s, 0);
    SW_JOIN_INNER_TD_3174(tbl_JOIN_INNER_TD_4550_output_partition_array, tbl_SerializeFromObject_TD_4433_input, tbl_JOIN_INNER_TD_3174_output, hpTimes_join);
    gettimeofday(&tv_r_JOIN_INNER_3_166_e, 0);

    struct timeval tv_r_Project_2_974_s, tv_r_Project_2_974_e;
    gettimeofday(&tv_r_Project_2_974_s, 0);
    SW_Project_TD_2289(tbl_JOIN_INNER_TD_3174_output, tbl_Project_TD_2289_output);
    gettimeofday(&tv_r_Project_2_974_e, 0);

    struct timeval tv_r_Aggregate_1_540_s, tv_r_Aggregate_1_540_e;
    gettimeofday(&tv_r_Aggregate_1_540_s, 0);
    SW_Aggregate_TD_1479(tbl_Project_TD_2289_output, tbl_Aggregate_TD_1479_output);
    gettimeofday(&tv_r_Aggregate_1_540_e, 0);

    struct timeval tv_r_Sort_0_462_s, tv_r_Sort_0_462_e;
    gettimeofday(&tv_r_Sort_0_462_s, 0);
    SW_Sort_TD_0706(tbl_Aggregate_TD_1479_output, tbl_Sort_TD_0706_output);
    gettimeofday(&tv_r_Sort_0_462_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_749_s, &tv_r_Filter_8_749_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9775_input: " << tbl_SerializeFromObject_TD_9775_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_554_s, &tv_r_JOIN_INNER_7_554_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_865_output: " << tbl_Filter_TD_865_output.getNumRow() << " " << "tbl_SerializeFromObject_TD_8891_input: " << tbl_SerializeFromObject_TD_8891_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_452_s, &tv_r_JOIN_INNER_6_452_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7954_output: " << tbl_JOIN_INNER_TD_7954_output.getNumRow() << " " << "tbl_SerializeFromObject_TD_7149_input: " << tbl_SerializeFromObject_TD_7149_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_679_s, &tv_r_JOIN_INNER_5_679_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6822_output: " << tbl_JOIN_INNER_TD_6822_output.getNumRow() << " " << "tbl_SerializeFromObject_TD_6711_input: " << tbl_SerializeFromObject_TD_6711_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_863_s, &tv_r_JOIN_INNER_4_863_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5936_output: " << tbl_JOIN_INNER_TD_5936_output.getNumRow() << " " << "tbl_SerializeFromObject_TD_568_input: " << tbl_SerializeFromObject_TD_568_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_166_s, &tv_r_JOIN_INNER_3_166_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4550_output: " << tbl_JOIN_INNER_TD_4550_output.getNumRow() << " " << "tbl_SerializeFromObject_TD_4433_input: " << tbl_SerializeFromObject_TD_4433_input.getNumRow() << " " << std::endl; 

    std::cout << "Project_2: " << tvdiff(&tv_r_Project_2_974_s, &tv_r_Project_2_974_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3174_output: " << tbl_JOIN_INNER_TD_3174_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_540_s, &tv_r_Aggregate_1_540_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_2289_output: " << tbl_Project_TD_2289_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_462_s, &tv_r_Sort_0_462_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_1479_output: " << tbl_Aggregate_TD_1479_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1049.218 * 1000 << "ms" << std::endl; 
    return 0; 
}
