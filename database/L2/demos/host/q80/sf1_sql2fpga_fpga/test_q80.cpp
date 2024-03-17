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

#include "cfgFunc_q80.hpp" 
#include "q80.hpp" 

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
    std::cout << "NOTE:running query #80\n."; 
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
    Table tbl_GlobalLimit_TD_0481036_output("tbl_GlobalLimit_TD_0481036_output", 6100000, 5, "");
    tbl_GlobalLimit_TD_0481036_output.allocateHost();
    Table tbl_LocalLimit_TD_1122885_output("tbl_LocalLimit_TD_1122885_output", 6100000, 5, "");
    tbl_LocalLimit_TD_1122885_output.allocateHost();
    Table tbl_Sort_TD_2745446_output("tbl_Sort_TD_2745446_output", 6100000, 5, "");
    tbl_Sort_TD_2745446_output.allocateHost();
    Table tbl_Aggregate_TD_3486002_output("tbl_Aggregate_TD_3486002_output", 6100000, 5, "");
    tbl_Aggregate_TD_3486002_output.allocateHost();
    Table tbl_Expand_TD_4666629_output("tbl_Expand_TD_4666629_output", 6100000, 6, "");
    tbl_Expand_TD_4666629_output.allocateHost();
    Table tbl_Union_TD_535352_output("tbl_Union_TD_535352_output", 6100000, 5, "");
    tbl_Union_TD_535352_output.allocateHost();
    Table tbl_Aggregate_TD_6197270_output("tbl_Aggregate_TD_6197270_output", 6100000, 5, "");
    tbl_Aggregate_TD_6197270_output.allocateHost();
    Table tbl_Aggregate_TD_6631003_output("tbl_Aggregate_TD_6631003_output", 6100000, 5, "");
    tbl_Aggregate_TD_6631003_output.allocateHost();
    Table tbl_Aggregate_TD_6790829_output("tbl_Aggregate_TD_6790829_output", 6100000, 5, "");
    tbl_Aggregate_TD_6790829_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7353460_output("tbl_JOIN_INNER_TD_7353460_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_7353460_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7282618_output("tbl_JOIN_INNER_TD_7282618_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_7282618_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7114427_output("tbl_JOIN_INNER_TD_7114427_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_7114427_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8230445_output("tbl_JOIN_INNER_TD_8230445_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_8230445_output.allocateHost();
    Table tbl_Filter_TD_822743_output("tbl_Filter_TD_822743_output", 6100000, 1, "");
    tbl_Filter_TD_822743_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8531564_output("tbl_JOIN_INNER_TD_8531564_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_8531564_output.allocateHost();
    Table tbl_Filter_TD_8291775_output("tbl_Filter_TD_8291775_output", 6100000, 1, "");
    tbl_Filter_TD_8291775_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8859329_output("tbl_JOIN_INNER_TD_8859329_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_8859329_output.allocateHost();
    Table tbl_Filter_TD_8992697_output("tbl_Filter_TD_8992697_output", 6100000, 1, "");
    tbl_Filter_TD_8992697_output.allocateHost();
    Table tbl_JOIN_INNER_TD_9447563_output("tbl_JOIN_INNER_TD_9447563_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_9447563_output.allocateHost();
    Table tbl_Filter_TD_9190310_output("tbl_Filter_TD_9190310_output", 6100000, 1, "");
    tbl_Filter_TD_9190310_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9730161_input;
    tbl_SerializeFromObject_TD_9730161_input = Table("promotion", promotion_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9730161_input.addCol("p_promo_sk", 4);
    tbl_SerializeFromObject_TD_9730161_input.addCol("p_channel_tv", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9730161_input.allocateHost();
    tbl_SerializeFromObject_TD_9730161_input.loadHost();
    Table tbl_JOIN_INNER_TD_9809851_output("tbl_JOIN_INNER_TD_9809851_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_9809851_output.allocateHost();
    Table tbl_Filter_TD_949741_output("tbl_Filter_TD_949741_output", 6100000, 1, "");
    tbl_Filter_TD_949741_output.allocateHost();
    Table tbl_SerializeFromObject_TD_917945_input;
    tbl_SerializeFromObject_TD_917945_input = Table("promotion", promotion_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_917945_input.addCol("p_promo_sk", 4);
    tbl_SerializeFromObject_TD_917945_input.addCol("p_channel_tv", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_917945_input.allocateHost();
    tbl_SerializeFromObject_TD_917945_input.loadHost();
    Table tbl_JOIN_INNER_TD_9261141_output("tbl_JOIN_INNER_TD_9261141_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_9261141_output.allocateHost();
    Table tbl_Filter_TD_9570177_output("tbl_Filter_TD_9570177_output", 6100000, 1, "");
    tbl_Filter_TD_9570177_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9748703_input;
    tbl_SerializeFromObject_TD_9748703_input = Table("promotion", promotion_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9748703_input.addCol("p_promo_sk", 4);
    tbl_SerializeFromObject_TD_9748703_input.addCol("p_channel_tv", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9748703_input.allocateHost();
    tbl_SerializeFromObject_TD_9748703_input.loadHost();
    Table tbl_JOIN_INNER_TD_10934769_output("tbl_JOIN_INNER_TD_10934769_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_10934769_output.allocateHost();
    Table tbl_Filter_TD_10841618_output("tbl_Filter_TD_10841618_output", 6100000, 2, "");
    tbl_Filter_TD_10841618_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10717886_input;
    tbl_SerializeFromObject_TD_10717886_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10717886_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_10717886_input.addCol("i_current_price", 4);
    tbl_SerializeFromObject_TD_10717886_input.allocateHost();
    tbl_SerializeFromObject_TD_10717886_input.loadHost();
    Table tbl_JOIN_INNER_TD_10664187_output("tbl_JOIN_INNER_TD_10664187_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_10664187_output.allocateHost();
    Table tbl_Filter_TD_10805972_output("tbl_Filter_TD_10805972_output", 6100000, 2, "");
    tbl_Filter_TD_10805972_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10840973_input;
    tbl_SerializeFromObject_TD_10840973_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10840973_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_10840973_input.addCol("i_current_price", 4);
    tbl_SerializeFromObject_TD_10840973_input.allocateHost();
    tbl_SerializeFromObject_TD_10840973_input.loadHost();
    Table tbl_JOIN_INNER_TD_10161275_output("tbl_JOIN_INNER_TD_10161275_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_10161275_output.allocateHost();
    Table tbl_Filter_TD_10449479_output("tbl_Filter_TD_10449479_output", 6100000, 2, "");
    tbl_Filter_TD_10449479_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10615885_input;
    tbl_SerializeFromObject_TD_10615885_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10615885_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_10615885_input.addCol("i_current_price", 4);
    tbl_SerializeFromObject_TD_10615885_input.allocateHost();
    tbl_SerializeFromObject_TD_10615885_input.loadHost();
    Table tbl_JOIN_LEFTOUTER_TD_11633857_output("tbl_JOIN_LEFTOUTER_TD_11633857_output", 6100000, 8, "");
    tbl_JOIN_LEFTOUTER_TD_11633857_output.allocateHost();
    Table tbl_Filter_TD_11838376_output("tbl_Filter_TD_11838376_output", 6100000, 1, "");
    tbl_Filter_TD_11838376_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11546211_input;
    tbl_SerializeFromObject_TD_11546211_input = Table("store", store_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11546211_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_11546211_input.addCol("s_store_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11546211_input.allocateHost();
    tbl_SerializeFromObject_TD_11546211_input.loadHost();
    Table tbl_JOIN_LEFTOUTER_TD_11822562_output("tbl_JOIN_LEFTOUTER_TD_11822562_output", 6100000, 8, "");
    tbl_JOIN_LEFTOUTER_TD_11822562_output.allocateHost();
    Table tbl_Filter_TD_11592606_output("tbl_Filter_TD_11592606_output", 6100000, 1, "");
    tbl_Filter_TD_11592606_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11468781_input;
    tbl_SerializeFromObject_TD_11468781_input = Table("catalog_page", catalog_page_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11468781_input.addCol("cp_catalog_page_sk", 4);
    tbl_SerializeFromObject_TD_11468781_input.addCol("cp_catalog_page_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11468781_input.allocateHost();
    tbl_SerializeFromObject_TD_11468781_input.loadHost();
    Table tbl_JOIN_LEFTOUTER_TD_11893643_output("tbl_JOIN_LEFTOUTER_TD_11893643_output", 6100000, 8, "");
    tbl_JOIN_LEFTOUTER_TD_11893643_output.allocateHost();
    Table tbl_Filter_TD_11839303_output("tbl_Filter_TD_11839303_output", 6100000, 1, "");
    tbl_Filter_TD_11839303_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11102949_input;
    tbl_SerializeFromObject_TD_11102949_input = Table("web_site", web_site_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11102949_input.addCol("web_site_sk", 4);
    tbl_SerializeFromObject_TD_11102949_input.addCol("web_site_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11102949_input.allocateHost();
    tbl_SerializeFromObject_TD_11102949_input.loadHost();
    Table tbl_Filter_TD_12213268_output("tbl_Filter_TD_12213268_output", 6100000, 7, "");
    tbl_Filter_TD_12213268_output.allocateHost();
    Table tbl_Filter_TD_12737824_output("tbl_Filter_TD_12737824_output", 6100000, 4, "");
    tbl_Filter_TD_12737824_output.allocateHost();
    Table tbl_SerializeFromObject_TD_12875359_input;
    tbl_SerializeFromObject_TD_12875359_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12875359_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_12875359_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_12875359_input.allocateHost();
    tbl_SerializeFromObject_TD_12875359_input.loadHost();
    Table tbl_Filter_TD_12684117_output("tbl_Filter_TD_12684117_output", 6100000, 7, "");
    tbl_Filter_TD_12684117_output.allocateHost();
    Table tbl_Filter_TD_12846373_output("tbl_Filter_TD_12846373_output", 6100000, 4, "");
    tbl_Filter_TD_12846373_output.allocateHost();
    Table tbl_SerializeFromObject_TD_12852394_input;
    tbl_SerializeFromObject_TD_12852394_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12852394_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_12852394_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_12852394_input.allocateHost();
    tbl_SerializeFromObject_TD_12852394_input.loadHost();
    Table tbl_Filter_TD_12385515_output("tbl_Filter_TD_12385515_output", 6100000, 7, "");
    tbl_Filter_TD_12385515_output.allocateHost();
    Table tbl_Filter_TD_12258539_output("tbl_Filter_TD_12258539_output", 6100000, 4, "");
    tbl_Filter_TD_12258539_output.allocateHost();
    Table tbl_SerializeFromObject_TD_12523840_input;
    tbl_SerializeFromObject_TD_12523840_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12523840_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_12523840_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_12523840_input.allocateHost();
    tbl_SerializeFromObject_TD_12523840_input.loadHost();
    Table tbl_SerializeFromObject_TD_13474202_input;
    tbl_SerializeFromObject_TD_13474202_input = Table("store_sales", store_sales_n, 7, in_dir, "orc");
    tbl_SerializeFromObject_TD_13474202_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_13474202_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_13474202_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_13474202_input.addCol("ss_promo_sk", 4);
    tbl_SerializeFromObject_TD_13474202_input.addCol("ss_ticket_number", 8);
    tbl_SerializeFromObject_TD_13474202_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_13474202_input.addCol("ss_net_profit", 4);
    tbl_SerializeFromObject_TD_13474202_input.allocateHost();
    tbl_SerializeFromObject_TD_13474202_input.loadHost();
    Table tbl_SerializeFromObject_TD_13406148_input;
    tbl_SerializeFromObject_TD_13406148_input = Table("store_returns", store_returns_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_13406148_input.addCol("sr_item_sk", 4);
    tbl_SerializeFromObject_TD_13406148_input.addCol("sr_ticket_number", 8);
    tbl_SerializeFromObject_TD_13406148_input.addCol("sr_return_amt", 4);
    tbl_SerializeFromObject_TD_13406148_input.addCol("sr_net_loss", 4);
    tbl_SerializeFromObject_TD_13406148_input.allocateHost();
    tbl_SerializeFromObject_TD_13406148_input.loadHost();
    Table tbl_SerializeFromObject_TD_13787663_input;
    tbl_SerializeFromObject_TD_13787663_input = Table("catalog_sales", catalog_sales_n, 7, in_dir, "orc");
    tbl_SerializeFromObject_TD_13787663_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_13787663_input.addCol("cs_catalog_page_sk", 4);
    tbl_SerializeFromObject_TD_13787663_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_13787663_input.addCol("cs_promo_sk", 4);
    tbl_SerializeFromObject_TD_13787663_input.addCol("cs_order_number", 8);
    tbl_SerializeFromObject_TD_13787663_input.addCol("cs_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_13787663_input.addCol("cs_net_profit", 4);
    tbl_SerializeFromObject_TD_13787663_input.allocateHost();
    tbl_SerializeFromObject_TD_13787663_input.loadHost();
    Table tbl_SerializeFromObject_TD_13541115_input;
    tbl_SerializeFromObject_TD_13541115_input = Table("catalog_returns", catalog_returns_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_13541115_input.addCol("cr_item_sk", 4);
    tbl_SerializeFromObject_TD_13541115_input.addCol("cr_order_number", 8);
    tbl_SerializeFromObject_TD_13541115_input.addCol("cr_return_amount", 4);
    tbl_SerializeFromObject_TD_13541115_input.addCol("cr_net_loss", 4);
    tbl_SerializeFromObject_TD_13541115_input.allocateHost();
    tbl_SerializeFromObject_TD_13541115_input.loadHost();
    Table tbl_SerializeFromObject_TD_1336654_input;
    tbl_SerializeFromObject_TD_1336654_input = Table("web_sales", web_sales_n, 7, in_dir, "orc");
    tbl_SerializeFromObject_TD_1336654_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_1336654_input.addCol("ws_item_sk", 4);
    tbl_SerializeFromObject_TD_1336654_input.addCol("ws_web_site_sk", 4);
    tbl_SerializeFromObject_TD_1336654_input.addCol("ws_promo_sk", 4);
    tbl_SerializeFromObject_TD_1336654_input.addCol("ws_order_number", 8);
    tbl_SerializeFromObject_TD_1336654_input.addCol("ws_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_1336654_input.addCol("ws_net_profit", 4);
    tbl_SerializeFromObject_TD_1336654_input.allocateHost();
    tbl_SerializeFromObject_TD_1336654_input.loadHost();
    Table tbl_SerializeFromObject_TD_13519132_input;
    tbl_SerializeFromObject_TD_13519132_input = Table("web_returns", web_returns_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_13519132_input.addCol("wr_item_sk", 4);
    tbl_SerializeFromObject_TD_13519132_input.addCol("wr_order_number", 8);
    tbl_SerializeFromObject_TD_13519132_input.addCol("wr_return_amt", 4);
    tbl_SerializeFromObject_TD_13519132_input.addCol("wr_net_loss", 4);
    tbl_SerializeFromObject_TD_13519132_input.allocateHost();
    tbl_SerializeFromObject_TD_13519132_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_10934769_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_10664187_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_10161275_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTOUTER_TD_11633857_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11838376_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTOUTER_TD_11822562_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11592606_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTOUTER_TD_11893643_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11839303_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_12213268_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_12737824_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_12684117_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_12846373_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_12385515_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_12258539_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_10934769_cmds;
    cfg_JOIN_INNER_TD_10934769_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_10934769_gqe_join (cfg_JOIN_INNER_TD_10934769_cmds.cmd);
    cfg_JOIN_INNER_TD_10934769_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_10664187_cmds;
    cfg_JOIN_INNER_TD_10664187_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_10664187_gqe_join (cfg_JOIN_INNER_TD_10664187_cmds.cmd);
    cfg_JOIN_INNER_TD_10664187_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_10161275_cmds;
    cfg_JOIN_INNER_TD_10161275_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_10161275_gqe_join (cfg_JOIN_INNER_TD_10161275_cmds.cmd);
    cfg_JOIN_INNER_TD_10161275_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTOUTER_TD_11633857_cmds;
    cfg_JOIN_LEFTOUTER_TD_11633857_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTOUTER_TD_11633857_gqe_join (cfg_JOIN_LEFTOUTER_TD_11633857_cmds.cmd);
    cfg_JOIN_LEFTOUTER_TD_11633857_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTOUTER_TD_11822562_cmds;
    cfg_JOIN_LEFTOUTER_TD_11822562_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTOUTER_TD_11822562_gqe_join (cfg_JOIN_LEFTOUTER_TD_11822562_cmds.cmd);
    cfg_JOIN_LEFTOUTER_TD_11822562_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTOUTER_TD_11893643_cmds;
    cfg_JOIN_LEFTOUTER_TD_11893643_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTOUTER_TD_11893643_gqe_join (cfg_JOIN_LEFTOUTER_TD_11893643_cmds.cmd);
    cfg_JOIN_LEFTOUTER_TD_11893643_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_10934769;
    krnl_JOIN_INNER_TD_10934769 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_10934769.setup(tbl_JOIN_LEFTOUTER_TD_11633857_output, tbl_Filter_TD_11838376_output, tbl_JOIN_INNER_TD_10934769_output, cfg_JOIN_INNER_TD_10934769_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_10664187;
    krnl_JOIN_INNER_TD_10664187 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_10664187.setup(tbl_JOIN_LEFTOUTER_TD_11822562_output, tbl_Filter_TD_11592606_output, tbl_JOIN_INNER_TD_10664187_output, cfg_JOIN_INNER_TD_10664187_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_10161275;
    krnl_JOIN_INNER_TD_10161275 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_10161275.setup(tbl_JOIN_LEFTOUTER_TD_11893643_output, tbl_Filter_TD_11839303_output, tbl_JOIN_INNER_TD_10161275_output, cfg_JOIN_INNER_TD_10161275_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTOUTER_TD_11633857;
    krnl_JOIN_LEFTOUTER_TD_11633857 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTOUTER_TD_11633857.setup(tbl_Filter_TD_12213268_output, tbl_Filter_TD_12737824_output, tbl_JOIN_LEFTOUTER_TD_11633857_output, cfg_JOIN_LEFTOUTER_TD_11633857_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTOUTER_TD_11822562;
    krnl_JOIN_LEFTOUTER_TD_11822562 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTOUTER_TD_11822562.setup(tbl_Filter_TD_12684117_output, tbl_Filter_TD_12846373_output, tbl_JOIN_LEFTOUTER_TD_11822562_output, cfg_JOIN_LEFTOUTER_TD_11822562_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTOUTER_TD_11893643;
    krnl_JOIN_LEFTOUTER_TD_11893643 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTOUTER_TD_11893643.setup(tbl_Filter_TD_12385515_output, tbl_Filter_TD_12258539_output, tbl_JOIN_LEFTOUTER_TD_11893643_output, cfg_JOIN_LEFTOUTER_TD_11893643_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_10934769;
    trans_JOIN_INNER_TD_10934769.setq(q_h);
    trans_JOIN_INNER_TD_10934769.add(&(cfg_JOIN_INNER_TD_10934769_cmds));
    transEngine trans_JOIN_INNER_TD_10934769_out;
    trans_JOIN_INNER_TD_10934769_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_10664187;
    trans_JOIN_INNER_TD_10664187.setq(q_h);
    trans_JOIN_INNER_TD_10664187.add(&(cfg_JOIN_INNER_TD_10664187_cmds));
    transEngine trans_JOIN_INNER_TD_10664187_out;
    trans_JOIN_INNER_TD_10664187_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_10161275;
    trans_JOIN_INNER_TD_10161275.setq(q_h);
    trans_JOIN_INNER_TD_10161275.add(&(cfg_JOIN_INNER_TD_10161275_cmds));
    transEngine trans_JOIN_INNER_TD_10161275_out;
    trans_JOIN_INNER_TD_10161275_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_LEFTOUTER_TD_11633857;
    trans_JOIN_LEFTOUTER_TD_11633857.setq(q_h);
    trans_JOIN_LEFTOUTER_TD_11633857.add(&(cfg_JOIN_LEFTOUTER_TD_11633857_cmds));
    q_h.finish();
    transEngine trans_JOIN_LEFTOUTER_TD_11822562;
    trans_JOIN_LEFTOUTER_TD_11822562.setq(q_h);
    trans_JOIN_LEFTOUTER_TD_11822562.add(&(cfg_JOIN_LEFTOUTER_TD_11822562_cmds));
    q_h.finish();
    transEngine trans_JOIN_LEFTOUTER_TD_11893643;
    trans_JOIN_LEFTOUTER_TD_11893643.setq(q_h);
    trans_JOIN_LEFTOUTER_TD_11893643.add(&(cfg_JOIN_LEFTOUTER_TD_11893643_cmds));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_10934769;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_10934769;
    std::vector<cl::Event> events_JOIN_INNER_TD_10934769;
    events_h2d_wr_JOIN_INNER_TD_10934769.resize(1);
    events_d2h_rd_JOIN_INNER_TD_10934769.resize(1);
    events_JOIN_INNER_TD_10934769.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_10934769;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_10934769;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_10664187;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_10664187;
    std::vector<cl::Event> events_JOIN_INNER_TD_10664187;
    events_h2d_wr_JOIN_INNER_TD_10664187.resize(1);
    events_d2h_rd_JOIN_INNER_TD_10664187.resize(1);
    events_JOIN_INNER_TD_10664187.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_10664187;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_10664187;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_10161275;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_10161275;
    std::vector<cl::Event> events_JOIN_INNER_TD_10161275;
    events_h2d_wr_JOIN_INNER_TD_10161275.resize(1);
    events_d2h_rd_JOIN_INNER_TD_10161275.resize(1);
    events_JOIN_INNER_TD_10161275.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_10161275;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_10161275;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTOUTER_TD_11633857;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTOUTER_TD_11633857;
    std::vector<cl::Event> events_JOIN_LEFTOUTER_TD_11633857;
    events_h2d_wr_JOIN_LEFTOUTER_TD_11633857.resize(1);
    events_d2h_rd_JOIN_LEFTOUTER_TD_11633857.resize(1);
    events_JOIN_LEFTOUTER_TD_11633857.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTOUTER_TD_11633857;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTOUTER_TD_11633857;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTOUTER_TD_11822562;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTOUTER_TD_11822562;
    std::vector<cl::Event> events_JOIN_LEFTOUTER_TD_11822562;
    events_h2d_wr_JOIN_LEFTOUTER_TD_11822562.resize(1);
    events_d2h_rd_JOIN_LEFTOUTER_TD_11822562.resize(1);
    events_JOIN_LEFTOUTER_TD_11822562.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTOUTER_TD_11822562;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTOUTER_TD_11822562;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTOUTER_TD_11893643;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTOUTER_TD_11893643;
    std::vector<cl::Event> events_JOIN_LEFTOUTER_TD_11893643;
    events_h2d_wr_JOIN_LEFTOUTER_TD_11893643.resize(1);
    events_d2h_rd_JOIN_LEFTOUTER_TD_11893643.resize(1);
    events_JOIN_LEFTOUTER_TD_11893643.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTOUTER_TD_11893643;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTOUTER_TD_11893643;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_12_584403_s, tv_r_Filter_12_584403_e;
    gettimeofday(&tv_r_Filter_12_584403_s, 0);
    SW_Filter_TD_12258539(tbl_SerializeFromObject_TD_13519132_input, tbl_Filter_TD_12258539_output);
    gettimeofday(&tv_r_Filter_12_584403_e, 0);

    struct timeval tv_r_Filter_12_663656_s, tv_r_Filter_12_663656_e;
    gettimeofday(&tv_r_Filter_12_663656_s, 0);
    SW_Filter_TD_12385515(tbl_SerializeFromObject_TD_1336654_input, tbl_Filter_TD_12385515_output);
    gettimeofday(&tv_r_Filter_12_663656_e, 0);

    struct timeval tv_r_Filter_12_851228_s, tv_r_Filter_12_851228_e;
    gettimeofday(&tv_r_Filter_12_851228_s, 0);
    SW_Filter_TD_12846373(tbl_SerializeFromObject_TD_13541115_input, tbl_Filter_TD_12846373_output);
    gettimeofday(&tv_r_Filter_12_851228_e, 0);

    struct timeval tv_r_Filter_12_401690_s, tv_r_Filter_12_401690_e;
    gettimeofday(&tv_r_Filter_12_401690_s, 0);
    SW_Filter_TD_12684117(tbl_SerializeFromObject_TD_13787663_input, tbl_Filter_TD_12684117_output);
    gettimeofday(&tv_r_Filter_12_401690_e, 0);

    struct timeval tv_r_Filter_12_93569_s, tv_r_Filter_12_93569_e;
    gettimeofday(&tv_r_Filter_12_93569_s, 0);
    SW_Filter_TD_12737824(tbl_SerializeFromObject_TD_13406148_input, tbl_Filter_TD_12737824_output);
    gettimeofday(&tv_r_Filter_12_93569_e, 0);

    struct timeval tv_r_Filter_12_461747_s, tv_r_Filter_12_461747_e;
    gettimeofday(&tv_r_Filter_12_461747_s, 0);
    SW_Filter_TD_12213268(tbl_SerializeFromObject_TD_13474202_input, tbl_Filter_TD_12213268_output);
    gettimeofday(&tv_r_Filter_12_461747_e, 0);

    struct timeval tv_r_Filter_11_713017_s, tv_r_Filter_11_713017_e;
    gettimeofday(&tv_r_Filter_11_713017_s, 0);
    SW_Filter_TD_11839303(tbl_SerializeFromObject_TD_12523840_input, tbl_Filter_TD_11839303_output);
    gettimeofday(&tv_r_Filter_11_713017_e, 0);

    struct timeval tv_r_JOIN_LEFTOUTER_11_768282_s, tv_r_JOIN_LEFTOUTER_11_768282_e;
    gettimeofday(&tv_r_JOIN_LEFTOUTER_11_768282_s, 0);
    trans_JOIN_LEFTOUTER_TD_11893643.add(&(tbl_Filter_TD_12385515_output));
    trans_JOIN_LEFTOUTER_TD_11893643.add(&(tbl_Filter_TD_12258539_output));
    trans_JOIN_LEFTOUTER_TD_11893643.host2dev(0, &(prev_events_grp_JOIN_LEFTOUTER_TD_11893643), &(events_h2d_wr_JOIN_LEFTOUTER_TD_11893643[0]));
    events_grp_JOIN_LEFTOUTER_TD_11893643.push_back(events_h2d_wr_JOIN_LEFTOUTER_TD_11893643[0]);
    krnl_JOIN_LEFTOUTER_TD_11893643.run(0, &(events_grp_JOIN_LEFTOUTER_TD_11893643), &(events_JOIN_LEFTOUTER_TD_11893643[0]));
    gettimeofday(&tv_r_JOIN_LEFTOUTER_11_768282_e, 0);

    struct timeval tv_r_Filter_11_686942_s, tv_r_Filter_11_686942_e;
    gettimeofday(&tv_r_Filter_11_686942_s, 0);
    SW_Filter_TD_11592606(tbl_SerializeFromObject_TD_12852394_input, tbl_Filter_TD_11592606_output);
    gettimeofday(&tv_r_Filter_11_686942_e, 0);

    struct timeval tv_r_JOIN_LEFTOUTER_11_498568_s, tv_r_JOIN_LEFTOUTER_11_498568_e;
    gettimeofday(&tv_r_JOIN_LEFTOUTER_11_498568_s, 0);
    trans_JOIN_LEFTOUTER_TD_11822562.add(&(tbl_Filter_TD_12684117_output));
    trans_JOIN_LEFTOUTER_TD_11822562.add(&(tbl_Filter_TD_12846373_output));
    trans_JOIN_LEFTOUTER_TD_11822562.host2dev(0, &(prev_events_grp_JOIN_LEFTOUTER_TD_11822562), &(events_h2d_wr_JOIN_LEFTOUTER_TD_11822562[0]));
    events_grp_JOIN_LEFTOUTER_TD_11822562.push_back(events_h2d_wr_JOIN_LEFTOUTER_TD_11822562[0]);
    krnl_JOIN_LEFTOUTER_TD_11822562.run(0, &(events_grp_JOIN_LEFTOUTER_TD_11822562), &(events_JOIN_LEFTOUTER_TD_11822562[0]));
    gettimeofday(&tv_r_JOIN_LEFTOUTER_11_498568_e, 0);

    struct timeval tv_r_Filter_11_569207_s, tv_r_Filter_11_569207_e;
    gettimeofday(&tv_r_Filter_11_569207_s, 0);
    SW_Filter_TD_11838376(tbl_SerializeFromObject_TD_12875359_input, tbl_Filter_TD_11838376_output);
    gettimeofday(&tv_r_Filter_11_569207_e, 0);

    struct timeval tv_r_JOIN_LEFTOUTER_11_282726_s, tv_r_JOIN_LEFTOUTER_11_282726_e;
    gettimeofday(&tv_r_JOIN_LEFTOUTER_11_282726_s, 0);
    trans_JOIN_LEFTOUTER_TD_11633857.add(&(tbl_Filter_TD_12213268_output));
    trans_JOIN_LEFTOUTER_TD_11633857.add(&(tbl_Filter_TD_12737824_output));
    trans_JOIN_LEFTOUTER_TD_11633857.host2dev(0, &(prev_events_grp_JOIN_LEFTOUTER_TD_11633857), &(events_h2d_wr_JOIN_LEFTOUTER_TD_11633857[0]));
    events_grp_JOIN_LEFTOUTER_TD_11633857.push_back(events_h2d_wr_JOIN_LEFTOUTER_TD_11633857[0]);
    krnl_JOIN_LEFTOUTER_TD_11633857.run(0, &(events_grp_JOIN_LEFTOUTER_TD_11633857), &(events_JOIN_LEFTOUTER_TD_11633857[0]));
    gettimeofday(&tv_r_JOIN_LEFTOUTER_11_282726_e, 0);

    struct timeval tv_r_Filter_10_390137_s, tv_r_Filter_10_390137_e;
    gettimeofday(&tv_r_Filter_10_390137_s, 0);
    SW_Filter_TD_10449479(tbl_SerializeFromObject_TD_11102949_input, tbl_Filter_TD_10449479_output);
    gettimeofday(&tv_r_Filter_10_390137_e, 0);

    struct timeval tv_r_JOIN_INNER_10_916112_s, tv_r_JOIN_INNER_10_916112_e;
    gettimeofday(&tv_r_JOIN_INNER_10_916112_s, 0);
    prev_events_grp_JOIN_INNER_TD_10161275.push_back(events_h2d_wr_JOIN_LEFTOUTER_TD_11893643[0]);
    trans_JOIN_INNER_TD_10161275.add(&(tbl_Filter_TD_11839303_output));
    trans_JOIN_INNER_TD_10161275.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_10161275), &(events_h2d_wr_JOIN_INNER_TD_10161275[0]));
    events_grp_JOIN_INNER_TD_10161275.push_back(events_h2d_wr_JOIN_INNER_TD_10161275[0]);
    events_grp_JOIN_INNER_TD_10161275.push_back(events_JOIN_LEFTOUTER_TD_11893643[0]);
    krnl_JOIN_INNER_TD_10161275.run(0, &(events_grp_JOIN_INNER_TD_10161275), &(events_JOIN_INNER_TD_10161275[0]));
    
    trans_JOIN_INNER_TD_10161275_out.add(&(tbl_JOIN_INNER_TD_10161275_output));
    trans_JOIN_INNER_TD_10161275_out.dev2host(0, &(events_JOIN_INNER_TD_10161275), &(events_d2h_rd_JOIN_INNER_TD_10161275[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_10_916112_e, 0);

    struct timeval tv_r_Filter_10_300209_s, tv_r_Filter_10_300209_e;
    gettimeofday(&tv_r_Filter_10_300209_s, 0);
    SW_Filter_TD_10805972(tbl_SerializeFromObject_TD_11468781_input, tbl_Filter_TD_10805972_output);
    gettimeofday(&tv_r_Filter_10_300209_e, 0);

    struct timeval tv_r_JOIN_INNER_10_980862_s, tv_r_JOIN_INNER_10_980862_e;
    gettimeofday(&tv_r_JOIN_INNER_10_980862_s, 0);
    prev_events_grp_JOIN_INNER_TD_10664187.push_back(events_h2d_wr_JOIN_LEFTOUTER_TD_11822562[0]);
    trans_JOIN_INNER_TD_10664187.add(&(tbl_Filter_TD_11592606_output));
    trans_JOIN_INNER_TD_10664187.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_10664187), &(events_h2d_wr_JOIN_INNER_TD_10664187[0]));
    events_grp_JOIN_INNER_TD_10664187.push_back(events_h2d_wr_JOIN_INNER_TD_10664187[0]);
    events_grp_JOIN_INNER_TD_10664187.push_back(events_JOIN_LEFTOUTER_TD_11822562[0]);
    krnl_JOIN_INNER_TD_10664187.run(0, &(events_grp_JOIN_INNER_TD_10664187), &(events_JOIN_INNER_TD_10664187[0]));
    
    trans_JOIN_INNER_TD_10664187_out.add(&(tbl_JOIN_INNER_TD_10664187_output));
    trans_JOIN_INNER_TD_10664187_out.dev2host(0, &(events_JOIN_INNER_TD_10664187), &(events_d2h_rd_JOIN_INNER_TD_10664187[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_10_980862_e, 0);

    struct timeval tv_r_Filter_10_260436_s, tv_r_Filter_10_260436_e;
    gettimeofday(&tv_r_Filter_10_260436_s, 0);
    SW_Filter_TD_10841618(tbl_SerializeFromObject_TD_11546211_input, tbl_Filter_TD_10841618_output);
    gettimeofday(&tv_r_Filter_10_260436_e, 0);

    struct timeval tv_r_JOIN_INNER_10_760284_s, tv_r_JOIN_INNER_10_760284_e;
    gettimeofday(&tv_r_JOIN_INNER_10_760284_s, 0);
    prev_events_grp_JOIN_INNER_TD_10934769.push_back(events_h2d_wr_JOIN_LEFTOUTER_TD_11633857[0]);
    trans_JOIN_INNER_TD_10934769.add(&(tbl_Filter_TD_11838376_output));
    trans_JOIN_INNER_TD_10934769.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_10934769), &(events_h2d_wr_JOIN_INNER_TD_10934769[0]));
    events_grp_JOIN_INNER_TD_10934769.push_back(events_h2d_wr_JOIN_INNER_TD_10934769[0]);
    events_grp_JOIN_INNER_TD_10934769.push_back(events_JOIN_LEFTOUTER_TD_11633857[0]);
    krnl_JOIN_INNER_TD_10934769.run(0, &(events_grp_JOIN_INNER_TD_10934769), &(events_JOIN_INNER_TD_10934769[0]));
    
    trans_JOIN_INNER_TD_10934769_out.add(&(tbl_JOIN_INNER_TD_10934769_output));
    trans_JOIN_INNER_TD_10934769_out.dev2host(0, &(events_JOIN_INNER_TD_10934769), &(events_d2h_rd_JOIN_INNER_TD_10934769[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_10_760284_e, 0);

    struct timeval tv_r_Filter_9_317269_s, tv_r_Filter_9_317269_e;
    gettimeofday(&tv_r_Filter_9_317269_s, 0);
    SW_Filter_TD_9570177(tbl_SerializeFromObject_TD_10615885_input, tbl_Filter_TD_9570177_output);
    gettimeofday(&tv_r_Filter_9_317269_e, 0);

    struct timeval tv_r_JOIN_INNER_9_106133_s, tv_r_JOIN_INNER_9_106133_e;
    gettimeofday(&tv_r_JOIN_INNER_9_106133_s, 0);
    SW_JOIN_INNER_TD_9261141(tbl_JOIN_INNER_TD_10161275_output, tbl_Filter_TD_10449479_output, tbl_JOIN_INNER_TD_9261141_output);
    gettimeofday(&tv_r_JOIN_INNER_9_106133_e, 0);

    struct timeval tv_r_Filter_9_912144_s, tv_r_Filter_9_912144_e;
    gettimeofday(&tv_r_Filter_9_912144_s, 0);
    SW_Filter_TD_949741(tbl_SerializeFromObject_TD_10840973_input, tbl_Filter_TD_949741_output);
    gettimeofday(&tv_r_Filter_9_912144_e, 0);

    struct timeval tv_r_JOIN_INNER_9_658311_s, tv_r_JOIN_INNER_9_658311_e;
    gettimeofday(&tv_r_JOIN_INNER_9_658311_s, 0);
    SW_JOIN_INNER_TD_9809851(tbl_JOIN_INNER_TD_10664187_output, tbl_Filter_TD_10805972_output, tbl_JOIN_INNER_TD_9809851_output);
    gettimeofday(&tv_r_JOIN_INNER_9_658311_e, 0);

    struct timeval tv_r_Filter_9_479905_s, tv_r_Filter_9_479905_e;
    gettimeofday(&tv_r_Filter_9_479905_s, 0);
    SW_Filter_TD_9190310(tbl_SerializeFromObject_TD_10717886_input, tbl_Filter_TD_9190310_output);
    gettimeofday(&tv_r_Filter_9_479905_e, 0);

    struct timeval tv_r_JOIN_INNER_9_417028_s, tv_r_JOIN_INNER_9_417028_e;
    gettimeofday(&tv_r_JOIN_INNER_9_417028_s, 0);
    SW_JOIN_INNER_TD_9447563(tbl_JOIN_INNER_TD_10934769_output, tbl_Filter_TD_10841618_output, tbl_JOIN_INNER_TD_9447563_output);
    gettimeofday(&tv_r_JOIN_INNER_9_417028_e, 0);

    struct timeval tv_r_Filter_8_901943_s, tv_r_Filter_8_901943_e;
    gettimeofday(&tv_r_Filter_8_901943_s, 0);
    SW_Filter_TD_8992697(tbl_SerializeFromObject_TD_9748703_input, tbl_Filter_TD_8992697_output);
    gettimeofday(&tv_r_Filter_8_901943_e, 0);

    struct timeval tv_r_JOIN_INNER_8_315512_s, tv_r_JOIN_INNER_8_315512_e;
    gettimeofday(&tv_r_JOIN_INNER_8_315512_s, 0);
    SW_JOIN_INNER_TD_8859329(tbl_JOIN_INNER_TD_9261141_output, tbl_Filter_TD_9570177_output, tbl_JOIN_INNER_TD_8859329_output);
    gettimeofday(&tv_r_JOIN_INNER_8_315512_e, 0);

    struct timeval tv_r_Filter_8_850238_s, tv_r_Filter_8_850238_e;
    gettimeofday(&tv_r_Filter_8_850238_s, 0);
    SW_Filter_TD_8291775(tbl_SerializeFromObject_TD_917945_input, tbl_Filter_TD_8291775_output);
    gettimeofday(&tv_r_Filter_8_850238_e, 0);

    struct timeval tv_r_JOIN_INNER_8_317537_s, tv_r_JOIN_INNER_8_317537_e;
    gettimeofday(&tv_r_JOIN_INNER_8_317537_s, 0);
    SW_JOIN_INNER_TD_8531564(tbl_JOIN_INNER_TD_9809851_output, tbl_Filter_TD_949741_output, tbl_JOIN_INNER_TD_8531564_output);
    gettimeofday(&tv_r_JOIN_INNER_8_317537_e, 0);

    struct timeval tv_r_Filter_8_495718_s, tv_r_Filter_8_495718_e;
    gettimeofday(&tv_r_Filter_8_495718_s, 0);
    SW_Filter_TD_822743(tbl_SerializeFromObject_TD_9730161_input, tbl_Filter_TD_822743_output);
    gettimeofday(&tv_r_Filter_8_495718_e, 0);

    struct timeval tv_r_JOIN_INNER_8_447556_s, tv_r_JOIN_INNER_8_447556_e;
    gettimeofday(&tv_r_JOIN_INNER_8_447556_s, 0);
    SW_JOIN_INNER_TD_8230445(tbl_JOIN_INNER_TD_9447563_output, tbl_Filter_TD_9190310_output, tbl_JOIN_INNER_TD_8230445_output);
    gettimeofday(&tv_r_JOIN_INNER_8_447556_e, 0);

    struct timeval tv_r_JOIN_INNER_7_112629_s, tv_r_JOIN_INNER_7_112629_e;
    gettimeofday(&tv_r_JOIN_INNER_7_112629_s, 0);
    SW_JOIN_INNER_TD_7114427(tbl_JOIN_INNER_TD_8859329_output, tbl_Filter_TD_8992697_output, tbl_JOIN_INNER_TD_7114427_output);
    gettimeofday(&tv_r_JOIN_INNER_7_112629_e, 0);

    struct timeval tv_r_JOIN_INNER_7_425643_s, tv_r_JOIN_INNER_7_425643_e;
    gettimeofday(&tv_r_JOIN_INNER_7_425643_s, 0);
    SW_JOIN_INNER_TD_7282618(tbl_JOIN_INNER_TD_8531564_output, tbl_Filter_TD_8291775_output, tbl_JOIN_INNER_TD_7282618_output);
    gettimeofday(&tv_r_JOIN_INNER_7_425643_e, 0);

    struct timeval tv_r_JOIN_INNER_7_381525_s, tv_r_JOIN_INNER_7_381525_e;
    gettimeofday(&tv_r_JOIN_INNER_7_381525_s, 0);
    SW_JOIN_INNER_TD_7353460(tbl_JOIN_INNER_TD_8230445_output, tbl_Filter_TD_822743_output, tbl_JOIN_INNER_TD_7353460_output);
    gettimeofday(&tv_r_JOIN_INNER_7_381525_e, 0);

    struct timeval tv_r_Aggregate_6_193072_s, tv_r_Aggregate_6_193072_e;
    gettimeofday(&tv_r_Aggregate_6_193072_s, 0);
    SW_Aggregate_TD_6790829(tbl_JOIN_INNER_TD_7114427_output, tbl_Aggregate_TD_6790829_output);
    gettimeofday(&tv_r_Aggregate_6_193072_e, 0);

    struct timeval tv_r_Aggregate_6_44434_s, tv_r_Aggregate_6_44434_e;
    gettimeofday(&tv_r_Aggregate_6_44434_s, 0);
    SW_Aggregate_TD_6631003(tbl_JOIN_INNER_TD_7282618_output, tbl_Aggregate_TD_6631003_output);
    gettimeofday(&tv_r_Aggregate_6_44434_e, 0);

    struct timeval tv_r_Aggregate_6_180252_s, tv_r_Aggregate_6_180252_e;
    gettimeofday(&tv_r_Aggregate_6_180252_s, 0);
    SW_Aggregate_TD_6197270(tbl_JOIN_INNER_TD_7353460_output, tbl_Aggregate_TD_6197270_output);
    gettimeofday(&tv_r_Aggregate_6_180252_e, 0);

    struct timeval tv_r_Union_5_107781_s, tv_r_Union_5_107781_e;
    gettimeofday(&tv_r_Union_5_107781_s, 0);
    SW_Union_TD_535352(tbl_Aggregate_TD_6197270_output, tbl_Aggregate_TD_6631003_output, tbl_Aggregate_TD_6790829_output, tbl_Union_TD_535352_output);
    gettimeofday(&tv_r_Union_5_107781_e, 0);

    struct timeval tv_r_Expand_4_662356_s, tv_r_Expand_4_662356_e;
    gettimeofday(&tv_r_Expand_4_662356_s, 0);
    SW_Expand_TD_4666629(tbl_Union_TD_535352_output, tbl_Expand_TD_4666629_output);
    gettimeofday(&tv_r_Expand_4_662356_e, 0);

    struct timeval tv_r_Aggregate_3_584276_s, tv_r_Aggregate_3_584276_e;
    gettimeofday(&tv_r_Aggregate_3_584276_s, 0);
    SW_Aggregate_TD_3486002(tbl_Expand_TD_4666629_output, tbl_Aggregate_TD_3486002_output);
    gettimeofday(&tv_r_Aggregate_3_584276_e, 0);

    struct timeval tv_r_Sort_2_310945_s, tv_r_Sort_2_310945_e;
    gettimeofday(&tv_r_Sort_2_310945_s, 0);
    SW_Sort_TD_2745446(tbl_Aggregate_TD_3486002_output, tbl_Sort_TD_2745446_output);
    gettimeofday(&tv_r_Sort_2_310945_e, 0);

    struct timeval tv_r_LocalLimit_1_95877_s, tv_r_LocalLimit_1_95877_e;
    gettimeofday(&tv_r_LocalLimit_1_95877_s, 0);
    SW_LocalLimit_TD_1122885(tbl_Sort_TD_2745446_output, tbl_LocalLimit_TD_1122885_output);
    gettimeofday(&tv_r_LocalLimit_1_95877_e, 0);

    struct timeval tv_r_GlobalLimit_0_523994_s, tv_r_GlobalLimit_0_523994_e;
    gettimeofday(&tv_r_GlobalLimit_0_523994_s, 0);
    SW_GlobalLimit_TD_0481036(tbl_LocalLimit_TD_1122885_output, tbl_GlobalLimit_TD_0481036_output);
    gettimeofday(&tv_r_GlobalLimit_0_523994_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_584403_s, &tv_r_Filter_12_584403_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13519132_input: " << tbl_SerializeFromObject_TD_13519132_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_663656_s, &tv_r_Filter_12_663656_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1336654_input: " << tbl_SerializeFromObject_TD_1336654_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_851228_s, &tv_r_Filter_12_851228_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13541115_input: " << tbl_SerializeFromObject_TD_13541115_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_401690_s, &tv_r_Filter_12_401690_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13787663_input: " << tbl_SerializeFromObject_TD_13787663_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_93569_s, &tv_r_Filter_12_93569_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13406148_input: " << tbl_SerializeFromObject_TD_13406148_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_461747_s, &tv_r_Filter_12_461747_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13474202_input: " << tbl_SerializeFromObject_TD_13474202_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_713017_s, &tv_r_Filter_11_713017_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12523840_input: " << tbl_SerializeFromObject_TD_12523840_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTOUTER_11: " << tvdiff(&tv_r_JOIN_LEFTOUTER_11_768282_s, &tv_r_JOIN_LEFTOUTER_11_768282_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_12385515_output: " << tbl_Filter_TD_12385515_output.getNumRow() << " " << "tbl_Filter_TD_12258539_output: " << tbl_Filter_TD_12258539_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_686942_s, &tv_r_Filter_11_686942_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12852394_input: " << tbl_SerializeFromObject_TD_12852394_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTOUTER_11: " << tvdiff(&tv_r_JOIN_LEFTOUTER_11_498568_s, &tv_r_JOIN_LEFTOUTER_11_498568_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_12684117_output: " << tbl_Filter_TD_12684117_output.getNumRow() << " " << "tbl_Filter_TD_12846373_output: " << tbl_Filter_TD_12846373_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_569207_s, &tv_r_Filter_11_569207_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12875359_input: " << tbl_SerializeFromObject_TD_12875359_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTOUTER_11: " << tvdiff(&tv_r_JOIN_LEFTOUTER_11_282726_s, &tv_r_JOIN_LEFTOUTER_11_282726_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_12213268_output: " << tbl_Filter_TD_12213268_output.getNumRow() << " " << "tbl_Filter_TD_12737824_output: " << tbl_Filter_TD_12737824_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_390137_s, &tv_r_Filter_10_390137_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11102949_input: " << tbl_SerializeFromObject_TD_11102949_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_916112_s, &tv_r_JOIN_INNER_10_916112_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTOUTER_TD_11893643_output: " << tbl_JOIN_LEFTOUTER_TD_11893643_output.getNumRow() << " " << "tbl_Filter_TD_11839303_output: " << tbl_Filter_TD_11839303_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_300209_s, &tv_r_Filter_10_300209_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11468781_input: " << tbl_SerializeFromObject_TD_11468781_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_980862_s, &tv_r_JOIN_INNER_10_980862_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTOUTER_TD_11822562_output: " << tbl_JOIN_LEFTOUTER_TD_11822562_output.getNumRow() << " " << "tbl_Filter_TD_11592606_output: " << tbl_Filter_TD_11592606_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_260436_s, &tv_r_Filter_10_260436_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11546211_input: " << tbl_SerializeFromObject_TD_11546211_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_760284_s, &tv_r_JOIN_INNER_10_760284_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTOUTER_TD_11633857_output: " << tbl_JOIN_LEFTOUTER_TD_11633857_output.getNumRow() << " " << "tbl_Filter_TD_11838376_output: " << tbl_Filter_TD_11838376_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_317269_s, &tv_r_Filter_9_317269_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10615885_input: " << tbl_SerializeFromObject_TD_10615885_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_106133_s, &tv_r_JOIN_INNER_9_106133_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10161275_output: " << tbl_JOIN_INNER_TD_10161275_output.getNumRow() << " " << "tbl_Filter_TD_10449479_output: " << tbl_Filter_TD_10449479_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_912144_s, &tv_r_Filter_9_912144_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10840973_input: " << tbl_SerializeFromObject_TD_10840973_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_658311_s, &tv_r_JOIN_INNER_9_658311_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10664187_output: " << tbl_JOIN_INNER_TD_10664187_output.getNumRow() << " " << "tbl_Filter_TD_10805972_output: " << tbl_Filter_TD_10805972_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_479905_s, &tv_r_Filter_9_479905_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10717886_input: " << tbl_SerializeFromObject_TD_10717886_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_417028_s, &tv_r_JOIN_INNER_9_417028_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10934769_output: " << tbl_JOIN_INNER_TD_10934769_output.getNumRow() << " " << "tbl_Filter_TD_10841618_output: " << tbl_Filter_TD_10841618_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_901943_s, &tv_r_Filter_8_901943_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9748703_input: " << tbl_SerializeFromObject_TD_9748703_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_315512_s, &tv_r_JOIN_INNER_8_315512_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9261141_output: " << tbl_JOIN_INNER_TD_9261141_output.getNumRow() << " " << "tbl_Filter_TD_9570177_output: " << tbl_Filter_TD_9570177_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_850238_s, &tv_r_Filter_8_850238_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_917945_input: " << tbl_SerializeFromObject_TD_917945_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_317537_s, &tv_r_JOIN_INNER_8_317537_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9809851_output: " << tbl_JOIN_INNER_TD_9809851_output.getNumRow() << " " << "tbl_Filter_TD_949741_output: " << tbl_Filter_TD_949741_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_495718_s, &tv_r_Filter_8_495718_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9730161_input: " << tbl_SerializeFromObject_TD_9730161_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_447556_s, &tv_r_JOIN_INNER_8_447556_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9447563_output: " << tbl_JOIN_INNER_TD_9447563_output.getNumRow() << " " << "tbl_Filter_TD_9190310_output: " << tbl_Filter_TD_9190310_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_112629_s, &tv_r_JOIN_INNER_7_112629_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8859329_output: " << tbl_JOIN_INNER_TD_8859329_output.getNumRow() << " " << "tbl_Filter_TD_8992697_output: " << tbl_Filter_TD_8992697_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_425643_s, &tv_r_JOIN_INNER_7_425643_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8531564_output: " << tbl_JOIN_INNER_TD_8531564_output.getNumRow() << " " << "tbl_Filter_TD_8291775_output: " << tbl_Filter_TD_8291775_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_381525_s, &tv_r_JOIN_INNER_7_381525_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8230445_output: " << tbl_JOIN_INNER_TD_8230445_output.getNumRow() << " " << "tbl_Filter_TD_822743_output: " << tbl_Filter_TD_822743_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_6: " << tvdiff(&tv_r_Aggregate_6_193072_s, &tv_r_Aggregate_6_193072_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7114427_output: " << tbl_JOIN_INNER_TD_7114427_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_6: " << tvdiff(&tv_r_Aggregate_6_44434_s, &tv_r_Aggregate_6_44434_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7282618_output: " << tbl_JOIN_INNER_TD_7282618_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_6: " << tvdiff(&tv_r_Aggregate_6_180252_s, &tv_r_Aggregate_6_180252_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7353460_output: " << tbl_JOIN_INNER_TD_7353460_output.getNumRow() << " " << std::endl; 

    std::cout << "Union_5: " << tvdiff(&tv_r_Union_5_107781_s, &tv_r_Union_5_107781_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_6197270_output: " << tbl_Aggregate_TD_6197270_output.getNumRow() << " " << "tbl_Aggregate_TD_6631003_output: " << tbl_Aggregate_TD_6631003_output.getNumRow() << " " << "tbl_Aggregate_TD_6790829_output: " << tbl_Aggregate_TD_6790829_output.getNumRow() << " " << std::endl; 

    std::cout << "Expand_4: " << tvdiff(&tv_r_Expand_4_662356_s, &tv_r_Expand_4_662356_e) / 1000.0 << " ms " 
     << "tbl_Union_TD_535352_output: " << tbl_Union_TD_535352_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_584276_s, &tv_r_Aggregate_3_584276_e) / 1000.0 << " ms " 
     << "tbl_Expand_TD_4666629_output: " << tbl_Expand_TD_4666629_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_310945_s, &tv_r_Sort_2_310945_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3486002_output: " << tbl_Aggregate_TD_3486002_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_95877_s, &tv_r_LocalLimit_1_95877_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2745446_output: " << tbl_Sort_TD_2745446_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_523994_s, &tv_r_GlobalLimit_0_523994_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1122885_output: " << tbl_LocalLimit_TD_1122885_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 3.3610153 * 1000 << "ms" << std::endl; 
    return 0; 
}
