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

#include "cfgFunc_q67.hpp" 
#include "q67.hpp" 

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
    std::cout << "NOTE:running query #67\n."; 
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
    Table tbl_GlobalLimit_TD_0215895_output("tbl_GlobalLimit_TD_0215895_output", 6100000, 10, "");
    tbl_GlobalLimit_TD_0215895_output.allocateHost();
    Table tbl_LocalLimit_TD_1458245_output("tbl_LocalLimit_TD_1458245_output", 6100000, 10, "");
    tbl_LocalLimit_TD_1458245_output.allocateHost();
    Table tbl_Sort_TD_2940586_output("tbl_Sort_TD_2940586_output", 6100000, 10, "");
    tbl_Sort_TD_2940586_output.allocateHost();
    Table tbl_Filter_TD_3982792_output("tbl_Filter_TD_3982792_output", 6100000, 10, "");
    tbl_Filter_TD_3982792_output.allocateHost();
    Table tbl_Window_TD_4776193_output("tbl_Window_TD_4776193_output", 6100000, 10, "");
    tbl_Window_TD_4776193_output.allocateHost();
    Table tbl_Aggregate_TD_5527344_output("tbl_Aggregate_TD_5527344_output", 6100000, 9, "");
    tbl_Aggregate_TD_5527344_output.allocateHost();
    Table tbl_Expand_TD_6238310_output("tbl_Expand_TD_6238310_output", 6100000, 11, "");
    tbl_Expand_TD_6238310_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7528358_output("tbl_JOIN_INNER_TD_7528358_output", 6100000, 10, "");
    tbl_JOIN_INNER_TD_7528358_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8235201_output("tbl_JOIN_INNER_TD_8235201_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_8235201_output.allocateHost();
    Table tbl_Filter_TD_8431695_output("tbl_Filter_TD_8431695_output", 6100000, 5, "");
    tbl_Filter_TD_8431695_output.allocateHost();
    Table tbl_JOIN_INNER_TD_9293512_output("tbl_JOIN_INNER_TD_9293512_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_9293512_output.allocateHost();
    Table tbl_Filter_TD_9243902_output("tbl_Filter_TD_9243902_output", 6100000, 2, "");
    tbl_Filter_TD_9243902_output.allocateHost();
    Table tbl_SerializeFromObject_TD_928953_input;
    tbl_SerializeFromObject_TD_928953_input = Table("item", item_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_928953_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_928953_input.addCol("i_brand", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_928953_input.addCol("i_class", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_928953_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_928953_input.addCol("i_product_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_928953_input.allocateHost();
    tbl_SerializeFromObject_TD_928953_input.loadHost();
    Table tbl_Filter_TD_10597889_output("tbl_Filter_TD_10597889_output", 6100000, 5, "");
    tbl_Filter_TD_10597889_output.allocateHost();
    Table tbl_Filter_TD_10831283_output("tbl_Filter_TD_10831283_output", 6100000, 4, "");
    tbl_Filter_TD_10831283_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10649466_input;
    tbl_SerializeFromObject_TD_10649466_input = Table("store", store_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10649466_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_10649466_input.addCol("s_store_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10649466_input.allocateHost();
    tbl_SerializeFromObject_TD_10649466_input.loadHost();
    Table tbl_SerializeFromObject_TD_11245076_input;
    tbl_SerializeFromObject_TD_11245076_input = Table("store_sales", store_sales_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_11245076_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_11245076_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_11245076_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_11245076_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_11245076_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_11245076_input.allocateHost();
    tbl_SerializeFromObject_TD_11245076_input.loadHost();
    Table tbl_SerializeFromObject_TD_11305067_input;
    tbl_SerializeFromObject_TD_11305067_input = Table("date_dim", date_dim_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_11305067_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_11305067_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_11305067_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_11305067_input.addCol("d_qoy", 4);
    tbl_SerializeFromObject_TD_11305067_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_11305067_input.allocateHost();
    tbl_SerializeFromObject_TD_11305067_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_9293512_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10597889_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10831283_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_9293512_cmds;
    cfg_JOIN_INNER_TD_9293512_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_9293512_gqe_join (cfg_JOIN_INNER_TD_9293512_cmds.cmd);
    cfg_JOIN_INNER_TD_9293512_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_9293512;
    krnl_JOIN_INNER_TD_9293512 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_9293512.setup(tbl_Filter_TD_10597889_output, tbl_Filter_TD_10831283_output, tbl_JOIN_INNER_TD_9293512_output, cfg_JOIN_INNER_TD_9293512_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_9293512;
    trans_JOIN_INNER_TD_9293512.setq(q_h);
    trans_JOIN_INNER_TD_9293512.add(&(cfg_JOIN_INNER_TD_9293512_cmds));
    transEngine trans_JOIN_INNER_TD_9293512_out;
    trans_JOIN_INNER_TD_9293512_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_9293512;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_9293512;
    std::vector<cl::Event> events_JOIN_INNER_TD_9293512;
    events_h2d_wr_JOIN_INNER_TD_9293512.resize(1);
    events_d2h_rd_JOIN_INNER_TD_9293512.resize(1);
    events_JOIN_INNER_TD_9293512.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_9293512;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_9293512;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_10_86422_s, tv_r_Filter_10_86422_e;
    gettimeofday(&tv_r_Filter_10_86422_s, 0);
    SW_Filter_TD_10831283(tbl_SerializeFromObject_TD_11305067_input, tbl_Filter_TD_10831283_output);
    gettimeofday(&tv_r_Filter_10_86422_e, 0);

    struct timeval tv_r_Filter_10_88654_s, tv_r_Filter_10_88654_e;
    gettimeofday(&tv_r_Filter_10_88654_s, 0);
    SW_Filter_TD_10597889(tbl_SerializeFromObject_TD_11245076_input, tbl_Filter_TD_10597889_output);
    gettimeofday(&tv_r_Filter_10_88654_e, 0);

    struct timeval tv_r_Filter_9_515229_s, tv_r_Filter_9_515229_e;
    gettimeofday(&tv_r_Filter_9_515229_s, 0);
    SW_Filter_TD_9243902(tbl_SerializeFromObject_TD_10649466_input, tbl_Filter_TD_9243902_output);
    gettimeofday(&tv_r_Filter_9_515229_e, 0);

    struct timeval tv_r_JOIN_INNER_9_366898_s, tv_r_JOIN_INNER_9_366898_e;
    gettimeofday(&tv_r_JOIN_INNER_9_366898_s, 0);
    trans_JOIN_INNER_TD_9293512.add(&(tbl_Filter_TD_10597889_output));
    trans_JOIN_INNER_TD_9293512.add(&(tbl_Filter_TD_10831283_output));
    trans_JOIN_INNER_TD_9293512.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_9293512), &(events_h2d_wr_JOIN_INNER_TD_9293512[0]));
    events_grp_JOIN_INNER_TD_9293512.push_back(events_h2d_wr_JOIN_INNER_TD_9293512[0]);
    krnl_JOIN_INNER_TD_9293512.run(0, &(events_grp_JOIN_INNER_TD_9293512), &(events_JOIN_INNER_TD_9293512[0]));
    
    trans_JOIN_INNER_TD_9293512_out.add(&(tbl_JOIN_INNER_TD_9293512_output));
    trans_JOIN_INNER_TD_9293512_out.dev2host(0, &(events_JOIN_INNER_TD_9293512), &(events_d2h_rd_JOIN_INNER_TD_9293512[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_9_366898_e, 0);

    struct timeval tv_r_Filter_8_467933_s, tv_r_Filter_8_467933_e;
    gettimeofday(&tv_r_Filter_8_467933_s, 0);
    SW_Filter_TD_8431695(tbl_SerializeFromObject_TD_928953_input, tbl_Filter_TD_8431695_output);
    gettimeofday(&tv_r_Filter_8_467933_e, 0);

    struct timeval tv_r_JOIN_INNER_8_235709_s, tv_r_JOIN_INNER_8_235709_e;
    gettimeofday(&tv_r_JOIN_INNER_8_235709_s, 0);
    SW_JOIN_INNER_TD_8235201(tbl_JOIN_INNER_TD_9293512_output, tbl_Filter_TD_9243902_output, tbl_JOIN_INNER_TD_8235201_output);
    gettimeofday(&tv_r_JOIN_INNER_8_235709_e, 0);

    struct timeval tv_r_JOIN_INNER_7_226739_s, tv_r_JOIN_INNER_7_226739_e;
    gettimeofday(&tv_r_JOIN_INNER_7_226739_s, 0);
    SW_JOIN_INNER_TD_7528358(tbl_JOIN_INNER_TD_8235201_output, tbl_Filter_TD_8431695_output, tbl_JOIN_INNER_TD_7528358_output);
    gettimeofday(&tv_r_JOIN_INNER_7_226739_e, 0);

    struct timeval tv_r_Expand_6_396239_s, tv_r_Expand_6_396239_e;
    gettimeofday(&tv_r_Expand_6_396239_s, 0);
    SW_Expand_TD_6238310(tbl_JOIN_INNER_TD_7528358_output, tbl_Expand_TD_6238310_output);
    gettimeofday(&tv_r_Expand_6_396239_e, 0);

    struct timeval tv_r_Aggregate_5_198266_s, tv_r_Aggregate_5_198266_e;
    gettimeofday(&tv_r_Aggregate_5_198266_s, 0);
    SW_Aggregate_TD_5527344(tbl_Expand_TD_6238310_output, tbl_Aggregate_TD_5527344_output);
    gettimeofday(&tv_r_Aggregate_5_198266_e, 0);

    struct timeval tv_r_Window_4_151058_s, tv_r_Window_4_151058_e;
    gettimeofday(&tv_r_Window_4_151058_s, 0);
    SW_Window_TD_4776193(tbl_Aggregate_TD_5527344_output, tbl_Window_TD_4776193_output);
    gettimeofday(&tv_r_Window_4_151058_e, 0);

    struct timeval tv_r_Filter_3_667701_s, tv_r_Filter_3_667701_e;
    gettimeofday(&tv_r_Filter_3_667701_s, 0);
    SW_Filter_TD_3982792(tbl_Window_TD_4776193_output, tbl_Filter_TD_3982792_output);
    gettimeofday(&tv_r_Filter_3_667701_e, 0);

    struct timeval tv_r_Sort_2_749657_s, tv_r_Sort_2_749657_e;
    gettimeofday(&tv_r_Sort_2_749657_s, 0);
    SW_Sort_TD_2940586(tbl_Filter_TD_3982792_output, tbl_Sort_TD_2940586_output);
    gettimeofday(&tv_r_Sort_2_749657_e, 0);

    struct timeval tv_r_LocalLimit_1_191213_s, tv_r_LocalLimit_1_191213_e;
    gettimeofday(&tv_r_LocalLimit_1_191213_s, 0);
    SW_LocalLimit_TD_1458245(tbl_Sort_TD_2940586_output, tbl_LocalLimit_TD_1458245_output);
    gettimeofday(&tv_r_LocalLimit_1_191213_e, 0);

    struct timeval tv_r_GlobalLimit_0_903744_s, tv_r_GlobalLimit_0_903744_e;
    gettimeofday(&tv_r_GlobalLimit_0_903744_s, 0);
    SW_GlobalLimit_TD_0215895(tbl_LocalLimit_TD_1458245_output, tbl_GlobalLimit_TD_0215895_output);
    gettimeofday(&tv_r_GlobalLimit_0_903744_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_86422_s, &tv_r_Filter_10_86422_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11305067_input: " << tbl_SerializeFromObject_TD_11305067_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_88654_s, &tv_r_Filter_10_88654_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11245076_input: " << tbl_SerializeFromObject_TD_11245076_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_515229_s, &tv_r_Filter_9_515229_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10649466_input: " << tbl_SerializeFromObject_TD_10649466_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_366898_s, &tv_r_JOIN_INNER_9_366898_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10597889_output: " << tbl_Filter_TD_10597889_output.getNumRow() << " " << "tbl_Filter_TD_10831283_output: " << tbl_Filter_TD_10831283_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_467933_s, &tv_r_Filter_8_467933_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_928953_input: " << tbl_SerializeFromObject_TD_928953_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_235709_s, &tv_r_JOIN_INNER_8_235709_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9293512_output: " << tbl_JOIN_INNER_TD_9293512_output.getNumRow() << " " << "tbl_Filter_TD_9243902_output: " << tbl_Filter_TD_9243902_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_226739_s, &tv_r_JOIN_INNER_7_226739_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8235201_output: " << tbl_JOIN_INNER_TD_8235201_output.getNumRow() << " " << "tbl_Filter_TD_8431695_output: " << tbl_Filter_TD_8431695_output.getNumRow() << " " << std::endl; 

    std::cout << "Expand_6: " << tvdiff(&tv_r_Expand_6_396239_s, &tv_r_Expand_6_396239_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7528358_output: " << tbl_JOIN_INNER_TD_7528358_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_198266_s, &tv_r_Aggregate_5_198266_e) / 1000.0 << " ms " 
     << "tbl_Expand_TD_6238310_output: " << tbl_Expand_TD_6238310_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_4: " << tvdiff(&tv_r_Window_4_151058_s, &tv_r_Window_4_151058_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_5527344_output: " << tbl_Aggregate_TD_5527344_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_667701_s, &tv_r_Filter_3_667701_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_4776193_output: " << tbl_Window_TD_4776193_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_749657_s, &tv_r_Sort_2_749657_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_3982792_output: " << tbl_Filter_TD_3982792_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_191213_s, &tv_r_LocalLimit_1_191213_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2940586_output: " << tbl_Sort_TD_2940586_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_903744_s, &tv_r_GlobalLimit_0_903744_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1458245_output: " << tbl_LocalLimit_TD_1458245_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 9.534836 * 1000 << "ms" << std::endl; 
    return 0; 
}
