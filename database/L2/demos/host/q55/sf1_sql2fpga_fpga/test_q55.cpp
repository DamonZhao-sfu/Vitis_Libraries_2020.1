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

#include "cfgFunc_q55.hpp" 
#include "q55.hpp" 

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
    std::cout << "NOTE:running query #55\n."; 
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
    Table tbl_GlobalLimit_TD_0498908_output("tbl_GlobalLimit_TD_0498908_output", 6100000, 3, "");
    tbl_GlobalLimit_TD_0498908_output.allocateHost();
    Table tbl_LocalLimit_TD_1482384_output("tbl_LocalLimit_TD_1482384_output", 6100000, 3, "");
    tbl_LocalLimit_TD_1482384_output.allocateHost();
    Table tbl_Sort_TD_2235772_output("tbl_Sort_TD_2235772_output", 6100000, 3, "");
    tbl_Sort_TD_2235772_output.allocateHost();
    Table tbl_Aggregate_TD_3771786_output("tbl_Aggregate_TD_3771786_output", 6100000, 3, "");
    tbl_Aggregate_TD_3771786_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4888683_output("tbl_JOIN_INNER_TD_4888683_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_4888683_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5269686_output("tbl_JOIN_INNER_TD_5269686_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_5269686_output.allocateHost();
    Table tbl_Filter_TD_5725449_output("tbl_Filter_TD_5725449_output", 6100000, 3, "");
    tbl_Filter_TD_5725449_output.allocateHost();
    Table tbl_Filter_TD_6966126_output("tbl_Filter_TD_6966126_output", 6100000, 1, "");
    tbl_Filter_TD_6966126_output.allocateHost();
    Table tbl_Filter_TD_6107427_output("tbl_Filter_TD_6107427_output", 6100000, 3, "");
    tbl_Filter_TD_6107427_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6861241_input;
    tbl_SerializeFromObject_TD_6861241_input = Table("item", item_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_6861241_input.addCol("i_item_sk", 4, 0, 1, ColumnType::INT32);
    tbl_SerializeFromObject_TD_6861241_input.addCol("i_brand_id", 4, 0, 1, ColumnType::INT32);
    tbl_SerializeFromObject_TD_6861241_input.addCol("i_brand", TPCDS_READ_MAX+1, 0, 1, ColumnType::STRING);
    tbl_SerializeFromObject_TD_6861241_input.addCol("i_manager_id", 4, 0,1 ,ColumnType::INT32);
    tbl_SerializeFromObject_TD_6861241_input.allocateHost();
    tbl_SerializeFromObject_TD_6861241_input.loadHost();
    Table tbl_SerializeFromObject_TD_7200129_input;
    tbl_SerializeFromObject_TD_7200129_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7200129_input.addCol("d_date_sk", 4, 0, 1, ColumnType::INT32);
    tbl_SerializeFromObject_TD_7200129_input.addCol("d_moy", 4, 0, 1, ColumnType::INT32);
    tbl_SerializeFromObject_TD_7200129_input.addCol("d_year", 4, 0, 1, ColumnType::INT32);
    tbl_SerializeFromObject_TD_7200129_input.allocateHost();
    tbl_SerializeFromObject_TD_7200129_input.loadHost();
    Table tbl_SerializeFromObject_TD_7969555_input;
    tbl_SerializeFromObject_TD_7969555_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7969555_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_7969555_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_7969555_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_7969555_input.allocateHost();
    tbl_SerializeFromObject_TD_7969555_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_6_157361_s, tv_r_Filter_6_157361_e;
    gettimeofday(&tv_r_Filter_6_157361_s, 0);
    SW_Filter_TD_6107427(tbl_SerializeFromObject_TD_7969555_input, tbl_Filter_TD_6107427_output);
    gettimeofday(&tv_r_Filter_6_157361_e, 0);

    struct timeval tv_r_Filter_6_892333_s, tv_r_Filter_6_892333_e;
    gettimeofday(&tv_r_Filter_6_892333_s, 0);
    SW_Filter_TD_6966126(tbl_SerializeFromObject_TD_7200129_input, tbl_Filter_TD_6966126_output);
    gettimeofday(&tv_r_Filter_6_892333_e, 0);

    struct timeval tv_r_Filter_5_361296_s, tv_r_Filter_5_361296_e;
    gettimeofday(&tv_r_Filter_5_361296_s, 0);
    SW_Filter_TD_5725449(tbl_SerializeFromObject_TD_6861241_input, tbl_Filter_TD_5725449_output);
    gettimeofday(&tv_r_Filter_5_361296_e, 0);

    struct timeval tv_r_JOIN_INNER_5_428469_s, tv_r_JOIN_INNER_5_428469_e;
    gettimeofday(&tv_r_JOIN_INNER_5_428469_s, 0);
    SW_JOIN_INNER_TD_5269686(tbl_Filter_TD_6966126_output, tbl_Filter_TD_6107427_output, tbl_JOIN_INNER_TD_5269686_output);
    gettimeofday(&tv_r_JOIN_INNER_5_428469_e, 0);

    struct timeval tv_r_JOIN_INNER_4_766090_s, tv_r_JOIN_INNER_4_766090_e;
    gettimeofday(&tv_r_JOIN_INNER_4_766090_s, 0);
    SW_JOIN_INNER_TD_4888683(tbl_JOIN_INNER_TD_5269686_output, tbl_Filter_TD_5725449_output, tbl_JOIN_INNER_TD_4888683_output);
    gettimeofday(&tv_r_JOIN_INNER_4_766090_e, 0);

    struct timeval tv_r_Aggregate_3_903061_s, tv_r_Aggregate_3_903061_e;
    gettimeofday(&tv_r_Aggregate_3_903061_s, 0);
    SW_Aggregate_TD_3771786(tbl_JOIN_INNER_TD_4888683_output, tbl_Aggregate_TD_3771786_output);
    gettimeofday(&tv_r_Aggregate_3_903061_e, 0);

    struct timeval tv_r_Sort_2_57449_s, tv_r_Sort_2_57449_e;
    gettimeofday(&tv_r_Sort_2_57449_s, 0);
    SW_Sort_TD_2235772(tbl_Aggregate_TD_3771786_output, tbl_Sort_TD_2235772_output);
    gettimeofday(&tv_r_Sort_2_57449_e, 0);

    struct timeval tv_r_LocalLimit_1_306451_s, tv_r_LocalLimit_1_306451_e;
    gettimeofday(&tv_r_LocalLimit_1_306451_s, 0);
    SW_LocalLimit_TD_1482384(tbl_Sort_TD_2235772_output, tbl_LocalLimit_TD_1482384_output);
    gettimeofday(&tv_r_LocalLimit_1_306451_e, 0);

    struct timeval tv_r_GlobalLimit_0_821050_s, tv_r_GlobalLimit_0_821050_e;
    gettimeofday(&tv_r_GlobalLimit_0_821050_s, 0);
    SW_GlobalLimit_TD_0498908(tbl_LocalLimit_TD_1482384_output, tbl_GlobalLimit_TD_0498908_output);
    gettimeofday(&tv_r_GlobalLimit_0_821050_e, 0);

    gettimeofday(&tv_r_e, 0); 

    auto recordBatch = tbl_JOIN_INNER_TD_5269686_output.convertToRecordBatch();
    std::cout << "recordBatch" << recordBatch->ToString() << std::endl;
    auto tbl = covertFromArrowRecordBatchToTable(*recordBatch);
    auto convertedBatch = tbl->convertToRecordBatch();
    std::cout << "convertedBatch" << convertedBatch->ToString() << std::endl;

    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_157361_s, &tv_r_Filter_6_157361_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7969555_input: " << tbl_SerializeFromObject_TD_7969555_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_892333_s, &tv_r_Filter_6_892333_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7200129_input: " << tbl_SerializeFromObject_TD_7200129_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_361296_s, &tv_r_Filter_5_361296_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6861241_input: " << tbl_SerializeFromObject_TD_6861241_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_428469_s, &tv_r_JOIN_INNER_5_428469_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6966126_output: " << tbl_Filter_TD_6966126_output.getNumRow() << " " << "tbl_Filter_TD_6107427_output: " << tbl_Filter_TD_6107427_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_766090_s, &tv_r_JOIN_INNER_4_766090_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5269686_output: " << tbl_JOIN_INNER_TD_5269686_output.getNumRow() << " " << "tbl_Filter_TD_5725449_output: " << tbl_Filter_TD_5725449_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_903061_s, &tv_r_Aggregate_3_903061_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4888683_output: " << tbl_JOIN_INNER_TD_4888683_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_57449_s, &tv_r_Sort_2_57449_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3771786_output: " << tbl_Aggregate_TD_3771786_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_306451_s, &tv_r_LocalLimit_1_306451_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2235772_output: " << tbl_Sort_TD_2235772_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_821050_s, &tv_r_GlobalLimit_0_821050_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1482384_output: " << tbl_LocalLimit_TD_1482384_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 0.6456536 * 1000 << "ms" << std::endl; 
    return 0; 
}
