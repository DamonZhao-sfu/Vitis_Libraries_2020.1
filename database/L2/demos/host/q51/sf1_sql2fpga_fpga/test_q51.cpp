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

#include "cfgFunc_q51.hpp" 
#include "q51.hpp" 

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
    std::cout << "NOTE:running query #51\n."; 
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
    Table tbl_GlobalLimit_TD_01307_output("tbl_GlobalLimit_TD_01307_output", 6100000, 6, "");
    tbl_GlobalLimit_TD_01307_output.allocateHost();
    Table tbl_LocalLimit_TD_178420_output("tbl_LocalLimit_TD_178420_output", 6100000, 6, "");
    tbl_LocalLimit_TD_178420_output.allocateHost();
    Table tbl_Sort_TD_2689516_output("tbl_Sort_TD_2689516_output", 6100000, 6, "");
    tbl_Sort_TD_2689516_output.allocateHost();
    Table tbl_Filter_TD_3873404_output("tbl_Filter_TD_3873404_output", 6100000, 6, "");
    tbl_Filter_TD_3873404_output.allocateHost();
    Table tbl_Window_TD_4307433_output("tbl_Window_TD_4307433_output", 6100000, 6, "");
    tbl_Window_TD_4307433_output.allocateHost();
    Table tbl_Project_TD_5156260_output("tbl_Project_TD_5156260_output", 6100000, 4, "");
    tbl_Project_TD_5156260_output.allocateHost();
    Table tbl_JOIN_FULLOUTER_TD_6746405_output("tbl_JOIN_FULLOUTER_TD_6746405_output", 6100000, 6, "");
    tbl_JOIN_FULLOUTER_TD_6746405_output.allocateHost();
    Table tbl_Window_TD_7855870_output("tbl_Window_TD_7855870_output", 6100000, 5, "");
    tbl_Window_TD_7855870_output.allocateHost();
    Table tbl_Window_TD_7799101_output("tbl_Window_TD_7799101_output", 6100000, 5, "");
    tbl_Window_TD_7799101_output.allocateHost();
    Table tbl_Aggregate_TD_8282744_output("tbl_Aggregate_TD_8282744_output", 6100000, 4, "");
    tbl_Aggregate_TD_8282744_output.allocateHost();
    Table tbl_Aggregate_TD_8426435_output("tbl_Aggregate_TD_8426435_output", 6100000, 4, "");
    tbl_Aggregate_TD_8426435_output.allocateHost();
    Table tbl_JOIN_INNER_TD_9717571_output("tbl_JOIN_INNER_TD_9717571_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_9717571_output.allocateHost();
    Table tbl_JOIN_INNER_TD_9238506_output("tbl_JOIN_INNER_TD_9238506_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_9238506_output.allocateHost();
    Table tbl_Filter_TD_10345630_output("tbl_Filter_TD_10345630_output", 6100000, 3, "");
    tbl_Filter_TD_10345630_output.allocateHost();
    Table tbl_Filter_TD_10732262_output("tbl_Filter_TD_10732262_output", 6100000, 2, "");
    tbl_Filter_TD_10732262_output.allocateHost();
    Table tbl_Filter_TD_10836943_output("tbl_Filter_TD_10836943_output", 6100000, 3, "");
    tbl_Filter_TD_10836943_output.allocateHost();
    Table tbl_Filter_TD_10761658_output("tbl_Filter_TD_10761658_output", 6100000, 2, "");
    tbl_Filter_TD_10761658_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11561049_input;
    tbl_SerializeFromObject_TD_11561049_input = Table("web_sales", web_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11561049_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_11561049_input.addCol("ws_item_sk", 4);
    tbl_SerializeFromObject_TD_11561049_input.addCol("ws_sales_price", 4);
    tbl_SerializeFromObject_TD_11561049_input.allocateHost();
    tbl_SerializeFromObject_TD_11561049_input.loadHost();
    Table tbl_SerializeFromObject_TD_11356790_input;
    tbl_SerializeFromObject_TD_11356790_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11356790_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_11356790_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_11356790_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_11356790_input.allocateHost();
    tbl_SerializeFromObject_TD_11356790_input.loadHost();
    Table tbl_SerializeFromObject_TD_11858691_input;
    tbl_SerializeFromObject_TD_11858691_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11858691_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_11858691_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_11858691_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_11858691_input.allocateHost();
    tbl_SerializeFromObject_TD_11858691_input.loadHost();
    Table tbl_SerializeFromObject_TD_11660686_input;
    tbl_SerializeFromObject_TD_11660686_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11660686_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_11660686_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_11660686_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_11660686_input.allocateHost();
    tbl_SerializeFromObject_TD_11660686_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_FULLOUTER_TD_6746405_output.allocateDevBuffer(context_h, 32);
    tbl_Window_TD_7855870_output.allocateDevBuffer(context_h, 32);
    tbl_Window_TD_7799101_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_9717571_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_9238506_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10345630_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10732262_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10836943_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10761658_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_FULLOUTER_TD_6746405_cmds;
    cfg_JOIN_FULLOUTER_TD_6746405_cmds.allocateHost();
    get_cfg_dat_JOIN_FULLOUTER_TD_6746405_gqe_join (cfg_JOIN_FULLOUTER_TD_6746405_cmds.cmd);
    cfg_JOIN_FULLOUTER_TD_6746405_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_9717571_cmds;
    cfg_JOIN_INNER_TD_9717571_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_9717571_gqe_join (cfg_JOIN_INNER_TD_9717571_cmds.cmd);
    cfg_JOIN_INNER_TD_9717571_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_9238506_cmds;
    cfg_JOIN_INNER_TD_9238506_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_9238506_gqe_join (cfg_JOIN_INNER_TD_9238506_cmds.cmd);
    cfg_JOIN_INNER_TD_9238506_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_FULLOUTER_TD_6746405;
    krnl_JOIN_FULLOUTER_TD_6746405 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_FULLOUTER_TD_6746405.setup(tbl_Window_TD_7855870_output, tbl_Window_TD_7799101_output, tbl_JOIN_FULLOUTER_TD_6746405_output, cfg_JOIN_FULLOUTER_TD_6746405_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_9717571;
    krnl_JOIN_INNER_TD_9717571 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_9717571.setup(tbl_Filter_TD_10345630_output, tbl_Filter_TD_10732262_output, tbl_JOIN_INNER_TD_9717571_output, cfg_JOIN_INNER_TD_9717571_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_9238506;
    krnl_JOIN_INNER_TD_9238506 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_9238506.setup(tbl_Filter_TD_10836943_output, tbl_Filter_TD_10761658_output, tbl_JOIN_INNER_TD_9238506_output, cfg_JOIN_INNER_TD_9238506_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_FULLOUTER_TD_6746405;
    trans_JOIN_FULLOUTER_TD_6746405.setq(q_h);
    trans_JOIN_FULLOUTER_TD_6746405.add(&(cfg_JOIN_FULLOUTER_TD_6746405_cmds));
    transEngine trans_JOIN_FULLOUTER_TD_6746405_out;
    trans_JOIN_FULLOUTER_TD_6746405_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_9717571;
    trans_JOIN_INNER_TD_9717571.setq(q_h);
    trans_JOIN_INNER_TD_9717571.add(&(cfg_JOIN_INNER_TD_9717571_cmds));
    transEngine trans_JOIN_INNER_TD_9717571_out;
    trans_JOIN_INNER_TD_9717571_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_9238506;
    trans_JOIN_INNER_TD_9238506.setq(q_h);
    trans_JOIN_INNER_TD_9238506.add(&(cfg_JOIN_INNER_TD_9238506_cmds));
    transEngine trans_JOIN_INNER_TD_9238506_out;
    trans_JOIN_INNER_TD_9238506_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_FULLOUTER_TD_6746405;
    std::vector<cl::Event> events_d2h_rd_JOIN_FULLOUTER_TD_6746405;
    std::vector<cl::Event> events_JOIN_FULLOUTER_TD_6746405;
    events_h2d_wr_JOIN_FULLOUTER_TD_6746405.resize(1);
    events_d2h_rd_JOIN_FULLOUTER_TD_6746405.resize(1);
    events_JOIN_FULLOUTER_TD_6746405.resize(1);
    std::vector<cl::Event> events_grp_JOIN_FULLOUTER_TD_6746405;
    std::vector<cl::Event> prev_events_grp_JOIN_FULLOUTER_TD_6746405;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_9717571;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_9717571;
    std::vector<cl::Event> events_JOIN_INNER_TD_9717571;
    events_h2d_wr_JOIN_INNER_TD_9717571.resize(1);
    events_d2h_rd_JOIN_INNER_TD_9717571.resize(1);
    events_JOIN_INNER_TD_9717571.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_9717571;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_9717571;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_9238506;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_9238506;
    std::vector<cl::Event> events_JOIN_INNER_TD_9238506;
    events_h2d_wr_JOIN_INNER_TD_9238506.resize(1);
    events_d2h_rd_JOIN_INNER_TD_9238506.resize(1);
    events_JOIN_INNER_TD_9238506.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_9238506;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_9238506;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_10_899065_s, tv_r_Filter_10_899065_e;
    gettimeofday(&tv_r_Filter_10_899065_s, 0);
    SW_Filter_TD_10761658(tbl_SerializeFromObject_TD_11660686_input, tbl_Filter_TD_10761658_output);
    gettimeofday(&tv_r_Filter_10_899065_e, 0);

    struct timeval tv_r_Filter_10_698274_s, tv_r_Filter_10_698274_e;
    gettimeofday(&tv_r_Filter_10_698274_s, 0);
    SW_Filter_TD_10836943(tbl_SerializeFromObject_TD_11858691_input, tbl_Filter_TD_10836943_output);
    gettimeofday(&tv_r_Filter_10_698274_e, 0);

    struct timeval tv_r_Filter_10_247106_s, tv_r_Filter_10_247106_e;
    gettimeofday(&tv_r_Filter_10_247106_s, 0);
    SW_Filter_TD_10732262(tbl_SerializeFromObject_TD_11356790_input, tbl_Filter_TD_10732262_output);
    gettimeofday(&tv_r_Filter_10_247106_e, 0);

    struct timeval tv_r_Filter_10_936386_s, tv_r_Filter_10_936386_e;
    gettimeofday(&tv_r_Filter_10_936386_s, 0);
    SW_Filter_TD_10345630(tbl_SerializeFromObject_TD_11561049_input, tbl_Filter_TD_10345630_output);
    gettimeofday(&tv_r_Filter_10_936386_e, 0);

    struct timeval tv_r_JOIN_INNER_9_57513_s, tv_r_JOIN_INNER_9_57513_e;
    gettimeofday(&tv_r_JOIN_INNER_9_57513_s, 0);
    trans_JOIN_INNER_TD_9238506.add(&(tbl_Filter_TD_10836943_output));
    trans_JOIN_INNER_TD_9238506.add(&(tbl_Filter_TD_10761658_output));
    trans_JOIN_INNER_TD_9238506.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_9238506), &(events_h2d_wr_JOIN_INNER_TD_9238506[0]));
    events_grp_JOIN_INNER_TD_9238506.push_back(events_h2d_wr_JOIN_INNER_TD_9238506[0]);
    krnl_JOIN_INNER_TD_9238506.run(0, &(events_grp_JOIN_INNER_TD_9238506), &(events_JOIN_INNER_TD_9238506[0]));
    
    trans_JOIN_INNER_TD_9238506_out.add(&(tbl_JOIN_INNER_TD_9238506_output));
    trans_JOIN_INNER_TD_9238506_out.dev2host(0, &(events_JOIN_INNER_TD_9238506), &(events_d2h_rd_JOIN_INNER_TD_9238506[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_9_57513_e, 0);

    struct timeval tv_r_JOIN_INNER_9_43737_s, tv_r_JOIN_INNER_9_43737_e;
    gettimeofday(&tv_r_JOIN_INNER_9_43737_s, 0);
    trans_JOIN_INNER_TD_9717571.add(&(tbl_Filter_TD_10345630_output));
    trans_JOIN_INNER_TD_9717571.add(&(tbl_Filter_TD_10732262_output));
    trans_JOIN_INNER_TD_9717571.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_9717571), &(events_h2d_wr_JOIN_INNER_TD_9717571[0]));
    events_grp_JOIN_INNER_TD_9717571.push_back(events_h2d_wr_JOIN_INNER_TD_9717571[0]);
    krnl_JOIN_INNER_TD_9717571.run(0, &(events_grp_JOIN_INNER_TD_9717571), &(events_JOIN_INNER_TD_9717571[0]));
    
    trans_JOIN_INNER_TD_9717571_out.add(&(tbl_JOIN_INNER_TD_9717571_output));
    trans_JOIN_INNER_TD_9717571_out.dev2host(0, &(events_JOIN_INNER_TD_9717571), &(events_d2h_rd_JOIN_INNER_TD_9717571[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_9_43737_e, 0);

    struct timeval tv_r_Aggregate_8_271916_s, tv_r_Aggregate_8_271916_e;
    gettimeofday(&tv_r_Aggregate_8_271916_s, 0);
    SW_Aggregate_TD_8426435(tbl_JOIN_INNER_TD_9238506_output, tbl_Aggregate_TD_8426435_output);
    gettimeofday(&tv_r_Aggregate_8_271916_e, 0);

    struct timeval tv_r_Aggregate_8_951066_s, tv_r_Aggregate_8_951066_e;
    gettimeofday(&tv_r_Aggregate_8_951066_s, 0);
    SW_Aggregate_TD_8282744(tbl_JOIN_INNER_TD_9717571_output, tbl_Aggregate_TD_8282744_output);
    gettimeofday(&tv_r_Aggregate_8_951066_e, 0);

    struct timeval tv_r_Window_7_939116_s, tv_r_Window_7_939116_e;
    gettimeofday(&tv_r_Window_7_939116_s, 0);
    SW_Window_TD_7799101(tbl_Aggregate_TD_8426435_output, tbl_Window_TD_7799101_output);
    gettimeofday(&tv_r_Window_7_939116_e, 0);

    struct timeval tv_r_Window_7_828235_s, tv_r_Window_7_828235_e;
    gettimeofday(&tv_r_Window_7_828235_s, 0);
    SW_Window_TD_7855870(tbl_Aggregate_TD_8282744_output, tbl_Window_TD_7855870_output);
    gettimeofday(&tv_r_Window_7_828235_e, 0);

    struct timeval tv_r_JOIN_FULLOUTER_6_603579_s, tv_r_JOIN_FULLOUTER_6_603579_e;
    gettimeofday(&tv_r_JOIN_FULLOUTER_6_603579_s, 0);
    trans_JOIN_FULLOUTER_TD_6746405.add(&(tbl_Window_TD_7855870_output));
    trans_JOIN_FULLOUTER_TD_6746405.add(&(tbl_Window_TD_7799101_output));
    trans_JOIN_FULLOUTER_TD_6746405.host2dev(0, &(prev_events_grp_JOIN_FULLOUTER_TD_6746405), &(events_h2d_wr_JOIN_FULLOUTER_TD_6746405[0]));
    events_grp_JOIN_FULLOUTER_TD_6746405.push_back(events_h2d_wr_JOIN_FULLOUTER_TD_6746405[0]);
    krnl_JOIN_FULLOUTER_TD_6746405.run(0, &(events_grp_JOIN_FULLOUTER_TD_6746405), &(events_JOIN_FULLOUTER_TD_6746405[0]));
    
    trans_JOIN_FULLOUTER_TD_6746405_out.add(&(tbl_JOIN_FULLOUTER_TD_6746405_output));
    trans_JOIN_FULLOUTER_TD_6746405_out.dev2host(0, &(events_JOIN_FULLOUTER_TD_6746405), &(events_d2h_rd_JOIN_FULLOUTER_TD_6746405[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_FULLOUTER_6_603579_e, 0);

    struct timeval tv_r_Project_5_580330_s, tv_r_Project_5_580330_e;
    gettimeofday(&tv_r_Project_5_580330_s, 0);
    SW_Project_TD_5156260(tbl_JOIN_FULLOUTER_TD_6746405_output, tbl_Project_TD_5156260_output);
    gettimeofday(&tv_r_Project_5_580330_e, 0);

    struct timeval tv_r_Window_4_786569_s, tv_r_Window_4_786569_e;
    gettimeofday(&tv_r_Window_4_786569_s, 0);
    SW_Window_TD_4307433(tbl_Project_TD_5156260_output, tbl_Window_TD_4307433_output);
    gettimeofday(&tv_r_Window_4_786569_e, 0);

    struct timeval tv_r_Filter_3_304044_s, tv_r_Filter_3_304044_e;
    gettimeofday(&tv_r_Filter_3_304044_s, 0);
    SW_Filter_TD_3873404(tbl_Window_TD_4307433_output, tbl_Filter_TD_3873404_output);
    gettimeofday(&tv_r_Filter_3_304044_e, 0);

    struct timeval tv_r_Sort_2_21419_s, tv_r_Sort_2_21419_e;
    gettimeofday(&tv_r_Sort_2_21419_s, 0);
    SW_Sort_TD_2689516(tbl_Filter_TD_3873404_output, tbl_Sort_TD_2689516_output);
    gettimeofday(&tv_r_Sort_2_21419_e, 0);

    struct timeval tv_r_LocalLimit_1_807_s, tv_r_LocalLimit_1_807_e;
    gettimeofday(&tv_r_LocalLimit_1_807_s, 0);
    SW_LocalLimit_TD_178420(tbl_Sort_TD_2689516_output, tbl_LocalLimit_TD_178420_output);
    gettimeofday(&tv_r_LocalLimit_1_807_e, 0);

    struct timeval tv_r_GlobalLimit_0_158059_s, tv_r_GlobalLimit_0_158059_e;
    gettimeofday(&tv_r_GlobalLimit_0_158059_s, 0);
    SW_GlobalLimit_TD_01307(tbl_LocalLimit_TD_178420_output, tbl_GlobalLimit_TD_01307_output);
    gettimeofday(&tv_r_GlobalLimit_0_158059_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_899065_s, &tv_r_Filter_10_899065_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11660686_input: " << tbl_SerializeFromObject_TD_11660686_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_698274_s, &tv_r_Filter_10_698274_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11858691_input: " << tbl_SerializeFromObject_TD_11858691_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_247106_s, &tv_r_Filter_10_247106_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11356790_input: " << tbl_SerializeFromObject_TD_11356790_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_936386_s, &tv_r_Filter_10_936386_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11561049_input: " << tbl_SerializeFromObject_TD_11561049_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_57513_s, &tv_r_JOIN_INNER_9_57513_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10836943_output: " << tbl_Filter_TD_10836943_output.getNumRow() << " " << "tbl_Filter_TD_10761658_output: " << tbl_Filter_TD_10761658_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_43737_s, &tv_r_JOIN_INNER_9_43737_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10345630_output: " << tbl_Filter_TD_10345630_output.getNumRow() << " " << "tbl_Filter_TD_10732262_output: " << tbl_Filter_TD_10732262_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_8: " << tvdiff(&tv_r_Aggregate_8_271916_s, &tv_r_Aggregate_8_271916_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9238506_output: " << tbl_JOIN_INNER_TD_9238506_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_8: " << tvdiff(&tv_r_Aggregate_8_951066_s, &tv_r_Aggregate_8_951066_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9717571_output: " << tbl_JOIN_INNER_TD_9717571_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_7: " << tvdiff(&tv_r_Window_7_939116_s, &tv_r_Window_7_939116_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_8426435_output: " << tbl_Aggregate_TD_8426435_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_7: " << tvdiff(&tv_r_Window_7_828235_s, &tv_r_Window_7_828235_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_8282744_output: " << tbl_Aggregate_TD_8282744_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_FULLOUTER_6: " << tvdiff(&tv_r_JOIN_FULLOUTER_6_603579_s, &tv_r_JOIN_FULLOUTER_6_603579_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_7855870_output: " << tbl_Window_TD_7855870_output.getNumRow() << " " << "tbl_Window_TD_7799101_output: " << tbl_Window_TD_7799101_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_5: " << tvdiff(&tv_r_Project_5_580330_s, &tv_r_Project_5_580330_e) / 1000.0 << " ms " 
     << "tbl_JOIN_FULLOUTER_TD_6746405_output: " << tbl_JOIN_FULLOUTER_TD_6746405_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_4: " << tvdiff(&tv_r_Window_4_786569_s, &tv_r_Window_4_786569_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_5156260_output: " << tbl_Project_TD_5156260_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_304044_s, &tv_r_Filter_3_304044_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_4307433_output: " << tbl_Window_TD_4307433_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_21419_s, &tv_r_Sort_2_21419_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_3873404_output: " << tbl_Filter_TD_3873404_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_807_s, &tv_r_LocalLimit_1_807_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2689516_output: " << tbl_Sort_TD_2689516_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_158059_s, &tv_r_GlobalLimit_0_158059_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_178420_output: " << tbl_LocalLimit_TD_178420_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 8.666352 * 1000 << "ms" << std::endl; 
    return 0; 
}
