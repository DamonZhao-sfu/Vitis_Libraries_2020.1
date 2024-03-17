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

#include "cfgFunc_q91.hpp" 
#include "q91.hpp" 

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
    std::cout << "NOTE:running query #91\n."; 
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
    Table tbl_Sort_TD_0892685_output("tbl_Sort_TD_0892685_output", 6100000, 4, "");
    tbl_Sort_TD_0892685_output.allocateHost();
    Table tbl_Aggregate_TD_1939108_output("tbl_Aggregate_TD_1939108_output", 6100000, 4, "");
    tbl_Aggregate_TD_1939108_output.allocateHost();
    Table tbl_JOIN_INNER_TD_2168164_output("tbl_JOIN_INNER_TD_2168164_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_2168164_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3525367_output("tbl_JOIN_INNER_TD_3525367_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_3525367_output.allocateHost();
    Table tbl_Filter_TD_3979165_output("tbl_Filter_TD_3979165_output", 6100000, 1, "");
    tbl_Filter_TD_3979165_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4723814_output("tbl_JOIN_INNER_TD_4723814_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_4723814_output.allocateHost();
    Table tbl_Filter_TD_4110362_output("tbl_Filter_TD_4110362_output", 6100000, 3, "");
    tbl_Filter_TD_4110362_output.allocateHost();
    Table tbl_SerializeFromObject_TD_4191882_input;
    tbl_SerializeFromObject_TD_4191882_input = Table("household_demographics", household_demographics_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_4191882_input.addCol("hd_demo_sk", 4);
    tbl_SerializeFromObject_TD_4191882_input.addCol("hd_buy_potential", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_4191882_input.allocateHost();
    tbl_SerializeFromObject_TD_4191882_input.loadHost();
    Table tbl_JOIN_INNER_TD_5104859_output("tbl_JOIN_INNER_TD_5104859_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_5104859_output.allocateHost();
    Table tbl_Filter_TD_5729786_output("tbl_Filter_TD_5729786_output", 6100000, 1, "");
    tbl_Filter_TD_5729786_output.allocateHost();
    Table tbl_SerializeFromObject_TD_5745377_input;
    tbl_SerializeFromObject_TD_5745377_input = Table("customer_demographics", customer_demographics_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_5745377_input.addCol("cd_demo_sk", 4);
    tbl_SerializeFromObject_TD_5745377_input.addCol("cd_marital_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_5745377_input.addCol("cd_education_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_5745377_input.allocateHost();
    tbl_SerializeFromObject_TD_5745377_input.loadHost();
    Table tbl_JOIN_INNER_TD_6187097_output("tbl_JOIN_INNER_TD_6187097_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_6187097_output.allocateHost();
    Table tbl_Filter_TD_6657760_output("tbl_Filter_TD_6657760_output", 6100000, 4, "");
    tbl_Filter_TD_6657760_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6796319_input;
    tbl_SerializeFromObject_TD_6796319_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_6796319_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_6796319_input.addCol("ca_gmt_offset", 4);
    tbl_SerializeFromObject_TD_6796319_input.allocateHost();
    tbl_SerializeFromObject_TD_6796319_input.loadHost();
    Table tbl_JOIN_INNER_TD_7560810_output("tbl_JOIN_INNER_TD_7560810_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_7560810_output.allocateHost();
    Table tbl_Filter_TD_7498066_output("tbl_Filter_TD_7498066_output", 6100000, 1, "");
    tbl_Filter_TD_7498066_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7657806_input;
    tbl_SerializeFromObject_TD_7657806_input = Table("customer", customer_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_7657806_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_7657806_input.addCol("c_current_cdemo_sk", 4);
    tbl_SerializeFromObject_TD_7657806_input.addCol("c_current_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_7657806_input.addCol("c_current_addr_sk", 4);
    tbl_SerializeFromObject_TD_7657806_input.allocateHost();
    tbl_SerializeFromObject_TD_7657806_input.loadHost();
    Table tbl_Filter_TD_8268033_output("tbl_Filter_TD_8268033_output", 6100000, 4, "");
    tbl_Filter_TD_8268033_output.allocateHost();
    Table tbl_Filter_TD_8688461_output("tbl_Filter_TD_8688461_output", 6100000, 4, "");
    tbl_Filter_TD_8688461_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8108689_input;
    tbl_SerializeFromObject_TD_8108689_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8108689_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_8108689_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_8108689_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_8108689_input.allocateHost();
    tbl_SerializeFromObject_TD_8108689_input.loadHost();
    Table tbl_SerializeFromObject_TD_9547899_input;
    tbl_SerializeFromObject_TD_9547899_input = Table("call_center", call_center_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_9547899_input.addCol("cc_call_center_sk", 4);
    tbl_SerializeFromObject_TD_9547899_input.addCol("cc_call_center_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9547899_input.addCol("cc_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9547899_input.addCol("cc_manager", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9547899_input.allocateHost();
    tbl_SerializeFromObject_TD_9547899_input.loadHost();
    Table tbl_SerializeFromObject_TD_972257_input;
    tbl_SerializeFromObject_TD_972257_input = Table("catalog_returns", catalog_returns_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_972257_input.addCol("cr_returned_date_sk", 4);
    tbl_SerializeFromObject_TD_972257_input.addCol("cr_returning_customer_sk", 4);
    tbl_SerializeFromObject_TD_972257_input.addCol("cr_call_center_sk", 4);
    tbl_SerializeFromObject_TD_972257_input.addCol("cr_net_loss", 4);
    tbl_SerializeFromObject_TD_972257_input.allocateHost();
    tbl_SerializeFromObject_TD_972257_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    std::cout << std::endl; 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_8_915955_s, tv_r_Filter_8_915955_e;
    gettimeofday(&tv_r_Filter_8_915955_s, 0);
    SW_Filter_TD_8688461(tbl_SerializeFromObject_TD_972257_input, tbl_Filter_TD_8688461_output);
    gettimeofday(&tv_r_Filter_8_915955_e, 0);

    struct timeval tv_r_Filter_8_34345_s, tv_r_Filter_8_34345_e;
    gettimeofday(&tv_r_Filter_8_34345_s, 0);
    SW_Filter_TD_8268033(tbl_SerializeFromObject_TD_9547899_input, tbl_Filter_TD_8268033_output);
    gettimeofday(&tv_r_Filter_8_34345_e, 0);

    struct timeval tv_r_Filter_7_335880_s, tv_r_Filter_7_335880_e;
    gettimeofday(&tv_r_Filter_7_335880_s, 0);
    SW_Filter_TD_7498066(tbl_SerializeFromObject_TD_8108689_input, tbl_Filter_TD_7498066_output);
    gettimeofday(&tv_r_Filter_7_335880_e, 0);

    struct timeval tv_r_JOIN_INNER_7_156934_s, tv_r_JOIN_INNER_7_156934_e;
    gettimeofday(&tv_r_JOIN_INNER_7_156934_s, 0);
    SW_JOIN_INNER_TD_7560810(tbl_Filter_TD_8268033_output, tbl_Filter_TD_8688461_output, tbl_JOIN_INNER_TD_7560810_output);
    gettimeofday(&tv_r_JOIN_INNER_7_156934_e, 0);

    struct timeval tv_r_Filter_6_923853_s, tv_r_Filter_6_923853_e;
    gettimeofday(&tv_r_Filter_6_923853_s, 0);
    SW_Filter_TD_6657760(tbl_SerializeFromObject_TD_7657806_input, tbl_Filter_TD_6657760_output);
    gettimeofday(&tv_r_Filter_6_923853_e, 0);

    struct timeval tv_r_JOIN_INNER_6_905661_s, tv_r_JOIN_INNER_6_905661_e;
    gettimeofday(&tv_r_JOIN_INNER_6_905661_s, 0);
    SW_JOIN_INNER_TD_6187097(tbl_JOIN_INNER_TD_7560810_output, tbl_Filter_TD_7498066_output, tbl_JOIN_INNER_TD_6187097_output);
    gettimeofday(&tv_r_JOIN_INNER_6_905661_e, 0);

    struct timeval tv_r_Filter_5_711030_s, tv_r_Filter_5_711030_e;
    gettimeofday(&tv_r_Filter_5_711030_s, 0);
    SW_Filter_TD_5729786(tbl_SerializeFromObject_TD_6796319_input, tbl_Filter_TD_5729786_output);
    gettimeofday(&tv_r_Filter_5_711030_e, 0);

    struct timeval tv_r_JOIN_INNER_5_227719_s, tv_r_JOIN_INNER_5_227719_e;
    gettimeofday(&tv_r_JOIN_INNER_5_227719_s, 0);
    SW_JOIN_INNER_TD_5104859(tbl_JOIN_INNER_TD_6187097_output, tbl_Filter_TD_6657760_output, tbl_JOIN_INNER_TD_5104859_output);
    gettimeofday(&tv_r_JOIN_INNER_5_227719_e, 0);

    struct timeval tv_r_Filter_4_946324_s, tv_r_Filter_4_946324_e;
    gettimeofday(&tv_r_Filter_4_946324_s, 0);
    SW_Filter_TD_4110362(tbl_SerializeFromObject_TD_5745377_input, tbl_Filter_TD_4110362_output);
    gettimeofday(&tv_r_Filter_4_946324_e, 0);

    struct timeval tv_r_JOIN_INNER_4_533514_s, tv_r_JOIN_INNER_4_533514_e;
    gettimeofday(&tv_r_JOIN_INNER_4_533514_s, 0);
    SW_JOIN_INNER_TD_4723814(tbl_JOIN_INNER_TD_5104859_output, tbl_Filter_TD_5729786_output, tbl_JOIN_INNER_TD_4723814_output);
    gettimeofday(&tv_r_JOIN_INNER_4_533514_e, 0);

    struct timeval tv_r_Filter_3_811356_s, tv_r_Filter_3_811356_e;
    gettimeofday(&tv_r_Filter_3_811356_s, 0);
    SW_Filter_TD_3979165(tbl_SerializeFromObject_TD_4191882_input, tbl_Filter_TD_3979165_output);
    gettimeofday(&tv_r_Filter_3_811356_e, 0);

    struct timeval tv_r_JOIN_INNER_3_423135_s, tv_r_JOIN_INNER_3_423135_e;
    gettimeofday(&tv_r_JOIN_INNER_3_423135_s, 0);
    SW_JOIN_INNER_TD_3525367(tbl_JOIN_INNER_TD_4723814_output, tbl_Filter_TD_4110362_output, tbl_JOIN_INNER_TD_3525367_output);
    gettimeofday(&tv_r_JOIN_INNER_3_423135_e, 0);

    struct timeval tv_r_JOIN_INNER_2_846475_s, tv_r_JOIN_INNER_2_846475_e;
    gettimeofday(&tv_r_JOIN_INNER_2_846475_s, 0);
    SW_JOIN_INNER_TD_2168164(tbl_JOIN_INNER_TD_3525367_output, tbl_Filter_TD_3979165_output, tbl_JOIN_INNER_TD_2168164_output);
    gettimeofday(&tv_r_JOIN_INNER_2_846475_e, 0);

    struct timeval tv_r_Aggregate_1_523490_s, tv_r_Aggregate_1_523490_e;
    gettimeofday(&tv_r_Aggregate_1_523490_s, 0);
    SW_Aggregate_TD_1939108(tbl_JOIN_INNER_TD_2168164_output, tbl_Aggregate_TD_1939108_output);
    gettimeofday(&tv_r_Aggregate_1_523490_e, 0);

    struct timeval tv_r_Sort_0_368744_s, tv_r_Sort_0_368744_e;
    gettimeofday(&tv_r_Sort_0_368744_s, 0);
    SW_Sort_TD_0892685(tbl_Aggregate_TD_1939108_output, tbl_Sort_TD_0892685_output);
    gettimeofday(&tv_r_Sort_0_368744_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_915955_s, &tv_r_Filter_8_915955_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_972257_input: " << tbl_SerializeFromObject_TD_972257_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_34345_s, &tv_r_Filter_8_34345_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9547899_input: " << tbl_SerializeFromObject_TD_9547899_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_335880_s, &tv_r_Filter_7_335880_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8108689_input: " << tbl_SerializeFromObject_TD_8108689_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_156934_s, &tv_r_JOIN_INNER_7_156934_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8268033_output: " << tbl_Filter_TD_8268033_output.getNumRow() << " " << "tbl_Filter_TD_8688461_output: " << tbl_Filter_TD_8688461_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_923853_s, &tv_r_Filter_6_923853_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7657806_input: " << tbl_SerializeFromObject_TD_7657806_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_905661_s, &tv_r_JOIN_INNER_6_905661_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7560810_output: " << tbl_JOIN_INNER_TD_7560810_output.getNumRow() << " " << "tbl_Filter_TD_7498066_output: " << tbl_Filter_TD_7498066_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_711030_s, &tv_r_Filter_5_711030_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6796319_input: " << tbl_SerializeFromObject_TD_6796319_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_227719_s, &tv_r_JOIN_INNER_5_227719_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6187097_output: " << tbl_JOIN_INNER_TD_6187097_output.getNumRow() << " " << "tbl_Filter_TD_6657760_output: " << tbl_Filter_TD_6657760_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_946324_s, &tv_r_Filter_4_946324_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5745377_input: " << tbl_SerializeFromObject_TD_5745377_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_533514_s, &tv_r_JOIN_INNER_4_533514_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5104859_output: " << tbl_JOIN_INNER_TD_5104859_output.getNumRow() << " " << "tbl_Filter_TD_5729786_output: " << tbl_Filter_TD_5729786_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_811356_s, &tv_r_Filter_3_811356_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_4191882_input: " << tbl_SerializeFromObject_TD_4191882_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_423135_s, &tv_r_JOIN_INNER_3_423135_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4723814_output: " << tbl_JOIN_INNER_TD_4723814_output.getNumRow() << " " << "tbl_Filter_TD_4110362_output: " << tbl_Filter_TD_4110362_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_2: " << tvdiff(&tv_r_JOIN_INNER_2_846475_s, &tv_r_JOIN_INNER_2_846475_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3525367_output: " << tbl_JOIN_INNER_TD_3525367_output.getNumRow() << " " << "tbl_Filter_TD_3979165_output: " << tbl_Filter_TD_3979165_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_523490_s, &tv_r_Aggregate_1_523490_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_2168164_output: " << tbl_JOIN_INNER_TD_2168164_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_368744_s, &tv_r_Sort_0_368744_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_1939108_output: " << tbl_Aggregate_TD_1939108_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.3154484 * 1000 << "ms" << std::endl; 
    return 0; 
}
