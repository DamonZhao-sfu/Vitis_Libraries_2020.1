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

#include "cfgFunc_q30.hpp" 
#include "q30.hpp" 

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
    std::cout << "NOTE:running query #30\n."; 
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
    Table tbl_GlobalLimit_TD_0403706_output("tbl_GlobalLimit_TD_0403706_output", 6100000, 13, "");
    tbl_GlobalLimit_TD_0403706_output.allocateHost();
    Table tbl_LocalLimit_TD_1637703_output("tbl_LocalLimit_TD_1637703_output", 6100000, 13, "");
    tbl_LocalLimit_TD_1637703_output.allocateHost();
    Table tbl_Sort_TD_2173178_output("tbl_Sort_TD_2173178_output", 6100000, 13, "");
    tbl_Sort_TD_2173178_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3343747_output("tbl_JOIN_INNER_TD_3343747_output", 6100000, 13, "");
    tbl_JOIN_INNER_TD_3343747_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4971542_output("tbl_JOIN_INNER_TD_4971542_output", 6100000, 14, "");
    tbl_JOIN_INNER_TD_4971542_output.allocateHost();
    Table tbl_Filter_TD_4514666_output("tbl_Filter_TD_4514666_output", 6100000, 1, "");
    tbl_Filter_TD_4514666_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5149717_output("tbl_JOIN_INNER_TD_5149717_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_5149717_output.allocateHost();
    Table tbl_Filter_TD_5834503_output("tbl_Filter_TD_5834503_output", 6100000, 14, "");
    tbl_Filter_TD_5834503_output.allocateHost();
    Table tbl_SerializeFromObject_TD_5865613_input;
    tbl_SerializeFromObject_TD_5865613_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_5865613_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_5865613_input.addCol("ca_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_5865613_input.allocateHost();
    tbl_SerializeFromObject_TD_5865613_input.loadHost();
    Table tbl_Filter_TD_6966344_output("tbl_Filter_TD_6966344_output", 6100000, 3, "");
    tbl_Filter_TD_6966344_output.allocateHost();
    Table tbl_Filter_TD_6751120_output("tbl_Filter_TD_6751120_output", 6100000, 2, "");
    tbl_Filter_TD_6751120_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6271956_input;
    tbl_SerializeFromObject_TD_6271956_input = Table("customer", customer_n, 14, in_dir, "orc");
    tbl_SerializeFromObject_TD_6271956_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_6271956_input.addCol("c_customer_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6271956_input.addCol("c_current_addr_sk", 4);
    tbl_SerializeFromObject_TD_6271956_input.addCol("c_salutation", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6271956_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6271956_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6271956_input.addCol("c_preferred_cust_flag", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6271956_input.addCol("c_birth_day", 4);
    tbl_SerializeFromObject_TD_6271956_input.addCol("c_birth_month", 4);
    tbl_SerializeFromObject_TD_6271956_input.addCol("c_birth_year", 4);
    tbl_SerializeFromObject_TD_6271956_input.addCol("c_birth_country", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6271956_input.addCol("c_login", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6271956_input.addCol("c_email_address", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6271956_input.addCol("c_last_review_date", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6271956_input.allocateHost();
    tbl_SerializeFromObject_TD_6271956_input.loadHost();
    Table tbl_Aggregate_TD_7493319_output("tbl_Aggregate_TD_7493319_output", 6100000, 3, "");
    tbl_Aggregate_TD_7493319_output.allocateHost();
    Table tbl_Aggregate_TD_7575826_output("tbl_Aggregate_TD_7575826_output", 6100000, 2, "");
    tbl_Aggregate_TD_7575826_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8601458_output("tbl_JOIN_INNER_TD_8601458_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_8601458_output.allocateHost();
    Table tbl_Aggregate_TD_8936138_output("tbl_Aggregate_TD_8936138_output", 6100000, 2, "");
    tbl_Aggregate_TD_8936138_output.allocateHost();
    Table tbl_JOIN_INNER_TD_9405197_output("tbl_JOIN_INNER_TD_9405197_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_9405197_output.allocateHost();
    Table tbl_Filter_TD_9477549_output("tbl_Filter_TD_9477549_output", 6100000, 2, "");
    tbl_Filter_TD_9477549_output.allocateHost();
    Table tbl_JOIN_INNER_TD_9976930_output("tbl_JOIN_INNER_TD_9976930_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_9976930_output.allocateHost();
    Table tbl_Filter_TD_10910584_output("tbl_Filter_TD_10910584_output", 6100000, 4, "");
    tbl_Filter_TD_10910584_output.allocateHost();
    Table tbl_Filter_TD_10123525_output("tbl_Filter_TD_10123525_output", 6100000, 1, "");
    tbl_Filter_TD_10123525_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10545088_input;
    tbl_SerializeFromObject_TD_10545088_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10545088_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_10545088_input.addCol("ca_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10545088_input.allocateHost();
    tbl_SerializeFromObject_TD_10545088_input.loadHost();
    Table tbl_JOIN_INNER_TD_10280374_output("tbl_JOIN_INNER_TD_10280374_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_10280374_output.allocateHost();
    Table tbl_Filter_TD_1050616_output("tbl_Filter_TD_1050616_output", 6100000, 2, "");
    tbl_Filter_TD_1050616_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11399790_input;
    tbl_SerializeFromObject_TD_11399790_input = Table("web_returns", web_returns_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_11399790_input.addCol("wr_returned_date_sk", 4);
    tbl_SerializeFromObject_TD_11399790_input.addCol("wr_returning_customer_sk", 4);
    tbl_SerializeFromObject_TD_11399790_input.addCol("wr_returning_addr_sk", 4);
    tbl_SerializeFromObject_TD_11399790_input.addCol("wr_return_amt", 4);
    tbl_SerializeFromObject_TD_11399790_input.allocateHost();
    tbl_SerializeFromObject_TD_11399790_input.loadHost();
    Table tbl_SerializeFromObject_TD_11131620_input;
    tbl_SerializeFromObject_TD_11131620_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11131620_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_11131620_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_11131620_input.allocateHost();
    tbl_SerializeFromObject_TD_11131620_input.loadHost();
    Table tbl_Filter_TD_11560775_output("tbl_Filter_TD_11560775_output", 6100000, 4, "");
    tbl_Filter_TD_11560775_output.allocateHost();
    Table tbl_Filter_TD_1184101_output("tbl_Filter_TD_1184101_output", 6100000, 1, "");
    tbl_Filter_TD_1184101_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11716935_input;
    tbl_SerializeFromObject_TD_11716935_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11716935_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_11716935_input.addCol("ca_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11716935_input.allocateHost();
    tbl_SerializeFromObject_TD_11716935_input.loadHost();
    Table tbl_SerializeFromObject_TD_12940974_input;
    tbl_SerializeFromObject_TD_12940974_input = Table("web_returns", web_returns_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_12940974_input.addCol("wr_returned_date_sk", 4);
    tbl_SerializeFromObject_TD_12940974_input.addCol("wr_returning_customer_sk", 4);
    tbl_SerializeFromObject_TD_12940974_input.addCol("wr_returning_addr_sk", 4);
    tbl_SerializeFromObject_TD_12940974_input.addCol("wr_return_amt", 4);
    tbl_SerializeFromObject_TD_12940974_input.allocateHost();
    tbl_SerializeFromObject_TD_12940974_input.loadHost();
    Table tbl_SerializeFromObject_TD_12313967_input;
    tbl_SerializeFromObject_TD_12313967_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12313967_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_12313967_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_12313967_input.allocateHost();
    tbl_SerializeFromObject_TD_12313967_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_9405197_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10910584_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10123525_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_10280374_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11560775_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_1184101_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_9405197_cmds;
    cfg_JOIN_INNER_TD_9405197_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_9405197_gqe_join (cfg_JOIN_INNER_TD_9405197_cmds.cmd);
    cfg_JOIN_INNER_TD_9405197_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_10280374_cmds;
    cfg_JOIN_INNER_TD_10280374_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_10280374_gqe_join (cfg_JOIN_INNER_TD_10280374_cmds.cmd);
    cfg_JOIN_INNER_TD_10280374_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_9405197;
    krnl_JOIN_INNER_TD_9405197 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_9405197.setup(tbl_Filter_TD_10910584_output, tbl_Filter_TD_10123525_output, tbl_JOIN_INNER_TD_9405197_output, cfg_JOIN_INNER_TD_9405197_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_10280374;
    krnl_JOIN_INNER_TD_10280374 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_10280374.setup(tbl_Filter_TD_11560775_output, tbl_Filter_TD_1184101_output, tbl_JOIN_INNER_TD_10280374_output, cfg_JOIN_INNER_TD_10280374_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_9405197;
    trans_JOIN_INNER_TD_9405197.setq(q_h);
    trans_JOIN_INNER_TD_9405197.add(&(cfg_JOIN_INNER_TD_9405197_cmds));
    transEngine trans_JOIN_INNER_TD_9405197_out;
    trans_JOIN_INNER_TD_9405197_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_10280374;
    trans_JOIN_INNER_TD_10280374.setq(q_h);
    trans_JOIN_INNER_TD_10280374.add(&(cfg_JOIN_INNER_TD_10280374_cmds));
    transEngine trans_JOIN_INNER_TD_10280374_out;
    trans_JOIN_INNER_TD_10280374_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_9405197;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_9405197;
    std::vector<cl::Event> events_JOIN_INNER_TD_9405197;
    events_h2d_wr_JOIN_INNER_TD_9405197.resize(1);
    events_d2h_rd_JOIN_INNER_TD_9405197.resize(1);
    events_JOIN_INNER_TD_9405197.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_9405197;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_9405197;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_10280374;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_10280374;
    std::vector<cl::Event> events_JOIN_INNER_TD_10280374;
    events_h2d_wr_JOIN_INNER_TD_10280374.resize(1);
    events_d2h_rd_JOIN_INNER_TD_10280374.resize(1);
    events_JOIN_INNER_TD_10280374.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_10280374;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_10280374;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_11_731016_s, tv_r_Filter_11_731016_e;
    gettimeofday(&tv_r_Filter_11_731016_s, 0);
    SW_Filter_TD_1184101(tbl_SerializeFromObject_TD_12313967_input, tbl_Filter_TD_1184101_output);
    gettimeofday(&tv_r_Filter_11_731016_e, 0);

    struct timeval tv_r_Filter_11_49456_s, tv_r_Filter_11_49456_e;
    gettimeofday(&tv_r_Filter_11_49456_s, 0);
    SW_Filter_TD_11560775(tbl_SerializeFromObject_TD_12940974_input, tbl_Filter_TD_11560775_output);
    gettimeofday(&tv_r_Filter_11_49456_e, 0);

    struct timeval tv_r_Filter_10_519488_s, tv_r_Filter_10_519488_e;
    gettimeofday(&tv_r_Filter_10_519488_s, 0);
    SW_Filter_TD_1050616(tbl_SerializeFromObject_TD_11716935_input, tbl_Filter_TD_1050616_output);
    gettimeofday(&tv_r_Filter_10_519488_e, 0);

    struct timeval tv_r_JOIN_INNER_10_593488_s, tv_r_JOIN_INNER_10_593488_e;
    gettimeofday(&tv_r_JOIN_INNER_10_593488_s, 0);
    trans_JOIN_INNER_TD_10280374.add(&(tbl_Filter_TD_11560775_output));
    trans_JOIN_INNER_TD_10280374.add(&(tbl_Filter_TD_1184101_output));
    trans_JOIN_INNER_TD_10280374.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_10280374), &(events_h2d_wr_JOIN_INNER_TD_10280374[0]));
    events_grp_JOIN_INNER_TD_10280374.push_back(events_h2d_wr_JOIN_INNER_TD_10280374[0]);
    krnl_JOIN_INNER_TD_10280374.run(0, &(events_grp_JOIN_INNER_TD_10280374), &(events_JOIN_INNER_TD_10280374[0]));
    
    trans_JOIN_INNER_TD_10280374_out.add(&(tbl_JOIN_INNER_TD_10280374_output));
    trans_JOIN_INNER_TD_10280374_out.dev2host(0, &(events_JOIN_INNER_TD_10280374), &(events_d2h_rd_JOIN_INNER_TD_10280374[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_10_593488_e, 0);

    struct timeval tv_r_Filter_10_65082_s, tv_r_Filter_10_65082_e;
    gettimeofday(&tv_r_Filter_10_65082_s, 0);
    SW_Filter_TD_10123525(tbl_SerializeFromObject_TD_11131620_input, tbl_Filter_TD_10123525_output);
    gettimeofday(&tv_r_Filter_10_65082_e, 0);

    struct timeval tv_r_Filter_10_20753_s, tv_r_Filter_10_20753_e;
    gettimeofday(&tv_r_Filter_10_20753_s, 0);
    SW_Filter_TD_10910584(tbl_SerializeFromObject_TD_11399790_input, tbl_Filter_TD_10910584_output);
    gettimeofday(&tv_r_Filter_10_20753_e, 0);

    struct timeval tv_r_JOIN_INNER_9_992581_s, tv_r_JOIN_INNER_9_992581_e;
    gettimeofday(&tv_r_JOIN_INNER_9_992581_s, 0);
    SW_JOIN_INNER_TD_9976930(tbl_JOIN_INNER_TD_10280374_output, tbl_Filter_TD_1050616_output, tbl_JOIN_INNER_TD_9976930_output);
    gettimeofday(&tv_r_JOIN_INNER_9_992581_e, 0);

    struct timeval tv_r_Filter_9_341828_s, tv_r_Filter_9_341828_e;
    gettimeofday(&tv_r_Filter_9_341828_s, 0);
    SW_Filter_TD_9477549(tbl_SerializeFromObject_TD_10545088_input, tbl_Filter_TD_9477549_output);
    gettimeofday(&tv_r_Filter_9_341828_e, 0);

    struct timeval tv_r_JOIN_INNER_9_285634_s, tv_r_JOIN_INNER_9_285634_e;
    gettimeofday(&tv_r_JOIN_INNER_9_285634_s, 0);
    trans_JOIN_INNER_TD_9405197.add(&(tbl_Filter_TD_10910584_output));
    trans_JOIN_INNER_TD_9405197.add(&(tbl_Filter_TD_10123525_output));
    trans_JOIN_INNER_TD_9405197.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_9405197), &(events_h2d_wr_JOIN_INNER_TD_9405197[0]));
    events_grp_JOIN_INNER_TD_9405197.push_back(events_h2d_wr_JOIN_INNER_TD_9405197[0]);
    krnl_JOIN_INNER_TD_9405197.run(0, &(events_grp_JOIN_INNER_TD_9405197), &(events_JOIN_INNER_TD_9405197[0]));
    
    trans_JOIN_INNER_TD_9405197_out.add(&(tbl_JOIN_INNER_TD_9405197_output));
    trans_JOIN_INNER_TD_9405197_out.dev2host(0, &(events_JOIN_INNER_TD_9405197), &(events_d2h_rd_JOIN_INNER_TD_9405197[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_9_285634_e, 0);

    struct timeval tv_r_Aggregate_8_236814_s, tv_r_Aggregate_8_236814_e;
    gettimeofday(&tv_r_Aggregate_8_236814_s, 0);
    SW_Aggregate_TD_8936138(tbl_JOIN_INNER_TD_9976930_output, tbl_Aggregate_TD_8936138_output);
    gettimeofday(&tv_r_Aggregate_8_236814_e, 0);

    struct timeval tv_r_JOIN_INNER_8_936614_s, tv_r_JOIN_INNER_8_936614_e;
    gettimeofday(&tv_r_JOIN_INNER_8_936614_s, 0);
    SW_JOIN_INNER_TD_8601458(tbl_JOIN_INNER_TD_9405197_output, tbl_Filter_TD_9477549_output, tbl_JOIN_INNER_TD_8601458_output);
    gettimeofday(&tv_r_JOIN_INNER_8_936614_e, 0);

    struct timeval tv_r_Aggregate_7_551747_s, tv_r_Aggregate_7_551747_e;
    gettimeofday(&tv_r_Aggregate_7_551747_s, 0);
    SW_Aggregate_TD_7575826(tbl_Aggregate_TD_8936138_output, tbl_Aggregate_TD_7575826_output);
    gettimeofday(&tv_r_Aggregate_7_551747_e, 0);

    struct timeval tv_r_Aggregate_7_459413_s, tv_r_Aggregate_7_459413_e;
    gettimeofday(&tv_r_Aggregate_7_459413_s, 0);
    SW_Aggregate_TD_7493319(tbl_JOIN_INNER_TD_8601458_output, tbl_Aggregate_TD_7493319_output);
    gettimeofday(&tv_r_Aggregate_7_459413_e, 0);

    struct timeval tv_r_Filter_6_175505_s, tv_r_Filter_6_175505_e;
    gettimeofday(&tv_r_Filter_6_175505_s, 0);
    SW_Filter_TD_6751120(tbl_Aggregate_TD_7575826_output, tbl_Filter_TD_6751120_output);
    gettimeofday(&tv_r_Filter_6_175505_e, 0);

    struct timeval tv_r_Filter_6_946057_s, tv_r_Filter_6_946057_e;
    gettimeofday(&tv_r_Filter_6_946057_s, 0);
    SW_Filter_TD_6966344(tbl_Aggregate_TD_7493319_output, tbl_Filter_TD_6966344_output);
    gettimeofday(&tv_r_Filter_6_946057_e, 0);

    struct timeval tv_r_Filter_5_266360_s, tv_r_Filter_5_266360_e;
    gettimeofday(&tv_r_Filter_5_266360_s, 0);
    SW_Filter_TD_5834503(tbl_SerializeFromObject_TD_6271956_input, tbl_Filter_TD_5834503_output);
    gettimeofday(&tv_r_Filter_5_266360_e, 0);

    struct timeval tv_r_JOIN_INNER_5_740175_s, tv_r_JOIN_INNER_5_740175_e;
    gettimeofday(&tv_r_JOIN_INNER_5_740175_s, 0);
    SW_JOIN_INNER_TD_5149717(tbl_Filter_TD_6966344_output, tbl_Filter_TD_6751120_output, tbl_JOIN_INNER_TD_5149717_output);
    gettimeofday(&tv_r_JOIN_INNER_5_740175_e, 0);

    struct timeval tv_r_Filter_4_25330_s, tv_r_Filter_4_25330_e;
    gettimeofday(&tv_r_Filter_4_25330_s, 0);
    SW_Filter_TD_4514666(tbl_SerializeFromObject_TD_5865613_input, tbl_Filter_TD_4514666_output);
    gettimeofday(&tv_r_Filter_4_25330_e, 0);

    struct timeval tv_r_JOIN_INNER_4_788890_s, tv_r_JOIN_INNER_4_788890_e;
    gettimeofday(&tv_r_JOIN_INNER_4_788890_s, 0);
    SW_JOIN_INNER_TD_4971542(tbl_JOIN_INNER_TD_5149717_output, tbl_Filter_TD_5834503_output, tbl_JOIN_INNER_TD_4971542_output);
    gettimeofday(&tv_r_JOIN_INNER_4_788890_e, 0);

    struct timeval tv_r_JOIN_INNER_3_939414_s, tv_r_JOIN_INNER_3_939414_e;
    gettimeofday(&tv_r_JOIN_INNER_3_939414_s, 0);
    SW_JOIN_INNER_TD_3343747(tbl_JOIN_INNER_TD_4971542_output, tbl_Filter_TD_4514666_output, tbl_JOIN_INNER_TD_3343747_output);
    gettimeofday(&tv_r_JOIN_INNER_3_939414_e, 0);

    struct timeval tv_r_Sort_2_581241_s, tv_r_Sort_2_581241_e;
    gettimeofday(&tv_r_Sort_2_581241_s, 0);
    SW_Sort_TD_2173178(tbl_JOIN_INNER_TD_3343747_output, tbl_Sort_TD_2173178_output);
    gettimeofday(&tv_r_Sort_2_581241_e, 0);

    struct timeval tv_r_LocalLimit_1_211922_s, tv_r_LocalLimit_1_211922_e;
    gettimeofday(&tv_r_LocalLimit_1_211922_s, 0);
    SW_LocalLimit_TD_1637703(tbl_Sort_TD_2173178_output, tbl_LocalLimit_TD_1637703_output);
    gettimeofday(&tv_r_LocalLimit_1_211922_e, 0);

    struct timeval tv_r_GlobalLimit_0_814176_s, tv_r_GlobalLimit_0_814176_e;
    gettimeofday(&tv_r_GlobalLimit_0_814176_s, 0);
    SW_GlobalLimit_TD_0403706(tbl_LocalLimit_TD_1637703_output, tbl_GlobalLimit_TD_0403706_output);
    gettimeofday(&tv_r_GlobalLimit_0_814176_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_731016_s, &tv_r_Filter_11_731016_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12313967_input: " << tbl_SerializeFromObject_TD_12313967_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_49456_s, &tv_r_Filter_11_49456_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12940974_input: " << tbl_SerializeFromObject_TD_12940974_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_519488_s, &tv_r_Filter_10_519488_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11716935_input: " << tbl_SerializeFromObject_TD_11716935_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_593488_s, &tv_r_JOIN_INNER_10_593488_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11560775_output: " << tbl_Filter_TD_11560775_output.getNumRow() << " " << "tbl_Filter_TD_1184101_output: " << tbl_Filter_TD_1184101_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_65082_s, &tv_r_Filter_10_65082_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11131620_input: " << tbl_SerializeFromObject_TD_11131620_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_20753_s, &tv_r_Filter_10_20753_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11399790_input: " << tbl_SerializeFromObject_TD_11399790_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_992581_s, &tv_r_JOIN_INNER_9_992581_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10280374_output: " << tbl_JOIN_INNER_TD_10280374_output.getNumRow() << " " << "tbl_Filter_TD_1050616_output: " << tbl_Filter_TD_1050616_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_341828_s, &tv_r_Filter_9_341828_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10545088_input: " << tbl_SerializeFromObject_TD_10545088_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_285634_s, &tv_r_JOIN_INNER_9_285634_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10910584_output: " << tbl_Filter_TD_10910584_output.getNumRow() << " " << "tbl_Filter_TD_10123525_output: " << tbl_Filter_TD_10123525_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_8: " << tvdiff(&tv_r_Aggregate_8_236814_s, &tv_r_Aggregate_8_236814_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9976930_output: " << tbl_JOIN_INNER_TD_9976930_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_936614_s, &tv_r_JOIN_INNER_8_936614_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9405197_output: " << tbl_JOIN_INNER_TD_9405197_output.getNumRow() << " " << "tbl_Filter_TD_9477549_output: " << tbl_Filter_TD_9477549_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_7: " << tvdiff(&tv_r_Aggregate_7_551747_s, &tv_r_Aggregate_7_551747_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_8936138_output: " << tbl_Aggregate_TD_8936138_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_7: " << tvdiff(&tv_r_Aggregate_7_459413_s, &tv_r_Aggregate_7_459413_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8601458_output: " << tbl_JOIN_INNER_TD_8601458_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_175505_s, &tv_r_Filter_6_175505_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_7575826_output: " << tbl_Aggregate_TD_7575826_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_946057_s, &tv_r_Filter_6_946057_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_7493319_output: " << tbl_Aggregate_TD_7493319_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_266360_s, &tv_r_Filter_5_266360_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6271956_input: " << tbl_SerializeFromObject_TD_6271956_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_740175_s, &tv_r_JOIN_INNER_5_740175_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6966344_output: " << tbl_Filter_TD_6966344_output.getNumRow() << " " << "tbl_Filter_TD_6751120_output: " << tbl_Filter_TD_6751120_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_25330_s, &tv_r_Filter_4_25330_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5865613_input: " << tbl_SerializeFromObject_TD_5865613_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_788890_s, &tv_r_JOIN_INNER_4_788890_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5149717_output: " << tbl_JOIN_INNER_TD_5149717_output.getNumRow() << " " << "tbl_Filter_TD_5834503_output: " << tbl_Filter_TD_5834503_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_939414_s, &tv_r_JOIN_INNER_3_939414_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4971542_output: " << tbl_JOIN_INNER_TD_4971542_output.getNumRow() << " " << "tbl_Filter_TD_4514666_output: " << tbl_Filter_TD_4514666_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_581241_s, &tv_r_Sort_2_581241_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3343747_output: " << tbl_JOIN_INNER_TD_3343747_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_211922_s, &tv_r_LocalLimit_1_211922_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2173178_output: " << tbl_Sort_TD_2173178_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_814176_s, &tv_r_GlobalLimit_0_814176_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1637703_output: " << tbl_LocalLimit_TD_1637703_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.7784246 * 1000 << "ms" << std::endl; 
    return 0; 
}
