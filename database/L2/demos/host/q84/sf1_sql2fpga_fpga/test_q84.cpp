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

#include "cfgFunc_q84.hpp" 
#include "q84.hpp" 

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
    std::cout << "NOTE:running query #84\n."; 
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
    // ****************************** Tables **************************** // 
    Table tbl_GlobalLimit_TD_0189407_output("tbl_GlobalLimit_TD_0189407_output", 6100000, 2, "");
    tbl_GlobalLimit_TD_0189407_output.allocateHost();
    Table tbl_LocalLimit_TD_1288159_output("tbl_LocalLimit_TD_1288159_output", 6100000, 2, "");
    tbl_LocalLimit_TD_1288159_output.allocateHost();
    Table tbl_Sort_TD_2648706_output("tbl_Sort_TD_2648706_output", 6100000, 3, "");
    tbl_Sort_TD_2648706_output.allocateHost();
    Table tbl_Project_TD_3615078_output("tbl_Project_TD_3615078_output", 6100000, 3, "");
    tbl_Project_TD_3615078_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4489493_output("tbl_JOIN_INNER_TD_4489493_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_4489493_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5630611_output("tbl_JOIN_INNER_TD_5630611_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_5630611_output.allocateHost();
    Table tbl_Filter_TD_5325356_output("tbl_Filter_TD_5325356_output", 6100000, 1, "");
    tbl_Filter_TD_5325356_output.allocateHost();
    Table tbl_JOIN_INNER_TD_62930_output("tbl_JOIN_INNER_TD_62930_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_62930_output.allocateHost();
    Table tbl_Filter_TD_6160676_output("tbl_Filter_TD_6160676_output", 6100000, 1, "");
    tbl_Filter_TD_6160676_output.allocateHost();
    Table tbl_SerializeFromObject_TD_634583_input;
    tbl_SerializeFromObject_TD_634583_input = Table("store_returns", store_returns_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_634583_input.addCol("sr_cdemo_sk", 4);
    tbl_SerializeFromObject_TD_634583_input.allocateHost();
    tbl_SerializeFromObject_TD_634583_input.loadHost();
    Table tbl_JOIN_INNER_TD_7770343_output("tbl_JOIN_INNER_TD_7770343_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_7770343_output.allocateHost();
    Table tbl_Filter_TD_7733011_output("tbl_Filter_TD_7733011_output", 6100000, 2, "");
    tbl_Filter_TD_7733011_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7493630_input;
    tbl_SerializeFromObject_TD_7493630_input = Table("income_band", income_band_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7493630_input.addCol("ib_income_band_sk", 4);
    tbl_SerializeFromObject_TD_7493630_input.addCol("ib_lower_bound", 4);
    tbl_SerializeFromObject_TD_7493630_input.addCol("ib_upper_bound", 4);
    tbl_SerializeFromObject_TD_7493630_input.allocateHost();
    tbl_SerializeFromObject_TD_7493630_input.loadHost();
    Table tbl_JOIN_INNER_TD_8174117_output("tbl_JOIN_INNER_TD_8174117_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_8174117_output.allocateHost();
    Table tbl_Filter_TD_8248739_output("tbl_Filter_TD_8248739_output", 6100000, 1, "");
    tbl_Filter_TD_8248739_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8581460_input;
    tbl_SerializeFromObject_TD_8581460_input = Table("household_demographics", household_demographics_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8581460_input.addCol("hd_demo_sk", 4);
    tbl_SerializeFromObject_TD_8581460_input.addCol("hd_income_band_sk", 4);
    tbl_SerializeFromObject_TD_8581460_input.allocateHost();
    tbl_SerializeFromObject_TD_8581460_input.loadHost();
    Table tbl_Filter_TD_9547861_output("tbl_Filter_TD_9547861_output", 6100000, 6, "");
    tbl_Filter_TD_9547861_output.allocateHost();
    Table tbl_Filter_TD_9919317_output("tbl_Filter_TD_9919317_output", 6100000, 1, "");
    tbl_Filter_TD_9919317_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9898109_input;
    tbl_SerializeFromObject_TD_9898109_input = Table("customer_demographics", customer_demographics_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_9898109_input.addCol("cd_demo_sk", 4);
    tbl_SerializeFromObject_TD_9898109_input.allocateHost();
    tbl_SerializeFromObject_TD_9898109_input.loadHost();
    Table tbl_SerializeFromObject_TD_10995676_input;
    tbl_SerializeFromObject_TD_10995676_input = Table("customer", customer_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_10995676_input.addCol("c_customer_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10995676_input.addCol("c_current_cdemo_sk", 4);
    tbl_SerializeFromObject_TD_10995676_input.addCol("c_current_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_10995676_input.addCol("c_current_addr_sk", 4);
    tbl_SerializeFromObject_TD_10995676_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10995676_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10995676_input.allocateHost();
    tbl_SerializeFromObject_TD_10995676_input.loadHost();
    Table tbl_SerializeFromObject_TD_10552597_input;
    tbl_SerializeFromObject_TD_10552597_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10552597_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_10552597_input.addCol("ca_city", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10552597_input.allocateHost();
    tbl_SerializeFromObject_TD_10552597_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    std::cout << std::endl; 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_9_893488_s, tv_r_Filter_9_893488_e;
    gettimeofday(&tv_r_Filter_9_893488_s, 0);
    SW_Filter_TD_9919317(tbl_SerializeFromObject_TD_10552597_input, tbl_Filter_TD_9919317_output);
    gettimeofday(&tv_r_Filter_9_893488_e, 0);

    struct timeval tv_r_Filter_9_157567_s, tv_r_Filter_9_157567_e;
    gettimeofday(&tv_r_Filter_9_157567_s, 0);
    SW_Filter_TD_9547861(tbl_SerializeFromObject_TD_10995676_input, tbl_Filter_TD_9547861_output);
    gettimeofday(&tv_r_Filter_9_157567_e, 0);

    struct timeval tv_r_Filter_8_51649_s, tv_r_Filter_8_51649_e;
    gettimeofday(&tv_r_Filter_8_51649_s, 0);
    SW_Filter_TD_8248739(tbl_SerializeFromObject_TD_9898109_input, tbl_Filter_TD_8248739_output);
    gettimeofday(&tv_r_Filter_8_51649_e, 0);

    struct timeval tv_r_JOIN_INNER_8_377796_s, tv_r_JOIN_INNER_8_377796_e;
    gettimeofday(&tv_r_JOIN_INNER_8_377796_s, 0);
    SW_JOIN_INNER_TD_8174117(tbl_Filter_TD_9547861_output, tbl_Filter_TD_9919317_output, tbl_JOIN_INNER_TD_8174117_output);
    gettimeofday(&tv_r_JOIN_INNER_8_377796_e, 0);

    struct timeval tv_r_Filter_7_542967_s, tv_r_Filter_7_542967_e;
    gettimeofday(&tv_r_Filter_7_542967_s, 0);
    SW_Filter_TD_7733011(tbl_SerializeFromObject_TD_8581460_input, tbl_Filter_TD_7733011_output);
    gettimeofday(&tv_r_Filter_7_542967_e, 0);

    struct timeval tv_r_JOIN_INNER_7_809625_s, tv_r_JOIN_INNER_7_809625_e;
    gettimeofday(&tv_r_JOIN_INNER_7_809625_s, 0);
    SW_JOIN_INNER_TD_7770343(tbl_JOIN_INNER_TD_8174117_output, tbl_Filter_TD_8248739_output, tbl_JOIN_INNER_TD_7770343_output);
    gettimeofday(&tv_r_JOIN_INNER_7_809625_e, 0);

    struct timeval tv_r_Filter_6_713325_s, tv_r_Filter_6_713325_e;
    gettimeofday(&tv_r_Filter_6_713325_s, 0);
    SW_Filter_TD_6160676(tbl_SerializeFromObject_TD_7493630_input, tbl_Filter_TD_6160676_output);
    gettimeofday(&tv_r_Filter_6_713325_e, 0);

    struct timeval tv_r_JOIN_INNER_6_433726_s, tv_r_JOIN_INNER_6_433726_e;
    gettimeofday(&tv_r_JOIN_INNER_6_433726_s, 0);
    SW_JOIN_INNER_TD_62930(tbl_JOIN_INNER_TD_7770343_output, tbl_Filter_TD_7733011_output, tbl_JOIN_INNER_TD_62930_output);
    gettimeofday(&tv_r_JOIN_INNER_6_433726_e, 0);

    struct timeval tv_r_Filter_5_807723_s, tv_r_Filter_5_807723_e;
    gettimeofday(&tv_r_Filter_5_807723_s, 0);
    SW_Filter_TD_5325356(tbl_SerializeFromObject_TD_634583_input, tbl_Filter_TD_5325356_output);
    gettimeofday(&tv_r_Filter_5_807723_e, 0);

    struct timeval tv_r_JOIN_INNER_5_415833_s, tv_r_JOIN_INNER_5_415833_e;
    gettimeofday(&tv_r_JOIN_INNER_5_415833_s, 0);
    SW_JOIN_INNER_TD_5630611(tbl_JOIN_INNER_TD_62930_output, tbl_Filter_TD_6160676_output, tbl_JOIN_INNER_TD_5630611_output);
    gettimeofday(&tv_r_JOIN_INNER_5_415833_e, 0);

    struct timeval tv_r_JOIN_INNER_4_914509_s, tv_r_JOIN_INNER_4_914509_e;
    gettimeofday(&tv_r_JOIN_INNER_4_914509_s, 0);
    SW_JOIN_INNER_TD_4489493(tbl_JOIN_INNER_TD_5630611_output, tbl_Filter_TD_5325356_output, tbl_JOIN_INNER_TD_4489493_output);
    gettimeofday(&tv_r_JOIN_INNER_4_914509_e, 0);

    struct timeval tv_r_Project_3_101912_s, tv_r_Project_3_101912_e;
    gettimeofday(&tv_r_Project_3_101912_s, 0);
    SW_Project_TD_3615078(tbl_JOIN_INNER_TD_4489493_output, tbl_Project_TD_3615078_output);
    gettimeofday(&tv_r_Project_3_101912_e, 0);

    struct timeval tv_r_Sort_2_767382_s, tv_r_Sort_2_767382_e;
    gettimeofday(&tv_r_Sort_2_767382_s, 0);
    SW_Sort_TD_2648706(tbl_Project_TD_3615078_output, tbl_Sort_TD_2648706_output);
    gettimeofday(&tv_r_Sort_2_767382_e, 0);

    struct timeval tv_r_LocalLimit_1_32108_s, tv_r_LocalLimit_1_32108_e;
    gettimeofday(&tv_r_LocalLimit_1_32108_s, 0);
    SW_LocalLimit_TD_1288159(tbl_Sort_TD_2648706_output, tbl_LocalLimit_TD_1288159_output);
    gettimeofday(&tv_r_LocalLimit_1_32108_e, 0);

    struct timeval tv_r_GlobalLimit_0_69652_s, tv_r_GlobalLimit_0_69652_e;
    gettimeofday(&tv_r_GlobalLimit_0_69652_s, 0);
    SW_GlobalLimit_TD_0189407(tbl_LocalLimit_TD_1288159_output, tbl_GlobalLimit_TD_0189407_output);
    gettimeofday(&tv_r_GlobalLimit_0_69652_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_893488_s, &tv_r_Filter_9_893488_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10552597_input: " << tbl_SerializeFromObject_TD_10552597_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_157567_s, &tv_r_Filter_9_157567_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10995676_input: " << tbl_SerializeFromObject_TD_10995676_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_51649_s, &tv_r_Filter_8_51649_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9898109_input: " << tbl_SerializeFromObject_TD_9898109_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_377796_s, &tv_r_JOIN_INNER_8_377796_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9547861_output: " << tbl_Filter_TD_9547861_output.getNumRow() << " " << "tbl_Filter_TD_9919317_output: " << tbl_Filter_TD_9919317_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_542967_s, &tv_r_Filter_7_542967_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8581460_input: " << tbl_SerializeFromObject_TD_8581460_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_809625_s, &tv_r_JOIN_INNER_7_809625_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8174117_output: " << tbl_JOIN_INNER_TD_8174117_output.getNumRow() << " " << "tbl_Filter_TD_8248739_output: " << tbl_Filter_TD_8248739_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_713325_s, &tv_r_Filter_6_713325_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7493630_input: " << tbl_SerializeFromObject_TD_7493630_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_433726_s, &tv_r_JOIN_INNER_6_433726_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7770343_output: " << tbl_JOIN_INNER_TD_7770343_output.getNumRow() << " " << "tbl_Filter_TD_7733011_output: " << tbl_Filter_TD_7733011_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_807723_s, &tv_r_Filter_5_807723_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_634583_input: " << tbl_SerializeFromObject_TD_634583_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_415833_s, &tv_r_JOIN_INNER_5_415833_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_62930_output: " << tbl_JOIN_INNER_TD_62930_output.getNumRow() << " " << "tbl_Filter_TD_6160676_output: " << tbl_Filter_TD_6160676_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_914509_s, &tv_r_JOIN_INNER_4_914509_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5630611_output: " << tbl_JOIN_INNER_TD_5630611_output.getNumRow() << " " << "tbl_Filter_TD_5325356_output: " << tbl_Filter_TD_5325356_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_3: " << tvdiff(&tv_r_Project_3_101912_s, &tv_r_Project_3_101912_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4489493_output: " << tbl_JOIN_INNER_TD_4489493_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_767382_s, &tv_r_Sort_2_767382_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_3615078_output: " << tbl_Project_TD_3615078_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_32108_s, &tv_r_LocalLimit_1_32108_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2648706_output: " << tbl_Sort_TD_2648706_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_69652_s, &tv_r_GlobalLimit_0_69652_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1288159_output: " << tbl_LocalLimit_TD_1288159_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.8641051 * 1000 << "ms" << std::endl; 
    return 0; 
}
