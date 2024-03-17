#include <regex> 
#include <stdint.h> 

void SW_Filter_TD_7691(Table &tbl_SerializeFromObject_TD_8758_input, Table &tbl_Filter_TD_7691_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((o_orderdate#211 >= 19930101) AND (o_orderdate#211 < 19940101)))
    // Input: ListBuffer(o_orderkey#207, o_custkey#208, o_orderdate#211)
    // Output: ListBuffer(o_orderkey#207, o_custkey#208)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8758_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _o_orderdate211 = tbl_SerializeFromObject_TD_8758_input.getInt32(i, 2);
        if ((_o_orderdate211 >= 19930101) && (_o_orderdate211 < 19940101)) {
            int32_t _o_orderkey207_t = tbl_SerializeFromObject_TD_8758_input.getInt32(i, 0);
            tbl_Filter_TD_7691_output.setInt32(r, 0, _o_orderkey207_t);
            int32_t _o_custkey208_t = tbl_SerializeFromObject_TD_8758_input.getInt32(i, 1);
            tbl_Filter_TD_7691_output.setInt32(r, 1, _o_custkey208_t);
            r++;
        }
    }
    tbl_Filter_TD_7691_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7691_output #Row: " << tbl_Filter_TD_7691_output.getNumRow() << std::endl;
}




void SW_Filter_TD_3311(Table &tbl_SerializeFromObject_TD_4686_input, Table &tbl_Filter_TD_3311_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(r_name#175) AND (r_name#175 = AFRICA)))
    // Input: ListBuffer(r_regionkey#174, r_name#175)
    // Output: ListBuffer(r_regionkey#174)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_4686_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_REGION_LEN + 1> _r_name175 = tbl_SerializeFromObject_TD_4686_input.getcharN<char, TPCH_READ_REGION_LEN + 1>(i, 1);
        if ((1) && (std::string(_r_name175.data()) == "AFRICA")) {
            int32_t _r_regionkey174_t = tbl_SerializeFromObject_TD_4686_input.getInt32(i, 0);
            tbl_Filter_TD_3311_output.setInt32(r, 0, _r_regionkey174_t);
            r++;
        }
    }
    tbl_Filter_TD_3311_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_3311_output #Row: " << tbl_Filter_TD_3311_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_3446_key_leftMajor {
    int32_t _s_nationkey345;
    bool operator==(const SW_JOIN_INNER_TD_3446_key_leftMajor& other) const {
        return ((_s_nationkey345 == other._s_nationkey345));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3446_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3446_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_nationkey345));
    }
};
}
struct SW_JOIN_INNER_TD_3446_payload_leftMajor {
    int32_t _l_extendedprice82;
    int32_t _l_discount83;
    int32_t _s_nationkey345;
};
struct SW_JOIN_INNER_TD_3446_key_rightMajor {
    int32_t _n_nationkey144;
    bool operator==(const SW_JOIN_INNER_TD_3446_key_rightMajor& other) const {
        return ((_n_nationkey144 == other._n_nationkey144));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3446_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3446_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._n_nationkey144));
    }
};
}
struct SW_JOIN_INNER_TD_3446_payload_rightMajor {
    int32_t _n_nationkey144;
    std::string _n_name145;
    int32_t _n_regionkey146;
};
void SW_JOIN_INNER_TD_3446(Table *tbl_JOIN_INNER_TD_4711_output, Table &tbl_SerializeFromObject_TD_4423_input, Table &tbl_JOIN_INNER_TD_3446_output, int hpTimes) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((s_nationkey#345 = n_nationkey#144))
    // Left Table: ListBuffer(l_extendedprice#82, l_discount#83, s_nationkey#345)
    // Right Table: ListBuffer(n_nationkey#144, n_name#145, n_regionkey#146)
    // Output Table: ListBuffer(l_extendedprice#82, l_discount#83, n_name#145, n_regionkey#146)
    int left_nrow = tbl_JOIN_INNER_TD_4711_output[0].getNumRow();
    int right_nrow = tbl_SerializeFromObject_TD_4423_input.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3446_key_leftMajor, SW_JOIN_INNER_TD_3446_payload_leftMajor> ht1;
    for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
        int nrow1 = tbl_JOIN_INNER_TD_4711_output[p_idx].getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_nationkey345_k = tbl_JOIN_INNER_TD_4711_output[p_idx].getInt32(i, 2);
            SW_JOIN_INNER_TD_3446_key_leftMajor keyA{_s_nationkey345_k};
            int32_t _l_extendedprice82 = tbl_JOIN_INNER_TD_4711_output[p_idx].getInt32(i, 0);
            int32_t _l_discount83 = tbl_JOIN_INNER_TD_4711_output[p_idx].getInt32(i, 1);
            int32_t _s_nationkey345 = tbl_JOIN_INNER_TD_4711_output[p_idx].getInt32(i, 2);
            SW_JOIN_INNER_TD_3446_payload_leftMajor payloadA{_l_extendedprice82, _l_discount83, _s_nationkey345};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
    }
        int r = 0;
        int nrow2 = tbl_SerializeFromObject_TD_4423_input.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _n_nationkey144_k = tbl_SerializeFromObject_TD_4423_input.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3446_key_leftMajor{_n_nationkey144_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _l_extendedprice82 = (it->second)._l_extendedprice82;
                int32_t _l_discount83 = (it->second)._l_discount83;
                int32_t _s_nationkey345 = (it->second)._s_nationkey345;
                int32_t _n_nationkey144 = tbl_SerializeFromObject_TD_4423_input.getInt32(i, 0);
                std::array<char, TPCH_READ_NATION_LEN + 1> _n_name145_n = tbl_SerializeFromObject_TD_4423_input.getcharN<char, TPCH_READ_NATION_LEN + 1>(i, 1);
                std::string _n_name145 = std::string(_n_name145_n.data());
                int32_t _n_regionkey146 = tbl_SerializeFromObject_TD_4423_input.getInt32(i, 2);
                tbl_JOIN_INNER_TD_3446_output.setInt32(r, 0, _l_extendedprice82);
                tbl_JOIN_INNER_TD_3446_output.setInt32(r, 1, _l_discount83);
                tbl_JOIN_INNER_TD_3446_output.setcharN<char, TPCH_READ_NATION_LEN + 1>(r, 2, _n_name145_n);
                tbl_JOIN_INNER_TD_3446_output.setInt32(r, 3, _n_regionkey146);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3446_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3446_key_rightMajor, SW_JOIN_INNER_TD_3446_payload_rightMajor> ht1;
        int nrow1 = tbl_SerializeFromObject_TD_4423_input.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _n_nationkey144_k = tbl_SerializeFromObject_TD_4423_input.getInt32(i, 0);
            SW_JOIN_INNER_TD_3446_key_rightMajor keyA{_n_nationkey144_k};
            int32_t _n_nationkey144 = tbl_SerializeFromObject_TD_4423_input.getInt32(i, 0);
            std::array<char, TPCH_READ_NATION_LEN + 1> _n_name145_n = tbl_SerializeFromObject_TD_4423_input.getcharN<char, TPCH_READ_NATION_LEN + 1>(i, 1);
            std::string _n_name145 = std::string(_n_name145_n.data());
            int32_t _n_regionkey146 = tbl_SerializeFromObject_TD_4423_input.getInt32(i, 2);
            SW_JOIN_INNER_TD_3446_payload_rightMajor payloadA{_n_nationkey144, _n_name145, _n_regionkey146};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
    for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
        int nrow2 = tbl_JOIN_INNER_TD_4711_output[p_idx].getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_nationkey345_k = tbl_JOIN_INNER_TD_4711_output[p_idx].getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3446_key_rightMajor{_s_nationkey345_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _n_nationkey144 = (it->second)._n_nationkey144;
                std::string _n_name145 = (it->second)._n_name145;
                std::array<char, TPCH_READ_NATION_LEN + 1> _n_name145_n{};
                memcpy(_n_name145_n.data(), (_n_name145).data(), (_n_name145).length());
                int32_t _n_regionkey146 = (it->second)._n_regionkey146;
                int32_t _l_extendedprice82 = tbl_JOIN_INNER_TD_4711_output[p_idx].getInt32(i, 0);
                int32_t _l_discount83 = tbl_JOIN_INNER_TD_4711_output[p_idx].getInt32(i, 1);
                int32_t _s_nationkey345 = tbl_JOIN_INNER_TD_4711_output[p_idx].getInt32(i, 2);
                tbl_JOIN_INNER_TD_3446_output.setcharN<char, TPCH_READ_NATION_LEN + 1>(r, 2, _n_name145_n);
                tbl_JOIN_INNER_TD_3446_output.setInt32(r, 3, _n_regionkey146);
                tbl_JOIN_INNER_TD_3446_output.setInt32(r, 0, _l_extendedprice82);
                tbl_JOIN_INNER_TD_3446_output.setInt32(r, 1, _l_discount83);
                it++;
                r++;
            }
        }
    }
        tbl_JOIN_INNER_TD_3446_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_3446_output #Row: " << tbl_JOIN_INNER_TD_3446_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_2549_key_leftMajor {
    int32_t _n_regionkey146;
    bool operator==(const SW_JOIN_INNER_TD_2549_key_leftMajor& other) const {
        return ((_n_regionkey146 == other._n_regionkey146));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_2549_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_2549_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._n_regionkey146));
    }
};
}
struct SW_JOIN_INNER_TD_2549_payload_leftMajor {
    int32_t _l_extendedprice82;
    int32_t _l_discount83;
    std::string _n_name145;
    int32_t _n_regionkey146;
};
struct SW_JOIN_INNER_TD_2549_key_rightMajor {
    int32_t _r_regionkey174;
    bool operator==(const SW_JOIN_INNER_TD_2549_key_rightMajor& other) const {
        return ((_r_regionkey174 == other._r_regionkey174));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_2549_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_2549_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._r_regionkey174));
    }
};
}
struct SW_JOIN_INNER_TD_2549_payload_rightMajor {
    int32_t _r_regionkey174;
};
void SW_JOIN_INNER_TD_2549(Table &tbl_JOIN_INNER_TD_3446_output, Table &tbl_Filter_TD_3311_output, Table &tbl_JOIN_INNER_TD_2549_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((n_regionkey#146 = r_regionkey#174))
    // Left Table: ListBuffer(l_extendedprice#82, l_discount#83, n_name#145, n_regionkey#146)
    // Right Table: ListBuffer(r_regionkey#174)
    // Output Table: ListBuffer(l_extendedprice#82, l_discount#83, n_name#145)
    int left_nrow = tbl_JOIN_INNER_TD_3446_output.getNumRow();
    int right_nrow = tbl_Filter_TD_3311_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_2549_key_leftMajor, SW_JOIN_INNER_TD_2549_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_3446_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _n_regionkey146_k = tbl_JOIN_INNER_TD_3446_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_2549_key_leftMajor keyA{_n_regionkey146_k};
            int32_t _l_extendedprice82 = tbl_JOIN_INNER_TD_3446_output.getInt32(i, 0);
            int32_t _l_discount83 = tbl_JOIN_INNER_TD_3446_output.getInt32(i, 1);
            std::array<char, TPCH_READ_NATION_LEN + 1> _n_name145_n = tbl_JOIN_INNER_TD_3446_output.getcharN<char, TPCH_READ_NATION_LEN + 1>(i, 2);
            std::string _n_name145 = std::string(_n_name145_n.data());
            int32_t _n_regionkey146 = tbl_JOIN_INNER_TD_3446_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_2549_payload_leftMajor payloadA{_l_extendedprice82, _l_discount83, _n_name145, _n_regionkey146};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_3311_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _r_regionkey174_k = tbl_Filter_TD_3311_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_2549_key_leftMajor{_r_regionkey174_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _l_extendedprice82 = (it->second)._l_extendedprice82;
                int32_t _l_discount83 = (it->second)._l_discount83;
                std::string _n_name145 = (it->second)._n_name145;
                std::array<char, TPCH_READ_NATION_LEN + 1> _n_name145_n{};
                memcpy(_n_name145_n.data(), (_n_name145).data(), (_n_name145).length());
                int32_t _n_regionkey146 = (it->second)._n_regionkey146;
                int32_t _r_regionkey174 = tbl_Filter_TD_3311_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_2549_output.setInt32(r, 0, _l_extendedprice82);
                tbl_JOIN_INNER_TD_2549_output.setInt32(r, 1, _l_discount83);
                tbl_JOIN_INNER_TD_2549_output.setcharN<char, TPCH_READ_NATION_LEN + 1>(r, 2, _n_name145_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_2549_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_2549_key_rightMajor, SW_JOIN_INNER_TD_2549_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_3311_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _r_regionkey174_k = tbl_Filter_TD_3311_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_2549_key_rightMajor keyA{_r_regionkey174_k};
            int32_t _r_regionkey174 = tbl_Filter_TD_3311_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_2549_payload_rightMajor payloadA{_r_regionkey174};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_3446_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _n_regionkey146_k = tbl_JOIN_INNER_TD_3446_output.getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_2549_key_rightMajor{_n_regionkey146_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _r_regionkey174 = (it->second)._r_regionkey174;
                int32_t _l_extendedprice82 = tbl_JOIN_INNER_TD_3446_output.getInt32(i, 0);
                int32_t _l_discount83 = tbl_JOIN_INNER_TD_3446_output.getInt32(i, 1);
                std::array<char, TPCH_READ_NATION_LEN + 1> _n_name145_n = tbl_JOIN_INNER_TD_3446_output.getcharN<char, TPCH_READ_NATION_LEN + 1>(i, 2);
                std::string _n_name145 = std::string(_n_name145_n.data());
                int32_t _n_regionkey146 = tbl_JOIN_INNER_TD_3446_output.getInt32(i, 3);
                tbl_JOIN_INNER_TD_2549_output.setInt32(r, 0, _l_extendedprice82);
                tbl_JOIN_INNER_TD_2549_output.setInt32(r, 1, _l_discount83);
                tbl_JOIN_INNER_TD_2549_output.setcharN<char, TPCH_READ_NATION_LEN + 1>(r, 2, _n_name145_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_2549_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_2549_output #Row: " << tbl_JOIN_INNER_TD_2549_output.getNumRow() << std::endl;
}

typedef std::string SW_Aggregate_TD_1299_key;
struct SW_Aggregate_TD_1299_payload {
    int64_t _revenue786L_sum_0;
};
void SW_Aggregate_TD_1299(Table &tbl_JOIN_INNER_TD_2549_output, Table &tbl_Aggregate_TD_1299_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(n_name#145, sum((l_extendedprice#82 * (100 - l_discount#83))) AS revenue#786L)
    // Input: ListBuffer(l_extendedprice#82, l_discount#83, n_name#145)
    // Output: ListBuffer(n_name#145, revenue#786L)
    std::unordered_map<SW_Aggregate_TD_1299_key, SW_Aggregate_TD_1299_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_2549_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _l_extendedprice82 = tbl_JOIN_INNER_TD_2549_output.getInt32(i, 0);
        int32_t _l_discount83 = tbl_JOIN_INNER_TD_2549_output.getInt32(i, 1);
        std::array<char, TPCH_READ_NATION_LEN + 1> _n_name145 = tbl_JOIN_INNER_TD_2549_output.getcharN<char, TPCH_READ_NATION_LEN + 1>(i, 2);
        SW_Aggregate_TD_1299_key k = std::string(_n_name145.data());
        int64_t _revenue786L_sum_0 = (_l_extendedprice82 * (100 - _l_discount83));
        SW_Aggregate_TD_1299_payload p{_revenue786L_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._revenue786L_sum_0 + _revenue786L_sum_0;
            p._revenue786L_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCH_READ_NATION_LEN + 1> _n_name145{};
        memcpy(_n_name145.data(), (it.first).data(), (it.first).length());
        tbl_Aggregate_TD_1299_output.setcharN<char, TPCH_READ_NATION_LEN + 1>(r, 0, _n_name145);
        int64_t _revenue786L = (it.second)._revenue786L_sum_0;
        tbl_Aggregate_TD_1299_output.setInt64(r, 1, _revenue786L);
        ++r;
    }
    tbl_Aggregate_TD_1299_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_1299_output #Row: " << tbl_Aggregate_TD_1299_output.getNumRow() << std::endl;
}

void SW_Sort_TD_0647(Table &tbl_Aggregate_TD_1299_output, Table &tbl_Sort_TD_0647_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(revenue#786L DESC NULLS LAST)
    // Input: ListBuffer(n_name#145, revenue#786L)
    // Output: ListBuffer(n_name#145, revenue#786L)
    struct SW_Sort_TD_0647Row {
        std::string _n_name145;
        int64_t _revenue786L;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_0647Row& a, const SW_Sort_TD_0647Row& b) const { return 
 (a._revenue786L > b._revenue786L); 
}
    }SW_Sort_TD_0647_order; 

    int nrow1 = tbl_Aggregate_TD_1299_output.getNumRow();
    std::vector<SW_Sort_TD_0647Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_NATION_LEN + 1> _n_name145 = tbl_Aggregate_TD_1299_output.getcharN<char, TPCH_READ_NATION_LEN +1>(i, 0);
        int64_t _revenue786L = tbl_Aggregate_TD_1299_output.getInt64(i, 1);
        SW_Sort_TD_0647Row t = {std::string(_n_name145.data()),_revenue786L};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_0647_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCH_READ_NATION_LEN + 1> _n_name145{};
        memcpy(_n_name145.data(), (it._n_name145).data(), (it._n_name145).length());
        tbl_Sort_TD_0647_output.setcharN<char, TPCH_READ_NATION_LEN +1>(r, 0, _n_name145);
        tbl_Sort_TD_0647_output.setInt64(r, 1, it._revenue786L);
        if (r < 10) {
            std::cout << (it._n_name145).data() << " " << it._revenue786L << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_0647_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_0647_output #Row: " << tbl_Sort_TD_0647_output.getNumRow() << std::endl;
}

