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

#include "cfgFunc_q36.hpp" 
#include "q36.hpp" 

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
    std::cout << "NOTE:running query #36\n."; 
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
    Table tbl_GlobalLimit_TD_0739015_output("tbl_GlobalLimit_TD_0739015_output", 6100000, 5, "");
    tbl_GlobalLimit_TD_0739015_output.allocateHost();
    Table tbl_LocalLimit_TD_147152_output("tbl_LocalLimit_TD_147152_output", 6100000, 5, "");
    tbl_LocalLimit_TD_147152_output.allocateHost();
    Table tbl_Sort_TD_294355_output("tbl_Sort_TD_294355_output", 6100000, 5, "");
    tbl_Sort_TD_294355_output.allocateHost();
    Table tbl_Window_TD_3768571_output("tbl_Window_TD_3768571_output", 6100000, 8, "");
    tbl_Window_TD_3768571_output.allocateHost();
    Table tbl_Aggregate_TD_4374802_output("tbl_Aggregate_TD_4374802_output", 6100000, 7, "");
    tbl_Aggregate_TD_4374802_output.allocateHost();
    Table tbl_Expand_TD_5642293_output("tbl_Expand_TD_5642293_output", 6100000, 5, "");
    tbl_Expand_TD_5642293_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6960671_output("tbl_JOIN_INNER_TD_6960671_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_6960671_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7367178_output("tbl_JOIN_INNER_TD_7367178_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_7367178_output.allocateHost();
    Table tbl_Filter_TD_7998377_output("tbl_Filter_TD_7998377_output", 6100000, 1, "");
    tbl_Filter_TD_7998377_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8999891_output("tbl_JOIN_INNER_TD_8999891_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_8999891_output.allocateHost();
    Table tbl_Filter_TD_8555915_output("tbl_Filter_TD_8555915_output", 6100000, 3, "");
    tbl_Filter_TD_8555915_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8119232_input;
    tbl_SerializeFromObject_TD_8119232_input = Table("store", store_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8119232_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_8119232_input.addCol("s_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8119232_input.allocateHost();
    tbl_SerializeFromObject_TD_8119232_input.loadHost();
    Table tbl_Filter_TD_9291015_output("tbl_Filter_TD_9291015_output", 6100000, 5, "");
    tbl_Filter_TD_9291015_output.allocateHost();
    Table tbl_Filter_TD_9591377_output("tbl_Filter_TD_9591377_output", 6100000, 1, "");
    tbl_Filter_TD_9591377_output.allocateHost();
    Table tbl_SerializeFromObject_TD_996716_input;
    tbl_SerializeFromObject_TD_996716_input = Table("item", item_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_996716_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_996716_input.addCol("i_class", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_996716_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_996716_input.allocateHost();
    tbl_SerializeFromObject_TD_996716_input.loadHost();
    Table tbl_SerializeFromObject_TD_10367580_input;
    tbl_SerializeFromObject_TD_10367580_input = Table("store_sales", store_sales_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_10367580_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10367580_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_10367580_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_10367580_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_10367580_input.addCol("ss_net_profit", 4);
    tbl_SerializeFromObject_TD_10367580_input.allocateHost();
    tbl_SerializeFromObject_TD_10367580_input.loadHost();
    Table tbl_SerializeFromObject_TD_10562796_input;
    tbl_SerializeFromObject_TD_10562796_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10562796_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10562796_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10562796_input.allocateHost();
    tbl_SerializeFromObject_TD_10562796_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_8999891_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9291015_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9591377_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_8999891_cmds;
    cfg_JOIN_INNER_TD_8999891_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8999891_gqe_join (cfg_JOIN_INNER_TD_8999891_cmds.cmd);
    cfg_JOIN_INNER_TD_8999891_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_8999891;
    krnl_JOIN_INNER_TD_8999891 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8999891.setup(tbl_Filter_TD_9291015_output, tbl_Filter_TD_9591377_output, tbl_JOIN_INNER_TD_8999891_output, cfg_JOIN_INNER_TD_8999891_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_8999891;
    trans_JOIN_INNER_TD_8999891.setq(q_h);
    trans_JOIN_INNER_TD_8999891.add(&(cfg_JOIN_INNER_TD_8999891_cmds));
    transEngine trans_JOIN_INNER_TD_8999891_out;
    trans_JOIN_INNER_TD_8999891_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8999891;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8999891;
    std::vector<cl::Event> events_JOIN_INNER_TD_8999891;
    events_h2d_wr_JOIN_INNER_TD_8999891.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8999891.resize(1);
    events_JOIN_INNER_TD_8999891.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8999891;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8999891;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_9_552060_s, tv_r_Filter_9_552060_e;
    gettimeofday(&tv_r_Filter_9_552060_s, 0);
    SW_Filter_TD_9591377(tbl_SerializeFromObject_TD_10562796_input, tbl_Filter_TD_9591377_output);
    gettimeofday(&tv_r_Filter_9_552060_e, 0);

    struct timeval tv_r_Filter_9_236972_s, tv_r_Filter_9_236972_e;
    gettimeofday(&tv_r_Filter_9_236972_s, 0);
    SW_Filter_TD_9291015(tbl_SerializeFromObject_TD_10367580_input, tbl_Filter_TD_9291015_output);
    gettimeofday(&tv_r_Filter_9_236972_e, 0);

    struct timeval tv_r_Filter_8_209402_s, tv_r_Filter_8_209402_e;
    gettimeofday(&tv_r_Filter_8_209402_s, 0);
    SW_Filter_TD_8555915(tbl_SerializeFromObject_TD_996716_input, tbl_Filter_TD_8555915_output);
    gettimeofday(&tv_r_Filter_8_209402_e, 0);

    struct timeval tv_r_JOIN_INNER_8_23698_s, tv_r_JOIN_INNER_8_23698_e;
    gettimeofday(&tv_r_JOIN_INNER_8_23698_s, 0);
    trans_JOIN_INNER_TD_8999891.add(&(tbl_Filter_TD_9291015_output));
    trans_JOIN_INNER_TD_8999891.add(&(tbl_Filter_TD_9591377_output));
    trans_JOIN_INNER_TD_8999891.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8999891), &(events_h2d_wr_JOIN_INNER_TD_8999891[0]));
    events_grp_JOIN_INNER_TD_8999891.push_back(events_h2d_wr_JOIN_INNER_TD_8999891[0]);
    krnl_JOIN_INNER_TD_8999891.run(0, &(events_grp_JOIN_INNER_TD_8999891), &(events_JOIN_INNER_TD_8999891[0]));
    
    trans_JOIN_INNER_TD_8999891_out.add(&(tbl_JOIN_INNER_TD_8999891_output));
    trans_JOIN_INNER_TD_8999891_out.dev2host(0, &(events_JOIN_INNER_TD_8999891), &(events_d2h_rd_JOIN_INNER_TD_8999891[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_8_23698_e, 0);

    struct timeval tv_r_Filter_7_466240_s, tv_r_Filter_7_466240_e;
    gettimeofday(&tv_r_Filter_7_466240_s, 0);
    SW_Filter_TD_7998377(tbl_SerializeFromObject_TD_8119232_input, tbl_Filter_TD_7998377_output);
    gettimeofday(&tv_r_Filter_7_466240_e, 0);

    struct timeval tv_r_JOIN_INNER_7_270782_s, tv_r_JOIN_INNER_7_270782_e;
    gettimeofday(&tv_r_JOIN_INNER_7_270782_s, 0);
    SW_JOIN_INNER_TD_7367178(tbl_JOIN_INNER_TD_8999891_output, tbl_Filter_TD_8555915_output, tbl_JOIN_INNER_TD_7367178_output);
    gettimeofday(&tv_r_JOIN_INNER_7_270782_e, 0);

    struct timeval tv_r_JOIN_INNER_6_251976_s, tv_r_JOIN_INNER_6_251976_e;
    gettimeofday(&tv_r_JOIN_INNER_6_251976_s, 0);
    SW_JOIN_INNER_TD_6960671(tbl_JOIN_INNER_TD_7367178_output, tbl_Filter_TD_7998377_output, tbl_JOIN_INNER_TD_6960671_output);
    gettimeofday(&tv_r_JOIN_INNER_6_251976_e, 0);

    struct timeval tv_r_Expand_5_284248_s, tv_r_Expand_5_284248_e;
    gettimeofday(&tv_r_Expand_5_284248_s, 0);
    SW_Expand_TD_5642293(tbl_JOIN_INNER_TD_6960671_output, tbl_Expand_TD_5642293_output);
    gettimeofday(&tv_r_Expand_5_284248_e, 0);

    struct timeval tv_r_Aggregate_4_603211_s, tv_r_Aggregate_4_603211_e;
    gettimeofday(&tv_r_Aggregate_4_603211_s, 0);
    SW_Aggregate_TD_4374802(tbl_Expand_TD_5642293_output, tbl_Aggregate_TD_4374802_output);
    gettimeofday(&tv_r_Aggregate_4_603211_e, 0);

    struct timeval tv_r_Window_3_739074_s, tv_r_Window_3_739074_e;
    gettimeofday(&tv_r_Window_3_739074_s, 0);
    SW_Window_TD_3768571(tbl_Aggregate_TD_4374802_output, tbl_Window_TD_3768571_output);
    gettimeofday(&tv_r_Window_3_739074_e, 0);

    struct timeval tv_r_Sort_2_540324_s, tv_r_Sort_2_540324_e;
    gettimeofday(&tv_r_Sort_2_540324_s, 0);
    SW_Sort_TD_294355(tbl_Window_TD_3768571_output, tbl_Sort_TD_294355_output);
    gettimeofday(&tv_r_Sort_2_540324_e, 0);

    struct timeval tv_r_LocalLimit_1_862035_s, tv_r_LocalLimit_1_862035_e;
    gettimeofday(&tv_r_LocalLimit_1_862035_s, 0);
    SW_LocalLimit_TD_147152(tbl_Sort_TD_294355_output, tbl_LocalLimit_TD_147152_output);
    gettimeofday(&tv_r_LocalLimit_1_862035_e, 0);

    struct timeval tv_r_GlobalLimit_0_450573_s, tv_r_GlobalLimit_0_450573_e;
    gettimeofday(&tv_r_GlobalLimit_0_450573_s, 0);
    SW_GlobalLimit_TD_0739015(tbl_LocalLimit_TD_147152_output, tbl_GlobalLimit_TD_0739015_output);
    gettimeofday(&tv_r_GlobalLimit_0_450573_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_552060_s, &tv_r_Filter_9_552060_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10562796_input: " << tbl_SerializeFromObject_TD_10562796_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_236972_s, &tv_r_Filter_9_236972_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10367580_input: " << tbl_SerializeFromObject_TD_10367580_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_209402_s, &tv_r_Filter_8_209402_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_996716_input: " << tbl_SerializeFromObject_TD_996716_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_23698_s, &tv_r_JOIN_INNER_8_23698_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9291015_output: " << tbl_Filter_TD_9291015_output.getNumRow() << " " << "tbl_Filter_TD_9591377_output: " << tbl_Filter_TD_9591377_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_466240_s, &tv_r_Filter_7_466240_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8119232_input: " << tbl_SerializeFromObject_TD_8119232_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_270782_s, &tv_r_JOIN_INNER_7_270782_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8999891_output: " << tbl_JOIN_INNER_TD_8999891_output.getNumRow() << " " << "tbl_Filter_TD_8555915_output: " << tbl_Filter_TD_8555915_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_251976_s, &tv_r_JOIN_INNER_6_251976_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7367178_output: " << tbl_JOIN_INNER_TD_7367178_output.getNumRow() << " " << "tbl_Filter_TD_7998377_output: " << tbl_Filter_TD_7998377_output.getNumRow() << " " << std::endl; 

    std::cout << "Expand_5: " << tvdiff(&tv_r_Expand_5_284248_s, &tv_r_Expand_5_284248_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6960671_output: " << tbl_JOIN_INNER_TD_6960671_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_4: " << tvdiff(&tv_r_Aggregate_4_603211_s, &tv_r_Aggregate_4_603211_e) / 1000.0 << " ms " 
     << "tbl_Expand_TD_5642293_output: " << tbl_Expand_TD_5642293_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_3: " << tvdiff(&tv_r_Window_3_739074_s, &tv_r_Window_3_739074_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_4374802_output: " << tbl_Aggregate_TD_4374802_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_540324_s, &tv_r_Sort_2_540324_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_3768571_output: " << tbl_Window_TD_3768571_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_862035_s, &tv_r_LocalLimit_1_862035_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_294355_output: " << tbl_Sort_TD_294355_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_450573_s, &tv_r_GlobalLimit_0_450573_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_147152_output: " << tbl_LocalLimit_TD_147152_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.4532983 * 1000 << "ms" << std::endl; 
    return 0; 
}
