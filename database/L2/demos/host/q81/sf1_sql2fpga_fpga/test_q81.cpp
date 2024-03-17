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

#include "cfgFunc_q81.hpp" 
#include "q81.hpp" 

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
    std::cout << "NOTE:running query #81\n."; 
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
    Table tbl_GlobalLimit_TD_0505574_output("tbl_GlobalLimit_TD_0505574_output", 6100000, 16, "");
    tbl_GlobalLimit_TD_0505574_output.allocateHost();
    Table tbl_LocalLimit_TD_165892_output("tbl_LocalLimit_TD_165892_output", 6100000, 16, "");
    tbl_LocalLimit_TD_165892_output.allocateHost();
    Table tbl_Sort_TD_2924774_output("tbl_Sort_TD_2924774_output", 6100000, 16, "");
    tbl_Sort_TD_2924774_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3236528_output("tbl_JOIN_INNER_TD_3236528_output", 6100000, 16, "");
    tbl_JOIN_INNER_TD_3236528_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4460001_output("tbl_JOIN_INNER_TD_4460001_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_4460001_output.allocateHost();
    Table tbl_Filter_TD_4388490_output("tbl_Filter_TD_4388490_output", 6100000, 12, "");
    tbl_Filter_TD_4388490_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5107319_output("tbl_JOIN_INNER_TD_5107319_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_5107319_output.allocateHost();
    Table tbl_Filter_TD_5743616_output("tbl_Filter_TD_5743616_output", 6100000, 6, "");
    tbl_Filter_TD_5743616_output.allocateHost();
    Table tbl_SerializeFromObject_TD_58837_input;
    tbl_SerializeFromObject_TD_58837_input = Table("customer_address", customer_address_n, 12, in_dir, "orc");
    tbl_SerializeFromObject_TD_58837_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_58837_input.addCol("ca_street_number", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_58837_input.addCol("ca_street_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_58837_input.addCol("ca_street_type", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_58837_input.addCol("ca_suite_number", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_58837_input.addCol("ca_city", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_58837_input.addCol("ca_county", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_58837_input.addCol("ca_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_58837_input.addCol("ca_zip", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_58837_input.addCol("ca_country", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_58837_input.addCol("ca_gmt_offset", 4);
    tbl_SerializeFromObject_TD_58837_input.addCol("ca_location_type", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_58837_input.allocateHost();
    tbl_SerializeFromObject_TD_58837_input.loadHost();
    Table tbl_Filter_TD_6893028_output("tbl_Filter_TD_6893028_output", 6100000, 3, "");
    tbl_Filter_TD_6893028_output.allocateHost();
    Table tbl_Filter_TD_6330250_output("tbl_Filter_TD_6330250_output", 6100000, 2, "");
    tbl_Filter_TD_6330250_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6317840_input;
    tbl_SerializeFromObject_TD_6317840_input = Table("customer", customer_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_6317840_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_6317840_input.addCol("c_customer_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6317840_input.addCol("c_current_addr_sk", 4);
    tbl_SerializeFromObject_TD_6317840_input.addCol("c_salutation", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6317840_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6317840_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6317840_input.allocateHost();
    tbl_SerializeFromObject_TD_6317840_input.loadHost();
    Table tbl_Aggregate_TD_740845_output("tbl_Aggregate_TD_740845_output", 6100000, 3, "");
    tbl_Aggregate_TD_740845_output.allocateHost();
    Table tbl_Aggregate_TD_7419266_output("tbl_Aggregate_TD_7419266_output", 6100000, 2, "");
    tbl_Aggregate_TD_7419266_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8829719_output("tbl_JOIN_INNER_TD_8829719_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_8829719_output.allocateHost();
    Table tbl_Aggregate_TD_8307166_output("tbl_Aggregate_TD_8307166_output", 6100000, 2, "");
    tbl_Aggregate_TD_8307166_output.allocateHost();
    Table tbl_JOIN_INNER_TD_934066_output("tbl_JOIN_INNER_TD_934066_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_934066_output.allocateHost();
    Table tbl_Filter_TD_9440346_output("tbl_Filter_TD_9440346_output", 6100000, 2, "");
    tbl_Filter_TD_9440346_output.allocateHost();
    Table tbl_JOIN_INNER_TD_9877513_output("tbl_JOIN_INNER_TD_9877513_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_9877513_output.allocateHost();
    Table tbl_Filter_TD_10717046_output("tbl_Filter_TD_10717046_output", 6100000, 4, "");
    tbl_Filter_TD_10717046_output.allocateHost();
    Table tbl_Filter_TD_10141018_output("tbl_Filter_TD_10141018_output", 6100000, 1, "");
    tbl_Filter_TD_10141018_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10698458_input;
    tbl_SerializeFromObject_TD_10698458_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10698458_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_10698458_input.addCol("ca_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10698458_input.allocateHost();
    tbl_SerializeFromObject_TD_10698458_input.loadHost();
    Table tbl_JOIN_INNER_TD_1014727_output("tbl_JOIN_INNER_TD_1014727_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_1014727_output.allocateHost();
    Table tbl_Filter_TD_10834331_output("tbl_Filter_TD_10834331_output", 6100000, 2, "");
    tbl_Filter_TD_10834331_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11857059_input;
    tbl_SerializeFromObject_TD_11857059_input = Table("catalog_returns", catalog_returns_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_11857059_input.addCol("cr_returned_date_sk", 4);
    tbl_SerializeFromObject_TD_11857059_input.addCol("cr_returning_customer_sk", 4);
    tbl_SerializeFromObject_TD_11857059_input.addCol("cr_returning_addr_sk", 4);
    tbl_SerializeFromObject_TD_11857059_input.addCol("cr_return_amt_inc_tax", 4);
    tbl_SerializeFromObject_TD_11857059_input.allocateHost();
    tbl_SerializeFromObject_TD_11857059_input.loadHost();
    Table tbl_SerializeFromObject_TD_11710837_input;
    tbl_SerializeFromObject_TD_11710837_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11710837_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_11710837_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_11710837_input.allocateHost();
    tbl_SerializeFromObject_TD_11710837_input.loadHost();
    Table tbl_Filter_TD_11864297_output("tbl_Filter_TD_11864297_output", 6100000, 4, "");
    tbl_Filter_TD_11864297_output.allocateHost();
    Table tbl_Filter_TD_1130081_output("tbl_Filter_TD_1130081_output", 6100000, 1, "");
    tbl_Filter_TD_1130081_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11499528_input;
    tbl_SerializeFromObject_TD_11499528_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11499528_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_11499528_input.addCol("ca_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11499528_input.allocateHost();
    tbl_SerializeFromObject_TD_11499528_input.loadHost();
    Table tbl_SerializeFromObject_TD_12306076_input;
    tbl_SerializeFromObject_TD_12306076_input = Table("catalog_returns", catalog_returns_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_12306076_input.addCol("cr_returned_date_sk", 4);
    tbl_SerializeFromObject_TD_12306076_input.addCol("cr_returning_customer_sk", 4);
    tbl_SerializeFromObject_TD_12306076_input.addCol("cr_returning_addr_sk", 4);
    tbl_SerializeFromObject_TD_12306076_input.addCol("cr_return_amt_inc_tax", 4);
    tbl_SerializeFromObject_TD_12306076_input.allocateHost();
    tbl_SerializeFromObject_TD_12306076_input.loadHost();
    Table tbl_SerializeFromObject_TD_12172702_input;
    tbl_SerializeFromObject_TD_12172702_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12172702_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_12172702_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_12172702_input.allocateHost();
    tbl_SerializeFromObject_TD_12172702_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_11_121812_s, tv_r_Filter_11_121812_e;
    gettimeofday(&tv_r_Filter_11_121812_s, 0);
    SW_Filter_TD_1130081(tbl_SerializeFromObject_TD_12172702_input, tbl_Filter_TD_1130081_output);
    gettimeofday(&tv_r_Filter_11_121812_e, 0);

    struct timeval tv_r_Filter_11_230069_s, tv_r_Filter_11_230069_e;
    gettimeofday(&tv_r_Filter_11_230069_s, 0);
    SW_Filter_TD_11864297(tbl_SerializeFromObject_TD_12306076_input, tbl_Filter_TD_11864297_output);
    gettimeofday(&tv_r_Filter_11_230069_e, 0);

    struct timeval tv_r_Filter_10_147797_s, tv_r_Filter_10_147797_e;
    gettimeofday(&tv_r_Filter_10_147797_s, 0);
    SW_Filter_TD_10834331(tbl_SerializeFromObject_TD_11499528_input, tbl_Filter_TD_10834331_output);
    gettimeofday(&tv_r_Filter_10_147797_e, 0);

    struct timeval tv_r_JOIN_INNER_10_509761_s, tv_r_JOIN_INNER_10_509761_e;
    gettimeofday(&tv_r_JOIN_INNER_10_509761_s, 0);
    SW_JOIN_INNER_TD_1014727(tbl_Filter_TD_11864297_output, tbl_Filter_TD_1130081_output, tbl_JOIN_INNER_TD_1014727_output);
    gettimeofday(&tv_r_JOIN_INNER_10_509761_e, 0);

    struct timeval tv_r_Filter_10_270119_s, tv_r_Filter_10_270119_e;
    gettimeofday(&tv_r_Filter_10_270119_s, 0);
    SW_Filter_TD_10141018(tbl_SerializeFromObject_TD_11710837_input, tbl_Filter_TD_10141018_output);
    gettimeofday(&tv_r_Filter_10_270119_e, 0);

    struct timeval tv_r_Filter_10_791776_s, tv_r_Filter_10_791776_e;
    gettimeofday(&tv_r_Filter_10_791776_s, 0);
    SW_Filter_TD_10717046(tbl_SerializeFromObject_TD_11857059_input, tbl_Filter_TD_10717046_output);
    gettimeofday(&tv_r_Filter_10_791776_e, 0);

    struct timeval tv_r_JOIN_INNER_9_640743_s, tv_r_JOIN_INNER_9_640743_e;
    gettimeofday(&tv_r_JOIN_INNER_9_640743_s, 0);
    SW_JOIN_INNER_TD_9877513(tbl_JOIN_INNER_TD_1014727_output, tbl_Filter_TD_10834331_output, tbl_JOIN_INNER_TD_9877513_output);
    gettimeofday(&tv_r_JOIN_INNER_9_640743_e, 0);

    struct timeval tv_r_Filter_9_849833_s, tv_r_Filter_9_849833_e;
    gettimeofday(&tv_r_Filter_9_849833_s, 0);
    SW_Filter_TD_9440346(tbl_SerializeFromObject_TD_10698458_input, tbl_Filter_TD_9440346_output);
    gettimeofday(&tv_r_Filter_9_849833_e, 0);

    struct timeval tv_r_JOIN_INNER_9_384295_s, tv_r_JOIN_INNER_9_384295_e;
    gettimeofday(&tv_r_JOIN_INNER_9_384295_s, 0);
    SW_JOIN_INNER_TD_934066(tbl_Filter_TD_10717046_output, tbl_Filter_TD_10141018_output, tbl_JOIN_INNER_TD_934066_output);
    gettimeofday(&tv_r_JOIN_INNER_9_384295_e, 0);

    struct timeval tv_r_Aggregate_8_135600_s, tv_r_Aggregate_8_135600_e;
    gettimeofday(&tv_r_Aggregate_8_135600_s, 0);
    SW_Aggregate_TD_8307166(tbl_JOIN_INNER_TD_9877513_output, tbl_Aggregate_TD_8307166_output);
    gettimeofday(&tv_r_Aggregate_8_135600_e, 0);

    struct timeval tv_r_JOIN_INNER_8_602061_s, tv_r_JOIN_INNER_8_602061_e;
    gettimeofday(&tv_r_JOIN_INNER_8_602061_s, 0);
    SW_JOIN_INNER_TD_8829719(tbl_JOIN_INNER_TD_934066_output, tbl_Filter_TD_9440346_output, tbl_JOIN_INNER_TD_8829719_output);
    gettimeofday(&tv_r_JOIN_INNER_8_602061_e, 0);

    struct timeval tv_r_Aggregate_7_858421_s, tv_r_Aggregate_7_858421_e;
    gettimeofday(&tv_r_Aggregate_7_858421_s, 0);
    SW_Aggregate_TD_7419266(tbl_Aggregate_TD_8307166_output, tbl_Aggregate_TD_7419266_output);
    gettimeofday(&tv_r_Aggregate_7_858421_e, 0);

    struct timeval tv_r_Aggregate_7_809860_s, tv_r_Aggregate_7_809860_e;
    gettimeofday(&tv_r_Aggregate_7_809860_s, 0);
    SW_Aggregate_TD_740845(tbl_JOIN_INNER_TD_8829719_output, tbl_Aggregate_TD_740845_output);
    gettimeofday(&tv_r_Aggregate_7_809860_e, 0);

    struct timeval tv_r_Filter_6_761994_s, tv_r_Filter_6_761994_e;
    gettimeofday(&tv_r_Filter_6_761994_s, 0);
    SW_Filter_TD_6330250(tbl_Aggregate_TD_7419266_output, tbl_Filter_TD_6330250_output);
    gettimeofday(&tv_r_Filter_6_761994_e, 0);

    struct timeval tv_r_Filter_6_351451_s, tv_r_Filter_6_351451_e;
    gettimeofday(&tv_r_Filter_6_351451_s, 0);
    SW_Filter_TD_6893028(tbl_Aggregate_TD_740845_output, tbl_Filter_TD_6893028_output);
    gettimeofday(&tv_r_Filter_6_351451_e, 0);

    struct timeval tv_r_Filter_5_414320_s, tv_r_Filter_5_414320_e;
    gettimeofday(&tv_r_Filter_5_414320_s, 0);
    SW_Filter_TD_5743616(tbl_SerializeFromObject_TD_6317840_input, tbl_Filter_TD_5743616_output);
    gettimeofday(&tv_r_Filter_5_414320_e, 0);

    struct timeval tv_r_JOIN_INNER_5_728035_s, tv_r_JOIN_INNER_5_728035_e;
    gettimeofday(&tv_r_JOIN_INNER_5_728035_s, 0);
    SW_JOIN_INNER_TD_5107319(tbl_Filter_TD_6893028_output, tbl_Filter_TD_6330250_output, tbl_JOIN_INNER_TD_5107319_output);
    gettimeofday(&tv_r_JOIN_INNER_5_728035_e, 0);

    struct timeval tv_r_Filter_4_373485_s, tv_r_Filter_4_373485_e;
    gettimeofday(&tv_r_Filter_4_373485_s, 0);
    SW_Filter_TD_4388490(tbl_SerializeFromObject_TD_58837_input, tbl_Filter_TD_4388490_output);
    gettimeofday(&tv_r_Filter_4_373485_e, 0);

    struct timeval tv_r_JOIN_INNER_4_281245_s, tv_r_JOIN_INNER_4_281245_e;
    gettimeofday(&tv_r_JOIN_INNER_4_281245_s, 0);
    SW_JOIN_INNER_TD_4460001(tbl_JOIN_INNER_TD_5107319_output, tbl_Filter_TD_5743616_output, tbl_JOIN_INNER_TD_4460001_output);
    gettimeofday(&tv_r_JOIN_INNER_4_281245_e, 0);

    struct timeval tv_r_JOIN_INNER_3_914733_s, tv_r_JOIN_INNER_3_914733_e;
    gettimeofday(&tv_r_JOIN_INNER_3_914733_s, 0);
    SW_JOIN_INNER_TD_3236528(tbl_JOIN_INNER_TD_4460001_output, tbl_Filter_TD_4388490_output, tbl_JOIN_INNER_TD_3236528_output);
    gettimeofday(&tv_r_JOIN_INNER_3_914733_e, 0);

    struct timeval tv_r_Sort_2_38095_s, tv_r_Sort_2_38095_e;
    gettimeofday(&tv_r_Sort_2_38095_s, 0);
    SW_Sort_TD_2924774(tbl_JOIN_INNER_TD_3236528_output, tbl_Sort_TD_2924774_output);
    gettimeofday(&tv_r_Sort_2_38095_e, 0);

    struct timeval tv_r_LocalLimit_1_852056_s, tv_r_LocalLimit_1_852056_e;
    gettimeofday(&tv_r_LocalLimit_1_852056_s, 0);
    SW_LocalLimit_TD_165892(tbl_Sort_TD_2924774_output, tbl_LocalLimit_TD_165892_output);
    gettimeofday(&tv_r_LocalLimit_1_852056_e, 0);

    struct timeval tv_r_GlobalLimit_0_81620_s, tv_r_GlobalLimit_0_81620_e;
    gettimeofday(&tv_r_GlobalLimit_0_81620_s, 0);
    SW_GlobalLimit_TD_0505574(tbl_LocalLimit_TD_165892_output, tbl_GlobalLimit_TD_0505574_output);
    gettimeofday(&tv_r_GlobalLimit_0_81620_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_121812_s, &tv_r_Filter_11_121812_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12172702_input: " << tbl_SerializeFromObject_TD_12172702_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_230069_s, &tv_r_Filter_11_230069_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12306076_input: " << tbl_SerializeFromObject_TD_12306076_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_147797_s, &tv_r_Filter_10_147797_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11499528_input: " << tbl_SerializeFromObject_TD_11499528_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_509761_s, &tv_r_JOIN_INNER_10_509761_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11864297_output: " << tbl_Filter_TD_11864297_output.getNumRow() << " " << "tbl_Filter_TD_1130081_output: " << tbl_Filter_TD_1130081_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_270119_s, &tv_r_Filter_10_270119_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11710837_input: " << tbl_SerializeFromObject_TD_11710837_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_791776_s, &tv_r_Filter_10_791776_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11857059_input: " << tbl_SerializeFromObject_TD_11857059_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_640743_s, &tv_r_JOIN_INNER_9_640743_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_1014727_output: " << tbl_JOIN_INNER_TD_1014727_output.getNumRow() << " " << "tbl_Filter_TD_10834331_output: " << tbl_Filter_TD_10834331_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_849833_s, &tv_r_Filter_9_849833_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10698458_input: " << tbl_SerializeFromObject_TD_10698458_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_384295_s, &tv_r_JOIN_INNER_9_384295_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10717046_output: " << tbl_Filter_TD_10717046_output.getNumRow() << " " << "tbl_Filter_TD_10141018_output: " << tbl_Filter_TD_10141018_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_8: " << tvdiff(&tv_r_Aggregate_8_135600_s, &tv_r_Aggregate_8_135600_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9877513_output: " << tbl_JOIN_INNER_TD_9877513_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_602061_s, &tv_r_JOIN_INNER_8_602061_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_934066_output: " << tbl_JOIN_INNER_TD_934066_output.getNumRow() << " " << "tbl_Filter_TD_9440346_output: " << tbl_Filter_TD_9440346_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_7: " << tvdiff(&tv_r_Aggregate_7_858421_s, &tv_r_Aggregate_7_858421_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_8307166_output: " << tbl_Aggregate_TD_8307166_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_7: " << tvdiff(&tv_r_Aggregate_7_809860_s, &tv_r_Aggregate_7_809860_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8829719_output: " << tbl_JOIN_INNER_TD_8829719_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_761994_s, &tv_r_Filter_6_761994_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_7419266_output: " << tbl_Aggregate_TD_7419266_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_351451_s, &tv_r_Filter_6_351451_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_740845_output: " << tbl_Aggregate_TD_740845_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_414320_s, &tv_r_Filter_5_414320_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6317840_input: " << tbl_SerializeFromObject_TD_6317840_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_728035_s, &tv_r_JOIN_INNER_5_728035_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6893028_output: " << tbl_Filter_TD_6893028_output.getNumRow() << " " << "tbl_Filter_TD_6330250_output: " << tbl_Filter_TD_6330250_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_373485_s, &tv_r_Filter_4_373485_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_58837_input: " << tbl_SerializeFromObject_TD_58837_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_281245_s, &tv_r_JOIN_INNER_4_281245_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5107319_output: " << tbl_JOIN_INNER_TD_5107319_output.getNumRow() << " " << "tbl_Filter_TD_5743616_output: " << tbl_Filter_TD_5743616_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_914733_s, &tv_r_JOIN_INNER_3_914733_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4460001_output: " << tbl_JOIN_INNER_TD_4460001_output.getNumRow() << " " << "tbl_Filter_TD_4388490_output: " << tbl_Filter_TD_4388490_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_38095_s, &tv_r_Sort_2_38095_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3236528_output: " << tbl_JOIN_INNER_TD_3236528_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_852056_s, &tv_r_LocalLimit_1_852056_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2924774_output: " << tbl_Sort_TD_2924774_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_81620_s, &tv_r_GlobalLimit_0_81620_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_165892_output: " << tbl_LocalLimit_TD_165892_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.0603353 * 1000 << "ms" << std::endl; 
    return 0; 
}
