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

#include "cfgFunc_q77.hpp" 
#include "q77.hpp" 

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
    std::cout << "NOTE:running query #77\n."; 
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
    Table tbl_GlobalLimit_TD_0369527_output("tbl_GlobalLimit_TD_0369527_output", 6100000, 5, "");
    tbl_GlobalLimit_TD_0369527_output.allocateHost();
    Table tbl_LocalLimit_TD_1514409_output("tbl_LocalLimit_TD_1514409_output", 6100000, 5, "");
    tbl_LocalLimit_TD_1514409_output.allocateHost();
    Table tbl_Sort_TD_2219717_output("tbl_Sort_TD_2219717_output", 6100000, 5, "");
    tbl_Sort_TD_2219717_output.allocateHost();
    Table tbl_Aggregate_TD_3725792_output("tbl_Aggregate_TD_3725792_output", 6100000, 5, "");
    tbl_Aggregate_TD_3725792_output.allocateHost();
    Table tbl_Expand_TD_44392_output("tbl_Expand_TD_44392_output", 6100000, 6, "");
    tbl_Expand_TD_44392_output.allocateHost();
    Table tbl_Union_TD_5775228_output("tbl_Union_TD_5775228_output", 6100000, 5, "");
    tbl_Union_TD_5775228_output.allocateHost();
    Table tbl_Project_TD_6172041_output("tbl_Project_TD_6172041_output", 6100000, 5, "");
    tbl_Project_TD_6172041_output.allocateHost();
    Table tbl_Project_TD_6997933_output("tbl_Project_TD_6997933_output", 6100000, 5, "");
    tbl_Project_TD_6997933_output.allocateHost();
    Table tbl_Project_TD_6224311_output("tbl_Project_TD_6224311_output", 6100000, 5, "");
    tbl_Project_TD_6224311_output.allocateHost();
    Table tbl_JOIN_LEFTOUTER_TD_7746880_output("tbl_JOIN_LEFTOUTER_TD_7746880_output", 6100000, 5, "");
    tbl_JOIN_LEFTOUTER_TD_7746880_output.allocateHost();
    Table tbl_JOIN_CROSS_TD_7789765_output("tbl_JOIN_CROSS_TD_7789765_output", 6100000, 5, "");
    tbl_JOIN_CROSS_TD_7789765_output.allocateHost();
    Table tbl_JOIN_LEFTOUTER_TD_7206188_output("tbl_JOIN_LEFTOUTER_TD_7206188_output", 6100000, 5, "");
    tbl_JOIN_LEFTOUTER_TD_7206188_output.allocateHost();
    Table tbl_Aggregate_TD_8981652_output_preprocess("tbl_Aggregate_TD_8981652_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_8981652_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_8981652_output("tbl_Aggregate_TD_8981652_output", 6100000, 3, "");
    tbl_Aggregate_TD_8981652_output.allocateHost();
    Table tbl_Aggregate_TD_8360457_output_preprocess("tbl_Aggregate_TD_8360457_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_8360457_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_8360457_output("tbl_Aggregate_TD_8360457_output", 6100000, 3, "");
    tbl_Aggregate_TD_8360457_output.allocateHost();
    Table tbl_Aggregate_TD_8763895_output_preprocess("tbl_Aggregate_TD_8763895_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_8763895_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_8763895_output("tbl_Aggregate_TD_8763895_output", 6100000, 3, "");
    tbl_Aggregate_TD_8763895_output.allocateHost();
    Table tbl_Aggregate_TD_858490_output_preprocess("tbl_Aggregate_TD_858490_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_858490_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_858490_output("tbl_Aggregate_TD_858490_output", 6100000, 2, "");
    tbl_Aggregate_TD_858490_output.allocateHost();
    Table tbl_Aggregate_TD_8707443_output_preprocess("tbl_Aggregate_TD_8707443_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_8707443_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_8707443_output("tbl_Aggregate_TD_8707443_output", 6100000, 3, "");
    tbl_Aggregate_TD_8707443_output.allocateHost();
    Table tbl_Aggregate_TD_8922127_output_preprocess("tbl_Aggregate_TD_8922127_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_8922127_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_8922127_output("tbl_Aggregate_TD_8922127_output", 6100000, 3, "");
    tbl_Aggregate_TD_8922127_output.allocateHost();
    Table tbl_JOIN_INNER_TD_956172_output_preprocess("tbl_JOIN_INNER_TD_956172_output_preprocess", 6100000, 3, "");
    tbl_JOIN_INNER_TD_956172_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_956172_output("tbl_JOIN_INNER_TD_956172_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_956172_output.allocateHost();
    Table tbl_JOIN_INNER_TD_9787277_output_preprocess("tbl_JOIN_INNER_TD_9787277_output_preprocess", 6100000, 3, "");
    tbl_JOIN_INNER_TD_9787277_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_9787277_output("tbl_JOIN_INNER_TD_9787277_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_9787277_output.allocateHost();
    Table tbl_JOIN_INNER_TD_9225031_output_preprocess("tbl_JOIN_INNER_TD_9225031_output_preprocess", 6100000, 3, "");
    tbl_JOIN_INNER_TD_9225031_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_9225031_output("tbl_JOIN_INNER_TD_9225031_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_9225031_output.allocateHost();
    Table tbl_JOIN_INNER_TD_9208135_output_preprocess("tbl_JOIN_INNER_TD_9208135_output_preprocess", 6100000, 3, "");
    tbl_JOIN_INNER_TD_9208135_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_9208135_output("tbl_JOIN_INNER_TD_9208135_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_9208135_output.allocateHost();
    Table tbl_JOIN_INNER_TD_9549918_output_preprocess("tbl_JOIN_INNER_TD_9549918_output_preprocess", 6100000, 3, "");
    tbl_JOIN_INNER_TD_9549918_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_9549918_output("tbl_JOIN_INNER_TD_9549918_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_9549918_output.allocateHost();
    Table tbl_JOIN_INNER_TD_9989152_output_preprocess("tbl_JOIN_INNER_TD_9989152_output_preprocess", 6100000, 3, "");
    tbl_JOIN_INNER_TD_9989152_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_9989152_output("tbl_JOIN_INNER_TD_9989152_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_9989152_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10976862_output("tbl_JOIN_INNER_TD_10976862_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_10976862_output.allocateHost();
    Table tbl_Filter_TD_10535472_output("tbl_Filter_TD_10535472_output", 6100000, 1, "");
    tbl_Filter_TD_10535472_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10454443_output("tbl_JOIN_INNER_TD_10454443_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_10454443_output.allocateHost();
    Table tbl_Filter_TD_1044974_output("tbl_Filter_TD_1044974_output", 6100000, 1, "");
    tbl_Filter_TD_1044974_output.allocateHost();
    Table tbl_Filter_TD_10197211_output("tbl_Filter_TD_10197211_output", 6100000, 4, "");
    tbl_Filter_TD_10197211_output.allocateHost();
    Table tbl_Filter_TD_1046563_output("tbl_Filter_TD_1046563_output", 6100000, 1, "");
    tbl_Filter_TD_1046563_output.allocateHost();
    Table tbl_Filter_TD_10188919_output("tbl_Filter_TD_10188919_output", 6100000, 4, "");
    tbl_Filter_TD_10188919_output.allocateHost();
    Table tbl_Filter_TD_10899949_output("tbl_Filter_TD_10899949_output", 6100000, 1, "");
    tbl_Filter_TD_10899949_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10232436_output("tbl_JOIN_INNER_TD_10232436_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_10232436_output.allocateHost();
    Table tbl_Filter_TD_10136224_output("tbl_Filter_TD_10136224_output", 6100000, 1, "");
    tbl_Filter_TD_10136224_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10865676_output("tbl_JOIN_INNER_TD_10865676_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_10865676_output.allocateHost();
    Table tbl_Filter_TD_10626660_output("tbl_Filter_TD_10626660_output", 6100000, 1, "");
    tbl_Filter_TD_10626660_output.allocateHost();
    Table tbl_Filter_TD_11932688_output("tbl_Filter_TD_11932688_output", 6100000, 4, "");
    tbl_Filter_TD_11932688_output.allocateHost();
    Table tbl_Filter_TD_11687332_output("tbl_Filter_TD_11687332_output", 6100000, 1, "");
    tbl_Filter_TD_11687332_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11586100_input;
    tbl_SerializeFromObject_TD_11586100_input = Table("store", store_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_11586100_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_11586100_input.allocateHost();
    tbl_SerializeFromObject_TD_11586100_input.loadHost();
    Table tbl_Filter_TD_11226393_output("tbl_Filter_TD_11226393_output", 6100000, 4, "");
    tbl_Filter_TD_11226393_output.allocateHost();
    Table tbl_Filter_TD_1145_output("tbl_Filter_TD_1145_output", 6100000, 1, "");
    tbl_Filter_TD_1145_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11249664_input;
    tbl_SerializeFromObject_TD_11249664_input = Table("store", store_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_11249664_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_11249664_input.allocateHost();
    tbl_SerializeFromObject_TD_11249664_input.loadHost();
    Table tbl_SerializeFromObject_TD_11279308_input;
    tbl_SerializeFromObject_TD_11279308_input = Table("catalog_sales", catalog_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_11279308_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_11279308_input.addCol("cs_call_center_sk", 4);
    tbl_SerializeFromObject_TD_11279308_input.addCol("cs_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_11279308_input.addCol("cs_net_profit", 4);
    tbl_SerializeFromObject_TD_11279308_input.allocateHost();
    tbl_SerializeFromObject_TD_11279308_input.loadHost();
    Table tbl_SerializeFromObject_TD_11299306_input;
    tbl_SerializeFromObject_TD_11299306_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11299306_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_11299306_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_11299306_input.allocateHost();
    tbl_SerializeFromObject_TD_11299306_input.loadHost();
    Table tbl_SerializeFromObject_TD_1153545_input;
    tbl_SerializeFromObject_TD_1153545_input = Table("catalog_returns", catalog_returns_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_1153545_input.addCol("cr_returned_date_sk", 4);
    tbl_SerializeFromObject_TD_1153545_input.addCol("cr_call_center_sk", 4);
    tbl_SerializeFromObject_TD_1153545_input.addCol("cr_return_amount", 4);
    tbl_SerializeFromObject_TD_1153545_input.addCol("cr_net_loss", 4);
    tbl_SerializeFromObject_TD_1153545_input.allocateHost();
    tbl_SerializeFromObject_TD_1153545_input.loadHost();
    Table tbl_SerializeFromObject_TD_11524432_input;
    tbl_SerializeFromObject_TD_11524432_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11524432_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_11524432_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_11524432_input.allocateHost();
    tbl_SerializeFromObject_TD_11524432_input.loadHost();
    Table tbl_Filter_TD_11281364_output("tbl_Filter_TD_11281364_output", 6100000, 4, "");
    tbl_Filter_TD_11281364_output.allocateHost();
    Table tbl_Filter_TD_11210199_output("tbl_Filter_TD_11210199_output", 6100000, 1, "");
    tbl_Filter_TD_11210199_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11461628_input;
    tbl_SerializeFromObject_TD_11461628_input = Table("web_page", web_page_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_11461628_input.addCol("wp_web_page_sk", 4);
    tbl_SerializeFromObject_TD_11461628_input.allocateHost();
    tbl_SerializeFromObject_TD_11461628_input.loadHost();
    Table tbl_Filter_TD_11118799_output("tbl_Filter_TD_11118799_output", 6100000, 4, "");
    tbl_Filter_TD_11118799_output.allocateHost();
    Table tbl_Filter_TD_11223248_output("tbl_Filter_TD_11223248_output", 6100000, 1, "");
    tbl_Filter_TD_11223248_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11223040_input;
    tbl_SerializeFromObject_TD_11223040_input = Table("web_page", web_page_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_11223040_input.addCol("wp_web_page_sk", 4);
    tbl_SerializeFromObject_TD_11223040_input.allocateHost();
    tbl_SerializeFromObject_TD_11223040_input.loadHost();
    Table tbl_SerializeFromObject_TD_12887464_input;
    tbl_SerializeFromObject_TD_12887464_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_12887464_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_12887464_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_12887464_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_12887464_input.addCol("ss_net_profit", 4);
    tbl_SerializeFromObject_TD_12887464_input.allocateHost();
    tbl_SerializeFromObject_TD_12887464_input.loadHost();
    Table tbl_SerializeFromObject_TD_12783138_input;
    tbl_SerializeFromObject_TD_12783138_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12783138_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_12783138_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_12783138_input.allocateHost();
    tbl_SerializeFromObject_TD_12783138_input.loadHost();
    Table tbl_SerializeFromObject_TD_12935067_input;
    tbl_SerializeFromObject_TD_12935067_input = Table("store_returns", store_returns_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_12935067_input.addCol("sr_returned_date_sk", 4);
    tbl_SerializeFromObject_TD_12935067_input.addCol("sr_store_sk", 4);
    tbl_SerializeFromObject_TD_12935067_input.addCol("sr_return_amt", 4);
    tbl_SerializeFromObject_TD_12935067_input.addCol("sr_net_loss", 4);
    tbl_SerializeFromObject_TD_12935067_input.allocateHost();
    tbl_SerializeFromObject_TD_12935067_input.loadHost();
    Table tbl_SerializeFromObject_TD_12794166_input;
    tbl_SerializeFromObject_TD_12794166_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12794166_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_12794166_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_12794166_input.allocateHost();
    tbl_SerializeFromObject_TD_12794166_input.loadHost();
    Table tbl_SerializeFromObject_TD_12791368_input;
    tbl_SerializeFromObject_TD_12791368_input = Table("web_sales", web_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_12791368_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_12791368_input.addCol("ws_web_page_sk", 4);
    tbl_SerializeFromObject_TD_12791368_input.addCol("ws_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_12791368_input.addCol("ws_net_profit", 4);
    tbl_SerializeFromObject_TD_12791368_input.allocateHost();
    tbl_SerializeFromObject_TD_12791368_input.loadHost();
    Table tbl_SerializeFromObject_TD_1291518_input;
    tbl_SerializeFromObject_TD_1291518_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_1291518_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_1291518_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_1291518_input.allocateHost();
    tbl_SerializeFromObject_TD_1291518_input.loadHost();
    Table tbl_SerializeFromObject_TD_12305071_input;
    tbl_SerializeFromObject_TD_12305071_input = Table("web_returns", web_returns_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_12305071_input.addCol("wr_returned_date_sk", 4);
    tbl_SerializeFromObject_TD_12305071_input.addCol("wr_web_page_sk", 4);
    tbl_SerializeFromObject_TD_12305071_input.addCol("wr_return_amt", 4);
    tbl_SerializeFromObject_TD_12305071_input.addCol("wr_net_loss", 4);
    tbl_SerializeFromObject_TD_12305071_input.allocateHost();
    tbl_SerializeFromObject_TD_12305071_input.loadHost();
    Table tbl_SerializeFromObject_TD_12223447_input;
    tbl_SerializeFromObject_TD_12223447_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12223447_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_12223447_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_12223447_input.allocateHost();
    tbl_SerializeFromObject_TD_12223447_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_LEFTOUTER_TD_7746880_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTOUTER_TD_7206188_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_956172_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_8981652_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_Aggregate_TD_8981652_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_9787277_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_8360457_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_Aggregate_TD_8360457_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_9225031_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_8763895_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_JOIN_INNER_TD_9208135_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_858490_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_JOIN_INNER_TD_9549918_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_8707443_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_Aggregate_TD_8707443_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_9989152_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_8922127_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_Aggregate_TD_8922127_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_956172_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_9787277_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_9225031_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_9208135_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_9549918_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_9989152_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_10976862_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10535472_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_10454443_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_1044974_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10197211_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_1046563_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10188919_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10899949_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_10232436_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10136224_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_10865676_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10626660_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11932688_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11687332_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11226393_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_1145_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11281364_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11210199_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11118799_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11223248_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_LEFTOUTER_TD_7746880_cmds;
    cfg_JOIN_LEFTOUTER_TD_7746880_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTOUTER_TD_7746880_gqe_join (cfg_JOIN_LEFTOUTER_TD_7746880_cmds.cmd);
    cfg_JOIN_LEFTOUTER_TD_7746880_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTOUTER_TD_7206188_cmds;
    cfg_JOIN_LEFTOUTER_TD_7206188_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTOUTER_TD_7206188_gqe_join (cfg_JOIN_LEFTOUTER_TD_7206188_cmds.cmd);
    cfg_JOIN_LEFTOUTER_TD_7206188_cmds.allocateDevBuffer(context_h, 32);
    AggrCfgCmd cfg_Aggregate_TD_8981652_cmds;
    cfg_Aggregate_TD_8981652_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_8981652_gqe_aggr(cfg_Aggregate_TD_8981652_cmds.cmd);
    cfg_Aggregate_TD_8981652_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_8981652_cmds_out;
    cfg_Aggregate_TD_8981652_cmds_out.allocateHost();
    cfg_Aggregate_TD_8981652_cmds_out.allocateDevBuffer(context_a, 33);
    AggrCfgCmd cfg_Aggregate_TD_8360457_cmds;
    cfg_Aggregate_TD_8360457_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_8360457_gqe_aggr(cfg_Aggregate_TD_8360457_cmds.cmd);
    cfg_Aggregate_TD_8360457_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_8360457_cmds_out;
    cfg_Aggregate_TD_8360457_cmds_out.allocateHost();
    cfg_Aggregate_TD_8360457_cmds_out.allocateDevBuffer(context_a, 33);
    AggrCfgCmd cfg_Aggregate_TD_8763895_cmds;
    cfg_Aggregate_TD_8763895_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_8763895_gqe_aggr(cfg_Aggregate_TD_8763895_cmds.cmd);
    cfg_Aggregate_TD_8763895_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_8763895_cmds_out;
    cfg_Aggregate_TD_8763895_cmds_out.allocateHost();
    cfg_Aggregate_TD_8763895_cmds_out.allocateDevBuffer(context_a, 33);
    AggrCfgCmd cfg_Aggregate_TD_858490_cmds;
    cfg_Aggregate_TD_858490_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_858490_gqe_aggr(cfg_Aggregate_TD_858490_cmds.cmd);
    cfg_Aggregate_TD_858490_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_858490_cmds_out;
    cfg_Aggregate_TD_858490_cmds_out.allocateHost();
    cfg_Aggregate_TD_858490_cmds_out.allocateDevBuffer(context_a, 33);
    AggrCfgCmd cfg_Aggregate_TD_8707443_cmds;
    cfg_Aggregate_TD_8707443_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_8707443_gqe_aggr(cfg_Aggregate_TD_8707443_cmds.cmd);
    cfg_Aggregate_TD_8707443_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_8707443_cmds_out;
    cfg_Aggregate_TD_8707443_cmds_out.allocateHost();
    cfg_Aggregate_TD_8707443_cmds_out.allocateDevBuffer(context_a, 33);
    AggrCfgCmd cfg_Aggregate_TD_8922127_cmds;
    cfg_Aggregate_TD_8922127_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_8922127_gqe_aggr(cfg_Aggregate_TD_8922127_cmds.cmd);
    cfg_Aggregate_TD_8922127_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_8922127_cmds_out;
    cfg_Aggregate_TD_8922127_cmds_out.allocateHost();
    cfg_Aggregate_TD_8922127_cmds_out.allocateDevBuffer(context_a, 33);
    cfgCmd cfg_JOIN_INNER_TD_956172_cmds;
    cfg_JOIN_INNER_TD_956172_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_956172_gqe_join (cfg_JOIN_INNER_TD_956172_cmds.cmd);
    cfg_JOIN_INNER_TD_956172_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_9787277_cmds;
    cfg_JOIN_INNER_TD_9787277_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_9787277_gqe_join (cfg_JOIN_INNER_TD_9787277_cmds.cmd);
    cfg_JOIN_INNER_TD_9787277_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_9225031_cmds;
    cfg_JOIN_INNER_TD_9225031_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_9225031_gqe_join (cfg_JOIN_INNER_TD_9225031_cmds.cmd);
    cfg_JOIN_INNER_TD_9225031_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_9208135_cmds;
    cfg_JOIN_INNER_TD_9208135_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_9208135_gqe_join (cfg_JOIN_INNER_TD_9208135_cmds.cmd);
    cfg_JOIN_INNER_TD_9208135_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_9549918_cmds;
    cfg_JOIN_INNER_TD_9549918_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_9549918_gqe_join (cfg_JOIN_INNER_TD_9549918_cmds.cmd);
    cfg_JOIN_INNER_TD_9549918_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_9989152_cmds;
    cfg_JOIN_INNER_TD_9989152_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_9989152_gqe_join (cfg_JOIN_INNER_TD_9989152_cmds.cmd);
    cfg_JOIN_INNER_TD_9989152_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_10976862_cmds;
    cfg_JOIN_INNER_TD_10976862_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_10976862_gqe_join (cfg_JOIN_INNER_TD_10976862_cmds.cmd);
    cfg_JOIN_INNER_TD_10976862_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_10454443_cmds;
    cfg_JOIN_INNER_TD_10454443_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_10454443_gqe_join (cfg_JOIN_INNER_TD_10454443_cmds.cmd);
    cfg_JOIN_INNER_TD_10454443_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_10232436_cmds;
    cfg_JOIN_INNER_TD_10232436_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_10232436_gqe_join (cfg_JOIN_INNER_TD_10232436_cmds.cmd);
    cfg_JOIN_INNER_TD_10232436_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_10865676_cmds;
    cfg_JOIN_INNER_TD_10865676_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_10865676_gqe_join (cfg_JOIN_INNER_TD_10865676_cmds.cmd);
    cfg_JOIN_INNER_TD_10865676_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    AggrBufferTmp buftmp_a(context_a); 
    buftmp_a.BufferInitial(q_a); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_LEFTOUTER_TD_7746880;
    krnl_JOIN_LEFTOUTER_TD_7746880 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTOUTER_TD_7746880.setup(tbl_Aggregate_TD_8981652_output, tbl_Aggregate_TD_8360457_output, tbl_JOIN_LEFTOUTER_TD_7746880_output, cfg_JOIN_LEFTOUTER_TD_7746880_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTOUTER_TD_7206188;
    krnl_JOIN_LEFTOUTER_TD_7206188 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTOUTER_TD_7206188.setup(tbl_Aggregate_TD_8707443_output, tbl_Aggregate_TD_8922127_output, tbl_JOIN_LEFTOUTER_TD_7206188_output, cfg_JOIN_LEFTOUTER_TD_7206188_cmds, buftmp_h);
    AggrKrnlEngine krnl_Aggregate_TD_8981652;
    krnl_Aggregate_TD_8981652 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_8981652.setup(tbl_JOIN_INNER_TD_956172_output, tbl_Aggregate_TD_8981652_output_preprocess, cfg_Aggregate_TD_8981652_cmds, cfg_Aggregate_TD_8981652_cmds_out, buftmp_a);
    AggrKrnlEngine krnl_Aggregate_TD_8360457;
    krnl_Aggregate_TD_8360457 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_8360457.setup(tbl_JOIN_INNER_TD_9787277_output, tbl_Aggregate_TD_8360457_output_preprocess, cfg_Aggregate_TD_8360457_cmds, cfg_Aggregate_TD_8360457_cmds_out, buftmp_a);
    AggrKrnlEngine krnl_Aggregate_TD_8763895;
    krnl_Aggregate_TD_8763895 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_8763895.setup(tbl_JOIN_INNER_TD_9225031_output, tbl_Aggregate_TD_8763895_output_preprocess, cfg_Aggregate_TD_8763895_cmds, cfg_Aggregate_TD_8763895_cmds_out, buftmp_a);
    AggrKrnlEngine krnl_Aggregate_TD_858490;
    krnl_Aggregate_TD_858490 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_858490.setup(tbl_JOIN_INNER_TD_9208135_output, tbl_Aggregate_TD_858490_output_preprocess, cfg_Aggregate_TD_858490_cmds, cfg_Aggregate_TD_858490_cmds_out, buftmp_a);
    AggrKrnlEngine krnl_Aggregate_TD_8707443;
    krnl_Aggregate_TD_8707443 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_8707443.setup(tbl_JOIN_INNER_TD_9549918_output, tbl_Aggregate_TD_8707443_output_preprocess, cfg_Aggregate_TD_8707443_cmds, cfg_Aggregate_TD_8707443_cmds_out, buftmp_a);
    AggrKrnlEngine krnl_Aggregate_TD_8922127;
    krnl_Aggregate_TD_8922127 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_8922127.setup(tbl_JOIN_INNER_TD_9989152_output, tbl_Aggregate_TD_8922127_output_preprocess, cfg_Aggregate_TD_8922127_cmds, cfg_Aggregate_TD_8922127_cmds_out, buftmp_a);
    krnlEngine krnl_JOIN_INNER_TD_956172;
    krnl_JOIN_INNER_TD_956172 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_956172.setup(tbl_JOIN_INNER_TD_10976862_output, tbl_Filter_TD_10535472_output, tbl_JOIN_INNER_TD_956172_output_preprocess, cfg_JOIN_INNER_TD_956172_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_9787277;
    krnl_JOIN_INNER_TD_9787277 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_9787277.setup(tbl_JOIN_INNER_TD_10454443_output, tbl_Filter_TD_1044974_output, tbl_JOIN_INNER_TD_9787277_output_preprocess, cfg_JOIN_INNER_TD_9787277_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_9225031;
    krnl_JOIN_INNER_TD_9225031 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_9225031.setup(tbl_Filter_TD_10197211_output, tbl_Filter_TD_1046563_output, tbl_JOIN_INNER_TD_9225031_output_preprocess, cfg_JOIN_INNER_TD_9225031_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_9208135;
    krnl_JOIN_INNER_TD_9208135 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_9208135.setup(tbl_Filter_TD_10188919_output, tbl_Filter_TD_10899949_output, tbl_JOIN_INNER_TD_9208135_output_preprocess, cfg_JOIN_INNER_TD_9208135_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_9549918;
    krnl_JOIN_INNER_TD_9549918 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_9549918.setup(tbl_JOIN_INNER_TD_10232436_output, tbl_Filter_TD_10136224_output, tbl_JOIN_INNER_TD_9549918_output_preprocess, cfg_JOIN_INNER_TD_9549918_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_9989152;
    krnl_JOIN_INNER_TD_9989152 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_9989152.setup(tbl_JOIN_INNER_TD_10865676_output, tbl_Filter_TD_10626660_output, tbl_JOIN_INNER_TD_9989152_output_preprocess, cfg_JOIN_INNER_TD_9989152_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_10976862;
    krnl_JOIN_INNER_TD_10976862 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_10976862.setup(tbl_Filter_TD_11932688_output, tbl_Filter_TD_11687332_output, tbl_JOIN_INNER_TD_10976862_output, cfg_JOIN_INNER_TD_10976862_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_10454443;
    krnl_JOIN_INNER_TD_10454443 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_10454443.setup(tbl_Filter_TD_11226393_output, tbl_Filter_TD_1145_output, tbl_JOIN_INNER_TD_10454443_output, cfg_JOIN_INNER_TD_10454443_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_10232436;
    krnl_JOIN_INNER_TD_10232436 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_10232436.setup(tbl_Filter_TD_11281364_output, tbl_Filter_TD_11210199_output, tbl_JOIN_INNER_TD_10232436_output, cfg_JOIN_INNER_TD_10232436_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_10865676;
    krnl_JOIN_INNER_TD_10865676 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_10865676.setup(tbl_Filter_TD_11118799_output, tbl_Filter_TD_11223248_output, tbl_JOIN_INNER_TD_10865676_output, cfg_JOIN_INNER_TD_10865676_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_LEFTOUTER_TD_7746880;
    trans_JOIN_LEFTOUTER_TD_7746880.setq(q_h);
    trans_JOIN_LEFTOUTER_TD_7746880.add(&(cfg_JOIN_LEFTOUTER_TD_7746880_cmds));
    transEngine trans_JOIN_LEFTOUTER_TD_7746880_out;
    trans_JOIN_LEFTOUTER_TD_7746880_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_LEFTOUTER_TD_7206188;
    trans_JOIN_LEFTOUTER_TD_7206188.setq(q_h);
    trans_JOIN_LEFTOUTER_TD_7206188.add(&(cfg_JOIN_LEFTOUTER_TD_7206188_cmds));
    transEngine trans_JOIN_LEFTOUTER_TD_7206188_out;
    trans_JOIN_LEFTOUTER_TD_7206188_out.setq(q_h);
    q_h.finish();
    transEngine trans_Aggregate_TD_8981652;
    trans_Aggregate_TD_8981652.setq(q_a);
    trans_Aggregate_TD_8981652.add(&(cfg_Aggregate_TD_8981652_cmds));
    transEngine trans_Aggregate_TD_8981652_out;
    trans_Aggregate_TD_8981652_out.setq(q_a);
    q_a.finish();
    transEngine trans_Aggregate_TD_8360457;
    trans_Aggregate_TD_8360457.setq(q_a);
    trans_Aggregate_TD_8360457.add(&(cfg_Aggregate_TD_8360457_cmds));
    transEngine trans_Aggregate_TD_8360457_out;
    trans_Aggregate_TD_8360457_out.setq(q_a);
    q_a.finish();
    transEngine trans_Aggregate_TD_8763895;
    trans_Aggregate_TD_8763895.setq(q_a);
    trans_Aggregate_TD_8763895.add(&(cfg_Aggregate_TD_8763895_cmds));
    transEngine trans_Aggregate_TD_8763895_out;
    trans_Aggregate_TD_8763895_out.setq(q_a);
    q_a.finish();
    transEngine trans_Aggregate_TD_858490;
    trans_Aggregate_TD_858490.setq(q_a);
    trans_Aggregate_TD_858490.add(&(cfg_Aggregate_TD_858490_cmds));
    transEngine trans_Aggregate_TD_858490_out;
    trans_Aggregate_TD_858490_out.setq(q_a);
    q_a.finish();
    transEngine trans_Aggregate_TD_8707443;
    trans_Aggregate_TD_8707443.setq(q_a);
    trans_Aggregate_TD_8707443.add(&(cfg_Aggregate_TD_8707443_cmds));
    transEngine trans_Aggregate_TD_8707443_out;
    trans_Aggregate_TD_8707443_out.setq(q_a);
    q_a.finish();
    transEngine trans_Aggregate_TD_8922127;
    trans_Aggregate_TD_8922127.setq(q_a);
    trans_Aggregate_TD_8922127.add(&(cfg_Aggregate_TD_8922127_cmds));
    transEngine trans_Aggregate_TD_8922127_out;
    trans_Aggregate_TD_8922127_out.setq(q_a);
    q_a.finish();
    transEngine trans_JOIN_INNER_TD_956172;
    trans_JOIN_INNER_TD_956172.setq(q_h);
    trans_JOIN_INNER_TD_956172.add(&(cfg_JOIN_INNER_TD_956172_cmds));
    transEngine trans_JOIN_INNER_TD_956172_out;
    trans_JOIN_INNER_TD_956172_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_9787277;
    trans_JOIN_INNER_TD_9787277.setq(q_h);
    trans_JOIN_INNER_TD_9787277.add(&(cfg_JOIN_INNER_TD_9787277_cmds));
    transEngine trans_JOIN_INNER_TD_9787277_out;
    trans_JOIN_INNER_TD_9787277_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_9225031;
    trans_JOIN_INNER_TD_9225031.setq(q_h);
    trans_JOIN_INNER_TD_9225031.add(&(cfg_JOIN_INNER_TD_9225031_cmds));
    transEngine trans_JOIN_INNER_TD_9225031_out;
    trans_JOIN_INNER_TD_9225031_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_9208135;
    trans_JOIN_INNER_TD_9208135.setq(q_h);
    trans_JOIN_INNER_TD_9208135.add(&(cfg_JOIN_INNER_TD_9208135_cmds));
    transEngine trans_JOIN_INNER_TD_9208135_out;
    trans_JOIN_INNER_TD_9208135_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_9549918;
    trans_JOIN_INNER_TD_9549918.setq(q_h);
    trans_JOIN_INNER_TD_9549918.add(&(cfg_JOIN_INNER_TD_9549918_cmds));
    transEngine trans_JOIN_INNER_TD_9549918_out;
    trans_JOIN_INNER_TD_9549918_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_9989152;
    trans_JOIN_INNER_TD_9989152.setq(q_h);
    trans_JOIN_INNER_TD_9989152.add(&(cfg_JOIN_INNER_TD_9989152_cmds));
    transEngine trans_JOIN_INNER_TD_9989152_out;
    trans_JOIN_INNER_TD_9989152_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_10976862;
    trans_JOIN_INNER_TD_10976862.setq(q_h);
    trans_JOIN_INNER_TD_10976862.add(&(cfg_JOIN_INNER_TD_10976862_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_10454443;
    trans_JOIN_INNER_TD_10454443.setq(q_h);
    trans_JOIN_INNER_TD_10454443.add(&(cfg_JOIN_INNER_TD_10454443_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_10232436;
    trans_JOIN_INNER_TD_10232436.setq(q_h);
    trans_JOIN_INNER_TD_10232436.add(&(cfg_JOIN_INNER_TD_10232436_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_10865676;
    trans_JOIN_INNER_TD_10865676.setq(q_h);
    trans_JOIN_INNER_TD_10865676.add(&(cfg_JOIN_INNER_TD_10865676_cmds));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTOUTER_TD_7746880;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTOUTER_TD_7746880;
    std::vector<cl::Event> events_JOIN_LEFTOUTER_TD_7746880;
    events_h2d_wr_JOIN_LEFTOUTER_TD_7746880.resize(1);
    events_d2h_rd_JOIN_LEFTOUTER_TD_7746880.resize(1);
    events_JOIN_LEFTOUTER_TD_7746880.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTOUTER_TD_7746880;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTOUTER_TD_7746880;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTOUTER_TD_7206188;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTOUTER_TD_7206188;
    std::vector<cl::Event> events_JOIN_LEFTOUTER_TD_7206188;
    events_h2d_wr_JOIN_LEFTOUTER_TD_7206188.resize(1);
    events_d2h_rd_JOIN_LEFTOUTER_TD_7206188.resize(1);
    events_JOIN_LEFTOUTER_TD_7206188.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTOUTER_TD_7206188;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTOUTER_TD_7206188;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_8981652;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_8981652;
    std::vector<cl::Event> events_Aggregate_TD_8981652;
    events_h2d_wr_Aggregate_TD_8981652.resize(1);
    events_d2h_rd_Aggregate_TD_8981652.resize(1);
    events_Aggregate_TD_8981652.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_8981652;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_8981652;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_8360457;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_8360457;
    std::vector<cl::Event> events_Aggregate_TD_8360457;
    events_h2d_wr_Aggregate_TD_8360457.resize(1);
    events_d2h_rd_Aggregate_TD_8360457.resize(1);
    events_Aggregate_TD_8360457.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_8360457;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_8360457;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_8763895;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_8763895;
    std::vector<cl::Event> events_Aggregate_TD_8763895;
    events_h2d_wr_Aggregate_TD_8763895.resize(1);
    events_d2h_rd_Aggregate_TD_8763895.resize(1);
    events_Aggregate_TD_8763895.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_8763895;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_8763895;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_858490;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_858490;
    std::vector<cl::Event> events_Aggregate_TD_858490;
    events_h2d_wr_Aggregate_TD_858490.resize(1);
    events_d2h_rd_Aggregate_TD_858490.resize(1);
    events_Aggregate_TD_858490.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_858490;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_858490;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_8707443;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_8707443;
    std::vector<cl::Event> events_Aggregate_TD_8707443;
    events_h2d_wr_Aggregate_TD_8707443.resize(1);
    events_d2h_rd_Aggregate_TD_8707443.resize(1);
    events_Aggregate_TD_8707443.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_8707443;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_8707443;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_8922127;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_8922127;
    std::vector<cl::Event> events_Aggregate_TD_8922127;
    events_h2d_wr_Aggregate_TD_8922127.resize(1);
    events_d2h_rd_Aggregate_TD_8922127.resize(1);
    events_Aggregate_TD_8922127.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_8922127;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_8922127;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_956172;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_956172;
    std::vector<cl::Event> events_JOIN_INNER_TD_956172;
    events_h2d_wr_JOIN_INNER_TD_956172.resize(1);
    events_d2h_rd_JOIN_INNER_TD_956172.resize(1);
    events_JOIN_INNER_TD_956172.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_956172;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_956172;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_9787277;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_9787277;
    std::vector<cl::Event> events_JOIN_INNER_TD_9787277;
    events_h2d_wr_JOIN_INNER_TD_9787277.resize(1);
    events_d2h_rd_JOIN_INNER_TD_9787277.resize(1);
    events_JOIN_INNER_TD_9787277.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_9787277;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_9787277;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_9225031;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_9225031;
    std::vector<cl::Event> events_JOIN_INNER_TD_9225031;
    events_h2d_wr_JOIN_INNER_TD_9225031.resize(1);
    events_d2h_rd_JOIN_INNER_TD_9225031.resize(1);
    events_JOIN_INNER_TD_9225031.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_9225031;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_9225031;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_9208135;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_9208135;
    std::vector<cl::Event> events_JOIN_INNER_TD_9208135;
    events_h2d_wr_JOIN_INNER_TD_9208135.resize(1);
    events_d2h_rd_JOIN_INNER_TD_9208135.resize(1);
    events_JOIN_INNER_TD_9208135.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_9208135;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_9208135;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_9549918;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_9549918;
    std::vector<cl::Event> events_JOIN_INNER_TD_9549918;
    events_h2d_wr_JOIN_INNER_TD_9549918.resize(1);
    events_d2h_rd_JOIN_INNER_TD_9549918.resize(1);
    events_JOIN_INNER_TD_9549918.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_9549918;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_9549918;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_9989152;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_9989152;
    std::vector<cl::Event> events_JOIN_INNER_TD_9989152;
    events_h2d_wr_JOIN_INNER_TD_9989152.resize(1);
    events_d2h_rd_JOIN_INNER_TD_9989152.resize(1);
    events_JOIN_INNER_TD_9989152.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_9989152;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_9989152;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_10976862;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_10976862;
    std::vector<cl::Event> events_JOIN_INNER_TD_10976862;
    events_h2d_wr_JOIN_INNER_TD_10976862.resize(1);
    events_d2h_rd_JOIN_INNER_TD_10976862.resize(1);
    events_JOIN_INNER_TD_10976862.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_10976862;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_10976862;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_10454443;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_10454443;
    std::vector<cl::Event> events_JOIN_INNER_TD_10454443;
    events_h2d_wr_JOIN_INNER_TD_10454443.resize(1);
    events_d2h_rd_JOIN_INNER_TD_10454443.resize(1);
    events_JOIN_INNER_TD_10454443.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_10454443;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_10454443;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_10232436;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_10232436;
    std::vector<cl::Event> events_JOIN_INNER_TD_10232436;
    events_h2d_wr_JOIN_INNER_TD_10232436.resize(1);
    events_d2h_rd_JOIN_INNER_TD_10232436.resize(1);
    events_JOIN_INNER_TD_10232436.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_10232436;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_10232436;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_10865676;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_10865676;
    std::vector<cl::Event> events_JOIN_INNER_TD_10865676;
    events_h2d_wr_JOIN_INNER_TD_10865676.resize(1);
    events_d2h_rd_JOIN_INNER_TD_10865676.resize(1);
    events_JOIN_INNER_TD_10865676.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_10865676;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_10865676;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_11_725809_s, tv_r_Filter_11_725809_e;
    gettimeofday(&tv_r_Filter_11_725809_s, 0);
    SW_Filter_TD_11223248(tbl_SerializeFromObject_TD_12223447_input, tbl_Filter_TD_11223248_output);
    gettimeofday(&tv_r_Filter_11_725809_e, 0);

    struct timeval tv_r_Filter_11_341961_s, tv_r_Filter_11_341961_e;
    gettimeofday(&tv_r_Filter_11_341961_s, 0);
    SW_Filter_TD_11118799(tbl_SerializeFromObject_TD_12305071_input, tbl_Filter_TD_11118799_output);
    gettimeofday(&tv_r_Filter_11_341961_e, 0);

    struct timeval tv_r_Filter_11_358937_s, tv_r_Filter_11_358937_e;
    gettimeofday(&tv_r_Filter_11_358937_s, 0);
    SW_Filter_TD_11210199(tbl_SerializeFromObject_TD_1291518_input, tbl_Filter_TD_11210199_output);
    gettimeofday(&tv_r_Filter_11_358937_e, 0);

    struct timeval tv_r_Filter_11_983399_s, tv_r_Filter_11_983399_e;
    gettimeofday(&tv_r_Filter_11_983399_s, 0);
    SW_Filter_TD_11281364(tbl_SerializeFromObject_TD_12791368_input, tbl_Filter_TD_11281364_output);
    gettimeofday(&tv_r_Filter_11_983399_e, 0);

    struct timeval tv_r_Filter_11_361038_s, tv_r_Filter_11_361038_e;
    gettimeofday(&tv_r_Filter_11_361038_s, 0);
    SW_Filter_TD_1145(tbl_SerializeFromObject_TD_12794166_input, tbl_Filter_TD_1145_output);
    gettimeofday(&tv_r_Filter_11_361038_e, 0);

    struct timeval tv_r_Filter_11_19378_s, tv_r_Filter_11_19378_e;
    gettimeofday(&tv_r_Filter_11_19378_s, 0);
    SW_Filter_TD_11226393(tbl_SerializeFromObject_TD_12935067_input, tbl_Filter_TD_11226393_output);
    gettimeofday(&tv_r_Filter_11_19378_e, 0);

    struct timeval tv_r_Filter_11_930955_s, tv_r_Filter_11_930955_e;
    gettimeofday(&tv_r_Filter_11_930955_s, 0);
    SW_Filter_TD_11687332(tbl_SerializeFromObject_TD_12783138_input, tbl_Filter_TD_11687332_output);
    gettimeofday(&tv_r_Filter_11_930955_e, 0);

    struct timeval tv_r_Filter_11_572068_s, tv_r_Filter_11_572068_e;
    gettimeofday(&tv_r_Filter_11_572068_s, 0);
    SW_Filter_TD_11932688(tbl_SerializeFromObject_TD_12887464_input, tbl_Filter_TD_11932688_output);
    gettimeofday(&tv_r_Filter_11_572068_e, 0);

    struct timeval tv_r_Filter_10_548014_s, tv_r_Filter_10_548014_e;
    gettimeofday(&tv_r_Filter_10_548014_s, 0);
    SW_Filter_TD_10626660(tbl_SerializeFromObject_TD_11223040_input, tbl_Filter_TD_10626660_output);
    gettimeofday(&tv_r_Filter_10_548014_e, 0);

    struct timeval tv_r_JOIN_INNER_10_88363_s, tv_r_JOIN_INNER_10_88363_e;
    gettimeofday(&tv_r_JOIN_INNER_10_88363_s, 0);
    trans_JOIN_INNER_TD_10865676.add(&(tbl_Filter_TD_11118799_output));
    trans_JOIN_INNER_TD_10865676.add(&(tbl_Filter_TD_11223248_output));
    trans_JOIN_INNER_TD_10865676.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_10865676), &(events_h2d_wr_JOIN_INNER_TD_10865676[0]));
    events_grp_JOIN_INNER_TD_10865676.push_back(events_h2d_wr_JOIN_INNER_TD_10865676[0]);
    krnl_JOIN_INNER_TD_10865676.run(0, &(events_grp_JOIN_INNER_TD_10865676), &(events_JOIN_INNER_TD_10865676[0]));
    gettimeofday(&tv_r_JOIN_INNER_10_88363_e, 0);

    struct timeval tv_r_Filter_10_4109_s, tv_r_Filter_10_4109_e;
    gettimeofday(&tv_r_Filter_10_4109_s, 0);
    SW_Filter_TD_10136224(tbl_SerializeFromObject_TD_11461628_input, tbl_Filter_TD_10136224_output);
    gettimeofday(&tv_r_Filter_10_4109_e, 0);

    struct timeval tv_r_JOIN_INNER_10_983866_s, tv_r_JOIN_INNER_10_983866_e;
    gettimeofday(&tv_r_JOIN_INNER_10_983866_s, 0);
    trans_JOIN_INNER_TD_10232436.add(&(tbl_Filter_TD_11281364_output));
    trans_JOIN_INNER_TD_10232436.add(&(tbl_Filter_TD_11210199_output));
    trans_JOIN_INNER_TD_10232436.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_10232436), &(events_h2d_wr_JOIN_INNER_TD_10232436[0]));
    events_grp_JOIN_INNER_TD_10232436.push_back(events_h2d_wr_JOIN_INNER_TD_10232436[0]);
    krnl_JOIN_INNER_TD_10232436.run(0, &(events_grp_JOIN_INNER_TD_10232436), &(events_JOIN_INNER_TD_10232436[0]));
    gettimeofday(&tv_r_JOIN_INNER_10_983866_e, 0);

    struct timeval tv_r_Filter_10_169895_s, tv_r_Filter_10_169895_e;
    gettimeofday(&tv_r_Filter_10_169895_s, 0);
    SW_Filter_TD_10899949(tbl_SerializeFromObject_TD_11524432_input, tbl_Filter_TD_10899949_output);
    gettimeofday(&tv_r_Filter_10_169895_e, 0);

    struct timeval tv_r_Filter_10_859716_s, tv_r_Filter_10_859716_e;
    gettimeofday(&tv_r_Filter_10_859716_s, 0);
    SW_Filter_TD_10188919(tbl_SerializeFromObject_TD_1153545_input, tbl_Filter_TD_10188919_output);
    gettimeofday(&tv_r_Filter_10_859716_e, 0);

    struct timeval tv_r_Filter_10_94497_s, tv_r_Filter_10_94497_e;
    gettimeofday(&tv_r_Filter_10_94497_s, 0);
    SW_Filter_TD_1046563(tbl_SerializeFromObject_TD_11299306_input, tbl_Filter_TD_1046563_output);
    gettimeofday(&tv_r_Filter_10_94497_e, 0);

    struct timeval tv_r_Filter_10_911563_s, tv_r_Filter_10_911563_e;
    gettimeofday(&tv_r_Filter_10_911563_s, 0);
    SW_Filter_TD_10197211(tbl_SerializeFromObject_TD_11279308_input, tbl_Filter_TD_10197211_output);
    gettimeofday(&tv_r_Filter_10_911563_e, 0);

    struct timeval tv_r_Filter_10_143648_s, tv_r_Filter_10_143648_e;
    gettimeofday(&tv_r_Filter_10_143648_s, 0);
    SW_Filter_TD_1044974(tbl_SerializeFromObject_TD_11249664_input, tbl_Filter_TD_1044974_output);
    gettimeofday(&tv_r_Filter_10_143648_e, 0);

    struct timeval tv_r_JOIN_INNER_10_312002_s, tv_r_JOIN_INNER_10_312002_e;
    gettimeofday(&tv_r_JOIN_INNER_10_312002_s, 0);
    trans_JOIN_INNER_TD_10454443.add(&(tbl_Filter_TD_11226393_output));
    trans_JOIN_INNER_TD_10454443.add(&(tbl_Filter_TD_1145_output));
    trans_JOIN_INNER_TD_10454443.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_10454443), &(events_h2d_wr_JOIN_INNER_TD_10454443[0]));
    events_grp_JOIN_INNER_TD_10454443.push_back(events_h2d_wr_JOIN_INNER_TD_10454443[0]);
    krnl_JOIN_INNER_TD_10454443.run(0, &(events_grp_JOIN_INNER_TD_10454443), &(events_JOIN_INNER_TD_10454443[0]));
    gettimeofday(&tv_r_JOIN_INNER_10_312002_e, 0);

    struct timeval tv_r_Filter_10_969278_s, tv_r_Filter_10_969278_e;
    gettimeofday(&tv_r_Filter_10_969278_s, 0);
    SW_Filter_TD_10535472(tbl_SerializeFromObject_TD_11586100_input, tbl_Filter_TD_10535472_output);
    gettimeofday(&tv_r_Filter_10_969278_e, 0);

    struct timeval tv_r_JOIN_INNER_10_529261_s, tv_r_JOIN_INNER_10_529261_e;
    gettimeofday(&tv_r_JOIN_INNER_10_529261_s, 0);
    trans_JOIN_INNER_TD_10976862.add(&(tbl_Filter_TD_11932688_output));
    trans_JOIN_INNER_TD_10976862.add(&(tbl_Filter_TD_11687332_output));
    trans_JOIN_INNER_TD_10976862.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_10976862), &(events_h2d_wr_JOIN_INNER_TD_10976862[0]));
    events_grp_JOIN_INNER_TD_10976862.push_back(events_h2d_wr_JOIN_INNER_TD_10976862[0]);
    krnl_JOIN_INNER_TD_10976862.run(0, &(events_grp_JOIN_INNER_TD_10976862), &(events_JOIN_INNER_TD_10976862[0]));
    gettimeofday(&tv_r_JOIN_INNER_10_529261_e, 0);

    struct timeval tv_r_JOIN_INNER_9_63647_s, tv_r_JOIN_INNER_9_63647_e;
    gettimeofday(&tv_r_JOIN_INNER_9_63647_s, 0);
    prev_events_grp_JOIN_INNER_TD_9989152.push_back(events_h2d_wr_JOIN_INNER_TD_10865676[0]);
    trans_JOIN_INNER_TD_9989152.add(&(tbl_Filter_TD_10626660_output));
    trans_JOIN_INNER_TD_9989152.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_9989152), &(events_h2d_wr_JOIN_INNER_TD_9989152[0]));
    events_grp_JOIN_INNER_TD_9989152.push_back(events_h2d_wr_JOIN_INNER_TD_9989152[0]);
    events_grp_JOIN_INNER_TD_9989152.push_back(events_JOIN_INNER_TD_10865676[0]);
    krnl_JOIN_INNER_TD_9989152.run(0, &(events_grp_JOIN_INNER_TD_9989152), &(events_JOIN_INNER_TD_9989152[0]));
    
    trans_JOIN_INNER_TD_9989152_out.add(&(tbl_JOIN_INNER_TD_9989152_output_preprocess));
    trans_JOIN_INNER_TD_9989152_out.dev2host(0, &(events_JOIN_INNER_TD_9989152), &(events_d2h_rd_JOIN_INNER_TD_9989152[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_9989152);
    tbl_JOIN_INNER_TD_9989152_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_9989152_output));
    gettimeofday(&tv_r_JOIN_INNER_9_63647_e, 0);

    struct timeval tv_r_JOIN_INNER_9_384576_s, tv_r_JOIN_INNER_9_384576_e;
    gettimeofday(&tv_r_JOIN_INNER_9_384576_s, 0);
    prev_events_grp_JOIN_INNER_TD_9549918.push_back(events_h2d_wr_JOIN_INNER_TD_10232436[0]);
    trans_JOIN_INNER_TD_9549918.add(&(tbl_Filter_TD_10136224_output));
    trans_JOIN_INNER_TD_9549918.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_9549918), &(events_h2d_wr_JOIN_INNER_TD_9549918[0]));
    events_grp_JOIN_INNER_TD_9549918.push_back(events_h2d_wr_JOIN_INNER_TD_9549918[0]);
    events_grp_JOIN_INNER_TD_9549918.push_back(events_JOIN_INNER_TD_10232436[0]);
    krnl_JOIN_INNER_TD_9549918.run(0, &(events_grp_JOIN_INNER_TD_9549918), &(events_JOIN_INNER_TD_9549918[0]));
    
    trans_JOIN_INNER_TD_9549918_out.add(&(tbl_JOIN_INNER_TD_9549918_output_preprocess));
    trans_JOIN_INNER_TD_9549918_out.dev2host(0, &(events_JOIN_INNER_TD_9549918), &(events_d2h_rd_JOIN_INNER_TD_9549918[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_9549918);
    tbl_JOIN_INNER_TD_9549918_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_9549918_output));
    gettimeofday(&tv_r_JOIN_INNER_9_384576_e, 0);

    struct timeval tv_r_JOIN_INNER_9_721389_s, tv_r_JOIN_INNER_9_721389_e;
    gettimeofday(&tv_r_JOIN_INNER_9_721389_s, 0);
    trans_JOIN_INNER_TD_9208135.add(&(tbl_Filter_TD_10188919_output));
    trans_JOIN_INNER_TD_9208135.add(&(tbl_Filter_TD_10899949_output));
    trans_JOIN_INNER_TD_9208135.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_9208135), &(events_h2d_wr_JOIN_INNER_TD_9208135[0]));
    events_grp_JOIN_INNER_TD_9208135.push_back(events_h2d_wr_JOIN_INNER_TD_9208135[0]);
    krnl_JOIN_INNER_TD_9208135.run(0, &(events_grp_JOIN_INNER_TD_9208135), &(events_JOIN_INNER_TD_9208135[0]));
    
    trans_JOIN_INNER_TD_9208135_out.add(&(tbl_JOIN_INNER_TD_9208135_output_preprocess));
    trans_JOIN_INNER_TD_9208135_out.dev2host(0, &(events_JOIN_INNER_TD_9208135), &(events_d2h_rd_JOIN_INNER_TD_9208135[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_9208135);
    tbl_JOIN_INNER_TD_9208135_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_9208135_output));
    gettimeofday(&tv_r_JOIN_INNER_9_721389_e, 0);

    struct timeval tv_r_JOIN_INNER_9_384158_s, tv_r_JOIN_INNER_9_384158_e;
    gettimeofday(&tv_r_JOIN_INNER_9_384158_s, 0);
    trans_JOIN_INNER_TD_9225031.add(&(tbl_Filter_TD_10197211_output));
    trans_JOIN_INNER_TD_9225031.add(&(tbl_Filter_TD_1046563_output));
    trans_JOIN_INNER_TD_9225031.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_9225031), &(events_h2d_wr_JOIN_INNER_TD_9225031[0]));
    events_grp_JOIN_INNER_TD_9225031.push_back(events_h2d_wr_JOIN_INNER_TD_9225031[0]);
    krnl_JOIN_INNER_TD_9225031.run(0, &(events_grp_JOIN_INNER_TD_9225031), &(events_JOIN_INNER_TD_9225031[0]));
    
    trans_JOIN_INNER_TD_9225031_out.add(&(tbl_JOIN_INNER_TD_9225031_output_preprocess));
    trans_JOIN_INNER_TD_9225031_out.dev2host(0, &(events_JOIN_INNER_TD_9225031), &(events_d2h_rd_JOIN_INNER_TD_9225031[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_9225031);
    tbl_JOIN_INNER_TD_9225031_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_9225031_output));
    gettimeofday(&tv_r_JOIN_INNER_9_384158_e, 0);

    struct timeval tv_r_JOIN_INNER_9_644028_s, tv_r_JOIN_INNER_9_644028_e;
    gettimeofday(&tv_r_JOIN_INNER_9_644028_s, 0);
    prev_events_grp_JOIN_INNER_TD_9787277.push_back(events_h2d_wr_JOIN_INNER_TD_10454443[0]);
    trans_JOIN_INNER_TD_9787277.add(&(tbl_Filter_TD_1044974_output));
    trans_JOIN_INNER_TD_9787277.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_9787277), &(events_h2d_wr_JOIN_INNER_TD_9787277[0]));
    events_grp_JOIN_INNER_TD_9787277.push_back(events_h2d_wr_JOIN_INNER_TD_9787277[0]);
    events_grp_JOIN_INNER_TD_9787277.push_back(events_JOIN_INNER_TD_10454443[0]);
    krnl_JOIN_INNER_TD_9787277.run(0, &(events_grp_JOIN_INNER_TD_9787277), &(events_JOIN_INNER_TD_9787277[0]));
    
    trans_JOIN_INNER_TD_9787277_out.add(&(tbl_JOIN_INNER_TD_9787277_output_preprocess));
    trans_JOIN_INNER_TD_9787277_out.dev2host(0, &(events_JOIN_INNER_TD_9787277), &(events_d2h_rd_JOIN_INNER_TD_9787277[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_9787277);
    tbl_JOIN_INNER_TD_9787277_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_9787277_output));
    gettimeofday(&tv_r_JOIN_INNER_9_644028_e, 0);

    struct timeval tv_r_JOIN_INNER_9_879424_s, tv_r_JOIN_INNER_9_879424_e;
    gettimeofday(&tv_r_JOIN_INNER_9_879424_s, 0);
    prev_events_grp_JOIN_INNER_TD_956172.push_back(events_h2d_wr_JOIN_INNER_TD_10976862[0]);
    trans_JOIN_INNER_TD_956172.add(&(tbl_Filter_TD_10535472_output));
    trans_JOIN_INNER_TD_956172.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_956172), &(events_h2d_wr_JOIN_INNER_TD_956172[0]));
    events_grp_JOIN_INNER_TD_956172.push_back(events_h2d_wr_JOIN_INNER_TD_956172[0]);
    events_grp_JOIN_INNER_TD_956172.push_back(events_JOIN_INNER_TD_10976862[0]);
    krnl_JOIN_INNER_TD_956172.run(0, &(events_grp_JOIN_INNER_TD_956172), &(events_JOIN_INNER_TD_956172[0]));
    
    trans_JOIN_INNER_TD_956172_out.add(&(tbl_JOIN_INNER_TD_956172_output_preprocess));
    trans_JOIN_INNER_TD_956172_out.dev2host(0, &(events_JOIN_INNER_TD_956172), &(events_d2h_rd_JOIN_INNER_TD_956172[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_956172);
    tbl_JOIN_INNER_TD_956172_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_956172_output));
    gettimeofday(&tv_r_JOIN_INNER_9_879424_e, 0);

    struct timeval tv_r_Aggregate_8_245268_s, tv_r_Aggregate_8_245268_e;
    gettimeofday(&tv_r_Aggregate_8_245268_s, 0);
    trans_Aggregate_TD_8922127.add(&(tbl_JOIN_INNER_TD_9989152_output));
    trans_Aggregate_TD_8922127.host2dev(0, &(prev_events_grp_Aggregate_TD_8922127), &(events_h2d_wr_Aggregate_TD_8922127[0]));
    events_grp_Aggregate_TD_8922127.push_back(events_h2d_wr_Aggregate_TD_8922127[0]);
    krnl_Aggregate_TD_8922127.run(0, &(events_grp_Aggregate_TD_8922127), &(events_Aggregate_TD_8922127[0]));
    
    trans_Aggregate_TD_8922127_out.add(&(tbl_Aggregate_TD_8922127_output_preprocess));
    trans_Aggregate_TD_8922127_out.dev2host(0, &(events_Aggregate_TD_8922127), &(events_d2h_rd_Aggregate_TD_8922127[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_8922127_consolidate(tbl_Aggregate_TD_8922127_output_preprocess, tbl_Aggregate_TD_8922127_output);
    gettimeofday(&tv_r_Aggregate_8_245268_e, 0);

    struct timeval tv_r_Aggregate_8_664292_s, tv_r_Aggregate_8_664292_e;
    gettimeofday(&tv_r_Aggregate_8_664292_s, 0);
    trans_Aggregate_TD_8707443.add(&(tbl_JOIN_INNER_TD_9549918_output));
    trans_Aggregate_TD_8707443.host2dev(0, &(prev_events_grp_Aggregate_TD_8707443), &(events_h2d_wr_Aggregate_TD_8707443[0]));
    events_grp_Aggregate_TD_8707443.push_back(events_h2d_wr_Aggregate_TD_8707443[0]);
    krnl_Aggregate_TD_8707443.run(0, &(events_grp_Aggregate_TD_8707443), &(events_Aggregate_TD_8707443[0]));
    
    trans_Aggregate_TD_8707443_out.add(&(tbl_Aggregate_TD_8707443_output_preprocess));
    trans_Aggregate_TD_8707443_out.dev2host(0, &(events_Aggregate_TD_8707443), &(events_d2h_rd_Aggregate_TD_8707443[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_8707443_consolidate(tbl_Aggregate_TD_8707443_output_preprocess, tbl_Aggregate_TD_8707443_output);
    gettimeofday(&tv_r_Aggregate_8_664292_e, 0);

    struct timeval tv_r_Aggregate_8_67639_s, tv_r_Aggregate_8_67639_e;
    gettimeofday(&tv_r_Aggregate_8_67639_s, 0);
    trans_Aggregate_TD_858490.add(&(tbl_JOIN_INNER_TD_9208135_output));
    trans_Aggregate_TD_858490.host2dev(0, &(prev_events_grp_Aggregate_TD_858490), &(events_h2d_wr_Aggregate_TD_858490[0]));
    events_grp_Aggregate_TD_858490.push_back(events_h2d_wr_Aggregate_TD_858490[0]);
    krnl_Aggregate_TD_858490.run(0, &(events_grp_Aggregate_TD_858490), &(events_Aggregate_TD_858490[0]));
    
    trans_Aggregate_TD_858490_out.add(&(tbl_Aggregate_TD_858490_output_preprocess));
    trans_Aggregate_TD_858490_out.dev2host(0, &(events_Aggregate_TD_858490), &(events_d2h_rd_Aggregate_TD_858490[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_858490_consolidate(tbl_Aggregate_TD_858490_output_preprocess, tbl_Aggregate_TD_858490_output);
    gettimeofday(&tv_r_Aggregate_8_67639_e, 0);

    struct timeval tv_r_Aggregate_8_439506_s, tv_r_Aggregate_8_439506_e;
    gettimeofday(&tv_r_Aggregate_8_439506_s, 0);
    trans_Aggregate_TD_8763895.add(&(tbl_JOIN_INNER_TD_9225031_output));
    trans_Aggregate_TD_8763895.host2dev(0, &(prev_events_grp_Aggregate_TD_8763895), &(events_h2d_wr_Aggregate_TD_8763895[0]));
    events_grp_Aggregate_TD_8763895.push_back(events_h2d_wr_Aggregate_TD_8763895[0]);
    krnl_Aggregate_TD_8763895.run(0, &(events_grp_Aggregate_TD_8763895), &(events_Aggregate_TD_8763895[0]));
    
    trans_Aggregate_TD_8763895_out.add(&(tbl_Aggregate_TD_8763895_output_preprocess));
    trans_Aggregate_TD_8763895_out.dev2host(0, &(events_Aggregate_TD_8763895), &(events_d2h_rd_Aggregate_TD_8763895[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_8763895_consolidate(tbl_Aggregate_TD_8763895_output_preprocess, tbl_Aggregate_TD_8763895_output);
    gettimeofday(&tv_r_Aggregate_8_439506_e, 0);

    struct timeval tv_r_Aggregate_8_214032_s, tv_r_Aggregate_8_214032_e;
    gettimeofday(&tv_r_Aggregate_8_214032_s, 0);
    trans_Aggregate_TD_8360457.add(&(tbl_JOIN_INNER_TD_9787277_output));
    trans_Aggregate_TD_8360457.host2dev(0, &(prev_events_grp_Aggregate_TD_8360457), &(events_h2d_wr_Aggregate_TD_8360457[0]));
    events_grp_Aggregate_TD_8360457.push_back(events_h2d_wr_Aggregate_TD_8360457[0]);
    krnl_Aggregate_TD_8360457.run(0, &(events_grp_Aggregate_TD_8360457), &(events_Aggregate_TD_8360457[0]));
    
    trans_Aggregate_TD_8360457_out.add(&(tbl_Aggregate_TD_8360457_output_preprocess));
    trans_Aggregate_TD_8360457_out.dev2host(0, &(events_Aggregate_TD_8360457), &(events_d2h_rd_Aggregate_TD_8360457[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_8360457_consolidate(tbl_Aggregate_TD_8360457_output_preprocess, tbl_Aggregate_TD_8360457_output);
    gettimeofday(&tv_r_Aggregate_8_214032_e, 0);

    struct timeval tv_r_Aggregate_8_831302_s, tv_r_Aggregate_8_831302_e;
    gettimeofday(&tv_r_Aggregate_8_831302_s, 0);
    trans_Aggregate_TD_8981652.add(&(tbl_JOIN_INNER_TD_956172_output));
    trans_Aggregate_TD_8981652.host2dev(0, &(prev_events_grp_Aggregate_TD_8981652), &(events_h2d_wr_Aggregate_TD_8981652[0]));
    events_grp_Aggregate_TD_8981652.push_back(events_h2d_wr_Aggregate_TD_8981652[0]);
    krnl_Aggregate_TD_8981652.run(0, &(events_grp_Aggregate_TD_8981652), &(events_Aggregate_TD_8981652[0]));
    
    trans_Aggregate_TD_8981652_out.add(&(tbl_Aggregate_TD_8981652_output_preprocess));
    trans_Aggregate_TD_8981652_out.dev2host(0, &(events_Aggregate_TD_8981652), &(events_d2h_rd_Aggregate_TD_8981652[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_8981652_consolidate(tbl_Aggregate_TD_8981652_output_preprocess, tbl_Aggregate_TD_8981652_output);
    gettimeofday(&tv_r_Aggregate_8_831302_e, 0);

    struct timeval tv_r_JOIN_LEFTOUTER_7_990629_s, tv_r_JOIN_LEFTOUTER_7_990629_e;
    gettimeofday(&tv_r_JOIN_LEFTOUTER_7_990629_s, 0);
    trans_JOIN_LEFTOUTER_TD_7206188.add(&(tbl_Aggregate_TD_8707443_output));
    trans_JOIN_LEFTOUTER_TD_7206188.add(&(tbl_Aggregate_TD_8922127_output));
    trans_JOIN_LEFTOUTER_TD_7206188.host2dev(0, &(prev_events_grp_JOIN_LEFTOUTER_TD_7206188), &(events_h2d_wr_JOIN_LEFTOUTER_TD_7206188[0]));
    events_grp_JOIN_LEFTOUTER_TD_7206188.push_back(events_h2d_wr_JOIN_LEFTOUTER_TD_7206188[0]);
    krnl_JOIN_LEFTOUTER_TD_7206188.run(0, &(events_grp_JOIN_LEFTOUTER_TD_7206188), &(events_JOIN_LEFTOUTER_TD_7206188[0]));
    
    trans_JOIN_LEFTOUTER_TD_7206188_out.add(&(tbl_JOIN_LEFTOUTER_TD_7206188_output));
    trans_JOIN_LEFTOUTER_TD_7206188_out.dev2host(0, &(events_JOIN_LEFTOUTER_TD_7206188), &(events_d2h_rd_JOIN_LEFTOUTER_TD_7206188[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_LEFTOUTER_7_990629_e, 0);

    struct timeval tv_r_JOIN_CROSS_7_424799_s, tv_r_JOIN_CROSS_7_424799_e;
    gettimeofday(&tv_r_JOIN_CROSS_7_424799_s, 0);
    SW_JOIN_CROSS_TD_7789765(tbl_Aggregate_TD_8763895_output, tbl_Aggregate_TD_858490_output, tbl_JOIN_CROSS_TD_7789765_output);
    gettimeofday(&tv_r_JOIN_CROSS_7_424799_e, 0);

    struct timeval tv_r_JOIN_LEFTOUTER_7_920251_s, tv_r_JOIN_LEFTOUTER_7_920251_e;
    gettimeofday(&tv_r_JOIN_LEFTOUTER_7_920251_s, 0);
    trans_JOIN_LEFTOUTER_TD_7746880.add(&(tbl_Aggregate_TD_8981652_output));
    trans_JOIN_LEFTOUTER_TD_7746880.add(&(tbl_Aggregate_TD_8360457_output));
    trans_JOIN_LEFTOUTER_TD_7746880.host2dev(0, &(prev_events_grp_JOIN_LEFTOUTER_TD_7746880), &(events_h2d_wr_JOIN_LEFTOUTER_TD_7746880[0]));
    events_grp_JOIN_LEFTOUTER_TD_7746880.push_back(events_h2d_wr_JOIN_LEFTOUTER_TD_7746880[0]);
    krnl_JOIN_LEFTOUTER_TD_7746880.run(0, &(events_grp_JOIN_LEFTOUTER_TD_7746880), &(events_JOIN_LEFTOUTER_TD_7746880[0]));
    
    trans_JOIN_LEFTOUTER_TD_7746880_out.add(&(tbl_JOIN_LEFTOUTER_TD_7746880_output));
    trans_JOIN_LEFTOUTER_TD_7746880_out.dev2host(0, &(events_JOIN_LEFTOUTER_TD_7746880), &(events_d2h_rd_JOIN_LEFTOUTER_TD_7746880[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_LEFTOUTER_7_920251_e, 0);

    struct timeval tv_r_Project_6_651232_s, tv_r_Project_6_651232_e;
    gettimeofday(&tv_r_Project_6_651232_s, 0);
    SW_Project_TD_6224311(tbl_JOIN_LEFTOUTER_TD_7206188_output, tbl_Project_TD_6224311_output);
    gettimeofday(&tv_r_Project_6_651232_e, 0);

    struct timeval tv_r_Project_6_687749_s, tv_r_Project_6_687749_e;
    gettimeofday(&tv_r_Project_6_687749_s, 0);
    SW_Project_TD_6997933(tbl_JOIN_CROSS_TD_7789765_output, tbl_Project_TD_6997933_output);
    gettimeofday(&tv_r_Project_6_687749_e, 0);

    struct timeval tv_r_Project_6_558418_s, tv_r_Project_6_558418_e;
    gettimeofday(&tv_r_Project_6_558418_s, 0);
    SW_Project_TD_6172041(tbl_JOIN_LEFTOUTER_TD_7746880_output, tbl_Project_TD_6172041_output);
    gettimeofday(&tv_r_Project_6_558418_e, 0);

    struct timeval tv_r_Union_5_405197_s, tv_r_Union_5_405197_e;
    gettimeofday(&tv_r_Union_5_405197_s, 0);
    SW_Union_TD_5775228(tbl_Project_TD_6172041_output, tbl_Project_TD_6997933_output, tbl_Project_TD_6224311_output, tbl_Union_TD_5775228_output);
    gettimeofday(&tv_r_Union_5_405197_e, 0);

    struct timeval tv_r_Expand_4_274919_s, tv_r_Expand_4_274919_e;
    gettimeofday(&tv_r_Expand_4_274919_s, 0);
    SW_Expand_TD_44392(tbl_Union_TD_5775228_output, tbl_Expand_TD_44392_output);
    gettimeofday(&tv_r_Expand_4_274919_e, 0);

    struct timeval tv_r_Aggregate_3_27952_s, tv_r_Aggregate_3_27952_e;
    gettimeofday(&tv_r_Aggregate_3_27952_s, 0);
    SW_Aggregate_TD_3725792(tbl_Expand_TD_44392_output, tbl_Aggregate_TD_3725792_output);
    gettimeofday(&tv_r_Aggregate_3_27952_e, 0);

    struct timeval tv_r_Sort_2_870052_s, tv_r_Sort_2_870052_e;
    gettimeofday(&tv_r_Sort_2_870052_s, 0);
    SW_Sort_TD_2219717(tbl_Aggregate_TD_3725792_output, tbl_Sort_TD_2219717_output);
    gettimeofday(&tv_r_Sort_2_870052_e, 0);

    struct timeval tv_r_LocalLimit_1_67358_s, tv_r_LocalLimit_1_67358_e;
    gettimeofday(&tv_r_LocalLimit_1_67358_s, 0);
    SW_LocalLimit_TD_1514409(tbl_Sort_TD_2219717_output, tbl_LocalLimit_TD_1514409_output);
    gettimeofday(&tv_r_LocalLimit_1_67358_e, 0);

    struct timeval tv_r_GlobalLimit_0_86650_s, tv_r_GlobalLimit_0_86650_e;
    gettimeofday(&tv_r_GlobalLimit_0_86650_s, 0);
    SW_GlobalLimit_TD_0369527(tbl_LocalLimit_TD_1514409_output, tbl_GlobalLimit_TD_0369527_output);
    gettimeofday(&tv_r_GlobalLimit_0_86650_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_725809_s, &tv_r_Filter_11_725809_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12223447_input: " << tbl_SerializeFromObject_TD_12223447_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_341961_s, &tv_r_Filter_11_341961_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12305071_input: " << tbl_SerializeFromObject_TD_12305071_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_358937_s, &tv_r_Filter_11_358937_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1291518_input: " << tbl_SerializeFromObject_TD_1291518_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_983399_s, &tv_r_Filter_11_983399_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12791368_input: " << tbl_SerializeFromObject_TD_12791368_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_361038_s, &tv_r_Filter_11_361038_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12794166_input: " << tbl_SerializeFromObject_TD_12794166_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_19378_s, &tv_r_Filter_11_19378_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12935067_input: " << tbl_SerializeFromObject_TD_12935067_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_930955_s, &tv_r_Filter_11_930955_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12783138_input: " << tbl_SerializeFromObject_TD_12783138_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_572068_s, &tv_r_Filter_11_572068_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12887464_input: " << tbl_SerializeFromObject_TD_12887464_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_548014_s, &tv_r_Filter_10_548014_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11223040_input: " << tbl_SerializeFromObject_TD_11223040_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_88363_s, &tv_r_JOIN_INNER_10_88363_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11118799_output: " << tbl_Filter_TD_11118799_output.getNumRow() << " " << "tbl_Filter_TD_11223248_output: " << tbl_Filter_TD_11223248_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_4109_s, &tv_r_Filter_10_4109_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11461628_input: " << tbl_SerializeFromObject_TD_11461628_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_983866_s, &tv_r_JOIN_INNER_10_983866_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11281364_output: " << tbl_Filter_TD_11281364_output.getNumRow() << " " << "tbl_Filter_TD_11210199_output: " << tbl_Filter_TD_11210199_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_169895_s, &tv_r_Filter_10_169895_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11524432_input: " << tbl_SerializeFromObject_TD_11524432_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_859716_s, &tv_r_Filter_10_859716_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1153545_input: " << tbl_SerializeFromObject_TD_1153545_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_94497_s, &tv_r_Filter_10_94497_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11299306_input: " << tbl_SerializeFromObject_TD_11299306_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_911563_s, &tv_r_Filter_10_911563_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11279308_input: " << tbl_SerializeFromObject_TD_11279308_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_143648_s, &tv_r_Filter_10_143648_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11249664_input: " << tbl_SerializeFromObject_TD_11249664_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_312002_s, &tv_r_JOIN_INNER_10_312002_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11226393_output: " << tbl_Filter_TD_11226393_output.getNumRow() << " " << "tbl_Filter_TD_1145_output: " << tbl_Filter_TD_1145_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_969278_s, &tv_r_Filter_10_969278_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11586100_input: " << tbl_SerializeFromObject_TD_11586100_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_529261_s, &tv_r_JOIN_INNER_10_529261_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11932688_output: " << tbl_Filter_TD_11932688_output.getNumRow() << " " << "tbl_Filter_TD_11687332_output: " << tbl_Filter_TD_11687332_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_63647_s, &tv_r_JOIN_INNER_9_63647_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10865676_output: " << tbl_JOIN_INNER_TD_10865676_output.getNumRow() << " " << "tbl_Filter_TD_10626660_output: " << tbl_Filter_TD_10626660_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_384576_s, &tv_r_JOIN_INNER_9_384576_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10232436_output: " << tbl_JOIN_INNER_TD_10232436_output.getNumRow() << " " << "tbl_Filter_TD_10136224_output: " << tbl_Filter_TD_10136224_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_721389_s, &tv_r_JOIN_INNER_9_721389_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10188919_output: " << tbl_Filter_TD_10188919_output.getNumRow() << " " << "tbl_Filter_TD_10899949_output: " << tbl_Filter_TD_10899949_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_384158_s, &tv_r_JOIN_INNER_9_384158_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10197211_output: " << tbl_Filter_TD_10197211_output.getNumRow() << " " << "tbl_Filter_TD_1046563_output: " << tbl_Filter_TD_1046563_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_644028_s, &tv_r_JOIN_INNER_9_644028_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10454443_output: " << tbl_JOIN_INNER_TD_10454443_output.getNumRow() << " " << "tbl_Filter_TD_1044974_output: " << tbl_Filter_TD_1044974_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_879424_s, &tv_r_JOIN_INNER_9_879424_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10976862_output: " << tbl_JOIN_INNER_TD_10976862_output.getNumRow() << " " << "tbl_Filter_TD_10535472_output: " << tbl_Filter_TD_10535472_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_8: " << tvdiff(&tv_r_Aggregate_8_245268_s, &tv_r_Aggregate_8_245268_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9989152_output: " << tbl_JOIN_INNER_TD_9989152_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_8: " << tvdiff(&tv_r_Aggregate_8_664292_s, &tv_r_Aggregate_8_664292_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9549918_output: " << tbl_JOIN_INNER_TD_9549918_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_8: " << tvdiff(&tv_r_Aggregate_8_67639_s, &tv_r_Aggregate_8_67639_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9208135_output: " << tbl_JOIN_INNER_TD_9208135_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_8: " << tvdiff(&tv_r_Aggregate_8_439506_s, &tv_r_Aggregate_8_439506_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9225031_output: " << tbl_JOIN_INNER_TD_9225031_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_8: " << tvdiff(&tv_r_Aggregate_8_214032_s, &tv_r_Aggregate_8_214032_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9787277_output: " << tbl_JOIN_INNER_TD_9787277_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_8: " << tvdiff(&tv_r_Aggregate_8_831302_s, &tv_r_Aggregate_8_831302_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_956172_output: " << tbl_JOIN_INNER_TD_956172_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTOUTER_7: " << tvdiff(&tv_r_JOIN_LEFTOUTER_7_990629_s, &tv_r_JOIN_LEFTOUTER_7_990629_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_8707443_output: " << tbl_Aggregate_TD_8707443_output.getNumRow() << " " << "tbl_Aggregate_TD_8922127_output: " << tbl_Aggregate_TD_8922127_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_CROSS_7: " << tvdiff(&tv_r_JOIN_CROSS_7_424799_s, &tv_r_JOIN_CROSS_7_424799_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_8763895_output: " << tbl_Aggregate_TD_8763895_output.getNumRow() << " " << "tbl_Aggregate_TD_858490_output: " << tbl_Aggregate_TD_858490_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTOUTER_7: " << tvdiff(&tv_r_JOIN_LEFTOUTER_7_920251_s, &tv_r_JOIN_LEFTOUTER_7_920251_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_8981652_output: " << tbl_Aggregate_TD_8981652_output.getNumRow() << " " << "tbl_Aggregate_TD_8360457_output: " << tbl_Aggregate_TD_8360457_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_6: " << tvdiff(&tv_r_Project_6_651232_s, &tv_r_Project_6_651232_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTOUTER_TD_7206188_output: " << tbl_JOIN_LEFTOUTER_TD_7206188_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_6: " << tvdiff(&tv_r_Project_6_687749_s, &tv_r_Project_6_687749_e) / 1000.0 << " ms " 
     << "tbl_JOIN_CROSS_TD_7789765_output: " << tbl_JOIN_CROSS_TD_7789765_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_6: " << tvdiff(&tv_r_Project_6_558418_s, &tv_r_Project_6_558418_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTOUTER_TD_7746880_output: " << tbl_JOIN_LEFTOUTER_TD_7746880_output.getNumRow() << " " << std::endl; 

    std::cout << "Union_5: " << tvdiff(&tv_r_Union_5_405197_s, &tv_r_Union_5_405197_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_6172041_output: " << tbl_Project_TD_6172041_output.getNumRow() << " " << "tbl_Project_TD_6997933_output: " << tbl_Project_TD_6997933_output.getNumRow() << " " << "tbl_Project_TD_6224311_output: " << tbl_Project_TD_6224311_output.getNumRow() << " " << std::endl; 

    std::cout << "Expand_4: " << tvdiff(&tv_r_Expand_4_274919_s, &tv_r_Expand_4_274919_e) / 1000.0 << " ms " 
     << "tbl_Union_TD_5775228_output: " << tbl_Union_TD_5775228_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_27952_s, &tv_r_Aggregate_3_27952_e) / 1000.0 << " ms " 
     << "tbl_Expand_TD_44392_output: " << tbl_Expand_TD_44392_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_870052_s, &tv_r_Sort_2_870052_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3725792_output: " << tbl_Aggregate_TD_3725792_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_67358_s, &tv_r_LocalLimit_1_67358_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2219717_output: " << tbl_Sort_TD_2219717_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_86650_s, &tv_r_GlobalLimit_0_86650_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1514409_output: " << tbl_LocalLimit_TD_1514409_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 4.9065413 * 1000 << "ms" << std::endl; 
    return 0; 
}
