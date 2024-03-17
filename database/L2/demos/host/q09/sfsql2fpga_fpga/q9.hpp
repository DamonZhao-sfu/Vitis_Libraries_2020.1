#include <regex> 
#include <stdint.h> 

void SW_Filter_TD_865(Table &tbl_SerializeFromObject_TD_9775_input, Table &tbl_Filter_TD_865_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(p_name#259) AND Contains(p_name#259, magenta)))
    // Input: ListBuffer(p_partkey#258, p_name#259)
    // Output: ListBuffer(p_partkey#258)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9775_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_P_NAME_LEN + 1> _p_name259 = tbl_SerializeFromObject_TD_9775_input.getcharN<char, TPCH_READ_P_NAME_LEN + 1>(i, 1);
        if ((1) && (std::string(_p_name259.data()).find("magenta")!=std::string::npos)) {
            int32_t _p_partkey258_t = tbl_SerializeFromObject_TD_9775_input.getInt32(i, 0);
            tbl_Filter_TD_865_output.setInt32(r, 0, _p_partkey258_t);
            r++;
        }
    }
    tbl_Filter_TD_865_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_865_output #Row: " << tbl_Filter_TD_865_output.getNumRow() << std::endl;
}





struct SW_JOIN_INNER_TD_3174_key_leftMajor {
    int32_t _s_nationkey345;
    bool operator==(const SW_JOIN_INNER_TD_3174_key_leftMajor& other) const {
        return ((_s_nationkey345 == other._s_nationkey345));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3174_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3174_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_nationkey345));
    }
};
}
struct SW_JOIN_INNER_TD_3174_payload_leftMajor {
    int32_t _l_quantity81;
    int32_t _l_extendedprice82;
    int32_t _l_discount83;
    int32_t _s_nationkey345;
    int32_t _ps_supplycost308;
    int32_t _o_orderdate211;
};
struct SW_JOIN_INNER_TD_3174_key_rightMajor {
    int32_t _n_nationkey144;
    bool operator==(const SW_JOIN_INNER_TD_3174_key_rightMajor& other) const {
        return ((_n_nationkey144 == other._n_nationkey144));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3174_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3174_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._n_nationkey144));
    }
};
}
struct SW_JOIN_INNER_TD_3174_payload_rightMajor {
    int32_t _n_nationkey144;
    std::string _n_name145;
};
void SW_JOIN_INNER_TD_3174(Table *tbl_JOIN_INNER_TD_4550_output, Table &tbl_SerializeFromObject_TD_4433_input, Table &tbl_JOIN_INNER_TD_3174_output, int hpTimes) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((s_nationkey#345 = n_nationkey#144))
    // Left Table: ListBuffer(l_quantity#81, l_extendedprice#82, l_discount#83, s_nationkey#345, ps_supplycost#308, o_orderdate#211)
    // Right Table: ListBuffer(n_nationkey#144, n_name#145)
    // Output Table: ListBuffer(n_name#145, o_orderdate#211, l_extendedprice#82, l_discount#83, ps_supplycost#308, l_quantity#81)
    int left_nrow = tbl_JOIN_INNER_TD_4550_output[0].getNumRow();
    int right_nrow = tbl_SerializeFromObject_TD_4433_input.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3174_key_leftMajor, SW_JOIN_INNER_TD_3174_payload_leftMajor> ht1;
    for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
        int nrow1 = tbl_JOIN_INNER_TD_4550_output[p_idx].getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_nationkey345_k = tbl_JOIN_INNER_TD_4550_output[p_idx].getInt32(i, 3);
            SW_JOIN_INNER_TD_3174_key_leftMajor keyA{_s_nationkey345_k};
            int32_t _l_quantity81 = tbl_JOIN_INNER_TD_4550_output[p_idx].getInt32(i, 0);
            int32_t _l_extendedprice82 = tbl_JOIN_INNER_TD_4550_output[p_idx].getInt32(i, 1);
            int32_t _l_discount83 = tbl_JOIN_INNER_TD_4550_output[p_idx].getInt32(i, 2);
            int32_t _s_nationkey345 = tbl_JOIN_INNER_TD_4550_output[p_idx].getInt32(i, 3);
            int32_t _ps_supplycost308 = tbl_JOIN_INNER_TD_4550_output[p_idx].getInt32(i, 4);
            int32_t _o_orderdate211 = tbl_JOIN_INNER_TD_4550_output[p_idx].getInt32(i, 5);
            SW_JOIN_INNER_TD_3174_payload_leftMajor payloadA{_l_quantity81, _l_extendedprice82, _l_discount83, _s_nationkey345, _ps_supplycost308, _o_orderdate211};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
    }
        int r = 0;
        int nrow2 = tbl_SerializeFromObject_TD_4433_input.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _n_nationkey144_k = tbl_SerializeFromObject_TD_4433_input.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3174_key_leftMajor{_n_nationkey144_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _l_quantity81 = (it->second)._l_quantity81;
                int32_t _l_extendedprice82 = (it->second)._l_extendedprice82;
                int32_t _l_discount83 = (it->second)._l_discount83;
                int32_t _s_nationkey345 = (it->second)._s_nationkey345;
                int32_t _ps_supplycost308 = (it->second)._ps_supplycost308;
                int32_t _o_orderdate211 = (it->second)._o_orderdate211;
                int32_t _n_nationkey144 = tbl_SerializeFromObject_TD_4433_input.getInt32(i, 0);
                std::array<char, TPCH_READ_NATION_LEN + 1> _n_name145_n = tbl_SerializeFromObject_TD_4433_input.getcharN<char, TPCH_READ_NATION_LEN + 1>(i, 1);
                std::string _n_name145 = std::string(_n_name145_n.data());
                tbl_JOIN_INNER_TD_3174_output.setInt32(r, 5, _l_quantity81);
                tbl_JOIN_INNER_TD_3174_output.setInt32(r, 2, _l_extendedprice82);
                tbl_JOIN_INNER_TD_3174_output.setInt32(r, 3, _l_discount83);
                tbl_JOIN_INNER_TD_3174_output.setInt32(r, 4, _ps_supplycost308);
                tbl_JOIN_INNER_TD_3174_output.setInt32(r, 1, _o_orderdate211);
                tbl_JOIN_INNER_TD_3174_output.setcharN<char, TPCH_READ_NATION_LEN + 1>(r, 0, _n_name145_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3174_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3174_key_rightMajor, SW_JOIN_INNER_TD_3174_payload_rightMajor> ht1;
        int nrow1 = tbl_SerializeFromObject_TD_4433_input.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _n_nationkey144_k = tbl_SerializeFromObject_TD_4433_input.getInt32(i, 0);
            SW_JOIN_INNER_TD_3174_key_rightMajor keyA{_n_nationkey144_k};
            int32_t _n_nationkey144 = tbl_SerializeFromObject_TD_4433_input.getInt32(i, 0);
            std::array<char, TPCH_READ_NATION_LEN + 1> _n_name145_n = tbl_SerializeFromObject_TD_4433_input.getcharN<char, TPCH_READ_NATION_LEN + 1>(i, 1);
            std::string _n_name145 = std::string(_n_name145_n.data());
            SW_JOIN_INNER_TD_3174_payload_rightMajor payloadA{_n_nationkey144, _n_name145};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
    for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
        int nrow2 = tbl_JOIN_INNER_TD_4550_output[p_idx].getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_nationkey345_k = tbl_JOIN_INNER_TD_4550_output[p_idx].getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3174_key_rightMajor{_s_nationkey345_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _n_nationkey144 = (it->second)._n_nationkey144;
                std::string _n_name145 = (it->second)._n_name145;
                std::array<char, TPCH_READ_NATION_LEN + 1> _n_name145_n{};
                memcpy(_n_name145_n.data(), (_n_name145).data(), (_n_name145).length());
                int32_t _l_quantity81 = tbl_JOIN_INNER_TD_4550_output[p_idx].getInt32(i, 0);
                int32_t _l_extendedprice82 = tbl_JOIN_INNER_TD_4550_output[p_idx].getInt32(i, 1);
                int32_t _l_discount83 = tbl_JOIN_INNER_TD_4550_output[p_idx].getInt32(i, 2);
                int32_t _s_nationkey345 = tbl_JOIN_INNER_TD_4550_output[p_idx].getInt32(i, 3);
                int32_t _ps_supplycost308 = tbl_JOIN_INNER_TD_4550_output[p_idx].getInt32(i, 4);
                int32_t _o_orderdate211 = tbl_JOIN_INNER_TD_4550_output[p_idx].getInt32(i, 5);
                tbl_JOIN_INNER_TD_3174_output.setcharN<char, TPCH_READ_NATION_LEN + 1>(r, 0, _n_name145_n);
                tbl_JOIN_INNER_TD_3174_output.setInt32(r, 5, _l_quantity81);
                tbl_JOIN_INNER_TD_3174_output.setInt32(r, 2, _l_extendedprice82);
                tbl_JOIN_INNER_TD_3174_output.setInt32(r, 3, _l_discount83);
                tbl_JOIN_INNER_TD_3174_output.setInt32(r, 4, _ps_supplycost308);
                tbl_JOIN_INNER_TD_3174_output.setInt32(r, 1, _o_orderdate211);
                it++;
                r++;
            }
        }
    }
        tbl_JOIN_INNER_TD_3174_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_3174_output #Row: " << tbl_JOIN_INNER_TD_3174_output.getNumRow() << std::endl;
}

