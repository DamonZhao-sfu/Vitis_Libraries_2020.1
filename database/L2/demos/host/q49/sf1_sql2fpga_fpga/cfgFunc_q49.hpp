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

void get_cfg_dat_JOIN_INNER_TD_11800726_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((ss_ticket_number#1215L = sr_ticket_number#678L) AND (ss_item_sk#1208 = sr_item_sk#671)))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_ticket_number#1215L, ss_quantity#1216, ss_net_paid#1226)
    // Right Table: ListBuffer(sr_item_sk#671, sr_ticket_number#678L, sr_return_quantity#679, sr_return_amt#680)
    // Output Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_quantity#1216, ss_net_paid#1226, sr_return_quantity#679, sr_return_amt#680)
    // Node Depth: 11
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,2,3,4,-1,-1,-1};
    for (int c = 0; c < 8; ++c) {
        t.range(56 + 8 * c + 7, 56 + 8 * c) = id_a[c];
    }
    // filter tbl_a config
    uint32_t cfga[45];
    gen_pass_fcfg(cfga);
    memcpy(&b[3], cfga, sizeof(uint32_t) * 45);

    // input table b
    signed char id_b[] = {0,1,2,3,-1,-1,-1,-1};
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
    shuffle1a_cfg(15, 8) = 1;
    shuffle1a_cfg(23, 16) = 4;
    shuffle1a_cfg(31, 24) = 0;
    shuffle1a_cfg(39, 32) = 3;
    shuffle1a_cfg(47, 40) = -1;
    shuffle1a_cfg(55, 48) = -1;
    shuffle1a_cfg(63, 56) = -1;

    //stream shuffle 1b
    ap_int<64> shuffle1b_cfg;
    shuffle1b_cfg(7, 0) = 1;
    shuffle1b_cfg(15, 8) = 0;
    shuffle1b_cfg(23, 16) = 3;
    shuffle1b_cfg(31, 24) = 2;
    shuffle1b_cfg(39, 32) = -1;
    shuffle1b_cfg(47, 40) = -1;
    shuffle1b_cfg(55, 48) = -1;
    shuffle1b_cfg(63, 56) = -1;

    // join config
    t.set_bit(0, 1);    // join
    t.set_bit(2, 1);    // dual-key
    t.range(5, 3) = 0;  // hash join flag = 0 for normal, 1 for semi, 2 for anti

    //--------------eval0--------------
    //stream shuffle 2
    ap_int<64> shuffle2_cfg;
    shuffle2_cfg(7, 0) = 7; // ss_sold_date_sk
    shuffle2_cfg(15, 8) = 13; // ss_item_sk
    shuffle2_cfg(23, 16) = 8; // ss_quantity
    shuffle2_cfg(31, 24) = 6; // ss_net_paid
    shuffle2_cfg(39, 32) = 1; // sr_return_quantity
    shuffle2_cfg(47, 40) = 0; // sr_return_amt
    shuffle2_cfg(55, 48) = -1;
    shuffle2_cfg(63, 56) = -1;

    ap_uint<289> op_eval_0 = 0; // NOP
    // eval0: NOP
    b[1] = op_eval_0;

    //--------------eval1--------------
    //stream shuffle 3
    ap_int<64> shuffle3_cfg;
    shuffle3_cfg(7, 0) = 0; // ss_sold_date_sk
    shuffle3_cfg(15, 8) = 1; // ss_item_sk
    shuffle3_cfg(23, 16) = 2; // ss_quantity
    shuffle3_cfg(31, 24) = 3; // ss_net_paid
    shuffle3_cfg(39, 32) = 4; // sr_return_quantity
    shuffle3_cfg(47, 40) = 5; // sr_return_amt
    shuffle3_cfg(55, 48) = -1;
    shuffle3_cfg(63, 56) = -1;

    ap_uint<289> op_eval_1 = 0; // NOP
    // eval1: NOP
    b[2] = op_eval_1;

    //--------------aggregate--------------
    //stream shuffle 4
    ap_int<64> shuffle4_cfg;
    shuffle4_cfg(7, 0) = 0; // ss_sold_date_sk
    shuffle4_cfg(15, 8) = 1; // ss_item_sk
    shuffle4_cfg(23, 16) = 2; // ss_quantity
    shuffle4_cfg(31, 24) = 3; // ss_net_paid
    shuffle4_cfg(39, 32) = 4; // sr_return_quantity
    shuffle4_cfg(47, 40) = 5; // sr_return_amt
    shuffle4_cfg(55, 48) = -1;
    shuffle4_cfg(63, 56) = -1;

    t.set_bit(1, 0); // aggr flag

    //--------------writeout--------------
    // output table col
    t.range(191, 184) = {1*1 + 2*1 + 4*1 + 8*1 + 16*1 + 32*1 + 64*0 + 128*0};
    b[0] = t;

    //stream shuffle assignment
    b[0].range(255, 192) = shuffle1a_cfg;
    b[0].range(319, 256) = shuffle1b_cfg;
    b[0].range(383, 320) = shuffle2_cfg;
    b[0].range(447, 384) = shuffle3_cfg;
    b[0].range(511, 448) = shuffle4_cfg;
}

