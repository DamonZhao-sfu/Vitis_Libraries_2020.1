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

#include "cfgFunc_q20.hpp" 
#include "q20.hpp" 

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
    std::cout << "NOTE:running query #20\n."; 
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
    Table tbl_GlobalLimit_TD_0898833_output("tbl_GlobalLimit_TD_0898833_output", 6100000, 7, "");
    tbl_GlobalLimit_TD_0898833_output.allocateHost();
    Table tbl_LocalLimit_TD_163517_output("tbl_LocalLimit_TD_163517_output", 6100000, 7, "");
    tbl_LocalLimit_TD_163517_output.allocateHost();
    Table tbl_Sort_TD_2108537_output("tbl_Sort_TD_2108537_output", 6100000, 7, "");
    tbl_Sort_TD_2108537_output.allocateHost();
    Table tbl_Project_TD_3240413_output("tbl_Project_TD_3240413_output", 6100000, 7, "");
    tbl_Project_TD_3240413_output.allocateHost();
    Table tbl_Window_TD_4569661_output("tbl_Window_TD_4569661_output", 6100000, 9, "");
    tbl_Window_TD_4569661_output.allocateHost();
    Table tbl_Aggregate_TD_5478371_output("tbl_Aggregate_TD_5478371_output", 6100000, 8, "");
    tbl_Aggregate_TD_5478371_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6176026_output("tbl_JOIN_INNER_TD_6176026_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_6176026_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7957703_output("tbl_JOIN_INNER_TD_7957703_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_7957703_output.allocateHost();
    Table tbl_Filter_TD_7289422_output("tbl_Filter_TD_7289422_output", 6100000, 1, "");
    tbl_Filter_TD_7289422_output.allocateHost();
    Table tbl_Filter_TD_8782645_output("tbl_Filter_TD_8782645_output", 6100000, 3, "");
    tbl_Filter_TD_8782645_output.allocateHost();
    Table tbl_Filter_TD_8898288_output("tbl_Filter_TD_8898288_output", 6100000, 6, "");
    tbl_Filter_TD_8898288_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8191863_input;
    tbl_SerializeFromObject_TD_8191863_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8191863_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_8191863_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_8191863_input.allocateHost();
    tbl_SerializeFromObject_TD_8191863_input.loadHost();
    Table tbl_SerializeFromObject_TD_9863281_input;
    tbl_SerializeFromObject_TD_9863281_input = Table("catalog_sales", catalog_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9863281_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_9863281_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_9863281_input.addCol("cs_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_9863281_input.allocateHost();
    tbl_SerializeFromObject_TD_9863281_input.loadHost();
    Table tbl_SerializeFromObject_TD_9212888_input;
    tbl_SerializeFromObject_TD_9212888_input = Table("item", item_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_9212888_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_9212888_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9212888_input.addCol("i_item_desc", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9212888_input.addCol("i_current_price", 4);
    tbl_SerializeFromObject_TD_9212888_input.addCol("i_class", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9212888_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9212888_input.allocateHost();
    tbl_SerializeFromObject_TD_9212888_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    std::cout << std::endl; 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_8_111845_s, tv_r_Filter_8_111845_e;
    gettimeofday(&tv_r_Filter_8_111845_s, 0);
    SW_Filter_TD_8898288(tbl_SerializeFromObject_TD_9212888_input, tbl_Filter_TD_8898288_output);
    gettimeofday(&tv_r_Filter_8_111845_e, 0);

    struct timeval tv_r_Filter_8_925142_s, tv_r_Filter_8_925142_e;
    gettimeofday(&tv_r_Filter_8_925142_s, 0);
    SW_Filter_TD_8782645(tbl_SerializeFromObject_TD_9863281_input, tbl_Filter_TD_8782645_output);
    gettimeofday(&tv_r_Filter_8_925142_e, 0);

    struct timeval tv_r_Filter_7_251250_s, tv_r_Filter_7_251250_e;
    gettimeofday(&tv_r_Filter_7_251250_s, 0);
    SW_Filter_TD_7289422(tbl_SerializeFromObject_TD_8191863_input, tbl_Filter_TD_7289422_output);
    gettimeofday(&tv_r_Filter_7_251250_e, 0);

    struct timeval tv_r_JOIN_INNER_7_930777_s, tv_r_JOIN_INNER_7_930777_e;
    gettimeofday(&tv_r_JOIN_INNER_7_930777_s, 0);
    SW_JOIN_INNER_TD_7957703(tbl_Filter_TD_8782645_output, tbl_Filter_TD_8898288_output, tbl_JOIN_INNER_TD_7957703_output);
    gettimeofday(&tv_r_JOIN_INNER_7_930777_e, 0);

    struct timeval tv_r_JOIN_INNER_6_150717_s, tv_r_JOIN_INNER_6_150717_e;
    gettimeofday(&tv_r_JOIN_INNER_6_150717_s, 0);
    SW_JOIN_INNER_TD_6176026(tbl_JOIN_INNER_TD_7957703_output, tbl_Filter_TD_7289422_output, tbl_JOIN_INNER_TD_6176026_output);
    gettimeofday(&tv_r_JOIN_INNER_6_150717_e, 0);

    struct timeval tv_r_Aggregate_5_425077_s, tv_r_Aggregate_5_425077_e;
    gettimeofday(&tv_r_Aggregate_5_425077_s, 0);
    SW_Aggregate_TD_5478371(tbl_JOIN_INNER_TD_6176026_output, tbl_Aggregate_TD_5478371_output);
    gettimeofday(&tv_r_Aggregate_5_425077_e, 0);

    struct timeval tv_r_Window_4_904374_s, tv_r_Window_4_904374_e;
    gettimeofday(&tv_r_Window_4_904374_s, 0);
    SW_Window_TD_4569661(tbl_Aggregate_TD_5478371_output, tbl_Window_TD_4569661_output);
    gettimeofday(&tv_r_Window_4_904374_e, 0);

    struct timeval tv_r_Project_3_86302_s, tv_r_Project_3_86302_e;
    gettimeofday(&tv_r_Project_3_86302_s, 0);
    SW_Project_TD_3240413(tbl_Window_TD_4569661_output, tbl_Project_TD_3240413_output);
    gettimeofday(&tv_r_Project_3_86302_e, 0);

    struct timeval tv_r_Sort_2_942530_s, tv_r_Sort_2_942530_e;
    gettimeofday(&tv_r_Sort_2_942530_s, 0);
    SW_Sort_TD_2108537(tbl_Project_TD_3240413_output, tbl_Sort_TD_2108537_output);
    gettimeofday(&tv_r_Sort_2_942530_e, 0);

    struct timeval tv_r_LocalLimit_1_69339_s, tv_r_LocalLimit_1_69339_e;
    gettimeofday(&tv_r_LocalLimit_1_69339_s, 0);
    SW_LocalLimit_TD_163517(tbl_Sort_TD_2108537_output, tbl_LocalLimit_TD_163517_output);
    gettimeofday(&tv_r_LocalLimit_1_69339_e, 0);

    struct timeval tv_r_GlobalLimit_0_45982_s, tv_r_GlobalLimit_0_45982_e;
    gettimeofday(&tv_r_GlobalLimit_0_45982_s, 0);
    SW_GlobalLimit_TD_0898833(tbl_LocalLimit_TD_163517_output, tbl_GlobalLimit_TD_0898833_output);
    gettimeofday(&tv_r_GlobalLimit_0_45982_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_111845_s, &tv_r_Filter_8_111845_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9212888_input: " << tbl_SerializeFromObject_TD_9212888_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_925142_s, &tv_r_Filter_8_925142_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9863281_input: " << tbl_SerializeFromObject_TD_9863281_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_251250_s, &tv_r_Filter_7_251250_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8191863_input: " << tbl_SerializeFromObject_TD_8191863_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_930777_s, &tv_r_JOIN_INNER_7_930777_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8782645_output: " << tbl_Filter_TD_8782645_output.getNumRow() << " " << "tbl_Filter_TD_8898288_output: " << tbl_Filter_TD_8898288_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_150717_s, &tv_r_JOIN_INNER_6_150717_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7957703_output: " << tbl_JOIN_INNER_TD_7957703_output.getNumRow() << " " << "tbl_Filter_TD_7289422_output: " << tbl_Filter_TD_7289422_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_425077_s, &tv_r_Aggregate_5_425077_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6176026_output: " << tbl_JOIN_INNER_TD_6176026_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_4: " << tvdiff(&tv_r_Window_4_904374_s, &tv_r_Window_4_904374_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_5478371_output: " << tbl_Aggregate_TD_5478371_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_3: " << tvdiff(&tv_r_Project_3_86302_s, &tv_r_Project_3_86302_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_4569661_output: " << tbl_Window_TD_4569661_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_942530_s, &tv_r_Sort_2_942530_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_3240413_output: " << tbl_Project_TD_3240413_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_69339_s, &tv_r_LocalLimit_1_69339_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2108537_output: " << tbl_Sort_TD_2108537_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_45982_s, &tv_r_GlobalLimit_0_45982_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_163517_output: " << tbl_LocalLimit_TD_163517_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.4312389 * 1000 << "ms" << std::endl; 
    return 0; 
}
