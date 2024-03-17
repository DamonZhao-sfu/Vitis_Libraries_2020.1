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

#include "cfgFunc_q43.hpp" 
#include "q43.hpp" 

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
    std::cout << "NOTE:running query #43\n."; 
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
    Table tbl_GlobalLimit_TD_0543461_output("tbl_GlobalLimit_TD_0543461_output", 6100000, 9, "");
    tbl_GlobalLimit_TD_0543461_output.allocateHost();
    Table tbl_LocalLimit_TD_1112902_output("tbl_LocalLimit_TD_1112902_output", 6100000, 9, "");
    tbl_LocalLimit_TD_1112902_output.allocateHost();
    Table tbl_Sort_TD_2452741_output("tbl_Sort_TD_2452741_output", 6100000, 9, "");
    tbl_Sort_TD_2452741_output.allocateHost();
    Table tbl_Aggregate_TD_3204869_output("tbl_Aggregate_TD_3204869_output", 6100000, 9, "");
    tbl_Aggregate_TD_3204869_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4549771_output("tbl_JOIN_INNER_TD_4549771_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_4549771_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5741773_output("tbl_JOIN_INNER_TD_5741773_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_5741773_output.allocateHost();
    Table tbl_Filter_TD_5157459_output("tbl_Filter_TD_5157459_output", 6100000, 3, "");
    tbl_Filter_TD_5157459_output.allocateHost();
    Table tbl_Filter_TD_6782103_output("tbl_Filter_TD_6782103_output", 6100000, 2, "");
    tbl_Filter_TD_6782103_output.allocateHost();
    Table tbl_Filter_TD_6363769_output("tbl_Filter_TD_6363769_output", 6100000, 3, "");
    tbl_Filter_TD_6363769_output.allocateHost();
    Table tbl_SerializeFromObject_TD_630191_input;
    tbl_SerializeFromObject_TD_630191_input = Table("store", store_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_630191_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_630191_input.addCol("s_store_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_630191_input.addCol("s_store_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_630191_input.addCol("s_gmt_offset", 4);
    tbl_SerializeFromObject_TD_630191_input.allocateHost();
    tbl_SerializeFromObject_TD_630191_input.loadHost();
    Table tbl_SerializeFromObject_TD_7724527_input;
    tbl_SerializeFromObject_TD_7724527_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7724527_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_7724527_input.addCol("d_day_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7724527_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_7724527_input.allocateHost();
    tbl_SerializeFromObject_TD_7724527_input.loadHost();
    Table tbl_SerializeFromObject_TD_7762907_input;
    tbl_SerializeFromObject_TD_7762907_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7762907_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_7762907_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_7762907_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_7762907_input.allocateHost();
    tbl_SerializeFromObject_TD_7762907_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    std::cout << std::endl; 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_6_631150_s, tv_r_Filter_6_631150_e;
    gettimeofday(&tv_r_Filter_6_631150_s, 0);
    SW_Filter_TD_6363769(tbl_SerializeFromObject_TD_7762907_input, tbl_Filter_TD_6363769_output);
    gettimeofday(&tv_r_Filter_6_631150_e, 0);

    struct timeval tv_r_Filter_6_455955_s, tv_r_Filter_6_455955_e;
    gettimeofday(&tv_r_Filter_6_455955_s, 0);
    SW_Filter_TD_6782103(tbl_SerializeFromObject_TD_7724527_input, tbl_Filter_TD_6782103_output);
    gettimeofday(&tv_r_Filter_6_455955_e, 0);

    struct timeval tv_r_Filter_5_245088_s, tv_r_Filter_5_245088_e;
    gettimeofday(&tv_r_Filter_5_245088_s, 0);
    SW_Filter_TD_5157459(tbl_SerializeFromObject_TD_630191_input, tbl_Filter_TD_5157459_output);
    gettimeofday(&tv_r_Filter_5_245088_e, 0);

    struct timeval tv_r_JOIN_INNER_5_789420_s, tv_r_JOIN_INNER_5_789420_e;
    gettimeofday(&tv_r_JOIN_INNER_5_789420_s, 0);
    SW_JOIN_INNER_TD_5741773(tbl_Filter_TD_6782103_output, tbl_Filter_TD_6363769_output, tbl_JOIN_INNER_TD_5741773_output);
    gettimeofday(&tv_r_JOIN_INNER_5_789420_e, 0);

    struct timeval tv_r_JOIN_INNER_4_70228_s, tv_r_JOIN_INNER_4_70228_e;
    gettimeofday(&tv_r_JOIN_INNER_4_70228_s, 0);
    SW_JOIN_INNER_TD_4549771(tbl_JOIN_INNER_TD_5741773_output, tbl_Filter_TD_5157459_output, tbl_JOIN_INNER_TD_4549771_output);
    gettimeofday(&tv_r_JOIN_INNER_4_70228_e, 0);

    struct timeval tv_r_Aggregate_3_625265_s, tv_r_Aggregate_3_625265_e;
    gettimeofday(&tv_r_Aggregate_3_625265_s, 0);
    SW_Aggregate_TD_3204869(tbl_JOIN_INNER_TD_4549771_output, tbl_Aggregate_TD_3204869_output);
    gettimeofday(&tv_r_Aggregate_3_625265_e, 0);

    struct timeval tv_r_Sort_2_531665_s, tv_r_Sort_2_531665_e;
    gettimeofday(&tv_r_Sort_2_531665_s, 0);
    SW_Sort_TD_2452741(tbl_Aggregate_TD_3204869_output, tbl_Sort_TD_2452741_output);
    gettimeofday(&tv_r_Sort_2_531665_e, 0);

    struct timeval tv_r_LocalLimit_1_727703_s, tv_r_LocalLimit_1_727703_e;
    gettimeofday(&tv_r_LocalLimit_1_727703_s, 0);
    SW_LocalLimit_TD_1112902(tbl_Sort_TD_2452741_output, tbl_LocalLimit_TD_1112902_output);
    gettimeofday(&tv_r_LocalLimit_1_727703_e, 0);

    struct timeval tv_r_GlobalLimit_0_942312_s, tv_r_GlobalLimit_0_942312_e;
    gettimeofday(&tv_r_GlobalLimit_0_942312_s, 0);
    SW_GlobalLimit_TD_0543461(tbl_LocalLimit_TD_1112902_output, tbl_GlobalLimit_TD_0543461_output);
    gettimeofday(&tv_r_GlobalLimit_0_942312_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_631150_s, &tv_r_Filter_6_631150_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7762907_input: " << tbl_SerializeFromObject_TD_7762907_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_455955_s, &tv_r_Filter_6_455955_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7724527_input: " << tbl_SerializeFromObject_TD_7724527_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_245088_s, &tv_r_Filter_5_245088_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_630191_input: " << tbl_SerializeFromObject_TD_630191_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_789420_s, &tv_r_JOIN_INNER_5_789420_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6782103_output: " << tbl_Filter_TD_6782103_output.getNumRow() << " " << "tbl_Filter_TD_6363769_output: " << tbl_Filter_TD_6363769_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_70228_s, &tv_r_JOIN_INNER_4_70228_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5741773_output: " << tbl_JOIN_INNER_TD_5741773_output.getNumRow() << " " << "tbl_Filter_TD_5157459_output: " << tbl_Filter_TD_5157459_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_625265_s, &tv_r_Aggregate_3_625265_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4549771_output: " << tbl_JOIN_INNER_TD_4549771_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_531665_s, &tv_r_Sort_2_531665_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3204869_output: " << tbl_Aggregate_TD_3204869_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_727703_s, &tv_r_LocalLimit_1_727703_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2452741_output: " << tbl_Sort_TD_2452741_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_942312_s, &tv_r_GlobalLimit_0_942312_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1112902_output: " << tbl_LocalLimit_TD_1112902_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.3105495 * 1000 << "ms" << std::endl; 
    return 0; 
}
