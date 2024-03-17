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

#include "cfgFunc_q72.hpp" 
#include "q72.hpp" 

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
    std::cout << "NOTE:running query #72\n."; 
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
    Table tbl_GlobalLimit_TD_0386962_output("tbl_GlobalLimit_TD_0386962_output", 6100000, 6, "");
    tbl_GlobalLimit_TD_0386962_output.allocateHost();
    Table tbl_LocalLimit_TD_1152739_output("tbl_LocalLimit_TD_1152739_output", 6100000, 6, "");
    tbl_LocalLimit_TD_1152739_output.allocateHost();
    Table tbl_Sort_TD_2889568_output("tbl_Sort_TD_2889568_output", 6100000, 6, "");
    tbl_Sort_TD_2889568_output.allocateHost();
    Table tbl_Aggregate_TD_3901718_output("tbl_Aggregate_TD_3901718_output", 6100000, 6, "");
    tbl_Aggregate_TD_3901718_output.allocateHost();
    Table tbl_JOIN_LEFTOUTER_TD_4611977_output("tbl_JOIN_LEFTOUTER_TD_4611977_output", 6100000, 4, "");
    tbl_JOIN_LEFTOUTER_TD_4611977_output.allocateHost();
    Table tbl_JOIN_LEFTOUTER_TD_527627_output("tbl_JOIN_LEFTOUTER_TD_527627_output", 6100000, 6, "");
    tbl_JOIN_LEFTOUTER_TD_527627_output.allocateHost();
    Table tbl_Filter_TD_5422168_output("tbl_Filter_TD_5422168_output", 6100000, 2, "");
    tbl_Filter_TD_5422168_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6586137_output("tbl_JOIN_INNER_TD_6586137_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_6586137_output.allocateHost();
    Table tbl_Filter_TD_6454903_output("tbl_Filter_TD_6454903_output", 6100000, 1, "");
    tbl_Filter_TD_6454903_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6941567_input;
    tbl_SerializeFromObject_TD_6941567_input = Table("catalog_returns", catalog_returns_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_6941567_input.addCol("cr_item_sk", 4);
    tbl_SerializeFromObject_TD_6941567_input.addCol("cr_order_number", 8);
    tbl_SerializeFromObject_TD_6941567_input.allocateHost();
    tbl_SerializeFromObject_TD_6941567_input.loadHost();
    Table tbl_JOIN_INNER_TD_7493664_output("tbl_JOIN_INNER_TD_7493664_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_7493664_output.allocateHost();
    Table tbl_Filter_TD_7268867_output("tbl_Filter_TD_7268867_output", 6100000, 2, "");
    tbl_Filter_TD_7268867_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7685570_input;
    tbl_SerializeFromObject_TD_7685570_input = Table("promotion", promotion_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_7685570_input.addCol("p_promo_sk", 4);
    tbl_SerializeFromObject_TD_7685570_input.allocateHost();
    tbl_SerializeFromObject_TD_7685570_input.loadHost();
    Table tbl_JOIN_INNER_TD_8683761_output("tbl_JOIN_INNER_TD_8683761_output", 6100000, 9, "");
    tbl_JOIN_INNER_TD_8683761_output.allocateHost();
    Table tbl_Filter_TD_8828751_output("tbl_Filter_TD_8828751_output", 6100000, 2, "");
    tbl_Filter_TD_8828751_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8675625_input;
    tbl_SerializeFromObject_TD_8675625_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8675625_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_8675625_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_8675625_input.allocateHost();
    tbl_SerializeFromObject_TD_8675625_input.loadHost();
    Table tbl_JOIN_INNER_TD_9660997_output("tbl_JOIN_INNER_TD_9660997_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_9660997_output.allocateHost();
    Table tbl_Filter_TD_9282160_output("tbl_Filter_TD_9282160_output", 6100000, 3, "");
    tbl_Filter_TD_9282160_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9436020_input;
    tbl_SerializeFromObject_TD_9436020_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9436020_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_9436020_input.addCol("d_week_seq", 4);
    tbl_SerializeFromObject_TD_9436020_input.allocateHost();
    tbl_SerializeFromObject_TD_9436020_input.loadHost();
    Table tbl_JOIN_INNER_TD_10460216_output("tbl_JOIN_INNER_TD_10460216_output", 6100000, 9, "");
    tbl_JOIN_INNER_TD_10460216_output.allocateHost();
    Table tbl_Filter_TD_10743744_output("tbl_Filter_TD_10743744_output", 6100000, 1, "");
    tbl_Filter_TD_10743744_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10843779_input;
    tbl_SerializeFromObject_TD_10843779_input = Table("date_dim", date_dim_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_10843779_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10843779_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_10843779_input.addCol("d_week_seq", 4);
    tbl_SerializeFromObject_TD_10843779_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10843779_input.allocateHost();
    tbl_SerializeFromObject_TD_10843779_input.loadHost();
    Table tbl_JOIN_INNER_TD_11107901_output("tbl_JOIN_INNER_TD_11107901_output", 6100000, 10, "");
    tbl_JOIN_INNER_TD_11107901_output.allocateHost();
    Table tbl_Filter_TD_11199147_output("tbl_Filter_TD_11199147_output", 6100000, 1, "");
    tbl_Filter_TD_11199147_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11731801_input;
    tbl_SerializeFromObject_TD_11731801_input = Table("household_demographics", household_demographics_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11731801_input.addCol("hd_demo_sk", 4);
    tbl_SerializeFromObject_TD_11731801_input.addCol("hd_buy_potential", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11731801_input.allocateHost();
    tbl_SerializeFromObject_TD_11731801_input.loadHost();
    Table tbl_JOIN_INNER_TD_12798498_output("tbl_JOIN_INNER_TD_12798498_output", 6100000, 9, "");
    tbl_JOIN_INNER_TD_12798498_output.allocateHost();
    Table tbl_Filter_TD_12480925_output("tbl_Filter_TD_12480925_output", 6100000, 2, "");
    tbl_Filter_TD_12480925_output.allocateHost();
    Table tbl_SerializeFromObject_TD_12813527_input;
    tbl_SerializeFromObject_TD_12813527_input = Table("customer_demographics", customer_demographics_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12813527_input.addCol("cd_demo_sk", 4);
    tbl_SerializeFromObject_TD_12813527_input.addCol("cd_marital_status", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_12813527_input.allocateHost();
    tbl_SerializeFromObject_TD_12813527_input.loadHost();
    Table tbl_JOIN_INNER_TD_13601989_output("tbl_JOIN_INNER_TD_13601989_output", 6100000, 9, "");
    tbl_JOIN_INNER_TD_13601989_output.allocateHost();
    Table tbl_Filter_TD_13548581_output("tbl_Filter_TD_13548581_output", 6100000, 2, "");
    tbl_Filter_TD_13548581_output.allocateHost();
    Table tbl_SerializeFromObject_TD_13883560_input;
    tbl_SerializeFromObject_TD_13883560_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_13883560_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_13883560_input.addCol("i_item_desc", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13883560_input.allocateHost();
    tbl_SerializeFromObject_TD_13883560_input.loadHost();
    Table tbl_Filter_TD_14587774_output("tbl_Filter_TD_14587774_output", 6100000, 8, "");
    tbl_Filter_TD_14587774_output.allocateHost();
    Table tbl_Filter_TD_14269610_output("tbl_Filter_TD_14269610_output", 6100000, 4, "");
    tbl_Filter_TD_14269610_output.allocateHost();
    Table tbl_SerializeFromObject_TD_14676846_input;
    tbl_SerializeFromObject_TD_14676846_input = Table("warehouse", warehouse_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_14676846_input.addCol("w_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_14676846_input.addCol("w_warehouse_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_14676846_input.allocateHost();
    tbl_SerializeFromObject_TD_14676846_input.loadHost();
    Table tbl_SerializeFromObject_TD_15356344_input;
    tbl_SerializeFromObject_TD_15356344_input = Table("catalog_sales", catalog_sales_n, 8, in_dir, "orc");
    tbl_SerializeFromObject_TD_15356344_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_15356344_input.addCol("cs_ship_date_sk", 4);
    tbl_SerializeFromObject_TD_15356344_input.addCol("cs_bill_cdemo_sk", 4);
    tbl_SerializeFromObject_TD_15356344_input.addCol("cs_bill_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_15356344_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_15356344_input.addCol("cs_promo_sk", 4);
    tbl_SerializeFromObject_TD_15356344_input.addCol("cs_order_number", 8);
    tbl_SerializeFromObject_TD_15356344_input.addCol("cs_quantity", 4);
    tbl_SerializeFromObject_TD_15356344_input.allocateHost();
    tbl_SerializeFromObject_TD_15356344_input.loadHost();
    Table tbl_SerializeFromObject_TD_15427726_input;
    tbl_SerializeFromObject_TD_15427726_input = Table("inventory", inventory_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_15427726_input.addCol("inv_date_sk", 4);
    tbl_SerializeFromObject_TD_15427726_input.addCol("inv_item_sk", 4);
    tbl_SerializeFromObject_TD_15427726_input.addCol("inv_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_15427726_input.addCol("inv_quantity_on_hand", 4);
    tbl_SerializeFromObject_TD_15427726_input.allocateHost();
    tbl_SerializeFromObject_TD_15427726_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    std::cout << std::endl; 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_14_890494_s, tv_r_Filter_14_890494_e;
    gettimeofday(&tv_r_Filter_14_890494_s, 0);
    SW_Filter_TD_14269610(tbl_SerializeFromObject_TD_15427726_input, tbl_Filter_TD_14269610_output);
    gettimeofday(&tv_r_Filter_14_890494_e, 0);

    struct timeval tv_r_Filter_14_876558_s, tv_r_Filter_14_876558_e;
    gettimeofday(&tv_r_Filter_14_876558_s, 0);
    SW_Filter_TD_14587774(tbl_SerializeFromObject_TD_15356344_input, tbl_Filter_TD_14587774_output);
    gettimeofday(&tv_r_Filter_14_876558_e, 0);

    struct timeval tv_r_Filter_13_641554_s, tv_r_Filter_13_641554_e;
    gettimeofday(&tv_r_Filter_13_641554_s, 0);
    SW_Filter_TD_13548581(tbl_SerializeFromObject_TD_14676846_input, tbl_Filter_TD_13548581_output);
    gettimeofday(&tv_r_Filter_13_641554_e, 0);

    struct timeval tv_r_JOIN_INNER_13_763927_s, tv_r_JOIN_INNER_13_763927_e;
    gettimeofday(&tv_r_JOIN_INNER_13_763927_s, 0);
    SW_JOIN_INNER_TD_13601989(tbl_Filter_TD_14587774_output, tbl_Filter_TD_14269610_output, tbl_JOIN_INNER_TD_13601989_output);
    gettimeofday(&tv_r_JOIN_INNER_13_763927_e, 0);

    struct timeval tv_r_Filter_12_955124_s, tv_r_Filter_12_955124_e;
    gettimeofday(&tv_r_Filter_12_955124_s, 0);
    SW_Filter_TD_12480925(tbl_SerializeFromObject_TD_13883560_input, tbl_Filter_TD_12480925_output);
    gettimeofday(&tv_r_Filter_12_955124_e, 0);

    struct timeval tv_r_JOIN_INNER_12_278898_s, tv_r_JOIN_INNER_12_278898_e;
    gettimeofday(&tv_r_JOIN_INNER_12_278898_s, 0);
    SW_JOIN_INNER_TD_12798498(tbl_JOIN_INNER_TD_13601989_output, tbl_Filter_TD_13548581_output, tbl_JOIN_INNER_TD_12798498_output);
    gettimeofday(&tv_r_JOIN_INNER_12_278898_e, 0);

    struct timeval tv_r_Filter_11_594772_s, tv_r_Filter_11_594772_e;
    gettimeofday(&tv_r_Filter_11_594772_s, 0);
    SW_Filter_TD_11199147(tbl_SerializeFromObject_TD_12813527_input, tbl_Filter_TD_11199147_output);
    gettimeofday(&tv_r_Filter_11_594772_e, 0);

    struct timeval tv_r_JOIN_INNER_11_13015_s, tv_r_JOIN_INNER_11_13015_e;
    gettimeofday(&tv_r_JOIN_INNER_11_13015_s, 0);
    SW_JOIN_INNER_TD_11107901(tbl_JOIN_INNER_TD_12798498_output, tbl_Filter_TD_12480925_output, tbl_JOIN_INNER_TD_11107901_output);
    gettimeofday(&tv_r_JOIN_INNER_11_13015_e, 0);

    struct timeval tv_r_Filter_10_187453_s, tv_r_Filter_10_187453_e;
    gettimeofday(&tv_r_Filter_10_187453_s, 0);
    SW_Filter_TD_10743744(tbl_SerializeFromObject_TD_11731801_input, tbl_Filter_TD_10743744_output);
    gettimeofday(&tv_r_Filter_10_187453_e, 0);

    struct timeval tv_r_JOIN_INNER_10_604285_s, tv_r_JOIN_INNER_10_604285_e;
    gettimeofday(&tv_r_JOIN_INNER_10_604285_s, 0);
    SW_JOIN_INNER_TD_10460216(tbl_JOIN_INNER_TD_11107901_output, tbl_Filter_TD_11199147_output, tbl_JOIN_INNER_TD_10460216_output);
    gettimeofday(&tv_r_JOIN_INNER_10_604285_e, 0);

    struct timeval tv_r_Filter_9_377358_s, tv_r_Filter_9_377358_e;
    gettimeofday(&tv_r_Filter_9_377358_s, 0);
    SW_Filter_TD_9282160(tbl_SerializeFromObject_TD_10843779_input, tbl_Filter_TD_9282160_output);
    gettimeofday(&tv_r_Filter_9_377358_e, 0);

    struct timeval tv_r_JOIN_INNER_9_816021_s, tv_r_JOIN_INNER_9_816021_e;
    gettimeofday(&tv_r_JOIN_INNER_9_816021_s, 0);
    SW_JOIN_INNER_TD_9660997(tbl_JOIN_INNER_TD_10460216_output, tbl_Filter_TD_10743744_output, tbl_JOIN_INNER_TD_9660997_output);
    gettimeofday(&tv_r_JOIN_INNER_9_816021_e, 0);

    struct timeval tv_r_Filter_8_873047_s, tv_r_Filter_8_873047_e;
    gettimeofday(&tv_r_Filter_8_873047_s, 0);
    SW_Filter_TD_8828751(tbl_SerializeFromObject_TD_9436020_input, tbl_Filter_TD_8828751_output);
    gettimeofday(&tv_r_Filter_8_873047_e, 0);

    struct timeval tv_r_JOIN_INNER_8_453831_s, tv_r_JOIN_INNER_8_453831_e;
    gettimeofday(&tv_r_JOIN_INNER_8_453831_s, 0);
    SW_JOIN_INNER_TD_8683761(tbl_JOIN_INNER_TD_9660997_output, tbl_Filter_TD_9282160_output, tbl_JOIN_INNER_TD_8683761_output);
    gettimeofday(&tv_r_JOIN_INNER_8_453831_e, 0);

    struct timeval tv_r_Filter_7_45865_s, tv_r_Filter_7_45865_e;
    gettimeofday(&tv_r_Filter_7_45865_s, 0);
    SW_Filter_TD_7268867(tbl_SerializeFromObject_TD_8675625_input, tbl_Filter_TD_7268867_output);
    gettimeofday(&tv_r_Filter_7_45865_e, 0);

    struct timeval tv_r_JOIN_INNER_7_485699_s, tv_r_JOIN_INNER_7_485699_e;
    gettimeofday(&tv_r_JOIN_INNER_7_485699_s, 0);
    SW_JOIN_INNER_TD_7493664(tbl_JOIN_INNER_TD_8683761_output, tbl_Filter_TD_8828751_output, tbl_JOIN_INNER_TD_7493664_output);
    gettimeofday(&tv_r_JOIN_INNER_7_485699_e, 0);

    struct timeval tv_r_Filter_6_825945_s, tv_r_Filter_6_825945_e;
    gettimeofday(&tv_r_Filter_6_825945_s, 0);
    SW_Filter_TD_6454903(tbl_SerializeFromObject_TD_7685570_input, tbl_Filter_TD_6454903_output);
    gettimeofday(&tv_r_Filter_6_825945_e, 0);

    struct timeval tv_r_JOIN_INNER_6_62534_s, tv_r_JOIN_INNER_6_62534_e;
    gettimeofday(&tv_r_JOIN_INNER_6_62534_s, 0);
    SW_JOIN_INNER_TD_6586137(tbl_JOIN_INNER_TD_7493664_output, tbl_Filter_TD_7268867_output, tbl_JOIN_INNER_TD_6586137_output);
    gettimeofday(&tv_r_JOIN_INNER_6_62534_e, 0);

    struct timeval tv_r_Filter_5_528834_s, tv_r_Filter_5_528834_e;
    gettimeofday(&tv_r_Filter_5_528834_s, 0);
    SW_Filter_TD_5422168(tbl_SerializeFromObject_TD_6941567_input, tbl_Filter_TD_5422168_output);
    gettimeofday(&tv_r_Filter_5_528834_e, 0);

    struct timeval tv_r_JOIN_LEFTOUTER_5_190732_s, tv_r_JOIN_LEFTOUTER_5_190732_e;
    gettimeofday(&tv_r_JOIN_LEFTOUTER_5_190732_s, 0);
    SW_JOIN_LEFTOUTER_TD_527627(tbl_JOIN_INNER_TD_6586137_output, tbl_Filter_TD_6454903_output, tbl_JOIN_LEFTOUTER_TD_527627_output);
    gettimeofday(&tv_r_JOIN_LEFTOUTER_5_190732_e, 0);

    struct timeval tv_r_JOIN_LEFTOUTER_4_443320_s, tv_r_JOIN_LEFTOUTER_4_443320_e;
    gettimeofday(&tv_r_JOIN_LEFTOUTER_4_443320_s, 0);
    SW_JOIN_LEFTOUTER_TD_4611977(tbl_JOIN_LEFTOUTER_TD_527627_output, tbl_Filter_TD_5422168_output, tbl_JOIN_LEFTOUTER_TD_4611977_output);
    gettimeofday(&tv_r_JOIN_LEFTOUTER_4_443320_e, 0);

    struct timeval tv_r_Aggregate_3_672747_s, tv_r_Aggregate_3_672747_e;
    gettimeofday(&tv_r_Aggregate_3_672747_s, 0);
    SW_Aggregate_TD_3901718(tbl_JOIN_LEFTOUTER_TD_4611977_output, tbl_Aggregate_TD_3901718_output);
    gettimeofday(&tv_r_Aggregate_3_672747_e, 0);

    struct timeval tv_r_Sort_2_391941_s, tv_r_Sort_2_391941_e;
    gettimeofday(&tv_r_Sort_2_391941_s, 0);
    SW_Sort_TD_2889568(tbl_Aggregate_TD_3901718_output, tbl_Sort_TD_2889568_output);
    gettimeofday(&tv_r_Sort_2_391941_e, 0);

    struct timeval tv_r_LocalLimit_1_578110_s, tv_r_LocalLimit_1_578110_e;
    gettimeofday(&tv_r_LocalLimit_1_578110_s, 0);
    SW_LocalLimit_TD_1152739(tbl_Sort_TD_2889568_output, tbl_LocalLimit_TD_1152739_output);
    gettimeofday(&tv_r_LocalLimit_1_578110_e, 0);

    struct timeval tv_r_GlobalLimit_0_114406_s, tv_r_GlobalLimit_0_114406_e;
    gettimeofday(&tv_r_GlobalLimit_0_114406_s, 0);
    SW_GlobalLimit_TD_0386962(tbl_LocalLimit_TD_1152739_output, tbl_GlobalLimit_TD_0386962_output);
    gettimeofday(&tv_r_GlobalLimit_0_114406_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_14: " << tvdiff(&tv_r_Filter_14_890494_s, &tv_r_Filter_14_890494_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_15427726_input: " << tbl_SerializeFromObject_TD_15427726_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_14: " << tvdiff(&tv_r_Filter_14_876558_s, &tv_r_Filter_14_876558_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_15356344_input: " << tbl_SerializeFromObject_TD_15356344_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_13: " << tvdiff(&tv_r_Filter_13_641554_s, &tv_r_Filter_13_641554_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_14676846_input: " << tbl_SerializeFromObject_TD_14676846_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_13: " << tvdiff(&tv_r_JOIN_INNER_13_763927_s, &tv_r_JOIN_INNER_13_763927_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_14587774_output: " << tbl_Filter_TD_14587774_output.getNumRow() << " " << "tbl_Filter_TD_14269610_output: " << tbl_Filter_TD_14269610_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_955124_s, &tv_r_Filter_12_955124_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13883560_input: " << tbl_SerializeFromObject_TD_13883560_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_12: " << tvdiff(&tv_r_JOIN_INNER_12_278898_s, &tv_r_JOIN_INNER_12_278898_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_13601989_output: " << tbl_JOIN_INNER_TD_13601989_output.getNumRow() << " " << "tbl_Filter_TD_13548581_output: " << tbl_Filter_TD_13548581_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_594772_s, &tv_r_Filter_11_594772_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12813527_input: " << tbl_SerializeFromObject_TD_12813527_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_11: " << tvdiff(&tv_r_JOIN_INNER_11_13015_s, &tv_r_JOIN_INNER_11_13015_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_12798498_output: " << tbl_JOIN_INNER_TD_12798498_output.getNumRow() << " " << "tbl_Filter_TD_12480925_output: " << tbl_Filter_TD_12480925_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_187453_s, &tv_r_Filter_10_187453_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11731801_input: " << tbl_SerializeFromObject_TD_11731801_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_604285_s, &tv_r_JOIN_INNER_10_604285_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_11107901_output: " << tbl_JOIN_INNER_TD_11107901_output.getNumRow() << " " << "tbl_Filter_TD_11199147_output: " << tbl_Filter_TD_11199147_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_377358_s, &tv_r_Filter_9_377358_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10843779_input: " << tbl_SerializeFromObject_TD_10843779_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_816021_s, &tv_r_JOIN_INNER_9_816021_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10460216_output: " << tbl_JOIN_INNER_TD_10460216_output.getNumRow() << " " << "tbl_Filter_TD_10743744_output: " << tbl_Filter_TD_10743744_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_873047_s, &tv_r_Filter_8_873047_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9436020_input: " << tbl_SerializeFromObject_TD_9436020_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_453831_s, &tv_r_JOIN_INNER_8_453831_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9660997_output: " << tbl_JOIN_INNER_TD_9660997_output.getNumRow() << " " << "tbl_Filter_TD_9282160_output: " << tbl_Filter_TD_9282160_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_45865_s, &tv_r_Filter_7_45865_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8675625_input: " << tbl_SerializeFromObject_TD_8675625_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_485699_s, &tv_r_JOIN_INNER_7_485699_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8683761_output: " << tbl_JOIN_INNER_TD_8683761_output.getNumRow() << " " << "tbl_Filter_TD_8828751_output: " << tbl_Filter_TD_8828751_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_825945_s, &tv_r_Filter_6_825945_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7685570_input: " << tbl_SerializeFromObject_TD_7685570_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_62534_s, &tv_r_JOIN_INNER_6_62534_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7493664_output: " << tbl_JOIN_INNER_TD_7493664_output.getNumRow() << " " << "tbl_Filter_TD_7268867_output: " << tbl_Filter_TD_7268867_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_528834_s, &tv_r_Filter_5_528834_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6941567_input: " << tbl_SerializeFromObject_TD_6941567_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTOUTER_5: " << tvdiff(&tv_r_JOIN_LEFTOUTER_5_190732_s, &tv_r_JOIN_LEFTOUTER_5_190732_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6586137_output: " << tbl_JOIN_INNER_TD_6586137_output.getNumRow() << " " << "tbl_Filter_TD_6454903_output: " << tbl_Filter_TD_6454903_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTOUTER_4: " << tvdiff(&tv_r_JOIN_LEFTOUTER_4_443320_s, &tv_r_JOIN_LEFTOUTER_4_443320_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTOUTER_TD_527627_output: " << tbl_JOIN_LEFTOUTER_TD_527627_output.getNumRow() << " " << "tbl_Filter_TD_5422168_output: " << tbl_Filter_TD_5422168_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_672747_s, &tv_r_Aggregate_3_672747_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTOUTER_TD_4611977_output: " << tbl_JOIN_LEFTOUTER_TD_4611977_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_391941_s, &tv_r_Sort_2_391941_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3901718_output: " << tbl_Aggregate_TD_3901718_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_578110_s, &tv_r_LocalLimit_1_578110_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2889568_output: " << tbl_Sort_TD_2889568_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_114406_s, &tv_r_GlobalLimit_0_114406_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1152739_output: " << tbl_LocalLimit_TD_1152739_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 20.676235 * 1000 << "ms" << std::endl; 
    return 0; 
}
