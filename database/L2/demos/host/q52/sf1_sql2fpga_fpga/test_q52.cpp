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

#include "cfgFunc_q52.hpp" 
#include "q52.hpp" 

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
    std::cout << "NOTE:running query #52\n."; 
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
    Table tbl_GlobalLimit_TD_0352934_output("tbl_GlobalLimit_TD_0352934_output", 6100000, 4, "");
    tbl_GlobalLimit_TD_0352934_output.allocateHost();
    Table tbl_LocalLimit_TD_1817293_output("tbl_LocalLimit_TD_1817293_output", 6100000, 4, "");
    tbl_LocalLimit_TD_1817293_output.allocateHost();
    Table tbl_Sort_TD_2937953_output("tbl_Sort_TD_2937953_output", 6100000, 4, "");
    tbl_Sort_TD_2937953_output.allocateHost();
    Table tbl_Aggregate_TD_3988287_output("tbl_Aggregate_TD_3988287_output", 6100000, 4, "");
    tbl_Aggregate_TD_3988287_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4942037_output("tbl_JOIN_INNER_TD_4942037_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_4942037_output.allocateHost();
    Table tbl_JOIN_INNER_TD_582576_output("tbl_JOIN_INNER_TD_582576_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_582576_output.allocateHost();
    Table tbl_Filter_TD_5357844_output("tbl_Filter_TD_5357844_output", 6100000, 3, "");
    tbl_Filter_TD_5357844_output.allocateHost();
    Table tbl_Filter_TD_6231194_output("tbl_Filter_TD_6231194_output", 6100000, 2, "");
    tbl_Filter_TD_6231194_output.allocateHost();
    Table tbl_Filter_TD_6116806_output("tbl_Filter_TD_6116806_output", 6100000, 3, "");
    tbl_Filter_TD_6116806_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6458135_input;
    tbl_SerializeFromObject_TD_6458135_input = Table("item", item_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_6458135_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_6458135_input.addCol("i_brand_id", 4);
    tbl_SerializeFromObject_TD_6458135_input.addCol("i_brand", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6458135_input.addCol("i_manager_id", 4);
    tbl_SerializeFromObject_TD_6458135_input.allocateHost();
    tbl_SerializeFromObject_TD_6458135_input.loadHost();
    Table tbl_SerializeFromObject_TD_7938405_input;
    tbl_SerializeFromObject_TD_7938405_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7938405_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_7938405_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_7938405_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_7938405_input.allocateHost();
    tbl_SerializeFromObject_TD_7938405_input.loadHost();
    Table tbl_SerializeFromObject_TD_7317535_input;
    tbl_SerializeFromObject_TD_7317535_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7317535_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_7317535_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_7317535_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_7317535_input.allocateHost();
    tbl_SerializeFromObject_TD_7317535_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_6_329932_s, tv_r_Filter_6_329932_e;
    gettimeofday(&tv_r_Filter_6_329932_s, 0);
    SW_Filter_TD_6116806(tbl_SerializeFromObject_TD_7317535_input, tbl_Filter_TD_6116806_output);
    gettimeofday(&tv_r_Filter_6_329932_e, 0);

    struct timeval tv_r_Filter_6_751360_s, tv_r_Filter_6_751360_e;
    gettimeofday(&tv_r_Filter_6_751360_s, 0);
    SW_Filter_TD_6231194(tbl_SerializeFromObject_TD_7938405_input, tbl_Filter_TD_6231194_output);
    gettimeofday(&tv_r_Filter_6_751360_e, 0);

    struct timeval tv_r_Filter_5_881052_s, tv_r_Filter_5_881052_e;
    gettimeofday(&tv_r_Filter_5_881052_s, 0);
    SW_Filter_TD_5357844(tbl_SerializeFromObject_TD_6458135_input, tbl_Filter_TD_5357844_output);
    gettimeofday(&tv_r_Filter_5_881052_e, 0);

    struct timeval tv_r_JOIN_INNER_5_232104_s, tv_r_JOIN_INNER_5_232104_e;
    gettimeofday(&tv_r_JOIN_INNER_5_232104_s, 0);
    SW_JOIN_INNER_TD_582576(tbl_Filter_TD_6231194_output, tbl_Filter_TD_6116806_output, tbl_JOIN_INNER_TD_582576_output);
    gettimeofday(&tv_r_JOIN_INNER_5_232104_e, 0);

    struct timeval tv_r_JOIN_INNER_4_821971_s, tv_r_JOIN_INNER_4_821971_e;
    gettimeofday(&tv_r_JOIN_INNER_4_821971_s, 0);
    SW_JOIN_INNER_TD_4942037(tbl_JOIN_INNER_TD_582576_output, tbl_Filter_TD_5357844_output, tbl_JOIN_INNER_TD_4942037_output);
    gettimeofday(&tv_r_JOIN_INNER_4_821971_e, 0);

    struct timeval tv_r_Aggregate_3_188957_s, tv_r_Aggregate_3_188957_e;
    gettimeofday(&tv_r_Aggregate_3_188957_s, 0);
    SW_Aggregate_TD_3988287(tbl_JOIN_INNER_TD_4942037_output, tbl_Aggregate_TD_3988287_output);
    gettimeofday(&tv_r_Aggregate_3_188957_e, 0);

    struct timeval tv_r_Sort_2_850273_s, tv_r_Sort_2_850273_e;
    gettimeofday(&tv_r_Sort_2_850273_s, 0);
    SW_Sort_TD_2937953(tbl_Aggregate_TD_3988287_output, tbl_Sort_TD_2937953_output);
    gettimeofday(&tv_r_Sort_2_850273_e, 0);

    struct timeval tv_r_LocalLimit_1_62180_s, tv_r_LocalLimit_1_62180_e;
    gettimeofday(&tv_r_LocalLimit_1_62180_s, 0);
    SW_LocalLimit_TD_1817293(tbl_Sort_TD_2937953_output, tbl_LocalLimit_TD_1817293_output);
    gettimeofday(&tv_r_LocalLimit_1_62180_e, 0);

    struct timeval tv_r_GlobalLimit_0_490747_s, tv_r_GlobalLimit_0_490747_e;
    gettimeofday(&tv_r_GlobalLimit_0_490747_s, 0);
    SW_GlobalLimit_TD_0352934(tbl_LocalLimit_TD_1817293_output, tbl_GlobalLimit_TD_0352934_output);
    gettimeofday(&tv_r_GlobalLimit_0_490747_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_329932_s, &tv_r_Filter_6_329932_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7317535_input: " << tbl_SerializeFromObject_TD_7317535_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_751360_s, &tv_r_Filter_6_751360_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7938405_input: " << tbl_SerializeFromObject_TD_7938405_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_881052_s, &tv_r_Filter_5_881052_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6458135_input: " << tbl_SerializeFromObject_TD_6458135_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_232104_s, &tv_r_JOIN_INNER_5_232104_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6231194_output: " << tbl_Filter_TD_6231194_output.getNumRow() << " " << "tbl_Filter_TD_6116806_output: " << tbl_Filter_TD_6116806_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_821971_s, &tv_r_JOIN_INNER_4_821971_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_582576_output: " << tbl_JOIN_INNER_TD_582576_output.getNumRow() << " " << "tbl_Filter_TD_5357844_output: " << tbl_Filter_TD_5357844_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_188957_s, &tv_r_Aggregate_3_188957_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4942037_output: " << tbl_JOIN_INNER_TD_4942037_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_850273_s, &tv_r_Sort_2_850273_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3988287_output: " << tbl_Aggregate_TD_3988287_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_62180_s, &tv_r_LocalLimit_1_62180_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2937953_output: " << tbl_Sort_TD_2937953_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_490747_s, &tv_r_GlobalLimit_0_490747_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1817293_output: " << tbl_LocalLimit_TD_1817293_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 0.68308043 * 1000 << "ms" << std::endl; 
    return 0; 
}
