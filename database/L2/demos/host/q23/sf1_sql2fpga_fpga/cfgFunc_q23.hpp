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

void get_cfg_dat_JOIN_INNER_TD_13942914_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#1206 = d_date_sk#120))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208)
    // Right Table: ListBuffer(d_date_sk#120, d_date#122)
    // Output Table: ListBuffer(ss_item_sk#1208, d_date#122)
    // Node Depth: 13
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,-1,-1,-1,-1,-1,-1};
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
    shuffle1a_cfg(23, 16) = -1;
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
    shuffle2_cfg(7, 0) = 6; // ss_item_sk
    shuffle2_cfg(15, 8) = 0; // d_date
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
    shuffle3_cfg(7, 0) = 0; // ss_item_sk
    shuffle3_cfg(15, 8) = 1; // d_date
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
    shuffle4_cfg(7, 0) = 0; // ss_item_sk
    shuffle4_cfg(15, 8) = 1; // d_date
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

void get_cfg_dat_JOIN_INNER_TD_13287355_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#1206 = d_date_sk#120))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208)
    // Right Table: ListBuffer(d_date_sk#120, d_date#122)
    // Output Table: ListBuffer(ss_item_sk#1208, d_date#122)
    // Node Depth: 13
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,-1,-1,-1,-1,-1,-1};
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
    shuffle1a_cfg(23, 16) = -1;
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
    shuffle2_cfg(7, 0) = 6; // ss_item_sk
    shuffle2_cfg(15, 8) = 0; // d_date
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
    shuffle3_cfg(7, 0) = 0; // ss_item_sk
    shuffle3_cfg(15, 8) = 1; // d_date
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
    shuffle4_cfg(7, 0) = 0; // ss_item_sk
    shuffle4_cfg(15, 8) = 1; // d_date
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

void get_cfg_dat_JOIN_INNER_TD_12149137_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_customer_sk#3561 = c_customer_sk#0))
    // Left Table: ListBuffer(ss_sold_date_sk#3558, ss_customer_sk#3561, ss_quantity#3568, ss_sales_price#3571)
    // Right Table: ListBuffer(c_customer_sk#0)
    // Output Table: ListBuffer(ss_sold_date_sk#3558, ss_quantity#3568, ss_sales_price#3571, c_customer_sk#0)
    // Node Depth: 12
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,2,3,-1,-1,-1,-1};
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
    shuffle1a_cfg(7, 0) = 1;
    shuffle1a_cfg(15, 8) = 0;
    shuffle1a_cfg(23, 16) = 2;
    shuffle1a_cfg(31, 24) = 3;
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
    shuffle2_cfg(7, 0) = 6; // ss_sold_date_sk
    shuffle2_cfg(15, 8) = 7; // ss_quantity
    shuffle2_cfg(23, 16) = 8; // ss_sales_price
    shuffle2_cfg(31, 24) = 12; // c_customer_sk
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
    shuffle3_cfg(7, 0) = 0; // ss_sold_date_sk
    shuffle3_cfg(15, 8) = 1; // ss_quantity
    shuffle3_cfg(23, 16) = 2; // ss_sales_price
    shuffle3_cfg(31, 24) = 3; // c_customer_sk
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
    shuffle4_cfg(7, 0) = 0; // ss_sold_date_sk
    shuffle4_cfg(15, 8) = 1; // ss_quantity
    shuffle4_cfg(23, 16) = 2; // ss_sales_price
    shuffle4_cfg(31, 24) = 3; // c_customer_sk
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

void get_cfg_dat_JOIN_INNER_TD_12732934_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_customer_sk#3561 = c_customer_sk#0))
    // Left Table: ListBuffer(ss_sold_date_sk#3558, ss_customer_sk#3561, ss_quantity#3568, ss_sales_price#3571)
    // Right Table: ListBuffer(c_customer_sk#0)
    // Output Table: ListBuffer(ss_sold_date_sk#3558, ss_quantity#3568, ss_sales_price#3571, c_customer_sk#0)
    // Node Depth: 12
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,2,3,-1,-1,-1,-1};
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
    shuffle1a_cfg(7, 0) = 1;
    shuffle1a_cfg(15, 8) = 0;
    shuffle1a_cfg(23, 16) = 2;
    shuffle1a_cfg(31, 24) = 3;
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
    shuffle2_cfg(7, 0) = 6; // ss_sold_date_sk
    shuffle2_cfg(15, 8) = 7; // ss_quantity
    shuffle2_cfg(23, 16) = 8; // ss_sales_price
    shuffle2_cfg(31, 24) = 12; // c_customer_sk
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
    shuffle3_cfg(7, 0) = 0; // ss_sold_date_sk
    shuffle3_cfg(15, 8) = 1; // ss_quantity
    shuffle3_cfg(23, 16) = 2; // ss_sales_price
    shuffle3_cfg(31, 24) = 3; // c_customer_sk
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
    shuffle4_cfg(7, 0) = 0; // ss_sold_date_sk
    shuffle4_cfg(15, 8) = 1; // ss_quantity
    shuffle4_cfg(23, 16) = 2; // ss_sales_price
    shuffle4_cfg(31, 24) = 3; // c_customer_sk
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

void get_cfg_dat_JOIN_INNER_TD_12552462_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_customer_sk#3561 = c_customer_sk#0))
    // Left Table: ListBuffer(ss_sold_date_sk#3558, ss_customer_sk#3561, ss_quantity#3568, ss_sales_price#3571)
    // Right Table: ListBuffer(c_customer_sk#0)
    // Output Table: ListBuffer(ss_sold_date_sk#3558, ss_quantity#3568, ss_sales_price#3571, c_customer_sk#0)
    // Node Depth: 12
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,2,3,-1,-1,-1,-1};
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
    shuffle1a_cfg(7, 0) = 1;
    shuffle1a_cfg(15, 8) = 0;
    shuffle1a_cfg(23, 16) = 2;
    shuffle1a_cfg(31, 24) = 3;
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
    shuffle2_cfg(7, 0) = 6; // ss_sold_date_sk
    shuffle2_cfg(15, 8) = 7; // ss_quantity
    shuffle2_cfg(23, 16) = 8; // ss_sales_price
    shuffle2_cfg(31, 24) = 12; // c_customer_sk
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
    shuffle3_cfg(7, 0) = 0; // ss_sold_date_sk
    shuffle3_cfg(15, 8) = 1; // ss_quantity
    shuffle3_cfg(23, 16) = 2; // ss_sales_price
    shuffle3_cfg(31, 24) = 3; // c_customer_sk
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
    shuffle4_cfg(7, 0) = 0; // ss_sold_date_sk
    shuffle4_cfg(15, 8) = 1; // ss_quantity
    shuffle4_cfg(23, 16) = 2; // ss_sales_price
    shuffle4_cfg(31, 24) = 3; // c_customer_sk
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

void get_cfg_dat_JOIN_INNER_TD_12481484_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_customer_sk#3561 = c_customer_sk#0))
    // Left Table: ListBuffer(ss_sold_date_sk#3558, ss_customer_sk#3561, ss_quantity#3568, ss_sales_price#3571)
    // Right Table: ListBuffer(c_customer_sk#0)
    // Output Table: ListBuffer(ss_sold_date_sk#3558, ss_quantity#3568, ss_sales_price#3571, c_customer_sk#0)
    // Node Depth: 12
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,2,3,-1,-1,-1,-1};
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
    shuffle1a_cfg(7, 0) = 1;
    shuffle1a_cfg(15, 8) = 0;
    shuffle1a_cfg(23, 16) = 2;
    shuffle1a_cfg(31, 24) = 3;
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
    shuffle2_cfg(7, 0) = 6; // ss_sold_date_sk
    shuffle2_cfg(15, 8) = 7; // ss_quantity
    shuffle2_cfg(23, 16) = 8; // ss_sales_price
    shuffle2_cfg(31, 24) = 12; // c_customer_sk
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
    shuffle3_cfg(7, 0) = 0; // ss_sold_date_sk
    shuffle3_cfg(15, 8) = 1; // ss_quantity
    shuffle3_cfg(23, 16) = 2; // ss_sales_price
    shuffle3_cfg(31, 24) = 3; // c_customer_sk
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
    shuffle4_cfg(7, 0) = 0; // ss_sold_date_sk
    shuffle4_cfg(15, 8) = 1; // ss_quantity
    shuffle4_cfg(23, 16) = 2; // ss_sales_price
    shuffle4_cfg(31, 24) = 3; // c_customer_sk
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

void get_cfg_dat_JOIN_INNER_TD_11391199_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#3558 = d_date_sk#3581))
    // Left Table: ListBuffer(ss_sold_date_sk#3558, ss_quantity#3568, ss_sales_price#3571, c_customer_sk#0)
    // Right Table: ListBuffer(d_date_sk#3581)
    // Output Table: ListBuffer(ss_quantity#3568, ss_sales_price#3571, c_customer_sk#0)
    // Node Depth: 11
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,2,3,-1,-1,-1,-1};
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
    shuffle1a_cfg(31, 24) = 2;
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
    shuffle2_cfg(7, 0) = 7; // ss_quantity
    shuffle2_cfg(15, 8) = 8; // ss_sales_price
    shuffle2_cfg(23, 16) = 6; // c_customer_sk
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
    shuffle3_cfg(7, 0) = 0; // ss_quantity
    shuffle3_cfg(15, 8) = 1; // ss_sales_price
    shuffle3_cfg(23, 16) = 2; // c_customer_sk
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
    shuffle4_cfg(7, 0) = 0; // ss_quantity
    shuffle4_cfg(15, 8) = 1; // ss_sales_price
    shuffle4_cfg(23, 16) = 2; // c_customer_sk
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

