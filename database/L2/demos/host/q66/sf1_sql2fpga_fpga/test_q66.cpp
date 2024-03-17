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

#include "cfgFunc_q66.hpp" 
#include "q66.hpp" 

int main(int argc, const char* argv[]) { 
    std::cout << "\n------------ TPC-H Query Test -------------\n"; 
    ArgParser parser(argc, argv); 
    std::string xclbin_path; 
    if (!parser.getCmdOption("-xclbin", xclbin_path)) { 
        std::cout << "ERROR: xclbin path is not set!\n"; 
        return 1; 
    } 
    std::string xclbin_path_h; 
    if (!parser.getCmdOption("-xclbin_h", xclbin_path_h)) { 
        std::cout << "ERROR: xclbin_h path is not set!\n"; 
        return 1; 
    } 
    std::string xclbin_path_a; 
    if (!parser.getCmdOption("-xclbin_a", xclbin_path_a)) { 
        std::cout << "ERROR: xclbin_a path is not set!\n"; 
        return 1; 
    } 
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
    std::cout << "NOTE:running query #66\n."; 
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
    // Get CL devices. 
    std::vector<cl::Device> devices = xcl::get_xil_devices(); 
    // ****************************** Tables **************************** // 
    Table tbl_GlobalLimit_TD_04967_output("tbl_GlobalLimit_TD_04967_output", 6100000, 44, "");
    tbl_GlobalLimit_TD_04967_output.allocateHost();
    Table tbl_LocalLimit_TD_137350_output("tbl_LocalLimit_TD_137350_output", 6100000, 44, "");
    tbl_LocalLimit_TD_137350_output.allocateHost();
    Table tbl_Sort_TD_2704870_output("tbl_Sort_TD_2704870_output", 6100000, 44, "");
    tbl_Sort_TD_2704870_output.allocateHost();
    Table tbl_Aggregate_TD_3248653_output("tbl_Aggregate_TD_3248653_output", 6100000, 44, "");
    tbl_Aggregate_TD_3248653_output.allocateHost();
    Table tbl_Union_TD_4183185_output("tbl_Union_TD_4183185_output", 6100000, 32, "");
    tbl_Union_TD_4183185_output.allocateHost();
    Table tbl_Aggregate_TD_5195105_output("tbl_Aggregate_TD_5195105_output", 6100000, 32, "");
    tbl_Aggregate_TD_5195105_output.allocateHost();
    Table tbl_Aggregate_TD_5572054_output("tbl_Aggregate_TD_5572054_output", 6100000, 32, "");
    tbl_Aggregate_TD_5572054_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6461642_output("tbl_JOIN_INNER_TD_6461642_output", 6100000, 11, "");
    tbl_JOIN_INNER_TD_6461642_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6705937_output("tbl_JOIN_INNER_TD_6705937_output", 6100000, 11, "");
    tbl_JOIN_INNER_TD_6705937_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7362851_output("tbl_JOIN_INNER_TD_7362851_output", 6100000, 12, "");
    tbl_JOIN_INNER_TD_7362851_output.allocateHost();
    Table tbl_Filter_TD_748969_output("tbl_Filter_TD_748969_output", 6100000, 1, "");
    tbl_Filter_TD_748969_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7312336_output("tbl_JOIN_INNER_TD_7312336_output", 6100000, 12, "");
    tbl_JOIN_INNER_TD_7312336_output.allocateHost();
    Table tbl_Filter_TD_7222045_output("tbl_Filter_TD_7222045_output", 6100000, 1, "");
    tbl_Filter_TD_7222045_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8505770_output("tbl_JOIN_INNER_TD_8505770_output", 6100000, 13, "");
    tbl_JOIN_INNER_TD_8505770_output.allocateHost();
    Table tbl_Filter_TD_888970_output("tbl_Filter_TD_888970_output", 6100000, 1, "");
    tbl_Filter_TD_888970_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8473429_input;
    tbl_SerializeFromObject_TD_8473429_input = Table("ship_mode", ship_mode_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8473429_input.addCol("sm_ship_mode_sk", 4);
    tbl_SerializeFromObject_TD_8473429_input.addCol("sm_carrier", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8473429_input.allocateHost();
    tbl_SerializeFromObject_TD_8473429_input.loadHost();
    Table tbl_JOIN_INNER_TD_8907863_output("tbl_JOIN_INNER_TD_8907863_output", 6100000, 13, "");
    tbl_JOIN_INNER_TD_8907863_output.allocateHost();
    Table tbl_Filter_TD_8812878_output("tbl_Filter_TD_8812878_output", 6100000, 1, "");
    tbl_Filter_TD_8812878_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8701910_input;
    tbl_SerializeFromObject_TD_8701910_input = Table("ship_mode", ship_mode_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8701910_input.addCol("sm_ship_mode_sk", 4);
    tbl_SerializeFromObject_TD_8701910_input.addCol("sm_carrier", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8701910_input.allocateHost();
    tbl_SerializeFromObject_TD_8701910_input.loadHost();
    Table tbl_JOIN_INNER_TD_9942357_output("tbl_JOIN_INNER_TD_9942357_output", 6100000, 12, "");
    tbl_JOIN_INNER_TD_9942357_output.allocateHost();
    Table tbl_Filter_TD_9609467_output("tbl_Filter_TD_9609467_output", 6100000, 3, "");
    tbl_Filter_TD_9609467_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9953389_input;
    tbl_SerializeFromObject_TD_9953389_input = Table("time_dim", time_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9953389_input.addCol("t_time_sk", 4);
    tbl_SerializeFromObject_TD_9953389_input.addCol("t_time", 4);
    tbl_SerializeFromObject_TD_9953389_input.allocateHost();
    tbl_SerializeFromObject_TD_9953389_input.loadHost();
    Table tbl_JOIN_INNER_TD_9386501_output("tbl_JOIN_INNER_TD_9386501_output", 6100000, 12, "");
    tbl_JOIN_INNER_TD_9386501_output.allocateHost();
    Table tbl_Filter_TD_9220854_output("tbl_Filter_TD_9220854_output", 6100000, 3, "");
    tbl_Filter_TD_9220854_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9783073_input;
    tbl_SerializeFromObject_TD_9783073_input = Table("time_dim", time_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9783073_input.addCol("t_time_sk", 4);
    tbl_SerializeFromObject_TD_9783073_input.addCol("t_time", 4);
    tbl_SerializeFromObject_TD_9783073_input.allocateHost();
    tbl_SerializeFromObject_TD_9783073_input.loadHost();
    Table tbl_Filter_TD_10567282_output("tbl_Filter_TD_10567282_output", 6100000, 7, "");
    tbl_Filter_TD_10567282_output.allocateHost();
    Table tbl_Filter_TD_10138559_output("tbl_Filter_TD_10138559_output", 6100000, 7, "");
    tbl_Filter_TD_10138559_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10715200_input;
    tbl_SerializeFromObject_TD_10715200_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10715200_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10715200_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10715200_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_10715200_input.allocateHost();
    tbl_SerializeFromObject_TD_10715200_input.loadHost();
    Table tbl_Filter_TD_1048090_output("tbl_Filter_TD_1048090_output", 6100000, 7, "");
    tbl_Filter_TD_1048090_output.allocateHost();
    Table tbl_Filter_TD_1054168_output("tbl_Filter_TD_1054168_output", 6100000, 7, "");
    tbl_Filter_TD_1054168_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10448007_input;
    tbl_SerializeFromObject_TD_10448007_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10448007_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10448007_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10448007_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_10448007_input.allocateHost();
    tbl_SerializeFromObject_TD_10448007_input.loadHost();
    Table tbl_SerializeFromObject_TD_11725552_input;
    tbl_SerializeFromObject_TD_11725552_input = Table("web_sales", web_sales_n, 7, in_dir, "orc");
    tbl_SerializeFromObject_TD_11725552_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_11725552_input.addCol("ws_sold_time_sk", 4);
    tbl_SerializeFromObject_TD_11725552_input.addCol("ws_ship_mode_sk", 4);
    tbl_SerializeFromObject_TD_11725552_input.addCol("ws_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_11725552_input.addCol("ws_quantity", 4);
    tbl_SerializeFromObject_TD_11725552_input.addCol("ws_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_11725552_input.addCol("ws_net_paid", 4);
    tbl_SerializeFromObject_TD_11725552_input.allocateHost();
    tbl_SerializeFromObject_TD_11725552_input.loadHost();
    Table tbl_SerializeFromObject_TD_11232543_input;
    tbl_SerializeFromObject_TD_11232543_input = Table("warehouse", warehouse_n, 7, in_dir, "orc");
    tbl_SerializeFromObject_TD_11232543_input.addCol("w_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_11232543_input.addCol("w_warehouse_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11232543_input.addCol("w_warehouse_sq_ft", 4);
    tbl_SerializeFromObject_TD_11232543_input.addCol("w_city", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11232543_input.addCol("w_county", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11232543_input.addCol("w_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11232543_input.addCol("w_country", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11232543_input.allocateHost();
    tbl_SerializeFromObject_TD_11232543_input.loadHost();
    Table tbl_SerializeFromObject_TD_11702404_input;
    tbl_SerializeFromObject_TD_11702404_input = Table("catalog_sales", catalog_sales_n, 7, in_dir, "orc");
    tbl_SerializeFromObject_TD_11702404_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_11702404_input.addCol("cs_sold_time_sk", 4);
    tbl_SerializeFromObject_TD_11702404_input.addCol("cs_ship_mode_sk", 4);
    tbl_SerializeFromObject_TD_11702404_input.addCol("cs_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_11702404_input.addCol("cs_quantity", 4);
    tbl_SerializeFromObject_TD_11702404_input.addCol("cs_sales_price", 4);
    tbl_SerializeFromObject_TD_11702404_input.addCol("cs_net_paid_inc_tax", 4);
    tbl_SerializeFromObject_TD_11702404_input.allocateHost();
    tbl_SerializeFromObject_TD_11702404_input.loadHost();
    Table tbl_SerializeFromObject_TD_11544265_input;
    tbl_SerializeFromObject_TD_11544265_input = Table("warehouse", warehouse_n, 7, in_dir, "orc");
    tbl_SerializeFromObject_TD_11544265_input.addCol("w_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_11544265_input.addCol("w_warehouse_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11544265_input.addCol("w_warehouse_sq_ft", 4);
    tbl_SerializeFromObject_TD_11544265_input.addCol("w_city", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11544265_input.addCol("w_county", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11544265_input.addCol("w_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11544265_input.addCol("w_country", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11544265_input.allocateHost();
    tbl_SerializeFromObject_TD_11544265_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    std::cout << std::endl; 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_10_378966_s, tv_r_Filter_10_378966_e;
    gettimeofday(&tv_r_Filter_10_378966_s, 0);
    SW_Filter_TD_1054168(tbl_SerializeFromObject_TD_11544265_input, tbl_Filter_TD_1054168_output);
    gettimeofday(&tv_r_Filter_10_378966_e, 0);

    struct timeval tv_r_Filter_10_521531_s, tv_r_Filter_10_521531_e;
    gettimeofday(&tv_r_Filter_10_521531_s, 0);
    SW_Filter_TD_1048090(tbl_SerializeFromObject_TD_11702404_input, tbl_Filter_TD_1048090_output);
    gettimeofday(&tv_r_Filter_10_521531_e, 0);

    struct timeval tv_r_Filter_10_630609_s, tv_r_Filter_10_630609_e;
    gettimeofday(&tv_r_Filter_10_630609_s, 0);
    SW_Filter_TD_10138559(tbl_SerializeFromObject_TD_11232543_input, tbl_Filter_TD_10138559_output);
    gettimeofday(&tv_r_Filter_10_630609_e, 0);

    struct timeval tv_r_Filter_10_597891_s, tv_r_Filter_10_597891_e;
    gettimeofday(&tv_r_Filter_10_597891_s, 0);
    SW_Filter_TD_10567282(tbl_SerializeFromObject_TD_11725552_input, tbl_Filter_TD_10567282_output);
    gettimeofday(&tv_r_Filter_10_597891_e, 0);

    struct timeval tv_r_Filter_9_963574_s, tv_r_Filter_9_963574_e;
    gettimeofday(&tv_r_Filter_9_963574_s, 0);
    SW_Filter_TD_9220854(tbl_SerializeFromObject_TD_10448007_input, tbl_Filter_TD_9220854_output);
    gettimeofday(&tv_r_Filter_9_963574_e, 0);

    struct timeval tv_r_JOIN_INNER_9_901167_s, tv_r_JOIN_INNER_9_901167_e;
    gettimeofday(&tv_r_JOIN_INNER_9_901167_s, 0);
    SW_JOIN_INNER_TD_9386501(tbl_Filter_TD_1048090_output, tbl_Filter_TD_1054168_output, tbl_JOIN_INNER_TD_9386501_output);
    gettimeofday(&tv_r_JOIN_INNER_9_901167_e, 0);

    struct timeval tv_r_Filter_9_629479_s, tv_r_Filter_9_629479_e;
    gettimeofday(&tv_r_Filter_9_629479_s, 0);
    SW_Filter_TD_9609467(tbl_SerializeFromObject_TD_10715200_input, tbl_Filter_TD_9609467_output);
    gettimeofday(&tv_r_Filter_9_629479_e, 0);

    struct timeval tv_r_JOIN_INNER_9_933949_s, tv_r_JOIN_INNER_9_933949_e;
    gettimeofday(&tv_r_JOIN_INNER_9_933949_s, 0);
    SW_JOIN_INNER_TD_9942357(tbl_Filter_TD_10567282_output, tbl_Filter_TD_10138559_output, tbl_JOIN_INNER_TD_9942357_output);
    gettimeofday(&tv_r_JOIN_INNER_9_933949_e, 0);

    struct timeval tv_r_Filter_8_822190_s, tv_r_Filter_8_822190_e;
    gettimeofday(&tv_r_Filter_8_822190_s, 0);
    SW_Filter_TD_8812878(tbl_SerializeFromObject_TD_9783073_input, tbl_Filter_TD_8812878_output);
    gettimeofday(&tv_r_Filter_8_822190_e, 0);

    struct timeval tv_r_JOIN_INNER_8_993191_s, tv_r_JOIN_INNER_8_993191_e;
    gettimeofday(&tv_r_JOIN_INNER_8_993191_s, 0);
    SW_JOIN_INNER_TD_8907863(tbl_JOIN_INNER_TD_9386501_output, tbl_Filter_TD_9220854_output, tbl_JOIN_INNER_TD_8907863_output);
    gettimeofday(&tv_r_JOIN_INNER_8_993191_e, 0);

    struct timeval tv_r_Filter_8_931878_s, tv_r_Filter_8_931878_e;
    gettimeofday(&tv_r_Filter_8_931878_s, 0);
    SW_Filter_TD_888970(tbl_SerializeFromObject_TD_9953389_input, tbl_Filter_TD_888970_output);
    gettimeofday(&tv_r_Filter_8_931878_e, 0);

    struct timeval tv_r_JOIN_INNER_8_855817_s, tv_r_JOIN_INNER_8_855817_e;
    gettimeofday(&tv_r_JOIN_INNER_8_855817_s, 0);
    SW_JOIN_INNER_TD_8505770(tbl_JOIN_INNER_TD_9942357_output, tbl_Filter_TD_9609467_output, tbl_JOIN_INNER_TD_8505770_output);
    gettimeofday(&tv_r_JOIN_INNER_8_855817_e, 0);

    struct timeval tv_r_Filter_7_304291_s, tv_r_Filter_7_304291_e;
    gettimeofday(&tv_r_Filter_7_304291_s, 0);
    SW_Filter_TD_7222045(tbl_SerializeFromObject_TD_8701910_input, tbl_Filter_TD_7222045_output);
    gettimeofday(&tv_r_Filter_7_304291_e, 0);

    struct timeval tv_r_JOIN_INNER_7_84991_s, tv_r_JOIN_INNER_7_84991_e;
    gettimeofday(&tv_r_JOIN_INNER_7_84991_s, 0);
    SW_JOIN_INNER_TD_7312336(tbl_JOIN_INNER_TD_8907863_output, tbl_Filter_TD_8812878_output, tbl_JOIN_INNER_TD_7312336_output);
    gettimeofday(&tv_r_JOIN_INNER_7_84991_e, 0);

    struct timeval tv_r_Filter_7_57990_s, tv_r_Filter_7_57990_e;
    gettimeofday(&tv_r_Filter_7_57990_s, 0);
    SW_Filter_TD_748969(tbl_SerializeFromObject_TD_8473429_input, tbl_Filter_TD_748969_output);
    gettimeofday(&tv_r_Filter_7_57990_e, 0);

    struct timeval tv_r_JOIN_INNER_7_431800_s, tv_r_JOIN_INNER_7_431800_e;
    gettimeofday(&tv_r_JOIN_INNER_7_431800_s, 0);
    SW_JOIN_INNER_TD_7362851(tbl_JOIN_INNER_TD_8505770_output, tbl_Filter_TD_888970_output, tbl_JOIN_INNER_TD_7362851_output);
    gettimeofday(&tv_r_JOIN_INNER_7_431800_e, 0);

    struct timeval tv_r_JOIN_INNER_6_471282_s, tv_r_JOIN_INNER_6_471282_e;
    gettimeofday(&tv_r_JOIN_INNER_6_471282_s, 0);
    SW_JOIN_INNER_TD_6705937(tbl_JOIN_INNER_TD_7312336_output, tbl_Filter_TD_7222045_output, tbl_JOIN_INNER_TD_6705937_output);
    gettimeofday(&tv_r_JOIN_INNER_6_471282_e, 0);

    struct timeval tv_r_JOIN_INNER_6_445722_s, tv_r_JOIN_INNER_6_445722_e;
    gettimeofday(&tv_r_JOIN_INNER_6_445722_s, 0);
    SW_JOIN_INNER_TD_6461642(tbl_JOIN_INNER_TD_7362851_output, tbl_Filter_TD_748969_output, tbl_JOIN_INNER_TD_6461642_output);
    gettimeofday(&tv_r_JOIN_INNER_6_445722_e, 0);

    struct timeval tv_r_Aggregate_5_912414_s, tv_r_Aggregate_5_912414_e;
    gettimeofday(&tv_r_Aggregate_5_912414_s, 0);
    SW_Aggregate_TD_5572054(tbl_JOIN_INNER_TD_6705937_output, tbl_Aggregate_TD_5572054_output);
    gettimeofday(&tv_r_Aggregate_5_912414_e, 0);

    struct timeval tv_r_Aggregate_5_806167_s, tv_r_Aggregate_5_806167_e;
    gettimeofday(&tv_r_Aggregate_5_806167_s, 0);
    SW_Aggregate_TD_5195105(tbl_JOIN_INNER_TD_6461642_output, tbl_Aggregate_TD_5195105_output);
    gettimeofday(&tv_r_Aggregate_5_806167_e, 0);

    struct timeval tv_r_Union_4_186986_s, tv_r_Union_4_186986_e;
    gettimeofday(&tv_r_Union_4_186986_s, 0);
    SW_Union_TD_4183185(tbl_Aggregate_TD_5195105_output, tbl_Aggregate_TD_5572054_output, tbl_Union_TD_4183185_output);
    gettimeofday(&tv_r_Union_4_186986_e, 0);

    struct timeval tv_r_Aggregate_3_694874_s, tv_r_Aggregate_3_694874_e;
    gettimeofday(&tv_r_Aggregate_3_694874_s, 0);
    SW_Aggregate_TD_3248653(tbl_Union_TD_4183185_output, tbl_Aggregate_TD_3248653_output);
    gettimeofday(&tv_r_Aggregate_3_694874_e, 0);

    struct timeval tv_r_Sort_2_198454_s, tv_r_Sort_2_198454_e;
    gettimeofday(&tv_r_Sort_2_198454_s, 0);
    SW_Sort_TD_2704870(tbl_Aggregate_TD_3248653_output, tbl_Sort_TD_2704870_output);
    gettimeofday(&tv_r_Sort_2_198454_e, 0);

    struct timeval tv_r_LocalLimit_1_732405_s, tv_r_LocalLimit_1_732405_e;
    gettimeofday(&tv_r_LocalLimit_1_732405_s, 0);
    SW_LocalLimit_TD_137350(tbl_Sort_TD_2704870_output, tbl_LocalLimit_TD_137350_output);
    gettimeofday(&tv_r_LocalLimit_1_732405_e, 0);

    struct timeval tv_r_GlobalLimit_0_425642_s, tv_r_GlobalLimit_0_425642_e;
    gettimeofday(&tv_r_GlobalLimit_0_425642_s, 0);
    SW_GlobalLimit_TD_04967(tbl_LocalLimit_TD_137350_output, tbl_GlobalLimit_TD_04967_output);
    gettimeofday(&tv_r_GlobalLimit_0_425642_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_378966_s, &tv_r_Filter_10_378966_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11544265_input: " << tbl_SerializeFromObject_TD_11544265_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_521531_s, &tv_r_Filter_10_521531_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11702404_input: " << tbl_SerializeFromObject_TD_11702404_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_630609_s, &tv_r_Filter_10_630609_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11232543_input: " << tbl_SerializeFromObject_TD_11232543_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_597891_s, &tv_r_Filter_10_597891_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11725552_input: " << tbl_SerializeFromObject_TD_11725552_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_963574_s, &tv_r_Filter_9_963574_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10448007_input: " << tbl_SerializeFromObject_TD_10448007_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_901167_s, &tv_r_JOIN_INNER_9_901167_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_1048090_output: " << tbl_Filter_TD_1048090_output.getNumRow() << " " << "tbl_Filter_TD_1054168_output: " << tbl_Filter_TD_1054168_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_629479_s, &tv_r_Filter_9_629479_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10715200_input: " << tbl_SerializeFromObject_TD_10715200_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_933949_s, &tv_r_JOIN_INNER_9_933949_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10567282_output: " << tbl_Filter_TD_10567282_output.getNumRow() << " " << "tbl_Filter_TD_10138559_output: " << tbl_Filter_TD_10138559_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_822190_s, &tv_r_Filter_8_822190_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9783073_input: " << tbl_SerializeFromObject_TD_9783073_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_993191_s, &tv_r_JOIN_INNER_8_993191_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9386501_output: " << tbl_JOIN_INNER_TD_9386501_output.getNumRow() << " " << "tbl_Filter_TD_9220854_output: " << tbl_Filter_TD_9220854_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_931878_s, &tv_r_Filter_8_931878_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9953389_input: " << tbl_SerializeFromObject_TD_9953389_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_855817_s, &tv_r_JOIN_INNER_8_855817_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9942357_output: " << tbl_JOIN_INNER_TD_9942357_output.getNumRow() << " " << "tbl_Filter_TD_9609467_output: " << tbl_Filter_TD_9609467_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_304291_s, &tv_r_Filter_7_304291_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8701910_input: " << tbl_SerializeFromObject_TD_8701910_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_84991_s, &tv_r_JOIN_INNER_7_84991_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8907863_output: " << tbl_JOIN_INNER_TD_8907863_output.getNumRow() << " " << "tbl_Filter_TD_8812878_output: " << tbl_Filter_TD_8812878_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_57990_s, &tv_r_Filter_7_57990_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8473429_input: " << tbl_SerializeFromObject_TD_8473429_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_431800_s, &tv_r_JOIN_INNER_7_431800_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8505770_output: " << tbl_JOIN_INNER_TD_8505770_output.getNumRow() << " " << "tbl_Filter_TD_888970_output: " << tbl_Filter_TD_888970_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_471282_s, &tv_r_JOIN_INNER_6_471282_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7312336_output: " << tbl_JOIN_INNER_TD_7312336_output.getNumRow() << " " << "tbl_Filter_TD_7222045_output: " << tbl_Filter_TD_7222045_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_445722_s, &tv_r_JOIN_INNER_6_445722_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7362851_output: " << tbl_JOIN_INNER_TD_7362851_output.getNumRow() << " " << "tbl_Filter_TD_748969_output: " << tbl_Filter_TD_748969_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_912414_s, &tv_r_Aggregate_5_912414_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6705937_output: " << tbl_JOIN_INNER_TD_6705937_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_806167_s, &tv_r_Aggregate_5_806167_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6461642_output: " << tbl_JOIN_INNER_TD_6461642_output.getNumRow() << " " << std::endl; 

    std::cout << "Union_4: " << tvdiff(&tv_r_Union_4_186986_s, &tv_r_Union_4_186986_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_5195105_output: " << tbl_Aggregate_TD_5195105_output.getNumRow() << " " << "tbl_Aggregate_TD_5572054_output: " << tbl_Aggregate_TD_5572054_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_694874_s, &tv_r_Aggregate_3_694874_e) / 1000.0 << " ms " 
     << "tbl_Union_TD_4183185_output: " << tbl_Union_TD_4183185_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_198454_s, &tv_r_Sort_2_198454_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3248653_output: " << tbl_Aggregate_TD_3248653_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_732405_s, &tv_r_LocalLimit_1_732405_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2704870_output: " << tbl_Sort_TD_2704870_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_425642_s, &tv_r_GlobalLimit_0_425642_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_137350_output: " << tbl_LocalLimit_TD_137350_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.7650237 * 1000 << "ms" << std::endl; 
    return 0; 
}
