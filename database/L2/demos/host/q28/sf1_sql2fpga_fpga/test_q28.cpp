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

#include "cfgFunc_q28.hpp" 
#include "q28.hpp" 

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
    std::cout << "NOTE:running query #28\n."; 
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
    Table tbl_JOIN_CROSS_TD_0149094_output("tbl_JOIN_CROSS_TD_0149094_output", 6100000, 18, "");
    tbl_JOIN_CROSS_TD_0149094_output.allocateHost();
    Table tbl_JOIN_CROSS_TD_1542306_output("tbl_JOIN_CROSS_TD_1542306_output", 6100000, 15, "");
    tbl_JOIN_CROSS_TD_1542306_output.allocateHost();
    Table tbl_Aggregate_TD_1518637_output("tbl_Aggregate_TD_1518637_output", 6100000, 3, "");
    tbl_Aggregate_TD_1518637_output.allocateHost();
    Table tbl_JOIN_CROSS_TD_2196656_output("tbl_JOIN_CROSS_TD_2196656_output", 6100000, 12, "");
    tbl_JOIN_CROSS_TD_2196656_output.allocateHost();
    Table tbl_Aggregate_TD_2912604_output("tbl_Aggregate_TD_2912604_output", 6100000, 3, "");
    tbl_Aggregate_TD_2912604_output.allocateHost();
    Table tbl_Filter_TD_2649598_output("tbl_Filter_TD_2649598_output", 6100000, 1, "");
    tbl_Filter_TD_2649598_output.allocateHost();
    Table tbl_JOIN_CROSS_TD_3716761_output("tbl_JOIN_CROSS_TD_3716761_output", 6100000, 9, "");
    tbl_JOIN_CROSS_TD_3716761_output.allocateHost();
    Table tbl_Aggregate_TD_3352777_output("tbl_Aggregate_TD_3352777_output", 6100000, 3, "");
    tbl_Aggregate_TD_3352777_output.allocateHost();
    Table tbl_Filter_TD_3666595_output("tbl_Filter_TD_3666595_output", 6100000, 1, "");
    tbl_Filter_TD_3666595_output.allocateHost();
    Table tbl_SerializeFromObject_TD_3635086_input;
    tbl_SerializeFromObject_TD_3635086_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_3635086_input.addCol("ss_list_price", 4);
    tbl_SerializeFromObject_TD_3635086_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_3635086_input.addCol("ss_coupon_amt", 4);
    tbl_SerializeFromObject_TD_3635086_input.addCol("ss_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_3635086_input.allocateHost();
    tbl_SerializeFromObject_TD_3635086_input.loadHost();
    Table tbl_JOIN_CROSS_TD_484149_output("tbl_JOIN_CROSS_TD_484149_output", 6100000, 6, "");
    tbl_JOIN_CROSS_TD_484149_output.allocateHost();
    Table tbl_Aggregate_TD_4810094_output("tbl_Aggregate_TD_4810094_output", 6100000, 3, "");
    tbl_Aggregate_TD_4810094_output.allocateHost();
    Table tbl_Filter_TD_4456148_output("tbl_Filter_TD_4456148_output", 6100000, 1, "");
    tbl_Filter_TD_4456148_output.allocateHost();
    Table tbl_SerializeFromObject_TD_4362882_input;
    tbl_SerializeFromObject_TD_4362882_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_4362882_input.addCol("ss_list_price", 4);
    tbl_SerializeFromObject_TD_4362882_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_4362882_input.addCol("ss_coupon_amt", 4);
    tbl_SerializeFromObject_TD_4362882_input.addCol("ss_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_4362882_input.allocateHost();
    tbl_SerializeFromObject_TD_4362882_input.loadHost();
    Table tbl_Aggregate_TD_5269518_output("tbl_Aggregate_TD_5269518_output", 6100000, 3, "");
    tbl_Aggregate_TD_5269518_output.allocateHost();
    Table tbl_Aggregate_TD_5667718_output("tbl_Aggregate_TD_5667718_output", 6100000, 3, "");
    tbl_Aggregate_TD_5667718_output.allocateHost();
    Table tbl_Filter_TD_5400820_output("tbl_Filter_TD_5400820_output", 6100000, 1, "");
    tbl_Filter_TD_5400820_output.allocateHost();
    Table tbl_SerializeFromObject_TD_5461933_input;
    tbl_SerializeFromObject_TD_5461933_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_5461933_input.addCol("ss_list_price", 4);
    tbl_SerializeFromObject_TD_5461933_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_5461933_input.addCol("ss_coupon_amt", 4);
    tbl_SerializeFromObject_TD_5461933_input.addCol("ss_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_5461933_input.allocateHost();
    tbl_SerializeFromObject_TD_5461933_input.loadHost();
    Table tbl_Filter_TD_6938631_output("tbl_Filter_TD_6938631_output", 6100000, 1, "");
    tbl_Filter_TD_6938631_output.allocateHost();
    Table tbl_Filter_TD_6704913_output("tbl_Filter_TD_6704913_output", 6100000, 1, "");
    tbl_Filter_TD_6704913_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6949753_input;
    tbl_SerializeFromObject_TD_6949753_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_6949753_input.addCol("ss_list_price", 4);
    tbl_SerializeFromObject_TD_6949753_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_6949753_input.addCol("ss_coupon_amt", 4);
    tbl_SerializeFromObject_TD_6949753_input.addCol("ss_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_6949753_input.allocateHost();
    tbl_SerializeFromObject_TD_6949753_input.loadHost();
    Table tbl_SerializeFromObject_TD_7716893_input;
    tbl_SerializeFromObject_TD_7716893_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_7716893_input.addCol("ss_list_price", 4);
    tbl_SerializeFromObject_TD_7716893_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_7716893_input.addCol("ss_coupon_amt", 4);
    tbl_SerializeFromObject_TD_7716893_input.addCol("ss_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_7716893_input.allocateHost();
    tbl_SerializeFromObject_TD_7716893_input.loadHost();
    Table tbl_SerializeFromObject_TD_7551047_input;
    tbl_SerializeFromObject_TD_7551047_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_7551047_input.addCol("ss_list_price", 4);
    tbl_SerializeFromObject_TD_7551047_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_7551047_input.addCol("ss_coupon_amt", 4);
    tbl_SerializeFromObject_TD_7551047_input.addCol("ss_wholesale_cost", 4);
    tbl_SerializeFromObject_TD_7551047_input.allocateHost();
    tbl_SerializeFromObject_TD_7551047_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    std::cout << std::endl; 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_6_545783_s, tv_r_Filter_6_545783_e;
    gettimeofday(&tv_r_Filter_6_545783_s, 0);
    SW_Filter_TD_6704913(tbl_SerializeFromObject_TD_7551047_input, tbl_Filter_TD_6704913_output);
    gettimeofday(&tv_r_Filter_6_545783_e, 0);

    struct timeval tv_r_Filter_6_693467_s, tv_r_Filter_6_693467_e;
    gettimeofday(&tv_r_Filter_6_693467_s, 0);
    SW_Filter_TD_6938631(tbl_SerializeFromObject_TD_7716893_input, tbl_Filter_TD_6938631_output);
    gettimeofday(&tv_r_Filter_6_693467_e, 0);

    struct timeval tv_r_Filter_5_611301_s, tv_r_Filter_5_611301_e;
    gettimeofday(&tv_r_Filter_5_611301_s, 0);
    SW_Filter_TD_5400820(tbl_SerializeFromObject_TD_6949753_input, tbl_Filter_TD_5400820_output);
    gettimeofday(&tv_r_Filter_5_611301_e, 0);

    struct timeval tv_r_Aggregate_5_702073_s, tv_r_Aggregate_5_702073_e;
    gettimeofday(&tv_r_Aggregate_5_702073_s, 0);
    SW_Aggregate_TD_5667718(tbl_Filter_TD_6704913_output, tbl_Aggregate_TD_5667718_output);
    gettimeofday(&tv_r_Aggregate_5_702073_e, 0);

    struct timeval tv_r_Aggregate_5_201377_s, tv_r_Aggregate_5_201377_e;
    gettimeofday(&tv_r_Aggregate_5_201377_s, 0);
    SW_Aggregate_TD_5269518(tbl_Filter_TD_6938631_output, tbl_Aggregate_TD_5269518_output);
    gettimeofday(&tv_r_Aggregate_5_201377_e, 0);

    struct timeval tv_r_Filter_4_601295_s, tv_r_Filter_4_601295_e;
    gettimeofday(&tv_r_Filter_4_601295_s, 0);
    SW_Filter_TD_4456148(tbl_SerializeFromObject_TD_5461933_input, tbl_Filter_TD_4456148_output);
    gettimeofday(&tv_r_Filter_4_601295_e, 0);

    struct timeval tv_r_Aggregate_4_209488_s, tv_r_Aggregate_4_209488_e;
    gettimeofday(&tv_r_Aggregate_4_209488_s, 0);
    SW_Aggregate_TD_4810094(tbl_Filter_TD_5400820_output, tbl_Aggregate_TD_4810094_output);
    gettimeofday(&tv_r_Aggregate_4_209488_e, 0);

    struct timeval tv_r_JOIN_CROSS_4_742779_s, tv_r_JOIN_CROSS_4_742779_e;
    gettimeofday(&tv_r_JOIN_CROSS_4_742779_s, 0);
    SW_JOIN_CROSS_TD_484149(tbl_Aggregate_TD_5269518_output, tbl_Aggregate_TD_5667718_output, tbl_JOIN_CROSS_TD_484149_output);
    gettimeofday(&tv_r_JOIN_CROSS_4_742779_e, 0);

    struct timeval tv_r_Filter_3_214721_s, tv_r_Filter_3_214721_e;
    gettimeofday(&tv_r_Filter_3_214721_s, 0);
    SW_Filter_TD_3666595(tbl_SerializeFromObject_TD_4362882_input, tbl_Filter_TD_3666595_output);
    gettimeofday(&tv_r_Filter_3_214721_e, 0);

    struct timeval tv_r_Aggregate_3_614202_s, tv_r_Aggregate_3_614202_e;
    gettimeofday(&tv_r_Aggregate_3_614202_s, 0);
    SW_Aggregate_TD_3352777(tbl_Filter_TD_4456148_output, tbl_Aggregate_TD_3352777_output);
    gettimeofday(&tv_r_Aggregate_3_614202_e, 0);

    struct timeval tv_r_JOIN_CROSS_3_498688_s, tv_r_JOIN_CROSS_3_498688_e;
    gettimeofday(&tv_r_JOIN_CROSS_3_498688_s, 0);
    SW_JOIN_CROSS_TD_3716761(tbl_JOIN_CROSS_TD_484149_output, tbl_Aggregate_TD_4810094_output, tbl_JOIN_CROSS_TD_3716761_output);
    gettimeofday(&tv_r_JOIN_CROSS_3_498688_e, 0);

    struct timeval tv_r_Filter_2_390246_s, tv_r_Filter_2_390246_e;
    gettimeofday(&tv_r_Filter_2_390246_s, 0);
    SW_Filter_TD_2649598(tbl_SerializeFromObject_TD_3635086_input, tbl_Filter_TD_2649598_output);
    gettimeofday(&tv_r_Filter_2_390246_e, 0);

    struct timeval tv_r_Aggregate_2_557264_s, tv_r_Aggregate_2_557264_e;
    gettimeofday(&tv_r_Aggregate_2_557264_s, 0);
    SW_Aggregate_TD_2912604(tbl_Filter_TD_3666595_output, tbl_Aggregate_TD_2912604_output);
    gettimeofday(&tv_r_Aggregate_2_557264_e, 0);

    struct timeval tv_r_JOIN_CROSS_2_369680_s, tv_r_JOIN_CROSS_2_369680_e;
    gettimeofday(&tv_r_JOIN_CROSS_2_369680_s, 0);
    SW_JOIN_CROSS_TD_2196656(tbl_JOIN_CROSS_TD_3716761_output, tbl_Aggregate_TD_3352777_output, tbl_JOIN_CROSS_TD_2196656_output);
    gettimeofday(&tv_r_JOIN_CROSS_2_369680_e, 0);

    struct timeval tv_r_Aggregate_1_645138_s, tv_r_Aggregate_1_645138_e;
    gettimeofday(&tv_r_Aggregate_1_645138_s, 0);
    SW_Aggregate_TD_1518637(tbl_Filter_TD_2649598_output, tbl_Aggregate_TD_1518637_output);
    gettimeofday(&tv_r_Aggregate_1_645138_e, 0);

    struct timeval tv_r_JOIN_CROSS_1_112619_s, tv_r_JOIN_CROSS_1_112619_e;
    gettimeofday(&tv_r_JOIN_CROSS_1_112619_s, 0);
    SW_JOIN_CROSS_TD_1542306(tbl_JOIN_CROSS_TD_2196656_output, tbl_Aggregate_TD_2912604_output, tbl_JOIN_CROSS_TD_1542306_output);
    gettimeofday(&tv_r_JOIN_CROSS_1_112619_e, 0);

    struct timeval tv_r_JOIN_CROSS_0_858140_s, tv_r_JOIN_CROSS_0_858140_e;
    gettimeofday(&tv_r_JOIN_CROSS_0_858140_s, 0);
    SW_JOIN_CROSS_TD_0149094(tbl_JOIN_CROSS_TD_1542306_output, tbl_Aggregate_TD_1518637_output, tbl_JOIN_CROSS_TD_0149094_output);
    gettimeofday(&tv_r_JOIN_CROSS_0_858140_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_545783_s, &tv_r_Filter_6_545783_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7551047_input: " << tbl_SerializeFromObject_TD_7551047_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_693467_s, &tv_r_Filter_6_693467_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7716893_input: " << tbl_SerializeFromObject_TD_7716893_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_611301_s, &tv_r_Filter_5_611301_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6949753_input: " << tbl_SerializeFromObject_TD_6949753_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_702073_s, &tv_r_Aggregate_5_702073_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6704913_output: " << tbl_Filter_TD_6704913_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_201377_s, &tv_r_Aggregate_5_201377_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6938631_output: " << tbl_Filter_TD_6938631_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_601295_s, &tv_r_Filter_4_601295_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5461933_input: " << tbl_SerializeFromObject_TD_5461933_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_4: " << tvdiff(&tv_r_Aggregate_4_209488_s, &tv_r_Aggregate_4_209488_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_5400820_output: " << tbl_Filter_TD_5400820_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_CROSS_4: " << tvdiff(&tv_r_JOIN_CROSS_4_742779_s, &tv_r_JOIN_CROSS_4_742779_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_5269518_output: " << tbl_Aggregate_TD_5269518_output.getNumRow() << " " << "tbl_Aggregate_TD_5667718_output: " << tbl_Aggregate_TD_5667718_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_214721_s, &tv_r_Filter_3_214721_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_4362882_input: " << tbl_SerializeFromObject_TD_4362882_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_614202_s, &tv_r_Aggregate_3_614202_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_4456148_output: " << tbl_Filter_TD_4456148_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_CROSS_3: " << tvdiff(&tv_r_JOIN_CROSS_3_498688_s, &tv_r_JOIN_CROSS_3_498688_e) / 1000.0 << " ms " 
     << "tbl_JOIN_CROSS_TD_484149_output: " << tbl_JOIN_CROSS_TD_484149_output.getNumRow() << " " << "tbl_Aggregate_TD_4810094_output: " << tbl_Aggregate_TD_4810094_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_390246_s, &tv_r_Filter_2_390246_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3635086_input: " << tbl_SerializeFromObject_TD_3635086_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_2: " << tvdiff(&tv_r_Aggregate_2_557264_s, &tv_r_Aggregate_2_557264_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_3666595_output: " << tbl_Filter_TD_3666595_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_CROSS_2: " << tvdiff(&tv_r_JOIN_CROSS_2_369680_s, &tv_r_JOIN_CROSS_2_369680_e) / 1000.0 << " ms " 
     << "tbl_JOIN_CROSS_TD_3716761_output: " << tbl_JOIN_CROSS_TD_3716761_output.getNumRow() << " " << "tbl_Aggregate_TD_3352777_output: " << tbl_Aggregate_TD_3352777_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_645138_s, &tv_r_Aggregate_1_645138_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_2649598_output: " << tbl_Filter_TD_2649598_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_CROSS_1: " << tvdiff(&tv_r_JOIN_CROSS_1_112619_s, &tv_r_JOIN_CROSS_1_112619_e) / 1000.0 << " ms " 
     << "tbl_JOIN_CROSS_TD_2196656_output: " << tbl_JOIN_CROSS_TD_2196656_output.getNumRow() << " " << "tbl_Aggregate_TD_2912604_output: " << tbl_Aggregate_TD_2912604_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_CROSS_0: " << tvdiff(&tv_r_JOIN_CROSS_0_858140_s, &tv_r_JOIN_CROSS_0_858140_e) / 1000.0 << " ms " 
     << "tbl_JOIN_CROSS_TD_1542306_output: " << tbl_JOIN_CROSS_TD_1542306_output.getNumRow() << " " << "tbl_Aggregate_TD_1518637_output: " << tbl_Aggregate_TD_1518637_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 5.380736 * 1000 << "ms" << std::endl; 
    return 0; 
}
