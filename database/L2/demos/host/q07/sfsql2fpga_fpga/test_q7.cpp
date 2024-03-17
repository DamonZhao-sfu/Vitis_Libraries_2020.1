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

#include "cfgFunc_q7.hpp" 
#include "q7.hpp" 

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
    std::cout << "NOTE:running query #7\n."; 
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
    // *********************** Partition Infomation ********************* // 
    int hpTimes_join = 32; 
    int power_of_hpTimes_join = log2(hpTimes_join); 
    std::cout << "Number of partition (gqeJoin) is: " << hpTimes_join << std::endl; 
    int hpTimes_aggr = 256; 
    int power_of_hpTimes_aggr = log2(hpTimes_aggr); 
    std::cout << "Number of partition (gqeAggr) is: " << hpTimes_aggr << std::endl; 
    // ****************************** Tables **************************** // 
    Table tbl_Sort_TD_0792_output("tbl_Sort_TD_0792_output", 183000000, 4, "");
    tbl_Sort_TD_0792_output.allocateHost();
    Table tbl_Aggregate_TD_143_output("tbl_Aggregate_TD_143_output", 183000000, 4, "");
    tbl_Aggregate_TD_143_output.allocateHost();
    Table tbl_Project_TD_2670_output("tbl_Project_TD_2670_output", 183000000, 4, "");
    tbl_Project_TD_2670_output.allocateHost();
    Table tbl_JOIN_INNER_TD_3444_output("tbl_JOIN_INNER_TD_3444_output", 183000000, 6, "");
    tbl_JOIN_INNER_TD_3444_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4775_output("tbl_JOIN_INNER_TD_4775_output", 153500, 5, "");
    tbl_JOIN_INNER_TD_4775_output.allocateHost(1.2, hpTimes_join);
    Table tbl_Filter_TD_4241_output("tbl_Filter_TD_4241_output", 183000000, 2, "");
    tbl_Filter_TD_4241_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5663_output("tbl_JOIN_INNER_TD_5663_output", 153500, 6, "");
    tbl_JOIN_INNER_TD_5663_output.allocateHost(1.2, hpTimes_join);
    Table tbl_SerializeFromObject_TD_5327_input;
    tbl_SerializeFromObject_TD_5327_input = Table("customer", customer_n, 2, in_dir);
    tbl_SerializeFromObject_TD_5327_input.addCol("c_custkey", 4);
    tbl_SerializeFromObject_TD_5327_input.addCol("c_nationkey", 4);
    tbl_SerializeFromObject_TD_5327_input.allocateHost();
    tbl_SerializeFromObject_TD_5327_input.loadHost();
    Table tbl_SerializeFromObject_TD_5327_input_partition("tbl_SerializeFromObject_TD_5327_input_partition", customer_n, 2, "");
    tbl_SerializeFromObject_TD_5327_input_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_5327_input_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_5327_input_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_5327_input_partition_array[i] = tbl_SerializeFromObject_TD_5327_input_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_5601_input;
    tbl_SerializeFromObject_TD_5601_input = Table("nation", nation_n, 2, in_dir);
    tbl_SerializeFromObject_TD_5601_input.addCol("n_nationkey", 4);
    tbl_SerializeFromObject_TD_5601_input.addCol("n_name", TPCH_READ_NATION_LEN+1);
    tbl_SerializeFromObject_TD_5601_input.allocateHost();
    tbl_SerializeFromObject_TD_5601_input.loadHost();
    Table tbl_JOIN_INNER_TD_6223_output("tbl_JOIN_INNER_TD_6223_output", 153500, 6, "");
    tbl_JOIN_INNER_TD_6223_output.allocateHost(1.2, hpTimes_join);
    Table tbl_SerializeFromObject_TD_676_input;
    tbl_SerializeFromObject_TD_676_input = Table("order", order_n, 2, in_dir);
    tbl_SerializeFromObject_TD_676_input.addCol("o_orderkey", 4);
    tbl_SerializeFromObject_TD_676_input.addCol("o_custkey", 4);
    tbl_SerializeFromObject_TD_676_input.allocateHost();
    tbl_SerializeFromObject_TD_676_input.loadHost();
    Table tbl_SerializeFromObject_TD_676_input_partition("tbl_SerializeFromObject_TD_676_input_partition", order_n, 2, "");
    tbl_SerializeFromObject_TD_676_input_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_676_input_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_676_input_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_676_input_partition_array[i] = tbl_SerializeFromObject_TD_676_input_partition.createSubTable(i);
    }
    Table tbl_JOIN_INNER_TD_7594_output("tbl_JOIN_INNER_TD_7594_output", 1829000, 5, "");
    tbl_JOIN_INNER_TD_7594_output.allocateHost(1.2, hpTimes_join);
    Table tbl_Filter_TD_5439_output("tbl_Filter_TD_5439_output", 183000000, 2, "");
    tbl_Filter_TD_5439_output.allocateHost();
    Table tbl_Filter_TD_5439_output_partition("tbl_Filter_TD_5439_output_partition", 183000000, 2, "");
    tbl_Filter_TD_5439_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_Filter_TD_5439_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_Filter_TD_5439_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_5439_output_partition_array[i] = tbl_Filter_TD_5439_output_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_8488_input;
    tbl_SerializeFromObject_TD_8488_input = Table("supplier", supplier_n, 2, in_dir);
    tbl_SerializeFromObject_TD_8488_input.addCol("s_suppkey", 4);
    tbl_SerializeFromObject_TD_8488_input.addCol("s_nationkey", 4);
    tbl_SerializeFromObject_TD_8488_input.allocateHost();
    tbl_SerializeFromObject_TD_8488_input.loadHost();
    Table tbl_SerializeFromObject_TD_8488_input_partition("tbl_SerializeFromObject_TD_8488_input_partition", supplier_n, 2, "");
    tbl_SerializeFromObject_TD_8488_input_partition.allocateHost(1.2, hpTimes_join);
    tbl_SerializeFromObject_TD_8488_input_partition.allocateDevBuffer(context_h, 32);
    Table tbl_SerializeFromObject_TD_8488_input_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_SerializeFromObject_TD_8488_input_partition_array[i] = tbl_SerializeFromObject_TD_8488_input_partition.createSubTable(i);
    }
    Table tbl_Filter_TD_8218_output("tbl_Filter_TD_8218_output", 183000000, 5, "");
    tbl_Filter_TD_8218_output.allocateHost();
    Table tbl_Filter_TD_8218_output_partition("tbl_Filter_TD_8218_output_partition", 183000000, 5, "");
    tbl_Filter_TD_8218_output_partition.allocateHost(1.2, hpTimes_join);
    tbl_Filter_TD_8218_output_partition.allocateDevBuffer(context_h, 32);
    Table tbl_Filter_TD_8218_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_Filter_TD_8218_output_partition_array[i] = tbl_Filter_TD_8218_output_partition.createSubTable(i);
    }
    Table tbl_SerializeFromObject_TD_6553_input;
    tbl_SerializeFromObject_TD_6553_input = Table("nation", nation_n, 2, in_dir);
    tbl_SerializeFromObject_TD_6553_input.addCol("n_nationkey", 4);
    tbl_SerializeFromObject_TD_6553_input.addCol("n_name", TPCH_READ_NATION_LEN+1);
    tbl_SerializeFromObject_TD_6553_input.allocateHost();
    tbl_SerializeFromObject_TD_6553_input.loadHost();
    Table tbl_SerializeFromObject_TD_9838_input;
    tbl_SerializeFromObject_TD_9838_input = Table("lineitem", lineitem_n, 5, in_dir);
    tbl_SerializeFromObject_TD_9838_input.addCol("l_orderkey", 4);
    tbl_SerializeFromObject_TD_9838_input.addCol("l_suppkey", 4);
    tbl_SerializeFromObject_TD_9838_input.addCol("l_extendedprice", 4);
    tbl_SerializeFromObject_TD_9838_input.addCol("l_discount", 4);
    tbl_SerializeFromObject_TD_9838_input.addCol("l_shipdate", 4);
    tbl_SerializeFromObject_TD_9838_input.allocateHost();
    tbl_SerializeFromObject_TD_9838_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_4775_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_4775_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_4775_output_partition_array[i] = tbl_JOIN_INNER_TD_4775_output.createSubTable(i);
    }
    tbl_JOIN_INNER_TD_5663_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_5663_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_5663_output_partition_array[i] = tbl_JOIN_INNER_TD_5663_output.createSubTable(i);
    }
    tbl_SerializeFromObject_TD_5327_input.allocateDevBuffer(context_h, 33);
    tbl_JOIN_INNER_TD_6223_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_6223_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_6223_output_partition_array[i] = tbl_JOIN_INNER_TD_6223_output.createSubTable(i);
    }
    tbl_SerializeFromObject_TD_676_input.allocateDevBuffer(context_h, 33);
    tbl_JOIN_INNER_TD_7594_output.allocateDevBuffer(context_h, 32);
    Table tbl_JOIN_INNER_TD_7594_output_partition_array[hpTimes_join];
    for (int i(0); i < hpTimes_join; ++i) {
        tbl_JOIN_INNER_TD_7594_output_partition_array[i] = tbl_JOIN_INNER_TD_7594_output.createSubTable(i);
    }
    tbl_Filter_TD_5439_output.allocateDevBuffer(context_h, 33);
    tbl_SerializeFromObject_TD_8488_input.allocateDevBuffer(context_h, 33);
    tbl_Filter_TD_8218_output.allocateDevBuffer(context_h, 33);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_4775_cmds;
    cfg_JOIN_INNER_TD_4775_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_4775_gqe_join (cfg_JOIN_INNER_TD_4775_cmds.cmd);
    cfg_JOIN_INNER_TD_4775_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_4775_cmds_part;
    cfg_JOIN_INNER_TD_4775_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_4775_gqe_join_part (cfg_JOIN_INNER_TD_4775_cmds_part.cmd);
    cfg_JOIN_INNER_TD_4775_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_5663_cmds;
    cfg_JOIN_INNER_TD_5663_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_5663_gqe_join (cfg_JOIN_INNER_TD_5663_cmds.cmd);
    cfg_JOIN_INNER_TD_5663_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_5663_cmds_part;
    cfg_JOIN_INNER_TD_5663_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_5663_gqe_join_part (cfg_JOIN_INNER_TD_5663_cmds_part.cmd);
    cfg_JOIN_INNER_TD_5663_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_6223_cmds;
    cfg_JOIN_INNER_TD_6223_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_6223_gqe_join (cfg_JOIN_INNER_TD_6223_cmds.cmd);
    cfg_JOIN_INNER_TD_6223_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_6223_cmds_part;
    cfg_JOIN_INNER_TD_6223_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_6223_gqe_join_part (cfg_JOIN_INNER_TD_6223_cmds_part.cmd);
    cfg_JOIN_INNER_TD_6223_cmds_part.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7594_cmds;
    cfg_JOIN_INNER_TD_7594_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7594_gqe_join (cfg_JOIN_INNER_TD_7594_cmds.cmd);
    cfg_JOIN_INNER_TD_7594_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_INNER_TD_7594_cmds_part;
    cfg_JOIN_INNER_TD_7594_cmds_part.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_7594_gqe_join_part (cfg_JOIN_INNER_TD_7594_cmds_part.cmd);
    cfg_JOIN_INNER_TD_7594_cmds_part.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_4775_part_left;
    krnl_JOIN_INNER_TD_4775_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_4775_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_SerializeFromObject_TD_5327_input, tbl_SerializeFromObject_TD_5327_input_partition, cfg_JOIN_INNER_TD_4775_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_4775[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_4775[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_4775[i].setup(tbl_SerializeFromObject_TD_5327_input_partition_array[i], tbl_JOIN_INNER_TD_5663_output_partition_array[i], tbl_JOIN_INNER_TD_4775_output_partition_array[i], cfg_JOIN_INNER_TD_4775_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_INNER_TD_5663_part_right;
    krnl_JOIN_INNER_TD_5663_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_5663_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_SerializeFromObject_TD_676_input, tbl_SerializeFromObject_TD_676_input_partition, cfg_JOIN_INNER_TD_5663_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_5663[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_5663[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_5663[i].setup(tbl_JOIN_INNER_TD_6223_output_partition_array[i], tbl_SerializeFromObject_TD_676_input_partition_array[i], tbl_JOIN_INNER_TD_5663_output_partition_array[i], cfg_JOIN_INNER_TD_5663_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_INNER_TD_6223_part_left;
    krnl_JOIN_INNER_TD_6223_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_6223_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_Filter_TD_5439_output, tbl_Filter_TD_5439_output_partition, cfg_JOIN_INNER_TD_6223_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_6223[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_6223[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_6223[i].setup(tbl_Filter_TD_5439_output_partition_array[i], tbl_JOIN_INNER_TD_7594_output_partition_array[i], tbl_JOIN_INNER_TD_6223_output_partition_array[i], cfg_JOIN_INNER_TD_6223_cmds, buftmp_h);
    }
    krnlEngine krnl_JOIN_INNER_TD_7594_part_left;
    krnl_JOIN_INNER_TD_7594_part_left = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_7594_part_left.setup_hp(512, 0, power_of_hpTimes_join, tbl_SerializeFromObject_TD_8488_input, tbl_SerializeFromObject_TD_8488_input_partition, cfg_JOIN_INNER_TD_7594_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_7594_part_right;
    krnl_JOIN_INNER_TD_7594_part_right = krnlEngine(program_h, q_h, "gqePart");
    krnl_JOIN_INNER_TD_7594_part_right.setup_hp(512, 1, power_of_hpTimes_join, tbl_Filter_TD_8218_output, tbl_Filter_TD_8218_output_partition, cfg_JOIN_INNER_TD_7594_cmds_part);
    krnlEngine krnl_JOIN_INNER_TD_7594[hpTimes_join];
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_7594[i] = krnlEngine(program_h, q_h, "gqeJoin");
    }
    for (int i = 0; i < hpTimes_join; i++) {
        krnl_JOIN_INNER_TD_7594[i].setup(tbl_SerializeFromObject_TD_8488_input_partition_array[i], tbl_Filter_TD_8218_output_partition_array[i], tbl_JOIN_INNER_TD_7594_output_partition_array[i], cfg_JOIN_INNER_TD_7594_cmds, buftmp_h);
    }
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_4775;
    trans_JOIN_INNER_TD_4775.setq(q_h);
    trans_JOIN_INNER_TD_4775.add(&(cfg_JOIN_INNER_TD_4775_cmds));
    trans_JOIN_INNER_TD_4775.add(&(tbl_SerializeFromObject_TD_5327_input));
    transEngine trans_JOIN_INNER_TD_4775_out;
    trans_JOIN_INNER_TD_4775_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_5663;
    trans_JOIN_INNER_TD_5663.setq(q_h);
    trans_JOIN_INNER_TD_5663.add(&(cfg_JOIN_INNER_TD_5663_cmds));
    trans_JOIN_INNER_TD_5663.add(&(tbl_SerializeFromObject_TD_676_input));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_6223;
    trans_JOIN_INNER_TD_6223.setq(q_h);
    trans_JOIN_INNER_TD_6223.add(&(cfg_JOIN_INNER_TD_6223_cmds_part));
    trans_JOIN_INNER_TD_6223.add(&(cfg_JOIN_INNER_TD_6223_cmds));
    q_h.finish();
    transEngine trans_JOIN_INNER_TD_7594;
    trans_JOIN_INNER_TD_7594.setq(q_h);
    trans_JOIN_INNER_TD_7594.add(&(cfg_JOIN_INNER_TD_7594_cmds_part));
    trans_JOIN_INNER_TD_7594.add(&(cfg_JOIN_INNER_TD_7594_cmds));
    trans_JOIN_INNER_TD_7594.add(&(tbl_SerializeFromObject_TD_8488_input));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_4775;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_4775;
    std::vector<cl::Event> events_JOIN_INNER_TD_4775[2];
    events_h2d_wr_JOIN_INNER_TD_4775.resize(1);
    events_d2h_rd_JOIN_INNER_TD_4775.resize(1);
    events_JOIN_INNER_TD_4775[0].resize(1);
    events_JOIN_INNER_TD_4775[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_4775;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_4775;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_5663;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_5663;
    std::vector<cl::Event> events_JOIN_INNER_TD_5663[2];
    events_h2d_wr_JOIN_INNER_TD_5663.resize(1);
    events_d2h_rd_JOIN_INNER_TD_5663.resize(1);
    events_JOIN_INNER_TD_5663[0].resize(1);
    events_JOIN_INNER_TD_5663[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_5663;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_5663;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_6223;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_6223;
    std::vector<cl::Event> events_JOIN_INNER_TD_6223[2];
    events_h2d_wr_JOIN_INNER_TD_6223.resize(1);
    events_d2h_rd_JOIN_INNER_TD_6223.resize(1);
    events_JOIN_INNER_TD_6223[0].resize(1);
    events_JOIN_INNER_TD_6223[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_6223;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_6223;
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_7594;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_7594;
    std::vector<cl::Event> events_JOIN_INNER_TD_7594[2];
    events_h2d_wr_JOIN_INNER_TD_7594.resize(1);
    events_d2h_rd_JOIN_INNER_TD_7594.resize(1);
    events_JOIN_INNER_TD_7594[0].resize(2);
    events_JOIN_INNER_TD_7594[1].resize(hpTimes_join);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_7594;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_7594;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_8_879_s, tv_r_Filter_8_879_e;
    gettimeofday(&tv_r_Filter_8_879_s, 0);
    SW_Filter_TD_8218(tbl_SerializeFromObject_TD_9838_input, tbl_Filter_TD_8218_output);
    gettimeofday(&tv_r_Filter_8_879_e, 0);

    struct timeval tv_r_Filter_5_370_s, tv_r_Filter_5_370_e;
    gettimeofday(&tv_r_Filter_5_370_s, 0);
    SW_Filter_TD_5439(tbl_SerializeFromObject_TD_6553_input, tbl_Filter_TD_5439_output);
    gettimeofday(&tv_r_Filter_5_370_e, 0);

    struct timeval tv_r_JOIN_INNER_7_127_s, tv_r_JOIN_INNER_7_127_e;
    gettimeofday(&tv_r_JOIN_INNER_7_127_s, 0);
    trans_JOIN_INNER_TD_7594.add(&(tbl_Filter_TD_8218_output));
    trans_JOIN_INNER_TD_7594.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_7594), &(events_h2d_wr_JOIN_INNER_TD_7594[0]));
    events_grp_JOIN_INNER_TD_7594.push_back(events_h2d_wr_JOIN_INNER_TD_7594[0]);
    krnl_JOIN_INNER_TD_7594_part_left.run(0, &(events_grp_JOIN_INNER_TD_7594), &(events_JOIN_INNER_TD_7594[0][0]));
    krnl_JOIN_INNER_TD_7594_part_right.run(0, &(events_grp_JOIN_INNER_TD_7594), &(events_JOIN_INNER_TD_7594[0][1]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_7594[i].run(0, &(events_JOIN_INNER_TD_7594[0]), &(events_JOIN_INNER_TD_7594[1][i]));
    }
    gettimeofday(&tv_r_JOIN_INNER_7_127_e, 0);

    struct timeval tv_r_JOIN_INNER_6_143_s, tv_r_JOIN_INNER_6_143_e;
    gettimeofday(&tv_r_JOIN_INNER_6_143_s, 0);
    prev_events_grp_JOIN_INNER_TD_6223.push_back(events_h2d_wr_JOIN_INNER_TD_7594[0]);
    trans_JOIN_INNER_TD_6223.add(&(tbl_Filter_TD_5439_output));
    trans_JOIN_INNER_TD_6223.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_6223), &(events_h2d_wr_JOIN_INNER_TD_6223[0]));
    events_grp_JOIN_INNER_TD_6223.push_back(events_h2d_wr_JOIN_INNER_TD_6223[0]);
    events_grp_JOIN_INNER_TD_6223.insert(std::end(events_grp_JOIN_INNER_TD_6223), std::begin(events_JOIN_INNER_TD_7594[0]), std::end(events_JOIN_INNER_TD_7594[0]));
    events_grp_JOIN_INNER_TD_6223.insert(std::end(events_grp_JOIN_INNER_TD_6223), std::begin(events_JOIN_INNER_TD_7594[1]), std::end(events_JOIN_INNER_TD_7594[1]));
    krnl_JOIN_INNER_TD_6223_part_left.run(0, &(events_grp_JOIN_INNER_TD_6223), &(events_JOIN_INNER_TD_6223[0][0]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_6223[i].run(0, &(events_JOIN_INNER_TD_6223[0]), &(events_JOIN_INNER_TD_6223[1][i]));
    }
    gettimeofday(&tv_r_JOIN_INNER_6_143_e, 0);

    struct timeval tv_r_JOIN_INNER_5_241_s, tv_r_JOIN_INNER_5_241_e;
    gettimeofday(&tv_r_JOIN_INNER_5_241_s, 0);
    prev_events_grp_JOIN_INNER_TD_5663.push_back(events_h2d_wr_JOIN_INNER_TD_6223[0]);
    trans_JOIN_INNER_TD_5663.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_5663), &(events_h2d_wr_JOIN_INNER_TD_5663[0]));
    events_grp_JOIN_INNER_TD_5663.push_back(events_h2d_wr_JOIN_INNER_TD_5663[0]);
    events_grp_JOIN_INNER_TD_5663.insert(std::end(events_grp_JOIN_INNER_TD_5663), std::begin(events_JOIN_INNER_TD_6223[0]), std::end(events_JOIN_INNER_TD_6223[0]));
    events_grp_JOIN_INNER_TD_5663.insert(std::end(events_grp_JOIN_INNER_TD_5663), std::begin(events_JOIN_INNER_TD_6223[1]), std::end(events_JOIN_INNER_TD_6223[1]));
    krnl_JOIN_INNER_TD_5663_part_right.run(0, &(events_grp_JOIN_INNER_TD_5663), &(events_JOIN_INNER_TD_5663[0][0]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_5663[i].run(0, &(events_grp_JOIN_INNER_TD_5663), &(events_JOIN_INNER_TD_5663[1][i]));
    }
    gettimeofday(&tv_r_JOIN_INNER_5_241_e, 0);

    struct timeval tv_r_Filter_4_907_s, tv_r_Filter_4_907_e;
    gettimeofday(&tv_r_Filter_4_907_s, 0);
    SW_Filter_TD_4241(tbl_SerializeFromObject_TD_5601_input, tbl_Filter_TD_4241_output);
    gettimeofday(&tv_r_Filter_4_907_e, 0);

    struct timeval tv_r_JOIN_INNER_4_706_s, tv_r_JOIN_INNER_4_706_e;
    gettimeofday(&tv_r_JOIN_INNER_4_706_s, 0);
    prev_events_grp_JOIN_INNER_TD_4775.push_back(events_h2d_wr_JOIN_INNER_TD_5663[0]);
    trans_JOIN_INNER_TD_4775.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_4775), &(events_h2d_wr_JOIN_INNER_TD_4775[0]));
    events_grp_JOIN_INNER_TD_4775.push_back(events_h2d_wr_JOIN_INNER_TD_4775[0]);
    events_grp_JOIN_INNER_TD_4775.insert(std::end(events_grp_JOIN_INNER_TD_4775), std::begin(events_JOIN_INNER_TD_5663[0]), std::end(events_JOIN_INNER_TD_5663[0]));
    events_grp_JOIN_INNER_TD_4775.insert(std::end(events_grp_JOIN_INNER_TD_4775), std::begin(events_JOIN_INNER_TD_5663[1]), std::end(events_JOIN_INNER_TD_5663[1]));
    krnl_JOIN_INNER_TD_4775_part_left.run(0, &(events_grp_JOIN_INNER_TD_4775), &(events_JOIN_INNER_TD_4775[0][0]));
    for (int i(0); i < hpTimes_join; ++i) {
        krnl_JOIN_INNER_TD_4775[i].run(0, &(events_JOIN_INNER_TD_4775[0]), &(events_JOIN_INNER_TD_4775[1][i]));
    }
    
    for (int i(0); i < hpTimes_join; ++i) {
        trans_JOIN_INNER_TD_4775_out.add(&(tbl_JOIN_INNER_TD_4775_output_partition_array[i]));
    }
    trans_JOIN_INNER_TD_4775_out.dev2host(0, &(events_JOIN_INNER_TD_4775[1]), &(events_d2h_rd_JOIN_INNER_TD_4775[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_4_706_e, 0);

    struct timeval tv_r_JOIN_INNER_3_160_s, tv_r_JOIN_INNER_3_160_e;
    gettimeofday(&tv_r_JOIN_INNER_3_160_s, 0);
    SW_JOIN_INNER_TD_3444(tbl_JOIN_INNER_TD_4775_output_partition_array, tbl_Filter_TD_4241_output, tbl_SerializeFromObject_TD_6553_input, tbl_JOIN_INNER_TD_3444_output, hpTimes_join);
    gettimeofday(&tv_r_JOIN_INNER_3_160_e, 0);

    struct timeval tv_r_Project_2_559_s, tv_r_Project_2_559_e;
    gettimeofday(&tv_r_Project_2_559_s, 0);
    SW_Project_TD_2670(tbl_JOIN_INNER_TD_3444_output, tbl_Project_TD_2670_output);
    gettimeofday(&tv_r_Project_2_559_e, 0);

    struct timeval tv_r_Aggregate_1_462_s, tv_r_Aggregate_1_462_e;
    gettimeofday(&tv_r_Aggregate_1_462_s, 0);
    SW_Aggregate_TD_143(tbl_Project_TD_2670_output, tbl_Aggregate_TD_143_output);
    gettimeofday(&tv_r_Aggregate_1_462_e, 0);

    struct timeval tv_r_Sort_0_740_s, tv_r_Sort_0_740_e;
    gettimeofday(&tv_r_Sort_0_740_s, 0);
    SW_Sort_TD_0792(tbl_Aggregate_TD_143_output, tbl_Sort_TD_0792_output);
    gettimeofday(&tv_r_Sort_0_740_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_879_s, &tv_r_Filter_8_879_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9838_input: " << tbl_SerializeFromObject_TD_9838_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_370_s, &tv_r_Filter_5_370_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6553_input: " << tbl_SerializeFromObject_TD_6553_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_127_s, &tv_r_JOIN_INNER_7_127_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8488_input: " << tbl_SerializeFromObject_TD_8488_input.getNumRow() << " " << "tbl_Filter_TD_8218_output: " << tbl_Filter_TD_8218_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_143_s, &tv_r_JOIN_INNER_6_143_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7594_output: " << tbl_JOIN_INNER_TD_7594_output.getNumRow() << " " << "tbl_Filter_TD_5439_output: " << tbl_Filter_TD_5439_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_241_s, &tv_r_JOIN_INNER_5_241_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6223_output: " << tbl_JOIN_INNER_TD_6223_output.getNumRow() << " " << "tbl_SerializeFromObject_TD_676_input: " << tbl_SerializeFromObject_TD_676_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_4: " << tvdiff(&tv_r_Filter_4_907_s, &tv_r_Filter_4_907_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_5601_input: " << tbl_SerializeFromObject_TD_5601_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_706_s, &tv_r_JOIN_INNER_4_706_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5663_output: " << tbl_JOIN_INNER_TD_5663_output.getNumRow() << " " << "tbl_SerializeFromObject_TD_5327_input: " << tbl_SerializeFromObject_TD_5327_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_3: " << tvdiff(&tv_r_JOIN_INNER_3_160_s, &tv_r_JOIN_INNER_3_160_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4775_output: " << tbl_JOIN_INNER_TD_4775_output.getNumRow() << " " << "tbl_Filter_TD_4241_output: " << tbl_Filter_TD_4241_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_2: " << tvdiff(&tv_r_Project_2_559_s, &tv_r_Project_2_559_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_3444_output: " << tbl_JOIN_INNER_TD_3444_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_1: " << tvdiff(&tv_r_Aggregate_1_462_s, &tv_r_Aggregate_1_462_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_2670_output: " << tbl_Project_TD_2670_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_0: " << tvdiff(&tv_r_Sort_0_740_s, &tv_r_Sort_0_740_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_143_output: " << tbl_Aggregate_TD_143_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 888.51135 * 1000 << "ms" << std::endl; 
    return 0; 
}
