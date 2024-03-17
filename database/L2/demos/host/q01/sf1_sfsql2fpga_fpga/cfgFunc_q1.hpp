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

void get_cfg_dat_Aggregate_TD_1416_gqe_aggr(ap_uint<32>* buf) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(l_returnflag#58, l_linestatus#59, sum(l_quantity#54) AS sum_qty#743L, sum(l_extendedprice#55) AS sum_base_price#744L, sum((l_extendedprice#55 * (100 - l_discount#56))) AS sum_disc_price#745L, sum(((l_extendedprice#55 * (100 - l_discount#56)) * (100 + l_tax#57))) AS sum_charge#746L, avg(l_quantity#54) AS avg_qty#747, avg(l_extendedprice#55) AS avg_price#748, avg(l_discount#56) AS avg_disc#749, count(1) AS count_order#750L)
    // Input Table: ListBuffer(l_quantity#54, l_extendedprice#55, l_discount#56, l_tax#57, l_returnflag#58, l_linestatus#59)
    // Output Table: ListBuffer(l_returnflag#58, l_linestatus#59, sum_qty#743L, sum_base_price#744L, sum_disc_price#745L, sum_charge#746L, avg_qty#747, avg_price#748, avg_disc#749, count_order#750L)
    // Node Depth: 1
    ap_uint<32>* config = buf;
    memset(config, 0, sizeof(ap_uint<32>) * 83);

    // eval0
    ap_uint<32> t;
    signed char id[] = {1,2,0,3,4,5,-1,-1};
    for (int c = 0; c < 4; ++c) {
        t.range(8 * c + 7, 8 * c) = id[c];
    }
    config[0] = t;
    for (int c = 0; c < 4; ++c) {
        t.range(8 * c + 7, 8 * c) = id[c + 4];
    }
    config[1] = t;

    ap_uint<289> op_eval_0 = 0; // (l_extendedprice#55 * (100 - l_discount#56))
    xf::database::dynamicALUOPCompiler<uint32_t, uint32_t, uint32_t, uint32_t>("strm1*(-strm2+c2)", 0, 100, 0, 0, op_eval_0);
    for (int i = 0; i < 9; i++) {
        config[i + 2] = op_eval_0(32 * (i + 1) - 1, 32 * i);
    }
    config[11] = op_eval_0[288];

    // eval0 -> eval1
    ap_int<64> shuffle1_cfg;
    shuffle1_cfg(7, 0) = 0; // l_extendedprice
    shuffle1_cfg(15, 8) = 1; // l_discount
    shuffle1_cfg(23, 16) = 3; // l_tax
    shuffle1_cfg(31, 24) = 2; // l_quantity
    shuffle1_cfg(39, 32) = 4; // l_returnflag#58
    shuffle1_cfg(47, 40) = 5; // l_linestatus#59
    shuffle1_cfg(55, 48) = 8; // sum_disc_price
    shuffle1_cfg(63, 56) = -1;
    config[67] = shuffle1_cfg(31, 0);
    config[68] = shuffle1_cfg(63, 32);

    ap_uint<289> op_eval_1 = 0; // ((l_extendedprice#55 * (100 - l_discount#56)) * (100 + l_tax#57))
    xf::database::dynamicALUOPCompiler<uint32_t, uint32_t, uint32_t, uint32_t>("(strm1*(-strm2+c2))*(strm3+c3)", 0, 100, 100, 0, op_eval_1);
    for (int i = 0; i < 9; i++) {
        config[i + 12] = op_eval_1(32 * (i + 1) - 1, 32 * i);
    }
    config[21] = op_eval_1[288];

    // eval1 -> filter
    ap_int<64> shuffle2_cfg;
    shuffle2_cfg(7, 0) = 0; // l_extendedprice
    shuffle2_cfg(15, 8) = 1; // l_discount
    shuffle2_cfg(23, 16) = 2; // l_tax
    shuffle2_cfg(31, 24) = 3; // l_quantity
    shuffle2_cfg(39, 32) = 4; // l_returnflag
    shuffle2_cfg(47, 40) = 5; // l_linestatus
    shuffle2_cfg(55, 48) = 6; // sum_disc_price
    shuffle2_cfg(63, 56) = 8; // sum_charge
    config[69] = shuffle2_cfg(31, 0);
    config[70] = shuffle2_cfg(63, 32);

    uint32_t fcfg[45];
    gen_pass_fcfg(fcfg);
    memcpy(&config[22], fcfg, sizeof(uint32_t) * 45);

    // filter -> groupBy
    ap_int<64> shuffle3_cfg;
    shuffle3_cfg(7, 0) = 4; // l_returnflag#58
    shuffle3_cfg(15, 8) = 5; // l_linestatus#59
    shuffle3_cfg(23, 16) = -1;
    shuffle3_cfg(31, 24) = -1;
    shuffle3_cfg(39, 32) = -1;
    shuffle3_cfg(47, 40) = -1;
    shuffle3_cfg(55, 48) = -1;
    shuffle3_cfg(63, 56) = -1;
    config[71] = shuffle3_cfg(31, 0);
    config[72] = shuffle3_cfg(63, 32);

    ap_int<64> shuffle4_cfg;
    shuffle4_cfg(7, 0) = 2; // sum_qty#743L
    shuffle4_cfg(15, 8) = 0; // sum_base_price#744L
    shuffle4_cfg(23, 16) = 6; // sum_disc_price#745L
    shuffle4_cfg(31, 24) = 8; // sum_charge#746L
    shuffle4_cfg(39, 32) = 2; // avg_qty#747
    shuffle4_cfg(47, 40) = 0; // avg_price#748
    shuffle4_cfg(55, 48) = 1; // avg_disc#749
    shuffle4_cfg(63, 56) = -1; // count_order#750L
    config[73] = shuffle4_cfg(31, 0);
    config[74] = shuffle4_cfg(63, 32);

    ap_uint<4> aggr_op[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    aggr_op[0] = xf::database::enums::AOP_SUM;
    aggr_op[1] = xf::database::enums::AOP_SUM;
    aggr_op[2] = xf::database::enums::AOP_SUM;
    aggr_op[3] = xf::database::enums::AOP_SUM;
    aggr_op[4] = xf::database::enums::AOP_MEAN;
    aggr_op[5] = xf::database::enums::AOP_MEAN;
    aggr_op[6] = xf::database::enums::AOP_MEAN;
    aggr_op[7] = xf::database::enums::AOP_COUNT;
    config[75] = (aggr_op[7], aggr_op[6], aggr_op[5], aggr_op[4], aggr_op[3], aggr_op[2], aggr_op[1], aggr_op[0]);

    config[76] = 2; //# key col
    config[77] = 8; //# pld col
    config[78] = 0; //# aggr num

    ap_uint<8> merge[5];
    merge[0] = 0b11000000;
    merge[1] = 0;
    merge[2] = 0;
    merge[3] = 0b11000000;
    merge[4] = 0;
    config[79] = (1, merge[2], merge[1], merge[0]);
    config[80] = (0, merge[4], merge[3]);

    // aggr - demux mux direct_aggr
    config[81] = 0;

    // output - demux mux direct_aggr
    config[82] = 0xffff;
}

