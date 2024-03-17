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

#include "cfgFunc_q11.hpp" 
#include "q11.hpp" 

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
    std::cout << "NOTE:running query #11\n."; 
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
    Table tbl_GlobalLimit_TD_0181662_output("tbl_GlobalLimit_TD_0181662_output", 6100000, 4, "");
    tbl_GlobalLimit_TD_0181662_output.allocateHost();
    Table tbl_LocalLimit_TD_1243487_output("tbl_LocalLimit_TD_1243487_output", 6100000, 4, "");
    tbl_LocalLimit_TD_1243487_output.allocateHost();
    Table tbl_Sort_TD_2445395_output("tbl_Sort_TD_2445395_output", 6100000, 4, "");
    tbl_Sort_TD_2445395_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3907935_output("tbl_JOIN_INNER_TD_3907935_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_3907935_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4534120_output("tbl_JOIN_INNER_TD_4534120_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_4534120_output.allocateHost();
    Table tbl_Aggregate_TD_4905961_output("tbl_Aggregate_TD_4905961_output", 6100000, 2, "");
    tbl_Aggregate_TD_4905961_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5762133_output("tbl_JOIN_INNER_TD_5762133_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_5762133_output.allocateHost();
    Table tbl_Project_TD_5144516_output("tbl_Project_TD_5144516_output", 6100000, 2, "");
    tbl_Project_TD_5144516_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5887108_output("tbl_JOIN_INNER_TD_5887108_output", 6100000, 10, "");
    tbl_JOIN_INNER_TD_5887108_output.allocateHost();
    Table tbl_Filter_TD_6520850_output("tbl_Filter_TD_6520850_output", 6100000, 2, "");
    tbl_Filter_TD_6520850_output.allocateHost();
    Table tbl_Aggregate_TD_6923041_output("tbl_Aggregate_TD_6923041_output", 6100000, 5, "");
    tbl_Aggregate_TD_6923041_output.allocateHost();
    Table tbl_Filter_TD_636853_output("tbl_Filter_TD_636853_output", 6100000, 2, "");
    tbl_Filter_TD_636853_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6611510_output("tbl_JOIN_INNER_TD_6611510_output", 6100000, 10, "");
    tbl_JOIN_INNER_TD_6611510_output.allocateHost();
    Table tbl_Filter_TD_6644775_output("tbl_Filter_TD_6644775_output", 6100000, 2, "");
    tbl_Filter_TD_6644775_output.allocateHost();
    Table tbl_Aggregate_TD_7565087_output("tbl_Aggregate_TD_7565087_output", 6100000, 2, "");
    tbl_Aggregate_TD_7565087_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7619669_output("tbl_JOIN_INNER_TD_7619669_output", 6100000, 10, "");
    tbl_JOIN_INNER_TD_7619669_output.allocateHost();
    Table tbl_Aggregate_TD_7692608_output("tbl_Aggregate_TD_7692608_output", 6100000, 2, "");
    tbl_Aggregate_TD_7692608_output.allocateHost();
    Table tbl_Filter_TD_7965326_output("tbl_Filter_TD_7965326_output", 6100000, 8, "");
    tbl_Filter_TD_7965326_output.allocateHost();
    Table tbl_Filter_TD_7147492_output("tbl_Filter_TD_7147492_output", 6100000, 4, "");
    tbl_Filter_TD_7147492_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7697996_input;
    tbl_SerializeFromObject_TD_7697996_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7697996_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_7697996_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_7697996_input.allocateHost();
    tbl_SerializeFromObject_TD_7697996_input.loadHost();
    Table tbl_JOIN_INNER_TD_8661755_output("tbl_JOIN_INNER_TD_8661755_output", 6100000, 10, "");
    tbl_JOIN_INNER_TD_8661755_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8588445_output("tbl_JOIN_INNER_TD_8588445_output", 6100000, 10, "");
    tbl_JOIN_INNER_TD_8588445_output.allocateHost();
    Table tbl_Filter_TD_8239347_output("tbl_Filter_TD_8239347_output", 6100000, 2, "");
    tbl_Filter_TD_8239347_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8385547_output("tbl_JOIN_INNER_TD_8385547_output", 6100000, 10, "");
    tbl_JOIN_INNER_TD_8385547_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8391444_input;
    tbl_SerializeFromObject_TD_8391444_input = Table("customer", customer_n, 8, in_dir, "orc");
    tbl_SerializeFromObject_TD_8391444_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_8391444_input.addCol("c_customer_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8391444_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8391444_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8391444_input.addCol("c_preferred_cust_flag", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8391444_input.addCol("c_birth_country", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8391444_input.addCol("c_login", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8391444_input.addCol("c_email_address", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8391444_input.allocateHost();
    tbl_SerializeFromObject_TD_8391444_input.loadHost();
    Table tbl_SerializeFromObject_TD_8163070_input;
    tbl_SerializeFromObject_TD_8163070_input = Table("web_sales", web_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_8163070_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_8163070_input.addCol("ws_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_8163070_input.addCol("ws_ext_discount_amt", 4);
    tbl_SerializeFromObject_TD_8163070_input.addCol("ws_ext_list_price", 4);
    tbl_SerializeFromObject_TD_8163070_input.allocateHost();
    tbl_SerializeFromObject_TD_8163070_input.loadHost();
    Table tbl_JOIN_INNER_TD_9611703_output("tbl_JOIN_INNER_TD_9611703_output", 6100000, 10, "");
    tbl_JOIN_INNER_TD_9611703_output.allocateHost();
    Table tbl_Filter_TD_9254929_output("tbl_Filter_TD_9254929_output", 6100000, 2, "");
    tbl_Filter_TD_9254929_output.allocateHost();
    Table tbl_Filter_TD_9366196_output("tbl_Filter_TD_9366196_output", 6100000, 8, "");
    tbl_Filter_TD_9366196_output.allocateHost();
    Table tbl_Filter_TD_9426441_output("tbl_Filter_TD_9426441_output", 6100000, 4, "");
    tbl_Filter_TD_9426441_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9552601_input;
    tbl_SerializeFromObject_TD_9552601_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9552601_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_9552601_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_9552601_input.allocateHost();
    tbl_SerializeFromObject_TD_9552601_input.loadHost();
    Table tbl_JOIN_INNER_TD_9216480_output("tbl_JOIN_INNER_TD_9216480_output", 6100000, 10, "");
    tbl_JOIN_INNER_TD_9216480_output.allocateHost();
    Table tbl_Filter_TD_9817279_output("tbl_Filter_TD_9817279_output", 6100000, 2, "");
    tbl_Filter_TD_9817279_output.allocateHost();
    Table tbl_Filter_TD_10622175_output("tbl_Filter_TD_10622175_output", 6100000, 8, "");
    tbl_Filter_TD_10622175_output.allocateHost();
    Table tbl_Filter_TD_10519755_output("tbl_Filter_TD_10519755_output", 6100000, 4, "");
    tbl_Filter_TD_10519755_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10905710_input;
    tbl_SerializeFromObject_TD_10905710_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10905710_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10905710_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10905710_input.allocateHost();
    tbl_SerializeFromObject_TD_10905710_input.loadHost();
    Table tbl_SerializeFromObject_TD_10366823_input;
    tbl_SerializeFromObject_TD_10366823_input = Table("customer", customer_n, 8, in_dir, "orc");
    tbl_SerializeFromObject_TD_10366823_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_10366823_input.addCol("c_customer_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10366823_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10366823_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10366823_input.addCol("c_preferred_cust_flag", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10366823_input.addCol("c_birth_country", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10366823_input.addCol("c_login", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10366823_input.addCol("c_email_address", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10366823_input.allocateHost();
    tbl_SerializeFromObject_TD_10366823_input.loadHost();
    Table tbl_SerializeFromObject_TD_10409304_input;
    tbl_SerializeFromObject_TD_10409304_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_10409304_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10409304_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_10409304_input.addCol("ss_ext_discount_amt", 4);
    tbl_SerializeFromObject_TD_10409304_input.addCol("ss_ext_list_price", 4);
    tbl_SerializeFromObject_TD_10409304_input.allocateHost();
    tbl_SerializeFromObject_TD_10409304_input.loadHost();
    Table tbl_Filter_TD_10973120_output("tbl_Filter_TD_10973120_output", 6100000, 8, "");
    tbl_Filter_TD_10973120_output.allocateHost();
    Table tbl_Filter_TD_10545828_output("tbl_Filter_TD_10545828_output", 6100000, 4, "");
    tbl_Filter_TD_10545828_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10382272_input;
    tbl_SerializeFromObject_TD_10382272_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10382272_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10382272_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10382272_input.allocateHost();
    tbl_SerializeFromObject_TD_10382272_input.loadHost();
    Table tbl_SerializeFromObject_TD_11930203_input;
    tbl_SerializeFromObject_TD_11930203_input = Table("customer", customer_n, 8, in_dir, "orc");
    tbl_SerializeFromObject_TD_11930203_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_11930203_input.addCol("c_customer_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11930203_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11930203_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11930203_input.addCol("c_preferred_cust_flag", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11930203_input.addCol("c_birth_country", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11930203_input.addCol("c_login", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11930203_input.addCol("c_email_address", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11930203_input.allocateHost();
    tbl_SerializeFromObject_TD_11930203_input.loadHost();
    Table tbl_SerializeFromObject_TD_1155822_input;
    tbl_SerializeFromObject_TD_1155822_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_1155822_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_1155822_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_1155822_input.addCol("ss_ext_discount_amt", 4);
    tbl_SerializeFromObject_TD_1155822_input.addCol("ss_ext_list_price", 4);
    tbl_SerializeFromObject_TD_1155822_input.allocateHost();
    tbl_SerializeFromObject_TD_1155822_input.loadHost();
    Table tbl_SerializeFromObject_TD_11986773_input;
    tbl_SerializeFromObject_TD_11986773_input = Table("customer", customer_n, 8, in_dir, "orc");
    tbl_SerializeFromObject_TD_11986773_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_11986773_input.addCol("c_customer_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11986773_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11986773_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11986773_input.addCol("c_preferred_cust_flag", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11986773_input.addCol("c_birth_country", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11986773_input.addCol("c_login", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11986773_input.addCol("c_email_address", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11986773_input.allocateHost();
    tbl_SerializeFromObject_TD_11986773_input.loadHost();
    Table tbl_SerializeFromObject_TD_11744465_input;
    tbl_SerializeFromObject_TD_11744465_input = Table("web_sales", web_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_11744465_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_11744465_input.addCol("ws_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_11744465_input.addCol("ws_ext_discount_amt", 4);
    tbl_SerializeFromObject_TD_11744465_input.addCol("ws_ext_list_price", 4);
    tbl_SerializeFromObject_TD_11744465_input.allocateHost();
    tbl_SerializeFromObject_TD_11744465_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    std::cout << std::endl; 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_10_485548_s, tv_r_Filter_10_485548_e;
    gettimeofday(&tv_r_Filter_10_485548_s, 0);
    SW_Filter_TD_10545828(tbl_SerializeFromObject_TD_11744465_input, tbl_Filter_TD_10545828_output);
    gettimeofday(&tv_r_Filter_10_485548_e, 0);

    struct timeval tv_r_Filter_10_382278_s, tv_r_Filter_10_382278_e;
    gettimeofday(&tv_r_Filter_10_382278_s, 0);
    SW_Filter_TD_10973120(tbl_SerializeFromObject_TD_11986773_input, tbl_Filter_TD_10973120_output);
    gettimeofday(&tv_r_Filter_10_382278_e, 0);

    struct timeval tv_r_Filter_10_176234_s, tv_r_Filter_10_176234_e;
    gettimeofday(&tv_r_Filter_10_176234_s, 0);
    SW_Filter_TD_10519755(tbl_SerializeFromObject_TD_1155822_input, tbl_Filter_TD_10519755_output);
    gettimeofday(&tv_r_Filter_10_176234_e, 0);

    struct timeval tv_r_Filter_10_723299_s, tv_r_Filter_10_723299_e;
    gettimeofday(&tv_r_Filter_10_723299_s, 0);
    SW_Filter_TD_10622175(tbl_SerializeFromObject_TD_11930203_input, tbl_Filter_TD_10622175_output);
    gettimeofday(&tv_r_Filter_10_723299_e, 0);

    struct timeval tv_r_Filter_9_207536_s, tv_r_Filter_9_207536_e;
    gettimeofday(&tv_r_Filter_9_207536_s, 0);
    SW_Filter_TD_9817279(tbl_SerializeFromObject_TD_10382272_input, tbl_Filter_TD_9817279_output);
    gettimeofday(&tv_r_Filter_9_207536_e, 0);

    struct timeval tv_r_JOIN_INNER_9_601135_s, tv_r_JOIN_INNER_9_601135_e;
    gettimeofday(&tv_r_JOIN_INNER_9_601135_s, 0);
    SW_JOIN_INNER_TD_9216480(tbl_Filter_TD_10973120_output, tbl_Filter_TD_10545828_output, tbl_JOIN_INNER_TD_9216480_output);
    gettimeofday(&tv_r_JOIN_INNER_9_601135_e, 0);

    struct timeval tv_r_Filter_9_286191_s, tv_r_Filter_9_286191_e;
    gettimeofday(&tv_r_Filter_9_286191_s, 0);
    SW_Filter_TD_9426441(tbl_SerializeFromObject_TD_10409304_input, tbl_Filter_TD_9426441_output);
    gettimeofday(&tv_r_Filter_9_286191_e, 0);

    struct timeval tv_r_Filter_9_525801_s, tv_r_Filter_9_525801_e;
    gettimeofday(&tv_r_Filter_9_525801_s, 0);
    SW_Filter_TD_9366196(tbl_SerializeFromObject_TD_10366823_input, tbl_Filter_TD_9366196_output);
    gettimeofday(&tv_r_Filter_9_525801_e, 0);

    struct timeval tv_r_Filter_9_895998_s, tv_r_Filter_9_895998_e;
    gettimeofday(&tv_r_Filter_9_895998_s, 0);
    SW_Filter_TD_9254929(tbl_SerializeFromObject_TD_10905710_input, tbl_Filter_TD_9254929_output);
    gettimeofday(&tv_r_Filter_9_895998_e, 0);

    struct timeval tv_r_JOIN_INNER_9_760901_s, tv_r_JOIN_INNER_9_760901_e;
    gettimeofday(&tv_r_JOIN_INNER_9_760901_s, 0);
    SW_JOIN_INNER_TD_9611703(tbl_Filter_TD_10622175_output, tbl_Filter_TD_10519755_output, tbl_JOIN_INNER_TD_9611703_output);
    gettimeofday(&tv_r_JOIN_INNER_9_760901_e, 0);

    struct timeval tv_r_JOIN_INNER_8_46364_s, tv_r_JOIN_INNER_8_46364_e;
    gettimeofday(&tv_r_JOIN_INNER_8_46364_s, 0);
    SW_JOIN_INNER_TD_8385547(tbl_JOIN_INNER_TD_9216480_output, tbl_Filter_TD_9817279_output, tbl_JOIN_INNER_TD_8385547_output);
    gettimeofday(&tv_r_JOIN_INNER_8_46364_e, 0);

    struct timeval tv_r_Filter_8_2352_s, tv_r_Filter_8_2352_e;
    gettimeofday(&tv_r_Filter_8_2352_s, 0);
    SW_Filter_TD_8239347(tbl_SerializeFromObject_TD_9552601_input, tbl_Filter_TD_8239347_output);
    gettimeofday(&tv_r_Filter_8_2352_e, 0);

    struct timeval tv_r_JOIN_INNER_8_429860_s, tv_r_JOIN_INNER_8_429860_e;
    gettimeofday(&tv_r_JOIN_INNER_8_429860_s, 0);
    SW_JOIN_INNER_TD_8588445(tbl_Filter_TD_9366196_output, tbl_Filter_TD_9426441_output, tbl_JOIN_INNER_TD_8588445_output);
    gettimeofday(&tv_r_JOIN_INNER_8_429860_e, 0);

    struct timeval tv_r_JOIN_INNER_8_486397_s, tv_r_JOIN_INNER_8_486397_e;
    gettimeofday(&tv_r_JOIN_INNER_8_486397_s, 0);
    SW_JOIN_INNER_TD_8661755(tbl_JOIN_INNER_TD_9611703_output, tbl_Filter_TD_9254929_output, tbl_JOIN_INNER_TD_8661755_output);
    gettimeofday(&tv_r_JOIN_INNER_8_486397_e, 0);

    struct timeval tv_r_Filter_7_591992_s, tv_r_Filter_7_591992_e;
    gettimeofday(&tv_r_Filter_7_591992_s, 0);
    SW_Filter_TD_7147492(tbl_SerializeFromObject_TD_8163070_input, tbl_Filter_TD_7147492_output);
    gettimeofday(&tv_r_Filter_7_591992_e, 0);

    struct timeval tv_r_Filter_7_7569_s, tv_r_Filter_7_7569_e;
    gettimeofday(&tv_r_Filter_7_7569_s, 0);
    SW_Filter_TD_7965326(tbl_SerializeFromObject_TD_8391444_input, tbl_Filter_TD_7965326_output);
    gettimeofday(&tv_r_Filter_7_7569_e, 0);

    struct timeval tv_r_Aggregate_7_412588_s, tv_r_Aggregate_7_412588_e;
    gettimeofday(&tv_r_Aggregate_7_412588_s, 0);
    SW_Aggregate_TD_7692608(tbl_JOIN_INNER_TD_8385547_output, tbl_Aggregate_TD_7692608_output);
    gettimeofday(&tv_r_Aggregate_7_412588_e, 0);

    struct timeval tv_r_JOIN_INNER_7_938789_s, tv_r_JOIN_INNER_7_938789_e;
    gettimeofday(&tv_r_JOIN_INNER_7_938789_s, 0);
    SW_JOIN_INNER_TD_7619669(tbl_JOIN_INNER_TD_8588445_output, tbl_Filter_TD_8239347_output, tbl_JOIN_INNER_TD_7619669_output);
    gettimeofday(&tv_r_JOIN_INNER_7_938789_e, 0);

    struct timeval tv_r_Aggregate_7_377008_s, tv_r_Aggregate_7_377008_e;
    gettimeofday(&tv_r_Aggregate_7_377008_s, 0);
    SW_Aggregate_TD_7565087(tbl_JOIN_INNER_TD_8661755_output, tbl_Aggregate_TD_7565087_output);
    gettimeofday(&tv_r_Aggregate_7_377008_e, 0);

    struct timeval tv_r_Filter_6_516711_s, tv_r_Filter_6_516711_e;
    gettimeofday(&tv_r_Filter_6_516711_s, 0);
    SW_Filter_TD_6644775(tbl_SerializeFromObject_TD_7697996_input, tbl_Filter_TD_6644775_output);
    gettimeofday(&tv_r_Filter_6_516711_e, 0);

    struct timeval tv_r_JOIN_INNER_6_190334_s, tv_r_JOIN_INNER_6_190334_e;
    gettimeofday(&tv_r_JOIN_INNER_6_190334_s, 0);
    SW_JOIN_INNER_TD_6611510(tbl_Filter_TD_7965326_output, tbl_Filter_TD_7147492_output, tbl_JOIN_INNER_TD_6611510_output);
    gettimeofday(&tv_r_JOIN_INNER_6_190334_e, 0);

    struct timeval tv_r_Filter_6_386912_s, tv_r_Filter_6_386912_e;
    gettimeofday(&tv_r_Filter_6_386912_s, 0);
    SW_Filter_TD_636853(tbl_Aggregate_TD_7692608_output, tbl_Filter_TD_636853_output);
    gettimeofday(&tv_r_Filter_6_386912_e, 0);

    struct timeval tv_r_Aggregate_6_709904_s, tv_r_Aggregate_6_709904_e;
    gettimeofday(&tv_r_Aggregate_6_709904_s, 0);
    SW_Aggregate_TD_6923041(tbl_JOIN_INNER_TD_7619669_output, tbl_Aggregate_TD_6923041_output);
    gettimeofday(&tv_r_Aggregate_6_709904_e, 0);

    struct timeval tv_r_Filter_6_272475_s, tv_r_Filter_6_272475_e;
    gettimeofday(&tv_r_Filter_6_272475_s, 0);
    SW_Filter_TD_6520850(tbl_Aggregate_TD_7565087_output, tbl_Filter_TD_6520850_output);
    gettimeofday(&tv_r_Filter_6_272475_e, 0);

    struct timeval tv_r_JOIN_INNER_5_113699_s, tv_r_JOIN_INNER_5_113699_e;
    gettimeofday(&tv_r_JOIN_INNER_5_113699_s, 0);
    SW_JOIN_INNER_TD_5887108(tbl_JOIN_INNER_TD_6611510_output, tbl_Filter_TD_6644775_output, tbl_JOIN_INNER_TD_5887108_output);
    gettimeofday(&tv_r_JOIN_INNER_5_113699_e, 0);

    struct timeval tv_r_Project_5_110078_s, tv_r_Project_5_110078_e;
    gettimeofday(&tv_r_Project_5_110078_s, 0);
    SW_Project_TD_5144516(tbl_Filter_TD_636853_output, tbl_Project_TD_5144516_output);
    gettimeofday(&tv_r_Project_5_110078_e, 0);

    struct timeval tv_r_JOIN_INNER_5_841997_s, tv_r_JOIN_INNER_5_841997_e;
    gettimeofday(&tv_r_JOIN_INNER_5_841997_s, 0);
    SW_JOIN_INNER_TD_5762133(tbl_Filter_TD_6520850_output, tbl_Aggregate_TD_6923041_output, tbl_JOIN_INNER_TD_5762133_output);
    gettimeofday(&tv_r_JOIN_INNER_5_841997_e, 0);

    struct timeval tv_r_Aggregate_4_369803_s, tv_r_Aggregate_4_369803_e;
    gettimeofday(&tv_r_Aggregate_4_369803_s, 0);
    SW_Aggregate_TD_4905961(tbl_JOIN_INNER_TD_5887108_output, tbl_Aggregate_TD_4905961_output);
    gettimeofday(&tv_r_Aggregate_4_369803_e, 0);

    struct timeval tv_r_JOIN_INNER_4_210212_s, tv_r_JOIN_INNER_4_210212_e;
    gettimeofday(&tv_r_JOIN_INNER_4_210212_s, 0);
    SW_JOIN_INNER_TD_4534120(tbl_JOIN_INNER_TD_5762133_output, tbl_Project_TD_5144516_output, tbl_JOIN_INNER_TD_4534120_output);
    gettimeofday(&tv_r_JOIN_INNER_4_210212_e, 0);

    struct timeval tv_r_JOIN_INNER_3_877687_s, tv_r_JOIN_INNER_3_877687_e;
    gettimeofday(&tv_r_JOIN_INNER_3_877687_s, 0);
    SW_JOIN_INNER_TD_3907935(tbl_JOIN_INNER_TD_4534120_output, tbl_Aggregate_TD_4905961_output, tbl_JOIN_INNER_TD_3907935_output);
    gettimeofday(&tv_r_JOIN_INNER_3_877687_e, 0);

    struct timeval tv_r_Sort_2_453887_s, tv_r_Sort_2_453887_e;
    gettimeofday(&tv_r_Sort_2_453887_s, 0);
    SW_Sort_TD_2445395(tbl_JOIN_INNER_TD_3907935_output, tbl_Sort_TD_2445395_output);
    gettimeofday(&tv_r_Sort_2_453887_e, 0);

    struct timeval tv_r_LocalLimit_1_15063_s, tv_r_LocalLimit_1_15063_e;
    gettimeofday(&tv_r_LocalLimit_1_15063_s, 0);
    SW_LocalLimit_TD_1243487(tbl_Sort_TD_2445395_output, tbl_LocalLimit_TD_1243487_output);
    gettimeofday(&tv_r_LocalLimit_1_15063_e, 0);

    struct timeval tv_r_GlobalLimit_0_739089_s, tv_r_GlobalLimit_0_739089_e;
    gettimeofday(&tv_r_GlobalLimit_0_739089_s, 0);
    SW_GlobalLimit_TD_0181662(tbl_LocalLimit_TD_1243487_output, tbl_GlobalLimit_TD_0181662_output);
    gettimeofday(&tv_r_GlobalLimit_0_739089_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_485548_s, &tv_r_Filter_10_485548_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11744465_input: " << tbl_SerializeFromObject_TD_11744465_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_382278_s, &tv_r_Filter_10_382278_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11986773_input: " << tbl_SerializeFromObject_TD_11986773_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_176234_s, &tv_r_Filter_10_176234_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1155822_input: " << tbl_SerializeFromObject_TD_1155822_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_723299_s, &tv_r_Filter_10_723299_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11930203_input: " << tbl_SerializeFromObject_TD_11930203_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_207536_s, &tv_r_Filter_9_207536_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10382272_input: " << tbl_SerializeFromObject_TD_10382272_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_601135_s, &tv_r_JOIN_INNER_9_601135_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10973120_output: " << tbl_Filter_TD_10973120_output.getNumRow() << " " << "tbl_Filter_TD_10545828_output: " << tbl_Filter_TD_10545828_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_286191_s, &tv_r_Filter_9_286191_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10409304_input: " << tbl_SerializeFromObject_TD_10409304_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_525801_s, &tv_r_Filter_9_525801_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10366823_input: " << tbl_SerializeFromObject_TD_10366823_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_895998_s, &tv_r_Filter_9_895998_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10905710_input: " << tbl_SerializeFromObject_TD_10905710_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_760901_s, &tv_r_JOIN_INNER_9_760901_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10622175_output: " << tbl_Filter_TD_10622175_output.getNumRow() << " " << "tbl_Filter_TD_10519755_output: " << tbl_Filter_TD_10519755_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_46364_s, &tv_r_JOIN_INNER_8_46364_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9216480_output: " << tbl_JOIN_INNER_TD_9216480_output.getNumRow() << " " << "tbl_Filter_TD_9817279_output: " << tbl_Filter_TD_9817279_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_2352_s, &tv_r_Filter_8_2352_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9552601_input: " << tbl_SerializeFromObject_TD_9552601_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_429860_s, &tv_r_JOIN_INNER_8_429860_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9366196_output: " << tbl_Filter_TD_9366196_output.getNumRow() << " " << "tbl_Filter_TD_9426441_output: " << tbl_Filter_TD_9426441_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_486397_s, &tv_r_JOIN_INNER_8_486397_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9611703_output: " << tbl_JOIN_INNER_TD_9611703_output.getNumRow() << " " << "tbl_Filter_TD_9254929_output: " << tbl_Filter_TD_9254929_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_591992_s, &tv_r_Filter_7_591992_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8163070_input: " << tbl_SerializeFromObject_TD_8163070_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_7569_s, &tv_r_Filter_7_7569_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8391444_input: " << tbl_SerializeFromObject_TD_8391444_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_7: " << tvdiff(&tv_r_Aggregate_7_412588_s, &tv_r_Aggregate_7_412588_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8385547_output: " << tbl_JOIN_INNER_TD_8385547_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_938789_s, &tv_r_JOIN_INNER_7_938789_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8588445_output: " << tbl_JOIN_INNER_TD_8588445_output.getNumRow() << " " << "tbl_Filter_TD_8239347_output: " << tbl_Filter_TD_8239347_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_7: " << tvdiff(&tv_r_Aggregate_7_377008_s, &tv_r_Aggregate_7_377008_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8661755_output: " << tbl_JOIN_INNER_TD_8661755_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_516711_s, &tv_r_Filter_6_516711_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7697996_input: " << tbl_SerializeFromObject_TD_7697996_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_190334_s, &tv_r_JOIN_INNER_6_190334_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_7965326_output: " << tbl_Filter_TD_7965326_output.getNumRow() << " " << "tbl_Filter_TD_7147492_output: " << tbl_Filter_TD_7147492_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_386912_s, &tv_r_Filter_6_386912_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_7692608_output: " << tbl_Aggregate_TD_7692608_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_6: " << tvdiff(&tv_r_Aggregate_6_709904_s, &tv_r_Aggregate_6_709904_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7619669_output: " << tbl_JOIN_INNER_TD_7619669_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_272475_s, &tv_r_Filter_6_272475_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_7565087_output: " << tbl_Aggregate_TD_7565087_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_113699_s, &tv_r_JOIN_INNER_5_113699_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6611510_output: " << tbl_JOIN_INNER_TD_6611510_output.getNumRow() << " " << "tbl_Filter_TD_6644775_output: " << tbl_Filter_TD_6644775_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_5: " << tvdiff(&tv_r_Project_5_110078_s, &tv_r_Project_5_110078_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_636853_output: " << tbl_Filter_TD_636853_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_841997_s, &tv_r_JOIN_INNER_5_841997_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6520850_output: " << tbl_Filter_TD_6520850_output.getNumRow() << " " << "tbl_Aggregate_TD_6923041_output: " << tbl_Aggregate_TD_6923041_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_4: " << tvdiff(&tv_r_Aggregate_4_369803_s, &tv_r_Aggregate_4_369803_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5887108_output: " << tbl_JOIN_INNER_TD_5887108_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_210212_s, &tv_r_JOIN_INNER_4_210212_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5762133_output: " << tbl_JOIN_INNER_TD_5762133_output.getNumRow() << " " << "tbl_Project_TD_5144516_output: " << tbl_Project_TD_5144516_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_877687_s, &tv_r_JOIN_INNER_3_877687_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4534120_output: " << tbl_JOIN_INNER_TD_4534120_output.getNumRow() << " " << "tbl_Aggregate_TD_4905961_output: " << tbl_Aggregate_TD_4905961_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_453887_s, &tv_r_Sort_2_453887_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3907935_output: " << tbl_JOIN_INNER_TD_3907935_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_15063_s, &tv_r_LocalLimit_1_15063_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2445395_output: " << tbl_Sort_TD_2445395_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_739089_s, &tv_r_GlobalLimit_0_739089_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1243487_output: " << tbl_LocalLimit_TD_1243487_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 5.281032 * 1000 << "ms" << std::endl; 
    return 0; 
}
