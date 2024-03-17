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

#include "cfgFunc_q33.hpp" 
#include "q33.hpp" 

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
    std::cout << "NOTE:running query #33\n."; 
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
    Table tbl_GlobalLimit_TD_0979670_output("tbl_GlobalLimit_TD_0979670_output", 6100000, 2, "");
    tbl_GlobalLimit_TD_0979670_output.allocateHost();
    Table tbl_LocalLimit_TD_1982910_output("tbl_LocalLimit_TD_1982910_output", 6100000, 2, "");
    tbl_LocalLimit_TD_1982910_output.allocateHost();
    Table tbl_Sort_TD_2163636_output("tbl_Sort_TD_2163636_output", 6100000, 2, "");
    tbl_Sort_TD_2163636_output.allocateHost();
    Table tbl_Aggregate_TD_384003_output_preprocess("tbl_Aggregate_TD_384003_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_384003_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_384003_output("tbl_Aggregate_TD_384003_output", 6100000, 2, "");
    tbl_Aggregate_TD_384003_output.allocateHost();
    Table tbl_Union_TD_4182112_output("tbl_Union_TD_4182112_output", 6100000, 2, "");
    tbl_Union_TD_4182112_output.allocateHost();
    Table tbl_Aggregate_TD_5453244_output_preprocess("tbl_Aggregate_TD_5453244_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_5453244_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_5453244_output("tbl_Aggregate_TD_5453244_output", 6100000, 2, "");
    tbl_Aggregate_TD_5453244_output.allocateHost();
    Table tbl_Aggregate_TD_5894224_output_preprocess("tbl_Aggregate_TD_5894224_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_5894224_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_5894224_output("tbl_Aggregate_TD_5894224_output", 6100000, 2, "");
    tbl_Aggregate_TD_5894224_output.allocateHost();
    Table tbl_Aggregate_TD_5343411_output_preprocess("tbl_Aggregate_TD_5343411_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_5343411_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_5343411_output("tbl_Aggregate_TD_5343411_output", 6100000, 2, "");
    tbl_Aggregate_TD_5343411_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6989915_output_preprocess("tbl_JOIN_INNER_TD_6989915_output_preprocess", 6100000, 2, "");
    tbl_JOIN_INNER_TD_6989915_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_6989915_output("tbl_JOIN_INNER_TD_6989915_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_6989915_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6766694_output_preprocess("tbl_JOIN_INNER_TD_6766694_output_preprocess", 6100000, 2, "");
    tbl_JOIN_INNER_TD_6766694_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_6766694_output("tbl_JOIN_INNER_TD_6766694_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_6766694_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6758993_output_preprocess("tbl_JOIN_INNER_TD_6758993_output_preprocess", 6100000, 2, "");
    tbl_JOIN_INNER_TD_6758993_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_6758993_output("tbl_JOIN_INNER_TD_6758993_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_6758993_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7433416_output("tbl_JOIN_INNER_TD_7433416_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_7433416_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_7347442_output("tbl_JOIN_LEFTSEMI_TD_7347442_output", 6100000, 2, "");
    tbl_JOIN_LEFTSEMI_TD_7347442_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7860766_output("tbl_JOIN_INNER_TD_7860766_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_7860766_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_7724291_output("tbl_JOIN_LEFTSEMI_TD_7724291_output", 6100000, 2, "");
    tbl_JOIN_LEFTSEMI_TD_7724291_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7445700_output("tbl_JOIN_INNER_TD_7445700_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_7445700_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_7524644_output("tbl_JOIN_LEFTSEMI_TD_7524644_output", 6100000, 2, "");
    tbl_JOIN_LEFTSEMI_TD_7524644_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8288042_output("tbl_JOIN_INNER_TD_8288042_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_8288042_output.allocateHost();
    Table tbl_Filter_TD_8631152_output("tbl_Filter_TD_8631152_output", 6100000, 1, "");
    tbl_Filter_TD_8631152_output.allocateHost();
    Table tbl_Filter_TD_8207053_output("tbl_Filter_TD_8207053_output", 6100000, 2, "");
    tbl_Filter_TD_8207053_output.allocateHost();
    Table tbl_Filter_TD_8428670_output("tbl_Filter_TD_8428670_output", 6100000, 1, "");
    tbl_Filter_TD_8428670_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8764765_output("tbl_JOIN_INNER_TD_8764765_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_8764765_output.allocateHost();
    Table tbl_Filter_TD_8614172_output("tbl_Filter_TD_8614172_output", 6100000, 1, "");
    tbl_Filter_TD_8614172_output.allocateHost();
    Table tbl_Filter_TD_8333166_output("tbl_Filter_TD_8333166_output", 6100000, 2, "");
    tbl_Filter_TD_8333166_output.allocateHost();
    Table tbl_Filter_TD_872308_output("tbl_Filter_TD_872308_output", 6100000, 1, "");
    tbl_Filter_TD_872308_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8571671_output("tbl_JOIN_INNER_TD_8571671_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_8571671_output.allocateHost();
    Table tbl_Filter_TD_8154288_output("tbl_Filter_TD_8154288_output", 6100000, 1, "");
    tbl_Filter_TD_8154288_output.allocateHost();
    Table tbl_Filter_TD_8603282_output("tbl_Filter_TD_8603282_output", 6100000, 2, "");
    tbl_Filter_TD_8603282_output.allocateHost();
    Table tbl_Filter_TD_8693444_output("tbl_Filter_TD_8693444_output", 6100000, 1, "");
    tbl_Filter_TD_8693444_output.allocateHost();
    Table tbl_Filter_TD_9812505_output("tbl_Filter_TD_9812505_output", 6100000, 4, "");
    tbl_Filter_TD_9812505_output.allocateHost();
    Table tbl_Filter_TD_9816920_output("tbl_Filter_TD_9816920_output", 6100000, 1, "");
    tbl_Filter_TD_9816920_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9293274_input;
    tbl_SerializeFromObject_TD_9293274_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9293274_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_9293274_input.addCol("ca_gmt_offset", 4);
    tbl_SerializeFromObject_TD_9293274_input.allocateHost();
    tbl_SerializeFromObject_TD_9293274_input.loadHost();
    Table tbl_SerializeFromObject_TD_9154893_input;
    tbl_SerializeFromObject_TD_9154893_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9154893_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_9154893_input.addCol("i_manufact_id", 4);
    tbl_SerializeFromObject_TD_9154893_input.allocateHost();
    tbl_SerializeFromObject_TD_9154893_input.loadHost();
    Table tbl_SerializeFromObject_TD_9919217_input;
    tbl_SerializeFromObject_TD_9919217_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9919217_input.addCol("i_manufact_id", 4);
    tbl_SerializeFromObject_TD_9919217_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9919217_input.allocateHost();
    tbl_SerializeFromObject_TD_9919217_input.loadHost();
    Table tbl_Filter_TD_9305145_output("tbl_Filter_TD_9305145_output", 6100000, 4, "");
    tbl_Filter_TD_9305145_output.allocateHost();
    Table tbl_Filter_TD_9443408_output("tbl_Filter_TD_9443408_output", 6100000, 1, "");
    tbl_Filter_TD_9443408_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9210785_input;
    tbl_SerializeFromObject_TD_9210785_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9210785_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_9210785_input.addCol("ca_gmt_offset", 4);
    tbl_SerializeFromObject_TD_9210785_input.allocateHost();
    tbl_SerializeFromObject_TD_9210785_input.loadHost();
    Table tbl_SerializeFromObject_TD_9385979_input;
    tbl_SerializeFromObject_TD_9385979_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9385979_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_9385979_input.addCol("i_manufact_id", 4);
    tbl_SerializeFromObject_TD_9385979_input.allocateHost();
    tbl_SerializeFromObject_TD_9385979_input.loadHost();
    Table tbl_SerializeFromObject_TD_9538311_input;
    tbl_SerializeFromObject_TD_9538311_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9538311_input.addCol("i_manufact_id", 4);
    tbl_SerializeFromObject_TD_9538311_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9538311_input.allocateHost();
    tbl_SerializeFromObject_TD_9538311_input.loadHost();
    Table tbl_Filter_TD_973621_output("tbl_Filter_TD_973621_output", 6100000, 4, "");
    tbl_Filter_TD_973621_output.allocateHost();
    Table tbl_Filter_TD_9411587_output("tbl_Filter_TD_9411587_output", 6100000, 1, "");
    tbl_Filter_TD_9411587_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9706056_input;
    tbl_SerializeFromObject_TD_9706056_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9706056_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_9706056_input.addCol("ca_gmt_offset", 4);
    tbl_SerializeFromObject_TD_9706056_input.allocateHost();
    tbl_SerializeFromObject_TD_9706056_input.loadHost();
    Table tbl_SerializeFromObject_TD_9714270_input;
    tbl_SerializeFromObject_TD_9714270_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9714270_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_9714270_input.addCol("i_manufact_id", 4);
    tbl_SerializeFromObject_TD_9714270_input.allocateHost();
    tbl_SerializeFromObject_TD_9714270_input.loadHost();
    Table tbl_SerializeFromObject_TD_981526_input;
    tbl_SerializeFromObject_TD_981526_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_981526_input.addCol("i_manufact_id", 4);
    tbl_SerializeFromObject_TD_981526_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_981526_input.allocateHost();
    tbl_SerializeFromObject_TD_981526_input.loadHost();
    Table tbl_SerializeFromObject_TD_10635206_input;
    tbl_SerializeFromObject_TD_10635206_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_10635206_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10635206_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_10635206_input.addCol("ss_addr_sk", 4);
    tbl_SerializeFromObject_TD_10635206_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_10635206_input.allocateHost();
    tbl_SerializeFromObject_TD_10635206_input.loadHost();
    Table tbl_SerializeFromObject_TD_1029519_input;
    tbl_SerializeFromObject_TD_1029519_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_1029519_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_1029519_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_1029519_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_1029519_input.allocateHost();
    tbl_SerializeFromObject_TD_1029519_input.loadHost();
    Table tbl_SerializeFromObject_TD_10815152_input;
    tbl_SerializeFromObject_TD_10815152_input = Table("catalog_sales", catalog_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_10815152_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10815152_input.addCol("cs_bill_addr_sk", 4);
    tbl_SerializeFromObject_TD_10815152_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_10815152_input.addCol("cs_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_10815152_input.allocateHost();
    tbl_SerializeFromObject_TD_10815152_input.loadHost();
    Table tbl_SerializeFromObject_TD_10451965_input;
    tbl_SerializeFromObject_TD_10451965_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10451965_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10451965_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10451965_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_10451965_input.allocateHost();
    tbl_SerializeFromObject_TD_10451965_input.loadHost();
    Table tbl_SerializeFromObject_TD_10310544_input;
    tbl_SerializeFromObject_TD_10310544_input = Table("web_sales", web_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_10310544_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10310544_input.addCol("ws_item_sk", 4);
    tbl_SerializeFromObject_TD_10310544_input.addCol("ws_bill_addr_sk", 4);
    tbl_SerializeFromObject_TD_10310544_input.addCol("ws_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_10310544_input.allocateHost();
    tbl_SerializeFromObject_TD_10310544_input.loadHost();
    Table tbl_SerializeFromObject_TD_10336437_input;
    tbl_SerializeFromObject_TD_10336437_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10336437_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10336437_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10336437_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_10336437_input.allocateHost();
    tbl_SerializeFromObject_TD_10336437_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_Aggregate_TD_384003_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_Union_TD_4182112_output.allocateDevBuffer(context_a, 32);
    tbl_JOIN_INNER_TD_6989915_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_5453244_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_JOIN_INNER_TD_6766694_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_5894224_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_JOIN_INNER_TD_6758993_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_5343411_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_JOIN_INNER_TD_6989915_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_6766694_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_6758993_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_7433416_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTSEMI_TD_7347442_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_7860766_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTSEMI_TD_7724291_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_7445700_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTSEMI_TD_7524644_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8288042_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8631152_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8207053_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8428670_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8764765_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8614172_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8333166_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_872308_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8571671_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8154288_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8603282_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8693444_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9812505_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9816920_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9305145_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9443408_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_973621_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9411587_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    AggrCfgCmd cfg_Aggregate_TD_384003_cmds;
    cfg_Aggregate_TD_384003_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_384003_gqe_aggr(cfg_Aggregate_TD_384003_cmds.cmd);
    cfg_Aggregate_TD_384003_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_384003_cmds_out;
    cfg_Aggregate_TD_384003_cmds_out.allocateHost();
    cfg_Aggregate_TD_384003_cmds_out.allocateDevBuffer(context_a, 33);
    AggrCfgCmd cfg_Aggregate_TD_5453244_cmds;
    cfg_Aggregate_TD_5453244_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_5453244_gqe_aggr(cfg_Aggregate_TD_5453244_cmds.cmd);
    cfg_Aggregate_TD_5453244_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_5453244_cmds_out;
    cfg_Aggregate_TD_5453244_cmds_out.allocateHost();
    cfg_Aggregate_TD_5453244_cmds_out.allocateDevBuffer(context_a, 33);
    AggrCfgCmd cfg_Aggregate_TD_5894224_cmds;
    cfg_Aggregate_TD_5894224_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_5894224_gqe_aggr(cfg_Aggregate_TD_5894224_cmds.cmd);
    cfg_Aggregate_TD_5894224_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_5894224_cmds_out;
    cfg_Aggregate_TD_5894224_cmds_out.allocateHost();
    cfg_Aggregate_TD_5894224_cmds_out.allocateDevBuffer(context_a, 33);
    AggrCfgCmd cfg_Aggregate_TD_5343411_cmds;
    cfg_Aggregate_TD_5343411_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_5343411_gqe_aggr(cfg_Aggregate_TD_5343411_cmds.cmd);
    cfg_Aggregate_TD_5343411_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_5343411_cmds_out;
    cfg_Aggregate_TD_5343411_cmds_out.allocateHost();
    cfg_Aggregate_TD_5343411_cmds_out.allocateDevBuffer(context_a, 33);
    cfgCmd cfg_JOIN_INNER_TD_6989915_cmds;
    cfg_JOIN_INNER_TD_6989915_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_6989915_gqe_join (cfg_JOIN_INNER_TD_6989915_cmds.cmd);
    cfg_JOIN_INNER_TD_6989915_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_6766694_cmds;
    cfg_JOIN_INNER_TD_6766694_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_6766694_gqe_join (cfg_JOIN_INNER_TD_6766694_cmds.cmd);
    cfg_JOIN_INNER_TD_6766694_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_6758993_cmds;
    cfg_JOIN_INNER_TD_6758993_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_6758993_gqe_join (cfg_JOIN_INNER_TD_6758993_cmds.cmd);
    cfg_JOIN_INNER_TD_6758993_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7433416_cmds;
    cfg_JOIN_INNER_TD_7433416_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7433416_gqe_join (cfg_JOIN_INNER_TD_7433416_cmds.cmd);
    cfg_JOIN_INNER_TD_7433416_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_7347442_cmds;
    cfg_JOIN_LEFTSEMI_TD_7347442_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_7347442_gqe_join (cfg_JOIN_LEFTSEMI_TD_7347442_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_7347442_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7860766_cmds;
    cfg_JOIN_INNER_TD_7860766_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7860766_gqe_join (cfg_JOIN_INNER_TD_7860766_cmds.cmd);
    cfg_JOIN_INNER_TD_7860766_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_7724291_cmds;
    cfg_JOIN_LEFTSEMI_TD_7724291_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_7724291_gqe_join (cfg_JOIN_LEFTSEMI_TD_7724291_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_7724291_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7445700_cmds;
    cfg_JOIN_INNER_TD_7445700_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7445700_gqe_join (cfg_JOIN_INNER_TD_7445700_cmds.cmd);
    cfg_JOIN_INNER_TD_7445700_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_7524644_cmds;
    cfg_JOIN_LEFTSEMI_TD_7524644_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_7524644_gqe_join (cfg_JOIN_LEFTSEMI_TD_7524644_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_7524644_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8288042_cmds;
    cfg_JOIN_INNER_TD_8288042_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8288042_gqe_join (cfg_JOIN_INNER_TD_8288042_cmds.cmd);
    cfg_JOIN_INNER_TD_8288042_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8764765_cmds;
    cfg_JOIN_INNER_TD_8764765_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8764765_gqe_join (cfg_JOIN_INNER_TD_8764765_cmds.cmd);
    cfg_JOIN_INNER_TD_8764765_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8571671_cmds;
    cfg_JOIN_INNER_TD_8571671_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8571671_gqe_join (cfg_JOIN_INNER_TD_8571671_cmds.cmd);
    cfg_JOIN_INNER_TD_8571671_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    AggrBufferTmp buftmp_a(context_a); 
    buftmp_a.BufferInitial(q_a); 
    std::cout << std::endl; 
    AggrKrnlEngine krnl_Aggregate_TD_384003;
    krnl_Aggregate_TD_384003 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_384003.setup(tbl_Union_TD_4182112_output, tbl_Aggregate_TD_384003_output_preprocess, cfg_Aggregate_TD_384003_cmds, cfg_Aggregate_TD_384003_cmds_out, buftmp_a);
    AggrKrnlEngine krnl_Aggregate_TD_5453244;
    krnl_Aggregate_TD_5453244 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_5453244.setup(tbl_JOIN_INNER_TD_6989915_output, tbl_Aggregate_TD_5453244_output_preprocess, cfg_Aggregate_TD_5453244_cmds, cfg_Aggregate_TD_5453244_cmds_out, buftmp_a);
    AggrKrnlEngine krnl_Aggregate_TD_5894224;
    krnl_Aggregate_TD_5894224 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_5894224.setup(tbl_JOIN_INNER_TD_6766694_output, tbl_Aggregate_TD_5894224_output_preprocess, cfg_Aggregate_TD_5894224_cmds, cfg_Aggregate_TD_5894224_cmds_out, buftmp_a);
    AggrKrnlEngine krnl_Aggregate_TD_5343411;
    krnl_Aggregate_TD_5343411 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_5343411.setup(tbl_JOIN_INNER_TD_6758993_output, tbl_Aggregate_TD_5343411_output_preprocess, cfg_Aggregate_TD_5343411_cmds, cfg_Aggregate_TD_5343411_cmds_out, buftmp_a);
    krnlEngine krnl_JOIN_INNER_TD_6989915;
    krnl_JOIN_INNER_TD_6989915 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_6989915.setup(tbl_JOIN_INNER_TD_7433416_output, tbl_JOIN_LEFTSEMI_TD_7347442_output, tbl_JOIN_INNER_TD_6989915_output_preprocess, cfg_JOIN_INNER_TD_6989915_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_6766694;
    krnl_JOIN_INNER_TD_6766694 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_6766694.setup(tbl_JOIN_INNER_TD_7860766_output, tbl_JOIN_LEFTSEMI_TD_7724291_output, tbl_JOIN_INNER_TD_6766694_output_preprocess, cfg_JOIN_INNER_TD_6766694_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_6758993;
    krnl_JOIN_INNER_TD_6758993 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_6758993.setup(tbl_JOIN_INNER_TD_7445700_output, tbl_JOIN_LEFTSEMI_TD_7524644_output, tbl_JOIN_INNER_TD_6758993_output_preprocess, cfg_JOIN_INNER_TD_6758993_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_7433416;
    krnl_JOIN_INNER_TD_7433416 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7433416.setup(tbl_JOIN_INNER_TD_8288042_output, tbl_Filter_TD_8631152_output, tbl_JOIN_INNER_TD_7433416_output, cfg_JOIN_INNER_TD_7433416_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_7347442;
    krnl_JOIN_LEFTSEMI_TD_7347442 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTSEMI_TD_7347442.setup(tbl_Filter_TD_8428670_output, tbl_Filter_TD_8207053_output, tbl_JOIN_LEFTSEMI_TD_7347442_output, cfg_JOIN_LEFTSEMI_TD_7347442_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_7860766;
    krnl_JOIN_INNER_TD_7860766 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7860766.setup(tbl_JOIN_INNER_TD_8764765_output, tbl_Filter_TD_8614172_output, tbl_JOIN_INNER_TD_7860766_output, cfg_JOIN_INNER_TD_7860766_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_7724291;
    krnl_JOIN_LEFTSEMI_TD_7724291 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTSEMI_TD_7724291.setup(tbl_Filter_TD_872308_output, tbl_Filter_TD_8333166_output, tbl_JOIN_LEFTSEMI_TD_7724291_output, cfg_JOIN_LEFTSEMI_TD_7724291_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_7445700;
    krnl_JOIN_INNER_TD_7445700 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7445700.setup(tbl_JOIN_INNER_TD_8571671_output, tbl_Filter_TD_8154288_output, tbl_JOIN_INNER_TD_7445700_output, cfg_JOIN_INNER_TD_7445700_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_7524644;
    krnl_JOIN_LEFTSEMI_TD_7524644 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTSEMI_TD_7524644.setup(tbl_Filter_TD_8693444_output, tbl_Filter_TD_8603282_output, tbl_JOIN_LEFTSEMI_TD_7524644_output, cfg_JOIN_LEFTSEMI_TD_7524644_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_8288042;
    krnl_JOIN_INNER_TD_8288042 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8288042.setup(tbl_Filter_TD_9812505_output, tbl_Filter_TD_9816920_output, tbl_JOIN_INNER_TD_8288042_output, cfg_JOIN_INNER_TD_8288042_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_8764765;
    krnl_JOIN_INNER_TD_8764765 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8764765.setup(tbl_Filter_TD_9305145_output, tbl_Filter_TD_9443408_output, tbl_JOIN_INNER_TD_8764765_output, cfg_JOIN_INNER_TD_8764765_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_8571671;
    krnl_JOIN_INNER_TD_8571671 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8571671.setup(tbl_Filter_TD_973621_output, tbl_Filter_TD_9411587_output, tbl_JOIN_INNER_TD_8571671_output, cfg_JOIN_INNER_TD_8571671_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_Aggregate_TD_384003;
    trans_Aggregate_TD_384003.setq(q_a);
    trans_Aggregate_TD_384003.add(&(cfg_Aggregate_TD_384003_cmds));
    transEngine trans_Aggregate_TD_384003_out;
    trans_Aggregate_TD_384003_out.setq(q_a);
    q_a.finish();
    transEngine trans_Aggregate_TD_5453244;
    trans_Aggregate_TD_5453244.setq(q_a);
    trans_Aggregate_TD_5453244.add(&(cfg_Aggregate_TD_5453244_cmds));
    transEngine trans_Aggregate_TD_5453244_out;
    trans_Aggregate_TD_5453244_out.setq(q_a);
    q_a.finish();
    transEngine trans_Aggregate_TD_5894224;
    trans_Aggregate_TD_5894224.setq(q_a);
    trans_Aggregate_TD_5894224.add(&(cfg_Aggregate_TD_5894224_cmds));
    transEngine trans_Aggregate_TD_5894224_out;
    trans_Aggregate_TD_5894224_out.setq(q_a);
    q_a.finish();
    transEngine trans_Aggregate_TD_5343411;
    trans_Aggregate_TD_5343411.setq(q_a);
    trans_Aggregate_TD_5343411.add(&(cfg_Aggregate_TD_5343411_cmds));
    transEngine trans_Aggregate_TD_5343411_out;
    trans_Aggregate_TD_5343411_out.setq(q_a);
    q_a.finish();
    transEngine trans_JOIN_INNER_TD_6989915;
    trans_JOIN_INNER_TD_6989915.setq(q_h);
    trans_JOIN_INNER_TD_6989915.add(&(cfg_JOIN_INNER_TD_6989915_cmds));
    transEngine trans_JOIN_INNER_TD_6989915_out;
    trans_JOIN_INNER_TD_6989915_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_6766694;
    trans_JOIN_INNER_TD_6766694.setq(q_h);
    trans_JOIN_INNER_TD_6766694.add(&(cfg_JOIN_INNER_TD_6766694_cmds));
    transEngine trans_JOIN_INNER_TD_6766694_out;
    trans_JOIN_INNER_TD_6766694_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_6758993;
    trans_JOIN_INNER_TD_6758993.setq(q_h);
    trans_JOIN_INNER_TD_6758993.add(&(cfg_JOIN_INNER_TD_6758993_cmds));
    transEngine trans_JOIN_INNER_TD_6758993_out;
    trans_JOIN_INNER_TD_6758993_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_7433416;
    trans_JOIN_INNER_TD_7433416.setq(q_h);
    trans_JOIN_INNER_TD_7433416.add(&(cfg_JOIN_INNER_TD_7433416_cmds));
    q_h.finish();
    transEngine trans_JOIN_LEFTSEMI_TD_7347442;
    trans_JOIN_LEFTSEMI_TD_7347442.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_7347442.add(&(cfg_JOIN_LEFTSEMI_TD_7347442_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_7860766;
    trans_JOIN_INNER_TD_7860766.setq(q_h);
    trans_JOIN_INNER_TD_7860766.add(&(cfg_JOIN_INNER_TD_7860766_cmds));
    q_h.finish();
    transEngine trans_JOIN_LEFTSEMI_TD_7724291;
    trans_JOIN_LEFTSEMI_TD_7724291.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_7724291.add(&(cfg_JOIN_LEFTSEMI_TD_7724291_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_7445700;
    trans_JOIN_INNER_TD_7445700.setq(q_h);
    trans_JOIN_INNER_TD_7445700.add(&(cfg_JOIN_INNER_TD_7445700_cmds));
    q_h.finish();
    transEngine trans_JOIN_LEFTSEMI_TD_7524644;
    trans_JOIN_LEFTSEMI_TD_7524644.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_7524644.add(&(cfg_JOIN_LEFTSEMI_TD_7524644_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_8288042;
    trans_JOIN_INNER_TD_8288042.setq(q_h);
    trans_JOIN_INNER_TD_8288042.add(&(cfg_JOIN_INNER_TD_8288042_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_8764765;
    trans_JOIN_INNER_TD_8764765.setq(q_h);
    trans_JOIN_INNER_TD_8764765.add(&(cfg_JOIN_INNER_TD_8764765_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_8571671;
    trans_JOIN_INNER_TD_8571671.setq(q_h);
    trans_JOIN_INNER_TD_8571671.add(&(cfg_JOIN_INNER_TD_8571671_cmds));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_384003;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_384003;
    std::vector<cl::Event> events_Aggregate_TD_384003;
    events_h2d_wr_Aggregate_TD_384003.resize(1);
    events_d2h_rd_Aggregate_TD_384003.resize(1);
    events_Aggregate_TD_384003.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_384003;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_384003;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_5453244;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_5453244;
    std::vector<cl::Event> events_Aggregate_TD_5453244;
    events_h2d_wr_Aggregate_TD_5453244.resize(1);
    events_d2h_rd_Aggregate_TD_5453244.resize(1);
    events_Aggregate_TD_5453244.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_5453244;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_5453244;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_5894224;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_5894224;
    std::vector<cl::Event> events_Aggregate_TD_5894224;
    events_h2d_wr_Aggregate_TD_5894224.resize(1);
    events_d2h_rd_Aggregate_TD_5894224.resize(1);
    events_Aggregate_TD_5894224.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_5894224;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_5894224;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_5343411;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_5343411;
    std::vector<cl::Event> events_Aggregate_TD_5343411;
    events_h2d_wr_Aggregate_TD_5343411.resize(1);
    events_d2h_rd_Aggregate_TD_5343411.resize(1);
    events_Aggregate_TD_5343411.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_5343411;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_5343411;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_6989915;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_6989915;
    std::vector<cl::Event> events_JOIN_INNER_TD_6989915;
    events_h2d_wr_JOIN_INNER_TD_6989915.resize(1);
    events_d2h_rd_JOIN_INNER_TD_6989915.resize(1);
    events_JOIN_INNER_TD_6989915.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_6989915;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_6989915;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_6766694;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_6766694;
    std::vector<cl::Event> events_JOIN_INNER_TD_6766694;
    events_h2d_wr_JOIN_INNER_TD_6766694.resize(1);
    events_d2h_rd_JOIN_INNER_TD_6766694.resize(1);
    events_JOIN_INNER_TD_6766694.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_6766694;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_6766694;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_6758993;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_6758993;
    std::vector<cl::Event> events_JOIN_INNER_TD_6758993;
    events_h2d_wr_JOIN_INNER_TD_6758993.resize(1);
    events_d2h_rd_JOIN_INNER_TD_6758993.resize(1);
    events_JOIN_INNER_TD_6758993.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_6758993;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_6758993;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7433416;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7433416;
    std::vector<cl::Event> events_JOIN_INNER_TD_7433416;
    events_h2d_wr_JOIN_INNER_TD_7433416.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7433416.resize(1);
    events_JOIN_INNER_TD_7433416.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7433416;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7433416;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_7347442;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_7347442;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_7347442;
    events_h2d_wr_JOIN_LEFTSEMI_TD_7347442.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_7347442.resize(1);
    events_JOIN_LEFTSEMI_TD_7347442.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_7347442;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_7347442;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7860766;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7860766;
    std::vector<cl::Event> events_JOIN_INNER_TD_7860766;
    events_h2d_wr_JOIN_INNER_TD_7860766.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7860766.resize(1);
    events_JOIN_INNER_TD_7860766.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7860766;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7860766;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_7724291;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_7724291;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_7724291;
    events_h2d_wr_JOIN_LEFTSEMI_TD_7724291.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_7724291.resize(1);
    events_JOIN_LEFTSEMI_TD_7724291.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_7724291;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_7724291;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7445700;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7445700;
    std::vector<cl::Event> events_JOIN_INNER_TD_7445700;
    events_h2d_wr_JOIN_INNER_TD_7445700.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7445700.resize(1);
    events_JOIN_INNER_TD_7445700.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7445700;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7445700;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_7524644;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_7524644;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_7524644;
    events_h2d_wr_JOIN_LEFTSEMI_TD_7524644.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_7524644.resize(1);
    events_JOIN_LEFTSEMI_TD_7524644.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_7524644;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_7524644;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8288042;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8288042;
    std::vector<cl::Event> events_JOIN_INNER_TD_8288042;
    events_h2d_wr_JOIN_INNER_TD_8288042.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8288042.resize(1);
    events_JOIN_INNER_TD_8288042.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8288042;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8288042;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8764765;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8764765;
    std::vector<cl::Event> events_JOIN_INNER_TD_8764765;
    events_h2d_wr_JOIN_INNER_TD_8764765.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8764765.resize(1);
    events_JOIN_INNER_TD_8764765.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8764765;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8764765;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8571671;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8571671;
    std::vector<cl::Event> events_JOIN_INNER_TD_8571671;
    events_h2d_wr_JOIN_INNER_TD_8571671.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8571671.resize(1);
    events_JOIN_INNER_TD_8571671.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8571671;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8571671;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_9_256315_s, tv_r_Filter_9_256315_e;
    gettimeofday(&tv_r_Filter_9_256315_s, 0);
    SW_Filter_TD_9411587(tbl_SerializeFromObject_TD_10336437_input, tbl_Filter_TD_9411587_output);
    gettimeofday(&tv_r_Filter_9_256315_e, 0);

    struct timeval tv_r_Filter_9_55433_s, tv_r_Filter_9_55433_e;
    gettimeofday(&tv_r_Filter_9_55433_s, 0);
    SW_Filter_TD_973621(tbl_SerializeFromObject_TD_10310544_input, tbl_Filter_TD_973621_output);
    gettimeofday(&tv_r_Filter_9_55433_e, 0);

    struct timeval tv_r_Filter_9_125474_s, tv_r_Filter_9_125474_e;
    gettimeofday(&tv_r_Filter_9_125474_s, 0);
    SW_Filter_TD_9443408(tbl_SerializeFromObject_TD_10451965_input, tbl_Filter_TD_9443408_output);
    gettimeofday(&tv_r_Filter_9_125474_e, 0);

    struct timeval tv_r_Filter_9_700516_s, tv_r_Filter_9_700516_e;
    gettimeofday(&tv_r_Filter_9_700516_s, 0);
    SW_Filter_TD_9305145(tbl_SerializeFromObject_TD_10815152_input, tbl_Filter_TD_9305145_output);
    gettimeofday(&tv_r_Filter_9_700516_e, 0);

    struct timeval tv_r_Filter_9_364367_s, tv_r_Filter_9_364367_e;
    gettimeofday(&tv_r_Filter_9_364367_s, 0);
    SW_Filter_TD_9816920(tbl_SerializeFromObject_TD_1029519_input, tbl_Filter_TD_9816920_output);
    gettimeofday(&tv_r_Filter_9_364367_e, 0);

    struct timeval tv_r_Filter_9_519459_s, tv_r_Filter_9_519459_e;
    gettimeofday(&tv_r_Filter_9_519459_s, 0);
    SW_Filter_TD_9812505(tbl_SerializeFromObject_TD_10635206_input, tbl_Filter_TD_9812505_output);
    gettimeofday(&tv_r_Filter_9_519459_e, 0);

    struct timeval tv_r_Filter_8_5370_s, tv_r_Filter_8_5370_e;
    gettimeofday(&tv_r_Filter_8_5370_s, 0);
    SW_Filter_TD_8693444(tbl_SerializeFromObject_TD_981526_input, tbl_Filter_TD_8693444_output);
    gettimeofday(&tv_r_Filter_8_5370_e, 0);

    struct timeval tv_r_Filter_8_724415_s, tv_r_Filter_8_724415_e;
    gettimeofday(&tv_r_Filter_8_724415_s, 0);
    SW_Filter_TD_8603282(tbl_SerializeFromObject_TD_9714270_input, tbl_Filter_TD_8603282_output);
    gettimeofday(&tv_r_Filter_8_724415_e, 0);

    struct timeval tv_r_Filter_8_108459_s, tv_r_Filter_8_108459_e;
    gettimeofday(&tv_r_Filter_8_108459_s, 0);
    SW_Filter_TD_8154288(tbl_SerializeFromObject_TD_9706056_input, tbl_Filter_TD_8154288_output);
    gettimeofday(&tv_r_Filter_8_108459_e, 0);

    struct timeval tv_r_JOIN_INNER_8_650343_s, tv_r_JOIN_INNER_8_650343_e;
    gettimeofday(&tv_r_JOIN_INNER_8_650343_s, 0);
    trans_JOIN_INNER_TD_8571671.add(&(tbl_Filter_TD_973621_output));
    trans_JOIN_INNER_TD_8571671.add(&(tbl_Filter_TD_9411587_output));
    trans_JOIN_INNER_TD_8571671.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8571671), &(events_h2d_wr_JOIN_INNER_TD_8571671[0]));
    events_grp_JOIN_INNER_TD_8571671.push_back(events_h2d_wr_JOIN_INNER_TD_8571671[0]);
    krnl_JOIN_INNER_TD_8571671.run(0, &(events_grp_JOIN_INNER_TD_8571671), &(events_JOIN_INNER_TD_8571671[0]));
    gettimeofday(&tv_r_JOIN_INNER_8_650343_e, 0);

    struct timeval tv_r_Filter_8_184053_s, tv_r_Filter_8_184053_e;
    gettimeofday(&tv_r_Filter_8_184053_s, 0);
    SW_Filter_TD_872308(tbl_SerializeFromObject_TD_9538311_input, tbl_Filter_TD_872308_output);
    gettimeofday(&tv_r_Filter_8_184053_e, 0);

    struct timeval tv_r_Filter_8_883117_s, tv_r_Filter_8_883117_e;
    gettimeofday(&tv_r_Filter_8_883117_s, 0);
    SW_Filter_TD_8333166(tbl_SerializeFromObject_TD_9385979_input, tbl_Filter_TD_8333166_output);
    gettimeofday(&tv_r_Filter_8_883117_e, 0);

    struct timeval tv_r_Filter_8_303458_s, tv_r_Filter_8_303458_e;
    gettimeofday(&tv_r_Filter_8_303458_s, 0);
    SW_Filter_TD_8614172(tbl_SerializeFromObject_TD_9210785_input, tbl_Filter_TD_8614172_output);
    gettimeofday(&tv_r_Filter_8_303458_e, 0);

    struct timeval tv_r_JOIN_INNER_8_806515_s, tv_r_JOIN_INNER_8_806515_e;
    gettimeofday(&tv_r_JOIN_INNER_8_806515_s, 0);
    trans_JOIN_INNER_TD_8764765.add(&(tbl_Filter_TD_9305145_output));
    trans_JOIN_INNER_TD_8764765.add(&(tbl_Filter_TD_9443408_output));
    trans_JOIN_INNER_TD_8764765.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8764765), &(events_h2d_wr_JOIN_INNER_TD_8764765[0]));
    events_grp_JOIN_INNER_TD_8764765.push_back(events_h2d_wr_JOIN_INNER_TD_8764765[0]);
    krnl_JOIN_INNER_TD_8764765.run(0, &(events_grp_JOIN_INNER_TD_8764765), &(events_JOIN_INNER_TD_8764765[0]));
    gettimeofday(&tv_r_JOIN_INNER_8_806515_e, 0);

    struct timeval tv_r_Filter_8_952890_s, tv_r_Filter_8_952890_e;
    gettimeofday(&tv_r_Filter_8_952890_s, 0);
    SW_Filter_TD_8428670(tbl_SerializeFromObject_TD_9919217_input, tbl_Filter_TD_8428670_output);
    gettimeofday(&tv_r_Filter_8_952890_e, 0);

    struct timeval tv_r_Filter_8_913279_s, tv_r_Filter_8_913279_e;
    gettimeofday(&tv_r_Filter_8_913279_s, 0);
    SW_Filter_TD_8207053(tbl_SerializeFromObject_TD_9154893_input, tbl_Filter_TD_8207053_output);
    gettimeofday(&tv_r_Filter_8_913279_e, 0);

    struct timeval tv_r_Filter_8_830647_s, tv_r_Filter_8_830647_e;
    gettimeofday(&tv_r_Filter_8_830647_s, 0);
    SW_Filter_TD_8631152(tbl_SerializeFromObject_TD_9293274_input, tbl_Filter_TD_8631152_output);
    gettimeofday(&tv_r_Filter_8_830647_e, 0);

    struct timeval tv_r_JOIN_INNER_8_231340_s, tv_r_JOIN_INNER_8_231340_e;
    gettimeofday(&tv_r_JOIN_INNER_8_231340_s, 0);
    trans_JOIN_INNER_TD_8288042.add(&(tbl_Filter_TD_9812505_output));
    trans_JOIN_INNER_TD_8288042.add(&(tbl_Filter_TD_9816920_output));
    trans_JOIN_INNER_TD_8288042.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8288042), &(events_h2d_wr_JOIN_INNER_TD_8288042[0]));
    events_grp_JOIN_INNER_TD_8288042.push_back(events_h2d_wr_JOIN_INNER_TD_8288042[0]);
    krnl_JOIN_INNER_TD_8288042.run(0, &(events_grp_JOIN_INNER_TD_8288042), &(events_JOIN_INNER_TD_8288042[0]));
    gettimeofday(&tv_r_JOIN_INNER_8_231340_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_7_727525_s, tv_r_JOIN_LEFTSEMI_7_727525_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_727525_s, 0);
    trans_JOIN_LEFTSEMI_TD_7524644.add(&(tbl_Filter_TD_8603282_output));
    trans_JOIN_LEFTSEMI_TD_7524644.add(&(tbl_Filter_TD_8693444_output));
    trans_JOIN_LEFTSEMI_TD_7524644.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_7524644), &(events_h2d_wr_JOIN_LEFTSEMI_TD_7524644[0]));
    events_grp_JOIN_LEFTSEMI_TD_7524644.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_7524644[0]);
    krnl_JOIN_LEFTSEMI_TD_7524644.run(0, &(events_grp_JOIN_LEFTSEMI_TD_7524644), &(events_JOIN_LEFTSEMI_TD_7524644[0]));
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_727525_e, 0);

    struct timeval tv_r_JOIN_INNER_7_486575_s, tv_r_JOIN_INNER_7_486575_e;
    gettimeofday(&tv_r_JOIN_INNER_7_486575_s, 0);
    prev_events_grp_JOIN_INNER_TD_7445700.push_back(events_h2d_wr_JOIN_INNER_TD_8571671[0]);
    trans_JOIN_INNER_TD_7445700.add(&(tbl_Filter_TD_8154288_output));
    trans_JOIN_INNER_TD_7445700.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7445700), &(events_h2d_wr_JOIN_INNER_TD_7445700[0]));
    events_grp_JOIN_INNER_TD_7445700.push_back(events_h2d_wr_JOIN_INNER_TD_7445700[0]);
    events_grp_JOIN_INNER_TD_7445700.push_back(events_JOIN_INNER_TD_8571671[0]);
    krnl_JOIN_INNER_TD_7445700.run(0, &(events_grp_JOIN_INNER_TD_7445700), &(events_JOIN_INNER_TD_7445700[0]));
    gettimeofday(&tv_r_JOIN_INNER_7_486575_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_7_880241_s, tv_r_JOIN_LEFTSEMI_7_880241_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_880241_s, 0);
    trans_JOIN_LEFTSEMI_TD_7724291.add(&(tbl_Filter_TD_8333166_output));
    trans_JOIN_LEFTSEMI_TD_7724291.add(&(tbl_Filter_TD_872308_output));
    trans_JOIN_LEFTSEMI_TD_7724291.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_7724291), &(events_h2d_wr_JOIN_LEFTSEMI_TD_7724291[0]));
    events_grp_JOIN_LEFTSEMI_TD_7724291.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_7724291[0]);
    krnl_JOIN_LEFTSEMI_TD_7724291.run(0, &(events_grp_JOIN_LEFTSEMI_TD_7724291), &(events_JOIN_LEFTSEMI_TD_7724291[0]));
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_880241_e, 0);

    struct timeval tv_r_JOIN_INNER_7_956131_s, tv_r_JOIN_INNER_7_956131_e;
    gettimeofday(&tv_r_JOIN_INNER_7_956131_s, 0);
    prev_events_grp_JOIN_INNER_TD_7860766.push_back(events_h2d_wr_JOIN_INNER_TD_8764765[0]);
    trans_JOIN_INNER_TD_7860766.add(&(tbl_Filter_TD_8614172_output));
    trans_JOIN_INNER_TD_7860766.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7860766), &(events_h2d_wr_JOIN_INNER_TD_7860766[0]));
    events_grp_JOIN_INNER_TD_7860766.push_back(events_h2d_wr_JOIN_INNER_TD_7860766[0]);
    events_grp_JOIN_INNER_TD_7860766.push_back(events_JOIN_INNER_TD_8764765[0]);
    krnl_JOIN_INNER_TD_7860766.run(0, &(events_grp_JOIN_INNER_TD_7860766), &(events_JOIN_INNER_TD_7860766[0]));
    gettimeofday(&tv_r_JOIN_INNER_7_956131_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_7_972846_s, tv_r_JOIN_LEFTSEMI_7_972846_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_972846_s, 0);
    trans_JOIN_LEFTSEMI_TD_7347442.add(&(tbl_Filter_TD_8207053_output));
    trans_JOIN_LEFTSEMI_TD_7347442.add(&(tbl_Filter_TD_8428670_output));
    trans_JOIN_LEFTSEMI_TD_7347442.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_7347442), &(events_h2d_wr_JOIN_LEFTSEMI_TD_7347442[0]));
    events_grp_JOIN_LEFTSEMI_TD_7347442.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_7347442[0]);
    krnl_JOIN_LEFTSEMI_TD_7347442.run(0, &(events_grp_JOIN_LEFTSEMI_TD_7347442), &(events_JOIN_LEFTSEMI_TD_7347442[0]));
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_972846_e, 0);

    struct timeval tv_r_JOIN_INNER_7_36242_s, tv_r_JOIN_INNER_7_36242_e;
    gettimeofday(&tv_r_JOIN_INNER_7_36242_s, 0);
    prev_events_grp_JOIN_INNER_TD_7433416.push_back(events_h2d_wr_JOIN_INNER_TD_8288042[0]);
    trans_JOIN_INNER_TD_7433416.add(&(tbl_Filter_TD_8631152_output));
    trans_JOIN_INNER_TD_7433416.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7433416), &(events_h2d_wr_JOIN_INNER_TD_7433416[0]));
    events_grp_JOIN_INNER_TD_7433416.push_back(events_h2d_wr_JOIN_INNER_TD_7433416[0]);
    events_grp_JOIN_INNER_TD_7433416.push_back(events_JOIN_INNER_TD_8288042[0]);
    krnl_JOIN_INNER_TD_7433416.run(0, &(events_grp_JOIN_INNER_TD_7433416), &(events_JOIN_INNER_TD_7433416[0]));
    gettimeofday(&tv_r_JOIN_INNER_7_36242_e, 0);

    struct timeval tv_r_JOIN_INNER_6_86034_s, tv_r_JOIN_INNER_6_86034_e;
    gettimeofday(&tv_r_JOIN_INNER_6_86034_s, 0);
    prev_events_grp_JOIN_INNER_TD_6758993.push_back(events_h2d_wr_JOIN_INNER_TD_7445700[0]);
    prev_events_grp_JOIN_INNER_TD_6758993.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_7524644[0]);
    trans_JOIN_INNER_TD_6758993.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_6758993), &(events_h2d_wr_JOIN_INNER_TD_6758993[0]));
    events_grp_JOIN_INNER_TD_6758993.push_back(events_h2d_wr_JOIN_INNER_TD_6758993[0]);
    events_grp_JOIN_INNER_TD_6758993.push_back(events_JOIN_INNER_TD_7445700[0]);
    events_grp_JOIN_INNER_TD_6758993.push_back(events_JOIN_LEFTSEMI_TD_7524644[0]);
    krnl_JOIN_INNER_TD_6758993.run(0, &(events_grp_JOIN_INNER_TD_6758993), &(events_JOIN_INNER_TD_6758993[0]));
    
    trans_JOIN_INNER_TD_6758993_out.add(&(tbl_JOIN_INNER_TD_6758993_output_preprocess));
    trans_JOIN_INNER_TD_6758993_out.dev2host(0, &(events_JOIN_INNER_TD_6758993), &(events_d2h_rd_JOIN_INNER_TD_6758993[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_6758993);
    tbl_JOIN_INNER_TD_6758993_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_6758993_output));
    gettimeofday(&tv_r_JOIN_INNER_6_86034_e, 0);

    struct timeval tv_r_JOIN_INNER_6_26020_s, tv_r_JOIN_INNER_6_26020_e;
    gettimeofday(&tv_r_JOIN_INNER_6_26020_s, 0);
    prev_events_grp_JOIN_INNER_TD_6766694.push_back(events_h2d_wr_JOIN_INNER_TD_7860766[0]);
    prev_events_grp_JOIN_INNER_TD_6766694.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_7724291[0]);
    trans_JOIN_INNER_TD_6766694.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_6766694), &(events_h2d_wr_JOIN_INNER_TD_6766694[0]));
    events_grp_JOIN_INNER_TD_6766694.push_back(events_h2d_wr_JOIN_INNER_TD_6766694[0]);
    events_grp_JOIN_INNER_TD_6766694.push_back(events_JOIN_INNER_TD_7860766[0]);
    events_grp_JOIN_INNER_TD_6766694.push_back(events_JOIN_LEFTSEMI_TD_7724291[0]);
    krnl_JOIN_INNER_TD_6766694.run(0, &(events_grp_JOIN_INNER_TD_6766694), &(events_JOIN_INNER_TD_6766694[0]));
    
    trans_JOIN_INNER_TD_6766694_out.add(&(tbl_JOIN_INNER_TD_6766694_output_preprocess));
    trans_JOIN_INNER_TD_6766694_out.dev2host(0, &(events_JOIN_INNER_TD_6766694), &(events_d2h_rd_JOIN_INNER_TD_6766694[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_6766694);
    tbl_JOIN_INNER_TD_6766694_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_6766694_output));
    gettimeofday(&tv_r_JOIN_INNER_6_26020_e, 0);

    struct timeval tv_r_JOIN_INNER_6_301483_s, tv_r_JOIN_INNER_6_301483_e;
    gettimeofday(&tv_r_JOIN_INNER_6_301483_s, 0);
    prev_events_grp_JOIN_INNER_TD_6989915.push_back(events_h2d_wr_JOIN_INNER_TD_7433416[0]);
    prev_events_grp_JOIN_INNER_TD_6989915.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_7347442[0]);
    trans_JOIN_INNER_TD_6989915.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_6989915), &(events_h2d_wr_JOIN_INNER_TD_6989915[0]));
    events_grp_JOIN_INNER_TD_6989915.push_back(events_h2d_wr_JOIN_INNER_TD_6989915[0]);
    events_grp_JOIN_INNER_TD_6989915.push_back(events_JOIN_INNER_TD_7433416[0]);
    events_grp_JOIN_INNER_TD_6989915.push_back(events_JOIN_LEFTSEMI_TD_7347442[0]);
    krnl_JOIN_INNER_TD_6989915.run(0, &(events_grp_JOIN_INNER_TD_6989915), &(events_JOIN_INNER_TD_6989915[0]));
    
    trans_JOIN_INNER_TD_6989915_out.add(&(tbl_JOIN_INNER_TD_6989915_output_preprocess));
    trans_JOIN_INNER_TD_6989915_out.dev2host(0, &(events_JOIN_INNER_TD_6989915), &(events_d2h_rd_JOIN_INNER_TD_6989915[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_6989915);
    tbl_JOIN_INNER_TD_6989915_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_6989915_output));
    gettimeofday(&tv_r_JOIN_INNER_6_301483_e, 0);

    struct timeval tv_r_Aggregate_5_650489_s, tv_r_Aggregate_5_650489_e;
    gettimeofday(&tv_r_Aggregate_5_650489_s, 0);
    trans_Aggregate_TD_5343411.add(&(tbl_JOIN_INNER_TD_6758993_output));
    trans_Aggregate_TD_5343411.host2dev(0, &(prev_events_grp_Aggregate_TD_5343411), &(events_h2d_wr_Aggregate_TD_5343411[0]));
    events_grp_Aggregate_TD_5343411.push_back(events_h2d_wr_Aggregate_TD_5343411[0]);
    krnl_Aggregate_TD_5343411.run(0, &(events_grp_Aggregate_TD_5343411), &(events_Aggregate_TD_5343411[0]));
    
    trans_Aggregate_TD_5343411_out.add(&(tbl_Aggregate_TD_5343411_output_preprocess));
    trans_Aggregate_TD_5343411_out.dev2host(0, &(events_Aggregate_TD_5343411), &(events_d2h_rd_Aggregate_TD_5343411[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_5343411_consolidate(tbl_Aggregate_TD_5343411_output_preprocess, tbl_Aggregate_TD_5343411_output);
    gettimeofday(&tv_r_Aggregate_5_650489_e, 0);

    struct timeval tv_r_Aggregate_5_324192_s, tv_r_Aggregate_5_324192_e;
    gettimeofday(&tv_r_Aggregate_5_324192_s, 0);
    trans_Aggregate_TD_5894224.add(&(tbl_JOIN_INNER_TD_6766694_output));
    trans_Aggregate_TD_5894224.host2dev(0, &(prev_events_grp_Aggregate_TD_5894224), &(events_h2d_wr_Aggregate_TD_5894224[0]));
    events_grp_Aggregate_TD_5894224.push_back(events_h2d_wr_Aggregate_TD_5894224[0]);
    krnl_Aggregate_TD_5894224.run(0, &(events_grp_Aggregate_TD_5894224), &(events_Aggregate_TD_5894224[0]));
    
    trans_Aggregate_TD_5894224_out.add(&(tbl_Aggregate_TD_5894224_output_preprocess));
    trans_Aggregate_TD_5894224_out.dev2host(0, &(events_Aggregate_TD_5894224), &(events_d2h_rd_Aggregate_TD_5894224[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_5894224_consolidate(tbl_Aggregate_TD_5894224_output_preprocess, tbl_Aggregate_TD_5894224_output);
    gettimeofday(&tv_r_Aggregate_5_324192_e, 0);

    struct timeval tv_r_Aggregate_5_503898_s, tv_r_Aggregate_5_503898_e;
    gettimeofday(&tv_r_Aggregate_5_503898_s, 0);
    trans_Aggregate_TD_5453244.add(&(tbl_JOIN_INNER_TD_6989915_output));
    trans_Aggregate_TD_5453244.host2dev(0, &(prev_events_grp_Aggregate_TD_5453244), &(events_h2d_wr_Aggregate_TD_5453244[0]));
    events_grp_Aggregate_TD_5453244.push_back(events_h2d_wr_Aggregate_TD_5453244[0]);
    krnl_Aggregate_TD_5453244.run(0, &(events_grp_Aggregate_TD_5453244), &(events_Aggregate_TD_5453244[0]));
    
    trans_Aggregate_TD_5453244_out.add(&(tbl_Aggregate_TD_5453244_output_preprocess));
    trans_Aggregate_TD_5453244_out.dev2host(0, &(events_Aggregate_TD_5453244), &(events_d2h_rd_Aggregate_TD_5453244[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_5453244_consolidate(tbl_Aggregate_TD_5453244_output_preprocess, tbl_Aggregate_TD_5453244_output);
    gettimeofday(&tv_r_Aggregate_5_503898_e, 0);

    struct timeval tv_r_Union_4_344940_s, tv_r_Union_4_344940_e;
    gettimeofday(&tv_r_Union_4_344940_s, 0);
    SW_Union_TD_4182112(tbl_Aggregate_TD_5453244_output, tbl_Aggregate_TD_5894224_output, tbl_Aggregate_TD_5343411_output, tbl_Union_TD_4182112_output);
    gettimeofday(&tv_r_Union_4_344940_e, 0);

    struct timeval tv_r_Aggregate_3_21866_s, tv_r_Aggregate_3_21866_e;
    gettimeofday(&tv_r_Aggregate_3_21866_s, 0);
    trans_Aggregate_TD_384003.add(&(tbl_Union_TD_4182112_output));
    trans_Aggregate_TD_384003.host2dev(0, &(prev_events_grp_Aggregate_TD_384003), &(events_h2d_wr_Aggregate_TD_384003[0]));
    events_grp_Aggregate_TD_384003.push_back(events_h2d_wr_Aggregate_TD_384003[0]);
    krnl_Aggregate_TD_384003.run(0, &(events_grp_Aggregate_TD_384003), &(events_Aggregate_TD_384003[0]));
    
    trans_Aggregate_TD_384003_out.add(&(tbl_Aggregate_TD_384003_output_preprocess));
    trans_Aggregate_TD_384003_out.dev2host(0, &(events_Aggregate_TD_384003), &(events_d2h_rd_Aggregate_TD_384003[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_384003_consolidate(tbl_Aggregate_TD_384003_output_preprocess, tbl_Aggregate_TD_384003_output);
    gettimeofday(&tv_r_Aggregate_3_21866_e, 0);

    struct timeval tv_r_Sort_2_295842_s, tv_r_Sort_2_295842_e;
    gettimeofday(&tv_r_Sort_2_295842_s, 0);
    SW_Sort_TD_2163636(tbl_Aggregate_TD_384003_output, tbl_Sort_TD_2163636_output);
    gettimeofday(&tv_r_Sort_2_295842_e, 0);

    struct timeval tv_r_LocalLimit_1_638050_s, tv_r_LocalLimit_1_638050_e;
    gettimeofday(&tv_r_LocalLimit_1_638050_s, 0);
    SW_LocalLimit_TD_1982910(tbl_Sort_TD_2163636_output, tbl_LocalLimit_TD_1982910_output);
    gettimeofday(&tv_r_LocalLimit_1_638050_e, 0);

    struct timeval tv_r_GlobalLimit_0_655044_s, tv_r_GlobalLimit_0_655044_e;
    gettimeofday(&tv_r_GlobalLimit_0_655044_s, 0);
    SW_GlobalLimit_TD_0979670(tbl_LocalLimit_TD_1982910_output, tbl_GlobalLimit_TD_0979670_output);
    gettimeofday(&tv_r_GlobalLimit_0_655044_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_256315_s, &tv_r_Filter_9_256315_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10336437_input: " << tbl_SerializeFromObject_TD_10336437_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_55433_s, &tv_r_Filter_9_55433_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10310544_input: " << tbl_SerializeFromObject_TD_10310544_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_125474_s, &tv_r_Filter_9_125474_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10451965_input: " << tbl_SerializeFromObject_TD_10451965_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_700516_s, &tv_r_Filter_9_700516_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10815152_input: " << tbl_SerializeFromObject_TD_10815152_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_364367_s, &tv_r_Filter_9_364367_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1029519_input: " << tbl_SerializeFromObject_TD_1029519_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_519459_s, &tv_r_Filter_9_519459_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10635206_input: " << tbl_SerializeFromObject_TD_10635206_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_5370_s, &tv_r_Filter_8_5370_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_981526_input: " << tbl_SerializeFromObject_TD_981526_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_724415_s, &tv_r_Filter_8_724415_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9714270_input: " << tbl_SerializeFromObject_TD_9714270_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_108459_s, &tv_r_Filter_8_108459_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9706056_input: " << tbl_SerializeFromObject_TD_9706056_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_650343_s, &tv_r_JOIN_INNER_8_650343_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_973621_output: " << tbl_Filter_TD_973621_output.getNumRow() << " " << "tbl_Filter_TD_9411587_output: " << tbl_Filter_TD_9411587_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_184053_s, &tv_r_Filter_8_184053_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9538311_input: " << tbl_SerializeFromObject_TD_9538311_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_883117_s, &tv_r_Filter_8_883117_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9385979_input: " << tbl_SerializeFromObject_TD_9385979_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_303458_s, &tv_r_Filter_8_303458_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9210785_input: " << tbl_SerializeFromObject_TD_9210785_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_806515_s, &tv_r_JOIN_INNER_8_806515_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9305145_output: " << tbl_Filter_TD_9305145_output.getNumRow() << " " << "tbl_Filter_TD_9443408_output: " << tbl_Filter_TD_9443408_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_952890_s, &tv_r_Filter_8_952890_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9919217_input: " << tbl_SerializeFromObject_TD_9919217_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_913279_s, &tv_r_Filter_8_913279_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9154893_input: " << tbl_SerializeFromObject_TD_9154893_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_830647_s, &tv_r_Filter_8_830647_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9293274_input: " << tbl_SerializeFromObject_TD_9293274_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_231340_s, &tv_r_JOIN_INNER_8_231340_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9812505_output: " << tbl_Filter_TD_9812505_output.getNumRow() << " " << "tbl_Filter_TD_9816920_output: " << tbl_Filter_TD_9816920_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_7: " << tvdiff(&tv_r_JOIN_LEFTSEMI_7_727525_s, &tv_r_JOIN_LEFTSEMI_7_727525_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8603282_output: " << tbl_Filter_TD_8603282_output.getNumRow() << " " << "tbl_Filter_TD_8693444_output: " << tbl_Filter_TD_8693444_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_486575_s, &tv_r_JOIN_INNER_7_486575_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8571671_output: " << tbl_JOIN_INNER_TD_8571671_output.getNumRow() << " " << "tbl_Filter_TD_8154288_output: " << tbl_Filter_TD_8154288_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_7: " << tvdiff(&tv_r_JOIN_LEFTSEMI_7_880241_s, &tv_r_JOIN_LEFTSEMI_7_880241_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8333166_output: " << tbl_Filter_TD_8333166_output.getNumRow() << " " << "tbl_Filter_TD_872308_output: " << tbl_Filter_TD_872308_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_956131_s, &tv_r_JOIN_INNER_7_956131_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8764765_output: " << tbl_JOIN_INNER_TD_8764765_output.getNumRow() << " " << "tbl_Filter_TD_8614172_output: " << tbl_Filter_TD_8614172_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_7: " << tvdiff(&tv_r_JOIN_LEFTSEMI_7_972846_s, &tv_r_JOIN_LEFTSEMI_7_972846_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8207053_output: " << tbl_Filter_TD_8207053_output.getNumRow() << " " << "tbl_Filter_TD_8428670_output: " << tbl_Filter_TD_8428670_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_36242_s, &tv_r_JOIN_INNER_7_36242_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8288042_output: " << tbl_JOIN_INNER_TD_8288042_output.getNumRow() << " " << "tbl_Filter_TD_8631152_output: " << tbl_Filter_TD_8631152_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_86034_s, &tv_r_JOIN_INNER_6_86034_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7445700_output: " << tbl_JOIN_INNER_TD_7445700_output.getNumRow() << " " << "tbl_JOIN_LEFTSEMI_TD_7524644_output: " << tbl_JOIN_LEFTSEMI_TD_7524644_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_26020_s, &tv_r_JOIN_INNER_6_26020_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7860766_output: " << tbl_JOIN_INNER_TD_7860766_output.getNumRow() << " " << "tbl_JOIN_LEFTSEMI_TD_7724291_output: " << tbl_JOIN_LEFTSEMI_TD_7724291_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_301483_s, &tv_r_JOIN_INNER_6_301483_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7433416_output: " << tbl_JOIN_INNER_TD_7433416_output.getNumRow() << " " << "tbl_JOIN_LEFTSEMI_TD_7347442_output: " << tbl_JOIN_LEFTSEMI_TD_7347442_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_650489_s, &tv_r_Aggregate_5_650489_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6758993_output: " << tbl_JOIN_INNER_TD_6758993_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_324192_s, &tv_r_Aggregate_5_324192_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6766694_output: " << tbl_JOIN_INNER_TD_6766694_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_503898_s, &tv_r_Aggregate_5_503898_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6989915_output: " << tbl_JOIN_INNER_TD_6989915_output.getNumRow() << " " << std::endl; 

    std::cout << "Union_4: " << tvdiff(&tv_r_Union_4_344940_s, &tv_r_Union_4_344940_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_5453244_output: " << tbl_Aggregate_TD_5453244_output.getNumRow() << " " << "tbl_Aggregate_TD_5894224_output: " << tbl_Aggregate_TD_5894224_output.getNumRow() << " " << "tbl_Aggregate_TD_5343411_output: " << tbl_Aggregate_TD_5343411_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_21866_s, &tv_r_Aggregate_3_21866_e) / 1000.0 << " ms " 
     << "tbl_Union_TD_4182112_output: " << tbl_Union_TD_4182112_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_295842_s, &tv_r_Sort_2_295842_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_384003_output: " << tbl_Aggregate_TD_384003_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_638050_s, &tv_r_LocalLimit_1_638050_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2163636_output: " << tbl_Sort_TD_2163636_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_655044_s, &tv_r_GlobalLimit_0_655044_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1982910_output: " << tbl_LocalLimit_TD_1982910_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.495854 * 1000 << "ms" << std::endl; 
    return 0; 
}
