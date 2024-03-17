// number of overlays (w/o fusion): 0 
// number of overlays (w/ fusion): 0 
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
#include "tpcds_read.hpp" 
#include "gqe_api.hpp" 

#include "cfgFunc_q96.hpp" 
#include "q96.hpp" 

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
    std::cout << "NOTE:running query #96\n."; 
    std::cout << "NOTE:running in sf" << scale << " data\n"; 

    int32_t customer_n = 	100000; 
    int32_t customer_address_n = 	50000; 
    int32_t customer_demographics_n = 	1920800; 
    int32_t date_dim_n = 	73049; 
    int32_t household_demographics_n = 	7200; 
    int32_t income_band_n = 	20; 
    int32_t item_n = 	18000; 
    int32_t promotion_n = 	300; 
    int32_t reason_n = 	35; 
    int32_t ship_mode_n = 	20; 
    int32_t store_n = 	12; 
    int32_t time_dim_n = 	86400; 
    int32_t warehouse_n = 	5; 
    int32_t web_site_n = 	30; 
    int32_t web_page_n = 	60; 
    int32_t inventory_n = 	11745000; 
    int32_t store_returns_n = 	300000; 
    int32_t web_sales_n = 	719384; 
    int32_t web_returns_n = 	71763; 
    int32_t call_center_n = 	6; 
    int32_t catalog_page_n = 	11718; 
    int32_t catalog_returns_n = 	144067; 
    int32_t catalog_sales_n = 	1441548; 
    int32_t store_sales_n = 	2880404    ; 
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
    // ****************************** Tables **************************** // 
    Table tbl_Aggregate_TD_0415774_output("tbl_Aggregate_TD_0415774_output", 6100000, 1, "");
    tbl_Aggregate_TD_0415774_output.allocateHost();
    Table tbl_JOIN_INNER_TD_1548488_output("tbl_JOIN_INNER_TD_1548488_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_1548488_output.allocateHost();
    Table tbl_JOIN_INNER_TD_2295924_output("tbl_JOIN_INNER_TD_2295924_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_2295924_output.allocateHost();
    Table tbl_Filter_TD_2803653_output("tbl_Filter_TD_2803653_output", 6100000, 1, "");
    tbl_Filter_TD_2803653_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3332627_output("tbl_JOIN_INNER_TD_3332627_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_3332627_output.allocateHost();
    Table tbl_Filter_TD_3444289_output("tbl_Filter_TD_3444289_output", 6100000, 1, "");
    tbl_Filter_TD_3444289_output.allocateHost();
    Table tbl_SerializeFromObject_TD_3483771_input;
    tbl_SerializeFromObject_TD_3483771_input = Table("store", store_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_3483771_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_3483771_input.addCol("s_store_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_3483771_input.allocateHost();
    tbl_SerializeFromObject_TD_3483771_input.loadHost();
    Table tbl_Filter_TD_4899304_output("tbl_Filter_TD_4899304_output", 6100000, 3, "");
    tbl_Filter_TD_4899304_output.allocateHost();
    Table tbl_Filter_TD_4921900_output("tbl_Filter_TD_4921900_output", 6100000, 1, "");
    tbl_Filter_TD_4921900_output.allocateHost();
    Table tbl_SerializeFromObject_TD_4857876_input;
    tbl_SerializeFromObject_TD_4857876_input = Table("time_dim", time_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_4857876_input.addCol("t_time_sk", 4);
    tbl_SerializeFromObject_TD_4857876_input.addCol("t_hour", 4);
    tbl_SerializeFromObject_TD_4857876_input.addCol("t_minute", 4);
    tbl_SerializeFromObject_TD_4857876_input.allocateHost();
    tbl_SerializeFromObject_TD_4857876_input.loadHost();
    Table tbl_SerializeFromObject_TD_5754127_input;
    tbl_SerializeFromObject_TD_5754127_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_5754127_input.addCol("ss_sold_time_sk", 4);
    tbl_SerializeFromObject_TD_5754127_input.addCol("ss_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_5754127_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_5754127_input.allocateHost();
    tbl_SerializeFromObject_TD_5754127_input.loadHost();
    Table tbl_SerializeFromObject_TD_5522672_input;
    tbl_SerializeFromObject_TD_5522672_input = Table("household_demographics", household_demographics_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_5522672_input.addCol("hd_demo_sk", 4);
    tbl_SerializeFromObject_TD_5522672_input.addCol("hd_dep_count", 4);
    tbl_SerializeFromObject_TD_5522672_input.allocateHost();
    tbl_SerializeFromObject_TD_5522672_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_1548488_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_2295924_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_2803653_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_3332627_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_3444289_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_4899304_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_4921900_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_1548488_cmds;
    cfg_JOIN_INNER_TD_1548488_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_1548488_gqe_join (cfg_JOIN_INNER_TD_1548488_cmds.cmd);
    cfg_JOIN_INNER_TD_1548488_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_2295924_cmds;
    cfg_JOIN_INNER_TD_2295924_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_2295924_gqe_join (cfg_JOIN_INNER_TD_2295924_cmds.cmd);
    cfg_JOIN_INNER_TD_2295924_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_3332627_cmds;
    cfg_JOIN_INNER_TD_3332627_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_3332627_gqe_join (cfg_JOIN_INNER_TD_3332627_cmds.cmd);
    cfg_JOIN_INNER_TD_3332627_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_1548488;
    krnl_JOIN_INNER_TD_1548488 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_1548488.setup(tbl_JOIN_INNER_TD_2295924_output, tbl_Filter_TD_2803653_output, tbl_JOIN_INNER_TD_1548488_output, cfg_JOIN_INNER_TD_1548488_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_2295924;
    krnl_JOIN_INNER_TD_2295924 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_2295924.setup(tbl_JOIN_INNER_TD_3332627_output, tbl_Filter_TD_3444289_output, tbl_JOIN_INNER_TD_2295924_output, cfg_JOIN_INNER_TD_2295924_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_3332627;
    krnl_JOIN_INNER_TD_3332627 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_3332627.setup(tbl_Filter_TD_4899304_output, tbl_Filter_TD_4921900_output, tbl_JOIN_INNER_TD_3332627_output, cfg_JOIN_INNER_TD_3332627_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_1548488;
    trans_JOIN_INNER_TD_1548488.setq(q_h);
    trans_JOIN_INNER_TD_1548488.add(&(cfg_JOIN_INNER_TD_1548488_cmds));
    transEngine trans_JOIN_INNER_TD_1548488_out;
    trans_JOIN_INNER_TD_1548488_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_2295924;
    trans_JOIN_INNER_TD_2295924.setq(q_h);
    trans_JOIN_INNER_TD_2295924.add(&(cfg_JOIN_INNER_TD_2295924_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_3332627;
    trans_JOIN_INNER_TD_3332627.setq(q_h);
    trans_JOIN_INNER_TD_3332627.add(&(cfg_JOIN_INNER_TD_3332627_cmds));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_1548488;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_1548488;
    std::vector<cl::Event> events_JOIN_INNER_TD_1548488;
    events_h2d_wr_JOIN_INNER_TD_1548488.resize(1);
    events_d2h_rd_JOIN_INNER_TD_1548488.resize(1);
    events_JOIN_INNER_TD_1548488.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_1548488;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_1548488;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_2295924;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_2295924;
    std::vector<cl::Event> events_JOIN_INNER_TD_2295924;
    events_h2d_wr_JOIN_INNER_TD_2295924.resize(1);
    events_d2h_rd_JOIN_INNER_TD_2295924.resize(1);
    events_JOIN_INNER_TD_2295924.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_2295924;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_2295924;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_3332627;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_3332627;
    std::vector<cl::Event> events_JOIN_INNER_TD_3332627;
    events_h2d_wr_JOIN_INNER_TD_3332627.resize(1);
    events_d2h_rd_JOIN_INNER_TD_3332627.resize(1);
    events_JOIN_INNER_TD_3332627.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_3332627;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_3332627;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_4_345921_s, tv_r_Filter_4_345921_e;
    gettimeofday(&tv_r_Filter_4_345921_s, 0);
    SW_Filter_TD_4921900(tbl_SerializeFromObject_TD_5522672_input, tbl_Filter_TD_4921900_output);
    gettimeofday(&tv_r_Filter_4_345921_e, 0);

    struct timeval tv_r_Filter_4_137367_s, tv_r_Filter_4_137367_e;
    gettimeofday(&tv_r_Filter_4_137367_s, 0);
    SW_Filter_TD_4899304(tbl_SerializeFromObject_TD_5754127_input, tbl_Filter_TD_4899304_output);
    gettimeofday(&tv_r_Filter_4_137367_e, 0);

    struct timeval tv_r_Filter_3_951356_s, tv_r_Filter_3_951356_e;
    gettimeofday(&tv_r_Filter_3_951356_s, 0);
    SW_Filter_TD_3444289(tbl_SerializeFromObject_TD_4857876_input, tbl_Filter_TD_3444289_output);
    gettimeofday(&tv_r_Filter_3_951356_e, 0);

    struct timeval tv_r_JOIN_INNER_3_968097_s, tv_r_JOIN_INNER_3_968097_e;
    gettimeofday(&tv_r_JOIN_INNER_3_968097_s, 0);
    trans_JOIN_INNER_TD_3332627.add(&(tbl_Filter_TD_4899304_output));
    trans_JOIN_INNER_TD_3332627.add(&(tbl_Filter_TD_4921900_output));
    trans_JOIN_INNER_TD_3332627.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_3332627), &(events_h2d_wr_JOIN_INNER_TD_3332627[0]));
    events_grp_JOIN_INNER_TD_3332627.push_back(events_h2d_wr_JOIN_INNER_TD_3332627[0]);
    krnl_JOIN_INNER_TD_3332627.run(0, &(events_grp_JOIN_INNER_TD_3332627), &(events_JOIN_INNER_TD_3332627[0]));
    gettimeofday(&tv_r_JOIN_INNER_3_968097_e, 0);

    struct timeval tv_r_Filter_2_55040_s, tv_r_Filter_2_55040_e;
    gettimeofday(&tv_r_Filter_2_55040_s, 0);
    SW_Filter_TD_2803653(tbl_SerializeFromObject_TD_3483771_input, tbl_Filter_TD_2803653_output);
    gettimeofday(&tv_r_Filter_2_55040_e, 0);

    struct timeval tv_r_JOIN_INNER_2_555369_s, tv_r_JOIN_INNER_2_555369_e;
    gettimeofday(&tv_r_JOIN_INNER_2_555369_s, 0);
    prev_events_grp_JOIN_INNER_TD_2295924.push_back(events_h2d_wr_JOIN_INNER_TD_3332627[0]);
    trans_JOIN_INNER_TD_2295924.add(&(tbl_Filter_TD_3444289_output));
    trans_JOIN_INNER_TD_2295924.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_2295924), &(events_h2d_wr_JOIN_INNER_TD_2295924[0]));
    events_grp_JOIN_INNER_TD_2295924.push_back(events_h2d_wr_JOIN_INNER_TD_2295924[0]);
    events_grp_JOIN_INNER_TD_2295924.push_back(events_JOIN_INNER_TD_3332627[0]);
    krnl_JOIN_INNER_TD_2295924.run(0, &(events_grp_JOIN_INNER_TD_2295924), &(events_JOIN_INNER_TD_2295924[0]));
    gettimeofday(&tv_r_JOIN_INNER_2_555369_e, 0);

    struct timeval tv_r_JOIN_INNER_1_674775_s, tv_r_JOIN_INNER_1_674775_e;
    gettimeofday(&tv_r_JOIN_INNER_1_674775_s, 0);
    prev_events_grp_JOIN_INNER_TD_1548488.push_back(events_h2d_wr_JOIN_INNER_TD_2295924[0]);
    trans_JOIN_INNER_TD_1548488.add(&(tbl_Filter_TD_2803653_output));
    trans_JOIN_INNER_TD_1548488.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_1548488), &(events_h2d_wr_JOIN_INNER_TD_1548488[0]));
    events_grp_JOIN_INNER_TD_1548488.push_back(events_h2d_wr_JOIN_INNER_TD_1548488[0]);
    events_grp_JOIN_INNER_TD_1548488.push_back(events_JOIN_INNER_TD_2295924[0]);
    krnl_JOIN_INNER_TD_1548488.run(0, &(events_grp_JOIN_INNER_TD_1548488), &(events_JOIN_INNER_TD_1548488[0]));
    
    trans_JOIN_INNER_TD_1548488_out.add(&(tbl_JOIN_INNER_TD_1548488_output));
    trans_JOIN_INNER_TD_1548488_out.dev2host(0, &(events_JOIN_INNER_TD_1548488), &(events_d2h_rd_JOIN_INNER_TD_1548488[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_1_674775_e, 0);

    struct timeval tv_r_Aggregate_0_414807_s, tv_r_Aggregate_0_414807_e;
    gettimeofday(&tv_r_Aggregate_0_414807_s, 0);
    SW_Aggregate_TD_0415774(tbl_JOIN_INNER_TD_1548488_output, tbl_Aggregate_TD_0415774_output);
    gettimeofday(&tv_r_Aggregate_0_414807_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_345921_s, &tv_r_Filter_4_345921_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5522672_input: " << tbl_SerializeFromObject_TD_5522672_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_137367_s, &tv_r_Filter_4_137367_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5754127_input: " << tbl_SerializeFromObject_TD_5754127_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_951356_s, &tv_r_Filter_3_951356_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_4857876_input: " << tbl_SerializeFromObject_TD_4857876_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_968097_s, &tv_r_JOIN_INNER_3_968097_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_4899304_output: " << tbl_Filter_TD_4899304_output.getNumRow() << " " << "tbl_Filter_TD_4921900_output: " << tbl_Filter_TD_4921900_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_55040_s, &tv_r_Filter_2_55040_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3483771_input: " << tbl_SerializeFromObject_TD_3483771_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_2: " << tvdiff(&tv_r_JOIN_INNER_2_555369_s, &tv_r_JOIN_INNER_2_555369_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3332627_output: " << tbl_JOIN_INNER_TD_3332627_output.getNumRow() << " " << "tbl_Filter_TD_3444289_output: " << tbl_Filter_TD_3444289_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_1: " << tvdiff(&tv_r_JOIN_INNER_1_674775_s, &tv_r_JOIN_INNER_1_674775_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_2295924_output: " << tbl_JOIN_INNER_TD_2295924_output.getNumRow() << " " << "tbl_Filter_TD_2803653_output: " << tbl_Filter_TD_2803653_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_0: " << tvdiff(&tv_r_Aggregate_0_414807_s, &tv_r_Aggregate_0_414807_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_1548488_output: " << tbl_JOIN_INNER_TD_1548488_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 0.7009557 * 1000 << "ms" << std::endl; 
    return 0; 
}
