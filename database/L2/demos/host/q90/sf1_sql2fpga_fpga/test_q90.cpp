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

#include "cfgFunc_q90.hpp" 
#include "q90.hpp" 

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
    std::cout << "NOTE:running query #90\n."; 
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
    Table tbl_Project_TD_0381653_output("tbl_Project_TD_0381653_output", 6100000, 1, "");
    tbl_Project_TD_0381653_output.allocateHost();
    Table tbl_JOIN_CROSS_TD_1827726_output("tbl_JOIN_CROSS_TD_1827726_output", 6100000, 2, "");
    tbl_JOIN_CROSS_TD_1827726_output.allocateHost();
    Table tbl_Aggregate_TD_2774199_output("tbl_Aggregate_TD_2774199_output", 6100000, 1, "");
    tbl_Aggregate_TD_2774199_output.allocateHost();
    Table tbl_Aggregate_TD_233819_output("tbl_Aggregate_TD_233819_output", 6100000, 1, "");
    tbl_Aggregate_TD_233819_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3686188_output("tbl_JOIN_INNER_TD_3686188_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_3686188_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3747960_output("tbl_JOIN_INNER_TD_3747960_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_3747960_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4724095_output("tbl_JOIN_INNER_TD_4724095_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_4724095_output.allocateHost();
    Table tbl_Filter_TD_4964076_output("tbl_Filter_TD_4964076_output", 6100000, 1, "");
    tbl_Filter_TD_4964076_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4611216_output("tbl_JOIN_INNER_TD_4611216_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_4611216_output.allocateHost();
    Table tbl_Filter_TD_4575207_output("tbl_Filter_TD_4575207_output", 6100000, 1, "");
    tbl_Filter_TD_4575207_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5681927_output("tbl_JOIN_INNER_TD_5681927_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_5681927_output.allocateHost();
    Table tbl_Filter_TD_5853126_output("tbl_Filter_TD_5853126_output", 6100000, 1, "");
    tbl_Filter_TD_5853126_output.allocateHost();
    Table tbl_SerializeFromObject_TD_5502004_input;
    tbl_SerializeFromObject_TD_5502004_input = Table("web_page", web_page_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_5502004_input.addCol("wp_web_page_sk", 4);
    tbl_SerializeFromObject_TD_5502004_input.addCol("wp_char_count", 4);
    tbl_SerializeFromObject_TD_5502004_input.allocateHost();
    tbl_SerializeFromObject_TD_5502004_input.loadHost();
    Table tbl_JOIN_INNER_TD_5389505_output("tbl_JOIN_INNER_TD_5389505_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_5389505_output.allocateHost();
    Table tbl_Filter_TD_5362484_output("tbl_Filter_TD_5362484_output", 6100000, 1, "");
    tbl_Filter_TD_5362484_output.allocateHost();
    Table tbl_SerializeFromObject_TD_5457751_input;
    tbl_SerializeFromObject_TD_5457751_input = Table("web_page", web_page_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_5457751_input.addCol("wp_web_page_sk", 4);
    tbl_SerializeFromObject_TD_5457751_input.addCol("wp_char_count", 4);
    tbl_SerializeFromObject_TD_5457751_input.allocateHost();
    tbl_SerializeFromObject_TD_5457751_input.loadHost();
    Table tbl_Filter_TD_6639300_output("tbl_Filter_TD_6639300_output", 6100000, 3, "");
    tbl_Filter_TD_6639300_output.allocateHost();
    Table tbl_Filter_TD_6791015_output("tbl_Filter_TD_6791015_output", 6100000, 1, "");
    tbl_Filter_TD_6791015_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6903122_input;
    tbl_SerializeFromObject_TD_6903122_input = Table("time_dim", time_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_6903122_input.addCol("t_time_sk", 4);
    tbl_SerializeFromObject_TD_6903122_input.addCol("t_hour", 4);
    tbl_SerializeFromObject_TD_6903122_input.allocateHost();
    tbl_SerializeFromObject_TD_6903122_input.loadHost();
    Table tbl_Filter_TD_6871743_output("tbl_Filter_TD_6871743_output", 6100000, 3, "");
    tbl_Filter_TD_6871743_output.allocateHost();
    Table tbl_Filter_TD_69504_output("tbl_Filter_TD_69504_output", 6100000, 1, "");
    tbl_Filter_TD_69504_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6428190_input;
    tbl_SerializeFromObject_TD_6428190_input = Table("time_dim", time_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_6428190_input.addCol("t_time_sk", 4);
    tbl_SerializeFromObject_TD_6428190_input.addCol("t_hour", 4);
    tbl_SerializeFromObject_TD_6428190_input.allocateHost();
    tbl_SerializeFromObject_TD_6428190_input.loadHost();
    Table tbl_SerializeFromObject_TD_785125_input;
    tbl_SerializeFromObject_TD_785125_input = Table("web_sales", web_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_785125_input.addCol("ws_sold_time_sk", 4);
    tbl_SerializeFromObject_TD_785125_input.addCol("ws_ship_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_785125_input.addCol("ws_web_page_sk", 4);
    tbl_SerializeFromObject_TD_785125_input.allocateHost();
    tbl_SerializeFromObject_TD_785125_input.loadHost();
    Table tbl_SerializeFromObject_TD_7883869_input;
    tbl_SerializeFromObject_TD_7883869_input = Table("household_demographics", household_demographics_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7883869_input.addCol("hd_demo_sk", 4);
    tbl_SerializeFromObject_TD_7883869_input.addCol("hd_dep_count", 4);
    tbl_SerializeFromObject_TD_7883869_input.allocateHost();
    tbl_SerializeFromObject_TD_7883869_input.loadHost();
    Table tbl_SerializeFromObject_TD_7681509_input;
    tbl_SerializeFromObject_TD_7681509_input = Table("web_sales", web_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7681509_input.addCol("ws_sold_time_sk", 4);
    tbl_SerializeFromObject_TD_7681509_input.addCol("ws_ship_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_7681509_input.addCol("ws_web_page_sk", 4);
    tbl_SerializeFromObject_TD_7681509_input.allocateHost();
    tbl_SerializeFromObject_TD_7681509_input.loadHost();
    Table tbl_SerializeFromObject_TD_7214634_input;
    tbl_SerializeFromObject_TD_7214634_input = Table("household_demographics", household_demographics_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7214634_input.addCol("hd_demo_sk", 4);
    tbl_SerializeFromObject_TD_7214634_input.addCol("hd_dep_count", 4);
    tbl_SerializeFromObject_TD_7214634_input.allocateHost();
    tbl_SerializeFromObject_TD_7214634_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_3686188_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_3747960_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_4724095_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_4964076_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_4611216_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_4575207_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_5681927_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_5853126_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_5389505_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_5362484_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_6639300_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_6791015_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_6871743_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_69504_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_3686188_cmds;
    cfg_JOIN_INNER_TD_3686188_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_3686188_gqe_join (cfg_JOIN_INNER_TD_3686188_cmds.cmd);
    cfg_JOIN_INNER_TD_3686188_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_3747960_cmds;
    cfg_JOIN_INNER_TD_3747960_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_3747960_gqe_join (cfg_JOIN_INNER_TD_3747960_cmds.cmd);
    cfg_JOIN_INNER_TD_3747960_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_4724095_cmds;
    cfg_JOIN_INNER_TD_4724095_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_4724095_gqe_join (cfg_JOIN_INNER_TD_4724095_cmds.cmd);
    cfg_JOIN_INNER_TD_4724095_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_4611216_cmds;
    cfg_JOIN_INNER_TD_4611216_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_4611216_gqe_join (cfg_JOIN_INNER_TD_4611216_cmds.cmd);
    cfg_JOIN_INNER_TD_4611216_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_5681927_cmds;
    cfg_JOIN_INNER_TD_5681927_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_5681927_gqe_join (cfg_JOIN_INNER_TD_5681927_cmds.cmd);
    cfg_JOIN_INNER_TD_5681927_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_5389505_cmds;
    cfg_JOIN_INNER_TD_5389505_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_5389505_gqe_join (cfg_JOIN_INNER_TD_5389505_cmds.cmd);
    cfg_JOIN_INNER_TD_5389505_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_3686188;
    krnl_JOIN_INNER_TD_3686188 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_3686188.setup(tbl_JOIN_INNER_TD_4724095_output, tbl_Filter_TD_4964076_output, tbl_JOIN_INNER_TD_3686188_output, cfg_JOIN_INNER_TD_3686188_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_3747960;
    krnl_JOIN_INNER_TD_3747960 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_3747960.setup(tbl_JOIN_INNER_TD_4611216_output, tbl_Filter_TD_4575207_output, tbl_JOIN_INNER_TD_3747960_output, cfg_JOIN_INNER_TD_3747960_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_4724095;
    krnl_JOIN_INNER_TD_4724095 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_4724095.setup(tbl_JOIN_INNER_TD_5681927_output, tbl_Filter_TD_5853126_output, tbl_JOIN_INNER_TD_4724095_output, cfg_JOIN_INNER_TD_4724095_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_4611216;
    krnl_JOIN_INNER_TD_4611216 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_4611216.setup(tbl_JOIN_INNER_TD_5389505_output, tbl_Filter_TD_5362484_output, tbl_JOIN_INNER_TD_4611216_output, cfg_JOIN_INNER_TD_4611216_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_5681927;
    krnl_JOIN_INNER_TD_5681927 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_5681927.setup(tbl_Filter_TD_6639300_output, tbl_Filter_TD_6791015_output, tbl_JOIN_INNER_TD_5681927_output, cfg_JOIN_INNER_TD_5681927_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_5389505;
    krnl_JOIN_INNER_TD_5389505 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_5389505.setup(tbl_Filter_TD_6871743_output, tbl_Filter_TD_69504_output, tbl_JOIN_INNER_TD_5389505_output, cfg_JOIN_INNER_TD_5389505_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_3686188;
    trans_JOIN_INNER_TD_3686188.setq(q_h);
    trans_JOIN_INNER_TD_3686188.add(&(cfg_JOIN_INNER_TD_3686188_cmds));
    transEngine trans_JOIN_INNER_TD_3686188_out;
    trans_JOIN_INNER_TD_3686188_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_3747960;
    trans_JOIN_INNER_TD_3747960.setq(q_h);
    trans_JOIN_INNER_TD_3747960.add(&(cfg_JOIN_INNER_TD_3747960_cmds));
    transEngine trans_JOIN_INNER_TD_3747960_out;
    trans_JOIN_INNER_TD_3747960_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_4724095;
    trans_JOIN_INNER_TD_4724095.setq(q_h);
    trans_JOIN_INNER_TD_4724095.add(&(cfg_JOIN_INNER_TD_4724095_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_4611216;
    trans_JOIN_INNER_TD_4611216.setq(q_h);
    trans_JOIN_INNER_TD_4611216.add(&(cfg_JOIN_INNER_TD_4611216_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_5681927;
    trans_JOIN_INNER_TD_5681927.setq(q_h);
    trans_JOIN_INNER_TD_5681927.add(&(cfg_JOIN_INNER_TD_5681927_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_5389505;
    trans_JOIN_INNER_TD_5389505.setq(q_h);
    trans_JOIN_INNER_TD_5389505.add(&(cfg_JOIN_INNER_TD_5389505_cmds));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_3686188;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_3686188;
    std::vector<cl::Event> events_JOIN_INNER_TD_3686188;
    events_h2d_wr_JOIN_INNER_TD_3686188.resize(1);
    events_d2h_rd_JOIN_INNER_TD_3686188.resize(1);
    events_JOIN_INNER_TD_3686188.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_3686188;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_3686188;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_3747960;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_3747960;
    std::vector<cl::Event> events_JOIN_INNER_TD_3747960;
    events_h2d_wr_JOIN_INNER_TD_3747960.resize(1);
    events_d2h_rd_JOIN_INNER_TD_3747960.resize(1);
    events_JOIN_INNER_TD_3747960.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_3747960;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_3747960;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_4724095;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_4724095;
    std::vector<cl::Event> events_JOIN_INNER_TD_4724095;
    events_h2d_wr_JOIN_INNER_TD_4724095.resize(1);
    events_d2h_rd_JOIN_INNER_TD_4724095.resize(1);
    events_JOIN_INNER_TD_4724095.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_4724095;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_4724095;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_4611216;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_4611216;
    std::vector<cl::Event> events_JOIN_INNER_TD_4611216;
    events_h2d_wr_JOIN_INNER_TD_4611216.resize(1);
    events_d2h_rd_JOIN_INNER_TD_4611216.resize(1);
    events_JOIN_INNER_TD_4611216.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_4611216;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_4611216;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_5681927;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_5681927;
    std::vector<cl::Event> events_JOIN_INNER_TD_5681927;
    events_h2d_wr_JOIN_INNER_TD_5681927.resize(1);
    events_d2h_rd_JOIN_INNER_TD_5681927.resize(1);
    events_JOIN_INNER_TD_5681927.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_5681927;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_5681927;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_5389505;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_5389505;
    std::vector<cl::Event> events_JOIN_INNER_TD_5389505;
    events_h2d_wr_JOIN_INNER_TD_5389505.resize(1);
    events_d2h_rd_JOIN_INNER_TD_5389505.resize(1);
    events_JOIN_INNER_TD_5389505.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_5389505;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_5389505;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_6_673376_s, tv_r_Filter_6_673376_e;
    gettimeofday(&tv_r_Filter_6_673376_s, 0);
    SW_Filter_TD_69504(tbl_SerializeFromObject_TD_7214634_input, tbl_Filter_TD_69504_output);
    gettimeofday(&tv_r_Filter_6_673376_e, 0);

    struct timeval tv_r_Filter_6_476785_s, tv_r_Filter_6_476785_e;
    gettimeofday(&tv_r_Filter_6_476785_s, 0);
    SW_Filter_TD_6871743(tbl_SerializeFromObject_TD_7681509_input, tbl_Filter_TD_6871743_output);
    gettimeofday(&tv_r_Filter_6_476785_e, 0);

    struct timeval tv_r_Filter_6_24500_s, tv_r_Filter_6_24500_e;
    gettimeofday(&tv_r_Filter_6_24500_s, 0);
    SW_Filter_TD_6791015(tbl_SerializeFromObject_TD_7883869_input, tbl_Filter_TD_6791015_output);
    gettimeofday(&tv_r_Filter_6_24500_e, 0);

    struct timeval tv_r_Filter_6_971938_s, tv_r_Filter_6_971938_e;
    gettimeofday(&tv_r_Filter_6_971938_s, 0);
    SW_Filter_TD_6639300(tbl_SerializeFromObject_TD_785125_input, tbl_Filter_TD_6639300_output);
    gettimeofday(&tv_r_Filter_6_971938_e, 0);

    struct timeval tv_r_Filter_5_842868_s, tv_r_Filter_5_842868_e;
    gettimeofday(&tv_r_Filter_5_842868_s, 0);
    SW_Filter_TD_5362484(tbl_SerializeFromObject_TD_6428190_input, tbl_Filter_TD_5362484_output);
    gettimeofday(&tv_r_Filter_5_842868_e, 0);

    struct timeval tv_r_JOIN_INNER_5_693076_s, tv_r_JOIN_INNER_5_693076_e;
    gettimeofday(&tv_r_JOIN_INNER_5_693076_s, 0);
    trans_JOIN_INNER_TD_5389505.add(&(tbl_Filter_TD_6871743_output));
    trans_JOIN_INNER_TD_5389505.add(&(tbl_Filter_TD_69504_output));
    trans_JOIN_INNER_TD_5389505.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_5389505), &(events_h2d_wr_JOIN_INNER_TD_5389505[0]));
    events_grp_JOIN_INNER_TD_5389505.push_back(events_h2d_wr_JOIN_INNER_TD_5389505[0]);
    krnl_JOIN_INNER_TD_5389505.run(0, &(events_grp_JOIN_INNER_TD_5389505), &(events_JOIN_INNER_TD_5389505[0]));
    gettimeofday(&tv_r_JOIN_INNER_5_693076_e, 0);

    struct timeval tv_r_Filter_5_917234_s, tv_r_Filter_5_917234_e;
    gettimeofday(&tv_r_Filter_5_917234_s, 0);
    SW_Filter_TD_5853126(tbl_SerializeFromObject_TD_6903122_input, tbl_Filter_TD_5853126_output);
    gettimeofday(&tv_r_Filter_5_917234_e, 0);

    struct timeval tv_r_JOIN_INNER_5_822039_s, tv_r_JOIN_INNER_5_822039_e;
    gettimeofday(&tv_r_JOIN_INNER_5_822039_s, 0);
    trans_JOIN_INNER_TD_5681927.add(&(tbl_Filter_TD_6639300_output));
    trans_JOIN_INNER_TD_5681927.add(&(tbl_Filter_TD_6791015_output));
    trans_JOIN_INNER_TD_5681927.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_5681927), &(events_h2d_wr_JOIN_INNER_TD_5681927[0]));
    events_grp_JOIN_INNER_TD_5681927.push_back(events_h2d_wr_JOIN_INNER_TD_5681927[0]);
    krnl_JOIN_INNER_TD_5681927.run(0, &(events_grp_JOIN_INNER_TD_5681927), &(events_JOIN_INNER_TD_5681927[0]));
    gettimeofday(&tv_r_JOIN_INNER_5_822039_e, 0);

    struct timeval tv_r_Filter_4_959645_s, tv_r_Filter_4_959645_e;
    gettimeofday(&tv_r_Filter_4_959645_s, 0);
    SW_Filter_TD_4575207(tbl_SerializeFromObject_TD_5457751_input, tbl_Filter_TD_4575207_output);
    gettimeofday(&tv_r_Filter_4_959645_e, 0);

    struct timeval tv_r_JOIN_INNER_4_302068_s, tv_r_JOIN_INNER_4_302068_e;
    gettimeofday(&tv_r_JOIN_INNER_4_302068_s, 0);
    prev_events_grp_JOIN_INNER_TD_4611216.push_back(events_h2d_wr_JOIN_INNER_TD_5389505[0]);
    trans_JOIN_INNER_TD_4611216.add(&(tbl_Filter_TD_5362484_output));
    trans_JOIN_INNER_TD_4611216.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_4611216), &(events_h2d_wr_JOIN_INNER_TD_4611216[0]));
    events_grp_JOIN_INNER_TD_4611216.push_back(events_h2d_wr_JOIN_INNER_TD_4611216[0]);
    events_grp_JOIN_INNER_TD_4611216.push_back(events_JOIN_INNER_TD_5389505[0]);
    krnl_JOIN_INNER_TD_4611216.run(0, &(events_grp_JOIN_INNER_TD_4611216), &(events_JOIN_INNER_TD_4611216[0]));
    gettimeofday(&tv_r_JOIN_INNER_4_302068_e, 0);

    struct timeval tv_r_Filter_4_417824_s, tv_r_Filter_4_417824_e;
    gettimeofday(&tv_r_Filter_4_417824_s, 0);
    SW_Filter_TD_4964076(tbl_SerializeFromObject_TD_5502004_input, tbl_Filter_TD_4964076_output);
    gettimeofday(&tv_r_Filter_4_417824_e, 0);

    struct timeval tv_r_JOIN_INNER_4_652273_s, tv_r_JOIN_INNER_4_652273_e;
    gettimeofday(&tv_r_JOIN_INNER_4_652273_s, 0);
    prev_events_grp_JOIN_INNER_TD_4724095.push_back(events_h2d_wr_JOIN_INNER_TD_5681927[0]);
    trans_JOIN_INNER_TD_4724095.add(&(tbl_Filter_TD_5853126_output));
    trans_JOIN_INNER_TD_4724095.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_4724095), &(events_h2d_wr_JOIN_INNER_TD_4724095[0]));
    events_grp_JOIN_INNER_TD_4724095.push_back(events_h2d_wr_JOIN_INNER_TD_4724095[0]);
    events_grp_JOIN_INNER_TD_4724095.push_back(events_JOIN_INNER_TD_5681927[0]);
    krnl_JOIN_INNER_TD_4724095.run(0, &(events_grp_JOIN_INNER_TD_4724095), &(events_JOIN_INNER_TD_4724095[0]));
    gettimeofday(&tv_r_JOIN_INNER_4_652273_e, 0);

    struct timeval tv_r_JOIN_INNER_3_576965_s, tv_r_JOIN_INNER_3_576965_e;
    gettimeofday(&tv_r_JOIN_INNER_3_576965_s, 0);
    prev_events_grp_JOIN_INNER_TD_3747960.push_back(events_h2d_wr_JOIN_INNER_TD_4611216[0]);
    trans_JOIN_INNER_TD_3747960.add(&(tbl_Filter_TD_4575207_output));
    trans_JOIN_INNER_TD_3747960.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_3747960), &(events_h2d_wr_JOIN_INNER_TD_3747960[0]));
    events_grp_JOIN_INNER_TD_3747960.push_back(events_h2d_wr_JOIN_INNER_TD_3747960[0]);
    events_grp_JOIN_INNER_TD_3747960.push_back(events_JOIN_INNER_TD_4611216[0]);
    krnl_JOIN_INNER_TD_3747960.run(0, &(events_grp_JOIN_INNER_TD_3747960), &(events_JOIN_INNER_TD_3747960[0]));
    
    trans_JOIN_INNER_TD_3747960_out.add(&(tbl_JOIN_INNER_TD_3747960_output));
    trans_JOIN_INNER_TD_3747960_out.dev2host(0, &(events_JOIN_INNER_TD_3747960), &(events_d2h_rd_JOIN_INNER_TD_3747960[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_3_576965_e, 0);

    struct timeval tv_r_JOIN_INNER_3_58600_s, tv_r_JOIN_INNER_3_58600_e;
    gettimeofday(&tv_r_JOIN_INNER_3_58600_s, 0);
    prev_events_grp_JOIN_INNER_TD_3686188.push_back(events_h2d_wr_JOIN_INNER_TD_4724095[0]);
    trans_JOIN_INNER_TD_3686188.add(&(tbl_Filter_TD_4964076_output));
    trans_JOIN_INNER_TD_3686188.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_3686188), &(events_h2d_wr_JOIN_INNER_TD_3686188[0]));
    events_grp_JOIN_INNER_TD_3686188.push_back(events_h2d_wr_JOIN_INNER_TD_3686188[0]);
    events_grp_JOIN_INNER_TD_3686188.push_back(events_JOIN_INNER_TD_4724095[0]);
    krnl_JOIN_INNER_TD_3686188.run(0, &(events_grp_JOIN_INNER_TD_3686188), &(events_JOIN_INNER_TD_3686188[0]));
    
    trans_JOIN_INNER_TD_3686188_out.add(&(tbl_JOIN_INNER_TD_3686188_output));
    trans_JOIN_INNER_TD_3686188_out.dev2host(0, &(events_JOIN_INNER_TD_3686188), &(events_d2h_rd_JOIN_INNER_TD_3686188[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_3_58600_e, 0);

    struct timeval tv_r_Aggregate_2_675381_s, tv_r_Aggregate_2_675381_e;
    gettimeofday(&tv_r_Aggregate_2_675381_s, 0);
    SW_Aggregate_TD_233819(tbl_JOIN_INNER_TD_3747960_output, tbl_Aggregate_TD_233819_output);
    gettimeofday(&tv_r_Aggregate_2_675381_e, 0);

    struct timeval tv_r_Aggregate_2_490481_s, tv_r_Aggregate_2_490481_e;
    gettimeofday(&tv_r_Aggregate_2_490481_s, 0);
    SW_Aggregate_TD_2774199(tbl_JOIN_INNER_TD_3686188_output, tbl_Aggregate_TD_2774199_output);
    gettimeofday(&tv_r_Aggregate_2_490481_e, 0);

    struct timeval tv_r_JOIN_CROSS_1_916121_s, tv_r_JOIN_CROSS_1_916121_e;
    gettimeofday(&tv_r_JOIN_CROSS_1_916121_s, 0);
    SW_JOIN_CROSS_TD_1827726(tbl_Aggregate_TD_2774199_output, tbl_Aggregate_TD_233819_output, tbl_JOIN_CROSS_TD_1827726_output);
    gettimeofday(&tv_r_JOIN_CROSS_1_916121_e, 0);

    struct timeval tv_r_Project_0_744651_s, tv_r_Project_0_744651_e;
    gettimeofday(&tv_r_Project_0_744651_s, 0);
    SW_Project_TD_0381653(tbl_JOIN_CROSS_TD_1827726_output, tbl_Project_TD_0381653_output);
    gettimeofday(&tv_r_Project_0_744651_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_673376_s, &tv_r_Filter_6_673376_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7214634_input: " << tbl_SerializeFromObject_TD_7214634_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_476785_s, &tv_r_Filter_6_476785_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7681509_input: " << tbl_SerializeFromObject_TD_7681509_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_24500_s, &tv_r_Filter_6_24500_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7883869_input: " << tbl_SerializeFromObject_TD_7883869_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_971938_s, &tv_r_Filter_6_971938_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_785125_input: " << tbl_SerializeFromObject_TD_785125_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_842868_s, &tv_r_Filter_5_842868_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6428190_input: " << tbl_SerializeFromObject_TD_6428190_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_693076_s, &tv_r_JOIN_INNER_5_693076_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6871743_output: " << tbl_Filter_TD_6871743_output.getNumRow() << " " << "tbl_Filter_TD_69504_output: " << tbl_Filter_TD_69504_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_917234_s, &tv_r_Filter_5_917234_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6903122_input: " << tbl_SerializeFromObject_TD_6903122_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_822039_s, &tv_r_JOIN_INNER_5_822039_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6639300_output: " << tbl_Filter_TD_6639300_output.getNumRow() << " " << "tbl_Filter_TD_6791015_output: " << tbl_Filter_TD_6791015_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_959645_s, &tv_r_Filter_4_959645_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5457751_input: " << tbl_SerializeFromObject_TD_5457751_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_302068_s, &tv_r_JOIN_INNER_4_302068_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5389505_output: " << tbl_JOIN_INNER_TD_5389505_output.getNumRow() << " " << "tbl_Filter_TD_5362484_output: " << tbl_Filter_TD_5362484_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_417824_s, &tv_r_Filter_4_417824_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5502004_input: " << tbl_SerializeFromObject_TD_5502004_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_652273_s, &tv_r_JOIN_INNER_4_652273_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5681927_output: " << tbl_JOIN_INNER_TD_5681927_output.getNumRow() << " " << "tbl_Filter_TD_5853126_output: " << tbl_Filter_TD_5853126_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_576965_s, &tv_r_JOIN_INNER_3_576965_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4611216_output: " << tbl_JOIN_INNER_TD_4611216_output.getNumRow() << " " << "tbl_Filter_TD_4575207_output: " << tbl_Filter_TD_4575207_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_58600_s, &tv_r_JOIN_INNER_3_58600_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4724095_output: " << tbl_JOIN_INNER_TD_4724095_output.getNumRow() << " " << "tbl_Filter_TD_4964076_output: " << tbl_Filter_TD_4964076_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_2: " << tvdiff(&tv_r_Aggregate_2_675381_s, &tv_r_Aggregate_2_675381_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3747960_output: " << tbl_JOIN_INNER_TD_3747960_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_2: " << tvdiff(&tv_r_Aggregate_2_490481_s, &tv_r_Aggregate_2_490481_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3686188_output: " << tbl_JOIN_INNER_TD_3686188_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_CROSS_1: " << tvdiff(&tv_r_JOIN_CROSS_1_916121_s, &tv_r_JOIN_CROSS_1_916121_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_2774199_output: " << tbl_Aggregate_TD_2774199_output.getNumRow() << " " << "tbl_Aggregate_TD_233819_output: " << tbl_Aggregate_TD_233819_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_0: " << tvdiff(&tv_r_Project_0_744651_s, &tv_r_Project_0_744651_e) / 1000.0 << " ms " 
     << "tbl_JOIN_CROSS_TD_1827726_output: " << tbl_JOIN_CROSS_TD_1827726_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 0.8309381 * 1000 << "ms" << std::endl; 
    return 0; 
}
