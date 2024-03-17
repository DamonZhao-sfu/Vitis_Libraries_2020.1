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

#include "cfgFunc_q35.hpp" 
#include "q35.hpp" 

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
    std::cout << "NOTE:running query #35\n."; 
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
    Table tbl_GlobalLimit_TD_0251568_output("tbl_GlobalLimit_TD_0251568_output", 6100000, 18, "");
    tbl_GlobalLimit_TD_0251568_output.allocateHost();
    Table tbl_LocalLimit_TD_131011_output("tbl_LocalLimit_TD_131011_output", 6100000, 18, "");
    tbl_LocalLimit_TD_131011_output.allocateHost();
    Table tbl_Sort_TD_2165466_output("tbl_Sort_TD_2165466_output", 6100000, 18, "");
    tbl_Sort_TD_2165466_output.allocateHost();
    Table tbl_Aggregate_TD_3220058_output("tbl_Aggregate_TD_3220058_output", 6100000, 18, "");
    tbl_Aggregate_TD_3220058_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4186727_output("tbl_JOIN_INNER_TD_4186727_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_4186727_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5693658_output("tbl_JOIN_INNER_TD_5693658_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_5693658_output.allocateHost();
    Table tbl_Filter_TD_5298468_output("tbl_Filter_TD_5298468_output", 6100000, 6, "");
    tbl_Filter_TD_5298468_output.allocateHost();
    Table tbl_Filter_TD_6149814_output("tbl_Filter_TD_6149814_output", 6100000, 2, "");
    tbl_Filter_TD_6149814_output.allocateHost();
    Table tbl_Filter_TD_6671766_output("tbl_Filter_TD_6671766_output", 6100000, 2, "");
    tbl_Filter_TD_6671766_output.allocateHost();
    Table tbl_SerializeFromObject_TD_628796_input;
    tbl_SerializeFromObject_TD_628796_input = Table("customer_demographics", customer_demographics_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_628796_input.addCol("cd_demo_sk", 4);
    tbl_SerializeFromObject_TD_628796_input.addCol("cd_gender", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_628796_input.addCol("cd_marital_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_628796_input.addCol("cd_dep_count", 4);
    tbl_SerializeFromObject_TD_628796_input.addCol("cd_dep_employed_count", 4);
    tbl_SerializeFromObject_TD_628796_input.addCol("cd_dep_college_count", 4);
    tbl_SerializeFromObject_TD_628796_input.allocateHost();
    tbl_SerializeFromObject_TD_628796_input.loadHost();
    Table tbl_JOIN_EXISTENCEJOINEXISTS19579_TD_7169608_output("tbl_JOIN_EXISTENCEJOINEXISTS19579_TD_7169608_output", 6100000, 4, "");
    tbl_JOIN_EXISTENCEJOINEXISTS19579_TD_7169608_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7250566_input;
    tbl_SerializeFromObject_TD_7250566_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7250566_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_7250566_input.addCol("ca_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7250566_input.allocateHost();
    tbl_SerializeFromObject_TD_7250566_input.loadHost();
    Table tbl_JOIN_EXISTENCEJOINEXISTS19578_TD_8137509_output("tbl_JOIN_EXISTENCEJOINEXISTS19578_TD_8137509_output", 6100000, 4, "");
    tbl_JOIN_EXISTENCEJOINEXISTS19578_TD_8137509_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8182040_output("tbl_JOIN_INNER_TD_8182040_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_8182040_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_9348623_output("tbl_JOIN_LEFTSEMI_TD_9348623_output", 6100000, 3, "");
    tbl_JOIN_LEFTSEMI_TD_9348623_output.allocateHost();
    Table tbl_JOIN_INNER_TD_9300891_output("tbl_JOIN_INNER_TD_9300891_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_9300891_output.allocateHost();
    Table tbl_Filter_TD_9991107_output("tbl_Filter_TD_9991107_output", 6100000, 2, "");
    tbl_Filter_TD_9991107_output.allocateHost();
    Table tbl_Filter_TD_9460652_output("tbl_Filter_TD_9460652_output", 6100000, 1, "");
    tbl_Filter_TD_9460652_output.allocateHost();
    Table tbl_Filter_TD_1028200_output("tbl_Filter_TD_1028200_output", 6100000, 3, "");
    tbl_Filter_TD_1028200_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10608355_output("tbl_JOIN_INNER_TD_10608355_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_10608355_output.allocateHost();
    Table tbl_Filter_TD_10427051_output("tbl_Filter_TD_10427051_output", 6100000, 2, "");
    tbl_Filter_TD_10427051_output.allocateHost();
    Table tbl_Filter_TD_10279793_output("tbl_Filter_TD_10279793_output", 6100000, 1, "");
    tbl_Filter_TD_10279793_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10892815_input;
    tbl_SerializeFromObject_TD_10892815_input = Table("catalog_sales", catalog_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10892815_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10892815_input.addCol("cs_ship_customer_sk", 4);
    tbl_SerializeFromObject_TD_10892815_input.allocateHost();
    tbl_SerializeFromObject_TD_10892815_input.loadHost();
    Table tbl_SerializeFromObject_TD_10283184_input;
    tbl_SerializeFromObject_TD_10283184_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10283184_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10283184_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10283184_input.addCol("d_qoy", 4);
    tbl_SerializeFromObject_TD_10283184_input.allocateHost();
    tbl_SerializeFromObject_TD_10283184_input.loadHost();
    Table tbl_SerializeFromObject_TD_11746427_input;
    tbl_SerializeFromObject_TD_11746427_input = Table("customer", customer_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11746427_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_11746427_input.addCol("c_current_cdemo_sk", 4);
    tbl_SerializeFromObject_TD_11746427_input.addCol("c_current_addr_sk", 4);
    tbl_SerializeFromObject_TD_11746427_input.allocateHost();
    tbl_SerializeFromObject_TD_11746427_input.loadHost();
    Table tbl_Filter_TD_11595738_output("tbl_Filter_TD_11595738_output", 6100000, 2, "");
    tbl_Filter_TD_11595738_output.allocateHost();
    Table tbl_Filter_TD_11517247_output("tbl_Filter_TD_11517247_output", 6100000, 1, "");
    tbl_Filter_TD_11517247_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11216231_input;
    tbl_SerializeFromObject_TD_11216231_input = Table("web_sales", web_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11216231_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_11216231_input.addCol("ws_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_11216231_input.allocateHost();
    tbl_SerializeFromObject_TD_11216231_input.loadHost();
    Table tbl_SerializeFromObject_TD_11428496_input;
    tbl_SerializeFromObject_TD_11428496_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11428496_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_11428496_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_11428496_input.addCol("d_qoy", 4);
    tbl_SerializeFromObject_TD_11428496_input.allocateHost();
    tbl_SerializeFromObject_TD_11428496_input.loadHost();
    Table tbl_SerializeFromObject_TD_1271917_input;
    tbl_SerializeFromObject_TD_1271917_input = Table("store_sales", store_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_1271917_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_1271917_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_1271917_input.allocateHost();
    tbl_SerializeFromObject_TD_1271917_input.loadHost();
    Table tbl_SerializeFromObject_TD_12336791_input;
    tbl_SerializeFromObject_TD_12336791_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_12336791_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_12336791_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_12336791_input.addCol("d_qoy", 4);
    tbl_SerializeFromObject_TD_12336791_input.allocateHost();
    tbl_SerializeFromObject_TD_12336791_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_11_89985_s, tv_r_Filter_11_89985_e;
    gettimeofday(&tv_r_Filter_11_89985_s, 0);
    SW_Filter_TD_11517247(tbl_SerializeFromObject_TD_12336791_input, tbl_Filter_TD_11517247_output);
    gettimeofday(&tv_r_Filter_11_89985_e, 0);

    struct timeval tv_r_Filter_11_541722_s, tv_r_Filter_11_541722_e;
    gettimeofday(&tv_r_Filter_11_541722_s, 0);
    SW_Filter_TD_11595738(tbl_SerializeFromObject_TD_1271917_input, tbl_Filter_TD_11595738_output);
    gettimeofday(&tv_r_Filter_11_541722_e, 0);

    struct timeval tv_r_Filter_10_37167_s, tv_r_Filter_10_37167_e;
    gettimeofday(&tv_r_Filter_10_37167_s, 0);
    SW_Filter_TD_10279793(tbl_SerializeFromObject_TD_11428496_input, tbl_Filter_TD_10279793_output);
    gettimeofday(&tv_r_Filter_10_37167_e, 0);

    struct timeval tv_r_Filter_10_202713_s, tv_r_Filter_10_202713_e;
    gettimeofday(&tv_r_Filter_10_202713_s, 0);
    SW_Filter_TD_10427051(tbl_SerializeFromObject_TD_11216231_input, tbl_Filter_TD_10427051_output);
    gettimeofday(&tv_r_Filter_10_202713_e, 0);

    struct timeval tv_r_JOIN_INNER_10_704917_s, tv_r_JOIN_INNER_10_704917_e;
    gettimeofday(&tv_r_JOIN_INNER_10_704917_s, 0);
    SW_JOIN_INNER_TD_10608355(tbl_Filter_TD_11595738_output, tbl_Filter_TD_11517247_output, tbl_JOIN_INNER_TD_10608355_output);
    gettimeofday(&tv_r_JOIN_INNER_10_704917_e, 0);

    struct timeval tv_r_Filter_10_611843_s, tv_r_Filter_10_611843_e;
    gettimeofday(&tv_r_Filter_10_611843_s, 0);
    SW_Filter_TD_1028200(tbl_SerializeFromObject_TD_11746427_input, tbl_Filter_TD_1028200_output);
    gettimeofday(&tv_r_Filter_10_611843_e, 0);

    struct timeval tv_r_Filter_9_426434_s, tv_r_Filter_9_426434_e;
    gettimeofday(&tv_r_Filter_9_426434_s, 0);
    SW_Filter_TD_9460652(tbl_SerializeFromObject_TD_10283184_input, tbl_Filter_TD_9460652_output);
    gettimeofday(&tv_r_Filter_9_426434_e, 0);

    struct timeval tv_r_Filter_9_222380_s, tv_r_Filter_9_222380_e;
    gettimeofday(&tv_r_Filter_9_222380_s, 0);
    SW_Filter_TD_9991107(tbl_SerializeFromObject_TD_10892815_input, tbl_Filter_TD_9991107_output);
    gettimeofday(&tv_r_Filter_9_222380_e, 0);

    struct timeval tv_r_JOIN_INNER_9_815736_s, tv_r_JOIN_INNER_9_815736_e;
    gettimeofday(&tv_r_JOIN_INNER_9_815736_s, 0);
    SW_JOIN_INNER_TD_9300891(tbl_Filter_TD_10427051_output, tbl_Filter_TD_10279793_output, tbl_JOIN_INNER_TD_9300891_output);
    gettimeofday(&tv_r_JOIN_INNER_9_815736_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_9_882180_s, tv_r_JOIN_LEFTSEMI_9_882180_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_9_882180_s, 0);
    SW_JOIN_LEFTSEMI_TD_9348623(tbl_Filter_TD_1028200_output, tbl_JOIN_INNER_TD_10608355_output, tbl_JOIN_LEFTSEMI_TD_9348623_output);
    gettimeofday(&tv_r_JOIN_LEFTSEMI_9_882180_e, 0);

    struct timeval tv_r_JOIN_INNER_8_828490_s, tv_r_JOIN_INNER_8_828490_e;
    gettimeofday(&tv_r_JOIN_INNER_8_828490_s, 0);
    SW_JOIN_INNER_TD_8182040(tbl_Filter_TD_9991107_output, tbl_Filter_TD_9460652_output, tbl_JOIN_INNER_TD_8182040_output);
    gettimeofday(&tv_r_JOIN_INNER_8_828490_e, 0);

    struct timeval tv_r_JOIN_EXISTENCEJOINEXISTS19578_8_709446_s, tv_r_JOIN_EXISTENCEJOINEXISTS19578_8_709446_e;
    gettimeofday(&tv_r_JOIN_EXISTENCEJOINEXISTS19578_8_709446_s, 0);
    SW_JOIN_EXISTENCEJOINEXISTS19578_TD_8137509(tbl_JOIN_LEFTSEMI_TD_9348623_output, tbl_JOIN_INNER_TD_9300891_output, tbl_JOIN_EXISTENCEJOINEXISTS19578_TD_8137509_output);
    gettimeofday(&tv_r_JOIN_EXISTENCEJOINEXISTS19578_8_709446_e, 0);

    struct timeval tv_r_JOIN_EXISTENCEJOINEXISTS19579_7_604954_s, tv_r_JOIN_EXISTENCEJOINEXISTS19579_7_604954_e;
    gettimeofday(&tv_r_JOIN_EXISTENCEJOINEXISTS19579_7_604954_s, 0);
    SW_JOIN_EXISTENCEJOINEXISTS19579_TD_7169608(tbl_JOIN_EXISTENCEJOINEXISTS19578_TD_8137509_output, tbl_JOIN_INNER_TD_8182040_output, tbl_JOIN_EXISTENCEJOINEXISTS19579_TD_7169608_output);
    gettimeofday(&tv_r_JOIN_EXISTENCEJOINEXISTS19579_7_604954_e, 0);

    struct timeval tv_r_Filter_6_26938_s, tv_r_Filter_6_26938_e;
    gettimeofday(&tv_r_Filter_6_26938_s, 0);
    SW_Filter_TD_6671766(tbl_SerializeFromObject_TD_7250566_input, tbl_Filter_TD_6671766_output);
    gettimeofday(&tv_r_Filter_6_26938_e, 0);

    struct timeval tv_r_Filter_6_893417_s, tv_r_Filter_6_893417_e;
    gettimeofday(&tv_r_Filter_6_893417_s, 0);
    SW_Filter_TD_6149814(tbl_JOIN_EXISTENCEJOINEXISTS19579_TD_7169608_output, tbl_Filter_TD_6149814_output);
    gettimeofday(&tv_r_Filter_6_893417_e, 0);

    struct timeval tv_r_Filter_5_97591_s, tv_r_Filter_5_97591_e;
    gettimeofday(&tv_r_Filter_5_97591_s, 0);
    SW_Filter_TD_5298468(tbl_SerializeFromObject_TD_628796_input, tbl_Filter_TD_5298468_output);
    gettimeofday(&tv_r_Filter_5_97591_e, 0);

    struct timeval tv_r_JOIN_INNER_5_316815_s, tv_r_JOIN_INNER_5_316815_e;
    gettimeofday(&tv_r_JOIN_INNER_5_316815_s, 0);
    SW_JOIN_INNER_TD_5693658(tbl_Filter_TD_6149814_output, tbl_Filter_TD_6671766_output, tbl_JOIN_INNER_TD_5693658_output);
    gettimeofday(&tv_r_JOIN_INNER_5_316815_e, 0);

    struct timeval tv_r_JOIN_INNER_4_452638_s, tv_r_JOIN_INNER_4_452638_e;
    gettimeofday(&tv_r_JOIN_INNER_4_452638_s, 0);
    SW_JOIN_INNER_TD_4186727(tbl_JOIN_INNER_TD_5693658_output, tbl_Filter_TD_5298468_output, tbl_JOIN_INNER_TD_4186727_output);
    gettimeofday(&tv_r_JOIN_INNER_4_452638_e, 0);

    struct timeval tv_r_Aggregate_3_298262_s, tv_r_Aggregate_3_298262_e;
    gettimeofday(&tv_r_Aggregate_3_298262_s, 0);
    SW_Aggregate_TD_3220058(tbl_JOIN_INNER_TD_4186727_output, tbl_Aggregate_TD_3220058_output);
    gettimeofday(&tv_r_Aggregate_3_298262_e, 0);

    struct timeval tv_r_Sort_2_798588_s, tv_r_Sort_2_798588_e;
    gettimeofday(&tv_r_Sort_2_798588_s, 0);
    SW_Sort_TD_2165466(tbl_Aggregate_TD_3220058_output, tbl_Sort_TD_2165466_output);
    gettimeofday(&tv_r_Sort_2_798588_e, 0);

    struct timeval tv_r_LocalLimit_1_374972_s, tv_r_LocalLimit_1_374972_e;
    gettimeofday(&tv_r_LocalLimit_1_374972_s, 0);
    SW_LocalLimit_TD_131011(tbl_Sort_TD_2165466_output, tbl_LocalLimit_TD_131011_output);
    gettimeofday(&tv_r_LocalLimit_1_374972_e, 0);

    struct timeval tv_r_GlobalLimit_0_462094_s, tv_r_GlobalLimit_0_462094_e;
    gettimeofday(&tv_r_GlobalLimit_0_462094_s, 0);
    SW_GlobalLimit_TD_0251568(tbl_LocalLimit_TD_131011_output, tbl_GlobalLimit_TD_0251568_output);
    gettimeofday(&tv_r_GlobalLimit_0_462094_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_89985_s, &tv_r_Filter_11_89985_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12336791_input: " << tbl_SerializeFromObject_TD_12336791_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_541722_s, &tv_r_Filter_11_541722_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1271917_input: " << tbl_SerializeFromObject_TD_1271917_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_37167_s, &tv_r_Filter_10_37167_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11428496_input: " << tbl_SerializeFromObject_TD_11428496_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_202713_s, &tv_r_Filter_10_202713_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11216231_input: " << tbl_SerializeFromObject_TD_11216231_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_704917_s, &tv_r_JOIN_INNER_10_704917_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11595738_output: " << tbl_Filter_TD_11595738_output.getNumRow() << " " << "tbl_Filter_TD_11517247_output: " << tbl_Filter_TD_11517247_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_611843_s, &tv_r_Filter_10_611843_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11746427_input: " << tbl_SerializeFromObject_TD_11746427_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_426434_s, &tv_r_Filter_9_426434_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10283184_input: " << tbl_SerializeFromObject_TD_10283184_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_222380_s, &tv_r_Filter_9_222380_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10892815_input: " << tbl_SerializeFromObject_TD_10892815_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_815736_s, &tv_r_JOIN_INNER_9_815736_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10427051_output: " << tbl_Filter_TD_10427051_output.getNumRow() << " " << "tbl_Filter_TD_10279793_output: " << tbl_Filter_TD_10279793_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_9: " << tvdiff(&tv_r_JOIN_LEFTSEMI_9_882180_s, &tv_r_JOIN_LEFTSEMI_9_882180_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_1028200_output: " << tbl_Filter_TD_1028200_output.getNumRow() << " " << "tbl_JOIN_INNER_TD_10608355_output: " << tbl_JOIN_INNER_TD_10608355_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_828490_s, &tv_r_JOIN_INNER_8_828490_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9991107_output: " << tbl_Filter_TD_9991107_output.getNumRow() << " " << "tbl_Filter_TD_9460652_output: " << tbl_Filter_TD_9460652_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_EXISTENCEJOINEXISTS19578_8: " << tvdiff(&tv_r_JOIN_EXISTENCEJOINEXISTS19578_8_709446_s, &tv_r_JOIN_EXISTENCEJOINEXISTS19578_8_709446_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTSEMI_TD_9348623_output: " << tbl_JOIN_LEFTSEMI_TD_9348623_output.getNumRow() << " " << "tbl_JOIN_INNER_TD_9300891_output: " << tbl_JOIN_INNER_TD_9300891_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_EXISTENCEJOINEXISTS19579_7: " << tvdiff(&tv_r_JOIN_EXISTENCEJOINEXISTS19579_7_604954_s, &tv_r_JOIN_EXISTENCEJOINEXISTS19579_7_604954_e) / 1000.0 << " ms " 
     << "tbl_JOIN_EXISTENCEJOINEXISTS19578_TD_8137509_output: " << tbl_JOIN_EXISTENCEJOINEXISTS19578_TD_8137509_output.getNumRow() << " " << "tbl_JOIN_INNER_TD_8182040_output: " << tbl_JOIN_INNER_TD_8182040_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_26938_s, &tv_r_Filter_6_26938_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7250566_input: " << tbl_SerializeFromObject_TD_7250566_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_893417_s, &tv_r_Filter_6_893417_e) / 1000.0 << " ms " 
     << "tbl_JOIN_EXISTENCEJOINEXISTS19579_TD_7169608_output: " << tbl_JOIN_EXISTENCEJOINEXISTS19579_TD_7169608_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_97591_s, &tv_r_Filter_5_97591_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_628796_input: " << tbl_SerializeFromObject_TD_628796_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_316815_s, &tv_r_JOIN_INNER_5_316815_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6149814_output: " << tbl_Filter_TD_6149814_output.getNumRow() << " " << "tbl_Filter_TD_6671766_output: " << tbl_Filter_TD_6671766_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_452638_s, &tv_r_JOIN_INNER_4_452638_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5693658_output: " << tbl_JOIN_INNER_TD_5693658_output.getNumRow() << " " << "tbl_Filter_TD_5298468_output: " << tbl_Filter_TD_5298468_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_298262_s, &tv_r_Aggregate_3_298262_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4186727_output: " << tbl_JOIN_INNER_TD_4186727_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_798588_s, &tv_r_Sort_2_798588_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3220058_output: " << tbl_Aggregate_TD_3220058_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_374972_s, &tv_r_LocalLimit_1_374972_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2165466_output: " << tbl_Sort_TD_2165466_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_462094_s, &tv_r_GlobalLimit_0_462094_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_131011_output: " << tbl_LocalLimit_TD_131011_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.431129 * 1000 << "ms" << std::endl; 
    return 0; 
}
