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

#include "cfgFunc_q5.hpp" 
#include "q5.hpp" 

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
    std::cout << "NOTE:running query #5\n."; 
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
    Table tbl_GlobalLimit_TD_0194894_output("tbl_GlobalLimit_TD_0194894_output", 6100000, 5, "");
    tbl_GlobalLimit_TD_0194894_output.allocateHost();
    Table tbl_LocalLimit_TD_1610557_output("tbl_LocalLimit_TD_1610557_output", 6100000, 5, "");
    tbl_LocalLimit_TD_1610557_output.allocateHost();
    Table tbl_Sort_TD_2670203_output("tbl_Sort_TD_2670203_output", 6100000, 5, "");
    tbl_Sort_TD_2670203_output.allocateHost();
    Table tbl_Aggregate_TD_319948_output("tbl_Aggregate_TD_319948_output", 6100000, 5, "");
    tbl_Aggregate_TD_319948_output.allocateHost();
    Table tbl_Expand_TD_4449971_output("tbl_Expand_TD_4449971_output", 6100000, 6, "");
    tbl_Expand_TD_4449971_output.allocateHost();
    Table tbl_Union_TD_5271381_output("tbl_Union_TD_5271381_output", 6100000, 5, "");
    tbl_Union_TD_5271381_output.allocateHost();
    Table tbl_Aggregate_TD_6804953_output("tbl_Aggregate_TD_6804953_output", 6100000, 5, "");
    tbl_Aggregate_TD_6804953_output.allocateHost();
    Table tbl_Aggregate_TD_6302693_output("tbl_Aggregate_TD_6302693_output", 6100000, 5, "");
    tbl_Aggregate_TD_6302693_output.allocateHost();
    Table tbl_Aggregate_TD_6713678_output("tbl_Aggregate_TD_6713678_output", 6100000, 5, "");
    tbl_Aggregate_TD_6713678_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7904255_output("tbl_JOIN_INNER_TD_7904255_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_7904255_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7797349_output("tbl_JOIN_INNER_TD_7797349_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_7797349_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7603722_output("tbl_JOIN_INNER_TD_7603722_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_7603722_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8825954_output("tbl_JOIN_INNER_TD_8825954_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_8825954_output.allocateHost();
    Table tbl_Filter_TD_8378457_output("tbl_Filter_TD_8378457_output", 6100000, 2, "");
    tbl_Filter_TD_8378457_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8779433_output("tbl_JOIN_INNER_TD_8779433_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_8779433_output.allocateHost();
    Table tbl_Filter_TD_8670372_output("tbl_Filter_TD_8670372_output", 6100000, 2, "");
    tbl_Filter_TD_8670372_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8828693_output("tbl_JOIN_INNER_TD_8828693_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_8828693_output.allocateHost();
    Table tbl_Filter_TD_8928910_output("tbl_Filter_TD_8928910_output", 6100000, 2, "");
    tbl_Filter_TD_8928910_output.allocateHost();
    Table tbl_Union_TD_9523992_output("tbl_Union_TD_9523992_output", 6100000, 6, "");
    tbl_Union_TD_9523992_output.allocateHost();
    Table tbl_Filter_TD_9561562_output("tbl_Filter_TD_9561562_output", 6100000, 1, "");
    tbl_Filter_TD_9561562_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9326199_input;
    tbl_SerializeFromObject_TD_9326199_input = Table("store", store_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9326199_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_9326199_input.addCol("s_store_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9326199_input.allocateHost();
    tbl_SerializeFromObject_TD_9326199_input.loadHost();
    Table tbl_Union_TD_9812863_output("tbl_Union_TD_9812863_output", 6100000, 6, "");
    tbl_Union_TD_9812863_output.allocateHost();
    Table tbl_Filter_TD_9539098_output("tbl_Filter_TD_9539098_output", 6100000, 1, "");
    tbl_Filter_TD_9539098_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9541220_input;
    tbl_SerializeFromObject_TD_9541220_input = Table("catalog_page", catalog_page_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9541220_input.addCol("cp_catalog_page_sk", 4);
    tbl_SerializeFromObject_TD_9541220_input.addCol("cp_catalog_page_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9541220_input.allocateHost();
    tbl_SerializeFromObject_TD_9541220_input.loadHost();
    Table tbl_Union_TD_980579_output("tbl_Union_TD_980579_output", 6100000, 6, "");
    tbl_Union_TD_980579_output.allocateHost();
    Table tbl_Filter_TD_9834949_output("tbl_Filter_TD_9834949_output", 6100000, 1, "");
    tbl_Filter_TD_9834949_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9886392_input;
    tbl_SerializeFromObject_TD_9886392_input = Table("web_site", web_site_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9886392_input.addCol("web_site_sk", 4);
    tbl_SerializeFromObject_TD_9886392_input.addCol("web_site_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9886392_input.allocateHost();
    tbl_SerializeFromObject_TD_9886392_input.loadHost();
    Table tbl_Project_TD_10341667_output("tbl_Project_TD_10341667_output", 6100000, 6, "");
    tbl_Project_TD_10341667_output.allocateHost();
    Table tbl_Project_TD_10240760_output("tbl_Project_TD_10240760_output", 6100000, 6, "");
    tbl_Project_TD_10240760_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10649452_input;
    tbl_SerializeFromObject_TD_10649452_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10649452_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10649452_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_10649452_input.allocateHost();
    tbl_SerializeFromObject_TD_10649452_input.loadHost();
    Table tbl_Project_TD_10840291_output("tbl_Project_TD_10840291_output", 6100000, 6, "");
    tbl_Project_TD_10840291_output.allocateHost();
    Table tbl_Project_TD_10950398_output("tbl_Project_TD_10950398_output", 6100000, 6, "");
    tbl_Project_TD_10950398_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10187856_input;
    tbl_SerializeFromObject_TD_10187856_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10187856_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10187856_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_10187856_input.allocateHost();
    tbl_SerializeFromObject_TD_10187856_input.loadHost();
    Table tbl_Project_TD_10400972_output("tbl_Project_TD_10400972_output", 6100000, 6, "");
    tbl_Project_TD_10400972_output.allocateHost();
    Table tbl_Project_TD_10926061_output("tbl_Project_TD_10926061_output", 6100000, 6, "");
    tbl_Project_TD_10926061_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10939837_input;
    tbl_SerializeFromObject_TD_10939837_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10939837_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10939837_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_10939837_input.allocateHost();
    tbl_SerializeFromObject_TD_10939837_input.loadHost();
    Table tbl_Filter_TD_11183378_output("tbl_Filter_TD_11183378_output", 6100000, 4, "");
    tbl_Filter_TD_11183378_output.allocateHost();
    Table tbl_Filter_TD_11519105_output("tbl_Filter_TD_11519105_output", 6100000, 4, "");
    tbl_Filter_TD_11519105_output.allocateHost();
    Table tbl_Filter_TD_11644099_output("tbl_Filter_TD_11644099_output", 6100000, 4, "");
    tbl_Filter_TD_11644099_output.allocateHost();
    Table tbl_Filter_TD_11173530_output("tbl_Filter_TD_11173530_output", 6100000, 4, "");
    tbl_Filter_TD_11173530_output.allocateHost();
    Table tbl_Filter_TD_11190108_output("tbl_Filter_TD_11190108_output", 6100000, 4, "");
    tbl_Filter_TD_11190108_output.allocateHost();
    Table tbl_JOIN_INNER_TD_11320228_output("tbl_JOIN_INNER_TD_11320228_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_11320228_output.allocateHost();
    Table tbl_SerializeFromObject_TD_12914841_input;
    tbl_SerializeFromObject_TD_12914841_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_12914841_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_12914841_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_12914841_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_12914841_input.addCol("ss_net_profit", 4);
    tbl_SerializeFromObject_TD_12914841_input.allocateHost();
    tbl_SerializeFromObject_TD_12914841_input.loadHost();
    Table tbl_SerializeFromObject_TD_1242456_input;
    tbl_SerializeFromObject_TD_1242456_input = Table("store_returns", store_returns_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_1242456_input.addCol("sr_store_sk", 4);
    tbl_SerializeFromObject_TD_1242456_input.addCol("sr_returned_date_sk", 4);
    tbl_SerializeFromObject_TD_1242456_input.addCol("sr_return_amt", 4);
    tbl_SerializeFromObject_TD_1242456_input.addCol("sr_net_loss", 4);
    tbl_SerializeFromObject_TD_1242456_input.allocateHost();
    tbl_SerializeFromObject_TD_1242456_input.loadHost();
    Table tbl_SerializeFromObject_TD_12121952_input;
    tbl_SerializeFromObject_TD_12121952_input = Table("catalog_sales", catalog_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_12121952_input.addCol("cs_catalog_page_sk", 4);
    tbl_SerializeFromObject_TD_12121952_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_12121952_input.addCol("cs_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_12121952_input.addCol("cs_net_profit", 4);
    tbl_SerializeFromObject_TD_12121952_input.allocateHost();
    tbl_SerializeFromObject_TD_12121952_input.loadHost();
    Table tbl_SerializeFromObject_TD_12330595_input;
    tbl_SerializeFromObject_TD_12330595_input = Table("catalog_returns", catalog_returns_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_12330595_input.addCol("cr_catalog_page_sk", 4);
    tbl_SerializeFromObject_TD_12330595_input.addCol("cr_returned_date_sk", 4);
    tbl_SerializeFromObject_TD_12330595_input.addCol("cr_return_amount", 4);
    tbl_SerializeFromObject_TD_12330595_input.addCol("cr_net_loss", 4);
    tbl_SerializeFromObject_TD_12330595_input.allocateHost();
    tbl_SerializeFromObject_TD_12330595_input.loadHost();
    Table tbl_SerializeFromObject_TD_12208814_input;
    tbl_SerializeFromObject_TD_12208814_input = Table("web_sales", web_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_12208814_input.addCol("ws_web_site_sk", 4);
    tbl_SerializeFromObject_TD_12208814_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_12208814_input.addCol("ws_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_12208814_input.addCol("ws_net_profit", 4);
    tbl_SerializeFromObject_TD_12208814_input.allocateHost();
    tbl_SerializeFromObject_TD_12208814_input.loadHost();
    Table tbl_Filter_TD_12427417_output("tbl_Filter_TD_12427417_output", 6100000, 5, "");
    tbl_Filter_TD_12427417_output.allocateHost();
    Table tbl_Filter_TD_12635927_output("tbl_Filter_TD_12635927_output", 6100000, 3, "");
    tbl_Filter_TD_12635927_output.allocateHost();
    Table tbl_SerializeFromObject_TD_13939313_input;
    tbl_SerializeFromObject_TD_13939313_input = Table("web_returns", web_returns_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_13939313_input.addCol("wr_returned_date_sk", 4);
    tbl_SerializeFromObject_TD_13939313_input.addCol("wr_item_sk", 4);
    tbl_SerializeFromObject_TD_13939313_input.addCol("wr_order_number", 8);
    tbl_SerializeFromObject_TD_13939313_input.addCol("wr_return_amt", 4);
    tbl_SerializeFromObject_TD_13939313_input.addCol("wr_net_loss", 4);
    tbl_SerializeFromObject_TD_13939313_input.allocateHost();
    tbl_SerializeFromObject_TD_13939313_input.loadHost();
    Table tbl_SerializeFromObject_TD_13656927_input;
    tbl_SerializeFromObject_TD_13656927_input = Table("web_sales", web_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_13656927_input.addCol("ws_item_sk", 4);
    tbl_SerializeFromObject_TD_13656927_input.addCol("ws_web_site_sk", 4);
    tbl_SerializeFromObject_TD_13656927_input.addCol("ws_order_number", 8);
    tbl_SerializeFromObject_TD_13656927_input.allocateHost();
    tbl_SerializeFromObject_TD_13656927_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_12_197731_s, tv_r_Filter_12_197731_e;
    gettimeofday(&tv_r_Filter_12_197731_s, 0);
    SW_Filter_TD_12635927(tbl_SerializeFromObject_TD_13656927_input, tbl_Filter_TD_12635927_output);
    gettimeofday(&tv_r_Filter_12_197731_e, 0);

    struct timeval tv_r_Filter_12_442837_s, tv_r_Filter_12_442837_e;
    gettimeofday(&tv_r_Filter_12_442837_s, 0);
    SW_Filter_TD_12427417(tbl_SerializeFromObject_TD_13939313_input, tbl_Filter_TD_12427417_output);
    gettimeofday(&tv_r_Filter_12_442837_e, 0);

    struct timeval tv_r_JOIN_INNER_11_831341_s, tv_r_JOIN_INNER_11_831341_e;
    gettimeofday(&tv_r_JOIN_INNER_11_831341_s, 0);
    SW_JOIN_INNER_TD_11320228(tbl_Filter_TD_12427417_output, tbl_Filter_TD_12635927_output, tbl_JOIN_INNER_TD_11320228_output);
    gettimeofday(&tv_r_JOIN_INNER_11_831341_e, 0);

    struct timeval tv_r_Filter_11_180859_s, tv_r_Filter_11_180859_e;
    gettimeofday(&tv_r_Filter_11_180859_s, 0);
    SW_Filter_TD_11190108(tbl_SerializeFromObject_TD_12208814_input, tbl_Filter_TD_11190108_output);
    gettimeofday(&tv_r_Filter_11_180859_e, 0);

    struct timeval tv_r_Filter_11_3_s, tv_r_Filter_11_3_e;
    gettimeofday(&tv_r_Filter_11_3_s, 0);
    SW_Filter_TD_11173530(tbl_SerializeFromObject_TD_12330595_input, tbl_Filter_TD_11173530_output);
    gettimeofday(&tv_r_Filter_11_3_e, 0);

    struct timeval tv_r_Filter_11_885247_s, tv_r_Filter_11_885247_e;
    gettimeofday(&tv_r_Filter_11_885247_s, 0);
    SW_Filter_TD_11644099(tbl_SerializeFromObject_TD_12121952_input, tbl_Filter_TD_11644099_output);
    gettimeofday(&tv_r_Filter_11_885247_e, 0);

    struct timeval tv_r_Filter_11_312806_s, tv_r_Filter_11_312806_e;
    gettimeofday(&tv_r_Filter_11_312806_s, 0);
    SW_Filter_TD_11519105(tbl_SerializeFromObject_TD_1242456_input, tbl_Filter_TD_11519105_output);
    gettimeofday(&tv_r_Filter_11_312806_e, 0);

    struct timeval tv_r_Filter_11_613112_s, tv_r_Filter_11_613112_e;
    gettimeofday(&tv_r_Filter_11_613112_s, 0);
    SW_Filter_TD_11183378(tbl_SerializeFromObject_TD_12914841_input, tbl_Filter_TD_11183378_output);
    gettimeofday(&tv_r_Filter_11_613112_e, 0);

    struct timeval tv_r_Project_10_599603_s, tv_r_Project_10_599603_e;
    gettimeofday(&tv_r_Project_10_599603_s, 0);
    SW_Project_TD_10926061(tbl_JOIN_INNER_TD_11320228_output, tbl_Project_TD_10926061_output);
    gettimeofday(&tv_r_Project_10_599603_e, 0);

    struct timeval tv_r_Project_10_685623_s, tv_r_Project_10_685623_e;
    gettimeofday(&tv_r_Project_10_685623_s, 0);
    SW_Project_TD_10400972(tbl_Filter_TD_11190108_output, tbl_Project_TD_10400972_output);
    gettimeofday(&tv_r_Project_10_685623_e, 0);

    struct timeval tv_r_Project_10_226545_s, tv_r_Project_10_226545_e;
    gettimeofday(&tv_r_Project_10_226545_s, 0);
    SW_Project_TD_10950398(tbl_Filter_TD_11173530_output, tbl_Project_TD_10950398_output);
    gettimeofday(&tv_r_Project_10_226545_e, 0);

    struct timeval tv_r_Project_10_418977_s, tv_r_Project_10_418977_e;
    gettimeofday(&tv_r_Project_10_418977_s, 0);
    SW_Project_TD_10840291(tbl_Filter_TD_11644099_output, tbl_Project_TD_10840291_output);
    gettimeofday(&tv_r_Project_10_418977_e, 0);

    struct timeval tv_r_Project_10_658053_s, tv_r_Project_10_658053_e;
    gettimeofday(&tv_r_Project_10_658053_s, 0);
    SW_Project_TD_10240760(tbl_Filter_TD_11519105_output, tbl_Project_TD_10240760_output);
    gettimeofday(&tv_r_Project_10_658053_e, 0);

    struct timeval tv_r_Project_10_836841_s, tv_r_Project_10_836841_e;
    gettimeofday(&tv_r_Project_10_836841_s, 0);
    SW_Project_TD_10341667(tbl_Filter_TD_11183378_output, tbl_Project_TD_10341667_output);
    gettimeofday(&tv_r_Project_10_836841_e, 0);

    struct timeval tv_r_Filter_9_978452_s, tv_r_Filter_9_978452_e;
    gettimeofday(&tv_r_Filter_9_978452_s, 0);
    SW_Filter_TD_9834949(tbl_SerializeFromObject_TD_10939837_input, tbl_Filter_TD_9834949_output);
    gettimeofday(&tv_r_Filter_9_978452_e, 0);

    struct timeval tv_r_Union_9_241683_s, tv_r_Union_9_241683_e;
    gettimeofday(&tv_r_Union_9_241683_s, 0);
    SW_Union_TD_980579(tbl_Project_TD_10400972_output, tbl_Project_TD_10926061_output, tbl_Union_TD_980579_output);
    gettimeofday(&tv_r_Union_9_241683_e, 0);

    struct timeval tv_r_Filter_9_546871_s, tv_r_Filter_9_546871_e;
    gettimeofday(&tv_r_Filter_9_546871_s, 0);
    SW_Filter_TD_9539098(tbl_SerializeFromObject_TD_10187856_input, tbl_Filter_TD_9539098_output);
    gettimeofday(&tv_r_Filter_9_546871_e, 0);

    struct timeval tv_r_Union_9_869405_s, tv_r_Union_9_869405_e;
    gettimeofday(&tv_r_Union_9_869405_s, 0);
    SW_Union_TD_9812863(tbl_Project_TD_10840291_output, tbl_Project_TD_10950398_output, tbl_Union_TD_9812863_output);
    gettimeofday(&tv_r_Union_9_869405_e, 0);

    struct timeval tv_r_Filter_9_250959_s, tv_r_Filter_9_250959_e;
    gettimeofday(&tv_r_Filter_9_250959_s, 0);
    SW_Filter_TD_9561562(tbl_SerializeFromObject_TD_10649452_input, tbl_Filter_TD_9561562_output);
    gettimeofday(&tv_r_Filter_9_250959_e, 0);

    struct timeval tv_r_Union_9_736435_s, tv_r_Union_9_736435_e;
    gettimeofday(&tv_r_Union_9_736435_s, 0);
    SW_Union_TD_9523992(tbl_Project_TD_10341667_output, tbl_Project_TD_10240760_output, tbl_Union_TD_9523992_output);
    gettimeofday(&tv_r_Union_9_736435_e, 0);

    struct timeval tv_r_Filter_8_727365_s, tv_r_Filter_8_727365_e;
    gettimeofday(&tv_r_Filter_8_727365_s, 0);
    SW_Filter_TD_8928910(tbl_SerializeFromObject_TD_9886392_input, tbl_Filter_TD_8928910_output);
    gettimeofday(&tv_r_Filter_8_727365_e, 0);

    struct timeval tv_r_JOIN_INNER_8_476753_s, tv_r_JOIN_INNER_8_476753_e;
    gettimeofday(&tv_r_JOIN_INNER_8_476753_s, 0);
    SW_JOIN_INNER_TD_8828693(tbl_Union_TD_980579_output, tbl_Filter_TD_9834949_output, tbl_JOIN_INNER_TD_8828693_output);
    gettimeofday(&tv_r_JOIN_INNER_8_476753_e, 0);

    struct timeval tv_r_Filter_8_178835_s, tv_r_Filter_8_178835_e;
    gettimeofday(&tv_r_Filter_8_178835_s, 0);
    SW_Filter_TD_8670372(tbl_SerializeFromObject_TD_9541220_input, tbl_Filter_TD_8670372_output);
    gettimeofday(&tv_r_Filter_8_178835_e, 0);

    struct timeval tv_r_JOIN_INNER_8_370247_s, tv_r_JOIN_INNER_8_370247_e;
    gettimeofday(&tv_r_JOIN_INNER_8_370247_s, 0);
    SW_JOIN_INNER_TD_8779433(tbl_Union_TD_9812863_output, tbl_Filter_TD_9539098_output, tbl_JOIN_INNER_TD_8779433_output);
    gettimeofday(&tv_r_JOIN_INNER_8_370247_e, 0);

    struct timeval tv_r_Filter_8_954729_s, tv_r_Filter_8_954729_e;
    gettimeofday(&tv_r_Filter_8_954729_s, 0);
    SW_Filter_TD_8378457(tbl_SerializeFromObject_TD_9326199_input, tbl_Filter_TD_8378457_output);
    gettimeofday(&tv_r_Filter_8_954729_e, 0);

    struct timeval tv_r_JOIN_INNER_8_851810_s, tv_r_JOIN_INNER_8_851810_e;
    gettimeofday(&tv_r_JOIN_INNER_8_851810_s, 0);
    SW_JOIN_INNER_TD_8825954(tbl_Union_TD_9523992_output, tbl_Filter_TD_9561562_output, tbl_JOIN_INNER_TD_8825954_output);
    gettimeofday(&tv_r_JOIN_INNER_8_851810_e, 0);

    struct timeval tv_r_JOIN_INNER_7_488768_s, tv_r_JOIN_INNER_7_488768_e;
    gettimeofday(&tv_r_JOIN_INNER_7_488768_s, 0);
    SW_JOIN_INNER_TD_7603722(tbl_JOIN_INNER_TD_8828693_output, tbl_Filter_TD_8928910_output, tbl_JOIN_INNER_TD_7603722_output);
    gettimeofday(&tv_r_JOIN_INNER_7_488768_e, 0);

    struct timeval tv_r_JOIN_INNER_7_660865_s, tv_r_JOIN_INNER_7_660865_e;
    gettimeofday(&tv_r_JOIN_INNER_7_660865_s, 0);
    SW_JOIN_INNER_TD_7797349(tbl_JOIN_INNER_TD_8779433_output, tbl_Filter_TD_8670372_output, tbl_JOIN_INNER_TD_7797349_output);
    gettimeofday(&tv_r_JOIN_INNER_7_660865_e, 0);

    struct timeval tv_r_JOIN_INNER_7_911729_s, tv_r_JOIN_INNER_7_911729_e;
    gettimeofday(&tv_r_JOIN_INNER_7_911729_s, 0);
    SW_JOIN_INNER_TD_7904255(tbl_JOIN_INNER_TD_8825954_output, tbl_Filter_TD_8378457_output, tbl_JOIN_INNER_TD_7904255_output);
    gettimeofday(&tv_r_JOIN_INNER_7_911729_e, 0);

    struct timeval tv_r_Aggregate_6_1315_s, tv_r_Aggregate_6_1315_e;
    gettimeofday(&tv_r_Aggregate_6_1315_s, 0);
    SW_Aggregate_TD_6713678(tbl_JOIN_INNER_TD_7603722_output, tbl_Aggregate_TD_6713678_output);
    gettimeofday(&tv_r_Aggregate_6_1315_e, 0);

    struct timeval tv_r_Aggregate_6_685081_s, tv_r_Aggregate_6_685081_e;
    gettimeofday(&tv_r_Aggregate_6_685081_s, 0);
    SW_Aggregate_TD_6302693(tbl_JOIN_INNER_TD_7797349_output, tbl_Aggregate_TD_6302693_output);
    gettimeofday(&tv_r_Aggregate_6_685081_e, 0);

    struct timeval tv_r_Aggregate_6_839389_s, tv_r_Aggregate_6_839389_e;
    gettimeofday(&tv_r_Aggregate_6_839389_s, 0);
    SW_Aggregate_TD_6804953(tbl_JOIN_INNER_TD_7904255_output, tbl_Aggregate_TD_6804953_output);
    gettimeofday(&tv_r_Aggregate_6_839389_e, 0);

    struct timeval tv_r_Union_5_98426_s, tv_r_Union_5_98426_e;
    gettimeofday(&tv_r_Union_5_98426_s, 0);
    SW_Union_TD_5271381(tbl_Aggregate_TD_6804953_output, tbl_Aggregate_TD_6302693_output, tbl_Aggregate_TD_6713678_output, tbl_Union_TD_5271381_output);
    gettimeofday(&tv_r_Union_5_98426_e, 0);

    struct timeval tv_r_Expand_4_325712_s, tv_r_Expand_4_325712_e;
    gettimeofday(&tv_r_Expand_4_325712_s, 0);
    SW_Expand_TD_4449971(tbl_Union_TD_5271381_output, tbl_Expand_TD_4449971_output);
    gettimeofday(&tv_r_Expand_4_325712_e, 0);

    struct timeval tv_r_Aggregate_3_22215_s, tv_r_Aggregate_3_22215_e;
    gettimeofday(&tv_r_Aggregate_3_22215_s, 0);
    SW_Aggregate_TD_319948(tbl_Expand_TD_4449971_output, tbl_Aggregate_TD_319948_output);
    gettimeofday(&tv_r_Aggregate_3_22215_e, 0);

    struct timeval tv_r_Sort_2_855200_s, tv_r_Sort_2_855200_e;
    gettimeofday(&tv_r_Sort_2_855200_s, 0);
    SW_Sort_TD_2670203(tbl_Aggregate_TD_319948_output, tbl_Sort_TD_2670203_output);
    gettimeofday(&tv_r_Sort_2_855200_e, 0);

    struct timeval tv_r_LocalLimit_1_656014_s, tv_r_LocalLimit_1_656014_e;
    gettimeofday(&tv_r_LocalLimit_1_656014_s, 0);
    SW_LocalLimit_TD_1610557(tbl_Sort_TD_2670203_output, tbl_LocalLimit_TD_1610557_output);
    gettimeofday(&tv_r_LocalLimit_1_656014_e, 0);

    struct timeval tv_r_GlobalLimit_0_52445_s, tv_r_GlobalLimit_0_52445_e;
    gettimeofday(&tv_r_GlobalLimit_0_52445_s, 0);
    SW_GlobalLimit_TD_0194894(tbl_LocalLimit_TD_1610557_output, tbl_GlobalLimit_TD_0194894_output);
    gettimeofday(&tv_r_GlobalLimit_0_52445_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_197731_s, &tv_r_Filter_12_197731_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13656927_input: " << tbl_SerializeFromObject_TD_13656927_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_442837_s, &tv_r_Filter_12_442837_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13939313_input: " << tbl_SerializeFromObject_TD_13939313_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_11: " << tvdiff(&tv_r_JOIN_INNER_11_831341_s, &tv_r_JOIN_INNER_11_831341_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_12427417_output: " << tbl_Filter_TD_12427417_output.getNumRow() << " " << "tbl_Filter_TD_12635927_output: " << tbl_Filter_TD_12635927_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_180859_s, &tv_r_Filter_11_180859_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12208814_input: " << tbl_SerializeFromObject_TD_12208814_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_3_s, &tv_r_Filter_11_3_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12330595_input: " << tbl_SerializeFromObject_TD_12330595_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_885247_s, &tv_r_Filter_11_885247_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12121952_input: " << tbl_SerializeFromObject_TD_12121952_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_312806_s, &tv_r_Filter_11_312806_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1242456_input: " << tbl_SerializeFromObject_TD_1242456_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_613112_s, &tv_r_Filter_11_613112_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12914841_input: " << tbl_SerializeFromObject_TD_12914841_input.getNumRow() << " " << std::endl; 

    std::cout << "Project_10: " << tvdiff(&tv_r_Project_10_599603_s, &tv_r_Project_10_599603_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_11320228_output: " << tbl_JOIN_INNER_TD_11320228_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_10: " << tvdiff(&tv_r_Project_10_685623_s, &tv_r_Project_10_685623_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11190108_output: " << tbl_Filter_TD_11190108_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_10: " << tvdiff(&tv_r_Project_10_226545_s, &tv_r_Project_10_226545_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11173530_output: " << tbl_Filter_TD_11173530_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_10: " << tvdiff(&tv_r_Project_10_418977_s, &tv_r_Project_10_418977_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11644099_output: " << tbl_Filter_TD_11644099_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_10: " << tvdiff(&tv_r_Project_10_658053_s, &tv_r_Project_10_658053_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11519105_output: " << tbl_Filter_TD_11519105_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_10: " << tvdiff(&tv_r_Project_10_836841_s, &tv_r_Project_10_836841_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11183378_output: " << tbl_Filter_TD_11183378_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_978452_s, &tv_r_Filter_9_978452_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10939837_input: " << tbl_SerializeFromObject_TD_10939837_input.getNumRow() << " " << std::endl; 

    std::cout << "Union_9: " << tvdiff(&tv_r_Union_9_241683_s, &tv_r_Union_9_241683_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_10400972_output: " << tbl_Project_TD_10400972_output.getNumRow() << " " << "tbl_Project_TD_10926061_output: " << tbl_Project_TD_10926061_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_546871_s, &tv_r_Filter_9_546871_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10187856_input: " << tbl_SerializeFromObject_TD_10187856_input.getNumRow() << " " << std::endl; 

    std::cout << "Union_9: " << tvdiff(&tv_r_Union_9_869405_s, &tv_r_Union_9_869405_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_10840291_output: " << tbl_Project_TD_10840291_output.getNumRow() << " " << "tbl_Project_TD_10950398_output: " << tbl_Project_TD_10950398_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_250959_s, &tv_r_Filter_9_250959_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10649452_input: " << tbl_SerializeFromObject_TD_10649452_input.getNumRow() << " " << std::endl; 

    std::cout << "Union_9: " << tvdiff(&tv_r_Union_9_736435_s, &tv_r_Union_9_736435_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_10341667_output: " << tbl_Project_TD_10341667_output.getNumRow() << " " << "tbl_Project_TD_10240760_output: " << tbl_Project_TD_10240760_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_727365_s, &tv_r_Filter_8_727365_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9886392_input: " << tbl_SerializeFromObject_TD_9886392_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_476753_s, &tv_r_JOIN_INNER_8_476753_e) / 1000.0 << " ms " 
     << "tbl_Union_TD_980579_output: " << tbl_Union_TD_980579_output.getNumRow() << " " << "tbl_Filter_TD_9834949_output: " << tbl_Filter_TD_9834949_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_178835_s, &tv_r_Filter_8_178835_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9541220_input: " << tbl_SerializeFromObject_TD_9541220_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_370247_s, &tv_r_JOIN_INNER_8_370247_e) / 1000.0 << " ms " 
     << "tbl_Union_TD_9812863_output: " << tbl_Union_TD_9812863_output.getNumRow() << " " << "tbl_Filter_TD_9539098_output: " << tbl_Filter_TD_9539098_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_954729_s, &tv_r_Filter_8_954729_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9326199_input: " << tbl_SerializeFromObject_TD_9326199_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_851810_s, &tv_r_JOIN_INNER_8_851810_e) / 1000.0 << " ms " 
     << "tbl_Union_TD_9523992_output: " << tbl_Union_TD_9523992_output.getNumRow() << " " << "tbl_Filter_TD_9561562_output: " << tbl_Filter_TD_9561562_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_488768_s, &tv_r_JOIN_INNER_7_488768_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8828693_output: " << tbl_JOIN_INNER_TD_8828693_output.getNumRow() << " " << "tbl_Filter_TD_8928910_output: " << tbl_Filter_TD_8928910_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_660865_s, &tv_r_JOIN_INNER_7_660865_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8779433_output: " << tbl_JOIN_INNER_TD_8779433_output.getNumRow() << " " << "tbl_Filter_TD_8670372_output: " << tbl_Filter_TD_8670372_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_911729_s, &tv_r_JOIN_INNER_7_911729_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8825954_output: " << tbl_JOIN_INNER_TD_8825954_output.getNumRow() << " " << "tbl_Filter_TD_8378457_output: " << tbl_Filter_TD_8378457_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_6: " << tvdiff(&tv_r_Aggregate_6_1315_s, &tv_r_Aggregate_6_1315_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7603722_output: " << tbl_JOIN_INNER_TD_7603722_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_6: " << tvdiff(&tv_r_Aggregate_6_685081_s, &tv_r_Aggregate_6_685081_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7797349_output: " << tbl_JOIN_INNER_TD_7797349_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_6: " << tvdiff(&tv_r_Aggregate_6_839389_s, &tv_r_Aggregate_6_839389_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7904255_output: " << tbl_JOIN_INNER_TD_7904255_output.getNumRow() << " " << std::endl; 

    std::cout << "Union_5: " << tvdiff(&tv_r_Union_5_98426_s, &tv_r_Union_5_98426_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_6804953_output: " << tbl_Aggregate_TD_6804953_output.getNumRow() << " " << "tbl_Aggregate_TD_6302693_output: " << tbl_Aggregate_TD_6302693_output.getNumRow() << " " << "tbl_Aggregate_TD_6713678_output: " << tbl_Aggregate_TD_6713678_output.getNumRow() << " " << std::endl; 

    std::cout << "Expand_4: " << tvdiff(&tv_r_Expand_4_325712_s, &tv_r_Expand_4_325712_e) / 1000.0 << " ms " 
     << "tbl_Union_TD_5271381_output: " << tbl_Union_TD_5271381_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_22215_s, &tv_r_Aggregate_3_22215_e) / 1000.0 << " ms " 
     << "tbl_Expand_TD_4449971_output: " << tbl_Expand_TD_4449971_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_855200_s, &tv_r_Sort_2_855200_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_319948_output: " << tbl_Aggregate_TD_319948_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_656014_s, &tv_r_LocalLimit_1_656014_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2670203_output: " << tbl_Sort_TD_2670203_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_52445_s, &tv_r_GlobalLimit_0_52445_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1610557_output: " << tbl_LocalLimit_TD_1610557_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 3.2792542 * 1000 << "ms" << std::endl; 
    return 0; 
}
