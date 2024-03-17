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

#include "cfgFunc_q1.hpp" 
#include "q1.hpp" 

int main(int argc, const char* argv[]) { 
    std::cout << "\n------------ TPC-H Query Test -------------\n"; 
    ArgParser parser(argc, argv); 
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
    std::cout << "NOTE:running query #1\n."; 
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
    // ****************************** Tables **************************** // 
    Table tbl_Sort_TD_0580320_output("tbl_Sort_TD_0580320_output", 6100000, 2, "");
    tbl_Sort_TD_0580320_output.allocateHost();
    Table tbl_JOIN_INNER_TD_1751278_output("tbl_JOIN_INNER_TD_1751278_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_1751278_output.allocateHost();
    Table tbl_JOIN_INNER_TD_2840998_output("tbl_JOIN_INNER_TD_2840998_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_2840998_output.allocateHost();
    Table tbl_Filter_TD_2130844_output("tbl_Filter_TD_2130844_output", 6100000, 2, "");
    tbl_Filter_TD_2130844_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3587777_output("tbl_JOIN_INNER_TD_3587777_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_3587777_output.allocateHost();
    Table tbl_Filter_TD_3343425_output("tbl_Filter_TD_3343425_output", 6100000, 1, "");
    tbl_Filter_TD_3343425_output.allocateHost();
    Table tbl_SerializeFromObject_TD_3147357_input;
    tbl_SerializeFromObject_TD_3147357_input = Table("customer", customer_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_3147357_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_3147357_input.addCol("c_customer_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_3147357_input.allocateHost();
    tbl_SerializeFromObject_TD_3147357_input.loadHost();
    Table tbl_Filter_TD_432961_output("tbl_Filter_TD_432961_output", 6100000, 3, "");
    tbl_Filter_TD_432961_output.allocateHost();
    Table tbl_Filter_TD_4955885_output("tbl_Filter_TD_4955885_output", 6100000, 2, "");
    tbl_Filter_TD_4955885_output.allocateHost();
    Table tbl_SerializeFromObject_TD_4143755_input;
    tbl_SerializeFromObject_TD_4143755_input = Table("store", store_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_4143755_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_4143755_input.addCol("s_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_4143755_input.allocateHost();
    tbl_SerializeFromObject_TD_4143755_input.loadHost();
    Table tbl_Aggregate_TD_5380173_output("tbl_Aggregate_TD_5380173_output", 6100000, 3, "");
    tbl_Aggregate_TD_5380173_output.allocateHost();
    Table tbl_Aggregate_TD_5668083_output("tbl_Aggregate_TD_5668083_output", 6100000, 2, "");
    tbl_Aggregate_TD_5668083_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6717294_output("tbl_JOIN_INNER_TD_6717294_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_6717294_output.allocateHost();
    Table tbl_Aggregate_TD_6815148_output("tbl_Aggregate_TD_6815148_output", 6100000, 2, "");
    tbl_Aggregate_TD_6815148_output.allocateHost();
    Table tbl_Filter_TD_731356_output("tbl_Filter_TD_731356_output", 6100000, 4, "");
    tbl_Filter_TD_731356_output.allocateHost();
    Table tbl_Filter_TD_7839758_output("tbl_Filter_TD_7839758_output", 6100000, 1, "");
    tbl_Filter_TD_7839758_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7806453_output("tbl_JOIN_INNER_TD_7806453_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_7806453_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8876312_input;
    tbl_SerializeFromObject_TD_8876312_input = Table("store_returns", store_returns_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_8876312_input.addCol("sr_returned_date_sk", 4);
    tbl_SerializeFromObject_TD_8876312_input.addCol("sr_customer_sk", 4);
    tbl_SerializeFromObject_TD_8876312_input.addCol("sr_store_sk", 4);
    tbl_SerializeFromObject_TD_8876312_input.addCol("sr_return_amt", 4);
    tbl_SerializeFromObject_TD_8876312_input.allocateHost();
    tbl_SerializeFromObject_TD_8876312_input.loadHost();
    Table tbl_SerializeFromObject_TD_8495458_input;
    tbl_SerializeFromObject_TD_8495458_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8495458_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_8495458_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_8495458_input.allocateHost();
    tbl_SerializeFromObject_TD_8495458_input.loadHost();
    Table tbl_Filter_TD_8741776_output("tbl_Filter_TD_8741776_output", 6100000, 4, "");
    tbl_Filter_TD_8741776_output.allocateHost();
    Table tbl_Filter_TD_8984869_output("tbl_Filter_TD_8984869_output", 6100000, 1, "");
    tbl_Filter_TD_8984869_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9308485_input;
    tbl_SerializeFromObject_TD_9308485_input = Table("store_returns", store_returns_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_9308485_input.addCol("sr_returned_date_sk", 4);
    tbl_SerializeFromObject_TD_9308485_input.addCol("sr_customer_sk", 4);
    tbl_SerializeFromObject_TD_9308485_input.addCol("sr_store_sk", 4);
    tbl_SerializeFromObject_TD_9308485_input.addCol("sr_return_amt", 4);
    tbl_SerializeFromObject_TD_9308485_input.allocateHost();
    tbl_SerializeFromObject_TD_9308485_input.loadHost();
    Table tbl_SerializeFromObject_TD_9420260_input;
    tbl_SerializeFromObject_TD_9420260_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9420260_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_9420260_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_9420260_input.allocateHost();
    tbl_SerializeFromObject_TD_9420260_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_8_924900_s, tv_r_Filter_8_924900_e;
    gettimeofday(&tv_r_Filter_8_924900_s, 0);
    SW_Filter_TD_8984869(tbl_SerializeFromObject_TD_9420260_input, tbl_Filter_TD_8984869_output);
    gettimeofday(&tv_r_Filter_8_924900_e, 0);

    struct timeval tv_r_Filter_8_415321_s, tv_r_Filter_8_415321_e;
    gettimeofday(&tv_r_Filter_8_415321_s, 0);
    SW_Filter_TD_8741776(tbl_SerializeFromObject_TD_9308485_input, tbl_Filter_TD_8741776_output);
    gettimeofday(&tv_r_Filter_8_415321_e, 0);

    struct timeval tv_r_JOIN_INNER_7_807699_s, tv_r_JOIN_INNER_7_807699_e;
    gettimeofday(&tv_r_JOIN_INNER_7_807699_s, 0);
    SW_JOIN_INNER_TD_7806453(tbl_Filter_TD_8741776_output, tbl_Filter_TD_8984869_output, tbl_JOIN_INNER_TD_7806453_output);
    gettimeofday(&tv_r_JOIN_INNER_7_807699_e, 0);

    struct timeval tv_r_Filter_7_388911_s, tv_r_Filter_7_388911_e;
    gettimeofday(&tv_r_Filter_7_388911_s, 0);
    SW_Filter_TD_7839758(tbl_SerializeFromObject_TD_8495458_input, tbl_Filter_TD_7839758_output);
    gettimeofday(&tv_r_Filter_7_388911_e, 0);

    struct timeval tv_r_Filter_7_844744_s, tv_r_Filter_7_844744_e;
    gettimeofday(&tv_r_Filter_7_844744_s, 0);
    SW_Filter_TD_731356(tbl_SerializeFromObject_TD_8876312_input, tbl_Filter_TD_731356_output);
    gettimeofday(&tv_r_Filter_7_844744_e, 0);

    struct timeval tv_r_Aggregate_6_815640_s, tv_r_Aggregate_6_815640_e;
    gettimeofday(&tv_r_Aggregate_6_815640_s, 0);
    SW_Aggregate_TD_6815148(tbl_JOIN_INNER_TD_7806453_output, tbl_Aggregate_TD_6815148_output);
    gettimeofday(&tv_r_Aggregate_6_815640_e, 0);

    struct timeval tv_r_JOIN_INNER_6_592776_s, tv_r_JOIN_INNER_6_592776_e;
    gettimeofday(&tv_r_JOIN_INNER_6_592776_s, 0);
    SW_JOIN_INNER_TD_6717294(tbl_Filter_TD_731356_output, tbl_Filter_TD_7839758_output, tbl_JOIN_INNER_TD_6717294_output);
    gettimeofday(&tv_r_JOIN_INNER_6_592776_e, 0);

    struct timeval tv_r_Aggregate_5_209915_s, tv_r_Aggregate_5_209915_e;
    gettimeofday(&tv_r_Aggregate_5_209915_s, 0);
    SW_Aggregate_TD_5668083(tbl_Aggregate_TD_6815148_output, tbl_Aggregate_TD_5668083_output);
    gettimeofday(&tv_r_Aggregate_5_209915_e, 0);

    struct timeval tv_r_Aggregate_5_31459_s, tv_r_Aggregate_5_31459_e;
    gettimeofday(&tv_r_Aggregate_5_31459_s, 0);
    SW_Aggregate_TD_5380173(tbl_JOIN_INNER_TD_6717294_output, tbl_Aggregate_TD_5380173_output);
    gettimeofday(&tv_r_Aggregate_5_31459_e, 0);

    struct timeval tv_r_Filter_4_364976_s, tv_r_Filter_4_364976_e;
    gettimeofday(&tv_r_Filter_4_364976_s, 0);
    SW_Filter_TD_4955885(tbl_Aggregate_TD_5668083_output, tbl_Filter_TD_4955885_output);
    gettimeofday(&tv_r_Filter_4_364976_e, 0);

    struct timeval tv_r_Filter_4_84671_s, tv_r_Filter_4_84671_e;
    gettimeofday(&tv_r_Filter_4_84671_s, 0);
    SW_Filter_TD_432961(tbl_Aggregate_TD_5380173_output, tbl_Filter_TD_432961_output);
    gettimeofday(&tv_r_Filter_4_84671_e, 0);

    struct timeval tv_r_Filter_3_683268_s, tv_r_Filter_3_683268_e;
    gettimeofday(&tv_r_Filter_3_683268_s, 0);
    SW_Filter_TD_3343425(tbl_SerializeFromObject_TD_4143755_input, tbl_Filter_TD_3343425_output);
    gettimeofday(&tv_r_Filter_3_683268_e, 0);

    struct timeval tv_r_JOIN_INNER_3_158317_s, tv_r_JOIN_INNER_3_158317_e;
    gettimeofday(&tv_r_JOIN_INNER_3_158317_s, 0);
    SW_JOIN_INNER_TD_3587777(tbl_Filter_TD_432961_output, tbl_Filter_TD_4955885_output, tbl_JOIN_INNER_TD_3587777_output);
    gettimeofday(&tv_r_JOIN_INNER_3_158317_e, 0);

    struct timeval tv_r_Filter_2_18118_s, tv_r_Filter_2_18118_e;
    gettimeofday(&tv_r_Filter_2_18118_s, 0);
    SW_Filter_TD_2130844(tbl_SerializeFromObject_TD_3147357_input, tbl_Filter_TD_2130844_output);
    gettimeofday(&tv_r_Filter_2_18118_e, 0);

    struct timeval tv_r_JOIN_INNER_2_811469_s, tv_r_JOIN_INNER_2_811469_e;
    gettimeofday(&tv_r_JOIN_INNER_2_811469_s, 0);
    SW_JOIN_INNER_TD_2840998(tbl_JOIN_INNER_TD_3587777_output, tbl_Filter_TD_3343425_output, tbl_JOIN_INNER_TD_2840998_output);
    gettimeofday(&tv_r_JOIN_INNER_2_811469_e, 0);

    struct timeval tv_r_JOIN_INNER_1_422135_s, tv_r_JOIN_INNER_1_422135_e;
    gettimeofday(&tv_r_JOIN_INNER_1_422135_s, 0);
    SW_JOIN_INNER_TD_1751278(tbl_JOIN_INNER_TD_2840998_output, tbl_Filter_TD_2130844_output, tbl_JOIN_INNER_TD_1751278_output);
    gettimeofday(&tv_r_JOIN_INNER_1_422135_e, 0);

    struct timeval tv_r_Sort_0_920647_s, tv_r_Sort_0_920647_e;
    gettimeofday(&tv_r_Sort_0_920647_s, 0);
    SW_Sort_TD_0580320(tbl_JOIN_INNER_TD_1751278_output, tbl_Sort_TD_0580320_output);
    gettimeofday(&tv_r_Sort_0_920647_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_924900_s, &tv_r_Filter_8_924900_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9420260_input: " << tbl_SerializeFromObject_TD_9420260_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_415321_s, &tv_r_Filter_8_415321_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9308485_input: " << tbl_SerializeFromObject_TD_9308485_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_807699_s, &tv_r_JOIN_INNER_7_807699_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8741776_output: " << tbl_Filter_TD_8741776_output.getNumRow() << " " << "tbl_Filter_TD_8984869_output: " << tbl_Filter_TD_8984869_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_388911_s, &tv_r_Filter_7_388911_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8495458_input: " << tbl_SerializeFromObject_TD_8495458_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_844744_s, &tv_r_Filter_7_844744_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8876312_input: " << tbl_SerializeFromObject_TD_8876312_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_6: " << tvdiff(&tv_r_Aggregate_6_815640_s, &tv_r_Aggregate_6_815640_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7806453_output: " << tbl_JOIN_INNER_TD_7806453_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_592776_s, &tv_r_JOIN_INNER_6_592776_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_731356_output: " << tbl_Filter_TD_731356_output.getNumRow() << " " << "tbl_Filter_TD_7839758_output: " << tbl_Filter_TD_7839758_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_209915_s, &tv_r_Aggregate_5_209915_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_6815148_output: " << tbl_Aggregate_TD_6815148_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_31459_s, &tv_r_Aggregate_5_31459_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6717294_output: " << tbl_JOIN_INNER_TD_6717294_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_364976_s, &tv_r_Filter_4_364976_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_5668083_output: " << tbl_Aggregate_TD_5668083_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_84671_s, &tv_r_Filter_4_84671_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_5380173_output: " << tbl_Aggregate_TD_5380173_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_683268_s, &tv_r_Filter_3_683268_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_4143755_input: " << tbl_SerializeFromObject_TD_4143755_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_158317_s, &tv_r_JOIN_INNER_3_158317_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_432961_output: " << tbl_Filter_TD_432961_output.getNumRow() << " " << "tbl_Filter_TD_4955885_output: " << tbl_Filter_TD_4955885_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_18118_s, &tv_r_Filter_2_18118_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3147357_input: " << tbl_SerializeFromObject_TD_3147357_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_2: " << tvdiff(&tv_r_JOIN_INNER_2_811469_s, &tv_r_JOIN_INNER_2_811469_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3587777_output: " << tbl_JOIN_INNER_TD_3587777_output.getNumRow() << " " << "tbl_Filter_TD_3343425_output: " << tbl_Filter_TD_3343425_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_1: " << tvdiff(&tv_r_JOIN_INNER_1_422135_s, &tv_r_JOIN_INNER_1_422135_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_2840998_output: " << tbl_JOIN_INNER_TD_2840998_output.getNumRow() << " " << "tbl_Filter_TD_2130844_output: " << tbl_Filter_TD_2130844_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_920647_s, &tv_r_Sort_0_920647_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_1751278_output: " << tbl_JOIN_INNER_TD_1751278_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.7887113 * 1000 << "ms" << std::endl; 
    return 0; 
}
