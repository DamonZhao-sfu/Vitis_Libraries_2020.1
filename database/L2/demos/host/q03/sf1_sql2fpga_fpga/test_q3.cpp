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

#include "cfgFunc_q3.hpp" 
#include "q3.hpp" 

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
    std::cout << "NOTE:running query #3\n."; 
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
    Table tbl_Sort_TD_0223276_output("tbl_Sort_TD_0223276_output", 6100000, 4, "");
    tbl_Sort_TD_0223276_output.allocateHost();
    Table tbl_Aggregate_TD_1534511_output("tbl_Aggregate_TD_1534511_output", 6100000, 4, "");
    tbl_Aggregate_TD_1534511_output.allocateHost();
    Table tbl_JOIN_INNER_TD_218141_output("tbl_JOIN_INNER_TD_218141_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_218141_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3887687_output("tbl_JOIN_INNER_TD_3887687_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_3887687_output.allocateHost();
    Table tbl_Filter_TD_3465058_output("tbl_Filter_TD_3465058_output", 6100000, 3, "");
    tbl_Filter_TD_3465058_output.allocateHost();
    Table tbl_Filter_TD_4286723_output("tbl_Filter_TD_4286723_output", 6100000, 2, "");
    tbl_Filter_TD_4286723_output.allocateHost();
    Table tbl_Filter_TD_4850135_output("tbl_Filter_TD_4850135_output", 6100000, 3, "");
    tbl_Filter_TD_4850135_output.allocateHost();
    Table tbl_SerializeFromObject_TD_46888_input;
    tbl_SerializeFromObject_TD_46888_input = Table("item", item_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_46888_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_46888_input.addCol("i_brand_id", 4);
    tbl_SerializeFromObject_TD_46888_input.addCol("i_brand", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_46888_input.addCol("i_manufact_id", 4);
    tbl_SerializeFromObject_TD_46888_input.allocateHost();
    tbl_SerializeFromObject_TD_46888_input.loadHost();
    Table tbl_SerializeFromObject_TD_5802948_input;
    tbl_SerializeFromObject_TD_5802948_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_5802948_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_5802948_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_5802948_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_5802948_input.allocateHost();
    tbl_SerializeFromObject_TD_5802948_input.loadHost();
    Table tbl_SerializeFromObject_TD_5506759_input;
    tbl_SerializeFromObject_TD_5506759_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_5506759_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_5506759_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_5506759_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_5506759_input.allocateHost();
    tbl_SerializeFromObject_TD_5506759_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_4_231258_s, tv_r_Filter_4_231258_e;
    gettimeofday(&tv_r_Filter_4_231258_s, 0);
    SW_Filter_TD_4850135(tbl_SerializeFromObject_TD_5506759_input, tbl_Filter_TD_4850135_output);
    gettimeofday(&tv_r_Filter_4_231258_e, 0);

    struct timeval tv_r_Filter_4_737317_s, tv_r_Filter_4_737317_e;
    gettimeofday(&tv_r_Filter_4_737317_s, 0);
    SW_Filter_TD_4286723(tbl_SerializeFromObject_TD_5802948_input, tbl_Filter_TD_4286723_output);
    gettimeofday(&tv_r_Filter_4_737317_e, 0);

    struct timeval tv_r_Filter_3_509436_s, tv_r_Filter_3_509436_e;
    gettimeofday(&tv_r_Filter_3_509436_s, 0);
    SW_Filter_TD_3465058(tbl_SerializeFromObject_TD_46888_input, tbl_Filter_TD_3465058_output);
    gettimeofday(&tv_r_Filter_3_509436_e, 0);

    struct timeval tv_r_JOIN_INNER_3_101668_s, tv_r_JOIN_INNER_3_101668_e;
    gettimeofday(&tv_r_JOIN_INNER_3_101668_s, 0);
    SW_JOIN_INNER_TD_3887687(tbl_Filter_TD_4286723_output, tbl_Filter_TD_4850135_output, tbl_JOIN_INNER_TD_3887687_output);
    gettimeofday(&tv_r_JOIN_INNER_3_101668_e, 0);

    struct timeval tv_r_JOIN_INNER_2_873967_s, tv_r_JOIN_INNER_2_873967_e;
    gettimeofday(&tv_r_JOIN_INNER_2_873967_s, 0);
    SW_JOIN_INNER_TD_218141(tbl_JOIN_INNER_TD_3887687_output, tbl_Filter_TD_3465058_output, tbl_JOIN_INNER_TD_218141_output);
    gettimeofday(&tv_r_JOIN_INNER_2_873967_e, 0);

    struct timeval tv_r_Aggregate_1_245089_s, tv_r_Aggregate_1_245089_e;
    gettimeofday(&tv_r_Aggregate_1_245089_s, 0);
    SW_Aggregate_TD_1534511(tbl_JOIN_INNER_TD_218141_output, tbl_Aggregate_TD_1534511_output);
    gettimeofday(&tv_r_Aggregate_1_245089_e, 0);

    struct timeval tv_r_Sort_0_904009_s, tv_r_Sort_0_904009_e;
    gettimeofday(&tv_r_Sort_0_904009_s, 0);
    SW_Sort_TD_0223276(tbl_Aggregate_TD_1534511_output, tbl_Sort_TD_0223276_output);
    gettimeofday(&tv_r_Sort_0_904009_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_231258_s, &tv_r_Filter_4_231258_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5506759_input: " << tbl_SerializeFromObject_TD_5506759_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_737317_s, &tv_r_Filter_4_737317_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5802948_input: " << tbl_SerializeFromObject_TD_5802948_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_509436_s, &tv_r_Filter_3_509436_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_46888_input: " << tbl_SerializeFromObject_TD_46888_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_101668_s, &tv_r_JOIN_INNER_3_101668_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_4286723_output: " << tbl_Filter_TD_4286723_output.getNumRow() << " " << "tbl_Filter_TD_4850135_output: " << tbl_Filter_TD_4850135_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_2: " << tvdiff(&tv_r_JOIN_INNER_2_873967_s, &tv_r_JOIN_INNER_2_873967_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3887687_output: " << tbl_JOIN_INNER_TD_3887687_output.getNumRow() << " " << "tbl_Filter_TD_3465058_output: " << tbl_Filter_TD_3465058_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_245089_s, &tv_r_Aggregate_1_245089_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_218141_output: " << tbl_JOIN_INNER_TD_218141_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_904009_s, &tv_r_Sort_0_904009_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_1534511_output: " << tbl_Aggregate_TD_1534511_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 0.81398195 * 1000 << "ms" << std::endl; 
    return 0; 
}
