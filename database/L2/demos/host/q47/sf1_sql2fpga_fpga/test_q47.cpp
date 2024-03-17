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

#include "cfgFunc_q47.hpp" 
#include "q47.hpp" 

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
    std::cout << "NOTE:running query #47\n."; 
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
    Table tbl_GlobalLimit_TD_0457744_output("tbl_GlobalLimit_TD_0457744_output", 6100000, 10, "");
    tbl_GlobalLimit_TD_0457744_output.allocateHost();
    Table tbl_LocalLimit_TD_1597577_output("tbl_LocalLimit_TD_1597577_output", 6100000, 10, "");
    tbl_LocalLimit_TD_1597577_output.allocateHost();
    Table tbl_Sort_TD_2151559_output("tbl_Sort_TD_2151559_output", 6100000, 10, "");
    tbl_Sort_TD_2151559_output.allocateHost();
    Table tbl_Project_TD_3149367_output("tbl_Project_TD_3149367_output", 6100000, 10, "");
    tbl_Project_TD_3149367_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4503684_output("tbl_JOIN_INNER_TD_4503684_output", 6100000, 10, "");
    tbl_JOIN_INNER_TD_4503684_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5199655_output("tbl_JOIN_INNER_TD_5199655_output", 6100000, 10, "");
    tbl_JOIN_INNER_TD_5199655_output.allocateHost();
    Table tbl_Project_TD_5902046_output("tbl_Project_TD_5902046_output", 6100000, 6, "");
    tbl_Project_TD_5902046_output.allocateHost();
    Table tbl_Filter_TD_6739433_output("tbl_Filter_TD_6739433_output", 6100000, 9, "");
    tbl_Filter_TD_6739433_output.allocateHost();
    Table tbl_Project_TD_6359877_output("tbl_Project_TD_6359877_output", 6100000, 6, "");
    tbl_Project_TD_6359877_output.allocateHost();
    Table tbl_Window_TD_6765754_output("tbl_Window_TD_6765754_output", 6100000, 8, "");
    tbl_Window_TD_6765754_output.allocateHost();
    Table tbl_Window_TD_7140839_output("tbl_Window_TD_7140839_output", 6100000, 10, "");
    tbl_Window_TD_7140839_output.allocateHost();
    Table tbl_Window_TD_74072_output("tbl_Window_TD_74072_output", 6100000, 8, "");
    tbl_Window_TD_74072_output.allocateHost();
    Table tbl_Aggregate_TD_7672439_output("tbl_Aggregate_TD_7672439_output", 6100000, 7, "");
    tbl_Aggregate_TD_7672439_output.allocateHost();
    Table tbl_Filter_TD_8717904_output("tbl_Filter_TD_8717904_output", 6100000, 9, "");
    tbl_Filter_TD_8717904_output.allocateHost();
    Table tbl_Aggregate_TD_8602438_output("tbl_Aggregate_TD_8602438_output", 6100000, 7, "");
    tbl_Aggregate_TD_8602438_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8400276_output("tbl_JOIN_INNER_TD_8400276_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_8400276_output.allocateHost();
    Table tbl_Window_TD_9144530_output("tbl_Window_TD_9144530_output", 6100000, 9, "");
    tbl_Window_TD_9144530_output.allocateHost();
    Table tbl_JOIN_INNER_TD_9135593_output("tbl_JOIN_INNER_TD_9135593_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_9135593_output.allocateHost();
    Table tbl_JOIN_INNER_TD_9435922_output("tbl_JOIN_INNER_TD_9435922_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_9435922_output.allocateHost();
    Table tbl_Filter_TD_9100061_output("tbl_Filter_TD_9100061_output", 6100000, 3, "");
    tbl_Filter_TD_9100061_output.allocateHost();
    Table tbl_Aggregate_TD_10406594_output("tbl_Aggregate_TD_10406594_output", 6100000, 8, "");
    tbl_Aggregate_TD_10406594_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10880607_output("tbl_JOIN_INNER_TD_10880607_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_10880607_output.allocateHost();
    Table tbl_Filter_TD_10808472_output("tbl_Filter_TD_10808472_output", 6100000, 3, "");
    tbl_Filter_TD_10808472_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10575406_output("tbl_JOIN_INNER_TD_10575406_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_10575406_output.allocateHost();
    Table tbl_Filter_TD_10754913_output("tbl_Filter_TD_10754913_output", 6100000, 3, "");
    tbl_Filter_TD_10754913_output.allocateHost();
    Table tbl_SerializeFromObject_TD_1058800_input;
    tbl_SerializeFromObject_TD_1058800_input = Table("store", store_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_1058800_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_1058800_input.addCol("s_store_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_1058800_input.addCol("s_company_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_1058800_input.allocateHost();
    tbl_SerializeFromObject_TD_1058800_input.loadHost();
    Table tbl_JOIN_INNER_TD_11976272_output("tbl_JOIN_INNER_TD_11976272_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_11976272_output.allocateHost();
    Table tbl_JOIN_INNER_TD_11650222_output("tbl_JOIN_INNER_TD_11650222_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_11650222_output.allocateHost();
    Table tbl_Filter_TD_11848688_output("tbl_Filter_TD_11848688_output", 6100000, 3, "");
    tbl_Filter_TD_11848688_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11511324_input;
    tbl_SerializeFromObject_TD_11511324_input = Table("store", store_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11511324_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_11511324_input.addCol("s_store_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11511324_input.addCol("s_company_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11511324_input.allocateHost();
    tbl_SerializeFromObject_TD_11511324_input.loadHost();
    Table tbl_Filter_TD_11686420_output("tbl_Filter_TD_11686420_output", 6100000, 3, "");
    tbl_Filter_TD_11686420_output.allocateHost();
    Table tbl_Filter_TD_11987487_output("tbl_Filter_TD_11987487_output", 6100000, 4, "");
    tbl_Filter_TD_11987487_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11779885_input;
    tbl_SerializeFromObject_TD_11779885_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11779885_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_11779885_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_11779885_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_11779885_input.allocateHost();
    tbl_SerializeFromObject_TD_11779885_input.loadHost();
    Table tbl_JOIN_INNER_TD_12974871_output("tbl_JOIN_INNER_TD_12974871_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_12974871_output.allocateHost();
    Table tbl_Filter_TD_12735478_output("tbl_Filter_TD_12735478_output", 6100000, 3, "");
    tbl_Filter_TD_12735478_output.allocateHost();
    Table tbl_Filter_TD_12274745_output("tbl_Filter_TD_12274745_output", 6100000, 3, "");
    tbl_Filter_TD_12274745_output.allocateHost();
    Table tbl_Filter_TD_12810859_output("tbl_Filter_TD_12810859_output", 6100000, 4, "");
    tbl_Filter_TD_12810859_output.allocateHost();
    Table tbl_SerializeFromObject_TD_1212713_input;
    tbl_SerializeFromObject_TD_1212713_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_1212713_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_1212713_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_1212713_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_1212713_input.allocateHost();
    tbl_SerializeFromObject_TD_1212713_input.loadHost();
    Table tbl_SerializeFromObject_TD_12145072_input;
    tbl_SerializeFromObject_TD_12145072_input = Table("item", item_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_12145072_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_12145072_input.addCol("i_brand", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_12145072_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_12145072_input.allocateHost();
    tbl_SerializeFromObject_TD_12145072_input.loadHost();
    Table tbl_SerializeFromObject_TD_12430691_input;
    tbl_SerializeFromObject_TD_12430691_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_12430691_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_12430691_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_12430691_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_12430691_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_12430691_input.allocateHost();
    tbl_SerializeFromObject_TD_12430691_input.loadHost();
    Table tbl_JOIN_INNER_TD_13515608_output("tbl_JOIN_INNER_TD_13515608_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_13515608_output.allocateHost();
    Table tbl_Filter_TD_13912779_output("tbl_Filter_TD_13912779_output", 6100000, 3, "");
    tbl_Filter_TD_13912779_output.allocateHost();
    Table tbl_SerializeFromObject_TD_13383862_input;
    tbl_SerializeFromObject_TD_13383862_input = Table("store", store_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_13383862_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_13383862_input.addCol("s_store_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13383862_input.addCol("s_company_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13383862_input.allocateHost();
    tbl_SerializeFromObject_TD_13383862_input.loadHost();
    Table tbl_SerializeFromObject_TD_13534262_input;
    tbl_SerializeFromObject_TD_13534262_input = Table("item", item_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_13534262_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_13534262_input.addCol("i_brand", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13534262_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13534262_input.allocateHost();
    tbl_SerializeFromObject_TD_13534262_input.loadHost();
    Table tbl_SerializeFromObject_TD_13911383_input;
    tbl_SerializeFromObject_TD_13911383_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_13911383_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_13911383_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_13911383_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_13911383_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_13911383_input.allocateHost();
    tbl_SerializeFromObject_TD_13911383_input.loadHost();
    Table tbl_Filter_TD_14208171_output("tbl_Filter_TD_14208171_output", 6100000, 3, "");
    tbl_Filter_TD_14208171_output.allocateHost();
    Table tbl_Filter_TD_14434599_output("tbl_Filter_TD_14434599_output", 6100000, 4, "");
    tbl_Filter_TD_14434599_output.allocateHost();
    Table tbl_SerializeFromObject_TD_14802568_input;
    tbl_SerializeFromObject_TD_14802568_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_14802568_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_14802568_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_14802568_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_14802568_input.allocateHost();
    tbl_SerializeFromObject_TD_14802568_input.loadHost();
    Table tbl_SerializeFromObject_TD_15398144_input;
    tbl_SerializeFromObject_TD_15398144_input = Table("item", item_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_15398144_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_15398144_input.addCol("i_brand", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_15398144_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_15398144_input.allocateHost();
    tbl_SerializeFromObject_TD_15398144_input.loadHost();
    Table tbl_SerializeFromObject_TD_15419224_input;
    tbl_SerializeFromObject_TD_15419224_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_15419224_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_15419224_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_15419224_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_15419224_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_15419224_input.allocateHost();
    tbl_SerializeFromObject_TD_15419224_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    std::cout << std::endl; 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_14_365202_s, tv_r_Filter_14_365202_e;
    gettimeofday(&tv_r_Filter_14_365202_s, 0);
    SW_Filter_TD_14434599(tbl_SerializeFromObject_TD_15419224_input, tbl_Filter_TD_14434599_output);
    gettimeofday(&tv_r_Filter_14_365202_e, 0);

    struct timeval tv_r_Filter_14_498618_s, tv_r_Filter_14_498618_e;
    gettimeofday(&tv_r_Filter_14_498618_s, 0);
    SW_Filter_TD_14208171(tbl_SerializeFromObject_TD_15398144_input, tbl_Filter_TD_14208171_output);
    gettimeofday(&tv_r_Filter_14_498618_e, 0);

    struct timeval tv_r_Filter_13_750349_s, tv_r_Filter_13_750349_e;
    gettimeofday(&tv_r_Filter_13_750349_s, 0);
    SW_Filter_TD_13912779(tbl_SerializeFromObject_TD_14802568_input, tbl_Filter_TD_13912779_output);
    gettimeofday(&tv_r_Filter_13_750349_e, 0);

    struct timeval tv_r_JOIN_INNER_13_93310_s, tv_r_JOIN_INNER_13_93310_e;
    gettimeofday(&tv_r_JOIN_INNER_13_93310_s, 0);
    SW_JOIN_INNER_TD_13515608(tbl_Filter_TD_14208171_output, tbl_Filter_TD_14434599_output, tbl_JOIN_INNER_TD_13515608_output);
    gettimeofday(&tv_r_JOIN_INNER_13_93310_e, 0);

    struct timeval tv_r_Filter_12_185055_s, tv_r_Filter_12_185055_e;
    gettimeofday(&tv_r_Filter_12_185055_s, 0);
    SW_Filter_TD_12810859(tbl_SerializeFromObject_TD_13911383_input, tbl_Filter_TD_12810859_output);
    gettimeofday(&tv_r_Filter_12_185055_e, 0);

    struct timeval tv_r_Filter_12_423997_s, tv_r_Filter_12_423997_e;
    gettimeofday(&tv_r_Filter_12_423997_s, 0);
    SW_Filter_TD_12274745(tbl_SerializeFromObject_TD_13534262_input, tbl_Filter_TD_12274745_output);
    gettimeofday(&tv_r_Filter_12_423997_e, 0);

    struct timeval tv_r_Filter_12_397371_s, tv_r_Filter_12_397371_e;
    gettimeofday(&tv_r_Filter_12_397371_s, 0);
    SW_Filter_TD_12735478(tbl_SerializeFromObject_TD_13383862_input, tbl_Filter_TD_12735478_output);
    gettimeofday(&tv_r_Filter_12_397371_e, 0);

    struct timeval tv_r_JOIN_INNER_12_669795_s, tv_r_JOIN_INNER_12_669795_e;
    gettimeofday(&tv_r_JOIN_INNER_12_669795_s, 0);
    SW_JOIN_INNER_TD_12974871(tbl_JOIN_INNER_TD_13515608_output, tbl_Filter_TD_13912779_output, tbl_JOIN_INNER_TD_12974871_output);
    gettimeofday(&tv_r_JOIN_INNER_12_669795_e, 0);

    struct timeval tv_r_Filter_11_862832_s, tv_r_Filter_11_862832_e;
    gettimeofday(&tv_r_Filter_11_862832_s, 0);
    SW_Filter_TD_11987487(tbl_SerializeFromObject_TD_12430691_input, tbl_Filter_TD_11987487_output);
    gettimeofday(&tv_r_Filter_11_862832_e, 0);

    struct timeval tv_r_Filter_11_701945_s, tv_r_Filter_11_701945_e;
    gettimeofday(&tv_r_Filter_11_701945_s, 0);
    SW_Filter_TD_11686420(tbl_SerializeFromObject_TD_12145072_input, tbl_Filter_TD_11686420_output);
    gettimeofday(&tv_r_Filter_11_701945_e, 0);

    struct timeval tv_r_Filter_11_863037_s, tv_r_Filter_11_863037_e;
    gettimeofday(&tv_r_Filter_11_863037_s, 0);
    SW_Filter_TD_11848688(tbl_SerializeFromObject_TD_1212713_input, tbl_Filter_TD_11848688_output);
    gettimeofday(&tv_r_Filter_11_863037_e, 0);

    struct timeval tv_r_JOIN_INNER_11_956267_s, tv_r_JOIN_INNER_11_956267_e;
    gettimeofday(&tv_r_JOIN_INNER_11_956267_s, 0);
    SW_JOIN_INNER_TD_11650222(tbl_Filter_TD_12274745_output, tbl_Filter_TD_12810859_output, tbl_JOIN_INNER_TD_11650222_output);
    gettimeofday(&tv_r_JOIN_INNER_11_956267_e, 0);

    struct timeval tv_r_JOIN_INNER_11_710419_s, tv_r_JOIN_INNER_11_710419_e;
    gettimeofday(&tv_r_JOIN_INNER_11_710419_s, 0);
    SW_JOIN_INNER_TD_11976272(tbl_JOIN_INNER_TD_12974871_output, tbl_Filter_TD_12735478_output, tbl_JOIN_INNER_TD_11976272_output);
    gettimeofday(&tv_r_JOIN_INNER_11_710419_e, 0);

    struct timeval tv_r_Filter_10_764208_s, tv_r_Filter_10_764208_e;
    gettimeofday(&tv_r_Filter_10_764208_s, 0);
    SW_Filter_TD_10754913(tbl_SerializeFromObject_TD_11779885_input, tbl_Filter_TD_10754913_output);
    gettimeofday(&tv_r_Filter_10_764208_e, 0);

    struct timeval tv_r_JOIN_INNER_10_790759_s, tv_r_JOIN_INNER_10_790759_e;
    gettimeofday(&tv_r_JOIN_INNER_10_790759_s, 0);
    SW_JOIN_INNER_TD_10575406(tbl_Filter_TD_11686420_output, tbl_Filter_TD_11987487_output, tbl_JOIN_INNER_TD_10575406_output);
    gettimeofday(&tv_r_JOIN_INNER_10_790759_e, 0);

    struct timeval tv_r_Filter_10_939974_s, tv_r_Filter_10_939974_e;
    gettimeofday(&tv_r_Filter_10_939974_s, 0);
    SW_Filter_TD_10808472(tbl_SerializeFromObject_TD_11511324_input, tbl_Filter_TD_10808472_output);
    gettimeofday(&tv_r_Filter_10_939974_e, 0);

    struct timeval tv_r_JOIN_INNER_10_185845_s, tv_r_JOIN_INNER_10_185845_e;
    gettimeofday(&tv_r_JOIN_INNER_10_185845_s, 0);
    SW_JOIN_INNER_TD_10880607(tbl_JOIN_INNER_TD_11650222_output, tbl_Filter_TD_11848688_output, tbl_JOIN_INNER_TD_10880607_output);
    gettimeofday(&tv_r_JOIN_INNER_10_185845_e, 0);

    struct timeval tv_r_Aggregate_10_333178_s, tv_r_Aggregate_10_333178_e;
    gettimeofday(&tv_r_Aggregate_10_333178_s, 0);
    SW_Aggregate_TD_10406594(tbl_JOIN_INNER_TD_11976272_output, tbl_Aggregate_TD_10406594_output);
    gettimeofday(&tv_r_Aggregate_10_333178_e, 0);

    struct timeval tv_r_Filter_9_877413_s, tv_r_Filter_9_877413_e;
    gettimeofday(&tv_r_Filter_9_877413_s, 0);
    SW_Filter_TD_9100061(tbl_SerializeFromObject_TD_1058800_input, tbl_Filter_TD_9100061_output);
    gettimeofday(&tv_r_Filter_9_877413_e, 0);

    struct timeval tv_r_JOIN_INNER_9_398384_s, tv_r_JOIN_INNER_9_398384_e;
    gettimeofday(&tv_r_JOIN_INNER_9_398384_s, 0);
    SW_JOIN_INNER_TD_9435922(tbl_JOIN_INNER_TD_10575406_output, tbl_Filter_TD_10754913_output, tbl_JOIN_INNER_TD_9435922_output);
    gettimeofday(&tv_r_JOIN_INNER_9_398384_e, 0);

    struct timeval tv_r_JOIN_INNER_9_855778_s, tv_r_JOIN_INNER_9_855778_e;
    gettimeofday(&tv_r_JOIN_INNER_9_855778_s, 0);
    SW_JOIN_INNER_TD_9135593(tbl_JOIN_INNER_TD_10880607_output, tbl_Filter_TD_10808472_output, tbl_JOIN_INNER_TD_9135593_output);
    gettimeofday(&tv_r_JOIN_INNER_9_855778_e, 0);

    struct timeval tv_r_Window_9_60442_s, tv_r_Window_9_60442_e;
    gettimeofday(&tv_r_Window_9_60442_s, 0);
    SW_Window_TD_9144530(tbl_Aggregate_TD_10406594_output, tbl_Window_TD_9144530_output);
    gettimeofday(&tv_r_Window_9_60442_e, 0);

    struct timeval tv_r_JOIN_INNER_8_216724_s, tv_r_JOIN_INNER_8_216724_e;
    gettimeofday(&tv_r_JOIN_INNER_8_216724_s, 0);
    SW_JOIN_INNER_TD_8400276(tbl_JOIN_INNER_TD_9435922_output, tbl_Filter_TD_9100061_output, tbl_JOIN_INNER_TD_8400276_output);
    gettimeofday(&tv_r_JOIN_INNER_8_216724_e, 0);

    struct timeval tv_r_Aggregate_8_671642_s, tv_r_Aggregate_8_671642_e;
    gettimeofday(&tv_r_Aggregate_8_671642_s, 0);
    SW_Aggregate_TD_8602438(tbl_JOIN_INNER_TD_9135593_output, tbl_Aggregate_TD_8602438_output);
    gettimeofday(&tv_r_Aggregate_8_671642_e, 0);

    struct timeval tv_r_Filter_8_28136_s, tv_r_Filter_8_28136_e;
    gettimeofday(&tv_r_Filter_8_28136_s, 0);
    SW_Filter_TD_8717904(tbl_Window_TD_9144530_output, tbl_Filter_TD_8717904_output);
    gettimeofday(&tv_r_Filter_8_28136_e, 0);

    struct timeval tv_r_Aggregate_7_902652_s, tv_r_Aggregate_7_902652_e;
    gettimeofday(&tv_r_Aggregate_7_902652_s, 0);
    SW_Aggregate_TD_7672439(tbl_JOIN_INNER_TD_8400276_output, tbl_Aggregate_TD_7672439_output);
    gettimeofday(&tv_r_Aggregate_7_902652_e, 0);

    struct timeval tv_r_Window_7_366958_s, tv_r_Window_7_366958_e;
    gettimeofday(&tv_r_Window_7_366958_s, 0);
    SW_Window_TD_74072(tbl_Aggregate_TD_8602438_output, tbl_Window_TD_74072_output);
    gettimeofday(&tv_r_Window_7_366958_e, 0);

    struct timeval tv_r_Window_7_274234_s, tv_r_Window_7_274234_e;
    gettimeofday(&tv_r_Window_7_274234_s, 0);
    SW_Window_TD_7140839(tbl_Filter_TD_8717904_output, tbl_Window_TD_7140839_output);
    gettimeofday(&tv_r_Window_7_274234_e, 0);

    struct timeval tv_r_Window_6_944857_s, tv_r_Window_6_944857_e;
    gettimeofday(&tv_r_Window_6_944857_s, 0);
    SW_Window_TD_6765754(tbl_Aggregate_TD_7672439_output, tbl_Window_TD_6765754_output);
    gettimeofday(&tv_r_Window_6_944857_e, 0);

    struct timeval tv_r_Project_6_948109_s, tv_r_Project_6_948109_e;
    gettimeofday(&tv_r_Project_6_948109_s, 0);
    SW_Project_TD_6359877(tbl_Window_TD_74072_output, tbl_Project_TD_6359877_output);
    gettimeofday(&tv_r_Project_6_948109_e, 0);

    struct timeval tv_r_Filter_6_131357_s, tv_r_Filter_6_131357_e;
    gettimeofday(&tv_r_Filter_6_131357_s, 0);
    SW_Filter_TD_6739433(tbl_Window_TD_7140839_output, tbl_Filter_TD_6739433_output);
    gettimeofday(&tv_r_Filter_6_131357_e, 0);

    struct timeval tv_r_Project_5_225004_s, tv_r_Project_5_225004_e;
    gettimeofday(&tv_r_Project_5_225004_s, 0);
    SW_Project_TD_5902046(tbl_Window_TD_6765754_output, tbl_Project_TD_5902046_output);
    gettimeofday(&tv_r_Project_5_225004_e, 0);

    struct timeval tv_r_JOIN_INNER_5_270062_s, tv_r_JOIN_INNER_5_270062_e;
    gettimeofday(&tv_r_JOIN_INNER_5_270062_s, 0);
    SW_JOIN_INNER_TD_5199655(tbl_Filter_TD_6739433_output, tbl_Project_TD_6359877_output, tbl_JOIN_INNER_TD_5199655_output);
    gettimeofday(&tv_r_JOIN_INNER_5_270062_e, 0);

    struct timeval tv_r_JOIN_INNER_4_736439_s, tv_r_JOIN_INNER_4_736439_e;
    gettimeofday(&tv_r_JOIN_INNER_4_736439_s, 0);
    SW_JOIN_INNER_TD_4503684(tbl_JOIN_INNER_TD_5199655_output, tbl_Project_TD_5902046_output, tbl_JOIN_INNER_TD_4503684_output);
    gettimeofday(&tv_r_JOIN_INNER_4_736439_e, 0);

    struct timeval tv_r_Project_3_725552_s, tv_r_Project_3_725552_e;
    gettimeofday(&tv_r_Project_3_725552_s, 0);
    SW_Project_TD_3149367(tbl_JOIN_INNER_TD_4503684_output, tbl_Project_TD_3149367_output);
    gettimeofday(&tv_r_Project_3_725552_e, 0);

    struct timeval tv_r_Sort_2_790275_s, tv_r_Sort_2_790275_e;
    gettimeofday(&tv_r_Sort_2_790275_s, 0);
    SW_Sort_TD_2151559(tbl_Project_TD_3149367_output, tbl_Sort_TD_2151559_output);
    gettimeofday(&tv_r_Sort_2_790275_e, 0);

    struct timeval tv_r_LocalLimit_1_512072_s, tv_r_LocalLimit_1_512072_e;
    gettimeofday(&tv_r_LocalLimit_1_512072_s, 0);
    SW_LocalLimit_TD_1597577(tbl_Sort_TD_2151559_output, tbl_LocalLimit_TD_1597577_output);
    gettimeofday(&tv_r_LocalLimit_1_512072_e, 0);

    struct timeval tv_r_GlobalLimit_0_80248_s, tv_r_GlobalLimit_0_80248_e;
    gettimeofday(&tv_r_GlobalLimit_0_80248_s, 0);
    SW_GlobalLimit_TD_0457744(tbl_LocalLimit_TD_1597577_output, tbl_GlobalLimit_TD_0457744_output);
    gettimeofday(&tv_r_GlobalLimit_0_80248_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_14: " << tvdiff(&tv_r_Filter_14_365202_s, &tv_r_Filter_14_365202_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_15419224_input: " << tbl_SerializeFromObject_TD_15419224_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_14: " << tvdiff(&tv_r_Filter_14_498618_s, &tv_r_Filter_14_498618_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_15398144_input: " << tbl_SerializeFromObject_TD_15398144_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_13: " << tvdiff(&tv_r_Filter_13_750349_s, &tv_r_Filter_13_750349_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_14802568_input: " << tbl_SerializeFromObject_TD_14802568_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_13: " << tvdiff(&tv_r_JOIN_INNER_13_93310_s, &tv_r_JOIN_INNER_13_93310_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_14208171_output: " << tbl_Filter_TD_14208171_output.getNumRow() << " " << "tbl_Filter_TD_14434599_output: " << tbl_Filter_TD_14434599_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_185055_s, &tv_r_Filter_12_185055_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13911383_input: " << tbl_SerializeFromObject_TD_13911383_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_423997_s, &tv_r_Filter_12_423997_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13534262_input: " << tbl_SerializeFromObject_TD_13534262_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_397371_s, &tv_r_Filter_12_397371_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13383862_input: " << tbl_SerializeFromObject_TD_13383862_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_12: " << tvdiff(&tv_r_JOIN_INNER_12_669795_s, &tv_r_JOIN_INNER_12_669795_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_13515608_output: " << tbl_JOIN_INNER_TD_13515608_output.getNumRow() << " " << "tbl_Filter_TD_13912779_output: " << tbl_Filter_TD_13912779_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_862832_s, &tv_r_Filter_11_862832_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12430691_input: " << tbl_SerializeFromObject_TD_12430691_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_701945_s, &tv_r_Filter_11_701945_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12145072_input: " << tbl_SerializeFromObject_TD_12145072_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_863037_s, &tv_r_Filter_11_863037_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1212713_input: " << tbl_SerializeFromObject_TD_1212713_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_11: " << tvdiff(&tv_r_JOIN_INNER_11_956267_s, &tv_r_JOIN_INNER_11_956267_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_12274745_output: " << tbl_Filter_TD_12274745_output.getNumRow() << " " << "tbl_Filter_TD_12810859_output: " << tbl_Filter_TD_12810859_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_11: " << tvdiff(&tv_r_JOIN_INNER_11_710419_s, &tv_r_JOIN_INNER_11_710419_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_12974871_output: " << tbl_JOIN_INNER_TD_12974871_output.getNumRow() << " " << "tbl_Filter_TD_12735478_output: " << tbl_Filter_TD_12735478_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_764208_s, &tv_r_Filter_10_764208_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11779885_input: " << tbl_SerializeFromObject_TD_11779885_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_790759_s, &tv_r_JOIN_INNER_10_790759_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11686420_output: " << tbl_Filter_TD_11686420_output.getNumRow() << " " << "tbl_Filter_TD_11987487_output: " << tbl_Filter_TD_11987487_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_939974_s, &tv_r_Filter_10_939974_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11511324_input: " << tbl_SerializeFromObject_TD_11511324_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_185845_s, &tv_r_JOIN_INNER_10_185845_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_11650222_output: " << tbl_JOIN_INNER_TD_11650222_output.getNumRow() << " " << "tbl_Filter_TD_11848688_output: " << tbl_Filter_TD_11848688_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_10: " << tvdiff(&tv_r_Aggregate_10_333178_s, &tv_r_Aggregate_10_333178_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_11976272_output: " << tbl_JOIN_INNER_TD_11976272_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_877413_s, &tv_r_Filter_9_877413_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1058800_input: " << tbl_SerializeFromObject_TD_1058800_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_398384_s, &tv_r_JOIN_INNER_9_398384_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10575406_output: " << tbl_JOIN_INNER_TD_10575406_output.getNumRow() << " " << "tbl_Filter_TD_10754913_output: " << tbl_Filter_TD_10754913_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_855778_s, &tv_r_JOIN_INNER_9_855778_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10880607_output: " << tbl_JOIN_INNER_TD_10880607_output.getNumRow() << " " << "tbl_Filter_TD_10808472_output: " << tbl_Filter_TD_10808472_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_9: " << tvdiff(&tv_r_Window_9_60442_s, &tv_r_Window_9_60442_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_10406594_output: " << tbl_Aggregate_TD_10406594_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_216724_s, &tv_r_JOIN_INNER_8_216724_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9435922_output: " << tbl_JOIN_INNER_TD_9435922_output.getNumRow() << " " << "tbl_Filter_TD_9100061_output: " << tbl_Filter_TD_9100061_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_8: " << tvdiff(&tv_r_Aggregate_8_671642_s, &tv_r_Aggregate_8_671642_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9135593_output: " << tbl_JOIN_INNER_TD_9135593_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_28136_s, &tv_r_Filter_8_28136_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_9144530_output: " << tbl_Window_TD_9144530_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_7: " << tvdiff(&tv_r_Aggregate_7_902652_s, &tv_r_Aggregate_7_902652_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8400276_output: " << tbl_JOIN_INNER_TD_8400276_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_7: " << tvdiff(&tv_r_Window_7_366958_s, &tv_r_Window_7_366958_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_8602438_output: " << tbl_Aggregate_TD_8602438_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_7: " << tvdiff(&tv_r_Window_7_274234_s, &tv_r_Window_7_274234_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8717904_output: " << tbl_Filter_TD_8717904_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_6: " << tvdiff(&tv_r_Window_6_944857_s, &tv_r_Window_6_944857_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_7672439_output: " << tbl_Aggregate_TD_7672439_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_6: " << tvdiff(&tv_r_Project_6_948109_s, &tv_r_Project_6_948109_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_74072_output: " << tbl_Window_TD_74072_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_131357_s, &tv_r_Filter_6_131357_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_7140839_output: " << tbl_Window_TD_7140839_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_5: " << tvdiff(&tv_r_Project_5_225004_s, &tv_r_Project_5_225004_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_6765754_output: " << tbl_Window_TD_6765754_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_270062_s, &tv_r_JOIN_INNER_5_270062_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6739433_output: " << tbl_Filter_TD_6739433_output.getNumRow() << " " << "tbl_Project_TD_6359877_output: " << tbl_Project_TD_6359877_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_736439_s, &tv_r_JOIN_INNER_4_736439_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5199655_output: " << tbl_JOIN_INNER_TD_5199655_output.getNumRow() << " " << "tbl_Project_TD_5902046_output: " << tbl_Project_TD_5902046_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_3: " << tvdiff(&tv_r_Project_3_725552_s, &tv_r_Project_3_725552_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4503684_output: " << tbl_JOIN_INNER_TD_4503684_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_790275_s, &tv_r_Sort_2_790275_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_3149367_output: " << tbl_Project_TD_3149367_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_512072_s, &tv_r_LocalLimit_1_512072_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2151559_output: " << tbl_Sort_TD_2151559_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_80248_s, &tv_r_GlobalLimit_0_80248_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1597577_output: " << tbl_LocalLimit_TD_1597577_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 4.299101 * 1000 << "ms" << std::endl; 
    return 0; 
}
