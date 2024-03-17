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

#include "cfgFunc_q68.hpp" 
#include "q68.hpp" 

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
    std::cout << "NOTE:running query #68\n."; 
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
    Table tbl_GlobalLimit_TD_083063_output("tbl_GlobalLimit_TD_083063_output", 6100000, 8, "");
    tbl_GlobalLimit_TD_083063_output.allocateHost();
    Table tbl_LocalLimit_TD_1578119_output("tbl_LocalLimit_TD_1578119_output", 6100000, 8, "");
    tbl_LocalLimit_TD_1578119_output.allocateHost();
    Table tbl_Sort_TD_2415189_output("tbl_Sort_TD_2415189_output", 6100000, 8, "");
    tbl_Sort_TD_2415189_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3503031_output("tbl_JOIN_INNER_TD_3503031_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_3503031_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4311690_output("tbl_JOIN_INNER_TD_4311690_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_4311690_output.allocateHost();
    Table tbl_Filter_TD_453726_output("tbl_Filter_TD_453726_output", 6100000, 2, "");
    tbl_Filter_TD_453726_output.allocateHost();
    Table tbl_Aggregate_TD_5312256_output("tbl_Aggregate_TD_5312256_output", 6100000, 6, "");
    tbl_Aggregate_TD_5312256_output.allocateHost();
    Table tbl_Filter_TD_5896878_output("tbl_Filter_TD_5896878_output", 6100000, 4, "");
    tbl_Filter_TD_5896878_output.allocateHost();
    Table tbl_SerializeFromObject_TD_5411227_input;
    tbl_SerializeFromObject_TD_5411227_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_5411227_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_5411227_input.addCol("ca_city", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_5411227_input.allocateHost();
    tbl_SerializeFromObject_TD_5411227_input.loadHost();
    Table tbl_JOIN_INNER_TD_6187048_output("tbl_JOIN_INNER_TD_6187048_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_6187048_output.allocateHost();
    Table tbl_SerializeFromObject_TD_663806_input;
    tbl_SerializeFromObject_TD_663806_input = Table("customer", customer_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_663806_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_663806_input.addCol("c_current_addr_sk", 4);
    tbl_SerializeFromObject_TD_663806_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_663806_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_663806_input.allocateHost();
    tbl_SerializeFromObject_TD_663806_input.loadHost();
    Table tbl_JOIN_INNER_TD_7768905_output("tbl_JOIN_INNER_TD_7768905_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_7768905_output.allocateHost();
    Table tbl_Filter_TD_796679_output("tbl_Filter_TD_796679_output", 6100000, 2, "");
    tbl_Filter_TD_796679_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8855685_output("tbl_JOIN_INNER_TD_8855685_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_8855685_output.allocateHost();
    Table tbl_Filter_TD_8869253_output("tbl_Filter_TD_8869253_output", 6100000, 1, "");
    tbl_Filter_TD_8869253_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8155146_input;
    tbl_SerializeFromObject_TD_8155146_input = Table("customer_address", customer_address_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8155146_input.addCol("ca_address_sk", 4);
    tbl_SerializeFromObject_TD_8155146_input.addCol("ca_city", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8155146_input.allocateHost();
    tbl_SerializeFromObject_TD_8155146_input.loadHost();
    Table tbl_JOIN_INNER_TD_9401357_output("tbl_JOIN_INNER_TD_9401357_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_9401357_output.allocateHost();
    Table tbl_Filter_TD_9289066_output("tbl_Filter_TD_9289066_output", 6100000, 1, "");
    tbl_Filter_TD_9289066_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9167176_input;
    tbl_SerializeFromObject_TD_9167176_input = Table("household_demographics", household_demographics_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9167176_input.addCol("hd_demo_sk", 4);
    tbl_SerializeFromObject_TD_9167176_input.addCol("hd_dep_count", 4);
    tbl_SerializeFromObject_TD_9167176_input.addCol("hd_vehicle_count", 4);
    tbl_SerializeFromObject_TD_9167176_input.allocateHost();
    tbl_SerializeFromObject_TD_9167176_input.loadHost();
    Table tbl_Filter_TD_10446092_output("tbl_Filter_TD_10446092_output", 6100000, 9, "");
    tbl_Filter_TD_10446092_output.allocateHost();
    Table tbl_Filter_TD_1023536_output("tbl_Filter_TD_1023536_output", 6100000, 1, "");
    tbl_Filter_TD_1023536_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10195679_input;
    tbl_SerializeFromObject_TD_10195679_input = Table("store", store_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10195679_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_10195679_input.addCol("s_city", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10195679_input.allocateHost();
    tbl_SerializeFromObject_TD_10195679_input.loadHost();
    Table tbl_SerializeFromObject_TD_11792256_input;
    tbl_SerializeFromObject_TD_11792256_input = Table("store_sales", store_sales_n, 9, in_dir, "orc");
    tbl_SerializeFromObject_TD_11792256_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_11792256_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_11792256_input.addCol("ss_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_11792256_input.addCol("ss_addr_sk", 4);
    tbl_SerializeFromObject_TD_11792256_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_11792256_input.addCol("ss_ticket_number", 8);
    tbl_SerializeFromObject_TD_11792256_input.addCol("ss_ext_sales_price", 4);
    tbl_SerializeFromObject_TD_11792256_input.addCol("ss_ext_list_price", 4);
    tbl_SerializeFromObject_TD_11792256_input.addCol("ss_ext_tax", 4);
    tbl_SerializeFromObject_TD_11792256_input.allocateHost();
    tbl_SerializeFromObject_TD_11792256_input.loadHost();
    Table tbl_SerializeFromObject_TD_11966388_input;
    tbl_SerializeFromObject_TD_11966388_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_11966388_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_11966388_input.addCol("d_dom", 4);
    tbl_SerializeFromObject_TD_11966388_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_11966388_input.allocateHost();
    tbl_SerializeFromObject_TD_11966388_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_7768905_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8855685_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8869253_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_9401357_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9289066_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_7768905_cmds;
    cfg_JOIN_INNER_TD_7768905_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7768905_gqe_join (cfg_JOIN_INNER_TD_7768905_cmds.cmd);
    cfg_JOIN_INNER_TD_7768905_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8855685_cmds;
    cfg_JOIN_INNER_TD_8855685_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8855685_gqe_join (cfg_JOIN_INNER_TD_8855685_cmds.cmd);
    cfg_JOIN_INNER_TD_8855685_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_7768905;
    krnl_JOIN_INNER_TD_7768905 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7768905.setup(tbl_JOIN_INNER_TD_8855685_output, tbl_Filter_TD_8869253_output, tbl_JOIN_INNER_TD_7768905_output, cfg_JOIN_INNER_TD_7768905_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_8855685;
    krnl_JOIN_INNER_TD_8855685 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8855685.setup(tbl_JOIN_INNER_TD_9401357_output, tbl_Filter_TD_9289066_output, tbl_JOIN_INNER_TD_8855685_output, cfg_JOIN_INNER_TD_8855685_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_7768905;
    trans_JOIN_INNER_TD_7768905.setq(q_h);
    trans_JOIN_INNER_TD_7768905.add(&(cfg_JOIN_INNER_TD_7768905_cmds));
    transEngine trans_JOIN_INNER_TD_7768905_out;
    trans_JOIN_INNER_TD_7768905_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_8855685;
    trans_JOIN_INNER_TD_8855685.setq(q_h);
    trans_JOIN_INNER_TD_8855685.add(&(cfg_JOIN_INNER_TD_8855685_cmds));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7768905;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7768905;
    std::vector<cl::Event> events_JOIN_INNER_TD_7768905;
    events_h2d_wr_JOIN_INNER_TD_7768905.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7768905.resize(1);
    events_JOIN_INNER_TD_7768905.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7768905;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7768905;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8855685;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8855685;
    std::vector<cl::Event> events_JOIN_INNER_TD_8855685;
    events_h2d_wr_JOIN_INNER_TD_8855685.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8855685.resize(1);
    events_JOIN_INNER_TD_8855685.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8855685;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8855685;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_10_710540_s, tv_r_Filter_10_710540_e;
    gettimeofday(&tv_r_Filter_10_710540_s, 0);
    SW_Filter_TD_1023536(tbl_SerializeFromObject_TD_11966388_input, tbl_Filter_TD_1023536_output);
    gettimeofday(&tv_r_Filter_10_710540_e, 0);

    struct timeval tv_r_Filter_10_22438_s, tv_r_Filter_10_22438_e;
    gettimeofday(&tv_r_Filter_10_22438_s, 0);
    SW_Filter_TD_10446092(tbl_SerializeFromObject_TD_11792256_input, tbl_Filter_TD_10446092_output);
    gettimeofday(&tv_r_Filter_10_22438_e, 0);

    struct timeval tv_r_Filter_9_489375_s, tv_r_Filter_9_489375_e;
    gettimeofday(&tv_r_Filter_9_489375_s, 0);
    SW_Filter_TD_9289066(tbl_SerializeFromObject_TD_10195679_input, tbl_Filter_TD_9289066_output);
    gettimeofday(&tv_r_Filter_9_489375_e, 0);

    struct timeval tv_r_JOIN_INNER_9_321401_s, tv_r_JOIN_INNER_9_321401_e;
    gettimeofday(&tv_r_JOIN_INNER_9_321401_s, 0);
    SW_JOIN_INNER_TD_9401357(tbl_Filter_TD_10446092_output, tbl_Filter_TD_1023536_output, tbl_JOIN_INNER_TD_9401357_output);
    gettimeofday(&tv_r_JOIN_INNER_9_321401_e, 0);

    struct timeval tv_r_Filter_8_498386_s, tv_r_Filter_8_498386_e;
    gettimeofday(&tv_r_Filter_8_498386_s, 0);
    SW_Filter_TD_8869253(tbl_SerializeFromObject_TD_9167176_input, tbl_Filter_TD_8869253_output);
    gettimeofday(&tv_r_Filter_8_498386_e, 0);

    struct timeval tv_r_JOIN_INNER_8_280433_s, tv_r_JOIN_INNER_8_280433_e;
    gettimeofday(&tv_r_JOIN_INNER_8_280433_s, 0);
    trans_JOIN_INNER_TD_8855685.add(&(tbl_JOIN_INNER_TD_9401357_output));
    trans_JOIN_INNER_TD_8855685.add(&(tbl_Filter_TD_9289066_output));
    trans_JOIN_INNER_TD_8855685.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8855685), &(events_h2d_wr_JOIN_INNER_TD_8855685[0]));
    events_grp_JOIN_INNER_TD_8855685.push_back(events_h2d_wr_JOIN_INNER_TD_8855685[0]);
    krnl_JOIN_INNER_TD_8855685.run(0, &(events_grp_JOIN_INNER_TD_8855685), &(events_JOIN_INNER_TD_8855685[0]));
    gettimeofday(&tv_r_JOIN_INNER_8_280433_e, 0);

    struct timeval tv_r_Filter_7_658540_s, tv_r_Filter_7_658540_e;
    gettimeofday(&tv_r_Filter_7_658540_s, 0);
    SW_Filter_TD_796679(tbl_SerializeFromObject_TD_8155146_input, tbl_Filter_TD_796679_output);
    gettimeofday(&tv_r_Filter_7_658540_e, 0);

    struct timeval tv_r_JOIN_INNER_7_442724_s, tv_r_JOIN_INNER_7_442724_e;
    gettimeofday(&tv_r_JOIN_INNER_7_442724_s, 0);
    prev_events_grp_JOIN_INNER_TD_7768905.push_back(events_h2d_wr_JOIN_INNER_TD_8855685[0]);
    trans_JOIN_INNER_TD_7768905.add(&(tbl_Filter_TD_8869253_output));
    trans_JOIN_INNER_TD_7768905.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7768905), &(events_h2d_wr_JOIN_INNER_TD_7768905[0]));
    events_grp_JOIN_INNER_TD_7768905.push_back(events_h2d_wr_JOIN_INNER_TD_7768905[0]);
    events_grp_JOIN_INNER_TD_7768905.push_back(events_JOIN_INNER_TD_8855685[0]);
    krnl_JOIN_INNER_TD_7768905.run(0, &(events_grp_JOIN_INNER_TD_7768905), &(events_JOIN_INNER_TD_7768905[0]));
    
    trans_JOIN_INNER_TD_7768905_out.add(&(tbl_JOIN_INNER_TD_7768905_output));
    trans_JOIN_INNER_TD_7768905_out.dev2host(0, &(events_JOIN_INNER_TD_7768905), &(events_d2h_rd_JOIN_INNER_TD_7768905[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_7_442724_e, 0);

    struct timeval tv_r_JOIN_INNER_6_416402_s, tv_r_JOIN_INNER_6_416402_e;
    gettimeofday(&tv_r_JOIN_INNER_6_416402_s, 0);
    SW_JOIN_INNER_TD_6187048(tbl_JOIN_INNER_TD_7768905_output, tbl_Filter_TD_796679_output, tbl_JOIN_INNER_TD_6187048_output);
    gettimeofday(&tv_r_JOIN_INNER_6_416402_e, 0);

    struct timeval tv_r_Filter_5_515074_s, tv_r_Filter_5_515074_e;
    gettimeofday(&tv_r_Filter_5_515074_s, 0);
    SW_Filter_TD_5896878(tbl_SerializeFromObject_TD_663806_input, tbl_Filter_TD_5896878_output);
    gettimeofday(&tv_r_Filter_5_515074_e, 0);

    struct timeval tv_r_Aggregate_5_735994_s, tv_r_Aggregate_5_735994_e;
    gettimeofday(&tv_r_Aggregate_5_735994_s, 0);
    SW_Aggregate_TD_5312256(tbl_JOIN_INNER_TD_6187048_output, tbl_Aggregate_TD_5312256_output);
    gettimeofday(&tv_r_Aggregate_5_735994_e, 0);

    struct timeval tv_r_Filter_4_621727_s, tv_r_Filter_4_621727_e;
    gettimeofday(&tv_r_Filter_4_621727_s, 0);
    SW_Filter_TD_453726(tbl_SerializeFromObject_TD_5411227_input, tbl_Filter_TD_453726_output);
    gettimeofday(&tv_r_Filter_4_621727_e, 0);

    struct timeval tv_r_JOIN_INNER_4_996005_s, tv_r_JOIN_INNER_4_996005_e;
    gettimeofday(&tv_r_JOIN_INNER_4_996005_s, 0);
    SW_JOIN_INNER_TD_4311690(tbl_Aggregate_TD_5312256_output, tbl_Filter_TD_5896878_output, tbl_JOIN_INNER_TD_4311690_output);
    gettimeofday(&tv_r_JOIN_INNER_4_996005_e, 0);

    struct timeval tv_r_JOIN_INNER_3_577182_s, tv_r_JOIN_INNER_3_577182_e;
    gettimeofday(&tv_r_JOIN_INNER_3_577182_s, 0);
    SW_JOIN_INNER_TD_3503031(tbl_JOIN_INNER_TD_4311690_output, tbl_Filter_TD_453726_output, tbl_JOIN_INNER_TD_3503031_output);
    gettimeofday(&tv_r_JOIN_INNER_3_577182_e, 0);

    struct timeval tv_r_Sort_2_715159_s, tv_r_Sort_2_715159_e;
    gettimeofday(&tv_r_Sort_2_715159_s, 0);
    SW_Sort_TD_2415189(tbl_JOIN_INNER_TD_3503031_output, tbl_Sort_TD_2415189_output);
    gettimeofday(&tv_r_Sort_2_715159_e, 0);

    struct timeval tv_r_LocalLimit_1_513639_s, tv_r_LocalLimit_1_513639_e;
    gettimeofday(&tv_r_LocalLimit_1_513639_s, 0);
    SW_LocalLimit_TD_1578119(tbl_Sort_TD_2415189_output, tbl_LocalLimit_TD_1578119_output);
    gettimeofday(&tv_r_LocalLimit_1_513639_e, 0);

    struct timeval tv_r_GlobalLimit_0_432572_s, tv_r_GlobalLimit_0_432572_e;
    gettimeofday(&tv_r_GlobalLimit_0_432572_s, 0);
    SW_GlobalLimit_TD_083063(tbl_LocalLimit_TD_1578119_output, tbl_GlobalLimit_TD_083063_output);
    gettimeofday(&tv_r_GlobalLimit_0_432572_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_710540_s, &tv_r_Filter_10_710540_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11966388_input: " << tbl_SerializeFromObject_TD_11966388_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_22438_s, &tv_r_Filter_10_22438_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11792256_input: " << tbl_SerializeFromObject_TD_11792256_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_489375_s, &tv_r_Filter_9_489375_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10195679_input: " << tbl_SerializeFromObject_TD_10195679_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_321401_s, &tv_r_JOIN_INNER_9_321401_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_10446092_output: " << tbl_Filter_TD_10446092_output.getNumRow() << " " << "tbl_Filter_TD_1023536_output: " << tbl_Filter_TD_1023536_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_498386_s, &tv_r_Filter_8_498386_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9167176_input: " << tbl_SerializeFromObject_TD_9167176_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_280433_s, &tv_r_JOIN_INNER_8_280433_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9401357_output: " << tbl_JOIN_INNER_TD_9401357_output.getNumRow() << " " << "tbl_Filter_TD_9289066_output: " << tbl_Filter_TD_9289066_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_658540_s, &tv_r_Filter_7_658540_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8155146_input: " << tbl_SerializeFromObject_TD_8155146_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_442724_s, &tv_r_JOIN_INNER_7_442724_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8855685_output: " << tbl_JOIN_INNER_TD_8855685_output.getNumRow() << " " << "tbl_Filter_TD_8869253_output: " << tbl_Filter_TD_8869253_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_416402_s, &tv_r_JOIN_INNER_6_416402_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7768905_output: " << tbl_JOIN_INNER_TD_7768905_output.getNumRow() << " " << "tbl_Filter_TD_796679_output: " << tbl_Filter_TD_796679_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_515074_s, &tv_r_Filter_5_515074_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_663806_input: " << tbl_SerializeFromObject_TD_663806_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_735994_s, &tv_r_Aggregate_5_735994_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6187048_output: " << tbl_JOIN_INNER_TD_6187048_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_621727_s, &tv_r_Filter_4_621727_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5411227_input: " << tbl_SerializeFromObject_TD_5411227_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_996005_s, &tv_r_JOIN_INNER_4_996005_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_5312256_output: " << tbl_Aggregate_TD_5312256_output.getNumRow() << " " << "tbl_Filter_TD_5896878_output: " << tbl_Filter_TD_5896878_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_577182_s, &tv_r_JOIN_INNER_3_577182_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4311690_output: " << tbl_JOIN_INNER_TD_4311690_output.getNumRow() << " " << "tbl_Filter_TD_453726_output: " << tbl_Filter_TD_453726_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_715159_s, &tv_r_Sort_2_715159_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3503031_output: " << tbl_JOIN_INNER_TD_3503031_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_513639_s, &tv_r_LocalLimit_1_513639_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2415189_output: " << tbl_Sort_TD_2415189_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_432572_s, &tv_r_GlobalLimit_0_432572_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1578119_output: " << tbl_LocalLimit_TD_1578119_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.2965348 * 1000 << "ms" << std::endl; 
    return 0; 
}
