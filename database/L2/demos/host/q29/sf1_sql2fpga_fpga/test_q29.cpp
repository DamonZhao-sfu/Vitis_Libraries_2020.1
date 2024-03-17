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

#include "cfgFunc_q29.hpp" 
#include "q29.hpp" 

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
    std::cout << "NOTE:running query #29\n."; 
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
    Table tbl_GlobalLimit_TD_0942974_output("tbl_GlobalLimit_TD_0942974_output", 6100000, 7, "");
    tbl_GlobalLimit_TD_0942974_output.allocateHost();
    Table tbl_LocalLimit_TD_1333569_output("tbl_LocalLimit_TD_1333569_output", 6100000, 7, "");
    tbl_LocalLimit_TD_1333569_output.allocateHost();
    Table tbl_Sort_TD_2872649_output("tbl_Sort_TD_2872649_output", 6100000, 7, "");
    tbl_Sort_TD_2872649_output.allocateHost();
    Table tbl_Aggregate_TD_3367866_output("tbl_Aggregate_TD_3367866_output", 6100000, 7, "");
    tbl_Aggregate_TD_3367866_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4153215_output("tbl_JOIN_INNER_TD_4153215_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_4153215_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5893074_output("tbl_JOIN_INNER_TD_5893074_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_5893074_output.allocateHost();
    Table tbl_Filter_TD_5387834_output("tbl_Filter_TD_5387834_output", 6100000, 3, "");
    tbl_Filter_TD_5387834_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6457328_output("tbl_JOIN_INNER_TD_6457328_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_6457328_output.allocateHost();
    Table tbl_Filter_TD_6473560_output("tbl_Filter_TD_6473560_output", 6100000, 3, "");
    tbl_Filter_TD_6473560_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6514562_input;
    tbl_SerializeFromObject_TD_6514562_input = Table("item", item_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_6514562_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_6514562_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6514562_input.addCol("i_item_desc", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6514562_input.allocateHost();
    tbl_SerializeFromObject_TD_6514562_input.loadHost();
    Table tbl_JOIN_INNER_TD_7869579_output("tbl_JOIN_INNER_TD_7869579_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_7869579_output.allocateHost();
    Table tbl_Filter_TD_748438_output("tbl_Filter_TD_748438_output", 6100000, 1, "");
    tbl_Filter_TD_748438_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7746550_input;
    tbl_SerializeFromObject_TD_7746550_input = Table("store", store_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7746550_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_7746550_input.addCol("s_store_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7746550_input.addCol("s_store_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7746550_input.allocateHost();
    tbl_SerializeFromObject_TD_7746550_input.loadHost();
    Table tbl_JOIN_INNER_TD_8671694_output("tbl_JOIN_INNER_TD_8671694_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_8671694_output.allocateHost();
    Table tbl_Filter_TD_8904232_output("tbl_Filter_TD_8904232_output", 6100000, 1, "");
    tbl_Filter_TD_8904232_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8574833_input;
    tbl_SerializeFromObject_TD_8574833_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8574833_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_8574833_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_8574833_input.allocateHost();
    tbl_SerializeFromObject_TD_8574833_input.loadHost();
    Table tbl_JOIN_INNER_TD_960556_output("tbl_JOIN_INNER_TD_960556_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_960556_output.allocateHost();
    Table tbl_Filter_TD_9953731_output("tbl_Filter_TD_9953731_output", 6100000, 1, "");
    tbl_Filter_TD_9953731_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9142686_input;
    tbl_SerializeFromObject_TD_9142686_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9142686_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_9142686_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_9142686_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_9142686_input.allocateHost();
    tbl_SerializeFromObject_TD_9142686_input.loadHost();
    Table tbl_JOIN_INNER_TD_1055627_output("tbl_JOIN_INNER_TD_1055627_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_1055627_output.allocateHost();
    Table tbl_Filter_TD_10519510_output("tbl_Filter_TD_10519510_output", 6100000, 4, "");
    tbl_Filter_TD_10519510_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10942565_input;
    tbl_SerializeFromObject_TD_10942565_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10942565_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10942565_input.addCol("d_moy", 4);
    tbl_SerializeFromObject_TD_10942565_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10942565_input.allocateHost();
    tbl_SerializeFromObject_TD_10942565_input.loadHost();
    Table tbl_Filter_TD_11329129_output("tbl_Filter_TD_11329129_output", 6100000, 6, "");
    tbl_Filter_TD_11329129_output.allocateHost();
    Table tbl_Filter_TD_11310146_output("tbl_Filter_TD_11310146_output", 6100000, 5, "");
    tbl_Filter_TD_11310146_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11931567_input;
    tbl_SerializeFromObject_TD_11931567_input = Table("catalog_sales", catalog_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_11931567_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_11931567_input.addCol("cs_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_11931567_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_11931567_input.addCol("cs_quantity", 4);
    tbl_SerializeFromObject_TD_11931567_input.allocateHost();
    tbl_SerializeFromObject_TD_11931567_input.loadHost();
    Table tbl_SerializeFromObject_TD_12221690_input;
    tbl_SerializeFromObject_TD_12221690_input = Table("store_sales", store_sales_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_12221690_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_12221690_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_12221690_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_12221690_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_12221690_input.addCol("ss_ticket_number", 8);
    tbl_SerializeFromObject_TD_12221690_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_12221690_input.allocateHost();
    tbl_SerializeFromObject_TD_12221690_input.loadHost();
    Table tbl_SerializeFromObject_TD_12161815_input;
    tbl_SerializeFromObject_TD_12161815_input = Table("store_returns", store_returns_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_12161815_input.addCol("sr_returned_date_sk", 4);
    tbl_SerializeFromObject_TD_12161815_input.addCol("sr_item_sk", 4);
    tbl_SerializeFromObject_TD_12161815_input.addCol("sr_customer_sk", 4);
    tbl_SerializeFromObject_TD_12161815_input.addCol("sr_ticket_number", 8);
    tbl_SerializeFromObject_TD_12161815_input.addCol("sr_return_quantity", 4);
    tbl_SerializeFromObject_TD_12161815_input.allocateHost();
    tbl_SerializeFromObject_TD_12161815_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_6457328_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_7869579_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_748438_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8671694_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8904232_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_960556_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9953731_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_1055627_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10519510_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_6457328_cmds;
    cfg_JOIN_INNER_TD_6457328_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_6457328_gqe_join (cfg_JOIN_INNER_TD_6457328_cmds.cmd);
    cfg_JOIN_INNER_TD_6457328_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7869579_cmds;
    cfg_JOIN_INNER_TD_7869579_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7869579_gqe_join (cfg_JOIN_INNER_TD_7869579_cmds.cmd);
    cfg_JOIN_INNER_TD_7869579_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8671694_cmds;
    cfg_JOIN_INNER_TD_8671694_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8671694_gqe_join (cfg_JOIN_INNER_TD_8671694_cmds.cmd);
    cfg_JOIN_INNER_TD_8671694_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_960556_cmds;
    cfg_JOIN_INNER_TD_960556_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_960556_gqe_join (cfg_JOIN_INNER_TD_960556_cmds.cmd);
    cfg_JOIN_INNER_TD_960556_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_6457328;
    krnl_JOIN_INNER_TD_6457328 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_6457328.setup(tbl_JOIN_INNER_TD_7869579_output, tbl_Filter_TD_748438_output, tbl_JOIN_INNER_TD_6457328_output, cfg_JOIN_INNER_TD_6457328_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_7869579;
    krnl_JOIN_INNER_TD_7869579 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7869579.setup(tbl_JOIN_INNER_TD_8671694_output, tbl_Filter_TD_8904232_output, tbl_JOIN_INNER_TD_7869579_output, cfg_JOIN_INNER_TD_7869579_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_8671694;
    krnl_JOIN_INNER_TD_8671694 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8671694.setup(tbl_JOIN_INNER_TD_960556_output, tbl_Filter_TD_9953731_output, tbl_JOIN_INNER_TD_8671694_output, cfg_JOIN_INNER_TD_8671694_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_960556;
    krnl_JOIN_INNER_TD_960556 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_960556.setup(tbl_JOIN_INNER_TD_1055627_output, tbl_Filter_TD_10519510_output, tbl_JOIN_INNER_TD_960556_output, cfg_JOIN_INNER_TD_960556_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_6457328;
    trans_JOIN_INNER_TD_6457328.setq(q_h);
    trans_JOIN_INNER_TD_6457328.add(&(cfg_JOIN_INNER_TD_6457328_cmds));
    transEngine trans_JOIN_INNER_TD_6457328_out;
    trans_JOIN_INNER_TD_6457328_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_7869579;
    trans_JOIN_INNER_TD_7869579.setq(q_h);
    trans_JOIN_INNER_TD_7869579.add(&(cfg_JOIN_INNER_TD_7869579_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_8671694;
    trans_JOIN_INNER_TD_8671694.setq(q_h);
    trans_JOIN_INNER_TD_8671694.add(&(cfg_JOIN_INNER_TD_8671694_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_960556;
    trans_JOIN_INNER_TD_960556.setq(q_h);
    trans_JOIN_INNER_TD_960556.add(&(cfg_JOIN_INNER_TD_960556_cmds));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_6457328;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_6457328;
    std::vector<cl::Event> events_JOIN_INNER_TD_6457328;
    events_h2d_wr_JOIN_INNER_TD_6457328.resize(1);
    events_d2h_rd_JOIN_INNER_TD_6457328.resize(1);
    events_JOIN_INNER_TD_6457328.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_6457328;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_6457328;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7869579;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7869579;
    std::vector<cl::Event> events_JOIN_INNER_TD_7869579;
    events_h2d_wr_JOIN_INNER_TD_7869579.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7869579.resize(1);
    events_JOIN_INNER_TD_7869579.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7869579;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7869579;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8671694;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8671694;
    std::vector<cl::Event> events_JOIN_INNER_TD_8671694;
    events_h2d_wr_JOIN_INNER_TD_8671694.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8671694.resize(1);
    events_JOIN_INNER_TD_8671694.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8671694;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8671694;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_960556;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_960556;
    std::vector<cl::Event> events_JOIN_INNER_TD_960556;
    events_h2d_wr_JOIN_INNER_TD_960556.resize(1);
    events_d2h_rd_JOIN_INNER_TD_960556.resize(1);
    events_JOIN_INNER_TD_960556.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_960556;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_960556;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_11_475794_s, tv_r_Filter_11_475794_e;
    gettimeofday(&tv_r_Filter_11_475794_s, 0);
    SW_Filter_TD_11310146(tbl_SerializeFromObject_TD_12161815_input, tbl_Filter_TD_11310146_output);
    gettimeofday(&tv_r_Filter_11_475794_e, 0);

    struct timeval tv_r_Filter_11_563689_s, tv_r_Filter_11_563689_e;
    gettimeofday(&tv_r_Filter_11_563689_s, 0);
    SW_Filter_TD_11329129(tbl_SerializeFromObject_TD_12221690_input, tbl_Filter_TD_11329129_output);
    gettimeofday(&tv_r_Filter_11_563689_e, 0);

    struct timeval tv_r_Filter_10_96025_s, tv_r_Filter_10_96025_e;
    gettimeofday(&tv_r_Filter_10_96025_s, 0);
    SW_Filter_TD_10519510(tbl_SerializeFromObject_TD_11931567_input, tbl_Filter_TD_10519510_output);
    gettimeofday(&tv_r_Filter_10_96025_e, 0);

    struct timeval tv_r_JOIN_INNER_10_520888_s, tv_r_JOIN_INNER_10_520888_e;
    gettimeofday(&tv_r_JOIN_INNER_10_520888_s, 0);
    SW_JOIN_INNER_TD_1055627(tbl_Filter_TD_11329129_output, tbl_Filter_TD_11310146_output, tbl_JOIN_INNER_TD_1055627_output);
    gettimeofday(&tv_r_JOIN_INNER_10_520888_e, 0);

    struct timeval tv_r_Filter_9_121480_s, tv_r_Filter_9_121480_e;
    gettimeofday(&tv_r_Filter_9_121480_s, 0);
    SW_Filter_TD_9953731(tbl_SerializeFromObject_TD_10942565_input, tbl_Filter_TD_9953731_output);
    gettimeofday(&tv_r_Filter_9_121480_e, 0);

    struct timeval tv_r_JOIN_INNER_9_574129_s, tv_r_JOIN_INNER_9_574129_e;
    gettimeofday(&tv_r_JOIN_INNER_9_574129_s, 0);
    trans_JOIN_INNER_TD_960556.add(&(tbl_JOIN_INNER_TD_1055627_output));
    trans_JOIN_INNER_TD_960556.add(&(tbl_Filter_TD_10519510_output));
    trans_JOIN_INNER_TD_960556.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_960556), &(events_h2d_wr_JOIN_INNER_TD_960556[0]));
    events_grp_JOIN_INNER_TD_960556.push_back(events_h2d_wr_JOIN_INNER_TD_960556[0]);
    krnl_JOIN_INNER_TD_960556.run(0, &(events_grp_JOIN_INNER_TD_960556), &(events_JOIN_INNER_TD_960556[0]));
    gettimeofday(&tv_r_JOIN_INNER_9_574129_e, 0);

    struct timeval tv_r_Filter_8_522975_s, tv_r_Filter_8_522975_e;
    gettimeofday(&tv_r_Filter_8_522975_s, 0);
    SW_Filter_TD_8904232(tbl_SerializeFromObject_TD_9142686_input, tbl_Filter_TD_8904232_output);
    gettimeofday(&tv_r_Filter_8_522975_e, 0);

    struct timeval tv_r_JOIN_INNER_8_854776_s, tv_r_JOIN_INNER_8_854776_e;
    gettimeofday(&tv_r_JOIN_INNER_8_854776_s, 0);
    prev_events_grp_JOIN_INNER_TD_8671694.push_back(events_h2d_wr_JOIN_INNER_TD_960556[0]);
    trans_JOIN_INNER_TD_8671694.add(&(tbl_Filter_TD_9953731_output));
    trans_JOIN_INNER_TD_8671694.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8671694), &(events_h2d_wr_JOIN_INNER_TD_8671694[0]));
    events_grp_JOIN_INNER_TD_8671694.push_back(events_h2d_wr_JOIN_INNER_TD_8671694[0]);
    events_grp_JOIN_INNER_TD_8671694.push_back(events_JOIN_INNER_TD_960556[0]);
    krnl_JOIN_INNER_TD_8671694.run(0, &(events_grp_JOIN_INNER_TD_8671694), &(events_JOIN_INNER_TD_8671694[0]));
    gettimeofday(&tv_r_JOIN_INNER_8_854776_e, 0);

    struct timeval tv_r_Filter_7_402693_s, tv_r_Filter_7_402693_e;
    gettimeofday(&tv_r_Filter_7_402693_s, 0);
    SW_Filter_TD_748438(tbl_SerializeFromObject_TD_8574833_input, tbl_Filter_TD_748438_output);
    gettimeofday(&tv_r_Filter_7_402693_e, 0);

    struct timeval tv_r_JOIN_INNER_7_50560_s, tv_r_JOIN_INNER_7_50560_e;
    gettimeofday(&tv_r_JOIN_INNER_7_50560_s, 0);
    prev_events_grp_JOIN_INNER_TD_7869579.push_back(events_h2d_wr_JOIN_INNER_TD_8671694[0]);
    trans_JOIN_INNER_TD_7869579.add(&(tbl_Filter_TD_8904232_output));
    trans_JOIN_INNER_TD_7869579.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7869579), &(events_h2d_wr_JOIN_INNER_TD_7869579[0]));
    events_grp_JOIN_INNER_TD_7869579.push_back(events_h2d_wr_JOIN_INNER_TD_7869579[0]);
    events_grp_JOIN_INNER_TD_7869579.push_back(events_JOIN_INNER_TD_8671694[0]);
    krnl_JOIN_INNER_TD_7869579.run(0, &(events_grp_JOIN_INNER_TD_7869579), &(events_JOIN_INNER_TD_7869579[0]));
    gettimeofday(&tv_r_JOIN_INNER_7_50560_e, 0);

    struct timeval tv_r_Filter_6_988699_s, tv_r_Filter_6_988699_e;
    gettimeofday(&tv_r_Filter_6_988699_s, 0);
    SW_Filter_TD_6473560(tbl_SerializeFromObject_TD_7746550_input, tbl_Filter_TD_6473560_output);
    gettimeofday(&tv_r_Filter_6_988699_e, 0);

    struct timeval tv_r_JOIN_INNER_6_689902_s, tv_r_JOIN_INNER_6_689902_e;
    gettimeofday(&tv_r_JOIN_INNER_6_689902_s, 0);
    prev_events_grp_JOIN_INNER_TD_6457328.push_back(events_h2d_wr_JOIN_INNER_TD_7869579[0]);
    trans_JOIN_INNER_TD_6457328.add(&(tbl_Filter_TD_748438_output));
    trans_JOIN_INNER_TD_6457328.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_6457328), &(events_h2d_wr_JOIN_INNER_TD_6457328[0]));
    events_grp_JOIN_INNER_TD_6457328.push_back(events_h2d_wr_JOIN_INNER_TD_6457328[0]);
    events_grp_JOIN_INNER_TD_6457328.push_back(events_JOIN_INNER_TD_7869579[0]);
    krnl_JOIN_INNER_TD_6457328.run(0, &(events_grp_JOIN_INNER_TD_6457328), &(events_JOIN_INNER_TD_6457328[0]));
    
    trans_JOIN_INNER_TD_6457328_out.add(&(tbl_JOIN_INNER_TD_6457328_output));
    trans_JOIN_INNER_TD_6457328_out.dev2host(0, &(events_JOIN_INNER_TD_6457328), &(events_d2h_rd_JOIN_INNER_TD_6457328[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_6_689902_e, 0);

    struct timeval tv_r_Filter_5_924956_s, tv_r_Filter_5_924956_e;
    gettimeofday(&tv_r_Filter_5_924956_s, 0);
    SW_Filter_TD_5387834(tbl_SerializeFromObject_TD_6514562_input, tbl_Filter_TD_5387834_output);
    gettimeofday(&tv_r_Filter_5_924956_e, 0);

    struct timeval tv_r_JOIN_INNER_5_994068_s, tv_r_JOIN_INNER_5_994068_e;
    gettimeofday(&tv_r_JOIN_INNER_5_994068_s, 0);
    SW_JOIN_INNER_TD_5893074(tbl_JOIN_INNER_TD_6457328_output, tbl_Filter_TD_6473560_output, tbl_JOIN_INNER_TD_5893074_output);
    gettimeofday(&tv_r_JOIN_INNER_5_994068_e, 0);

    struct timeval tv_r_JOIN_INNER_4_971463_s, tv_r_JOIN_INNER_4_971463_e;
    gettimeofday(&tv_r_JOIN_INNER_4_971463_s, 0);
    SW_JOIN_INNER_TD_4153215(tbl_JOIN_INNER_TD_5893074_output, tbl_Filter_TD_5387834_output, tbl_JOIN_INNER_TD_4153215_output);
    gettimeofday(&tv_r_JOIN_INNER_4_971463_e, 0);

    struct timeval tv_r_Aggregate_3_166919_s, tv_r_Aggregate_3_166919_e;
    gettimeofday(&tv_r_Aggregate_3_166919_s, 0);
    SW_Aggregate_TD_3367866(tbl_JOIN_INNER_TD_4153215_output, tbl_Aggregate_TD_3367866_output);
    gettimeofday(&tv_r_Aggregate_3_166919_e, 0);

    struct timeval tv_r_Sort_2_297436_s, tv_r_Sort_2_297436_e;
    gettimeofday(&tv_r_Sort_2_297436_s, 0);
    SW_Sort_TD_2872649(tbl_Aggregate_TD_3367866_output, tbl_Sort_TD_2872649_output);
    gettimeofday(&tv_r_Sort_2_297436_e, 0);

    struct timeval tv_r_LocalLimit_1_243568_s, tv_r_LocalLimit_1_243568_e;
    gettimeofday(&tv_r_LocalLimit_1_243568_s, 0);
    SW_LocalLimit_TD_1333569(tbl_Sort_TD_2872649_output, tbl_LocalLimit_TD_1333569_output);
    gettimeofday(&tv_r_LocalLimit_1_243568_e, 0);

    struct timeval tv_r_GlobalLimit_0_868461_s, tv_r_GlobalLimit_0_868461_e;
    gettimeofday(&tv_r_GlobalLimit_0_868461_s, 0);
    SW_GlobalLimit_TD_0942974(tbl_LocalLimit_TD_1333569_output, tbl_GlobalLimit_TD_0942974_output);
    gettimeofday(&tv_r_GlobalLimit_0_868461_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_475794_s, &tv_r_Filter_11_475794_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12161815_input: " << tbl_SerializeFromObject_TD_12161815_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_563689_s, &tv_r_Filter_11_563689_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12221690_input: " << tbl_SerializeFromObject_TD_12221690_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_96025_s, &tv_r_Filter_10_96025_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11931567_input: " << tbl_SerializeFromObject_TD_11931567_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_520888_s, &tv_r_JOIN_INNER_10_520888_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11329129_output: " << tbl_Filter_TD_11329129_output.getNumRow() << " " << "tbl_Filter_TD_11310146_output: " << tbl_Filter_TD_11310146_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_121480_s, &tv_r_Filter_9_121480_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10942565_input: " << tbl_SerializeFromObject_TD_10942565_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_574129_s, &tv_r_JOIN_INNER_9_574129_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_1055627_output: " << tbl_JOIN_INNER_TD_1055627_output.getNumRow() << " " << "tbl_Filter_TD_10519510_output: " << tbl_Filter_TD_10519510_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_522975_s, &tv_r_Filter_8_522975_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9142686_input: " << tbl_SerializeFromObject_TD_9142686_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_854776_s, &tv_r_JOIN_INNER_8_854776_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_960556_output: " << tbl_JOIN_INNER_TD_960556_output.getNumRow() << " " << "tbl_Filter_TD_9953731_output: " << tbl_Filter_TD_9953731_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_402693_s, &tv_r_Filter_7_402693_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8574833_input: " << tbl_SerializeFromObject_TD_8574833_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_50560_s, &tv_r_JOIN_INNER_7_50560_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8671694_output: " << tbl_JOIN_INNER_TD_8671694_output.getNumRow() << " " << "tbl_Filter_TD_8904232_output: " << tbl_Filter_TD_8904232_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_988699_s, &tv_r_Filter_6_988699_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7746550_input: " << tbl_SerializeFromObject_TD_7746550_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_689902_s, &tv_r_JOIN_INNER_6_689902_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7869579_output: " << tbl_JOIN_INNER_TD_7869579_output.getNumRow() << " " << "tbl_Filter_TD_748438_output: " << tbl_Filter_TD_748438_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_924956_s, &tv_r_Filter_5_924956_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6514562_input: " << tbl_SerializeFromObject_TD_6514562_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_994068_s, &tv_r_JOIN_INNER_5_994068_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6457328_output: " << tbl_JOIN_INNER_TD_6457328_output.getNumRow() << " " << "tbl_Filter_TD_6473560_output: " << tbl_Filter_TD_6473560_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_971463_s, &tv_r_JOIN_INNER_4_971463_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5893074_output: " << tbl_JOIN_INNER_TD_5893074_output.getNumRow() << " " << "tbl_Filter_TD_5387834_output: " << tbl_Filter_TD_5387834_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_166919_s, &tv_r_Aggregate_3_166919_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4153215_output: " << tbl_JOIN_INNER_TD_4153215_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_297436_s, &tv_r_Sort_2_297436_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_3367866_output: " << tbl_Aggregate_TD_3367866_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_243568_s, &tv_r_LocalLimit_1_243568_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2872649_output: " << tbl_Sort_TD_2872649_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_868461_s, &tv_r_GlobalLimit_0_868461_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1333569_output: " << tbl_LocalLimit_TD_1333569_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 3.1692488 * 1000 << "ms" << std::endl; 
    return 0; 
}
