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

void get_cfg_dat_JOIN_LEFTOUTER_TD_11893643_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTOUTER
    // Operation: ListBuffer(((ws_item_sk#732 = wr_item_sk#833) AND (ws_order_number#746L = wr_order_number#844L)))
    // Left Table: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_web_site_sk#742, ws_promo_sk#745, ws_order_number#746L, ws_ext_sales_price#752, ws_net_profit#762)
    // Right Table: ListBuffer(wr_item_sk#833, wr_order_number#844L, wr_return_amt#846, wr_net_loss#854)
    // Output Table: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_web_site_sk#742, ws_promo_sk#745, ws_ext_sales_price#752, ws_net_profit#762, wr_return_amt#846, wr_net_loss#854)
    // Node Depth: 11
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,2,3,4,5,6,-1};
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
    shuffle1a_cfg(15, 8) = 1;
    shuffle1a_cfg(23, 16) = 2;
    shuffle1a_cfg(31, 24) = 3;
    shuffle1a_cfg(39, 32) = 4;
    shuffle1a_cfg(47, 40) = 5;
    shuffle1a_cfg(55, 48) = 6;
    shuffle1a_cfg(63, 56) = -1;

    //stream shuffle 1b
    ap_int<64> shuffle1b_cfg;
    shuffle1b_cfg(7, 0) = 0;
    shuffle1b_cfg(15, 8) = 1;
    shuffle1b_cfg(23, 16) = 2;
    shuffle1b_cfg(31, 24) = 3;
    shuffle1b_cfg(39, 32) = -1;
    shuffle1b_cfg(47, 40) = -1;
    shuffle1b_cfg(55, 48) = -1;
    shuffle1b_cfg(63, 56) = -1;

    // join config
    t.set_bit(0, 0);    // join
    t.set_bit(2, 0);    // dual-key
    t.range(5, 3) = 0;  // hash join flag = 0 for normal, 1 for semi, 2 for anti

    //--------------eval0--------------
    //stream shuffle 2
    ap_int<64> shuffle2_cfg;
    shuffle2_cfg(7, 0) = 0; // ws_sold_date_sk
    shuffle2_cfg(15, 8) = 1; // ws_item_sk
    shuffle2_cfg(23, 16) = 2; // ws_web_site_sk
    shuffle2_cfg(31, 24) = 3; // ws_promo_sk
    shuffle2_cfg(39, 32) = 4; // ws_ext_sales_price
    shuffle2_cfg(47, 40) = 5; // ws_net_profit
    shuffle2_cfg(55, 48) = 6; // wr_return_amt
    shuffle2_cfg(63, 56) = 7; // wr_net_loss

    ap_uint<289> op_eval_0 = 0; // NOP
    // eval0: NOP
    b[1] = op_eval_0;

    //--------------eval1--------------
    //stream shuffle 3
    ap_int<64> shuffle3_cfg;
    shuffle3_cfg(7, 0) = 0; // ws_sold_date_sk
    shuffle3_cfg(15, 8) = 1; // ws_item_sk
    shuffle3_cfg(23, 16) = 2; // ws_web_site_sk
    shuffle3_cfg(31, 24) = 3; // ws_promo_sk
    shuffle3_cfg(39, 32) = 4; // ws_ext_sales_price
    shuffle3_cfg(47, 40) = 5; // ws_net_profit
    shuffle3_cfg(55, 48) = 6; // wr_return_amt
    shuffle3_cfg(63, 56) = 7; // wr_net_loss

    ap_uint<289> op_eval_1 = 0; // NOP
    // eval1: NOP
    b[2] = op_eval_1;

    //--------------aggregate--------------
    //stream shuffle 4
    ap_int<64> shuffle4_cfg;
    shuffle4_cfg(7, 0) = 0; // ws_sold_date_sk
    shuffle4_cfg(15, 8) = 1; // ws_item_sk
    shuffle4_cfg(23, 16) = 2; // ws_web_site_sk
    shuffle4_cfg(31, 24) = 3; // ws_promo_sk
    shuffle4_cfg(39, 32) = 4; // ws_ext_sales_price
    shuffle4_cfg(47, 40) = 5; // ws_net_profit
    shuffle4_cfg(55, 48) = 6; // wr_return_amt
    shuffle4_cfg(63, 56) = 7; // wr_net_loss

    t.set_bit(1, 0); // aggr flag

    //--------------writeout--------------
    // output table col
    t.range(191, 184) = {1*1 + 2*1 + 4*1 + 8*1 + 16*1 + 32*1 + 64*1 + 128*1};
    b[0] = t;

    //stream shuffle assignment
    b[0].range(255, 192) = shuffle1a_cfg;
    b[0].range(319, 256) = shuffle1b_cfg;
    b[0].range(383, 320) = shuffle2_cfg;
    b[0].range(447, 384) = shuffle3_cfg;
    b[0].range(511, 448) = shuffle4_cfg;
}

