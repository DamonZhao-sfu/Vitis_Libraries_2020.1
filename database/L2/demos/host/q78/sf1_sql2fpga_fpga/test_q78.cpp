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

#include "cfgFunc_q78.hpp" 
#include "q78.hpp" 

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
    std::cout << "NOTE:running query #78\n."; 
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
    Table tbl_GlobalLimit_TD_0687397_output("tbl_GlobalLimit_TD_0687397_output", 6100000, 10, "");
    tbl_GlobalLimit_TD_0687397_output.allocateHost();
    Table tbl_LocalLimit_TD_1909826_output("tbl_LocalLimit_TD_1909826_output", 6100000, 10, "");
    tbl_LocalLimit_TD_1909826_output.allocateHost();
    Table tbl_Sort_TD_2920142_output("tbl_Sort_TD_2920142_output", 6100000, 13, "");
    tbl_Sort_TD_2920142_output.allocateHost();
    Table tbl_Project_TD_3467215_output("tbl_Project_TD_3467215_output", 6100000, 13, "");
    tbl_Project_TD_3467215_output.allocateHost();
    Table tbl_Filter_TD_4962810_output("tbl_Filter_TD_4962810_output", 6100000, 12, "");
    tbl_Filter_TD_4962810_output.allocateHost();
    Table tbl_JOIN_LEFTOUTER_TD_5348560_output("tbl_JOIN_LEFTOUTER_TD_5348560_output", 6100000, 12, "");
    tbl_JOIN_LEFTOUTER_TD_5348560_output.allocateHost();
    Table tbl_JOIN_LEFTOUTER_TD_6605679_output("tbl_JOIN_LEFTOUTER_TD_6605679_output", 6100000, 9, "");
    tbl_JOIN_LEFTOUTER_TD_6605679_output.allocateHost();
    Table tbl_Aggregate_TD_6327308_output("tbl_Aggregate_TD_6327308_output", 6100000, 6, "");
    tbl_Aggregate_TD_6327308_output.allocateHost();
    Table tbl_Aggregate_TD_7527825_output("tbl_Aggregate_TD_7527825_output", 6100000, 6, "");
    tbl_Aggregate_TD_7527825_output.allocateHost();
    Table tbl_Aggregate_TD_7416502_output("tbl_Aggregate_TD_7416502_output", 6100000, 6, "");
    tbl_Aggregate_TD_7416502_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7958840_output("tbl_JOIN_INNER_TD_7958840_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_7958840_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8752431_output("tbl_JOIN_INNER_TD_8752431_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_8752431_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8497666_output("tbl_JOIN_INNER_TD_8497666_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_8497666_output.allocateHost();
    Table tbl_Filter_TD_8532339_output("tbl_Filter_TD_8532339_output", 6100000, 6, "");
    tbl_Filter_TD_8532339_output.allocateHost();
    Table tbl_Filter_TD_8740746_output("tbl_Filter_TD_8740746_output", 6100000, 2, "");
    tbl_Filter_TD_8740746_output.allocateHost();
    Table tbl_Filter_TD_9112927_output("tbl_Filter_TD_9112927_output", 6100000, 6, "");
    tbl_Filter_TD_9112927_output.allocateHost();
    Table tbl_Filter_TD_9947940_output("tbl_Filter_TD_9947940_output", 6100000, 2, "");
    tbl_Filter_TD_9947940_output.allocateHost();
    Table tbl_Filter_TD_9909549_output("tbl_Filter_TD_9909549_output", 6100000, 6, "");
    tbl_Filter_TD_9909549_output.allocateHost();
    Table tbl_Filter_TD_9807504_output("tbl_Filter_TD_9807504_output", 6100000, 2, "");
    tbl_Filter_TD_9807504_output.allocateHost();
    Table tbl_JOIN_LEFTOUTER_TD_9190274_output("tbl_JOIN_LEFTOUTER_TD_9190274_output", 6100000, 7, "");
    tbl_JOIN_LEFTOUTER_TD_9190274_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9423601_input;
    tbl_SerializeFromObject_TD_9423601_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9423601_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_9423601_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_9423601_input.allocateHost();
    tbl_SerializeFromObject_TD_9423601_input.loadHost();
    Table tbl_JOIN_LEFTOUTER_TD_10794663_output("tbl_JOIN_LEFTOUTER_TD_10794663_output", 6100000, 7, "");
    tbl_JOIN_LEFTOUTER_TD_10794663_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10497773_input;
    tbl_SerializeFromObject_TD_10497773_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10497773_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10497773_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10497773_input.allocateHost();
    tbl_SerializeFromObject_TD_10497773_input.loadHost();
    Table tbl_JOIN_LEFTOUTER_TD_10452759_output("tbl_JOIN_LEFTOUTER_TD_10452759_output", 6100000, 7, "");
    tbl_JOIN_LEFTOUTER_TD_10452759_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10623568_input;
    tbl_SerializeFromObject_TD_10623568_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10623568_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10623568_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10623568_input.allocateHost();
    tbl_SerializeFromObject_TD_10623568_input.loadHost();
    Table tbl_Filter_TD_10942672_output("tbl_Filter_TD_10942672_output", 6100000, 7, "");
    tbl_Filter_TD_10942672_output.allocateHost();
    Table tbl_Filter_TD_10105006_output("tbl_Filter_TD_10105006_output", 6100000, 2, "");
    tbl_Filter_TD_10105006_output.allocateHost();
    Table tbl_Filter_TD_11239235_output("tbl_Filter_TD_11239235_output", 6100000, 7, "");
    tbl_Filter_TD_11239235_output.allocateHost();
    Table tbl_Filter_TD_11109600_output("tbl_Filter_TD_11109600_output", 6100000, 2, "");
    tbl_Filter_TD_11109600_output.allocateHost();
    Table tbl_Filter_TD_11691082_output("tbl_Filter_TD_11691082_output", 6100000, 7, "");
    tbl_Filter_TD_11691082_output.allocateHost();
    Table tbl_Filter_TD_11309608_output("tbl_Filter_TD_11309608_output", 6100000, 2, "");
    tbl_Filter_TD_11309608_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11867361_input;
    tbl_SerializeFromObject_TD_11867361_input = Table("catalog_sales", catalog_sales_n, 7, in_dir, "orc");
    tbl_SerializeFromObject_TD_11867361_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_11867361_input.addCol("cs_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_11867361_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_11867361_input.addCol("cs_order_number", 8);
    tbl_SerializeFromObject_TD_11867361_input.addCol("cs_quantity", 4);
    tbl_SerializeFromObject_TD_11867361_input.addCol("cs_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_11867361_input.addCol("cs_sales_price", 4);
    tbl_SerializeFromObject_TD_11867361_input.allocateHost();
    tbl_SerializeFromObject_TD_11867361_input.loadHost();
    Table tbl_SerializeFromObject_TD_11905275_input;
    tbl_SerializeFromObject_TD_11905275_input = Table("catalog_returns", catalog_returns_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11905275_input.addCol("cr_item_sk", 4);
    tbl_SerializeFromObject_TD_11905275_input.addCol("cr_order_number", 8);
    tbl_SerializeFromObject_TD_11905275_input.allocateHost();
    tbl_SerializeFromObject_TD_11905275_input.loadHost();
    Table tbl_SerializeFromObject_TD_12731183_input;
    tbl_SerializeFromObject_TD_12731183_input = Table("store_sales", store_sales_n, 7, in_dir, "orc");
    tbl_SerializeFromObject_TD_12731183_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_12731183_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_12731183_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_12731183_input.addCol("ss_ticket_number", 8);
    tbl_SerializeFromObject_TD_12731183_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_12731183_input.addCol("ss_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_12731183_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_12731183_input.allocateHost();
    tbl_SerializeFromObject_TD_12731183_input.loadHost();
    Table tbl_SerializeFromObject_TD_12520073_input;
    tbl_SerializeFromObject_TD_12520073_input = Table("store_returns", store_returns_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12520073_input.addCol("sr_item_sk", 4);
    tbl_SerializeFromObject_TD_12520073_input.addCol("sr_ticket_number", 8);
    tbl_SerializeFromObject_TD_12520073_input.allocateHost();
    tbl_SerializeFromObject_TD_12520073_input.loadHost();
    Table tbl_SerializeFromObject_TD_12435085_input;
    tbl_SerializeFromObject_TD_12435085_input = Table("web_sales", web_sales_n, 7, in_dir, "orc");
    tbl_SerializeFromObject_TD_12435085_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_12435085_input.addCol("ws_item_sk", 4);
    tbl_SerializeFromObject_TD_12435085_input.addCol("ws_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_12435085_input.addCol("ws_order_number", 8);
    tbl_SerializeFromObject_TD_12435085_input.addCol("ws_quantity", 4);
    tbl_SerializeFromObject_TD_12435085_input.addCol("ws_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_12435085_input.addCol("ws_sales_price", 4);
    tbl_SerializeFromObject_TD_12435085_input.allocateHost();
    tbl_SerializeFromObject_TD_12435085_input.loadHost();
    Table tbl_SerializeFromObject_TD_1283330_input;
    tbl_SerializeFromObject_TD_1283330_input = Table("web_returns", web_returns_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_1283330_input.addCol("wr_item_sk", 4);
    tbl_SerializeFromObject_TD_1283330_input.addCol("wr_order_number", 8);
    tbl_SerializeFromObject_TD_1283330_input.allocateHost();
    tbl_SerializeFromObject_TD_1283330_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_7958840_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8752431_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8497666_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8532339_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8740746_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9112927_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9947940_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9909549_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9807504_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTOUTER_TD_9190274_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTOUTER_TD_10794663_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTOUTER_TD_10452759_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10942672_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10105006_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11239235_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11109600_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11691082_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11309608_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_7958840_cmds;
    cfg_JOIN_INNER_TD_7958840_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7958840_gqe_join (cfg_JOIN_INNER_TD_7958840_cmds.cmd);
    cfg_JOIN_INNER_TD_7958840_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8752431_cmds;
    cfg_JOIN_INNER_TD_8752431_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8752431_gqe_join (cfg_JOIN_INNER_TD_8752431_cmds.cmd);
    cfg_JOIN_INNER_TD_8752431_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8497666_cmds;
    cfg_JOIN_INNER_TD_8497666_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8497666_gqe_join (cfg_JOIN_INNER_TD_8497666_cmds.cmd);
    cfg_JOIN_INNER_TD_8497666_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTOUTER_TD_9190274_cmds;
    cfg_JOIN_LEFTOUTER_TD_9190274_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTOUTER_TD_9190274_gqe_join (cfg_JOIN_LEFTOUTER_TD_9190274_cmds.cmd);
    cfg_JOIN_LEFTOUTER_TD_9190274_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTOUTER_TD_10794663_cmds;
    cfg_JOIN_LEFTOUTER_TD_10794663_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTOUTER_TD_10794663_gqe_join (cfg_JOIN_LEFTOUTER_TD_10794663_cmds.cmd);
    cfg_JOIN_LEFTOUTER_TD_10794663_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTOUTER_TD_10452759_cmds;
    cfg_JOIN_LEFTOUTER_TD_10452759_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTOUTER_TD_10452759_gqe_join (cfg_JOIN_LEFTOUTER_TD_10452759_cmds.cmd);
    cfg_JOIN_LEFTOUTER_TD_10452759_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_7958840;
    krnl_JOIN_INNER_TD_7958840 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7958840.setup(tbl_Filter_TD_8532339_output, tbl_Filter_TD_8740746_output, tbl_JOIN_INNER_TD_7958840_output, cfg_JOIN_INNER_TD_7958840_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_8752431;
    krnl_JOIN_INNER_TD_8752431 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8752431.setup(tbl_Filter_TD_9112927_output, tbl_Filter_TD_9947940_output, tbl_JOIN_INNER_TD_8752431_output, cfg_JOIN_INNER_TD_8752431_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_8497666;
    krnl_JOIN_INNER_TD_8497666 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8497666.setup(tbl_Filter_TD_9909549_output, tbl_Filter_TD_9807504_output, tbl_JOIN_INNER_TD_8497666_output, cfg_JOIN_INNER_TD_8497666_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTOUTER_TD_9190274;
    krnl_JOIN_LEFTOUTER_TD_9190274 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTOUTER_TD_9190274.setup(tbl_Filter_TD_10942672_output, tbl_Filter_TD_10105006_output, tbl_JOIN_LEFTOUTER_TD_9190274_output, cfg_JOIN_LEFTOUTER_TD_9190274_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTOUTER_TD_10794663;
    krnl_JOIN_LEFTOUTER_TD_10794663 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTOUTER_TD_10794663.setup(tbl_Filter_TD_11239235_output, tbl_Filter_TD_11109600_output, tbl_JOIN_LEFTOUTER_TD_10794663_output, cfg_JOIN_LEFTOUTER_TD_10794663_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTOUTER_TD_10452759;
    krnl_JOIN_LEFTOUTER_TD_10452759 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTOUTER_TD_10452759.setup(tbl_Filter_TD_11691082_output, tbl_Filter_TD_11309608_output, tbl_JOIN_LEFTOUTER_TD_10452759_output, cfg_JOIN_LEFTOUTER_TD_10452759_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_7958840;
    trans_JOIN_INNER_TD_7958840.setq(q_h);
    trans_JOIN_INNER_TD_7958840.add(&(cfg_JOIN_INNER_TD_7958840_cmds));
    transEngine trans_JOIN_INNER_TD_7958840_out;
    trans_JOIN_INNER_TD_7958840_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_8752431;
    trans_JOIN_INNER_TD_8752431.setq(q_h);
    trans_JOIN_INNER_TD_8752431.add(&(cfg_JOIN_INNER_TD_8752431_cmds));
    transEngine trans_JOIN_INNER_TD_8752431_out;
    trans_JOIN_INNER_TD_8752431_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_8497666;
    trans_JOIN_INNER_TD_8497666.setq(q_h);
    trans_JOIN_INNER_TD_8497666.add(&(cfg_JOIN_INNER_TD_8497666_cmds));
    transEngine trans_JOIN_INNER_TD_8497666_out;
    trans_JOIN_INNER_TD_8497666_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_LEFTOUTER_TD_9190274;
    trans_JOIN_LEFTOUTER_TD_9190274.setq(q_h);
    trans_JOIN_LEFTOUTER_TD_9190274.add(&(cfg_JOIN_LEFTOUTER_TD_9190274_cmds));
    transEngine trans_JOIN_LEFTOUTER_TD_9190274_out;
    trans_JOIN_LEFTOUTER_TD_9190274_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_LEFTOUTER_TD_10794663;
    trans_JOIN_LEFTOUTER_TD_10794663.setq(q_h);
    trans_JOIN_LEFTOUTER_TD_10794663.add(&(cfg_JOIN_LEFTOUTER_TD_10794663_cmds));
    transEngine trans_JOIN_LEFTOUTER_TD_10794663_out;
    trans_JOIN_LEFTOUTER_TD_10794663_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_LEFTOUTER_TD_10452759;
    trans_JOIN_LEFTOUTER_TD_10452759.setq(q_h);
    trans_JOIN_LEFTOUTER_TD_10452759.add(&(cfg_JOIN_LEFTOUTER_TD_10452759_cmds));
    transEngine trans_JOIN_LEFTOUTER_TD_10452759_out;
    trans_JOIN_LEFTOUTER_TD_10452759_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7958840;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7958840;
    std::vector<cl::Event> events_JOIN_INNER_TD_7958840;
    events_h2d_wr_JOIN_INNER_TD_7958840.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7958840.resize(1);
    events_JOIN_INNER_TD_7958840.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7958840;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7958840;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8752431;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8752431;
    std::vector<cl::Event> events_JOIN_INNER_TD_8752431;
    events_h2d_wr_JOIN_INNER_TD_8752431.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8752431.resize(1);
    events_JOIN_INNER_TD_8752431.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8752431;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8752431;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8497666;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8497666;
    std::vector<cl::Event> events_JOIN_INNER_TD_8497666;
    events_h2d_wr_JOIN_INNER_TD_8497666.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8497666.resize(1);
    events_JOIN_INNER_TD_8497666.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8497666;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8497666;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTOUTER_TD_9190274;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTOUTER_TD_9190274;
    std::vector<cl::Event> events_JOIN_LEFTOUTER_TD_9190274;
    events_h2d_wr_JOIN_LEFTOUTER_TD_9190274.resize(1);
    events_d2h_rd_JOIN_LEFTOUTER_TD_9190274.resize(1);
    events_JOIN_LEFTOUTER_TD_9190274.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTOUTER_TD_9190274;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTOUTER_TD_9190274;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTOUTER_TD_10794663;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTOUTER_TD_10794663;
    std::vector<cl::Event> events_JOIN_LEFTOUTER_TD_10794663;
    events_h2d_wr_JOIN_LEFTOUTER_TD_10794663.resize(1);
    events_d2h_rd_JOIN_LEFTOUTER_TD_10794663.resize(1);
    events_JOIN_LEFTOUTER_TD_10794663.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTOUTER_TD_10794663;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTOUTER_TD_10794663;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTOUTER_TD_10452759;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTOUTER_TD_10452759;
    std::vector<cl::Event> events_JOIN_LEFTOUTER_TD_10452759;
    events_h2d_wr_JOIN_LEFTOUTER_TD_10452759.resize(1);
    events_d2h_rd_JOIN_LEFTOUTER_TD_10452759.resize(1);
    events_JOIN_LEFTOUTER_TD_10452759.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTOUTER_TD_10452759;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTOUTER_TD_10452759;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_11_732387_s, tv_r_Filter_11_732387_e;
    gettimeofday(&tv_r_Filter_11_732387_s, 0);
    SW_Filter_TD_11309608(tbl_SerializeFromObject_TD_1283330_input, tbl_Filter_TD_11309608_output);
    gettimeofday(&tv_r_Filter_11_732387_e, 0);

    struct timeval tv_r_Filter_11_940545_s, tv_r_Filter_11_940545_e;
    gettimeofday(&tv_r_Filter_11_940545_s, 0);
    SW_Filter_TD_11691082(tbl_SerializeFromObject_TD_12435085_input, tbl_Filter_TD_11691082_output);
    gettimeofday(&tv_r_Filter_11_940545_e, 0);

    struct timeval tv_r_Filter_11_369799_s, tv_r_Filter_11_369799_e;
    gettimeofday(&tv_r_Filter_11_369799_s, 0);
    SW_Filter_TD_11109600(tbl_SerializeFromObject_TD_12520073_input, tbl_Filter_TD_11109600_output);
    gettimeofday(&tv_r_Filter_11_369799_e, 0);

    struct timeval tv_r_Filter_11_394676_s, tv_r_Filter_11_394676_e;
    gettimeofday(&tv_r_Filter_11_394676_s, 0);
    SW_Filter_TD_11239235(tbl_SerializeFromObject_TD_12731183_input, tbl_Filter_TD_11239235_output);
    gettimeofday(&tv_r_Filter_11_394676_e, 0);

    struct timeval tv_r_Filter_10_290379_s, tv_r_Filter_10_290379_e;
    gettimeofday(&tv_r_Filter_10_290379_s, 0);
    SW_Filter_TD_10105006(tbl_SerializeFromObject_TD_11905275_input, tbl_Filter_TD_10105006_output);
    gettimeofday(&tv_r_Filter_10_290379_e, 0);

    struct timeval tv_r_Filter_10_391203_s, tv_r_Filter_10_391203_e;
    gettimeofday(&tv_r_Filter_10_391203_s, 0);
    SW_Filter_TD_10942672(tbl_SerializeFromObject_TD_11867361_input, tbl_Filter_TD_10942672_output);
    gettimeofday(&tv_r_Filter_10_391203_e, 0);

    struct timeval tv_r_JOIN_LEFTOUTER_10_905192_s, tv_r_JOIN_LEFTOUTER_10_905192_e;
    gettimeofday(&tv_r_JOIN_LEFTOUTER_10_905192_s, 0);
    trans_JOIN_LEFTOUTER_TD_10452759.add(&(tbl_Filter_TD_11691082_output));
    trans_JOIN_LEFTOUTER_TD_10452759.add(&(tbl_Filter_TD_11309608_output));
    trans_JOIN_LEFTOUTER_TD_10452759.host2dev(0, &(prev_events_grp_JOIN_LEFTOUTER_TD_10452759), &(events_h2d_wr_JOIN_LEFTOUTER_TD_10452759[0]));
    events_grp_JOIN_LEFTOUTER_TD_10452759.push_back(events_h2d_wr_JOIN_LEFTOUTER_TD_10452759[0]);
    krnl_JOIN_LEFTOUTER_TD_10452759.run(0, &(events_grp_JOIN_LEFTOUTER_TD_10452759), &(events_JOIN_LEFTOUTER_TD_10452759[0]));
    
    trans_JOIN_LEFTOUTER_TD_10452759_out.add(&(tbl_JOIN_LEFTOUTER_TD_10452759_output));
    trans_JOIN_LEFTOUTER_TD_10452759_out.dev2host(0, &(events_JOIN_LEFTOUTER_TD_10452759), &(events_d2h_rd_JOIN_LEFTOUTER_TD_10452759[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_LEFTOUTER_10_905192_e, 0);

    struct timeval tv_r_JOIN_LEFTOUTER_10_53697_s, tv_r_JOIN_LEFTOUTER_10_53697_e;
    gettimeofday(&tv_r_JOIN_LEFTOUTER_10_53697_s, 0);
    trans_JOIN_LEFTOUTER_TD_10794663.add(&(tbl_Filter_TD_11239235_output));
    trans_JOIN_LEFTOUTER_TD_10794663.add(&(tbl_Filter_TD_11109600_output));
    trans_JOIN_LEFTOUTER_TD_10794663.host2dev(0, &(prev_events_grp_JOIN_LEFTOUTER_TD_10794663), &(events_h2d_wr_JOIN_LEFTOUTER_TD_10794663[0]));
    events_grp_JOIN_LEFTOUTER_TD_10794663.push_back(events_h2d_wr_JOIN_LEFTOUTER_TD_10794663[0]);
    krnl_JOIN_LEFTOUTER_TD_10794663.run(0, &(events_grp_JOIN_LEFTOUTER_TD_10794663), &(events_JOIN_LEFTOUTER_TD_10794663[0]));
    
    trans_JOIN_LEFTOUTER_TD_10794663_out.add(&(tbl_JOIN_LEFTOUTER_TD_10794663_output));
    trans_JOIN_LEFTOUTER_TD_10794663_out.dev2host(0, &(events_JOIN_LEFTOUTER_TD_10794663), &(events_d2h_rd_JOIN_LEFTOUTER_TD_10794663[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_LEFTOUTER_10_53697_e, 0);

    struct timeval tv_r_JOIN_LEFTOUTER_9_657699_s, tv_r_JOIN_LEFTOUTER_9_657699_e;
    gettimeofday(&tv_r_JOIN_LEFTOUTER_9_657699_s, 0);
    trans_JOIN_LEFTOUTER_TD_9190274.add(&(tbl_Filter_TD_10942672_output));
    trans_JOIN_LEFTOUTER_TD_9190274.add(&(tbl_Filter_TD_10105006_output));
    trans_JOIN_LEFTOUTER_TD_9190274.host2dev(0, &(prev_events_grp_JOIN_LEFTOUTER_TD_9190274), &(events_h2d_wr_JOIN_LEFTOUTER_TD_9190274[0]));
    events_grp_JOIN_LEFTOUTER_TD_9190274.push_back(events_h2d_wr_JOIN_LEFTOUTER_TD_9190274[0]);
    krnl_JOIN_LEFTOUTER_TD_9190274.run(0, &(events_grp_JOIN_LEFTOUTER_TD_9190274), &(events_JOIN_LEFTOUTER_TD_9190274[0]));
    
    trans_JOIN_LEFTOUTER_TD_9190274_out.add(&(tbl_JOIN_LEFTOUTER_TD_9190274_output));
    trans_JOIN_LEFTOUTER_TD_9190274_out.dev2host(0, &(events_JOIN_LEFTOUTER_TD_9190274), &(events_d2h_rd_JOIN_LEFTOUTER_TD_9190274[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_LEFTOUTER_9_657699_e, 0);

    struct timeval tv_r_Filter_9_760937_s, tv_r_Filter_9_760937_e;
    gettimeofday(&tv_r_Filter_9_760937_s, 0);
    SW_Filter_TD_9807504(tbl_SerializeFromObject_TD_10623568_input, tbl_Filter_TD_9807504_output);
    gettimeofday(&tv_r_Filter_9_760937_e, 0);

    struct timeval tv_r_Filter_9_764565_s, tv_r_Filter_9_764565_e;
    gettimeofday(&tv_r_Filter_9_764565_s, 0);
    SW_Filter_TD_9909549(tbl_JOIN_LEFTOUTER_TD_10452759_output, tbl_Filter_TD_9909549_output);
    gettimeofday(&tv_r_Filter_9_764565_e, 0);

    struct timeval tv_r_Filter_9_571054_s, tv_r_Filter_9_571054_e;
    gettimeofday(&tv_r_Filter_9_571054_s, 0);
    SW_Filter_TD_9947940(tbl_SerializeFromObject_TD_10497773_input, tbl_Filter_TD_9947940_output);
    gettimeofday(&tv_r_Filter_9_571054_e, 0);

    struct timeval tv_r_Filter_9_297397_s, tv_r_Filter_9_297397_e;
    gettimeofday(&tv_r_Filter_9_297397_s, 0);
    SW_Filter_TD_9112927(tbl_JOIN_LEFTOUTER_TD_10794663_output, tbl_Filter_TD_9112927_output);
    gettimeofday(&tv_r_Filter_9_297397_e, 0);

    struct timeval tv_r_Filter_8_933667_s, tv_r_Filter_8_933667_e;
    gettimeofday(&tv_r_Filter_8_933667_s, 0);
    SW_Filter_TD_8740746(tbl_SerializeFromObject_TD_9423601_input, tbl_Filter_TD_8740746_output);
    gettimeofday(&tv_r_Filter_8_933667_e, 0);

    struct timeval tv_r_Filter_8_124765_s, tv_r_Filter_8_124765_e;
    gettimeofday(&tv_r_Filter_8_124765_s, 0);
    SW_Filter_TD_8532339(tbl_JOIN_LEFTOUTER_TD_9190274_output, tbl_Filter_TD_8532339_output);
    gettimeofday(&tv_r_Filter_8_124765_e, 0);

    struct timeval tv_r_JOIN_INNER_8_395667_s, tv_r_JOIN_INNER_8_395667_e;
    gettimeofday(&tv_r_JOIN_INNER_8_395667_s, 0);
    trans_JOIN_INNER_TD_8497666.add(&(tbl_Filter_TD_9909549_output));
    trans_JOIN_INNER_TD_8497666.add(&(tbl_Filter_TD_9807504_output));
    trans_JOIN_INNER_TD_8497666.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8497666), &(events_h2d_wr_JOIN_INNER_TD_8497666[0]));
    events_grp_JOIN_INNER_TD_8497666.push_back(events_h2d_wr_JOIN_INNER_TD_8497666[0]);
    krnl_JOIN_INNER_TD_8497666.run(0, &(events_grp_JOIN_INNER_TD_8497666), &(events_JOIN_INNER_TD_8497666[0]));
    
    trans_JOIN_INNER_TD_8497666_out.add(&(tbl_JOIN_INNER_TD_8497666_output));
    trans_JOIN_INNER_TD_8497666_out.dev2host(0, &(events_JOIN_INNER_TD_8497666), &(events_d2h_rd_JOIN_INNER_TD_8497666[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_8_395667_e, 0);

    struct timeval tv_r_JOIN_INNER_8_672067_s, tv_r_JOIN_INNER_8_672067_e;
    gettimeofday(&tv_r_JOIN_INNER_8_672067_s, 0);
    trans_JOIN_INNER_TD_8752431.add(&(tbl_Filter_TD_9112927_output));
    trans_JOIN_INNER_TD_8752431.add(&(tbl_Filter_TD_9947940_output));
    trans_JOIN_INNER_TD_8752431.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8752431), &(events_h2d_wr_JOIN_INNER_TD_8752431[0]));
    events_grp_JOIN_INNER_TD_8752431.push_back(events_h2d_wr_JOIN_INNER_TD_8752431[0]);
    krnl_JOIN_INNER_TD_8752431.run(0, &(events_grp_JOIN_INNER_TD_8752431), &(events_JOIN_INNER_TD_8752431[0]));
    
    trans_JOIN_INNER_TD_8752431_out.add(&(tbl_JOIN_INNER_TD_8752431_output));
    trans_JOIN_INNER_TD_8752431_out.dev2host(0, &(events_JOIN_INNER_TD_8752431), &(events_d2h_rd_JOIN_INNER_TD_8752431[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_8_672067_e, 0);

    struct timeval tv_r_JOIN_INNER_7_298045_s, tv_r_JOIN_INNER_7_298045_e;
    gettimeofday(&tv_r_JOIN_INNER_7_298045_s, 0);
    trans_JOIN_INNER_TD_7958840.add(&(tbl_Filter_TD_8532339_output));
    trans_JOIN_INNER_TD_7958840.add(&(tbl_Filter_TD_8740746_output));
    trans_JOIN_INNER_TD_7958840.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7958840), &(events_h2d_wr_JOIN_INNER_TD_7958840[0]));
    events_grp_JOIN_INNER_TD_7958840.push_back(events_h2d_wr_JOIN_INNER_TD_7958840[0]);
    krnl_JOIN_INNER_TD_7958840.run(0, &(events_grp_JOIN_INNER_TD_7958840), &(events_JOIN_INNER_TD_7958840[0]));
    
    trans_JOIN_INNER_TD_7958840_out.add(&(tbl_JOIN_INNER_TD_7958840_output));
    trans_JOIN_INNER_TD_7958840_out.dev2host(0, &(events_JOIN_INNER_TD_7958840), &(events_d2h_rd_JOIN_INNER_TD_7958840[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_7_298045_e, 0);

    struct timeval tv_r_Aggregate_7_989962_s, tv_r_Aggregate_7_989962_e;
    gettimeofday(&tv_r_Aggregate_7_989962_s, 0);
    SW_Aggregate_TD_7416502(tbl_JOIN_INNER_TD_8497666_output, tbl_Aggregate_TD_7416502_output);
    gettimeofday(&tv_r_Aggregate_7_989962_e, 0);

    struct timeval tv_r_Aggregate_7_433487_s, tv_r_Aggregate_7_433487_e;
    gettimeofday(&tv_r_Aggregate_7_433487_s, 0);
    SW_Aggregate_TD_7527825(tbl_JOIN_INNER_TD_8752431_output, tbl_Aggregate_TD_7527825_output);
    gettimeofday(&tv_r_Aggregate_7_433487_e, 0);

    struct timeval tv_r_Aggregate_6_246068_s, tv_r_Aggregate_6_246068_e;
    gettimeofday(&tv_r_Aggregate_6_246068_s, 0);
    SW_Aggregate_TD_6327308(tbl_JOIN_INNER_TD_7958840_output, tbl_Aggregate_TD_6327308_output);
    gettimeofday(&tv_r_Aggregate_6_246068_e, 0);

    struct timeval tv_r_JOIN_LEFTOUTER_6_221921_s, tv_r_JOIN_LEFTOUTER_6_221921_e;
    gettimeofday(&tv_r_JOIN_LEFTOUTER_6_221921_s, 0);
    SW_JOIN_LEFTOUTER_TD_6605679(tbl_Aggregate_TD_7527825_output, tbl_Aggregate_TD_7416502_output, tbl_JOIN_LEFTOUTER_TD_6605679_output);
    gettimeofday(&tv_r_JOIN_LEFTOUTER_6_221921_e, 0);

    struct timeval tv_r_JOIN_LEFTOUTER_5_233047_s, tv_r_JOIN_LEFTOUTER_5_233047_e;
    gettimeofday(&tv_r_JOIN_LEFTOUTER_5_233047_s, 0);
    SW_JOIN_LEFTOUTER_TD_5348560(tbl_JOIN_LEFTOUTER_TD_6605679_output, tbl_Aggregate_TD_6327308_output, tbl_JOIN_LEFTOUTER_TD_5348560_output);
    gettimeofday(&tv_r_JOIN_LEFTOUTER_5_233047_e, 0);

    struct timeval tv_r_Filter_4_293887_s, tv_r_Filter_4_293887_e;
    gettimeofday(&tv_r_Filter_4_293887_s, 0);
    SW_Filter_TD_4962810(tbl_JOIN_LEFTOUTER_TD_5348560_output, tbl_Filter_TD_4962810_output);
    gettimeofday(&tv_r_Filter_4_293887_e, 0);

    struct timeval tv_r_Project_3_633177_s, tv_r_Project_3_633177_e;
    gettimeofday(&tv_r_Project_3_633177_s, 0);
    SW_Project_TD_3467215(tbl_Filter_TD_4962810_output, tbl_Project_TD_3467215_output);
    gettimeofday(&tv_r_Project_3_633177_e, 0);

    struct timeval tv_r_Sort_2_153402_s, tv_r_Sort_2_153402_e;
    gettimeofday(&tv_r_Sort_2_153402_s, 0);
    SW_Sort_TD_2920142(tbl_Project_TD_3467215_output, tbl_Sort_TD_2920142_output);
    gettimeofday(&tv_r_Sort_2_153402_e, 0);

    struct timeval tv_r_LocalLimit_1_42127_s, tv_r_LocalLimit_1_42127_e;
    gettimeofday(&tv_r_LocalLimit_1_42127_s, 0);
    SW_LocalLimit_TD_1909826(tbl_Sort_TD_2920142_output, tbl_LocalLimit_TD_1909826_output);
    gettimeofday(&tv_r_LocalLimit_1_42127_e, 0);

    struct timeval tv_r_GlobalLimit_0_670669_s, tv_r_GlobalLimit_0_670669_e;
    gettimeofday(&tv_r_GlobalLimit_0_670669_s, 0);
    SW_GlobalLimit_TD_0687397(tbl_LocalLimit_TD_1909826_output, tbl_GlobalLimit_TD_0687397_output);
    gettimeofday(&tv_r_GlobalLimit_0_670669_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_732387_s, &tv_r_Filter_11_732387_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1283330_input: " << tbl_SerializeFromObject_TD_1283330_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_940545_s, &tv_r_Filter_11_940545_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12435085_input: " << tbl_SerializeFromObject_TD_12435085_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_369799_s, &tv_r_Filter_11_369799_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12520073_input: " << tbl_SerializeFromObject_TD_12520073_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_394676_s, &tv_r_Filter_11_394676_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12731183_input: " << tbl_SerializeFromObject_TD_12731183_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_290379_s, &tv_r_Filter_10_290379_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11905275_input: " << tbl_SerializeFromObject_TD_11905275_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_391203_s, &tv_r_Filter_10_391203_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11867361_input: " << tbl_SerializeFromObject_TD_11867361_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTOUTER_10: " << tvdiff(&tv_r_JOIN_LEFTOUTER_10_905192_s, &tv_r_JOIN_LEFTOUTER_10_905192_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11691082_output: " << tbl_Filter_TD_11691082_output.getNumRow() << " " << "tbl_Filter_TD_11309608_output: " << tbl_Filter_TD_11309608_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTOUTER_10: " << tvdiff(&tv_r_JOIN_LEFTOUTER_10_53697_s, &tv_r_JOIN_LEFTOUTER_10_53697_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11239235_output: " << tbl_Filter_TD_11239235_output.getNumRow() << " " << "tbl_Filter_TD_11109600_output: " << tbl_Filter_TD_11109600_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTOUTER_9: " << tvdiff(&tv_r_JOIN_LEFTOUTER_9_657699_s, &tv_r_JOIN_LEFTOUTER_9_657699_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10942672_output: " << tbl_Filter_TD_10942672_output.getNumRow() << " " << "tbl_Filter_TD_10105006_output: " << tbl_Filter_TD_10105006_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_760937_s, &tv_r_Filter_9_760937_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10623568_input: " << tbl_SerializeFromObject_TD_10623568_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_764565_s, &tv_r_Filter_9_764565_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTOUTER_TD_10452759_output: " << tbl_JOIN_LEFTOUTER_TD_10452759_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_571054_s, &tv_r_Filter_9_571054_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10497773_input: " << tbl_SerializeFromObject_TD_10497773_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_297397_s, &tv_r_Filter_9_297397_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTOUTER_TD_10794663_output: " << tbl_JOIN_LEFTOUTER_TD_10794663_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_933667_s, &tv_r_Filter_8_933667_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9423601_input: " << tbl_SerializeFromObject_TD_9423601_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_124765_s, &tv_r_Filter_8_124765_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTOUTER_TD_9190274_output: " << tbl_JOIN_LEFTOUTER_TD_9190274_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_395667_s, &tv_r_JOIN_INNER_8_395667_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9909549_output: " << tbl_Filter_TD_9909549_output.getNumRow() << " " << "tbl_Filter_TD_9807504_output: " << tbl_Filter_TD_9807504_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_672067_s, &tv_r_JOIN_INNER_8_672067_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9112927_output: " << tbl_Filter_TD_9112927_output.getNumRow() << " " << "tbl_Filter_TD_9947940_output: " << tbl_Filter_TD_9947940_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_298045_s, &tv_r_JOIN_INNER_7_298045_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8532339_output: " << tbl_Filter_TD_8532339_output.getNumRow() << " " << "tbl_Filter_TD_8740746_output: " << tbl_Filter_TD_8740746_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_7: " << tvdiff(&tv_r_Aggregate_7_989962_s, &tv_r_Aggregate_7_989962_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8497666_output: " << tbl_JOIN_INNER_TD_8497666_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_7: " << tvdiff(&tv_r_Aggregate_7_433487_s, &tv_r_Aggregate_7_433487_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8752431_output: " << tbl_JOIN_INNER_TD_8752431_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_6: " << tvdiff(&tv_r_Aggregate_6_246068_s, &tv_r_Aggregate_6_246068_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7958840_output: " << tbl_JOIN_INNER_TD_7958840_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTOUTER_6: " << tvdiff(&tv_r_JOIN_LEFTOUTER_6_221921_s, &tv_r_JOIN_LEFTOUTER_6_221921_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_7527825_output: " << tbl_Aggregate_TD_7527825_output.getNumRow() << " " << "tbl_Aggregate_TD_7416502_output: " << tbl_Aggregate_TD_7416502_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTOUTER_5: " << tvdiff(&tv_r_JOIN_LEFTOUTER_5_233047_s, &tv_r_JOIN_LEFTOUTER_5_233047_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTOUTER_TD_6605679_output: " << tbl_JOIN_LEFTOUTER_TD_6605679_output.getNumRow() << " " << "tbl_Aggregate_TD_6327308_output: " << tbl_Aggregate_TD_6327308_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_293887_s, &tv_r_Filter_4_293887_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTOUTER_TD_5348560_output: " << tbl_JOIN_LEFTOUTER_TD_5348560_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_3: " << tvdiff(&tv_r_Project_3_633177_s, &tv_r_Project_3_633177_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_4962810_output: " << tbl_Filter_TD_4962810_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_153402_s, &tv_r_Sort_2_153402_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_3467215_output: " << tbl_Project_TD_3467215_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_42127_s, &tv_r_LocalLimit_1_42127_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2920142_output: " << tbl_Sort_TD_2920142_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_670669_s, &tv_r_GlobalLimit_0_670669_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1909826_output: " << tbl_LocalLimit_TD_1909826_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 7.216196 * 1000 << "ms" << std::endl; 
    return 0; 
}
