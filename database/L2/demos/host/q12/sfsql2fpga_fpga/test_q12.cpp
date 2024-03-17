// number of overlays (w/o fusion): 1 
// number of overlays (w/ fusion): 1 
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

#include "cfgFunc_q12.hpp" 
#include "q12.hpp" 

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
    std::cout << "NOTE:running query #12\n."; 
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
    Table tbl_Sort_TD_0753_output("tbl_Sort_TD_0753_output", 183000000, 3, "");
    tbl_Sort_TD_0753_output.allocateHost();
    Table tbl_Aggregate_TD_1399_output("tbl_Aggregate_TD_1399_output", 183000000, 3, "");
    tbl_Aggregate_TD_1399_output.allocateHost();
    Table tbl_JOIN_INNER_TD_2407_output("tbl_JOIN_INNER_TD_2407_output", 31211, 2, "");
    tbl_JOIN_INNER_TD_2407_output.allocateHost(1.2, hpTimes_join);
    Table tbl_SerializeFromObject_TD_3642_input_stringRowIDSubstitute;
    tbl_SerializeFromObject_TD_3642_input_stringRowIDSubstitute = Table("order", order_n, 2, in_dir);
    tbl_SerializeFromObject_TD_3642_input_stringRowIDSubstitute.addCol("o_orderkey", 4);
    tbl_SerializeFromObject_TD_3642_input_stringRowIDSubstitute.addCol("o_orderpriority", 4, 1, 0);
    tbl_SerializeFromObject_TD_3642_input_stringRowIDSubstitute.allocateHost();
    tbl_SerializeFromObject_TD_3642_input_stringRowIDSubstitute.loadHost();
    Table tbl_SerializeFromObject_TD_3642_input_stringRowIDSubstitute_partition("tbl_SerializeFromObject_TD_3642_input_stringRowIDSubstitute_partition", order_n, 2, "");
    tbl_SerializeFromObject_TD_3642_input_stringRowIDSubstitute_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_3642_input_stringRowIDSubstitute_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_3642_input_stringRowIDSubstitute_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_3642_input_stringRowIDSubstitute_partition_array[i] = tbl_SerializeFromObject_TD_3642_input_stringRowIDSubstitute_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_3642_input;
    tbl_SerializeFromObject_TD_3642_input = Table("order", order_n, 2, in_dir);
    tbl_SerializeFromObject_TD_3642_input.addCol("o_orderkey", 4);
    tbl_SerializeFromObject_TD_3642_input.addCol("o_orderpriority", TPCH_READ_MAXAGG_LEN+1);
    tbl_SerializeFromObject_TD_3642_input.allocateHost();
    tbl_SerializeFromObject_TD_3642_input.loadHost();
    Table tbl_Filter_TD_393_output("tbl_Filter_TD_393_output", 183000000, 2, "");
    tbl_Filter_TD_393_output.allocateHost();
    Table tbl_Filter_TD_393_output_partition("tbl_Filter_TD_393_output_partition", 183000000, 2, "");
    tbl_Filter_TD_393_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_Filter_TD_393_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_Filter_TD_393_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_393_output_partition_array[i] = tbl_Filter_TD_393_output_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_4563_input;
    tbl_SerializeFromObject_TD_4563_input = Table("lineitem", lineitem_n, 5, in_dir);
    tbl_SerializeFromObject_TD_4563_input.addCol("l_orderkey", 4);
    tbl_SerializeFromObject_TD_4563_input.addCol("l_shipmode", TPCH_READ_MAXAGG_LEN+1);
    tbl_SerializeFromObject_TD_4563_input.addCol("l_commitdate", 4);
    tbl_SerializeFromObject_TD_4563_input.addCol("l_receiptdate", 4);
    tbl_SerializeFromObject_TD_4563_input.addCol("l_shipdate", 4);
    tbl_SerializeFromObject_TD_4563_input.allocateHost();
    tbl_SerializeFromObject_TD_4563_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_2407_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_2407_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_2407_output_partition_array[i] = tbl_JOIN_INNER_TD_2407_output.createSubTable(i);
    }
    tbl_SerializeFromObject_TD_3642_input_stringRowIDSubstitute.allocateDevBuffer(context_h, 33);
    tbl_Filter_TD_393_output.allocateDevBuffer(context_h, 33);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_2407_cmds;
    cfg_JOIN_INNER_TD_2407_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_2407_gqe_join (cfg_JOIN_INNER_TD_2407_cmds.cmd);
    cfg_JOIN_INNER_TD_2407_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_2407_cmds_part;
    cfg_JOIN_INNER_TD_2407_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_2407_gqe_join_part (cfg_JOIN_INNER_TD_2407_cmds_part.cmd);
    cfg_JOIN_INNER_TD_2407_cmds_part.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_2407_part_left;
    krnl_JOIN_INNER_TD_2407_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_2407_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_Filter_TD_393_output, tbl_Filter_TD_393_output_partition, cfg_JOIN_INNER_TD_2407_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_2407_part_right;
    krnl_JOIN_INNER_TD_2407_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_2407_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_SerializeFromObject_TD_3642_input_stringRowIDSubstitute, tbl_SerializeFromObject_TD_3642_input_stringRowIDSubstitute_partition, cfg_JOIN_INNER_TD_2407_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_2407[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_2407[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_2407[i].setup(tbl_Filter_TD_393_output_partition_array[i], tbl_SerializeFromObject_TD_3642_input_stringRowIDSubstitute_partition_array[i], tbl_JOIN_INNER_TD_2407_output_partition_array[i], cfg_JOIN_INNER_TD_2407_cmds, buftmp_h);
    }
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_2407;
    trans_JOIN_INNER_TD_2407.setq(q_h);
    trans_JOIN_INNER_TD_2407.add(&(cfg_JOIN_INNER_TD_2407_cmds_part));
    trans_JOIN_INNER_TD_2407.add(&(cfg_JOIN_INNER_TD_2407_cmds));
    trans_JOIN_INNER_TD_2407.add(&(tbl_SerializeFromObject_TD_3642_input_stringRowIDSubstitute));
    transEngine trans_JOIN_INNER_TD_2407_out;
    trans_JOIN_INNER_TD_2407_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_2407;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_2407;
    std::vector<cl::Event> events_JOIN_INNER_TD_2407[2];
    events_h2d_wr_JOIN_INNER_TD_2407.resize(1);
    events_d2h_rd_JOIN_INNER_TD_2407.resize(1);
    events_JOIN_INNER_TD_2407[0].resize(2);
    events_JOIN_INNER_TD_2407[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_2407;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_2407;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_3_724_s, tv_r_Filter_3_724_e;
    gettimeofday(&tv_r_Filter_3_724_s, 0);
    SW_Filter_TD_393(tbl_SerializeFromObject_TD_4563_input, tbl_Filter_TD_393_output);
    gettimeofday(&tv_r_Filter_3_724_e, 0);

    struct timeval tv_r_JOIN_INNER_2_808_s, tv_r_JOIN_INNER_2_808_e;
    gettimeofday(&tv_r_JOIN_INNER_2_808_s, 0);
    trans_JOIN_INNER_TD_2407.add(&(tbl_Filter_TD_393_output));
    trans_JOIN_INNER_TD_2407.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_2407), &(events_h2d_wr_JOIN_INNER_TD_2407[0]));
    events_grp_JOIN_INNER_TD_2407.push_back(events_h2d_wr_JOIN_INNER_TD_2407[0]);
    krnl_JOIN_INNER_TD_2407_part_left.run(0, &(events_grp_JOIN_INNER_TD_2407), &(events_JOIN_INNER_TD_2407[0][0]));
    krnl_JOIN_INNER_TD_2407_part_right.run(0, &(events_grp_JOIN_INNER_TD_2407), &(events_JOIN_INNER_TD_2407[0][1]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_2407[i].run(0, &(events_JOIN_INNER_TD_2407[0]), &(events_JOIN_INNER_TD_2407[1][i]));
    }
    
    for (int i(0); i < hpTimes_join; ++i) {
        trans_JOIN_INNER_TD_2407_out.add(&(tbl_JOIN_INNER_TD_2407_output_partition_array[i]));
    }
    trans_JOIN_INNER_TD_2407_out.dev2host(0, &(events_JOIN_INNER_TD_2407[1]), &(events_d2h_rd_JOIN_INNER_TD_2407[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_2_808_e, 0);

    struct timeval tv_r_Aggregate_1_312_s, tv_r_Aggregate_1_312_e;
    gettimeofday(&tv_r_Aggregate_1_312_s, 0);
    SW_Aggregate_TD_1399(tbl_JOIN_INNER_TD_2407_output_partition_array, tbl_SerializeFromObject_TD_3642_input, tbl_SerializeFromObject_TD_4563_input, tbl_Aggregate_TD_1399_output, hpTimes_join);
    gettimeofday(&tv_r_Aggregate_1_312_e, 0);

    struct timeval tv_r_Sort_0_610_s, tv_r_Sort_0_610_e;
    gettimeofday(&tv_r_Sort_0_610_s, 0);
    SW_Sort_TD_0753(tbl_Aggregate_TD_1399_output, tbl_Sort_TD_0753_output);
    gettimeofday(&tv_r_Sort_0_610_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_724_s, &tv_r_Filter_3_724_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_4563_input: " << tbl_SerializeFromObject_TD_4563_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_2: " << tvdiff(&tv_r_JOIN_INNER_2_808_s, &tv_r_JOIN_INNER_2_808_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3642_input_stringRowIDSubstitute: " << tbl_SerializeFromObject_TD_3642_input_stringRowIDSubstitute.getNumRow() << " " << "tbl_Filter_TD_393_output: " << tbl_Filter_TD_393_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_312_s, &tv_r_Aggregate_1_312_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_2407_output: " << tbl_JOIN_INNER_TD_2407_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_610_s, &tv_r_Sort_0_610_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_1399_output: " << tbl_Aggregate_TD_1399_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 809.9673 * 1000 << "ms" << std::endl; 
    return 0; 
}