void get_cfg_dat_JOIN_INNER_TD_11730313_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((cs_order_number#1121L = cr_order_number#1039L) AND (cs_item_sk#1119 = cr_item_sk#1025)))
    // Left Table: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119, cs_order_number#1121L, cs_quantity#1122, cs_net_paid#1133)
    // Right Table: ListBuffer(cr_item_sk#1025, cr_order_number#1039L, cr_return_quantity#1040, cr_return_amount#1041)
    // Output Table: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119, cs_quantity#1122, cs_net_paid#1133, cr_return_quantity#1040, cr_return_amount#1041)
    // Node Depth: 11
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,2,3,4,-1,-1,-1};
    for (int c = 0; c < 8; ++c) {
        t.range(56 + 8 * c + 7, 56 + 8 * c) = id_a[c];
    }
    // filter tbl_a config
    uint32_t cfga[45];
    gen_pass_fcfg(cfga);
    memcpy(&b[3], cfga, sizeof(uint32_t) * 45);

    // input table b
    signed char id_b[] = {0,1,2,3,-1,-1,-1,-1};
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
    shuffle1a_cfg(15, 8) = 1;
    shuffle1a_cfg(23, 16) = 4;
    shuffle1a_cfg(31, 24) = 0;
    shuffle1a_cfg(39, 32) = 3;
    shuffle1a_cfg(47, 40) = -1;
    shuffle1a_cfg(55, 48) = -1;
    shuffle1a_cfg(63, 56) = -1;

    //stream shuffle 1b
    ap_int<64> shuffle1b_cfg;
    shuffle1b_cfg(7, 0) = 1;
    shuffle1b_cfg(15, 8) = 0;
    shuffle1b_cfg(23, 16) = 2;
    shuffle1b_cfg(31, 24) = 3;
    shuffle1b_cfg(39, 32) = -1;
    shuffle1b_cfg(47, 40) = -1;
    shuffle1b_cfg(55, 48) = -1;
    shuffle1b_cfg(63, 56) = -1;

    // join config
    t.set_bit(0, 1);    // join
    t.set_bit(2, 1);    // dual-key
    t.range(5, 3) = 0;  // hash join flag = 0 for normal, 1 for semi, 2 for anti

    //--------------eval0--------------
    //stream shuffle 2
    ap_int<64> shuffle2_cfg;
    shuffle2_cfg(7, 0) = 7; // cs_sold_date_sk
    shuffle2_cfg(15, 8) = 13; // cs_item_sk
    shuffle2_cfg(23, 16) = 8; // cs_quantity
    shuffle2_cfg(31, 24) = 6; // cs_net_paid
    shuffle2_cfg(39, 32) = 0; // cr_return_quantity
    shuffle2_cfg(47, 40) = 1; // cr_return_amount
    shuffle2_cfg(55, 48) = -1;
    shuffle2_cfg(63, 56) = -1;

    ap_uint<289> op_eval_0 = 0; // NOP
    // eval0: NOP
    b[1] = op_eval_0;

    //--------------eval1--------------
    //stream shuffle 3
    ap_int<64> shuffle3_cfg;
    shuffle3_cfg(7, 0) = 0; // cs_sold_date_sk
    shuffle3_cfg(15, 8) = 1; // cs_item_sk
    shuffle3_cfg(23, 16) = 2; // cs_quantity
    shuffle3_cfg(31, 24) = 3; // cs_net_paid
    shuffle3_cfg(39, 32) = 4; // cr_return_quantity
    shuffle3_cfg(47, 40) = 5; // cr_return_amount
    shuffle3_cfg(55, 48) = -1;
    shuffle3_cfg(63, 56) = -1;

    ap_uint<289> op_eval_1 = 0; // NOP
    // eval1: NOP
    b[2] = op_eval_1;

    //--------------aggregate--------------
    //stream shuffle 4
    ap_int<64> shuffle4_cfg;
    shuffle4_cfg(7, 0) = 0; // cs_sold_date_sk
    shuffle4_cfg(15, 8) = 1; // cs_item_sk
    shuffle4_cfg(23, 16) = 2; // cs_quantity
    shuffle4_cfg(31, 24) = 3; // cs_net_paid
    shuffle4_cfg(39, 32) = 4; // cr_return_quantity
    shuffle4_cfg(47, 40) = 5; // cr_return_amount
    shuffle4_cfg(55, 48) = -1;
    shuffle4_cfg(63, 56) = -1;

    t.set_bit(1, 0); // aggr flag

    //--------------writeout--------------
    // output table col
    t.range(191, 184) = {1*1 + 2*1 + 4*1 + 8*1 + 16*1 + 32*1 + 64*0 + 128*0};
    b[0] = t;

    //stream shuffle assignment
    b[0].range(255, 192) = shuffle1a_cfg;
    b[0].range(319, 256) = shuffle1b_cfg;
    b[0].range(383, 320) = shuffle2_cfg;
    b[0].range(447, 384) = shuffle3_cfg;
    b[0].range(511, 448) = shuffle4_cfg;
}

