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

#include "cfgFunc_q15.hpp" 
#include "q15.hpp" 

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
    std::cout << "NOTE:running query #15\n."; 
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
    Table tbl_GlobalLimit_TD_0641704_output("tbl_GlobalLimit_TD_0641704_output", 6100000, 2, "");
    tbl_GlobalLimit_TD_0641704_output.allocateHost();
    Table tbl_LocalLimit_TD_1163099_output("tbl_LocalLimit_TD_1163099_output", 6100000, 2, "");
    tbl_LocalLimit_TD_1163099_output.allocateHost();
    Table tbl_Sort_TD_2598097_output("tbl_Sort_TD_2598097_output", 6100000, 2, "");
    tbl_Sort_TD_2598097_output.allocateHost();
    Table tbl_Aggregate_TD_3535252_output("tbl_Aggregate_TD_3535252_output", 6100000, 2, "");
    tbl_Aggregate_TD_3535252_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4785895_output("tbl_JOIN_INNER_TD_4785895_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_4785895_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5755369_output("tbl_JOIN_INNER_TD_5755369_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_5755369_output.allocateHost();
    Table tbl_Filter_TD_5411451_output("tbl_Filter_TD_5411451_output", 6100000, 1, "");
    tbl_Filter_TD_5411451_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6478923_output("tbl_JOIN_INNER_TD_6478923_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_6478923_output.allocateHost();
    Table tbl_Filter_TD_6343756_output("tbl_Filter_TD_6343756_output", 6100000, 3, "");
    tbl_Filter_TD_6343756_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6644602_input;
    tbl_SerializeFromObject_TD_6644602_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_6644602_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_6644602_input.addCol("d_qoy", 4);
    tbl_SerializeFromObject_TD_6644602_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_6644602_input.allocateHost();
    tbl_SerializeFromObject_TD_6644602_input.loadHost();
    Table tbl_Filter_TD_7147270_output("tbl_Filter_TD_7147270_output", 6100000, 3, "");
    tbl_Filter_TD_7147270_output.allocateHost();
    Table tbl_Filter_TD_7472290_output("tbl_Filter_TD_7472290_output", 6100000, 2, "");
    tbl_Filter_TD_7472290_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7788931_input;
    tbl_SerializeFromObject_TD_7788931_input = Table("customer_address", customer_address_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7788931_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_7788931_input.addCol("ca_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7788931_input.addCol("ca_zip", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7788931_input.allocateHost();
    tbl_SerializeFromObject_TD_7788931_input.loadHost();
    Table tbl_SerializeFromObject_TD_8863912_input;
    tbl_SerializeFromObject_TD_8863912_input = Table("catalog_sales", catalog_sales_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8863912_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_8863912_input.addCol("cs_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_8863912_input.addCol("cs_sales_price", 4);
    tbl_SerializeFromObject_TD_8863912_input.allocateHost();
    tbl_SerializeFromObject_TD_8863912_input.loadHost();
    Table tbl_SerializeFromObject_TD_8740244_input;
    tbl_SerializeFromObject_TD_8740244_input = Table("customer", customer_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8740244_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_8740244_input.addCol("c_current_addr_sk", 4);
    tbl_SerializeFromObject_TD_8740244_input.allocateHost();
    tbl_SerializeFromObject_TD_8740244_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_6478923_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_7147270_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_7472290_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_6478923_cmds;
    cfg_JOIN_INNER_TD_6478923_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_6478923_gqe_join (cfg_JOIN_INNER_TD_6478923_cmds.cmd);
    cfg_JOIN_INNER_TD_6478923_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_6478923;
    krnl_JOIN_INNER_TD_6478923 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_6478923.setup(tbl_Filter_TD_7147270_output, tbl_Filter_TD_7472290_output, tbl_JOIN_INNER_TD_6478923_output, cfg_JOIN_INNER_TD_6478923_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_6478923;
    trans_JOIN_INNER_TD_6478923.setq(q_h);
    trans_JOIN_INNER_TD_6478923.add(&(cfg_JOIN_INNER_TD_6478923_cmds));
    transEngine trans_JOIN_INNER_TD_6478923_out;
    trans_JOIN_INNER_TD_6478923_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_6478923;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_6478923;
    std::vector<cl::Event> events_JOIN_INNER_TD_6478923;
    events_h2d_wr_JOIN_INNER_TD_6478923.resize(1);
    events_d2h_rd_JOIN_INNER_TD_6478923.resize(1);
    events_JOIN_INNER_TD_6478923.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_6478923;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_6478923;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_7_399131_s, tv_r_Filter_7_399131_e;
    gettimeofday(&tv_r_Filter_7_399131_s, 0);
    SW_Filter_TD_7472290(tbl_SerializeFromObject_TD_8740244_input, tbl_Filter_TD_7472290_output);
    gettimeofday(&tv_r_Filter_7_399131_e, 0);

    struct timeval tv_r_Filter_7_375934_s, tv_r_Filter_7_375934_e;
    gettimeofday(&tv_r_Filter_7_375934_s, 0);
    SW_Filter_TD_7147270(tbl_SerializeFromObject_TD_8863912_input, tbl_Filter_TD_7147270_output);
    gettimeofday(&tv_r_Filter_7_375934_e, 0);

    struct timeval tv_r_Filter_6_976283_s, tv_r_Filter_6_976283_e;
    gettimeofday(&tv_r_Filter_6_976283_s, 0);
    SW_Filter_TD_6343756(tbl_SerializeFromObject_TD_7788931_input, tbl_Filter_TD_6343756_output);
    gettimeofday(&tv_r_Filter_6_976283_e, 0);

    struct timeval tv_r_JOIN_INNER_6_738842_s, tv_r_JOIN_INNER_6_738842_e;
    gettimeofday(&tv_r_JOIN_INNER_6_738842_s, 0);
    trans_JOIN_INNER_TD_6478923.add(&(tbl_Filter_TD_7147270_output));
    trans_JOIN_INNER_TD_6478923.add(&(tbl_Filter_TD_7472290_output));
    trans_JOIN_INNER_TD_6478923.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_6478923), &(events_h2d_wr_JOIN_INNER_TD_6478923[0]));
    events_grp_JOIN_INNER_TD_6478923.push_back(events_h2d_wr_JOIN_INNER_TD_6478923[0]);
    krnl_JOIN_INNER_TD_6478923.run(0, &(events_grp_JOIN_INNER_TD_6478923), &(events_JOIN_INNER_TD_6478923[0]));
    
    trans_JOIN_INNER_TD_6478923_out.add(&(tbl_JOIN_INNER_TD_6478923_output));
    trans_JOIN_INNER_TD_6478923_out.dev2host(0, &(events_JOIN_INNER_TD_6478923), &(events_d2h_rd_JOIN_INNER_TD_6478923[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_6_738842_e, 0);

    struct timeval tv_r_Filter_5_1106_s, tv_r_Filter_5_1106_e;
    gettimeofday(&tv_r_Filter_5_1106_s, 0);
    SW_Filter_TD_5411451(tbl_SerializeFromObject_TD_6644602_input, tbl_Filter_TD_5411451_output);
    gettimeofday(&tv_r_Filter_5_1106_e, 0);

    struct timeval tv_r_JOIN_INNER_5_134066_s, tv_r_JOIN_INNER_5_134066_e;
    gettimeofday(&tv_r_JOIN_INNER_5_134066_s, 0);
    SW_JOIN_INNER_TD_5755369(tbl_JOIN_INNER_TD_6478923_output, tbl_Filter_TD_6343756_output, tbl_JOIN_INNER_TD_5755369_output);
    gettimeofday(&tv_r_JOIN_INNER_5_134066_e, 0);

    struct timeval tv_r_JOIN_INNER_4_597768_s, tv_r_JOIN_INNER_4_597768_e;
    gettimeofday(&tv_r_JOIN_INNER_4_597768_s, 0);
    SW_JOIN_INNER_TD_4785895(tbl_JOIN_INNER_TD_5755369_output, tbl_Filter_TD_5411451_output, tbl_JOIN_INNER_TD_4785895_output);
    gettimeofday(&tv_r_JOIN_INNER_4_597768_e, 0);

    struct timeval tv_r_Aggregate_3_930385_s, tv_r_Aggregate_3_930385_e;
    gettimeofday(&tv_r_Aggregate_3_930385_s, 0);
    SW_Aggregate_TD_3535252(tbl_JOIN_INNER_TD_4785895_output, tbl_Aggregate_TD_3535252_output);
    gettimeofday(&tv_r_Aggregate_3_930385_e, 0);

    struct timeval tv_r_Sort_2_341888_s, tv_r_Sort_2_341888_e;
    gettimeofday(&tv_r_Sort_2_341888_s, 0);
    SW_Sort_TD_2598097(tbl_Aggregate_TD_3535252_output, tbl_Sort_TD_2598097_output);
    gettimeofday(&tv_r_Sort_2_341888_e, 0);

    struct timeval tv_r_LocalLimit_1_311154_s, tv_r_LocalLimit_1_311154_e;
    gettimeofday(&tv_r_LocalLimit_1_311154_s, 0);
    SW_LocalLimit_TD_1163099(tbl_Sort_TD_2598097_output, tbl_LocalLimit_TD_1163099_output);
    gettimeofday(&tv_r_LocalLimit_1_311154_e, 0);

    struct timeval tv_r_GlobalLimit_0_260909_s, tv_r_GlobalLimit_0_260909_e;
    gettimeofday(&tv_r_GlobalLimit_0_260909_s, 0);
    SW_GlobalLimit_TD_0641704(tbl_LocalLimit_TD_1163099_output, tbl_GlobalLimit_TD_0641704_output);
    gettimeofday(&tv_r_GlobalLimit_0_260909_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_399131_s, &tv_r_Filter_7_399131_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8740244_input: " << tbl_SerializeFromObject_TD_8740244_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_375934_s, &tv_r_Filter_7_375934_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8863912_input: " << tbl_SerializeFromObject_TD_8863912_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_976283_s, &tv_r_Filter_6_976283_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7788931_input: " << tbl_SerializeFromObject_TD_7788931_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_738842_s, &tv_r_JOIN_INNER_6_738842_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_7147270_output: " << tbl_Filter_TD_7147270_output.getNumRow() << " " << "tbl_Filter_TD_7472290_output: " << tbl_Filter_TD_7472290_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_1106_s, &tv_r_Filter_5_1106_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6644602_input: " << tbl_SerializeFromObject_TD_6644602_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_134066_s, &tv_r_JOIN_INNER_5_134066_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6478923_output: " << tbl_JOIN_INNER_TD_6478923_output.getNumRow() << " " << "tbl_Filter_TD_6343756_output: " << tbl_Filter_TD_6343756_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_597768_s, &tv_r_JOIN_INNER_4_597768_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5755369_output: " << tbl_JOIN_INNER_TD_5755369_output.getNumRow() << " " << "tbl_Filter_TD_5411451_output: " << tbl_Filter_TD_5411451_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_930385_s, &tv_r_Aggregate_3_930385_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4785895_output: " << tbl_JOIN_INNER_TD_4785895_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_341888_s, &tv_r_Sort_2_341888_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3535252_output: " << tbl_Aggregate_TD_3535252_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_311154_s, &tv_r_LocalLimit_1_311154_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2598097_output: " << tbl_Sort_TD_2598097_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_260909_s, &tv_r_GlobalLimit_0_260909_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1163099_output: " << tbl_LocalLimit_TD_1163099_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.8549271 * 1000 << "ms" << std::endl; 
    return 0; 
}
