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

#include "cfgFunc_q45.hpp" 
#include "q45.hpp" 

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
    std::cout << "NOTE:running query #45\n."; 
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
    Table tbl_GlobalLimit_TD_0622700_output("tbl_GlobalLimit_TD_0622700_output", 6100000, 3, "");
    tbl_GlobalLimit_TD_0622700_output.allocateHost();
    Table tbl_LocalLimit_TD_1210851_output("tbl_LocalLimit_TD_1210851_output", 6100000, 3, "");
    tbl_LocalLimit_TD_1210851_output.allocateHost();
    Table tbl_Sort_TD_2655674_output("tbl_Sort_TD_2655674_output", 6100000, 3, "");
    tbl_Sort_TD_2655674_output.allocateHost();
    Table tbl_Aggregate_TD_3887165_output("tbl_Aggregate_TD_3887165_output", 6100000, 3, "");
    tbl_Aggregate_TD_3887165_output.allocateHost();
    Table tbl_Filter_TD_4910441_output("tbl_Filter_TD_4910441_output", 6100000, 3, "");
    tbl_Filter_TD_4910441_output.allocateHost();
    Table tbl_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_output("tbl_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_output", 6100000, 4, "");
    tbl_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6781537_output("tbl_JOIN_INNER_TD_6781537_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_6781537_output.allocateHost();
    Table tbl_Filter_TD_69059_output("tbl_Filter_TD_69059_output", 6100000, 1, "");
    tbl_Filter_TD_69059_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7695168_output("tbl_JOIN_INNER_TD_7695168_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_7695168_output.allocateHost();
    Table tbl_Filter_TD_7573511_output("tbl_Filter_TD_7573511_output", 6100000, 2, "");
    tbl_Filter_TD_7573511_output.allocateHost();
    Table tbl_SerializeFromObject_TD_730314_input;
    tbl_SerializeFromObject_TD_730314_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_730314_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_730314_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_730314_input.allocateHost();
    tbl_SerializeFromObject_TD_730314_input.loadHost();
    Table tbl_JOIN_INNER_TD_8551704_output("tbl_JOIN_INNER_TD_8551704_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_8551704_output.allocateHost();
    Table tbl_Filter_TD_8388173_output("tbl_Filter_TD_8388173_output", 6100000, 1, "");
    tbl_Filter_TD_8388173_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8996797_input;
    tbl_SerializeFromObject_TD_8996797_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8996797_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_8996797_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8996797_input.allocateHost();
    tbl_SerializeFromObject_TD_8996797_input.loadHost();
    Table tbl_JOIN_INNER_TD_9659581_output("tbl_JOIN_INNER_TD_9659581_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_9659581_output.allocateHost();
    Table tbl_Filter_TD_9681038_output("tbl_Filter_TD_9681038_output", 6100000, 3, "");
    tbl_Filter_TD_9681038_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9501720_input;
    tbl_SerializeFromObject_TD_9501720_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9501720_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_9501720_input.addCol("d_qoy", 4);
    tbl_SerializeFromObject_TD_9501720_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_9501720_input.allocateHost();
    tbl_SerializeFromObject_TD_9501720_input.loadHost();
    Table tbl_Filter_TD_10495730_output("tbl_Filter_TD_10495730_output", 6100000, 4, "");
    tbl_Filter_TD_10495730_output.allocateHost();
    Table tbl_Filter_TD_10556224_output("tbl_Filter_TD_10556224_output", 6100000, 2, "");
    tbl_Filter_TD_10556224_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10258774_input;
    tbl_SerializeFromObject_TD_10258774_input = Table("customer_address", customer_address_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10258774_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_10258774_input.addCol("ca_city", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10258774_input.addCol("ca_zip", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10258774_input.allocateHost();
    tbl_SerializeFromObject_TD_10258774_input.loadHost();
    Table tbl_SerializeFromObject_TD_11463406_input;
    tbl_SerializeFromObject_TD_11463406_input = Table("web_sales", web_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_11463406_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_11463406_input.addCol("ws_item_sk", 4);
    tbl_SerializeFromObject_TD_11463406_input.addCol("ws_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_11463406_input.addCol("ws_sales_price", 4);
    tbl_SerializeFromObject_TD_11463406_input.allocateHost();
    tbl_SerializeFromObject_TD_11463406_input.loadHost();
    Table tbl_SerializeFromObject_TD_11394399_input;
    tbl_SerializeFromObject_TD_11394399_input = Table("customer", customer_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11394399_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_11394399_input.addCol("c_current_addr_sk", 4);
    tbl_SerializeFromObject_TD_11394399_input.allocateHost();
    tbl_SerializeFromObject_TD_11394399_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_9659581_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10495730_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10556224_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_9659581_cmds;
    cfg_JOIN_INNER_TD_9659581_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_9659581_gqe_join (cfg_JOIN_INNER_TD_9659581_cmds.cmd);
    cfg_JOIN_INNER_TD_9659581_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_9659581;
    krnl_JOIN_INNER_TD_9659581 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_9659581.setup(tbl_Filter_TD_10495730_output, tbl_Filter_TD_10556224_output, tbl_JOIN_INNER_TD_9659581_output, cfg_JOIN_INNER_TD_9659581_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_9659581;
    trans_JOIN_INNER_TD_9659581.setq(q_h);
    trans_JOIN_INNER_TD_9659581.add(&(cfg_JOIN_INNER_TD_9659581_cmds));
    transEngine trans_JOIN_INNER_TD_9659581_out;
    trans_JOIN_INNER_TD_9659581_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_9659581;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_9659581;
    std::vector<cl::Event> events_JOIN_INNER_TD_9659581;
    events_h2d_wr_JOIN_INNER_TD_9659581.resize(1);
    events_d2h_rd_JOIN_INNER_TD_9659581.resize(1);
    events_JOIN_INNER_TD_9659581.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_9659581;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_9659581;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_10_77803_s, tv_r_Filter_10_77803_e;
    gettimeofday(&tv_r_Filter_10_77803_s, 0);
    SW_Filter_TD_10556224(tbl_SerializeFromObject_TD_11394399_input, tbl_Filter_TD_10556224_output);
    gettimeofday(&tv_r_Filter_10_77803_e, 0);

    struct timeval tv_r_Filter_10_963234_s, tv_r_Filter_10_963234_e;
    gettimeofday(&tv_r_Filter_10_963234_s, 0);
    SW_Filter_TD_10495730(tbl_SerializeFromObject_TD_11463406_input, tbl_Filter_TD_10495730_output);
    gettimeofday(&tv_r_Filter_10_963234_e, 0);

    struct timeval tv_r_Filter_9_416716_s, tv_r_Filter_9_416716_e;
    gettimeofday(&tv_r_Filter_9_416716_s, 0);
    SW_Filter_TD_9681038(tbl_SerializeFromObject_TD_10258774_input, tbl_Filter_TD_9681038_output);
    gettimeofday(&tv_r_Filter_9_416716_e, 0);

    struct timeval tv_r_JOIN_INNER_9_350381_s, tv_r_JOIN_INNER_9_350381_e;
    gettimeofday(&tv_r_JOIN_INNER_9_350381_s, 0);
    trans_JOIN_INNER_TD_9659581.add(&(tbl_Filter_TD_10495730_output));
    trans_JOIN_INNER_TD_9659581.add(&(tbl_Filter_TD_10556224_output));
    trans_JOIN_INNER_TD_9659581.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_9659581), &(events_h2d_wr_JOIN_INNER_TD_9659581[0]));
    events_grp_JOIN_INNER_TD_9659581.push_back(events_h2d_wr_JOIN_INNER_TD_9659581[0]);
    krnl_JOIN_INNER_TD_9659581.run(0, &(events_grp_JOIN_INNER_TD_9659581), &(events_JOIN_INNER_TD_9659581[0]));
    
    trans_JOIN_INNER_TD_9659581_out.add(&(tbl_JOIN_INNER_TD_9659581_output));
    trans_JOIN_INNER_TD_9659581_out.dev2host(0, &(events_JOIN_INNER_TD_9659581), &(events_d2h_rd_JOIN_INNER_TD_9659581[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_9_350381_e, 0);

    struct timeval tv_r_Filter_8_243325_s, tv_r_Filter_8_243325_e;
    gettimeofday(&tv_r_Filter_8_243325_s, 0);
    SW_Filter_TD_8388173(tbl_SerializeFromObject_TD_9501720_input, tbl_Filter_TD_8388173_output);
    gettimeofday(&tv_r_Filter_8_243325_e, 0);

    struct timeval tv_r_JOIN_INNER_8_79137_s, tv_r_JOIN_INNER_8_79137_e;
    gettimeofday(&tv_r_JOIN_INNER_8_79137_s, 0);
    SW_JOIN_INNER_TD_8551704(tbl_JOIN_INNER_TD_9659581_output, tbl_Filter_TD_9681038_output, tbl_JOIN_INNER_TD_8551704_output);
    gettimeofday(&tv_r_JOIN_INNER_8_79137_e, 0);

    struct timeval tv_r_Filter_7_601413_s, tv_r_Filter_7_601413_e;
    gettimeofday(&tv_r_Filter_7_601413_s, 0);
    SW_Filter_TD_7573511(tbl_SerializeFromObject_TD_8996797_input, tbl_Filter_TD_7573511_output);
    gettimeofday(&tv_r_Filter_7_601413_e, 0);

    struct timeval tv_r_JOIN_INNER_7_383872_s, tv_r_JOIN_INNER_7_383872_e;
    gettimeofday(&tv_r_JOIN_INNER_7_383872_s, 0);
    SW_JOIN_INNER_TD_7695168(tbl_JOIN_INNER_TD_8551704_output, tbl_Filter_TD_8388173_output, tbl_JOIN_INNER_TD_7695168_output);
    gettimeofday(&tv_r_JOIN_INNER_7_383872_e, 0);

    struct timeval tv_r_Filter_6_997086_s, tv_r_Filter_6_997086_e;
    gettimeofday(&tv_r_Filter_6_997086_s, 0);
    SW_Filter_TD_69059(tbl_SerializeFromObject_TD_730314_input, tbl_Filter_TD_69059_output);
    gettimeofday(&tv_r_Filter_6_997086_e, 0);

    struct timeval tv_r_JOIN_INNER_6_896237_s, tv_r_JOIN_INNER_6_896237_e;
    gettimeofday(&tv_r_JOIN_INNER_6_896237_s, 0);
    SW_JOIN_INNER_TD_6781537(tbl_JOIN_INNER_TD_7695168_output, tbl_Filter_TD_7573511_output, tbl_JOIN_INNER_TD_6781537_output);
    gettimeofday(&tv_r_JOIN_INNER_6_896237_e, 0);

    struct timeval tv_r_JOIN_EXISTENCEJOINEXISTS3600_5_181150_s, tv_r_JOIN_EXISTENCEJOINEXISTS3600_5_181150_e;
    gettimeofday(&tv_r_JOIN_EXISTENCEJOINEXISTS3600_5_181150_s, 0);
    SW_JOIN_EXISTENCEJOINEXISTS3600_TD_587761(tbl_JOIN_INNER_TD_6781537_output, tbl_Filter_TD_69059_output, tbl_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_output);
    gettimeofday(&tv_r_JOIN_EXISTENCEJOINEXISTS3600_5_181150_e, 0);

    struct timeval tv_r_Filter_4_262217_s, tv_r_Filter_4_262217_e;
    gettimeofday(&tv_r_Filter_4_262217_s, 0);
    SW_Filter_TD_4910441(tbl_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_output, tbl_Filter_TD_4910441_output);
    gettimeofday(&tv_r_Filter_4_262217_e, 0);

    struct timeval tv_r_Aggregate_3_274678_s, tv_r_Aggregate_3_274678_e;
    gettimeofday(&tv_r_Aggregate_3_274678_s, 0);
    SW_Aggregate_TD_3887165(tbl_Filter_TD_4910441_output, tbl_Aggregate_TD_3887165_output);
    gettimeofday(&tv_r_Aggregate_3_274678_e, 0);

    struct timeval tv_r_Sort_2_754304_s, tv_r_Sort_2_754304_e;
    gettimeofday(&tv_r_Sort_2_754304_s, 0);
    SW_Sort_TD_2655674(tbl_Aggregate_TD_3887165_output, tbl_Sort_TD_2655674_output);
    gettimeofday(&tv_r_Sort_2_754304_e, 0);

    struct timeval tv_r_LocalLimit_1_258044_s, tv_r_LocalLimit_1_258044_e;
    gettimeofday(&tv_r_LocalLimit_1_258044_s, 0);
    SW_LocalLimit_TD_1210851(tbl_Sort_TD_2655674_output, tbl_LocalLimit_TD_1210851_output);
    gettimeofday(&tv_r_LocalLimit_1_258044_e, 0);

    struct timeval tv_r_GlobalLimit_0_113189_s, tv_r_GlobalLimit_0_113189_e;
    gettimeofday(&tv_r_GlobalLimit_0_113189_s, 0);
    SW_GlobalLimit_TD_0622700(tbl_LocalLimit_TD_1210851_output, tbl_GlobalLimit_TD_0622700_output);
    gettimeofday(&tv_r_GlobalLimit_0_113189_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_77803_s, &tv_r_Filter_10_77803_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11394399_input: " << tbl_SerializeFromObject_TD_11394399_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_963234_s, &tv_r_Filter_10_963234_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11463406_input: " << tbl_SerializeFromObject_TD_11463406_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_416716_s, &tv_r_Filter_9_416716_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10258774_input: " << tbl_SerializeFromObject_TD_10258774_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_350381_s, &tv_r_JOIN_INNER_9_350381_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10495730_output: " << tbl_Filter_TD_10495730_output.getNumRow() << " " << "tbl_Filter_TD_10556224_output: " << tbl_Filter_TD_10556224_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_243325_s, &tv_r_Filter_8_243325_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9501720_input: " << tbl_SerializeFromObject_TD_9501720_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_79137_s, &tv_r_JOIN_INNER_8_79137_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9659581_output: " << tbl_JOIN_INNER_TD_9659581_output.getNumRow() << " " << "tbl_Filter_TD_9681038_output: " << tbl_Filter_TD_9681038_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_601413_s, &tv_r_Filter_7_601413_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8996797_input: " << tbl_SerializeFromObject_TD_8996797_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_383872_s, &tv_r_JOIN_INNER_7_383872_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8551704_output: " << tbl_JOIN_INNER_TD_8551704_output.getNumRow() << " " << "tbl_Filter_TD_8388173_output: " << tbl_Filter_TD_8388173_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_997086_s, &tv_r_Filter_6_997086_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_730314_input: " << tbl_SerializeFromObject_TD_730314_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_896237_s, &tv_r_JOIN_INNER_6_896237_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7695168_output: " << tbl_JOIN_INNER_TD_7695168_output.getNumRow() << " " << "tbl_Filter_TD_7573511_output: " << tbl_Filter_TD_7573511_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_EXISTENCEJOINEXISTS3600_5: " << tvdiff(&tv_r_JOIN_EXISTENCEJOINEXISTS3600_5_181150_s, &tv_r_JOIN_EXISTENCEJOINEXISTS3600_5_181150_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6781537_output: " << tbl_JOIN_INNER_TD_6781537_output.getNumRow() << " " << "tbl_Filter_TD_69059_output: " << tbl_Filter_TD_69059_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_262217_s, &tv_r_Filter_4_262217_e) / 1000.0 << " ms " 
     << "tbl_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_output: " << tbl_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_274678_s, &tv_r_Aggregate_3_274678_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_4910441_output: " << tbl_Filter_TD_4910441_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_754304_s, &tv_r_Sort_2_754304_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3887165_output: " << tbl_Aggregate_TD_3887165_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_258044_s, &tv_r_LocalLimit_1_258044_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2655674_output: " << tbl_Sort_TD_2655674_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_113189_s, &tv_r_GlobalLimit_0_113189_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1210851_output: " << tbl_LocalLimit_TD_1210851_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.191385 * 1000 << "ms" << std::endl; 
    return 0; 
}
