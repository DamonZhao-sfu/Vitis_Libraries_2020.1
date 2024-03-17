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

#include "cfgFunc_q34.hpp" 
#include "q34.hpp" 

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
    std::cout << "NOTE:running query #34\n."; 
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
    cl::Device device_a = devices[1]; 
    // Create context_a and command queue for selected device 
    cl::Context context_a(device_a); 
    cl::CommandQueue q_a(context_a, device_a, CL_QUEUE_PROFILING_ENABLE | CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE); 
    std::string devName_a = device_a.getInfo<CL_DEVICE_NAME>(); 
    std::cout << "Selected Device " << devName_a << "\n"; 
    cl::Program::Binaries xclBins_a = xcl::import_binary_file(xclbin_path_a); 
    std::vector<cl::Device> devices_a; 
    devices_a.push_back(device_a); 
    cl::Program program_a(context_a, devices_a, xclBins_a); 
    // ****************************** Tables **************************** // 
    Table tbl_Sort_TD_0679127_output("tbl_Sort_TD_0679127_output", 6100000, 6, "");
    tbl_Sort_TD_0679127_output.allocateHost();
    Table tbl_JOIN_INNER_TD_1289093_output("tbl_JOIN_INNER_TD_1289093_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_1289093_output.allocateHost();
    Table tbl_Filter_TD_2684058_output("tbl_Filter_TD_2684058_output", 6100000, 3, "");
    tbl_Filter_TD_2684058_output.allocateHost();
    Table tbl_Filter_TD_2279980_output("tbl_Filter_TD_2279980_output", 6100000, 5, "");
    tbl_Filter_TD_2279980_output.allocateHost();
    Table tbl_Aggregate_TD_3550962_output_preprocess("tbl_Aggregate_TD_3550962_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_3550962_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_3550962_output("tbl_Aggregate_TD_3550962_output", 6100000, 3, "");
    tbl_Aggregate_TD_3550962_output.allocateHost();
    Table tbl_SerializeFromObject_TD_341779_input;
    tbl_SerializeFromObject_TD_341779_input = Table("customer", customer_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_341779_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_341779_input.addCol("c_salutation", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_341779_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_341779_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_341779_input.addCol("c_preferred_cust_flag", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_341779_input.allocateHost();
    tbl_SerializeFromObject_TD_341779_input.loadHost();
    Table tbl_JOIN_INNER_TD_4371159_output_preprocess("tbl_JOIN_INNER_TD_4371159_output_preprocess", 6100000, 2, "");
    tbl_JOIN_INNER_TD_4371159_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_4371159_output("tbl_JOIN_INNER_TD_4371159_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_4371159_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5598297_output("tbl_JOIN_INNER_TD_5598297_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_5598297_output.allocateHost();
    Table tbl_Filter_TD_5615967_output("tbl_Filter_TD_5615967_output", 6100000, 1, "");
    tbl_Filter_TD_5615967_output.allocateHost();
    Table tbl_JOIN_INNER_TD_673887_output("tbl_JOIN_INNER_TD_673887_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_673887_output.allocateHost();
    Table tbl_Filter_TD_6377917_output("tbl_Filter_TD_6377917_output", 6100000, 1, "");
    tbl_Filter_TD_6377917_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6894735_input;
    tbl_SerializeFromObject_TD_6894735_input = Table("household_demographics", household_demographics_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_6894735_input.addCol("hd_demo_sk", 4);
    tbl_SerializeFromObject_TD_6894735_input.addCol("hd_vehicle_count", 4);
    tbl_SerializeFromObject_TD_6894735_input.addCol("hd_dep_count", 4);
    tbl_SerializeFromObject_TD_6894735_input.addCol("hd_buy_potential", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6894735_input.allocateHost();
    tbl_SerializeFromObject_TD_6894735_input.loadHost();
    Table tbl_Filter_TD_7991912_output("tbl_Filter_TD_7991912_output", 6100000, 5, "");
    tbl_Filter_TD_7991912_output.allocateHost();
    Table tbl_Filter_TD_7739985_output("tbl_Filter_TD_7739985_output", 6100000, 1, "");
    tbl_Filter_TD_7739985_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7752946_input;
    tbl_SerializeFromObject_TD_7752946_input = Table("store", store_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7752946_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_7752946_input.addCol("s_county", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7752946_input.allocateHost();
    tbl_SerializeFromObject_TD_7752946_input.loadHost();
    Table tbl_SerializeFromObject_TD_8451563_input;
    tbl_SerializeFromObject_TD_8451563_input = Table("store_sales", store_sales_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_8451563_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_8451563_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_8451563_input.addCol("ss_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_8451563_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_8451563_input.addCol("ss_ticket_number", 8);
    tbl_SerializeFromObject_TD_8451563_input.allocateHost();
    tbl_SerializeFromObject_TD_8451563_input.loadHost();
    Table tbl_SerializeFromObject_TD_815489_input;
    tbl_SerializeFromObject_TD_815489_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_815489_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_815489_input.addCol("d_dom", 4);
    tbl_SerializeFromObject_TD_815489_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_815489_input.allocateHost();
    tbl_SerializeFromObject_TD_815489_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_4371159_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_3550962_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_JOIN_INNER_TD_4371159_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_5598297_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_5615967_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_673887_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_6377917_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_7991912_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_7739985_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    AggrCfgCmd cfg_Aggregate_TD_3550962_cmds;
    cfg_Aggregate_TD_3550962_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_3550962_gqe_aggr(cfg_Aggregate_TD_3550962_cmds.cmd);
    cfg_Aggregate_TD_3550962_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_3550962_cmds_out;
    cfg_Aggregate_TD_3550962_cmds_out.allocateHost();
    cfg_Aggregate_TD_3550962_cmds_out.allocateDevBuffer(context_a, 33);
    cfgCmd cfg_JOIN_INNER_TD_4371159_cmds;
    cfg_JOIN_INNER_TD_4371159_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_4371159_gqe_join (cfg_JOIN_INNER_TD_4371159_cmds.cmd);
    cfg_JOIN_INNER_TD_4371159_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_5598297_cmds;
    cfg_JOIN_INNER_TD_5598297_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_5598297_gqe_join (cfg_JOIN_INNER_TD_5598297_cmds.cmd);
    cfg_JOIN_INNER_TD_5598297_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_673887_cmds;
    cfg_JOIN_INNER_TD_673887_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_673887_gqe_join (cfg_JOIN_INNER_TD_673887_cmds.cmd);
    cfg_JOIN_INNER_TD_673887_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    AggrBufferTmp buftmp_a(context_a); 
    buftmp_a.BufferInitial(q_a); 
    std::cout << std::endl; 
    AggrKrnlEngine krnl_Aggregate_TD_3550962;
    krnl_Aggregate_TD_3550962 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_3550962.setup(tbl_JOIN_INNER_TD_4371159_output, tbl_Aggregate_TD_3550962_output_preprocess, cfg_Aggregate_TD_3550962_cmds, cfg_Aggregate_TD_3550962_cmds_out, buftmp_a);
    krnlEngine krnl_JOIN_INNER_TD_4371159;
    krnl_JOIN_INNER_TD_4371159 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_4371159.setup(tbl_JOIN_INNER_TD_5598297_output, tbl_Filter_TD_5615967_output, tbl_JOIN_INNER_TD_4371159_output_preprocess, cfg_JOIN_INNER_TD_4371159_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_5598297;
    krnl_JOIN_INNER_TD_5598297 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_5598297.setup(tbl_JOIN_INNER_TD_673887_output, tbl_Filter_TD_6377917_output, tbl_JOIN_INNER_TD_5598297_output, cfg_JOIN_INNER_TD_5598297_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_673887;
    krnl_JOIN_INNER_TD_673887 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_673887.setup(tbl_Filter_TD_7991912_output, tbl_Filter_TD_7739985_output, tbl_JOIN_INNER_TD_673887_output, cfg_JOIN_INNER_TD_673887_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_Aggregate_TD_3550962;
    trans_Aggregate_TD_3550962.setq(q_a);
    trans_Aggregate_TD_3550962.add(&(cfg_Aggregate_TD_3550962_cmds));
    transEngine trans_Aggregate_TD_3550962_out;
    trans_Aggregate_TD_3550962_out.setq(q_a);
    q_a.finish();
    transEngine trans_JOIN_INNER_TD_4371159;
    trans_JOIN_INNER_TD_4371159.setq(q_h);
    trans_JOIN_INNER_TD_4371159.add(&(cfg_JOIN_INNER_TD_4371159_cmds));
    transEngine trans_JOIN_INNER_TD_4371159_out;
    trans_JOIN_INNER_TD_4371159_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_5598297;
    trans_JOIN_INNER_TD_5598297.setq(q_h);
    trans_JOIN_INNER_TD_5598297.add(&(cfg_JOIN_INNER_TD_5598297_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_673887;
    trans_JOIN_INNER_TD_673887.setq(q_h);
    trans_JOIN_INNER_TD_673887.add(&(cfg_JOIN_INNER_TD_673887_cmds));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_3550962;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_3550962;
    std::vector<cl::Event> events_Aggregate_TD_3550962;
    events_h2d_wr_Aggregate_TD_3550962.resize(1);
    events_d2h_rd_Aggregate_TD_3550962.resize(1);
    events_Aggregate_TD_3550962.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_3550962;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_3550962;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_4371159;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_4371159;
    std::vector<cl::Event> events_JOIN_INNER_TD_4371159;
    events_h2d_wr_JOIN_INNER_TD_4371159.resize(1);
    events_d2h_rd_JOIN_INNER_TD_4371159.resize(1);
    events_JOIN_INNER_TD_4371159.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_4371159;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_4371159;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_5598297;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_5598297;
    std::vector<cl::Event> events_JOIN_INNER_TD_5598297;
    events_h2d_wr_JOIN_INNER_TD_5598297.resize(1);
    events_d2h_rd_JOIN_INNER_TD_5598297.resize(1);
    events_JOIN_INNER_TD_5598297.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_5598297;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_5598297;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_673887;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_673887;
    std::vector<cl::Event> events_JOIN_INNER_TD_673887;
    events_h2d_wr_JOIN_INNER_TD_673887.resize(1);
    events_d2h_rd_JOIN_INNER_TD_673887.resize(1);
    events_JOIN_INNER_TD_673887.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_673887;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_673887;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_7_548995_s, tv_r_Filter_7_548995_e;
    gettimeofday(&tv_r_Filter_7_548995_s, 0);
    SW_Filter_TD_7739985(tbl_SerializeFromObject_TD_815489_input, tbl_Filter_TD_7739985_output);
    gettimeofday(&tv_r_Filter_7_548995_e, 0);

    struct timeval tv_r_Filter_7_955869_s, tv_r_Filter_7_955869_e;
    gettimeofday(&tv_r_Filter_7_955869_s, 0);
    SW_Filter_TD_7991912(tbl_SerializeFromObject_TD_8451563_input, tbl_Filter_TD_7991912_output);
    gettimeofday(&tv_r_Filter_7_955869_e, 0);

    struct timeval tv_r_Filter_6_336233_s, tv_r_Filter_6_336233_e;
    gettimeofday(&tv_r_Filter_6_336233_s, 0);
    SW_Filter_TD_6377917(tbl_SerializeFromObject_TD_7752946_input, tbl_Filter_TD_6377917_output);
    gettimeofday(&tv_r_Filter_6_336233_e, 0);

    struct timeval tv_r_JOIN_INNER_6_619258_s, tv_r_JOIN_INNER_6_619258_e;
    gettimeofday(&tv_r_JOIN_INNER_6_619258_s, 0);
    trans_JOIN_INNER_TD_673887.add(&(tbl_Filter_TD_7991912_output));
    trans_JOIN_INNER_TD_673887.add(&(tbl_Filter_TD_7739985_output));
    trans_JOIN_INNER_TD_673887.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_673887), &(events_h2d_wr_JOIN_INNER_TD_673887[0]));
    events_grp_JOIN_INNER_TD_673887.push_back(events_h2d_wr_JOIN_INNER_TD_673887[0]);
    krnl_JOIN_INNER_TD_673887.run(0, &(events_grp_JOIN_INNER_TD_673887), &(events_JOIN_INNER_TD_673887[0]));
    gettimeofday(&tv_r_JOIN_INNER_6_619258_e, 0);

    struct timeval tv_r_Filter_5_103407_s, tv_r_Filter_5_103407_e;
    gettimeofday(&tv_r_Filter_5_103407_s, 0);
    SW_Filter_TD_5615967(tbl_SerializeFromObject_TD_6894735_input, tbl_Filter_TD_5615967_output);
    gettimeofday(&tv_r_Filter_5_103407_e, 0);

    struct timeval tv_r_JOIN_INNER_5_668766_s, tv_r_JOIN_INNER_5_668766_e;
    gettimeofday(&tv_r_JOIN_INNER_5_668766_s, 0);
    prev_events_grp_JOIN_INNER_TD_5598297.push_back(events_h2d_wr_JOIN_INNER_TD_673887[0]);
    trans_JOIN_INNER_TD_5598297.add(&(tbl_Filter_TD_6377917_output));
    trans_JOIN_INNER_TD_5598297.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_5598297), &(events_h2d_wr_JOIN_INNER_TD_5598297[0]));
    events_grp_JOIN_INNER_TD_5598297.push_back(events_h2d_wr_JOIN_INNER_TD_5598297[0]);
    events_grp_JOIN_INNER_TD_5598297.push_back(events_JOIN_INNER_TD_673887[0]);
    krnl_JOIN_INNER_TD_5598297.run(0, &(events_grp_JOIN_INNER_TD_5598297), &(events_JOIN_INNER_TD_5598297[0]));
    gettimeofday(&tv_r_JOIN_INNER_5_668766_e, 0);

    struct timeval tv_r_JOIN_INNER_4_446685_s, tv_r_JOIN_INNER_4_446685_e;
    gettimeofday(&tv_r_JOIN_INNER_4_446685_s, 0);
    prev_events_grp_JOIN_INNER_TD_4371159.push_back(events_h2d_wr_JOIN_INNER_TD_5598297[0]);
    trans_JOIN_INNER_TD_4371159.add(&(tbl_Filter_TD_5615967_output));
    trans_JOIN_INNER_TD_4371159.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_4371159), &(events_h2d_wr_JOIN_INNER_TD_4371159[0]));
    events_grp_JOIN_INNER_TD_4371159.push_back(events_h2d_wr_JOIN_INNER_TD_4371159[0]);
    events_grp_JOIN_INNER_TD_4371159.push_back(events_JOIN_INNER_TD_5598297[0]);
    krnl_JOIN_INNER_TD_4371159.run(0, &(events_grp_JOIN_INNER_TD_4371159), &(events_JOIN_INNER_TD_4371159[0]));
    
    trans_JOIN_INNER_TD_4371159_out.add(&(tbl_JOIN_INNER_TD_4371159_output_preprocess));
    trans_JOIN_INNER_TD_4371159_out.dev2host(0, &(events_JOIN_INNER_TD_4371159), &(events_d2h_rd_JOIN_INNER_TD_4371159[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_4371159);
    tbl_JOIN_INNER_TD_4371159_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_4371159_output));
    gettimeofday(&tv_r_JOIN_INNER_4_446685_e, 0);

    struct timeval tv_r_Aggregate_3_582689_s, tv_r_Aggregate_3_582689_e;
    gettimeofday(&tv_r_Aggregate_3_582689_s, 0);
    trans_Aggregate_TD_3550962.add(&(tbl_JOIN_INNER_TD_4371159_output));
    trans_Aggregate_TD_3550962.host2dev(0, &(prev_events_grp_Aggregate_TD_3550962), &(events_h2d_wr_Aggregate_TD_3550962[0]));
    events_grp_Aggregate_TD_3550962.push_back(events_h2d_wr_Aggregate_TD_3550962[0]);
    krnl_Aggregate_TD_3550962.run(0, &(events_grp_Aggregate_TD_3550962), &(events_Aggregate_TD_3550962[0]));
    
    trans_Aggregate_TD_3550962_out.add(&(tbl_Aggregate_TD_3550962_output_preprocess));
    trans_Aggregate_TD_3550962_out.dev2host(0, &(events_Aggregate_TD_3550962), &(events_d2h_rd_Aggregate_TD_3550962[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_3550962_consolidate(tbl_Aggregate_TD_3550962_output_preprocess, tbl_Aggregate_TD_3550962_output);
    gettimeofday(&tv_r_Aggregate_3_582689_e, 0);

    struct timeval tv_r_Filter_2_771232_s, tv_r_Filter_2_771232_e;
    gettimeofday(&tv_r_Filter_2_771232_s, 0);
    SW_Filter_TD_2279980(tbl_SerializeFromObject_TD_341779_input, tbl_Filter_TD_2279980_output);
    gettimeofday(&tv_r_Filter_2_771232_e, 0);

    struct timeval tv_r_Filter_2_429131_s, tv_r_Filter_2_429131_e;
    gettimeofday(&tv_r_Filter_2_429131_s, 0);
    SW_Filter_TD_2684058(tbl_Aggregate_TD_3550962_output, tbl_Filter_TD_2684058_output);
    gettimeofday(&tv_r_Filter_2_429131_e, 0);

    struct timeval tv_r_JOIN_INNER_1_955544_s, tv_r_JOIN_INNER_1_955544_e;
    gettimeofday(&tv_r_JOIN_INNER_1_955544_s, 0);
    SW_JOIN_INNER_TD_1289093(tbl_Filter_TD_2684058_output, tbl_Filter_TD_2279980_output, tbl_JOIN_INNER_TD_1289093_output);
    gettimeofday(&tv_r_JOIN_INNER_1_955544_e, 0);

    struct timeval tv_r_Sort_0_611325_s, tv_r_Sort_0_611325_e;
    gettimeofday(&tv_r_Sort_0_611325_s, 0);
    SW_Sort_TD_0679127(tbl_JOIN_INNER_TD_1289093_output, tbl_Sort_TD_0679127_output);
    gettimeofday(&tv_r_Sort_0_611325_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_548995_s, &tv_r_Filter_7_548995_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_815489_input: " << tbl_SerializeFromObject_TD_815489_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_955869_s, &tv_r_Filter_7_955869_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8451563_input: " << tbl_SerializeFromObject_TD_8451563_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_336233_s, &tv_r_Filter_6_336233_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7752946_input: " << tbl_SerializeFromObject_TD_7752946_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_619258_s, &tv_r_JOIN_INNER_6_619258_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_7991912_output: " << tbl_Filter_TD_7991912_output.getNumRow() << " " << "tbl_Filter_TD_7739985_output: " << tbl_Filter_TD_7739985_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_103407_s, &tv_r_Filter_5_103407_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6894735_input: " << tbl_SerializeFromObject_TD_6894735_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_668766_s, &tv_r_JOIN_INNER_5_668766_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_673887_output: " << tbl_JOIN_INNER_TD_673887_output.getNumRow() << " " << "tbl_Filter_TD_6377917_output: " << tbl_Filter_TD_6377917_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_446685_s, &tv_r_JOIN_INNER_4_446685_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5598297_output: " << tbl_JOIN_INNER_TD_5598297_output.getNumRow() << " " << "tbl_Filter_TD_5615967_output: " << tbl_Filter_TD_5615967_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_582689_s, &tv_r_Aggregate_3_582689_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4371159_output: " << tbl_JOIN_INNER_TD_4371159_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_771232_s, &tv_r_Filter_2_771232_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_341779_input: " << tbl_SerializeFromObject_TD_341779_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_429131_s, &tv_r_Filter_2_429131_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3550962_output: " << tbl_Aggregate_TD_3550962_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_1: " << tvdiff(&tv_r_JOIN_INNER_1_955544_s, &tv_r_JOIN_INNER_1_955544_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_2684058_output: " << tbl_Filter_TD_2684058_output.getNumRow() << " " << "tbl_Filter_TD_2279980_output: " << tbl_Filter_TD_2279980_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_611325_s, &tv_r_Sort_0_611325_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_1289093_output: " << tbl_JOIN_INNER_TD_1289093_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.4940583 * 1000 << "ms" << std::endl; 
    return 0; 
}
