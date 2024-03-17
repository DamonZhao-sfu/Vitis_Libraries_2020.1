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

#include "cfgFunc_q23.hpp" 
#include "q23.hpp" 

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
    std::cout << "NOTE:running query #23\n."; 
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
    Table tbl_GlobalLimit_TD_0220815_output("tbl_GlobalLimit_TD_0220815_output", 6100000, 3, "");
    tbl_GlobalLimit_TD_0220815_output.allocateHost();
    Table tbl_LocalLimit_TD_1536848_output("tbl_LocalLimit_TD_1536848_output", 6100000, 3, "");
    tbl_LocalLimit_TD_1536848_output.allocateHost();
    Table tbl_Sort_TD_2281265_output("tbl_Sort_TD_2281265_output", 6100000, 3, "");
    tbl_Sort_TD_2281265_output.allocateHost();
    Table tbl_Union_TD_3362723_output("tbl_Union_TD_3362723_output", 6100000, 3, "");
    tbl_Union_TD_3362723_output.allocateHost();
    Table tbl_Aggregate_TD_4622735_output("tbl_Aggregate_TD_4622735_output", 6100000, 3, "");
    tbl_Aggregate_TD_4622735_output.allocateHost();
    Table tbl_Aggregate_TD_4296780_output("tbl_Aggregate_TD_4296780_output", 6100000, 3, "");
    tbl_Aggregate_TD_4296780_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5393483_output("tbl_JOIN_INNER_TD_5393483_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_5393483_output.allocateHost();
    Table tbl_JOIN_INNER_TD_514082_output("tbl_JOIN_INNER_TD_514082_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_514082_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6832049_output("tbl_JOIN_INNER_TD_6832049_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_6832049_output.allocateHost();
    Table tbl_Filter_TD_6729719_output("tbl_Filter_TD_6729719_output", 6100000, 1, "");
    tbl_Filter_TD_6729719_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6288197_output("tbl_JOIN_INNER_TD_6288197_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_6288197_output.allocateHost();
    Table tbl_Filter_TD_659084_output("tbl_Filter_TD_659084_output", 6100000, 1, "");
    tbl_Filter_TD_659084_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_7619982_output("tbl_JOIN_LEFTSEMI_TD_7619982_output", 6100000, 4, "");
    tbl_JOIN_LEFTSEMI_TD_7619982_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_7493952_output("tbl_JOIN_LEFTSEMI_TD_7493952_output", 6100000, 3, "");
    tbl_JOIN_LEFTSEMI_TD_7493952_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7253164_input;
    tbl_SerializeFromObject_TD_7253164_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7253164_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_7253164_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_7253164_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_7253164_input.allocateHost();
    tbl_SerializeFromObject_TD_7253164_input.loadHost();
    Table tbl_JOIN_LEFTSEMI_TD_7552478_output("tbl_JOIN_LEFTSEMI_TD_7552478_output", 6100000, 4, "");
    tbl_JOIN_LEFTSEMI_TD_7552478_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_7221819_output("tbl_JOIN_LEFTSEMI_TD_7221819_output", 6100000, 3, "");
    tbl_JOIN_LEFTSEMI_TD_7221819_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7703945_input;
    tbl_SerializeFromObject_TD_7703945_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7703945_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_7703945_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_7703945_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_7703945_input.allocateHost();
    tbl_SerializeFromObject_TD_7703945_input.loadHost();
    Table tbl_JOIN_LEFTSEMI_TD_8187296_output("tbl_JOIN_LEFTSEMI_TD_8187296_output", 6100000, 4, "");
    tbl_JOIN_LEFTSEMI_TD_8187296_output.allocateHost();
    Table tbl_Filter_TD_8434144_output("tbl_Filter_TD_8434144_output", 6100000, 1, "");
    tbl_Filter_TD_8434144_output.allocateHost();
    Table tbl_Filter_TD_8727146_output("tbl_Filter_TD_8727146_output", 6100000, 3, "");
    tbl_Filter_TD_8727146_output.allocateHost();
    Table tbl_Filter_TD_8479531_output("tbl_Filter_TD_8479531_output", 6100000, 1, "");
    tbl_Filter_TD_8479531_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_8435885_output("tbl_JOIN_LEFTSEMI_TD_8435885_output", 6100000, 4, "");
    tbl_JOIN_LEFTSEMI_TD_8435885_output.allocateHost();
    Table tbl_Filter_TD_8261746_output("tbl_Filter_TD_8261746_output", 6100000, 1, "");
    tbl_Filter_TD_8261746_output.allocateHost();
    Table tbl_Filter_TD_8166631_output("tbl_Filter_TD_8166631_output", 6100000, 3, "");
    tbl_Filter_TD_8166631_output.allocateHost();
    Table tbl_Filter_TD_8101406_output("tbl_Filter_TD_8101406_output", 6100000, 1, "");
    tbl_Filter_TD_8101406_output.allocateHost();
    Table tbl_Filter_TD_9849852_output("tbl_Filter_TD_9849852_output", 6100000, 5, "");
    tbl_Filter_TD_9849852_output.allocateHost();
    Table tbl_Filter_TD_9527090_output("tbl_Filter_TD_9527090_output", 6100000, 1, "");
    tbl_Filter_TD_9527090_output.allocateHost();
    Table tbl_Aggregate_TD_9241296_output_preprocess("tbl_Aggregate_TD_9241296_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_9241296_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_9241296_output("tbl_Aggregate_TD_9241296_output", 6100000, 2, "");
    tbl_Aggregate_TD_9241296_output.allocateHost();
    Table tbl_Aggregate_TD_9707922_output("tbl_Aggregate_TD_9707922_output", 6100000, 1, "");
    tbl_Aggregate_TD_9707922_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9246457_input;
    tbl_SerializeFromObject_TD_9246457_input = Table("customer", customer_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9246457_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_9246457_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9246457_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9246457_input.allocateHost();
    tbl_SerializeFromObject_TD_9246457_input.loadHost();
    Table tbl_Aggregate_TD_9394832_output_preprocess("tbl_Aggregate_TD_9394832_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_9394832_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_9394832_output("tbl_Aggregate_TD_9394832_output", 6100000, 2, "");
    tbl_Aggregate_TD_9394832_output.allocateHost();
    Table tbl_Aggregate_TD_9773538_output("tbl_Aggregate_TD_9773538_output", 6100000, 1, "");
    tbl_Aggregate_TD_9773538_output.allocateHost();
    Table tbl_Filter_TD_9697381_output("tbl_Filter_TD_9697381_output", 6100000, 5, "");
    tbl_Filter_TD_9697381_output.allocateHost();
    Table tbl_Filter_TD_9735928_output("tbl_Filter_TD_9735928_output", 6100000, 1, "");
    tbl_Filter_TD_9735928_output.allocateHost();
    Table tbl_Aggregate_TD_9948690_output_preprocess("tbl_Aggregate_TD_9948690_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_9948690_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_9948690_output("tbl_Aggregate_TD_9948690_output", 6100000, 2, "");
    tbl_Aggregate_TD_9948690_output.allocateHost();
    Table tbl_Aggregate_TD_9132965_output("tbl_Aggregate_TD_9132965_output", 6100000, 1, "");
    tbl_Aggregate_TD_9132965_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9255648_input;
    tbl_SerializeFromObject_TD_9255648_input = Table("customer", customer_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9255648_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_9255648_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9255648_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9255648_input.allocateHost();
    tbl_SerializeFromObject_TD_9255648_input.loadHost();
    Table tbl_Aggregate_TD_9533960_output_preprocess("tbl_Aggregate_TD_9533960_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_9533960_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_9533960_output("tbl_Aggregate_TD_9533960_output", 6100000, 2, "");
    tbl_Aggregate_TD_9533960_output.allocateHost();
    Table tbl_Aggregate_TD_9116253_output("tbl_Aggregate_TD_9116253_output", 6100000, 1, "");
    tbl_Aggregate_TD_9116253_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10110473_input;
    tbl_SerializeFromObject_TD_10110473_input = Table("catalog_sales", catalog_sales_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_10110473_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10110473_input.addCol("cs_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_10110473_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_10110473_input.addCol("cs_quantity", 4);
    tbl_SerializeFromObject_TD_10110473_input.addCol("cs_list_price", 4);
    tbl_SerializeFromObject_TD_10110473_input.allocateHost();
    tbl_SerializeFromObject_TD_10110473_input.loadHost();
    Table tbl_Aggregate_TD_10150991_output("tbl_Aggregate_TD_10150991_output", 6100000, 2, "");
    tbl_Aggregate_TD_10150991_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10122185_output_preprocess("tbl_JOIN_INNER_TD_10122185_output_preprocess", 6100000, 3, "");
    tbl_JOIN_INNER_TD_10122185_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_10122185_output("tbl_JOIN_INNER_TD_10122185_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_10122185_output.allocateHost();
    Table tbl_Aggregate_TD_10940044_output_preprocess("tbl_Aggregate_TD_10940044_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_10940044_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_10940044_output("tbl_Aggregate_TD_10940044_output", 6100000, 1, "");
    tbl_Aggregate_TD_10940044_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10548299_output_preprocess("tbl_JOIN_INNER_TD_10548299_output_preprocess", 6100000, 3, "");
    tbl_JOIN_INNER_TD_10548299_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_10548299_output("tbl_JOIN_INNER_TD_10548299_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_10548299_output.allocateHost();
    Table tbl_Aggregate_TD_10779337_output_preprocess("tbl_Aggregate_TD_10779337_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_10779337_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_10779337_output("tbl_Aggregate_TD_10779337_output", 6100000, 1, "");
    tbl_Aggregate_TD_10779337_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10269486_input;
    tbl_SerializeFromObject_TD_10269486_input = Table("web_sales", web_sales_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_10269486_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10269486_input.addCol("ws_item_sk", 4);
    tbl_SerializeFromObject_TD_10269486_input.addCol("ws_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_10269486_input.addCol("ws_quantity", 4);
    tbl_SerializeFromObject_TD_10269486_input.addCol("ws_list_price", 4);
    tbl_SerializeFromObject_TD_10269486_input.allocateHost();
    tbl_SerializeFromObject_TD_10269486_input.loadHost();
    Table tbl_Aggregate_TD_10874103_output("tbl_Aggregate_TD_10874103_output", 6100000, 2, "");
    tbl_Aggregate_TD_10874103_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10979249_output_preprocess("tbl_JOIN_INNER_TD_10979249_output_preprocess", 6100000, 3, "");
    tbl_JOIN_INNER_TD_10979249_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_10979249_output("tbl_JOIN_INNER_TD_10979249_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_10979249_output.allocateHost();
    Table tbl_Aggregate_TD_10114900_output_preprocess("tbl_Aggregate_TD_10114900_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_10114900_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_10114900_output("tbl_Aggregate_TD_10114900_output", 6100000, 1, "");
    tbl_Aggregate_TD_10114900_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10264341_output_preprocess("tbl_JOIN_INNER_TD_10264341_output_preprocess", 6100000, 3, "");
    tbl_JOIN_INNER_TD_10264341_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_10264341_output("tbl_JOIN_INNER_TD_10264341_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_10264341_output.allocateHost();
    Table tbl_Aggregate_TD_10391355_output_preprocess("tbl_Aggregate_TD_10391355_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_10391355_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_10391355_output("tbl_Aggregate_TD_10391355_output", 6100000, 1, "");
    tbl_Aggregate_TD_10391355_output.allocateHost();
    Table tbl_Project_TD_11995959_output("tbl_Project_TD_11995959_output", 6100000, 3, "");
    tbl_Project_TD_11995959_output.allocateHost();
    Table tbl_Filter_TD_11726486_output("tbl_Filter_TD_11726486_output", 6100000, 3, "");
    tbl_Filter_TD_11726486_output.allocateHost();
    Table tbl_Filter_TD_11957528_output("tbl_Filter_TD_11957528_output", 6100000, 1, "");
    tbl_Filter_TD_11957528_output.allocateHost();
    Table tbl_JOIN_INNER_TD_1137987_output_preprocess("tbl_JOIN_INNER_TD_1137987_output_preprocess", 6100000, 3, "");
    tbl_JOIN_INNER_TD_1137987_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_1137987_output("tbl_JOIN_INNER_TD_1137987_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_1137987_output.allocateHost();
    Table tbl_Filter_TD_11510993_output("tbl_Filter_TD_11510993_output", 6100000, 3, "");
    tbl_Filter_TD_11510993_output.allocateHost();
    Table tbl_Filter_TD_11361028_output("tbl_Filter_TD_11361028_output", 6100000, 1, "");
    tbl_Filter_TD_11361028_output.allocateHost();
    Table tbl_JOIN_INNER_TD_11161751_output_preprocess("tbl_JOIN_INNER_TD_11161751_output_preprocess", 6100000, 3, "");
    tbl_JOIN_INNER_TD_11161751_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_11161751_output("tbl_JOIN_INNER_TD_11161751_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_11161751_output.allocateHost();
    Table tbl_Project_TD_11107252_output("tbl_Project_TD_11107252_output", 6100000, 3, "");
    tbl_Project_TD_11107252_output.allocateHost();
    Table tbl_Filter_TD_11187752_output("tbl_Filter_TD_11187752_output", 6100000, 3, "");
    tbl_Filter_TD_11187752_output.allocateHost();
    Table tbl_Filter_TD_11871505_output("tbl_Filter_TD_11871505_output", 6100000, 1, "");
    tbl_Filter_TD_11871505_output.allocateHost();
    Table tbl_JOIN_INNER_TD_11586348_output_preprocess("tbl_JOIN_INNER_TD_11586348_output_preprocess", 6100000, 3, "");
    tbl_JOIN_INNER_TD_11586348_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_11586348_output("tbl_JOIN_INNER_TD_11586348_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_11586348_output.allocateHost();
    Table tbl_Filter_TD_11174320_output("tbl_Filter_TD_11174320_output", 6100000, 3, "");
    tbl_Filter_TD_11174320_output.allocateHost();
    Table tbl_Filter_TD_11760980_output("tbl_Filter_TD_11760980_output", 6100000, 1, "");
    tbl_Filter_TD_11760980_output.allocateHost();
    Table tbl_JOIN_INNER_TD_11391199_output_preprocess("tbl_JOIN_INNER_TD_11391199_output_preprocess", 6100000, 3, "");
    tbl_JOIN_INNER_TD_11391199_output_preprocess.allocateHost();
    Table tbl_JOIN_INNER_TD_11391199_output("tbl_JOIN_INNER_TD_11391199_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_11391199_output.allocateHost();
    Table tbl_JOIN_INNER_TD_12731607_output("tbl_JOIN_INNER_TD_12731607_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_12731607_output.allocateHost();
    Table tbl_SerializeFromObject_TD_12133188_input;
    tbl_SerializeFromObject_TD_12133188_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_12133188_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_12133188_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_12133188_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_12133188_input.allocateHost();
    tbl_SerializeFromObject_TD_12133188_input.loadHost();
    Table tbl_SerializeFromObject_TD_12783408_input;
    tbl_SerializeFromObject_TD_12783408_input = Table("customer", customer_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_12783408_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_12783408_input.allocateHost();
    tbl_SerializeFromObject_TD_12783408_input.loadHost();
    Table tbl_JOIN_INNER_TD_12481484_output("tbl_JOIN_INNER_TD_12481484_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_12481484_output.allocateHost();
    Table tbl_Filter_TD_12691562_output("tbl_Filter_TD_12691562_output", 6100000, 1, "");
    tbl_Filter_TD_12691562_output.allocateHost();
    Table tbl_SerializeFromObject_TD_12390145_input;
    tbl_SerializeFromObject_TD_12390145_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_12390145_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_12390145_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_12390145_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_12390145_input.allocateHost();
    tbl_SerializeFromObject_TD_12390145_input.loadHost();
    Table tbl_SerializeFromObject_TD_1223068_input;
    tbl_SerializeFromObject_TD_1223068_input = Table("customer", customer_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_1223068_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_1223068_input.allocateHost();
    tbl_SerializeFromObject_TD_1223068_input.loadHost();
    Table tbl_JOIN_INNER_TD_12552462_output("tbl_JOIN_INNER_TD_12552462_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_12552462_output.allocateHost();
    Table tbl_Filter_TD_12313344_output("tbl_Filter_TD_12313344_output", 6100000, 1, "");
    tbl_Filter_TD_12313344_output.allocateHost();
    Table tbl_JOIN_INNER_TD_12390969_output("tbl_JOIN_INNER_TD_12390969_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_12390969_output.allocateHost();
    Table tbl_SerializeFromObject_TD_12747514_input;
    tbl_SerializeFromObject_TD_12747514_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_12747514_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_12747514_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_12747514_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_12747514_input.allocateHost();
    tbl_SerializeFromObject_TD_12747514_input.loadHost();
    Table tbl_SerializeFromObject_TD_12680534_input;
    tbl_SerializeFromObject_TD_12680534_input = Table("customer", customer_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_12680534_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_12680534_input.allocateHost();
    tbl_SerializeFromObject_TD_12680534_input.loadHost();
    Table tbl_JOIN_INNER_TD_12732934_output("tbl_JOIN_INNER_TD_12732934_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_12732934_output.allocateHost();
    Table tbl_Filter_TD_12901777_output("tbl_Filter_TD_12901777_output", 6100000, 1, "");
    tbl_Filter_TD_12901777_output.allocateHost();
    Table tbl_SerializeFromObject_TD_12735447_input;
    tbl_SerializeFromObject_TD_12735447_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_12735447_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_12735447_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_12735447_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_12735447_input.allocateHost();
    tbl_SerializeFromObject_TD_12735447_input.loadHost();
    Table tbl_SerializeFromObject_TD_12350645_input;
    tbl_SerializeFromObject_TD_12350645_input = Table("customer", customer_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_12350645_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_12350645_input.allocateHost();
    tbl_SerializeFromObject_TD_12350645_input.loadHost();
    Table tbl_JOIN_INNER_TD_12149137_output("tbl_JOIN_INNER_TD_12149137_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_12149137_output.allocateHost();
    Table tbl_Filter_TD_12386496_output("tbl_Filter_TD_12386496_output", 6100000, 1, "");
    tbl_Filter_TD_12386496_output.allocateHost();
    Table tbl_JOIN_INNER_TD_13287355_output("tbl_JOIN_INNER_TD_13287355_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_13287355_output.allocateHost();
    Table tbl_Filter_TD_1373874_output("tbl_Filter_TD_1373874_output", 6100000, 2, "");
    tbl_Filter_TD_1373874_output.allocateHost();
    Table tbl_Filter_TD_13366246_output("tbl_Filter_TD_13366246_output", 6100000, 4, "");
    tbl_Filter_TD_13366246_output.allocateHost();
    Table tbl_Filter_TD_13539019_output("tbl_Filter_TD_13539019_output", 6100000, 1, "");
    tbl_Filter_TD_13539019_output.allocateHost();
    Table tbl_SerializeFromObject_TD_13438014_input;
    tbl_SerializeFromObject_TD_13438014_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_13438014_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_13438014_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_13438014_input.allocateHost();
    tbl_SerializeFromObject_TD_13438014_input.loadHost();
    Table tbl_Filter_TD_13702041_output("tbl_Filter_TD_13702041_output", 6100000, 4, "");
    tbl_Filter_TD_13702041_output.allocateHost();
    Table tbl_Filter_TD_13469673_output("tbl_Filter_TD_13469673_output", 6100000, 1, "");
    tbl_Filter_TD_13469673_output.allocateHost();
    Table tbl_SerializeFromObject_TD_13259179_input;
    tbl_SerializeFromObject_TD_13259179_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_13259179_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_13259179_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_13259179_input.allocateHost();
    tbl_SerializeFromObject_TD_13259179_input.loadHost();
    Table tbl_JOIN_INNER_TD_13942914_output("tbl_JOIN_INNER_TD_13942914_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_13942914_output.allocateHost();
    Table tbl_Filter_TD_13954360_output("tbl_Filter_TD_13954360_output", 6100000, 2, "");
    tbl_Filter_TD_13954360_output.allocateHost();
    Table tbl_Filter_TD_13647399_output("tbl_Filter_TD_13647399_output", 6100000, 4, "");
    tbl_Filter_TD_13647399_output.allocateHost();
    Table tbl_Filter_TD_1386041_output("tbl_Filter_TD_1386041_output", 6100000, 1, "");
    tbl_Filter_TD_1386041_output.allocateHost();
    Table tbl_SerializeFromObject_TD_13842382_input;
    tbl_SerializeFromObject_TD_13842382_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_13842382_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_13842382_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_13842382_input.allocateHost();
    tbl_SerializeFromObject_TD_13842382_input.loadHost();
    Table tbl_Filter_TD_13700909_output("tbl_Filter_TD_13700909_output", 6100000, 4, "");
    tbl_Filter_TD_13700909_output.allocateHost();
    Table tbl_Filter_TD_13452877_output("tbl_Filter_TD_13452877_output", 6100000, 1, "");
    tbl_Filter_TD_13452877_output.allocateHost();
    Table tbl_SerializeFromObject_TD_13541437_input;
    tbl_SerializeFromObject_TD_13541437_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_13541437_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_13541437_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_13541437_input.allocateHost();
    tbl_SerializeFromObject_TD_13541437_input.loadHost();
    Table tbl_Filter_TD_14640872_output("tbl_Filter_TD_14640872_output", 6100000, 2, "");
    tbl_Filter_TD_14640872_output.allocateHost();
    Table tbl_Filter_TD_14165006_output("tbl_Filter_TD_14165006_output", 6100000, 2, "");
    tbl_Filter_TD_14165006_output.allocateHost();
    Table tbl_SerializeFromObject_TD_14800257_input;
    tbl_SerializeFromObject_TD_14800257_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_14800257_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_14800257_input.addCol("i_item_desc", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_14800257_input.allocateHost();
    tbl_SerializeFromObject_TD_14800257_input.loadHost();
    Table tbl_SerializeFromObject_TD_14654455_input;
    tbl_SerializeFromObject_TD_14654455_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_14654455_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_14654455_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_14654455_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_14654455_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_14654455_input.allocateHost();
    tbl_SerializeFromObject_TD_14654455_input.loadHost();
    Table tbl_SerializeFromObject_TD_1452553_input;
    tbl_SerializeFromObject_TD_1452553_input = Table("customer", customer_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_1452553_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_1452553_input.allocateHost();
    tbl_SerializeFromObject_TD_1452553_input.loadHost();
    Table tbl_SerializeFromObject_TD_14673856_input;
    tbl_SerializeFromObject_TD_14673856_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_14673856_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_14673856_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_14673856_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_14673856_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_14673856_input.allocateHost();
    tbl_SerializeFromObject_TD_14673856_input.loadHost();
    Table tbl_SerializeFromObject_TD_14786228_input;
    tbl_SerializeFromObject_TD_14786228_input = Table("customer", customer_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_14786228_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_14786228_input.allocateHost();
    tbl_SerializeFromObject_TD_14786228_input.loadHost();
    Table tbl_Filter_TD_14407716_output("tbl_Filter_TD_14407716_output", 6100000, 2, "");
    tbl_Filter_TD_14407716_output.allocateHost();
    Table tbl_Filter_TD_14399817_output("tbl_Filter_TD_14399817_output", 6100000, 2, "");
    tbl_Filter_TD_14399817_output.allocateHost();
    Table tbl_SerializeFromObject_TD_14566612_input;
    tbl_SerializeFromObject_TD_14566612_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_14566612_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_14566612_input.addCol("i_item_desc", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_14566612_input.allocateHost();
    tbl_SerializeFromObject_TD_14566612_input.loadHost();
    Table tbl_SerializeFromObject_TD_14570327_input;
    tbl_SerializeFromObject_TD_14570327_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_14570327_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_14570327_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_14570327_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_14570327_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_14570327_input.allocateHost();
    tbl_SerializeFromObject_TD_14570327_input.loadHost();
    Table tbl_SerializeFromObject_TD_14532305_input;
    tbl_SerializeFromObject_TD_14532305_input = Table("customer", customer_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_14532305_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_14532305_input.allocateHost();
    tbl_SerializeFromObject_TD_14532305_input.loadHost();
    Table tbl_SerializeFromObject_TD_1443236_input;
    tbl_SerializeFromObject_TD_1443236_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_1443236_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_1443236_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_1443236_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_1443236_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_1443236_input.allocateHost();
    tbl_SerializeFromObject_TD_1443236_input.loadHost();
    Table tbl_SerializeFromObject_TD_14255064_input;
    tbl_SerializeFromObject_TD_14255064_input = Table("customer", customer_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_14255064_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_14255064_input.allocateHost();
    tbl_SerializeFromObject_TD_14255064_input.loadHost();
    Table tbl_SerializeFromObject_TD_15306391_input;
    tbl_SerializeFromObject_TD_15306391_input = Table("store_sales", store_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_15306391_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_15306391_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_15306391_input.allocateHost();
    tbl_SerializeFromObject_TD_15306391_input.loadHost();
    Table tbl_SerializeFromObject_TD_15216586_input;
    tbl_SerializeFromObject_TD_15216586_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_15216586_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_15216586_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_15216586_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_15216586_input.allocateHost();
    tbl_SerializeFromObject_TD_15216586_input.loadHost();
    Table tbl_SerializeFromObject_TD_15445630_input;
    tbl_SerializeFromObject_TD_15445630_input = Table("store_sales", store_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_15445630_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_15445630_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_15445630_input.allocateHost();
    tbl_SerializeFromObject_TD_15445630_input.loadHost();
    Table tbl_SerializeFromObject_TD_15662963_input;
    tbl_SerializeFromObject_TD_15662963_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_15662963_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_15662963_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_15662963_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_15662963_input.allocateHost();
    tbl_SerializeFromObject_TD_15662963_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_LEFTSEMI_TD_7619982_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTSEMI_TD_7552478_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTSEMI_TD_8187296_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8434144_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTSEMI_TD_8435885_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8261746_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9849852_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9527090_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_10122185_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_9241296_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_JOIN_INNER_TD_10548299_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_9394832_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_Filter_TD_9697381_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9735928_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_10979249_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_9948690_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_JOIN_INNER_TD_10264341_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_9533960_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_JOIN_INNER_TD_10122185_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_1137987_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_10940044_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_JOIN_INNER_TD_10548299_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_11161751_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_10779337_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_JOIN_INNER_TD_10979249_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_11586348_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_10114900_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_JOIN_INNER_TD_10264341_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_11391199_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_10391355_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_Filter_TD_11726486_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11957528_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_1137987_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11510993_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11361028_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_11161751_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11187752_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11871505_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_11586348_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11174320_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11760980_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_11391199_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_12481484_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_12691562_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_12552462_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_12313344_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_12732934_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_12901777_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_12149137_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_12386496_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_13287355_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_13366246_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_13539019_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_13702041_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_13469673_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_13942914_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_13647399_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_1386041_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_13700909_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_13452877_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_14640872_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_14165006_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_14407716_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_14399817_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_LEFTSEMI_TD_7619982_cmds;
    cfg_JOIN_LEFTSEMI_TD_7619982_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_7619982_gqe_join (cfg_JOIN_LEFTSEMI_TD_7619982_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_7619982_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_7552478_cmds;
    cfg_JOIN_LEFTSEMI_TD_7552478_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_7552478_gqe_join (cfg_JOIN_LEFTSEMI_TD_7552478_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_7552478_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_8187296_cmds;
    cfg_JOIN_LEFTSEMI_TD_8187296_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_8187296_gqe_join (cfg_JOIN_LEFTSEMI_TD_8187296_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_8187296_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_8435885_cmds;
    cfg_JOIN_LEFTSEMI_TD_8435885_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_8435885_gqe_join (cfg_JOIN_LEFTSEMI_TD_8435885_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_8435885_cmds.allocateDevBuffer(context_h, 32);
    AggrCfgCmd cfg_Aggregate_TD_9241296_cmds;
    cfg_Aggregate_TD_9241296_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_9241296_gqe_aggr(cfg_Aggregate_TD_9241296_cmds.cmd);
    cfg_Aggregate_TD_9241296_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_9241296_cmds_out;
    cfg_Aggregate_TD_9241296_cmds_out.allocateHost();
    cfg_Aggregate_TD_9241296_cmds_out.allocateDevBuffer(context_a, 33);
    AggrCfgCmd cfg_Aggregate_TD_9394832_cmds;
    cfg_Aggregate_TD_9394832_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_9394832_gqe_aggr(cfg_Aggregate_TD_9394832_cmds.cmd);
    cfg_Aggregate_TD_9394832_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_9394832_cmds_out;
    cfg_Aggregate_TD_9394832_cmds_out.allocateHost();
    cfg_Aggregate_TD_9394832_cmds_out.allocateDevBuffer(context_a, 33);
    AggrCfgCmd cfg_Aggregate_TD_9948690_cmds;
    cfg_Aggregate_TD_9948690_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_9948690_gqe_aggr(cfg_Aggregate_TD_9948690_cmds.cmd);
    cfg_Aggregate_TD_9948690_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_9948690_cmds_out;
    cfg_Aggregate_TD_9948690_cmds_out.allocateHost();
    cfg_Aggregate_TD_9948690_cmds_out.allocateDevBuffer(context_a, 33);
    AggrCfgCmd cfg_Aggregate_TD_9533960_cmds;
    cfg_Aggregate_TD_9533960_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_9533960_gqe_aggr(cfg_Aggregate_TD_9533960_cmds.cmd);
    cfg_Aggregate_TD_9533960_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_9533960_cmds_out;
    cfg_Aggregate_TD_9533960_cmds_out.allocateHost();
    cfg_Aggregate_TD_9533960_cmds_out.allocateDevBuffer(context_a, 33);
    cfgCmd cfg_JOIN_INNER_TD_10122185_cmds;
    cfg_JOIN_INNER_TD_10122185_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_10122185_gqe_join (cfg_JOIN_INNER_TD_10122185_cmds.cmd);
    cfg_JOIN_INNER_TD_10122185_cmds.allocateDevBuffer(context_h, 32);
    AggrCfgCmd cfg_Aggregate_TD_10940044_cmds;
    cfg_Aggregate_TD_10940044_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_10940044_gqe_aggr(cfg_Aggregate_TD_10940044_cmds.cmd);
    cfg_Aggregate_TD_10940044_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_10940044_cmds_out;
    cfg_Aggregate_TD_10940044_cmds_out.allocateHost();
    cfg_Aggregate_TD_10940044_cmds_out.allocateDevBuffer(context_a, 33);
    cfgCmd cfg_JOIN_INNER_TD_10548299_cmds;
    cfg_JOIN_INNER_TD_10548299_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_10548299_gqe_join (cfg_JOIN_INNER_TD_10548299_cmds.cmd);
    cfg_JOIN_INNER_TD_10548299_cmds.allocateDevBuffer(context_h, 32);
    AggrCfgCmd cfg_Aggregate_TD_10779337_cmds;
    cfg_Aggregate_TD_10779337_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_10779337_gqe_aggr(cfg_Aggregate_TD_10779337_cmds.cmd);
    cfg_Aggregate_TD_10779337_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_10779337_cmds_out;
    cfg_Aggregate_TD_10779337_cmds_out.allocateHost();
    cfg_Aggregate_TD_10779337_cmds_out.allocateDevBuffer(context_a, 33);
    cfgCmd cfg_JOIN_INNER_TD_10979249_cmds;
    cfg_JOIN_INNER_TD_10979249_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_10979249_gqe_join (cfg_JOIN_INNER_TD_10979249_cmds.cmd);
    cfg_JOIN_INNER_TD_10979249_cmds.allocateDevBuffer(context_h, 32);
    AggrCfgCmd cfg_Aggregate_TD_10114900_cmds;
    cfg_Aggregate_TD_10114900_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_10114900_gqe_aggr(cfg_Aggregate_TD_10114900_cmds.cmd);
    cfg_Aggregate_TD_10114900_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_10114900_cmds_out;
    cfg_Aggregate_TD_10114900_cmds_out.allocateHost();
    cfg_Aggregate_TD_10114900_cmds_out.allocateDevBuffer(context_a, 33);
    cfgCmd cfg_JOIN_INNER_TD_10264341_cmds;
    cfg_JOIN_INNER_TD_10264341_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_10264341_gqe_join (cfg_JOIN_INNER_TD_10264341_cmds.cmd);
    cfg_JOIN_INNER_TD_10264341_cmds.allocateDevBuffer(context_h, 32);
    AggrCfgCmd cfg_Aggregate_TD_10391355_cmds;
    cfg_Aggregate_TD_10391355_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_10391355_gqe_aggr(cfg_Aggregate_TD_10391355_cmds.cmd);
    cfg_Aggregate_TD_10391355_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_10391355_cmds_out;
    cfg_Aggregate_TD_10391355_cmds_out.allocateHost();
    cfg_Aggregate_TD_10391355_cmds_out.allocateDevBuffer(context_a, 33);
    cfgCmd cfg_JOIN_INNER_TD_1137987_cmds;
    cfg_JOIN_INNER_TD_1137987_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_1137987_gqe_join (cfg_JOIN_INNER_TD_1137987_cmds.cmd);
    cfg_JOIN_INNER_TD_1137987_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_11161751_cmds;
    cfg_JOIN_INNER_TD_11161751_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_11161751_gqe_join (cfg_JOIN_INNER_TD_11161751_cmds.cmd);
    cfg_JOIN_INNER_TD_11161751_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_11586348_cmds;
    cfg_JOIN_INNER_TD_11586348_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_11586348_gqe_join (cfg_JOIN_INNER_TD_11586348_cmds.cmd);
    cfg_JOIN_INNER_TD_11586348_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_11391199_cmds;
    cfg_JOIN_INNER_TD_11391199_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_11391199_gqe_join (cfg_JOIN_INNER_TD_11391199_cmds.cmd);
    cfg_JOIN_INNER_TD_11391199_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_12481484_cmds;
    cfg_JOIN_INNER_TD_12481484_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_12481484_gqe_join (cfg_JOIN_INNER_TD_12481484_cmds.cmd);
    cfg_JOIN_INNER_TD_12481484_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_12552462_cmds;
    cfg_JOIN_INNER_TD_12552462_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_12552462_gqe_join (cfg_JOIN_INNER_TD_12552462_cmds.cmd);
    cfg_JOIN_INNER_TD_12552462_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_12732934_cmds;
    cfg_JOIN_INNER_TD_12732934_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_12732934_gqe_join (cfg_JOIN_INNER_TD_12732934_cmds.cmd);
    cfg_JOIN_INNER_TD_12732934_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_12149137_cmds;
    cfg_JOIN_INNER_TD_12149137_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_12149137_gqe_join (cfg_JOIN_INNER_TD_12149137_cmds.cmd);
    cfg_JOIN_INNER_TD_12149137_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_13287355_cmds;
    cfg_JOIN_INNER_TD_13287355_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_13287355_gqe_join (cfg_JOIN_INNER_TD_13287355_cmds.cmd);
    cfg_JOIN_INNER_TD_13287355_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_13942914_cmds;
    cfg_JOIN_INNER_TD_13942914_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_13942914_gqe_join (cfg_JOIN_INNER_TD_13942914_cmds.cmd);
    cfg_JOIN_INNER_TD_13942914_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    AggrBufferTmp buftmp_a(context_a); 
    buftmp_a.BufferInitial(q_a); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_LEFTSEMI_TD_7619982;
    krnl_JOIN_LEFTSEMI_TD_7619982 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTSEMI_TD_7619982.setup(tbl_Filter_TD_8434144_output, tbl_JOIN_LEFTSEMI_TD_8187296_output, tbl_JOIN_LEFTSEMI_TD_7619982_output, cfg_JOIN_LEFTSEMI_TD_7619982_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_7552478;
    krnl_JOIN_LEFTSEMI_TD_7552478 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTSEMI_TD_7552478.setup(tbl_Filter_TD_8261746_output, tbl_JOIN_LEFTSEMI_TD_8435885_output, tbl_JOIN_LEFTSEMI_TD_7552478_output, cfg_JOIN_LEFTSEMI_TD_7552478_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_8187296;
    krnl_JOIN_LEFTSEMI_TD_8187296 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTSEMI_TD_8187296.setup(tbl_Filter_TD_9527090_output, tbl_Filter_TD_9849852_output, tbl_JOIN_LEFTSEMI_TD_8187296_output, cfg_JOIN_LEFTSEMI_TD_8187296_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_8435885;
    krnl_JOIN_LEFTSEMI_TD_8435885 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTSEMI_TD_8435885.setup(tbl_Filter_TD_9735928_output, tbl_Filter_TD_9697381_output, tbl_JOIN_LEFTSEMI_TD_8435885_output, cfg_JOIN_LEFTSEMI_TD_8435885_cmds, buftmp_h);
    AggrKrnlEngine krnl_Aggregate_TD_9241296;
    krnl_Aggregate_TD_9241296 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_9241296.setup(tbl_JOIN_INNER_TD_10122185_output, tbl_Aggregate_TD_9241296_output_preprocess, cfg_Aggregate_TD_9241296_cmds, cfg_Aggregate_TD_9241296_cmds_out, buftmp_a);
    AggrKrnlEngine krnl_Aggregate_TD_9394832;
    krnl_Aggregate_TD_9394832 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_9394832.setup(tbl_JOIN_INNER_TD_10548299_output, tbl_Aggregate_TD_9394832_output_preprocess, cfg_Aggregate_TD_9394832_cmds, cfg_Aggregate_TD_9394832_cmds_out, buftmp_a);
    AggrKrnlEngine krnl_Aggregate_TD_9948690;
    krnl_Aggregate_TD_9948690 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_9948690.setup(tbl_JOIN_INNER_TD_10979249_output, tbl_Aggregate_TD_9948690_output_preprocess, cfg_Aggregate_TD_9948690_cmds, cfg_Aggregate_TD_9948690_cmds_out, buftmp_a);
    AggrKrnlEngine krnl_Aggregate_TD_9533960;
    krnl_Aggregate_TD_9533960 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_9533960.setup(tbl_JOIN_INNER_TD_10264341_output, tbl_Aggregate_TD_9533960_output_preprocess, cfg_Aggregate_TD_9533960_cmds, cfg_Aggregate_TD_9533960_cmds_out, buftmp_a);
    krnlEngine krnl_JOIN_INNER_TD_10122185;
    krnl_JOIN_INNER_TD_10122185 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_10122185.setup(tbl_Filter_TD_11726486_output, tbl_Filter_TD_11957528_output, tbl_JOIN_INNER_TD_10122185_output_preprocess, cfg_JOIN_INNER_TD_10122185_cmds, buftmp_h);
    AggrKrnlEngine krnl_Aggregate_TD_10940044;
    krnl_Aggregate_TD_10940044 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_10940044.setup(tbl_JOIN_INNER_TD_1137987_output, tbl_Aggregate_TD_10940044_output_preprocess, cfg_Aggregate_TD_10940044_cmds, cfg_Aggregate_TD_10940044_cmds_out, buftmp_a);
    krnlEngine krnl_JOIN_INNER_TD_10548299;
    krnl_JOIN_INNER_TD_10548299 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_10548299.setup(tbl_Filter_TD_11510993_output, tbl_Filter_TD_11361028_output, tbl_JOIN_INNER_TD_10548299_output_preprocess, cfg_JOIN_INNER_TD_10548299_cmds, buftmp_h);
    AggrKrnlEngine krnl_Aggregate_TD_10779337;
    krnl_Aggregate_TD_10779337 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_10779337.setup(tbl_JOIN_INNER_TD_11161751_output, tbl_Aggregate_TD_10779337_output_preprocess, cfg_Aggregate_TD_10779337_cmds, cfg_Aggregate_TD_10779337_cmds_out, buftmp_a);
    krnlEngine krnl_JOIN_INNER_TD_10979249;
    krnl_JOIN_INNER_TD_10979249 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_10979249.setup(tbl_Filter_TD_11187752_output, tbl_Filter_TD_11871505_output, tbl_JOIN_INNER_TD_10979249_output_preprocess, cfg_JOIN_INNER_TD_10979249_cmds, buftmp_h);
    AggrKrnlEngine krnl_Aggregate_TD_10114900;
    krnl_Aggregate_TD_10114900 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_10114900.setup(tbl_JOIN_INNER_TD_11586348_output, tbl_Aggregate_TD_10114900_output_preprocess, cfg_Aggregate_TD_10114900_cmds, cfg_Aggregate_TD_10114900_cmds_out, buftmp_a);
    krnlEngine krnl_JOIN_INNER_TD_10264341;
    krnl_JOIN_INNER_TD_10264341 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_10264341.setup(tbl_Filter_TD_11174320_output, tbl_Filter_TD_11760980_output, tbl_JOIN_INNER_TD_10264341_output_preprocess, cfg_JOIN_INNER_TD_10264341_cmds, buftmp_h);
    AggrKrnlEngine krnl_Aggregate_TD_10391355;
    krnl_Aggregate_TD_10391355 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_10391355.setup(tbl_JOIN_INNER_TD_11391199_output, tbl_Aggregate_TD_10391355_output_preprocess, cfg_Aggregate_TD_10391355_cmds, cfg_Aggregate_TD_10391355_cmds_out, buftmp_a);
    krnlEngine krnl_JOIN_INNER_TD_1137987;
    krnl_JOIN_INNER_TD_1137987 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_1137987.setup(tbl_JOIN_INNER_TD_12481484_output, tbl_Filter_TD_12691562_output, tbl_JOIN_INNER_TD_1137987_output_preprocess, cfg_JOIN_INNER_TD_1137987_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_11161751;
    krnl_JOIN_INNER_TD_11161751 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_11161751.setup(tbl_JOIN_INNER_TD_12552462_output, tbl_Filter_TD_12313344_output, tbl_JOIN_INNER_TD_11161751_output_preprocess, cfg_JOIN_INNER_TD_11161751_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_11586348;
    krnl_JOIN_INNER_TD_11586348 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_11586348.setup(tbl_JOIN_INNER_TD_12732934_output, tbl_Filter_TD_12901777_output, tbl_JOIN_INNER_TD_11586348_output_preprocess, cfg_JOIN_INNER_TD_11586348_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_11391199;
    krnl_JOIN_INNER_TD_11391199 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_11391199.setup(tbl_JOIN_INNER_TD_12149137_output, tbl_Filter_TD_12386496_output, tbl_JOIN_INNER_TD_11391199_output_preprocess, cfg_JOIN_INNER_TD_11391199_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_12481484;
    krnl_JOIN_INNER_TD_12481484 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_12481484.setup(tbl_Filter_TD_13366246_output, tbl_Filter_TD_13539019_output, tbl_JOIN_INNER_TD_12481484_output, cfg_JOIN_INNER_TD_12481484_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_12552462;
    krnl_JOIN_INNER_TD_12552462 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_12552462.setup(tbl_Filter_TD_13702041_output, tbl_Filter_TD_13469673_output, tbl_JOIN_INNER_TD_12552462_output, cfg_JOIN_INNER_TD_12552462_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_12732934;
    krnl_JOIN_INNER_TD_12732934 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_12732934.setup(tbl_Filter_TD_13647399_output, tbl_Filter_TD_1386041_output, tbl_JOIN_INNER_TD_12732934_output, cfg_JOIN_INNER_TD_12732934_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_12149137;
    krnl_JOIN_INNER_TD_12149137 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_12149137.setup(tbl_Filter_TD_13700909_output, tbl_Filter_TD_13452877_output, tbl_JOIN_INNER_TD_12149137_output, cfg_JOIN_INNER_TD_12149137_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_13287355;
    krnl_JOIN_INNER_TD_13287355 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_13287355.setup(tbl_Filter_TD_14640872_output, tbl_Filter_TD_14165006_output, tbl_JOIN_INNER_TD_13287355_output, cfg_JOIN_INNER_TD_13287355_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_13942914;
    krnl_JOIN_INNER_TD_13942914 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_13942914.setup(tbl_Filter_TD_14407716_output, tbl_Filter_TD_14399817_output, tbl_JOIN_INNER_TD_13942914_output, cfg_JOIN_INNER_TD_13942914_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_LEFTSEMI_TD_7619982;
    trans_JOIN_LEFTSEMI_TD_7619982.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_7619982.add(&(cfg_JOIN_LEFTSEMI_TD_7619982_cmds));
    transEngine trans_JOIN_LEFTSEMI_TD_7619982_out;
    trans_JOIN_LEFTSEMI_TD_7619982_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_LEFTSEMI_TD_7552478;
    trans_JOIN_LEFTSEMI_TD_7552478.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_7552478.add(&(cfg_JOIN_LEFTSEMI_TD_7552478_cmds));
    transEngine trans_JOIN_LEFTSEMI_TD_7552478_out;
    trans_JOIN_LEFTSEMI_TD_7552478_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_LEFTSEMI_TD_8187296;
    trans_JOIN_LEFTSEMI_TD_8187296.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_8187296.add(&(cfg_JOIN_LEFTSEMI_TD_8187296_cmds));
    q_h.finish();
    transEngine trans_JOIN_LEFTSEMI_TD_8435885;
    trans_JOIN_LEFTSEMI_TD_8435885.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_8435885.add(&(cfg_JOIN_LEFTSEMI_TD_8435885_cmds));
    q_h.finish();
    transEngine trans_Aggregate_TD_9241296;
    trans_Aggregate_TD_9241296.setq(q_a);
    trans_Aggregate_TD_9241296.add(&(cfg_Aggregate_TD_9241296_cmds));
    transEngine trans_Aggregate_TD_9241296_out;
    trans_Aggregate_TD_9241296_out.setq(q_a);
    q_a.finish();
    transEngine trans_Aggregate_TD_9394832;
    trans_Aggregate_TD_9394832.setq(q_a);
    trans_Aggregate_TD_9394832.add(&(cfg_Aggregate_TD_9394832_cmds));
    transEngine trans_Aggregate_TD_9394832_out;
    trans_Aggregate_TD_9394832_out.setq(q_a);
    q_a.finish();
    transEngine trans_Aggregate_TD_9948690;
    trans_Aggregate_TD_9948690.setq(q_a);
    trans_Aggregate_TD_9948690.add(&(cfg_Aggregate_TD_9948690_cmds));
    transEngine trans_Aggregate_TD_9948690_out;
    trans_Aggregate_TD_9948690_out.setq(q_a);
    q_a.finish();
    transEngine trans_Aggregate_TD_9533960;
    trans_Aggregate_TD_9533960.setq(q_a);
    trans_Aggregate_TD_9533960.add(&(cfg_Aggregate_TD_9533960_cmds));
    transEngine trans_Aggregate_TD_9533960_out;
    trans_Aggregate_TD_9533960_out.setq(q_a);
    q_a.finish();
    transEngine trans_JOIN_INNER_TD_10122185;
    trans_JOIN_INNER_TD_10122185.setq(q_h);
    trans_JOIN_INNER_TD_10122185.add(&(cfg_JOIN_INNER_TD_10122185_cmds));
    transEngine trans_JOIN_INNER_TD_10122185_out;
    trans_JOIN_INNER_TD_10122185_out.setq(q_h);
    q_h.finish();
    transEngine trans_Aggregate_TD_10940044;
    trans_Aggregate_TD_10940044.setq(q_a);
    trans_Aggregate_TD_10940044.add(&(cfg_Aggregate_TD_10940044_cmds));
    transEngine trans_Aggregate_TD_10940044_out;
    trans_Aggregate_TD_10940044_out.setq(q_a);
    q_a.finish();
    transEngine trans_JOIN_INNER_TD_10548299;
    trans_JOIN_INNER_TD_10548299.setq(q_h);
    trans_JOIN_INNER_TD_10548299.add(&(cfg_JOIN_INNER_TD_10548299_cmds));
    transEngine trans_JOIN_INNER_TD_10548299_out;
    trans_JOIN_INNER_TD_10548299_out.setq(q_h);
    q_h.finish();
    transEngine trans_Aggregate_TD_10779337;
    trans_Aggregate_TD_10779337.setq(q_a);
    trans_Aggregate_TD_10779337.add(&(cfg_Aggregate_TD_10779337_cmds));
    transEngine trans_Aggregate_TD_10779337_out;
    trans_Aggregate_TD_10779337_out.setq(q_a);
    q_a.finish();
    transEngine trans_JOIN_INNER_TD_10979249;
    trans_JOIN_INNER_TD_10979249.setq(q_h);
    trans_JOIN_INNER_TD_10979249.add(&(cfg_JOIN_INNER_TD_10979249_cmds));
    transEngine trans_JOIN_INNER_TD_10979249_out;
    trans_JOIN_INNER_TD_10979249_out.setq(q_h);
    q_h.finish();
    transEngine trans_Aggregate_TD_10114900;
    trans_Aggregate_TD_10114900.setq(q_a);
    trans_Aggregate_TD_10114900.add(&(cfg_Aggregate_TD_10114900_cmds));
    transEngine trans_Aggregate_TD_10114900_out;
    trans_Aggregate_TD_10114900_out.setq(q_a);
    q_a.finish();
    transEngine trans_JOIN_INNER_TD_10264341;
    trans_JOIN_INNER_TD_10264341.setq(q_h);
    trans_JOIN_INNER_TD_10264341.add(&(cfg_JOIN_INNER_TD_10264341_cmds));
    transEngine trans_JOIN_INNER_TD_10264341_out;
    trans_JOIN_INNER_TD_10264341_out.setq(q_h);
    q_h.finish();
    transEngine trans_Aggregate_TD_10391355;
    trans_Aggregate_TD_10391355.setq(q_a);
    trans_Aggregate_TD_10391355.add(&(cfg_Aggregate_TD_10391355_cmds));
    transEngine trans_Aggregate_TD_10391355_out;
    trans_Aggregate_TD_10391355_out.setq(q_a);
    q_a.finish();
    transEngine trans_JOIN_INNER_TD_1137987;
    trans_JOIN_INNER_TD_1137987.setq(q_h);
    trans_JOIN_INNER_TD_1137987.add(&(cfg_JOIN_INNER_TD_1137987_cmds));
    transEngine trans_JOIN_INNER_TD_1137987_out;
    trans_JOIN_INNER_TD_1137987_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_11161751;
    trans_JOIN_INNER_TD_11161751.setq(q_h);
    trans_JOIN_INNER_TD_11161751.add(&(cfg_JOIN_INNER_TD_11161751_cmds));
    transEngine trans_JOIN_INNER_TD_11161751_out;
    trans_JOIN_INNER_TD_11161751_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_11586348;
    trans_JOIN_INNER_TD_11586348.setq(q_h);
    trans_JOIN_INNER_TD_11586348.add(&(cfg_JOIN_INNER_TD_11586348_cmds));
    transEngine trans_JOIN_INNER_TD_11586348_out;
    trans_JOIN_INNER_TD_11586348_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_11391199;
    trans_JOIN_INNER_TD_11391199.setq(q_h);
    trans_JOIN_INNER_TD_11391199.add(&(cfg_JOIN_INNER_TD_11391199_cmds));
    transEngine trans_JOIN_INNER_TD_11391199_out;
    trans_JOIN_INNER_TD_11391199_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_12481484;
    trans_JOIN_INNER_TD_12481484.setq(q_h);
    trans_JOIN_INNER_TD_12481484.add(&(cfg_JOIN_INNER_TD_12481484_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_12552462;
    trans_JOIN_INNER_TD_12552462.setq(q_h);
    trans_JOIN_INNER_TD_12552462.add(&(cfg_JOIN_INNER_TD_12552462_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_12732934;
    trans_JOIN_INNER_TD_12732934.setq(q_h);
    trans_JOIN_INNER_TD_12732934.add(&(cfg_JOIN_INNER_TD_12732934_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_12149137;
    trans_JOIN_INNER_TD_12149137.setq(q_h);
    trans_JOIN_INNER_TD_12149137.add(&(cfg_JOIN_INNER_TD_12149137_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_13287355;
    trans_JOIN_INNER_TD_13287355.setq(q_h);
    trans_JOIN_INNER_TD_13287355.add(&(cfg_JOIN_INNER_TD_13287355_cmds));
    transEngine trans_JOIN_INNER_TD_13287355_out;
    trans_JOIN_INNER_TD_13287355_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_13942914;
    trans_JOIN_INNER_TD_13942914.setq(q_h);
    trans_JOIN_INNER_TD_13942914.add(&(cfg_JOIN_INNER_TD_13942914_cmds));
    transEngine trans_JOIN_INNER_TD_13942914_out;
    trans_JOIN_INNER_TD_13942914_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_7619982;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_7619982;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_7619982;
    events_h2d_wr_JOIN_LEFTSEMI_TD_7619982.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_7619982.resize(1);
    events_JOIN_LEFTSEMI_TD_7619982.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_7619982;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_7619982;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_7552478;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_7552478;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_7552478;
    events_h2d_wr_JOIN_LEFTSEMI_TD_7552478.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_7552478.resize(1);
    events_JOIN_LEFTSEMI_TD_7552478.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_7552478;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_7552478;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_8187296;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_8187296;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_8187296;
    events_h2d_wr_JOIN_LEFTSEMI_TD_8187296.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_8187296.resize(1);
    events_JOIN_LEFTSEMI_TD_8187296.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_8187296;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_8187296;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_8435885;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_8435885;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_8435885;
    events_h2d_wr_JOIN_LEFTSEMI_TD_8435885.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_8435885.resize(1);
    events_JOIN_LEFTSEMI_TD_8435885.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_8435885;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_8435885;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_9241296;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_9241296;
    std::vector<cl::Event> events_Aggregate_TD_9241296;
    events_h2d_wr_Aggregate_TD_9241296.resize(1);
    events_d2h_rd_Aggregate_TD_9241296.resize(1);
    events_Aggregate_TD_9241296.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_9241296;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_9241296;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_9394832;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_9394832;
    std::vector<cl::Event> events_Aggregate_TD_9394832;
    events_h2d_wr_Aggregate_TD_9394832.resize(1);
    events_d2h_rd_Aggregate_TD_9394832.resize(1);
    events_Aggregate_TD_9394832.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_9394832;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_9394832;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_9948690;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_9948690;
    std::vector<cl::Event> events_Aggregate_TD_9948690;
    events_h2d_wr_Aggregate_TD_9948690.resize(1);
    events_d2h_rd_Aggregate_TD_9948690.resize(1);
    events_Aggregate_TD_9948690.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_9948690;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_9948690;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_9533960;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_9533960;
    std::vector<cl::Event> events_Aggregate_TD_9533960;
    events_h2d_wr_Aggregate_TD_9533960.resize(1);
    events_d2h_rd_Aggregate_TD_9533960.resize(1);
    events_Aggregate_TD_9533960.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_9533960;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_9533960;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_10122185;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_10122185;
    std::vector<cl::Event> events_JOIN_INNER_TD_10122185;
    events_h2d_wr_JOIN_INNER_TD_10122185.resize(1);
    events_d2h_rd_JOIN_INNER_TD_10122185.resize(1);
    events_JOIN_INNER_TD_10122185.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_10122185;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_10122185;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_10940044;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_10940044;
    std::vector<cl::Event> events_Aggregate_TD_10940044;
    events_h2d_wr_Aggregate_TD_10940044.resize(1);
    events_d2h_rd_Aggregate_TD_10940044.resize(1);
    events_Aggregate_TD_10940044.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_10940044;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_10940044;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_10548299;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_10548299;
    std::vector<cl::Event> events_JOIN_INNER_TD_10548299;
    events_h2d_wr_JOIN_INNER_TD_10548299.resize(1);
    events_d2h_rd_JOIN_INNER_TD_10548299.resize(1);
    events_JOIN_INNER_TD_10548299.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_10548299;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_10548299;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_10779337;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_10779337;
    std::vector<cl::Event> events_Aggregate_TD_10779337;
    events_h2d_wr_Aggregate_TD_10779337.resize(1);
    events_d2h_rd_Aggregate_TD_10779337.resize(1);
    events_Aggregate_TD_10779337.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_10779337;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_10779337;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_10979249;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_10979249;
    std::vector<cl::Event> events_JOIN_INNER_TD_10979249;
    events_h2d_wr_JOIN_INNER_TD_10979249.resize(1);
    events_d2h_rd_JOIN_INNER_TD_10979249.resize(1);
    events_JOIN_INNER_TD_10979249.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_10979249;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_10979249;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_10114900;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_10114900;
    std::vector<cl::Event> events_Aggregate_TD_10114900;
    events_h2d_wr_Aggregate_TD_10114900.resize(1);
    events_d2h_rd_Aggregate_TD_10114900.resize(1);
    events_Aggregate_TD_10114900.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_10114900;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_10114900;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_10264341;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_10264341;
    std::vector<cl::Event> events_JOIN_INNER_TD_10264341;
    events_h2d_wr_JOIN_INNER_TD_10264341.resize(1);
    events_d2h_rd_JOIN_INNER_TD_10264341.resize(1);
    events_JOIN_INNER_TD_10264341.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_10264341;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_10264341;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_10391355;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_10391355;
    std::vector<cl::Event> events_Aggregate_TD_10391355;
    events_h2d_wr_Aggregate_TD_10391355.resize(1);
    events_d2h_rd_Aggregate_TD_10391355.resize(1);
    events_Aggregate_TD_10391355.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_10391355;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_10391355;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_1137987;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_1137987;
    std::vector<cl::Event> events_JOIN_INNER_TD_1137987;
    events_h2d_wr_JOIN_INNER_TD_1137987.resize(1);
    events_d2h_rd_JOIN_INNER_TD_1137987.resize(1);
    events_JOIN_INNER_TD_1137987.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_1137987;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_1137987;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_11161751;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_11161751;
    std::vector<cl::Event> events_JOIN_INNER_TD_11161751;
    events_h2d_wr_JOIN_INNER_TD_11161751.resize(1);
    events_d2h_rd_JOIN_INNER_TD_11161751.resize(1);
    events_JOIN_INNER_TD_11161751.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_11161751;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_11161751;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_11586348;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_11586348;
    std::vector<cl::Event> events_JOIN_INNER_TD_11586348;
    events_h2d_wr_JOIN_INNER_TD_11586348.resize(1);
    events_d2h_rd_JOIN_INNER_TD_11586348.resize(1);
    events_JOIN_INNER_TD_11586348.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_11586348;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_11586348;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_11391199;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_11391199;
    std::vector<cl::Event> events_JOIN_INNER_TD_11391199;
    events_h2d_wr_JOIN_INNER_TD_11391199.resize(1);
    events_d2h_rd_JOIN_INNER_TD_11391199.resize(1);
    events_JOIN_INNER_TD_11391199.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_11391199;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_11391199;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_12481484;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_12481484;
    std::vector<cl::Event> events_JOIN_INNER_TD_12481484;
    events_h2d_wr_JOIN_INNER_TD_12481484.resize(1);
    events_d2h_rd_JOIN_INNER_TD_12481484.resize(1);
    events_JOIN_INNER_TD_12481484.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_12481484;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_12481484;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_12552462;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_12552462;
    std::vector<cl::Event> events_JOIN_INNER_TD_12552462;
    events_h2d_wr_JOIN_INNER_TD_12552462.resize(1);
    events_d2h_rd_JOIN_INNER_TD_12552462.resize(1);
    events_JOIN_INNER_TD_12552462.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_12552462;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_12552462;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_12732934;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_12732934;
    std::vector<cl::Event> events_JOIN_INNER_TD_12732934;
    events_h2d_wr_JOIN_INNER_TD_12732934.resize(1);
    events_d2h_rd_JOIN_INNER_TD_12732934.resize(1);
    events_JOIN_INNER_TD_12732934.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_12732934;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_12732934;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_12149137;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_12149137;
    std::vector<cl::Event> events_JOIN_INNER_TD_12149137;
    events_h2d_wr_JOIN_INNER_TD_12149137.resize(1);
    events_d2h_rd_JOIN_INNER_TD_12149137.resize(1);
    events_JOIN_INNER_TD_12149137.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_12149137;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_12149137;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_13287355;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_13287355;
    std::vector<cl::Event> events_JOIN_INNER_TD_13287355;
    events_h2d_wr_JOIN_INNER_TD_13287355.resize(1);
    events_d2h_rd_JOIN_INNER_TD_13287355.resize(1);
    events_JOIN_INNER_TD_13287355.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_13287355;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_13287355;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_13942914;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_13942914;
    std::vector<cl::Event> events_JOIN_INNER_TD_13942914;
    events_h2d_wr_JOIN_INNER_TD_13942914.resize(1);
    events_d2h_rd_JOIN_INNER_TD_13942914.resize(1);
    events_JOIN_INNER_TD_13942914.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_13942914;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_13942914;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_14_876067_s, tv_r_Filter_14_876067_e;
    gettimeofday(&tv_r_Filter_14_876067_s, 0);
    SW_Filter_TD_14399817(tbl_SerializeFromObject_TD_15662963_input, tbl_Filter_TD_14399817_output);
    gettimeofday(&tv_r_Filter_14_876067_e, 0);

    struct timeval tv_r_Filter_14_409491_s, tv_r_Filter_14_409491_e;
    gettimeofday(&tv_r_Filter_14_409491_s, 0);
    SW_Filter_TD_14407716(tbl_SerializeFromObject_TD_15445630_input, tbl_Filter_TD_14407716_output);
    gettimeofday(&tv_r_Filter_14_409491_e, 0);

    struct timeval tv_r_Filter_14_704742_s, tv_r_Filter_14_704742_e;
    gettimeofday(&tv_r_Filter_14_704742_s, 0);
    SW_Filter_TD_14165006(tbl_SerializeFromObject_TD_15216586_input, tbl_Filter_TD_14165006_output);
    gettimeofday(&tv_r_Filter_14_704742_e, 0);

    struct timeval tv_r_Filter_14_200064_s, tv_r_Filter_14_200064_e;
    gettimeofday(&tv_r_Filter_14_200064_s, 0);
    SW_Filter_TD_14640872(tbl_SerializeFromObject_TD_15306391_input, tbl_Filter_TD_14640872_output);
    gettimeofday(&tv_r_Filter_14_200064_e, 0);

    struct timeval tv_r_Filter_13_27231_s, tv_r_Filter_13_27231_e;
    gettimeofday(&tv_r_Filter_13_27231_s, 0);
    SW_Filter_TD_13452877(tbl_SerializeFromObject_TD_14255064_input, tbl_Filter_TD_13452877_output);
    gettimeofday(&tv_r_Filter_13_27231_e, 0);

    struct timeval tv_r_Filter_13_609096_s, tv_r_Filter_13_609096_e;
    gettimeofday(&tv_r_Filter_13_609096_s, 0);
    SW_Filter_TD_13700909(tbl_SerializeFromObject_TD_1443236_input, tbl_Filter_TD_13700909_output);
    gettimeofday(&tv_r_Filter_13_609096_e, 0);

    struct timeval tv_r_Filter_13_999031_s, tv_r_Filter_13_999031_e;
    gettimeofday(&tv_r_Filter_13_999031_s, 0);
    SW_Filter_TD_1386041(tbl_SerializeFromObject_TD_14532305_input, tbl_Filter_TD_1386041_output);
    gettimeofday(&tv_r_Filter_13_999031_e, 0);

    struct timeval tv_r_Filter_13_875330_s, tv_r_Filter_13_875330_e;
    gettimeofday(&tv_r_Filter_13_875330_s, 0);
    SW_Filter_TD_13647399(tbl_SerializeFromObject_TD_14570327_input, tbl_Filter_TD_13647399_output);
    gettimeofday(&tv_r_Filter_13_875330_e, 0);

    struct timeval tv_r_Filter_13_371161_s, tv_r_Filter_13_371161_e;
    gettimeofday(&tv_r_Filter_13_371161_s, 0);
    SW_Filter_TD_13954360(tbl_SerializeFromObject_TD_14566612_input, tbl_Filter_TD_13954360_output);
    gettimeofday(&tv_r_Filter_13_371161_e, 0);

    struct timeval tv_r_JOIN_INNER_13_757892_s, tv_r_JOIN_INNER_13_757892_e;
    gettimeofday(&tv_r_JOIN_INNER_13_757892_s, 0);
    trans_JOIN_INNER_TD_13942914.add(&(tbl_Filter_TD_14407716_output));
    trans_JOIN_INNER_TD_13942914.add(&(tbl_Filter_TD_14399817_output));
    trans_JOIN_INNER_TD_13942914.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_13942914), &(events_h2d_wr_JOIN_INNER_TD_13942914[0]));
    events_grp_JOIN_INNER_TD_13942914.push_back(events_h2d_wr_JOIN_INNER_TD_13942914[0]);
    krnl_JOIN_INNER_TD_13942914.run(0, &(events_grp_JOIN_INNER_TD_13942914), &(events_JOIN_INNER_TD_13942914[0]));
    
    trans_JOIN_INNER_TD_13942914_out.add(&(tbl_JOIN_INNER_TD_13942914_output));
    trans_JOIN_INNER_TD_13942914_out.dev2host(0, &(events_JOIN_INNER_TD_13942914), &(events_d2h_rd_JOIN_INNER_TD_13942914[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_13_757892_e, 0);

    struct timeval tv_r_Filter_13_697167_s, tv_r_Filter_13_697167_e;
    gettimeofday(&tv_r_Filter_13_697167_s, 0);
    SW_Filter_TD_13469673(tbl_SerializeFromObject_TD_14786228_input, tbl_Filter_TD_13469673_output);
    gettimeofday(&tv_r_Filter_13_697167_e, 0);

    struct timeval tv_r_Filter_13_936276_s, tv_r_Filter_13_936276_e;
    gettimeofday(&tv_r_Filter_13_936276_s, 0);
    SW_Filter_TD_13702041(tbl_SerializeFromObject_TD_14673856_input, tbl_Filter_TD_13702041_output);
    gettimeofday(&tv_r_Filter_13_936276_e, 0);

    struct timeval tv_r_Filter_13_871554_s, tv_r_Filter_13_871554_e;
    gettimeofday(&tv_r_Filter_13_871554_s, 0);
    SW_Filter_TD_13539019(tbl_SerializeFromObject_TD_1452553_input, tbl_Filter_TD_13539019_output);
    gettimeofday(&tv_r_Filter_13_871554_e, 0);

    struct timeval tv_r_Filter_13_263699_s, tv_r_Filter_13_263699_e;
    gettimeofday(&tv_r_Filter_13_263699_s, 0);
    SW_Filter_TD_13366246(tbl_SerializeFromObject_TD_14654455_input, tbl_Filter_TD_13366246_output);
    gettimeofday(&tv_r_Filter_13_263699_e, 0);

    struct timeval tv_r_Filter_13_884641_s, tv_r_Filter_13_884641_e;
    gettimeofday(&tv_r_Filter_13_884641_s, 0);
    SW_Filter_TD_1373874(tbl_SerializeFromObject_TD_14800257_input, tbl_Filter_TD_1373874_output);
    gettimeofday(&tv_r_Filter_13_884641_e, 0);

    struct timeval tv_r_JOIN_INNER_13_931591_s, tv_r_JOIN_INNER_13_931591_e;
    gettimeofday(&tv_r_JOIN_INNER_13_931591_s, 0);
    trans_JOIN_INNER_TD_13287355.add(&(tbl_Filter_TD_14640872_output));
    trans_JOIN_INNER_TD_13287355.add(&(tbl_Filter_TD_14165006_output));
    trans_JOIN_INNER_TD_13287355.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_13287355), &(events_h2d_wr_JOIN_INNER_TD_13287355[0]));
    events_grp_JOIN_INNER_TD_13287355.push_back(events_h2d_wr_JOIN_INNER_TD_13287355[0]);
    krnl_JOIN_INNER_TD_13287355.run(0, &(events_grp_JOIN_INNER_TD_13287355), &(events_JOIN_INNER_TD_13287355[0]));
    
    trans_JOIN_INNER_TD_13287355_out.add(&(tbl_JOIN_INNER_TD_13287355_output));
    trans_JOIN_INNER_TD_13287355_out.dev2host(0, &(events_JOIN_INNER_TD_13287355), &(events_d2h_rd_JOIN_INNER_TD_13287355[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_13_931591_e, 0);

    struct timeval tv_r_Filter_12_538704_s, tv_r_Filter_12_538704_e;
    gettimeofday(&tv_r_Filter_12_538704_s, 0);
    SW_Filter_TD_12386496(tbl_SerializeFromObject_TD_13541437_input, tbl_Filter_TD_12386496_output);
    gettimeofday(&tv_r_Filter_12_538704_e, 0);

    struct timeval tv_r_JOIN_INNER_12_843426_s, tv_r_JOIN_INNER_12_843426_e;
    gettimeofday(&tv_r_JOIN_INNER_12_843426_s, 0);
    trans_JOIN_INNER_TD_12149137.add(&(tbl_Filter_TD_13700909_output));
    trans_JOIN_INNER_TD_12149137.add(&(tbl_Filter_TD_13452877_output));
    trans_JOIN_INNER_TD_12149137.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_12149137), &(events_h2d_wr_JOIN_INNER_TD_12149137[0]));
    events_grp_JOIN_INNER_TD_12149137.push_back(events_h2d_wr_JOIN_INNER_TD_12149137[0]);
    krnl_JOIN_INNER_TD_12149137.run(0, &(events_grp_JOIN_INNER_TD_12149137), &(events_JOIN_INNER_TD_12149137[0]));
    gettimeofday(&tv_r_JOIN_INNER_12_843426_e, 0);

    struct timeval tv_r_Filter_12_671723_s, tv_r_Filter_12_671723_e;
    gettimeofday(&tv_r_Filter_12_671723_s, 0);
    SW_Filter_TD_12901777(tbl_SerializeFromObject_TD_13842382_input, tbl_Filter_TD_12901777_output);
    gettimeofday(&tv_r_Filter_12_671723_e, 0);

    struct timeval tv_r_JOIN_INNER_12_500779_s, tv_r_JOIN_INNER_12_500779_e;
    gettimeofday(&tv_r_JOIN_INNER_12_500779_s, 0);
    trans_JOIN_INNER_TD_12732934.add(&(tbl_Filter_TD_13647399_output));
    trans_JOIN_INNER_TD_12732934.add(&(tbl_Filter_TD_1386041_output));
    trans_JOIN_INNER_TD_12732934.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_12732934), &(events_h2d_wr_JOIN_INNER_TD_12732934[0]));
    events_grp_JOIN_INNER_TD_12732934.push_back(events_h2d_wr_JOIN_INNER_TD_12732934[0]);
    krnl_JOIN_INNER_TD_12732934.run(0, &(events_grp_JOIN_INNER_TD_12732934), &(events_JOIN_INNER_TD_12732934[0]));
    gettimeofday(&tv_r_JOIN_INNER_12_500779_e, 0);

    struct timeval tv_r_JOIN_INNER_12_767863_s, tv_r_JOIN_INNER_12_767863_e;
    gettimeofday(&tv_r_JOIN_INNER_12_767863_s, 0);
    SW_JOIN_INNER_TD_12390969(tbl_JOIN_INNER_TD_13942914_output, tbl_Filter_TD_13954360_output, tbl_JOIN_INNER_TD_12390969_output);
    gettimeofday(&tv_r_JOIN_INNER_12_767863_e, 0);

    struct timeval tv_r_Filter_12_230263_s, tv_r_Filter_12_230263_e;
    gettimeofday(&tv_r_Filter_12_230263_s, 0);
    SW_Filter_TD_12313344(tbl_SerializeFromObject_TD_13259179_input, tbl_Filter_TD_12313344_output);
    gettimeofday(&tv_r_Filter_12_230263_e, 0);

    struct timeval tv_r_JOIN_INNER_12_611464_s, tv_r_JOIN_INNER_12_611464_e;
    gettimeofday(&tv_r_JOIN_INNER_12_611464_s, 0);
    trans_JOIN_INNER_TD_12552462.add(&(tbl_Filter_TD_13702041_output));
    trans_JOIN_INNER_TD_12552462.add(&(tbl_Filter_TD_13469673_output));
    trans_JOIN_INNER_TD_12552462.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_12552462), &(events_h2d_wr_JOIN_INNER_TD_12552462[0]));
    events_grp_JOIN_INNER_TD_12552462.push_back(events_h2d_wr_JOIN_INNER_TD_12552462[0]);
    krnl_JOIN_INNER_TD_12552462.run(0, &(events_grp_JOIN_INNER_TD_12552462), &(events_JOIN_INNER_TD_12552462[0]));
    gettimeofday(&tv_r_JOIN_INNER_12_611464_e, 0);

    struct timeval tv_r_Filter_12_997768_s, tv_r_Filter_12_997768_e;
    gettimeofday(&tv_r_Filter_12_997768_s, 0);
    SW_Filter_TD_12691562(tbl_SerializeFromObject_TD_13438014_input, tbl_Filter_TD_12691562_output);
    gettimeofday(&tv_r_Filter_12_997768_e, 0);

    struct timeval tv_r_JOIN_INNER_12_755974_s, tv_r_JOIN_INNER_12_755974_e;
    gettimeofday(&tv_r_JOIN_INNER_12_755974_s, 0);
    trans_JOIN_INNER_TD_12481484.add(&(tbl_Filter_TD_13366246_output));
    trans_JOIN_INNER_TD_12481484.add(&(tbl_Filter_TD_13539019_output));
    trans_JOIN_INNER_TD_12481484.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_12481484), &(events_h2d_wr_JOIN_INNER_TD_12481484[0]));
    events_grp_JOIN_INNER_TD_12481484.push_back(events_h2d_wr_JOIN_INNER_TD_12481484[0]);
    krnl_JOIN_INNER_TD_12481484.run(0, &(events_grp_JOIN_INNER_TD_12481484), &(events_JOIN_INNER_TD_12481484[0]));
    gettimeofday(&tv_r_JOIN_INNER_12_755974_e, 0);

    struct timeval tv_r_JOIN_INNER_12_588417_s, tv_r_JOIN_INNER_12_588417_e;
    gettimeofday(&tv_r_JOIN_INNER_12_588417_s, 0);
    SW_JOIN_INNER_TD_12731607(tbl_JOIN_INNER_TD_13287355_output, tbl_Filter_TD_1373874_output, tbl_JOIN_INNER_TD_12731607_output);
    gettimeofday(&tv_r_JOIN_INNER_12_588417_e, 0);

    struct timeval tv_r_JOIN_INNER_11_77138_s, tv_r_JOIN_INNER_11_77138_e;
    gettimeofday(&tv_r_JOIN_INNER_11_77138_s, 0);
    prev_events_grp_JOIN_INNER_TD_11391199.push_back(events_h2d_wr_JOIN_INNER_TD_12149137[0]);
    trans_JOIN_INNER_TD_11391199.add(&(tbl_Filter_TD_12386496_output));
    trans_JOIN_INNER_TD_11391199.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_11391199), &(events_h2d_wr_JOIN_INNER_TD_11391199[0]));
    events_grp_JOIN_INNER_TD_11391199.push_back(events_h2d_wr_JOIN_INNER_TD_11391199[0]);
    events_grp_JOIN_INNER_TD_11391199.push_back(events_JOIN_INNER_TD_12149137[0]);
    krnl_JOIN_INNER_TD_11391199.run(0, &(events_grp_JOIN_INNER_TD_11391199), &(events_JOIN_INNER_TD_11391199[0]));
    
    trans_JOIN_INNER_TD_11391199_out.add(&(tbl_JOIN_INNER_TD_11391199_output_preprocess));
    trans_JOIN_INNER_TD_11391199_out.dev2host(0, &(events_JOIN_INNER_TD_11391199), &(events_d2h_rd_JOIN_INNER_TD_11391199[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_11391199);
    tbl_JOIN_INNER_TD_11391199_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_11391199_output));
    gettimeofday(&tv_r_JOIN_INNER_11_77138_e, 0);

    struct timeval tv_r_Filter_11_107720_s, tv_r_Filter_11_107720_e;
    gettimeofday(&tv_r_Filter_11_107720_s, 0);
    SW_Filter_TD_11760980(tbl_SerializeFromObject_TD_12350645_input, tbl_Filter_TD_11760980_output);
    gettimeofday(&tv_r_Filter_11_107720_e, 0);

    struct timeval tv_r_Filter_11_792481_s, tv_r_Filter_11_792481_e;
    gettimeofday(&tv_r_Filter_11_792481_s, 0);
    SW_Filter_TD_11174320(tbl_SerializeFromObject_TD_12735447_input, tbl_Filter_TD_11174320_output);
    gettimeofday(&tv_r_Filter_11_792481_e, 0);

    struct timeval tv_r_JOIN_INNER_11_290121_s, tv_r_JOIN_INNER_11_290121_e;
    gettimeofday(&tv_r_JOIN_INNER_11_290121_s, 0);
    prev_events_grp_JOIN_INNER_TD_11586348.push_back(events_h2d_wr_JOIN_INNER_TD_12732934[0]);
    trans_JOIN_INNER_TD_11586348.add(&(tbl_Filter_TD_12901777_output));
    trans_JOIN_INNER_TD_11586348.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_11586348), &(events_h2d_wr_JOIN_INNER_TD_11586348[0]));
    events_grp_JOIN_INNER_TD_11586348.push_back(events_h2d_wr_JOIN_INNER_TD_11586348[0]);
    events_grp_JOIN_INNER_TD_11586348.push_back(events_JOIN_INNER_TD_12732934[0]);
    krnl_JOIN_INNER_TD_11586348.run(0, &(events_grp_JOIN_INNER_TD_11586348), &(events_JOIN_INNER_TD_11586348[0]));
    
    trans_JOIN_INNER_TD_11586348_out.add(&(tbl_JOIN_INNER_TD_11586348_output_preprocess));
    trans_JOIN_INNER_TD_11586348_out.dev2host(0, &(events_JOIN_INNER_TD_11586348), &(events_d2h_rd_JOIN_INNER_TD_11586348[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_11586348);
    tbl_JOIN_INNER_TD_11586348_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_11586348_output));
    gettimeofday(&tv_r_JOIN_INNER_11_290121_e, 0);

    struct timeval tv_r_Filter_11_256561_s, tv_r_Filter_11_256561_e;
    gettimeofday(&tv_r_Filter_11_256561_s, 0);
    SW_Filter_TD_11871505(tbl_SerializeFromObject_TD_12680534_input, tbl_Filter_TD_11871505_output);
    gettimeofday(&tv_r_Filter_11_256561_e, 0);

    struct timeval tv_r_Filter_11_241074_s, tv_r_Filter_11_241074_e;
    gettimeofday(&tv_r_Filter_11_241074_s, 0);
    SW_Filter_TD_11187752(tbl_SerializeFromObject_TD_12747514_input, tbl_Filter_TD_11187752_output);
    gettimeofday(&tv_r_Filter_11_241074_e, 0);

    struct timeval tv_r_Project_11_879959_s, tv_r_Project_11_879959_e;
    gettimeofday(&tv_r_Project_11_879959_s, 0);
    SW_Project_TD_11107252(tbl_JOIN_INNER_TD_12390969_output, tbl_Project_TD_11107252_output);
    gettimeofday(&tv_r_Project_11_879959_e, 0);

    struct timeval tv_r_JOIN_INNER_11_990152_s, tv_r_JOIN_INNER_11_990152_e;
    gettimeofday(&tv_r_JOIN_INNER_11_990152_s, 0);
    prev_events_grp_JOIN_INNER_TD_11161751.push_back(events_h2d_wr_JOIN_INNER_TD_12552462[0]);
    trans_JOIN_INNER_TD_11161751.add(&(tbl_Filter_TD_12313344_output));
    trans_JOIN_INNER_TD_11161751.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_11161751), &(events_h2d_wr_JOIN_INNER_TD_11161751[0]));
    events_grp_JOIN_INNER_TD_11161751.push_back(events_h2d_wr_JOIN_INNER_TD_11161751[0]);
    events_grp_JOIN_INNER_TD_11161751.push_back(events_JOIN_INNER_TD_12552462[0]);
    krnl_JOIN_INNER_TD_11161751.run(0, &(events_grp_JOIN_INNER_TD_11161751), &(events_JOIN_INNER_TD_11161751[0]));
    
    trans_JOIN_INNER_TD_11161751_out.add(&(tbl_JOIN_INNER_TD_11161751_output_preprocess));
    trans_JOIN_INNER_TD_11161751_out.dev2host(0, &(events_JOIN_INNER_TD_11161751), &(events_d2h_rd_JOIN_INNER_TD_11161751[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_11161751);
    tbl_JOIN_INNER_TD_11161751_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_11161751_output));
    gettimeofday(&tv_r_JOIN_INNER_11_990152_e, 0);

    struct timeval tv_r_Filter_11_500485_s, tv_r_Filter_11_500485_e;
    gettimeofday(&tv_r_Filter_11_500485_s, 0);
    SW_Filter_TD_11361028(tbl_SerializeFromObject_TD_1223068_input, tbl_Filter_TD_11361028_output);
    gettimeofday(&tv_r_Filter_11_500485_e, 0);

    struct timeval tv_r_Filter_11_216337_s, tv_r_Filter_11_216337_e;
    gettimeofday(&tv_r_Filter_11_216337_s, 0);
    SW_Filter_TD_11510993(tbl_SerializeFromObject_TD_12390145_input, tbl_Filter_TD_11510993_output);
    gettimeofday(&tv_r_Filter_11_216337_e, 0);

    struct timeval tv_r_JOIN_INNER_11_792607_s, tv_r_JOIN_INNER_11_792607_e;
    gettimeofday(&tv_r_JOIN_INNER_11_792607_s, 0);
    prev_events_grp_JOIN_INNER_TD_1137987.push_back(events_h2d_wr_JOIN_INNER_TD_12481484[0]);
    trans_JOIN_INNER_TD_1137987.add(&(tbl_Filter_TD_12691562_output));
    trans_JOIN_INNER_TD_1137987.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_1137987), &(events_h2d_wr_JOIN_INNER_TD_1137987[0]));
    events_grp_JOIN_INNER_TD_1137987.push_back(events_h2d_wr_JOIN_INNER_TD_1137987[0]);
    events_grp_JOIN_INNER_TD_1137987.push_back(events_JOIN_INNER_TD_12481484[0]);
    krnl_JOIN_INNER_TD_1137987.run(0, &(events_grp_JOIN_INNER_TD_1137987), &(events_JOIN_INNER_TD_1137987[0]));
    
    trans_JOIN_INNER_TD_1137987_out.add(&(tbl_JOIN_INNER_TD_1137987_output_preprocess));
    trans_JOIN_INNER_TD_1137987_out.dev2host(0, &(events_JOIN_INNER_TD_1137987), &(events_d2h_rd_JOIN_INNER_TD_1137987[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_1137987);
    tbl_JOIN_INNER_TD_1137987_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_1137987_output));
    gettimeofday(&tv_r_JOIN_INNER_11_792607_e, 0);

    struct timeval tv_r_Filter_11_242643_s, tv_r_Filter_11_242643_e;
    gettimeofday(&tv_r_Filter_11_242643_s, 0);
    SW_Filter_TD_11957528(tbl_SerializeFromObject_TD_12783408_input, tbl_Filter_TD_11957528_output);
    gettimeofday(&tv_r_Filter_11_242643_e, 0);

    struct timeval tv_r_Filter_11_41004_s, tv_r_Filter_11_41004_e;
    gettimeofday(&tv_r_Filter_11_41004_s, 0);
    SW_Filter_TD_11726486(tbl_SerializeFromObject_TD_12133188_input, tbl_Filter_TD_11726486_output);
    gettimeofday(&tv_r_Filter_11_41004_e, 0);

    struct timeval tv_r_Project_11_384051_s, tv_r_Project_11_384051_e;
    gettimeofday(&tv_r_Project_11_384051_s, 0);
    SW_Project_TD_11995959(tbl_JOIN_INNER_TD_12731607_output, tbl_Project_TD_11995959_output);
    gettimeofday(&tv_r_Project_11_384051_e, 0);

    struct timeval tv_r_Aggregate_10_201524_s, tv_r_Aggregate_10_201524_e;
    gettimeofday(&tv_r_Aggregate_10_201524_s, 0);
    trans_Aggregate_TD_10391355.add(&(tbl_JOIN_INNER_TD_11391199_output));
    trans_Aggregate_TD_10391355.host2dev(0, &(prev_events_grp_Aggregate_TD_10391355), &(events_h2d_wr_Aggregate_TD_10391355[0]));
    events_grp_Aggregate_TD_10391355.push_back(events_h2d_wr_Aggregate_TD_10391355[0]);
    krnl_Aggregate_TD_10391355.run(0, &(events_grp_Aggregate_TD_10391355), &(events_Aggregate_TD_10391355[0]));
    
    trans_Aggregate_TD_10391355_out.add(&(tbl_Aggregate_TD_10391355_output_preprocess));
    trans_Aggregate_TD_10391355_out.dev2host(0, &(events_Aggregate_TD_10391355), &(events_d2h_rd_Aggregate_TD_10391355[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_10391355_consolidate(tbl_Aggregate_TD_10391355_output_preprocess, tbl_Aggregate_TD_10391355_output);
    gettimeofday(&tv_r_Aggregate_10_201524_e, 0);

    struct timeval tv_r_JOIN_INNER_10_648882_s, tv_r_JOIN_INNER_10_648882_e;
    gettimeofday(&tv_r_JOIN_INNER_10_648882_s, 0);
    trans_JOIN_INNER_TD_10264341.add(&(tbl_Filter_TD_11174320_output));
    trans_JOIN_INNER_TD_10264341.add(&(tbl_Filter_TD_11760980_output));
    trans_JOIN_INNER_TD_10264341.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_10264341), &(events_h2d_wr_JOIN_INNER_TD_10264341[0]));
    events_grp_JOIN_INNER_TD_10264341.push_back(events_h2d_wr_JOIN_INNER_TD_10264341[0]);
    krnl_JOIN_INNER_TD_10264341.run(0, &(events_grp_JOIN_INNER_TD_10264341), &(events_JOIN_INNER_TD_10264341[0]));
    
    trans_JOIN_INNER_TD_10264341_out.add(&(tbl_JOIN_INNER_TD_10264341_output_preprocess));
    trans_JOIN_INNER_TD_10264341_out.dev2host(0, &(events_JOIN_INNER_TD_10264341), &(events_d2h_rd_JOIN_INNER_TD_10264341[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_10264341);
    tbl_JOIN_INNER_TD_10264341_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_10264341_output));
    gettimeofday(&tv_r_JOIN_INNER_10_648882_e, 0);

    struct timeval tv_r_Aggregate_10_321328_s, tv_r_Aggregate_10_321328_e;
    gettimeofday(&tv_r_Aggregate_10_321328_s, 0);
    trans_Aggregate_TD_10114900.add(&(tbl_JOIN_INNER_TD_11586348_output));
    trans_Aggregate_TD_10114900.host2dev(0, &(prev_events_grp_Aggregate_TD_10114900), &(events_h2d_wr_Aggregate_TD_10114900[0]));
    events_grp_Aggregate_TD_10114900.push_back(events_h2d_wr_Aggregate_TD_10114900[0]);
    krnl_Aggregate_TD_10114900.run(0, &(events_grp_Aggregate_TD_10114900), &(events_Aggregate_TD_10114900[0]));
    
    trans_Aggregate_TD_10114900_out.add(&(tbl_Aggregate_TD_10114900_output_preprocess));
    trans_Aggregate_TD_10114900_out.dev2host(0, &(events_Aggregate_TD_10114900), &(events_d2h_rd_Aggregate_TD_10114900[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_10114900_consolidate(tbl_Aggregate_TD_10114900_output_preprocess, tbl_Aggregate_TD_10114900_output);
    gettimeofday(&tv_r_Aggregate_10_321328_e, 0);

    struct timeval tv_r_JOIN_INNER_10_806349_s, tv_r_JOIN_INNER_10_806349_e;
    gettimeofday(&tv_r_JOIN_INNER_10_806349_s, 0);
    trans_JOIN_INNER_TD_10979249.add(&(tbl_Filter_TD_11187752_output));
    trans_JOIN_INNER_TD_10979249.add(&(tbl_Filter_TD_11871505_output));
    trans_JOIN_INNER_TD_10979249.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_10979249), &(events_h2d_wr_JOIN_INNER_TD_10979249[0]));
    events_grp_JOIN_INNER_TD_10979249.push_back(events_h2d_wr_JOIN_INNER_TD_10979249[0]);
    krnl_JOIN_INNER_TD_10979249.run(0, &(events_grp_JOIN_INNER_TD_10979249), &(events_JOIN_INNER_TD_10979249[0]));
    
    trans_JOIN_INNER_TD_10979249_out.add(&(tbl_JOIN_INNER_TD_10979249_output_preprocess));
    trans_JOIN_INNER_TD_10979249_out.dev2host(0, &(events_JOIN_INNER_TD_10979249), &(events_d2h_rd_JOIN_INNER_TD_10979249[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_10979249);
    tbl_JOIN_INNER_TD_10979249_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_10979249_output));
    gettimeofday(&tv_r_JOIN_INNER_10_806349_e, 0);

    struct timeval tv_r_Aggregate_10_554762_s, tv_r_Aggregate_10_554762_e;
    gettimeofday(&tv_r_Aggregate_10_554762_s, 0);
    SW_Aggregate_TD_10874103(tbl_Project_TD_11107252_output, tbl_Aggregate_TD_10874103_output);
    gettimeofday(&tv_r_Aggregate_10_554762_e, 0);

    struct timeval tv_r_Aggregate_10_340942_s, tv_r_Aggregate_10_340942_e;
    gettimeofday(&tv_r_Aggregate_10_340942_s, 0);
    trans_Aggregate_TD_10779337.add(&(tbl_JOIN_INNER_TD_11161751_output));
    trans_Aggregate_TD_10779337.host2dev(0, &(prev_events_grp_Aggregate_TD_10779337), &(events_h2d_wr_Aggregate_TD_10779337[0]));
    events_grp_Aggregate_TD_10779337.push_back(events_h2d_wr_Aggregate_TD_10779337[0]);
    krnl_Aggregate_TD_10779337.run(0, &(events_grp_Aggregate_TD_10779337), &(events_Aggregate_TD_10779337[0]));
    
    trans_Aggregate_TD_10779337_out.add(&(tbl_Aggregate_TD_10779337_output_preprocess));
    trans_Aggregate_TD_10779337_out.dev2host(0, &(events_Aggregate_TD_10779337), &(events_d2h_rd_Aggregate_TD_10779337[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_10779337_consolidate(tbl_Aggregate_TD_10779337_output_preprocess, tbl_Aggregate_TD_10779337_output);
    gettimeofday(&tv_r_Aggregate_10_340942_e, 0);

    struct timeval tv_r_JOIN_INNER_10_499920_s, tv_r_JOIN_INNER_10_499920_e;
    gettimeofday(&tv_r_JOIN_INNER_10_499920_s, 0);
    trans_JOIN_INNER_TD_10548299.add(&(tbl_Filter_TD_11510993_output));
    trans_JOIN_INNER_TD_10548299.add(&(tbl_Filter_TD_11361028_output));
    trans_JOIN_INNER_TD_10548299.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_10548299), &(events_h2d_wr_JOIN_INNER_TD_10548299[0]));
    events_grp_JOIN_INNER_TD_10548299.push_back(events_h2d_wr_JOIN_INNER_TD_10548299[0]);
    krnl_JOIN_INNER_TD_10548299.run(0, &(events_grp_JOIN_INNER_TD_10548299), &(events_JOIN_INNER_TD_10548299[0]));
    
    trans_JOIN_INNER_TD_10548299_out.add(&(tbl_JOIN_INNER_TD_10548299_output_preprocess));
    trans_JOIN_INNER_TD_10548299_out.dev2host(0, &(events_JOIN_INNER_TD_10548299), &(events_d2h_rd_JOIN_INNER_TD_10548299[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_10548299);
    tbl_JOIN_INNER_TD_10548299_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_10548299_output));
    gettimeofday(&tv_r_JOIN_INNER_10_499920_e, 0);

    struct timeval tv_r_Aggregate_10_720764_s, tv_r_Aggregate_10_720764_e;
    gettimeofday(&tv_r_Aggregate_10_720764_s, 0);
    trans_Aggregate_TD_10940044.add(&(tbl_JOIN_INNER_TD_1137987_output));
    trans_Aggregate_TD_10940044.host2dev(0, &(prev_events_grp_Aggregate_TD_10940044), &(events_h2d_wr_Aggregate_TD_10940044[0]));
    events_grp_Aggregate_TD_10940044.push_back(events_h2d_wr_Aggregate_TD_10940044[0]);
    krnl_Aggregate_TD_10940044.run(0, &(events_grp_Aggregate_TD_10940044), &(events_Aggregate_TD_10940044[0]));
    
    trans_Aggregate_TD_10940044_out.add(&(tbl_Aggregate_TD_10940044_output_preprocess));
    trans_Aggregate_TD_10940044_out.dev2host(0, &(events_Aggregate_TD_10940044), &(events_d2h_rd_Aggregate_TD_10940044[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_10940044_consolidate(tbl_Aggregate_TD_10940044_output_preprocess, tbl_Aggregate_TD_10940044_output);
    gettimeofday(&tv_r_Aggregate_10_720764_e, 0);

    struct timeval tv_r_JOIN_INNER_10_700459_s, tv_r_JOIN_INNER_10_700459_e;
    gettimeofday(&tv_r_JOIN_INNER_10_700459_s, 0);
    trans_JOIN_INNER_TD_10122185.add(&(tbl_Filter_TD_11726486_output));
    trans_JOIN_INNER_TD_10122185.add(&(tbl_Filter_TD_11957528_output));
    trans_JOIN_INNER_TD_10122185.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_10122185), &(events_h2d_wr_JOIN_INNER_TD_10122185[0]));
    events_grp_JOIN_INNER_TD_10122185.push_back(events_h2d_wr_JOIN_INNER_TD_10122185[0]);
    krnl_JOIN_INNER_TD_10122185.run(0, &(events_grp_JOIN_INNER_TD_10122185), &(events_JOIN_INNER_TD_10122185[0]));
    
    trans_JOIN_INNER_TD_10122185_out.add(&(tbl_JOIN_INNER_TD_10122185_output_preprocess));
    trans_JOIN_INNER_TD_10122185_out.dev2host(0, &(events_JOIN_INNER_TD_10122185), &(events_d2h_rd_JOIN_INNER_TD_10122185[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_INNER_TD_10122185);
    tbl_JOIN_INNER_TD_10122185_output_preprocess.copyTableData(&(tbl_JOIN_INNER_TD_10122185_output));
    gettimeofday(&tv_r_JOIN_INNER_10_700459_e, 0);

    struct timeval tv_r_Aggregate_10_786632_s, tv_r_Aggregate_10_786632_e;
    gettimeofday(&tv_r_Aggregate_10_786632_s, 0);
    SW_Aggregate_TD_10150991(tbl_Project_TD_11995959_output, tbl_Aggregate_TD_10150991_output);
    gettimeofday(&tv_r_Aggregate_10_786632_e, 0);

    struct timeval tv_r_Aggregate_9_525801_s, tv_r_Aggregate_9_525801_e;
    gettimeofday(&tv_r_Aggregate_9_525801_s, 0);
    SW_Aggregate_TD_9116253(tbl_Aggregate_TD_10391355_output, tbl_Aggregate_TD_9116253_output);
    gettimeofday(&tv_r_Aggregate_9_525801_e, 0);

    struct timeval tv_r_Aggregate_9_819814_s, tv_r_Aggregate_9_819814_e;
    gettimeofday(&tv_r_Aggregate_9_819814_s, 0);
    trans_Aggregate_TD_9533960.add(&(tbl_JOIN_INNER_TD_10264341_output));
    trans_Aggregate_TD_9533960.host2dev(0, &(prev_events_grp_Aggregate_TD_9533960), &(events_h2d_wr_Aggregate_TD_9533960[0]));
    events_grp_Aggregate_TD_9533960.push_back(events_h2d_wr_Aggregate_TD_9533960[0]);
    krnl_Aggregate_TD_9533960.run(0, &(events_grp_Aggregate_TD_9533960), &(events_Aggregate_TD_9533960[0]));
    
    trans_Aggregate_TD_9533960_out.add(&(tbl_Aggregate_TD_9533960_output_preprocess));
    trans_Aggregate_TD_9533960_out.dev2host(0, &(events_Aggregate_TD_9533960), &(events_d2h_rd_Aggregate_TD_9533960[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_9533960_consolidate(tbl_Aggregate_TD_9533960_output_preprocess, tbl_Aggregate_TD_9533960_output);
    gettimeofday(&tv_r_Aggregate_9_819814_e, 0);

    struct timeval tv_r_Aggregate_9_580083_s, tv_r_Aggregate_9_580083_e;
    gettimeofday(&tv_r_Aggregate_9_580083_s, 0);
    SW_Aggregate_TD_9132965(tbl_Aggregate_TD_10114900_output, tbl_Aggregate_TD_9132965_output);
    gettimeofday(&tv_r_Aggregate_9_580083_e, 0);

    struct timeval tv_r_Aggregate_9_385894_s, tv_r_Aggregate_9_385894_e;
    gettimeofday(&tv_r_Aggregate_9_385894_s, 0);
    trans_Aggregate_TD_9948690.add(&(tbl_JOIN_INNER_TD_10979249_output));
    trans_Aggregate_TD_9948690.host2dev(0, &(prev_events_grp_Aggregate_TD_9948690), &(events_h2d_wr_Aggregate_TD_9948690[0]));
    events_grp_Aggregate_TD_9948690.push_back(events_h2d_wr_Aggregate_TD_9948690[0]);
    krnl_Aggregate_TD_9948690.run(0, &(events_grp_Aggregate_TD_9948690), &(events_Aggregate_TD_9948690[0]));
    
    trans_Aggregate_TD_9948690_out.add(&(tbl_Aggregate_TD_9948690_output_preprocess));
    trans_Aggregate_TD_9948690_out.dev2host(0, &(events_Aggregate_TD_9948690), &(events_d2h_rd_Aggregate_TD_9948690[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_9948690_consolidate(tbl_Aggregate_TD_9948690_output_preprocess, tbl_Aggregate_TD_9948690_output);
    gettimeofday(&tv_r_Aggregate_9_385894_e, 0);

    struct timeval tv_r_Filter_9_726145_s, tv_r_Filter_9_726145_e;
    gettimeofday(&tv_r_Filter_9_726145_s, 0);
    SW_Filter_TD_9735928(tbl_Aggregate_TD_10874103_output, tbl_Filter_TD_9735928_output);
    gettimeofday(&tv_r_Filter_9_726145_e, 0);

    struct timeval tv_r_Filter_9_37375_s, tv_r_Filter_9_37375_e;
    gettimeofday(&tv_r_Filter_9_37375_s, 0);
    SW_Filter_TD_9697381(tbl_SerializeFromObject_TD_10269486_input, tbl_Filter_TD_9697381_output);
    gettimeofday(&tv_r_Filter_9_37375_e, 0);

    struct timeval tv_r_Aggregate_9_199972_s, tv_r_Aggregate_9_199972_e;
    gettimeofday(&tv_r_Aggregate_9_199972_s, 0);
    SW_Aggregate_TD_9773538(tbl_Aggregate_TD_10779337_output, tbl_Aggregate_TD_9773538_output);
    gettimeofday(&tv_r_Aggregate_9_199972_e, 0);

    struct timeval tv_r_Aggregate_9_322280_s, tv_r_Aggregate_9_322280_e;
    gettimeofday(&tv_r_Aggregate_9_322280_s, 0);
    trans_Aggregate_TD_9394832.add(&(tbl_JOIN_INNER_TD_10548299_output));
    trans_Aggregate_TD_9394832.host2dev(0, &(prev_events_grp_Aggregate_TD_9394832), &(events_h2d_wr_Aggregate_TD_9394832[0]));
    events_grp_Aggregate_TD_9394832.push_back(events_h2d_wr_Aggregate_TD_9394832[0]);
    krnl_Aggregate_TD_9394832.run(0, &(events_grp_Aggregate_TD_9394832), &(events_Aggregate_TD_9394832[0]));
    
    trans_Aggregate_TD_9394832_out.add(&(tbl_Aggregate_TD_9394832_output_preprocess));
    trans_Aggregate_TD_9394832_out.dev2host(0, &(events_Aggregate_TD_9394832), &(events_d2h_rd_Aggregate_TD_9394832[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_9394832_consolidate(tbl_Aggregate_TD_9394832_output_preprocess, tbl_Aggregate_TD_9394832_output);
    gettimeofday(&tv_r_Aggregate_9_322280_e, 0);

    struct timeval tv_r_Aggregate_9_630128_s, tv_r_Aggregate_9_630128_e;
    gettimeofday(&tv_r_Aggregate_9_630128_s, 0);
    SW_Aggregate_TD_9707922(tbl_Aggregate_TD_10940044_output, tbl_Aggregate_TD_9707922_output);
    gettimeofday(&tv_r_Aggregate_9_630128_e, 0);

    struct timeval tv_r_Aggregate_9_368104_s, tv_r_Aggregate_9_368104_e;
    gettimeofday(&tv_r_Aggregate_9_368104_s, 0);
    trans_Aggregate_TD_9241296.add(&(tbl_JOIN_INNER_TD_10122185_output));
    trans_Aggregate_TD_9241296.host2dev(0, &(prev_events_grp_Aggregate_TD_9241296), &(events_h2d_wr_Aggregate_TD_9241296[0]));
    events_grp_Aggregate_TD_9241296.push_back(events_h2d_wr_Aggregate_TD_9241296[0]);
    krnl_Aggregate_TD_9241296.run(0, &(events_grp_Aggregate_TD_9241296), &(events_Aggregate_TD_9241296[0]));
    
    trans_Aggregate_TD_9241296_out.add(&(tbl_Aggregate_TD_9241296_output_preprocess));
    trans_Aggregate_TD_9241296_out.dev2host(0, &(events_Aggregate_TD_9241296), &(events_d2h_rd_Aggregate_TD_9241296[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_9241296_consolidate(tbl_Aggregate_TD_9241296_output_preprocess, tbl_Aggregate_TD_9241296_output);
    gettimeofday(&tv_r_Aggregate_9_368104_e, 0);

    struct timeval tv_r_Filter_9_764903_s, tv_r_Filter_9_764903_e;
    gettimeofday(&tv_r_Filter_9_764903_s, 0);
    SW_Filter_TD_9527090(tbl_Aggregate_TD_10150991_output, tbl_Filter_TD_9527090_output);
    gettimeofday(&tv_r_Filter_9_764903_e, 0);

    struct timeval tv_r_Filter_9_458425_s, tv_r_Filter_9_458425_e;
    gettimeofday(&tv_r_Filter_9_458425_s, 0);
    SW_Filter_TD_9849852(tbl_SerializeFromObject_TD_10110473_input, tbl_Filter_TD_9849852_output);
    gettimeofday(&tv_r_Filter_9_458425_e, 0);

    struct timeval tv_r_Filter_8_274476_s, tv_r_Filter_8_274476_e;
    gettimeofday(&tv_r_Filter_8_274476_s, 0);
    SW_Filter_TD_8101406(tbl_Aggregate_TD_9533960_output, tbl_Aggregate_TD_9116253_output, tbl_Filter_TD_8101406_output);
    gettimeofday(&tv_r_Filter_8_274476_e, 0);

    struct timeval tv_r_Filter_8_292209_s, tv_r_Filter_8_292209_e;
    gettimeofday(&tv_r_Filter_8_292209_s, 0);
    SW_Filter_TD_8166631(tbl_SerializeFromObject_TD_9255648_input, tbl_Filter_TD_8166631_output);
    gettimeofday(&tv_r_Filter_8_292209_e, 0);

    struct timeval tv_r_Filter_8_676768_s, tv_r_Filter_8_676768_e;
    gettimeofday(&tv_r_Filter_8_676768_s, 0);
    SW_Filter_TD_8261746(tbl_Aggregate_TD_9948690_output, tbl_Aggregate_TD_9132965_output, tbl_Filter_TD_8261746_output);
    gettimeofday(&tv_r_Filter_8_676768_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_8_813185_s, tv_r_JOIN_LEFTSEMI_8_813185_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_8_813185_s, 0);
    trans_JOIN_LEFTSEMI_TD_8435885.add(&(tbl_Filter_TD_9697381_output));
    trans_JOIN_LEFTSEMI_TD_8435885.add(&(tbl_Filter_TD_9735928_output));
    trans_JOIN_LEFTSEMI_TD_8435885.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_8435885), &(events_h2d_wr_JOIN_LEFTSEMI_TD_8435885[0]));
    events_grp_JOIN_LEFTSEMI_TD_8435885.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_8435885[0]);
    krnl_JOIN_LEFTSEMI_TD_8435885.run(0, &(events_grp_JOIN_LEFTSEMI_TD_8435885), &(events_JOIN_LEFTSEMI_TD_8435885[0]));
    gettimeofday(&tv_r_JOIN_LEFTSEMI_8_813185_e, 0);

    struct timeval tv_r_Filter_8_649519_s, tv_r_Filter_8_649519_e;
    gettimeofday(&tv_r_Filter_8_649519_s, 0);
    SW_Filter_TD_8479531(tbl_Aggregate_TD_9394832_output, tbl_Aggregate_TD_9773538_output, tbl_Filter_TD_8479531_output);
    gettimeofday(&tv_r_Filter_8_649519_e, 0);

    struct timeval tv_r_Filter_8_185727_s, tv_r_Filter_8_185727_e;
    gettimeofday(&tv_r_Filter_8_185727_s, 0);
    SW_Filter_TD_8727146(tbl_SerializeFromObject_TD_9246457_input, tbl_Filter_TD_8727146_output);
    gettimeofday(&tv_r_Filter_8_185727_e, 0);

    struct timeval tv_r_Filter_8_511660_s, tv_r_Filter_8_511660_e;
    gettimeofday(&tv_r_Filter_8_511660_s, 0);
    SW_Filter_TD_8434144(tbl_Aggregate_TD_9241296_output, tbl_Aggregate_TD_9707922_output, tbl_Filter_TD_8434144_output);
    gettimeofday(&tv_r_Filter_8_511660_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_8_546135_s, tv_r_JOIN_LEFTSEMI_8_546135_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_8_546135_s, 0);
    trans_JOIN_LEFTSEMI_TD_8187296.add(&(tbl_Filter_TD_9849852_output));
    trans_JOIN_LEFTSEMI_TD_8187296.add(&(tbl_Filter_TD_9527090_output));
    trans_JOIN_LEFTSEMI_TD_8187296.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_8187296), &(events_h2d_wr_JOIN_LEFTSEMI_TD_8187296[0]));
    events_grp_JOIN_LEFTSEMI_TD_8187296.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_8187296[0]);
    krnl_JOIN_LEFTSEMI_TD_8187296.run(0, &(events_grp_JOIN_LEFTSEMI_TD_8187296), &(events_JOIN_LEFTSEMI_TD_8187296[0]));
    gettimeofday(&tv_r_JOIN_LEFTSEMI_8_546135_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_7_624647_s, tv_r_JOIN_LEFTSEMI_7_624647_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_624647_s, 0);
    SW_JOIN_LEFTSEMI_TD_7221819(tbl_Filter_TD_8166631_output, tbl_Filter_TD_8101406_output, tbl_JOIN_LEFTSEMI_TD_7221819_output);
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_624647_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_7_387529_s, tv_r_JOIN_LEFTSEMI_7_387529_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_387529_s, 0);
    prev_events_grp_JOIN_LEFTSEMI_TD_7552478.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_8435885[0]);
    trans_JOIN_LEFTSEMI_TD_7552478.add(&(tbl_Filter_TD_8261746_output));
    trans_JOIN_LEFTSEMI_TD_7552478.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_7552478), &(events_h2d_wr_JOIN_LEFTSEMI_TD_7552478[0]));
    events_grp_JOIN_LEFTSEMI_TD_7552478.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_7552478[0]);
    events_grp_JOIN_LEFTSEMI_TD_7552478.push_back(events_JOIN_LEFTSEMI_TD_8435885[0]);
    krnl_JOIN_LEFTSEMI_TD_7552478.run(0, &(events_grp_JOIN_LEFTSEMI_TD_7552478), &(events_JOIN_LEFTSEMI_TD_7552478[0]));
    
    trans_JOIN_LEFTSEMI_TD_7552478_out.add(&(tbl_JOIN_LEFTSEMI_TD_7552478_output));
    trans_JOIN_LEFTSEMI_TD_7552478_out.dev2host(0, &(events_JOIN_LEFTSEMI_TD_7552478), &(events_d2h_rd_JOIN_LEFTSEMI_TD_7552478[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_387529_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_7_904186_s, tv_r_JOIN_LEFTSEMI_7_904186_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_904186_s, 0);
    SW_JOIN_LEFTSEMI_TD_7493952(tbl_Filter_TD_8727146_output, tbl_Filter_TD_8479531_output, tbl_JOIN_LEFTSEMI_TD_7493952_output);
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_904186_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_7_616724_s, tv_r_JOIN_LEFTSEMI_7_616724_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_616724_s, 0);
    prev_events_grp_JOIN_LEFTSEMI_TD_7619982.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_8187296[0]);
    trans_JOIN_LEFTSEMI_TD_7619982.add(&(tbl_Filter_TD_8434144_output));
    trans_JOIN_LEFTSEMI_TD_7619982.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_7619982), &(events_h2d_wr_JOIN_LEFTSEMI_TD_7619982[0]));
    events_grp_JOIN_LEFTSEMI_TD_7619982.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_7619982[0]);
    events_grp_JOIN_LEFTSEMI_TD_7619982.push_back(events_JOIN_LEFTSEMI_TD_8187296[0]);
    krnl_JOIN_LEFTSEMI_TD_7619982.run(0, &(events_grp_JOIN_LEFTSEMI_TD_7619982), &(events_JOIN_LEFTSEMI_TD_7619982[0]));
    
    trans_JOIN_LEFTSEMI_TD_7619982_out.add(&(tbl_JOIN_LEFTSEMI_TD_7619982_output));
    trans_JOIN_LEFTSEMI_TD_7619982_out.dev2host(0, &(events_JOIN_LEFTSEMI_TD_7619982), &(events_d2h_rd_JOIN_LEFTSEMI_TD_7619982[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_616724_e, 0);

    struct timeval tv_r_Filter_6_501626_s, tv_r_Filter_6_501626_e;
    gettimeofday(&tv_r_Filter_6_501626_s, 0);
    SW_Filter_TD_659084(tbl_SerializeFromObject_TD_7703945_input, tbl_Filter_TD_659084_output);
    gettimeofday(&tv_r_Filter_6_501626_e, 0);

    struct timeval tv_r_JOIN_INNER_6_35324_s, tv_r_JOIN_INNER_6_35324_e;
    gettimeofday(&tv_r_JOIN_INNER_6_35324_s, 0);
    SW_JOIN_INNER_TD_6288197(tbl_JOIN_LEFTSEMI_TD_7552478_output, tbl_JOIN_LEFTSEMI_TD_7221819_output, tbl_JOIN_INNER_TD_6288197_output);
    gettimeofday(&tv_r_JOIN_INNER_6_35324_e, 0);

    struct timeval tv_r_Filter_6_431875_s, tv_r_Filter_6_431875_e;
    gettimeofday(&tv_r_Filter_6_431875_s, 0);
    SW_Filter_TD_6729719(tbl_SerializeFromObject_TD_7253164_input, tbl_Filter_TD_6729719_output);
    gettimeofday(&tv_r_Filter_6_431875_e, 0);

    struct timeval tv_r_JOIN_INNER_6_452163_s, tv_r_JOIN_INNER_6_452163_e;
    gettimeofday(&tv_r_JOIN_INNER_6_452163_s, 0);
    SW_JOIN_INNER_TD_6832049(tbl_JOIN_LEFTSEMI_TD_7619982_output, tbl_JOIN_LEFTSEMI_TD_7493952_output, tbl_JOIN_INNER_TD_6832049_output);
    gettimeofday(&tv_r_JOIN_INNER_6_452163_e, 0);

    struct timeval tv_r_JOIN_INNER_5_163027_s, tv_r_JOIN_INNER_5_163027_e;
    gettimeofday(&tv_r_JOIN_INNER_5_163027_s, 0);
    SW_JOIN_INNER_TD_514082(tbl_JOIN_INNER_TD_6288197_output, tbl_Filter_TD_659084_output, tbl_JOIN_INNER_TD_514082_output);
    gettimeofday(&tv_r_JOIN_INNER_5_163027_e, 0);

    struct timeval tv_r_JOIN_INNER_5_680959_s, tv_r_JOIN_INNER_5_680959_e;
    gettimeofday(&tv_r_JOIN_INNER_5_680959_s, 0);
    SW_JOIN_INNER_TD_5393483(tbl_JOIN_INNER_TD_6832049_output, tbl_Filter_TD_6729719_output, tbl_JOIN_INNER_TD_5393483_output);
    gettimeofday(&tv_r_JOIN_INNER_5_680959_e, 0);

    struct timeval tv_r_Aggregate_4_286631_s, tv_r_Aggregate_4_286631_e;
    gettimeofday(&tv_r_Aggregate_4_286631_s, 0);
    SW_Aggregate_TD_4296780(tbl_JOIN_INNER_TD_514082_output, tbl_Aggregate_TD_4296780_output);
    gettimeofday(&tv_r_Aggregate_4_286631_e, 0);

    struct timeval tv_r_Aggregate_4_211572_s, tv_r_Aggregate_4_211572_e;
    gettimeofday(&tv_r_Aggregate_4_211572_s, 0);
    SW_Aggregate_TD_4622735(tbl_JOIN_INNER_TD_5393483_output, tbl_Aggregate_TD_4622735_output);
    gettimeofday(&tv_r_Aggregate_4_211572_e, 0);

    struct timeval tv_r_Union_3_756301_s, tv_r_Union_3_756301_e;
    gettimeofday(&tv_r_Union_3_756301_s, 0);
    SW_Union_TD_3362723(tbl_Aggregate_TD_4622735_output, tbl_Aggregate_TD_4296780_output, tbl_Union_TD_3362723_output);
    gettimeofday(&tv_r_Union_3_756301_e, 0);

    struct timeval tv_r_Sort_2_610768_s, tv_r_Sort_2_610768_e;
    gettimeofday(&tv_r_Sort_2_610768_s, 0);
    SW_Sort_TD_2281265(tbl_Union_TD_3362723_output, tbl_Sort_TD_2281265_output);
    gettimeofday(&tv_r_Sort_2_610768_e, 0);

    struct timeval tv_r_LocalLimit_1_150886_s, tv_r_LocalLimit_1_150886_e;
    gettimeofday(&tv_r_LocalLimit_1_150886_s, 0);
    SW_LocalLimit_TD_1536848(tbl_Sort_TD_2281265_output, tbl_LocalLimit_TD_1536848_output);
    gettimeofday(&tv_r_LocalLimit_1_150886_e, 0);

    struct timeval tv_r_GlobalLimit_0_384367_s, tv_r_GlobalLimit_0_384367_e;
    gettimeofday(&tv_r_GlobalLimit_0_384367_s, 0);
    SW_GlobalLimit_TD_0220815(tbl_LocalLimit_TD_1536848_output, tbl_GlobalLimit_TD_0220815_output);
    gettimeofday(&tv_r_GlobalLimit_0_384367_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_14: " << tvdiff(&tv_r_Filter_14_876067_s, &tv_r_Filter_14_876067_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_15662963_input: " << tbl_SerializeFromObject_TD_15662963_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_14: " << tvdiff(&tv_r_Filter_14_409491_s, &tv_r_Filter_14_409491_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_15445630_input: " << tbl_SerializeFromObject_TD_15445630_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_14: " << tvdiff(&tv_r_Filter_14_704742_s, &tv_r_Filter_14_704742_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_15216586_input: " << tbl_SerializeFromObject_TD_15216586_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_14: " << tvdiff(&tv_r_Filter_14_200064_s, &tv_r_Filter_14_200064_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_15306391_input: " << tbl_SerializeFromObject_TD_15306391_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_13: " << tvdiff(&tv_r_Filter_13_27231_s, &tv_r_Filter_13_27231_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_14255064_input: " << tbl_SerializeFromObject_TD_14255064_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_13: " << tvdiff(&tv_r_Filter_13_609096_s, &tv_r_Filter_13_609096_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1443236_input: " << tbl_SerializeFromObject_TD_1443236_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_13: " << tvdiff(&tv_r_Filter_13_999031_s, &tv_r_Filter_13_999031_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_14532305_input: " << tbl_SerializeFromObject_TD_14532305_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_13: " << tvdiff(&tv_r_Filter_13_875330_s, &tv_r_Filter_13_875330_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_14570327_input: " << tbl_SerializeFromObject_TD_14570327_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_13: " << tvdiff(&tv_r_Filter_13_371161_s, &tv_r_Filter_13_371161_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_14566612_input: " << tbl_SerializeFromObject_TD_14566612_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_13: " << tvdiff(&tv_r_JOIN_INNER_13_757892_s, &tv_r_JOIN_INNER_13_757892_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_14407716_output: " << tbl_Filter_TD_14407716_output.getNumRow() << " " << "tbl_Filter_TD_14399817_output: " << tbl_Filter_TD_14399817_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_13: " << tvdiff(&tv_r_Filter_13_697167_s, &tv_r_Filter_13_697167_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_14786228_input: " << tbl_SerializeFromObject_TD_14786228_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_13: " << tvdiff(&tv_r_Filter_13_936276_s, &tv_r_Filter_13_936276_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_14673856_input: " << tbl_SerializeFromObject_TD_14673856_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_13: " << tvdiff(&tv_r_Filter_13_871554_s, &tv_r_Filter_13_871554_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1452553_input: " << tbl_SerializeFromObject_TD_1452553_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_13: " << tvdiff(&tv_r_Filter_13_263699_s, &tv_r_Filter_13_263699_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_14654455_input: " << tbl_SerializeFromObject_TD_14654455_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_13: " << tvdiff(&tv_r_Filter_13_884641_s, &tv_r_Filter_13_884641_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_14800257_input: " << tbl_SerializeFromObject_TD_14800257_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_13: " << tvdiff(&tv_r_JOIN_INNER_13_931591_s, &tv_r_JOIN_INNER_13_931591_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_14640872_output: " << tbl_Filter_TD_14640872_output.getNumRow() << " " << "tbl_Filter_TD_14165006_output: " << tbl_Filter_TD_14165006_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_538704_s, &tv_r_Filter_12_538704_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13541437_input: " << tbl_SerializeFromObject_TD_13541437_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_12: " << tvdiff(&tv_r_JOIN_INNER_12_843426_s, &tv_r_JOIN_INNER_12_843426_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_13700909_output: " << tbl_Filter_TD_13700909_output.getNumRow() << " " << "tbl_Filter_TD_13452877_output: " << tbl_Filter_TD_13452877_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_671723_s, &tv_r_Filter_12_671723_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13842382_input: " << tbl_SerializeFromObject_TD_13842382_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_12: " << tvdiff(&tv_r_JOIN_INNER_12_500779_s, &tv_r_JOIN_INNER_12_500779_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_13647399_output: " << tbl_Filter_TD_13647399_output.getNumRow() << " " << "tbl_Filter_TD_1386041_output: " << tbl_Filter_TD_1386041_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_12: " << tvdiff(&tv_r_JOIN_INNER_12_767863_s, &tv_r_JOIN_INNER_12_767863_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_13942914_output: " << tbl_JOIN_INNER_TD_13942914_output.getNumRow() << " " << "tbl_Filter_TD_13954360_output: " << tbl_Filter_TD_13954360_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_230263_s, &tv_r_Filter_12_230263_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13259179_input: " << tbl_SerializeFromObject_TD_13259179_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_12: " << tvdiff(&tv_r_JOIN_INNER_12_611464_s, &tv_r_JOIN_INNER_12_611464_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_13702041_output: " << tbl_Filter_TD_13702041_output.getNumRow() << " " << "tbl_Filter_TD_13469673_output: " << tbl_Filter_TD_13469673_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_997768_s, &tv_r_Filter_12_997768_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13438014_input: " << tbl_SerializeFromObject_TD_13438014_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_12: " << tvdiff(&tv_r_JOIN_INNER_12_755974_s, &tv_r_JOIN_INNER_12_755974_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_13366246_output: " << tbl_Filter_TD_13366246_output.getNumRow() << " " << "tbl_Filter_TD_13539019_output: " << tbl_Filter_TD_13539019_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_12: " << tvdiff(&tv_r_JOIN_INNER_12_588417_s, &tv_r_JOIN_INNER_12_588417_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_13287355_output: " << tbl_JOIN_INNER_TD_13287355_output.getNumRow() << " " << "tbl_Filter_TD_1373874_output: " << tbl_Filter_TD_1373874_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_11: " << tvdiff(&tv_r_JOIN_INNER_11_77138_s, &tv_r_JOIN_INNER_11_77138_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_12149137_output: " << tbl_JOIN_INNER_TD_12149137_output.getNumRow() << " " << "tbl_Filter_TD_12386496_output: " << tbl_Filter_TD_12386496_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_107720_s, &tv_r_Filter_11_107720_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12350645_input: " << tbl_SerializeFromObject_TD_12350645_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_792481_s, &tv_r_Filter_11_792481_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12735447_input: " << tbl_SerializeFromObject_TD_12735447_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_11: " << tvdiff(&tv_r_JOIN_INNER_11_290121_s, &tv_r_JOIN_INNER_11_290121_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_12732934_output: " << tbl_JOIN_INNER_TD_12732934_output.getNumRow() << " " << "tbl_Filter_TD_12901777_output: " << tbl_Filter_TD_12901777_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_256561_s, &tv_r_Filter_11_256561_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12680534_input: " << tbl_SerializeFromObject_TD_12680534_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_241074_s, &tv_r_Filter_11_241074_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12747514_input: " << tbl_SerializeFromObject_TD_12747514_input.getNumRow() << " " << std::endl; 

    std::cout << "Project_11: " << tvdiff(&tv_r_Project_11_879959_s, &tv_r_Project_11_879959_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_12390969_output: " << tbl_JOIN_INNER_TD_12390969_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_11: " << tvdiff(&tv_r_JOIN_INNER_11_990152_s, &tv_r_JOIN_INNER_11_990152_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_12552462_output: " << tbl_JOIN_INNER_TD_12552462_output.getNumRow() << " " << "tbl_Filter_TD_12313344_output: " << tbl_Filter_TD_12313344_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_500485_s, &tv_r_Filter_11_500485_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1223068_input: " << tbl_SerializeFromObject_TD_1223068_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_216337_s, &tv_r_Filter_11_216337_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12390145_input: " << tbl_SerializeFromObject_TD_12390145_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_11: " << tvdiff(&tv_r_JOIN_INNER_11_792607_s, &tv_r_JOIN_INNER_11_792607_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_12481484_output: " << tbl_JOIN_INNER_TD_12481484_output.getNumRow() << " " << "tbl_Filter_TD_12691562_output: " << tbl_Filter_TD_12691562_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_242643_s, &tv_r_Filter_11_242643_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12783408_input: " << tbl_SerializeFromObject_TD_12783408_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_41004_s, &tv_r_Filter_11_41004_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12133188_input: " << tbl_SerializeFromObject_TD_12133188_input.getNumRow() << " " << std::endl; 

    std::cout << "Project_11: " << tvdiff(&tv_r_Project_11_384051_s, &tv_r_Project_11_384051_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_12731607_output: " << tbl_JOIN_INNER_TD_12731607_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_10: " << tvdiff(&tv_r_Aggregate_10_201524_s, &tv_r_Aggregate_10_201524_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_11391199_output: " << tbl_JOIN_INNER_TD_11391199_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_648882_s, &tv_r_JOIN_INNER_10_648882_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11174320_output: " << tbl_Filter_TD_11174320_output.getNumRow() << " " << "tbl_Filter_TD_11760980_output: " << tbl_Filter_TD_11760980_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_10: " << tvdiff(&tv_r_Aggregate_10_321328_s, &tv_r_Aggregate_10_321328_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_11586348_output: " << tbl_JOIN_INNER_TD_11586348_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_806349_s, &tv_r_JOIN_INNER_10_806349_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11187752_output: " << tbl_Filter_TD_11187752_output.getNumRow() << " " << "tbl_Filter_TD_11871505_output: " << tbl_Filter_TD_11871505_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_10: " << tvdiff(&tv_r_Aggregate_10_554762_s, &tv_r_Aggregate_10_554762_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_11107252_output: " << tbl_Project_TD_11107252_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_10: " << tvdiff(&tv_r_Aggregate_10_340942_s, &tv_r_Aggregate_10_340942_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_11161751_output: " << tbl_JOIN_INNER_TD_11161751_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_499920_s, &tv_r_JOIN_INNER_10_499920_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11510993_output: " << tbl_Filter_TD_11510993_output.getNumRow() << " " << "tbl_Filter_TD_11361028_output: " << tbl_Filter_TD_11361028_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_10: " << tvdiff(&tv_r_Aggregate_10_720764_s, &tv_r_Aggregate_10_720764_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_1137987_output: " << tbl_JOIN_INNER_TD_1137987_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_700459_s, &tv_r_JOIN_INNER_10_700459_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11726486_output: " << tbl_Filter_TD_11726486_output.getNumRow() << " " << "tbl_Filter_TD_11957528_output: " << tbl_Filter_TD_11957528_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_10: " << tvdiff(&tv_r_Aggregate_10_786632_s, &tv_r_Aggregate_10_786632_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_11995959_output: " << tbl_Project_TD_11995959_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_9: " << tvdiff(&tv_r_Aggregate_9_525801_s, &tv_r_Aggregate_9_525801_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_10391355_output: " << tbl_Aggregate_TD_10391355_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_9: " << tvdiff(&tv_r_Aggregate_9_819814_s, &tv_r_Aggregate_9_819814_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10264341_output: " << tbl_JOIN_INNER_TD_10264341_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_9: " << tvdiff(&tv_r_Aggregate_9_580083_s, &tv_r_Aggregate_9_580083_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_10114900_output: " << tbl_Aggregate_TD_10114900_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_9: " << tvdiff(&tv_r_Aggregate_9_385894_s, &tv_r_Aggregate_9_385894_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10979249_output: " << tbl_JOIN_INNER_TD_10979249_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_726145_s, &tv_r_Filter_9_726145_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_10874103_output: " << tbl_Aggregate_TD_10874103_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_37375_s, &tv_r_Filter_9_37375_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10269486_input: " << tbl_SerializeFromObject_TD_10269486_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_9: " << tvdiff(&tv_r_Aggregate_9_199972_s, &tv_r_Aggregate_9_199972_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_10779337_output: " << tbl_Aggregate_TD_10779337_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_9: " << tvdiff(&tv_r_Aggregate_9_322280_s, &tv_r_Aggregate_9_322280_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10548299_output: " << tbl_JOIN_INNER_TD_10548299_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_9: " << tvdiff(&tv_r_Aggregate_9_630128_s, &tv_r_Aggregate_9_630128_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_10940044_output: " << tbl_Aggregate_TD_10940044_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_9: " << tvdiff(&tv_r_Aggregate_9_368104_s, &tv_r_Aggregate_9_368104_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10122185_output: " << tbl_JOIN_INNER_TD_10122185_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_764903_s, &tv_r_Filter_9_764903_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_10150991_output: " << tbl_Aggregate_TD_10150991_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_458425_s, &tv_r_Filter_9_458425_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10110473_input: " << tbl_SerializeFromObject_TD_10110473_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_274476_s, &tv_r_Filter_8_274476_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_9533960_output: " << tbl_Aggregate_TD_9533960_output.getNumRow() << " " << "tbl_Aggregate_TD_9116253_output: " << tbl_Aggregate_TD_9116253_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_292209_s, &tv_r_Filter_8_292209_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9255648_input: " << tbl_SerializeFromObject_TD_9255648_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_676768_s, &tv_r_Filter_8_676768_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_9948690_output: " << tbl_Aggregate_TD_9948690_output.getNumRow() << " " << "tbl_Aggregate_TD_9132965_output: " << tbl_Aggregate_TD_9132965_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_8: " << tvdiff(&tv_r_JOIN_LEFTSEMI_8_813185_s, &tv_r_JOIN_LEFTSEMI_8_813185_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9697381_output: " << tbl_Filter_TD_9697381_output.getNumRow() << " " << "tbl_Filter_TD_9735928_output: " << tbl_Filter_TD_9735928_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_649519_s, &tv_r_Filter_8_649519_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_9394832_output: " << tbl_Aggregate_TD_9394832_output.getNumRow() << " " << "tbl_Aggregate_TD_9773538_output: " << tbl_Aggregate_TD_9773538_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_185727_s, &tv_r_Filter_8_185727_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9246457_input: " << tbl_SerializeFromObject_TD_9246457_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_511660_s, &tv_r_Filter_8_511660_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_9241296_output: " << tbl_Aggregate_TD_9241296_output.getNumRow() << " " << "tbl_Aggregate_TD_9707922_output: " << tbl_Aggregate_TD_9707922_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_8: " << tvdiff(&tv_r_JOIN_LEFTSEMI_8_546135_s, &tv_r_JOIN_LEFTSEMI_8_546135_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9849852_output: " << tbl_Filter_TD_9849852_output.getNumRow() << " " << "tbl_Filter_TD_9527090_output: " << tbl_Filter_TD_9527090_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_7: " << tvdiff(&tv_r_JOIN_LEFTSEMI_7_624647_s, &tv_r_JOIN_LEFTSEMI_7_624647_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8166631_output: " << tbl_Filter_TD_8166631_output.getNumRow() << " " << "tbl_Filter_TD_8101406_output: " << tbl_Filter_TD_8101406_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_7: " << tvdiff(&tv_r_JOIN_LEFTSEMI_7_387529_s, &tv_r_JOIN_LEFTSEMI_7_387529_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTSEMI_TD_8435885_output: " << tbl_JOIN_LEFTSEMI_TD_8435885_output.getNumRow() << " " << "tbl_Filter_TD_8261746_output: " << tbl_Filter_TD_8261746_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_7: " << tvdiff(&tv_r_JOIN_LEFTSEMI_7_904186_s, &tv_r_JOIN_LEFTSEMI_7_904186_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8727146_output: " << tbl_Filter_TD_8727146_output.getNumRow() << " " << "tbl_Filter_TD_8479531_output: " << tbl_Filter_TD_8479531_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_7: " << tvdiff(&tv_r_JOIN_LEFTSEMI_7_616724_s, &tv_r_JOIN_LEFTSEMI_7_616724_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTSEMI_TD_8187296_output: " << tbl_JOIN_LEFTSEMI_TD_8187296_output.getNumRow() << " " << "tbl_Filter_TD_8434144_output: " << tbl_Filter_TD_8434144_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_501626_s, &tv_r_Filter_6_501626_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7703945_input: " << tbl_SerializeFromObject_TD_7703945_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_35324_s, &tv_r_JOIN_INNER_6_35324_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTSEMI_TD_7552478_output: " << tbl_JOIN_LEFTSEMI_TD_7552478_output.getNumRow() << " " << "tbl_JOIN_LEFTSEMI_TD_7221819_output: " << tbl_JOIN_LEFTSEMI_TD_7221819_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_431875_s, &tv_r_Filter_6_431875_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7253164_input: " << tbl_SerializeFromObject_TD_7253164_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_452163_s, &tv_r_JOIN_INNER_6_452163_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTSEMI_TD_7619982_output: " << tbl_JOIN_LEFTSEMI_TD_7619982_output.getNumRow() << " " << "tbl_JOIN_LEFTSEMI_TD_7493952_output: " << tbl_JOIN_LEFTSEMI_TD_7493952_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_163027_s, &tv_r_JOIN_INNER_5_163027_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6288197_output: " << tbl_JOIN_INNER_TD_6288197_output.getNumRow() << " " << "tbl_Filter_TD_659084_output: " << tbl_Filter_TD_659084_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_680959_s, &tv_r_JOIN_INNER_5_680959_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6832049_output: " << tbl_JOIN_INNER_TD_6832049_output.getNumRow() << " " << "tbl_Filter_TD_6729719_output: " << tbl_Filter_TD_6729719_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_4: " << tvdiff(&tv_r_Aggregate_4_286631_s, &tv_r_Aggregate_4_286631_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_514082_output: " << tbl_JOIN_INNER_TD_514082_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_4: " << tvdiff(&tv_r_Aggregate_4_211572_s, &tv_r_Aggregate_4_211572_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5393483_output: " << tbl_JOIN_INNER_TD_5393483_output.getNumRow() << " " << std::endl; 

    std::cout << "Union_3: " << tvdiff(&tv_r_Union_3_756301_s, &tv_r_Union_3_756301_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_4622735_output: " << tbl_Aggregate_TD_4622735_output.getNumRow() << " " << "tbl_Aggregate_TD_4296780_output: " << tbl_Aggregate_TD_4296780_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_610768_s, &tv_r_Sort_2_610768_e) / 1000.0 << " ms " 
     << "tbl_Union_TD_3362723_output: " << tbl_Union_TD_3362723_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_150886_s, &tv_r_LocalLimit_1_150886_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2281265_output: " << tbl_Sort_TD_2281265_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_384367_s, &tv_r_GlobalLimit_0_384367_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1536848_output: " << tbl_LocalLimit_TD_1536848_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 10.815436 * 1000 << "ms" << std::endl; 
    return 0; 
}
