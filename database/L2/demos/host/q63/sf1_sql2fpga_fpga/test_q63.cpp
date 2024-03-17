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

#include "cfgFunc_q63.hpp" 
#include "q63.hpp" 

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
    std::cout << "NOTE:running query #63\n."; 
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
    Table tbl_GlobalLimit_TD_0427754_output("tbl_GlobalLimit_TD_0427754_output", 6100000, 3, "");
    tbl_GlobalLimit_TD_0427754_output.allocateHost();
    Table tbl_LocalLimit_TD_1586201_output("tbl_LocalLimit_TD_1586201_output", 6100000, 3, "");
    tbl_LocalLimit_TD_1586201_output.allocateHost();
    Table tbl_Sort_TD_2283574_output("tbl_Sort_TD_2283574_output", 6100000, 3, "");
    tbl_Sort_TD_2283574_output.allocateHost();
    Table tbl_Filter_TD_3970267_output("tbl_Filter_TD_3970267_output", 6100000, 3, "");
    tbl_Filter_TD_3970267_output.allocateHost();
    Table tbl_Window_TD_4163701_output("tbl_Window_TD_4163701_output", 6100000, 4, "");
    tbl_Window_TD_4163701_output.allocateHost();
    Table tbl_Aggregate_TD_5904487_output_preprocess("tbl_Aggregate_TD_5904487_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_5904487_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_5904487_output("tbl_Aggregate_TD_5904487_output", 6100000, 3, "");
    tbl_Aggregate_TD_5904487_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6480946_output_preprocess("tbl_JOIN_INNER_TD_6480946_output_preprocess", 6100000, 3, "");
    tbl_JOIN_INNER_TD_6480946_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_6480946_output("tbl_JOIN_INNER_TD_6480946_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_6480946_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7598577_output("tbl_JOIN_INNER_TD_7598577_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_7598577_output.allocateHost();
    Table tbl_Filter_TD_7790009_output("tbl_Filter_TD_7790009_output", 6100000, 1, "");
    tbl_Filter_TD_7790009_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8516482_output("tbl_JOIN_INNER_TD_8516482_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_8516482_output.allocateHost();
    Table tbl_Filter_TD_8214873_output("tbl_Filter_TD_8214873_output", 6100000, 2, "");
    tbl_Filter_TD_8214873_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8635282_input;
    tbl_SerializeFromObject_TD_8635282_input = Table("store", store_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_8635282_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_8635282_input.allocateHost();
    tbl_SerializeFromObject_TD_8635282_input.loadHost();
    Table tbl_Filter_TD_9228880_output("tbl_Filter_TD_9228880_output", 6100000, 2, "");
    tbl_Filter_TD_9228880_output.allocateHost();
    Table tbl_Filter_TD_9687484_output("tbl_Filter_TD_9687484_output", 6100000, 4, "");
    tbl_Filter_TD_9687484_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9988462_input;
    tbl_SerializeFromObject_TD_9988462_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9988462_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_9988462_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_9988462_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_9988462_input.allocateHost();
    tbl_SerializeFromObject_TD_9988462_input.loadHost();
    Table tbl_SerializeFromObject_TD_10947373_input;
    tbl_SerializeFromObject_TD_10947373_input = Table("item", item_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_10947373_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_10947373_input.addCol("i_manager_id", 4);
    tbl_SerializeFromObject_TD_10947373_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10947373_input.addCol("i_class", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10947373_input.addCol("i_brand", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10947373_input.allocateHost();
    tbl_SerializeFromObject_TD_10947373_input.loadHost();
    Table tbl_SerializeFromObject_TD_10681810_input;
    tbl_SerializeFromObject_TD_10681810_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_10681810_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10681810_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_10681810_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_10681810_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_10681810_input.allocateHost();
    tbl_SerializeFromObject_TD_10681810_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_6480946_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_5904487_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_JOIN_INNER_TD_6480946_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_7598577_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_7790009_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8516482_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8214873_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9228880_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9687484_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    AggrCfgCmd cfg_Aggregate_TD_5904487_cmds;
    cfg_Aggregate_TD_5904487_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_5904487_gqe_aggr(cfg_Aggregate_TD_5904487_cmds.cmd);
    cfg_Aggregate_TD_5904487_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_5904487_cmds_out;
    cfg_Aggregate_TD_5904487_cmds_out.allocateHost();
    cfg_Aggregate_TD_5904487_cmds_out.allocateDevBuffer(context_a, 33);
    cfgCmd cfg_JOIN_INNER_TD_6480946_cmds;
    cfg_JOIN_INNER_TD_6480946_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_6480946_gqe_join (cfg_JOIN_INNER_TD_6480946_cmds.cmd);
    cfg_JOIN_INNER_TD_6480946_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7598577_cmds;
    cfg_JOIN_INNER_TD_7598577_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7598577_gqe_join (cfg_JOIN_INNER_TD_7598577_cmds.cmd);
    cfg_JOIN_INNER_TD_7598577_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8516482_cmds;
    cfg_JOIN_INNER_TD_8516482_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8516482_gqe_join (cfg_JOIN_INNER_TD_8516482_cmds.cmd);
    cfg_JOIN_INNER_TD_8516482_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    AggrBufferTmp buftmp_a(context_a); 
    buftmp_a.BufferInitial(q_a); 
    std::cout << std::endl; 
    AggrKrnlEngine krnl_Aggregate_TD_5904487;
    krnl_Aggregate_TD_5904487 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_5904487.setup(tbl_JOIN_INNER_TD_6480946_output, tbl_Aggregate_TD_5904487_output_preprocess, cfg_Aggregate_TD_5904487_cmds, cfg_Aggregate_TD_5904487_cmds_out, buftmp_a);
    krnlEngine krnl_JOIN_INNER_TD_6480946;
    krnl_JOIN_INNER_TD_6480946 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_6480946.setup(tbl_JOIN_INNER_TD_7598577_output, tbl_Filter_TD_7790009_output, tbl_JOIN_INNER_TD_6480946_output_preprocess, cfg_JOIN_INNER_TD_6480946_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_7598577;
    krnl_JOIN_INNER_TD_7598577 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7598577.setup(tbl_JOIN_INNER_TD_8516482_output, tbl_Filter_TD_8214873_output, tbl_JOIN_INNER_TD_7598577_output, cfg_JOIN_INNER_TD_7598577_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_8516482;
    krnl_JOIN_INNER_TD_8516482 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8516482.setup(tbl_Filter_TD_9228880_output, tbl_Filter_TD_9687484_output, tbl_JOIN_INNER_TD_8516482_output, cfg_JOIN_INNER_TD_8516482_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_Aggregate_TD_5904487;
    trans_Aggregate_TD_5904487.setq(q_a);
    trans_Aggregate_TD_5904487.add(&(cfg_Aggregate_TD_5904487_cmds));
    transEngine trans_Aggregate_TD_5904487_out;
    trans_Aggregate_TD_5904487_out.setq(q_a);
    q_a.finish();
    transEngine trans_JOIN_INNER_TD_6480946;
    trans_JOIN_INNER_TD_6480946.setq(q_h);
    trans_JOIN_INNER_TD_6480946.add(&(cfg_JOIN_INNER_TD_6480946_cmds));
    transEngine trans_JOIN_INNER_TD_6480946_out;
    trans_JOIN_INNER_TD_6480946_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_7598577;
    trans_JOIN_INNER_TD_7598577.setq(q_h);
    trans_JOIN_INNER_TD_7598577.add(&(cfg_JOIN_INNER_TD_7598577_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_8516482;
    trans_JOIN_INNER_TD_8516482.setq(q_h);
    trans_JOIN_INNER_TD_8516482.add(&(cfg_JOIN_INNER_TD_8516482_cmds));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_5904487;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_5904487;
    std::vector<cl::Event> events_Aggregate_TD_5904487;
    events_h2d_wr_Aggregate_TD_5904487.resize(1);
    events_d2h_rd_Aggregate_TD_5904487.resize(1);
    events_Aggregate_TD_5904487.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_5904487;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_5904487;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_6480946;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_6480946;
    std::vector<cl::Event> events_JOIN_INNER_TD_6480946;
    events_h2d_wr_JOIN_INNER_TD_6480946.resize(1);
    events_d2h_rd_JOIN_INNER_TD_6480946.resize(1);
    events_JOIN_INNER_TD_6480946.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_6480946;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_6480946;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7598577;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7598577;
    std::vector<cl::Event> events_JOIN_INNER_TD_7598577;
    events_h2d_wr_JOIN_INNER_TD_7598577.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7598577.resize(1);
    events_JOIN_INNER_TD_7598577.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7598577;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7598577;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8516482;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8516482;
    std::vector<cl::Event> events_JOIN_INNER_TD_8516482;
    events_h2d_wr_JOIN_INNER_TD_8516482.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8516482.resize(1);
    events_JOIN_INNER_TD_8516482.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8516482;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8516482;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_9_558883_s, tv_r_Filter_9_558883_e;
    gettimeofday(&tv_r_Filter_9_558883_s, 0);
    SW_Filter_TD_9687484(tbl_SerializeFromObject_TD_10681810_input, tbl_Filter_TD_9687484_output);
    gettimeofday(&tv_r_Filter_9_558883_e, 0);

    struct timeval tv_r_Filter_9_532321_s, tv_r_Filter_9_532321_e;
    gettimeofday(&tv_r_Filter_9_532321_s, 0);
    SW_Filter_TD_9228880(tbl_SerializeFromObject_TD_10947373_input, tbl_Filter_TD_9228880_output);
    gettimeofday(&tv_r_Filter_9_532321_e, 0);

    struct timeval tv_r_Filter_8_759812_s, tv_r_Filter_8_759812_e;
    gettimeofday(&tv_r_Filter_8_759812_s, 0);
    SW_Filter_TD_8214873(tbl_SerializeFromObject_TD_9988462_input, tbl_Filter_TD_8214873_output);
    gettimeofday(&tv_r_Filter_8_759812_e, 0);

    struct timeval tv_r_JOIN_INNER_8_625363_s, tv_r_JOIN_INNER_8_625363_e;
    gettimeofday(&tv_r_JOIN_INNER_8_625363_s, 0);
    trans_JOIN_INNER_TD_8516482.add(&(tbl_Filter_TD_9228880_output));
    trans_JOIN_INNER_TD_8516482.add(&(tbl_Filter_TD_9687484_output));
    trans_JOIN_INNER_TD_8516482.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8516482), &(events_h2d_wr_JOIN_INNER_TD_8516482[0]));
    events_grp_JOIN_INNER_TD_8516482.push_back(events_h2d_wr_JOIN_INNER_TD_8516482[0]);
    krnl_JOIN_INNER_TD_8516482.run(0, &(events_grp_JOIN_INNER_TD_8516482), &(events_JOIN_INNER_TD_8516482[0]));
    gettimeofday(&tv_r_JOIN_INNER_8_625363_e, 0);

    struct timeval tv_r_Filter_7_831150_s, tv_r_Filter_7_831150_e;
    gettimeofday(&tv_r_Filter_7_831150_s, 0);
    SW_Filter_TD_7790009(tbl_SerializeFromObject_TD_8635282_input, tbl_Filter_TD_7790009_output);
    gettimeofday(&tv_r_Filter_7_831150_e, 0);

    struct timeval tv_r_JOIN_INNER_7_985738_s, tv_r_JOIN_INNER_7_985738_e;
    gettimeofday(&tv_r_JOIN_INNER_7_985738_s, 0);
    prev_events_grp_JOIN_INNER_TD_7598577.push_back(events_h2d_wr_JOIN_INNER_TD_8516482[0]);
    trans_JOIN_INNER_TD_7598577.add(&(tbl_Filter_TD_8214873_output));
    trans_JOIN_INNER_TD_7598577.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7598577), &(events_h2d_wr_JOIN_INNER_TD_7598577[0]));
    events_grp_JOIN_INNER_TD_7598577.push_back(events_h2d_wr_JOIN_INNER_TD_7598577[0]);
    events_grp_JOIN_INNER_TD_7598577.push_back(events_JOIN_INNER_TD_8516482[0]);
    krnl_JOIN_INNER_TD_7598577.run(0, &(events_grp_JOIN_INNER_TD_7598577), &(events_JOIN_INNER_TD_7598577[0]));
    gettimeofday(&tv_r_JOIN_INNER_7_985738_e, 0);

    struct timeval tv_r_JOIN_INNER_6_726706_s, tv_r_JOIN_INNER_6_726706_e;
    gettimeofday(&tv_r_JOIN_INNER_6_726706_s, 0);
    prev_events_grp_JOIN_INNER_TD_6480946.push_back(events_h2d_wr_JOIN_INNER_TD_7598577[0]);
    trans_JOIN_INNER_TD_6480946.add(&(tbl_Filter_TD_7790009_output));
    trans_JOIN_INNER_TD_6480946.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_6480946), &(events_h2d_wr_JOIN_INNER_TD_6480946[0]));
    events_grp_JOIN_INNER_TD_6480946.push_back(events_h2d_wr_JOIN_INNER_TD_6480946[0]);
    events_grp_JOIN_INNER_TD_6480946.push_back(events_JOIN_INNER_TD_7598577[0]);
    krnl_JOIN_INNER_TD_6480946.run(0, &(events_grp_JOIN_INNER_TD_6480946), &(events_JOIN_INNER_TD_6480946[0]));
    
    trans_JOIN_INNER_TD_6480946_out.add(&(tbl_JOIN_INNER_TD_6480946_output_preprocess));
    trans_JOIN_INNER_TD_6480946_out.dev2host(0, &(events_JOIN_INNER_TD_6480946), &(events_d2h_rd_JOIN_INNER_TD_6480946[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_6480946);
    tbl_JOIN_INNER_TD_6480946_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_6480946_output));
    gettimeofday(&tv_r_JOIN_INNER_6_726706_e, 0);

    struct timeval tv_r_Aggregate_5_194472_s, tv_r_Aggregate_5_194472_e;
    gettimeofday(&tv_r_Aggregate_5_194472_s, 0);
    trans_Aggregate_TD_5904487.add(&(tbl_JOIN_INNER_TD_6480946_output));
    trans_Aggregate_TD_5904487.host2dev(0, &(prev_events_grp_Aggregate_TD_5904487), &(events_h2d_wr_Aggregate_TD_5904487[0]));
    events_grp_Aggregate_TD_5904487.push_back(events_h2d_wr_Aggregate_TD_5904487[0]);
    krnl_Aggregate_TD_5904487.run(0, &(events_grp_Aggregate_TD_5904487), &(events_Aggregate_TD_5904487[0]));
    
    trans_Aggregate_TD_5904487_out.add(&(tbl_Aggregate_TD_5904487_output_preprocess));
    trans_Aggregate_TD_5904487_out.dev2host(0, &(events_Aggregate_TD_5904487), &(events_d2h_rd_Aggregate_TD_5904487[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_5904487_consolidate(tbl_Aggregate_TD_5904487_output_preprocess, tbl_Aggregate_TD_5904487_output);
    gettimeofday(&tv_r_Aggregate_5_194472_e, 0);

    struct timeval tv_r_Window_4_684011_s, tv_r_Window_4_684011_e;
    gettimeofday(&tv_r_Window_4_684011_s, 0);
    SW_Window_TD_4163701(tbl_Aggregate_TD_5904487_output, tbl_Window_TD_4163701_output);
    gettimeofday(&tv_r_Window_4_684011_e, 0);

    struct timeval tv_r_Filter_3_272266_s, tv_r_Filter_3_272266_e;
    gettimeofday(&tv_r_Filter_3_272266_s, 0);
    SW_Filter_TD_3970267(tbl_Window_TD_4163701_output, tbl_Filter_TD_3970267_output);
    gettimeofday(&tv_r_Filter_3_272266_e, 0);

    struct timeval tv_r_Sort_2_196908_s, tv_r_Sort_2_196908_e;
    gettimeofday(&tv_r_Sort_2_196908_s, 0);
    SW_Sort_TD_2283574(tbl_Filter_TD_3970267_output, tbl_Sort_TD_2283574_output);
    gettimeofday(&tv_r_Sort_2_196908_e, 0);

    struct timeval tv_r_LocalLimit_1_266902_s, tv_r_LocalLimit_1_266902_e;
    gettimeofday(&tv_r_LocalLimit_1_266902_s, 0);
    SW_LocalLimit_TD_1586201(tbl_Sort_TD_2283574_output, tbl_LocalLimit_TD_1586201_output);
    gettimeofday(&tv_r_LocalLimit_1_266902_e, 0);

    struct timeval tv_r_GlobalLimit_0_10387_s, tv_r_GlobalLimit_0_10387_e;
    gettimeofday(&tv_r_GlobalLimit_0_10387_s, 0);
    SW_GlobalLimit_TD_0427754(tbl_LocalLimit_TD_1586201_output, tbl_GlobalLimit_TD_0427754_output);
    gettimeofday(&tv_r_GlobalLimit_0_10387_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_558883_s, &tv_r_Filter_9_558883_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10681810_input: " << tbl_SerializeFromObject_TD_10681810_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_532321_s, &tv_r_Filter_9_532321_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10947373_input: " << tbl_SerializeFromObject_TD_10947373_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_759812_s, &tv_r_Filter_8_759812_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9988462_input: " << tbl_SerializeFromObject_TD_9988462_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_625363_s, &tv_r_JOIN_INNER_8_625363_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9228880_output: " << tbl_Filter_TD_9228880_output.getNumRow() << " " << "tbl_Filter_TD_9687484_output: " << tbl_Filter_TD_9687484_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_831150_s, &tv_r_Filter_7_831150_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8635282_input: " << tbl_SerializeFromObject_TD_8635282_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_985738_s, &tv_r_JOIN_INNER_7_985738_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8516482_output: " << tbl_JOIN_INNER_TD_8516482_output.getNumRow() << " " << "tbl_Filter_TD_8214873_output: " << tbl_Filter_TD_8214873_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_726706_s, &tv_r_JOIN_INNER_6_726706_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7598577_output: " << tbl_JOIN_INNER_TD_7598577_output.getNumRow() << " " << "tbl_Filter_TD_7790009_output: " << tbl_Filter_TD_7790009_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_194472_s, &tv_r_Aggregate_5_194472_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6480946_output: " << tbl_JOIN_INNER_TD_6480946_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_4: " << tvdiff(&tv_r_Window_4_684011_s, &tv_r_Window_4_684011_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_5904487_output: " << tbl_Aggregate_TD_5904487_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_272266_s, &tv_r_Filter_3_272266_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_4163701_output: " << tbl_Window_TD_4163701_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_196908_s, &tv_r_Sort_2_196908_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_3970267_output: " << tbl_Filter_TD_3970267_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_266902_s, &tv_r_LocalLimit_1_266902_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2283574_output: " << tbl_Sort_TD_2283574_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_10387_s, &tv_r_GlobalLimit_0_10387_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1586201_output: " << tbl_LocalLimit_TD_1586201_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.6090202 * 1000 << "ms" << std::endl; 
    return 0; 
}
