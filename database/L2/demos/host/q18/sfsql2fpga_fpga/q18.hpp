#include <regex> 
#include <stdint.h> 

void SW_Aggregate_TD_6796_consolidate(Table *tbl_Aggregate_TD_6796_output_preprocess, Table &tbl_Aggregate_TD_6796_output, int hpTimes) {
    int nrow = 0;
for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
    int nrow_p = tbl_Aggregate_TD_6796_output_preprocess[p_idx].getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _l_orderkey77 = tbl_Aggregate_TD_6796_output_preprocess[p_idx].getInt32(r, 7);
        tbl_Aggregate_TD_6796_output.setInt32(r, 0, _l_orderkey77);
        int64_t _suml_quantity81366L = tbl_Aggregate_TD_6796_output_preprocess[p_idx].combineInt64(r, 8, 0);
        tbl_Aggregate_TD_6796_output.setInt64(r, 1, _suml_quantity81366L);
    }
    nrow += nrow_p;
}
    tbl_Aggregate_TD_6796_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_6796_output #Row: " << tbl_Aggregate_TD_6796_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5290(Table &tbl_Aggregate_TD_6796_output, Table &tbl_Filter_TD_5290_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(sum(l_quantity#81)#366L) AND (sum(l_quantity#81)#366L > 312)))
    // Input: ListBuffer(l_orderkey#77, sum(l_quantity#81)#366L)
    // Output: ListBuffer(l_orderkey#77)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_6796_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _suml_quantity81366L = tbl_Aggregate_TD_6796_output.getInt64(i, 1);
        if ((1) && (_suml_quantity81366L > 312)) {
            int32_t _l_orderkey77_t = tbl_Aggregate_TD_6796_output.getInt32(i, 0);
            tbl_Filter_TD_5290_output.setInt32(r, 0, _l_orderkey77_t);
            r++;
        }
    }
    tbl_Filter_TD_5290_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5290_output #Row: " << tbl_Filter_TD_5290_output.getNumRow() << std::endl;
}

void SW_Filter_TD_4903(Table &tbl_Aggregate_TD_6796_output, Table &tbl_Filter_TD_4903_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(sum(l_quantity#81)#366L) AND (sum(l_quantity#81)#366L > 312)))
    // Input: ListBuffer(l_orderkey#77, sum(l_quantity#81)#366L)
    // Output: ListBuffer(l_orderkey#77#442)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_6796_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _suml_quantity81366L = tbl_Aggregate_TD_6796_output.getInt64(i, 1);
        if ((1) && (_suml_quantity81366L > 312)) {
            int32_t _l_orderkey77442_t = tbl_Aggregate_TD_6796_output.getInt32(i, 0);
            tbl_Filter_TD_4903_output.setInt32(r, 0, _l_orderkey77442_t);
            r++;
        }
    }
    tbl_Filter_TD_4903_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4903_output #Row: " << tbl_Filter_TD_4903_output.getNumRow() << std::endl;
}





struct SW_Aggregate_TD_1769_key {
    std::string _c_name23;
    int32_t _c_custkey22;
    int32_t _o_orderkey207;
    int32_t _o_orderdate211;
    int32_t _o_totalprice210;
    bool operator==(const SW_Aggregate_TD_1769_key& other) const { return (_c_name23 == other._c_name23) && (_c_custkey22 == other._c_custkey22) && (_o_orderkey207 == other._o_orderkey207) && (_o_orderdate211 == other._o_orderdate211) && (_o_totalprice210 == other._o_totalprice210); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_1769_key> {
    std::size_t operator() (const SW_Aggregate_TD_1769_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._c_name23)) + (hash<int32_t>()(k._c_custkey22)) + (hash<int32_t>()(k._o_orderkey207)) + (hash<int32_t>()(k._o_orderdate211)) + (hash<int32_t>()(k._o_totalprice210));
    }
};
}
struct SW_Aggregate_TD_1769_payload {
    int64_t _suml_quantity369L_sum_0;
};
void SW_Aggregate_TD_1769(Table *tbl_JOIN_INNER_TD_2223_output, Table &tbl_SerializeFromObject_TD_4686_input, Table &tbl_Aggregate_TD_1769_output, int hpTimes) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: true
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_name#23, c_custkey#22, o_orderkey#207, o_orderdate#211, o_totalprice#210, sum(l_quantity#81) AS sum(l_quantity)#369L)
    // Input: ListBuffer(c_custkey#22, c_name#23, o_orderkey#207, o_totalprice#210, o_orderdate#211, l_quantity#81)
    // Output: ListBuffer(c_name#23, c_custkey#22, o_orderkey#207, o_orderdate#211, o_totalprice#210, sum(l_quantity)#369L)
    std::unordered_map<SW_Aggregate_TD_1769_key, SW_Aggregate_TD_1769_payload> ht1;
