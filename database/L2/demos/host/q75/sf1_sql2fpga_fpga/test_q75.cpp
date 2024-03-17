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

#include "cfgFunc_q75.hpp" 
#include "q75.hpp" 

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
    std::cout << "NOTE:running query #75\n."; 
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
    cl::Device device_a = devices[1]; 
    // Create context_a and command queue for selected device 
    cl::Context context_a(device_a); 
    cl::CommandQueue q_a(context_a, device_a, CL_QUEUE_PROFILING_ENABLE | CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE); 
    std::string devName_a = device_a.getInfo<CL_DEVICE_NAME>(); 
    std::cout << "Selected Device " << devName_a << "\n"; 
    cl::Program::Binaries xclBins_a = xcl::import_binary_file(xclbin_path_a); 
    std::vector<cl::Device> devices_a; 
    devices_a.push_back(device_a); 
    cl::Program program_a(context_a, devices_a, xclBins_a); 
    // ****************************** Tables **************************** // 
    Table tbl_GlobalLimit_TD_0663158_output("tbl_GlobalLimit_TD_0663158_output", 6100000, 10, "");
    tbl_GlobalLimit_TD_0663158_output.allocateHost();
    Table tbl_LocalLimit_TD_1422359_output("tbl_LocalLimit_TD_1422359_output", 6100000, 10, "");
    tbl_LocalLimit_TD_1422359_output.allocateHost();
    Table tbl_Sort_TD_2198469_output("tbl_Sort_TD_2198469_output", 6100000, 10, "");
    tbl_Sort_TD_2198469_output.allocateHost();
    Table tbl_Project_TD_3602289_output("tbl_Project_TD_3602289_output", 6100000, 10, "");
    tbl_Project_TD_3602289_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4241816_output("tbl_JOIN_INNER_TD_4241816_output", 6100000, 10, "");
    tbl_JOIN_INNER_TD_4241816_output.allocateHost();
    Table tbl_Aggregate_TD_5950654_output_preprocess("tbl_Aggregate_TD_5950654_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_5950654_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_5950654_output("tbl_Aggregate_TD_5950654_output", 6100000, 7, "");
    tbl_Aggregate_TD_5950654_output.allocateHost();
    Table tbl_Aggregate_TD_5612354_output_preprocess("tbl_Aggregate_TD_5612354_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_5612354_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_5612354_output("tbl_Aggregate_TD_5612354_output", 6100000, 7, "");
    tbl_Aggregate_TD_5612354_output.allocateHost();
    Table tbl_Aggregate_TD_6604092_output_preprocess("tbl_Aggregate_TD_6604092_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_6604092_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_6604092_output("tbl_Aggregate_TD_6604092_output", 6100000, 7, "");
    tbl_Aggregate_TD_6604092_output.allocateHost();
    Table tbl_Aggregate_TD_641603_output_preprocess("tbl_Aggregate_TD_641603_output_preprocess", 6100000, 16, "");
    tbl_Aggregate_TD_641603_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_641603_output("tbl_Aggregate_TD_641603_output", 6100000, 7, "");
    tbl_Aggregate_TD_641603_output.allocateHost();
    Table tbl_Union_TD_7483707_output("tbl_Union_TD_7483707_output", 6100000, 7, "");
    tbl_Union_TD_7483707_output.allocateHost();
    Table tbl_Union_TD_72857_output("tbl_Union_TD_72857_output", 6100000, 7, "");
    tbl_Union_TD_72857_output.allocateHost();
    Table tbl_Project_TD_8151633_output("tbl_Project_TD_8151633_output", 6100000, 7, "");
    tbl_Project_TD_8151633_output.allocateHost();
    Table tbl_Project_TD_8509641_output("tbl_Project_TD_8509641_output", 6100000, 7, "");
    tbl_Project_TD_8509641_output.allocateHost();
    Table tbl_Project_TD_8125147_output("tbl_Project_TD_8125147_output", 6100000, 7, "");
    tbl_Project_TD_8125147_output.allocateHost();
    Table tbl_Project_TD_8211225_output("tbl_Project_TD_8211225_output", 6100000, 7, "");
    tbl_Project_TD_8211225_output.allocateHost();
    Table tbl_Project_TD_8980056_output("tbl_Project_TD_8980056_output", 6100000, 7, "");
    tbl_Project_TD_8980056_output.allocateHost();
    Table tbl_Project_TD_8914491_output("tbl_Project_TD_8914491_output", 6100000, 7, "");
    tbl_Project_TD_8914491_output.allocateHost();
    Table tbl_JOIN_LEFTOUTER_TD_9685430_output("tbl_JOIN_LEFTOUTER_TD_9685430_output", 6100000, 9, "");
    tbl_JOIN_LEFTOUTER_TD_9685430_output.allocateHost();
    Table tbl_JOIN_LEFTOUTER_TD_9954081_output("tbl_JOIN_LEFTOUTER_TD_9954081_output", 6100000, 9, "");
    tbl_JOIN_LEFTOUTER_TD_9954081_output.allocateHost();
    Table tbl_JOIN_LEFTOUTER_TD_9408405_output("tbl_JOIN_LEFTOUTER_TD_9408405_output", 6100000, 9, "");
    tbl_JOIN_LEFTOUTER_TD_9408405_output.allocateHost();
    Table tbl_JOIN_LEFTOUTER_TD_9932501_output("tbl_JOIN_LEFTOUTER_TD_9932501_output", 6100000, 9, "");
    tbl_JOIN_LEFTOUTER_TD_9932501_output.allocateHost();
    Table tbl_JOIN_LEFTOUTER_TD_9732787_output("tbl_JOIN_LEFTOUTER_TD_9732787_output", 6100000, 9, "");
    tbl_JOIN_LEFTOUTER_TD_9732787_output.allocateHost();
    Table tbl_JOIN_LEFTOUTER_TD_9282254_output("tbl_JOIN_LEFTOUTER_TD_9282254_output", 6100000, 9, "");
    tbl_JOIN_LEFTOUTER_TD_9282254_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10170990_output("tbl_JOIN_INNER_TD_10170990_output", 6100000, 9, "");
    tbl_JOIN_INNER_TD_10170990_output.allocateHost();
    Table tbl_Filter_TD_10619629_output("tbl_Filter_TD_10619629_output", 6100000, 4, "");
    tbl_Filter_TD_10619629_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10968541_output("tbl_JOIN_INNER_TD_10968541_output", 6100000, 9, "");
    tbl_JOIN_INNER_TD_10968541_output.allocateHost();
    Table tbl_Filter_TD_10273351_output("tbl_Filter_TD_10273351_output", 6100000, 4, "");
    tbl_Filter_TD_10273351_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10636324_output("tbl_JOIN_INNER_TD_10636324_output", 6100000, 9, "");
    tbl_JOIN_INNER_TD_10636324_output.allocateHost();
    Table tbl_Filter_TD_10332983_output("tbl_Filter_TD_10332983_output", 6100000, 4, "");
    tbl_Filter_TD_10332983_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10795304_output("tbl_JOIN_INNER_TD_10795304_output", 6100000, 9, "");
    tbl_JOIN_INNER_TD_10795304_output.allocateHost();
    Table tbl_Filter_TD_1062905_output("tbl_Filter_TD_1062905_output", 6100000, 4, "");
    tbl_Filter_TD_1062905_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10931863_output("tbl_JOIN_INNER_TD_10931863_output", 6100000, 9, "");
    tbl_JOIN_INNER_TD_10931863_output.allocateHost();
    Table tbl_Filter_TD_1021027_output("tbl_Filter_TD_1021027_output", 6100000, 4, "");
    tbl_Filter_TD_1021027_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10158452_output("tbl_JOIN_INNER_TD_10158452_output", 6100000, 9, "");
    tbl_JOIN_INNER_TD_10158452_output.allocateHost();
    Table tbl_Filter_TD_10776215_output("tbl_Filter_TD_10776215_output", 6100000, 4, "");
    tbl_Filter_TD_10776215_output.allocateHost();
    Table tbl_JOIN_INNER_TD_11627645_output("tbl_JOIN_INNER_TD_11627645_output", 6100000, 9, "");
    tbl_JOIN_INNER_TD_11627645_output.allocateHost();
    Table tbl_Filter_TD_11781310_output("tbl_Filter_TD_11781310_output", 6100000, 2, "");
    tbl_Filter_TD_11781310_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11308853_input;
    tbl_SerializeFromObject_TD_11308853_input = Table("catalog_returns", catalog_returns_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_11308853_input.addCol("cr_item_sk", 4);
    tbl_SerializeFromObject_TD_11308853_input.addCol("cr_order_number", 8);
    tbl_SerializeFromObject_TD_11308853_input.addCol("cr_return_quantity", 4);
    tbl_SerializeFromObject_TD_11308853_input.addCol("cr_return_amount", 4);
    tbl_SerializeFromObject_TD_11308853_input.allocateHost();
    tbl_SerializeFromObject_TD_11308853_input.loadHost();
    Table tbl_JOIN_INNER_TD_11868273_output("tbl_JOIN_INNER_TD_11868273_output", 6100000, 9, "");
    tbl_JOIN_INNER_TD_11868273_output.allocateHost();
    Table tbl_Filter_TD_11126261_output("tbl_Filter_TD_11126261_output", 6100000, 2, "");
    tbl_Filter_TD_11126261_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11832329_input;
    tbl_SerializeFromObject_TD_11832329_input = Table("store_returns", store_returns_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_11832329_input.addCol("sr_item_sk", 4);
    tbl_SerializeFromObject_TD_11832329_input.addCol("sr_ticket_number", 8);
    tbl_SerializeFromObject_TD_11832329_input.addCol("sr_return_quantity", 4);
    tbl_SerializeFromObject_TD_11832329_input.addCol("sr_return_amt", 4);
    tbl_SerializeFromObject_TD_11832329_input.allocateHost();
    tbl_SerializeFromObject_TD_11832329_input.loadHost();
    Table tbl_JOIN_INNER_TD_11650737_output("tbl_JOIN_INNER_TD_11650737_output", 6100000, 9, "");
    tbl_JOIN_INNER_TD_11650737_output.allocateHost();
    Table tbl_Filter_TD_11291823_output("tbl_Filter_TD_11291823_output", 6100000, 2, "");
    tbl_Filter_TD_11291823_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11105343_input;
    tbl_SerializeFromObject_TD_11105343_input = Table("web_returns", web_returns_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_11105343_input.addCol("wr_item_sk", 4);
    tbl_SerializeFromObject_TD_11105343_input.addCol("wr_order_number", 8);
    tbl_SerializeFromObject_TD_11105343_input.addCol("wr_return_quantity", 4);
    tbl_SerializeFromObject_TD_11105343_input.addCol("wr_return_amt", 4);
    tbl_SerializeFromObject_TD_11105343_input.allocateHost();
    tbl_SerializeFromObject_TD_11105343_input.loadHost();
    Table tbl_JOIN_INNER_TD_11469408_output("tbl_JOIN_INNER_TD_11469408_output", 6100000, 9, "");
    tbl_JOIN_INNER_TD_11469408_output.allocateHost();
    Table tbl_Filter_TD_11546642_output("tbl_Filter_TD_11546642_output", 6100000, 2, "");
    tbl_Filter_TD_11546642_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11428191_input;
    tbl_SerializeFromObject_TD_11428191_input = Table("catalog_returns", catalog_returns_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_11428191_input.addCol("cr_item_sk", 4);
    tbl_SerializeFromObject_TD_11428191_input.addCol("cr_order_number", 8);
    tbl_SerializeFromObject_TD_11428191_input.addCol("cr_return_quantity", 4);
    tbl_SerializeFromObject_TD_11428191_input.addCol("cr_return_amount", 4);
    tbl_SerializeFromObject_TD_11428191_input.allocateHost();
    tbl_SerializeFromObject_TD_11428191_input.loadHost();
    Table tbl_JOIN_INNER_TD_11321498_output("tbl_JOIN_INNER_TD_11321498_output", 6100000, 9, "");
    tbl_JOIN_INNER_TD_11321498_output.allocateHost();
    Table tbl_Filter_TD_11485295_output("tbl_Filter_TD_11485295_output", 6100000, 2, "");
    tbl_Filter_TD_11485295_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11213585_input;
    tbl_SerializeFromObject_TD_11213585_input = Table("store_returns", store_returns_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_11213585_input.addCol("sr_item_sk", 4);
    tbl_SerializeFromObject_TD_11213585_input.addCol("sr_ticket_number", 8);
    tbl_SerializeFromObject_TD_11213585_input.addCol("sr_return_quantity", 4);
    tbl_SerializeFromObject_TD_11213585_input.addCol("sr_return_amt", 4);
    tbl_SerializeFromObject_TD_11213585_input.allocateHost();
    tbl_SerializeFromObject_TD_11213585_input.loadHost();
    Table tbl_JOIN_INNER_TD_11243517_output("tbl_JOIN_INNER_TD_11243517_output", 6100000, 9, "");
    tbl_JOIN_INNER_TD_11243517_output.allocateHost();
    Table tbl_Filter_TD_11196108_output("tbl_Filter_TD_11196108_output", 6100000, 2, "");
    tbl_Filter_TD_11196108_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11542495_input;
    tbl_SerializeFromObject_TD_11542495_input = Table("web_returns", web_returns_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_11542495_input.addCol("wr_item_sk", 4);
    tbl_SerializeFromObject_TD_11542495_input.addCol("wr_order_number", 8);
    tbl_SerializeFromObject_TD_11542495_input.addCol("wr_return_quantity", 4);
    tbl_SerializeFromObject_TD_11542495_input.addCol("wr_return_amt", 4);
    tbl_SerializeFromObject_TD_11542495_input.allocateHost();
    tbl_SerializeFromObject_TD_11542495_input.loadHost();
    Table tbl_Filter_TD_1278768_output("tbl_Filter_TD_1278768_output", 6100000, 5, "");
    tbl_Filter_TD_1278768_output.allocateHost();
    Table tbl_Filter_TD_12265825_output("tbl_Filter_TD_12265825_output", 6100000, 5, "");
    tbl_Filter_TD_12265825_output.allocateHost();
    Table tbl_SerializeFromObject_TD_12955447_input;
    tbl_SerializeFromObject_TD_12955447_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12955447_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_12955447_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_12955447_input.allocateHost();
    tbl_SerializeFromObject_TD_12955447_input.loadHost();
    Table tbl_Filter_TD_12304293_output("tbl_Filter_TD_12304293_output", 6100000, 5, "");
    tbl_Filter_TD_12304293_output.allocateHost();
    Table tbl_Filter_TD_12968861_output("tbl_Filter_TD_12968861_output", 6100000, 5, "");
    tbl_Filter_TD_12968861_output.allocateHost();
    Table tbl_SerializeFromObject_TD_12757823_input;
    tbl_SerializeFromObject_TD_12757823_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12757823_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_12757823_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_12757823_input.allocateHost();
    tbl_SerializeFromObject_TD_12757823_input.loadHost();
    Table tbl_Filter_TD_12460154_output("tbl_Filter_TD_12460154_output", 6100000, 5, "");
    tbl_Filter_TD_12460154_output.allocateHost();
    Table tbl_Filter_TD_12301909_output("tbl_Filter_TD_12301909_output", 6100000, 5, "");
    tbl_Filter_TD_12301909_output.allocateHost();
    Table tbl_SerializeFromObject_TD_12818793_input;
    tbl_SerializeFromObject_TD_12818793_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12818793_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_12818793_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_12818793_input.allocateHost();
    tbl_SerializeFromObject_TD_12818793_input.loadHost();
    Table tbl_Filter_TD_12968394_output("tbl_Filter_TD_12968394_output", 6100000, 5, "");
    tbl_Filter_TD_12968394_output.allocateHost();
    Table tbl_Filter_TD_1270854_output("tbl_Filter_TD_1270854_output", 6100000, 5, "");
    tbl_Filter_TD_1270854_output.allocateHost();
    Table tbl_SerializeFromObject_TD_12876421_input;
    tbl_SerializeFromObject_TD_12876421_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12876421_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_12876421_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_12876421_input.allocateHost();
    tbl_SerializeFromObject_TD_12876421_input.loadHost();
    Table tbl_Filter_TD_12349655_output("tbl_Filter_TD_12349655_output", 6100000, 5, "");
    tbl_Filter_TD_12349655_output.allocateHost();
    Table tbl_Filter_TD_12246209_output("tbl_Filter_TD_12246209_output", 6100000, 5, "");
    tbl_Filter_TD_12246209_output.allocateHost();
    Table tbl_SerializeFromObject_TD_12935935_input;
    tbl_SerializeFromObject_TD_12935935_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12935935_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_12935935_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_12935935_input.allocateHost();
    tbl_SerializeFromObject_TD_12935935_input.loadHost();
    Table tbl_Filter_TD_12741275_output("tbl_Filter_TD_12741275_output", 6100000, 5, "");
    tbl_Filter_TD_12741275_output.allocateHost();
    Table tbl_Filter_TD_12881251_output("tbl_Filter_TD_12881251_output", 6100000, 5, "");
    tbl_Filter_TD_12881251_output.allocateHost();
    Table tbl_SerializeFromObject_TD_12141446_input;
    tbl_SerializeFromObject_TD_12141446_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12141446_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_12141446_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_12141446_input.allocateHost();
    tbl_SerializeFromObject_TD_12141446_input.loadHost();
    Table tbl_SerializeFromObject_TD_13951278_input;
    tbl_SerializeFromObject_TD_13951278_input = Table("catalog_sales", catalog_sales_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_13951278_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_13951278_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_13951278_input.addCol("cs_order_number", 8);
    tbl_SerializeFromObject_TD_13951278_input.addCol("cs_quantity", 4);
    tbl_SerializeFromObject_TD_13951278_input.addCol("cs_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_13951278_input.allocateHost();
    tbl_SerializeFromObject_TD_13951278_input.loadHost();
    Table tbl_SerializeFromObject_TD_13648438_input;
    tbl_SerializeFromObject_TD_13648438_input = Table("item", item_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_13648438_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_13648438_input.addCol("i_brand_id", 4);
    tbl_SerializeFromObject_TD_13648438_input.addCol("i_class_id", 4);
    tbl_SerializeFromObject_TD_13648438_input.addCol("i_category_id", 4);
    tbl_SerializeFromObject_TD_13648438_input.addCol("i_manufact_id", 4);
    tbl_SerializeFromObject_TD_13648438_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13648438_input.allocateHost();
    tbl_SerializeFromObject_TD_13648438_input.loadHost();
    Table tbl_SerializeFromObject_TD_13666961_input;
    tbl_SerializeFromObject_TD_13666961_input = Table("store_sales", store_sales_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_13666961_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_13666961_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_13666961_input.addCol("ss_ticket_number", 8);
    tbl_SerializeFromObject_TD_13666961_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_13666961_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_13666961_input.allocateHost();
    tbl_SerializeFromObject_TD_13666961_input.loadHost();
    Table tbl_SerializeFromObject_TD_13698675_input;
    tbl_SerializeFromObject_TD_13698675_input = Table("item", item_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_13698675_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_13698675_input.addCol("i_brand_id", 4);
    tbl_SerializeFromObject_TD_13698675_input.addCol("i_class_id", 4);
    tbl_SerializeFromObject_TD_13698675_input.addCol("i_category_id", 4);
    tbl_SerializeFromObject_TD_13698675_input.addCol("i_manufact_id", 4);
    tbl_SerializeFromObject_TD_13698675_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13698675_input.allocateHost();
    tbl_SerializeFromObject_TD_13698675_input.loadHost();
    Table tbl_SerializeFromObject_TD_13634156_input;
    tbl_SerializeFromObject_TD_13634156_input = Table("web_sales", web_sales_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_13634156_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_13634156_input.addCol("ws_item_sk", 4);
    tbl_SerializeFromObject_TD_13634156_input.addCol("ws_order_number", 8);
    tbl_SerializeFromObject_TD_13634156_input.addCol("ws_quantity", 4);
    tbl_SerializeFromObject_TD_13634156_input.addCol("ws_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_13634156_input.allocateHost();
    tbl_SerializeFromObject_TD_13634156_input.loadHost();
    Table tbl_SerializeFromObject_TD_13679127_input;
    tbl_SerializeFromObject_TD_13679127_input = Table("item", item_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_13679127_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_13679127_input.addCol("i_brand_id", 4);
    tbl_SerializeFromObject_TD_13679127_input.addCol("i_class_id", 4);
    tbl_SerializeFromObject_TD_13679127_input.addCol("i_category_id", 4);
    tbl_SerializeFromObject_TD_13679127_input.addCol("i_manufact_id", 4);
    tbl_SerializeFromObject_TD_13679127_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13679127_input.allocateHost();
    tbl_SerializeFromObject_TD_13679127_input.loadHost();
    Table tbl_SerializeFromObject_TD_13386576_input;
    tbl_SerializeFromObject_TD_13386576_input = Table("catalog_sales", catalog_sales_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_13386576_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_13386576_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_13386576_input.addCol("cs_order_number", 8);
    tbl_SerializeFromObject_TD_13386576_input.addCol("cs_quantity", 4);
    tbl_SerializeFromObject_TD_13386576_input.addCol("cs_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_13386576_input.allocateHost();
    tbl_SerializeFromObject_TD_13386576_input.loadHost();
    Table tbl_SerializeFromObject_TD_13916556_input;
    tbl_SerializeFromObject_TD_13916556_input = Table("item", item_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_13916556_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_13916556_input.addCol("i_brand_id", 4);
    tbl_SerializeFromObject_TD_13916556_input.addCol("i_class_id", 4);
    tbl_SerializeFromObject_TD_13916556_input.addCol("i_category_id", 4);
    tbl_SerializeFromObject_TD_13916556_input.addCol("i_manufact_id", 4);
    tbl_SerializeFromObject_TD_13916556_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13916556_input.allocateHost();
    tbl_SerializeFromObject_TD_13916556_input.loadHost();
    Table tbl_SerializeFromObject_TD_13788587_input;
    tbl_SerializeFromObject_TD_13788587_input = Table("store_sales", store_sales_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_13788587_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_13788587_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_13788587_input.addCol("ss_ticket_number", 8);
    tbl_SerializeFromObject_TD_13788587_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_13788587_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_13788587_input.allocateHost();
    tbl_SerializeFromObject_TD_13788587_input.loadHost();
    Table tbl_SerializeFromObject_TD_13207901_input;
    tbl_SerializeFromObject_TD_13207901_input = Table("item", item_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_13207901_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_13207901_input.addCol("i_brand_id", 4);
    tbl_SerializeFromObject_TD_13207901_input.addCol("i_class_id", 4);
    tbl_SerializeFromObject_TD_13207901_input.addCol("i_category_id", 4);
    tbl_SerializeFromObject_TD_13207901_input.addCol("i_manufact_id", 4);
    tbl_SerializeFromObject_TD_13207901_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13207901_input.allocateHost();
    tbl_SerializeFromObject_TD_13207901_input.loadHost();
    Table tbl_SerializeFromObject_TD_13650294_input;
    tbl_SerializeFromObject_TD_13650294_input = Table("web_sales", web_sales_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_13650294_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_13650294_input.addCol("ws_item_sk", 4);
    tbl_SerializeFromObject_TD_13650294_input.addCol("ws_order_number", 8);
    tbl_SerializeFromObject_TD_13650294_input.addCol("ws_quantity", 4);
    tbl_SerializeFromObject_TD_13650294_input.addCol("ws_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_13650294_input.allocateHost();
    tbl_SerializeFromObject_TD_13650294_input.loadHost();
    Table tbl_SerializeFromObject_TD_13186167_input;
    tbl_SerializeFromObject_TD_13186167_input = Table("item", item_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_13186167_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_13186167_input.addCol("i_brand_id", 4);
    tbl_SerializeFromObject_TD_13186167_input.addCol("i_class_id", 4);
    tbl_SerializeFromObject_TD_13186167_input.addCol("i_category_id", 4);
    tbl_SerializeFromObject_TD_13186167_input.addCol("i_manufact_id", 4);
    tbl_SerializeFromObject_TD_13186167_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_13186167_input.allocateHost();
    tbl_SerializeFromObject_TD_13186167_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_Aggregate_TD_5950654_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_Aggregate_TD_5612354_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_Aggregate_TD_6604092_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_Aggregate_TD_6604092_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_641603_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_Aggregate_TD_641603_output.allocateDevBuffer(context_a, 32);
    tbl_Union_TD_7483707_output.allocateDevBuffer(context_a, 32);
    tbl_Union_TD_72857_output.allocateDevBuffer(context_a, 32);
    // ****************************** Config **************************** // 
    AggrCfgCmd cfg_Aggregate_TD_5950654_cmds;
    cfg_Aggregate_TD_5950654_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_5950654_gqe_aggr(cfg_Aggregate_TD_5950654_cmds.cmd);
    cfg_Aggregate_TD_5950654_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_5950654_cmds_out;
    cfg_Aggregate_TD_5950654_cmds_out.allocateHost();
    cfg_Aggregate_TD_5950654_cmds_out.allocateDevBuffer(context_a, 33);
    AggrCfgCmd cfg_Aggregate_TD_5612354_cmds;
    cfg_Aggregate_TD_5612354_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_5612354_gqe_aggr(cfg_Aggregate_TD_5612354_cmds.cmd);
    cfg_Aggregate_TD_5612354_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_5612354_cmds_out;
    cfg_Aggregate_TD_5612354_cmds_out.allocateHost();
    cfg_Aggregate_TD_5612354_cmds_out.allocateDevBuffer(context_a, 33);
    AggrCfgCmd cfg_Aggregate_TD_6604092_cmds;
    cfg_Aggregate_TD_6604092_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_6604092_gqe_aggr(cfg_Aggregate_TD_6604092_cmds.cmd);
    cfg_Aggregate_TD_6604092_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_6604092_cmds_out;
    cfg_Aggregate_TD_6604092_cmds_out.allocateHost();
    cfg_Aggregate_TD_6604092_cmds_out.allocateDevBuffer(context_a, 33);
    AggrCfgCmd cfg_Aggregate_TD_641603_cmds;
    cfg_Aggregate_TD_641603_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_641603_gqe_aggr(cfg_Aggregate_TD_641603_cmds.cmd);
    cfg_Aggregate_TD_641603_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_641603_cmds_out;
    cfg_Aggregate_TD_641603_cmds_out.allocateHost();
    cfg_Aggregate_TD_641603_cmds_out.allocateDevBuffer(context_a, 33);
    // *************************** Kernel Setup ************************* // 
    AggrBufferTmp buftmp_a(context_a); 
    buftmp_a.BufferInitial(q_a); 
    std::cout << std::endl; 
    AggrKrnlEngine krnl_Aggregate_TD_5950654;
    krnl_Aggregate_TD_5950654 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_5950654.setup(tbl_Aggregate_TD_6604092_output, tbl_Aggregate_TD_5950654_output_preprocess, cfg_Aggregate_TD_5950654_cmds, cfg_Aggregate_TD_5950654_cmds_out, buftmp_a);
    AggrKrnlEngine krnl_Aggregate_TD_5612354;
    krnl_Aggregate_TD_5612354 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_5612354.setup(tbl_Aggregate_TD_641603_output, tbl_Aggregate_TD_5612354_output_preprocess, cfg_Aggregate_TD_5612354_cmds, cfg_Aggregate_TD_5612354_cmds_out, buftmp_a);
    AggrKrnlEngine krnl_Aggregate_TD_6604092;
    krnl_Aggregate_TD_6604092 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_6604092.setup(tbl_Union_TD_7483707_output, tbl_Aggregate_TD_6604092_output_preprocess, cfg_Aggregate_TD_6604092_cmds, cfg_Aggregate_TD_6604092_cmds_out, buftmp_a);
    AggrKrnlEngine krnl_Aggregate_TD_641603;
    krnl_Aggregate_TD_641603 = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    krnl_Aggregate_TD_641603.setup(tbl_Union_TD_72857_output, tbl_Aggregate_TD_641603_output_preprocess, cfg_Aggregate_TD_641603_cmds, cfg_Aggregate_TD_641603_cmds_out, buftmp_a);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_Aggregate_TD_5950654;
    trans_Aggregate_TD_5950654.setq(q_a);
    trans_Aggregate_TD_5950654.add(&(cfg_Aggregate_TD_5950654_cmds));
    transEngine trans_Aggregate_TD_5950654_out;
    trans_Aggregate_TD_5950654_out.setq(q_a);
    q_a.finish();
    transEngine trans_Aggregate_TD_5612354;
    trans_Aggregate_TD_5612354.setq(q_a);
    trans_Aggregate_TD_5612354.add(&(cfg_Aggregate_TD_5612354_cmds));
    transEngine trans_Aggregate_TD_5612354_out;
    trans_Aggregate_TD_5612354_out.setq(q_a);
    q_a.finish();
    transEngine trans_Aggregate_TD_6604092;
    trans_Aggregate_TD_6604092.setq(q_a);
    trans_Aggregate_TD_6604092.add(&(cfg_Aggregate_TD_6604092_cmds));
    transEngine trans_Aggregate_TD_6604092_out;
    trans_Aggregate_TD_6604092_out.setq(q_a);
    q_a.finish();
    transEngine trans_Aggregate_TD_641603;
    trans_Aggregate_TD_641603.setq(q_a);
    trans_Aggregate_TD_641603.add(&(cfg_Aggregate_TD_641603_cmds));
    transEngine trans_Aggregate_TD_641603_out;
    trans_Aggregate_TD_641603_out.setq(q_a);
    q_a.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_5950654;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_5950654;
    std::vector<cl::Event> events_Aggregate_TD_5950654;
    events_h2d_wr_Aggregate_TD_5950654.resize(1);
    events_d2h_rd_Aggregate_TD_5950654.resize(1);
    events_Aggregate_TD_5950654.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_5950654;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_5950654;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_5612354;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_5612354;
    std::vector<cl::Event> events_Aggregate_TD_5612354;
    events_h2d_wr_Aggregate_TD_5612354.resize(1);
    events_d2h_rd_Aggregate_TD_5612354.resize(1);
    events_Aggregate_TD_5612354.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_5612354;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_5612354;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_6604092;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_6604092;
    std::vector<cl::Event> events_Aggregate_TD_6604092;
    events_h2d_wr_Aggregate_TD_6604092.resize(1);
    events_d2h_rd_Aggregate_TD_6604092.resize(1);
    events_Aggregate_TD_6604092.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_6604092;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_6604092;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_641603;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_641603;
    std::vector<cl::Event> events_Aggregate_TD_641603;
    events_h2d_wr_Aggregate_TD_641603.resize(1);
    events_d2h_rd_Aggregate_TD_641603.resize(1);
    events_Aggregate_TD_641603.resize(1);
    std::vector<cl::Event> events_grp_Aggregate_TD_641603;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_641603;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_12_419043_s, tv_r_Filter_12_419043_e;
    gettimeofday(&tv_r_Filter_12_419043_s, 0);
    SW_Filter_TD_12881251(tbl_SerializeFromObject_TD_13186167_input, tbl_Filter_TD_12881251_output);
    gettimeofday(&tv_r_Filter_12_419043_e, 0);

    struct timeval tv_r_Filter_12_94988_s, tv_r_Filter_12_94988_e;
    gettimeofday(&tv_r_Filter_12_94988_s, 0);
    SW_Filter_TD_12741275(tbl_SerializeFromObject_TD_13650294_input, tbl_Filter_TD_12741275_output);
    gettimeofday(&tv_r_Filter_12_94988_e, 0);

    struct timeval tv_r_Filter_12_747855_s, tv_r_Filter_12_747855_e;
    gettimeofday(&tv_r_Filter_12_747855_s, 0);
    SW_Filter_TD_12246209(tbl_SerializeFromObject_TD_13207901_input, tbl_Filter_TD_12246209_output);
    gettimeofday(&tv_r_Filter_12_747855_e, 0);

    struct timeval tv_r_Filter_12_377409_s, tv_r_Filter_12_377409_e;
    gettimeofday(&tv_r_Filter_12_377409_s, 0);
    SW_Filter_TD_12349655(tbl_SerializeFromObject_TD_13788587_input, tbl_Filter_TD_12349655_output);
    gettimeofday(&tv_r_Filter_12_377409_e, 0);

    struct timeval tv_r_Filter_12_463481_s, tv_r_Filter_12_463481_e;
    gettimeofday(&tv_r_Filter_12_463481_s, 0);
    SW_Filter_TD_1270854(tbl_SerializeFromObject_TD_13916556_input, tbl_Filter_TD_1270854_output);
    gettimeofday(&tv_r_Filter_12_463481_e, 0);

    struct timeval tv_r_Filter_12_440899_s, tv_r_Filter_12_440899_e;
    gettimeofday(&tv_r_Filter_12_440899_s, 0);
    SW_Filter_TD_12968394(tbl_SerializeFromObject_TD_13386576_input, tbl_Filter_TD_12968394_output);
    gettimeofday(&tv_r_Filter_12_440899_e, 0);

    struct timeval tv_r_Filter_12_626871_s, tv_r_Filter_12_626871_e;
    gettimeofday(&tv_r_Filter_12_626871_s, 0);
    SW_Filter_TD_12301909(tbl_SerializeFromObject_TD_13679127_input, tbl_Filter_TD_12301909_output);
    gettimeofday(&tv_r_Filter_12_626871_e, 0);

    struct timeval tv_r_Filter_12_150533_s, tv_r_Filter_12_150533_e;
    gettimeofday(&tv_r_Filter_12_150533_s, 0);
    SW_Filter_TD_12460154(tbl_SerializeFromObject_TD_13634156_input, tbl_Filter_TD_12460154_output);
    gettimeofday(&tv_r_Filter_12_150533_e, 0);

    struct timeval tv_r_Filter_12_721929_s, tv_r_Filter_12_721929_e;
    gettimeofday(&tv_r_Filter_12_721929_s, 0);
    SW_Filter_TD_12968861(tbl_SerializeFromObject_TD_13698675_input, tbl_Filter_TD_12968861_output);
    gettimeofday(&tv_r_Filter_12_721929_e, 0);

    struct timeval tv_r_Filter_12_92346_s, tv_r_Filter_12_92346_e;
    gettimeofday(&tv_r_Filter_12_92346_s, 0);
    SW_Filter_TD_12304293(tbl_SerializeFromObject_TD_13666961_input, tbl_Filter_TD_12304293_output);
    gettimeofday(&tv_r_Filter_12_92346_e, 0);

    struct timeval tv_r_Filter_12_559442_s, tv_r_Filter_12_559442_e;
    gettimeofday(&tv_r_Filter_12_559442_s, 0);
    SW_Filter_TD_12265825(tbl_SerializeFromObject_TD_13648438_input, tbl_Filter_TD_12265825_output);
    gettimeofday(&tv_r_Filter_12_559442_e, 0);

    struct timeval tv_r_Filter_12_262116_s, tv_r_Filter_12_262116_e;
    gettimeofday(&tv_r_Filter_12_262116_s, 0);
    SW_Filter_TD_1278768(tbl_SerializeFromObject_TD_13951278_input, tbl_Filter_TD_1278768_output);
    gettimeofday(&tv_r_Filter_12_262116_e, 0);

    struct timeval tv_r_Filter_11_819768_s, tv_r_Filter_11_819768_e;
    gettimeofday(&tv_r_Filter_11_819768_s, 0);
    SW_Filter_TD_11196108(tbl_SerializeFromObject_TD_12141446_input, tbl_Filter_TD_11196108_output);
    gettimeofday(&tv_r_Filter_11_819768_e, 0);

    struct timeval tv_r_JOIN_INNER_11_856694_s, tv_r_JOIN_INNER_11_856694_e;
    gettimeofday(&tv_r_JOIN_INNER_11_856694_s, 0);
    SW_JOIN_INNER_TD_11243517(tbl_Filter_TD_12741275_output, tbl_Filter_TD_12881251_output, tbl_JOIN_INNER_TD_11243517_output);
    gettimeofday(&tv_r_JOIN_INNER_11_856694_e, 0);

    struct timeval tv_r_Filter_11_831828_s, tv_r_Filter_11_831828_e;
    gettimeofday(&tv_r_Filter_11_831828_s, 0);
    SW_Filter_TD_11485295(tbl_SerializeFromObject_TD_12935935_input, tbl_Filter_TD_11485295_output);
    gettimeofday(&tv_r_Filter_11_831828_e, 0);

    struct timeval tv_r_JOIN_INNER_11_330484_s, tv_r_JOIN_INNER_11_330484_e;
    gettimeofday(&tv_r_JOIN_INNER_11_330484_s, 0);
    SW_JOIN_INNER_TD_11321498(tbl_Filter_TD_12349655_output, tbl_Filter_TD_12246209_output, tbl_JOIN_INNER_TD_11321498_output);
    gettimeofday(&tv_r_JOIN_INNER_11_330484_e, 0);

    struct timeval tv_r_Filter_11_600268_s, tv_r_Filter_11_600268_e;
    gettimeofday(&tv_r_Filter_11_600268_s, 0);
    SW_Filter_TD_11546642(tbl_SerializeFromObject_TD_12876421_input, tbl_Filter_TD_11546642_output);
    gettimeofday(&tv_r_Filter_11_600268_e, 0);

    struct timeval tv_r_JOIN_INNER_11_521234_s, tv_r_JOIN_INNER_11_521234_e;
    gettimeofday(&tv_r_JOIN_INNER_11_521234_s, 0);
    SW_JOIN_INNER_TD_11469408(tbl_Filter_TD_12968394_output, tbl_Filter_TD_1270854_output, tbl_JOIN_INNER_TD_11469408_output);
    gettimeofday(&tv_r_JOIN_INNER_11_521234_e, 0);

    struct timeval tv_r_Filter_11_500810_s, tv_r_Filter_11_500810_e;
    gettimeofday(&tv_r_Filter_11_500810_s, 0);
    SW_Filter_TD_11291823(tbl_SerializeFromObject_TD_12818793_input, tbl_Filter_TD_11291823_output);
    gettimeofday(&tv_r_Filter_11_500810_e, 0);

    struct timeval tv_r_JOIN_INNER_11_786611_s, tv_r_JOIN_INNER_11_786611_e;
    gettimeofday(&tv_r_JOIN_INNER_11_786611_s, 0);
    SW_JOIN_INNER_TD_11650737(tbl_Filter_TD_12460154_output, tbl_Filter_TD_12301909_output, tbl_JOIN_INNER_TD_11650737_output);
    gettimeofday(&tv_r_JOIN_INNER_11_786611_e, 0);

    struct timeval tv_r_Filter_11_454880_s, tv_r_Filter_11_454880_e;
    gettimeofday(&tv_r_Filter_11_454880_s, 0);
    SW_Filter_TD_11126261(tbl_SerializeFromObject_TD_12757823_input, tbl_Filter_TD_11126261_output);
    gettimeofday(&tv_r_Filter_11_454880_e, 0);

    struct timeval tv_r_JOIN_INNER_11_227471_s, tv_r_JOIN_INNER_11_227471_e;
    gettimeofday(&tv_r_JOIN_INNER_11_227471_s, 0);
    SW_JOIN_INNER_TD_11868273(tbl_Filter_TD_12304293_output, tbl_Filter_TD_12968861_output, tbl_JOIN_INNER_TD_11868273_output);
    gettimeofday(&tv_r_JOIN_INNER_11_227471_e, 0);

    struct timeval tv_r_Filter_11_567191_s, tv_r_Filter_11_567191_e;
    gettimeofday(&tv_r_Filter_11_567191_s, 0);
    SW_Filter_TD_11781310(tbl_SerializeFromObject_TD_12955447_input, tbl_Filter_TD_11781310_output);
    gettimeofday(&tv_r_Filter_11_567191_e, 0);

    struct timeval tv_r_JOIN_INNER_11_677095_s, tv_r_JOIN_INNER_11_677095_e;
    gettimeofday(&tv_r_JOIN_INNER_11_677095_s, 0);
    SW_JOIN_INNER_TD_11627645(tbl_Filter_TD_1278768_output, tbl_Filter_TD_12265825_output, tbl_JOIN_INNER_TD_11627645_output);
    gettimeofday(&tv_r_JOIN_INNER_11_677095_e, 0);

    struct timeval tv_r_Filter_10_560_s, tv_r_Filter_10_560_e;
    gettimeofday(&tv_r_Filter_10_560_s, 0);
    SW_Filter_TD_10776215(tbl_SerializeFromObject_TD_11542495_input, tbl_Filter_TD_10776215_output);
    gettimeofday(&tv_r_Filter_10_560_e, 0);

    struct timeval tv_r_JOIN_INNER_10_902848_s, tv_r_JOIN_INNER_10_902848_e;
    gettimeofday(&tv_r_JOIN_INNER_10_902848_s, 0);
    SW_JOIN_INNER_TD_10158452(tbl_JOIN_INNER_TD_11243517_output, tbl_Filter_TD_11196108_output, tbl_JOIN_INNER_TD_10158452_output);
    gettimeofday(&tv_r_JOIN_INNER_10_902848_e, 0);

    struct timeval tv_r_Filter_10_654808_s, tv_r_Filter_10_654808_e;
    gettimeofday(&tv_r_Filter_10_654808_s, 0);
    SW_Filter_TD_1021027(tbl_SerializeFromObject_TD_11213585_input, tbl_Filter_TD_1021027_output);
    gettimeofday(&tv_r_Filter_10_654808_e, 0);

    struct timeval tv_r_JOIN_INNER_10_760918_s, tv_r_JOIN_INNER_10_760918_e;
    gettimeofday(&tv_r_JOIN_INNER_10_760918_s, 0);
    SW_JOIN_INNER_TD_10931863(tbl_JOIN_INNER_TD_11321498_output, tbl_Filter_TD_11485295_output, tbl_JOIN_INNER_TD_10931863_output);
    gettimeofday(&tv_r_JOIN_INNER_10_760918_e, 0);

    struct timeval tv_r_Filter_10_790164_s, tv_r_Filter_10_790164_e;
    gettimeofday(&tv_r_Filter_10_790164_s, 0);
    SW_Filter_TD_1062905(tbl_SerializeFromObject_TD_11428191_input, tbl_Filter_TD_1062905_output);
    gettimeofday(&tv_r_Filter_10_790164_e, 0);

    struct timeval tv_r_JOIN_INNER_10_768843_s, tv_r_JOIN_INNER_10_768843_e;
    gettimeofday(&tv_r_JOIN_INNER_10_768843_s, 0);
    SW_JOIN_INNER_TD_10795304(tbl_JOIN_INNER_TD_11469408_output, tbl_Filter_TD_11546642_output, tbl_JOIN_INNER_TD_10795304_output);
    gettimeofday(&tv_r_JOIN_INNER_10_768843_e, 0);

    struct timeval tv_r_Filter_10_535401_s, tv_r_Filter_10_535401_e;
    gettimeofday(&tv_r_Filter_10_535401_s, 0);
    SW_Filter_TD_10332983(tbl_SerializeFromObject_TD_11105343_input, tbl_Filter_TD_10332983_output);
    gettimeofday(&tv_r_Filter_10_535401_e, 0);

    struct timeval tv_r_JOIN_INNER_10_364831_s, tv_r_JOIN_INNER_10_364831_e;
    gettimeofday(&tv_r_JOIN_INNER_10_364831_s, 0);
    SW_JOIN_INNER_TD_10636324(tbl_JOIN_INNER_TD_11650737_output, tbl_Filter_TD_11291823_output, tbl_JOIN_INNER_TD_10636324_output);
    gettimeofday(&tv_r_JOIN_INNER_10_364831_e, 0);

    struct timeval tv_r_Filter_10_476170_s, tv_r_Filter_10_476170_e;
    gettimeofday(&tv_r_Filter_10_476170_s, 0);
    SW_Filter_TD_10273351(tbl_SerializeFromObject_TD_11832329_input, tbl_Filter_TD_10273351_output);
    gettimeofday(&tv_r_Filter_10_476170_e, 0);

    struct timeval tv_r_JOIN_INNER_10_489500_s, tv_r_JOIN_INNER_10_489500_e;
    gettimeofday(&tv_r_JOIN_INNER_10_489500_s, 0);
    SW_JOIN_INNER_TD_10968541(tbl_JOIN_INNER_TD_11868273_output, tbl_Filter_TD_11126261_output, tbl_JOIN_INNER_TD_10968541_output);
    gettimeofday(&tv_r_JOIN_INNER_10_489500_e, 0);

    struct timeval tv_r_Filter_10_372417_s, tv_r_Filter_10_372417_e;
    gettimeofday(&tv_r_Filter_10_372417_s, 0);
    SW_Filter_TD_10619629(tbl_SerializeFromObject_TD_11308853_input, tbl_Filter_TD_10619629_output);
    gettimeofday(&tv_r_Filter_10_372417_e, 0);

    struct timeval tv_r_JOIN_INNER_10_882740_s, tv_r_JOIN_INNER_10_882740_e;
    gettimeofday(&tv_r_JOIN_INNER_10_882740_s, 0);
    SW_JOIN_INNER_TD_10170990(tbl_JOIN_INNER_TD_11627645_output, tbl_Filter_TD_11781310_output, tbl_JOIN_INNER_TD_10170990_output);
    gettimeofday(&tv_r_JOIN_INNER_10_882740_e, 0);

    struct timeval tv_r_JOIN_LEFTOUTER_9_221292_s, tv_r_JOIN_LEFTOUTER_9_221292_e;
    gettimeofday(&tv_r_JOIN_LEFTOUTER_9_221292_s, 0);
    SW_JOIN_LEFTOUTER_TD_9282254(tbl_JOIN_INNER_TD_10158452_output, tbl_Filter_TD_10776215_output, tbl_JOIN_LEFTOUTER_TD_9282254_output);
    gettimeofday(&tv_r_JOIN_LEFTOUTER_9_221292_e, 0);

    struct timeval tv_r_JOIN_LEFTOUTER_9_623404_s, tv_r_JOIN_LEFTOUTER_9_623404_e;
    gettimeofday(&tv_r_JOIN_LEFTOUTER_9_623404_s, 0);
    SW_JOIN_LEFTOUTER_TD_9732787(tbl_JOIN_INNER_TD_10931863_output, tbl_Filter_TD_1021027_output, tbl_JOIN_LEFTOUTER_TD_9732787_output);
    gettimeofday(&tv_r_JOIN_LEFTOUTER_9_623404_e, 0);

    struct timeval tv_r_JOIN_LEFTOUTER_9_332984_s, tv_r_JOIN_LEFTOUTER_9_332984_e;
    gettimeofday(&tv_r_JOIN_LEFTOUTER_9_332984_s, 0);
    SW_JOIN_LEFTOUTER_TD_9932501(tbl_JOIN_INNER_TD_10795304_output, tbl_Filter_TD_1062905_output, tbl_JOIN_LEFTOUTER_TD_9932501_output);
    gettimeofday(&tv_r_JOIN_LEFTOUTER_9_332984_e, 0);

    struct timeval tv_r_JOIN_LEFTOUTER_9_811445_s, tv_r_JOIN_LEFTOUTER_9_811445_e;
    gettimeofday(&tv_r_JOIN_LEFTOUTER_9_811445_s, 0);
    SW_JOIN_LEFTOUTER_TD_9408405(tbl_JOIN_INNER_TD_10636324_output, tbl_Filter_TD_10332983_output, tbl_JOIN_LEFTOUTER_TD_9408405_output);
    gettimeofday(&tv_r_JOIN_LEFTOUTER_9_811445_e, 0);

    struct timeval tv_r_JOIN_LEFTOUTER_9_738624_s, tv_r_JOIN_LEFTOUTER_9_738624_e;
    gettimeofday(&tv_r_JOIN_LEFTOUTER_9_738624_s, 0);
    SW_JOIN_LEFTOUTER_TD_9954081(tbl_JOIN_INNER_TD_10968541_output, tbl_Filter_TD_10273351_output, tbl_JOIN_LEFTOUTER_TD_9954081_output);
    gettimeofday(&tv_r_JOIN_LEFTOUTER_9_738624_e, 0);

    struct timeval tv_r_JOIN_LEFTOUTER_9_82409_s, tv_r_JOIN_LEFTOUTER_9_82409_e;
    gettimeofday(&tv_r_JOIN_LEFTOUTER_9_82409_s, 0);
    SW_JOIN_LEFTOUTER_TD_9685430(tbl_JOIN_INNER_TD_10170990_output, tbl_Filter_TD_10619629_output, tbl_JOIN_LEFTOUTER_TD_9685430_output);
    gettimeofday(&tv_r_JOIN_LEFTOUTER_9_82409_e, 0);

    struct timeval tv_r_Project_8_429802_s, tv_r_Project_8_429802_e;
    gettimeofday(&tv_r_Project_8_429802_s, 0);
    SW_Project_TD_8914491(tbl_JOIN_LEFTOUTER_TD_9282254_output, tbl_Project_TD_8914491_output);
    gettimeofday(&tv_r_Project_8_429802_e, 0);

    struct timeval tv_r_Project_8_505129_s, tv_r_Project_8_505129_e;
    gettimeofday(&tv_r_Project_8_505129_s, 0);
    SW_Project_TD_8980056(tbl_JOIN_LEFTOUTER_TD_9732787_output, tbl_Project_TD_8980056_output);
    gettimeofday(&tv_r_Project_8_505129_e, 0);

    struct timeval tv_r_Project_8_629998_s, tv_r_Project_8_629998_e;
    gettimeofday(&tv_r_Project_8_629998_s, 0);
    SW_Project_TD_8211225(tbl_JOIN_LEFTOUTER_TD_9932501_output, tbl_Project_TD_8211225_output);
    gettimeofday(&tv_r_Project_8_629998_e, 0);

    struct timeval tv_r_Project_8_852995_s, tv_r_Project_8_852995_e;
    gettimeofday(&tv_r_Project_8_852995_s, 0);
    SW_Project_TD_8125147(tbl_JOIN_LEFTOUTER_TD_9408405_output, tbl_Project_TD_8125147_output);
    gettimeofday(&tv_r_Project_8_852995_e, 0);

    struct timeval tv_r_Project_8_403379_s, tv_r_Project_8_403379_e;
    gettimeofday(&tv_r_Project_8_403379_s, 0);
    SW_Project_TD_8509641(tbl_JOIN_LEFTOUTER_TD_9954081_output, tbl_Project_TD_8509641_output);
    gettimeofday(&tv_r_Project_8_403379_e, 0);

    struct timeval tv_r_Project_8_707483_s, tv_r_Project_8_707483_e;
    gettimeofday(&tv_r_Project_8_707483_s, 0);
    SW_Project_TD_8151633(tbl_JOIN_LEFTOUTER_TD_9685430_output, tbl_Project_TD_8151633_output);
    gettimeofday(&tv_r_Project_8_707483_e, 0);

    struct timeval tv_r_Union_7_523404_s, tv_r_Union_7_523404_e;
    gettimeofday(&tv_r_Union_7_523404_s, 0);
    SW_Union_TD_72857(tbl_Project_TD_8211225_output, tbl_Project_TD_8980056_output, tbl_Project_TD_8914491_output, tbl_Union_TD_72857_output);
    gettimeofday(&tv_r_Union_7_523404_e, 0);

    struct timeval tv_r_Union_7_841939_s, tv_r_Union_7_841939_e;
    gettimeofday(&tv_r_Union_7_841939_s, 0);
    SW_Union_TD_7483707(tbl_Project_TD_8151633_output, tbl_Project_TD_8509641_output, tbl_Project_TD_8125147_output, tbl_Union_TD_7483707_output);
    gettimeofday(&tv_r_Union_7_841939_e, 0);

    struct timeval tv_r_Aggregate_6_455449_s, tv_r_Aggregate_6_455449_e;
    gettimeofday(&tv_r_Aggregate_6_455449_s, 0);
    trans_Aggregate_TD_641603.add(&(tbl_Union_TD_72857_output));
    trans_Aggregate_TD_641603.host2dev(0, &(prev_events_grp_Aggregate_TD_641603), &(events_h2d_wr_Aggregate_TD_641603[0]));
    events_grp_Aggregate_TD_641603.push_back(events_h2d_wr_Aggregate_TD_641603[0]);
    krnl_Aggregate_TD_641603.run(0, &(events_grp_Aggregate_TD_641603), &(events_Aggregate_TD_641603[0]));
    
    trans_Aggregate_TD_641603_out.add(&(tbl_Aggregate_TD_641603_output_preprocess));
    trans_Aggregate_TD_641603_out.dev2host(0, &(events_Aggregate_TD_641603), &(events_d2h_rd_Aggregate_TD_641603[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_641603_consolidate(tbl_Aggregate_TD_641603_output_preprocess, tbl_Aggregate_TD_641603_output);
    gettimeofday(&tv_r_Aggregate_6_455449_e, 0);

    struct timeval tv_r_Aggregate_6_840911_s, tv_r_Aggregate_6_840911_e;
    gettimeofday(&tv_r_Aggregate_6_840911_s, 0);
    trans_Aggregate_TD_6604092.add(&(tbl_Union_TD_7483707_output));
    trans_Aggregate_TD_6604092.host2dev(0, &(prev_events_grp_Aggregate_TD_6604092), &(events_h2d_wr_Aggregate_TD_6604092[0]));
    events_grp_Aggregate_TD_6604092.push_back(events_h2d_wr_Aggregate_TD_6604092[0]);
    krnl_Aggregate_TD_6604092.run(0, &(events_grp_Aggregate_TD_6604092), &(events_Aggregate_TD_6604092[0]));
    
    trans_Aggregate_TD_6604092_out.add(&(tbl_Aggregate_TD_6604092_output_preprocess));
    trans_Aggregate_TD_6604092_out.dev2host(0, &(events_Aggregate_TD_6604092), &(events_d2h_rd_Aggregate_TD_6604092[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_6604092_consolidate(tbl_Aggregate_TD_6604092_output_preprocess, tbl_Aggregate_TD_6604092_output);
    gettimeofday(&tv_r_Aggregate_6_840911_e, 0);

    struct timeval tv_r_Aggregate_5_461333_s, tv_r_Aggregate_5_461333_e;
    gettimeofday(&tv_r_Aggregate_5_461333_s, 0);
    prev_events_grp_Aggregate_TD_5612354.push_back(events_h2d_wr_Aggregate_TD_641603[0]);
    trans_Aggregate_TD_5612354.add(&(tbl_Aggregate_TD_641603_output));
    trans_Aggregate_TD_5612354.host2dev(0, &(prev_events_grp_Aggregate_TD_5612354), &(events_h2d_wr_Aggregate_TD_5612354[0]));
    events_grp_Aggregate_TD_5612354.push_back(events_h2d_wr_Aggregate_TD_5612354[0]);
    events_grp_Aggregate_TD_5612354.push_back(events_Aggregate_TD_641603[0]);
    krnl_Aggregate_TD_5612354.run(0, &(events_grp_Aggregate_TD_5612354), &(events_Aggregate_TD_5612354[0]));
    
    trans_Aggregate_TD_5612354_out.add(&(tbl_Aggregate_TD_5612354_output_preprocess));
    trans_Aggregate_TD_5612354_out.dev2host(0, &(events_Aggregate_TD_5612354), &(events_d2h_rd_Aggregate_TD_5612354[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_5612354_consolidate(tbl_Aggregate_TD_5612354_output_preprocess, tbl_Aggregate_TD_5612354_output);
    gettimeofday(&tv_r_Aggregate_5_461333_e, 0);

    struct timeval tv_r_Aggregate_5_258727_s, tv_r_Aggregate_5_258727_e;
    gettimeofday(&tv_r_Aggregate_5_258727_s, 0);
    prev_events_grp_Aggregate_TD_5950654.push_back(events_h2d_wr_Aggregate_TD_6604092[0]);
    trans_Aggregate_TD_5950654.add(&(tbl_Aggregate_TD_6604092_output));
    trans_Aggregate_TD_5950654.host2dev(0, &(prev_events_grp_Aggregate_TD_5950654), &(events_h2d_wr_Aggregate_TD_5950654[0]));
    events_grp_Aggregate_TD_5950654.push_back(events_h2d_wr_Aggregate_TD_5950654[0]);
    events_grp_Aggregate_TD_5950654.push_back(events_Aggregate_TD_6604092[0]);
    krnl_Aggregate_TD_5950654.run(0, &(events_grp_Aggregate_TD_5950654), &(events_Aggregate_TD_5950654[0]));
    
    trans_Aggregate_TD_5950654_out.add(&(tbl_Aggregate_TD_5950654_output_preprocess));
    trans_Aggregate_TD_5950654_out.dev2host(0, &(events_Aggregate_TD_5950654), &(events_d2h_rd_Aggregate_TD_5950654[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_5950654_consolidate(tbl_Aggregate_TD_5950654_output_preprocess, tbl_Aggregate_TD_5950654_output);
    gettimeofday(&tv_r_Aggregate_5_258727_e, 0);

    struct timeval tv_r_JOIN_INNER_4_320265_s, tv_r_JOIN_INNER_4_320265_e;
    gettimeofday(&tv_r_JOIN_INNER_4_320265_s, 0);
    SW_JOIN_INNER_TD_4241816(tbl_Aggregate_TD_5950654_output, tbl_Aggregate_TD_5612354_output, tbl_JOIN_INNER_TD_4241816_output);
    gettimeofday(&tv_r_JOIN_INNER_4_320265_e, 0);

    struct timeval tv_r_Project_3_904992_s, tv_r_Project_3_904992_e;
    gettimeofday(&tv_r_Project_3_904992_s, 0);
    SW_Project_TD_3602289(tbl_JOIN_INNER_TD_4241816_output, tbl_Project_TD_3602289_output);
    gettimeofday(&tv_r_Project_3_904992_e, 0);

    struct timeval tv_r_Sort_2_164409_s, tv_r_Sort_2_164409_e;
    gettimeofday(&tv_r_Sort_2_164409_s, 0);
    SW_Sort_TD_2198469(tbl_Project_TD_3602289_output, tbl_Sort_TD_2198469_output);
    gettimeofday(&tv_r_Sort_2_164409_e, 0);

    struct timeval tv_r_LocalLimit_1_700142_s, tv_r_LocalLimit_1_700142_e;
    gettimeofday(&tv_r_LocalLimit_1_700142_s, 0);
    SW_LocalLimit_TD_1422359(tbl_Sort_TD_2198469_output, tbl_LocalLimit_TD_1422359_output);
    gettimeofday(&tv_r_LocalLimit_1_700142_e, 0);

    struct timeval tv_r_GlobalLimit_0_251322_s, tv_r_GlobalLimit_0_251322_e;
    gettimeofday(&tv_r_GlobalLimit_0_251322_s, 0);
    SW_GlobalLimit_TD_0663158(tbl_LocalLimit_TD_1422359_output, tbl_GlobalLimit_TD_0663158_output);
    gettimeofday(&tv_r_GlobalLimit_0_251322_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_419043_s, &tv_r_Filter_12_419043_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13186167_input: " << tbl_SerializeFromObject_TD_13186167_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_94988_s, &tv_r_Filter_12_94988_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13650294_input: " << tbl_SerializeFromObject_TD_13650294_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_747855_s, &tv_r_Filter_12_747855_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13207901_input: " << tbl_SerializeFromObject_TD_13207901_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_377409_s, &tv_r_Filter_12_377409_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13788587_input: " << tbl_SerializeFromObject_TD_13788587_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_463481_s, &tv_r_Filter_12_463481_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13916556_input: " << tbl_SerializeFromObject_TD_13916556_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_440899_s, &tv_r_Filter_12_440899_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13386576_input: " << tbl_SerializeFromObject_TD_13386576_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_626871_s, &tv_r_Filter_12_626871_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13679127_input: " << tbl_SerializeFromObject_TD_13679127_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_150533_s, &tv_r_Filter_12_150533_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13634156_input: " << tbl_SerializeFromObject_TD_13634156_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_721929_s, &tv_r_Filter_12_721929_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13698675_input: " << tbl_SerializeFromObject_TD_13698675_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_92346_s, &tv_r_Filter_12_92346_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13666961_input: " << tbl_SerializeFromObject_TD_13666961_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_559442_s, &tv_r_Filter_12_559442_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13648438_input: " << tbl_SerializeFromObject_TD_13648438_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_262116_s, &tv_r_Filter_12_262116_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13951278_input: " << tbl_SerializeFromObject_TD_13951278_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_819768_s, &tv_r_Filter_11_819768_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12141446_input: " << tbl_SerializeFromObject_TD_12141446_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_11: " << tvdiff(&tv_r_JOIN_INNER_11_856694_s, &tv_r_JOIN_INNER_11_856694_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_12741275_output: " << tbl_Filter_TD_12741275_output.getNumRow() << " " << "tbl_Filter_TD_12881251_output: " << tbl_Filter_TD_12881251_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_831828_s, &tv_r_Filter_11_831828_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12935935_input: " << tbl_SerializeFromObject_TD_12935935_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_11: " << tvdiff(&tv_r_JOIN_INNER_11_330484_s, &tv_r_JOIN_INNER_11_330484_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_12349655_output: " << tbl_Filter_TD_12349655_output.getNumRow() << " " << "tbl_Filter_TD_12246209_output: " << tbl_Filter_TD_12246209_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_600268_s, &tv_r_Filter_11_600268_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12876421_input: " << tbl_SerializeFromObject_TD_12876421_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_11: " << tvdiff(&tv_r_JOIN_INNER_11_521234_s, &tv_r_JOIN_INNER_11_521234_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_12968394_output: " << tbl_Filter_TD_12968394_output.getNumRow() << " " << "tbl_Filter_TD_1270854_output: " << tbl_Filter_TD_1270854_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_500810_s, &tv_r_Filter_11_500810_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12818793_input: " << tbl_SerializeFromObject_TD_12818793_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_11: " << tvdiff(&tv_r_JOIN_INNER_11_786611_s, &tv_r_JOIN_INNER_11_786611_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_12460154_output: " << tbl_Filter_TD_12460154_output.getNumRow() << " " << "tbl_Filter_TD_12301909_output: " << tbl_Filter_TD_12301909_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_454880_s, &tv_r_Filter_11_454880_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12757823_input: " << tbl_SerializeFromObject_TD_12757823_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_11: " << tvdiff(&tv_r_JOIN_INNER_11_227471_s, &tv_r_JOIN_INNER_11_227471_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_12304293_output: " << tbl_Filter_TD_12304293_output.getNumRow() << " " << "tbl_Filter_TD_12968861_output: " << tbl_Filter_TD_12968861_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_567191_s, &tv_r_Filter_11_567191_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12955447_input: " << tbl_SerializeFromObject_TD_12955447_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_11: " << tvdiff(&tv_r_JOIN_INNER_11_677095_s, &tv_r_JOIN_INNER_11_677095_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_1278768_output: " << tbl_Filter_TD_1278768_output.getNumRow() << " " << "tbl_Filter_TD_12265825_output: " << tbl_Filter_TD_12265825_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_560_s, &tv_r_Filter_10_560_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11542495_input: " << tbl_SerializeFromObject_TD_11542495_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_902848_s, &tv_r_JOIN_INNER_10_902848_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_11243517_output: " << tbl_JOIN_INNER_TD_11243517_output.getNumRow() << " " << "tbl_Filter_TD_11196108_output: " << tbl_Filter_TD_11196108_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_654808_s, &tv_r_Filter_10_654808_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11213585_input: " << tbl_SerializeFromObject_TD_11213585_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_760918_s, &tv_r_JOIN_INNER_10_760918_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_11321498_output: " << tbl_JOIN_INNER_TD_11321498_output.getNumRow() << " " << "tbl_Filter_TD_11485295_output: " << tbl_Filter_TD_11485295_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_790164_s, &tv_r_Filter_10_790164_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11428191_input: " << tbl_SerializeFromObject_TD_11428191_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_768843_s, &tv_r_JOIN_INNER_10_768843_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_11469408_output: " << tbl_JOIN_INNER_TD_11469408_output.getNumRow() << " " << "tbl_Filter_TD_11546642_output: " << tbl_Filter_TD_11546642_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_535401_s, &tv_r_Filter_10_535401_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11105343_input: " << tbl_SerializeFromObject_TD_11105343_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_364831_s, &tv_r_JOIN_INNER_10_364831_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_11650737_output: " << tbl_JOIN_INNER_TD_11650737_output.getNumRow() << " " << "tbl_Filter_TD_11291823_output: " << tbl_Filter_TD_11291823_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_476170_s, &tv_r_Filter_10_476170_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11832329_input: " << tbl_SerializeFromObject_TD_11832329_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_489500_s, &tv_r_JOIN_INNER_10_489500_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_11868273_output: " << tbl_JOIN_INNER_TD_11868273_output.getNumRow() << " " << "tbl_Filter_TD_11126261_output: " << tbl_Filter_TD_11126261_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_372417_s, &tv_r_Filter_10_372417_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11308853_input: " << tbl_SerializeFromObject_TD_11308853_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_882740_s, &tv_r_JOIN_INNER_10_882740_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_11627645_output: " << tbl_JOIN_INNER_TD_11627645_output.getNumRow() << " " << "tbl_Filter_TD_11781310_output: " << tbl_Filter_TD_11781310_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTOUTER_9: " << tvdiff(&tv_r_JOIN_LEFTOUTER_9_221292_s, &tv_r_JOIN_LEFTOUTER_9_221292_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10158452_output: " << tbl_JOIN_INNER_TD_10158452_output.getNumRow() << " " << "tbl_Filter_TD_10776215_output: " << tbl_Filter_TD_10776215_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTOUTER_9: " << tvdiff(&tv_r_JOIN_LEFTOUTER_9_623404_s, &tv_r_JOIN_LEFTOUTER_9_623404_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10931863_output: " << tbl_JOIN_INNER_TD_10931863_output.getNumRow() << " " << "tbl_Filter_TD_1021027_output: " << tbl_Filter_TD_1021027_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTOUTER_9: " << tvdiff(&tv_r_JOIN_LEFTOUTER_9_332984_s, &tv_r_JOIN_LEFTOUTER_9_332984_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10795304_output: " << tbl_JOIN_INNER_TD_10795304_output.getNumRow() << " " << "tbl_Filter_TD_1062905_output: " << tbl_Filter_TD_1062905_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTOUTER_9: " << tvdiff(&tv_r_JOIN_LEFTOUTER_9_811445_s, &tv_r_JOIN_LEFTOUTER_9_811445_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10636324_output: " << tbl_JOIN_INNER_TD_10636324_output.getNumRow() << " " << "tbl_Filter_TD_10332983_output: " << tbl_Filter_TD_10332983_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTOUTER_9: " << tvdiff(&tv_r_JOIN_LEFTOUTER_9_738624_s, &tv_r_JOIN_LEFTOUTER_9_738624_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10968541_output: " << tbl_JOIN_INNER_TD_10968541_output.getNumRow() << " " << "tbl_Filter_TD_10273351_output: " << tbl_Filter_TD_10273351_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTOUTER_9: " << tvdiff(&tv_r_JOIN_LEFTOUTER_9_82409_s, &tv_r_JOIN_LEFTOUTER_9_82409_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10170990_output: " << tbl_JOIN_INNER_TD_10170990_output.getNumRow() << " " << "tbl_Filter_TD_10619629_output: " << tbl_Filter_TD_10619629_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_8: " << tvdiff(&tv_r_Project_8_429802_s, &tv_r_Project_8_429802_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTOUTER_TD_9282254_output: " << tbl_JOIN_LEFTOUTER_TD_9282254_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_8: " << tvdiff(&tv_r_Project_8_505129_s, &tv_r_Project_8_505129_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTOUTER_TD_9732787_output: " << tbl_JOIN_LEFTOUTER_TD_9732787_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_8: " << tvdiff(&tv_r_Project_8_629998_s, &tv_r_Project_8_629998_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTOUTER_TD_9932501_output: " << tbl_JOIN_LEFTOUTER_TD_9932501_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_8: " << tvdiff(&tv_r_Project_8_852995_s, &tv_r_Project_8_852995_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTOUTER_TD_9408405_output: " << tbl_JOIN_LEFTOUTER_TD_9408405_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_8: " << tvdiff(&tv_r_Project_8_403379_s, &tv_r_Project_8_403379_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTOUTER_TD_9954081_output: " << tbl_JOIN_LEFTOUTER_TD_9954081_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_8: " << tvdiff(&tv_r_Project_8_707483_s, &tv_r_Project_8_707483_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTOUTER_TD_9685430_output: " << tbl_JOIN_LEFTOUTER_TD_9685430_output.getNumRow() << " " << std::endl; 

    std::cout << "Union_7: " << tvdiff(&tv_r_Union_7_523404_s, &tv_r_Union_7_523404_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_8211225_output: " << tbl_Project_TD_8211225_output.getNumRow() << " " << "tbl_Project_TD_8980056_output: " << tbl_Project_TD_8980056_output.getNumRow() << " " << "tbl_Project_TD_8914491_output: " << tbl_Project_TD_8914491_output.getNumRow() << " " << std::endl; 

    std::cout << "Union_7: " << tvdiff(&tv_r_Union_7_841939_s, &tv_r_Union_7_841939_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_8151633_output: " << tbl_Project_TD_8151633_output.getNumRow() << " " << "tbl_Project_TD_8509641_output: " << tbl_Project_TD_8509641_output.getNumRow() << " " << "tbl_Project_TD_8125147_output: " << tbl_Project_TD_8125147_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_6: " << tvdiff(&tv_r_Aggregate_6_455449_s, &tv_r_Aggregate_6_455449_e) / 1000.0 << " ms " 
     << "tbl_Union_TD_72857_output: " << tbl_Union_TD_72857_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_6: " << tvdiff(&tv_r_Aggregate_6_840911_s, &tv_r_Aggregate_6_840911_e) / 1000.0 << " ms " 
     << "tbl_Union_TD_7483707_output: " << tbl_Union_TD_7483707_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_461333_s, &tv_r_Aggregate_5_461333_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_641603_output: " << tbl_Aggregate_TD_641603_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_258727_s, &tv_r_Aggregate_5_258727_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_6604092_output: " << tbl_Aggregate_TD_6604092_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_320265_s, &tv_r_JOIN_INNER_4_320265_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_5950654_output: " << tbl_Aggregate_TD_5950654_output.getNumRow() << " " << "tbl_Aggregate_TD_5612354_output: " << tbl_Aggregate_TD_5612354_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_3: " << tvdiff(&tv_r_Project_3_904992_s, &tv_r_Project_3_904992_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4241816_output: " << tbl_JOIN_INNER_TD_4241816_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_164409_s, &tv_r_Sort_2_164409_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_3602289_output: " << tbl_Project_TD_3602289_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_700142_s, &tv_r_LocalLimit_1_700142_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2198469_output: " << tbl_Sort_TD_2198469_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_251322_s, &tv_r_GlobalLimit_0_251322_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1422359_output: " << tbl_LocalLimit_TD_1422359_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 4.963705 * 1000 << "ms" << std::endl; 
    return 0; 
}
