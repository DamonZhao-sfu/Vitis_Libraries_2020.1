#include <regex> 
#include <stdint.h> 

void SW_Filter_TD_8218(Table &tbl_SerializeFromObject_TD_9838_input, Table &tbl_Filter_TD_8218_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((l_shipdate#87 >= 19950101) AND (l_shipdate#87 <= 19961231)))
    // Input: ListBuffer(l_orderkey#77, l_suppkey#79, l_extendedprice#82, l_discount#83, l_shipdate#87)
    // Output: ListBuffer(l_orderkey#77, l_suppkey#79, l_extendedprice#82, l_discount#83, l_shipdate#87)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9838_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _l_shipdate87 = tbl_SerializeFromObject_TD_9838_input.getInt32(i, 4);
        if ((_l_shipdate87 >= 19950101) && (_l_shipdate87 <= 19961231)) {
            int32_t _l_orderkey77_t = tbl_SerializeFromObject_TD_9838_input.getInt32(i, 0);
            tbl_Filter_TD_8218_output.setInt32(r, 0, _l_orderkey77_t);
            int32_t _l_suppkey79_t = tbl_SerializeFromObject_TD_9838_input.getInt32(i, 1);
            tbl_Filter_TD_8218_output.setInt32(r, 1, _l_suppkey79_t);
            int32_t _l_extendedprice82_t = tbl_SerializeFromObject_TD_9838_input.getInt32(i, 2);
            tbl_Filter_TD_8218_output.setInt32(r, 2, _l_extendedprice82_t);
            int32_t _l_discount83_t = tbl_SerializeFromObject_TD_9838_input.getInt32(i, 3);
            tbl_Filter_TD_8218_output.setInt32(r, 3, _l_discount83_t);
            int32_t _l_shipdate87_t = tbl_SerializeFromObject_TD_9838_input.getInt32(i, 4);
            tbl_Filter_TD_8218_output.setInt32(r, 4, _l_shipdate87_t);
            r++;
        }
    }
    tbl_Filter_TD_8218_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8218_output #Row: " << tbl_Filter_TD_8218_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5439(Table &tbl_SerializeFromObject_TD_6553_input, Table &tbl_Filter_TD_5439_output) {
    // StringRowIDSubstitution: true StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((n_name#145 = FRANCE) OR (n_name#145 = IRAQ)))
    // Input: ListBuffer(n_nationkey#144, n_name#145)
    // Output: ListBuffer(n_nationkey#144, n_name#145)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6553_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_NATION_LEN + 1> _n_name145 = tbl_SerializeFromObject_TD_6553_input.getcharN<char, TPCH_READ_NATION_LEN + 1>(i, 1);
        if ((std::string(_n_name145.data()) == "FRANCE") || (std::string(_n_name145.data()) == "IRAQ")) {
            int32_t _n_nationkey144_t = tbl_SerializeFromObject_TD_6553_input.getInt32(i, 0);
            tbl_Filter_TD_5439_output.setInt32(r, 0, _n_nationkey144_t);
            tbl_Filter_TD_5439_output.setInt32(r, 1, i);
            r++;
        }
    }
    tbl_Filter_TD_5439_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5439_output #Row: " << tbl_Filter_TD_5439_output.getNumRow() << std::endl;
}




