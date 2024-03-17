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

#include "cfgFunc_q56.hpp" 
#include "q56.hpp" 

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
    std::cout << "NOTE:running query #56\n."; 
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
    Table tbl_GlobalLimit_TD_067268_output("tbl_GlobalLimit_TD_067268_output", 6100000, 2, "");
    tbl_GlobalLimit_TD_067268_output.allocateHost();
    Table tbl_LocalLimit_TD_1545917_output("tbl_LocalLimit_TD_1545917_output", 6100000, 2, "");
    tbl_LocalLimit_TD_1545917_output.allocateHost();
    Table tbl_Sort_TD_2121567_output("tbl_Sort_TD_2121567_output", 6100000, 2, "");
    tbl_Sort_TD_2121567_output.allocateHost();
    Table tbl_Aggregate_TD_3682917_output("tbl_Aggregate_TD_3682917_output", 6100000, 2, "");
    tbl_Aggregate_TD_3682917_output.allocateHost();
    Table tbl_Union_TD_4424619_output("tbl_Union_TD_4424619_output", 6100000, 2, "");
    tbl_Union_TD_4424619_output.allocateHost();
    Table tbl_Aggregate_TD_5675265_output("tbl_Aggregate_TD_5675265_output", 6100000, 2, "");
    tbl_Aggregate_TD_5675265_output.allocateHost();
    Table tbl_Aggregate_TD_5454060_output("tbl_Aggregate_TD_5454060_output", 6100000, 2, "");
    tbl_Aggregate_TD_5454060_output.allocateHost();
    Table tbl_Aggregate_TD_5415964_output("tbl_Aggregate_TD_5415964_output", 6100000, 2, "");
    tbl_Aggregate_TD_5415964_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6645053_output("tbl_JOIN_INNER_TD_6645053_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_6645053_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6679733_output("tbl_JOIN_INNER_TD_6679733_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_6679733_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6530078_output("tbl_JOIN_INNER_TD_6530078_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_6530078_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7486229_output("tbl_JOIN_INNER_TD_7486229_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_7486229_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_7421637_output("tbl_JOIN_LEFTSEMI_TD_7421637_output", 6100000, 2, "");
    tbl_JOIN_LEFTSEMI_TD_7421637_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7450298_output("tbl_JOIN_INNER_TD_7450298_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_7450298_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_7580410_output("tbl_JOIN_LEFTSEMI_TD_7580410_output", 6100000, 2, "");
    tbl_JOIN_LEFTSEMI_TD_7580410_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7169986_output("tbl_JOIN_INNER_TD_7169986_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_7169986_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_7180037_output("tbl_JOIN_LEFTSEMI_TD_7180037_output", 6100000, 2, "");
    tbl_JOIN_LEFTSEMI_TD_7180037_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8344086_output("tbl_JOIN_INNER_TD_8344086_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_8344086_output.allocateHost();
    Table tbl_Filter_TD_8991702_output("tbl_Filter_TD_8991702_output", 6100000, 1, "");
    tbl_Filter_TD_8991702_output.allocateHost();
    Table tbl_Filter_TD_8169404_output("tbl_Filter_TD_8169404_output", 6100000, 2, "");
    tbl_Filter_TD_8169404_output.allocateHost();
    Table tbl_Filter_TD_8271261_output("tbl_Filter_TD_8271261_output", 6100000, 1, "");
    tbl_Filter_TD_8271261_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8636067_output("tbl_JOIN_INNER_TD_8636067_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_8636067_output.allocateHost();
    Table tbl_Filter_TD_8588043_output("tbl_Filter_TD_8588043_output", 6100000, 1, "");
    tbl_Filter_TD_8588043_output.allocateHost();
    Table tbl_Filter_TD_8969594_output("tbl_Filter_TD_8969594_output", 6100000, 2, "");
    tbl_Filter_TD_8969594_output.allocateHost();
    Table tbl_Filter_TD_8210260_output("tbl_Filter_TD_8210260_output", 6100000, 1, "");
    tbl_Filter_TD_8210260_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8413016_output("tbl_JOIN_INNER_TD_8413016_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_8413016_output.allocateHost();
    Table tbl_Filter_TD_8468755_output("tbl_Filter_TD_8468755_output", 6100000, 1, "");
    tbl_Filter_TD_8468755_output.allocateHost();
    Table tbl_Filter_TD_830576_output("tbl_Filter_TD_830576_output", 6100000, 2, "");
    tbl_Filter_TD_830576_output.allocateHost();
    Table tbl_Filter_TD_8664082_output("tbl_Filter_TD_8664082_output", 6100000, 1, "");
    tbl_Filter_TD_8664082_output.allocateHost();
    Table tbl_Filter_TD_956963_output("tbl_Filter_TD_956963_output", 6100000, 4, "");
    tbl_Filter_TD_956963_output.allocateHost();
    Table tbl_Filter_TD_9256316_output("tbl_Filter_TD_9256316_output", 6100000, 1, "");
    tbl_Filter_TD_9256316_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9593503_input;
    tbl_SerializeFromObject_TD_9593503_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9593503_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_9593503_input.addCol("ca_gmt_offset", 4);
    tbl_SerializeFromObject_TD_9593503_input.allocateHost();
    tbl_SerializeFromObject_TD_9593503_input.loadHost();
    Table tbl_SerializeFromObject_TD_9565321_input;
    tbl_SerializeFromObject_TD_9565321_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9565321_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_9565321_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9565321_input.allocateHost();
    tbl_SerializeFromObject_TD_9565321_input.loadHost();
    Table tbl_SerializeFromObject_TD_9229579_input;
    tbl_SerializeFromObject_TD_9229579_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9229579_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9229579_input.addCol("i_color", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9229579_input.allocateHost();
    tbl_SerializeFromObject_TD_9229579_input.loadHost();
    Table tbl_Filter_TD_912636_output("tbl_Filter_TD_912636_output", 6100000, 4, "");
    tbl_Filter_TD_912636_output.allocateHost();
    Table tbl_Filter_TD_9489580_output("tbl_Filter_TD_9489580_output", 6100000, 1, "");
    tbl_Filter_TD_9489580_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9114440_input;
    tbl_SerializeFromObject_TD_9114440_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9114440_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_9114440_input.addCol("ca_gmt_offset", 4);
    tbl_SerializeFromObject_TD_9114440_input.allocateHost();
    tbl_SerializeFromObject_TD_9114440_input.loadHost();
    Table tbl_SerializeFromObject_TD_9471458_input;
    tbl_SerializeFromObject_TD_9471458_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9471458_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_9471458_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9471458_input.allocateHost();
    tbl_SerializeFromObject_TD_9471458_input.loadHost();
    Table tbl_SerializeFromObject_TD_9744059_input;
    tbl_SerializeFromObject_TD_9744059_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9744059_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9744059_input.addCol("i_color", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9744059_input.allocateHost();
    tbl_SerializeFromObject_TD_9744059_input.loadHost();
    Table tbl_Filter_TD_9517811_output("tbl_Filter_TD_9517811_output", 6100000, 4, "");
    tbl_Filter_TD_9517811_output.allocateHost();
    Table tbl_Filter_TD_9906071_output("tbl_Filter_TD_9906071_output", 6100000, 1, "");
    tbl_Filter_TD_9906071_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9552791_input;
    tbl_SerializeFromObject_TD_9552791_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9552791_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_9552791_input.addCol("ca_gmt_offset", 4);
    tbl_SerializeFromObject_TD_9552791_input.allocateHost();
    tbl_SerializeFromObject_TD_9552791_input.loadHost();
    Table tbl_SerializeFromObject_TD_9822938_input;
    tbl_SerializeFromObject_TD_9822938_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9822938_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_9822938_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9822938_input.allocateHost();
    tbl_SerializeFromObject_TD_9822938_input.loadHost();
    Table tbl_SerializeFromObject_TD_968716_input;
    tbl_SerializeFromObject_TD_968716_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_968716_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_968716_input.addCol("i_color", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_968716_input.allocateHost();
    tbl_SerializeFromObject_TD_968716_input.loadHost();
    Table tbl_SerializeFromObject_TD_10603067_input;
    tbl_SerializeFromObject_TD_10603067_input = Table("store_sales", store_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_10603067_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10603067_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_10603067_input.addCol("ss_addr_sk", 4);
    tbl_SerializeFromObject_TD_10603067_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_10603067_input.allocateHost();
    tbl_SerializeFromObject_TD_10603067_input.loadHost();
    Table tbl_SerializeFromObject_TD_10953264_input;
    tbl_SerializeFromObject_TD_10953264_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10953264_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10953264_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10953264_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_10953264_input.allocateHost();
    tbl_SerializeFromObject_TD_10953264_input.loadHost();
    Table tbl_SerializeFromObject_TD_10346483_input;
    tbl_SerializeFromObject_TD_10346483_input = Table("catalog_sales", catalog_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_10346483_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10346483_input.addCol("cs_bill_addr_sk", 4);
    tbl_SerializeFromObject_TD_10346483_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_10346483_input.addCol("cs_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_10346483_input.allocateHost();
    tbl_SerializeFromObject_TD_10346483_input.loadHost();
    Table tbl_SerializeFromObject_TD_10959226_input;
    tbl_SerializeFromObject_TD_10959226_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10959226_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10959226_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10959226_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_10959226_input.allocateHost();
    tbl_SerializeFromObject_TD_10959226_input.loadHost();
    Table tbl_SerializeFromObject_TD_10129579_input;
    tbl_SerializeFromObject_TD_10129579_input = Table("web_sales", web_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_10129579_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10129579_input.addCol("ws_item_sk", 4);
    tbl_SerializeFromObject_TD_10129579_input.addCol("ws_bill_addr_sk", 4);
    tbl_SerializeFromObject_TD_10129579_input.addCol("ws_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_10129579_input.allocateHost();
    tbl_SerializeFromObject_TD_10129579_input.loadHost();
    Table tbl_SerializeFromObject_TD_10886347_input;
    tbl_SerializeFromObject_TD_10886347_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10886347_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10886347_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10886347_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_10886347_input.allocateHost();
    tbl_SerializeFromObject_TD_10886347_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_7486229_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_7450298_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_7169986_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8344086_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8991702_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8636067_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8588043_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8413016_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8468755_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_956963_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9256316_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_912636_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9489580_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9517811_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9906071_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_7486229_cmds;
    cfg_JOIN_INNER_TD_7486229_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7486229_gqe_join (cfg_JOIN_INNER_TD_7486229_cmds.cmd);
    cfg_JOIN_INNER_TD_7486229_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7450298_cmds;
    cfg_JOIN_INNER_TD_7450298_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7450298_gqe_join (cfg_JOIN_INNER_TD_7450298_cmds.cmd);
    cfg_JOIN_INNER_TD_7450298_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7169986_cmds;
    cfg_JOIN_INNER_TD_7169986_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7169986_gqe_join (cfg_JOIN_INNER_TD_7169986_cmds.cmd);
    cfg_JOIN_INNER_TD_7169986_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8344086_cmds;
    cfg_JOIN_INNER_TD_8344086_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8344086_gqe_join (cfg_JOIN_INNER_TD_8344086_cmds.cmd);
    cfg_JOIN_INNER_TD_8344086_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8636067_cmds;
    cfg_JOIN_INNER_TD_8636067_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8636067_gqe_join (cfg_JOIN_INNER_TD_8636067_cmds.cmd);
    cfg_JOIN_INNER_TD_8636067_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8413016_cmds;
    cfg_JOIN_INNER_TD_8413016_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8413016_gqe_join (cfg_JOIN_INNER_TD_8413016_cmds.cmd);
    cfg_JOIN_INNER_TD_8413016_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_7486229;
    krnl_JOIN_INNER_TD_7486229 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7486229.setup(tbl_JOIN_INNER_TD_8344086_output, tbl_Filter_TD_8991702_output, tbl_JOIN_INNER_TD_7486229_output, cfg_JOIN_INNER_TD_7486229_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_7450298;
    krnl_JOIN_INNER_TD_7450298 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7450298.setup(tbl_JOIN_INNER_TD_8636067_output, tbl_Filter_TD_8588043_output, tbl_JOIN_INNER_TD_7450298_output, cfg_JOIN_INNER_TD_7450298_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_7169986;
    krnl_JOIN_INNER_TD_7169986 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7169986.setup(tbl_JOIN_INNER_TD_8413016_output, tbl_Filter_TD_8468755_output, tbl_JOIN_INNER_TD_7169986_output, cfg_JOIN_INNER_TD_7169986_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_8344086;
    krnl_JOIN_INNER_TD_8344086 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8344086.setup(tbl_Filter_TD_956963_output, tbl_Filter_TD_9256316_output, tbl_JOIN_INNER_TD_8344086_output, cfg_JOIN_INNER_TD_8344086_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_8636067;
    krnl_JOIN_INNER_TD_8636067 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8636067.setup(tbl_Filter_TD_912636_output, tbl_Filter_TD_9489580_output, tbl_JOIN_INNER_TD_8636067_output, cfg_JOIN_INNER_TD_8636067_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_8413016;
    krnl_JOIN_INNER_TD_8413016 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8413016.setup(tbl_Filter_TD_9517811_output, tbl_Filter_TD_9906071_output, tbl_JOIN_INNER_TD_8413016_output, cfg_JOIN_INNER_TD_8413016_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_7486229;
    trans_JOIN_INNER_TD_7486229.setq(q_h);
    trans_JOIN_INNER_TD_7486229.add(&(cfg_JOIN_INNER_TD_7486229_cmds));
    transEngine trans_JOIN_INNER_TD_7486229_out;
    trans_JOIN_INNER_TD_7486229_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_7450298;
    trans_JOIN_INNER_TD_7450298.setq(q_h);
    trans_JOIN_INNER_TD_7450298.add(&(cfg_JOIN_INNER_TD_7450298_cmds));
    transEngine trans_JOIN_INNER_TD_7450298_out;
    trans_JOIN_INNER_TD_7450298_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_7169986;
    trans_JOIN_INNER_TD_7169986.setq(q_h);
    trans_JOIN_INNER_TD_7169986.add(&(cfg_JOIN_INNER_TD_7169986_cmds));
    transEngine trans_JOIN_INNER_TD_7169986_out;
    trans_JOIN_INNER_TD_7169986_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_8344086;
    trans_JOIN_INNER_TD_8344086.setq(q_h);
    trans_JOIN_INNER_TD_8344086.add(&(cfg_JOIN_INNER_TD_8344086_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_8636067;
    trans_JOIN_INNER_TD_8636067.setq(q_h);
    trans_JOIN_INNER_TD_8636067.add(&(cfg_JOIN_INNER_TD_8636067_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_8413016;
    trans_JOIN_INNER_TD_8413016.setq(q_h);
    trans_JOIN_INNER_TD_8413016.add(&(cfg_JOIN_INNER_TD_8413016_cmds));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7486229;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7486229;
    std::vector<cl::Event> events_JOIN_INNER_TD_7486229;
    events_h2d_wr_JOIN_INNER_TD_7486229.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7486229.resize(1);
    events_JOIN_INNER_TD_7486229.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7486229;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7486229;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7450298;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7450298;
    std::vector<cl::Event> events_JOIN_INNER_TD_7450298;
    events_h2d_wr_JOIN_INNER_TD_7450298.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7450298.resize(1);
    events_JOIN_INNER_TD_7450298.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7450298;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7450298;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7169986;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7169986;
    std::vector<cl::Event> events_JOIN_INNER_TD_7169986;
    events_h2d_wr_JOIN_INNER_TD_7169986.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7169986.resize(1);
    events_JOIN_INNER_TD_7169986.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7169986;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7169986;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8344086;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8344086;
    std::vector<cl::Event> events_JOIN_INNER_TD_8344086;
    events_h2d_wr_JOIN_INNER_TD_8344086.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8344086.resize(1);
    events_JOIN_INNER_TD_8344086.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8344086;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8344086;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8636067;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8636067;
    std::vector<cl::Event> events_JOIN_INNER_TD_8636067;
    events_h2d_wr_JOIN_INNER_TD_8636067.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8636067.resize(1);
    events_JOIN_INNER_TD_8636067.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8636067;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8636067;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8413016;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8413016;
    std::vector<cl::Event> events_JOIN_INNER_TD_8413016;
    events_h2d_wr_JOIN_INNER_TD_8413016.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8413016.resize(1);
    events_JOIN_INNER_TD_8413016.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8413016;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8413016;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_9_366098_s, tv_r_Filter_9_366098_e;
    gettimeofday(&tv_r_Filter_9_366098_s, 0);
    SW_Filter_TD_9906071(tbl_SerializeFromObject_TD_10886347_input, tbl_Filter_TD_9906071_output);
    gettimeofday(&tv_r_Filter_9_366098_e, 0);

    struct timeval tv_r_Filter_9_916594_s, tv_r_Filter_9_916594_e;
    gettimeofday(&tv_r_Filter_9_916594_s, 0);
    SW_Filter_TD_9517811(tbl_SerializeFromObject_TD_10129579_input, tbl_Filter_TD_9517811_output);
    gettimeofday(&tv_r_Filter_9_916594_e, 0);

    struct timeval tv_r_Filter_9_220056_s, tv_r_Filter_9_220056_e;
    gettimeofday(&tv_r_Filter_9_220056_s, 0);
    SW_Filter_TD_9489580(tbl_SerializeFromObject_TD_10959226_input, tbl_Filter_TD_9489580_output);
    gettimeofday(&tv_r_Filter_9_220056_e, 0);

    struct timeval tv_r_Filter_9_471179_s, tv_r_Filter_9_471179_e;
    gettimeofday(&tv_r_Filter_9_471179_s, 0);
    SW_Filter_TD_912636(tbl_SerializeFromObject_TD_10346483_input, tbl_Filter_TD_912636_output);
    gettimeofday(&tv_r_Filter_9_471179_e, 0);

    struct timeval tv_r_Filter_9_192845_s, tv_r_Filter_9_192845_e;
    gettimeofday(&tv_r_Filter_9_192845_s, 0);
    SW_Filter_TD_9256316(tbl_SerializeFromObject_TD_10953264_input, tbl_Filter_TD_9256316_output);
    gettimeofday(&tv_r_Filter_9_192845_e, 0);

    struct timeval tv_r_Filter_9_734955_s, tv_r_Filter_9_734955_e;
    gettimeofday(&tv_r_Filter_9_734955_s, 0);
    SW_Filter_TD_956963(tbl_SerializeFromObject_TD_10603067_input, tbl_Filter_TD_956963_output);
    gettimeofday(&tv_r_Filter_9_734955_e, 0);

    struct timeval tv_r_Filter_8_481578_s, tv_r_Filter_8_481578_e;
    gettimeofday(&tv_r_Filter_8_481578_s, 0);
    SW_Filter_TD_8664082(tbl_SerializeFromObject_TD_968716_input, tbl_Filter_TD_8664082_output);
    gettimeofday(&tv_r_Filter_8_481578_e, 0);

    struct timeval tv_r_Filter_8_933050_s, tv_r_Filter_8_933050_e;
    gettimeofday(&tv_r_Filter_8_933050_s, 0);
    SW_Filter_TD_830576(tbl_SerializeFromObject_TD_9822938_input, tbl_Filter_TD_830576_output);
    gettimeofday(&tv_r_Filter_8_933050_e, 0);

    struct timeval tv_r_Filter_8_717819_s, tv_r_Filter_8_717819_e;
    gettimeofday(&tv_r_Filter_8_717819_s, 0);
    SW_Filter_TD_8468755(tbl_SerializeFromObject_TD_9552791_input, tbl_Filter_TD_8468755_output);
    gettimeofday(&tv_r_Filter_8_717819_e, 0);

    struct timeval tv_r_JOIN_INNER_8_153997_s, tv_r_JOIN_INNER_8_153997_e;
    gettimeofday(&tv_r_JOIN_INNER_8_153997_s, 0);
    trans_JOIN_INNER_TD_8413016.add(&(tbl_Filter_TD_9517811_output));
    trans_JOIN_INNER_TD_8413016.add(&(tbl_Filter_TD_9906071_output));
    trans_JOIN_INNER_TD_8413016.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8413016), &(events_h2d_wr_JOIN_INNER_TD_8413016[0]));
    events_grp_JOIN_INNER_TD_8413016.push_back(events_h2d_wr_JOIN_INNER_TD_8413016[0]);
    krnl_JOIN_INNER_TD_8413016.run(0, &(events_grp_JOIN_INNER_TD_8413016), &(events_JOIN_INNER_TD_8413016[0]));
    gettimeofday(&tv_r_JOIN_INNER_8_153997_e, 0);

    struct timeval tv_r_Filter_8_876555_s, tv_r_Filter_8_876555_e;
    gettimeofday(&tv_r_Filter_8_876555_s, 0);
    SW_Filter_TD_8210260(tbl_SerializeFromObject_TD_9744059_input, tbl_Filter_TD_8210260_output);
    gettimeofday(&tv_r_Filter_8_876555_e, 0);

    struct timeval tv_r_Filter_8_973915_s, tv_r_Filter_8_973915_e;
    gettimeofday(&tv_r_Filter_8_973915_s, 0);
    SW_Filter_TD_8969594(tbl_SerializeFromObject_TD_9471458_input, tbl_Filter_TD_8969594_output);
    gettimeofday(&tv_r_Filter_8_973915_e, 0);

    struct timeval tv_r_Filter_8_904049_s, tv_r_Filter_8_904049_e;
    gettimeofday(&tv_r_Filter_8_904049_s, 0);
    SW_Filter_TD_8588043(tbl_SerializeFromObject_TD_9114440_input, tbl_Filter_TD_8588043_output);
    gettimeofday(&tv_r_Filter_8_904049_e, 0);

    struct timeval tv_r_JOIN_INNER_8_887828_s, tv_r_JOIN_INNER_8_887828_e;
    gettimeofday(&tv_r_JOIN_INNER_8_887828_s, 0);
    trans_JOIN_INNER_TD_8636067.add(&(tbl_Filter_TD_912636_output));
    trans_JOIN_INNER_TD_8636067.add(&(tbl_Filter_TD_9489580_output));
    trans_JOIN_INNER_TD_8636067.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8636067), &(events_h2d_wr_JOIN_INNER_TD_8636067[0]));
    events_grp_JOIN_INNER_TD_8636067.push_back(events_h2d_wr_JOIN_INNER_TD_8636067[0]);
    krnl_JOIN_INNER_TD_8636067.run(0, &(events_grp_JOIN_INNER_TD_8636067), &(events_JOIN_INNER_TD_8636067[0]));
    gettimeofday(&tv_r_JOIN_INNER_8_887828_e, 0);

    struct timeval tv_r_Filter_8_481540_s, tv_r_Filter_8_481540_e;
    gettimeofday(&tv_r_Filter_8_481540_s, 0);
    SW_Filter_TD_8271261(tbl_SerializeFromObject_TD_9229579_input, tbl_Filter_TD_8271261_output);
    gettimeofday(&tv_r_Filter_8_481540_e, 0);

    struct timeval tv_r_Filter_8_902807_s, tv_r_Filter_8_902807_e;
    gettimeofday(&tv_r_Filter_8_902807_s, 0);
    SW_Filter_TD_8169404(tbl_SerializeFromObject_TD_9565321_input, tbl_Filter_TD_8169404_output);
    gettimeofday(&tv_r_Filter_8_902807_e, 0);

    struct timeval tv_r_Filter_8_353185_s, tv_r_Filter_8_353185_e;
    gettimeofday(&tv_r_Filter_8_353185_s, 0);
    SW_Filter_TD_8991702(tbl_SerializeFromObject_TD_9593503_input, tbl_Filter_TD_8991702_output);
    gettimeofday(&tv_r_Filter_8_353185_e, 0);

    struct timeval tv_r_JOIN_INNER_8_268238_s, tv_r_JOIN_INNER_8_268238_e;
    gettimeofday(&tv_r_JOIN_INNER_8_268238_s, 0);
    trans_JOIN_INNER_TD_8344086.add(&(tbl_Filter_TD_956963_output));
    trans_JOIN_INNER_TD_8344086.add(&(tbl_Filter_TD_9256316_output));
    trans_JOIN_INNER_TD_8344086.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8344086), &(events_h2d_wr_JOIN_INNER_TD_8344086[0]));
    events_grp_JOIN_INNER_TD_8344086.push_back(events_h2d_wr_JOIN_INNER_TD_8344086[0]);
    krnl_JOIN_INNER_TD_8344086.run(0, &(events_grp_JOIN_INNER_TD_8344086), &(events_JOIN_INNER_TD_8344086[0]));
    gettimeofday(&tv_r_JOIN_INNER_8_268238_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_7_939335_s, tv_r_JOIN_LEFTSEMI_7_939335_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_939335_s, 0);
    SW_JOIN_LEFTSEMI_TD_7180037(tbl_Filter_TD_830576_output, tbl_Filter_TD_8664082_output, tbl_JOIN_LEFTSEMI_TD_7180037_output);
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_939335_e, 0);

    struct timeval tv_r_JOIN_INNER_7_180845_s, tv_r_JOIN_INNER_7_180845_e;
    gettimeofday(&tv_r_JOIN_INNER_7_180845_s, 0);
    prev_events_grp_JOIN_INNER_TD_7169986.push_back(events_h2d_wr_JOIN_INNER_TD_8413016[0]);
    trans_JOIN_INNER_TD_7169986.add(&(tbl_Filter_TD_8468755_output));
    trans_JOIN_INNER_TD_7169986.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7169986), &(events_h2d_wr_JOIN_INNER_TD_7169986[0]));
    events_grp_JOIN_INNER_TD_7169986.push_back(events_h2d_wr_JOIN_INNER_TD_7169986[0]);
    events_grp_JOIN_INNER_TD_7169986.push_back(events_JOIN_INNER_TD_8413016[0]);
    krnl_JOIN_INNER_TD_7169986.run(0, &(events_grp_JOIN_INNER_TD_7169986), &(events_JOIN_INNER_TD_7169986[0]));
    
    trans_JOIN_INNER_TD_7169986_out.add(&(tbl_JOIN_INNER_TD_7169986_output));
    trans_JOIN_INNER_TD_7169986_out.dev2host(0, &(events_JOIN_INNER_TD_7169986), &(events_d2h_rd_JOIN_INNER_TD_7169986[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_7_180845_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_7_898656_s, tv_r_JOIN_LEFTSEMI_7_898656_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_898656_s, 0);
    SW_JOIN_LEFTSEMI_TD_7580410(tbl_Filter_TD_8969594_output, tbl_Filter_TD_8210260_output, tbl_JOIN_LEFTSEMI_TD_7580410_output);
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_898656_e, 0);

    struct timeval tv_r_JOIN_INNER_7_837219_s, tv_r_JOIN_INNER_7_837219_e;
    gettimeofday(&tv_r_JOIN_INNER_7_837219_s, 0);
    prev_events_grp_JOIN_INNER_TD_7450298.push_back(events_h2d_wr_JOIN_INNER_TD_8636067[0]);
    trans_JOIN_INNER_TD_7450298.add(&(tbl_Filter_TD_8588043_output));
    trans_JOIN_INNER_TD_7450298.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7450298), &(events_h2d_wr_JOIN_INNER_TD_7450298[0]));
    events_grp_JOIN_INNER_TD_7450298.push_back(events_h2d_wr_JOIN_INNER_TD_7450298[0]);
    events_grp_JOIN_INNER_TD_7450298.push_back(events_JOIN_INNER_TD_8636067[0]);
    krnl_JOIN_INNER_TD_7450298.run(0, &(events_grp_JOIN_INNER_TD_7450298), &(events_JOIN_INNER_TD_7450298[0]));
    
    trans_JOIN_INNER_TD_7450298_out.add(&(tbl_JOIN_INNER_TD_7450298_output));
    trans_JOIN_INNER_TD_7450298_out.dev2host(0, &(events_JOIN_INNER_TD_7450298), &(events_d2h_rd_JOIN_INNER_TD_7450298[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_7_837219_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_7_575823_s, tv_r_JOIN_LEFTSEMI_7_575823_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_575823_s, 0);
    SW_JOIN_LEFTSEMI_TD_7421637(tbl_Filter_TD_8169404_output, tbl_Filter_TD_8271261_output, tbl_JOIN_LEFTSEMI_TD_7421637_output);
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_575823_e, 0);

    struct timeval tv_r_JOIN_INNER_7_621822_s, tv_r_JOIN_INNER_7_621822_e;
    gettimeofday(&tv_r_JOIN_INNER_7_621822_s, 0);
    prev_events_grp_JOIN_INNER_TD_7486229.push_back(events_h2d_wr_JOIN_INNER_TD_8344086[0]);
    trans_JOIN_INNER_TD_7486229.add(&(tbl_Filter_TD_8991702_output));
    trans_JOIN_INNER_TD_7486229.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7486229), &(events_h2d_wr_JOIN_INNER_TD_7486229[0]));
    events_grp_JOIN_INNER_TD_7486229.push_back(events_h2d_wr_JOIN_INNER_TD_7486229[0]);
    events_grp_JOIN_INNER_TD_7486229.push_back(events_JOIN_INNER_TD_8344086[0]);
    krnl_JOIN_INNER_TD_7486229.run(0, &(events_grp_JOIN_INNER_TD_7486229), &(events_JOIN_INNER_TD_7486229[0]));
    
    trans_JOIN_INNER_TD_7486229_out.add(&(tbl_JOIN_INNER_TD_7486229_output));
    trans_JOIN_INNER_TD_7486229_out.dev2host(0, &(events_JOIN_INNER_TD_7486229), &(events_d2h_rd_JOIN_INNER_TD_7486229[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_7_621822_e, 0);

    struct timeval tv_r_JOIN_INNER_6_119571_s, tv_r_JOIN_INNER_6_119571_e;
    gettimeofday(&tv_r_JOIN_INNER_6_119571_s, 0);
    SW_JOIN_INNER_TD_6530078(tbl_JOIN_INNER_TD_7169986_output, tbl_JOIN_LEFTSEMI_TD_7180037_output, tbl_JOIN_INNER_TD_6530078_output);
    gettimeofday(&tv_r_JOIN_INNER_6_119571_e, 0);

    struct timeval tv_r_JOIN_INNER_6_179190_s, tv_r_JOIN_INNER_6_179190_e;
    gettimeofday(&tv_r_JOIN_INNER_6_179190_s, 0);
    SW_JOIN_INNER_TD_6679733(tbl_JOIN_INNER_TD_7450298_output, tbl_JOIN_LEFTSEMI_TD_7580410_output, tbl_JOIN_INNER_TD_6679733_output);
    gettimeofday(&tv_r_JOIN_INNER_6_179190_e, 0);

    struct timeval tv_r_JOIN_INNER_6_422613_s, tv_r_JOIN_INNER_6_422613_e;
    gettimeofday(&tv_r_JOIN_INNER_6_422613_s, 0);
    SW_JOIN_INNER_TD_6645053(tbl_JOIN_INNER_TD_7486229_output, tbl_JOIN_LEFTSEMI_TD_7421637_output, tbl_JOIN_INNER_TD_6645053_output);
    gettimeofday(&tv_r_JOIN_INNER_6_422613_e, 0);

    struct timeval tv_r_Aggregate_5_523204_s, tv_r_Aggregate_5_523204_e;
    gettimeofday(&tv_r_Aggregate_5_523204_s, 0);
    SW_Aggregate_TD_5415964(tbl_JOIN_INNER_TD_6530078_output, tbl_Aggregate_TD_5415964_output);
    gettimeofday(&tv_r_Aggregate_5_523204_e, 0);

    struct timeval tv_r_Aggregate_5_231798_s, tv_r_Aggregate_5_231798_e;
    gettimeofday(&tv_r_Aggregate_5_231798_s, 0);
    SW_Aggregate_TD_5454060(tbl_JOIN_INNER_TD_6679733_output, tbl_Aggregate_TD_5454060_output);
    gettimeofday(&tv_r_Aggregate_5_231798_e, 0);

    struct timeval tv_r_Aggregate_5_908708_s, tv_r_Aggregate_5_908708_e;
    gettimeofday(&tv_r_Aggregate_5_908708_s, 0);
    SW_Aggregate_TD_5675265(tbl_JOIN_INNER_TD_6645053_output, tbl_Aggregate_TD_5675265_output);
    gettimeofday(&tv_r_Aggregate_5_908708_e, 0);

    struct timeval tv_r_Union_4_24364_s, tv_r_Union_4_24364_e;
    gettimeofday(&tv_r_Union_4_24364_s, 0);
    SW_Union_TD_4424619(tbl_Aggregate_TD_5675265_output, tbl_Aggregate_TD_5454060_output, tbl_Aggregate_TD_5415964_output, tbl_Union_TD_4424619_output);
    gettimeofday(&tv_r_Union_4_24364_e, 0);

    struct timeval tv_r_Aggregate_3_368547_s, tv_r_Aggregate_3_368547_e;
    gettimeofday(&tv_r_Aggregate_3_368547_s, 0);
    SW_Aggregate_TD_3682917(tbl_Union_TD_4424619_output, tbl_Aggregate_TD_3682917_output);
    gettimeofday(&tv_r_Aggregate_3_368547_e, 0);

    struct timeval tv_r_Sort_2_769096_s, tv_r_Sort_2_769096_e;
    gettimeofday(&tv_r_Sort_2_769096_s, 0);
    SW_Sort_TD_2121567(tbl_Aggregate_TD_3682917_output, tbl_Sort_TD_2121567_output);
    gettimeofday(&tv_r_Sort_2_769096_e, 0);

    struct timeval tv_r_LocalLimit_1_650986_s, tv_r_LocalLimit_1_650986_e;
    gettimeofday(&tv_r_LocalLimit_1_650986_s, 0);
    SW_LocalLimit_TD_1545917(tbl_Sort_TD_2121567_output, tbl_LocalLimit_TD_1545917_output);
    gettimeofday(&tv_r_LocalLimit_1_650986_e, 0);

    struct timeval tv_r_GlobalLimit_0_134010_s, tv_r_GlobalLimit_0_134010_e;
    gettimeofday(&tv_r_GlobalLimit_0_134010_s, 0);
    SW_GlobalLimit_TD_067268(tbl_LocalLimit_TD_1545917_output, tbl_GlobalLimit_TD_067268_output);
    gettimeofday(&tv_r_GlobalLimit_0_134010_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_366098_s, &tv_r_Filter_9_366098_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10886347_input: " << tbl_SerializeFromObject_TD_10886347_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_916594_s, &tv_r_Filter_9_916594_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10129579_input: " << tbl_SerializeFromObject_TD_10129579_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_220056_s, &tv_r_Filter_9_220056_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10959226_input: " << tbl_SerializeFromObject_TD_10959226_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_471179_s, &tv_r_Filter_9_471179_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10346483_input: " << tbl_SerializeFromObject_TD_10346483_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_192845_s, &tv_r_Filter_9_192845_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10953264_input: " << tbl_SerializeFromObject_TD_10953264_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_734955_s, &tv_r_Filter_9_734955_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10603067_input: " << tbl_SerializeFromObject_TD_10603067_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_481578_s, &tv_r_Filter_8_481578_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_968716_input: " << tbl_SerializeFromObject_TD_968716_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_933050_s, &tv_r_Filter_8_933050_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9822938_input: " << tbl_SerializeFromObject_TD_9822938_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_717819_s, &tv_r_Filter_8_717819_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9552791_input: " << tbl_SerializeFromObject_TD_9552791_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_153997_s, &tv_r_JOIN_INNER_8_153997_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9517811_output: " << tbl_Filter_TD_9517811_output.getNumRow() << " " << "tbl_Filter_TD_9906071_output: " << tbl_Filter_TD_9906071_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_876555_s, &tv_r_Filter_8_876555_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9744059_input: " << tbl_SerializeFromObject_TD_9744059_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_973915_s, &tv_r_Filter_8_973915_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9471458_input: " << tbl_SerializeFromObject_TD_9471458_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_904049_s, &tv_r_Filter_8_904049_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9114440_input: " << tbl_SerializeFromObject_TD_9114440_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_887828_s, &tv_r_JOIN_INNER_8_887828_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_912636_output: " << tbl_Filter_TD_912636_output.getNumRow() << " " << "tbl_Filter_TD_9489580_output: " << tbl_Filter_TD_9489580_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_481540_s, &tv_r_Filter_8_481540_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9229579_input: " << tbl_SerializeFromObject_TD_9229579_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_902807_s, &tv_r_Filter_8_902807_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9565321_input: " << tbl_SerializeFromObject_TD_9565321_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_353185_s, &tv_r_Filter_8_353185_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9593503_input: " << tbl_SerializeFromObject_TD_9593503_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_268238_s, &tv_r_JOIN_INNER_8_268238_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_956963_output: " << tbl_Filter_TD_956963_output.getNumRow() << " " << "tbl_Filter_TD_9256316_output: " << tbl_Filter_TD_9256316_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_7: " << tvdiff(&tv_r_JOIN_LEFTSEMI_7_939335_s, &tv_r_JOIN_LEFTSEMI_7_939335_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_830576_output: " << tbl_Filter_TD_830576_output.getNumRow() << " " << "tbl_Filter_TD_8664082_output: " << tbl_Filter_TD_8664082_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_180845_s, &tv_r_JOIN_INNER_7_180845_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8413016_output: " << tbl_JOIN_INNER_TD_8413016_output.getNumRow() << " " << "tbl_Filter_TD_8468755_output: " << tbl_Filter_TD_8468755_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_7: " << tvdiff(&tv_r_JOIN_LEFTSEMI_7_898656_s, &tv_r_JOIN_LEFTSEMI_7_898656_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8969594_output: " << tbl_Filter_TD_8969594_output.getNumRow() << " " << "tbl_Filter_TD_8210260_output: " << tbl_Filter_TD_8210260_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_837219_s, &tv_r_JOIN_INNER_7_837219_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8636067_output: " << tbl_JOIN_INNER_TD_8636067_output.getNumRow() << " " << "tbl_Filter_TD_8588043_output: " << tbl_Filter_TD_8588043_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_7: " << tvdiff(&tv_r_JOIN_LEFTSEMI_7_575823_s, &tv_r_JOIN_LEFTSEMI_7_575823_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8169404_output: " << tbl_Filter_TD_8169404_output.getNumRow() << " " << "tbl_Filter_TD_8271261_output: " << tbl_Filter_TD_8271261_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_621822_s, &tv_r_JOIN_INNER_7_621822_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8344086_output: " << tbl_JOIN_INNER_TD_8344086_output.getNumRow() << " " << "tbl_Filter_TD_8991702_output: " << tbl_Filter_TD_8991702_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_119571_s, &tv_r_JOIN_INNER_6_119571_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7169986_output: " << tbl_JOIN_INNER_TD_7169986_output.getNumRow() << " " << "tbl_JOIN_LEFTSEMI_TD_7180037_output: " << tbl_JOIN_LEFTSEMI_TD_7180037_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_179190_s, &tv_r_JOIN_INNER_6_179190_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7450298_output: " << tbl_JOIN_INNER_TD_7450298_output.getNumRow() << " " << "tbl_JOIN_LEFTSEMI_TD_7580410_output: " << tbl_JOIN_LEFTSEMI_TD_7580410_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_422613_s, &tv_r_JOIN_INNER_6_422613_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7486229_output: " << tbl_JOIN_INNER_TD_7486229_output.getNumRow() << " " << "tbl_JOIN_LEFTSEMI_TD_7421637_output: " << tbl_JOIN_LEFTSEMI_TD_7421637_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_523204_s, &tv_r_Aggregate_5_523204_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6530078_output: " << tbl_JOIN_INNER_TD_6530078_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_231798_s, &tv_r_Aggregate_5_231798_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6679733_output: " << tbl_JOIN_INNER_TD_6679733_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_908708_s, &tv_r_Aggregate_5_908708_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6645053_output: " << tbl_JOIN_INNER_TD_6645053_output.getNumRow() << " " << std::endl; 

    std::cout << "Union_4: " << tvdiff(&tv_r_Union_4_24364_s, &tv_r_Union_4_24364_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_5675265_output: " << tbl_Aggregate_TD_5675265_output.getNumRow() << " " << "tbl_Aggregate_TD_5454060_output: " << tbl_Aggregate_TD_5454060_output.getNumRow() << " " << "tbl_Aggregate_TD_5415964_output: " << tbl_Aggregate_TD_5415964_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_368547_s, &tv_r_Aggregate_3_368547_e) / 1000.0 << " ms " 
     << "tbl_Union_TD_4424619_output: " << tbl_Union_TD_4424619_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_769096_s, &tv_r_Sort_2_769096_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3682917_output: " << tbl_Aggregate_TD_3682917_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_650986_s, &tv_r_LocalLimit_1_650986_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2121567_output: " << tbl_Sort_TD_2121567_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_134010_s, &tv_r_GlobalLimit_0_134010_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1545917_output: " << tbl_LocalLimit_TD_1545917_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.42274 * 1000 << "ms" << std::endl; 
    return 0; 
}
