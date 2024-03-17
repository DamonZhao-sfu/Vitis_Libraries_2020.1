#include <regex> 
#include <stdint.h> 

void SW_Filter_TD_10213(Table &tbl_SerializeFromObject_TD_11625_input, Table &tbl_Filter_TD_10213_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(p_type#262) AND (p_type#262 = LARGE ANODIZED STEEL)))
    // Input: ListBuffer(p_partkey#258, p_type#262)
    // Output: ListBuffer(p_partkey#258)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11625_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_P_TYPE_LEN + 1> _p_type262 = tbl_SerializeFromObject_TD_11625_input.getcharN<char, TPCH_READ_P_TYPE_LEN + 1>(i, 1);
        if ((1) && (std::string(_p_type262.data()) == "LARGE ANODIZED STEEL")) {
            int32_t _p_partkey258_t = tbl_SerializeFromObject_TD_11625_input.getInt32(i, 0);
            tbl_Filter_TD_10213_output.setInt32(r, 0, _p_partkey258_t);
            r++;
        }
    }
    tbl_Filter_TD_10213_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10213_output #Row: " << tbl_Filter_TD_10213_output.getNumRow() << std::endl;
}


void SW_Filter_TD_8923(Table &tbl_SerializeFromObject_TD_9538_input, Table &tbl_Filter_TD_8923_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((o_orderdate#211 >= 19950101) AND (o_orderdate#211 <= 19961231)))
    // Input: ListBuffer(o_orderkey#207, o_custkey#208, o_orderdate#211)
    // Output: ListBuffer(o_orderkey#207, o_custkey#208, o_orderdate#211)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9538_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _o_orderdate211 = tbl_SerializeFromObject_TD_9538_input.getInt32(i, 2);
        if ((_o_orderdate211 >= 19950101) && (_o_orderdate211 <= 19961231)) {
            int32_t _o_orderkey207_t = tbl_SerializeFromObject_TD_9538_input.getInt32(i, 0);
            tbl_Filter_TD_8923_output.setInt32(r, 0, _o_orderkey207_t);
            int32_t _o_custkey208_t = tbl_SerializeFromObject_TD_9538_input.getInt32(i, 1);
            tbl_Filter_TD_8923_output.setInt32(r, 1, _o_custkey208_t);
            int32_t _o_orderdate211_t = tbl_SerializeFromObject_TD_9538_input.getInt32(i, 2);
            tbl_Filter_TD_8923_output.setInt32(r, 2, _o_orderdate211_t);
            r++;
        }
    }
    tbl_Filter_TD_8923_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8923_output #Row: " << tbl_Filter_TD_8923_output.getNumRow() << std::endl;
}




void SW_Filter_TD_4155(Table &tbl_SerializeFromObject_TD_5297_input, Table &tbl_Filter_TD_4155_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(r_name#175) AND (r_name#175 = MIDDLE EAST)))
    // Input: ListBuffer(r_regionkey#174, r_name#175)
    // Output: ListBuffer(r_regionkey#174)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5297_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_REGION_LEN + 1> _r_name175 = tbl_SerializeFromObject_TD_5297_input.getcharN<char, TPCH_READ_REGION_LEN + 1>(i, 1);
        if ((1) && (std::string(_r_name175.data()) == "MIDDLE EAST")) {
            int32_t _r_regionkey174_t = tbl_SerializeFromObject_TD_5297_input.getInt32(i, 0);
            tbl_Filter_TD_4155_output.setInt32(r, 0, _r_regionkey174_t);
            r++;
        }
    }
    tbl_Filter_TD_4155_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4155_output #Row: " << tbl_Filter_TD_4155_output.getNumRow() << std::endl;
}



struct SW_JOIN_INNER_TD_3467_key_leftMajor {
    int32_t _s_nationkey345;
    bool operator==(const SW_JOIN_INNER_TD_3467_key_leftMajor& other) const {
        return ((_s_nationkey345 == other._s_nationkey345));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3467_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3467_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_nationkey345));
    }
};
}
struct SW_JOIN_INNER_TD_3467_payload_leftMajor {
    int32_t _o_orderdate211;
    int32_t _l_extendedprice82;
    int32_t _l_discount83;
    int32_t _s_nationkey345;
    int32_t _n_regionkey146;
};
struct SW_JOIN_INNER_TD_3467_key_rightMajor {
    int32_t _n_nationkey961;
    bool operator==(const SW_JOIN_INNER_TD_3467_key_rightMajor& other) const {
        return ((_n_nationkey961 == other._n_nationkey961));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3467_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3467_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._n_nationkey961));
    }
};
}
struct SW_JOIN_INNER_TD_3467_payload_rightMajor {
    int32_t _n_nationkey961;
    std::string _n_name962;
};
void SW_JOIN_INNER_TD_3467(Table *tbl_JOIN_INNER_TD_4178_output, Table &tbl_SerializeFromObject_TD_4614_input, Table &tbl_JOIN_INNER_TD_3467_output, int hpTimes) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((s_nationkey#345 = n_nationkey#961))
    // Left Table: ListBuffer(o_orderdate#211, l_extendedprice#82, l_discount#83, s_nationkey#345, n_regionkey#146)
    // Right Table: ListBuffer(n_nationkey#961, n_name#962)
    // Output Table: ListBuffer(o_orderdate#211, l_extendedprice#82, l_discount#83, n_name#962)
    int left_nrow = tbl_JOIN_INNER_TD_4178_output[0].getNumRow();
    int right_nrow = tbl_SerializeFromObject_TD_4614_input.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3467_key_leftMajor, SW_JOIN_INNER_TD_3467_payload_leftMajor> ht1;
    for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
        int nrow1 = tbl_JOIN_INNER_TD_4178_output[p_idx].getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_nationkey345_k = tbl_JOIN_INNER_TD_4178_output[p_idx].getInt32(i, 3);
            SW_JOIN_INNER_TD_3467_key_leftMajor keyA{_s_nationkey345_k};
            int32_t _o_orderdate211 = tbl_JOIN_INNER_TD_4178_output[p_idx].getInt32(i, 0);
            int32_t _l_extendedprice82 = tbl_JOIN_INNER_TD_4178_output[p_idx].getInt32(i, 1);
            int32_t _l_discount83 = tbl_JOIN_INNER_TD_4178_output[p_idx].getInt32(i, 2);
            int32_t _s_nationkey345 = tbl_JOIN_INNER_TD_4178_output[p_idx].getInt32(i, 3);
            int32_t _n_regionkey146 = tbl_JOIN_INNER_TD_4178_output[p_idx].getInt32(i, 4);
            SW_JOIN_INNER_TD_3467_payload_leftMajor payloadA{_o_orderdate211, _l_extendedprice82, _l_discount83, _s_nationkey345, _n_regionkey146};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
    }
        int r = 0;
        int nrow2 = tbl_SerializeFromObject_TD_4614_input.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _n_nationkey961_k = tbl_SerializeFromObject_TD_4614_input.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3467_key_leftMajor{_n_nationkey961_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _o_orderdate211 = (it->second)._o_orderdate211;
                int32_t _l_extendedprice82 = (it->second)._l_extendedprice82;
                int32_t _l_discount83 = (it->second)._l_discount83;
                int32_t _s_nationkey345 = (it->second)._s_nationkey345;
                int32_t _n_regionkey146 = (it->second)._n_regionkey146;
                int32_t _n_nationkey961 = tbl_SerializeFromObject_TD_4614_input.getInt32(i, 0);
                std::array<char, TPCH_READ_NATION_LEN + 1> _n_name962_n = tbl_SerializeFromObject_TD_4614_input.getcharN<char, TPCH_READ_NATION_LEN + 1>(i, 1);
                std::string _n_name962 = std::string(_n_name962_n.data());
                tbl_JOIN_INNER_TD_3467_output.setInt32(r, 0, _o_orderdate211);
                tbl_JOIN_INNER_TD_3467_output.setInt32(r, 1, _l_extendedprice82);
                tbl_JOIN_INNER_TD_3467_output.setInt32(r, 2, _l_discount83);
                tbl_JOIN_INNER_TD_3467_output.setcharN<char, TPCH_READ_NATION_LEN + 1>(r, 3, _n_name962_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3467_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3467_key_rightMajor, SW_JOIN_INNER_TD_3467_payload_rightMajor> ht1;
        int nrow1 = tbl_SerializeFromObject_TD_4614_input.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _n_nationkey961_k = tbl_SerializeFromObject_TD_4614_input.getInt32(i, 0);
            SW_JOIN_INNER_TD_3467_key_rightMajor keyA{_n_nationkey961_k};
            int32_t _n_nationkey961 = tbl_SerializeFromObject_TD_4614_input.getInt32(i, 0);
            std::array<char, TPCH_READ_NATION_LEN + 1> _n_name962_n = tbl_SerializeFromObject_TD_4614_input.getcharN<char, TPCH_READ_NATION_LEN + 1>(i, 1);
            std::string _n_name962 = std::string(_n_name962_n.data());
            SW_JOIN_INNER_TD_3467_payload_rightMajor payloadA{_n_nationkey961, _n_name962};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
    for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
        int nrow2 = tbl_JOIN_INNER_TD_4178_output[p_idx].getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_nationkey345_k = tbl_JOIN_INNER_TD_4178_output[p_idx].getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3467_key_rightMajor{_s_nationkey345_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _n_nationkey961 = (it->second)._n_nationkey961;
                std::string _n_name962 = (it->second)._n_name962;
                std::array<char, TPCH_READ_NATION_LEN + 1> _n_name962_n{};
                memcpy(_n_name962_n.data(), (_n_name962).data(), (_n_name962).length());
                int32_t _o_orderdate211 = tbl_JOIN_INNER_TD_4178_output[p_idx].getInt32(i, 0);
                int32_t _l_extendedprice82 = tbl_JOIN_INNER_TD_4178_output[p_idx].getInt32(i, 1);
                int32_t _l_discount83 = tbl_JOIN_INNER_TD_4178_output[p_idx].getInt32(i, 2);
                int32_t _s_nationkey345 = tbl_JOIN_INNER_TD_4178_output[p_idx].getInt32(i, 3);
                int32_t _n_regionkey146 = tbl_JOIN_INNER_TD_4178_output[p_idx].getInt32(i, 4);
                tbl_JOIN_INNER_TD_3467_output.setcharN<char, TPCH_READ_NATION_LEN + 1>(r, 3, _n_name962_n);
                tbl_JOIN_INNER_TD_3467_output.setInt32(r, 0, _o_orderdate211);
                tbl_JOIN_INNER_TD_3467_output.setInt32(r, 1, _l_extendedprice82);
                tbl_JOIN_INNER_TD_3467_output.setInt32(r, 2, _l_discount83);
                it++;
                r++;
            }
        }
    }
        tbl_JOIN_INNER_TD_3467_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_3467_output #Row: " << tbl_JOIN_INNER_TD_3467_output.getNumRow() << std::endl;
}

