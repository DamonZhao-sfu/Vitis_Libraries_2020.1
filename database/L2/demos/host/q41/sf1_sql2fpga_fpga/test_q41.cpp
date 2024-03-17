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

#include "cfgFunc_q41.hpp" 
#include "q41.hpp" 

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
    std::cout << "NOTE:running query #41\n."; 
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
    Table tbl_GlobalLimit_TD_0845238_output("tbl_GlobalLimit_TD_0845238_output", 6100000, 1, "");
    tbl_GlobalLimit_TD_0845238_output.allocateHost();
    Table tbl_LocalLimit_TD_1722381_output("tbl_LocalLimit_TD_1722381_output", 6100000, 1, "");
    tbl_LocalLimit_TD_1722381_output.allocateHost();
    Table tbl_Sort_TD_2224667_output("tbl_Sort_TD_2224667_output", 6100000, 1, "");
    tbl_Sort_TD_2224667_output.allocateHost();
    Table tbl_Aggregate_TD_344476_output("tbl_Aggregate_TD_344476_output", 6100000, 1, "");
    tbl_Aggregate_TD_344476_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4927887_output("tbl_JOIN_INNER_TD_4927887_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_4927887_output.allocateHost();
    Table tbl_Filter_TD_5361033_output("tbl_Filter_TD_5361033_output", 6100000, 2, "");
    tbl_Filter_TD_5361033_output.allocateHost();
    Table tbl_Filter_TD_5935086_output("tbl_Filter_TD_5935086_output", 6100000, 1, "");
    tbl_Filter_TD_5935086_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6141526_input;
    tbl_SerializeFromObject_TD_6141526_input = Table("item", item_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_6141526_input.addCol("i_manufact", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6141526_input.addCol("i_product_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6141526_input.addCol("i_manufact_id", 4);
    tbl_SerializeFromObject_TD_6141526_input.allocateHost();
    tbl_SerializeFromObject_TD_6141526_input.loadHost();
    Table tbl_Aggregate_TD_6957621_output("tbl_Aggregate_TD_6957621_output", 6100000, 2, "");
    tbl_Aggregate_TD_6957621_output.allocateHost();
    Table tbl_Filter_TD_7990412_output("tbl_Filter_TD_7990412_output", 6100000, 1, "");
    tbl_Filter_TD_7990412_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8140664_input;
    tbl_SerializeFromObject_TD_8140664_input = Table("item", item_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_8140664_input.addCol("i_manufact", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8140664_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8140664_input.addCol("i_color", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8140664_input.addCol("i_units", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8140664_input.addCol("i_size", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8140664_input.allocateHost();
    tbl_SerializeFromObject_TD_8140664_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    std::cout << std::endl; 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_7_60731_s, tv_r_Filter_7_60731_e;
    gettimeofday(&tv_r_Filter_7_60731_s, 0);
    SW_Filter_TD_7990412(tbl_SerializeFromObject_TD_8140664_input, tbl_Filter_TD_7990412_output);
    gettimeofday(&tv_r_Filter_7_60731_e, 0);

    struct timeval tv_r_Aggregate_6_544111_s, tv_r_Aggregate_6_544111_e;
    gettimeofday(&tv_r_Aggregate_6_544111_s, 0);
    SW_Aggregate_TD_6957621(tbl_Filter_TD_7990412_output, tbl_Aggregate_TD_6957621_output);
    gettimeofday(&tv_r_Aggregate_6_544111_e, 0);

    struct timeval tv_r_Filter_5_940332_s, tv_r_Filter_5_940332_e;
    gettimeofday(&tv_r_Filter_5_940332_s, 0);
    SW_Filter_TD_5935086(tbl_Aggregate_TD_6957621_output, tbl_Filter_TD_5935086_output);
    gettimeofday(&tv_r_Filter_5_940332_e, 0);

    struct timeval tv_r_Filter_5_784030_s, tv_r_Filter_5_784030_e;
    gettimeofday(&tv_r_Filter_5_784030_s, 0);
    SW_Filter_TD_5361033(tbl_SerializeFromObject_TD_6141526_input, tbl_Filter_TD_5361033_output);
    gettimeofday(&tv_r_Filter_5_784030_e, 0);

    struct timeval tv_r_JOIN_INNER_4_780170_s, tv_r_JOIN_INNER_4_780170_e;
    gettimeofday(&tv_r_JOIN_INNER_4_780170_s, 0);
    SW_JOIN_INNER_TD_4927887(tbl_Filter_TD_5361033_output, tbl_Filter_TD_5935086_output, tbl_JOIN_INNER_TD_4927887_output);
    gettimeofday(&tv_r_JOIN_INNER_4_780170_e, 0);

    struct timeval tv_r_Aggregate_3_536192_s, tv_r_Aggregate_3_536192_e;
    gettimeofday(&tv_r_Aggregate_3_536192_s, 0);
    SW_Aggregate_TD_344476(tbl_JOIN_INNER_TD_4927887_output, tbl_Aggregate_TD_344476_output);
    gettimeofday(&tv_r_Aggregate_3_536192_e, 0);

    struct timeval tv_r_Sort_2_461624_s, tv_r_Sort_2_461624_e;
    gettimeofday(&tv_r_Sort_2_461624_s, 0);
    SW_Sort_TD_2224667(tbl_Aggregate_TD_344476_output, tbl_Sort_TD_2224667_output);
    gettimeofday(&tv_r_Sort_2_461624_e, 0);

    struct timeval tv_r_LocalLimit_1_534785_s, tv_r_LocalLimit_1_534785_e;
    gettimeofday(&tv_r_LocalLimit_1_534785_s, 0);
    SW_LocalLimit_TD_1722381(tbl_Sort_TD_2224667_output, tbl_LocalLimit_TD_1722381_output);
    gettimeofday(&tv_r_LocalLimit_1_534785_e, 0);

    struct timeval tv_r_GlobalLimit_0_251094_s, tv_r_GlobalLimit_0_251094_e;
    gettimeofday(&tv_r_GlobalLimit_0_251094_s, 0);
    SW_GlobalLimit_TD_0845238(tbl_LocalLimit_TD_1722381_output, tbl_GlobalLimit_TD_0845238_output);
    gettimeofday(&tv_r_GlobalLimit_0_251094_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_60731_s, &tv_r_Filter_7_60731_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8140664_input: " << tbl_SerializeFromObject_TD_8140664_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_6: " << tvdiff(&tv_r_Aggregate_6_544111_s, &tv_r_Aggregate_6_544111_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_7990412_output: " << tbl_Filter_TD_7990412_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_940332_s, &tv_r_Filter_5_940332_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_6957621_output: " << tbl_Aggregate_TD_6957621_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_784030_s, &tv_r_Filter_5_784030_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6141526_input: " << tbl_SerializeFromObject_TD_6141526_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_780170_s, &tv_r_JOIN_INNER_4_780170_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_5361033_output: " << tbl_Filter_TD_5361033_output.getNumRow() << " " << "tbl_Filter_TD_5935086_output: " << tbl_Filter_TD_5935086_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_536192_s, &tv_r_Aggregate_3_536192_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4927887_output: " << tbl_JOIN_INNER_TD_4927887_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_461624_s, &tv_r_Sort_2_461624_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_344476_output: " << tbl_Aggregate_TD_344476_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_534785_s, &tv_r_LocalLimit_1_534785_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2224667_output: " << tbl_Sort_TD_2224667_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_251094_s, &tv_r_GlobalLimit_0_251094_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1722381_output: " << tbl_LocalLimit_TD_1722381_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 0.8422776 * 1000 << "ms" << std::endl; 
    return 0; 
}
