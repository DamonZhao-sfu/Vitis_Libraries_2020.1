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

#include "cfgFunc_q26.hpp" 
#include "q26.hpp" 

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
    std::cout << "NOTE:running query #26\n."; 
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
    Table tbl_GlobalLimit_TD_0222110_output("tbl_GlobalLimit_TD_0222110_output", 6100000, 5, "");
    tbl_GlobalLimit_TD_0222110_output.allocateHost();
    Table tbl_LocalLimit_TD_1892022_output("tbl_LocalLimit_TD_1892022_output", 6100000, 5, "");
    tbl_LocalLimit_TD_1892022_output.allocateHost();
    Table tbl_Sort_TD_2221668_output("tbl_Sort_TD_2221668_output", 6100000, 5, "");
    tbl_Sort_TD_2221668_output.allocateHost();
    Table tbl_Aggregate_TD_393241_output("tbl_Aggregate_TD_393241_output", 6100000, 5, "");
    tbl_Aggregate_TD_393241_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4693748_output("tbl_JOIN_INNER_TD_4693748_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_4693748_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5621689_output("tbl_JOIN_INNER_TD_5621689_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_5621689_output.allocateHost();
    Table tbl_Filter_TD_5243394_output("tbl_Filter_TD_5243394_output", 6100000, 1, "");
    tbl_Filter_TD_5243394_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6820981_output("tbl_JOIN_INNER_TD_6820981_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_6820981_output.allocateHost();
    Table tbl_Filter_TD_647048_output("tbl_Filter_TD_647048_output", 6100000, 2, "");
    tbl_Filter_TD_647048_output.allocateHost();
    Table tbl_SerializeFromObject_TD_66547_input;
    tbl_SerializeFromObject_TD_66547_input = Table("promotion", promotion_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_66547_input.addCol("p_promo_sk", 4);
    tbl_SerializeFromObject_TD_66547_input.addCol("p_channel_email", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_66547_input.addCol("p_channel_event", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_66547_input.allocateHost();
    tbl_SerializeFromObject_TD_66547_input.loadHost();
    Table tbl_JOIN_INNER_TD_7248247_output("tbl_JOIN_INNER_TD_7248247_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_7248247_output.allocateHost();
    Table tbl_Filter_TD_738942_output("tbl_Filter_TD_738942_output", 6100000, 1, "");
    tbl_Filter_TD_738942_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7377191_input;
    tbl_SerializeFromObject_TD_7377191_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7377191_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_7377191_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7377191_input.allocateHost();
    tbl_SerializeFromObject_TD_7377191_input.loadHost();
    Table tbl_Filter_TD_8376892_output("tbl_Filter_TD_8376892_output", 6100000, 8, "");
    tbl_Filter_TD_8376892_output.allocateHost();
    Table tbl_Filter_TD_8949382_output("tbl_Filter_TD_8949382_output", 6100000, 1, "");
    tbl_Filter_TD_8949382_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8494840_input;
    tbl_SerializeFromObject_TD_8494840_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8494840_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_8494840_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_8494840_input.allocateHost();
    tbl_SerializeFromObject_TD_8494840_input.loadHost();
    Table tbl_SerializeFromObject_TD_9974861_input;
    tbl_SerializeFromObject_TD_9974861_input = Table("catalog_sales", catalog_sales_n, 8, in_dir, "orc");
    tbl_SerializeFromObject_TD_9974861_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_9974861_input.addCol("cs_bill_cdemo_sk", 4);
    tbl_SerializeFromObject_TD_9974861_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_9974861_input.addCol("cs_promo_sk", 4);
    tbl_SerializeFromObject_TD_9974861_input.addCol("cs_quantity", 4);
    tbl_SerializeFromObject_TD_9974861_input.addCol("cs_list_price", 4);
    tbl_SerializeFromObject_TD_9974861_input.addCol("cs_sales_price", 4);
    tbl_SerializeFromObject_TD_9974861_input.addCol("cs_coupon_amt", 4);
    tbl_SerializeFromObject_TD_9974861_input.allocateHost();
    tbl_SerializeFromObject_TD_9974861_input.loadHost();
    Table tbl_SerializeFromObject_TD_9787079_input;
    tbl_SerializeFromObject_TD_9787079_input = Table("customer_demographics", customer_demographics_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_9787079_input.addCol("cd_demo_sk", 4);
    tbl_SerializeFromObject_TD_9787079_input.addCol("cd_gender", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9787079_input.addCol("cd_marital_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9787079_input.addCol("cd_education_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9787079_input.allocateHost();
    tbl_SerializeFromObject_TD_9787079_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_8_863471_s, tv_r_Filter_8_863471_e;
    gettimeofday(&tv_r_Filter_8_863471_s, 0);
    SW_Filter_TD_8949382(tbl_SerializeFromObject_TD_9787079_input, tbl_Filter_TD_8949382_output);
    gettimeofday(&tv_r_Filter_8_863471_e, 0);

    struct timeval tv_r_Filter_8_926332_s, tv_r_Filter_8_926332_e;
    gettimeofday(&tv_r_Filter_8_926332_s, 0);
    SW_Filter_TD_8376892(tbl_SerializeFromObject_TD_9974861_input, tbl_Filter_TD_8376892_output);
    gettimeofday(&tv_r_Filter_8_926332_e, 0);

    struct timeval tv_r_Filter_7_208051_s, tv_r_Filter_7_208051_e;
    gettimeofday(&tv_r_Filter_7_208051_s, 0);
    SW_Filter_TD_738942(tbl_SerializeFromObject_TD_8494840_input, tbl_Filter_TD_738942_output);
    gettimeofday(&tv_r_Filter_7_208051_e, 0);

    struct timeval tv_r_JOIN_INNER_7_499763_s, tv_r_JOIN_INNER_7_499763_e;
    gettimeofday(&tv_r_JOIN_INNER_7_499763_s, 0);
    SW_JOIN_INNER_TD_7248247(tbl_Filter_TD_8376892_output, tbl_Filter_TD_8949382_output, tbl_JOIN_INNER_TD_7248247_output);
    gettimeofday(&tv_r_JOIN_INNER_7_499763_e, 0);

    struct timeval tv_r_Filter_6_19755_s, tv_r_Filter_6_19755_e;
    gettimeofday(&tv_r_Filter_6_19755_s, 0);
    SW_Filter_TD_647048(tbl_SerializeFromObject_TD_7377191_input, tbl_Filter_TD_647048_output);
    gettimeofday(&tv_r_Filter_6_19755_e, 0);

    struct timeval tv_r_JOIN_INNER_6_806207_s, tv_r_JOIN_INNER_6_806207_e;
    gettimeofday(&tv_r_JOIN_INNER_6_806207_s, 0);
    SW_JOIN_INNER_TD_6820981(tbl_JOIN_INNER_TD_7248247_output, tbl_Filter_TD_738942_output, tbl_JOIN_INNER_TD_6820981_output);
    gettimeofday(&tv_r_JOIN_INNER_6_806207_e, 0);

    struct timeval tv_r_Filter_5_45258_s, tv_r_Filter_5_45258_e;
    gettimeofday(&tv_r_Filter_5_45258_s, 0);
    SW_Filter_TD_5243394(tbl_SerializeFromObject_TD_66547_input, tbl_Filter_TD_5243394_output);
    gettimeofday(&tv_r_Filter_5_45258_e, 0);

    struct timeval tv_r_JOIN_INNER_5_621821_s, tv_r_JOIN_INNER_5_621821_e;
    gettimeofday(&tv_r_JOIN_INNER_5_621821_s, 0);
    SW_JOIN_INNER_TD_5621689(tbl_JOIN_INNER_TD_6820981_output, tbl_Filter_TD_647048_output, tbl_JOIN_INNER_TD_5621689_output);
    gettimeofday(&tv_r_JOIN_INNER_5_621821_e, 0);

    struct timeval tv_r_JOIN_INNER_4_683299_s, tv_r_JOIN_INNER_4_683299_e;
    gettimeofday(&tv_r_JOIN_INNER_4_683299_s, 0);
    SW_JOIN_INNER_TD_4693748(tbl_JOIN_INNER_TD_5621689_output, tbl_Filter_TD_5243394_output, tbl_JOIN_INNER_TD_4693748_output);
    gettimeofday(&tv_r_JOIN_INNER_4_683299_e, 0);

    struct timeval tv_r_Aggregate_3_885505_s, tv_r_Aggregate_3_885505_e;
    gettimeofday(&tv_r_Aggregate_3_885505_s, 0);
    SW_Aggregate_TD_393241(tbl_JOIN_INNER_TD_4693748_output, tbl_Aggregate_TD_393241_output);
    gettimeofday(&tv_r_Aggregate_3_885505_e, 0);

    struct timeval tv_r_Sort_2_58656_s, tv_r_Sort_2_58656_e;
    gettimeofday(&tv_r_Sort_2_58656_s, 0);
    SW_Sort_TD_2221668(tbl_Aggregate_TD_393241_output, tbl_Sort_TD_2221668_output);
    gettimeofday(&tv_r_Sort_2_58656_e, 0);

    struct timeval tv_r_LocalLimit_1_437141_s, tv_r_LocalLimit_1_437141_e;
    gettimeofday(&tv_r_LocalLimit_1_437141_s, 0);
    SW_LocalLimit_TD_1892022(tbl_Sort_TD_2221668_output, tbl_LocalLimit_TD_1892022_output);
    gettimeofday(&tv_r_LocalLimit_1_437141_e, 0);

    struct timeval tv_r_GlobalLimit_0_820157_s, tv_r_GlobalLimit_0_820157_e;
    gettimeofday(&tv_r_GlobalLimit_0_820157_s, 0);
    SW_GlobalLimit_TD_0222110(tbl_LocalLimit_TD_1892022_output, tbl_GlobalLimit_TD_0222110_output);
    gettimeofday(&tv_r_GlobalLimit_0_820157_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_863471_s, &tv_r_Filter_8_863471_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9787079_input: " << tbl_SerializeFromObject_TD_9787079_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_926332_s, &tv_r_Filter_8_926332_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9974861_input: " << tbl_SerializeFromObject_TD_9974861_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_208051_s, &tv_r_Filter_7_208051_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8494840_input: " << tbl_SerializeFromObject_TD_8494840_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_499763_s, &tv_r_JOIN_INNER_7_499763_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8376892_output: " << tbl_Filter_TD_8376892_output.getNumRow() << " " << "tbl_Filter_TD_8949382_output: " << tbl_Filter_TD_8949382_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_19755_s, &tv_r_Filter_6_19755_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7377191_input: " << tbl_SerializeFromObject_TD_7377191_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_806207_s, &tv_r_JOIN_INNER_6_806207_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7248247_output: " << tbl_JOIN_INNER_TD_7248247_output.getNumRow() << " " << "tbl_Filter_TD_738942_output: " << tbl_Filter_TD_738942_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_45258_s, &tv_r_Filter_5_45258_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_66547_input: " << tbl_SerializeFromObject_TD_66547_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_621821_s, &tv_r_JOIN_INNER_5_621821_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6820981_output: " << tbl_JOIN_INNER_TD_6820981_output.getNumRow() << " " << "tbl_Filter_TD_647048_output: " << tbl_Filter_TD_647048_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_683299_s, &tv_r_JOIN_INNER_4_683299_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5621689_output: " << tbl_JOIN_INNER_TD_5621689_output.getNumRow() << " " << "tbl_Filter_TD_5243394_output: " << tbl_Filter_TD_5243394_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_885505_s, &tv_r_Aggregate_3_885505_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4693748_output: " << tbl_JOIN_INNER_TD_4693748_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_58656_s, &tv_r_Sort_2_58656_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_393241_output: " << tbl_Aggregate_TD_393241_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_437141_s, &tv_r_LocalLimit_1_437141_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2221668_output: " << tbl_Sort_TD_2221668_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_820157_s, &tv_r_GlobalLimit_0_820157_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1892022_output: " << tbl_LocalLimit_TD_1892022_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.5649676 * 1000 << "ms" << std::endl; 
    return 0; 
}
