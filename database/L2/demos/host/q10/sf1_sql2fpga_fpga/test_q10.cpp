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

#include "cfgFunc_q10.hpp" 
#include "q10.hpp" 

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
    std::cout << "NOTE:running query #10\n."; 
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
    Table tbl_GlobalLimit_TD_0635270_output("tbl_GlobalLimit_TD_0635270_output", 6100000, 14, "");
    tbl_GlobalLimit_TD_0635270_output.allocateHost();
    Table tbl_LocalLimit_TD_1501158_output("tbl_LocalLimit_TD_1501158_output", 6100000, 14, "");
    tbl_LocalLimit_TD_1501158_output.allocateHost();
    Table tbl_Sort_TD_2337436_output("tbl_Sort_TD_2337436_output", 6100000, 14, "");
    tbl_Sort_TD_2337436_output.allocateHost();
    Table tbl_Aggregate_TD_3424105_output("tbl_Aggregate_TD_3424105_output", 6100000, 14, "");
    tbl_Aggregate_TD_3424105_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4686642_output("tbl_JOIN_INNER_TD_4686642_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_4686642_output.allocateHost();
    Table tbl_JOIN_INNER_TD_532935_output("tbl_JOIN_INNER_TD_532935_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_532935_output.allocateHost();
    Table tbl_Filter_TD_5486844_output("tbl_Filter_TD_5486844_output", 6100000, 9, "");
    tbl_Filter_TD_5486844_output.allocateHost();
    Table tbl_Filter_TD_6583708_output("tbl_Filter_TD_6583708_output", 6100000, 2, "");
    tbl_Filter_TD_6583708_output.allocateHost();
    Table tbl_Filter_TD_6530669_output("tbl_Filter_TD_6530669_output", 6100000, 1, "");
    tbl_Filter_TD_6530669_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6720945_input;
    tbl_SerializeFromObject_TD_6720945_input = Table("customer_demographics", customer_demographics_n, 9, in_dir, "orc");
    tbl_SerializeFromObject_TD_6720945_input.addCol("cd_demo_sk", 4);
    tbl_SerializeFromObject_TD_6720945_input.addCol("cd_gender", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6720945_input.addCol("cd_marital_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6720945_input.addCol("cd_education_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6720945_input.addCol("cd_purchase_estimate", 4);
    tbl_SerializeFromObject_TD_6720945_input.addCol("cd_credit_rating", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6720945_input.addCol("cd_dep_count", 4);
    tbl_SerializeFromObject_TD_6720945_input.addCol("cd_dep_employed_count", 4);
    tbl_SerializeFromObject_TD_6720945_input.addCol("cd_dep_college_count", 4);
    tbl_SerializeFromObject_TD_6720945_input.allocateHost();
    tbl_SerializeFromObject_TD_6720945_input.loadHost();
    Table tbl_JOIN_EXISTENCEJOINEXISTS3707_TD_7884092_output("tbl_JOIN_EXISTENCEJOINEXISTS3707_TD_7884092_output", 6100000, 4, "");
    tbl_JOIN_EXISTENCEJOINEXISTS3707_TD_7884092_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7153701_input;
    tbl_SerializeFromObject_TD_7153701_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7153701_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_7153701_input.addCol("ca_county", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7153701_input.allocateHost();
    tbl_SerializeFromObject_TD_7153701_input.loadHost();
    Table tbl_JOIN_EXISTENCEJOINEXISTS3706_TD_8105759_output("tbl_JOIN_EXISTENCEJOINEXISTS3706_TD_8105759_output", 6100000, 4, "");
    tbl_JOIN_EXISTENCEJOINEXISTS3706_TD_8105759_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8369493_output("tbl_JOIN_INNER_TD_8369493_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_8369493_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_9524694_output("tbl_JOIN_LEFTSEMI_TD_9524694_output", 6100000, 3, "");
    tbl_JOIN_LEFTSEMI_TD_9524694_output.allocateHost();
    Table tbl_JOIN_INNER_TD_9813470_output("tbl_JOIN_INNER_TD_9813470_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_9813470_output.allocateHost();
    Table tbl_Filter_TD_9738061_output("tbl_Filter_TD_9738061_output", 6100000, 2, "");
    tbl_Filter_TD_9738061_output.allocateHost();
    Table tbl_Filter_TD_9771974_output("tbl_Filter_TD_9771974_output", 6100000, 1, "");
    tbl_Filter_TD_9771974_output.allocateHost();
    Table tbl_Filter_TD_10797617_output("tbl_Filter_TD_10797617_output", 6100000, 3, "");
    tbl_Filter_TD_10797617_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10273266_output("tbl_JOIN_INNER_TD_10273266_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_10273266_output.allocateHost();
    Table tbl_Filter_TD_10998105_output("tbl_Filter_TD_10998105_output", 6100000, 2, "");
    tbl_Filter_TD_10998105_output.allocateHost();
    Table tbl_Filter_TD_10458702_output("tbl_Filter_TD_10458702_output", 6100000, 1, "");
    tbl_Filter_TD_10458702_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10959747_input;
    tbl_SerializeFromObject_TD_10959747_input = Table("catalog_sales", catalog_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10959747_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10959747_input.addCol("cs_ship_customer_sk", 4);
    tbl_SerializeFromObject_TD_10959747_input.allocateHost();
    tbl_SerializeFromObject_TD_10959747_input.loadHost();
    Table tbl_SerializeFromObject_TD_10533693_input;
    tbl_SerializeFromObject_TD_10533693_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10533693_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10533693_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10533693_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_10533693_input.allocateHost();
    tbl_SerializeFromObject_TD_10533693_input.loadHost();
    Table tbl_SerializeFromObject_TD_11839181_input;
    tbl_SerializeFromObject_TD_11839181_input = Table("customer", customer_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11839181_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_11839181_input.addCol("c_current_cdemo_sk", 4);
    tbl_SerializeFromObject_TD_11839181_input.addCol("c_current_addr_sk", 4);
    tbl_SerializeFromObject_TD_11839181_input.allocateHost();
    tbl_SerializeFromObject_TD_11839181_input.loadHost();
    Table tbl_Filter_TD_1173219_output("tbl_Filter_TD_1173219_output", 6100000, 2, "");
    tbl_Filter_TD_1173219_output.allocateHost();
    Table tbl_Filter_TD_11840758_output("tbl_Filter_TD_11840758_output", 6100000, 1, "");
    tbl_Filter_TD_11840758_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11943181_input;
    tbl_SerializeFromObject_TD_11943181_input = Table("web_sales", web_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11943181_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_11943181_input.addCol("ws_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_11943181_input.allocateHost();
    tbl_SerializeFromObject_TD_11943181_input.loadHost();
    Table tbl_SerializeFromObject_TD_11300735_input;
    tbl_SerializeFromObject_TD_11300735_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11300735_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_11300735_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_11300735_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_11300735_input.allocateHost();
    tbl_SerializeFromObject_TD_11300735_input.loadHost();
    Table tbl_SerializeFromObject_TD_12406378_input;
    tbl_SerializeFromObject_TD_12406378_input = Table("store_sales", store_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12406378_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_12406378_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_12406378_input.allocateHost();
    tbl_SerializeFromObject_TD_12406378_input.loadHost();
    Table tbl_SerializeFromObject_TD_12752135_input;
    tbl_SerializeFromObject_TD_12752135_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_12752135_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_12752135_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_12752135_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_12752135_input.allocateHost();
    tbl_SerializeFromObject_TD_12752135_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_11_656031_s, tv_r_Filter_11_656031_e;
    gettimeofday(&tv_r_Filter_11_656031_s, 0);
    SW_Filter_TD_11840758(tbl_SerializeFromObject_TD_12752135_input, tbl_Filter_TD_11840758_output);
    gettimeofday(&tv_r_Filter_11_656031_e, 0);

    struct timeval tv_r_Filter_11_497751_s, tv_r_Filter_11_497751_e;
    gettimeofday(&tv_r_Filter_11_497751_s, 0);
    SW_Filter_TD_1173219(tbl_SerializeFromObject_TD_12406378_input, tbl_Filter_TD_1173219_output);
    gettimeofday(&tv_r_Filter_11_497751_e, 0);

    struct timeval tv_r_Filter_10_248797_s, tv_r_Filter_10_248797_e;
    gettimeofday(&tv_r_Filter_10_248797_s, 0);
    SW_Filter_TD_10458702(tbl_SerializeFromObject_TD_11300735_input, tbl_Filter_TD_10458702_output);
    gettimeofday(&tv_r_Filter_10_248797_e, 0);

    struct timeval tv_r_Filter_10_413032_s, tv_r_Filter_10_413032_e;
    gettimeofday(&tv_r_Filter_10_413032_s, 0);
    SW_Filter_TD_10998105(tbl_SerializeFromObject_TD_11943181_input, tbl_Filter_TD_10998105_output);
    gettimeofday(&tv_r_Filter_10_413032_e, 0);

    struct timeval tv_r_JOIN_INNER_10_658136_s, tv_r_JOIN_INNER_10_658136_e;
    gettimeofday(&tv_r_JOIN_INNER_10_658136_s, 0);
    SW_JOIN_INNER_TD_10273266(tbl_Filter_TD_1173219_output, tbl_Filter_TD_11840758_output, tbl_JOIN_INNER_TD_10273266_output);
    gettimeofday(&tv_r_JOIN_INNER_10_658136_e, 0);

    struct timeval tv_r_Filter_10_406776_s, tv_r_Filter_10_406776_e;
    gettimeofday(&tv_r_Filter_10_406776_s, 0);
    SW_Filter_TD_10797617(tbl_SerializeFromObject_TD_11839181_input, tbl_Filter_TD_10797617_output);
    gettimeofday(&tv_r_Filter_10_406776_e, 0);

    struct timeval tv_r_Filter_9_7003_s, tv_r_Filter_9_7003_e;
    gettimeofday(&tv_r_Filter_9_7003_s, 0);
    SW_Filter_TD_9771974(tbl_SerializeFromObject_TD_10533693_input, tbl_Filter_TD_9771974_output);
    gettimeofday(&tv_r_Filter_9_7003_e, 0);

    struct timeval tv_r_Filter_9_171783_s, tv_r_Filter_9_171783_e;
    gettimeofday(&tv_r_Filter_9_171783_s, 0);
    SW_Filter_TD_9738061(tbl_SerializeFromObject_TD_10959747_input, tbl_Filter_TD_9738061_output);
    gettimeofday(&tv_r_Filter_9_171783_e, 0);

    struct timeval tv_r_JOIN_INNER_9_547077_s, tv_r_JOIN_INNER_9_547077_e;
    gettimeofday(&tv_r_JOIN_INNER_9_547077_s, 0);
    SW_JOIN_INNER_TD_9813470(tbl_Filter_TD_10998105_output, tbl_Filter_TD_10458702_output, tbl_JOIN_INNER_TD_9813470_output);
    gettimeofday(&tv_r_JOIN_INNER_9_547077_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_9_481911_s, tv_r_JOIN_LEFTSEMI_9_481911_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_9_481911_s, 0);
    SW_JOIN_LEFTSEMI_TD_9524694(tbl_Filter_TD_10797617_output, tbl_JOIN_INNER_TD_10273266_output, tbl_JOIN_LEFTSEMI_TD_9524694_output);
    gettimeofday(&tv_r_JOIN_LEFTSEMI_9_481911_e, 0);

    struct timeval tv_r_JOIN_INNER_8_61883_s, tv_r_JOIN_INNER_8_61883_e;
    gettimeofday(&tv_r_JOIN_INNER_8_61883_s, 0);
    SW_JOIN_INNER_TD_8369493(tbl_Filter_TD_9738061_output, tbl_Filter_TD_9771974_output, tbl_JOIN_INNER_TD_8369493_output);
    gettimeofday(&tv_r_JOIN_INNER_8_61883_e, 0);

    struct timeval tv_r_JOIN_EXISTENCEJOINEXISTS3706_8_376357_s, tv_r_JOIN_EXISTENCEJOINEXISTS3706_8_376357_e;
    gettimeofday(&tv_r_JOIN_EXISTENCEJOINEXISTS3706_8_376357_s, 0);
    SW_JOIN_EXISTENCEJOINEXISTS3706_TD_8105759(tbl_JOIN_LEFTSEMI_TD_9524694_output, tbl_JOIN_INNER_TD_9813470_output, tbl_JOIN_EXISTENCEJOINEXISTS3706_TD_8105759_output);
    gettimeofday(&tv_r_JOIN_EXISTENCEJOINEXISTS3706_8_376357_e, 0);

    struct timeval tv_r_JOIN_EXISTENCEJOINEXISTS3707_7_192547_s, tv_r_JOIN_EXISTENCEJOINEXISTS3707_7_192547_e;
    gettimeofday(&tv_r_JOIN_EXISTENCEJOINEXISTS3707_7_192547_s, 0);
    SW_JOIN_EXISTENCEJOINEXISTS3707_TD_7884092(tbl_JOIN_EXISTENCEJOINEXISTS3706_TD_8105759_output, tbl_JOIN_INNER_TD_8369493_output, tbl_JOIN_EXISTENCEJOINEXISTS3707_TD_7884092_output);
    gettimeofday(&tv_r_JOIN_EXISTENCEJOINEXISTS3707_7_192547_e, 0);

    struct timeval tv_r_Filter_6_883219_s, tv_r_Filter_6_883219_e;
    gettimeofday(&tv_r_Filter_6_883219_s, 0);
    SW_Filter_TD_6530669(tbl_SerializeFromObject_TD_7153701_input, tbl_Filter_TD_6530669_output);
    gettimeofday(&tv_r_Filter_6_883219_e, 0);

    struct timeval tv_r_Filter_6_798709_s, tv_r_Filter_6_798709_e;
    gettimeofday(&tv_r_Filter_6_798709_s, 0);
    SW_Filter_TD_6583708(tbl_JOIN_EXISTENCEJOINEXISTS3707_TD_7884092_output, tbl_Filter_TD_6583708_output);
    gettimeofday(&tv_r_Filter_6_798709_e, 0);

    struct timeval tv_r_Filter_5_974727_s, tv_r_Filter_5_974727_e;
    gettimeofday(&tv_r_Filter_5_974727_s, 0);
    SW_Filter_TD_5486844(tbl_SerializeFromObject_TD_6720945_input, tbl_Filter_TD_5486844_output);
    gettimeofday(&tv_r_Filter_5_974727_e, 0);

    struct timeval tv_r_JOIN_INNER_5_383809_s, tv_r_JOIN_INNER_5_383809_e;
    gettimeofday(&tv_r_JOIN_INNER_5_383809_s, 0);
    SW_JOIN_INNER_TD_532935(tbl_Filter_TD_6583708_output, tbl_Filter_TD_6530669_output, tbl_JOIN_INNER_TD_532935_output);
    gettimeofday(&tv_r_JOIN_INNER_5_383809_e, 0);

    struct timeval tv_r_JOIN_INNER_4_195602_s, tv_r_JOIN_INNER_4_195602_e;
    gettimeofday(&tv_r_JOIN_INNER_4_195602_s, 0);
    SW_JOIN_INNER_TD_4686642(tbl_JOIN_INNER_TD_532935_output, tbl_Filter_TD_5486844_output, tbl_JOIN_INNER_TD_4686642_output);
    gettimeofday(&tv_r_JOIN_INNER_4_195602_e, 0);

    struct timeval tv_r_Aggregate_3_729013_s, tv_r_Aggregate_3_729013_e;
    gettimeofday(&tv_r_Aggregate_3_729013_s, 0);
    SW_Aggregate_TD_3424105(tbl_JOIN_INNER_TD_4686642_output, tbl_Aggregate_TD_3424105_output);
    gettimeofday(&tv_r_Aggregate_3_729013_e, 0);

    struct timeval tv_r_Sort_2_504838_s, tv_r_Sort_2_504838_e;
    gettimeofday(&tv_r_Sort_2_504838_s, 0);
    SW_Sort_TD_2337436(tbl_Aggregate_TD_3424105_output, tbl_Sort_TD_2337436_output);
    gettimeofday(&tv_r_Sort_2_504838_e, 0);

    struct timeval tv_r_LocalLimit_1_400112_s, tv_r_LocalLimit_1_400112_e;
    gettimeofday(&tv_r_LocalLimit_1_400112_s, 0);
    SW_LocalLimit_TD_1501158(tbl_Sort_TD_2337436_output, tbl_LocalLimit_TD_1501158_output);
    gettimeofday(&tv_r_LocalLimit_1_400112_e, 0);

    struct timeval tv_r_GlobalLimit_0_141285_s, tv_r_GlobalLimit_0_141285_e;
    gettimeofday(&tv_r_GlobalLimit_0_141285_s, 0);
    SW_GlobalLimit_TD_0635270(tbl_LocalLimit_TD_1501158_output, tbl_GlobalLimit_TD_0635270_output);
    gettimeofday(&tv_r_GlobalLimit_0_141285_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_656031_s, &tv_r_Filter_11_656031_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12752135_input: " << tbl_SerializeFromObject_TD_12752135_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_497751_s, &tv_r_Filter_11_497751_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12406378_input: " << tbl_SerializeFromObject_TD_12406378_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_248797_s, &tv_r_Filter_10_248797_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11300735_input: " << tbl_SerializeFromObject_TD_11300735_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_413032_s, &tv_r_Filter_10_413032_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11943181_input: " << tbl_SerializeFromObject_TD_11943181_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_658136_s, &tv_r_JOIN_INNER_10_658136_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_1173219_output: " << tbl_Filter_TD_1173219_output.getNumRow() << " " << "tbl_Filter_TD_11840758_output: " << tbl_Filter_TD_11840758_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_406776_s, &tv_r_Filter_10_406776_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11839181_input: " << tbl_SerializeFromObject_TD_11839181_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_7003_s, &tv_r_Filter_9_7003_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10533693_input: " << tbl_SerializeFromObject_TD_10533693_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_171783_s, &tv_r_Filter_9_171783_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10959747_input: " << tbl_SerializeFromObject_TD_10959747_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_547077_s, &tv_r_JOIN_INNER_9_547077_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10998105_output: " << tbl_Filter_TD_10998105_output.getNumRow() << " " << "tbl_Filter_TD_10458702_output: " << tbl_Filter_TD_10458702_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_9: " << tvdiff(&tv_r_JOIN_LEFTSEMI_9_481911_s, &tv_r_JOIN_LEFTSEMI_9_481911_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10797617_output: " << tbl_Filter_TD_10797617_output.getNumRow() << " " << "tbl_JOIN_INNER_TD_10273266_output: " << tbl_JOIN_INNER_TD_10273266_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_61883_s, &tv_r_JOIN_INNER_8_61883_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9738061_output: " << tbl_Filter_TD_9738061_output.getNumRow() << " " << "tbl_Filter_TD_9771974_output: " << tbl_Filter_TD_9771974_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_EXISTENCEJOINEXISTS3706_8: " << tvdiff(&tv_r_JOIN_EXISTENCEJOINEXISTS3706_8_376357_s, &tv_r_JOIN_EXISTENCEJOINEXISTS3706_8_376357_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTSEMI_TD_9524694_output: " << tbl_JOIN_LEFTSEMI_TD_9524694_output.getNumRow() << " " << "tbl_JOIN_INNER_TD_9813470_output: " << tbl_JOIN_INNER_TD_9813470_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_EXISTENCEJOINEXISTS3707_7: " << tvdiff(&tv_r_JOIN_EXISTENCEJOINEXISTS3707_7_192547_s, &tv_r_JOIN_EXISTENCEJOINEXISTS3707_7_192547_e) / 1000.0 << " ms " 
     << "tbl_JOIN_EXISTENCEJOINEXISTS3706_TD_8105759_output: " << tbl_JOIN_EXISTENCEJOINEXISTS3706_TD_8105759_output.getNumRow() << " " << "tbl_JOIN_INNER_TD_8369493_output: " << tbl_JOIN_INNER_TD_8369493_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_883219_s, &tv_r_Filter_6_883219_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7153701_input: " << tbl_SerializeFromObject_TD_7153701_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_798709_s, &tv_r_Filter_6_798709_e) / 1000.0 << " ms " 
     << "tbl_JOIN_EXISTENCEJOINEXISTS3707_TD_7884092_output: " << tbl_JOIN_EXISTENCEJOINEXISTS3707_TD_7884092_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_974727_s, &tv_r_Filter_5_974727_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6720945_input: " << tbl_SerializeFromObject_TD_6720945_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_383809_s, &tv_r_JOIN_INNER_5_383809_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6583708_output: " << tbl_Filter_TD_6583708_output.getNumRow() << " " << "tbl_Filter_TD_6530669_output: " << tbl_Filter_TD_6530669_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_195602_s, &tv_r_JOIN_INNER_4_195602_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_532935_output: " << tbl_JOIN_INNER_TD_532935_output.getNumRow() << " " << "tbl_Filter_TD_5486844_output: " << tbl_Filter_TD_5486844_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_729013_s, &tv_r_Aggregate_3_729013_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4686642_output: " << tbl_JOIN_INNER_TD_4686642_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_504838_s, &tv_r_Sort_2_504838_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3424105_output: " << tbl_Aggregate_TD_3424105_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_400112_s, &tv_r_LocalLimit_1_400112_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2337436_output: " << tbl_Sort_TD_2337436_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_141285_s, &tv_r_GlobalLimit_0_141285_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1501158_output: " << tbl_LocalLimit_TD_1501158_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 3.729741 * 1000 << "ms" << std::endl; 
    return 0; 
}
