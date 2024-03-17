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

#include "cfgFunc_q9.hpp" 
#include "q9.hpp" 

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
    std::cout << "NOTE:running query #9\n."; 
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
    Table tbl_Project_TD_068088_output("tbl_Project_TD_068088_output", 6100000, 5, "");
    tbl_Project_TD_068088_output.allocateHost();
    Table tbl_Filter_TD_1155884_output("tbl_Filter_TD_1155884_output", 6100000, 3, "");
    tbl_Filter_TD_1155884_output.allocateHost();
    Table tbl_Aggregate_TD_1676151_output("tbl_Aggregate_TD_1676151_output", 6100000, 1, "");
    tbl_Aggregate_TD_1676151_output.allocateHost();
    Table tbl_Aggregate_TD_198396_output("tbl_Aggregate_TD_198396_output", 6100000, 1, "");
    tbl_Aggregate_TD_198396_output.allocateHost();
    Table tbl_Aggregate_TD_1245632_output("tbl_Aggregate_TD_1245632_output", 6100000, 1, "");
    tbl_Aggregate_TD_1245632_output.allocateHost();
    Table tbl_Aggregate_TD_13942_output("tbl_Aggregate_TD_13942_output", 6100000, 1, "");
    tbl_Aggregate_TD_13942_output.allocateHost();
    Table tbl_Aggregate_TD_1603570_output("tbl_Aggregate_TD_1603570_output", 6100000, 1, "");
    tbl_Aggregate_TD_1603570_output.allocateHost();
    Table tbl_Aggregate_TD_1688913_output("tbl_Aggregate_TD_1688913_output", 6100000, 1, "");
    tbl_Aggregate_TD_1688913_output.allocateHost();
    Table tbl_Aggregate_TD_1773595_output("tbl_Aggregate_TD_1773595_output", 6100000, 1, "");
    tbl_Aggregate_TD_1773595_output.allocateHost();
    Table tbl_Aggregate_TD_1546826_output("tbl_Aggregate_TD_1546826_output", 6100000, 1, "");
    tbl_Aggregate_TD_1546826_output.allocateHost();
    Table tbl_Aggregate_TD_1797134_output("tbl_Aggregate_TD_1797134_output", 6100000, 1, "");
    tbl_Aggregate_TD_1797134_output.allocateHost();
    Table tbl_Aggregate_TD_1639105_output("tbl_Aggregate_TD_1639105_output", 6100000, 1, "");
    tbl_Aggregate_TD_1639105_output.allocateHost();
    Table tbl_Aggregate_TD_1658567_output("tbl_Aggregate_TD_1658567_output", 6100000, 1, "");
    tbl_Aggregate_TD_1658567_output.allocateHost();
    Table tbl_Aggregate_TD_1820383_output("tbl_Aggregate_TD_1820383_output", 6100000, 1, "");
    tbl_Aggregate_TD_1820383_output.allocateHost();
    Table tbl_Aggregate_TD_1879094_output("tbl_Aggregate_TD_1879094_output", 6100000, 1, "");
    tbl_Aggregate_TD_1879094_output.allocateHost();
    Table tbl_Aggregate_TD_137914_output("tbl_Aggregate_TD_137914_output", 6100000, 1, "");
    tbl_Aggregate_TD_137914_output.allocateHost();
    Table tbl_Aggregate_TD_1807473_output("tbl_Aggregate_TD_1807473_output", 6100000, 1, "");
    tbl_Aggregate_TD_1807473_output.allocateHost();
    Table tbl_SerializeFromObject_TD_242771_input;
    tbl_SerializeFromObject_TD_242771_input = Table("reason", reason_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_242771_input.addCol("r_reason_sk", 4);
    tbl_SerializeFromObject_TD_242771_input.addCol("r_reason_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_242771_input.addCol("r_reason_desc", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_242771_input.allocateHost();
    tbl_SerializeFromObject_TD_242771_input.loadHost();
    Table tbl_Filter_TD_2674416_output("tbl_Filter_TD_2674416_output", 6100000, 23, "");
    tbl_Filter_TD_2674416_output.allocateHost();
    Table tbl_Filter_TD_2332879_output("tbl_Filter_TD_2332879_output", 6100000, 1, "");
    tbl_Filter_TD_2332879_output.allocateHost();
    Table tbl_Filter_TD_2153204_output("tbl_Filter_TD_2153204_output", 6100000, 1, "");
    tbl_Filter_TD_2153204_output.allocateHost();
    Table tbl_Filter_TD_2578037_output("tbl_Filter_TD_2578037_output", 6100000, 23, "");
    tbl_Filter_TD_2578037_output.allocateHost();
    Table tbl_Filter_TD_2948317_output("tbl_Filter_TD_2948317_output", 6100000, 1, "");
    tbl_Filter_TD_2948317_output.allocateHost();
    Table tbl_Filter_TD_2457007_output("tbl_Filter_TD_2457007_output", 6100000, 1, "");
    tbl_Filter_TD_2457007_output.allocateHost();
    Table tbl_Filter_TD_2634644_output("tbl_Filter_TD_2634644_output", 6100000, 23, "");
    tbl_Filter_TD_2634644_output.allocateHost();
    Table tbl_Filter_TD_234100_output("tbl_Filter_TD_234100_output", 6100000, 1, "");
    tbl_Filter_TD_234100_output.allocateHost();
    Table tbl_Filter_TD_2279938_output("tbl_Filter_TD_2279938_output", 6100000, 1, "");
    tbl_Filter_TD_2279938_output.allocateHost();
    Table tbl_Filter_TD_2487201_output("tbl_Filter_TD_2487201_output", 6100000, 23, "");
    tbl_Filter_TD_2487201_output.allocateHost();
    Table tbl_Filter_TD_2839080_output("tbl_Filter_TD_2839080_output", 6100000, 1, "");
    tbl_Filter_TD_2839080_output.allocateHost();
    Table tbl_Filter_TD_2902889_output("tbl_Filter_TD_2902889_output", 6100000, 1, "");
    tbl_Filter_TD_2902889_output.allocateHost();
    Table tbl_Filter_TD_2144689_output("tbl_Filter_TD_2144689_output", 6100000, 23, "");
    tbl_Filter_TD_2144689_output.allocateHost();
    Table tbl_Filter_TD_2480680_output("tbl_Filter_TD_2480680_output", 6100000, 1, "");
    tbl_Filter_TD_2480680_output.allocateHost();
    Table tbl_Filter_TD_2736300_output("tbl_Filter_TD_2736300_output", 6100000, 1, "");
    tbl_Filter_TD_2736300_output.allocateHost();
    Table tbl_SerializeFromObject_TD_3778761_input;
    tbl_SerializeFromObject_TD_3778761_input = Table("store_sales", store_sales_n, 23, in_dir, "orc");
    tbl_SerializeFromObject_TD_3778761_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_3778761_input.addCol("ss_sold_time_sk", 4);
    tbl_SerializeFromObject_TD_3778761_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_3778761_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_3778761_input.addCol("ss_cdemo_sk", 4);
    tbl_SerializeFromObject_TD_3778761_input.addCol("ss_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_3778761_input.addCol("ss_addr_sk", 4);
    tbl_SerializeFromObject_TD_3778761_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_3778761_input.addCol("ss_promo_sk", 4);
    tbl_SerializeFromObject_TD_3778761_input.addCol("ss_ticket_number", 8);
    tbl_SerializeFromObject_TD_3778761_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_3778761_input.addCol("ss_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_3778761_input.addCol("ss_list_price", 4);
    tbl_SerializeFromObject_TD_3778761_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_3778761_input.addCol("ss_ext_discount_amt", 4);
    tbl_SerializeFromObject_TD_3778761_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_3778761_input.addCol("ss_ext_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_3778761_input.addCol("ss_ext_list_price", 4);
    tbl_SerializeFromObject_TD_3778761_input.addCol("ss_ext_tax", 4);
    tbl_SerializeFromObject_TD_3778761_input.addCol("ss_coupon_amt", 4);
    tbl_SerializeFromObject_TD_3778761_input.addCol("ss_net_paid", 4);
    tbl_SerializeFromObject_TD_3778761_input.addCol("ss_net_paid_inc_tax", 4);
    tbl_SerializeFromObject_TD_3778761_input.addCol("ss_net_profit", 4);
    tbl_SerializeFromObject_TD_3778761_input.allocateHost();
    tbl_SerializeFromObject_TD_3778761_input.loadHost();
    Table tbl_SerializeFromObject_TD_3698144_input;
    tbl_SerializeFromObject_TD_3698144_input = Table("store_sales", store_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_3698144_input.addCol("ss_ext_discount_amt", 4);
    tbl_SerializeFromObject_TD_3698144_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_3698144_input.allocateHost();
    tbl_SerializeFromObject_TD_3698144_input.loadHost();
    Table tbl_SerializeFromObject_TD_3666916_input;
    tbl_SerializeFromObject_TD_3666916_input = Table("store_sales", store_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_3666916_input.addCol("ss_net_paid", 4);
    tbl_SerializeFromObject_TD_3666916_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_3666916_input.allocateHost();
    tbl_SerializeFromObject_TD_3666916_input.loadHost();
    Table tbl_SerializeFromObject_TD_3582417_input;
    tbl_SerializeFromObject_TD_3582417_input = Table("store_sales", store_sales_n, 23, in_dir, "orc");
    tbl_SerializeFromObject_TD_3582417_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_3582417_input.addCol("ss_sold_time_sk", 4);
    tbl_SerializeFromObject_TD_3582417_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_3582417_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_3582417_input.addCol("ss_cdemo_sk", 4);
    tbl_SerializeFromObject_TD_3582417_input.addCol("ss_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_3582417_input.addCol("ss_addr_sk", 4);
    tbl_SerializeFromObject_TD_3582417_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_3582417_input.addCol("ss_promo_sk", 4);
    tbl_SerializeFromObject_TD_3582417_input.addCol("ss_ticket_number", 8);
    tbl_SerializeFromObject_TD_3582417_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_3582417_input.addCol("ss_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_3582417_input.addCol("ss_list_price", 4);
    tbl_SerializeFromObject_TD_3582417_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_3582417_input.addCol("ss_ext_discount_amt", 4);
    tbl_SerializeFromObject_TD_3582417_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_3582417_input.addCol("ss_ext_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_3582417_input.addCol("ss_ext_list_price", 4);
    tbl_SerializeFromObject_TD_3582417_input.addCol("ss_ext_tax", 4);
    tbl_SerializeFromObject_TD_3582417_input.addCol("ss_coupon_amt", 4);
    tbl_SerializeFromObject_TD_3582417_input.addCol("ss_net_paid", 4);
    tbl_SerializeFromObject_TD_3582417_input.addCol("ss_net_paid_inc_tax", 4);
    tbl_SerializeFromObject_TD_3582417_input.addCol("ss_net_profit", 4);
    tbl_SerializeFromObject_TD_3582417_input.allocateHost();
    tbl_SerializeFromObject_TD_3582417_input.loadHost();
    Table tbl_SerializeFromObject_TD_3129152_input;
    tbl_SerializeFromObject_TD_3129152_input = Table("store_sales", store_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_3129152_input.addCol("ss_ext_discount_amt", 4);
    tbl_SerializeFromObject_TD_3129152_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_3129152_input.allocateHost();
    tbl_SerializeFromObject_TD_3129152_input.loadHost();
    Table tbl_SerializeFromObject_TD_3146485_input;
    tbl_SerializeFromObject_TD_3146485_input = Table("store_sales", store_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_3146485_input.addCol("ss_net_paid", 4);
    tbl_SerializeFromObject_TD_3146485_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_3146485_input.allocateHost();
    tbl_SerializeFromObject_TD_3146485_input.loadHost();
    Table tbl_SerializeFromObject_TD_3845752_input;
    tbl_SerializeFromObject_TD_3845752_input = Table("store_sales", store_sales_n, 23, in_dir, "orc");
    tbl_SerializeFromObject_TD_3845752_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_3845752_input.addCol("ss_sold_time_sk", 4);
    tbl_SerializeFromObject_TD_3845752_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_3845752_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_3845752_input.addCol("ss_cdemo_sk", 4);
    tbl_SerializeFromObject_TD_3845752_input.addCol("ss_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_3845752_input.addCol("ss_addr_sk", 4);
    tbl_SerializeFromObject_TD_3845752_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_3845752_input.addCol("ss_promo_sk", 4);
    tbl_SerializeFromObject_TD_3845752_input.addCol("ss_ticket_number", 8);
    tbl_SerializeFromObject_TD_3845752_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_3845752_input.addCol("ss_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_3845752_input.addCol("ss_list_price", 4);
    tbl_SerializeFromObject_TD_3845752_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_3845752_input.addCol("ss_ext_discount_amt", 4);
    tbl_SerializeFromObject_TD_3845752_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_3845752_input.addCol("ss_ext_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_3845752_input.addCol("ss_ext_list_price", 4);
    tbl_SerializeFromObject_TD_3845752_input.addCol("ss_ext_tax", 4);
    tbl_SerializeFromObject_TD_3845752_input.addCol("ss_coupon_amt", 4);
    tbl_SerializeFromObject_TD_3845752_input.addCol("ss_net_paid", 4);
    tbl_SerializeFromObject_TD_3845752_input.addCol("ss_net_paid_inc_tax", 4);
    tbl_SerializeFromObject_TD_3845752_input.addCol("ss_net_profit", 4);
    tbl_SerializeFromObject_TD_3845752_input.allocateHost();
    tbl_SerializeFromObject_TD_3845752_input.loadHost();
    Table tbl_SerializeFromObject_TD_3204179_input;
    tbl_SerializeFromObject_TD_3204179_input = Table("store_sales", store_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_3204179_input.addCol("ss_ext_discount_amt", 4);
    tbl_SerializeFromObject_TD_3204179_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_3204179_input.allocateHost();
    tbl_SerializeFromObject_TD_3204179_input.loadHost();
    Table tbl_SerializeFromObject_TD_3416277_input;
    tbl_SerializeFromObject_TD_3416277_input = Table("store_sales", store_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_3416277_input.addCol("ss_net_paid", 4);
    tbl_SerializeFromObject_TD_3416277_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_3416277_input.allocateHost();
    tbl_SerializeFromObject_TD_3416277_input.loadHost();
    Table tbl_SerializeFromObject_TD_3844841_input;
    tbl_SerializeFromObject_TD_3844841_input = Table("store_sales", store_sales_n, 23, in_dir, "orc");
    tbl_SerializeFromObject_TD_3844841_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_3844841_input.addCol("ss_sold_time_sk", 4);
    tbl_SerializeFromObject_TD_3844841_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_3844841_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_3844841_input.addCol("ss_cdemo_sk", 4);
    tbl_SerializeFromObject_TD_3844841_input.addCol("ss_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_3844841_input.addCol("ss_addr_sk", 4);
    tbl_SerializeFromObject_TD_3844841_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_3844841_input.addCol("ss_promo_sk", 4);
    tbl_SerializeFromObject_TD_3844841_input.addCol("ss_ticket_number", 8);
    tbl_SerializeFromObject_TD_3844841_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_3844841_input.addCol("ss_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_3844841_input.addCol("ss_list_price", 4);
    tbl_SerializeFromObject_TD_3844841_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_3844841_input.addCol("ss_ext_discount_amt", 4);
    tbl_SerializeFromObject_TD_3844841_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_3844841_input.addCol("ss_ext_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_3844841_input.addCol("ss_ext_list_price", 4);
    tbl_SerializeFromObject_TD_3844841_input.addCol("ss_ext_tax", 4);
    tbl_SerializeFromObject_TD_3844841_input.addCol("ss_coupon_amt", 4);
    tbl_SerializeFromObject_TD_3844841_input.addCol("ss_net_paid", 4);
    tbl_SerializeFromObject_TD_3844841_input.addCol("ss_net_paid_inc_tax", 4);
    tbl_SerializeFromObject_TD_3844841_input.addCol("ss_net_profit", 4);
    tbl_SerializeFromObject_TD_3844841_input.allocateHost();
    tbl_SerializeFromObject_TD_3844841_input.loadHost();
    Table tbl_SerializeFromObject_TD_3204386_input;
    tbl_SerializeFromObject_TD_3204386_input = Table("store_sales", store_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_3204386_input.addCol("ss_ext_discount_amt", 4);
    tbl_SerializeFromObject_TD_3204386_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_3204386_input.allocateHost();
    tbl_SerializeFromObject_TD_3204386_input.loadHost();
    Table tbl_SerializeFromObject_TD_3844515_input;
    tbl_SerializeFromObject_TD_3844515_input = Table("store_sales", store_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_3844515_input.addCol("ss_net_paid", 4);
    tbl_SerializeFromObject_TD_3844515_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_3844515_input.allocateHost();
    tbl_SerializeFromObject_TD_3844515_input.loadHost();
    Table tbl_SerializeFromObject_TD_3514886_input;
    tbl_SerializeFromObject_TD_3514886_input = Table("store_sales", store_sales_n, 23, in_dir, "orc");
    tbl_SerializeFromObject_TD_3514886_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_3514886_input.addCol("ss_sold_time_sk", 4);
    tbl_SerializeFromObject_TD_3514886_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_3514886_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_3514886_input.addCol("ss_cdemo_sk", 4);
    tbl_SerializeFromObject_TD_3514886_input.addCol("ss_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_3514886_input.addCol("ss_addr_sk", 4);
    tbl_SerializeFromObject_TD_3514886_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_3514886_input.addCol("ss_promo_sk", 4);
    tbl_SerializeFromObject_TD_3514886_input.addCol("ss_ticket_number", 8);
    tbl_SerializeFromObject_TD_3514886_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_3514886_input.addCol("ss_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_3514886_input.addCol("ss_list_price", 4);
    tbl_SerializeFromObject_TD_3514886_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_3514886_input.addCol("ss_ext_discount_amt", 4);
    tbl_SerializeFromObject_TD_3514886_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_3514886_input.addCol("ss_ext_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_3514886_input.addCol("ss_ext_list_price", 4);
    tbl_SerializeFromObject_TD_3514886_input.addCol("ss_ext_tax", 4);
    tbl_SerializeFromObject_TD_3514886_input.addCol("ss_coupon_amt", 4);
    tbl_SerializeFromObject_TD_3514886_input.addCol("ss_net_paid", 4);
    tbl_SerializeFromObject_TD_3514886_input.addCol("ss_net_paid_inc_tax", 4);
    tbl_SerializeFromObject_TD_3514886_input.addCol("ss_net_profit", 4);
    tbl_SerializeFromObject_TD_3514886_input.allocateHost();
    tbl_SerializeFromObject_TD_3514886_input.loadHost();
    Table tbl_SerializeFromObject_TD_3892127_input;
    tbl_SerializeFromObject_TD_3892127_input = Table("store_sales", store_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_3892127_input.addCol("ss_ext_discount_amt", 4);
    tbl_SerializeFromObject_TD_3892127_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_3892127_input.allocateHost();
    tbl_SerializeFromObject_TD_3892127_input.loadHost();
    Table tbl_SerializeFromObject_TD_3511965_input;
    tbl_SerializeFromObject_TD_3511965_input = Table("store_sales", store_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_3511965_input.addCol("ss_net_paid", 4);
    tbl_SerializeFromObject_TD_3511965_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_3511965_input.allocateHost();
    tbl_SerializeFromObject_TD_3511965_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_2_40558_s, tv_r_Filter_2_40558_e;
    gettimeofday(&tv_r_Filter_2_40558_s, 0);
    SW_Filter_TD_2736300(tbl_SerializeFromObject_TD_3511965_input, tbl_Filter_TD_2736300_output);
    gettimeofday(&tv_r_Filter_2_40558_e, 0);

    struct timeval tv_r_Filter_2_244761_s, tv_r_Filter_2_244761_e;
    gettimeofday(&tv_r_Filter_2_244761_s, 0);
    SW_Filter_TD_2480680(tbl_SerializeFromObject_TD_3892127_input, tbl_Filter_TD_2480680_output);
    gettimeofday(&tv_r_Filter_2_244761_e, 0);

    struct timeval tv_r_Filter_2_672753_s, tv_r_Filter_2_672753_e;
    gettimeofday(&tv_r_Filter_2_672753_s, 0);
    SW_Filter_TD_2144689(tbl_SerializeFromObject_TD_3514886_input, tbl_Filter_TD_2144689_output);
    gettimeofday(&tv_r_Filter_2_672753_e, 0);

    struct timeval tv_r_Filter_2_112507_s, tv_r_Filter_2_112507_e;
    gettimeofday(&tv_r_Filter_2_112507_s, 0);
    SW_Filter_TD_2902889(tbl_SerializeFromObject_TD_3844515_input, tbl_Filter_TD_2902889_output);
    gettimeofday(&tv_r_Filter_2_112507_e, 0);

    struct timeval tv_r_Filter_2_395615_s, tv_r_Filter_2_395615_e;
    gettimeofday(&tv_r_Filter_2_395615_s, 0);
    SW_Filter_TD_2839080(tbl_SerializeFromObject_TD_3204386_input, tbl_Filter_TD_2839080_output);
    gettimeofday(&tv_r_Filter_2_395615_e, 0);

    struct timeval tv_r_Filter_2_102206_s, tv_r_Filter_2_102206_e;
    gettimeofday(&tv_r_Filter_2_102206_s, 0);
    SW_Filter_TD_2487201(tbl_SerializeFromObject_TD_3844841_input, tbl_Filter_TD_2487201_output);
    gettimeofday(&tv_r_Filter_2_102206_e, 0);

    struct timeval tv_r_Filter_2_851065_s, tv_r_Filter_2_851065_e;
    gettimeofday(&tv_r_Filter_2_851065_s, 0);
    SW_Filter_TD_2279938(tbl_SerializeFromObject_TD_3416277_input, tbl_Filter_TD_2279938_output);
    gettimeofday(&tv_r_Filter_2_851065_e, 0);

    struct timeval tv_r_Filter_2_854836_s, tv_r_Filter_2_854836_e;
    gettimeofday(&tv_r_Filter_2_854836_s, 0);
    SW_Filter_TD_234100(tbl_SerializeFromObject_TD_3204179_input, tbl_Filter_TD_234100_output);
    gettimeofday(&tv_r_Filter_2_854836_e, 0);

    struct timeval tv_r_Filter_2_352135_s, tv_r_Filter_2_352135_e;
    gettimeofday(&tv_r_Filter_2_352135_s, 0);
    SW_Filter_TD_2634644(tbl_SerializeFromObject_TD_3845752_input, tbl_Filter_TD_2634644_output);
    gettimeofday(&tv_r_Filter_2_352135_e, 0);

    struct timeval tv_r_Filter_2_874071_s, tv_r_Filter_2_874071_e;
    gettimeofday(&tv_r_Filter_2_874071_s, 0);
    SW_Filter_TD_2457007(tbl_SerializeFromObject_TD_3146485_input, tbl_Filter_TD_2457007_output);
    gettimeofday(&tv_r_Filter_2_874071_e, 0);

    struct timeval tv_r_Filter_2_938474_s, tv_r_Filter_2_938474_e;
    gettimeofday(&tv_r_Filter_2_938474_s, 0);
    SW_Filter_TD_2948317(tbl_SerializeFromObject_TD_3129152_input, tbl_Filter_TD_2948317_output);
    gettimeofday(&tv_r_Filter_2_938474_e, 0);

    struct timeval tv_r_Filter_2_464704_s, tv_r_Filter_2_464704_e;
    gettimeofday(&tv_r_Filter_2_464704_s, 0);
    SW_Filter_TD_2578037(tbl_SerializeFromObject_TD_3582417_input, tbl_Filter_TD_2578037_output);
    gettimeofday(&tv_r_Filter_2_464704_e, 0);

    struct timeval tv_r_Filter_2_354119_s, tv_r_Filter_2_354119_e;
    gettimeofday(&tv_r_Filter_2_354119_s, 0);
    SW_Filter_TD_2153204(tbl_SerializeFromObject_TD_3666916_input, tbl_Filter_TD_2153204_output);
    gettimeofday(&tv_r_Filter_2_354119_e, 0);

    struct timeval tv_r_Filter_2_596348_s, tv_r_Filter_2_596348_e;
    gettimeofday(&tv_r_Filter_2_596348_s, 0);
    SW_Filter_TD_2332879(tbl_SerializeFromObject_TD_3698144_input, tbl_Filter_TD_2332879_output);
    gettimeofday(&tv_r_Filter_2_596348_e, 0);

    struct timeval tv_r_Filter_2_762856_s, tv_r_Filter_2_762856_e;
    gettimeofday(&tv_r_Filter_2_762856_s, 0);
    SW_Filter_TD_2674416(tbl_SerializeFromObject_TD_3778761_input, tbl_Filter_TD_2674416_output);
    gettimeofday(&tv_r_Filter_2_762856_e, 0);

    struct timeval tv_r_Aggregate_1_622031_s, tv_r_Aggregate_1_622031_e;
    gettimeofday(&tv_r_Aggregate_1_622031_s, 0);
    SW_Aggregate_TD_1807473(tbl_Filter_TD_2736300_output, tbl_Aggregate_TD_1807473_output);
    gettimeofday(&tv_r_Aggregate_1_622031_e, 0);

    struct timeval tv_r_Aggregate_1_311171_s, tv_r_Aggregate_1_311171_e;
    gettimeofday(&tv_r_Aggregate_1_311171_s, 0);
    SW_Aggregate_TD_137914(tbl_Filter_TD_2480680_output, tbl_Aggregate_TD_137914_output);
    gettimeofday(&tv_r_Aggregate_1_311171_e, 0);

    struct timeval tv_r_Aggregate_1_890489_s, tv_r_Aggregate_1_890489_e;
    gettimeofday(&tv_r_Aggregate_1_890489_s, 0);
    SW_Aggregate_TD_1879094(tbl_Filter_TD_2144689_output, tbl_Aggregate_TD_1879094_output);
    gettimeofday(&tv_r_Aggregate_1_890489_e, 0);

    struct timeval tv_r_Aggregate_1_49198_s, tv_r_Aggregate_1_49198_e;
    gettimeofday(&tv_r_Aggregate_1_49198_s, 0);
    SW_Aggregate_TD_1820383(tbl_Filter_TD_2902889_output, tbl_Aggregate_TD_1820383_output);
    gettimeofday(&tv_r_Aggregate_1_49198_e, 0);

    struct timeval tv_r_Aggregate_1_541328_s, tv_r_Aggregate_1_541328_e;
    gettimeofday(&tv_r_Aggregate_1_541328_s, 0);
    SW_Aggregate_TD_1658567(tbl_Filter_TD_2839080_output, tbl_Aggregate_TD_1658567_output);
    gettimeofday(&tv_r_Aggregate_1_541328_e, 0);

    struct timeval tv_r_Aggregate_1_891854_s, tv_r_Aggregate_1_891854_e;
    gettimeofday(&tv_r_Aggregate_1_891854_s, 0);
    SW_Aggregate_TD_1639105(tbl_Filter_TD_2487201_output, tbl_Aggregate_TD_1639105_output);
    gettimeofday(&tv_r_Aggregate_1_891854_e, 0);

    struct timeval tv_r_Aggregate_1_761865_s, tv_r_Aggregate_1_761865_e;
    gettimeofday(&tv_r_Aggregate_1_761865_s, 0);
    SW_Aggregate_TD_1797134(tbl_Filter_TD_2279938_output, tbl_Aggregate_TD_1797134_output);
    gettimeofday(&tv_r_Aggregate_1_761865_e, 0);

    struct timeval tv_r_Aggregate_1_374652_s, tv_r_Aggregate_1_374652_e;
    gettimeofday(&tv_r_Aggregate_1_374652_s, 0);
    SW_Aggregate_TD_1546826(tbl_Filter_TD_234100_output, tbl_Aggregate_TD_1546826_output);
    gettimeofday(&tv_r_Aggregate_1_374652_e, 0);

    struct timeval tv_r_Aggregate_1_696571_s, tv_r_Aggregate_1_696571_e;
    gettimeofday(&tv_r_Aggregate_1_696571_s, 0);
    SW_Aggregate_TD_1773595(tbl_Filter_TD_2634644_output, tbl_Aggregate_TD_1773595_output);
    gettimeofday(&tv_r_Aggregate_1_696571_e, 0);

    struct timeval tv_r_Aggregate_1_980004_s, tv_r_Aggregate_1_980004_e;
    gettimeofday(&tv_r_Aggregate_1_980004_s, 0);
    SW_Aggregate_TD_1688913(tbl_Filter_TD_2457007_output, tbl_Aggregate_TD_1688913_output);
    gettimeofday(&tv_r_Aggregate_1_980004_e, 0);

    struct timeval tv_r_Aggregate_1_555060_s, tv_r_Aggregate_1_555060_e;
    gettimeofday(&tv_r_Aggregate_1_555060_s, 0);
    SW_Aggregate_TD_1603570(tbl_Filter_TD_2948317_output, tbl_Aggregate_TD_1603570_output);
    gettimeofday(&tv_r_Aggregate_1_555060_e, 0);

    struct timeval tv_r_Aggregate_1_202411_s, tv_r_Aggregate_1_202411_e;
    gettimeofday(&tv_r_Aggregate_1_202411_s, 0);
    SW_Aggregate_TD_13942(tbl_Filter_TD_2578037_output, tbl_Aggregate_TD_13942_output);
    gettimeofday(&tv_r_Aggregate_1_202411_e, 0);

    struct timeval tv_r_Aggregate_1_496506_s, tv_r_Aggregate_1_496506_e;
    gettimeofday(&tv_r_Aggregate_1_496506_s, 0);
    SW_Aggregate_TD_1245632(tbl_Filter_TD_2153204_output, tbl_Aggregate_TD_1245632_output);
    gettimeofday(&tv_r_Aggregate_1_496506_e, 0);

    struct timeval tv_r_Aggregate_1_773328_s, tv_r_Aggregate_1_773328_e;
    gettimeofday(&tv_r_Aggregate_1_773328_s, 0);
    SW_Aggregate_TD_198396(tbl_Filter_TD_2332879_output, tbl_Aggregate_TD_198396_output);
    gettimeofday(&tv_r_Aggregate_1_773328_e, 0);

    struct timeval tv_r_Aggregate_1_226946_s, tv_r_Aggregate_1_226946_e;
    gettimeofday(&tv_r_Aggregate_1_226946_s, 0);
    SW_Aggregate_TD_1676151(tbl_Filter_TD_2674416_output, tbl_Aggregate_TD_1676151_output);
    gettimeofday(&tv_r_Aggregate_1_226946_e, 0);

    struct timeval tv_r_Filter_1_817312_s, tv_r_Filter_1_817312_e;
    gettimeofday(&tv_r_Filter_1_817312_s, 0);
    SW_Filter_TD_1155884(tbl_SerializeFromObject_TD_242771_input, tbl_Filter_TD_1155884_output);
    gettimeofday(&tv_r_Filter_1_817312_e, 0);

    struct timeval tv_r_Project_0_164277_s, tv_r_Project_0_164277_e;
    gettimeofday(&tv_r_Project_0_164277_s, 0);
    SW_Project_TD_068088(tbl_Filter_TD_1155884_output, tbl_Aggregate_TD_1676151_output, tbl_Aggregate_TD_198396_output, tbl_Aggregate_TD_1245632_output, tbl_Aggregate_TD_13942_output, tbl_Aggregate_TD_1603570_output, tbl_Aggregate_TD_1688913_output, tbl_Aggregate_TD_1773595_output, tbl_Aggregate_TD_1546826_output, tbl_Aggregate_TD_1797134_output, tbl_Aggregate_TD_1639105_output, tbl_Aggregate_TD_1658567_output, tbl_Aggregate_TD_1820383_output, tbl_Aggregate_TD_1879094_output, tbl_Aggregate_TD_137914_output, tbl_Aggregate_TD_1807473_output, tbl_Project_TD_068088_output);
    gettimeofday(&tv_r_Project_0_164277_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_40558_s, &tv_r_Filter_2_40558_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3511965_input: " << tbl_SerializeFromObject_TD_3511965_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_244761_s, &tv_r_Filter_2_244761_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3892127_input: " << tbl_SerializeFromObject_TD_3892127_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_672753_s, &tv_r_Filter_2_672753_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3514886_input: " << tbl_SerializeFromObject_TD_3514886_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_112507_s, &tv_r_Filter_2_112507_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3844515_input: " << tbl_SerializeFromObject_TD_3844515_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_395615_s, &tv_r_Filter_2_395615_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3204386_input: " << tbl_SerializeFromObject_TD_3204386_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_102206_s, &tv_r_Filter_2_102206_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3844841_input: " << tbl_SerializeFromObject_TD_3844841_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_851065_s, &tv_r_Filter_2_851065_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3416277_input: " << tbl_SerializeFromObject_TD_3416277_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_854836_s, &tv_r_Filter_2_854836_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3204179_input: " << tbl_SerializeFromObject_TD_3204179_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_352135_s, &tv_r_Filter_2_352135_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3845752_input: " << tbl_SerializeFromObject_TD_3845752_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_874071_s, &tv_r_Filter_2_874071_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3146485_input: " << tbl_SerializeFromObject_TD_3146485_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_938474_s, &tv_r_Filter_2_938474_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3129152_input: " << tbl_SerializeFromObject_TD_3129152_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_464704_s, &tv_r_Filter_2_464704_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3582417_input: " << tbl_SerializeFromObject_TD_3582417_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_354119_s, &tv_r_Filter_2_354119_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3666916_input: " << tbl_SerializeFromObject_TD_3666916_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_596348_s, &tv_r_Filter_2_596348_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3698144_input: " << tbl_SerializeFromObject_TD_3698144_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_762856_s, &tv_r_Filter_2_762856_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3778761_input: " << tbl_SerializeFromObject_TD_3778761_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_622031_s, &tv_r_Aggregate_1_622031_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_2736300_output: " << tbl_Filter_TD_2736300_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_311171_s, &tv_r_Aggregate_1_311171_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_2480680_output: " << tbl_Filter_TD_2480680_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_890489_s, &tv_r_Aggregate_1_890489_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_2144689_output: " << tbl_Filter_TD_2144689_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_49198_s, &tv_r_Aggregate_1_49198_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_2902889_output: " << tbl_Filter_TD_2902889_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_541328_s, &tv_r_Aggregate_1_541328_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_2839080_output: " << tbl_Filter_TD_2839080_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_891854_s, &tv_r_Aggregate_1_891854_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_2487201_output: " << tbl_Filter_TD_2487201_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_761865_s, &tv_r_Aggregate_1_761865_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_2279938_output: " << tbl_Filter_TD_2279938_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_374652_s, &tv_r_Aggregate_1_374652_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_234100_output: " << tbl_Filter_TD_234100_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_696571_s, &tv_r_Aggregate_1_696571_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_2634644_output: " << tbl_Filter_TD_2634644_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_980004_s, &tv_r_Aggregate_1_980004_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_2457007_output: " << tbl_Filter_TD_2457007_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_555060_s, &tv_r_Aggregate_1_555060_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_2948317_output: " << tbl_Filter_TD_2948317_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_202411_s, &tv_r_Aggregate_1_202411_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_2578037_output: " << tbl_Filter_TD_2578037_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_496506_s, &tv_r_Aggregate_1_496506_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_2153204_output: " << tbl_Filter_TD_2153204_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_773328_s, &tv_r_Aggregate_1_773328_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_2332879_output: " << tbl_Filter_TD_2332879_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_226946_s, &tv_r_Aggregate_1_226946_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_2674416_output: " << tbl_Filter_TD_2674416_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_1: " << tvdiff(&tv_r_Filter_1_817312_s, &tv_r_Filter_1_817312_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_242771_input: " << tbl_SerializeFromObject_TD_242771_input.getNumRow() << " " << std::endl; 

    std::cout << "Project_0: " << tvdiff(&tv_r_Project_0_164277_s, &tv_r_Project_0_164277_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_1155884_output: " << tbl_Filter_TD_1155884_output.getNumRow() << " " << "tbl_Aggregate_TD_1676151_output: " << tbl_Aggregate_TD_1676151_output.getNumRow() << " " << "tbl_Aggregate_TD_198396_output: " << tbl_Aggregate_TD_198396_output.getNumRow() << " " << "tbl_Aggregate_TD_1245632_output: " << tbl_Aggregate_TD_1245632_output.getNumRow() << " " << "tbl_Aggregate_TD_13942_output: " << tbl_Aggregate_TD_13942_output.getNumRow() << " " << "tbl_Aggregate_TD_1603570_output: " << tbl_Aggregate_TD_1603570_output.getNumRow() << " " << "tbl_Aggregate_TD_1688913_output: " << tbl_Aggregate_TD_1688913_output.getNumRow() << " " << "tbl_Aggregate_TD_1773595_output: " << tbl_Aggregate_TD_1773595_output.getNumRow() << " " << "tbl_Aggregate_TD_1546826_output: " << tbl_Aggregate_TD_1546826_output.getNumRow() << " " << "tbl_Aggregate_TD_1797134_output: " << tbl_Aggregate_TD_1797134_output.getNumRow() << " " << "tbl_Aggregate_TD_1639105_output: " << tbl_Aggregate_TD_1639105_output.getNumRow() << " " << "tbl_Aggregate_TD_1658567_output: " << tbl_Aggregate_TD_1658567_output.getNumRow() << " " << "tbl_Aggregate_TD_1820383_output: " << tbl_Aggregate_TD_1820383_output.getNumRow() << " " << "tbl_Aggregate_TD_1879094_output: " << tbl_Aggregate_TD_1879094_output.getNumRow() << " " << "tbl_Aggregate_TD_137914_output: " << tbl_Aggregate_TD_137914_output.getNumRow() << " " << "tbl_Aggregate_TD_1807473_output: " << tbl_Aggregate_TD_1807473_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 4.3396835 * 1000 << "ms" << std::endl; 
    return 0; 
}
