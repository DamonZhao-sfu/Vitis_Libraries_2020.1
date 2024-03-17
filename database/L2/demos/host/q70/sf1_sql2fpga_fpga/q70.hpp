#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_13278379(Table &tbl_SerializeFromObject_TD_14958137_input, Table &tbl_Filter_TD_13278379_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(s_store_sk#3585))
    // Input: ListBuffer(s_store_sk#3585, s_state#3609)
    // Output: ListBuffer(s_store_sk#3585, s_state#3609)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_14958137_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _s_store_sk3585 = tbl_SerializeFromObject_TD_14958137_input.getInt32(i, 0);
        if (_s_store_sk3585!= 0) {
            int32_t _s_store_sk3585_t = tbl_SerializeFromObject_TD_14958137_input.getInt32(i, 0);
            tbl_Filter_TD_13278379_output.setInt32(r, 0, _s_store_sk3585_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_state3609_t = tbl_SerializeFromObject_TD_14958137_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_13278379_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_state3609_t);
            r++;
        }
    }
    tbl_Filter_TD_13278379_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_13278379_output #Row: " << tbl_Filter_TD_13278379_output.getNumRow() << std::endl;
}

void SW_Filter_TD_13179144(Table &tbl_SerializeFromObject_TD_14148582_input, Table &tbl_Filter_TD_13179144_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_store_sk#3569) AND isnotnull(ss_sold_date_sk#3562)))
    // Input: ListBuffer(ss_sold_date_sk#3562, ss_store_sk#3569, ss_net_profit#3584)
    // Output: ListBuffer(ss_sold_date_sk#3562, ss_store_sk#3569, ss_net_profit#3584)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_14148582_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_store_sk3569 = tbl_SerializeFromObject_TD_14148582_input.getInt32(i, 1);
        int32_t _ss_sold_date_sk3562 = tbl_SerializeFromObject_TD_14148582_input.getInt32(i, 0);
        if ((_ss_store_sk3569!= 0) && (_ss_sold_date_sk3562!= 0)) {
            int32_t _ss_sold_date_sk3562_t = tbl_SerializeFromObject_TD_14148582_input.getInt32(i, 0);
            tbl_Filter_TD_13179144_output.setInt32(r, 0, _ss_sold_date_sk3562_t);
            int32_t _ss_store_sk3569_t = tbl_SerializeFromObject_TD_14148582_input.getInt32(i, 1);
            tbl_Filter_TD_13179144_output.setInt32(r, 1, _ss_store_sk3569_t);
            int64_t _ss_net_profit3584_t = tbl_SerializeFromObject_TD_14148582_input.getInt64(i, 2);
            tbl_Filter_TD_13179144_output.setInt64(r, 2, _ss_net_profit3584_t);
            r++;
        }
    }
    tbl_Filter_TD_13179144_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_13179144_output #Row: " << tbl_Filter_TD_13179144_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12933514(Table &tbl_SerializeFromObject_TD_13738402_input, Table &tbl_Filter_TD_12933514_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_month_seq#3617) AND ((d_month_seq#3617 >= 1200) AND (d_month_seq#3617 <= 1211))) AND isnotnull(d_date_sk#3614)))
    // Input: ListBuffer(d_date_sk#3614, d_month_seq#3617)
    // Output: ListBuffer(d_date_sk#3614)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13738402_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_month_seq3617 = tbl_SerializeFromObject_TD_13738402_input.getInt32(i, 1);
        int32_t _d_date_sk3614 = tbl_SerializeFromObject_TD_13738402_input.getInt32(i, 0);
        if (((_d_month_seq3617!= 0) && ((_d_month_seq3617 >= 1200) && (_d_month_seq3617 <= 1211))) && (_d_date_sk3614!= 0)) {
            int32_t _d_date_sk3614_t = tbl_SerializeFromObject_TD_13738402_input.getInt32(i, 0);
            tbl_Filter_TD_12933514_output.setInt32(r, 0, _d_date_sk3614_t);
            r++;
        }
    }
    tbl_Filter_TD_12933514_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12933514_output #Row: " << tbl_Filter_TD_12933514_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_12232573_key_leftMajor {
    int32_t _ss_store_sk3569;
    bool operator==(const SW_JOIN_INNER_TD_12232573_key_leftMajor& other) const {
        return ((_ss_store_sk3569 == other._ss_store_sk3569));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_12232573_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_12232573_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_store_sk3569));
    }
};
}
struct SW_JOIN_INNER_TD_12232573_payload_leftMajor {
    int32_t _ss_sold_date_sk3562;
    int32_t _ss_store_sk3569;
    int64_t _ss_net_profit3584;
};
struct SW_JOIN_INNER_TD_12232573_key_rightMajor {
    int32_t _s_store_sk3585;
    bool operator==(const SW_JOIN_INNER_TD_12232573_key_rightMajor& other) const {
        return ((_s_store_sk3585 == other._s_store_sk3585));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_12232573_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_12232573_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_store_sk3585));
    }
};
}
struct SW_JOIN_INNER_TD_12232573_payload_rightMajor {
    int32_t _s_store_sk3585;
    std::string _s_state3609;
};
void SW_JOIN_INNER_TD_12232573(Table &tbl_Filter_TD_13179144_output, Table &tbl_Filter_TD_13278379_output, Table &tbl_JOIN_INNER_TD_12232573_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((s_store_sk#3585 = ss_store_sk#3569))
    // Left Table: ListBuffer(ss_sold_date_sk#3562, ss_store_sk#3569, ss_net_profit#3584)
    // Right Table: ListBuffer(s_store_sk#3585, s_state#3609)
    // Output Table: ListBuffer(ss_sold_date_sk#3562, ss_net_profit#3584, s_state#3609)
    int left_nrow = tbl_Filter_TD_13179144_output.getNumRow();
    int right_nrow = tbl_Filter_TD_13278379_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_12232573_key_leftMajor, SW_JOIN_INNER_TD_12232573_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_13179144_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_store_sk3569_k = tbl_Filter_TD_13179144_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_12232573_key_leftMajor keyA{_ss_store_sk3569_k};
            int32_t _ss_sold_date_sk3562 = tbl_Filter_TD_13179144_output.getInt32(i, 0);
            int32_t _ss_store_sk3569 = tbl_Filter_TD_13179144_output.getInt32(i, 1);
            int64_t _ss_net_profit3584 = tbl_Filter_TD_13179144_output.getInt64(i, 2);
            SW_JOIN_INNER_TD_12232573_payload_leftMajor payloadA{_ss_sold_date_sk3562, _ss_store_sk3569, _ss_net_profit3584};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_13278379_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_store_sk3585_k = tbl_Filter_TD_13278379_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_12232573_key_leftMajor{_s_store_sk3585_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk3562 = (it->second)._ss_sold_date_sk3562;
                int32_t _ss_store_sk3569 = (it->second)._ss_store_sk3569;
                int64_t _ss_net_profit3584 = (it->second)._ss_net_profit3584;
                int32_t _s_store_sk3585 = tbl_Filter_TD_13278379_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _s_state3609_n = tbl_Filter_TD_13278379_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _s_state3609 = std::string(_s_state3609_n.data());
                tbl_JOIN_INNER_TD_12232573_output.setInt32(r, 0, _ss_sold_date_sk3562);
                tbl_JOIN_INNER_TD_12232573_output.setInt64(r, 1, _ss_net_profit3584);
                tbl_JOIN_INNER_TD_12232573_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_state3609_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_12232573_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_12232573_key_rightMajor, SW_JOIN_INNER_TD_12232573_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_13278379_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_store_sk3585_k = tbl_Filter_TD_13278379_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_12232573_key_rightMajor keyA{_s_store_sk3585_k};
            int32_t _s_store_sk3585 = tbl_Filter_TD_13278379_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _s_state3609_n = tbl_Filter_TD_13278379_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _s_state3609 = std::string(_s_state3609_n.data());
            SW_JOIN_INNER_TD_12232573_payload_rightMajor payloadA{_s_store_sk3585, _s_state3609};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_13179144_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_store_sk3569_k = tbl_Filter_TD_13179144_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_12232573_key_rightMajor{_ss_store_sk3569_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _s_store_sk3585 = (it->second)._s_store_sk3585;
                std::string _s_state3609 = (it->second)._s_state3609;
                std::array<char, TPCDS_READ_MAX + 1> _s_state3609_n{};
                memcpy(_s_state3609_n.data(), (_s_state3609).data(), (_s_state3609).length());
                int32_t _ss_sold_date_sk3562 = tbl_Filter_TD_13179144_output.getInt32(i, 0);
                int32_t _ss_store_sk3569 = tbl_Filter_TD_13179144_output.getInt32(i, 1);
                int64_t _ss_net_profit3584 = tbl_Filter_TD_13179144_output.getInt64(i, 2);
                tbl_JOIN_INNER_TD_12232573_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_state3609_n);
                tbl_JOIN_INNER_TD_12232573_output.setInt32(r, 0, _ss_sold_date_sk3562);
                tbl_JOIN_INNER_TD_12232573_output.setInt64(r, 1, _ss_net_profit3584);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_12232573_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_12232573_output #Row: " << tbl_JOIN_INNER_TD_12232573_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_11784386_key_leftMajor {
    int32_t _ss_sold_date_sk3562;
    bool operator==(const SW_JOIN_INNER_TD_11784386_key_leftMajor& other) const {
        return ((_ss_sold_date_sk3562 == other._ss_sold_date_sk3562));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11784386_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11784386_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_sold_date_sk3562));
    }
};
}
struct SW_JOIN_INNER_TD_11784386_payload_leftMajor {
    int32_t _ss_sold_date_sk3562;
    int64_t _ss_net_profit3584;
    std::string _s_state3609;
};
struct SW_JOIN_INNER_TD_11784386_key_rightMajor {
    int32_t _d_date_sk3614;
    bool operator==(const SW_JOIN_INNER_TD_11784386_key_rightMajor& other) const {
        return ((_d_date_sk3614 == other._d_date_sk3614));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11784386_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11784386_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk3614));
    }
};
}
struct SW_JOIN_INNER_TD_11784386_payload_rightMajor {
    int32_t _d_date_sk3614;
};
void SW_JOIN_INNER_TD_11784386(Table &tbl_JOIN_INNER_TD_12232573_output, Table &tbl_Filter_TD_12933514_output, Table &tbl_JOIN_INNER_TD_11784386_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((d_date_sk#3614 = ss_sold_date_sk#3562))
    // Left Table: ListBuffer(ss_sold_date_sk#3562, ss_net_profit#3584, s_state#3609)
    // Right Table: ListBuffer(d_date_sk#3614)
    // Output Table: ListBuffer(ss_net_profit#3584, s_state#3609)
    int left_nrow = tbl_JOIN_INNER_TD_12232573_output.getNumRow();
    int right_nrow = tbl_Filter_TD_12933514_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11784386_key_leftMajor, SW_JOIN_INNER_TD_11784386_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_12232573_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_sold_date_sk3562_k = tbl_JOIN_INNER_TD_12232573_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_11784386_key_leftMajor keyA{_ss_sold_date_sk3562_k};
            int32_t _ss_sold_date_sk3562 = tbl_JOIN_INNER_TD_12232573_output.getInt32(i, 0);
            int64_t _ss_net_profit3584 = tbl_JOIN_INNER_TD_12232573_output.getInt64(i, 1);
            std::array<char, TPCDS_READ_MAX + 1> _s_state3609_n = tbl_JOIN_INNER_TD_12232573_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _s_state3609 = std::string(_s_state3609_n.data());
            SW_JOIN_INNER_TD_11784386_payload_leftMajor payloadA{_ss_sold_date_sk3562, _ss_net_profit3584, _s_state3609};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_12933514_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk3614_k = tbl_Filter_TD_12933514_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11784386_key_leftMajor{_d_date_sk3614_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk3562 = (it->second)._ss_sold_date_sk3562;
                int64_t _ss_net_profit3584 = (it->second)._ss_net_profit3584;
                std::string _s_state3609 = (it->second)._s_state3609;
                std::array<char, TPCDS_READ_MAX + 1> _s_state3609_n{};
                memcpy(_s_state3609_n.data(), (_s_state3609).data(), (_s_state3609).length());
                int32_t _d_date_sk3614 = tbl_Filter_TD_12933514_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_11784386_output.setInt64(r, 0, _ss_net_profit3584);
                tbl_JOIN_INNER_TD_11784386_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_state3609_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11784386_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11784386_key_rightMajor, SW_JOIN_INNER_TD_11784386_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_12933514_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk3614_k = tbl_Filter_TD_12933514_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_11784386_key_rightMajor keyA{_d_date_sk3614_k};
            int32_t _d_date_sk3614 = tbl_Filter_TD_12933514_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_11784386_payload_rightMajor payloadA{_d_date_sk3614};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_12232573_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_sold_date_sk3562_k = tbl_JOIN_INNER_TD_12232573_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11784386_key_rightMajor{_ss_sold_date_sk3562_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk3614 = (it->second)._d_date_sk3614;
                int32_t _ss_sold_date_sk3562 = tbl_JOIN_INNER_TD_12232573_output.getInt32(i, 0);
                int64_t _ss_net_profit3584 = tbl_JOIN_INNER_TD_12232573_output.getInt64(i, 1);
                std::array<char, TPCDS_READ_MAX + 1> _s_state3609_n = tbl_JOIN_INNER_TD_12232573_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _s_state3609 = std::string(_s_state3609_n.data());
                tbl_JOIN_INNER_TD_11784386_output.setInt64(r, 0, _ss_net_profit3584);
                tbl_JOIN_INNER_TD_11784386_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_state3609_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11784386_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_11784386_output #Row: " << tbl_JOIN_INNER_TD_11784386_output.getNumRow() << std::endl;
}

typedef std::string SW_Aggregate_TD_10921692_key;
struct SW_Aggregate_TD_10921692_payload {
    std::string _s_state3547;
    int64_t __w13555_sum_0;
};
void SW_Aggregate_TD_10921692(Table &tbl_JOIN_INNER_TD_11784386_output, Table &tbl_Aggregate_TD_10921692_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(s_state#3609, s_state#3609 AS s_state#3547, MakeDecimal(sum(UnscaledValue(ss_net_profit#3584)),17,2) AS _w1#3555)
    // Input: ListBuffer(ss_net_profit#3584, s_state#3609)
    // Output: ListBuffer(s_state#3547, s_state#3609, _w1#3555)
    std::unordered_map<SW_Aggregate_TD_10921692_key, SW_Aggregate_TD_10921692_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_11784386_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ss_net_profit3584 = tbl_JOIN_INNER_TD_11784386_output.getInt64(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _s_state3609 = tbl_JOIN_INNER_TD_11784386_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        SW_Aggregate_TD_10921692_key k = std::string(_s_state3609.data());
        std::array<char, TPCDS_READ_MAX + 1> _s_state3547 = _s_state3609;
        int64_t __w13555_sum_0 = _ss_net_profit3584;
        SW_Aggregate_TD_10921692_payload p{std::string(_s_state3547.data()), __w13555_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second).__w13555_sum_0 + __w13555_sum_0;
            p.__w13555_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _s_state3609{};
        memcpy(_s_state3609.data(), (it.first).data(), (it.first).length());
        tbl_Aggregate_TD_10921692_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_state3609);
        std::array<char, TPCDS_READ_MAX + 1> _s_state3547_n{};
        memcpy(_s_state3547_n.data(), (it.second)._s_state3547.data(), (it.second)._s_state3547.length());
        tbl_Aggregate_TD_10921692_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _s_state3547_n);
        int64_t __w13555 = (it.second).__w13555_sum_0;
        tbl_Aggregate_TD_10921692_output.setInt64(r, 2, __w13555);
        ++r;
    }
    tbl_Aggregate_TD_10921692_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_10921692_output #Row: " << tbl_Aggregate_TD_10921692_output.getNumRow() << std::endl;
}

void SW_Window_TD_9667985(Table &tbl_Aggregate_TD_10921692_output, Table &tbl_Window_TD_9667985_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Window
    // Operation: ListBuffer(rank(_w1#3555) windowspecdefinition(s_state#3609, _w1#3555 DESC NULLS LAST, specifiedwindowframe(RowFrame, unboundedpreceding$(), currentrow$())) AS ranking#3548)
    // Input: ListBuffer(s_state#3547, s_state#3609, _w1#3555)
    // Output: ListBuffer(s_state#3547, s_state#3609, _w1#3555, ranking#3548)
    struct SW_Window_TD_9667985Row {
        std::string _s_state3547;
        std::string _s_state3609;
        int64_t __w13555;
    }; 

    int nrow = tbl_Aggregate_TD_10921692_output.getNumRow();
    std::vector<SW_Window_TD_9667985Row> rows0;
    int r = 0;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_state3547 = tbl_Aggregate_TD_10921692_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        tbl_Window_TD_9667985_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _s_state3547);
        std::array<char, TPCDS_READ_MAX + 1> _s_state3609 = tbl_Aggregate_TD_10921692_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        tbl_Window_TD_9667985_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _s_state3609);
        int64_t __w13555 = tbl_Aggregate_TD_10921692_output.getInt64(i, 2);
        tbl_Window_TD_9667985_output.setInt64(r, 2,__w13555);
        r++;
        SW_Window_TD_9667985Row t = {std::string(_s_state3547.data()),std::string(_s_state3609.data()),__w13555};
        rows0.push_back(t);
    }
    struct {
        bool operator()(const SW_Window_TD_9667985Row& a, const SW_Window_TD_9667985Row& b) const { return 
(a._s_state3609 < b._s_state3609) || 
 ((a._s_state3609 == b._s_state3609) && (a.__w13555 > b.__w13555)); 
}
    }SW_Window_TD_9667985_order0; 

    std::sort(rows0.begin(), rows0.end(), SW_Window_TD_9667985_order0);
    std::vector<int32_t> ranks0(rows0.size(), 0);
    int32_t currentRank0 = 0;
    int32_t currentPartitionCount0 = 1;
    bool isSamePartition0 = true;
    bool isSameOrderKey0 = true;
    if (!rows0.empty()) {;
      ranks0[0] = ++currentRank0;
    };
    for (int i = 1; i< rows0.size(); i++) {
        isSamePartition0 = ( rows0[i]._s_state3609 == rows0[i-1]._s_state3609);
        isSameOrderKey0 = ( rows0[i].__w13555 == rows0[i-1].__w13555);
        currentPartitionCount0++;
        if (isSamePartition0&& !isSameOrderKey0) {
            currentRank0 = currentPartitionCount0;
        } else if (!isSamePartition0) {
            currentPartitionCount0 = 1;
            currentRank0 = currentPartitionCount0;
        }
        ranks0[i] = currentRank0;
    }
    for (int i = 0; i< nrow; i++) {
        tbl_Window_TD_9667985_output.setInt32(r, 3, ranks0[i]);
    }
    tbl_Window_TD_9667985_output.setNumRow(r);
    std::cout << "tbl_Window_TD_9667985_output #Row: " << tbl_Window_TD_9667985_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8385174(Table &tbl_Window_TD_9667985_output, Table &tbl_Filter_TD_8385174_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((ranking#3548 <= 5))
    // Input: ListBuffer(s_state#3547, s_state#3609, _w1#3555, ranking#3548)
    // Output: ListBuffer(s_state#3547)
    int r = 0;
    int nrow1 = tbl_Window_TD_9667985_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ranking3548 = tbl_Window_TD_9667985_output.getInt32(i, 3);
        if (_ranking3548 <= 5) {
            std::array<char, TPCDS_READ_MAX + 1> _s_state3547_t = tbl_Window_TD_9667985_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            tbl_Filter_TD_8385174_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _s_state3547_t);
            r++;
        }
    }
    tbl_Filter_TD_8385174_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8385174_output #Row: " << tbl_Filter_TD_8385174_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8609848(Table &tbl_SerializeFromObject_TD_9230220_input, Table &tbl_Filter_TD_8609848_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(s_store_sk#378))
    // Input: ListBuffer(s_store_sk#378, s_county#401, s_state#402)
    // Output: ListBuffer(s_store_sk#378, s_county#401, s_state#402)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9230220_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _s_store_sk378 = tbl_SerializeFromObject_TD_9230220_input.getInt32(i, 0);
        if (_s_store_sk378!= 0) {
            int32_t _s_store_sk378_t = tbl_SerializeFromObject_TD_9230220_input.getInt32(i, 0);
            tbl_Filter_TD_8609848_output.setInt32(r, 0, _s_store_sk378_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_county401_t = tbl_SerializeFromObject_TD_9230220_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_8609848_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_county401_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_state402_t = tbl_SerializeFromObject_TD_9230220_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_8609848_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_state402_t);
            r++;
        }
    }
    tbl_Filter_TD_8609848_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8609848_output #Row: " << tbl_Filter_TD_8609848_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8777042(Table &tbl_SerializeFromObject_TD_9263367_input, Table &tbl_Filter_TD_8777042_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_month_seq#123) AND ((d_month_seq#123 >= 1200) AND (d_month_seq#123 <= 1211))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_month_seq#123)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9263367_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_month_seq123 = tbl_SerializeFromObject_TD_9263367_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_9263367_input.getInt32(i, 0);
        if (((_d_month_seq123!= 0) && ((_d_month_seq123 >= 1200) && (_d_month_seq123 <= 1211))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_9263367_input.getInt32(i, 0);
            tbl_Filter_TD_8777042_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_8777042_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8777042_output #Row: " << tbl_Filter_TD_8777042_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8758138(Table &tbl_SerializeFromObject_TD_9119720_input, Table &tbl_Filter_TD_8758138_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_sold_date_sk#1206) AND isnotnull(ss_store_sk#1213)))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_store_sk#1213, ss_net_profit#1228)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_store_sk#1213, ss_net_profit#1228)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9119720_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_9119720_input.getInt32(i, 0);
        int32_t _ss_store_sk1213 = tbl_SerializeFromObject_TD_9119720_input.getInt32(i, 1);
        if ((_ss_sold_date_sk1206!= 0) && (_ss_store_sk1213!= 0)) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_9119720_input.getInt32(i, 0);
            tbl_Filter_TD_8758138_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_store_sk1213_t = tbl_SerializeFromObject_TD_9119720_input.getInt32(i, 1);
            tbl_Filter_TD_8758138_output.setInt32(r, 1, _ss_store_sk1213_t);
            int64_t _ss_net_profit1228_t = tbl_SerializeFromObject_TD_9119720_input.getInt64(i, 2);
            tbl_Filter_TD_8758138_output.setInt64(r, 2, _ss_net_profit1228_t);
            r++;
        }
    }
    tbl_Filter_TD_8758138_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8758138_output #Row: " << tbl_Filter_TD_8758138_output.getNumRow() << std::endl;
}

