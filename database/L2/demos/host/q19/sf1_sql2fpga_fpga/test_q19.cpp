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

#include "cfgFunc_q19.hpp" 
#include "q19.hpp" 

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
    std::cout << "NOTE:running query #19\n."; 
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
    Table tbl_GlobalLimit_TD_0181450_output("tbl_GlobalLimit_TD_0181450_output", 6100000, 5, "");
    tbl_GlobalLimit_TD_0181450_output.allocateHost();
    Table tbl_LocalLimit_TD_1160103_output("tbl_LocalLimit_TD_1160103_output", 6100000, 5, "");
    tbl_LocalLimit_TD_1160103_output.allocateHost();
    Table tbl_Sort_TD_2305604_output("tbl_Sort_TD_2305604_output", 6100000, 5, "");
    tbl_Sort_TD_2305604_output.allocateHost();
    Table tbl_Aggregate_TD_3159577_output("tbl_Aggregate_TD_3159577_output", 6100000, 5, "");
    tbl_Aggregate_TD_3159577_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4722905_output("tbl_JOIN_INNER_TD_4722905_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_4722905_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5539659_output("tbl_JOIN_INNER_TD_5539659_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_5539659_output.allocateHost();
    Table tbl_Filter_TD_5383133_output("tbl_Filter_TD_5383133_output", 6100000, 2, "");
    tbl_Filter_TD_5383133_output.allocateHost();
    Table tbl_JOIN_INNER_TD_699556_output("tbl_JOIN_INNER_TD_699556_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_699556_output.allocateHost();
    Table tbl_Filter_TD_6707020_output("tbl_Filter_TD_6707020_output", 6100000, 2, "");
    tbl_Filter_TD_6707020_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6144669_input;
    tbl_SerializeFromObject_TD_6144669_input = Table("store", store_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_6144669_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_6144669_input.addCol("s_zip", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6144669_input.allocateHost();
    tbl_SerializeFromObject_TD_6144669_input.loadHost();
    Table tbl_JOIN_INNER_TD_7277267_output("tbl_JOIN_INNER_TD_7277267_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_7277267_output.allocateHost();
    Table tbl_Filter_TD_7506281_output("tbl_Filter_TD_7506281_output", 6100000, 2, "");
    tbl_Filter_TD_7506281_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7437376_input;
    tbl_SerializeFromObject_TD_7437376_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7437376_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_7437376_input.addCol("ca_zip", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7437376_input.allocateHost();
    tbl_SerializeFromObject_TD_7437376_input.loadHost();
    Table tbl_JOIN_INNER_TD_8358257_output("tbl_JOIN_INNER_TD_8358257_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_8358257_output.allocateHost();
    Table tbl_Filter_TD_818702_output("tbl_Filter_TD_818702_output", 6100000, 5, "");
    tbl_Filter_TD_818702_output.allocateHost();
    Table tbl_SerializeFromObject_TD_898673_input;
    tbl_SerializeFromObject_TD_898673_input = Table("customer", customer_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_898673_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_898673_input.addCol("c_current_addr_sk", 4);
    tbl_SerializeFromObject_TD_898673_input.allocateHost();
    tbl_SerializeFromObject_TD_898673_input.loadHost();
    Table tbl_Filter_TD_965544_output("tbl_Filter_TD_965544_output", 6100000, 1, "");
    tbl_Filter_TD_965544_output.allocateHost();
    Table tbl_Filter_TD_9641519_output("tbl_Filter_TD_9641519_output", 6100000, 5, "");
    tbl_Filter_TD_9641519_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9735851_input;
    tbl_SerializeFromObject_TD_9735851_input = Table("item", item_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_9735851_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_9735851_input.addCol("i_brand_id", 4);
    tbl_SerializeFromObject_TD_9735851_input.addCol("i_brand", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9735851_input.addCol("i_manufact_id", 4);
    tbl_SerializeFromObject_TD_9735851_input.addCol("i_manufact", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9735851_input.addCol("i_manager_id", 4);
    tbl_SerializeFromObject_TD_9735851_input.allocateHost();
    tbl_SerializeFromObject_TD_9735851_input.loadHost();
    Table tbl_SerializeFromObject_TD_10317571_input;
    tbl_SerializeFromObject_TD_10317571_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10317571_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10317571_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_10317571_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10317571_input.allocateHost();
    tbl_SerializeFromObject_TD_10317571_input.loadHost();
    Table tbl_SerializeFromObject_TD_10111436_input;
    tbl_SerializeFromObject_TD_10111436_input = Table("store_sales", store_sales_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_10111436_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10111436_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_10111436_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_10111436_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_10111436_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_10111436_input.allocateHost();
    tbl_SerializeFromObject_TD_10111436_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_9_870229_s, tv_r_Filter_9_870229_e;
    gettimeofday(&tv_r_Filter_9_870229_s, 0);
    SW_Filter_TD_9641519(tbl_SerializeFromObject_TD_10111436_input, tbl_Filter_TD_9641519_output);
    gettimeofday(&tv_r_Filter_9_870229_e, 0);

    struct timeval tv_r_Filter_9_347586_s, tv_r_Filter_9_347586_e;
    gettimeofday(&tv_r_Filter_9_347586_s, 0);
    SW_Filter_TD_965544(tbl_SerializeFromObject_TD_10317571_input, tbl_Filter_TD_965544_output);
    gettimeofday(&tv_r_Filter_9_347586_e, 0);

    struct timeval tv_r_Filter_8_811398_s, tv_r_Filter_8_811398_e;
    gettimeofday(&tv_r_Filter_8_811398_s, 0);
    SW_Filter_TD_818702(tbl_SerializeFromObject_TD_9735851_input, tbl_Filter_TD_818702_output);
    gettimeofday(&tv_r_Filter_8_811398_e, 0);

    struct timeval tv_r_JOIN_INNER_8_198993_s, tv_r_JOIN_INNER_8_198993_e;
    gettimeofday(&tv_r_JOIN_INNER_8_198993_s, 0);
    SW_JOIN_INNER_TD_8358257(tbl_Filter_TD_965544_output, tbl_Filter_TD_9641519_output, tbl_JOIN_INNER_TD_8358257_output);
    gettimeofday(&tv_r_JOIN_INNER_8_198993_e, 0);

    struct timeval tv_r_Filter_7_954206_s, tv_r_Filter_7_954206_e;
    gettimeofday(&tv_r_Filter_7_954206_s, 0);
    SW_Filter_TD_7506281(tbl_SerializeFromObject_TD_898673_input, tbl_Filter_TD_7506281_output);
    gettimeofday(&tv_r_Filter_7_954206_e, 0);

    struct timeval tv_r_JOIN_INNER_7_81167_s, tv_r_JOIN_INNER_7_81167_e;
    gettimeofday(&tv_r_JOIN_INNER_7_81167_s, 0);
    SW_JOIN_INNER_TD_7277267(tbl_JOIN_INNER_TD_8358257_output, tbl_Filter_TD_818702_output, tbl_JOIN_INNER_TD_7277267_output);
    gettimeofday(&tv_r_JOIN_INNER_7_81167_e, 0);

    struct timeval tv_r_Filter_6_478204_s, tv_r_Filter_6_478204_e;
    gettimeofday(&tv_r_Filter_6_478204_s, 0);
    SW_Filter_TD_6707020(tbl_SerializeFromObject_TD_7437376_input, tbl_Filter_TD_6707020_output);
    gettimeofday(&tv_r_Filter_6_478204_e, 0);

    struct timeval tv_r_JOIN_INNER_6_473264_s, tv_r_JOIN_INNER_6_473264_e;
    gettimeofday(&tv_r_JOIN_INNER_6_473264_s, 0);
    SW_JOIN_INNER_TD_699556(tbl_JOIN_INNER_TD_7277267_output, tbl_Filter_TD_7506281_output, tbl_JOIN_INNER_TD_699556_output);
    gettimeofday(&tv_r_JOIN_INNER_6_473264_e, 0);

    struct timeval tv_r_Filter_5_929654_s, tv_r_Filter_5_929654_e;
    gettimeofday(&tv_r_Filter_5_929654_s, 0);
    SW_Filter_TD_5383133(tbl_SerializeFromObject_TD_6144669_input, tbl_Filter_TD_5383133_output);
    gettimeofday(&tv_r_Filter_5_929654_e, 0);

    struct timeval tv_r_JOIN_INNER_5_430998_s, tv_r_JOIN_INNER_5_430998_e;
    gettimeofday(&tv_r_JOIN_INNER_5_430998_s, 0);
    SW_JOIN_INNER_TD_5539659(tbl_JOIN_INNER_TD_699556_output, tbl_Filter_TD_6707020_output, tbl_JOIN_INNER_TD_5539659_output);
    gettimeofday(&tv_r_JOIN_INNER_5_430998_e, 0);

    struct timeval tv_r_JOIN_INNER_4_717814_s, tv_r_JOIN_INNER_4_717814_e;
    gettimeofday(&tv_r_JOIN_INNER_4_717814_s, 0);
    SW_JOIN_INNER_TD_4722905(tbl_JOIN_INNER_TD_5539659_output, tbl_Filter_TD_5383133_output, tbl_JOIN_INNER_TD_4722905_output);
    gettimeofday(&tv_r_JOIN_INNER_4_717814_e, 0);

    struct timeval tv_r_Aggregate_3_841372_s, tv_r_Aggregate_3_841372_e;
    gettimeofday(&tv_r_Aggregate_3_841372_s, 0);
    SW_Aggregate_TD_3159577(tbl_JOIN_INNER_TD_4722905_output, tbl_Aggregate_TD_3159577_output);
    gettimeofday(&tv_r_Aggregate_3_841372_e, 0);

    struct timeval tv_r_Sort_2_679389_s, tv_r_Sort_2_679389_e;
    gettimeofday(&tv_r_Sort_2_679389_s, 0);
    SW_Sort_TD_2305604(tbl_Aggregate_TD_3159577_output, tbl_Sort_TD_2305604_output);
    gettimeofday(&tv_r_Sort_2_679389_e, 0);

    struct timeval tv_r_LocalLimit_1_934629_s, tv_r_LocalLimit_1_934629_e;
    gettimeofday(&tv_r_LocalLimit_1_934629_s, 0);
    SW_LocalLimit_TD_1160103(tbl_Sort_TD_2305604_output, tbl_LocalLimit_TD_1160103_output);
    gettimeofday(&tv_r_LocalLimit_1_934629_e, 0);

    struct timeval tv_r_GlobalLimit_0_909189_s, tv_r_GlobalLimit_0_909189_e;
    gettimeofday(&tv_r_GlobalLimit_0_909189_s, 0);
    SW_GlobalLimit_TD_0181450(tbl_LocalLimit_TD_1160103_output, tbl_GlobalLimit_TD_0181450_output);
    gettimeofday(&tv_r_GlobalLimit_0_909189_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_870229_s, &tv_r_Filter_9_870229_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10111436_input: " << tbl_SerializeFromObject_TD_10111436_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_347586_s, &tv_r_Filter_9_347586_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10317571_input: " << tbl_SerializeFromObject_TD_10317571_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_811398_s, &tv_r_Filter_8_811398_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9735851_input: " << tbl_SerializeFromObject_TD_9735851_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_198993_s, &tv_r_JOIN_INNER_8_198993_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_965544_output: " << tbl_Filter_TD_965544_output.getNumRow() << " " << "tbl_Filter_TD_9641519_output: " << tbl_Filter_TD_9641519_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_954206_s, &tv_r_Filter_7_954206_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_898673_input: " << tbl_SerializeFromObject_TD_898673_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_81167_s, &tv_r_JOIN_INNER_7_81167_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8358257_output: " << tbl_JOIN_INNER_TD_8358257_output.getNumRow() << " " << "tbl_Filter_TD_818702_output: " << tbl_Filter_TD_818702_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_478204_s, &tv_r_Filter_6_478204_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7437376_input: " << tbl_SerializeFromObject_TD_7437376_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_473264_s, &tv_r_JOIN_INNER_6_473264_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7277267_output: " << tbl_JOIN_INNER_TD_7277267_output.getNumRow() << " " << "tbl_Filter_TD_7506281_output: " << tbl_Filter_TD_7506281_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_929654_s, &tv_r_Filter_5_929654_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6144669_input: " << tbl_SerializeFromObject_TD_6144669_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_430998_s, &tv_r_JOIN_INNER_5_430998_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_699556_output: " << tbl_JOIN_INNER_TD_699556_output.getNumRow() << " " << "tbl_Filter_TD_6707020_output: " << tbl_Filter_TD_6707020_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_717814_s, &tv_r_JOIN_INNER_4_717814_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5539659_output: " << tbl_JOIN_INNER_TD_5539659_output.getNumRow() << " " << "tbl_Filter_TD_5383133_output: " << tbl_Filter_TD_5383133_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_841372_s, &tv_r_Aggregate_3_841372_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4722905_output: " << tbl_JOIN_INNER_TD_4722905_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_679389_s, &tv_r_Sort_2_679389_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3159577_output: " << tbl_Aggregate_TD_3159577_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_934629_s, &tv_r_LocalLimit_1_934629_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2305604_output: " << tbl_Sort_TD_2305604_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_909189_s, &tv_r_GlobalLimit_0_909189_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1160103_output: " << tbl_LocalLimit_TD_1160103_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.5953498 * 1000 << "ms" << std::endl; 
    return 0; 
}
