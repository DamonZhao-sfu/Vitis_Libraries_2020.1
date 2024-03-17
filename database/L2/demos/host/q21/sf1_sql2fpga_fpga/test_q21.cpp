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

#include "cfgFunc_q21.hpp" 
#include "q21.hpp" 

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
    std::cout << "NOTE:running query #21\n."; 
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
    Table tbl_GlobalLimit_TD_0564374_output("tbl_GlobalLimit_TD_0564374_output", 6100000, 4, "");
    tbl_GlobalLimit_TD_0564374_output.allocateHost();
    Table tbl_LocalLimit_TD_1953724_output("tbl_LocalLimit_TD_1953724_output", 6100000, 4, "");
    tbl_LocalLimit_TD_1953724_output.allocateHost();
    Table tbl_Sort_TD_264578_output("tbl_Sort_TD_264578_output", 6100000, 4, "");
    tbl_Sort_TD_264578_output.allocateHost();
    Table tbl_Filter_TD_3950469_output("tbl_Filter_TD_3950469_output", 6100000, 4, "");
    tbl_Filter_TD_3950469_output.allocateHost();
    Table tbl_Aggregate_TD_4230421_output("tbl_Aggregate_TD_4230421_output", 6100000, 4, "");
    tbl_Aggregate_TD_4230421_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5737030_output("tbl_JOIN_INNER_TD_5737030_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_5737030_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6218165_output("tbl_JOIN_INNER_TD_6218165_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_6218165_output.allocateHost();
    Table tbl_Filter_TD_6896397_output("tbl_Filter_TD_6896397_output", 6100000, 2, "");
    tbl_Filter_TD_6896397_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7304750_output("tbl_JOIN_INNER_TD_7304750_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_7304750_output.allocateHost();
    Table tbl_Filter_TD_7227204_output("tbl_Filter_TD_7227204_output", 6100000, 2, "");
    tbl_Filter_TD_7227204_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7952618_input;
    tbl_SerializeFromObject_TD_7952618_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7952618_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_7952618_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_7952618_input.allocateHost();
    tbl_SerializeFromObject_TD_7952618_input.loadHost();
    Table tbl_Filter_TD_8562041_output("tbl_Filter_TD_8562041_output", 6100000, 4, "");
    tbl_Filter_TD_8562041_output.allocateHost();
    Table tbl_Filter_TD_8969129_output("tbl_Filter_TD_8969129_output", 6100000, 2, "");
    tbl_Filter_TD_8969129_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8809267_input;
    tbl_SerializeFromObject_TD_8809267_input = Table("item", item_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8809267_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_8809267_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8809267_input.addCol("i_current_price", 4);
    tbl_SerializeFromObject_TD_8809267_input.allocateHost();
    tbl_SerializeFromObject_TD_8809267_input.loadHost();
    Table tbl_SerializeFromObject_TD_9969271_input;
    tbl_SerializeFromObject_TD_9969271_input = Table("inventory", inventory_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_9969271_input.addCol("inv_date_sk", 4);
    tbl_SerializeFromObject_TD_9969271_input.addCol("inv_item_sk", 4);
    tbl_SerializeFromObject_TD_9969271_input.addCol("inv_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_9969271_input.addCol("inv_quantity_on_hand", 4);
    tbl_SerializeFromObject_TD_9969271_input.allocateHost();
    tbl_SerializeFromObject_TD_9969271_input.loadHost();
    Table tbl_SerializeFromObject_TD_9286651_input;
    tbl_SerializeFromObject_TD_9286651_input = Table("warehouse", warehouse_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9286651_input.addCol("w_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_9286651_input.addCol("w_warehouse_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9286651_input.allocateHost();
    tbl_SerializeFromObject_TD_9286651_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    std::cout << std::endl; 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_8_187083_s, tv_r_Filter_8_187083_e;
    gettimeofday(&tv_r_Filter_8_187083_s, 0);
    SW_Filter_TD_8969129(tbl_SerializeFromObject_TD_9286651_input, tbl_Filter_TD_8969129_output);
    gettimeofday(&tv_r_Filter_8_187083_e, 0);

    struct timeval tv_r_Filter_8_181491_s, tv_r_Filter_8_181491_e;
    gettimeofday(&tv_r_Filter_8_181491_s, 0);
    SW_Filter_TD_8562041(tbl_SerializeFromObject_TD_9969271_input, tbl_Filter_TD_8562041_output);
    gettimeofday(&tv_r_Filter_8_181491_e, 0);

    struct timeval tv_r_Filter_7_343225_s, tv_r_Filter_7_343225_e;
    gettimeofday(&tv_r_Filter_7_343225_s, 0);
    SW_Filter_TD_7227204(tbl_SerializeFromObject_TD_8809267_input, tbl_Filter_TD_7227204_output);
    gettimeofday(&tv_r_Filter_7_343225_e, 0);

    struct timeval tv_r_JOIN_INNER_7_261083_s, tv_r_JOIN_INNER_7_261083_e;
    gettimeofday(&tv_r_JOIN_INNER_7_261083_s, 0);
    SW_JOIN_INNER_TD_7304750(tbl_Filter_TD_8562041_output, tbl_Filter_TD_8969129_output, tbl_JOIN_INNER_TD_7304750_output);
    gettimeofday(&tv_r_JOIN_INNER_7_261083_e, 0);

    struct timeval tv_r_Filter_6_449460_s, tv_r_Filter_6_449460_e;
    gettimeofday(&tv_r_Filter_6_449460_s, 0);
    SW_Filter_TD_6896397(tbl_SerializeFromObject_TD_7952618_input, tbl_Filter_TD_6896397_output);
    gettimeofday(&tv_r_Filter_6_449460_e, 0);

    struct timeval tv_r_JOIN_INNER_6_200464_s, tv_r_JOIN_INNER_6_200464_e;
    gettimeofday(&tv_r_JOIN_INNER_6_200464_s, 0);
    SW_JOIN_INNER_TD_6218165(tbl_JOIN_INNER_TD_7304750_output, tbl_Filter_TD_7227204_output, tbl_JOIN_INNER_TD_6218165_output);
    gettimeofday(&tv_r_JOIN_INNER_6_200464_e, 0);

    struct timeval tv_r_JOIN_INNER_5_574904_s, tv_r_JOIN_INNER_5_574904_e;
    gettimeofday(&tv_r_JOIN_INNER_5_574904_s, 0);
    SW_JOIN_INNER_TD_5737030(tbl_JOIN_INNER_TD_6218165_output, tbl_Filter_TD_6896397_output, tbl_JOIN_INNER_TD_5737030_output);
    gettimeofday(&tv_r_JOIN_INNER_5_574904_e, 0);

    struct timeval tv_r_Aggregate_4_438562_s, tv_r_Aggregate_4_438562_e;
    gettimeofday(&tv_r_Aggregate_4_438562_s, 0);
    SW_Aggregate_TD_4230421(tbl_JOIN_INNER_TD_5737030_output, tbl_Aggregate_TD_4230421_output);
    gettimeofday(&tv_r_Aggregate_4_438562_e, 0);

    struct timeval tv_r_Filter_3_14783_s, tv_r_Filter_3_14783_e;
    gettimeofday(&tv_r_Filter_3_14783_s, 0);
    SW_Filter_TD_3950469(tbl_Aggregate_TD_4230421_output, tbl_Filter_TD_3950469_output);
    gettimeofday(&tv_r_Filter_3_14783_e, 0);

    struct timeval tv_r_Sort_2_122160_s, tv_r_Sort_2_122160_e;
    gettimeofday(&tv_r_Sort_2_122160_s, 0);
    SW_Sort_TD_264578(tbl_Filter_TD_3950469_output, tbl_Sort_TD_264578_output);
    gettimeofday(&tv_r_Sort_2_122160_e, 0);

    struct timeval tv_r_LocalLimit_1_683969_s, tv_r_LocalLimit_1_683969_e;
    gettimeofday(&tv_r_LocalLimit_1_683969_s, 0);
    SW_LocalLimit_TD_1953724(tbl_Sort_TD_264578_output, tbl_LocalLimit_TD_1953724_output);
    gettimeofday(&tv_r_LocalLimit_1_683969_e, 0);

    struct timeval tv_r_GlobalLimit_0_306463_s, tv_r_GlobalLimit_0_306463_e;
    gettimeofday(&tv_r_GlobalLimit_0_306463_s, 0);
    SW_GlobalLimit_TD_0564374(tbl_LocalLimit_TD_1953724_output, tbl_GlobalLimit_TD_0564374_output);
    gettimeofday(&tv_r_GlobalLimit_0_306463_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_187083_s, &tv_r_Filter_8_187083_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9286651_input: " << tbl_SerializeFromObject_TD_9286651_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_181491_s, &tv_r_Filter_8_181491_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9969271_input: " << tbl_SerializeFromObject_TD_9969271_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_343225_s, &tv_r_Filter_7_343225_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8809267_input: " << tbl_SerializeFromObject_TD_8809267_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_261083_s, &tv_r_JOIN_INNER_7_261083_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8562041_output: " << tbl_Filter_TD_8562041_output.getNumRow() << " " << "tbl_Filter_TD_8969129_output: " << tbl_Filter_TD_8969129_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_449460_s, &tv_r_Filter_6_449460_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7952618_input: " << tbl_SerializeFromObject_TD_7952618_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_200464_s, &tv_r_JOIN_INNER_6_200464_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7304750_output: " << tbl_JOIN_INNER_TD_7304750_output.getNumRow() << " " << "tbl_Filter_TD_7227204_output: " << tbl_Filter_TD_7227204_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_574904_s, &tv_r_JOIN_INNER_5_574904_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6218165_output: " << tbl_JOIN_INNER_TD_6218165_output.getNumRow() << " " << "tbl_Filter_TD_6896397_output: " << tbl_Filter_TD_6896397_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_4: " << tvdiff(&tv_r_Aggregate_4_438562_s, &tv_r_Aggregate_4_438562_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5737030_output: " << tbl_JOIN_INNER_TD_5737030_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_14783_s, &tv_r_Filter_3_14783_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_4230421_output: " << tbl_Aggregate_TD_4230421_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_122160_s, &tv_r_Sort_2_122160_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_3950469_output: " << tbl_Filter_TD_3950469_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_683969_s, &tv_r_LocalLimit_1_683969_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_264578_output: " << tbl_Sort_TD_264578_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_306463_s, &tv_r_GlobalLimit_0_306463_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1953724_output: " << tbl_LocalLimit_TD_1953724_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.9071237 * 1000 << "ms" << std::endl; 
    return 0; 
}