void get_cfg_dat_JOIN_LEFTOUTER_TD_11822562_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTOUTER
    // Operation: ListBuffer(((cs_item_sk#1119 = cr_item_sk#1025) AND (cs_order_number#1121L = cr_order_number#1039L)))
    // Left Table: ListBuffer(cs_sold_date_sk#1104, cs_catalog_page_sk#1116, cs_item_sk#1119, cs_promo_sk#1120, cs_order_number#1121L, cs_ext_sales_price#1127, cs_net_profit#1137)
    // Right Table: ListBuffer(cr_item_sk#1025, cr_order_number#1039L, cr_return_amount#1041, cr_net_loss#1049)
    // Output Table: ListBuffer(cs_sold_date_sk#1104, cs_catalog_page_sk#1116, cs_item_sk#1119, cs_promo_sk#1120, cs_ext_sales_price#1127, cs_net_profit#1137, cr_return_amount#1041, cr_net_loss#1049)
    // Node Depth: 11
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,2,3,4,5,6,-1};
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
    shuffle1a_cfg(15, 8) = 1;
    shuffle1a_cfg(23, 16) = 2;
    shuffle1a_cfg(31, 24) = 3;
    shuffle1a_cfg(39, 32) = 4;
    shuffle1a_cfg(47, 40) = 5;
    shuffle1a_cfg(55, 48) = 6;
    shuffle1a_cfg(63, 56) = -1;

    //stream shuffle 1b
    ap_int<64> shuffle1b_cfg;
    shuffle1b_cfg(7, 0) = 0;
    shuffle1b_cfg(15, 8) = 1;
    shuffle1b_cfg(23, 16) = 2;
    shuffle1b_cfg(31, 24) = 3;
    shuffle1b_cfg(39, 32) = -1;
    shuffle1b_cfg(47, 40) = -1;
    shuffle1b_cfg(55, 48) = -1;
    shuffle1b_cfg(63, 56) = -1;

    // join config
    t.set_bit(0, 0);    // join
    t.set_bit(2, 0);    // dual-key
    t.range(5, 3) = 0;  // hash join flag = 0 for normal, 1 for semi, 2 for anti

    //--------------eval0--------------
    //stream shuffle 2
    ap_int<64> shuffle2_cfg;
    shuffle2_cfg(7, 0) = 0; // cs_sold_date_sk
    shuffle2_cfg(15, 8) = 1; // cs_catalog_page_sk
    shuffle2_cfg(23, 16) = 2; // cs_item_sk
    shuffle2_cfg(31, 24) = 3; // cs_promo_sk
    shuffle2_cfg(39, 32) = 4; // cs_ext_sales_price
    shuffle2_cfg(47, 40) = 5; // cs_net_profit
    shuffle2_cfg(55, 48) = 6; // cr_return_amount
    shuffle2_cfg(63, 56) = 7; // cr_net_loss

    ap_uint<289> op_eval_0 = 0; // NOP
    // eval0: NOP
    b[1] = op_eval_0;

    //--------------eval1--------------
    //stream shuffle 3
    ap_int<64> shuffle3_cfg;
    shuffle3_cfg(7, 0) = 0; // cs_sold_date_sk
    shuffle3_cfg(15, 8) = 1; // cs_catalog_page_sk
    shuffle3_cfg(23, 16) = 2; // cs_item_sk
    shuffle3_cfg(31, 24) = 3; // cs_promo_sk
    shuffle3_cfg(39, 32) = 4; // cs_ext_sales_price
    shuffle3_cfg(47, 40) = 5; // cs_net_profit
    shuffle3_cfg(55, 48) = 6; // cr_return_amount
    shuffle3_cfg(63, 56) = 7; // cr_net_loss

    ap_uint<289> op_eval_1 = 0; // NOP
    // eval1: NOP
    b[2] = op_eval_1;

    //--------------aggregate--------------
    //stream shuffle 4
    ap_int<64> shuffle4_cfg;
    shuffle4_cfg(7, 0) = 0; // cs_sold_date_sk
    shuffle4_cfg(15, 8) = 1; // cs_catalog_page_sk
    shuffle4_cfg(23, 16) = 2; // cs_item_sk
    shuffle4_cfg(31, 24) = 3; // cs_promo_sk
    shuffle4_cfg(39, 32) = 4; // cs_ext_sales_price
    shuffle4_cfg(47, 40) = 5; // cs_net_profit
    shuffle4_cfg(55, 48) = 6; // cr_return_amount
    shuffle4_cfg(63, 56) = 7; // cr_net_loss

    t.set_bit(1, 0); // aggr flag

    //--------------writeout--------------
    // output table col
    t.range(191, 184) = {1*1 + 2*1 + 4*1 + 8*1 + 16*1 + 32*1 + 64*1 + 128*1};
    b[0] = t;

    //stream shuffle assignment
    b[0].range(255, 192) = shuffle1a_cfg;
    b[0].range(319, 256) = shuffle1b_cfg;
    b[0].range(383, 320) = shuffle2_cfg;
    b[0].range(447, 384) = shuffle3_cfg;
    b[0].range(511, 448) = shuffle4_cfg;
}

