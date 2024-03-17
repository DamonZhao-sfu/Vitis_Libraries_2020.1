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

#include "cfgFunc_q27.hpp" 
#include "q27.hpp" 

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
    std::cout << "NOTE:running query #27\n."; 
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
    Table tbl_GlobalLimit_TD_0318897_output("tbl_GlobalLimit_TD_0318897_output", 6100000, 7, "");
    tbl_GlobalLimit_TD_0318897_output.allocateHost();
    Table tbl_LocalLimit_TD_1216500_output("tbl_LocalLimit_TD_1216500_output", 6100000, 7, "");
    tbl_LocalLimit_TD_1216500_output.allocateHost();
    Table tbl_Sort_TD_2827164_output("tbl_Sort_TD_2827164_output", 6100000, 7, "");
    tbl_Sort_TD_2827164_output.allocateHost();
    Table tbl_Aggregate_TD_3494765_output("tbl_Aggregate_TD_3494765_output", 6100000, 7, "");
    tbl_Aggregate_TD_3494765_output.allocateHost();
    Table tbl_Expand_TD_4857594_output("tbl_Expand_TD_4857594_output", 6100000, 7, "");
    tbl_Expand_TD_4857594_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5947504_output("tbl_JOIN_INNER_TD_5947504_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_5947504_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6356181_output("tbl_JOIN_INNER_TD_6356181_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_6356181_output.allocateHost();
    Table tbl_Filter_TD_685002_output("tbl_Filter_TD_685002_output", 6100000, 2, "");
    tbl_Filter_TD_685002_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7348578_output("tbl_JOIN_INNER_TD_7348578_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_7348578_output.allocateHost();
    Table tbl_Filter_TD_7646483_output("tbl_Filter_TD_7646483_output", 6100000, 2, "");
    tbl_Filter_TD_7646483_output.allocateHost();
    Table tbl_SerializeFromObject_TD_778862_input;
    tbl_SerializeFromObject_TD_778862_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_778862_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_778862_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_778862_input.allocateHost();
    tbl_SerializeFromObject_TD_778862_input.loadHost();
    Table tbl_JOIN_INNER_TD_8575196_output("tbl_JOIN_INNER_TD_8575196_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_8575196_output.allocateHost();
    Table tbl_Filter_TD_8464956_output("tbl_Filter_TD_8464956_output", 6100000, 1, "");
    tbl_Filter_TD_8464956_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8699779_input;
    tbl_SerializeFromObject_TD_8699779_input = Table("store", store_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8699779_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_8699779_input.addCol("s_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8699779_input.allocateHost();
    tbl_SerializeFromObject_TD_8699779_input.loadHost();
    Table tbl_Filter_TD_9310488_output("tbl_Filter_TD_9310488_output", 6100000, 8, "");
    tbl_Filter_TD_9310488_output.allocateHost();
    Table tbl_Filter_TD_9913329_output("tbl_Filter_TD_9913329_output", 6100000, 1, "");
    tbl_Filter_TD_9913329_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9644014_input;
    tbl_SerializeFromObject_TD_9644014_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9644014_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_9644014_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_9644014_input.allocateHost();
    tbl_SerializeFromObject_TD_9644014_input.loadHost();
    Table tbl_SerializeFromObject_TD_10328485_input;
    tbl_SerializeFromObject_TD_10328485_input = Table("store_sales", store_sales_n, 8, in_dir, "orc");
    tbl_SerializeFromObject_TD_10328485_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10328485_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_10328485_input.addCol("ss_cdemo_sk", 4);
    tbl_SerializeFromObject_TD_10328485_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_10328485_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_10328485_input.addCol("ss_list_price", 4);
    tbl_SerializeFromObject_TD_10328485_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_10328485_input.addCol("ss_coupon_amt", 4);
    tbl_SerializeFromObject_TD_10328485_input.allocateHost();
    tbl_SerializeFromObject_TD_10328485_input.loadHost();
    Table tbl_SerializeFromObject_TD_10579768_input;
    tbl_SerializeFromObject_TD_10579768_input = Table("customer_demographics", customer_demographics_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_10579768_input.addCol("cd_demo_sk", 4);
    tbl_SerializeFromObject_TD_10579768_input.addCol("cd_gender", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10579768_input.addCol("cd_marital_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10579768_input.addCol("cd_education_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10579768_input.allocateHost();
    tbl_SerializeFromObject_TD_10579768_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_7348578_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8575196_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8464956_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9310488_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9913329_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_7348578_cmds;
    cfg_JOIN_INNER_TD_7348578_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7348578_gqe_join (cfg_JOIN_INNER_TD_7348578_cmds.cmd);
    cfg_JOIN_INNER_TD_7348578_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8575196_cmds;
    cfg_JOIN_INNER_TD_8575196_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8575196_gqe_join (cfg_JOIN_INNER_TD_8575196_cmds.cmd);
    cfg_JOIN_INNER_TD_8575196_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_7348578;
    krnl_JOIN_INNER_TD_7348578 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7348578.setup(tbl_JOIN_INNER_TD_8575196_output, tbl_Filter_TD_8464956_output, tbl_JOIN_INNER_TD_7348578_output, cfg_JOIN_INNER_TD_7348578_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_8575196;
    krnl_JOIN_INNER_TD_8575196 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8575196.setup(tbl_Filter_TD_9310488_output, tbl_Filter_TD_9913329_output, tbl_JOIN_INNER_TD_8575196_output, cfg_JOIN_INNER_TD_8575196_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_7348578;
    trans_JOIN_INNER_TD_7348578.setq(q_h);
    trans_JOIN_INNER_TD_7348578.add(&(cfg_JOIN_INNER_TD_7348578_cmds));
    transEngine trans_JOIN_INNER_TD_7348578_out;
    trans_JOIN_INNER_TD_7348578_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_8575196;
    trans_JOIN_INNER_TD_8575196.setq(q_h);
    trans_JOIN_INNER_TD_8575196.add(&(cfg_JOIN_INNER_TD_8575196_cmds));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7348578;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7348578;
    std::vector<cl::Event> events_JOIN_INNER_TD_7348578;
    events_h2d_wr_JOIN_INNER_TD_7348578.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7348578.resize(1);
    events_JOIN_INNER_TD_7348578.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7348578;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7348578;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8575196;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8575196;
    std::vector<cl::Event> events_JOIN_INNER_TD_8575196;
    events_h2d_wr_JOIN_INNER_TD_8575196.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8575196.resize(1);
    events_JOIN_INNER_TD_8575196.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8575196;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8575196;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_9_211057_s, tv_r_Filter_9_211057_e;
    gettimeofday(&tv_r_Filter_9_211057_s, 0);
    SW_Filter_TD_9913329(tbl_SerializeFromObject_TD_10579768_input, tbl_Filter_TD_9913329_output);
    gettimeofday(&tv_r_Filter_9_211057_e, 0);

    struct timeval tv_r_Filter_9_941268_s, tv_r_Filter_9_941268_e;
    gettimeofday(&tv_r_Filter_9_941268_s, 0);
    SW_Filter_TD_9310488(tbl_SerializeFromObject_TD_10328485_input, tbl_Filter_TD_9310488_output);
    gettimeofday(&tv_r_Filter_9_941268_e, 0);

    struct timeval tv_r_Filter_8_537375_s, tv_r_Filter_8_537375_e;
    gettimeofday(&tv_r_Filter_8_537375_s, 0);
    SW_Filter_TD_8464956(tbl_SerializeFromObject_TD_9644014_input, tbl_Filter_TD_8464956_output);
    gettimeofday(&tv_r_Filter_8_537375_e, 0);

    struct timeval tv_r_JOIN_INNER_8_108759_s, tv_r_JOIN_INNER_8_108759_e;
    gettimeofday(&tv_r_JOIN_INNER_8_108759_s, 0);
    trans_JOIN_INNER_TD_8575196.add(&(tbl_Filter_TD_9310488_output));
    trans_JOIN_INNER_TD_8575196.add(&(tbl_Filter_TD_9913329_output));
    trans_JOIN_INNER_TD_8575196.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8575196), &(events_h2d_wr_JOIN_INNER_TD_8575196[0]));
    events_grp_JOIN_INNER_TD_8575196.push_back(events_h2d_wr_JOIN_INNER_TD_8575196[0]);
    krnl_JOIN_INNER_TD_8575196.run(0, &(events_grp_JOIN_INNER_TD_8575196), &(events_JOIN_INNER_TD_8575196[0]));
    gettimeofday(&tv_r_JOIN_INNER_8_108759_e, 0);

    struct timeval tv_r_Filter_7_316059_s, tv_r_Filter_7_316059_e;
    gettimeofday(&tv_r_Filter_7_316059_s, 0);
    SW_Filter_TD_7646483(tbl_SerializeFromObject_TD_8699779_input, tbl_Filter_TD_7646483_output);
    gettimeofday(&tv_r_Filter_7_316059_e, 0);

    struct timeval tv_r_JOIN_INNER_7_979855_s, tv_r_JOIN_INNER_7_979855_e;
    gettimeofday(&tv_r_JOIN_INNER_7_979855_s, 0);
    prev_events_grp_JOIN_INNER_TD_7348578.push_back(events_h2d_wr_JOIN_INNER_TD_8575196[0]);
    trans_JOIN_INNER_TD_7348578.add(&(tbl_Filter_TD_8464956_output));
    trans_JOIN_INNER_TD_7348578.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7348578), &(events_h2d_wr_JOIN_INNER_TD_7348578[0]));
    events_grp_JOIN_INNER_TD_7348578.push_back(events_h2d_wr_JOIN_INNER_TD_7348578[0]);
    events_grp_JOIN_INNER_TD_7348578.push_back(events_JOIN_INNER_TD_8575196[0]);
    krnl_JOIN_INNER_TD_7348578.run(0, &(events_grp_JOIN_INNER_TD_7348578), &(events_JOIN_INNER_TD_7348578[0]));
    
    trans_JOIN_INNER_TD_7348578_out.add(&(tbl_JOIN_INNER_TD_7348578_output));
    trans_JOIN_INNER_TD_7348578_out.dev2host(0, &(events_JOIN_INNER_TD_7348578), &(events_d2h_rd_JOIN_INNER_TD_7348578[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_7_979855_e, 0);

    struct timeval tv_r_Filter_6_871725_s, tv_r_Filter_6_871725_e;
    gettimeofday(&tv_r_Filter_6_871725_s, 0);
    SW_Filter_TD_685002(tbl_SerializeFromObject_TD_778862_input, tbl_Filter_TD_685002_output);
    gettimeofday(&tv_r_Filter_6_871725_e, 0);

    struct timeval tv_r_JOIN_INNER_6_514748_s, tv_r_JOIN_INNER_6_514748_e;
    gettimeofday(&tv_r_JOIN_INNER_6_514748_s, 0);
    SW_JOIN_INNER_TD_6356181(tbl_JOIN_INNER_TD_7348578_output, tbl_Filter_TD_7646483_output, tbl_JOIN_INNER_TD_6356181_output);
    gettimeofday(&tv_r_JOIN_INNER_6_514748_e, 0);

    struct timeval tv_r_JOIN_INNER_5_957562_s, tv_r_JOIN_INNER_5_957562_e;
    gettimeofday(&tv_r_JOIN_INNER_5_957562_s, 0);
    SW_JOIN_INNER_TD_5947504(tbl_JOIN_INNER_TD_6356181_output, tbl_Filter_TD_685002_output, tbl_JOIN_INNER_TD_5947504_output);
    gettimeofday(&tv_r_JOIN_INNER_5_957562_e, 0);

    struct timeval tv_r_Expand_4_807132_s, tv_r_Expand_4_807132_e;
    gettimeofday(&tv_r_Expand_4_807132_s, 0);
    SW_Expand_TD_4857594(tbl_JOIN_INNER_TD_5947504_output, tbl_Expand_TD_4857594_output);
    gettimeofday(&tv_r_Expand_4_807132_e, 0);

    struct timeval tv_r_Aggregate_3_691229_s, tv_r_Aggregate_3_691229_e;
    gettimeofday(&tv_r_Aggregate_3_691229_s, 0);
    SW_Aggregate_TD_3494765(tbl_Expand_TD_4857594_output, tbl_Aggregate_TD_3494765_output);
    gettimeofday(&tv_r_Aggregate_3_691229_e, 0);

    struct timeval tv_r_Sort_2_775467_s, tv_r_Sort_2_775467_e;
    gettimeofday(&tv_r_Sort_2_775467_s, 0);
    SW_Sort_TD_2827164(tbl_Aggregate_TD_3494765_output, tbl_Sort_TD_2827164_output);
    gettimeofday(&tv_r_Sort_2_775467_e, 0);

    struct timeval tv_r_LocalLimit_1_80066_s, tv_r_LocalLimit_1_80066_e;
    gettimeofday(&tv_r_LocalLimit_1_80066_s, 0);
    SW_LocalLimit_TD_1216500(tbl_Sort_TD_2827164_output, tbl_LocalLimit_TD_1216500_output);
    gettimeofday(&tv_r_LocalLimit_1_80066_e, 0);

    struct timeval tv_r_GlobalLimit_0_315408_s, tv_r_GlobalLimit_0_315408_e;
    gettimeofday(&tv_r_GlobalLimit_0_315408_s, 0);
    SW_GlobalLimit_TD_0318897(tbl_LocalLimit_TD_1216500_output, tbl_GlobalLimit_TD_0318897_output);
    gettimeofday(&tv_r_GlobalLimit_0_315408_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_211057_s, &tv_r_Filter_9_211057_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10579768_input: " << tbl_SerializeFromObject_TD_10579768_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_941268_s, &tv_r_Filter_9_941268_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10328485_input: " << tbl_SerializeFromObject_TD_10328485_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_537375_s, &tv_r_Filter_8_537375_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9644014_input: " << tbl_SerializeFromObject_TD_9644014_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_108759_s, &tv_r_JOIN_INNER_8_108759_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9310488_output: " << tbl_Filter_TD_9310488_output.getNumRow() << " " << "tbl_Filter_TD_9913329_output: " << tbl_Filter_TD_9913329_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_316059_s, &tv_r_Filter_7_316059_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8699779_input: " << tbl_SerializeFromObject_TD_8699779_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_979855_s, &tv_r_JOIN_INNER_7_979855_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8575196_output: " << tbl_JOIN_INNER_TD_8575196_output.getNumRow() << " " << "tbl_Filter_TD_8464956_output: " << tbl_Filter_TD_8464956_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_871725_s, &tv_r_Filter_6_871725_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_778862_input: " << tbl_SerializeFromObject_TD_778862_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_514748_s, &tv_r_JOIN_INNER_6_514748_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7348578_output: " << tbl_JOIN_INNER_TD_7348578_output.getNumRow() << " " << "tbl_Filter_TD_7646483_output: " << tbl_Filter_TD_7646483_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_957562_s, &tv_r_JOIN_INNER_5_957562_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6356181_output: " << tbl_JOIN_INNER_TD_6356181_output.getNumRow() << " " << "tbl_Filter_TD_685002_output: " << tbl_Filter_TD_685002_output.getNumRow() << " " << std::endl; 

    std::cout << "Expand_4: " << tvdiff(&tv_r_Expand_4_807132_s, &tv_r_Expand_4_807132_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5947504_output: " << tbl_JOIN_INNER_TD_5947504_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_691229_s, &tv_r_Aggregate_3_691229_e) / 1000.0 << " ms " 
     << "tbl_Expand_TD_4857594_output: " << tbl_Expand_TD_4857594_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_775467_s, &tv_r_Sort_2_775467_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3494765_output: " << tbl_Aggregate_TD_3494765_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_80066_s, &tv_r_LocalLimit_1_80066_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2827164_output: " << tbl_Sort_TD_2827164_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_315408_s, &tv_r_GlobalLimit_0_315408_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1216500_output: " << tbl_LocalLimit_TD_1216500_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.4744296 * 1000 << "ms" << std::endl; 
    return 0; 
}
