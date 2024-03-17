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

#include "cfgFunc_q62.hpp" 
#include "q62.hpp" 

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
    std::cout << "NOTE:running query #62\n."; 
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
    Table tbl_GlobalLimit_TD_0581969_output("tbl_GlobalLimit_TD_0581969_output", 6100000, 8, "");
    tbl_GlobalLimit_TD_0581969_output.allocateHost();
    Table tbl_LocalLimit_TD_1152328_output("tbl_LocalLimit_TD_1152328_output", 6100000, 8, "");
    tbl_LocalLimit_TD_1152328_output.allocateHost();
    Table tbl_Sort_TD_2270030_output("tbl_Sort_TD_2270030_output", 6100000, 8, "");
    tbl_Sort_TD_2270030_output.allocateHost();
    Table tbl_Aggregate_TD_3269919_output("tbl_Aggregate_TD_3269919_output", 6100000, 8, "");
    tbl_Aggregate_TD_3269919_output.allocateHost();
    Table tbl_Project_TD_488822_output("tbl_Project_TD_488822_output", 6100000, 5, "");
    tbl_Project_TD_488822_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5764510_output("tbl_JOIN_INNER_TD_5764510_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_5764510_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6100287_output("tbl_JOIN_INNER_TD_6100287_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_6100287_output.allocateHost();
    Table tbl_Filter_TD_6757077_output("tbl_Filter_TD_6757077_output", 6100000, 1, "");
    tbl_Filter_TD_6757077_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7941240_output("tbl_JOIN_INNER_TD_7941240_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_7941240_output.allocateHost();
    Table tbl_Filter_TD_7910097_output("tbl_Filter_TD_7910097_output", 6100000, 2, "");
    tbl_Filter_TD_7910097_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7767525_input;
    tbl_SerializeFromObject_TD_7767525_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7767525_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_7767525_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_7767525_input.allocateHost();
    tbl_SerializeFromObject_TD_7767525_input.loadHost();
    Table tbl_JOIN_INNER_TD_8555322_output("tbl_JOIN_INNER_TD_8555322_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_8555322_output.allocateHost();
    Table tbl_Filter_TD_8263398_output("tbl_Filter_TD_8263398_output", 6100000, 2, "");
    tbl_Filter_TD_8263398_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8942264_input;
    tbl_SerializeFromObject_TD_8942264_input = Table("web_site", web_site_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8942264_input.addCol("web_site_sk", 4);
    tbl_SerializeFromObject_TD_8942264_input.addCol("web_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8942264_input.allocateHost();
    tbl_SerializeFromObject_TD_8942264_input.loadHost();
    Table tbl_Filter_TD_9315014_output("tbl_Filter_TD_9315014_output", 6100000, 5, "");
    tbl_Filter_TD_9315014_output.allocateHost();
    Table tbl_Filter_TD_9368299_output("tbl_Filter_TD_9368299_output", 6100000, 2, "");
    tbl_Filter_TD_9368299_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9910388_input;
    tbl_SerializeFromObject_TD_9910388_input = Table("ship_mode", ship_mode_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9910388_input.addCol("sm_ship_mode_sk", 4);
    tbl_SerializeFromObject_TD_9910388_input.addCol("sm_type", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9910388_input.allocateHost();
    tbl_SerializeFromObject_TD_9910388_input.loadHost();
    Table tbl_SerializeFromObject_TD_10454510_input;
    tbl_SerializeFromObject_TD_10454510_input = Table("web_sales", web_sales_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_10454510_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10454510_input.addCol("ws_ship_date_sk", 4);
    tbl_SerializeFromObject_TD_10454510_input.addCol("ws_web_site_sk", 4);
    tbl_SerializeFromObject_TD_10454510_input.addCol("ws_ship_mode_sk", 4);
    tbl_SerializeFromObject_TD_10454510_input.addCol("ws_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_10454510_input.allocateHost();
    tbl_SerializeFromObject_TD_10454510_input.loadHost();
    Table tbl_SerializeFromObject_TD_10814938_input;
    tbl_SerializeFromObject_TD_10814938_input = Table("warehouse", warehouse_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10814938_input.addCol("w_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_10814938_input.addCol("w_warehouse_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10814938_input.allocateHost();
    tbl_SerializeFromObject_TD_10814938_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    std::cout << std::endl; 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_9_148262_s, tv_r_Filter_9_148262_e;
    gettimeofday(&tv_r_Filter_9_148262_s, 0);
    SW_Filter_TD_9368299(tbl_SerializeFromObject_TD_10814938_input, tbl_Filter_TD_9368299_output);
    gettimeofday(&tv_r_Filter_9_148262_e, 0);

    struct timeval tv_r_Filter_9_989579_s, tv_r_Filter_9_989579_e;
    gettimeofday(&tv_r_Filter_9_989579_s, 0);
    SW_Filter_TD_9315014(tbl_SerializeFromObject_TD_10454510_input, tbl_Filter_TD_9315014_output);
    gettimeofday(&tv_r_Filter_9_989579_e, 0);

    struct timeval tv_r_Filter_8_729693_s, tv_r_Filter_8_729693_e;
    gettimeofday(&tv_r_Filter_8_729693_s, 0);
    SW_Filter_TD_8263398(tbl_SerializeFromObject_TD_9910388_input, tbl_Filter_TD_8263398_output);
    gettimeofday(&tv_r_Filter_8_729693_e, 0);

    struct timeval tv_r_JOIN_INNER_8_289988_s, tv_r_JOIN_INNER_8_289988_e;
    gettimeofday(&tv_r_JOIN_INNER_8_289988_s, 0);
    SW_JOIN_INNER_TD_8555322(tbl_Filter_TD_9315014_output, tbl_Filter_TD_9368299_output, tbl_JOIN_INNER_TD_8555322_output);
    gettimeofday(&tv_r_JOIN_INNER_8_289988_e, 0);

    struct timeval tv_r_Filter_7_239705_s, tv_r_Filter_7_239705_e;
    gettimeofday(&tv_r_Filter_7_239705_s, 0);
    SW_Filter_TD_7910097(tbl_SerializeFromObject_TD_8942264_input, tbl_Filter_TD_7910097_output);
    gettimeofday(&tv_r_Filter_7_239705_e, 0);

    struct timeval tv_r_JOIN_INNER_7_698981_s, tv_r_JOIN_INNER_7_698981_e;
    gettimeofday(&tv_r_JOIN_INNER_7_698981_s, 0);
    SW_JOIN_INNER_TD_7941240(tbl_JOIN_INNER_TD_8555322_output, tbl_Filter_TD_8263398_output, tbl_JOIN_INNER_TD_7941240_output);
    gettimeofday(&tv_r_JOIN_INNER_7_698981_e, 0);

    struct timeval tv_r_Filter_6_67947_s, tv_r_Filter_6_67947_e;
    gettimeofday(&tv_r_Filter_6_67947_s, 0);
    SW_Filter_TD_6757077(tbl_SerializeFromObject_TD_7767525_input, tbl_Filter_TD_6757077_output);
    gettimeofday(&tv_r_Filter_6_67947_e, 0);

    struct timeval tv_r_JOIN_INNER_6_6078_s, tv_r_JOIN_INNER_6_6078_e;
    gettimeofday(&tv_r_JOIN_INNER_6_6078_s, 0);
    SW_JOIN_INNER_TD_6100287(tbl_JOIN_INNER_TD_7941240_output, tbl_Filter_TD_7910097_output, tbl_JOIN_INNER_TD_6100287_output);
    gettimeofday(&tv_r_JOIN_INNER_6_6078_e, 0);

    struct timeval tv_r_JOIN_INNER_5_277657_s, tv_r_JOIN_INNER_5_277657_e;
    gettimeofday(&tv_r_JOIN_INNER_5_277657_s, 0);
    SW_JOIN_INNER_TD_5764510(tbl_JOIN_INNER_TD_6100287_output, tbl_Filter_TD_6757077_output, tbl_JOIN_INNER_TD_5764510_output);
    gettimeofday(&tv_r_JOIN_INNER_5_277657_e, 0);

    struct timeval tv_r_Project_4_495241_s, tv_r_Project_4_495241_e;
    gettimeofday(&tv_r_Project_4_495241_s, 0);
    SW_Project_TD_488822(tbl_JOIN_INNER_TD_5764510_output, tbl_Project_TD_488822_output);
    gettimeofday(&tv_r_Project_4_495241_e, 0);

    struct timeval tv_r_Aggregate_3_43703_s, tv_r_Aggregate_3_43703_e;
    gettimeofday(&tv_r_Aggregate_3_43703_s, 0);
    SW_Aggregate_TD_3269919(tbl_Project_TD_488822_output, tbl_Aggregate_TD_3269919_output);
    gettimeofday(&tv_r_Aggregate_3_43703_e, 0);

    struct timeval tv_r_Sort_2_285790_s, tv_r_Sort_2_285790_e;
    gettimeofday(&tv_r_Sort_2_285790_s, 0);
    SW_Sort_TD_2270030(tbl_Aggregate_TD_3269919_output, tbl_Sort_TD_2270030_output);
    gettimeofday(&tv_r_Sort_2_285790_e, 0);

    struct timeval tv_r_LocalLimit_1_964125_s, tv_r_LocalLimit_1_964125_e;
    gettimeofday(&tv_r_LocalLimit_1_964125_s, 0);
    SW_LocalLimit_TD_1152328(tbl_Sort_TD_2270030_output, tbl_LocalLimit_TD_1152328_output);
    gettimeofday(&tv_r_LocalLimit_1_964125_e, 0);

    struct timeval tv_r_GlobalLimit_0_110004_s, tv_r_GlobalLimit_0_110004_e;
    gettimeofday(&tv_r_GlobalLimit_0_110004_s, 0);
    SW_GlobalLimit_TD_0581969(tbl_LocalLimit_TD_1152328_output, tbl_GlobalLimit_TD_0581969_output);
    gettimeofday(&tv_r_GlobalLimit_0_110004_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_148262_s, &tv_r_Filter_9_148262_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10814938_input: " << tbl_SerializeFromObject_TD_10814938_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_989579_s, &tv_r_Filter_9_989579_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10454510_input: " << tbl_SerializeFromObject_TD_10454510_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_729693_s, &tv_r_Filter_8_729693_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9910388_input: " << tbl_SerializeFromObject_TD_9910388_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_289988_s, &tv_r_JOIN_INNER_8_289988_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9315014_output: " << tbl_Filter_TD_9315014_output.getNumRow() << " " << "tbl_Filter_TD_9368299_output: " << tbl_Filter_TD_9368299_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_239705_s, &tv_r_Filter_7_239705_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8942264_input: " << tbl_SerializeFromObject_TD_8942264_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_698981_s, &tv_r_JOIN_INNER_7_698981_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8555322_output: " << tbl_JOIN_INNER_TD_8555322_output.getNumRow() << " " << "tbl_Filter_TD_8263398_output: " << tbl_Filter_TD_8263398_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_67947_s, &tv_r_Filter_6_67947_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7767525_input: " << tbl_SerializeFromObject_TD_7767525_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_6078_s, &tv_r_JOIN_INNER_6_6078_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7941240_output: " << tbl_JOIN_INNER_TD_7941240_output.getNumRow() << " " << "tbl_Filter_TD_7910097_output: " << tbl_Filter_TD_7910097_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_277657_s, &tv_r_JOIN_INNER_5_277657_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6100287_output: " << tbl_JOIN_INNER_TD_6100287_output.getNumRow() << " " << "tbl_Filter_TD_6757077_output: " << tbl_Filter_TD_6757077_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_4: " << tvdiff(&tv_r_Project_4_495241_s, &tv_r_Project_4_495241_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5764510_output: " << tbl_JOIN_INNER_TD_5764510_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_43703_s, &tv_r_Aggregate_3_43703_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_488822_output: " << tbl_Project_TD_488822_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_285790_s, &tv_r_Sort_2_285790_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3269919_output: " << tbl_Aggregate_TD_3269919_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_964125_s, &tv_r_LocalLimit_1_964125_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2270030_output: " << tbl_Sort_TD_2270030_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_110004_s, &tv_r_GlobalLimit_0_110004_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1152328_output: " << tbl_LocalLimit_TD_1152328_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.0661097 * 1000 << "ms" << std::endl; 
    return 0; 
}