void get_cfg_dat_JOIN_INNER_TD_11320265_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((ws_order_number#746L = wr_order_number#844L) AND (ws_item_sk#732 = wr_item_sk#833)))
    // Left Table: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_order_number#746L, ws_quantity#747, ws_net_paid#758)
    // Right Table: ListBuffer(wr_item_sk#833, wr_order_number#844L, wr_return_quantity#845, wr_return_amt#846)
    // Output Table: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_quantity#747, ws_net_paid#758, wr_return_quantity#845, wr_return_amt#846)
    // Node Depth: 11
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,2,3,4,-1,-1,-1};
    for (int c = 0; c < 8; ++c) {
        t.range(56 + 8 * c + 7, 56 + 8 * c) = id_a[c];
    }
    // filter tbl_a config
    uint32_t cfga[45];
    gen_pass_fcfg(cfga);
    memcpy(&b[3], cfga, sizeof(uint32_t) * 45);

    // input table b
    signed char id_b[] = {0,1,2,3,-1,-1,-1,-1};
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
    shuffle1a_cfg(15, 8) = 1;
    shuffle1a_cfg(23, 16) = 3;
    shuffle1a_cfg(31, 24) = 0;
    shuffle1a_cfg(39, 32) = 4;
    shuffle1a_cfg(47, 40) = -1;
    shuffle1a_cfg(55, 48) = -1;
    shuffle1a_cfg(63, 56) = -1;

    //stream shuffle 1b
    ap_int<64> shuffle1b_cfg;
    shuffle1b_cfg(7, 0) = 1;
    shuffle1b_cfg(15, 8) = 0;
    shuffle1b_cfg(23, 16) = 3;
    shuffle1b_cfg(31, 24) = 2;
    shuffle1b_cfg(39, 32) = -1;
    shuffle1b_cfg(47, 40) = -1;
    shuffle1b_cfg(55, 48) = -1;
    shuffle1b_cfg(63, 56) = -1;

    // join config
    t.set_bit(0, 1);    // join
    t.set_bit(2, 1);    // dual-key
    t.range(5, 3) = 0;  // hash join flag = 0 for normal, 1 for semi, 2 for anti

    //--------------eval0--------------
    //stream shuffle 2
    ap_int<64> shuffle2_cfg;
    shuffle2_cfg(7, 0) = 7; // ws_sold_date_sk
    shuffle2_cfg(15, 8) = 13; // ws_item_sk
    shuffle2_cfg(23, 16) = 6; // ws_quantity
    shuffle2_cfg(31, 24) = 8; // ws_net_paid
    shuffle2_cfg(39, 32) = 1; // wr_return_quantity
    shuffle2_cfg(47, 40) = 0; // wr_return_amt
    shuffle2_cfg(55, 48) = -1;
    shuffle2_cfg(63, 56) = -1;

    ap_uint<289> op_eval_0 = 0; // NOP
    // eval0: NOP
    b[1] = op_eval_0;

    //--------------eval1--------------
    //stream shuffle 3
    ap_int<64> shuffle3_cfg;
    shuffle3_cfg(7, 0) = 0; // ws_sold_date_sk
    shuffle3_cfg(15, 8) = 1; // ws_item_sk
    shuffle3_cfg(23, 16) = 2; // ws_quantity
    shuffle3_cfg(31, 24) = 3; // ws_net_paid
    shuffle3_cfg(39, 32) = 4; // wr_return_quantity
    shuffle3_cfg(47, 40) = 5; // wr_return_amt
    shuffle3_cfg(55, 48) = -1;
    shuffle3_cfg(63, 56) = -1;

    ap_uint<289> op_eval_1 = 0; // NOP
    // eval1: NOP
    b[2] = op_eval_1;

    //--------------aggregate--------------
    //stream shuffle 4
    ap_int<64> shuffle4_cfg;
    shuffle4_cfg(7, 0) = 0; // ws_sold_date_sk
    shuffle4_cfg(15, 8) = 1; // ws_item_sk
    shuffle4_cfg(23, 16) = 2; // ws_quantity
    shuffle4_cfg(31, 24) = 3; // ws_net_paid
    shuffle4_cfg(39, 32) = 4; // wr_return_quantity
    shuffle4_cfg(47, 40) = 5; // wr_return_amt
    shuffle4_cfg(55, 48) = -1;
    shuffle4_cfg(63, 56) = -1;

    t.set_bit(1, 0); // aggr flag

    //--------------writeout--------------
    // output table col
    t.range(191, 184) = {1*1 + 2*1 + 4*1 + 8*1 + 16*1 + 32*1 + 64*0 + 128*0};
    b[0] = t;

    //stream shuffle assignment
    b[0].range(255, 192) = shuffle1a_cfg;
    b[0].range(319, 256) = shuffle1b_cfg;
    b[0].range(383, 320) = shuffle2_cfg;
    b[0].range(447, 384) = shuffle3_cfg;
    b[0].range(511, 448) = shuffle4_cfg;
}

