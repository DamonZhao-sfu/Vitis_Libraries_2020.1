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

#include "cfgFunc_q86.hpp" 
#include "q86.hpp" 

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
    std::cout << "NOTE:running query #86\n."; 
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
    Table tbl_GlobalLimit_TD_0847510_output("tbl_GlobalLimit_TD_0847510_output", 6100000, 5, "");
    tbl_GlobalLimit_TD_0847510_output.allocateHost();
    Table tbl_LocalLimit_TD_1613268_output("tbl_LocalLimit_TD_1613268_output", 6100000, 5, "");
    tbl_LocalLimit_TD_1613268_output.allocateHost();
    Table tbl_Sort_TD_2561917_output("tbl_Sort_TD_2561917_output", 6100000, 5, "");
    tbl_Sort_TD_2561917_output.allocateHost();
    Table tbl_Window_TD_3229898_output("tbl_Window_TD_3229898_output", 6100000, 8, "");
    tbl_Window_TD_3229898_output.allocateHost();
    Table tbl_Aggregate_TD_4765968_output("tbl_Aggregate_TD_4765968_output", 6100000, 7, "");
    tbl_Aggregate_TD_4765968_output.allocateHost();
    Table tbl_Expand_TD_5234627_output("tbl_Expand_TD_5234627_output", 6100000, 4, "");
    tbl_Expand_TD_5234627_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6755077_output("tbl_JOIN_INNER_TD_6755077_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_6755077_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7959031_output("tbl_JOIN_INNER_TD_7959031_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_7959031_output.allocateHost();
    Table tbl_Filter_TD_7847500_output("tbl_Filter_TD_7847500_output", 6100000, 3, "");
    tbl_Filter_TD_7847500_output.allocateHost();
    Table tbl_Filter_TD_8251406_output("tbl_Filter_TD_8251406_output", 6100000, 3, "");
    tbl_Filter_TD_8251406_output.allocateHost();
    Table tbl_Filter_TD_8265674_output("tbl_Filter_TD_8265674_output", 6100000, 1, "");
    tbl_Filter_TD_8265674_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8301945_input;
    tbl_SerializeFromObject_TD_8301945_input = Table("item", item_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8301945_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_8301945_input.addCol("i_class", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8301945_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8301945_input.allocateHost();
    tbl_SerializeFromObject_TD_8301945_input.loadHost();
    Table tbl_SerializeFromObject_TD_9429991_input;
    tbl_SerializeFromObject_TD_9429991_input = Table("web_sales", web_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9429991_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_9429991_input.addCol("ws_item_sk", 4);
    tbl_SerializeFromObject_TD_9429991_input.addCol("ws_net_paid", 4);
    tbl_SerializeFromObject_TD_9429991_input.allocateHost();
    tbl_SerializeFromObject_TD_9429991_input.loadHost();
    Table tbl_SerializeFromObject_TD_962216_input;
    tbl_SerializeFromObject_TD_962216_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_962216_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_962216_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_962216_input.allocateHost();
    tbl_SerializeFromObject_TD_962216_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_7959031_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8251406_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8265674_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_7959031_cmds;
    cfg_JOIN_INNER_TD_7959031_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7959031_gqe_join (cfg_JOIN_INNER_TD_7959031_cmds.cmd);
    cfg_JOIN_INNER_TD_7959031_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_7959031;
    krnl_JOIN_INNER_TD_7959031 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7959031.setup(tbl_Filter_TD_8251406_output, tbl_Filter_TD_8265674_output, tbl_JOIN_INNER_TD_7959031_output, cfg_JOIN_INNER_TD_7959031_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_7959031;
    trans_JOIN_INNER_TD_7959031.setq(q_h);
    trans_JOIN_INNER_TD_7959031.add(&(cfg_JOIN_INNER_TD_7959031_cmds));
    transEngine trans_JOIN_INNER_TD_7959031_out;
    trans_JOIN_INNER_TD_7959031_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7959031;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7959031;
    std::vector<cl::Event> events_JOIN_INNER_TD_7959031;
    events_h2d_wr_JOIN_INNER_TD_7959031.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7959031.resize(1);
    events_JOIN_INNER_TD_7959031.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7959031;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7959031;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_8_338989_s, tv_r_Filter_8_338989_e;
    gettimeofday(&tv_r_Filter_8_338989_s, 0);
    SW_Filter_TD_8265674(tbl_SerializeFromObject_TD_962216_input, tbl_Filter_TD_8265674_output);
    gettimeofday(&tv_r_Filter_8_338989_e, 0);

    struct timeval tv_r_Filter_8_92224_s, tv_r_Filter_8_92224_e;
    gettimeofday(&tv_r_Filter_8_92224_s, 0);
    SW_Filter_TD_8251406(tbl_SerializeFromObject_TD_9429991_input, tbl_Filter_TD_8251406_output);
    gettimeofday(&tv_r_Filter_8_92224_e, 0);

    struct timeval tv_r_Filter_7_984733_s, tv_r_Filter_7_984733_e;
    gettimeofday(&tv_r_Filter_7_984733_s, 0);
    SW_Filter_TD_7847500(tbl_SerializeFromObject_TD_8301945_input, tbl_Filter_TD_7847500_output);
    gettimeofday(&tv_r_Filter_7_984733_e, 0);

    struct timeval tv_r_JOIN_INNER_7_664998_s, tv_r_JOIN_INNER_7_664998_e;
    gettimeofday(&tv_r_JOIN_INNER_7_664998_s, 0);
    trans_JOIN_INNER_TD_7959031.add(&(tbl_Filter_TD_8251406_output));
    trans_JOIN_INNER_TD_7959031.add(&(tbl_Filter_TD_8265674_output));
    trans_JOIN_INNER_TD_7959031.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7959031), &(events_h2d_wr_JOIN_INNER_TD_7959031[0]));
    events_grp_JOIN_INNER_TD_7959031.push_back(events_h2d_wr_JOIN_INNER_TD_7959031[0]);
    krnl_JOIN_INNER_TD_7959031.run(0, &(events_grp_JOIN_INNER_TD_7959031), &(events_JOIN_INNER_TD_7959031[0]));
    
    trans_JOIN_INNER_TD_7959031_out.add(&(tbl_JOIN_INNER_TD_7959031_output));
    trans_JOIN_INNER_TD_7959031_out.dev2host(0, &(events_JOIN_INNER_TD_7959031), &(events_d2h_rd_JOIN_INNER_TD_7959031[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_7_664998_e, 0);

    struct timeval tv_r_JOIN_INNER_6_898958_s, tv_r_JOIN_INNER_6_898958_e;
    gettimeofday(&tv_r_JOIN_INNER_6_898958_s, 0);
    SW_JOIN_INNER_TD_6755077(tbl_JOIN_INNER_TD_7959031_output, tbl_Filter_TD_7847500_output, tbl_JOIN_INNER_TD_6755077_output);
    gettimeofday(&tv_r_JOIN_INNER_6_898958_e, 0);

    struct timeval tv_r_Expand_5_972444_s, tv_r_Expand_5_972444_e;
    gettimeofday(&tv_r_Expand_5_972444_s, 0);
    SW_Expand_TD_5234627(tbl_JOIN_INNER_TD_6755077_output, tbl_Expand_TD_5234627_output);
    gettimeofday(&tv_r_Expand_5_972444_e, 0);

    struct timeval tv_r_Aggregate_4_454605_s, tv_r_Aggregate_4_454605_e;
    gettimeofday(&tv_r_Aggregate_4_454605_s, 0);
    SW_Aggregate_TD_4765968(tbl_Expand_TD_5234627_output, tbl_Aggregate_TD_4765968_output);
    gettimeofday(&tv_r_Aggregate_4_454605_e, 0);

    struct timeval tv_r_Window_3_236709_s, tv_r_Window_3_236709_e;
    gettimeofday(&tv_r_Window_3_236709_s, 0);
    SW_Window_TD_3229898(tbl_Aggregate_TD_4765968_output, tbl_Window_TD_3229898_output);
    gettimeofday(&tv_r_Window_3_236709_e, 0);

    struct timeval tv_r_Sort_2_738007_s, tv_r_Sort_2_738007_e;
    gettimeofday(&tv_r_Sort_2_738007_s, 0);
    SW_Sort_TD_2561917(tbl_Window_TD_3229898_output, tbl_Sort_TD_2561917_output);
    gettimeofday(&tv_r_Sort_2_738007_e, 0);

    struct timeval tv_r_LocalLimit_1_815510_s, tv_r_LocalLimit_1_815510_e;
    gettimeofday(&tv_r_LocalLimit_1_815510_s, 0);
    SW_LocalLimit_TD_1613268(tbl_Sort_TD_2561917_output, tbl_LocalLimit_TD_1613268_output);
    gettimeofday(&tv_r_LocalLimit_1_815510_e, 0);

    struct timeval tv_r_GlobalLimit_0_618500_s, tv_r_GlobalLimit_0_618500_e;
    gettimeofday(&tv_r_GlobalLimit_0_618500_s, 0);
    SW_GlobalLimit_TD_0847510(tbl_LocalLimit_TD_1613268_output, tbl_GlobalLimit_TD_0847510_output);
    gettimeofday(&tv_r_GlobalLimit_0_618500_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_338989_s, &tv_r_Filter_8_338989_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_962216_input: " << tbl_SerializeFromObject_TD_962216_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_92224_s, &tv_r_Filter_8_92224_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9429991_input: " << tbl_SerializeFromObject_TD_9429991_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_984733_s, &tv_r_Filter_7_984733_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8301945_input: " << tbl_SerializeFromObject_TD_8301945_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_664998_s, &tv_r_JOIN_INNER_7_664998_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8251406_output: " << tbl_Filter_TD_8251406_output.getNumRow() << " " << "tbl_Filter_TD_8265674_output: " << tbl_Filter_TD_8265674_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_898958_s, &tv_r_JOIN_INNER_6_898958_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7959031_output: " << tbl_JOIN_INNER_TD_7959031_output.getNumRow() << " " << "tbl_Filter_TD_7847500_output: " << tbl_Filter_TD_7847500_output.getNumRow() << " " << std::endl; 

    std::cout << "Expand_5: " << tvdiff(&tv_r_Expand_5_972444_s, &tv_r_Expand_5_972444_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6755077_output: " << tbl_JOIN_INNER_TD_6755077_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_4: " << tvdiff(&tv_r_Aggregate_4_454605_s, &tv_r_Aggregate_4_454605_e) / 1000.0 << " ms " 
     << "tbl_Expand_TD_5234627_output: " << tbl_Expand_TD_5234627_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_3: " << tvdiff(&tv_r_Window_3_236709_s, &tv_r_Window_3_236709_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_4765968_output: " << tbl_Aggregate_TD_4765968_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_738007_s, &tv_r_Sort_2_738007_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_3229898_output: " << tbl_Window_TD_3229898_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_815510_s, &tv_r_LocalLimit_1_815510_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2561917_output: " << tbl_Sort_TD_2561917_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_618500_s, &tv_r_GlobalLimit_0_618500_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1613268_output: " << tbl_LocalLimit_TD_1613268_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.2433478 * 1000 << "ms" << std::endl; 
    return 0; 
}
