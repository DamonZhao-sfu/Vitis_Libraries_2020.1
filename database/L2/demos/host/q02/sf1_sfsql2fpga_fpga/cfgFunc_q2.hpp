#include "ap_int.h" 
#include "xf_database/dynamic_alu_host.hpp"
#include "xf_database/enums.hpp"
#include <fstream> 
 
static void gen_pass_fcfg(uint32_t cfg[]) { 
    using namespace xf::database; 
    int n = 0; 
 
    // cond_1 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = 0UL | (FOP_DC << FilterOpWidth) | (FOP_DC); 
    // cond_2 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = 0UL | (FOP_DC << FilterOpWidth) | (FOP_DC); 
    // cond_3 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = 0UL | (FOP_DC << FilterOpWidth) | (FOP_DC); 
    // cond_4 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = 0UL | (FOP_DC << FilterOpWidth) | (FOP_DC); 
 
    uint32_t r = 0; 
    int sh = 0; 
    // cond_1 -- cond_2 
    r |= ((uint32_t)(FOP_DC << sh)); 
    sh += FilterOpWidth; 
    // cond_1 -- cond_3 
    r |= ((uint32_t)(FOP_DC << sh)); 
    sh += FilterOpWidth; 
    // cond_1 -- cond_4 
    r |= ((uint32_t)(FOP_DC << sh)); 
    sh += FilterOpWidth; 
 
    // cond_2 -- cond_3 
    r |= ((uint32_t)(FOP_DC << sh)); 
    sh += FilterOpWidth; 
    // cond_2 -- cond_4 
    r |= ((uint32_t)(FOP_DC << sh)); 
    sh += FilterOpWidth; 
 
    // cond_3 -- cond_4 
    r |= ((uint32_t)(FOP_DC << sh)); 
    sh += FilterOpWidth; 
 
    cfg[n++] = r; 
 
    // 4 true and 6 true 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)0UL; 
    cfg[n++] = (uint32_t)(1UL << 31); 
} 

