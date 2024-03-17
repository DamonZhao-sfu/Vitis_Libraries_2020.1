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

#include "cfgFunc_q70.hpp" 
#include "q70.hpp" 

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
    std::cout << "NOTE:running query #70\n."; 
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
    Table tbl_GlobalLimit_TD_0640622_output("tbl_GlobalLimit_TD_0640622_output", 6100000, 5, "");
    tbl_GlobalLimit_TD_0640622_output.allocateHost();
    Table tbl_LocalLimit_TD_1655134_output("tbl_LocalLimit_TD_1655134_output", 6100000, 5, "");
    tbl_LocalLimit_TD_1655134_output.allocateHost();
    Table tbl_Sort_TD_2668436_output("tbl_Sort_TD_2668436_output", 6100000, 5, "");
    tbl_Sort_TD_2668436_output.allocateHost();
    Table tbl_Window_TD_3896206_output("tbl_Window_TD_3896206_output", 6100000, 8, "");
    tbl_Window_TD_3896206_output.allocateHost();
    Table tbl_Aggregate_TD_4856132_output("tbl_Aggregate_TD_4856132_output", 6100000, 7, "");
    tbl_Aggregate_TD_4856132_output.allocateHost();
    Table tbl_Expand_TD_547287_output("tbl_Expand_TD_547287_output", 6100000, 4, "");
    tbl_Expand_TD_547287_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6302484_output("tbl_JOIN_INNER_TD_6302484_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_6302484_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7883227_output("tbl_JOIN_INNER_TD_7883227_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_7883227_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_7300130_output("tbl_JOIN_LEFTSEMI_TD_7300130_output", 6100000, 3, "");
    tbl_JOIN_LEFTSEMI_TD_7300130_output.allocateHost();
    Table tbl_Filter_TD_8758138_output("tbl_Filter_TD_8758138_output", 6100000, 3, "");
    tbl_Filter_TD_8758138_output.allocateHost();
    Table tbl_Filter_TD_8777042_output("tbl_Filter_TD_8777042_output", 6100000, 1, "");
    tbl_Filter_TD_8777042_output.allocateHost();
    Table tbl_Filter_TD_8609848_output("tbl_Filter_TD_8609848_output", 6100000, 3, "");
    tbl_Filter_TD_8609848_output.allocateHost();
    Table tbl_Filter_TD_8385174_output("tbl_Filter_TD_8385174_output", 6100000, 1, "");
    tbl_Filter_TD_8385174_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9119720_input;
    tbl_SerializeFromObject_TD_9119720_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9119720_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_9119720_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_9119720_input.addCol("ss_net_profit", 4);
    tbl_SerializeFromObject_TD_9119720_input.allocateHost();
    tbl_SerializeFromObject_TD_9119720_input.loadHost();
    Table tbl_SerializeFromObject_TD_9263367_input;
    tbl_SerializeFromObject_TD_9263367_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9263367_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_9263367_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_9263367_input.allocateHost();
    tbl_SerializeFromObject_TD_9263367_input.loadHost();
    Table tbl_SerializeFromObject_TD_9230220_input;
    tbl_SerializeFromObject_TD_9230220_input = Table("store", store_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9230220_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_9230220_input.addCol("s_county", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9230220_input.addCol("s_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9230220_input.allocateHost();
    tbl_SerializeFromObject_TD_9230220_input.loadHost();
    Table tbl_Window_TD_9667985_output("tbl_Window_TD_9667985_output", 6100000, 4, "");
    tbl_Window_TD_9667985_output.allocateHost();
    Table tbl_Aggregate_TD_10921692_output("tbl_Aggregate_TD_10921692_output", 6100000, 3, "");
    tbl_Aggregate_TD_10921692_output.allocateHost();
    Table tbl_JOIN_INNER_TD_11784386_output("tbl_JOIN_INNER_TD_11784386_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_11784386_output.allocateHost();
    Table tbl_JOIN_INNER_TD_12232573_output("tbl_JOIN_INNER_TD_12232573_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_12232573_output.allocateHost();
    Table tbl_Filter_TD_12933514_output("tbl_Filter_TD_12933514_output", 6100000, 1, "");
    tbl_Filter_TD_12933514_output.allocateHost();
    Table tbl_Filter_TD_13179144_output("tbl_Filter_TD_13179144_output", 6100000, 3, "");
    tbl_Filter_TD_13179144_output.allocateHost();
    Table tbl_Filter_TD_13278379_output("tbl_Filter_TD_13278379_output", 6100000, 2, "");
    tbl_Filter_TD_13278379_output.allocateHost();
    Table tbl_SerializeFromObject_TD_13738402_input;
    tbl_SerializeFromObject_TD_13738402_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_13738402_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_13738402_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_13738402_input.allocateHost();
    tbl_SerializeFromObject_TD_13738402_input.loadHost();
    Table tbl_SerializeFromObject_TD_14148582_input;
    tbl_SerializeFromObject_TD_14148582_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_14148582_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_14148582_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_14148582_input.addCol("ss_net_profit", 4);
    tbl_SerializeFromObject_TD_14148582_input.allocateHost();
    tbl_SerializeFromObject_TD_14148582_input.loadHost();
    Table tbl_SerializeFromObject_TD_14958137_input;
    tbl_SerializeFromObject_TD_14958137_input = Table("store", store_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_14958137_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_14958137_input.addCol("s_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_14958137_input.allocateHost();
    tbl_SerializeFromObject_TD_14958137_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_7883227_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8758138_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8777042_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_7883227_cmds;
    cfg_JOIN_INNER_TD_7883227_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7883227_gqe_join (cfg_JOIN_INNER_TD_7883227_cmds.cmd);
    cfg_JOIN_INNER_TD_7883227_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_7883227;
    krnl_JOIN_INNER_TD_7883227 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7883227.setup(tbl_Filter_TD_8758138_output, tbl_Filter_TD_8777042_output, tbl_JOIN_INNER_TD_7883227_output, cfg_JOIN_INNER_TD_7883227_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_7883227;
    trans_JOIN_INNER_TD_7883227.setq(q_h);
    trans_JOIN_INNER_TD_7883227.add(&(cfg_JOIN_INNER_TD_7883227_cmds));
    transEngine trans_JOIN_INNER_TD_7883227_out;
    trans_JOIN_INNER_TD_7883227_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7883227;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7883227;
    std::vector<cl::Event> events_JOIN_INNER_TD_7883227;
    events_h2d_wr_JOIN_INNER_TD_7883227.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7883227.resize(1);
    events_JOIN_INNER_TD_7883227.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7883227;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7883227;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_13_785057_s, tv_r_Filter_13_785057_e;
    gettimeofday(&tv_r_Filter_13_785057_s, 0);
    SW_Filter_TD_13278379(tbl_SerializeFromObject_TD_14958137_input, tbl_Filter_TD_13278379_output);
    gettimeofday(&tv_r_Filter_13_785057_e, 0);

    struct timeval tv_r_Filter_13_187032_s, tv_r_Filter_13_187032_e;
    gettimeofday(&tv_r_Filter_13_187032_s, 0);
    SW_Filter_TD_13179144(tbl_SerializeFromObject_TD_14148582_input, tbl_Filter_TD_13179144_output);
    gettimeofday(&tv_r_Filter_13_187032_e, 0);

    struct timeval tv_r_Filter_12_154240_s, tv_r_Filter_12_154240_e;
    gettimeofday(&tv_r_Filter_12_154240_s, 0);
    SW_Filter_TD_12933514(tbl_SerializeFromObject_TD_13738402_input, tbl_Filter_TD_12933514_output);
    gettimeofday(&tv_r_Filter_12_154240_e, 0);

    struct timeval tv_r_JOIN_INNER_12_995042_s, tv_r_JOIN_INNER_12_995042_e;
    gettimeofday(&tv_r_JOIN_INNER_12_995042_s, 0);
    SW_JOIN_INNER_TD_12232573(tbl_Filter_TD_13179144_output, tbl_Filter_TD_13278379_output, tbl_JOIN_INNER_TD_12232573_output);
    gettimeofday(&tv_r_JOIN_INNER_12_995042_e, 0);

    struct timeval tv_r_JOIN_INNER_11_800104_s, tv_r_JOIN_INNER_11_800104_e;
    gettimeofday(&tv_r_JOIN_INNER_11_800104_s, 0);
    SW_JOIN_INNER_TD_11784386(tbl_JOIN_INNER_TD_12232573_output, tbl_Filter_TD_12933514_output, tbl_JOIN_INNER_TD_11784386_output);
    gettimeofday(&tv_r_JOIN_INNER_11_800104_e, 0);

    struct timeval tv_r_Aggregate_10_805632_s, tv_r_Aggregate_10_805632_e;
    gettimeofday(&tv_r_Aggregate_10_805632_s, 0);
    SW_Aggregate_TD_10921692(tbl_JOIN_INNER_TD_11784386_output, tbl_Aggregate_TD_10921692_output);
    gettimeofday(&tv_r_Aggregate_10_805632_e, 0);

    struct timeval tv_r_Window_9_344369_s, tv_r_Window_9_344369_e;
    gettimeofday(&tv_r_Window_9_344369_s, 0);
    SW_Window_TD_9667985(tbl_Aggregate_TD_10921692_output, tbl_Window_TD_9667985_output);
    gettimeofday(&tv_r_Window_9_344369_e, 0);

    struct timeval tv_r_Filter_8_422722_s, tv_r_Filter_8_422722_e;
    gettimeofday(&tv_r_Filter_8_422722_s, 0);
    SW_Filter_TD_8385174(tbl_Window_TD_9667985_output, tbl_Filter_TD_8385174_output);
    gettimeofday(&tv_r_Filter_8_422722_e, 0);

    struct timeval tv_r_Filter_8_3866_s, tv_r_Filter_8_3866_e;
    gettimeofday(&tv_r_Filter_8_3866_s, 0);
    SW_Filter_TD_8609848(tbl_SerializeFromObject_TD_9230220_input, tbl_Filter_TD_8609848_output);
    gettimeofday(&tv_r_Filter_8_3866_e, 0);

    struct timeval tv_r_Filter_8_28923_s, tv_r_Filter_8_28923_e;
    gettimeofday(&tv_r_Filter_8_28923_s, 0);
    SW_Filter_TD_8777042(tbl_SerializeFromObject_TD_9263367_input, tbl_Filter_TD_8777042_output);
    gettimeofday(&tv_r_Filter_8_28923_e, 0);

    struct timeval tv_r_Filter_8_357741_s, tv_r_Filter_8_357741_e;
    gettimeofday(&tv_r_Filter_8_357741_s, 0);
    SW_Filter_TD_8758138(tbl_SerializeFromObject_TD_9119720_input, tbl_Filter_TD_8758138_output);
    gettimeofday(&tv_r_Filter_8_357741_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_7_698443_s, tv_r_JOIN_LEFTSEMI_7_698443_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_698443_s, 0);
    SW_JOIN_LEFTSEMI_TD_7300130(tbl_Filter_TD_8609848_output, tbl_Filter_TD_8385174_output, tbl_JOIN_LEFTSEMI_TD_7300130_output);
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_698443_e, 0);

    struct timeval tv_r_JOIN_INNER_7_237941_s, tv_r_JOIN_INNER_7_237941_e;
    gettimeofday(&tv_r_JOIN_INNER_7_237941_s, 0);
    trans_JOIN_INNER_TD_7883227.add(&(tbl_Filter_TD_8758138_output));
    trans_JOIN_INNER_TD_7883227.add(&(tbl_Filter_TD_8777042_output));
    trans_JOIN_INNER_TD_7883227.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7883227), &(events_h2d_wr_JOIN_INNER_TD_7883227[0]));
    events_grp_JOIN_INNER_TD_7883227.push_back(events_h2d_wr_JOIN_INNER_TD_7883227[0]);
    krnl_JOIN_INNER_TD_7883227.run(0, &(events_grp_JOIN_INNER_TD_7883227), &(events_JOIN_INNER_TD_7883227[0]));
    
    trans_JOIN_INNER_TD_7883227_out.add(&(tbl_JOIN_INNER_TD_7883227_output));
    trans_JOIN_INNER_TD_7883227_out.dev2host(0, &(events_JOIN_INNER_TD_7883227), &(events_d2h_rd_JOIN_INNER_TD_7883227[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_7_237941_e, 0);

    struct timeval tv_r_JOIN_INNER_6_8994_s, tv_r_JOIN_INNER_6_8994_e;
    gettimeofday(&tv_r_JOIN_INNER_6_8994_s, 0);
    SW_JOIN_INNER_TD_6302484(tbl_JOIN_INNER_TD_7883227_output, tbl_JOIN_LEFTSEMI_TD_7300130_output, tbl_JOIN_INNER_TD_6302484_output);
    gettimeofday(&tv_r_JOIN_INNER_6_8994_e, 0);

    struct timeval tv_r_Expand_5_562042_s, tv_r_Expand_5_562042_e;
    gettimeofday(&tv_r_Expand_5_562042_s, 0);
    SW_Expand_TD_547287(tbl_JOIN_INNER_TD_6302484_output, tbl_Expand_TD_547287_output);
    gettimeofday(&tv_r_Expand_5_562042_e, 0);

    struct timeval tv_r_Aggregate_4_560498_s, tv_r_Aggregate_4_560498_e;
    gettimeofday(&tv_r_Aggregate_4_560498_s, 0);
    SW_Aggregate_TD_4856132(tbl_Expand_TD_547287_output, tbl_Aggregate_TD_4856132_output);
    gettimeofday(&tv_r_Aggregate_4_560498_e, 0);

    struct timeval tv_r_Window_3_538229_s, tv_r_Window_3_538229_e;
    gettimeofday(&tv_r_Window_3_538229_s, 0);
    SW_Window_TD_3896206(tbl_Aggregate_TD_4856132_output, tbl_Window_TD_3896206_output);
    gettimeofday(&tv_r_Window_3_538229_e, 0);

    struct timeval tv_r_Sort_2_72545_s, tv_r_Sort_2_72545_e;
    gettimeofday(&tv_r_Sort_2_72545_s, 0);
    SW_Sort_TD_2668436(tbl_Window_TD_3896206_output, tbl_Sort_TD_2668436_output);
    gettimeofday(&tv_r_Sort_2_72545_e, 0);

    struct timeval tv_r_LocalLimit_1_150073_s, tv_r_LocalLimit_1_150073_e;
    gettimeofday(&tv_r_LocalLimit_1_150073_s, 0);
    SW_LocalLimit_TD_1655134(tbl_Sort_TD_2668436_output, tbl_LocalLimit_TD_1655134_output);
    gettimeofday(&tv_r_LocalLimit_1_150073_e, 0);

    struct timeval tv_r_GlobalLimit_0_294762_s, tv_r_GlobalLimit_0_294762_e;
    gettimeofday(&tv_r_GlobalLimit_0_294762_s, 0);
    SW_GlobalLimit_TD_0640622(tbl_LocalLimit_TD_1655134_output, tbl_GlobalLimit_TD_0640622_output);
    gettimeofday(&tv_r_GlobalLimit_0_294762_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_13: " << tvdiff(&tv_r_Filter_13_785057_s, &tv_r_Filter_13_785057_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_14958137_input: " << tbl_SerializeFromObject_TD_14958137_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_13: " << tvdiff(&tv_r_Filter_13_187032_s, &tv_r_Filter_13_187032_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_14148582_input: " << tbl_SerializeFromObject_TD_14148582_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_154240_s, &tv_r_Filter_12_154240_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13738402_input: " << tbl_SerializeFromObject_TD_13738402_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_12: " << tvdiff(&tv_r_JOIN_INNER_12_995042_s, &tv_r_JOIN_INNER_12_995042_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_13179144_output: " << tbl_Filter_TD_13179144_output.getNumRow() << " " << "tbl_Filter_TD_13278379_output: " << tbl_Filter_TD_13278379_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_11: " << tvdiff(&tv_r_JOIN_INNER_11_800104_s, &tv_r_JOIN_INNER_11_800104_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_12232573_output: " << tbl_JOIN_INNER_TD_12232573_output.getNumRow() << " " << "tbl_Filter_TD_12933514_output: " << tbl_Filter_TD_12933514_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_10: " << tvdiff(&tv_r_Aggregate_10_805632_s, &tv_r_Aggregate_10_805632_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_11784386_output: " << tbl_JOIN_INNER_TD_11784386_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_9: " << tvdiff(&tv_r_Window_9_344369_s, &tv_r_Window_9_344369_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_10921692_output: " << tbl_Aggregate_TD_10921692_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_422722_s, &tv_r_Filter_8_422722_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_9667985_output: " << tbl_Window_TD_9667985_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_3866_s, &tv_r_Filter_8_3866_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9230220_input: " << tbl_SerializeFromObject_TD_9230220_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_28923_s, &tv_r_Filter_8_28923_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9263367_input: " << tbl_SerializeFromObject_TD_9263367_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_357741_s, &tv_r_Filter_8_357741_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9119720_input: " << tbl_SerializeFromObject_TD_9119720_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_7: " << tvdiff(&tv_r_JOIN_LEFTSEMI_7_698443_s, &tv_r_JOIN_LEFTSEMI_7_698443_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8609848_output: " << tbl_Filter_TD_8609848_output.getNumRow() << " " << "tbl_Filter_TD_8385174_output: " << tbl_Filter_TD_8385174_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_237941_s, &tv_r_JOIN_INNER_7_237941_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8758138_output: " << tbl_Filter_TD_8758138_output.getNumRow() << " " << "tbl_Filter_TD_8777042_output: " << tbl_Filter_TD_8777042_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_8994_s, &tv_r_JOIN_INNER_6_8994_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7883227_output: " << tbl_JOIN_INNER_TD_7883227_output.getNumRow() << " " << "tbl_JOIN_LEFTSEMI_TD_7300130_output: " << tbl_JOIN_LEFTSEMI_TD_7300130_output.getNumRow() << " " << std::endl; 

    std::cout << "Expand_5: " << tvdiff(&tv_r_Expand_5_562042_s, &tv_r_Expand_5_562042_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6302484_output: " << tbl_JOIN_INNER_TD_6302484_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_4: " << tvdiff(&tv_r_Aggregate_4_560498_s, &tv_r_Aggregate_4_560498_e) / 1000.0 << " ms " 
     << "tbl_Expand_TD_547287_output: " << tbl_Expand_TD_547287_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_3: " << tvdiff(&tv_r_Window_3_538229_s, &tv_r_Window_3_538229_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_4856132_output: " << tbl_Aggregate_TD_4856132_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_72545_s, &tv_r_Sort_2_72545_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_3896206_output: " << tbl_Window_TD_3896206_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_150073_s, &tv_r_LocalLimit_1_150073_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2668436_output: " << tbl_Sort_TD_2668436_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_294762_s, &tv_r_GlobalLimit_0_294762_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1655134_output: " << tbl_LocalLimit_TD_1655134_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1344.0433 * 1000 << "ms" << std::endl; 
    return 0; 
}
