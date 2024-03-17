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

#include "cfgFunc_q24.hpp" 
#include "q24.hpp" 

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
    std::cout << "NOTE:running query #24\n."; 
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
    Table tbl_Filter_TD_0910086_output("tbl_Filter_TD_0910086_output", 6100000, 4, "");
    tbl_Filter_TD_0910086_output.allocateHost();
    Table tbl_Aggregate_TD_1756945_output("tbl_Aggregate_TD_1756945_output", 6100000, 4, "");
    tbl_Aggregate_TD_1756945_output.allocateHost();
    Table tbl_Aggregate_TD_1394297_output("tbl_Aggregate_TD_1394297_output", 6100000, 1, "");
    tbl_Aggregate_TD_1394297_output.allocateHost();
    Table tbl_Aggregate_TD_2240297_output("tbl_Aggregate_TD_2240297_output", 6100000, 4, "");
    tbl_Aggregate_TD_2240297_output.allocateHost();
    Table tbl_Aggregate_TD_2418209_output("tbl_Aggregate_TD_2418209_output", 6100000, 1, "");
    tbl_Aggregate_TD_2418209_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3724347_output("tbl_JOIN_INNER_TD_3724347_output", 6100000, 11, "");
    tbl_JOIN_INNER_TD_3724347_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3784845_output("tbl_JOIN_INNER_TD_3784845_output", 6100000, 11, "");
    tbl_JOIN_INNER_TD_3784845_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4629849_output("tbl_JOIN_INNER_TD_4629849_output", 6100000, 12, "");
    tbl_JOIN_INNER_TD_4629849_output.allocateHost();
    Table tbl_Filter_TD_488239_output("tbl_Filter_TD_488239_output", 6100000, 3, "");
    tbl_Filter_TD_488239_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4377805_output("tbl_JOIN_INNER_TD_4377805_output", 6100000, 12, "");
    tbl_JOIN_INNER_TD_4377805_output.allocateHost();
    Table tbl_Filter_TD_4488634_output("tbl_Filter_TD_4488634_output", 6100000, 3, "");
    tbl_Filter_TD_4488634_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5566941_output("tbl_JOIN_INNER_TD_5566941_output", 6100000, 10, "");
    tbl_JOIN_INNER_TD_5566941_output.allocateHost();
    Table tbl_Filter_TD_5465349_output("tbl_Filter_TD_5465349_output", 6100000, 4, "");
    tbl_Filter_TD_5465349_output.allocateHost();
    Table tbl_SerializeFromObject_TD_5829472_input;
    tbl_SerializeFromObject_TD_5829472_input = Table("customer_address", customer_address_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_5829472_input.addCol("ca_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_5829472_input.addCol("ca_zip", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_5829472_input.addCol("ca_country", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_5829472_input.allocateHost();
    tbl_SerializeFromObject_TD_5829472_input.loadHost();
    Table tbl_JOIN_INNER_TD_5131839_output("tbl_JOIN_INNER_TD_5131839_output", 6100000, 10, "");
    tbl_JOIN_INNER_TD_5131839_output.allocateHost();
    Table tbl_Filter_TD_5624264_output("tbl_Filter_TD_5624264_output", 6100000, 4, "");
    tbl_Filter_TD_5624264_output.allocateHost();
    Table tbl_SerializeFromObject_TD_580398_input;
    tbl_SerializeFromObject_TD_580398_input = Table("customer_address", customer_address_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_580398_input.addCol("ca_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_580398_input.addCol("ca_zip", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_580398_input.addCol("ca_country", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_580398_input.allocateHost();
    tbl_SerializeFromObject_TD_580398_input.loadHost();
    Table tbl_JOIN_INNER_TD_6233621_output("tbl_JOIN_INNER_TD_6233621_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_6233621_output.allocateHost();
    Table tbl_Filter_TD_6386375_output("tbl_Filter_TD_6386375_output", 6100000, 6, "");
    tbl_Filter_TD_6386375_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6198063_input;
    tbl_SerializeFromObject_TD_6198063_input = Table("customer", customer_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_6198063_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_6198063_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6198063_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6198063_input.addCol("c_birth_country", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6198063_input.allocateHost();
    tbl_SerializeFromObject_TD_6198063_input.loadHost();
    Table tbl_JOIN_INNER_TD_6914803_output("tbl_JOIN_INNER_TD_6914803_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_6914803_output.allocateHost();
    Table tbl_Filter_TD_6193182_output("tbl_Filter_TD_6193182_output", 6100000, 6, "");
    tbl_Filter_TD_6193182_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6878937_input;
    tbl_SerializeFromObject_TD_6878937_input = Table("customer", customer_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_6878937_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_6878937_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6878937_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6878937_input.addCol("c_birth_country", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6878937_input.allocateHost();
    tbl_SerializeFromObject_TD_6878937_input.loadHost();
    Table tbl_JOIN_INNER_TD_7419839_output("tbl_JOIN_INNER_TD_7419839_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_7419839_output.allocateHost();
    Table tbl_Filter_TD_7125399_output("tbl_Filter_TD_7125399_output", 6100000, 4, "");
    tbl_Filter_TD_7125399_output.allocateHost();
    Table tbl_SerializeFromObject_TD_755795_input;
    tbl_SerializeFromObject_TD_755795_input = Table("item", item_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_755795_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_755795_input.addCol("i_current_price", 4);
    tbl_SerializeFromObject_TD_755795_input.addCol("i_size", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_755795_input.addCol("i_color", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_755795_input.addCol("i_units", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_755795_input.addCol("i_manager_id", 4);
    tbl_SerializeFromObject_TD_755795_input.allocateHost();
    tbl_SerializeFromObject_TD_755795_input.loadHost();
    Table tbl_JOIN_INNER_TD_7406547_output("tbl_JOIN_INNER_TD_7406547_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_7406547_output.allocateHost();
    Table tbl_Filter_TD_7527555_output("tbl_Filter_TD_7527555_output", 6100000, 4, "");
    tbl_Filter_TD_7527555_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7373764_input;
    tbl_SerializeFromObject_TD_7373764_input = Table("item", item_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_7373764_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_7373764_input.addCol("i_current_price", 4);
    tbl_SerializeFromObject_TD_7373764_input.addCol("i_size", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7373764_input.addCol("i_color", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7373764_input.addCol("i_units", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7373764_input.addCol("i_manager_id", 4);
    tbl_SerializeFromObject_TD_7373764_input.allocateHost();
    tbl_SerializeFromObject_TD_7373764_input.loadHost();
    Table tbl_Filter_TD_8933235_output("tbl_Filter_TD_8933235_output", 6100000, 5, "");
    tbl_Filter_TD_8933235_output.allocateHost();
    Table tbl_Filter_TD_8157960_output("tbl_Filter_TD_8157960_output", 6100000, 2, "");
    tbl_Filter_TD_8157960_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8275695_input;
    tbl_SerializeFromObject_TD_8275695_input = Table("store", store_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_8275695_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_8275695_input.addCol("s_store_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8275695_input.addCol("s_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8275695_input.addCol("s_zip", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8275695_input.addCol("s_market_id", 4);
    tbl_SerializeFromObject_TD_8275695_input.allocateHost();
    tbl_SerializeFromObject_TD_8275695_input.loadHost();
    Table tbl_Filter_TD_8975445_output("tbl_Filter_TD_8975445_output", 6100000, 5, "");
    tbl_Filter_TD_8975445_output.allocateHost();
    Table tbl_Filter_TD_8440977_output("tbl_Filter_TD_8440977_output", 6100000, 2, "");
    tbl_Filter_TD_8440977_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8541374_input;
    tbl_SerializeFromObject_TD_8541374_input = Table("store", store_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_8541374_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_8541374_input.addCol("s_store_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8541374_input.addCol("s_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8541374_input.addCol("s_zip", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8541374_input.addCol("s_market_id", 4);
    tbl_SerializeFromObject_TD_8541374_input.allocateHost();
    tbl_SerializeFromObject_TD_8541374_input.loadHost();
    Table tbl_SerializeFromObject_TD_9624777_input;
    tbl_SerializeFromObject_TD_9624777_input = Table("store_sales", store_sales_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_9624777_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_9624777_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_9624777_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_9624777_input.addCol("ss_ticket_number", 8);
    tbl_SerializeFromObject_TD_9624777_input.addCol("ss_net_paid", 4);
    tbl_SerializeFromObject_TD_9624777_input.allocateHost();
    tbl_SerializeFromObject_TD_9624777_input.loadHost();
    Table tbl_SerializeFromObject_TD_9114852_input;
    tbl_SerializeFromObject_TD_9114852_input = Table("store_returns", store_returns_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9114852_input.addCol("sr_item_sk", 4);
    tbl_SerializeFromObject_TD_9114852_input.addCol("sr_ticket_number", 8);
    tbl_SerializeFromObject_TD_9114852_input.allocateHost();
    tbl_SerializeFromObject_TD_9114852_input.loadHost();
    Table tbl_SerializeFromObject_TD_9813656_input;
    tbl_SerializeFromObject_TD_9813656_input = Table("store_sales", store_sales_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_9813656_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_9813656_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_9813656_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_9813656_input.addCol("ss_ticket_number", 8);
    tbl_SerializeFromObject_TD_9813656_input.addCol("ss_net_paid", 4);
    tbl_SerializeFromObject_TD_9813656_input.allocateHost();
    tbl_SerializeFromObject_TD_9813656_input.loadHost();
    Table tbl_SerializeFromObject_TD_9181200_input;
    tbl_SerializeFromObject_TD_9181200_input = Table("store_returns", store_returns_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9181200_input.addCol("sr_item_sk", 4);
    tbl_SerializeFromObject_TD_9181200_input.addCol("sr_ticket_number", 8);
    tbl_SerializeFromObject_TD_9181200_input.allocateHost();
    tbl_SerializeFromObject_TD_9181200_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_7419839_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_7406547_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8933235_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8157960_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8975445_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8440977_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_7419839_cmds;
    cfg_JOIN_INNER_TD_7419839_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7419839_gqe_join (cfg_JOIN_INNER_TD_7419839_cmds.cmd);
    cfg_JOIN_INNER_TD_7419839_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7406547_cmds;
    cfg_JOIN_INNER_TD_7406547_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7406547_gqe_join (cfg_JOIN_INNER_TD_7406547_cmds.cmd);
    cfg_JOIN_INNER_TD_7406547_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_7419839;
    krnl_JOIN_INNER_TD_7419839 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7419839.setup(tbl_Filter_TD_8933235_output, tbl_Filter_TD_8157960_output, tbl_JOIN_INNER_TD_7419839_output, cfg_JOIN_INNER_TD_7419839_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_7406547;
    krnl_JOIN_INNER_TD_7406547 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7406547.setup(tbl_Filter_TD_8975445_output, tbl_Filter_TD_8440977_output, tbl_JOIN_INNER_TD_7406547_output, cfg_JOIN_INNER_TD_7406547_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_7419839;
    trans_JOIN_INNER_TD_7419839.setq(q_h);
    trans_JOIN_INNER_TD_7419839.add(&(cfg_JOIN_INNER_TD_7419839_cmds));
    transEngine trans_JOIN_INNER_TD_7419839_out;
    trans_JOIN_INNER_TD_7419839_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_7406547;
    trans_JOIN_INNER_TD_7406547.setq(q_h);
    trans_JOIN_INNER_TD_7406547.add(&(cfg_JOIN_INNER_TD_7406547_cmds));
    transEngine trans_JOIN_INNER_TD_7406547_out;
    trans_JOIN_INNER_TD_7406547_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7419839;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7419839;
    std::vector<cl::Event> events_JOIN_INNER_TD_7419839;
    events_h2d_wr_JOIN_INNER_TD_7419839.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7419839.resize(1);
    events_JOIN_INNER_TD_7419839.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7419839;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7419839;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7406547;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7406547;
    std::vector<cl::Event> events_JOIN_INNER_TD_7406547;
    events_h2d_wr_JOIN_INNER_TD_7406547.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7406547.resize(1);
    events_JOIN_INNER_TD_7406547.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7406547;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7406547;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_8_645007_s, tv_r_Filter_8_645007_e;
    gettimeofday(&tv_r_Filter_8_645007_s, 0);
    SW_Filter_TD_8440977(tbl_SerializeFromObject_TD_9181200_input, tbl_Filter_TD_8440977_output);
    gettimeofday(&tv_r_Filter_8_645007_e, 0);

    struct timeval tv_r_Filter_8_127784_s, tv_r_Filter_8_127784_e;
    gettimeofday(&tv_r_Filter_8_127784_s, 0);
    SW_Filter_TD_8975445(tbl_SerializeFromObject_TD_9813656_input, tbl_Filter_TD_8975445_output);
    gettimeofday(&tv_r_Filter_8_127784_e, 0);

    struct timeval tv_r_Filter_8_324747_s, tv_r_Filter_8_324747_e;
    gettimeofday(&tv_r_Filter_8_324747_s, 0);
    SW_Filter_TD_8157960(tbl_SerializeFromObject_TD_9114852_input, tbl_Filter_TD_8157960_output);
    gettimeofday(&tv_r_Filter_8_324747_e, 0);

    struct timeval tv_r_Filter_8_850976_s, tv_r_Filter_8_850976_e;
    gettimeofday(&tv_r_Filter_8_850976_s, 0);
    SW_Filter_TD_8933235(tbl_SerializeFromObject_TD_9624777_input, tbl_Filter_TD_8933235_output);
    gettimeofday(&tv_r_Filter_8_850976_e, 0);

    struct timeval tv_r_Filter_7_401707_s, tv_r_Filter_7_401707_e;
    gettimeofday(&tv_r_Filter_7_401707_s, 0);
    SW_Filter_TD_7527555(tbl_SerializeFromObject_TD_8541374_input, tbl_Filter_TD_7527555_output);
    gettimeofday(&tv_r_Filter_7_401707_e, 0);

    struct timeval tv_r_JOIN_INNER_7_625265_s, tv_r_JOIN_INNER_7_625265_e;
    gettimeofday(&tv_r_JOIN_INNER_7_625265_s, 0);
    trans_JOIN_INNER_TD_7406547.add(&(tbl_Filter_TD_8975445_output));
    trans_JOIN_INNER_TD_7406547.add(&(tbl_Filter_TD_8440977_output));
    trans_JOIN_INNER_TD_7406547.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7406547), &(events_h2d_wr_JOIN_INNER_TD_7406547[0]));
    events_grp_JOIN_INNER_TD_7406547.push_back(events_h2d_wr_JOIN_INNER_TD_7406547[0]);
    krnl_JOIN_INNER_TD_7406547.run(0, &(events_grp_JOIN_INNER_TD_7406547), &(events_JOIN_INNER_TD_7406547[0]));
    
    trans_JOIN_INNER_TD_7406547_out.add(&(tbl_JOIN_INNER_TD_7406547_output));
    trans_JOIN_INNER_TD_7406547_out.dev2host(0, &(events_JOIN_INNER_TD_7406547), &(events_d2h_rd_JOIN_INNER_TD_7406547[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_7_625265_e, 0);

    struct timeval tv_r_Filter_7_365309_s, tv_r_Filter_7_365309_e;
    gettimeofday(&tv_r_Filter_7_365309_s, 0);
    SW_Filter_TD_7125399(tbl_SerializeFromObject_TD_8275695_input, tbl_Filter_TD_7125399_output);
    gettimeofday(&tv_r_Filter_7_365309_e, 0);

    struct timeval tv_r_JOIN_INNER_7_36810_s, tv_r_JOIN_INNER_7_36810_e;
    gettimeofday(&tv_r_JOIN_INNER_7_36810_s, 0);
    trans_JOIN_INNER_TD_7419839.add(&(tbl_Filter_TD_8933235_output));
    trans_JOIN_INNER_TD_7419839.add(&(tbl_Filter_TD_8157960_output));
    trans_JOIN_INNER_TD_7419839.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7419839), &(events_h2d_wr_JOIN_INNER_TD_7419839[0]));
    events_grp_JOIN_INNER_TD_7419839.push_back(events_h2d_wr_JOIN_INNER_TD_7419839[0]);
    krnl_JOIN_INNER_TD_7419839.run(0, &(events_grp_JOIN_INNER_TD_7419839), &(events_JOIN_INNER_TD_7419839[0]));
    
    trans_JOIN_INNER_TD_7419839_out.add(&(tbl_JOIN_INNER_TD_7419839_output));
    trans_JOIN_INNER_TD_7419839_out.dev2host(0, &(events_JOIN_INNER_TD_7419839), &(events_d2h_rd_JOIN_INNER_TD_7419839[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_7_36810_e, 0);

    struct timeval tv_r_Filter_6_900513_s, tv_r_Filter_6_900513_e;
    gettimeofday(&tv_r_Filter_6_900513_s, 0);
    SW_Filter_TD_6193182(tbl_SerializeFromObject_TD_7373764_input, tbl_Filter_TD_6193182_output);
    gettimeofday(&tv_r_Filter_6_900513_e, 0);

    struct timeval tv_r_JOIN_INNER_6_64965_s, tv_r_JOIN_INNER_6_64965_e;
    gettimeofday(&tv_r_JOIN_INNER_6_64965_s, 0);
    SW_JOIN_INNER_TD_6914803(tbl_JOIN_INNER_TD_7406547_output, tbl_Filter_TD_7527555_output, tbl_JOIN_INNER_TD_6914803_output);
    gettimeofday(&tv_r_JOIN_INNER_6_64965_e, 0);

    struct timeval tv_r_Filter_6_653123_s, tv_r_Filter_6_653123_e;
    gettimeofday(&tv_r_Filter_6_653123_s, 0);
    SW_Filter_TD_6386375(tbl_SerializeFromObject_TD_755795_input, tbl_Filter_TD_6386375_output);
    gettimeofday(&tv_r_Filter_6_653123_e, 0);

    struct timeval tv_r_JOIN_INNER_6_834463_s, tv_r_JOIN_INNER_6_834463_e;
    gettimeofday(&tv_r_JOIN_INNER_6_834463_s, 0);
    SW_JOIN_INNER_TD_6233621(tbl_JOIN_INNER_TD_7419839_output, tbl_Filter_TD_7125399_output, tbl_JOIN_INNER_TD_6233621_output);
    gettimeofday(&tv_r_JOIN_INNER_6_834463_e, 0);

    struct timeval tv_r_Filter_5_774187_s, tv_r_Filter_5_774187_e;
    gettimeofday(&tv_r_Filter_5_774187_s, 0);
    SW_Filter_TD_5624264(tbl_SerializeFromObject_TD_6878937_input, tbl_Filter_TD_5624264_output);
    gettimeofday(&tv_r_Filter_5_774187_e, 0);

    struct timeval tv_r_JOIN_INNER_5_399155_s, tv_r_JOIN_INNER_5_399155_e;
    gettimeofday(&tv_r_JOIN_INNER_5_399155_s, 0);
    SW_JOIN_INNER_TD_5131839(tbl_JOIN_INNER_TD_6914803_output, tbl_Filter_TD_6193182_output, tbl_JOIN_INNER_TD_5131839_output);
    gettimeofday(&tv_r_JOIN_INNER_5_399155_e, 0);

    struct timeval tv_r_Filter_5_762866_s, tv_r_Filter_5_762866_e;
    gettimeofday(&tv_r_Filter_5_762866_s, 0);
    SW_Filter_TD_5465349(tbl_SerializeFromObject_TD_6198063_input, tbl_Filter_TD_5465349_output);
    gettimeofday(&tv_r_Filter_5_762866_e, 0);

    struct timeval tv_r_JOIN_INNER_5_774073_s, tv_r_JOIN_INNER_5_774073_e;
    gettimeofday(&tv_r_JOIN_INNER_5_774073_s, 0);
    SW_JOIN_INNER_TD_5566941(tbl_JOIN_INNER_TD_6233621_output, tbl_Filter_TD_6386375_output, tbl_JOIN_INNER_TD_5566941_output);
    gettimeofday(&tv_r_JOIN_INNER_5_774073_e, 0);

    struct timeval tv_r_Filter_4_105652_s, tv_r_Filter_4_105652_e;
    gettimeofday(&tv_r_Filter_4_105652_s, 0);
    SW_Filter_TD_4488634(tbl_SerializeFromObject_TD_580398_input, tbl_Filter_TD_4488634_output);
    gettimeofday(&tv_r_Filter_4_105652_e, 0);

    struct timeval tv_r_JOIN_INNER_4_664649_s, tv_r_JOIN_INNER_4_664649_e;
    gettimeofday(&tv_r_JOIN_INNER_4_664649_s, 0);
    SW_JOIN_INNER_TD_4377805(tbl_JOIN_INNER_TD_5131839_output, tbl_Filter_TD_5624264_output, tbl_JOIN_INNER_TD_4377805_output);
    gettimeofday(&tv_r_JOIN_INNER_4_664649_e, 0);

    struct timeval tv_r_Filter_4_730188_s, tv_r_Filter_4_730188_e;
    gettimeofday(&tv_r_Filter_4_730188_s, 0);
    SW_Filter_TD_488239(tbl_SerializeFromObject_TD_5829472_input, tbl_Filter_TD_488239_output);
    gettimeofday(&tv_r_Filter_4_730188_e, 0);

    struct timeval tv_r_JOIN_INNER_4_554930_s, tv_r_JOIN_INNER_4_554930_e;
    gettimeofday(&tv_r_JOIN_INNER_4_554930_s, 0);
    SW_JOIN_INNER_TD_4629849(tbl_JOIN_INNER_TD_5566941_output, tbl_Filter_TD_5465349_output, tbl_JOIN_INNER_TD_4629849_output);
    gettimeofday(&tv_r_JOIN_INNER_4_554930_e, 0);

    struct timeval tv_r_JOIN_INNER_3_121975_s, tv_r_JOIN_INNER_3_121975_e;
    gettimeofday(&tv_r_JOIN_INNER_3_121975_s, 0);
    SW_JOIN_INNER_TD_3784845(tbl_JOIN_INNER_TD_4377805_output, tbl_Filter_TD_4488634_output, tbl_JOIN_INNER_TD_3784845_output);
    gettimeofday(&tv_r_JOIN_INNER_3_121975_e, 0);

    struct timeval tv_r_JOIN_INNER_3_76575_s, tv_r_JOIN_INNER_3_76575_e;
    gettimeofday(&tv_r_JOIN_INNER_3_76575_s, 0);
    SW_JOIN_INNER_TD_3724347(tbl_JOIN_INNER_TD_4629849_output, tbl_Filter_TD_488239_output, tbl_JOIN_INNER_TD_3724347_output);
    gettimeofday(&tv_r_JOIN_INNER_3_76575_e, 0);

    struct timeval tv_r_Aggregate_2_147370_s, tv_r_Aggregate_2_147370_e;
    gettimeofday(&tv_r_Aggregate_2_147370_s, 0);
    SW_Aggregate_TD_2418209(tbl_JOIN_INNER_TD_3784845_output, tbl_Aggregate_TD_2418209_output);
    gettimeofday(&tv_r_Aggregate_2_147370_e, 0);

    struct timeval tv_r_Aggregate_2_912008_s, tv_r_Aggregate_2_912008_e;
    gettimeofday(&tv_r_Aggregate_2_912008_s, 0);
    SW_Aggregate_TD_2240297(tbl_JOIN_INNER_TD_3724347_output, tbl_Aggregate_TD_2240297_output);
    gettimeofday(&tv_r_Aggregate_2_912008_e, 0);

    struct timeval tv_r_Aggregate_1_798069_s, tv_r_Aggregate_1_798069_e;
    gettimeofday(&tv_r_Aggregate_1_798069_s, 0);
    SW_Aggregate_TD_1394297(tbl_Aggregate_TD_2418209_output, tbl_Aggregate_TD_1394297_output);
    gettimeofday(&tv_r_Aggregate_1_798069_e, 0);

    struct timeval tv_r_Aggregate_1_769229_s, tv_r_Aggregate_1_769229_e;
    gettimeofday(&tv_r_Aggregate_1_769229_s, 0);
    SW_Aggregate_TD_1756945(tbl_Aggregate_TD_2240297_output, tbl_Aggregate_TD_1756945_output);
    gettimeofday(&tv_r_Aggregate_1_769229_e, 0);

    struct timeval tv_r_Filter_0_781124_s, tv_r_Filter_0_781124_e;
    gettimeofday(&tv_r_Filter_0_781124_s, 0);
    SW_Filter_TD_0910086(tbl_Aggregate_TD_1756945_output, tbl_Aggregate_TD_1394297_output, tbl_Filter_TD_0910086_output);
    gettimeofday(&tv_r_Filter_0_781124_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_645007_s, &tv_r_Filter_8_645007_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9181200_input: " << tbl_SerializeFromObject_TD_9181200_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_127784_s, &tv_r_Filter_8_127784_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9813656_input: " << tbl_SerializeFromObject_TD_9813656_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_324747_s, &tv_r_Filter_8_324747_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9114852_input: " << tbl_SerializeFromObject_TD_9114852_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_850976_s, &tv_r_Filter_8_850976_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9624777_input: " << tbl_SerializeFromObject_TD_9624777_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_401707_s, &tv_r_Filter_7_401707_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8541374_input: " << tbl_SerializeFromObject_TD_8541374_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_625265_s, &tv_r_JOIN_INNER_7_625265_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8975445_output: " << tbl_Filter_TD_8975445_output.getNumRow() << " " << "tbl_Filter_TD_8440977_output: " << tbl_Filter_TD_8440977_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_365309_s, &tv_r_Filter_7_365309_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8275695_input: " << tbl_SerializeFromObject_TD_8275695_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_36810_s, &tv_r_JOIN_INNER_7_36810_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8933235_output: " << tbl_Filter_TD_8933235_output.getNumRow() << " " << "tbl_Filter_TD_8157960_output: " << tbl_Filter_TD_8157960_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_900513_s, &tv_r_Filter_6_900513_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7373764_input: " << tbl_SerializeFromObject_TD_7373764_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_64965_s, &tv_r_JOIN_INNER_6_64965_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7406547_output: " << tbl_JOIN_INNER_TD_7406547_output.getNumRow() << " " << "tbl_Filter_TD_7527555_output: " << tbl_Filter_TD_7527555_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_653123_s, &tv_r_Filter_6_653123_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_755795_input: " << tbl_SerializeFromObject_TD_755795_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_834463_s, &tv_r_JOIN_INNER_6_834463_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7419839_output: " << tbl_JOIN_INNER_TD_7419839_output.getNumRow() << " " << "tbl_Filter_TD_7125399_output: " << tbl_Filter_TD_7125399_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_774187_s, &tv_r_Filter_5_774187_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6878937_input: " << tbl_SerializeFromObject_TD_6878937_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_399155_s, &tv_r_JOIN_INNER_5_399155_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6914803_output: " << tbl_JOIN_INNER_TD_6914803_output.getNumRow() << " " << "tbl_Filter_TD_6193182_output: " << tbl_Filter_TD_6193182_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_762866_s, &tv_r_Filter_5_762866_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6198063_input: " << tbl_SerializeFromObject_TD_6198063_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_774073_s, &tv_r_JOIN_INNER_5_774073_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6233621_output: " << tbl_JOIN_INNER_TD_6233621_output.getNumRow() << " " << "tbl_Filter_TD_6386375_output: " << tbl_Filter_TD_6386375_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_105652_s, &tv_r_Filter_4_105652_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_580398_input: " << tbl_SerializeFromObject_TD_580398_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_664649_s, &tv_r_JOIN_INNER_4_664649_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5131839_output: " << tbl_JOIN_INNER_TD_5131839_output.getNumRow() << " " << "tbl_Filter_TD_5624264_output: " << tbl_Filter_TD_5624264_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_730188_s, &tv_r_Filter_4_730188_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5829472_input: " << tbl_SerializeFromObject_TD_5829472_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_554930_s, &tv_r_JOIN_INNER_4_554930_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5566941_output: " << tbl_JOIN_INNER_TD_5566941_output.getNumRow() << " " << "tbl_Filter_TD_5465349_output: " << tbl_Filter_TD_5465349_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_121975_s, &tv_r_JOIN_INNER_3_121975_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4377805_output: " << tbl_JOIN_INNER_TD_4377805_output.getNumRow() << " " << "tbl_Filter_TD_4488634_output: " << tbl_Filter_TD_4488634_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_76575_s, &tv_r_JOIN_INNER_3_76575_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4629849_output: " << tbl_JOIN_INNER_TD_4629849_output.getNumRow() << " " << "tbl_Filter_TD_488239_output: " << tbl_Filter_TD_488239_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_2: " << tvdiff(&tv_r_Aggregate_2_147370_s, &tv_r_Aggregate_2_147370_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3784845_output: " << tbl_JOIN_INNER_TD_3784845_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_2: " << tvdiff(&tv_r_Aggregate_2_912008_s, &tv_r_Aggregate_2_912008_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3724347_output: " << tbl_JOIN_INNER_TD_3724347_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_798069_s, &tv_r_Aggregate_1_798069_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_2418209_output: " << tbl_Aggregate_TD_2418209_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_769229_s, &tv_r_Aggregate_1_769229_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_2240297_output: " << tbl_Aggregate_TD_2240297_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_0: " << tvdiff(&tv_r_Filter_0_781124_s, &tv_r_Filter_0_781124_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_1756945_output: " << tbl_Aggregate_TD_1756945_output.getNumRow() << " " << "tbl_Aggregate_TD_1394297_output: " << tbl_Aggregate_TD_1394297_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.2676427 * 1000 << "ms" << std::endl; 
    return 0; 
}
