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

#include "cfgFunc_q8.hpp" 
#include "q8.hpp" 

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
    std::cout << "NOTE:running query #8\n."; 
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
    Table tbl_GlobalLimit_TD_0995574_output("tbl_GlobalLimit_TD_0995574_output", 6100000, 2, "");
    tbl_GlobalLimit_TD_0995574_output.allocateHost();
    Table tbl_LocalLimit_TD_1126508_output("tbl_LocalLimit_TD_1126508_output", 6100000, 2, "");
    tbl_LocalLimit_TD_1126508_output.allocateHost();
    Table tbl_Sort_TD_2661167_output("tbl_Sort_TD_2661167_output", 6100000, 2, "");
    tbl_Sort_TD_2661167_output.allocateHost();
    Table tbl_Aggregate_TD_3858525_output("tbl_Aggregate_TD_3858525_output", 6100000, 2, "");
    tbl_Aggregate_TD_3858525_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4637194_output("tbl_JOIN_INNER_TD_4637194_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_4637194_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5798898_output("tbl_JOIN_INNER_TD_5798898_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_5798898_output.allocateHost();
    Table tbl_Aggregate_TD_5823112_output("tbl_Aggregate_TD_5823112_output", 6100000, 1, "");
    tbl_Aggregate_TD_5823112_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6582286_output("tbl_JOIN_INNER_TD_6582286_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_6582286_output.allocateHost();
    Table tbl_Filter_TD_6724151_output("tbl_Filter_TD_6724151_output", 6100000, 3, "");
    tbl_Filter_TD_6724151_output.allocateHost();
    Table tbl_Project_TD_6630930_output("tbl_Project_TD_6630930_output", 6100000, 1, "");
    tbl_Project_TD_6630930_output.allocateHost();
    Table tbl_Filter_TD_7892264_output("tbl_Filter_TD_7892264_output", 6100000, 3, "");
    tbl_Filter_TD_7892264_output.allocateHost();
    Table tbl_Filter_TD_7308976_output("tbl_Filter_TD_7308976_output", 6100000, 1, "");
    tbl_Filter_TD_7308976_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7375910_input;
    tbl_SerializeFromObject_TD_7375910_input = Table("store", store_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7375910_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_7375910_input.addCol("s_store_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7375910_input.addCol("s_zip", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7375910_input.allocateHost();
    tbl_SerializeFromObject_TD_7375910_input.loadHost();
    Table tbl_JOIN_LEFTSEMI_TD_7583863_output("tbl_JOIN_LEFTSEMI_TD_7583863_output", 6100000, 1, "");
    tbl_JOIN_LEFTSEMI_TD_7583863_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8432298_input;
    tbl_SerializeFromObject_TD_8432298_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8432298_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_8432298_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_8432298_input.addCol("ss_net_profit", 4);
    tbl_SerializeFromObject_TD_8432298_input.allocateHost();
    tbl_SerializeFromObject_TD_8432298_input.loadHost();
    Table tbl_SerializeFromObject_TD_8881453_input;
    tbl_SerializeFromObject_TD_8881453_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8881453_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_8881453_input.addCol("d_qoy", 4);
    tbl_SerializeFromObject_TD_8881453_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_8881453_input.allocateHost();
    tbl_SerializeFromObject_TD_8881453_input.loadHost();
    Table tbl_Filter_TD_8626150_output("tbl_Filter_TD_8626150_output", 6100000, 1, "");
    tbl_Filter_TD_8626150_output.allocateHost();
    Table tbl_Filter_TD_8776660_output("tbl_Filter_TD_8776660_output", 6100000, 1, "");
    tbl_Filter_TD_8776660_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9902922_input;
    tbl_SerializeFromObject_TD_9902922_input = Table("customer_address", customer_address_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_9902922_input.addCol("ca_zip", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9902922_input.allocateHost();
    tbl_SerializeFromObject_TD_9902922_input.loadHost();
    Table tbl_Aggregate_TD_9125763_output("tbl_Aggregate_TD_9125763_output", 6100000, 2, "");
    tbl_Aggregate_TD_9125763_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10333873_output("tbl_JOIN_INNER_TD_10333873_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_10333873_output.allocateHost();
    Table tbl_Filter_TD_11602729_output("tbl_Filter_TD_11602729_output", 6100000, 2, "");
    tbl_Filter_TD_11602729_output.allocateHost();
    Table tbl_Filter_TD_11851119_output("tbl_Filter_TD_11851119_output", 6100000, 1, "");
    tbl_Filter_TD_11851119_output.allocateHost();
    Table tbl_SerializeFromObject_TD_12362469_input;
    tbl_SerializeFromObject_TD_12362469_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12362469_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_12362469_input.addCol("ca_zip", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_12362469_input.allocateHost();
    tbl_SerializeFromObject_TD_12362469_input.loadHost();
    Table tbl_SerializeFromObject_TD_12368307_input;
    tbl_SerializeFromObject_TD_12368307_input = Table("customer", customer_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12368307_input.addCol("c_current_addr_sk", 4);
    tbl_SerializeFromObject_TD_12368307_input.addCol("c_preferred_cust_flag", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_12368307_input.allocateHost();
    tbl_SerializeFromObject_TD_12368307_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_11_296284_s, tv_r_Filter_11_296284_e;
    gettimeofday(&tv_r_Filter_11_296284_s, 0);
    SW_Filter_TD_11851119(tbl_SerializeFromObject_TD_12368307_input, tbl_Filter_TD_11851119_output);
    gettimeofday(&tv_r_Filter_11_296284_e, 0);

    struct timeval tv_r_Filter_11_685707_s, tv_r_Filter_11_685707_e;
    gettimeofday(&tv_r_Filter_11_685707_s, 0);
    SW_Filter_TD_11602729(tbl_SerializeFromObject_TD_12362469_input, tbl_Filter_TD_11602729_output);
    gettimeofday(&tv_r_Filter_11_685707_e, 0);

    struct timeval tv_r_JOIN_INNER_10_749231_s, tv_r_JOIN_INNER_10_749231_e;
    gettimeofday(&tv_r_JOIN_INNER_10_749231_s, 0);
    SW_JOIN_INNER_TD_10333873(tbl_Filter_TD_11602729_output, tbl_Filter_TD_11851119_output, tbl_JOIN_INNER_TD_10333873_output);
    gettimeofday(&tv_r_JOIN_INNER_10_749231_e, 0);

    struct timeval tv_r_Aggregate_9_894295_s, tv_r_Aggregate_9_894295_e;
    gettimeofday(&tv_r_Aggregate_9_894295_s, 0);
    SW_Aggregate_TD_9125763(tbl_JOIN_INNER_TD_10333873_output, tbl_Aggregate_TD_9125763_output);
    gettimeofday(&tv_r_Aggregate_9_894295_e, 0);

    struct timeval tv_r_Filter_8_918875_s, tv_r_Filter_8_918875_e;
    gettimeofday(&tv_r_Filter_8_918875_s, 0);
    SW_Filter_TD_8776660(tbl_Aggregate_TD_9125763_output, tbl_Filter_TD_8776660_output);
    gettimeofday(&tv_r_Filter_8_918875_e, 0);

    struct timeval tv_r_Filter_8_609236_s, tv_r_Filter_8_609236_e;
    gettimeofday(&tv_r_Filter_8_609236_s, 0);
    SW_Filter_TD_8626150(tbl_SerializeFromObject_TD_9902922_input, tbl_Filter_TD_8626150_output);
    gettimeofday(&tv_r_Filter_8_609236_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_7_652424_s, tv_r_JOIN_LEFTSEMI_7_652424_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_652424_s, 0);
    SW_JOIN_LEFTSEMI_TD_7583863(tbl_Filter_TD_8626150_output, tbl_Filter_TD_8776660_output, tbl_JOIN_LEFTSEMI_TD_7583863_output);
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_652424_e, 0);

    struct timeval tv_r_Filter_7_546737_s, tv_r_Filter_7_546737_e;
    gettimeofday(&tv_r_Filter_7_546737_s, 0);
    SW_Filter_TD_7308976(tbl_SerializeFromObject_TD_8881453_input, tbl_Filter_TD_7308976_output);
    gettimeofday(&tv_r_Filter_7_546737_e, 0);

    struct timeval tv_r_Filter_7_434538_s, tv_r_Filter_7_434538_e;
    gettimeofday(&tv_r_Filter_7_434538_s, 0);
    SW_Filter_TD_7892264(tbl_SerializeFromObject_TD_8432298_input, tbl_Filter_TD_7892264_output);
    gettimeofday(&tv_r_Filter_7_434538_e, 0);

    struct timeval tv_r_Project_6_990553_s, tv_r_Project_6_990553_e;
    gettimeofday(&tv_r_Project_6_990553_s, 0);
    SW_Project_TD_6630930(tbl_JOIN_LEFTSEMI_TD_7583863_output, tbl_Project_TD_6630930_output);
    gettimeofday(&tv_r_Project_6_990553_e, 0);

    struct timeval tv_r_Filter_6_96301_s, tv_r_Filter_6_96301_e;
    gettimeofday(&tv_r_Filter_6_96301_s, 0);
    SW_Filter_TD_6724151(tbl_SerializeFromObject_TD_7375910_input, tbl_Filter_TD_6724151_output);
    gettimeofday(&tv_r_Filter_6_96301_e, 0);

    struct timeval tv_r_JOIN_INNER_6_986634_s, tv_r_JOIN_INNER_6_986634_e;
    gettimeofday(&tv_r_JOIN_INNER_6_986634_s, 0);
    SW_JOIN_INNER_TD_6582286(tbl_Filter_TD_7892264_output, tbl_Filter_TD_7308976_output, tbl_JOIN_INNER_TD_6582286_output);
    gettimeofday(&tv_r_JOIN_INNER_6_986634_e, 0);

    struct timeval tv_r_Aggregate_5_602587_s, tv_r_Aggregate_5_602587_e;
    gettimeofday(&tv_r_Aggregate_5_602587_s, 0);
    SW_Aggregate_TD_5823112(tbl_Project_TD_6630930_output, tbl_Aggregate_TD_5823112_output);
    gettimeofday(&tv_r_Aggregate_5_602587_e, 0);

    struct timeval tv_r_JOIN_INNER_5_7833_s, tv_r_JOIN_INNER_5_7833_e;
    gettimeofday(&tv_r_JOIN_INNER_5_7833_s, 0);
    SW_JOIN_INNER_TD_5798898(tbl_JOIN_INNER_TD_6582286_output, tbl_Filter_TD_6724151_output, tbl_JOIN_INNER_TD_5798898_output);
    gettimeofday(&tv_r_JOIN_INNER_5_7833_e, 0);

    struct timeval tv_r_JOIN_INNER_4_54978_s, tv_r_JOIN_INNER_4_54978_e;
    gettimeofday(&tv_r_JOIN_INNER_4_54978_s, 0);
    SW_JOIN_INNER_TD_4637194(tbl_JOIN_INNER_TD_5798898_output, tbl_Aggregate_TD_5823112_output, tbl_JOIN_INNER_TD_4637194_output);
    gettimeofday(&tv_r_JOIN_INNER_4_54978_e, 0);

    struct timeval tv_r_Aggregate_3_456719_s, tv_r_Aggregate_3_456719_e;
    gettimeofday(&tv_r_Aggregate_3_456719_s, 0);
    SW_Aggregate_TD_3858525(tbl_JOIN_INNER_TD_4637194_output, tbl_Aggregate_TD_3858525_output);
    gettimeofday(&tv_r_Aggregate_3_456719_e, 0);

    struct timeval tv_r_Sort_2_589115_s, tv_r_Sort_2_589115_e;
    gettimeofday(&tv_r_Sort_2_589115_s, 0);
    SW_Sort_TD_2661167(tbl_Aggregate_TD_3858525_output, tbl_Sort_TD_2661167_output);
    gettimeofday(&tv_r_Sort_2_589115_e, 0);

    struct timeval tv_r_LocalLimit_1_369910_s, tv_r_LocalLimit_1_369910_e;
    gettimeofday(&tv_r_LocalLimit_1_369910_s, 0);
    SW_LocalLimit_TD_1126508(tbl_Sort_TD_2661167_output, tbl_LocalLimit_TD_1126508_output);
    gettimeofday(&tv_r_LocalLimit_1_369910_e, 0);

    struct timeval tv_r_GlobalLimit_0_648347_s, tv_r_GlobalLimit_0_648347_e;
    gettimeofday(&tv_r_GlobalLimit_0_648347_s, 0);
    SW_GlobalLimit_TD_0995574(tbl_LocalLimit_TD_1126508_output, tbl_GlobalLimit_TD_0995574_output);
    gettimeofday(&tv_r_GlobalLimit_0_648347_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_296284_s, &tv_r_Filter_11_296284_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12368307_input: " << tbl_SerializeFromObject_TD_12368307_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_685707_s, &tv_r_Filter_11_685707_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12362469_input: " << tbl_SerializeFromObject_TD_12362469_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_749231_s, &tv_r_JOIN_INNER_10_749231_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11602729_output: " << tbl_Filter_TD_11602729_output.getNumRow() << " " << "tbl_Filter_TD_11851119_output: " << tbl_Filter_TD_11851119_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_9: " << tvdiff(&tv_r_Aggregate_9_894295_s, &tv_r_Aggregate_9_894295_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10333873_output: " << tbl_JOIN_INNER_TD_10333873_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_918875_s, &tv_r_Filter_8_918875_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_9125763_output: " << tbl_Aggregate_TD_9125763_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_609236_s, &tv_r_Filter_8_609236_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9902922_input: " << tbl_SerializeFromObject_TD_9902922_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_7: " << tvdiff(&tv_r_JOIN_LEFTSEMI_7_652424_s, &tv_r_JOIN_LEFTSEMI_7_652424_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8626150_output: " << tbl_Filter_TD_8626150_output.getNumRow() << " " << "tbl_Filter_TD_8776660_output: " << tbl_Filter_TD_8776660_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_546737_s, &tv_r_Filter_7_546737_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8881453_input: " << tbl_SerializeFromObject_TD_8881453_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_434538_s, &tv_r_Filter_7_434538_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8432298_input: " << tbl_SerializeFromObject_TD_8432298_input.getNumRow() << " " << std::endl; 

    std::cout << "Project_6: " << tvdiff(&tv_r_Project_6_990553_s, &tv_r_Project_6_990553_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTSEMI_TD_7583863_output: " << tbl_JOIN_LEFTSEMI_TD_7583863_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_96301_s, &tv_r_Filter_6_96301_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7375910_input: " << tbl_SerializeFromObject_TD_7375910_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_986634_s, &tv_r_JOIN_INNER_6_986634_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_7892264_output: " << tbl_Filter_TD_7892264_output.getNumRow() << " " << "tbl_Filter_TD_7308976_output: " << tbl_Filter_TD_7308976_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_602587_s, &tv_r_Aggregate_5_602587_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_6630930_output: " << tbl_Project_TD_6630930_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_7833_s, &tv_r_JOIN_INNER_5_7833_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6582286_output: " << tbl_JOIN_INNER_TD_6582286_output.getNumRow() << " " << "tbl_Filter_TD_6724151_output: " << tbl_Filter_TD_6724151_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_54978_s, &tv_r_JOIN_INNER_4_54978_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5798898_output: " << tbl_JOIN_INNER_TD_5798898_output.getNumRow() << " " << "tbl_Aggregate_TD_5823112_output: " << tbl_Aggregate_TD_5823112_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_456719_s, &tv_r_Aggregate_3_456719_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4637194_output: " << tbl_JOIN_INNER_TD_4637194_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_589115_s, &tv_r_Sort_2_589115_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3858525_output: " << tbl_Aggregate_TD_3858525_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_369910_s, &tv_r_LocalLimit_1_369910_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2661167_output: " << tbl_Sort_TD_2661167_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_648347_s, &tv_r_GlobalLimit_0_648347_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1126508_output: " << tbl_LocalLimit_TD_1126508_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 96.526794 * 1000 << "ms" << std::endl; 
    return 0; 
}