void get_cfg_dat_JOIN_LEFTOUTER_TD_11633857_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTOUTER
    // Operation: ListBuffer(((ss_item_sk#1208 = sr_item_sk#671) AND (ss_ticket_number#1215L = sr_ticket_number#678L)))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_store_sk#1213, ss_promo_sk#1214, ss_ticket_number#1215L, ss_ext_sales_price#1221, ss_net_profit#1228)
    // Right Table: ListBuffer(sr_item_sk#671, sr_ticket_number#678L, sr_return_amt#680, sr_net_loss#688)
    // Output Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_store_sk#1213, ss_promo_sk#1214, ss_ext_sales_price#1221, ss_net_profit#1228, sr_return_amt#680, sr_net_loss#688)
    // Node Depth: 11
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,2,3,4,5,6,-1};
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
    shuffle1a_cfg(15, 8) = 1;
    shuffle1a_cfg(23, 16) = 2;
    shuffle1a_cfg(31, 24) = 3;
    shuffle1a_cfg(39, 32) = 4;
    shuffle1a_cfg(47, 40) = 5;
    shuffle1a_cfg(55, 48) = 6;
    shuffle1a_cfg(63, 56) = -1;

    //stream shuffle 1b
    ap_int<64> shuffle1b_cfg;
    shuffle1b_cfg(7, 0) = 0;
    shuffle1b_cfg(15, 8) = 1;
    shuffle1b_cfg(23, 16) = 2;
    shuffle1b_cfg(31, 24) = 3;
    shuffle1b_cfg(39, 32) = -1;
    shuffle1b_cfg(47, 40) = -1;
    shuffle1b_cfg(55, 48) = -1;
    shuffle1b_cfg(63, 56) = -1;

    // join config
    t.set_bit(0, 0);    // join
    t.set_bit(2, 0);    // dual-key
    t.range(5, 3) = 0;  // hash join flag = 0 for normal, 1 for semi, 2 for anti

    //--------------eval0--------------
    //stream shuffle 2
    ap_int<64> shuffle2_cfg;
    shuffle2_cfg(7, 0) = 0; // ss_sold_date_sk
    shuffle2_cfg(15, 8) = 1; // ss_item_sk
    shuffle2_cfg(23, 16) = 2; // ss_store_sk
    shuffle2_cfg(31, 24) = 3; // ss_promo_sk
    shuffle2_cfg(39, 32) = 4; // ss_ext_sales_price
    shuffle2_cfg(47, 40) = 5; // ss_net_profit
    shuffle2_cfg(55, 48) = 6; // sr_return_amt
    shuffle2_cfg(63, 56) = 7; // sr_net_loss

    ap_uint<289> op_eval_0 = 0; // NOP
    // eval0: NOP
    b[1] = op_eval_0;

    //--------------eval1--------------
    //stream shuffle 3
    ap_int<64> shuffle3_cfg;
    shuffle3_cfg(7, 0) = 0; // ss_sold_date_sk
    shuffle3_cfg(15, 8) = 1; // ss_item_sk
    shuffle3_cfg(23, 16) = 2; // ss_store_sk
    shuffle3_cfg(31, 24) = 3; // ss_promo_sk
    shuffle3_cfg(39, 32) = 4; // ss_ext_sales_price
    shuffle3_cfg(47, 40) = 5; // ss_net_profit
    shuffle3_cfg(55, 48) = 6; // sr_return_amt
    shuffle3_cfg(63, 56) = 7; // sr_net_loss

    ap_uint<289> op_eval_1 = 0; // NOP
    // eval1: NOP
    b[2] = op_eval_1;

    //--------------aggregate--------------
    //stream shuffle 4
    ap_int<64> shuffle4_cfg;
    shuffle4_cfg(7, 0) = 0; // ss_sold_date_sk
    shuffle4_cfg(15, 8) = 1; // ss_item_sk
    shuffle4_cfg(23, 16) = 2; // ss_store_sk
    shuffle4_cfg(31, 24) = 3; // ss_promo_sk
    shuffle4_cfg(39, 32) = 4; // ss_ext_sales_price
    shuffle4_cfg(47, 40) = 5; // ss_net_profit
    shuffle4_cfg(55, 48) = 6; // sr_return_amt
    shuffle4_cfg(63, 56) = 7; // sr_net_loss

    t.set_bit(1, 0); // aggr flag

    //--------------writeout--------------
    // output table col
    t.range(191, 184) = {1*1 + 2*1 + 4*1 + 8*1 + 16*1 + 32*1 + 64*1 + 128*1};
    b[0] = t;

    //stream shuffle assignment
    b[0].range(255, 192) = shuffle1a_cfg;
    b[0].range(319, 256) = shuffle1b_cfg;
    b[0].range(383, 320) = shuffle2_cfg;
    b[0].range(447, 384) = shuffle3_cfg;
    b[0].range(511, 448) = shuffle4_cfg;
}

