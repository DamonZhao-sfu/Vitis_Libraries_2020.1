// number of overlays (w/o fusion): 4 
// number of overlays (w/ fusion): 4 
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
#include "gqe_api.hpp" 

#include "cfgFunc_q11.hpp" 
#include "q11.hpp" 

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
    std::cout << "NOTE:running query #11\n."; 
    std::cout << "NOTE:running in sf" << scale << " data\n"; 

    int32_t lineitem_n = SF1_LINEITEM; 
    int32_t supplier_n = SF1_SUPPLIER; 
    int32_t nation_n = SF1_NATION; 
    int32_t order_n = SF1_ORDERS; 
    int32_t customer_n = SF1_CUSTOMER; 
    int32_t region_n = SF1_REGION; 
    int32_t part_n = SF1_PART; 
    int32_t partsupp_n = SF1_PARTSUPP; 
    if (scale == 30) { 
        lineitem_n = SF30_LINEITEM; 
        supplier_n = SF30_SUPPLIER; 
        nation_n = SF30_NATION; 
        order_n = SF30_ORDERS; 
        customer_n = SF30_CUSTOMER; 
        region_n = SF30_REGION; 
        part_n = SF30_PART; 
        partsupp_n = SF30_PARTSUPP; 
    } 
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
    Table tbl_Sort_TD_0107_output("tbl_Sort_TD_0107_output", 6100000, 2, "");
    tbl_Sort_TD_0107_output.allocateHost();
    Table tbl_Filter_TD_1880_output("tbl_Filter_TD_1880_output", 6100000, 2, "");
    tbl_Filter_TD_1880_output.allocateHost();
    Table tbl_Aggregate_TD_2411_output("tbl_Aggregate_TD_2411_output", 6100000, 2, "");
    tbl_Aggregate_TD_2411_output.allocateHost();
    Table tbl_Aggregate_TD_2714_output("tbl_Aggregate_TD_2714_output", 6100000, 1, "");
    tbl_Aggregate_TD_2714_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4990_output("tbl_JOIN_INNER_TD_4990_output", 31440, 3, "");
    tbl_JOIN_INNER_TD_4990_output.allocateHost();
    Table tbl_SerializeFromObject_TD_5511_input;
    tbl_SerializeFromObject_TD_5511_input = Table("partsupp", partsupp_n, 4, in_dir);
    tbl_SerializeFromObject_TD_5511_input.addCol("ps_partkey", 4);
    tbl_SerializeFromObject_TD_5511_input.addCol("ps_suppkey", 4);
    tbl_SerializeFromObject_TD_5511_input.addCol("ps_availqty", 4);
    tbl_SerializeFromObject_TD_5511_input.addCol("ps_supplycost", 4);
    tbl_SerializeFromObject_TD_5511_input.allocateHost();
    tbl_SerializeFromObject_TD_5511_input.loadHost();
    Table tbl_JOIN_INNER_TD_3505_output("tbl_JOIN_INNER_TD_3505_output", 393, 1, "");
    tbl_JOIN_INNER_TD_3505_output.allocateHost();
    Table tbl_SerializeFromObject_TD_5781_input;
    tbl_SerializeFromObject_TD_5781_input = Table("supplier", supplier_n, 2, in_dir);
    tbl_SerializeFromObject_TD_5781_input.addCol("s_suppkey", 4);
    tbl_SerializeFromObject_TD_5781_input.addCol("s_nationkey", 4);
    tbl_SerializeFromObject_TD_5781_input.allocateHost();
    tbl_SerializeFromObject_TD_5781_input.loadHost();
    Table tbl_Filter_TD_4867_output("tbl_Filter_TD_4867_output", 6100000, 1, "");
    tbl_Filter_TD_4867_output.allocateHost();
    Table tbl_SerializeFromObject_TD_5250_input;
    tbl_SerializeFromObject_TD_5250_input = Table("nation", nation_n, 2, in_dir);
    tbl_SerializeFromObject_TD_5250_input.addCol("n_nationkey", 4);
    tbl_SerializeFromObject_TD_5250_input.addCol("n_name", TPCH_READ_NATION_LEN+1);
    tbl_SerializeFromObject_TD_5250_input.allocateHost();
    tbl_SerializeFromObject_TD_5250_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_4990_output.allocateDevBuffer(context_h, 32);
    tbl_SerializeFromObject_TD_5511_input.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_3505_output.allocateDevBuffer(context_h, 32);
    tbl_SerializeFromObject_TD_5781_input.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_4867_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_4990_cmds;
    cfg_JOIN_INNER_TD_4990_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_4990_gqe_join (cfg_JOIN_INNER_TD_4990_cmds.cmd);
    cfg_JOIN_INNER_TD_4990_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_3505_cmds;
    cfg_JOIN_INNER_TD_3505_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_3505_gqe_join (cfg_JOIN_INNER_TD_3505_cmds.cmd);
    cfg_JOIN_INNER_TD_3505_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_4990;
    krnl_JOIN_INNER_TD_4990 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_4990.setup(tbl_JOIN_INNER_TD_3505_output, tbl_SerializeFromObject_TD_5511_input, tbl_JOIN_INNER_TD_4990_output, cfg_JOIN_INNER_TD_4990_cmds, buftmp_h);
    krnlEngine krnl_JOIN_INNER_TD_3505;
    krnl_JOIN_INNER_TD_3505 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_3505.setup(tbl_Filter_TD_4867_output, tbl_SerializeFromObject_TD_5781_input, tbl_JOIN_INNER_TD_3505_output, cfg_JOIN_INNER_TD_3505_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_4990;
    trans_JOIN_INNER_TD_4990.setq(q_h);
    trans_JOIN_INNER_TD_4990.add(&(cfg_JOIN_INNER_TD_4990_cmds));
    trans_JOIN_INNER_TD_4990.add(&(tbl_SerializeFromObject_TD_5511_input));
    transEngine trans_JOIN_INNER_TD_4990_out;
    trans_JOIN_INNER_TD_4990_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_3505;
    trans_JOIN_INNER_TD_3505.setq(q_h);
    trans_JOIN_INNER_TD_3505.add(&(cfg_JOIN_INNER_TD_3505_cmds));
    trans_JOIN_INNER_TD_3505.add(&(tbl_SerializeFromObject_TD_5781_input));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_4990;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_4990;
    std::vector<cl::Event> events_JOIN_INNER_TD_4990;
    events_h2d_wr_JOIN_INNER_TD_4990.resize(1);
    events_d2h_rd_JOIN_INNER_TD_4990.resize(1);
    events_JOIN_INNER_TD_4990.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_4990;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_4990;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_3505;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_3505;
    std::vector<cl::Event> events_JOIN_INNER_TD_3505;
    events_h2d_wr_JOIN_INNER_TD_3505.resize(1);
    events_d2h_rd_JOIN_INNER_TD_3505.resize(1);
    events_JOIN_INNER_TD_3505.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_3505;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_3505;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_4_21_s, tv_r_Filter_4_21_e;
    gettimeofday(&tv_r_Filter_4_21_s, 0);
    SW_Filter_TD_4867(tbl_SerializeFromObject_TD_5250_input, tbl_Filter_TD_4867_output);
    gettimeofday(&tv_r_Filter_4_21_e, 0);

    struct timeval tv_r_JOIN_INNER_3_733_s, tv_r_JOIN_INNER_3_733_e;
    gettimeofday(&tv_r_JOIN_INNER_3_733_s, 0);
    trans_JOIN_INNER_TD_3505.add(&(tbl_Filter_TD_4867_output));
    trans_JOIN_INNER_TD_3505.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_3505), &(events_h2d_wr_JOIN_INNER_TD_3505[0]));
    events_grp_JOIN_INNER_TD_3505.push_back(events_h2d_wr_JOIN_INNER_TD_3505[0]);
    krnl_JOIN_INNER_TD_3505.run(0, &(events_grp_JOIN_INNER_TD_3505), &(events_JOIN_INNER_TD_3505[0]));
    gettimeofday(&tv_r_JOIN_INNER_3_733_e, 0);

    struct timeval tv_r_JOIN_INNER_4_175_s, tv_r_JOIN_INNER_4_175_e;
    gettimeofday(&tv_r_JOIN_INNER_4_175_s, 0);
    prev_events_grp_JOIN_INNER_TD_4990.push_back(events_h2d_wr_JOIN_INNER_TD_3505[0]);
    trans_JOIN_INNER_TD_4990.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_4990), &(events_h2d_wr_JOIN_INNER_TD_4990[0]));
    events_grp_JOIN_INNER_TD_4990.push_back(events_h2d_wr_JOIN_INNER_TD_4990[0]);
    events_grp_JOIN_INNER_TD_4990.push_back(events_JOIN_INNER_TD_3505[0]);
    krnl_JOIN_INNER_TD_4990.run(0, &(events_grp_JOIN_INNER_TD_4990), &(events_JOIN_INNER_TD_4990[0]));
    
    trans_JOIN_INNER_TD_4990_out.add(&(tbl_JOIN_INNER_TD_4990_output));
    trans_JOIN_INNER_TD_4990_out.dev2host(0, &(events_JOIN_INNER_TD_4990), &(events_d2h_rd_JOIN_INNER_TD_4990[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_4_175_e, 0);

    struct timeval tv_r_Aggregate_2_167_s, tv_r_Aggregate_2_167_e;
    gettimeofday(&tv_r_Aggregate_2_167_s, 0);
    SW_Aggregate_TD_2714(tbl_JOIN_INNER_TD_4990_output, tbl_Aggregate_TD_2714_output);
    gettimeofday(&tv_r_Aggregate_2_167_e, 0);

    struct timeval tv_r_Aggregate_2_314_s, tv_r_Aggregate_2_314_e;
    gettimeofday(&tv_r_Aggregate_2_314_s, 0);
    SW_Aggregate_TD_2411(tbl_JOIN_INNER_TD_4990_output, tbl_Aggregate_TD_2411_output);
    gettimeofday(&tv_r_Aggregate_2_314_e, 0);

    struct timeval tv_r_Filter_1_108_s, tv_r_Filter_1_108_e;
    gettimeofday(&tv_r_Filter_1_108_s, 0);
    SW_Filter_TD_1880(tbl_Aggregate_TD_2411_output, tbl_Aggregate_TD_2714_output, tbl_Filter_TD_1880_output);
    gettimeofday(&tv_r_Filter_1_108_e, 0);

    struct timeval tv_r_Sort_0_708_s, tv_r_Sort_0_708_e;
    gettimeofday(&tv_r_Sort_0_708_s, 0);
    SW_Sort_TD_0107(tbl_Filter_TD_1880_output, tbl_Sort_TD_0107_output);
    gettimeofday(&tv_r_Sort_0_708_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_21_s, &tv_r_Filter_4_21_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5250_input: " << tbl_SerializeFromObject_TD_5250_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_733_s, &tv_r_JOIN_INNER_3_733_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5781_input: " << tbl_SerializeFromObject_TD_5781_input.getNumRow() << " " << "tbl_Filter_TD_4867_output: " << tbl_Filter_TD_4867_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_175_s, &tv_r_JOIN_INNER_4_175_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5511_input: " << tbl_SerializeFromObject_TD_5511_input.getNumRow() << " " << "tbl_JOIN_INNER_TD_3505_output: " << tbl_JOIN_INNER_TD_3505_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_2: " << tvdiff(&tv_r_Aggregate_2_167_s, &tv_r_Aggregate_2_167_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4990_output: " << tbl_JOIN_INNER_TD_4990_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_2: " << tvdiff(&tv_r_Aggregate_2_314_s, &tv_r_Aggregate_2_314_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4990_output: " << tbl_JOIN_INNER_TD_4990_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_1: " << tvdiff(&tv_r_Filter_1_108_s, &tv_r_Filter_1_108_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_2411_output: " << tbl_Aggregate_TD_2411_output.getNumRow() << " " << "tbl_Aggregate_TD_2714_output: " << tbl_Aggregate_TD_2714_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_708_s, &tv_r_Sort_0_708_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_1880_output: " << tbl_Filter_TD_1880_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 0.4985934 * 1000 << "ms" << std::endl; 
    return 0; 
}
