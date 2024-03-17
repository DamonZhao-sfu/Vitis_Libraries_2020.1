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

#include "cfgFunc_q54.hpp" 
#include "q54.hpp" 

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
    std::cout << "NOTE:running query #54\n."; 
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
    Table tbl_GlobalLimit_TD_0179492_output("tbl_GlobalLimit_TD_0179492_output", 6100000, 3, "");
    tbl_GlobalLimit_TD_0179492_output.allocateHost();
    Table tbl_LocalLimit_TD_1325297_output("tbl_LocalLimit_TD_1325297_output", 6100000, 3, "");
    tbl_LocalLimit_TD_1325297_output.allocateHost();
    Table tbl_Sort_TD_2149954_output("tbl_Sort_TD_2149954_output", 6100000, 3, "");
    tbl_Sort_TD_2149954_output.allocateHost();
    Table tbl_Aggregate_TD_325302_output("tbl_Aggregate_TD_325302_output", 6100000, 3, "");
    tbl_Aggregate_TD_325302_output.allocateHost();
    Table tbl_Aggregate_TD_4795083_output_preprocess("tbl_Aggregate_TD_4795083_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_4795083_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_4795083_output("tbl_Aggregate_TD_4795083_output", 6100000, 1, "");
    tbl_Aggregate_TD_4795083_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5487086_output_preprocess("tbl_JOIN_INNER_TD_5487086_output_preprocess", 6100000, 2, "");
    tbl_JOIN_INNER_TD_5487086_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_5487086_output("tbl_JOIN_INNER_TD_5487086_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_5487086_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6724290_output("tbl_JOIN_INNER_TD_6724290_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_6724290_output.allocateHost();
    Table tbl_Filter_TD_6320172_output("tbl_Filter_TD_6320172_output", 6100000, 1, "");
    tbl_Filter_TD_6320172_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7928320_output("tbl_JOIN_INNER_TD_7928320_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_7928320_output.allocateHost();
    Table tbl_Filter_TD_7534451_output("tbl_Filter_TD_7534451_output", 6100000, 2, "");
    tbl_Filter_TD_7534451_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7371785_input;
    tbl_SerializeFromObject_TD_7371785_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7371785_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_7371785_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_7371785_input.allocateHost();
    tbl_SerializeFromObject_TD_7371785_input.loadHost();
    Table tbl_Aggregate_TD_7805576_output_preprocess("tbl_Aggregate_TD_7805576_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_7805576_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_7805576_output("tbl_Aggregate_TD_7805576_output", 6100000, 1, "");
    tbl_Aggregate_TD_7805576_output.allocateHost();
    Table tbl_Aggregate_TD_7521203_output_preprocess("tbl_Aggregate_TD_7521203_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_7521203_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_7521203_output("tbl_Aggregate_TD_7521203_output", 6100000, 1, "");
    tbl_Aggregate_TD_7521203_output.allocateHost();
    Table tbl_JOIN_INNER_TD_838624_output("tbl_JOIN_INNER_TD_838624_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_838624_output.allocateHost();
    Table tbl_Filter_TD_8729339_output("tbl_Filter_TD_8729339_output", 6100000, 3, "");
    tbl_Filter_TD_8729339_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8205186_input;
    tbl_SerializeFromObject_TD_8205186_input = Table("store", store_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8205186_input.addCol("s_county", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8205186_input.addCol("s_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8205186_input.allocateHost();
    tbl_SerializeFromObject_TD_8205186_input.loadHost();
    Table tbl_Project_TD_8400581_output("tbl_Project_TD_8400581_output", 6100000, 1, "");
    tbl_Project_TD_8400581_output.allocateHost();
    Table tbl_Project_TD_8876293_output("tbl_Project_TD_8876293_output", 6100000, 1, "");
    tbl_Project_TD_8876293_output.allocateHost();
    Table tbl_Aggregate_TD_9953648_output_preprocess("tbl_Aggregate_TD_9953648_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_9953648_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_9953648_output("tbl_Aggregate_TD_9953648_output", 6100000, 2, "");
    tbl_Aggregate_TD_9953648_output.allocateHost();
    Table tbl_Filter_TD_9845184_output("tbl_Filter_TD_9845184_output", 6100000, 3, "");
    tbl_Filter_TD_9845184_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9680138_input;
    tbl_SerializeFromObject_TD_9680138_input = Table("customer_address", customer_address_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9680138_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_9680138_input.addCol("ca_county", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9680138_input.addCol("ca_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9680138_input.allocateHost();
    tbl_SerializeFromObject_TD_9680138_input.loadHost();
    Table tbl_Filter_TD_9916711_output("tbl_Filter_TD_9916711_output", 6100000, 1, "");
    tbl_Filter_TD_9916711_output.allocateHost();
    Table tbl_Filter_TD_9679178_output("tbl_Filter_TD_9679178_output", 6100000, 1, "");
    tbl_Filter_TD_9679178_output.allocateHost();
    Table tbl_JOIN_INNER_TD_1077543_output_preprocess("tbl_JOIN_INNER_TD_1077543_output_preprocess", 6100000, 2, "");
    tbl_JOIN_INNER_TD_1077543_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_1077543_output("tbl_JOIN_INNER_TD_1077543_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_1077543_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10516255_input;
    tbl_SerializeFromObject_TD_10516255_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10516255_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10516255_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_10516255_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_10516255_input.allocateHost();
    tbl_SerializeFromObject_TD_10516255_input.loadHost();
    Table tbl_SerializeFromObject_TD_10746465_input;
    tbl_SerializeFromObject_TD_10746465_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10746465_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_10746465_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10746465_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_10746465_input.allocateHost();
    tbl_SerializeFromObject_TD_10746465_input.loadHost();
    Table tbl_SerializeFromObject_TD_10345680_input;
    tbl_SerializeFromObject_TD_10345680_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10345680_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_10345680_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10345680_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_10345680_input.allocateHost();
    tbl_SerializeFromObject_TD_10345680_input.loadHost();
    Table tbl_JOIN_INNER_TD_11589620_output("tbl_JOIN_INNER_TD_11589620_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_11589620_output.allocateHost();
    Table tbl_Filter_TD_11768305_output("tbl_Filter_TD_11768305_output", 6100000, 2, "");
    tbl_Filter_TD_11768305_output.allocateHost();
    Table tbl_JOIN_INNER_TD_12959194_output("tbl_JOIN_INNER_TD_12959194_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_12959194_output.allocateHost();
    Table tbl_Filter_TD_12895959_output("tbl_Filter_TD_12895959_output", 6100000, 1, "");
    tbl_Filter_TD_12895959_output.allocateHost();
    Table tbl_SerializeFromObject_TD_12107220_input;
    tbl_SerializeFromObject_TD_12107220_input = Table("customer", customer_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12107220_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_12107220_input.addCol("c_current_addr_sk", 4);
    tbl_SerializeFromObject_TD_12107220_input.allocateHost();
    tbl_SerializeFromObject_TD_12107220_input.loadHost();
    Table tbl_Union_TD_13712926_output("tbl_Union_TD_13712926_output", 6100000, 3, "");
    tbl_Union_TD_13712926_output.allocateHost();
    Table tbl_Filter_TD_13998184_output("tbl_Filter_TD_13998184_output", 6100000, 1, "");
    tbl_Filter_TD_13998184_output.allocateHost();
    Table tbl_SerializeFromObject_TD_1357148_input;
    tbl_SerializeFromObject_TD_1357148_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_1357148_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_1357148_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_1357148_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_1357148_input.allocateHost();
    tbl_SerializeFromObject_TD_1357148_input.loadHost();
    Table tbl_Project_TD_14575890_output("tbl_Project_TD_14575890_output", 6100000, 3, "");
    tbl_Project_TD_14575890_output.allocateHost();
    Table tbl_Project_TD_14411667_output("tbl_Project_TD_14411667_output", 6100000, 3, "");
    tbl_Project_TD_14411667_output.allocateHost();
    Table tbl_SerializeFromObject_TD_14698106_input;
    tbl_SerializeFromObject_TD_14698106_input = Table("item", item_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_14698106_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_14698106_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_14698106_input.addCol("i_class", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_14698106_input.allocateHost();
    tbl_SerializeFromObject_TD_14698106_input.loadHost();
    Table tbl_Filter_TD_15417386_output("tbl_Filter_TD_15417386_output", 6100000, 3, "");
    tbl_Filter_TD_15417386_output.allocateHost();
    Table tbl_Filter_TD_15942981_output("tbl_Filter_TD_15942981_output", 6100000, 3, "");
    tbl_Filter_TD_15942981_output.allocateHost();
    Table tbl_SerializeFromObject_TD_16713508_input;
    tbl_SerializeFromObject_TD_16713508_input = Table("catalog_sales", catalog_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_16713508_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_16713508_input.addCol("cs_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_16713508_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_16713508_input.allocateHost();
    tbl_SerializeFromObject_TD_16713508_input.loadHost();
    Table tbl_SerializeFromObject_TD_16194364_input;
    tbl_SerializeFromObject_TD_16194364_input = Table("web_sales", web_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_16194364_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_16194364_input.addCol("ws_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_16194364_input.addCol("ws_item_sk", 4);
    tbl_SerializeFromObject_TD_16194364_input.allocateHost();
    tbl_SerializeFromObject_TD_16194364_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_5487086_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_4795083_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_JOIN_INNER_TD_5487086_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_6724290_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_6320172_output.allocateDevBuffer(context_h, 32);
    tbl_Aggregate_TD_7805576_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_Aggregate_TD_7521203_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_JOIN_INNER_TD_838624_output.allocateDevBuffer(context_h, 32);
    tbl_Project_TD_8400581_output.allocateDevBuffer(context_a, 32);
    tbl_Project_TD_8876293_output.allocateDevBuffer(context_a, 32);
    tbl_JOIN_INNER_TD_1077543_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_9953648_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_Aggregate_TD_9953648_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9845184_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_1077543_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_11589620_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11768305_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_12959194_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_12895959_output.allocateDevBuffer(context_h, 32);
    tbl_Union_TD_13712926_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_13998184_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    AggrCfgCmd cfg_Aggregate_TD_4795083_cmds;
    cfg_Aggregate_TD_4795083_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_4795083_gqe_aggr(cfg_Aggregate_TD_4795083_cmds.cmd);
    cfg_Aggregate_TD_4795083_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_4795083_cmds_out;
    cfg_Aggregate_TD_4795083_cmds_out.allocateHost();
    cfg_Aggregate_TD_4795083_cmds_out.allocateDevBuffer(context_a, 33);
    cfgCmd cfg_JOIN_INNER_TD_5487086_cmds;
    cfg_JOIN_INNER_TD_5487086_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_5487086_gqe_join (cfg_JOIN_INNER_TD_5487086_cmds.cmd);
    cfg_JOIN_INNER_TD_5487086_cmds.allocateDevBuffer(context_h, 32);
    AggrCfgCmd cfg_Aggregate_TD_7805576_cmds;
    cfg_Aggregate_TD_7805576_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_7805576_gqe_aggr(cfg_Aggregate_TD_7805576_cmds.cmd);
    cfg_Aggregate_TD_7805576_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_7805576_cmds_out;
    cfg_Aggregate_TD_7805576_cmds_out.allocateHost();
    cfg_Aggregate_TD_7805576_cmds_out.allocateDevBuffer(context_a, 33);
    AggrCfgCmd cfg_Aggregate_TD_7521203_cmds;
    cfg_Aggregate_TD_7521203_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_7521203_gqe_aggr(cfg_Aggregate_TD_7521203_cmds.cmd);
    cfg_Aggregate_TD_7521203_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_7521203_cmds_out;
    cfg_Aggregate_TD_7521203_cmds_out.allocateHost();
    cfg_Aggregate_TD_7521203_cmds_out.allocateDevBuffer(context_a, 33);
    cfgCmd cfg_JOIN_INNER_TD_838624_cmds;
    cfg_JOIN_INNER_TD_838624_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_838624_gqe_join (cfg_JOIN_INNER_TD_838624_cmds.cmd);
    cfg_JOIN_INNER_TD_838624_cmds.allocateDevBuffer(context_h, 32);
    AggrCfgCmd cfg_Aggregate_TD_9953648_cmds;
    cfg_Aggregate_TD_9953648_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_9953648_gqe_aggr(cfg_Aggregate_TD_9953648_cmds.cmd);
    cfg_Aggregate_TD_9953648_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_9953648_cmds_out;
    cfg_Aggregate_TD_9953648_cmds_out.allocateHost();
    cfg_Aggregate_TD_9953648_cmds_out.allocateDevBuffer(context_a, 33);
    cfgCmd cfg_JOIN_INNER_TD_1077543_cmds;
    cfg_JOIN_INNER_TD_1077543_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_1077543_gqe_join (cfg_JOIN_INNER_TD_1077543_cmds.cmd);
    cfg_JOIN_INNER_TD_1077543_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_11589620_cmds;
    cfg_JOIN_INNER_TD_11589620_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_11589620_gqe_join (cfg_JOIN_INNER_TD_11589620_cmds.cmd);
    cfg_JOIN_INNER_TD_11589620_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_12959194_cmds;
    cfg_JOIN_INNER_TD_12959194_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_12959194_gqe_join (cfg_JOIN_INNER_TD_12959194_cmds.cmd);
    cfg_JOIN_INNER_TD_12959194_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    AggrBufferTmp buftmp_a(context_a); 
    buftmp_a.BufferInitial(q_a); 
    std::cout << std::endl; 
    AggrKrnlEngine krnl_Aggregate_TD_4795083;
    krnl_Aggregate_TD_4795083 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_4795083.setup(tbl_JOIN_INNER_TD_5487086_output, tbl_Aggregate_TD_4795083_output_preprocess, cfg_Aggregate_TD_4795083_cmds, cfg_Aggregate_TD_4795083_cmds_out, buftmp_a);
    krnlEngine krnl_JOIN_INNER_TD_5487086;
    krnl_JOIN_INNER_TD_5487086 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_5487086.setup(tbl_JOIN_INNER_TD_6724290_output, tbl_Filter_TD_6320172_output, tbl_JOIN_INNER_TD_5487086_output_preprocess, cfg_JOIN_INNER_TD_5487086_cmds, buftmp_h);
    AggrKrnlEngine krnl_Aggregate_TD_7805576;
    krnl_Aggregate_TD_7805576 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_7805576.setup(tbl_Project_TD_8400581_output, tbl_Aggregate_TD_7805576_output_preprocess, cfg_Aggregate_TD_7805576_cmds, cfg_Aggregate_TD_7805576_cmds_out, buftmp_a);
    AggrKrnlEngine krnl_Aggregate_TD_7521203;
    krnl_Aggregate_TD_7521203 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_7521203.setup(tbl_Project_TD_8876293_output, tbl_Aggregate_TD_7521203_output_preprocess, cfg_Aggregate_TD_7521203_cmds, cfg_Aggregate_TD_7521203_cmds_out, buftmp_a);
    krnlEngine krnl_JOIN_INNER_TD_838624;
    krnl_JOIN_INNER_TD_838624 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_838624.setup(tbl_Aggregate_TD_9953648_output, tbl_Filter_TD_9845184_output, tbl_JOIN_INNER_TD_838624_output, cfg_JOIN_INNER_TD_838624_cmds, buftmp_h);
    AggrKrnlEngine krnl_Aggregate_TD_9953648;
    krnl_Aggregate_TD_9953648 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_9953648.setup(tbl_JOIN_INNER_TD_1077543_output, tbl_Aggregate_TD_9953648_output_preprocess, cfg_Aggregate_TD_9953648_cmds, cfg_Aggregate_TD_9953648_cmds_out, buftmp_a);
    krnlEngine krnl_JOIN_INNER_TD_1077543;
    krnl_JOIN_INNER_TD_1077543 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_1077543.setup(tbl_JOIN_INNER_TD_11589620_output, tbl_Filter_TD_11768305_output, tbl_JOIN_INNER_TD_1077543_output_preprocess, cfg_JOIN_INNER_TD_1077543_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_11589620;
    krnl_JOIN_INNER_TD_11589620 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_11589620.setup(tbl_JOIN_INNER_TD_12959194_output, tbl_Filter_TD_12895959_output, tbl_JOIN_INNER_TD_11589620_output, cfg_JOIN_INNER_TD_11589620_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_12959194;
    krnl_JOIN_INNER_TD_12959194 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_12959194.setup(tbl_Union_TD_13712926_output, tbl_Filter_TD_13998184_output, tbl_JOIN_INNER_TD_12959194_output, cfg_JOIN_INNER_TD_12959194_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_Aggregate_TD_4795083;
    trans_Aggregate_TD_4795083.setq(q_a);
    trans_Aggregate_TD_4795083.add(&(cfg_Aggregate_TD_4795083_cmds));
    transEngine trans_Aggregate_TD_4795083_out;
    trans_Aggregate_TD_4795083_out.setq(q_a);
    q_a.finish();
    transEngine trans_JOIN_INNER_TD_5487086;
    trans_JOIN_INNER_TD_5487086.setq(q_h);
    trans_JOIN_INNER_TD_5487086.add(&(cfg_JOIN_INNER_TD_5487086_cmds));
    transEngine trans_JOIN_INNER_TD_5487086_out;
    trans_JOIN_INNER_TD_5487086_out.setq(q_h);
    q_h.finish();
    transEngine trans_Aggregate_TD_7805576;
    trans_Aggregate_TD_7805576.setq(q_a);
    trans_Aggregate_TD_7805576.add(&(cfg_Aggregate_TD_7805576_cmds));
    transEngine trans_Aggregate_TD_7805576_out;
    trans_Aggregate_TD_7805576_out.setq(q_a);
    q_a.finish();
    transEngine trans_Aggregate_TD_7521203;
    trans_Aggregate_TD_7521203.setq(q_a);
    trans_Aggregate_TD_7521203.add(&(cfg_Aggregate_TD_7521203_cmds));
    transEngine trans_Aggregate_TD_7521203_out;
    trans_Aggregate_TD_7521203_out.setq(q_a);
    q_a.finish();
    transEngine trans_JOIN_INNER_TD_838624;
    trans_JOIN_INNER_TD_838624.setq(q_h);
    trans_JOIN_INNER_TD_838624.add(&(cfg_JOIN_INNER_TD_838624_cmds));
    transEngine trans_JOIN_INNER_TD_838624_out;
    trans_JOIN_INNER_TD_838624_out.setq(q_h);
    q_h.finish();
    transEngine trans_Aggregate_TD_9953648;
    trans_Aggregate_TD_9953648.setq(q_a);
    trans_Aggregate_TD_9953648.add(&(cfg_Aggregate_TD_9953648_cmds));
    transEngine trans_Aggregate_TD_9953648_out;
    trans_Aggregate_TD_9953648_out.setq(q_a);
    q_a.finish();
    transEngine trans_JOIN_INNER_TD_1077543;
    trans_JOIN_INNER_TD_1077543.setq(q_h);
    trans_JOIN_INNER_TD_1077543.add(&(cfg_JOIN_INNER_TD_1077543_cmds));
    transEngine trans_JOIN_INNER_TD_1077543_out;
    trans_JOIN_INNER_TD_1077543_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_11589620;
    trans_JOIN_INNER_TD_11589620.setq(q_h);
    trans_JOIN_INNER_TD_11589620.add(&(cfg_JOIN_INNER_TD_11589620_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_12959194;
    trans_JOIN_INNER_TD_12959194.setq(q_h);
    trans_JOIN_INNER_TD_12959194.add(&(cfg_JOIN_INNER_TD_12959194_cmds));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_4795083;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_4795083;
    std::vector<cl::Event> events_Aggregate_TD_4795083;
    events_h2d_wr_Aggregate_TD_4795083.resize(1);
    events_d2h_rd_Aggregate_TD_4795083.resize(1);
    events_Aggregate_TD_4795083.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_4795083;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_4795083;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_5487086;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_5487086;
    std::vector<cl::Event> events_JOIN_INNER_TD_5487086;
    events_h2d_wr_JOIN_INNER_TD_5487086.resize(1);
    events_d2h_rd_JOIN_INNER_TD_5487086.resize(1);
    events_JOIN_INNER_TD_5487086.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_5487086;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_5487086;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_7805576;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_7805576;
    std::vector<cl::Event> events_Aggregate_TD_7805576;
    events_h2d_wr_Aggregate_TD_7805576.resize(1);
    events_d2h_rd_Aggregate_TD_7805576.resize(1);
    events_Aggregate_TD_7805576.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_7805576;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_7805576;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_7521203;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_7521203;
    std::vector<cl::Event> events_Aggregate_TD_7521203;
    events_h2d_wr_Aggregate_TD_7521203.resize(1);
    events_d2h_rd_Aggregate_TD_7521203.resize(1);
    events_Aggregate_TD_7521203.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_7521203;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_7521203;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_838624;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_838624;
    std::vector<cl::Event> events_JOIN_INNER_TD_838624;
    events_h2d_wr_JOIN_INNER_TD_838624.resize(1);
    events_d2h_rd_JOIN_INNER_TD_838624.resize(1);
    events_JOIN_INNER_TD_838624.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_838624;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_838624;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_9953648;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_9953648;
    std::vector<cl::Event> events_Aggregate_TD_9953648;
    events_h2d_wr_Aggregate_TD_9953648.resize(1);
    events_d2h_rd_Aggregate_TD_9953648.resize(1);
    events_Aggregate_TD_9953648.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_9953648;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_9953648;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_1077543;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_1077543;
    std::vector<cl::Event> events_JOIN_INNER_TD_1077543;
    events_h2d_wr_JOIN_INNER_TD_1077543.resize(1);
    events_d2h_rd_JOIN_INNER_TD_1077543.resize(1);
    events_JOIN_INNER_TD_1077543.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_1077543;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_1077543;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_11589620;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_11589620;
    std::vector<cl::Event> events_JOIN_INNER_TD_11589620;
    events_h2d_wr_JOIN_INNER_TD_11589620.resize(1);
    events_d2h_rd_JOIN_INNER_TD_11589620.resize(1);
    events_JOIN_INNER_TD_11589620.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_11589620;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_11589620;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_12959194;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_12959194;
    std::vector<cl::Event> events_JOIN_INNER_TD_12959194;
    events_h2d_wr_JOIN_INNER_TD_12959194.resize(1);
    events_d2h_rd_JOIN_INNER_TD_12959194.resize(1);
    events_JOIN_INNER_TD_12959194.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_12959194;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_12959194;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_15_766603_s, tv_r_Filter_15_766603_e;
    gettimeofday(&tv_r_Filter_15_766603_s, 0);
    SW_Filter_TD_15942981(tbl_SerializeFromObject_TD_16194364_input, tbl_Filter_TD_15942981_output);
    gettimeofday(&tv_r_Filter_15_766603_e, 0);

    struct timeval tv_r_Filter_15_810782_s, tv_r_Filter_15_810782_e;
    gettimeofday(&tv_r_Filter_15_810782_s, 0);
    SW_Filter_TD_15417386(tbl_SerializeFromObject_TD_16713508_input, tbl_Filter_TD_15417386_output);
    gettimeofday(&tv_r_Filter_15_810782_e, 0);

    struct timeval tv_r_Project_14_255236_s, tv_r_Project_14_255236_e;
    gettimeofday(&tv_r_Project_14_255236_s, 0);
    SW_Project_TD_14411667(tbl_Filter_TD_15942981_output, tbl_Project_TD_14411667_output);
    gettimeofday(&tv_r_Project_14_255236_e, 0);

    struct timeval tv_r_Project_14_259197_s, tv_r_Project_14_259197_e;
    gettimeofday(&tv_r_Project_14_259197_s, 0);
    SW_Project_TD_14575890(tbl_Filter_TD_15417386_output, tbl_Project_TD_14575890_output);
    gettimeofday(&tv_r_Project_14_259197_e, 0);

    struct timeval tv_r_Filter_13_682887_s, tv_r_Filter_13_682887_e;
    gettimeofday(&tv_r_Filter_13_682887_s, 0);
    SW_Filter_TD_13998184(tbl_SerializeFromObject_TD_14698106_input, tbl_Filter_TD_13998184_output);
    gettimeofday(&tv_r_Filter_13_682887_e, 0);

    struct timeval tv_r_Union_13_43569_s, tv_r_Union_13_43569_e;
    gettimeofday(&tv_r_Union_13_43569_s, 0);
    SW_Union_TD_13712926(tbl_Project_TD_14575890_output, tbl_Project_TD_14411667_output, tbl_Union_TD_13712926_output);
    gettimeofday(&tv_r_Union_13_43569_e, 0);

    struct timeval tv_r_Filter_12_979462_s, tv_r_Filter_12_979462_e;
    gettimeofday(&tv_r_Filter_12_979462_s, 0);
    SW_Filter_TD_12895959(tbl_SerializeFromObject_TD_1357148_input, tbl_Filter_TD_12895959_output);
    gettimeofday(&tv_r_Filter_12_979462_e, 0);

    struct timeval tv_r_JOIN_INNER_12_797463_s, tv_r_JOIN_INNER_12_797463_e;
    gettimeofday(&tv_r_JOIN_INNER_12_797463_s, 0);
    trans_JOIN_INNER_TD_12959194.add(&(tbl_Union_TD_13712926_output));
    trans_JOIN_INNER_TD_12959194.add(&(tbl_Filter_TD_13998184_output));
    trans_JOIN_INNER_TD_12959194.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_12959194), &(events_h2d_wr_JOIN_INNER_TD_12959194[0]));
    events_grp_JOIN_INNER_TD_12959194.push_back(events_h2d_wr_JOIN_INNER_TD_12959194[0]);
    krnl_JOIN_INNER_TD_12959194.run(0, &(events_grp_JOIN_INNER_TD_12959194), &(events_JOIN_INNER_TD_12959194[0]));
    gettimeofday(&tv_r_JOIN_INNER_12_797463_e, 0);

    struct timeval tv_r_Filter_11_588049_s, tv_r_Filter_11_588049_e;
    gettimeofday(&tv_r_Filter_11_588049_s, 0);
    SW_Filter_TD_11768305(tbl_SerializeFromObject_TD_12107220_input, tbl_Filter_TD_11768305_output);
    gettimeofday(&tv_r_Filter_11_588049_e, 0);

    struct timeval tv_r_JOIN_INNER_11_379998_s, tv_r_JOIN_INNER_11_379998_e;
    gettimeofday(&tv_r_JOIN_INNER_11_379998_s, 0);
    prev_events_grp_JOIN_INNER_TD_11589620.push_back(events_h2d_wr_JOIN_INNER_TD_12959194[0]);
    trans_JOIN_INNER_TD_11589620.add(&(tbl_Filter_TD_12895959_output));
    trans_JOIN_INNER_TD_11589620.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_11589620), &(events_h2d_wr_JOIN_INNER_TD_11589620[0]));
    events_grp_JOIN_INNER_TD_11589620.push_back(events_h2d_wr_JOIN_INNER_TD_11589620[0]);
    events_grp_JOIN_INNER_TD_11589620.push_back(events_JOIN_INNER_TD_12959194[0]);
    krnl_JOIN_INNER_TD_11589620.run(0, &(events_grp_JOIN_INNER_TD_11589620), &(events_JOIN_INNER_TD_11589620[0]));
    gettimeofday(&tv_r_JOIN_INNER_11_379998_e, 0);

    struct timeval tv_r_JOIN_INNER_10_655630_s, tv_r_JOIN_INNER_10_655630_e;
    gettimeofday(&tv_r_JOIN_INNER_10_655630_s, 0);
    prev_events_grp_JOIN_INNER_TD_1077543.push_back(events_h2d_wr_JOIN_INNER_TD_11589620[0]);
    trans_JOIN_INNER_TD_1077543.add(&(tbl_Filter_TD_11768305_output));
    trans_JOIN_INNER_TD_1077543.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_1077543), &(events_h2d_wr_JOIN_INNER_TD_1077543[0]));
    events_grp_JOIN_INNER_TD_1077543.push_back(events_h2d_wr_JOIN_INNER_TD_1077543[0]);
    events_grp_JOIN_INNER_TD_1077543.push_back(events_JOIN_INNER_TD_11589620[0]);
    krnl_JOIN_INNER_TD_1077543.run(0, &(events_grp_JOIN_INNER_TD_1077543), &(events_JOIN_INNER_TD_1077543[0]));
    
    trans_JOIN_INNER_TD_1077543_out.add(&(tbl_JOIN_INNER_TD_1077543_output_preprocess));
    trans_JOIN_INNER_TD_1077543_out.dev2host(0, &(events_JOIN_INNER_TD_1077543), &(events_d2h_rd_JOIN_INNER_TD_1077543[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_1077543);
    tbl_JOIN_INNER_TD_1077543_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_1077543_output));
    gettimeofday(&tv_r_JOIN_INNER_10_655630_e, 0);

    struct timeval tv_r_Filter_9_499238_s, tv_r_Filter_9_499238_e;
    gettimeofday(&tv_r_Filter_9_499238_s, 0);
    SW_Filter_TD_9679178(tbl_SerializeFromObject_TD_10345680_input, tbl_Filter_TD_9679178_output);
    gettimeofday(&tv_r_Filter_9_499238_e, 0);

    struct timeval tv_r_Filter_9_689039_s, tv_r_Filter_9_689039_e;
    gettimeofday(&tv_r_Filter_9_689039_s, 0);
    SW_Filter_TD_9916711(tbl_SerializeFromObject_TD_10746465_input, tbl_Filter_TD_9916711_output);
    gettimeofday(&tv_r_Filter_9_689039_e, 0);

    struct timeval tv_r_Filter_9_380065_s, tv_r_Filter_9_380065_e;
    gettimeofday(&tv_r_Filter_9_380065_s, 0);
    SW_Filter_TD_9845184(tbl_SerializeFromObject_TD_10516255_input, tbl_Filter_TD_9845184_output);
    gettimeofday(&tv_r_Filter_9_380065_e, 0);

    struct timeval tv_r_Aggregate_9_740232_s, tv_r_Aggregate_9_740232_e;
    gettimeofday(&tv_r_Aggregate_9_740232_s, 0);
    trans_Aggregate_TD_9953648.add(&(tbl_JOIN_INNER_TD_1077543_output));
    trans_Aggregate_TD_9953648.host2dev(0, &(prev_events_grp_Aggregate_TD_9953648), &(events_h2d_wr_Aggregate_TD_9953648[0]));
    events_grp_Aggregate_TD_9953648.push_back(events_h2d_wr_Aggregate_TD_9953648[0]);
    krnl_Aggregate_TD_9953648.run(0, &(events_grp_Aggregate_TD_9953648), &(events_Aggregate_TD_9953648[0]));
    
    trans_Aggregate_TD_9953648_out.add(&(tbl_Aggregate_TD_9953648_output_preprocess));
    trans_Aggregate_TD_9953648_out.dev2host(0, &(events_Aggregate_TD_9953648), &(events_d2h_rd_Aggregate_TD_9953648[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_9953648_consolidate(tbl_Aggregate_TD_9953648_output_preprocess, tbl_Aggregate_TD_9953648_output);
    gettimeofday(&tv_r_Aggregate_9_740232_e, 0);

    struct timeval tv_r_Project_8_839436_s, tv_r_Project_8_839436_e;
    gettimeofday(&tv_r_Project_8_839436_s, 0);
    SW_Project_TD_8876293(tbl_Filter_TD_9679178_output, tbl_Project_TD_8876293_output);
    gettimeofday(&tv_r_Project_8_839436_e, 0);

    struct timeval tv_r_Project_8_252601_s, tv_r_Project_8_252601_e;
    gettimeofday(&tv_r_Project_8_252601_s, 0);
    SW_Project_TD_8400581(tbl_Filter_TD_9916711_output, tbl_Project_TD_8400581_output);
    gettimeofday(&tv_r_Project_8_252601_e, 0);

    struct timeval tv_r_Filter_8_967644_s, tv_r_Filter_8_967644_e;
    gettimeofday(&tv_r_Filter_8_967644_s, 0);
    SW_Filter_TD_8729339(tbl_SerializeFromObject_TD_9680138_input, tbl_Filter_TD_8729339_output);
    gettimeofday(&tv_r_Filter_8_967644_e, 0);

    struct timeval tv_r_JOIN_INNER_8_23286_s, tv_r_JOIN_INNER_8_23286_e;
    gettimeofday(&tv_r_JOIN_INNER_8_23286_s, 0);
    trans_JOIN_INNER_TD_838624.add(&(tbl_Aggregate_TD_9953648_output));
    trans_JOIN_INNER_TD_838624.add(&(tbl_Filter_TD_9845184_output));
    trans_JOIN_INNER_TD_838624.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_838624), &(events_h2d_wr_JOIN_INNER_TD_838624[0]));
    events_grp_JOIN_INNER_TD_838624.push_back(events_h2d_wr_JOIN_INNER_TD_838624[0]);
    krnl_JOIN_INNER_TD_838624.run(0, &(events_grp_JOIN_INNER_TD_838624), &(events_JOIN_INNER_TD_838624[0]));
    
    trans_JOIN_INNER_TD_838624_out.add(&(tbl_JOIN_INNER_TD_838624_output));
    trans_JOIN_INNER_TD_838624_out.dev2host(0, &(events_JOIN_INNER_TD_838624), &(events_d2h_rd_JOIN_INNER_TD_838624[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_8_23286_e, 0);

    struct timeval tv_r_Aggregate_7_524525_s, tv_r_Aggregate_7_524525_e;
    gettimeofday(&tv_r_Aggregate_7_524525_s, 0);
    trans_Aggregate_TD_7521203.add(&(tbl_Project_TD_8876293_output));
    trans_Aggregate_TD_7521203.host2dev(0, &(prev_events_grp_Aggregate_TD_7521203), &(events_h2d_wr_Aggregate_TD_7521203[0]));
    events_grp_Aggregate_TD_7521203.push_back(events_h2d_wr_Aggregate_TD_7521203[0]);
    krnl_Aggregate_TD_7521203.run(0, &(events_grp_Aggregate_TD_7521203), &(events_Aggregate_TD_7521203[0]));
    
    trans_Aggregate_TD_7521203_out.add(&(tbl_Aggregate_TD_7521203_output_preprocess));
    trans_Aggregate_TD_7521203_out.dev2host(0, &(events_Aggregate_TD_7521203), &(events_d2h_rd_Aggregate_TD_7521203[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_7521203_consolidate(tbl_Aggregate_TD_7521203_output_preprocess, tbl_Aggregate_TD_7521203_output);
    gettimeofday(&tv_r_Aggregate_7_524525_e, 0);

    struct timeval tv_r_Aggregate_7_709038_s, tv_r_Aggregate_7_709038_e;
    gettimeofday(&tv_r_Aggregate_7_709038_s, 0);
    trans_Aggregate_TD_7805576.add(&(tbl_Project_TD_8400581_output));
    trans_Aggregate_TD_7805576.host2dev(0, &(prev_events_grp_Aggregate_TD_7805576), &(events_h2d_wr_Aggregate_TD_7805576[0]));
    events_grp_Aggregate_TD_7805576.push_back(events_h2d_wr_Aggregate_TD_7805576[0]);
    krnl_Aggregate_TD_7805576.run(0, &(events_grp_Aggregate_TD_7805576), &(events_Aggregate_TD_7805576[0]));
    
    trans_Aggregate_TD_7805576_out.add(&(tbl_Aggregate_TD_7805576_output_preprocess));
    trans_Aggregate_TD_7805576_out.dev2host(0, &(events_Aggregate_TD_7805576), &(events_d2h_rd_Aggregate_TD_7805576[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_7805576_consolidate(tbl_Aggregate_TD_7805576_output_preprocess, tbl_Aggregate_TD_7805576_output);
    gettimeofday(&tv_r_Aggregate_7_709038_e, 0);

    struct timeval tv_r_Filter_7_680128_s, tv_r_Filter_7_680128_e;
    gettimeofday(&tv_r_Filter_7_680128_s, 0);
    SW_Filter_TD_7534451(tbl_SerializeFromObject_TD_8205186_input, tbl_Filter_TD_7534451_output);
    gettimeofday(&tv_r_Filter_7_680128_e, 0);

    struct timeval tv_r_JOIN_INNER_7_459480_s, tv_r_JOIN_INNER_7_459480_e;
    gettimeofday(&tv_r_JOIN_INNER_7_459480_s, 0);
    SW_JOIN_INNER_TD_7928320(tbl_JOIN_INNER_TD_838624_output, tbl_Filter_TD_8729339_output, tbl_JOIN_INNER_TD_7928320_output);
    gettimeofday(&tv_r_JOIN_INNER_7_459480_e, 0);

    struct timeval tv_r_Filter_6_517678_s, tv_r_Filter_6_517678_e;
    gettimeofday(&tv_r_Filter_6_517678_s, 0);
    SW_Filter_TD_6320172(tbl_SerializeFromObject_TD_7371785_input, tbl_Aggregate_TD_7805576_output, tbl_Aggregate_TD_7521203_output, tbl_Filter_TD_6320172_output);
    gettimeofday(&tv_r_Filter_6_517678_e, 0);

    struct timeval tv_r_JOIN_INNER_6_496485_s, tv_r_JOIN_INNER_6_496485_e;
    gettimeofday(&tv_r_JOIN_INNER_6_496485_s, 0);
    SW_JOIN_INNER_TD_6724290(tbl_JOIN_INNER_TD_7928320_output, tbl_Filter_TD_7534451_output, tbl_JOIN_INNER_TD_6724290_output);
    gettimeofday(&tv_r_JOIN_INNER_6_496485_e, 0);

    struct timeval tv_r_JOIN_INNER_5_788948_s, tv_r_JOIN_INNER_5_788948_e;
    gettimeofday(&tv_r_JOIN_INNER_5_788948_s, 0);
    trans_JOIN_INNER_TD_5487086.add(&(tbl_JOIN_INNER_TD_6724290_output));
    trans_JOIN_INNER_TD_5487086.add(&(tbl_Filter_TD_6320172_output));
    trans_JOIN_INNER_TD_5487086.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_5487086), &(events_h2d_wr_JOIN_INNER_TD_5487086[0]));
    events_grp_JOIN_INNER_TD_5487086.push_back(events_h2d_wr_JOIN_INNER_TD_5487086[0]);
    krnl_JOIN_INNER_TD_5487086.run(0, &(events_grp_JOIN_INNER_TD_5487086), &(events_JOIN_INNER_TD_5487086[0]));
    
    trans_JOIN_INNER_TD_5487086_out.add(&(tbl_JOIN_INNER_TD_5487086_output_preprocess));
    trans_JOIN_INNER_TD_5487086_out.dev2host(0, &(events_JOIN_INNER_TD_5487086), &(events_d2h_rd_JOIN_INNER_TD_5487086[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_5487086);
    tbl_JOIN_INNER_TD_5487086_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_5487086_output));
    gettimeofday(&tv_r_JOIN_INNER_5_788948_e, 0);

    struct timeval tv_r_Aggregate_4_697127_s, tv_r_Aggregate_4_697127_e;
    gettimeofday(&tv_r_Aggregate_4_697127_s, 0);
    trans_Aggregate_TD_4795083.add(&(tbl_JOIN_INNER_TD_5487086_output));
    trans_Aggregate_TD_4795083.host2dev(0, &(prev_events_grp_Aggregate_TD_4795083), &(events_h2d_wr_Aggregate_TD_4795083[0]));
    events_grp_Aggregate_TD_4795083.push_back(events_h2d_wr_Aggregate_TD_4795083[0]);
    krnl_Aggregate_TD_4795083.run(0, &(events_grp_Aggregate_TD_4795083), &(events_Aggregate_TD_4795083[0]));
    
    trans_Aggregate_TD_4795083_out.add(&(tbl_Aggregate_TD_4795083_output_preprocess));
    trans_Aggregate_TD_4795083_out.dev2host(0, &(events_Aggregate_TD_4795083), &(events_d2h_rd_Aggregate_TD_4795083[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_4795083_consolidate(tbl_Aggregate_TD_4795083_output_preprocess, tbl_Aggregate_TD_4795083_output);
    gettimeofday(&tv_r_Aggregate_4_697127_e, 0);

    struct timeval tv_r_Aggregate_3_273615_s, tv_r_Aggregate_3_273615_e;
    gettimeofday(&tv_r_Aggregate_3_273615_s, 0);
    SW_Aggregate_TD_325302(tbl_Aggregate_TD_4795083_output, tbl_Aggregate_TD_325302_output);
    gettimeofday(&tv_r_Aggregate_3_273615_e, 0);

    struct timeval tv_r_Sort_2_593724_s, tv_r_Sort_2_593724_e;
    gettimeofday(&tv_r_Sort_2_593724_s, 0);
    SW_Sort_TD_2149954(tbl_Aggregate_TD_325302_output, tbl_Sort_TD_2149954_output);
    gettimeofday(&tv_r_Sort_2_593724_e, 0);

    struct timeval tv_r_LocalLimit_1_507813_s, tv_r_LocalLimit_1_507813_e;
    gettimeofday(&tv_r_LocalLimit_1_507813_s, 0);
    SW_LocalLimit_TD_1325297(tbl_Sort_TD_2149954_output, tbl_LocalLimit_TD_1325297_output);
    gettimeofday(&tv_r_LocalLimit_1_507813_e, 0);

    struct timeval tv_r_GlobalLimit_0_516731_s, tv_r_GlobalLimit_0_516731_e;
    gettimeofday(&tv_r_GlobalLimit_0_516731_s, 0);
    SW_GlobalLimit_TD_0179492(tbl_LocalLimit_TD_1325297_output, tbl_GlobalLimit_TD_0179492_output);
    gettimeofday(&tv_r_GlobalLimit_0_516731_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_15: " << tvdiff(&tv_r_Filter_15_766603_s, &tv_r_Filter_15_766603_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_16194364_input: " << tbl_SerializeFromObject_TD_16194364_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_15: " << tvdiff(&tv_r_Filter_15_810782_s, &tv_r_Filter_15_810782_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_16713508_input: " << tbl_SerializeFromObject_TD_16713508_input.getNumRow() << " " << std::endl; 

    std::cout << "Project_14: " << tvdiff(&tv_r_Project_14_255236_s, &tv_r_Project_14_255236_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_15942981_output: " << tbl_Filter_TD_15942981_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_14: " << tvdiff(&tv_r_Project_14_259197_s, &tv_r_Project_14_259197_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_15417386_output: " << tbl_Filter_TD_15417386_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_13: " << tvdiff(&tv_r_Filter_13_682887_s, &tv_r_Filter_13_682887_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_14698106_input: " << tbl_SerializeFromObject_TD_14698106_input.getNumRow() << " " << std::endl; 

    std::cout << "Union_13: " << tvdiff(&tv_r_Union_13_43569_s, &tv_r_Union_13_43569_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_14575890_output: " << tbl_Project_TD_14575890_output.getNumRow() << " " << "tbl_Project_TD_14411667_output: " << tbl_Project_TD_14411667_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_979462_s, &tv_r_Filter_12_979462_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1357148_input: " << tbl_SerializeFromObject_TD_1357148_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_12: " << tvdiff(&tv_r_JOIN_INNER_12_797463_s, &tv_r_JOIN_INNER_12_797463_e) / 1000.0 << " ms " 
     << "tbl_Union_TD_13712926_output: " << tbl_Union_TD_13712926_output.getNumRow() << " " << "tbl_Filter_TD_13998184_output: " << tbl_Filter_TD_13998184_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_588049_s, &tv_r_Filter_11_588049_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12107220_input: " << tbl_SerializeFromObject_TD_12107220_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_11: " << tvdiff(&tv_r_JOIN_INNER_11_379998_s, &tv_r_JOIN_INNER_11_379998_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_12959194_output: " << tbl_JOIN_INNER_TD_12959194_output.getNumRow() << " " << "tbl_Filter_TD_12895959_output: " << tbl_Filter_TD_12895959_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_655630_s, &tv_r_JOIN_INNER_10_655630_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_11589620_output: " << tbl_JOIN_INNER_TD_11589620_output.getNumRow() << " " << "tbl_Filter_TD_11768305_output: " << tbl_Filter_TD_11768305_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_499238_s, &tv_r_Filter_9_499238_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10345680_input: " << tbl_SerializeFromObject_TD_10345680_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_689039_s, &tv_r_Filter_9_689039_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10746465_input: " << tbl_SerializeFromObject_TD_10746465_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_380065_s, &tv_r_Filter_9_380065_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10516255_input: " << tbl_SerializeFromObject_TD_10516255_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_9: " << tvdiff(&tv_r_Aggregate_9_740232_s, &tv_r_Aggregate_9_740232_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_1077543_output: " << tbl_JOIN_INNER_TD_1077543_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_8: " << tvdiff(&tv_r_Project_8_839436_s, &tv_r_Project_8_839436_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9679178_output: " << tbl_Filter_TD_9679178_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_8: " << tvdiff(&tv_r_Project_8_252601_s, &tv_r_Project_8_252601_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9916711_output: " << tbl_Filter_TD_9916711_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_967644_s, &tv_r_Filter_8_967644_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9680138_input: " << tbl_SerializeFromObject_TD_9680138_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_23286_s, &tv_r_JOIN_INNER_8_23286_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_9953648_output: " << tbl_Aggregate_TD_9953648_output.getNumRow() << " " << "tbl_Filter_TD_9845184_output: " << tbl_Filter_TD_9845184_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_7: " << tvdiff(&tv_r_Aggregate_7_524525_s, &tv_r_Aggregate_7_524525_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_8876293_output: " << tbl_Project_TD_8876293_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_7: " << tvdiff(&tv_r_Aggregate_7_709038_s, &tv_r_Aggregate_7_709038_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_8400581_output: " << tbl_Project_TD_8400581_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_680128_s, &tv_r_Filter_7_680128_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8205186_input: " << tbl_SerializeFromObject_TD_8205186_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_459480_s, &tv_r_JOIN_INNER_7_459480_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_838624_output: " << tbl_JOIN_INNER_TD_838624_output.getNumRow() << " " << "tbl_Filter_TD_8729339_output: " << tbl_Filter_TD_8729339_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_517678_s, &tv_r_Filter_6_517678_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7371785_input: " << tbl_SerializeFromObject_TD_7371785_input.getNumRow() << " " << "tbl_Aggregate_TD_7805576_output: " << tbl_Aggregate_TD_7805576_output.getNumRow() << " " << "tbl_Aggregate_TD_7521203_output: " << tbl_Aggregate_TD_7521203_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_496485_s, &tv_r_JOIN_INNER_6_496485_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7928320_output: " << tbl_JOIN_INNER_TD_7928320_output.getNumRow() << " " << "tbl_Filter_TD_7534451_output: " << tbl_Filter_TD_7534451_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_788948_s, &tv_r_JOIN_INNER_5_788948_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6724290_output: " << tbl_JOIN_INNER_TD_6724290_output.getNumRow() << " " << "tbl_Filter_TD_6320172_output: " << tbl_Filter_TD_6320172_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_4: " << tvdiff(&tv_r_Aggregate_4_697127_s, &tv_r_Aggregate_4_697127_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5487086_output: " << tbl_JOIN_INNER_TD_5487086_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_273615_s, &tv_r_Aggregate_3_273615_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_4795083_output: " << tbl_Aggregate_TD_4795083_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_593724_s, &tv_r_Sort_2_593724_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_325302_output: " << tbl_Aggregate_TD_325302_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_507813_s, &tv_r_LocalLimit_1_507813_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2149954_output: " << tbl_Sort_TD_2149954_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_516731_s, &tv_r_GlobalLimit_0_516731_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1325297_output: " << tbl_LocalLimit_TD_1325297_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 3.226007 * 1000 << "ms" << std::endl; 
    return 0; 
}
