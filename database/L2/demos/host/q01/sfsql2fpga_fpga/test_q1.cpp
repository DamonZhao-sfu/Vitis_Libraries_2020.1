// number of overlays (w/o fusion): 1 
// number of overlays (w/ fusion): 1 
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

#include "cfgFunc_q1.hpp" 
#include "q1.hpp" 

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
    std::cout << "NOTE:running query #1\n."; 
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
    cl::Device device_a = devices[1]; 
    // Create context_a and command queue for selected device 
    cl::Context context_a(device_a); 
    cl::CommandQueue q_a(context_a, device_a, CL_QUEUE_PROFILING_ENABLE | CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE); 
    std::string devName_a = device_a.getInfo<CL_DEVICE_NAME>(); 
    std::cout << "Selected Device " << devName_a << "\n"; 
    cl::Program::Binaries xclBins_a = xcl::import_binary_file(xclbin_path_a); 
    std::vector<cl::Device> devices_a; 
    devices_a.push_back(device_a); 
    cl::Program program_a(context_a, devices_a, xclBins_a); 
    // *********************** Partition Infomation ********************* // 
    int hpTimes_join = 32; 
    int power_of_hpTimes_join = log2(hpTimes_join); 
    std::cout << "Number of partition (gqeJoin) is: " << hpTimes_join << std::endl; 
    int hpTimes_aggr = 256; 
    int power_of_hpTimes_aggr = log2(hpTimes_aggr); 
    std::cout << "Number of partition (gqeAggr) is: " << hpTimes_aggr << std::endl; 
    // ****************************** Tables **************************** // 
    Table tbl_Sort_TD_0537_output("tbl_Sort_TD_0537_output", 183000000, 10, "");
    tbl_Sort_TD_0537_output.allocateHost();
    Table tbl_Aggregate_TD_1130_output_preprocess("tbl_Aggregate_TD_1130_output_preprocess", 10, 16, "");
    tbl_Aggregate_TD_1130_output_preprocess.allocateHost(1.2, hpTimes_aggr);
    Table tbl_Aggregate_TD_1130_output("tbl_Aggregate_TD_1130_output", 10, 10, "");
    tbl_Aggregate_TD_1130_output.allocateHost(1.2,hpTimes_aggr);
    Table tbl_Aggregate_TD_1130_output_partition_array[hpTimes_aggr];
    for (int i(0); i < hpTimes_aggr; ++i) {
        tbl_Aggregate_TD_1130_output_partition_array[i] = tbl_Aggregate_TD_1130_output.createSubTable(i);
    }
    Table tbl_Filter_TD_2859_output("tbl_Filter_TD_2859_output", 183000000, 6, "");
    tbl_Filter_TD_2859_output.allocateHost();
    Table tbl_Filter_TD_2859_output_partition("tbl_Filter_TD_2859_output_partition", 183000000, 6, "");
    tbl_Filter_TD_2859_output_partition.allocateHost(1.2, hpTimes_aggr);
    tbl_Filter_TD_2859_output_partition.allocateDevBuffer(context_a, 32);
    Table tbl_Filter_TD_2859_output_partition_array[hpTimes_aggr];
    for (int i(0); i < hpTimes_aggr; ++i) {
        tbl_Filter_TD_2859_output_partition_array[i] = tbl_Filter_TD_2859_output_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_3513_input;
    tbl_SerializeFromObject_TD_3513_input = Table("lineitem", lineitem_n, 7, in_dir);
    tbl_SerializeFromObject_TD_3513_input.addCol("l_quantity", 4);
    tbl_SerializeFromObject_TD_3513_input.addCol("l_extendedprice", 4);
    tbl_SerializeFromObject_TD_3513_input.addCol("l_discount", 4);
    tbl_SerializeFromObject_TD_3513_input.addCol("l_tax", 4);
    tbl_SerializeFromObject_TD_3513_input.addCol("l_returnflag", 4);
    tbl_SerializeFromObject_TD_3513_input.addCol("l_linestatus", 4);
    tbl_SerializeFromObject_TD_3513_input.addCol("l_shipdate", 4);
    tbl_SerializeFromObject_TD_3513_input.allocateHost();
    tbl_SerializeFromObject_TD_3513_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_Aggregate_TD_1130_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_Aggregate_TD_1130_output.allocateDevBuffer(context_a, 33);
    tbl_Filter_TD_2859_output.allocateDevBuffer(context_a, 33);
    // ****************************** Config **************************** // 
    AggrCfgCmd cfg_Aggregate_TD_1130_cmds;
    cfg_Aggregate_TD_1130_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_1130_gqe_aggr(cfg_Aggregate_TD_1130_cmds.cmd);
    cfg_Aggregate_TD_1130_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_1130_cmds_out;
    cfg_Aggregate_TD_1130_cmds_out.allocateHost();
    cfg_Aggregate_TD_1130_cmds_out.allocateDevBuffer(context_a, 33);
    cfgCmd cfg_Aggregate_TD_1130_cmds_part;
    cfg_Aggregate_TD_1130_cmds_part.allocateHost();
    get_cfg_dat_Aggregate_TD_1130_gqe_aggr_part (cfg_Aggregate_TD_1130_cmds_part.cmd);
    cfg_Aggregate_TD_1130_cmds_part.allocateDevBuffer(context_a, 32);
    // *************************** Kernel Setup ************************* // 
    AggrBufferTmp buftmp_a(context_a); 
    buftmp_a.BufferInitial(q_a); 
    std::cout << std::endl; 
    AggrKrnlEngine krnl_Aggregate_TD_1130_part;
    krnl_Aggregate_TD_1130_part = AggrKrnlEngine(program_a, q_a, "gqePart");
    krnl_Aggregate_TD_1130_part.setup_hp(512, 0, power_of_hpTimes_aggr, tbl_Filter_TD_2859_output, tbl_Filter_TD_2859_output_partition, cfg_Aggregate_TD_1130_cmds_part);
    AggrKrnlEngine krnl_Aggregate_TD_1130[hpTimes_aggr];
    for (int i = 0; i < hpTimes_aggr; i++) {
        krnl_Aggregate_TD_1130[i] = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    }
    for (int i = 0; i < hpTimes_aggr; i++) {
        krnl_Aggregate_TD_1130[i].setup(tbl_Filter_TD_2859_output_partition_array[i], tbl_Aggregate_TD_1130_output_partition_array[i], cfg_Aggregate_TD_1130_cmds, cfg_Aggregate_TD_1130_cmds_out, buftmp_a);
    }
    // ************************** Transfer Engine *********************** // 
    transEngine trans_Aggregate_TD_1130;
    trans_Aggregate_TD_1130.setq(q_a);
    trans_Aggregate_TD_1130.add(&(cfg_Aggregate_TD_1130_cmds_part));
    trans_Aggregate_TD_1130.add(&(cfg_Aggregate_TD_1130_cmds));
    transEngine trans_Aggregate_TD_1130_out;
    trans_Aggregate_TD_1130_out.setq(q_a);
    q_a.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_1130;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_1130;
    std::vector<cl::Event> events_Aggregate_TD_1130[2];
    events_h2d_wr_Aggregate_TD_1130.resize(1);
    events_d2h_rd_Aggregate_TD_1130.resize(1);
    events_Aggregate_TD_1130[0].resize(1);
    events_Aggregate_TD_1130[1].resize(hpTimes_aggr);
    std::vector<cl::Event> events_grp_Aggregate_TD_1130;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_1130;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_2_761_s, tv_r_Filter_2_761_e;
    gettimeofday(&tv_r_Filter_2_761_s, 0);
    SW_Filter_TD_2859(tbl_SerializeFromObject_TD_3513_input, tbl_Filter_TD_2859_output);
    gettimeofday(&tv_r_Filter_2_761_e, 0);

    struct timeval tv_r_Aggregate_1_552_s, tv_r_Aggregate_1_552_e;
    gettimeofday(&tv_r_Aggregate_1_552_s, 0);
    trans_Aggregate_TD_1130.add(&(tbl_Filter_TD_2859_output));
    trans_Aggregate_TD_1130.host2dev(0, &(prev_events_grp_Aggregate_TD_1130), &(events_h2d_wr_Aggregate_TD_1130[0]));
    events_grp_Aggregate_TD_1130.push_back(events_h2d_wr_Aggregate_TD_1130[0]);
    krnl_Aggregate_TD_1130_part.run(0, &(events_grp_Aggregate_TD_1130), &(events_Aggregate_TD_1130[0][0]));
    for (int i(0); i < hpTimes_aggr; ++i) {
        krnl_Aggregate_TD_1130[i].run(0, &(events_Aggregate_TD_1130[0]), &(events_Aggregate_TD_1130[1][i]));
    }
    
    for (int i(0); i < hpTimes_aggr; ++i) {
        trans_Aggregate_TD_1130_out.add(&(tbl_Aggregate_TD_1130_output_partition_array[i]));
    }
    trans_Aggregate_TD_1130_out.dev2host(0, &(events_Aggregate_TD_1130[1]), &(events_d2h_rd_Aggregate_TD_1130[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_1130_consolidate(tbl_Aggregate_TD_1130_output_partition_array, tbl_Aggregate_TD_1130_output, hpTimes_aggr);
    gettimeofday(&tv_r_Aggregate_1_552_e, 0);

    struct timeval tv_r_Sort_0_277_s, tv_r_Sort_0_277_e;
    gettimeofday(&tv_r_Sort_0_277_s, 0);
    SW_Sort_TD_0537(tbl_Aggregate_TD_1130_output, tbl_Sort_TD_0537_output);
    gettimeofday(&tv_r_Sort_0_277_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_761_s, &tv_r_Filter_2_761_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3513_input: " << tbl_SerializeFromObject_TD_3513_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_552_s, &tv_r_Aggregate_1_552_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_2859_output: " << tbl_Filter_TD_2859_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_277_s, &tv_r_Sort_0_277_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_1130_output: " << tbl_Aggregate_TD_1130_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 644.9954 * 1000 << "ms" << std::endl; 
    return 0; 
}
