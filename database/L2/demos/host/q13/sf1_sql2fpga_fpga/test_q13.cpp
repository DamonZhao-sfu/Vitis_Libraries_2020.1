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

#include "cfgFunc_q13.hpp" 
#include "q13.hpp" 

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
    std::cout << "NOTE:running query #13\n."; 
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
    Table tbl_Aggregate_TD_0266099_output("tbl_Aggregate_TD_0266099_output", 6100000, 4, "");
    tbl_Aggregate_TD_0266099_output.allocateHost();
    Table tbl_JOIN_INNER_TD_1560680_output("tbl_JOIN_INNER_TD_1560680_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_1560680_output.allocateHost();
    Table tbl_JOIN_INNER_TD_2211379_output("tbl_JOIN_INNER_TD_2211379_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_2211379_output.allocateHost();
    Table tbl_Filter_TD_2319273_output("tbl_Filter_TD_2319273_output", 6100000, 2, "");
    tbl_Filter_TD_2319273_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3672673_output("tbl_JOIN_INNER_TD_3672673_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_3672673_output.allocateHost();
    Table tbl_Filter_TD_3998484_output("tbl_Filter_TD_3998484_output", 6100000, 3, "");
    tbl_Filter_TD_3998484_output.allocateHost();
    Table tbl_SerializeFromObject_TD_3706291_input;
    tbl_SerializeFromObject_TD_3706291_input = Table("household_demographics", household_demographics_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_3706291_input.addCol("hd_demo_sk", 4);
    tbl_SerializeFromObject_TD_3706291_input.addCol("hd_dep_count", 4);
    tbl_SerializeFromObject_TD_3706291_input.allocateHost();
    tbl_SerializeFromObject_TD_3706291_input.loadHost();
    Table tbl_JOIN_INNER_TD_4768430_output("tbl_JOIN_INNER_TD_4768430_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_4768430_output.allocateHost();
    Table tbl_Filter_TD_421869_output("tbl_Filter_TD_421869_output", 6100000, 1, "");
    tbl_Filter_TD_421869_output.allocateHost();
    Table tbl_SerializeFromObject_TD_4447020_input;
    tbl_SerializeFromObject_TD_4447020_input = Table("customer_demographics", customer_demographics_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_4447020_input.addCol("cd_demo_sk", 4);
    tbl_SerializeFromObject_TD_4447020_input.addCol("cd_marital_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_4447020_input.addCol("cd_education_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_4447020_input.allocateHost();
    tbl_SerializeFromObject_TD_4447020_input.loadHost();
    Table tbl_JOIN_INNER_TD_5401243_output("tbl_JOIN_INNER_TD_5401243_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_5401243_output.allocateHost();
    Table tbl_Filter_TD_5170556_output("tbl_Filter_TD_5170556_output", 6100000, 2, "");
    tbl_Filter_TD_5170556_output.allocateHost();
    Table tbl_SerializeFromObject_TD_5546898_input;
    tbl_SerializeFromObject_TD_5546898_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_5546898_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_5546898_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_5546898_input.allocateHost();
    tbl_SerializeFromObject_TD_5546898_input.loadHost();
    Table tbl_Filter_TD_6882769_output("tbl_Filter_TD_6882769_output", 6100000, 9, "");
    tbl_Filter_TD_6882769_output.allocateHost();
    Table tbl_Filter_TD_6222323_output("tbl_Filter_TD_6222323_output", 6100000, 1, "");
    tbl_Filter_TD_6222323_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6366082_input;
    tbl_SerializeFromObject_TD_6366082_input = Table("customer_address", customer_address_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_6366082_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_6366082_input.addCol("ca_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6366082_input.addCol("ca_country", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6366082_input.allocateHost();
    tbl_SerializeFromObject_TD_6366082_input.loadHost();
    Table tbl_SerializeFromObject_TD_7568957_input;
    tbl_SerializeFromObject_TD_7568957_input = Table("store_sales", store_sales_n, 9, in_dir, "orc");
    tbl_SerializeFromObject_TD_7568957_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_7568957_input.addCol("ss_cdemo_sk", 4);
    tbl_SerializeFromObject_TD_7568957_input.addCol("ss_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_7568957_input.addCol("ss_addr_sk", 4);
    tbl_SerializeFromObject_TD_7568957_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_7568957_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_7568957_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_7568957_input.addCol("ss_ext_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_7568957_input.addCol("ss_net_profit", 4);
    tbl_SerializeFromObject_TD_7568957_input.allocateHost();
    tbl_SerializeFromObject_TD_7568957_input.loadHost();
    Table tbl_SerializeFromObject_TD_7411555_input;
    tbl_SerializeFromObject_TD_7411555_input = Table("store", store_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_7411555_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_7411555_input.allocateHost();
    tbl_SerializeFromObject_TD_7411555_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_6_639540_s, tv_r_Filter_6_639540_e;
    gettimeofday(&tv_r_Filter_6_639540_s, 0);
    SW_Filter_TD_6222323(tbl_SerializeFromObject_TD_7411555_input, tbl_Filter_TD_6222323_output);
    gettimeofday(&tv_r_Filter_6_639540_e, 0);

    struct timeval tv_r_Filter_6_868943_s, tv_r_Filter_6_868943_e;
    gettimeofday(&tv_r_Filter_6_868943_s, 0);
    SW_Filter_TD_6882769(tbl_SerializeFromObject_TD_7568957_input, tbl_Filter_TD_6882769_output);
    gettimeofday(&tv_r_Filter_6_868943_e, 0);

    struct timeval tv_r_Filter_5_514757_s, tv_r_Filter_5_514757_e;
    gettimeofday(&tv_r_Filter_5_514757_s, 0);
    SW_Filter_TD_5170556(tbl_SerializeFromObject_TD_6366082_input, tbl_Filter_TD_5170556_output);
    gettimeofday(&tv_r_Filter_5_514757_e, 0);

    struct timeval tv_r_JOIN_INNER_5_334542_s, tv_r_JOIN_INNER_5_334542_e;
    gettimeofday(&tv_r_JOIN_INNER_5_334542_s, 0);
    SW_JOIN_INNER_TD_5401243(tbl_Filter_TD_6882769_output, tbl_Filter_TD_6222323_output, tbl_JOIN_INNER_TD_5401243_output);
    gettimeofday(&tv_r_JOIN_INNER_5_334542_e, 0);

    struct timeval tv_r_Filter_4_508946_s, tv_r_Filter_4_508946_e;
    gettimeofday(&tv_r_Filter_4_508946_s, 0);
    SW_Filter_TD_421869(tbl_SerializeFromObject_TD_5546898_input, tbl_Filter_TD_421869_output);
    gettimeofday(&tv_r_Filter_4_508946_e, 0);

    struct timeval tv_r_JOIN_INNER_4_827913_s, tv_r_JOIN_INNER_4_827913_e;
    gettimeofday(&tv_r_JOIN_INNER_4_827913_s, 0);
    SW_JOIN_INNER_TD_4768430(tbl_JOIN_INNER_TD_5401243_output, tbl_Filter_TD_5170556_output, tbl_JOIN_INNER_TD_4768430_output);
    gettimeofday(&tv_r_JOIN_INNER_4_827913_e, 0);

    struct timeval tv_r_Filter_3_3154_s, tv_r_Filter_3_3154_e;
    gettimeofday(&tv_r_Filter_3_3154_s, 0);
    SW_Filter_TD_3998484(tbl_SerializeFromObject_TD_4447020_input, tbl_Filter_TD_3998484_output);
    gettimeofday(&tv_r_Filter_3_3154_e, 0);

    struct timeval tv_r_JOIN_INNER_3_963712_s, tv_r_JOIN_INNER_3_963712_e;
    gettimeofday(&tv_r_JOIN_INNER_3_963712_s, 0);
    SW_JOIN_INNER_TD_3672673(tbl_JOIN_INNER_TD_4768430_output, tbl_Filter_TD_421869_output, tbl_JOIN_INNER_TD_3672673_output);
    gettimeofday(&tv_r_JOIN_INNER_3_963712_e, 0);

    struct timeval tv_r_Filter_2_777751_s, tv_r_Filter_2_777751_e;
    gettimeofday(&tv_r_Filter_2_777751_s, 0);
    SW_Filter_TD_2319273(tbl_SerializeFromObject_TD_3706291_input, tbl_Filter_TD_2319273_output);
    gettimeofday(&tv_r_Filter_2_777751_e, 0);

    struct timeval tv_r_JOIN_INNER_2_38523_s, tv_r_JOIN_INNER_2_38523_e;
    gettimeofday(&tv_r_JOIN_INNER_2_38523_s, 0);
    SW_JOIN_INNER_TD_2211379(tbl_JOIN_INNER_TD_3672673_output, tbl_Filter_TD_3998484_output, tbl_JOIN_INNER_TD_2211379_output);
    gettimeofday(&tv_r_JOIN_INNER_2_38523_e, 0);

    struct timeval tv_r_JOIN_INNER_1_835693_s, tv_r_JOIN_INNER_1_835693_e;
    gettimeofday(&tv_r_JOIN_INNER_1_835693_s, 0);
    SW_JOIN_INNER_TD_1560680(tbl_JOIN_INNER_TD_2211379_output, tbl_Filter_TD_2319273_output, tbl_JOIN_INNER_TD_1560680_output);
    gettimeofday(&tv_r_JOIN_INNER_1_835693_e, 0);

    struct timeval tv_r_Aggregate_0_169568_s, tv_r_Aggregate_0_169568_e;
    gettimeofday(&tv_r_Aggregate_0_169568_s, 0);
    SW_Aggregate_TD_0266099(tbl_JOIN_INNER_TD_1560680_output, tbl_Aggregate_TD_0266099_output);
    gettimeofday(&tv_r_Aggregate_0_169568_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_639540_s, &tv_r_Filter_6_639540_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7411555_input: " << tbl_SerializeFromObject_TD_7411555_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_868943_s, &tv_r_Filter_6_868943_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7568957_input: " << tbl_SerializeFromObject_TD_7568957_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_514757_s, &tv_r_Filter_5_514757_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6366082_input: " << tbl_SerializeFromObject_TD_6366082_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_334542_s, &tv_r_JOIN_INNER_5_334542_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6882769_output: " << tbl_Filter_TD_6882769_output.getNumRow() << " " << "tbl_Filter_TD_6222323_output: " << tbl_Filter_TD_6222323_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_508946_s, &tv_r_Filter_4_508946_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5546898_input: " << tbl_SerializeFromObject_TD_5546898_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_827913_s, &tv_r_JOIN_INNER_4_827913_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5401243_output: " << tbl_JOIN_INNER_TD_5401243_output.getNumRow() << " " << "tbl_Filter_TD_5170556_output: " << tbl_Filter_TD_5170556_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_3154_s, &tv_r_Filter_3_3154_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_4447020_input: " << tbl_SerializeFromObject_TD_4447020_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_963712_s, &tv_r_JOIN_INNER_3_963712_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4768430_output: " << tbl_JOIN_INNER_TD_4768430_output.getNumRow() << " " << "tbl_Filter_TD_421869_output: " << tbl_Filter_TD_421869_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_777751_s, &tv_r_Filter_2_777751_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3706291_input: " << tbl_SerializeFromObject_TD_3706291_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_2: " << tvdiff(&tv_r_JOIN_INNER_2_38523_s, &tv_r_JOIN_INNER_2_38523_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3672673_output: " << tbl_JOIN_INNER_TD_3672673_output.getNumRow() << " " << "tbl_Filter_TD_3998484_output: " << tbl_Filter_TD_3998484_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_1: " << tvdiff(&tv_r_JOIN_INNER_1_835693_s, &tv_r_JOIN_INNER_1_835693_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_2211379_output: " << tbl_JOIN_INNER_TD_2211379_output.getNumRow() << " " << "tbl_Filter_TD_2319273_output: " << tbl_Filter_TD_2319273_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_0: " << tvdiff(&tv_r_Aggregate_0_169568_s, &tv_r_Aggregate_0_169568_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_1560680_output: " << tbl_JOIN_INNER_TD_1560680_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 3.0818605 * 1000 << "ms" << std::endl; 
    return 0; 
}