void get_cfg_dat_JOIN_INNER_TD_9373_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((s_suppkey#368 = ps_suppkey#330))
    // Left Table: ListBuffer(ps_partkey#329, ps_suppkey#330, ps_supplycost#332)
    // Right Table: ListBuffer(s_suppkey#368, s_nationkey#371)
    // Output Table: ListBuffer(ps_partkey#329, ps_supplycost#332, s_nationkey#371)
    // Node Depth: 9
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,2,-1,-1,-1,-1,-1};
    for (int c = 0; c < 8; ++c) {
        t.range(56 + 8 * c + 7, 56 + 8 * c) = id_a[c];
    }
    // filter tbl_a config
    uint32_t cfga[45];
    gen_pass_fcfg(cfga);
    memcpy(&b[3], cfga, sizeof(uint32_t) * 45);

    // input table b
    signed char id_b[] = {0,1,-1,-1,-1,-1,-1,-1};
    for (int c = 0; c < 8; ++c) {
        t.range(120 + 8 * c + 7, 120 + 8 * c) = id_b[c];
    }
    // filter tbl_b config
    uint32_t cfgb[45];
    gen_pass_fcfg(cfgb);
    memcpy(&b[6], cfgb, sizeof(uint32_t) * 45);

    //--------------join--------------
    //stream shuffle 1a
    ap_int<64> shuffle1a_cfg;
    shuffle1a_cfg(7, 0) = 1;
    shuffle1a_cfg(15, 8) = 0;
    shuffle1a_cfg(23, 16) = 2;
    shuffle1a_cfg(31, 24) = -1;
    shuffle1a_cfg(39, 32) = -1;
    shuffle1a_cfg(47, 40) = -1;
    shuffle1a_cfg(55, 48) = -1;
    shuffle1a_cfg(63, 56) = -1;

    //stream shuffle 1b
    ap_int<64> shuffle1b_cfg;
    shuffle1b_cfg(7, 0) = 0;
    shuffle1b_cfg(15, 8) = 1;
    shuffle1b_cfg(23, 16) = -1;
    shuffle1b_cfg(31, 24) = -1;
    shuffle1b_cfg(39, 32) = -1;
    shuffle1b_cfg(47, 40) = -1;
    shuffle1b_cfg(55, 48) = -1;
    shuffle1b_cfg(63, 56) = -1;

    // join config
    t.set_bit(0, 1);    // join
    t.set_bit(2, 0);    // dual-key
    t.range(5, 3) = 0;  // hash join flag = 0 for normal, 1 for semi, 2 for anti

    //--------------eval0--------------
    //stream shuffle 2
    ap_int<64> shuffle2_cfg;
    shuffle2_cfg(7, 0) = 6; // ps_partkey
    shuffle2_cfg(15, 8) = 7; // ps_supplycost
    shuffle2_cfg(23, 16) = 0; // s_nationkey
    shuffle2_cfg(31, 24) = -1;
    shuffle2_cfg(39, 32) = -1;
    shuffle2_cfg(47, 40) = -1;
    shuffle2_cfg(55, 48) = -1;
    shuffle2_cfg(63, 56) = -1;

    ap_uint<289> op_eval_0 = 0; // NOP
    // eval0: NOP
    b[1] = op_eval_0;

    //--------------eval1--------------
    //stream shuffle 3
    ap_int<64> shuffle3_cfg;
    shuffle3_cfg(7, 0) = 0; // ps_partkey
    shuffle3_cfg(15, 8) = 1; // ps_supplycost
    shuffle3_cfg(23, 16) = 2; // s_nationkey
    shuffle3_cfg(31, 24) = -1;
    shuffle3_cfg(39, 32) = -1;
    shuffle3_cfg(47, 40) = -1;
    shuffle3_cfg(55, 48) = -1;
    shuffle3_cfg(63, 56) = -1;

    ap_uint<289> op_eval_1 = 0; // NOP
    // eval1: NOP
    b[2] = op_eval_1;

    //--------------aggregate--------------
    //stream shuffle 4
    ap_int<64> shuffle4_cfg;
    shuffle4_cfg(7, 0) = 0; // ps_partkey
    shuffle4_cfg(15, 8) = 1; // ps_supplycost
    shuffle4_cfg(23, 16) = 2; // s_nationkey
    shuffle4_cfg(31, 24) = -1;
    shuffle4_cfg(39, 32) = -1;
    shuffle4_cfg(47, 40) = -1;
    shuffle4_cfg(55, 48) = -1;
    shuffle4_cfg(63, 56) = -1;

    t.set_bit(1, 0); // aggr flag

    //--------------writeout--------------
    // output table col
    t.range(191, 184) = {1*1 + 2*1 + 4*1 + 8*0 + 16*0 + 32*0 + 64*0 + 128*0};
    b[0] = t;

    //stream shuffle assignment
    b[0].range(255, 192) = shuffle1a_cfg;
    b[0].range(319, 256) = shuffle1b_cfg;
    b[0].range(383, 320) = shuffle2_cfg;
    b[0].range(447, 384) = shuffle3_cfg;
    b[0].range(511, 448) = shuffle4_cfg;
}