void get_cfg_dat_JOIN_INNER_TD_11586348_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#3558 = d_date_sk#3581))
    // Left Table: ListBuffer(ss_sold_date_sk#3558, ss_quantity#3568, ss_sales_price#3571, c_customer_sk#0)
    // Right Table: ListBuffer(d_date_sk#3581)
    // Output Table: ListBuffer(ss_quantity#3568, ss_sales_price#3571, c_customer_sk#0)
    // Node Depth: 11
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,2,3,-1,-1,-1,-1};
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
    shuffle1a_cfg(31, 24) = 2;
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
    shuffle2_cfg(7, 0) = 7; // ss_quantity
    shuffle2_cfg(15, 8) = 8; // ss_sales_price
    shuffle2_cfg(23, 16) = 6; // c_customer_sk
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
    shuffle3_cfg(7, 0) = 0; // ss_quantity
    shuffle3_cfg(15, 8) = 1; // ss_sales_price
    shuffle3_cfg(23, 16) = 2; // c_customer_sk
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
    shuffle4_cfg(7, 0) = 0; // ss_quantity
    shuffle4_cfg(15, 8) = 1; // ss_sales_price
    shuffle4_cfg(23, 16) = 2; // c_customer_sk
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

void get_cfg_dat_JOIN_INNER_TD_11161751_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#3558 = d_date_sk#3581))
    // Left Table: ListBuffer(ss_sold_date_sk#3558, ss_quantity#3568, ss_sales_price#3571, c_customer_sk#0)
    // Right Table: ListBuffer(d_date_sk#3581)
    // Output Table: ListBuffer(ss_quantity#3568, ss_sales_price#3571, c_customer_sk#0)
    // Node Depth: 11
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,2,3,-1,-1,-1,-1};
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
    shuffle1a_cfg(31, 24) = 2;
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
    shuffle2_cfg(7, 0) = 7; // ss_quantity
    shuffle2_cfg(15, 8) = 8; // ss_sales_price
    shuffle2_cfg(23, 16) = 6; // c_customer_sk
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
    shuffle3_cfg(7, 0) = 0; // ss_quantity
    shuffle3_cfg(15, 8) = 1; // ss_sales_price
    shuffle3_cfg(23, 16) = 2; // c_customer_sk
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
    shuffle4_cfg(7, 0) = 0; // ss_quantity
    shuffle4_cfg(15, 8) = 1; // ss_sales_price
    shuffle4_cfg(23, 16) = 2; // c_customer_sk
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

void get_cfg_dat_JOIN_INNER_TD_1137987_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#3558 = d_date_sk#3581))
    // Left Table: ListBuffer(ss_sold_date_sk#3558, ss_quantity#3568, ss_sales_price#3571, c_customer_sk#0)
    // Right Table: ListBuffer(d_date_sk#3581)
    // Output Table: ListBuffer(ss_quantity#3568, ss_sales_price#3571, c_customer_sk#0)
    // Node Depth: 11
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,2,3,-1,-1,-1,-1};
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
    shuffle1a_cfg(31, 24) = 2;
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
    shuffle2_cfg(7, 0) = 7; // ss_quantity
    shuffle2_cfg(15, 8) = 8; // ss_sales_price
    shuffle2_cfg(23, 16) = 6; // c_customer_sk
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
    shuffle3_cfg(7, 0) = 0; // ss_quantity
    shuffle3_cfg(15, 8) = 1; // ss_sales_price
    shuffle3_cfg(23, 16) = 2; // c_customer_sk
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
    shuffle4_cfg(7, 0) = 0; // ss_quantity
    shuffle4_cfg(15, 8) = 1; // ss_sales_price
    shuffle4_cfg(23, 16) = 2; // c_customer_sk
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

