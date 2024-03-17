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

#include "cfgFunc_q85.hpp" 
#include "q85.hpp" 

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
    std::cout << "NOTE:running query #85\n."; 
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
    Table tbl_GlobalLimit_TD_0464822_output("tbl_GlobalLimit_TD_0464822_output", 6100000, 4, "");
    tbl_GlobalLimit_TD_0464822_output.allocateHost();
    Table tbl_LocalLimit_TD_137117_output("tbl_LocalLimit_TD_137117_output", 6100000, 4, "");
    tbl_LocalLimit_TD_137117_output.allocateHost();
    Table tbl_Sort_TD_2234757_output("tbl_Sort_TD_2234757_output", 6100000, 4, "");
    tbl_Sort_TD_2234757_output.allocateHost();
    Table tbl_Aggregate_TD_3188024_output("tbl_Aggregate_TD_3188024_output", 6100000, 4, "");
    tbl_Aggregate_TD_3188024_output.allocateHost();
    Table tbl_JOIN_INNER_TD_488414_output("tbl_JOIN_INNER_TD_488414_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_488414_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5887610_output("tbl_JOIN_INNER_TD_5887610_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_5887610_output.allocateHost();
    Table tbl_Filter_TD_5498063_output("tbl_Filter_TD_5498063_output", 6100000, 2, "");
    tbl_Filter_TD_5498063_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6321424_output("tbl_JOIN_INNER_TD_6321424_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_6321424_output.allocateHost();
    Table tbl_Filter_TD_6220690_output("tbl_Filter_TD_6220690_output", 6100000, 1, "");
    tbl_Filter_TD_6220690_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6840585_input;
    tbl_SerializeFromObject_TD_6840585_input = Table("reason", reason_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_6840585_input.addCol("r_reason_sk", 4);
    tbl_SerializeFromObject_TD_6840585_input.addCol("r_reason_desc", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6840585_input.allocateHost();
    tbl_SerializeFromObject_TD_6840585_input.loadHost();
    Table tbl_JOIN_INNER_TD_7458932_output("tbl_JOIN_INNER_TD_7458932_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_7458932_output.allocateHost();
    Table tbl_Filter_TD_7544516_output("tbl_Filter_TD_7544516_output", 6100000, 1, "");
    tbl_Filter_TD_7544516_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7127349_input;
    tbl_SerializeFromObject_TD_7127349_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7127349_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_7127349_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_7127349_input.allocateHost();
    tbl_SerializeFromObject_TD_7127349_input.loadHost();
    Table tbl_JOIN_INNER_TD_8871642_output("tbl_JOIN_INNER_TD_8871642_output", 6100000, 9, "");
    tbl_JOIN_INNER_TD_8871642_output.allocateHost();
    Table tbl_Filter_TD_8713280_output("tbl_Filter_TD_8713280_output", 6100000, 3, "");
    tbl_Filter_TD_8713280_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8220681_input;
    tbl_SerializeFromObject_TD_8220681_input = Table("customer_address", customer_address_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8220681_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_8220681_input.addCol("ca_country", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8220681_input.addCol("ca_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8220681_input.allocateHost();
    tbl_SerializeFromObject_TD_8220681_input.loadHost();
    Table tbl_JOIN_INNER_TD_9304127_output("tbl_JOIN_INNER_TD_9304127_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_9304127_output.allocateHost();
    Table tbl_Filter_TD_9582973_output("tbl_Filter_TD_9582973_output", 6100000, 3, "");
    tbl_Filter_TD_9582973_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9898241_input;
    tbl_SerializeFromObject_TD_9898241_input = Table("customer_demographics", customer_demographics_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9898241_input.addCol("cd_demo_sk", 4);
    tbl_SerializeFromObject_TD_9898241_input.addCol("cd_marital_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9898241_input.addCol("cd_education_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9898241_input.allocateHost();
    tbl_SerializeFromObject_TD_9898241_input.loadHost();
    Table tbl_JOIN_INNER_TD_10650531_output("tbl_JOIN_INNER_TD_10650531_output", 6100000, 9, "");
    tbl_JOIN_INNER_TD_10650531_output.allocateHost();
    Table tbl_Filter_TD_10377597_output("tbl_Filter_TD_10377597_output", 6100000, 1, "");
    tbl_Filter_TD_10377597_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10827303_input;
    tbl_SerializeFromObject_TD_10827303_input = Table("customer_demographics", customer_demographics_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10827303_input.addCol("cd_demo_sk", 4);
    tbl_SerializeFromObject_TD_10827303_input.addCol("cd_marital_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10827303_input.addCol("cd_education_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10827303_input.allocateHost();
    tbl_SerializeFromObject_TD_10827303_input.loadHost();
    Table tbl_Filter_TD_11499683_output("tbl_Filter_TD_11499683_output", 6100000, 5, "");
    tbl_Filter_TD_11499683_output.allocateHost();
    Table tbl_Filter_TD_11321754_output("tbl_Filter_TD_11321754_output", 6100000, 8, "");
    tbl_Filter_TD_11321754_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11468886_input;
    tbl_SerializeFromObject_TD_11468886_input = Table("web_page", web_page_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_11468886_input.addCol("wp_web_page_sk", 4);
    tbl_SerializeFromObject_TD_11468886_input.allocateHost();
    tbl_SerializeFromObject_TD_11468886_input.loadHost();
    Table tbl_SerializeFromObject_TD_12744007_input;
    tbl_SerializeFromObject_TD_12744007_input = Table("web_sales", web_sales_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_12744007_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_12744007_input.addCol("ws_item_sk", 4);
    tbl_SerializeFromObject_TD_12744007_input.addCol("ws_web_page_sk", 4);
    tbl_SerializeFromObject_TD_12744007_input.addCol("ws_order_number", 8);
    tbl_SerializeFromObject_TD_12744007_input.addCol("ws_quantity", 4);
    tbl_SerializeFromObject_TD_12744007_input.allocateHost();
    tbl_SerializeFromObject_TD_12744007_input.loadHost();
    Table tbl_SerializeFromObject_TD_12141188_input;
    tbl_SerializeFromObject_TD_12141188_input = Table("web_returns", web_returns_n, 8, in_dir, "orc");
    tbl_SerializeFromObject_TD_12141188_input.addCol("wr_item_sk", 4);
    tbl_SerializeFromObject_TD_12141188_input.addCol("wr_refunded_cdemo_sk", 4);
    tbl_SerializeFromObject_TD_12141188_input.addCol("wr_refunded_addr_sk", 4);
    tbl_SerializeFromObject_TD_12141188_input.addCol("wr_returning_cdemo_sk", 4);
    tbl_SerializeFromObject_TD_12141188_input.addCol("wr_reason_sk", 4);
    tbl_SerializeFromObject_TD_12141188_input.addCol("wr_order_number", 8);
    tbl_SerializeFromObject_TD_12141188_input.addCol("wr_fee", 4);
    tbl_SerializeFromObject_TD_12141188_input.addCol("wr_refunded_cash", 4);
    tbl_SerializeFromObject_TD_12141188_input.allocateHost();
    tbl_SerializeFromObject_TD_12141188_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_11_62889_s, tv_r_Filter_11_62889_e;
    gettimeofday(&tv_r_Filter_11_62889_s, 0);
    SW_Filter_TD_11321754(tbl_SerializeFromObject_TD_12141188_input, tbl_Filter_TD_11321754_output);
    gettimeofday(&tv_r_Filter_11_62889_e, 0);

    struct timeval tv_r_Filter_11_110479_s, tv_r_Filter_11_110479_e;
    gettimeofday(&tv_r_Filter_11_110479_s, 0);
    SW_Filter_TD_11499683(tbl_SerializeFromObject_TD_12744007_input, tbl_Filter_TD_11499683_output);
    gettimeofday(&tv_r_Filter_11_110479_e, 0);

    struct timeval tv_r_Filter_10_611932_s, tv_r_Filter_10_611932_e;
    gettimeofday(&tv_r_Filter_10_611932_s, 0);
    SW_Filter_TD_10377597(tbl_SerializeFromObject_TD_11468886_input, tbl_Filter_TD_10377597_output);
    gettimeofday(&tv_r_Filter_10_611932_e, 0);

    struct timeval tv_r_JOIN_INNER_10_664895_s, tv_r_JOIN_INNER_10_664895_e;
    gettimeofday(&tv_r_JOIN_INNER_10_664895_s, 0);
    SW_JOIN_INNER_TD_10650531(tbl_Filter_TD_11499683_output, tbl_Filter_TD_11321754_output, tbl_JOIN_INNER_TD_10650531_output);
    gettimeofday(&tv_r_JOIN_INNER_10_664895_e, 0);

    struct timeval tv_r_Filter_9_330756_s, tv_r_Filter_9_330756_e;
    gettimeofday(&tv_r_Filter_9_330756_s, 0);
    SW_Filter_TD_9582973(tbl_SerializeFromObject_TD_10827303_input, tbl_Filter_TD_9582973_output);
    gettimeofday(&tv_r_Filter_9_330756_e, 0);

    struct timeval tv_r_JOIN_INNER_9_39032_s, tv_r_JOIN_INNER_9_39032_e;
    gettimeofday(&tv_r_JOIN_INNER_9_39032_s, 0);
    SW_JOIN_INNER_TD_9304127(tbl_JOIN_INNER_TD_10650531_output, tbl_Filter_TD_10377597_output, tbl_JOIN_INNER_TD_9304127_output);
    gettimeofday(&tv_r_JOIN_INNER_9_39032_e, 0);

    struct timeval tv_r_Filter_8_405859_s, tv_r_Filter_8_405859_e;
    gettimeofday(&tv_r_Filter_8_405859_s, 0);
    SW_Filter_TD_8713280(tbl_SerializeFromObject_TD_9898241_input, tbl_Filter_TD_8713280_output);
    gettimeofday(&tv_r_Filter_8_405859_e, 0);

    struct timeval tv_r_JOIN_INNER_8_10127_s, tv_r_JOIN_INNER_8_10127_e;
    gettimeofday(&tv_r_JOIN_INNER_8_10127_s, 0);
    SW_JOIN_INNER_TD_8871642(tbl_JOIN_INNER_TD_9304127_output, tbl_Filter_TD_9582973_output, tbl_JOIN_INNER_TD_8871642_output);
    gettimeofday(&tv_r_JOIN_INNER_8_10127_e, 0);

    struct timeval tv_r_Filter_7_517842_s, tv_r_Filter_7_517842_e;
    gettimeofday(&tv_r_Filter_7_517842_s, 0);
    SW_Filter_TD_7544516(tbl_SerializeFromObject_TD_8220681_input, tbl_Filter_TD_7544516_output);
    gettimeofday(&tv_r_Filter_7_517842_e, 0);

    struct timeval tv_r_JOIN_INNER_7_619348_s, tv_r_JOIN_INNER_7_619348_e;
    gettimeofday(&tv_r_JOIN_INNER_7_619348_s, 0);
    SW_JOIN_INNER_TD_7458932(tbl_JOIN_INNER_TD_8871642_output, tbl_Filter_TD_8713280_output, tbl_JOIN_INNER_TD_7458932_output);
    gettimeofday(&tv_r_JOIN_INNER_7_619348_e, 0);

    struct timeval tv_r_Filter_6_247507_s, tv_r_Filter_6_247507_e;
    gettimeofday(&tv_r_Filter_6_247507_s, 0);
    SW_Filter_TD_6220690(tbl_SerializeFromObject_TD_7127349_input, tbl_Filter_TD_6220690_output);
    gettimeofday(&tv_r_Filter_6_247507_e, 0);

    struct timeval tv_r_JOIN_INNER_6_218617_s, tv_r_JOIN_INNER_6_218617_e;
    gettimeofday(&tv_r_JOIN_INNER_6_218617_s, 0);
    SW_JOIN_INNER_TD_6321424(tbl_JOIN_INNER_TD_7458932_output, tbl_Filter_TD_7544516_output, tbl_JOIN_INNER_TD_6321424_output);
    gettimeofday(&tv_r_JOIN_INNER_6_218617_e, 0);

    struct timeval tv_r_Filter_5_698089_s, tv_r_Filter_5_698089_e;
    gettimeofday(&tv_r_Filter_5_698089_s, 0);
    SW_Filter_TD_5498063(tbl_SerializeFromObject_TD_6840585_input, tbl_Filter_TD_5498063_output);
    gettimeofday(&tv_r_Filter_5_698089_e, 0);

    struct timeval tv_r_JOIN_INNER_5_1368_s, tv_r_JOIN_INNER_5_1368_e;
    gettimeofday(&tv_r_JOIN_INNER_5_1368_s, 0);
    SW_JOIN_INNER_TD_5887610(tbl_JOIN_INNER_TD_6321424_output, tbl_Filter_TD_6220690_output, tbl_JOIN_INNER_TD_5887610_output);
    gettimeofday(&tv_r_JOIN_INNER_5_1368_e, 0);

    struct timeval tv_r_JOIN_INNER_4_824328_s, tv_r_JOIN_INNER_4_824328_e;
    gettimeofday(&tv_r_JOIN_INNER_4_824328_s, 0);
    SW_JOIN_INNER_TD_488414(tbl_JOIN_INNER_TD_5887610_output, tbl_Filter_TD_5498063_output, tbl_JOIN_INNER_TD_488414_output);
    gettimeofday(&tv_r_JOIN_INNER_4_824328_e, 0);

    struct timeval tv_r_Aggregate_3_93175_s, tv_r_Aggregate_3_93175_e;
    gettimeofday(&tv_r_Aggregate_3_93175_s, 0);
    SW_Aggregate_TD_3188024(tbl_JOIN_INNER_TD_488414_output, tbl_Aggregate_TD_3188024_output);
    gettimeofday(&tv_r_Aggregate_3_93175_e, 0);

    struct timeval tv_r_Sort_2_812946_s, tv_r_Sort_2_812946_e;
    gettimeofday(&tv_r_Sort_2_812946_s, 0);
    SW_Sort_TD_2234757(tbl_Aggregate_TD_3188024_output, tbl_Sort_TD_2234757_output);
    gettimeofday(&tv_r_Sort_2_812946_e, 0);

    struct timeval tv_r_LocalLimit_1_647822_s, tv_r_LocalLimit_1_647822_e;
    gettimeofday(&tv_r_LocalLimit_1_647822_s, 0);
    SW_LocalLimit_TD_137117(tbl_Sort_TD_2234757_output, tbl_LocalLimit_TD_137117_output);
    gettimeofday(&tv_r_LocalLimit_1_647822_e, 0);

    struct timeval tv_r_GlobalLimit_0_999346_s, tv_r_GlobalLimit_0_999346_e;
    gettimeofday(&tv_r_GlobalLimit_0_999346_s, 0);
    SW_GlobalLimit_TD_0464822(tbl_LocalLimit_TD_137117_output, tbl_GlobalLimit_TD_0464822_output);
    gettimeofday(&tv_r_GlobalLimit_0_999346_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_62889_s, &tv_r_Filter_11_62889_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12141188_input: " << tbl_SerializeFromObject_TD_12141188_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_110479_s, &tv_r_Filter_11_110479_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12744007_input: " << tbl_SerializeFromObject_TD_12744007_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_611932_s, &tv_r_Filter_10_611932_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11468886_input: " << tbl_SerializeFromObject_TD_11468886_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_664895_s, &tv_r_JOIN_INNER_10_664895_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11499683_output: " << tbl_Filter_TD_11499683_output.getNumRow() << " " << "tbl_Filter_TD_11321754_output: " << tbl_Filter_TD_11321754_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_330756_s, &tv_r_Filter_9_330756_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10827303_input: " << tbl_SerializeFromObject_TD_10827303_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_39032_s, &tv_r_JOIN_INNER_9_39032_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10650531_output: " << tbl_JOIN_INNER_TD_10650531_output.getNumRow() << " " << "tbl_Filter_TD_10377597_output: " << tbl_Filter_TD_10377597_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_405859_s, &tv_r_Filter_8_405859_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9898241_input: " << tbl_SerializeFromObject_TD_9898241_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_10127_s, &tv_r_JOIN_INNER_8_10127_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9304127_output: " << tbl_JOIN_INNER_TD_9304127_output.getNumRow() << " " << "tbl_Filter_TD_9582973_output: " << tbl_Filter_TD_9582973_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_517842_s, &tv_r_Filter_7_517842_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8220681_input: " << tbl_SerializeFromObject_TD_8220681_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_619348_s, &tv_r_JOIN_INNER_7_619348_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8871642_output: " << tbl_JOIN_INNER_TD_8871642_output.getNumRow() << " " << "tbl_Filter_TD_8713280_output: " << tbl_Filter_TD_8713280_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_247507_s, &tv_r_Filter_6_247507_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7127349_input: " << tbl_SerializeFromObject_TD_7127349_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_218617_s, &tv_r_JOIN_INNER_6_218617_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7458932_output: " << tbl_JOIN_INNER_TD_7458932_output.getNumRow() << " " << "tbl_Filter_TD_7544516_output: " << tbl_Filter_TD_7544516_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_698089_s, &tv_r_Filter_5_698089_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6840585_input: " << tbl_SerializeFromObject_TD_6840585_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_1368_s, &tv_r_JOIN_INNER_5_1368_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6321424_output: " << tbl_JOIN_INNER_TD_6321424_output.getNumRow() << " " << "tbl_Filter_TD_6220690_output: " << tbl_Filter_TD_6220690_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_824328_s, &tv_r_JOIN_INNER_4_824328_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5887610_output: " << tbl_JOIN_INNER_TD_5887610_output.getNumRow() << " " << "tbl_Filter_TD_5498063_output: " << tbl_Filter_TD_5498063_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_93175_s, &tv_r_Aggregate_3_93175_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_488414_output: " << tbl_JOIN_INNER_TD_488414_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_812946_s, &tv_r_Sort_2_812946_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3188024_output: " << tbl_Aggregate_TD_3188024_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_647822_s, &tv_r_LocalLimit_1_647822_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2234757_output: " << tbl_Sort_TD_2234757_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_999346_s, &tv_r_GlobalLimit_0_999346_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_137117_output: " << tbl_LocalLimit_TD_137117_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.6676621 * 1000 << "ms" << std::endl; 
    return 0; 
}
