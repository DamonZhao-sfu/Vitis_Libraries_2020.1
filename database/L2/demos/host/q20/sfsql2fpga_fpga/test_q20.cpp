// number of overlays (w/o fusion): 6 
// number of overlays (w/ fusion): 6 
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

#include "cfgFunc_q20.hpp" 
#include "q20.hpp" 

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
    std::cout << "NOTE:running query #20\n."; 
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
    Table tbl_Sort_TD_0524_output("tbl_Sort_TD_0524_output", 183000000, 2, "");
    tbl_Sort_TD_0524_output.allocateHost();
    tbl_Sort_TD_0524_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_164_output("tbl_JOIN_INNER_TD_164_output", 210, 2, "");
    tbl_JOIN_INNER_TD_164_output.allocateHost(1.2, hpTimes_join);
    Table tbl_JOIN_LEFTSEMI_TD_2681_output("tbl_JOIN_LEFTSEMI_TD_2681_output", 5366, 3, "");
    tbl_JOIN_LEFTSEMI_TD_2681_output.allocateHost(1.2, hpTimes_join);
    Table tbl_Filter_TD_220_output("tbl_Filter_TD_220_output", 183000000, 1, "");
    tbl_Filter_TD_220_output.allocateHost();
    Table tbl_Filter_TD_220_output_partition("tbl_Filter_TD_220_output_partition", 183000000, 1, "");
    tbl_Filter_TD_220_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_Filter_TD_220_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_Filter_TD_220_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_220_output_partition_array[i] = tbl_Filter_TD_220_output_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_3506_input_stringRowIDSubstitute;
    tbl_SerializeFromObject_TD_3506_input_stringRowIDSubstitute = Table("supplier", supplier_n, 4, in_dir);
    tbl_SerializeFromObject_TD_3506_input_stringRowIDSubstitute.addCol("s_suppkey", 4);
    tbl_SerializeFromObject_TD_3506_input_stringRowIDSubstitute.addCol("s_name", 4, 1, 0);
    tbl_SerializeFromObject_TD_3506_input_stringRowIDSubstitute.addCol("s_address", 4, 1, 0);
    tbl_SerializeFromObject_TD_3506_input_stringRowIDSubstitute.addCol("s_nationkey", 4);
    tbl_SerializeFromObject_TD_3506_input_stringRowIDSubstitute.allocateHost();
    tbl_SerializeFromObject_TD_3506_input_stringRowIDSubstitute.loadHost();
    tbl_SerializeFromObject_TD_3506_input_stringRowIDSubstitute.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_3506_input_stringRowIDSubstitute_partition("tbl_SerializeFromObject_TD_3506_input_stringRowIDSubstitute_partition", supplier_n, 4, "");
    tbl_SerializeFromObject_TD_3506_input_stringRowIDSubstitute_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_3506_input_stringRowIDSubstitute_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_3506_input_stringRowIDSubstitute_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_3506_input_stringRowIDSubstitute_partition_array[i] = tbl_SerializeFromObject_TD_3506_input_stringRowIDSubstitute_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_3506_input;
    tbl_SerializeFromObject_TD_3506_input = Table("supplier", supplier_n, 4, in_dir);
    tbl_SerializeFromObject_TD_3506_input.addCol("s_suppkey", 4);
    tbl_SerializeFromObject_TD_3506_input.addCol("s_name", TPCH_READ_S_NAME_LEN+1);
    tbl_SerializeFromObject_TD_3506_input.addCol("s_address", TPCH_READ_S_ADDR_MAX+1);
    tbl_SerializeFromObject_TD_3506_input.addCol("s_nationkey", 4);
    tbl_SerializeFromObject_TD_3506_input.allocateHost();
    tbl_SerializeFromObject_TD_3506_input.loadHost();
    tbl_SerializeFromObject_TD_3506_input.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_3989_output("tbl_JOIN_INNER_TD_3989_output", 7670, 1, "");
    tbl_JOIN_INNER_TD_3989_output.allocateHost(1.2, hpTimes_join);
    Table tbl_SerializeFromObject_TD_3494_input;
    tbl_SerializeFromObject_TD_3494_input = Table("nation", nation_n, 2, in_dir);
    tbl_SerializeFromObject_TD_3494_input.addCol("n_nationkey", 4);
    tbl_SerializeFromObject_TD_3494_input.addCol("n_name", TPCH_READ_NATION_LEN+1);
    tbl_SerializeFromObject_TD_3494_input.allocateHost();
    tbl_SerializeFromObject_TD_3494_input.loadHost();
    tbl_SerializeFromObject_TD_3494_input.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_LEFTSEMI_TD_4572_output("tbl_JOIN_LEFTSEMI_TD_4572_output", 11160, 3, "");
    tbl_JOIN_LEFTSEMI_TD_4572_output.allocateHost(1.2, hpTimes_join);
    Table tbl_Aggregate_TD_5593_output_preprocess("tbl_Aggregate_TD_5593_output_preprocess", 15000, 16, "");
    tbl_Aggregate_TD_5593_output_preprocess.allocateHost();
    Table tbl_Aggregate_TD_5593_output("tbl_Aggregate_TD_5593_output", 15000, 3, "");
    tbl_Aggregate_TD_5593_output.allocateHost(1.2, hpTimes_aggr);

    Table tbl_Aggregate_TD_5593_output_partition_array[hpTimes_aggr];
    for (int i(0); i < hpTimes_aggr; ++i) {
        tbl_Aggregate_TD_5593_output_partition_array[i] = tbl_Aggregate_TD_5593_output.createSubTable(i);
    }

    Table tbl_SerializeFromObject_TD_5483_input;
    tbl_SerializeFromObject_TD_5483_input = Table("partsupp", partsupp_n, 3, in_dir);
    tbl_SerializeFromObject_TD_5483_input.addCol("ps_partkey", 4);
    tbl_SerializeFromObject_TD_5483_input.addCol("ps_suppkey", 4);
    tbl_SerializeFromObject_TD_5483_input.addCol("ps_availqty", 4);
    tbl_SerializeFromObject_TD_5483_input.allocateHost();
    tbl_SerializeFromObject_TD_5483_input.loadHost();
    Table tbl_SerializeFromObject_TD_5483_input_partition("tbl_SerializeFromObject_TD_5483_input_partition", partsupp_n, 3, "");
    tbl_SerializeFromObject_TD_5483_input_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_5483_input_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_5483_input_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_5483_input_partition_array[i] = tbl_SerializeFromObject_TD_5483_input_partition.createSubTable(i);
    }
    Table tbl_JOIN_LEFTSEMI_TD_6770_output_preprocess("tbl_JOIN_LEFTSEMI_TD_6770_output_preprocess", 12816, 3, "");
    tbl_JOIN_LEFTSEMI_TD_6770_output_preprocess.allocateHost(1.2, hpTimes_join);
    tbl_JOIN_LEFTSEMI_TD_6770_output_preprocess.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_LEFTSEMI_TD_6770_output_preprocess_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_LEFTSEMI_TD_6770_output_preprocess_partition_array[i] = tbl_JOIN_LEFTSEMI_TD_6770_output_preprocess.createSubTable(i);
    }

    Table tbl_JOIN_LEFTSEMI_TD_6770_output("tbl_JOIN_LEFTSEMI_TD_6770_output", 12816, 3, "");
    tbl_JOIN_LEFTSEMI_TD_6770_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_6770_output_partition("tbl_JOIN_LEFTSEMI_TD_6770_output_partition", 12816, 3, "");
    tbl_JOIN_LEFTSEMI_TD_6770_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_JOIN_LEFTSEMI_TD_6770_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_LEFTSEMI_TD_6770_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_LEFTSEMI_TD_6770_output_partition_array[i] = tbl_JOIN_LEFTSEMI_TD_6770_output_partition.createSubTable(i);
    }

    Table tbl_Filter_TD_793_output("tbl_Filter_TD_793_output", 183000000, 3, "");
    tbl_Filter_TD_793_output.allocateHost();
    Table tbl_Filter_TD_793_output_partition("tbl_Filter_TD_793_output_partition", 183000000, 3, "");
    tbl_Filter_TD_793_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_Filter_TD_793_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_Filter_TD_793_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_793_output_partition_array[i] = tbl_Filter_TD_793_output_partition.createSubTable(i);
    }
    Table tbl_Filter_TD_7132_output("tbl_Filter_TD_7132_output", 183000000, 1, "");
    tbl_Filter_TD_7132_output.allocateHost();
    Table tbl_Filter_TD_7132_output_partition("tbl_Filter_TD_7132_output_partition", 183000000, 1, "");
    tbl_Filter_TD_7132_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_Filter_TD_7132_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_Filter_TD_7132_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_7132_output_partition_array[i] = tbl_Filter_TD_7132_output_partition.createSubTable(i);
    }

    Table tbl_SerializeFromObject_TD_8100_input;
    tbl_SerializeFromObject_TD_8100_input = Table("lineitem", lineitem_n, 4, in_dir);
    tbl_SerializeFromObject_TD_8100_input.addCol("l_partkey", 4);
    tbl_SerializeFromObject_TD_8100_input.addCol("l_suppkey", 4);
    tbl_SerializeFromObject_TD_8100_input.addCol("l_quantity", 4);
    tbl_SerializeFromObject_TD_8100_input.addCol("l_shipdate", 4);
    tbl_SerializeFromObject_TD_8100_input.allocateHost();
    tbl_SerializeFromObject_TD_8100_input.loadHost();
    Table tbl_SerializeFromObject_TD_8698_input;
    tbl_SerializeFromObject_TD_8698_input = Table("part", part_n, 2, in_dir);
    tbl_SerializeFromObject_TD_8698_input.addCol("p_partkey", 4);
    tbl_SerializeFromObject_TD_8698_input.addCol("p_name", TPCH_READ_P_NAME_LEN+1);
    tbl_SerializeFromObject_TD_8698_input.allocateHost();
    tbl_SerializeFromObject_TD_8698_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_SerializeFromObject_TD_8698_input.allocateDevBuffer(context_h, 32);
    tbl_SerializeFromObject_TD_8100_input.allocateDevBuffer(context_h, 32);
    tbl_JOIN_INNER_TD_164_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_164_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_164_output_partition_array[i] = tbl_JOIN_INNER_TD_164_output.createSubTable(i);
    }
    tbl_JOIN_LEFTSEMI_TD_2681_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_LEFTSEMI_TD_2681_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_LEFTSEMI_TD_2681_output_partition_array[i] = tbl_JOIN_LEFTSEMI_TD_2681_output.createSubTable(i);
    }
    tbl_Filter_TD_220_output.allocateDevBuffer(context_h, 33);
    tbl_SerializeFromObject_TD_3506_input_stringRowIDSubstitute.allocateDevBuffer(context_h, 33);
    tbl_JOIN_INNER_TD_3989_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_3989_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_3989_output_partition_array[i] = tbl_JOIN_INNER_TD_3989_output.createSubTable(i);
    }
    tbl_JOIN_LEFTSEMI_TD_4572_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_LEFTSEMI_TD_4572_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_LEFTSEMI_TD_4572_output_partition_array[i] = tbl_JOIN_LEFTSEMI_TD_4572_output.createSubTable(i);
    }
    tbl_JOIN_LEFTSEMI_TD_6770_output.allocateDevBuffer(context_a, 32);
    tbl_Aggregate_TD_5593_output_preprocess.allocateDevBuffer(context_a, 33);
    tbl_Aggregate_TD_5593_output.allocateDevBuffer(context_a, 32);
    tbl_SerializeFromObject_TD_5483_input.allocateDevBuffer(context_h, 33);
    tbl_JOIN_LEFTSEMI_TD_6770_output_preprocess.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_793_output.allocateDevBuffer(context_h, 33);
    tbl_Filter_TD_7132_output.allocateDevBuffer(context_h, 33);
    tbl_JOIN_LEFTSEMI_TD_6770_output_partition.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_164_cmds;
    cfg_JOIN_INNER_TD_164_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_164_gqe_join (cfg_JOIN_INNER_TD_164_cmds.cmd);
    cfg_JOIN_INNER_TD_164_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_164_cmds_part;
    cfg_JOIN_INNER_TD_164_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_164_gqe_join_part (cfg_JOIN_INNER_TD_164_cmds_part.cmd);
    cfg_JOIN_INNER_TD_164_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_2681_cmds;
    cfg_JOIN_LEFTSEMI_TD_2681_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_2681_gqe_join (cfg_JOIN_LEFTSEMI_TD_2681_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_2681_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_2681_cmds_part;
    cfg_JOIN_LEFTSEMI_TD_2681_cmds_part.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_2681_gqe_join_part (cfg_JOIN_LEFTSEMI_TD_2681_cmds_part.cmd);
    cfg_JOIN_LEFTSEMI_TD_2681_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_3989_cmds;
    cfg_JOIN_INNER_TD_3989_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_3989_gqe_join (cfg_JOIN_INNER_TD_3989_cmds.cmd);
    cfg_JOIN_INNER_TD_3989_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_4572_cmds;
    cfg_JOIN_LEFTSEMI_TD_4572_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_4572_gqe_join (cfg_JOIN_LEFTSEMI_TD_4572_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_4572_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_4572_cmds_part;
    cfg_JOIN_LEFTSEMI_TD_4572_cmds_part.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_4572_gqe_join_part (cfg_JOIN_LEFTSEMI_TD_4572_cmds_part.cmd);
    cfg_JOIN_LEFTSEMI_TD_4572_cmds_part.allocateDevBuffer(context_h, 32);
    
    cfgCmd cfg_Aggregate_TD_5593_cmds_part;
    cfg_Aggregate_TD_5593_cmds_part.allocateHost();
    get_cfg_dat_Aggregate_TD_5593_gqe_aggr_part (cfg_Aggregate_TD_5593_cmds_part.cmd);
    cfg_Aggregate_TD_5593_cmds_part.allocateDevBuffer(context_a, 32);
    
    AggrCfgCmd cfg_Aggregate_TD_5593_cmds;
    cfg_Aggregate_TD_5593_cmds.allocateHost();
    get_cfg_dat_Aggregate_TD_5593_gqe_aggr(cfg_Aggregate_TD_5593_cmds.cmd);
    cfg_Aggregate_TD_5593_cmds.allocateDevBuffer(context_a, 32);
    AggrCfgCmd cfg_Aggregate_TD_5593_cmds_out;
    cfg_Aggregate_TD_5593_cmds_out.allocateHost();
    cfg_Aggregate_TD_5593_cmds_out.allocateDevBuffer(context_a, 33);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_6770_cmds;
    cfg_JOIN_LEFTSEMI_TD_6770_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_6770_gqe_join (cfg_JOIN_LEFTSEMI_TD_6770_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_6770_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_6770_cmds_part;
    cfg_JOIN_LEFTSEMI_TD_6770_cmds_part.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_6770_gqe_join_part (cfg_JOIN_LEFTSEMI_TD_6770_cmds_part.cmd);
    cfg_JOIN_LEFTSEMI_TD_6770_cmds_part.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    AggrBufferTmp buftmp_a(context_a); 
    buftmp_a.BufferInitial(q_a); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_164_part_right;
    krnl_JOIN_INNER_TD_164_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_164_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_Filter_TD_220_output, tbl_Filter_TD_220_output_partition, cfg_JOIN_INNER_TD_164_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_164[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_164[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_164[i].setup(tbl_JOIN_LEFTSEMI_TD_2681_output_partition_array[i], tbl_Filter_TD_220_output_partition_array[i], tbl_JOIN_INNER_TD_164_output_partition_array[i], cfg_JOIN_INNER_TD_164_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_LEFTSEMI_TD_2681_part_right;
    krnl_JOIN_LEFTSEMI_TD_2681_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_LEFTSEMI_TD_2681_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_SerializeFromObject_TD_3506_input_stringRowIDSubstitute, tbl_SerializeFromObject_TD_3506_input_stringRowIDSubstitute_partition, cfg_JOIN_LEFTSEMI_TD_2681_cmds_part);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_2681[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_LEFTSEMI_TD_2681[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_LEFTSEMI_TD_2681[i].setup(tbl_JOIN_INNER_TD_3989_output_partition_array[i], tbl_SerializeFromObject_TD_3506_input_stringRowIDSubstitute_partition_array[i], tbl_JOIN_LEFTSEMI_TD_2681_output_partition_array[i], cfg_JOIN_LEFTSEMI_TD_2681_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_INNER_TD_3989[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_3989[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_3989[i].setup(tbl_JOIN_LEFTSEMI_TD_4572_output_partition_array[i], tbl_Aggregate_TD_5593_output_partition_array[i], tbl_JOIN_INNER_TD_3989_output_partition_array[i], cfg_JOIN_INNER_TD_3989_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_LEFTSEMI_TD_4572_part_left;
    krnl_JOIN_LEFTSEMI_TD_4572_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_LEFTSEMI_TD_4572_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_Filter_TD_7132_output, tbl_Filter_TD_7132_output_partition, cfg_JOIN_LEFTSEMI_TD_4572_cmds_part);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_4572_part_right;
    krnl_JOIN_LEFTSEMI_TD_4572_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_LEFTSEMI_TD_4572_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_SerializeFromObject_TD_5483_input, tbl_SerializeFromObject_TD_5483_input_partition, cfg_JOIN_LEFTSEMI_TD_4572_cmds_part);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_4572[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_LEFTSEMI_TD_4572[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_LEFTSEMI_TD_4572[i].setup(tbl_Filter_TD_7132_output_partition_array[i], tbl_SerializeFromObject_TD_5483_input_partition_array[i], tbl_JOIN_LEFTSEMI_TD_4572_output_partition_array[i], cfg_JOIN_LEFTSEMI_TD_4572_cmds, buftmp_h);
    }
    AggrKrnlEngine krnl_Aggregate_TD_5593_part;
    krnl_Aggregate_TD_5593_part = AggrKrnlEngine(program_a, q_a, "gqePart");
    krnl_Aggregate_TD_5593_part.setup_hp(512, 0, power_of_hpTimes_aggr, tbl_JOIN_LEFTSEMI_TD_6770_output, tbl_JOIN_LEFTSEMI_TD_6770_output_partition, cfg_Aggregate_TD_5593_cmds_part);
    AggrKrnlEngine krnl_Aggregate_TD_5593[hpTimes_aggr];
    for (int i = 0; i < hpTimes_aggr; i++) {
        krnl_Aggregate_TD_5593[i] = AggrKrnlEngine(program_a, q_a, "gqeAggr");
    }
    for (int i = 0; i < hpTimes_aggr; i++) {
        krnl_Aggregate_TD_5593[i].setup(tbl_JOIN_LEFTSEMI_TD_6770_output_partition_array[i], tbl_Aggregate_TD_5593_output_partition_array[i], cfg_Aggregate_TD_5593_cmds, cfg_Aggregate_TD_5593_cmds_out, buftmp_a);
    }
    krnlEngine krnl_JOIN_LEFTSEMI_TD_6770_part_left;
    krnl_JOIN_LEFTSEMI_TD_6770_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_LEFTSEMI_TD_6770_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_Filter_TD_7132_output, tbl_Filter_TD_7132_output_partition, cfg_JOIN_LEFTSEMI_TD_6770_cmds_part);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_6770_part_right;
    krnl_JOIN_LEFTSEMI_TD_6770_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_LEFTSEMI_TD_6770_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_Filter_TD_793_output, tbl_Filter_TD_793_output_partition, cfg_JOIN_LEFTSEMI_TD_6770_cmds_part);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_6770[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_LEFTSEMI_TD_6770[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_LEFTSEMI_TD_6770[i].setup(tbl_Filter_TD_7132_output_partition_array[i], tbl_Filter_TD_793_output_partition_array[i], tbl_JOIN_LEFTSEMI_TD_6770_output_preprocess_partition_array[i], cfg_JOIN_LEFTSEMI_TD_6770_cmds, buftmp_h);
    }
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_164;
    trans_JOIN_INNER_TD_164.setq(q_h);
    trans_JOIN_INNER_TD_164.add(&(cfg_JOIN_INNER_TD_164_cmds_part));
    trans_JOIN_INNER_TD_164.add(&(cfg_JOIN_INNER_TD_164_cmds));
    transEngine trans_JOIN_INNER_TD_164_out;
    trans_JOIN_INNER_TD_164_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_LEFTSEMI_TD_2681;
    trans_JOIN_LEFTSEMI_TD_2681.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_2681.add(&(cfg_JOIN_LEFTSEMI_TD_2681_cmds));
    trans_JOIN_LEFTSEMI_TD_2681.add(&(tbl_SerializeFromObject_TD_3506_input_stringRowIDSubstitute));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_3989;
    trans_JOIN_INNER_TD_3989.setq(q_h);
    trans_JOIN_INNER_TD_3989.add(&(cfg_JOIN_INNER_TD_3989_cmds));
    q_h.finish();
    transEngine trans_JOIN_LEFTSEMI_TD_4572;
    trans_JOIN_LEFTSEMI_TD_4572.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_4572.add(&(cfg_JOIN_LEFTSEMI_TD_4572_cmds_part));
    trans_JOIN_LEFTSEMI_TD_4572.add(&(cfg_JOIN_LEFTSEMI_TD_4572_cmds));
    trans_JOIN_LEFTSEMI_TD_4572.add(&(tbl_SerializeFromObject_TD_5483_input));
    q_h.finish();
    transEngine trans_Aggregate_TD_5593;
    trans_Aggregate_TD_5593.setq(q_a);
    trans_Aggregate_TD_5593.add(&(cfg_Aggregate_TD_5593_cmds_part));
    trans_Aggregate_TD_5593.add(&(cfg_Aggregate_TD_5593_cmds));
    transEngine trans_Aggregate_TD_5593_out;
    trans_Aggregate_TD_5593_out.setq(q_a);
    q_a.finish();
    transEngine trans_JOIN_LEFTSEMI_TD_6770;
    trans_JOIN_LEFTSEMI_TD_6770.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_6770.add(&(cfg_JOIN_LEFTSEMI_TD_6770_cmds_part));
    trans_JOIN_LEFTSEMI_TD_6770.add(&(cfg_JOIN_LEFTSEMI_TD_6770_cmds));
    transEngine trans_JOIN_LEFTSEMI_TD_6770_out;
    trans_JOIN_LEFTSEMI_TD_6770_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_164;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_164;
    std::vector<cl::Event> events_JOIN_INNER_TD_164[2];
    events_h2d_wr_JOIN_INNER_TD_164.resize(1);
    events_d2h_rd_JOIN_INNER_TD_164.resize(1);
    events_JOIN_INNER_TD_164[0].resize(1);
    events_JOIN_INNER_TD_164[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_164;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_164;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_2681;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_2681;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_2681[2];
    events_h2d_wr_JOIN_LEFTSEMI_TD_2681.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_2681.resize(1);
    events_JOIN_LEFTSEMI_TD_2681[0].resize(1);
    events_JOIN_LEFTSEMI_TD_2681[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_2681;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_2681;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_3989;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_3989;
    std::vector<cl::Event> events_JOIN_INNER_TD_3989[2];
    events_h2d_wr_JOIN_INNER_TD_3989.resize(1);
    events_d2h_rd_JOIN_INNER_TD_3989.resize(1);
    events_JOIN_INNER_TD_3989[0].resize(0);
    events_JOIN_INNER_TD_3989[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_3989;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_3989;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_4572;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_4572;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_4572[2];
    events_h2d_wr_JOIN_LEFTSEMI_TD_4572.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_4572.resize(1);
    events_JOIN_LEFTSEMI_TD_4572[0].resize(2);
    events_JOIN_LEFTSEMI_TD_4572[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_4572;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_4572;
    std::vector<cl::Event> events_h2d_wr_Aggregate_TD_5593;
    std::vector<cl::Event> events_d2h_rd_Aggregate_TD_5593;
    std::vector<cl::Event> events_Aggregate_TD_5593[2];
    events_h2d_wr_Aggregate_TD_5593.resize(1);
    events_d2h_rd_Aggregate_TD_5593.resize(1);
    events_Aggregate_TD_5593[0].resize(1);
    events_Aggregate_TD_5593[1].resize(hpTimes_aggr);
    std::vector<cl::Event> events_grp_Aggregate_TD_5593;
    std::vector<cl::Event> prev_events_grp_Aggregate_TD_5593;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_6770;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_6770;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_6770[2];
    events_h2d_wr_JOIN_LEFTSEMI_TD_6770.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_6770.resize(1);
    events_JOIN_LEFTSEMI_TD_6770[0].resize(2);
    events_JOIN_LEFTSEMI_TD_6770[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_6770;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_6770;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_7_456_s, tv_r_Filter_7_456_e;
    gettimeofday(&tv_r_Filter_7_456_s, 0);
    SW_Filter_TD_7132(tbl_SerializeFromObject_TD_8698_input, tbl_Filter_TD_7132_output);
    gettimeofday(&tv_r_Filter_7_456_e, 0);

    struct timeval tv_r_Filter_7_62_s, tv_r_Filter_7_62_e;
    gettimeofday(&tv_r_Filter_7_62_s, 0);
    SW_Filter_TD_793(tbl_SerializeFromObject_TD_8100_input, tbl_Filter_TD_793_output);
    gettimeofday(&tv_r_Filter_7_62_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_6_483_s, tv_r_JOIN_LEFTSEMI_6_483_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_6_483_s, 0);
    trans_JOIN_LEFTSEMI_TD_6770.add(&(tbl_Filter_TD_793_output));
    trans_JOIN_LEFTSEMI_TD_6770.add(&(tbl_Filter_TD_7132_output));
    trans_JOIN_LEFTSEMI_TD_6770.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_6770), &(events_h2d_wr_JOIN_LEFTSEMI_TD_6770[0]));
    events_grp_JOIN_LEFTSEMI_TD_6770.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_6770[0]);
    krnl_JOIN_LEFTSEMI_TD_6770_part_left.run(0, &(events_grp_JOIN_LEFTSEMI_TD_6770), &(events_JOIN_LEFTSEMI_TD_6770[0][0]));
    krnl_JOIN_LEFTSEMI_TD_6770_part_right.run(0, &(events_grp_JOIN_LEFTSEMI_TD_6770), &(events_JOIN_LEFTSEMI_TD_6770[0][1]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_LEFTSEMI_TD_6770[i].run(0, &(events_JOIN_LEFTSEMI_TD_6770[0]), &(events_JOIN_LEFTSEMI_TD_6770[1][i]));
    }
    
    for (int i(0); i < hpTimes_join; ++i) {
        trans_JOIN_LEFTSEMI_TD_6770_out.add(&(tbl_JOIN_LEFTSEMI_TD_6770_output_preprocess_partition_array[i]));
    }
    trans_JOIN_LEFTSEMI_TD_6770_out.dev2host(0, &(events_JOIN_LEFTSEMI_TD_6770[1]), &(events_d2h_rd_JOIN_LEFTSEMI_TD_6770[0]));
    q_h.flush();
    q_h.finish();
    WaitForEvents(events_d2h_rd_JOIN_LEFTSEMI_TD_6770);
    tbl_JOIN_LEFTSEMI_TD_6770_output_preprocess.copyTableData(&(tbl_JOIN_LEFTSEMI_TD_6770_output));
    gettimeofday(&tv_r_JOIN_LEFTSEMI_6_483_e, 0);

    struct timeval tv_r_Aggregate_5_949_s, tv_r_Aggregate_5_949_e;
    gettimeofday(&tv_r_Aggregate_5_949_s, 0);
    trans_Aggregate_TD_5593.add(&(tbl_JOIN_LEFTSEMI_TD_6770_output));
    trans_Aggregate_TD_5593.host2dev(0, &(prev_events_grp_Aggregate_TD_5593), &(events_h2d_wr_Aggregate_TD_5593[0]));
    events_grp_Aggregate_TD_5593.push_back(events_h2d_wr_Aggregate_TD_5593[0]);
    krnl_Aggregate_TD_5593_part.run(0, &(events_grp_Aggregate_TD_5593), &(events_Aggregate_TD_5593[0][0]));
    for (int i(0); i < hpTimes_aggr; ++i) {
        krnl_Aggregate_TD_5593[i].run(0, &(events_Aggregate_TD_5593[0]), &(events_Aggregate_TD_5593[1][i]));
    }
    
    for (int i(0); i < hpTimes_aggr; ++i) {
        trans_Aggregate_TD_5593_out.add(&(tbl_Aggregate_TD_5593_output_partition_array[i]));
    }
    trans_Aggregate_TD_5593_out.dev2host(0, &(events_Aggregate_TD_5593[1]), &(events_d2h_rd_Aggregate_TD_5593[0]));
    q_a.flush();
    q_a.finish();
    
    SW_Aggregate_TD_5593_consolidate(tbl_Aggregate_TD_5593_output_partition_array, tbl_Aggregate_TD_5593_output, hpTimes_aggr);
    gettimeofday(&tv_r_Aggregate_5_949_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_4_695_s, tv_r_JOIN_LEFTSEMI_4_695_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_4_695_s, 0);
    trans_JOIN_LEFTSEMI_TD_4572.add(&(tbl_Filter_TD_7132_output));
    trans_JOIN_LEFTSEMI_TD_4572.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_4572), &(events_h2d_wr_JOIN_LEFTSEMI_TD_4572[0]));
    events_grp_JOIN_LEFTSEMI_TD_4572.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_4572[0]);
    krnl_JOIN_LEFTSEMI_TD_4572_part_left.run(0, &(events_grp_JOIN_LEFTSEMI_TD_4572), &(events_JOIN_LEFTSEMI_TD_4572[0][0]));
    krnl_JOIN_LEFTSEMI_TD_4572_part_right.run(0, &(events_grp_JOIN_LEFTSEMI_TD_4572), &(events_JOIN_LEFTSEMI_TD_4572[0][1]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_LEFTSEMI_TD_4572[i].run(0, &(events_JOIN_LEFTSEMI_TD_4572[0]), &(events_JOIN_LEFTSEMI_TD_4572[1][i]));
    }
    gettimeofday(&tv_r_JOIN_LEFTSEMI_4_695_e, 0);

    struct timeval tv_r_JOIN_INNER_3_900_s, tv_r_JOIN_INNER_3_900_e;
    gettimeofday(&tv_r_JOIN_INNER_3_900_s, 0);
    prev_events_grp_JOIN_INNER_TD_3989.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_4572[0]);
    trans_JOIN_INNER_TD_3989.add(&(tbl_Aggregate_TD_5593_output));
    trans_JOIN_INNER_TD_3989.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_3989), &(events_h2d_wr_JOIN_INNER_TD_3989[0]));
    events_grp_JOIN_INNER_TD_3989.push_back(events_h2d_wr_JOIN_INNER_TD_3989[0]);
    events_grp_JOIN_INNER_TD_3989.insert(std::end(events_grp_JOIN_INNER_TD_3989), std::begin(events_JOIN_LEFTSEMI_TD_4572[0]), std::end(events_JOIN_LEFTSEMI_TD_4572[0]));
    events_grp_JOIN_INNER_TD_3989.insert(std::end(events_grp_JOIN_INNER_TD_3989), std::begin(events_JOIN_LEFTSEMI_TD_4572[1]), std::end(events_JOIN_LEFTSEMI_TD_4572[1]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_3989[i].run(0, &(events_grp_JOIN_INNER_TD_3989), &(events_JOIN_INNER_TD_3989[1][i]));
    }
    gettimeofday(&tv_r_JOIN_INNER_3_900_e, 0);

    struct timeval tv_r_Filter_2_59_s, tv_r_Filter_2_59_e;
    gettimeofday(&tv_r_Filter_2_59_s, 0);
    SW_Filter_TD_220(tbl_SerializeFromObject_TD_3494_input, tbl_Filter_TD_220_output);
    gettimeofday(&tv_r_Filter_2_59_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_2_51_s, tv_r_JOIN_LEFTSEMI_2_51_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_2_51_s, 0);
    prev_events_grp_JOIN_LEFTSEMI_TD_2681.push_back(events_h2d_wr_JOIN_INNER_TD_3989[0]);
    trans_JOIN_LEFTSEMI_TD_2681.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_2681), &(events_h2d_wr_JOIN_LEFTSEMI_TD_2681[0]));
    events_grp_JOIN_LEFTSEMI_TD_2681.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_2681[0]);
    events_grp_JOIN_LEFTSEMI_TD_2681.insert(std::end(events_grp_JOIN_LEFTSEMI_TD_2681), std::begin(events_JOIN_INNER_TD_3989[0]), std::end(events_JOIN_INNER_TD_3989[0]));
    events_grp_JOIN_LEFTSEMI_TD_2681.insert(std::end(events_grp_JOIN_LEFTSEMI_TD_2681), std::begin(events_JOIN_INNER_TD_3989[1]), std::end(events_JOIN_INNER_TD_3989[1]));
    krnl_JOIN_LEFTSEMI_TD_2681_part_right.run(0, &(events_grp_JOIN_LEFTSEMI_TD_2681), &(events_JOIN_LEFTSEMI_TD_2681[0][0]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_LEFTSEMI_TD_2681[i].run(0, &(events_grp_JOIN_LEFTSEMI_TD_2681), &(events_JOIN_LEFTSEMI_TD_2681[1][i]));
    }
    gettimeofday(&tv_r_JOIN_LEFTSEMI_2_51_e, 0);

    struct timeval tv_r_JOIN_INNER_1_103_s, tv_r_JOIN_INNER_1_103_e;
    gettimeofday(&tv_r_JOIN_INNER_1_103_s, 0);
    prev_events_grp_JOIN_INNER_TD_164.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_2681[0]);
    trans_JOIN_INNER_TD_164.add(&(tbl_Filter_TD_220_output));
    trans_JOIN_INNER_TD_164.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_164), &(events_h2d_wr_JOIN_INNER_TD_164[0]));
    events_grp_JOIN_INNER_TD_164.push_back(events_h2d_wr_JOIN_INNER_TD_164[0]);
    events_grp_JOIN_INNER_TD_164.insert(std::end(events_grp_JOIN_INNER_TD_164), std::begin(events_JOIN_LEFTSEMI_TD_2681[0]), std::end(events_JOIN_LEFTSEMI_TD_2681[0]));
    events_grp_JOIN_INNER_TD_164.insert(std::end(events_grp_JOIN_INNER_TD_164), std::begin(events_JOIN_LEFTSEMI_TD_2681[1]), std::end(events_JOIN_LEFTSEMI_TD_2681[1]));
    krnl_JOIN_INNER_TD_164_part_right.run(0, &(events_grp_JOIN_INNER_TD_164), &(events_JOIN_INNER_TD_164[0][0]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_164[i].run(0, &(events_grp_JOIN_INNER_TD_164), &(events_JOIN_INNER_TD_164[1][i]));
    }
    
    for (int i(0); i < hpTimes_join; ++i) {
        trans_JOIN_INNER_TD_164_out.add(&(tbl_JOIN_INNER_TD_164_output_partition_array[i]));
    }
    trans_JOIN_INNER_TD_164_out.dev2host(0, &(events_JOIN_INNER_TD_164[1]), &(events_d2h_rd_JOIN_INNER_TD_164[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_1_103_e, 0);

    struct timeval tv_r_Sort_0_898_s, tv_r_Sort_0_898_e;
    gettimeofday(&tv_r_Sort_0_898_s, 0);
    SW_Sort_TD_0524(tbl_JOIN_INNER_TD_164_output_partition_array, tbl_SerializeFromObject_TD_3506_input, tbl_SerializeFromObject_TD_3494_input, tbl_Sort_TD_0524_output, hpTimes_join);
    gettimeofday(&tv_r_Sort_0_898_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_456_s, &tv_r_Filter_7_456_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8698_input: " << tbl_SerializeFromObject_TD_8698_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_62_s, &tv_r_Filter_7_62_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8100_input: " << tbl_SerializeFromObject_TD_8100_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_6: " << tvdiff(&tv_r_JOIN_LEFTSEMI_6_483_s, &tv_r_JOIN_LEFTSEMI_6_483_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_793_output: " << tbl_Filter_TD_793_output.getNumRow() << " " << "tbl_Filter_TD_7132_output: " << tbl_Filter_TD_7132_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_949_s, &tv_r_Aggregate_5_949_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTSEMI_TD_6770_output: " << tbl_JOIN_LEFTSEMI_TD_6770_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_4: " << tvdiff(&tv_r_JOIN_LEFTSEMI_4_695_s, &tv_r_JOIN_LEFTSEMI_4_695_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5483_input: " << tbl_SerializeFromObject_TD_5483_input.getNumRow() << " " << "tbl_Filter_TD_7132_output: " << tbl_Filter_TD_7132_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_900_s, &tv_r_JOIN_INNER_3_900_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTSEMI_TD_4572_output: " << tbl_JOIN_LEFTSEMI_TD_4572_output.getNumRow() << " " << "tbl_Aggregate_TD_5593_output: " << tbl_Aggregate_TD_5593_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_2: " << tvdiff(&tv_r_Filter_2_59_s, &tv_r_Filter_2_59_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3494_input: " << tbl_SerializeFromObject_TD_3494_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_2: " << tvdiff(&tv_r_JOIN_LEFTSEMI_2_51_s, &tv_r_JOIN_LEFTSEMI_2_51_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_3506_input_stringRowIDSubstitute: " << tbl_SerializeFromObject_TD_3506_input_stringRowIDSubstitute.getNumRow() << " " << "tbl_JOIN_INNER_TD_3989_output: " << tbl_JOIN_INNER_TD_3989_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_1: " << tvdiff(&tv_r_JOIN_INNER_1_103_s, &tv_r_JOIN_INNER_1_103_e) / 1000.0 << " ms " 
     << "tbl_JOIN_LEFTSEMI_TD_2681_output: " << tbl_JOIN_LEFTSEMI_TD_2681_output.getNumRow() << " " << "tbl_Filter_TD_220_output: " << tbl_Filter_TD_220_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_898_s, &tv_r_Sort_0_898_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_164_output: " << tbl_JOIN_INNER_TD_164_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 661.1226 * 1000 << "ms" << std::endl; 
    return 0; 
}
