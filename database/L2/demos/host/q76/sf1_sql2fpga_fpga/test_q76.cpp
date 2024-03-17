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

#include "cfgFunc_q76.hpp" 
#include "q76.hpp" 

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
    std::cout << "NOTE:running query #76\n."; 
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
    Table tbl_GlobalLimit_TD_0199395_output("tbl_GlobalLimit_TD_0199395_output", 6100000, 7, "");
    tbl_GlobalLimit_TD_0199395_output.allocateHost();
    Table tbl_LocalLimit_TD_1508290_output("tbl_LocalLimit_TD_1508290_output", 6100000, 7, "");
    tbl_LocalLimit_TD_1508290_output.allocateHost();
    Table tbl_Sort_TD_2732461_output("tbl_Sort_TD_2732461_output", 6100000, 7, "");
    tbl_Sort_TD_2732461_output.allocateHost();
    Table tbl_Aggregate_TD_3969948_output("tbl_Aggregate_TD_3969948_output", 6100000, 7, "");
    tbl_Aggregate_TD_3969948_output.allocateHost();
    Table tbl_Union_TD_4497145_output("tbl_Union_TD_4497145_output", 6100000, 6, "");
    tbl_Union_TD_4497145_output.allocateHost();
    Table tbl_Project_TD_5916327_output("tbl_Project_TD_5916327_output", 6100000, 6, "");
    tbl_Project_TD_5916327_output.allocateHost();
    Table tbl_Project_TD_5734491_output("tbl_Project_TD_5734491_output", 6100000, 6, "");
    tbl_Project_TD_5734491_output.allocateHost();
    Table tbl_Project_TD_5319470_output("tbl_Project_TD_5319470_output", 6100000, 6, "");
    tbl_Project_TD_5319470_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6427217_output("tbl_JOIN_INNER_TD_6427217_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_6427217_output.allocateHost();
    Table tbl_JOIN_INNER_TD_615364_output("tbl_JOIN_INNER_TD_615364_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_615364_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6573325_output("tbl_JOIN_INNER_TD_6573325_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_6573325_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7304208_output("tbl_JOIN_INNER_TD_7304208_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_7304208_output.allocateHost();
    Table tbl_Filter_TD_7573692_output("tbl_Filter_TD_7573692_output", 6100000, 3, "");
    tbl_Filter_TD_7573692_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7567278_output("tbl_JOIN_INNER_TD_7567278_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_7567278_output.allocateHost();
    Table tbl_Filter_TD_7519686_output("tbl_Filter_TD_7519686_output", 6100000, 3, "");
    tbl_Filter_TD_7519686_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7432201_output("tbl_JOIN_INNER_TD_7432201_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_7432201_output.allocateHost();
    Table tbl_Filter_TD_7209744_output("tbl_Filter_TD_7209744_output", 6100000, 3, "");
    tbl_Filter_TD_7209744_output.allocateHost();
    Table tbl_Filter_TD_8412947_output("tbl_Filter_TD_8412947_output", 6100000, 4, "");
    tbl_Filter_TD_8412947_output.allocateHost();
    Table tbl_Filter_TD_8755214_output("tbl_Filter_TD_8755214_output", 6100000, 2, "");
    tbl_Filter_TD_8755214_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8313236_input;
    tbl_SerializeFromObject_TD_8313236_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8313236_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_8313236_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_8313236_input.addCol("d_qoy", 4);
    tbl_SerializeFromObject_TD_8313236_input.allocateHost();
    tbl_SerializeFromObject_TD_8313236_input.loadHost();
    Table tbl_Filter_TD_8862949_output("tbl_Filter_TD_8862949_output", 6100000, 4, "");
    tbl_Filter_TD_8862949_output.allocateHost();
    Table tbl_Filter_TD_8518523_output("tbl_Filter_TD_8518523_output", 6100000, 2, "");
    tbl_Filter_TD_8518523_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8721637_input;
    tbl_SerializeFromObject_TD_8721637_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8721637_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_8721637_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_8721637_input.addCol("d_qoy", 4);
    tbl_SerializeFromObject_TD_8721637_input.allocateHost();
    tbl_SerializeFromObject_TD_8721637_input.loadHost();
    Table tbl_Filter_TD_8483042_output("tbl_Filter_TD_8483042_output", 6100000, 4, "");
    tbl_Filter_TD_8483042_output.allocateHost();
    Table tbl_Filter_TD_8467215_output("tbl_Filter_TD_8467215_output", 6100000, 2, "");
    tbl_Filter_TD_8467215_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8167116_input;
    tbl_SerializeFromObject_TD_8167116_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8167116_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_8167116_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_8167116_input.addCol("d_qoy", 4);
    tbl_SerializeFromObject_TD_8167116_input.allocateHost();
    tbl_SerializeFromObject_TD_8167116_input.loadHost();
    Table tbl_SerializeFromObject_TD_9573968_input;
    tbl_SerializeFromObject_TD_9573968_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_9573968_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_9573968_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_9573968_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_9573968_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_9573968_input.allocateHost();
    tbl_SerializeFromObject_TD_9573968_input.loadHost();
    Table tbl_SerializeFromObject_TD_9655304_input;
    tbl_SerializeFromObject_TD_9655304_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9655304_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_9655304_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9655304_input.allocateHost();
    tbl_SerializeFromObject_TD_9655304_input.loadHost();
    Table tbl_SerializeFromObject_TD_9763286_input;
    tbl_SerializeFromObject_TD_9763286_input = Table("web_sales", web_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_9763286_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_9763286_input.addCol("ws_item_sk", 4);
    tbl_SerializeFromObject_TD_9763286_input.addCol("ws_ship_customer_sk", 4);
    tbl_SerializeFromObject_TD_9763286_input.addCol("ws_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_9763286_input.allocateHost();
    tbl_SerializeFromObject_TD_9763286_input.loadHost();
    Table tbl_SerializeFromObject_TD_9684655_input;
    tbl_SerializeFromObject_TD_9684655_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9684655_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_9684655_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9684655_input.allocateHost();
    tbl_SerializeFromObject_TD_9684655_input.loadHost();
    Table tbl_SerializeFromObject_TD_9537733_input;
    tbl_SerializeFromObject_TD_9537733_input = Table("catalog_sales", catalog_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_9537733_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_9537733_input.addCol("cs_ship_addr_sk", 4);
    tbl_SerializeFromObject_TD_9537733_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_9537733_input.addCol("cs_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_9537733_input.allocateHost();
    tbl_SerializeFromObject_TD_9537733_input.loadHost();
    Table tbl_SerializeFromObject_TD_9825367_input;
    tbl_SerializeFromObject_TD_9825367_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9825367_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_9825367_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9825367_input.allocateHost();
    tbl_SerializeFromObject_TD_9825367_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    std::cout << std::endl; 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_8_87969_s, tv_r_Filter_8_87969_e;
    gettimeofday(&tv_r_Filter_8_87969_s, 0);
    SW_Filter_TD_8467215(tbl_SerializeFromObject_TD_9825367_input, tbl_Filter_TD_8467215_output);
    gettimeofday(&tv_r_Filter_8_87969_e, 0);

    struct timeval tv_r_Filter_8_494973_s, tv_r_Filter_8_494973_e;
    gettimeofday(&tv_r_Filter_8_494973_s, 0);
    SW_Filter_TD_8483042(tbl_SerializeFromObject_TD_9537733_input, tbl_Filter_TD_8483042_output);
    gettimeofday(&tv_r_Filter_8_494973_e, 0);

    struct timeval tv_r_Filter_8_166240_s, tv_r_Filter_8_166240_e;
    gettimeofday(&tv_r_Filter_8_166240_s, 0);
    SW_Filter_TD_8518523(tbl_SerializeFromObject_TD_9684655_input, tbl_Filter_TD_8518523_output);
    gettimeofday(&tv_r_Filter_8_166240_e, 0);

    struct timeval tv_r_Filter_8_583414_s, tv_r_Filter_8_583414_e;
    gettimeofday(&tv_r_Filter_8_583414_s, 0);
    SW_Filter_TD_8862949(tbl_SerializeFromObject_TD_9763286_input, tbl_Filter_TD_8862949_output);
    gettimeofday(&tv_r_Filter_8_583414_e, 0);

    struct timeval tv_r_Filter_8_966858_s, tv_r_Filter_8_966858_e;
    gettimeofday(&tv_r_Filter_8_966858_s, 0);
    SW_Filter_TD_8755214(tbl_SerializeFromObject_TD_9655304_input, tbl_Filter_TD_8755214_output);
    gettimeofday(&tv_r_Filter_8_966858_e, 0);

    struct timeval tv_r_Filter_8_139202_s, tv_r_Filter_8_139202_e;
    gettimeofday(&tv_r_Filter_8_139202_s, 0);
    SW_Filter_TD_8412947(tbl_SerializeFromObject_TD_9573968_input, tbl_Filter_TD_8412947_output);
    gettimeofday(&tv_r_Filter_8_139202_e, 0);

    struct timeval tv_r_Filter_7_453319_s, tv_r_Filter_7_453319_e;
    gettimeofday(&tv_r_Filter_7_453319_s, 0);
    SW_Filter_TD_7209744(tbl_SerializeFromObject_TD_8167116_input, tbl_Filter_TD_7209744_output);
    gettimeofday(&tv_r_Filter_7_453319_e, 0);

    struct timeval tv_r_JOIN_INNER_7_332384_s, tv_r_JOIN_INNER_7_332384_e;
    gettimeofday(&tv_r_JOIN_INNER_7_332384_s, 0);
    SW_JOIN_INNER_TD_7432201(tbl_Filter_TD_8483042_output, tbl_Filter_TD_8467215_output, tbl_JOIN_INNER_TD_7432201_output);
    gettimeofday(&tv_r_JOIN_INNER_7_332384_e, 0);

    struct timeval tv_r_Filter_7_239474_s, tv_r_Filter_7_239474_e;
    gettimeofday(&tv_r_Filter_7_239474_s, 0);
    SW_Filter_TD_7519686(tbl_SerializeFromObject_TD_8721637_input, tbl_Filter_TD_7519686_output);
    gettimeofday(&tv_r_Filter_7_239474_e, 0);

    struct timeval tv_r_JOIN_INNER_7_408092_s, tv_r_JOIN_INNER_7_408092_e;
    gettimeofday(&tv_r_JOIN_INNER_7_408092_s, 0);
    SW_JOIN_INNER_TD_7567278(tbl_Filter_TD_8862949_output, tbl_Filter_TD_8518523_output, tbl_JOIN_INNER_TD_7567278_output);
    gettimeofday(&tv_r_JOIN_INNER_7_408092_e, 0);

    struct timeval tv_r_Filter_7_154711_s, tv_r_Filter_7_154711_e;
    gettimeofday(&tv_r_Filter_7_154711_s, 0);
    SW_Filter_TD_7573692(tbl_SerializeFromObject_TD_8313236_input, tbl_Filter_TD_7573692_output);
    gettimeofday(&tv_r_Filter_7_154711_e, 0);

    struct timeval tv_r_JOIN_INNER_7_554699_s, tv_r_JOIN_INNER_7_554699_e;
    gettimeofday(&tv_r_JOIN_INNER_7_554699_s, 0);
    SW_JOIN_INNER_TD_7304208(tbl_Filter_TD_8412947_output, tbl_Filter_TD_8755214_output, tbl_JOIN_INNER_TD_7304208_output);
    gettimeofday(&tv_r_JOIN_INNER_7_554699_e, 0);

    struct timeval tv_r_JOIN_INNER_6_370732_s, tv_r_JOIN_INNER_6_370732_e;
    gettimeofday(&tv_r_JOIN_INNER_6_370732_s, 0);
    SW_JOIN_INNER_TD_6573325(tbl_JOIN_INNER_TD_7432201_output, tbl_Filter_TD_7209744_output, tbl_JOIN_INNER_TD_6573325_output);
    gettimeofday(&tv_r_JOIN_INNER_6_370732_e, 0);

    struct timeval tv_r_JOIN_INNER_6_571399_s, tv_r_JOIN_INNER_6_571399_e;
    gettimeofday(&tv_r_JOIN_INNER_6_571399_s, 0);
    SW_JOIN_INNER_TD_615364(tbl_JOIN_INNER_TD_7567278_output, tbl_Filter_TD_7519686_output, tbl_JOIN_INNER_TD_615364_output);
    gettimeofday(&tv_r_JOIN_INNER_6_571399_e, 0);

    struct timeval tv_r_JOIN_INNER_6_66599_s, tv_r_JOIN_INNER_6_66599_e;
    gettimeofday(&tv_r_JOIN_INNER_6_66599_s, 0);
    SW_JOIN_INNER_TD_6427217(tbl_JOIN_INNER_TD_7304208_output, tbl_Filter_TD_7573692_output, tbl_JOIN_INNER_TD_6427217_output);
    gettimeofday(&tv_r_JOIN_INNER_6_66599_e, 0);

    struct timeval tv_r_Project_5_738791_s, tv_r_Project_5_738791_e;
    gettimeofday(&tv_r_Project_5_738791_s, 0);
    SW_Project_TD_5319470(tbl_JOIN_INNER_TD_6573325_output, tbl_Project_TD_5319470_output);
    gettimeofday(&tv_r_Project_5_738791_e, 0);

    struct timeval tv_r_Project_5_184749_s, tv_r_Project_5_184749_e;
    gettimeofday(&tv_r_Project_5_184749_s, 0);
    SW_Project_TD_5734491(tbl_JOIN_INNER_TD_615364_output, tbl_Project_TD_5734491_output);
    gettimeofday(&tv_r_Project_5_184749_e, 0);

    struct timeval tv_r_Project_5_328061_s, tv_r_Project_5_328061_e;
    gettimeofday(&tv_r_Project_5_328061_s, 0);
    SW_Project_TD_5916327(tbl_JOIN_INNER_TD_6427217_output, tbl_Project_TD_5916327_output);
    gettimeofday(&tv_r_Project_5_328061_e, 0);

    struct timeval tv_r_Union_4_537989_s, tv_r_Union_4_537989_e;
    gettimeofday(&tv_r_Union_4_537989_s, 0);
    SW_Union_TD_4497145(tbl_Project_TD_5916327_output, tbl_Project_TD_5734491_output, tbl_Project_TD_5319470_output, tbl_Union_TD_4497145_output);
    gettimeofday(&tv_r_Union_4_537989_e, 0);

    struct timeval tv_r_Aggregate_3_739296_s, tv_r_Aggregate_3_739296_e;
    gettimeofday(&tv_r_Aggregate_3_739296_s, 0);
    SW_Aggregate_TD_3969948(tbl_Union_TD_4497145_output, tbl_Aggregate_TD_3969948_output);
    gettimeofday(&tv_r_Aggregate_3_739296_e, 0);

    struct timeval tv_r_Sort_2_854231_s, tv_r_Sort_2_854231_e;
    gettimeofday(&tv_r_Sort_2_854231_s, 0);
    SW_Sort_TD_2732461(tbl_Aggregate_TD_3969948_output, tbl_Sort_TD_2732461_output);
    gettimeofday(&tv_r_Sort_2_854231_e, 0);

    struct timeval tv_r_LocalLimit_1_736761_s, tv_r_LocalLimit_1_736761_e;
    gettimeofday(&tv_r_LocalLimit_1_736761_s, 0);
    SW_LocalLimit_TD_1508290(tbl_Sort_TD_2732461_output, tbl_LocalLimit_TD_1508290_output);
    gettimeofday(&tv_r_LocalLimit_1_736761_e, 0);

    struct timeval tv_r_GlobalLimit_0_827915_s, tv_r_GlobalLimit_0_827915_e;
    gettimeofday(&tv_r_GlobalLimit_0_827915_s, 0);
    SW_GlobalLimit_TD_0199395(tbl_LocalLimit_TD_1508290_output, tbl_GlobalLimit_TD_0199395_output);
    gettimeofday(&tv_r_GlobalLimit_0_827915_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_87969_s, &tv_r_Filter_8_87969_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9825367_input: " << tbl_SerializeFromObject_TD_9825367_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_494973_s, &tv_r_Filter_8_494973_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9537733_input: " << tbl_SerializeFromObject_TD_9537733_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_166240_s, &tv_r_Filter_8_166240_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9684655_input: " << tbl_SerializeFromObject_TD_9684655_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_583414_s, &tv_r_Filter_8_583414_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9763286_input: " << tbl_SerializeFromObject_TD_9763286_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_966858_s, &tv_r_Filter_8_966858_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9655304_input: " << tbl_SerializeFromObject_TD_9655304_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_139202_s, &tv_r_Filter_8_139202_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9573968_input: " << tbl_SerializeFromObject_TD_9573968_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_453319_s, &tv_r_Filter_7_453319_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8167116_input: " << tbl_SerializeFromObject_TD_8167116_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_332384_s, &tv_r_JOIN_INNER_7_332384_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8483042_output: " << tbl_Filter_TD_8483042_output.getNumRow() << " " << "tbl_Filter_TD_8467215_output: " << tbl_Filter_TD_8467215_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_239474_s, &tv_r_Filter_7_239474_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8721637_input: " << tbl_SerializeFromObject_TD_8721637_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_408092_s, &tv_r_JOIN_INNER_7_408092_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8862949_output: " << tbl_Filter_TD_8862949_output.getNumRow() << " " << "tbl_Filter_TD_8518523_output: " << tbl_Filter_TD_8518523_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_154711_s, &tv_r_Filter_7_154711_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8313236_input: " << tbl_SerializeFromObject_TD_8313236_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_554699_s, &tv_r_JOIN_INNER_7_554699_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8412947_output: " << tbl_Filter_TD_8412947_output.getNumRow() << " " << "tbl_Filter_TD_8755214_output: " << tbl_Filter_TD_8755214_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_370732_s, &tv_r_JOIN_INNER_6_370732_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7432201_output: " << tbl_JOIN_INNER_TD_7432201_output.getNumRow() << " " << "tbl_Filter_TD_7209744_output: " << tbl_Filter_TD_7209744_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_571399_s, &tv_r_JOIN_INNER_6_571399_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7567278_output: " << tbl_JOIN_INNER_TD_7567278_output.getNumRow() << " " << "tbl_Filter_TD_7519686_output: " << tbl_Filter_TD_7519686_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_66599_s, &tv_r_JOIN_INNER_6_66599_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7304208_output: " << tbl_JOIN_INNER_TD_7304208_output.getNumRow() << " " << "tbl_Filter_TD_7573692_output: " << tbl_Filter_TD_7573692_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_5: " << tvdiff(&tv_r_Project_5_738791_s, &tv_r_Project_5_738791_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6573325_output: " << tbl_JOIN_INNER_TD_6573325_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_5: " << tvdiff(&tv_r_Project_5_184749_s, &tv_r_Project_5_184749_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_615364_output: " << tbl_JOIN_INNER_TD_615364_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_5: " << tvdiff(&tv_r_Project_5_328061_s, &tv_r_Project_5_328061_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6427217_output: " << tbl_JOIN_INNER_TD_6427217_output.getNumRow() << " " << std::endl; 

    std::cout << "Union_4: " << tvdiff(&tv_r_Union_4_537989_s, &tv_r_Union_4_537989_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_5916327_output: " << tbl_Project_TD_5916327_output.getNumRow() << " " << "tbl_Project_TD_5734491_output: " << tbl_Project_TD_5734491_output.getNumRow() << " " << "tbl_Project_TD_5319470_output: " << tbl_Project_TD_5319470_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_739296_s, &tv_r_Aggregate_3_739296_e) / 1000.0 << " ms " 
     << "tbl_Union_TD_4497145_output: " << tbl_Union_TD_4497145_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_854231_s, &tv_r_Sort_2_854231_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3969948_output: " << tbl_Aggregate_TD_3969948_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_736761_s, &tv_r_LocalLimit_1_736761_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2732461_output: " << tbl_Sort_TD_2732461_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_827915_s, &tv_r_GlobalLimit_0_827915_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1508290_output: " << tbl_LocalLimit_TD_1508290_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.8147722 * 1000 << "ms" << std::endl; 
    return 0; 
}
