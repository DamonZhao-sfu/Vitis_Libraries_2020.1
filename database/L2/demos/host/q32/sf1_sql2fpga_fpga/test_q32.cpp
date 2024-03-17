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

#include "cfgFunc_q32.hpp" 
#include "q32.hpp" 

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
    std::cout << "NOTE:running query #32\n."; 
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
    Table tbl_Aggregate_TD_0715066_output("tbl_Aggregate_TD_0715066_output", 6100000, 1, "");
    tbl_Aggregate_TD_0715066_output.allocateHost();
    Table tbl_JOIN_INNER_TD_1846235_output("tbl_JOIN_INNER_TD_1846235_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_1846235_output.allocateHost();
    Table tbl_JOIN_INNER_TD_2562385_output("tbl_JOIN_INNER_TD_2562385_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_2562385_output.allocateHost();
    Table tbl_Filter_TD_2216161_output("tbl_Filter_TD_2216161_output", 6100000, 1, "");
    tbl_Filter_TD_2216161_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3122102_output("tbl_JOIN_INNER_TD_3122102_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_3122102_output.allocateHost();
    Table tbl_Filter_TD_3878254_output("tbl_Filter_TD_3878254_output", 6100000, 2, "");
    tbl_Filter_TD_3878254_output.allocateHost();
    Table tbl_SerializeFromObject_TD_3416327_input;
    tbl_SerializeFromObject_TD_3416327_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_3416327_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_3416327_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_3416327_input.allocateHost();
    tbl_SerializeFromObject_TD_3416327_input.loadHost();
    Table tbl_Filter_TD_4946654_output("tbl_Filter_TD_4946654_output", 6100000, 3, "");
    tbl_Filter_TD_4946654_output.allocateHost();
    Table tbl_Filter_TD_4407201_output("tbl_Filter_TD_4407201_output", 6100000, 1, "");
    tbl_Filter_TD_4407201_output.allocateHost();
    Table tbl_Aggregate_TD_4606231_output_preprocess("tbl_Aggregate_TD_4606231_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_4606231_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_4606231_output("tbl_Aggregate_TD_4606231_output", 6100000, 2, "");
    tbl_Aggregate_TD_4606231_output.allocateHost();
    Table tbl_SerializeFromObject_TD_5477478_input;
    tbl_SerializeFromObject_TD_5477478_input = Table("catalog_sales", catalog_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_5477478_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_5477478_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_5477478_input.addCol("cs_ext_discount_amt", 4);
    tbl_SerializeFromObject_TD_5477478_input.allocateHost();
    tbl_SerializeFromObject_TD_5477478_input.loadHost();
    Table tbl_SerializeFromObject_TD_5529308_input;
    tbl_SerializeFromObject_TD_5529308_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_5529308_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_5529308_input.addCol("i_manufact_id", 4);
    tbl_SerializeFromObject_TD_5529308_input.allocateHost();
    tbl_SerializeFromObject_TD_5529308_input.loadHost();
    Table tbl_JOIN_INNER_TD_5608393_output_preprocess("tbl_JOIN_INNER_TD_5608393_output_preprocess", 6100000, 2, "");
    tbl_JOIN_INNER_TD_5608393_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_5608393_output("tbl_JOIN_INNER_TD_5608393_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_5608393_output.allocateHost();
    Table tbl_Filter_TD_6947090_output("tbl_Filter_TD_6947090_output", 6100000, 3, "");
    tbl_Filter_TD_6947090_output.allocateHost();
    Table tbl_Filter_TD_6570646_output("tbl_Filter_TD_6570646_output", 6100000, 1, "");
    tbl_Filter_TD_6570646_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7499425_input;
    tbl_SerializeFromObject_TD_7499425_input = Table("catalog_sales", catalog_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7499425_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_7499425_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_7499425_input.addCol("cs_ext_discount_amt", 4);
    tbl_SerializeFromObject_TD_7499425_input.allocateHost();
    tbl_SerializeFromObject_TD_7499425_input.loadHost();
    Table tbl_SerializeFromObject_TD_7891843_input;
    tbl_SerializeFromObject_TD_7891843_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7891843_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_7891843_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_7891843_input.allocateHost();
    tbl_SerializeFromObject_TD_7891843_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_1846235_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_2562385_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_2216161_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_3122102_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_3878254_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_4946654_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_4407201_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_5608393_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_4606231_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_JOIN_INNER_TD_5608393_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_6947090_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_6570646_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_1846235_cmds;
    cfg_JOIN_INNER_TD_1846235_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_1846235_gqe_join (cfg_JOIN_INNER_TD_1846235_cmds.cmd);
    cfg_JOIN_INNER_TD_1846235_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_2562385_cmds;
    cfg_JOIN_INNER_TD_2562385_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_2562385_gqe_join (cfg_JOIN_INNER_TD_2562385_cmds.cmd);
    cfg_JOIN_INNER_TD_2562385_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_3122102_cmds;
    cfg_JOIN_INNER_TD_3122102_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_3122102_gqe_join (cfg_JOIN_INNER_TD_3122102_cmds.cmd);
    cfg_JOIN_INNER_TD_3122102_cmds.allocateDevBuffer(context_h, 32);
    AggrCfgCmd cfg_Aggregate_TD_4606231_cmds;
    cfg_Aggregate_TD_4606231_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_4606231_gqe_aggr(cfg_Aggregate_TD_4606231_cmds.cmd);
    cfg_Aggregate_TD_4606231_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_4606231_cmds_out;
    cfg_Aggregate_TD_4606231_cmds_out.allocateHost();
    cfg_Aggregate_TD_4606231_cmds_out.allocateDevBuffer(context_a, 33);
    cfgCmd cfg_JOIN_INNER_TD_5608393_cmds;
    cfg_JOIN_INNER_TD_5608393_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_5608393_gqe_join (cfg_JOIN_INNER_TD_5608393_cmds.cmd);
    cfg_JOIN_INNER_TD_5608393_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    AggrBufferTmp buftmp_a(context_a); 
    buftmp_a.BufferInitial(q_a); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_1846235;
    krnl_JOIN_INNER_TD_1846235 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_1846235.setup(tbl_JOIN_INNER_TD_2562385_output, tbl_Filter_TD_2216161_output, tbl_JOIN_INNER_TD_1846235_output, cfg_JOIN_INNER_TD_1846235_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_2562385;
    krnl_JOIN_INNER_TD_2562385 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_2562385.setup(tbl_JOIN_INNER_TD_3122102_output, tbl_Filter_TD_3878254_output, tbl_JOIN_INNER_TD_2562385_output, cfg_JOIN_INNER_TD_2562385_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_3122102;
    krnl_JOIN_INNER_TD_3122102 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_3122102.setup(tbl_Filter_TD_4946654_output, tbl_Filter_TD_4407201_output, tbl_JOIN_INNER_TD_3122102_output, cfg_JOIN_INNER_TD_3122102_cmds, buftmp_h);
    AggrKrnlEngine krnl_Aggregate_TD_4606231;
    krnl_Aggregate_TD_4606231 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_4606231.setup(tbl_JOIN_INNER_TD_5608393_output, tbl_Aggregate_TD_4606231_output_preprocess, cfg_Aggregate_TD_4606231_cmds, cfg_Aggregate_TD_4606231_cmds_out, buftmp_a);
    krnlEngine krnl_JOIN_INNER_TD_5608393;
    krnl_JOIN_INNER_TD_5608393 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_5608393.setup(tbl_Filter_TD_6947090_output, tbl_Filter_TD_6570646_output, tbl_JOIN_INNER_TD_5608393_output_preprocess, cfg_JOIN_INNER_TD_5608393_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_1846235;
    trans_JOIN_INNER_TD_1846235.setq(q_h);
    trans_JOIN_INNER_TD_1846235.add(&(cfg_JOIN_INNER_TD_1846235_cmds));
    transEngine trans_JOIN_INNER_TD_1846235_out;
    trans_JOIN_INNER_TD_1846235_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_2562385;
    trans_JOIN_INNER_TD_2562385.setq(q_h);
    trans_JOIN_INNER_TD_2562385.add(&(cfg_JOIN_INNER_TD_2562385_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_3122102;
    trans_JOIN_INNER_TD_3122102.setq(q_h);
    trans_JOIN_INNER_TD_3122102.add(&(cfg_JOIN_INNER_TD_3122102_cmds));
    q_h.finish();
    transEngine trans_Aggregate_TD_4606231;
    trans_Aggregate_TD_4606231.setq(q_a);
    trans_Aggregate_TD_4606231.add(&(cfg_Aggregate_TD_4606231_cmds));
    transEngine trans_Aggregate_TD_4606231_out;
    trans_Aggregate_TD_4606231_out.setq(q_a);
    q_a.finish();
    transEngine trans_JOIN_INNER_TD_5608393;
    trans_JOIN_INNER_TD_5608393.setq(q_h);
    trans_JOIN_INNER_TD_5608393.add(&(cfg_JOIN_INNER_TD_5608393_cmds));
    transEngine trans_JOIN_INNER_TD_5608393_out;
    trans_JOIN_INNER_TD_5608393_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_1846235;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_1846235;
    std::vector<cl::Event> events_JOIN_INNER_TD_1846235;
    events_h2d_wr_JOIN_INNER_TD_1846235.resize(1);
    events_d2h_rd_JOIN_INNER_TD_1846235.resize(1);
    events_JOIN_INNER_TD_1846235.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_1846235;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_1846235;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_2562385;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_2562385;
    std::vector<cl::Event> events_JOIN_INNER_TD_2562385;
    events_h2d_wr_JOIN_INNER_TD_2562385.resize(1);
    events_d2h_rd_JOIN_INNER_TD_2562385.resize(1);
    events_JOIN_INNER_TD_2562385.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_2562385;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_2562385;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_3122102;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_3122102;
    std::vector<cl::Event> events_JOIN_INNER_TD_3122102;
    events_h2d_wr_JOIN_INNER_TD_3122102.resize(1);
    events_d2h_rd_JOIN_INNER_TD_3122102.resize(1);
    events_JOIN_INNER_TD_3122102.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_3122102;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_3122102;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_4606231;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_4606231;
    std::vector<cl::Event> events_Aggregate_TD_4606231;
    events_h2d_wr_Aggregate_TD_4606231.resize(1);
    events_d2h_rd_Aggregate_TD_4606231.resize(1);
    events_Aggregate_TD_4606231.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_4606231;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_4606231;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_5608393;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_5608393;
    std::vector<cl::Event> events_JOIN_INNER_TD_5608393;
    events_h2d_wr_JOIN_INNER_TD_5608393.resize(1);
    events_d2h_rd_JOIN_INNER_TD_5608393.resize(1);
    events_JOIN_INNER_TD_5608393.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_5608393;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_5608393;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_6_544144_s, tv_r_Filter_6_544144_e;
    gettimeofday(&tv_r_Filter_6_544144_s, 0);
    SW_Filter_TD_6570646(tbl_SerializeFromObject_TD_7891843_input, tbl_Filter_TD_6570646_output);
    gettimeofday(&tv_r_Filter_6_544144_e, 0);

    struct timeval tv_r_Filter_6_799293_s, tv_r_Filter_6_799293_e;
    gettimeofday(&tv_r_Filter_6_799293_s, 0);
    SW_Filter_TD_6947090(tbl_SerializeFromObject_TD_7499425_input, tbl_Filter_TD_6947090_output);
    gettimeofday(&tv_r_Filter_6_799293_e, 0);

    struct timeval tv_r_JOIN_INNER_5_257224_s, tv_r_JOIN_INNER_5_257224_e;
    gettimeofday(&tv_r_JOIN_INNER_5_257224_s, 0);
    trans_JOIN_INNER_TD_5608393.add(&(tbl_Filter_TD_6947090_output));
    trans_JOIN_INNER_TD_5608393.add(&(tbl_Filter_TD_6570646_output));
    trans_JOIN_INNER_TD_5608393.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_5608393), &(events_h2d_wr_JOIN_INNER_TD_5608393[0]));
    events_grp_JOIN_INNER_TD_5608393.push_back(events_h2d_wr_JOIN_INNER_TD_5608393[0]);
    krnl_JOIN_INNER_TD_5608393.run(0, &(events_grp_JOIN_INNER_TD_5608393), &(events_JOIN_INNER_TD_5608393[0]));
    
    trans_JOIN_INNER_TD_5608393_out.add(&(tbl_JOIN_INNER_TD_5608393_output_preprocess));
    trans_JOIN_INNER_TD_5608393_out.dev2host(0, &(events_JOIN_INNER_TD_5608393), &(events_d2h_rd_JOIN_INNER_TD_5608393[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_5608393);
    tbl_JOIN_INNER_TD_5608393_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_5608393_output));
    gettimeofday(&tv_r_JOIN_INNER_5_257224_e, 0);

    struct timeval tv_r_Aggregate_4_845049_s, tv_r_Aggregate_4_845049_e;
    gettimeofday(&tv_r_Aggregate_4_845049_s, 0);
    trans_Aggregate_TD_4606231.add(&(tbl_JOIN_INNER_TD_5608393_output));
    trans_Aggregate_TD_4606231.host2dev(0, &(prev_events_grp_Aggregate_TD_4606231), &(events_h2d_wr_Aggregate_TD_4606231[0]));
    events_grp_Aggregate_TD_4606231.push_back(events_h2d_wr_Aggregate_TD_4606231[0]);
    krnl_Aggregate_TD_4606231.run(0, &(events_grp_Aggregate_TD_4606231), &(events_Aggregate_TD_4606231[0]));
    
    trans_Aggregate_TD_4606231_out.add(&(tbl_Aggregate_TD_4606231_output_preprocess));
    trans_Aggregate_TD_4606231_out.dev2host(0, &(events_Aggregate_TD_4606231), &(events_d2h_rd_Aggregate_TD_4606231[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_4606231_consolidate(tbl_Aggregate_TD_4606231_output_preprocess, tbl_Aggregate_TD_4606231_output);
    gettimeofday(&tv_r_Aggregate_4_845049_e, 0);

    struct timeval tv_r_Filter_4_448741_s, tv_r_Filter_4_448741_e;
    gettimeofday(&tv_r_Filter_4_448741_s, 0);
    SW_Filter_TD_4407201(tbl_SerializeFromObject_TD_5529308_input, tbl_Filter_TD_4407201_output);
    gettimeofday(&tv_r_Filter_4_448741_e, 0);

    struct timeval tv_r_Filter_4_210672_s, tv_r_Filter_4_210672_e;
    gettimeofday(&tv_r_Filter_4_210672_s, 0);
    SW_Filter_TD_4946654(tbl_SerializeFromObject_TD_5477478_input, tbl_Filter_TD_4946654_output);
    gettimeofday(&tv_r_Filter_4_210672_e, 0);

    struct timeval tv_r_Filter_3_316613_s, tv_r_Filter_3_316613_e;
    gettimeofday(&tv_r_Filter_3_316613_s, 0);
    SW_Filter_TD_3878254(tbl_Aggregate_TD_4606231_output, tbl_Filter_TD_3878254_output);
    gettimeofday(&tv_r_Filter_3_316613_e, 0);

    struct timeval tv_r_JOIN_INNER_3_650805_s, tv_r_JOIN_INNER_3_650805_e;
    gettimeofday(&tv_r_JOIN_INNER_3_650805_s, 0);
    trans_JOIN_INNER_TD_3122102.add(&(tbl_Filter_TD_4946654_output));
    trans_JOIN_INNER_TD_3122102.add(&(tbl_Filter_TD_4407201_output));
    trans_JOIN_INNER_TD_3122102.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_3122102), &(events_h2d_wr_JOIN_INNER_TD_3122102[0]));
    events_grp_JOIN_INNER_TD_3122102.push_back(events_h2d_wr_JOIN_INNER_TD_3122102[0]);
    krnl_JOIN_INNER_TD_3122102.run(0, &(events_grp_JOIN_INNER_TD_3122102), &(events_JOIN_INNER_TD_3122102[0]));
    gettimeofday(&tv_r_JOIN_INNER_3_650805_e, 0);

    struct timeval tv_r_Filter_2_788461_s, tv_r_Filter_2_788461_e;
    gettimeofday(&tv_r_Filter_2_788461_s, 0);
    SW_Filter_TD_2216161(tbl_SerializeFromObject_TD_3416327_input, tbl_Filter_TD_2216161_output);
    gettimeofday(&tv_r_Filter_2_788461_e, 0);

    struct timeval tv_r_JOIN_INNER_2_950832_s, tv_r_JOIN_INNER_2_950832_e;
    gettimeofday(&tv_r_JOIN_INNER_2_950832_s, 0);
    prev_events_grp_JOIN_INNER_TD_2562385.push_back(events_h2d_wr_JOIN_INNER_TD_3122102[0]);
    trans_JOIN_INNER_TD_2562385.add(&(tbl_Filter_TD_3878254_output));
    trans_JOIN_INNER_TD_2562385.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_2562385), &(events_h2d_wr_JOIN_INNER_TD_2562385[0]));
    events_grp_JOIN_INNER_TD_2562385.push_back(events_h2d_wr_JOIN_INNER_TD_2562385[0]);
    events_grp_JOIN_INNER_TD_2562385.push_back(events_JOIN_INNER_TD_3122102[0]);
    krnl_JOIN_INNER_TD_2562385.run(0, &(events_grp_JOIN_INNER_TD_2562385), &(events_JOIN_INNER_TD_2562385[0]));
    gettimeofday(&tv_r_JOIN_INNER_2_950832_e, 0);

    struct timeval tv_r_JOIN_INNER_1_74348_s, tv_r_JOIN_INNER_1_74348_e;
    gettimeofday(&tv_r_JOIN_INNER_1_74348_s, 0);
    prev_events_grp_JOIN_INNER_TD_1846235.push_back(events_h2d_wr_JOIN_INNER_TD_2562385[0]);
    trans_JOIN_INNER_TD_1846235.add(&(tbl_Filter_TD_2216161_output));
    trans_JOIN_INNER_TD_1846235.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_1846235), &(events_h2d_wr_JOIN_INNER_TD_1846235[0]));
    events_grp_JOIN_INNER_TD_1846235.push_back(events_h2d_wr_JOIN_INNER_TD_1846235[0]);
    events_grp_JOIN_INNER_TD_1846235.push_back(events_JOIN_INNER_TD_2562385[0]);
    krnl_JOIN_INNER_TD_1846235.run(0, &(events_grp_JOIN_INNER_TD_1846235), &(events_JOIN_INNER_TD_1846235[0]));
    
    trans_JOIN_INNER_TD_1846235_out.add(&(tbl_JOIN_INNER_TD_1846235_output));
    trans_JOIN_INNER_TD_1846235_out.dev2host(0, &(events_JOIN_INNER_TD_1846235), &(events_d2h_rd_JOIN_INNER_TD_1846235[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_1_74348_e, 0);

    struct timeval tv_r_Aggregate_0_885663_s, tv_r_Aggregate_0_885663_e;
    gettimeofday(&tv_r_Aggregate_0_885663_s, 0);
    SW_Aggregate_TD_0715066(tbl_JOIN_INNER_TD_1846235_output, tbl_Aggregate_TD_0715066_output);
    gettimeofday(&tv_r_Aggregate_0_885663_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_544144_s, &tv_r_Filter_6_544144_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7891843_input: " << tbl_SerializeFromObject_TD_7891843_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_799293_s, &tv_r_Filter_6_799293_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7499425_input: " << tbl_SerializeFromObject_TD_7499425_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_257224_s, &tv_r_JOIN_INNER_5_257224_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6947090_output: " << tbl_Filter_TD_6947090_output.getNumRow() << " " << "tbl_Filter_TD_6570646_output: " << tbl_Filter_TD_6570646_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_4: " << tvdiff(&tv_r_Aggregate_4_845049_s, &tv_r_Aggregate_4_845049_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5608393_output: " << tbl_JOIN_INNER_TD_5608393_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_448741_s, &tv_r_Filter_4_448741_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5529308_input: " << tbl_SerializeFromObject_TD_5529308_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_210672_s, &tv_r_Filter_4_210672_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5477478_input: " << tbl_SerializeFromObject_TD_5477478_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_316613_s, &tv_r_Filter_3_316613_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_4606231_output: " << tbl_Aggregate_TD_4606231_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_650805_s, &tv_r_JOIN_INNER_3_650805_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_4946654_output: " << tbl_Filter_TD_4946654_output.getNumRow() << " " << "tbl_Filter_TD_4407201_output: " << tbl_Filter_TD_4407201_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_788461_s, &tv_r_Filter_2_788461_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3416327_input: " << tbl_SerializeFromObject_TD_3416327_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_2: " << tvdiff(&tv_r_JOIN_INNER_2_950832_s, &tv_r_JOIN_INNER_2_950832_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3122102_output: " << tbl_JOIN_INNER_TD_3122102_output.getNumRow() << " " << "tbl_Filter_TD_3878254_output: " << tbl_Filter_TD_3878254_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_1: " << tvdiff(&tv_r_JOIN_INNER_1_74348_s, &tv_r_JOIN_INNER_1_74348_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_2562385_output: " << tbl_JOIN_INNER_TD_2562385_output.getNumRow() << " " << "tbl_Filter_TD_2216161_output: " << tbl_Filter_TD_2216161_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_0: " << tvdiff(&tv_r_Aggregate_0_885663_s, &tv_r_Aggregate_0_885663_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_1846235_output: " << tbl_JOIN_INNER_TD_1846235_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.6309004 * 1000 << "ms" << std::endl; 
    return 0; 
}
