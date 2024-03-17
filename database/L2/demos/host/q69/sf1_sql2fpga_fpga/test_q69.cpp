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

#include "cfgFunc_q69.hpp" 
#include "q69.hpp" 

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
    std::cout << "NOTE:running query #69\n."; 
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
    Table tbl_GlobalLimit_TD_0239138_output("tbl_GlobalLimit_TD_0239138_output", 6100000, 8, "");
    tbl_GlobalLimit_TD_0239138_output.allocateHost();
    Table tbl_LocalLimit_TD_1636925_output("tbl_LocalLimit_TD_1636925_output", 6100000, 8, "");
    tbl_LocalLimit_TD_1636925_output.allocateHost();
    Table tbl_Sort_TD_210950_output("tbl_Sort_TD_210950_output", 6100000, 8, "");
    tbl_Sort_TD_210950_output.allocateHost();
    Table tbl_Aggregate_TD_3194621_output("tbl_Aggregate_TD_3194621_output", 6100000, 8, "");
    tbl_Aggregate_TD_3194621_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4103900_output("tbl_JOIN_INNER_TD_4103900_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_4103900_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5163540_output("tbl_JOIN_INNER_TD_5163540_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_5163540_output.allocateHost();
    Table tbl_Filter_TD_5392010_output("tbl_Filter_TD_5392010_output", 6100000, 6, "");
    tbl_Filter_TD_5392010_output.allocateHost();
    Table tbl_JOIN_LEFTANTI_TD_6565911_output("tbl_JOIN_LEFTANTI_TD_6565911_output", 6100000, 2, "");
    tbl_JOIN_LEFTANTI_TD_6565911_output.allocateHost();
    Table tbl_Filter_TD_6774424_output("tbl_Filter_TD_6774424_output", 6100000, 1, "");
    tbl_Filter_TD_6774424_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6681835_input;
    tbl_SerializeFromObject_TD_6681835_input = Table("customer_demographics", customer_demographics_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_6681835_input.addCol("cd_demo_sk", 4);
    tbl_SerializeFromObject_TD_6681835_input.addCol("cd_gender", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6681835_input.addCol("cd_marital_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6681835_input.addCol("cd_education_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6681835_input.addCol("cd_purchase_estimate", 4);
    tbl_SerializeFromObject_TD_6681835_input.addCol("cd_credit_rating", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6681835_input.allocateHost();
    tbl_SerializeFromObject_TD_6681835_input.loadHost();
    Table tbl_JOIN_LEFTANTI_TD_769216_output("tbl_JOIN_LEFTANTI_TD_769216_output", 6100000, 3, "");
    tbl_JOIN_LEFTANTI_TD_769216_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7493365_output("tbl_JOIN_INNER_TD_7493365_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_7493365_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7871697_input;
    tbl_SerializeFromObject_TD_7871697_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7871697_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_7871697_input.addCol("ca_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7871697_input.allocateHost();
    tbl_SerializeFromObject_TD_7871697_input.loadHost();
    Table tbl_JOIN_LEFTSEMI_TD_880618_output("tbl_JOIN_LEFTSEMI_TD_880618_output", 6100000, 3, "");
    tbl_JOIN_LEFTSEMI_TD_880618_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8459874_output("tbl_JOIN_INNER_TD_8459874_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_8459874_output.allocateHost();
    Table tbl_Filter_TD_8877333_output("tbl_Filter_TD_8877333_output", 6100000, 2, "");
    tbl_Filter_TD_8877333_output.allocateHost();
    Table tbl_Filter_TD_8385324_output("tbl_Filter_TD_8385324_output", 6100000, 1, "");
    tbl_Filter_TD_8385324_output.allocateHost();
    Table tbl_Filter_TD_9875328_output("tbl_Filter_TD_9875328_output", 6100000, 3, "");
    tbl_Filter_TD_9875328_output.allocateHost();
    Table tbl_JOIN_INNER_TD_9685683_output("tbl_JOIN_INNER_TD_9685683_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_9685683_output.allocateHost();
    Table tbl_Filter_TD_982088_output("tbl_Filter_TD_982088_output", 6100000, 2, "");
    tbl_Filter_TD_982088_output.allocateHost();
    Table tbl_Filter_TD_9364528_output("tbl_Filter_TD_9364528_output", 6100000, 1, "");
    tbl_Filter_TD_9364528_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9446430_input;
    tbl_SerializeFromObject_TD_9446430_input = Table("catalog_sales", catalog_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9446430_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_9446430_input.addCol("cs_ship_customer_sk", 4);
    tbl_SerializeFromObject_TD_9446430_input.allocateHost();
    tbl_SerializeFromObject_TD_9446430_input.loadHost();
    Table tbl_SerializeFromObject_TD_9412864_input;
    tbl_SerializeFromObject_TD_9412864_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9412864_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_9412864_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_9412864_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_9412864_input.allocateHost();
    tbl_SerializeFromObject_TD_9412864_input.loadHost();
    Table tbl_SerializeFromObject_TD_10692572_input;
    tbl_SerializeFromObject_TD_10692572_input = Table("customer", customer_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10692572_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_10692572_input.addCol("c_current_cdemo_sk", 4);
    tbl_SerializeFromObject_TD_10692572_input.addCol("c_current_addr_sk", 4);
    tbl_SerializeFromObject_TD_10692572_input.allocateHost();
    tbl_SerializeFromObject_TD_10692572_input.loadHost();
    Table tbl_Filter_TD_10902294_output("tbl_Filter_TD_10902294_output", 6100000, 2, "");
    tbl_Filter_TD_10902294_output.allocateHost();
    Table tbl_Filter_TD_10489898_output("tbl_Filter_TD_10489898_output", 6100000, 1, "");
    tbl_Filter_TD_10489898_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10337341_input;
    tbl_SerializeFromObject_TD_10337341_input = Table("web_sales", web_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10337341_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10337341_input.addCol("ws_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_10337341_input.allocateHost();
    tbl_SerializeFromObject_TD_10337341_input.loadHost();
    Table tbl_SerializeFromObject_TD_10490214_input;
    tbl_SerializeFromObject_TD_10490214_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10490214_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10490214_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10490214_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_10490214_input.allocateHost();
    tbl_SerializeFromObject_TD_10490214_input.loadHost();
    Table tbl_SerializeFromObject_TD_11655553_input;
    tbl_SerializeFromObject_TD_11655553_input = Table("store_sales", store_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11655553_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_11655553_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_11655553_input.allocateHost();
    tbl_SerializeFromObject_TD_11655553_input.loadHost();
    Table tbl_SerializeFromObject_TD_11725638_input;
    tbl_SerializeFromObject_TD_11725638_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11725638_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_11725638_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_11725638_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_11725638_input.allocateHost();
    tbl_SerializeFromObject_TD_11725638_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_5163540_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTANTI_TD_6565911_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_6774424_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTANTI_TD_769216_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_7493365_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTSEMI_TD_880618_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8459874_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8877333_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8385324_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9875328_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_9685683_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_982088_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9364528_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10902294_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10489898_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_5163540_cmds;
    cfg_JOIN_INNER_TD_5163540_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_5163540_gqe_join (cfg_JOIN_INNER_TD_5163540_cmds.cmd);
    cfg_JOIN_INNER_TD_5163540_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTANTI_TD_6565911_cmds;
    cfg_JOIN_LEFTANTI_TD_6565911_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTANTI_TD_6565911_gqe_join (cfg_JOIN_LEFTANTI_TD_6565911_cmds.cmd);
    cfg_JOIN_LEFTANTI_TD_6565911_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTANTI_TD_769216_cmds;
    cfg_JOIN_LEFTANTI_TD_769216_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTANTI_TD_769216_gqe_join (cfg_JOIN_LEFTANTI_TD_769216_cmds.cmd);
    cfg_JOIN_LEFTANTI_TD_769216_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7493365_cmds;
    cfg_JOIN_INNER_TD_7493365_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7493365_gqe_join (cfg_JOIN_INNER_TD_7493365_cmds.cmd);
    cfg_JOIN_INNER_TD_7493365_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_880618_cmds;
    cfg_JOIN_LEFTSEMI_TD_880618_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_880618_gqe_join (cfg_JOIN_LEFTSEMI_TD_880618_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_880618_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8459874_cmds;
    cfg_JOIN_INNER_TD_8459874_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8459874_gqe_join (cfg_JOIN_INNER_TD_8459874_cmds.cmd);
    cfg_JOIN_INNER_TD_8459874_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_9685683_cmds;
    cfg_JOIN_INNER_TD_9685683_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_9685683_gqe_join (cfg_JOIN_INNER_TD_9685683_cmds.cmd);
    cfg_JOIN_INNER_TD_9685683_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_5163540;
    krnl_JOIN_INNER_TD_5163540 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_5163540.setup(tbl_JOIN_LEFTANTI_TD_6565911_output, tbl_Filter_TD_6774424_output, tbl_JOIN_INNER_TD_5163540_output, cfg_JOIN_INNER_TD_5163540_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTANTI_TD_6565911;
    krnl_JOIN_LEFTANTI_TD_6565911 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTANTI_TD_6565911.setup(tbl_JOIN_INNER_TD_7493365_output, tbl_JOIN_LEFTANTI_TD_769216_output, tbl_JOIN_LEFTANTI_TD_6565911_output, cfg_JOIN_LEFTANTI_TD_6565911_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTANTI_TD_769216;
    krnl_JOIN_LEFTANTI_TD_769216 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTANTI_TD_769216.setup(tbl_JOIN_INNER_TD_8459874_output, tbl_JOIN_LEFTSEMI_TD_880618_output, tbl_JOIN_LEFTANTI_TD_769216_output, cfg_JOIN_LEFTANTI_TD_769216_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_7493365;
    krnl_JOIN_INNER_TD_7493365 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7493365.setup(tbl_Filter_TD_8877333_output, tbl_Filter_TD_8385324_output, tbl_JOIN_INNER_TD_7493365_output, cfg_JOIN_INNER_TD_7493365_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_880618;
    krnl_JOIN_LEFTSEMI_TD_880618 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTSEMI_TD_880618.setup(tbl_JOIN_INNER_TD_9685683_output, tbl_Filter_TD_9875328_output, tbl_JOIN_LEFTSEMI_TD_880618_output, cfg_JOIN_LEFTSEMI_TD_880618_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_8459874;
    krnl_JOIN_INNER_TD_8459874 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8459874.setup(tbl_Filter_TD_982088_output, tbl_Filter_TD_9364528_output, tbl_JOIN_INNER_TD_8459874_output, cfg_JOIN_INNER_TD_8459874_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_9685683;
    krnl_JOIN_INNER_TD_9685683 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_9685683.setup(tbl_Filter_TD_10902294_output, tbl_Filter_TD_10489898_output, tbl_JOIN_INNER_TD_9685683_output, cfg_JOIN_INNER_TD_9685683_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_5163540;
    trans_JOIN_INNER_TD_5163540.setq(q_h);
    trans_JOIN_INNER_TD_5163540.add(&(cfg_JOIN_INNER_TD_5163540_cmds));
    transEngine trans_JOIN_INNER_TD_5163540_out;
    trans_JOIN_INNER_TD_5163540_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_LEFTANTI_TD_6565911;
    trans_JOIN_LEFTANTI_TD_6565911.setq(q_h);
    trans_JOIN_LEFTANTI_TD_6565911.add(&(cfg_JOIN_LEFTANTI_TD_6565911_cmds));
    q_h.finish();
    transEngine trans_JOIN_LEFTANTI_TD_769216;
    trans_JOIN_LEFTANTI_TD_769216.setq(q_h);
    trans_JOIN_LEFTANTI_TD_769216.add(&(cfg_JOIN_LEFTANTI_TD_769216_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_7493365;
    trans_JOIN_INNER_TD_7493365.setq(q_h);
    trans_JOIN_INNER_TD_7493365.add(&(cfg_JOIN_INNER_TD_7493365_cmds));
    q_h.finish();
    transEngine trans_JOIN_LEFTSEMI_TD_880618;
    trans_JOIN_LEFTSEMI_TD_880618.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_880618.add(&(cfg_JOIN_LEFTSEMI_TD_880618_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_8459874;
    trans_JOIN_INNER_TD_8459874.setq(q_h);
    trans_JOIN_INNER_TD_8459874.add(&(cfg_JOIN_INNER_TD_8459874_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_9685683;
    trans_JOIN_INNER_TD_9685683.setq(q_h);
    trans_JOIN_INNER_TD_9685683.add(&(cfg_JOIN_INNER_TD_9685683_cmds));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_5163540;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_5163540;
    std::vector<cl::Event> events_JOIN_INNER_TD_5163540;
    events_h2d_wr_JOIN_INNER_TD_5163540.resize(1);
    events_d2h_rd_JOIN_INNER_TD_5163540.resize(1);
    events_JOIN_INNER_TD_5163540.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_5163540;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_5163540;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTANTI_TD_6565911;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTANTI_TD_6565911;
    std::vector<cl::Event> events_JOIN_LEFTANTI_TD_6565911;
    events_h2d_wr_JOIN_LEFTANTI_TD_6565911.resize(1);
    events_d2h_rd_JOIN_LEFTANTI_TD_6565911.resize(1);
    events_JOIN_LEFTANTI_TD_6565911.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTANTI_TD_6565911;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTANTI_TD_6565911;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTANTI_TD_769216;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTANTI_TD_769216;
    std::vector<cl::Event> events_JOIN_LEFTANTI_TD_769216;
    events_h2d_wr_JOIN_LEFTANTI_TD_769216.resize(1);
    events_d2h_rd_JOIN_LEFTANTI_TD_769216.resize(1);
    events_JOIN_LEFTANTI_TD_769216.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTANTI_TD_769216;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTANTI_TD_769216;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7493365;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7493365;
    std::vector<cl::Event> events_JOIN_INNER_TD_7493365;
    events_h2d_wr_JOIN_INNER_TD_7493365.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7493365.resize(1);
    events_JOIN_INNER_TD_7493365.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7493365;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7493365;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_880618;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_880618;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_880618;
    events_h2d_wr_JOIN_LEFTSEMI_TD_880618.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_880618.resize(1);
    events_JOIN_LEFTSEMI_TD_880618.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_880618;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_880618;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8459874;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8459874;
    std::vector<cl::Event> events_JOIN_INNER_TD_8459874;
    events_h2d_wr_JOIN_INNER_TD_8459874.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8459874.resize(1);
    events_JOIN_INNER_TD_8459874.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8459874;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8459874;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_9685683;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_9685683;
    std::vector<cl::Event> events_JOIN_INNER_TD_9685683;
    events_h2d_wr_JOIN_INNER_TD_9685683.resize(1);
    events_d2h_rd_JOIN_INNER_TD_9685683.resize(1);
    events_JOIN_INNER_TD_9685683.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_9685683;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_9685683;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_10_542505_s, tv_r_Filter_10_542505_e;
    gettimeofday(&tv_r_Filter_10_542505_s, 0);
    SW_Filter_TD_10489898(tbl_SerializeFromObject_TD_11725638_input, tbl_Filter_TD_10489898_output);
    gettimeofday(&tv_r_Filter_10_542505_e, 0);

    struct timeval tv_r_Filter_10_638186_s, tv_r_Filter_10_638186_e;
    gettimeofday(&tv_r_Filter_10_638186_s, 0);
    SW_Filter_TD_10902294(tbl_SerializeFromObject_TD_11655553_input, tbl_Filter_TD_10902294_output);
    gettimeofday(&tv_r_Filter_10_638186_e, 0);

    struct timeval tv_r_Filter_9_567141_s, tv_r_Filter_9_567141_e;
    gettimeofday(&tv_r_Filter_9_567141_s, 0);
    SW_Filter_TD_9364528(tbl_SerializeFromObject_TD_10490214_input, tbl_Filter_TD_9364528_output);
    gettimeofday(&tv_r_Filter_9_567141_e, 0);

    struct timeval tv_r_Filter_9_790855_s, tv_r_Filter_9_790855_e;
    gettimeofday(&tv_r_Filter_9_790855_s, 0);
    SW_Filter_TD_982088(tbl_SerializeFromObject_TD_10337341_input, tbl_Filter_TD_982088_output);
    gettimeofday(&tv_r_Filter_9_790855_e, 0);

    struct timeval tv_r_JOIN_INNER_9_983942_s, tv_r_JOIN_INNER_9_983942_e;
    gettimeofday(&tv_r_JOIN_INNER_9_983942_s, 0);
    trans_JOIN_INNER_TD_9685683.add(&(tbl_Filter_TD_10902294_output));
    trans_JOIN_INNER_TD_9685683.add(&(tbl_Filter_TD_10489898_output));
    trans_JOIN_INNER_TD_9685683.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_9685683), &(events_h2d_wr_JOIN_INNER_TD_9685683[0]));
    events_grp_JOIN_INNER_TD_9685683.push_back(events_h2d_wr_JOIN_INNER_TD_9685683[0]);
    krnl_JOIN_INNER_TD_9685683.run(0, &(events_grp_JOIN_INNER_TD_9685683), &(events_JOIN_INNER_TD_9685683[0]));
    gettimeofday(&tv_r_JOIN_INNER_9_983942_e, 0);

    struct timeval tv_r_Filter_9_502777_s, tv_r_Filter_9_502777_e;
    gettimeofday(&tv_r_Filter_9_502777_s, 0);
    SW_Filter_TD_9875328(tbl_SerializeFromObject_TD_10692572_input, tbl_Filter_TD_9875328_output);
    gettimeofday(&tv_r_Filter_9_502777_e, 0);

    struct timeval tv_r_Filter_8_777655_s, tv_r_Filter_8_777655_e;
    gettimeofday(&tv_r_Filter_8_777655_s, 0);
    SW_Filter_TD_8385324(tbl_SerializeFromObject_TD_9412864_input, tbl_Filter_TD_8385324_output);
    gettimeofday(&tv_r_Filter_8_777655_e, 0);

    struct timeval tv_r_Filter_8_733408_s, tv_r_Filter_8_733408_e;
    gettimeofday(&tv_r_Filter_8_733408_s, 0);
    SW_Filter_TD_8877333(tbl_SerializeFromObject_TD_9446430_input, tbl_Filter_TD_8877333_output);
    gettimeofday(&tv_r_Filter_8_733408_e, 0);

    struct timeval tv_r_JOIN_INNER_8_519210_s, tv_r_JOIN_INNER_8_519210_e;
    gettimeofday(&tv_r_JOIN_INNER_8_519210_s, 0);
    trans_JOIN_INNER_TD_8459874.add(&(tbl_Filter_TD_982088_output));
    trans_JOIN_INNER_TD_8459874.add(&(tbl_Filter_TD_9364528_output));
    trans_JOIN_INNER_TD_8459874.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8459874), &(events_h2d_wr_JOIN_INNER_TD_8459874[0]));
    events_grp_JOIN_INNER_TD_8459874.push_back(events_h2d_wr_JOIN_INNER_TD_8459874[0]);
    krnl_JOIN_INNER_TD_8459874.run(0, &(events_grp_JOIN_INNER_TD_8459874), &(events_JOIN_INNER_TD_8459874[0]));
    gettimeofday(&tv_r_JOIN_INNER_8_519210_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_8_461142_s, tv_r_JOIN_LEFTSEMI_8_461142_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_8_461142_s, 0);
    prev_events_grp_JOIN_LEFTSEMI_TD_880618.push_back(events_h2d_wr_JOIN_INNER_TD_9685683[0]);
    trans_JOIN_LEFTSEMI_TD_880618.add(&(tbl_Filter_TD_9875328_output));
    trans_JOIN_LEFTSEMI_TD_880618.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_880618), &(events_h2d_wr_JOIN_LEFTSEMI_TD_880618[0]));
    events_grp_JOIN_LEFTSEMI_TD_880618.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_880618[0]);
    events_grp_JOIN_LEFTSEMI_TD_880618.push_back(events_JOIN_INNER_TD_9685683[0]);
    krnl_JOIN_LEFTSEMI_TD_880618.run(0, &(events_grp_JOIN_LEFTSEMI_TD_880618), &(events_JOIN_LEFTSEMI_TD_880618[0]));
    gettimeofday(&tv_r_JOIN_LEFTSEMI_8_461142_e, 0);

    struct timeval tv_r_JOIN_INNER_7_102081_s, tv_r_JOIN_INNER_7_102081_e;
    gettimeofday(&tv_r_JOIN_INNER_7_102081_s, 0);
    trans_JOIN_INNER_TD_7493365.add(&(tbl_Filter_TD_8877333_output));
    trans_JOIN_INNER_TD_7493365.add(&(tbl_Filter_TD_8385324_output));
    trans_JOIN_INNER_TD_7493365.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7493365), &(events_h2d_wr_JOIN_INNER_TD_7493365[0]));
    events_grp_JOIN_INNER_TD_7493365.push_back(events_h2d_wr_JOIN_INNER_TD_7493365[0]);
    krnl_JOIN_INNER_TD_7493365.run(0, &(events_grp_JOIN_INNER_TD_7493365), &(events_JOIN_INNER_TD_7493365[0]));
    gettimeofday(&tv_r_JOIN_INNER_7_102081_e, 0);

    struct timeval tv_r_JOIN_LEFTANTI_7_145177_s, tv_r_JOIN_LEFTANTI_7_145177_e;
    gettimeofday(&tv_r_JOIN_LEFTANTI_7_145177_s, 0);
    prev_events_grp_JOIN_LEFTANTI_TD_769216.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_880618[0]);
    prev_events_grp_JOIN_LEFTANTI_TD_769216.push_back(events_h2d_wr_JOIN_INNER_TD_8459874[0]);
    trans_JOIN_LEFTANTI_TD_769216.host2dev(0, &(prev_events_grp_JOIN_LEFTANTI_TD_769216), &(events_h2d_wr_JOIN_LEFTANTI_TD_769216[0]));
    events_grp_JOIN_LEFTANTI_TD_769216.push_back(events_h2d_wr_JOIN_LEFTANTI_TD_769216[0]);
    events_grp_JOIN_LEFTANTI_TD_769216.push_back(events_JOIN_LEFTSEMI_TD_880618[0]);
    events_grp_JOIN_LEFTANTI_TD_769216.push_back(events_JOIN_INNER_TD_8459874[0]);
    krnl_JOIN_LEFTANTI_TD_769216.run(0, &(events_grp_JOIN_LEFTANTI_TD_769216), &(events_JOIN_LEFTANTI_TD_769216[0]));
    gettimeofday(&tv_r_JOIN_LEFTANTI_7_145177_e, 0);

    struct timeval tv_r_Filter_6_333704_s, tv_r_Filter_6_333704_e;
    gettimeofday(&tv_r_Filter_6_333704_s, 0);
    SW_Filter_TD_6774424(tbl_SerializeFromObject_TD_7871697_input, tbl_Filter_TD_6774424_output);
    gettimeofday(&tv_r_Filter_6_333704_e, 0);

    struct timeval tv_r_JOIN_LEFTANTI_6_939505_s, tv_r_JOIN_LEFTANTI_6_939505_e;
    gettimeofday(&tv_r_JOIN_LEFTANTI_6_939505_s, 0);
    prev_events_grp_JOIN_LEFTANTI_TD_6565911.push_back(events_h2d_wr_JOIN_LEFTANTI_TD_769216[0]);
    prev_events_grp_JOIN_LEFTANTI_TD_6565911.push_back(events_h2d_wr_JOIN_INNER_TD_7493365[0]);
    trans_JOIN_LEFTANTI_TD_6565911.host2dev(0, &(prev_events_grp_JOIN_LEFTANTI_TD_6565911), &(events_h2d_wr_JOIN_LEFTANTI_TD_6565911[0]));
    events_grp_JOIN_LEFTANTI_TD_6565911.push_back(events_h2d_wr_JOIN_LEFTANTI_TD_6565911[0]);
    events_grp_JOIN_LEFTANTI_TD_6565911.push_back(events_JOIN_LEFTANTI_TD_769216[0]);
    events_grp_JOIN_LEFTANTI_TD_6565911.push_back(events_JOIN_INNER_TD_7493365[0]);
    krnl_JOIN_LEFTANTI_TD_6565911.run(0, &(events_grp_JOIN_LEFTANTI_TD_6565911), &(events_JOIN_LEFTANTI_TD_6565911[0]));
    gettimeofday(&tv_r_JOIN_LEFTANTI_6_939505_e, 0);

    struct timeval tv_r_Filter_5_991476_s, tv_r_Filter_5_991476_e;
    gettimeofday(&tv_r_Filter_5_991476_s, 0);
    SW_Filter_TD_5392010(tbl_SerializeFromObject_TD_6681835_input, tbl_Filter_TD_5392010_output);
    gettimeofday(&tv_r_Filter_5_991476_e, 0);

    struct timeval tv_r_JOIN_INNER_5_116042_s, tv_r_JOIN_INNER_5_116042_e;
    gettimeofday(&tv_r_JOIN_INNER_5_116042_s, 0);
    prev_events_grp_JOIN_INNER_TD_5163540.push_back(events_h2d_wr_JOIN_LEFTANTI_TD_6565911[0]);
    trans_JOIN_INNER_TD_5163540.add(&(tbl_Filter_TD_6774424_output));
    trans_JOIN_INNER_TD_5163540.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_5163540), &(events_h2d_wr_JOIN_INNER_TD_5163540[0]));
    events_grp_JOIN_INNER_TD_5163540.push_back(events_h2d_wr_JOIN_INNER_TD_5163540[0]);
    events_grp_JOIN_INNER_TD_5163540.push_back(events_JOIN_LEFTANTI_TD_6565911[0]);
    krnl_JOIN_INNER_TD_5163540.run(0, &(events_grp_JOIN_INNER_TD_5163540), &(events_JOIN_INNER_TD_5163540[0]));
    
    trans_JOIN_INNER_TD_5163540_out.add(&(tbl_JOIN_INNER_TD_5163540_output));
    trans_JOIN_INNER_TD_5163540_out.dev2host(0, &(events_JOIN_INNER_TD_5163540), &(events_d2h_rd_JOIN_INNER_TD_5163540[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_5_116042_e, 0);

    struct timeval tv_r_JOIN_INNER_4_631101_s, tv_r_JOIN_INNER_4_631101_e;
    gettimeofday(&tv_r_JOIN_INNER_4_631101_s, 0);
    SW_JOIN_INNER_TD_4103900(tbl_JOIN_INNER_TD_5163540_output, tbl_Filter_TD_5392010_output, tbl_JOIN_INNER_TD_4103900_output);
    gettimeofday(&tv_r_JOIN_INNER_4_631101_e, 0);

    struct timeval tv_r_Aggregate_3_931761_s, tv_r_Aggregate_3_931761_e;
    gettimeofday(&tv_r_Aggregate_3_931761_s, 0);
    SW_Aggregate_TD_3194621(tbl_JOIN_INNER_TD_4103900_output, tbl_Aggregate_TD_3194621_output);
    gettimeofday(&tv_r_Aggregate_3_931761_e, 0);

    struct timeval tv_r_Sort_2_468290_s, tv_r_Sort_2_468290_e;
    gettimeofday(&tv_r_Sort_2_468290_s, 0);
    SW_Sort_TD_210950(tbl_Aggregate_TD_3194621_output, tbl_Sort_TD_210950_output);
    gettimeofday(&tv_r_Sort_2_468290_e, 0);

    struct timeval tv_r_LocalLimit_1_641777_s, tv_r_LocalLimit_1_641777_e;
    gettimeofday(&tv_r_LocalLimit_1_641777_s, 0);
    SW_LocalLimit_TD_1636925(tbl_Sort_TD_210950_output, tbl_LocalLimit_TD_1636925_output);
    gettimeofday(&tv_r_LocalLimit_1_641777_e, 0);

    struct timeval tv_r_GlobalLimit_0_542474_s, tv_r_GlobalLimit_0_542474_e;
    gettimeofday(&tv_r_GlobalLimit_0_542474_s, 0);
    SW_GlobalLimit_TD_0239138(tbl_LocalLimit_TD_1636925_output, tbl_GlobalLimit_TD_0239138_output);
    gettimeofday(&tv_r_GlobalLimit_0_542474_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_542505_s, &tv_r_Filter_10_542505_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11725638_input: " << tbl_SerializeFromObject_TD_11725638_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_638186_s, &tv_r_Filter_10_638186_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11655553_input: " << tbl_SerializeFromObject_TD_11655553_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_567141_s, &tv_r_Filter_9_567141_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10490214_input: " << tbl_SerializeFromObject_TD_10490214_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_790855_s, &tv_r_Filter_9_790855_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10337341_input: " << tbl_SerializeFromObject_TD_10337341_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_983942_s, &tv_r_JOIN_INNER_9_983942_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10902294_output: " << tbl_Filter_TD_10902294_output.getNumRow() << " " << "tbl_Filter_TD_10489898_output: " << tbl_Filter_TD_10489898_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_502777_s, &tv_r_Filter_9_502777_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10692572_input: " << tbl_SerializeFromObject_TD_10692572_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_777655_s, &tv_r_Filter_8_777655_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9412864_input: " << tbl_SerializeFromObject_TD_9412864_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_733408_s, &tv_r_Filter_8_733408_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9446430_input: " << tbl_SerializeFromObject_TD_9446430_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_519210_s, &tv_r_JOIN_INNER_8_519210_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_982088_output: " << tbl_Filter_TD_982088_output.getNumRow() << " " << "tbl_Filter_TD_9364528_output: " << tbl_Filter_TD_9364528_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_8: " << tvdiff(&tv_r_JOIN_LEFTSEMI_8_461142_s, &tv_r_JOIN_LEFTSEMI_8_461142_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9875328_output: " << tbl_Filter_TD_9875328_output.getNumRow() << " " << "tbl_JOIN_INNER_TD_9685683_output: " << tbl_JOIN_INNER_TD_9685683_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_102081_s, &tv_r_JOIN_INNER_7_102081_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8877333_output: " << tbl_Filter_TD_8877333_output.getNumRow() << " " << "tbl_Filter_TD_8385324_output: " << tbl_Filter_TD_8385324_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTANTI_7: " << tvdiff(&tv_r_JOIN_LEFTANTI_7_145177_s, &tv_r_JOIN_LEFTANTI_7_145177_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTSEMI_TD_880618_output: " << tbl_JOIN_LEFTSEMI_TD_880618_output.getNumRow() << " " << "tbl_JOIN_INNER_TD_8459874_output: " << tbl_JOIN_INNER_TD_8459874_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_333704_s, &tv_r_Filter_6_333704_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7871697_input: " << tbl_SerializeFromObject_TD_7871697_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTANTI_6: " << tvdiff(&tv_r_JOIN_LEFTANTI_6_939505_s, &tv_r_JOIN_LEFTANTI_6_939505_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTANTI_TD_769216_output: " << tbl_JOIN_LEFTANTI_TD_769216_output.getNumRow() << " " << "tbl_JOIN_INNER_TD_7493365_output: " << tbl_JOIN_INNER_TD_7493365_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_991476_s, &tv_r_Filter_5_991476_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6681835_input: " << tbl_SerializeFromObject_TD_6681835_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_116042_s, &tv_r_JOIN_INNER_5_116042_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTANTI_TD_6565911_output: " << tbl_JOIN_LEFTANTI_TD_6565911_output.getNumRow() << " " << "tbl_Filter_TD_6774424_output: " << tbl_Filter_TD_6774424_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_631101_s, &tv_r_JOIN_INNER_4_631101_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5163540_output: " << tbl_JOIN_INNER_TD_5163540_output.getNumRow() << " " << "tbl_Filter_TD_5392010_output: " << tbl_Filter_TD_5392010_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_931761_s, &tv_r_Aggregate_3_931761_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4103900_output: " << tbl_JOIN_INNER_TD_4103900_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_468290_s, &tv_r_Sort_2_468290_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3194621_output: " << tbl_Aggregate_TD_3194621_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_641777_s, &tv_r_LocalLimit_1_641777_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_210950_output: " << tbl_Sort_TD_210950_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_542474_s, &tv_r_GlobalLimit_0_542474_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1636925_output: " << tbl_LocalLimit_TD_1636925_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 3.680641 * 1000 << "ms" << std::endl; 
    return 0; 
}