void get_cfg_dat_JOIN_INNER_TD_10213953_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#1206 = d_date_sk#3590))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_quantity#1216, ss_net_paid#1226, sr_return_quantity#679, sr_return_amt#680)
    // Right Table: ListBuffer(d_date_sk#3590)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_quantity#1216, ss_net_paid#1226, sr_return_quantity#679, sr_return_amt#680)
    // Node Depth: 10
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,2,3,4,5,-1,-1};
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
    shuffle1a_cfg(7, 0) = 0;
    shuffle1a_cfg(15, 8) = 5;
    shuffle1a_cfg(23, 16) = 3;
    shuffle1a_cfg(31, 24) = 1;
    shuffle1a_cfg(39, 32) = 4;
    shuffle1a_cfg(47, 40) = 2;
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
    shuffle2_cfg(7, 0) = 8; // ss_item_sk
    shuffle2_cfg(15, 8) = 10; // ss_quantity
    shuffle2_cfg(23, 16) = 7; // ss_net_paid
    shuffle2_cfg(31, 24) = 9; // sr_return_quantity
    shuffle2_cfg(39, 32) = 6; // sr_return_amt
    shuffle2_cfg(47, 40) = -1;
    shuffle2_cfg(55, 48) = -1;
    shuffle2_cfg(63, 56) = -1;

    ap_uint<289> op_eval_0 = 0; // NOP
    // eval0: NOP
    b[1] = op_eval_0;

    //--------------eval1--------------
    //stream shuffle 3
    ap_int<64> shuffle3_cfg;
    shuffle3_cfg(7, 0) = 0; // ss_item_sk
    shuffle3_cfg(15, 8) = 1; // ss_quantity
    shuffle3_cfg(23, 16) = 2; // ss_net_paid
    shuffle3_cfg(31, 24) = 3; // sr_return_quantity
    shuffle3_cfg(39, 32) = 4; // sr_return_amt
    shuffle3_cfg(47, 40) = -1;
    shuffle3_cfg(55, 48) = -1;
    shuffle3_cfg(63, 56) = -1;

    ap_uint<289> op_eval_1 = 0; // NOP
    // eval1: NOP
    b[2] = op_eval_1;

    //--------------aggregate--------------
    //stream shuffle 4
    ap_int<64> shuffle4_cfg;
    shuffle4_cfg(7, 0) = 0; // ss_item_sk
    shuffle4_cfg(15, 8) = 1; // ss_quantity
    shuffle4_cfg(23, 16) = 2; // ss_net_paid
    shuffle4_cfg(31, 24) = 3; // sr_return_quantity
    shuffle4_cfg(39, 32) = 4; // sr_return_amt
    shuffle4_cfg(47, 40) = -1;
    shuffle4_cfg(55, 48) = -1;
    shuffle4_cfg(63, 56) = -1;

    t.set_bit(1, 0); // aggr flag

    //--------------writeout--------------
    // output table col
    t.range(191, 184) = {1*1 + 2*1 + 4*1 + 8*1 + 16*1 + 32*0 + 64*0 + 128*0};
    b[0] = t;

    //stream shuffle assignment
    b[0].range(255, 192) = shuffle1a_cfg;
    b[0].range(319, 256) = shuffle1b_cfg;
    b[0].range(383, 320) = shuffle2_cfg;
    b[0].range(447, 384) = shuffle3_cfg;
    b[0].range(511, 448) = shuffle4_cfg;
}

