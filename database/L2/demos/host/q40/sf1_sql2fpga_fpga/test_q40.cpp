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

#include "cfgFunc_q40.hpp" 
#include "q40.hpp" 

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
    std::cout << "NOTE:running query #40\n."; 
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
    cl::Device device_h = devices[1]; 
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
    Table tbl_GlobalLimit_TD_0806260_output("tbl_GlobalLimit_TD_0806260_output", 6100000, 4, "");
    tbl_GlobalLimit_TD_0806260_output.allocateHost();
    Table tbl_LocalLimit_TD_1566283_output("tbl_LocalLimit_TD_1566283_output", 6100000, 4, "");
    tbl_LocalLimit_TD_1566283_output.allocateHost();
    Table tbl_Sort_TD_2827851_output("tbl_Sort_TD_2827851_output", 6100000, 4, "");
    tbl_Sort_TD_2827851_output.allocateHost();
    Table tbl_Aggregate_TD_3359756_output("tbl_Aggregate_TD_3359756_output", 6100000, 4, "");
    tbl_Aggregate_TD_3359756_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4654729_output("tbl_JOIN_INNER_TD_4654729_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_4654729_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5268466_output("tbl_JOIN_INNER_TD_5268466_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_5268466_output.allocateHost();
    Table tbl_Filter_TD_5723416_output("tbl_Filter_TD_5723416_output", 6100000, 2, "");
    tbl_Filter_TD_5723416_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6961330_output("tbl_JOIN_INNER_TD_6961330_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_6961330_output.allocateHost();
    Table tbl_Filter_TD_6406877_output("tbl_Filter_TD_6406877_output", 6100000, 2, "");
    tbl_Filter_TD_6406877_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6911686_input;
    tbl_SerializeFromObject_TD_6911686_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_6911686_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_6911686_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_6911686_input.allocateHost();
    tbl_SerializeFromObject_TD_6911686_input.loadHost();
    Table tbl_JOIN_LEFTOUTER_TD_7493053_output("tbl_JOIN_LEFTOUTER_TD_7493053_output", 6100000, 5, "");
    tbl_JOIN_LEFTOUTER_TD_7493053_output.allocateHost();
    Table tbl_Filter_TD_7839635_output("tbl_Filter_TD_7839635_output", 6100000, 2, "");
    tbl_Filter_TD_7839635_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7228497_input;
    tbl_SerializeFromObject_TD_7228497_input = Table("item", item_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7228497_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_7228497_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7228497_input.addCol("i_current_price", 4);
    tbl_SerializeFromObject_TD_7228497_input.allocateHost();
    tbl_SerializeFromObject_TD_7228497_input.loadHost();
    Table tbl_Filter_TD_8893652_output("tbl_Filter_TD_8893652_output", 6100000, 5, "");
    tbl_Filter_TD_8893652_output.allocateHost();
    Table tbl_Filter_TD_8184505_output("tbl_Filter_TD_8184505_output", 6100000, 3, "");
    tbl_Filter_TD_8184505_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8638313_input;
    tbl_SerializeFromObject_TD_8638313_input = Table("warehouse", warehouse_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8638313_input.addCol("w_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_8638313_input.addCol("w_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8638313_input.allocateHost();
    tbl_SerializeFromObject_TD_8638313_input.loadHost();
    Table tbl_SerializeFromObject_TD_9282325_input;
    tbl_SerializeFromObject_TD_9282325_input = Table("catalog_sales", catalog_sales_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_9282325_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_9282325_input.addCol("cs_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_9282325_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_9282325_input.addCol("cs_order_number", 8);
    tbl_SerializeFromObject_TD_9282325_input.addCol("cs_sales_price", 4);
    tbl_SerializeFromObject_TD_9282325_input.allocateHost();
    tbl_SerializeFromObject_TD_9282325_input.loadHost();
    Table tbl_SerializeFromObject_TD_97331_input;
    tbl_SerializeFromObject_TD_97331_input = Table("catalog_returns", catalog_returns_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_97331_input.addCol("cr_item_sk", 4);
    tbl_SerializeFromObject_TD_97331_input.addCol("cr_order_number", 8);
    tbl_SerializeFromObject_TD_97331_input.addCol("cr_refunded_cash", 4);
    tbl_SerializeFromObject_TD_97331_input.allocateHost();
    tbl_SerializeFromObject_TD_97331_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_LEFTOUTER_TD_7493053_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8893652_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8184505_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_LEFTOUTER_TD_7493053_cmds;
    cfg_JOIN_LEFTOUTER_TD_7493053_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTOUTER_TD_7493053_gqe_join (cfg_JOIN_LEFTOUTER_TD_7493053_cmds.cmd);
    cfg_JOIN_LEFTOUTER_TD_7493053_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_LEFTOUTER_TD_7493053;
    krnl_JOIN_LEFTOUTER_TD_7493053 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTOUTER_TD_7493053.setup(tbl_Filter_TD_8893652_output, tbl_Filter_TD_8184505_output, tbl_JOIN_LEFTOUTER_TD_7493053_output, cfg_JOIN_LEFTOUTER_TD_7493053_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_LEFTOUTER_TD_7493053;
    trans_JOIN_LEFTOUTER_TD_7493053.setq(q_h);
    trans_JOIN_LEFTOUTER_TD_7493053.add(&(cfg_JOIN_LEFTOUTER_TD_7493053_cmds));
    transEngine trans_JOIN_LEFTOUTER_TD_7493053_out;
    trans_JOIN_LEFTOUTER_TD_7493053_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTOUTER_TD_7493053;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTOUTER_TD_7493053;
    std::vector<cl::Event> events_JOIN_LEFTOUTER_TD_7493053;
    events_h2d_wr_JOIN_LEFTOUTER_TD_7493053.resize(1);
    events_d2h_rd_JOIN_LEFTOUTER_TD_7493053.resize(1);
    events_JOIN_LEFTOUTER_TD_7493053.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTOUTER_TD_7493053;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTOUTER_TD_7493053;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_8_480392_s, tv_r_Filter_8_480392_e;
    gettimeofday(&tv_r_Filter_8_480392_s, 0);
    SW_Filter_TD_8184505(tbl_SerializeFromObject_TD_97331_input, tbl_Filter_TD_8184505_output);
    gettimeofday(&tv_r_Filter_8_480392_e, 0);

    struct timeval tv_r_Filter_8_101873_s, tv_r_Filter_8_101873_e;
    gettimeofday(&tv_r_Filter_8_101873_s, 0);
    SW_Filter_TD_8893652(tbl_SerializeFromObject_TD_9282325_input, tbl_Filter_TD_8893652_output);
    gettimeofday(&tv_r_Filter_8_101873_e, 0);

    struct timeval tv_r_Filter_7_947898_s, tv_r_Filter_7_947898_e;
    gettimeofday(&tv_r_Filter_7_947898_s, 0);
    SW_Filter_TD_7839635(tbl_SerializeFromObject_TD_8638313_input, tbl_Filter_TD_7839635_output);
    gettimeofday(&tv_r_Filter_7_947898_e, 0);

    struct timeval tv_r_JOIN_LEFTOUTER_7_578386_s, tv_r_JOIN_LEFTOUTER_7_578386_e;
    gettimeofday(&tv_r_JOIN_LEFTOUTER_7_578386_s, 0);
    trans_JOIN_LEFTOUTER_TD_7493053.add(&(tbl_Filter_TD_8893652_output));
    trans_JOIN_LEFTOUTER_TD_7493053.add(&(tbl_Filter_TD_8184505_output));
    trans_JOIN_LEFTOUTER_TD_7493053.host2dev(0, &(prev_events_grp_JOIN_LEFTOUTER_TD_7493053), &(events_h2d_wr_JOIN_LEFTOUTER_TD_7493053[0]));
    events_grp_JOIN_LEFTOUTER_TD_7493053.push_back(events_h2d_wr_JOIN_LEFTOUTER_TD_7493053[0]);
    krnl_JOIN_LEFTOUTER_TD_7493053.run(0, &(events_grp_JOIN_LEFTOUTER_TD_7493053), &(events_JOIN_LEFTOUTER_TD_7493053[0]));
    
    trans_JOIN_LEFTOUTER_TD_7493053_out.add(&(tbl_JOIN_LEFTOUTER_TD_7493053_output));
    trans_JOIN_LEFTOUTER_TD_7493053_out.dev2host(0, &(events_JOIN_LEFTOUTER_TD_7493053), &(events_d2h_rd_JOIN_LEFTOUTER_TD_7493053[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_LEFTOUTER_7_578386_e, 0);

    struct timeval tv_r_Filter_6_261606_s, tv_r_Filter_6_261606_e;
    gettimeofday(&tv_r_Filter_6_261606_s, 0);
    SW_Filter_TD_6406877(tbl_SerializeFromObject_TD_7228497_input, tbl_Filter_TD_6406877_output);
    gettimeofday(&tv_r_Filter_6_261606_e, 0);

    struct timeval tv_r_JOIN_INNER_6_263823_s, tv_r_JOIN_INNER_6_263823_e;
    gettimeofday(&tv_r_JOIN_INNER_6_263823_s, 0);
    SW_JOIN_INNER_TD_6961330(tbl_JOIN_LEFTOUTER_TD_7493053_output, tbl_Filter_TD_7839635_output, tbl_JOIN_INNER_TD_6961330_output);
    gettimeofday(&tv_r_JOIN_INNER_6_263823_e, 0);

    struct timeval tv_r_Filter_5_73932_s, tv_r_Filter_5_73932_e;
    gettimeofday(&tv_r_Filter_5_73932_s, 0);
    SW_Filter_TD_5723416(tbl_SerializeFromObject_TD_6911686_input, tbl_Filter_TD_5723416_output);
    gettimeofday(&tv_r_Filter_5_73932_e, 0);

    struct timeval tv_r_JOIN_INNER_5_618332_s, tv_r_JOIN_INNER_5_618332_e;
    gettimeofday(&tv_r_JOIN_INNER_5_618332_s, 0);
    SW_JOIN_INNER_TD_5268466(tbl_JOIN_INNER_TD_6961330_output, tbl_Filter_TD_6406877_output, tbl_JOIN_INNER_TD_5268466_output);
    gettimeofday(&tv_r_JOIN_INNER_5_618332_e, 0);

    struct timeval tv_r_JOIN_INNER_4_19976_s, tv_r_JOIN_INNER_4_19976_e;
    gettimeofday(&tv_r_JOIN_INNER_4_19976_s, 0);
    SW_JOIN_INNER_TD_4654729(tbl_JOIN_INNER_TD_5268466_output, tbl_Filter_TD_5723416_output, tbl_JOIN_INNER_TD_4654729_output);
    gettimeofday(&tv_r_JOIN_INNER_4_19976_e, 0);

    struct timeval tv_r_Aggregate_3_712520_s, tv_r_Aggregate_3_712520_e;
    gettimeofday(&tv_r_Aggregate_3_712520_s, 0);
    SW_Aggregate_TD_3359756(tbl_JOIN_INNER_TD_4654729_output, tbl_Aggregate_TD_3359756_output);
    gettimeofday(&tv_r_Aggregate_3_712520_e, 0);

    struct timeval tv_r_Sort_2_620003_s, tv_r_Sort_2_620003_e;
    gettimeofday(&tv_r_Sort_2_620003_s, 0);
    SW_Sort_TD_2827851(tbl_Aggregate_TD_3359756_output, tbl_Sort_TD_2827851_output);
    gettimeofday(&tv_r_Sort_2_620003_e, 0);

    struct timeval tv_r_LocalLimit_1_986829_s, tv_r_LocalLimit_1_986829_e;
    gettimeofday(&tv_r_LocalLimit_1_986829_s, 0);
    SW_LocalLimit_TD_1566283(tbl_Sort_TD_2827851_output, tbl_LocalLimit_TD_1566283_output);
    gettimeofday(&tv_r_LocalLimit_1_986829_e, 0);

    struct timeval tv_r_GlobalLimit_0_701159_s, tv_r_GlobalLimit_0_701159_e;
    gettimeofday(&tv_r_GlobalLimit_0_701159_s, 0);
    SW_GlobalLimit_TD_0806260(tbl_LocalLimit_TD_1566283_output, tbl_GlobalLimit_TD_0806260_output);
    gettimeofday(&tv_r_GlobalLimit_0_701159_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_480392_s, &tv_r_Filter_8_480392_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_97331_input: " << tbl_SerializeFromObject_TD_97331_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_101873_s, &tv_r_Filter_8_101873_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9282325_input: " << tbl_SerializeFromObject_TD_9282325_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_947898_s, &tv_r_Filter_7_947898_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8638313_input: " << tbl_SerializeFromObject_TD_8638313_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTOUTER_7: " << tvdiff(&tv_r_JOIN_LEFTOUTER_7_578386_s, &tv_r_JOIN_LEFTOUTER_7_578386_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8893652_output: " << tbl_Filter_TD_8893652_output.getNumRow() << " " << "tbl_Filter_TD_8184505_output: " << tbl_Filter_TD_8184505_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_261606_s, &tv_r_Filter_6_261606_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7228497_input: " << tbl_SerializeFromObject_TD_7228497_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_263823_s, &tv_r_JOIN_INNER_6_263823_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTOUTER_TD_7493053_output: " << tbl_JOIN_LEFTOUTER_TD_7493053_output.getNumRow() << " " << "tbl_Filter_TD_7839635_output: " << tbl_Filter_TD_7839635_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_73932_s, &tv_r_Filter_5_73932_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6911686_input: " << tbl_SerializeFromObject_TD_6911686_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_618332_s, &tv_r_JOIN_INNER_5_618332_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6961330_output: " << tbl_JOIN_INNER_TD_6961330_output.getNumRow() << " " << "tbl_Filter_TD_6406877_output: " << tbl_Filter_TD_6406877_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_19976_s, &tv_r_JOIN_INNER_4_19976_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5268466_output: " << tbl_JOIN_INNER_TD_5268466_output.getNumRow() << " " << "tbl_Filter_TD_5723416_output: " << tbl_Filter_TD_5723416_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_712520_s, &tv_r_Aggregate_3_712520_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4654729_output: " << tbl_JOIN_INNER_TD_4654729_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_620003_s, &tv_r_Sort_2_620003_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3359756_output: " << tbl_Aggregate_TD_3359756_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_986829_s, &tv_r_LocalLimit_1_986829_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2827851_output: " << tbl_Sort_TD_2827851_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_701159_s, &tv_r_GlobalLimit_0_701159_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1566283_output: " << tbl_LocalLimit_TD_1566283_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.005121 * 1000 << "ms" << std::endl; 
    return 0; 
}