struct SW_JOIN_LEFTSEMI_TD_7300130_key_leftMajor {
    std::string _s_state402;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_7300130_key_leftMajor& other) const {
        return ((_s_state402 == other._s_state402));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_7300130_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_7300130_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._s_state402));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_7300130_payload_leftMajor {
    int32_t _s_store_sk378;
    std::string _s_county401;
    std::string _s_state402;
};
struct SW_JOIN_LEFTSEMI_TD_7300130_key_rightMajor {
    std::string _s_state3547;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_7300130_key_rightMajor& other) const {
        return ((_s_state3547 == other._s_state3547));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_7300130_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_7300130_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._s_state3547));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_7300130_payload_rightMajor {
    std::string _s_state3547;
};
void SW_JOIN_LEFTSEMI_TD_7300130(Table &tbl_Filter_TD_8609848_output, Table &tbl_Filter_TD_8385174_output, Table &tbl_JOIN_LEFTSEMI_TD_7300130_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTSEMI
    // Operation: ListBuffer((s_state#402 = s_state#3547))
    // Left Table: ListBuffer(s_store_sk#378, s_county#401, s_state#402)
    // Right Table: ListBuffer(s_state#3547)
    // Output Table: ListBuffer(s_store_sk#378, s_county#401, s_state#402)
    int left_nrow = tbl_Filter_TD_8609848_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8385174_output.getNumRow();
        std::unordered_map<SW_JOIN_LEFTSEMI_TD_7300130_key_rightMajor, SW_JOIN_LEFTSEMI_TD_7300130_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8385174_output.getNumRow();
        int nrow2 = tbl_Filter_TD_8609848_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _s_state3547_k_n = tbl_Filter_TD_8385174_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _s_state3547_k = std::string(_s_state3547_k_n.data());
            SW_JOIN_LEFTSEMI_TD_7300130_key_rightMajor keyA{_s_state3547_k};
            std::array<char, TPCDS_READ_MAX + 1> _s_state3547_n = tbl_Filter_TD_8385174_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _s_state3547 = std::string(_s_state3547_n.data());
            SW_JOIN_LEFTSEMI_TD_7300130_payload_rightMajor payloadA{_s_state3547};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _s_state402_k_n = tbl_Filter_TD_8609848_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _s_state402_k = std::string(_s_state402_k_n.data());
            auto it = ht1.find(SW_JOIN_LEFTSEMI_TD_7300130_key_rightMajor{_s_state402_k});
            if (it != ht1.end()) {
                int32_t _s_store_sk378 = tbl_Filter_TD_8609848_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _s_county401 = tbl_Filter_TD_8609848_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::array<char, TPCDS_READ_MAX + 1> _s_state402 = tbl_Filter_TD_8609848_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                tbl_JOIN_LEFTSEMI_TD_7300130_output.setInt32(r, 0, _s_store_sk378);
                tbl_JOIN_LEFTSEMI_TD_7300130_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_county401);
                tbl_JOIN_LEFTSEMI_TD_7300130_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_state402);
                r++;
            }
        }
        tbl_JOIN_LEFTSEMI_TD_7300130_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTSEMI_TD_7300130_output #Row: " << tbl_JOIN_LEFTSEMI_TD_7300130_output.getNumRow() << std::endl;
}