void get_cfg_dat_JOIN_INNER_TD_10161275_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_sold_date_sk#729 = d_date_sk#4642))
    // Left Table: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_web_site_sk#742, ws_promo_sk#745, ws_ext_sales_price#752, ws_net_profit#762, wr_return_amt#846, wr_net_loss#854)
    // Right Table: ListBuffer(d_date_sk#4642)
    // Output Table: ListBuffer(ws_item_sk#732, ws_web_site_sk#742, ws_promo_sk#745, ws_ext_sales_price#752, ws_net_profit#762, wr_return_amt#846, wr_net_loss#854)
    // Node Depth: 10
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,2,3,4,5,6,7};
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
    shuffle1a_cfg(47, 40) = 6;
    shuffle1a_cfg(55, 48) = 7;
    shuffle1a_cfg(63, 56) = 5;

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
    shuffle2_cfg(7, 0) = 0; // ws_item_sk
    shuffle2_cfg(15, 8) = 1; // ws_web_site_sk
    shuffle2_cfg(23, 16) = 2; // ws_promo_sk
    shuffle2_cfg(31, 24) = 3; // ws_ext_sales_price
    shuffle2_cfg(39, 32) = 4; // ws_net_profit
    shuffle2_cfg(47, 40) = 5; // wr_return_amt
    shuffle2_cfg(55, 48) = 6; // wr_net_loss
    shuffle2_cfg(63, 56) = -1;

    ap_uint<289> op_eval_0 = 0; // NOP
    // eval0: NOP
    b[1] = op_eval_0;

    //--------------eval1--------------
    //stream shuffle 3
    ap_int<64> shuffle3_cfg;
    shuffle3_cfg(7, 0) = 0; // ws_item_sk
    shuffle3_cfg(15, 8) = 1; // ws_web_site_sk
    shuffle3_cfg(23, 16) = 2; // ws_promo_sk
    shuffle3_cfg(31, 24) = 3; // ws_ext_sales_price
    shuffle3_cfg(39, 32) = 4; // ws_net_profit
    shuffle3_cfg(47, 40) = 5; // wr_return_amt
    shuffle3_cfg(55, 48) = 6; // wr_net_loss
    shuffle3_cfg(63, 56) = -1;

    ap_uint<289> op_eval_1 = 0; // NOP
    // eval1: NOP
    b[2] = op_eval_1;

    //--------------aggregate--------------
    //stream shuffle 4
    ap_int<64> shuffle4_cfg;
    shuffle4_cfg(7, 0) = 0; // ws_item_sk
    shuffle4_cfg(15, 8) = 1; // ws_web_site_sk
    shuffle4_cfg(23, 16) = 2; // ws_promo_sk
    shuffle4_cfg(31, 24) = 3; // ws_ext_sales_price
    shuffle4_cfg(39, 32) = 4; // ws_net_profit
    shuffle4_cfg(47, 40) = 5; // wr_return_amt
    shuffle4_cfg(55, 48) = 6; // wr_net_loss
    shuffle4_cfg(63, 56) = -1;

    t.set_bit(1, 0); // aggr flag

    //--------------writeout--------------
    // output table col
    t.range(191, 184) = {1*1 + 2*1 + 4*1 + 8*1 + 16*1 + 32*1 + 64*1 + 128*0};
    b[0] = t;

    //stream shuffle assignment
    b[0].range(255, 192) = shuffle1a_cfg;
    b[0].range(319, 256) = shuffle1b_cfg;
    b[0].range(383, 320) = shuffle2_cfg;
    b[0].range(447, 384) = shuffle3_cfg;
    b[0].range(511, 448) = shuffle4_cfg;
}