void get_cfg_dat_JOIN_INNER_TD_8484_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((s_nationkey#371 = n_nationkey#164))
    // Left Table: ListBuffer(ps_partkey#329, ps_supplycost#332, s_nationkey#371)
    // Right Table: ListBuffer(n_nationkey#164, n_regionkey#166)
    // Output Table: ListBuffer(ps_partkey#329, ps_supplycost#332, n_regionkey#166)
    // Node Depth: 8
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,2,-1,-1,-1,-1,-1};
    for (int c = 0; c < 8; ++c) {
        t.range(56 + 8 * c + 7, 56 + 8 * c) = id_a[c];
    }
    // filter tbl_a config
    uint32_t cfga[45];
    gen_pass_fcfg(cfga);
    memcpy(&b[3], cfga, sizeof(uint32_t) * 45);

    // input table b
    signed char id_b[] = {0,1,-1,-1,-1,-1,-1,-1};
    for (int c = 0; c < 8; ++c) {
        t.range(120 + 8 * c + 7, 120 + 8 * c) = id_b[c];
    }
    // filter tbl_b config
    uint32_t cfgb[45];
    gen_pass_fcfg(cfgb);
    memcpy(&b[6], cfgb, sizeof(uint32_t) * 45);

    //--------------join--------------
    //stream shuffle 1a
    ap_int<64> shuffle1a_cfg;
    shuffle1a_cfg(7, 0) = 2;
    shuffle1a_cfg(15, 8) = 0;
    shuffle1a_cfg(23, 16) = 1;
    shuffle1a_cfg(31, 24) = -1;
    shuffle1a_cfg(39, 32) = -1;
    shuffle1a_cfg(47, 40) = -1;
    shuffle1a_cfg(55, 48) = -1;
    shuffle1a_cfg(63, 56) = -1;

    //stream shuffle 1b
    ap_int<64> shuffle1b_cfg;
    shuffle1b_cfg(7, 0) = 0;
    shuffle1b_cfg(15, 8) = 1;
    shuffle1b_cfg(23, 16) = -1;
    shuffle1b_cfg(31, 24) = -1;
    shuffle1b_cfg(39, 32) = -1;
    shuffle1b_cfg(47, 40) = -1;
    shuffle1b_cfg(55, 48) = -1;
    shuffle1b_cfg(63, 56) = -1;

    // join config
    t.set_bit(0, 1);    // join
    t.set_bit(2, 0);    // dual-key
    t.range(5, 3) = 0;  // hash join flag = 0 for normal, 1 for semi, 2 for anti

    //--------------eval0--------------
    //stream shuffle 2
    ap_int<64> shuffle2_cfg;
    shuffle2_cfg(7, 0) = 6; // ps_partkey
    shuffle2_cfg(15, 8) = 7; // ps_supplycost
    shuffle2_cfg(23, 16) = 0; // n_regionkey
    shuffle2_cfg(31, 24) = -1;
    shuffle2_cfg(39, 32) = -1;
    shuffle2_cfg(47, 40) = -1;
    shuffle2_cfg(55, 48) = -1;
    shuffle2_cfg(63, 56) = -1;

    ap_uint<289> op_eval_0 = 0; // NOP
    // eval0: NOP
    b[1] = op_eval_0;

    //--------------eval1--------------
    //stream shuffle 3
    ap_int<64> shuffle3_cfg;
    shuffle3_cfg(7, 0) = 0; // ps_partkey
    shuffle3_cfg(15, 8) = 1; // ps_supplycost
    shuffle3_cfg(23, 16) = 2; // n_regionkey
    shuffle3_cfg(31, 24) = -1;
    shuffle3_cfg(39, 32) = -1;
    shuffle3_cfg(47, 40) = -1;
    shuffle3_cfg(55, 48) = -1;
    shuffle3_cfg(63, 56) = -1;

    ap_uint<289> op_eval_1 = 0; // NOP
    // eval1: NOP
    b[2] = op_eval_1;

    //--------------aggregate--------------
    //stream shuffle 4
    ap_int<64> shuffle4_cfg;
    shuffle4_cfg(7, 0) = 0; // ps_partkey
    shuffle4_cfg(15, 8) = 1; // ps_supplycost
    shuffle4_cfg(23, 16) = 2; // n_regionkey
    shuffle4_cfg(31, 24) = -1;
    shuffle4_cfg(39, 32) = -1;
    shuffle4_cfg(47, 40) = -1;
    shuffle4_cfg(55, 48) = -1;
    shuffle4_cfg(63, 56) = -1;

    t.set_bit(1, 0); // aggr flag

    //--------------writeout--------------
    // output table col
    t.range(191, 184) = {1*1 + 2*1 + 4*1 + 8*0 + 16*0 + 32*0 + 64*0 + 128*0};
    b[0] = t;

    //stream shuffle assignment
    b[0].range(255, 192) = shuffle1a_cfg;
    b[0].range(319, 256) = shuffle1b_cfg;
    b[0].range(383, 320) = shuffle2_cfg;
    b[0].range(447, 384) = shuffle3_cfg;
    b[0].range(511, 448) = shuffle4_cfg;
}

