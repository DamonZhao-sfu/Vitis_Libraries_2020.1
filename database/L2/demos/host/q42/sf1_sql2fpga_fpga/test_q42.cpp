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

#include "cfgFunc_q42.hpp" 
#include "q42.hpp" 

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
    std::cout << "NOTE:running query #42\n."; 
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
    Table tbl_GlobalLimit_TD_0308580_output("tbl_GlobalLimit_TD_0308580_output", 6100000, 4, "");
    tbl_GlobalLimit_TD_0308580_output.allocateHost();
    Table tbl_LocalLimit_TD_1317136_output("tbl_LocalLimit_TD_1317136_output", 6100000, 4, "");
    tbl_LocalLimit_TD_1317136_output.allocateHost();
    Table tbl_Sort_TD_2540051_output("tbl_Sort_TD_2540051_output", 6100000, 4, "");
    tbl_Sort_TD_2540051_output.allocateHost();
    Table tbl_Aggregate_TD_3582605_output("tbl_Aggregate_TD_3582605_output", 6100000, 4, "");
    tbl_Aggregate_TD_3582605_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4142333_output("tbl_JOIN_INNER_TD_4142333_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_4142333_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5999083_output("tbl_JOIN_INNER_TD_5999083_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_5999083_output.allocateHost();
    Table tbl_Filter_TD_523672_output("tbl_Filter_TD_523672_output", 6100000, 3, "");
    tbl_Filter_TD_523672_output.allocateHost();
    Table tbl_Filter_TD_6820771_output("tbl_Filter_TD_6820771_output", 6100000, 2, "");
    tbl_Filter_TD_6820771_output.allocateHost();
    Table tbl_Filter_TD_6282188_output("tbl_Filter_TD_6282188_output", 6100000, 3, "");
    tbl_Filter_TD_6282188_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6509298_input;
    tbl_SerializeFromObject_TD_6509298_input = Table("item", item_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_6509298_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_6509298_input.addCol("i_category_id", 4);
    tbl_SerializeFromObject_TD_6509298_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6509298_input.addCol("i_manager_id", 4);
    tbl_SerializeFromObject_TD_6509298_input.allocateHost();
    tbl_SerializeFromObject_TD_6509298_input.loadHost();
    Table tbl_SerializeFromObject_TD_7310609_input;
    tbl_SerializeFromObject_TD_7310609_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7310609_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_7310609_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_7310609_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_7310609_input.allocateHost();
    tbl_SerializeFromObject_TD_7310609_input.loadHost();
    Table tbl_SerializeFromObject_TD_7213546_input;
    tbl_SerializeFromObject_TD_7213546_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7213546_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_7213546_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_7213546_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_7213546_input.allocateHost();
    tbl_SerializeFromObject_TD_7213546_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_6_904586_s, tv_r_Filter_6_904586_e;
    gettimeofday(&tv_r_Filter_6_904586_s, 0);
    SW_Filter_TD_6282188(tbl_SerializeFromObject_TD_7213546_input, tbl_Filter_TD_6282188_output);
    gettimeofday(&tv_r_Filter_6_904586_e, 0);

    struct timeval tv_r_Filter_6_699848_s, tv_r_Filter_6_699848_e;
    gettimeofday(&tv_r_Filter_6_699848_s, 0);
    SW_Filter_TD_6820771(tbl_SerializeFromObject_TD_7310609_input, tbl_Filter_TD_6820771_output);
    gettimeofday(&tv_r_Filter_6_699848_e, 0);

    struct timeval tv_r_Filter_5_617646_s, tv_r_Filter_5_617646_e;
    gettimeofday(&tv_r_Filter_5_617646_s, 0);
    SW_Filter_TD_523672(tbl_SerializeFromObject_TD_6509298_input, tbl_Filter_TD_523672_output);
    gettimeofday(&tv_r_Filter_5_617646_e, 0);

    struct timeval tv_r_JOIN_INNER_5_921425_s, tv_r_JOIN_INNER_5_921425_e;
    gettimeofday(&tv_r_JOIN_INNER_5_921425_s, 0);
    SW_JOIN_INNER_TD_5999083(tbl_Filter_TD_6820771_output, tbl_Filter_TD_6282188_output, tbl_JOIN_INNER_TD_5999083_output);
    gettimeofday(&tv_r_JOIN_INNER_5_921425_e, 0);

    struct timeval tv_r_JOIN_INNER_4_799306_s, tv_r_JOIN_INNER_4_799306_e;
    gettimeofday(&tv_r_JOIN_INNER_4_799306_s, 0);
    SW_JOIN_INNER_TD_4142333(tbl_JOIN_INNER_TD_5999083_output, tbl_Filter_TD_523672_output, tbl_JOIN_INNER_TD_4142333_output);
    gettimeofday(&tv_r_JOIN_INNER_4_799306_e, 0);

    struct timeval tv_r_Aggregate_3_683172_s, tv_r_Aggregate_3_683172_e;
    gettimeofday(&tv_r_Aggregate_3_683172_s, 0);
    SW_Aggregate_TD_3582605(tbl_JOIN_INNER_TD_4142333_output, tbl_Aggregate_TD_3582605_output);
    gettimeofday(&tv_r_Aggregate_3_683172_e, 0);

    struct timeval tv_r_Sort_2_854037_s, tv_r_Sort_2_854037_e;
    gettimeofday(&tv_r_Sort_2_854037_s, 0);
    SW_Sort_TD_2540051(tbl_Aggregate_TD_3582605_output, tbl_Sort_TD_2540051_output);
    gettimeofday(&tv_r_Sort_2_854037_e, 0);

    struct timeval tv_r_LocalLimit_1_71215_s, tv_r_LocalLimit_1_71215_e;
    gettimeofday(&tv_r_LocalLimit_1_71215_s, 0);
    SW_LocalLimit_TD_1317136(tbl_Sort_TD_2540051_output, tbl_LocalLimit_TD_1317136_output);
    gettimeofday(&tv_r_LocalLimit_1_71215_e, 0);

    struct timeval tv_r_GlobalLimit_0_108722_s, tv_r_GlobalLimit_0_108722_e;
    gettimeofday(&tv_r_GlobalLimit_0_108722_s, 0);
    SW_GlobalLimit_TD_0308580(tbl_LocalLimit_TD_1317136_output, tbl_GlobalLimit_TD_0308580_output);
    gettimeofday(&tv_r_GlobalLimit_0_108722_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_904586_s, &tv_r_Filter_6_904586_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7213546_input: " << tbl_SerializeFromObject_TD_7213546_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_699848_s, &tv_r_Filter_6_699848_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7310609_input: " << tbl_SerializeFromObject_TD_7310609_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_617646_s, &tv_r_Filter_5_617646_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6509298_input: " << tbl_SerializeFromObject_TD_6509298_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_921425_s, &tv_r_JOIN_INNER_5_921425_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6820771_output: " << tbl_Filter_TD_6820771_output.getNumRow() << " " << "tbl_Filter_TD_6282188_output: " << tbl_Filter_TD_6282188_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_799306_s, &tv_r_JOIN_INNER_4_799306_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5999083_output: " << tbl_JOIN_INNER_TD_5999083_output.getNumRow() << " " << "tbl_Filter_TD_523672_output: " << tbl_Filter_TD_523672_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_683172_s, &tv_r_Aggregate_3_683172_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4142333_output: " << tbl_JOIN_INNER_TD_4142333_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_854037_s, &tv_r_Sort_2_854037_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3582605_output: " << tbl_Aggregate_TD_3582605_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_71215_s, &tv_r_LocalLimit_1_71215_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2540051_output: " << tbl_Sort_TD_2540051_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_108722_s, &tv_r_GlobalLimit_0_108722_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1317136_output: " << tbl_LocalLimit_TD_1317136_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 0.79616034 * 1000 << "ms" << std::endl; 
    return 0; 
}
