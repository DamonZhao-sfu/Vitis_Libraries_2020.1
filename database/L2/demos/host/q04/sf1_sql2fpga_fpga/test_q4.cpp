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

#include "cfgFunc_q4.hpp" 
#include "q4.hpp" 

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
    std::cout << "NOTE:running query #4\n."; 
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
    Table tbl_GlobalLimit_TD_094744_output("tbl_GlobalLimit_TD_094744_output", 6100000, 4, "");
    tbl_GlobalLimit_TD_094744_output.allocateHost();
    Table tbl_LocalLimit_TD_1827104_output("tbl_LocalLimit_TD_1827104_output", 6100000, 4, "");
    tbl_LocalLimit_TD_1827104_output.allocateHost();
    Table tbl_Sort_TD_2518178_output("tbl_Sort_TD_2518178_output", 6100000, 4, "");
    tbl_Sort_TD_2518178_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3549486_output("tbl_JOIN_INNER_TD_3549486_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_3549486_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4125986_output("tbl_JOIN_INNER_TD_4125986_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_4125986_output.allocateHost();
    Table tbl_Aggregate_TD_4731680_output("tbl_Aggregate_TD_4731680_output", 6100000, 1, "");
    tbl_Aggregate_TD_4731680_output.allocateHost();
    Table tbl_JOIN_INNER_TD_567869_output("tbl_JOIN_INNER_TD_567869_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_567869_output.allocateHost();
    Table tbl_Project_TD_5499769_output("tbl_Project_TD_5499769_output", 6100000, 1, "");
    tbl_Project_TD_5499769_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5399415_output("tbl_JOIN_INNER_TD_5399415_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_5399415_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6978445_output("tbl_JOIN_INNER_TD_6978445_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_6978445_output.allocateHost();
    Table tbl_Aggregate_TD_6888380_output("tbl_Aggregate_TD_6888380_output", 6100000, 1, "");
    tbl_Aggregate_TD_6888380_output.allocateHost();
    Table tbl_Filter_TD_68527_output("tbl_Filter_TD_68527_output", 6100000, 1, "");
    tbl_Filter_TD_68527_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6804084_output("tbl_JOIN_INNER_TD_6804084_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_6804084_output.allocateHost();
    Table tbl_Filter_TD_6163670_output("tbl_Filter_TD_6163670_output", 6100000, 2, "");
    tbl_Filter_TD_6163670_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7228170_output("tbl_JOIN_INNER_TD_7228170_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_7228170_output.allocateHost();
    Table tbl_Project_TD_7309655_output("tbl_Project_TD_7309655_output", 6100000, 1, "");
    tbl_Project_TD_7309655_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7196854_output("tbl_JOIN_INNER_TD_7196854_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_7196854_output.allocateHost();
    Table tbl_Aggregate_TD_7400563_output("tbl_Aggregate_TD_7400563_output", 6100000, 2, "");
    tbl_Aggregate_TD_7400563_output.allocateHost();
    Table tbl_Filter_TD_7347147_output("tbl_Filter_TD_7347147_output", 6100000, 8, "");
    tbl_Filter_TD_7347147_output.allocateHost();
    Table tbl_Filter_TD_7195484_output("tbl_Filter_TD_7195484_output", 6100000, 2, "");
    tbl_Filter_TD_7195484_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7850014_input;
    tbl_SerializeFromObject_TD_7850014_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7850014_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_7850014_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_7850014_input.allocateHost();
    tbl_SerializeFromObject_TD_7850014_input.loadHost();
    Table tbl_Filter_TD_8321963_output("tbl_Filter_TD_8321963_output", 6100000, 1, "");
    tbl_Filter_TD_8321963_output.allocateHost();
    Table tbl_Aggregate_TD_8273256_output("tbl_Aggregate_TD_8273256_output", 6100000, 4, "");
    tbl_Aggregate_TD_8273256_output.allocateHost();
    Table tbl_Filter_TD_8183160_output("tbl_Filter_TD_8183160_output", 6100000, 1, "");
    tbl_Filter_TD_8183160_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8473697_output("tbl_JOIN_INNER_TD_8473697_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_8473697_output.allocateHost();
    Table tbl_Filter_TD_8315128_output("tbl_Filter_TD_8315128_output", 6100000, 2, "");
    tbl_Filter_TD_8315128_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8303630_output("tbl_JOIN_INNER_TD_8303630_output", 6100000, 12, "");
    tbl_JOIN_INNER_TD_8303630_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8806662_input;
    tbl_SerializeFromObject_TD_8806662_input = Table("customer", customer_n, 8, in_dir, "orc");
    tbl_SerializeFromObject_TD_8806662_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_8806662_input.addCol("c_customer_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8806662_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8806662_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8806662_input.addCol("c_preferred_cust_flag", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8806662_input.addCol("c_birth_country", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8806662_input.addCol("c_login", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8806662_input.addCol("c_email_address", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8806662_input.allocateHost();
    tbl_SerializeFromObject_TD_8806662_input.loadHost();
    Table tbl_SerializeFromObject_TD_8398758_input;
    tbl_SerializeFromObject_TD_8398758_input = Table("web_sales", web_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8398758_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_8398758_input.addCol("ws_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_8398758_input.allocateHost();
    tbl_SerializeFromObject_TD_8398758_input.loadHost();
    Table tbl_Aggregate_TD_9482711_output("tbl_Aggregate_TD_9482711_output", 6100000, 2, "");
    tbl_Aggregate_TD_9482711_output.allocateHost();
    Table tbl_JOIN_INNER_TD_9331224_output("tbl_JOIN_INNER_TD_9331224_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_9331224_output.allocateHost();
    Table tbl_Aggregate_TD_919589_output("tbl_Aggregate_TD_919589_output", 6100000, 2, "");
    tbl_Aggregate_TD_919589_output.allocateHost();
    Table tbl_Filter_TD_990363_output("tbl_Filter_TD_990363_output", 6100000, 8, "");
    tbl_Filter_TD_990363_output.allocateHost();
    Table tbl_Filter_TD_9343399_output("tbl_Filter_TD_9343399_output", 6100000, 2, "");
    tbl_Filter_TD_9343399_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9401882_input;
    tbl_SerializeFromObject_TD_9401882_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9401882_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_9401882_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_9401882_input.allocateHost();
    tbl_SerializeFromObject_TD_9401882_input.loadHost();
    Table tbl_JOIN_INNER_TD_9827835_output("tbl_JOIN_INNER_TD_9827835_output", 6100000, 12, "");
    tbl_JOIN_INNER_TD_9827835_output.allocateHost();
    Table tbl_Filter_TD_9472472_output("tbl_Filter_TD_9472472_output", 6100000, 2, "");
    tbl_Filter_TD_9472472_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10119634_output("tbl_JOIN_INNER_TD_10119634_output", 6100000, 12, "");
    tbl_JOIN_INNER_TD_10119634_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10915984_output("tbl_JOIN_INNER_TD_10915984_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_10915984_output.allocateHost();
    Table tbl_Filter_TD_10239172_output("tbl_Filter_TD_10239172_output", 6100000, 2, "");
    tbl_Filter_TD_10239172_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10185218_output("tbl_JOIN_INNER_TD_10185218_output", 6100000, 12, "");
    tbl_JOIN_INNER_TD_10185218_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10360779_input;
    tbl_SerializeFromObject_TD_10360779_input = Table("customer", customer_n, 8, in_dir, "orc");
    tbl_SerializeFromObject_TD_10360779_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_10360779_input.addCol("c_customer_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10360779_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10360779_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10360779_input.addCol("c_preferred_cust_flag", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10360779_input.addCol("c_birth_country", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10360779_input.addCol("c_login", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10360779_input.addCol("c_email_address", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10360779_input.allocateHost();
    tbl_SerializeFromObject_TD_10360779_input.loadHost();
    Table tbl_SerializeFromObject_TD_1065884_input;
    tbl_SerializeFromObject_TD_1065884_input = Table("catalog_sales", catalog_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_1065884_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_1065884_input.addCol("cs_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_1065884_input.allocateHost();
    tbl_SerializeFromObject_TD_1065884_input.loadHost();
    Table tbl_Filter_TD_10966392_output("tbl_Filter_TD_10966392_output", 6100000, 8, "");
    tbl_Filter_TD_10966392_output.allocateHost();
    Table tbl_Filter_TD_10440338_output("tbl_Filter_TD_10440338_output", 6100000, 6, "");
    tbl_Filter_TD_10440338_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10827904_input;
    tbl_SerializeFromObject_TD_10827904_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10827904_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10827904_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10827904_input.allocateHost();
    tbl_SerializeFromObject_TD_10827904_input.loadHost();
    Table tbl_JOIN_INNER_TD_11823337_output("tbl_JOIN_INNER_TD_11823337_output", 6100000, 12, "");
    tbl_JOIN_INNER_TD_11823337_output.allocateHost();
    Table tbl_Filter_TD_11270920_output("tbl_Filter_TD_11270920_output", 6100000, 2, "");
    tbl_Filter_TD_11270920_output.allocateHost();
    Table tbl_Filter_TD_11355673_output("tbl_Filter_TD_11355673_output", 6100000, 8, "");
    tbl_Filter_TD_11355673_output.allocateHost();
    Table tbl_Filter_TD_11770821_output("tbl_Filter_TD_11770821_output", 6100000, 2, "");
    tbl_Filter_TD_11770821_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11709768_input;
    tbl_SerializeFromObject_TD_11709768_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11709768_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_11709768_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_11709768_input.allocateHost();
    tbl_SerializeFromObject_TD_11709768_input.loadHost();
    Table tbl_JOIN_INNER_TD_11806703_output("tbl_JOIN_INNER_TD_11806703_output", 6100000, 12, "");
    tbl_JOIN_INNER_TD_11806703_output.allocateHost();
    Table tbl_Filter_TD_1111564_output("tbl_Filter_TD_1111564_output", 6100000, 2, "");
    tbl_Filter_TD_1111564_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11120933_input;
    tbl_SerializeFromObject_TD_11120933_input = Table("customer", customer_n, 8, in_dir, "orc");
    tbl_SerializeFromObject_TD_11120933_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_11120933_input.addCol("c_customer_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11120933_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11120933_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11120933_input.addCol("c_preferred_cust_flag", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11120933_input.addCol("c_birth_country", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11120933_input.addCol("c_login", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11120933_input.addCol("c_email_address", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11120933_input.allocateHost();
    tbl_SerializeFromObject_TD_11120933_input.loadHost();
    Table tbl_SerializeFromObject_TD_11911995_input;
    tbl_SerializeFromObject_TD_11911995_input = Table("web_sales", web_sales_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_11911995_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_11911995_input.addCol("ws_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_11911995_input.addCol("ws_ext_discount_amt", 4);
    tbl_SerializeFromObject_TD_11911995_input.addCol("ws_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_11911995_input.addCol("ws_ext_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_11911995_input.addCol("ws_ext_list_price", 4);
    tbl_SerializeFromObject_TD_11911995_input.allocateHost();
    tbl_SerializeFromObject_TD_11911995_input.loadHost();
    Table tbl_Filter_TD_12786550_output("tbl_Filter_TD_12786550_output", 6100000, 8, "");
    tbl_Filter_TD_12786550_output.allocateHost();
    Table tbl_Filter_TD_12912549_output("tbl_Filter_TD_12912549_output", 6100000, 6, "");
    tbl_Filter_TD_12912549_output.allocateHost();
    Table tbl_SerializeFromObject_TD_1224704_input;
    tbl_SerializeFromObject_TD_1224704_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_1224704_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_1224704_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_1224704_input.allocateHost();
    tbl_SerializeFromObject_TD_1224704_input.loadHost();
    Table tbl_SerializeFromObject_TD_12145002_input;
    tbl_SerializeFromObject_TD_12145002_input = Table("customer", customer_n, 8, in_dir, "orc");
    tbl_SerializeFromObject_TD_12145002_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_12145002_input.addCol("c_customer_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_12145002_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_12145002_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_12145002_input.addCol("c_preferred_cust_flag", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_12145002_input.addCol("c_birth_country", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_12145002_input.addCol("c_login", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_12145002_input.addCol("c_email_address", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_12145002_input.allocateHost();
    tbl_SerializeFromObject_TD_12145002_input.loadHost();
    Table tbl_SerializeFromObject_TD_12880131_input;
    tbl_SerializeFromObject_TD_12880131_input = Table("store_sales", store_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12880131_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_12880131_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_12880131_input.allocateHost();
    tbl_SerializeFromObject_TD_12880131_input.loadHost();
    Table tbl_Filter_TD_12825046_output("tbl_Filter_TD_12825046_output", 6100000, 8, "");
    tbl_Filter_TD_12825046_output.allocateHost();
    Table tbl_Filter_TD_12646433_output("tbl_Filter_TD_12646433_output", 6100000, 6, "");
    tbl_Filter_TD_12646433_output.allocateHost();
    Table tbl_SerializeFromObject_TD_12424610_input;
    tbl_SerializeFromObject_TD_12424610_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12424610_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_12424610_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_12424610_input.allocateHost();
    tbl_SerializeFromObject_TD_12424610_input.loadHost();
    Table tbl_SerializeFromObject_TD_13137578_input;
    tbl_SerializeFromObject_TD_13137578_input = Table("customer", customer_n, 8, in_dir, "orc");
    tbl_SerializeFromObject_TD_13137578_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_13137578_input.addCol("c_customer_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13137578_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13137578_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13137578_input.addCol("c_preferred_cust_flag", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13137578_input.addCol("c_birth_country", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13137578_input.addCol("c_login", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13137578_input.addCol("c_email_address", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13137578_input.allocateHost();
    tbl_SerializeFromObject_TD_13137578_input.loadHost();
    Table tbl_SerializeFromObject_TD_13398411_input;
    tbl_SerializeFromObject_TD_13398411_input = Table("store_sales", store_sales_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_13398411_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_13398411_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_13398411_input.addCol("ss_ext_discount_amt", 4);
    tbl_SerializeFromObject_TD_13398411_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_13398411_input.addCol("ss_ext_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_13398411_input.addCol("ss_ext_list_price", 4);
    tbl_SerializeFromObject_TD_13398411_input.allocateHost();
    tbl_SerializeFromObject_TD_13398411_input.loadHost();
    Table tbl_SerializeFromObject_TD_13814225_input;
    tbl_SerializeFromObject_TD_13814225_input = Table("customer", customer_n, 8, in_dir, "orc");
    tbl_SerializeFromObject_TD_13814225_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_13814225_input.addCol("c_customer_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13814225_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13814225_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13814225_input.addCol("c_preferred_cust_flag", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13814225_input.addCol("c_birth_country", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13814225_input.addCol("c_login", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13814225_input.addCol("c_email_address", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13814225_input.allocateHost();
    tbl_SerializeFromObject_TD_13814225_input.loadHost();
    Table tbl_SerializeFromObject_TD_13357717_input;
    tbl_SerializeFromObject_TD_13357717_input = Table("catalog_sales", catalog_sales_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_13357717_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_13357717_input.addCol("cs_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_13357717_input.addCol("cs_ext_discount_amt", 4);
    tbl_SerializeFromObject_TD_13357717_input.addCol("cs_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_13357717_input.addCol("cs_ext_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_13357717_input.addCol("cs_ext_list_price", 4);
    tbl_SerializeFromObject_TD_13357717_input.allocateHost();
    tbl_SerializeFromObject_TD_13357717_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_12_322804_s, tv_r_Filter_12_322804_e;
    gettimeofday(&tv_r_Filter_12_322804_s, 0);
    SW_Filter_TD_12646433(tbl_SerializeFromObject_TD_13357717_input, tbl_Filter_TD_12646433_output);
    gettimeofday(&tv_r_Filter_12_322804_e, 0);

    struct timeval tv_r_Filter_12_314395_s, tv_r_Filter_12_314395_e;
    gettimeofday(&tv_r_Filter_12_314395_s, 0);
    SW_Filter_TD_12825046(tbl_SerializeFromObject_TD_13814225_input, tbl_Filter_TD_12825046_output);
    gettimeofday(&tv_r_Filter_12_314395_e, 0);

    struct timeval tv_r_Filter_12_954725_s, tv_r_Filter_12_954725_e;
    gettimeofday(&tv_r_Filter_12_954725_s, 0);
    SW_Filter_TD_12912549(tbl_SerializeFromObject_TD_13398411_input, tbl_Filter_TD_12912549_output);
    gettimeofday(&tv_r_Filter_12_954725_e, 0);

    struct timeval tv_r_Filter_12_93811_s, tv_r_Filter_12_93811_e;
    gettimeofday(&tv_r_Filter_12_93811_s, 0);
    SW_Filter_TD_12786550(tbl_SerializeFromObject_TD_13137578_input, tbl_Filter_TD_12786550_output);
    gettimeofday(&tv_r_Filter_12_93811_e, 0);

    struct timeval tv_r_Filter_11_615227_s, tv_r_Filter_11_615227_e;
    gettimeofday(&tv_r_Filter_11_615227_s, 0);
    SW_Filter_TD_1111564(tbl_SerializeFromObject_TD_12424610_input, tbl_Filter_TD_1111564_output);
    gettimeofday(&tv_r_Filter_11_615227_e, 0);

    struct timeval tv_r_JOIN_INNER_11_251959_s, tv_r_JOIN_INNER_11_251959_e;
    gettimeofday(&tv_r_JOIN_INNER_11_251959_s, 0);
    SW_JOIN_INNER_TD_11806703(tbl_Filter_TD_12825046_output, tbl_Filter_TD_12646433_output, tbl_JOIN_INNER_TD_11806703_output);
    gettimeofday(&tv_r_JOIN_INNER_11_251959_e, 0);

    struct timeval tv_r_Filter_11_321980_s, tv_r_Filter_11_321980_e;
    gettimeofday(&tv_r_Filter_11_321980_s, 0);
    SW_Filter_TD_11770821(tbl_SerializeFromObject_TD_12880131_input, tbl_Filter_TD_11770821_output);
    gettimeofday(&tv_r_Filter_11_321980_e, 0);

    struct timeval tv_r_Filter_11_480083_s, tv_r_Filter_11_480083_e;
    gettimeofday(&tv_r_Filter_11_480083_s, 0);
    SW_Filter_TD_11355673(tbl_SerializeFromObject_TD_12145002_input, tbl_Filter_TD_11355673_output);
    gettimeofday(&tv_r_Filter_11_480083_e, 0);

    struct timeval tv_r_Filter_11_435447_s, tv_r_Filter_11_435447_e;
    gettimeofday(&tv_r_Filter_11_435447_s, 0);
    SW_Filter_TD_11270920(tbl_SerializeFromObject_TD_1224704_input, tbl_Filter_TD_11270920_output);
    gettimeofday(&tv_r_Filter_11_435447_e, 0);

    struct timeval tv_r_JOIN_INNER_11_344422_s, tv_r_JOIN_INNER_11_344422_e;
    gettimeofday(&tv_r_JOIN_INNER_11_344422_s, 0);
    SW_JOIN_INNER_TD_11823337(tbl_Filter_TD_12786550_output, tbl_Filter_TD_12912549_output, tbl_JOIN_INNER_TD_11823337_output);
    gettimeofday(&tv_r_JOIN_INNER_11_344422_e, 0);

    struct timeval tv_r_Filter_10_241390_s, tv_r_Filter_10_241390_e;
    gettimeofday(&tv_r_Filter_10_241390_s, 0);
    SW_Filter_TD_10440338(tbl_SerializeFromObject_TD_11911995_input, tbl_Filter_TD_10440338_output);
    gettimeofday(&tv_r_Filter_10_241390_e, 0);

    struct timeval tv_r_Filter_10_804490_s, tv_r_Filter_10_804490_e;
    gettimeofday(&tv_r_Filter_10_804490_s, 0);
    SW_Filter_TD_10966392(tbl_SerializeFromObject_TD_11120933_input, tbl_Filter_TD_10966392_output);
    gettimeofday(&tv_r_Filter_10_804490_e, 0);

    struct timeval tv_r_JOIN_INNER_10_889152_s, tv_r_JOIN_INNER_10_889152_e;
    gettimeofday(&tv_r_JOIN_INNER_10_889152_s, 0);
    SW_JOIN_INNER_TD_10185218(tbl_JOIN_INNER_TD_11806703_output, tbl_Filter_TD_1111564_output, tbl_JOIN_INNER_TD_10185218_output);
    gettimeofday(&tv_r_JOIN_INNER_10_889152_e, 0);

    struct timeval tv_r_Filter_10_881026_s, tv_r_Filter_10_881026_e;
    gettimeofday(&tv_r_Filter_10_881026_s, 0);
    SW_Filter_TD_10239172(tbl_SerializeFromObject_TD_11709768_input, tbl_Filter_TD_10239172_output);
    gettimeofday(&tv_r_Filter_10_881026_e, 0);

    struct timeval tv_r_JOIN_INNER_10_952991_s, tv_r_JOIN_INNER_10_952991_e;
    gettimeofday(&tv_r_JOIN_INNER_10_952991_s, 0);
    SW_JOIN_INNER_TD_10915984(tbl_Filter_TD_11355673_output, tbl_Filter_TD_11770821_output, tbl_JOIN_INNER_TD_10915984_output);
    gettimeofday(&tv_r_JOIN_INNER_10_952991_e, 0);

    struct timeval tv_r_JOIN_INNER_10_999513_s, tv_r_JOIN_INNER_10_999513_e;
    gettimeofday(&tv_r_JOIN_INNER_10_999513_s, 0);
    SW_JOIN_INNER_TD_10119634(tbl_JOIN_INNER_TD_11823337_output, tbl_Filter_TD_11270920_output, tbl_JOIN_INNER_TD_10119634_output);
    gettimeofday(&tv_r_JOIN_INNER_10_999513_e, 0);

    struct timeval tv_r_Filter_9_229546_s, tv_r_Filter_9_229546_e;
    gettimeofday(&tv_r_Filter_9_229546_s, 0);
    SW_Filter_TD_9472472(tbl_SerializeFromObject_TD_10827904_input, tbl_Filter_TD_9472472_output);
    gettimeofday(&tv_r_Filter_9_229546_e, 0);

    struct timeval tv_r_JOIN_INNER_9_620709_s, tv_r_JOIN_INNER_9_620709_e;
    gettimeofday(&tv_r_JOIN_INNER_9_620709_s, 0);
    SW_JOIN_INNER_TD_9827835(tbl_Filter_TD_10966392_output, tbl_Filter_TD_10440338_output, tbl_JOIN_INNER_TD_9827835_output);
    gettimeofday(&tv_r_JOIN_INNER_9_620709_e, 0);

    struct timeval tv_r_Filter_9_667962_s, tv_r_Filter_9_667962_e;
    gettimeofday(&tv_r_Filter_9_667962_s, 0);
    SW_Filter_TD_9343399(tbl_SerializeFromObject_TD_1065884_input, tbl_Filter_TD_9343399_output);
    gettimeofday(&tv_r_Filter_9_667962_e, 0);

    struct timeval tv_r_Filter_9_272980_s, tv_r_Filter_9_272980_e;
    gettimeofday(&tv_r_Filter_9_272980_s, 0);
    SW_Filter_TD_990363(tbl_SerializeFromObject_TD_10360779_input, tbl_Filter_TD_990363_output);
    gettimeofday(&tv_r_Filter_9_272980_e, 0);

    struct timeval tv_r_Aggregate_9_838273_s, tv_r_Aggregate_9_838273_e;
    gettimeofday(&tv_r_Aggregate_9_838273_s, 0);
    SW_Aggregate_TD_919589(tbl_JOIN_INNER_TD_10185218_output, tbl_Aggregate_TD_919589_output);
    gettimeofday(&tv_r_Aggregate_9_838273_e, 0);

    struct timeval tv_r_JOIN_INNER_9_533270_s, tv_r_JOIN_INNER_9_533270_e;
    gettimeofday(&tv_r_JOIN_INNER_9_533270_s, 0);
    SW_JOIN_INNER_TD_9331224(tbl_JOIN_INNER_TD_10915984_output, tbl_Filter_TD_10239172_output, tbl_JOIN_INNER_TD_9331224_output);
    gettimeofday(&tv_r_JOIN_INNER_9_533270_e, 0);

    struct timeval tv_r_Aggregate_9_940925_s, tv_r_Aggregate_9_940925_e;
    gettimeofday(&tv_r_Aggregate_9_940925_s, 0);
    SW_Aggregate_TD_9482711(tbl_JOIN_INNER_TD_10119634_output, tbl_Aggregate_TD_9482711_output);
    gettimeofday(&tv_r_Aggregate_9_940925_e, 0);

    struct timeval tv_r_JOIN_INNER_8_441185_s, tv_r_JOIN_INNER_8_441185_e;
    gettimeofday(&tv_r_JOIN_INNER_8_441185_s, 0);
    SW_JOIN_INNER_TD_8303630(tbl_JOIN_INNER_TD_9827835_output, tbl_Filter_TD_9472472_output, tbl_JOIN_INNER_TD_8303630_output);
    gettimeofday(&tv_r_JOIN_INNER_8_441185_e, 0);

    struct timeval tv_r_Filter_8_9766_s, tv_r_Filter_8_9766_e;
    gettimeofday(&tv_r_Filter_8_9766_s, 0);
    SW_Filter_TD_8315128(tbl_SerializeFromObject_TD_9401882_input, tbl_Filter_TD_8315128_output);
    gettimeofday(&tv_r_Filter_8_9766_e, 0);

    struct timeval tv_r_JOIN_INNER_8_719003_s, tv_r_JOIN_INNER_8_719003_e;
    gettimeofday(&tv_r_JOIN_INNER_8_719003_s, 0);
    SW_JOIN_INNER_TD_8473697(tbl_Filter_TD_990363_output, tbl_Filter_TD_9343399_output, tbl_JOIN_INNER_TD_8473697_output);
    gettimeofday(&tv_r_JOIN_INNER_8_719003_e, 0);

    struct timeval tv_r_Filter_8_184286_s, tv_r_Filter_8_184286_e;
    gettimeofday(&tv_r_Filter_8_184286_s, 0);
    SW_Filter_TD_8183160(tbl_Aggregate_TD_919589_output, tbl_Filter_TD_8183160_output);
    gettimeofday(&tv_r_Filter_8_184286_e, 0);

    struct timeval tv_r_Aggregate_8_474399_s, tv_r_Aggregate_8_474399_e;
    gettimeofday(&tv_r_Aggregate_8_474399_s, 0);
    SW_Aggregate_TD_8273256(tbl_JOIN_INNER_TD_9331224_output, tbl_Aggregate_TD_8273256_output);
    gettimeofday(&tv_r_Aggregate_8_474399_e, 0);

    struct timeval tv_r_Filter_8_264833_s, tv_r_Filter_8_264833_e;
    gettimeofday(&tv_r_Filter_8_264833_s, 0);
    SW_Filter_TD_8321963(tbl_Aggregate_TD_9482711_output, tbl_Filter_TD_8321963_output);
    gettimeofday(&tv_r_Filter_8_264833_e, 0);

    struct timeval tv_r_Filter_7_81906_s, tv_r_Filter_7_81906_e;
    gettimeofday(&tv_r_Filter_7_81906_s, 0);
    SW_Filter_TD_7195484(tbl_SerializeFromObject_TD_8398758_input, tbl_Filter_TD_7195484_output);
    gettimeofday(&tv_r_Filter_7_81906_e, 0);

    struct timeval tv_r_Filter_7_682521_s, tv_r_Filter_7_682521_e;
    gettimeofday(&tv_r_Filter_7_682521_s, 0);
    SW_Filter_TD_7347147(tbl_SerializeFromObject_TD_8806662_input, tbl_Filter_TD_7347147_output);
    gettimeofday(&tv_r_Filter_7_682521_e, 0);

    struct timeval tv_r_Aggregate_7_676195_s, tv_r_Aggregate_7_676195_e;
    gettimeofday(&tv_r_Aggregate_7_676195_s, 0);
    SW_Aggregate_TD_7400563(tbl_JOIN_INNER_TD_8303630_output, tbl_Aggregate_TD_7400563_output);
    gettimeofday(&tv_r_Aggregate_7_676195_e, 0);

    struct timeval tv_r_JOIN_INNER_7_531169_s, tv_r_JOIN_INNER_7_531169_e;
    gettimeofday(&tv_r_JOIN_INNER_7_531169_s, 0);
    SW_JOIN_INNER_TD_7196854(tbl_JOIN_INNER_TD_8473697_output, tbl_Filter_TD_8315128_output, tbl_JOIN_INNER_TD_7196854_output);
    gettimeofday(&tv_r_JOIN_INNER_7_531169_e, 0);

    struct timeval tv_r_Project_7_108954_s, tv_r_Project_7_108954_e;
    gettimeofday(&tv_r_Project_7_108954_s, 0);
    SW_Project_TD_7309655(tbl_Filter_TD_8183160_output, tbl_Project_TD_7309655_output);
    gettimeofday(&tv_r_Project_7_108954_e, 0);

    struct timeval tv_r_JOIN_INNER_7_836375_s, tv_r_JOIN_INNER_7_836375_e;
    gettimeofday(&tv_r_JOIN_INNER_7_836375_s, 0);
    SW_JOIN_INNER_TD_7228170(tbl_Filter_TD_8321963_output, tbl_Aggregate_TD_8273256_output, tbl_JOIN_INNER_TD_7228170_output);
    gettimeofday(&tv_r_JOIN_INNER_7_836375_e, 0);

    struct timeval tv_r_Filter_6_246493_s, tv_r_Filter_6_246493_e;
    gettimeofday(&tv_r_Filter_6_246493_s, 0);
    SW_Filter_TD_6163670(tbl_SerializeFromObject_TD_7850014_input, tbl_Filter_TD_6163670_output);
    gettimeofday(&tv_r_Filter_6_246493_e, 0);

    struct timeval tv_r_JOIN_INNER_6_708472_s, tv_r_JOIN_INNER_6_708472_e;
    gettimeofday(&tv_r_JOIN_INNER_6_708472_s, 0);
    SW_JOIN_INNER_TD_6804084(tbl_Filter_TD_7347147_output, tbl_Filter_TD_7195484_output, tbl_JOIN_INNER_TD_6804084_output);
    gettimeofday(&tv_r_JOIN_INNER_6_708472_e, 0);

    struct timeval tv_r_Filter_6_386572_s, tv_r_Filter_6_386572_e;
    gettimeofday(&tv_r_Filter_6_386572_s, 0);
    SW_Filter_TD_68527(tbl_Aggregate_TD_7400563_output, tbl_Filter_TD_68527_output);
    gettimeofday(&tv_r_Filter_6_386572_e, 0);

    struct timeval tv_r_Aggregate_6_420924_s, tv_r_Aggregate_6_420924_e;
    gettimeofday(&tv_r_Aggregate_6_420924_s, 0);
    SW_Aggregate_TD_6888380(tbl_JOIN_INNER_TD_7196854_output, tbl_Aggregate_TD_6888380_output);
    gettimeofday(&tv_r_Aggregate_6_420924_e, 0);

    struct timeval tv_r_JOIN_INNER_6_309721_s, tv_r_JOIN_INNER_6_309721_e;
    gettimeofday(&tv_r_JOIN_INNER_6_309721_s, 0);
    SW_JOIN_INNER_TD_6978445(tbl_JOIN_INNER_TD_7228170_output, tbl_Project_TD_7309655_output, tbl_JOIN_INNER_TD_6978445_output);
    gettimeofday(&tv_r_JOIN_INNER_6_309721_e, 0);

    struct timeval tv_r_JOIN_INNER_5_109292_s, tv_r_JOIN_INNER_5_109292_e;
    gettimeofday(&tv_r_JOIN_INNER_5_109292_s, 0);
    SW_JOIN_INNER_TD_5399415(tbl_JOIN_INNER_TD_6804084_output, tbl_Filter_TD_6163670_output, tbl_JOIN_INNER_TD_5399415_output);
    gettimeofday(&tv_r_JOIN_INNER_5_109292_e, 0);

    struct timeval tv_r_Project_5_965703_s, tv_r_Project_5_965703_e;
    gettimeofday(&tv_r_Project_5_965703_s, 0);
    SW_Project_TD_5499769(tbl_Filter_TD_68527_output, tbl_Project_TD_5499769_output);
    gettimeofday(&tv_r_Project_5_965703_e, 0);

    struct timeval tv_r_JOIN_INNER_5_702029_s, tv_r_JOIN_INNER_5_702029_e;
    gettimeofday(&tv_r_JOIN_INNER_5_702029_s, 0);
    SW_JOIN_INNER_TD_567869(tbl_JOIN_INNER_TD_6978445_output, tbl_Aggregate_TD_6888380_output, tbl_JOIN_INNER_TD_567869_output);
    gettimeofday(&tv_r_JOIN_INNER_5_702029_e, 0);

    struct timeval tv_r_Aggregate_4_417698_s, tv_r_Aggregate_4_417698_e;
    gettimeofday(&tv_r_Aggregate_4_417698_s, 0);
    SW_Aggregate_TD_4731680(tbl_JOIN_INNER_TD_5399415_output, tbl_Aggregate_TD_4731680_output);
    gettimeofday(&tv_r_Aggregate_4_417698_e, 0);

    struct timeval tv_r_JOIN_INNER_4_932699_s, tv_r_JOIN_INNER_4_932699_e;
    gettimeofday(&tv_r_JOIN_INNER_4_932699_s, 0);
    SW_JOIN_INNER_TD_4125986(tbl_JOIN_INNER_TD_567869_output, tbl_Project_TD_5499769_output, tbl_JOIN_INNER_TD_4125986_output);
    gettimeofday(&tv_r_JOIN_INNER_4_932699_e, 0);

    struct timeval tv_r_JOIN_INNER_3_770249_s, tv_r_JOIN_INNER_3_770249_e;
    gettimeofday(&tv_r_JOIN_INNER_3_770249_s, 0);
    SW_JOIN_INNER_TD_3549486(tbl_JOIN_INNER_TD_4125986_output, tbl_Aggregate_TD_4731680_output, tbl_JOIN_INNER_TD_3549486_output);
    gettimeofday(&tv_r_JOIN_INNER_3_770249_e, 0);

    struct timeval tv_r_Sort_2_675196_s, tv_r_Sort_2_675196_e;
    gettimeofday(&tv_r_Sort_2_675196_s, 0);
    SW_Sort_TD_2518178(tbl_JOIN_INNER_TD_3549486_output, tbl_Sort_TD_2518178_output);
    gettimeofday(&tv_r_Sort_2_675196_e, 0);

    struct timeval tv_r_LocalLimit_1_85569_s, tv_r_LocalLimit_1_85569_e;
    gettimeofday(&tv_r_LocalLimit_1_85569_s, 0);
    SW_LocalLimit_TD_1827104(tbl_Sort_TD_2518178_output, tbl_LocalLimit_TD_1827104_output);
    gettimeofday(&tv_r_LocalLimit_1_85569_e, 0);

    struct timeval tv_r_GlobalLimit_0_81518_s, tv_r_GlobalLimit_0_81518_e;
    gettimeofday(&tv_r_GlobalLimit_0_81518_s, 0);
    SW_GlobalLimit_TD_094744(tbl_LocalLimit_TD_1827104_output, tbl_GlobalLimit_TD_094744_output);
    gettimeofday(&tv_r_GlobalLimit_0_81518_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_322804_s, &tv_r_Filter_12_322804_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13357717_input: " << tbl_SerializeFromObject_TD_13357717_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_314395_s, &tv_r_Filter_12_314395_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13814225_input: " << tbl_SerializeFromObject_TD_13814225_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_954725_s, &tv_r_Filter_12_954725_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13398411_input: " << tbl_SerializeFromObject_TD_13398411_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_93811_s, &tv_r_Filter_12_93811_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13137578_input: " << tbl_SerializeFromObject_TD_13137578_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_615227_s, &tv_r_Filter_11_615227_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12424610_input: " << tbl_SerializeFromObject_TD_12424610_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_11: " << tvdiff(&tv_r_JOIN_INNER_11_251959_s, &tv_r_JOIN_INNER_11_251959_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_12825046_output: " << tbl_Filter_TD_12825046_output.getNumRow() << " " << "tbl_Filter_TD_12646433_output: " << tbl_Filter_TD_12646433_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_321980_s, &tv_r_Filter_11_321980_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12880131_input: " << tbl_SerializeFromObject_TD_12880131_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_480083_s, &tv_r_Filter_11_480083_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12145002_input: " << tbl_SerializeFromObject_TD_12145002_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_435447_s, &tv_r_Filter_11_435447_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1224704_input: " << tbl_SerializeFromObject_TD_1224704_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_11: " << tvdiff(&tv_r_JOIN_INNER_11_344422_s, &tv_r_JOIN_INNER_11_344422_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_12786550_output: " << tbl_Filter_TD_12786550_output.getNumRow() << " " << "tbl_Filter_TD_12912549_output: " << tbl_Filter_TD_12912549_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_241390_s, &tv_r_Filter_10_241390_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11911995_input: " << tbl_SerializeFromObject_TD_11911995_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_804490_s, &tv_r_Filter_10_804490_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11120933_input: " << tbl_SerializeFromObject_TD_11120933_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_889152_s, &tv_r_JOIN_INNER_10_889152_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_11806703_output: " << tbl_JOIN_INNER_TD_11806703_output.getNumRow() << " " << "tbl_Filter_TD_1111564_output: " << tbl_Filter_TD_1111564_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_881026_s, &tv_r_Filter_10_881026_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11709768_input: " << tbl_SerializeFromObject_TD_11709768_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_952991_s, &tv_r_JOIN_INNER_10_952991_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11355673_output: " << tbl_Filter_TD_11355673_output.getNumRow() << " " << "tbl_Filter_TD_11770821_output: " << tbl_Filter_TD_11770821_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_999513_s, &tv_r_JOIN_INNER_10_999513_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_11823337_output: " << tbl_JOIN_INNER_TD_11823337_output.getNumRow() << " " << "tbl_Filter_TD_11270920_output: " << tbl_Filter_TD_11270920_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_229546_s, &tv_r_Filter_9_229546_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10827904_input: " << tbl_SerializeFromObject_TD_10827904_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_620709_s, &tv_r_JOIN_INNER_9_620709_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10966392_output: " << tbl_Filter_TD_10966392_output.getNumRow() << " " << "tbl_Filter_TD_10440338_output: " << tbl_Filter_TD_10440338_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_667962_s, &tv_r_Filter_9_667962_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1065884_input: " << tbl_SerializeFromObject_TD_1065884_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_272980_s, &tv_r_Filter_9_272980_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10360779_input: " << tbl_SerializeFromObject_TD_10360779_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_9: " << tvdiff(&tv_r_Aggregate_9_838273_s, &tv_r_Aggregate_9_838273_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10185218_output: " << tbl_JOIN_INNER_TD_10185218_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_533270_s, &tv_r_JOIN_INNER_9_533270_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10915984_output: " << tbl_JOIN_INNER_TD_10915984_output.getNumRow() << " " << "tbl_Filter_TD_10239172_output: " << tbl_Filter_TD_10239172_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_9: " << tvdiff(&tv_r_Aggregate_9_940925_s, &tv_r_Aggregate_9_940925_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10119634_output: " << tbl_JOIN_INNER_TD_10119634_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_441185_s, &tv_r_JOIN_INNER_8_441185_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9827835_output: " << tbl_JOIN_INNER_TD_9827835_output.getNumRow() << " " << "tbl_Filter_TD_9472472_output: " << tbl_Filter_TD_9472472_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_9766_s, &tv_r_Filter_8_9766_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9401882_input: " << tbl_SerializeFromObject_TD_9401882_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_719003_s, &tv_r_JOIN_INNER_8_719003_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_990363_output: " << tbl_Filter_TD_990363_output.getNumRow() << " " << "tbl_Filter_TD_9343399_output: " << tbl_Filter_TD_9343399_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_184286_s, &tv_r_Filter_8_184286_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_919589_output: " << tbl_Aggregate_TD_919589_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_8: " << tvdiff(&tv_r_Aggregate_8_474399_s, &tv_r_Aggregate_8_474399_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9331224_output: " << tbl_JOIN_INNER_TD_9331224_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_264833_s, &tv_r_Filter_8_264833_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_9482711_output: " << tbl_Aggregate_TD_9482711_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_81906_s, &tv_r_Filter_7_81906_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8398758_input: " << tbl_SerializeFromObject_TD_8398758_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_682521_s, &tv_r_Filter_7_682521_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8806662_input: " << tbl_SerializeFromObject_TD_8806662_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_7: " << tvdiff(&tv_r_Aggregate_7_676195_s, &tv_r_Aggregate_7_676195_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8303630_output: " << tbl_JOIN_INNER_TD_8303630_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_531169_s, &tv_r_JOIN_INNER_7_531169_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8473697_output: " << tbl_JOIN_INNER_TD_8473697_output.getNumRow() << " " << "tbl_Filter_TD_8315128_output: " << tbl_Filter_TD_8315128_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_7: " << tvdiff(&tv_r_Project_7_108954_s, &tv_r_Project_7_108954_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8183160_output: " << tbl_Filter_TD_8183160_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_836375_s, &tv_r_JOIN_INNER_7_836375_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8321963_output: " << tbl_Filter_TD_8321963_output.getNumRow() << " " << "tbl_Aggregate_TD_8273256_output: " << tbl_Aggregate_TD_8273256_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_246493_s, &tv_r_Filter_6_246493_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7850014_input: " << tbl_SerializeFromObject_TD_7850014_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_708472_s, &tv_r_JOIN_INNER_6_708472_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_7347147_output: " << tbl_Filter_TD_7347147_output.getNumRow() << " " << "tbl_Filter_TD_7195484_output: " << tbl_Filter_TD_7195484_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_386572_s, &tv_r_Filter_6_386572_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_7400563_output: " << tbl_Aggregate_TD_7400563_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_6: " << tvdiff(&tv_r_Aggregate_6_420924_s, &tv_r_Aggregate_6_420924_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7196854_output: " << tbl_JOIN_INNER_TD_7196854_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_309721_s, &tv_r_JOIN_INNER_6_309721_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7228170_output: " << tbl_JOIN_INNER_TD_7228170_output.getNumRow() << " " << "tbl_Project_TD_7309655_output: " << tbl_Project_TD_7309655_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_109292_s, &tv_r_JOIN_INNER_5_109292_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6804084_output: " << tbl_JOIN_INNER_TD_6804084_output.getNumRow() << " " << "tbl_Filter_TD_6163670_output: " << tbl_Filter_TD_6163670_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_5: " << tvdiff(&tv_r_Project_5_965703_s, &tv_r_Project_5_965703_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_68527_output: " << tbl_Filter_TD_68527_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_702029_s, &tv_r_JOIN_INNER_5_702029_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6978445_output: " << tbl_JOIN_INNER_TD_6978445_output.getNumRow() << " " << "tbl_Aggregate_TD_6888380_output: " << tbl_Aggregate_TD_6888380_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_4: " << tvdiff(&tv_r_Aggregate_4_417698_s, &tv_r_Aggregate_4_417698_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5399415_output: " << tbl_JOIN_INNER_TD_5399415_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_932699_s, &tv_r_JOIN_INNER_4_932699_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_567869_output: " << tbl_JOIN_INNER_TD_567869_output.getNumRow() << " " << "tbl_Project_TD_5499769_output: " << tbl_Project_TD_5499769_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_770249_s, &tv_r_JOIN_INNER_3_770249_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4125986_output: " << tbl_JOIN_INNER_TD_4125986_output.getNumRow() << " " << "tbl_Aggregate_TD_4731680_output: " << tbl_Aggregate_TD_4731680_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_675196_s, &tv_r_Sort_2_675196_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3549486_output: " << tbl_JOIN_INNER_TD_3549486_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_85569_s, &tv_r_LocalLimit_1_85569_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2518178_output: " << tbl_Sort_TD_2518178_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_81518_s, &tv_r_GlobalLimit_0_81518_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1827104_output: " << tbl_LocalLimit_TD_1827104_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 15.334603 * 1000 << "ms" << std::endl; 
    return 0; 
}