void SW_Filter_TD_4241(Table &tbl_SerializeFromObject_TD_5601_input, Table &tbl_Filter_TD_4241_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((n_name#879 = IRAQ) OR (n_name#879 = FRANCE)))
    // Input: ListBuffer(n_nationkey#878, n_name#879)
    // Output: ListBuffer(n_nationkey#878, n_name#879)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5601_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_NATION_LEN + 1> _n_name879 = tbl_SerializeFromObject_TD_5601_input.getcharN<char, TPCH_READ_NATION_LEN + 1>(i, 1);
        if ((std::string(_n_name879.data()) == "IRAQ") || (std::string(_n_name879.data()) == "FRANCE")) {
            int32_t _n_nationkey878_t = tbl_SerializeFromObject_TD_5601_input.getInt32(i, 0);
            tbl_Filter_TD_4241_output.setInt32(r, 0, _n_nationkey878_t);
            std::array<char, TPCH_READ_NATION_LEN + 1> _n_name879_t = tbl_SerializeFromObject_TD_5601_input.getcharN<char, TPCH_READ_NATION_LEN + 1>(i, 1);
            tbl_Filter_TD_4241_output.setcharN<char, TPCH_READ_NATION_LEN + 1>(r, 1, _n_name879_t);
            r++;
        }
    }
    tbl_Filter_TD_4241_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4241_output #Row: " << tbl_Filter_TD_4241_output.getNumRow() << std::endl;
}


struct SW_JOIN_INNER_TD_3444_key_leftMajor {
    int32_t _c_nationkey25;
    bool operator==(const SW_JOIN_INNER_TD_3444_key_leftMajor& other) const {
        return ((_c_nationkey25 == other._c_nationkey25));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3444_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3444_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_nationkey25));
    }
};
}
struct SW_JOIN_INNER_TD_3444_payload_leftMajor {
    int32_t _l_extendedprice82;
    int32_t _l_discount83;
    int32_t _l_shipdate87;
    int32_t _c_nationkey25;
    std::string _n_name145;
};
struct SW_JOIN_INNER_TD_3444_key_rightMajor {
    int32_t _n_nationkey878;
    bool operator==(const SW_JOIN_INNER_TD_3444_key_rightMajor& other) const {
        return ((_n_nationkey878 == other._n_nationkey878));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3444_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3444_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._n_nationkey878));
    }
};
}
struct SW_JOIN_INNER_TD_3444_payload_rightMajor {
    int32_t _n_nationkey878;
    std::string _n_name879;
};
void SW_JOIN_INNER_TD_3444(Table *tbl_JOIN_INNER_TD_4775_output, Table &tbl_Filter_TD_4241_output, Table &tbl_SerializeFromObject_TD_6553_input, Table &tbl_JOIN_INNER_TD_3444_output, int hpTimes) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: true
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((c_nationkey#25 = n_nationkey#878) AND (((n_name#145 = FRANCE) AND (n_name#879 = IRAQ)) OR ((n_name#145 = IRAQ) AND (n_name#879 = FRANCE)))))
    // Left Table: ListBuffer(l_extendedprice#82, l_discount#83, l_shipdate#87, c_nationkey#25, n_name#145)
    // Right Table: ListBuffer(n_nationkey#878, n_name#879)
    // Output Table: ListBuffer(n_name#145, n_name#879, l_shipdate#87, l_extendedprice#82, l_discount#83, c_nationkey#25)
    int left_nrow = tbl_JOIN_INNER_TD_4775_output[0].getNumRow();
    int right_nrow = tbl_Filter_TD_4241_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3444_key_leftMajor, SW_JOIN_INNER_TD_3444_payload_leftMajor> ht1;
    for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
        int nrow1 = tbl_JOIN_INNER_TD_4775_output[p_idx].getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_nationkey25_k = tbl_JOIN_INNER_TD_4775_output[p_idx].getInt32(i, 3);
            SW_JOIN_INNER_TD_3444_key_leftMajor keyA{_c_nationkey25_k};
            int32_t _l_extendedprice82 = tbl_JOIN_INNER_TD_4775_output[p_idx].getInt32(i, 0);
            int32_t _l_discount83 = tbl_JOIN_INNER_TD_4775_output[p_idx].getInt32(i, 1);
            int32_t _l_shipdate87 = tbl_JOIN_INNER_TD_4775_output[p_idx].getInt32(i, 2);
            int32_t _c_nationkey25 = tbl_JOIN_INNER_TD_4775_output[p_idx].getInt32(i, 3);
            std::array<char, TPCH_READ_NATION_LEN + 1> _n_name145_n = tbl_SerializeFromObject_TD_6553_input.getcharN<char, TPCH_READ_NATION_LEN + 1>(tbl_JOIN_INNER_TD_4775_output[p_idx].getInt32(i, 4), 1);
            std::string _n_name145 = std::string(_n_name145_n.data());
            SW_JOIN_INNER_TD_3444_payload_leftMajor payloadA{_l_extendedprice82, _l_discount83, _l_shipdate87, _c_nationkey25, _n_name145};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
    }
        int r = 0;
        int nrow2 = tbl_Filter_TD_4241_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _n_nationkey878_k = tbl_Filter_TD_4241_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3444_key_leftMajor{_n_nationkey878_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _l_extendedprice82 = (it->second)._l_extendedprice82;
                int32_t _l_discount83 = (it->second)._l_discount83;
                int32_t _l_shipdate87 = (it->second)._l_shipdate87;
                int32_t _c_nationkey25 = (it->second)._c_nationkey25;
                std::string _n_name145 = (it->second)._n_name145;
                std::array<char, TPCH_READ_NATION_LEN + 1> _n_name145_n{};
                memcpy(_n_name145_n.data(), (_n_name145).data(), (_n_name145).length());
                int32_t _n_nationkey878 = tbl_Filter_TD_4241_output.getInt32(i, 0);
                std::array<char, TPCH_READ_NATION_LEN + 1> _n_name879_n = tbl_Filter_TD_4241_output.getcharN<char, TPCH_READ_NATION_LEN + 1>(i, 1);
                std::string _n_name879 = std::string(_n_name879_n.data());
                if (((_n_name145 == "FRANCE") && (_n_name879 == "IRAQ")) || ((_n_name145 == "IRAQ") && (_n_name879 == "FRANCE"))) {
                    tbl_JOIN_INNER_TD_3444_output.setInt32(r, 3, _l_extendedprice82);
                    tbl_JOIN_INNER_TD_3444_output.setInt32(r, 4, _l_discount83);
                    tbl_JOIN_INNER_TD_3444_output.setInt32(r, 2, _l_shipdate87);
                    tbl_JOIN_INNER_TD_3444_output.setInt32(r, 5, _c_nationkey25);
                    tbl_JOIN_INNER_TD_3444_output.setcharN<char, TPCH_READ_NATION_LEN + 1>(r, 0, _n_name145_n);
                    tbl_JOIN_INNER_TD_3444_output.setcharN<char, TPCH_READ_NATION_LEN + 1>(r, 1, _n_name879_n);
                    r++;
                }
                it++;
            }
        }
        tbl_JOIN_INNER_TD_3444_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3444_key_rightMajor, SW_JOIN_INNER_TD_3444_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_4241_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _n_nationkey878_k = tbl_Filter_TD_4241_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3444_key_rightMajor keyA{_n_nationkey878_k};
            int32_t _n_nationkey878 = tbl_Filter_TD_4241_output.getInt32(i, 0);
            std::array<char, TPCH_READ_NATION_LEN + 1> _n_name879_n = tbl_Filter_TD_4241_output.getcharN<char, TPCH_READ_NATION_LEN + 1>(i, 1);
            std::string _n_name879 = std::string(_n_name879_n.data());
            SW_JOIN_INNER_TD_3444_payload_rightMajor payloadA{_n_nationkey878, _n_name879};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
    for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
        int nrow2 = tbl_JOIN_INNER_TD_4775_output[p_idx].getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_nationkey25_k = tbl_JOIN_INNER_TD_4775_output[p_idx].getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3444_key_rightMajor{_c_nationkey25_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _n_nationkey878 = (it->second)._n_nationkey878;
                std::string _n_name879 = (it->second)._n_name879;
                std::array<char, TPCH_READ_NATION_LEN + 1> _n_name879_n{};
                memcpy(_n_name879_n.data(), (_n_name879).data(), (_n_name879).length());
                int32_t _l_extendedprice82 = tbl_JOIN_INNER_TD_4775_output[p_idx].getInt32(i, 0);
                int32_t _l_discount83 = tbl_JOIN_INNER_TD_4775_output[p_idx].getInt32(i, 1);
                int32_t _l_shipdate87 = tbl_JOIN_INNER_TD_4775_output[p_idx].getInt32(i, 2);
                int32_t _c_nationkey25 = tbl_JOIN_INNER_TD_4775_output[p_idx].getInt32(i, 3);
            std::array<char, TPCH_READ_NATION_LEN + 1> _n_name145_n = tbl_SerializeFromObject_TD_6553_input.getcharN<char, TPCH_READ_NATION_LEN + 1>(tbl_JOIN_INNER_TD_4775_output[p_idx].getInt32(i, 4), 1);
            std::string _n_name145 = std::string(_n_name145_n.data());
                if (((_n_name145 == "FRANCE") && (_n_name879 == "IRAQ")) || ((_n_name145 == "IRAQ") && (_n_name879 == "FRANCE"))) {
                    tbl_JOIN_INNER_TD_3444_output.setcharN<char, TPCH_READ_NATION_LEN + 1>(r, 1, _n_name879_n);
                    tbl_JOIN_INNER_TD_3444_output.setInt32(r, 3, _l_extendedprice82);
                    tbl_JOIN_INNER_TD_3444_output.setInt32(r, 4, _l_discount83);
                    tbl_JOIN_INNER_TD_3444_output.setInt32(r, 2, _l_shipdate87);
                    tbl_JOIN_INNER_TD_3444_output.setInt32(r, 5, _c_nationkey25);
                    tbl_JOIN_INNER_TD_3444_output.setcharN<char, TPCH_READ_NATION_LEN + 1>(r, 0, _n_name145_n);
                    r++;
                }
                it++;
            }
        }
    }
        tbl_JOIN_INNER_TD_3444_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_3444_output #Row: " << tbl_JOIN_INNER_TD_3444_output.getNumRow() << std::endl;
}