void get_cfg_dat_JOIN_INNER_TD_10288240_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_sold_date_sk#1104 = d_date_sk#3562))
    // Left Table: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119, cs_quantity#1122, cs_net_paid#1133, cr_return_quantity#1040, cr_return_amount#1041)
    // Right Table: ListBuffer(d_date_sk#3562)
    // Output Table: ListBuffer(cs_item_sk#1119, cs_quantity#1122, cs_net_paid#1133, cr_return_quantity#1040, cr_return_amount#1041)
    // Node Depth: 10
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,2,3,4,5,-1,-1};
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
    shuffle1a_cfg(7, 0) = 0;
    shuffle1a_cfg(15, 8) = 3;
    shuffle1a_cfg(23, 16) = 1;
    shuffle1a_cfg(31, 24) = 4;
    shuffle1a_cfg(39, 32) = 2;
    shuffle1a_cfg(47, 40) = 5;
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
    shuffle2_cfg(7, 0) = 7; // cs_item_sk
    shuffle2_cfg(15, 8) = 9; // cs_quantity
    shuffle2_cfg(23, 16) = 6; // cs_net_paid
    shuffle2_cfg(31, 24) = 8; // cr_return_quantity
    shuffle2_cfg(39, 32) = 10; // cr_return_amount
    shuffle2_cfg(47, 40) = -1;
    shuffle2_cfg(55, 48) = -1;
    shuffle2_cfg(63, 56) = -1;

    ap_uint<289> op_eval_0 = 0; // NOP
    // eval0: NOP
    b[1] = op_eval_0;

    //--------------eval1--------------
    //stream shuffle 3
    ap_int<64> shuffle3_cfg;
    shuffle3_cfg(7, 0) = 0; // cs_item_sk
    shuffle3_cfg(15, 8) = 1; // cs_quantity
    shuffle3_cfg(23, 16) = 2; // cs_net_paid
    shuffle3_cfg(31, 24) = 3; // cr_return_quantity
    shuffle3_cfg(39, 32) = 4; // cr_return_amount
    shuffle3_cfg(47, 40) = -1;
    shuffle3_cfg(55, 48) = -1;
    shuffle3_cfg(63, 56) = -1;

    ap_uint<289> op_eval_1 = 0; // NOP
    // eval1: NOP
    b[2] = op_eval_1;

    //--------------aggregate--------------
    //stream shuffle 4
    ap_int<64> shuffle4_cfg;
    shuffle4_cfg(7, 0) = 0; // cs_item_sk
    shuffle4_cfg(15, 8) = 1; // cs_quantity
    shuffle4_cfg(23, 16) = 2; // cs_net_paid
    shuffle4_cfg(31, 24) = 3; // cr_return_quantity
    shuffle4_cfg(39, 32) = 4; // cr_return_amount
    shuffle4_cfg(47, 40) = -1;
    shuffle4_cfg(55, 48) = -1;
    shuffle4_cfg(63, 56) = -1;

    t.set_bit(1, 0); // aggr flag

    //--------------writeout--------------
    // output table col
    t.range(191, 184) = {1*1 + 2*1 + 4*1 + 8*1 + 16*1 + 32*0 + 64*0 + 128*0};
    b[0] = t;

    //stream shuffle assignment
    b[0].range(255, 192) = shuffle1a_cfg;
    b[0].range(319, 256) = shuffle1b_cfg;
    b[0].range(383, 320) = shuffle2_cfg;
    b[0].range(447, 384) = shuffle3_cfg;
    b[0].range(511, 448) = shuffle4_cfg;
}