void get_cfg_dat_JOIN_INNER_TD_10664187_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_sold_date_sk#1104 = d_date_sk#4573))
    // Left Table: ListBuffer(cs_sold_date_sk#1104, cs_catalog_page_sk#1116, cs_item_sk#1119, cs_promo_sk#1120, cs_ext_sales_price#1127, cs_net_profit#1137, cr_return_amount#1041, cr_net_loss#1049)
    // Right Table: ListBuffer(d_date_sk#4573)
    // Output Table: ListBuffer(cs_catalog_page_sk#1116, cs_item_sk#1119, cs_promo_sk#1120, cs_ext_sales_price#1127, cs_net_profit#1137, cr_return_amount#1041, cr_net_loss#1049)
    // Node Depth: 10
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,2,3,4,5,6,7};
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
    shuffle1a_cfg(23, 16) = 4;
    shuffle1a_cfg(31, 24) = 5;
    shuffle1a_cfg(39, 32) = 2;
    shuffle1a_cfg(47, 40) = 7;
    shuffle1a_cfg(55, 48) = 6;
    shuffle1a_cfg(63, 56) = 3;

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
    shuffle2_cfg(7, 0) = 0; // cs_catalog_page_sk
    shuffle2_cfg(15, 8) = 1; // cs_item_sk
    shuffle2_cfg(23, 16) = 2; // cs_promo_sk
    shuffle2_cfg(31, 24) = 3; // cs_ext_sales_price
    shuffle2_cfg(39, 32) = 4; // cs_net_profit
    shuffle2_cfg(47, 40) = 5; // cr_return_amount
    shuffle2_cfg(55, 48) = 6; // cr_net_loss
    shuffle2_cfg(63, 56) = -1;

    ap_uint<289> op_eval_0 = 0; // NOP
    // eval0: NOP
    b[1] = op_eval_0;

    //--------------eval1--------------
    //stream shuffle 3
    ap_int<64> shuffle3_cfg;
    shuffle3_cfg(7, 0) = 0; // cs_catalog_page_sk
    shuffle3_cfg(15, 8) = 1; // cs_item_sk
    shuffle3_cfg(23, 16) = 2; // cs_promo_sk
    shuffle3_cfg(31, 24) = 3; // cs_ext_sales_price
    shuffle3_cfg(39, 32) = 4; // cs_net_profit
    shuffle3_cfg(47, 40) = 5; // cr_return_amount
    shuffle3_cfg(55, 48) = 6; // cr_net_loss
    shuffle3_cfg(63, 56) = -1;

    ap_uint<289> op_eval_1 = 0; // NOP
    // eval1: NOP
    b[2] = op_eval_1;

    //--------------aggregate--------------
    //stream shuffle 4
    ap_int<64> shuffle4_cfg;
    shuffle4_cfg(7, 0) = 0; // cs_catalog_page_sk
    shuffle4_cfg(15, 8) = 1; // cs_item_sk
    shuffle4_cfg(23, 16) = 2; // cs_promo_sk
    shuffle4_cfg(31, 24) = 3; // cs_ext_sales_price
    shuffle4_cfg(39, 32) = 4; // cs_net_profit
    shuffle4_cfg(47, 40) = 5; // cr_return_amount
    shuffle4_cfg(55, 48) = 6; // cr_net_loss
    shuffle4_cfg(63, 56) = -1;

    t.set_bit(1, 0); // aggr flag

    //--------------writeout--------------
    // output table col
    t.range(191, 184) = {1*1 + 2*1 + 4*1 + 8*1 + 16*1 + 32*1 + 64*1 + 128*0};
    b[0] = t;

    //stream shuffle assignment
    b[0].range(255, 192) = shuffle1a_cfg;
    b[0].range(319, 256) = shuffle1b_cfg;
    b[0].range(383, 320) = shuffle2_cfg;
    b[0].range(447, 384) = shuffle3_cfg;
    b[0].range(511, 448) = shuffle4_cfg;
}

