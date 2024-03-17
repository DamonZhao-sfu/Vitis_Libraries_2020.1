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

#include "cfgFunc_q22.hpp" 
#include "q22.hpp" 

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
    std::cout << "NOTE:running query #22\n."; 
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
    Table tbl_Sort_TD_0764_output("tbl_Sort_TD_0764_output", 183000000, 3, "");
    tbl_Sort_TD_0764_output.allocateHost();
    Table tbl_Aggregate_TD_1795_output("tbl_Aggregate_TD_1795_output", 183000000, 3, "");
    tbl_Aggregate_TD_1795_output.allocateHost();
    Table tbl_Project_TD_2712_output("tbl_Project_TD_2712_output", 183000000, 2, "");
    tbl_Project_TD_2712_output.allocateHost();
    Table tbl_JOIN_LEFTANTI_TD_3178_output("tbl_JOIN_LEFTANTI_TD_3178_output", 6283, 2, "");
    tbl_JOIN_LEFTANTI_TD_3178_output.allocateHost(1.2, hpTimes_join);
    Table tbl_Filter_TD_4410_output("tbl_Filter_TD_4410_output", 183000000, 3, "");
    tbl_Filter_TD_4410_output.allocateHost();
    Table tbl_Filter_TD_4410_output_partition("tbl_Filter_TD_4410_output_partition", 183000000, 3, "");
    tbl_Filter_TD_4410_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_Filter_TD_4410_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_Filter_TD_4410_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_4410_output_partition_array[i] = tbl_Filter_TD_4410_output_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_4666_input;
    tbl_SerializeFromObject_TD_4666_input = Table("order", order_n, 1, in_dir);
    tbl_SerializeFromObject_TD_4666_input.addCol("o_custkey", 4);
    tbl_SerializeFromObject_TD_4666_input.allocateHost();
    tbl_SerializeFromObject_TD_4666_input.loadHost();
    Table tbl_SerializeFromObject_TD_4666_input_partition("tbl_SerializeFromObject_TD_4666_input_partition", order_n, 1, "");
    tbl_SerializeFromObject_TD_4666_input_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_4666_input_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_4666_input_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_4666_input_partition_array[i] = tbl_SerializeFromObject_TD_4666_input_partition.createSubTable(i);
    }
    Table tbl_Aggregate_TD_5678_output("tbl_Aggregate_TD_5678_output", 183000000, 1, "");
    tbl_Aggregate_TD_5678_output.allocateHost();
    Table tbl_Filter_TD_6160_output("tbl_Filter_TD_6160_output", 183000000, 1, "");
    tbl_Filter_TD_6160_output.allocateHost();
    Table tbl_SerializeFromObject_TD_5811_input;
    tbl_SerializeFromObject_TD_5811_input = Table("customer", customer_n, 3, in_dir);
    tbl_SerializeFromObject_TD_5811_input.addCol("c_custkey", 4);
    tbl_SerializeFromObject_TD_5811_input.addCol("c_phone", TPCH_READ_PHONE_LEN+1);
    tbl_SerializeFromObject_TD_5811_input.addCol("c_acctbal", 4);
    tbl_SerializeFromObject_TD_5811_input.allocateHost();
    tbl_SerializeFromObject_TD_5811_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_LEFTANTI_TD_3178_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_LEFTANTI_TD_3178_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_LEFTANTI_TD_3178_output_partition_array[i] = tbl_JOIN_LEFTANTI_TD_3178_output.createSubTable(i);
    }
    tbl_Filter_TD_4410_output.allocateDevBuffer(context_h, 33);
    tbl_SerializeFromObject_TD_4666_input.allocateDevBuffer(context_h, 33);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_LEFTANTI_TD_3178_cmds;
    cfg_JOIN_LEFTANTI_TD_3178_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTANTI_TD_3178_gqe_join (cfg_JOIN_LEFTANTI_TD_3178_cmds.cmd);
    cfg_JOIN_LEFTANTI_TD_3178_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTANTI_TD_3178_cmds_part;
    cfg_JOIN_LEFTANTI_TD_3178_cmds_part.allocateHost();
    get_cfg_dat_JOIN_LEFTANTI_TD_3178_gqe_join_part (cfg_JOIN_LEFTANTI_TD_3178_cmds_part.cmd);
    cfg_JOIN_LEFTANTI_TD_3178_cmds_part.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_LEFTANTI_TD_3178_part_left;
    krnl_JOIN_LEFTANTI_TD_3178_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_LEFTANTI_TD_3178_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_SerializeFromObject_TD_4666_input, tbl_SerializeFromObject_TD_4666_input_partition, cfg_JOIN_LEFTANTI_TD_3178_cmds_part);
    krnlEngine krnl_JOIN_LEFTANTI_TD_3178_part_right;
    krnl_JOIN_LEFTANTI_TD_3178_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_LEFTANTI_TD_3178_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_Filter_TD_4410_output, tbl_Filter_TD_4410_output_partition, cfg_JOIN_LEFTANTI_TD_3178_cmds_part);
    krnlEngine krnl_JOIN_LEFTANTI_TD_3178[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_LEFTANTI_TD_3178[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_LEFTANTI_TD_3178[i].setup(tbl_SerializeFromObject_TD_4666_input_partition_array[i], tbl_Filter_TD_4410_output_partition_array[i], tbl_JOIN_LEFTANTI_TD_3178_output_partition_array[i], cfg_JOIN_LEFTANTI_TD_3178_cmds, buftmp_h);
    }
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_LEFTANTI_TD_3178;
    trans_JOIN_LEFTANTI_TD_3178.setq(q_h);
    trans_JOIN_LEFTANTI_TD_3178.add(&(cfg_JOIN_LEFTANTI_TD_3178_cmds_part));
    trans_JOIN_LEFTANTI_TD_3178.add(&(cfg_JOIN_LEFTANTI_TD_3178_cmds));
    trans_JOIN_LEFTANTI_TD_3178.add(&(tbl_SerializeFromObject_TD_4666_input));
    transEngine trans_JOIN_LEFTANTI_TD_3178_out;
    trans_JOIN_LEFTANTI_TD_3178_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTANTI_TD_3178;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTANTI_TD_3178;
    std::vector<cl::Event> events_JOIN_LEFTANTI_TD_3178[2];
    events_h2d_wr_JOIN_LEFTANTI_TD_3178.resize(1);
    events_d2h_rd_JOIN_LEFTANTI_TD_3178.resize(1);
    events_JOIN_LEFTANTI_TD_3178[0].resize(2);
    events_JOIN_LEFTANTI_TD_3178[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_LEFTANTI_TD_3178;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTANTI_TD_3178;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_6_207_s, tv_r_Filter_6_207_e;
    gettimeofday(&tv_r_Filter_6_207_s, 0);
    SW_Filter_TD_6160(tbl_SerializeFromObject_TD_5811_input, tbl_Filter_TD_6160_output);
    gettimeofday(&tv_r_Filter_6_207_e, 0);

    struct timeval tv_r_Aggregate_5_911_s, tv_r_Aggregate_5_911_e;
    gettimeofday(&tv_r_Aggregate_5_911_s, 0);
    SW_Aggregate_TD_5678(tbl_Filter_TD_6160_output, tbl_Aggregate_TD_5678_output);
    gettimeofday(&tv_r_Aggregate_5_911_e, 0);

    struct timeval tv_r_Filter_4_836_s, tv_r_Filter_4_836_e;
    gettimeofday(&tv_r_Filter_4_836_s, 0);
    SW_Filter_TD_4410(tbl_SerializeFromObject_TD_5811_input, tbl_Aggregate_TD_5678_output, tbl_Filter_TD_4410_output);
    gettimeofday(&tv_r_Filter_4_836_e, 0);

    struct timeval tv_r_JOIN_LEFTANTI_3_991_s, tv_r_JOIN_LEFTANTI_3_991_e;
    gettimeofday(&tv_r_JOIN_LEFTANTI_3_991_s, 0);
    trans_JOIN_LEFTANTI_TD_3178.add(&(tbl_Filter_TD_4410_output));
    trans_JOIN_LEFTANTI_TD_3178.host2dev(0, &(prev_events_grp_JOIN_LEFTANTI_TD_3178), &(events_h2d_wr_JOIN_LEFTANTI_TD_3178[0]));
    events_grp_JOIN_LEFTANTI_TD_3178.push_back(events_h2d_wr_JOIN_LEFTANTI_TD_3178[0]);
    krnl_JOIN_LEFTANTI_TD_3178_part_left.run(0, &(events_grp_JOIN_LEFTANTI_TD_3178), &(events_JOIN_LEFTANTI_TD_3178[0][0]));
    krnl_JOIN_LEFTANTI_TD_3178_part_right.run(0, &(events_grp_JOIN_LEFTANTI_TD_3178), &(events_JOIN_LEFTANTI_TD_3178[0][1]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_LEFTANTI_TD_3178[i].run(0, &(events_JOIN_LEFTANTI_TD_3178[0]), &(events_JOIN_LEFTANTI_TD_3178[1][i]));
    }
    
    for (int i(0); i < hpTimes_join; ++i) {
        trans_JOIN_LEFTANTI_TD_3178_out.add(&(tbl_JOIN_LEFTANTI_TD_3178_output_partition_array[i]));
    }
    trans_JOIN_LEFTANTI_TD_3178_out.dev2host(0, &(events_JOIN_LEFTANTI_TD_3178[1]), &(events_d2h_rd_JOIN_LEFTANTI_TD_3178[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_LEFTANTI_3_991_e, 0);

    struct timeval tv_r_Project_2_150_s, tv_r_Project_2_150_e;
    gettimeofday(&tv_r_Project_2_150_s, 0);
    SW_Project_TD_2712(tbl_JOIN_LEFTANTI_TD_3178_output_partition_array, tbl_SerializeFromObject_TD_5811_input, tbl_Project_TD_2712_output, hpTimes_join);
    gettimeofday(&tv_r_Project_2_150_e, 0);

    struct timeval tv_r_Aggregate_1_775_s, tv_r_Aggregate_1_775_e;
    gettimeofday(&tv_r_Aggregate_1_775_s, 0);
    SW_Aggregate_TD_1795(tbl_Project_TD_2712_output, tbl_Aggregate_TD_1795_output);
    gettimeofday(&tv_r_Aggregate_1_775_e, 0);

    struct timeval tv_r_Sort_0_56_s, tv_r_Sort_0_56_e;
    gettimeofday(&tv_r_Sort_0_56_s, 0);
    SW_Sort_TD_0764(tbl_Aggregate_TD_1795_output, tbl_Sort_TD_0764_output);
    gettimeofday(&tv_r_Sort_0_56_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_207_s, &tv_r_Filter_6_207_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5811_input: " << tbl_SerializeFromObject_TD_5811_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_911_s, &tv_r_Aggregate_5_911_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6160_output: " << tbl_Filter_TD_6160_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_836_s, &tv_r_Filter_4_836_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5811_input: " << tbl_SerializeFromObject_TD_5811_input.getNumRow() << " " << "tbl_Aggregate_TD_5678_output: " << tbl_Aggregate_TD_5678_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTANTI_3: " << tvdiff(&tv_r_JOIN_LEFTANTI_3_991_s, &tv_r_JOIN_LEFTANTI_3_991_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_4410_output: " << tbl_Filter_TD_4410_output.getNumRow() << " " << "tbl_SerializeFromObject_TD_4666_input: " << tbl_SerializeFromObject_TD_4666_input.getNumRow() << " " << std::endl; 

    std::cout << "Project_2: " << tvdiff(&tv_r_Project_2_150_s, &tv_r_Project_2_150_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTANTI_TD_3178_output: " << tbl_JOIN_LEFTANTI_TD_3178_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_775_s, &tv_r_Aggregate_1_775_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_2712_output: " << tbl_Project_TD_2712_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_56_s, &tv_r_Sort_0_56_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_1795_output: " << tbl_Aggregate_TD_1795_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 125.714775 * 1000 << "ms" << std::endl; 
    return 0; 
}