void get_cfg_dat_JOIN_INNER_TD_10424443_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_sold_date_sk#729 = d_date_sk#120))
    // Left Table: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_quantity#747, ws_net_paid#758, wr_return_quantity#845, wr_return_amt#846)
    // Right Table: ListBuffer(d_date_sk#120)
    // Output Table: ListBuffer(ws_item_sk#732, ws_quantity#747, ws_net_paid#758, wr_return_quantity#845, wr_return_amt#846)
    // Node Depth: 10
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,2,3,4,5,-1,-1};
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
    shuffle1a_cfg(7, 0) = 0;
    shuffle1a_cfg(15, 8) = 1;
    shuffle1a_cfg(23, 16) = 2;
    shuffle1a_cfg(31, 24) = 5;
    shuffle1a_cfg(39, 32) = 4;
    shuffle1a_cfg(47, 40) = 3;
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
    shuffle2_cfg(7, 0) = 6; // ws_item_sk
    shuffle2_cfg(15, 8) = 7; // ws_quantity
    shuffle2_cfg(23, 16) = 10; // ws_net_paid
    shuffle2_cfg(31, 24) = 9; // wr_return_quantity
    shuffle2_cfg(39, 32) = 8; // wr_return_amt
    shuffle2_cfg(47, 40) = -1;
    shuffle2_cfg(55, 48) = -1;
    shuffle2_cfg(63, 56) = -1;

    ap_uint<289> op_eval_0 = 0; // NOP
    // eval0: NOP
    b[1] = op_eval_0;

    //--------------eval1--------------
    //stream shuffle 3
    ap_int<64> shuffle3_cfg;
    shuffle3_cfg(7, 0) = 0; // ws_item_sk
    shuffle3_cfg(15, 8) = 1; // ws_quantity
    shuffle3_cfg(23, 16) = 2; // ws_net_paid
    shuffle3_cfg(31, 24) = 3; // wr_return_quantity
    shuffle3_cfg(39, 32) = 4; // wr_return_amt
    shuffle3_cfg(47, 40) = -1;
    shuffle3_cfg(55, 48) = -1;
    shuffle3_cfg(63, 56) = -1;

    ap_uint<289> op_eval_1 = 0; // NOP
    // eval1: NOP
    b[2] = op_eval_1;

    //--------------aggregate--------------
    //stream shuffle 4
    ap_int<64> shuffle4_cfg;
    shuffle4_cfg(7, 0) = 0; // ws_item_sk
    shuffle4_cfg(15, 8) = 1; // ws_quantity
    shuffle4_cfg(23, 16) = 2; // ws_net_paid
    shuffle4_cfg(31, 24) = 3; // wr_return_quantity
    shuffle4_cfg(39, 32) = 4; // wr_return_amt
    shuffle4_cfg(47, 40) = -1;
    shuffle4_cfg(55, 48) = -1;
    shuffle4_cfg(63, 56) = -1;

    t.set_bit(1, 0); // aggr flag

    //--------------writeout--------------
    // output table col
    t.range(191, 184) = {1*1 + 2*1 + 4*1 + 8*1 + 16*1 + 32*0 + 64*0 + 128*0};
    b[0] = t;

    //stream shuffle assignment
    b[0].range(255, 192) = shuffle1a_cfg;
    b[0].range(319, 256) = shuffle1b_cfg;
    b[0].range(383, 320) = shuffle2_cfg;
    b[0].range(447, 384) = shuffle3_cfg;
    b[0].range(511, 448) = shuffle4_cfg;
}

