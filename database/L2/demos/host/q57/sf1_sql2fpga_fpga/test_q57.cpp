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

#include "cfgFunc_q57.hpp" 
#include "q57.hpp" 

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
    std::cout << "NOTE:running query #57\n."; 
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
    Table tbl_GlobalLimit_TD_0684633_output("tbl_GlobalLimit_TD_0684633_output", 6100000, 9, "");
    tbl_GlobalLimit_TD_0684633_output.allocateHost();
    Table tbl_LocalLimit_TD_130890_output("tbl_LocalLimit_TD_130890_output", 6100000, 9, "");
    tbl_LocalLimit_TD_130890_output.allocateHost();
    Table tbl_Sort_TD_2562001_output("tbl_Sort_TD_2562001_output", 6100000, 9, "");
    tbl_Sort_TD_2562001_output.allocateHost();
    Table tbl_Project_TD_3902436_output("tbl_Project_TD_3902436_output", 6100000, 9, "");
    tbl_Project_TD_3902436_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4632128_output("tbl_JOIN_INNER_TD_4632128_output", 6100000, 9, "");
    tbl_JOIN_INNER_TD_4632128_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5241974_output("tbl_JOIN_INNER_TD_5241974_output", 6100000, 9, "");
    tbl_JOIN_INNER_TD_5241974_output.allocateHost();
    Table tbl_Project_TD_5357390_output("tbl_Project_TD_5357390_output", 6100000, 5, "");
    tbl_Project_TD_5357390_output.allocateHost();
    Table tbl_Filter_TD_6667714_output("tbl_Filter_TD_6667714_output", 6100000, 8, "");
    tbl_Filter_TD_6667714_output.allocateHost();
    Table tbl_Project_TD_6224007_output("tbl_Project_TD_6224007_output", 6100000, 5, "");
    tbl_Project_TD_6224007_output.allocateHost();
    Table tbl_Window_TD_6547937_output("tbl_Window_TD_6547937_output", 6100000, 7, "");
    tbl_Window_TD_6547937_output.allocateHost();
    Table tbl_Window_TD_7405474_output("tbl_Window_TD_7405474_output", 6100000, 9, "");
    tbl_Window_TD_7405474_output.allocateHost();
    Table tbl_Window_TD_7331027_output("tbl_Window_TD_7331027_output", 6100000, 7, "");
    tbl_Window_TD_7331027_output.allocateHost();
    Table tbl_Aggregate_TD_7738360_output("tbl_Aggregate_TD_7738360_output", 6100000, 6, "");
    tbl_Aggregate_TD_7738360_output.allocateHost();
    Table tbl_Filter_TD_8164128_output("tbl_Filter_TD_8164128_output", 6100000, 8, "");
    tbl_Filter_TD_8164128_output.allocateHost();
    Table tbl_Aggregate_TD_8279717_output("tbl_Aggregate_TD_8279717_output", 6100000, 6, "");
    tbl_Aggregate_TD_8279717_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8589361_output("tbl_JOIN_INNER_TD_8589361_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_8589361_output.allocateHost();
    Table tbl_Window_TD_9852472_output("tbl_Window_TD_9852472_output", 6100000, 8, "");
    tbl_Window_TD_9852472_output.allocateHost();
    Table tbl_JOIN_INNER_TD_9160603_output("tbl_JOIN_INNER_TD_9160603_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_9160603_output.allocateHost();
    Table tbl_JOIN_INNER_TD_9514904_output("tbl_JOIN_INNER_TD_9514904_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_9514904_output.allocateHost();
    Table tbl_Filter_TD_9968509_output("tbl_Filter_TD_9968509_output", 6100000, 2, "");
    tbl_Filter_TD_9968509_output.allocateHost();
    Table tbl_Aggregate_TD_10376037_output("tbl_Aggregate_TD_10376037_output", 6100000, 7, "");
    tbl_Aggregate_TD_10376037_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10462332_output("tbl_JOIN_INNER_TD_10462332_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_10462332_output.allocateHost();
    Table tbl_Filter_TD_10422941_output("tbl_Filter_TD_10422941_output", 6100000, 2, "");
    tbl_Filter_TD_10422941_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10332289_output("tbl_JOIN_INNER_TD_10332289_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_10332289_output.allocateHost();
    Table tbl_Filter_TD_10827249_output("tbl_Filter_TD_10827249_output", 6100000, 3, "");
    tbl_Filter_TD_10827249_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10909689_input;
    tbl_SerializeFromObject_TD_10909689_input = Table("call_center", call_center_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10909689_input.addCol("cc_call_center_sk", 4);
    tbl_SerializeFromObject_TD_10909689_input.addCol("cc_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10909689_input.allocateHost();
    tbl_SerializeFromObject_TD_10909689_input.loadHost();
    Table tbl_JOIN_INNER_TD_113015_output("tbl_JOIN_INNER_TD_113015_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_113015_output.allocateHost();
    Table tbl_JOIN_INNER_TD_11646117_output("tbl_JOIN_INNER_TD_11646117_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_11646117_output.allocateHost();
    Table tbl_Filter_TD_11656057_output("tbl_Filter_TD_11656057_output", 6100000, 3, "");
    tbl_Filter_TD_11656057_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11945483_input;
    tbl_SerializeFromObject_TD_11945483_input = Table("call_center", call_center_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11945483_input.addCol("cc_call_center_sk", 4);
    tbl_SerializeFromObject_TD_11945483_input.addCol("cc_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11945483_input.allocateHost();
    tbl_SerializeFromObject_TD_11945483_input.loadHost();
    Table tbl_Filter_TD_11715245_output("tbl_Filter_TD_11715245_output", 6100000, 3, "");
    tbl_Filter_TD_11715245_output.allocateHost();
    Table tbl_Filter_TD_1193880_output("tbl_Filter_TD_1193880_output", 6100000, 4, "");
    tbl_Filter_TD_1193880_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11476877_input;
    tbl_SerializeFromObject_TD_11476877_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11476877_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_11476877_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_11476877_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_11476877_input.allocateHost();
    tbl_SerializeFromObject_TD_11476877_input.loadHost();
    Table tbl_JOIN_INNER_TD_12967486_output("tbl_JOIN_INNER_TD_12967486_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_12967486_output.allocateHost();
    Table tbl_Filter_TD_1271702_output("tbl_Filter_TD_1271702_output", 6100000, 2, "");
    tbl_Filter_TD_1271702_output.allocateHost();
    Table tbl_Filter_TD_12627067_output("tbl_Filter_TD_12627067_output", 6100000, 3, "");
    tbl_Filter_TD_12627067_output.allocateHost();
    Table tbl_Filter_TD_12327273_output("tbl_Filter_TD_12327273_output", 6100000, 4, "");
    tbl_Filter_TD_12327273_output.allocateHost();
    Table tbl_SerializeFromObject_TD_12856143_input;
    tbl_SerializeFromObject_TD_12856143_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_12856143_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_12856143_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_12856143_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_12856143_input.allocateHost();
    tbl_SerializeFromObject_TD_12856143_input.loadHost();
    Table tbl_SerializeFromObject_TD_12818095_input;
    tbl_SerializeFromObject_TD_12818095_input = Table("item", item_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_12818095_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_12818095_input.addCol("i_brand", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_12818095_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_12818095_input.allocateHost();
    tbl_SerializeFromObject_TD_12818095_input.loadHost();
    Table tbl_SerializeFromObject_TD_12261048_input;
    tbl_SerializeFromObject_TD_12261048_input = Table("catalog_sales", catalog_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_12261048_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_12261048_input.addCol("cs_call_center_sk", 4);
    tbl_SerializeFromObject_TD_12261048_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_12261048_input.addCol("cs_sales_price", 4);
    tbl_SerializeFromObject_TD_12261048_input.allocateHost();
    tbl_SerializeFromObject_TD_12261048_input.loadHost();
    Table tbl_JOIN_INNER_TD_13115189_output("tbl_JOIN_INNER_TD_13115189_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_13115189_output.allocateHost();
    Table tbl_Filter_TD_13806451_output("tbl_Filter_TD_13806451_output", 6100000, 3, "");
    tbl_Filter_TD_13806451_output.allocateHost();
    Table tbl_SerializeFromObject_TD_13444029_input;
    tbl_SerializeFromObject_TD_13444029_input = Table("call_center", call_center_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_13444029_input.addCol("cc_call_center_sk", 4);
    tbl_SerializeFromObject_TD_13444029_input.addCol("cc_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13444029_input.allocateHost();
    tbl_SerializeFromObject_TD_13444029_input.loadHost();
    Table tbl_SerializeFromObject_TD_13178687_input;
    tbl_SerializeFromObject_TD_13178687_input = Table("item", item_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_13178687_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_13178687_input.addCol("i_brand", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13178687_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13178687_input.allocateHost();
    tbl_SerializeFromObject_TD_13178687_input.loadHost();
    Table tbl_SerializeFromObject_TD_13134184_input;
    tbl_SerializeFromObject_TD_13134184_input = Table("catalog_sales", catalog_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_13134184_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_13134184_input.addCol("cs_call_center_sk", 4);
    tbl_SerializeFromObject_TD_13134184_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_13134184_input.addCol("cs_sales_price", 4);
    tbl_SerializeFromObject_TD_13134184_input.allocateHost();
    tbl_SerializeFromObject_TD_13134184_input.loadHost();
    Table tbl_Filter_TD_14929180_output("tbl_Filter_TD_14929180_output", 6100000, 3, "");
    tbl_Filter_TD_14929180_output.allocateHost();
    Table tbl_Filter_TD_14476204_output("tbl_Filter_TD_14476204_output", 6100000, 4, "");
    tbl_Filter_TD_14476204_output.allocateHost();
    Table tbl_SerializeFromObject_TD_14673181_input;
    tbl_SerializeFromObject_TD_14673181_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_14673181_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_14673181_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_14673181_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_14673181_input.allocateHost();
    tbl_SerializeFromObject_TD_14673181_input.loadHost();
    Table tbl_SerializeFromObject_TD_15806479_input;
    tbl_SerializeFromObject_TD_15806479_input = Table("item", item_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_15806479_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_15806479_input.addCol("i_brand", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_15806479_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_15806479_input.allocateHost();
    tbl_SerializeFromObject_TD_15806479_input.loadHost();
    Table tbl_SerializeFromObject_TD_15139586_input;
    tbl_SerializeFromObject_TD_15139586_input = Table("catalog_sales", catalog_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_15139586_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_15139586_input.addCol("cs_call_center_sk", 4);
    tbl_SerializeFromObject_TD_15139586_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_15139586_input.addCol("cs_sales_price", 4);
    tbl_SerializeFromObject_TD_15139586_input.allocateHost();
    tbl_SerializeFromObject_TD_15139586_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    // ****************************** Config **************************** // 
    // *************************** Kernel Setup ************************* // 
    std::cout << std::endl; 
    // ************************** Transfer Engine *********************** // 
    // ****************************** Events **************************** // 
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_14_570040_s, tv_r_Filter_14_570040_e;
    gettimeofday(&tv_r_Filter_14_570040_s, 0);
    SW_Filter_TD_14476204(tbl_SerializeFromObject_TD_15139586_input, tbl_Filter_TD_14476204_output);
    gettimeofday(&tv_r_Filter_14_570040_e, 0);

    struct timeval tv_r_Filter_14_613601_s, tv_r_Filter_14_613601_e;
    gettimeofday(&tv_r_Filter_14_613601_s, 0);
    SW_Filter_TD_14929180(tbl_SerializeFromObject_TD_15806479_input, tbl_Filter_TD_14929180_output);
    gettimeofday(&tv_r_Filter_14_613601_e, 0);

    struct timeval tv_r_Filter_13_155525_s, tv_r_Filter_13_155525_e;
    gettimeofday(&tv_r_Filter_13_155525_s, 0);
    SW_Filter_TD_13806451(tbl_SerializeFromObject_TD_14673181_input, tbl_Filter_TD_13806451_output);
    gettimeofday(&tv_r_Filter_13_155525_e, 0);

    struct timeval tv_r_JOIN_INNER_13_70322_s, tv_r_JOIN_INNER_13_70322_e;
    gettimeofday(&tv_r_JOIN_INNER_13_70322_s, 0);
    SW_JOIN_INNER_TD_13115189(tbl_Filter_TD_14929180_output, tbl_Filter_TD_14476204_output, tbl_JOIN_INNER_TD_13115189_output);
    gettimeofday(&tv_r_JOIN_INNER_13_70322_e, 0);

    struct timeval tv_r_Filter_12_587358_s, tv_r_Filter_12_587358_e;
    gettimeofday(&tv_r_Filter_12_587358_s, 0);
    SW_Filter_TD_12327273(tbl_SerializeFromObject_TD_13134184_input, tbl_Filter_TD_12327273_output);
    gettimeofday(&tv_r_Filter_12_587358_e, 0);

    struct timeval tv_r_Filter_12_760264_s, tv_r_Filter_12_760264_e;
    gettimeofday(&tv_r_Filter_12_760264_s, 0);
    SW_Filter_TD_12627067(tbl_SerializeFromObject_TD_13178687_input, tbl_Filter_TD_12627067_output);
    gettimeofday(&tv_r_Filter_12_760264_e, 0);

    struct timeval tv_r_Filter_12_615986_s, tv_r_Filter_12_615986_e;
    gettimeofday(&tv_r_Filter_12_615986_s, 0);
    SW_Filter_TD_1271702(tbl_SerializeFromObject_TD_13444029_input, tbl_Filter_TD_1271702_output);
    gettimeofday(&tv_r_Filter_12_615986_e, 0);

    struct timeval tv_r_JOIN_INNER_12_777001_s, tv_r_JOIN_INNER_12_777001_e;
    gettimeofday(&tv_r_JOIN_INNER_12_777001_s, 0);
    SW_JOIN_INNER_TD_12967486(tbl_JOIN_INNER_TD_13115189_output, tbl_Filter_TD_13806451_output, tbl_JOIN_INNER_TD_12967486_output);
    gettimeofday(&tv_r_JOIN_INNER_12_777001_e, 0);

    struct timeval tv_r_Filter_11_135155_s, tv_r_Filter_11_135155_e;
    gettimeofday(&tv_r_Filter_11_135155_s, 0);
    SW_Filter_TD_1193880(tbl_SerializeFromObject_TD_12261048_input, tbl_Filter_TD_1193880_output);
    gettimeofday(&tv_r_Filter_11_135155_e, 0);

    struct timeval tv_r_Filter_11_833366_s, tv_r_Filter_11_833366_e;
    gettimeofday(&tv_r_Filter_11_833366_s, 0);
    SW_Filter_TD_11715245(tbl_SerializeFromObject_TD_12818095_input, tbl_Filter_TD_11715245_output);
    gettimeofday(&tv_r_Filter_11_833366_e, 0);

    struct timeval tv_r_Filter_11_817746_s, tv_r_Filter_11_817746_e;
    gettimeofday(&tv_r_Filter_11_817746_s, 0);
    SW_Filter_TD_11656057(tbl_SerializeFromObject_TD_12856143_input, tbl_Filter_TD_11656057_output);
    gettimeofday(&tv_r_Filter_11_817746_e, 0);

    struct timeval tv_r_JOIN_INNER_11_558669_s, tv_r_JOIN_INNER_11_558669_e;
    gettimeofday(&tv_r_JOIN_INNER_11_558669_s, 0);
    SW_JOIN_INNER_TD_11646117(tbl_Filter_TD_12627067_output, tbl_Filter_TD_12327273_output, tbl_JOIN_INNER_TD_11646117_output);
    gettimeofday(&tv_r_JOIN_INNER_11_558669_e, 0);

    struct timeval tv_r_JOIN_INNER_11_299595_s, tv_r_JOIN_INNER_11_299595_e;
    gettimeofday(&tv_r_JOIN_INNER_11_299595_s, 0);
    SW_JOIN_INNER_TD_113015(tbl_JOIN_INNER_TD_12967486_output, tbl_Filter_TD_1271702_output, tbl_JOIN_INNER_TD_113015_output);
    gettimeofday(&tv_r_JOIN_INNER_11_299595_e, 0);

    struct timeval tv_r_Filter_10_500298_s, tv_r_Filter_10_500298_e;
    gettimeofday(&tv_r_Filter_10_500298_s, 0);
    SW_Filter_TD_10827249(tbl_SerializeFromObject_TD_11476877_input, tbl_Filter_TD_10827249_output);
    gettimeofday(&tv_r_Filter_10_500298_e, 0);

    struct timeval tv_r_JOIN_INNER_10_695655_s, tv_r_JOIN_INNER_10_695655_e;
    gettimeofday(&tv_r_JOIN_INNER_10_695655_s, 0);
    SW_JOIN_INNER_TD_10332289(tbl_Filter_TD_11715245_output, tbl_Filter_TD_1193880_output, tbl_JOIN_INNER_TD_10332289_output);
    gettimeofday(&tv_r_JOIN_INNER_10_695655_e, 0);

    struct timeval tv_r_Filter_10_3397_s, tv_r_Filter_10_3397_e;
    gettimeofday(&tv_r_Filter_10_3397_s, 0);
    SW_Filter_TD_10422941(tbl_SerializeFromObject_TD_11945483_input, tbl_Filter_TD_10422941_output);
    gettimeofday(&tv_r_Filter_10_3397_e, 0);

    struct timeval tv_r_JOIN_INNER_10_940939_s, tv_r_JOIN_INNER_10_940939_e;
    gettimeofday(&tv_r_JOIN_INNER_10_940939_s, 0);
    SW_JOIN_INNER_TD_10462332(tbl_JOIN_INNER_TD_11646117_output, tbl_Filter_TD_11656057_output, tbl_JOIN_INNER_TD_10462332_output);
    gettimeofday(&tv_r_JOIN_INNER_10_940939_e, 0);

    struct timeval tv_r_Aggregate_10_627857_s, tv_r_Aggregate_10_627857_e;
    gettimeofday(&tv_r_Aggregate_10_627857_s, 0);
    SW_Aggregate_TD_10376037(tbl_JOIN_INNER_TD_113015_output, tbl_Aggregate_TD_10376037_output);
    gettimeofday(&tv_r_Aggregate_10_627857_e, 0);

    struct timeval tv_r_Filter_9_157574_s, tv_r_Filter_9_157574_e;
    gettimeofday(&tv_r_Filter_9_157574_s, 0);
    SW_Filter_TD_9968509(tbl_SerializeFromObject_TD_10909689_input, tbl_Filter_TD_9968509_output);
    gettimeofday(&tv_r_Filter_9_157574_e, 0);

    struct timeval tv_r_JOIN_INNER_9_798113_s, tv_r_JOIN_INNER_9_798113_e;
    gettimeofday(&tv_r_JOIN_INNER_9_798113_s, 0);
    SW_JOIN_INNER_TD_9514904(tbl_JOIN_INNER_TD_10332289_output, tbl_Filter_TD_10827249_output, tbl_JOIN_INNER_TD_9514904_output);
    gettimeofday(&tv_r_JOIN_INNER_9_798113_e, 0);

    struct timeval tv_r_JOIN_INNER_9_680821_s, tv_r_JOIN_INNER_9_680821_e;
    gettimeofday(&tv_r_JOIN_INNER_9_680821_s, 0);
    SW_JOIN_INNER_TD_9160603(tbl_JOIN_INNER_TD_10462332_output, tbl_Filter_TD_10422941_output, tbl_JOIN_INNER_TD_9160603_output);
    gettimeofday(&tv_r_JOIN_INNER_9_680821_e, 0);

    struct timeval tv_r_Window_9_891420_s, tv_r_Window_9_891420_e;
    gettimeofday(&tv_r_Window_9_891420_s, 0);
    SW_Window_TD_9852472(tbl_Aggregate_TD_10376037_output, tbl_Window_TD_9852472_output);
    gettimeofday(&tv_r_Window_9_891420_e, 0);

    struct timeval tv_r_JOIN_INNER_8_111339_s, tv_r_JOIN_INNER_8_111339_e;
    gettimeofday(&tv_r_JOIN_INNER_8_111339_s, 0);
    SW_JOIN_INNER_TD_8589361(tbl_JOIN_INNER_TD_9514904_output, tbl_Filter_TD_9968509_output, tbl_JOIN_INNER_TD_8589361_output);
    gettimeofday(&tv_r_JOIN_INNER_8_111339_e, 0);

    struct timeval tv_r_Aggregate_8_561147_s, tv_r_Aggregate_8_561147_e;
    gettimeofday(&tv_r_Aggregate_8_561147_s, 0);
    SW_Aggregate_TD_8279717(tbl_JOIN_INNER_TD_9160603_output, tbl_Aggregate_TD_8279717_output);
    gettimeofday(&tv_r_Aggregate_8_561147_e, 0);

    struct timeval tv_r_Filter_8_694977_s, tv_r_Filter_8_694977_e;
    gettimeofday(&tv_r_Filter_8_694977_s, 0);
    SW_Filter_TD_8164128(tbl_Window_TD_9852472_output, tbl_Filter_TD_8164128_output);
    gettimeofday(&tv_r_Filter_8_694977_e, 0);

    struct timeval tv_r_Aggregate_7_303516_s, tv_r_Aggregate_7_303516_e;
    gettimeofday(&tv_r_Aggregate_7_303516_s, 0);
    SW_Aggregate_TD_7738360(tbl_JOIN_INNER_TD_8589361_output, tbl_Aggregate_TD_7738360_output);
    gettimeofday(&tv_r_Aggregate_7_303516_e, 0);

    struct timeval tv_r_Window_7_218022_s, tv_r_Window_7_218022_e;
    gettimeofday(&tv_r_Window_7_218022_s, 0);
    SW_Window_TD_7331027(tbl_Aggregate_TD_8279717_output, tbl_Window_TD_7331027_output);
    gettimeofday(&tv_r_Window_7_218022_e, 0);

    struct timeval tv_r_Window_7_30921_s, tv_r_Window_7_30921_e;
    gettimeofday(&tv_r_Window_7_30921_s, 0);
    SW_Window_TD_7405474(tbl_Filter_TD_8164128_output, tbl_Window_TD_7405474_output);
    gettimeofday(&tv_r_Window_7_30921_e, 0);

    struct timeval tv_r_Window_6_269862_s, tv_r_Window_6_269862_e;
    gettimeofday(&tv_r_Window_6_269862_s, 0);
    SW_Window_TD_6547937(tbl_Aggregate_TD_7738360_output, tbl_Window_TD_6547937_output);
    gettimeofday(&tv_r_Window_6_269862_e, 0);

    struct timeval tv_r_Project_6_625629_s, tv_r_Project_6_625629_e;
    gettimeofday(&tv_r_Project_6_625629_s, 0);
    SW_Project_TD_6224007(tbl_Window_TD_7331027_output, tbl_Project_TD_6224007_output);
    gettimeofday(&tv_r_Project_6_625629_e, 0);

    struct timeval tv_r_Filter_6_782516_s, tv_r_Filter_6_782516_e;
    gettimeofday(&tv_r_Filter_6_782516_s, 0);
    SW_Filter_TD_6667714(tbl_Window_TD_7405474_output, tbl_Filter_TD_6667714_output);
    gettimeofday(&tv_r_Filter_6_782516_e, 0);

    struct timeval tv_r_Project_5_568899_s, tv_r_Project_5_568899_e;
    gettimeofday(&tv_r_Project_5_568899_s, 0);
    SW_Project_TD_5357390(tbl_Window_TD_6547937_output, tbl_Project_TD_5357390_output);
    gettimeofday(&tv_r_Project_5_568899_e, 0);

    struct timeval tv_r_JOIN_INNER_5_508344_s, tv_r_JOIN_INNER_5_508344_e;
    gettimeofday(&tv_r_JOIN_INNER_5_508344_s, 0);
    SW_JOIN_INNER_TD_5241974(tbl_Filter_TD_6667714_output, tbl_Project_TD_6224007_output, tbl_JOIN_INNER_TD_5241974_output);
    gettimeofday(&tv_r_JOIN_INNER_5_508344_e, 0);

    struct timeval tv_r_JOIN_INNER_4_530876_s, tv_r_JOIN_INNER_4_530876_e;
    gettimeofday(&tv_r_JOIN_INNER_4_530876_s, 0);
    SW_JOIN_INNER_TD_4632128(tbl_JOIN_INNER_TD_5241974_output, tbl_Project_TD_5357390_output, tbl_JOIN_INNER_TD_4632128_output);
    gettimeofday(&tv_r_JOIN_INNER_4_530876_e, 0);

    struct timeval tv_r_Project_3_431145_s, tv_r_Project_3_431145_e;
    gettimeofday(&tv_r_Project_3_431145_s, 0);
    SW_Project_TD_3902436(tbl_JOIN_INNER_TD_4632128_output, tbl_Project_TD_3902436_output);
    gettimeofday(&tv_r_Project_3_431145_e, 0);

    struct timeval tv_r_Sort_2_186539_s, tv_r_Sort_2_186539_e;
    gettimeofday(&tv_r_Sort_2_186539_s, 0);
    SW_Sort_TD_2562001(tbl_Project_TD_3902436_output, tbl_Sort_TD_2562001_output);
    gettimeofday(&tv_r_Sort_2_186539_e, 0);

    struct timeval tv_r_LocalLimit_1_415147_s, tv_r_LocalLimit_1_415147_e;
    gettimeofday(&tv_r_LocalLimit_1_415147_s, 0);
    SW_LocalLimit_TD_130890(tbl_Sort_TD_2562001_output, tbl_LocalLimit_TD_130890_output);
    gettimeofday(&tv_r_LocalLimit_1_415147_e, 0);

    struct timeval tv_r_GlobalLimit_0_436166_s, tv_r_GlobalLimit_0_436166_e;
    gettimeofday(&tv_r_GlobalLimit_0_436166_s, 0);
    SW_GlobalLimit_TD_0684633(tbl_LocalLimit_TD_130890_output, tbl_GlobalLimit_TD_0684633_output);
    gettimeofday(&tv_r_GlobalLimit_0_436166_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_14: " << tvdiff(&tv_r_Filter_14_570040_s, &tv_r_Filter_14_570040_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_15139586_input: " << tbl_SerializeFromObject_TD_15139586_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_14: " << tvdiff(&tv_r_Filter_14_613601_s, &tv_r_Filter_14_613601_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_15806479_input: " << tbl_SerializeFromObject_TD_15806479_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_13: " << tvdiff(&tv_r_Filter_13_155525_s, &tv_r_Filter_13_155525_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_14673181_input: " << tbl_SerializeFromObject_TD_14673181_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_13: " << tvdiff(&tv_r_JOIN_INNER_13_70322_s, &tv_r_JOIN_INNER_13_70322_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_14929180_output: " << tbl_Filter_TD_14929180_output.getNumRow() << " " << "tbl_Filter_TD_14476204_output: " << tbl_Filter_TD_14476204_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_587358_s, &tv_r_Filter_12_587358_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13134184_input: " << tbl_SerializeFromObject_TD_13134184_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_760264_s, &tv_r_Filter_12_760264_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13178687_input: " << tbl_SerializeFromObject_TD_13178687_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_615986_s, &tv_r_Filter_12_615986_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13444029_input: " << tbl_SerializeFromObject_TD_13444029_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_12: " << tvdiff(&tv_r_JOIN_INNER_12_777001_s, &tv_r_JOIN_INNER_12_777001_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_13115189_output: " << tbl_JOIN_INNER_TD_13115189_output.getNumRow() << " " << "tbl_Filter_TD_13806451_output: " << tbl_Filter_TD_13806451_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_135155_s, &tv_r_Filter_11_135155_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12261048_input: " << tbl_SerializeFromObject_TD_12261048_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_833366_s, &tv_r_Filter_11_833366_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12818095_input: " << tbl_SerializeFromObject_TD_12818095_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_817746_s, &tv_r_Filter_11_817746_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12856143_input: " << tbl_SerializeFromObject_TD_12856143_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_11: " << tvdiff(&tv_r_JOIN_INNER_11_558669_s, &tv_r_JOIN_INNER_11_558669_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_12627067_output: " << tbl_Filter_TD_12627067_output.getNumRow() << " " << "tbl_Filter_TD_12327273_output: " << tbl_Filter_TD_12327273_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_11: " << tvdiff(&tv_r_JOIN_INNER_11_299595_s, &tv_r_JOIN_INNER_11_299595_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_12967486_output: " << tbl_JOIN_INNER_TD_12967486_output.getNumRow() << " " << "tbl_Filter_TD_1271702_output: " << tbl_Filter_TD_1271702_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_500298_s, &tv_r_Filter_10_500298_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11476877_input: " << tbl_SerializeFromObject_TD_11476877_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_695655_s, &tv_r_JOIN_INNER_10_695655_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11715245_output: " << tbl_Filter_TD_11715245_output.getNumRow() << " " << "tbl_Filter_TD_1193880_output: " << tbl_Filter_TD_1193880_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_3397_s, &tv_r_Filter_10_3397_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11945483_input: " << tbl_SerializeFromObject_TD_11945483_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_940939_s, &tv_r_JOIN_INNER_10_940939_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_11646117_output: " << tbl_JOIN_INNER_TD_11646117_output.getNumRow() << " " << "tbl_Filter_TD_11656057_output: " << tbl_Filter_TD_11656057_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_10: " << tvdiff(&tv_r_Aggregate_10_627857_s, &tv_r_Aggregate_10_627857_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_113015_output: " << tbl_JOIN_INNER_TD_113015_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_157574_s, &tv_r_Filter_9_157574_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10909689_input: " << tbl_SerializeFromObject_TD_10909689_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_798113_s, &tv_r_JOIN_INNER_9_798113_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10332289_output: " << tbl_JOIN_INNER_TD_10332289_output.getNumRow() << " " << "tbl_Filter_TD_10827249_output: " << tbl_Filter_TD_10827249_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_680821_s, &tv_r_JOIN_INNER_9_680821_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10462332_output: " << tbl_JOIN_INNER_TD_10462332_output.getNumRow() << " " << "tbl_Filter_TD_10422941_output: " << tbl_Filter_TD_10422941_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_9: " << tvdiff(&tv_r_Window_9_891420_s, &tv_r_Window_9_891420_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_10376037_output: " << tbl_Aggregate_TD_10376037_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_111339_s, &tv_r_JOIN_INNER_8_111339_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9514904_output: " << tbl_JOIN_INNER_TD_9514904_output.getNumRow() << " " << "tbl_Filter_TD_9968509_output: " << tbl_Filter_TD_9968509_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_8: " << tvdiff(&tv_r_Aggregate_8_561147_s, &tv_r_Aggregate_8_561147_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9160603_output: " << tbl_JOIN_INNER_TD_9160603_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_694977_s, &tv_r_Filter_8_694977_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_9852472_output: " << tbl_Window_TD_9852472_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_7: " << tvdiff(&tv_r_Aggregate_7_303516_s, &tv_r_Aggregate_7_303516_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8589361_output: " << tbl_JOIN_INNER_TD_8589361_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_7: " << tvdiff(&tv_r_Window_7_218022_s, &tv_r_Window_7_218022_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_8279717_output: " << tbl_Aggregate_TD_8279717_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_7: " << tvdiff(&tv_r_Window_7_30921_s, &tv_r_Window_7_30921_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8164128_output: " << tbl_Filter_TD_8164128_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_6: " << tvdiff(&tv_r_Window_6_269862_s, &tv_r_Window_6_269862_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_7738360_output: " << tbl_Aggregate_TD_7738360_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_6: " << tvdiff(&tv_r_Project_6_625629_s, &tv_r_Project_6_625629_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_7331027_output: " << tbl_Window_TD_7331027_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_782516_s, &tv_r_Filter_6_782516_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_7405474_output: " << tbl_Window_TD_7405474_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_5: " << tvdiff(&tv_r_Project_5_568899_s, &tv_r_Project_5_568899_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_6547937_output: " << tbl_Window_TD_6547937_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_508344_s, &tv_r_JOIN_INNER_5_508344_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6667714_output: " << tbl_Filter_TD_6667714_output.getNumRow() << " " << "tbl_Project_TD_6224007_output: " << tbl_Project_TD_6224007_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_530876_s, &tv_r_JOIN_INNER_4_530876_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5241974_output: " << tbl_JOIN_INNER_TD_5241974_output.getNumRow() << " " << "tbl_Project_TD_5357390_output: " << tbl_Project_TD_5357390_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_3: " << tvdiff(&tv_r_Project_3_431145_s, &tv_r_Project_3_431145_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4632128_output: " << tbl_JOIN_INNER_TD_4632128_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_186539_s, &tv_r_Sort_2_186539_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_3902436_output: " << tbl_Project_TD_3902436_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_415147_s, &tv_r_LocalLimit_1_415147_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2562001_output: " << tbl_Sort_TD_2562001_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_436166_s, &tv_r_GlobalLimit_0_436166_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_130890_output: " << tbl_LocalLimit_TD_130890_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 3.1851258 * 1000 << "ms" << std::endl; 
    return 0; 
}