void SW_Project_TD_2953(Table &tbl_JOIN_INNER_TD_3467_output, Table &tbl_Project_TD_2953_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(cast((cast(o_orderdate#211 as double) / 10000.0) as int) AS o_year#956, (l_extendedprice#82 * (100 - l_discount#83)) AS volume#957, n_name#962 AS nation#958)
    // Input: ListBuffer(o_orderdate#211, l_extendedprice#82, l_discount#83, n_name#962)
    // Output: ListBuffer(o_year#956, volume#957, nation#958)
    int nrow1 = tbl_JOIN_INNER_TD_3467_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _o_orderdate211 = tbl_JOIN_INNER_TD_3467_output.getInt32(i, 0);
        int32_t _l_extendedprice82 = tbl_JOIN_INNER_TD_3467_output.getInt32(i, 1);
        int32_t _l_discount83 = tbl_JOIN_INNER_TD_3467_output.getInt32(i, 2);
        std::array<char, TPCH_READ_NATION_LEN + 1> _n_name962 = tbl_JOIN_INNER_TD_3467_output.getcharN<char, TPCH_READ_NATION_LEN + 1>(i, 3);
        int32_t _o_year956 = (_o_orderdate211 / 10000.0);
        tbl_Project_TD_2953_output.setInt32(i, 0, _o_year956);
        int32_t _volume957 = (_l_extendedprice82 * (100 - _l_discount83));
        tbl_Project_TD_2953_output.setInt32(i, 1, _volume957);
        std::array<char, TPCH_READ_NATION_LEN + 1> _nation958 = _n_name962;
        tbl_Project_TD_2953_output.setcharN<char, TPCH_READ_NATION_LEN + 1>(i, 2, _nation958);
    }
    tbl_Project_TD_2953_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_2953_output #Row: " << tbl_Project_TD_2953_output.getNumRow() << std::endl;
}

typedef int32_t SW_Aggregate_TD_1108_key;
struct SW_Aggregate_TD_1108_payload {
    int64_t _mkt_share959_sum_0;
    int64_t _mkt_share959_sum_1;
};
void SW_Aggregate_TD_1108(Table &tbl_Project_TD_2953_output, Table &tbl_Aggregate_TD_1108_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(o_year#956, (cast(sum(CASE WHEN (nation#958 = IRAQ) THEN volume#957 ELSE 0 END) as double) / cast(sum(volume#957) as double)) AS mkt_share#959)
    // Input: ListBuffer(o_year#956, volume#957, nation#958)
    // Output: ListBuffer(o_year#956, mkt_share#959)
    std::unordered_map<SW_Aggregate_TD_1108_key, SW_Aggregate_TD_1108_payload> ht1;
    int nrow1 = tbl_Project_TD_2953_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _o_year956 = tbl_Project_TD_2953_output.getInt32(i, 0);
        int32_t _volume957 = tbl_Project_TD_2953_output.getInt32(i, 1);
        std::array<char, TPCH_READ_NATION_LEN + 1> _nation958 = tbl_Project_TD_2953_output.getcharN<char, TPCH_READ_NATION_LEN + 1>(i, 2);
        SW_Aggregate_TD_1108_key k = _o_year956;
        int64_t _mkt_share959_sum_0 = (std::string(_nation958.data()) == "IRAQ") ? _volume957 : 0;
        int64_t _mkt_share959_sum_1 = _volume957;
        SW_Aggregate_TD_1108_payload p{_mkt_share959_sum_0, _mkt_share959_sum_1};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._mkt_share959_sum_0 + _mkt_share959_sum_0;
            p._mkt_share959_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._mkt_share959_sum_1 + _mkt_share959_sum_1;
            p._mkt_share959_sum_1 = sum_1;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        tbl_Aggregate_TD_1108_output.setInt32(r, 0, (it.first));
        int64_t _mkt_share959 = ((it.second)._mkt_share959_sum_0 / (it.second)._mkt_share959_sum_1);
        tbl_Aggregate_TD_1108_output.setInt64(r, 1, _mkt_share959);
        ++r;
    }
    tbl_Aggregate_TD_1108_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_1108_output #Row: " << tbl_Aggregate_TD_1108_output.getNumRow() << std::endl;
}

void SW_Sort_TD_027(Table &tbl_Aggregate_TD_1108_output, Table &tbl_Sort_TD_027_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(o_year#956 ASC NULLS FIRST)
    // Input: ListBuffer(o_year#956, mkt_share#959)
    // Output: ListBuffer(o_year#956, mkt_share#959)
    struct SW_Sort_TD_027Row {
        int32_t _o_year956;
        int64_t _mkt_share959;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_027Row& a, const SW_Sort_TD_027Row& b) const { return 
 (a._o_year956 < b._o_year956); 
}
    }SW_Sort_TD_027_order; 

    int nrow1 = tbl_Aggregate_TD_1108_output.getNumRow();
    std::vector<SW_Sort_TD_027Row> rows;
    for (int i = 0; i < nrow1; i++) {
        int32_t _o_year956 = tbl_Aggregate_TD_1108_output.getInt32(i, 0);
        int64_t _mkt_share959 = tbl_Aggregate_TD_1108_output.getInt64(i, 1);
        SW_Sort_TD_027Row t = {_o_year956,_mkt_share959};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_027_order);
    int r = 0;
    for (auto& it : rows) {
        tbl_Sort_TD_027_output.setInt32(r, 0, it._o_year956);
        tbl_Sort_TD_027_output.setInt64(r, 1, it._mkt_share959);
        if (r < 10) {
            std::cout << it._o_year956 << " " << it._mkt_share959 << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_027_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_027_output #Row: " << tbl_Sort_TD_027_output.getNumRow() << std::endl;
}

