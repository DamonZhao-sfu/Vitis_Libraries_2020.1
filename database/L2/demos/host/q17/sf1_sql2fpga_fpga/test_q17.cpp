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

#include "cfgFunc_q17.hpp" 
#include "q17.hpp" 

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
    std::cout << "NOTE:running query #17\n."; 
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
    Table tbl_GlobalLimit_TD_0702997_output("tbl_GlobalLimit_TD_0702997_output", 6100000, 9, "");
    tbl_GlobalLimit_TD_0702997_output.allocateHost();
    Table tbl_LocalLimit_TD_110708_output("tbl_LocalLimit_TD_110708_output", 6100000, 9, "");
    tbl_LocalLimit_TD_110708_output.allocateHost();
    Table tbl_Sort_TD_2886361_output("tbl_Sort_TD_2886361_output", 6100000, 9, "");
    tbl_Sort_TD_2886361_output.allocateHost();
    Table tbl_Aggregate_TD_339190_output("tbl_Aggregate_TD_339190_output", 6100000, 9, "");
    tbl_Aggregate_TD_339190_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4457812_output("tbl_JOIN_INNER_TD_4457812_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_4457812_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5192827_output("tbl_JOIN_INNER_TD_5192827_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_5192827_output.allocateHost();
    Table tbl_Filter_TD_5707128_output("tbl_Filter_TD_5707128_output", 6100000, 3, "");
    tbl_Filter_TD_5707128_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6555791_output("tbl_JOIN_INNER_TD_6555791_output", 6100000, 5, "");
    tbl_JOIN_INNER_TD_6555791_output.allocateHost();
    Table tbl_Filter_TD_631201_output("tbl_Filter_TD_631201_output", 6100000, 2, "");
    tbl_Filter_TD_631201_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6408587_input;
    tbl_SerializeFromObject_TD_6408587_input = Table("item", item_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_6408587_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_6408587_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6408587_input.addCol("i_item_desc", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6408587_input.allocateHost();
    tbl_SerializeFromObject_TD_6408587_input.loadHost();
    Table tbl_JOIN_INNER_TD_7191732_output("tbl_JOIN_INNER_TD_7191732_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_7191732_output.allocateHost();
    Table tbl_Filter_TD_7232045_output("tbl_Filter_TD_7232045_output", 6100000, 1, "");
    tbl_Filter_TD_7232045_output.allocateHost();
    Table tbl_SerializeFromObject_TD_7400112_input;
    tbl_SerializeFromObject_TD_7400112_input = Table("store", store_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_7400112_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_7400112_input.addCol("s_state", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_7400112_input.allocateHost();
    tbl_SerializeFromObject_TD_7400112_input.loadHost();
    Table tbl_JOIN_INNER_TD_8800395_output("tbl_JOIN_INNER_TD_8800395_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_8800395_output.allocateHost();
    Table tbl_Filter_TD_8850597_output("tbl_Filter_TD_8850597_output", 6100000, 1, "");
    tbl_Filter_TD_8850597_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8296782_input;
    tbl_SerializeFromObject_TD_8296782_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_8296782_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_8296782_input.addCol("d_quarter_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_8296782_input.allocateHost();
    tbl_SerializeFromObject_TD_8296782_input.loadHost();
    Table tbl_JOIN_INNER_TD_9944205_output("tbl_JOIN_INNER_TD_9944205_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_9944205_output.allocateHost();
    Table tbl_Filter_TD_911781_output("tbl_Filter_TD_911781_output", 6100000, 1, "");
    tbl_Filter_TD_911781_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9557744_input;
    tbl_SerializeFromObject_TD_9557744_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9557744_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_9557744_input.addCol("d_quarter_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9557744_input.allocateHost();
    tbl_SerializeFromObject_TD_9557744_input.loadHost();
    Table tbl_JOIN_INNER_TD_10202533_output("tbl_JOIN_INNER_TD_10202533_output", 6100000, 8, "");
    tbl_JOIN_INNER_TD_10202533_output.allocateHost();
    Table tbl_Filter_TD_10109488_output("tbl_Filter_TD_10109488_output", 6100000, 4, "");
    tbl_Filter_TD_10109488_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10502506_input;
    tbl_SerializeFromObject_TD_10502506_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10502506_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10502506_input.addCol("d_quarter_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10502506_input.allocateHost();
    tbl_SerializeFromObject_TD_10502506_input.loadHost();
    Table tbl_Filter_TD_11489820_output("tbl_Filter_TD_11489820_output", 6100000, 6, "");
    tbl_Filter_TD_11489820_output.allocateHost();
    Table tbl_Filter_TD_1197701_output("tbl_Filter_TD_1197701_output", 6100000, 5, "");
    tbl_Filter_TD_1197701_output.allocateHost();
    Table tbl_SerializeFromObject_TD_11247689_input;
    tbl_SerializeFromObject_TD_11247689_input = Table("catalog_sales", catalog_sales_n, 4, in_dir, "orc");
    tbl_SerializeFromObject_TD_11247689_input.addCol("cs_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_11247689_input.addCol("cs_bill_customer_sk", 4);
    tbl_SerializeFromObject_TD_11247689_input.addCol("cs_item_sk", 4);
    tbl_SerializeFromObject_TD_11247689_input.addCol("cs_quantity", 4);
    tbl_SerializeFromObject_TD_11247689_input.allocateHost();
    tbl_SerializeFromObject_TD_11247689_input.loadHost();
    Table tbl_SerializeFromObject_TD_12301244_input;
    tbl_SerializeFromObject_TD_12301244_input = Table("store_sales", store_sales_n, 6, in_dir, "orc");
    tbl_SerializeFromObject_TD_12301244_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_12301244_input.addCol("ss_item_sk", 4);
    tbl_SerializeFromObject_TD_12301244_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_12301244_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_12301244_input.addCol("ss_ticket_number", 8);
    tbl_SerializeFromObject_TD_12301244_input.addCol("ss_quantity", 4);
    tbl_SerializeFromObject_TD_12301244_input.allocateHost();
    tbl_SerializeFromObject_TD_12301244_input.loadHost();
    Table tbl_SerializeFromObject_TD_12116079_input;
    tbl_SerializeFromObject_TD_12116079_input = Table("store_returns", store_returns_n, 5, in_dir, "orc");
    tbl_SerializeFromObject_TD_12116079_input.addCol("sr_returned_date_sk", 4);
    tbl_SerializeFromObject_TD_12116079_input.addCol("sr_item_sk", 4);
    tbl_SerializeFromObject_TD_12116079_input.addCol("sr_customer_sk", 4);
    tbl_SerializeFromObject_TD_12116079_input.addCol("sr_ticket_number", 8);
    tbl_SerializeFromObject_TD_12116079_input.addCol("sr_return_quantity", 4);
    tbl_SerializeFromObject_TD_12116079_input.allocateHost();
    tbl_SerializeFromObject_TD_12116079_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_6555791_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_7191732_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_7232045_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_8800395_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8850597_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_9944205_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_911781_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_10202533_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10109488_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_6555791_cmds;
    cfg_JOIN_INNER_TD_6555791_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_6555791_gqe_join (cfg_JOIN_INNER_TD_6555791_cmds.cmd);
    cfg_JOIN_INNER_TD_6555791_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7191732_cmds;
    cfg_JOIN_INNER_TD_7191732_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7191732_gqe_join (cfg_JOIN_INNER_TD_7191732_cmds.cmd);
    cfg_JOIN_INNER_TD_7191732_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_8800395_cmds;
    cfg_JOIN_INNER_TD_8800395_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8800395_gqe_join (cfg_JOIN_INNER_TD_8800395_cmds.cmd);
    cfg_JOIN_INNER_TD_8800395_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_9944205_cmds;
    cfg_JOIN_INNER_TD_9944205_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_9944205_gqe_join (cfg_JOIN_INNER_TD_9944205_cmds.cmd);
    cfg_JOIN_INNER_TD_9944205_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_6555791;
    krnl_JOIN_INNER_TD_6555791 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_6555791.setup(tbl_JOIN_INNER_TD_7191732_output, tbl_Filter_TD_7232045_output, tbl_JOIN_INNER_TD_6555791_output, cfg_JOIN_INNER_TD_6555791_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_7191732;
    krnl_JOIN_INNER_TD_7191732 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_7191732.setup(tbl_JOIN_INNER_TD_8800395_output, tbl_Filter_TD_8850597_output, tbl_JOIN_INNER_TD_7191732_output, cfg_JOIN_INNER_TD_7191732_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_8800395;
    krnl_JOIN_INNER_TD_8800395 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8800395.setup(tbl_JOIN_INNER_TD_9944205_output, tbl_Filter_TD_911781_output, tbl_JOIN_INNER_TD_8800395_output, cfg_JOIN_INNER_TD_8800395_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_9944205;
    krnl_JOIN_INNER_TD_9944205 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_9944205.setup(tbl_JOIN_INNER_TD_10202533_output, tbl_Filter_TD_10109488_output, tbl_JOIN_INNER_TD_9944205_output, cfg_JOIN_INNER_TD_9944205_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_6555791;
    trans_JOIN_INNER_TD_6555791.setq(q_h);
    trans_JOIN_INNER_TD_6555791.add(&(cfg_JOIN_INNER_TD_6555791_cmds));
    transEngine trans_JOIN_INNER_TD_6555791_out;
    trans_JOIN_INNER_TD_6555791_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_7191732;
    trans_JOIN_INNER_TD_7191732.setq(q_h);
    trans_JOIN_INNER_TD_7191732.add(&(cfg_JOIN_INNER_TD_7191732_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_8800395;
    trans_JOIN_INNER_TD_8800395.setq(q_h);
    trans_JOIN_INNER_TD_8800395.add(&(cfg_JOIN_INNER_TD_8800395_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_9944205;
    trans_JOIN_INNER_TD_9944205.setq(q_h);
    trans_JOIN_INNER_TD_9944205.add(&(cfg_JOIN_INNER_TD_9944205_cmds));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_6555791;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_6555791;
    std::vector<cl::Event> events_JOIN_INNER_TD_6555791;
    events_h2d_wr_JOIN_INNER_TD_6555791.resize(1);
    events_d2h_rd_JOIN_INNER_TD_6555791.resize(1);
    events_JOIN_INNER_TD_6555791.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_6555791;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_6555791;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7191732;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7191732;
    std::vector<cl::Event> events_JOIN_INNER_TD_7191732;
    events_h2d_wr_JOIN_INNER_TD_7191732.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7191732.resize(1);
    events_JOIN_INNER_TD_7191732.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7191732;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7191732;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8800395;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8800395;
    std::vector<cl::Event> events_JOIN_INNER_TD_8800395;
    events_h2d_wr_JOIN_INNER_TD_8800395.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8800395.resize(1);
    events_JOIN_INNER_TD_8800395.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8800395;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8800395;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_9944205;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_9944205;
    std::vector<cl::Event> events_JOIN_INNER_TD_9944205;
    events_h2d_wr_JOIN_INNER_TD_9944205.resize(1);
    events_d2h_rd_JOIN_INNER_TD_9944205.resize(1);
    events_JOIN_INNER_TD_9944205.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_9944205;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_9944205;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_11_685634_s, tv_r_Filter_11_685634_e;
    gettimeofday(&tv_r_Filter_11_685634_s, 0);
    SW_Filter_TD_1197701(tbl_SerializeFromObject_TD_12116079_input, tbl_Filter_TD_1197701_output);
    gettimeofday(&tv_r_Filter_11_685634_e, 0);

    struct timeval tv_r_Filter_11_703624_s, tv_r_Filter_11_703624_e;
    gettimeofday(&tv_r_Filter_11_703624_s, 0);
    SW_Filter_TD_11489820(tbl_SerializeFromObject_TD_12301244_input, tbl_Filter_TD_11489820_output);
    gettimeofday(&tv_r_Filter_11_703624_e, 0);

    struct timeval tv_r_Filter_10_473293_s, tv_r_Filter_10_473293_e;
    gettimeofday(&tv_r_Filter_10_473293_s, 0);
    SW_Filter_TD_10109488(tbl_SerializeFromObject_TD_11247689_input, tbl_Filter_TD_10109488_output);
    gettimeofday(&tv_r_Filter_10_473293_e, 0);

    struct timeval tv_r_JOIN_INNER_10_7641_s, tv_r_JOIN_INNER_10_7641_e;
    gettimeofday(&tv_r_JOIN_INNER_10_7641_s, 0);
    SW_JOIN_INNER_TD_10202533(tbl_Filter_TD_11489820_output, tbl_Filter_TD_1197701_output, tbl_JOIN_INNER_TD_10202533_output);
    gettimeofday(&tv_r_JOIN_INNER_10_7641_e, 0);

    struct timeval tv_r_Filter_9_297815_s, tv_r_Filter_9_297815_e;
    gettimeofday(&tv_r_Filter_9_297815_s, 0);
    SW_Filter_TD_911781(tbl_SerializeFromObject_TD_10502506_input, tbl_Filter_TD_911781_output);
    gettimeofday(&tv_r_Filter_9_297815_e, 0);

    struct timeval tv_r_JOIN_INNER_9_240959_s, tv_r_JOIN_INNER_9_240959_e;
    gettimeofday(&tv_r_JOIN_INNER_9_240959_s, 0);
    trans_JOIN_INNER_TD_9944205.add(&(tbl_JOIN_INNER_TD_10202533_output));
    trans_JOIN_INNER_TD_9944205.add(&(tbl_Filter_TD_10109488_output));
    trans_JOIN_INNER_TD_9944205.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_9944205), &(events_h2d_wr_JOIN_INNER_TD_9944205[0]));
    events_grp_JOIN_INNER_TD_9944205.push_back(events_h2d_wr_JOIN_INNER_TD_9944205[0]);
    krnl_JOIN_INNER_TD_9944205.run(0, &(events_grp_JOIN_INNER_TD_9944205), &(events_JOIN_INNER_TD_9944205[0]));
    gettimeofday(&tv_r_JOIN_INNER_9_240959_e, 0);

    struct timeval tv_r_Filter_8_388540_s, tv_r_Filter_8_388540_e;
    gettimeofday(&tv_r_Filter_8_388540_s, 0);
    SW_Filter_TD_8850597(tbl_SerializeFromObject_TD_9557744_input, tbl_Filter_TD_8850597_output);
    gettimeofday(&tv_r_Filter_8_388540_e, 0);

    struct timeval tv_r_JOIN_INNER_8_978503_s, tv_r_JOIN_INNER_8_978503_e;
    gettimeofday(&tv_r_JOIN_INNER_8_978503_s, 0);
    prev_events_grp_JOIN_INNER_TD_8800395.push_back(events_h2d_wr_JOIN_INNER_TD_9944205[0]);
    trans_JOIN_INNER_TD_8800395.add(&(tbl_Filter_TD_911781_output));
    trans_JOIN_INNER_TD_8800395.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8800395), &(events_h2d_wr_JOIN_INNER_TD_8800395[0]));
    events_grp_JOIN_INNER_TD_8800395.push_back(events_h2d_wr_JOIN_INNER_TD_8800395[0]);
    events_grp_JOIN_INNER_TD_8800395.push_back(events_JOIN_INNER_TD_9944205[0]);
    krnl_JOIN_INNER_TD_8800395.run(0, &(events_grp_JOIN_INNER_TD_8800395), &(events_JOIN_INNER_TD_8800395[0]));
    gettimeofday(&tv_r_JOIN_INNER_8_978503_e, 0);

    struct timeval tv_r_Filter_7_968860_s, tv_r_Filter_7_968860_e;
    gettimeofday(&tv_r_Filter_7_968860_s, 0);
    SW_Filter_TD_7232045(tbl_SerializeFromObject_TD_8296782_input, tbl_Filter_TD_7232045_output);
    gettimeofday(&tv_r_Filter_7_968860_e, 0);

    struct timeval tv_r_JOIN_INNER_7_48214_s, tv_r_JOIN_INNER_7_48214_e;
    gettimeofday(&tv_r_JOIN_INNER_7_48214_s, 0);
    prev_events_grp_JOIN_INNER_TD_7191732.push_back(events_h2d_wr_JOIN_INNER_TD_8800395[0]);
    trans_JOIN_INNER_TD_7191732.add(&(tbl_Filter_TD_8850597_output));
    trans_JOIN_INNER_TD_7191732.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7191732), &(events_h2d_wr_JOIN_INNER_TD_7191732[0]));
    events_grp_JOIN_INNER_TD_7191732.push_back(events_h2d_wr_JOIN_INNER_TD_7191732[0]);
    events_grp_JOIN_INNER_TD_7191732.push_back(events_JOIN_INNER_TD_8800395[0]);
    krnl_JOIN_INNER_TD_7191732.run(0, &(events_grp_JOIN_INNER_TD_7191732), &(events_JOIN_INNER_TD_7191732[0]));
    gettimeofday(&tv_r_JOIN_INNER_7_48214_e, 0);

    struct timeval tv_r_Filter_6_286811_s, tv_r_Filter_6_286811_e;
    gettimeofday(&tv_r_Filter_6_286811_s, 0);
    SW_Filter_TD_631201(tbl_SerializeFromObject_TD_7400112_input, tbl_Filter_TD_631201_output);
    gettimeofday(&tv_r_Filter_6_286811_e, 0);

    struct timeval tv_r_JOIN_INNER_6_181920_s, tv_r_JOIN_INNER_6_181920_e;
    gettimeofday(&tv_r_JOIN_INNER_6_181920_s, 0);
    prev_events_grp_JOIN_INNER_TD_6555791.push_back(events_h2d_wr_JOIN_INNER_TD_7191732[0]);
    trans_JOIN_INNER_TD_6555791.add(&(tbl_Filter_TD_7232045_output));
    trans_JOIN_INNER_TD_6555791.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_6555791), &(events_h2d_wr_JOIN_INNER_TD_6555791[0]));
    events_grp_JOIN_INNER_TD_6555791.push_back(events_h2d_wr_JOIN_INNER_TD_6555791[0]);
    events_grp_JOIN_INNER_TD_6555791.push_back(events_JOIN_INNER_TD_7191732[0]);
    krnl_JOIN_INNER_TD_6555791.run(0, &(events_grp_JOIN_INNER_TD_6555791), &(events_JOIN_INNER_TD_6555791[0]));
    
    trans_JOIN_INNER_TD_6555791_out.add(&(tbl_JOIN_INNER_TD_6555791_output));
    trans_JOIN_INNER_TD_6555791_out.dev2host(0, &(events_JOIN_INNER_TD_6555791), &(events_d2h_rd_JOIN_INNER_TD_6555791[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_6_181920_e, 0);

    struct timeval tv_r_Filter_5_34738_s, tv_r_Filter_5_34738_e;
    gettimeofday(&tv_r_Filter_5_34738_s, 0);
    SW_Filter_TD_5707128(tbl_SerializeFromObject_TD_6408587_input, tbl_Filter_TD_5707128_output);
    gettimeofday(&tv_r_Filter_5_34738_e, 0);

    struct timeval tv_r_JOIN_INNER_5_910225_s, tv_r_JOIN_INNER_5_910225_e;
    gettimeofday(&tv_r_JOIN_INNER_5_910225_s, 0);
    SW_JOIN_INNER_TD_5192827(tbl_JOIN_INNER_TD_6555791_output, tbl_Filter_TD_631201_output, tbl_JOIN_INNER_TD_5192827_output);
    gettimeofday(&tv_r_JOIN_INNER_5_910225_e, 0);

    struct timeval tv_r_JOIN_INNER_4_683321_s, tv_r_JOIN_INNER_4_683321_e;
    gettimeofday(&tv_r_JOIN_INNER_4_683321_s, 0);
    SW_JOIN_INNER_TD_4457812(tbl_JOIN_INNER_TD_5192827_output, tbl_Filter_TD_5707128_output, tbl_JOIN_INNER_TD_4457812_output);
    gettimeofday(&tv_r_JOIN_INNER_4_683321_e, 0);

    struct timeval tv_r_Aggregate_3_135306_s, tv_r_Aggregate_3_135306_e;
    gettimeofday(&tv_r_Aggregate_3_135306_s, 0);
    SW_Aggregate_TD_339190(tbl_JOIN_INNER_TD_4457812_output, tbl_Aggregate_TD_339190_output);
    gettimeofday(&tv_r_Aggregate_3_135306_e, 0);

    struct timeval tv_r_Sort_2_771665_s, tv_r_Sort_2_771665_e;
    gettimeofday(&tv_r_Sort_2_771665_s, 0);
    SW_Sort_TD_2886361(tbl_Aggregate_TD_339190_output, tbl_Sort_TD_2886361_output);
    gettimeofday(&tv_r_Sort_2_771665_e, 0);

    struct timeval tv_r_LocalLimit_1_267833_s, tv_r_LocalLimit_1_267833_e;
    gettimeofday(&tv_r_LocalLimit_1_267833_s, 0);
    SW_LocalLimit_TD_110708(tbl_Sort_TD_2886361_output, tbl_LocalLimit_TD_110708_output);
    gettimeofday(&tv_r_LocalLimit_1_267833_e, 0);

    struct timeval tv_r_GlobalLimit_0_879687_s, tv_r_GlobalLimit_0_879687_e;
    gettimeofday(&tv_r_GlobalLimit_0_879687_s, 0);
    SW_GlobalLimit_TD_0702997(tbl_LocalLimit_TD_110708_output, tbl_GlobalLimit_TD_0702997_output);
    gettimeofday(&tv_r_GlobalLimit_0_879687_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_685634_s, &tv_r_Filter_11_685634_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12116079_input: " << tbl_SerializeFromObject_TD_12116079_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_11: " << tvdiff(&tv_r_Filter_11_703624_s, &tv_r_Filter_11_703624_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_12301244_input: " << tbl_SerializeFromObject_TD_12301244_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_473293_s, &tv_r_Filter_10_473293_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11247689_input: " << tbl_SerializeFromObject_TD_11247689_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_10: " << tvdiff(&tv_r_JOIN_INNER_10_7641_s, &tv_r_JOIN_INNER_10_7641_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_11489820_output: " << tbl_Filter_TD_11489820_output.getNumRow() << " " << "tbl_Filter_TD_1197701_output: " << tbl_Filter_TD_1197701_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_297815_s, &tv_r_Filter_9_297815_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10502506_input: " << tbl_SerializeFromObject_TD_10502506_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_9: " << tvdiff(&tv_r_JOIN_INNER_9_240959_s, &tv_r_JOIN_INNER_9_240959_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_10202533_output: " << tbl_JOIN_INNER_TD_10202533_output.getNumRow() << " " << "tbl_Filter_TD_10109488_output: " << tbl_Filter_TD_10109488_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_388540_s, &tv_r_Filter_8_388540_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9557744_input: " << tbl_SerializeFromObject_TD_9557744_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_978503_s, &tv_r_JOIN_INNER_8_978503_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_9944205_output: " << tbl_JOIN_INNER_TD_9944205_output.getNumRow() << " " << "tbl_Filter_TD_911781_output: " << tbl_Filter_TD_911781_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_968860_s, &tv_r_Filter_7_968860_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8296782_input: " << tbl_SerializeFromObject_TD_8296782_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_48214_s, &tv_r_JOIN_INNER_7_48214_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8800395_output: " << tbl_JOIN_INNER_TD_8800395_output.getNumRow() << " " << "tbl_Filter_TD_8850597_output: " << tbl_Filter_TD_8850597_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_6: " << tvdiff(&tv_r_Filter_6_286811_s, &tv_r_Filter_6_286811_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_7400112_input: " << tbl_SerializeFromObject_TD_7400112_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_181920_s, &tv_r_JOIN_INNER_6_181920_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7191732_output: " << tbl_JOIN_INNER_TD_7191732_output.getNumRow() << " " << "tbl_Filter_TD_7232045_output: " << tbl_Filter_TD_7232045_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_34738_s, &tv_r_Filter_5_34738_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6408587_input: " << tbl_SerializeFromObject_TD_6408587_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_910225_s, &tv_r_JOIN_INNER_5_910225_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6555791_output: " << tbl_JOIN_INNER_TD_6555791_output.getNumRow() << " " << "tbl_Filter_TD_631201_output: " << tbl_Filter_TD_631201_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_683321_s, &tv_r_JOIN_INNER_4_683321_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5192827_output: " << tbl_JOIN_INNER_TD_5192827_output.getNumRow() << " " << "tbl_Filter_TD_5707128_output: " << tbl_Filter_TD_5707128_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_3: " << tvdiff(&tv_r_Aggregate_3_135306_s, &tv_r_Aggregate_3_135306_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4457812_output: " << tbl_JOIN_INNER_TD_4457812_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_771665_s, &tv_r_Sort_2_771665_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_339190_output: " << tbl_Aggregate_TD_339190_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_267833_s, &tv_r_LocalLimit_1_267833_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2886361_output: " << tbl_Sort_TD_2886361_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_879687_s, &tv_r_GlobalLimit_0_879687_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_110708_output: " << tbl_LocalLimit_TD_110708_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 3.0952396 * 1000 << "ms" << std::endl; 
    return 0; 
}