void get_cfg_dat_Aggregate_TD_10391355_gqe_aggr(ap_uint<32>* buf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_customer_sk#0, sum(CheckOverflow((promote_precision(cast(cast(ss_quantity#3568 as decimal(10,0)) as decimal(12,2))) * promote_precision(cast(ss_sales_price#3571 as decimal(12,2)))), DecimalType(18,2), true)) AS csales#3554)
    // Input Table: ListBuffer(ss_quantity#3568, ss_sales_price#3571, c_customer_sk#0)
    // Output Table: ListBuffer(csales#3554)
    // Node Depth: 10
    ap_uint<32>* config = buf;
    memset(config, 0, sizeof(ap_uint<32>) * 83);

    // eval0
    ap_uint<32> t;
    signed char id[] = {0,1,2,-1,-1,-1,-1,-1};
    for (int c = 0; c < 4; ++c) {
        t.range(8 * c + 7, 8 * c) = id[c];
    }
    config[0] = t;
    for (int c = 0; c < 4; ++c) {
        t.range(8 * c + 7, 8 * c) = id[c + 4];
    }
    config[1] = t;

    ap_uint<289> op_eval_0 = 0; // (ss_quantity#3568 * ss_sales_price#3571)
    xf::database::dynamicALUOPCompiler<uint32_t, uint32_t, uint32_t, uint32_t>("strm1*strm2", 0, 0, 0, 0, op_eval_0);
    for (int i = 0; i < 9; i++) {
        config[i + 2] = op_eval_0(32 * (i + 1) - 1, 32 * i);
    }
    config[11] = op_eval_0[288];

    // eval0 -> eval1
    // NO evaluation 1 in aggregation expression - eval1
    ap_int<64> shuffle1_cfg;
    shuffle1_cfg(7, 0) = 0; // ss_quantity
    shuffle1_cfg(15, 8) = 1; // ss_sales_price
    shuffle1_cfg(23, 16) = 2; // c_customer_sk#0
    shuffle1_cfg(31, 24) = 8; // csales
    shuffle1_cfg(39, 32) = -1;
    shuffle1_cfg(47, 40) = -1;
    shuffle1_cfg(55, 48) = -1;
    shuffle1_cfg(63, 56) = -1;
    config[67] = shuffle1_cfg(31, 0);
    config[68] = shuffle1_cfg(63, 32);

    ap_uint<289> op_eval_1 = 0; // NOP
    // eval1: NOP
    for (int i = 0; i < 9; i++) {
        config[i + 12] = op_eval_1(32 * (i + 1) - 1, 32 * i);
    }
    config[21] = op_eval_1[288];

    // eval1 -> filter
    ap_int<64> shuffle2_cfg;
    shuffle2_cfg(7, 0) = 0; // ss_quantity
    shuffle2_cfg(15, 8) = 1; // ss_sales_price
    shuffle2_cfg(23, 16) = 2; // c_customer_sk
    shuffle2_cfg(31, 24) = 3; // csales
    shuffle2_cfg(39, 32) = -1;
    shuffle2_cfg(47, 40) = -1;
    shuffle2_cfg(55, 48) = -1;
    shuffle2_cfg(63, 56) = -1;
    config[69] = shuffle2_cfg(31, 0);
    config[70] = shuffle2_cfg(63, 32);

    uint32_t fcfg[45];
    gen_pass_fcfg(fcfg);
    memcpy(&config[22], fcfg, sizeof(uint32_t) * 45);

    // filter -> groupBy
    ap_int<64> shuffle3_cfg;
    shuffle3_cfg(7, 0) = 2; // c_customer_sk#0
    shuffle3_cfg(15, 8) = -1;
    shuffle3_cfg(23, 16) = -1;
    shuffle3_cfg(31, 24) = -1;
    shuffle3_cfg(39, 32) = -1;
    shuffle3_cfg(47, 40) = -1;
    shuffle3_cfg(55, 48) = -1;
    shuffle3_cfg(63, 56) = -1;
    config[71] = shuffle3_cfg(31, 0);
    config[72] = shuffle3_cfg(63, 32);

    ap_int<64> shuffle4_cfg;
    shuffle4_cfg(7, 0) = 3; // csales#3554
    shuffle4_cfg(15, 8) = -1;
    shuffle4_cfg(23, 16) = -1;
    shuffle4_cfg(31, 24) = -1;
    shuffle4_cfg(39, 32) = -1;
    shuffle4_cfg(47, 40) = -1;
    shuffle4_cfg(55, 48) = -1;
    shuffle4_cfg(63, 56) = -1;
    config[73] = shuffle4_cfg(31, 0);
    config[74] = shuffle4_cfg(63, 32);

    ap_uint<4> aggr_op[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    aggr_op[0] = xf::database::enums::AOP_SUM;
    aggr_op[1] = xf::database::enums::AOP_SUM;
    aggr_op[2] = xf::database::enums::AOP_SUM;
    aggr_op[3] = xf::database::enums::AOP_SUM;
    aggr_op[4] = xf::database::enums::AOP_SUM;
    aggr_op[5] = xf::database::enums::AOP_SUM;
    aggr_op[6] = xf::database::enums::AOP_SUM;
    aggr_op[7] = xf::database::enums::AOP_SUM;
    config[75] = (aggr_op[7], aggr_op[6], aggr_op[5], aggr_op[4], aggr_op[3], aggr_op[2], aggr_op[1], aggr_op[0]);

    config[76] = 1; //# key col
    config[77] = 1; //# pld col
    config[78] = 0; //# aggr num

    ap_uint<8> merge[5];
    merge[0] = 0b10000000;
    merge[1] = 0;
    merge[2] = 0;
    merge[3] = 0b10000000;
    merge[4] = 0;
    config[79] = (1, merge[2], merge[1], merge[0]);
    config[80] = (0, merge[4], merge[3]);

    // aggr - demux mux direct_aggr
    config[81] = 0;

    // output - demux mux direct_aggr
    config[82] = 0xffff;
}

void get_cfg_dat_JOIN_INNER_TD_10264341_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_customer_sk#3612 = c_customer_sk#3632))
    // Left Table: ListBuffer(ss_customer_sk#3612, ss_quantity#3619, ss_sales_price#3622)
    // Right Table: ListBuffer(c_customer_sk#3632)
    // Output Table: ListBuffer(ss_quantity#3619, ss_sales_price#3622, c_customer_sk#3632)
    // Node Depth: 10
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
    shuffle2_cfg(7, 0) = 6; // ss_quantity
    shuffle2_cfg(15, 8) = 7; // ss_sales_price
    shuffle2_cfg(23, 16) = 12; // c_customer_sk
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
    shuffle3_cfg(7, 0) = 0; // ss_quantity
    shuffle3_cfg(15, 8) = 1; // ss_sales_price
    shuffle3_cfg(23, 16) = 2; // c_customer_sk
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
    shuffle4_cfg(7, 0) = 0; // ss_quantity
    shuffle4_cfg(15, 8) = 1; // ss_sales_price
    shuffle4_cfg(23, 16) = 2; // c_customer_sk
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

void get_cfg_dat_Aggregate_TD_10114900_gqe_aggr(ap_uint<32>* buf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_customer_sk#0, sum(CheckOverflow((promote_precision(cast(cast(ss_quantity#3568 as decimal(10,0)) as decimal(12,2))) * promote_precision(cast(ss_sales_price#3571 as decimal(12,2)))), DecimalType(18,2), true)) AS csales#3554)
    // Input Table: ListBuffer(ss_quantity#3568, ss_sales_price#3571, c_customer_sk#0)
    // Output Table: ListBuffer(csales#3554)
    // Node Depth: 10
    ap_uint<32>* config = buf;
    memset(config, 0, sizeof(ap_uint<32>) * 83);

    // eval0
    ap_uint<32> t;
    signed char id[] = {0,1,2,-1,-1,-1,-1,-1};
    for (int c = 0; c < 4; ++c) {
        t.range(8 * c + 7, 8 * c) = id[c];
    }
    config[0] = t;
    for (int c = 0; c < 4; ++c) {
        t.range(8 * c + 7, 8 * c) = id[c + 4];
    }
    config[1] = t;

    ap_uint<289> op_eval_0 = 0; // (ss_quantity#3568 * ss_sales_price#3571)
    xf::database::dynamicALUOPCompiler<uint32_t, uint32_t, uint32_t, uint32_t>("strm1*strm2", 0, 0, 0, 0, op_eval_0);
    for (int i = 0; i < 9; i++) {
        config[i + 2] = op_eval_0(32 * (i + 1) - 1, 32 * i);
    }
    config[11] = op_eval_0[288];

    // eval0 -> eval1
    // NO evaluation 1 in aggregation expression - eval1
    ap_int<64> shuffle1_cfg;
    shuffle1_cfg(7, 0) = 0; // ss_quantity
    shuffle1_cfg(15, 8) = 1; // ss_sales_price
    shuffle1_cfg(23, 16) = 2; // c_customer_sk#0
    shuffle1_cfg(31, 24) = 8; // csales
    shuffle1_cfg(39, 32) = -1;
    shuffle1_cfg(47, 40) = -1;
    shuffle1_cfg(55, 48) = -1;
    shuffle1_cfg(63, 56) = -1;
    config[67] = shuffle1_cfg(31, 0);
    config[68] = shuffle1_cfg(63, 32);

    ap_uint<289> op_eval_1 = 0; // NOP
    // eval1: NOP
    for (int i = 0; i < 9; i++) {
        config[i + 12] = op_eval_1(32 * (i + 1) - 1, 32 * i);
    }
    config[21] = op_eval_1[288];

    // eval1 -> filter
    ap_int<64> shuffle2_cfg;
    shuffle2_cfg(7, 0) = 0; // ss_quantity
    shuffle2_cfg(15, 8) = 1; // ss_sales_price
    shuffle2_cfg(23, 16) = 2; // c_customer_sk
    shuffle2_cfg(31, 24) = 3; // csales
    shuffle2_cfg(39, 32) = -1;
    shuffle2_cfg(47, 40) = -1;
    shuffle2_cfg(55, 48) = -1;
    shuffle2_cfg(63, 56) = -1;
    config[69] = shuffle2_cfg(31, 0);
    config[70] = shuffle2_cfg(63, 32);

    uint32_t fcfg[45];
    gen_pass_fcfg(fcfg);
    memcpy(&config[22], fcfg, sizeof(uint32_t) * 45);

    // filter -> groupBy
    ap_int<64> shuffle3_cfg;
    shuffle3_cfg(7, 0) = 2; // c_customer_sk#0
    shuffle3_cfg(15, 8) = -1;
    shuffle3_cfg(23, 16) = -1;
    shuffle3_cfg(31, 24) = -1;
    shuffle3_cfg(39, 32) = -1;
    shuffle3_cfg(47, 40) = -1;
    shuffle3_cfg(55, 48) = -1;
    shuffle3_cfg(63, 56) = -1;
    config[71] = shuffle3_cfg(31, 0);
    config[72] = shuffle3_cfg(63, 32);

    ap_int<64> shuffle4_cfg;
    shuffle4_cfg(7, 0) = 3; // csales#3554
    shuffle4_cfg(15, 8) = -1;
    shuffle4_cfg(23, 16) = -1;
    shuffle4_cfg(31, 24) = -1;
    shuffle4_cfg(39, 32) = -1;
    shuffle4_cfg(47, 40) = -1;
    shuffle4_cfg(55, 48) = -1;
    shuffle4_cfg(63, 56) = -1;
    config[73] = shuffle4_cfg(31, 0);
    config[74] = shuffle4_cfg(63, 32);

    ap_uint<4> aggr_op[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    aggr_op[0] = xf::database::enums::AOP_SUM;
    aggr_op[1] = xf::database::enums::AOP_SUM;
    aggr_op[2] = xf::database::enums::AOP_SUM;
    aggr_op[3] = xf::database::enums::AOP_SUM;
    aggr_op[4] = xf::database::enums::AOP_SUM;
    aggr_op[5] = xf::database::enums::AOP_SUM;
    aggr_op[6] = xf::database::enums::AOP_SUM;
    aggr_op[7] = xf::database::enums::AOP_SUM;
    config[75] = (aggr_op[7], aggr_op[6], aggr_op[5], aggr_op[4], aggr_op[3], aggr_op[2], aggr_op[1], aggr_op[0]);

    config[76] = 1; //# key col
    config[77] = 1; //# pld col
    config[78] = 0; //# aggr num

    ap_uint<8> merge[5];
    merge[0] = 0b10000000;
    merge[1] = 0;
    merge[2] = 0;
    merge[3] = 0b10000000;
    merge[4] = 0;
    config[79] = (1, merge[2], merge[1], merge[0]);
    config[80] = (0, merge[4], merge[3]);

    // aggr - demux mux direct_aggr
    config[81] = 0;

    // output - demux mux direct_aggr
    config[82] = 0xffff;
}

void get_cfg_dat_JOIN_INNER_TD_10979249_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_customer_sk#3612 = c_customer_sk#3632))
    // Left Table: ListBuffer(ss_customer_sk#3612, ss_quantity#3619, ss_sales_price#3622)
    // Right Table: ListBuffer(c_customer_sk#3632)
    // Output Table: ListBuffer(ss_quantity#3619, ss_sales_price#3622, c_customer_sk#3632)
    // Node Depth: 10
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
    shuffle2_cfg(7, 0) = 6; // ss_quantity
    shuffle2_cfg(15, 8) = 7; // ss_sales_price
    shuffle2_cfg(23, 16) = 12; // c_customer_sk
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
    shuffle3_cfg(7, 0) = 0; // ss_quantity
    shuffle3_cfg(15, 8) = 1; // ss_sales_price
    shuffle3_cfg(23, 16) = 2; // c_customer_sk
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
    shuffle4_cfg(7, 0) = 0; // ss_quantity
    shuffle4_cfg(15, 8) = 1; // ss_sales_price
    shuffle4_cfg(23, 16) = 2; // c_customer_sk
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

void get_cfg_dat_Aggregate_TD_10779337_gqe_aggr(ap_uint<32>* buf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_customer_sk#0, sum(CheckOverflow((promote_precision(cast(cast(ss_quantity#3568 as decimal(10,0)) as decimal(12,2))) * promote_precision(cast(ss_sales_price#3571 as decimal(12,2)))), DecimalType(18,2), true)) AS csales#3554)
    // Input Table: ListBuffer(ss_quantity#3568, ss_sales_price#3571, c_customer_sk#0)
    // Output Table: ListBuffer(csales#3554)
    // Node Depth: 10
    ap_uint<32>* config = buf;
    memset(config, 0, sizeof(ap_uint<32>) * 83);

    // eval0
    ap_uint<32> t;
    signed char id[] = {0,1,2,-1,-1,-1,-1,-1};
    for (int c = 0; c < 4; ++c) {
        t.range(8 * c + 7, 8 * c) = id[c];
    }
    config[0] = t;
    for (int c = 0; c < 4; ++c) {
        t.range(8 * c + 7, 8 * c) = id[c + 4];
    }
    config[1] = t;

    ap_uint<289> op_eval_0 = 0; // (ss_quantity#3568 * ss_sales_price#3571)
    xf::database::dynamicALUOPCompiler<uint32_t, uint32_t, uint32_t, uint32_t>("strm1*strm2", 0, 0, 0, 0, op_eval_0);
    for (int i = 0; i < 9; i++) {
        config[i + 2] = op_eval_0(32 * (i + 1) - 1, 32 * i);
    }
    config[11] = op_eval_0[288];

    // eval0 -> eval1
    // NO evaluation 1 in aggregation expression - eval1
    ap_int<64> shuffle1_cfg;
    shuffle1_cfg(7, 0) = 0; // ss_quantity
    shuffle1_cfg(15, 8) = 1; // ss_sales_price
    shuffle1_cfg(23, 16) = 2; // c_customer_sk#0
    shuffle1_cfg(31, 24) = 8; // csales
    shuffle1_cfg(39, 32) = -1;
    shuffle1_cfg(47, 40) = -1;
    shuffle1_cfg(55, 48) = -1;
    shuffle1_cfg(63, 56) = -1;
    config[67] = shuffle1_cfg(31, 0);
    config[68] = shuffle1_cfg(63, 32);

    ap_uint<289> op_eval_1 = 0; // NOP
    // eval1: NOP
    for (int i = 0; i < 9; i++) {
        config[i + 12] = op_eval_1(32 * (i + 1) - 1, 32 * i);
    }
    config[21] = op_eval_1[288];

    // eval1 -> filter
    ap_int<64> shuffle2_cfg;
    shuffle2_cfg(7, 0) = 0; // ss_quantity
    shuffle2_cfg(15, 8) = 1; // ss_sales_price
    shuffle2_cfg(23, 16) = 2; // c_customer_sk
    shuffle2_cfg(31, 24) = 3; // csales
    shuffle2_cfg(39, 32) = -1;
    shuffle2_cfg(47, 40) = -1;
    shuffle2_cfg(55, 48) = -1;
    shuffle2_cfg(63, 56) = -1;
    config[69] = shuffle2_cfg(31, 0);
    config[70] = shuffle2_cfg(63, 32);

    uint32_t fcfg[45];
    gen_pass_fcfg(fcfg);
    memcpy(&config[22], fcfg, sizeof(uint32_t) * 45);

    // filter -> groupBy
    ap_int<64> shuffle3_cfg;
    shuffle3_cfg(7, 0) = 2; // c_customer_sk#0
    shuffle3_cfg(15, 8) = -1;
    shuffle3_cfg(23, 16) = -1;
    shuffle3_cfg(31, 24) = -1;
    shuffle3_cfg(39, 32) = -1;
    shuffle3_cfg(47, 40) = -1;
    shuffle3_cfg(55, 48) = -1;
    shuffle3_cfg(63, 56) = -1;
    config[71] = shuffle3_cfg(31, 0);
    config[72] = shuffle3_cfg(63, 32);

    ap_int<64> shuffle4_cfg;
    shuffle4_cfg(7, 0) = 3; // csales#3554
    shuffle4_cfg(15, 8) = -1;
    shuffle4_cfg(23, 16) = -1;
    shuffle4_cfg(31, 24) = -1;
    shuffle4_cfg(39, 32) = -1;
    shuffle4_cfg(47, 40) = -1;
    shuffle4_cfg(55, 48) = -1;
    shuffle4_cfg(63, 56) = -1;
    config[73] = shuffle4_cfg(31, 0);
    config[74] = shuffle4_cfg(63, 32);

    ap_uint<4> aggr_op[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    aggr_op[0] = xf::database::enums::AOP_SUM;
    aggr_op[1] = xf::database::enums::AOP_SUM;
    aggr_op[2] = xf::database::enums::AOP_SUM;
    aggr_op[3] = xf::database::enums::AOP_SUM;
    aggr_op[4] = xf::database::enums::AOP_SUM;
    aggr_op[5] = xf::database::enums::AOP_SUM;
    aggr_op[6] = xf::database::enums::AOP_SUM;
    aggr_op[7] = xf::database::enums::AOP_SUM;
    config[75] = (aggr_op[7], aggr_op[6], aggr_op[5], aggr_op[4], aggr_op[3], aggr_op[2], aggr_op[1], aggr_op[0]);

    config[76] = 1; //# key col
    config[77] = 1; //# pld col
    config[78] = 0; //# aggr num

    ap_uint<8> merge[5];
    merge[0] = 0b10000000;
    merge[1] = 0;
    merge[2] = 0;
    merge[3] = 0b10000000;
    merge[4] = 0;
    config[79] = (1, merge[2], merge[1], merge[0]);
    config[80] = (0, merge[4], merge[3]);

    // aggr - demux mux direct_aggr
    config[81] = 0;

    // output - demux mux direct_aggr
    config[82] = 0xffff;
}

void get_cfg_dat_JOIN_INNER_TD_10548299_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_customer_sk#3612 = c_customer_sk#3632))
    // Left Table: ListBuffer(ss_customer_sk#3612, ss_quantity#3619, ss_sales_price#3622)
    // Right Table: ListBuffer(c_customer_sk#3632)
    // Output Table: ListBuffer(ss_quantity#3619, ss_sales_price#3622, c_customer_sk#3632)
    // Node Depth: 10
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
    shuffle2_cfg(7, 0) = 6; // ss_quantity
    shuffle2_cfg(15, 8) = 7; // ss_sales_price
    shuffle2_cfg(23, 16) = 12; // c_customer_sk
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
    shuffle3_cfg(7, 0) = 0; // ss_quantity
    shuffle3_cfg(15, 8) = 1; // ss_sales_price
    shuffle3_cfg(23, 16) = 2; // c_customer_sk
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
    shuffle4_cfg(7, 0) = 0; // ss_quantity
    shuffle4_cfg(15, 8) = 1; // ss_sales_price
    shuffle4_cfg(23, 16) = 2; // c_customer_sk
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

void get_cfg_dat_Aggregate_TD_10940044_gqe_aggr(ap_uint<32>* buf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_customer_sk#0, sum(CheckOverflow((promote_precision(cast(cast(ss_quantity#3568 as decimal(10,0)) as decimal(12,2))) * promote_precision(cast(ss_sales_price#3571 as decimal(12,2)))), DecimalType(18,2), true)) AS csales#3554)
    // Input Table: ListBuffer(ss_quantity#3568, ss_sales_price#3571, c_customer_sk#0)
    // Output Table: ListBuffer(csales#3554)
    // Node Depth: 10
    ap_uint<32>* config = buf;
    memset(config, 0, sizeof(ap_uint<32>) * 83);

    // eval0
    ap_uint<32> t;
    signed char id[] = {0,1,2,-1,-1,-1,-1,-1};
    for (int c = 0; c < 4; ++c) {
        t.range(8 * c + 7, 8 * c) = id[c];
    }
    config[0] = t;
    for (int c = 0; c < 4; ++c) {
        t.range(8 * c + 7, 8 * c) = id[c + 4];
    }
    config[1] = t;

    ap_uint<289> op_eval_0 = 0; // (ss_quantity#3568 * ss_sales_price#3571)
    xf::database::dynamicALUOPCompiler<uint32_t, uint32_t, uint32_t, uint32_t>("strm1*strm2", 0, 0, 0, 0, op_eval_0);
    for (int i = 0; i < 9; i++) {
        config[i + 2] = op_eval_0(32 * (i + 1) - 1, 32 * i);
    }
    config[11] = op_eval_0[288];

    // eval0 -> eval1
    // NO evaluation 1 in aggregation expression - eval1
    ap_int<64> shuffle1_cfg;
    shuffle1_cfg(7, 0) = 0; // ss_quantity
    shuffle1_cfg(15, 8) = 1; // ss_sales_price
    shuffle1_cfg(23, 16) = 2; // c_customer_sk#0
    shuffle1_cfg(31, 24) = 8; // csales
    shuffle1_cfg(39, 32) = -1;
    shuffle1_cfg(47, 40) = -1;
    shuffle1_cfg(55, 48) = -1;
    shuffle1_cfg(63, 56) = -1;
    config[67] = shuffle1_cfg(31, 0);
    config[68] = shuffle1_cfg(63, 32);

    ap_uint<289> op_eval_1 = 0; // NOP
    // eval1: NOP
    for (int i = 0; i < 9; i++) {
        config[i + 12] = op_eval_1(32 * (i + 1) - 1, 32 * i);
    }
    config[21] = op_eval_1[288];

    // eval1 -> filter
    ap_int<64> shuffle2_cfg;
    shuffle2_cfg(7, 0) = 0; // ss_quantity
    shuffle2_cfg(15, 8) = 1; // ss_sales_price
    shuffle2_cfg(23, 16) = 2; // c_customer_sk
    shuffle2_cfg(31, 24) = 3; // csales
    shuffle2_cfg(39, 32) = -1;
    shuffle2_cfg(47, 40) = -1;
    shuffle2_cfg(55, 48) = -1;
    shuffle2_cfg(63, 56) = -1;
    config[69] = shuffle2_cfg(31, 0);
    config[70] = shuffle2_cfg(63, 32);

    uint32_t fcfg[45];
    gen_pass_fcfg(fcfg);
    memcpy(&config[22], fcfg, sizeof(uint32_t) * 45);

    // filter -> groupBy
    ap_int<64> shuffle3_cfg;
    shuffle3_cfg(7, 0) = 2; // c_customer_sk#0
    shuffle3_cfg(15, 8) = -1;
    shuffle3_cfg(23, 16) = -1;
    shuffle3_cfg(31, 24) = -1;
    shuffle3_cfg(39, 32) = -1;
    shuffle3_cfg(47, 40) = -1;
    shuffle3_cfg(55, 48) = -1;
    shuffle3_cfg(63, 56) = -1;
    config[71] = shuffle3_cfg(31, 0);
    config[72] = shuffle3_cfg(63, 32);

    ap_int<64> shuffle4_cfg;
    shuffle4_cfg(7, 0) = 3; // csales#3554
    shuffle4_cfg(15, 8) = -1;
    shuffle4_cfg(23, 16) = -1;
    shuffle4_cfg(31, 24) = -1;
    shuffle4_cfg(39, 32) = -1;
    shuffle4_cfg(47, 40) = -1;
    shuffle4_cfg(55, 48) = -1;
    shuffle4_cfg(63, 56) = -1;
    config[73] = shuffle4_cfg(31, 0);
    config[74] = shuffle4_cfg(63, 32);

    ap_uint<4> aggr_op[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    aggr_op[0] = xf::database::enums::AOP_SUM;
    aggr_op[1] = xf::database::enums::AOP_SUM;
    aggr_op[2] = xf::database::enums::AOP_SUM;
    aggr_op[3] = xf::database::enums::AOP_SUM;
    aggr_op[4] = xf::database::enums::AOP_SUM;
    aggr_op[5] = xf::database::enums::AOP_SUM;
    aggr_op[6] = xf::database::enums::AOP_SUM;
    aggr_op[7] = xf::database::enums::AOP_SUM;
    config[75] = (aggr_op[7], aggr_op[6], aggr_op[5], aggr_op[4], aggr_op[3], aggr_op[2], aggr_op[1], aggr_op[0]);

    config[76] = 1; //# key col
    config[77] = 1; //# pld col
    config[78] = 0; //# aggr num

    ap_uint<8> merge[5];
    merge[0] = 0b10000000;
    merge[1] = 0;
    merge[2] = 0;
    merge[3] = 0b10000000;
    merge[4] = 0;
    config[79] = (1, merge[2], merge[1], merge[0]);
    config[80] = (0, merge[4], merge[3]);

    // aggr - demux mux direct_aggr
    config[81] = 0;

    // output - demux mux direct_aggr
    config[82] = 0xffff;
}

void get_cfg_dat_JOIN_INNER_TD_10122185_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_customer_sk#3612 = c_customer_sk#3632))
    // Left Table: ListBuffer(ss_customer_sk#3612, ss_quantity#3619, ss_sales_price#3622)
    // Right Table: ListBuffer(c_customer_sk#3632)
    // Output Table: ListBuffer(ss_quantity#3619, ss_sales_price#3622, c_customer_sk#3632)
    // Node Depth: 10
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
    shuffle2_cfg(7, 0) = 6; // ss_quantity
    shuffle2_cfg(15, 8) = 7; // ss_sales_price
    shuffle2_cfg(23, 16) = 12; // c_customer_sk
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
    shuffle3_cfg(7, 0) = 0; // ss_quantity
    shuffle3_cfg(15, 8) = 1; // ss_sales_price
    shuffle3_cfg(23, 16) = 2; // c_customer_sk
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
    shuffle4_cfg(7, 0) = 0; // ss_quantity
    shuffle4_cfg(15, 8) = 1; // ss_sales_price
    shuffle4_cfg(23, 16) = 2; // c_customer_sk
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

void get_cfg_dat_Aggregate_TD_9533960_gqe_aggr(ap_uint<32>* buf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_customer_sk#3632, sum(CheckOverflow((promote_precision(cast(cast(ss_quantity#3619 as decimal(10,0)) as decimal(12,2))) * promote_precision(cast(ss_sales_price#3622 as decimal(12,2)))), DecimalType(18,2), true)) AS ssales#3556)
    // Input Table: ListBuffer(ss_quantity#3619, ss_sales_price#3622, c_customer_sk#3632)
    // Output Table: ListBuffer(c_customer_sk#3632, ssales#3556)
    // Node Depth: 9
    ap_uint<32>* config = buf;
    memset(config, 0, sizeof(ap_uint<32>) * 83);

    // eval0
    ap_uint<32> t;
    signed char id[] = {0,1,2,-1,-1,-1,-1,-1};
    for (int c = 0; c < 4; ++c) {
        t.range(8 * c + 7, 8 * c) = id[c];
    }
    config[0] = t;
    for (int c = 0; c < 4; ++c) {
        t.range(8 * c + 7, 8 * c) = id[c + 4];
    }
    config[1] = t;

    ap_uint<289> op_eval_0 = 0; // (ss_quantity#3619 * ss_sales_price#3622)
    xf::database::dynamicALUOPCompiler<uint32_t, uint32_t, uint32_t, uint32_t>("strm1*strm2", 0, 0, 0, 0, op_eval_0);
    for (int i = 0; i < 9; i++) {
        config[i + 2] = op_eval_0(32 * (i + 1) - 1, 32 * i);
    }
    config[11] = op_eval_0[288];

    // eval0 -> eval1
    // NO evaluation 1 in aggregation expression - eval1
    ap_int<64> shuffle1_cfg;
    shuffle1_cfg(7, 0) = 0; // ss_quantity
    shuffle1_cfg(15, 8) = 1; // ss_sales_price
    shuffle1_cfg(23, 16) = 2; // c_customer_sk#3632
    shuffle1_cfg(31, 24) = 8; // ssales
    shuffle1_cfg(39, 32) = -1;
    shuffle1_cfg(47, 40) = -1;
    shuffle1_cfg(55, 48) = -1;
    shuffle1_cfg(63, 56) = -1;
    config[67] = shuffle1_cfg(31, 0);
    config[68] = shuffle1_cfg(63, 32);

    ap_uint<289> op_eval_1 = 0; // NOP
    // eval1: NOP
    for (int i = 0; i < 9; i++) {
        config[i + 12] = op_eval_1(32 * (i + 1) - 1, 32 * i);
    }
    config[21] = op_eval_1[288];

    // eval1 -> filter
    ap_int<64> shuffle2_cfg;
    shuffle2_cfg(7, 0) = 0; // ss_quantity
    shuffle2_cfg(15, 8) = 1; // ss_sales_price
    shuffle2_cfg(23, 16) = 2; // c_customer_sk
    shuffle2_cfg(31, 24) = 3; // ssales
    shuffle2_cfg(39, 32) = -1;
    shuffle2_cfg(47, 40) = -1;
    shuffle2_cfg(55, 48) = -1;
    shuffle2_cfg(63, 56) = -1;
    config[69] = shuffle2_cfg(31, 0);
    config[70] = shuffle2_cfg(63, 32);

    uint32_t fcfg[45];
    gen_pass_fcfg(fcfg);
    memcpy(&config[22], fcfg, sizeof(uint32_t) * 45);

    // filter -> groupBy
    ap_int<64> shuffle3_cfg;
    shuffle3_cfg(7, 0) = 2; // c_customer_sk#3632
    shuffle3_cfg(15, 8) = -1;
    shuffle3_cfg(23, 16) = -1;
    shuffle3_cfg(31, 24) = -1;
    shuffle3_cfg(39, 32) = -1;
    shuffle3_cfg(47, 40) = -1;
    shuffle3_cfg(55, 48) = -1;
    shuffle3_cfg(63, 56) = -1;
    config[71] = shuffle3_cfg(31, 0);
    config[72] = shuffle3_cfg(63, 32);

    ap_int<64> shuffle4_cfg;
    shuffle4_cfg(7, 0) = 3; // ssales#3556
    shuffle4_cfg(15, 8) = -1;
    shuffle4_cfg(23, 16) = -1;
    shuffle4_cfg(31, 24) = -1;
    shuffle4_cfg(39, 32) = -1;
    shuffle4_cfg(47, 40) = -1;
    shuffle4_cfg(55, 48) = -1;
    shuffle4_cfg(63, 56) = -1;
    config[73] = shuffle4_cfg(31, 0);
    config[74] = shuffle4_cfg(63, 32);

    ap_uint<4> aggr_op[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    aggr_op[0] = xf::database::enums::AOP_SUM;
    aggr_op[1] = xf::database::enums::AOP_SUM;
    aggr_op[2] = xf::database::enums::AOP_SUM;
    aggr_op[3] = xf::database::enums::AOP_SUM;
    aggr_op[4] = xf::database::enums::AOP_SUM;
    aggr_op[5] = xf::database::enums::AOP_SUM;
    aggr_op[6] = xf::database::enums::AOP_SUM;
    aggr_op[7] = xf::database::enums::AOP_SUM;
    config[75] = (aggr_op[7], aggr_op[6], aggr_op[5], aggr_op[4], aggr_op[3], aggr_op[2], aggr_op[1], aggr_op[0]);

    config[76] = 1; //# key col
    config[77] = 1; //# pld col
    config[78] = 0; //# aggr num

    ap_uint<8> merge[5];
    merge[0] = 0b10000000;
    merge[1] = 0;
    merge[2] = 0;
    merge[3] = 0b10000000;
    merge[4] = 0;
    config[79] = (1, merge[2], merge[1], merge[0]);
    config[80] = (0, merge[4], merge[3]);

    // aggr - demux mux direct_aggr
    config[81] = 0;

    // output - demux mux direct_aggr
    config[82] = 0xffff;
}

void get_cfg_dat_Aggregate_TD_9948690_gqe_aggr(ap_uint<32>* buf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_customer_sk#3632, sum(CheckOverflow((promote_precision(cast(cast(ss_quantity#3619 as decimal(10,0)) as decimal(12,2))) * promote_precision(cast(ss_sales_price#3622 as decimal(12,2)))), DecimalType(18,2), true)) AS ssales#3556)
    // Input Table: ListBuffer(ss_quantity#3619, ss_sales_price#3622, c_customer_sk#3632)
    // Output Table: ListBuffer(c_customer_sk#3632, ssales#3556)
    // Node Depth: 9
    ap_uint<32>* config = buf;
    memset(config, 0, sizeof(ap_uint<32>) * 83);

    // eval0
    ap_uint<32> t;
    signed char id[] = {0,1,2,-1,-1,-1,-1,-1};
    for (int c = 0; c < 4; ++c) {
        t.range(8 * c + 7, 8 * c) = id[c];
    }
    config[0] = t;
    for (int c = 0; c < 4; ++c) {
        t.range(8 * c + 7, 8 * c) = id[c + 4];
    }
    config[1] = t;

    ap_uint<289> op_eval_0 = 0; // (ss_quantity#3619 * ss_sales_price#3622)
    xf::database::dynamicALUOPCompiler<uint32_t, uint32_t, uint32_t, uint32_t>("strm1*strm2", 0, 0, 0, 0, op_eval_0);
    for (int i = 0; i < 9; i++) {
        config[i + 2] = op_eval_0(32 * (i + 1) - 1, 32 * i);
    }
    config[11] = op_eval_0[288];

    // eval0 -> eval1
    // NO evaluation 1 in aggregation expression - eval1
    ap_int<64> shuffle1_cfg;
    shuffle1_cfg(7, 0) = 0; // ss_quantity
    shuffle1_cfg(15, 8) = 1; // ss_sales_price
    shuffle1_cfg(23, 16) = 2; // c_customer_sk#3632
    shuffle1_cfg(31, 24) = 8; // ssales
    shuffle1_cfg(39, 32) = -1;
    shuffle1_cfg(47, 40) = -1;
    shuffle1_cfg(55, 48) = -1;
    shuffle1_cfg(63, 56) = -1;
    config[67] = shuffle1_cfg(31, 0);
    config[68] = shuffle1_cfg(63, 32);

    ap_uint<289> op_eval_1 = 0; // NOP
    // eval1: NOP
    for (int i = 0; i < 9; i++) {
        config[i + 12] = op_eval_1(32 * (i + 1) - 1, 32 * i);
    }
    config[21] = op_eval_1[288];

    // eval1 -> filter
    ap_int<64> shuffle2_cfg;
    shuffle2_cfg(7, 0) = 0; // ss_quantity
    shuffle2_cfg(15, 8) = 1; // ss_sales_price
    shuffle2_cfg(23, 16) = 2; // c_customer_sk
    shuffle2_cfg(31, 24) = 3; // ssales
    shuffle2_cfg(39, 32) = -1;
    shuffle2_cfg(47, 40) = -1;
    shuffle2_cfg(55, 48) = -1;
    shuffle2_cfg(63, 56) = -1;
    config[69] = shuffle2_cfg(31, 0);
    config[70] = shuffle2_cfg(63, 32);

    uint32_t fcfg[45];
    gen_pass_fcfg(fcfg);
    memcpy(&config[22], fcfg, sizeof(uint32_t) * 45);

    // filter -> groupBy
    ap_int<64> shuffle3_cfg;
    shuffle3_cfg(7, 0) = 2; // c_customer_sk#3632
    shuffle3_cfg(15, 8) = -1;
    shuffle3_cfg(23, 16) = -1;
    shuffle3_cfg(31, 24) = -1;
    shuffle3_cfg(39, 32) = -1;
    shuffle3_cfg(47, 40) = -1;
    shuffle3_cfg(55, 48) = -1;
    shuffle3_cfg(63, 56) = -1;
    config[71] = shuffle3_cfg(31, 0);
    config[72] = shuffle3_cfg(63, 32);

    ap_int<64> shuffle4_cfg;
    shuffle4_cfg(7, 0) = 3; // ssales#3556
    shuffle4_cfg(15, 8) = -1;
    shuffle4_cfg(23, 16) = -1;
    shuffle4_cfg(31, 24) = -1;
    shuffle4_cfg(39, 32) = -1;
    shuffle4_cfg(47, 40) = -1;
    shuffle4_cfg(55, 48) = -1;
    shuffle4_cfg(63, 56) = -1;
    config[73] = shuffle4_cfg(31, 0);
    config[74] = shuffle4_cfg(63, 32);

    ap_uint<4> aggr_op[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    aggr_op[0] = xf::database::enums::AOP_SUM;
    aggr_op[1] = xf::database::enums::AOP_SUM;
    aggr_op[2] = xf::database::enums::AOP_SUM;
    aggr_op[3] = xf::database::enums::AOP_SUM;
    aggr_op[4] = xf::database::enums::AOP_SUM;
    aggr_op[5] = xf::database::enums::AOP_SUM;
    aggr_op[6] = xf::database::enums::AOP_SUM;
    aggr_op[7] = xf::database::enums::AOP_SUM;
    config[75] = (aggr_op[7], aggr_op[6], aggr_op[5], aggr_op[4], aggr_op[3], aggr_op[2], aggr_op[1], aggr_op[0]);

    config[76] = 1; //# key col
    config[77] = 1; //# pld col
    config[78] = 0; //# aggr num

    ap_uint<8> merge[5];
    merge[0] = 0b10000000;
    merge[1] = 0;
    merge[2] = 0;
    merge[3] = 0b10000000;
    merge[4] = 0;
    config[79] = (1, merge[2], merge[1], merge[0]);
    config[80] = (0, merge[4], merge[3]);

    // aggr - demux mux direct_aggr
    config[81] = 0;

    // output - demux mux direct_aggr
    config[82] = 0xffff;
}

void get_cfg_dat_Aggregate_TD_9394832_gqe_aggr(ap_uint<32>* buf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_customer_sk#3632, sum(CheckOverflow((promote_precision(cast(cast(ss_quantity#3619 as decimal(10,0)) as decimal(12,2))) * promote_precision(cast(ss_sales_price#3622 as decimal(12,2)))), DecimalType(18,2), true)) AS ssales#3556)
    // Input Table: ListBuffer(ss_quantity#3619, ss_sales_price#3622, c_customer_sk#3632)
    // Output Table: ListBuffer(c_customer_sk#3632, ssales#3556)
    // Node Depth: 9
    ap_uint<32>* config = buf;
    memset(config, 0, sizeof(ap_uint<32>) * 83);

    // eval0
    ap_uint<32> t;
    signed char id[] = {0,1,2,-1,-1,-1,-1,-1};
    for (int c = 0; c < 4; ++c) {
        t.range(8 * c + 7, 8 * c) = id[c];
    }
    config[0] = t;
    for (int c = 0; c < 4; ++c) {
        t.range(8 * c + 7, 8 * c) = id[c + 4];
    }
    config[1] = t;

    ap_uint<289> op_eval_0 = 0; // (ss_quantity#3619 * ss_sales_price#3622)
    xf::database::dynamicALUOPCompiler<uint32_t, uint32_t, uint32_t, uint32_t>("strm1*strm2", 0, 0, 0, 0, op_eval_0);
    for (int i = 0; i < 9; i++) {
        config[i + 2] = op_eval_0(32 * (i + 1) - 1, 32 * i);
    }
    config[11] = op_eval_0[288];

    // eval0 -> eval1
    // NO evaluation 1 in aggregation expression - eval1
    ap_int<64> shuffle1_cfg;
    shuffle1_cfg(7, 0) = 0; // ss_quantity
    shuffle1_cfg(15, 8) = 1; // ss_sales_price
    shuffle1_cfg(23, 16) = 2; // c_customer_sk#3632
    shuffle1_cfg(31, 24) = 8; // ssales
    shuffle1_cfg(39, 32) = -1;
    shuffle1_cfg(47, 40) = -1;
    shuffle1_cfg(55, 48) = -1;
    shuffle1_cfg(63, 56) = -1;
    config[67] = shuffle1_cfg(31, 0);
    config[68] = shuffle1_cfg(63, 32);

    ap_uint<289> op_eval_1 = 0; // NOP
    // eval1: NOP
    for (int i = 0; i < 9; i++) {
        config[i + 12] = op_eval_1(32 * (i + 1) - 1, 32 * i);
    }
    config[21] = op_eval_1[288];

    // eval1 -> filter
    ap_int<64> shuffle2_cfg;
    shuffle2_cfg(7, 0) = 0; // ss_quantity
    shuffle2_cfg(15, 8) = 1; // ss_sales_price
    shuffle2_cfg(23, 16) = 2; // c_customer_sk
    shuffle2_cfg(31, 24) = 3; // ssales
    shuffle2_cfg(39, 32) = -1;
    shuffle2_cfg(47, 40) = -1;
    shuffle2_cfg(55, 48) = -1;
    shuffle2_cfg(63, 56) = -1;
    config[69] = shuffle2_cfg(31, 0);
    config[70] = shuffle2_cfg(63, 32);

    uint32_t fcfg[45];
    gen_pass_fcfg(fcfg);
    memcpy(&config[22], fcfg, sizeof(uint32_t) * 45);

    // filter -> groupBy
    ap_int<64> shuffle3_cfg;
    shuffle3_cfg(7, 0) = 2; // c_customer_sk#3632
    shuffle3_cfg(15, 8) = -1;
    shuffle3_cfg(23, 16) = -1;
    shuffle3_cfg(31, 24) = -1;
    shuffle3_cfg(39, 32) = -1;
    shuffle3_cfg(47, 40) = -1;
    shuffle3_cfg(55, 48) = -1;
    shuffle3_cfg(63, 56) = -1;
    config[71] = shuffle3_cfg(31, 0);
    config[72] = shuffle3_cfg(63, 32);

    ap_int<64> shuffle4_cfg;
    shuffle4_cfg(7, 0) = 3; // ssales#3556
    shuffle4_cfg(15, 8) = -1;
    shuffle4_cfg(23, 16) = -1;
    shuffle4_cfg(31, 24) = -1;
    shuffle4_cfg(39, 32) = -1;
    shuffle4_cfg(47, 40) = -1;
    shuffle4_cfg(55, 48) = -1;
    shuffle4_cfg(63, 56) = -1;
    config[73] = shuffle4_cfg(31, 0);
    config[74] = shuffle4_cfg(63, 32);

    ap_uint<4> aggr_op[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    aggr_op[0] = xf::database::enums::AOP_SUM;
    aggr_op[1] = xf::database::enums::AOP_SUM;
    aggr_op[2] = xf::database::enums::AOP_SUM;
    aggr_op[3] = xf::database::enums::AOP_SUM;
    aggr_op[4] = xf::database::enums::AOP_SUM;
    aggr_op[5] = xf::database::enums::AOP_SUM;
    aggr_op[6] = xf::database::enums::AOP_SUM;
    aggr_op[7] = xf::database::enums::AOP_SUM;
    config[75] = (aggr_op[7], aggr_op[6], aggr_op[5], aggr_op[4], aggr_op[3], aggr_op[2], aggr_op[1], aggr_op[0]);

    config[76] = 1; //# key col
    config[77] = 1; //# pld col
    config[78] = 0; //# aggr num

    ap_uint<8> merge[5];
    merge[0] = 0b10000000;
    merge[1] = 0;
    merge[2] = 0;
    merge[3] = 0b10000000;
    merge[4] = 0;
    config[79] = (1, merge[2], merge[1], merge[0]);
    config[80] = (0, merge[4], merge[3]);

    // aggr - demux mux direct_aggr
    config[81] = 0;

    // output - demux mux direct_aggr
    config[82] = 0xffff;
}

void get_cfg_dat_Aggregate_TD_9241296_gqe_aggr(ap_uint<32>* buf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_customer_sk#3632, sum(CheckOverflow((promote_precision(cast(cast(ss_quantity#3619 as decimal(10,0)) as decimal(12,2))) * promote_precision(cast(ss_sales_price#3622 as decimal(12,2)))), DecimalType(18,2), true)) AS ssales#3556)
    // Input Table: ListBuffer(ss_quantity#3619, ss_sales_price#3622, c_customer_sk#3632)
    // Output Table: ListBuffer(c_customer_sk#3632, ssales#3556)
    // Node Depth: 9
    ap_uint<32>* config = buf;
    memset(config, 0, sizeof(ap_uint<32>) * 83);

    // eval0
    ap_uint<32> t;
    signed char id[] = {0,1,2,-1,-1,-1,-1,-1};
    for (int c = 0; c < 4; ++c) {
        t.range(8 * c + 7, 8 * c) = id[c];
    }
    config[0] = t;
    for (int c = 0; c < 4; ++c) {
        t.range(8 * c + 7, 8 * c) = id[c + 4];
    }
    config[1] = t;

    ap_uint<289> op_eval_0 = 0; // (ss_quantity#3619 * ss_sales_price#3622)
    xf::database::dynamicALUOPCompiler<uint32_t, uint32_t, uint32_t, uint32_t>("strm1*strm2", 0, 0, 0, 0, op_eval_0);
    for (int i = 0; i < 9; i++) {
        config[i + 2] = op_eval_0(32 * (i + 1) - 1, 32 * i);
    }
    config[11] = op_eval_0[288];

    // eval0 -> eval1
    // NO evaluation 1 in aggregation expression - eval1
    ap_int<64> shuffle1_cfg;
    shuffle1_cfg(7, 0) = 0; // ss_quantity
    shuffle1_cfg(15, 8) = 1; // ss_sales_price
    shuffle1_cfg(23, 16) = 2; // c_customer_sk#3632
    shuffle1_cfg(31, 24) = 8; // ssales
    shuffle1_cfg(39, 32) = -1;
    shuffle1_cfg(47, 40) = -1;
    shuffle1_cfg(55, 48) = -1;
    shuffle1_cfg(63, 56) = -1;
    config[67] = shuffle1_cfg(31, 0);
    config[68] = shuffle1_cfg(63, 32);

    ap_uint<289> op_eval_1 = 0; // NOP
    // eval1: NOP
    for (int i = 0; i < 9; i++) {
        config[i + 12] = op_eval_1(32 * (i + 1) - 1, 32 * i);
    }
    config[21] = op_eval_1[288];

    // eval1 -> filter
    ap_int<64> shuffle2_cfg;
    shuffle2_cfg(7, 0) = 0; // ss_quantity
    shuffle2_cfg(15, 8) = 1; // ss_sales_price
    shuffle2_cfg(23, 16) = 2; // c_customer_sk
    shuffle2_cfg(31, 24) = 3; // ssales
    shuffle2_cfg(39, 32) = -1;
    shuffle2_cfg(47, 40) = -1;
    shuffle2_cfg(55, 48) = -1;
    shuffle2_cfg(63, 56) = -1;
    config[69] = shuffle2_cfg(31, 0);
    config[70] = shuffle2_cfg(63, 32);

    uint32_t fcfg[45];
    gen_pass_fcfg(fcfg);
    memcpy(&config[22], fcfg, sizeof(uint32_t) * 45);

    // filter -> groupBy
    ap_int<64> shuffle3_cfg;
    shuffle3_cfg(7, 0) = 2; // c_customer_sk#3632
    shuffle3_cfg(15, 8) = -1;
    shuffle3_cfg(23, 16) = -1;
    shuffle3_cfg(31, 24) = -1;
    shuffle3_cfg(39, 32) = -1;
    shuffle3_cfg(47, 40) = -1;
    shuffle3_cfg(55, 48) = -1;
    shuffle3_cfg(63, 56) = -1;
    config[71] = shuffle3_cfg(31, 0);
    config[72] = shuffle3_cfg(63, 32);

    ap_int<64> shuffle4_cfg;
    shuffle4_cfg(7, 0) = 3; // ssales#3556
    shuffle4_cfg(15, 8) = -1;
    shuffle4_cfg(23, 16) = -1;
    shuffle4_cfg(31, 24) = -1;
    shuffle4_cfg(39, 32) = -1;
    shuffle4_cfg(47, 40) = -1;
    shuffle4_cfg(55, 48) = -1;
    shuffle4_cfg(63, 56) = -1;
    config[73] = shuffle4_cfg(31, 0);
    config[74] = shuffle4_cfg(63, 32);

    ap_uint<4> aggr_op[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    aggr_op[0] = xf::database::enums::AOP_SUM;
    aggr_op[1] = xf::database::enums::AOP_SUM;
    aggr_op[2] = xf::database::enums::AOP_SUM;
    aggr_op[3] = xf::database::enums::AOP_SUM;
    aggr_op[4] = xf::database::enums::AOP_SUM;
    aggr_op[5] = xf::database::enums::AOP_SUM;
    aggr_op[6] = xf::database::enums::AOP_SUM;
    aggr_op[7] = xf::database::enums::AOP_SUM;
    config[75] = (aggr_op[7], aggr_op[6], aggr_op[5], aggr_op[4], aggr_op[3], aggr_op[2], aggr_op[1], aggr_op[0]);

    config[76] = 1; //# key col
    config[77] = 1; //# pld col
    config[78] = 0; //# aggr num

    ap_uint<8> merge[5];
    merge[0] = 0b10000000;
    merge[1] = 0;
    merge[2] = 0;
    merge[3] = 0b10000000;
    merge[4] = 0;
    config[79] = (1, merge[2], merge[1], merge[0]);
    config[80] = (0, merge[4], merge[3]);

    // aggr - demux mux direct_aggr
    config[81] = 0;

    // output - demux mux direct_aggr
    config[82] = 0xffff;
}

void get_cfg_dat_JOIN_LEFTSEMI_TD_8435885_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTSEMI
    // Operation: ListBuffer((ws_item_sk#732 = item_sk#3551))
    // Left Table: ListBuffer(item_sk#3551)
    // Right Table: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_bill_customer_sk#733, ws_quantity#747, ws_list_price#749)
    // Output Table: ListBuffer(ws_sold_date_sk#729, ws_bill_customer_sk#733, ws_quantity#747, ws_list_price#749)
    // Node Depth: 8
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,-1,-1,-1,-1,-1,-1,-1};
    for (int c = 0; c < 8; ++c) {
        t.range(56 + 8 * c + 7, 56 + 8 * c) = id_a[c];
    }
    // filter tbl_a config
    uint32_t cfga[45];
    gen_pass_fcfg(cfga);
    memcpy(&b[3], cfga, sizeof(uint32_t) * 45);

    // input table b
    signed char id_b[] = {0,1,2,3,4,-1,-1,-1};
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
    shuffle1a_cfg(15, 8) = -1;
    shuffle1a_cfg(23, 16) = -1;
    shuffle1a_cfg(31, 24) = -1;
    shuffle1a_cfg(39, 32) = -1;
    shuffle1a_cfg(47, 40) = -1;
    shuffle1a_cfg(55, 48) = -1;
    shuffle1a_cfg(63, 56) = -1;

    //stream shuffle 1b
    ap_int<64> shuffle1b_cfg;
    shuffle1b_cfg(7, 0) = 1;
    shuffle1b_cfg(15, 8) = 3;
    shuffle1b_cfg(23, 16) = 0;
    shuffle1b_cfg(31, 24) = 2;
    shuffle1b_cfg(39, 32) = 4;
    shuffle1b_cfg(47, 40) = -1;
    shuffle1b_cfg(55, 48) = -1;
    shuffle1b_cfg(63, 56) = -1;

    // join config
    t.set_bit(0, 1);    // join
    t.set_bit(2, 0);    // dual-key
    t.range(5, 3) = 1;  // hash join flag = 0 for normal, 1 for semi, 2 for anti

    //--------------eval0--------------
    //stream shuffle 2
    ap_int<64> shuffle2_cfg;
    shuffle2_cfg(7, 0) = 1; // ws_sold_date_sk
    shuffle2_cfg(15, 8) = 2; // ws_bill_customer_sk
    shuffle2_cfg(23, 16) = 0; // ws_quantity
    shuffle2_cfg(31, 24) = 3; // ws_list_price
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
    shuffle3_cfg(7, 0) = 0; // ws_sold_date_sk
    shuffle3_cfg(15, 8) = 1; // ws_bill_customer_sk
    shuffle3_cfg(23, 16) = 2; // ws_quantity
    shuffle3_cfg(31, 24) = 3; // ws_list_price
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
    shuffle4_cfg(7, 0) = 0; // ws_sold_date_sk
    shuffle4_cfg(15, 8) = 1; // ws_bill_customer_sk
    shuffle4_cfg(23, 16) = 2; // ws_quantity
    shuffle4_cfg(31, 24) = 3; // ws_list_price
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

void get_cfg_dat_JOIN_LEFTSEMI_TD_8187296_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTSEMI
    // Operation: ListBuffer((cs_item_sk#1119 = item_sk#3551))
    // Left Table: ListBuffer(item_sk#3551)
    // Right Table: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_item_sk#1119, cs_quantity#1122, cs_list_price#1124)
    // Output Table: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_quantity#1122, cs_list_price#1124)
    // Node Depth: 8
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,-1,-1,-1,-1,-1,-1,-1};
    for (int c = 0; c < 8; ++c) {
        t.range(56 + 8 * c + 7, 56 + 8 * c) = id_a[c];
    }
    // filter tbl_a config
    uint32_t cfga[45];
    gen_pass_fcfg(cfga);
    memcpy(&b[3], cfga, sizeof(uint32_t) * 45);

    // input table b
    signed char id_b[] = {0,1,2,3,4,-1,-1,-1};
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
    shuffle1a_cfg(15, 8) = -1;
    shuffle1a_cfg(23, 16) = -1;
    shuffle1a_cfg(31, 24) = -1;
    shuffle1a_cfg(39, 32) = -1;
    shuffle1a_cfg(47, 40) = -1;
    shuffle1a_cfg(55, 48) = -1;
    shuffle1a_cfg(63, 56) = -1;

    //stream shuffle 1b
    ap_int<64> shuffle1b_cfg;
    shuffle1b_cfg(7, 0) = 2;
    shuffle1b_cfg(15, 8) = 0;
    shuffle1b_cfg(23, 16) = 3;
    shuffle1b_cfg(31, 24) = 4;
    shuffle1b_cfg(39, 32) = 1;
    shuffle1b_cfg(47, 40) = -1;
    shuffle1b_cfg(55, 48) = -1;
    shuffle1b_cfg(63, 56) = -1;

    // join config
    t.set_bit(0, 1);    // join
    t.set_bit(2, 0);    // dual-key
    t.range(5, 3) = 1;  // hash join flag = 0 for normal, 1 for semi, 2 for anti

    //--------------eval0--------------
    //stream shuffle 2
    ap_int<64> shuffle2_cfg;
    shuffle2_cfg(7, 0) = 0; // cs_sold_date_sk
    shuffle2_cfg(15, 8) = 3; // cs_bill_customer_sk
    shuffle2_cfg(23, 16) = 1; // cs_quantity
    shuffle2_cfg(31, 24) = 2; // cs_list_price
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
    shuffle3_cfg(7, 0) = 0; // cs_sold_date_sk
    shuffle3_cfg(15, 8) = 1; // cs_bill_customer_sk
    shuffle3_cfg(23, 16) = 2; // cs_quantity
    shuffle3_cfg(31, 24) = 3; // cs_list_price
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
    shuffle4_cfg(7, 0) = 0; // cs_sold_date_sk
    shuffle4_cfg(15, 8) = 1; // cs_bill_customer_sk
    shuffle4_cfg(23, 16) = 2; // cs_quantity
    shuffle4_cfg(31, 24) = 3; // cs_list_price
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

void get_cfg_dat_JOIN_LEFTSEMI_TD_7552478_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTSEMI
    // Operation: ListBuffer((ws_bill_customer_sk#733 = c_customer_sk#3632))
    // Left Table: ListBuffer(c_customer_sk#3632)
    // Right Table: ListBuffer(ws_sold_date_sk#729, ws_bill_customer_sk#733, ws_quantity#747, ws_list_price#749)
    // Output Table: ListBuffer(ws_sold_date_sk#729, ws_bill_customer_sk#733, ws_quantity#747, ws_list_price#749)
    // Node Depth: 7
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,-1,-1,-1,-1,-1,-1,-1};
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
    shuffle1a_cfg(7, 0) = 0;
    shuffle1a_cfg(15, 8) = -1;
    shuffle1a_cfg(23, 16) = -1;
    shuffle1a_cfg(31, 24) = -1;
    shuffle1a_cfg(39, 32) = -1;
    shuffle1a_cfg(47, 40) = -1;
    shuffle1a_cfg(55, 48) = -1;
    shuffle1a_cfg(63, 56) = -1;

    //stream shuffle 1b
    ap_int<64> shuffle1b_cfg;
    shuffle1b_cfg(7, 0) = 1;
    shuffle1b_cfg(15, 8) = 2;
    shuffle1b_cfg(23, 16) = 0;
    shuffle1b_cfg(31, 24) = 3;
    shuffle1b_cfg(39, 32) = -1;
    shuffle1b_cfg(47, 40) = -1;
    shuffle1b_cfg(55, 48) = -1;
    shuffle1b_cfg(63, 56) = -1;

    // join config
    t.set_bit(0, 1);    // join
    t.set_bit(2, 0);    // dual-key
    t.range(5, 3) = 1;  // hash join flag = 0 for normal, 1 for semi, 2 for anti

    //--------------eval0--------------
    //stream shuffle 2
    ap_int<64> shuffle2_cfg;
    shuffle2_cfg(7, 0) = 1; // ws_sold_date_sk
    shuffle2_cfg(15, 8) = 12; // ws_bill_customer_sk
    shuffle2_cfg(23, 16) = 0; // ws_quantity
    shuffle2_cfg(31, 24) = 2; // ws_list_price
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
    shuffle3_cfg(7, 0) = 0; // ws_sold_date_sk
    shuffle3_cfg(15, 8) = 1; // ws_bill_customer_sk
    shuffle3_cfg(23, 16) = 2; // ws_quantity
    shuffle3_cfg(31, 24) = 3; // ws_list_price
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
    shuffle4_cfg(7, 0) = 0; // ws_sold_date_sk
    shuffle4_cfg(15, 8) = 1; // ws_bill_customer_sk
    shuffle4_cfg(23, 16) = 2; // ws_quantity
    shuffle4_cfg(31, 24) = 3; // ws_list_price
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

void get_cfg_dat_JOIN_LEFTSEMI_TD_7619982_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTSEMI
    // Operation: ListBuffer((cs_bill_customer_sk#1107 = c_customer_sk#3632))
    // Left Table: ListBuffer(c_customer_sk#3632)
    // Right Table: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_quantity#1122, cs_list_price#1124)
    // Output Table: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_quantity#1122, cs_list_price#1124)
    // Node Depth: 7
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,-1,-1,-1,-1,-1,-1,-1};
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
    shuffle1a_cfg(7, 0) = 0;
    shuffle1a_cfg(15, 8) = -1;
    shuffle1a_cfg(23, 16) = -1;
    shuffle1a_cfg(31, 24) = -1;
    shuffle1a_cfg(39, 32) = -1;
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
    t.set_bit(2, 0);    // dual-key
    t.range(5, 3) = 1;  // hash join flag = 0 for normal, 1 for semi, 2 for anti

    //--------------eval0--------------
    //stream shuffle 2
    ap_int<64> shuffle2_cfg;
    shuffle2_cfg(7, 0) = 0; // cs_sold_date_sk
    shuffle2_cfg(15, 8) = 12; // cs_bill_customer_sk
    shuffle2_cfg(23, 16) = 1; // cs_quantity
    shuffle2_cfg(31, 24) = 2; // cs_list_price
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
    shuffle3_cfg(7, 0) = 0; // cs_sold_date_sk
    shuffle3_cfg(15, 8) = 1; // cs_bill_customer_sk
    shuffle3_cfg(23, 16) = 2; // cs_quantity
    shuffle3_cfg(31, 24) = 3; // cs_list_price
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
    shuffle4_cfg(7, 0) = 0; // cs_sold_date_sk
    shuffle4_cfg(15, 8) = 1; // cs_bill_customer_sk
    shuffle4_cfg(23, 16) = 2; // cs_quantity
    shuffle4_cfg(31, 24) = 3; // cs_list_price
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

