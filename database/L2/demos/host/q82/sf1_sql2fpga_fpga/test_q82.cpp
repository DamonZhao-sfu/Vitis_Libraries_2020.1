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

#include "cfgFunc_q82.hpp" 
#include "q82.hpp" 

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
    std::cout << "NOTE:running query #82\n."; 
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
    Table tbl_GlobalLimit_TD_0267483_output("tbl_GlobalLimit_TD_0267483_output", 6100000, 3, "");
    tbl_GlobalLimit_TD_0267483_output.allocateHost();
    Table tbl_LocalLimit_TD_1461457_output("tbl_LocalLimit_TD_1461457_output", 6100000, 3, "");
    tbl_LocalLimit_TD_1461457_output.allocateHost();
    Table tbl_Sort_TD_2302450_output("tbl_Sort_TD_2302450_output", 6100000, 3, "");
    tbl_Sort_TD_2302450_output.allocateHost();
    Table tbl_Aggregate_TD_3716190_output("tbl_Aggregate_TD_3716190_output", 6100000, 3, "");
    tbl_Aggregate_TD_3716190_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4106646_output("tbl_JOIN_INNER_TD_4106646_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_4106646_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5821750_output("tbl_JOIN_INNER_TD_5821750_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_5821750_output.allocateHost();
    Table tbl_Filter_TD_5734335_output("tbl_Filter_TD_5734335_output", 6100000, 1, "");
    tbl_Filter_TD_5734335_output.allocateHost();
    Table tbl_JOIN_INNER_TD_627839_output("tbl_JOIN_INNER_TD_627839_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_627839_output.allocateHost();
    Table tbl_Filter_TD_6971540_output("tbl_Filter_TD_6971540_output", 6100000, 1, "");
    tbl_Filter_TD_6971540_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6240181_input;
    tbl_SerializeFromObject_TD_6240181_input = Table("store_sales", store_sales_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_6240181_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_6240181_input.allocateHost();
    tbl_SerializeFromObject_TD_6240181_input.loadHost();
    Table tbl_Filter_TD_713861_output("tbl_Filter_TD_713861_output", 6100000, 4, "");
    tbl_Filter_TD_713861_output.allocateHost();
    Table tbl_Filter_TD_7656596_output("tbl_Filter_TD_7656596_output", 6100000, 2, "");
    tbl_Filter_TD_7656596_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7496951_input;
    tbl_SerializeFromObject_TD_7496951_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7496951_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_7496951_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_7496951_input.allocateHost();
    tbl_SerializeFromObject_TD_7496951_input.loadHost();
    Table tbl_SerializeFromObject_TD_8919781_input;
    tbl_SerializeFromObject_TD_8919781_input = Table("item", item_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_8919781_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_8919781_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8919781_input.addCol("i_item_desc", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8919781_input.addCol("i_current_price", 4);
    tbl_SerializeFromObject_TD_8919781_input.addCol("i_manufact_id", 4);
    tbl_SerializeFromObject_TD_8919781_input.allocateHost();
    tbl_SerializeFromObject_TD_8919781_input.loadHost();
    Table tbl_SerializeFromObject_TD_849963_input;
    tbl_SerializeFromObject_TD_849963_input = Table("inventory", inventory_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_849963_input.addCol("inv_date_sk", 4);
    tbl_SerializeFromObject_TD_849963_input.addCol("inv_item_sk", 4);
    tbl_SerializeFromObject_TD_849963_input.addCol("inv_quantity_on_hand", 4);
    tbl_SerializeFromObject_TD_849963_input.allocateHost();
    tbl_SerializeFromObject_TD_849963_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_7_379796_s, tv_r_Filter_7_379796_e;
    gettimeofday(&tv_r_Filter_7_379796_s, 0);
    SW_Filter_TD_7656596(tbl_SerializeFromObject_TD_849963_input, tbl_Filter_TD_7656596_output);
    gettimeofday(&tv_r_Filter_7_379796_e, 0);

    struct timeval tv_r_Filter_7_616408_s, tv_r_Filter_7_616408_e;
    gettimeofday(&tv_r_Filter_7_616408_s, 0);
    SW_Filter_TD_713861(tbl_SerializeFromObject_TD_8919781_input, tbl_Filter_TD_713861_output);
    gettimeofday(&tv_r_Filter_7_616408_e, 0);

    struct timeval tv_r_Filter_6_459982_s, tv_r_Filter_6_459982_e;
    gettimeofday(&tv_r_Filter_6_459982_s, 0);
    SW_Filter_TD_6971540(tbl_SerializeFromObject_TD_7496951_input, tbl_Filter_TD_6971540_output);
    gettimeofday(&tv_r_Filter_6_459982_e, 0);

    struct timeval tv_r_JOIN_INNER_6_734915_s, tv_r_JOIN_INNER_6_734915_e;
    gettimeofday(&tv_r_JOIN_INNER_6_734915_s, 0);
    SW_JOIN_INNER_TD_627839(tbl_Filter_TD_713861_output, tbl_Filter_TD_7656596_output, tbl_JOIN_INNER_TD_627839_output);
    gettimeofday(&tv_r_JOIN_INNER_6_734915_e, 0);

    struct timeval tv_r_Filter_5_518250_s, tv_r_Filter_5_518250_e;
    gettimeofday(&tv_r_Filter_5_518250_s, 0);
    SW_Filter_TD_5734335(tbl_SerializeFromObject_TD_6240181_input, tbl_Filter_TD_5734335_output);
    gettimeofday(&tv_r_Filter_5_518250_e, 0);

    struct timeval tv_r_JOIN_INNER_5_486016_s, tv_r_JOIN_INNER_5_486016_e;
    gettimeofday(&tv_r_JOIN_INNER_5_486016_s, 0);
    SW_JOIN_INNER_TD_5821750(tbl_JOIN_INNER_TD_627839_output, tbl_Filter_TD_6971540_output, tbl_JOIN_INNER_TD_5821750_output);
    gettimeofday(&tv_r_JOIN_INNER_5_486016_e, 0);

    struct timeval tv_r_JOIN_INNER_4_817848_s, tv_r_JOIN_INNER_4_817848_e;
    gettimeofday(&tv_r_JOIN_INNER_4_817848_s, 0);
    SW_JOIN_INNER_TD_4106646(tbl_JOIN_INNER_TD_5821750_output, tbl_Filter_TD_5734335_output, tbl_JOIN_INNER_TD_4106646_output);
    gettimeofday(&tv_r_JOIN_INNER_4_817848_e, 0);

    struct timeval tv_r_Aggregate_3_628211_s, tv_r_Aggregate_3_628211_e;
    gettimeofday(&tv_r_Aggregate_3_628211_s, 0);
    SW_Aggregate_TD_3716190(tbl_JOIN_INNER_TD_4106646_output, tbl_Aggregate_TD_3716190_output);
    gettimeofday(&tv_r_Aggregate_3_628211_e, 0);

    struct timeval tv_r_Sort_2_149340_s, tv_r_Sort_2_149340_e;
    gettimeofday(&tv_r_Sort_2_149340_s, 0);
    SW_Sort_TD_2302450(tbl_Aggregate_TD_3716190_output, tbl_Sort_TD_2302450_output);
    gettimeofday(&tv_r_Sort_2_149340_e, 0);

    struct timeval tv_r_LocalLimit_1_635039_s, tv_r_LocalLimit_1_635039_e;
    gettimeofday(&tv_r_LocalLimit_1_635039_s, 0);
    SW_LocalLimit_TD_1461457(tbl_Sort_TD_2302450_output, tbl_LocalLimit_TD_1461457_output);
    gettimeofday(&tv_r_LocalLimit_1_635039_e, 0);

    struct timeval tv_r_GlobalLimit_0_830706_s, tv_r_GlobalLimit_0_830706_e;
    gettimeofday(&tv_r_GlobalLimit_0_830706_s, 0);
    SW_GlobalLimit_TD_0267483(tbl_LocalLimit_TD_1461457_output, tbl_GlobalLimit_TD_0267483_output);
    gettimeofday(&tv_r_GlobalLimit_0_830706_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_379796_s, &tv_r_Filter_7_379796_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_849963_input: " << tbl_SerializeFromObject_TD_849963_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_616408_s, &tv_r_Filter_7_616408_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8919781_input: " << tbl_SerializeFromObject_TD_8919781_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_459982_s, &tv_r_Filter_6_459982_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7496951_input: " << tbl_SerializeFromObject_TD_7496951_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_734915_s, &tv_r_JOIN_INNER_6_734915_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_713861_output: " << tbl_Filter_TD_713861_output.getNumRow() << " " << "tbl_Filter_TD_7656596_output: " << tbl_Filter_TD_7656596_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_518250_s, &tv_r_Filter_5_518250_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6240181_input: " << tbl_SerializeFromObject_TD_6240181_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_486016_s, &tv_r_JOIN_INNER_5_486016_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_627839_output: " << tbl_JOIN_INNER_TD_627839_output.getNumRow() << " " << "tbl_Filter_TD_6971540_output: " << tbl_Filter_TD_6971540_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_817848_s, &tv_r_JOIN_INNER_4_817848_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5821750_output: " << tbl_JOIN_INNER_TD_5821750_output.getNumRow() << " " << "tbl_Filter_TD_5734335_output: " << tbl_Filter_TD_5734335_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_628211_s, &tv_r_Aggregate_3_628211_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4106646_output: " << tbl_JOIN_INNER_TD_4106646_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_149340_s, &tv_r_Sort_2_149340_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3716190_output: " << tbl_Aggregate_TD_3716190_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_635039_s, &tv_r_LocalLimit_1_635039_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2302450_output: " << tbl_Sort_TD_2302450_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_830706_s, &tv_r_GlobalLimit_0_830706_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1461457_output: " << tbl_LocalLimit_TD_1461457_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 3.6563945 * 1000 << "ms" << std::endl; 
    return 0; 
}
