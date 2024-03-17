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

#include "cfgFunc_q59.hpp" 
#include "q59.hpp" 

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
    std::cout << "NOTE:running query #59\n."; 
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
    Table tbl_GlobalLimit_TD_0244891_output("tbl_GlobalLimit_TD_0244891_output", 6100000, 10, "");
    tbl_GlobalLimit_TD_0244891_output.allocateHost();
    Table tbl_LocalLimit_TD_1688090_output("tbl_LocalLimit_TD_1688090_output", 6100000, 10, "");
    tbl_LocalLimit_TD_1688090_output.allocateHost();
    Table tbl_Sort_TD_2763988_output("tbl_Sort_TD_2763988_output", 6100000, 10, "");
    tbl_Sort_TD_2763988_output.allocateHost();
    Table tbl_Project_TD_332022_output("tbl_Project_TD_332022_output", 6100000, 10, "");
    tbl_Project_TD_332022_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4905171_output("tbl_JOIN_INNER_TD_4905171_output", 6100000, 17, "");
    tbl_JOIN_INNER_TD_4905171_output.allocateHost();
    Table tbl_Project_TD_5585874_output("tbl_Project_TD_5585874_output", 6100000, 10, "");
    tbl_Project_TD_5585874_output.allocateHost();
    Table tbl_Project_TD_5292855_output("tbl_Project_TD_5292855_output", 6100000, 9, "");
    tbl_Project_TD_5292855_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6265659_output("tbl_JOIN_INNER_TD_6265659_output", 6100000, 10, "");
    tbl_JOIN_INNER_TD_6265659_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6607199_output("tbl_JOIN_INNER_TD_6607199_output", 6100000, 9, "");
    tbl_JOIN_INNER_TD_6607199_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7115974_output("tbl_JOIN_INNER_TD_7115974_output", 6100000, 10, "");
    tbl_JOIN_INNER_TD_7115974_output.allocateHost();
    Table tbl_Filter_TD_7387081_output("tbl_Filter_TD_7387081_output", 6100000, 1, "");
    tbl_Filter_TD_7387081_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7720700_output("tbl_JOIN_INNER_TD_7720700_output", 6100000, 9, "");
    tbl_JOIN_INNER_TD_7720700_output.allocateHost();
    Table tbl_Filter_TD_7520649_output("tbl_Filter_TD_7520649_output", 6100000, 1, "");
    tbl_Filter_TD_7520649_output.allocateHost();
    Table tbl_Aggregate_TD_8112002_output("tbl_Aggregate_TD_8112002_output", 6100000, 9, "");
    tbl_Aggregate_TD_8112002_output.allocateHost();
    Table tbl_Filter_TD_8590989_output("tbl_Filter_TD_8590989_output", 6100000, 3, "");
    tbl_Filter_TD_8590989_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8659135_input;
    tbl_SerializeFromObject_TD_8659135_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8659135_input.addCol("d_week_seq", 4);
    tbl_SerializeFromObject_TD_8659135_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_8659135_input.allocateHost();
    tbl_SerializeFromObject_TD_8659135_input.loadHost();
    Table tbl_Aggregate_TD_8390994_output("tbl_Aggregate_TD_8390994_output", 6100000, 9, "");
    tbl_Aggregate_TD_8390994_output.allocateHost();
    Table tbl_Filter_TD_8578775_output("tbl_Filter_TD_8578775_output", 6100000, 2, "");
    tbl_Filter_TD_8578775_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8719221_input;
    tbl_SerializeFromObject_TD_8719221_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8719221_input.addCol("d_week_seq", 4);
    tbl_SerializeFromObject_TD_8719221_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_8719221_input.allocateHost();
    tbl_SerializeFromObject_TD_8719221_input.loadHost();
    Table tbl_JOIN_INNER_TD_9606643_output("tbl_JOIN_INNER_TD_9606643_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_9606643_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9428042_input;
    tbl_SerializeFromObject_TD_9428042_input = Table("store", store_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9428042_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_9428042_input.addCol("s_store_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9428042_input.addCol("s_store_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9428042_input.allocateHost();
    tbl_SerializeFromObject_TD_9428042_input.loadHost();
    Table tbl_JOIN_INNER_TD_9206684_output("tbl_JOIN_INNER_TD_9206684_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_9206684_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9492681_input;
    tbl_SerializeFromObject_TD_9492681_input = Table("store", store_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9492681_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_9492681_input.addCol("s_store_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9492681_input.allocateHost();
    tbl_SerializeFromObject_TD_9492681_input.loadHost();
    Table tbl_Filter_TD_10797846_output("tbl_Filter_TD_10797846_output", 6100000, 3, "");
    tbl_Filter_TD_10797846_output.allocateHost();
    Table tbl_Filter_TD_10280259_output("tbl_Filter_TD_10280259_output", 6100000, 3, "");
    tbl_Filter_TD_10280259_output.allocateHost();
    Table tbl_Filter_TD_1026918_output("tbl_Filter_TD_1026918_output", 6100000, 3, "");
    tbl_Filter_TD_1026918_output.allocateHost();
    Table tbl_Filter_TD_10557753_output("tbl_Filter_TD_10557753_output", 6100000, 3, "");
    tbl_Filter_TD_10557753_output.allocateHost();
    Table tbl_SerializeFromObject_TD_1185562_input;
    tbl_SerializeFromObject_TD_1185562_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_1185562_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_1185562_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_1185562_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_1185562_input.allocateHost();
    tbl_SerializeFromObject_TD_1185562_input.loadHost();
    Table tbl_SerializeFromObject_TD_11219554_input;
    tbl_SerializeFromObject_TD_11219554_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11219554_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_11219554_input.addCol("d_week_seq", 4);
    tbl_SerializeFromObject_TD_11219554_input.addCol("d_day_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11219554_input.allocateHost();
    tbl_SerializeFromObject_TD_11219554_input.loadHost();
    Table tbl_SerializeFromObject_TD_114973_input;
    tbl_SerializeFromObject_TD_114973_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_114973_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_114973_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_114973_input.addCol("ss_sales_price", 4);
    tbl_SerializeFromObject_TD_114973_input.allocateHost();
    tbl_SerializeFromObject_TD_114973_input.loadHost();
    Table tbl_SerializeFromObject_TD_1133894_input;
    tbl_SerializeFromObject_TD_1133894_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_1133894_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_1133894_input.addCol("d_week_seq", 4);
    tbl_SerializeFromObject_TD_1133894_input.addCol("d_day_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_1133894_input.allocateHost();
    tbl_SerializeFromObject_TD_1133894_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    std::cout << std::endl; 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_10_602345_s, tv_r_Filter_10_602345_e;
    gettimeofday(&tv_r_Filter_10_602345_s, 0);
    SW_Filter_TD_10557753(tbl_SerializeFromObject_TD_1133894_input, tbl_Filter_TD_10557753_output);
    gettimeofday(&tv_r_Filter_10_602345_e, 0);

    struct timeval tv_r_Filter_10_155297_s, tv_r_Filter_10_155297_e;
    gettimeofday(&tv_r_Filter_10_155297_s, 0);
    SW_Filter_TD_1026918(tbl_SerializeFromObject_TD_114973_input, tbl_Filter_TD_1026918_output);
    gettimeofday(&tv_r_Filter_10_155297_e, 0);

    struct timeval tv_r_Filter_10_997870_s, tv_r_Filter_10_997870_e;
    gettimeofday(&tv_r_Filter_10_997870_s, 0);
    SW_Filter_TD_10280259(tbl_SerializeFromObject_TD_11219554_input, tbl_Filter_TD_10280259_output);
    gettimeofday(&tv_r_Filter_10_997870_e, 0);

    struct timeval tv_r_Filter_10_143308_s, tv_r_Filter_10_143308_e;
    gettimeofday(&tv_r_Filter_10_143308_s, 0);
    SW_Filter_TD_10797846(tbl_SerializeFromObject_TD_1185562_input, tbl_Filter_TD_10797846_output);
    gettimeofday(&tv_r_Filter_10_143308_e, 0);

    struct timeval tv_r_JOIN_INNER_9_985197_s, tv_r_JOIN_INNER_9_985197_e;
    gettimeofday(&tv_r_JOIN_INNER_9_985197_s, 0);
    SW_JOIN_INNER_TD_9206684(tbl_Filter_TD_1026918_output, tbl_Filter_TD_10557753_output, tbl_JOIN_INNER_TD_9206684_output);
    gettimeofday(&tv_r_JOIN_INNER_9_985197_e, 0);

    struct timeval tv_r_JOIN_INNER_9_142167_s, tv_r_JOIN_INNER_9_142167_e;
    gettimeofday(&tv_r_JOIN_INNER_9_142167_s, 0);
    SW_JOIN_INNER_TD_9606643(tbl_Filter_TD_10797846_output, tbl_Filter_TD_10280259_output, tbl_JOIN_INNER_TD_9606643_output);
    gettimeofday(&tv_r_JOIN_INNER_9_142167_e, 0);

    struct timeval tv_r_Filter_8_62053_s, tv_r_Filter_8_62053_e;
    gettimeofday(&tv_r_Filter_8_62053_s, 0);
    SW_Filter_TD_8578775(tbl_SerializeFromObject_TD_9492681_input, tbl_Filter_TD_8578775_output);
    gettimeofday(&tv_r_Filter_8_62053_e, 0);

    struct timeval tv_r_Aggregate_8_78276_s, tv_r_Aggregate_8_78276_e;
    gettimeofday(&tv_r_Aggregate_8_78276_s, 0);
    SW_Aggregate_TD_8390994(tbl_JOIN_INNER_TD_9206684_output, tbl_Aggregate_TD_8390994_output);
    gettimeofday(&tv_r_Aggregate_8_78276_e, 0);

    struct timeval tv_r_Filter_8_862778_s, tv_r_Filter_8_862778_e;
    gettimeofday(&tv_r_Filter_8_862778_s, 0);
    SW_Filter_TD_8590989(tbl_SerializeFromObject_TD_9428042_input, tbl_Filter_TD_8590989_output);
    gettimeofday(&tv_r_Filter_8_862778_e, 0);

    struct timeval tv_r_Aggregate_8_274881_s, tv_r_Aggregate_8_274881_e;
    gettimeofday(&tv_r_Aggregate_8_274881_s, 0);
    SW_Aggregate_TD_8112002(tbl_JOIN_INNER_TD_9606643_output, tbl_Aggregate_TD_8112002_output);
    gettimeofday(&tv_r_Aggregate_8_274881_e, 0);

    struct timeval tv_r_Filter_7_508528_s, tv_r_Filter_7_508528_e;
    gettimeofday(&tv_r_Filter_7_508528_s, 0);
    SW_Filter_TD_7520649(tbl_SerializeFromObject_TD_8719221_input, tbl_Filter_TD_7520649_output);
    gettimeofday(&tv_r_Filter_7_508528_e, 0);

    struct timeval tv_r_JOIN_INNER_7_311719_s, tv_r_JOIN_INNER_7_311719_e;
    gettimeofday(&tv_r_JOIN_INNER_7_311719_s, 0);
    SW_JOIN_INNER_TD_7720700(tbl_Aggregate_TD_8390994_output, tbl_Filter_TD_8578775_output, tbl_JOIN_INNER_TD_7720700_output);
    gettimeofday(&tv_r_JOIN_INNER_7_311719_e, 0);

    struct timeval tv_r_Filter_7_173500_s, tv_r_Filter_7_173500_e;
    gettimeofday(&tv_r_Filter_7_173500_s, 0);
    SW_Filter_TD_7387081(tbl_SerializeFromObject_TD_8659135_input, tbl_Filter_TD_7387081_output);
    gettimeofday(&tv_r_Filter_7_173500_e, 0);

    struct timeval tv_r_JOIN_INNER_7_607716_s, tv_r_JOIN_INNER_7_607716_e;
    gettimeofday(&tv_r_JOIN_INNER_7_607716_s, 0);
    SW_JOIN_INNER_TD_7115974(tbl_Aggregate_TD_8112002_output, tbl_Filter_TD_8590989_output, tbl_JOIN_INNER_TD_7115974_output);
    gettimeofday(&tv_r_JOIN_INNER_7_607716_e, 0);

    struct timeval tv_r_JOIN_INNER_6_159150_s, tv_r_JOIN_INNER_6_159150_e;
    gettimeofday(&tv_r_JOIN_INNER_6_159150_s, 0);
    SW_JOIN_INNER_TD_6607199(tbl_JOIN_INNER_TD_7720700_output, tbl_Filter_TD_7520649_output, tbl_JOIN_INNER_TD_6607199_output);
    gettimeofday(&tv_r_JOIN_INNER_6_159150_e, 0);

    struct timeval tv_r_JOIN_INNER_6_101608_s, tv_r_JOIN_INNER_6_101608_e;
    gettimeofday(&tv_r_JOIN_INNER_6_101608_s, 0);
    SW_JOIN_INNER_TD_6265659(tbl_JOIN_INNER_TD_7115974_output, tbl_Filter_TD_7387081_output, tbl_JOIN_INNER_TD_6265659_output);
    gettimeofday(&tv_r_JOIN_INNER_6_101608_e, 0);

    struct timeval tv_r_Project_5_153842_s, tv_r_Project_5_153842_e;
    gettimeofday(&tv_r_Project_5_153842_s, 0);
    SW_Project_TD_5292855(tbl_JOIN_INNER_TD_6607199_output, tbl_Project_TD_5292855_output);
    gettimeofday(&tv_r_Project_5_153842_e, 0);

    struct timeval tv_r_Project_5_418712_s, tv_r_Project_5_418712_e;
    gettimeofday(&tv_r_Project_5_418712_s, 0);
    SW_Project_TD_5585874(tbl_JOIN_INNER_TD_6265659_output, tbl_Project_TD_5585874_output);
    gettimeofday(&tv_r_Project_5_418712_e, 0);

    struct timeval tv_r_JOIN_INNER_4_980606_s, tv_r_JOIN_INNER_4_980606_e;
    gettimeofday(&tv_r_JOIN_INNER_4_980606_s, 0);
    SW_JOIN_INNER_TD_4905171(tbl_Project_TD_5585874_output, tbl_Project_TD_5292855_output, tbl_JOIN_INNER_TD_4905171_output);
    gettimeofday(&tv_r_JOIN_INNER_4_980606_e, 0);

    struct timeval tv_r_Project_3_552823_s, tv_r_Project_3_552823_e;
    gettimeofday(&tv_r_Project_3_552823_s, 0);
    SW_Project_TD_332022(tbl_JOIN_INNER_TD_4905171_output, tbl_Project_TD_332022_output);
    gettimeofday(&tv_r_Project_3_552823_e, 0);

    struct timeval tv_r_Sort_2_961555_s, tv_r_Sort_2_961555_e;
    gettimeofday(&tv_r_Sort_2_961555_s, 0);
    SW_Sort_TD_2763988(tbl_Project_TD_332022_output, tbl_Sort_TD_2763988_output);
    gettimeofday(&tv_r_Sort_2_961555_e, 0);

    struct timeval tv_r_LocalLimit_1_526845_s, tv_r_LocalLimit_1_526845_e;
    gettimeofday(&tv_r_LocalLimit_1_526845_s, 0);
    SW_LocalLimit_TD_1688090(tbl_Sort_TD_2763988_output, tbl_LocalLimit_TD_1688090_output);
    gettimeofday(&tv_r_LocalLimit_1_526845_e, 0);

    struct timeval tv_r_GlobalLimit_0_610741_s, tv_r_GlobalLimit_0_610741_e;
    gettimeofday(&tv_r_GlobalLimit_0_610741_s, 0);
    SW_GlobalLimit_TD_0244891(tbl_LocalLimit_TD_1688090_output, tbl_GlobalLimit_TD_0244891_output);
    gettimeofday(&tv_r_GlobalLimit_0_610741_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_602345_s, &tv_r_Filter_10_602345_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1133894_input: " << tbl_SerializeFromObject_TD_1133894_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_155297_s, &tv_r_Filter_10_155297_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_114973_input: " << tbl_SerializeFromObject_TD_114973_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_997870_s, &tv_r_Filter_10_997870_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11219554_input: " << tbl_SerializeFromObject_TD_11219554_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_143308_s, &tv_r_Filter_10_143308_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1185562_input: " << tbl_SerializeFromObject_TD_1185562_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_985197_s, &tv_r_JOIN_INNER_9_985197_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_1026918_output: " << tbl_Filter_TD_1026918_output.getNumRow() << " " << "tbl_Filter_TD_10557753_output: " << tbl_Filter_TD_10557753_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_142167_s, &tv_r_JOIN_INNER_9_142167_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10797846_output: " << tbl_Filter_TD_10797846_output.getNumRow() << " " << "tbl_Filter_TD_10280259_output: " << tbl_Filter_TD_10280259_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_62053_s, &tv_r_Filter_8_62053_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9492681_input: " << tbl_SerializeFromObject_TD_9492681_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_8: " << tvdiff(&tv_r_Aggregate_8_78276_s, &tv_r_Aggregate_8_78276_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9206684_output: " << tbl_JOIN_INNER_TD_9206684_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_862778_s, &tv_r_Filter_8_862778_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9428042_input: " << tbl_SerializeFromObject_TD_9428042_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_8: " << tvdiff(&tv_r_Aggregate_8_274881_s, &tv_r_Aggregate_8_274881_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9606643_output: " << tbl_JOIN_INNER_TD_9606643_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_508528_s, &tv_r_Filter_7_508528_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8719221_input: " << tbl_SerializeFromObject_TD_8719221_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_311719_s, &tv_r_JOIN_INNER_7_311719_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_8390994_output: " << tbl_Aggregate_TD_8390994_output.getNumRow() << " " << "tbl_Filter_TD_8578775_output: " << tbl_Filter_TD_8578775_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_173500_s, &tv_r_Filter_7_173500_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8659135_input: " << tbl_SerializeFromObject_TD_8659135_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_607716_s, &tv_r_JOIN_INNER_7_607716_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_8112002_output: " << tbl_Aggregate_TD_8112002_output.getNumRow() << " " << "tbl_Filter_TD_8590989_output: " << tbl_Filter_TD_8590989_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_159150_s, &tv_r_JOIN_INNER_6_159150_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7720700_output: " << tbl_JOIN_INNER_TD_7720700_output.getNumRow() << " " << "tbl_Filter_TD_7520649_output: " << tbl_Filter_TD_7520649_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_101608_s, &tv_r_JOIN_INNER_6_101608_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7115974_output: " << tbl_JOIN_INNER_TD_7115974_output.getNumRow() << " " << "tbl_Filter_TD_7387081_output: " << tbl_Filter_TD_7387081_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_5: " << tvdiff(&tv_r_Project_5_153842_s, &tv_r_Project_5_153842_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6607199_output: " << tbl_JOIN_INNER_TD_6607199_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_5: " << tvdiff(&tv_r_Project_5_418712_s, &tv_r_Project_5_418712_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6265659_output: " << tbl_JOIN_INNER_TD_6265659_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_980606_s, &tv_r_JOIN_INNER_4_980606_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_5585874_output: " << tbl_Project_TD_5585874_output.getNumRow() << " " << "tbl_Project_TD_5292855_output: " << tbl_Project_TD_5292855_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_3: " << tvdiff(&tv_r_Project_3_552823_s, &tv_r_Project_3_552823_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4905171_output: " << tbl_JOIN_INNER_TD_4905171_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_961555_s, &tv_r_Sort_2_961555_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_332022_output: " << tbl_Project_TD_332022_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_526845_s, &tv_r_LocalLimit_1_526845_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2763988_output: " << tbl_Sort_TD_2763988_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_610741_s, &tv_r_GlobalLimit_0_610741_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1688090_output: " << tbl_LocalLimit_TD_1688090_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.598242 * 1000 << "ms" << std::endl; 
    return 0; 
}