for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
    int nrow1 = tbl_JOIN_INNER_TD_2223_output[p_idx].getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_custkey22 = tbl_JOIN_INNER_TD_2223_output[p_idx].getInt32(i, 0);
        std::array<char, TPCH_READ_C_NAME_LEN + 1> _c_name23 = tbl_SerializeFromObject_TD_4686_input.getcharN<char, TPCH_READ_C_NAME_LEN + 1>(tbl_JOIN_INNER_TD_2223_output[p_idx].getInt32(i, 1), 1);
        int32_t _o_orderkey207 = tbl_JOIN_INNER_TD_2223_output[p_idx].getInt32(i, 2);
        int32_t _o_totalprice210 = tbl_JOIN_INNER_TD_2223_output[p_idx].getInt32(i, 3);
        int32_t _o_orderdate211 = tbl_JOIN_INNER_TD_2223_output[p_idx].getInt32(i, 4);
        int32_t _l_quantity81 = tbl_JOIN_INNER_TD_2223_output[p_idx].getInt32(i, 5);
        SW_Aggregate_TD_1769_key k{std::string(_c_name23.data()), _c_custkey22, _o_orderkey207, _o_orderdate211, _o_totalprice210};
        int64_t _suml_quantity369L_sum_0 = _l_quantity81;
        SW_Aggregate_TD_1769_payload p{_suml_quantity369L_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._suml_quantity369L_sum_0 + _suml_quantity369L_sum_0;
            p._suml_quantity369L_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
}
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCH_READ_C_NAME_LEN + 1> _c_name23{};
        memcpy(_c_name23.data(), ((it.first)._c_name23).data(), ((it.first)._c_name23).length());
        tbl_Aggregate_TD_1769_output.setcharN<char, TPCH_READ_C_NAME_LEN + 1>(r, 0, _c_name23);
        tbl_Aggregate_TD_1769_output.setInt32(r, 1, (it.first)._c_custkey22);
        tbl_Aggregate_TD_1769_output.setInt32(r, 2, (it.first)._o_orderkey207);
        tbl_Aggregate_TD_1769_output.setInt32(r, 3, (it.first)._o_orderdate211);
        tbl_Aggregate_TD_1769_output.setInt32(r, 4, (it.first)._o_totalprice210);
        int64_t _suml_quantity369L = (it.second)._suml_quantity369L_sum_0;
        tbl_Aggregate_TD_1769_output.setInt64(r, 5, _suml_quantity369L);
        ++r;
    }
    tbl_Aggregate_TD_1769_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_1769_output #Row: " << tbl_Aggregate_TD_1769_output.getNumRow() << std::endl;
}

void SW_Sort_TD_0312(Table &tbl_Aggregate_TD_1769_output, Table &tbl_Sort_TD_0312_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(o_totalprice#210 DESC NULLS LAST, o_orderdate#211 ASC NULLS FIRST)
    // Input: ListBuffer(c_name#23, c_custkey#22, o_orderkey#207, o_orderdate#211, o_totalprice#210, sum(l_quantity)#369L)
    // Output: ListBuffer(c_name#23, c_custkey#22, o_orderkey#207, o_orderdate#211, o_totalprice#210, sum(l_quantity)#369L)
    struct SW_Sort_TD_0312Row {
        std::string _c_name23;
        int32_t _c_custkey22;
        int32_t _o_orderkey207;
        int32_t _o_orderdate211;
        int32_t _o_totalprice210;
        int64_t _suml_quantity369L;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_0312Row& a, const SW_Sort_TD_0312Row& b) const { return 
 (a._o_totalprice210 > b._o_totalprice210) || 
 ((a._o_totalprice210 == b._o_totalprice210) && (a._o_orderdate211 < b._o_orderdate211)); 
}
    }SW_Sort_TD_0312_order; 

    int nrow1 = tbl_Aggregate_TD_1769_output.getNumRow();
    std::vector<SW_Sort_TD_0312Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_C_NAME_LEN + 1> _c_name23 = tbl_Aggregate_TD_1769_output.getcharN<char, TPCH_READ_C_NAME_LEN +1>(i, 0);
        int32_t _c_custkey22 = tbl_Aggregate_TD_1769_output.getInt32(i, 1);
        int32_t _o_orderkey207 = tbl_Aggregate_TD_1769_output.getInt32(i, 2);
        int32_t _o_orderdate211 = tbl_Aggregate_TD_1769_output.getInt32(i, 3);
        int32_t _o_totalprice210 = tbl_Aggregate_TD_1769_output.getInt32(i, 4);
        int64_t _suml_quantity369L = tbl_Aggregate_TD_1769_output.getInt64(i, 5);
        SW_Sort_TD_0312Row t = {std::string(_c_name23.data()),_c_custkey22,_o_orderkey207,_o_orderdate211,_o_totalprice210,_suml_quantity369L};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_0312_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCH_READ_C_NAME_LEN + 1> _c_name23{};
        memcpy(_c_name23.data(), (it._c_name23).data(), (it._c_name23).length());
        tbl_Sort_TD_0312_output.setcharN<char, TPCH_READ_C_NAME_LEN +1>(r, 0, _c_name23);
        tbl_Sort_TD_0312_output.setInt32(r, 1, it._c_custkey22);
        tbl_Sort_TD_0312_output.setInt32(r, 2, it._o_orderkey207);
        tbl_Sort_TD_0312_output.setInt32(r, 3, it._o_orderdate211);
        tbl_Sort_TD_0312_output.setInt32(r, 4, it._o_totalprice210);
        tbl_Sort_TD_0312_output.setInt64(r, 5, it._suml_quantity369L);
        if (r < 10) {
            std::cout << (it._c_name23).data() << " " << it._c_custkey22 << " " << it._o_orderkey207 << " " << it._o_orderdate211 << " " << it._o_totalprice210 << " " << it._suml_quantity369L << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_0312_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_0312_output #Row: " << tbl_Sort_TD_0312_output.getNumRow() << std::endl;
}

