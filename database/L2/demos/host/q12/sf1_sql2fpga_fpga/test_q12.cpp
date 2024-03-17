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

#include "cfgFunc_q12.hpp" 
#include "q12.hpp" 

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
    std::cout << "NOTE:running query #12\n."; 
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
    Table tbl_GlobalLimit_TD_0528340_output("tbl_GlobalLimit_TD_0528340_output", 6100000, 7, "");
    tbl_GlobalLimit_TD_0528340_output.allocateHost();
    Table tbl_LocalLimit_TD_1446660_output("tbl_LocalLimit_TD_1446660_output", 6100000, 7, "");
    tbl_LocalLimit_TD_1446660_output.allocateHost();
    Table tbl_Sort_TD_2649169_output("tbl_Sort_TD_2649169_output", 6100000, 7, "");
    tbl_Sort_TD_2649169_output.allocateHost();
    Table tbl_Project_TD_3460544_output("tbl_Project_TD_3460544_output", 6100000, 7, "");
    tbl_Project_TD_3460544_output.allocateHost();
    Table tbl_Window_TD_4332232_output("tbl_Window_TD_4332232_output", 6100000, 9, "");
    tbl_Window_TD_4332232_output.allocateHost();
    Table tbl_Aggregate_TD_5951892_output("tbl_Aggregate_TD_5951892_output", 6100000, 8, "");
    tbl_Aggregate_TD_5951892_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6436394_output("tbl_JOIN_INNER_TD_6436394_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_6436394_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7797929_output("tbl_JOIN_INNER_TD_7797929_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_7797929_output.allocateHost();
    Table tbl_Filter_TD_7450004_output("tbl_Filter_TD_7450004_output", 6100000, 1, "");
    tbl_Filter_TD_7450004_output.allocateHost();
    Table tbl_Filter_TD_8610465_output("tbl_Filter_TD_8610465_output", 6100000, 3, "");
    tbl_Filter_TD_8610465_output.allocateHost();
    Table tbl_Filter_TD_8272523_output("tbl_Filter_TD_8272523_output", 6100000, 6, "");
    tbl_Filter_TD_8272523_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8920945_input;
    tbl_SerializeFromObject_TD_8920945_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8920945_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_8920945_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_8920945_input.allocateHost();
    tbl_SerializeFromObject_TD_8920945_input.loadHost();
    Table tbl_SerializeFromObject_TD_9980572_input;
    tbl_SerializeFromObject_TD_9980572_input = Table("web_sales", web_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9980572_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_9980572_input.addCol("ws_item_sk", 4);
    tbl_SerializeFromObject_TD_9980572_input.addCol("ws_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_9980572_input.allocateHost();
    tbl_SerializeFromObject_TD_9980572_input.loadHost();
    Table tbl_SerializeFromObject_TD_964347_input;
    tbl_SerializeFromObject_TD_964347_input = Table("item", item_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_964347_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_964347_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_964347_input.addCol("i_item_desc", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_964347_input.addCol("i_current_price", 4);
    tbl_SerializeFromObject_TD_964347_input.addCol("i_class", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_964347_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_964347_input.allocateHost();
    tbl_SerializeFromObject_TD_964347_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    std::cout << std::endl; 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_8_742527_s, tv_r_Filter_8_742527_e;
    gettimeofday(&tv_r_Filter_8_742527_s, 0);
    SW_Filter_TD_8272523(tbl_SerializeFromObject_TD_964347_input, tbl_Filter_TD_8272523_output);
    gettimeofday(&tv_r_Filter_8_742527_e, 0);

    struct timeval tv_r_Filter_8_81235_s, tv_r_Filter_8_81235_e;
    gettimeofday(&tv_r_Filter_8_81235_s, 0);
    SW_Filter_TD_8610465(tbl_SerializeFromObject_TD_9980572_input, tbl_Filter_TD_8610465_output);
    gettimeofday(&tv_r_Filter_8_81235_e, 0);

    struct timeval tv_r_Filter_7_784523_s, tv_r_Filter_7_784523_e;
    gettimeofday(&tv_r_Filter_7_784523_s, 0);
    SW_Filter_TD_7450004(tbl_SerializeFromObject_TD_8920945_input, tbl_Filter_TD_7450004_output);
    gettimeofday(&tv_r_Filter_7_784523_e, 0);

    struct timeval tv_r_JOIN_INNER_7_389805_s, tv_r_JOIN_INNER_7_389805_e;
    gettimeofday(&tv_r_JOIN_INNER_7_389805_s, 0);
    SW_JOIN_INNER_TD_7797929(tbl_Filter_TD_8610465_output, tbl_Filter_TD_8272523_output, tbl_JOIN_INNER_TD_7797929_output);
    gettimeofday(&tv_r_JOIN_INNER_7_389805_e, 0);

    struct timeval tv_r_JOIN_INNER_6_262891_s, tv_r_JOIN_INNER_6_262891_e;
    gettimeofday(&tv_r_JOIN_INNER_6_262891_s, 0);
    SW_JOIN_INNER_TD_6436394(tbl_JOIN_INNER_TD_7797929_output, tbl_Filter_TD_7450004_output, tbl_JOIN_INNER_TD_6436394_output);
    gettimeofday(&tv_r_JOIN_INNER_6_262891_e, 0);

    struct timeval tv_r_Aggregate_5_637332_s, tv_r_Aggregate_5_637332_e;
    gettimeofday(&tv_r_Aggregate_5_637332_s, 0);
    SW_Aggregate_TD_5951892(tbl_JOIN_INNER_TD_6436394_output, tbl_Aggregate_TD_5951892_output);
    gettimeofday(&tv_r_Aggregate_5_637332_e, 0);

    struct timeval tv_r_Window_4_719594_s, tv_r_Window_4_719594_e;
    gettimeofday(&tv_r_Window_4_719594_s, 0);
    SW_Window_TD_4332232(tbl_Aggregate_TD_5951892_output, tbl_Window_TD_4332232_output);
    gettimeofday(&tv_r_Window_4_719594_e, 0);

    struct timeval tv_r_Project_3_913255_s, tv_r_Project_3_913255_e;
    gettimeofday(&tv_r_Project_3_913255_s, 0);
    SW_Project_TD_3460544(tbl_Window_TD_4332232_output, tbl_Project_TD_3460544_output);
    gettimeofday(&tv_r_Project_3_913255_e, 0);

    struct timeval tv_r_Sort_2_667358_s, tv_r_Sort_2_667358_e;
    gettimeofday(&tv_r_Sort_2_667358_s, 0);
    SW_Sort_TD_2649169(tbl_Project_TD_3460544_output, tbl_Sort_TD_2649169_output);
    gettimeofday(&tv_r_Sort_2_667358_e, 0);

    struct timeval tv_r_LocalLimit_1_915839_s, tv_r_LocalLimit_1_915839_e;
    gettimeofday(&tv_r_LocalLimit_1_915839_s, 0);
    SW_LocalLimit_TD_1446660(tbl_Sort_TD_2649169_output, tbl_LocalLimit_TD_1446660_output);
    gettimeofday(&tv_r_LocalLimit_1_915839_e, 0);

    struct timeval tv_r_GlobalLimit_0_276341_s, tv_r_GlobalLimit_0_276341_e;
    gettimeofday(&tv_r_GlobalLimit_0_276341_s, 0);
    SW_GlobalLimit_TD_0528340(tbl_LocalLimit_TD_1446660_output, tbl_GlobalLimit_TD_0528340_output);
    gettimeofday(&tv_r_GlobalLimit_0_276341_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_742527_s, &tv_r_Filter_8_742527_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_964347_input: " << tbl_SerializeFromObject_TD_964347_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_81235_s, &tv_r_Filter_8_81235_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9980572_input: " << tbl_SerializeFromObject_TD_9980572_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_784523_s, &tv_r_Filter_7_784523_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8920945_input: " << tbl_SerializeFromObject_TD_8920945_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_389805_s, &tv_r_JOIN_INNER_7_389805_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8610465_output: " << tbl_Filter_TD_8610465_output.getNumRow() << " " << "tbl_Filter_TD_8272523_output: " << tbl_Filter_TD_8272523_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_262891_s, &tv_r_JOIN_INNER_6_262891_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7797929_output: " << tbl_JOIN_INNER_TD_7797929_output.getNumRow() << " " << "tbl_Filter_TD_7450004_output: " << tbl_Filter_TD_7450004_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_637332_s, &tv_r_Aggregate_5_637332_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6436394_output: " << tbl_JOIN_INNER_TD_6436394_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_4: " << tvdiff(&tv_r_Window_4_719594_s, &tv_r_Window_4_719594_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_5951892_output: " << tbl_Aggregate_TD_5951892_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_3: " << tvdiff(&tv_r_Project_3_913255_s, &tv_r_Project_3_913255_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_4332232_output: " << tbl_Window_TD_4332232_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_667358_s, &tv_r_Sort_2_667358_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_3460544_output: " << tbl_Project_TD_3460544_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_915839_s, &tv_r_LocalLimit_1_915839_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2649169_output: " << tbl_Sort_TD_2649169_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_276341_s, &tv_r_GlobalLimit_0_276341_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1446660_output: " << tbl_LocalLimit_TD_1446660_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.2633007 * 1000 << "ms" << std::endl; 
    return 0; 
}
