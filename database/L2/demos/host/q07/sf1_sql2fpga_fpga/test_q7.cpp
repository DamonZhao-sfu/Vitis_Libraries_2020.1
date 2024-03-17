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

#include "cfgFunc_q7.hpp" 
#include "q7.hpp" 

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
    std::cout << "NOTE:running query #7\n."; 
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
    Table tbl_Sort_TD_0403938_output("tbl_Sort_TD_0403938_output", 6100000, 1, "");
    tbl_Sort_TD_0403938_output.allocateHost();
    Table tbl_JOIN_INNER_TD_116077_output("tbl_JOIN_INNER_TD_116077_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_116077_output.allocateHost();
    Table tbl_JOIN_INNER_TD_2604902_output("tbl_JOIN_INNER_TD_2604902_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_2604902_output.allocateHost();
    Table tbl_Filter_TD_2901630_output("tbl_Filter_TD_2901630_output", 6100000, 1, "");
    tbl_Filter_TD_2901630_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3717004_output("tbl_JOIN_INNER_TD_3717004_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_3717004_output.allocateHost();
    Table tbl_Filter_TD_3908859_output("tbl_Filter_TD_3908859_output", 6100000, 2, "");
    tbl_Filter_TD_3908859_output.allocateHost();
    Table tbl_SerializeFromObject_TD_3724616_input;
    tbl_SerializeFromObject_TD_3724616_input = Table("promotion", promotion_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_3724616_input.addCol("p_promo_sk", 4);
    tbl_SerializeFromObject_TD_3724616_input.addCol("p_channel_email", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_3724616_input.addCol("p_channel_event", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_3724616_input.allocateHost();
    tbl_SerializeFromObject_TD_3724616_input.loadHost();
    Table tbl_JOIN_INNER_TD_4663801_output("tbl_JOIN_INNER_TD_4663801_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_4663801_output.allocateHost();
    Table tbl_Filter_TD_4984697_output("tbl_Filter_TD_4984697_output", 6100000, 1, "");
    tbl_Filter_TD_4984697_output.allocateHost();
    Table tbl_SerializeFromObject_TD_426962_input;
    tbl_SerializeFromObject_TD_426962_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_426962_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_426962_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_426962_input.allocateHost();
    tbl_SerializeFromObject_TD_426962_input.loadHost();
    Table tbl_Filter_TD_5568778_output("tbl_Filter_TD_5568778_output", 6100000, 4, "");
    tbl_Filter_TD_5568778_output.allocateHost();
    Table tbl_Filter_TD_5561270_output("tbl_Filter_TD_5561270_output", 6100000, 1, "");
    tbl_Filter_TD_5561270_output.allocateHost();
    Table tbl_SerializeFromObject_TD_5789587_input;
    tbl_SerializeFromObject_TD_5789587_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_5789587_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_5789587_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_5789587_input.allocateHost();
    tbl_SerializeFromObject_TD_5789587_input.loadHost();
    Table tbl_SerializeFromObject_TD_647904_input;
    tbl_SerializeFromObject_TD_647904_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_647904_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_647904_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_647904_input.addCol("ss_cdemo_sk", 4);
    tbl_SerializeFromObject_TD_647904_input.addCol("ss_promo_sk", 4);
    tbl_SerializeFromObject_TD_647904_input.allocateHost();
    tbl_SerializeFromObject_TD_647904_input.loadHost();
    Table tbl_SerializeFromObject_TD_6857844_input;
    tbl_SerializeFromObject_TD_6857844_input = Table("customer_demographics", customer_demographics_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_6857844_input.addCol("cd_demo_sk", 4);
    tbl_SerializeFromObject_TD_6857844_input.addCol("cd_gender", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6857844_input.addCol("cd_marital_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6857844_input.addCol("cd_education_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6857844_input.allocateHost();
    tbl_SerializeFromObject_TD_6857844_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_5_608937_s, tv_r_Filter_5_608937_e;
    gettimeofday(&tv_r_Filter_5_608937_s, 0);
    SW_Filter_TD_5561270(tbl_SerializeFromObject_TD_6857844_input, tbl_Filter_TD_5561270_output);
    gettimeofday(&tv_r_Filter_5_608937_e, 0);

    struct timeval tv_r_Filter_5_425931_s, tv_r_Filter_5_425931_e;
    gettimeofday(&tv_r_Filter_5_425931_s, 0);
    SW_Filter_TD_5568778(tbl_SerializeFromObject_TD_647904_input, tbl_Filter_TD_5568778_output);
    gettimeofday(&tv_r_Filter_5_425931_e, 0);

    struct timeval tv_r_Filter_4_257566_s, tv_r_Filter_4_257566_e;
    gettimeofday(&tv_r_Filter_4_257566_s, 0);
    SW_Filter_TD_4984697(tbl_SerializeFromObject_TD_5789587_input, tbl_Filter_TD_4984697_output);
    gettimeofday(&tv_r_Filter_4_257566_e, 0);

    struct timeval tv_r_JOIN_INNER_4_329271_s, tv_r_JOIN_INNER_4_329271_e;
    gettimeofday(&tv_r_JOIN_INNER_4_329271_s, 0);
    SW_JOIN_INNER_TD_4663801(tbl_Filter_TD_5568778_output, tbl_Filter_TD_5561270_output, tbl_JOIN_INNER_TD_4663801_output);
    gettimeofday(&tv_r_JOIN_INNER_4_329271_e, 0);

    struct timeval tv_r_Filter_3_21165_s, tv_r_Filter_3_21165_e;
    gettimeofday(&tv_r_Filter_3_21165_s, 0);
    SW_Filter_TD_3908859(tbl_SerializeFromObject_TD_426962_input, tbl_Filter_TD_3908859_output);
    gettimeofday(&tv_r_Filter_3_21165_e, 0);

    struct timeval tv_r_JOIN_INNER_3_943417_s, tv_r_JOIN_INNER_3_943417_e;
    gettimeofday(&tv_r_JOIN_INNER_3_943417_s, 0);
    SW_JOIN_INNER_TD_3717004(tbl_JOIN_INNER_TD_4663801_output, tbl_Filter_TD_4984697_output, tbl_JOIN_INNER_TD_3717004_output);
    gettimeofday(&tv_r_JOIN_INNER_3_943417_e, 0);

    struct timeval tv_r_Filter_2_645247_s, tv_r_Filter_2_645247_e;
    gettimeofday(&tv_r_Filter_2_645247_s, 0);
    SW_Filter_TD_2901630(tbl_SerializeFromObject_TD_3724616_input, tbl_Filter_TD_2901630_output);
    gettimeofday(&tv_r_Filter_2_645247_e, 0);

    struct timeval tv_r_JOIN_INNER_2_704985_s, tv_r_JOIN_INNER_2_704985_e;
    gettimeofday(&tv_r_JOIN_INNER_2_704985_s, 0);
    SW_JOIN_INNER_TD_2604902(tbl_JOIN_INNER_TD_3717004_output, tbl_Filter_TD_3908859_output, tbl_JOIN_INNER_TD_2604902_output);
    gettimeofday(&tv_r_JOIN_INNER_2_704985_e, 0);

    struct timeval tv_r_JOIN_INNER_1_985619_s, tv_r_JOIN_INNER_1_985619_e;
    gettimeofday(&tv_r_JOIN_INNER_1_985619_s, 0);
    SW_JOIN_INNER_TD_116077(tbl_JOIN_INNER_TD_2604902_output, tbl_Filter_TD_2901630_output, tbl_JOIN_INNER_TD_116077_output);
    gettimeofday(&tv_r_JOIN_INNER_1_985619_e, 0);

    struct timeval tv_r_Sort_0_807062_s, tv_r_Sort_0_807062_e;
    gettimeofday(&tv_r_Sort_0_807062_s, 0);
    SW_Sort_TD_0403938(tbl_JOIN_INNER_TD_116077_output, tbl_Sort_TD_0403938_output);
    gettimeofday(&tv_r_Sort_0_807062_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_608937_s, &tv_r_Filter_5_608937_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6857844_input: " << tbl_SerializeFromObject_TD_6857844_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_425931_s, &tv_r_Filter_5_425931_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_647904_input: " << tbl_SerializeFromObject_TD_647904_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_257566_s, &tv_r_Filter_4_257566_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5789587_input: " << tbl_SerializeFromObject_TD_5789587_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_329271_s, &tv_r_JOIN_INNER_4_329271_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_5568778_output: " << tbl_Filter_TD_5568778_output.getNumRow() << " " << "tbl_Filter_TD_5561270_output: " << tbl_Filter_TD_5561270_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_21165_s, &tv_r_Filter_3_21165_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_426962_input: " << tbl_SerializeFromObject_TD_426962_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_943417_s, &tv_r_JOIN_INNER_3_943417_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4663801_output: " << tbl_JOIN_INNER_TD_4663801_output.getNumRow() << " " << "tbl_Filter_TD_4984697_output: " << tbl_Filter_TD_4984697_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_645247_s, &tv_r_Filter_2_645247_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3724616_input: " << tbl_SerializeFromObject_TD_3724616_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_2: " << tvdiff(&tv_r_JOIN_INNER_2_704985_s, &tv_r_JOIN_INNER_2_704985_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3717004_output: " << tbl_JOIN_INNER_TD_3717004_output.getNumRow() << " " << "tbl_Filter_TD_3908859_output: " << tbl_Filter_TD_3908859_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_1: " << tvdiff(&tv_r_JOIN_INNER_1_985619_s, &tv_r_JOIN_INNER_1_985619_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_2604902_output: " << tbl_JOIN_INNER_TD_2604902_output.getNumRow() << " " << "tbl_Filter_TD_2901630_output: " << tbl_Filter_TD_2901630_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_807062_s, &tv_r_Sort_0_807062_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_116077_output: " << tbl_JOIN_INNER_TD_116077_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.292465 * 1000 << "ms" << std::endl; 
    return 0; 
}
