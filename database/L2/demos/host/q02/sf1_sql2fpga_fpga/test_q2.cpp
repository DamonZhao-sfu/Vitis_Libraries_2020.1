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

#include "cfgFunc_q2.hpp" 
#include "q2.hpp" 

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
    std::cout << "NOTE:running query #2\n."; 
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
    Table tbl_Sort_TD_0638674_output("tbl_Sort_TD_0638674_output", 6100000, 8, "");
    tbl_Sort_TD_0638674_output.allocateHost();
    Table tbl_Project_TD_1645820_output("tbl_Project_TD_1645820_output", 6100000, 8, "");
    tbl_Project_TD_1645820_output.allocateHost();
    Table tbl_JOIN_INNER_TD_2353970_output("tbl_JOIN_INNER_TD_2353970_output", 6100000, 15, "");
    tbl_JOIN_INNER_TD_2353970_output.allocateHost();
    Table tbl_Project_TD_3759542_output("tbl_Project_TD_3759542_output", 6100000, 8, "");
    tbl_Project_TD_3759542_output.allocateHost();
    Table tbl_Project_TD_3531034_output("tbl_Project_TD_3531034_output", 6100000, 8, "");
    tbl_Project_TD_3531034_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4970008_output("tbl_JOIN_INNER_TD_4970008_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_4970008_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4804647_output("tbl_JOIN_INNER_TD_4804647_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_4804647_output.allocateHost();
    Table tbl_Aggregate_TD_5928393_output("tbl_Aggregate_TD_5928393_output", 6100000, 8, "");
    tbl_Aggregate_TD_5928393_output.allocateHost();
    Table tbl_Filter_TD_5955066_output("tbl_Filter_TD_5955066_output", 6100000, 1, "");
    tbl_Filter_TD_5955066_output.allocateHost();
    Table tbl_Aggregate_TD_5941078_output("tbl_Aggregate_TD_5941078_output", 6100000, 8, "");
    tbl_Aggregate_TD_5941078_output.allocateHost();
    Table tbl_Filter_TD_5146130_output("tbl_Filter_TD_5146130_output", 6100000, 1, "");
    tbl_Filter_TD_5146130_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6614106_output("tbl_JOIN_INNER_TD_6614106_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_6614106_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6582006_input;
    tbl_SerializeFromObject_TD_6582006_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_6582006_input.addCol("d_week_seq", 4);
    tbl_SerializeFromObject_TD_6582006_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_6582006_input.allocateHost();
    tbl_SerializeFromObject_TD_6582006_input.loadHost();
    Table tbl_JOIN_INNER_TD_6479048_output("tbl_JOIN_INNER_TD_6479048_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_6479048_output.allocateHost();
    Table tbl_SerializeFromObject_TD_693662_input;
    tbl_SerializeFromObject_TD_693662_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_693662_input.addCol("d_week_seq", 4);
    tbl_SerializeFromObject_TD_693662_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_693662_input.allocateHost();
    tbl_SerializeFromObject_TD_693662_input.loadHost();
    Table tbl_Union_TD_7159974_output("tbl_Union_TD_7159974_output", 6100000, 2, "");
    tbl_Union_TD_7159974_output.allocateHost();
    Table tbl_Filter_TD_7212909_output("tbl_Filter_TD_7212909_output", 6100000, 3, "");
    tbl_Filter_TD_7212909_output.allocateHost();
    Table tbl_Union_TD_728800_output("tbl_Union_TD_728800_output", 6100000, 2, "");
    tbl_Union_TD_728800_output.allocateHost();
    Table tbl_Filter_TD_7666715_output("tbl_Filter_TD_7666715_output", 6100000, 3, "");
    tbl_Filter_TD_7666715_output.allocateHost();
    Table tbl_Project_TD_880677_output("tbl_Project_TD_880677_output", 6100000, 2, "");
    tbl_Project_TD_880677_output.allocateHost();
    Table tbl_Project_TD_8411917_output("tbl_Project_TD_8411917_output", 6100000, 2, "");
    tbl_Project_TD_8411917_output.allocateHost();
    Table tbl_SerializeFromObject_TD_874855_input;
    tbl_SerializeFromObject_TD_874855_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_874855_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_874855_input.addCol("d_week_seq", 4);
    tbl_SerializeFromObject_TD_874855_input.addCol("d_day_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_874855_input.allocateHost();
    tbl_SerializeFromObject_TD_874855_input.loadHost();
    Table tbl_Project_TD_8396090_output("tbl_Project_TD_8396090_output", 6100000, 2, "");
    tbl_Project_TD_8396090_output.allocateHost();
    Table tbl_Project_TD_8854524_output("tbl_Project_TD_8854524_output", 6100000, 2, "");
    tbl_Project_TD_8854524_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8177967_input;
    tbl_SerializeFromObject_TD_8177967_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8177967_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_8177967_input.addCol("d_week_seq", 4);
    tbl_SerializeFromObject_TD_8177967_input.addCol("d_day_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8177967_input.allocateHost();
    tbl_SerializeFromObject_TD_8177967_input.loadHost();
    Table tbl_Filter_TD_9501449_output("tbl_Filter_TD_9501449_output", 6100000, 2, "");
    tbl_Filter_TD_9501449_output.allocateHost();
    Table tbl_Filter_TD_9871123_output("tbl_Filter_TD_9871123_output", 6100000, 2, "");
    tbl_Filter_TD_9871123_output.allocateHost();
    Table tbl_Filter_TD_9340820_output("tbl_Filter_TD_9340820_output", 6100000, 2, "");
    tbl_Filter_TD_9340820_output.allocateHost();
    Table tbl_Filter_TD_9841153_output("tbl_Filter_TD_9841153_output", 6100000, 2, "");
    tbl_Filter_TD_9841153_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10510131_input;
    tbl_SerializeFromObject_TD_10510131_input = Table("web_sales", web_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10510131_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10510131_input.addCol("ws_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_10510131_input.allocateHost();
    tbl_SerializeFromObject_TD_10510131_input.loadHost();
    Table tbl_SerializeFromObject_TD_10396147_input;
    tbl_SerializeFromObject_TD_10396147_input = Table("catalog_sales", catalog_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10396147_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10396147_input.addCol("cs_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_10396147_input.allocateHost();
    tbl_SerializeFromObject_TD_10396147_input.loadHost();
    Table tbl_SerializeFromObject_TD_10802478_input;
    tbl_SerializeFromObject_TD_10802478_input = Table("web_sales", web_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10802478_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10802478_input.addCol("ws_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_10802478_input.allocateHost();
    tbl_SerializeFromObject_TD_10802478_input.loadHost();
    Table tbl_SerializeFromObject_TD_10238307_input;
    tbl_SerializeFromObject_TD_10238307_input = Table("catalog_sales", catalog_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10238307_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10238307_input.addCol("cs_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_10238307_input.allocateHost();
    tbl_SerializeFromObject_TD_10238307_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_9_393275_s, tv_r_Filter_9_393275_e;
    gettimeofday(&tv_r_Filter_9_393275_s, 0);
    SW_Filter_TD_9841153(tbl_SerializeFromObject_TD_10238307_input, tbl_Filter_TD_9841153_output);
    gettimeofday(&tv_r_Filter_9_393275_e, 0);

    struct timeval tv_r_Filter_9_784930_s, tv_r_Filter_9_784930_e;
    gettimeofday(&tv_r_Filter_9_784930_s, 0);
    SW_Filter_TD_9340820(tbl_SerializeFromObject_TD_10802478_input, tbl_Filter_TD_9340820_output);
    gettimeofday(&tv_r_Filter_9_784930_e, 0);

    struct timeval tv_r_Filter_9_147418_s, tv_r_Filter_9_147418_e;
    gettimeofday(&tv_r_Filter_9_147418_s, 0);
    SW_Filter_TD_9871123(tbl_SerializeFromObject_TD_10396147_input, tbl_Filter_TD_9871123_output);
    gettimeofday(&tv_r_Filter_9_147418_e, 0);

    struct timeval tv_r_Filter_9_194386_s, tv_r_Filter_9_194386_e;
    gettimeofday(&tv_r_Filter_9_194386_s, 0);
    SW_Filter_TD_9501449(tbl_SerializeFromObject_TD_10510131_input, tbl_Filter_TD_9501449_output);
    gettimeofday(&tv_r_Filter_9_194386_e, 0);

    struct timeval tv_r_Project_8_202940_s, tv_r_Project_8_202940_e;
    gettimeofday(&tv_r_Project_8_202940_s, 0);
    SW_Project_TD_8854524(tbl_Filter_TD_9841153_output, tbl_Project_TD_8854524_output);
    gettimeofday(&tv_r_Project_8_202940_e, 0);

    struct timeval tv_r_Project_8_773370_s, tv_r_Project_8_773370_e;
    gettimeofday(&tv_r_Project_8_773370_s, 0);
    SW_Project_TD_8396090(tbl_Filter_TD_9340820_output, tbl_Project_TD_8396090_output);
    gettimeofday(&tv_r_Project_8_773370_e, 0);

    struct timeval tv_r_Project_8_884849_s, tv_r_Project_8_884849_e;
    gettimeofday(&tv_r_Project_8_884849_s, 0);
    SW_Project_TD_8411917(tbl_Filter_TD_9871123_output, tbl_Project_TD_8411917_output);
    gettimeofday(&tv_r_Project_8_884849_e, 0);

    struct timeval tv_r_Project_8_345512_s, tv_r_Project_8_345512_e;
    gettimeofday(&tv_r_Project_8_345512_s, 0);
    SW_Project_TD_880677(tbl_Filter_TD_9501449_output, tbl_Project_TD_880677_output);
    gettimeofday(&tv_r_Project_8_345512_e, 0);

    struct timeval tv_r_Filter_7_390168_s, tv_r_Filter_7_390168_e;
    gettimeofday(&tv_r_Filter_7_390168_s, 0);
    SW_Filter_TD_7666715(tbl_SerializeFromObject_TD_8177967_input, tbl_Filter_TD_7666715_output);
    gettimeofday(&tv_r_Filter_7_390168_e, 0);

    struct timeval tv_r_Union_7_96270_s, tv_r_Union_7_96270_e;
    gettimeofday(&tv_r_Union_7_96270_s, 0);
    SW_Union_TD_728800(tbl_Project_TD_8396090_output, tbl_Project_TD_8854524_output, tbl_Union_TD_728800_output);
    gettimeofday(&tv_r_Union_7_96270_e, 0);

    struct timeval tv_r_Filter_7_949113_s, tv_r_Filter_7_949113_e;
    gettimeofday(&tv_r_Filter_7_949113_s, 0);
    SW_Filter_TD_7212909(tbl_SerializeFromObject_TD_874855_input, tbl_Filter_TD_7212909_output);
    gettimeofday(&tv_r_Filter_7_949113_e, 0);

    struct timeval tv_r_Union_7_870876_s, tv_r_Union_7_870876_e;
    gettimeofday(&tv_r_Union_7_870876_s, 0);
    SW_Union_TD_7159974(tbl_Project_TD_880677_output, tbl_Project_TD_8411917_output, tbl_Union_TD_7159974_output);
    gettimeofday(&tv_r_Union_7_870876_e, 0);

    struct timeval tv_r_JOIN_INNER_6_828800_s, tv_r_JOIN_INNER_6_828800_e;
    gettimeofday(&tv_r_JOIN_INNER_6_828800_s, 0);
    SW_JOIN_INNER_TD_6479048(tbl_Union_TD_728800_output, tbl_Filter_TD_7666715_output, tbl_JOIN_INNER_TD_6479048_output);
    gettimeofday(&tv_r_JOIN_INNER_6_828800_e, 0);

    struct timeval tv_r_JOIN_INNER_6_381532_s, tv_r_JOIN_INNER_6_381532_e;
    gettimeofday(&tv_r_JOIN_INNER_6_381532_s, 0);
    SW_JOIN_INNER_TD_6614106(tbl_Union_TD_7159974_output, tbl_Filter_TD_7212909_output, tbl_JOIN_INNER_TD_6614106_output);
    gettimeofday(&tv_r_JOIN_INNER_6_381532_e, 0);

    struct timeval tv_r_Filter_5_154927_s, tv_r_Filter_5_154927_e;
    gettimeofday(&tv_r_Filter_5_154927_s, 0);
    SW_Filter_TD_5146130(tbl_SerializeFromObject_TD_693662_input, tbl_Filter_TD_5146130_output);
    gettimeofday(&tv_r_Filter_5_154927_e, 0);

    struct timeval tv_r_Aggregate_5_611429_s, tv_r_Aggregate_5_611429_e;
    gettimeofday(&tv_r_Aggregate_5_611429_s, 0);
    SW_Aggregate_TD_5941078(tbl_JOIN_INNER_TD_6479048_output, tbl_Aggregate_TD_5941078_output);
    gettimeofday(&tv_r_Aggregate_5_611429_e, 0);

    struct timeval tv_r_Filter_5_763264_s, tv_r_Filter_5_763264_e;
    gettimeofday(&tv_r_Filter_5_763264_s, 0);
    SW_Filter_TD_5955066(tbl_SerializeFromObject_TD_6582006_input, tbl_Filter_TD_5955066_output);
    gettimeofday(&tv_r_Filter_5_763264_e, 0);

    struct timeval tv_r_Aggregate_5_723645_s, tv_r_Aggregate_5_723645_e;
    gettimeofday(&tv_r_Aggregate_5_723645_s, 0);
    SW_Aggregate_TD_5928393(tbl_JOIN_INNER_TD_6614106_output, tbl_Aggregate_TD_5928393_output);
    gettimeofday(&tv_r_Aggregate_5_723645_e, 0);

    struct timeval tv_r_JOIN_INNER_4_598405_s, tv_r_JOIN_INNER_4_598405_e;
    gettimeofday(&tv_r_JOIN_INNER_4_598405_s, 0);
    SW_JOIN_INNER_TD_4804647(tbl_Aggregate_TD_5941078_output, tbl_Filter_TD_5146130_output, tbl_JOIN_INNER_TD_4804647_output);
    gettimeofday(&tv_r_JOIN_INNER_4_598405_e, 0);

    struct timeval tv_r_JOIN_INNER_4_993457_s, tv_r_JOIN_INNER_4_993457_e;
    gettimeofday(&tv_r_JOIN_INNER_4_993457_s, 0);
    SW_JOIN_INNER_TD_4970008(tbl_Aggregate_TD_5928393_output, tbl_Filter_TD_5955066_output, tbl_JOIN_INNER_TD_4970008_output);
    gettimeofday(&tv_r_JOIN_INNER_4_993457_e, 0);

    struct timeval tv_r_Project_3_122879_s, tv_r_Project_3_122879_e;
    gettimeofday(&tv_r_Project_3_122879_s, 0);
    SW_Project_TD_3531034(tbl_JOIN_INNER_TD_4804647_output, tbl_Project_TD_3531034_output);
    gettimeofday(&tv_r_Project_3_122879_e, 0);

    struct timeval tv_r_Project_3_867400_s, tv_r_Project_3_867400_e;
    gettimeofday(&tv_r_Project_3_867400_s, 0);
    SW_Project_TD_3759542(tbl_JOIN_INNER_TD_4970008_output, tbl_Project_TD_3759542_output);
    gettimeofday(&tv_r_Project_3_867400_e, 0);

    struct timeval tv_r_JOIN_INNER_2_194617_s, tv_r_JOIN_INNER_2_194617_e;
    gettimeofday(&tv_r_JOIN_INNER_2_194617_s, 0);
    SW_JOIN_INNER_TD_2353970(tbl_Project_TD_3759542_output, tbl_Project_TD_3531034_output, tbl_JOIN_INNER_TD_2353970_output);
    gettimeofday(&tv_r_JOIN_INNER_2_194617_e, 0);

    struct timeval tv_r_Project_1_551443_s, tv_r_Project_1_551443_e;
    gettimeofday(&tv_r_Project_1_551443_s, 0);
    SW_Project_TD_1645820(tbl_JOIN_INNER_TD_2353970_output, tbl_Project_TD_1645820_output);
    gettimeofday(&tv_r_Project_1_551443_e, 0);

    struct timeval tv_r_Sort_0_577637_s, tv_r_Sort_0_577637_e;
    gettimeofday(&tv_r_Sort_0_577637_s, 0);
    SW_Sort_TD_0638674(tbl_Project_TD_1645820_output, tbl_Sort_TD_0638674_output);
    gettimeofday(&tv_r_Sort_0_577637_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_393275_s, &tv_r_Filter_9_393275_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10238307_input: " << tbl_SerializeFromObject_TD_10238307_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_784930_s, &tv_r_Filter_9_784930_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10802478_input: " << tbl_SerializeFromObject_TD_10802478_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_147418_s, &tv_r_Filter_9_147418_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10396147_input: " << tbl_SerializeFromObject_TD_10396147_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_194386_s, &tv_r_Filter_9_194386_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10510131_input: " << tbl_SerializeFromObject_TD_10510131_input.getNumRow() << " " << std::endl; 

    std::cout << "Project_8: " << tvdiff(&tv_r_Project_8_202940_s, &tv_r_Project_8_202940_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9841153_output: " << tbl_Filter_TD_9841153_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_8: " << tvdiff(&tv_r_Project_8_773370_s, &tv_r_Project_8_773370_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9340820_output: " << tbl_Filter_TD_9340820_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_8: " << tvdiff(&tv_r_Project_8_884849_s, &tv_r_Project_8_884849_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9871123_output: " << tbl_Filter_TD_9871123_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_8: " << tvdiff(&tv_r_Project_8_345512_s, &tv_r_Project_8_345512_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9501449_output: " << tbl_Filter_TD_9501449_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_390168_s, &tv_r_Filter_7_390168_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8177967_input: " << tbl_SerializeFromObject_TD_8177967_input.getNumRow() << " " << std::endl; 

    std::cout << "Union_7: " << tvdiff(&tv_r_Union_7_96270_s, &tv_r_Union_7_96270_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_8396090_output: " << tbl_Project_TD_8396090_output.getNumRow() << " " << "tbl_Project_TD_8854524_output: " << tbl_Project_TD_8854524_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_949113_s, &tv_r_Filter_7_949113_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_874855_input: " << tbl_SerializeFromObject_TD_874855_input.getNumRow() << " " << std::endl; 

    std::cout << "Union_7: " << tvdiff(&tv_r_Union_7_870876_s, &tv_r_Union_7_870876_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_880677_output: " << tbl_Project_TD_880677_output.getNumRow() << " " << "tbl_Project_TD_8411917_output: " << tbl_Project_TD_8411917_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_828800_s, &tv_r_JOIN_INNER_6_828800_e) / 1000.0 << " ms " 
     << "tbl_Union_TD_728800_output: " << tbl_Union_TD_728800_output.getNumRow() << " " << "tbl_Filter_TD_7666715_output: " << tbl_Filter_TD_7666715_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_381532_s, &tv_r_JOIN_INNER_6_381532_e) / 1000.0 << " ms " 
     << "tbl_Union_TD_7159974_output: " << tbl_Union_TD_7159974_output.getNumRow() << " " << "tbl_Filter_TD_7212909_output: " << tbl_Filter_TD_7212909_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_154927_s, &tv_r_Filter_5_154927_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_693662_input: " << tbl_SerializeFromObject_TD_693662_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_611429_s, &tv_r_Aggregate_5_611429_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6479048_output: " << tbl_JOIN_INNER_TD_6479048_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_763264_s, &tv_r_Filter_5_763264_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6582006_input: " << tbl_SerializeFromObject_TD_6582006_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_723645_s, &tv_r_Aggregate_5_723645_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6614106_output: " << tbl_JOIN_INNER_TD_6614106_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_598405_s, &tv_r_JOIN_INNER_4_598405_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_5941078_output: " << tbl_Aggregate_TD_5941078_output.getNumRow() << " " << "tbl_Filter_TD_5146130_output: " << tbl_Filter_TD_5146130_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_993457_s, &tv_r_JOIN_INNER_4_993457_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_5928393_output: " << tbl_Aggregate_TD_5928393_output.getNumRow() << " " << "tbl_Filter_TD_5955066_output: " << tbl_Filter_TD_5955066_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_3: " << tvdiff(&tv_r_Project_3_122879_s, &tv_r_Project_3_122879_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4804647_output: " << tbl_JOIN_INNER_TD_4804647_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_3: " << tvdiff(&tv_r_Project_3_867400_s, &tv_r_Project_3_867400_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4970008_output: " << tbl_JOIN_INNER_TD_4970008_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_2: " << tvdiff(&tv_r_JOIN_INNER_2_194617_s, &tv_r_JOIN_INNER_2_194617_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_3759542_output: " << tbl_Project_TD_3759542_output.getNumRow() << " " << "tbl_Project_TD_3531034_output: " << tbl_Project_TD_3531034_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_1: " << tvdiff(&tv_r_Project_1_551443_s, &tv_r_Project_1_551443_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_2353970_output: " << tbl_JOIN_INNER_TD_2353970_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_577637_s, &tv_r_Sort_0_577637_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_1645820_output: " << tbl_Project_TD_1645820_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.349268 * 1000 << "ms" << std::endl; 
    return 0; 
}
