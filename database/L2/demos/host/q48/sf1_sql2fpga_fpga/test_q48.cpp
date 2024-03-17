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

#include "cfgFunc_q48.hpp" 
#include "q48.hpp" 

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
    std::cout << "NOTE:running query #48\n."; 
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
    Table tbl_Aggregate_TD_0670688_output("tbl_Aggregate_TD_0670688_output", 6100000, 1, "");
    tbl_Aggregate_TD_0670688_output.allocateHost();
    Table tbl_JOIN_INNER_TD_1833252_output("tbl_JOIN_INNER_TD_1833252_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_1833252_output.allocateHost();
    Table tbl_JOIN_INNER_TD_269188_output("tbl_JOIN_INNER_TD_269188_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_269188_output.allocateHost();
    Table tbl_Filter_TD_2957694_output("tbl_Filter_TD_2957694_output", 6100000, 1, "");
    tbl_Filter_TD_2957694_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3645887_output("tbl_JOIN_INNER_TD_3645887_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_3645887_output.allocateHost();
    Table tbl_Filter_TD_3502655_output("tbl_Filter_TD_3502655_output", 6100000, 2, "");
    tbl_Filter_TD_3502655_output.allocateHost();
    Table tbl_SerializeFromObject_TD_3325149_input;
    tbl_SerializeFromObject_TD_3325149_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_3325149_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_3325149_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_3325149_input.allocateHost();
    tbl_SerializeFromObject_TD_3325149_input.loadHost();
    Table tbl_JOIN_INNER_TD_4339933_output("tbl_JOIN_INNER_TD_4339933_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_4339933_output.allocateHost();
    Table tbl_Filter_TD_456302_output("tbl_Filter_TD_456302_output", 6100000, 1, "");
    tbl_Filter_TD_456302_output.allocateHost();
    Table tbl_SerializeFromObject_TD_4871625_input;
    tbl_SerializeFromObject_TD_4871625_input = Table("customer_address", customer_address_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_4871625_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_4871625_input.addCol("ca_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_4871625_input.addCol("ca_country", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_4871625_input.allocateHost();
    tbl_SerializeFromObject_TD_4871625_input.loadHost();
    Table tbl_Filter_TD_5289871_output("tbl_Filter_TD_5289871_output", 6100000, 6, "");
    tbl_Filter_TD_5289871_output.allocateHost();
    Table tbl_Filter_TD_5163331_output("tbl_Filter_TD_5163331_output", 6100000, 1, "");
    tbl_Filter_TD_5163331_output.allocateHost();
    Table tbl_SerializeFromObject_TD_5456146_input;
    tbl_SerializeFromObject_TD_5456146_input = Table("customer_demographics", customer_demographics_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_5456146_input.addCol("cd_demo_sk", 4);
    tbl_SerializeFromObject_TD_5456146_input.addCol("cd_marital_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_5456146_input.addCol("cd_education_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_5456146_input.allocateHost();
    tbl_SerializeFromObject_TD_5456146_input.loadHost();
    Table tbl_SerializeFromObject_TD_6722378_input;
    tbl_SerializeFromObject_TD_6722378_input = Table("store_sales", store_sales_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_6722378_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_6722378_input.addCol("ss_cdemo_sk", 4);
    tbl_SerializeFromObject_TD_6722378_input.addCol("ss_addr_sk", 4);
    tbl_SerializeFromObject_TD_6722378_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_6722378_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_6722378_input.addCol("ss_net_profit", 4);
    tbl_SerializeFromObject_TD_6722378_input.allocateHost();
    tbl_SerializeFromObject_TD_6722378_input.loadHost();
    Table tbl_SerializeFromObject_TD_6261022_input;
    tbl_SerializeFromObject_TD_6261022_input = Table("store", store_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_6261022_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_6261022_input.allocateHost();
    tbl_SerializeFromObject_TD_6261022_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_5_625428_s, tv_r_Filter_5_625428_e;
    gettimeofday(&tv_r_Filter_5_625428_s, 0);
    SW_Filter_TD_5163331(tbl_SerializeFromObject_TD_6261022_input, tbl_Filter_TD_5163331_output);
    gettimeofday(&tv_r_Filter_5_625428_e, 0);

    struct timeval tv_r_Filter_5_693232_s, tv_r_Filter_5_693232_e;
    gettimeofday(&tv_r_Filter_5_693232_s, 0);
    SW_Filter_TD_5289871(tbl_SerializeFromObject_TD_6722378_input, tbl_Filter_TD_5289871_output);
    gettimeofday(&tv_r_Filter_5_693232_e, 0);

    struct timeval tv_r_Filter_4_196527_s, tv_r_Filter_4_196527_e;
    gettimeofday(&tv_r_Filter_4_196527_s, 0);
    SW_Filter_TD_456302(tbl_SerializeFromObject_TD_5456146_input, tbl_Filter_TD_456302_output);
    gettimeofday(&tv_r_Filter_4_196527_e, 0);

    struct timeval tv_r_JOIN_INNER_4_136390_s, tv_r_JOIN_INNER_4_136390_e;
    gettimeofday(&tv_r_JOIN_INNER_4_136390_s, 0);
    SW_JOIN_INNER_TD_4339933(tbl_Filter_TD_5289871_output, tbl_Filter_TD_5163331_output, tbl_JOIN_INNER_TD_4339933_output);
    gettimeofday(&tv_r_JOIN_INNER_4_136390_e, 0);

    struct timeval tv_r_Filter_3_310322_s, tv_r_Filter_3_310322_e;
    gettimeofday(&tv_r_Filter_3_310322_s, 0);
    SW_Filter_TD_3502655(tbl_SerializeFromObject_TD_4871625_input, tbl_Filter_TD_3502655_output);
    gettimeofday(&tv_r_Filter_3_310322_e, 0);

    struct timeval tv_r_JOIN_INNER_3_655344_s, tv_r_JOIN_INNER_3_655344_e;
    gettimeofday(&tv_r_JOIN_INNER_3_655344_s, 0);
    SW_JOIN_INNER_TD_3645887(tbl_JOIN_INNER_TD_4339933_output, tbl_Filter_TD_456302_output, tbl_JOIN_INNER_TD_3645887_output);
    gettimeofday(&tv_r_JOIN_INNER_3_655344_e, 0);

    struct timeval tv_r_Filter_2_617600_s, tv_r_Filter_2_617600_e;
    gettimeofday(&tv_r_Filter_2_617600_s, 0);
    SW_Filter_TD_2957694(tbl_SerializeFromObject_TD_3325149_input, tbl_Filter_TD_2957694_output);
    gettimeofday(&tv_r_Filter_2_617600_e, 0);

    struct timeval tv_r_JOIN_INNER_2_534363_s, tv_r_JOIN_INNER_2_534363_e;
    gettimeofday(&tv_r_JOIN_INNER_2_534363_s, 0);
    SW_JOIN_INNER_TD_269188(tbl_JOIN_INNER_TD_3645887_output, tbl_Filter_TD_3502655_output, tbl_JOIN_INNER_TD_269188_output);
    gettimeofday(&tv_r_JOIN_INNER_2_534363_e, 0);

    struct timeval tv_r_JOIN_INNER_1_13115_s, tv_r_JOIN_INNER_1_13115_e;
    gettimeofday(&tv_r_JOIN_INNER_1_13115_s, 0);
    SW_JOIN_INNER_TD_1833252(tbl_JOIN_INNER_TD_269188_output, tbl_Filter_TD_2957694_output, tbl_JOIN_INNER_TD_1833252_output);
    gettimeofday(&tv_r_JOIN_INNER_1_13115_e, 0);

    struct timeval tv_r_Aggregate_0_542580_s, tv_r_Aggregate_0_542580_e;
    gettimeofday(&tv_r_Aggregate_0_542580_s, 0);
    SW_Aggregate_TD_0670688(tbl_JOIN_INNER_TD_1833252_output, tbl_Aggregate_TD_0670688_output);
    gettimeofday(&tv_r_Aggregate_0_542580_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_625428_s, &tv_r_Filter_5_625428_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6261022_input: " << tbl_SerializeFromObject_TD_6261022_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_693232_s, &tv_r_Filter_5_693232_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6722378_input: " << tbl_SerializeFromObject_TD_6722378_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_196527_s, &tv_r_Filter_4_196527_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5456146_input: " << tbl_SerializeFromObject_TD_5456146_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_136390_s, &tv_r_JOIN_INNER_4_136390_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_5289871_output: " << tbl_Filter_TD_5289871_output.getNumRow() << " " << "tbl_Filter_TD_5163331_output: " << tbl_Filter_TD_5163331_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_310322_s, &tv_r_Filter_3_310322_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_4871625_input: " << tbl_SerializeFromObject_TD_4871625_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_655344_s, &tv_r_JOIN_INNER_3_655344_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4339933_output: " << tbl_JOIN_INNER_TD_4339933_output.getNumRow() << " " << "tbl_Filter_TD_456302_output: " << tbl_Filter_TD_456302_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_617600_s, &tv_r_Filter_2_617600_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3325149_input: " << tbl_SerializeFromObject_TD_3325149_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_2: " << tvdiff(&tv_r_JOIN_INNER_2_534363_s, &tv_r_JOIN_INNER_2_534363_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3645887_output: " << tbl_JOIN_INNER_TD_3645887_output.getNumRow() << " " << "tbl_Filter_TD_3502655_output: " << tbl_Filter_TD_3502655_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_1: " << tvdiff(&tv_r_JOIN_INNER_1_13115_s, &tv_r_JOIN_INNER_1_13115_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_269188_output: " << tbl_JOIN_INNER_TD_269188_output.getNumRow() << " " << "tbl_Filter_TD_2957694_output: " << tbl_Filter_TD_2957694_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_0: " << tvdiff(&tv_r_Aggregate_0_542580_s, &tv_r_Aggregate_0_542580_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_1833252_output: " << tbl_JOIN_INNER_TD_1833252_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.7303035 * 1000 << "ms" << std::endl; 
    return 0; 
}
