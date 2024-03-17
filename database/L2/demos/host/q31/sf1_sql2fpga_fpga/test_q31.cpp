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

#include "cfgFunc_q31.hpp" 
#include "q31.hpp" 

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
    std::cout << "NOTE:running query #31\n."; 
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
    Table tbl_Sort_TD_0853836_output("tbl_Sort_TD_0853836_output", 6100000, 6, "");
    tbl_Sort_TD_0853836_output.allocateHost();
    Table tbl_Project_TD_1506350_output("tbl_Project_TD_1506350_output", 6100000, 6, "");
    tbl_Project_TD_1506350_output.allocateHost();
    Table tbl_JOIN_INNER_TD_2833924_output("tbl_JOIN_INNER_TD_2833924_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_2833924_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3159277_output("tbl_JOIN_INNER_TD_3159277_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_3159277_output.allocateHost();
    Table tbl_Aggregate_TD_3361928_output("tbl_Aggregate_TD_3361928_output", 6100000, 2, "");
    tbl_Aggregate_TD_3361928_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4757004_output("tbl_JOIN_INNER_TD_4757004_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_4757004_output.allocateHost();
    Table tbl_Aggregate_TD_4174487_output("tbl_Aggregate_TD_4174487_output", 6100000, 2, "");
    tbl_Aggregate_TD_4174487_output.allocateHost();
    Table tbl_JOIN_INNER_TD_412391_output("tbl_JOIN_INNER_TD_412391_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_412391_output.allocateHost();
    Table tbl_JOIN_INNER_TD_56034_output("tbl_JOIN_INNER_TD_56034_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_56034_output.allocateHost();
    Table tbl_Aggregate_TD_5281409_output("tbl_Aggregate_TD_5281409_output", 6100000, 2, "");
    tbl_Aggregate_TD_5281409_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5780330_output("tbl_JOIN_INNER_TD_5780330_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_5780330_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5648307_output("tbl_JOIN_INNER_TD_5648307_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_5648307_output.allocateHost();
    Table tbl_Filter_TD_5427652_output("tbl_Filter_TD_5427652_output", 6100000, 2, "");
    tbl_Filter_TD_5427652_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6883781_output("tbl_JOIN_INNER_TD_6883781_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_6883781_output.allocateHost();
    Table tbl_Aggregate_TD_6401051_output("tbl_Aggregate_TD_6401051_output", 6100000, 2, "");
    tbl_Aggregate_TD_6401051_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6834355_output("tbl_JOIN_INNER_TD_6834355_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_6834355_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6513082_output("tbl_JOIN_INNER_TD_6513082_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_6513082_output.allocateHost();
    Table tbl_Filter_TD_6936522_output("tbl_Filter_TD_6936522_output", 6100000, 2, "");
    tbl_Filter_TD_6936522_output.allocateHost();
    Table tbl_Filter_TD_6875471_output("tbl_Filter_TD_6875471_output", 6100000, 3, "");
    tbl_Filter_TD_6875471_output.allocateHost();
    Table tbl_Filter_TD_694516_output("tbl_Filter_TD_694516_output", 6100000, 3, "");
    tbl_Filter_TD_694516_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6872052_input;
    tbl_SerializeFromObject_TD_6872052_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_6872052_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_6872052_input.addCol("ca_county", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6872052_input.allocateHost();
    tbl_SerializeFromObject_TD_6872052_input.loadHost();
    Table tbl_Aggregate_TD_7393156_output("tbl_Aggregate_TD_7393156_output", 6100000, 3, "");
    tbl_Aggregate_TD_7393156_output.allocateHost();
    Table tbl_Aggregate_TD_7282392_output("tbl_Aggregate_TD_7282392_output", 6100000, 2, "");
    tbl_Aggregate_TD_7282392_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7452580_output("tbl_JOIN_INNER_TD_7452580_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_7452580_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7616985_output("tbl_JOIN_INNER_TD_7616985_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_7616985_output.allocateHost();
    Table tbl_Filter_TD_7689133_output("tbl_Filter_TD_7689133_output", 6100000, 2, "");
    tbl_Filter_TD_7689133_output.allocateHost();
    Table tbl_Filter_TD_7224122_output("tbl_Filter_TD_7224122_output", 6100000, 3, "");
    tbl_Filter_TD_7224122_output.allocateHost();
    Table tbl_Filter_TD_7752021_output("tbl_Filter_TD_7752021_output", 6100000, 3, "");
    tbl_Filter_TD_7752021_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7451227_input;
    tbl_SerializeFromObject_TD_7451227_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7451227_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_7451227_input.addCol("ca_county", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7451227_input.allocateHost();
    tbl_SerializeFromObject_TD_7451227_input.loadHost();
    Table tbl_SerializeFromObject_TD_7110449_input;
    tbl_SerializeFromObject_TD_7110449_input = Table("web_sales", web_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7110449_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_7110449_input.addCol("ws_bill_addr_sk", 4);
    tbl_SerializeFromObject_TD_7110449_input.addCol("ws_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_7110449_input.allocateHost();
    tbl_SerializeFromObject_TD_7110449_input.loadHost();
    Table tbl_SerializeFromObject_TD_7421218_input;
    tbl_SerializeFromObject_TD_7421218_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7421218_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_7421218_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_7421218_input.addCol("d_qoy", 4);
    tbl_SerializeFromObject_TD_7421218_input.allocateHost();
    tbl_SerializeFromObject_TD_7421218_input.loadHost();
    Table tbl_JOIN_INNER_TD_8588441_output("tbl_JOIN_INNER_TD_8588441_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_8588441_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8914256_output("tbl_JOIN_INNER_TD_8914256_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_8914256_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8666731_output("tbl_JOIN_INNER_TD_8666731_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_8666731_output.allocateHost();
    Table tbl_Filter_TD_8760047_output("tbl_Filter_TD_8760047_output", 6100000, 2, "");
    tbl_Filter_TD_8760047_output.allocateHost();
    Table tbl_Filter_TD_8645917_output("tbl_Filter_TD_8645917_output", 6100000, 3, "");
    tbl_Filter_TD_8645917_output.allocateHost();
    Table tbl_Filter_TD_8273211_output("tbl_Filter_TD_8273211_output", 6100000, 3, "");
    tbl_Filter_TD_8273211_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8113542_input;
    tbl_SerializeFromObject_TD_8113542_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8113542_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_8113542_input.addCol("ca_county", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8113542_input.allocateHost();
    tbl_SerializeFromObject_TD_8113542_input.loadHost();
    Table tbl_SerializeFromObject_TD_8224831_input;
    tbl_SerializeFromObject_TD_8224831_input = Table("web_sales", web_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8224831_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_8224831_input.addCol("ws_bill_addr_sk", 4);
    tbl_SerializeFromObject_TD_8224831_input.addCol("ws_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_8224831_input.allocateHost();
    tbl_SerializeFromObject_TD_8224831_input.loadHost();
    Table tbl_SerializeFromObject_TD_8558338_input;
    tbl_SerializeFromObject_TD_8558338_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8558338_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_8558338_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_8558338_input.addCol("d_qoy", 4);
    tbl_SerializeFromObject_TD_8558338_input.allocateHost();
    tbl_SerializeFromObject_TD_8558338_input.loadHost();
    Table tbl_JOIN_INNER_TD_9888218_output("tbl_JOIN_INNER_TD_9888218_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_9888218_output.allocateHost();
    Table tbl_Filter_TD_9913508_output("tbl_Filter_TD_9913508_output", 6100000, 2, "");
    tbl_Filter_TD_9913508_output.allocateHost();
    Table tbl_JOIN_INNER_TD_9874636_output("tbl_JOIN_INNER_TD_9874636_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_9874636_output.allocateHost();
    Table tbl_Filter_TD_9281970_output("tbl_Filter_TD_9281970_output", 6100000, 2, "");
    tbl_Filter_TD_9281970_output.allocateHost();
    Table tbl_Filter_TD_9673388_output("tbl_Filter_TD_9673388_output", 6100000, 3, "");
    tbl_Filter_TD_9673388_output.allocateHost();
    Table tbl_Filter_TD_9611663_output("tbl_Filter_TD_9611663_output", 6100000, 3, "");
    tbl_Filter_TD_9611663_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9124573_input;
    tbl_SerializeFromObject_TD_9124573_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9124573_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_9124573_input.addCol("ca_county", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9124573_input.allocateHost();
    tbl_SerializeFromObject_TD_9124573_input.loadHost();
    Table tbl_SerializeFromObject_TD_9345771_input;
    tbl_SerializeFromObject_TD_9345771_input = Table("web_sales", web_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9345771_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_9345771_input.addCol("ws_bill_addr_sk", 4);
    tbl_SerializeFromObject_TD_9345771_input.addCol("ws_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_9345771_input.allocateHost();
    tbl_SerializeFromObject_TD_9345771_input.loadHost();
    Table tbl_SerializeFromObject_TD_9849394_input;
    tbl_SerializeFromObject_TD_9849394_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9849394_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_9849394_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_9849394_input.addCol("d_qoy", 4);
    tbl_SerializeFromObject_TD_9849394_input.allocateHost();
    tbl_SerializeFromObject_TD_9849394_input.loadHost();
    Table tbl_Filter_TD_10907178_output("tbl_Filter_TD_10907178_output", 6100000, 3, "");
    tbl_Filter_TD_10907178_output.allocateHost();
    Table tbl_Filter_TD_10222848_output("tbl_Filter_TD_10222848_output", 6100000, 3, "");
    tbl_Filter_TD_10222848_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10128076_input;
    tbl_SerializeFromObject_TD_10128076_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10128076_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_10128076_input.addCol("ca_county", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10128076_input.allocateHost();
    tbl_SerializeFromObject_TD_10128076_input.loadHost();
    Table tbl_Filter_TD_10946768_output("tbl_Filter_TD_10946768_output", 6100000, 3, "");
    tbl_Filter_TD_10946768_output.allocateHost();
    Table tbl_Filter_TD_10959900_output("tbl_Filter_TD_10959900_output", 6100000, 3, "");
    tbl_Filter_TD_10959900_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10148362_input;
    tbl_SerializeFromObject_TD_10148362_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10148362_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_10148362_input.addCol("ca_county", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10148362_input.allocateHost();
    tbl_SerializeFromObject_TD_10148362_input.loadHost();
    Table tbl_SerializeFromObject_TD_1089102_input;
    tbl_SerializeFromObject_TD_1089102_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_1089102_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_1089102_input.addCol("ss_addr_sk", 4);
    tbl_SerializeFromObject_TD_1089102_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_1089102_input.allocateHost();
    tbl_SerializeFromObject_TD_1089102_input.loadHost();
    Table tbl_SerializeFromObject_TD_10307863_input;
    tbl_SerializeFromObject_TD_10307863_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10307863_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10307863_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10307863_input.addCol("d_qoy", 4);
    tbl_SerializeFromObject_TD_10307863_input.allocateHost();
    tbl_SerializeFromObject_TD_10307863_input.loadHost();
    Table tbl_SerializeFromObject_TD_1126797_input;
    tbl_SerializeFromObject_TD_1126797_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_1126797_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_1126797_input.addCol("ss_addr_sk", 4);
    tbl_SerializeFromObject_TD_1126797_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_1126797_input.allocateHost();
    tbl_SerializeFromObject_TD_1126797_input.loadHost();
    Table tbl_SerializeFromObject_TD_11404989_input;
    tbl_SerializeFromObject_TD_11404989_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11404989_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_11404989_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_11404989_input.addCol("d_qoy", 4);
    tbl_SerializeFromObject_TD_11404989_input.allocateHost();
    tbl_SerializeFromObject_TD_11404989_input.loadHost();
    Table tbl_SerializeFromObject_TD_11334014_input;
    tbl_SerializeFromObject_TD_11334014_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11334014_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_11334014_input.addCol("ss_addr_sk", 4);
    tbl_SerializeFromObject_TD_11334014_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_11334014_input.allocateHost();
    tbl_SerializeFromObject_TD_11334014_input.loadHost();
    Table tbl_SerializeFromObject_TD_11452411_input;
    tbl_SerializeFromObject_TD_11452411_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11452411_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_11452411_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_11452411_input.addCol("d_qoy", 4);
    tbl_SerializeFromObject_TD_11452411_input.allocateHost();
    tbl_SerializeFromObject_TD_11452411_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_5648307_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_6513082_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_6875471_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_694516_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_7616985_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_7224122_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_7752021_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8666731_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8645917_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8273211_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_9888218_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_9874636_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9673388_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9611663_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10907178_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10222848_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10946768_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10959900_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_5648307_cmds;
    cfg_JOIN_INNER_TD_5648307_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_5648307_gqe_join (cfg_JOIN_INNER_TD_5648307_cmds.cmd);
    cfg_JOIN_INNER_TD_5648307_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_6513082_cmds;
    cfg_JOIN_INNER_TD_6513082_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_6513082_gqe_join (cfg_JOIN_INNER_TD_6513082_cmds.cmd);
    cfg_JOIN_INNER_TD_6513082_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7616985_cmds;
    cfg_JOIN_INNER_TD_7616985_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7616985_gqe_join (cfg_JOIN_INNER_TD_7616985_cmds.cmd);
    cfg_JOIN_INNER_TD_7616985_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8666731_cmds;
    cfg_JOIN_INNER_TD_8666731_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8666731_gqe_join (cfg_JOIN_INNER_TD_8666731_cmds.cmd);
    cfg_JOIN_INNER_TD_8666731_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_9888218_cmds;
    cfg_JOIN_INNER_TD_9888218_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_9888218_gqe_join (cfg_JOIN_INNER_TD_9888218_cmds.cmd);
    cfg_JOIN_INNER_TD_9888218_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_9874636_cmds;
    cfg_JOIN_INNER_TD_9874636_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_9874636_gqe_join (cfg_JOIN_INNER_TD_9874636_cmds.cmd);
    cfg_JOIN_INNER_TD_9874636_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_5648307;
    krnl_JOIN_INNER_TD_5648307 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_5648307.setup(tbl_Filter_TD_6875471_output, tbl_Filter_TD_694516_output, tbl_JOIN_INNER_TD_5648307_output, cfg_JOIN_INNER_TD_5648307_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_6513082;
    krnl_JOIN_INNER_TD_6513082 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_6513082.setup(tbl_Filter_TD_7224122_output, tbl_Filter_TD_7752021_output, tbl_JOIN_INNER_TD_6513082_output, cfg_JOIN_INNER_TD_6513082_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_7616985;
    krnl_JOIN_INNER_TD_7616985 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7616985.setup(tbl_Filter_TD_8645917_output, tbl_Filter_TD_8273211_output, tbl_JOIN_INNER_TD_7616985_output, cfg_JOIN_INNER_TD_7616985_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_8666731;
    krnl_JOIN_INNER_TD_8666731 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8666731.setup(tbl_Filter_TD_9673388_output, tbl_Filter_TD_9611663_output, tbl_JOIN_INNER_TD_8666731_output, cfg_JOIN_INNER_TD_8666731_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_9888218;
    krnl_JOIN_INNER_TD_9888218 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_9888218.setup(tbl_Filter_TD_10907178_output, tbl_Filter_TD_10222848_output, tbl_JOIN_INNER_TD_9888218_output, cfg_JOIN_INNER_TD_9888218_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_9874636;
    krnl_JOIN_INNER_TD_9874636 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_9874636.setup(tbl_Filter_TD_10946768_output, tbl_Filter_TD_10959900_output, tbl_JOIN_INNER_TD_9874636_output, cfg_JOIN_INNER_TD_9874636_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_5648307;
    trans_JOIN_INNER_TD_5648307.setq(q_h);
    trans_JOIN_INNER_TD_5648307.add(&(cfg_JOIN_INNER_TD_5648307_cmds));
    transEngine trans_JOIN_INNER_TD_5648307_out;
    trans_JOIN_INNER_TD_5648307_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_6513082;
    trans_JOIN_INNER_TD_6513082.setq(q_h);
    trans_JOIN_INNER_TD_6513082.add(&(cfg_JOIN_INNER_TD_6513082_cmds));
    transEngine trans_JOIN_INNER_TD_6513082_out;
    trans_JOIN_INNER_TD_6513082_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_7616985;
    trans_JOIN_INNER_TD_7616985.setq(q_h);
    trans_JOIN_INNER_TD_7616985.add(&(cfg_JOIN_INNER_TD_7616985_cmds));
    transEngine trans_JOIN_INNER_TD_7616985_out;
    trans_JOIN_INNER_TD_7616985_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_8666731;
    trans_JOIN_INNER_TD_8666731.setq(q_h);
    trans_JOIN_INNER_TD_8666731.add(&(cfg_JOIN_INNER_TD_8666731_cmds));
    transEngine trans_JOIN_INNER_TD_8666731_out;
    trans_JOIN_INNER_TD_8666731_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_9888218;
    trans_JOIN_INNER_TD_9888218.setq(q_h);
    trans_JOIN_INNER_TD_9888218.add(&(cfg_JOIN_INNER_TD_9888218_cmds));
    transEngine trans_JOIN_INNER_TD_9888218_out;
    trans_JOIN_INNER_TD_9888218_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_9874636;
    trans_JOIN_INNER_TD_9874636.setq(q_h);
    trans_JOIN_INNER_TD_9874636.add(&(cfg_JOIN_INNER_TD_9874636_cmds));
    transEngine trans_JOIN_INNER_TD_9874636_out;
    trans_JOIN_INNER_TD_9874636_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_5648307;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_5648307;
    std::vector<cl::Event> events_JOIN_INNER_TD_5648307;
    events_h2d_wr_JOIN_INNER_TD_5648307.resize(1);
    events_d2h_rd_JOIN_INNER_TD_5648307.resize(1);
    events_JOIN_INNER_TD_5648307.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_5648307;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_5648307;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_6513082;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_6513082;
    std::vector<cl::Event> events_JOIN_INNER_TD_6513082;
    events_h2d_wr_JOIN_INNER_TD_6513082.resize(1);
    events_d2h_rd_JOIN_INNER_TD_6513082.resize(1);
    events_JOIN_INNER_TD_6513082.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_6513082;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_6513082;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7616985;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7616985;
    std::vector<cl::Event> events_JOIN_INNER_TD_7616985;
    events_h2d_wr_JOIN_INNER_TD_7616985.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7616985.resize(1);
    events_JOIN_INNER_TD_7616985.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7616985;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7616985;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8666731;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8666731;
    std::vector<cl::Event> events_JOIN_INNER_TD_8666731;
    events_h2d_wr_JOIN_INNER_TD_8666731.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8666731.resize(1);
    events_JOIN_INNER_TD_8666731.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8666731;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8666731;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_9888218;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_9888218;
    std::vector<cl::Event> events_JOIN_INNER_TD_9888218;
    events_h2d_wr_JOIN_INNER_TD_9888218.resize(1);
    events_d2h_rd_JOIN_INNER_TD_9888218.resize(1);
    events_JOIN_INNER_TD_9888218.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_9888218;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_9888218;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_9874636;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_9874636;
    std::vector<cl::Event> events_JOIN_INNER_TD_9874636;
    events_h2d_wr_JOIN_INNER_TD_9874636.resize(1);
    events_d2h_rd_JOIN_INNER_TD_9874636.resize(1);
    events_JOIN_INNER_TD_9874636.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_9874636;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_9874636;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_10_945826_s, tv_r_Filter_10_945826_e;
    gettimeofday(&tv_r_Filter_10_945826_s, 0);
    SW_Filter_TD_10959900(tbl_SerializeFromObject_TD_11452411_input, tbl_Filter_TD_10959900_output);
    gettimeofday(&tv_r_Filter_10_945826_e, 0);

    struct timeval tv_r_Filter_10_244314_s, tv_r_Filter_10_244314_e;
    gettimeofday(&tv_r_Filter_10_244314_s, 0);
    SW_Filter_TD_10946768(tbl_SerializeFromObject_TD_11334014_input, tbl_Filter_TD_10946768_output);
    gettimeofday(&tv_r_Filter_10_244314_e, 0);

    struct timeval tv_r_Filter_10_685344_s, tv_r_Filter_10_685344_e;
    gettimeofday(&tv_r_Filter_10_685344_s, 0);
    SW_Filter_TD_10222848(tbl_SerializeFromObject_TD_11404989_input, tbl_Filter_TD_10222848_output);
    gettimeofday(&tv_r_Filter_10_685344_e, 0);

    struct timeval tv_r_Filter_10_1792_s, tv_r_Filter_10_1792_e;
    gettimeofday(&tv_r_Filter_10_1792_s, 0);
    SW_Filter_TD_10907178(tbl_SerializeFromObject_TD_1126797_input, tbl_Filter_TD_10907178_output);
    gettimeofday(&tv_r_Filter_10_1792_e, 0);

    struct timeval tv_r_Filter_9_957699_s, tv_r_Filter_9_957699_e;
    gettimeofday(&tv_r_Filter_9_957699_s, 0);
    SW_Filter_TD_9611663(tbl_SerializeFromObject_TD_10307863_input, tbl_Filter_TD_9611663_output);
    gettimeofday(&tv_r_Filter_9_957699_e, 0);

    struct timeval tv_r_Filter_9_499987_s, tv_r_Filter_9_499987_e;
    gettimeofday(&tv_r_Filter_9_499987_s, 0);
    SW_Filter_TD_9673388(tbl_SerializeFromObject_TD_1089102_input, tbl_Filter_TD_9673388_output);
    gettimeofday(&tv_r_Filter_9_499987_e, 0);

    struct timeval tv_r_Filter_9_723731_s, tv_r_Filter_9_723731_e;
    gettimeofday(&tv_r_Filter_9_723731_s, 0);
    SW_Filter_TD_9281970(tbl_SerializeFromObject_TD_10148362_input, tbl_Filter_TD_9281970_output);
    gettimeofday(&tv_r_Filter_9_723731_e, 0);

    struct timeval tv_r_JOIN_INNER_9_560083_s, tv_r_JOIN_INNER_9_560083_e;
    gettimeofday(&tv_r_JOIN_INNER_9_560083_s, 0);
    trans_JOIN_INNER_TD_9874636.add(&(tbl_Filter_TD_10946768_output));
    trans_JOIN_INNER_TD_9874636.add(&(tbl_Filter_TD_10959900_output));
    trans_JOIN_INNER_TD_9874636.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_9874636), &(events_h2d_wr_JOIN_INNER_TD_9874636[0]));
    events_grp_JOIN_INNER_TD_9874636.push_back(events_h2d_wr_JOIN_INNER_TD_9874636[0]);
    krnl_JOIN_INNER_TD_9874636.run(0, &(events_grp_JOIN_INNER_TD_9874636), &(events_JOIN_INNER_TD_9874636[0]));
    
    trans_JOIN_INNER_TD_9874636_out.add(&(tbl_JOIN_INNER_TD_9874636_output));
    trans_JOIN_INNER_TD_9874636_out.dev2host(0, &(events_JOIN_INNER_TD_9874636), &(events_d2h_rd_JOIN_INNER_TD_9874636[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_9_560083_e, 0);

    struct timeval tv_r_Filter_9_936056_s, tv_r_Filter_9_936056_e;
    gettimeofday(&tv_r_Filter_9_936056_s, 0);
    SW_Filter_TD_9913508(tbl_SerializeFromObject_TD_10128076_input, tbl_Filter_TD_9913508_output);
    gettimeofday(&tv_r_Filter_9_936056_e, 0);

    struct timeval tv_r_JOIN_INNER_9_574782_s, tv_r_JOIN_INNER_9_574782_e;
    gettimeofday(&tv_r_JOIN_INNER_9_574782_s, 0);
    trans_JOIN_INNER_TD_9888218.add(&(tbl_Filter_TD_10907178_output));
    trans_JOIN_INNER_TD_9888218.add(&(tbl_Filter_TD_10222848_output));
    trans_JOIN_INNER_TD_9888218.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_9888218), &(events_h2d_wr_JOIN_INNER_TD_9888218[0]));
    events_grp_JOIN_INNER_TD_9888218.push_back(events_h2d_wr_JOIN_INNER_TD_9888218[0]);
    krnl_JOIN_INNER_TD_9888218.run(0, &(events_grp_JOIN_INNER_TD_9888218), &(events_JOIN_INNER_TD_9888218[0]));
    
    trans_JOIN_INNER_TD_9888218_out.add(&(tbl_JOIN_INNER_TD_9888218_output));
    trans_JOIN_INNER_TD_9888218_out.dev2host(0, &(events_JOIN_INNER_TD_9888218), &(events_d2h_rd_JOIN_INNER_TD_9888218[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_9_574782_e, 0);

    struct timeval tv_r_Filter_8_309513_s, tv_r_Filter_8_309513_e;
    gettimeofday(&tv_r_Filter_8_309513_s, 0);
    SW_Filter_TD_8273211(tbl_SerializeFromObject_TD_9849394_input, tbl_Filter_TD_8273211_output);
    gettimeofday(&tv_r_Filter_8_309513_e, 0);

    struct timeval tv_r_Filter_8_597327_s, tv_r_Filter_8_597327_e;
    gettimeofday(&tv_r_Filter_8_597327_s, 0);
    SW_Filter_TD_8645917(tbl_SerializeFromObject_TD_9345771_input, tbl_Filter_TD_8645917_output);
    gettimeofday(&tv_r_Filter_8_597327_e, 0);

    struct timeval tv_r_Filter_8_417077_s, tv_r_Filter_8_417077_e;
    gettimeofday(&tv_r_Filter_8_417077_s, 0);
    SW_Filter_TD_8760047(tbl_SerializeFromObject_TD_9124573_input, tbl_Filter_TD_8760047_output);
    gettimeofday(&tv_r_Filter_8_417077_e, 0);

    struct timeval tv_r_JOIN_INNER_8_245168_s, tv_r_JOIN_INNER_8_245168_e;
    gettimeofday(&tv_r_JOIN_INNER_8_245168_s, 0);
    trans_JOIN_INNER_TD_8666731.add(&(tbl_Filter_TD_9673388_output));
    trans_JOIN_INNER_TD_8666731.add(&(tbl_Filter_TD_9611663_output));
    trans_JOIN_INNER_TD_8666731.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8666731), &(events_h2d_wr_JOIN_INNER_TD_8666731[0]));
    events_grp_JOIN_INNER_TD_8666731.push_back(events_h2d_wr_JOIN_INNER_TD_8666731[0]);
    krnl_JOIN_INNER_TD_8666731.run(0, &(events_grp_JOIN_INNER_TD_8666731), &(events_JOIN_INNER_TD_8666731[0]));
    
    trans_JOIN_INNER_TD_8666731_out.add(&(tbl_JOIN_INNER_TD_8666731_output));
    trans_JOIN_INNER_TD_8666731_out.dev2host(0, &(events_JOIN_INNER_TD_8666731), &(events_d2h_rd_JOIN_INNER_TD_8666731[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_8_245168_e, 0);

    struct timeval tv_r_JOIN_INNER_8_687663_s, tv_r_JOIN_INNER_8_687663_e;
    gettimeofday(&tv_r_JOIN_INNER_8_687663_s, 0);
    SW_JOIN_INNER_TD_8914256(tbl_JOIN_INNER_TD_9874636_output, tbl_Filter_TD_9281970_output, tbl_JOIN_INNER_TD_8914256_output);
    gettimeofday(&tv_r_JOIN_INNER_8_687663_e, 0);

    struct timeval tv_r_JOIN_INNER_8_573273_s, tv_r_JOIN_INNER_8_573273_e;
    gettimeofday(&tv_r_JOIN_INNER_8_573273_s, 0);
    SW_JOIN_INNER_TD_8588441(tbl_JOIN_INNER_TD_9888218_output, tbl_Filter_TD_9913508_output, tbl_JOIN_INNER_TD_8588441_output);
    gettimeofday(&tv_r_JOIN_INNER_8_573273_e, 0);

    struct timeval tv_r_Filter_7_724430_s, tv_r_Filter_7_724430_e;
    gettimeofday(&tv_r_Filter_7_724430_s, 0);
    SW_Filter_TD_7752021(tbl_SerializeFromObject_TD_8558338_input, tbl_Filter_TD_7752021_output);
    gettimeofday(&tv_r_Filter_7_724430_e, 0);

    struct timeval tv_r_Filter_7_733173_s, tv_r_Filter_7_733173_e;
    gettimeofday(&tv_r_Filter_7_733173_s, 0);
    SW_Filter_TD_7224122(tbl_SerializeFromObject_TD_8224831_input, tbl_Filter_TD_7224122_output);
    gettimeofday(&tv_r_Filter_7_733173_e, 0);

    struct timeval tv_r_Filter_7_324779_s, tv_r_Filter_7_324779_e;
    gettimeofday(&tv_r_Filter_7_324779_s, 0);
    SW_Filter_TD_7689133(tbl_SerializeFromObject_TD_8113542_input, tbl_Filter_TD_7689133_output);
    gettimeofday(&tv_r_Filter_7_324779_e, 0);

    struct timeval tv_r_JOIN_INNER_7_271217_s, tv_r_JOIN_INNER_7_271217_e;
    gettimeofday(&tv_r_JOIN_INNER_7_271217_s, 0);
    trans_JOIN_INNER_TD_7616985.add(&(tbl_Filter_TD_8645917_output));
    trans_JOIN_INNER_TD_7616985.add(&(tbl_Filter_TD_8273211_output));
    trans_JOIN_INNER_TD_7616985.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7616985), &(events_h2d_wr_JOIN_INNER_TD_7616985[0]));
    events_grp_JOIN_INNER_TD_7616985.push_back(events_h2d_wr_JOIN_INNER_TD_7616985[0]);
    krnl_JOIN_INNER_TD_7616985.run(0, &(events_grp_JOIN_INNER_TD_7616985), &(events_JOIN_INNER_TD_7616985[0]));
    
    trans_JOIN_INNER_TD_7616985_out.add(&(tbl_JOIN_INNER_TD_7616985_output));
    trans_JOIN_INNER_TD_7616985_out.dev2host(0, &(events_JOIN_INNER_TD_7616985), &(events_d2h_rd_JOIN_INNER_TD_7616985[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_7_271217_e, 0);

    struct timeval tv_r_JOIN_INNER_7_362896_s, tv_r_JOIN_INNER_7_362896_e;
    gettimeofday(&tv_r_JOIN_INNER_7_362896_s, 0);
    SW_JOIN_INNER_TD_7452580(tbl_JOIN_INNER_TD_8666731_output, tbl_Filter_TD_8760047_output, tbl_JOIN_INNER_TD_7452580_output);
    gettimeofday(&tv_r_JOIN_INNER_7_362896_e, 0);

    struct timeval tv_r_Aggregate_7_290273_s, tv_r_Aggregate_7_290273_e;
    gettimeofday(&tv_r_Aggregate_7_290273_s, 0);
    SW_Aggregate_TD_7282392(tbl_JOIN_INNER_TD_8914256_output, tbl_Aggregate_TD_7282392_output);
    gettimeofday(&tv_r_Aggregate_7_290273_e, 0);

    struct timeval tv_r_Aggregate_7_146760_s, tv_r_Aggregate_7_146760_e;
    gettimeofday(&tv_r_Aggregate_7_146760_s, 0);
    SW_Aggregate_TD_7393156(tbl_JOIN_INNER_TD_8588441_output, tbl_Aggregate_TD_7393156_output);
    gettimeofday(&tv_r_Aggregate_7_146760_e, 0);

    struct timeval tv_r_Filter_6_359764_s, tv_r_Filter_6_359764_e;
    gettimeofday(&tv_r_Filter_6_359764_s, 0);
    SW_Filter_TD_694516(tbl_SerializeFromObject_TD_7421218_input, tbl_Filter_TD_694516_output);
    gettimeofday(&tv_r_Filter_6_359764_e, 0);

    struct timeval tv_r_Filter_6_224762_s, tv_r_Filter_6_224762_e;
    gettimeofday(&tv_r_Filter_6_224762_s, 0);
    SW_Filter_TD_6875471(tbl_SerializeFromObject_TD_7110449_input, tbl_Filter_TD_6875471_output);
    gettimeofday(&tv_r_Filter_6_224762_e, 0);

    struct timeval tv_r_Filter_6_507268_s, tv_r_Filter_6_507268_e;
    gettimeofday(&tv_r_Filter_6_507268_s, 0);
    SW_Filter_TD_6936522(tbl_SerializeFromObject_TD_7451227_input, tbl_Filter_TD_6936522_output);
    gettimeofday(&tv_r_Filter_6_507268_e, 0);

    struct timeval tv_r_JOIN_INNER_6_281916_s, tv_r_JOIN_INNER_6_281916_e;
    gettimeofday(&tv_r_JOIN_INNER_6_281916_s, 0);
    trans_JOIN_INNER_TD_6513082.add(&(tbl_Filter_TD_7224122_output));
    trans_JOIN_INNER_TD_6513082.add(&(tbl_Filter_TD_7752021_output));
    trans_JOIN_INNER_TD_6513082.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_6513082), &(events_h2d_wr_JOIN_INNER_TD_6513082[0]));
    events_grp_JOIN_INNER_TD_6513082.push_back(events_h2d_wr_JOIN_INNER_TD_6513082[0]);
    krnl_JOIN_INNER_TD_6513082.run(0, &(events_grp_JOIN_INNER_TD_6513082), &(events_JOIN_INNER_TD_6513082[0]));
    
    trans_JOIN_INNER_TD_6513082_out.add(&(tbl_JOIN_INNER_TD_6513082_output));
    trans_JOIN_INNER_TD_6513082_out.dev2host(0, &(events_JOIN_INNER_TD_6513082), &(events_d2h_rd_JOIN_INNER_TD_6513082[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_6_281916_e, 0);

    struct timeval tv_r_JOIN_INNER_6_661441_s, tv_r_JOIN_INNER_6_661441_e;
    gettimeofday(&tv_r_JOIN_INNER_6_661441_s, 0);
    SW_JOIN_INNER_TD_6834355(tbl_JOIN_INNER_TD_7616985_output, tbl_Filter_TD_7689133_output, tbl_JOIN_INNER_TD_6834355_output);
    gettimeofday(&tv_r_JOIN_INNER_6_661441_e, 0);

    struct timeval tv_r_Aggregate_6_446683_s, tv_r_Aggregate_6_446683_e;
    gettimeofday(&tv_r_Aggregate_6_446683_s, 0);
    SW_Aggregate_TD_6401051(tbl_JOIN_INNER_TD_7452580_output, tbl_Aggregate_TD_6401051_output);
    gettimeofday(&tv_r_Aggregate_6_446683_e, 0);

    struct timeval tv_r_JOIN_INNER_6_217211_s, tv_r_JOIN_INNER_6_217211_e;
    gettimeofday(&tv_r_JOIN_INNER_6_217211_s, 0);
    SW_JOIN_INNER_TD_6883781(tbl_Aggregate_TD_7393156_output, tbl_Aggregate_TD_7282392_output, tbl_JOIN_INNER_TD_6883781_output);
    gettimeofday(&tv_r_JOIN_INNER_6_217211_e, 0);

    struct timeval tv_r_Filter_5_465426_s, tv_r_Filter_5_465426_e;
    gettimeofday(&tv_r_Filter_5_465426_s, 0);
    SW_Filter_TD_5427652(tbl_SerializeFromObject_TD_6872052_input, tbl_Filter_TD_5427652_output);
    gettimeofday(&tv_r_Filter_5_465426_e, 0);

    struct timeval tv_r_JOIN_INNER_5_176920_s, tv_r_JOIN_INNER_5_176920_e;
    gettimeofday(&tv_r_JOIN_INNER_5_176920_s, 0);
    trans_JOIN_INNER_TD_5648307.add(&(tbl_Filter_TD_6875471_output));
    trans_JOIN_INNER_TD_5648307.add(&(tbl_Filter_TD_694516_output));
    trans_JOIN_INNER_TD_5648307.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_5648307), &(events_h2d_wr_JOIN_INNER_TD_5648307[0]));
    events_grp_JOIN_INNER_TD_5648307.push_back(events_h2d_wr_JOIN_INNER_TD_5648307[0]);
    krnl_JOIN_INNER_TD_5648307.run(0, &(events_grp_JOIN_INNER_TD_5648307), &(events_JOIN_INNER_TD_5648307[0]));
    
    trans_JOIN_INNER_TD_5648307_out.add(&(tbl_JOIN_INNER_TD_5648307_output));
    trans_JOIN_INNER_TD_5648307_out.dev2host(0, &(events_JOIN_INNER_TD_5648307), &(events_d2h_rd_JOIN_INNER_TD_5648307[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_5_176920_e, 0);

    struct timeval tv_r_JOIN_INNER_5_812617_s, tv_r_JOIN_INNER_5_812617_e;
    gettimeofday(&tv_r_JOIN_INNER_5_812617_s, 0);
    SW_JOIN_INNER_TD_5780330(tbl_JOIN_INNER_TD_6513082_output, tbl_Filter_TD_6936522_output, tbl_JOIN_INNER_TD_5780330_output);
    gettimeofday(&tv_r_JOIN_INNER_5_812617_e, 0);

    struct timeval tv_r_Aggregate_5_803299_s, tv_r_Aggregate_5_803299_e;
    gettimeofday(&tv_r_Aggregate_5_803299_s, 0);
    SW_Aggregate_TD_5281409(tbl_JOIN_INNER_TD_6834355_output, tbl_Aggregate_TD_5281409_output);
    gettimeofday(&tv_r_Aggregate_5_803299_e, 0);

    struct timeval tv_r_JOIN_INNER_5_349368_s, tv_r_JOIN_INNER_5_349368_e;
    gettimeofday(&tv_r_JOIN_INNER_5_349368_s, 0);
    SW_JOIN_INNER_TD_56034(tbl_JOIN_INNER_TD_6883781_output, tbl_Aggregate_TD_6401051_output, tbl_JOIN_INNER_TD_56034_output);
    gettimeofday(&tv_r_JOIN_INNER_5_349368_e, 0);

    struct timeval tv_r_JOIN_INNER_4_979741_s, tv_r_JOIN_INNER_4_979741_e;
    gettimeofday(&tv_r_JOIN_INNER_4_979741_s, 0);
    SW_JOIN_INNER_TD_412391(tbl_JOIN_INNER_TD_5648307_output, tbl_Filter_TD_5427652_output, tbl_JOIN_INNER_TD_412391_output);
    gettimeofday(&tv_r_JOIN_INNER_4_979741_e, 0);

    struct timeval tv_r_Aggregate_4_719291_s, tv_r_Aggregate_4_719291_e;
    gettimeofday(&tv_r_Aggregate_4_719291_s, 0);
    SW_Aggregate_TD_4174487(tbl_JOIN_INNER_TD_5780330_output, tbl_Aggregate_TD_4174487_output);
    gettimeofday(&tv_r_Aggregate_4_719291_e, 0);

    struct timeval tv_r_JOIN_INNER_4_542313_s, tv_r_JOIN_INNER_4_542313_e;
    gettimeofday(&tv_r_JOIN_INNER_4_542313_s, 0);
    SW_JOIN_INNER_TD_4757004(tbl_JOIN_INNER_TD_56034_output, tbl_Aggregate_TD_5281409_output, tbl_JOIN_INNER_TD_4757004_output);
    gettimeofday(&tv_r_JOIN_INNER_4_542313_e, 0);

    struct timeval tv_r_Aggregate_3_746023_s, tv_r_Aggregate_3_746023_e;
    gettimeofday(&tv_r_Aggregate_3_746023_s, 0);
    SW_Aggregate_TD_3361928(tbl_JOIN_INNER_TD_412391_output, tbl_Aggregate_TD_3361928_output);
    gettimeofday(&tv_r_Aggregate_3_746023_e, 0);

    struct timeval tv_r_JOIN_INNER_3_503964_s, tv_r_JOIN_INNER_3_503964_e;
    gettimeofday(&tv_r_JOIN_INNER_3_503964_s, 0);
    SW_JOIN_INNER_TD_3159277(tbl_JOIN_INNER_TD_4757004_output, tbl_Aggregate_TD_4174487_output, tbl_JOIN_INNER_TD_3159277_output);
    gettimeofday(&tv_r_JOIN_INNER_3_503964_e, 0);

    struct timeval tv_r_JOIN_INNER_2_460292_s, tv_r_JOIN_INNER_2_460292_e;
    gettimeofday(&tv_r_JOIN_INNER_2_460292_s, 0);
    SW_JOIN_INNER_TD_2833924(tbl_JOIN_INNER_TD_3159277_output, tbl_Aggregate_TD_3361928_output, tbl_JOIN_INNER_TD_2833924_output);
    gettimeofday(&tv_r_JOIN_INNER_2_460292_e, 0);

    struct timeval tv_r_Project_1_288957_s, tv_r_Project_1_288957_e;
    gettimeofday(&tv_r_Project_1_288957_s, 0);
    SW_Project_TD_1506350(tbl_JOIN_INNER_TD_2833924_output, tbl_Project_TD_1506350_output);
    gettimeofday(&tv_r_Project_1_288957_e, 0);

    struct timeval tv_r_Sort_0_582570_s, tv_r_Sort_0_582570_e;
    gettimeofday(&tv_r_Sort_0_582570_s, 0);
    SW_Sort_TD_0853836(tbl_Project_TD_1506350_output, tbl_Sort_TD_0853836_output);
    gettimeofday(&tv_r_Sort_0_582570_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_945826_s, &tv_r_Filter_10_945826_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11452411_input: " << tbl_SerializeFromObject_TD_11452411_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_244314_s, &tv_r_Filter_10_244314_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11334014_input: " << tbl_SerializeFromObject_TD_11334014_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_685344_s, &tv_r_Filter_10_685344_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11404989_input: " << tbl_SerializeFromObject_TD_11404989_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_1792_s, &tv_r_Filter_10_1792_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1126797_input: " << tbl_SerializeFromObject_TD_1126797_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_957699_s, &tv_r_Filter_9_957699_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10307863_input: " << tbl_SerializeFromObject_TD_10307863_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_499987_s, &tv_r_Filter_9_499987_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1089102_input: " << tbl_SerializeFromObject_TD_1089102_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_723731_s, &tv_r_Filter_9_723731_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10148362_input: " << tbl_SerializeFromObject_TD_10148362_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_560083_s, &tv_r_JOIN_INNER_9_560083_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10946768_output: " << tbl_Filter_TD_10946768_output.getNumRow() << " " << "tbl_Filter_TD_10959900_output: " << tbl_Filter_TD_10959900_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_936056_s, &tv_r_Filter_9_936056_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10128076_input: " << tbl_SerializeFromObject_TD_10128076_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_574782_s, &tv_r_JOIN_INNER_9_574782_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10907178_output: " << tbl_Filter_TD_10907178_output.getNumRow() << " " << "tbl_Filter_TD_10222848_output: " << tbl_Filter_TD_10222848_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_309513_s, &tv_r_Filter_8_309513_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9849394_input: " << tbl_SerializeFromObject_TD_9849394_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_597327_s, &tv_r_Filter_8_597327_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9345771_input: " << tbl_SerializeFromObject_TD_9345771_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_417077_s, &tv_r_Filter_8_417077_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9124573_input: " << tbl_SerializeFromObject_TD_9124573_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_245168_s, &tv_r_JOIN_INNER_8_245168_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9673388_output: " << tbl_Filter_TD_9673388_output.getNumRow() << " " << "tbl_Filter_TD_9611663_output: " << tbl_Filter_TD_9611663_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_687663_s, &tv_r_JOIN_INNER_8_687663_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9874636_output: " << tbl_JOIN_INNER_TD_9874636_output.getNumRow() << " " << "tbl_Filter_TD_9281970_output: " << tbl_Filter_TD_9281970_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_573273_s, &tv_r_JOIN_INNER_8_573273_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9888218_output: " << tbl_JOIN_INNER_TD_9888218_output.getNumRow() << " " << "tbl_Filter_TD_9913508_output: " << tbl_Filter_TD_9913508_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_724430_s, &tv_r_Filter_7_724430_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8558338_input: " << tbl_SerializeFromObject_TD_8558338_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_733173_s, &tv_r_Filter_7_733173_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8224831_input: " << tbl_SerializeFromObject_TD_8224831_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_324779_s, &tv_r_Filter_7_324779_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8113542_input: " << tbl_SerializeFromObject_TD_8113542_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_271217_s, &tv_r_JOIN_INNER_7_271217_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8645917_output: " << tbl_Filter_TD_8645917_output.getNumRow() << " " << "tbl_Filter_TD_8273211_output: " << tbl_Filter_TD_8273211_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_362896_s, &tv_r_JOIN_INNER_7_362896_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8666731_output: " << tbl_JOIN_INNER_TD_8666731_output.getNumRow() << " " << "tbl_Filter_TD_8760047_output: " << tbl_Filter_TD_8760047_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_7: " << tvdiff(&tv_r_Aggregate_7_290273_s, &tv_r_Aggregate_7_290273_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8914256_output: " << tbl_JOIN_INNER_TD_8914256_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_7: " << tvdiff(&tv_r_Aggregate_7_146760_s, &tv_r_Aggregate_7_146760_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8588441_output: " << tbl_JOIN_INNER_TD_8588441_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_359764_s, &tv_r_Filter_6_359764_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7421218_input: " << tbl_SerializeFromObject_TD_7421218_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_224762_s, &tv_r_Filter_6_224762_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7110449_input: " << tbl_SerializeFromObject_TD_7110449_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_507268_s, &tv_r_Filter_6_507268_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7451227_input: " << tbl_SerializeFromObject_TD_7451227_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_281916_s, &tv_r_JOIN_INNER_6_281916_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_7224122_output: " << tbl_Filter_TD_7224122_output.getNumRow() << " " << "tbl_Filter_TD_7752021_output: " << tbl_Filter_TD_7752021_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_661441_s, &tv_r_JOIN_INNER_6_661441_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7616985_output: " << tbl_JOIN_INNER_TD_7616985_output.getNumRow() << " " << "tbl_Filter_TD_7689133_output: " << tbl_Filter_TD_7689133_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_6: " << tvdiff(&tv_r_Aggregate_6_446683_s, &tv_r_Aggregate_6_446683_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7452580_output: " << tbl_JOIN_INNER_TD_7452580_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_217211_s, &tv_r_JOIN_INNER_6_217211_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_7393156_output: " << tbl_Aggregate_TD_7393156_output.getNumRow() << " " << "tbl_Aggregate_TD_7282392_output: " << tbl_Aggregate_TD_7282392_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_465426_s, &tv_r_Filter_5_465426_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6872052_input: " << tbl_SerializeFromObject_TD_6872052_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_176920_s, &tv_r_JOIN_INNER_5_176920_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6875471_output: " << tbl_Filter_TD_6875471_output.getNumRow() << " " << "tbl_Filter_TD_694516_output: " << tbl_Filter_TD_694516_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_812617_s, &tv_r_JOIN_INNER_5_812617_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6513082_output: " << tbl_JOIN_INNER_TD_6513082_output.getNumRow() << " " << "tbl_Filter_TD_6936522_output: " << tbl_Filter_TD_6936522_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_803299_s, &tv_r_Aggregate_5_803299_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6834355_output: " << tbl_JOIN_INNER_TD_6834355_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_349368_s, &tv_r_JOIN_INNER_5_349368_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6883781_output: " << tbl_JOIN_INNER_TD_6883781_output.getNumRow() << " " << "tbl_Aggregate_TD_6401051_output: " << tbl_Aggregate_TD_6401051_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_979741_s, &tv_r_JOIN_INNER_4_979741_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5648307_output: " << tbl_JOIN_INNER_TD_5648307_output.getNumRow() << " " << "tbl_Filter_TD_5427652_output: " << tbl_Filter_TD_5427652_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_4: " << tvdiff(&tv_r_Aggregate_4_719291_s, &tv_r_Aggregate_4_719291_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5780330_output: " << tbl_JOIN_INNER_TD_5780330_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_542313_s, &tv_r_JOIN_INNER_4_542313_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_56034_output: " << tbl_JOIN_INNER_TD_56034_output.getNumRow() << " " << "tbl_Aggregate_TD_5281409_output: " << tbl_Aggregate_TD_5281409_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_746023_s, &tv_r_Aggregate_3_746023_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_412391_output: " << tbl_JOIN_INNER_TD_412391_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_503964_s, &tv_r_JOIN_INNER_3_503964_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4757004_output: " << tbl_JOIN_INNER_TD_4757004_output.getNumRow() << " " << "tbl_Aggregate_TD_4174487_output: " << tbl_Aggregate_TD_4174487_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_2: " << tvdiff(&tv_r_JOIN_INNER_2_460292_s, &tv_r_JOIN_INNER_2_460292_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3159277_output: " << tbl_JOIN_INNER_TD_3159277_output.getNumRow() << " " << "tbl_Aggregate_TD_3361928_output: " << tbl_Aggregate_TD_3361928_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_1: " << tvdiff(&tv_r_Project_1_288957_s, &tv_r_Project_1_288957_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_2833924_output: " << tbl_JOIN_INNER_TD_2833924_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_582570_s, &tv_r_Sort_0_582570_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_1506350_output: " << tbl_Project_TD_1506350_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 3.519929 * 1000 << "ms" << std::endl; 
    return 0; 
}
