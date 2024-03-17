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

#include "cfgFunc_q38.hpp" 
#include "q38.hpp" 

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
    std::cout << "NOTE:running query #38\n."; 
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
    Table tbl_Aggregate_TD_0404666_output("tbl_Aggregate_TD_0404666_output", 6100000, 1, "");
    tbl_Aggregate_TD_0404666_output.allocateHost();
    Table tbl_Aggregate_TD_143829_output("tbl_Aggregate_TD_143829_output", 6100000, 3, "");
    tbl_Aggregate_TD_143829_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_2717577_output("tbl_JOIN_LEFTSEMI_TD_2717577_output", 6100000, 3, "");
    tbl_JOIN_LEFTSEMI_TD_2717577_output.allocateHost();
    Table tbl_Aggregate_TD_3143065_output("tbl_Aggregate_TD_3143065_output", 6100000, 3, "");
    tbl_Aggregate_TD_3143065_output.allocateHost();
    Table tbl_Aggregate_TD_3175316_output("tbl_Aggregate_TD_3175316_output", 6100000, 3, "");
    tbl_Aggregate_TD_3175316_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_4885373_output("tbl_JOIN_LEFTSEMI_TD_4885373_output", 6100000, 3, "");
    tbl_JOIN_LEFTSEMI_TD_4885373_output.allocateHost();
    Table tbl_JOIN_INNER_TD_419249_output("tbl_JOIN_INNER_TD_419249_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_419249_output.allocateHost();
    Table tbl_Aggregate_TD_5573215_output("tbl_Aggregate_TD_5573215_output", 6100000, 3, "");
    tbl_Aggregate_TD_5573215_output.allocateHost();
    Table tbl_Aggregate_TD_5205078_output("tbl_Aggregate_TD_5205078_output", 6100000, 3, "");
    tbl_Aggregate_TD_5205078_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5872542_output("tbl_JOIN_INNER_TD_5872542_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_5872542_output.allocateHost();
    Table tbl_Filter_TD_5464439_output("tbl_Filter_TD_5464439_output", 6100000, 3, "");
    tbl_Filter_TD_5464439_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6440608_output("tbl_JOIN_INNER_TD_6440608_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_6440608_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6727332_output("tbl_JOIN_INNER_TD_6727332_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_6727332_output.allocateHost();
    Table tbl_Filter_TD_6866543_output("tbl_Filter_TD_6866543_output", 6100000, 2, "");
    tbl_Filter_TD_6866543_output.allocateHost();
    Table tbl_Filter_TD_6169348_output("tbl_Filter_TD_6169348_output", 6100000, 2, "");
    tbl_Filter_TD_6169348_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6491402_input;
    tbl_SerializeFromObject_TD_6491402_input = Table("customer", customer_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_6491402_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_6491402_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6491402_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6491402_input.allocateHost();
    tbl_SerializeFromObject_TD_6491402_input.loadHost();
    Table tbl_JOIN_INNER_TD_7552832_output("tbl_JOIN_INNER_TD_7552832_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_7552832_output.allocateHost();
    Table tbl_Filter_TD_7950101_output("tbl_Filter_TD_7950101_output", 6100000, 3, "");
    tbl_Filter_TD_7950101_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7447635_output("tbl_JOIN_INNER_TD_7447635_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_7447635_output.allocateHost();
    Table tbl_Filter_TD_7225211_output("tbl_Filter_TD_7225211_output", 6100000, 3, "");
    tbl_Filter_TD_7225211_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7312231_input;
    tbl_SerializeFromObject_TD_7312231_input = Table("web_sales", web_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7312231_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_7312231_input.addCol("ws_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_7312231_input.allocateHost();
    tbl_SerializeFromObject_TD_7312231_input.loadHost();
    Table tbl_SerializeFromObject_TD_7373497_input;
    tbl_SerializeFromObject_TD_7373497_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7373497_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_7373497_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_7373497_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_7373497_input.allocateHost();
    tbl_SerializeFromObject_TD_7373497_input.loadHost();
    Table tbl_Filter_TD_8497140_output("tbl_Filter_TD_8497140_output", 6100000, 2, "");
    tbl_Filter_TD_8497140_output.allocateHost();
    Table tbl_Filter_TD_8520215_output("tbl_Filter_TD_8520215_output", 6100000, 2, "");
    tbl_Filter_TD_8520215_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8842322_input;
    tbl_SerializeFromObject_TD_8842322_input = Table("customer", customer_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8842322_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_8842322_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8842322_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8842322_input.allocateHost();
    tbl_SerializeFromObject_TD_8842322_input.loadHost();
    Table tbl_Filter_TD_8529464_output("tbl_Filter_TD_8529464_output", 6100000, 2, "");
    tbl_Filter_TD_8529464_output.allocateHost();
    Table tbl_Filter_TD_8352888_output("tbl_Filter_TD_8352888_output", 6100000, 2, "");
    tbl_Filter_TD_8352888_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8725126_input;
    tbl_SerializeFromObject_TD_8725126_input = Table("customer", customer_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8725126_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_8725126_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8725126_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8725126_input.allocateHost();
    tbl_SerializeFromObject_TD_8725126_input.loadHost();
    Table tbl_SerializeFromObject_TD_9342680_input;
    tbl_SerializeFromObject_TD_9342680_input = Table("store_sales", store_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9342680_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_9342680_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_9342680_input.allocateHost();
    tbl_SerializeFromObject_TD_9342680_input.loadHost();
    Table tbl_SerializeFromObject_TD_9955100_input;
    tbl_SerializeFromObject_TD_9955100_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9955100_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_9955100_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_9955100_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_9955100_input.allocateHost();
    tbl_SerializeFromObject_TD_9955100_input.loadHost();
    Table tbl_SerializeFromObject_TD_99094_input;
    tbl_SerializeFromObject_TD_99094_input = Table("catalog_sales", catalog_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_99094_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_99094_input.addCol("cs_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_99094_input.allocateHost();
    tbl_SerializeFromObject_TD_99094_input.loadHost();
    Table tbl_SerializeFromObject_TD_9277668_input;
    tbl_SerializeFromObject_TD_9277668_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9277668_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_9277668_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_9277668_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_9277668_input.allocateHost();
    tbl_SerializeFromObject_TD_9277668_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_5872542_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_6866543_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_6169348_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_7552832_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_7447635_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8497140_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8520215_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8529464_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8352888_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_5872542_cmds;
    cfg_JOIN_INNER_TD_5872542_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_5872542_gqe_join (cfg_JOIN_INNER_TD_5872542_cmds.cmd);
    cfg_JOIN_INNER_TD_5872542_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7552832_cmds;
    cfg_JOIN_INNER_TD_7552832_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7552832_gqe_join (cfg_JOIN_INNER_TD_7552832_cmds.cmd);
    cfg_JOIN_INNER_TD_7552832_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7447635_cmds;
    cfg_JOIN_INNER_TD_7447635_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7447635_gqe_join (cfg_JOIN_INNER_TD_7447635_cmds.cmd);
    cfg_JOIN_INNER_TD_7447635_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_5872542;
    krnl_JOIN_INNER_TD_5872542 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_5872542.setup(tbl_Filter_TD_6866543_output, tbl_Filter_TD_6169348_output, tbl_JOIN_INNER_TD_5872542_output, cfg_JOIN_INNER_TD_5872542_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_7552832;
    krnl_JOIN_INNER_TD_7552832 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7552832.setup(tbl_Filter_TD_8497140_output, tbl_Filter_TD_8520215_output, tbl_JOIN_INNER_TD_7552832_output, cfg_JOIN_INNER_TD_7552832_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_7447635;
    krnl_JOIN_INNER_TD_7447635 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7447635.setup(tbl_Filter_TD_8529464_output, tbl_Filter_TD_8352888_output, tbl_JOIN_INNER_TD_7447635_output, cfg_JOIN_INNER_TD_7447635_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_5872542;
    trans_JOIN_INNER_TD_5872542.setq(q_h);
    trans_JOIN_INNER_TD_5872542.add(&(cfg_JOIN_INNER_TD_5872542_cmds));
    transEngine trans_JOIN_INNER_TD_5872542_out;
    trans_JOIN_INNER_TD_5872542_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_7552832;
    trans_JOIN_INNER_TD_7552832.setq(q_h);
    trans_JOIN_INNER_TD_7552832.add(&(cfg_JOIN_INNER_TD_7552832_cmds));
    transEngine trans_JOIN_INNER_TD_7552832_out;
    trans_JOIN_INNER_TD_7552832_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_7447635;
    trans_JOIN_INNER_TD_7447635.setq(q_h);
    trans_JOIN_INNER_TD_7447635.add(&(cfg_JOIN_INNER_TD_7447635_cmds));
    transEngine trans_JOIN_INNER_TD_7447635_out;
    trans_JOIN_INNER_TD_7447635_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_5872542;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_5872542;
    std::vector<cl::Event> events_JOIN_INNER_TD_5872542;
    events_h2d_wr_JOIN_INNER_TD_5872542.resize(1);
    events_d2h_rd_JOIN_INNER_TD_5872542.resize(1);
    events_JOIN_INNER_TD_5872542.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_5872542;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_5872542;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7552832;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7552832;
    std::vector<cl::Event> events_JOIN_INNER_TD_7552832;
    events_h2d_wr_JOIN_INNER_TD_7552832.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7552832.resize(1);
    events_JOIN_INNER_TD_7552832.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7552832;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7552832;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7447635;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7447635;
    std::vector<cl::Event> events_JOIN_INNER_TD_7447635;
    events_h2d_wr_JOIN_INNER_TD_7447635.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7447635.resize(1);
    events_JOIN_INNER_TD_7447635.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7447635;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7447635;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_8_802931_s, tv_r_Filter_8_802931_e;
    gettimeofday(&tv_r_Filter_8_802931_s, 0);
    SW_Filter_TD_8352888(tbl_SerializeFromObject_TD_9277668_input, tbl_Filter_TD_8352888_output);
    gettimeofday(&tv_r_Filter_8_802931_e, 0);

    struct timeval tv_r_Filter_8_671568_s, tv_r_Filter_8_671568_e;
    gettimeofday(&tv_r_Filter_8_671568_s, 0);
    SW_Filter_TD_8529464(tbl_SerializeFromObject_TD_99094_input, tbl_Filter_TD_8529464_output);
    gettimeofday(&tv_r_Filter_8_671568_e, 0);

    struct timeval tv_r_Filter_8_386294_s, tv_r_Filter_8_386294_e;
    gettimeofday(&tv_r_Filter_8_386294_s, 0);
    SW_Filter_TD_8520215(tbl_SerializeFromObject_TD_9955100_input, tbl_Filter_TD_8520215_output);
    gettimeofday(&tv_r_Filter_8_386294_e, 0);

    struct timeval tv_r_Filter_8_638079_s, tv_r_Filter_8_638079_e;
    gettimeofday(&tv_r_Filter_8_638079_s, 0);
    SW_Filter_TD_8497140(tbl_SerializeFromObject_TD_9342680_input, tbl_Filter_TD_8497140_output);
    gettimeofday(&tv_r_Filter_8_638079_e, 0);

    struct timeval tv_r_Filter_7_969111_s, tv_r_Filter_7_969111_e;
    gettimeofday(&tv_r_Filter_7_969111_s, 0);
    SW_Filter_TD_7225211(tbl_SerializeFromObject_TD_8725126_input, tbl_Filter_TD_7225211_output);
    gettimeofday(&tv_r_Filter_7_969111_e, 0);

    struct timeval tv_r_JOIN_INNER_7_76332_s, tv_r_JOIN_INNER_7_76332_e;
    gettimeofday(&tv_r_JOIN_INNER_7_76332_s, 0);
    trans_JOIN_INNER_TD_7447635.add(&(tbl_Filter_TD_8529464_output));
    trans_JOIN_INNER_TD_7447635.add(&(tbl_Filter_TD_8352888_output));
    trans_JOIN_INNER_TD_7447635.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7447635), &(events_h2d_wr_JOIN_INNER_TD_7447635[0]));
    events_grp_JOIN_INNER_TD_7447635.push_back(events_h2d_wr_JOIN_INNER_TD_7447635[0]);
    krnl_JOIN_INNER_TD_7447635.run(0, &(events_grp_JOIN_INNER_TD_7447635), &(events_JOIN_INNER_TD_7447635[0]));
    
    trans_JOIN_INNER_TD_7447635_out.add(&(tbl_JOIN_INNER_TD_7447635_output));
    trans_JOIN_INNER_TD_7447635_out.dev2host(0, &(events_JOIN_INNER_TD_7447635), &(events_d2h_rd_JOIN_INNER_TD_7447635[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_7_76332_e, 0);

    struct timeval tv_r_Filter_7_128097_s, tv_r_Filter_7_128097_e;
    gettimeofday(&tv_r_Filter_7_128097_s, 0);
    SW_Filter_TD_7950101(tbl_SerializeFromObject_TD_8842322_input, tbl_Filter_TD_7950101_output);
    gettimeofday(&tv_r_Filter_7_128097_e, 0);

    struct timeval tv_r_JOIN_INNER_7_512086_s, tv_r_JOIN_INNER_7_512086_e;
    gettimeofday(&tv_r_JOIN_INNER_7_512086_s, 0);
    trans_JOIN_INNER_TD_7552832.add(&(tbl_Filter_TD_8497140_output));
    trans_JOIN_INNER_TD_7552832.add(&(tbl_Filter_TD_8520215_output));
    trans_JOIN_INNER_TD_7552832.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7552832), &(events_h2d_wr_JOIN_INNER_TD_7552832[0]));
    events_grp_JOIN_INNER_TD_7552832.push_back(events_h2d_wr_JOIN_INNER_TD_7552832[0]);
    krnl_JOIN_INNER_TD_7552832.run(0, &(events_grp_JOIN_INNER_TD_7552832), &(events_JOIN_INNER_TD_7552832[0]));
    
    trans_JOIN_INNER_TD_7552832_out.add(&(tbl_JOIN_INNER_TD_7552832_output));
    trans_JOIN_INNER_TD_7552832_out.dev2host(0, &(events_JOIN_INNER_TD_7552832), &(events_d2h_rd_JOIN_INNER_TD_7552832[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_7_512086_e, 0);

    struct timeval tv_r_Filter_6_799870_s, tv_r_Filter_6_799870_e;
    gettimeofday(&tv_r_Filter_6_799870_s, 0);
    SW_Filter_TD_6169348(tbl_SerializeFromObject_TD_7373497_input, tbl_Filter_TD_6169348_output);
    gettimeofday(&tv_r_Filter_6_799870_e, 0);

    struct timeval tv_r_Filter_6_573153_s, tv_r_Filter_6_573153_e;
    gettimeofday(&tv_r_Filter_6_573153_s, 0);
    SW_Filter_TD_6866543(tbl_SerializeFromObject_TD_7312231_input, tbl_Filter_TD_6866543_output);
    gettimeofday(&tv_r_Filter_6_573153_e, 0);

    struct timeval tv_r_JOIN_INNER_6_552137_s, tv_r_JOIN_INNER_6_552137_e;
    gettimeofday(&tv_r_JOIN_INNER_6_552137_s, 0);
    SW_JOIN_INNER_TD_6727332(tbl_JOIN_INNER_TD_7447635_output, tbl_Filter_TD_7225211_output, tbl_JOIN_INNER_TD_6727332_output);
    gettimeofday(&tv_r_JOIN_INNER_6_552137_e, 0);

    struct timeval tv_r_JOIN_INNER_6_53360_s, tv_r_JOIN_INNER_6_53360_e;
    gettimeofday(&tv_r_JOIN_INNER_6_53360_s, 0);
    SW_JOIN_INNER_TD_6440608(tbl_JOIN_INNER_TD_7552832_output, tbl_Filter_TD_7950101_output, tbl_JOIN_INNER_TD_6440608_output);
    gettimeofday(&tv_r_JOIN_INNER_6_53360_e, 0);

    struct timeval tv_r_Filter_5_883868_s, tv_r_Filter_5_883868_e;
    gettimeofday(&tv_r_Filter_5_883868_s, 0);
    SW_Filter_TD_5464439(tbl_SerializeFromObject_TD_6491402_input, tbl_Filter_TD_5464439_output);
    gettimeofday(&tv_r_Filter_5_883868_e, 0);

    struct timeval tv_r_JOIN_INNER_5_675214_s, tv_r_JOIN_INNER_5_675214_e;
    gettimeofday(&tv_r_JOIN_INNER_5_675214_s, 0);
    trans_JOIN_INNER_TD_5872542.add(&(tbl_Filter_TD_6866543_output));
    trans_JOIN_INNER_TD_5872542.add(&(tbl_Filter_TD_6169348_output));
    trans_JOIN_INNER_TD_5872542.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_5872542), &(events_h2d_wr_JOIN_INNER_TD_5872542[0]));
    events_grp_JOIN_INNER_TD_5872542.push_back(events_h2d_wr_JOIN_INNER_TD_5872542[0]);
    krnl_JOIN_INNER_TD_5872542.run(0, &(events_grp_JOIN_INNER_TD_5872542), &(events_JOIN_INNER_TD_5872542[0]));
    
    trans_JOIN_INNER_TD_5872542_out.add(&(tbl_JOIN_INNER_TD_5872542_output));
    trans_JOIN_INNER_TD_5872542_out.dev2host(0, &(events_JOIN_INNER_TD_5872542), &(events_d2h_rd_JOIN_INNER_TD_5872542[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_5_675214_e, 0);

    struct timeval tv_r_Aggregate_5_181128_s, tv_r_Aggregate_5_181128_e;
    gettimeofday(&tv_r_Aggregate_5_181128_s, 0);
    SW_Aggregate_TD_5205078(tbl_JOIN_INNER_TD_6727332_output, tbl_Aggregate_TD_5205078_output);
    gettimeofday(&tv_r_Aggregate_5_181128_e, 0);

    struct timeval tv_r_Aggregate_5_67017_s, tv_r_Aggregate_5_67017_e;
    gettimeofday(&tv_r_Aggregate_5_67017_s, 0);
    SW_Aggregate_TD_5573215(tbl_JOIN_INNER_TD_6440608_output, tbl_Aggregate_TD_5573215_output);
    gettimeofday(&tv_r_Aggregate_5_67017_e, 0);

    struct timeval tv_r_JOIN_INNER_4_502155_s, tv_r_JOIN_INNER_4_502155_e;
    gettimeofday(&tv_r_JOIN_INNER_4_502155_s, 0);
    SW_JOIN_INNER_TD_419249(tbl_JOIN_INNER_TD_5872542_output, tbl_Filter_TD_5464439_output, tbl_JOIN_INNER_TD_419249_output);
    gettimeofday(&tv_r_JOIN_INNER_4_502155_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_4_170559_s, tv_r_JOIN_LEFTSEMI_4_170559_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_4_170559_s, 0);
    SW_JOIN_LEFTSEMI_TD_4885373(tbl_Aggregate_TD_5573215_output, tbl_Aggregate_TD_5205078_output, tbl_JOIN_LEFTSEMI_TD_4885373_output);
    gettimeofday(&tv_r_JOIN_LEFTSEMI_4_170559_e, 0);

    struct timeval tv_r_Aggregate_3_528580_s, tv_r_Aggregate_3_528580_e;
    gettimeofday(&tv_r_Aggregate_3_528580_s, 0);
    SW_Aggregate_TD_3175316(tbl_JOIN_INNER_TD_419249_output, tbl_Aggregate_TD_3175316_output);
    gettimeofday(&tv_r_Aggregate_3_528580_e, 0);

    struct timeval tv_r_Aggregate_3_235467_s, tv_r_Aggregate_3_235467_e;
    gettimeofday(&tv_r_Aggregate_3_235467_s, 0);
    SW_Aggregate_TD_3143065(tbl_JOIN_LEFTSEMI_TD_4885373_output, tbl_Aggregate_TD_3143065_output);
    gettimeofday(&tv_r_Aggregate_3_235467_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_2_729824_s, tv_r_JOIN_LEFTSEMI_2_729824_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_2_729824_s, 0);
    SW_JOIN_LEFTSEMI_TD_2717577(tbl_Aggregate_TD_3143065_output, tbl_Aggregate_TD_3175316_output, tbl_JOIN_LEFTSEMI_TD_2717577_output);
    gettimeofday(&tv_r_JOIN_LEFTSEMI_2_729824_e, 0);

    struct timeval tv_r_Aggregate_1_468943_s, tv_r_Aggregate_1_468943_e;
    gettimeofday(&tv_r_Aggregate_1_468943_s, 0);
    SW_Aggregate_TD_143829(tbl_JOIN_LEFTSEMI_TD_2717577_output, tbl_Aggregate_TD_143829_output);
    gettimeofday(&tv_r_Aggregate_1_468943_e, 0);

    struct timeval tv_r_Aggregate_0_146003_s, tv_r_Aggregate_0_146003_e;
    gettimeofday(&tv_r_Aggregate_0_146003_s, 0);
    SW_Aggregate_TD_0404666(tbl_Aggregate_TD_143829_output, tbl_Aggregate_TD_0404666_output);
    gettimeofday(&tv_r_Aggregate_0_146003_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_802931_s, &tv_r_Filter_8_802931_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9277668_input: " << tbl_SerializeFromObject_TD_9277668_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_671568_s, &tv_r_Filter_8_671568_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_99094_input: " << tbl_SerializeFromObject_TD_99094_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_386294_s, &tv_r_Filter_8_386294_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9955100_input: " << tbl_SerializeFromObject_TD_9955100_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_638079_s, &tv_r_Filter_8_638079_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9342680_input: " << tbl_SerializeFromObject_TD_9342680_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_969111_s, &tv_r_Filter_7_969111_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8725126_input: " << tbl_SerializeFromObject_TD_8725126_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_76332_s, &tv_r_JOIN_INNER_7_76332_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8529464_output: " << tbl_Filter_TD_8529464_output.getNumRow() << " " << "tbl_Filter_TD_8352888_output: " << tbl_Filter_TD_8352888_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_128097_s, &tv_r_Filter_7_128097_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8842322_input: " << tbl_SerializeFromObject_TD_8842322_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_512086_s, &tv_r_JOIN_INNER_7_512086_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8497140_output: " << tbl_Filter_TD_8497140_output.getNumRow() << " " << "tbl_Filter_TD_8520215_output: " << tbl_Filter_TD_8520215_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_799870_s, &tv_r_Filter_6_799870_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7373497_input: " << tbl_SerializeFromObject_TD_7373497_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_573153_s, &tv_r_Filter_6_573153_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7312231_input: " << tbl_SerializeFromObject_TD_7312231_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_552137_s, &tv_r_JOIN_INNER_6_552137_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7447635_output: " << tbl_JOIN_INNER_TD_7447635_output.getNumRow() << " " << "tbl_Filter_TD_7225211_output: " << tbl_Filter_TD_7225211_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_53360_s, &tv_r_JOIN_INNER_6_53360_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7552832_output: " << tbl_JOIN_INNER_TD_7552832_output.getNumRow() << " " << "tbl_Filter_TD_7950101_output: " << tbl_Filter_TD_7950101_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_883868_s, &tv_r_Filter_5_883868_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6491402_input: " << tbl_SerializeFromObject_TD_6491402_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_675214_s, &tv_r_JOIN_INNER_5_675214_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6866543_output: " << tbl_Filter_TD_6866543_output.getNumRow() << " " << "tbl_Filter_TD_6169348_output: " << tbl_Filter_TD_6169348_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_181128_s, &tv_r_Aggregate_5_181128_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6727332_output: " << tbl_JOIN_INNER_TD_6727332_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_67017_s, &tv_r_Aggregate_5_67017_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6440608_output: " << tbl_JOIN_INNER_TD_6440608_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_502155_s, &tv_r_JOIN_INNER_4_502155_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5872542_output: " << tbl_JOIN_INNER_TD_5872542_output.getNumRow() << " " << "tbl_Filter_TD_5464439_output: " << tbl_Filter_TD_5464439_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_4: " << tvdiff(&tv_r_JOIN_LEFTSEMI_4_170559_s, &tv_r_JOIN_LEFTSEMI_4_170559_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_5573215_output: " << tbl_Aggregate_TD_5573215_output.getNumRow() << " " << "tbl_Aggregate_TD_5205078_output: " << tbl_Aggregate_TD_5205078_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_528580_s, &tv_r_Aggregate_3_528580_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_419249_output: " << tbl_JOIN_INNER_TD_419249_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_235467_s, &tv_r_Aggregate_3_235467_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTSEMI_TD_4885373_output: " << tbl_JOIN_LEFTSEMI_TD_4885373_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_2: " << tvdiff(&tv_r_JOIN_LEFTSEMI_2_729824_s, &tv_r_JOIN_LEFTSEMI_2_729824_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3143065_output: " << tbl_Aggregate_TD_3143065_output.getNumRow() << " " << "tbl_Aggregate_TD_3175316_output: " << tbl_Aggregate_TD_3175316_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_468943_s, &tv_r_Aggregate_1_468943_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTSEMI_TD_2717577_output: " << tbl_JOIN_LEFTSEMI_TD_2717577_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_0: " << tvdiff(&tv_r_Aggregate_0_146003_s, &tv_r_Aggregate_0_146003_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_143829_output: " << tbl_Aggregate_TD_143829_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.8051927 * 1000 << "ms" << std::endl; 
    return 0; 
}
