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

#include "cfgFunc_q49.hpp" 
#include "q49.hpp" 

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
    std::cout << "NOTE:running query #49\n."; 
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
    Table tbl_GlobalLimit_TD_0829867_output("tbl_GlobalLimit_TD_0829867_output", 6100000, 5, "");
    tbl_GlobalLimit_TD_0829867_output.allocateHost();
    Table tbl_LocalLimit_TD_1425520_output("tbl_LocalLimit_TD_1425520_output", 6100000, 5, "");
    tbl_LocalLimit_TD_1425520_output.allocateHost();
    Table tbl_Sort_TD_2554921_output("tbl_Sort_TD_2554921_output", 6100000, 5, "");
    tbl_Sort_TD_2554921_output.allocateHost();
    Table tbl_Aggregate_TD_3792164_output("tbl_Aggregate_TD_3792164_output", 6100000, 5, "");
    tbl_Aggregate_TD_3792164_output.allocateHost();
    Table tbl_Union_TD_4632723_output("tbl_Union_TD_4632723_output", 6100000, 5, "");
    tbl_Union_TD_4632723_output.allocateHost();
    Table tbl_Project_TD_539447_output("tbl_Project_TD_539447_output", 6100000, 5, "");
    tbl_Project_TD_539447_output.allocateHost();
    Table tbl_Project_TD_5226488_output("tbl_Project_TD_5226488_output", 6100000, 5, "");
    tbl_Project_TD_5226488_output.allocateHost();
    Table tbl_Project_TD_5936868_output("tbl_Project_TD_5936868_output", 6100000, 5, "");
    tbl_Project_TD_5936868_output.allocateHost();
    Table tbl_Filter_TD_6372096_output("tbl_Filter_TD_6372096_output", 6100000, 4, "");
    tbl_Filter_TD_6372096_output.allocateHost();
    Table tbl_Filter_TD_6282526_output("tbl_Filter_TD_6282526_output", 6100000, 4, "");
    tbl_Filter_TD_6282526_output.allocateHost();
    Table tbl_Filter_TD_6959809_output("tbl_Filter_TD_6959809_output", 6100000, 4, "");
    tbl_Filter_TD_6959809_output.allocateHost();
    Table tbl_Window_TD_7299122_output("tbl_Window_TD_7299122_output", 6100000, 5, "");
    tbl_Window_TD_7299122_output.allocateHost();
    Table tbl_Window_TD_7394613_output("tbl_Window_TD_7394613_output", 6100000, 5, "");
    tbl_Window_TD_7394613_output.allocateHost();
    Table tbl_Window_TD_7606668_output("tbl_Window_TD_7606668_output", 6100000, 5, "");
    tbl_Window_TD_7606668_output.allocateHost();
    Table tbl_Window_TD_8875475_output("tbl_Window_TD_8875475_output", 6100000, 4, "");
    tbl_Window_TD_8875475_output.allocateHost();
    Table tbl_Window_TD_8431871_output("tbl_Window_TD_8431871_output", 6100000, 4, "");
    tbl_Window_TD_8431871_output.allocateHost();
    Table tbl_Window_TD_8967856_output("tbl_Window_TD_8967856_output", 6100000, 4, "");
    tbl_Window_TD_8967856_output.allocateHost();
    Table tbl_Aggregate_TD_9541230_output("tbl_Aggregate_TD_9541230_output", 6100000, 3, "");
    tbl_Aggregate_TD_9541230_output.allocateHost();
    Table tbl_Aggregate_TD_9138966_output("tbl_Aggregate_TD_9138966_output", 6100000, 3, "");
    tbl_Aggregate_TD_9138966_output.allocateHost();
    Table tbl_Aggregate_TD_9243762_output("tbl_Aggregate_TD_9243762_output", 6100000, 3, "");
    tbl_Aggregate_TD_9243762_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10424443_output("tbl_JOIN_INNER_TD_10424443_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_10424443_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10288240_output("tbl_JOIN_INNER_TD_10288240_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_10288240_output.allocateHost();
    Table tbl_JOIN_INNER_TD_10213953_output("tbl_JOIN_INNER_TD_10213953_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_10213953_output.allocateHost();
    Table tbl_JOIN_INNER_TD_11320265_output("tbl_JOIN_INNER_TD_11320265_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_11320265_output.allocateHost();
    Table tbl_Filter_TD_11726296_output("tbl_Filter_TD_11726296_output", 6100000, 1, "");
    tbl_Filter_TD_11726296_output.allocateHost();
    Table tbl_JOIN_INNER_TD_11730313_output("tbl_JOIN_INNER_TD_11730313_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_11730313_output.allocateHost();
    Table tbl_Filter_TD_11206071_output("tbl_Filter_TD_11206071_output", 6100000, 1, "");
    tbl_Filter_TD_11206071_output.allocateHost();
    Table tbl_JOIN_INNER_TD_11800726_output("tbl_JOIN_INNER_TD_11800726_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_11800726_output.allocateHost();
    Table tbl_Filter_TD_11834944_output("tbl_Filter_TD_11834944_output", 6100000, 1, "");
    tbl_Filter_TD_11834944_output.allocateHost();
    Table tbl_Filter_TD_12973526_output("tbl_Filter_TD_12973526_output", 6100000, 5, "");
    tbl_Filter_TD_12973526_output.allocateHost();
    Table tbl_Filter_TD_12826276_output("tbl_Filter_TD_12826276_output", 6100000, 4, "");
    tbl_Filter_TD_12826276_output.allocateHost();
    Table tbl_SerializeFromObject_TD_12604243_input;
    tbl_SerializeFromObject_TD_12604243_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_12604243_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_12604243_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_12604243_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_12604243_input.allocateHost();
    tbl_SerializeFromObject_TD_12604243_input.loadHost();
    Table tbl_Filter_TD_1256418_output("tbl_Filter_TD_1256418_output", 6100000, 5, "");
    tbl_Filter_TD_1256418_output.allocateHost();
    Table tbl_Filter_TD_12994471_output("tbl_Filter_TD_12994471_output", 6100000, 4, "");
    tbl_Filter_TD_12994471_output.allocateHost();
    Table tbl_SerializeFromObject_TD_12297946_input;
    tbl_SerializeFromObject_TD_12297946_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_12297946_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_12297946_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_12297946_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_12297946_input.allocateHost();
    tbl_SerializeFromObject_TD_12297946_input.loadHost();
    Table tbl_Filter_TD_12459707_output("tbl_Filter_TD_12459707_output", 6100000, 5, "");
    tbl_Filter_TD_12459707_output.allocateHost();
    Table tbl_Filter_TD_1293473_output("tbl_Filter_TD_1293473_output", 6100000, 4, "");
    tbl_Filter_TD_1293473_output.allocateHost();
    Table tbl_SerializeFromObject_TD_12915351_input;
    tbl_SerializeFromObject_TD_12915351_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_12915351_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_12915351_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_12915351_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_12915351_input.allocateHost();
    tbl_SerializeFromObject_TD_12915351_input.loadHost();
    Table tbl_SerializeFromObject_TD_13473325_input;
    tbl_SerializeFromObject_TD_13473325_input = Table("web_sales", web_sales_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_13473325_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_13473325_input.addCol("ws_item_sk", 4);
    tbl_SerializeFromObject_TD_13473325_input.addCol("ws_order_number", 8);
    tbl_SerializeFromObject_TD_13473325_input.addCol("ws_quantity", 4);
    tbl_SerializeFromObject_TD_13473325_input.addCol("ws_net_paid", 4);
    tbl_SerializeFromObject_TD_13473325_input.addCol("ws_net_profit", 4);
    tbl_SerializeFromObject_TD_13473325_input.allocateHost();
    tbl_SerializeFromObject_TD_13473325_input.loadHost();
    Table tbl_SerializeFromObject_TD_13706169_input;
    tbl_SerializeFromObject_TD_13706169_input = Table("web_returns", web_returns_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_13706169_input.addCol("wr_item_sk", 4);
    tbl_SerializeFromObject_TD_13706169_input.addCol("wr_order_number", 8);
    tbl_SerializeFromObject_TD_13706169_input.addCol("wr_return_quantity", 4);
    tbl_SerializeFromObject_TD_13706169_input.addCol("wr_return_amt", 4);
    tbl_SerializeFromObject_TD_13706169_input.allocateHost();
    tbl_SerializeFromObject_TD_13706169_input.loadHost();
    Table tbl_SerializeFromObject_TD_13640436_input;
    tbl_SerializeFromObject_TD_13640436_input = Table("catalog_sales", catalog_sales_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_13640436_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_13640436_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_13640436_input.addCol("cs_order_number", 8);
    tbl_SerializeFromObject_TD_13640436_input.addCol("cs_quantity", 4);
    tbl_SerializeFromObject_TD_13640436_input.addCol("cs_net_paid", 4);
    tbl_SerializeFromObject_TD_13640436_input.addCol("cs_net_profit", 4);
    tbl_SerializeFromObject_TD_13640436_input.allocateHost();
    tbl_SerializeFromObject_TD_13640436_input.loadHost();
    Table tbl_SerializeFromObject_TD_13648727_input;
    tbl_SerializeFromObject_TD_13648727_input = Table("catalog_returns", catalog_returns_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_13648727_input.addCol("cr_item_sk", 4);
    tbl_SerializeFromObject_TD_13648727_input.addCol("cr_order_number", 8);
    tbl_SerializeFromObject_TD_13648727_input.addCol("cr_return_quantity", 4);
    tbl_SerializeFromObject_TD_13648727_input.addCol("cr_return_amount", 4);
    tbl_SerializeFromObject_TD_13648727_input.allocateHost();
    tbl_SerializeFromObject_TD_13648727_input.loadHost();
    Table tbl_SerializeFromObject_TD_13589665_input;
    tbl_SerializeFromObject_TD_13589665_input = Table("store_sales", store_sales_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_13589665_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_13589665_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_13589665_input.addCol("ss_ticket_number", 8);
    tbl_SerializeFromObject_TD_13589665_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_13589665_input.addCol("ss_net_paid", 4);
    tbl_SerializeFromObject_TD_13589665_input.addCol("ss_net_profit", 4);
    tbl_SerializeFromObject_TD_13589665_input.allocateHost();
    tbl_SerializeFromObject_TD_13589665_input.loadHost();
    Table tbl_SerializeFromObject_TD_13279940_input;
    tbl_SerializeFromObject_TD_13279940_input = Table("store_returns", store_returns_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_13279940_input.addCol("sr_item_sk", 4);
    tbl_SerializeFromObject_TD_13279940_input.addCol("sr_ticket_number", 8);
    tbl_SerializeFromObject_TD_13279940_input.addCol("sr_return_quantity", 4);
    tbl_SerializeFromObject_TD_13279940_input.addCol("sr_return_amt", 4);
    tbl_SerializeFromObject_TD_13279940_input.allocateHost();
    tbl_SerializeFromObject_TD_13279940_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_10424443_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_10288240_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_10213953_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_11320265_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11726296_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_11730313_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11206071_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_11800726_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_11834944_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_12973526_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_12826276_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_1256418_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_12994471_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_12459707_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_1293473_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_10424443_cmds;
    cfg_JOIN_INNER_TD_10424443_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_10424443_gqe_join (cfg_JOIN_INNER_TD_10424443_cmds.cmd);
    cfg_JOIN_INNER_TD_10424443_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_10288240_cmds;
    cfg_JOIN_INNER_TD_10288240_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_10288240_gqe_join (cfg_JOIN_INNER_TD_10288240_cmds.cmd);
    cfg_JOIN_INNER_TD_10288240_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_10213953_cmds;
    cfg_JOIN_INNER_TD_10213953_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_10213953_gqe_join (cfg_JOIN_INNER_TD_10213953_cmds.cmd);
    cfg_JOIN_INNER_TD_10213953_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_11320265_cmds;
    cfg_JOIN_INNER_TD_11320265_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_11320265_gqe_join (cfg_JOIN_INNER_TD_11320265_cmds.cmd);
    cfg_JOIN_INNER_TD_11320265_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_11730313_cmds;
    cfg_JOIN_INNER_TD_11730313_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_11730313_gqe_join (cfg_JOIN_INNER_TD_11730313_cmds.cmd);
    cfg_JOIN_INNER_TD_11730313_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_11800726_cmds;
    cfg_JOIN_INNER_TD_11800726_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_11800726_gqe_join (cfg_JOIN_INNER_TD_11800726_cmds.cmd);
    cfg_JOIN_INNER_TD_11800726_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_10424443;
    krnl_JOIN_INNER_TD_10424443 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_10424443.setup(tbl_JOIN_INNER_TD_11320265_output, tbl_Filter_TD_11726296_output, tbl_JOIN_INNER_TD_10424443_output, cfg_JOIN_INNER_TD_10424443_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_10288240;
    krnl_JOIN_INNER_TD_10288240 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_10288240.setup(tbl_JOIN_INNER_TD_11730313_output, tbl_Filter_TD_11206071_output, tbl_JOIN_INNER_TD_10288240_output, cfg_JOIN_INNER_TD_10288240_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_10213953;
    krnl_JOIN_INNER_TD_10213953 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_10213953.setup(tbl_JOIN_INNER_TD_11800726_output, tbl_Filter_TD_11834944_output, tbl_JOIN_INNER_TD_10213953_output, cfg_JOIN_INNER_TD_10213953_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_11320265;
    krnl_JOIN_INNER_TD_11320265 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_11320265.setup(tbl_Filter_TD_12973526_output, tbl_Filter_TD_12826276_output, tbl_JOIN_INNER_TD_11320265_output, cfg_JOIN_INNER_TD_11320265_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_11730313;
    krnl_JOIN_INNER_TD_11730313 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_11730313.setup(tbl_Filter_TD_1256418_output, tbl_Filter_TD_12994471_output, tbl_JOIN_INNER_TD_11730313_output, cfg_JOIN_INNER_TD_11730313_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_11800726;
    krnl_JOIN_INNER_TD_11800726 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_11800726.setup(tbl_Filter_TD_12459707_output, tbl_Filter_TD_1293473_output, tbl_JOIN_INNER_TD_11800726_output, cfg_JOIN_INNER_TD_11800726_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_10424443;
    trans_JOIN_INNER_TD_10424443.setq(q_h);
    trans_JOIN_INNER_TD_10424443.add(&(cfg_JOIN_INNER_TD_10424443_cmds));
    transEngine trans_JOIN_INNER_TD_10424443_out;
    trans_JOIN_INNER_TD_10424443_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_10288240;
    trans_JOIN_INNER_TD_10288240.setq(q_h);
    trans_JOIN_INNER_TD_10288240.add(&(cfg_JOIN_INNER_TD_10288240_cmds));
    transEngine trans_JOIN_INNER_TD_10288240_out;
    trans_JOIN_INNER_TD_10288240_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_10213953;
    trans_JOIN_INNER_TD_10213953.setq(q_h);
    trans_JOIN_INNER_TD_10213953.add(&(cfg_JOIN_INNER_TD_10213953_cmds));
    transEngine trans_JOIN_INNER_TD_10213953_out;
    trans_JOIN_INNER_TD_10213953_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_11320265;
    trans_JOIN_INNER_TD_11320265.setq(q_h);
    trans_JOIN_INNER_TD_11320265.add(&(cfg_JOIN_INNER_TD_11320265_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_11730313;
    trans_JOIN_INNER_TD_11730313.setq(q_h);
    trans_JOIN_INNER_TD_11730313.add(&(cfg_JOIN_INNER_TD_11730313_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_11800726;
    trans_JOIN_INNER_TD_11800726.setq(q_h);
    trans_JOIN_INNER_TD_11800726.add(&(cfg_JOIN_INNER_TD_11800726_cmds));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_10424443;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_10424443;
    std::vector<cl::Event> events_JOIN_INNER_TD_10424443;
    events_h2d_wr_JOIN_INNER_TD_10424443.resize(1);
    events_d2h_rd_JOIN_INNER_TD_10424443.resize(1);
    events_JOIN_INNER_TD_10424443.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_10424443;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_10424443;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_10288240;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_10288240;
    std::vector<cl::Event> events_JOIN_INNER_TD_10288240;
    events_h2d_wr_JOIN_INNER_TD_10288240.resize(1);
    events_d2h_rd_JOIN_INNER_TD_10288240.resize(1);
    events_JOIN_INNER_TD_10288240.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_10288240;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_10288240;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_10213953;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_10213953;
    std::vector<cl::Event> events_JOIN_INNER_TD_10213953;
    events_h2d_wr_JOIN_INNER_TD_10213953.resize(1);
    events_d2h_rd_JOIN_INNER_TD_10213953.resize(1);
    events_JOIN_INNER_TD_10213953.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_10213953;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_10213953;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_11320265;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_11320265;
    std::vector<cl::Event> events_JOIN_INNER_TD_11320265;
    events_h2d_wr_JOIN_INNER_TD_11320265.resize(1);
    events_d2h_rd_JOIN_INNER_TD_11320265.resize(1);
    events_JOIN_INNER_TD_11320265.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_11320265;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_11320265;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_11730313;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_11730313;
    std::vector<cl::Event> events_JOIN_INNER_TD_11730313;
    events_h2d_wr_JOIN_INNER_TD_11730313.resize(1);
    events_d2h_rd_JOIN_INNER_TD_11730313.resize(1);
    events_JOIN_INNER_TD_11730313.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_11730313;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_11730313;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_11800726;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_11800726;
    std::vector<cl::Event> events_JOIN_INNER_TD_11800726;
    events_h2d_wr_JOIN_INNER_TD_11800726.resize(1);
    events_d2h_rd_JOIN_INNER_TD_11800726.resize(1);
    events_JOIN_INNER_TD_11800726.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_11800726;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_11800726;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_12_549328_s, tv_r_Filter_12_549328_e;
    gettimeofday(&tv_r_Filter_12_549328_s, 0);
    SW_Filter_TD_1293473(tbl_SerializeFromObject_TD_13279940_input, tbl_Filter_TD_1293473_output);
    gettimeofday(&tv_r_Filter_12_549328_e, 0);

    struct timeval tv_r_Filter_12_34338_s, tv_r_Filter_12_34338_e;
    gettimeofday(&tv_r_Filter_12_34338_s, 0);
    SW_Filter_TD_12459707(tbl_SerializeFromObject_TD_13589665_input, tbl_Filter_TD_12459707_output);
    gettimeofday(&tv_r_Filter_12_34338_e, 0);

    struct timeval tv_r_Filter_12_518917_s, tv_r_Filter_12_518917_e;
    gettimeofday(&tv_r_Filter_12_518917_s, 0);
    SW_Filter_TD_12994471(tbl_SerializeFromObject_TD_13648727_input, tbl_Filter_TD_12994471_output);
    gettimeofday(&tv_r_Filter_12_518917_e, 0);

    struct timeval tv_r_Filter_12_841039_s, tv_r_Filter_12_841039_e;
    gettimeofday(&tv_r_Filter_12_841039_s, 0);
    SW_Filter_TD_1256418(tbl_SerializeFromObject_TD_13640436_input, tbl_Filter_TD_1256418_output);
    gettimeofday(&tv_r_Filter_12_841039_e, 0);

    struct timeval tv_r_Filter_12_571277_s, tv_r_Filter_12_571277_e;
    gettimeofday(&tv_r_Filter_12_571277_s, 0);
    SW_Filter_TD_12826276(tbl_SerializeFromObject_TD_13706169_input, tbl_Filter_TD_12826276_output);
    gettimeofday(&tv_r_Filter_12_571277_e, 0);

    struct timeval tv_r_Filter_12_599637_s, tv_r_Filter_12_599637_e;
    gettimeofday(&tv_r_Filter_12_599637_s, 0);
    SW_Filter_TD_12973526(tbl_SerializeFromObject_TD_13473325_input, tbl_Filter_TD_12973526_output);
    gettimeofday(&tv_r_Filter_12_599637_e, 0);

    struct timeval tv_r_Filter_11_768506_s, tv_r_Filter_11_768506_e;
    gettimeofday(&tv_r_Filter_11_768506_s, 0);
    SW_Filter_TD_11834944(tbl_SerializeFromObject_TD_12915351_input, tbl_Filter_TD_11834944_output);
    gettimeofday(&tv_r_Filter_11_768506_e, 0);

    struct timeval tv_r_JOIN_INNER_11_396662_s, tv_r_JOIN_INNER_11_396662_e;
    gettimeofday(&tv_r_JOIN_INNER_11_396662_s, 0);
    trans_JOIN_INNER_TD_11800726.add(&(tbl_Filter_TD_12459707_output));
    trans_JOIN_INNER_TD_11800726.add(&(tbl_Filter_TD_1293473_output));
    trans_JOIN_INNER_TD_11800726.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_11800726), &(events_h2d_wr_JOIN_INNER_TD_11800726[0]));
    events_grp_JOIN_INNER_TD_11800726.push_back(events_h2d_wr_JOIN_INNER_TD_11800726[0]);
    krnl_JOIN_INNER_TD_11800726.run(0, &(events_grp_JOIN_INNER_TD_11800726), &(events_JOIN_INNER_TD_11800726[0]));
    gettimeofday(&tv_r_JOIN_INNER_11_396662_e, 0);

    struct timeval tv_r_Filter_11_570908_s, tv_r_Filter_11_570908_e;
    gettimeofday(&tv_r_Filter_11_570908_s, 0);
    SW_Filter_TD_11206071(tbl_SerializeFromObject_TD_12297946_input, tbl_Filter_TD_11206071_output);
    gettimeofday(&tv_r_Filter_11_570908_e, 0);

    struct timeval tv_r_JOIN_INNER_11_606321_s, tv_r_JOIN_INNER_11_606321_e;
    gettimeofday(&tv_r_JOIN_INNER_11_606321_s, 0);
    trans_JOIN_INNER_TD_11730313.add(&(tbl_Filter_TD_1256418_output));
    trans_JOIN_INNER_TD_11730313.add(&(tbl_Filter_TD_12994471_output));
    trans_JOIN_INNER_TD_11730313.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_11730313), &(events_h2d_wr_JOIN_INNER_TD_11730313[0]));
    events_grp_JOIN_INNER_TD_11730313.push_back(events_h2d_wr_JOIN_INNER_TD_11730313[0]);
    krnl_JOIN_INNER_TD_11730313.run(0, &(events_grp_JOIN_INNER_TD_11730313), &(events_JOIN_INNER_TD_11730313[0]));
    gettimeofday(&tv_r_JOIN_INNER_11_606321_e, 0);

    struct timeval tv_r_Filter_11_90858_s, tv_r_Filter_11_90858_e;
    gettimeofday(&tv_r_Filter_11_90858_s, 0);
    SW_Filter_TD_11726296(tbl_SerializeFromObject_TD_12604243_input, tbl_Filter_TD_11726296_output);
    gettimeofday(&tv_r_Filter_11_90858_e, 0);

    struct timeval tv_r_JOIN_INNER_11_185221_s, tv_r_JOIN_INNER_11_185221_e;
    gettimeofday(&tv_r_JOIN_INNER_11_185221_s, 0);
    trans_JOIN_INNER_TD_11320265.add(&(tbl_Filter_TD_12973526_output));
    trans_JOIN_INNER_TD_11320265.add(&(tbl_Filter_TD_12826276_output));
    trans_JOIN_INNER_TD_11320265.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_11320265), &(events_h2d_wr_JOIN_INNER_TD_11320265[0]));
    events_grp_JOIN_INNER_TD_11320265.push_back(events_h2d_wr_JOIN_INNER_TD_11320265[0]);
    krnl_JOIN_INNER_TD_11320265.run(0, &(events_grp_JOIN_INNER_TD_11320265), &(events_JOIN_INNER_TD_11320265[0]));
    gettimeofday(&tv_r_JOIN_INNER_11_185221_e, 0);

    struct timeval tv_r_JOIN_INNER_10_878118_s, tv_r_JOIN_INNER_10_878118_e;
    gettimeofday(&tv_r_JOIN_INNER_10_878118_s, 0);
    prev_events_grp_JOIN_INNER_TD_10213953.push_back(events_h2d_wr_JOIN_INNER_TD_11800726[0]);
    trans_JOIN_INNER_TD_10213953.add(&(tbl_Filter_TD_11834944_output));
    trans_JOIN_INNER_TD_10213953.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_10213953), &(events_h2d_wr_JOIN_INNER_TD_10213953[0]));
    events_grp_JOIN_INNER_TD_10213953.push_back(events_h2d_wr_JOIN_INNER_TD_10213953[0]);
    events_grp_JOIN_INNER_TD_10213953.push_back(events_JOIN_INNER_TD_11800726[0]);
    krnl_JOIN_INNER_TD_10213953.run(0, &(events_grp_JOIN_INNER_TD_10213953), &(events_JOIN_INNER_TD_10213953[0]));
    
    trans_JOIN_INNER_TD_10213953_out.add(&(tbl_JOIN_INNER_TD_10213953_output));
    trans_JOIN_INNER_TD_10213953_out.dev2host(0, &(events_JOIN_INNER_TD_10213953), &(events_d2h_rd_JOIN_INNER_TD_10213953[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_10_878118_e, 0);

    struct timeval tv_r_JOIN_INNER_10_456588_s, tv_r_JOIN_INNER_10_456588_e;
    gettimeofday(&tv_r_JOIN_INNER_10_456588_s, 0);
    prev_events_grp_JOIN_INNER_TD_10288240.push_back(events_h2d_wr_JOIN_INNER_TD_11730313[0]);
    trans_JOIN_INNER_TD_10288240.add(&(tbl_Filter_TD_11206071_output));
    trans_JOIN_INNER_TD_10288240.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_10288240), &(events_h2d_wr_JOIN_INNER_TD_10288240[0]));
    events_grp_JOIN_INNER_TD_10288240.push_back(events_h2d_wr_JOIN_INNER_TD_10288240[0]);
    events_grp_JOIN_INNER_TD_10288240.push_back(events_JOIN_INNER_TD_11730313[0]);
    krnl_JOIN_INNER_TD_10288240.run(0, &(events_grp_JOIN_INNER_TD_10288240), &(events_JOIN_INNER_TD_10288240[0]));
    
    trans_JOIN_INNER_TD_10288240_out.add(&(tbl_JOIN_INNER_TD_10288240_output));
    trans_JOIN_INNER_TD_10288240_out.dev2host(0, &(events_JOIN_INNER_TD_10288240), &(events_d2h_rd_JOIN_INNER_TD_10288240[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_10_456588_e, 0);

    struct timeval tv_r_JOIN_INNER_10_964904_s, tv_r_JOIN_INNER_10_964904_e;
    gettimeofday(&tv_r_JOIN_INNER_10_964904_s, 0);
    prev_events_grp_JOIN_INNER_TD_10424443.push_back(events_h2d_wr_JOIN_INNER_TD_11320265[0]);
    trans_JOIN_INNER_TD_10424443.add(&(tbl_Filter_TD_11726296_output));
    trans_JOIN_INNER_TD_10424443.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_10424443), &(events_h2d_wr_JOIN_INNER_TD_10424443[0]));
    events_grp_JOIN_INNER_TD_10424443.push_back(events_h2d_wr_JOIN_INNER_TD_10424443[0]);
    events_grp_JOIN_INNER_TD_10424443.push_back(events_JOIN_INNER_TD_11320265[0]);
    krnl_JOIN_INNER_TD_10424443.run(0, &(events_grp_JOIN_INNER_TD_10424443), &(events_JOIN_INNER_TD_10424443[0]));
    
    trans_JOIN_INNER_TD_10424443_out.add(&(tbl_JOIN_INNER_TD_10424443_output));
    trans_JOIN_INNER_TD_10424443_out.dev2host(0, &(events_JOIN_INNER_TD_10424443), &(events_d2h_rd_JOIN_INNER_TD_10424443[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_10_964904_e, 0);

    struct timeval tv_r_Aggregate_9_651657_s, tv_r_Aggregate_9_651657_e;
    gettimeofday(&tv_r_Aggregate_9_651657_s, 0);
    SW_Aggregate_TD_9243762(tbl_JOIN_INNER_TD_10213953_output, tbl_Aggregate_TD_9243762_output);
    gettimeofday(&tv_r_Aggregate_9_651657_e, 0);

    struct timeval tv_r_Aggregate_9_374154_s, tv_r_Aggregate_9_374154_e;
    gettimeofday(&tv_r_Aggregate_9_374154_s, 0);
    SW_Aggregate_TD_9138966(tbl_JOIN_INNER_TD_10288240_output, tbl_Aggregate_TD_9138966_output);
    gettimeofday(&tv_r_Aggregate_9_374154_e, 0);

    struct timeval tv_r_Aggregate_9_714273_s, tv_r_Aggregate_9_714273_e;
    gettimeofday(&tv_r_Aggregate_9_714273_s, 0);
    SW_Aggregate_TD_9541230(tbl_JOIN_INNER_TD_10424443_output, tbl_Aggregate_TD_9541230_output);
    gettimeofday(&tv_r_Aggregate_9_714273_e, 0);

    struct timeval tv_r_Window_8_398369_s, tv_r_Window_8_398369_e;
    gettimeofday(&tv_r_Window_8_398369_s, 0);
    SW_Window_TD_8967856(tbl_Aggregate_TD_9243762_output, tbl_Window_TD_8967856_output);
    gettimeofday(&tv_r_Window_8_398369_e, 0);

    struct timeval tv_r_Window_8_459456_s, tv_r_Window_8_459456_e;
    gettimeofday(&tv_r_Window_8_459456_s, 0);
    SW_Window_TD_8431871(tbl_Aggregate_TD_9138966_output, tbl_Window_TD_8431871_output);
    gettimeofday(&tv_r_Window_8_459456_e, 0);

    struct timeval tv_r_Window_8_278981_s, tv_r_Window_8_278981_e;
    gettimeofday(&tv_r_Window_8_278981_s, 0);
    SW_Window_TD_8875475(tbl_Aggregate_TD_9541230_output, tbl_Window_TD_8875475_output);
    gettimeofday(&tv_r_Window_8_278981_e, 0);

    struct timeval tv_r_Window_7_699128_s, tv_r_Window_7_699128_e;
    gettimeofday(&tv_r_Window_7_699128_s, 0);
    SW_Window_TD_7606668(tbl_Window_TD_8967856_output, tbl_Window_TD_7606668_output);
    gettimeofday(&tv_r_Window_7_699128_e, 0);

    struct timeval tv_r_Window_7_77965_s, tv_r_Window_7_77965_e;
    gettimeofday(&tv_r_Window_7_77965_s, 0);
    SW_Window_TD_7394613(tbl_Window_TD_8431871_output, tbl_Window_TD_7394613_output);
    gettimeofday(&tv_r_Window_7_77965_e, 0);

    struct timeval tv_r_Window_7_311250_s, tv_r_Window_7_311250_e;
    gettimeofday(&tv_r_Window_7_311250_s, 0);
    SW_Window_TD_7299122(tbl_Window_TD_8875475_output, tbl_Window_TD_7299122_output);
    gettimeofday(&tv_r_Window_7_311250_e, 0);

    struct timeval tv_r_Filter_6_116669_s, tv_r_Filter_6_116669_e;
    gettimeofday(&tv_r_Filter_6_116669_s, 0);
    SW_Filter_TD_6959809(tbl_Window_TD_7606668_output, tbl_Filter_TD_6959809_output);
    gettimeofday(&tv_r_Filter_6_116669_e, 0);

    struct timeval tv_r_Filter_6_376995_s, tv_r_Filter_6_376995_e;
    gettimeofday(&tv_r_Filter_6_376995_s, 0);
    SW_Filter_TD_6282526(tbl_Window_TD_7394613_output, tbl_Filter_TD_6282526_output);
    gettimeofday(&tv_r_Filter_6_376995_e, 0);

    struct timeval tv_r_Filter_6_460177_s, tv_r_Filter_6_460177_e;
    gettimeofday(&tv_r_Filter_6_460177_s, 0);
    SW_Filter_TD_6372096(tbl_Window_TD_7299122_output, tbl_Filter_TD_6372096_output);
    gettimeofday(&tv_r_Filter_6_460177_e, 0);

    struct timeval tv_r_Project_5_761757_s, tv_r_Project_5_761757_e;
    gettimeofday(&tv_r_Project_5_761757_s, 0);
    SW_Project_TD_5936868(tbl_Filter_TD_6959809_output, tbl_Project_TD_5936868_output);
    gettimeofday(&tv_r_Project_5_761757_e, 0);

    struct timeval tv_r_Project_5_205738_s, tv_r_Project_5_205738_e;
    gettimeofday(&tv_r_Project_5_205738_s, 0);
    SW_Project_TD_5226488(tbl_Filter_TD_6282526_output, tbl_Project_TD_5226488_output);
    gettimeofday(&tv_r_Project_5_205738_e, 0);

    struct timeval tv_r_Project_5_511652_s, tv_r_Project_5_511652_e;
    gettimeofday(&tv_r_Project_5_511652_s, 0);
    SW_Project_TD_539447(tbl_Filter_TD_6372096_output, tbl_Project_TD_539447_output);
    gettimeofday(&tv_r_Project_5_511652_e, 0);

    struct timeval tv_r_Union_4_439541_s, tv_r_Union_4_439541_e;
    gettimeofday(&tv_r_Union_4_439541_s, 0);
    SW_Union_TD_4632723(tbl_Project_TD_539447_output, tbl_Project_TD_5226488_output, tbl_Project_TD_5936868_output, tbl_Union_TD_4632723_output);
    gettimeofday(&tv_r_Union_4_439541_e, 0);

    struct timeval tv_r_Aggregate_3_68910_s, tv_r_Aggregate_3_68910_e;
    gettimeofday(&tv_r_Aggregate_3_68910_s, 0);
    SW_Aggregate_TD_3792164(tbl_Union_TD_4632723_output, tbl_Aggregate_TD_3792164_output);
    gettimeofday(&tv_r_Aggregate_3_68910_e, 0);

    struct timeval tv_r_Sort_2_7329_s, tv_r_Sort_2_7329_e;
    gettimeofday(&tv_r_Sort_2_7329_s, 0);
    SW_Sort_TD_2554921(tbl_Aggregate_TD_3792164_output, tbl_Sort_TD_2554921_output);
    gettimeofday(&tv_r_Sort_2_7329_e, 0);

    struct timeval tv_r_LocalLimit_1_264556_s, tv_r_LocalLimit_1_264556_e;
    gettimeofday(&tv_r_LocalLimit_1_264556_s, 0);
    SW_LocalLimit_TD_1425520(tbl_Sort_TD_2554921_output, tbl_LocalLimit_TD_1425520_output);
    gettimeofday(&tv_r_LocalLimit_1_264556_e, 0);

    struct timeval tv_r_GlobalLimit_0_802685_s, tv_r_GlobalLimit_0_802685_e;
    gettimeofday(&tv_r_GlobalLimit_0_802685_s, 0);
    SW_GlobalLimit_TD_0829867(tbl_LocalLimit_TD_1425520_output, tbl_GlobalLimit_TD_0829867_output);
    gettimeofday(&tv_r_GlobalLimit_0_802685_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_549328_s, &tv_r_Filter_12_549328_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13279940_input: " << tbl_SerializeFromObject_TD_13279940_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_34338_s, &tv_r_Filter_12_34338_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13589665_input: " << tbl_SerializeFromObject_TD_13589665_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_518917_s, &tv_r_Filter_12_518917_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13648727_input: " << tbl_SerializeFromObject_TD_13648727_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_841039_s, &tv_r_Filter_12_841039_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13640436_input: " << tbl_SerializeFromObject_TD_13640436_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_571277_s, &tv_r_Filter_12_571277_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13706169_input: " << tbl_SerializeFromObject_TD_13706169_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_12: " << tvdiff(&tv_r_Filter_12_599637_s, &tv_r_Filter_12_599637_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_13473325_input: " << tbl_SerializeFromObject_TD_13473325_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_768506_s, &tv_r_Filter_11_768506_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12915351_input: " << tbl_SerializeFromObject_TD_12915351_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_11: " << tvdiff(&tv_r_JOIN_INNER_11_396662_s, &tv_r_JOIN_INNER_11_396662_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_12459707_output: " << tbl_Filter_TD_12459707_output.getNumRow() << " " << "tbl_Filter_TD_1293473_output: " << tbl_Filter_TD_1293473_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_570908_s, &tv_r_Filter_11_570908_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12297946_input: " << tbl_SerializeFromObject_TD_12297946_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_11: " << tvdiff(&tv_r_JOIN_INNER_11_606321_s, &tv_r_JOIN_INNER_11_606321_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_1256418_output: " << tbl_Filter_TD_1256418_output.getNumRow() << " " << "tbl_Filter_TD_12994471_output: " << tbl_Filter_TD_12994471_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_90858_s, &tv_r_Filter_11_90858_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12604243_input: " << tbl_SerializeFromObject_TD_12604243_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_11: " << tvdiff(&tv_r_JOIN_INNER_11_185221_s, &tv_r_JOIN_INNER_11_185221_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_12973526_output: " << tbl_Filter_TD_12973526_output.getNumRow() << " " << "tbl_Filter_TD_12826276_output: " << tbl_Filter_TD_12826276_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_878118_s, &tv_r_JOIN_INNER_10_878118_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_11800726_output: " << tbl_JOIN_INNER_TD_11800726_output.getNumRow() << " " << "tbl_Filter_TD_11834944_output: " << tbl_Filter_TD_11834944_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_456588_s, &tv_r_JOIN_INNER_10_456588_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_11730313_output: " << tbl_JOIN_INNER_TD_11730313_output.getNumRow() << " " << "tbl_Filter_TD_11206071_output: " << tbl_Filter_TD_11206071_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_964904_s, &tv_r_JOIN_INNER_10_964904_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_11320265_output: " << tbl_JOIN_INNER_TD_11320265_output.getNumRow() << " " << "tbl_Filter_TD_11726296_output: " << tbl_Filter_TD_11726296_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_9: " << tvdiff(&tv_r_Aggregate_9_651657_s, &tv_r_Aggregate_9_651657_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10213953_output: " << tbl_JOIN_INNER_TD_10213953_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_9: " << tvdiff(&tv_r_Aggregate_9_374154_s, &tv_r_Aggregate_9_374154_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10288240_output: " << tbl_JOIN_INNER_TD_10288240_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_9: " << tvdiff(&tv_r_Aggregate_9_714273_s, &tv_r_Aggregate_9_714273_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10424443_output: " << tbl_JOIN_INNER_TD_10424443_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_8: " << tvdiff(&tv_r_Window_8_398369_s, &tv_r_Window_8_398369_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_9243762_output: " << tbl_Aggregate_TD_9243762_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_8: " << tvdiff(&tv_r_Window_8_459456_s, &tv_r_Window_8_459456_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_9138966_output: " << tbl_Aggregate_TD_9138966_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_8: " << tvdiff(&tv_r_Window_8_278981_s, &tv_r_Window_8_278981_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_9541230_output: " << tbl_Aggregate_TD_9541230_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_7: " << tvdiff(&tv_r_Window_7_699128_s, &tv_r_Window_7_699128_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_8967856_output: " << tbl_Window_TD_8967856_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_7: " << tvdiff(&tv_r_Window_7_77965_s, &tv_r_Window_7_77965_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_8431871_output: " << tbl_Window_TD_8431871_output.getNumRow() << " " << std::endl; 

    std::cout << "Window_7: " << tvdiff(&tv_r_Window_7_311250_s, &tv_r_Window_7_311250_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_8875475_output: " << tbl_Window_TD_8875475_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_116669_s, &tv_r_Filter_6_116669_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_7606668_output: " << tbl_Window_TD_7606668_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_376995_s, &tv_r_Filter_6_376995_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_7394613_output: " << tbl_Window_TD_7394613_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_460177_s, &tv_r_Filter_6_460177_e) / 1000.0 << " ms " 
     << "tbl_Window_TD_7299122_output: " << tbl_Window_TD_7299122_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_5: " << tvdiff(&tv_r_Project_5_761757_s, &tv_r_Project_5_761757_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6959809_output: " << tbl_Filter_TD_6959809_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_5: " << tvdiff(&tv_r_Project_5_205738_s, &tv_r_Project_5_205738_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6282526_output: " << tbl_Filter_TD_6282526_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_5: " << tvdiff(&tv_r_Project_5_511652_s, &tv_r_Project_5_511652_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6372096_output: " << tbl_Filter_TD_6372096_output.getNumRow() << " " << std::endl; 

    std::cout << "Union_4: " << tvdiff(&tv_r_Union_4_439541_s, &tv_r_Union_4_439541_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_539447_output: " << tbl_Project_TD_539447_output.getNumRow() << " " << "tbl_Project_TD_5226488_output: " << tbl_Project_TD_5226488_output.getNumRow() << " " << "tbl_Project_TD_5936868_output: " << tbl_Project_TD_5936868_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_68910_s, &tv_r_Aggregate_3_68910_e) / 1000.0 << " ms " 
     << "tbl_Union_TD_4632723_output: " << tbl_Union_TD_4632723_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_7329_s, &tv_r_Sort_2_7329_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3792164_output: " << tbl_Aggregate_TD_3792164_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_264556_s, &tv_r_LocalLimit_1_264556_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2554921_output: " << tbl_Sort_TD_2554921_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_802685_s, &tv_r_GlobalLimit_0_802685_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1425520_output: " << tbl_LocalLimit_TD_1425520_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 8.010835 * 1000 << "ms" << std::endl; 
    return 0; 
}
