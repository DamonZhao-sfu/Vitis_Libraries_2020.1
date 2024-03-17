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

#include "cfgFunc_q97.hpp" 
#include "q97.hpp" 

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
    std::cout << "NOTE:running query #97\n."; 
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
    Table tbl_Aggregate_TD_0758201_output("tbl_Aggregate_TD_0758201_output", 6100000, 3, "");
    tbl_Aggregate_TD_0758201_output.allocateHost();
    Table tbl_JOIN_FULLOUTER_TD_1314734_output("tbl_JOIN_FULLOUTER_TD_1314734_output", 6100000, 2, "");
    tbl_JOIN_FULLOUTER_TD_1314734_output.allocateHost();
    Table tbl_Aggregate_TD_2677304_output("tbl_Aggregate_TD_2677304_output", 6100000, 2, "");
    tbl_Aggregate_TD_2677304_output.allocateHost();
    Table tbl_Aggregate_TD_2546754_output("tbl_Aggregate_TD_2546754_output", 6100000, 2, "");
    tbl_Aggregate_TD_2546754_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3179392_output("tbl_JOIN_INNER_TD_3179392_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_3179392_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3222611_output("tbl_JOIN_INNER_TD_3222611_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_3222611_output.allocateHost();
    Table tbl_Filter_TD_4866947_output("tbl_Filter_TD_4866947_output", 6100000, 3, "");
    tbl_Filter_TD_4866947_output.allocateHost();
    Table tbl_Filter_TD_4752553_output("tbl_Filter_TD_4752553_output", 6100000, 1, "");
    tbl_Filter_TD_4752553_output.allocateHost();
    Table tbl_Filter_TD_4420490_output("tbl_Filter_TD_4420490_output", 6100000, 3, "");
    tbl_Filter_TD_4420490_output.allocateHost();
    Table tbl_Filter_TD_446761_output("tbl_Filter_TD_446761_output", 6100000, 1, "");
    tbl_Filter_TD_446761_output.allocateHost();
    Table tbl_SerializeFromObject_TD_5101142_input;
    tbl_SerializeFromObject_TD_5101142_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_5101142_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_5101142_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_5101142_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_5101142_input.allocateHost();
    tbl_SerializeFromObject_TD_5101142_input.loadHost();
    Table tbl_SerializeFromObject_TD_5180935_input;
    tbl_SerializeFromObject_TD_5180935_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_5180935_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_5180935_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_5180935_input.allocateHost();
    tbl_SerializeFromObject_TD_5180935_input.loadHost();
    Table tbl_SerializeFromObject_TD_5317840_input;
    tbl_SerializeFromObject_TD_5317840_input = Table("catalog_sales", catalog_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_5317840_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_5317840_input.addCol("cs_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_5317840_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_5317840_input.allocateHost();
    tbl_SerializeFromObject_TD_5317840_input.loadHost();
    Table tbl_SerializeFromObject_TD_5917850_input;
    tbl_SerializeFromObject_TD_5917850_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_5917850_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_5917850_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_5917850_input.allocateHost();
    tbl_SerializeFromObject_TD_5917850_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_4_352252_s, tv_r_Filter_4_352252_e;
    gettimeofday(&tv_r_Filter_4_352252_s, 0);
    SW_Filter_TD_446761(tbl_SerializeFromObject_TD_5917850_input, tbl_Filter_TD_446761_output);
    gettimeofday(&tv_r_Filter_4_352252_e, 0);

    struct timeval tv_r_Filter_4_444672_s, tv_r_Filter_4_444672_e;
    gettimeofday(&tv_r_Filter_4_444672_s, 0);
    SW_Filter_TD_4420490(tbl_SerializeFromObject_TD_5317840_input, tbl_Filter_TD_4420490_output);
    gettimeofday(&tv_r_Filter_4_444672_e, 0);

    struct timeval tv_r_Filter_4_45337_s, tv_r_Filter_4_45337_e;
    gettimeofday(&tv_r_Filter_4_45337_s, 0);
    SW_Filter_TD_4752553(tbl_SerializeFromObject_TD_5180935_input, tbl_Filter_TD_4752553_output);
    gettimeofday(&tv_r_Filter_4_45337_e, 0);

    struct timeval tv_r_Filter_4_449560_s, tv_r_Filter_4_449560_e;
    gettimeofday(&tv_r_Filter_4_449560_s, 0);
    SW_Filter_TD_4866947(tbl_SerializeFromObject_TD_5101142_input, tbl_Filter_TD_4866947_output);
    gettimeofday(&tv_r_Filter_4_449560_e, 0);

    struct timeval tv_r_JOIN_INNER_3_393195_s, tv_r_JOIN_INNER_3_393195_e;
    gettimeofday(&tv_r_JOIN_INNER_3_393195_s, 0);
    SW_JOIN_INNER_TD_3222611(tbl_Filter_TD_4420490_output, tbl_Filter_TD_446761_output, tbl_JOIN_INNER_TD_3222611_output);
    gettimeofday(&tv_r_JOIN_INNER_3_393195_e, 0);

    struct timeval tv_r_JOIN_INNER_3_591139_s, tv_r_JOIN_INNER_3_591139_e;
    gettimeofday(&tv_r_JOIN_INNER_3_591139_s, 0);
    SW_JOIN_INNER_TD_3179392(tbl_Filter_TD_4866947_output, tbl_Filter_TD_4752553_output, tbl_JOIN_INNER_TD_3179392_output);
    gettimeofday(&tv_r_JOIN_INNER_3_591139_e, 0);

    struct timeval tv_r_Aggregate_2_808555_s, tv_r_Aggregate_2_808555_e;
    gettimeofday(&tv_r_Aggregate_2_808555_s, 0);
    SW_Aggregate_TD_2546754(tbl_JOIN_INNER_TD_3222611_output, tbl_Aggregate_TD_2546754_output);
    gettimeofday(&tv_r_Aggregate_2_808555_e, 0);

    struct timeval tv_r_Aggregate_2_213530_s, tv_r_Aggregate_2_213530_e;
    gettimeofday(&tv_r_Aggregate_2_213530_s, 0);
    SW_Aggregate_TD_2677304(tbl_JOIN_INNER_TD_3179392_output, tbl_Aggregate_TD_2677304_output);
    gettimeofday(&tv_r_Aggregate_2_213530_e, 0);

    struct timeval tv_r_JOIN_FULLOUTER_1_243353_s, tv_r_JOIN_FULLOUTER_1_243353_e;
    gettimeofday(&tv_r_JOIN_FULLOUTER_1_243353_s, 0);
    SW_JOIN_FULLOUTER_TD_1314734(tbl_Aggregate_TD_2677304_output, tbl_Aggregate_TD_2546754_output, tbl_JOIN_FULLOUTER_TD_1314734_output);
    gettimeofday(&tv_r_JOIN_FULLOUTER_1_243353_e, 0);

    struct timeval tv_r_Aggregate_0_40293_s, tv_r_Aggregate_0_40293_e;
    gettimeofday(&tv_r_Aggregate_0_40293_s, 0);
    SW_Aggregate_TD_0758201(tbl_JOIN_FULLOUTER_TD_1314734_output, tbl_Aggregate_TD_0758201_output);
    gettimeofday(&tv_r_Aggregate_0_40293_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_352252_s, &tv_r_Filter_4_352252_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5917850_input: " << tbl_SerializeFromObject_TD_5917850_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_444672_s, &tv_r_Filter_4_444672_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5317840_input: " << tbl_SerializeFromObject_TD_5317840_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_45337_s, &tv_r_Filter_4_45337_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5180935_input: " << tbl_SerializeFromObject_TD_5180935_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_449560_s, &tv_r_Filter_4_449560_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5101142_input: " << tbl_SerializeFromObject_TD_5101142_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_393195_s, &tv_r_JOIN_INNER_3_393195_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_4420490_output: " << tbl_Filter_TD_4420490_output.getNumRow() << " " << "tbl_Filter_TD_446761_output: " << tbl_Filter_TD_446761_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_591139_s, &tv_r_JOIN_INNER_3_591139_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_4866947_output: " << tbl_Filter_TD_4866947_output.getNumRow() << " " << "tbl_Filter_TD_4752553_output: " << tbl_Filter_TD_4752553_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_2: " << tvdiff(&tv_r_Aggregate_2_808555_s, &tv_r_Aggregate_2_808555_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3222611_output: " << tbl_JOIN_INNER_TD_3222611_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_2: " << tvdiff(&tv_r_Aggregate_2_213530_s, &tv_r_Aggregate_2_213530_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3179392_output: " << tbl_JOIN_INNER_TD_3179392_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_FULLOUTER_1: " << tvdiff(&tv_r_JOIN_FULLOUTER_1_243353_s, &tv_r_JOIN_FULLOUTER_1_243353_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_2677304_output: " << tbl_Aggregate_TD_2677304_output.getNumRow() << " " << "tbl_Aggregate_TD_2546754_output: " << tbl_Aggregate_TD_2546754_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_0: " << tvdiff(&tv_r_Aggregate_0_40293_s, &tv_r_Aggregate_0_40293_e) / 1000.0 << " ms " 
     << "tbl_JOIN_FULLOUTER_TD_1314734_output: " << tbl_JOIN_FULLOUTER_TD_1314734_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 3.0619426 * 1000 << "ms" << std::endl; 
    return 0; 
}
