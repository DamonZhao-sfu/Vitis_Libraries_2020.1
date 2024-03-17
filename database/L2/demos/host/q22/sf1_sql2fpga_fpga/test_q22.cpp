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

#include "cfgFunc_q22.hpp" 
#include "q22.hpp" 

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
    std::cout << "NOTE:running query #22\n."; 
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
    Table tbl_GlobalLimit_TD_0604693_output("tbl_GlobalLimit_TD_0604693_output", 6100000, 5, "");
    tbl_GlobalLimit_TD_0604693_output.allocateHost();
    Table tbl_LocalLimit_TD_1139268_output("tbl_LocalLimit_TD_1139268_output", 6100000, 5, "");
    tbl_LocalLimit_TD_1139268_output.allocateHost();
    Table tbl_Sort_TD_2820994_output("tbl_Sort_TD_2820994_output", 6100000, 5, "");
    tbl_Sort_TD_2820994_output.allocateHost();
    Table tbl_Aggregate_TD_390297_output("tbl_Aggregate_TD_390297_output", 6100000, 5, "");
    tbl_Aggregate_TD_390297_output.allocateHost();
    Table tbl_Expand_TD_4271355_output("tbl_Expand_TD_4271355_output", 6100000, 6, "");
    tbl_Expand_TD_4271355_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5233900_output("tbl_JOIN_INNER_TD_5233900_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_5233900_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6547169_output("tbl_JOIN_INNER_TD_6547169_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_6547169_output.allocateHost();
    Table tbl_Filter_TD_6992471_output("tbl_Filter_TD_6992471_output", 6100000, 1, "");
    tbl_Filter_TD_6992471_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7800854_output("tbl_JOIN_INNER_TD_7800854_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_7800854_output.allocateHost();
    Table tbl_Filter_TD_7202835_output("tbl_Filter_TD_7202835_output", 6100000, 5, "");
    tbl_Filter_TD_7202835_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7675708_input;
    tbl_SerializeFromObject_TD_7675708_input = Table("warehouse", warehouse_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_7675708_input.addCol("w_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_7675708_input.allocateHost();
    tbl_SerializeFromObject_TD_7675708_input.loadHost();
    Table tbl_Filter_TD_8356489_output("tbl_Filter_TD_8356489_output", 6100000, 4, "");
    tbl_Filter_TD_8356489_output.allocateHost();
    Table tbl_Filter_TD_8257265_output("tbl_Filter_TD_8257265_output", 6100000, 1, "");
    tbl_Filter_TD_8257265_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8234898_input;
    tbl_SerializeFromObject_TD_8234898_input = Table("item", item_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_8234898_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_8234898_input.addCol("i_brand", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8234898_input.addCol("i_class", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8234898_input.addCol("i_category", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8234898_input.addCol("i_product_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8234898_input.allocateHost();
    tbl_SerializeFromObject_TD_8234898_input.loadHost();
    Table tbl_SerializeFromObject_TD_9362481_input;
    tbl_SerializeFromObject_TD_9362481_input = Table("inventory", inventory_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_9362481_input.addCol("inv_date_sk", 4);
    tbl_SerializeFromObject_TD_9362481_input.addCol("inv_item_sk", 4);
    tbl_SerializeFromObject_TD_9362481_input.addCol("inv_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_9362481_input.addCol("inv_quantity_on_hand", 4);
    tbl_SerializeFromObject_TD_9362481_input.allocateHost();
    tbl_SerializeFromObject_TD_9362481_input.loadHost();
    Table tbl_SerializeFromObject_TD_9119968_input;
    tbl_SerializeFromObject_TD_9119968_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9119968_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_9119968_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_9119968_input.allocateHost();
    tbl_SerializeFromObject_TD_9119968_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_7800854_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8356489_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8257265_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_7800854_cmds;
    cfg_JOIN_INNER_TD_7800854_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7800854_gqe_join (cfg_JOIN_INNER_TD_7800854_cmds.cmd);
    cfg_JOIN_INNER_TD_7800854_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_7800854;
    krnl_JOIN_INNER_TD_7800854 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7800854.setup(tbl_Filter_TD_8356489_output, tbl_Filter_TD_8257265_output, tbl_JOIN_INNER_TD_7800854_output, cfg_JOIN_INNER_TD_7800854_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_7800854;
    trans_JOIN_INNER_TD_7800854.setq(q_h);
    trans_JOIN_INNER_TD_7800854.add(&(cfg_JOIN_INNER_TD_7800854_cmds));
    transEngine trans_JOIN_INNER_TD_7800854_out;
    trans_JOIN_INNER_TD_7800854_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7800854;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7800854;
    std::vector<cl::Event> events_JOIN_INNER_TD_7800854;
    events_h2d_wr_JOIN_INNER_TD_7800854.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7800854.resize(1);
    events_JOIN_INNER_TD_7800854.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7800854;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7800854;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_8_739201_s, tv_r_Filter_8_739201_e;
    gettimeofday(&tv_r_Filter_8_739201_s, 0);
    SW_Filter_TD_8257265(tbl_SerializeFromObject_TD_9119968_input, tbl_Filter_TD_8257265_output);
    gettimeofday(&tv_r_Filter_8_739201_e, 0);

    struct timeval tv_r_Filter_8_985618_s, tv_r_Filter_8_985618_e;
    gettimeofday(&tv_r_Filter_8_985618_s, 0);
    SW_Filter_TD_8356489(tbl_SerializeFromObject_TD_9362481_input, tbl_Filter_TD_8356489_output);
    gettimeofday(&tv_r_Filter_8_985618_e, 0);

    struct timeval tv_r_Filter_7_401810_s, tv_r_Filter_7_401810_e;
    gettimeofday(&tv_r_Filter_7_401810_s, 0);
    SW_Filter_TD_7202835(tbl_SerializeFromObject_TD_8234898_input, tbl_Filter_TD_7202835_output);
    gettimeofday(&tv_r_Filter_7_401810_e, 0);

    struct timeval tv_r_JOIN_INNER_7_301781_s, tv_r_JOIN_INNER_7_301781_e;
    gettimeofday(&tv_r_JOIN_INNER_7_301781_s, 0);
    trans_JOIN_INNER_TD_7800854.add(&(tbl_Filter_TD_8356489_output));
    trans_JOIN_INNER_TD_7800854.add(&(tbl_Filter_TD_8257265_output));
    trans_JOIN_INNER_TD_7800854.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7800854), &(events_h2d_wr_JOIN_INNER_TD_7800854[0]));
    events_grp_JOIN_INNER_TD_7800854.push_back(events_h2d_wr_JOIN_INNER_TD_7800854[0]);
    krnl_JOIN_INNER_TD_7800854.run(0, &(events_grp_JOIN_INNER_TD_7800854), &(events_JOIN_INNER_TD_7800854[0]));
    
    trans_JOIN_INNER_TD_7800854_out.add(&(tbl_JOIN_INNER_TD_7800854_output));
    trans_JOIN_INNER_TD_7800854_out.dev2host(0, &(events_JOIN_INNER_TD_7800854), &(events_d2h_rd_JOIN_INNER_TD_7800854[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_7_301781_e, 0);

    struct timeval tv_r_Filter_6_449448_s, tv_r_Filter_6_449448_e;
    gettimeofday(&tv_r_Filter_6_449448_s, 0);
    SW_Filter_TD_6992471(tbl_SerializeFromObject_TD_7675708_input, tbl_Filter_TD_6992471_output);
    gettimeofday(&tv_r_Filter_6_449448_e, 0);

    struct timeval tv_r_JOIN_INNER_6_403570_s, tv_r_JOIN_INNER_6_403570_e;
    gettimeofday(&tv_r_JOIN_INNER_6_403570_s, 0);
    SW_JOIN_INNER_TD_6547169(tbl_JOIN_INNER_TD_7800854_output, tbl_Filter_TD_7202835_output, tbl_JOIN_INNER_TD_6547169_output);
    gettimeofday(&tv_r_JOIN_INNER_6_403570_e, 0);

    struct timeval tv_r_JOIN_INNER_5_496760_s, tv_r_JOIN_INNER_5_496760_e;
    gettimeofday(&tv_r_JOIN_INNER_5_496760_s, 0);
    SW_JOIN_INNER_TD_5233900(tbl_JOIN_INNER_TD_6547169_output, tbl_Filter_TD_6992471_output, tbl_JOIN_INNER_TD_5233900_output);
    gettimeofday(&tv_r_JOIN_INNER_5_496760_e, 0);

    struct timeval tv_r_Expand_4_284053_s, tv_r_Expand_4_284053_e;
    gettimeofday(&tv_r_Expand_4_284053_s, 0);
    SW_Expand_TD_4271355(tbl_JOIN_INNER_TD_5233900_output, tbl_Expand_TD_4271355_output);
    gettimeofday(&tv_r_Expand_4_284053_e, 0);

    struct timeval tv_r_Aggregate_3_65028_s, tv_r_Aggregate_3_65028_e;
    gettimeofday(&tv_r_Aggregate_3_65028_s, 0);
    SW_Aggregate_TD_390297(tbl_Expand_TD_4271355_output, tbl_Aggregate_TD_390297_output);
    gettimeofday(&tv_r_Aggregate_3_65028_e, 0);

    struct timeval tv_r_Sort_2_919864_s, tv_r_Sort_2_919864_e;
    gettimeofday(&tv_r_Sort_2_919864_s, 0);
    SW_Sort_TD_2820994(tbl_Aggregate_TD_390297_output, tbl_Sort_TD_2820994_output);
    gettimeofday(&tv_r_Sort_2_919864_e, 0);

    struct timeval tv_r_LocalLimit_1_225466_s, tv_r_LocalLimit_1_225466_e;
    gettimeofday(&tv_r_LocalLimit_1_225466_s, 0);
    SW_LocalLimit_TD_1139268(tbl_Sort_TD_2820994_output, tbl_LocalLimit_TD_1139268_output);
    gettimeofday(&tv_r_LocalLimit_1_225466_e, 0);

    struct timeval tv_r_GlobalLimit_0_448752_s, tv_r_GlobalLimit_0_448752_e;
    gettimeofday(&tv_r_GlobalLimit_0_448752_s, 0);
    SW_GlobalLimit_TD_0604693(tbl_LocalLimit_TD_1139268_output, tbl_GlobalLimit_TD_0604693_output);
    gettimeofday(&tv_r_GlobalLimit_0_448752_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_739201_s, &tv_r_Filter_8_739201_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9119968_input: " << tbl_SerializeFromObject_TD_9119968_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_985618_s, &tv_r_Filter_8_985618_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9362481_input: " << tbl_SerializeFromObject_TD_9362481_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_401810_s, &tv_r_Filter_7_401810_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8234898_input: " << tbl_SerializeFromObject_TD_8234898_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_301781_s, &tv_r_JOIN_INNER_7_301781_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8356489_output: " << tbl_Filter_TD_8356489_output.getNumRow() << " " << "tbl_Filter_TD_8257265_output: " << tbl_Filter_TD_8257265_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_449448_s, &tv_r_Filter_6_449448_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7675708_input: " << tbl_SerializeFromObject_TD_7675708_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_403570_s, &tv_r_JOIN_INNER_6_403570_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7800854_output: " << tbl_JOIN_INNER_TD_7800854_output.getNumRow() << " " << "tbl_Filter_TD_7202835_output: " << tbl_Filter_TD_7202835_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_496760_s, &tv_r_JOIN_INNER_5_496760_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6547169_output: " << tbl_JOIN_INNER_TD_6547169_output.getNumRow() << " " << "tbl_Filter_TD_6992471_output: " << tbl_Filter_TD_6992471_output.getNumRow() << " " << std::endl; 

    std::cout << "Expand_4: " << tvdiff(&tv_r_Expand_4_284053_s, &tv_r_Expand_4_284053_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5233900_output: " << tbl_JOIN_INNER_TD_5233900_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_65028_s, &tv_r_Aggregate_3_65028_e) / 1000.0 << " ms " 
     << "tbl_Expand_TD_4271355_output: " << tbl_Expand_TD_4271355_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_919864_s, &tv_r_Sort_2_919864_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_390297_output: " << tbl_Aggregate_TD_390297_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_225466_s, &tv_r_LocalLimit_1_225466_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2820994_output: " << tbl_Sort_TD_2820994_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_448752_s, &tv_r_GlobalLimit_0_448752_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1139268_output: " << tbl_LocalLimit_TD_1139268_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 4.3865275 * 1000 << "ms" << std::endl; 
    return 0; 
}