void SW_Project_TD_2289(Table &tbl_JOIN_INNER_TD_3174_output, Table &tbl_Project_TD_2289_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(n_name#145 AS nation#1083, cast((cast(o_orderdate#211 as double) / 10000.0) as int) AS o_year#1084, ((l_extendedprice#82 * (1 - l_discount#83)) - (ps_supplycost#308 * l_quantity#81)) AS amount#1085)
    // Input: ListBuffer(n_name#145, o_orderdate#211, l_extendedprice#82, l_discount#83, ps_supplycost#308, l_quantity#81)
    // Output: ListBuffer(nation#1083, o_year#1084, amount#1085)
    int nrow1 = tbl_JOIN_INNER_TD_3174_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_NATION_LEN + 1> _n_name145 = tbl_JOIN_INNER_TD_3174_output.getcharN<char, TPCH_READ_NATION_LEN + 1>(i, 0);
        int32_t _o_orderdate211 = tbl_JOIN_INNER_TD_3174_output.getInt32(i, 1);
        int32_t _l_extendedprice82 = tbl_JOIN_INNER_TD_3174_output.getInt32(i, 2);
        int32_t _l_discount83 = tbl_JOIN_INNER_TD_3174_output.getInt32(i, 3);
        int32_t _ps_supplycost308 = tbl_JOIN_INNER_TD_3174_output.getInt32(i, 4);
        int32_t _l_quantity81 = tbl_JOIN_INNER_TD_3174_output.getInt32(i, 5);
        std::array<char, TPCH_READ_NATION_LEN + 1> _nation1083 = _n_name145;
        tbl_Project_TD_2289_output.setcharN<char, TPCH_READ_NATION_LEN + 1>(i, 0, _nation1083);
        int32_t _o_year1084 = (_o_orderdate211 / 10000.0);
        tbl_Project_TD_2289_output.setInt32(i, 1, _o_year1084);
        int32_t _amount1085 = ((_l_extendedprice82 * (1 - _l_discount83)) - (_ps_supplycost308 * _l_quantity81));
        tbl_Project_TD_2289_output.setInt32(i, 2, _amount1085);
    }
    tbl_Project_TD_2289_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_2289_output #Row: " << tbl_Project_TD_2289_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_1479_key {
    std::string _nation1083;
    int32_t _o_year1084;
    bool operator==(const SW_Aggregate_TD_1479_key& other) const { return (_nation1083 == other._nation1083) && (_o_year1084 == other._o_year1084); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_1479_key> {
    std::size_t operator() (const SW_Aggregate_TD_1479_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._nation1083)) + (hash<int32_t>()(k._o_year1084));
    }
};
}
struct SW_Aggregate_TD_1479_payload {
    int64_t _sum_profit1086L_sum_0;
};
void SW_Aggregate_TD_1479(Table &tbl_Project_TD_2289_output, Table &tbl_Aggregate_TD_1479_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(nation#1083, o_year#1084, sum(amount#1085) AS sum_profit#1086L)
    // Input: ListBuffer(nation#1083, o_year#1084, amount#1085)
    // Output: ListBuffer(nation#1083, o_year#1084, sum_profit#1086L)
    std::unordered_map<SW_Aggregate_TD_1479_key, SW_Aggregate_TD_1479_payload> ht1;
    int nrow1 = tbl_Project_TD_2289_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_NATION_LEN + 1> _nation1083 = tbl_Project_TD_2289_output.getcharN<char, TPCH_READ_NATION_LEN + 1>(i, 0);
        int32_t _o_year1084 = tbl_Project_TD_2289_output.getInt32(i, 1);
        int32_t _amount1085 = tbl_Project_TD_2289_output.getInt32(i, 2);
        SW_Aggregate_TD_1479_key k{std::string(_nation1083.data()), _o_year1084};
        int64_t _sum_profit1086L_sum_0 = _amount1085;
        SW_Aggregate_TD_1479_payload p{_sum_profit1086L_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._sum_profit1086L_sum_0 + _sum_profit1086L_sum_0;
            p._sum_profit1086L_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCH_READ_NATION_LEN + 1> _nation1083{};
        memcpy(_nation1083.data(), ((it.first)._nation1083).data(), ((it.first)._nation1083).length());
        tbl_Aggregate_TD_1479_output.setcharN<char, TPCH_READ_NATION_LEN + 1>(r, 0, _nation1083);
        tbl_Aggregate_TD_1479_output.setInt32(r, 1, (it.first)._o_year1084);
        int64_t _sum_profit1086L = (it.second)._sum_profit1086L_sum_0;
        tbl_Aggregate_TD_1479_output.setInt64(r, 2, _sum_profit1086L);
        ++r;
    }
    tbl_Aggregate_TD_1479_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_1479_output #Row: " << tbl_Aggregate_TD_1479_output.getNumRow() << std::endl;
}

void SW_Sort_TD_0706(Table &tbl_Aggregate_TD_1479_output, Table &tbl_Sort_TD_0706_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(nation#1083 ASC NULLS FIRST, o_year#1084 DESC NULLS LAST)
    // Input: ListBuffer(nation#1083, o_year#1084, sum_profit#1086L)
    // Output: ListBuffer(nation#1083, o_year#1084, sum_profit#1086L)
    struct SW_Sort_TD_0706Row {
        std::string _nation1083;
        int32_t _o_year1084;
        int64_t _sum_profit1086L;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_0706Row& a, const SW_Sort_TD_0706Row& b) const { return 
 (a._nation1083 < b._nation1083) || 
 ((a._nation1083 == b._nation1083) && (a._o_year1084 > b._o_year1084)); 
}
    }SW_Sort_TD_0706_order; 

    int nrow1 = tbl_Aggregate_TD_1479_output.getNumRow();
    std::vector<SW_Sort_TD_0706Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_NATION_LEN + 1> _nation1083 = tbl_Aggregate_TD_1479_output.getcharN<char, TPCH_READ_NATION_LEN +1>(i, 0);
        int32_t _o_year1084 = tbl_Aggregate_TD_1479_output.getInt32(i, 1);
        int64_t _sum_profit1086L = tbl_Aggregate_TD_1479_output.getInt64(i, 2);
        SW_Sort_TD_0706Row t = {std::string(_nation1083.data()),_o_year1084,_sum_profit1086L};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_0706_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCH_READ_NATION_LEN + 1> _nation1083{};
        memcpy(_nation1083.data(), (it._nation1083).data(), (it._nation1083).length());
        tbl_Sort_TD_0706_output.setcharN<char, TPCH_READ_NATION_LEN +1>(r, 0, _nation1083);
        tbl_Sort_TD_0706_output.setInt32(r, 1, it._o_year1084);
        tbl_Sort_TD_0706_output.setInt64(r, 2, it._sum_profit1086L);
        if (r < 10) {
            std::cout << (it._nation1083).data() << " " << it._o_year1084 << " " << it._sum_profit1086L << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_0706_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_0706_output #Row: " << tbl_Sort_TD_0706_output.getNumRow() << std::endl;
}

