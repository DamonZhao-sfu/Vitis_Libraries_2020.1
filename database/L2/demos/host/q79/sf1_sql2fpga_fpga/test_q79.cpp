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

#include "cfgFunc_q79.hpp" 
#include "q79.hpp" 

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
    std::cout << "NOTE:running query #79\n."; 
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
    Table tbl_GlobalLimit_TD_0429094_output("tbl_GlobalLimit_TD_0429094_output", 6100000, 6, "");
    tbl_GlobalLimit_TD_0429094_output.allocateHost();
    Table tbl_LocalLimit_TD_1569601_output("tbl_LocalLimit_TD_1569601_output", 6100000, 6, "");
    tbl_LocalLimit_TD_1569601_output.allocateHost();
    Table tbl_Sort_TD_2609056_output("tbl_Sort_TD_2609056_output", 6100000, 6, "");
    tbl_Sort_TD_2609056_output.allocateHost();
    Table tbl_Project_TD_3222343_output("tbl_Project_TD_3222343_output", 6100000, 6, "");
    tbl_Project_TD_3222343_output.allocateHost();
    Table tbl_JOIN_INNER_TD_4274840_output("tbl_JOIN_INNER_TD_4274840_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_4274840_output.allocateHost();
    Table tbl_Aggregate_TD_5506717_output("tbl_Aggregate_TD_5506717_output", 6100000, 5, "");
    tbl_Aggregate_TD_5506717_output.allocateHost();
    Table tbl_Filter_TD_5980825_output("tbl_Filter_TD_5980825_output", 6100000, 3, "");
    tbl_Filter_TD_5980825_output.allocateHost();
    Table tbl_JOIN_INNER_TD_6528034_output("tbl_JOIN_INNER_TD_6528034_output", 6100000, 6, "");
    tbl_JOIN_INNER_TD_6528034_output.allocateHost();
    Table tbl_SerializeFromObject_TD_6679178_input;
    tbl_SerializeFromObject_TD_6679178_input = Table("customer", customer_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_6679178_input.addCol("c_customer_sk", 4);
    tbl_SerializeFromObject_TD_6679178_input.addCol("c_first_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6679178_input.addCol("c_last_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_6679178_input.allocateHost();
    tbl_SerializeFromObject_TD_6679178_input.loadHost();
    Table tbl_JOIN_INNER_TD_7738791_output("tbl_JOIN_INNER_TD_7738791_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_7738791_output.allocateHost();
    Table tbl_Filter_TD_7202907_output("tbl_Filter_TD_7202907_output", 6100000, 1, "");
    tbl_Filter_TD_7202907_output.allocateHost();
    Table tbl_JOIN_INNER_TD_8391419_output("tbl_JOIN_INNER_TD_8391419_output", 6100000, 7, "");
    tbl_JOIN_INNER_TD_8391419_output.allocateHost();
    Table tbl_Filter_TD_8889660_output("tbl_Filter_TD_8889660_output", 6100000, 2, "");
    tbl_Filter_TD_8889660_output.allocateHost();
    Table tbl_SerializeFromObject_TD_8891195_input;
    tbl_SerializeFromObject_TD_8891195_input = Table("household_demographics", household_demographics_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_8891195_input.addCol("hd_demo_sk", 4);
    tbl_SerializeFromObject_TD_8891195_input.addCol("hd_dep_count", 4);
    tbl_SerializeFromObject_TD_8891195_input.addCol("hd_vehicle_count", 4);
    tbl_SerializeFromObject_TD_8891195_input.allocateHost();
    tbl_SerializeFromObject_TD_8891195_input.loadHost();
    Table tbl_Filter_TD_978927_output("tbl_Filter_TD_978927_output", 6100000, 8, "");
    tbl_Filter_TD_978927_output.allocateHost();
    Table tbl_Filter_TD_9830144_output("tbl_Filter_TD_9830144_output", 6100000, 1, "");
    tbl_Filter_TD_9830144_output.allocateHost();
    Table tbl_SerializeFromObject_TD_9353951_input;
    tbl_SerializeFromObject_TD_9353951_input = Table("store", store_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_9353951_input.addCol("s_store_sk", 4);
    tbl_SerializeFromObject_TD_9353951_input.addCol("s_city", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_9353951_input.addCol("s_number_employees", 4);
    tbl_SerializeFromObject_TD_9353951_input.allocateHost();
    tbl_SerializeFromObject_TD_9353951_input.loadHost();
    Table tbl_SerializeFromObject_TD_10845328_input;
    tbl_SerializeFromObject_TD_10845328_input = Table("store_sales", store_sales_n, 8, in_dir, "orc");
    tbl_SerializeFromObject_TD_10845328_input.addCol("ss_sold_date_sk", 4);
    tbl_SerializeFromObject_TD_10845328_input.addCol("ss_customer_sk", 4);
    tbl_SerializeFromObject_TD_10845328_input.addCol("ss_hdemo_sk", 4);
    tbl_SerializeFromObject_TD_10845328_input.addCol("ss_addr_sk", 4);
    tbl_SerializeFromObject_TD_10845328_input.addCol("ss_store_sk", 4);
    tbl_SerializeFromObject_TD_10845328_input.addCol("ss_ticket_number", 8);
    tbl_SerializeFromObject_TD_10845328_input.addCol("ss_coupon_amt", 4);
    tbl_SerializeFromObject_TD_10845328_input.addCol("ss_net_profit", 4);
    tbl_SerializeFromObject_TD_10845328_input.allocateHost();
    tbl_SerializeFromObject_TD_10845328_input.loadHost();
    Table tbl_SerializeFromObject_TD_10127397_input;
    tbl_SerializeFromObject_TD_10127397_input = Table("date_dim", date_dim_n, 3, in_dir, "orc");
    tbl_SerializeFromObject_TD_10127397_input.addCol("d_date_sk", 4);
    tbl_SerializeFromObject_TD_10127397_input.addCol("d_dow", 4);
    tbl_SerializeFromObject_TD_10127397_input.addCol("d_year", 4);
    tbl_SerializeFromObject_TD_10127397_input.allocateHost();
    tbl_SerializeFromObject_TD_10127397_input.loadHost();
    // ********************** Allocate Device Buffer ******************** // 
    tbl_JOIN_INNER_TD_8391419_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_978927_output.allocateDevBuffer(context_h, 32);
    tbl_Filter_TD_9830144_output.allocateDevBuffer(context_h, 32);
    // ****************************** Config **************************** // 
    cfgCmd cfg_JOIN_INNER_TD_8391419_cmds;
    cfg_JOIN_INNER_TD_8391419_cmds.allocateHost();
    get_cfg_dat_JOIN_INNER_TD_8391419_gqe_join (cfg_JOIN_INNER_TD_8391419_cmds.cmd);
    cfg_JOIN_INNER_TD_8391419_cmds.allocateDevBuffer(context_h, 32);
    // *************************** Kernel Setup ************************* // 
    bufferTmp buftmp_h(context_h); 
    buftmp_h.initBuffer(q_h); 
    std::cout << std::endl; 
    krnlEngine krnl_JOIN_INNER_TD_8391419;
    krnl_JOIN_INNER_TD_8391419 = krnlEngine(program_h, q_h, "gqeJoin");
    krnl_JOIN_INNER_TD_8391419.setup(tbl_Filter_TD_978927_output, tbl_Filter_TD_9830144_output, tbl_JOIN_INNER_TD_8391419_output, cfg_JOIN_INNER_TD_8391419_cmds, buftmp_h);
    // ************************** Transfer Engine *********************** // 
    transEngine trans_JOIN_INNER_TD_8391419;
    trans_JOIN_INNER_TD_8391419.setq(q_h);
    trans_JOIN_INNER_TD_8391419.add(&(cfg_JOIN_INNER_TD_8391419_cmds));
    transEngine trans_JOIN_INNER_TD_8391419_out;
    trans_JOIN_INNER_TD_8391419_out.setq(q_h);
    q_h.finish();
    // ****************************** Events **************************** // 
    std::vector<cl::Event> events_h2d_wr_JOIN_INNER_TD_8391419;
    std::vector<cl::Event> events_d2h_rd_JOIN_INNER_TD_8391419;
    std::vector<cl::Event> events_JOIN_INNER_TD_8391419;
    events_h2d_wr_JOIN_INNER_TD_8391419.resize(1);
    events_d2h_rd_JOIN_INNER_TD_8391419.resize(1);
    events_JOIN_INNER_TD_8391419.resize(1);
    std::vector<cl::Event> events_grp_JOIN_INNER_TD_8391419;
    std::vector<cl::Event> prev_events_grp_JOIN_INNER_TD_8391419;
    // **************************** Operations ************************** // 
    struct timeval tv_r_s, tv_r_e; 
    gettimeofday(&tv_r_s, 0); 

    struct timeval tv_r_Filter_9_161267_s, tv_r_Filter_9_161267_e;
    gettimeofday(&tv_r_Filter_9_161267_s, 0);
    SW_Filter_TD_9830144(tbl_SerializeFromObject_TD_10127397_input, tbl_Filter_TD_9830144_output);
    gettimeofday(&tv_r_Filter_9_161267_e, 0);

    struct timeval tv_r_Filter_9_922556_s, tv_r_Filter_9_922556_e;
    gettimeofday(&tv_r_Filter_9_922556_s, 0);
    SW_Filter_TD_978927(tbl_SerializeFromObject_TD_10845328_input, tbl_Filter_TD_978927_output);
    gettimeofday(&tv_r_Filter_9_922556_e, 0);

    struct timeval tv_r_Filter_8_91388_s, tv_r_Filter_8_91388_e;
    gettimeofday(&tv_r_Filter_8_91388_s, 0);
    SW_Filter_TD_8889660(tbl_SerializeFromObject_TD_9353951_input, tbl_Filter_TD_8889660_output);
    gettimeofday(&tv_r_Filter_8_91388_e, 0);

    struct timeval tv_r_JOIN_INNER_8_982978_s, tv_r_JOIN_INNER_8_982978_e;
    gettimeofday(&tv_r_JOIN_INNER_8_982978_s, 0);
    trans_JOIN_INNER_TD_8391419.add(&(tbl_Filter_TD_978927_output));
    trans_JOIN_INNER_TD_8391419.add(&(tbl_Filter_TD_9830144_output));
    trans_JOIN_INNER_TD_8391419.host2dev(0, &(prev_events_grp_JOIN_INNER_TD_8391419), &(events_h2d_wr_JOIN_INNER_TD_8391419[0]));
    events_grp_JOIN_INNER_TD_8391419.push_back(events_h2d_wr_JOIN_INNER_TD_8391419[0]);
    krnl_JOIN_INNER_TD_8391419.run(0, &(events_grp_JOIN_INNER_TD_8391419), &(events_JOIN_INNER_TD_8391419[0]));
    
    trans_JOIN_INNER_TD_8391419_out.add(&(tbl_JOIN_INNER_TD_8391419_output));
    trans_JOIN_INNER_TD_8391419_out.dev2host(0, &(events_JOIN_INNER_TD_8391419), &(events_d2h_rd_JOIN_INNER_TD_8391419[0]));
    q_h.flush();
    q_h.finish();
    gettimeofday(&tv_r_JOIN_INNER_8_982978_e, 0);

    struct timeval tv_r_Filter_7_115931_s, tv_r_Filter_7_115931_e;
    gettimeofday(&tv_r_Filter_7_115931_s, 0);
    SW_Filter_TD_7202907(tbl_SerializeFromObject_TD_8891195_input, tbl_Filter_TD_7202907_output);
    gettimeofday(&tv_r_Filter_7_115931_e, 0);

    struct timeval tv_r_JOIN_INNER_7_687939_s, tv_r_JOIN_INNER_7_687939_e;
    gettimeofday(&tv_r_JOIN_INNER_7_687939_s, 0);
    SW_JOIN_INNER_TD_7738791(tbl_JOIN_INNER_TD_8391419_output, tbl_Filter_TD_8889660_output, tbl_JOIN_INNER_TD_7738791_output);
    gettimeofday(&tv_r_JOIN_INNER_7_687939_e, 0);

    struct timeval tv_r_JOIN_INNER_6_816624_s, tv_r_JOIN_INNER_6_816624_e;
    gettimeofday(&tv_r_JOIN_INNER_6_816624_s, 0);
    SW_JOIN_INNER_TD_6528034(tbl_JOIN_INNER_TD_7738791_output, tbl_Filter_TD_7202907_output, tbl_JOIN_INNER_TD_6528034_output);
    gettimeofday(&tv_r_JOIN_INNER_6_816624_e, 0);

    struct timeval tv_r_Filter_5_870983_s, tv_r_Filter_5_870983_e;
    gettimeofday(&tv_r_Filter_5_870983_s, 0);
    SW_Filter_TD_5980825(tbl_SerializeFromObject_TD_6679178_input, tbl_Filter_TD_5980825_output);
    gettimeofday(&tv_r_Filter_5_870983_e, 0);

    struct timeval tv_r_Aggregate_5_609070_s, tv_r_Aggregate_5_609070_e;
    gettimeofday(&tv_r_Aggregate_5_609070_s, 0);
    SW_Aggregate_TD_5506717(tbl_JOIN_INNER_TD_6528034_output, tbl_Aggregate_TD_5506717_output);
    gettimeofday(&tv_r_Aggregate_5_609070_e, 0);

    struct timeval tv_r_JOIN_INNER_4_873538_s, tv_r_JOIN_INNER_4_873538_e;
    gettimeofday(&tv_r_JOIN_INNER_4_873538_s, 0);
    SW_JOIN_INNER_TD_4274840(tbl_Aggregate_TD_5506717_output, tbl_Filter_TD_5980825_output, tbl_JOIN_INNER_TD_4274840_output);
    gettimeofday(&tv_r_JOIN_INNER_4_873538_e, 0);

    struct timeval tv_r_Project_3_115094_s, tv_r_Project_3_115094_e;
    gettimeofday(&tv_r_Project_3_115094_s, 0);
    SW_Project_TD_3222343(tbl_JOIN_INNER_TD_4274840_output, tbl_Project_TD_3222343_output);
    gettimeofday(&tv_r_Project_3_115094_e, 0);

    struct timeval tv_r_Sort_2_128708_s, tv_r_Sort_2_128708_e;
    gettimeofday(&tv_r_Sort_2_128708_s, 0);
    SW_Sort_TD_2609056(tbl_Project_TD_3222343_output, tbl_Sort_TD_2609056_output);
    gettimeofday(&tv_r_Sort_2_128708_e, 0);

    struct timeval tv_r_LocalLimit_1_612025_s, tv_r_LocalLimit_1_612025_e;
    gettimeofday(&tv_r_LocalLimit_1_612025_s, 0);
    SW_LocalLimit_TD_1569601(tbl_Sort_TD_2609056_output, tbl_LocalLimit_TD_1569601_output);
    gettimeofday(&tv_r_LocalLimit_1_612025_e, 0);

    struct timeval tv_r_GlobalLimit_0_689552_s, tv_r_GlobalLimit_0_689552_e;
    gettimeofday(&tv_r_GlobalLimit_0_689552_s, 0);
    SW_GlobalLimit_TD_0429094(tbl_LocalLimit_TD_1569601_output, tbl_GlobalLimit_TD_0429094_output);
    gettimeofday(&tv_r_GlobalLimit_0_689552_e, 0);

    gettimeofday(&tv_r_e, 0); 
    // **************************** Print Execution Time ************************** // 
    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_161267_s, &tv_r_Filter_9_161267_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10127397_input: " << tbl_SerializeFromObject_TD_10127397_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_9: " << tvdiff(&tv_r_Filter_9_922556_s, &tv_r_Filter_9_922556_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_10845328_input: " << tbl_SerializeFromObject_TD_10845328_input.getNumRow() << " " << std::endl; 

    std::cout << "Filter_8: " << tvdiff(&tv_r_Filter_8_91388_s, &tv_r_Filter_8_91388_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_9353951_input: " << tbl_SerializeFromObject_TD_9353951_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_8: " << tvdiff(&tv_r_JOIN_INNER_8_982978_s, &tv_r_JOIN_INNER_8_982978_e) / 1000.0 << " ms " 
     << "tbl_Filter_TD_978927_output: " << tbl_Filter_TD_978927_output.getNumRow() << " " << "tbl_Filter_TD_9830144_output: " << tbl_Filter_TD_9830144_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_7: " << tvdiff(&tv_r_Filter_7_115931_s, &tv_r_Filter_7_115931_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_8891195_input: " << tbl_SerializeFromObject_TD_8891195_input.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_7: " << tvdiff(&tv_r_JOIN_INNER_7_687939_s, &tv_r_JOIN_INNER_7_687939_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_8391419_output: " << tbl_JOIN_INNER_TD_8391419_output.getNumRow() << " " << "tbl_Filter_TD_8889660_output: " << tbl_Filter_TD_8889660_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_6: " << tvdiff(&tv_r_JOIN_INNER_6_816624_s, &tv_r_JOIN_INNER_6_816624_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_7738791_output: " << tbl_JOIN_INNER_TD_7738791_output.getNumRow() << " " << "tbl_Filter_TD_7202907_output: " << tbl_Filter_TD_7202907_output.getNumRow() << " " << std::endl; 

    std::cout << "Filter_5: " << tvdiff(&tv_r_Filter_5_870983_s, &tv_r_Filter_5_870983_e) / 1000.0 << " ms " 
     << "tbl_SerializeFromObject_TD_6679178_input: " << tbl_SerializeFromObject_TD_6679178_input.getNumRow() << " " << std::endl; 

    std::cout << "Aggregate_5: " << tvdiff(&tv_r_Aggregate_5_609070_s, &tv_r_Aggregate_5_609070_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_6528034_output: " << tbl_JOIN_INNER_TD_6528034_output.getNumRow() << " " << std::endl; 

    std::cout << "JOIN_INNER_4: " << tvdiff(&tv_r_JOIN_INNER_4_873538_s, &tv_r_JOIN_INNER_4_873538_e) / 1000.0 << " ms " 
     << "tbl_Aggregate_TD_5506717_output: " << tbl_Aggregate_TD_5506717_output.getNumRow() << " " << "tbl_Filter_TD_5980825_output: " << tbl_Filter_TD_5980825_output.getNumRow() << " " << std::endl; 

    std::cout << "Project_3: " << tvdiff(&tv_r_Project_3_115094_s, &tv_r_Project_3_115094_e) / 1000.0 << " ms " 
     << "tbl_JOIN_INNER_TD_4274840_output: " << tbl_JOIN_INNER_TD_4274840_output.getNumRow() << " " << std::endl; 

    std::cout << "Sort_2: " << tvdiff(&tv_r_Sort_2_128708_s, &tv_r_Sort_2_128708_e) / 1000.0 << " ms " 
     << "tbl_Project_TD_3222343_output: " << tbl_Project_TD_3222343_output.getNumRow() << " " << std::endl; 

    std::cout << "LocalLimit_1: " << tvdiff(&tv_r_LocalLimit_1_612025_s, &tv_r_LocalLimit_1_612025_e) / 1000.0 << " ms " 
     << "tbl_Sort_TD_2609056_output: " << tbl_Sort_TD_2609056_output.getNumRow() << " " << std::endl; 

    std::cout << "GlobalLimit_0: " << tvdiff(&tv_r_GlobalLimit_0_689552_s, &tv_r_GlobalLimit_0_689552_e) / 1000.0 << " ms " 
     << "tbl_LocalLimit_TD_1569601_output: " << tbl_LocalLimit_TD_1569601_output.getNumRow() << " " << std::endl; 

    std::cout << std::endl << " Total execution time: " << tvdiff(&tv_r_s, &tv_r_e) / 1000 << " ms"; 

    std::cout << std::endl << " Spark elapsed time: " << 1.9725868 * 1000 << "ms" << std::endl; 
    return 0; 
}
