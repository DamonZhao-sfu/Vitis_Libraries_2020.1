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

#include "cfgFunc_q17.hpp" 
#include "q17.hpp" 

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
    std::cout << "NOTE:running query #17\n."; 
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
    Table tbl_Aggregate_TD_0696_output("tbl_Aggregate_TD_0696_output", 183000000, 1, "");
    tbl_Aggregate_TD_0696_output.allocateHost();
    Table tbl_JOIN_INNER_TD_1700_output("tbl_JOIN_INNER_TD_1700_output", 183000000, 1, "");
    tbl_JOIN_INNER_TD_1700_output.allocateHost();
    Table tbl_JOIN_INNER_TD_2677_output("tbl_JOIN_INNER_TD_2677_output", 1507, 3, "");
    tbl_JOIN_INNER_TD_2677_output.allocateHost(1.2, hpTimes_join);
    Table tbl_Aggregate_TD_3446_output("tbl_Aggregate_TD_3446_output", 183000000, 2, "");
    tbl_Aggregate_TD_3446_output.allocateHost();
    Table tbl_SerializeFromObject_TD_3705_input;
    tbl_SerializeFromObject_TD_3705_input = Table("lineitem", lineitem_n, 3, in_dir);
    tbl_SerializeFromObject_TD_3705_input.addCol("l_partkey", 4);
    tbl_SerializeFromObject_TD_3705_input.addCol("l_quantity", 4);
    tbl_SerializeFromObject_TD_3705_input.addCol("l_extendedprice", 4);
    tbl_SerializeFromObject_TD_3705_input.allocateHost();
    tbl_SerializeFromObject_TD_3705_input.loadHost();
    Table tbl_SerializeFromObject_TD_3705_input_partition("tbl_SerializeFromObject_TD_3705_input_partition", lineitem_n, 3, "");
    tbl_SerializeFromObject_TD_3705_input_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_3705_input_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_3705_input_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_3705_input_partition_array[i] = tbl_SerializeFromObject_TD_3705_input_partition.createSubTable(i);
    }
    Table tbl_Filter_TD_34_output("tbl_Filter_TD_34_output", 183000000, 1, "");
    tbl_Filter_TD_34_output.allocateHost();
    Table tbl_Filter_TD_34_output_partition("tbl_Filter_TD_34_output_partition", 183000000, 1, "");
    tbl_Filter_TD_34_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_Filter_TD_34_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_Filter_TD_34_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_34_output_partition_array[i] = tbl_Filter_TD_34_output_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_4124_input;
    tbl_SerializeFromObject_TD_4124_input = Table("lineitem", lineitem_n, 2, in_dir);
    tbl_SerializeFromObject_TD_4124_input.addCol("l_partkey", 4);
    tbl_SerializeFromObject_TD_4124_input.addCol("l_quantity", 4);
    tbl_SerializeFromObject_TD_4124_input.allocateHost();
    tbl_SerializeFromObject_TD_4124_input.loadHost();
    Table tbl_SerializeFromObject_TD_478_input;
    tbl_SerializeFromObject_TD_478_input = Table("part", part_n, 3, in_dir);
    tbl_SerializeFromObject_TD_478_input.addCol("p_partkey", 4);
    tbl_SerializeFromObject_TD_478_input.addCol("p_brand", TPCH_READ_P_BRND_LEN+1);
    tbl_SerializeFromObject_TD_478_input.addCol("p_container", TPCH_READ_P_CNTR_LEN+1);
    tbl_SerializeFromObject_TD_478_input.allocateHost();
    tbl_SerializeFromObject_TD_478_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_2677_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_2677_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_2677_output_partition_array[i] = tbl_JOIN_INNER_TD_2677_output.createSubTable(i);
    }
    tbl_SerializeFromObject_TD_3705_input.allocateDevBuffer(context_h, 33);
    tbl_Filter_TD_34_output.allocateDevBuffer(context_h, 33);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_2677_cmds;
    cfg_JOIN_INNER_TD_2677_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_2677_gqe_join (cfg_JOIN_INNER_TD_2677_cmds.cmd);
    cfg_JOIN_INNER_TD_2677_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_2677_cmds_part;
    cfg_JOIN_INNER_TD_2677_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_2677_gqe_join_part (cfg_JOIN_INNER_TD_2677_cmds_part.cmd);
    cfg_JOIN_INNER_TD_2677_cmds_part.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_2677_part_left;
    krnl_JOIN_INNER_TD_2677_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_2677_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_Filter_TD_34_output, tbl_Filter_TD_34_output_partition, cfg_JOIN_INNER_TD_2677_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_2677_part_right;
    krnl_JOIN_INNER_TD_2677_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_2677_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_SerializeFromObject_TD_3705_input, tbl_SerializeFromObject_TD_3705_input_partition, cfg_JOIN_INNER_TD_2677_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_2677[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_2677[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_2677[i].setup(tbl_Filter_TD_34_output_partition_array[i], tbl_SerializeFromObject_TD_3705_input_partition_array[i], tbl_JOIN_INNER_TD_2677_output_partition_array[i], cfg_JOIN_INNER_TD_2677_cmds, buftmp_h);
    }
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_2677;
    trans_JOIN_INNER_TD_2677.setq(q_h);
    trans_JOIN_INNER_TD_2677.add(&(cfg_JOIN_INNER_TD_2677_cmds_part));
    trans_JOIN_INNER_TD_2677.add(&(cfg_JOIN_INNER_TD_2677_cmds));
    trans_JOIN_INNER_TD_2677.add(&(tbl_SerializeFromObject_TD_3705_input));
    transEngine trans_JOIN_INNER_TD_2677_out;
    trans_JOIN_INNER_TD_2677_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_2677;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_2677;
    std::vector<cl::Event> events_JOIN_INNER_TD_2677[2];
    events_h2d_wr_JOIN_INNER_TD_2677.resize(1);
    events_d2h_rd_JOIN_INNER_TD_2677.resize(1);
    events_JOIN_INNER_TD_2677[0].resize(2);
    events_JOIN_INNER_TD_2677[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_2677;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_2677;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_3_203_s, tv_r_Filter_3_203_e;
    gettimeofday(&tv_r_Filter_3_203_s, 0);
    SW_Filter_TD_34(tbl_SerializeFromObject_TD_478_input, tbl_Filter_TD_34_output);
    gettimeofday(&tv_r_Filter_3_203_e, 0);

    struct timeval tv_r_Aggregate_3_948_s, tv_r_Aggregate_3_948_e;
    gettimeofday(&tv_r_Aggregate_3_948_s, 0);
    SW_Aggregate_TD_3446(tbl_SerializeFromObject_TD_4124_input, tbl_Aggregate_TD_3446_output);
    gettimeofday(&tv_r_Aggregate_3_948_e, 0);

    struct timeval tv_r_JOIN_INNER_2_708_s, tv_r_JOIN_INNER_2_708_e;
    gettimeofday(&tv_r_JOIN_INNER_2_708_s, 0);
    trans_JOIN_INNER_TD_2677.add(&(tbl_Filter_TD_34_output));
    trans_JOIN_INNER_TD_2677.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_2677), &(events_h2d_wr_JOIN_INNER_TD_2677[0]));
    events_grp_JOIN_INNER_TD_2677.push_back(events_h2d_wr_JOIN_INNER_TD_2677[0]);
    krnl_JOIN_INNER_TD_2677_part_left.run(0, &(events_grp_JOIN_INNER_TD_2677), &(events_JOIN_INNER_TD_2677[0][0]));
    krnl_JOIN_INNER_TD_2677_part_right.run(0, &(events_grp_JOIN_INNER_TD_2677), &(events_JOIN_INNER_TD_2677[0][1]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_2677[i].run(0, &(events_JOIN_INNER_TD_2677[0]), &(events_JOIN_INNER_TD_2677[1][i]));
    }
    
    for (int i(0); i < hpTimes_join; ++i) {
        trans_JOIN_INNER_TD_2677_out.add(&(tbl_JOIN_INNER_TD_2677_output_partition_array[i]));
    }
    trans_JOIN_INNER_TD_2677_out.dev2host(0, &(events_JOIN_INNER_TD_2677[1]), &(events_d2h_rd_JOIN_INNER_TD_2677[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_2_708_e, 0);

    struct timeval tv_r_JOIN_INNER_1_31_s, tv_r_JOIN_INNER_1_31_e;
    gettimeofday(&tv_r_JOIN_INNER_1_31_s, 0);
    SW_JOIN_INNER_TD_1700(tbl_JOIN_INNER_TD_2677_output_partition_array, tbl_Aggregate_TD_3446_output, tbl_JOIN_INNER_TD_1700_output, hpTimes_join);
    gettimeofday(&tv_r_JOIN_INNER_1_31_e, 0);

    struct timeval tv_r_Aggregate_0_213_s, tv_r_Aggregate_0_213_e;
    gettimeofday(&tv_r_Aggregate_0_213_s, 0);
    SW_Aggregate_TD_0696(tbl_JOIN_INNER_TD_1700_output, tbl_Aggregate_TD_0696_output);
    gettimeofday(&tv_r_Aggregate_0_213_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_203_s, &tv_r_Filter_3_203_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_478_input: " << tbl_SerializeFromObject_TD_478_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_948_s, &tv_r_Aggregate_3_948_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_4124_input: " << tbl_SerializeFromObject_TD_4124_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_2: " << tvdiff(&tv_r_JOIN_INNER_2_708_s, &tv_r_JOIN_INNER_2_708_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3705_input: " << tbl_SerializeFromObject_TD_3705_input.getNumRow() << " " << "tbl_Filter_TD_34_output: " << tbl_Filter_TD_34_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_1: " << tvdiff(&tv_r_JOIN_INNER_1_31_s, &tv_r_JOIN_INNER_1_31_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_2677_output: " << tbl_JOIN_INNER_TD_2677_output.getNumRow() << " " << "tbl_Aggregate_TD_3446_output: " << tbl_Aggregate_TD_3446_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_0: " << tvdiff(&tv_r_Aggregate_0_213_s, &tv_r_Aggregate_0_213_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_1700_output: " << tbl_JOIN_INNER_TD_1700_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1472.1187 * 1000 << "ms" << std::endl; 
    return 0; 
}
