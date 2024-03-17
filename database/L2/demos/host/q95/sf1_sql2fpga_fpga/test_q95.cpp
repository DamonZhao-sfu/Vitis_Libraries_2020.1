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

#include "cfgFunc_q95.hpp" 
#include "q95.hpp" 

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
    std::cout << "NOTE:running query #95\n."; 
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
    Table tbl_Aggregate_TD_0758830_output("tbl_Aggregate_TD_0758830_output", 6100000, 3, "");
    tbl_Aggregate_TD_0758830_output.allocateHost();
    Table tbl_JOIN_INNER_TD_1787047_output("tbl_JOIN_INNER_TD_1787047_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_1787047_output.allocateHost();
    Table tbl_JOIN_INNER_TD_2754169_output("tbl_JOIN_INNER_TD_2754169_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_2754169_output.allocateHost();
    Table tbl_Filter_TD_2161704_output("tbl_Filter_TD_2161704_output", 6100000, 1, "");
    tbl_Filter_TD_2161704_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3440127_output("tbl_JOIN_INNER_TD_3440127_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_3440127_output.allocateHost();
    Table tbl_Filter_TD_3190998_output("tbl_Filter_TD_3190998_output", 6100000, 1, "");
    tbl_Filter_TD_3190998_output.allocateHost();
    Table tbl_SerializeFromObject_TD_3225711_input;
    tbl_SerializeFromObject_TD_3225711_input = Table("web_site", web_site_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_3225711_input.addCol("web_site_sk", 4);
    tbl_SerializeFromObject_TD_3225711_input.addCol("web_company_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_3225711_input.allocateHost();
    tbl_SerializeFromObject_TD_3225711_input.loadHost();
    Table tbl_JOIN_LEFTSEMI_TD_4697125_output("tbl_JOIN_LEFTSEMI_TD_4697125_output", 6100000, 6, "");
    tbl_JOIN_LEFTSEMI_TD_4697125_output.allocateHost();
    Table tbl_Filter_TD_4929431_output("tbl_Filter_TD_4929431_output", 6100000, 1, "");
    tbl_Filter_TD_4929431_output.allocateHost();
    Table tbl_SerializeFromObject_TD_455743_input;
    tbl_SerializeFromObject_TD_455743_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_455743_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_455743_input.addCol("ca_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_455743_input.allocateHost();
    tbl_SerializeFromObject_TD_455743_input.loadHost();
    Table tbl_JOIN_LEFTSEMI_TD_552916_output("tbl_JOIN_LEFTSEMI_TD_552916_output", 6100000, 6, "");
    tbl_JOIN_LEFTSEMI_TD_552916_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5255352_output("tbl_JOIN_INNER_TD_5255352_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_5255352_output.allocateHost();
    Table tbl_SerializeFromObject_TD_5992253_input;
    tbl_SerializeFromObject_TD_5992253_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_5992253_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_5992253_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_5992253_input.allocateHost();
    tbl_SerializeFromObject_TD_5992253_input.loadHost();
    Table tbl_Filter_TD_637367_output("tbl_Filter_TD_637367_output", 6100000, 6, "");
    tbl_Filter_TD_637367_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6724276_output("tbl_JOIN_INNER_TD_6724276_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_6724276_output.allocateHost();
    Table tbl_Filter_TD_6644598_output("tbl_Filter_TD_6644598_output", 6100000, 1, "");
    tbl_Filter_TD_6644598_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6127464_output("tbl_JOIN_INNER_TD_6127464_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_6127464_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7979578_input;
    tbl_SerializeFromObject_TD_7979578_input = Table("web_sales", web_sales_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_7979578_input.addCol("ws_ship_date_sk", 4);
    tbl_SerializeFromObject_TD_7979578_input.addCol("ws_ship_addr_sk", 4);
    tbl_SerializeFromObject_TD_7979578_input.addCol("ws_web_site_sk", 4);
    tbl_SerializeFromObject_TD_7979578_input.addCol("ws_order_number", 8);
    tbl_SerializeFromObject_TD_7979578_input.addCol("ws_ext_ship_cost", 4);
    tbl_SerializeFromObject_TD_7979578_input.addCol("ws_net_profit", 4);
    tbl_SerializeFromObject_TD_7979578_input.allocateHost();
    tbl_SerializeFromObject_TD_7979578_input.loadHost();
    Table tbl_Filter_TD_7701619_output("tbl_Filter_TD_7701619_output", 6100000, 2, "");
    tbl_Filter_TD_7701619_output.allocateHost();
    Table tbl_Filter_TD_7753681_output("tbl_Filter_TD_7753681_output", 6100000, 2, "");
    tbl_Filter_TD_7753681_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7660154_input;
    tbl_SerializeFromObject_TD_7660154_input = Table("web_returns", web_returns_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_7660154_input.addCol("wr_order_number", 8);
    tbl_SerializeFromObject_TD_7660154_input.allocateHost();
    tbl_SerializeFromObject_TD_7660154_input.loadHost();
    Table tbl_Filter_TD_7127062_output("tbl_Filter_TD_7127062_output", 6100000, 2, "");
    tbl_Filter_TD_7127062_output.allocateHost();
    Table tbl_Filter_TD_7579134_output("tbl_Filter_TD_7579134_output", 6100000, 2, "");
    tbl_Filter_TD_7579134_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8599880_input;
    tbl_SerializeFromObject_TD_8599880_input = Table("web_sales", web_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8599880_input.addCol("ws_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_8599880_input.addCol("ws_order_number", 8);
    tbl_SerializeFromObject_TD_8599880_input.allocateHost();
    tbl_SerializeFromObject_TD_8599880_input.loadHost();
    Table tbl_SerializeFromObject_TD_8380147_input;
    tbl_SerializeFromObject_TD_8380147_input = Table("web_sales", web_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8380147_input.addCol("ws_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_8380147_input.addCol("ws_order_number", 8);
    tbl_SerializeFromObject_TD_8380147_input.allocateHost();
    tbl_SerializeFromObject_TD_8380147_input.loadHost();
    Table tbl_SerializeFromObject_TD_8439018_input;
    tbl_SerializeFromObject_TD_8439018_input = Table("web_sales", web_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8439018_input.addCol("ws_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_8439018_input.addCol("ws_order_number", 8);
    tbl_SerializeFromObject_TD_8439018_input.allocateHost();
    tbl_SerializeFromObject_TD_8439018_input.loadHost();
    Table tbl_SerializeFromObject_TD_8441518_input;
    tbl_SerializeFromObject_TD_8441518_input = Table("web_sales", web_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8441518_input.addCol("ws_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_8441518_input.addCol("ws_order_number", 8);
    tbl_SerializeFromObject_TD_8441518_input.allocateHost();
    tbl_SerializeFromObject_TD_8441518_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_1787047_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_2754169_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_2161704_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_3440127_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_3190998_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTSEMI_TD_4697125_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_4929431_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTSEMI_TD_552916_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_5255352_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_637367_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_6724276_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_6644598_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_6127464_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_7701619_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_7753681_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_7127062_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_7579134_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_1787047_cmds;
    cfg_JOIN_INNER_TD_1787047_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_1787047_gqe_join (cfg_JOIN_INNER_TD_1787047_cmds.cmd);
    cfg_JOIN_INNER_TD_1787047_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_2754169_cmds;
    cfg_JOIN_INNER_TD_2754169_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_2754169_gqe_join (cfg_JOIN_INNER_TD_2754169_cmds.cmd);
    cfg_JOIN_INNER_TD_2754169_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_3440127_cmds;
    cfg_JOIN_INNER_TD_3440127_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_3440127_gqe_join (cfg_JOIN_INNER_TD_3440127_cmds.cmd);
    cfg_JOIN_INNER_TD_3440127_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_4697125_cmds;
    cfg_JOIN_LEFTSEMI_TD_4697125_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_4697125_gqe_join (cfg_JOIN_LEFTSEMI_TD_4697125_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_4697125_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_552916_cmds;
    cfg_JOIN_LEFTSEMI_TD_552916_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_552916_gqe_join (cfg_JOIN_LEFTSEMI_TD_552916_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_552916_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_5255352_cmds;
    cfg_JOIN_INNER_TD_5255352_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_5255352_gqe_join (cfg_JOIN_INNER_TD_5255352_cmds.cmd);
    cfg_JOIN_INNER_TD_5255352_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_6724276_cmds;
    cfg_JOIN_INNER_TD_6724276_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_6724276_gqe_join (cfg_JOIN_INNER_TD_6724276_cmds.cmd);
    cfg_JOIN_INNER_TD_6724276_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_6127464_cmds;
    cfg_JOIN_INNER_TD_6127464_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_6127464_gqe_join (cfg_JOIN_INNER_TD_6127464_cmds.cmd);
    cfg_JOIN_INNER_TD_6127464_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_1787047;
    krnl_JOIN_INNER_TD_1787047 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_1787047.setup(tbl_JOIN_INNER_TD_2754169_output, tbl_Filter_TD_2161704_output, tbl_JOIN_INNER_TD_1787047_output, cfg_JOIN_INNER_TD_1787047_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_2754169;
    krnl_JOIN_INNER_TD_2754169 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_2754169.setup(tbl_JOIN_INNER_TD_3440127_output, tbl_Filter_TD_3190998_output, tbl_JOIN_INNER_TD_2754169_output, cfg_JOIN_INNER_TD_2754169_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_3440127;
    krnl_JOIN_INNER_TD_3440127 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_3440127.setup(tbl_JOIN_LEFTSEMI_TD_4697125_output, tbl_Filter_TD_4929431_output, tbl_JOIN_INNER_TD_3440127_output, cfg_JOIN_INNER_TD_3440127_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_4697125;
    krnl_JOIN_LEFTSEMI_TD_4697125 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTSEMI_TD_4697125.setup(tbl_JOIN_INNER_TD_5255352_output, tbl_JOIN_LEFTSEMI_TD_552916_output, tbl_JOIN_LEFTSEMI_TD_4697125_output, cfg_JOIN_LEFTSEMI_TD_4697125_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_552916;
    krnl_JOIN_LEFTSEMI_TD_552916 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTSEMI_TD_552916.setup(tbl_JOIN_INNER_TD_6724276_output, tbl_Filter_TD_637367_output, tbl_JOIN_LEFTSEMI_TD_552916_output, cfg_JOIN_LEFTSEMI_TD_552916_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_5255352;
    krnl_JOIN_INNER_TD_5255352 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_5255352.setup(tbl_Filter_TD_6644598_output, tbl_JOIN_INNER_TD_6127464_output, tbl_JOIN_INNER_TD_5255352_output, cfg_JOIN_INNER_TD_5255352_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_6724276;
    krnl_JOIN_INNER_TD_6724276 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_6724276.setup(tbl_Filter_TD_7701619_output, tbl_Filter_TD_7753681_output, tbl_JOIN_INNER_TD_6724276_output, cfg_JOIN_INNER_TD_6724276_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_6127464;
    krnl_JOIN_INNER_TD_6127464 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_6127464.setup(tbl_Filter_TD_7127062_output, tbl_Filter_TD_7579134_output, tbl_JOIN_INNER_TD_6127464_output, cfg_JOIN_INNER_TD_6127464_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_1787047;
    trans_JOIN_INNER_TD_1787047.setq(q_h);
    trans_JOIN_INNER_TD_1787047.add(&(cfg_JOIN_INNER_TD_1787047_cmds));
    transEngine trans_JOIN_INNER_TD_1787047_out;
    trans_JOIN_INNER_TD_1787047_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_2754169;
    trans_JOIN_INNER_TD_2754169.setq(q_h);
    trans_JOIN_INNER_TD_2754169.add(&(cfg_JOIN_INNER_TD_2754169_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_3440127;
    trans_JOIN_INNER_TD_3440127.setq(q_h);
    trans_JOIN_INNER_TD_3440127.add(&(cfg_JOIN_INNER_TD_3440127_cmds));
    q_h.finish();
    transEngine trans_JOIN_LEFTSEMI_TD_4697125;
    trans_JOIN_LEFTSEMI_TD_4697125.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_4697125.add(&(cfg_JOIN_LEFTSEMI_TD_4697125_cmds));
    q_h.finish();
    transEngine trans_JOIN_LEFTSEMI_TD_552916;
    trans_JOIN_LEFTSEMI_TD_552916.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_552916.add(&(cfg_JOIN_LEFTSEMI_TD_552916_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_5255352;
    trans_JOIN_INNER_TD_5255352.setq(q_h);
    trans_JOIN_INNER_TD_5255352.add(&(cfg_JOIN_INNER_TD_5255352_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_6724276;
    trans_JOIN_INNER_TD_6724276.setq(q_h);
    trans_JOIN_INNER_TD_6724276.add(&(cfg_JOIN_INNER_TD_6724276_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_6127464;
    trans_JOIN_INNER_TD_6127464.setq(q_h);
    trans_JOIN_INNER_TD_6127464.add(&(cfg_JOIN_INNER_TD_6127464_cmds));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_1787047;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_1787047;
    std::vector<cl::Event> events_JOIN_INNER_TD_1787047;
    events_h2d_wr_JOIN_INNER_TD_1787047.resize(1);
    events_d2h_rd_JOIN_INNER_TD_1787047.resize(1);
    events_JOIN_INNER_TD_1787047.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_1787047;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_1787047;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_2754169;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_2754169;
    std::vector<cl::Event> events_JOIN_INNER_TD_2754169;
    events_h2d_wr_JOIN_INNER_TD_2754169.resize(1);
    events_d2h_rd_JOIN_INNER_TD_2754169.resize(1);
    events_JOIN_INNER_TD_2754169.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_2754169;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_2754169;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_3440127;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_3440127;
    std::vector<cl::Event> events_JOIN_INNER_TD_3440127;
    events_h2d_wr_JOIN_INNER_TD_3440127.resize(1);
    events_d2h_rd_JOIN_INNER_TD_3440127.resize(1);
    events_JOIN_INNER_TD_3440127.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_3440127;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_3440127;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_4697125;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_4697125;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_4697125;
    events_h2d_wr_JOIN_LEFTSEMI_TD_4697125.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_4697125.resize(1);
    events_JOIN_LEFTSEMI_TD_4697125.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_4697125;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_4697125;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_552916;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_552916;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_552916;
    events_h2d_wr_JOIN_LEFTSEMI_TD_552916.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_552916.resize(1);
    events_JOIN_LEFTSEMI_TD_552916.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_552916;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_552916;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_5255352;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_5255352;
    std::vector<cl::Event> events_JOIN_INNER_TD_5255352;
    events_h2d_wr_JOIN_INNER_TD_5255352.resize(1);
    events_d2h_rd_JOIN_INNER_TD_5255352.resize(1);
    events_JOIN_INNER_TD_5255352.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_5255352;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_5255352;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_6724276;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_6724276;
    std::vector<cl::Event> events_JOIN_INNER_TD_6724276;
    events_h2d_wr_JOIN_INNER_TD_6724276.resize(1);
    events_d2h_rd_JOIN_INNER_TD_6724276.resize(1);
    events_JOIN_INNER_TD_6724276.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_6724276;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_6724276;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_6127464;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_6127464;
    std::vector<cl::Event> events_JOIN_INNER_TD_6127464;
    events_h2d_wr_JOIN_INNER_TD_6127464.resize(1);
    events_d2h_rd_JOIN_INNER_TD_6127464.resize(1);
    events_JOIN_INNER_TD_6127464.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_6127464;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_6127464;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_7_375663_s, tv_r_Filter_7_375663_e;
    gettimeofday(&tv_r_Filter_7_375663_s, 0);
    SW_Filter_TD_7579134(tbl_SerializeFromObject_TD_8441518_input, tbl_Filter_TD_7579134_output);
    gettimeofday(&tv_r_Filter_7_375663_e, 0);

    struct timeval tv_r_Filter_7_459817_s, tv_r_Filter_7_459817_e;
    gettimeofday(&tv_r_Filter_7_459817_s, 0);
    SW_Filter_TD_7127062(tbl_SerializeFromObject_TD_8439018_input, tbl_Filter_TD_7127062_output);
    gettimeofday(&tv_r_Filter_7_459817_e, 0);

    struct timeval tv_r_Filter_7_398882_s, tv_r_Filter_7_398882_e;
    gettimeofday(&tv_r_Filter_7_398882_s, 0);
    SW_Filter_TD_7753681(tbl_SerializeFromObject_TD_8380147_input, tbl_Filter_TD_7753681_output);
    gettimeofday(&tv_r_Filter_7_398882_e, 0);

    struct timeval tv_r_Filter_7_600739_s, tv_r_Filter_7_600739_e;
    gettimeofday(&tv_r_Filter_7_600739_s, 0);
    SW_Filter_TD_7701619(tbl_SerializeFromObject_TD_8599880_input, tbl_Filter_TD_7701619_output);
    gettimeofday(&tv_r_Filter_7_600739_e, 0);

    struct timeval tv_r_JOIN_INNER_6_229423_s, tv_r_JOIN_INNER_6_229423_e;
    gettimeofday(&tv_r_JOIN_INNER_6_229423_s, 0);
    trans_JOIN_INNER_TD_6127464.add(&(tbl_Filter_TD_7127062_output));
    trans_JOIN_INNER_TD_6127464.add(&(tbl_Filter_TD_7579134_output));
    trans_JOIN_INNER_TD_6127464.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_6127464), &(events_h2d_wr_JOIN_INNER_TD_6127464[0]));
    events_grp_JOIN_INNER_TD_6127464.push_back(events_h2d_wr_JOIN_INNER_TD_6127464[0]);
    krnl_JOIN_INNER_TD_6127464.run(0, &(events_grp_JOIN_INNER_TD_6127464), &(events_JOIN_INNER_TD_6127464[0]));
    gettimeofday(&tv_r_JOIN_INNER_6_229423_e, 0);

    struct timeval tv_r_Filter_6_658475_s, tv_r_Filter_6_658475_e;
    gettimeofday(&tv_r_Filter_6_658475_s, 0);
    SW_Filter_TD_6644598(tbl_SerializeFromObject_TD_7660154_input, tbl_Filter_TD_6644598_output);
    gettimeofday(&tv_r_Filter_6_658475_e, 0);

    struct timeval tv_r_JOIN_INNER_6_393147_s, tv_r_JOIN_INNER_6_393147_e;
    gettimeofday(&tv_r_JOIN_INNER_6_393147_s, 0);
    trans_JOIN_INNER_TD_6724276.add(&(tbl_Filter_TD_7701619_output));
    trans_JOIN_INNER_TD_6724276.add(&(tbl_Filter_TD_7753681_output));
    trans_JOIN_INNER_TD_6724276.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_6724276), &(events_h2d_wr_JOIN_INNER_TD_6724276[0]));
    events_grp_JOIN_INNER_TD_6724276.push_back(events_h2d_wr_JOIN_INNER_TD_6724276[0]);
    krnl_JOIN_INNER_TD_6724276.run(0, &(events_grp_JOIN_INNER_TD_6724276), &(events_JOIN_INNER_TD_6724276[0]));
    gettimeofday(&tv_r_JOIN_INNER_6_393147_e, 0);

    struct timeval tv_r_Filter_6_608344_s, tv_r_Filter_6_608344_e;
    gettimeofday(&tv_r_Filter_6_608344_s, 0);
    SW_Filter_TD_637367(tbl_SerializeFromObject_TD_7979578_input, tbl_Filter_TD_637367_output);
    gettimeofday(&tv_r_Filter_6_608344_e, 0);

    struct timeval tv_r_JOIN_INNER_5_587685_s, tv_r_JOIN_INNER_5_587685_e;
    gettimeofday(&tv_r_JOIN_INNER_5_587685_s, 0);
    prev_events_grp_JOIN_INNER_TD_5255352.push_back(events_h2d_wr_JOIN_INNER_TD_6127464[0]);
    trans_JOIN_INNER_TD_5255352.add(&(tbl_Filter_TD_6644598_output));
    trans_JOIN_INNER_TD_5255352.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_5255352), &(events_h2d_wr_JOIN_INNER_TD_5255352[0]));
    events_grp_JOIN_INNER_TD_5255352.push_back(events_h2d_wr_JOIN_INNER_TD_5255352[0]);
    events_grp_JOIN_INNER_TD_5255352.push_back(events_JOIN_INNER_TD_6127464[0]);
    krnl_JOIN_INNER_TD_5255352.run(0, &(events_grp_JOIN_INNER_TD_5255352), &(events_JOIN_INNER_TD_5255352[0]));
    gettimeofday(&tv_r_JOIN_INNER_5_587685_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_5_953418_s, tv_r_JOIN_LEFTSEMI_5_953418_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_5_953418_s, 0);
    prev_events_grp_JOIN_LEFTSEMI_TD_552916.push_back(events_h2d_wr_JOIN_INNER_TD_6724276[0]);
    trans_JOIN_LEFTSEMI_TD_552916.add(&(tbl_Filter_TD_637367_output));
    trans_JOIN_LEFTSEMI_TD_552916.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_552916), &(events_h2d_wr_JOIN_LEFTSEMI_TD_552916[0]));
    events_grp_JOIN_LEFTSEMI_TD_552916.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_552916[0]);
    events_grp_JOIN_LEFTSEMI_TD_552916.push_back(events_JOIN_INNER_TD_6724276[0]);
    krnl_JOIN_LEFTSEMI_TD_552916.run(0, &(events_grp_JOIN_LEFTSEMI_TD_552916), &(events_JOIN_LEFTSEMI_TD_552916[0]));
    gettimeofday(&tv_r_JOIN_LEFTSEMI_5_953418_e, 0);

    struct timeval tv_r_Filter_4_789821_s, tv_r_Filter_4_789821_e;
    gettimeofday(&tv_r_Filter_4_789821_s, 0);
    SW_Filter_TD_4929431(tbl_SerializeFromObject_TD_5992253_input, tbl_Filter_TD_4929431_output);
    gettimeofday(&tv_r_Filter_4_789821_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_4_326923_s, tv_r_JOIN_LEFTSEMI_4_326923_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_4_326923_s, 0);
    prev_events_grp_JOIN_LEFTSEMI_TD_4697125.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_552916[0]);
    prev_events_grp_JOIN_LEFTSEMI_TD_4697125.push_back(events_h2d_wr_JOIN_INNER_TD_5255352[0]);
    trans_JOIN_LEFTSEMI_TD_4697125.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_4697125), &(events_h2d_wr_JOIN_LEFTSEMI_TD_4697125[0]));
    events_grp_JOIN_LEFTSEMI_TD_4697125.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_4697125[0]);
    events_grp_JOIN_LEFTSEMI_TD_4697125.push_back(events_JOIN_LEFTSEMI_TD_552916[0]);
    events_grp_JOIN_LEFTSEMI_TD_4697125.push_back(events_JOIN_INNER_TD_5255352[0]);
    krnl_JOIN_LEFTSEMI_TD_4697125.run(0, &(events_grp_JOIN_LEFTSEMI_TD_4697125), &(events_JOIN_LEFTSEMI_TD_4697125[0]));
    gettimeofday(&tv_r_JOIN_LEFTSEMI_4_326923_e, 0);

    struct timeval tv_r_Filter_3_113266_s, tv_r_Filter_3_113266_e;
    gettimeofday(&tv_r_Filter_3_113266_s, 0);
    SW_Filter_TD_3190998(tbl_SerializeFromObject_TD_455743_input, tbl_Filter_TD_3190998_output);
    gettimeofday(&tv_r_Filter_3_113266_e, 0);

    struct timeval tv_r_JOIN_INNER_3_532626_s, tv_r_JOIN_INNER_3_532626_e;
    gettimeofday(&tv_r_JOIN_INNER_3_532626_s, 0);
    prev_events_grp_JOIN_INNER_TD_3440127.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_4697125[0]);
    trans_JOIN_INNER_TD_3440127.add(&(tbl_Filter_TD_4929431_output));
    trans_JOIN_INNER_TD_3440127.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_3440127), &(events_h2d_wr_JOIN_INNER_TD_3440127[0]));
    events_grp_JOIN_INNER_TD_3440127.push_back(events_h2d_wr_JOIN_INNER_TD_3440127[0]);
    events_grp_JOIN_INNER_TD_3440127.push_back(events_JOIN_LEFTSEMI_TD_4697125[0]);
    krnl_JOIN_INNER_TD_3440127.run(0, &(events_grp_JOIN_INNER_TD_3440127), &(events_JOIN_INNER_TD_3440127[0]));
    gettimeofday(&tv_r_JOIN_INNER_3_532626_e, 0);

    struct timeval tv_r_Filter_2_391416_s, tv_r_Filter_2_391416_e;
    gettimeofday(&tv_r_Filter_2_391416_s, 0);
    SW_Filter_TD_2161704(tbl_SerializeFromObject_TD_3225711_input, tbl_Filter_TD_2161704_output);
    gettimeofday(&tv_r_Filter_2_391416_e, 0);

    struct timeval tv_r_JOIN_INNER_2_243910_s, tv_r_JOIN_INNER_2_243910_e;
    gettimeofday(&tv_r_JOIN_INNER_2_243910_s, 0);
    prev_events_grp_JOIN_INNER_TD_2754169.push_back(events_h2d_wr_JOIN_INNER_TD_3440127[0]);
    trans_JOIN_INNER_TD_2754169.add(&(tbl_Filter_TD_3190998_output));
    trans_JOIN_INNER_TD_2754169.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_2754169), &(events_h2d_wr_JOIN_INNER_TD_2754169[0]));
    events_grp_JOIN_INNER_TD_2754169.push_back(events_h2d_wr_JOIN_INNER_TD_2754169[0]);
    events_grp_JOIN_INNER_TD_2754169.push_back(events_JOIN_INNER_TD_3440127[0]);
    krnl_JOIN_INNER_TD_2754169.run(0, &(events_grp_JOIN_INNER_TD_2754169), &(events_JOIN_INNER_TD_2754169[0]));
    gettimeofday(&tv_r_JOIN_INNER_2_243910_e, 0);

    struct timeval tv_r_JOIN_INNER_1_470436_s, tv_r_JOIN_INNER_1_470436_e;
    gettimeofday(&tv_r_JOIN_INNER_1_470436_s, 0);
    prev_events_grp_JOIN_INNER_TD_1787047.push_back(events_h2d_wr_JOIN_INNER_TD_2754169[0]);
    trans_JOIN_INNER_TD_1787047.add(&(tbl_Filter_TD_2161704_output));
    trans_JOIN_INNER_TD_1787047.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_1787047), &(events_h2d_wr_JOIN_INNER_TD_1787047[0]));
    events_grp_JOIN_INNER_TD_1787047.push_back(events_h2d_wr_JOIN_INNER_TD_1787047[0]);
    events_grp_JOIN_INNER_TD_1787047.push_back(events_JOIN_INNER_TD_2754169[0]);
    krnl_JOIN_INNER_TD_1787047.run(0, &(events_grp_JOIN_INNER_TD_1787047), &(events_JOIN_INNER_TD_1787047[0]));
    
    trans_JOIN_INNER_TD_1787047_out.add(&(tbl_JOIN_INNER_TD_1787047_output));
    trans_JOIN_INNER_TD_1787047_out.dev2host(0, &(events_JOIN_INNER_TD_1787047), &(events_d2h_rd_JOIN_INNER_TD_1787047[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_1_470436_e, 0);

    struct timeval tv_r_Aggregate_0_656793_s, tv_r_Aggregate_0_656793_e;
    gettimeofday(&tv_r_Aggregate_0_656793_s, 0);
    SW_Aggregate_TD_0758830(tbl_JOIN_INNER_TD_1787047_output, tbl_Aggregate_TD_0758830_output);
    gettimeofday(&tv_r_Aggregate_0_656793_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_375663_s, &tv_r_Filter_7_375663_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8441518_input: " << tbl_SerializeFromObject_TD_8441518_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_459817_s, &tv_r_Filter_7_459817_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8439018_input: " << tbl_SerializeFromObject_TD_8439018_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_398882_s, &tv_r_Filter_7_398882_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8380147_input: " << tbl_SerializeFromObject_TD_8380147_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_600739_s, &tv_r_Filter_7_600739_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8599880_input: " << tbl_SerializeFromObject_TD_8599880_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_229423_s, &tv_r_JOIN_INNER_6_229423_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_7127062_output: " << tbl_Filter_TD_7127062_output.getNumRow() << " " << "tbl_Filter_TD_7579134_output: " << tbl_Filter_TD_7579134_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_658475_s, &tv_r_Filter_6_658475_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7660154_input: " << tbl_SerializeFromObject_TD_7660154_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_393147_s, &tv_r_JOIN_INNER_6_393147_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_7701619_output: " << tbl_Filter_TD_7701619_output.getNumRow() << " " << "tbl_Filter_TD_7753681_output: " << tbl_Filter_TD_7753681_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_608344_s, &tv_r_Filter_6_608344_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7979578_input: " << tbl_SerializeFromObject_TD_7979578_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_587685_s, &tv_r_JOIN_INNER_5_587685_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6644598_output: " << tbl_Filter_TD_6644598_output.getNumRow() << " " << "tbl_JOIN_INNER_TD_6127464_output: " << tbl_JOIN_INNER_TD_6127464_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_5: " << tvdiff(&tv_r_JOIN_LEFTSEMI_5_953418_s, &tv_r_JOIN_LEFTSEMI_5_953418_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_637367_output: " << tbl_Filter_TD_637367_output.getNumRow() << " " << "tbl_JOIN_INNER_TD_6724276_output: " << tbl_JOIN_INNER_TD_6724276_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_789821_s, &tv_r_Filter_4_789821_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5992253_input: " << tbl_SerializeFromObject_TD_5992253_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_4: " << tvdiff(&tv_r_JOIN_LEFTSEMI_4_326923_s, &tv_r_JOIN_LEFTSEMI_4_326923_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTSEMI_TD_552916_output: " << tbl_JOIN_LEFTSEMI_TD_552916_output.getNumRow() << " " << "tbl_JOIN_INNER_TD_5255352_output: " << tbl_JOIN_INNER_TD_5255352_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_113266_s, &tv_r_Filter_3_113266_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_455743_input: " << tbl_SerializeFromObject_TD_455743_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_532626_s, &tv_r_JOIN_INNER_3_532626_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTSEMI_TD_4697125_output: " << tbl_JOIN_LEFTSEMI_TD_4697125_output.getNumRow() << " " << "tbl_Filter_TD_4929431_output: " << tbl_Filter_TD_4929431_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_391416_s, &tv_r_Filter_2_391416_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3225711_input: " << tbl_SerializeFromObject_TD_3225711_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_2: " << tvdiff(&tv_r_JOIN_INNER_2_243910_s, &tv_r_JOIN_INNER_2_243910_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3440127_output: " << tbl_JOIN_INNER_TD_3440127_output.getNumRow() << " " << "tbl_Filter_TD_3190998_output: " << tbl_Filter_TD_3190998_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_1: " << tvdiff(&tv_r_JOIN_INNER_1_470436_s, &tv_r_JOIN_INNER_1_470436_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_2754169_output: " << tbl_JOIN_INNER_TD_2754169_output.getNumRow() << " " << "tbl_Filter_TD_2161704_output: " << tbl_Filter_TD_2161704_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_0: " << tvdiff(&tv_r_Aggregate_0_656793_s, &tv_r_Aggregate_0_656793_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_1787047_output: " << tbl_JOIN_INNER_TD_1787047_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 10.238709 * 1000 << "ms" << std::endl; 
    return 0; 
}