void get_cfg_dat_JOIN_INNER_TD_7289_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((n_regionkey#166 = r_regionkey#188))
    // Left Table: ListBuffer(ps_partkey#329, ps_supplycost#332, n_regionkey#166)
    // Right Table: ListBuffer(r_regionkey#188)
    // Output Table: ListBuffer(ps_partkey#329, ps_supplycost#332)
    // Node Depth: 7
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,2,-1,-1,-1,-1,-1};
    for (int c = 0; c < 8; ++c) {
        t.range(56 + 8 * c + 7, 56 + 8 * c) = id_a[c];
    }
    // filter tbl_a config
    uint32_t cfga[45];
    gen_pass_fcfg(cfga);
    memcpy(&b[3], cfga, sizeof(uint32_t) * 45);

    // input table b
    signed char id_b[] = {0,-1,-1,-1,-1,-1,-1,-1};
    for (int c = 0; c < 8; ++c) {
        t.range(120 + 8 * c + 7, 120 + 8 * c) = id_b[c];
    }
    // filter tbl_b config
    uint32_t cfgb[45];
    gen_pass_fcfg(cfgb);
    memcpy(&b[6], cfgb, sizeof(uint32_t) * 45);

    //--------------join--------------
    //stream shuffle 1a
    ap_int<64> shuffle1a_cfg;
    shuffle1a_cfg(7, 0) = 2;
    shuffle1a_cfg(15, 8) = 0;
    shuffle1a_cfg(23, 16) = 1;
    shuffle1a_cfg(31, 24) = -1;
    shuffle1a_cfg(39, 32) = -1;
    shuffle1a_cfg(47, 40) = -1;
    shuffle1a_cfg(55, 48) = -1;
    shuffle1a_cfg(63, 56) = -1;

    //stream shuffle 1b
    ap_int<64> shuffle1b_cfg;
    shuffle1b_cfg(7, 0) = 0;
    shuffle1b_cfg(15, 8) = -1;
    shuffle1b_cfg(23, 16) = -1;
    shuffle1b_cfg(31, 24) = -1;
    shuffle1b_cfg(39, 32) = -1;
    shuffle1b_cfg(47, 40) = -1;
    shuffle1b_cfg(55, 48) = -1;
    shuffle1b_cfg(63, 56) = -1;

    // join config
    t.set_bit(0, 1);    // join
    t.set_bit(2, 0);    // dual-key
    t.range(5, 3) = 0;  // hash join flag = 0 for normal, 1 for semi, 2 for anti

    //--------------eval0--------------
    //stream shuffle 2
    ap_int<64> shuffle2_cfg;
    shuffle2_cfg(7, 0) = 6; // ps_partkey
    shuffle2_cfg(15, 8) = 7; // ps_supplycost
    shuffle2_cfg(23, 16) = -1;
    shuffle2_cfg(31, 24) = -1;
    shuffle2_cfg(39, 32) = -1;
    shuffle2_cfg(47, 40) = -1;
    shuffle2_cfg(55, 48) = -1;
    shuffle2_cfg(63, 56) = -1;

    ap_uint<289> op_eval_0 = 0; // NOP
    // eval0: NOP
    b[1] = op_eval_0;

    //--------------eval1--------------
    //stream shuffle 3
    ap_int<64> shuffle3_cfg;
    shuffle3_cfg(7, 0) = 0; // ps_partkey
    shuffle3_cfg(15, 8) = 1; // ps_supplycost
    shuffle3_cfg(23, 16) = -1;
    shuffle3_cfg(31, 24) = -1;
    shuffle3_cfg(39, 32) = -1;
    shuffle3_cfg(47, 40) = -1;
    shuffle3_cfg(55, 48) = -1;
    shuffle3_cfg(63, 56) = -1;

    ap_uint<289> op_eval_1 = 0; // NOP
    // eval1: NOP
    b[2] = op_eval_1;

    //--------------aggregate--------------
    //stream shuffle 4
    ap_int<64> shuffle4_cfg;
    shuffle4_cfg(7, 0) = 0; // ps_partkey
    shuffle4_cfg(15, 8) = 1; // ps_supplycost
    shuffle4_cfg(23, 16) = -1;
    shuffle4_cfg(31, 24) = -1;
    shuffle4_cfg(39, 32) = -1;
    shuffle4_cfg(47, 40) = -1;
    shuffle4_cfg(55, 48) = -1;
    shuffle4_cfg(63, 56) = -1;

    t.set_bit(1, 0); // aggr flag

    //--------------writeout--------------
    // output table col
    t.range(191, 184) = {1*1 + 2*1 + 4*0 + 8*0 + 16*0 + 32*0 + 64*0 + 128*0};
    b[0] = t;

    //stream shuffle assignment
    b[0].range(255, 192) = shuffle1a_cfg;
    b[0].range(319, 256) = shuffle1b_cfg;
    b[0].range(383, 320) = shuffle2_cfg;
    b[0].range(447, 384) = shuffle3_cfg;
    b[0].range(511, 448) = shuffle4_cfg;
}

