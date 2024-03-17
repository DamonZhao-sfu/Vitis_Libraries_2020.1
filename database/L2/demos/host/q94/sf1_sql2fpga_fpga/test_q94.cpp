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

#include "cfgFunc_q94.hpp" 
#include "q94.hpp" 

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
    std::cout << "NOTE:running query #94\n."; 
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
    Table tbl_Aggregate_TD_0312384_output("tbl_Aggregate_TD_0312384_output", 6100000, 3, "");
    tbl_Aggregate_TD_0312384_output.allocateHost();
    Table tbl_JOIN_INNER_TD_1453782_output("tbl_JOIN_INNER_TD_1453782_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_1453782_output.allocateHost();
    Table tbl_JOIN_INNER_TD_233645_output("tbl_JOIN_INNER_TD_233645_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_233645_output.allocateHost();
    Table tbl_Filter_TD_2974057_output("tbl_Filter_TD_2974057_output", 6100000, 1, "");
    tbl_Filter_TD_2974057_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3137012_output("tbl_JOIN_INNER_TD_3137012_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_3137012_output.allocateHost();
    Table tbl_Filter_TD_3363199_output("tbl_Filter_TD_3363199_output", 6100000, 1, "");
    tbl_Filter_TD_3363199_output.allocateHost();
    Table tbl_SerializeFromObject_TD_3180338_input;
    tbl_SerializeFromObject_TD_3180338_input = Table("web_site", web_site_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_3180338_input.addCol("web_site_sk", 4);
    tbl_SerializeFromObject_TD_3180338_input.addCol("web_company_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_3180338_input.allocateHost();
    tbl_SerializeFromObject_TD_3180338_input.loadHost();
    Table tbl_JOIN_LEFTANTI_TD_4651670_output("tbl_JOIN_LEFTANTI_TD_4651670_output", 6100000, 6, "");
    tbl_JOIN_LEFTANTI_TD_4651670_output.allocateHost();
    Table tbl_Filter_TD_4436273_output("tbl_Filter_TD_4436273_output", 6100000, 1, "");
    tbl_Filter_TD_4436273_output.allocateHost();
    Table tbl_SerializeFromObject_TD_4704706_input;
    tbl_SerializeFromObject_TD_4704706_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_4704706_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_4704706_input.addCol("ca_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_4704706_input.allocateHost();
    tbl_SerializeFromObject_TD_4704706_input.loadHost();
    Table tbl_JOIN_LEFTSEMI_TD_5499524_output("tbl_JOIN_LEFTSEMI_TD_5499524_output", 6100000, 6, "");
    tbl_JOIN_LEFTSEMI_TD_5499524_output.allocateHost();
    Table tbl_SerializeFromObject_TD_5782537_input;
    tbl_SerializeFromObject_TD_5782537_input = Table("web_returns", web_returns_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_5782537_input.addCol("wr_order_number", 8);
    tbl_SerializeFromObject_TD_5782537_input.allocateHost();
    tbl_SerializeFromObject_TD_5782537_input.loadHost();
    Table tbl_SerializeFromObject_TD_5508883_input;
    tbl_SerializeFromObject_TD_5508883_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_5508883_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_5508883_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_5508883_input.allocateHost();
    tbl_SerializeFromObject_TD_5508883_input.loadHost();
    Table tbl_Filter_TD_6146319_output("tbl_Filter_TD_6146319_output", 6100000, 7, "");
    tbl_Filter_TD_6146319_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6499892_input;
    tbl_SerializeFromObject_TD_6499892_input = Table("web_sales", web_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_6499892_input.addCol("ws_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_6499892_input.addCol("ws_order_number", 8);
    tbl_SerializeFromObject_TD_6499892_input.allocateHost();
    tbl_SerializeFromObject_TD_6499892_input.loadHost();
    Table tbl_SerializeFromObject_TD_7728411_input;
    tbl_SerializeFromObject_TD_7728411_input = Table("web_sales", web_sales_n, 7, in_dir, "orc");
    tbl_SerializeFromObject_TD_7728411_input.addCol("ws_ship_date_sk", 4);
    tbl_SerializeFromObject_TD_7728411_input.addCol("ws_ship_addr_sk", 4);
    tbl_SerializeFromObject_TD_7728411_input.addCol("ws_web_site_sk", 4);
    tbl_SerializeFromObject_TD_7728411_input.addCol("ws_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_7728411_input.addCol("ws_order_number", 8);
    tbl_SerializeFromObject_TD_7728411_input.addCol("ws_ext_ship_cost", 4);
    tbl_SerializeFromObject_TD_7728411_input.addCol("ws_net_profit", 4);
    tbl_SerializeFromObject_TD_7728411_input.allocateHost();
    tbl_SerializeFromObject_TD_7728411_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_1453782_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_233645_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_2974057_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_3137012_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_3363199_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTANTI_TD_4651670_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_4436273_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTSEMI_TD_5499524_output.allocateDevBuffer(context_h, 32);
    tbl_SerializeFromObject_TD_5782537_input.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_6146319_output.allocateDevBuffer(context_h, 32);
    tbl_SerializeFromObject_TD_6499892_input.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_1453782_cmds;
    cfg_JOIN_INNER_TD_1453782_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_1453782_gqe_join (cfg_JOIN_INNER_TD_1453782_cmds.cmd);
    cfg_JOIN_INNER_TD_1453782_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_233645_cmds;
    cfg_JOIN_INNER_TD_233645_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_233645_gqe_join (cfg_JOIN_INNER_TD_233645_cmds.cmd);
    cfg_JOIN_INNER_TD_233645_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_3137012_cmds;
    cfg_JOIN_INNER_TD_3137012_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_3137012_gqe_join (cfg_JOIN_INNER_TD_3137012_cmds.cmd);
    cfg_JOIN_INNER_TD_3137012_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTANTI_TD_4651670_cmds;
    cfg_JOIN_LEFTANTI_TD_4651670_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTANTI_TD_4651670_gqe_join (cfg_JOIN_LEFTANTI_TD_4651670_cmds.cmd);
    cfg_JOIN_LEFTANTI_TD_4651670_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_5499524_cmds;
    cfg_JOIN_LEFTSEMI_TD_5499524_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_5499524_gqe_join (cfg_JOIN_LEFTSEMI_TD_5499524_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_5499524_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_1453782;
    krnl_JOIN_INNER_TD_1453782 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_1453782.setup(tbl_JOIN_INNER_TD_233645_output, tbl_Filter_TD_2974057_output, tbl_JOIN_INNER_TD_1453782_output, cfg_JOIN_INNER_TD_1453782_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_233645;
    krnl_JOIN_INNER_TD_233645 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_233645.setup(tbl_JOIN_INNER_TD_3137012_output, tbl_Filter_TD_3363199_output, tbl_JOIN_INNER_TD_233645_output, cfg_JOIN_INNER_TD_233645_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_3137012;
    krnl_JOIN_INNER_TD_3137012 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_3137012.setup(tbl_JOIN_LEFTANTI_TD_4651670_output, tbl_Filter_TD_4436273_output, tbl_JOIN_INNER_TD_3137012_output, cfg_JOIN_INNER_TD_3137012_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTANTI_TD_4651670;
    krnl_JOIN_LEFTANTI_TD_4651670 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTANTI_TD_4651670.setup(tbl_SerializeFromObject_TD_5782537_input, tbl_JOIN_LEFTSEMI_TD_5499524_output, tbl_JOIN_LEFTANTI_TD_4651670_output, cfg_JOIN_LEFTANTI_TD_4651670_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_5499524;
    krnl_JOIN_LEFTSEMI_TD_5499524 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTSEMI_TD_5499524.setup(tbl_SerializeFromObject_TD_6499892_input, tbl_Filter_TD_6146319_output, tbl_JOIN_LEFTSEMI_TD_5499524_output, cfg_JOIN_LEFTSEMI_TD_5499524_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_1453782;
    trans_JOIN_INNER_TD_1453782.setq(q_h);
    trans_JOIN_INNER_TD_1453782.add(&(cfg_JOIN_INNER_TD_1453782_cmds));
    transEngine trans_JOIN_INNER_TD_1453782_out;
    trans_JOIN_INNER_TD_1453782_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_233645;
    trans_JOIN_INNER_TD_233645.setq(q_h);
    trans_JOIN_INNER_TD_233645.add(&(cfg_JOIN_INNER_TD_233645_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_3137012;
    trans_JOIN_INNER_TD_3137012.setq(q_h);
    trans_JOIN_INNER_TD_3137012.add(&(cfg_JOIN_INNER_TD_3137012_cmds));
    q_h.finish();
    transEngine trans_JOIN_LEFTANTI_TD_4651670;
    trans_JOIN_LEFTANTI_TD_4651670.setq(q_h);
    trans_JOIN_LEFTANTI_TD_4651670.add(&(cfg_JOIN_LEFTANTI_TD_4651670_cmds));
    trans_JOIN_LEFTANTI_TD_4651670.add(&(tbl_SerializeFromObject_TD_5782537_input));
    q_h.finish();
    transEngine trans_JOIN_LEFTSEMI_TD_5499524;
    trans_JOIN_LEFTSEMI_TD_5499524.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_5499524.add(&(cfg_JOIN_LEFTSEMI_TD_5499524_cmds));
    trans_JOIN_LEFTSEMI_TD_5499524.add(&(tbl_SerializeFromObject_TD_6499892_input));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_1453782;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_1453782;
    std::vector<cl::Event> events_JOIN_INNER_TD_1453782;
    events_h2d_wr_JOIN_INNER_TD_1453782.resize(1);
    events_d2h_rd_JOIN_INNER_TD_1453782.resize(1);
    events_JOIN_INNER_TD_1453782.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_1453782;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_1453782;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_233645;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_233645;
    std::vector<cl::Event> events_JOIN_INNER_TD_233645;
    events_h2d_wr_JOIN_INNER_TD_233645.resize(1);
    events_d2h_rd_JOIN_INNER_TD_233645.resize(1);
    events_JOIN_INNER_TD_233645.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_233645;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_233645;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_3137012;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_3137012;
    std::vector<cl::Event> events_JOIN_INNER_TD_3137012;
    events_h2d_wr_JOIN_INNER_TD_3137012.resize(1);
    events_d2h_rd_JOIN_INNER_TD_3137012.resize(1);
    events_JOIN_INNER_TD_3137012.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_3137012;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_3137012;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTANTI_TD_4651670;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTANTI_TD_4651670;
    std::vector<cl::Event> events_JOIN_LEFTANTI_TD_4651670;
    events_h2d_wr_JOIN_LEFTANTI_TD_4651670.resize(1);
    events_d2h_rd_JOIN_LEFTANTI_TD_4651670.resize(1);
    events_JOIN_LEFTANTI_TD_4651670.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTANTI_TD_4651670;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTANTI_TD_4651670;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_5499524;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_5499524;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_5499524;
    events_h2d_wr_JOIN_LEFTSEMI_TD_5499524.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_5499524.resize(1);
    events_JOIN_LEFTSEMI_TD_5499524.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_5499524;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_5499524;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_6_383107_s, tv_r_Filter_6_383107_e;
    gettimeofday(&tv_r_Filter_6_383107_s, 0);
    SW_Filter_TD_6146319(tbl_SerializeFromObject_TD_7728411_input, tbl_Filter_TD_6146319_output);
    gettimeofday(&tv_r_Filter_6_383107_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_5_94589_s, tv_r_JOIN_LEFTSEMI_5_94589_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_5_94589_s, 0);
    trans_JOIN_LEFTSEMI_TD_5499524.add(&(tbl_Filter_TD_6146319_output));
    trans_JOIN_LEFTSEMI_TD_5499524.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_5499524), &(events_h2d_wr_JOIN_LEFTSEMI_TD_5499524[0]));
    events_grp_JOIN_LEFTSEMI_TD_5499524.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_5499524[0]);
    krnl_JOIN_LEFTSEMI_TD_5499524.run(0, &(events_grp_JOIN_LEFTSEMI_TD_5499524), &(events_JOIN_LEFTSEMI_TD_5499524[0]));
    gettimeofday(&tv_r_JOIN_LEFTSEMI_5_94589_e, 0);

    struct timeval tv_r_Filter_4_326519_s, tv_r_Filter_4_326519_e;
    gettimeofday(&tv_r_Filter_4_326519_s, 0);
    SW_Filter_TD_4436273(tbl_SerializeFromObject_TD_5508883_input, tbl_Filter_TD_4436273_output);
    gettimeofday(&tv_r_Filter_4_326519_e, 0);

    struct timeval tv_r_JOIN_LEFTANTI_4_697810_s, tv_r_JOIN_LEFTANTI_4_697810_e;
    gettimeofday(&tv_r_JOIN_LEFTANTI_4_697810_s, 0);
    prev_events_grp_JOIN_LEFTANTI_TD_4651670.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_5499524[0]);
    trans_JOIN_LEFTANTI_TD_4651670.host2dev(0, &(prev_events_grp_JOIN_LEFTANTI_TD_4651670), &(events_h2d_wr_JOIN_LEFTANTI_TD_4651670[0]));
    events_grp_JOIN_LEFTANTI_TD_4651670.push_back(events_h2d_wr_JOIN_LEFTANTI_TD_4651670[0]);
    events_grp_JOIN_LEFTANTI_TD_4651670.push_back(events_JOIN_LEFTSEMI_TD_5499524[0]);
    krnl_JOIN_LEFTANTI_TD_4651670.run(0, &(events_grp_JOIN_LEFTANTI_TD_4651670), &(events_JOIN_LEFTANTI_TD_4651670[0]));
    gettimeofday(&tv_r_JOIN_LEFTANTI_4_697810_e, 0);

    struct timeval tv_r_Filter_3_651825_s, tv_r_Filter_3_651825_e;
    gettimeofday(&tv_r_Filter_3_651825_s, 0);
    SW_Filter_TD_3363199(tbl_SerializeFromObject_TD_4704706_input, tbl_Filter_TD_3363199_output);
    gettimeofday(&tv_r_Filter_3_651825_e, 0);

    struct timeval tv_r_JOIN_INNER_3_331110_s, tv_r_JOIN_INNER_3_331110_e;
    gettimeofday(&tv_r_JOIN_INNER_3_331110_s, 0);
    prev_events_grp_JOIN_INNER_TD_3137012.push_back(events_h2d_wr_JOIN_LEFTANTI_TD_4651670[0]);
    trans_JOIN_INNER_TD_3137012.add(&(tbl_Filter_TD_4436273_output));
    trans_JOIN_INNER_TD_3137012.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_3137012), &(events_h2d_wr_JOIN_INNER_TD_3137012[0]));
    events_grp_JOIN_INNER_TD_3137012.push_back(events_h2d_wr_JOIN_INNER_TD_3137012[0]);
    events_grp_JOIN_INNER_TD_3137012.push_back(events_JOIN_LEFTANTI_TD_4651670[0]);
    krnl_JOIN_INNER_TD_3137012.run(0, &(events_grp_JOIN_INNER_TD_3137012), &(events_JOIN_INNER_TD_3137012[0]));
    gettimeofday(&tv_r_JOIN_INNER_3_331110_e, 0);

    struct timeval tv_r_Filter_2_786629_s, tv_r_Filter_2_786629_e;
    gettimeofday(&tv_r_Filter_2_786629_s, 0);
    SW_Filter_TD_2974057(tbl_SerializeFromObject_TD_3180338_input, tbl_Filter_TD_2974057_output);
    gettimeofday(&tv_r_Filter_2_786629_e, 0);

    struct timeval tv_r_JOIN_INNER_2_896486_s, tv_r_JOIN_INNER_2_896486_e;
    gettimeofday(&tv_r_JOIN_INNER_2_896486_s, 0);
    prev_events_grp_JOIN_INNER_TD_233645.push_back(events_h2d_wr_JOIN_INNER_TD_3137012[0]);
    trans_JOIN_INNER_TD_233645.add(&(tbl_Filter_TD_3363199_output));
    trans_JOIN_INNER_TD_233645.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_233645), &(events_h2d_wr_JOIN_INNER_TD_233645[0]));
    events_grp_JOIN_INNER_TD_233645.push_back(events_h2d_wr_JOIN_INNER_TD_233645[0]);
    events_grp_JOIN_INNER_TD_233645.push_back(events_JOIN_INNER_TD_3137012[0]);
    krnl_JOIN_INNER_TD_233645.run(0, &(events_grp_JOIN_INNER_TD_233645), &(events_JOIN_INNER_TD_233645[0]));
    gettimeofday(&tv_r_JOIN_INNER_2_896486_e, 0);

    struct timeval tv_r_JOIN_INNER_1_691234_s, tv_r_JOIN_INNER_1_691234_e;
    gettimeofday(&tv_r_JOIN_INNER_1_691234_s, 0);
    prev_events_grp_JOIN_INNER_TD_1453782.push_back(events_h2d_wr_JOIN_INNER_TD_233645[0]);
    trans_JOIN_INNER_TD_1453782.add(&(tbl_Filter_TD_2974057_output));
    trans_JOIN_INNER_TD_1453782.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_1453782), &(events_h2d_wr_JOIN_INNER_TD_1453782[0]));
    events_grp_JOIN_INNER_TD_1453782.push_back(events_h2d_wr_JOIN_INNER_TD_1453782[0]);
    events_grp_JOIN_INNER_TD_1453782.push_back(events_JOIN_INNER_TD_233645[0]);
    krnl_JOIN_INNER_TD_1453782.run(0, &(events_grp_JOIN_INNER_TD_1453782), &(events_JOIN_INNER_TD_1453782[0]));
    
    trans_JOIN_INNER_TD_1453782_out.add(&(tbl_JOIN_INNER_TD_1453782_output));
    trans_JOIN_INNER_TD_1453782_out.dev2host(0, &(events_JOIN_INNER_TD_1453782), &(events_d2h_rd_JOIN_INNER_TD_1453782[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_1_691234_e, 0);

    struct timeval tv_r_Aggregate_0_479691_s, tv_r_Aggregate_0_479691_e;
    gettimeofday(&tv_r_Aggregate_0_479691_s, 0);
    SW_Aggregate_TD_0312384(tbl_JOIN_INNER_TD_1453782_output, tbl_Aggregate_TD_0312384_output);
    gettimeofday(&tv_r_Aggregate_0_479691_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_383107_s, &tv_r_Filter_6_383107_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7728411_input: " << tbl_SerializeFromObject_TD_7728411_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_5: " << tvdiff(&tv_r_JOIN_LEFTSEMI_5_94589_s, &tv_r_JOIN_LEFTSEMI_5_94589_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6146319_output: " << tbl_Filter_TD_6146319_output.getNumRow() << " " << "tbl_SerializeFromObject_TD_6499892_input: " << tbl_SerializeFromObject_TD_6499892_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_326519_s, &tv_r_Filter_4_326519_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5508883_input: " << tbl_SerializeFromObject_TD_5508883_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTANTI_4: " << tvdiff(&tv_r_JOIN_LEFTANTI_4_697810_s, &tv_r_JOIN_LEFTANTI_4_697810_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTSEMI_TD_5499524_output: " << tbl_JOIN_LEFTSEMI_TD_5499524_output.getNumRow() << " " << "tbl_SerializeFromObject_TD_5782537_input: " << tbl_SerializeFromObject_TD_5782537_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_651825_s, &tv_r_Filter_3_651825_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_4704706_input: " << tbl_SerializeFromObject_TD_4704706_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_331110_s, &tv_r_JOIN_INNER_3_331110_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTANTI_TD_4651670_output: " << tbl_JOIN_LEFTANTI_TD_4651670_output.getNumRow() << " " << "tbl_Filter_TD_4436273_output: " << tbl_Filter_TD_4436273_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_786629_s, &tv_r_Filter_2_786629_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3180338_input: " << tbl_SerializeFromObject_TD_3180338_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_2: " << tvdiff(&tv_r_JOIN_INNER_2_896486_s, &tv_r_JOIN_INNER_2_896486_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3137012_output: " << tbl_JOIN_INNER_TD_3137012_output.getNumRow() << " " << "tbl_Filter_TD_3363199_output: " << tbl_Filter_TD_3363199_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_1: " << tvdiff(&tv_r_JOIN_INNER_1_691234_s, &tv_r_JOIN_INNER_1_691234_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_233645_output: " << tbl_JOIN_INNER_TD_233645_output.getNumRow() << " " << "tbl_Filter_TD_2974057_output: " << tbl_Filter_TD_2974057_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_0: " << tvdiff(&tv_r_Aggregate_0_479691_s, &tv_r_Aggregate_0_479691_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_1453782_output: " << tbl_JOIN_INNER_TD_1453782_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.5079192 * 1000 << "ms" << std::endl; 
    return 0; 
}