struct SW_JOIN_INNER_TD_6302484_key_leftMajor {
    int32_t _ss_store_sk1213;
    bool operator==(const SW_JOIN_INNER_TD_6302484_key_leftMajor& other) const {
        return ((_ss_store_sk1213 == other._ss_store_sk1213));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6302484_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6302484_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_store_sk1213));
    }
};
}
struct SW_JOIN_INNER_TD_6302484_payload_leftMajor {
    int32_t _ss_store_sk1213;
    int64_t _ss_net_profit1228;
};
struct SW_JOIN_INNER_TD_6302484_key_rightMajor {
    int32_t _s_store_sk378;
    bool operator==(const SW_JOIN_INNER_TD_6302484_key_rightMajor& other) const {
        return ((_s_store_sk378 == other._s_store_sk378));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6302484_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6302484_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_store_sk378));
    }
};
}
struct SW_JOIN_INNER_TD_6302484_payload_rightMajor {
    int32_t _s_store_sk378;
    std::string _s_county401;
    std::string _s_state402;
};
void SW_JOIN_INNER_TD_6302484(Table &tbl_JOIN_INNER_TD_7883227_output, Table &tbl_JOIN_LEFTSEMI_TD_7300130_output, Table &tbl_JOIN_INNER_TD_6302484_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((s_store_sk#378 = ss_store_sk#1213))
    // Left Table: ListBuffer(ss_store_sk#1213, ss_net_profit#1228)
    // Right Table: ListBuffer(s_store_sk#378, s_county#401, s_state#402)
    // Output Table: ListBuffer(ss_net_profit#1228, s_state#402, s_county#401)
    int left_nrow = tbl_JOIN_INNER_TD_7883227_output.getNumRow();
    int right_nrow = tbl_JOIN_LEFTSEMI_TD_7300130_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6302484_key_leftMajor, SW_JOIN_INNER_TD_6302484_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7883227_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_store_sk1213_k = tbl_JOIN_INNER_TD_7883227_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6302484_key_leftMajor keyA{_ss_store_sk1213_k};
            int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_7883227_output.getInt32(i, 0);
            int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_7883227_output.getInt64(i, 1);
            SW_JOIN_INNER_TD_6302484_payload_leftMajor payloadA{_ss_store_sk1213, _ss_net_profit1228};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_LEFTSEMI_TD_7300130_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_store_sk378_k = tbl_JOIN_LEFTSEMI_TD_7300130_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6302484_key_leftMajor{_s_store_sk378_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_store_sk1213 = (it->second)._ss_store_sk1213;
                int64_t _ss_net_profit1228 = (it->second)._ss_net_profit1228;
                int32_t _s_store_sk378 = tbl_JOIN_LEFTSEMI_TD_7300130_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _s_county401_n = tbl_JOIN_LEFTSEMI_TD_7300130_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _s_county401 = std::string(_s_county401_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_state402_n = tbl_JOIN_LEFTSEMI_TD_7300130_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _s_state402 = std::string(_s_state402_n.data());
                tbl_JOIN_INNER_TD_6302484_output.setInt64(r, 0, _ss_net_profit1228);
                tbl_JOIN_INNER_TD_6302484_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_county401_n);
                tbl_JOIN_INNER_TD_6302484_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_state402_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6302484_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6302484_key_rightMajor, SW_JOIN_INNER_TD_6302484_payload_rightMajor> ht1;
        int nrow1 = tbl_JOIN_LEFTSEMI_TD_7300130_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_store_sk378_k = tbl_JOIN_LEFTSEMI_TD_7300130_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6302484_key_rightMajor keyA{_s_store_sk378_k};
            int32_t _s_store_sk378 = tbl_JOIN_LEFTSEMI_TD_7300130_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _s_county401_n = tbl_JOIN_LEFTSEMI_TD_7300130_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _s_county401 = std::string(_s_county401_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_state402_n = tbl_JOIN_LEFTSEMI_TD_7300130_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _s_state402 = std::string(_s_state402_n.data());
            SW_JOIN_INNER_TD_6302484_payload_rightMajor payloadA{_s_store_sk378, _s_county401, _s_state402};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7883227_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_store_sk1213_k = tbl_JOIN_INNER_TD_7883227_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6302484_key_rightMajor{_ss_store_sk1213_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _s_store_sk378 = (it->second)._s_store_sk378;
                std::string _s_county401 = (it->second)._s_county401;
                std::array<char, TPCDS_READ_MAX + 1> _s_county401_n{};
                memcpy(_s_county401_n.data(), (_s_county401).data(), (_s_county401).length());
                std::string _s_state402 = (it->second)._s_state402;
                std::array<char, TPCDS_READ_MAX + 1> _s_state402_n{};
                memcpy(_s_state402_n.data(), (_s_state402).data(), (_s_state402).length());
                int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_7883227_output.getInt32(i, 0);
                int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_7883227_output.getInt64(i, 1);
                tbl_JOIN_INNER_TD_6302484_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_county401_n);
                tbl_JOIN_INNER_TD_6302484_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_state402_n);
                tbl_JOIN_INNER_TD_6302484_output.setInt64(r, 0, _ss_net_profit1228);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6302484_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6302484_output #Row: " << tbl_JOIN_INNER_TD_6302484_output.getNumRow() << std::endl;
}

void SW_Expand_TD_547287(Table &tbl_JOIN_INNER_TD_6302484_output, Table &tbl_Expand_TD_547287_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Expand
    // Operation: ListBuffer(Expand)
    // Input: ListBuffer(ss_net_profit#1228, s_state#402, s_county#401)
    // Output: ListBuffer(ss_net_profit#1228, s_state#3647, s_county#3648, spark_grouping_id#3646L)
    std::cout << "tbl_Expand_TD_547287_output #Row: " << tbl_Expand_TD_547287_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_4856132_key {
    std::string _s_state3647;
    std::string _s_county3648;
    int64_t _spark_grouping_id3646L;
    bool operator==(const SW_Aggregate_TD_4856132_key& other) const { return (_s_state3647 == other._s_state3647) && (_s_county3648 == other._s_county3648) && (_spark_grouping_id3646L == other._spark_grouping_id3646L); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_4856132_key> {
    std::size_t operator() (const SW_Aggregate_TD_4856132_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._s_state3647)) + (hash<string>()(k._s_county3648)) + (hash<int64_t>()(k._spark_grouping_id3646L));
    }
};
}
struct SW_Aggregate_TD_4856132_payload {
    int64_t _total_sum3544_sum_0;
    int32_t _lochierarchy3545;
    int32_t __w13661;
    std::string __w23662;
    int64_t __w33663_sum_1;
};
void SW_Aggregate_TD_4856132(Table &tbl_Expand_TD_547287_output, Table &tbl_Aggregate_TD_4856132_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(s_state#3647, s_county#3648, spark_grouping_id#3646L, MakeDecimal(sum(UnscaledValue(ss_net_profit#1228)),17,2) AS total_sum#3544, (cast((shiftright(spark_grouping_id#3646L, 1) & 1) as tinyint) + cast((shiftright(spark_grouping_id#3646L, 0) & 1) as tinyint)) AS lochierarchy#3545, (cast((shiftright(spark_grouping_id#3646L, 1) & 1) as tinyint) + cast((shiftright(spark_grouping_id#3646L, 0) & 1) as tinyint)) AS _w1#3661, CASE WHEN (cast((shiftright(spark_grouping_id#3646L, 0) & 1) as tinyint) = 0) THEN s_state#3647 END AS _w2#3662, MakeDecimal(sum(UnscaledValue(ss_net_profit#1228)),17,2) AS _w3#3663)
    // Input: ListBuffer(ss_net_profit#1228, s_state#3647, s_county#3648, spark_grouping_id#3646L)
    // Output: ListBuffer(total_sum#3544, s_state#3647, s_county#3648, lochierarchy#3545, _w1#3661, _w2#3662, _w3#3663)
    std::unordered_map<SW_Aggregate_TD_4856132_key, SW_Aggregate_TD_4856132_payload> ht1;
    int nrow1 = tbl_Expand_TD_547287_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ss_net_profit1228 = tbl_Expand_TD_547287_output.getInt64(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _s_state3647 = tbl_Expand_TD_547287_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _s_county3648 = tbl_Expand_TD_547287_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        int64_t _spark_grouping_id3646L = tbl_Expand_TD_547287_output.getInt64(i, 3);
        SW_Aggregate_TD_4856132_key k{std::string(_s_state3647.data()), std::string(_s_county3648.data()), _spark_grouping_id3646L};
        int64_t _total_sum3544_sum_0 = _ss_net_profit1228;
        int32_t _lochierarchy3545 = (_spark_grouping_id3646L + _spark_grouping_id3646L);
        int32_t __w13661 = (_spark_grouping_id3646L + _spark_grouping_id3646L);
        std::array<char, TPCDS_READ_MAX + 1> __w23662 = (_spark_grouping_id3646L == 0) ? _s_state3647 : 1;
        int64_t __w33663_sum_1 = _ss_net_profit1228;
        SW_Aggregate_TD_4856132_payload p{_total_sum3544_sum_0, _lochierarchy3545, __w13661, std::string(__w23662.data()), __w33663_sum_1};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._total_sum3544_sum_0 + _total_sum3544_sum_0;
            p._total_sum3544_sum_0 = sum_0;
            int64_t sum_1 = (it->second).__w33663_sum_1 + __w33663_sum_1;
            p.__w33663_sum_1 = sum_1;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _s_state3647{};
        memcpy(_s_state3647.data(), ((it.first)._s_state3647).data(), ((it.first)._s_state3647).length());
        tbl_Aggregate_TD_4856132_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_state3647);
        std::array<char, TPCDS_READ_MAX + 1> _s_county3648{};
        memcpy(_s_county3648.data(), ((it.first)._s_county3648).data(), ((it.first)._s_county3648).length());
        tbl_Aggregate_TD_4856132_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_county3648);
        // _spark_grouping_id3646L not required in the output table
        int64_t _total_sum3544 = (it.second)._total_sum3544_sum_0;
        tbl_Aggregate_TD_4856132_output.setInt64(r, 0, _total_sum3544);
        tbl_Aggregate_TD_4856132_output.setInt32(r, 3, (it.second)._lochierarchy3545);
        tbl_Aggregate_TD_4856132_output.setInt32(r, 4, (it.second).__w13661);
        tbl_Aggregate_TD_4856132_output.setInt64(r, 5, (it.second).__w23662);
        int64_t __w33663 = (it.second).__w33663_sum_1;
        tbl_Aggregate_TD_4856132_output.setInt64(r, 6, __w33663);
        ++r;
    }
    tbl_Aggregate_TD_4856132_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_4856132_output #Row: " << tbl_Aggregate_TD_4856132_output.getNumRow() << std::endl;
}

void SW_Window_TD_3896206(Table &tbl_Aggregate_TD_4856132_output, Table &tbl_Window_TD_3896206_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Window
    // Operation: ListBuffer(rank(_w3#3663) windowspecdefinition(_w1#3661, _w2#3662, _w3#3663 DESC NULLS LAST, specifiedwindowframe(RowFrame, unboundedpreceding$(), currentrow$())) AS rank_within_parent#3546)
    // Input: ListBuffer(total_sum#3544, s_state#3647, s_county#3648, lochierarchy#3545, _w1#3661, _w2#3662, _w3#3663)
    // Output: ListBuffer(total_sum#3544, s_state#3647, s_county#3648, lochierarchy#3545, _w1#3661, _w2#3662, _w3#3663, rank_within_parent#3546)
    struct SW_Window_TD_3896206Row {
        int64_t _total_sum3544;
        std::string _s_state3647;
        std::string _s_county3648;
        int32_t _lochierarchy3545;
        int32_t __w13661;
        int64_t __w23662;
        int64_t __w33663;
    }; 

    int nrow = tbl_Aggregate_TD_4856132_output.getNumRow();
    std::vector<SW_Window_TD_3896206Row> rows0;
    int r = 0;
    for (int i = 0; i < nrow; i++) {
        int64_t _total_sum3544 = tbl_Aggregate_TD_4856132_output.getInt64(i, 0);
        tbl_Window_TD_3896206_output.setInt64(r, 0,_total_sum3544);
        std::array<char, TPCDS_READ_MAX + 1> _s_state3647 = tbl_Aggregate_TD_4856132_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        tbl_Window_TD_3896206_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _s_state3647);
        std::array<char, TPCDS_READ_MAX + 1> _s_county3648 = tbl_Aggregate_TD_4856132_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        tbl_Window_TD_3896206_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _s_county3648);
        int32_t _lochierarchy3545 = tbl_Aggregate_TD_4856132_output.getInt32(i, 3);
        tbl_Window_TD_3896206_output.setInt32(r, 3,_lochierarchy3545);
        int32_t __w13661 = tbl_Aggregate_TD_4856132_output.getInt32(i, 4);
        tbl_Window_TD_3896206_output.setInt32(r, 4,__w13661);
        int64_t __w23662 = tbl_Aggregate_TD_4856132_output.getInt64(i, 5);
        tbl_Window_TD_3896206_output.setInt64(r, 5,__w23662);
        int64_t __w33663 = tbl_Aggregate_TD_4856132_output.getInt64(i, 6);
        tbl_Window_TD_3896206_output.setInt64(r, 6,__w33663);
        r++;
        SW_Window_TD_3896206Row t = {_total_sum3544,std::string(_s_state3647.data()),std::string(_s_county3648.data()),_lochierarchy3545,__w13661,__w23662,__w33663};
        rows0.push_back(t);
    }
    struct {
        bool operator()(const SW_Window_TD_3896206Row& a, const SW_Window_TD_3896206Row& b) const { return 
(a.__w13661 < b.__w13661) || 
 ((a.__w13661 == b.__w13661) && (a.__w23662 < b.__w23662)) || 
 ((a.__w13661 == b.__w13661) && (a.__w23662 == b.__w23662) && (a.__w33663 > b.__w33663)); 
}
    }SW_Window_TD_3896206_order0; 

    std::sort(rows0.begin(), rows0.end(), SW_Window_TD_3896206_order0);
    std::vector<int32_t> ranks0(rows0.size(), 0);
    int32_t currentRank0 = 0;
    int32_t currentPartitionCount0 = 1;
    bool isSamePartition0 = true;
    bool isSameOrderKey0 = true;
    if (!rows0.empty()) {;
      ranks0[0] = ++currentRank0;
    };
    for (int i = 1; i< rows0.size(); i++) {
        isSamePartition0 = ( rows0[i].__w13661 == rows0[i-1].__w13661 && rows0[i].__w23662 == rows0[i-1].__w23662);
        isSameOrderKey0 = ( rows0[i].__w33663 == rows0[i-1].__w33663);
        currentPartitionCount0++;
        if (isSamePartition0&& !isSameOrderKey0) {
            currentRank0 = currentPartitionCount0;
        } else if (!isSamePartition0) {
            currentPartitionCount0 = 1;
            currentRank0 = currentPartitionCount0;
        }
        ranks0[i] = currentRank0;
    }
    for (int i = 0; i< nrow; i++) {
        tbl_Window_TD_3896206_output.setInt32(r, 7, ranks0[i]);
    }
    tbl_Window_TD_3896206_output.setNumRow(r);
    std::cout << "tbl_Window_TD_3896206_output #Row: " << tbl_Window_TD_3896206_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2668436(Table &tbl_Window_TD_3896206_output, Table &tbl_Sort_TD_2668436_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(lochierarchy#3545 DESC NULLS LAST, CASE WHEN (lochierarchy#3545 = 0) THEN s_state#3647 END ASC NULLS FIRST, rank_within_parent#3546 ASC NULLS FIRST)
    // Input: ListBuffer(total_sum#3544, s_state#3647, s_county#3648, lochierarchy#3545, _w1#3661, _w2#3662, _w3#3663, rank_within_parent#3546)
    // Output: ListBuffer(total_sum#3544, s_state#3647, s_county#3648, lochierarchy#3545, rank_within_parent#3546)
    struct SW_Sort_TD_2668436Row {
        int64_t _total_sum3544;
        std::string _s_state3647;
        std::string _s_county3648;
        int32_t _lochierarchy3545;
        int32_t __w13661;
        int64_t __w23662;
        int64_t __w33663;
        int32_t _rank_within_parent3546;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2668436Row& a, const SW_Sort_TD_2668436Row& b) const { return 
 (a._lochierarchy3545 > b._lochierarchy3545) || 
 ((a._lochierarchy3545 == b._lochierarchy3545) && (a._lochierarchy3545 < b._lochierarchy3545)) || 
 ((a._lochierarchy3545 == b._lochierarchy3545) && (a._lochierarchy3545 == b._lochierarchy3545) && (a._rank_within_parent3546 < b._rank_within_parent3546)); 
}
    }SW_Sort_TD_2668436_order; 

    int nrow1 = tbl_Window_TD_3896206_output.getNumRow();
    std::vector<SW_Sort_TD_2668436Row> rows;
    for (int i = 0; i < nrow1; i++) {
        int64_t _total_sum3544 = tbl_Window_TD_3896206_output.getInt64(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _s_state3647 = tbl_Window_TD_3896206_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _s_county3648 = tbl_Window_TD_3896206_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        int32_t _lochierarchy3545 = tbl_Window_TD_3896206_output.getInt32(i, 3);
        int32_t __w13661 = tbl_Window_TD_3896206_output.getInt32(i, 4);
        int64_t __w23662 = tbl_Window_TD_3896206_output.getInt64(i, 5);
        int64_t __w33663 = tbl_Window_TD_3896206_output.getInt64(i, 6);
        int32_t _rank_within_parent3546 = tbl_Window_TD_3896206_output.getInt32(i, 7);
        SW_Sort_TD_2668436Row t = {_total_sum3544,std::string(_s_state3647.data()),std::string(_s_county3648.data()),_lochierarchy3545,__w13661,__w23662,__w33663,_rank_within_parent3546};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2668436_order);
    int r = 0;
    for (auto& it : rows) {
        tbl_Sort_TD_2668436_output.setInt64(r, 0, it._total_sum3544);
        std::array<char, TPCDS_READ_MAX + 1> _s_state3647{};
        memcpy(_s_state3647.data(), (it._s_state3647).data(), (it._s_state3647).length());
        tbl_Sort_TD_2668436_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _s_state3647);
        std::array<char, TPCDS_READ_MAX + 1> _s_county3648{};
        memcpy(_s_county3648.data(), (it._s_county3648).data(), (it._s_county3648).length());
        tbl_Sort_TD_2668436_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _s_county3648);
        tbl_Sort_TD_2668436_output.setInt32(r, 3, it._lochierarchy3545);
        tbl_Sort_TD_2668436_output.setInt32(r, 4, it._rank_within_parent3546);
        ++r;
    }
    tbl_Sort_TD_2668436_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2668436_output #Row: " << tbl_Sort_TD_2668436_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1655134(Table &tbl_Sort_TD_2668436_output, Table &tbl_LocalLimit_TD_1655134_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(total_sum#3544, s_state#3647, s_county#3648, lochierarchy#3545, rank_within_parent#3546)
    // Output: ListBuffer(total_sum#3544, s_state#3647, s_county#3648, lochierarchy#3545, rank_within_parent#3546)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        tbl_LocalLimit_TD_1655134_output.setInt64(r, 0, tbl_Sort_TD_2668436_output.getInt64(i, 0));
        std::array<char, TPCDS_READ_MAX + 1> _s_state3647_n = tbl_Sort_TD_2668436_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_1655134_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_state3647_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_county3648_n = tbl_Sort_TD_2668436_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_LocalLimit_TD_1655134_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_county3648_n);
        tbl_LocalLimit_TD_1655134_output.setInt32(r, 3, tbl_Sort_TD_2668436_output.getInt32(i, 3));
        tbl_LocalLimit_TD_1655134_output.setInt32(r, 4, tbl_Sort_TD_2668436_output.getInt32(i, 4));
        r++;
    }
    tbl_LocalLimit_TD_1655134_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1655134_output #Row: " << tbl_LocalLimit_TD_1655134_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0640622(Table &tbl_LocalLimit_TD_1655134_output, Table &tbl_GlobalLimit_TD_0640622_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(total_sum#3544, s_state#3647, s_county#3648, lochierarchy#3545, rank_within_parent#3546)
    // Output: ListBuffer(total_sum#3544, s_state#3647, s_county#3648, lochierarchy#3545, rank_within_parent#3546)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        tbl_GlobalLimit_TD_0640622_output.setInt64(r, 0, tbl_LocalLimit_TD_1655134_output.getInt64(i, 0));
        std::array<char, TPCDS_READ_MAX + 1> _s_state3647_n = tbl_LocalLimit_TD_1655134_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_0640622_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_state3647_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_county3648_n = tbl_LocalLimit_TD_1655134_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_GlobalLimit_TD_0640622_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_county3648_n);
        tbl_GlobalLimit_TD_0640622_output.setInt32(r, 3, tbl_LocalLimit_TD_1655134_output.getInt32(i, 3));
        tbl_GlobalLimit_TD_0640622_output.setInt32(r, 4, tbl_LocalLimit_TD_1655134_output.getInt32(i, 4));
        r++;
    }
    tbl_GlobalLimit_TD_0640622_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0640622_output #Row: " << tbl_GlobalLimit_TD_0640622_output.getNumRow() << std::endl;
}