void get_cfg_dat_JOIN_INNER_TD_5202_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: true StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((p_partkey#284 = ps_partkey#329))
    // Left Table: ListBuffer(ps_partkey#329, ps_suppkey#330, ps_supplycost#332)
    // Right Table: ListBuffer(p_partkey#284, p_mfgr#286)
    // Output Table: ListBuffer(p_partkey#284, p_mfgr#286, ps_suppkey#330, ps_supplycost#332)
    // Node Depth: 5
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,2,-1,-1,-1,-1,-1};
    for (int c = 0; c < 8; ++c) {
        t.range(56 + 8 * c + 7, 56 + 8 * c) = id_a[c];
    }
    // filter tbl_a config
    uint32_t cfga[45];
    gen_pass_fcfg(cfga);
    memcpy(&b[3], cfga, sizeof(uint32_t) * 45);

    // input table b
    signed char id_b[] = {0,1,-1,-1,-1,-1,-1,-1};
    for (int c = 0; c < 8; ++c) {
        t.range(120 + 8 * c + 7, 120 + 8 * c) = id_b[c];
    }
    // filter tbl_b config
    uint32_t cfgb[45];
    gen_pass_fcfg(cfgb);
    memcpy(&b[6], cfgb, sizeof(uint32_t) * 45);

    //--------------join--------------
    //stream shuffle 1a
    ap_int<64> shuffle1a_cfg;
    shuffle1a_cfg(7, 0) = 0;
    shuffle1a_cfg(15, 8) = 1;
    shuffle1a_cfg(23, 16) = 2;
    shuffle1a_cfg(31, 24) = -1;
    shuffle1a_cfg(39, 32) = -1;
    shuffle1a_cfg(47, 40) = -1;
    shuffle1a_cfg(55, 48) = -1;
    shuffle1a_cfg(63, 56) = -1;

    //stream shuffle 1b
    ap_int<64> shuffle1b_cfg;
    shuffle1b_cfg(7, 0) = 0;
    shuffle1b_cfg(15, 8) = 1;
    shuffle1b_cfg(23, 16) = -1;
    shuffle1b_cfg(31, 24) = -1;
    shuffle1b_cfg(39, 32) = -1;
    shuffle1b_cfg(47, 40) = -1;
    shuffle1b_cfg(55, 48) = -1;
    shuffle1b_cfg(63, 56) = -1;

    // join config
    t.set_bit(0, 1);    // join
    t.set_bit(2, 0);    // dual-key
    t.range(5, 3) = 0;  // hash join flag = 0 for normal, 1 for semi, 2 for anti

    //--------------eval0--------------
    //stream shuffle 2
    ap_int<64> shuffle2_cfg;
    shuffle2_cfg(7, 0) = 12; // p_partkey
    shuffle2_cfg(15, 8) = 0; // p_mfgr
    shuffle2_cfg(23, 16) = 6; // ps_suppkey
    shuffle2_cfg(31, 24) = 7; // ps_supplycost
    shuffle2_cfg(39, 32) = -1;
    shuffle2_cfg(47, 40) = -1;
    shuffle2_cfg(55, 48) = -1;
    shuffle2_cfg(63, 56) = -1;

    ap_uint<289> op_eval_0 = 0; // NOP
    // eval0: NOP
    b[1] = op_eval_0;

    //--------------eval1--------------
    //stream shuffle 3
    ap_int<64> shuffle3_cfg;
    shuffle3_cfg(7, 0) = 0; // p_partkey
    shuffle3_cfg(15, 8) = 1; // p_mfgr
    shuffle3_cfg(23, 16) = 2; // ps_suppkey
    shuffle3_cfg(31, 24) = 3; // ps_supplycost
    shuffle3_cfg(39, 32) = -1;
    shuffle3_cfg(47, 40) = -1;
    shuffle3_cfg(55, 48) = -1;
    shuffle3_cfg(63, 56) = -1;

    ap_uint<289> op_eval_1 = 0; // NOP
    // eval1: NOP
    b[2] = op_eval_1;

    //--------------aggregate--------------
    //stream shuffle 4
    ap_int<64> shuffle4_cfg;
    shuffle4_cfg(7, 0) = 0; // p_partkey
    shuffle4_cfg(15, 8) = 1; // p_mfgr
    shuffle4_cfg(23, 16) = 2; // ps_suppkey
    shuffle4_cfg(31, 24) = 3; // ps_supplycost
    shuffle4_cfg(39, 32) = -1;
    shuffle4_cfg(47, 40) = -1;
    shuffle4_cfg(55, 48) = -1;
    shuffle4_cfg(63, 56) = -1;

    t.set_bit(1, 0); // aggr flag

    //--------------writeout--------------
    // output table col
    t.range(191, 184) = {1*1 + 2*1 + 4*1 + 8*1 + 16*0 + 32*0 + 64*0 + 128*0};
    b[0] = t;

    //stream shuffle assignment
    b[0].range(255, 192) = shuffle1a_cfg;
    b[0].range(319, 256) = shuffle1b_cfg;
    b[0].range(383, 320) = shuffle2_cfg;
    b[0].range(447, 384) = shuffle3_cfg;
    b[0].range(511, 448) = shuffle4_cfg;
}

