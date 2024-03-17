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

#include "cfgFunc_q71.hpp" 
#include "q71.hpp" 

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
    std::cout << "NOTE:running query #71\n."; 
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
    Table tbl_Sort_TD_0434544_output("tbl_Sort_TD_0434544_output", 6100000, 5, "");
    tbl_Sort_TD_0434544_output.allocateHost();
    Table tbl_Aggregate_TD_1621060_output("tbl_Aggregate_TD_1621060_output", 6100000, 5, "");
    tbl_Aggregate_TD_1621060_output.allocateHost();
    Table tbl_JOIN_INNER_TD_2111129_output("tbl_JOIN_INNER_TD_2111129_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_2111129_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3329195_output("tbl_JOIN_INNER_TD_3329195_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_3329195_output.allocateHost();
    Table tbl_Filter_TD_3228522_output("tbl_Filter_TD_3228522_output", 6100000, 3, "");
    tbl_Filter_TD_3228522_output.allocateHost();
    Table tbl_Filter_TD_4891119_output("tbl_Filter_TD_4891119_output", 6100000, 3, "");
    tbl_Filter_TD_4891119_output.allocateHost();
    Table tbl_Union_TD_4542419_output("tbl_Union_TD_4542419_output", 6100000, 3, "");
    tbl_Union_TD_4542419_output.allocateHost();
    Table tbl_SerializeFromObject_TD_4839560_input;
    tbl_SerializeFromObject_TD_4839560_input = Table("time_dim", time_dim_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_4839560_input.addCol("t_time_sk", 4);
    tbl_SerializeFromObject_TD_4839560_input.addCol("t_hour", 4);
    tbl_SerializeFromObject_TD_4839560_input.addCol("t_minute", 4);
    tbl_SerializeFromObject_TD_4839560_input.addCol("t_meal_time", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_4839560_input.allocateHost();
    tbl_SerializeFromObject_TD_4839560_input.loadHost();
    Table tbl_SerializeFromObject_TD_5483920_input;
    tbl_SerializeFromObject_TD_5483920_input = Table("item", item_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_5483920_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_5483920_input.addCol("i_brand_id", 4);
    tbl_SerializeFromObject_TD_5483920_input.addCol("i_brand", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_5483920_input.addCol("i_manager_id", 4);
    tbl_SerializeFromObject_TD_5483920_input.allocateHost();
    tbl_SerializeFromObject_TD_5483920_input.loadHost();
    Table tbl_Project_TD_5746317_output("tbl_Project_TD_5746317_output", 6100000, 3, "");
    tbl_Project_TD_5746317_output.allocateHost();
    Table tbl_Project_TD_5188579_output("tbl_Project_TD_5188579_output", 6100000, 3, "");
    tbl_Project_TD_5188579_output.allocateHost();
    Table tbl_Project_TD_516911_output("tbl_Project_TD_516911_output", 6100000, 3, "");
    tbl_Project_TD_516911_output.allocateHost();
    Table tbl_JOIN_INNER_TD_646046_output("tbl_JOIN_INNER_TD_646046_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_646046_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6463096_output("tbl_JOIN_INNER_TD_6463096_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_6463096_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6577483_output("tbl_JOIN_INNER_TD_6577483_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_6577483_output.allocateHost();
    Table tbl_Filter_TD_7675179_output("tbl_Filter_TD_7675179_output", 6100000, 4, "");
    tbl_Filter_TD_7675179_output.allocateHost();
    Table tbl_Filter_TD_7772714_output("tbl_Filter_TD_7772714_output", 6100000, 1, "");
    tbl_Filter_TD_7772714_output.allocateHost();
    Table tbl_Filter_TD_7490330_output("tbl_Filter_TD_7490330_output", 6100000, 4, "");
    tbl_Filter_TD_7490330_output.allocateHost();
    Table tbl_Filter_TD_7697127_output("tbl_Filter_TD_7697127_output", 6100000, 1, "");
    tbl_Filter_TD_7697127_output.allocateHost();
    Table tbl_Filter_TD_7416657_output("tbl_Filter_TD_7416657_output", 6100000, 4, "");
    tbl_Filter_TD_7416657_output.allocateHost();
    Table tbl_Filter_TD_7369543_output("tbl_Filter_TD_7369543_output", 6100000, 1, "");
    tbl_Filter_TD_7369543_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8504978_input;
    tbl_SerializeFromObject_TD_8504978_input = Table("web_sales", web_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_8504978_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_8504978_input.addCol("ws_sold_time_sk", 4);
    tbl_SerializeFromObject_TD_8504978_input.addCol("ws_item_sk", 4);
    tbl_SerializeFromObject_TD_8504978_input.addCol("ws_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_8504978_input.allocateHost();
    tbl_SerializeFromObject_TD_8504978_input.loadHost();
    Table tbl_SerializeFromObject_TD_8241330_input;
    tbl_SerializeFromObject_TD_8241330_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8241330_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_8241330_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_8241330_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_8241330_input.allocateHost();
    tbl_SerializeFromObject_TD_8241330_input.loadHost();
    Table tbl_SerializeFromObject_TD_8690146_input;
    tbl_SerializeFromObject_TD_8690146_input = Table("catalog_sales", catalog_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_8690146_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_8690146_input.addCol("cs_sold_time_sk", 4);
    tbl_SerializeFromObject_TD_8690146_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_8690146_input.addCol("cs_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_8690146_input.allocateHost();
    tbl_SerializeFromObject_TD_8690146_input.loadHost();
    Table tbl_SerializeFromObject_TD_8620034_input;
    tbl_SerializeFromObject_TD_8620034_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8620034_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_8620034_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_8620034_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_8620034_input.allocateHost();
    tbl_SerializeFromObject_TD_8620034_input.loadHost();
    Table tbl_SerializeFromObject_TD_8556038_input;
    tbl_SerializeFromObject_TD_8556038_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_8556038_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_8556038_input.addCol("ss_sold_time_sk", 4);
    tbl_SerializeFromObject_TD_8556038_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_8556038_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_8556038_input.allocateHost();
    tbl_SerializeFromObject_TD_8556038_input.loadHost();
    Table tbl_SerializeFromObject_TD_8813871_input;
    tbl_SerializeFromObject_TD_8813871_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8813871_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_8813871_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_8813871_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_8813871_input.allocateHost();
    tbl_SerializeFromObject_TD_8813871_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_7_131373_s, tv_r_Filter_7_131373_e;
    gettimeofday(&tv_r_Filter_7_131373_s, 0);
    SW_Filter_TD_7369543(tbl_SerializeFromObject_TD_8813871_input, tbl_Filter_TD_7369543_output);
    gettimeofday(&tv_r_Filter_7_131373_e, 0);

    struct timeval tv_r_Filter_7_428617_s, tv_r_Filter_7_428617_e;
    gettimeofday(&tv_r_Filter_7_428617_s, 0);
    SW_Filter_TD_7416657(tbl_SerializeFromObject_TD_8556038_input, tbl_Filter_TD_7416657_output);
    gettimeofday(&tv_r_Filter_7_428617_e, 0);

    struct timeval tv_r_Filter_7_572254_s, tv_r_Filter_7_572254_e;
    gettimeofday(&tv_r_Filter_7_572254_s, 0);
    SW_Filter_TD_7697127(tbl_SerializeFromObject_TD_8620034_input, tbl_Filter_TD_7697127_output);
    gettimeofday(&tv_r_Filter_7_572254_e, 0);

    struct timeval tv_r_Filter_7_204528_s, tv_r_Filter_7_204528_e;
    gettimeofday(&tv_r_Filter_7_204528_s, 0);
    SW_Filter_TD_7490330(tbl_SerializeFromObject_TD_8690146_input, tbl_Filter_TD_7490330_output);
    gettimeofday(&tv_r_Filter_7_204528_e, 0);

    struct timeval tv_r_Filter_7_692921_s, tv_r_Filter_7_692921_e;
    gettimeofday(&tv_r_Filter_7_692921_s, 0);
    SW_Filter_TD_7772714(tbl_SerializeFromObject_TD_8241330_input, tbl_Filter_TD_7772714_output);
    gettimeofday(&tv_r_Filter_7_692921_e, 0);

    struct timeval tv_r_Filter_7_426198_s, tv_r_Filter_7_426198_e;
    gettimeofday(&tv_r_Filter_7_426198_s, 0);
    SW_Filter_TD_7675179(tbl_SerializeFromObject_TD_8504978_input, tbl_Filter_TD_7675179_output);
    gettimeofday(&tv_r_Filter_7_426198_e, 0);

    struct timeval tv_r_JOIN_INNER_6_147657_s, tv_r_JOIN_INNER_6_147657_e;
    gettimeofday(&tv_r_JOIN_INNER_6_147657_s, 0);
    SW_JOIN_INNER_TD_6577483(tbl_Filter_TD_7416657_output, tbl_Filter_TD_7369543_output, tbl_JOIN_INNER_TD_6577483_output);
    gettimeofday(&tv_r_JOIN_INNER_6_147657_e, 0);

    struct timeval tv_r_JOIN_INNER_6_137812_s, tv_r_JOIN_INNER_6_137812_e;
    gettimeofday(&tv_r_JOIN_INNER_6_137812_s, 0);
    SW_JOIN_INNER_TD_6463096(tbl_Filter_TD_7490330_output, tbl_Filter_TD_7697127_output, tbl_JOIN_INNER_TD_6463096_output);
    gettimeofday(&tv_r_JOIN_INNER_6_137812_e, 0);

    struct timeval tv_r_JOIN_INNER_6_289990_s, tv_r_JOIN_INNER_6_289990_e;
    gettimeofday(&tv_r_JOIN_INNER_6_289990_s, 0);
    SW_JOIN_INNER_TD_646046(tbl_Filter_TD_7675179_output, tbl_Filter_TD_7772714_output, tbl_JOIN_INNER_TD_646046_output);
    gettimeofday(&tv_r_JOIN_INNER_6_289990_e, 0);

    struct timeval tv_r_Project_5_970638_s, tv_r_Project_5_970638_e;
    gettimeofday(&tv_r_Project_5_970638_s, 0);
    SW_Project_TD_516911(tbl_JOIN_INNER_TD_6577483_output, tbl_Project_TD_516911_output);
    gettimeofday(&tv_r_Project_5_970638_e, 0);

    struct timeval tv_r_Project_5_4064_s, tv_r_Project_5_4064_e;
    gettimeofday(&tv_r_Project_5_4064_s, 0);
    SW_Project_TD_5188579(tbl_JOIN_INNER_TD_6463096_output, tbl_Project_TD_5188579_output);
    gettimeofday(&tv_r_Project_5_4064_e, 0);

    struct timeval tv_r_Project_5_92297_s, tv_r_Project_5_92297_e;
    gettimeofday(&tv_r_Project_5_92297_s, 0);
    SW_Project_TD_5746317(tbl_JOIN_INNER_TD_646046_output, tbl_Project_TD_5746317_output);
    gettimeofday(&tv_r_Project_5_92297_e, 0);

    struct timeval tv_r_Union_4_51510_s, tv_r_Union_4_51510_e;
    gettimeofday(&tv_r_Union_4_51510_s, 0);
    SW_Union_TD_4542419(tbl_Project_TD_5746317_output, tbl_Project_TD_5188579_output, tbl_Project_TD_516911_output, tbl_Union_TD_4542419_output);
    gettimeofday(&tv_r_Union_4_51510_e, 0);

    struct timeval tv_r_Filter_4_262444_s, tv_r_Filter_4_262444_e;
    gettimeofday(&tv_r_Filter_4_262444_s, 0);
    SW_Filter_TD_4891119(tbl_SerializeFromObject_TD_5483920_input, tbl_Filter_TD_4891119_output);
    gettimeofday(&tv_r_Filter_4_262444_e, 0);

    struct timeval tv_r_Filter_3_526967_s, tv_r_Filter_3_526967_e;
    gettimeofday(&tv_r_Filter_3_526967_s, 0);
    SW_Filter_TD_3228522(tbl_SerializeFromObject_TD_4839560_input, tbl_Filter_TD_3228522_output);
    gettimeofday(&tv_r_Filter_3_526967_e, 0);

    struct timeval tv_r_JOIN_INNER_3_274557_s, tv_r_JOIN_INNER_3_274557_e;
    gettimeofday(&tv_r_JOIN_INNER_3_274557_s, 0);
    SW_JOIN_INNER_TD_3329195(tbl_Filter_TD_4891119_output, tbl_Union_TD_4542419_output, tbl_JOIN_INNER_TD_3329195_output);
    gettimeofday(&tv_r_JOIN_INNER_3_274557_e, 0);

    struct timeval tv_r_JOIN_INNER_2_889239_s, tv_r_JOIN_INNER_2_889239_e;
    gettimeofday(&tv_r_JOIN_INNER_2_889239_s, 0);
    SW_JOIN_INNER_TD_2111129(tbl_JOIN_INNER_TD_3329195_output, tbl_Filter_TD_3228522_output, tbl_JOIN_INNER_TD_2111129_output);
    gettimeofday(&tv_r_JOIN_INNER_2_889239_e, 0);

    struct timeval tv_r_Aggregate_1_700235_s, tv_r_Aggregate_1_700235_e;
    gettimeofday(&tv_r_Aggregate_1_700235_s, 0);
    SW_Aggregate_TD_1621060(tbl_JOIN_INNER_TD_2111129_output, tbl_Aggregate_TD_1621060_output);
    gettimeofday(&tv_r_Aggregate_1_700235_e, 0);

    struct timeval tv_r_Sort_0_761888_s, tv_r_Sort_0_761888_e;
    gettimeofday(&tv_r_Sort_0_761888_s, 0);
    SW_Sort_TD_0434544(tbl_Aggregate_TD_1621060_output, tbl_Sort_TD_0434544_output);
    gettimeofday(&tv_r_Sort_0_761888_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_131373_s, &tv_r_Filter_7_131373_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8813871_input: " << tbl_SerializeFromObject_TD_8813871_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_428617_s, &tv_r_Filter_7_428617_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8556038_input: " << tbl_SerializeFromObject_TD_8556038_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_572254_s, &tv_r_Filter_7_572254_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8620034_input: " << tbl_SerializeFromObject_TD_8620034_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_204528_s, &tv_r_Filter_7_204528_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8690146_input: " << tbl_SerializeFromObject_TD_8690146_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_692921_s, &tv_r_Filter_7_692921_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8241330_input: " << tbl_SerializeFromObject_TD_8241330_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_426198_s, &tv_r_Filter_7_426198_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8504978_input: " << tbl_SerializeFromObject_TD_8504978_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_147657_s, &tv_r_JOIN_INNER_6_147657_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_7416657_output: " << tbl_Filter_TD_7416657_output.getNumRow() << " " << "tbl_Filter_TD_7369543_output: " << tbl_Filter_TD_7369543_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_137812_s, &tv_r_JOIN_INNER_6_137812_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_7490330_output: " << tbl_Filter_TD_7490330_output.getNumRow() << " " << "tbl_Filter_TD_7697127_output: " << tbl_Filter_TD_7697127_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_289990_s, &tv_r_JOIN_INNER_6_289990_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_7675179_output: " << tbl_Filter_TD_7675179_output.getNumRow() << " " << "tbl_Filter_TD_7772714_output: " << tbl_Filter_TD_7772714_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_5: " << tvdiff(&tv_r_Project_5_970638_s, &tv_r_Project_5_970638_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6577483_output: " << tbl_JOIN_INNER_TD_6577483_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_5: " << tvdiff(&tv_r_Project_5_4064_s, &tv_r_Project_5_4064_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6463096_output: " << tbl_JOIN_INNER_TD_6463096_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_5: " << tvdiff(&tv_r_Project_5_92297_s, &tv_r_Project_5_92297_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_646046_output: " << tbl_JOIN_INNER_TD_646046_output.getNumRow() << " " << std::endl; 

    std::cout << "Union_4: " << tvdiff(&tv_r_Union_4_51510_s, &tv_r_Union_4_51510_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_5746317_output: " << tbl_Project_TD_5746317_output.getNumRow() << " " << "tbl_Project_TD_5188579_output: " << tbl_Project_TD_5188579_output.getNumRow() << " " << "tbl_Project_TD_516911_output: " << tbl_Project_TD_516911_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_262444_s, &tv_r_Filter_4_262444_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5483920_input: " << tbl_SerializeFromObject_TD_5483920_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_526967_s, &tv_r_Filter_3_526967_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_4839560_input: " << tbl_SerializeFromObject_TD_4839560_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_274557_s, &tv_r_JOIN_INNER_3_274557_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_4891119_output: " << tbl_Filter_TD_4891119_output.getNumRow() << " " << "tbl_Union_TD_4542419_output: " << tbl_Union_TD_4542419_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_2: " << tvdiff(&tv_r_JOIN_INNER_2_889239_s, &tv_r_JOIN_INNER_2_889239_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3329195_output: " << tbl_JOIN_INNER_TD_3329195_output.getNumRow() << " " << "tbl_Filter_TD_3228522_output: " << tbl_Filter_TD_3228522_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_700235_s, &tv_r_Aggregate_1_700235_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_2111129_output: " << tbl_JOIN_INNER_TD_2111129_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_761888_s, &tv_r_Sort_0_761888_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_1621060_output: " << tbl_Aggregate_TD_1621060_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.9581153 * 1000 << "ms" << std::endl; 
    return 0; 
}
