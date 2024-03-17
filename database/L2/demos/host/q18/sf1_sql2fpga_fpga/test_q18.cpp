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

#include "cfgFunc_q18.hpp" 
#include "q18.hpp" 

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
    std::cout << "NOTE:running query #18\n."; 
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
    Table tbl_GlobalLimit_TD_031669_output("tbl_GlobalLimit_TD_031669_output", 6100000, 11, "");
    tbl_GlobalLimit_TD_031669_output.allocateHost();
    Table tbl_LocalLimit_TD_1416138_output("tbl_LocalLimit_TD_1416138_output", 6100000, 11, "");
    tbl_LocalLimit_TD_1416138_output.allocateHost();
    Table tbl_Sort_TD_2700404_output("tbl_Sort_TD_2700404_output", 6100000, 11, "");
    tbl_Sort_TD_2700404_output.allocateHost();
    Table tbl_Aggregate_TD_3249924_output("tbl_Aggregate_TD_3249924_output", 6100000, 11, "");
    tbl_Aggregate_TD_3249924_output.allocateHost();
    Table tbl_Expand_TD_4155296_output("tbl_Expand_TD_4155296_output", 6100000, 12, "");
    tbl_Expand_TD_4155296_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5741847_output("tbl_JOIN_INNER_TD_5741847_output", 6100000, 11, "");
    tbl_JOIN_INNER_TD_5741847_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6928432_output("tbl_JOIN_INNER_TD_6928432_output", 6100000, 11, "");
    tbl_JOIN_INNER_TD_6928432_output.allocateHost();
    Table tbl_Filter_TD_6117315_output("tbl_Filter_TD_6117315_output", 6100000, 2, "");
    tbl_Filter_TD_6117315_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7582503_output("tbl_JOIN_INNER_TD_7582503_output", 6100000, 12, "");
    tbl_JOIN_INNER_TD_7582503_output.allocateHost();
    Table tbl_Filter_TD_7361265_output("tbl_Filter_TD_7361265_output", 6100000, 1, "");
    tbl_Filter_TD_7361265_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7802083_input;
    tbl_SerializeFromObject_TD_7802083_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7802083_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_7802083_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7802083_input.allocateHost();
    tbl_SerializeFromObject_TD_7802083_input.loadHost();
    Table tbl_JOIN_INNER_TD_8717419_output("tbl_JOIN_INNER_TD_8717419_output", 6100000, 10, "");
    tbl_JOIN_INNER_TD_8717419_output.allocateHost();
    Table tbl_Filter_TD_8235861_output("tbl_Filter_TD_8235861_output", 6100000, 4, "");
    tbl_Filter_TD_8235861_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8678348_input;
    tbl_SerializeFromObject_TD_8678348_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8678348_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_8678348_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_8678348_input.allocateHost();
    tbl_SerializeFromObject_TD_8678348_input.loadHost();
    Table tbl_JOIN_INNER_TD_9835286_output("tbl_JOIN_INNER_TD_9835286_output", 6100000, 11, "");
    tbl_JOIN_INNER_TD_9835286_output.allocateHost();
    Table tbl_Filter_TD_9573228_output("tbl_Filter_TD_9573228_output", 6100000, 1, "");
    tbl_Filter_TD_9573228_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9446975_input;
    tbl_SerializeFromObject_TD_9446975_input = Table("customer_address", customer_address_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_9446975_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_9446975_input.addCol("ca_county", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9446975_input.addCol("ca_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9446975_input.addCol("ca_country", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9446975_input.allocateHost();
    tbl_SerializeFromObject_TD_9446975_input.loadHost();
    Table tbl_JOIN_INNER_TD_10298733_output("tbl_JOIN_INNER_TD_10298733_output", 6100000, 9, "");
    tbl_JOIN_INNER_TD_10298733_output.allocateHost();
    Table tbl_Filter_TD_10725660_output("tbl_Filter_TD_10725660_output", 6100000, 4, "");
    tbl_Filter_TD_10725660_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10769478_input;
    tbl_SerializeFromObject_TD_10769478_input = Table("customer_demographics", customer_demographics_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_10769478_input.addCol("cd_demo_sk", 4);
    tbl_SerializeFromObject_TD_10769478_input.allocateHost();
    tbl_SerializeFromObject_TD_10769478_input.loadHost();
    Table tbl_Filter_TD_11717203_output("tbl_Filter_TD_11717203_output", 6100000, 9, "");
    tbl_Filter_TD_11717203_output.allocateHost();
    Table tbl_Filter_TD_1132354_output("tbl_Filter_TD_1132354_output", 6100000, 2, "");
    tbl_Filter_TD_1132354_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11936941_input;
    tbl_SerializeFromObject_TD_11936941_input = Table("customer", customer_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_11936941_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_11936941_input.addCol("c_current_cdemo_sk", 4);
    tbl_SerializeFromObject_TD_11936941_input.addCol("c_current_addr_sk", 4);
    tbl_SerializeFromObject_TD_11936941_input.addCol("c_birth_year", 4);
    tbl_SerializeFromObject_TD_11936941_input.addCol("c_birth_month", 4);
    tbl_SerializeFromObject_TD_11936941_input.allocateHost();
    tbl_SerializeFromObject_TD_11936941_input.loadHost();
    Table tbl_SerializeFromObject_TD_12525558_input;
    tbl_SerializeFromObject_TD_12525558_input = Table("catalog_sales", catalog_sales_n, 9, in_dir, "orc");
    tbl_SerializeFromObject_TD_12525558_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_12525558_input.addCol("cs_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_12525558_input.addCol("cs_bill_cdemo_sk", 4);
    tbl_SerializeFromObject_TD_12525558_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_12525558_input.addCol("cs_quantity", 4);
    tbl_SerializeFromObject_TD_12525558_input.addCol("cs_list_price", 4);
    tbl_SerializeFromObject_TD_12525558_input.addCol("cs_sales_price", 4);
    tbl_SerializeFromObject_TD_12525558_input.addCol("cs_coupon_amt", 4);
    tbl_SerializeFromObject_TD_12525558_input.addCol("cs_net_profit", 4);
    tbl_SerializeFromObject_TD_12525558_input.allocateHost();
    tbl_SerializeFromObject_TD_12525558_input.loadHost();
    Table tbl_SerializeFromObject_TD_12302435_input;
    tbl_SerializeFromObject_TD_12302435_input = Table("customer_demographics", customer_demographics_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_12302435_input.addCol("cd_demo_sk", 4);
    tbl_SerializeFromObject_TD_12302435_input.addCol("cd_dep_count", 4);
    tbl_SerializeFromObject_TD_12302435_input.addCol("cd_gender", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_12302435_input.addCol("cd_education_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_12302435_input.allocateHost();
    tbl_SerializeFromObject_TD_12302435_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    std::cout << std::endl; 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_11_590707_s, tv_r_Filter_11_590707_e;
    gettimeofday(&tv_r_Filter_11_590707_s, 0);
    SW_Filter_TD_1132354(tbl_SerializeFromObject_TD_12302435_input, tbl_Filter_TD_1132354_output);
    gettimeofday(&tv_r_Filter_11_590707_e, 0);

    struct timeval tv_r_Filter_11_515779_s, tv_r_Filter_11_515779_e;
    gettimeofday(&tv_r_Filter_11_515779_s, 0);
    SW_Filter_TD_11717203(tbl_SerializeFromObject_TD_12525558_input, tbl_Filter_TD_11717203_output);
    gettimeofday(&tv_r_Filter_11_515779_e, 0);

    struct timeval tv_r_Filter_10_817365_s, tv_r_Filter_10_817365_e;
    gettimeofday(&tv_r_Filter_10_817365_s, 0);
    SW_Filter_TD_10725660(tbl_SerializeFromObject_TD_11936941_input, tbl_Filter_TD_10725660_output);
    gettimeofday(&tv_r_Filter_10_817365_e, 0);

    struct timeval tv_r_JOIN_INNER_10_690895_s, tv_r_JOIN_INNER_10_690895_e;
    gettimeofday(&tv_r_JOIN_INNER_10_690895_s, 0);
    SW_JOIN_INNER_TD_10298733(tbl_Filter_TD_11717203_output, tbl_Filter_TD_1132354_output, tbl_JOIN_INNER_TD_10298733_output);
    gettimeofday(&tv_r_JOIN_INNER_10_690895_e, 0);

    struct timeval tv_r_Filter_9_100270_s, tv_r_Filter_9_100270_e;
    gettimeofday(&tv_r_Filter_9_100270_s, 0);
    SW_Filter_TD_9573228(tbl_SerializeFromObject_TD_10769478_input, tbl_Filter_TD_9573228_output);
    gettimeofday(&tv_r_Filter_9_100270_e, 0);

    struct timeval tv_r_JOIN_INNER_9_228883_s, tv_r_JOIN_INNER_9_228883_e;
    gettimeofday(&tv_r_JOIN_INNER_9_228883_s, 0);
    SW_JOIN_INNER_TD_9835286(tbl_JOIN_INNER_TD_10298733_output, tbl_Filter_TD_10725660_output, tbl_JOIN_INNER_TD_9835286_output);
    gettimeofday(&tv_r_JOIN_INNER_9_228883_e, 0);

    struct timeval tv_r_Filter_8_876652_s, tv_r_Filter_8_876652_e;
    gettimeofday(&tv_r_Filter_8_876652_s, 0);
    SW_Filter_TD_8235861(tbl_SerializeFromObject_TD_9446975_input, tbl_Filter_TD_8235861_output);
    gettimeofday(&tv_r_Filter_8_876652_e, 0);

    struct timeval tv_r_JOIN_INNER_8_723454_s, tv_r_JOIN_INNER_8_723454_e;
    gettimeofday(&tv_r_JOIN_INNER_8_723454_s, 0);
    SW_JOIN_INNER_TD_8717419(tbl_JOIN_INNER_TD_9835286_output, tbl_Filter_TD_9573228_output, tbl_JOIN_INNER_TD_8717419_output);
    gettimeofday(&tv_r_JOIN_INNER_8_723454_e, 0);

    struct timeval tv_r_Filter_7_264632_s, tv_r_Filter_7_264632_e;
    gettimeofday(&tv_r_Filter_7_264632_s, 0);
    SW_Filter_TD_7361265(tbl_SerializeFromObject_TD_8678348_input, tbl_Filter_TD_7361265_output);
    gettimeofday(&tv_r_Filter_7_264632_e, 0);

    struct timeval tv_r_JOIN_INNER_7_720209_s, tv_r_JOIN_INNER_7_720209_e;
    gettimeofday(&tv_r_JOIN_INNER_7_720209_s, 0);
    SW_JOIN_INNER_TD_7582503(tbl_JOIN_INNER_TD_8717419_output, tbl_Filter_TD_8235861_output, tbl_JOIN_INNER_TD_7582503_output);
    gettimeofday(&tv_r_JOIN_INNER_7_720209_e, 0);

    struct timeval tv_r_Filter_6_99505_s, tv_r_Filter_6_99505_e;
    gettimeofday(&tv_r_Filter_6_99505_s, 0);
    SW_Filter_TD_6117315(tbl_SerializeFromObject_TD_7802083_input, tbl_Filter_TD_6117315_output);
    gettimeofday(&tv_r_Filter_6_99505_e, 0);

    struct timeval tv_r_JOIN_INNER_6_796061_s, tv_r_JOIN_INNER_6_796061_e;
    gettimeofday(&tv_r_JOIN_INNER_6_796061_s, 0);
    SW_JOIN_INNER_TD_6928432(tbl_JOIN_INNER_TD_7582503_output, tbl_Filter_TD_7361265_output, tbl_JOIN_INNER_TD_6928432_output);
    gettimeofday(&tv_r_JOIN_INNER_6_796061_e, 0);

    struct timeval tv_r_JOIN_INNER_5_785201_s, tv_r_JOIN_INNER_5_785201_e;
    gettimeofday(&tv_r_JOIN_INNER_5_785201_s, 0);
    SW_JOIN_INNER_TD_5741847(tbl_JOIN_INNER_TD_6928432_output, tbl_Filter_TD_6117315_output, tbl_JOIN_INNER_TD_5741847_output);
    gettimeofday(&tv_r_JOIN_INNER_5_785201_e, 0);

    struct timeval tv_r_Expand_4_865370_s, tv_r_Expand_4_865370_e;
    gettimeofday(&tv_r_Expand_4_865370_s, 0);
    SW_Expand_TD_4155296(tbl_JOIN_INNER_TD_5741847_output, tbl_Expand_TD_4155296_output);
    gettimeofday(&tv_r_Expand_4_865370_e, 0);

    struct timeval tv_r_Aggregate_3_857298_s, tv_r_Aggregate_3_857298_e;
    gettimeofday(&tv_r_Aggregate_3_857298_s, 0);
    SW_Aggregate_TD_3249924(tbl_Expand_TD_4155296_output, tbl_Aggregate_TD_3249924_output);
    gettimeofday(&tv_r_Aggregate_3_857298_e, 0);

    struct timeval tv_r_Sort_2_469192_s, tv_r_Sort_2_469192_e;
    gettimeofday(&tv_r_Sort_2_469192_s, 0);
    SW_Sort_TD_2700404(tbl_Aggregate_TD_3249924_output, tbl_Sort_TD_2700404_output);
    gettimeofday(&tv_r_Sort_2_469192_e, 0);

    struct timeval tv_r_LocalLimit_1_69440_s, tv_r_LocalLimit_1_69440_e;
    gettimeofday(&tv_r_LocalLimit_1_69440_s, 0);
    SW_LocalLimit_TD_1416138(tbl_Sort_TD_2700404_output, tbl_LocalLimit_TD_1416138_output);
    gettimeofday(&tv_r_LocalLimit_1_69440_e, 0);

    struct timeval tv_r_GlobalLimit_0_768778_s, tv_r_GlobalLimit_0_768778_e;
    gettimeofday(&tv_r_GlobalLimit_0_768778_s, 0);
    SW_GlobalLimit_TD_031669(tbl_LocalLimit_TD_1416138_output, tbl_GlobalLimit_TD_031669_output);
    gettimeofday(&tv_r_GlobalLimit_0_768778_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_590707_s, &tv_r_Filter_11_590707_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12302435_input: " << tbl_SerializeFromObject_TD_12302435_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_515779_s, &tv_r_Filter_11_515779_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12525558_input: " << tbl_SerializeFromObject_TD_12525558_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_817365_s, &tv_r_Filter_10_817365_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11936941_input: " << tbl_SerializeFromObject_TD_11936941_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_690895_s, &tv_r_JOIN_INNER_10_690895_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11717203_output: " << tbl_Filter_TD_11717203_output.getNumRow() << " " << "tbl_Filter_TD_1132354_output: " << tbl_Filter_TD_1132354_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_100270_s, &tv_r_Filter_9_100270_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10769478_input: " << tbl_SerializeFromObject_TD_10769478_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_228883_s, &tv_r_JOIN_INNER_9_228883_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10298733_output: " << tbl_JOIN_INNER_TD_10298733_output.getNumRow() << " " << "tbl_Filter_TD_10725660_output: " << tbl_Filter_TD_10725660_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_876652_s, &tv_r_Filter_8_876652_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9446975_input: " << tbl_SerializeFromObject_TD_9446975_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_723454_s, &tv_r_JOIN_INNER_8_723454_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9835286_output: " << tbl_JOIN_INNER_TD_9835286_output.getNumRow() << " " << "tbl_Filter_TD_9573228_output: " << tbl_Filter_TD_9573228_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_264632_s, &tv_r_Filter_7_264632_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8678348_input: " << tbl_SerializeFromObject_TD_8678348_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_720209_s, &tv_r_JOIN_INNER_7_720209_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8717419_output: " << tbl_JOIN_INNER_TD_8717419_output.getNumRow() << " " << "tbl_Filter_TD_8235861_output: " << tbl_Filter_TD_8235861_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_99505_s, &tv_r_Filter_6_99505_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7802083_input: " << tbl_SerializeFromObject_TD_7802083_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_796061_s, &tv_r_JOIN_INNER_6_796061_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7582503_output: " << tbl_JOIN_INNER_TD_7582503_output.getNumRow() << " " << "tbl_Filter_TD_7361265_output: " << tbl_Filter_TD_7361265_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_785201_s, &tv_r_JOIN_INNER_5_785201_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6928432_output: " << tbl_JOIN_INNER_TD_6928432_output.getNumRow() << " " << "tbl_Filter_TD_6117315_output: " << tbl_Filter_TD_6117315_output.getNumRow() << " " << std::endl; 

    std::cout << "Expand_4: " << tvdiff(&tv_r_Expand_4_865370_s, &tv_r_Expand_4_865370_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5741847_output: " << tbl_JOIN_INNER_TD_5741847_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_857298_s, &tv_r_Aggregate_3_857298_e) / 1000.0 << " ms " 
     << "tbl_Expand_TD_4155296_output: " << tbl_Expand_TD_4155296_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_469192_s, &tv_r_Sort_2_469192_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3249924_output: " << tbl_Aggregate_TD_3249924_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_69440_s, &tv_r_LocalLimit_1_69440_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2700404_output: " << tbl_Sort_TD_2700404_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_768778_s, &tv_r_GlobalLimit_0_768778_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1416138_output: " << tbl_LocalLimit_TD_1416138_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 3.3928437 * 1000 << "ms" << std::endl; 
    return 0; 
}
