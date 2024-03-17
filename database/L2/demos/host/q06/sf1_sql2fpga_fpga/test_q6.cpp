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

#include "cfgFunc_q6.hpp" 
#include "q6.hpp" 

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
    std::cout << "NOTE:running query #6\n."; 
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
    Table tbl_Sort_TD_0329279_output("tbl_Sort_TD_0329279_output", 6100000, 2, "");
    tbl_Sort_TD_0329279_output.allocateHost();
    Table tbl_Filter_TD_1801776_output("tbl_Filter_TD_1801776_output", 6100000, 2, "");
    tbl_Filter_TD_1801776_output.allocateHost();
    Table tbl_Aggregate_TD_2916649_output("tbl_Aggregate_TD_2916649_output", 6100000, 2, "");
    tbl_Aggregate_TD_2916649_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3934585_output("tbl_JOIN_INNER_TD_3934585_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_3934585_output.allocateHost();
    Table tbl_JOIN_INNER_TD_443036_output("tbl_JOIN_INNER_TD_443036_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_443036_output.allocateHost();
    Table tbl_Filter_TD_4334129_output("tbl_Filter_TD_4334129_output", 6100000, 1, "");
    tbl_Filter_TD_4334129_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5146300_output("tbl_JOIN_INNER_TD_5146300_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_5146300_output.allocateHost();
    Table tbl_Filter_TD_5911680_output("tbl_Filter_TD_5911680_output", 6100000, 1, "");
    tbl_Filter_TD_5911680_output.allocateHost();
    Table tbl_JOIN_LEFTOUTER_TD_5823126_output("tbl_JOIN_LEFTOUTER_TD_5823126_output", 6100000, 3, "");
    tbl_JOIN_LEFTOUTER_TD_5823126_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6919996_output("tbl_JOIN_INNER_TD_6919996_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_6919996_output.allocateHost();
    Table tbl_Filter_TD_639923_output("tbl_Filter_TD_639923_output", 6100000, 3, "");
    tbl_Filter_TD_639923_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6747453_input;
    tbl_SerializeFromObject_TD_6747453_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_6747453_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_6747453_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_6747453_input.allocateHost();
    tbl_SerializeFromObject_TD_6747453_input.loadHost();
    Table tbl_Aggregate_TD_6589217_output("tbl_Aggregate_TD_6589217_output", 6100000, 1, "");
    tbl_Aggregate_TD_6589217_output.allocateHost();
    Table tbl_Filter_TD_6759273_output("tbl_Filter_TD_6759273_output", 6100000, 3, "");
    tbl_Filter_TD_6759273_output.allocateHost();
    Table tbl_Aggregate_TD_6617436_output("tbl_Aggregate_TD_6617436_output", 6100000, 2, "");
    tbl_Aggregate_TD_6617436_output.allocateHost();
    Table tbl_Filter_TD_792899_output("tbl_Filter_TD_792899_output", 6100000, 2, "");
    tbl_Filter_TD_792899_output.allocateHost();
    Table tbl_Filter_TD_7189205_output("tbl_Filter_TD_7189205_output", 6100000, 2, "");
    tbl_Filter_TD_7189205_output.allocateHost();
    Table tbl_SerializeFromObject_TD_771679_input;
    tbl_SerializeFromObject_TD_771679_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_771679_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_771679_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_771679_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_771679_input.allocateHost();
    tbl_SerializeFromObject_TD_771679_input.loadHost();
    Table tbl_Filter_TD_761648_output("tbl_Filter_TD_761648_output", 6100000, 1, "");
    tbl_Filter_TD_761648_output.allocateHost();
    Table tbl_SerializeFromObject_TD_765730_input;
    tbl_SerializeFromObject_TD_765730_input = Table("item", item_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_765730_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_765730_input.addCol("i_current_price", 4);
    tbl_SerializeFromObject_TD_765730_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_765730_input.allocateHost();
    tbl_SerializeFromObject_TD_765730_input.loadHost();
    Table tbl_Filter_TD_7643535_output("tbl_Filter_TD_7643535_output", 6100000, 2, "");
    tbl_Filter_TD_7643535_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8824865_input;
    tbl_SerializeFromObject_TD_8824865_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8824865_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_8824865_input.addCol("ca_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8824865_input.allocateHost();
    tbl_SerializeFromObject_TD_8824865_input.loadHost();
    Table tbl_SerializeFromObject_TD_8566050_input;
    tbl_SerializeFromObject_TD_8566050_input = Table("customer", customer_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8566050_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_8566050_input.addCol("c_current_addr_sk", 4);
    tbl_SerializeFromObject_TD_8566050_input.allocateHost();
    tbl_SerializeFromObject_TD_8566050_input.loadHost();
    Table tbl_SerializeFromObject_TD_8183182_input;
    tbl_SerializeFromObject_TD_8183182_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8183182_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_8183182_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_8183182_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_8183182_input.allocateHost();
    tbl_SerializeFromObject_TD_8183182_input.loadHost();
    Table tbl_SerializeFromObject_TD_8212594_input;
    tbl_SerializeFromObject_TD_8212594_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8212594_input.addCol("i_current_price", 4);
    tbl_SerializeFromObject_TD_8212594_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8212594_input.allocateHost();
    tbl_SerializeFromObject_TD_8212594_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_7_160270_s, tv_r_Filter_7_160270_e;
    gettimeofday(&tv_r_Filter_7_160270_s, 0);
    SW_Filter_TD_7643535(tbl_SerializeFromObject_TD_8212594_input, tbl_Filter_TD_7643535_output);
    gettimeofday(&tv_r_Filter_7_160270_e, 0);

    struct timeval tv_r_Filter_7_578100_s, tv_r_Filter_7_578100_e;
    gettimeofday(&tv_r_Filter_7_578100_s, 0);
    SW_Filter_TD_761648(tbl_SerializeFromObject_TD_8183182_input, tbl_Filter_TD_761648_output);
    gettimeofday(&tv_r_Filter_7_578100_e, 0);

    struct timeval tv_r_Filter_7_54785_s, tv_r_Filter_7_54785_e;
    gettimeofday(&tv_r_Filter_7_54785_s, 0);
    SW_Filter_TD_7189205(tbl_SerializeFromObject_TD_8566050_input, tbl_Filter_TD_7189205_output);
    gettimeofday(&tv_r_Filter_7_54785_e, 0);

    struct timeval tv_r_Filter_7_376097_s, tv_r_Filter_7_376097_e;
    gettimeofday(&tv_r_Filter_7_376097_s, 0);
    SW_Filter_TD_792899(tbl_SerializeFromObject_TD_8824865_input, tbl_Filter_TD_792899_output);
    gettimeofday(&tv_r_Filter_7_376097_e, 0);

    struct timeval tv_r_Aggregate_6_279663_s, tv_r_Aggregate_6_279663_e;
    gettimeofday(&tv_r_Aggregate_6_279663_s, 0);
    SW_Aggregate_TD_6617436(tbl_Filter_TD_7643535_output, tbl_Aggregate_TD_6617436_output);
    gettimeofday(&tv_r_Aggregate_6_279663_e, 0);

    struct timeval tv_r_Filter_6_971636_s, tv_r_Filter_6_971636_e;
    gettimeofday(&tv_r_Filter_6_971636_s, 0);
    SW_Filter_TD_6759273(tbl_SerializeFromObject_TD_765730_input, tbl_Filter_TD_6759273_output);
    gettimeofday(&tv_r_Filter_6_971636_e, 0);

    struct timeval tv_r_Aggregate_6_274169_s, tv_r_Aggregate_6_274169_e;
    gettimeofday(&tv_r_Aggregate_6_274169_s, 0);
    SW_Aggregate_TD_6589217(tbl_Filter_TD_761648_output, tbl_Aggregate_TD_6589217_output);
    gettimeofday(&tv_r_Aggregate_6_274169_e, 0);

    struct timeval tv_r_Filter_6_830234_s, tv_r_Filter_6_830234_e;
    gettimeofday(&tv_r_Filter_6_830234_s, 0);
    SW_Filter_TD_639923(tbl_SerializeFromObject_TD_771679_input, tbl_Filter_TD_639923_output);
    gettimeofday(&tv_r_Filter_6_830234_e, 0);

    struct timeval tv_r_JOIN_INNER_6_820645_s, tv_r_JOIN_INNER_6_820645_e;
    gettimeofday(&tv_r_JOIN_INNER_6_820645_s, 0);
    SW_JOIN_INNER_TD_6919996(tbl_Filter_TD_792899_output, tbl_Filter_TD_7189205_output, tbl_JOIN_INNER_TD_6919996_output);
    gettimeofday(&tv_r_JOIN_INNER_6_820645_e, 0);

    struct timeval tv_r_JOIN_LEFTOUTER_5_341969_s, tv_r_JOIN_LEFTOUTER_5_341969_e;
    gettimeofday(&tv_r_JOIN_LEFTOUTER_5_341969_s, 0);
    SW_JOIN_LEFTOUTER_TD_5823126(tbl_Filter_TD_6759273_output, tbl_Aggregate_TD_6617436_output, tbl_JOIN_LEFTOUTER_TD_5823126_output);
    gettimeofday(&tv_r_JOIN_LEFTOUTER_5_341969_e, 0);

    struct timeval tv_r_Filter_5_659634_s, tv_r_Filter_5_659634_e;
    gettimeofday(&tv_r_Filter_5_659634_s, 0);
    SW_Filter_TD_5911680(tbl_SerializeFromObject_TD_6747453_input, tbl_Aggregate_TD_6589217_output, tbl_Filter_TD_5911680_output);
    gettimeofday(&tv_r_Filter_5_659634_e, 0);

    struct timeval tv_r_JOIN_INNER_5_470783_s, tv_r_JOIN_INNER_5_470783_e;
    gettimeofday(&tv_r_JOIN_INNER_5_470783_s, 0);
    SW_JOIN_INNER_TD_5146300(tbl_JOIN_INNER_TD_6919996_output, tbl_Filter_TD_639923_output, tbl_JOIN_INNER_TD_5146300_output);
    gettimeofday(&tv_r_JOIN_INNER_5_470783_e, 0);

    struct timeval tv_r_Filter_4_388393_s, tv_r_Filter_4_388393_e;
    gettimeofday(&tv_r_Filter_4_388393_s, 0);
    SW_Filter_TD_4334129(tbl_JOIN_LEFTOUTER_TD_5823126_output, tbl_Filter_TD_4334129_output);
    gettimeofday(&tv_r_Filter_4_388393_e, 0);

    struct timeval tv_r_JOIN_INNER_4_405847_s, tv_r_JOIN_INNER_4_405847_e;
    gettimeofday(&tv_r_JOIN_INNER_4_405847_s, 0);
    SW_JOIN_INNER_TD_443036(tbl_JOIN_INNER_TD_5146300_output, tbl_Filter_TD_5911680_output, tbl_JOIN_INNER_TD_443036_output);
    gettimeofday(&tv_r_JOIN_INNER_4_405847_e, 0);

    struct timeval tv_r_JOIN_INNER_3_519246_s, tv_r_JOIN_INNER_3_519246_e;
    gettimeofday(&tv_r_JOIN_INNER_3_519246_s, 0);
    SW_JOIN_INNER_TD_3934585(tbl_JOIN_INNER_TD_443036_output, tbl_Filter_TD_4334129_output, tbl_JOIN_INNER_TD_3934585_output);
    gettimeofday(&tv_r_JOIN_INNER_3_519246_e, 0);

    struct timeval tv_r_Aggregate_2_454519_s, tv_r_Aggregate_2_454519_e;
    gettimeofday(&tv_r_Aggregate_2_454519_s, 0);
    SW_Aggregate_TD_2916649(tbl_JOIN_INNER_TD_3934585_output, tbl_Aggregate_TD_2916649_output);
    gettimeofday(&tv_r_Aggregate_2_454519_e, 0);

    struct timeval tv_r_Filter_1_775839_s, tv_r_Filter_1_775839_e;
    gettimeofday(&tv_r_Filter_1_775839_s, 0);
    SW_Filter_TD_1801776(tbl_Aggregate_TD_2916649_output, tbl_Filter_TD_1801776_output);
    gettimeofday(&tv_r_Filter_1_775839_e, 0);

    struct timeval tv_r_Sort_0_948150_s, tv_r_Sort_0_948150_e;
    gettimeofday(&tv_r_Sort_0_948150_s, 0);
    SW_Sort_TD_0329279(tbl_Filter_TD_1801776_output, tbl_Sort_TD_0329279_output);
    gettimeofday(&tv_r_Sort_0_948150_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_160270_s, &tv_r_Filter_7_160270_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8212594_input: " << tbl_SerializeFromObject_TD_8212594_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_578100_s, &tv_r_Filter_7_578100_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8183182_input: " << tbl_SerializeFromObject_TD_8183182_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_54785_s, &tv_r_Filter_7_54785_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8566050_input: " << tbl_SerializeFromObject_TD_8566050_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_376097_s, &tv_r_Filter_7_376097_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8824865_input: " << tbl_SerializeFromObject_TD_8824865_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_6: " << tvdiff(&tv_r_Aggregate_6_279663_s, &tv_r_Aggregate_6_279663_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_7643535_output: " << tbl_Filter_TD_7643535_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_971636_s, &tv_r_Filter_6_971636_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_765730_input: " << tbl_SerializeFromObject_TD_765730_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_6: " << tvdiff(&tv_r_Aggregate_6_274169_s, &tv_r_Aggregate_6_274169_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_761648_output: " << tbl_Filter_TD_761648_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_830234_s, &tv_r_Filter_6_830234_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_771679_input: " << tbl_SerializeFromObject_TD_771679_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_820645_s, &tv_r_JOIN_INNER_6_820645_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_792899_output: " << tbl_Filter_TD_792899_output.getNumRow() << " " << "tbl_Filter_TD_7189205_output: " << tbl_Filter_TD_7189205_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTOUTER_5: " << tvdiff(&tv_r_JOIN_LEFTOUTER_5_341969_s, &tv_r_JOIN_LEFTOUTER_5_341969_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6759273_output: " << tbl_Filter_TD_6759273_output.getNumRow() << " " << "tbl_Aggregate_TD_6617436_output: " << tbl_Aggregate_TD_6617436_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_659634_s, &tv_r_Filter_5_659634_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6747453_input: " << tbl_SerializeFromObject_TD_6747453_input.getNumRow() << " " << "tbl_Aggregate_TD_6589217_output: " << tbl_Aggregate_TD_6589217_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_470783_s, &tv_r_JOIN_INNER_5_470783_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6919996_output: " << tbl_JOIN_INNER_TD_6919996_output.getNumRow() << " " << "tbl_Filter_TD_639923_output: " << tbl_Filter_TD_639923_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_388393_s, &tv_r_Filter_4_388393_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTOUTER_TD_5823126_output: " << tbl_JOIN_LEFTOUTER_TD_5823126_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_405847_s, &tv_r_JOIN_INNER_4_405847_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5146300_output: " << tbl_JOIN_INNER_TD_5146300_output.getNumRow() << " " << "tbl_Filter_TD_5911680_output: " << tbl_Filter_TD_5911680_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_519246_s, &tv_r_JOIN_INNER_3_519246_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_443036_output: " << tbl_JOIN_INNER_TD_443036_output.getNumRow() << " " << "tbl_Filter_TD_4334129_output: " << tbl_Filter_TD_4334129_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_2: " << tvdiff(&tv_r_Aggregate_2_454519_s, &tv_r_Aggregate_2_454519_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3934585_output: " << tbl_JOIN_INNER_TD_3934585_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_1: " << tvdiff(&tv_r_Filter_1_775839_s, &tv_r_Filter_1_775839_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_2916649_output: " << tbl_Aggregate_TD_2916649_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_948150_s, &tv_r_Sort_0_948150_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_1801776_output: " << tbl_Filter_TD_1801776_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.112456 * 1000 << "ms" << std::endl; 
    return 0; 
}
