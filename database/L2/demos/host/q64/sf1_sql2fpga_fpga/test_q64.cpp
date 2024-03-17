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

#include "cfgFunc_q64.hpp" 
#include "q64.hpp" 

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
    std::cout << "NOTE:running query #64\n."; 
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
    Table tbl_Sort_TD_0976842_output("tbl_Sort_TD_0976842_output", 6100000, 22, "");
    tbl_Sort_TD_0976842_output.allocateHost();
    Table tbl_Project_TD_1260547_output("tbl_Project_TD_1260547_output", 6100000, 22, "");
    tbl_Project_TD_1260547_output.allocateHost();
    Table tbl_JOIN_INNER_TD_2710081_output("tbl_JOIN_INNER_TD_2710081_output", 6100000, 21, "");
    tbl_JOIN_INNER_TD_2710081_output.allocateHost();
    Table tbl_Aggregate_TD_3607278_output("tbl_Aggregate_TD_3607278_output", 6100000, 17, "");
    tbl_Aggregate_TD_3607278_output.allocateHost();
    Table tbl_Aggregate_TD_3248686_output("tbl_Aggregate_TD_3248686_output", 6100000, 8, "");
    tbl_Aggregate_TD_3248686_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4338385_output("tbl_JOIN_INNER_TD_4338385_output", 6100000, 18, "");
    tbl_JOIN_INNER_TD_4338385_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4452906_output("tbl_JOIN_INNER_TD_4452906_output", 6100000, 18, "");
    tbl_JOIN_INNER_TD_4452906_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5927078_output("tbl_JOIN_INNER_TD_5927078_output", 6100000, 17, "");
    tbl_JOIN_INNER_TD_5927078_output.allocateHost();
    Table tbl_Filter_TD_5748863_output("tbl_Filter_TD_5748863_output", 6100000, 2, "");
    tbl_Filter_TD_5748863_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5724624_output("tbl_JOIN_INNER_TD_5724624_output", 6100000, 17, "");
    tbl_JOIN_INNER_TD_5724624_output.allocateHost();
    Table tbl_Filter_TD_5514808_output("tbl_Filter_TD_5514808_output", 6100000, 2, "");
    tbl_Filter_TD_5514808_output.allocateHost();
    Table tbl_JOIN_INNER_TD_653599_output("tbl_JOIN_INNER_TD_653599_output", 6100000, 18, "");
    tbl_JOIN_INNER_TD_653599_output.allocateHost();
    Table tbl_Filter_TD_6461371_output("tbl_Filter_TD_6461371_output", 6100000, 1, "");
    tbl_Filter_TD_6461371_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6648753_input;
    tbl_SerializeFromObject_TD_6648753_input = Table("item", item_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_6648753_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_6648753_input.addCol("i_product_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6648753_input.addCol("i_current_price", 4);
    tbl_SerializeFromObject_TD_6648753_input.addCol("i_color", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6648753_input.allocateHost();
    tbl_SerializeFromObject_TD_6648753_input.loadHost();
    Table tbl_JOIN_INNER_TD_6838150_output("tbl_JOIN_INNER_TD_6838150_output", 6100000, 18, "");
    tbl_JOIN_INNER_TD_6838150_output.allocateHost();
    Table tbl_Filter_TD_6220581_output("tbl_Filter_TD_6220581_output", 6100000, 1, "");
    tbl_Filter_TD_6220581_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6423713_input;
    tbl_SerializeFromObject_TD_6423713_input = Table("item", item_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_6423713_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_6423713_input.addCol("i_product_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6423713_input.addCol("i_current_price", 4);
    tbl_SerializeFromObject_TD_6423713_input.addCol("i_color", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6423713_input.allocateHost();
    tbl_SerializeFromObject_TD_6423713_input.loadHost();
    Table tbl_JOIN_INNER_TD_74545_output("tbl_JOIN_INNER_TD_74545_output", 6100000, 19, "");
    tbl_JOIN_INNER_TD_74545_output.allocateHost();
    Table tbl_Filter_TD_727362_output("tbl_Filter_TD_727362_output", 6100000, 1, "");
    tbl_Filter_TD_727362_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7194992_input;
    tbl_SerializeFromObject_TD_7194992_input = Table("income_band", income_band_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_7194992_input.addCol("ib_income_band_sk", 4);
    tbl_SerializeFromObject_TD_7194992_input.allocateHost();
    tbl_SerializeFromObject_TD_7194992_input.loadHost();
    Table tbl_JOIN_INNER_TD_7719384_output("tbl_JOIN_INNER_TD_7719384_output", 6100000, 19, "");
    tbl_JOIN_INNER_TD_7719384_output.allocateHost();
    Table tbl_Filter_TD_7895840_output("tbl_Filter_TD_7895840_output", 6100000, 1, "");
    tbl_Filter_TD_7895840_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7880239_input;
    tbl_SerializeFromObject_TD_7880239_input = Table("income_band", income_band_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_7880239_input.addCol("ib_income_band_sk", 4);
    tbl_SerializeFromObject_TD_7880239_input.allocateHost();
    tbl_SerializeFromObject_TD_7880239_input.loadHost();
    Table tbl_JOIN_INNER_TD_8755957_output("tbl_JOIN_INNER_TD_8755957_output", 6100000, 16, "");
    tbl_JOIN_INNER_TD_8755957_output.allocateHost();
    Table tbl_Filter_TD_8585812_output("tbl_Filter_TD_8585812_output", 6100000, 5, "");
    tbl_Filter_TD_8585812_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8344879_input;
    tbl_SerializeFromObject_TD_8344879_input = Table("income_band", income_band_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_8344879_input.addCol("ib_income_band_sk", 4);
    tbl_SerializeFromObject_TD_8344879_input.allocateHost();
    tbl_SerializeFromObject_TD_8344879_input.loadHost();
    Table tbl_JOIN_INNER_TD_8966505_output("tbl_JOIN_INNER_TD_8966505_output", 6100000, 16, "");
    tbl_JOIN_INNER_TD_8966505_output.allocateHost();
    Table tbl_Filter_TD_8103123_output("tbl_Filter_TD_8103123_output", 6100000, 5, "");
    tbl_Filter_TD_8103123_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8407051_input;
    tbl_SerializeFromObject_TD_8407051_input = Table("income_band", income_band_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_8407051_input.addCol("ib_income_band_sk", 4);
    tbl_SerializeFromObject_TD_8407051_input.allocateHost();
    tbl_SerializeFromObject_TD_8407051_input.loadHost();
    Table tbl_JOIN_INNER_TD_9678884_output("tbl_JOIN_INNER_TD_9678884_output", 6100000, 13, "");
    tbl_JOIN_INNER_TD_9678884_output.allocateHost();
    Table tbl_Filter_TD_9772283_output("tbl_Filter_TD_9772283_output", 6100000, 5, "");
    tbl_Filter_TD_9772283_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9859896_input;
    tbl_SerializeFromObject_TD_9859896_input = Table("customer_address", customer_address_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_9859896_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_9859896_input.addCol("ca_street_number", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9859896_input.addCol("ca_street_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9859896_input.addCol("ca_city", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9859896_input.addCol("ca_zip", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9859896_input.allocateHost();
    tbl_SerializeFromObject_TD_9859896_input.loadHost();
    Table tbl_JOIN_INNER_TD_9425844_output("tbl_JOIN_INNER_TD_9425844_output", 6100000, 13, "");
    tbl_JOIN_INNER_TD_9425844_output.allocateHost();
    Table tbl_Filter_TD_9328766_output("tbl_Filter_TD_9328766_output", 6100000, 5, "");
    tbl_Filter_TD_9328766_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9446210_input;
    tbl_SerializeFromObject_TD_9446210_input = Table("customer_address", customer_address_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_9446210_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_9446210_input.addCol("ca_street_number", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9446210_input.addCol("ca_street_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9446210_input.addCol("ca_city", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9446210_input.addCol("ca_zip", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9446210_input.allocateHost();
    tbl_SerializeFromObject_TD_9446210_input.loadHost();
    Table tbl_JOIN_INNER_TD_10446614_output("tbl_JOIN_INNER_TD_10446614_output", 6100000, 13, "");
    tbl_JOIN_INNER_TD_10446614_output.allocateHost();
    Table tbl_Filter_TD_1015392_output("tbl_Filter_TD_1015392_output", 6100000, 2, "");
    tbl_Filter_TD_1015392_output.allocateHost();
    Table tbl_SerializeFromObject_TD_1065428_input;
    tbl_SerializeFromObject_TD_1065428_input = Table("customer_address", customer_address_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_1065428_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_1065428_input.addCol("ca_street_number", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_1065428_input.addCol("ca_street_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_1065428_input.addCol("ca_city", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_1065428_input.addCol("ca_zip", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_1065428_input.allocateHost();
    tbl_SerializeFromObject_TD_1065428_input.loadHost();
    Table tbl_JOIN_INNER_TD_10951912_output("tbl_JOIN_INNER_TD_10951912_output", 6100000, 13, "");
    tbl_JOIN_INNER_TD_10951912_output.allocateHost();
    Table tbl_Filter_TD_10762193_output("tbl_Filter_TD_10762193_output", 6100000, 2, "");
    tbl_Filter_TD_10762193_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10706938_input;
    tbl_SerializeFromObject_TD_10706938_input = Table("customer_address", customer_address_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_10706938_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_10706938_input.addCol("ca_street_number", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10706938_input.addCol("ca_street_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10706938_input.addCol("ca_city", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10706938_input.addCol("ca_zip", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10706938_input.allocateHost();
    tbl_SerializeFromObject_TD_10706938_input.loadHost();
    Table tbl_JOIN_INNER_TD_11526036_output("tbl_JOIN_INNER_TD_11526036_output", 6100000, 13, "");
    tbl_JOIN_INNER_TD_11526036_output.allocateHost();
    Table tbl_Filter_TD_1117050_output("tbl_Filter_TD_1117050_output", 6100000, 2, "");
    tbl_Filter_TD_1117050_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11703170_input;
    tbl_SerializeFromObject_TD_11703170_input = Table("household_demographics", household_demographics_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11703170_input.addCol("hd_demo_sk", 4);
    tbl_SerializeFromObject_TD_11703170_input.addCol("hd_income_band_sk", 4);
    tbl_SerializeFromObject_TD_11703170_input.allocateHost();
    tbl_SerializeFromObject_TD_11703170_input.loadHost();
    Table tbl_JOIN_INNER_TD_11493165_output("tbl_JOIN_INNER_TD_11493165_output", 6100000, 13, "");
    tbl_JOIN_INNER_TD_11493165_output.allocateHost();
    Table tbl_Filter_TD_11557957_output("tbl_Filter_TD_11557957_output", 6100000, 2, "");
    tbl_Filter_TD_11557957_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11758762_input;
    tbl_SerializeFromObject_TD_11758762_input = Table("household_demographics", household_demographics_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11758762_input.addCol("hd_demo_sk", 4);
    tbl_SerializeFromObject_TD_11758762_input.addCol("hd_income_band_sk", 4);
    tbl_SerializeFromObject_TD_11758762_input.allocateHost();
    tbl_SerializeFromObject_TD_11758762_input.loadHost();
    Table tbl_JOIN_INNER_TD_12115296_output("tbl_JOIN_INNER_TD_12115296_output", 6100000, 14, "");
    tbl_JOIN_INNER_TD_12115296_output.allocateHost();
    Table tbl_Filter_TD_12174597_output("tbl_Filter_TD_12174597_output", 6100000, 1, "");
    tbl_Filter_TD_12174597_output.allocateHost();
    Table tbl_SerializeFromObject_TD_12986662_input;
    tbl_SerializeFromObject_TD_12986662_input = Table("household_demographics", household_demographics_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12986662_input.addCol("hd_demo_sk", 4);
    tbl_SerializeFromObject_TD_12986662_input.addCol("hd_income_band_sk", 4);
    tbl_SerializeFromObject_TD_12986662_input.allocateHost();
    tbl_SerializeFromObject_TD_12986662_input.loadHost();
    Table tbl_JOIN_INNER_TD_12273451_output("tbl_JOIN_INNER_TD_12273451_output", 6100000, 14, "");
    tbl_JOIN_INNER_TD_12273451_output.allocateHost();
    Table tbl_Filter_TD_124448_output("tbl_Filter_TD_124448_output", 6100000, 1, "");
    tbl_Filter_TD_124448_output.allocateHost();
    Table tbl_SerializeFromObject_TD_12679417_input;
    tbl_SerializeFromObject_TD_12679417_input = Table("household_demographics", household_demographics_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12679417_input.addCol("hd_demo_sk", 4);
    tbl_SerializeFromObject_TD_12679417_input.addCol("hd_income_band_sk", 4);
    tbl_SerializeFromObject_TD_12679417_input.allocateHost();
    tbl_SerializeFromObject_TD_12679417_input.loadHost();
    Table tbl_JOIN_INNER_TD_13600633_output("tbl_JOIN_INNER_TD_13600633_output", 6100000, 16, "");
    tbl_JOIN_INNER_TD_13600633_output.allocateHost();
    Table tbl_Filter_TD_13256744_output("tbl_Filter_TD_13256744_output", 6100000, 2, "");
    tbl_Filter_TD_13256744_output.allocateHost();
    Table tbl_SerializeFromObject_TD_13651411_input;
    tbl_SerializeFromObject_TD_13651411_input = Table("promotion", promotion_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_13651411_input.addCol("p_promo_sk", 4);
    tbl_SerializeFromObject_TD_13651411_input.allocateHost();
    tbl_SerializeFromObject_TD_13651411_input.loadHost();
    Table tbl_JOIN_INNER_TD_13369006_output("tbl_JOIN_INNER_TD_13369006_output", 6100000, 16, "");
    tbl_JOIN_INNER_TD_13369006_output.allocateHost();
    Table tbl_Filter_TD_13655875_output("tbl_Filter_TD_13655875_output", 6100000, 2, "");
    tbl_Filter_TD_13655875_output.allocateHost();
    Table tbl_SerializeFromObject_TD_13452394_input;
    tbl_SerializeFromObject_TD_13452394_input = Table("promotion", promotion_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_13452394_input.addCol("p_promo_sk", 4);
    tbl_SerializeFromObject_TD_13452394_input.allocateHost();
    tbl_SerializeFromObject_TD_13452394_input.loadHost();
    Table tbl_JOIN_INNER_TD_14267925_output("tbl_JOIN_INNER_TD_14267925_output", 6100000, 16, "");
    tbl_JOIN_INNER_TD_14267925_output.allocateHost();
    Table tbl_Filter_TD_14892724_output("tbl_Filter_TD_14892724_output", 6100000, 2, "");
    tbl_Filter_TD_14892724_output.allocateHost();
    Table tbl_SerializeFromObject_TD_14853068_input;
    tbl_SerializeFromObject_TD_14853068_input = Table("customer_demographics", customer_demographics_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_14853068_input.addCol("cd_demo_sk", 4);
    tbl_SerializeFromObject_TD_14853068_input.addCol("cd_marital_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_14853068_input.allocateHost();
    tbl_SerializeFromObject_TD_14853068_input.loadHost();
    Table tbl_JOIN_INNER_TD_14747919_output("tbl_JOIN_INNER_TD_14747919_output", 6100000, 16, "");
    tbl_JOIN_INNER_TD_14747919_output.allocateHost();
    Table tbl_Filter_TD_14721747_output("tbl_Filter_TD_14721747_output", 6100000, 2, "");
    tbl_Filter_TD_14721747_output.allocateHost();
    Table tbl_SerializeFromObject_TD_14299454_input;
    tbl_SerializeFromObject_TD_14299454_input = Table("customer_demographics", customer_demographics_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_14299454_input.addCol("cd_demo_sk", 4);
    tbl_SerializeFromObject_TD_14299454_input.addCol("cd_marital_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_14299454_input.allocateHost();
    tbl_SerializeFromObject_TD_14299454_input.loadHost();
    Table tbl_JOIN_INNER_TD_15907739_output("tbl_JOIN_INNER_TD_15907739_output", 6100000, 16, "");
    tbl_JOIN_INNER_TD_15907739_output.allocateHost();
    Table tbl_Filter_TD_15770298_output("tbl_Filter_TD_15770298_output", 6100000, 2, "");
    tbl_Filter_TD_15770298_output.allocateHost();
    Table tbl_SerializeFromObject_TD_15734826_input;
    tbl_SerializeFromObject_TD_15734826_input = Table("customer_demographics", customer_demographics_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_15734826_input.addCol("cd_demo_sk", 4);
    tbl_SerializeFromObject_TD_15734826_input.addCol("cd_marital_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_15734826_input.allocateHost();
    tbl_SerializeFromObject_TD_15734826_input.loadHost();
    Table tbl_JOIN_INNER_TD_15257714_output("tbl_JOIN_INNER_TD_15257714_output", 6100000, 16, "");
    tbl_JOIN_INNER_TD_15257714_output.allocateHost();
    Table tbl_Filter_TD_15892114_output("tbl_Filter_TD_15892114_output", 6100000, 2, "");
    tbl_Filter_TD_15892114_output.allocateHost();
    Table tbl_SerializeFromObject_TD_15202776_input;
    tbl_SerializeFromObject_TD_15202776_input = Table("customer_demographics", customer_demographics_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_15202776_input.addCol("cd_demo_sk", 4);
    tbl_SerializeFromObject_TD_15202776_input.addCol("cd_marital_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_15202776_input.allocateHost();
    tbl_SerializeFromObject_TD_15202776_input.loadHost();
    Table tbl_JOIN_INNER_TD_16633534_output("tbl_JOIN_INNER_TD_16633534_output", 6100000, 16, "");
    tbl_JOIN_INNER_TD_16633534_output.allocateHost();
    Table tbl_Filter_TD_16426838_output("tbl_Filter_TD_16426838_output", 6100000, 2, "");
    tbl_Filter_TD_16426838_output.allocateHost();
    Table tbl_SerializeFromObject_TD_1695065_input;
    tbl_SerializeFromObject_TD_1695065_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_1695065_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_1695065_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_1695065_input.allocateHost();
    tbl_SerializeFromObject_TD_1695065_input.loadHost();
    Table tbl_JOIN_INNER_TD_16134853_output("tbl_JOIN_INNER_TD_16134853_output", 6100000, 16, "");
    tbl_JOIN_INNER_TD_16134853_output.allocateHost();
    Table tbl_Filter_TD_16382357_output("tbl_Filter_TD_16382357_output", 6100000, 2, "");
    tbl_Filter_TD_16382357_output.allocateHost();
    Table tbl_SerializeFromObject_TD_16553257_input;
    tbl_SerializeFromObject_TD_16553257_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_16553257_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_16553257_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_16553257_input.allocateHost();
    tbl_SerializeFromObject_TD_16553257_input.loadHost();
    Table tbl_JOIN_INNER_TD_17102777_output("tbl_JOIN_INNER_TD_17102777_output", 6100000, 12, "");
    tbl_JOIN_INNER_TD_17102777_output.allocateHost();
    Table tbl_Filter_TD_17180494_output("tbl_Filter_TD_17180494_output", 6100000, 6, "");
    tbl_Filter_TD_17180494_output.allocateHost();
    Table tbl_SerializeFromObject_TD_1799058_input;
    tbl_SerializeFromObject_TD_1799058_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_1799058_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_1799058_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_1799058_input.allocateHost();
    tbl_SerializeFromObject_TD_1799058_input.loadHost();
    Table tbl_JOIN_INNER_TD_17330885_output("tbl_JOIN_INNER_TD_17330885_output", 6100000, 12, "");
    tbl_JOIN_INNER_TD_17330885_output.allocateHost();
    Table tbl_Filter_TD_17952307_output("tbl_Filter_TD_17952307_output", 6100000, 6, "");
    tbl_Filter_TD_17952307_output.allocateHost();
    Table tbl_SerializeFromObject_TD_17244473_input;
    tbl_SerializeFromObject_TD_17244473_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_17244473_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_17244473_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_17244473_input.allocateHost();
    tbl_SerializeFromObject_TD_17244473_input.loadHost();
    Table tbl_JOIN_INNER_TD_18402844_output("tbl_JOIN_INNER_TD_18402844_output", 6100000, 11, "");
    tbl_JOIN_INNER_TD_18402844_output.allocateHost();
    Table tbl_Filter_TD_18921231_output("tbl_Filter_TD_18921231_output", 6100000, 3, "");
    tbl_Filter_TD_18921231_output.allocateHost();
    Table tbl_SerializeFromObject_TD_18137679_input;
    tbl_SerializeFromObject_TD_18137679_input = Table("customer", customer_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_18137679_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_18137679_input.addCol("c_current_cdemo_sk", 4);
    tbl_SerializeFromObject_TD_18137679_input.addCol("c_current_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_18137679_input.addCol("c_current_addr_sk", 4);
    tbl_SerializeFromObject_TD_18137679_input.addCol("c_first_shipto_date_sk", 4);
    tbl_SerializeFromObject_TD_18137679_input.addCol("c_first_sales_date_sk", 4);
    tbl_SerializeFromObject_TD_18137679_input.allocateHost();
    tbl_SerializeFromObject_TD_18137679_input.loadHost();
    Table tbl_JOIN_INNER_TD_18378634_output("tbl_JOIN_INNER_TD_18378634_output", 6100000, 11, "");
    tbl_JOIN_INNER_TD_18378634_output.allocateHost();
    Table tbl_Filter_TD_18157257_output("tbl_Filter_TD_18157257_output", 6100000, 3, "");
    tbl_Filter_TD_18157257_output.allocateHost();
    Table tbl_SerializeFromObject_TD_18797728_input;
    tbl_SerializeFromObject_TD_18797728_input = Table("customer", customer_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_18797728_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_18797728_input.addCol("c_current_cdemo_sk", 4);
    tbl_SerializeFromObject_TD_18797728_input.addCol("c_current_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_18797728_input.addCol("c_current_addr_sk", 4);
    tbl_SerializeFromObject_TD_18797728_input.addCol("c_first_shipto_date_sk", 4);
    tbl_SerializeFromObject_TD_18797728_input.addCol("c_first_sales_date_sk", 4);
    tbl_SerializeFromObject_TD_18797728_input.allocateHost();
    tbl_SerializeFromObject_TD_18797728_input.loadHost();
    Table tbl_JOIN_INNER_TD_19871408_output("tbl_JOIN_INNER_TD_19871408_output", 6100000, 11, "");
    tbl_JOIN_INNER_TD_19871408_output.allocateHost();
    Table tbl_Filter_TD_19514965_output("tbl_Filter_TD_19514965_output", 6100000, 2, "");
    tbl_Filter_TD_19514965_output.allocateHost();
    Table tbl_SerializeFromObject_TD_19986180_input;
    tbl_SerializeFromObject_TD_19986180_input = Table("store", store_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_19986180_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_19986180_input.addCol("s_store_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_19986180_input.addCol("s_zip", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_19986180_input.allocateHost();
    tbl_SerializeFromObject_TD_19986180_input.loadHost();
    Table tbl_JOIN_INNER_TD_19390320_output("tbl_JOIN_INNER_TD_19390320_output", 6100000, 11, "");
    tbl_JOIN_INNER_TD_19390320_output.allocateHost();
    Table tbl_Filter_TD_19132336_output("tbl_Filter_TD_19132336_output", 6100000, 2, "");
    tbl_Filter_TD_19132336_output.allocateHost();
    Table tbl_SerializeFromObject_TD_19226242_input;
    tbl_SerializeFromObject_TD_19226242_input = Table("store", store_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_19226242_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_19226242_input.addCol("s_store_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_19226242_input.addCol("s_zip", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_19226242_input.allocateHost();
    tbl_SerializeFromObject_TD_19226242_input.loadHost();
    Table tbl_JOIN_INNER_TD_2032998_output("tbl_JOIN_INNER_TD_2032998_output", 6100000, 11, "");
    tbl_JOIN_INNER_TD_2032998_output.allocateHost();
    Table tbl_Filter_TD_20877354_output("tbl_Filter_TD_20877354_output", 6100000, 1, "");
    tbl_Filter_TD_20877354_output.allocateHost();
    Table tbl_SerializeFromObject_TD_20256349_input;
    tbl_SerializeFromObject_TD_20256349_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_20256349_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_20256349_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_20256349_input.allocateHost();
    tbl_SerializeFromObject_TD_20256349_input.loadHost();
    Table tbl_JOIN_INNER_TD_20362010_output("tbl_JOIN_INNER_TD_20362010_output", 6100000, 11, "");
    tbl_JOIN_INNER_TD_20362010_output.allocateHost();
    Table tbl_Filter_TD_20489126_output("tbl_Filter_TD_20489126_output", 6100000, 1, "");
    tbl_Filter_TD_20489126_output.allocateHost();
    Table tbl_SerializeFromObject_TD_2011150_input;
    tbl_SerializeFromObject_TD_2011150_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_2011150_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_2011150_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_2011150_input.allocateHost();
    tbl_SerializeFromObject_TD_2011150_input.loadHost();
    Table tbl_Filter_TD_21713546_output("tbl_Filter_TD_21713546_output", 6100000, 12, "");
    tbl_Filter_TD_21713546_output.allocateHost();
    Table tbl_Filter_TD_21797575_output("tbl_Filter_TD_21797575_output", 6100000, 2, "");
    tbl_Filter_TD_21797575_output.allocateHost();
    Table tbl_Aggregate_TD_2133729_output_preprocess("tbl_Aggregate_TD_2133729_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_2133729_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_2133729_output("tbl_Aggregate_TD_2133729_output", 6100000, 3, "");
    tbl_Aggregate_TD_2133729_output.allocateHost();
    Table tbl_Filter_TD_21248971_output("tbl_Filter_TD_21248971_output", 6100000, 12, "");
    tbl_Filter_TD_21248971_output.allocateHost();
    Table tbl_Filter_TD_21831586_output("tbl_Filter_TD_21831586_output", 6100000, 2, "");
    tbl_Filter_TD_21831586_output.allocateHost();
    Table tbl_Aggregate_TD_21170493_output_preprocess("tbl_Aggregate_TD_21170493_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_21170493_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_21170493_output("tbl_Aggregate_TD_21170493_output", 6100000, 3, "");
    tbl_Aggregate_TD_21170493_output.allocateHost();
    Table tbl_SerializeFromObject_TD_22959783_input;
    tbl_SerializeFromObject_TD_22959783_input = Table("store_sales", store_sales_n, 12, in_dir, "orc");
    tbl_SerializeFromObject_TD_22959783_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_22959783_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_22959783_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_22959783_input.addCol("ss_cdemo_sk", 4);
    tbl_SerializeFromObject_TD_22959783_input.addCol("ss_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_22959783_input.addCol("ss_addr_sk", 4);
    tbl_SerializeFromObject_TD_22959783_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_22959783_input.addCol("ss_promo_sk", 4);
    tbl_SerializeFromObject_TD_22959783_input.addCol("ss_ticket_number", 8);
    tbl_SerializeFromObject_TD_22959783_input.addCol("ss_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_22959783_input.addCol("ss_list_price", 4);
    tbl_SerializeFromObject_TD_22959783_input.addCol("ss_coupon_amt", 4);
    tbl_SerializeFromObject_TD_22959783_input.allocateHost();
    tbl_SerializeFromObject_TD_22959783_input.loadHost();
    Table tbl_SerializeFromObject_TD_22773205_input;
    tbl_SerializeFromObject_TD_22773205_input = Table("store_returns", store_returns_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_22773205_input.addCol("sr_item_sk", 4);
    tbl_SerializeFromObject_TD_22773205_input.addCol("sr_ticket_number", 8);
    tbl_SerializeFromObject_TD_22773205_input.allocateHost();
    tbl_SerializeFromObject_TD_22773205_input.loadHost();
    Table tbl_JOIN_INNER_TD_22931170_output_preprocess("tbl_JOIN_INNER_TD_22931170_output_preprocess", 6100000, 5, "");
    tbl_JOIN_INNER_TD_22931170_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_22931170_output("tbl_JOIN_INNER_TD_22931170_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_22931170_output.allocateHost();
    Table tbl_SerializeFromObject_TD_22217702_input;
    tbl_SerializeFromObject_TD_22217702_input = Table("store_sales", store_sales_n, 12, in_dir, "orc");
    tbl_SerializeFromObject_TD_22217702_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_22217702_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_22217702_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_22217702_input.addCol("ss_cdemo_sk", 4);
    tbl_SerializeFromObject_TD_22217702_input.addCol("ss_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_22217702_input.addCol("ss_addr_sk", 4);
    tbl_SerializeFromObject_TD_22217702_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_22217702_input.addCol("ss_promo_sk", 4);
    tbl_SerializeFromObject_TD_22217702_input.addCol("ss_ticket_number", 8);
    tbl_SerializeFromObject_TD_22217702_input.addCol("ss_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_22217702_input.addCol("ss_list_price", 4);
    tbl_SerializeFromObject_TD_22217702_input.addCol("ss_coupon_amt", 4);
    tbl_SerializeFromObject_TD_22217702_input.allocateHost();
    tbl_SerializeFromObject_TD_22217702_input.loadHost();
    Table tbl_SerializeFromObject_TD_22126571_input;
    tbl_SerializeFromObject_TD_22126571_input = Table("store_returns", store_returns_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_22126571_input.addCol("sr_item_sk", 4);
    tbl_SerializeFromObject_TD_22126571_input.addCol("sr_ticket_number", 8);
    tbl_SerializeFromObject_TD_22126571_input.allocateHost();
    tbl_SerializeFromObject_TD_22126571_input.loadHost();
    Table tbl_JOIN_INNER_TD_22819382_output_preprocess("tbl_JOIN_INNER_TD_22819382_output_preprocess", 6100000, 5, "");
    tbl_JOIN_INNER_TD_22819382_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_22819382_output("tbl_JOIN_INNER_TD_22819382_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_22819382_output.allocateHost();
    Table tbl_Filter_TD_23520356_output("tbl_Filter_TD_23520356_output", 6100000, 3, "");
    tbl_Filter_TD_23520356_output.allocateHost();
    Table tbl_Filter_TD_23493262_output("tbl_Filter_TD_23493262_output", 6100000, 5, "");
    tbl_Filter_TD_23493262_output.allocateHost();
    Table tbl_Filter_TD_23478920_output("tbl_Filter_TD_23478920_output", 6100000, 3, "");
    tbl_Filter_TD_23478920_output.allocateHost();
    Table tbl_Filter_TD_23711028_output("tbl_Filter_TD_23711028_output", 6100000, 5, "");
    tbl_Filter_TD_23711028_output.allocateHost();
    Table tbl_SerializeFromObject_TD_24709735_input;
    tbl_SerializeFromObject_TD_24709735_input = Table("catalog_sales", catalog_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_24709735_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_24709735_input.addCol("cs_order_number", 8);
    tbl_SerializeFromObject_TD_24709735_input.addCol("cs_ext_list_price", 4);
    tbl_SerializeFromObject_TD_24709735_input.allocateHost();
    tbl_SerializeFromObject_TD_24709735_input.loadHost();
    Table tbl_SerializeFromObject_TD_24454546_input;
    tbl_SerializeFromObject_TD_24454546_input = Table("catalog_returns", catalog_returns_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_24454546_input.addCol("cr_item_sk", 4);
    tbl_SerializeFromObject_TD_24454546_input.addCol("cr_order_number", 8);
    tbl_SerializeFromObject_TD_24454546_input.addCol("cr_refunded_cash", 4);
    tbl_SerializeFromObject_TD_24454546_input.addCol("cr_reversed_charge", 4);
    tbl_SerializeFromObject_TD_24454546_input.addCol("cr_store_credit", 4);
    tbl_SerializeFromObject_TD_24454546_input.allocateHost();
    tbl_SerializeFromObject_TD_24454546_input.loadHost();
    Table tbl_SerializeFromObject_TD_24104912_input;
    tbl_SerializeFromObject_TD_24104912_input = Table("catalog_sales", catalog_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_24104912_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_24104912_input.addCol("cs_order_number", 8);
    tbl_SerializeFromObject_TD_24104912_input.addCol("cs_ext_list_price", 4);
    tbl_SerializeFromObject_TD_24104912_input.allocateHost();
    tbl_SerializeFromObject_TD_24104912_input.loadHost();
    Table tbl_SerializeFromObject_TD_24761971_input;
    tbl_SerializeFromObject_TD_24761971_input = Table("catalog_returns", catalog_returns_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_24761971_input.addCol("cr_item_sk", 4);
    tbl_SerializeFromObject_TD_24761971_input.addCol("cr_order_number", 8);
    tbl_SerializeFromObject_TD_24761971_input.addCol("cr_refunded_cash", 4);
    tbl_SerializeFromObject_TD_24761971_input.addCol("cr_reversed_charge", 4);
    tbl_SerializeFromObject_TD_24761971_input.addCol("cr_store_credit", 4);
    tbl_SerializeFromObject_TD_24761971_input.allocateHost();
    tbl_SerializeFromObject_TD_24761971_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_22931170_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_2133729_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_JOIN_INNER_TD_22819382_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_21170493_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_JOIN_INNER_TD_22931170_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_22819382_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_23520356_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_23493262_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_23478920_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_23711028_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    AggrCfgCmd cfg_Aggregate_TD_2133729_cmds;
    cfg_Aggregate_TD_2133729_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_2133729_gqe_aggr(cfg_Aggregate_TD_2133729_cmds.cmd);
    cfg_Aggregate_TD_2133729_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_2133729_cmds_out;
    cfg_Aggregate_TD_2133729_cmds_out.allocateHost();
    cfg_Aggregate_TD_2133729_cmds_out.allocateDevBuffer(context_a, 33);
    AggrCfgCmd cfg_Aggregate_TD_21170493_cmds;
    cfg_Aggregate_TD_21170493_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_21170493_gqe_aggr(cfg_Aggregate_TD_21170493_cmds.cmd);
    cfg_Aggregate_TD_21170493_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_21170493_cmds_out;
    cfg_Aggregate_TD_21170493_cmds_out.allocateHost();
    cfg_Aggregate_TD_21170493_cmds_out.allocateDevBuffer(context_a, 33);
    cfgCmd cfg_JOIN_INNER_TD_22931170_cmds;
    cfg_JOIN_INNER_TD_22931170_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_22931170_gqe_join (cfg_JOIN_INNER_TD_22931170_cmds.cmd);
    cfg_JOIN_INNER_TD_22931170_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_22819382_cmds;
    cfg_JOIN_INNER_TD_22819382_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_22819382_gqe_join (cfg_JOIN_INNER_TD_22819382_cmds.cmd);
    cfg_JOIN_INNER_TD_22819382_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    AggrBufferTmp buftmp_a(context_a); 
    buftmp_a.BufferInitial(q_a); 
    std::cout << std::endl; 
    AggrKrnlEngine krnl_Aggregate_TD_2133729;
    krnl_Aggregate_TD_2133729 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_2133729.setup(tbl_JOIN_INNER_TD_22931170_output, tbl_Aggregate_TD_2133729_output_preprocess, cfg_Aggregate_TD_2133729_cmds, cfg_Aggregate_TD_2133729_cmds_out, buftmp_a);
    AggrKrnlEngine krnl_Aggregate_TD_21170493;
    krnl_Aggregate_TD_21170493 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_21170493.setup(tbl_JOIN_INNER_TD_22819382_output, tbl_Aggregate_TD_21170493_output_preprocess, cfg_Aggregate_TD_21170493_cmds, cfg_Aggregate_TD_21170493_cmds_out, buftmp_a);
    krnlEngine krnl_JOIN_INNER_TD_22931170;
    krnl_JOIN_INNER_TD_22931170 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_22931170.setup(tbl_Filter_TD_23520356_output, tbl_Filter_TD_23493262_output, tbl_JOIN_INNER_TD_22931170_output_preprocess, cfg_JOIN_INNER_TD_22931170_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_22819382;
    krnl_JOIN_INNER_TD_22819382 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_22819382.setup(tbl_Filter_TD_23478920_output, tbl_Filter_TD_23711028_output, tbl_JOIN_INNER_TD_22819382_output_preprocess, cfg_JOIN_INNER_TD_22819382_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_Aggregate_TD_2133729;
    trans_Aggregate_TD_2133729.setq(q_a);
    trans_Aggregate_TD_2133729.add(&(cfg_Aggregate_TD_2133729_cmds));
    transEngine trans_Aggregate_TD_2133729_out;
    trans_Aggregate_TD_2133729_out.setq(q_a);
    q_a.finish();
    transEngine trans_Aggregate_TD_21170493;
    trans_Aggregate_TD_21170493.setq(q_a);
    trans_Aggregate_TD_21170493.add(&(cfg_Aggregate_TD_21170493_cmds));
    transEngine trans_Aggregate_TD_21170493_out;
    trans_Aggregate_TD_21170493_out.setq(q_a);
    q_a.finish();
    transEngine trans_JOIN_INNER_TD_22931170;
    trans_JOIN_INNER_TD_22931170.setq(q_h);
    trans_JOIN_INNER_TD_22931170.add(&(cfg_JOIN_INNER_TD_22931170_cmds));
    transEngine trans_JOIN_INNER_TD_22931170_out;
    trans_JOIN_INNER_TD_22931170_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_22819382;
    trans_JOIN_INNER_TD_22819382.setq(q_h);
    trans_JOIN_INNER_TD_22819382.add(&(cfg_JOIN_INNER_TD_22819382_cmds));
    transEngine trans_JOIN_INNER_TD_22819382_out;
    trans_JOIN_INNER_TD_22819382_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_2133729;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_2133729;
    std::vector<cl::Event> events_Aggregate_TD_2133729;
    events_h2d_wr_Aggregate_TD_2133729.resize(1);
    events_d2h_rd_Aggregate_TD_2133729.resize(1);
    events_Aggregate_TD_2133729.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_2133729;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_2133729;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_21170493;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_21170493;
    std::vector<cl::Event> events_Aggregate_TD_21170493;
    events_h2d_wr_Aggregate_TD_21170493.resize(1);
    events_d2h_rd_Aggregate_TD_21170493.resize(1);
    events_Aggregate_TD_21170493.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_21170493;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_21170493;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_22931170;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_22931170;
    std::vector<cl::Event> events_JOIN_INNER_TD_22931170;
    events_h2d_wr_JOIN_INNER_TD_22931170.resize(1);
    events_d2h_rd_JOIN_INNER_TD_22931170.resize(1);
    events_JOIN_INNER_TD_22931170.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_22931170;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_22931170;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_22819382;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_22819382;
    std::vector<cl::Event> events_JOIN_INNER_TD_22819382;
    events_h2d_wr_JOIN_INNER_TD_22819382.resize(1);
    events_d2h_rd_JOIN_INNER_TD_22819382.resize(1);
    events_JOIN_INNER_TD_22819382.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_22819382;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_22819382;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_23_444181_s, tv_r_Filter_23_444181_e;
    gettimeofday(&tv_r_Filter_23_444181_s, 0);
    SW_Filter_TD_23711028(tbl_SerializeFromObject_TD_24761971_input, tbl_Filter_TD_23711028_output);
    gettimeofday(&tv_r_Filter_23_444181_e, 0);

    struct timeval tv_r_Filter_23_361901_s, tv_r_Filter_23_361901_e;
    gettimeofday(&tv_r_Filter_23_361901_s, 0);
    SW_Filter_TD_23478920(tbl_SerializeFromObject_TD_24104912_input, tbl_Filter_TD_23478920_output);
    gettimeofday(&tv_r_Filter_23_361901_e, 0);

    struct timeval tv_r_Filter_23_320832_s, tv_r_Filter_23_320832_e;
    gettimeofday(&tv_r_Filter_23_320832_s, 0);
    SW_Filter_TD_23493262(tbl_SerializeFromObject_TD_24454546_input, tbl_Filter_TD_23493262_output);
    gettimeofday(&tv_r_Filter_23_320832_e, 0);

    struct timeval tv_r_Filter_23_817111_s, tv_r_Filter_23_817111_e;
    gettimeofday(&tv_r_Filter_23_817111_s, 0);
    SW_Filter_TD_23520356(tbl_SerializeFromObject_TD_24709735_input, tbl_Filter_TD_23520356_output);
    gettimeofday(&tv_r_Filter_23_817111_e, 0);

    struct timeval tv_r_JOIN_INNER_22_204127_s, tv_r_JOIN_INNER_22_204127_e;
    gettimeofday(&tv_r_JOIN_INNER_22_204127_s, 0);
    trans_JOIN_INNER_TD_22819382.add(&(tbl_Filter_TD_23478920_output));
    trans_JOIN_INNER_TD_22819382.add(&(tbl_Filter_TD_23711028_output));
    trans_JOIN_INNER_TD_22819382.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_22819382), &(events_h2d_wr_JOIN_INNER_TD_22819382[0]));
    events_grp_JOIN_INNER_TD_22819382.push_back(events_h2d_wr_JOIN_INNER_TD_22819382[0]);
    krnl_JOIN_INNER_TD_22819382.run(0, &(events_grp_JOIN_INNER_TD_22819382), &(events_JOIN_INNER_TD_22819382[0]));
    
    trans_JOIN_INNER_TD_22819382_out.add(&(tbl_JOIN_INNER_TD_22819382_output_preprocess));
    trans_JOIN_INNER_TD_22819382_out.dev2host(0, &(events_JOIN_INNER_TD_22819382), &(events_d2h_rd_JOIN_INNER_TD_22819382[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_22819382);
    tbl_JOIN_INNER_TD_22819382_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_22819382_output));
    gettimeofday(&tv_r_JOIN_INNER_22_204127_e, 0);

    struct timeval tv_r_JOIN_INNER_22_307596_s, tv_r_JOIN_INNER_22_307596_e;
    gettimeofday(&tv_r_JOIN_INNER_22_307596_s, 0);
    trans_JOIN_INNER_TD_22931170.add(&(tbl_Filter_TD_23520356_output));
    trans_JOIN_INNER_TD_22931170.add(&(tbl_Filter_TD_23493262_output));
    trans_JOIN_INNER_TD_22931170.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_22931170), &(events_h2d_wr_JOIN_INNER_TD_22931170[0]));
    events_grp_JOIN_INNER_TD_22931170.push_back(events_h2d_wr_JOIN_INNER_TD_22931170[0]);
    krnl_JOIN_INNER_TD_22931170.run(0, &(events_grp_JOIN_INNER_TD_22931170), &(events_JOIN_INNER_TD_22931170[0]));
    
    trans_JOIN_INNER_TD_22931170_out.add(&(tbl_JOIN_INNER_TD_22931170_output_preprocess));
    trans_JOIN_INNER_TD_22931170_out.dev2host(0, &(events_JOIN_INNER_TD_22931170), &(events_d2h_rd_JOIN_INNER_TD_22931170[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_22931170);
    tbl_JOIN_INNER_TD_22931170_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_22931170_output));
    gettimeofday(&tv_r_JOIN_INNER_22_307596_e, 0);

    struct timeval tv_r_Aggregate_21_530090_s, tv_r_Aggregate_21_530090_e;
    gettimeofday(&tv_r_Aggregate_21_530090_s, 0);
    trans_Aggregate_TD_21170493.add(&(tbl_JOIN_INNER_TD_22819382_output));
    trans_Aggregate_TD_21170493.host2dev(0, &(prev_events_grp_Aggregate_TD_21170493), &(events_h2d_wr_Aggregate_TD_21170493[0]));
    events_grp_Aggregate_TD_21170493.push_back(events_h2d_wr_Aggregate_TD_21170493[0]);
    krnl_Aggregate_TD_21170493.run(0, &(events_grp_Aggregate_TD_21170493), &(events_Aggregate_TD_21170493[0]));
    
    trans_Aggregate_TD_21170493_out.add(&(tbl_Aggregate_TD_21170493_output_preprocess));
    trans_Aggregate_TD_21170493_out.dev2host(0, &(events_Aggregate_TD_21170493), &(events_d2h_rd_Aggregate_TD_21170493[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_21170493_consolidate(tbl_Aggregate_TD_21170493_output_preprocess, tbl_Aggregate_TD_21170493_output);
    gettimeofday(&tv_r_Aggregate_21_530090_e, 0);

    struct timeval tv_r_Filter_21_337520_s, tv_r_Filter_21_337520_e;
    gettimeofday(&tv_r_Filter_21_337520_s, 0);
    SW_Filter_TD_21831586(tbl_SerializeFromObject_TD_22126571_input, tbl_Filter_TD_21831586_output);
    gettimeofday(&tv_r_Filter_21_337520_e, 0);

    struct timeval tv_r_Filter_21_306453_s, tv_r_Filter_21_306453_e;
    gettimeofday(&tv_r_Filter_21_306453_s, 0);
    SW_Filter_TD_21248971(tbl_SerializeFromObject_TD_22217702_input, tbl_Filter_TD_21248971_output);
    gettimeofday(&tv_r_Filter_21_306453_e, 0);

    struct timeval tv_r_Aggregate_21_271062_s, tv_r_Aggregate_21_271062_e;
    gettimeofday(&tv_r_Aggregate_21_271062_s, 0);
    trans_Aggregate_TD_2133729.add(&(tbl_JOIN_INNER_TD_22931170_output));
    trans_Aggregate_TD_2133729.host2dev(0, &(prev_events_grp_Aggregate_TD_2133729), &(events_h2d_wr_Aggregate_TD_2133729[0]));
    events_grp_Aggregate_TD_2133729.push_back(events_h2d_wr_Aggregate_TD_2133729[0]);
    krnl_Aggregate_TD_2133729.run(0, &(events_grp_Aggregate_TD_2133729), &(events_Aggregate_TD_2133729[0]));
    
    trans_Aggregate_TD_2133729_out.add(&(tbl_Aggregate_TD_2133729_output_preprocess));
    trans_Aggregate_TD_2133729_out.dev2host(0, &(events_Aggregate_TD_2133729), &(events_d2h_rd_Aggregate_TD_2133729[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_2133729_consolidate(tbl_Aggregate_TD_2133729_output_preprocess, tbl_Aggregate_TD_2133729_output);
    gettimeofday(&tv_r_Aggregate_21_271062_e, 0);

    struct timeval tv_r_Filter_21_941336_s, tv_r_Filter_21_941336_e;
    gettimeofday(&tv_r_Filter_21_941336_s, 0);
    SW_Filter_TD_21797575(tbl_SerializeFromObject_TD_22773205_input, tbl_Filter_TD_21797575_output);
    gettimeofday(&tv_r_Filter_21_941336_e, 0);

    struct timeval tv_r_Filter_21_395380_s, tv_r_Filter_21_395380_e;
    gettimeofday(&tv_r_Filter_21_395380_s, 0);
    SW_Filter_TD_21713546(tbl_SerializeFromObject_TD_22959783_input, tbl_Filter_TD_21713546_output);
    gettimeofday(&tv_r_Filter_21_395380_e, 0);

    struct timeval tv_r_Filter_20_192519_s, tv_r_Filter_20_192519_e;
    gettimeofday(&tv_r_Filter_20_192519_s, 0);
    SW_Filter_TD_20489126(tbl_Aggregate_TD_21170493_output, tbl_Filter_TD_20489126_output);
    gettimeofday(&tv_r_Filter_20_192519_e, 0);

    struct timeval tv_r_JOIN_INNER_20_527813_s, tv_r_JOIN_INNER_20_527813_e;
    gettimeofday(&tv_r_JOIN_INNER_20_527813_s, 0);
    SW_JOIN_INNER_TD_20362010(tbl_Filter_TD_21248971_output, tbl_Filter_TD_21831586_output, tbl_JOIN_INNER_TD_20362010_output);
    gettimeofday(&tv_r_JOIN_INNER_20_527813_e, 0);

    struct timeval tv_r_Filter_20_705554_s, tv_r_Filter_20_705554_e;
    gettimeofday(&tv_r_Filter_20_705554_s, 0);
    SW_Filter_TD_20877354(tbl_Aggregate_TD_2133729_output, tbl_Filter_TD_20877354_output);
    gettimeofday(&tv_r_Filter_20_705554_e, 0);

    struct timeval tv_r_JOIN_INNER_20_342446_s, tv_r_JOIN_INNER_20_342446_e;
    gettimeofday(&tv_r_JOIN_INNER_20_342446_s, 0);
    SW_JOIN_INNER_TD_2032998(tbl_Filter_TD_21713546_output, tbl_Filter_TD_21797575_output, tbl_JOIN_INNER_TD_2032998_output);
    gettimeofday(&tv_r_JOIN_INNER_20_342446_e, 0);

    struct timeval tv_r_Filter_19_631784_s, tv_r_Filter_19_631784_e;
    gettimeofday(&tv_r_Filter_19_631784_s, 0);
    SW_Filter_TD_19132336(tbl_SerializeFromObject_TD_2011150_input, tbl_Filter_TD_19132336_output);
    gettimeofday(&tv_r_Filter_19_631784_e, 0);

    struct timeval tv_r_JOIN_INNER_19_281484_s, tv_r_JOIN_INNER_19_281484_e;
    gettimeofday(&tv_r_JOIN_INNER_19_281484_s, 0);
    SW_JOIN_INNER_TD_19390320(tbl_JOIN_INNER_TD_20362010_output, tbl_Filter_TD_20489126_output, tbl_JOIN_INNER_TD_19390320_output);
    gettimeofday(&tv_r_JOIN_INNER_19_281484_e, 0);

    struct timeval tv_r_Filter_19_155842_s, tv_r_Filter_19_155842_e;
    gettimeofday(&tv_r_Filter_19_155842_s, 0);
    SW_Filter_TD_19514965(tbl_SerializeFromObject_TD_20256349_input, tbl_Filter_TD_19514965_output);
    gettimeofday(&tv_r_Filter_19_155842_e, 0);

    struct timeval tv_r_JOIN_INNER_19_430108_s, tv_r_JOIN_INNER_19_430108_e;
    gettimeofday(&tv_r_JOIN_INNER_19_430108_s, 0);
    SW_JOIN_INNER_TD_19871408(tbl_JOIN_INNER_TD_2032998_output, tbl_Filter_TD_20877354_output, tbl_JOIN_INNER_TD_19871408_output);
    gettimeofday(&tv_r_JOIN_INNER_19_430108_e, 0);

    struct timeval tv_r_Filter_18_650007_s, tv_r_Filter_18_650007_e;
    gettimeofday(&tv_r_Filter_18_650007_s, 0);
    SW_Filter_TD_18157257(tbl_SerializeFromObject_TD_19226242_input, tbl_Filter_TD_18157257_output);
    gettimeofday(&tv_r_Filter_18_650007_e, 0);

    struct timeval tv_r_JOIN_INNER_18_547063_s, tv_r_JOIN_INNER_18_547063_e;
    gettimeofday(&tv_r_JOIN_INNER_18_547063_s, 0);
    SW_JOIN_INNER_TD_18378634(tbl_JOIN_INNER_TD_19390320_output, tbl_Filter_TD_19132336_output, tbl_JOIN_INNER_TD_18378634_output);
    gettimeofday(&tv_r_JOIN_INNER_18_547063_e, 0);

    struct timeval tv_r_Filter_18_221256_s, tv_r_Filter_18_221256_e;
    gettimeofday(&tv_r_Filter_18_221256_s, 0);
    SW_Filter_TD_18921231(tbl_SerializeFromObject_TD_19986180_input, tbl_Filter_TD_18921231_output);
    gettimeofday(&tv_r_Filter_18_221256_e, 0);

    struct timeval tv_r_JOIN_INNER_18_326491_s, tv_r_JOIN_INNER_18_326491_e;
    gettimeofday(&tv_r_JOIN_INNER_18_326491_s, 0);
    SW_JOIN_INNER_TD_18402844(tbl_JOIN_INNER_TD_19871408_output, tbl_Filter_TD_19514965_output, tbl_JOIN_INNER_TD_18402844_output);
    gettimeofday(&tv_r_JOIN_INNER_18_326491_e, 0);

    struct timeval tv_r_Filter_17_320825_s, tv_r_Filter_17_320825_e;
    gettimeofday(&tv_r_Filter_17_320825_s, 0);
    SW_Filter_TD_17952307(tbl_SerializeFromObject_TD_18797728_input, tbl_Filter_TD_17952307_output);
    gettimeofday(&tv_r_Filter_17_320825_e, 0);

    struct timeval tv_r_JOIN_INNER_17_582752_s, tv_r_JOIN_INNER_17_582752_e;
    gettimeofday(&tv_r_JOIN_INNER_17_582752_s, 0);
    SW_JOIN_INNER_TD_17330885(tbl_JOIN_INNER_TD_18378634_output, tbl_Filter_TD_18157257_output, tbl_JOIN_INNER_TD_17330885_output);
    gettimeofday(&tv_r_JOIN_INNER_17_582752_e, 0);

    struct timeval tv_r_Filter_17_813417_s, tv_r_Filter_17_813417_e;
    gettimeofday(&tv_r_Filter_17_813417_s, 0);
    SW_Filter_TD_17180494(tbl_SerializeFromObject_TD_18137679_input, tbl_Filter_TD_17180494_output);
    gettimeofday(&tv_r_Filter_17_813417_e, 0);

    struct timeval tv_r_JOIN_INNER_17_287408_s, tv_r_JOIN_INNER_17_287408_e;
    gettimeofday(&tv_r_JOIN_INNER_17_287408_s, 0);
    SW_JOIN_INNER_TD_17102777(tbl_JOIN_INNER_TD_18402844_output, tbl_Filter_TD_18921231_output, tbl_JOIN_INNER_TD_17102777_output);
    gettimeofday(&tv_r_JOIN_INNER_17_287408_e, 0);

    struct timeval tv_r_Filter_16_67393_s, tv_r_Filter_16_67393_e;
    gettimeofday(&tv_r_Filter_16_67393_s, 0);
    SW_Filter_TD_16382357(tbl_SerializeFromObject_TD_17244473_input, tbl_Filter_TD_16382357_output);
    gettimeofday(&tv_r_Filter_16_67393_e, 0);

    struct timeval tv_r_JOIN_INNER_16_668747_s, tv_r_JOIN_INNER_16_668747_e;
    gettimeofday(&tv_r_JOIN_INNER_16_668747_s, 0);
    SW_JOIN_INNER_TD_16134853(tbl_JOIN_INNER_TD_17330885_output, tbl_Filter_TD_17952307_output, tbl_JOIN_INNER_TD_16134853_output);
    gettimeofday(&tv_r_JOIN_INNER_16_668747_e, 0);

    struct timeval tv_r_Filter_16_346535_s, tv_r_Filter_16_346535_e;
    gettimeofday(&tv_r_Filter_16_346535_s, 0);
    SW_Filter_TD_16426838(tbl_SerializeFromObject_TD_1799058_input, tbl_Filter_TD_16426838_output);
    gettimeofday(&tv_r_Filter_16_346535_e, 0);

    struct timeval tv_r_JOIN_INNER_16_740597_s, tv_r_JOIN_INNER_16_740597_e;
    gettimeofday(&tv_r_JOIN_INNER_16_740597_s, 0);
    SW_JOIN_INNER_TD_16633534(tbl_JOIN_INNER_TD_17102777_output, tbl_Filter_TD_17180494_output, tbl_JOIN_INNER_TD_16633534_output);
    gettimeofday(&tv_r_JOIN_INNER_16_740597_e, 0);

    struct timeval tv_r_Filter_15_855249_s, tv_r_Filter_15_855249_e;
    gettimeofday(&tv_r_Filter_15_855249_s, 0);
    SW_Filter_TD_15892114(tbl_SerializeFromObject_TD_16553257_input, tbl_Filter_TD_15892114_output);
    gettimeofday(&tv_r_Filter_15_855249_e, 0);

    struct timeval tv_r_JOIN_INNER_15_752351_s, tv_r_JOIN_INNER_15_752351_e;
    gettimeofday(&tv_r_JOIN_INNER_15_752351_s, 0);
    SW_JOIN_INNER_TD_15257714(tbl_JOIN_INNER_TD_16134853_output, tbl_Filter_TD_16382357_output, tbl_JOIN_INNER_TD_15257714_output);
    gettimeofday(&tv_r_JOIN_INNER_15_752351_e, 0);

    struct timeval tv_r_Filter_15_590187_s, tv_r_Filter_15_590187_e;
    gettimeofday(&tv_r_Filter_15_590187_s, 0);
    SW_Filter_TD_15770298(tbl_SerializeFromObject_TD_1695065_input, tbl_Filter_TD_15770298_output);
    gettimeofday(&tv_r_Filter_15_590187_e, 0);

    struct timeval tv_r_JOIN_INNER_15_795614_s, tv_r_JOIN_INNER_15_795614_e;
    gettimeofday(&tv_r_JOIN_INNER_15_795614_s, 0);
    SW_JOIN_INNER_TD_15907739(tbl_JOIN_INNER_TD_16633534_output, tbl_Filter_TD_16426838_output, tbl_JOIN_INNER_TD_15907739_output);
    gettimeofday(&tv_r_JOIN_INNER_15_795614_e, 0);

    struct timeval tv_r_Filter_14_819834_s, tv_r_Filter_14_819834_e;
    gettimeofday(&tv_r_Filter_14_819834_s, 0);
    SW_Filter_TD_14721747(tbl_SerializeFromObject_TD_15202776_input, tbl_Filter_TD_14721747_output);
    gettimeofday(&tv_r_Filter_14_819834_e, 0);

    struct timeval tv_r_JOIN_INNER_14_820610_s, tv_r_JOIN_INNER_14_820610_e;
    gettimeofday(&tv_r_JOIN_INNER_14_820610_s, 0);
    SW_JOIN_INNER_TD_14747919(tbl_JOIN_INNER_TD_15257714_output, tbl_Filter_TD_15892114_output, tbl_JOIN_INNER_TD_14747919_output);
    gettimeofday(&tv_r_JOIN_INNER_14_820610_e, 0);

    struct timeval tv_r_Filter_14_850335_s, tv_r_Filter_14_850335_e;
    gettimeofday(&tv_r_Filter_14_850335_s, 0);
    SW_Filter_TD_14892724(tbl_SerializeFromObject_TD_15734826_input, tbl_Filter_TD_14892724_output);
    gettimeofday(&tv_r_Filter_14_850335_e, 0);

    struct timeval tv_r_JOIN_INNER_14_352999_s, tv_r_JOIN_INNER_14_352999_e;
    gettimeofday(&tv_r_JOIN_INNER_14_352999_s, 0);
    SW_JOIN_INNER_TD_14267925(tbl_JOIN_INNER_TD_15907739_output, tbl_Filter_TD_15770298_output, tbl_JOIN_INNER_TD_14267925_output);
    gettimeofday(&tv_r_JOIN_INNER_14_352999_e, 0);

    struct timeval tv_r_Filter_13_906272_s, tv_r_Filter_13_906272_e;
    gettimeofday(&tv_r_Filter_13_906272_s, 0);
    SW_Filter_TD_13655875(tbl_SerializeFromObject_TD_14299454_input, tbl_Filter_TD_13655875_output);
    gettimeofday(&tv_r_Filter_13_906272_e, 0);

    struct timeval tv_r_JOIN_INNER_13_310543_s, tv_r_JOIN_INNER_13_310543_e;
    gettimeofday(&tv_r_JOIN_INNER_13_310543_s, 0);
    SW_JOIN_INNER_TD_13369006(tbl_JOIN_INNER_TD_14747919_output, tbl_Filter_TD_14721747_output, tbl_JOIN_INNER_TD_13369006_output);
    gettimeofday(&tv_r_JOIN_INNER_13_310543_e, 0);

    struct timeval tv_r_Filter_13_59096_s, tv_r_Filter_13_59096_e;
    gettimeofday(&tv_r_Filter_13_59096_s, 0);
    SW_Filter_TD_13256744(tbl_SerializeFromObject_TD_14853068_input, tbl_Filter_TD_13256744_output);
    gettimeofday(&tv_r_Filter_13_59096_e, 0);

    struct timeval tv_r_JOIN_INNER_13_757596_s, tv_r_JOIN_INNER_13_757596_e;
    gettimeofday(&tv_r_JOIN_INNER_13_757596_s, 0);
    SW_JOIN_INNER_TD_13600633(tbl_JOIN_INNER_TD_14267925_output, tbl_Filter_TD_14892724_output, tbl_JOIN_INNER_TD_13600633_output);
    gettimeofday(&tv_r_JOIN_INNER_13_757596_e, 0);

    struct timeval tv_r_Filter_12_983033_s, tv_r_Filter_12_983033_e;
    gettimeofday(&tv_r_Filter_12_983033_s, 0);
    SW_Filter_TD_124448(tbl_SerializeFromObject_TD_13452394_input, tbl_Filter_TD_124448_output);
    gettimeofday(&tv_r_Filter_12_983033_e, 0);

    struct timeval tv_r_JOIN_INNER_12_950263_s, tv_r_JOIN_INNER_12_950263_e;
    gettimeofday(&tv_r_JOIN_INNER_12_950263_s, 0);
    SW_JOIN_INNER_TD_12273451(tbl_JOIN_INNER_TD_13369006_output, tbl_Filter_TD_13655875_output, tbl_JOIN_INNER_TD_12273451_output);
    gettimeofday(&tv_r_JOIN_INNER_12_950263_e, 0);

    struct timeval tv_r_Filter_12_54129_s, tv_r_Filter_12_54129_e;
    gettimeofday(&tv_r_Filter_12_54129_s, 0);
    SW_Filter_TD_12174597(tbl_SerializeFromObject_TD_13651411_input, tbl_Filter_TD_12174597_output);
    gettimeofday(&tv_r_Filter_12_54129_e, 0);

    struct timeval tv_r_JOIN_INNER_12_760004_s, tv_r_JOIN_INNER_12_760004_e;
    gettimeofday(&tv_r_JOIN_INNER_12_760004_s, 0);
    SW_JOIN_INNER_TD_12115296(tbl_JOIN_INNER_TD_13600633_output, tbl_Filter_TD_13256744_output, tbl_JOIN_INNER_TD_12115296_output);
    gettimeofday(&tv_r_JOIN_INNER_12_760004_e, 0);

    struct timeval tv_r_Filter_11_434548_s, tv_r_Filter_11_434548_e;
    gettimeofday(&tv_r_Filter_11_434548_s, 0);
    SW_Filter_TD_11557957(tbl_SerializeFromObject_TD_12679417_input, tbl_Filter_TD_11557957_output);
    gettimeofday(&tv_r_Filter_11_434548_e, 0);

    struct timeval tv_r_JOIN_INNER_11_339569_s, tv_r_JOIN_INNER_11_339569_e;
    gettimeofday(&tv_r_JOIN_INNER_11_339569_s, 0);
    SW_JOIN_INNER_TD_11493165(tbl_JOIN_INNER_TD_12273451_output, tbl_Filter_TD_124448_output, tbl_JOIN_INNER_TD_11493165_output);
    gettimeofday(&tv_r_JOIN_INNER_11_339569_e, 0);

    struct timeval tv_r_Filter_11_764595_s, tv_r_Filter_11_764595_e;
    gettimeofday(&tv_r_Filter_11_764595_s, 0);
    SW_Filter_TD_1117050(tbl_SerializeFromObject_TD_12986662_input, tbl_Filter_TD_1117050_output);
    gettimeofday(&tv_r_Filter_11_764595_e, 0);

    struct timeval tv_r_JOIN_INNER_11_273323_s, tv_r_JOIN_INNER_11_273323_e;
    gettimeofday(&tv_r_JOIN_INNER_11_273323_s, 0);
    SW_JOIN_INNER_TD_11526036(tbl_JOIN_INNER_TD_12115296_output, tbl_Filter_TD_12174597_output, tbl_JOIN_INNER_TD_11526036_output);
    gettimeofday(&tv_r_JOIN_INNER_11_273323_e, 0);

    struct timeval tv_r_Filter_10_885430_s, tv_r_Filter_10_885430_e;
    gettimeofday(&tv_r_Filter_10_885430_s, 0);
    SW_Filter_TD_10762193(tbl_SerializeFromObject_TD_11758762_input, tbl_Filter_TD_10762193_output);
    gettimeofday(&tv_r_Filter_10_885430_e, 0);

    struct timeval tv_r_JOIN_INNER_10_598879_s, tv_r_JOIN_INNER_10_598879_e;
    gettimeofday(&tv_r_JOIN_INNER_10_598879_s, 0);
    SW_JOIN_INNER_TD_10951912(tbl_JOIN_INNER_TD_11493165_output, tbl_Filter_TD_11557957_output, tbl_JOIN_INNER_TD_10951912_output);
    gettimeofday(&tv_r_JOIN_INNER_10_598879_e, 0);

    struct timeval tv_r_Filter_10_347312_s, tv_r_Filter_10_347312_e;
    gettimeofday(&tv_r_Filter_10_347312_s, 0);
    SW_Filter_TD_1015392(tbl_SerializeFromObject_TD_11703170_input, tbl_Filter_TD_1015392_output);
    gettimeofday(&tv_r_Filter_10_347312_e, 0);

    struct timeval tv_r_JOIN_INNER_10_598283_s, tv_r_JOIN_INNER_10_598283_e;
    gettimeofday(&tv_r_JOIN_INNER_10_598283_s, 0);
    SW_JOIN_INNER_TD_10446614(tbl_JOIN_INNER_TD_11526036_output, tbl_Filter_TD_1117050_output, tbl_JOIN_INNER_TD_10446614_output);
    gettimeofday(&tv_r_JOIN_INNER_10_598283_e, 0);

    struct timeval tv_r_Filter_9_315519_s, tv_r_Filter_9_315519_e;
    gettimeofday(&tv_r_Filter_9_315519_s, 0);
    SW_Filter_TD_9328766(tbl_SerializeFromObject_TD_10706938_input, tbl_Filter_TD_9328766_output);
    gettimeofday(&tv_r_Filter_9_315519_e, 0);

    struct timeval tv_r_JOIN_INNER_9_189759_s, tv_r_JOIN_INNER_9_189759_e;
    gettimeofday(&tv_r_JOIN_INNER_9_189759_s, 0);
    SW_JOIN_INNER_TD_9425844(tbl_JOIN_INNER_TD_10951912_output, tbl_Filter_TD_10762193_output, tbl_JOIN_INNER_TD_9425844_output);
    gettimeofday(&tv_r_JOIN_INNER_9_189759_e, 0);

    struct timeval tv_r_Filter_9_467951_s, tv_r_Filter_9_467951_e;
    gettimeofday(&tv_r_Filter_9_467951_s, 0);
    SW_Filter_TD_9772283(tbl_SerializeFromObject_TD_1065428_input, tbl_Filter_TD_9772283_output);
    gettimeofday(&tv_r_Filter_9_467951_e, 0);

    struct timeval tv_r_JOIN_INNER_9_741846_s, tv_r_JOIN_INNER_9_741846_e;
    gettimeofday(&tv_r_JOIN_INNER_9_741846_s, 0);
    SW_JOIN_INNER_TD_9678884(tbl_JOIN_INNER_TD_10446614_output, tbl_Filter_TD_1015392_output, tbl_JOIN_INNER_TD_9678884_output);
    gettimeofday(&tv_r_JOIN_INNER_9_741846_e, 0);

    struct timeval tv_r_Filter_8_771883_s, tv_r_Filter_8_771883_e;
    gettimeofday(&tv_r_Filter_8_771883_s, 0);
    SW_Filter_TD_8103123(tbl_SerializeFromObject_TD_9446210_input, tbl_Filter_TD_8103123_output);
    gettimeofday(&tv_r_Filter_8_771883_e, 0);

    struct timeval tv_r_JOIN_INNER_8_583242_s, tv_r_JOIN_INNER_8_583242_e;
    gettimeofday(&tv_r_JOIN_INNER_8_583242_s, 0);
    SW_JOIN_INNER_TD_8966505(tbl_JOIN_INNER_TD_9425844_output, tbl_Filter_TD_9328766_output, tbl_JOIN_INNER_TD_8966505_output);
    gettimeofday(&tv_r_JOIN_INNER_8_583242_e, 0);

    struct timeval tv_r_Filter_8_862209_s, tv_r_Filter_8_862209_e;
    gettimeofday(&tv_r_Filter_8_862209_s, 0);
    SW_Filter_TD_8585812(tbl_SerializeFromObject_TD_9859896_input, tbl_Filter_TD_8585812_output);
    gettimeofday(&tv_r_Filter_8_862209_e, 0);

    struct timeval tv_r_JOIN_INNER_8_926115_s, tv_r_JOIN_INNER_8_926115_e;
    gettimeofday(&tv_r_JOIN_INNER_8_926115_s, 0);
    SW_JOIN_INNER_TD_8755957(tbl_JOIN_INNER_TD_9678884_output, tbl_Filter_TD_9772283_output, tbl_JOIN_INNER_TD_8755957_output);
    gettimeofday(&tv_r_JOIN_INNER_8_926115_e, 0);

    struct timeval tv_r_Filter_7_477461_s, tv_r_Filter_7_477461_e;
    gettimeofday(&tv_r_Filter_7_477461_s, 0);
    SW_Filter_TD_7895840(tbl_SerializeFromObject_TD_8407051_input, tbl_Filter_TD_7895840_output);
    gettimeofday(&tv_r_Filter_7_477461_e, 0);

    struct timeval tv_r_JOIN_INNER_7_543725_s, tv_r_JOIN_INNER_7_543725_e;
    gettimeofday(&tv_r_JOIN_INNER_7_543725_s, 0);
    SW_JOIN_INNER_TD_7719384(tbl_JOIN_INNER_TD_8966505_output, tbl_Filter_TD_8103123_output, tbl_JOIN_INNER_TD_7719384_output);
    gettimeofday(&tv_r_JOIN_INNER_7_543725_e, 0);

    struct timeval tv_r_Filter_7_484722_s, tv_r_Filter_7_484722_e;
    gettimeofday(&tv_r_Filter_7_484722_s, 0);
    SW_Filter_TD_727362(tbl_SerializeFromObject_TD_8344879_input, tbl_Filter_TD_727362_output);
    gettimeofday(&tv_r_Filter_7_484722_e, 0);

    struct timeval tv_r_JOIN_INNER_7_958322_s, tv_r_JOIN_INNER_7_958322_e;
    gettimeofday(&tv_r_JOIN_INNER_7_958322_s, 0);
    SW_JOIN_INNER_TD_74545(tbl_JOIN_INNER_TD_8755957_output, tbl_Filter_TD_8585812_output, tbl_JOIN_INNER_TD_74545_output);
    gettimeofday(&tv_r_JOIN_INNER_7_958322_e, 0);

    struct timeval tv_r_Filter_6_654742_s, tv_r_Filter_6_654742_e;
    gettimeofday(&tv_r_Filter_6_654742_s, 0);
    SW_Filter_TD_6220581(tbl_SerializeFromObject_TD_7880239_input, tbl_Filter_TD_6220581_output);
    gettimeofday(&tv_r_Filter_6_654742_e, 0);

    struct timeval tv_r_JOIN_INNER_6_41697_s, tv_r_JOIN_INNER_6_41697_e;
    gettimeofday(&tv_r_JOIN_INNER_6_41697_s, 0);
    SW_JOIN_INNER_TD_6838150(tbl_JOIN_INNER_TD_7719384_output, tbl_Filter_TD_7895840_output, tbl_JOIN_INNER_TD_6838150_output);
    gettimeofday(&tv_r_JOIN_INNER_6_41697_e, 0);

    struct timeval tv_r_Filter_6_242139_s, tv_r_Filter_6_242139_e;
    gettimeofday(&tv_r_Filter_6_242139_s, 0);
    SW_Filter_TD_6461371(tbl_SerializeFromObject_TD_7194992_input, tbl_Filter_TD_6461371_output);
    gettimeofday(&tv_r_Filter_6_242139_e, 0);

    struct timeval tv_r_JOIN_INNER_6_220509_s, tv_r_JOIN_INNER_6_220509_e;
    gettimeofday(&tv_r_JOIN_INNER_6_220509_s, 0);
    SW_JOIN_INNER_TD_653599(tbl_JOIN_INNER_TD_74545_output, tbl_Filter_TD_727362_output, tbl_JOIN_INNER_TD_653599_output);
    gettimeofday(&tv_r_JOIN_INNER_6_220509_e, 0);

    struct timeval tv_r_Filter_5_243563_s, tv_r_Filter_5_243563_e;
    gettimeofday(&tv_r_Filter_5_243563_s, 0);
    SW_Filter_TD_5514808(tbl_SerializeFromObject_TD_6423713_input, tbl_Filter_TD_5514808_output);
    gettimeofday(&tv_r_Filter_5_243563_e, 0);

    struct timeval tv_r_JOIN_INNER_5_219369_s, tv_r_JOIN_INNER_5_219369_e;
    gettimeofday(&tv_r_JOIN_INNER_5_219369_s, 0);
    SW_JOIN_INNER_TD_5724624(tbl_JOIN_INNER_TD_6838150_output, tbl_Filter_TD_6220581_output, tbl_JOIN_INNER_TD_5724624_output);
    gettimeofday(&tv_r_JOIN_INNER_5_219369_e, 0);

    struct timeval tv_r_Filter_5_308500_s, tv_r_Filter_5_308500_e;
    gettimeofday(&tv_r_Filter_5_308500_s, 0);
    SW_Filter_TD_5748863(tbl_SerializeFromObject_TD_6648753_input, tbl_Filter_TD_5748863_output);
    gettimeofday(&tv_r_Filter_5_308500_e, 0);

    struct timeval tv_r_JOIN_INNER_5_647198_s, tv_r_JOIN_INNER_5_647198_e;
    gettimeofday(&tv_r_JOIN_INNER_5_647198_s, 0);
    SW_JOIN_INNER_TD_5927078(tbl_JOIN_INNER_TD_653599_output, tbl_Filter_TD_6461371_output, tbl_JOIN_INNER_TD_5927078_output);
    gettimeofday(&tv_r_JOIN_INNER_5_647198_e, 0);

    struct timeval tv_r_JOIN_INNER_4_13748_s, tv_r_JOIN_INNER_4_13748_e;
    gettimeofday(&tv_r_JOIN_INNER_4_13748_s, 0);
    SW_JOIN_INNER_TD_4452906(tbl_JOIN_INNER_TD_5724624_output, tbl_Filter_TD_5514808_output, tbl_JOIN_INNER_TD_4452906_output);
    gettimeofday(&tv_r_JOIN_INNER_4_13748_e, 0);

    struct timeval tv_r_JOIN_INNER_4_544103_s, tv_r_JOIN_INNER_4_544103_e;
    gettimeofday(&tv_r_JOIN_INNER_4_544103_s, 0);
    SW_JOIN_INNER_TD_4338385(tbl_JOIN_INNER_TD_5927078_output, tbl_Filter_TD_5748863_output, tbl_JOIN_INNER_TD_4338385_output);
    gettimeofday(&tv_r_JOIN_INNER_4_544103_e, 0);

    struct timeval tv_r_Aggregate_3_113224_s, tv_r_Aggregate_3_113224_e;
    gettimeofday(&tv_r_Aggregate_3_113224_s, 0);
    SW_Aggregate_TD_3248686(tbl_JOIN_INNER_TD_4452906_output, tbl_Aggregate_TD_3248686_output);
    gettimeofday(&tv_r_Aggregate_3_113224_e, 0);

    struct timeval tv_r_Aggregate_3_833655_s, tv_r_Aggregate_3_833655_e;
    gettimeofday(&tv_r_Aggregate_3_833655_s, 0);
    SW_Aggregate_TD_3607278(tbl_JOIN_INNER_TD_4338385_output, tbl_Aggregate_TD_3607278_output);
    gettimeofday(&tv_r_Aggregate_3_833655_e, 0);

    struct timeval tv_r_JOIN_INNER_2_874585_s, tv_r_JOIN_INNER_2_874585_e;
    gettimeofday(&tv_r_JOIN_INNER_2_874585_s, 0);
    SW_JOIN_INNER_TD_2710081(tbl_Aggregate_TD_3607278_output, tbl_Aggregate_TD_3248686_output, tbl_JOIN_INNER_TD_2710081_output);
    gettimeofday(&tv_r_JOIN_INNER_2_874585_e, 0);

    struct timeval tv_r_Project_1_978716_s, tv_r_Project_1_978716_e;
    gettimeofday(&tv_r_Project_1_978716_s, 0);
    SW_Project_TD_1260547(tbl_JOIN_INNER_TD_2710081_output, tbl_Project_TD_1260547_output);
    gettimeofday(&tv_r_Project_1_978716_e, 0);

    struct timeval tv_r_Sort_0_335777_s, tv_r_Sort_0_335777_e;
    gettimeofday(&tv_r_Sort_0_335777_s, 0);
    SW_Sort_TD_0976842(tbl_Project_TD_1260547_output, tbl_Sort_TD_0976842_output);
    gettimeofday(&tv_r_Sort_0_335777_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_23: " << tvdiff(&tv_r_Filter_23_444181_s, &tv_r_Filter_23_444181_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_24761971_input: " << tbl_SerializeFromObject_TD_24761971_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_23: " << tvdiff(&tv_r_Filter_23_361901_s, &tv_r_Filter_23_361901_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_24104912_input: " << tbl_SerializeFromObject_TD_24104912_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_23: " << tvdiff(&tv_r_Filter_23_320832_s, &tv_r_Filter_23_320832_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_24454546_input: " << tbl_SerializeFromObject_TD_24454546_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_23: " << tvdiff(&tv_r_Filter_23_817111_s, &tv_r_Filter_23_817111_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_24709735_input: " << tbl_SerializeFromObject_TD_24709735_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_22: " << tvdiff(&tv_r_JOIN_INNER_22_204127_s, &tv_r_JOIN_INNER_22_204127_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_23478920_output: " << tbl_Filter_TD_23478920_output.getNumRow() << " " << "tbl_Filter_TD_23711028_output: " << tbl_Filter_TD_23711028_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_22: " << tvdiff(&tv_r_JOIN_INNER_22_307596_s, &tv_r_JOIN_INNER_22_307596_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_23520356_output: " << tbl_Filter_TD_23520356_output.getNumRow() << " " << "tbl_Filter_TD_23493262_output: " << tbl_Filter_TD_23493262_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_21: " << tvdiff(&tv_r_Aggregate_21_530090_s, &tv_r_Aggregate_21_530090_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_22819382_output: " << tbl_JOIN_INNER_TD_22819382_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_21: " << tvdiff(&tv_r_Filter_21_337520_s, &tv_r_Filter_21_337520_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_22126571_input: " << tbl_SerializeFromObject_TD_22126571_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_21: " << tvdiff(&tv_r_Filter_21_306453_s, &tv_r_Filter_21_306453_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_22217702_input: " << tbl_SerializeFromObject_TD_22217702_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_21: " << tvdiff(&tv_r_Aggregate_21_271062_s, &tv_r_Aggregate_21_271062_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_22931170_output: " << tbl_JOIN_INNER_TD_22931170_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_21: " << tvdiff(&tv_r_Filter_21_941336_s, &tv_r_Filter_21_941336_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_22773205_input: " << tbl_SerializeFromObject_TD_22773205_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_21: " << tvdiff(&tv_r_Filter_21_395380_s, &tv_r_Filter_21_395380_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_22959783_input: " << tbl_SerializeFromObject_TD_22959783_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_20: " << tvdiff(&tv_r_Filter_20_192519_s, &tv_r_Filter_20_192519_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_21170493_output: " << tbl_Aggregate_TD_21170493_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_20: " << tvdiff(&tv_r_JOIN_INNER_20_527813_s, &tv_r_JOIN_INNER_20_527813_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_21248971_output: " << tbl_Filter_TD_21248971_output.getNumRow() << " " << "tbl_Filter_TD_21831586_output: " << tbl_Filter_TD_21831586_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_20: " << tvdiff(&tv_r_Filter_20_705554_s, &tv_r_Filter_20_705554_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_2133729_output: " << tbl_Aggregate_TD_2133729_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_20: " << tvdiff(&tv_r_JOIN_INNER_20_342446_s, &tv_r_JOIN_INNER_20_342446_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_21713546_output: " << tbl_Filter_TD_21713546_output.getNumRow() << " " << "tbl_Filter_TD_21797575_output: " << tbl_Filter_TD_21797575_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_19: " << tvdiff(&tv_r_Filter_19_631784_s, &tv_r_Filter_19_631784_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_2011150_input: " << tbl_SerializeFromObject_TD_2011150_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_19: " << tvdiff(&tv_r_JOIN_INNER_19_281484_s, &tv_r_JOIN_INNER_19_281484_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_20362010_output: " << tbl_JOIN_INNER_TD_20362010_output.getNumRow() << " " << "tbl_Filter_TD_20489126_output: " << tbl_Filter_TD_20489126_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_19: " << tvdiff(&tv_r_Filter_19_155842_s, &tv_r_Filter_19_155842_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_20256349_input: " << tbl_SerializeFromObject_TD_20256349_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_19: " << tvdiff(&tv_r_JOIN_INNER_19_430108_s, &tv_r_JOIN_INNER_19_430108_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_2032998_output: " << tbl_JOIN_INNER_TD_2032998_output.getNumRow() << " " << "tbl_Filter_TD_20877354_output: " << tbl_Filter_TD_20877354_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_18: " << tvdiff(&tv_r_Filter_18_650007_s, &tv_r_Filter_18_650007_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_19226242_input: " << tbl_SerializeFromObject_TD_19226242_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_18: " << tvdiff(&tv_r_JOIN_INNER_18_547063_s, &tv_r_JOIN_INNER_18_547063_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_19390320_output: " << tbl_JOIN_INNER_TD_19390320_output.getNumRow() << " " << "tbl_Filter_TD_19132336_output: " << tbl_Filter_TD_19132336_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_18: " << tvdiff(&tv_r_Filter_18_221256_s, &tv_r_Filter_18_221256_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_19986180_input: " << tbl_SerializeFromObject_TD_19986180_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_18: " << tvdiff(&tv_r_JOIN_INNER_18_326491_s, &tv_r_JOIN_INNER_18_326491_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_19871408_output: " << tbl_JOIN_INNER_TD_19871408_output.getNumRow() << " " << "tbl_Filter_TD_19514965_output: " << tbl_Filter_TD_19514965_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_17: " << tvdiff(&tv_r_Filter_17_320825_s, &tv_r_Filter_17_320825_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_18797728_input: " << tbl_SerializeFromObject_TD_18797728_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_17: " << tvdiff(&tv_r_JOIN_INNER_17_582752_s, &tv_r_JOIN_INNER_17_582752_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_18378634_output: " << tbl_JOIN_INNER_TD_18378634_output.getNumRow() << " " << "tbl_Filter_TD_18157257_output: " << tbl_Filter_TD_18157257_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_17: " << tvdiff(&tv_r_Filter_17_813417_s, &tv_r_Filter_17_813417_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_18137679_input: " << tbl_SerializeFromObject_TD_18137679_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_17: " << tvdiff(&tv_r_JOIN_INNER_17_287408_s, &tv_r_JOIN_INNER_17_287408_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_18402844_output: " << tbl_JOIN_INNER_TD_18402844_output.getNumRow() << " " << "tbl_Filter_TD_18921231_output: " << tbl_Filter_TD_18921231_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_16: " << tvdiff(&tv_r_Filter_16_67393_s, &tv_r_Filter_16_67393_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_17244473_input: " << tbl_SerializeFromObject_TD_17244473_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_16: " << tvdiff(&tv_r_JOIN_INNER_16_668747_s, &tv_r_JOIN_INNER_16_668747_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_17330885_output: " << tbl_JOIN_INNER_TD_17330885_output.getNumRow() << " " << "tbl_Filter_TD_17952307_output: " << tbl_Filter_TD_17952307_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_16: " << tvdiff(&tv_r_Filter_16_346535_s, &tv_r_Filter_16_346535_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1799058_input: " << tbl_SerializeFromObject_TD_1799058_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_16: " << tvdiff(&tv_r_JOIN_INNER_16_740597_s, &tv_r_JOIN_INNER_16_740597_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_17102777_output: " << tbl_JOIN_INNER_TD_17102777_output.getNumRow() << " " << "tbl_Filter_TD_17180494_output: " << tbl_Filter_TD_17180494_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_15: " << tvdiff(&tv_r_Filter_15_855249_s, &tv_r_Filter_15_855249_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_16553257_input: " << tbl_SerializeFromObject_TD_16553257_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_15: " << tvdiff(&tv_r_JOIN_INNER_15_752351_s, &tv_r_JOIN_INNER_15_752351_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_16134853_output: " << tbl_JOIN_INNER_TD_16134853_output.getNumRow() << " " << "tbl_Filter_TD_16382357_output: " << tbl_Filter_TD_16382357_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_15: " << tvdiff(&tv_r_Filter_15_590187_s, &tv_r_Filter_15_590187_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1695065_input: " << tbl_SerializeFromObject_TD_1695065_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_15: " << tvdiff(&tv_r_JOIN_INNER_15_795614_s, &tv_r_JOIN_INNER_15_795614_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_16633534_output: " << tbl_JOIN_INNER_TD_16633534_output.getNumRow() << " " << "tbl_Filter_TD_16426838_output: " << tbl_Filter_TD_16426838_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_14: " << tvdiff(&tv_r_Filter_14_819834_s, &tv_r_Filter_14_819834_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_15202776_input: " << tbl_SerializeFromObject_TD_15202776_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_14: " << tvdiff(&tv_r_JOIN_INNER_14_820610_s, &tv_r_JOIN_INNER_14_820610_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_15257714_output: " << tbl_JOIN_INNER_TD_15257714_output.getNumRow() << " " << "tbl_Filter_TD_15892114_output: " << tbl_Filter_TD_15892114_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_14: " << tvdiff(&tv_r_Filter_14_850335_s, &tv_r_Filter_14_850335_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_15734826_input: " << tbl_SerializeFromObject_TD_15734826_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_14: " << tvdiff(&tv_r_JOIN_INNER_14_352999_s, &tv_r_JOIN_INNER_14_352999_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_15907739_output: " << tbl_JOIN_INNER_TD_15907739_output.getNumRow() << " " << "tbl_Filter_TD_15770298_output: " << tbl_Filter_TD_15770298_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_13: " << tvdiff(&tv_r_Filter_13_906272_s, &tv_r_Filter_13_906272_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_14299454_input: " << tbl_SerializeFromObject_TD_14299454_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_13: " << tvdiff(&tv_r_JOIN_INNER_13_310543_s, &tv_r_JOIN_INNER_13_310543_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_14747919_output: " << tbl_JOIN_INNER_TD_14747919_output.getNumRow() << " " << "tbl_Filter_TD_14721747_output: " << tbl_Filter_TD_14721747_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_13: " << tvdiff(&tv_r_Filter_13_59096_s, &tv_r_Filter_13_59096_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_14853068_input: " << tbl_SerializeFromObject_TD_14853068_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_13: " << tvdiff(&tv_r_JOIN_INNER_13_757596_s, &tv_r_JOIN_INNER_13_757596_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_14267925_output: " << tbl_JOIN_INNER_TD_14267925_output.getNumRow() << " " << "tbl_Filter_TD_14892724_output: " << tbl_Filter_TD_14892724_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_983033_s, &tv_r_Filter_12_983033_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13452394_input: " << tbl_SerializeFromObject_TD_13452394_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_12: " << tvdiff(&tv_r_JOIN_INNER_12_950263_s, &tv_r_JOIN_INNER_12_950263_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_13369006_output: " << tbl_JOIN_INNER_TD_13369006_output.getNumRow() << " " << "tbl_Filter_TD_13655875_output: " << tbl_Filter_TD_13655875_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_54129_s, &tv_r_Filter_12_54129_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13651411_input: " << tbl_SerializeFromObject_TD_13651411_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_12: " << tvdiff(&tv_r_JOIN_INNER_12_760004_s, &tv_r_JOIN_INNER_12_760004_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_13600633_output: " << tbl_JOIN_INNER_TD_13600633_output.getNumRow() << " " << "tbl_Filter_TD_13256744_output: " << tbl_Filter_TD_13256744_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_434548_s, &tv_r_Filter_11_434548_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12679417_input: " << tbl_SerializeFromObject_TD_12679417_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_11: " << tvdiff(&tv_r_JOIN_INNER_11_339569_s, &tv_r_JOIN_INNER_11_339569_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_12273451_output: " << tbl_JOIN_INNER_TD_12273451_output.getNumRow() << " " << "tbl_Filter_TD_124448_output: " << tbl_Filter_TD_124448_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_764595_s, &tv_r_Filter_11_764595_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12986662_input: " << tbl_SerializeFromObject_TD_12986662_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_11: " << tvdiff(&tv_r_JOIN_INNER_11_273323_s, &tv_r_JOIN_INNER_11_273323_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_12115296_output: " << tbl_JOIN_INNER_TD_12115296_output.getNumRow() << " " << "tbl_Filter_TD_12174597_output: " << tbl_Filter_TD_12174597_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_885430_s, &tv_r_Filter_10_885430_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11758762_input: " << tbl_SerializeFromObject_TD_11758762_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_598879_s, &tv_r_JOIN_INNER_10_598879_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_11493165_output: " << tbl_JOIN_INNER_TD_11493165_output.getNumRow() << " " << "tbl_Filter_TD_11557957_output: " << tbl_Filter_TD_11557957_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_347312_s, &tv_r_Filter_10_347312_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11703170_input: " << tbl_SerializeFromObject_TD_11703170_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_598283_s, &tv_r_JOIN_INNER_10_598283_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_11526036_output: " << tbl_JOIN_INNER_TD_11526036_output.getNumRow() << " " << "tbl_Filter_TD_1117050_output: " << tbl_Filter_TD_1117050_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_315519_s, &tv_r_Filter_9_315519_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10706938_input: " << tbl_SerializeFromObject_TD_10706938_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_189759_s, &tv_r_JOIN_INNER_9_189759_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10951912_output: " << tbl_JOIN_INNER_TD_10951912_output.getNumRow() << " " << "tbl_Filter_TD_10762193_output: " << tbl_Filter_TD_10762193_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_467951_s, &tv_r_Filter_9_467951_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1065428_input: " << tbl_SerializeFromObject_TD_1065428_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_741846_s, &tv_r_JOIN_INNER_9_741846_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10446614_output: " << tbl_JOIN_INNER_TD_10446614_output.getNumRow() << " " << "tbl_Filter_TD_1015392_output: " << tbl_Filter_TD_1015392_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_771883_s, &tv_r_Filter_8_771883_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9446210_input: " << tbl_SerializeFromObject_TD_9446210_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_583242_s, &tv_r_JOIN_INNER_8_583242_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9425844_output: " << tbl_JOIN_INNER_TD_9425844_output.getNumRow() << " " << "tbl_Filter_TD_9328766_output: " << tbl_Filter_TD_9328766_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_862209_s, &tv_r_Filter_8_862209_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9859896_input: " << tbl_SerializeFromObject_TD_9859896_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_926115_s, &tv_r_JOIN_INNER_8_926115_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9678884_output: " << tbl_JOIN_INNER_TD_9678884_output.getNumRow() << " " << "tbl_Filter_TD_9772283_output: " << tbl_Filter_TD_9772283_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_477461_s, &tv_r_Filter_7_477461_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8407051_input: " << tbl_SerializeFromObject_TD_8407051_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_543725_s, &tv_r_JOIN_INNER_7_543725_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8966505_output: " << tbl_JOIN_INNER_TD_8966505_output.getNumRow() << " " << "tbl_Filter_TD_8103123_output: " << tbl_Filter_TD_8103123_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_484722_s, &tv_r_Filter_7_484722_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8344879_input: " << tbl_SerializeFromObject_TD_8344879_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_958322_s, &tv_r_JOIN_INNER_7_958322_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8755957_output: " << tbl_JOIN_INNER_TD_8755957_output.getNumRow() << " " << "tbl_Filter_TD_8585812_output: " << tbl_Filter_TD_8585812_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_654742_s, &tv_r_Filter_6_654742_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7880239_input: " << tbl_SerializeFromObject_TD_7880239_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_41697_s, &tv_r_JOIN_INNER_6_41697_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7719384_output: " << tbl_JOIN_INNER_TD_7719384_output.getNumRow() << " " << "tbl_Filter_TD_7895840_output: " << tbl_Filter_TD_7895840_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_242139_s, &tv_r_Filter_6_242139_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7194992_input: " << tbl_SerializeFromObject_TD_7194992_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_220509_s, &tv_r_JOIN_INNER_6_220509_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_74545_output: " << tbl_JOIN_INNER_TD_74545_output.getNumRow() << " " << "tbl_Filter_TD_727362_output: " << tbl_Filter_TD_727362_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_243563_s, &tv_r_Filter_5_243563_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6423713_input: " << tbl_SerializeFromObject_TD_6423713_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_219369_s, &tv_r_JOIN_INNER_5_219369_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6838150_output: " << tbl_JOIN_INNER_TD_6838150_output.getNumRow() << " " << "tbl_Filter_TD_6220581_output: " << tbl_Filter_TD_6220581_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_308500_s, &tv_r_Filter_5_308500_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6648753_input: " << tbl_SerializeFromObject_TD_6648753_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_647198_s, &tv_r_JOIN_INNER_5_647198_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_653599_output: " << tbl_JOIN_INNER_TD_653599_output.getNumRow() << " " << "tbl_Filter_TD_6461371_output: " << tbl_Filter_TD_6461371_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_13748_s, &tv_r_JOIN_INNER_4_13748_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5724624_output: " << tbl_JOIN_INNER_TD_5724624_output.getNumRow() << " " << "tbl_Filter_TD_5514808_output: " << tbl_Filter_TD_5514808_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_544103_s, &tv_r_JOIN_INNER_4_544103_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5927078_output: " << tbl_JOIN_INNER_TD_5927078_output.getNumRow() << " " << "tbl_Filter_TD_5748863_output: " << tbl_Filter_TD_5748863_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_113224_s, &tv_r_Aggregate_3_113224_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4452906_output: " << tbl_JOIN_INNER_TD_4452906_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_833655_s, &tv_r_Aggregate_3_833655_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4338385_output: " << tbl_JOIN_INNER_TD_4338385_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_2: " << tvdiff(&tv_r_JOIN_INNER_2_874585_s, &tv_r_JOIN_INNER_2_874585_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3607278_output: " << tbl_Aggregate_TD_3607278_output.getNumRow() << " " << "tbl_Aggregate_TD_3248686_output: " << tbl_Aggregate_TD_3248686_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_1: " << tvdiff(&tv_r_Project_1_978716_s, &tv_r_Project_1_978716_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_2710081_output: " << tbl_JOIN_INNER_TD_2710081_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_335777_s, &tv_r_Sort_0_335777_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_1260547_output: " << tbl_Project_TD_1260547_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 5.480512 * 1000 << "ms" << std::endl; 
    return 0; 
}
