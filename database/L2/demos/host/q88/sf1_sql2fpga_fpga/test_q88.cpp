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

#include "cfgFunc_q88.hpp" 
#include "q88.hpp" 

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
    std::cout << "NOTE:running query #88\n."; 
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
    cl::Device device_h = devices[0]; 
    // Create context_h and command queue for selected device 
    cl::Context context_h(device_h); 
    cl::CommandQueue q_h(context_h, device_h, CL_QUEUE_PROFILING_ENABLE | CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE); 
    std::string devName_h = device_h.getInfo<CL_DEVICE_NAME>(); 
    std::cout << "Selected Device " << devName_h << "\n"; 
    cl::Program::Binaries xclBins_h = xcl::import_binary_file(xclbin_path_h); 
    std::vector<cl::Device> devices_h; 
    devices_h.push_back(device_h); 
    cl::Program program_h(context_h, devices_h, xclBins_h); 
    // ****************************** Tables **************************** // 
    Table tbl_JOIN_CROSS_TD_086561_output("tbl_JOIN_CROSS_TD_086561_output", 6100000, 8, "");
    tbl_JOIN_CROSS_TD_086561_output.allocateHost();
    Table tbl_JOIN_CROSS_TD_1212895_output("tbl_JOIN_CROSS_TD_1212895_output", 6100000, 7, "");
    tbl_JOIN_CROSS_TD_1212895_output.allocateHost();
    Table tbl_Aggregate_TD_1840294_output("tbl_Aggregate_TD_1840294_output", 6100000, 1, "");
    tbl_Aggregate_TD_1840294_output.allocateHost();
    Table tbl_JOIN_CROSS_TD_2364608_output("tbl_JOIN_CROSS_TD_2364608_output", 6100000, 6, "");
    tbl_JOIN_CROSS_TD_2364608_output.allocateHost();
    Table tbl_Aggregate_TD_2384017_output("tbl_Aggregate_TD_2384017_output", 6100000, 1, "");
    tbl_Aggregate_TD_2384017_output.allocateHost();
    Table tbl_JOIN_INNER_TD_2645078_output("tbl_JOIN_INNER_TD_2645078_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_2645078_output.allocateHost();
    Table tbl_JOIN_CROSS_TD_3927976_output("tbl_JOIN_CROSS_TD_3927976_output", 6100000, 5, "");
    tbl_JOIN_CROSS_TD_3927976_output.allocateHost();
    Table tbl_Aggregate_TD_3629204_output("tbl_Aggregate_TD_3629204_output", 6100000, 1, "");
    tbl_Aggregate_TD_3629204_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3912575_output("tbl_JOIN_INNER_TD_3912575_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_3912575_output.allocateHost();
    Table tbl_JOIN_INNER_TD_332118_output("tbl_JOIN_INNER_TD_332118_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_332118_output.allocateHost();
    Table tbl_Filter_TD_3373394_output("tbl_Filter_TD_3373394_output", 6100000, 1, "");
    tbl_Filter_TD_3373394_output.allocateHost();
    Table tbl_JOIN_CROSS_TD_4414428_output("tbl_JOIN_CROSS_TD_4414428_output", 6100000, 4, "");
    tbl_JOIN_CROSS_TD_4414428_output.allocateHost();
    Table tbl_Aggregate_TD_4249092_output("tbl_Aggregate_TD_4249092_output", 6100000, 1, "");
    tbl_Aggregate_TD_4249092_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4705166_output("tbl_JOIN_INNER_TD_4705166_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_4705166_output.allocateHost();
    Table tbl_JOIN_INNER_TD_421336_output("tbl_JOIN_INNER_TD_421336_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_421336_output.allocateHost();
    Table tbl_Filter_TD_4532889_output("tbl_Filter_TD_4532889_output", 6100000, 1, "");
    tbl_Filter_TD_4532889_output.allocateHost();
    Table tbl_JOIN_INNER_TD_444226_output("tbl_JOIN_INNER_TD_444226_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_444226_output.allocateHost();
    Table tbl_Filter_TD_4107367_output("tbl_Filter_TD_4107367_output", 6100000, 1, "");
    tbl_Filter_TD_4107367_output.allocateHost();
    Table tbl_SerializeFromObject_TD_4330522_input;
    tbl_SerializeFromObject_TD_4330522_input = Table("store", store_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_4330522_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_4330522_input.addCol("s_store_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_4330522_input.allocateHost();
    tbl_SerializeFromObject_TD_4330522_input.loadHost();
    Table tbl_JOIN_CROSS_TD_5759888_output("tbl_JOIN_CROSS_TD_5759888_output", 6100000, 3, "");
    tbl_JOIN_CROSS_TD_5759888_output.allocateHost();
    Table tbl_Aggregate_TD_5162264_output("tbl_Aggregate_TD_5162264_output", 6100000, 1, "");
    tbl_Aggregate_TD_5162264_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5336669_output("tbl_JOIN_INNER_TD_5336669_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_5336669_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5823975_output("tbl_JOIN_INNER_TD_5823975_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_5823975_output.allocateHost();
    Table tbl_Filter_TD_5329556_output("tbl_Filter_TD_5329556_output", 6100000, 1, "");
    tbl_Filter_TD_5329556_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5600859_output("tbl_JOIN_INNER_TD_5600859_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_5600859_output.allocateHost();
    Table tbl_Filter_TD_5944573_output("tbl_Filter_TD_5944573_output", 6100000, 1, "");
    tbl_Filter_TD_5944573_output.allocateHost();
    Table tbl_SerializeFromObject_TD_5893686_input;
    tbl_SerializeFromObject_TD_5893686_input = Table("store", store_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_5893686_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_5893686_input.addCol("s_store_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_5893686_input.allocateHost();
    tbl_SerializeFromObject_TD_5893686_input.loadHost();
    Table tbl_Filter_TD_5906846_output("tbl_Filter_TD_5906846_output", 6100000, 3, "");
    tbl_Filter_TD_5906846_output.allocateHost();
    Table tbl_Filter_TD_5562669_output("tbl_Filter_TD_5562669_output", 6100000, 1, "");
    tbl_Filter_TD_5562669_output.allocateHost();
    Table tbl_SerializeFromObject_TD_5555205_input;
    tbl_SerializeFromObject_TD_5555205_input = Table("time_dim", time_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_5555205_input.addCol("t_time_sk", 4);
    tbl_SerializeFromObject_TD_5555205_input.addCol("t_hour", 4);
    tbl_SerializeFromObject_TD_5555205_input.addCol("t_minute", 4);
    tbl_SerializeFromObject_TD_5555205_input.allocateHost();
    tbl_SerializeFromObject_TD_5555205_input.loadHost();
    Table tbl_JOIN_CROSS_TD_6160501_output("tbl_JOIN_CROSS_TD_6160501_output", 6100000, 2, "");
    tbl_JOIN_CROSS_TD_6160501_output.allocateHost();
    Table tbl_Aggregate_TD_6953350_output("tbl_Aggregate_TD_6953350_output", 6100000, 1, "");
    tbl_Aggregate_TD_6953350_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6313985_output("tbl_JOIN_INNER_TD_6313985_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_6313985_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6298318_output("tbl_JOIN_INNER_TD_6298318_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_6298318_output.allocateHost();
    Table tbl_Filter_TD_6190390_output("tbl_Filter_TD_6190390_output", 6100000, 1, "");
    tbl_Filter_TD_6190390_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6912217_output("tbl_JOIN_INNER_TD_6912217_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_6912217_output.allocateHost();
    Table tbl_Filter_TD_621706_output("tbl_Filter_TD_621706_output", 6100000, 1, "");
    tbl_Filter_TD_621706_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6424078_input;
    tbl_SerializeFromObject_TD_6424078_input = Table("store", store_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_6424078_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_6424078_input.addCol("s_store_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6424078_input.allocateHost();
    tbl_SerializeFromObject_TD_6424078_input.loadHost();
    Table tbl_Filter_TD_6868889_output("tbl_Filter_TD_6868889_output", 6100000, 3, "");
    tbl_Filter_TD_6868889_output.allocateHost();
    Table tbl_Filter_TD_6510134_output("tbl_Filter_TD_6510134_output", 6100000, 1, "");
    tbl_Filter_TD_6510134_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6791061_input;
    tbl_SerializeFromObject_TD_6791061_input = Table("time_dim", time_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_6791061_input.addCol("t_time_sk", 4);
    tbl_SerializeFromObject_TD_6791061_input.addCol("t_hour", 4);
    tbl_SerializeFromObject_TD_6791061_input.addCol("t_minute", 4);
    tbl_SerializeFromObject_TD_6791061_input.allocateHost();
    tbl_SerializeFromObject_TD_6791061_input.loadHost();
    Table tbl_SerializeFromObject_TD_681115_input;
    tbl_SerializeFromObject_TD_681115_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_681115_input.addCol("ss_sold_time_sk", 4);
    tbl_SerializeFromObject_TD_681115_input.addCol("ss_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_681115_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_681115_input.allocateHost();
    tbl_SerializeFromObject_TD_681115_input.loadHost();
    Table tbl_SerializeFromObject_TD_6203791_input;
    tbl_SerializeFromObject_TD_6203791_input = Table("household_demographics", household_demographics_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_6203791_input.addCol("hd_demo_sk", 4);
    tbl_SerializeFromObject_TD_6203791_input.addCol("hd_dep_count", 4);
    tbl_SerializeFromObject_TD_6203791_input.addCol("hd_vehicle_count", 4);
    tbl_SerializeFromObject_TD_6203791_input.allocateHost();
    tbl_SerializeFromObject_TD_6203791_input.loadHost();
    Table tbl_Aggregate_TD_7359641_output("tbl_Aggregate_TD_7359641_output", 6100000, 1, "");
    tbl_Aggregate_TD_7359641_output.allocateHost();
    Table tbl_Aggregate_TD_7988832_output("tbl_Aggregate_TD_7988832_output", 6100000, 1, "");
    tbl_Aggregate_TD_7988832_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7143737_output("tbl_JOIN_INNER_TD_7143737_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_7143737_output.allocateHost();
    Table tbl_JOIN_INNER_TD_733731_output("tbl_JOIN_INNER_TD_733731_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_733731_output.allocateHost();
    Table tbl_Filter_TD_725548_output("tbl_Filter_TD_725548_output", 6100000, 1, "");
    tbl_Filter_TD_725548_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7284355_output("tbl_JOIN_INNER_TD_7284355_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_7284355_output.allocateHost();
    Table tbl_Filter_TD_7632249_output("tbl_Filter_TD_7632249_output", 6100000, 1, "");
    tbl_Filter_TD_7632249_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7674429_input;
    tbl_SerializeFromObject_TD_7674429_input = Table("store", store_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7674429_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_7674429_input.addCol("s_store_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7674429_input.allocateHost();
    tbl_SerializeFromObject_TD_7674429_input.loadHost();
    Table tbl_Filter_TD_7710378_output("tbl_Filter_TD_7710378_output", 6100000, 3, "");
    tbl_Filter_TD_7710378_output.allocateHost();
    Table tbl_Filter_TD_7643990_output("tbl_Filter_TD_7643990_output", 6100000, 1, "");
    tbl_Filter_TD_7643990_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7679477_input;
    tbl_SerializeFromObject_TD_7679477_input = Table("time_dim", time_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7679477_input.addCol("t_time_sk", 4);
    tbl_SerializeFromObject_TD_7679477_input.addCol("t_hour", 4);
    tbl_SerializeFromObject_TD_7679477_input.addCol("t_minute", 4);
    tbl_SerializeFromObject_TD_7679477_input.allocateHost();
    tbl_SerializeFromObject_TD_7679477_input.loadHost();
    Table tbl_SerializeFromObject_TD_7705973_input;
    tbl_SerializeFromObject_TD_7705973_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7705973_input.addCol("ss_sold_time_sk", 4);
    tbl_SerializeFromObject_TD_7705973_input.addCol("ss_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_7705973_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_7705973_input.allocateHost();
    tbl_SerializeFromObject_TD_7705973_input.loadHost();
    Table tbl_SerializeFromObject_TD_7430105_input;
    tbl_SerializeFromObject_TD_7430105_input = Table("household_demographics", household_demographics_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7430105_input.addCol("hd_demo_sk", 4);
    tbl_SerializeFromObject_TD_7430105_input.addCol("hd_dep_count", 4);
    tbl_SerializeFromObject_TD_7430105_input.addCol("hd_vehicle_count", 4);
    tbl_SerializeFromObject_TD_7430105_input.allocateHost();
    tbl_SerializeFromObject_TD_7430105_input.loadHost();
    Table tbl_JOIN_INNER_TD_8444716_output("tbl_JOIN_INNER_TD_8444716_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_8444716_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8393357_output("tbl_JOIN_INNER_TD_8393357_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_8393357_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8123925_output("tbl_JOIN_INNER_TD_8123925_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_8123925_output.allocateHost();
    Table tbl_Filter_TD_8558615_output("tbl_Filter_TD_8558615_output", 6100000, 1, "");
    tbl_Filter_TD_8558615_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8295220_output("tbl_JOIN_INNER_TD_8295220_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_8295220_output.allocateHost();
    Table tbl_Filter_TD_8123668_output("tbl_Filter_TD_8123668_output", 6100000, 1, "");
    tbl_Filter_TD_8123668_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8488467_input;
    tbl_SerializeFromObject_TD_8488467_input = Table("store", store_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8488467_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_8488467_input.addCol("s_store_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8488467_input.allocateHost();
    tbl_SerializeFromObject_TD_8488467_input.loadHost();
    Table tbl_Filter_TD_8395884_output("tbl_Filter_TD_8395884_output", 6100000, 3, "");
    tbl_Filter_TD_8395884_output.allocateHost();
    Table tbl_Filter_TD_8550963_output("tbl_Filter_TD_8550963_output", 6100000, 1, "");
    tbl_Filter_TD_8550963_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8210534_input;
    tbl_SerializeFromObject_TD_8210534_input = Table("time_dim", time_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8210534_input.addCol("t_time_sk", 4);
    tbl_SerializeFromObject_TD_8210534_input.addCol("t_hour", 4);
    tbl_SerializeFromObject_TD_8210534_input.addCol("t_minute", 4);
    tbl_SerializeFromObject_TD_8210534_input.allocateHost();
    tbl_SerializeFromObject_TD_8210534_input.loadHost();
    Table tbl_SerializeFromObject_TD_8678517_input;
    tbl_SerializeFromObject_TD_8678517_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8678517_input.addCol("ss_sold_time_sk", 4);
    tbl_SerializeFromObject_TD_8678517_input.addCol("ss_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_8678517_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_8678517_input.allocateHost();
    tbl_SerializeFromObject_TD_8678517_input.loadHost();
    Table tbl_SerializeFromObject_TD_8986814_input;
    tbl_SerializeFromObject_TD_8986814_input = Table("household_demographics", household_demographics_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8986814_input.addCol("hd_demo_sk", 4);
    tbl_SerializeFromObject_TD_8986814_input.addCol("hd_dep_count", 4);
    tbl_SerializeFromObject_TD_8986814_input.addCol("hd_vehicle_count", 4);
    tbl_SerializeFromObject_TD_8986814_input.allocateHost();
    tbl_SerializeFromObject_TD_8986814_input.loadHost();
    Table tbl_JOIN_INNER_TD_9537683_output("tbl_JOIN_INNER_TD_9537683_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_9537683_output.allocateHost();
    Table tbl_Filter_TD_9319524_output("tbl_Filter_TD_9319524_output", 6100000, 1, "");
    tbl_Filter_TD_9319524_output.allocateHost();
    Table tbl_JOIN_INNER_TD_9681030_output("tbl_JOIN_INNER_TD_9681030_output", 6100000, 1, "");
    tbl_JOIN_INNER_TD_9681030_output.allocateHost();
    Table tbl_Filter_TD_9704552_output("tbl_Filter_TD_9704552_output", 6100000, 1, "");
    tbl_Filter_TD_9704552_output.allocateHost();
    Table tbl_JOIN_INNER_TD_9323172_output("tbl_JOIN_INNER_TD_9323172_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_9323172_output.allocateHost();
    Table tbl_Filter_TD_9706559_output("tbl_Filter_TD_9706559_output", 6100000, 1, "");
    tbl_Filter_TD_9706559_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9568378_input;
    tbl_SerializeFromObject_TD_9568378_input = Table("store", store_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9568378_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_9568378_input.addCol("s_store_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9568378_input.allocateHost();
    tbl_SerializeFromObject_TD_9568378_input.loadHost();
    Table tbl_Filter_TD_9731454_output("tbl_Filter_TD_9731454_output", 6100000, 3, "");
    tbl_Filter_TD_9731454_output.allocateHost();
    Table tbl_Filter_TD_9721109_output("tbl_Filter_TD_9721109_output", 6100000, 1, "");
    tbl_Filter_TD_9721109_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9320282_input;
    tbl_SerializeFromObject_TD_9320282_input = Table("time_dim", time_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9320282_input.addCol("t_time_sk", 4);
    tbl_SerializeFromObject_TD_9320282_input.addCol("t_hour", 4);
    tbl_SerializeFromObject_TD_9320282_input.addCol("t_minute", 4);
    tbl_SerializeFromObject_TD_9320282_input.allocateHost();
    tbl_SerializeFromObject_TD_9320282_input.loadHost();
    Table tbl_SerializeFromObject_TD_910318_input;
    tbl_SerializeFromObject_TD_910318_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_910318_input.addCol("ss_sold_time_sk", 4);
    tbl_SerializeFromObject_TD_910318_input.addCol("ss_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_910318_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_910318_input.allocateHost();
    tbl_SerializeFromObject_TD_910318_input.loadHost();
    Table tbl_SerializeFromObject_TD_9324654_input;
    tbl_SerializeFromObject_TD_9324654_input = Table("household_demographics", household_demographics_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9324654_input.addCol("hd_demo_sk", 4);
    tbl_SerializeFromObject_TD_9324654_input.addCol("hd_dep_count", 4);
    tbl_SerializeFromObject_TD_9324654_input.addCol("hd_vehicle_count", 4);
    tbl_SerializeFromObject_TD_9324654_input.allocateHost();
    tbl_SerializeFromObject_TD_9324654_input.loadHost();
    Table tbl_JOIN_INNER_TD_10970681_output("tbl_JOIN_INNER_TD_10970681_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_10970681_output.allocateHost();
    Table tbl_Filter_TD_10407068_output("tbl_Filter_TD_10407068_output", 6100000, 1, "");
    tbl_Filter_TD_10407068_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10826019_input;
    tbl_SerializeFromObject_TD_10826019_input = Table("store", store_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10826019_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_10826019_input.addCol("s_store_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10826019_input.allocateHost();
    tbl_SerializeFromObject_TD_10826019_input.loadHost();
    Table tbl_JOIN_INNER_TD_10472652_output("tbl_JOIN_INNER_TD_10472652_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_10472652_output.allocateHost();
    Table tbl_Filter_TD_10773494_output("tbl_Filter_TD_10773494_output", 6100000, 1, "");
    tbl_Filter_TD_10773494_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10678969_input;
    tbl_SerializeFromObject_TD_10678969_input = Table("store", store_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10678969_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_10678969_input.addCol("s_store_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10678969_input.allocateHost();
    tbl_SerializeFromObject_TD_10678969_input.loadHost();
    Table tbl_Filter_TD_10930230_output("tbl_Filter_TD_10930230_output", 6100000, 3, "");
    tbl_Filter_TD_10930230_output.allocateHost();
    Table tbl_Filter_TD_10112030_output("tbl_Filter_TD_10112030_output", 6100000, 1, "");
    tbl_Filter_TD_10112030_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10560310_input;
    tbl_SerializeFromObject_TD_10560310_input = Table("time_dim", time_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10560310_input.addCol("t_time_sk", 4);
    tbl_SerializeFromObject_TD_10560310_input.addCol("t_hour", 4);
    tbl_SerializeFromObject_TD_10560310_input.addCol("t_minute", 4);
    tbl_SerializeFromObject_TD_10560310_input.allocateHost();
    tbl_SerializeFromObject_TD_10560310_input.loadHost();
    Table tbl_SerializeFromObject_TD_1039924_input;
    tbl_SerializeFromObject_TD_1039924_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_1039924_input.addCol("ss_sold_time_sk", 4);
    tbl_SerializeFromObject_TD_1039924_input.addCol("ss_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_1039924_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_1039924_input.allocateHost();
    tbl_SerializeFromObject_TD_1039924_input.loadHost();
    Table tbl_SerializeFromObject_TD_10384773_input;
    tbl_SerializeFromObject_TD_10384773_input = Table("household_demographics", household_demographics_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10384773_input.addCol("hd_demo_sk", 4);
    tbl_SerializeFromObject_TD_10384773_input.addCol("hd_dep_count", 4);
    tbl_SerializeFromObject_TD_10384773_input.addCol("hd_vehicle_count", 4);
    tbl_SerializeFromObject_TD_10384773_input.allocateHost();
    tbl_SerializeFromObject_TD_10384773_input.loadHost();
    Table tbl_Filter_TD_11825044_output("tbl_Filter_TD_11825044_output", 6100000, 3, "");
    tbl_Filter_TD_11825044_output.allocateHost();
    Table tbl_Filter_TD_11863624_output("tbl_Filter_TD_11863624_output", 6100000, 1, "");
    tbl_Filter_TD_11863624_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11139299_input;
    tbl_SerializeFromObject_TD_11139299_input = Table("time_dim", time_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11139299_input.addCol("t_time_sk", 4);
    tbl_SerializeFromObject_TD_11139299_input.addCol("t_hour", 4);
    tbl_SerializeFromObject_TD_11139299_input.addCol("t_minute", 4);
    tbl_SerializeFromObject_TD_11139299_input.allocateHost();
    tbl_SerializeFromObject_TD_11139299_input.loadHost();
    Table tbl_Filter_TD_11494174_output("tbl_Filter_TD_11494174_output", 6100000, 3, "");
    tbl_Filter_TD_11494174_output.allocateHost();
    Table tbl_Filter_TD_11501915_output("tbl_Filter_TD_11501915_output", 6100000, 1, "");
    tbl_Filter_TD_11501915_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11646343_input;
    tbl_SerializeFromObject_TD_11646343_input = Table("time_dim", time_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11646343_input.addCol("t_time_sk", 4);
    tbl_SerializeFromObject_TD_11646343_input.addCol("t_hour", 4);
    tbl_SerializeFromObject_TD_11646343_input.addCol("t_minute", 4);
    tbl_SerializeFromObject_TD_11646343_input.allocateHost();
    tbl_SerializeFromObject_TD_11646343_input.loadHost();
    Table tbl_SerializeFromObject_TD_11840076_input;
    tbl_SerializeFromObject_TD_11840076_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11840076_input.addCol("ss_sold_time_sk", 4);
    tbl_SerializeFromObject_TD_11840076_input.addCol("ss_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_11840076_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_11840076_input.allocateHost();
    tbl_SerializeFromObject_TD_11840076_input.loadHost();
    Table tbl_SerializeFromObject_TD_11248910_input;
    tbl_SerializeFromObject_TD_11248910_input = Table("household_demographics", household_demographics_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11248910_input.addCol("hd_demo_sk", 4);
    tbl_SerializeFromObject_TD_11248910_input.addCol("hd_dep_count", 4);
    tbl_SerializeFromObject_TD_11248910_input.addCol("hd_vehicle_count", 4);
    tbl_SerializeFromObject_TD_11248910_input.allocateHost();
    tbl_SerializeFromObject_TD_11248910_input.loadHost();
    Table tbl_SerializeFromObject_TD_12473315_input;
    tbl_SerializeFromObject_TD_12473315_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_12473315_input.addCol("ss_sold_time_sk", 4);
    tbl_SerializeFromObject_TD_12473315_input.addCol("ss_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_12473315_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_12473315_input.allocateHost();
    tbl_SerializeFromObject_TD_12473315_input.loadHost();
    Table tbl_SerializeFromObject_TD_12427169_input;
    tbl_SerializeFromObject_TD_12427169_input = Table("household_demographics", household_demographics_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_12427169_input.addCol("hd_demo_sk", 4);
    tbl_SerializeFromObject_TD_12427169_input.addCol("hd_dep_count", 4);
    tbl_SerializeFromObject_TD_12427169_input.addCol("hd_vehicle_count", 4);
    tbl_SerializeFromObject_TD_12427169_input.allocateHost();
    tbl_SerializeFromObject_TD_12427169_input.loadHost();
    Table tbl_SerializeFromObject_TD_12265143_input;
    tbl_SerializeFromObject_TD_12265143_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_12265143_input.addCol("ss_sold_time_sk", 4);
    tbl_SerializeFromObject_TD_12265143_input.addCol("ss_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_12265143_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_12265143_input.allocateHost();
    tbl_SerializeFromObject_TD_12265143_input.loadHost();
    Table tbl_SerializeFromObject_TD_1233021_input;
    tbl_SerializeFromObject_TD_1233021_input = Table("household_demographics", household_demographics_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_1233021_input.addCol("hd_demo_sk", 4);
    tbl_SerializeFromObject_TD_1233021_input.addCol("hd_dep_count", 4);
    tbl_SerializeFromObject_TD_1233021_input.addCol("hd_vehicle_count", 4);
    tbl_SerializeFromObject_TD_1233021_input.allocateHost();
    tbl_SerializeFromObject_TD_1233021_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_2645078_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_3912575_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_332118_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_3373394_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_4705166_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_421336_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_4532889_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_444226_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_4107367_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_5336669_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_5823975_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_5329556_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_5600859_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_5944573_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_5906846_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_5562669_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_6313985_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_6298318_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_6190390_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_6912217_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_621706_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_6868889_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_6510134_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_7143737_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_733731_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_725548_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_7284355_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_7632249_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_7710378_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_7643990_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8444716_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8393357_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8123925_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8558615_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8295220_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8123668_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8395884_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8550963_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_9537683_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9319524_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_9681030_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9704552_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_9323172_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9706559_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9731454_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9721109_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_10970681_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10407068_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_10472652_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10773494_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10930230_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10112030_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11825044_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11863624_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11494174_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11501915_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_2645078_cmds;
    cfg_JOIN_INNER_TD_2645078_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_2645078_gqe_join (cfg_JOIN_INNER_TD_2645078_cmds.cmd);
    cfg_JOIN_INNER_TD_2645078_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_3912575_cmds;
    cfg_JOIN_INNER_TD_3912575_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_3912575_gqe_join (cfg_JOIN_INNER_TD_3912575_cmds.cmd);
    cfg_JOIN_INNER_TD_3912575_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_332118_cmds;
    cfg_JOIN_INNER_TD_332118_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_332118_gqe_join (cfg_JOIN_INNER_TD_332118_cmds.cmd);
    cfg_JOIN_INNER_TD_332118_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_4705166_cmds;
    cfg_JOIN_INNER_TD_4705166_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_4705166_gqe_join (cfg_JOIN_INNER_TD_4705166_cmds.cmd);
    cfg_JOIN_INNER_TD_4705166_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_421336_cmds;
    cfg_JOIN_INNER_TD_421336_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_421336_gqe_join (cfg_JOIN_INNER_TD_421336_cmds.cmd);
    cfg_JOIN_INNER_TD_421336_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_444226_cmds;
    cfg_JOIN_INNER_TD_444226_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_444226_gqe_join (cfg_JOIN_INNER_TD_444226_cmds.cmd);
    cfg_JOIN_INNER_TD_444226_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_5336669_cmds;
    cfg_JOIN_INNER_TD_5336669_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_5336669_gqe_join (cfg_JOIN_INNER_TD_5336669_cmds.cmd);
    cfg_JOIN_INNER_TD_5336669_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_5823975_cmds;
    cfg_JOIN_INNER_TD_5823975_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_5823975_gqe_join (cfg_JOIN_INNER_TD_5823975_cmds.cmd);
    cfg_JOIN_INNER_TD_5823975_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_5600859_cmds;
    cfg_JOIN_INNER_TD_5600859_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_5600859_gqe_join (cfg_JOIN_INNER_TD_5600859_cmds.cmd);
    cfg_JOIN_INNER_TD_5600859_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_6313985_cmds;
    cfg_JOIN_INNER_TD_6313985_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_6313985_gqe_join (cfg_JOIN_INNER_TD_6313985_cmds.cmd);
    cfg_JOIN_INNER_TD_6313985_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_6298318_cmds;
    cfg_JOIN_INNER_TD_6298318_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_6298318_gqe_join (cfg_JOIN_INNER_TD_6298318_cmds.cmd);
    cfg_JOIN_INNER_TD_6298318_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_6912217_cmds;
    cfg_JOIN_INNER_TD_6912217_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_6912217_gqe_join (cfg_JOIN_INNER_TD_6912217_cmds.cmd);
    cfg_JOIN_INNER_TD_6912217_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7143737_cmds;
    cfg_JOIN_INNER_TD_7143737_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7143737_gqe_join (cfg_JOIN_INNER_TD_7143737_cmds.cmd);
    cfg_JOIN_INNER_TD_7143737_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_733731_cmds;
    cfg_JOIN_INNER_TD_733731_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_733731_gqe_join (cfg_JOIN_INNER_TD_733731_cmds.cmd);
    cfg_JOIN_INNER_TD_733731_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7284355_cmds;
    cfg_JOIN_INNER_TD_7284355_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7284355_gqe_join (cfg_JOIN_INNER_TD_7284355_cmds.cmd);
    cfg_JOIN_INNER_TD_7284355_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8444716_cmds;
    cfg_JOIN_INNER_TD_8444716_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8444716_gqe_join (cfg_JOIN_INNER_TD_8444716_cmds.cmd);
    cfg_JOIN_INNER_TD_8444716_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8393357_cmds;
    cfg_JOIN_INNER_TD_8393357_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8393357_gqe_join (cfg_JOIN_INNER_TD_8393357_cmds.cmd);
    cfg_JOIN_INNER_TD_8393357_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8123925_cmds;
    cfg_JOIN_INNER_TD_8123925_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8123925_gqe_join (cfg_JOIN_INNER_TD_8123925_cmds.cmd);
    cfg_JOIN_INNER_TD_8123925_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8295220_cmds;
    cfg_JOIN_INNER_TD_8295220_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8295220_gqe_join (cfg_JOIN_INNER_TD_8295220_cmds.cmd);
    cfg_JOIN_INNER_TD_8295220_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_9537683_cmds;
    cfg_JOIN_INNER_TD_9537683_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_9537683_gqe_join (cfg_JOIN_INNER_TD_9537683_cmds.cmd);
    cfg_JOIN_INNER_TD_9537683_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_9681030_cmds;
    cfg_JOIN_INNER_TD_9681030_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_9681030_gqe_join (cfg_JOIN_INNER_TD_9681030_cmds.cmd);
    cfg_JOIN_INNER_TD_9681030_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_9323172_cmds;
    cfg_JOIN_INNER_TD_9323172_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_9323172_gqe_join (cfg_JOIN_INNER_TD_9323172_cmds.cmd);
    cfg_JOIN_INNER_TD_9323172_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_10970681_cmds;
    cfg_JOIN_INNER_TD_10970681_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_10970681_gqe_join (cfg_JOIN_INNER_TD_10970681_cmds.cmd);
    cfg_JOIN_INNER_TD_10970681_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_10472652_cmds;
    cfg_JOIN_INNER_TD_10472652_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_10472652_gqe_join (cfg_JOIN_INNER_TD_10472652_cmds.cmd);
    cfg_JOIN_INNER_TD_10472652_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_2645078;
    krnl_JOIN_INNER_TD_2645078 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_2645078.setup(tbl_JOIN_INNER_TD_332118_output, tbl_Filter_TD_3373394_output, tbl_JOIN_INNER_TD_2645078_output, cfg_JOIN_INNER_TD_2645078_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_3912575;
    krnl_JOIN_INNER_TD_3912575 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_3912575.setup(tbl_JOIN_INNER_TD_421336_output, tbl_Filter_TD_4532889_output, tbl_JOIN_INNER_TD_3912575_output, cfg_JOIN_INNER_TD_3912575_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_332118;
    krnl_JOIN_INNER_TD_332118 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_332118.setup(tbl_JOIN_INNER_TD_444226_output, tbl_Filter_TD_4107367_output, tbl_JOIN_INNER_TD_332118_output, cfg_JOIN_INNER_TD_332118_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_4705166;
    krnl_JOIN_INNER_TD_4705166 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_4705166.setup(tbl_JOIN_INNER_TD_5823975_output, tbl_Filter_TD_5329556_output, tbl_JOIN_INNER_TD_4705166_output, cfg_JOIN_INNER_TD_4705166_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_421336;
    krnl_JOIN_INNER_TD_421336 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_421336.setup(tbl_JOIN_INNER_TD_5600859_output, tbl_Filter_TD_5944573_output, tbl_JOIN_INNER_TD_421336_output, cfg_JOIN_INNER_TD_421336_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_444226;
    krnl_JOIN_INNER_TD_444226 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_444226.setup(tbl_Filter_TD_5906846_output, tbl_Filter_TD_5562669_output, tbl_JOIN_INNER_TD_444226_output, cfg_JOIN_INNER_TD_444226_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_5336669;
    krnl_JOIN_INNER_TD_5336669 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_5336669.setup(tbl_JOIN_INNER_TD_6298318_output, tbl_Filter_TD_6190390_output, tbl_JOIN_INNER_TD_5336669_output, cfg_JOIN_INNER_TD_5336669_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_5823975;
    krnl_JOIN_INNER_TD_5823975 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_5823975.setup(tbl_JOIN_INNER_TD_6912217_output, tbl_Filter_TD_621706_output, tbl_JOIN_INNER_TD_5823975_output, cfg_JOIN_INNER_TD_5823975_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_5600859;
    krnl_JOIN_INNER_TD_5600859 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_5600859.setup(tbl_Filter_TD_6868889_output, tbl_Filter_TD_6510134_output, tbl_JOIN_INNER_TD_5600859_output, cfg_JOIN_INNER_TD_5600859_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_6313985;
    krnl_JOIN_INNER_TD_6313985 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_6313985.setup(tbl_JOIN_INNER_TD_733731_output, tbl_Filter_TD_725548_output, tbl_JOIN_INNER_TD_6313985_output, cfg_JOIN_INNER_TD_6313985_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_6298318;
    krnl_JOIN_INNER_TD_6298318 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_6298318.setup(tbl_JOIN_INNER_TD_7284355_output, tbl_Filter_TD_7632249_output, tbl_JOIN_INNER_TD_6298318_output, cfg_JOIN_INNER_TD_6298318_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_6912217;
    krnl_JOIN_INNER_TD_6912217 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_6912217.setup(tbl_Filter_TD_7710378_output, tbl_Filter_TD_7643990_output, tbl_JOIN_INNER_TD_6912217_output, cfg_JOIN_INNER_TD_6912217_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_7143737;
    krnl_JOIN_INNER_TD_7143737 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7143737.setup(tbl_JOIN_INNER_TD_8123925_output, tbl_Filter_TD_8558615_output, tbl_JOIN_INNER_TD_7143737_output, cfg_JOIN_INNER_TD_7143737_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_733731;
    krnl_JOIN_INNER_TD_733731 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_733731.setup(tbl_JOIN_INNER_TD_8295220_output, tbl_Filter_TD_8123668_output, tbl_JOIN_INNER_TD_733731_output, cfg_JOIN_INNER_TD_733731_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_7284355;
    krnl_JOIN_INNER_TD_7284355 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7284355.setup(tbl_Filter_TD_8395884_output, tbl_Filter_TD_8550963_output, tbl_JOIN_INNER_TD_7284355_output, cfg_JOIN_INNER_TD_7284355_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_8444716;
    krnl_JOIN_INNER_TD_8444716 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8444716.setup(tbl_JOIN_INNER_TD_9537683_output, tbl_Filter_TD_9319524_output, tbl_JOIN_INNER_TD_8444716_output, cfg_JOIN_INNER_TD_8444716_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_8393357;
    krnl_JOIN_INNER_TD_8393357 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8393357.setup(tbl_JOIN_INNER_TD_9681030_output, tbl_Filter_TD_9704552_output, tbl_JOIN_INNER_TD_8393357_output, cfg_JOIN_INNER_TD_8393357_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_8123925;
    krnl_JOIN_INNER_TD_8123925 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8123925.setup(tbl_JOIN_INNER_TD_9323172_output, tbl_Filter_TD_9706559_output, tbl_JOIN_INNER_TD_8123925_output, cfg_JOIN_INNER_TD_8123925_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_8295220;
    krnl_JOIN_INNER_TD_8295220 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8295220.setup(tbl_Filter_TD_9731454_output, tbl_Filter_TD_9721109_output, tbl_JOIN_INNER_TD_8295220_output, cfg_JOIN_INNER_TD_8295220_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_9537683;
    krnl_JOIN_INNER_TD_9537683 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_9537683.setup(tbl_JOIN_INNER_TD_10970681_output, tbl_Filter_TD_10407068_output, tbl_JOIN_INNER_TD_9537683_output, cfg_JOIN_INNER_TD_9537683_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_9681030;
    krnl_JOIN_INNER_TD_9681030 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_9681030.setup(tbl_JOIN_INNER_TD_10472652_output, tbl_Filter_TD_10773494_output, tbl_JOIN_INNER_TD_9681030_output, cfg_JOIN_INNER_TD_9681030_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_9323172;
    krnl_JOIN_INNER_TD_9323172 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_9323172.setup(tbl_Filter_TD_10930230_output, tbl_Filter_TD_10112030_output, tbl_JOIN_INNER_TD_9323172_output, cfg_JOIN_INNER_TD_9323172_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_10970681;
    krnl_JOIN_INNER_TD_10970681 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_10970681.setup(tbl_Filter_TD_11825044_output, tbl_Filter_TD_11863624_output, tbl_JOIN_INNER_TD_10970681_output, cfg_JOIN_INNER_TD_10970681_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_10472652;
    krnl_JOIN_INNER_TD_10472652 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_10472652.setup(tbl_Filter_TD_11494174_output, tbl_Filter_TD_11501915_output, tbl_JOIN_INNER_TD_10472652_output, cfg_JOIN_INNER_TD_10472652_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_2645078;
    trans_JOIN_INNER_TD_2645078.setq(q_h);
    trans_JOIN_INNER_TD_2645078.add(&(cfg_JOIN_INNER_TD_2645078_cmds));
    transEngine trans_JOIN_INNER_TD_2645078_out;
    trans_JOIN_INNER_TD_2645078_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_3912575;
    trans_JOIN_INNER_TD_3912575.setq(q_h);
    trans_JOIN_INNER_TD_3912575.add(&(cfg_JOIN_INNER_TD_3912575_cmds));
    transEngine trans_JOIN_INNER_TD_3912575_out;
    trans_JOIN_INNER_TD_3912575_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_332118;
    trans_JOIN_INNER_TD_332118.setq(q_h);
    trans_JOIN_INNER_TD_332118.add(&(cfg_JOIN_INNER_TD_332118_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_4705166;
    trans_JOIN_INNER_TD_4705166.setq(q_h);
    trans_JOIN_INNER_TD_4705166.add(&(cfg_JOIN_INNER_TD_4705166_cmds));
    transEngine trans_JOIN_INNER_TD_4705166_out;
    trans_JOIN_INNER_TD_4705166_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_421336;
    trans_JOIN_INNER_TD_421336.setq(q_h);
    trans_JOIN_INNER_TD_421336.add(&(cfg_JOIN_INNER_TD_421336_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_444226;
    trans_JOIN_INNER_TD_444226.setq(q_h);
    trans_JOIN_INNER_TD_444226.add(&(cfg_JOIN_INNER_TD_444226_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_5336669;
    trans_JOIN_INNER_TD_5336669.setq(q_h);
    trans_JOIN_INNER_TD_5336669.add(&(cfg_JOIN_INNER_TD_5336669_cmds));
    transEngine trans_JOIN_INNER_TD_5336669_out;
    trans_JOIN_INNER_TD_5336669_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_5823975;
    trans_JOIN_INNER_TD_5823975.setq(q_h);
    trans_JOIN_INNER_TD_5823975.add(&(cfg_JOIN_INNER_TD_5823975_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_5600859;
    trans_JOIN_INNER_TD_5600859.setq(q_h);
    trans_JOIN_INNER_TD_5600859.add(&(cfg_JOIN_INNER_TD_5600859_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_6313985;
    trans_JOIN_INNER_TD_6313985.setq(q_h);
    trans_JOIN_INNER_TD_6313985.add(&(cfg_JOIN_INNER_TD_6313985_cmds));
    transEngine trans_JOIN_INNER_TD_6313985_out;
    trans_JOIN_INNER_TD_6313985_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_6298318;
    trans_JOIN_INNER_TD_6298318.setq(q_h);
    trans_JOIN_INNER_TD_6298318.add(&(cfg_JOIN_INNER_TD_6298318_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_6912217;
    trans_JOIN_INNER_TD_6912217.setq(q_h);
    trans_JOIN_INNER_TD_6912217.add(&(cfg_JOIN_INNER_TD_6912217_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_7143737;
    trans_JOIN_INNER_TD_7143737.setq(q_h);
    trans_JOIN_INNER_TD_7143737.add(&(cfg_JOIN_INNER_TD_7143737_cmds));
    transEngine trans_JOIN_INNER_TD_7143737_out;
    trans_JOIN_INNER_TD_7143737_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_733731;
    trans_JOIN_INNER_TD_733731.setq(q_h);
    trans_JOIN_INNER_TD_733731.add(&(cfg_JOIN_INNER_TD_733731_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_7284355;
    trans_JOIN_INNER_TD_7284355.setq(q_h);
    trans_JOIN_INNER_TD_7284355.add(&(cfg_JOIN_INNER_TD_7284355_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_8444716;
    trans_JOIN_INNER_TD_8444716.setq(q_h);
    trans_JOIN_INNER_TD_8444716.add(&(cfg_JOIN_INNER_TD_8444716_cmds));
    transEngine trans_JOIN_INNER_TD_8444716_out;
    trans_JOIN_INNER_TD_8444716_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_8393357;
    trans_JOIN_INNER_TD_8393357.setq(q_h);
    trans_JOIN_INNER_TD_8393357.add(&(cfg_JOIN_INNER_TD_8393357_cmds));
    transEngine trans_JOIN_INNER_TD_8393357_out;
    trans_JOIN_INNER_TD_8393357_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_8123925;
    trans_JOIN_INNER_TD_8123925.setq(q_h);
    trans_JOIN_INNER_TD_8123925.add(&(cfg_JOIN_INNER_TD_8123925_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_8295220;
    trans_JOIN_INNER_TD_8295220.setq(q_h);
    trans_JOIN_INNER_TD_8295220.add(&(cfg_JOIN_INNER_TD_8295220_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_9537683;
    trans_JOIN_INNER_TD_9537683.setq(q_h);
    trans_JOIN_INNER_TD_9537683.add(&(cfg_JOIN_INNER_TD_9537683_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_9681030;
    trans_JOIN_INNER_TD_9681030.setq(q_h);
    trans_JOIN_INNER_TD_9681030.add(&(cfg_JOIN_INNER_TD_9681030_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_9323172;
    trans_JOIN_INNER_TD_9323172.setq(q_h);
    trans_JOIN_INNER_TD_9323172.add(&(cfg_JOIN_INNER_TD_9323172_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_10970681;
    trans_JOIN_INNER_TD_10970681.setq(q_h);
    trans_JOIN_INNER_TD_10970681.add(&(cfg_JOIN_INNER_TD_10970681_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_10472652;
    trans_JOIN_INNER_TD_10472652.setq(q_h);
    trans_JOIN_INNER_TD_10472652.add(&(cfg_JOIN_INNER_TD_10472652_cmds));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_2645078;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_2645078;
    std::vector<cl::Event> events_JOIN_INNER_TD_2645078;
    events_h2d_wr_JOIN_INNER_TD_2645078.resize(1);
    events_d2h_rd_JOIN_INNER_TD_2645078.resize(1);
    events_JOIN_INNER_TD_2645078.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_2645078;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_2645078;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_3912575;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_3912575;
    std::vector<cl::Event> events_JOIN_INNER_TD_3912575;
    events_h2d_wr_JOIN_INNER_TD_3912575.resize(1);
    events_d2h_rd_JOIN_INNER_TD_3912575.resize(1);
    events_JOIN_INNER_TD_3912575.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_3912575;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_3912575;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_332118;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_332118;
    std::vector<cl::Event> events_JOIN_INNER_TD_332118;
    events_h2d_wr_JOIN_INNER_TD_332118.resize(1);
    events_d2h_rd_JOIN_INNER_TD_332118.resize(1);
    events_JOIN_INNER_TD_332118.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_332118;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_332118;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_4705166;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_4705166;
    std::vector<cl::Event> events_JOIN_INNER_TD_4705166;
    events_h2d_wr_JOIN_INNER_TD_4705166.resize(1);
    events_d2h_rd_JOIN_INNER_TD_4705166.resize(1);
    events_JOIN_INNER_TD_4705166.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_4705166;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_4705166;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_421336;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_421336;
    std::vector<cl::Event> events_JOIN_INNER_TD_421336;
    events_h2d_wr_JOIN_INNER_TD_421336.resize(1);
    events_d2h_rd_JOIN_INNER_TD_421336.resize(1);
    events_JOIN_INNER_TD_421336.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_421336;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_421336;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_444226;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_444226;
    std::vector<cl::Event> events_JOIN_INNER_TD_444226;
    events_h2d_wr_JOIN_INNER_TD_444226.resize(1);
    events_d2h_rd_JOIN_INNER_TD_444226.resize(1);
    events_JOIN_INNER_TD_444226.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_444226;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_444226;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_5336669;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_5336669;
    std::vector<cl::Event> events_JOIN_INNER_TD_5336669;
    events_h2d_wr_JOIN_INNER_TD_5336669.resize(1);
    events_d2h_rd_JOIN_INNER_TD_5336669.resize(1);
    events_JOIN_INNER_TD_5336669.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_5336669;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_5336669;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_5823975;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_5823975;
    std::vector<cl::Event> events_JOIN_INNER_TD_5823975;
    events_h2d_wr_JOIN_INNER_TD_5823975.resize(1);
    events_d2h_rd_JOIN_INNER_TD_5823975.resize(1);
    events_JOIN_INNER_TD_5823975.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_5823975;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_5823975;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_5600859;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_5600859;
    std::vector<cl::Event> events_JOIN_INNER_TD_5600859;
    events_h2d_wr_JOIN_INNER_TD_5600859.resize(1);
    events_d2h_rd_JOIN_INNER_TD_5600859.resize(1);
    events_JOIN_INNER_TD_5600859.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_5600859;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_5600859;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_6313985;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_6313985;
    std::vector<cl::Event> events_JOIN_INNER_TD_6313985;
    events_h2d_wr_JOIN_INNER_TD_6313985.resize(1);
    events_d2h_rd_JOIN_INNER_TD_6313985.resize(1);
    events_JOIN_INNER_TD_6313985.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_6313985;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_6313985;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_6298318;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_6298318;
    std::vector<cl::Event> events_JOIN_INNER_TD_6298318;
    events_h2d_wr_JOIN_INNER_TD_6298318.resize(1);
    events_d2h_rd_JOIN_INNER_TD_6298318.resize(1);
    events_JOIN_INNER_TD_6298318.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_6298318;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_6298318;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_6912217;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_6912217;
    std::vector<cl::Event> events_JOIN_INNER_TD_6912217;
    events_h2d_wr_JOIN_INNER_TD_6912217.resize(1);
    events_d2h_rd_JOIN_INNER_TD_6912217.resize(1);
    events_JOIN_INNER_TD_6912217.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_6912217;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_6912217;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7143737;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7143737;
    std::vector<cl::Event> events_JOIN_INNER_TD_7143737;
    events_h2d_wr_JOIN_INNER_TD_7143737.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7143737.resize(1);
    events_JOIN_INNER_TD_7143737.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7143737;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7143737;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_733731;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_733731;
    std::vector<cl::Event> events_JOIN_INNER_TD_733731;
    events_h2d_wr_JOIN_INNER_TD_733731.resize(1);
    events_d2h_rd_JOIN_INNER_TD_733731.resize(1);
    events_JOIN_INNER_TD_733731.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_733731;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_733731;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7284355;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7284355;
    std::vector<cl::Event> events_JOIN_INNER_TD_7284355;
    events_h2d_wr_JOIN_INNER_TD_7284355.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7284355.resize(1);
    events_JOIN_INNER_TD_7284355.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7284355;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7284355;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8444716;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8444716;
    std::vector<cl::Event> events_JOIN_INNER_TD_8444716;
    events_h2d_wr_JOIN_INNER_TD_8444716.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8444716.resize(1);
    events_JOIN_INNER_TD_8444716.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8444716;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8444716;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8393357;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8393357;
    std::vector<cl::Event> events_JOIN_INNER_TD_8393357;
    events_h2d_wr_JOIN_INNER_TD_8393357.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8393357.resize(1);
    events_JOIN_INNER_TD_8393357.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8393357;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8393357;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8123925;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8123925;
    std::vector<cl::Event> events_JOIN_INNER_TD_8123925;
    events_h2d_wr_JOIN_INNER_TD_8123925.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8123925.resize(1);
    events_JOIN_INNER_TD_8123925.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8123925;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8123925;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8295220;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8295220;
    std::vector<cl::Event> events_JOIN_INNER_TD_8295220;
    events_h2d_wr_JOIN_INNER_TD_8295220.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8295220.resize(1);
    events_JOIN_INNER_TD_8295220.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8295220;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8295220;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_9537683;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_9537683;
    std::vector<cl::Event> events_JOIN_INNER_TD_9537683;
    events_h2d_wr_JOIN_INNER_TD_9537683.resize(1);
    events_d2h_rd_JOIN_INNER_TD_9537683.resize(1);
    events_JOIN_INNER_TD_9537683.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_9537683;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_9537683;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_9681030;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_9681030;
    std::vector<cl::Event> events_JOIN_INNER_TD_9681030;
    events_h2d_wr_JOIN_INNER_TD_9681030.resize(1);
    events_d2h_rd_JOIN_INNER_TD_9681030.resize(1);
    events_JOIN_INNER_TD_9681030.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_9681030;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_9681030;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_9323172;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_9323172;
    std::vector<cl::Event> events_JOIN_INNER_TD_9323172;
    events_h2d_wr_JOIN_INNER_TD_9323172.resize(1);
    events_d2h_rd_JOIN_INNER_TD_9323172.resize(1);
    events_JOIN_INNER_TD_9323172.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_9323172;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_9323172;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_10970681;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_10970681;
    std::vector<cl::Event> events_JOIN_INNER_TD_10970681;
    events_h2d_wr_JOIN_INNER_TD_10970681.resize(1);
    events_d2h_rd_JOIN_INNER_TD_10970681.resize(1);
    events_JOIN_INNER_TD_10970681.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_10970681;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_10970681;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_10472652;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_10472652;
    std::vector<cl::Event> events_JOIN_INNER_TD_10472652;
    events_h2d_wr_JOIN_INNER_TD_10472652.resize(1);
    events_d2h_rd_JOIN_INNER_TD_10472652.resize(1);
    events_JOIN_INNER_TD_10472652.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_10472652;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_10472652;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_11_192386_s, tv_r_Filter_11_192386_e;
    gettimeofday(&tv_r_Filter_11_192386_s, 0);
    SW_Filter_TD_11501915(tbl_SerializeFromObject_TD_1233021_input, tbl_Filter_TD_11501915_output);
    gettimeofday(&tv_r_Filter_11_192386_e, 0);

    struct timeval tv_r_Filter_11_304610_s, tv_r_Filter_11_304610_e;
    gettimeofday(&tv_r_Filter_11_304610_s, 0);
    SW_Filter_TD_11494174(tbl_SerializeFromObject_TD_12265143_input, tbl_Filter_TD_11494174_output);
    gettimeofday(&tv_r_Filter_11_304610_e, 0);

    struct timeval tv_r_Filter_11_733685_s, tv_r_Filter_11_733685_e;
    gettimeofday(&tv_r_Filter_11_733685_s, 0);
    SW_Filter_TD_11863624(tbl_SerializeFromObject_TD_12427169_input, tbl_Filter_TD_11863624_output);
    gettimeofday(&tv_r_Filter_11_733685_e, 0);

    struct timeval tv_r_Filter_11_349566_s, tv_r_Filter_11_349566_e;
    gettimeofday(&tv_r_Filter_11_349566_s, 0);
    SW_Filter_TD_11825044(tbl_SerializeFromObject_TD_12473315_input, tbl_Filter_TD_11825044_output);
    gettimeofday(&tv_r_Filter_11_349566_e, 0);

    struct timeval tv_r_Filter_10_848826_s, tv_r_Filter_10_848826_e;
    gettimeofday(&tv_r_Filter_10_848826_s, 0);
    SW_Filter_TD_10112030(tbl_SerializeFromObject_TD_11248910_input, tbl_Filter_TD_10112030_output);
    gettimeofday(&tv_r_Filter_10_848826_e, 0);

    struct timeval tv_r_Filter_10_401312_s, tv_r_Filter_10_401312_e;
    gettimeofday(&tv_r_Filter_10_401312_s, 0);
    SW_Filter_TD_10930230(tbl_SerializeFromObject_TD_11840076_input, tbl_Filter_TD_10930230_output);
    gettimeofday(&tv_r_Filter_10_401312_e, 0);

    struct timeval tv_r_Filter_10_328712_s, tv_r_Filter_10_328712_e;
    gettimeofday(&tv_r_Filter_10_328712_s, 0);
    SW_Filter_TD_10773494(tbl_SerializeFromObject_TD_11646343_input, tbl_Filter_TD_10773494_output);
    gettimeofday(&tv_r_Filter_10_328712_e, 0);

    struct timeval tv_r_JOIN_INNER_10_344721_s, tv_r_JOIN_INNER_10_344721_e;
    gettimeofday(&tv_r_JOIN_INNER_10_344721_s, 0);
    trans_JOIN_INNER_TD_10472652.add(&(tbl_Filter_TD_11494174_output));
    trans_JOIN_INNER_TD_10472652.add(&(tbl_Filter_TD_11501915_output));
    trans_JOIN_INNER_TD_10472652.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_10472652), &(events_h2d_wr_JOIN_INNER_TD_10472652[0]));
    events_grp_JOIN_INNER_TD_10472652.push_back(events_h2d_wr_JOIN_INNER_TD_10472652[0]);
    krnl_JOIN_INNER_TD_10472652.run(0, &(events_grp_JOIN_INNER_TD_10472652), &(events_JOIN_INNER_TD_10472652[0]));
    gettimeofday(&tv_r_JOIN_INNER_10_344721_e, 0);

    struct timeval tv_r_Filter_10_145460_s, tv_r_Filter_10_145460_e;
    gettimeofday(&tv_r_Filter_10_145460_s, 0);
    SW_Filter_TD_10407068(tbl_SerializeFromObject_TD_11139299_input, tbl_Filter_TD_10407068_output);
    gettimeofday(&tv_r_Filter_10_145460_e, 0);

    struct timeval tv_r_JOIN_INNER_10_922638_s, tv_r_JOIN_INNER_10_922638_e;
    gettimeofday(&tv_r_JOIN_INNER_10_922638_s, 0);
    trans_JOIN_INNER_TD_10970681.add(&(tbl_Filter_TD_11825044_output));
    trans_JOIN_INNER_TD_10970681.add(&(tbl_Filter_TD_11863624_output));
    trans_JOIN_INNER_TD_10970681.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_10970681), &(events_h2d_wr_JOIN_INNER_TD_10970681[0]));
    events_grp_JOIN_INNER_TD_10970681.push_back(events_h2d_wr_JOIN_INNER_TD_10970681[0]);
    krnl_JOIN_INNER_TD_10970681.run(0, &(events_grp_JOIN_INNER_TD_10970681), &(events_JOIN_INNER_TD_10970681[0]));
    gettimeofday(&tv_r_JOIN_INNER_10_922638_e, 0);

    struct timeval tv_r_Filter_9_454886_s, tv_r_Filter_9_454886_e;
    gettimeofday(&tv_r_Filter_9_454886_s, 0);
    SW_Filter_TD_9721109(tbl_SerializeFromObject_TD_10384773_input, tbl_Filter_TD_9721109_output);
    gettimeofday(&tv_r_Filter_9_454886_e, 0);

    struct timeval tv_r_Filter_9_926501_s, tv_r_Filter_9_926501_e;
    gettimeofday(&tv_r_Filter_9_926501_s, 0);
    SW_Filter_TD_9731454(tbl_SerializeFromObject_TD_1039924_input, tbl_Filter_TD_9731454_output);
    gettimeofday(&tv_r_Filter_9_926501_e, 0);

    struct timeval tv_r_Filter_9_225412_s, tv_r_Filter_9_225412_e;
    gettimeofday(&tv_r_Filter_9_225412_s, 0);
    SW_Filter_TD_9706559(tbl_SerializeFromObject_TD_10560310_input, tbl_Filter_TD_9706559_output);
    gettimeofday(&tv_r_Filter_9_225412_e, 0);

    struct timeval tv_r_JOIN_INNER_9_695008_s, tv_r_JOIN_INNER_9_695008_e;
    gettimeofday(&tv_r_JOIN_INNER_9_695008_s, 0);
    trans_JOIN_INNER_TD_9323172.add(&(tbl_Filter_TD_10930230_output));
    trans_JOIN_INNER_TD_9323172.add(&(tbl_Filter_TD_10112030_output));
    trans_JOIN_INNER_TD_9323172.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_9323172), &(events_h2d_wr_JOIN_INNER_TD_9323172[0]));
    events_grp_JOIN_INNER_TD_9323172.push_back(events_h2d_wr_JOIN_INNER_TD_9323172[0]);
    krnl_JOIN_INNER_TD_9323172.run(0, &(events_grp_JOIN_INNER_TD_9323172), &(events_JOIN_INNER_TD_9323172[0]));
    gettimeofday(&tv_r_JOIN_INNER_9_695008_e, 0);

    struct timeval tv_r_Filter_9_744853_s, tv_r_Filter_9_744853_e;
    gettimeofday(&tv_r_Filter_9_744853_s, 0);
    SW_Filter_TD_9704552(tbl_SerializeFromObject_TD_10678969_input, tbl_Filter_TD_9704552_output);
    gettimeofday(&tv_r_Filter_9_744853_e, 0);

    struct timeval tv_r_JOIN_INNER_9_303682_s, tv_r_JOIN_INNER_9_303682_e;
    gettimeofday(&tv_r_JOIN_INNER_9_303682_s, 0);
    prev_events_grp_JOIN_INNER_TD_9681030.push_back(events_h2d_wr_JOIN_INNER_TD_10472652[0]);
    trans_JOIN_INNER_TD_9681030.add(&(tbl_Filter_TD_10773494_output));
    trans_JOIN_INNER_TD_9681030.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_9681030), &(events_h2d_wr_JOIN_INNER_TD_9681030[0]));
    events_grp_JOIN_INNER_TD_9681030.push_back(events_h2d_wr_JOIN_INNER_TD_9681030[0]);
    events_grp_JOIN_INNER_TD_9681030.push_back(events_JOIN_INNER_TD_10472652[0]);
    krnl_JOIN_INNER_TD_9681030.run(0, &(events_grp_JOIN_INNER_TD_9681030), &(events_JOIN_INNER_TD_9681030[0]));
    gettimeofday(&tv_r_JOIN_INNER_9_303682_e, 0);

    struct timeval tv_r_Filter_9_743046_s, tv_r_Filter_9_743046_e;
    gettimeofday(&tv_r_Filter_9_743046_s, 0);
    SW_Filter_TD_9319524(tbl_SerializeFromObject_TD_10826019_input, tbl_Filter_TD_9319524_output);
    gettimeofday(&tv_r_Filter_9_743046_e, 0);

    struct timeval tv_r_JOIN_INNER_9_758488_s, tv_r_JOIN_INNER_9_758488_e;
    gettimeofday(&tv_r_JOIN_INNER_9_758488_s, 0);
    prev_events_grp_JOIN_INNER_TD_9537683.push_back(events_h2d_wr_JOIN_INNER_TD_10970681[0]);
    trans_JOIN_INNER_TD_9537683.add(&(tbl_Filter_TD_10407068_output));
    trans_JOIN_INNER_TD_9537683.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_9537683), &(events_h2d_wr_JOIN_INNER_TD_9537683[0]));
    events_grp_JOIN_INNER_TD_9537683.push_back(events_h2d_wr_JOIN_INNER_TD_9537683[0]);
    events_grp_JOIN_INNER_TD_9537683.push_back(events_JOIN_INNER_TD_10970681[0]);
    krnl_JOIN_INNER_TD_9537683.run(0, &(events_grp_JOIN_INNER_TD_9537683), &(events_JOIN_INNER_TD_9537683[0]));
    gettimeofday(&tv_r_JOIN_INNER_9_758488_e, 0);

    struct timeval tv_r_Filter_8_395537_s, tv_r_Filter_8_395537_e;
    gettimeofday(&tv_r_Filter_8_395537_s, 0);
    SW_Filter_TD_8550963(tbl_SerializeFromObject_TD_9324654_input, tbl_Filter_TD_8550963_output);
    gettimeofday(&tv_r_Filter_8_395537_e, 0);

    struct timeval tv_r_Filter_8_992480_s, tv_r_Filter_8_992480_e;
    gettimeofday(&tv_r_Filter_8_992480_s, 0);
    SW_Filter_TD_8395884(tbl_SerializeFromObject_TD_910318_input, tbl_Filter_TD_8395884_output);
    gettimeofday(&tv_r_Filter_8_992480_e, 0);

    struct timeval tv_r_Filter_8_964135_s, tv_r_Filter_8_964135_e;
    gettimeofday(&tv_r_Filter_8_964135_s, 0);
    SW_Filter_TD_8123668(tbl_SerializeFromObject_TD_9320282_input, tbl_Filter_TD_8123668_output);
    gettimeofday(&tv_r_Filter_8_964135_e, 0);

    struct timeval tv_r_JOIN_INNER_8_163918_s, tv_r_JOIN_INNER_8_163918_e;
    gettimeofday(&tv_r_JOIN_INNER_8_163918_s, 0);
    trans_JOIN_INNER_TD_8295220.add(&(tbl_Filter_TD_9731454_output));
    trans_JOIN_INNER_TD_8295220.add(&(tbl_Filter_TD_9721109_output));
    trans_JOIN_INNER_TD_8295220.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8295220), &(events_h2d_wr_JOIN_INNER_TD_8295220[0]));
    events_grp_JOIN_INNER_TD_8295220.push_back(events_h2d_wr_JOIN_INNER_TD_8295220[0]);
    krnl_JOIN_INNER_TD_8295220.run(0, &(events_grp_JOIN_INNER_TD_8295220), &(events_JOIN_INNER_TD_8295220[0]));
    gettimeofday(&tv_r_JOIN_INNER_8_163918_e, 0);

    struct timeval tv_r_Filter_8_534888_s, tv_r_Filter_8_534888_e;
    gettimeofday(&tv_r_Filter_8_534888_s, 0);
    SW_Filter_TD_8558615(tbl_SerializeFromObject_TD_9568378_input, tbl_Filter_TD_8558615_output);
    gettimeofday(&tv_r_Filter_8_534888_e, 0);

    struct timeval tv_r_JOIN_INNER_8_967158_s, tv_r_JOIN_INNER_8_967158_e;
    gettimeofday(&tv_r_JOIN_INNER_8_967158_s, 0);
    prev_events_grp_JOIN_INNER_TD_8123925.push_back(events_h2d_wr_JOIN_INNER_TD_9323172[0]);
    trans_JOIN_INNER_TD_8123925.add(&(tbl_Filter_TD_9706559_output));
    trans_JOIN_INNER_TD_8123925.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8123925), &(events_h2d_wr_JOIN_INNER_TD_8123925[0]));
    events_grp_JOIN_INNER_TD_8123925.push_back(events_h2d_wr_JOIN_INNER_TD_8123925[0]);
    events_grp_JOIN_INNER_TD_8123925.push_back(events_JOIN_INNER_TD_9323172[0]);
    krnl_JOIN_INNER_TD_8123925.run(0, &(events_grp_JOIN_INNER_TD_8123925), &(events_JOIN_INNER_TD_8123925[0]));
    gettimeofday(&tv_r_JOIN_INNER_8_967158_e, 0);

    struct timeval tv_r_JOIN_INNER_8_220684_s, tv_r_JOIN_INNER_8_220684_e;
    gettimeofday(&tv_r_JOIN_INNER_8_220684_s, 0);
    prev_events_grp_JOIN_INNER_TD_8393357.push_back(events_h2d_wr_JOIN_INNER_TD_9681030[0]);
    trans_JOIN_INNER_TD_8393357.add(&(tbl_Filter_TD_9704552_output));
    trans_JOIN_INNER_TD_8393357.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8393357), &(events_h2d_wr_JOIN_INNER_TD_8393357[0]));
    events_grp_JOIN_INNER_TD_8393357.push_back(events_h2d_wr_JOIN_INNER_TD_8393357[0]);
    events_grp_JOIN_INNER_TD_8393357.push_back(events_JOIN_INNER_TD_9681030[0]);
    krnl_JOIN_INNER_TD_8393357.run(0, &(events_grp_JOIN_INNER_TD_8393357), &(events_JOIN_INNER_TD_8393357[0]));
    
    trans_JOIN_INNER_TD_8393357_out.add(&(tbl_JOIN_INNER_TD_8393357_output));
    trans_JOIN_INNER_TD_8393357_out.dev2host(0, &(events_JOIN_INNER_TD_8393357), &(events_d2h_rd_JOIN_INNER_TD_8393357[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_8_220684_e, 0);

    struct timeval tv_r_JOIN_INNER_8_502351_s, tv_r_JOIN_INNER_8_502351_e;
    gettimeofday(&tv_r_JOIN_INNER_8_502351_s, 0);
    prev_events_grp_JOIN_INNER_TD_8444716.push_back(events_h2d_wr_JOIN_INNER_TD_9537683[0]);
    trans_JOIN_INNER_TD_8444716.add(&(tbl_Filter_TD_9319524_output));
    trans_JOIN_INNER_TD_8444716.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8444716), &(events_h2d_wr_JOIN_INNER_TD_8444716[0]));
    events_grp_JOIN_INNER_TD_8444716.push_back(events_h2d_wr_JOIN_INNER_TD_8444716[0]);
    events_grp_JOIN_INNER_TD_8444716.push_back(events_JOIN_INNER_TD_9537683[0]);
    krnl_JOIN_INNER_TD_8444716.run(0, &(events_grp_JOIN_INNER_TD_8444716), &(events_JOIN_INNER_TD_8444716[0]));
    
    trans_JOIN_INNER_TD_8444716_out.add(&(tbl_JOIN_INNER_TD_8444716_output));
    trans_JOIN_INNER_TD_8444716_out.dev2host(0, &(events_JOIN_INNER_TD_8444716), &(events_d2h_rd_JOIN_INNER_TD_8444716[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_8_502351_e, 0);

    struct timeval tv_r_Filter_7_162165_s, tv_r_Filter_7_162165_e;
    gettimeofday(&tv_r_Filter_7_162165_s, 0);
    SW_Filter_TD_7643990(tbl_SerializeFromObject_TD_8986814_input, tbl_Filter_TD_7643990_output);
    gettimeofday(&tv_r_Filter_7_162165_e, 0);

    struct timeval tv_r_Filter_7_407856_s, tv_r_Filter_7_407856_e;
    gettimeofday(&tv_r_Filter_7_407856_s, 0);
    SW_Filter_TD_7710378(tbl_SerializeFromObject_TD_8678517_input, tbl_Filter_TD_7710378_output);
    gettimeofday(&tv_r_Filter_7_407856_e, 0);

    struct timeval tv_r_Filter_7_762466_s, tv_r_Filter_7_762466_e;
    gettimeofday(&tv_r_Filter_7_762466_s, 0);
    SW_Filter_TD_7632249(tbl_SerializeFromObject_TD_8210534_input, tbl_Filter_TD_7632249_output);
    gettimeofday(&tv_r_Filter_7_762466_e, 0);

    struct timeval tv_r_JOIN_INNER_7_474786_s, tv_r_JOIN_INNER_7_474786_e;
    gettimeofday(&tv_r_JOIN_INNER_7_474786_s, 0);
    trans_JOIN_INNER_TD_7284355.add(&(tbl_Filter_TD_8395884_output));
    trans_JOIN_INNER_TD_7284355.add(&(tbl_Filter_TD_8550963_output));
    trans_JOIN_INNER_TD_7284355.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7284355), &(events_h2d_wr_JOIN_INNER_TD_7284355[0]));
    events_grp_JOIN_INNER_TD_7284355.push_back(events_h2d_wr_JOIN_INNER_TD_7284355[0]);
    krnl_JOIN_INNER_TD_7284355.run(0, &(events_grp_JOIN_INNER_TD_7284355), &(events_JOIN_INNER_TD_7284355[0]));
    gettimeofday(&tv_r_JOIN_INNER_7_474786_e, 0);

    struct timeval tv_r_Filter_7_367862_s, tv_r_Filter_7_367862_e;
    gettimeofday(&tv_r_Filter_7_367862_s, 0);
    SW_Filter_TD_725548(tbl_SerializeFromObject_TD_8488467_input, tbl_Filter_TD_725548_output);
    gettimeofday(&tv_r_Filter_7_367862_e, 0);

    struct timeval tv_r_JOIN_INNER_7_772990_s, tv_r_JOIN_INNER_7_772990_e;
    gettimeofday(&tv_r_JOIN_INNER_7_772990_s, 0);
    prev_events_grp_JOIN_INNER_TD_733731.push_back(events_h2d_wr_JOIN_INNER_TD_8295220[0]);
    trans_JOIN_INNER_TD_733731.add(&(tbl_Filter_TD_8123668_output));
    trans_JOIN_INNER_TD_733731.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_733731), &(events_h2d_wr_JOIN_INNER_TD_733731[0]));
    events_grp_JOIN_INNER_TD_733731.push_back(events_h2d_wr_JOIN_INNER_TD_733731[0]);
    events_grp_JOIN_INNER_TD_733731.push_back(events_JOIN_INNER_TD_8295220[0]);
    krnl_JOIN_INNER_TD_733731.run(0, &(events_grp_JOIN_INNER_TD_733731), &(events_JOIN_INNER_TD_733731[0]));
    gettimeofday(&tv_r_JOIN_INNER_7_772990_e, 0);

    struct timeval tv_r_JOIN_INNER_7_474371_s, tv_r_JOIN_INNER_7_474371_e;
    gettimeofday(&tv_r_JOIN_INNER_7_474371_s, 0);
    prev_events_grp_JOIN_INNER_TD_7143737.push_back(events_h2d_wr_JOIN_INNER_TD_8123925[0]);
    trans_JOIN_INNER_TD_7143737.add(&(tbl_Filter_TD_8558615_output));
    trans_JOIN_INNER_TD_7143737.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7143737), &(events_h2d_wr_JOIN_INNER_TD_7143737[0]));
    events_grp_JOIN_INNER_TD_7143737.push_back(events_h2d_wr_JOIN_INNER_TD_7143737[0]);
    events_grp_JOIN_INNER_TD_7143737.push_back(events_JOIN_INNER_TD_8123925[0]);
    krnl_JOIN_INNER_TD_7143737.run(0, &(events_grp_JOIN_INNER_TD_7143737), &(events_JOIN_INNER_TD_7143737[0]));
    
    trans_JOIN_INNER_TD_7143737_out.add(&(tbl_JOIN_INNER_TD_7143737_output));
    trans_JOIN_INNER_TD_7143737_out.dev2host(0, &(events_JOIN_INNER_TD_7143737), &(events_d2h_rd_JOIN_INNER_TD_7143737[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_7_474371_e, 0);

    struct timeval tv_r_Aggregate_7_507238_s, tv_r_Aggregate_7_507238_e;
    gettimeofday(&tv_r_Aggregate_7_507238_s, 0);
    SW_Aggregate_TD_7988832(tbl_JOIN_INNER_TD_8393357_output, tbl_Aggregate_TD_7988832_output);
    gettimeofday(&tv_r_Aggregate_7_507238_e, 0);

    struct timeval tv_r_Aggregate_7_765004_s, tv_r_Aggregate_7_765004_e;
    gettimeofday(&tv_r_Aggregate_7_765004_s, 0);
    SW_Aggregate_TD_7359641(tbl_JOIN_INNER_TD_8444716_output, tbl_Aggregate_TD_7359641_output);
    gettimeofday(&tv_r_Aggregate_7_765004_e, 0);

    struct timeval tv_r_Filter_6_327305_s, tv_r_Filter_6_327305_e;
    gettimeofday(&tv_r_Filter_6_327305_s, 0);
    SW_Filter_TD_6510134(tbl_SerializeFromObject_TD_7430105_input, tbl_Filter_TD_6510134_output);
    gettimeofday(&tv_r_Filter_6_327305_e, 0);

    struct timeval tv_r_Filter_6_78914_s, tv_r_Filter_6_78914_e;
    gettimeofday(&tv_r_Filter_6_78914_s, 0);
    SW_Filter_TD_6868889(tbl_SerializeFromObject_TD_7705973_input, tbl_Filter_TD_6868889_output);
    gettimeofday(&tv_r_Filter_6_78914_e, 0);

    struct timeval tv_r_Filter_6_371159_s, tv_r_Filter_6_371159_e;
    gettimeofday(&tv_r_Filter_6_371159_s, 0);
    SW_Filter_TD_621706(tbl_SerializeFromObject_TD_7679477_input, tbl_Filter_TD_621706_output);
    gettimeofday(&tv_r_Filter_6_371159_e, 0);

    struct timeval tv_r_JOIN_INNER_6_717520_s, tv_r_JOIN_INNER_6_717520_e;
    gettimeofday(&tv_r_JOIN_INNER_6_717520_s, 0);
    trans_JOIN_INNER_TD_6912217.add(&(tbl_Filter_TD_7710378_output));
    trans_JOIN_INNER_TD_6912217.add(&(tbl_Filter_TD_7643990_output));
    trans_JOIN_INNER_TD_6912217.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_6912217), &(events_h2d_wr_JOIN_INNER_TD_6912217[0]));
    events_grp_JOIN_INNER_TD_6912217.push_back(events_h2d_wr_JOIN_INNER_TD_6912217[0]);
    krnl_JOIN_INNER_TD_6912217.run(0, &(events_grp_JOIN_INNER_TD_6912217), &(events_JOIN_INNER_TD_6912217[0]));
    gettimeofday(&tv_r_JOIN_INNER_6_717520_e, 0);

    struct timeval tv_r_Filter_6_553984_s, tv_r_Filter_6_553984_e;
    gettimeofday(&tv_r_Filter_6_553984_s, 0);
    SW_Filter_TD_6190390(tbl_SerializeFromObject_TD_7674429_input, tbl_Filter_TD_6190390_output);
    gettimeofday(&tv_r_Filter_6_553984_e, 0);

    struct timeval tv_r_JOIN_INNER_6_178451_s, tv_r_JOIN_INNER_6_178451_e;
    gettimeofday(&tv_r_JOIN_INNER_6_178451_s, 0);
    prev_events_grp_JOIN_INNER_TD_6298318.push_back(events_h2d_wr_JOIN_INNER_TD_7284355[0]);
    trans_JOIN_INNER_TD_6298318.add(&(tbl_Filter_TD_7632249_output));
    trans_JOIN_INNER_TD_6298318.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_6298318), &(events_h2d_wr_JOIN_INNER_TD_6298318[0]));
    events_grp_JOIN_INNER_TD_6298318.push_back(events_h2d_wr_JOIN_INNER_TD_6298318[0]);
    events_grp_JOIN_INNER_TD_6298318.push_back(events_JOIN_INNER_TD_7284355[0]);
    krnl_JOIN_INNER_TD_6298318.run(0, &(events_grp_JOIN_INNER_TD_6298318), &(events_JOIN_INNER_TD_6298318[0]));
    gettimeofday(&tv_r_JOIN_INNER_6_178451_e, 0);

    struct timeval tv_r_JOIN_INNER_6_769967_s, tv_r_JOIN_INNER_6_769967_e;
    gettimeofday(&tv_r_JOIN_INNER_6_769967_s, 0);
    prev_events_grp_JOIN_INNER_TD_6313985.push_back(events_h2d_wr_JOIN_INNER_TD_733731[0]);
    trans_JOIN_INNER_TD_6313985.add(&(tbl_Filter_TD_725548_output));
    trans_JOIN_INNER_TD_6313985.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_6313985), &(events_h2d_wr_JOIN_INNER_TD_6313985[0]));
    events_grp_JOIN_INNER_TD_6313985.push_back(events_h2d_wr_JOIN_INNER_TD_6313985[0]);
    events_grp_JOIN_INNER_TD_6313985.push_back(events_JOIN_INNER_TD_733731[0]);
    krnl_JOIN_INNER_TD_6313985.run(0, &(events_grp_JOIN_INNER_TD_6313985), &(events_JOIN_INNER_TD_6313985[0]));
    
    trans_JOIN_INNER_TD_6313985_out.add(&(tbl_JOIN_INNER_TD_6313985_output));
    trans_JOIN_INNER_TD_6313985_out.dev2host(0, &(events_JOIN_INNER_TD_6313985), &(events_d2h_rd_JOIN_INNER_TD_6313985[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_6_769967_e, 0);

    struct timeval tv_r_Aggregate_6_425356_s, tv_r_Aggregate_6_425356_e;
    gettimeofday(&tv_r_Aggregate_6_425356_s, 0);
    SW_Aggregate_TD_6953350(tbl_JOIN_INNER_TD_7143737_output, tbl_Aggregate_TD_6953350_output);
    gettimeofday(&tv_r_Aggregate_6_425356_e, 0);

    struct timeval tv_r_JOIN_CROSS_6_562705_s, tv_r_JOIN_CROSS_6_562705_e;
    gettimeofday(&tv_r_JOIN_CROSS_6_562705_s, 0);
    SW_JOIN_CROSS_TD_6160501(tbl_Aggregate_TD_7359641_output, tbl_Aggregate_TD_7988832_output, tbl_JOIN_CROSS_TD_6160501_output);
    gettimeofday(&tv_r_JOIN_CROSS_6_562705_e, 0);

    struct timeval tv_r_Filter_5_842138_s, tv_r_Filter_5_842138_e;
    gettimeofday(&tv_r_Filter_5_842138_s, 0);
    SW_Filter_TD_5562669(tbl_SerializeFromObject_TD_6203791_input, tbl_Filter_TD_5562669_output);
    gettimeofday(&tv_r_Filter_5_842138_e, 0);

    struct timeval tv_r_Filter_5_212201_s, tv_r_Filter_5_212201_e;
    gettimeofday(&tv_r_Filter_5_212201_s, 0);
    SW_Filter_TD_5906846(tbl_SerializeFromObject_TD_681115_input, tbl_Filter_TD_5906846_output);
    gettimeofday(&tv_r_Filter_5_212201_e, 0);

    struct timeval tv_r_Filter_5_830877_s, tv_r_Filter_5_830877_e;
    gettimeofday(&tv_r_Filter_5_830877_s, 0);
    SW_Filter_TD_5944573(tbl_SerializeFromObject_TD_6791061_input, tbl_Filter_TD_5944573_output);
    gettimeofday(&tv_r_Filter_5_830877_e, 0);

    struct timeval tv_r_JOIN_INNER_5_680692_s, tv_r_JOIN_INNER_5_680692_e;
    gettimeofday(&tv_r_JOIN_INNER_5_680692_s, 0);
    trans_JOIN_INNER_TD_5600859.add(&(tbl_Filter_TD_6868889_output));
    trans_JOIN_INNER_TD_5600859.add(&(tbl_Filter_TD_6510134_output));
    trans_JOIN_INNER_TD_5600859.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_5600859), &(events_h2d_wr_JOIN_INNER_TD_5600859[0]));
    events_grp_JOIN_INNER_TD_5600859.push_back(events_h2d_wr_JOIN_INNER_TD_5600859[0]);
    krnl_JOIN_INNER_TD_5600859.run(0, &(events_grp_JOIN_INNER_TD_5600859), &(events_JOIN_INNER_TD_5600859[0]));
    gettimeofday(&tv_r_JOIN_INNER_5_680692_e, 0);

    struct timeval tv_r_Filter_5_738894_s, tv_r_Filter_5_738894_e;
    gettimeofday(&tv_r_Filter_5_738894_s, 0);
    SW_Filter_TD_5329556(tbl_SerializeFromObject_TD_6424078_input, tbl_Filter_TD_5329556_output);
    gettimeofday(&tv_r_Filter_5_738894_e, 0);

    struct timeval tv_r_JOIN_INNER_5_449952_s, tv_r_JOIN_INNER_5_449952_e;
    gettimeofday(&tv_r_JOIN_INNER_5_449952_s, 0);
    prev_events_grp_JOIN_INNER_TD_5823975.push_back(events_h2d_wr_JOIN_INNER_TD_6912217[0]);
    trans_JOIN_INNER_TD_5823975.add(&(tbl_Filter_TD_621706_output));
    trans_JOIN_INNER_TD_5823975.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_5823975), &(events_h2d_wr_JOIN_INNER_TD_5823975[0]));
    events_grp_JOIN_INNER_TD_5823975.push_back(events_h2d_wr_JOIN_INNER_TD_5823975[0]);
    events_grp_JOIN_INNER_TD_5823975.push_back(events_JOIN_INNER_TD_6912217[0]);
    krnl_JOIN_INNER_TD_5823975.run(0, &(events_grp_JOIN_INNER_TD_5823975), &(events_JOIN_INNER_TD_5823975[0]));
    gettimeofday(&tv_r_JOIN_INNER_5_449952_e, 0);

    struct timeval tv_r_JOIN_INNER_5_173027_s, tv_r_JOIN_INNER_5_173027_e;
    gettimeofday(&tv_r_JOIN_INNER_5_173027_s, 0);
    prev_events_grp_JOIN_INNER_TD_5336669.push_back(events_h2d_wr_JOIN_INNER_TD_6298318[0]);
    trans_JOIN_INNER_TD_5336669.add(&(tbl_Filter_TD_6190390_output));
    trans_JOIN_INNER_TD_5336669.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_5336669), &(events_h2d_wr_JOIN_INNER_TD_5336669[0]));
    events_grp_JOIN_INNER_TD_5336669.push_back(events_h2d_wr_JOIN_INNER_TD_5336669[0]);
    events_grp_JOIN_INNER_TD_5336669.push_back(events_JOIN_INNER_TD_6298318[0]);
    krnl_JOIN_INNER_TD_5336669.run(0, &(events_grp_JOIN_INNER_TD_5336669), &(events_JOIN_INNER_TD_5336669[0]));
    
    trans_JOIN_INNER_TD_5336669_out.add(&(tbl_JOIN_INNER_TD_5336669_output));
    trans_JOIN_INNER_TD_5336669_out.dev2host(0, &(events_JOIN_INNER_TD_5336669), &(events_d2h_rd_JOIN_INNER_TD_5336669[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_5_173027_e, 0);

    struct timeval tv_r_Aggregate_5_896929_s, tv_r_Aggregate_5_896929_e;
    gettimeofday(&tv_r_Aggregate_5_896929_s, 0);
    SW_Aggregate_TD_5162264(tbl_JOIN_INNER_TD_6313985_output, tbl_Aggregate_TD_5162264_output);
    gettimeofday(&tv_r_Aggregate_5_896929_e, 0);

    struct timeval tv_r_JOIN_CROSS_5_357066_s, tv_r_JOIN_CROSS_5_357066_e;
    gettimeofday(&tv_r_JOIN_CROSS_5_357066_s, 0);
    SW_JOIN_CROSS_TD_5759888(tbl_JOIN_CROSS_TD_6160501_output, tbl_Aggregate_TD_6953350_output, tbl_JOIN_CROSS_TD_5759888_output);
    gettimeofday(&tv_r_JOIN_CROSS_5_357066_e, 0);

    struct timeval tv_r_Filter_4_266390_s, tv_r_Filter_4_266390_e;
    gettimeofday(&tv_r_Filter_4_266390_s, 0);
    SW_Filter_TD_4107367(tbl_SerializeFromObject_TD_5555205_input, tbl_Filter_TD_4107367_output);
    gettimeofday(&tv_r_Filter_4_266390_e, 0);

    struct timeval tv_r_JOIN_INNER_4_62498_s, tv_r_JOIN_INNER_4_62498_e;
    gettimeofday(&tv_r_JOIN_INNER_4_62498_s, 0);
    trans_JOIN_INNER_TD_444226.add(&(tbl_Filter_TD_5906846_output));
    trans_JOIN_INNER_TD_444226.add(&(tbl_Filter_TD_5562669_output));
    trans_JOIN_INNER_TD_444226.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_444226), &(events_h2d_wr_JOIN_INNER_TD_444226[0]));
    events_grp_JOIN_INNER_TD_444226.push_back(events_h2d_wr_JOIN_INNER_TD_444226[0]);
    krnl_JOIN_INNER_TD_444226.run(0, &(events_grp_JOIN_INNER_TD_444226), &(events_JOIN_INNER_TD_444226[0]));
    gettimeofday(&tv_r_JOIN_INNER_4_62498_e, 0);

    struct timeval tv_r_Filter_4_566562_s, tv_r_Filter_4_566562_e;
    gettimeofday(&tv_r_Filter_4_566562_s, 0);
    SW_Filter_TD_4532889(tbl_SerializeFromObject_TD_5893686_input, tbl_Filter_TD_4532889_output);
    gettimeofday(&tv_r_Filter_4_566562_e, 0);

    struct timeval tv_r_JOIN_INNER_4_386672_s, tv_r_JOIN_INNER_4_386672_e;
    gettimeofday(&tv_r_JOIN_INNER_4_386672_s, 0);
    prev_events_grp_JOIN_INNER_TD_421336.push_back(events_h2d_wr_JOIN_INNER_TD_5600859[0]);
    trans_JOIN_INNER_TD_421336.add(&(tbl_Filter_TD_5944573_output));
    trans_JOIN_INNER_TD_421336.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_421336), &(events_h2d_wr_JOIN_INNER_TD_421336[0]));
    events_grp_JOIN_INNER_TD_421336.push_back(events_h2d_wr_JOIN_INNER_TD_421336[0]);
    events_grp_JOIN_INNER_TD_421336.push_back(events_JOIN_INNER_TD_5600859[0]);
    krnl_JOIN_INNER_TD_421336.run(0, &(events_grp_JOIN_INNER_TD_421336), &(events_JOIN_INNER_TD_421336[0]));
    gettimeofday(&tv_r_JOIN_INNER_4_386672_e, 0);

    struct timeval tv_r_JOIN_INNER_4_190802_s, tv_r_JOIN_INNER_4_190802_e;
    gettimeofday(&tv_r_JOIN_INNER_4_190802_s, 0);
    prev_events_grp_JOIN_INNER_TD_4705166.push_back(events_h2d_wr_JOIN_INNER_TD_5823975[0]);
    trans_JOIN_INNER_TD_4705166.add(&(tbl_Filter_TD_5329556_output));
    trans_JOIN_INNER_TD_4705166.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_4705166), &(events_h2d_wr_JOIN_INNER_TD_4705166[0]));
    events_grp_JOIN_INNER_TD_4705166.push_back(events_h2d_wr_JOIN_INNER_TD_4705166[0]);
    events_grp_JOIN_INNER_TD_4705166.push_back(events_JOIN_INNER_TD_5823975[0]);
    krnl_JOIN_INNER_TD_4705166.run(0, &(events_grp_JOIN_INNER_TD_4705166), &(events_JOIN_INNER_TD_4705166[0]));
    
    trans_JOIN_INNER_TD_4705166_out.add(&(tbl_JOIN_INNER_TD_4705166_output));
    trans_JOIN_INNER_TD_4705166_out.dev2host(0, &(events_JOIN_INNER_TD_4705166), &(events_d2h_rd_JOIN_INNER_TD_4705166[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_4_190802_e, 0);

    struct timeval tv_r_Aggregate_4_740088_s, tv_r_Aggregate_4_740088_e;
    gettimeofday(&tv_r_Aggregate_4_740088_s, 0);
    SW_Aggregate_TD_4249092(tbl_JOIN_INNER_TD_5336669_output, tbl_Aggregate_TD_4249092_output);
    gettimeofday(&tv_r_Aggregate_4_740088_e, 0);

    struct timeval tv_r_JOIN_CROSS_4_438786_s, tv_r_JOIN_CROSS_4_438786_e;
    gettimeofday(&tv_r_JOIN_CROSS_4_438786_s, 0);
    SW_JOIN_CROSS_TD_4414428(tbl_JOIN_CROSS_TD_5759888_output, tbl_Aggregate_TD_5162264_output, tbl_JOIN_CROSS_TD_4414428_output);
    gettimeofday(&tv_r_JOIN_CROSS_4_438786_e, 0);

    struct timeval tv_r_Filter_3_783482_s, tv_r_Filter_3_783482_e;
    gettimeofday(&tv_r_Filter_3_783482_s, 0);
    SW_Filter_TD_3373394(tbl_SerializeFromObject_TD_4330522_input, tbl_Filter_TD_3373394_output);
    gettimeofday(&tv_r_Filter_3_783482_e, 0);

    struct timeval tv_r_JOIN_INNER_3_29857_s, tv_r_JOIN_INNER_3_29857_e;
    gettimeofday(&tv_r_JOIN_INNER_3_29857_s, 0);
    prev_events_grp_JOIN_INNER_TD_332118.push_back(events_h2d_wr_JOIN_INNER_TD_444226[0]);
    trans_JOIN_INNER_TD_332118.add(&(tbl_Filter_TD_4107367_output));
    trans_JOIN_INNER_TD_332118.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_332118), &(events_h2d_wr_JOIN_INNER_TD_332118[0]));
    events_grp_JOIN_INNER_TD_332118.push_back(events_h2d_wr_JOIN_INNER_TD_332118[0]);
    events_grp_JOIN_INNER_TD_332118.push_back(events_JOIN_INNER_TD_444226[0]);
    krnl_JOIN_INNER_TD_332118.run(0, &(events_grp_JOIN_INNER_TD_332118), &(events_JOIN_INNER_TD_332118[0]));
    gettimeofday(&tv_r_JOIN_INNER_3_29857_e, 0);

    struct timeval tv_r_JOIN_INNER_3_640379_s, tv_r_JOIN_INNER_3_640379_e;
    gettimeofday(&tv_r_JOIN_INNER_3_640379_s, 0);
    prev_events_grp_JOIN_INNER_TD_3912575.push_back(events_h2d_wr_JOIN_INNER_TD_421336[0]);
    trans_JOIN_INNER_TD_3912575.add(&(tbl_Filter_TD_4532889_output));
    trans_JOIN_INNER_TD_3912575.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_3912575), &(events_h2d_wr_JOIN_INNER_TD_3912575[0]));
    events_grp_JOIN_INNER_TD_3912575.push_back(events_h2d_wr_JOIN_INNER_TD_3912575[0]);
    events_grp_JOIN_INNER_TD_3912575.push_back(events_JOIN_INNER_TD_421336[0]);
    krnl_JOIN_INNER_TD_3912575.run(0, &(events_grp_JOIN_INNER_TD_3912575), &(events_JOIN_INNER_TD_3912575[0]));
    
    trans_JOIN_INNER_TD_3912575_out.add(&(tbl_JOIN_INNER_TD_3912575_output));
    trans_JOIN_INNER_TD_3912575_out.dev2host(0, &(events_JOIN_INNER_TD_3912575), &(events_d2h_rd_JOIN_INNER_TD_3912575[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_3_640379_e, 0);

    struct timeval tv_r_Aggregate_3_417701_s, tv_r_Aggregate_3_417701_e;
    gettimeofday(&tv_r_Aggregate_3_417701_s, 0);
    SW_Aggregate_TD_3629204(tbl_JOIN_INNER_TD_4705166_output, tbl_Aggregate_TD_3629204_output);
    gettimeofday(&tv_r_Aggregate_3_417701_e, 0);

    struct timeval tv_r_JOIN_CROSS_3_343454_s, tv_r_JOIN_CROSS_3_343454_e;
    gettimeofday(&tv_r_JOIN_CROSS_3_343454_s, 0);
    SW_JOIN_CROSS_TD_3927976(tbl_JOIN_CROSS_TD_4414428_output, tbl_Aggregate_TD_4249092_output, tbl_JOIN_CROSS_TD_3927976_output);
    gettimeofday(&tv_r_JOIN_CROSS_3_343454_e, 0);

    struct timeval tv_r_JOIN_INNER_2_89084_s, tv_r_JOIN_INNER_2_89084_e;
    gettimeofday(&tv_r_JOIN_INNER_2_89084_s, 0);
    prev_events_grp_JOIN_INNER_TD_2645078.push_back(events_h2d_wr_JOIN_INNER_TD_332118[0]);
    trans_JOIN_INNER_TD_2645078.add(&(tbl_Filter_TD_3373394_output));
    trans_JOIN_INNER_TD_2645078.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_2645078), &(events_h2d_wr_JOIN_INNER_TD_2645078[0]));
    events_grp_JOIN_INNER_TD_2645078.push_back(events_h2d_wr_JOIN_INNER_TD_2645078[0]);
    events_grp_JOIN_INNER_TD_2645078.push_back(events_JOIN_INNER_TD_332118[0]);
    krnl_JOIN_INNER_TD_2645078.run(0, &(events_grp_JOIN_INNER_TD_2645078), &(events_JOIN_INNER_TD_2645078[0]));
    
    trans_JOIN_INNER_TD_2645078_out.add(&(tbl_JOIN_INNER_TD_2645078_output));
    trans_JOIN_INNER_TD_2645078_out.dev2host(0, &(events_JOIN_INNER_TD_2645078), &(events_d2h_rd_JOIN_INNER_TD_2645078[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_2_89084_e, 0);

    struct timeval tv_r_Aggregate_2_906350_s, tv_r_Aggregate_2_906350_e;
    gettimeofday(&tv_r_Aggregate_2_906350_s, 0);
    SW_Aggregate_TD_2384017(tbl_JOIN_INNER_TD_3912575_output, tbl_Aggregate_TD_2384017_output);
    gettimeofday(&tv_r_Aggregate_2_906350_e, 0);

    struct timeval tv_r_JOIN_CROSS_2_501553_s, tv_r_JOIN_CROSS_2_501553_e;
    gettimeofday(&tv_r_JOIN_CROSS_2_501553_s, 0);
    SW_JOIN_CROSS_TD_2364608(tbl_JOIN_CROSS_TD_3927976_output, tbl_Aggregate_TD_3629204_output, tbl_JOIN_CROSS_TD_2364608_output);
    gettimeofday(&tv_r_JOIN_CROSS_2_501553_e, 0);

    struct timeval tv_r_Aggregate_1_365085_s, tv_r_Aggregate_1_365085_e;
    gettimeofday(&tv_r_Aggregate_1_365085_s, 0);
    SW_Aggregate_TD_1840294(tbl_JOIN_INNER_TD_2645078_output, tbl_Aggregate_TD_1840294_output);
    gettimeofday(&tv_r_Aggregate_1_365085_e, 0);

    struct timeval tv_r_JOIN_CROSS_1_5578_s, tv_r_JOIN_CROSS_1_5578_e;
    gettimeofday(&tv_r_JOIN_CROSS_1_5578_s, 0);
    SW_JOIN_CROSS_TD_1212895(tbl_JOIN_CROSS_TD_2364608_output, tbl_Aggregate_TD_2384017_output, tbl_JOIN_CROSS_TD_1212895_output);
    gettimeofday(&tv_r_JOIN_CROSS_1_5578_e, 0);

    struct timeval tv_r_JOIN_CROSS_0_175136_s, tv_r_JOIN_CROSS_0_175136_e;
    gettimeofday(&tv_r_JOIN_CROSS_0_175136_s, 0);
    SW_JOIN_CROSS_TD_086561(tbl_JOIN_CROSS_TD_1212895_output, tbl_Aggregate_TD_1840294_output, tbl_JOIN_CROSS_TD_086561_output);
    gettimeofday(&tv_r_JOIN_CROSS_0_175136_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_192386_s, &tv_r_Filter_11_192386_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1233021_input: " << tbl_SerializeFromObject_TD_1233021_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_304610_s, &tv_r_Filter_11_304610_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12265143_input: " << tbl_SerializeFromObject_TD_12265143_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_733685_s, &tv_r_Filter_11_733685_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12427169_input: " << tbl_SerializeFromObject_TD_12427169_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_349566_s, &tv_r_Filter_11_349566_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12473315_input: " << tbl_SerializeFromObject_TD_12473315_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_848826_s, &tv_r_Filter_10_848826_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11248910_input: " << tbl_SerializeFromObject_TD_11248910_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_401312_s, &tv_r_Filter_10_401312_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11840076_input: " << tbl_SerializeFromObject_TD_11840076_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_328712_s, &tv_r_Filter_10_328712_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11646343_input: " << tbl_SerializeFromObject_TD_11646343_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_344721_s, &tv_r_JOIN_INNER_10_344721_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11494174_output: " << tbl_Filter_TD_11494174_output.getNumRow() << " " << "tbl_Filter_TD_11501915_output: " << tbl_Filter_TD_11501915_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_145460_s, &tv_r_Filter_10_145460_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11139299_input: " << tbl_SerializeFromObject_TD_11139299_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_922638_s, &tv_r_JOIN_INNER_10_922638_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11825044_output: " << tbl_Filter_TD_11825044_output.getNumRow() << " " << "tbl_Filter_TD_11863624_output: " << tbl_Filter_TD_11863624_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_454886_s, &tv_r_Filter_9_454886_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10384773_input: " << tbl_SerializeFromObject_TD_10384773_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_926501_s, &tv_r_Filter_9_926501_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1039924_input: " << tbl_SerializeFromObject_TD_1039924_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_225412_s, &tv_r_Filter_9_225412_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10560310_input: " << tbl_SerializeFromObject_TD_10560310_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_695008_s, &tv_r_JOIN_INNER_9_695008_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10930230_output: " << tbl_Filter_TD_10930230_output.getNumRow() << " " << "tbl_Filter_TD_10112030_output: " << tbl_Filter_TD_10112030_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_744853_s, &tv_r_Filter_9_744853_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10678969_input: " << tbl_SerializeFromObject_TD_10678969_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_303682_s, &tv_r_JOIN_INNER_9_303682_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10472652_output: " << tbl_JOIN_INNER_TD_10472652_output.getNumRow() << " " << "tbl_Filter_TD_10773494_output: " << tbl_Filter_TD_10773494_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_743046_s, &tv_r_Filter_9_743046_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10826019_input: " << tbl_SerializeFromObject_TD_10826019_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_758488_s, &tv_r_JOIN_INNER_9_758488_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10970681_output: " << tbl_JOIN_INNER_TD_10970681_output.getNumRow() << " " << "tbl_Filter_TD_10407068_output: " << tbl_Filter_TD_10407068_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_395537_s, &tv_r_Filter_8_395537_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9324654_input: " << tbl_SerializeFromObject_TD_9324654_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_992480_s, &tv_r_Filter_8_992480_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_910318_input: " << tbl_SerializeFromObject_TD_910318_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_964135_s, &tv_r_Filter_8_964135_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9320282_input: " << tbl_SerializeFromObject_TD_9320282_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_163918_s, &tv_r_JOIN_INNER_8_163918_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9731454_output: " << tbl_Filter_TD_9731454_output.getNumRow() << " " << "tbl_Filter_TD_9721109_output: " << tbl_Filter_TD_9721109_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_534888_s, &tv_r_Filter_8_534888_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9568378_input: " << tbl_SerializeFromObject_TD_9568378_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_967158_s, &tv_r_JOIN_INNER_8_967158_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9323172_output: " << tbl_JOIN_INNER_TD_9323172_output.getNumRow() << " " << "tbl_Filter_TD_9706559_output: " << tbl_Filter_TD_9706559_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_220684_s, &tv_r_JOIN_INNER_8_220684_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9681030_output: " << tbl_JOIN_INNER_TD_9681030_output.getNumRow() << " " << "tbl_Filter_TD_9704552_output: " << tbl_Filter_TD_9704552_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_502351_s, &tv_r_JOIN_INNER_8_502351_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9537683_output: " << tbl_JOIN_INNER_TD_9537683_output.getNumRow() << " " << "tbl_Filter_TD_9319524_output: " << tbl_Filter_TD_9319524_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_162165_s, &tv_r_Filter_7_162165_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8986814_input: " << tbl_SerializeFromObject_TD_8986814_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_407856_s, &tv_r_Filter_7_407856_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8678517_input: " << tbl_SerializeFromObject_TD_8678517_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_762466_s, &tv_r_Filter_7_762466_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8210534_input: " << tbl_SerializeFromObject_TD_8210534_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_474786_s, &tv_r_JOIN_INNER_7_474786_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8395884_output: " << tbl_Filter_TD_8395884_output.getNumRow() << " " << "tbl_Filter_TD_8550963_output: " << tbl_Filter_TD_8550963_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_367862_s, &tv_r_Filter_7_367862_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8488467_input: " << tbl_SerializeFromObject_TD_8488467_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_772990_s, &tv_r_JOIN_INNER_7_772990_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8295220_output: " << tbl_JOIN_INNER_TD_8295220_output.getNumRow() << " " << "tbl_Filter_TD_8123668_output: " << tbl_Filter_TD_8123668_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_474371_s, &tv_r_JOIN_INNER_7_474371_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8123925_output: " << tbl_JOIN_INNER_TD_8123925_output.getNumRow() << " " << "tbl_Filter_TD_8558615_output: " << tbl_Filter_TD_8558615_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_7: " << tvdiff(&tv_r_Aggregate_7_507238_s, &tv_r_Aggregate_7_507238_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8393357_output: " << tbl_JOIN_INNER_TD_8393357_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_7: " << tvdiff(&tv_r_Aggregate_7_765004_s, &tv_r_Aggregate_7_765004_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8444716_output: " << tbl_JOIN_INNER_TD_8444716_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_327305_s, &tv_r_Filter_6_327305_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7430105_input: " << tbl_SerializeFromObject_TD_7430105_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_78914_s, &tv_r_Filter_6_78914_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7705973_input: " << tbl_SerializeFromObject_TD_7705973_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_371159_s, &tv_r_Filter_6_371159_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7679477_input: " << tbl_SerializeFromObject_TD_7679477_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_717520_s, &tv_r_JOIN_INNER_6_717520_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_7710378_output: " << tbl_Filter_TD_7710378_output.getNumRow() << " " << "tbl_Filter_TD_7643990_output: " << tbl_Filter_TD_7643990_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_553984_s, &tv_r_Filter_6_553984_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7674429_input: " << tbl_SerializeFromObject_TD_7674429_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_178451_s, &tv_r_JOIN_INNER_6_178451_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7284355_output: " << tbl_JOIN_INNER_TD_7284355_output.getNumRow() << " " << "tbl_Filter_TD_7632249_output: " << tbl_Filter_TD_7632249_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_769967_s, &tv_r_JOIN_INNER_6_769967_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_733731_output: " << tbl_JOIN_INNER_TD_733731_output.getNumRow() << " " << "tbl_Filter_TD_725548_output: " << tbl_Filter_TD_725548_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_6: " << tvdiff(&tv_r_Aggregate_6_425356_s, &tv_r_Aggregate_6_425356_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7143737_output: " << tbl_JOIN_INNER_TD_7143737_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_CROSS_6: " << tvdiff(&tv_r_JOIN_CROSS_6_562705_s, &tv_r_JOIN_CROSS_6_562705_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_7359641_output: " << tbl_Aggregate_TD_7359641_output.getNumRow() << " " << "tbl_Aggregate_TD_7988832_output: " << tbl_Aggregate_TD_7988832_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_842138_s, &tv_r_Filter_5_842138_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6203791_input: " << tbl_SerializeFromObject_TD_6203791_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_212201_s, &tv_r_Filter_5_212201_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_681115_input: " << tbl_SerializeFromObject_TD_681115_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_830877_s, &tv_r_Filter_5_830877_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6791061_input: " << tbl_SerializeFromObject_TD_6791061_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_680692_s, &tv_r_JOIN_INNER_5_680692_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6868889_output: " << tbl_Filter_TD_6868889_output.getNumRow() << " " << "tbl_Filter_TD_6510134_output: " << tbl_Filter_TD_6510134_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_738894_s, &tv_r_Filter_5_738894_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6424078_input: " << tbl_SerializeFromObject_TD_6424078_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_449952_s, &tv_r_JOIN_INNER_5_449952_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6912217_output: " << tbl_JOIN_INNER_TD_6912217_output.getNumRow() << " " << "tbl_Filter_TD_621706_output: " << tbl_Filter_TD_621706_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_173027_s, &tv_r_JOIN_INNER_5_173027_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6298318_output: " << tbl_JOIN_INNER_TD_6298318_output.getNumRow() << " " << "tbl_Filter_TD_6190390_output: " << tbl_Filter_TD_6190390_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_896929_s, &tv_r_Aggregate_5_896929_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6313985_output: " << tbl_JOIN_INNER_TD_6313985_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_CROSS_5: " << tvdiff(&tv_r_JOIN_CROSS_5_357066_s, &tv_r_JOIN_CROSS_5_357066_e) / 1000.0 << " ms " 
     << "tbl_JOIN_CROSS_TD_6160501_output: " << tbl_JOIN_CROSS_TD_6160501_output.getNumRow() << " " << "tbl_Aggregate_TD_6953350_output: " << tbl_Aggregate_TD_6953350_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_266390_s, &tv_r_Filter_4_266390_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5555205_input: " << tbl_SerializeFromObject_TD_5555205_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_62498_s, &tv_r_JOIN_INNER_4_62498_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_5906846_output: " << tbl_Filter_TD_5906846_output.getNumRow() << " " << "tbl_Filter_TD_5562669_output: " << tbl_Filter_TD_5562669_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_566562_s, &tv_r_Filter_4_566562_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5893686_input: " << tbl_SerializeFromObject_TD_5893686_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_386672_s, &tv_r_JOIN_INNER_4_386672_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5600859_output: " << tbl_JOIN_INNER_TD_5600859_output.getNumRow() << " " << "tbl_Filter_TD_5944573_output: " << tbl_Filter_TD_5944573_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_190802_s, &tv_r_JOIN_INNER_4_190802_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5823975_output: " << tbl_JOIN_INNER_TD_5823975_output.getNumRow() << " " << "tbl_Filter_TD_5329556_output: " << tbl_Filter_TD_5329556_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_4: " << tvdiff(&tv_r_Aggregate_4_740088_s, &tv_r_Aggregate_4_740088_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5336669_output: " << tbl_JOIN_INNER_TD_5336669_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_CROSS_4: " << tvdiff(&tv_r_JOIN_CROSS_4_438786_s, &tv_r_JOIN_CROSS_4_438786_e) / 1000.0 << " ms " 
     << "tbl_JOIN_CROSS_TD_5759888_output: " << tbl_JOIN_CROSS_TD_5759888_output.getNumRow() << " " << "tbl_Aggregate_TD_5162264_output: " << tbl_Aggregate_TD_5162264_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_3: " << tvdiff(&tv_r_Filter_3_783482_s, &tv_r_Filter_3_783482_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_4330522_input: " << tbl_SerializeFromObject_TD_4330522_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_29857_s, &tv_r_JOIN_INNER_3_29857_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_444226_output: " << tbl_JOIN_INNER_TD_444226_output.getNumRow() << " " << "tbl_Filter_TD_4107367_output: " << tbl_Filter_TD_4107367_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_640379_s, &tv_r_JOIN_INNER_3_640379_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_421336_output: " << tbl_JOIN_INNER_TD_421336_output.getNumRow() << " " << "tbl_Filter_TD_4532889_output: " << tbl_Filter_TD_4532889_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_417701_s, &tv_r_Aggregate_3_417701_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4705166_output: " << tbl_JOIN_INNER_TD_4705166_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_CROSS_3: " << tvdiff(&tv_r_JOIN_CROSS_3_343454_s, &tv_r_JOIN_CROSS_3_343454_e) / 1000.0 << " ms " 
     << "tbl_JOIN_CROSS_TD_4414428_output: " << tbl_JOIN_CROSS_TD_4414428_output.getNumRow() << " " << "tbl_Aggregate_TD_4249092_output: " << tbl_Aggregate_TD_4249092_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_2: " << tvdiff(&tv_r_JOIN_INNER_2_89084_s, &tv_r_JOIN_INNER_2_89084_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_332118_output: " << tbl_JOIN_INNER_TD_332118_output.getNumRow() << " " << "tbl_Filter_TD_3373394_output: " << tbl_Filter_TD_3373394_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_2: " << tvdiff(&tv_r_Aggregate_2_906350_s, &tv_r_Aggregate_2_906350_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3912575_output: " << tbl_JOIN_INNER_TD_3912575_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_CROSS_2: " << tvdiff(&tv_r_JOIN_CROSS_2_501553_s, &tv_r_JOIN_CROSS_2_501553_e) / 1000.0 << " ms " 
     << "tbl_JOIN_CROSS_TD_3927976_output: " << tbl_JOIN_CROSS_TD_3927976_output.getNumRow() << " " << "tbl_Aggregate_TD_3629204_output: " << tbl_Aggregate_TD_3629204_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_365085_s, &tv_r_Aggregate_1_365085_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_2645078_output: " << tbl_JOIN_INNER_TD_2645078_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_CROSS_1: " << tvdiff(&tv_r_JOIN_CROSS_1_5578_s, &tv_r_JOIN_CROSS_1_5578_e) / 1000.0 << " ms " 
     << "tbl_JOIN_CROSS_TD_2364608_output: " << tbl_JOIN_CROSS_TD_2364608_output.getNumRow() << " " << "tbl_Aggregate_TD_2384017_output: " << tbl_Aggregate_TD_2384017_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_CROSS_0: " << tvdiff(&tv_r_JOIN_CROSS_0_175136_s, &tv_r_JOIN_CROSS_0_175136_e) / 1000.0 << " ms " 
     << "tbl_JOIN_CROSS_TD_1212895_output: " << tbl_JOIN_CROSS_TD_1212895_output.getNumRow() << " " << "tbl_Aggregate_TD_1840294_output: " << tbl_Aggregate_TD_1840294_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.9755986 * 1000 << "ms" << std::endl; 
    return 0; 
}
