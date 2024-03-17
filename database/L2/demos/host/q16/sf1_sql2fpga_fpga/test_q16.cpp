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

#include "cfgFunc_q16.hpp" 
#include "q16.hpp" 

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
    std::cout << "NOTE:running query #16\n."; 
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
    Table tbl_Aggregate_TD_0403217_output("tbl_Aggregate_TD_0403217_output", 6100000, 3, "");
    tbl_Aggregate_TD_0403217_output.allocateHost();
    Table tbl_JOIN_INNER_TD_1729688_output("tbl_JOIN_INNER_TD_1729688_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_1729688_output.allocateHost();
    Table tbl_JOIN_INNER_TD_286385_output("tbl_JOIN_INNER_TD_286385_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_286385_output.allocateHost();
    Table tbl_Filter_TD_2432498_output("tbl_Filter_TD_2432498_output", 6100000, 1, "");
    tbl_Filter_TD_2432498_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3402955_output("tbl_JOIN_INNER_TD_3402955_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_3402955_output.allocateHost();
    Table tbl_Filter_TD_3340251_output("tbl_Filter_TD_3340251_output", 6100000, 1, "");
    tbl_Filter_TD_3340251_output.allocateHost();
    Table tbl_SerializeFromObject_TD_3412899_input;
    tbl_SerializeFromObject_TD_3412899_input = Table("call_center", call_center_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_3412899_input.addCol("cc_call_center_sk", 4);
    tbl_SerializeFromObject_TD_3412899_input.addCol("cc_county", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_3412899_input.allocateHost();
    tbl_SerializeFromObject_TD_3412899_input.loadHost();
    Table tbl_JOIN_LEFTANTI_TD_4223389_output("tbl_JOIN_LEFTANTI_TD_4223389_output", 6100000, 6, "");
    tbl_JOIN_LEFTANTI_TD_4223389_output.allocateHost();
    Table tbl_Filter_TD_4694564_output("tbl_Filter_TD_4694564_output", 6100000, 1, "");
    tbl_Filter_TD_4694564_output.allocateHost();
    Table tbl_SerializeFromObject_TD_4155524_input;
    tbl_SerializeFromObject_TD_4155524_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_4155524_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_4155524_input.addCol("ca_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_4155524_input.allocateHost();
    tbl_SerializeFromObject_TD_4155524_input.loadHost();
    Table tbl_JOIN_LEFTSEMI_TD_5989449_output("tbl_JOIN_LEFTSEMI_TD_5989449_output", 6100000, 6, "");
    tbl_JOIN_LEFTSEMI_TD_5989449_output.allocateHost();
    Table tbl_SerializeFromObject_TD_5578761_input;
    tbl_SerializeFromObject_TD_5578761_input = Table("catalog_returns", catalog_returns_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_5578761_input.addCol("cr_order_number", 8);
    tbl_SerializeFromObject_TD_5578761_input.allocateHost();
    tbl_SerializeFromObject_TD_5578761_input.loadHost();
    Table tbl_SerializeFromObject_TD_5596905_input;
    tbl_SerializeFromObject_TD_5596905_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_5596905_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_5596905_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_5596905_input.allocateHost();
    tbl_SerializeFromObject_TD_5596905_input.loadHost();
    Table tbl_Filter_TD_6793448_output("tbl_Filter_TD_6793448_output", 6100000, 7, "");
    tbl_Filter_TD_6793448_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6890169_input;
    tbl_SerializeFromObject_TD_6890169_input = Table("catalog_sales", catalog_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_6890169_input.addCol("cs_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_6890169_input.addCol("cs_order_number", 8);
    tbl_SerializeFromObject_TD_6890169_input.allocateHost();
    tbl_SerializeFromObject_TD_6890169_input.loadHost();
    Table tbl_SerializeFromObject_TD_7182984_input;
    tbl_SerializeFromObject_TD_7182984_input = Table("catalog_sales", catalog_sales_n, 7, in_dir, "orc");
    tbl_SerializeFromObject_TD_7182984_input.addCol("cs_ship_date_sk", 4);
    tbl_SerializeFromObject_TD_7182984_input.addCol("cs_ship_addr_sk", 4);
    tbl_SerializeFromObject_TD_7182984_input.addCol("cs_call_center_sk", 4);
    tbl_SerializeFromObject_TD_7182984_input.addCol("cs_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_7182984_input.addCol("cs_order_number", 8);
    tbl_SerializeFromObject_TD_7182984_input.addCol("cs_ext_ship_cost", 4);
    tbl_SerializeFromObject_TD_7182984_input.addCol("cs_net_profit", 4);
    tbl_SerializeFromObject_TD_7182984_input.allocateHost();
    tbl_SerializeFromObject_TD_7182984_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_1729688_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_286385_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_2432498_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_3402955_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_3340251_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTANTI_TD_4223389_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_4694564_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTSEMI_TD_5989449_output.allocateDevBuffer(context_h, 32);
    tbl_SerializeFromObject_TD_5578761_input.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_6793448_output.allocateDevBuffer(context_h, 32);
    tbl_SerializeFromObject_TD_6890169_input.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_1729688_cmds;
    cfg_JOIN_INNER_TD_1729688_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_1729688_gqe_join (cfg_JOIN_INNER_TD_1729688_cmds.cmd);
    cfg_JOIN_INNER_TD_1729688_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_286385_cmds;
    cfg_JOIN_INNER_TD_286385_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_286385_gqe_join (cfg_JOIN_INNER_TD_286385_cmds.cmd);
    cfg_JOIN_INNER_TD_286385_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_3402955_cmds;
    cfg_JOIN_INNER_TD_3402955_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_3402955_gqe_join (cfg_JOIN_INNER_TD_3402955_cmds.cmd);
    cfg_JOIN_INNER_TD_3402955_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTANTI_TD_4223389_cmds;
    cfg_JOIN_LEFTANTI_TD_4223389_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTANTI_TD_4223389_gqe_join (cfg_JOIN_LEFTANTI_TD_4223389_cmds.cmd);
    cfg_JOIN_LEFTANTI_TD_4223389_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_5989449_cmds;
    cfg_JOIN_LEFTSEMI_TD_5989449_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_5989449_gqe_join (cfg_JOIN_LEFTSEMI_TD_5989449_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_5989449_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_1729688;
    krnl_JOIN_INNER_TD_1729688 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_1729688.setup(tbl_JOIN_INNER_TD_286385_output, tbl_Filter_TD_2432498_output, tbl_JOIN_INNER_TD_1729688_output, cfg_JOIN_INNER_TD_1729688_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_286385;
    krnl_JOIN_INNER_TD_286385 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_286385.setup(tbl_JOIN_INNER_TD_3402955_output, tbl_Filter_TD_3340251_output, tbl_JOIN_INNER_TD_286385_output, cfg_JOIN_INNER_TD_286385_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_3402955;
    krnl_JOIN_INNER_TD_3402955 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_3402955.setup(tbl_JOIN_LEFTANTI_TD_4223389_output, tbl_Filter_TD_4694564_output, tbl_JOIN_INNER_TD_3402955_output, cfg_JOIN_INNER_TD_3402955_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTANTI_TD_4223389;
    krnl_JOIN_LEFTANTI_TD_4223389 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTANTI_TD_4223389.setup(tbl_SerializeFromObject_TD_5578761_input, tbl_JOIN_LEFTSEMI_TD_5989449_output, tbl_JOIN_LEFTANTI_TD_4223389_output, cfg_JOIN_LEFTANTI_TD_4223389_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_5989449;
    krnl_JOIN_LEFTSEMI_TD_5989449 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTSEMI_TD_5989449.setup(tbl_SerializeFromObject_TD_6890169_input, tbl_Filter_TD_6793448_output, tbl_JOIN_LEFTSEMI_TD_5989449_output, cfg_JOIN_LEFTSEMI_TD_5989449_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_1729688;
    trans_JOIN_INNER_TD_1729688.setq(q_h);
    trans_JOIN_INNER_TD_1729688.add(&(cfg_JOIN_INNER_TD_1729688_cmds));
    transEngine trans_JOIN_INNER_TD_1729688_out;
    trans_JOIN_INNER_TD_1729688_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_286385;
    trans_JOIN_INNER_TD_286385.setq(q_h);
    trans_JOIN_INNER_TD_286385.add(&(cfg_JOIN_INNER_TD_286385_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_3402955;
    trans_JOIN_INNER_TD_3402955.setq(q_h);
    trans_JOIN_INNER_TD_3402955.add(&(cfg_JOIN_INNER_TD_3402955_cmds));
    q_h.finish();
    transEngine trans_JOIN_LEFTANTI_TD_4223389;
    trans_JOIN_LEFTANTI_TD_4223389.setq(q_h);
    trans_JOIN_LEFTANTI_TD_4223389.add(&(cfg_JOIN_LEFTANTI_TD_4223389_cmds));
    trans_JOIN_LEFTANTI_TD_4223389.add(&(tbl_SerializeFromObject_TD_5578761_input));
    q_h.finish();
    transEngine trans_JOIN_LEFTSEMI_TD_5989449;
    trans_JOIN_LEFTSEMI_TD_5989449.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_5989449.add(&(cfg_JOIN_LEFTSEMI_TD_5989449_cmds));
    trans_JOIN_LEFTSEMI_TD_5989449.add(&(tbl_SerializeFromObject_TD_6890169_input));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_1729688;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_1729688;
    std::vector<cl::Event> events_JOIN_INNER_TD_1729688;
    events_h2d_wr_JOIN_INNER_TD_1729688.resize(1);
    events_d2h_rd_JOIN_INNER_TD_1729688.resize(1);
    events_JOIN_INNER_TD_1729688.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_1729688;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_1729688;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_286385;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_286385;
    std::vector<cl::Event> events_JOIN_INNER_TD_286385;
    events_h2d_wr_JOIN_INNER_TD_286385.resize(1);
    events_d2h_rd_JOIN_INNER_TD_286385.resize(1);
    events_JOIN_INNER_TD_286385.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_286385;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_286385;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_3402955;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_3402955;
    std::vector<cl::Event> events_JOIN_INNER_TD_3402955;
    events_h2d_wr_JOIN_INNER_TD_3402955.resize(1);
    events_d2h_rd_JOIN_INNER_TD_3402955.resize(1);
    events_JOIN_INNER_TD_3402955.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_3402955;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_3402955;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTANTI_TD_4223389;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTANTI_TD_4223389;
    std::vector<cl::Event> events_JOIN_LEFTANTI_TD_4223389;
    events_h2d_wr_JOIN_LEFTANTI_TD_4223389.resize(1);
    events_d2h_rd_JOIN_LEFTANTI_TD_4223389.resize(1);
    events_JOIN_LEFTANTI_TD_4223389.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTANTI_TD_4223389;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTANTI_TD_4223389;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_5989449;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_5989449;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_5989449;
    events_h2d_wr_JOIN_LEFTSEMI_TD_5989449.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_5989449.resize(1);
    events_JOIN_LEFTSEMI_TD_5989449.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_5989449;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_5989449;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_6_341389_s, tv_r_Filter_6_341389_e;
    gettimeofday(&tv_r_Filter_6_341389_s, 0);
    SW_Filter_TD_6793448(tbl_SerializeFromObject_TD_7182984_input, tbl_Filter_TD_6793448_output);
    gettimeofday(&tv_r_Filter_6_341389_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_5_348690_s, tv_r_JOIN_LEFTSEMI_5_348690_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_5_348690_s, 0);
    trans_JOIN_LEFTSEMI_TD_5989449.add(&(tbl_Filter_TD_6793448_output));
    trans_JOIN_LEFTSEMI_TD_5989449.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_5989449), &(events_h2d_wr_JOIN_LEFTSEMI_TD_5989449[0]));
    events_grp_JOIN_LEFTSEMI_TD_5989449.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_5989449[0]);
    krnl_JOIN_LEFTSEMI_TD_5989449.run(0, &(events_grp_JOIN_LEFTSEMI_TD_5989449), &(events_JOIN_LEFTSEMI_TD_5989449[0]));
    gettimeofday(&tv_r_JOIN_LEFTSEMI_5_348690_e, 0);

    struct timeval tv_r_Filter_4_874657_s, tv_r_Filter_4_874657_e;
    gettimeofday(&tv_r_Filter_4_874657_s, 0);
    SW_Filter_TD_4694564(tbl_SerializeFromObject_TD_5596905_input, tbl_Filter_TD_4694564_output);
    gettimeofday(&tv_r_Filter_4_874657_e, 0);

    struct timeval tv_r_JOIN_LEFTANTI_4_907839_s, tv_r_JOIN_LEFTANTI_4_907839_e;
    gettimeofday(&tv_r_JOIN_LEFTANTI_4_907839_s, 0);
    prev_events_grp_JOIN_LEFTANTI_TD_4223389.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_5989449[0]);
    trans_JOIN_LEFTANTI_TD_4223389.host2dev(0, &(prev_events_grp_JOIN_LEFTANTI_TD_4223389), &(events_h2d_wr_JOIN_LEFTANTI_TD_4223389[0]));
    events_grp_JOIN_LEFTANTI_TD_4223389.push_back(events_h2d_wr_JOIN_LEFTANTI_TD_4223389[0]);
    events_grp_JOIN_LEFTANTI_TD_4223389.push_back(events_JOIN_LEFTSEMI_TD_5989449[0]);
    krnl_JOIN_LEFTANTI_TD_4223389.run(0, &(events_grp_JOIN_LEFTANTI_TD_4223389), &(events_JOIN_LEFTANTI_TD_4223389[0]));
    gettimeofday(&tv_r_JOIN_LEFTANTI_4_907839_e, 0);

    struct timeval tv_r_Filter_3_644369_s, tv_r_Filter_3_644369_e;
    gettimeofday(&tv_r_Filter_3_644369_s, 0);
    SW_Filter_TD_3340251(tbl_SerializeFromObject_TD_4155524_input, tbl_Filter_TD_3340251_output);
    gettimeofday(&tv_r_Filter_3_644369_e, 0);

    struct timeval tv_r_JOIN_INNER_3_63902_s, tv_r_JOIN_INNER_3_63902_e;
    gettimeofday(&tv_r_JOIN_INNER_3_63902_s, 0);
    prev_events_grp_JOIN_INNER_TD_3402955.push_back(events_h2d_wr_JOIN_LEFTANTI_TD_4223389[0]);
    trans_JOIN_INNER_TD_3402955.add(&(tbl_Filter_TD_4694564_output));
    trans_JOIN_INNER_TD_3402955.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_3402955), &(events_h2d_wr_JOIN_INNER_TD_3402955[0]));
    events_grp_JOIN_INNER_TD_3402955.push_back(events_h2d_wr_JOIN_INNER_TD_3402955[0]);
    events_grp_JOIN_INNER_TD_3402955.push_back(events_JOIN_LEFTANTI_TD_4223389[0]);
    krnl_JOIN_INNER_TD_3402955.run(0, &(events_grp_JOIN_INNER_TD_3402955), &(events_JOIN_INNER_TD_3402955[0]));
    gettimeofday(&tv_r_JOIN_INNER_3_63902_e, 0);

    struct timeval tv_r_Filter_2_411547_s, tv_r_Filter_2_411547_e;
    gettimeofday(&tv_r_Filter_2_411547_s, 0);
    SW_Filter_TD_2432498(tbl_SerializeFromObject_TD_3412899_input, tbl_Filter_TD_2432498_output);
    gettimeofday(&tv_r_Filter_2_411547_e, 0);

    struct timeval tv_r_JOIN_INNER_2_578339_s, tv_r_JOIN_INNER_2_578339_e;
    gettimeofday(&tv_r_JOIN_INNER_2_578339_s, 0);
    prev_events_grp_JOIN_INNER_TD_286385.push_back(events_h2d_wr_JOIN_INNER_TD_3402955[0]);
    trans_JOIN_INNER_TD_286385.add(&(tbl_Filter_TD_3340251_output));
    trans_JOIN_INNER_TD_286385.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_286385), &(events_h2d_wr_JOIN_INNER_TD_286385[0]));
    events_grp_JOIN_INNER_TD_286385.push_back(events_h2d_wr_JOIN_INNER_TD_286385[0]);
    events_grp_JOIN_INNER_TD_286385.push_back(events_JOIN_INNER_TD_3402955[0]);
    krnl_JOIN_INNER_TD_286385.run(0, &(events_grp_JOIN_INNER_TD_286385), &(events_JOIN_INNER_TD_286385[0]));
    gettimeofday(&tv_r_JOIN_INNER_2_578339_e, 0);

    struct timeval tv_r_JOIN_INNER_1_451650_s, tv_r_JOIN_INNER_1_451650_e;
    gettimeofday(&tv_r_JOIN_INNER_1_451650_s, 0);
    prev_events_grp_JOIN_INNER_TD_1729688.push_back(events_h2d_wr_JOIN_INNER_TD_286385[0]);
    trans_JOIN_INNER_TD_1729688.add(&(tbl_Filter_TD_2432498_output));
    trans_JOIN_INNER_TD_1729688.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_1729688), &(events_h2d_wr_JOIN_INNER_TD_1729688[0]));
    events_grp_JOIN_INNER_TD_1729688.push_back(events_h2d_wr_JOIN_INNER_TD_1729688[0]);
    events_grp_JOIN_INNER_TD_1729688.push_back(events_JOIN_INNER_TD_286385[0]);
    krnl_JOIN_INNER_TD_1729688.run(0, &(events_grp_JOIN_INNER_TD_1729688), &(events_JOIN_INNER_TD_1729688[0]));
    
    trans_JOIN_INNER_TD_1729688_out.add(&(tbl_JOIN_INNER_TD_1729688_output));
    trans_JOIN_INNER_TD_1729688_out.dev2host(0, &(events_JOIN_INNER_TD_1729688), &(events_d2h_rd_JOIN_INNER_TD_1729688[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_1_451650_e, 0);

    struct timeval tv_r_Aggregate_0_842362_s, tv_r_Aggregate_0_842362_e;
    gettimeofday(&tv_r_Aggregate_0_842362_s, 0);
    SW_Aggregate_TD_0403217(tbl_JOIN_INNER_TD_1729688_output, tbl_Aggregate_TD_0403217_output);
    gettimeofday(&tv_r_Aggregate_0_842362_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_341389_s, &tv_r_Filter_6_341389_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7182984_input: " << tbl_SerializeFromObject_TD_7182984_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_5: " << tvdiff(&tv_r_JOIN_LEFTSEMI_5_348690_s, &tv_r_JOIN_LEFTSEMI_5_348690_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6793448_output: " << tbl_Filter_TD_6793448_output.getNumRow() << " " << "tbl_SerializeFromObject_TD_6890169_input: " << tbl_SerializeFromObject_TD_6890169_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_874657_s, &tv_r_Filter_4_874657_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5596905_input: " << tbl_SerializeFromObject_TD_5596905_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTANTI_4: " << tvdiff(&tv_r_JOIN_LEFTANTI_4_907839_s, &tv_r_JOIN_LEFTANTI_4_907839_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTSEMI_TD_5989449_output: " << tbl_JOIN_LEFTSEMI_TD_5989449_output.getNumRow() << " " << "tbl_SerializeFromObject_TD_5578761_input: " << tbl_SerializeFromObject_TD_5578761_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_644369_s, &tv_r_Filter_3_644369_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_4155524_input: " << tbl_SerializeFromObject_TD_4155524_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_63902_s, &tv_r_JOIN_INNER_3_63902_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTANTI_TD_4223389_output: " << tbl_JOIN_LEFTANTI_TD_4223389_output.getNumRow() << " " << "tbl_Filter_TD_4694564_output: " << tbl_Filter_TD_4694564_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_411547_s, &tv_r_Filter_2_411547_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3412899_input: " << tbl_SerializeFromObject_TD_3412899_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_2: " << tvdiff(&tv_r_JOIN_INNER_2_578339_s, &tv_r_JOIN_INNER_2_578339_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3402955_output: " << tbl_JOIN_INNER_TD_3402955_output.getNumRow() << " " << "tbl_Filter_TD_3340251_output: " << tbl_Filter_TD_3340251_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_1: " << tvdiff(&tv_r_JOIN_INNER_1_451650_s, &tv_r_JOIN_INNER_1_451650_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_286385_output: " << tbl_JOIN_INNER_TD_286385_output.getNumRow() << " " << "tbl_Filter_TD_2432498_output: " << tbl_Filter_TD_2432498_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_0: " << tvdiff(&tv_r_Aggregate_0_842362_s, &tv_r_Aggregate_0_842362_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_1729688_output: " << tbl_JOIN_INNER_TD_1729688_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.170717 * 1000 << "ms" << std::endl; 
    return 0; 
}
