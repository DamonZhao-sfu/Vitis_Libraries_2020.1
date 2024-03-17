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

#include "cfgFunc_q46.hpp" 
#include "q46.hpp" 

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
    std::cout << "NOTE:running query #46\n."; 
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
    Table tbl_GlobalLimit_TD_0407832_output("tbl_GlobalLimit_TD_0407832_output", 6100000, 7, "");
    tbl_GlobalLimit_TD_0407832_output.allocateHost();
    Table tbl_LocalLimit_TD_1603446_output("tbl_LocalLimit_TD_1603446_output", 6100000, 7, "");
    tbl_LocalLimit_TD_1603446_output.allocateHost();
    Table tbl_Sort_TD_2538629_output("tbl_Sort_TD_2538629_output", 6100000, 7, "");
    tbl_Sort_TD_2538629_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3172888_output("tbl_JOIN_INNER_TD_3172888_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_3172888_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4588809_output("tbl_JOIN_INNER_TD_4588809_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_4588809_output.allocateHost();
    Table tbl_Filter_TD_4502187_output("tbl_Filter_TD_4502187_output", 6100000, 2, "");
    tbl_Filter_TD_4502187_output.allocateHost();
    Table tbl_Aggregate_TD_5264040_output("tbl_Aggregate_TD_5264040_output", 6100000, 5, "");
    tbl_Aggregate_TD_5264040_output.allocateHost();
    Table tbl_Filter_TD_5796898_output("tbl_Filter_TD_5796898_output", 6100000, 4, "");
    tbl_Filter_TD_5796898_output.allocateHost();
    Table tbl_SerializeFromObject_TD_5838757_input;
    tbl_SerializeFromObject_TD_5838757_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_5838757_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_5838757_input.addCol("ca_city", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_5838757_input.allocateHost();
    tbl_SerializeFromObject_TD_5838757_input.loadHost();
    Table tbl_JOIN_INNER_TD_629120_output("tbl_JOIN_INNER_TD_629120_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_629120_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6969397_input;
    tbl_SerializeFromObject_TD_6969397_input = Table("customer", customer_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_6969397_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_6969397_input.addCol("c_current_addr_sk", 4);
    tbl_SerializeFromObject_TD_6969397_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6969397_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6969397_input.allocateHost();
    tbl_SerializeFromObject_TD_6969397_input.loadHost();
    Table tbl_JOIN_INNER_TD_7582378_output("tbl_JOIN_INNER_TD_7582378_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_7582378_output.allocateHost();
    Table tbl_Filter_TD_7114843_output("tbl_Filter_TD_7114843_output", 6100000, 2, "");
    tbl_Filter_TD_7114843_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8473776_output("tbl_JOIN_INNER_TD_8473776_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_8473776_output.allocateHost();
    Table tbl_Filter_TD_8926590_output("tbl_Filter_TD_8926590_output", 6100000, 1, "");
    tbl_Filter_TD_8926590_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8895912_input;
    tbl_SerializeFromObject_TD_8895912_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8895912_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_8895912_input.addCol("ca_city", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8895912_input.allocateHost();
    tbl_SerializeFromObject_TD_8895912_input.loadHost();
    Table tbl_JOIN_INNER_TD_9898996_output("tbl_JOIN_INNER_TD_9898996_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_9898996_output.allocateHost();
    Table tbl_Filter_TD_9798814_output("tbl_Filter_TD_9798814_output", 6100000, 1, "");
    tbl_Filter_TD_9798814_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9102889_input;
    tbl_SerializeFromObject_TD_9102889_input = Table("household_demographics", household_demographics_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9102889_input.addCol("hd_demo_sk", 4);
    tbl_SerializeFromObject_TD_9102889_input.addCol("hd_dep_count", 4);
    tbl_SerializeFromObject_TD_9102889_input.addCol("hd_vehicle_count", 4);
    tbl_SerializeFromObject_TD_9102889_input.allocateHost();
    tbl_SerializeFromObject_TD_9102889_input.loadHost();
    Table tbl_Filter_TD_10331539_output("tbl_Filter_TD_10331539_output", 6100000, 8, "");
    tbl_Filter_TD_10331539_output.allocateHost();
    Table tbl_Filter_TD_10589704_output("tbl_Filter_TD_10589704_output", 6100000, 1, "");
    tbl_Filter_TD_10589704_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10797235_input;
    tbl_SerializeFromObject_TD_10797235_input = Table("store", store_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10797235_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_10797235_input.addCol("s_city", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10797235_input.allocateHost();
    tbl_SerializeFromObject_TD_10797235_input.loadHost();
    Table tbl_SerializeFromObject_TD_11663159_input;
    tbl_SerializeFromObject_TD_11663159_input = Table("store_sales", store_sales_n, 8, in_dir, "orc");
    tbl_SerializeFromObject_TD_11663159_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_11663159_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_11663159_input.addCol("ss_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_11663159_input.addCol("ss_addr_sk", 4);
    tbl_SerializeFromObject_TD_11663159_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_11663159_input.addCol("ss_ticket_number", 8);
    tbl_SerializeFromObject_TD_11663159_input.addCol("ss_coupon_amt", 4);
    tbl_SerializeFromObject_TD_11663159_input.addCol("ss_net_profit", 4);
    tbl_SerializeFromObject_TD_11663159_input.allocateHost();
    tbl_SerializeFromObject_TD_11663159_input.loadHost();
    Table tbl_SerializeFromObject_TD_11967105_input;
    tbl_SerializeFromObject_TD_11967105_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11967105_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_11967105_input.addCol("d_dow", 4);
    tbl_SerializeFromObject_TD_11967105_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_11967105_input.allocateHost();
    tbl_SerializeFromObject_TD_11967105_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_7582378_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8473776_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8926590_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_9898996_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9798814_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10331539_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10589704_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_7582378_cmds;
    cfg_JOIN_INNER_TD_7582378_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7582378_gqe_join (cfg_JOIN_INNER_TD_7582378_cmds.cmd);
    cfg_JOIN_INNER_TD_7582378_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8473776_cmds;
    cfg_JOIN_INNER_TD_8473776_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8473776_gqe_join (cfg_JOIN_INNER_TD_8473776_cmds.cmd);
    cfg_JOIN_INNER_TD_8473776_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_9898996_cmds;
    cfg_JOIN_INNER_TD_9898996_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_9898996_gqe_join (cfg_JOIN_INNER_TD_9898996_cmds.cmd);
    cfg_JOIN_INNER_TD_9898996_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_7582378;
    krnl_JOIN_INNER_TD_7582378 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7582378.setup(tbl_JOIN_INNER_TD_8473776_output, tbl_Filter_TD_8926590_output, tbl_JOIN_INNER_TD_7582378_output, cfg_JOIN_INNER_TD_7582378_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_8473776;
    krnl_JOIN_INNER_TD_8473776 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8473776.setup(tbl_JOIN_INNER_TD_9898996_output, tbl_Filter_TD_9798814_output, tbl_JOIN_INNER_TD_8473776_output, cfg_JOIN_INNER_TD_8473776_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_9898996;
    krnl_JOIN_INNER_TD_9898996 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_9898996.setup(tbl_Filter_TD_10331539_output, tbl_Filter_TD_10589704_output, tbl_JOIN_INNER_TD_9898996_output, cfg_JOIN_INNER_TD_9898996_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_7582378;
    trans_JOIN_INNER_TD_7582378.setq(q_h);
    trans_JOIN_INNER_TD_7582378.add(&(cfg_JOIN_INNER_TD_7582378_cmds));
    transEngine trans_JOIN_INNER_TD_7582378_out;
    trans_JOIN_INNER_TD_7582378_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_8473776;
    trans_JOIN_INNER_TD_8473776.setq(q_h);
    trans_JOIN_INNER_TD_8473776.add(&(cfg_JOIN_INNER_TD_8473776_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_9898996;
    trans_JOIN_INNER_TD_9898996.setq(q_h);
    trans_JOIN_INNER_TD_9898996.add(&(cfg_JOIN_INNER_TD_9898996_cmds));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7582378;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7582378;
    std::vector<cl::Event> events_JOIN_INNER_TD_7582378;
    events_h2d_wr_JOIN_INNER_TD_7582378.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7582378.resize(1);
    events_JOIN_INNER_TD_7582378.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7582378;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7582378;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8473776;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8473776;
    std::vector<cl::Event> events_JOIN_INNER_TD_8473776;
    events_h2d_wr_JOIN_INNER_TD_8473776.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8473776.resize(1);
    events_JOIN_INNER_TD_8473776.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8473776;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8473776;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_9898996;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_9898996;
    std::vector<cl::Event> events_JOIN_INNER_TD_9898996;
    events_h2d_wr_JOIN_INNER_TD_9898996.resize(1);
    events_d2h_rd_JOIN_INNER_TD_9898996.resize(1);
    events_JOIN_INNER_TD_9898996.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_9898996;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_9898996;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_10_419394_s, tv_r_Filter_10_419394_e;
    gettimeofday(&tv_r_Filter_10_419394_s, 0);
    SW_Filter_TD_10589704(tbl_SerializeFromObject_TD_11967105_input, tbl_Filter_TD_10589704_output);
    gettimeofday(&tv_r_Filter_10_419394_e, 0);

    struct timeval tv_r_Filter_10_637616_s, tv_r_Filter_10_637616_e;
    gettimeofday(&tv_r_Filter_10_637616_s, 0);
    SW_Filter_TD_10331539(tbl_SerializeFromObject_TD_11663159_input, tbl_Filter_TD_10331539_output);
    gettimeofday(&tv_r_Filter_10_637616_e, 0);

    struct timeval tv_r_Filter_9_680578_s, tv_r_Filter_9_680578_e;
    gettimeofday(&tv_r_Filter_9_680578_s, 0);
    SW_Filter_TD_9798814(tbl_SerializeFromObject_TD_10797235_input, tbl_Filter_TD_9798814_output);
    gettimeofday(&tv_r_Filter_9_680578_e, 0);

    struct timeval tv_r_JOIN_INNER_9_882521_s, tv_r_JOIN_INNER_9_882521_e;
    gettimeofday(&tv_r_JOIN_INNER_9_882521_s, 0);
    trans_JOIN_INNER_TD_9898996.add(&(tbl_Filter_TD_10331539_output));
    trans_JOIN_INNER_TD_9898996.add(&(tbl_Filter_TD_10589704_output));
    trans_JOIN_INNER_TD_9898996.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_9898996), &(events_h2d_wr_JOIN_INNER_TD_9898996[0]));
    events_grp_JOIN_INNER_TD_9898996.push_back(events_h2d_wr_JOIN_INNER_TD_9898996[0]);
    krnl_JOIN_INNER_TD_9898996.run(0, &(events_grp_JOIN_INNER_TD_9898996), &(events_JOIN_INNER_TD_9898996[0]));
    gettimeofday(&tv_r_JOIN_INNER_9_882521_e, 0);

    struct timeval tv_r_Filter_8_662954_s, tv_r_Filter_8_662954_e;
    gettimeofday(&tv_r_Filter_8_662954_s, 0);
    SW_Filter_TD_8926590(tbl_SerializeFromObject_TD_9102889_input, tbl_Filter_TD_8926590_output);
    gettimeofday(&tv_r_Filter_8_662954_e, 0);

    struct timeval tv_r_JOIN_INNER_8_911810_s, tv_r_JOIN_INNER_8_911810_e;
    gettimeofday(&tv_r_JOIN_INNER_8_911810_s, 0);
    prev_events_grp_JOIN_INNER_TD_8473776.push_back(events_h2d_wr_JOIN_INNER_TD_9898996[0]);
    trans_JOIN_INNER_TD_8473776.add(&(tbl_Filter_TD_9798814_output));
    trans_JOIN_INNER_TD_8473776.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8473776), &(events_h2d_wr_JOIN_INNER_TD_8473776[0]));
    events_grp_JOIN_INNER_TD_8473776.push_back(events_h2d_wr_JOIN_INNER_TD_8473776[0]);
    events_grp_JOIN_INNER_TD_8473776.push_back(events_JOIN_INNER_TD_9898996[0]);
    krnl_JOIN_INNER_TD_8473776.run(0, &(events_grp_JOIN_INNER_TD_8473776), &(events_JOIN_INNER_TD_8473776[0]));
    gettimeofday(&tv_r_JOIN_INNER_8_911810_e, 0);

    struct timeval tv_r_Filter_7_791718_s, tv_r_Filter_7_791718_e;
    gettimeofday(&tv_r_Filter_7_791718_s, 0);
    SW_Filter_TD_7114843(tbl_SerializeFromObject_TD_8895912_input, tbl_Filter_TD_7114843_output);
    gettimeofday(&tv_r_Filter_7_791718_e, 0);

    struct timeval tv_r_JOIN_INNER_7_528024_s, tv_r_JOIN_INNER_7_528024_e;
    gettimeofday(&tv_r_JOIN_INNER_7_528024_s, 0);
    prev_events_grp_JOIN_INNER_TD_7582378.push_back(events_h2d_wr_JOIN_INNER_TD_8473776[0]);
    trans_JOIN_INNER_TD_7582378.add(&(tbl_Filter_TD_8926590_output));
    trans_JOIN_INNER_TD_7582378.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7582378), &(events_h2d_wr_JOIN_INNER_TD_7582378[0]));
    events_grp_JOIN_INNER_TD_7582378.push_back(events_h2d_wr_JOIN_INNER_TD_7582378[0]);
    events_grp_JOIN_INNER_TD_7582378.push_back(events_JOIN_INNER_TD_8473776[0]);
    krnl_JOIN_INNER_TD_7582378.run(0, &(events_grp_JOIN_INNER_TD_7582378), &(events_JOIN_INNER_TD_7582378[0]));
    
    trans_JOIN_INNER_TD_7582378_out.add(&(tbl_JOIN_INNER_TD_7582378_output));
    trans_JOIN_INNER_TD_7582378_out.dev2host(0, &(events_JOIN_INNER_TD_7582378), &(events_d2h_rd_JOIN_INNER_TD_7582378[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_7_528024_e, 0);

    struct timeval tv_r_JOIN_INNER_6_739148_s, tv_r_JOIN_INNER_6_739148_e;
    gettimeofday(&tv_r_JOIN_INNER_6_739148_s, 0);
    SW_JOIN_INNER_TD_629120(tbl_JOIN_INNER_TD_7582378_output, tbl_Filter_TD_7114843_output, tbl_JOIN_INNER_TD_629120_output);
    gettimeofday(&tv_r_JOIN_INNER_6_739148_e, 0);

    struct timeval tv_r_Filter_5_942389_s, tv_r_Filter_5_942389_e;
    gettimeofday(&tv_r_Filter_5_942389_s, 0);
    SW_Filter_TD_5796898(tbl_SerializeFromObject_TD_6969397_input, tbl_Filter_TD_5796898_output);
    gettimeofday(&tv_r_Filter_5_942389_e, 0);

    struct timeval tv_r_Aggregate_5_5113_s, tv_r_Aggregate_5_5113_e;
    gettimeofday(&tv_r_Aggregate_5_5113_s, 0);
    SW_Aggregate_TD_5264040(tbl_JOIN_INNER_TD_629120_output, tbl_Aggregate_TD_5264040_output);
    gettimeofday(&tv_r_Aggregate_5_5113_e, 0);

    struct timeval tv_r_Filter_4_986277_s, tv_r_Filter_4_986277_e;
    gettimeofday(&tv_r_Filter_4_986277_s, 0);
    SW_Filter_TD_4502187(tbl_SerializeFromObject_TD_5838757_input, tbl_Filter_TD_4502187_output);
    gettimeofday(&tv_r_Filter_4_986277_e, 0);

    struct timeval tv_r_JOIN_INNER_4_88614_s, tv_r_JOIN_INNER_4_88614_e;
    gettimeofday(&tv_r_JOIN_INNER_4_88614_s, 0);
    SW_JOIN_INNER_TD_4588809(tbl_Aggregate_TD_5264040_output, tbl_Filter_TD_5796898_output, tbl_JOIN_INNER_TD_4588809_output);
    gettimeofday(&tv_r_JOIN_INNER_4_88614_e, 0);

    struct timeval tv_r_JOIN_INNER_3_190196_s, tv_r_JOIN_INNER_3_190196_e;
    gettimeofday(&tv_r_JOIN_INNER_3_190196_s, 0);
    SW_JOIN_INNER_TD_3172888(tbl_JOIN_INNER_TD_4588809_output, tbl_Filter_TD_4502187_output, tbl_JOIN_INNER_TD_3172888_output);
    gettimeofday(&tv_r_JOIN_INNER_3_190196_e, 0);

    struct timeval tv_r_Sort_2_432937_s, tv_r_Sort_2_432937_e;
    gettimeofday(&tv_r_Sort_2_432937_s, 0);
    SW_Sort_TD_2538629(tbl_JOIN_INNER_TD_3172888_output, tbl_Sort_TD_2538629_output);
    gettimeofday(&tv_r_Sort_2_432937_e, 0);

    struct timeval tv_r_LocalLimit_1_281520_s, tv_r_LocalLimit_1_281520_e;
    gettimeofday(&tv_r_LocalLimit_1_281520_s, 0);
    SW_LocalLimit_TD_1603446(tbl_Sort_TD_2538629_output, tbl_LocalLimit_TD_1603446_output);
    gettimeofday(&tv_r_LocalLimit_1_281520_e, 0);

    struct timeval tv_r_GlobalLimit_0_895154_s, tv_r_GlobalLimit_0_895154_e;
    gettimeofday(&tv_r_GlobalLimit_0_895154_s, 0);
    SW_GlobalLimit_TD_0407832(tbl_LocalLimit_TD_1603446_output, tbl_GlobalLimit_TD_0407832_output);
    gettimeofday(&tv_r_GlobalLimit_0_895154_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_419394_s, &tv_r_Filter_10_419394_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11967105_input: " << tbl_SerializeFromObject_TD_11967105_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_637616_s, &tv_r_Filter_10_637616_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11663159_input: " << tbl_SerializeFromObject_TD_11663159_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_680578_s, &tv_r_Filter_9_680578_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10797235_input: " << tbl_SerializeFromObject_TD_10797235_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_882521_s, &tv_r_JOIN_INNER_9_882521_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10331539_output: " << tbl_Filter_TD_10331539_output.getNumRow() << " " << "tbl_Filter_TD_10589704_output: " << tbl_Filter_TD_10589704_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_662954_s, &tv_r_Filter_8_662954_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9102889_input: " << tbl_SerializeFromObject_TD_9102889_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_911810_s, &tv_r_JOIN_INNER_8_911810_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9898996_output: " << tbl_JOIN_INNER_TD_9898996_output.getNumRow() << " " << "tbl_Filter_TD_9798814_output: " << tbl_Filter_TD_9798814_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_791718_s, &tv_r_Filter_7_791718_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8895912_input: " << tbl_SerializeFromObject_TD_8895912_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_528024_s, &tv_r_JOIN_INNER_7_528024_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8473776_output: " << tbl_JOIN_INNER_TD_8473776_output.getNumRow() << " " << "tbl_Filter_TD_8926590_output: " << tbl_Filter_TD_8926590_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_739148_s, &tv_r_JOIN_INNER_6_739148_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7582378_output: " << tbl_JOIN_INNER_TD_7582378_output.getNumRow() << " " << "tbl_Filter_TD_7114843_output: " << tbl_Filter_TD_7114843_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_942389_s, &tv_r_Filter_5_942389_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6969397_input: " << tbl_SerializeFromObject_TD_6969397_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_5113_s, &tv_r_Aggregate_5_5113_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_629120_output: " << tbl_JOIN_INNER_TD_629120_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_986277_s, &tv_r_Filter_4_986277_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5838757_input: " << tbl_SerializeFromObject_TD_5838757_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_88614_s, &tv_r_JOIN_INNER_4_88614_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_5264040_output: " << tbl_Aggregate_TD_5264040_output.getNumRow() << " " << "tbl_Filter_TD_5796898_output: " << tbl_Filter_TD_5796898_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_190196_s, &tv_r_JOIN_INNER_3_190196_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4588809_output: " << tbl_JOIN_INNER_TD_4588809_output.getNumRow() << " " << "tbl_Filter_TD_4502187_output: " << tbl_Filter_TD_4502187_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_432937_s, &tv_r_Sort_2_432937_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3172888_output: " << tbl_JOIN_INNER_TD_3172888_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_281520_s, &tv_r_LocalLimit_1_281520_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2538629_output: " << tbl_Sort_TD_2538629_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_895154_s, &tv_r_GlobalLimit_0_895154_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1603446_output: " << tbl_LocalLimit_TD_1603446_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.208588 * 1000 << "ms" << std::endl; 
    return 0; 
}
