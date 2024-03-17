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

#include "cfgFunc_q44.hpp" 
#include "q44.hpp" 

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
    std::cout << "NOTE:running query #44\n."; 
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
    Table tbl_GlobalLimit_TD_0501983_output("tbl_GlobalLimit_TD_0501983_output", 6100000, 3, "");
    tbl_GlobalLimit_TD_0501983_output.allocateHost();
    Table tbl_LocalLimit_TD_1740878_output("tbl_LocalLimit_TD_1740878_output", 6100000, 3, "");
    tbl_LocalLimit_TD_1740878_output.allocateHost();
    Table tbl_Sort_TD_252860_output("tbl_Sort_TD_252860_output", 6100000, 3, "");
    tbl_Sort_TD_252860_output.allocateHost();
    Table tbl_Project_TD_3167661_output("tbl_Project_TD_3167661_output", 6100000, 3, "");
    tbl_Project_TD_3167661_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4252493_output("tbl_JOIN_INNER_TD_4252493_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_4252493_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5576240_output("tbl_JOIN_INNER_TD_5576240_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_5576240_output.allocateHost();
    Table tbl_Filter_TD_5658199_output("tbl_Filter_TD_5658199_output", 6100000, 2, "");
    tbl_Filter_TD_5658199_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6645449_output("tbl_JOIN_INNER_TD_6645449_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_6645449_output.allocateHost();
    Table tbl_Filter_TD_6323366_output("tbl_Filter_TD_6323366_output", 6100000, 2, "");
    tbl_Filter_TD_6323366_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6863009_input;
    tbl_SerializeFromObject_TD_6863009_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_6863009_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_6863009_input.addCol("i_product_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6863009_input.allocateHost();
    tbl_SerializeFromObject_TD_6863009_input.loadHost();
    Table tbl_Filter_TD_7441872_output("tbl_Filter_TD_7441872_output", 6100000, 2, "");
    tbl_Filter_TD_7441872_output.allocateHost();
    Table tbl_Filter_TD_7754331_output("tbl_Filter_TD_7754331_output", 6100000, 2, "");
    tbl_Filter_TD_7754331_output.allocateHost();
    Table tbl_SerializeFromObject_TD_786427_input;
    tbl_SerializeFromObject_TD_786427_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_786427_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_786427_input.addCol("i_product_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_786427_input.allocateHost();
    tbl_SerializeFromObject_TD_786427_input.loadHost();
    Table tbl_Window_TD_8700488_output("tbl_Window_TD_8700488_output", 6100000, 3, "");
    tbl_Window_TD_8700488_output.allocateHost();
    Table tbl_Window_TD_817373_output("tbl_Window_TD_817373_output", 6100000, 3, "");
    tbl_Window_TD_817373_output.allocateHost();
    Table tbl_Filter_TD_9372422_output("tbl_Filter_TD_9372422_output", 6100000, 2, "");
    tbl_Filter_TD_9372422_output.allocateHost();
    Table tbl_Filter_TD_9678502_output("tbl_Filter_TD_9678502_output", 6100000, 2, "");
    tbl_Filter_TD_9678502_output.allocateHost();
    Table tbl_Aggregate_TD_10147165_output("tbl_Aggregate_TD_10147165_output", 6100000, 2, "");
    tbl_Aggregate_TD_10147165_output.allocateHost();
    Table tbl_Aggregate_TD_10335950_output_preprocess("tbl_Aggregate_TD_10335950_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_10335950_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_10335950_output("tbl_Aggregate_TD_10335950_output", 6100000, 1, "");
    tbl_Aggregate_TD_10335950_output.allocateHost();
    Table tbl_Aggregate_TD_10722913_output("tbl_Aggregate_TD_10722913_output", 6100000, 2, "");
    tbl_Aggregate_TD_10722913_output.allocateHost();
    Table tbl_Aggregate_TD_10584880_output_preprocess("tbl_Aggregate_TD_10584880_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_10584880_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_10584880_output("tbl_Aggregate_TD_10584880_output", 6100000, 1, "");
    tbl_Aggregate_TD_10584880_output.allocateHost();
    Table tbl_Filter_TD_11742844_output("tbl_Filter_TD_11742844_output", 6100000, 2, "");
    tbl_Filter_TD_11742844_output.allocateHost();
    Table tbl_Filter_TD_11331822_output("tbl_Filter_TD_11331822_output", 6100000, 2, "");
    tbl_Filter_TD_11331822_output.allocateHost();
    Table tbl_Filter_TD_11594691_output("tbl_Filter_TD_11594691_output", 6100000, 2, "");
    tbl_Filter_TD_11594691_output.allocateHost();
    Table tbl_Filter_TD_11517063_output("tbl_Filter_TD_11517063_output", 6100000, 2, "");
    tbl_Filter_TD_11517063_output.allocateHost();
    Table tbl_SerializeFromObject_TD_12733181_input;
    tbl_SerializeFromObject_TD_12733181_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_12733181_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_12733181_input.addCol("ss_net_profit", 4);
    tbl_SerializeFromObject_TD_12733181_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_12733181_input.allocateHost();
    tbl_SerializeFromObject_TD_12733181_input.loadHost();
    Table tbl_SerializeFromObject_TD_12371888_input;
    tbl_SerializeFromObject_TD_12371888_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_12371888_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_12371888_input.addCol("ss_net_profit", 4);
    tbl_SerializeFromObject_TD_12371888_input.addCol("ss_addr_sk", 4);
    tbl_SerializeFromObject_TD_12371888_input.allocateHost();
    tbl_SerializeFromObject_TD_12371888_input.loadHost();
    Table tbl_SerializeFromObject_TD_12240194_input;
    tbl_SerializeFromObject_TD_12240194_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_12240194_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_12240194_input.addCol("ss_net_profit", 4);
    tbl_SerializeFromObject_TD_12240194_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_12240194_input.allocateHost();
    tbl_SerializeFromObject_TD_12240194_input.loadHost();
    Table tbl_SerializeFromObject_TD_12831297_input;
    tbl_SerializeFromObject_TD_12831297_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_12831297_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_12831297_input.addCol("ss_net_profit", 4);
    tbl_SerializeFromObject_TD_12831297_input.addCol("ss_addr_sk", 4);
    tbl_SerializeFromObject_TD_12831297_input.allocateHost();
    tbl_SerializeFromObject_TD_12831297_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_6645449_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_7441872_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_7754331_output.allocateDevBuffer(context_h, 32);
    tbl_Aggregate_TD_10335950_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_Aggregate_TD_10584880_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_Filter_TD_11331822_output.allocateDevBuffer(context_a, 32);
    tbl_Filter_TD_11517063_output.allocateDevBuffer(context_a, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_6645449_cmds;
    cfg_JOIN_INNER_TD_6645449_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_6645449_gqe_join (cfg_JOIN_INNER_TD_6645449_cmds.cmd);
    cfg_JOIN_INNER_TD_6645449_cmds.allocateDevBuffer(context_h, 32);
    AggrCfgCmd cfg_Aggregate_TD_10335950_cmds;
    cfg_Aggregate_TD_10335950_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_10335950_gqe_aggr(cfg_Aggregate_TD_10335950_cmds.cmd);
    cfg_Aggregate_TD_10335950_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_10335950_cmds_out;
    cfg_Aggregate_TD_10335950_cmds_out.allocateHost();
    cfg_Aggregate_TD_10335950_cmds_out.allocateDevBuffer(context_a, 33);
    AggrCfgCmd cfg_Aggregate_TD_10584880_cmds;
    cfg_Aggregate_TD_10584880_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_10584880_gqe_aggr(cfg_Aggregate_TD_10584880_cmds.cmd);
    cfg_Aggregate_TD_10584880_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_10584880_cmds_out;
    cfg_Aggregate_TD_10584880_cmds_out.allocateHost();
    cfg_Aggregate_TD_10584880_cmds_out.allocateDevBuffer(context_a, 33);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    AggrBufferTmp buftmp_a(context_a); 
    buftmp_a.BufferInitial(q_a); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_6645449;
    krnl_JOIN_INNER_TD_6645449 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_6645449.setup(tbl_Filter_TD_7441872_output, tbl_Filter_TD_7754331_output, tbl_JOIN_INNER_TD_6645449_output, cfg_JOIN_INNER_TD_6645449_cmds, buftmp_h);
    AggrKrnlEngine krnl_Aggregate_TD_10335950;
    krnl_Aggregate_TD_10335950 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_10335950.setup(tbl_Filter_TD_11331822_output, tbl_Aggregate_TD_10335950_output_preprocess, cfg_Aggregate_TD_10335950_cmds, cfg_Aggregate_TD_10335950_cmds_out, buftmp_a);
    AggrKrnlEngine krnl_Aggregate_TD_10584880;
    krnl_Aggregate_TD_10584880 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_10584880.setup(tbl_Filter_TD_11517063_output, tbl_Aggregate_TD_10584880_output_preprocess, cfg_Aggregate_TD_10584880_cmds, cfg_Aggregate_TD_10584880_cmds_out, buftmp_a);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_6645449;
    trans_JOIN_INNER_TD_6645449.setq(q_h);
    trans_JOIN_INNER_TD_6645449.add(&(cfg_JOIN_INNER_TD_6645449_cmds));
    transEngine trans_JOIN_INNER_TD_6645449_out;
    trans_JOIN_INNER_TD_6645449_out.setq(q_h);
    q_h.finish();
    transEngine trans_Aggregate_TD_10335950;
    trans_Aggregate_TD_10335950.setq(q_a);
    trans_Aggregate_TD_10335950.add(&(cfg_Aggregate_TD_10335950_cmds));
    transEngine trans_Aggregate_TD_10335950_out;
    trans_Aggregate_TD_10335950_out.setq(q_a);
    q_a.finish();
    transEngine trans_Aggregate_TD_10584880;
    trans_Aggregate_TD_10584880.setq(q_a);
    trans_Aggregate_TD_10584880.add(&(cfg_Aggregate_TD_10584880_cmds));
    transEngine trans_Aggregate_TD_10584880_out;
    trans_Aggregate_TD_10584880_out.setq(q_a);
    q_a.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_6645449;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_6645449;
    std::vector<cl::Event> events_JOIN_INNER_TD_6645449;
    events_h2d_wr_JOIN_INNER_TD_6645449.resize(1);
    events_d2h_rd_JOIN_INNER_TD_6645449.resize(1);
    events_JOIN_INNER_TD_6645449.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_6645449;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_6645449;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_10335950;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_10335950;
    std::vector<cl::Event> events_Aggregate_TD_10335950;
    events_h2d_wr_Aggregate_TD_10335950.resize(1);
    events_d2h_rd_Aggregate_TD_10335950.resize(1);
    events_Aggregate_TD_10335950.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_10335950;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_10335950;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_10584880;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_10584880;
    std::vector<cl::Event> events_Aggregate_TD_10584880;
    events_h2d_wr_Aggregate_TD_10584880.resize(1);
    events_d2h_rd_Aggregate_TD_10584880.resize(1);
    events_Aggregate_TD_10584880.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_10584880;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_10584880;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_11_204171_s, tv_r_Filter_11_204171_e;
    gettimeofday(&tv_r_Filter_11_204171_s, 0);
    SW_Filter_TD_11517063(tbl_SerializeFromObject_TD_12831297_input, tbl_Filter_TD_11517063_output);
    gettimeofday(&tv_r_Filter_11_204171_e, 0);

    struct timeval tv_r_Filter_11_720393_s, tv_r_Filter_11_720393_e;
    gettimeofday(&tv_r_Filter_11_720393_s, 0);
    SW_Filter_TD_11594691(tbl_SerializeFromObject_TD_12240194_input, tbl_Filter_TD_11594691_output);
    gettimeofday(&tv_r_Filter_11_720393_e, 0);

    struct timeval tv_r_Filter_11_763468_s, tv_r_Filter_11_763468_e;
    gettimeofday(&tv_r_Filter_11_763468_s, 0);
    SW_Filter_TD_11331822(tbl_SerializeFromObject_TD_12371888_input, tbl_Filter_TD_11331822_output);
    gettimeofday(&tv_r_Filter_11_763468_e, 0);

    struct timeval tv_r_Filter_11_700623_s, tv_r_Filter_11_700623_e;
    gettimeofday(&tv_r_Filter_11_700623_s, 0);
    SW_Filter_TD_11742844(tbl_SerializeFromObject_TD_12733181_input, tbl_Filter_TD_11742844_output);
    gettimeofday(&tv_r_Filter_11_700623_e, 0);

    struct timeval tv_r_Aggregate_10_600224_s, tv_r_Aggregate_10_600224_e;
    gettimeofday(&tv_r_Aggregate_10_600224_s, 0);
    trans_Aggregate_TD_10584880.add(&(tbl_Filter_TD_11517063_output));
    trans_Aggregate_TD_10584880.host2dev(0, &(prev_events_grp_Aggregate_TD_10584880), &(events_h2d_wr_Aggregate_TD_10584880[0]));
    events_grp_Aggregate_TD_10584880.push_back(events_h2d_wr_Aggregate_TD_10584880[0]);
    krnl_Aggregate_TD_10584880.run(0, &(events_grp_Aggregate_TD_10584880), &(events_Aggregate_TD_10584880[0]));
    
    trans_Aggregate_TD_10584880_out.add(&(tbl_Aggregate_TD_10584880_output_preprocess));
    trans_Aggregate_TD_10584880_out.dev2host(0, &(events_Aggregate_TD_10584880), &(events_d2h_rd_Aggregate_TD_10584880[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_10584880_consolidate(tbl_Aggregate_TD_10584880_output_preprocess, tbl_Aggregate_TD_10584880_output);
    gettimeofday(&tv_r_Aggregate_10_600224_e, 0);

    struct timeval tv_r_Aggregate_10_347839_s, tv_r_Aggregate_10_347839_e;
    gettimeofday(&tv_r_Aggregate_10_347839_s, 0);
    SW_Aggregate_TD_10722913(tbl_Filter_TD_11594691_output, tbl_Aggregate_TD_10722913_output);
    gettimeofday(&tv_r_Aggregate_10_347839_e, 0);

    struct timeval tv_r_Aggregate_10_687998_s, tv_r_Aggregate_10_687998_e;
    gettimeofday(&tv_r_Aggregate_10_687998_s, 0);
    trans_Aggregate_TD_10335950.add(&(tbl_Filter_TD_11331822_output));
    trans_Aggregate_TD_10335950.host2dev(0, &(prev_events_grp_Aggregate_TD_10335950), &(events_h2d_wr_Aggregate_TD_10335950[0]));
    events_grp_Aggregate_TD_10335950.push_back(events_h2d_wr_Aggregate_TD_10335950[0]);
    krnl_Aggregate_TD_10335950.run(0, &(events_grp_Aggregate_TD_10335950), &(events_Aggregate_TD_10335950[0]));
    
    trans_Aggregate_TD_10335950_out.add(&(tbl_Aggregate_TD_10335950_output_preprocess));
    trans_Aggregate_TD_10335950_out.dev2host(0, &(events_Aggregate_TD_10335950), &(events_d2h_rd_Aggregate_TD_10335950[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_10335950_consolidate(tbl_Aggregate_TD_10335950_output_preprocess, tbl_Aggregate_TD_10335950_output);
    gettimeofday(&tv_r_Aggregate_10_687998_e, 0);

    struct timeval tv_r_Aggregate_10_963676_s, tv_r_Aggregate_10_963676_e;
    gettimeofday(&tv_r_Aggregate_10_963676_s, 0);
    SW_Aggregate_TD_10147165(tbl_Filter_TD_11742844_output, tbl_Aggregate_TD_10147165_output);
    gettimeofday(&tv_r_Aggregate_10_963676_e, 0);

    struct timeval tv_r_Filter_9_60281_s, tv_r_Filter_9_60281_e;
    gettimeofday(&tv_r_Filter_9_60281_s, 0);
    SW_Filter_TD_9678502(tbl_Aggregate_TD_10722913_output, tbl_Aggregate_TD_10584880_output, tbl_Filter_TD_9678502_output);
    gettimeofday(&tv_r_Filter_9_60281_e, 0);

    struct timeval tv_r_Filter_9_140882_s, tv_r_Filter_9_140882_e;
    gettimeofday(&tv_r_Filter_9_140882_s, 0);
    SW_Filter_TD_9372422(tbl_Aggregate_TD_10147165_output, tbl_Aggregate_TD_10335950_output, tbl_Filter_TD_9372422_output);
    gettimeofday(&tv_r_Filter_9_140882_e, 0);

    struct timeval tv_r_Window_8_813675_s, tv_r_Window_8_813675_e;
    gettimeofday(&tv_r_Window_8_813675_s, 0);
    SW_Window_TD_817373(tbl_Filter_TD_9678502_output, tbl_Window_TD_817373_output);
    gettimeofday(&tv_r_Window_8_813675_e, 0);

    struct timeval tv_r_Window_8_582111_s, tv_r_Window_8_582111_e;
    gettimeofday(&tv_r_Window_8_582111_s, 0);
    SW_Window_TD_8700488(tbl_Filter_TD_9372422_output, tbl_Window_TD_8700488_output);
    gettimeofday(&tv_r_Window_8_582111_e, 0);

    struct timeval tv_r_Filter_7_249887_s, tv_r_Filter_7_249887_e;
    gettimeofday(&tv_r_Filter_7_249887_s, 0);
    SW_Filter_TD_7754331(tbl_Window_TD_817373_output, tbl_Filter_TD_7754331_output);
    gettimeofday(&tv_r_Filter_7_249887_e, 0);

    struct timeval tv_r_Filter_7_137810_s, tv_r_Filter_7_137810_e;
    gettimeofday(&tv_r_Filter_7_137810_s, 0);
    SW_Filter_TD_7441872(tbl_Window_TD_8700488_output, tbl_Filter_TD_7441872_output);
    gettimeofday(&tv_r_Filter_7_137810_e, 0);

    struct timeval tv_r_Filter_6_405568_s, tv_r_Filter_6_405568_e;
    gettimeofday(&tv_r_Filter_6_405568_s, 0);
    SW_Filter_TD_6323366(tbl_SerializeFromObject_TD_786427_input, tbl_Filter_TD_6323366_output);
    gettimeofday(&tv_r_Filter_6_405568_e, 0);

    struct timeval tv_r_JOIN_INNER_6_362547_s, tv_r_JOIN_INNER_6_362547_e;
    gettimeofday(&tv_r_JOIN_INNER_6_362547_s, 0);
    trans_JOIN_INNER_TD_6645449.add(&(tbl_Filter_TD_7441872_output));
    trans_JOIN_INNER_TD_6645449.add(&(tbl_Filter_TD_7754331_output));
    trans_JOIN_INNER_TD_6645449.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_6645449), &(events_h2d_wr_JOIN_INNER_TD_6645449[0]));
    events_grp_JOIN_INNER_TD_6645449.push_back(events_h2d_wr_JOIN_INNER_TD_6645449[0]);
    krnl_JOIN_INNER_TD_6645449.run(0, &(events_grp_JOIN_INNER_TD_6645449), &(events_JOIN_INNER_TD_6645449[0]));
    
    trans_JOIN_INNER_TD_6645449_out.add(&(tbl_JOIN_INNER_TD_6645449_output));
    trans_JOIN_INNER_TD_6645449_out.dev2host(0, &(events_JOIN_INNER_TD_6645449), &(events_d2h_rd_JOIN_INNER_TD_6645449[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_6_362547_e, 0);

    struct timeval tv_r_Filter_5_360508_s, tv_r_Filter_5_360508_e;
    gettimeofday(&tv_r_Filter_5_360508_s, 0);
    SW_Filter_TD_5658199(tbl_SerializeFromObject_TD_6863009_input, tbl_Filter_TD_5658199_output);
    gettimeofday(&tv_r_Filter_5_360508_e, 0);

    struct timeval tv_r_JOIN_INNER_5_675041_s, tv_r_JOIN_INNER_5_675041_e;
    gettimeofday(&tv_r_JOIN_INNER_5_675041_s, 0);
    SW_JOIN_INNER_TD_5576240(tbl_JOIN_INNER_TD_6645449_output, tbl_Filter_TD_6323366_output, tbl_JOIN_INNER_TD_5576240_output);
    gettimeofday(&tv_r_JOIN_INNER_5_675041_e, 0);

    struct timeval tv_r_JOIN_INNER_4_815176_s, tv_r_JOIN_INNER_4_815176_e;
    gettimeofday(&tv_r_JOIN_INNER_4_815176_s, 0);
    SW_JOIN_INNER_TD_4252493(tbl_JOIN_INNER_TD_5576240_output, tbl_Filter_TD_5658199_output, tbl_JOIN_INNER_TD_4252493_output);
    gettimeofday(&tv_r_JOIN_INNER_4_815176_e, 0);

    struct timeval tv_r_Project_3_467712_s, tv_r_Project_3_467712_e;
    gettimeofday(&tv_r_Project_3_467712_s, 0);
    SW_Project_TD_3167661(tbl_JOIN_INNER_TD_4252493_output, tbl_Project_TD_3167661_output);
    gettimeofday(&tv_r_Project_3_467712_e, 0);

    struct timeval tv_r_Sort_2_692888_s, tv_r_Sort_2_692888_e;
    gettimeofday(&tv_r_Sort_2_692888_s, 0);
    SW_Sort_TD_252860(tbl_Project_TD_3167661_output, tbl_Sort_TD_252860_output);
    gettimeofday(&tv_r_Sort_2_692888_e, 0);

    struct timeval tv_r_LocalLimit_1_567375_s, tv_r_LocalLimit_1_567375_e;
    gettimeofday(&tv_r_LocalLimit_1_567375_s, 0);
    SW_LocalLimit_TD_1740878(tbl_Sort_TD_252860_output, tbl_LocalLimit_TD_1740878_output);
    gettimeofday(&tv_r_LocalLimit_1_567375_e, 0);

    struct timeval tv_r_GlobalLimit_0_364730_s, tv_r_GlobalLimit_0_364730_e;
    gettimeofday(&tv_r_GlobalLimit_0_364730_s, 0);
    SW_GlobalLimit_TD_0501983(tbl_LocalLimit_TD_1740878_output, tbl_GlobalLimit_TD_0501983_output);
    gettimeofday(&tv_r_GlobalLimit_0_364730_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_204171_s, &tv_r_Filter_11_204171_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12831297_input: " << tbl_SerializeFromObject_TD_12831297_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_720393_s, &tv_r_Filter_11_720393_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12240194_input: " << tbl_SerializeFromObject_TD_12240194_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_763468_s, &tv_r_Filter_11_763468_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12371888_input: " << tbl_SerializeFromObject_TD_12371888_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_700623_s, &tv_r_Filter_11_700623_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12733181_input: " << tbl_SerializeFromObject_TD_12733181_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_10: " << tvdiff(&tv_r_Aggregate_10_600224_s, &tv_r_Aggregate_10_600224_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11517063_output: " << tbl_Filter_TD_11517063_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_10: " << tvdiff(&tv_r_Aggregate_10_347839_s, &tv_r_Aggregate_10_347839_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11594691_output: " << tbl_Filter_TD_11594691_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_10: " << tvdiff(&tv_r_Aggregate_10_687998_s, &tv_r_Aggregate_10_687998_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11331822_output: " << tbl_Filter_TD_11331822_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_10: " << tvdiff(&tv_r_Aggregate_10_963676_s, &tv_r_Aggregate_10_963676_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11742844_output: " << tbl_Filter_TD_11742844_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_60281_s, &tv_r_Filter_9_60281_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_10722913_output: " << tbl_Aggregate_TD_10722913_output.getNumRow() << " " << "tbl_Aggregate_TD_10584880_output: " << tbl_Aggregate_TD_10584880_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_140882_s, &tv_r_Filter_9_140882_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_10147165_output: " << tbl_Aggregate_TD_10147165_output.getNumRow() << " " << "tbl_Aggregate_TD_10335950_output: " << tbl_Aggregate_TD_10335950_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_8: " << tvdiff(&tv_r_Window_8_813675_s, &tv_r_Window_8_813675_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9678502_output: " << tbl_Filter_TD_9678502_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_8: " << tvdiff(&tv_r_Window_8_582111_s, &tv_r_Window_8_582111_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9372422_output: " << tbl_Filter_TD_9372422_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_249887_s, &tv_r_Filter_7_249887_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_817373_output: " << tbl_Window_TD_817373_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_137810_s, &tv_r_Filter_7_137810_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_8700488_output: " << tbl_Window_TD_8700488_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_405568_s, &tv_r_Filter_6_405568_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_786427_input: " << tbl_SerializeFromObject_TD_786427_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_362547_s, &tv_r_JOIN_INNER_6_362547_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_7441872_output: " << tbl_Filter_TD_7441872_output.getNumRow() << " " << "tbl_Filter_TD_7754331_output: " << tbl_Filter_TD_7754331_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_360508_s, &tv_r_Filter_5_360508_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6863009_input: " << tbl_SerializeFromObject_TD_6863009_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_675041_s, &tv_r_JOIN_INNER_5_675041_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6645449_output: " << tbl_JOIN_INNER_TD_6645449_output.getNumRow() << " " << "tbl_Filter_TD_6323366_output: " << tbl_Filter_TD_6323366_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_815176_s, &tv_r_JOIN_INNER_4_815176_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5576240_output: " << tbl_JOIN_INNER_TD_5576240_output.getNumRow() << " " << "tbl_Filter_TD_5658199_output: " << tbl_Filter_TD_5658199_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_3: " << tvdiff(&tv_r_Project_3_467712_s, &tv_r_Project_3_467712_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4252493_output: " << tbl_JOIN_INNER_TD_4252493_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_692888_s, &tv_r_Sort_2_692888_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_3167661_output: " << tbl_Project_TD_3167661_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_567375_s, &tv_r_LocalLimit_1_567375_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_252860_output: " << tbl_Sort_TD_252860_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_364730_s, &tv_r_GlobalLimit_0_364730_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1740878_output: " << tbl_LocalLimit_TD_1740878_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.434645 * 1000 << "ms" << std::endl; 
    return 0; 
}
