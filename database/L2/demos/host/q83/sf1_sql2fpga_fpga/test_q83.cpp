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

#include "cfgFunc_q83.hpp" 
#include "q83.hpp" 

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
    std::cout << "NOTE:running query #83\n."; 
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
    Table tbl_GlobalLimit_TD_0354763_output("tbl_GlobalLimit_TD_0354763_output", 6100000, 8, "");
    tbl_GlobalLimit_TD_0354763_output.allocateHost();
    Table tbl_LocalLimit_TD_1548979_output("tbl_LocalLimit_TD_1548979_output", 6100000, 8, "");
    tbl_LocalLimit_TD_1548979_output.allocateHost();
    Table tbl_Sort_TD_2298876_output("tbl_Sort_TD_2298876_output", 6100000, 8, "");
    tbl_Sort_TD_2298876_output.allocateHost();
    Table tbl_Project_TD_3603414_output("tbl_Project_TD_3603414_output", 6100000, 8, "");
    tbl_Project_TD_3603414_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4443009_output("tbl_JOIN_INNER_TD_4443009_output", 6100000, 4, "");
    tbl_JOIN_INNER_TD_4443009_output.allocateHost();
    Table tbl_JOIN_INNER_TD_5855891_output("tbl_JOIN_INNER_TD_5855891_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_5855891_output.allocateHost();
    Table tbl_Aggregate_TD_5140271_output("tbl_Aggregate_TD_5140271_output", 6100000, 2, "");
    tbl_Aggregate_TD_5140271_output.allocateHost();
    Table tbl_Aggregate_TD_622222_output("tbl_Aggregate_TD_622222_output", 6100000, 2, "");
    tbl_Aggregate_TD_622222_output.allocateHost();
    Table tbl_Aggregate_TD_6605838_output("tbl_Aggregate_TD_6605838_output", 6100000, 2, "");
    tbl_Aggregate_TD_6605838_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6944999_output("tbl_JOIN_INNER_TD_6944999_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_6944999_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7607555_output("tbl_JOIN_INNER_TD_7607555_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_7607555_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7528220_output("tbl_JOIN_INNER_TD_7528220_output", 6100000, 2, "");
    tbl_JOIN_INNER_TD_7528220_output.allocateHost();
    Table tbl_JOIN_INNER_TD_7569124_output("tbl_JOIN_INNER_TD_7569124_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_7569124_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_7153185_output("tbl_JOIN_LEFTSEMI_TD_7153185_output", 6100000, 1, "");
    tbl_JOIN_LEFTSEMI_TD_7153185_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8909122_output("tbl_JOIN_INNER_TD_8909122_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_8909122_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_8288015_output("tbl_JOIN_LEFTSEMI_TD_8288015_output", 6100000, 1, "");
    tbl_JOIN_LEFTSEMI_TD_8288015_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8720192_output("tbl_JOIN_INNER_TD_8720192_output", 6100000, 3, "");
    tbl_JOIN_INNER_TD_8720192_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_8973839_output("tbl_JOIN_LEFTSEMI_TD_8973839_output", 6100000, 1, "");
    tbl_JOIN_LEFTSEMI_TD_8973839_output.allocateHost();
    Table tbl_Filter_TD_8146224_output("tbl_Filter_TD_8146224_output", 6100000, 3, "");
    tbl_Filter_TD_8146224_output.allocateHost();
    Table tbl_Filter_TD_8814972_output("tbl_Filter_TD_8814972_output", 6100000, 2, "");
    tbl_Filter_TD_8814972_output.allocateHost();
    Table tbl_Filter_TD_8868428_output("tbl_Filter_TD_8868428_output", 6100000, 2, "");
    tbl_Filter_TD_8868428_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_8468980_output("tbl_JOIN_LEFTSEMI_TD_8468980_output", 6100000, 1, "");
    tbl_JOIN_LEFTSEMI_TD_8468980_output.allocateHost();
    Table tbl_Filter_TD_9942402_output("tbl_Filter_TD_9942402_output", 6100000, 3, "");
    tbl_Filter_TD_9942402_output.allocateHost();
    Table tbl_Filter_TD_9135474_output("tbl_Filter_TD_9135474_output", 6100000, 2, "");
    tbl_Filter_TD_9135474_output.allocateHost();
    Table tbl_Filter_TD_9460043_output("tbl_Filter_TD_9460043_output", 6100000, 2, "");
    tbl_Filter_TD_9460043_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_934800_output("tbl_JOIN_LEFTSEMI_TD_934800_output", 6100000, 1, "");
    tbl_JOIN_LEFTSEMI_TD_934800_output.allocateHost();
    Table tbl_Filter_TD_9359687_output("tbl_Filter_TD_9359687_output", 6100000, 3, "");
    tbl_Filter_TD_9359687_output.allocateHost();
    Table tbl_Filter_TD_9586511_output("tbl_Filter_TD_9586511_output", 6100000, 2, "");
    tbl_Filter_TD_9586511_output.allocateHost();
    Table tbl_Filter_TD_9441387_output("tbl_Filter_TD_9441387_output", 6100000, 2, "");
    tbl_Filter_TD_9441387_output.allocateHost();
    Table tbl_JOIN_LEFTSEMI_TD_9296332_output("tbl_JOIN_LEFTSEMI_TD_9296332_output", 6100000, 1, "");
    tbl_JOIN_LEFTSEMI_TD_9296332_output.allocateHost();
    Table tbl_SerializeFromObject_TD_962194_input;
    tbl_SerializeFromObject_TD_962194_input = Table("web_returns", web_returns_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_962194_input.addCol("wr_returned_date_sk", 4);
    tbl_SerializeFromObject_TD_962194_input.addCol("wr_item_sk", 4);
    tbl_SerializeFromObject_TD_962194_input.addCol("wr_return_quantity", 4);
    tbl_SerializeFromObject_TD_962194_input.allocateHost();
    tbl_SerializeFromObject_TD_962194_input.loadHost();
    Table tbl_SerializeFromObject_TD_9770366_input;
    tbl_SerializeFromObject_TD_9770366_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9770366_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_9770366_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9770366_input.allocateHost();
    tbl_SerializeFromObject_TD_9770366_input.loadHost();
    Table tbl_SerializeFromObject_TD_9432388_input;
    tbl_SerializeFromObject_TD_9432388_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9432388_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_9432388_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_9432388_input.allocateHost();
    tbl_SerializeFromObject_TD_9432388_input.loadHost();
    Table tbl_SerializeFromObject_TD_9245771_input;
    tbl_SerializeFromObject_TD_9245771_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_9245771_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_9245771_input.addCol("d_week_seq", 4);
    tbl_SerializeFromObject_TD_9245771_input.allocateHost();
    tbl_SerializeFromObject_TD_9245771_input.loadHost();
    Table tbl_Filter_TD_9330248_output("tbl_Filter_TD_9330248_output", 6100000, 1, "");
    tbl_Filter_TD_9330248_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10452888_input;
    tbl_SerializeFromObject_TD_10452888_input = Table("store_returns", store_returns_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10452888_input.addCol("sr_returned_date_sk", 4);
    tbl_SerializeFromObject_TD_10452888_input.addCol("sr_item_sk", 4);
    tbl_SerializeFromObject_TD_10452888_input.addCol("sr_return_quantity", 4);
    tbl_SerializeFromObject_TD_10452888_input.allocateHost();
    tbl_SerializeFromObject_TD_10452888_input.loadHost();
    Table tbl_SerializeFromObject_TD_1076967_input;
    tbl_SerializeFromObject_TD_1076967_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_1076967_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_1076967_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_1076967_input.allocateHost();
    tbl_SerializeFromObject_TD_1076967_input.loadHost();
    Table tbl_SerializeFromObject_TD_10103265_input;
    tbl_SerializeFromObject_TD_10103265_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10103265_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10103265_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_10103265_input.allocateHost();
    tbl_SerializeFromObject_TD_10103265_input.loadHost();
    Table tbl_SerializeFromObject_TD_10700909_input;
    tbl_SerializeFromObject_TD_10700909_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10700909_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_10700909_input.addCol("d_week_seq", 4);
    tbl_SerializeFromObject_TD_10700909_input.allocateHost();
    tbl_SerializeFromObject_TD_10700909_input.loadHost();
    Table tbl_Filter_TD_1051056_output("tbl_Filter_TD_1051056_output", 6100000, 1, "");
    tbl_Filter_TD_1051056_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10369223_input;
    tbl_SerializeFromObject_TD_10369223_input = Table("catalog_returns", catalog_returns_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10369223_input.addCol("cr_returned_date_sk", 4);
    tbl_SerializeFromObject_TD_10369223_input.addCol("cr_item_sk", 4);
    tbl_SerializeFromObject_TD_10369223_input.addCol("cr_return_quantity", 4);
    tbl_SerializeFromObject_TD_10369223_input.allocateHost();
    tbl_SerializeFromObject_TD_10369223_input.loadHost();
    Table tbl_SerializeFromObject_TD_10383149_input;
    tbl_SerializeFromObject_TD_10383149_input = Table("item", item_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10383149_input.addCol("i_item_sk", 4);
    tbl_SerializeFromObject_TD_10383149_input.addCol("i_item_id", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10383149_input.allocateHost();
    tbl_SerializeFromObject_TD_10383149_input.loadHost();
    Table tbl_SerializeFromObject_TD_10473374_input;
    tbl_SerializeFromObject_TD_10473374_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10473374_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10473374_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_10473374_input.allocateHost();
    tbl_SerializeFromObject_TD_10473374_input.loadHost();
    Table tbl_SerializeFromObject_TD_10529678_input;
    tbl_SerializeFromObject_TD_10529678_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10529678_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_10529678_input.addCol("d_week_seq", 4);
    tbl_SerializeFromObject_TD_10529678_input.allocateHost();
    tbl_SerializeFromObject_TD_10529678_input.loadHost();
    Table tbl_Filter_TD_10926404_output("tbl_Filter_TD_10926404_output", 6100000, 1, "");
    tbl_Filter_TD_10926404_output.allocateHost();
    Table tbl_SerializeFromObject_TD_10523745_input;
    tbl_SerializeFromObject_TD_10523745_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10523745_input.addCol("d_week_seq", 4);
    tbl_SerializeFromObject_TD_10523745_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_10523745_input.allocateHost();
    tbl_SerializeFromObject_TD_10523745_input.loadHost();
    Table tbl_SerializeFromObject_TD_11516843_input;
    tbl_SerializeFromObject_TD_11516843_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11516843_input.addCol("d_week_seq", 4);
    tbl_SerializeFromObject_TD_11516843_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_11516843_input.allocateHost();
    tbl_SerializeFromObject_TD_11516843_input.loadHost();
    Table tbl_SerializeFromObject_TD_11991779_input;
    tbl_SerializeFromObject_TD_11991779_input = Table("date_dim", date_dim_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_11991779_input.addCol("d_week_seq", 4);
    tbl_SerializeFromObject_TD_11991779_input.addCol("d_date", 4);
    tbl_SerializeFromObject_TD_11991779_input.allocateHost();
    tbl_SerializeFromObject_TD_11991779_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_LEFTSEMI_TD_7153185_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTSEMI_TD_8288015_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTSEMI_TD_8973839_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_8868428_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTSEMI_TD_8468980_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9460043_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTSEMI_TD_934800_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9441387_output.allocateDevBuffer(context_h, 32);
    tbl_JOIN_LEFTSEMI_TD_9296332_output.allocateDevBuffer(context_h, 32);
    tbl_SerializeFromObject_TD_9245771_input.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9330248_output.allocateDevBuffer(context_h, 32);
    tbl_SerializeFromObject_TD_10700909_input.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_1051056_output.allocateDevBuffer(context_h, 32);
    tbl_SerializeFromObject_TD_10529678_input.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_10926404_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_LEFTSEMI_TD_7153185_cmds;
    cfg_JOIN_LEFTSEMI_TD_7153185_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_7153185_gqe_join (cfg_JOIN_LEFTSEMI_TD_7153185_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_7153185_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_8288015_cmds;
    cfg_JOIN_LEFTSEMI_TD_8288015_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_8288015_gqe_join (cfg_JOIN_LEFTSEMI_TD_8288015_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_8288015_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_8973839_cmds;
    cfg_JOIN_LEFTSEMI_TD_8973839_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_8973839_gqe_join (cfg_JOIN_LEFTSEMI_TD_8973839_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_8973839_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_8468980_cmds;
    cfg_JOIN_LEFTSEMI_TD_8468980_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_8468980_gqe_join (cfg_JOIN_LEFTSEMI_TD_8468980_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_8468980_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_934800_cmds;
    cfg_JOIN_LEFTSEMI_TD_934800_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_934800_gqe_join (cfg_JOIN_LEFTSEMI_TD_934800_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_934800_cmds.allocateDevBuffer(context_h, 32);
    cfgCmd cfg_JOIN_LEFTSEMI_TD_9296332_cmds;
    cfg_JOIN_LEFTSEMI_TD_9296332_cmds.allocateHost();
    get_cfg_dat_JOIN_LEFTSEMI_TD_9296332_gqe_join (cfg_JOIN_LEFTSEMI_TD_9296332_cmds.cmd);
    cfg_JOIN_LEFTSEMI_TD_9296332_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_LEFTSEMI_TD_7153185;
    krnl_JOIN_LEFTSEMI_TD_7153185 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTSEMI_TD_7153185.setup(tbl_JOIN_LEFTSEMI_TD_8468980_output, tbl_Filter_TD_8868428_output, tbl_JOIN_LEFTSEMI_TD_7153185_output, cfg_JOIN_LEFTSEMI_TD_7153185_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_8288015;
    krnl_JOIN_LEFTSEMI_TD_8288015 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTSEMI_TD_8288015.setup(tbl_JOIN_LEFTSEMI_TD_934800_output, tbl_Filter_TD_9460043_output, tbl_JOIN_LEFTSEMI_TD_8288015_output, cfg_JOIN_LEFTSEMI_TD_8288015_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_8973839;
    krnl_JOIN_LEFTSEMI_TD_8973839 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTSEMI_TD_8973839.setup(tbl_JOIN_LEFTSEMI_TD_9296332_output, tbl_Filter_TD_9441387_output, tbl_JOIN_LEFTSEMI_TD_8973839_output, cfg_JOIN_LEFTSEMI_TD_8973839_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_8468980;
    krnl_JOIN_LEFTSEMI_TD_8468980 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTSEMI_TD_8468980.setup(tbl_Filter_TD_9330248_output, tbl_SerializeFromObject_TD_9245771_input, tbl_JOIN_LEFTSEMI_TD_8468980_output, cfg_JOIN_LEFTSEMI_TD_8468980_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_934800;
    krnl_JOIN_LEFTSEMI_TD_934800 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTSEMI_TD_934800.setup(tbl_Filter_TD_1051056_output, tbl_SerializeFromObject_TD_10700909_input, tbl_JOIN_LEFTSEMI_TD_934800_output, cfg_JOIN_LEFTSEMI_TD_934800_cmds, buftmp_h);
    krnlEngine krnl_JOIN_LEFTSEMI_TD_9296332;
    krnl_JOIN_LEFTSEMI_TD_9296332 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_LEFTSEMI_TD_9296332.setup(tbl_Filter_TD_10926404_output, tbl_SerializeFromObject_TD_10529678_input, tbl_JOIN_LEFTSEMI_TD_9296332_output, cfg_JOIN_LEFTSEMI_TD_9296332_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_LEFTSEMI_TD_7153185;
    trans_JOIN_LEFTSEMI_TD_7153185.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_7153185.add(&(cfg_JOIN_LEFTSEMI_TD_7153185_cmds));
    transEngine trans_JOIN_LEFTSEMI_TD_7153185_out;
    trans_JOIN_LEFTSEMI_TD_7153185_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_LEFTSEMI_TD_8288015;
    trans_JOIN_LEFTSEMI_TD_8288015.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_8288015.add(&(cfg_JOIN_LEFTSEMI_TD_8288015_cmds));
    transEngine trans_JOIN_LEFTSEMI_TD_8288015_out;
    trans_JOIN_LEFTSEMI_TD_8288015_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_LEFTSEMI_TD_8973839;
    trans_JOIN_LEFTSEMI_TD_8973839.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_8973839.add(&(cfg_JOIN_LEFTSEMI_TD_8973839_cmds));
    transEngine trans_JOIN_LEFTSEMI_TD_8973839_out;
    trans_JOIN_LEFTSEMI_TD_8973839_out.setq(q_h);
    q_h.finish();
    transEngine trans_JOIN_LEFTSEMI_TD_8468980;
    trans_JOIN_LEFTSEMI_TD_8468980.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_8468980.add(&(cfg_JOIN_LEFTSEMI_TD_8468980_cmds));
    trans_JOIN_LEFTSEMI_TD_8468980.add(&(tbl_SerializeFromObject_TD_9245771_input));
    q_h.finish();
    transEngine trans_JOIN_LEFTSEMI_TD_934800;
    trans_JOIN_LEFTSEMI_TD_934800.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_934800.add(&(cfg_JOIN_LEFTSEMI_TD_934800_cmds));
    trans_JOIN_LEFTSEMI_TD_934800.add(&(tbl_SerializeFromObject_TD_10700909_input));
    q_h.finish();
    transEngine trans_JOIN_LEFTSEMI_TD_9296332;
    trans_JOIN_LEFTSEMI_TD_9296332.setq(q_h);
    trans_JOIN_LEFTSEMI_TD_9296332.add(&(cfg_JOIN_LEFTSEMI_TD_9296332_cmds));
    trans_JOIN_LEFTSEMI_TD_9296332.add(&(tbl_SerializeFromObject_TD_10529678_input));
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_7153185;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_7153185;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_7153185;
    events_h2d_wr_JOIN_LEFTSEMI_TD_7153185.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_7153185.resize(1);
    events_JOIN_LEFTSEMI_TD_7153185.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_7153185;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_7153185;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_8288015;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_8288015;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_8288015;
    events_h2d_wr_JOIN_LEFTSEMI_TD_8288015.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_8288015.resize(1);
    events_JOIN_LEFTSEMI_TD_8288015.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_8288015;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_8288015;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_8973839;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_8973839;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_8973839;
    events_h2d_wr_JOIN_LEFTSEMI_TD_8973839.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_8973839.resize(1);
    events_JOIN_LEFTSEMI_TD_8973839.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_8973839;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_8973839;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_8468980;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_8468980;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_8468980;
    events_h2d_wr_JOIN_LEFTSEMI_TD_8468980.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_8468980.resize(1);
    events_JOIN_LEFTSEMI_TD_8468980.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_8468980;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_8468980;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_934800;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_934800;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_934800;
    events_h2d_wr_JOIN_LEFTSEMI_TD_934800.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_934800.resize(1);
    events_JOIN_LEFTSEMI_TD_934800.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_934800;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_934800;
    std::vector<cl::Event> events_h2d_wr_JOIN_LEFTSEMI_TD_9296332;
    std::vector<cl::Event> events_d2h_rd_JOIN_LEFTSEMI_TD_9296332;
    std::vector<cl::Event> events_JOIN_LEFTSEMI_TD_9296332;
    events_h2d_wr_JOIN_LEFTSEMI_TD_9296332.resize(1);
    events_d2h_rd_JOIN_LEFTSEMI_TD_9296332.resize(1);
    events_JOIN_LEFTSEMI_TD_9296332.resize(1);
    std::vector<cl::Event> events_grp_JOIN_LEFTSEMI_TD_9296332;
    std::vector<cl::Event> prev_events_grp_JOIN_LEFTSEMI_TD_9296332;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_10_190977_s, tv_r_Filter_10_190977_e;
    gettimeofday(&tv_r_Filter_10_190977_s, 0);
    SW_Filter_TD_10926404(tbl_SerializeFromObject_TD_11991779_input, tbl_Filter_TD_10926404_output);
    gettimeofday(&tv_r_Filter_10_190977_e, 0);

    struct timeval tv_r_Filter_10_719460_s, tv_r_Filter_10_719460_e;
    gettimeofday(&tv_r_Filter_10_719460_s, 0);
    SW_Filter_TD_1051056(tbl_SerializeFromObject_TD_11516843_input, tbl_Filter_TD_1051056_output);
    gettimeofday(&tv_r_Filter_10_719460_e, 0);

    struct timeval tv_r_Filter_9_879914_s, tv_r_Filter_9_879914_e;
    gettimeofday(&tv_r_Filter_9_879914_s, 0);
    SW_Filter_TD_9330248(tbl_SerializeFromObject_TD_10523745_input, tbl_Filter_TD_9330248_output);
    gettimeofday(&tv_r_Filter_9_879914_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_9_147493_s, tv_r_JOIN_LEFTSEMI_9_147493_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_9_147493_s, 0);
    trans_JOIN_LEFTSEMI_TD_9296332.add(&(tbl_Filter_TD_10926404_output));
    trans_JOIN_LEFTSEMI_TD_9296332.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_9296332), &(events_h2d_wr_JOIN_LEFTSEMI_TD_9296332[0]));
    events_grp_JOIN_LEFTSEMI_TD_9296332.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_9296332[0]);
    krnl_JOIN_LEFTSEMI_TD_9296332.run(0, &(events_grp_JOIN_LEFTSEMI_TD_9296332), &(events_JOIN_LEFTSEMI_TD_9296332[0]));
    gettimeofday(&tv_r_JOIN_LEFTSEMI_9_147493_e, 0);

    struct timeval tv_r_Filter_9_167537_s, tv_r_Filter_9_167537_e;
    gettimeofday(&tv_r_Filter_9_167537_s, 0);
    SW_Filter_TD_9441387(tbl_SerializeFromObject_TD_10473374_input, tbl_Filter_TD_9441387_output);
    gettimeofday(&tv_r_Filter_9_167537_e, 0);

    struct timeval tv_r_Filter_9_78126_s, tv_r_Filter_9_78126_e;
    gettimeofday(&tv_r_Filter_9_78126_s, 0);
    SW_Filter_TD_9586511(tbl_SerializeFromObject_TD_10383149_input, tbl_Filter_TD_9586511_output);
    gettimeofday(&tv_r_Filter_9_78126_e, 0);

    struct timeval tv_r_Filter_9_426130_s, tv_r_Filter_9_426130_e;
    gettimeofday(&tv_r_Filter_9_426130_s, 0);
    SW_Filter_TD_9359687(tbl_SerializeFromObject_TD_10369223_input, tbl_Filter_TD_9359687_output);
    gettimeofday(&tv_r_Filter_9_426130_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_9_253529_s, tv_r_JOIN_LEFTSEMI_9_253529_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_9_253529_s, 0);
    trans_JOIN_LEFTSEMI_TD_934800.add(&(tbl_Filter_TD_1051056_output));
    trans_JOIN_LEFTSEMI_TD_934800.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_934800), &(events_h2d_wr_JOIN_LEFTSEMI_TD_934800[0]));
    events_grp_JOIN_LEFTSEMI_TD_934800.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_934800[0]);
    krnl_JOIN_LEFTSEMI_TD_934800.run(0, &(events_grp_JOIN_LEFTSEMI_TD_934800), &(events_JOIN_LEFTSEMI_TD_934800[0]));
    gettimeofday(&tv_r_JOIN_LEFTSEMI_9_253529_e, 0);

    struct timeval tv_r_Filter_9_270810_s, tv_r_Filter_9_270810_e;
    gettimeofday(&tv_r_Filter_9_270810_s, 0);
    SW_Filter_TD_9460043(tbl_SerializeFromObject_TD_10103265_input, tbl_Filter_TD_9460043_output);
    gettimeofday(&tv_r_Filter_9_270810_e, 0);

    struct timeval tv_r_Filter_9_834863_s, tv_r_Filter_9_834863_e;
    gettimeofday(&tv_r_Filter_9_834863_s, 0);
    SW_Filter_TD_9135474(tbl_SerializeFromObject_TD_1076967_input, tbl_Filter_TD_9135474_output);
    gettimeofday(&tv_r_Filter_9_834863_e, 0);

    struct timeval tv_r_Filter_9_880731_s, tv_r_Filter_9_880731_e;
    gettimeofday(&tv_r_Filter_9_880731_s, 0);
    SW_Filter_TD_9942402(tbl_SerializeFromObject_TD_10452888_input, tbl_Filter_TD_9942402_output);
    gettimeofday(&tv_r_Filter_9_880731_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_8_744074_s, tv_r_JOIN_LEFTSEMI_8_744074_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_8_744074_s, 0);
    trans_JOIN_LEFTSEMI_TD_8468980.add(&(tbl_Filter_TD_9330248_output));
    trans_JOIN_LEFTSEMI_TD_8468980.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_8468980), &(events_h2d_wr_JOIN_LEFTSEMI_TD_8468980[0]));
    events_grp_JOIN_LEFTSEMI_TD_8468980.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_8468980[0]);
    krnl_JOIN_LEFTSEMI_TD_8468980.run(0, &(events_grp_JOIN_LEFTSEMI_TD_8468980), &(events_JOIN_LEFTSEMI_TD_8468980[0]));
    gettimeofday(&tv_r_JOIN_LEFTSEMI_8_744074_e, 0);

    struct timeval tv_r_Filter_8_793102_s, tv_r_Filter_8_793102_e;
    gettimeofday(&tv_r_Filter_8_793102_s, 0);
    SW_Filter_TD_8868428(tbl_SerializeFromObject_TD_9432388_input, tbl_Filter_TD_8868428_output);
    gettimeofday(&tv_r_Filter_8_793102_e, 0);

    struct timeval tv_r_Filter_8_866035_s, tv_r_Filter_8_866035_e;
    gettimeofday(&tv_r_Filter_8_866035_s, 0);
    SW_Filter_TD_8814972(tbl_SerializeFromObject_TD_9770366_input, tbl_Filter_TD_8814972_output);
    gettimeofday(&tv_r_Filter_8_866035_e, 0);

    struct timeval tv_r_Filter_8_9067_s, tv_r_Filter_8_9067_e;
    gettimeofday(&tv_r_Filter_8_9067_s, 0);
    SW_Filter_TD_8146224(tbl_SerializeFromObject_TD_962194_input, tbl_Filter_TD_8146224_output);
    gettimeofday(&tv_r_Filter_8_9067_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_8_928696_s, tv_r_JOIN_LEFTSEMI_8_928696_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_8_928696_s, 0);
    prev_events_grp_JOIN_LEFTSEMI_TD_8973839.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_9296332[0]);
    trans_JOIN_LEFTSEMI_TD_8973839.add(&(tbl_Filter_TD_9441387_output));
    trans_JOIN_LEFTSEMI_TD_8973839.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_8973839), &(events_h2d_wr_JOIN_LEFTSEMI_TD_8973839[0]));
    events_grp_JOIN_LEFTSEMI_TD_8973839.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_8973839[0]);
    events_grp_JOIN_LEFTSEMI_TD_8973839.push_back(events_JOIN_LEFTSEMI_TD_9296332[0]);
    krnl_JOIN_LEFTSEMI_TD_8973839.run(0, &(events_grp_JOIN_LEFTSEMI_TD_8973839), &(events_JOIN_LEFTSEMI_TD_8973839[0]));
    
    trans_JOIN_LEFTSEMI_TD_8973839_out.add(&(tbl_JOIN_LEFTSEMI_TD_8973839_output));
    trans_JOIN_LEFTSEMI_TD_8973839_out.dev2host(0, &(events_JOIN_LEFTSEMI_TD_8973839), &(events_d2h_rd_JOIN_LEFTSEMI_TD_8973839[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_LEFTSEMI_8_928696_e, 0);

    struct timeval tv_r_JOIN_INNER_8_711194_s, tv_r_JOIN_INNER_8_711194_e;
    gettimeofday(&tv_r_JOIN_INNER_8_711194_s, 0);
    SW_JOIN_INNER_TD_8720192(tbl_Filter_TD_9359687_output, tbl_Filter_TD_9586511_output, tbl_JOIN_INNER_TD_8720192_output);
    gettimeofday(&tv_r_JOIN_INNER_8_711194_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_8_265550_s, tv_r_JOIN_LEFTSEMI_8_265550_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_8_265550_s, 0);
    prev_events_grp_JOIN_LEFTSEMI_TD_8288015.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_934800[0]);
    trans_JOIN_LEFTSEMI_TD_8288015.add(&(tbl_Filter_TD_9460043_output));
    trans_JOIN_LEFTSEMI_TD_8288015.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_8288015), &(events_h2d_wr_JOIN_LEFTSEMI_TD_8288015[0]));
    events_grp_JOIN_LEFTSEMI_TD_8288015.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_8288015[0]);
    events_grp_JOIN_LEFTSEMI_TD_8288015.push_back(events_JOIN_LEFTSEMI_TD_934800[0]);
    krnl_JOIN_LEFTSEMI_TD_8288015.run(0, &(events_grp_JOIN_LEFTSEMI_TD_8288015), &(events_JOIN_LEFTSEMI_TD_8288015[0]));
    
    trans_JOIN_LEFTSEMI_TD_8288015_out.add(&(tbl_JOIN_LEFTSEMI_TD_8288015_output));
    trans_JOIN_LEFTSEMI_TD_8288015_out.dev2host(0, &(events_JOIN_LEFTSEMI_TD_8288015), &(events_d2h_rd_JOIN_LEFTSEMI_TD_8288015[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_LEFTSEMI_8_265550_e, 0);

    struct timeval tv_r_JOIN_INNER_8_34314_s, tv_r_JOIN_INNER_8_34314_e;
    gettimeofday(&tv_r_JOIN_INNER_8_34314_s, 0);
    SW_JOIN_INNER_TD_8909122(tbl_Filter_TD_9942402_output, tbl_Filter_TD_9135474_output, tbl_JOIN_INNER_TD_8909122_output);
    gettimeofday(&tv_r_JOIN_INNER_8_34314_e, 0);

    struct timeval tv_r_JOIN_LEFTSEMI_7_873634_s, tv_r_JOIN_LEFTSEMI_7_873634_e;
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_873634_s, 0);
    prev_events_grp_JOIN_LEFTSEMI_TD_7153185.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_8468980[0]);
    trans_JOIN_LEFTSEMI_TD_7153185.add(&(tbl_Filter_TD_8868428_output));
    trans_JOIN_LEFTSEMI_TD_7153185.host2dev(0, &(prev_events_grp_JOIN_LEFTSEMI_TD_7153185), &(events_h2d_wr_JOIN_LEFTSEMI_TD_7153185[0]));
    events_grp_JOIN_LEFTSEMI_TD_7153185.push_back(events_h2d_wr_JOIN_LEFTSEMI_TD_7153185[0]);
    events_grp_JOIN_LEFTSEMI_TD_7153185.push_back(events_JOIN_LEFTSEMI_TD_8468980[0]);
    krnl_JOIN_LEFTSEMI_TD_7153185.run(0, &(events_grp_JOIN_LEFTSEMI_TD_7153185), &(events_JOIN_LEFTSEMI_TD_7153185[0]));
    
    trans_JOIN_LEFTSEMI_TD_7153185_out.add(&(tbl_JOIN_LEFTSEMI_TD_7153185_output));
    trans_JOIN_LEFTSEMI_TD_7153185_out.dev2host(0, &(events_JOIN_LEFTSEMI_TD_7153185), &(events_d2h_rd_JOIN_LEFTSEMI_TD_7153185[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_LEFTSEMI_7_873634_e, 0);

    struct timeval tv_r_JOIN_INNER_7_746048_s, tv_r_JOIN_INNER_7_746048_e;
    gettimeofday(&tv_r_JOIN_INNER_7_746048_s, 0);
    SW_JOIN_INNER_TD_7569124(tbl_Filter_TD_8146224_output, tbl_Filter_TD_8814972_output, tbl_JOIN_INNER_TD_7569124_output);
    gettimeofday(&tv_r_JOIN_INNER_7_746048_e, 0);

    struct timeval tv_r_JOIN_INNER_7_631504_s, tv_r_JOIN_INNER_7_631504_e;
    gettimeofday(&tv_r_JOIN_INNER_7_631504_s, 0);
    SW_JOIN_INNER_TD_7528220(tbl_JOIN_INNER_TD_8720192_output, tbl_JOIN_LEFTSEMI_TD_8973839_output, tbl_JOIN_INNER_TD_7528220_output);
    gettimeofday(&tv_r_JOIN_INNER_7_631504_e, 0);

    struct timeval tv_r_JOIN_INNER_7_855921_s, tv_r_JOIN_INNER_7_855921_e;
    gettimeofday(&tv_r_JOIN_INNER_7_855921_s, 0);
    SW_JOIN_INNER_TD_7607555(tbl_JOIN_INNER_TD_8909122_output, tbl_JOIN_LEFTSEMI_TD_8288015_output, tbl_JOIN_INNER_TD_7607555_output);
    gettimeofday(&tv_r_JOIN_INNER_7_855921_e, 0);

    struct timeval tv_r_JOIN_INNER_6_794118_s, tv_r_JOIN_INNER_6_794118_e;
    gettimeofday(&tv_r_JOIN_INNER_6_794118_s, 0);
    SW_JOIN_INNER_TD_6944999(tbl_JOIN_INNER_TD_7569124_output, tbl_JOIN_LEFTSEMI_TD_7153185_output, tbl_JOIN_INNER_TD_6944999_output);
    gettimeofday(&tv_r_JOIN_INNER_6_794118_e, 0);

    struct timeval tv_r_Aggregate_6_868492_s, tv_r_Aggregate_6_868492_e;
    gettimeofday(&tv_r_Aggregate_6_868492_s, 0);
    SW_Aggregate_TD_6605838(tbl_JOIN_INNER_TD_7528220_output, tbl_Aggregate_TD_6605838_output);
    gettimeofday(&tv_r_Aggregate_6_868492_e, 0);

    struct timeval tv_r_Aggregate_6_246614_s, tv_r_Aggregate_6_246614_e;
    gettimeofday(&tv_r_Aggregate_6_246614_s, 0);
    SW_Aggregate_TD_622222(tbl_JOIN_INNER_TD_7607555_output, tbl_Aggregate_TD_622222_output);
    gettimeofday(&tv_r_Aggregate_6_246614_e, 0);

    struct timeval tv_r_Aggregate_5_939562_s, tv_r_Aggregate_5_939562_e;
    gettimeofday(&tv_r_Aggregate_5_939562_s, 0);
    SW_Aggregate_TD_5140271(tbl_JOIN_INNER_TD_6944999_output, tbl_Aggregate_TD_5140271_output);
    gettimeofday(&tv_r_Aggregate_5_939562_e, 0);

    struct timeval tv_r_JOIN_INNER_5_1028_s, tv_r_JOIN_INNER_5_1028_e;
    gettimeofday(&tv_r_JOIN_INNER_5_1028_s, 0);
    SW_JOIN_INNER_TD_5855891(tbl_Aggregate_TD_622222_output, tbl_Aggregate_TD_6605838_output, tbl_JOIN_INNER_TD_5855891_output);
    gettimeofday(&tv_r_JOIN_INNER_5_1028_e, 0);

    struct timeval tv_r_JOIN_INNER_4_843925_s, tv_r_JOIN_INNER_4_843925_e;
    gettimeofday(&tv_r_JOIN_INNER_4_843925_s, 0);
    SW_JOIN_INNER_TD_4443009(tbl_JOIN_INNER_TD_5855891_output, tbl_Aggregate_TD_5140271_output, tbl_JOIN_INNER_TD_4443009_output);
    gettimeofday(&tv_r_JOIN_INNER_4_843925_e, 0);

    struct timeval tv_r_Project_3_983997_s, tv_r_Project_3_983997_e;
    gettimeofday(&tv_r_Project_3_983997_s, 0);
    SW_Project_TD_3603414(tbl_JOIN_INNER_TD_4443009_output, tbl_Project_TD_3603414_output);
    gettimeofday(&tv_r_Project_3_983997_e, 0);

    struct timeval tv_r_Sort_2_733347_s, tv_r_Sort_2_733347_e;
    gettimeofday(&tv_r_Sort_2_733347_s, 0);
    SW_Sort_TD_2298876(tbl_Project_TD_3603414_output, tbl_Sort_TD_2298876_output);
    gettimeofday(&tv_r_Sort_2_733347_e, 0);

    struct timeval tv_r_LocalLimit_1_974497_s, tv_r_LocalLimit_1_974497_e;
    gettimeofday(&tv_r_LocalLimit_1_974497_s, 0);
    SW_LocalLimit_TD_1548979(tbl_Sort_TD_2298876_output, tbl_LocalLimit_TD_1548979_output);
    gettimeofday(&tv_r_LocalLimit_1_974497_e, 0);

    struct timeval tv_r_GlobalLimit_0_829330_s, tv_r_GlobalLimit_0_829330_e;
    gettimeofday(&tv_r_GlobalLimit_0_829330_s, 0);
    SW_GlobalLimit_TD_0354763(tbl_LocalLimit_TD_1548979_output, tbl_GlobalLimit_TD_0354763_output);
    gettimeofday(&tv_r_GlobalLimit_0_829330_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_190977_s, &tv_r_Filter_10_190977_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11991779_input: " << tbl_SerializeFromObject_TD_11991779_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_10: " << tvdiff(&tv_r_Filter_10_719460_s, &tv_r_Filter_10_719460_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_11516843_input: " << tbl_SerializeFromObject_TD_11516843_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_879914_s, &tv_r_Filter_9_879914_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10523745_input: " << tbl_SerializeFromObject_TD_10523745_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_9: " << tvdiff(&tv_r_JOIN_LEFTSEMI_9_147493_s, &tv_r_JOIN_LEFTSEMI_9_147493_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10529678_input: " << tbl_SerializeFromObject_TD_10529678_input.getNumRow() << " " << "tbl_Filter_TD_10926404_output: " << tbl_Filter_TD_10926404_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_167537_s, &tv_r_Filter_9_167537_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10473374_input: " << tbl_SerializeFromObject_TD_10473374_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_78126_s, &tv_r_Filter_9_78126_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10383149_input: " << tbl_SerializeFromObject_TD_10383149_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_426130_s, &tv_r_Filter_9_426130_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10369223_input: " << tbl_SerializeFromObject_TD_10369223_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_9: " << tvdiff(&tv_r_JOIN_LEFTSEMI_9_253529_s, &tv_r_JOIN_LEFTSEMI_9_253529_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10700909_input: " << tbl_SerializeFromObject_TD_10700909_input.getNumRow() << " " << "tbl_Filter_TD_1051056_output: " << tbl_Filter_TD_1051056_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_270810_s, &tv_r_Filter_9_270810_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10103265_input: " << tbl_SerializeFromObject_TD_10103265_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_834863_s, &tv_r_Filter_9_834863_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_1076967_input: " << tbl_SerializeFromObject_TD_1076967_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_880731_s, &tv_r_Filter_9_880731_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10452888_input: " << tbl_SerializeFromObject_TD_10452888_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_8: " << tvdiff(&tv_r_JOIN_LEFTSEMI_8_744074_s, &tv_r_JOIN_LEFTSEMI_8_744074_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9245771_input: " << tbl_SerializeFromObject_TD_9245771_input.getNumRow() << " " << "tbl_Filter_TD_9330248_output: " << tbl_Filter_TD_9330248_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_793102_s, &tv_r_Filter_8_793102_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9432388_input: " << tbl_SerializeFromObject_TD_9432388_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_866035_s, &tv_r_Filter_8_866035_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9770366_input: " << tbl_SerializeFromObject_TD_9770366_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_9067_s, &tv_r_Filter_8_9067_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_962194_input: " << tbl_SerializeFromObject_TD_962194_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_8: " << tvdiff(&tv_r_JOIN_LEFTSEMI_8_928696_s, &tv_r_JOIN_LEFTSEMI_8_928696_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9441387_output: " << tbl_Filter_TD_9441387_output.getNumRow() << " " << "tbl_JOIN_LEFTSEMI_TD_9296332_output: " << tbl_JOIN_LEFTSEMI_TD_9296332_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_711194_s, &tv_r_JOIN_INNER_8_711194_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9359687_output: " << tbl_Filter_TD_9359687_output.getNumRow() << " " << "tbl_Filter_TD_9586511_output: " << tbl_Filter_TD_9586511_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_8: " << tvdiff(&tv_r_JOIN_LEFTSEMI_8_265550_s, &tv_r_JOIN_LEFTSEMI_8_265550_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9460043_output: " << tbl_Filter_TD_9460043_output.getNumRow() << " " << "tbl_JOIN_LEFTSEMI_TD_934800_output: " << tbl_JOIN_LEFTSEMI_TD_934800_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_34314_s, &tv_r_JOIN_INNER_8_34314_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_9942402_output: " << tbl_Filter_TD_9942402_output.getNumRow() << " " << "tbl_Filter_TD_9135474_output: " << tbl_Filter_TD_9135474_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_LEFTSEMI_7: " << tvdiff(&tv_r_JOIN_LEFTSEMI_7_873634_s, &tv_r_JOIN_LEFTSEMI_7_873634_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8868428_output: " << tbl_Filter_TD_8868428_output.getNumRow() << " " << "tbl_JOIN_LEFTSEMI_TD_8468980_output: " << tbl_JOIN_LEFTSEMI_TD_8468980_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_746048_s, &tv_r_JOIN_INNER_7_746048_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_8146224_output: " << tbl_Filter_TD_8146224_output.getNumRow() << " " << "tbl_Filter_TD_8814972_output: " << tbl_Filter_TD_8814972_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_631504_s, &tv_r_JOIN_INNER_7_631504_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8720192_output: " << tbl_JOIN_INNER_TD_8720192_output.getNumRow() << " " << "tbl_JOIN_LEFTSEMI_TD_8973839_output: " << tbl_JOIN_LEFTSEMI_TD_8973839_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_855921_s, &tv_r_JOIN_INNER_7_855921_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8909122_output: " << tbl_JOIN_INNER_TD_8909122_output.getNumRow() << " " << "tbl_JOIN_LEFTSEMI_TD_8288015_output: " << tbl_JOIN_LEFTSEMI_TD_8288015_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_794118_s, &tv_r_JOIN_INNER_6_794118_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7569124_output: " << tbl_JOIN_INNER_TD_7569124_output.getNumRow() << " " << "tbl_JOIN_LEFTSEMI_TD_7153185_output: " << tbl_JOIN_LEFTSEMI_TD_7153185_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_6: " << tvdiff(&tv_r_Aggregate_6_868492_s, &tv_r_Aggregate_6_868492_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7528220_output: " << tbl_JOIN_INNER_TD_7528220_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_6: " << tvdiff(&tv_r_Aggregate_6_246614_s, &tv_r_Aggregate_6_246614_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7607555_output: " << tbl_JOIN_INNER_TD_7607555_output.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_939562_s, &tv_r_Aggregate_5_939562_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6944999_output: " << tbl_JOIN_INNER_TD_6944999_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_5: " << tvdiff(&tv_r_JOIN_INNER_5_1028_s, &tv_r_JOIN_INNER_5_1028_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_622222_output: " << tbl_Aggregate_TD_622222_output.getNumRow() << " " << "tbl_Aggregate_TD_6605838_output: " << tbl_Aggregate_TD_6605838_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_843925_s, &tv_r_JOIN_INNER_4_843925_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_5855891_output: " << tbl_JOIN_INNER_TD_5855891_output.getNumRow() << " " << "tbl_Aggregate_TD_5140271_output: " << tbl_Aggregate_TD_5140271_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_3: " << tvdiff(&tv_r_Project_3_983997_s, &tv_r_Project_3_983997_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4443009_output: " << tbl_JOIN_INNER_TD_4443009_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_733347_s, &tv_r_Sort_2_733347_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_3603414_output: " << tbl_Project_TD_3603414_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_974497_s, &tv_r_LocalLimit_1_974497_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2298876_output: " << tbl_Sort_TD_2298876_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_829330_s, &tv_r_GlobalLimit_0_829330_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1548979_output: " << tbl_LocalLimit_TD_1548979_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 5.615429 * 1000 << "ms" << std::endl; 
    return 0; 
}
