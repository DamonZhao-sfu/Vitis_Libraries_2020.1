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

#include "cfgFunc_q53.hpp" 
#include "q53.hpp" 

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
    std::cout << "NOTE:running query #53\n."; 
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
    Table tbl_GlobalLimit_TD_0376571_output("tbl_GlobalLimit_TD_0376571_output", 6100000, 3, "");
    tbl_GlobalLimit_TD_0376571_output.allocateHost();
    Table tbl_LocalLimit_TD_1353004_output("tbl_LocalLimit_TD_1353004_output", 6100000, 3, "");
    tbl_LocalLimit_TD_1353004_output.allocateHost();
    Table tbl_Sort_TD_2430546_output("tbl_Sort_TD_2430546_output", 6100000, 3, "");
    tbl_Sort_TD_2430546_output.allocateHost();
    Table tbl_Filter_TD_3548668_output("tbl_Filter_TD_3548668_output", 6100000, 3, "");
    tbl_Filter_TD_3548668_output.allocateHost();
    Table tbl_Window_TD_4522026_output("tbl_Window_TD_4522026_output", 6100000, 4, "");
    tbl_Window_TD_4522026_output.allocateHost();
    Table tbl_Aggregate_TD_5872697_output_preprocess("tbl_Aggregate_TD_5872697_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_5872697_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_5872697_output("tbl_Aggregate_TD_5872697_output", 6100000, 3, "");
    tbl_Aggregate_TD_5872697_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6839131_output_preprocess("tbl_JOIN_INNER_TD_6839131_output_preprocess", 6100000, 3, "");
    tbl_JOIN_INNER_TD_6839131_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_6839131_output("tbl_JOIN_INNER_TD_6839131_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_6839131_output.allocateHost();
    Table tbl_JOIN_INNER_TD_747576_output("tbl_JOIN_INNER_TD_747576_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_747576_output.allocateHost();
    Table tbl_Filter_TD_7715016_output("tbl_Filter_TD_7715016_output", 6100000, 1, "");
    tbl_Filter_TD_7715016_output.allocateHost();
    Table tbl_JOIN_INNER_TD_829930_output("tbl_JOIN_INNER_TD_829930_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_829930_output.allocateHost();
    Table tbl_Filter_TD_8316034_output("tbl_Filter_TD_8316034_output", 6100000, 2, "");
    tbl_Filter_TD_8316034_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8392936_input;
    tbl_SerializeFromObject_TD_8392936_input = Table("store", store_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_8392936_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_8392936_input.allocateHost();
    tbl_SerializeFromObject_TD_8392936_input.loadHost();
    Table tbl_Filter_TD_9433095_output("tbl_Filter_TD_9433095_output", 6100000, 2, "");
    tbl_Filter_TD_9433095_output.allocateHost();
    Table tbl_Filter_TD_9856148_output("tbl_Filter_TD_9856148_output", 6100000, 4, "");
    tbl_Filter_TD_9856148_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9170354_input;
    tbl_SerializeFromObject_TD_9170354_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9170354_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_9170354_input.addCol("d_qoy", 4);
    tbl_SerializeFromObject_TD_9170354_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_9170354_input.allocateHost();
    tbl_SerializeFromObject_TD_9170354_input.loadHost();
    Table tbl_SerializeFromObject_TD_1086331_input;
    tbl_SerializeFromObject_TD_1086331_input = Table("item", item_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_1086331_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_1086331_input.addCol("i_manufact_id", 4);
    tbl_SerializeFromObject_TD_1086331_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_1086331_input.addCol("i_class", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_1086331_input.addCol("i_brand", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_1086331_input.allocateHost();
    tbl_SerializeFromObject_TD_1086331_input.loadHost();
    Table tbl_SerializeFromObject_TD_10208510_input;
    tbl_SerializeFromObject_TD_10208510_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_10208510_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10208510_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_10208510_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_10208510_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_10208510_input.allocateHost();
    tbl_SerializeFromObject_TD_10208510_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_6839131_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_5872697_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_JOIN_INNER_TD_6839131_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_747576_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_7715016_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_829930_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8316034_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9433095_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9856148_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    AggrCfgCmd cfg_Aggregate_TD_5872697_cmds;
    cfg_Aggregate_TD_5872697_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_5872697_gqe_aggr(cfg_Aggregate_TD_5872697_cmds.cmd);
    cfg_Aggregate_TD_5872697_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_5872697_cmds_out;
    cfg_Aggregate_TD_5872697_cmds_out.allocateHost();
    cfg_Aggregate_TD_5872697_cmds_out.allocateDevBuffer(context_a, 33);
    cfgCmd cfg_JOIN_INNER_TD_6839131_cmds;
    cfg_JOIN_INNER_TD_6839131_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_6839131_gqe_join (cfg_JOIN_INNER_TD_6839131_cmds.cmd);
    cfg_JOIN_INNER_TD_6839131_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_747576_cmds;
    cfg_JOIN_INNER_TD_747576_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_747576_gqe_join (cfg_JOIN_INNER_TD_747576_cmds.cmd);
    cfg_JOIN_INNER_TD_747576_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_829930_cmds;
    cfg_JOIN_INNER_TD_829930_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_829930_gqe_join (cfg_JOIN_INNER_TD_829930_cmds.cmd);
    cfg_JOIN_INNER_TD_829930_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    AggrBufferTmp buftmp_a(context_a); 
    buftmp_a.BufferInitial(q_a); 
    std::cout << std::endl; 
    AggrKrnlEngine krnl_Aggregate_TD_5872697;
    krnl_Aggregate_TD_5872697 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_5872697.setup(tbl_JOIN_INNER_TD_6839131_output, tbl_Aggregate_TD_5872697_output_preprocess, cfg_Aggregate_TD_5872697_cmds, cfg_Aggregate_TD_5872697_cmds_out, buftmp_a);
    krnlEngine krnl_JOIN_INNER_TD_6839131;
    krnl_JOIN_INNER_TD_6839131 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_6839131.setup(tbl_JOIN_INNER_TD_747576_output, tbl_Filter_TD_7715016_output, tbl_JOIN_INNER_TD_6839131_output_preprocess, cfg_JOIN_INNER_TD_6839131_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_747576;
    krnl_JOIN_INNER_TD_747576 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_747576.setup(tbl_JOIN_INNER_TD_829930_output, tbl_Filter_TD_8316034_output, tbl_JOIN_INNER_TD_747576_output, cfg_JOIN_INNER_TD_747576_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_829930;
    krnl_JOIN_INNER_TD_829930 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_829930.setup(tbl_Filter_TD_9433095_output, tbl_Filter_TD_9856148_output, tbl_JOIN_INNER_TD_829930_output, cfg_JOIN_INNER_TD_829930_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_Aggregate_TD_5872697;
    trans_Aggregate_TD_5872697.setq(q_a);
    trans_Aggregate_TD_5872697.add(&(cfg_Aggregate_TD_5872697_cmds));
    transEngine trans_Aggregate_TD_5872697_out;
    trans_Aggregate_TD_5872697_out.setq(q_a);
    q_a.finish();
    transEngine trans_JOIN_INNER_TD_6839131;
    trans_JOIN_INNER_TD_6839131.setq(q_h);
    trans_JOIN_INNER_TD_6839131.add(&(cfg_JOIN_INNER_TD_6839131_cmds));
    transEngine trans_JOIN_INNER_TD_6839131_out;
    trans_JOIN_INNER_TD_6839131_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_747576;
    trans_JOIN_INNER_TD_747576.setq(q_h);
    trans_JOIN_INNER_TD_747576.add(&(cfg_JOIN_INNER_TD_747576_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_829930;
    trans_JOIN_INNER_TD_829930.setq(q_h);
    trans_JOIN_INNER_TD_829930.add(&(cfg_JOIN_INNER_TD_829930_cmds));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_5872697;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_5872697;
    std::vector<cl::Event> events_Aggregate_TD_5872697;
    events_h2d_wr_Aggregate_TD_5872697.resize(1);
    events_d2h_rd_Aggregate_TD_5872697.resize(1);
    events_Aggregate_TD_5872697.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_5872697;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_5872697;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_6839131;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_6839131;
    std::vector<cl::Event> events_JOIN_INNER_TD_6839131;
    events_h2d_wr_JOIN_INNER_TD_6839131.resize(1);
    events_d2h_rd_JOIN_INNER_TD_6839131.resize(1);
    events_JOIN_INNER_TD_6839131.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_6839131;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_6839131;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_747576;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_747576;
    std::vector<cl::Event> events_JOIN_INNER_TD_747576;
    events_h2d_wr_JOIN_INNER_TD_747576.resize(1);
    events_d2h_rd_JOIN_INNER_TD_747576.resize(1);
    events_JOIN_INNER_TD_747576.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_747576;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_747576;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_829930;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_829930;
    std::vector<cl::Event> events_JOIN_INNER_TD_829930;
    events_h2d_wr_JOIN_INNER_TD_829930.resize(1);
    events_d2h_rd_JOIN_INNER_TD_829930.resize(1);
    events_JOIN_INNER_TD_829930.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_829930;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_829930;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_9_38195_s, tv_r_Filter_9_38195_e;
    gettimeofday(&tv_r_Filter_9_38195_s, 0);
    SW_Filter_TD_9856148(tbl_SerializeFromObject_TD_10208510_input, tbl_Filter_TD_9856148_output);
    gettimeofday(&tv_r_Filter_9_38195_e, 0);

    struct timeval tv_r_Filter_9_456158_s, tv_r_Filter_9_456158_e;
    gettimeofday(&tv_r_Filter_9_456158_s, 0);
    SW_Filter_TD_9433095(tbl_SerializeFromObject_TD_1086331_input, tbl_Filter_TD_9433095_output);
    gettimeofday(&tv_r_Filter_9_456158_e, 0);

    struct timeval tv_r_Filter_8_900757_s, tv_r_Filter_8_900757_e;
    gettimeofday(&tv_r_Filter_8_900757_s, 0);
    SW_Filter_TD_8316034(tbl_SerializeFromObject_TD_9170354_input, tbl_Filter_TD_8316034_output);
    gettimeofday(&tv_r_Filter_8_900757_e, 0);

    struct timeval tv_r_JOIN_INNER_8_269736_s, tv_r_JOIN_INNER_8_269736_e;
    gettimeofday(&tv_r_JOIN_INNER_8_269736_s, 0);
    trans_JOIN_INNER_TD_829930.add(&(tbl_Filter_TD_9433095_output));
    trans_JOIN_INNER_TD_829930.add(&(tbl_Filter_TD_9856148_output));
    trans_JOIN_INNER_TD_829930.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_829930), &(events_h2d_wr_JOIN_INNER_TD_829930[0]));
    events_grp_JOIN_INNER_TD_829930.push_back(events_h2d_wr_JOIN_INNER_TD_829930[0]);
    krnl_JOIN_INNER_TD_829930.run(0, &(events_grp_JOIN_INNER_TD_829930), &(events_JOIN_INNER_TD_829930[0]));
    gettimeofday(&tv_r_JOIN_INNER_8_269736_e, 0);

    struct timeval tv_r_Filter_7_260909_s, tv_r_Filter_7_260909_e;
    gettimeofday(&tv_r_Filter_7_260909_s, 0);
    SW_Filter_TD_7715016(tbl_SerializeFromObject_TD_8392936_input, tbl_Filter_TD_7715016_output);
    gettimeofday(&tv_r_Filter_7_260909_e, 0);

    struct timeval tv_r_JOIN_INNER_7_54390_s, tv_r_JOIN_INNER_7_54390_e;
    gettimeofday(&tv_r_JOIN_INNER_7_54390_s, 0);
    prev_events_grp_JOIN_INNER_TD_747576.push_back(events_h2d_wr_JOIN_INNER_TD_829930[0]);
    trans_JOIN_INNER_TD_747576.add(&(tbl_Filter_TD_8316034_output));
    trans_JOIN_INNER_TD_747576.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_747576), &(events_h2d_wr_JOIN_INNER_TD_747576[0]));
    events_grp_JOIN_INNER_TD_747576.push_back(events_h2d_wr_JOIN_INNER_TD_747576[0]);
    events_grp_JOIN_INNER_TD_747576.push_back(events_JOIN_INNER_TD_829930[0]);
    krnl_JOIN_INNER_TD_747576.run(0, &(events_grp_JOIN_INNER_TD_747576), &(events_JOIN_INNER_TD_747576[0]));
    gettimeofday(&tv_r_JOIN_INNER_7_54390_e, 0);

    struct timeval tv_r_JOIN_INNER_6_159282_s, tv_r_JOIN_INNER_6_159282_e;
    gettimeofday(&tv_r_JOIN_INNER_6_159282_s, 0);
    prev_events_grp_JOIN_INNER_TD_6839131.push_back(events_h2d_wr_JOIN_INNER_TD_747576[0]);
    trans_JOIN_INNER_TD_6839131.add(&(tbl_Filter_TD_7715016_output));
    trans_JOIN_INNER_TD_6839131.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_6839131), &(events_h2d_wr_JOIN_INNER_TD_6839131[0]));
    events_grp_JOIN_INNER_TD_6839131.push_back(events_h2d_wr_JOIN_INNER_TD_6839131[0]);
    events_grp_JOIN_INNER_TD_6839131.push_back(events_JOIN_INNER_TD_747576[0]);
    krnl_JOIN_INNER_TD_6839131.run(0, &(events_grp_JOIN_INNER_TD_6839131), &(events_JOIN_INNER_TD_6839131[0]));
    
    trans_JOIN_INNER_TD_6839131_out.add(&(tbl_JOIN_INNER_TD_6839131_output_preprocess));
    trans_JOIN_INNER_TD_6839131_out.dev2host(0, &(events_JOIN_INNER_TD_6839131), &(events_d2h_rd_JOIN_INNER_TD_6839131[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_6839131);
    tbl_JOIN_INNER_TD_6839131_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_6839131_output));
    gettimeofday(&tv_r_JOIN_INNER_6_159282_e, 0);

    struct timeval tv_r_Aggregate_5_630382_s, tv_r_Aggregate_5_630382_e;
    gettimeofday(&tv_r_Aggregate_5_630382_s, 0);
    trans_Aggregate_TD_5872697.add(&(tbl_JOIN_INNER_TD_6839131_output));
    trans_Aggregate_TD_5872697.host2dev(0, &(prev_events_grp_Aggregate_TD_5872697), &(events_h2d_wr_Aggregate_TD_5872697[0]));
    events_grp_Aggregate_TD_5872697.push_back(events_h2d_wr_Aggregate_TD_5872697[0]);
    krnl_Aggregate_TD_5872697.run(0, &(events_grp_Aggregate_TD_5872697), &(events_Aggregate_TD_5872697[0]));
    
    trans_Aggregate_TD_5872697_out.add(&(tbl_Aggregate_TD_5872697_output_preprocess));
    trans_Aggregate_TD_5872697_out.dev2host(0, &(events_Aggregate_TD_5872697), &(events_d2h_rd_Aggregate_TD_5872697[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_5872697_consolidate(tbl_Aggregate_TD_5872697_output_preprocess, tbl_Aggregate_TD_5872697_output);
    gettimeofday(&tv_r_Aggregate_5_630382_e, 0);

    struct timeval tv_r_Window_4_309305_s, tv_r_Window_4_309305_e;
    gettimeofday(&tv_r_Window_4_309305_s, 0);
    SW_Window_TD_4522026(tbl_Aggregate_TD_5872697_output, tbl_Window_TD_4522026_output);
    gettimeofday(&tv_r_Window_4_309305_e, 0);

    struct timeval tv_r_Filter_3_217497_s, tv_r_Filter_3_217497_e;
    gettimeofday(&tv_r_Filter_3_217497_s, 0);
    SW_Filter_TD_3548668(tbl_Window_TD_4522026_output, tbl_Filter_TD_3548668_output);
    gettimeofday(&tv_r_Filter_3_217497_e, 0);

    struct timeval tv_r_Sort_2_224139_s, tv_r_Sort_2_224139_e;
    gettimeofday(&tv_r_Sort_2_224139_s, 0);
    SW_Sort_TD_2430546(tbl_Filter_TD_3548668_output, tbl_Sort_TD_2430546_output);
    gettimeofday(&tv_r_Sort_2_224139_e, 0);

    struct timeval tv_r_LocalLimit_1_761672_s, tv_r_LocalLimit_1_761672_e;
    gettimeofday(&tv_r_LocalLimit_1_761672_s, 0);
    SW_LocalLimit_TD_1353004(tbl_Sort_TD_2430546_output, tbl_LocalLimit_TD_1353004_output);
    gettimeofday(&tv_r_LocalLimit_1_761672_e, 0);

    struct timeval tv_r_GlobalLimit_0_75256_s, tv_r_GlobalLimit_0_75256_e;
    gettimeofday(&tv_r_GlobalLimit_0_75256_s, 0);
    SW_GlobalLimit_TD_0376571(tbl_LocalLimit_TD_1353004_output, tbl_GlobalLimit_TD_0376571_output);
    gettimeofday(&tv_r_GlobalLimit_0_75256_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_38195_s, &tv_r_Filter_9_38195_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10208510_input: " << tbl_SerializeFromObject_TD_10208510_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_456158_s, &tv_r_Filter_9_456158_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1086331_input: " << tbl_SerializeFromObject_TD_1086331_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_900757_s, &tv_r_Filter_8_900757_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9170354_input: " << tbl_SerializeFromObject_TD_9170354_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_269736_s, &tv_r_JOIN_INNER_8_269736_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9433095_output: " << tbl_Filter_TD_9433095_output.getNumRow() << " " << "tbl_Filter_TD_9856148_output: " << tbl_Filter_TD_9856148_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_260909_s, &tv_r_Filter_7_260909_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8392936_input: " << tbl_SerializeFromObject_TD_8392936_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_54390_s, &tv_r_JOIN_INNER_7_54390_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_829930_output: " << tbl_JOIN_INNER_TD_829930_output.getNumRow() << " " << "tbl_Filter_TD_8316034_output: " << tbl_Filter_TD_8316034_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_159282_s, &tv_r_JOIN_INNER_6_159282_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_747576_output: " << tbl_JOIN_INNER_TD_747576_output.getNumRow() << " " << "tbl_Filter_TD_7715016_output: " << tbl_Filter_TD_7715016_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_630382_s, &tv_r_Aggregate_5_630382_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6839131_output: " << tbl_JOIN_INNER_TD_6839131_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_4: " << tvdiff(&tv_r_Window_4_309305_s, &tv_r_Window_4_309305_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_5872697_output: " << tbl_Aggregate_TD_5872697_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_217497_s, &tv_r_Filter_3_217497_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_4522026_output: " << tbl_Window_TD_4522026_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_224139_s, &tv_r_Sort_2_224139_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_3548668_output: " << tbl_Filter_TD_3548668_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_761672_s, &tv_r_LocalLimit_1_761672_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2430546_output: " << tbl_Sort_TD_2430546_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_75256_s, &tv_r_GlobalLimit_0_75256_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1353004_output: " << tbl_LocalLimit_TD_1353004_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.6398731 * 1000 << "ms" << std::endl; 
    return 0; 
}