void SW_Project_TD_2670(Table &tbl_JOIN_INNER_TD_3444_output, Table &tbl_Project_TD_2670_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(n_name#145 AS supp_nation#872, n_name#879 AS cust_nation#873, cast((cast(l_shipdate#87 as double) / 10000.0) as int) AS l_year#874, (l_extendedprice#82 * (100 - l_discount#83)) AS volume#875)
    // Input: ListBuffer(n_name#145, n_name#879, l_shipdate#87, l_extendedprice#82, l_discount#83, c_nationkey#25)
    // Output: ListBuffer(supp_nation#872, cust_nation#873, l_year#874, volume#875)
    int nrow1 = tbl_JOIN_INNER_TD_3444_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_NATION_LEN + 1> _n_name145 = tbl_JOIN_INNER_TD_3444_output.getcharN<char, TPCH_READ_NATION_LEN + 1>(i, 0);
        std::array<char, TPCH_READ_NATION_LEN + 1> _n_name879 = tbl_JOIN_INNER_TD_3444_output.getcharN<char, TPCH_READ_NATION_LEN + 1>(i, 1);
        int32_t _l_shipdate87 = tbl_JOIN_INNER_TD_3444_output.getInt32(i, 2);
        int32_t _l_extendedprice82 = tbl_JOIN_INNER_TD_3444_output.getInt32(i, 3);
        int32_t _l_discount83 = tbl_JOIN_INNER_TD_3444_output.getInt32(i, 4);
        int32_t _c_nationkey25 = tbl_JOIN_INNER_TD_3444_output.getInt32(i, 5);
        std::array<char, TPCH_READ_NATION_LEN + 1> _supp_nation872 = _n_name145;
        tbl_Project_TD_2670_output.setcharN<char, TPCH_READ_NATION_LEN + 1>(i, 0, _supp_nation872);
        std::array<char, TPCH_READ_NATION_LEN + 1> _cust_nation873 = _n_name879;
        tbl_Project_TD_2670_output.setcharN<char, TPCH_READ_NATION_LEN + 1>(i, 1, _cust_nation873);
        int32_t _l_year874 = (_l_shipdate87 / 10000.0);
        tbl_Project_TD_2670_output.setInt32(i, 2, _l_year874);
        int32_t _volume875 = (_l_extendedprice82 * (100 - _l_discount83));
        tbl_Project_TD_2670_output.setInt32(i, 3, _volume875);
    }
    tbl_Project_TD_2670_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_2670_output #Row: " << tbl_Project_TD_2670_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_143_key {
    std::string _supp_nation872;
    std::string _cust_nation873;
    int32_t _l_year874;
    bool operator==(const SW_Aggregate_TD_143_key& other) const { return (_supp_nation872 == other._supp_nation872) && (_cust_nation873 == other._cust_nation873) && (_l_year874 == other._l_year874); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_143_key> {
    std::size_t operator() (const SW_Aggregate_TD_143_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._supp_nation872)) + (hash<string>()(k._cust_nation873)) + (hash<int32_t>()(k._l_year874));
    }
};
}
struct SW_Aggregate_TD_143_payload {
    int64_t _revenue876L_sum_0;
};
void SW_Aggregate_TD_143(Table &tbl_Project_TD_2670_output, Table &tbl_Aggregate_TD_143_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(supp_nation#872, cust_nation#873, l_year#874, sum(volume#875) AS revenue#876L)
    // Input: ListBuffer(supp_nation#872, cust_nation#873, l_year#874, volume#875)
    // Output: ListBuffer(supp_nation#872, cust_nation#873, l_year#874, revenue#876L)
    std::unordered_map<SW_Aggregate_TD_143_key, SW_Aggregate_TD_143_payload> ht1;
    int nrow1 = tbl_Project_TD_2670_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_NATION_LEN + 1> _supp_nation872 = tbl_Project_TD_2670_output.getcharN<char, TPCH_READ_NATION_LEN + 1>(i, 0);
        std::array<char, TPCH_READ_NATION_LEN + 1> _cust_nation873 = tbl_Project_TD_2670_output.getcharN<char, TPCH_READ_NATION_LEN + 1>(i, 1);
        int32_t _l_year874 = tbl_Project_TD_2670_output.getInt32(i, 2);
        int32_t _volume875 = tbl_Project_TD_2670_output.getInt32(i, 3);
        SW_Aggregate_TD_143_key k{std::string(_supp_nation872.data()), std::string(_cust_nation873.data()), _l_year874};
        int64_t _revenue876L_sum_0 = _volume875;
        SW_Aggregate_TD_143_payload p{_revenue876L_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._revenue876L_sum_0 + _revenue876L_sum_0;
            p._revenue876L_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCH_READ_NATION_LEN + 1> _supp_nation872{};
        memcpy(_supp_nation872.data(), ((it.first)._supp_nation872).data(), ((it.first)._supp_nation872).length());
        tbl_Aggregate_TD_143_output.setcharN<char, TPCH_READ_NATION_LEN + 1>(r, 0, _supp_nation872);
        std::array<char, TPCH_READ_NATION_LEN + 1> _cust_nation873{};
        memcpy(_cust_nation873.data(), ((it.first)._cust_nation873).data(), ((it.first)._cust_nation873).length());
        tbl_Aggregate_TD_143_output.setcharN<char, TPCH_READ_NATION_LEN + 1>(r, 1, _cust_nation873);
        tbl_Aggregate_TD_143_output.setInt32(r, 2, (it.first)._l_year874);
        int64_t _revenue876L = (it.second)._revenue876L_sum_0;
        tbl_Aggregate_TD_143_output.setInt64(r, 3, _revenue876L);
        ++r;
    }
    tbl_Aggregate_TD_143_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_143_output #Row: " << tbl_Aggregate_TD_143_output.getNumRow() << std::endl;
}

void SW_Sort_TD_0792(Table &tbl_Aggregate_TD_143_output, Table &tbl_Sort_TD_0792_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(supp_nation#872 ASC NULLS FIRST, cust_nation#873 ASC NULLS FIRST, l_year#874 ASC NULLS FIRST)
    // Input: ListBuffer(supp_nation#872, cust_nation#873, l_year#874, revenue#876L)
    // Output: ListBuffer(supp_nation#872, cust_nation#873, l_year#874, revenue#876L)
    struct SW_Sort_TD_0792Row {
        std::string _supp_nation872;
        std::string _cust_nation873;
        int32_t _l_year874;
        int64_t _revenue876L;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_0792Row& a, const SW_Sort_TD_0792Row& b) const { return 
 (a._supp_nation872 < b._supp_nation872) || 
 ((a._supp_nation872 == b._supp_nation872) && (a._cust_nation873 < b._cust_nation873)) || 
 ((a._supp_nation872 == b._supp_nation872) && (a._cust_nation873 == b._cust_nation873) && (a._l_year874 < b._l_year874)); 
}
    }SW_Sort_TD_0792_order; 

    int nrow1 = tbl_Aggregate_TD_143_output.getNumRow();
    std::vector<SW_Sort_TD_0792Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_NATION_LEN + 1> _supp_nation872 = tbl_Aggregate_TD_143_output.getcharN<char, TPCH_READ_NATION_LEN +1>(i, 0);
        std::array<char, TPCH_READ_NATION_LEN + 1> _cust_nation873 = tbl_Aggregate_TD_143_output.getcharN<char, TPCH_READ_NATION_LEN +1>(i, 1);
        int32_t _l_year874 = tbl_Aggregate_TD_143_output.getInt32(i, 2);
        int64_t _revenue876L = tbl_Aggregate_TD_143_output.getInt64(i, 3);
        SW_Sort_TD_0792Row t = {std::string(_supp_nation872.data()),std::string(_cust_nation873.data()),_l_year874,_revenue876L};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_0792_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCH_READ_NATION_LEN + 1> _supp_nation872{};
        memcpy(_supp_nation872.data(), (it._supp_nation872).data(), (it._supp_nation872).length());
        tbl_Sort_TD_0792_output.setcharN<char, TPCH_READ_NATION_LEN +1>(r, 0, _supp_nation872);
        std::array<char, TPCH_READ_NATION_LEN + 1> _cust_nation873{};
        memcpy(_cust_nation873.data(), (it._cust_nation873).data(), (it._cust_nation873).length());
        tbl_Sort_TD_0792_output.setcharN<char, TPCH_READ_NATION_LEN +1>(r, 1, _cust_nation873);
        tbl_Sort_TD_0792_output.setInt32(r, 2, it._l_year874);
        tbl_Sort_TD_0792_output.setInt64(r, 3, it._revenue876L);
        if (r < 10) {
            std::cout << (it._supp_nation872).data() << " " << (it._cust_nation873).data() << " " << it._l_year874 << " " << it._revenue876L << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_0792_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_0792_output #Row: " << tbl_Sort_TD_0792_output.getNumRow() << std::endl;
}

