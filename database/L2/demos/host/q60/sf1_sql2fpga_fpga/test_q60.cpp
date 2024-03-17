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

#include "cfgFunc_q60.hpp" 
#include "q60.hpp" 

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
    std::cout << "NOTE:running query #60\n."; 
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
    Table tbl_GlobalLimit_TD_0799225_output("tbl_GlobalLimit_TD_0799225_output", 6100000, 2, "");
    tbl_GlobalLimit_TD_0799225_output.allocateHost();
    Table tbl_LocalLimit_TD_1867169_output("tbl_LocalLimit_TD_1867169_output", 6100000, 2, "");
    tbl_LocalLimit_TD_1867169_output.allocateHost();
    Table tbl_Sort_TD_2924655_output("tbl_Sort_TD_2924655_output", 6100000, 2, "");
    tbl_Sort_TD_2924655_output.allocateHost();
    Table tbl_Aggregate_TD_3933724_output("tbl_Aggregate_TD_3933724_output", 6100000, 2, "");
    tbl_Aggregate_TD_3933724_output.allocateHost();
    Table tbl_Union_TD_4612144_output("tbl_Union_TD_4612144_output", 6100000, 2, "");
    tbl_Union_TD_4612144_output.allocateHost();
    Table tbl_Aggregate_TD_5879177_output("tbl_Aggregate_TD_5879177_output", 6100000, 2, "");
    tbl_Aggregate_TD_5879177_output.allocateHost();
    Table tbl_Aggregate_TD_5617076_output("tbl_Aggregate_TD_5617076_output", 6100000, 2, "");
    tbl_Aggregate_TD_5617076_output.allocateHost();
    Table tbl_Aggregate_TD_5792815_output("tbl_Aggregate_TD_5792815_output", 6100000, 2, "");
    tbl_Aggregate_TD_5792815_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6520657_output("tbl_JOIN_INNER_TD_6520657_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_6520657_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6260223_output("tbl_JOIN_INNER_TD_6260223_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_6260223_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6561024_output("tbl_JOIN_INNER_TD_6561024_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_6561024_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7798154_output("tbl_JOIN_INNER_TD_7798154_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_7798154_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_7600525_output("tbl_JOIN_LEFTSEMI_TD_7600525_output", 6100000, 2, "");
    tbl_JOIN_LEFTSEMI_TD_7600525_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7858959_output("tbl_JOIN_INNER_TD_7858959_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_7858959_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_7822991_output("tbl_JOIN_LEFTSEMI_TD_7822991_output", 6100000, 2, "");
    tbl_JOIN_LEFTSEMI_TD_7822991_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7719503_output("tbl_JOIN_INNER_TD_7719503_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_7719503_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_794456_output("tbl_JOIN_LEFTSEMI_TD_794456_output", 6100000, 2, "");
    tbl_JOIN_LEFTSEMI_TD_794456_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8980338_output("tbl_JOIN_INNER_TD_8980338_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_8980338_output.allocateHost();
    Table tbl_Filter_TD_8267550_output("tbl_Filter_TD_8267550_output", 6100000, 1, "");
    tbl_Filter_TD_8267550_output.allocateHost();
    Table tbl_Filter_TD_876093_output("tbl_Filter_TD_876093_output", 6100000, 2, "");
    tbl_Filter_TD_876093_output.allocateHost();
    Table tbl_Filter_TD_8719793_output("tbl_Filter_TD_8719793_output", 6100000, 1, "");
    tbl_Filter_TD_8719793_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8251745_output("tbl_JOIN_INNER_TD_8251745_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_8251745_output.allocateHost();
    Table tbl_Filter_TD_8836925_output("tbl_Filter_TD_8836925_output", 6100000, 1, "");
    tbl_Filter_TD_8836925_output.allocateHost();
    Table tbl_Filter_TD_8631630_output("tbl_Filter_TD_8631630_output", 6100000, 2, "");
    tbl_Filter_TD_8631630_output.allocateHost();
    Table tbl_Filter_TD_8125778_output("tbl_Filter_TD_8125778_output", 6100000, 1, "");
    tbl_Filter_TD_8125778_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8846061_output("tbl_JOIN_INNER_TD_8846061_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_8846061_output.allocateHost();
    Table tbl_Filter_TD_8312215_output("tbl_Filter_TD_8312215_output", 6100000, 1, "");
    tbl_Filter_TD_8312215_output.allocateHost();
    Table tbl_Filter_TD_864645_output("tbl_Filter_TD_864645_output", 6100000, 2, "");
    tbl_Filter_TD_864645_output.allocateHost();
    Table tbl_Filter_TD_8188749_output("tbl_Filter_TD_8188749_output", 6100000, 1, "");
    tbl_Filter_TD_8188749_output.allocateHost();
    Table tbl_Filter_TD_9373438_output("tbl_Filter_TD_9373438_output", 6100000, 4, "");
    tbl_Filter_TD_9373438_output.allocateHost();
    Table tbl_Filter_TD_9696288_output("tbl_Filter_TD_9696288_output", 6100000, 1, "");
    tbl_Filter_TD_9696288_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9327842_input;
    tbl_SerializeFromObject_TD_9327842_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9327842_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_9327842_input.addCol("ca_gmt_offset", 4);
    tbl_SerializeFromObject_TD_9327842_input.allocateHost();
    tbl_SerializeFromObject_TD_9327842_input.loadHost();
    Table tbl_SerializeFromObject_TD_9324260_input;
    tbl_SerializeFromObject_TD_9324260_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9324260_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_9324260_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9324260_input.allocateHost();
    tbl_SerializeFromObject_TD_9324260_input.loadHost();
    Table tbl_SerializeFromObject_TD_9760548_input;
    tbl_SerializeFromObject_TD_9760548_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9760548_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9760548_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9760548_input.allocateHost();
    tbl_SerializeFromObject_TD_9760548_input.loadHost();
    Table tbl_Filter_TD_9573092_output("tbl_Filter_TD_9573092_output", 6100000, 4, "");
    tbl_Filter_TD_9573092_output.allocateHost();
    Table tbl_Filter_TD_9921276_output("tbl_Filter_TD_9921276_output", 6100000, 1, "");
    tbl_Filter_TD_9921276_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9982138_input;
    tbl_SerializeFromObject_TD_9982138_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9982138_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_9982138_input.addCol("ca_gmt_offset", 4);
    tbl_SerializeFromObject_TD_9982138_input.allocateHost();
    tbl_SerializeFromObject_TD_9982138_input.loadHost();
    Table tbl_SerializeFromObject_TD_9316845_input;
    tbl_SerializeFromObject_TD_9316845_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9316845_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_9316845_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9316845_input.allocateHost();
    tbl_SerializeFromObject_TD_9316845_input.loadHost();
    Table tbl_SerializeFromObject_TD_9396460_input;
    tbl_SerializeFromObject_TD_9396460_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9396460_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9396460_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9396460_input.allocateHost();
    tbl_SerializeFromObject_TD_9396460_input.loadHost();
    Table tbl_Filter_TD_9848935_output("tbl_Filter_TD_9848935_output", 6100000, 4, "");
    tbl_Filter_TD_9848935_output.allocateHost();
    Table tbl_Filter_TD_9905864_output("tbl_Filter_TD_9905864_output", 6100000, 1, "");
    tbl_Filter_TD_9905864_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9208467_input;
    tbl_SerializeFromObject_TD_9208467_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9208467_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_9208467_input.addCol("ca_gmt_offset", 4);
    tbl_SerializeFromObject_TD_9208467_input.allocateHost();
    tbl_SerializeFromObject_TD_9208467_input.loadHost();
    Table tbl_SerializeFromObject_TD_9274214_input;
    tbl_SerializeFromObject_TD_9274214_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9274214_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_9274214_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9274214_input.allocateHost();
    tbl_SerializeFromObject_TD_9274214_input.loadHost();
    Table tbl_SerializeFromObject_TD_9187609_input;
    tbl_SerializeFromObject_TD_9187609_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9187609_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9187609_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9187609_input.allocateHost();
    tbl_SerializeFromObject_TD_9187609_input.loadHost();
    Table tbl_SerializeFromObject_TD_10408232_input;
    tbl_SerializeFromObject_TD_10408232_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_10408232_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10408232_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_10408232_input.addCol("ss_addr_sk", 4);
    tbl_SerializeFromObject_TD_10408232_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_10408232_input.allocateHost();
    tbl_SerializeFromObject_TD_10408232_input.loadHost();
    Table tbl_SerializeFromObject_TD_10428004_input;
    tbl_SerializeFromObject_TD_10428004_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10428004_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10428004_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10428004_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_10428004_input.allocateHost();
    tbl_SerializeFromObject_TD_10428004_input.loadHost();
    Table tbl_SerializeFromObject_TD_1079370_input;
    tbl_SerializeFromObject_TD_1079370_input = Table("catalog_sales", catalog_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_1079370_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_1079370_input.addCol("cs_bill_addr_sk", 4);
    tbl_SerializeFromObject_TD_1079370_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_1079370_input.addCol("cs_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_1079370_input.allocateHost();
    tbl_SerializeFromObject_TD_1079370_input.loadHost();
    Table tbl_SerializeFromObject_TD_10452129_input;
    tbl_SerializeFromObject_TD_10452129_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10452129_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10452129_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10452129_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_10452129_input.allocateHost();
    tbl_SerializeFromObject_TD_10452129_input.loadHost();
    Table tbl_SerializeFromObject_TD_10881630_input;
    tbl_SerializeFromObject_TD_10881630_input = Table("web_sales", web_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_10881630_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10881630_input.addCol("ws_item_sk", 4);
    tbl_SerializeFromObject_TD_10881630_input.addCol("ws_bill_addr_sk", 4);
    tbl_SerializeFromObject_TD_10881630_input.addCol("ws_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_10881630_input.allocateHost();
    tbl_SerializeFromObject_TD_10881630_input.loadHost();
    Table tbl_SerializeFromObject_TD_10676252_input;
    tbl_SerializeFromObject_TD_10676252_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10676252_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10676252_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10676252_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_10676252_input.allocateHost();
    tbl_SerializeFromObject_TD_10676252_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_7798154_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_7858959_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_7719503_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8980338_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8267550_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8251745_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8836925_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8846061_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8312215_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9373438_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9696288_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9573092_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9921276_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9848935_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9905864_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_7798154_cmds;
    cfg_JOIN_INNER_TD_7798154_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7798154_gqe_join (cfg_JOIN_INNER_TD_7798154_cmds.cmd);
    cfg_JOIN_INNER_TD_7798154_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7858959_cmds;
    cfg_JOIN_INNER_TD_7858959_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7858959_gqe_join (cfg_JOIN_INNER_TD_7858959_cmds.cmd);
    cfg_JOIN_INNER_TD_7858959_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7719503_cmds;
    cfg_JOIN_INNER_TD_7719503_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7719503_gqe_join (cfg_JOIN_INNER_TD_7719503_cmds.cmd);
    cfg_JOIN_INNER_TD_7719503_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8980338_cmds;
    cfg_JOIN_INNER_TD_8980338_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8980338_gqe_join (cfg_JOIN_INNER_TD_8980338_cmds.cmd);
    cfg_JOIN_INNER_TD_8980338_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8251745_cmds;
    cfg_JOIN_INNER_TD_8251745_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8251745_gqe_join (cfg_JOIN_INNER_TD_8251745_cmds.cmd);
    cfg_JOIN_INNER_TD_8251745_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8846061_cmds;
    cfg_JOIN_INNER_TD_8846061_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8846061_gqe_join (cfg_JOIN_INNER_TD_8846061_cmds.cmd);
    cfg_JOIN_INNER_TD_8846061_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_7798154;
    krnl_JOIN_INNER_TD_7798154 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7798154.setup(tbl_JOIN_INNER_TD_8980338_output, tbl_Filter_TD_8267550_output, tbl_JOIN_INNER_TD_7798154_output, cfg_JOIN_INNER_TD_7798154_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_7858959;
    krnl_JOIN_INNER_TD_7858959 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7858959.setup(tbl_JOIN_INNER_TD_8251745_output, tbl_Filter_TD_8836925_output, tbl_JOIN_INNER_TD_7858959_output, cfg_JOIN_INNER_TD_7858959_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_7719503;
    krnl_JOIN_INNER_TD_7719503 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7719503.setup(tbl_JOIN_INNER_TD_8846061_output, tbl_Filter_TD_8312215_output, tbl_JOIN_INNER_TD_7719503_output, cfg_JOIN_INNER_TD_7719503_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_8980338;
    krnl_JOIN_INNER_TD_8980338 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8980338.setup(tbl_Filter_TD_9373438_output, tbl_Filter_TD_9696288_output, tbl_JOIN_INNER_TD_8980338_output, cfg_JOIN_INNER_TD_8980338_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_8251745;
    krnl_JOIN_INNER_TD_8251745 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8251745.setup(tbl_Filter_TD_9573092_output, tbl_Filter_TD_9921276_output, tbl_JOIN_INNER_TD_8251745_output, cfg_JOIN_INNER_TD_8251745_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_8846061;
    krnl_JOIN_INNER_TD_8846061 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8846061.setup(tbl_Filter_TD_9848935_output, tbl_Filter_TD_9905864_output, tbl_JOIN_INNER_TD_8846061_output, cfg_JOIN_INNER_TD_8846061_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_7798154;
    trans_JOIN_INNER_TD_7798154.setq(q_h);
    trans_JOIN_INNER_TD_7798154.add(&(cfg_JOIN_INNER_TD_7798154_cmds));
    transEngine trans_JOIN_INNER_TD_7798154_out;
    trans_JOIN_INNER_TD_7798154_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_7858959;
    trans_JOIN_INNER_TD_7858959.setq(q_h);
    trans_JOIN_INNER_TD_7858959.add(&(cfg_JOIN_INNER_TD_7858959_cmds));
    transEngine trans_JOIN_INNER_TD_7858959_out;
    trans_JOIN_INNER_TD_7858959_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_7719503;
    trans_JOIN_INNER_TD_7719503.setq(q_h);
    trans_JOIN_INNER_TD_7719503.add(&(cfg_JOIN_INNER_TD_7719503_cmds));
    transEngine trans_JOIN_INNER_TD_7719503_out;
    trans_JOIN_INNER_TD_7719503_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_8980338;
    trans_JOIN_INNER_TD_8980338.setq(q_h);
    trans_JOIN_INNER_TD_8980338.add(&(cfg_JOIN_INNER_TD_8980338_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_8251745;
    trans_JOIN_INNER_TD_8251745.setq(q_h);
    trans_JOIN_INNER_TD_8251745.add(&(cfg_JOIN_INNER_TD_8251745_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_8846061;
    trans_JOIN_INNER_TD_8846061.setq(q_h);
    trans_JOIN_INNER_TD_8846061.add(&(cfg_JOIN_INNER_TD_8846061_cmds));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7798154;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7798154;
    std::vector<cl::Event> events_JOIN_INNER_TD_7798154;
    events_h2d_wr_JOIN_INNER_TD_7798154.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7798154.resize(1);
    events_JOIN_INNER_TD_7798154.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7798154;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7798154;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7858959;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7858959;
    std::vector<cl::Event> events_JOIN_INNER_TD_7858959;
    events_h2d_wr_JOIN_INNER_TD_7858959.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7858959.resize(1);
    events_JOIN_INNER_TD_7858959.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7858959;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7858959;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7719503;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7719503;
    std::vector<cl::Event> events_JOIN_INNER_TD_7719503;
    events_h2d_wr_JOIN_INNER_TD_7719503.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7719503.resize(1);
    events_JOIN_INNER_TD_7719503.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7719503;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7719503;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8980338;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8980338;
    std::vector<cl::Event> events_JOIN_INNER_TD_8980338;
    events_h2d_wr_JOIN_INNER_TD_8980338.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8980338.resize(1);
    events_JOIN_INNER_TD_8980338.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8980338;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8980338;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8251745;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8251745;
    std::vector<cl::Event> events_JOIN_INNER_TD_8251745;
    events_h2d_wr_JOIN_INNER_TD_8251745.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8251745.resize(1);
    events_JOIN_INNER_TD_8251745.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8251745;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8251745;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8846061;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8846061;
    std::vector<cl::Event> events_JOIN_INNER_TD_8846061;
    events_h2d_wr_JOIN_INNER_TD_8846061.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8846061.resize(1);
    events_JOIN_INNER_TD_8846061.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8846061;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8846061;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_9_155516_s, tv_r_Filter_9_155516_e;
    gettimeofday(&tv_r_Filter_9_155516_s, 0);
    SW_Filter_TD_9905864(tbl_SerializeFromObject_TD_10676252_input, tbl_Filter_TD_9905864_output);
    gettimeofday(&tv_r_Filter_9_155516_e, 0);

    struct timeval tv_r_Filter_9_749346_s, tv_r_Filter_9_749346_e;
    gettimeofday(&tv_r_Filter_9_749346_s, 0);
    SW_Filter_TD_9848935(tbl_SerializeFromObject_TD_10881630_input, tbl_Filter_TD_9848935_output);
    gettimeofday(&tv_r_Filter_9_749346_e, 0);

    struct timeval tv_r_Filter_9_753059_s, tv_r_Filter_9_753059_e;
    gettimeofday(&tv_r_Filter_9_753059_s, 0);
    SW_Filter_TD_9921276(tbl_SerializeFromObject_TD_10452129_input, tbl_Filter_TD_9921276_output);
    gettimeofday(&tv_r_Filter_9_753059_e, 0);

    struct timeval tv_r_Filter_9_732549_s, tv_r_Filter_9_732549_e;
    gettimeofday(&tv_r_Filter_9_732549_s, 0);
    SW_Filter_TD_9573092(tbl_SerializeFromObject_TD_1079370_input, tbl_Filter_TD_9573092_output);
    gettimeofday(&tv_r_Filter_9_732549_e, 0);

    struct timeval tv_r_Filter_9_711538_s, tv_r_Filter_9_711538_e;
    gettimeofday(&tv_r_Filter_9_711538_s, 0);
    SW_Filter_TD_9696288(tbl_SerializeFromObject_TD_10428004_input, tbl_Filter_TD_9696288_output);
    gettimeofday(&tv_r_Filter_9_711538_e, 0);

    struct timeval tv_r_Filter_9_254502_s, tv_r_Filter_9_254502_e;
    gettimeofday(&tv_r_Filter_9_254502_s, 0);
    SW_Filter_TD_9373438(tbl_SerializeFromObject_TD_10408232_input, tbl_Filter_TD_9373438_output);
    gettimeofday(&tv_r_Filter_9_254502_e, 0);

    struct timeval tv_r_Filter_8_855269_s, tv_r_Filter_8_855269_e;
    gettimeofday(&tv_r_Filter_8_855269_s, 0);
    SW_Filter_TD_8188749(tbl_SerializeFromObject_TD_9187609_input, tbl_Filter_TD_8188749_output);
    gettimeofday(&tv_r_Filter_8_855269_e, 0);

    struct timeval tv_r_Filter_8_785208_s, tv_r_Filter_8_785208_e;
    gettimeofday(&tv_r_Filter_8_785208_s, 0);
    SW_Filter_TD_864645(tbl_SerializeFromObject_TD_9274214_input, tbl_Filter_TD_864645_output);
    gettimeofday(&tv_r_Filter_8_785208_e, 0);

    struct timeval tv_r_Filter_8_199913_s, tv_r_Filter_8_199913_e;
    gettimeofday(&tv_r_Filter_8_199913_s, 0);
    SW_Filter_TD_8312215(tbl_SerializeFromObject_TD_9208467_input, tbl_Filter_TD_8312215_output);
    gettimeofday(&tv_r_Filter_8_199913_e, 0);

    struct timeval tv_r_JOIN_INNER_8_735231_s, tv_r_JOIN_INNER_8_735231_e;
    gettimeofday(&tv_r_JOIN_INNER_8_735231_s, 0);
    trans_JOIN_INNER_TD_8846061.add(&(tbl_Filter_TD_9848935_output));
    trans_JOIN_INNER_TD_8846061.add(&(tbl_Filter_TD_9905864_output));
    trans_JOIN_INNER_TD_8846061.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8846061), &(events_h2d_wr_JOIN_INNER_TD_8846061[0]));
    events_grp_JOIN_INNER_TD_8846061.push_back(events_h2d_wr_JOIN_INNER_TD_8846061[0]);
    krnl_JOIN_INNER_TD_8846061.run(0, &(events_grp_JOIN_INNER_TD_8846061), &(events_JOIN_INNER_TD_8846061[0]));
    gettimeofday(&tv_r_JOIN_INNER_8_735231_e, 0);

    struct timeval tv_r_Filter_8_810885_s, tv_r_Filter_8_810885_e;
    gettimeofday(&tv_r_Filter_8_810885_s, 0);
    SW_Filter_TD_8125778(tbl_SerializeFromObject_TD_9396460_input, tbl_Filter_TD_8125778_output);
    gettimeofday(&tv_r_Filter_8_810885_e, 0);

    struct timeval tv_r_Filter_8_228357_s, tv_r_Filter_8_228357_e;
    gettimeofday(&tv_r_Filter_8_228357_s, 0);
    SW_Filter_TD_8631630(tbl_SerializeFromObject_TD_9316845_input, tbl_Filter_TD_8631630_output);
    gettimeofday(&tv_r_Filter_8_228357_e, 0);

    struct timeval tv_r_Filter_8_832928_s, tv_r_Filter_8_832928_e;
    gettimeofday(&tv_r_Filter_8_832928_s, 0);
    SW_Filter_TD_8836925(tbl_SerializeFromObject_TD_9982138_input, tbl_Filter_TD_8836925_output);
    gettimeofday(&tv_r_Filter_8_832928_e, 0);

    struct timeval tv_r_JOIN_INNER_8_366468_s, tv_r_JOIN_INNER_8_366468_e;
    gettimeofday(&tv_r_JOIN_INNER_8_366468_s, 0);
    trans_JOIN_INNER_TD_8251745.add(&(tbl_Filter_TD_9573092_output));
    trans_JOIN_INNER_TD_8251745.add(&(tbl_Filter_TD_9921276_output));
    trans_JOIN_INNER_TD_8251745.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8251745), &(events_h2d_wr_JOIN_INNER_TD_8251745[0]));
    events_grp_JOIN_INNER_TD_8251745.push_back(events_h2d_wr_JOIN_INNER_TD_8251745[0]);
    krnl_JOIN_INNER_TD_8251745.run(0, &(events_grp_JOIN_INNER_TD_8251745), &(events_JOIN_INNER_TD_8251745[0]));
    gettimeofday(&tv_r_JOIN_INNER_8_366468_e, 0);

    struct timeval tv_r_Filter_8_449509_s, tv_r_Filter_8_449509_e;
    gettimeofday(&tv_r_Filter_8_449509_s, 0);
    SW_Filter_TD_8719793(tbl_SerializeFromObject_TD_9760548_input, tbl_Filter_TD_8719793_output);
    gettimeofday(&tv_r_Filter_8_449509_e, 0);

    struct timeval tv_r_Filter_8_372699_s, tv_r_Filter_8_372699_e;
    gettimeofday(&tv_r_Filter_8_372699_s, 0);
    SW_Filter_TD_876093(tbl_SerializeFromObject_TD_9324260_input, tbl_Filter_TD_876093_output);
    gettimeofday(&tv_r_Filter_8_372699_e, 0);

    struct timeval tv_r_Filter_8_782797_s, tv_r_Filter_8_782797_e;
    gettimeofday(&tv_r_Filter_8_782797_s, 0);
    SW_Filter_TD_8267550(tbl_SerializeFromObject_TD_9327842_input, tbl_Filter_TD_8267550_output);
    gettimeofday(&tv_r_Filter_8_782797_e, 0);

    struct timeval tv_r_JOIN_INNER_8_959640_s, tv_r_JOIN_INNER_8_959640_e;
    gettimeofday(&tv_r_JOIN_INNER_8_959640_s, 0);
    trans_JOIN_INNER_TD_8980338.add(&(tbl_Filter_TD_9373438_output));
    trans_JOIN_INNER_TD_8980338.add(&(tbl_Filter_TD_9696288_output));
    trans_JOIN_INNER_TD_8980338.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8980338), &(events_h2d_wr_JOIN_INNER_TD_8980338[0]));
    events_grp_JOIN_INNER_TD_8980338.push_back(events_h2d_wr_JOIN_INNER_TD_8980338[0]);
    krnl_JOIN_INNER_TD_8980338.run(0, &(events_grp_JOIN_INNER_TD_8980338), &(events_JOIN_INNER_TD_8980338[0]));
    gettimeofday(&tv_r_JOIN_INNER_8_959640_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_7_771030_s, tv_r_JOIN_LEFTSEMI_7_771030_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_771030_s, 0);
    SW_JOIN_LEFTSEMI_TD_794456(tbl_Filter_TD_864645_output, tbl_Filter_TD_8188749_output, tbl_JOIN_LEFTSEMI_TD_794456_output);
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_771030_e, 0);

    struct timeval tv_r_JOIN_INNER_7_331247_s, tv_r_JOIN_INNER_7_331247_e;
    gettimeofday(&tv_r_JOIN_INNER_7_331247_s, 0);
    prev_events_grp_JOIN_INNER_TD_7719503.push_back(events_h2d_wr_JOIN_INNER_TD_8846061[0]);
    trans_JOIN_INNER_TD_7719503.add(&(tbl_Filter_TD_8312215_output));
    trans_JOIN_INNER_TD_7719503.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7719503), &(events_h2d_wr_JOIN_INNER_TD_7719503[0]));
    events_grp_JOIN_INNER_TD_7719503.push_back(events_h2d_wr_JOIN_INNER_TD_7719503[0]);
    events_grp_JOIN_INNER_TD_7719503.push_back(events_JOIN_INNER_TD_8846061[0]);
    krnl_JOIN_INNER_TD_7719503.run(0, &(events_grp_JOIN_INNER_TD_7719503), &(events_JOIN_INNER_TD_7719503[0]));
    
    trans_JOIN_INNER_TD_7719503_out.add(&(tbl_JOIN_INNER_TD_7719503_output));
    trans_JOIN_INNER_TD_7719503_out.dev2host(0, &(events_JOIN_INNER_TD_7719503), &(events_d2h_rd_JOIN_INNER_TD_7719503[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_7_331247_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_7_661022_s, tv_r_JOIN_LEFTSEMI_7_661022_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_661022_s, 0);
    SW_JOIN_LEFTSEMI_TD_7822991(tbl_Filter_TD_8631630_output, tbl_Filter_TD_8125778_output, tbl_JOIN_LEFTSEMI_TD_7822991_output);
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_661022_e, 0);

    struct timeval tv_r_JOIN_INNER_7_287104_s, tv_r_JOIN_INNER_7_287104_e;
    gettimeofday(&tv_r_JOIN_INNER_7_287104_s, 0);
    prev_events_grp_JOIN_INNER_TD_7858959.push_back(events_h2d_wr_JOIN_INNER_TD_8251745[0]);
    trans_JOIN_INNER_TD_7858959.add(&(tbl_Filter_TD_8836925_output));
    trans_JOIN_INNER_TD_7858959.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7858959), &(events_h2d_wr_JOIN_INNER_TD_7858959[0]));
    events_grp_JOIN_INNER_TD_7858959.push_back(events_h2d_wr_JOIN_INNER_TD_7858959[0]);
    events_grp_JOIN_INNER_TD_7858959.push_back(events_JOIN_INNER_TD_8251745[0]);
    krnl_JOIN_INNER_TD_7858959.run(0, &(events_grp_JOIN_INNER_TD_7858959), &(events_JOIN_INNER_TD_7858959[0]));
    
    trans_JOIN_INNER_TD_7858959_out.add(&(tbl_JOIN_INNER_TD_7858959_output));
    trans_JOIN_INNER_TD_7858959_out.dev2host(0, &(events_JOIN_INNER_TD_7858959), &(events_d2h_rd_JOIN_INNER_TD_7858959[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_7_287104_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_7_83059_s, tv_r_JOIN_LEFTSEMI_7_83059_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_83059_s, 0);
    SW_JOIN_LEFTSEMI_TD_7600525(tbl_Filter_TD_876093_output, tbl_Filter_TD_8719793_output, tbl_JOIN_LEFTSEMI_TD_7600525_output);
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_83059_e, 0);

    struct timeval tv_r_JOIN_INNER_7_151778_s, tv_r_JOIN_INNER_7_151778_e;
    gettimeofday(&tv_r_JOIN_INNER_7_151778_s, 0);
    prev_events_grp_JOIN_INNER_TD_7798154.push_back(events_h2d_wr_JOIN_INNER_TD_8980338[0]);
    trans_JOIN_INNER_TD_7798154.add(&(tbl_Filter_TD_8267550_output));
    trans_JOIN_INNER_TD_7798154.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7798154), &(events_h2d_wr_JOIN_INNER_TD_7798154[0]));
    events_grp_JOIN_INNER_TD_7798154.push_back(events_h2d_wr_JOIN_INNER_TD_7798154[0]);
    events_grp_JOIN_INNER_TD_7798154.push_back(events_JOIN_INNER_TD_8980338[0]);
    krnl_JOIN_INNER_TD_7798154.run(0, &(events_grp_JOIN_INNER_TD_7798154), &(events_JOIN_INNER_TD_7798154[0]));
    
    trans_JOIN_INNER_TD_7798154_out.add(&(tbl_JOIN_INNER_TD_7798154_output));
    trans_JOIN_INNER_TD_7798154_out.dev2host(0, &(events_JOIN_INNER_TD_7798154), &(events_d2h_rd_JOIN_INNER_TD_7798154[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_7_151778_e, 0);

    struct timeval tv_r_JOIN_INNER_6_980570_s, tv_r_JOIN_INNER_6_980570_e;
    gettimeofday(&tv_r_JOIN_INNER_6_980570_s, 0);
    SW_JOIN_INNER_TD_6561024(tbl_JOIN_INNER_TD_7719503_output, tbl_JOIN_LEFTSEMI_TD_794456_output, tbl_JOIN_INNER_TD_6561024_output);
    gettimeofday(&tv_r_JOIN_INNER_6_980570_e, 0);

    struct timeval tv_r_JOIN_INNER_6_15270_s, tv_r_JOIN_INNER_6_15270_e;
    gettimeofday(&tv_r_JOIN_INNER_6_15270_s, 0);
    SW_JOIN_INNER_TD_6260223(tbl_JOIN_INNER_TD_7858959_output, tbl_JOIN_LEFTSEMI_TD_7822991_output, tbl_JOIN_INNER_TD_6260223_output);
    gettimeofday(&tv_r_JOIN_INNER_6_15270_e, 0);

    struct timeval tv_r_JOIN_INNER_6_58315_s, tv_r_JOIN_INNER_6_58315_e;
    gettimeofday(&tv_r_JOIN_INNER_6_58315_s, 0);
    SW_JOIN_INNER_TD_6520657(tbl_JOIN_INNER_TD_7798154_output, tbl_JOIN_LEFTSEMI_TD_7600525_output, tbl_JOIN_INNER_TD_6520657_output);
    gettimeofday(&tv_r_JOIN_INNER_6_58315_e, 0);

    struct timeval tv_r_Aggregate_5_770960_s, tv_r_Aggregate_5_770960_e;
    gettimeofday(&tv_r_Aggregate_5_770960_s, 0);
    SW_Aggregate_TD_5792815(tbl_JOIN_INNER_TD_6561024_output, tbl_Aggregate_TD_5792815_output);
    gettimeofday(&tv_r_Aggregate_5_770960_e, 0);

    struct timeval tv_r_Aggregate_5_256870_s, tv_r_Aggregate_5_256870_e;
    gettimeofday(&tv_r_Aggregate_5_256870_s, 0);
    SW_Aggregate_TD_5617076(tbl_JOIN_INNER_TD_6260223_output, tbl_Aggregate_TD_5617076_output);
    gettimeofday(&tv_r_Aggregate_5_256870_e, 0);

    struct timeval tv_r_Aggregate_5_550249_s, tv_r_Aggregate_5_550249_e;
    gettimeofday(&tv_r_Aggregate_5_550249_s, 0);
    SW_Aggregate_TD_5879177(tbl_JOIN_INNER_TD_6520657_output, tbl_Aggregate_TD_5879177_output);
    gettimeofday(&tv_r_Aggregate_5_550249_e, 0);

    struct timeval tv_r_Union_4_926582_s, tv_r_Union_4_926582_e;
    gettimeofday(&tv_r_Union_4_926582_s, 0);
    SW_Union_TD_4612144(tbl_Aggregate_TD_5879177_output, tbl_Aggregate_TD_5617076_output, tbl_Aggregate_TD_5792815_output, tbl_Union_TD_4612144_output);
    gettimeofday(&tv_r_Union_4_926582_e, 0);

    struct timeval tv_r_Aggregate_3_615988_s, tv_r_Aggregate_3_615988_e;
    gettimeofday(&tv_r_Aggregate_3_615988_s, 0);
    SW_Aggregate_TD_3933724(tbl_Union_TD_4612144_output, tbl_Aggregate_TD_3933724_output);
    gettimeofday(&tv_r_Aggregate_3_615988_e, 0);

    struct timeval tv_r_Sort_2_716580_s, tv_r_Sort_2_716580_e;
    gettimeofday(&tv_r_Sort_2_716580_s, 0);
    SW_Sort_TD_2924655(tbl_Aggregate_TD_3933724_output, tbl_Sort_TD_2924655_output);
    gettimeofday(&tv_r_Sort_2_716580_e, 0);

    struct timeval tv_r_LocalLimit_1_164703_s, tv_r_LocalLimit_1_164703_e;
    gettimeofday(&tv_r_LocalLimit_1_164703_s, 0);
    SW_LocalLimit_TD_1867169(tbl_Sort_TD_2924655_output, tbl_LocalLimit_TD_1867169_output);
    gettimeofday(&tv_r_LocalLimit_1_164703_e, 0);

    struct timeval tv_r_GlobalLimit_0_836360_s, tv_r_GlobalLimit_0_836360_e;
    gettimeofday(&tv_r_GlobalLimit_0_836360_s, 0);
    SW_GlobalLimit_TD_0799225(tbl_LocalLimit_TD_1867169_output, tbl_GlobalLimit_TD_0799225_output);
    gettimeofday(&tv_r_GlobalLimit_0_836360_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_155516_s, &tv_r_Filter_9_155516_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10676252_input: " << tbl_SerializeFromObject_TD_10676252_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_749346_s, &tv_r_Filter_9_749346_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10881630_input: " << tbl_SerializeFromObject_TD_10881630_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_753059_s, &tv_r_Filter_9_753059_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10452129_input: " << tbl_SerializeFromObject_TD_10452129_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_732549_s, &tv_r_Filter_9_732549_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1079370_input: " << tbl_SerializeFromObject_TD_1079370_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_711538_s, &tv_r_Filter_9_711538_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10428004_input: " << tbl_SerializeFromObject_TD_10428004_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_254502_s, &tv_r_Filter_9_254502_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10408232_input: " << tbl_SerializeFromObject_TD_10408232_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_855269_s, &tv_r_Filter_8_855269_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9187609_input: " << tbl_SerializeFromObject_TD_9187609_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_785208_s, &tv_r_Filter_8_785208_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9274214_input: " << tbl_SerializeFromObject_TD_9274214_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_199913_s, &tv_r_Filter_8_199913_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9208467_input: " << tbl_SerializeFromObject_TD_9208467_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_735231_s, &tv_r_JOIN_INNER_8_735231_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9848935_output: " << tbl_Filter_TD_9848935_output.getNumRow() << " " << "tbl_Filter_TD_9905864_output: " << tbl_Filter_TD_9905864_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_810885_s, &tv_r_Filter_8_810885_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9396460_input: " << tbl_SerializeFromObject_TD_9396460_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_228357_s, &tv_r_Filter_8_228357_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9316845_input: " << tbl_SerializeFromObject_TD_9316845_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_832928_s, &tv_r_Filter_8_832928_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9982138_input: " << tbl_SerializeFromObject_TD_9982138_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_366468_s, &tv_r_JOIN_INNER_8_366468_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9573092_output: " << tbl_Filter_TD_9573092_output.getNumRow() << " " << "tbl_Filter_TD_9921276_output: " << tbl_Filter_TD_9921276_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_449509_s, &tv_r_Filter_8_449509_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9760548_input: " << tbl_SerializeFromObject_TD_9760548_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_372699_s, &tv_r_Filter_8_372699_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9324260_input: " << tbl_SerializeFromObject_TD_9324260_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_782797_s, &tv_r_Filter_8_782797_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9327842_input: " << tbl_SerializeFromObject_TD_9327842_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_959640_s, &tv_r_JOIN_INNER_8_959640_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9373438_output: " << tbl_Filter_TD_9373438_output.getNumRow() << " " << "tbl_Filter_TD_9696288_output: " << tbl_Filter_TD_9696288_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_7: " << tvdiff(&tv_r_JOIN_LEFTSEMI_7_771030_s, &tv_r_JOIN_LEFTSEMI_7_771030_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_864645_output: " << tbl_Filter_TD_864645_output.getNumRow() << " " << "tbl_Filter_TD_8188749_output: " << tbl_Filter_TD_8188749_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_331247_s, &tv_r_JOIN_INNER_7_331247_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8846061_output: " << tbl_JOIN_INNER_TD_8846061_output.getNumRow() << " " << "tbl_Filter_TD_8312215_output: " << tbl_Filter_TD_8312215_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_7: " << tvdiff(&tv_r_JOIN_LEFTSEMI_7_661022_s, &tv_r_JOIN_LEFTSEMI_7_661022_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8631630_output: " << tbl_Filter_TD_8631630_output.getNumRow() << " " << "tbl_Filter_TD_8125778_output: " << tbl_Filter_TD_8125778_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_287104_s, &tv_r_JOIN_INNER_7_287104_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8251745_output: " << tbl_JOIN_INNER_TD_8251745_output.getNumRow() << " " << "tbl_Filter_TD_8836925_output: " << tbl_Filter_TD_8836925_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_7: " << tvdiff(&tv_r_JOIN_LEFTSEMI_7_83059_s, &tv_r_JOIN_LEFTSEMI_7_83059_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_876093_output: " << tbl_Filter_TD_876093_output.getNumRow() << " " << "tbl_Filter_TD_8719793_output: " << tbl_Filter_TD_8719793_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_151778_s, &tv_r_JOIN_INNER_7_151778_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8980338_output: " << tbl_JOIN_INNER_TD_8980338_output.getNumRow() << " " << "tbl_Filter_TD_8267550_output: " << tbl_Filter_TD_8267550_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_980570_s, &tv_r_JOIN_INNER_6_980570_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7719503_output: " << tbl_JOIN_INNER_TD_7719503_output.getNumRow() << " " << "tbl_JOIN_LEFTSEMI_TD_794456_output: " << tbl_JOIN_LEFTSEMI_TD_794456_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_15270_s, &tv_r_JOIN_INNER_6_15270_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7858959_output: " << tbl_JOIN_INNER_TD_7858959_output.getNumRow() << " " << "tbl_JOIN_LEFTSEMI_TD_7822991_output: " << tbl_JOIN_LEFTSEMI_TD_7822991_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_58315_s, &tv_r_JOIN_INNER_6_58315_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7798154_output: " << tbl_JOIN_INNER_TD_7798154_output.getNumRow() << " " << "tbl_JOIN_LEFTSEMI_TD_7600525_output: " << tbl_JOIN_LEFTSEMI_TD_7600525_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_770960_s, &tv_r_Aggregate_5_770960_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6561024_output: " << tbl_JOIN_INNER_TD_6561024_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_256870_s, &tv_r_Aggregate_5_256870_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6260223_output: " << tbl_JOIN_INNER_TD_6260223_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_550249_s, &tv_r_Aggregate_5_550249_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6520657_output: " << tbl_JOIN_INNER_TD_6520657_output.getNumRow() << " " << std::endl; 

    std::cout << "Union_4: " << tvdiff(&tv_r_Union_4_926582_s, &tv_r_Union_4_926582_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_5879177_output: " << tbl_Aggregate_TD_5879177_output.getNumRow() << " " << "tbl_Aggregate_TD_5617076_output: " << tbl_Aggregate_TD_5617076_output.getNumRow() << " " << "tbl_Aggregate_TD_5792815_output: " << tbl_Aggregate_TD_5792815_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_615988_s, &tv_r_Aggregate_3_615988_e) / 1000.0 << " ms " 
     << "tbl_Union_TD_4612144_output: " << tbl_Union_TD_4612144_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_716580_s, &tv_r_Sort_2_716580_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3933724_output: " << tbl_Aggregate_TD_3933724_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_164703_s, &tv_r_LocalLimit_1_164703_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2924655_output: " << tbl_Sort_TD_2924655_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_836360_s, &tv_r_GlobalLimit_0_836360_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1867169_output: " << tbl_LocalLimit_TD_1867169_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.4699354 * 1000 << "ms" << std::endl; 
    return 0; 
}
