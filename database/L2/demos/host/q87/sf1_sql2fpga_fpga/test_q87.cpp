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

#include "cfgFunc_q87.hpp" 
#include "q87.hpp" 

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
    std::cout << "NOTE:running query #87\n."; 
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
    Table tbl_Aggregate_TD_058870_output("tbl_Aggregate_TD_058870_output", 6100000, 1, "");
    tbl_Aggregate_TD_058870_output.allocateHost();
    Table tbl_Aggregate_TD_1795115_output("tbl_Aggregate_TD_1795115_output", 6100000, 3, "");
    tbl_Aggregate_TD_1795115_output.allocateHost();
    Table tbl_JOIN_LEFTANTI_TD_2524386_output("tbl_JOIN_LEFTANTI_TD_2524386_output", 6100000, 3, "");
    tbl_JOIN_LEFTANTI_TD_2524386_output.allocateHost();
    Table tbl_Aggregate_TD_35404_output("tbl_Aggregate_TD_35404_output", 6100000, 3, "");
    tbl_Aggregate_TD_35404_output.allocateHost();
    Table tbl_Aggregate_TD_3711086_output("tbl_Aggregate_TD_3711086_output", 6100000, 3, "");
    tbl_Aggregate_TD_3711086_output.allocateHost();
    Table tbl_JOIN_LEFTANTI_TD_4900814_output("tbl_JOIN_LEFTANTI_TD_4900814_output", 6100000, 3, "");
    tbl_JOIN_LEFTANTI_TD_4900814_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4561328_output("tbl_JOIN_INNER_TD_4561328_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_4561328_output.allocateHost();
    Table tbl_Aggregate_TD_5334987_output("tbl_Aggregate_TD_5334987_output", 6100000, 3, "");
    tbl_Aggregate_TD_5334987_output.allocateHost();
    Table tbl_Aggregate_TD_5916216_output("tbl_Aggregate_TD_5916216_output", 6100000, 3, "");
    tbl_Aggregate_TD_5916216_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5148663_output("tbl_JOIN_INNER_TD_5148663_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_5148663_output.allocateHost();
    Table tbl_Filter_TD_5495216_output("tbl_Filter_TD_5495216_output", 6100000, 3, "");
    tbl_Filter_TD_5495216_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6410541_output("tbl_JOIN_INNER_TD_6410541_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_6410541_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6411803_output("tbl_JOIN_INNER_TD_6411803_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_6411803_output.allocateHost();
    Table tbl_Filter_TD_6134278_output("tbl_Filter_TD_6134278_output", 6100000, 2, "");
    tbl_Filter_TD_6134278_output.allocateHost();
    Table tbl_Filter_TD_6781690_output("tbl_Filter_TD_6781690_output", 6100000, 2, "");
    tbl_Filter_TD_6781690_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6409310_input;
    tbl_SerializeFromObject_TD_6409310_input = Table("customer", customer_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_6409310_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_6409310_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6409310_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6409310_input.allocateHost();
    tbl_SerializeFromObject_TD_6409310_input.loadHost();
    Table tbl_JOIN_INNER_TD_7237780_output("tbl_JOIN_INNER_TD_7237780_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_7237780_output.allocateHost();
    Table tbl_Filter_TD_7677050_output("tbl_Filter_TD_7677050_output", 6100000, 3, "");
    tbl_Filter_TD_7677050_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7485296_output("tbl_JOIN_INNER_TD_7485296_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_7485296_output.allocateHost();
    Table tbl_Filter_TD_7165466_output("tbl_Filter_TD_7165466_output", 6100000, 3, "");
    tbl_Filter_TD_7165466_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7816642_input;
    tbl_SerializeFromObject_TD_7816642_input = Table("web_sales", web_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7816642_input.addCol("ws_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_7816642_input.addCol("ws_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_7816642_input.allocateHost();
    tbl_SerializeFromObject_TD_7816642_input.loadHost();
    Table tbl_SerializeFromObject_TD_7625798_input;
    tbl_SerializeFromObject_TD_7625798_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_7625798_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_7625798_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_7625798_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_7625798_input.allocateHost();
    tbl_SerializeFromObject_TD_7625798_input.loadHost();
    Table tbl_Filter_TD_8264333_output("tbl_Filter_TD_8264333_output", 6100000, 2, "");
    tbl_Filter_TD_8264333_output.allocateHost();
    Table tbl_Filter_TD_8451687_output("tbl_Filter_TD_8451687_output", 6100000, 2, "");
    tbl_Filter_TD_8451687_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8925315_input;
    tbl_SerializeFromObject_TD_8925315_input = Table("customer", customer_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8925315_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_8925315_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8925315_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8925315_input.allocateHost();
    tbl_SerializeFromObject_TD_8925315_input.loadHost();
    Table tbl_Filter_TD_863215_output("tbl_Filter_TD_863215_output", 6100000, 2, "");
    tbl_Filter_TD_863215_output.allocateHost();
    Table tbl_Filter_TD_8493865_output("tbl_Filter_TD_8493865_output", 6100000, 2, "");
    tbl_Filter_TD_8493865_output.allocateHost();
    Table tbl_SerializeFromObject_TD_833767_input;
    tbl_SerializeFromObject_TD_833767_input = Table("customer", customer_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_833767_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_833767_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_833767_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_833767_input.allocateHost();
    tbl_SerializeFromObject_TD_833767_input.loadHost();
    Table tbl_SerializeFromObject_TD_9514605_input;
    tbl_SerializeFromObject_TD_9514605_input = Table("store_sales", store_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9514605_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_9514605_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_9514605_input.allocateHost();
    tbl_SerializeFromObject_TD_9514605_input.loadHost();
    Table tbl_SerializeFromObject_TD_9267166_input;
    tbl_SerializeFromObject_TD_9267166_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9267166_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_9267166_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_9267166_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_9267166_input.allocateHost();
    tbl_SerializeFromObject_TD_9267166_input.loadHost();
    Table tbl_SerializeFromObject_TD_9868367_input;
    tbl_SerializeFromObject_TD_9868367_input = Table("catalog_sales", catalog_sales_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9868367_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_9868367_input.addCol("cs_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_9868367_input.allocateHost();
    tbl_SerializeFromObject_TD_9868367_input.loadHost();
    Table tbl_SerializeFromObject_TD_9538659_input;
    tbl_SerializeFromObject_TD_9538659_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9538659_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_9538659_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_9538659_input.addCol("d_month_seq", 4);
    tbl_SerializeFromObject_TD_9538659_input.allocateHost();
    tbl_SerializeFromObject_TD_9538659_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_5148663_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_6134278_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_6781690_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_7237780_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_7485296_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8264333_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8451687_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_863215_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8493865_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_5148663_cmds;
    cfg_JOIN_INNER_TD_5148663_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_5148663_gqe_join (cfg_JOIN_INNER_TD_5148663_cmds.cmd);
    cfg_JOIN_INNER_TD_5148663_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7237780_cmds;
    cfg_JOIN_INNER_TD_7237780_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7237780_gqe_join (cfg_JOIN_INNER_TD_7237780_cmds.cmd);
    cfg_JOIN_INNER_TD_7237780_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7485296_cmds;
    cfg_JOIN_INNER_TD_7485296_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7485296_gqe_join (cfg_JOIN_INNER_TD_7485296_cmds.cmd);
    cfg_JOIN_INNER_TD_7485296_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_5148663;
    krnl_JOIN_INNER_TD_5148663 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_5148663.setup(tbl_Filter_TD_6134278_output, tbl_Filter_TD_6781690_output, tbl_JOIN_INNER_TD_5148663_output, cfg_JOIN_INNER_TD_5148663_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_7237780;
    krnl_JOIN_INNER_TD_7237780 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7237780.setup(tbl_Filter_TD_8264333_output, tbl_Filter_TD_8451687_output, tbl_JOIN_INNER_TD_7237780_output, cfg_JOIN_INNER_TD_7237780_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_7485296;
    krnl_JOIN_INNER_TD_7485296 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7485296.setup(tbl_Filter_TD_863215_output, tbl_Filter_TD_8493865_output, tbl_JOIN_INNER_TD_7485296_output, cfg_JOIN_INNER_TD_7485296_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_5148663;
    trans_JOIN_INNER_TD_5148663.setq(q_h);
    trans_JOIN_INNER_TD_5148663.add(&(cfg_JOIN_INNER_TD_5148663_cmds));
    transEngine trans_JOIN_INNER_TD_5148663_out;
    trans_JOIN_INNER_TD_5148663_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_7237780;
    trans_JOIN_INNER_TD_7237780.setq(q_h);
    trans_JOIN_INNER_TD_7237780.add(&(cfg_JOIN_INNER_TD_7237780_cmds));
    transEngine trans_JOIN_INNER_TD_7237780_out;
    trans_JOIN_INNER_TD_7237780_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_7485296;
    trans_JOIN_INNER_TD_7485296.setq(q_h);
    trans_JOIN_INNER_TD_7485296.add(&(cfg_JOIN_INNER_TD_7485296_cmds));
    transEngine trans_JOIN_INNER_TD_7485296_out;
    trans_JOIN_INNER_TD_7485296_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_5148663;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_5148663;
    std::vector<cl::Event> events_JOIN_INNER_TD_5148663;
    events_h2d_wr_JOIN_INNER_TD_5148663.resize(1);
    events_d2h_rd_JOIN_INNER_TD_5148663.resize(1);
    events_JOIN_INNER_TD_5148663.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_5148663;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_5148663;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7237780;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7237780;
    std::vector<cl::Event> events_JOIN_INNER_TD_7237780;
    events_h2d_wr_JOIN_INNER_TD_7237780.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7237780.resize(1);
    events_JOIN_INNER_TD_7237780.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7237780;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7237780;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7485296;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7485296;
    std::vector<cl::Event> events_JOIN_INNER_TD_7485296;
    events_h2d_wr_JOIN_INNER_TD_7485296.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7485296.resize(1);
    events_JOIN_INNER_TD_7485296.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7485296;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7485296;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_8_594616_s, tv_r_Filter_8_594616_e;
    gettimeofday(&tv_r_Filter_8_594616_s, 0);
    SW_Filter_TD_8493865(tbl_SerializeFromObject_TD_9538659_input, tbl_Filter_TD_8493865_output);
    gettimeofday(&tv_r_Filter_8_594616_e, 0);

    struct timeval tv_r_Filter_8_466416_s, tv_r_Filter_8_466416_e;
    gettimeofday(&tv_r_Filter_8_466416_s, 0);
    SW_Filter_TD_863215(tbl_SerializeFromObject_TD_9868367_input, tbl_Filter_TD_863215_output);
    gettimeofday(&tv_r_Filter_8_466416_e, 0);

    struct timeval tv_r_Filter_8_149529_s, tv_r_Filter_8_149529_e;
    gettimeofday(&tv_r_Filter_8_149529_s, 0);
    SW_Filter_TD_8451687(tbl_SerializeFromObject_TD_9267166_input, tbl_Filter_TD_8451687_output);
    gettimeofday(&tv_r_Filter_8_149529_e, 0);

    struct timeval tv_r_Filter_8_323814_s, tv_r_Filter_8_323814_e;
    gettimeofday(&tv_r_Filter_8_323814_s, 0);
    SW_Filter_TD_8264333(tbl_SerializeFromObject_TD_9514605_input, tbl_Filter_TD_8264333_output);
    gettimeofday(&tv_r_Filter_8_323814_e, 0);

    struct timeval tv_r_Filter_7_5858_s, tv_r_Filter_7_5858_e;
    gettimeofday(&tv_r_Filter_7_5858_s, 0);
    SW_Filter_TD_7165466(tbl_SerializeFromObject_TD_833767_input, tbl_Filter_TD_7165466_output);
    gettimeofday(&tv_r_Filter_7_5858_e, 0);

    struct timeval tv_r_JOIN_INNER_7_795863_s, tv_r_JOIN_INNER_7_795863_e;
    gettimeofday(&tv_r_JOIN_INNER_7_795863_s, 0);
    trans_JOIN_INNER_TD_7485296.add(&(tbl_Filter_TD_863215_output));
    trans_JOIN_INNER_TD_7485296.add(&(tbl_Filter_TD_8493865_output));
    trans_JOIN_INNER_TD_7485296.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7485296), &(events_h2d_wr_JOIN_INNER_TD_7485296[0]));
    events_grp_JOIN_INNER_TD_7485296.push_back(events_h2d_wr_JOIN_INNER_TD_7485296[0]);
    krnl_JOIN_INNER_TD_7485296.run(0, &(events_grp_JOIN_INNER_TD_7485296), &(events_JOIN_INNER_TD_7485296[0]));
    
    trans_JOIN_INNER_TD_7485296_out.add(&(tbl_JOIN_INNER_TD_7485296_output));
    trans_JOIN_INNER_TD_7485296_out.dev2host(0, &(events_JOIN_INNER_TD_7485296), &(events_d2h_rd_JOIN_INNER_TD_7485296[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_7_795863_e, 0);

    struct timeval tv_r_Filter_7_164316_s, tv_r_Filter_7_164316_e;
    gettimeofday(&tv_r_Filter_7_164316_s, 0);
    SW_Filter_TD_7677050(tbl_SerializeFromObject_TD_8925315_input, tbl_Filter_TD_7677050_output);
    gettimeofday(&tv_r_Filter_7_164316_e, 0);

    struct timeval tv_r_JOIN_INNER_7_16772_s, tv_r_JOIN_INNER_7_16772_e;
    gettimeofday(&tv_r_JOIN_INNER_7_16772_s, 0);
    trans_JOIN_INNER_TD_7237780.add(&(tbl_Filter_TD_8264333_output));
    trans_JOIN_INNER_TD_7237780.add(&(tbl_Filter_TD_8451687_output));
    trans_JOIN_INNER_TD_7237780.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7237780), &(events_h2d_wr_JOIN_INNER_TD_7237780[0]));
    events_grp_JOIN_INNER_TD_7237780.push_back(events_h2d_wr_JOIN_INNER_TD_7237780[0]);
    krnl_JOIN_INNER_TD_7237780.run(0, &(events_grp_JOIN_INNER_TD_7237780), &(events_JOIN_INNER_TD_7237780[0]));
    
    trans_JOIN_INNER_TD_7237780_out.add(&(tbl_JOIN_INNER_TD_7237780_output));
    trans_JOIN_INNER_TD_7237780_out.dev2host(0, &(events_JOIN_INNER_TD_7237780), &(events_d2h_rd_JOIN_INNER_TD_7237780[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_7_16772_e, 0);

    struct timeval tv_r_Filter_6_330299_s, tv_r_Filter_6_330299_e;
    gettimeofday(&tv_r_Filter_6_330299_s, 0);
    SW_Filter_TD_6781690(tbl_SerializeFromObject_TD_7625798_input, tbl_Filter_TD_6781690_output);
    gettimeofday(&tv_r_Filter_6_330299_e, 0);

    struct timeval tv_r_Filter_6_902262_s, tv_r_Filter_6_902262_e;
    gettimeofday(&tv_r_Filter_6_902262_s, 0);
    SW_Filter_TD_6134278(tbl_SerializeFromObject_TD_7816642_input, tbl_Filter_TD_6134278_output);
    gettimeofday(&tv_r_Filter_6_902262_e, 0);

    struct timeval tv_r_JOIN_INNER_6_608161_s, tv_r_JOIN_INNER_6_608161_e;
    gettimeofday(&tv_r_JOIN_INNER_6_608161_s, 0);
    SW_JOIN_INNER_TD_6411803(tbl_JOIN_INNER_TD_7485296_output, tbl_Filter_TD_7165466_output, tbl_JOIN_INNER_TD_6411803_output);
    gettimeofday(&tv_r_JOIN_INNER_6_608161_e, 0);

    struct timeval tv_r_JOIN_INNER_6_918255_s, tv_r_JOIN_INNER_6_918255_e;
    gettimeofday(&tv_r_JOIN_INNER_6_918255_s, 0);
    SW_JOIN_INNER_TD_6410541(tbl_JOIN_INNER_TD_7237780_output, tbl_Filter_TD_7677050_output, tbl_JOIN_INNER_TD_6410541_output);
    gettimeofday(&tv_r_JOIN_INNER_6_918255_e, 0);

    struct timeval tv_r_Filter_5_438067_s, tv_r_Filter_5_438067_e;
    gettimeofday(&tv_r_Filter_5_438067_s, 0);
    SW_Filter_TD_5495216(tbl_SerializeFromObject_TD_6409310_input, tbl_Filter_TD_5495216_output);
    gettimeofday(&tv_r_Filter_5_438067_e, 0);

    struct timeval tv_r_JOIN_INNER_5_641651_s, tv_r_JOIN_INNER_5_641651_e;
    gettimeofday(&tv_r_JOIN_INNER_5_641651_s, 0);
    trans_JOIN_INNER_TD_5148663.add(&(tbl_Filter_TD_6134278_output));
    trans_JOIN_INNER_TD_5148663.add(&(tbl_Filter_TD_6781690_output));
    trans_JOIN_INNER_TD_5148663.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_5148663), &(events_h2d_wr_JOIN_INNER_TD_5148663[0]));
    events_grp_JOIN_INNER_TD_5148663.push_back(events_h2d_wr_JOIN_INNER_TD_5148663[0]);
    krnl_JOIN_INNER_TD_5148663.run(0, &(events_grp_JOIN_INNER_TD_5148663), &(events_JOIN_INNER_TD_5148663[0]));
    
    trans_JOIN_INNER_TD_5148663_out.add(&(tbl_JOIN_INNER_TD_5148663_output));
    trans_JOIN_INNER_TD_5148663_out.dev2host(0, &(events_JOIN_INNER_TD_5148663), &(events_d2h_rd_JOIN_INNER_TD_5148663[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_5_641651_e, 0);

    struct timeval tv_r_Aggregate_5_416338_s, tv_r_Aggregate_5_416338_e;
    gettimeofday(&tv_r_Aggregate_5_416338_s, 0);
    SW_Aggregate_TD_5916216(tbl_JOIN_INNER_TD_6411803_output, tbl_Aggregate_TD_5916216_output);
    gettimeofday(&tv_r_Aggregate_5_416338_e, 0);

    struct timeval tv_r_Aggregate_5_139043_s, tv_r_Aggregate_5_139043_e;
    gettimeofday(&tv_r_Aggregate_5_139043_s, 0);
    SW_Aggregate_TD_5334987(tbl_JOIN_INNER_TD_6410541_output, tbl_Aggregate_TD_5334987_output);
    gettimeofday(&tv_r_Aggregate_5_139043_e, 0);

    struct timeval tv_r_JOIN_INNER_4_515551_s, tv_r_JOIN_INNER_4_515551_e;
    gettimeofday(&tv_r_JOIN_INNER_4_515551_s, 0);
    SW_JOIN_INNER_TD_4561328(tbl_JOIN_INNER_TD_5148663_output, tbl_Filter_TD_5495216_output, tbl_JOIN_INNER_TD_4561328_output);
    gettimeofday(&tv_r_JOIN_INNER_4_515551_e, 0);

    struct timeval tv_r_JOIN_LEFTANTI_4_595221_s, tv_r_JOIN_LEFTANTI_4_595221_e;
    gettimeofday(&tv_r_JOIN_LEFTANTI_4_595221_s, 0);
    SW_JOIN_LEFTANTI_TD_4900814(tbl_Aggregate_TD_5334987_output, tbl_Aggregate_TD_5916216_output, tbl_JOIN_LEFTANTI_TD_4900814_output);
    gettimeofday(&tv_r_JOIN_LEFTANTI_4_595221_e, 0);

    struct timeval tv_r_Aggregate_3_117743_s, tv_r_Aggregate_3_117743_e;
    gettimeofday(&tv_r_Aggregate_3_117743_s, 0);
    SW_Aggregate_TD_3711086(tbl_JOIN_INNER_TD_4561328_output, tbl_Aggregate_TD_3711086_output);
    gettimeofday(&tv_r_Aggregate_3_117743_e, 0);

    struct timeval tv_r_Aggregate_3_611689_s, tv_r_Aggregate_3_611689_e;
    gettimeofday(&tv_r_Aggregate_3_611689_s, 0);
    SW_Aggregate_TD_35404(tbl_JOIN_LEFTANTI_TD_4900814_output, tbl_Aggregate_TD_35404_output);
    gettimeofday(&tv_r_Aggregate_3_611689_e, 0);

    struct timeval tv_r_JOIN_LEFTANTI_2_641625_s, tv_r_JOIN_LEFTANTI_2_641625_e;
    gettimeofday(&tv_r_JOIN_LEFTANTI_2_641625_s, 0);
    SW_JOIN_LEFTANTI_TD_2524386(tbl_Aggregate_TD_35404_output, tbl_Aggregate_TD_3711086_output, tbl_JOIN_LEFTANTI_TD_2524386_output);
    gettimeofday(&tv_r_JOIN_LEFTANTI_2_641625_e, 0);

    struct timeval tv_r_Aggregate_1_273343_s, tv_r_Aggregate_1_273343_e;
    gettimeofday(&tv_r_Aggregate_1_273343_s, 0);
    SW_Aggregate_TD_1795115(tbl_JOIN_LEFTANTI_TD_2524386_output, tbl_Aggregate_TD_1795115_output);
    gettimeofday(&tv_r_Aggregate_1_273343_e, 0);

    struct timeval tv_r_Aggregate_0_110711_s, tv_r_Aggregate_0_110711_e;
    gettimeofday(&tv_r_Aggregate_0_110711_s, 0);
    SW_Aggregate_TD_058870(tbl_Aggregate_TD_1795115_output, tbl_Aggregate_TD_058870_output);
    gettimeofday(&tv_r_Aggregate_0_110711_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_594616_s, &tv_r_Filter_8_594616_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9538659_input: " << tbl_SerializeFromObject_TD_9538659_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_466416_s, &tv_r_Filter_8_466416_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9868367_input: " << tbl_SerializeFromObject_TD_9868367_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_149529_s, &tv_r_Filter_8_149529_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9267166_input: " << tbl_SerializeFromObject_TD_9267166_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_323814_s, &tv_r_Filter_8_323814_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9514605_input: " << tbl_SerializeFromObject_TD_9514605_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_5858_s, &tv_r_Filter_7_5858_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_833767_input: " << tbl_SerializeFromObject_TD_833767_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_795863_s, &tv_r_JOIN_INNER_7_795863_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_863215_output: " << tbl_Filter_TD_863215_output.getNumRow() << " " << "tbl_Filter_TD_8493865_output: " << tbl_Filter_TD_8493865_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_164316_s, &tv_r_Filter_7_164316_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8925315_input: " << tbl_SerializeFromObject_TD_8925315_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_16772_s, &tv_r_JOIN_INNER_7_16772_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8264333_output: " << tbl_Filter_TD_8264333_output.getNumRow() << " " << "tbl_Filter_TD_8451687_output: " << tbl_Filter_TD_8451687_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_330299_s, &tv_r_Filter_6_330299_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7625798_input: " << tbl_SerializeFromObject_TD_7625798_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_902262_s, &tv_r_Filter_6_902262_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7816642_input: " << tbl_SerializeFromObject_TD_7816642_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_608161_s, &tv_r_JOIN_INNER_6_608161_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7485296_output: " << tbl_JOIN_INNER_TD_7485296_output.getNumRow() << " " << "tbl_Filter_TD_7165466_output: " << tbl_Filter_TD_7165466_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_918255_s, &tv_r_JOIN_INNER_6_918255_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7237780_output: " << tbl_JOIN_INNER_TD_7237780_output.getNumRow() << " " << "tbl_Filter_TD_7677050_output: " << tbl_Filter_TD_7677050_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_438067_s, &tv_r_Filter_5_438067_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6409310_input: " << tbl_SerializeFromObject_TD_6409310_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_641651_s, &tv_r_JOIN_INNER_5_641651_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_6134278_output: " << tbl_Filter_TD_6134278_output.getNumRow() << " " << "tbl_Filter_TD_6781690_output: " << tbl_Filter_TD_6781690_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_416338_s, &tv_r_Aggregate_5_416338_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6411803_output: " << tbl_JOIN_INNER_TD_6411803_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_139043_s, &tv_r_Aggregate_5_139043_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6410541_output: " << tbl_JOIN_INNER_TD_6410541_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_515551_s, &tv_r_JOIN_INNER_4_515551_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5148663_output: " << tbl_JOIN_INNER_TD_5148663_output.getNumRow() << " " << "tbl_Filter_TD_5495216_output: " << tbl_Filter_TD_5495216_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTANTI_4: " << tvdiff(&tv_r_JOIN_LEFTANTI_4_595221_s, &tv_r_JOIN_LEFTANTI_4_595221_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_5334987_output: " << tbl_Aggregate_TD_5334987_output.getNumRow() << " " << "tbl_Aggregate_TD_5916216_output: " << tbl_Aggregate_TD_5916216_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_117743_s, &tv_r_Aggregate_3_117743_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4561328_output: " << tbl_JOIN_INNER_TD_4561328_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_611689_s, &tv_r_Aggregate_3_611689_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTANTI_TD_4900814_output: " << tbl_JOIN_LEFTANTI_TD_4900814_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTANTI_2: " << tvdiff(&tv_r_JOIN_LEFTANTI_2_641625_s, &tv_r_JOIN_LEFTANTI_2_641625_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_35404_output: " << tbl_Aggregate_TD_35404_output.getNumRow() << " " << "tbl_Aggregate_TD_3711086_output: " << tbl_Aggregate_TD_3711086_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_273343_s, &tv_r_Aggregate_1_273343_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTANTI_TD_2524386_output: " << tbl_JOIN_LEFTANTI_TD_2524386_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_0: " << tvdiff(&tv_r_Aggregate_0_110711_s, &tv_r_Aggregate_0_110711_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_1795115_output: " << tbl_Aggregate_TD_1795115_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 2.6272016 * 1000 << "ms" << std::endl; 
    return 0; 
}
