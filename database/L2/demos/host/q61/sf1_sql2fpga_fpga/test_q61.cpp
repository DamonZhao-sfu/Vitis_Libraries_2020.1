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

#include "cfgFunc_q61.hpp" 
#include "q61.hpp" 

int main(int argc, const char* argv[]) { 
    std::cout << "\n------------ TPC-H Query Test -------------\n"; 
    ArgParser parser(argc, argv); 
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
    std::cout << "NOTE:running query #61\n."; 
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
    // ****************************** Tables **************************** // 
    Table tbl_Project_TD_0192533_output("tbl_Project_TD_0192533_output", 6100000, 3, "");
    tbl_Project_TD_0192533_output.allocateHost();
    Table tbl_JOIN_CROSS_TD_1666977_output("tbl_JOIN_CROSS_TD_1666977_output", 6100000, 2, "");
    tbl_JOIN_CROSS_TD_1666977_output.allocateHost();
    Table tbl_Aggregate_TD_2869480_output("tbl_Aggregate_TD_2869480_output", 6100000, 1, "");
    tbl_Aggregate_TD_2869480_output.allocateHost();
    Table tbl_Aggregate_TD_2866432_output("tbl_Aggregate_TD_2866432_output", 6100000, 1, "");
    tbl_Aggregate_TD_2866432_output.allocateHost();
    Table tbl_JOIN_INNER_TD_362046_output("tbl_JOIN_INNER_TD_362046_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_362046_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3519817_output("tbl_JOIN_INNER_TD_3519817_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_3519817_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4146508_output("tbl_JOIN_INNER_TD_4146508_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_4146508_output.allocateHost();
    Table tbl_Filter_TD_4121212_output("tbl_Filter_TD_4121212_output", 6100000, 1, "");
    tbl_Filter_TD_4121212_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4283852_output("tbl_JOIN_INNER_TD_4283852_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_4283852_output.allocateHost();
    Table tbl_Filter_TD_4540377_output("tbl_Filter_TD_4540377_output", 6100000, 1, "");
    tbl_Filter_TD_4540377_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5241017_output("tbl_JOIN_INNER_TD_5241017_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_5241017_output.allocateHost();
    Table tbl_Filter_TD_5522498_output("tbl_Filter_TD_5522498_output", 6100000, 1, "");
    tbl_Filter_TD_5522498_output.allocateHost();
    Table tbl_SerializeFromObject_TD_5542235_input;
    tbl_SerializeFromObject_TD_5542235_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_5542235_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_5542235_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_5542235_input.allocateHost();
    tbl_SerializeFromObject_TD_5542235_input.loadHost();
    Table tbl_JOIN_INNER_TD_5966274_output("tbl_JOIN_INNER_TD_5966274_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_5966274_output.allocateHost();
    Table tbl_Filter_TD_5282555_output("tbl_Filter_TD_5282555_output", 6100000, 1, "");
    tbl_Filter_TD_5282555_output.allocateHost();
    Table tbl_SerializeFromObject_TD_5169601_input;
    tbl_SerializeFromObject_TD_5169601_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_5169601_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_5169601_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_5169601_input.allocateHost();
    tbl_SerializeFromObject_TD_5169601_input.loadHost();
    Table tbl_JOIN_INNER_TD_6370860_output("tbl_JOIN_INNER_TD_6370860_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_6370860_output.allocateHost();
    Table tbl_Filter_TD_6785245_output("tbl_Filter_TD_6785245_output", 6100000, 2, "");
    tbl_Filter_TD_6785245_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6784548_input;
    tbl_SerializeFromObject_TD_6784548_input = Table("customer_address", customer_address_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_6784548_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_6784548_input.allocateHost();
    tbl_SerializeFromObject_TD_6784548_input.loadHost();
    Table tbl_JOIN_INNER_TD_6149111_output("tbl_JOIN_INNER_TD_6149111_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_6149111_output.allocateHost();
    Table tbl_Filter_TD_656333_output("tbl_Filter_TD_656333_output", 6100000, 2, "");
    tbl_Filter_TD_656333_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6566856_input;
    tbl_SerializeFromObject_TD_6566856_input = Table("customer_address", customer_address_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_6566856_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_6566856_input.allocateHost();
    tbl_SerializeFromObject_TD_6566856_input.loadHost();
    Table tbl_JOIN_INNER_TD_7792795_output("tbl_JOIN_INNER_TD_7792795_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_7792795_output.allocateHost();
    Table tbl_Filter_TD_7892130_output("tbl_Filter_TD_7892130_output", 6100000, 1, "");
    tbl_Filter_TD_7892130_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7302846_input;
    tbl_SerializeFromObject_TD_7302846_input = Table("customer", customer_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7302846_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_7302846_input.addCol("c_current_addr_sk", 4);
    tbl_SerializeFromObject_TD_7302846_input.allocateHost();
    tbl_SerializeFromObject_TD_7302846_input.loadHost();
    Table tbl_JOIN_INNER_TD_721842_output("tbl_JOIN_INNER_TD_721842_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_721842_output.allocateHost();
    Table tbl_Filter_TD_77755_output("tbl_Filter_TD_77755_output", 6100000, 1, "");
    tbl_Filter_TD_77755_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7846787_input;
    tbl_SerializeFromObject_TD_7846787_input = Table("customer", customer_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7846787_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_7846787_input.addCol("c_current_addr_sk", 4);
    tbl_SerializeFromObject_TD_7846787_input.allocateHost();
    tbl_SerializeFromObject_TD_7846787_input.loadHost();
    Table tbl_JOIN_INNER_TD_8567840_output("tbl_JOIN_INNER_TD_8567840_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_8567840_output.allocateHost();
    Table tbl_Filter_TD_8191688_output("tbl_Filter_TD_8191688_output", 6100000, 1, "");
    tbl_Filter_TD_8191688_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8833837_input;
    tbl_SerializeFromObject_TD_8833837_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8833837_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_8833837_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_8833837_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_8833837_input.allocateHost();
    tbl_SerializeFromObject_TD_8833837_input.loadHost();
    Table tbl_Filter_TD_8713340_output("tbl_Filter_TD_8713340_output", 6100000, 5, "");
    tbl_Filter_TD_8713340_output.allocateHost();
    Table tbl_Filter_TD_8202988_output("tbl_Filter_TD_8202988_output", 6100000, 1, "");
    tbl_Filter_TD_8202988_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8285486_input;
    tbl_SerializeFromObject_TD_8285486_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8285486_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_8285486_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_8285486_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_8285486_input.allocateHost();
    tbl_SerializeFromObject_TD_8285486_input.loadHost();
    Table tbl_Filter_TD_9580451_output("tbl_Filter_TD_9580451_output", 6100000, 6, "");
    tbl_Filter_TD_9580451_output.allocateHost();
    Table tbl_Filter_TD_9779445_output("tbl_Filter_TD_9779445_output", 6100000, 1, "");
    tbl_Filter_TD_9779445_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9939005_input;
    tbl_SerializeFromObject_TD_9939005_input = Table("promotion", promotion_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_9939005_input.addCol("p_promo_sk", 4);
    tbl_SerializeFromObject_TD_9939005_input.addCol("p_channel_dmail", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9939005_input.addCol("p_channel_email", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9939005_input.addCol("p_channel_tv", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9939005_input.allocateHost();
    tbl_SerializeFromObject_TD_9939005_input.loadHost();
    Table tbl_SerializeFromObject_TD_9961376_input;
    tbl_SerializeFromObject_TD_9961376_input = Table("store_sales", store_sales_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_9961376_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_9961376_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_9961376_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_9961376_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_9961376_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_9961376_input.allocateHost();
    tbl_SerializeFromObject_TD_9961376_input.loadHost();
    Table tbl_SerializeFromObject_TD_9382655_input;
    tbl_SerializeFromObject_TD_9382655_input = Table("store", store_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_9382655_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_9382655_input.allocateHost();
    tbl_SerializeFromObject_TD_9382655_input.loadHost();
    Table tbl_SerializeFromObject_TD_10851664_input;
    tbl_SerializeFromObject_TD_10851664_input = Table("store_sales", store_sales_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_10851664_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10851664_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_10851664_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_10851664_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_10851664_input.addCol("ss_promo_sk", 4);
    tbl_SerializeFromObject_TD_10851664_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_10851664_input.allocateHost();
    tbl_SerializeFromObject_TD_10851664_input.loadHost();
    Table tbl_SerializeFromObject_TD_10504956_input;
    tbl_SerializeFromObject_TD_10504956_input = Table("store", store_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_10504956_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_10504956_input.allocateHost();
    tbl_SerializeFromObject_TD_10504956_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_9_254970_s, tv_r_Filter_9_254970_e;
    gettimeofday(&tv_r_Filter_9_254970_s, 0);
    SW_Filter_TD_9779445(tbl_SerializeFromObject_TD_10504956_input, tbl_Filter_TD_9779445_output);
    gettimeofday(&tv_r_Filter_9_254970_e, 0);

    struct timeval tv_r_Filter_9_485034_s, tv_r_Filter_9_485034_e;
    gettimeofday(&tv_r_Filter_9_485034_s, 0);
    SW_Filter_TD_9580451(tbl_SerializeFromObject_TD_10851664_input, tbl_Filter_TD_9580451_output);
    gettimeofday(&tv_r_Filter_9_485034_e, 0);

    struct timeval tv_r_Filter_8_902396_s, tv_r_Filter_8_902396_e;
    gettimeofday(&tv_r_Filter_8_902396_s, 0);
    SW_Filter_TD_8202988(tbl_SerializeFromObject_TD_9382655_input, tbl_Filter_TD_8202988_output);
    gettimeofday(&tv_r_Filter_8_902396_e, 0);

    struct timeval tv_r_Filter_8_819702_s, tv_r_Filter_8_819702_e;
    gettimeofday(&tv_r_Filter_8_819702_s, 0);
    SW_Filter_TD_8713340(tbl_SerializeFromObject_TD_9961376_input, tbl_Filter_TD_8713340_output);
    gettimeofday(&tv_r_Filter_8_819702_e, 0);

    struct timeval tv_r_Filter_8_247272_s, tv_r_Filter_8_247272_e;
    gettimeofday(&tv_r_Filter_8_247272_s, 0);
    SW_Filter_TD_8191688(tbl_SerializeFromObject_TD_9939005_input, tbl_Filter_TD_8191688_output);
    gettimeofday(&tv_r_Filter_8_247272_e, 0);

    struct timeval tv_r_JOIN_INNER_8_100581_s, tv_r_JOIN_INNER_8_100581_e;
    gettimeofday(&tv_r_JOIN_INNER_8_100581_s, 0);
    SW_JOIN_INNER_TD_8567840(tbl_Filter_TD_9580451_output, tbl_Filter_TD_9779445_output, tbl_JOIN_INNER_TD_8567840_output);
    gettimeofday(&tv_r_JOIN_INNER_8_100581_e, 0);

    struct timeval tv_r_Filter_7_70799_s, tv_r_Filter_7_70799_e;
    gettimeofday(&tv_r_Filter_7_70799_s, 0);
    SW_Filter_TD_77755(tbl_SerializeFromObject_TD_8285486_input, tbl_Filter_TD_77755_output);
    gettimeofday(&tv_r_Filter_7_70799_e, 0);

    struct timeval tv_r_JOIN_INNER_7_597119_s, tv_r_JOIN_INNER_7_597119_e;
    gettimeofday(&tv_r_JOIN_INNER_7_597119_s, 0);
    SW_JOIN_INNER_TD_721842(tbl_Filter_TD_8713340_output, tbl_Filter_TD_8202988_output, tbl_JOIN_INNER_TD_721842_output);
    gettimeofday(&tv_r_JOIN_INNER_7_597119_e, 0);

    struct timeval tv_r_Filter_7_415146_s, tv_r_Filter_7_415146_e;
    gettimeofday(&tv_r_Filter_7_415146_s, 0);
    SW_Filter_TD_7892130(tbl_SerializeFromObject_TD_8833837_input, tbl_Filter_TD_7892130_output);
    gettimeofday(&tv_r_Filter_7_415146_e, 0);

    struct timeval tv_r_JOIN_INNER_7_724968_s, tv_r_JOIN_INNER_7_724968_e;
    gettimeofday(&tv_r_JOIN_INNER_7_724968_s, 0);
    SW_JOIN_INNER_TD_7792795(tbl_JOIN_INNER_TD_8567840_output, tbl_Filter_TD_8191688_output, tbl_JOIN_INNER_TD_7792795_output);
    gettimeofday(&tv_r_JOIN_INNER_7_724968_e, 0);

    struct timeval tv_r_Filter_6_57083_s, tv_r_Filter_6_57083_e;
    gettimeofday(&tv_r_Filter_6_57083_s, 0);
    SW_Filter_TD_656333(tbl_SerializeFromObject_TD_7846787_input, tbl_Filter_TD_656333_output);
    gettimeofday(&tv_r_Filter_6_57083_e, 0);

    struct timeval tv_r_JOIN_INNER_6_493459_s, tv_r_JOIN_INNER_6_493459_e;
    gettimeofday(&tv_r_JOIN_INNER_6_493459_s, 0);
    SW_JOIN_INNER_TD_6149111(tbl_JOIN_INNER_TD_721842_output, tbl_Filter_TD_77755_output, tbl_JOIN_INNER_TD_6149111_output);
    gettimeofday(&tv_r_JOIN_INNER_6_493459_e, 0);

    struct timeval tv_r_Filter_6_191273_s, tv_r_Filter_6_191273_e;
    gettimeofday(&tv_r_Filter_6_191273_s, 0);
    SW_Filter_TD_6785245(tbl_SerializeFromObject_TD_7302846_input, tbl_Filter_TD_6785245_output);
    gettimeofday(&tv_r_Filter_6_191273_e, 0);

    struct timeval tv_r_JOIN_INNER_6_654457_s, tv_r_JOIN_INNER_6_654457_e;
    gettimeofday(&tv_r_JOIN_INNER_6_654457_s, 0);
    SW_JOIN_INNER_TD_6370860(tbl_JOIN_INNER_TD_7792795_output, tbl_Filter_TD_7892130_output, tbl_JOIN_INNER_TD_6370860_output);
    gettimeofday(&tv_r_JOIN_INNER_6_654457_e, 0);

    struct timeval tv_r_Filter_5_157990_s, tv_r_Filter_5_157990_e;
    gettimeofday(&tv_r_Filter_5_157990_s, 0);
    SW_Filter_TD_5282555(tbl_SerializeFromObject_TD_6566856_input, tbl_Filter_TD_5282555_output);
    gettimeofday(&tv_r_Filter_5_157990_e, 0);

    struct timeval tv_r_JOIN_INNER_5_552369_s, tv_r_JOIN_INNER_5_552369_e;
    gettimeofday(&tv_r_JOIN_INNER_5_552369_s, 0);
    SW_JOIN_INNER_TD_5966274(tbl_JOIN_INNER_TD_6149111_output, tbl_Filter_TD_656333_output, tbl_JOIN_INNER_TD_5966274_output);
    gettimeofday(&tv_r_JOIN_INNER_5_552369_e, 0);

    struct timeval tv_r_Filter_5_117522_s, tv_r_Filter_5_117522_e;
    gettimeofday(&tv_r_Filter_5_117522_s, 0);
    SW_Filter_TD_5522498(tbl_SerializeFromObject_TD_6784548_input, tbl_Filter_TD_5522498_output);
    gettimeofday(&tv_r_Filter_5_117522_e, 0);

    struct timeval tv_r_JOIN_INNER_5_71407_s, tv_r_JOIN_INNER_5_71407_e;
    gettimeofday(&tv_r_JOIN_INNER_5_71407_s, 0);
    SW_JOIN_INNER_TD_5241017(tbl_JOIN_INNER_TD_6370860_output, tbl_Filter_TD_6785245_output, tbl_JOIN_INNER_TD_5241017_output);
    gettimeofday(&tv_r_JOIN_INNER_5_71407_e, 0);

    struct timeval tv_r_Filter_4_432190_s, tv_r_Filter_4_432190_e;
    gettimeofday(&tv_r_Filter_4_432190_s, 0);
    SW_Filter_TD_4540377(tbl_SerializeFromObject_TD_5169601_input, tbl_Filter_TD_4540377_output);
    gettimeofday(&tv_r_Filter_4_432190_e, 0);

    struct timeval tv_r_JOIN_INNER_4_249997_s, tv_r_JOIN_INNER_4_249997_e;
    gettimeofday(&tv_r_JOIN_INNER_4_249997_s, 0);
    SW_JOIN_INNER_TD_4283852(tbl_JOIN_INNER_TD_5966274_output, tbl_Filter_TD_5282555_output, tbl_JOIN_INNER_TD_4283852_output);
    gettimeofday(&tv_r_JOIN_INNER_4_249997_e, 0);

    struct timeval tv_r_Filter_4_300647_s, tv_r_Filter_4_300647_e;
    gettimeofday(&tv_r_Filter_4_300647_s, 0);
    SW_Filter_TD_4121212(tbl_SerializeFromObject_TD_5542235_input, tbl_Filter_TD_4121212_output);
    gettimeofday(&tv_r_Filter_4_300647_e, 0);

    struct timeval tv_r_JOIN_INNER_4_942434_s, tv_r_JOIN_INNER_4_942434_e;
    gettimeofday(&tv_r_JOIN_INNER_4_942434_s, 0);
    SW_JOIN_INNER_TD_4146508(tbl_JOIN_INNER_TD_5241017_output, tbl_Filter_TD_5522498_output, tbl_JOIN_INNER_TD_4146508_output);
    gettimeofday(&tv_r_JOIN_INNER_4_942434_e, 0);

    struct timeval tv_r_JOIN_INNER_3_813150_s, tv_r_JOIN_INNER_3_813150_e;
    gettimeofday(&tv_r_JOIN_INNER_3_813150_s, 0);
    SW_JOIN_INNER_TD_3519817(tbl_JOIN_INNER_TD_4283852_output, tbl_Filter_TD_4540377_output, tbl_JOIN_INNER_TD_3519817_output);
    gettimeofday(&tv_r_JOIN_INNER_3_813150_e, 0);

    struct timeval tv_r_JOIN_INNER_3_338571_s, tv_r_JOIN_INNER_3_338571_e;
    gettimeofday(&tv_r_JOIN_INNER_3_338571_s, 0);
    SW_JOIN_INNER_TD_362046(tbl_JOIN_INNER_TD_4146508_output, tbl_Filter_TD_4121212_output, tbl_JOIN_INNER_TD_362046_output);
    gettimeofday(&tv_r_JOIN_INNER_3_338571_e, 0);

    struct timeval tv_r_Aggregate_2_772272_s, tv_r_Aggregate_2_772272_e;
    gettimeofday(&tv_r_Aggregate_2_772272_s, 0);
    SW_Aggregate_TD_2866432(tbl_JOIN_INNER_TD_3519817_output, tbl_Aggregate_TD_2866432_output);
    gettimeofday(&tv_r_Aggregate_2_772272_e, 0);

    struct timeval tv_r_Aggregate_2_571825_s, tv_r_Aggregate_2_571825_e;
    gettimeofday(&tv_r_Aggregate_2_571825_s, 0);
    SW_Aggregate_TD_2869480(tbl_JOIN_INNER_TD_362046_output, tbl_Aggregate_TD_2869480_output);
    gettimeofday(&tv_r_Aggregate_2_571825_e, 0);

    struct timeval tv_r_JOIN_CROSS_1_374025_s, tv_r_JOIN_CROSS_1_374025_e;
    gettimeofday(&tv_r_JOIN_CROSS_1_374025_s, 0);
    SW_JOIN_CROSS_TD_1666977(tbl_Aggregate_TD_2869480_output, tbl_Aggregate_TD_2866432_output, tbl_JOIN_CROSS_TD_1666977_output);
    gettimeofday(&tv_r_JOIN_CROSS_1_374025_e, 0);

    struct timeval tv_r_Project_0_675674_s, tv_r_Project_0_675674_e;
    gettimeofday(&tv_r_Project_0_675674_s, 0);
    SW_Project_TD_0192533(tbl_JOIN_CROSS_TD_1666977_output, tbl_Project_TD_0192533_output);
    gettimeofday(&tv_r_Project_0_675674_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_254970_s, &tv_r_Filter_9_254970_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10504956_input: " << tbl_SerializeFromObject_TD_10504956_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_485034_s, &tv_r_Filter_9_485034_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10851664_input: " << tbl_SerializeFromObject_TD_10851664_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_902396_s, &tv_r_Filter_8_902396_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9382655_input: " << tbl_SerializeFromObject_TD_9382655_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_819702_s, &tv_r_Filter_8_819702_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9961376_input: " << tbl_SerializeFromObject_TD_9961376_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_247272_s, &tv_r_Filter_8_247272_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9939005_input: " << tbl_SerializeFromObject_TD_9939005_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_100581_s, &tv_r_JOIN_INNER_8_100581_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9580451_output: " << tbl_Filter_TD_9580451_output.getNumRow() << " " << "tbl_Filter_TD_9779445_output: " << tbl_Filter_TD_9779445_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_70799_s, &tv_r_Filter_7_70799_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8285486_input: " << tbl_SerializeFromObject_TD_8285486_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_597119_s, &tv_r_JOIN_INNER_7_597119_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8713340_output: " << tbl_Filter_TD_8713340_output.getNumRow() << " " << "tbl_Filter_TD_8202988_output: " << tbl_Filter_TD_8202988_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_415146_s, &tv_r_Filter_7_415146_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8833837_input: " << tbl_SerializeFromObject_TD_8833837_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_724968_s, &tv_r_JOIN_INNER_7_724968_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8567840_output: " << tbl_JOIN_INNER_TD_8567840_output.getNumRow() << " " << "tbl_Filter_TD_8191688_output: " << tbl_Filter_TD_8191688_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_57083_s, &tv_r_Filter_6_57083_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7846787_input: " << tbl_SerializeFromObject_TD_7846787_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_493459_s, &tv_r_JOIN_INNER_6_493459_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_721842_output: " << tbl_JOIN_INNER_TD_721842_output.getNumRow() << " " << "tbl_Filter_TD_77755_output: " << tbl_Filter_TD_77755_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_191273_s, &tv_r_Filter_6_191273_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7302846_input: " << tbl_SerializeFromObject_TD_7302846_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_654457_s, &tv_r_JOIN_INNER_6_654457_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7792795_output: " << tbl_JOIN_INNER_TD_7792795_output.getNumRow() << " " << "tbl_Filter_TD_7892130_output: " << tbl_Filter_TD_7892130_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_157990_s, &tv_r_Filter_5_157990_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6566856_input: " << tbl_SerializeFromObject_TD_6566856_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_552369_s, &tv_r_JOIN_INNER_5_552369_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6149111_output: " << tbl_JOIN_INNER_TD_6149111_output.getNumRow() << " " << "tbl_Filter_TD_656333_output: " << tbl_Filter_TD_656333_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_117522_s, &tv_r_Filter_5_117522_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6784548_input: " << tbl_SerializeFromObject_TD_6784548_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_71407_s, &tv_r_JOIN_INNER_5_71407_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6370860_output: " << tbl_JOIN_INNER_TD_6370860_output.getNumRow() << " " << "tbl_Filter_TD_6785245_output: " << tbl_Filter_TD_6785245_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_432190_s, &tv_r_Filter_4_432190_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5169601_input: " << tbl_SerializeFromObject_TD_5169601_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_249997_s, &tv_r_JOIN_INNER_4_249997_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5966274_output: " << tbl_JOIN_INNER_TD_5966274_output.getNumRow() << " " << "tbl_Filter_TD_5282555_output: " << tbl_Filter_TD_5282555_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_300647_s, &tv_r_Filter_4_300647_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5542235_input: " << tbl_SerializeFromObject_TD_5542235_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_942434_s, &tv_r_JOIN_INNER_4_942434_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5241017_output: " << tbl_JOIN_INNER_TD_5241017_output.getNumRow() << " " << "tbl_Filter_TD_5522498_output: " << tbl_Filter_TD_5522498_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_813150_s, &tv_r_JOIN_INNER_3_813150_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4283852_output: " << tbl_JOIN_INNER_TD_4283852_output.getNumRow() << " " << "tbl_Filter_TD_4540377_output: " << tbl_Filter_TD_4540377_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_338571_s, &tv_r_JOIN_INNER_3_338571_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4146508_output: " << tbl_JOIN_INNER_TD_4146508_output.getNumRow() << " " << "tbl_Filter_TD_4121212_output: " << tbl_Filter_TD_4121212_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_2: " << tvdiff(&tv_r_Aggregate_2_772272_s, &tv_r_Aggregate_2_772272_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3519817_output: " << tbl_JOIN_INNER_TD_3519817_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_2: " << tvdiff(&tv_r_Aggregate_2_571825_s, &tv_r_Aggregate_2_571825_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_362046_output: " << tbl_JOIN_INNER_TD_362046_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_CROSS_1: " << tvdiff(&tv_r_JOIN_CROSS_1_374025_s, &tv_r_JOIN_CROSS_1_374025_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_2869480_output: " << tbl_Aggregate_TD_2869480_output.getNumRow() << " " << "tbl_Aggregate_TD_2866432_output: " << tbl_Aggregate_TD_2866432_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_0: " << tvdiff(&tv_r_Project_0_675674_s, &tv_r_Project_0_675674_e) / 1000.0 << " ms " 
     << "tbl_JOIN_CROSS_TD_1666977_output: " << tbl_JOIN_CROSS_TD_1666977_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.0840056 * 1000 << "ms" << std::endl; 
    return 0; 
}
