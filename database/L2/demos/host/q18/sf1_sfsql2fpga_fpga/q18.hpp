#include <regex> 
#include <stdint.h> 

void SW_Aggregate_TD_6111_consolidate(Table &tbl_Aggregate_TD_6111_output_preprocess, Table &tbl_Aggregate_TD_6111_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_6111_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _l_orderkey50 = tbl_Aggregate_TD_6111_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_6111_output.setInt32(r, 0, _l_orderkey50);
        int64_t _suml_quantity541960L = tbl_Aggregate_TD_6111_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_6111_output.setInt64(r, 1, _suml_quantity541960L);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_6111_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_6111_output #Row: " << tbl_Aggregate_TD_6111_output.getNumRow() << std::endl;
}

void SW_Filter_TD_54(Table &tbl_Aggregate_TD_6111_output, Table &tbl_Filter_TD_54_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(sum(l_quantity#54)#1960L) AND (sum(l_quantity#54)#1960L > 312)))
    // Input: ListBuffer(l_orderkey#50, sum(l_quantity#54)#1960L)
    // Output: ListBuffer(l_orderkey#50)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_6111_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _suml_quantity541960L = tbl_Aggregate_TD_6111_output.getInt64(i, 1);
        if ((1) && (_suml_quantity541960L > 312)) {
            int32_t _l_orderkey50_t = tbl_Aggregate_TD_6111_output.getInt32(i, 0);
            tbl_Filter_TD_54_output.setInt32(r, 0, _l_orderkey50_t);
            r++;
        }
    }
    tbl_Filter_TD_54_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_54_output #Row: " << tbl_Filter_TD_54_output.getNumRow() << std::endl;
}

void SW_Filter_TD_4736(Table &tbl_Aggregate_TD_6111_output, Table &tbl_Filter_TD_4736_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(sum(l_quantity#54)#1960L) AND (sum(l_quantity#54)#1960L > 312)))
    // Input: ListBuffer(l_orderkey#50, sum(l_quantity#54)#1960L)
    // Output: ListBuffer(l_orderkey#50#2044)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_6111_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _suml_quantity541960L = tbl_Aggregate_TD_6111_output.getInt64(i, 1);
        if ((1) && (_suml_quantity541960L > 312)) {
            int32_t _l_orderkey502044_t = tbl_Aggregate_TD_6111_output.getInt32(i, 0);
            tbl_Filter_TD_4736_output.setInt32(r, 0, _l_orderkey502044_t);
            r++;
        }
    }
    tbl_Filter_TD_4736_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4736_output #Row: " << tbl_Filter_TD_4736_output.getNumRow() << std::endl;
}





struct SW_Aggregate_TD_1120_key {
    std::string _c_name126;
    int32_t _c_custkey125;
    int32_t _o_orderkey227;
    int32_t _o_orderdate231;
    int32_t _o_totalprice230;
    bool operator==(const SW_Aggregate_TD_1120_key& other) const { return (_c_name126 == other._c_name126) && (_c_custkey125 == other._c_custkey125) && (_o_orderkey227 == other._o_orderkey227) && (_o_orderdate231 == other._o_orderdate231) && (_o_totalprice230 == other._o_totalprice230); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_1120_key> {
    std::size_t operator() (const SW_Aggregate_TD_1120_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._c_name126)) + (hash<int32_t>()(k._c_custkey125)) + (hash<int32_t>()(k._o_orderkey227)) + (hash<int32_t>()(k._o_orderdate231)) + (hash<int32_t>()(k._o_totalprice230));
    }
};
}
struct SW_Aggregate_TD_1120_payload {
    int64_t _suml_quantity1978L_sum_0;
};
void SW_Aggregate_TD_1120(Table &tbl_JOIN_INNER_TD_2768_output, Table &tbl_SerializeFromObject_TD_4803_input, Table &tbl_Aggregate_TD_1120_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: true
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_name#126, c_custkey#125, o_orderkey#227, o_orderdate#231, o_totalprice#230, sum(l_quantity#54) AS sum(l_quantity)#1978L)
    // Input: ListBuffer(c_custkey#125, c_name#126, o_orderkey#227, o_totalprice#230, o_orderdate#231, l_quantity#54)
    // Output: ListBuffer(c_name#126, c_custkey#125, o_orderkey#227, o_orderdate#231, o_totalprice#230, sum(l_quantity)#1978L)
    std::unordered_map<SW_Aggregate_TD_1120_key, SW_Aggregate_TD_1120_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_2768_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_custkey125 = tbl_JOIN_INNER_TD_2768_output.getInt32(i, 0);
        std::array<char, TPCH_READ_REGION_LEN + 1> _c_name126 = tbl_SerializeFromObject_TD_4803_input.getcharN<char, TPCH_READ_REGION_LEN + 1>(tbl_JOIN_INNER_TD_2768_output.getInt32(i, 1), 1);
        int32_t _o_orderkey227 = tbl_JOIN_INNER_TD_2768_output.getInt32(i, 2);
        int32_t _o_totalprice230 = tbl_JOIN_INNER_TD_2768_output.getInt32(i, 3);
        int32_t _o_orderdate231 = tbl_JOIN_INNER_TD_2768_output.getInt32(i, 4);
        int32_t _l_quantity54 = tbl_JOIN_INNER_TD_2768_output.getInt32(i, 5);
        SW_Aggregate_TD_1120_key k{std::string(_c_name126.data()), _c_custkey125, _o_orderkey227, _o_orderdate231, _o_totalprice230};
        int64_t _suml_quantity1978L_sum_0 = _l_quantity54;
        SW_Aggregate_TD_1120_payload p{_suml_quantity1978L_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._suml_quantity1978L_sum_0 + _suml_quantity1978L_sum_0;
            p._suml_quantity1978L_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCH_READ_REGION_LEN + 1> _c_name126{};
        memcpy(_c_name126.data(), ((it.first)._c_name126).data(), ((it.first)._c_name126).length());
        tbl_Aggregate_TD_1120_output.setcharN<char, TPCH_READ_REGION_LEN + 1>(r, 0, _c_name126);
        tbl_Aggregate_TD_1120_output.setInt32(r, 1, (it.first)._c_custkey125);
        tbl_Aggregate_TD_1120_output.setInt32(r, 2, (it.first)._o_orderkey227);
        tbl_Aggregate_TD_1120_output.setInt32(r, 3, (it.first)._o_orderdate231);
        tbl_Aggregate_TD_1120_output.setInt32(r, 4, (it.first)._o_totalprice230);
        int64_t _suml_quantity1978L = (it.second)._suml_quantity1978L_sum_0;
        tbl_Aggregate_TD_1120_output.setInt64(r, 5, _suml_quantity1978L);
        ++r;
    }
    tbl_Aggregate_TD_1120_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_1120_output #Row: " << tbl_Aggregate_TD_1120_output.getNumRow() << std::endl;
}

void SW_Sort_TD_0923(Table &tbl_Aggregate_TD_1120_output, Table &tbl_Sort_TD_0923_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(o_totalprice#230 DESC NULLS LAST, o_orderdate#231 ASC NULLS FIRST)
    // Input: ListBuffer(c_name#126, c_custkey#125, o_orderkey#227, o_orderdate#231, o_totalprice#230, sum(l_quantity)#1978L)
    // Output: ListBuffer(c_name#126, c_custkey#125, o_orderkey#227, o_orderdate#231, o_totalprice#230, sum(l_quantity)#1978L)
    struct SW_Sort_TD_0923Row {
        std::string _c_name126;
        int32_t _c_custkey125;
        int32_t _o_orderkey227;
        int32_t _o_orderdate231;
        int32_t _o_totalprice230;
        int64_t _suml_quantity1978L;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_0923Row& a, const SW_Sort_TD_0923Row& b) const { return 
 (a._o_totalprice230 > b._o_totalprice230) || 
 ((a._o_totalprice230 == b._o_totalprice230) && (a._o_orderdate231 < b._o_orderdate231)); 
}
    }SW_Sort_TD_0923_order; 

    int nrow1 = tbl_Aggregate_TD_1120_output.getNumRow();
    std::vector<SW_Sort_TD_0923Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_REGION_LEN + 1> _c_name126 = tbl_Aggregate_TD_1120_output.getcharN<char, TPCH_READ_REGION_LEN +1>(i, 0);
        int32_t _c_custkey125 = tbl_Aggregate_TD_1120_output.getInt32(i, 1);
        int32_t _o_orderkey227 = tbl_Aggregate_TD_1120_output.getInt32(i, 2);
        int32_t _o_orderdate231 = tbl_Aggregate_TD_1120_output.getInt32(i, 3);
        int32_t _o_totalprice230 = tbl_Aggregate_TD_1120_output.getInt32(i, 4);
        int64_t _suml_quantity1978L = tbl_Aggregate_TD_1120_output.getInt64(i, 5);
        SW_Sort_TD_0923Row t = {std::string(_c_name126.data()),_c_custkey125,_o_orderkey227,_o_orderdate231,_o_totalprice230,_suml_quantity1978L};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_0923_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCH_READ_REGION_LEN + 1> _c_name126{};
        memcpy(_c_name126.data(), (it._c_name126).data(), (it._c_name126).length());
        tbl_Sort_TD_0923_output.setcharN<char, TPCH_READ_REGION_LEN +1>(r, 0, _c_name126);
        tbl_Sort_TD_0923_output.setInt32(r, 1, it._c_custkey125);
        tbl_Sort_TD_0923_output.setInt32(r, 2, it._o_orderkey227);
        tbl_Sort_TD_0923_output.setInt32(r, 3, it._o_orderdate231);
        tbl_Sort_TD_0923_output.setInt32(r, 4, it._o_totalprice230);
        tbl_Sort_TD_0923_output.setInt64(r, 5, it._suml_quantity1978L);
        if (r < 10) {
            std::cout << (it._c_name126).data() << " " << it._c_custkey125 << " " << it._o_orderkey227 << " " << it._o_orderdate231 << " " << it._o_totalprice230 << " " << it._suml_quantity1978L << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_0923_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_0923_output #Row: " << tbl_Sort_TD_0923_output.getNumRow() << std::endl;
}