void get_cfg_dat_JOIN_INNER_TD_10934769_gqe_join(ap_uint<512>* hbuf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#1206 = d_date_sk#120))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_store_sk#1213, ss_promo_sk#1214, ss_ext_sales_price#1221, ss_net_profit#1228, sr_return_amt#680, sr_net_loss#688)
    // Right Table: ListBuffer(d_date_sk#120)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_store_sk#1213, ss_promo_sk#1214, ss_ext_sales_price#1221, ss_net_profit#1228, sr_return_amt#680, sr_net_loss#688)
    // Node Depth: 10
    ap_uint<512>* b = hbuf;
    memset(b, 0, sizeof(ap_uint<512>) * 9);
    ap_uint<512> t = 0;

    //--------------filter--------------
    // input table a
    signed char id_a[] = {0,1,2,3,4,5,6,7};
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
    shuffle1a_cfg(15, 8) = 4;
    shuffle1a_cfg(23, 16) = 3;
    shuffle1a_cfg(31, 24) = 5;
    shuffle1a_cfg(39, 32) = 6;
    shuffle1a_cfg(47, 40) = 7;
    shuffle1a_cfg(55, 48) = 1;
    shuffle1a_cfg(63, 56) = 2;

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
    shuffle2_cfg(7, 0) = 0; // ss_item_sk
    shuffle2_cfg(15, 8) = 1; // ss_store_sk
    shuffle2_cfg(23, 16) = 2; // ss_promo_sk
    shuffle2_cfg(31, 24) = 3; // ss_ext_sales_price
    shuffle2_cfg(39, 32) = 4; // ss_net_profit
    shuffle2_cfg(47, 40) = 5; // sr_return_amt
    shuffle2_cfg(55, 48) = 6; // sr_net_loss
    shuffle2_cfg(63, 56) = -1;

    ap_uint<289> op_eval_0 = 0; // NOP
    // eval0: NOP
    b[1] = op_eval_0;

    //--------------eval1--------------
    //stream shuffle 3
    ap_int<64> shuffle3_cfg;
    shuffle3_cfg(7, 0) = 0; // ss_item_sk
    shuffle3_cfg(15, 8) = 1; // ss_store_sk
    shuffle3_cfg(23, 16) = 2; // ss_promo_sk
    shuffle3_cfg(31, 24) = 3; // ss_ext_sales_price
    shuffle3_cfg(39, 32) = 4; // ss_net_profit
    shuffle3_cfg(47, 40) = 5; // sr_return_amt
    shuffle3_cfg(55, 48) = 6; // sr_net_loss
    shuffle3_cfg(63, 56) = -1;

    ap_uint<289> op_eval_1 = 0; // NOP
    // eval1: NOP
    b[2] = op_eval_1;

    //--------------aggregate--------------
    //stream shuffle 4
    ap_int<64> shuffle4_cfg;
    shuffle4_cfg(7, 0) = 0; // ss_item_sk
    shuffle4_cfg(15, 8) = 1; // ss_store_sk
    shuffle4_cfg(23, 16) = 2; // ss_promo_sk
    shuffle4_cfg(31, 24) = 3; // ss_ext_sales_price
    shuffle4_cfg(39, 32) = 4; // ss_net_profit
    shuffle4_cfg(47, 40) = 5; // sr_return_amt
    shuffle4_cfg(55, 48) = 6; // sr_net_loss
    shuffle4_cfg(63, 56) = -1;

    t.set_bit(1, 0); // aggr flag

    //--------------writeout--------------
    // output table col
    t.range(191, 184) = {1*1 + 2*1 + 4*1 + 8*1 + 16*1 + 32*1 + 64*1 + 128*0};
    b[0] = t;

    //stream shuffle assignment
    b[0].range(255, 192) = shuffle1a_cfg;
    b[0].range(319, 256) = shuffle1b_cfg;
    b[0].range(383, 320) = shuffle2_cfg;
    b[0].range(447, 384) = shuffle3_cfg;
    b[0].range(511, 448) = shuffle4_cfg;
}

