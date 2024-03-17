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

#include "cfgFunc_q25.hpp" 
#include "q25.hpp" 

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
    std::cout << "NOTE:running query #25\n."; 
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
    Table tbl_GlobalLimit_TD_019475_output("tbl_GlobalLimit_TD_019475_output", 6100000, 7, "");
    tbl_GlobalLimit_TD_019475_output.allocateHost();
    Table tbl_LocalLimit_TD_1609438_output("tbl_LocalLimit_TD_1609438_output", 6100000, 7, "");
    tbl_LocalLimit_TD_1609438_output.allocateHost();
    Table tbl_Sort_TD_2152722_output("tbl_Sort_TD_2152722_output", 6100000, 7, "");
    tbl_Sort_TD_2152722_output.allocateHost();
    Table tbl_Aggregate_TD_3303406_output("tbl_Aggregate_TD_3303406_output", 6100000, 7, "");
    tbl_Aggregate_TD_3303406_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4861903_output("tbl_JOIN_INNER_TD_4861903_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_4861903_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5574246_output("tbl_JOIN_INNER_TD_5574246_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_5574246_output.allocateHost();
    Table tbl_Filter_TD_5339843_output("tbl_Filter_TD_5339843_output", 6100000, 3, "");
    tbl_Filter_TD_5339843_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6594018_output("tbl_JOIN_INNER_TD_6594018_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_6594018_output.allocateHost();
    Table tbl_Filter_TD_6762899_output("tbl_Filter_TD_6762899_output", 6100000, 3, "");
    tbl_Filter_TD_6762899_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6525760_input;
    tbl_SerializeFromObject_TD_6525760_input = Table("item", item_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_6525760_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_6525760_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6525760_input.addCol("i_item_desc", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6525760_input.allocateHost();
    tbl_SerializeFromObject_TD_6525760_input.loadHost();
    Table tbl_JOIN_INNER_TD_7674356_output("tbl_JOIN_INNER_TD_7674356_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_7674356_output.allocateHost();
    Table tbl_Filter_TD_738762_output("tbl_Filter_TD_738762_output", 6100000, 1, "");
    tbl_Filter_TD_738762_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7982168_input;
    tbl_SerializeFromObject_TD_7982168_input = Table("store", store_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7982168_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_7982168_input.addCol("s_store_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7982168_input.addCol("s_store_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7982168_input.allocateHost();
    tbl_SerializeFromObject_TD_7982168_input.loadHost();
    Table tbl_JOIN_INNER_TD_8963030_output("tbl_JOIN_INNER_TD_8963030_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_8963030_output.allocateHost();
    Table tbl_Filter_TD_8995233_output("tbl_Filter_TD_8995233_output", 6100000, 1, "");
    tbl_Filter_TD_8995233_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8700903_input;
    tbl_SerializeFromObject_TD_8700903_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8700903_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_8700903_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_8700903_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_8700903_input.allocateHost();
    tbl_SerializeFromObject_TD_8700903_input.loadHost();
    Table tbl_JOIN_INNER_TD_9641592_output("tbl_JOIN_INNER_TD_9641592_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_9641592_output.allocateHost();
    Table tbl_Filter_TD_9158216_output("tbl_Filter_TD_9158216_output", 6100000, 1, "");
    tbl_Filter_TD_9158216_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9330558_input;
    tbl_SerializeFromObject_TD_9330558_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9330558_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_9330558_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_9330558_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_9330558_input.allocateHost();
    tbl_SerializeFromObject_TD_9330558_input.loadHost();
    Table tbl_JOIN_INNER_TD_10908177_output("tbl_JOIN_INNER_TD_10908177_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_10908177_output.allocateHost();
    Table tbl_Filter_TD_10434519_output("tbl_Filter_TD_10434519_output", 6100000, 4, "");
    tbl_Filter_TD_10434519_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10552846_input;
    tbl_SerializeFromObject_TD_10552846_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10552846_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10552846_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_10552846_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10552846_input.allocateHost();
    tbl_SerializeFromObject_TD_10552846_input.loadHost();
    Table tbl_Filter_TD_11790567_output("tbl_Filter_TD_11790567_output", 6100000, 6, "");
    tbl_Filter_TD_11790567_output.allocateHost();
    Table tbl_Filter_TD_11785293_output("tbl_Filter_TD_11785293_output", 6100000, 5, "");
    tbl_Filter_TD_11785293_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11612571_input;
    tbl_SerializeFromObject_TD_11612571_input = Table("catalog_sales", catalog_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_11612571_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_11612571_input.addCol("cs_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_11612571_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_11612571_input.addCol("cs_net_profit", 4);
    tbl_SerializeFromObject_TD_11612571_input.allocateHost();
    tbl_SerializeFromObject_TD_11612571_input.loadHost();
    Table tbl_SerializeFromObject_TD_12901765_input;
    tbl_SerializeFromObject_TD_12901765_input = Table("store_sales", store_sales_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_12901765_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_12901765_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_12901765_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_12901765_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_12901765_input.addCol("ss_ticket_number", 8);
    tbl_SerializeFromObject_TD_12901765_input.addCol("ss_net_profit", 4);
    tbl_SerializeFromObject_TD_12901765_input.allocateHost();
    tbl_SerializeFromObject_TD_12901765_input.loadHost();
    Table tbl_SerializeFromObject_TD_12921492_input;
    tbl_SerializeFromObject_TD_12921492_input = Table("store_returns", store_returns_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_12921492_input.addCol("sr_returned_date_sk", 4);
    tbl_SerializeFromObject_TD_12921492_input.addCol("sr_item_sk", 4);
    tbl_SerializeFromObject_TD_12921492_input.addCol("sr_customer_sk", 4);
    tbl_SerializeFromObject_TD_12921492_input.addCol("sr_ticket_number", 8);
    tbl_SerializeFromObject_TD_12921492_input.addCol("sr_net_loss", 4);
    tbl_SerializeFromObject_TD_12921492_input.allocateHost();
    tbl_SerializeFromObject_TD_12921492_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_6594018_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_7674356_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_738762_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8963030_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8995233_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_9641592_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9158216_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_10908177_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10434519_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_6594018_cmds;
    cfg_JOIN_INNER_TD_6594018_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_6594018_gqe_join (cfg_JOIN_INNER_TD_6594018_cmds.cmd);
    cfg_JOIN_INNER_TD_6594018_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7674356_cmds;
    cfg_JOIN_INNER_TD_7674356_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7674356_gqe_join (cfg_JOIN_INNER_TD_7674356_cmds.cmd);
    cfg_JOIN_INNER_TD_7674356_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8963030_cmds;
    cfg_JOIN_INNER_TD_8963030_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8963030_gqe_join (cfg_JOIN_INNER_TD_8963030_cmds.cmd);
    cfg_JOIN_INNER_TD_8963030_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_9641592_cmds;
    cfg_JOIN_INNER_TD_9641592_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_9641592_gqe_join (cfg_JOIN_INNER_TD_9641592_cmds.cmd);
    cfg_JOIN_INNER_TD_9641592_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_6594018;
    krnl_JOIN_INNER_TD_6594018 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_6594018.setup(tbl_JOIN_INNER_TD_7674356_output, tbl_Filter_TD_738762_output, tbl_JOIN_INNER_TD_6594018_output, cfg_JOIN_INNER_TD_6594018_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_7674356;
    krnl_JOIN_INNER_TD_7674356 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7674356.setup(tbl_JOIN_INNER_TD_8963030_output, tbl_Filter_TD_8995233_output, tbl_JOIN_INNER_TD_7674356_output, cfg_JOIN_INNER_TD_7674356_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_8963030;
    krnl_JOIN_INNER_TD_8963030 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8963030.setup(tbl_JOIN_INNER_TD_9641592_output, tbl_Filter_TD_9158216_output, tbl_JOIN_INNER_TD_8963030_output, cfg_JOIN_INNER_TD_8963030_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_9641592;
    krnl_JOIN_INNER_TD_9641592 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_9641592.setup(tbl_JOIN_INNER_TD_10908177_output, tbl_Filter_TD_10434519_output, tbl_JOIN_INNER_TD_9641592_output, cfg_JOIN_INNER_TD_9641592_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_6594018;
    trans_JOIN_INNER_TD_6594018.setq(q_h);
    trans_JOIN_INNER_TD_6594018.add(&(cfg_JOIN_INNER_TD_6594018_cmds));
    transEngine trans_JOIN_INNER_TD_6594018_out;
    trans_JOIN_INNER_TD_6594018_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_7674356;
    trans_JOIN_INNER_TD_7674356.setq(q_h);
    trans_JOIN_INNER_TD_7674356.add(&(cfg_JOIN_INNER_TD_7674356_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_8963030;
    trans_JOIN_INNER_TD_8963030.setq(q_h);
    trans_JOIN_INNER_TD_8963030.add(&(cfg_JOIN_INNER_TD_8963030_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_9641592;
    trans_JOIN_INNER_TD_9641592.setq(q_h);
    trans_JOIN_INNER_TD_9641592.add(&(cfg_JOIN_INNER_TD_9641592_cmds));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_6594018;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_6594018;
    std::vector<cl::Event> events_JOIN_INNER_TD_6594018;
    events_h2d_wr_JOIN_INNER_TD_6594018.resize(1);
    events_d2h_rd_JOIN_INNER_TD_6594018.resize(1);
    events_JOIN_INNER_TD_6594018.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_6594018;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_6594018;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7674356;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7674356;
    std::vector<cl::Event> events_JOIN_INNER_TD_7674356;
    events_h2d_wr_JOIN_INNER_TD_7674356.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7674356.resize(1);
    events_JOIN_INNER_TD_7674356.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7674356;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7674356;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8963030;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8963030;
    std::vector<cl::Event> events_JOIN_INNER_TD_8963030;
    events_h2d_wr_JOIN_INNER_TD_8963030.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8963030.resize(1);
    events_JOIN_INNER_TD_8963030.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8963030;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8963030;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_9641592;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_9641592;
    std::vector<cl::Event> events_JOIN_INNER_TD_9641592;
    events_h2d_wr_JOIN_INNER_TD_9641592.resize(1);
    events_d2h_rd_JOIN_INNER_TD_9641592.resize(1);
    events_JOIN_INNER_TD_9641592.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_9641592;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_9641592;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_11_767271_s, tv_r_Filter_11_767271_e;
    gettimeofday(&tv_r_Filter_11_767271_s, 0);
    SW_Filter_TD_11785293(tbl_SerializeFromObject_TD_12921492_input, tbl_Filter_TD_11785293_output);
    gettimeofday(&tv_r_Filter_11_767271_e, 0);

    struct timeval tv_r_Filter_11_780731_s, tv_r_Filter_11_780731_e;
    gettimeofday(&tv_r_Filter_11_780731_s, 0);
    SW_Filter_TD_11790567(tbl_SerializeFromObject_TD_12901765_input, tbl_Filter_TD_11790567_output);
    gettimeofday(&tv_r_Filter_11_780731_e, 0);

    struct timeval tv_r_Filter_10_272458_s, tv_r_Filter_10_272458_e;
    gettimeofday(&tv_r_Filter_10_272458_s, 0);
    SW_Filter_TD_10434519(tbl_SerializeFromObject_TD_11612571_input, tbl_Filter_TD_10434519_output);
    gettimeofday(&tv_r_Filter_10_272458_e, 0);

    struct timeval tv_r_JOIN_INNER_10_506074_s, tv_r_JOIN_INNER_10_506074_e;
    gettimeofday(&tv_r_JOIN_INNER_10_506074_s, 0);
    SW_JOIN_INNER_TD_10908177(tbl_Filter_TD_11790567_output, tbl_Filter_TD_11785293_output, tbl_JOIN_INNER_TD_10908177_output);
    gettimeofday(&tv_r_JOIN_INNER_10_506074_e, 0);

    struct timeval tv_r_Filter_9_391305_s, tv_r_Filter_9_391305_e;
    gettimeofday(&tv_r_Filter_9_391305_s, 0);
    SW_Filter_TD_9158216(tbl_SerializeFromObject_TD_10552846_input, tbl_Filter_TD_9158216_output);
    gettimeofday(&tv_r_Filter_9_391305_e, 0);

    struct timeval tv_r_JOIN_INNER_9_555320_s, tv_r_JOIN_INNER_9_555320_e;
    gettimeofday(&tv_r_JOIN_INNER_9_555320_s, 0);
    trans_JOIN_INNER_TD_9641592.add(&(tbl_JOIN_INNER_TD_10908177_output));
    trans_JOIN_INNER_TD_9641592.add(&(tbl_Filter_TD_10434519_output));
    trans_JOIN_INNER_TD_9641592.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_9641592), &(events_h2d_wr_JOIN_INNER_TD_9641592[0]));
    events_grp_JOIN_INNER_TD_9641592.push_back(events_h2d_wr_JOIN_INNER_TD_9641592[0]);
    krnl_JOIN_INNER_TD_9641592.run(0, &(events_grp_JOIN_INNER_TD_9641592), &(events_JOIN_INNER_TD_9641592[0]));
    gettimeofday(&tv_r_JOIN_INNER_9_555320_e, 0);

    struct timeval tv_r_Filter_8_716326_s, tv_r_Filter_8_716326_e;
    gettimeofday(&tv_r_Filter_8_716326_s, 0);
    SW_Filter_TD_8995233(tbl_SerializeFromObject_TD_9330558_input, tbl_Filter_TD_8995233_output);
    gettimeofday(&tv_r_Filter_8_716326_e, 0);

    struct timeval tv_r_JOIN_INNER_8_883124_s, tv_r_JOIN_INNER_8_883124_e;
    gettimeofday(&tv_r_JOIN_INNER_8_883124_s, 0);
    prev_events_grp_JOIN_INNER_TD_8963030.push_back(events_h2d_wr_JOIN_INNER_TD_9641592[0]);
    trans_JOIN_INNER_TD_8963030.add(&(tbl_Filter_TD_9158216_output));
    trans_JOIN_INNER_TD_8963030.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8963030), &(events_h2d_wr_JOIN_INNER_TD_8963030[0]));
    events_grp_JOIN_INNER_TD_8963030.push_back(events_h2d_wr_JOIN_INNER_TD_8963030[0]);
    events_grp_JOIN_INNER_TD_8963030.push_back(events_JOIN_INNER_TD_9641592[0]);
    krnl_JOIN_INNER_TD_8963030.run(0, &(events_grp_JOIN_INNER_TD_8963030), &(events_JOIN_INNER_TD_8963030[0]));
    gettimeofday(&tv_r_JOIN_INNER_8_883124_e, 0);

    struct timeval tv_r_Filter_7_832246_s, tv_r_Filter_7_832246_e;
    gettimeofday(&tv_r_Filter_7_832246_s, 0);
    SW_Filter_TD_738762(tbl_SerializeFromObject_TD_8700903_input, tbl_Filter_TD_738762_output);
    gettimeofday(&tv_r_Filter_7_832246_e, 0);

    struct timeval tv_r_JOIN_INNER_7_915465_s, tv_r_JOIN_INNER_7_915465_e;
    gettimeofday(&tv_r_JOIN_INNER_7_915465_s, 0);
    prev_events_grp_JOIN_INNER_TD_7674356.push_back(events_h2d_wr_JOIN_INNER_TD_8963030[0]);
    trans_JOIN_INNER_TD_7674356.add(&(tbl_Filter_TD_8995233_output));
    trans_JOIN_INNER_TD_7674356.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7674356), &(events_h2d_wr_JOIN_INNER_TD_7674356[0]));
    events_grp_JOIN_INNER_TD_7674356.push_back(events_h2d_wr_JOIN_INNER_TD_7674356[0]);
    events_grp_JOIN_INNER_TD_7674356.push_back(events_JOIN_INNER_TD_8963030[0]);
    krnl_JOIN_INNER_TD_7674356.run(0, &(events_grp_JOIN_INNER_TD_7674356), &(events_JOIN_INNER_TD_7674356[0]));
    gettimeofday(&tv_r_JOIN_INNER_7_915465_e, 0);

    struct timeval tv_r_Filter_6_326892_s, tv_r_Filter_6_326892_e;
    gettimeofday(&tv_r_Filter_6_326892_s, 0);
    SW_Filter_TD_6762899(tbl_SerializeFromObject_TD_7982168_input, tbl_Filter_TD_6762899_output);
    gettimeofday(&tv_r_Filter_6_326892_e, 0);

    struct timeval tv_r_JOIN_INNER_6_71883_s, tv_r_JOIN_INNER_6_71883_e;
    gettimeofday(&tv_r_JOIN_INNER_6_71883_s, 0);
    prev_events_grp_JOIN_INNER_TD_6594018.push_back(events_h2d_wr_JOIN_INNER_TD_7674356[0]);
    trans_JOIN_INNER_TD_6594018.add(&(tbl_Filter_TD_738762_output));
    trans_JOIN_INNER_TD_6594018.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_6594018), &(events_h2d_wr_JOIN_INNER_TD_6594018[0]));
    events_grp_JOIN_INNER_TD_6594018.push_back(events_h2d_wr_JOIN_INNER_TD_6594018[0]);
    events_grp_JOIN_INNER_TD_6594018.push_back(events_JOIN_INNER_TD_7674356[0]);
    krnl_JOIN_INNER_TD_6594018.run(0, &(events_grp_JOIN_INNER_TD_6594018), &(events_JOIN_INNER_TD_6594018[0]));
    
    trans_JOIN_INNER_TD_6594018_out.add(&(tbl_JOIN_INNER_TD_6594018_output));
    trans_JOIN_INNER_TD_6594018_out.dev2host(0, &(events_JOIN_INNER_TD_6594018), &(events_d2h_rd_JOIN_INNER_TD_6594018[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_6_71883_e, 0);

    struct timeval tv_r_Filter_5_909231_s, tv_r_Filter_5_909231_e;
    gettimeofday(&tv_r_Filter_5_909231_s, 0);
    SW_Filter_TD_5339843(tbl_SerializeFromObject_TD_6525760_input, tbl_Filter_TD_5339843_output);
    gettimeofday(&tv_r_Filter_5_909231_e, 0);

    struct timeval tv_r_JOIN_INNER_5_975993_s, tv_r_JOIN_INNER_5_975993_e;
    gettimeofday(&tv_r_JOIN_INNER_5_975993_s, 0);
    SW_JOIN_INNER_TD_5574246(tbl_JOIN_INNER_TD_6594018_output, tbl_Filter_TD_6762899_output, tbl_JOIN_INNER_TD_5574246_output);
    gettimeofday(&tv_r_JOIN_INNER_5_975993_e, 0);

    struct timeval tv_r_JOIN_INNER_4_445947_s, tv_r_JOIN_INNER_4_445947_e;
    gettimeofday(&tv_r_JOIN_INNER_4_445947_s, 0);
    SW_JOIN_INNER_TD_4861903(tbl_JOIN_INNER_TD_5574246_output, tbl_Filter_TD_5339843_output, tbl_JOIN_INNER_TD_4861903_output);
    gettimeofday(&tv_r_JOIN_INNER_4_445947_e, 0);

    struct timeval tv_r_Aggregate_3_442224_s, tv_r_Aggregate_3_442224_e;
    gettimeofday(&tv_r_Aggregate_3_442224_s, 0);
    SW_Aggregate_TD_3303406(tbl_JOIN_INNER_TD_4861903_output, tbl_Aggregate_TD_3303406_output);
    gettimeofday(&tv_r_Aggregate_3_442224_e, 0);

    struct timeval tv_r_Sort_2_39452_s, tv_r_Sort_2_39452_e;
    gettimeofday(&tv_r_Sort_2_39452_s, 0);
    SW_Sort_TD_2152722(tbl_Aggregate_TD_3303406_output, tbl_Sort_TD_2152722_output);
    gettimeofday(&tv_r_Sort_2_39452_e, 0);

    struct timeval tv_r_LocalLimit_1_42956_s, tv_r_LocalLimit_1_42956_e;
    gettimeofday(&tv_r_LocalLimit_1_42956_s, 0);
    SW_LocalLimit_TD_1609438(tbl_Sort_TD_2152722_output, tbl_LocalLimit_TD_1609438_output);
    gettimeofday(&tv_r_LocalLimit_1_42956_e, 0);

    struct timeval tv_r_GlobalLimit_0_684911_s, tv_r_GlobalLimit_0_684911_e;
    gettimeofday(&tv_r_GlobalLimit_0_684911_s, 0);
    SW_GlobalLimit_TD_019475(tbl_LocalLimit_TD_1609438_output, tbl_GlobalLimit_TD_019475_output);
    gettimeofday(&tv_r_GlobalLimit_0_684911_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_767271_s, &tv_r_Filter_11_767271_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12921492_input: " << tbl_SerializeFromObject_TD_12921492_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_780731_s, &tv_r_Filter_11_780731_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12901765_input: " << tbl_SerializeFromObject_TD_12901765_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_272458_s, &tv_r_Filter_10_272458_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11612571_input: " << tbl_SerializeFromObject_TD_11612571_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_506074_s, &tv_r_JOIN_INNER_10_506074_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11790567_output: " << tbl_Filter_TD_11790567_output.getNumRow() << " " << "tbl_Filter_TD_11785293_output: " << tbl_Filter_TD_11785293_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_391305_s, &tv_r_Filter_9_391305_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10552846_input: " << tbl_SerializeFromObject_TD_10552846_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_555320_s, &tv_r_JOIN_INNER_9_555320_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10908177_output: " << tbl_JOIN_INNER_TD_10908177_output.getNumRow() << " " << "tbl_Filter_TD_10434519_output: " << tbl_Filter_TD_10434519_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_716326_s, &tv_r_Filter_8_716326_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9330558_input: " << tbl_SerializeFromObject_TD_9330558_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_883124_s, &tv_r_JOIN_INNER_8_883124_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9641592_output: " << tbl_JOIN_INNER_TD_9641592_output.getNumRow() << " " << "tbl_Filter_TD_9158216_output: " << tbl_Filter_TD_9158216_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_832246_s, &tv_r_Filter_7_832246_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8700903_input: " << tbl_SerializeFromObject_TD_8700903_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_915465_s, &tv_r_JOIN_INNER_7_915465_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8963030_output: " << tbl_JOIN_INNER_TD_8963030_output.getNumRow() << " " << "tbl_Filter_TD_8995233_output: " << tbl_Filter_TD_8995233_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_326892_s, &tv_r_Filter_6_326892_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7982168_input: " << tbl_SerializeFromObject_TD_7982168_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_71883_s, &tv_r_JOIN_INNER_6_71883_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7674356_output: " << tbl_JOIN_INNER_TD_7674356_output.getNumRow() << " " << "tbl_Filter_TD_738762_output: " << tbl_Filter_TD_738762_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_909231_s, &tv_r_Filter_5_909231_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6525760_input: " << tbl_SerializeFromObject_TD_6525760_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_975993_s, &tv_r_JOIN_INNER_5_975993_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6594018_output: " << tbl_JOIN_INNER_TD_6594018_output.getNumRow() << " " << "tbl_Filter_TD_6762899_output: " << tbl_Filter_TD_6762899_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_445947_s, &tv_r_JOIN_INNER_4_445947_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5574246_output: " << tbl_JOIN_INNER_TD_5574246_output.getNumRow() << " " << "tbl_Filter_TD_5339843_output: " << tbl_Filter_TD_5339843_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_442224_s, &tv_r_Aggregate_3_442224_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4861903_output: " << tbl_JOIN_INNER_TD_4861903_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_39452_s, &tv_r_Sort_2_39452_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3303406_output: " << tbl_Aggregate_TD_3303406_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_42956_s, &tv_r_LocalLimit_1_42956_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2152722_output: " << tbl_Sort_TD_2152722_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_684911_s, &tv_r_GlobalLimit_0_684911_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1609438_output: " << tbl_LocalLimit_TD_1609438_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 5.3693533 * 1000 << "ms" << std::endl; 
    return 0; 
}
