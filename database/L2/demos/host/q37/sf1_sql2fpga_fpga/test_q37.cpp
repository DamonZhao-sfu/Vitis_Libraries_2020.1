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

#include "cfgFunc_q37.hpp" 
#include "q37.hpp" 

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
    std::cout << "NOTE:running query #37\n."; 
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
    Table tbl_GlobalLimit_TD_0649744_output("tbl_GlobalLimit_TD_0649744_output", 6100000, 2, "");
    tbl_GlobalLimit_TD_0649744_output.allocateHost();
    Table tbl_LocalLimit_TD_1977096_output("tbl_LocalLimit_TD_1977096_output", 6100000, 2, "");
    tbl_LocalLimit_TD_1977096_output.allocateHost();
    Table tbl_Sort_TD_2354622_output("tbl_Sort_TD_2354622_output", 6100000, 2, "");
    tbl_Sort_TD_2354622_output.allocateHost();
    Table tbl_Aggregate_TD_3668708_output("tbl_Aggregate_TD_3668708_output", 6100000, 2, "");
    tbl_Aggregate_TD_3668708_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4659468_output("tbl_JOIN_INNER_TD_4659468_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_4659468_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5257295_output("tbl_JOIN_INNER_TD_5257295_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_5257295_output.allocateHost();
    Table tbl_Filter_TD_5736170_output("tbl_Filter_TD_5736170_output", 6100000, 1, "");
    tbl_Filter_TD_5736170_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6382831_output("tbl_JOIN_INNER_TD_6382831_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_6382831_output.allocateHost();
    Table tbl_Filter_TD_6515285_output("tbl_Filter_TD_6515285_output", 6100000, 1, "");
    tbl_Filter_TD_6515285_output.allocateHost();
    Table tbl_SerializeFromObject_TD_64767_input;
    tbl_SerializeFromObject_TD_64767_input = Table("catalog_sales", catalog_sales_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_64767_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_64767_input.allocateHost();
    tbl_SerializeFromObject_TD_64767_input.loadHost();
    Table tbl_Filter_TD_7889765_output("tbl_Filter_TD_7889765_output", 6100000, 3, "");
    tbl_Filter_TD_7889765_output.allocateHost();
    Table tbl_Filter_TD_7262490_output("tbl_Filter_TD_7262490_output", 6100000, 2, "");
    tbl_Filter_TD_7262490_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7760315_input;
    tbl_SerializeFromObject_TD_7760315_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7760315_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_7760315_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_7760315_input.allocateHost();
    tbl_SerializeFromObject_TD_7760315_input.loadHost();
    Table tbl_SerializeFromObject_TD_8334515_input;
    tbl_SerializeFromObject_TD_8334515_input = Table("item", item_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_8334515_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_8334515_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8334515_input.addCol("i_item_desc", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8334515_input.addCol("i_manufact_id", 4);
    tbl_SerializeFromObject_TD_8334515_input.allocateHost();
    tbl_SerializeFromObject_TD_8334515_input.loadHost();
    Table tbl_SerializeFromObject_TD_8345509_input;
    tbl_SerializeFromObject_TD_8345509_input = Table("inventory", inventory_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8345509_input.addCol("inv_date_sk", 4);
    tbl_SerializeFromObject_TD_8345509_input.addCol("inv_item_sk", 4);
    tbl_SerializeFromObject_TD_8345509_input.addCol("inv_quantity_on_hand", 4);
    tbl_SerializeFromObject_TD_8345509_input.allocateHost();
    tbl_SerializeFromObject_TD_8345509_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_7_675440_s, tv_r_Filter_7_675440_e;
    gettimeofday(&tv_r_Filter_7_675440_s, 0);
    SW_Filter_TD_7262490(tbl_SerializeFromObject_TD_8345509_input, tbl_Filter_TD_7262490_output);
    gettimeofday(&tv_r_Filter_7_675440_e, 0);

    struct timeval tv_r_Filter_7_513486_s, tv_r_Filter_7_513486_e;
    gettimeofday(&tv_r_Filter_7_513486_s, 0);
    SW_Filter_TD_7889765(tbl_SerializeFromObject_TD_8334515_input, tbl_Filter_TD_7889765_output);
    gettimeofday(&tv_r_Filter_7_513486_e, 0);

    struct timeval tv_r_Filter_6_724192_s, tv_r_Filter_6_724192_e;
    gettimeofday(&tv_r_Filter_6_724192_s, 0);
    SW_Filter_TD_6515285(tbl_SerializeFromObject_TD_7760315_input, tbl_Filter_TD_6515285_output);
    gettimeofday(&tv_r_Filter_6_724192_e, 0);

    struct timeval tv_r_JOIN_INNER_6_800942_s, tv_r_JOIN_INNER_6_800942_e;
    gettimeofday(&tv_r_JOIN_INNER_6_800942_s, 0);
    SW_JOIN_INNER_TD_6382831(tbl_Filter_TD_7889765_output, tbl_Filter_TD_7262490_output, tbl_JOIN_INNER_TD_6382831_output);
    gettimeofday(&tv_r_JOIN_INNER_6_800942_e, 0);

    struct timeval tv_r_Filter_5_135097_s, tv_r_Filter_5_135097_e;
    gettimeofday(&tv_r_Filter_5_135097_s, 0);
    SW_Filter_TD_5736170(tbl_SerializeFromObject_TD_64767_input, tbl_Filter_TD_5736170_output);
    gettimeofday(&tv_r_Filter_5_135097_e, 0);

    struct timeval tv_r_JOIN_INNER_5_558251_s, tv_r_JOIN_INNER_5_558251_e;
    gettimeofday(&tv_r_JOIN_INNER_5_558251_s, 0);
    SW_JOIN_INNER_TD_5257295(tbl_JOIN_INNER_TD_6382831_output, tbl_Filter_TD_6515285_output, tbl_JOIN_INNER_TD_5257295_output);
    gettimeofday(&tv_r_JOIN_INNER_5_558251_e, 0);

    struct timeval tv_r_JOIN_INNER_4_670940_s, tv_r_JOIN_INNER_4_670940_e;
    gettimeofday(&tv_r_JOIN_INNER_4_670940_s, 0);
    SW_JOIN_INNER_TD_4659468(tbl_JOIN_INNER_TD_5257295_output, tbl_Filter_TD_5736170_output, tbl_JOIN_INNER_TD_4659468_output);
    gettimeofday(&tv_r_JOIN_INNER_4_670940_e, 0);

    struct timeval tv_r_Aggregate_3_313706_s, tv_r_Aggregate_3_313706_e;
    gettimeofday(&tv_r_Aggregate_3_313706_s, 0);
    SW_Aggregate_TD_3668708(tbl_JOIN_INNER_TD_4659468_output, tbl_Aggregate_TD_3668708_output);
    gettimeofday(&tv_r_Aggregate_3_313706_e, 0);

    struct timeval tv_r_Sort_2_515071_s, tv_r_Sort_2_515071_e;
    gettimeofday(&tv_r_Sort_2_515071_s, 0);
    SW_Sort_TD_2354622(tbl_Aggregate_TD_3668708_output, tbl_Sort_TD_2354622_output);
    gettimeofday(&tv_r_Sort_2_515071_e, 0);

    struct timeval tv_r_LocalLimit_1_240141_s, tv_r_LocalLimit_1_240141_e;
    gettimeofday(&tv_r_LocalLimit_1_240141_s, 0);
    SW_LocalLimit_TD_1977096(tbl_Sort_TD_2354622_output, tbl_LocalLimit_TD_1977096_output);
    gettimeofday(&tv_r_LocalLimit_1_240141_e, 0);

    struct timeval tv_r_GlobalLimit_0_574691_s, tv_r_GlobalLimit_0_574691_e;
    gettimeofday(&tv_r_GlobalLimit_0_574691_s, 0);
    SW_GlobalLimit_TD_0649744(tbl_LocalLimit_TD_1977096_output, tbl_GlobalLimit_TD_0649744_output);
    gettimeofday(&tv_r_GlobalLimit_0_574691_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_675440_s, &tv_r_Filter_7_675440_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8345509_input: " << tbl_SerializeFromObject_TD_8345509_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_513486_s, &tv_r_Filter_7_513486_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8334515_input: " << tbl_SerializeFromObject_TD_8334515_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_724192_s, &tv_r_Filter_6_724192_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7760315_input: " << tbl_SerializeFromObject_TD_7760315_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_800942_s, &tv_r_JOIN_INNER_6_800942_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_7889765_output: " << tbl_Filter_TD_7889765_output.getNumRow() << " " << "tbl_Filter_TD_7262490_output: " << tbl_Filter_TD_7262490_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_135097_s, &tv_r_Filter_5_135097_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_64767_input: " << tbl_SerializeFromObject_TD_64767_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_558251_s, &tv_r_JOIN_INNER_5_558251_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6382831_output: " << tbl_JOIN_INNER_TD_6382831_output.getNumRow() << " " << "tbl_Filter_TD_6515285_output: " << tbl_Filter_TD_6515285_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_670940_s, &tv_r_JOIN_INNER_4_670940_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5257295_output: " << tbl_JOIN_INNER_TD_5257295_output.getNumRow() << " " << "tbl_Filter_TD_5736170_output: " << tbl_Filter_TD_5736170_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_313706_s, &tv_r_Aggregate_3_313706_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4659468_output: " << tbl_JOIN_INNER_TD_4659468_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_515071_s, &tv_r_Sort_2_515071_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3668708_output: " << tbl_Aggregate_TD_3668708_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_240141_s, &tv_r_LocalLimit_1_240141_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2354622_output: " << tbl_Sort_TD_2354622_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_574691_s, &tv_r_GlobalLimit_0_574691_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1977096_output: " << tbl_LocalLimit_TD_1977096_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.4256818 * 1000 << "ms" << std::endl; 
    return 0; 
}
