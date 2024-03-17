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

#include "cfgFunc_q74.hpp" 
#include "q74.hpp" 

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
    std::cout << "NOTE:running query #74\n."; 
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
    Table tbl_GlobalLimit_TD_0529391_output("tbl_GlobalLimit_TD_0529391_output", 6100000, 3, "");
    tbl_GlobalLimit_TD_0529391_output.allocateHost();
    Table tbl_LocalLimit_TD_1483626_output("tbl_LocalLimit_TD_1483626_output", 6100000, 3, "");
    tbl_LocalLimit_TD_1483626_output.allocateHost();
    Table tbl_Sort_TD_2666397_output("tbl_Sort_TD_2666397_output", 6100000, 3, "");
    tbl_Sort_TD_2666397_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3702038_output("tbl_JOIN_INNER_TD_3702038_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_3702038_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4124713_output("tbl_JOIN_INNER_TD_4124713_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_4124713_output.allocateHost();
    Table tbl_Aggregate_TD_4949259_output("tbl_Aggregate_TD_4949259_output", 6100000, 2, "");
    tbl_Aggregate_TD_4949259_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5209094_output("tbl_JOIN_INNER_TD_5209094_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_5209094_output.allocateHost();
    Table tbl_Project_TD_5973542_output("tbl_Project_TD_5973542_output", 6100000, 2, "");
    tbl_Project_TD_5973542_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5898578_output("tbl_JOIN_INNER_TD_5898578_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_5898578_output.allocateHost();
    Table tbl_Filter_TD_6543927_output("tbl_Filter_TD_6543927_output", 6100000, 2, "");
    tbl_Filter_TD_6543927_output.allocateHost();
    Table tbl_Aggregate_TD_6862075_output("tbl_Aggregate_TD_6862075_output", 6100000, 4, "");
    tbl_Aggregate_TD_6862075_output.allocateHost();
    Table tbl_Filter_TD_6122861_output("tbl_Filter_TD_6122861_output", 6100000, 2, "");
    tbl_Filter_TD_6122861_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6987382_output("tbl_JOIN_INNER_TD_6987382_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_6987382_output.allocateHost();
    Table tbl_Filter_TD_6198075_output("tbl_Filter_TD_6198075_output", 6100000, 2, "");
    tbl_Filter_TD_6198075_output.allocateHost();
    Table tbl_Aggregate_TD_7612001_output("tbl_Aggregate_TD_7612001_output", 6100000, 2, "");
    tbl_Aggregate_TD_7612001_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7914670_output("tbl_JOIN_INNER_TD_7914670_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_7914670_output.allocateHost();
    Table tbl_Aggregate_TD_7135176_output("tbl_Aggregate_TD_7135176_output", 6100000, 2, "");
    tbl_Aggregate_TD_7135176_output.allocateHost();
    Table tbl_Filter_TD_7606581_output("tbl_Filter_TD_7606581_output", 6100000, 4, "");
    tbl_Filter_TD_7606581_output.allocateHost();
    Table tbl_Filter_TD_7674026_output("tbl_Filter_TD_7674026_output", 6100000, 3, "");
    tbl_Filter_TD_7674026_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7975189_input;
    tbl_SerializeFromObject_TD_7975189_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7975189_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_7975189_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_7975189_input.allocateHost();
    tbl_SerializeFromObject_TD_7975189_input.loadHost();
    Table tbl_JOIN_INNER_TD_8128046_output("tbl_JOIN_INNER_TD_8128046_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_8128046_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8637088_output("tbl_JOIN_INNER_TD_8637088_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_8637088_output.allocateHost();
    Table tbl_Filter_TD_8670784_output("tbl_Filter_TD_8670784_output", 6100000, 2, "");
    tbl_Filter_TD_8670784_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8457000_output("tbl_JOIN_INNER_TD_8457000_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_8457000_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8236414_input;
    tbl_SerializeFromObject_TD_8236414_input = Table("customer", customer_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_8236414_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_8236414_input.addCol("c_customer_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8236414_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8236414_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8236414_input.allocateHost();
    tbl_SerializeFromObject_TD_8236414_input.loadHost();
    Table tbl_SerializeFromObject_TD_8829642_input;
    tbl_SerializeFromObject_TD_8829642_input = Table("web_sales", web_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8829642_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_8829642_input.addCol("ws_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_8829642_input.addCol("ws_net_paid", 4);
    tbl_SerializeFromObject_TD_8829642_input.allocateHost();
    tbl_SerializeFromObject_TD_8829642_input.loadHost();
    Table tbl_JOIN_INNER_TD_9915620_output("tbl_JOIN_INNER_TD_9915620_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_9915620_output.allocateHost();
    Table tbl_Filter_TD_9937168_output("tbl_Filter_TD_9937168_output", 6100000, 2, "");
    tbl_Filter_TD_9937168_output.allocateHost();
    Table tbl_Filter_TD_9794804_output("tbl_Filter_TD_9794804_output", 6100000, 4, "");
    tbl_Filter_TD_9794804_output.allocateHost();
    Table tbl_Filter_TD_9947129_output("tbl_Filter_TD_9947129_output", 6100000, 3, "");
    tbl_Filter_TD_9947129_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9161498_input;
    tbl_SerializeFromObject_TD_9161498_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9161498_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_9161498_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_9161498_input.allocateHost();
    tbl_SerializeFromObject_TD_9161498_input.loadHost();
    Table tbl_JOIN_INNER_TD_9984531_output("tbl_JOIN_INNER_TD_9984531_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_9984531_output.allocateHost();
    Table tbl_Filter_TD_9388926_output("tbl_Filter_TD_9388926_output", 6100000, 2, "");
    tbl_Filter_TD_9388926_output.allocateHost();
    Table tbl_Filter_TD_10841932_output("tbl_Filter_TD_10841932_output", 6100000, 4, "");
    tbl_Filter_TD_10841932_output.allocateHost();
    Table tbl_Filter_TD_10631613_output("tbl_Filter_TD_10631613_output", 6100000, 3, "");
    tbl_Filter_TD_10631613_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10490387_input;
    tbl_SerializeFromObject_TD_10490387_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10490387_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10490387_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10490387_input.allocateHost();
    tbl_SerializeFromObject_TD_10490387_input.loadHost();
    Table tbl_SerializeFromObject_TD_10373979_input;
    tbl_SerializeFromObject_TD_10373979_input = Table("customer", customer_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_10373979_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_10373979_input.addCol("c_customer_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10373979_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10373979_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10373979_input.allocateHost();
    tbl_SerializeFromObject_TD_10373979_input.loadHost();
    Table tbl_SerializeFromObject_TD_10630342_input;
    tbl_SerializeFromObject_TD_10630342_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10630342_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10630342_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_10630342_input.addCol("ss_net_paid", 4);
    tbl_SerializeFromObject_TD_10630342_input.allocateHost();
    tbl_SerializeFromObject_TD_10630342_input.loadHost();
    Table tbl_Filter_TD_10555553_output("tbl_Filter_TD_10555553_output", 6100000, 4, "");
    tbl_Filter_TD_10555553_output.allocateHost();
    Table tbl_Filter_TD_10523569_output("tbl_Filter_TD_10523569_output", 6100000, 3, "");
    tbl_Filter_TD_10523569_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10655370_input;
    tbl_SerializeFromObject_TD_10655370_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10655370_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10655370_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10655370_input.allocateHost();
    tbl_SerializeFromObject_TD_10655370_input.loadHost();
    Table tbl_SerializeFromObject_TD_11587509_input;
    tbl_SerializeFromObject_TD_11587509_input = Table("customer", customer_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_11587509_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_11587509_input.addCol("c_customer_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11587509_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11587509_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11587509_input.allocateHost();
    tbl_SerializeFromObject_TD_11587509_input.loadHost();
    Table tbl_SerializeFromObject_TD_11927657_input;
    tbl_SerializeFromObject_TD_11927657_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11927657_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_11927657_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_11927657_input.addCol("ss_net_paid", 4);
    tbl_SerializeFromObject_TD_11927657_input.allocateHost();
    tbl_SerializeFromObject_TD_11927657_input.loadHost();
    Table tbl_SerializeFromObject_TD_11666360_input;
    tbl_SerializeFromObject_TD_11666360_input = Table("customer", customer_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_11666360_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_11666360_input.addCol("c_customer_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11666360_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11666360_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11666360_input.allocateHost();
    tbl_SerializeFromObject_TD_11666360_input.loadHost();
    Table tbl_SerializeFromObject_TD_11447356_input;
    tbl_SerializeFromObject_TD_11447356_input = Table("web_sales", web_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11447356_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_11447356_input.addCol("ws_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_11447356_input.addCol("ws_net_paid", 4);
    tbl_SerializeFromObject_TD_11447356_input.allocateHost();
    tbl_SerializeFromObject_TD_11447356_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    std::cout << std::endl; 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_10_573237_s, tv_r_Filter_10_573237_e;
    gettimeofday(&tv_r_Filter_10_573237_s, 0);
    SW_Filter_TD_10523569(tbl_SerializeFromObject_TD_11447356_input, tbl_Filter_TD_10523569_output);
    gettimeofday(&tv_r_Filter_10_573237_e, 0);

    struct timeval tv_r_Filter_10_865599_s, tv_r_Filter_10_865599_e;
    gettimeofday(&tv_r_Filter_10_865599_s, 0);
    SW_Filter_TD_10555553(tbl_SerializeFromObject_TD_11666360_input, tbl_Filter_TD_10555553_output);
    gettimeofday(&tv_r_Filter_10_865599_e, 0);

    struct timeval tv_r_Filter_10_991239_s, tv_r_Filter_10_991239_e;
    gettimeofday(&tv_r_Filter_10_991239_s, 0);
    SW_Filter_TD_10631613(tbl_SerializeFromObject_TD_11927657_input, tbl_Filter_TD_10631613_output);
    gettimeofday(&tv_r_Filter_10_991239_e, 0);

    struct timeval tv_r_Filter_10_268764_s, tv_r_Filter_10_268764_e;
    gettimeofday(&tv_r_Filter_10_268764_s, 0);
    SW_Filter_TD_10841932(tbl_SerializeFromObject_TD_11587509_input, tbl_Filter_TD_10841932_output);
    gettimeofday(&tv_r_Filter_10_268764_e, 0);

    struct timeval tv_r_Filter_9_545278_s, tv_r_Filter_9_545278_e;
    gettimeofday(&tv_r_Filter_9_545278_s, 0);
    SW_Filter_TD_9388926(tbl_SerializeFromObject_TD_10655370_input, tbl_Filter_TD_9388926_output);
    gettimeofday(&tv_r_Filter_9_545278_e, 0);

    struct timeval tv_r_JOIN_INNER_9_201508_s, tv_r_JOIN_INNER_9_201508_e;
    gettimeofday(&tv_r_JOIN_INNER_9_201508_s, 0);
    SW_JOIN_INNER_TD_9984531(tbl_Filter_TD_10555553_output, tbl_Filter_TD_10523569_output, tbl_JOIN_INNER_TD_9984531_output);
    gettimeofday(&tv_r_JOIN_INNER_9_201508_e, 0);

    struct timeval tv_r_Filter_9_371067_s, tv_r_Filter_9_371067_e;
    gettimeofday(&tv_r_Filter_9_371067_s, 0);
    SW_Filter_TD_9947129(tbl_SerializeFromObject_TD_10630342_input, tbl_Filter_TD_9947129_output);
    gettimeofday(&tv_r_Filter_9_371067_e, 0);

    struct timeval tv_r_Filter_9_804425_s, tv_r_Filter_9_804425_e;
    gettimeofday(&tv_r_Filter_9_804425_s, 0);
    SW_Filter_TD_9794804(tbl_SerializeFromObject_TD_10373979_input, tbl_Filter_TD_9794804_output);
    gettimeofday(&tv_r_Filter_9_804425_e, 0);

    struct timeval tv_r_Filter_9_428293_s, tv_r_Filter_9_428293_e;
    gettimeofday(&tv_r_Filter_9_428293_s, 0);
    SW_Filter_TD_9937168(tbl_SerializeFromObject_TD_10490387_input, tbl_Filter_TD_9937168_output);
    gettimeofday(&tv_r_Filter_9_428293_e, 0);

    struct timeval tv_r_JOIN_INNER_9_603283_s, tv_r_JOIN_INNER_9_603283_e;
    gettimeofday(&tv_r_JOIN_INNER_9_603283_s, 0);
    SW_JOIN_INNER_TD_9915620(tbl_Filter_TD_10841932_output, tbl_Filter_TD_10631613_output, tbl_JOIN_INNER_TD_9915620_output);
    gettimeofday(&tv_r_JOIN_INNER_9_603283_e, 0);

    struct timeval tv_r_JOIN_INNER_8_395995_s, tv_r_JOIN_INNER_8_395995_e;
    gettimeofday(&tv_r_JOIN_INNER_8_395995_s, 0);
    SW_JOIN_INNER_TD_8457000(tbl_JOIN_INNER_TD_9984531_output, tbl_Filter_TD_9388926_output, tbl_JOIN_INNER_TD_8457000_output);
    gettimeofday(&tv_r_JOIN_INNER_8_395995_e, 0);

    struct timeval tv_r_Filter_8_247733_s, tv_r_Filter_8_247733_e;
    gettimeofday(&tv_r_Filter_8_247733_s, 0);
    SW_Filter_TD_8670784(tbl_SerializeFromObject_TD_9161498_input, tbl_Filter_TD_8670784_output);
    gettimeofday(&tv_r_Filter_8_247733_e, 0);

    struct timeval tv_r_JOIN_INNER_8_938591_s, tv_r_JOIN_INNER_8_938591_e;
    gettimeofday(&tv_r_JOIN_INNER_8_938591_s, 0);
    SW_JOIN_INNER_TD_8637088(tbl_Filter_TD_9794804_output, tbl_Filter_TD_9947129_output, tbl_JOIN_INNER_TD_8637088_output);
    gettimeofday(&tv_r_JOIN_INNER_8_938591_e, 0);

    struct timeval tv_r_JOIN_INNER_8_540131_s, tv_r_JOIN_INNER_8_540131_e;
    gettimeofday(&tv_r_JOIN_INNER_8_540131_s, 0);
    SW_JOIN_INNER_TD_8128046(tbl_JOIN_INNER_TD_9915620_output, tbl_Filter_TD_9937168_output, tbl_JOIN_INNER_TD_8128046_output);
    gettimeofday(&tv_r_JOIN_INNER_8_540131_e, 0);

    struct timeval tv_r_Filter_7_163227_s, tv_r_Filter_7_163227_e;
    gettimeofday(&tv_r_Filter_7_163227_s, 0);
    SW_Filter_TD_7674026(tbl_SerializeFromObject_TD_8829642_input, tbl_Filter_TD_7674026_output);
    gettimeofday(&tv_r_Filter_7_163227_e, 0);

    struct timeval tv_r_Filter_7_923969_s, tv_r_Filter_7_923969_e;
    gettimeofday(&tv_r_Filter_7_923969_s, 0);
    SW_Filter_TD_7606581(tbl_SerializeFromObject_TD_8236414_input, tbl_Filter_TD_7606581_output);
    gettimeofday(&tv_r_Filter_7_923969_e, 0);

    struct timeval tv_r_Aggregate_7_602308_s, tv_r_Aggregate_7_602308_e;
    gettimeofday(&tv_r_Aggregate_7_602308_s, 0);
    SW_Aggregate_TD_7135176(tbl_JOIN_INNER_TD_8457000_output, tbl_Aggregate_TD_7135176_output);
    gettimeofday(&tv_r_Aggregate_7_602308_e, 0);

    struct timeval tv_r_JOIN_INNER_7_90078_s, tv_r_JOIN_INNER_7_90078_e;
    gettimeofday(&tv_r_JOIN_INNER_7_90078_s, 0);
    SW_JOIN_INNER_TD_7914670(tbl_JOIN_INNER_TD_8637088_output, tbl_Filter_TD_8670784_output, tbl_JOIN_INNER_TD_7914670_output);
    gettimeofday(&tv_r_JOIN_INNER_7_90078_e, 0);

    struct timeval tv_r_Aggregate_7_493060_s, tv_r_Aggregate_7_493060_e;
    gettimeofday(&tv_r_Aggregate_7_493060_s, 0);
    SW_Aggregate_TD_7612001(tbl_JOIN_INNER_TD_8128046_output, tbl_Aggregate_TD_7612001_output);
    gettimeofday(&tv_r_Aggregate_7_493060_e, 0);

    struct timeval tv_r_Filter_6_812631_s, tv_r_Filter_6_812631_e;
    gettimeofday(&tv_r_Filter_6_812631_s, 0);
    SW_Filter_TD_6198075(tbl_SerializeFromObject_TD_7975189_input, tbl_Filter_TD_6198075_output);
    gettimeofday(&tv_r_Filter_6_812631_e, 0);

    struct timeval tv_r_JOIN_INNER_6_755679_s, tv_r_JOIN_INNER_6_755679_e;
    gettimeofday(&tv_r_JOIN_INNER_6_755679_s, 0);
    SW_JOIN_INNER_TD_6987382(tbl_Filter_TD_7606581_output, tbl_Filter_TD_7674026_output, tbl_JOIN_INNER_TD_6987382_output);
    gettimeofday(&tv_r_JOIN_INNER_6_755679_e, 0);

    struct timeval tv_r_Filter_6_577026_s, tv_r_Filter_6_577026_e;
    gettimeofday(&tv_r_Filter_6_577026_s, 0);
    SW_Filter_TD_6122861(tbl_Aggregate_TD_7135176_output, tbl_Filter_TD_6122861_output);
    gettimeofday(&tv_r_Filter_6_577026_e, 0);

    struct timeval tv_r_Aggregate_6_98324_s, tv_r_Aggregate_6_98324_e;
    gettimeofday(&tv_r_Aggregate_6_98324_s, 0);
    SW_Aggregate_TD_6862075(tbl_JOIN_INNER_TD_7914670_output, tbl_Aggregate_TD_6862075_output);
    gettimeofday(&tv_r_Aggregate_6_98324_e, 0);

    struct timeval tv_r_Filter_6_447752_s, tv_r_Filter_6_447752_e;
    gettimeofday(&tv_r_Filter_6_447752_s, 0);
    SW_Filter_TD_6543927(tbl_Aggregate_TD_7612001_output, tbl_Filter_TD_6543927_output);
    gettimeofday(&tv_r_Filter_6_447752_e, 0);

    struct timeval tv_r_JOIN_INNER_5_878710_s, tv_r_JOIN_INNER_5_878710_e;
    gettimeofday(&tv_r_JOIN_INNER_5_878710_s, 0);
    SW_JOIN_INNER_TD_5898578(tbl_JOIN_INNER_TD_6987382_output, tbl_Filter_TD_6198075_output, tbl_JOIN_INNER_TD_5898578_output);
    gettimeofday(&tv_r_JOIN_INNER_5_878710_e, 0);

    struct timeval tv_r_Project_5_771297_s, tv_r_Project_5_771297_e;
    gettimeofday(&tv_r_Project_5_771297_s, 0);
    SW_Project_TD_5973542(tbl_Filter_TD_6122861_output, tbl_Project_TD_5973542_output);
    gettimeofday(&tv_r_Project_5_771297_e, 0);

    struct timeval tv_r_JOIN_INNER_5_691826_s, tv_r_JOIN_INNER_5_691826_e;
    gettimeofday(&tv_r_JOIN_INNER_5_691826_s, 0);
    SW_JOIN_INNER_TD_5209094(tbl_Filter_TD_6543927_output, tbl_Aggregate_TD_6862075_output, tbl_JOIN_INNER_TD_5209094_output);
    gettimeofday(&tv_r_JOIN_INNER_5_691826_e, 0);

    struct timeval tv_r_Aggregate_4_858164_s, tv_r_Aggregate_4_858164_e;
    gettimeofday(&tv_r_Aggregate_4_858164_s, 0);
    SW_Aggregate_TD_4949259(tbl_JOIN_INNER_TD_5898578_output, tbl_Aggregate_TD_4949259_output);
    gettimeofday(&tv_r_Aggregate_4_858164_e, 0);

    struct timeval tv_r_JOIN_INNER_4_854641_s, tv_r_JOIN_INNER_4_854641_e;
    gettimeofday(&tv_r_JOIN_INNER_4_854641_s, 0);
    SW_JOIN_INNER_TD_4124713(tbl_JOIN_INNER_TD_5209094_output, tbl_Project_TD_5973542_output, tbl_JOIN_INNER_TD_4124713_output);
    gettimeofday(&tv_r_JOIN_INNER_4_854641_e, 0);

    struct timeval tv_r_JOIN_INNER_3_907176_s, tv_r_JOIN_INNER_3_907176_e;
    gettimeofday(&tv_r_JOIN_INNER_3_907176_s, 0);
    SW_JOIN_INNER_TD_3702038(tbl_JOIN_INNER_TD_4124713_output, tbl_Aggregate_TD_4949259_output, tbl_JOIN_INNER_TD_3702038_output);
    gettimeofday(&tv_r_JOIN_INNER_3_907176_e, 0);

    struct timeval tv_r_Sort_2_515660_s, tv_r_Sort_2_515660_e;
    gettimeofday(&tv_r_Sort_2_515660_s, 0);
    SW_Sort_TD_2666397(tbl_JOIN_INNER_TD_3702038_output, tbl_Sort_TD_2666397_output);
    gettimeofday(&tv_r_Sort_2_515660_e, 0);

    struct timeval tv_r_LocalLimit_1_932386_s, tv_r_LocalLimit_1_932386_e;
    gettimeofday(&tv_r_LocalLimit_1_932386_s, 0);
    SW_LocalLimit_TD_1483626(tbl_Sort_TD_2666397_output, tbl_LocalLimit_TD_1483626_output);
    gettimeofday(&tv_r_LocalLimit_1_932386_e, 0);

    struct timeval tv_r_GlobalLimit_0_149193_s, tv_r_GlobalLimit_0_149193_e;
    gettimeofday(&tv_r_GlobalLimit_0_149193_s, 0);
    SW_GlobalLimit_TD_0529391(tbl_LocalLimit_TD_1483626_output, tbl_GlobalLimit_TD_0529391_output);
    gettimeofday(&tv_r_GlobalLimit_0_149193_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_573237_s, &tv_r_Filter_10_573237_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11447356_input: " << tbl_SerializeFromObject_TD_11447356_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_865599_s, &tv_r_Filter_10_865599_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11666360_input: " << tbl_SerializeFromObject_TD_11666360_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_991239_s, &tv_r_Filter_10_991239_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11927657_input: " << tbl_SerializeFromObject_TD_11927657_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_268764_s, &tv_r_Filter_10_268764_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11587509_input: " << tbl_SerializeFromObject_TD_11587509_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_545278_s, &tv_r_Filter_9_545278_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10655370_input: " << tbl_SerializeFromObject_TD_10655370_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_201508_s, &tv_r_JOIN_INNER_9_201508_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10555553_output: " << tbl_Filter_TD_10555553_output.getNumRow() << " " << "tbl_Filter_TD_10523569_output: " << tbl_Filter_TD_10523569_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_371067_s, &tv_r_Filter_9_371067_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10630342_input: " << tbl_SerializeFromObject_TD_10630342_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_804425_s, &tv_r_Filter_9_804425_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10373979_input: " << tbl_SerializeFromObject_TD_10373979_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_428293_s, &tv_r_Filter_9_428293_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10490387_input: " << tbl_SerializeFromObject_TD_10490387_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_603283_s, &tv_r_JOIN_INNER_9_603283_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10841932_output: " << tbl_Filter_TD_10841932_output.getNumRow() << " " << "tbl_Filter_TD_10631613_output: " << tbl_Filter_TD_10631613_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_395995_s, &tv_r_JOIN_INNER_8_395995_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9984531_output: " << tbl_JOIN_INNER_TD_9984531_output.getNumRow() << " " << "tbl_Filter_TD_9388926_output: " << tbl_Filter_TD_9388926_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_247733_s, &tv_r_Filter_8_247733_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9161498_input: " << tbl_SerializeFromObject_TD_9161498_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_938591_s, &tv_r_JOIN_INNER_8_938591_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9794804_output: " << tbl_Filter_TD_9794804_output.getNumRow() << " " << "tbl_Filter_TD_9947129_output: " << tbl_Filter_TD_9947129_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_540131_s, &tv_r_JOIN_INNER_8_540131_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9915620_output: " << tbl_JOIN_INNER_TD_9915620_output.getNumRow() << " " << "tbl_Filter_TD_9937168_output: " << tbl_Filter_TD_9937168_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_163227_s, &tv_r_Filter_7_163227_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8829642_input: " << tbl_SerializeFromObject_TD_8829642_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_923969_s, &tv_r_Filter_7_923969_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8236414_input: " << tbl_SerializeFromObject_TD_8236414_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_7: " << tvdiff(&tv_r_Aggregate_7_602308_s, &tv_r_Aggregate_7_602308_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8457000_output: " << tbl_JOIN_INNER_TD_8457000_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_90078_s, &tv_r_JOIN_INNER_7_90078_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8637088_output: " << tbl_JOIN_INNER_TD_8637088_output.getNumRow() << " " << "tbl_Filter_TD_8670784_output: " << tbl_Filter_TD_8670784_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_7: " << tvdiff(&tv_r_Aggregate_7_493060_s, &tv_r_Aggregate_7_493060_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8128046_output: " << tbl_JOIN_INNER_TD_8128046_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_812631_s, &tv_r_Filter_6_812631_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7975189_input: " << tbl_SerializeFromObject_TD_7975189_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_755679_s, &tv_r_JOIN_INNER_6_755679_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_7606581_output: " << tbl_Filter_TD_7606581_output.getNumRow() << " " << "tbl_Filter_TD_7674026_output: " << tbl_Filter_TD_7674026_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_577026_s, &tv_r_Filter_6_577026_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_7135176_output: " << tbl_Aggregate_TD_7135176_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_6: " << tvdiff(&tv_r_Aggregate_6_98324_s, &tv_r_Aggregate_6_98324_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7914670_output: " << tbl_JOIN_INNER_TD_7914670_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_447752_s, &tv_r_Filter_6_447752_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_7612001_output: " << tbl_Aggregate_TD_7612001_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_878710_s, &tv_r_JOIN_INNER_5_878710_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6987382_output: " << tbl_JOIN_INNER_TD_6987382_output.getNumRow() << " " << "tbl_Filter_TD_6198075_output: " << tbl_Filter_TD_6198075_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_5: " << tvdiff(&tv_r_Project_5_771297_s, &tv_r_Project_5_771297_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6122861_output: " << tbl_Filter_TD_6122861_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_691826_s, &tv_r_JOIN_INNER_5_691826_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6543927_output: " << tbl_Filter_TD_6543927_output.getNumRow() << " " << "tbl_Aggregate_TD_6862075_output: " << tbl_Aggregate_TD_6862075_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_4: " << tvdiff(&tv_r_Aggregate_4_858164_s, &tv_r_Aggregate_4_858164_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5898578_output: " << tbl_JOIN_INNER_TD_5898578_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_854641_s, &tv_r_JOIN_INNER_4_854641_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5209094_output: " << tbl_JOIN_INNER_TD_5209094_output.getNumRow() << " " << "tbl_Project_TD_5973542_output: " << tbl_Project_TD_5973542_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_907176_s, &tv_r_JOIN_INNER_3_907176_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4124713_output: " << tbl_JOIN_INNER_TD_4124713_output.getNumRow() << " " << "tbl_Aggregate_TD_4949259_output: " << tbl_Aggregate_TD_4949259_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_515660_s, &tv_r_Sort_2_515660_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3702038_output: " << tbl_JOIN_INNER_TD_3702038_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_932386_s, &tv_r_LocalLimit_1_932386_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2666397_output: " << tbl_Sort_TD_2666397_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_149193_s, &tv_r_GlobalLimit_0_149193_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1483626_output: " << tbl_LocalLimit_TD_1483626_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 3.6967118 * 1000 << "ms" << std::endl; 
    return 0; 
}
