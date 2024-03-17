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

#include "cfgFunc_q58.hpp" 
#include "q58.hpp" 

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
    std::cout << "NOTE:running query #58\n."; 
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
    Table tbl_GlobalLimit_TD_0582834_output("tbl_GlobalLimit_TD_0582834_output", 6100000, 8, "");
    tbl_GlobalLimit_TD_0582834_output.allocateHost();
    Table tbl_LocalLimit_TD_1544112_output("tbl_LocalLimit_TD_1544112_output", 6100000, 8, "");
    tbl_LocalLimit_TD_1544112_output.allocateHost();
    Table tbl_Sort_TD_2284597_output("tbl_Sort_TD_2284597_output", 6100000, 8, "");
    tbl_Sort_TD_2284597_output.allocateHost();
    Table tbl_Project_TD_3107127_output("tbl_Project_TD_3107127_output", 6100000, 8, "");
    tbl_Project_TD_3107127_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4925555_output("tbl_JOIN_INNER_TD_4925555_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_4925555_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5246198_output("tbl_JOIN_INNER_TD_5246198_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_5246198_output.allocateHost();
    Table tbl_Filter_TD_5974239_output("tbl_Filter_TD_5974239_output", 6100000, 2, "");
    tbl_Filter_TD_5974239_output.allocateHost();
    Table tbl_Filter_TD_6913275_output("tbl_Filter_TD_6913275_output", 6100000, 2, "");
    tbl_Filter_TD_6913275_output.allocateHost();
    Table tbl_Filter_TD_6473482_output("tbl_Filter_TD_6473482_output", 6100000, 2, "");
    tbl_Filter_TD_6473482_output.allocateHost();
    Table tbl_Aggregate_TD_6612499_output("tbl_Aggregate_TD_6612499_output", 6100000, 2, "");
    tbl_Aggregate_TD_6612499_output.allocateHost();
    Table tbl_Aggregate_TD_7578458_output("tbl_Aggregate_TD_7578458_output", 6100000, 2, "");
    tbl_Aggregate_TD_7578458_output.allocateHost();
    Table tbl_Aggregate_TD_7558107_output("tbl_Aggregate_TD_7558107_output", 6100000, 2, "");
    tbl_Aggregate_TD_7558107_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7624743_output("tbl_JOIN_INNER_TD_7624743_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_7624743_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8556613_output("tbl_JOIN_INNER_TD_8556613_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_8556613_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8153793_output("tbl_JOIN_INNER_TD_8153793_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_8153793_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8660771_output("tbl_JOIN_INNER_TD_8660771_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_8660771_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_8762305_output("tbl_JOIN_LEFTSEMI_TD_8762305_output", 6100000, 1, "");
    tbl_JOIN_LEFTSEMI_TD_8762305_output.allocateHost();
    Table tbl_JOIN_INNER_TD_9257061_output("tbl_JOIN_INNER_TD_9257061_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_9257061_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_9665435_output("tbl_JOIN_LEFTSEMI_TD_9665435_output", 6100000, 1, "");
    tbl_JOIN_LEFTSEMI_TD_9665435_output.allocateHost();
    Table tbl_JOIN_INNER_TD_9827406_output("tbl_JOIN_INNER_TD_9827406_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_9827406_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_9390391_output("tbl_JOIN_LEFTSEMI_TD_9390391_output", 6100000, 1, "");
    tbl_JOIN_LEFTSEMI_TD_9390391_output.allocateHost();
    Table tbl_Filter_TD_9823304_output("tbl_Filter_TD_9823304_output", 6100000, 3, "");
    tbl_Filter_TD_9823304_output.allocateHost();
    Table tbl_Filter_TD_9910098_output("tbl_Filter_TD_9910098_output", 6100000, 2, "");
    tbl_Filter_TD_9910098_output.allocateHost();
    Table tbl_Filter_TD_9498299_output("tbl_Filter_TD_9498299_output", 6100000, 2, "");
    tbl_Filter_TD_9498299_output.allocateHost();
    Table tbl_Filter_TD_9246886_output("tbl_Filter_TD_9246886_output", 6100000, 1, "");
    tbl_Filter_TD_9246886_output.allocateHost();
    Table tbl_Filter_TD_10307030_output("tbl_Filter_TD_10307030_output", 6100000, 3, "");
    tbl_Filter_TD_10307030_output.allocateHost();
    Table tbl_Filter_TD_10874105_output("tbl_Filter_TD_10874105_output", 6100000, 2, "");
    tbl_Filter_TD_10874105_output.allocateHost();
    Table tbl_Filter_TD_1092114_output("tbl_Filter_TD_1092114_output", 6100000, 2, "");
    tbl_Filter_TD_1092114_output.allocateHost();
    Table tbl_Filter_TD_1072639_output("tbl_Filter_TD_1072639_output", 6100000, 1, "");
    tbl_Filter_TD_1072639_output.allocateHost();
    Table tbl_Filter_TD_10649710_output("tbl_Filter_TD_10649710_output", 6100000, 3, "");
    tbl_Filter_TD_10649710_output.allocateHost();
    Table tbl_Filter_TD_10143311_output("tbl_Filter_TD_10143311_output", 6100000, 2, "");
    tbl_Filter_TD_10143311_output.allocateHost();
    Table tbl_Filter_TD_10511021_output("tbl_Filter_TD_10511021_output", 6100000, 2, "");
    tbl_Filter_TD_10511021_output.allocateHost();
    Table tbl_Filter_TD_10563997_output("tbl_Filter_TD_10563997_output", 6100000, 1, "");
    tbl_Filter_TD_10563997_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10556762_input;
    tbl_SerializeFromObject_TD_10556762_input = Table("web_sales", web_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10556762_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10556762_input.addCol("ws_item_sk", 4);
    tbl_SerializeFromObject_TD_10556762_input.addCol("ws_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_10556762_input.allocateHost();
    tbl_SerializeFromObject_TD_10556762_input.loadHost();
    Table tbl_SerializeFromObject_TD_10749887_input;
    tbl_SerializeFromObject_TD_10749887_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10749887_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_10749887_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10749887_input.allocateHost();
    tbl_SerializeFromObject_TD_10749887_input.loadHost();
    Table tbl_SerializeFromObject_TD_10808018_input;
    tbl_SerializeFromObject_TD_10808018_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10808018_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10808018_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_10808018_input.allocateHost();
    tbl_SerializeFromObject_TD_10808018_input.loadHost();
    Table tbl_SerializeFromObject_TD_10133961_input;
    tbl_SerializeFromObject_TD_10133961_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10133961_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_10133961_input.addCol("d_week_seq", 4);
    tbl_SerializeFromObject_TD_10133961_input.allocateHost();
    tbl_SerializeFromObject_TD_10133961_input.loadHost();
    Table tbl_Filter_TD_10185589_output("tbl_Filter_TD_10185589_output", 6100000, 1, "");
    tbl_Filter_TD_10185589_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11147263_input;
    tbl_SerializeFromObject_TD_11147263_input = Table("store_sales", store_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11147263_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_11147263_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_11147263_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_11147263_input.allocateHost();
    tbl_SerializeFromObject_TD_11147263_input.loadHost();
    Table tbl_SerializeFromObject_TD_1127514_input;
    tbl_SerializeFromObject_TD_1127514_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_1127514_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_1127514_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_1127514_input.allocateHost();
    tbl_SerializeFromObject_TD_1127514_input.loadHost();
    Table tbl_SerializeFromObject_TD_11801816_input;
    tbl_SerializeFromObject_TD_11801816_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11801816_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_11801816_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_11801816_input.allocateHost();
    tbl_SerializeFromObject_TD_11801816_input.loadHost();
    Table tbl_SerializeFromObject_TD_11933280_input;
    tbl_SerializeFromObject_TD_11933280_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11933280_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_11933280_input.addCol("d_week_seq", 4);
    tbl_SerializeFromObject_TD_11933280_input.allocateHost();
    tbl_SerializeFromObject_TD_11933280_input.loadHost();
    Table tbl_Filter_TD_11442474_output("tbl_Filter_TD_11442474_output", 6100000, 1, "");
    tbl_Filter_TD_11442474_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11835059_input;
    tbl_SerializeFromObject_TD_11835059_input = Table("catalog_sales", catalog_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11835059_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_11835059_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_11835059_input.addCol("cs_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_11835059_input.allocateHost();
    tbl_SerializeFromObject_TD_11835059_input.loadHost();
    Table tbl_SerializeFromObject_TD_11217812_input;
    tbl_SerializeFromObject_TD_11217812_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11217812_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_11217812_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_11217812_input.allocateHost();
    tbl_SerializeFromObject_TD_11217812_input.loadHost();
    Table tbl_SerializeFromObject_TD_11249605_input;
    tbl_SerializeFromObject_TD_11249605_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11249605_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_11249605_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_11249605_input.allocateHost();
    tbl_SerializeFromObject_TD_11249605_input.loadHost();
    Table tbl_SerializeFromObject_TD_11717880_input;
    tbl_SerializeFromObject_TD_11717880_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11717880_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_11717880_input.addCol("d_week_seq", 4);
    tbl_SerializeFromObject_TD_11717880_input.allocateHost();
    tbl_SerializeFromObject_TD_11717880_input.loadHost();
    Table tbl_Filter_TD_11372705_output("tbl_Filter_TD_11372705_output", 6100000, 1, "");
    tbl_Filter_TD_11372705_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11990241_input;
    tbl_SerializeFromObject_TD_11990241_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11990241_input.addCol("d_week_seq", 4);
    tbl_SerializeFromObject_TD_11990241_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_11990241_input.allocateHost();
    tbl_SerializeFromObject_TD_11990241_input.loadHost();
    Table tbl_SerializeFromObject_TD_12250840_input;
    tbl_SerializeFromObject_TD_12250840_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12250840_input.addCol("d_week_seq", 4);
    tbl_SerializeFromObject_TD_12250840_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_12250840_input.allocateHost();
    tbl_SerializeFromObject_TD_12250840_input.loadHost();
    Table tbl_SerializeFromObject_TD_12123737_input;
    tbl_SerializeFromObject_TD_12123737_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_12123737_input.addCol("d_week_seq", 4);
    tbl_SerializeFromObject_TD_12123737_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_12123737_input.allocateHost();
    tbl_SerializeFromObject_TD_12123737_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_LEFTSEMI_TD_8762305_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTSEMI_TD_9665435_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTSEMI_TD_9390391_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9498299_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9246886_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_1092114_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_1072639_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10511021_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10563997_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_LEFTSEMI_TD_8762305_cmds;
    cfg_JOIN_LEFTSEMI_TD_8762305_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_8762305_gqe_join (cfg_JOIN_LEFTSEMI_TD_8762305_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_8762305_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_9665435_cmds;
    cfg_JOIN_LEFTSEMI_TD_9665435_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_9665435_gqe_join (cfg_JOIN_LEFTSEMI_TD_9665435_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_9665435_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_9390391_cmds;
    cfg_JOIN_LEFTSEMI_TD_9390391_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_9390391_gqe_join (cfg_JOIN_LEFTSEMI_TD_9390391_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_9390391_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_LEFTSEMI_TD_8762305;
    krnl_JOIN_LEFTSEMI_TD_8762305 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTSEMI_TD_8762305.setup(tbl_Filter_TD_9246886_output, tbl_Filter_TD_9498299_output, tbl_JOIN_LEFTSEMI_TD_8762305_output, cfg_JOIN_LEFTSEMI_TD_8762305_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_9665435;
    krnl_JOIN_LEFTSEMI_TD_9665435 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTSEMI_TD_9665435.setup(tbl_Filter_TD_1072639_output, tbl_Filter_TD_1092114_output, tbl_JOIN_LEFTSEMI_TD_9665435_output, cfg_JOIN_LEFTSEMI_TD_9665435_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_9390391;
    krnl_JOIN_LEFTSEMI_TD_9390391 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTSEMI_TD_9390391.setup(tbl_Filter_TD_10563997_output, tbl_Filter_TD_10511021_output, tbl_JOIN_LEFTSEMI_TD_9390391_output, cfg_JOIN_LEFTSEMI_TD_9390391_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_LEFTSEMI_TD_8762305;
    trans_JOIN_LEFTSEMI_TD_8762305.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_8762305.add(&(cfg_JOIN_LEFTSEMI_TD_8762305_cmds));
    transEngine trans_JOIN_LEFTSEMI_TD_8762305_out;
    trans_JOIN_LEFTSEMI_TD_8762305_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_LEFTSEMI_TD_9665435;
    trans_JOIN_LEFTSEMI_TD_9665435.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_9665435.add(&(cfg_JOIN_LEFTSEMI_TD_9665435_cmds));
    transEngine trans_JOIN_LEFTSEMI_TD_9665435_out;
    trans_JOIN_LEFTSEMI_TD_9665435_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_LEFTSEMI_TD_9390391;
    trans_JOIN_LEFTSEMI_TD_9390391.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_9390391.add(&(cfg_JOIN_LEFTSEMI_TD_9390391_cmds));
    transEngine trans_JOIN_LEFTSEMI_TD_9390391_out;
    trans_JOIN_LEFTSEMI_TD_9390391_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_8762305;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_8762305;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_8762305;
    events_h2d_wr_JOIN_LEFTSEMI_TD_8762305.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_8762305.resize(1);
    events_JOIN_LEFTSEMI_TD_8762305.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_8762305;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_8762305;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_9665435;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_9665435;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_9665435;
    events_h2d_wr_JOIN_LEFTSEMI_TD_9665435.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_9665435.resize(1);
    events_JOIN_LEFTSEMI_TD_9665435.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_9665435;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_9665435;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_9390391;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_9390391;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_9390391;
    events_h2d_wr_JOIN_LEFTSEMI_TD_9390391.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_9390391.resize(1);
    events_JOIN_LEFTSEMI_TD_9390391.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_9390391;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_9390391;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_11_248259_s, tv_r_Filter_11_248259_e;
    gettimeofday(&tv_r_Filter_11_248259_s, 0);
    SW_Filter_TD_11372705(tbl_SerializeFromObject_TD_12123737_input, tbl_Filter_TD_11372705_output);
    gettimeofday(&tv_r_Filter_11_248259_e, 0);

    struct timeval tv_r_Filter_11_425311_s, tv_r_Filter_11_425311_e;
    gettimeofday(&tv_r_Filter_11_425311_s, 0);
    SW_Filter_TD_11442474(tbl_SerializeFromObject_TD_12250840_input, tbl_Filter_TD_11442474_output);
    gettimeofday(&tv_r_Filter_11_425311_e, 0);

    struct timeval tv_r_Filter_10_555683_s, tv_r_Filter_10_555683_e;
    gettimeofday(&tv_r_Filter_10_555683_s, 0);
    SW_Filter_TD_10185589(tbl_SerializeFromObject_TD_11990241_input, tbl_Filter_TD_10185589_output);
    gettimeofday(&tv_r_Filter_10_555683_e, 0);

    struct timeval tv_r_Filter_10_989340_s, tv_r_Filter_10_989340_e;
    gettimeofday(&tv_r_Filter_10_989340_s, 0);
    SW_Filter_TD_10563997(tbl_SerializeFromObject_TD_11717880_input, tbl_Filter_TD_11372705_output, tbl_Filter_TD_10563997_output);
    gettimeofday(&tv_r_Filter_10_989340_e, 0);

    struct timeval tv_r_Filter_10_895116_s, tv_r_Filter_10_895116_e;
    gettimeofday(&tv_r_Filter_10_895116_s, 0);
    SW_Filter_TD_10511021(tbl_SerializeFromObject_TD_11249605_input, tbl_Filter_TD_10511021_output);
    gettimeofday(&tv_r_Filter_10_895116_e, 0);

    struct timeval tv_r_Filter_10_403727_s, tv_r_Filter_10_403727_e;
    gettimeofday(&tv_r_Filter_10_403727_s, 0);
    SW_Filter_TD_10143311(tbl_SerializeFromObject_TD_11217812_input, tbl_Filter_TD_10143311_output);
    gettimeofday(&tv_r_Filter_10_403727_e, 0);

    struct timeval tv_r_Filter_10_948078_s, tv_r_Filter_10_948078_e;
    gettimeofday(&tv_r_Filter_10_948078_s, 0);
    SW_Filter_TD_10649710(tbl_SerializeFromObject_TD_11835059_input, tbl_Filter_TD_10649710_output);
    gettimeofday(&tv_r_Filter_10_948078_e, 0);

    struct timeval tv_r_Filter_10_952860_s, tv_r_Filter_10_952860_e;
    gettimeofday(&tv_r_Filter_10_952860_s, 0);
    SW_Filter_TD_1072639(tbl_SerializeFromObject_TD_11933280_input, tbl_Filter_TD_11442474_output, tbl_Filter_TD_1072639_output);
    gettimeofday(&tv_r_Filter_10_952860_e, 0);

    struct timeval tv_r_Filter_10_456620_s, tv_r_Filter_10_456620_e;
    gettimeofday(&tv_r_Filter_10_456620_s, 0);
    SW_Filter_TD_1092114(tbl_SerializeFromObject_TD_11801816_input, tbl_Filter_TD_1092114_output);
    gettimeofday(&tv_r_Filter_10_456620_e, 0);

    struct timeval tv_r_Filter_10_626066_s, tv_r_Filter_10_626066_e;
    gettimeofday(&tv_r_Filter_10_626066_s, 0);
    SW_Filter_TD_10874105(tbl_SerializeFromObject_TD_1127514_input, tbl_Filter_TD_10874105_output);
    gettimeofday(&tv_r_Filter_10_626066_e, 0);

    struct timeval tv_r_Filter_10_510281_s, tv_r_Filter_10_510281_e;
    gettimeofday(&tv_r_Filter_10_510281_s, 0);
    SW_Filter_TD_10307030(tbl_SerializeFromObject_TD_11147263_input, tbl_Filter_TD_10307030_output);
    gettimeofday(&tv_r_Filter_10_510281_e, 0);

    struct timeval tv_r_Filter_9_512601_s, tv_r_Filter_9_512601_e;
    gettimeofday(&tv_r_Filter_9_512601_s, 0);
    SW_Filter_TD_9246886(tbl_SerializeFromObject_TD_10133961_input, tbl_Filter_TD_10185589_output, tbl_Filter_TD_9246886_output);
    gettimeofday(&tv_r_Filter_9_512601_e, 0);

    struct timeval tv_r_Filter_9_272174_s, tv_r_Filter_9_272174_e;
    gettimeofday(&tv_r_Filter_9_272174_s, 0);
    SW_Filter_TD_9498299(tbl_SerializeFromObject_TD_10808018_input, tbl_Filter_TD_9498299_output);
    gettimeofday(&tv_r_Filter_9_272174_e, 0);

    struct timeval tv_r_Filter_9_565186_s, tv_r_Filter_9_565186_e;
    gettimeofday(&tv_r_Filter_9_565186_s, 0);
    SW_Filter_TD_9910098(tbl_SerializeFromObject_TD_10749887_input, tbl_Filter_TD_9910098_output);
    gettimeofday(&tv_r_Filter_9_565186_e, 0);

    struct timeval tv_r_Filter_9_200608_s, tv_r_Filter_9_200608_e;
    gettimeofday(&tv_r_Filter_9_200608_s, 0);
    SW_Filter_TD_9823304(tbl_SerializeFromObject_TD_10556762_input, tbl_Filter_TD_9823304_output);
    gettimeofday(&tv_r_Filter_9_200608_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_9_960510_s, tv_r_JOIN_LEFTSEMI_9_960510_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_9_960510_s, 0);
    trans_JOIN_LEFTSEMI_TD_9390391.add(&(tbl_Filter_TD_10511021_output));
    trans_JOIN_LEFTSEMI_TD_9390391.add(&(tbl_Filter_TD_10563997_output));
    trans_JOIN_LEFTSEMI_TD_9390391.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_9390391), &(events_h2d_wr_JOIN_LEFTSEMI_TD_9390391[0]));
    events_grp_JOIN_LEFTSEMI_TD_9390391.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_9390391[0]);
    krnl_JOIN_LEFTSEMI_TD_9390391.run(0, &(events_grp_JOIN_LEFTSEMI_TD_9390391), &(events_JOIN_LEFTSEMI_TD_9390391[0]));
    
    trans_JOIN_LEFTSEMI_TD_9390391_out.add(&(tbl_JOIN_LEFTSEMI_TD_9390391_output));
    trans_JOIN_LEFTSEMI_TD_9390391_out.dev2host(0, &(events_JOIN_LEFTSEMI_TD_9390391), &(events_d2h_rd_JOIN_LEFTSEMI_TD_9390391[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_LEFTSEMI_9_960510_e, 0);

    struct timeval tv_r_JOIN_INNER_9_984347_s, tv_r_JOIN_INNER_9_984347_e;
    gettimeofday(&tv_r_JOIN_INNER_9_984347_s, 0);
    SW_JOIN_INNER_TD_9827406(tbl_Filter_TD_10649710_output, tbl_Filter_TD_10143311_output, tbl_JOIN_INNER_TD_9827406_output);
    gettimeofday(&tv_r_JOIN_INNER_9_984347_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_9_463775_s, tv_r_JOIN_LEFTSEMI_9_463775_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_9_463775_s, 0);
    trans_JOIN_LEFTSEMI_TD_9665435.add(&(tbl_Filter_TD_1092114_output));
    trans_JOIN_LEFTSEMI_TD_9665435.add(&(tbl_Filter_TD_1072639_output));
    trans_JOIN_LEFTSEMI_TD_9665435.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_9665435), &(events_h2d_wr_JOIN_LEFTSEMI_TD_9665435[0]));
    events_grp_JOIN_LEFTSEMI_TD_9665435.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_9665435[0]);
    krnl_JOIN_LEFTSEMI_TD_9665435.run(0, &(events_grp_JOIN_LEFTSEMI_TD_9665435), &(events_JOIN_LEFTSEMI_TD_9665435[0]));
    
    trans_JOIN_LEFTSEMI_TD_9665435_out.add(&(tbl_JOIN_LEFTSEMI_TD_9665435_output));
    trans_JOIN_LEFTSEMI_TD_9665435_out.dev2host(0, &(events_JOIN_LEFTSEMI_TD_9665435), &(events_d2h_rd_JOIN_LEFTSEMI_TD_9665435[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_LEFTSEMI_9_463775_e, 0);

    struct timeval tv_r_JOIN_INNER_9_942180_s, tv_r_JOIN_INNER_9_942180_e;
    gettimeofday(&tv_r_JOIN_INNER_9_942180_s, 0);
    SW_JOIN_INNER_TD_9257061(tbl_Filter_TD_10307030_output, tbl_Filter_TD_10874105_output, tbl_JOIN_INNER_TD_9257061_output);
    gettimeofday(&tv_r_JOIN_INNER_9_942180_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_8_799399_s, tv_r_JOIN_LEFTSEMI_8_799399_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_8_799399_s, 0);
    trans_JOIN_LEFTSEMI_TD_8762305.add(&(tbl_Filter_TD_9498299_output));
    trans_JOIN_LEFTSEMI_TD_8762305.add(&(tbl_Filter_TD_9246886_output));
    trans_JOIN_LEFTSEMI_TD_8762305.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_8762305), &(events_h2d_wr_JOIN_LEFTSEMI_TD_8762305[0]));
    events_grp_JOIN_LEFTSEMI_TD_8762305.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_8762305[0]);
    krnl_JOIN_LEFTSEMI_TD_8762305.run(0, &(events_grp_JOIN_LEFTSEMI_TD_8762305), &(events_JOIN_LEFTSEMI_TD_8762305[0]));
    
    trans_JOIN_LEFTSEMI_TD_8762305_out.add(&(tbl_JOIN_LEFTSEMI_TD_8762305_output));
    trans_JOIN_LEFTSEMI_TD_8762305_out.dev2host(0, &(events_JOIN_LEFTSEMI_TD_8762305), &(events_d2h_rd_JOIN_LEFTSEMI_TD_8762305[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_LEFTSEMI_8_799399_e, 0);

    struct timeval tv_r_JOIN_INNER_8_296528_s, tv_r_JOIN_INNER_8_296528_e;
    gettimeofday(&tv_r_JOIN_INNER_8_296528_s, 0);
    SW_JOIN_INNER_TD_8660771(tbl_Filter_TD_9823304_output, tbl_Filter_TD_9910098_output, tbl_JOIN_INNER_TD_8660771_output);
    gettimeofday(&tv_r_JOIN_INNER_8_296528_e, 0);

    struct timeval tv_r_JOIN_INNER_8_375241_s, tv_r_JOIN_INNER_8_375241_e;
    gettimeofday(&tv_r_JOIN_INNER_8_375241_s, 0);
    SW_JOIN_INNER_TD_8153793(tbl_JOIN_INNER_TD_9827406_output, tbl_JOIN_LEFTSEMI_TD_9390391_output, tbl_JOIN_INNER_TD_8153793_output);
    gettimeofday(&tv_r_JOIN_INNER_8_375241_e, 0);

    struct timeval tv_r_JOIN_INNER_8_32508_s, tv_r_JOIN_INNER_8_32508_e;
    gettimeofday(&tv_r_JOIN_INNER_8_32508_s, 0);
    SW_JOIN_INNER_TD_8556613(tbl_JOIN_INNER_TD_9257061_output, tbl_JOIN_LEFTSEMI_TD_9665435_output, tbl_JOIN_INNER_TD_8556613_output);
    gettimeofday(&tv_r_JOIN_INNER_8_32508_e, 0);

    struct timeval tv_r_JOIN_INNER_7_674085_s, tv_r_JOIN_INNER_7_674085_e;
    gettimeofday(&tv_r_JOIN_INNER_7_674085_s, 0);
    SW_JOIN_INNER_TD_7624743(tbl_JOIN_INNER_TD_8660771_output, tbl_JOIN_LEFTSEMI_TD_8762305_output, tbl_JOIN_INNER_TD_7624743_output);
    gettimeofday(&tv_r_JOIN_INNER_7_674085_e, 0);

    struct timeval tv_r_Aggregate_7_522826_s, tv_r_Aggregate_7_522826_e;
    gettimeofday(&tv_r_Aggregate_7_522826_s, 0);
    SW_Aggregate_TD_7558107(tbl_JOIN_INNER_TD_8153793_output, tbl_Aggregate_TD_7558107_output);
    gettimeofday(&tv_r_Aggregate_7_522826_e, 0);

    struct timeval tv_r_Aggregate_7_711447_s, tv_r_Aggregate_7_711447_e;
    gettimeofday(&tv_r_Aggregate_7_711447_s, 0);
    SW_Aggregate_TD_7578458(tbl_JOIN_INNER_TD_8556613_output, tbl_Aggregate_TD_7578458_output);
    gettimeofday(&tv_r_Aggregate_7_711447_e, 0);

    struct timeval tv_r_Aggregate_6_579418_s, tv_r_Aggregate_6_579418_e;
    gettimeofday(&tv_r_Aggregate_6_579418_s, 0);
    SW_Aggregate_TD_6612499(tbl_JOIN_INNER_TD_7624743_output, tbl_Aggregate_TD_6612499_output);
    gettimeofday(&tv_r_Aggregate_6_579418_e, 0);

    struct timeval tv_r_Filter_6_149422_s, tv_r_Filter_6_149422_e;
    gettimeofday(&tv_r_Filter_6_149422_s, 0);
    SW_Filter_TD_6473482(tbl_Aggregate_TD_7558107_output, tbl_Filter_TD_6473482_output);
    gettimeofday(&tv_r_Filter_6_149422_e, 0);

    struct timeval tv_r_Filter_6_56772_s, tv_r_Filter_6_56772_e;
    gettimeofday(&tv_r_Filter_6_56772_s, 0);
    SW_Filter_TD_6913275(tbl_Aggregate_TD_7578458_output, tbl_Filter_TD_6913275_output);
    gettimeofday(&tv_r_Filter_6_56772_e, 0);

    struct timeval tv_r_Filter_5_177048_s, tv_r_Filter_5_177048_e;
    gettimeofday(&tv_r_Filter_5_177048_s, 0);
    SW_Filter_TD_5974239(tbl_Aggregate_TD_6612499_output, tbl_Filter_TD_5974239_output);
    gettimeofday(&tv_r_Filter_5_177048_e, 0);

    struct timeval tv_r_JOIN_INNER_5_199272_s, tv_r_JOIN_INNER_5_199272_e;
    gettimeofday(&tv_r_JOIN_INNER_5_199272_s, 0);
    SW_JOIN_INNER_TD_5246198(tbl_Filter_TD_6913275_output, tbl_Filter_TD_6473482_output, tbl_JOIN_INNER_TD_5246198_output);
    gettimeofday(&tv_r_JOIN_INNER_5_199272_e, 0);

    struct timeval tv_r_JOIN_INNER_4_766948_s, tv_r_JOIN_INNER_4_766948_e;
    gettimeofday(&tv_r_JOIN_INNER_4_766948_s, 0);
    SW_JOIN_INNER_TD_4925555(tbl_JOIN_INNER_TD_5246198_output, tbl_Filter_TD_5974239_output, tbl_JOIN_INNER_TD_4925555_output);
    gettimeofday(&tv_r_JOIN_INNER_4_766948_e, 0);

    struct timeval tv_r_Project_3_349303_s, tv_r_Project_3_349303_e;
    gettimeofday(&tv_r_Project_3_349303_s, 0);
    SW_Project_TD_3107127(tbl_JOIN_INNER_TD_4925555_output, tbl_Project_TD_3107127_output);
    gettimeofday(&tv_r_Project_3_349303_e, 0);

    struct timeval tv_r_Sort_2_490340_s, tv_r_Sort_2_490340_e;
    gettimeofday(&tv_r_Sort_2_490340_s, 0);
    SW_Sort_TD_2284597(tbl_Project_TD_3107127_output, tbl_Sort_TD_2284597_output);
    gettimeofday(&tv_r_Sort_2_490340_e, 0);

    struct timeval tv_r_LocalLimit_1_840288_s, tv_r_LocalLimit_1_840288_e;
    gettimeofday(&tv_r_LocalLimit_1_840288_s, 0);
    SW_LocalLimit_TD_1544112(tbl_Sort_TD_2284597_output, tbl_LocalLimit_TD_1544112_output);
    gettimeofday(&tv_r_LocalLimit_1_840288_e, 0);

    struct timeval tv_r_GlobalLimit_0_439488_s, tv_r_GlobalLimit_0_439488_e;
    gettimeofday(&tv_r_GlobalLimit_0_439488_s, 0);
    SW_GlobalLimit_TD_0582834(tbl_LocalLimit_TD_1544112_output, tbl_GlobalLimit_TD_0582834_output);
    gettimeofday(&tv_r_GlobalLimit_0_439488_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_248259_s, &tv_r_Filter_11_248259_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12123737_input: " << tbl_SerializeFromObject_TD_12123737_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_425311_s, &tv_r_Filter_11_425311_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12250840_input: " << tbl_SerializeFromObject_TD_12250840_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_555683_s, &tv_r_Filter_10_555683_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11990241_input: " << tbl_SerializeFromObject_TD_11990241_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_989340_s, &tv_r_Filter_10_989340_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11717880_input: " << tbl_SerializeFromObject_TD_11717880_input.getNumRow() << " " << "tbl_Filter_TD_11372705_output: " << tbl_Filter_TD_11372705_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_895116_s, &tv_r_Filter_10_895116_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11249605_input: " << tbl_SerializeFromObject_TD_11249605_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_403727_s, &tv_r_Filter_10_403727_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11217812_input: " << tbl_SerializeFromObject_TD_11217812_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_948078_s, &tv_r_Filter_10_948078_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11835059_input: " << tbl_SerializeFromObject_TD_11835059_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_952860_s, &tv_r_Filter_10_952860_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11933280_input: " << tbl_SerializeFromObject_TD_11933280_input.getNumRow() << " " << "tbl_Filter_TD_11442474_output: " << tbl_Filter_TD_11442474_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_456620_s, &tv_r_Filter_10_456620_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11801816_input: " << tbl_SerializeFromObject_TD_11801816_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_626066_s, &tv_r_Filter_10_626066_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1127514_input: " << tbl_SerializeFromObject_TD_1127514_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_510281_s, &tv_r_Filter_10_510281_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11147263_input: " << tbl_SerializeFromObject_TD_11147263_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_512601_s, &tv_r_Filter_9_512601_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10133961_input: " << tbl_SerializeFromObject_TD_10133961_input.getNumRow() << " " << "tbl_Filter_TD_10185589_output: " << tbl_Filter_TD_10185589_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_272174_s, &tv_r_Filter_9_272174_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10808018_input: " << tbl_SerializeFromObject_TD_10808018_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_565186_s, &tv_r_Filter_9_565186_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10749887_input: " << tbl_SerializeFromObject_TD_10749887_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_200608_s, &tv_r_Filter_9_200608_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10556762_input: " << tbl_SerializeFromObject_TD_10556762_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_9: " << tvdiff(&tv_r_JOIN_LEFTSEMI_9_960510_s, &tv_r_JOIN_LEFTSEMI_9_960510_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10511021_output: " << tbl_Filter_TD_10511021_output.getNumRow() << " " << "tbl_Filter_TD_10563997_output: " << tbl_Filter_TD_10563997_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_984347_s, &tv_r_JOIN_INNER_9_984347_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10649710_output: " << tbl_Filter_TD_10649710_output.getNumRow() << " " << "tbl_Filter_TD_10143311_output: " << tbl_Filter_TD_10143311_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_9: " << tvdiff(&tv_r_JOIN_LEFTSEMI_9_463775_s, &tv_r_JOIN_LEFTSEMI_9_463775_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_1092114_output: " << tbl_Filter_TD_1092114_output.getNumRow() << " " << "tbl_Filter_TD_1072639_output: " << tbl_Filter_TD_1072639_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_942180_s, &tv_r_JOIN_INNER_9_942180_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10307030_output: " << tbl_Filter_TD_10307030_output.getNumRow() << " " << "tbl_Filter_TD_10874105_output: " << tbl_Filter_TD_10874105_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_8: " << tvdiff(&tv_r_JOIN_LEFTSEMI_8_799399_s, &tv_r_JOIN_LEFTSEMI_8_799399_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9498299_output: " << tbl_Filter_TD_9498299_output.getNumRow() << " " << "tbl_Filter_TD_9246886_output: " << tbl_Filter_TD_9246886_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_296528_s, &tv_r_JOIN_INNER_8_296528_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9823304_output: " << tbl_Filter_TD_9823304_output.getNumRow() << " " << "tbl_Filter_TD_9910098_output: " << tbl_Filter_TD_9910098_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_375241_s, &tv_r_JOIN_INNER_8_375241_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9827406_output: " << tbl_JOIN_INNER_TD_9827406_output.getNumRow() << " " << "tbl_JOIN_LEFTSEMI_TD_9390391_output: " << tbl_JOIN_LEFTSEMI_TD_9390391_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_32508_s, &tv_r_JOIN_INNER_8_32508_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9257061_output: " << tbl_JOIN_INNER_TD_9257061_output.getNumRow() << " " << "tbl_JOIN_LEFTSEMI_TD_9665435_output: " << tbl_JOIN_LEFTSEMI_TD_9665435_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_674085_s, &tv_r_JOIN_INNER_7_674085_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8660771_output: " << tbl_JOIN_INNER_TD_8660771_output.getNumRow() << " " << "tbl_JOIN_LEFTSEMI_TD_8762305_output: " << tbl_JOIN_LEFTSEMI_TD_8762305_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_7: " << tvdiff(&tv_r_Aggregate_7_522826_s, &tv_r_Aggregate_7_522826_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8153793_output: " << tbl_JOIN_INNER_TD_8153793_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_7: " << tvdiff(&tv_r_Aggregate_7_711447_s, &tv_r_Aggregate_7_711447_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8556613_output: " << tbl_JOIN_INNER_TD_8556613_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_6: " << tvdiff(&tv_r_Aggregate_6_579418_s, &tv_r_Aggregate_6_579418_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7624743_output: " << tbl_JOIN_INNER_TD_7624743_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_149422_s, &tv_r_Filter_6_149422_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_7558107_output: " << tbl_Aggregate_TD_7558107_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_56772_s, &tv_r_Filter_6_56772_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_7578458_output: " << tbl_Aggregate_TD_7578458_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_177048_s, &tv_r_Filter_5_177048_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_6612499_output: " << tbl_Aggregate_TD_6612499_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_199272_s, &tv_r_JOIN_INNER_5_199272_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6913275_output: " << tbl_Filter_TD_6913275_output.getNumRow() << " " << "tbl_Filter_TD_6473482_output: " << tbl_Filter_TD_6473482_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_766948_s, &tv_r_JOIN_INNER_4_766948_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5246198_output: " << tbl_JOIN_INNER_TD_5246198_output.getNumRow() << " " << "tbl_Filter_TD_5974239_output: " << tbl_Filter_TD_5974239_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_3: " << tvdiff(&tv_r_Project_3_349303_s, &tv_r_Project_3_349303_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4925555_output: " << tbl_JOIN_INNER_TD_4925555_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_490340_s, &tv_r_Sort_2_490340_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_3107127_output: " << tbl_Project_TD_3107127_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_840288_s, &tv_r_LocalLimit_1_840288_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2284597_output: " << tbl_Sort_TD_2284597_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_439488_s, &tv_r_GlobalLimit_0_439488_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1544112_output: " << tbl_LocalLimit_TD_1544112_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 3.6722064 * 1000 << "ms" << std::endl; 
    return 0; 
}
