#include <regex> 
#include <stdint.h> 

void SW_Filter_TD_4876(Table &tbl_SerializeFromObject_TD_5101_input, Table &tbl_Filter_TD_4876_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(o_comment#215) AND NOT o_comment#215 LIKE %unusual%deposits%))
    // Input: ListBuffer(o_orderkey#207, o_custkey#208, o_comment#215)
    // Output: ListBuffer(o_orderkey#207, o_custkey#208)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5101_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_O_CMNT_MAX + 1> _o_comment215 = tbl_SerializeFromObject_TD_5101_input.getcharN<char, TPCH_READ_O_CMNT_MAX + 1>(i, 2);
        struct custom_func {
                bool strm_pattern(std::string sub1, std::string sub2, std::string s, int len = 7) {
                    std::string::size_type spe_f = s.find(sub1);
                    std::string::size_type c_f = 0;
                    while (spe_f != std::string::npos) {
                        c_f += (spe_f + len);
                        std::string sub_s = s.substr(c_f);
                        if (sub_s.find(sub2) != std::string::npos) return true;
                        spe_f = sub_s.find(sub1);
                    }
                    return false;
                }
        }custom_func_obj;
        if ((1) && !(custom_func_obj.strm_pattern("unusual", "deposits", _o_comment215.data()))) {
            int32_t _o_orderkey207_t = tbl_SerializeFromObject_TD_5101_input.getInt32(i, 0);
            tbl_Filter_TD_4876_output.setInt32(r, 0, _o_orderkey207_t);
            int32_t _o_custkey208_t = tbl_SerializeFromObject_TD_5101_input.getInt32(i, 1);
            tbl_Filter_TD_4876_output.setInt32(r, 1, _o_custkey208_t);
            r++;
        }
    }
    tbl_Filter_TD_4876_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4876_output #Row: " << tbl_Filter_TD_4876_output.getNumRow() << std::endl;
}


void SW_JOIN_LEFTANTI_TD_3550_concatenate(Table &tbl_JOIN_LEFTANTI_TD_3550_output_preprocess, Table &tbl_JOIN_INNER_TD_0152_output) {
    int start_idx = tbl_JOIN_LEFTANTI_TD_3550_output_preprocess.getNumRow();
    int nrow = tbl_JOIN_INNER_TD_0152_output.getNumRow();
    int i = 0;
    for (int r(start_idx); r<start_idx+nrow; ++r) {
        int32_t _c_custkey22 = tbl_JOIN_INNER_TD_0152_output.getInt32(i, 0);
        tbl_JOIN_LEFTANTI_TD_3550_output_preprocess.setInt32(r, 0, _c_custkey22);
        int32_t _o_orderkey207 = tbl_JOIN_INNER_TD_0152_output.getInt32(i, 1);
        tbl_JOIN_LEFTANTI_TD_3550_output_preprocess.setInt32(r, 1, _o_orderkey207);
        i++;
    }
    tbl_JOIN_LEFTANTI_TD_3550_output_preprocess.setNumRow(start_idx + nrow);
    std::cout << "tbl_JOIN_LEFTANTI_TD_3550_output_preprocess #Row: " << tbl_JOIN_LEFTANTI_TD_3550_output_preprocess.getNumRow() << std::endl;
}

void SW_Aggregate_TD_212_consolidate(Table *tbl_Aggregate_TD_212_output_preprocess, Table &tbl_Aggregate_TD_212_output, int hpTimes) {
    int nrow = 0;
for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
    int nrow_p = tbl_Aggregate_TD_212_output_preprocess[p_idx].getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _c_count1386L = tbl_Aggregate_TD_212_output_preprocess[p_idx].getInt32(r, 0);
        tbl_Aggregate_TD_212_output.setInt32(r, 0, _c_count1386L);
    }
    nrow += nrow_p;
}
    tbl_Aggregate_TD_212_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_212_output #Row: " << tbl_Aggregate_TD_212_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_1543_consolidate(Table *tbl_Aggregate_TD_1543_output_preprocess, Table &tbl_Aggregate_TD_1543_output, int hpTimes) {
    int nrow = 0;
for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
    int nrow_p = tbl_Aggregate_TD_1543_output_preprocess[p_idx].getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _c_count1386L = tbl_Aggregate_TD_1543_output_preprocess[p_idx].getInt32(r, 7);
        tbl_Aggregate_TD_1543_output.setInt32(r, 0, _c_count1386L);
        int32_t _custdist1381L = tbl_Aggregate_TD_1543_output_preprocess[p_idx].getInt32(r, 0);
        tbl_Aggregate_TD_1543_output.setInt32(r, 1, _custdist1381L);
    }
    nrow += nrow_p;
}
    tbl_Aggregate_TD_1543_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_1543_output #Row: " << tbl_Aggregate_TD_1543_output.getNumRow() << std::endl;
}

void SW_Sort_TD_0399(Table &tbl_Aggregate_TD_1543_output, Table &tbl_Sort_TD_0399_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(custdist#1381L DESC NULLS LAST, c_count#1386L DESC NULLS LAST)
    // Input: ListBuffer(c_count#1386L, custdist#1381L)
    // Output: ListBuffer(c_count#1386L, custdist#1381L)
    struct SW_Sort_TD_0399Row {
        int64_t _c_count1386L;
        int64_t _custdist1381L;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_0399Row& a, const SW_Sort_TD_0399Row& b) const { return 
 (a._custdist1381L > b._custdist1381L) || 
 ((a._custdist1381L == b._custdist1381L) && (a._c_count1386L > b._c_count1386L)); 
}
    }SW_Sort_TD_0399_order; 

    int nrow1 = tbl_Aggregate_TD_1543_output.getNumRow();
    std::vector<SW_Sort_TD_0399Row> rows;
    for (int i = 0; i < nrow1; i++) {
        int64_t _c_count1386L = tbl_Aggregate_TD_1543_output.getInt64(i, 0);
        int64_t _custdist1381L = tbl_Aggregate_TD_1543_output.getInt64(i, 1);
        SW_Sort_TD_0399Row t = {_c_count1386L,_custdist1381L};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_0399_order);
    int r = 0;
    for (auto& it : rows) {
        tbl_Sort_TD_0399_output.setInt64(r, 0, it._c_count1386L);
        tbl_Sort_TD_0399_output.setInt64(r, 1, it._custdist1381L);
        if (r < 10) {
            std::cout << it._c_count1386L << " " << it._custdist1381L << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_0399_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_0399_output #Row: " << tbl_Sort_TD_0399_output.getNumRow() << std::endl;
}

