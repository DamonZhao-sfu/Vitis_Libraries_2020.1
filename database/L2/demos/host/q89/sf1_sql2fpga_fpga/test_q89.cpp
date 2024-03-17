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

#include "cfgFunc_q89.hpp" 
#include "q89.hpp" 

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
    std::cout << "NOTE:running query #89\n."; 
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
    Table tbl_GlobalLimit_TD_0786241_output("tbl_GlobalLimit_TD_0786241_output", 6100000, 8, "");
    tbl_GlobalLimit_TD_0786241_output.allocateHost();
    Table tbl_LocalLimit_TD_1566628_output("tbl_LocalLimit_TD_1566628_output", 6100000, 8, "");
    tbl_LocalLimit_TD_1566628_output.allocateHost();
    Table tbl_Sort_TD_2310981_output("tbl_Sort_TD_2310981_output", 6100000, 8, "");
    tbl_Sort_TD_2310981_output.allocateHost();
    Table tbl_Filter_TD_3580027_output("tbl_Filter_TD_3580027_output", 6100000, 8, "");
    tbl_Filter_TD_3580027_output.allocateHost();
    Table tbl_Window_TD_4399809_output("tbl_Window_TD_4399809_output", 6100000, 9, "");
    tbl_Window_TD_4399809_output.allocateHost();
    Table tbl_Aggregate_TD_5876975_output("tbl_Aggregate_TD_5876975_output", 6100000, 8, "");
    tbl_Aggregate_TD_5876975_output.allocateHost();
    Table tbl_JOIN_INNER_TD_698343_output("tbl_JOIN_INNER_TD_698343_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_698343_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7920663_output("tbl_JOIN_INNER_TD_7920663_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_7920663_output.allocateHost();
    Table tbl_Filter_TD_7604217_output("tbl_Filter_TD_7604217_output", 6100000, 3, "");
    tbl_Filter_TD_7604217_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8613451_output("tbl_JOIN_INNER_TD_8613451_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_8613451_output.allocateHost();
    Table tbl_Filter_TD_8724584_output("tbl_Filter_TD_8724584_output", 6100000, 2, "");
    tbl_Filter_TD_8724584_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8797397_input;
    tbl_SerializeFromObject_TD_8797397_input = Table("store", store_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8797397_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_8797397_input.addCol("s_store_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8797397_input.addCol("s_company_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8797397_input.allocateHost();
    tbl_SerializeFromObject_TD_8797397_input.loadHost();
    Table tbl_Filter_TD_9757821_output("tbl_Filter_TD_9757821_output", 6100000, 4, "");
    tbl_Filter_TD_9757821_output.allocateHost();
    Table tbl_Filter_TD_9220831_output("tbl_Filter_TD_9220831_output", 6100000, 4, "");
    tbl_Filter_TD_9220831_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9244436_input;
    tbl_SerializeFromObject_TD_9244436_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9244436_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_9244436_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_9244436_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_9244436_input.allocateHost();
    tbl_SerializeFromObject_TD_9244436_input.loadHost();
    Table tbl_SerializeFromObject_TD_10113743_input;
    tbl_SerializeFromObject_TD_10113743_input = Table("item", item_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_10113743_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_10113743_input.addCol("i_brand", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10113743_input.addCol("i_class", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10113743_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10113743_input.allocateHost();
    tbl_SerializeFromObject_TD_10113743_input.loadHost();
    Table tbl_SerializeFromObject_TD_10847610_input;
    tbl_SerializeFromObject_TD_10847610_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_10847610_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10847610_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_10847610_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_10847610_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_10847610_input.allocateHost();
    tbl_SerializeFromObject_TD_10847610_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    std::cout << std::endl; 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_9_203801_s, tv_r_Filter_9_203801_e;
    gettimeofday(&tv_r_Filter_9_203801_s, 0);
    SW_Filter_TD_9220831(tbl_SerializeFromObject_TD_10847610_input, tbl_Filter_TD_9220831_output);
    gettimeofday(&tv_r_Filter_9_203801_e, 0);

    struct timeval tv_r_Filter_9_738666_s, tv_r_Filter_9_738666_e;
    gettimeofday(&tv_r_Filter_9_738666_s, 0);
    SW_Filter_TD_9757821(tbl_SerializeFromObject_TD_10113743_input, tbl_Filter_TD_9757821_output);
    gettimeofday(&tv_r_Filter_9_738666_e, 0);

    struct timeval tv_r_Filter_8_474782_s, tv_r_Filter_8_474782_e;
    gettimeofday(&tv_r_Filter_8_474782_s, 0);
    SW_Filter_TD_8724584(tbl_SerializeFromObject_TD_9244436_input, tbl_Filter_TD_8724584_output);
    gettimeofday(&tv_r_Filter_8_474782_e, 0);

    struct timeval tv_r_JOIN_INNER_8_500359_s, tv_r_JOIN_INNER_8_500359_e;
    gettimeofday(&tv_r_JOIN_INNER_8_500359_s, 0);
    SW_JOIN_INNER_TD_8613451(tbl_Filter_TD_9757821_output, tbl_Filter_TD_9220831_output, tbl_JOIN_INNER_TD_8613451_output);
    gettimeofday(&tv_r_JOIN_INNER_8_500359_e, 0);

    struct timeval tv_r_Filter_7_169270_s, tv_r_Filter_7_169270_e;
    gettimeofday(&tv_r_Filter_7_169270_s, 0);
    SW_Filter_TD_7604217(tbl_SerializeFromObject_TD_8797397_input, tbl_Filter_TD_7604217_output);
    gettimeofday(&tv_r_Filter_7_169270_e, 0);

    struct timeval tv_r_JOIN_INNER_7_447567_s, tv_r_JOIN_INNER_7_447567_e;
    gettimeofday(&tv_r_JOIN_INNER_7_447567_s, 0);
    SW_JOIN_INNER_TD_7920663(tbl_JOIN_INNER_TD_8613451_output, tbl_Filter_TD_8724584_output, tbl_JOIN_INNER_TD_7920663_output);
    gettimeofday(&tv_r_JOIN_INNER_7_447567_e, 0);

    struct timeval tv_r_JOIN_INNER_6_834142_s, tv_r_JOIN_INNER_6_834142_e;
    gettimeofday(&tv_r_JOIN_INNER_6_834142_s, 0);
    SW_JOIN_INNER_TD_698343(tbl_JOIN_INNER_TD_7920663_output, tbl_Filter_TD_7604217_output, tbl_JOIN_INNER_TD_698343_output);
    gettimeofday(&tv_r_JOIN_INNER_6_834142_e, 0);

    struct timeval tv_r_Aggregate_5_858261_s, tv_r_Aggregate_5_858261_e;
    gettimeofday(&tv_r_Aggregate_5_858261_s, 0);
    SW_Aggregate_TD_5876975(tbl_JOIN_INNER_TD_698343_output, tbl_Aggregate_TD_5876975_output);
    gettimeofday(&tv_r_Aggregate_5_858261_e, 0);

    struct timeval tv_r_Window_4_10320_s, tv_r_Window_4_10320_e;
    gettimeofday(&tv_r_Window_4_10320_s, 0);
    SW_Window_TD_4399809(tbl_Aggregate_TD_5876975_output, tbl_Window_TD_4399809_output);
    gettimeofday(&tv_r_Window_4_10320_e, 0);

    struct timeval tv_r_Filter_3_973332_s, tv_r_Filter_3_973332_e;
    gettimeofday(&tv_r_Filter_3_973332_s, 0);
    SW_Filter_TD_3580027(tbl_Window_TD_4399809_output, tbl_Filter_TD_3580027_output);
    gettimeofday(&tv_r_Filter_3_973332_e, 0);

    struct timeval tv_r_Sort_2_120032_s, tv_r_Sort_2_120032_e;
    gettimeofday(&tv_r_Sort_2_120032_s, 0);
    SW_Sort_TD_2310981(tbl_Filter_TD_3580027_output, tbl_Sort_TD_2310981_output);
    gettimeofday(&tv_r_Sort_2_120032_e, 0);

    struct timeval tv_r_LocalLimit_1_26602_s, tv_r_LocalLimit_1_26602_e;
    gettimeofday(&tv_r_LocalLimit_1_26602_s, 0);
    SW_LocalLimit_TD_1566628(tbl_Sort_TD_2310981_output, tbl_LocalLimit_TD_1566628_output);
    gettimeofday(&tv_r_LocalLimit_1_26602_e, 0);

    struct timeval tv_r_GlobalLimit_0_298082_s, tv_r_GlobalLimit_0_298082_e;
    gettimeofday(&tv_r_GlobalLimit_0_298082_s, 0);
    SW_GlobalLimit_TD_0786241(tbl_LocalLimit_TD_1566628_output, tbl_GlobalLimit_TD_0786241_output);
    gettimeofday(&tv_r_GlobalLimit_0_298082_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_203801_s, &tv_r_Filter_9_203801_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10847610_input: " << tbl_SerializeFromObject_TD_10847610_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_738666_s, &tv_r_Filter_9_738666_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10113743_input: " << tbl_SerializeFromObject_TD_10113743_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_474782_s, &tv_r_Filter_8_474782_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9244436_input: " << tbl_SerializeFromObject_TD_9244436_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_500359_s, &tv_r_JOIN_INNER_8_500359_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9757821_output: " << tbl_Filter_TD_9757821_output.getNumRow() << " " << "tbl_Filter_TD_9220831_output: " << tbl_Filter_TD_9220831_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_169270_s, &tv_r_Filter_7_169270_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8797397_input: " << tbl_SerializeFromObject_TD_8797397_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_447567_s, &tv_r_JOIN_INNER_7_447567_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8613451_output: " << tbl_JOIN_INNER_TD_8613451_output.getNumRow() << " " << "tbl_Filter_TD_8724584_output: " << tbl_Filter_TD_8724584_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_834142_s, &tv_r_JOIN_INNER_6_834142_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7920663_output: " << tbl_JOIN_INNER_TD_7920663_output.getNumRow() << " " << "tbl_Filter_TD_7604217_output: " << tbl_Filter_TD_7604217_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_858261_s, &tv_r_Aggregate_5_858261_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_698343_output: " << tbl_JOIN_INNER_TD_698343_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_4: " << tvdiff(&tv_r_Window_4_10320_s, &tv_r_Window_4_10320_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_5876975_output: " << tbl_Aggregate_TD_5876975_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_973332_s, &tv_r_Filter_3_973332_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_4399809_output: " << tbl_Window_TD_4399809_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_120032_s, &tv_r_Sort_2_120032_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_3580027_output: " << tbl_Filter_TD_3580027_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_26602_s, &tv_r_LocalLimit_1_26602_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2310981_output: " << tbl_Sort_TD_2310981_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_298082_s, &tv_r_GlobalLimit_0_298082_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1566628_output: " << tbl_LocalLimit_TD_1566628_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.7073483 * 1000 << "ms" << std::endl; 
    return 0; 
}
