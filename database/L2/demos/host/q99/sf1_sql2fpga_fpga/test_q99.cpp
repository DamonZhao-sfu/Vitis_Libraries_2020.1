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
#include "cfgFunc_q99.hpp" 
#include "q99.hpp" 

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
    std::cout << "NOTE:running query #99\n."; 
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
    Table tbl_GlobalLimit_TD_0227526_output("tbl_GlobalLimit_TD_0227526_output", 6100000, 8, "");
    tbl_GlobalLimit_TD_0227526_output.allocateHost();
    Table tbl_LocalLimit_TD_1349029_output("tbl_LocalLimit_TD_1349029_output", 6100000, 8, "");
    tbl_LocalLimit_TD_1349029_output.allocateHost();
    Table tbl_Sort_TD_2588414_output("tbl_Sort_TD_2588414_output", 6100000, 8, "");
    tbl_Sort_TD_2588414_output.allocateHost();
    Table tbl_Aggregate_TD_3984732_output("tbl_Aggregate_TD_3984732_output", 6100000, 8, "");
    tbl_Aggregate_TD_3984732_output.allocateHost();
    Table tbl_Project_TD_471838_output("tbl_Project_TD_471838_output", 6100000, 5, "");
    tbl_Project_TD_471838_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5276004_output("tbl_JOIN_INNER_TD_5276004_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_5276004_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6388532_output("tbl_JOIN_INNER_TD_6388532_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_6388532_output.allocateHost();
    Table tbl_Filter_TD_6791794_output("tbl_Filter_TD_6791794_output", 6100000, 1, "");
    tbl_Filter_TD_6791794_output.allocateHost();
    Table tbl_JOIN_INNER_TD_745813_output("tbl_JOIN_INNER_TD_745813_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_745813_output.allocateHost();
    Table tbl_Filter_TD_735959_output("tbl_Filter_TD_735959_output", 6100000, 2, "");
    tbl_Filter_TD_735959_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7894001_input;
    tbl_SerializeFromObject_TD_7894001_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7894001_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_7894001_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_7894001_input.allocateHost();
    tbl_SerializeFromObject_TD_7894001_input.loadHost();
    Table tbl_JOIN_INNER_TD_8387172_output("tbl_JOIN_INNER_TD_8387172_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_8387172_output.allocateHost();
    Table tbl_Filter_TD_8794558_output("tbl_Filter_TD_8794558_output", 6100000, 2, "");
    tbl_Filter_TD_8794558_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8118177_input;
    tbl_SerializeFromObject_TD_8118177_input = Table("call_center", call_center_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8118177_input.addCol("cc_call_center_sk", 4);
    tbl_SerializeFromObject_TD_8118177_input.addCol("cc_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8118177_input.allocateHost();
    tbl_SerializeFromObject_TD_8118177_input.loadHost();
    Table tbl_Filter_TD_9736564_output("tbl_Filter_TD_9736564_output", 6100000, 5, "");
    tbl_Filter_TD_9736564_output.allocateHost();
    Table tbl_Filter_TD_9837484_output("tbl_Filter_TD_9837484_output", 6100000, 2, "");
    tbl_Filter_TD_9837484_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9288641_input;
    tbl_SerializeFromObject_TD_9288641_input = Table("ship_mode", ship_mode_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9288641_input.addCol("sm_ship_mode_sk", 4);
    tbl_SerializeFromObject_TD_9288641_input.addCol("sm_type", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9288641_input.allocateHost();
    tbl_SerializeFromObject_TD_9288641_input.loadHost();
    Table tbl_SerializeFromObject_TD_10637158_input;
    tbl_SerializeFromObject_TD_10637158_input = Table("catalog_sales", catalog_sales_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_10637158_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10637158_input.addCol("cs_ship_date_sk", 4);
    tbl_SerializeFromObject_TD_10637158_input.addCol("cs_call_center_sk", 4);
    tbl_SerializeFromObject_TD_10637158_input.addCol("cs_ship_mode_sk", 4);
    tbl_SerializeFromObject_TD_10637158_input.addCol("cs_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_10637158_input.allocateHost();
    tbl_SerializeFromObject_TD_10637158_input.loadHost();
    Table tbl_SerializeFromObject_TD_10543223_input;
    tbl_SerializeFromObject_TD_10543223_input = Table("warehouse", warehouse_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10543223_input.addCol("w_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_10543223_input.addCol("w_warehouse_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10543223_input.allocateHost();
    tbl_SerializeFromObject_TD_10543223_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    std::cout << std::endl; 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_9_394670_s, tv_r_Filter_9_394670_e;
    gettimeofday(&tv_r_Filter_9_394670_s, 0);
    SW_Filter_TD_9837484(tbl_SerializeFromObject_TD_10543223_input, tbl_Filter_TD_9837484_output);
    gettimeofday(&tv_r_Filter_9_394670_e, 0);

    struct timeval tv_r_Filter_9_124130_s, tv_r_Filter_9_124130_e;
    gettimeofday(&tv_r_Filter_9_124130_s, 0);
    SW_Filter_TD_9736564(tbl_SerializeFromObject_TD_10637158_input, tbl_Filter_TD_9736564_output);
    gettimeofday(&tv_r_Filter_9_124130_e, 0);

    struct timeval tv_r_Filter_8_864996_s, tv_r_Filter_8_864996_e;
    gettimeofday(&tv_r_Filter_8_864996_s, 0);
    SW_Filter_TD_8794558(tbl_SerializeFromObject_TD_9288641_input, tbl_Filter_TD_8794558_output);
    gettimeofday(&tv_r_Filter_8_864996_e, 0);

    struct timeval tv_r_JOIN_INNER_8_899112_s, tv_r_JOIN_INNER_8_899112_e;
    gettimeofday(&tv_r_JOIN_INNER_8_899112_s, 0);
    SW_JOIN_INNER_TD_8387172(tbl_Filter_TD_9736564_output, tbl_Filter_TD_9837484_output, tbl_JOIN_INNER_TD_8387172_output);
    gettimeofday(&tv_r_JOIN_INNER_8_899112_e, 0);

    struct timeval tv_r_Filter_7_236769_s, tv_r_Filter_7_236769_e;
    gettimeofday(&tv_r_Filter_7_236769_s, 0);
    SW_Filter_TD_735959(tbl_SerializeFromObject_TD_8118177_input, tbl_Filter_TD_735959_output);
    gettimeofday(&tv_r_Filter_7_236769_e, 0);

    struct timeval tv_r_JOIN_INNER_7_758325_s, tv_r_JOIN_INNER_7_758325_e;
    gettimeofday(&tv_r_JOIN_INNER_7_758325_s, 0);
    SW_JOIN_INNER_TD_745813(tbl_JOIN_INNER_TD_8387172_output, tbl_Filter_TD_8794558_output, tbl_JOIN_INNER_TD_745813_output);
    gettimeofday(&tv_r_JOIN_INNER_7_758325_e, 0);

    struct timeval tv_r_Filter_6_670641_s, tv_r_Filter_6_670641_e;
    gettimeofday(&tv_r_Filter_6_670641_s, 0);
    SW_Filter_TD_6791794(tbl_SerializeFromObject_TD_7894001_input, tbl_Filter_TD_6791794_output);
    gettimeofday(&tv_r_Filter_6_670641_e, 0);

    struct timeval tv_r_JOIN_INNER_6_106114_s, tv_r_JOIN_INNER_6_106114_e;
    gettimeofday(&tv_r_JOIN_INNER_6_106114_s, 0);
    SW_JOIN_INNER_TD_6388532(tbl_JOIN_INNER_TD_745813_output, tbl_Filter_TD_735959_output, tbl_JOIN_INNER_TD_6388532_output);
    gettimeofday(&tv_r_JOIN_INNER_6_106114_e, 0);

    struct timeval tv_r_JOIN_INNER_5_263712_s, tv_r_JOIN_INNER_5_263712_e;
    gettimeofday(&tv_r_JOIN_INNER_5_263712_s, 0);
    SW_JOIN_INNER_TD_5276004(tbl_JOIN_INNER_TD_6388532_output, tbl_Filter_TD_6791794_output, tbl_JOIN_INNER_TD_5276004_output);
    gettimeofday(&tv_r_JOIN_INNER_5_263712_e, 0);

    struct timeval tv_r_Project_4_192997_s, tv_r_Project_4_192997_e;
    gettimeofday(&tv_r_Project_4_192997_s, 0);
    SW_Project_TD_471838(tbl_JOIN_INNER_TD_5276004_output, tbl_Project_TD_471838_output);
    gettimeofday(&tv_r_Project_4_192997_e, 0);

    struct timeval tv_r_Aggregate_3_174268_s, tv_r_Aggregate_3_174268_e;
    gettimeofday(&tv_r_Aggregate_3_174268_s, 0);
    SW_Aggregate_TD_3984732(tbl_Project_TD_471838_output, tbl_Aggregate_TD_3984732_output);
    gettimeofday(&tv_r_Aggregate_3_174268_e, 0);

    struct timeval tv_r_Sort_2_447694_s, tv_r_Sort_2_447694_e;
    gettimeofday(&tv_r_Sort_2_447694_s, 0);
    SW_Sort_TD_2588414(tbl_Aggregate_TD_3984732_output, tbl_Sort_TD_2588414_output);
    gettimeofday(&tv_r_Sort_2_447694_e, 0);

    struct timeval tv_r_LocalLimit_1_315790_s, tv_r_LocalLimit_1_315790_e;
    gettimeofday(&tv_r_LocalLimit_1_315790_s, 0);
    SW_LocalLimit_TD_1349029(tbl_Sort_TD_2588414_output, tbl_LocalLimit_TD_1349029_output);
    gettimeofday(&tv_r_LocalLimit_1_315790_e, 0);

    struct timeval tv_r_GlobalLimit_0_446400_s, tv_r_GlobalLimit_0_446400_e;
    gettimeofday(&tv_r_GlobalLimit_0_446400_s, 0);
    SW_GlobalLimit_TD_0227526(tbl_LocalLimit_TD_1349029_output, tbl_GlobalLimit_TD_0227526_output);
    gettimeofday(&tv_r_GlobalLimit_0_446400_e, 0);

    


    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_394670_s, &tv_r_Filter_9_394670_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10543223_input: " << tbl_SerializeFromObject_TD_10543223_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_124130_s, &tv_r_Filter_9_124130_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10637158_input: " << tbl_SerializeFromObject_TD_10637158_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_864996_s, &tv_r_Filter_8_864996_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9288641_input: " << tbl_SerializeFromObject_TD_9288641_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_899112_s, &tv_r_JOIN_INNER_8_899112_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9736564_output: " << tbl_Filter_TD_9736564_output.getNumRow() << " " << "tbl_Filter_TD_9837484_output: " << tbl_Filter_TD_9837484_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_236769_s, &tv_r_Filter_7_236769_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8118177_input: " << tbl_SerializeFromObject_TD_8118177_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_758325_s, &tv_r_JOIN_INNER_7_758325_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8387172_output: " << tbl_JOIN_INNER_TD_8387172_output.getNumRow() << " " << "tbl_Filter_TD_8794558_output: " << tbl_Filter_TD_8794558_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_670641_s, &tv_r_Filter_6_670641_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7894001_input: " << tbl_SerializeFromObject_TD_7894001_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_106114_s, &tv_r_JOIN_INNER_6_106114_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_745813_output: " << tbl_JOIN_INNER_TD_745813_output.getNumRow() << " " << "tbl_Filter_TD_735959_output: " << tbl_Filter_TD_735959_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_263712_s, &tv_r_JOIN_INNER_5_263712_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6388532_output: " << tbl_JOIN_INNER_TD_6388532_output.getNumRow() << " " << "tbl_Filter_TD_6791794_output: " << tbl_Filter_TD_6791794_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_4: " << tvdiff(&tv_r_Project_4_192997_s, &tv_r_Project_4_192997_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5276004_output: " << tbl_JOIN_INNER_TD_5276004_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_174268_s, &tv_r_Aggregate_3_174268_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_471838_output: " << tbl_Project_TD_471838_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_447694_s, &tv_r_Sort_2_447694_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3984732_output: " << tbl_Aggregate_TD_3984732_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_315790_s, &tv_r_LocalLimit_1_315790_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2588414_output: " << tbl_Sort_TD_2588414_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_446400_s, &tv_r_GlobalLimit_0_446400_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1349029_output: " << tbl_LocalLimit_TD_1349029_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.2510155 * 1000 << "ms" << std::endl; 
    return 0; 
}
