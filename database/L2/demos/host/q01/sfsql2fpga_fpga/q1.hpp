#include <regex> 
#include <stdint.h> 

void SW_Filter_TD_2859(Table &tbl_SerializeFromObject_TD_3513_input, Table &tbl_Filter_TD_2859_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((l_shipdate#87 <= 19980803))
    // Input: ListBuffer(l_quantity#81, l_extendedprice#82, l_discount#83, l_tax#84, l_returnflag#85, l_linestatus#86, l_shipdate#87)
    // Output: ListBuffer(l_quantity#81, l_extendedprice#82, l_discount#83, l_tax#84, l_returnflag#85, l_linestatus#86)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_3513_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _l_shipdate87 = tbl_SerializeFromObject_TD_3513_input.getInt32(i, 6);
        if (_l_shipdate87 <= 19980803) {
            int32_t _l_quantity81_t = tbl_SerializeFromObject_TD_3513_input.getInt32(i, 0);
            tbl_Filter_TD_2859_output.setInt32(r, 0, _l_quantity81_t);
            int32_t _l_extendedprice82_t = tbl_SerializeFromObject_TD_3513_input.getInt32(i, 1);
            tbl_Filter_TD_2859_output.setInt32(r, 1, _l_extendedprice82_t);
            int32_t _l_discount83_t = tbl_SerializeFromObject_TD_3513_input.getInt32(i, 2);
            tbl_Filter_TD_2859_output.setInt32(r, 2, _l_discount83_t);
            int32_t _l_tax84_t = tbl_SerializeFromObject_TD_3513_input.getInt32(i, 3);
            tbl_Filter_TD_2859_output.setInt32(r, 3, _l_tax84_t);
            int32_t _l_returnflag85_t = tbl_SerializeFromObject_TD_3513_input.getInt32(i, 4);
            tbl_Filter_TD_2859_output.setInt32(r, 4, _l_returnflag85_t);
            int32_t _l_linestatus86_t = tbl_SerializeFromObject_TD_3513_input.getInt32(i, 5);
            tbl_Filter_TD_2859_output.setInt32(r, 5, _l_linestatus86_t);
            r++;
        }
    }
    tbl_Filter_TD_2859_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2859_output #Row: " << tbl_Filter_TD_2859_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_1130_consolidate(Table *tbl_Aggregate_TD_1130_output_preprocess, Table &tbl_Aggregate_TD_1130_output, int hpTimes) {
    int nrow = 0;
for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
    int nrow_p = tbl_Aggregate_TD_1130_output_preprocess[p_idx].getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _l_returnflag85 = tbl_Aggregate_TD_1130_output_preprocess[p_idx].getInt32(r, 7);
        tbl_Aggregate_TD_1130_output.setInt32(r + p_idx*nrow_p, 0, _l_returnflag85);
        int32_t _l_linestatus86 = tbl_Aggregate_TD_1130_output_preprocess[p_idx].getInt32(r, 6);
        tbl_Aggregate_TD_1130_output.setInt32(r, 1, _l_linestatus86);
        int64_t _sum_qty364L = tbl_Aggregate_TD_1130_output_preprocess[p_idx].combineInt64(r, 8, 0);
        tbl_Aggregate_TD_1130_output.setInt64(r, 2, _sum_qty364L);
        int64_t _sum_base_price365L = tbl_Aggregate_TD_1130_output_preprocess[p_idx].combineInt64(r, 9, 1);
        tbl_Aggregate_TD_1130_output.setInt64(r, 3, _sum_base_price365L);
        int64_t _sum_disc_price366L = tbl_Aggregate_TD_1130_output_preprocess[p_idx].combineInt64(r, 10, 2);
        tbl_Aggregate_TD_1130_output.setInt64(r, 4, _sum_disc_price366L);
        int64_t _sum_charge367L = tbl_Aggregate_TD_1130_output_preprocess[p_idx].combineInt64(r, 11, 3);
        tbl_Aggregate_TD_1130_output.setInt64(r, 5, _sum_charge367L);
        int32_t _avg_qty368 = tbl_Aggregate_TD_1130_output_preprocess[p_idx].getInt32(r, 4);
        tbl_Aggregate_TD_1130_output.setInt32(r, 6, _avg_qty368);
        int32_t _avg_price369 = tbl_Aggregate_TD_1130_output_preprocess[p_idx].getInt32(r, 5);
        tbl_Aggregate_TD_1130_output.setInt32(r, 7, _avg_price369);
        int32_t _avg_disc370 = tbl_Aggregate_TD_1130_output_preprocess[p_idx].getInt32(r, 6);
        tbl_Aggregate_TD_1130_output.setInt32(r, 8, _avg_disc370);
        int32_t _count_order371L = tbl_Aggregate_TD_1130_output_preprocess[p_idx].getInt32(r, 7);
        tbl_Aggregate_TD_1130_output.setInt32(r, 9, _count_order371L);
    }
    nrow += nrow_p;
}
    tbl_Aggregate_TD_1130_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_1130_output #Row: " << tbl_Aggregate_TD_1130_output.getNumRow() << std::endl;
}

