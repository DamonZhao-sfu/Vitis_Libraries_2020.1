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

#include "cfgFunc_q92.hpp" 
#include "q92.hpp" 

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
    std::cout << "NOTE:running query #92\n."; 
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
    Table tbl_Aggregate_TD_012180_output("tbl_Aggregate_TD_012180_output", 6100000, 1, "");
    tbl_Aggregate_TD_012180_output.allocateHost();
    Table tbl_JOIN_INNER_TD_1785021_output("tbl_JOIN_INNER_TD_1785021_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_1785021_output.allocateHost();
    Table tbl_JOIN_INNER_TD_2176142_output("tbl_JOIN_INNER_TD_2176142_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_2176142_output.allocateHost();
    Table tbl_Filter_TD_2823943_output("tbl_Filter_TD_2823943_output", 6100000, 1, "");
    tbl_Filter_TD_2823943_output.allocateHost();
    Table tbl_JOIN_INNER_TD_342355_output("tbl_JOIN_INNER_TD_342355_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_342355_output.allocateHost();
    Table tbl_Filter_TD_3919242_output("tbl_Filter_TD_3919242_output", 6100000, 2, "");
    tbl_Filter_TD_3919242_output.allocateHost();
    Table tbl_SerializeFromObject_TD_3720904_input;
    tbl_SerializeFromObject_TD_3720904_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_3720904_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_3720904_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_3720904_input.allocateHost();
    tbl_SerializeFromObject_TD_3720904_input.loadHost();
    Table tbl_Filter_TD_477201_output("tbl_Filter_TD_477201_output", 6100000, 3, "");
    tbl_Filter_TD_477201_output.allocateHost();
    Table tbl_Filter_TD_4774196_output("tbl_Filter_TD_4774196_output", 6100000, 1, "");
    tbl_Filter_TD_4774196_output.allocateHost();
    Table tbl_Aggregate_TD_4463533_output_preprocess("tbl_Aggregate_TD_4463533_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_4463533_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_4463533_output("tbl_Aggregate_TD_4463533_output", 6100000, 2, "");
    tbl_Aggregate_TD_4463533_output.allocateHost();
    Table tbl_SerializeFromObject_TD_5726134_input;
    tbl_SerializeFromObject_TD_5726134_input = Table("web_sales", web_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_5726134_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_5726134_input.addCol("ws_item_sk", 4);
    tbl_SerializeFromObject_TD_5726134_input.addCol("ws_ext_discount_amt", 4);
    tbl_SerializeFromObject_TD_5726134_input.allocateHost();
    tbl_SerializeFromObject_TD_5726134_input.loadHost();
    Table tbl_SerializeFromObject_TD_5497117_input;
    tbl_SerializeFromObject_TD_5497117_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_5497117_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_5497117_input.addCol("i_manufact_id", 4);
    tbl_SerializeFromObject_TD_5497117_input.allocateHost();
    tbl_SerializeFromObject_TD_5497117_input.loadHost();
    Table tbl_JOIN_INNER_TD_5277628_output_preprocess("tbl_JOIN_INNER_TD_5277628_output_preprocess", 6100000, 2, "");
    tbl_JOIN_INNER_TD_5277628_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_5277628_output("tbl_JOIN_INNER_TD_5277628_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_5277628_output.allocateHost();
    Table tbl_Filter_TD_6257412_output("tbl_Filter_TD_6257412_output", 6100000, 3, "");
    tbl_Filter_TD_6257412_output.allocateHost();
    Table tbl_Filter_TD_6125439_output("tbl_Filter_TD_6125439_output", 6100000, 1, "");
    tbl_Filter_TD_6125439_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7346119_input;
    tbl_SerializeFromObject_TD_7346119_input = Table("web_sales", web_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7346119_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_7346119_input.addCol("ws_item_sk", 4);
    tbl_SerializeFromObject_TD_7346119_input.addCol("ws_ext_discount_amt", 4);
    tbl_SerializeFromObject_TD_7346119_input.allocateHost();
    tbl_SerializeFromObject_TD_7346119_input.loadHost();
    Table tbl_SerializeFromObject_TD_7671180_input;
    tbl_SerializeFromObject_TD_7671180_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7671180_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_7671180_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_7671180_input.allocateHost();
    tbl_SerializeFromObject_TD_7671180_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_1785021_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_2176142_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_2823943_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_342355_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_3919242_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_477201_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_4774196_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_5277628_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_4463533_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_JOIN_INNER_TD_5277628_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_6257412_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_6125439_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_1785021_cmds;
    cfg_JOIN_INNER_TD_1785021_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_1785021_gqe_join (cfg_JOIN_INNER_TD_1785021_cmds.cmd);
    cfg_JOIN_INNER_TD_1785021_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_2176142_cmds;
    cfg_JOIN_INNER_TD_2176142_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_2176142_gqe_join (cfg_JOIN_INNER_TD_2176142_cmds.cmd);
    cfg_JOIN_INNER_TD_2176142_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_342355_cmds;
    cfg_JOIN_INNER_TD_342355_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_342355_gqe_join (cfg_JOIN_INNER_TD_342355_cmds.cmd);
    cfg_JOIN_INNER_TD_342355_cmds.allocateDevBuffer(context_h, 32);
    AggrCfgCmd cfg_Aggregate_TD_4463533_cmds;
    cfg_Aggregate_TD_4463533_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_4463533_gqe_aggr(cfg_Aggregate_TD_4463533_cmds.cmd);
    cfg_Aggregate_TD_4463533_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_4463533_cmds_out;
    cfg_Aggregate_TD_4463533_cmds_out.allocateHost();
    cfg_Aggregate_TD_4463533_cmds_out.allocateDevBuffer(context_a, 33);
    cfgCmd cfg_JOIN_INNER_TD_5277628_cmds;
    cfg_JOIN_INNER_TD_5277628_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_5277628_gqe_join (cfg_JOIN_INNER_TD_5277628_cmds.cmd);
    cfg_JOIN_INNER_TD_5277628_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    AggrBufferTmp buftmp_a(context_a); 
    buftmp_a.BufferInitial(q_a); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_1785021;
    krnl_JOIN_INNER_TD_1785021 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_1785021.setup(tbl_JOIN_INNER_TD_2176142_output, tbl_Filter_TD_2823943_output, tbl_JOIN_INNER_TD_1785021_output, cfg_JOIN_INNER_TD_1785021_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_2176142;
    krnl_JOIN_INNER_TD_2176142 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_2176142.setup(tbl_JOIN_INNER_TD_342355_output, tbl_Filter_TD_3919242_output, tbl_JOIN_INNER_TD_2176142_output, cfg_JOIN_INNER_TD_2176142_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_342355;
    krnl_JOIN_INNER_TD_342355 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_342355.setup(tbl_Filter_TD_477201_output, tbl_Filter_TD_4774196_output, tbl_JOIN_INNER_TD_342355_output, cfg_JOIN_INNER_TD_342355_cmds, buftmp_h);
    AggrKrnlEngine krnl_Aggregate_TD_4463533;
    krnl_Aggregate_TD_4463533 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_4463533.setup(tbl_JOIN_INNER_TD_5277628_output, tbl_Aggregate_TD_4463533_output_preprocess, cfg_Aggregate_TD_4463533_cmds, cfg_Aggregate_TD_4463533_cmds_out, buftmp_a);
    krnlEngine krnl_JOIN_INNER_TD_5277628;
    krnl_JOIN_INNER_TD_5277628 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_5277628.setup(tbl_Filter_TD_6257412_output, tbl_Filter_TD_6125439_output, tbl_JOIN_INNER_TD_5277628_output_preprocess, cfg_JOIN_INNER_TD_5277628_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_1785021;
    trans_JOIN_INNER_TD_1785021.setq(q_h);
    trans_JOIN_INNER_TD_1785021.add(&(cfg_JOIN_INNER_TD_1785021_cmds));
    transEngine trans_JOIN_INNER_TD_1785021_out;
    trans_JOIN_INNER_TD_1785021_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_2176142;
    trans_JOIN_INNER_TD_2176142.setq(q_h);
    trans_JOIN_INNER_TD_2176142.add(&(cfg_JOIN_INNER_TD_2176142_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_342355;
    trans_JOIN_INNER_TD_342355.setq(q_h);
    trans_JOIN_INNER_TD_342355.add(&(cfg_JOIN_INNER_TD_342355_cmds));
    q_h.finish();
    transEngine trans_Aggregate_TD_4463533;
    trans_Aggregate_TD_4463533.setq(q_a);
    trans_Aggregate_TD_4463533.add(&(cfg_Aggregate_TD_4463533_cmds));
    transEngine trans_Aggregate_TD_4463533_out;
    trans_Aggregate_TD_4463533_out.setq(q_a);
    q_a.finish();
    transEngine trans_JOIN_INNER_TD_5277628;
    trans_JOIN_INNER_TD_5277628.setq(q_h);
    trans_JOIN_INNER_TD_5277628.add(&(cfg_JOIN_INNER_TD_5277628_cmds));
    transEngine trans_JOIN_INNER_TD_5277628_out;
    trans_JOIN_INNER_TD_5277628_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_1785021;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_1785021;
    std::vector<cl::Event> events_JOIN_INNER_TD_1785021;
    events_h2d_wr_JOIN_INNER_TD_1785021.resize(1);
    events_d2h_rd_JOIN_INNER_TD_1785021.resize(1);
    events_JOIN_INNER_TD_1785021.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_1785021;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_1785021;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_2176142;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_2176142;
    std::vector<cl::Event> events_JOIN_INNER_TD_2176142;
    events_h2d_wr_JOIN_INNER_TD_2176142.resize(1);
    events_d2h_rd_JOIN_INNER_TD_2176142.resize(1);
    events_JOIN_INNER_TD_2176142.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_2176142;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_2176142;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_342355;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_342355;
    std::vector<cl::Event> events_JOIN_INNER_TD_342355;
    events_h2d_wr_JOIN_INNER_TD_342355.resize(1);
    events_d2h_rd_JOIN_INNER_TD_342355.resize(1);
    events_JOIN_INNER_TD_342355.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_342355;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_342355;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_4463533;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_4463533;
    std::vector<cl::Event> events_Aggregate_TD_4463533;
    events_h2d_wr_Aggregate_TD_4463533.resize(1);
    events_d2h_rd_Aggregate_TD_4463533.resize(1);
    events_Aggregate_TD_4463533.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_4463533;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_4463533;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_5277628;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_5277628;
    std::vector<cl::Event> events_JOIN_INNER_TD_5277628;
    events_h2d_wr_JOIN_INNER_TD_5277628.resize(1);
    events_d2h_rd_JOIN_INNER_TD_5277628.resize(1);
    events_JOIN_INNER_TD_5277628.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_5277628;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_5277628;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_6_318066_s, tv_r_Filter_6_318066_e;
    gettimeofday(&tv_r_Filter_6_318066_s, 0);
    SW_Filter_TD_6125439(tbl_SerializeFromObject_TD_7671180_input, tbl_Filter_TD_6125439_output);
    gettimeofday(&tv_r_Filter_6_318066_e, 0);

    struct timeval tv_r_Filter_6_528373_s, tv_r_Filter_6_528373_e;
    gettimeofday(&tv_r_Filter_6_528373_s, 0);
    SW_Filter_TD_6257412(tbl_SerializeFromObject_TD_7346119_input, tbl_Filter_TD_6257412_output);
    gettimeofday(&tv_r_Filter_6_528373_e, 0);

    struct timeval tv_r_JOIN_INNER_5_670009_s, tv_r_JOIN_INNER_5_670009_e;
    gettimeofday(&tv_r_JOIN_INNER_5_670009_s, 0);
    trans_JOIN_INNER_TD_5277628.add(&(tbl_Filter_TD_6257412_output));
    trans_JOIN_INNER_TD_5277628.add(&(tbl_Filter_TD_6125439_output));
    trans_JOIN_INNER_TD_5277628.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_5277628), &(events_h2d_wr_JOIN_INNER_TD_5277628[0]));
    events_grp_JOIN_INNER_TD_5277628.push_back(events_h2d_wr_JOIN_INNER_TD_5277628[0]);
    krnl_JOIN_INNER_TD_5277628.run(0, &(events_grp_JOIN_INNER_TD_5277628), &(events_JOIN_INNER_TD_5277628[0]));
    
    trans_JOIN_INNER_TD_5277628_out.add(&(tbl_JOIN_INNER_TD_5277628_output_preprocess));
    trans_JOIN_INNER_TD_5277628_out.dev2host(0, &(events_JOIN_INNER_TD_5277628), &(events_d2h_rd_JOIN_INNER_TD_5277628[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_5277628);
    tbl_JOIN_INNER_TD_5277628_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_5277628_output));
    gettimeofday(&tv_r_JOIN_INNER_5_670009_e, 0);

    struct timeval tv_r_Aggregate_4_490508_s, tv_r_Aggregate_4_490508_e;
    gettimeofday(&tv_r_Aggregate_4_490508_s, 0);
    trans_Aggregate_TD_4463533.add(&(tbl_JOIN_INNER_TD_5277628_output));
    trans_Aggregate_TD_4463533.host2dev(0, &(prev_events_grp_Aggregate_TD_4463533), &(events_h2d_wr_Aggregate_TD_4463533[0]));
    events_grp_Aggregate_TD_4463533.push_back(events_h2d_wr_Aggregate_TD_4463533[0]);
    krnl_Aggregate_TD_4463533.run(0, &(events_grp_Aggregate_TD_4463533), &(events_Aggregate_TD_4463533[0]));
    
    trans_Aggregate_TD_4463533_out.add(&(tbl_Aggregate_TD_4463533_output_preprocess));
    trans_Aggregate_TD_4463533_out.dev2host(0, &(events_Aggregate_TD_4463533), &(events_d2h_rd_Aggregate_TD_4463533[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_4463533_consolidate(tbl_Aggregate_TD_4463533_output_preprocess, tbl_Aggregate_TD_4463533_output);
    gettimeofday(&tv_r_Aggregate_4_490508_e, 0);

    struct timeval tv_r_Filter_4_865707_s, tv_r_Filter_4_865707_e;
    gettimeofday(&tv_r_Filter_4_865707_s, 0);
    SW_Filter_TD_4774196(tbl_SerializeFromObject_TD_5497117_input, tbl_Filter_TD_4774196_output);
    gettimeofday(&tv_r_Filter_4_865707_e, 0);

    struct timeval tv_r_Filter_4_336734_s, tv_r_Filter_4_336734_e;
    gettimeofday(&tv_r_Filter_4_336734_s, 0);
    SW_Filter_TD_477201(tbl_SerializeFromObject_TD_5726134_input, tbl_Filter_TD_477201_output);
    gettimeofday(&tv_r_Filter_4_336734_e, 0);

    struct timeval tv_r_Filter_3_68460_s, tv_r_Filter_3_68460_e;
    gettimeofday(&tv_r_Filter_3_68460_s, 0);
    SW_Filter_TD_3919242(tbl_Aggregate_TD_4463533_output, tbl_Filter_TD_3919242_output);
    gettimeofday(&tv_r_Filter_3_68460_e, 0);

    struct timeval tv_r_JOIN_INNER_3_480741_s, tv_r_JOIN_INNER_3_480741_e;
    gettimeofday(&tv_r_JOIN_INNER_3_480741_s, 0);
    trans_JOIN_INNER_TD_342355.add(&(tbl_Filter_TD_477201_output));
    trans_JOIN_INNER_TD_342355.add(&(tbl_Filter_TD_4774196_output));
    trans_JOIN_INNER_TD_342355.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_342355), &(events_h2d_wr_JOIN_INNER_TD_342355[0]));
    events_grp_JOIN_INNER_TD_342355.push_back(events_h2d_wr_JOIN_INNER_TD_342355[0]);
    krnl_JOIN_INNER_TD_342355.run(0, &(events_grp_JOIN_INNER_TD_342355), &(events_JOIN_INNER_TD_342355[0]));
    gettimeofday(&tv_r_JOIN_INNER_3_480741_e, 0);

    struct timeval tv_r_Filter_2_833393_s, tv_r_Filter_2_833393_e;
    gettimeofday(&tv_r_Filter_2_833393_s, 0);
    SW_Filter_TD_2823943(tbl_SerializeFromObject_TD_3720904_input, tbl_Filter_TD_2823943_output);
    gettimeofday(&tv_r_Filter_2_833393_e, 0);

    struct timeval tv_r_JOIN_INNER_2_794929_s, tv_r_JOIN_INNER_2_794929_e;
    gettimeofday(&tv_r_JOIN_INNER_2_794929_s, 0);
    prev_events_grp_JOIN_INNER_TD_2176142.push_back(events_h2d_wr_JOIN_INNER_TD_342355[0]);
    trans_JOIN_INNER_TD_2176142.add(&(tbl_Filter_TD_3919242_output));
    trans_JOIN_INNER_TD_2176142.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_2176142), &(events_h2d_wr_JOIN_INNER_TD_2176142[0]));
    events_grp_JOIN_INNER_TD_2176142.push_back(events_h2d_wr_JOIN_INNER_TD_2176142[0]);
    events_grp_JOIN_INNER_TD_2176142.push_back(events_JOIN_INNER_TD_342355[0]);
    krnl_JOIN_INNER_TD_2176142.run(0, &(events_grp_JOIN_INNER_TD_2176142), &(events_JOIN_INNER_TD_2176142[0]));
    gettimeofday(&tv_r_JOIN_INNER_2_794929_e, 0);

    struct timeval tv_r_JOIN_INNER_1_337039_s, tv_r_JOIN_INNER_1_337039_e;
    gettimeofday(&tv_r_JOIN_INNER_1_337039_s, 0);
    prev_events_grp_JOIN_INNER_TD_1785021.push_back(events_h2d_wr_JOIN_INNER_TD_2176142[0]);
    trans_JOIN_INNER_TD_1785021.add(&(tbl_Filter_TD_2823943_output));
    trans_JOIN_INNER_TD_1785021.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_1785021), &(events_h2d_wr_JOIN_INNER_TD_1785021[0]));
    events_grp_JOIN_INNER_TD_1785021.push_back(events_h2d_wr_JOIN_INNER_TD_1785021[0]);
    events_grp_JOIN_INNER_TD_1785021.push_back(events_JOIN_INNER_TD_2176142[0]);
    krnl_JOIN_INNER_TD_1785021.run(0, &(events_grp_JOIN_INNER_TD_1785021), &(events_JOIN_INNER_TD_1785021[0]));
    
    trans_JOIN_INNER_TD_1785021_out.add(&(tbl_JOIN_INNER_TD_1785021_output));
    trans_JOIN_INNER_TD_1785021_out.dev2host(0, &(events_JOIN_INNER_TD_1785021), &(events_d2h_rd_JOIN_INNER_TD_1785021[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_1_337039_e, 0);

    struct timeval tv_r_Aggregate_0_691721_s, tv_r_Aggregate_0_691721_e;
    gettimeofday(&tv_r_Aggregate_0_691721_s, 0);
    SW_Aggregate_TD_012180(tbl_JOIN_INNER_TD_1785021_output, tbl_Aggregate_TD_012180_output);
    gettimeofday(&tv_r_Aggregate_0_691721_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_318066_s, &tv_r_Filter_6_318066_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7671180_input: " << tbl_SerializeFromObject_TD_7671180_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_528373_s, &tv_r_Filter_6_528373_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7346119_input: " << tbl_SerializeFromObject_TD_7346119_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_670009_s, &tv_r_JOIN_INNER_5_670009_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6257412_output: " << tbl_Filter_TD_6257412_output.getNumRow() << " " << "tbl_Filter_TD_6125439_output: " << tbl_Filter_TD_6125439_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_4: " << tvdiff(&tv_r_Aggregate_4_490508_s, &tv_r_Aggregate_4_490508_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5277628_output: " << tbl_JOIN_INNER_TD_5277628_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_865707_s, &tv_r_Filter_4_865707_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5497117_input: " << tbl_SerializeFromObject_TD_5497117_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_336734_s, &tv_r_Filter_4_336734_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5726134_input: " << tbl_SerializeFromObject_TD_5726134_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_68460_s, &tv_r_Filter_3_68460_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_4463533_output: " << tbl_Aggregate_TD_4463533_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_480741_s, &tv_r_JOIN_INNER_3_480741_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_477201_output: " << tbl_Filter_TD_477201_output.getNumRow() << " " << "tbl_Filter_TD_4774196_output: " << tbl_Filter_TD_4774196_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_833393_s, &tv_r_Filter_2_833393_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3720904_input: " << tbl_SerializeFromObject_TD_3720904_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_2: " << tvdiff(&tv_r_JOIN_INNER_2_794929_s, &tv_r_JOIN_INNER_2_794929_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_342355_output: " << tbl_JOIN_INNER_TD_342355_output.getNumRow() << " " << "tbl_Filter_TD_3919242_output: " << tbl_Filter_TD_3919242_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_1: " << tvdiff(&tv_r_JOIN_INNER_1_337039_s, &tv_r_JOIN_INNER_1_337039_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_2176142_output: " << tbl_JOIN_INNER_TD_2176142_output.getNumRow() << " " << "tbl_Filter_TD_2823943_output: " << tbl_Filter_TD_2823943_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_0: " << tvdiff(&tv_r_Aggregate_0_691721_s, &tv_r_Aggregate_0_691721_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_1785021_output: " << tbl_JOIN_INNER_TD_1785021_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.2224259 * 1000 << "ms" << std::endl; 
    return 0; 
}
