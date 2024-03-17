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

#include "cfgFunc_q65.hpp" 
#include "q65.hpp" 

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
    std::cout << "NOTE:running query #65\n."; 
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
    Table tbl_GlobalLimit_TD_0437713_output("tbl_GlobalLimit_TD_0437713_output", 6100000, 6, "");
    tbl_GlobalLimit_TD_0437713_output.allocateHost();
    Table tbl_LocalLimit_TD_1586279_output("tbl_LocalLimit_TD_1586279_output", 6100000, 6, "");
    tbl_LocalLimit_TD_1586279_output.allocateHost();
    Table tbl_Sort_TD_2360197_output("tbl_Sort_TD_2360197_output", 6100000, 6, "");
    tbl_Sort_TD_2360197_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3745615_output("tbl_JOIN_INNER_TD_3745615_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_3745615_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4754884_output("tbl_JOIN_INNER_TD_4754884_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_4754884_output.allocateHost();
    Table tbl_Aggregate_TD_4332386_output_preprocess("tbl_Aggregate_TD_4332386_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_4332386_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_4332386_output("tbl_Aggregate_TD_4332386_output", 6100000, 2, "");
    tbl_Aggregate_TD_4332386_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5306576_output("tbl_JOIN_INNER_TD_5306576_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_5306576_output.allocateHost();
    Table tbl_Filter_TD_5811715_output("tbl_Filter_TD_5811715_output", 6100000, 5, "");
    tbl_Filter_TD_5811715_output.allocateHost();
    Table tbl_Aggregate_TD_5599450_output_preprocess("tbl_Aggregate_TD_5599450_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_5599450_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_5599450_output("tbl_Aggregate_TD_5599450_output", 6100000, 2, "");
    tbl_Aggregate_TD_5599450_output.allocateHost();
    Table tbl_Filter_TD_6930836_output("tbl_Filter_TD_6930836_output", 6100000, 2, "");
    tbl_Filter_TD_6930836_output.allocateHost();
    Table tbl_Filter_TD_6709673_output("tbl_Filter_TD_6709673_output", 6100000, 3, "");
    tbl_Filter_TD_6709673_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6713419_input;
    tbl_SerializeFromObject_TD_6713419_input = Table("item", item_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_6713419_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_6713419_input.addCol("i_item_desc", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6713419_input.addCol("i_current_price", 4);
    tbl_SerializeFromObject_TD_6713419_input.addCol("i_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_6713419_input.addCol("i_brand", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6713419_input.allocateHost();
    tbl_SerializeFromObject_TD_6713419_input.loadHost();
    Table tbl_JOIN_INNER_TD_6343340_output_preprocess("tbl_JOIN_INNER_TD_6343340_output_preprocess", 6100000, 3, "");
    tbl_JOIN_INNER_TD_6343340_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_6343340_output("tbl_JOIN_INNER_TD_6343340_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_6343340_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7661880_input;
    tbl_SerializeFromObject_TD_7661880_input = Table("store", store_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7661880_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_7661880_input.addCol("s_store_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7661880_input.allocateHost();
    tbl_SerializeFromObject_TD_7661880_input.loadHost();
    Table tbl_Aggregate_TD_762968_output_preprocess("tbl_Aggregate_TD_762968_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_762968_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_762968_output("tbl_Aggregate_TD_762968_output", 6100000, 3, "");
    tbl_Aggregate_TD_762968_output.allocateHost();
    Table tbl_Filter_TD_7758790_output("tbl_Filter_TD_7758790_output", 6100000, 4, "");
    tbl_Filter_TD_7758790_output.allocateHost();
    Table tbl_Filter_TD_7521533_output("tbl_Filter_TD_7521533_output", 6100000, 1, "");
    tbl_Filter_TD_7521533_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8100064_output_preprocess("tbl_JOIN_INNER_TD_8100064_output_preprocess", 6100000, 3, "");
    tbl_JOIN_INNER_TD_8100064_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_8100064_output("tbl_JOIN_INNER_TD_8100064_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_8100064_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8764101_input;
    tbl_SerializeFromObject_TD_8764101_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_8764101_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_8764101_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_8764101_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_8764101_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_8764101_input.allocateHost();
    tbl_SerializeFromObject_TD_8764101_input.loadHost();
    Table tbl_SerializeFromObject_TD_8296862_input;
    tbl_SerializeFromObject_TD_8296862_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8296862_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_8296862_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_8296862_input.allocateHost();
    tbl_SerializeFromObject_TD_8296862_input.loadHost();
    Table tbl_Filter_TD_9172885_output("tbl_Filter_TD_9172885_output", 6100000, 4, "");
    tbl_Filter_TD_9172885_output.allocateHost();
    Table tbl_Filter_TD_9237991_output("tbl_Filter_TD_9237991_output", 6100000, 1, "");
    tbl_Filter_TD_9237991_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10722735_input;
    tbl_SerializeFromObject_TD_10722735_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_10722735_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10722735_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_10722735_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_10722735_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_10722735_input.allocateHost();
    tbl_SerializeFromObject_TD_10722735_input.loadHost();
    Table tbl_SerializeFromObject_TD_1072979_input;
    tbl_SerializeFromObject_TD_1072979_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_1072979_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_1072979_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_1072979_input.allocateHost();
    tbl_SerializeFromObject_TD_1072979_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_Aggregate_TD_4332386_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_JOIN_INNER_TD_6343340_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_5599450_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_Aggregate_TD_5599450_output.allocateDevBuffer(context_a, 32);
    tbl_JOIN_INNER_TD_6343340_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8100064_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_762968_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_Filter_TD_7758790_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_7521533_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8100064_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9172885_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9237991_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    AggrCfgCmd cfg_Aggregate_TD_4332386_cmds;
    cfg_Aggregate_TD_4332386_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_4332386_gqe_aggr(cfg_Aggregate_TD_4332386_cmds.cmd);
    cfg_Aggregate_TD_4332386_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_4332386_cmds_out;
    cfg_Aggregate_TD_4332386_cmds_out.allocateHost();
    cfg_Aggregate_TD_4332386_cmds_out.allocateDevBuffer(context_a, 33);
    AggrCfgCmd cfg_Aggregate_TD_5599450_cmds;
    cfg_Aggregate_TD_5599450_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_5599450_gqe_aggr(cfg_Aggregate_TD_5599450_cmds.cmd);
    cfg_Aggregate_TD_5599450_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_5599450_cmds_out;
    cfg_Aggregate_TD_5599450_cmds_out.allocateHost();
    cfg_Aggregate_TD_5599450_cmds_out.allocateDevBuffer(context_a, 33);
    cfgCmd cfg_JOIN_INNER_TD_6343340_cmds;
    cfg_JOIN_INNER_TD_6343340_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_6343340_gqe_join (cfg_JOIN_INNER_TD_6343340_cmds.cmd);
    cfg_JOIN_INNER_TD_6343340_cmds.allocateDevBuffer(context_h, 32);
    AggrCfgCmd cfg_Aggregate_TD_762968_cmds;
    cfg_Aggregate_TD_762968_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_762968_gqe_aggr(cfg_Aggregate_TD_762968_cmds.cmd);
    cfg_Aggregate_TD_762968_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_762968_cmds_out;
    cfg_Aggregate_TD_762968_cmds_out.allocateHost();
    cfg_Aggregate_TD_762968_cmds_out.allocateDevBuffer(context_a, 33);
    cfgCmd cfg_JOIN_INNER_TD_8100064_cmds;
    cfg_JOIN_INNER_TD_8100064_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8100064_gqe_join (cfg_JOIN_INNER_TD_8100064_cmds.cmd);
    cfg_JOIN_INNER_TD_8100064_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    AggrBufferTmp buftmp_a(context_a); 
    buftmp_a.BufferInitial(q_a); 
    std::cout << std::endl; 
    AggrKrnlEngine krnl_Aggregate_TD_4332386;
    krnl_Aggregate_TD_4332386 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_4332386.setup(tbl_Aggregate_TD_5599450_output, tbl_Aggregate_TD_4332386_output_preprocess, cfg_Aggregate_TD_4332386_cmds, cfg_Aggregate_TD_4332386_cmds_out, buftmp_a);
    AggrKrnlEngine krnl_Aggregate_TD_5599450;
    krnl_Aggregate_TD_5599450 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_5599450.setup(tbl_JOIN_INNER_TD_6343340_output, tbl_Aggregate_TD_5599450_output_preprocess, cfg_Aggregate_TD_5599450_cmds, cfg_Aggregate_TD_5599450_cmds_out, buftmp_a);
    krnlEngine krnl_JOIN_INNER_TD_6343340;
    krnl_JOIN_INNER_TD_6343340 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_6343340.setup(tbl_Filter_TD_7758790_output, tbl_Filter_TD_7521533_output, tbl_JOIN_INNER_TD_6343340_output_preprocess, cfg_JOIN_INNER_TD_6343340_cmds, buftmp_h);
    AggrKrnlEngine krnl_Aggregate_TD_762968;
    krnl_Aggregate_TD_762968 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_762968.setup(tbl_JOIN_INNER_TD_8100064_output, tbl_Aggregate_TD_762968_output_preprocess, cfg_Aggregate_TD_762968_cmds, cfg_Aggregate_TD_762968_cmds_out, buftmp_a);
    krnlEngine krnl_JOIN_INNER_TD_8100064;
    krnl_JOIN_INNER_TD_8100064 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8100064.setup(tbl_Filter_TD_9172885_output, tbl_Filter_TD_9237991_output, tbl_JOIN_INNER_TD_8100064_output_preprocess, cfg_JOIN_INNER_TD_8100064_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_Aggregate_TD_4332386;
    trans_Aggregate_TD_4332386.setq(q_a);
    trans_Aggregate_TD_4332386.add(&(cfg_Aggregate_TD_4332386_cmds));
    transEngine trans_Aggregate_TD_4332386_out;
    trans_Aggregate_TD_4332386_out.setq(q_a);
    q_a.finish();
    transEngine trans_Aggregate_TD_5599450;
    trans_Aggregate_TD_5599450.setq(q_a);
    trans_Aggregate_TD_5599450.add(&(cfg_Aggregate_TD_5599450_cmds));
    transEngine trans_Aggregate_TD_5599450_out;
    trans_Aggregate_TD_5599450_out.setq(q_a);
    q_a.finish();
    transEngine trans_JOIN_INNER_TD_6343340;
    trans_JOIN_INNER_TD_6343340.setq(q_h);
    trans_JOIN_INNER_TD_6343340.add(&(cfg_JOIN_INNER_TD_6343340_cmds));
    transEngine trans_JOIN_INNER_TD_6343340_out;
    trans_JOIN_INNER_TD_6343340_out.setq(q_h);
    q_h.finish();
    transEngine trans_Aggregate_TD_762968;
    trans_Aggregate_TD_762968.setq(q_a);
    trans_Aggregate_TD_762968.add(&(cfg_Aggregate_TD_762968_cmds));
    transEngine trans_Aggregate_TD_762968_out;
    trans_Aggregate_TD_762968_out.setq(q_a);
    q_a.finish();
    transEngine trans_JOIN_INNER_TD_8100064;
    trans_JOIN_INNER_TD_8100064.setq(q_h);
    trans_JOIN_INNER_TD_8100064.add(&(cfg_JOIN_INNER_TD_8100064_cmds));
    transEngine trans_JOIN_INNER_TD_8100064_out;
    trans_JOIN_INNER_TD_8100064_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_4332386;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_4332386;
    std::vector<cl::Event> events_Aggregate_TD_4332386;
    events_h2d_wr_Aggregate_TD_4332386.resize(1);
    events_d2h_rd_Aggregate_TD_4332386.resize(1);
    events_Aggregate_TD_4332386.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_4332386;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_4332386;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_5599450;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_5599450;
    std::vector<cl::Event> events_Aggregate_TD_5599450;
    events_h2d_wr_Aggregate_TD_5599450.resize(1);
    events_d2h_rd_Aggregate_TD_5599450.resize(1);
    events_Aggregate_TD_5599450.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_5599450;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_5599450;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_6343340;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_6343340;
    std::vector<cl::Event> events_JOIN_INNER_TD_6343340;
    events_h2d_wr_JOIN_INNER_TD_6343340.resize(1);
    events_d2h_rd_JOIN_INNER_TD_6343340.resize(1);
    events_JOIN_INNER_TD_6343340.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_6343340;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_6343340;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_762968;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_762968;
    std::vector<cl::Event> events_Aggregate_TD_762968;
    events_h2d_wr_Aggregate_TD_762968.resize(1);
    events_d2h_rd_Aggregate_TD_762968.resize(1);
    events_Aggregate_TD_762968.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_762968;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_762968;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8100064;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8100064;
    std::vector<cl::Event> events_JOIN_INNER_TD_8100064;
    events_h2d_wr_JOIN_INNER_TD_8100064.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8100064.resize(1);
    events_JOIN_INNER_TD_8100064.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8100064;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8100064;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_9_948488_s, tv_r_Filter_9_948488_e;
    gettimeofday(&tv_r_Filter_9_948488_s, 0);
    SW_Filter_TD_9237991(tbl_SerializeFromObject_TD_1072979_input, tbl_Filter_TD_9237991_output);
    gettimeofday(&tv_r_Filter_9_948488_e, 0);

    struct timeval tv_r_Filter_9_665655_s, tv_r_Filter_9_665655_e;
    gettimeofday(&tv_r_Filter_9_665655_s, 0);
    SW_Filter_TD_9172885(tbl_SerializeFromObject_TD_10722735_input, tbl_Filter_TD_9172885_output);
    gettimeofday(&tv_r_Filter_9_665655_e, 0);

    struct timeval tv_r_JOIN_INNER_8_945123_s, tv_r_JOIN_INNER_8_945123_e;
    gettimeofday(&tv_r_JOIN_INNER_8_945123_s, 0);
    trans_JOIN_INNER_TD_8100064.add(&(tbl_Filter_TD_9172885_output));
    trans_JOIN_INNER_TD_8100064.add(&(tbl_Filter_TD_9237991_output));
    trans_JOIN_INNER_TD_8100064.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8100064), &(events_h2d_wr_JOIN_INNER_TD_8100064[0]));
    events_grp_JOIN_INNER_TD_8100064.push_back(events_h2d_wr_JOIN_INNER_TD_8100064[0]);
    krnl_JOIN_INNER_TD_8100064.run(0, &(events_grp_JOIN_INNER_TD_8100064), &(events_JOIN_INNER_TD_8100064[0]));
    
    trans_JOIN_INNER_TD_8100064_out.add(&(tbl_JOIN_INNER_TD_8100064_output_preprocess));
    trans_JOIN_INNER_TD_8100064_out.dev2host(0, &(events_JOIN_INNER_TD_8100064), &(events_d2h_rd_JOIN_INNER_TD_8100064[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_8100064);
    tbl_JOIN_INNER_TD_8100064_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_8100064_output));
    gettimeofday(&tv_r_JOIN_INNER_8_945123_e, 0);

    struct timeval tv_r_Filter_7_428086_s, tv_r_Filter_7_428086_e;
    gettimeofday(&tv_r_Filter_7_428086_s, 0);
    SW_Filter_TD_7521533(tbl_SerializeFromObject_TD_8296862_input, tbl_Filter_TD_7521533_output);
    gettimeofday(&tv_r_Filter_7_428086_e, 0);

    struct timeval tv_r_Filter_7_260056_s, tv_r_Filter_7_260056_e;
    gettimeofday(&tv_r_Filter_7_260056_s, 0);
    SW_Filter_TD_7758790(tbl_SerializeFromObject_TD_8764101_input, tbl_Filter_TD_7758790_output);
    gettimeofday(&tv_r_Filter_7_260056_e, 0);

    struct timeval tv_r_Aggregate_7_67573_s, tv_r_Aggregate_7_67573_e;
    gettimeofday(&tv_r_Aggregate_7_67573_s, 0);
    trans_Aggregate_TD_762968.add(&(tbl_JOIN_INNER_TD_8100064_output));
    trans_Aggregate_TD_762968.host2dev(0, &(prev_events_grp_Aggregate_TD_762968), &(events_h2d_wr_Aggregate_TD_762968[0]));
    events_grp_Aggregate_TD_762968.push_back(events_h2d_wr_Aggregate_TD_762968[0]);
    krnl_Aggregate_TD_762968.run(0, &(events_grp_Aggregate_TD_762968), &(events_Aggregate_TD_762968[0]));
    
    trans_Aggregate_TD_762968_out.add(&(tbl_Aggregate_TD_762968_output_preprocess));
    trans_Aggregate_TD_762968_out.dev2host(0, &(events_Aggregate_TD_762968), &(events_d2h_rd_Aggregate_TD_762968[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_762968_consolidate(tbl_Aggregate_TD_762968_output_preprocess, tbl_Aggregate_TD_762968_output);
    gettimeofday(&tv_r_Aggregate_7_67573_e, 0);

    struct timeval tv_r_JOIN_INNER_6_924931_s, tv_r_JOIN_INNER_6_924931_e;
    gettimeofday(&tv_r_JOIN_INNER_6_924931_s, 0);
    trans_JOIN_INNER_TD_6343340.add(&(tbl_Filter_TD_7758790_output));
    trans_JOIN_INNER_TD_6343340.add(&(tbl_Filter_TD_7521533_output));
    trans_JOIN_INNER_TD_6343340.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_6343340), &(events_h2d_wr_JOIN_INNER_TD_6343340[0]));
    events_grp_JOIN_INNER_TD_6343340.push_back(events_h2d_wr_JOIN_INNER_TD_6343340[0]);
    krnl_JOIN_INNER_TD_6343340.run(0, &(events_grp_JOIN_INNER_TD_6343340), &(events_JOIN_INNER_TD_6343340[0]));
    
    trans_JOIN_INNER_TD_6343340_out.add(&(tbl_JOIN_INNER_TD_6343340_output_preprocess));
    trans_JOIN_INNER_TD_6343340_out.dev2host(0, &(events_JOIN_INNER_TD_6343340), &(events_d2h_rd_JOIN_INNER_TD_6343340[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_6343340);
    tbl_JOIN_INNER_TD_6343340_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_6343340_output));
    gettimeofday(&tv_r_JOIN_INNER_6_924931_e, 0);

    struct timeval tv_r_Filter_6_432858_s, tv_r_Filter_6_432858_e;
    gettimeofday(&tv_r_Filter_6_432858_s, 0);
    SW_Filter_TD_6709673(tbl_Aggregate_TD_762968_output, tbl_Filter_TD_6709673_output);
    gettimeofday(&tv_r_Filter_6_432858_e, 0);

    struct timeval tv_r_Filter_6_476428_s, tv_r_Filter_6_476428_e;
    gettimeofday(&tv_r_Filter_6_476428_s, 0);
    SW_Filter_TD_6930836(tbl_SerializeFromObject_TD_7661880_input, tbl_Filter_TD_6930836_output);
    gettimeofday(&tv_r_Filter_6_476428_e, 0);

    struct timeval tv_r_Aggregate_5_331981_s, tv_r_Aggregate_5_331981_e;
    gettimeofday(&tv_r_Aggregate_5_331981_s, 0);
    trans_Aggregate_TD_5599450.add(&(tbl_JOIN_INNER_TD_6343340_output));
    trans_Aggregate_TD_5599450.host2dev(0, &(prev_events_grp_Aggregate_TD_5599450), &(events_h2d_wr_Aggregate_TD_5599450[0]));
    events_grp_Aggregate_TD_5599450.push_back(events_h2d_wr_Aggregate_TD_5599450[0]);
    krnl_Aggregate_TD_5599450.run(0, &(events_grp_Aggregate_TD_5599450), &(events_Aggregate_TD_5599450[0]));
    
    trans_Aggregate_TD_5599450_out.add(&(tbl_Aggregate_TD_5599450_output_preprocess));
    trans_Aggregate_TD_5599450_out.dev2host(0, &(events_Aggregate_TD_5599450), &(events_d2h_rd_Aggregate_TD_5599450[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_5599450_consolidate(tbl_Aggregate_TD_5599450_output_preprocess, tbl_Aggregate_TD_5599450_output);
    gettimeofday(&tv_r_Aggregate_5_331981_e, 0);

    struct timeval tv_r_Filter_5_929522_s, tv_r_Filter_5_929522_e;
    gettimeofday(&tv_r_Filter_5_929522_s, 0);
    SW_Filter_TD_5811715(tbl_SerializeFromObject_TD_6713419_input, tbl_Filter_TD_5811715_output);
    gettimeofday(&tv_r_Filter_5_929522_e, 0);

    struct timeval tv_r_JOIN_INNER_5_142944_s, tv_r_JOIN_INNER_5_142944_e;
    gettimeofday(&tv_r_JOIN_INNER_5_142944_s, 0);
    SW_JOIN_INNER_TD_5306576(tbl_Filter_TD_6930836_output, tbl_Filter_TD_6709673_output, tbl_JOIN_INNER_TD_5306576_output);
    gettimeofday(&tv_r_JOIN_INNER_5_142944_e, 0);

    struct timeval tv_r_Aggregate_4_239508_s, tv_r_Aggregate_4_239508_e;
    gettimeofday(&tv_r_Aggregate_4_239508_s, 0);
    prev_events_grp_Aggregate_TD_4332386.push_back(events_h2d_wr_Aggregate_TD_5599450[0]);
    trans_Aggregate_TD_4332386.add(&(tbl_Aggregate_TD_5599450_output));
    trans_Aggregate_TD_4332386.host2dev(0, &(prev_events_grp_Aggregate_TD_4332386), &(events_h2d_wr_Aggregate_TD_4332386[0]));
    events_grp_Aggregate_TD_4332386.push_back(events_h2d_wr_Aggregate_TD_4332386[0]);
    events_grp_Aggregate_TD_4332386.push_back(events_Aggregate_TD_5599450[0]);
    krnl_Aggregate_TD_4332386.run(0, &(events_grp_Aggregate_TD_4332386), &(events_Aggregate_TD_4332386[0]));
    
    trans_Aggregate_TD_4332386_out.add(&(tbl_Aggregate_TD_4332386_output_preprocess));
    trans_Aggregate_TD_4332386_out.dev2host(0, &(events_Aggregate_TD_4332386), &(events_d2h_rd_Aggregate_TD_4332386[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_4332386_consolidate(tbl_Aggregate_TD_4332386_output_preprocess, tbl_Aggregate_TD_4332386_output);
    gettimeofday(&tv_r_Aggregate_4_239508_e, 0);

    struct timeval tv_r_JOIN_INNER_4_905741_s, tv_r_JOIN_INNER_4_905741_e;
    gettimeofday(&tv_r_JOIN_INNER_4_905741_s, 0);
    SW_JOIN_INNER_TD_4754884(tbl_JOIN_INNER_TD_5306576_output, tbl_Filter_TD_5811715_output, tbl_JOIN_INNER_TD_4754884_output);
    gettimeofday(&tv_r_JOIN_INNER_4_905741_e, 0);

    struct timeval tv_r_JOIN_INNER_3_450942_s, tv_r_JOIN_INNER_3_450942_e;
    gettimeofday(&tv_r_JOIN_INNER_3_450942_s, 0);
    SW_JOIN_INNER_TD_3745615(tbl_JOIN_INNER_TD_4754884_output, tbl_Aggregate_TD_4332386_output, tbl_JOIN_INNER_TD_3745615_output);
    gettimeofday(&tv_r_JOIN_INNER_3_450942_e, 0);

    struct timeval tv_r_Sort_2_458622_s, tv_r_Sort_2_458622_e;
    gettimeofday(&tv_r_Sort_2_458622_s, 0);
    SW_Sort_TD_2360197(tbl_JOIN_INNER_TD_3745615_output, tbl_Sort_TD_2360197_output);
    gettimeofday(&tv_r_Sort_2_458622_e, 0);

    struct timeval tv_r_LocalLimit_1_488832_s, tv_r_LocalLimit_1_488832_e;
    gettimeofday(&tv_r_LocalLimit_1_488832_s, 0);
    SW_LocalLimit_TD_1586279(tbl_Sort_TD_2360197_output, tbl_LocalLimit_TD_1586279_output);
    gettimeofday(&tv_r_LocalLimit_1_488832_e, 0);

    struct timeval tv_r_GlobalLimit_0_76946_s, tv_r_GlobalLimit_0_76946_e;
    gettimeofday(&tv_r_GlobalLimit_0_76946_s, 0);
    SW_GlobalLimit_TD_0437713(tbl_LocalLimit_TD_1586279_output, tbl_GlobalLimit_TD_0437713_output);
    gettimeofday(&tv_r_GlobalLimit_0_76946_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_948488_s, &tv_r_Filter_9_948488_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1072979_input: " << tbl_SerializeFromObject_TD_1072979_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_665655_s, &tv_r_Filter_9_665655_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10722735_input: " << tbl_SerializeFromObject_TD_10722735_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_945123_s, &tv_r_JOIN_INNER_8_945123_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9172885_output: " << tbl_Filter_TD_9172885_output.getNumRow() << " " << "tbl_Filter_TD_9237991_output: " << tbl_Filter_TD_9237991_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_428086_s, &tv_r_Filter_7_428086_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8296862_input: " << tbl_SerializeFromObject_TD_8296862_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_260056_s, &tv_r_Filter_7_260056_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8764101_input: " << tbl_SerializeFromObject_TD_8764101_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_7: " << tvdiff(&tv_r_Aggregate_7_67573_s, &tv_r_Aggregate_7_67573_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8100064_output: " << tbl_JOIN_INNER_TD_8100064_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_924931_s, &tv_r_JOIN_INNER_6_924931_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_7758790_output: " << tbl_Filter_TD_7758790_output.getNumRow() << " " << "tbl_Filter_TD_7521533_output: " << tbl_Filter_TD_7521533_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_432858_s, &tv_r_Filter_6_432858_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_762968_output: " << tbl_Aggregate_TD_762968_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_476428_s, &tv_r_Filter_6_476428_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7661880_input: " << tbl_SerializeFromObject_TD_7661880_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_331981_s, &tv_r_Aggregate_5_331981_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6343340_output: " << tbl_JOIN_INNER_TD_6343340_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_929522_s, &tv_r_Filter_5_929522_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6713419_input: " << tbl_SerializeFromObject_TD_6713419_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_142944_s, &tv_r_JOIN_INNER_5_142944_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6930836_output: " << tbl_Filter_TD_6930836_output.getNumRow() << " " << "tbl_Filter_TD_6709673_output: " << tbl_Filter_TD_6709673_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_4: " << tvdiff(&tv_r_Aggregate_4_239508_s, &tv_r_Aggregate_4_239508_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_5599450_output: " << tbl_Aggregate_TD_5599450_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_905741_s, &tv_r_JOIN_INNER_4_905741_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5306576_output: " << tbl_JOIN_INNER_TD_5306576_output.getNumRow() << " " << "tbl_Filter_TD_5811715_output: " << tbl_Filter_TD_5811715_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_450942_s, &tv_r_JOIN_INNER_3_450942_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4754884_output: " << tbl_JOIN_INNER_TD_4754884_output.getNumRow() << " " << "tbl_Aggregate_TD_4332386_output: " << tbl_Aggregate_TD_4332386_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_458622_s, &tv_r_Sort_2_458622_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3745615_output: " << tbl_JOIN_INNER_TD_3745615_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_488832_s, &tv_r_LocalLimit_1_488832_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2360197_output: " << tbl_Sort_TD_2360197_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_76946_s, &tv_r_GlobalLimit_0_76946_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1586279_output: " << tbl_LocalLimit_TD_1586279_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.6894577 * 1000 << "ms" << std::endl; 
    return 0; 
}
