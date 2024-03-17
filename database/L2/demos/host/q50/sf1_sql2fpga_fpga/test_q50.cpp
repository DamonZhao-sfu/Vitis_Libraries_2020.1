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

#include "cfgFunc_q50.hpp" 
#include "q50.hpp" 

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
    std::cout << "NOTE:running query #50\n."; 
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
    Table tbl_GlobalLimit_TD_0856848_output("tbl_GlobalLimit_TD_0856848_output", 6100000, 15, "");
    tbl_GlobalLimit_TD_0856848_output.allocateHost();
    Table tbl_LocalLimit_TD_1902271_output("tbl_LocalLimit_TD_1902271_output", 6100000, 15, "");
    tbl_LocalLimit_TD_1902271_output.allocateHost();
    Table tbl_Sort_TD_2559866_output("tbl_Sort_TD_2559866_output", 6100000, 15, "");
    tbl_Sort_TD_2559866_output.allocateHost();
    Table tbl_Aggregate_TD_3396839_output("tbl_Aggregate_TD_3396839_output", 6100000, 15, "");
    tbl_Aggregate_TD_3396839_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4422236_output("tbl_JOIN_INNER_TD_4422236_output", 6100000, 12, "");
    tbl_JOIN_INNER_TD_4422236_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5558590_output("tbl_JOIN_INNER_TD_5558590_output", 6100000, 12, "");
    tbl_JOIN_INNER_TD_5558590_output.allocateHost();
    Table tbl_Filter_TD_5961219_output("tbl_Filter_TD_5961219_output", 6100000, 1, "");
    tbl_Filter_TD_5961219_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6935557_output("tbl_JOIN_INNER_TD_6935557_output", 6100000, 12, "");
    tbl_JOIN_INNER_TD_6935557_output.allocateHost();
    Table tbl_Filter_TD_6167012_output("tbl_Filter_TD_6167012_output", 6100000, 1, "");
    tbl_Filter_TD_6167012_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6633768_input;
    tbl_SerializeFromObject_TD_6633768_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_6633768_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_6633768_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_6633768_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_6633768_input.allocateHost();
    tbl_SerializeFromObject_TD_6633768_input.loadHost();
    Table tbl_JOIN_INNER_TD_7222960_output("tbl_JOIN_INNER_TD_7222960_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_7222960_output.allocateHost();
    Table tbl_Filter_TD_7731477_output("tbl_Filter_TD_7731477_output", 6100000, 11, "");
    tbl_Filter_TD_7731477_output.allocateHost();
    Table tbl_SerializeFromObject_TD_716473_input;
    tbl_SerializeFromObject_TD_716473_input = Table("date_dim", date_dim_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_716473_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_716473_input.allocateHost();
    tbl_SerializeFromObject_TD_716473_input.loadHost();
    Table tbl_Filter_TD_8778206_output("tbl_Filter_TD_8778206_output", 6100000, 5, "");
    tbl_Filter_TD_8778206_output.allocateHost();
    Table tbl_Filter_TD_8273266_output("tbl_Filter_TD_8273266_output", 6100000, 4, "");
    tbl_Filter_TD_8273266_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8830283_input;
    tbl_SerializeFromObject_TD_8830283_input = Table("store", store_n, 11, in_dir, "orc");
    tbl_SerializeFromObject_TD_8830283_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_8830283_input.addCol("s_store_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8830283_input.addCol("s_company_id", 4);
    tbl_SerializeFromObject_TD_8830283_input.addCol("s_street_number", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8830283_input.addCol("s_street_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8830283_input.addCol("s_street_type", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8830283_input.addCol("s_suite_number", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8830283_input.addCol("s_city", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8830283_input.addCol("s_county", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8830283_input.addCol("s_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8830283_input.addCol("s_zip", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8830283_input.allocateHost();
    tbl_SerializeFromObject_TD_8830283_input.loadHost();
    Table tbl_SerializeFromObject_TD_9888251_input;
    tbl_SerializeFromObject_TD_9888251_input = Table("store_sales", store_sales_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_9888251_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_9888251_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_9888251_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_9888251_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_9888251_input.addCol("ss_ticket_number", 8);
    tbl_SerializeFromObject_TD_9888251_input.allocateHost();
    tbl_SerializeFromObject_TD_9888251_input.loadHost();
    Table tbl_SerializeFromObject_TD_9189504_input;
    tbl_SerializeFromObject_TD_9189504_input = Table("store_returns", store_returns_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_9189504_input.addCol("sr_returned_date_sk", 4);
    tbl_SerializeFromObject_TD_9189504_input.addCol("sr_item_sk", 4);
    tbl_SerializeFromObject_TD_9189504_input.addCol("sr_customer_sk", 4);
    tbl_SerializeFromObject_TD_9189504_input.addCol("sr_ticket_number", 8);
    tbl_SerializeFromObject_TD_9189504_input.allocateHost();
    tbl_SerializeFromObject_TD_9189504_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    std::cout << std::endl; 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_8_495374_s, tv_r_Filter_8_495374_e;
    gettimeofday(&tv_r_Filter_8_495374_s, 0);
    SW_Filter_TD_8273266(tbl_SerializeFromObject_TD_9189504_input, tbl_Filter_TD_8273266_output);
    gettimeofday(&tv_r_Filter_8_495374_e, 0);

    struct timeval tv_r_Filter_8_580053_s, tv_r_Filter_8_580053_e;
    gettimeofday(&tv_r_Filter_8_580053_s, 0);
    SW_Filter_TD_8778206(tbl_SerializeFromObject_TD_9888251_input, tbl_Filter_TD_8778206_output);
    gettimeofday(&tv_r_Filter_8_580053_e, 0);

    struct timeval tv_r_Filter_7_191518_s, tv_r_Filter_7_191518_e;
    gettimeofday(&tv_r_Filter_7_191518_s, 0);
    SW_Filter_TD_7731477(tbl_SerializeFromObject_TD_8830283_input, tbl_Filter_TD_7731477_output);
    gettimeofday(&tv_r_Filter_7_191518_e, 0);

    struct timeval tv_r_JOIN_INNER_7_292529_s, tv_r_JOIN_INNER_7_292529_e;
    gettimeofday(&tv_r_JOIN_INNER_7_292529_s, 0);
    SW_JOIN_INNER_TD_7222960(tbl_Filter_TD_8778206_output, tbl_Filter_TD_8273266_output, tbl_JOIN_INNER_TD_7222960_output);
    gettimeofday(&tv_r_JOIN_INNER_7_292529_e, 0);

    struct timeval tv_r_Filter_6_116166_s, tv_r_Filter_6_116166_e;
    gettimeofday(&tv_r_Filter_6_116166_s, 0);
    SW_Filter_TD_6167012(tbl_SerializeFromObject_TD_716473_input, tbl_Filter_TD_6167012_output);
    gettimeofday(&tv_r_Filter_6_116166_e, 0);

    struct timeval tv_r_JOIN_INNER_6_178254_s, tv_r_JOIN_INNER_6_178254_e;
    gettimeofday(&tv_r_JOIN_INNER_6_178254_s, 0);
    SW_JOIN_INNER_TD_6935557(tbl_JOIN_INNER_TD_7222960_output, tbl_Filter_TD_7731477_output, tbl_JOIN_INNER_TD_6935557_output);
    gettimeofday(&tv_r_JOIN_INNER_6_178254_e, 0);

    struct timeval tv_r_Filter_5_6091_s, tv_r_Filter_5_6091_e;
    gettimeofday(&tv_r_Filter_5_6091_s, 0);
    SW_Filter_TD_5961219(tbl_SerializeFromObject_TD_6633768_input, tbl_Filter_TD_5961219_output);
    gettimeofday(&tv_r_Filter_5_6091_e, 0);

    struct timeval tv_r_JOIN_INNER_5_800474_s, tv_r_JOIN_INNER_5_800474_e;
    gettimeofday(&tv_r_JOIN_INNER_5_800474_s, 0);
    SW_JOIN_INNER_TD_5558590(tbl_JOIN_INNER_TD_6935557_output, tbl_Filter_TD_6167012_output, tbl_JOIN_INNER_TD_5558590_output);
    gettimeofday(&tv_r_JOIN_INNER_5_800474_e, 0);

    struct timeval tv_r_JOIN_INNER_4_35175_s, tv_r_JOIN_INNER_4_35175_e;
    gettimeofday(&tv_r_JOIN_INNER_4_35175_s, 0);
    SW_JOIN_INNER_TD_4422236(tbl_JOIN_INNER_TD_5558590_output, tbl_Filter_TD_5961219_output, tbl_JOIN_INNER_TD_4422236_output);
    gettimeofday(&tv_r_JOIN_INNER_4_35175_e, 0);

    struct timeval tv_r_Aggregate_3_788186_s, tv_r_Aggregate_3_788186_e;
    gettimeofday(&tv_r_Aggregate_3_788186_s, 0);
    SW_Aggregate_TD_3396839(tbl_JOIN_INNER_TD_4422236_output, tbl_Aggregate_TD_3396839_output);
    gettimeofday(&tv_r_Aggregate_3_788186_e, 0);

    struct timeval tv_r_Sort_2_647110_s, tv_r_Sort_2_647110_e;
    gettimeofday(&tv_r_Sort_2_647110_s, 0);
    SW_Sort_TD_2559866(tbl_Aggregate_TD_3396839_output, tbl_Sort_TD_2559866_output);
    gettimeofday(&tv_r_Sort_2_647110_e, 0);

    struct timeval tv_r_LocalLimit_1_112192_s, tv_r_LocalLimit_1_112192_e;
    gettimeofday(&tv_r_LocalLimit_1_112192_s, 0);
    SW_LocalLimit_TD_1902271(tbl_Sort_TD_2559866_output, tbl_LocalLimit_TD_1902271_output);
    gettimeofday(&tv_r_LocalLimit_1_112192_e, 0);

    struct timeval tv_r_GlobalLimit_0_771477_s, tv_r_GlobalLimit_0_771477_e;
    gettimeofday(&tv_r_GlobalLimit_0_771477_s, 0);
    SW_GlobalLimit_TD_0856848(tbl_LocalLimit_TD_1902271_output, tbl_GlobalLimit_TD_0856848_output);
    gettimeofday(&tv_r_GlobalLimit_0_771477_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_495374_s, &tv_r_Filter_8_495374_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9189504_input: " << tbl_SerializeFromObject_TD_9189504_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_580053_s, &tv_r_Filter_8_580053_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9888251_input: " << tbl_SerializeFromObject_TD_9888251_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_191518_s, &tv_r_Filter_7_191518_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8830283_input: " << tbl_SerializeFromObject_TD_8830283_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_292529_s, &tv_r_JOIN_INNER_7_292529_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8778206_output: " << tbl_Filter_TD_8778206_output.getNumRow() << " " << "tbl_Filter_TD_8273266_output: " << tbl_Filter_TD_8273266_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_116166_s, &tv_r_Filter_6_116166_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_716473_input: " << tbl_SerializeFromObject_TD_716473_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_178254_s, &tv_r_JOIN_INNER_6_178254_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7222960_output: " << tbl_JOIN_INNER_TD_7222960_output.getNumRow() << " " << "tbl_Filter_TD_7731477_output: " << tbl_Filter_TD_7731477_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_6091_s, &tv_r_Filter_5_6091_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6633768_input: " << tbl_SerializeFromObject_TD_6633768_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_800474_s, &tv_r_JOIN_INNER_5_800474_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6935557_output: " << tbl_JOIN_INNER_TD_6935557_output.getNumRow() << " " << "tbl_Filter_TD_6167012_output: " << tbl_Filter_TD_6167012_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_35175_s, &tv_r_JOIN_INNER_4_35175_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5558590_output: " << tbl_JOIN_INNER_TD_5558590_output.getNumRow() << " " << "tbl_Filter_TD_5961219_output: " << tbl_Filter_TD_5961219_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_788186_s, &tv_r_Aggregate_3_788186_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4422236_output: " << tbl_JOIN_INNER_TD_4422236_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_647110_s, &tv_r_Sort_2_647110_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3396839_output: " << tbl_Aggregate_TD_3396839_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_112192_s, &tv_r_LocalLimit_1_112192_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2559866_output: " << tbl_Sort_TD_2559866_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_771477_s, &tv_r_GlobalLimit_0_771477_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1902271_output: " << tbl_LocalLimit_TD_1902271_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.327417 * 1000 << "ms" << std::endl; 
    return 0; 
}
