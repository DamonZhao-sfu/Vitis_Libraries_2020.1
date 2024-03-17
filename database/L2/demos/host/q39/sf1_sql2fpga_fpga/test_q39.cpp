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

#include "cfgFunc_q39.hpp" 
#include "q39.hpp" 

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
    std::cout << "NOTE:running query #39\n."; 
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
    Table tbl_Sort_TD_0879350_output("tbl_Sort_TD_0879350_output", 6100000, 8, "");
    tbl_Sort_TD_0879350_output.allocateHost();
    Table tbl_Project_TD_1989169_output("tbl_Project_TD_1989169_output", 6100000, 8, "");
    tbl_Project_TD_1989169_output.allocateHost();
    Table tbl_JOIN_INNER_TD_2855441_output("tbl_JOIN_INNER_TD_2855441_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_2855441_output.allocateHost();
    Table tbl_Aggregate_TD_3609414_output("tbl_Aggregate_TD_3609414_output", 6100000, 4, "");
    tbl_Aggregate_TD_3609414_output.allocateHost();
    Table tbl_Aggregate_TD_3749183_output("tbl_Aggregate_TD_3749183_output", 6100000, 4, "");
    tbl_Aggregate_TD_3749183_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4416401_output("tbl_JOIN_INNER_TD_4416401_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_4416401_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4105155_output("tbl_JOIN_INNER_TD_4105155_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_4105155_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5695264_output("tbl_JOIN_INNER_TD_5695264_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_5695264_output.allocateHost();
    Table tbl_Filter_TD_590232_output("tbl_Filter_TD_590232_output", 6100000, 2, "");
    tbl_Filter_TD_590232_output.allocateHost();
    Table tbl_JOIN_INNER_TD_524399_output("tbl_JOIN_INNER_TD_524399_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_524399_output.allocateHost();
    Table tbl_Filter_TD_5755827_output("tbl_Filter_TD_5755827_output", 6100000, 2, "");
    tbl_Filter_TD_5755827_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6744667_output("tbl_JOIN_INNER_TD_6744667_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_6744667_output.allocateHost();
    Table tbl_Filter_TD_6115940_output("tbl_Filter_TD_6115940_output", 6100000, 2, "");
    tbl_Filter_TD_6115940_output.allocateHost();
    Table tbl_SerializeFromObject_TD_634398_input;
    tbl_SerializeFromObject_TD_634398_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_634398_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_634398_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_634398_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_634398_input.allocateHost();
    tbl_SerializeFromObject_TD_634398_input.loadHost();
    Table tbl_JOIN_INNER_TD_6378861_output("tbl_JOIN_INNER_TD_6378861_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_6378861_output.allocateHost();
    Table tbl_Filter_TD_6578507_output("tbl_Filter_TD_6578507_output", 6100000, 2, "");
    tbl_Filter_TD_6578507_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6323741_input;
    tbl_SerializeFromObject_TD_6323741_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_6323741_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_6323741_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_6323741_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_6323741_input.allocateHost();
    tbl_SerializeFromObject_TD_6323741_input.loadHost();
    Table tbl_Filter_TD_7159328_output("tbl_Filter_TD_7159328_output", 6100000, 4, "");
    tbl_Filter_TD_7159328_output.allocateHost();
    Table tbl_Filter_TD_7725992_output("tbl_Filter_TD_7725992_output", 6100000, 1, "");
    tbl_Filter_TD_7725992_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7758238_input;
    tbl_SerializeFromObject_TD_7758238_input = Table("warehouse", warehouse_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7758238_input.addCol("w_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_7758238_input.addCol("w_warehouse_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7758238_input.allocateHost();
    tbl_SerializeFromObject_TD_7758238_input.loadHost();
    Table tbl_Filter_TD_7266744_output("tbl_Filter_TD_7266744_output", 6100000, 4, "");
    tbl_Filter_TD_7266744_output.allocateHost();
    Table tbl_Filter_TD_7396602_output("tbl_Filter_TD_7396602_output", 6100000, 1, "");
    tbl_Filter_TD_7396602_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7888077_input;
    tbl_SerializeFromObject_TD_7888077_input = Table("warehouse", warehouse_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7888077_input.addCol("w_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_7888077_input.addCol("w_warehouse_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7888077_input.allocateHost();
    tbl_SerializeFromObject_TD_7888077_input.loadHost();
    Table tbl_SerializeFromObject_TD_8335970_input;
    tbl_SerializeFromObject_TD_8335970_input = Table("inventory", inventory_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_8335970_input.addCol("inv_date_sk", 4);
    tbl_SerializeFromObject_TD_8335970_input.addCol("inv_item_sk", 4);
    tbl_SerializeFromObject_TD_8335970_input.addCol("inv_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_8335970_input.addCol("inv_quantity_on_hand", 4);
    tbl_SerializeFromObject_TD_8335970_input.allocateHost();
    tbl_SerializeFromObject_TD_8335970_input.loadHost();
    Table tbl_SerializeFromObject_TD_8487683_input;
    tbl_SerializeFromObject_TD_8487683_input = Table("item", item_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_8487683_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_8487683_input.allocateHost();
    tbl_SerializeFromObject_TD_8487683_input.loadHost();
    Table tbl_SerializeFromObject_TD_8947352_input;
    tbl_SerializeFromObject_TD_8947352_input = Table("inventory", inventory_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_8947352_input.addCol("inv_date_sk", 4);
    tbl_SerializeFromObject_TD_8947352_input.addCol("inv_item_sk", 4);
    tbl_SerializeFromObject_TD_8947352_input.addCol("inv_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_8947352_input.addCol("inv_quantity_on_hand", 4);
    tbl_SerializeFromObject_TD_8947352_input.allocateHost();
    tbl_SerializeFromObject_TD_8947352_input.loadHost();
    Table tbl_SerializeFromObject_TD_8323268_input;
    tbl_SerializeFromObject_TD_8323268_input = Table("item", item_n, 1, in_dir, "orc");
    tbl_SerializeFromObject_TD_8323268_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_8323268_input.allocateHost();
    tbl_SerializeFromObject_TD_8323268_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_2855441_output.allocateDevBuffer(context_h, 32);
    tbl_Aggregate_TD_3609414_output.allocateDevBuffer(context_h, 32);
    tbl_Aggregate_TD_3749183_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_6744667_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_6378861_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_7159328_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_7725992_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_7266744_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_7396602_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_2855441_cmds;
    cfg_JOIN_INNER_TD_2855441_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_2855441_gqe_join (cfg_JOIN_INNER_TD_2855441_cmds.cmd);
    cfg_JOIN_INNER_TD_2855441_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_6744667_cmds;
    cfg_JOIN_INNER_TD_6744667_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_6744667_gqe_join (cfg_JOIN_INNER_TD_6744667_cmds.cmd);
    cfg_JOIN_INNER_TD_6744667_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_6378861_cmds;
    cfg_JOIN_INNER_TD_6378861_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_6378861_gqe_join (cfg_JOIN_INNER_TD_6378861_cmds.cmd);
    cfg_JOIN_INNER_TD_6378861_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_2855441;
    krnl_JOIN_INNER_TD_2855441 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_2855441.setup(tbl_Aggregate_TD_3609414_output, tbl_Aggregate_TD_3749183_output, tbl_JOIN_INNER_TD_2855441_output, cfg_JOIN_INNER_TD_2855441_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_6744667;
    krnl_JOIN_INNER_TD_6744667 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_6744667.setup(tbl_Filter_TD_7159328_output, tbl_Filter_TD_7725992_output, tbl_JOIN_INNER_TD_6744667_output, cfg_JOIN_INNER_TD_6744667_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_6378861;
    krnl_JOIN_INNER_TD_6378861 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_6378861.setup(tbl_Filter_TD_7266744_output, tbl_Filter_TD_7396602_output, tbl_JOIN_INNER_TD_6378861_output, cfg_JOIN_INNER_TD_6378861_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_2855441;
    trans_JOIN_INNER_TD_2855441.setq(q_h);
    trans_JOIN_INNER_TD_2855441.add(&(cfg_JOIN_INNER_TD_2855441_cmds));
    transEngine trans_JOIN_INNER_TD_2855441_out;
    trans_JOIN_INNER_TD_2855441_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_6744667;
    trans_JOIN_INNER_TD_6744667.setq(q_h);
    trans_JOIN_INNER_TD_6744667.add(&(cfg_JOIN_INNER_TD_6744667_cmds));
    transEngine trans_JOIN_INNER_TD_6744667_out;
    trans_JOIN_INNER_TD_6744667_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_6378861;
    trans_JOIN_INNER_TD_6378861.setq(q_h);
    trans_JOIN_INNER_TD_6378861.add(&(cfg_JOIN_INNER_TD_6378861_cmds));
    transEngine trans_JOIN_INNER_TD_6378861_out;
    trans_JOIN_INNER_TD_6378861_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_2855441;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_2855441;
    std::vector<cl::Event> events_JOIN_INNER_TD_2855441;
    events_h2d_wr_JOIN_INNER_TD_2855441.resize(1);
    events_d2h_rd_JOIN_INNER_TD_2855441.resize(1);
    events_JOIN_INNER_TD_2855441.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_2855441;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_2855441;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_6744667;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_6744667;
    std::vector<cl::Event> events_JOIN_INNER_TD_6744667;
    events_h2d_wr_JOIN_INNER_TD_6744667.resize(1);
    events_d2h_rd_JOIN_INNER_TD_6744667.resize(1);
    events_JOIN_INNER_TD_6744667.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_6744667;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_6744667;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_6378861;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_6378861;
    std::vector<cl::Event> events_JOIN_INNER_TD_6378861;
    events_h2d_wr_JOIN_INNER_TD_6378861.resize(1);
    events_d2h_rd_JOIN_INNER_TD_6378861.resize(1);
    events_JOIN_INNER_TD_6378861.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_6378861;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_6378861;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_7_63998_s, tv_r_Filter_7_63998_e;
    gettimeofday(&tv_r_Filter_7_63998_s, 0);
    SW_Filter_TD_7396602(tbl_SerializeFromObject_TD_8323268_input, tbl_Filter_TD_7396602_output);
    gettimeofday(&tv_r_Filter_7_63998_e, 0);

    struct timeval tv_r_Filter_7_283656_s, tv_r_Filter_7_283656_e;
    gettimeofday(&tv_r_Filter_7_283656_s, 0);
    SW_Filter_TD_7266744(tbl_SerializeFromObject_TD_8947352_input, tbl_Filter_TD_7266744_output);
    gettimeofday(&tv_r_Filter_7_283656_e, 0);

    struct timeval tv_r_Filter_7_628220_s, tv_r_Filter_7_628220_e;
    gettimeofday(&tv_r_Filter_7_628220_s, 0);
    SW_Filter_TD_7725992(tbl_SerializeFromObject_TD_8487683_input, tbl_Filter_TD_7725992_output);
    gettimeofday(&tv_r_Filter_7_628220_e, 0);

    struct timeval tv_r_Filter_7_445711_s, tv_r_Filter_7_445711_e;
    gettimeofday(&tv_r_Filter_7_445711_s, 0);
    SW_Filter_TD_7159328(tbl_SerializeFromObject_TD_8335970_input, tbl_Filter_TD_7159328_output);
    gettimeofday(&tv_r_Filter_7_445711_e, 0);

    struct timeval tv_r_Filter_6_419819_s, tv_r_Filter_6_419819_e;
    gettimeofday(&tv_r_Filter_6_419819_s, 0);
    SW_Filter_TD_6578507(tbl_SerializeFromObject_TD_7888077_input, tbl_Filter_TD_6578507_output);
    gettimeofday(&tv_r_Filter_6_419819_e, 0);

    struct timeval tv_r_JOIN_INNER_6_668313_s, tv_r_JOIN_INNER_6_668313_e;
    gettimeofday(&tv_r_JOIN_INNER_6_668313_s, 0);
    trans_JOIN_INNER_TD_6378861.add(&(tbl_Filter_TD_7266744_output));
    trans_JOIN_INNER_TD_6378861.add(&(tbl_Filter_TD_7396602_output));
    trans_JOIN_INNER_TD_6378861.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_6378861), &(events_h2d_wr_JOIN_INNER_TD_6378861[0]));
    events_grp_JOIN_INNER_TD_6378861.push_back(events_h2d_wr_JOIN_INNER_TD_6378861[0]);
    krnl_JOIN_INNER_TD_6378861.run(0, &(events_grp_JOIN_INNER_TD_6378861), &(events_JOIN_INNER_TD_6378861[0]));
    
    trans_JOIN_INNER_TD_6378861_out.add(&(tbl_JOIN_INNER_TD_6378861_output));
    trans_JOIN_INNER_TD_6378861_out.dev2host(0, &(events_JOIN_INNER_TD_6378861), &(events_d2h_rd_JOIN_INNER_TD_6378861[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_6_668313_e, 0);

    struct timeval tv_r_Filter_6_138553_s, tv_r_Filter_6_138553_e;
    gettimeofday(&tv_r_Filter_6_138553_s, 0);
    SW_Filter_TD_6115940(tbl_SerializeFromObject_TD_7758238_input, tbl_Filter_TD_6115940_output);
    gettimeofday(&tv_r_Filter_6_138553_e, 0);

    struct timeval tv_r_JOIN_INNER_6_6390_s, tv_r_JOIN_INNER_6_6390_e;
    gettimeofday(&tv_r_JOIN_INNER_6_6390_s, 0);
    trans_JOIN_INNER_TD_6744667.add(&(tbl_Filter_TD_7159328_output));
    trans_JOIN_INNER_TD_6744667.add(&(tbl_Filter_TD_7725992_output));
    trans_JOIN_INNER_TD_6744667.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_6744667), &(events_h2d_wr_JOIN_INNER_TD_6744667[0]));
    events_grp_JOIN_INNER_TD_6744667.push_back(events_h2d_wr_JOIN_INNER_TD_6744667[0]);
    krnl_JOIN_INNER_TD_6744667.run(0, &(events_grp_JOIN_INNER_TD_6744667), &(events_JOIN_INNER_TD_6744667[0]));
    
    trans_JOIN_INNER_TD_6744667_out.add(&(tbl_JOIN_INNER_TD_6744667_output));
    trans_JOIN_INNER_TD_6744667_out.dev2host(0, &(events_JOIN_INNER_TD_6744667), &(events_d2h_rd_JOIN_INNER_TD_6744667[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_6_6390_e, 0);

    struct timeval tv_r_Filter_5_682595_s, tv_r_Filter_5_682595_e;
    gettimeofday(&tv_r_Filter_5_682595_s, 0);
    SW_Filter_TD_5755827(tbl_SerializeFromObject_TD_6323741_input, tbl_Filter_TD_5755827_output);
    gettimeofday(&tv_r_Filter_5_682595_e, 0);

    struct timeval tv_r_JOIN_INNER_5_961124_s, tv_r_JOIN_INNER_5_961124_e;
    gettimeofday(&tv_r_JOIN_INNER_5_961124_s, 0);
    SW_JOIN_INNER_TD_524399(tbl_JOIN_INNER_TD_6378861_output, tbl_Filter_TD_6578507_output, tbl_JOIN_INNER_TD_524399_output);
    gettimeofday(&tv_r_JOIN_INNER_5_961124_e, 0);

    struct timeval tv_r_Filter_5_411744_s, tv_r_Filter_5_411744_e;
    gettimeofday(&tv_r_Filter_5_411744_s, 0);
    SW_Filter_TD_590232(tbl_SerializeFromObject_TD_634398_input, tbl_Filter_TD_590232_output);
    gettimeofday(&tv_r_Filter_5_411744_e, 0);

    struct timeval tv_r_JOIN_INNER_5_31180_s, tv_r_JOIN_INNER_5_31180_e;
    gettimeofday(&tv_r_JOIN_INNER_5_31180_s, 0);
    SW_JOIN_INNER_TD_5695264(tbl_JOIN_INNER_TD_6744667_output, tbl_Filter_TD_6115940_output, tbl_JOIN_INNER_TD_5695264_output);
    gettimeofday(&tv_r_JOIN_INNER_5_31180_e, 0);

    struct timeval tv_r_JOIN_INNER_4_331952_s, tv_r_JOIN_INNER_4_331952_e;
    gettimeofday(&tv_r_JOIN_INNER_4_331952_s, 0);
    SW_JOIN_INNER_TD_4105155(tbl_JOIN_INNER_TD_524399_output, tbl_Filter_TD_5755827_output, tbl_JOIN_INNER_TD_4105155_output);
    gettimeofday(&tv_r_JOIN_INNER_4_331952_e, 0);

    struct timeval tv_r_JOIN_INNER_4_232409_s, tv_r_JOIN_INNER_4_232409_e;
    gettimeofday(&tv_r_JOIN_INNER_4_232409_s, 0);
    SW_JOIN_INNER_TD_4416401(tbl_JOIN_INNER_TD_5695264_output, tbl_Filter_TD_590232_output, tbl_JOIN_INNER_TD_4416401_output);
    gettimeofday(&tv_r_JOIN_INNER_4_232409_e, 0);

    struct timeval tv_r_Aggregate_3_634940_s, tv_r_Aggregate_3_634940_e;
    gettimeofday(&tv_r_Aggregate_3_634940_s, 0);
    SW_Aggregate_TD_3749183(tbl_JOIN_INNER_TD_4105155_output, tbl_Aggregate_TD_3749183_output);
    gettimeofday(&tv_r_Aggregate_3_634940_e, 0);

    struct timeval tv_r_Aggregate_3_731524_s, tv_r_Aggregate_3_731524_e;
    gettimeofday(&tv_r_Aggregate_3_731524_s, 0);
    SW_Aggregate_TD_3609414(tbl_JOIN_INNER_TD_4416401_output, tbl_Aggregate_TD_3609414_output);
    gettimeofday(&tv_r_Aggregate_3_731524_e, 0);

    struct timeval tv_r_JOIN_INNER_2_189599_s, tv_r_JOIN_INNER_2_189599_e;
    gettimeofday(&tv_r_JOIN_INNER_2_189599_s, 0);
    trans_JOIN_INNER_TD_2855441.add(&(tbl_Aggregate_TD_3609414_output));
    trans_JOIN_INNER_TD_2855441.add(&(tbl_Aggregate_TD_3749183_output));
    trans_JOIN_INNER_TD_2855441.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_2855441), &(events_h2d_wr_JOIN_INNER_TD_2855441[0]));
    events_grp_JOIN_INNER_TD_2855441.push_back(events_h2d_wr_JOIN_INNER_TD_2855441[0]);
    krnl_JOIN_INNER_TD_2855441.run(0, &(events_grp_JOIN_INNER_TD_2855441), &(events_JOIN_INNER_TD_2855441[0]));
    
    trans_JOIN_INNER_TD_2855441_out.add(&(tbl_JOIN_INNER_TD_2855441_output));
    trans_JOIN_INNER_TD_2855441_out.dev2host(0, &(events_JOIN_INNER_TD_2855441), &(events_d2h_rd_JOIN_INNER_TD_2855441[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_2_189599_e, 0);

    struct timeval tv_r_Project_1_958820_s, tv_r_Project_1_958820_e;
    gettimeofday(&tv_r_Project_1_958820_s, 0);
    SW_Project_TD_1989169(tbl_JOIN_INNER_TD_2855441_output, tbl_Project_TD_1989169_output);
    gettimeofday(&tv_r_Project_1_958820_e, 0);

    struct timeval tv_r_Sort_0_700943_s, tv_r_Sort_0_700943_e;
    gettimeofday(&tv_r_Sort_0_700943_s, 0);
    SW_Sort_TD_0879350(tbl_Project_TD_1989169_output, tbl_Sort_TD_0879350_output);
    gettimeofday(&tv_r_Sort_0_700943_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_63998_s, &tv_r_Filter_7_63998_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8323268_input: " << tbl_SerializeFromObject_TD_8323268_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_283656_s, &tv_r_Filter_7_283656_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8947352_input: " << tbl_SerializeFromObject_TD_8947352_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_628220_s, &tv_r_Filter_7_628220_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8487683_input: " << tbl_SerializeFromObject_TD_8487683_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_445711_s, &tv_r_Filter_7_445711_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8335970_input: " << tbl_SerializeFromObject_TD_8335970_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_419819_s, &tv_r_Filter_6_419819_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7888077_input: " << tbl_SerializeFromObject_TD_7888077_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_668313_s, &tv_r_JOIN_INNER_6_668313_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_7266744_output: " << tbl_Filter_TD_7266744_output.getNumRow() << " " << "tbl_Filter_TD_7396602_output: " << tbl_Filter_TD_7396602_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_138553_s, &tv_r_Filter_6_138553_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7758238_input: " << tbl_SerializeFromObject_TD_7758238_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_6390_s, &tv_r_JOIN_INNER_6_6390_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_7159328_output: " << tbl_Filter_TD_7159328_output.getNumRow() << " " << "tbl_Filter_TD_7725992_output: " << tbl_Filter_TD_7725992_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_682595_s, &tv_r_Filter_5_682595_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6323741_input: " << tbl_SerializeFromObject_TD_6323741_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_961124_s, &tv_r_JOIN_INNER_5_961124_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6378861_output: " << tbl_JOIN_INNER_TD_6378861_output.getNumRow() << " " << "tbl_Filter_TD_6578507_output: " << tbl_Filter_TD_6578507_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_411744_s, &tv_r_Filter_5_411744_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_634398_input: " << tbl_SerializeFromObject_TD_634398_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_31180_s, &tv_r_JOIN_INNER_5_31180_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6744667_output: " << tbl_JOIN_INNER_TD_6744667_output.getNumRow() << " " << "tbl_Filter_TD_6115940_output: " << tbl_Filter_TD_6115940_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_331952_s, &tv_r_JOIN_INNER_4_331952_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_524399_output: " << tbl_JOIN_INNER_TD_524399_output.getNumRow() << " " << "tbl_Filter_TD_5755827_output: " << tbl_Filter_TD_5755827_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_232409_s, &tv_r_JOIN_INNER_4_232409_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5695264_output: " << tbl_JOIN_INNER_TD_5695264_output.getNumRow() << " " << "tbl_Filter_TD_590232_output: " << tbl_Filter_TD_590232_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_634940_s, &tv_r_Aggregate_3_634940_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4105155_output: " << tbl_JOIN_INNER_TD_4105155_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_731524_s, &tv_r_Aggregate_3_731524_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4416401_output: " << tbl_JOIN_INNER_TD_4416401_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_2: " << tvdiff(&tv_r_JOIN_INNER_2_189599_s, &tv_r_JOIN_INNER_2_189599_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3609414_output: " << tbl_Aggregate_TD_3609414_output.getNumRow() << " " << "tbl_Aggregate_TD_3749183_output: " << tbl_Aggregate_TD_3749183_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_1: " << tvdiff(&tv_r_Project_1_958820_s, &tv_r_Project_1_958820_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_2855441_output: " << tbl_JOIN_INNER_TD_2855441_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_700943_s, &tv_r_Sort_0_700943_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_1989169_output: " << tbl_Project_TD_1989169_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 3.4103127 * 1000 << "ms" << std::endl; 
    return 0; 
}
