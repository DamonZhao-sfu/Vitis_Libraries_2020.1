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

#include "cfgFunc_q5.hpp" 
#include "q5.hpp" 

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
    std::cout << "NOTE:running query #5\n."; 
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
    Table tbl_Sort_TD_0647_output("tbl_Sort_TD_0647_output", 183000000, 2, "");
    tbl_Sort_TD_0647_output.allocateHost();
    Table tbl_Aggregate_TD_1299_output("tbl_Aggregate_TD_1299_output", 183000000, 2, "");
    tbl_Aggregate_TD_1299_output.allocateHost();
    Table tbl_JOIN_INNER_TD_2549_output("tbl_JOIN_INNER_TD_2549_output", 183000000, 3, "");
    tbl_JOIN_INNER_TD_2549_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3446_output("tbl_JOIN_INNER_TD_3446_output", 183000000, 4, "");
    tbl_JOIN_INNER_TD_3446_output.allocateHost();
    Table tbl_Filter_TD_3311_output("tbl_Filter_TD_3311_output", 183000000, 1, "");
    tbl_Filter_TD_3311_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4711_output("tbl_JOIN_INNER_TD_4711_output", 37000, 3, "");
    tbl_JOIN_INNER_TD_4711_output.allocateHost(1.2, hpTimes_join);
    Table tbl_SerializeFromObject_TD_4423_input;
    tbl_SerializeFromObject_TD_4423_input = Table("nation", nation_n, 3, in_dir);
    tbl_SerializeFromObject_TD_4423_input.addCol("n_nationkey", 4);
    tbl_SerializeFromObject_TD_4423_input.addCol("n_name", TPCH_READ_NATION_LEN+1);
    tbl_SerializeFromObject_TD_4423_input.addCol("n_regionkey", 4);
    tbl_SerializeFromObject_TD_4423_input.allocateHost();
    tbl_SerializeFromObject_TD_4423_input.loadHost();
    Table tbl_SerializeFromObject_TD_4686_input;
    tbl_SerializeFromObject_TD_4686_input = Table("region", region_n, 2, in_dir);
    tbl_SerializeFromObject_TD_4686_input.addCol("r_regionkey", 4);
    tbl_SerializeFromObject_TD_4686_input.addCol("r_name", TPCH_READ_REGION_LEN+1);
    tbl_SerializeFromObject_TD_4686_input.allocateHost();
    tbl_SerializeFromObject_TD_4686_input.loadHost();
    Table tbl_JOIN_INNER_TD_5225_output("tbl_JOIN_INNER_TD_5225_output", 909000, 4, "");
    tbl_JOIN_INNER_TD_5225_output.allocateHost(1.2, hpTimes_join);
    Table tbl_SerializeFromObject_TD_5772_input;
    tbl_SerializeFromObject_TD_5772_input = Table("supplier", supplier_n, 2, in_dir);
    tbl_SerializeFromObject_TD_5772_input.addCol("s_suppkey", 4);
    tbl_SerializeFromObject_TD_5772_input.addCol("s_nationkey", 4);
    tbl_SerializeFromObject_TD_5772_input.allocateHost();
    tbl_SerializeFromObject_TD_5772_input.loadHost();
    Table tbl_SerializeFromObject_TD_5772_input_partition("tbl_SerializeFromObject_TD_5772_input_partition", supplier_n, 2, "");
    tbl_SerializeFromObject_TD_5772_input_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_5772_input_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_5772_input_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_5772_input_partition_array[i] = tbl_SerializeFromObject_TD_5772_input_partition.createSubTable(i);
    }
    Table tbl_JOIN_INNER_TD_624_output("tbl_JOIN_INNER_TD_624_output", 227000, 2, "");
    tbl_JOIN_INNER_TD_624_output.allocateHost(1.2, hpTimes_join);
    Table tbl_SerializeFromObject_TD_620_input;
    tbl_SerializeFromObject_TD_620_input = Table("lineitem", lineitem_n, 4, in_dir);
    tbl_SerializeFromObject_TD_620_input.addCol("l_orderkey", 4);
    tbl_SerializeFromObject_TD_620_input.addCol("l_suppkey", 4);
    tbl_SerializeFromObject_TD_620_input.addCol("l_extendedprice", 4);
    tbl_SerializeFromObject_TD_620_input.addCol("l_discount", 4);
    tbl_SerializeFromObject_TD_620_input.allocateHost();
    tbl_SerializeFromObject_TD_620_input.loadHost();
    Table tbl_SerializeFromObject_TD_620_input_partition("tbl_SerializeFromObject_TD_620_input_partition", lineitem_n, 4, "");
    tbl_SerializeFromObject_TD_620_input_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_620_input_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_620_input_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_620_input_partition_array[i] = tbl_SerializeFromObject_TD_620_input_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_7239_input;
    tbl_SerializeFromObject_TD_7239_input = Table("customer", customer_n, 2, in_dir);
    tbl_SerializeFromObject_TD_7239_input.addCol("c_custkey", 4);
    tbl_SerializeFromObject_TD_7239_input.addCol("c_nationkey", 4);
    tbl_SerializeFromObject_TD_7239_input.allocateHost();
    tbl_SerializeFromObject_TD_7239_input.loadHost();
    Table tbl_SerializeFromObject_TD_7239_input_partition("tbl_SerializeFromObject_TD_7239_input_partition", customer_n, 2, "");
    tbl_SerializeFromObject_TD_7239_input_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_7239_input_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_7239_input_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_7239_input_partition_array[i] = tbl_SerializeFromObject_TD_7239_input_partition.createSubTable(i);
    }
    Table tbl_Filter_TD_7691_output("tbl_Filter_TD_7691_output", 183000000, 2, "");
    tbl_Filter_TD_7691_output.allocateHost();
    Table tbl_Filter_TD_7691_output_partition("tbl_Filter_TD_7691_output_partition", 183000000, 2, "");
    tbl_Filter_TD_7691_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_Filter_TD_7691_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_Filter_TD_7691_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_7691_output_partition_array[i] = tbl_Filter_TD_7691_output_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_8758_input;
    tbl_SerializeFromObject_TD_8758_input = Table("order", order_n, 3, in_dir);
    tbl_SerializeFromObject_TD_8758_input.addCol("o_orderkey", 4);
    tbl_SerializeFromObject_TD_8758_input.addCol("o_custkey", 4);
    tbl_SerializeFromObject_TD_8758_input.addCol("o_orderdate", 4);
    tbl_SerializeFromObject_TD_8758_input.allocateHost();
    tbl_SerializeFromObject_TD_8758_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_4711_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_4711_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_4711_output_partition_array[i] = tbl_JOIN_INNER_TD_4711_output.createSubTable(i);
    }
    tbl_JOIN_INNER_TD_5225_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_5225_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_5225_output_partition_array[i] = tbl_JOIN_INNER_TD_5225_output.createSubTable(i);
    }
    tbl_SerializeFromObject_TD_5772_input.allocateDevBuffer(context_h, 33);
    tbl_JOIN_INNER_TD_624_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_624_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_624_output_partition_array[i] = tbl_JOIN_INNER_TD_624_output.createSubTable(i);
    }
    tbl_SerializeFromObject_TD_620_input.allocateDevBuffer(context_h, 33);
    tbl_SerializeFromObject_TD_7239_input.allocateDevBuffer(context_h, 33);
    tbl_Filter_TD_7691_output.allocateDevBuffer(context_h, 33);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_4711_cmds;
    cfg_JOIN_INNER_TD_4711_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_4711_gqe_join (cfg_JOIN_INNER_TD_4711_cmds.cmd);
    cfg_JOIN_INNER_TD_4711_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_4711_cmds_part;
    cfg_JOIN_INNER_TD_4711_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_4711_gqe_join_part (cfg_JOIN_INNER_TD_4711_cmds_part.cmd);
    cfg_JOIN_INNER_TD_4711_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_5225_cmds;
    cfg_JOIN_INNER_TD_5225_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_5225_gqe_join (cfg_JOIN_INNER_TD_5225_cmds.cmd);
    cfg_JOIN_INNER_TD_5225_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_5225_cmds_part;
    cfg_JOIN_INNER_TD_5225_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_5225_gqe_join_part (cfg_JOIN_INNER_TD_5225_cmds_part.cmd);
    cfg_JOIN_INNER_TD_5225_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_624_cmds;
    cfg_JOIN_INNER_TD_624_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_624_gqe_join (cfg_JOIN_INNER_TD_624_cmds.cmd);
    cfg_JOIN_INNER_TD_624_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_624_cmds_part;
    cfg_JOIN_INNER_TD_624_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_624_gqe_join_part (cfg_JOIN_INNER_TD_624_cmds_part.cmd);
    cfg_JOIN_INNER_TD_624_cmds_part.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_4711_part_left;
    krnl_JOIN_INNER_TD_4711_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_4711_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_SerializeFromObject_TD_5772_input, tbl_SerializeFromObject_TD_5772_input_partition, cfg_JOIN_INNER_TD_4711_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_4711[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_4711[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_4711[i].setup(tbl_SerializeFromObject_TD_5772_input_partition_array[i], tbl_JOIN_INNER_TD_5225_output_partition_array[i], tbl_JOIN_INNER_TD_4711_output_partition_array[i], cfg_JOIN_INNER_TD_4711_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_INNER_TD_5225_part_right;
    krnl_JOIN_INNER_TD_5225_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_5225_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_SerializeFromObject_TD_620_input, tbl_SerializeFromObject_TD_620_input_partition, cfg_JOIN_INNER_TD_5225_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_5225[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_5225[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_5225[i].setup(tbl_JOIN_INNER_TD_624_output_partition_array[i], tbl_SerializeFromObject_TD_620_input_partition_array[i], tbl_JOIN_INNER_TD_5225_output_partition_array[i], cfg_JOIN_INNER_TD_5225_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_INNER_TD_624_part_left;
    krnl_JOIN_INNER_TD_624_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_624_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_SerializeFromObject_TD_7239_input, tbl_SerializeFromObject_TD_7239_input_partition, cfg_JOIN_INNER_TD_624_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_624_part_right;
    krnl_JOIN_INNER_TD_624_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_624_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_Filter_TD_7691_output, tbl_Filter_TD_7691_output_partition, cfg_JOIN_INNER_TD_624_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_624[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_624[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_624[i].setup(tbl_SerializeFromObject_TD_7239_input_partition_array[i], tbl_Filter_TD_7691_output_partition_array[i], tbl_JOIN_INNER_TD_624_output_partition_array[i], cfg_JOIN_INNER_TD_624_cmds, buftmp_h);
    }
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_4711;
    trans_JOIN_INNER_TD_4711.setq(q_h);
    trans_JOIN_INNER_TD_4711.add(&(cfg_JOIN_INNER_TD_4711_cmds));
    trans_JOIN_INNER_TD_4711.add(&(tbl_SerializeFromObject_TD_5772_input));
    transEngine trans_JOIN_INNER_TD_4711_out;
    trans_JOIN_INNER_TD_4711_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_5225;
    trans_JOIN_INNER_TD_5225.setq(q_h);
    trans_JOIN_INNER_TD_5225.add(&(cfg_JOIN_INNER_TD_5225_cmds));
    trans_JOIN_INNER_TD_5225.add(&(tbl_SerializeFromObject_TD_620_input));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_624;
    trans_JOIN_INNER_TD_624.setq(q_h);
    trans_JOIN_INNER_TD_624.add(&(cfg_JOIN_INNER_TD_624_cmds_part));
    trans_JOIN_INNER_TD_624.add(&(cfg_JOIN_INNER_TD_624_cmds));
    trans_JOIN_INNER_TD_624.add(&(tbl_SerializeFromObject_TD_7239_input));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_4711;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_4711;
    std::vector<cl::Event> events_JOIN_INNER_TD_4711[2];
    events_h2d_wr_JOIN_INNER_TD_4711.resize(1);
    events_d2h_rd_JOIN_INNER_TD_4711.resize(1);
    events_JOIN_INNER_TD_4711[0].resize(1);
    events_JOIN_INNER_TD_4711[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_4711;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_4711;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_5225;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_5225;
    std::vector<cl::Event> events_JOIN_INNER_TD_5225[2];
    events_h2d_wr_JOIN_INNER_TD_5225.resize(1);
    events_d2h_rd_JOIN_INNER_TD_5225.resize(1);
    events_JOIN_INNER_TD_5225[0].resize(1);
    events_JOIN_INNER_TD_5225[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_5225;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_5225;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_624;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_624;
    std::vector<cl::Event> events_JOIN_INNER_TD_624[2];
    events_h2d_wr_JOIN_INNER_TD_624.resize(1);
    events_d2h_rd_JOIN_INNER_TD_624.resize(1);
    events_JOIN_INNER_TD_624[0].resize(2);
    events_JOIN_INNER_TD_624[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_624;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_624;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_7_624_s, tv_r_Filter_7_624_e;
    gettimeofday(&tv_r_Filter_7_624_s, 0);
    SW_Filter_TD_7691(tbl_SerializeFromObject_TD_8758_input, tbl_Filter_TD_7691_output);
    gettimeofday(&tv_r_Filter_7_624_e, 0);

    struct timeval tv_r_JOIN_INNER_6_637_s, tv_r_JOIN_INNER_6_637_e;
    gettimeofday(&tv_r_JOIN_INNER_6_637_s, 0);
    trans_JOIN_INNER_TD_624.add(&(tbl_Filter_TD_7691_output));
    trans_JOIN_INNER_TD_624.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_624), &(events_h2d_wr_JOIN_INNER_TD_624[0]));
    events_grp_JOIN_INNER_TD_624.push_back(events_h2d_wr_JOIN_INNER_TD_624[0]);
    krnl_JOIN_INNER_TD_624_part_left.run(0, &(events_grp_JOIN_INNER_TD_624), &(events_JOIN_INNER_TD_624[0][0]));
    krnl_JOIN_INNER_TD_624_part_right.run(0, &(events_grp_JOIN_INNER_TD_624), &(events_JOIN_INNER_TD_624[0][1]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_624[i].run(0, &(events_JOIN_INNER_TD_624[0]), &(events_JOIN_INNER_TD_624[1][i]));
    }
    gettimeofday(&tv_r_JOIN_INNER_6_637_e, 0);

    struct timeval tv_r_JOIN_INNER_5_619_s, tv_r_JOIN_INNER_5_619_e;
    gettimeofday(&tv_r_JOIN_INNER_5_619_s, 0);
    prev_events_grp_JOIN_INNER_TD_5225.push_back(events_h2d_wr_JOIN_INNER_TD_624[0]);
    trans_JOIN_INNER_TD_5225.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_5225), &(events_h2d_wr_JOIN_INNER_TD_5225[0]));
    events_grp_JOIN_INNER_TD_5225.push_back(events_h2d_wr_JOIN_INNER_TD_5225[0]);
    events_grp_JOIN_INNER_TD_5225.insert(std::end(events_grp_JOIN_INNER_TD_5225), std::begin(events_JOIN_INNER_TD_624[0]), std::end(events_JOIN_INNER_TD_624[0]));
    events_grp_JOIN_INNER_TD_5225.insert(std::end(events_grp_JOIN_INNER_TD_5225), std::begin(events_JOIN_INNER_TD_624[1]), std::end(events_JOIN_INNER_TD_624[1]));
    krnl_JOIN_INNER_TD_5225_part_right.run(0, &(events_grp_JOIN_INNER_TD_5225), &(events_JOIN_INNER_TD_5225[0][0]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_5225[i].run(0, &(events_grp_JOIN_INNER_TD_5225), &(events_JOIN_INNER_TD_5225[1][i]));
    }
    gettimeofday(&tv_r_JOIN_INNER_5_619_e, 0);

    struct timeval tv_r_JOIN_INNER_4_486_s, tv_r_JOIN_INNER_4_486_e;
    gettimeofday(&tv_r_JOIN_INNER_4_486_s, 0);
    prev_events_grp_JOIN_INNER_TD_4711.push_back(events_h2d_wr_JOIN_INNER_TD_5225[0]);
    trans_JOIN_INNER_TD_4711.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_4711), &(events_h2d_wr_JOIN_INNER_TD_4711[0]));
    events_grp_JOIN_INNER_TD_4711.push_back(events_h2d_wr_JOIN_INNER_TD_4711[0]);
    events_grp_JOIN_INNER_TD_4711.insert(std::end(events_grp_JOIN_INNER_TD_4711), std::begin(events_JOIN_INNER_TD_5225[0]), std::end(events_JOIN_INNER_TD_5225[0]));
    events_grp_JOIN_INNER_TD_4711.insert(std::end(events_grp_JOIN_INNER_TD_4711), std::begin(events_JOIN_INNER_TD_5225[1]), std::end(events_JOIN_INNER_TD_5225[1]));
    krnl_JOIN_INNER_TD_4711_part_left.run(0, &(events_grp_JOIN_INNER_TD_4711), &(events_JOIN_INNER_TD_4711[0][0]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_4711[i].run(0, &(events_JOIN_INNER_TD_4711[0]), &(events_JOIN_INNER_TD_4711[1][i]));
    }
    
    for (int i(0); i < hpTimes_join; ++i) {
        trans_JOIN_INNER_TD_4711_out.add(&(tbl_JOIN_INNER_TD_4711_output_partition_array[i]));
    }
    trans_JOIN_INNER_TD_4711_out.dev2host(0, &(events_JOIN_INNER_TD_4711[1]), &(events_d2h_rd_JOIN_INNER_TD_4711[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_4_486_e, 0);

    struct timeval tv_r_Filter_3_479_s, tv_r_Filter_3_479_e;
    gettimeofday(&tv_r_Filter_3_479_s, 0);
    SW_Filter_TD_3311(tbl_SerializeFromObject_TD_4686_input, tbl_Filter_TD_3311_output);
    gettimeofday(&tv_r_Filter_3_479_e, 0);

    struct timeval tv_r_JOIN_INNER_3_930_s, tv_r_JOIN_INNER_3_930_e;
    gettimeofday(&tv_r_JOIN_INNER_3_930_s, 0);
    SW_JOIN_INNER_TD_3446(tbl_JOIN_INNER_TD_4711_output_partition_array, tbl_SerializeFromObject_TD_4423_input, tbl_JOIN_INNER_TD_3446_output, hpTimes_join);
    gettimeofday(&tv_r_JOIN_INNER_3_930_e, 0);

    struct timeval tv_r_JOIN_INNER_2_341_s, tv_r_JOIN_INNER_2_341_e;
    gettimeofday(&tv_r_JOIN_INNER_2_341_s, 0);
    SW_JOIN_INNER_TD_2549(tbl_JOIN_INNER_TD_3446_output, tbl_Filter_TD_3311_output, tbl_JOIN_INNER_TD_2549_output);
    gettimeofday(&tv_r_JOIN_INNER_2_341_e, 0);

    struct timeval tv_r_Aggregate_1_770_s, tv_r_Aggregate_1_770_e;
    gettimeofday(&tv_r_Aggregate_1_770_s, 0);
    SW_Aggregate_TD_1299(tbl_JOIN_INNER_TD_2549_output, tbl_Aggregate_TD_1299_output);
    gettimeofday(&tv_r_Aggregate_1_770_e, 0);

    struct timeval tv_r_Sort_0_938_s, tv_r_Sort_0_938_e;
    gettimeofday(&tv_r_Sort_0_938_s, 0);
    SW_Sort_TD_0647(tbl_Aggregate_TD_1299_output, tbl_Sort_TD_0647_output);
    gettimeofday(&tv_r_Sort_0_938_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_624_s, &tv_r_Filter_7_624_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8758_input: " << tbl_SerializeFromObject_TD_8758_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_637_s, &tv_r_JOIN_INNER_6_637_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7239_input: " << tbl_SerializeFromObject_TD_7239_input.getNumRow() << " " << "tbl_Filter_TD_7691_output: " << tbl_Filter_TD_7691_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_619_s, &tv_r_JOIN_INNER_5_619_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_624_output: " << tbl_JOIN_INNER_TD_624_output.getNumRow() << " " << "tbl_SerializeFromObject_TD_620_input: " << tbl_SerializeFromObject_TD_620_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_486_s, &tv_r_JOIN_INNER_4_486_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5225_output: " << tbl_JOIN_INNER_TD_5225_output.getNumRow() << " " << "tbl_SerializeFromObject_TD_5772_input: " << tbl_SerializeFromObject_TD_5772_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_479_s, &tv_r_Filter_3_479_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_4686_input: " << tbl_SerializeFromObject_TD_4686_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_930_s, &tv_r_JOIN_INNER_3_930_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4711_output: " << tbl_JOIN_INNER_TD_4711_output.getNumRow() << " " << "tbl_SerializeFromObject_TD_4423_input: " << tbl_SerializeFromObject_TD_4423_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_2: " << tvdiff(&tv_r_JOIN_INNER_2_341_s, &tv_r_JOIN_INNER_2_341_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3446_output: " << tbl_JOIN_INNER_TD_3446_output.getNumRow() << " " << "tbl_Filter_TD_3311_output: " << tbl_Filter_TD_3311_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_770_s, &tv_r_Aggregate_1_770_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_2549_output: " << tbl_JOIN_INNER_TD_2549_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_938_s, &tv_r_Sort_0_938_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_1299_output: " << tbl_Aggregate_TD_1299_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 908.73724 * 1000 << "ms" << std::endl; 
    return 0; 
}