void SW_Sort_TD_0537(Table &tbl_Aggregate_TD_1130_output, Table &tbl_Sort_TD_0537_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(l_returnflag#85 ASC NULLS FIRST, l_linestatus#86 ASC NULLS FIRST)
    // Input: ListBuffer(l_returnflag#85, l_linestatus#86, sum_qty#364L, sum_base_price#365L, sum_disc_price#366L, sum_charge#367L, avg_qty#368, avg_price#369, avg_disc#370, count_order#371L)
    // Output: ListBuffer(l_returnflag#85, l_linestatus#86, sum_qty#364L, sum_base_price#365L, sum_disc_price#366L, sum_charge#367L, avg_qty#368, avg_price#369, avg_disc#370, count_order#371L)
    struct SW_Sort_TD_0537Row {
        int32_t _l_returnflag85;
        int32_t _l_linestatus86;
        int64_t _sum_qty364L;
        int64_t _sum_base_price365L;
        int64_t _sum_disc_price366L;
        int64_t _sum_charge367L;
        int32_t _avg_qty368;
        int32_t _avg_price369;
        int32_t _avg_disc370;
        int64_t _count_order371L;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_0537Row& a, const SW_Sort_TD_0537Row& b) const { return 
 (a._l_returnflag85 < b._l_returnflag85) || 
 ((a._l_returnflag85 == b._l_returnflag85) && (a._l_linestatus86 < b._l_linestatus86)); 
}
    }SW_Sort_TD_0537_order; 

    int nrow1 = tbl_Aggregate_TD_1130_output.getNumRow();
    std::vector<SW_Sort_TD_0537Row> rows;
    for (int i = 0; i < nrow1; i++) {
        int32_t _l_returnflag85 = tbl_Aggregate_TD_1130_output.getInt32(i, 0);
        int32_t _l_linestatus86 = tbl_Aggregate_TD_1130_output.getInt32(i, 1);
        int64_t _sum_qty364L = tbl_Aggregate_TD_1130_output.getInt64(i, 2);
        int64_t _sum_base_price365L = tbl_Aggregate_TD_1130_output.getInt64(i, 3);
        int64_t _sum_disc_price366L = tbl_Aggregate_TD_1130_output.getInt64(i, 4);
        int64_t _sum_charge367L = tbl_Aggregate_TD_1130_output.getInt64(i, 5);
        int32_t _avg_qty368 = tbl_Aggregate_TD_1130_output.getInt32(i, 6);
        int32_t _avg_price369 = tbl_Aggregate_TD_1130_output.getInt32(i, 7);
        int32_t _avg_disc370 = tbl_Aggregate_TD_1130_output.getInt32(i, 8);
        int64_t _count_order371L = tbl_Aggregate_TD_1130_output.getInt64(i, 9);
        SW_Sort_TD_0537Row t = {_l_returnflag85,_l_linestatus86,_sum_qty364L,_sum_base_price365L,_sum_disc_price366L,_sum_charge367L,_avg_qty368,_avg_price369,_avg_disc370,_count_order371L};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_0537_order);
    int r = 0;
    for (auto& it : rows) {
        tbl_Sort_TD_0537_output.setInt32(r, 0, it._l_returnflag85);
        tbl_Sort_TD_0537_output.setInt32(r, 1, it._l_linestatus86);
        tbl_Sort_TD_0537_output.setInt64(r, 2, it._sum_qty364L);
        tbl_Sort_TD_0537_output.setInt64(r, 3, it._sum_base_price365L);
        tbl_Sort_TD_0537_output.setInt64(r, 4, it._sum_disc_price366L);
        tbl_Sort_TD_0537_output.setInt64(r, 5, it._sum_charge367L);
        tbl_Sort_TD_0537_output.setInt32(r, 6, it._avg_qty368);
        tbl_Sort_TD_0537_output.setInt32(r, 7, it._avg_price369);
        tbl_Sort_TD_0537_output.setInt32(r, 8, it._avg_disc370);
        tbl_Sort_TD_0537_output.setInt64(r, 9, it._count_order371L);
        if (r < 10) {
            std::cout << it._l_returnflag85 << " " << it._l_linestatus86 << " " << it._sum_qty364L << " " << it._sum_base_price365L << " " << it._sum_disc_price366L << " " << it._sum_charge367L << " " << it._avg_qty368 << " " << it._avg_price369 << " " << it._avg_disc370 << " " << it._count_order371L << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_0537_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_0537_output #Row: " << tbl_Sort_TD_0537_output.getNumRow() << std::endl;
}

