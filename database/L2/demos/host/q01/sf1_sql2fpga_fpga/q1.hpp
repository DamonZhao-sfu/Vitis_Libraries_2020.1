#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_8984869(Table &tbl_SerializeFromObject_TD_9420260_input, Table &tbl_Filter_TD_8984869_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#126) AND (d_year#126 = 2000)) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9420260_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_9420260_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_9420260_input.getInt32(i, 0);
        if (((_d_year126!= 0) && (_d_year126 == 2000)) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_9420260_input.getInt32(i, 0);
            tbl_Filter_TD_8984869_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_8984869_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8984869_output #Row: " << tbl_Filter_TD_8984869_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8741776(Table &tbl_SerializeFromObject_TD_9308485_input, Table &tbl_Filter_TD_8741776_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(sr_returned_date_sk#669) AND isnotnull(sr_store_sk#676)))
    // Input: ListBuffer(sr_returned_date_sk#669, sr_customer_sk#672, sr_store_sk#676, sr_return_amt#680)
    // Output: ListBuffer(sr_returned_date_sk#669, sr_customer_sk#672, sr_store_sk#676, sr_return_amt#680)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9308485_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _sr_returned_date_sk669 = tbl_SerializeFromObject_TD_9308485_input.getInt32(i, 0);
        int32_t _sr_store_sk676 = tbl_SerializeFromObject_TD_9308485_input.getInt32(i, 2);
        if ((_sr_returned_date_sk669!= 0) && (_sr_store_sk676!= 0)) {
            int32_t _sr_returned_date_sk669_t = tbl_SerializeFromObject_TD_9308485_input.getInt32(i, 0);
            tbl_Filter_TD_8741776_output.setInt32(r, 0, _sr_returned_date_sk669_t);
            int32_t _sr_customer_sk672_t = tbl_SerializeFromObject_TD_9308485_input.getInt32(i, 1);
            tbl_Filter_TD_8741776_output.setInt32(r, 1, _sr_customer_sk672_t);
            int32_t _sr_store_sk676_t = tbl_SerializeFromObject_TD_9308485_input.getInt32(i, 2);
            tbl_Filter_TD_8741776_output.setInt32(r, 2, _sr_store_sk676_t);
            int64_t _sr_return_amt680_t = tbl_SerializeFromObject_TD_9308485_input.getInt64(i, 3);
            tbl_Filter_TD_8741776_output.setInt64(r, 3, _sr_return_amt680_t);
            r++;
        }
    }
    tbl_Filter_TD_8741776_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8741776_output #Row: " << tbl_Filter_TD_8741776_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_7806453_key_leftMajor {
    int32_t _sr_returned_date_sk669;
    bool operator==(const SW_JOIN_INNER_TD_7806453_key_leftMajor& other) const {
        return ((_sr_returned_date_sk669 == other._sr_returned_date_sk669));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7806453_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7806453_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._sr_returned_date_sk669));
    }
};
}
struct SW_JOIN_INNER_TD_7806453_payload_leftMajor {
    int32_t _sr_returned_date_sk669;
    int32_t _sr_customer_sk672;
    int32_t _sr_store_sk676;
    int64_t _sr_return_amt680;
};
struct SW_JOIN_INNER_TD_7806453_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_7806453_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7806453_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7806453_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_7806453_payload_rightMajor {
    int32_t _d_date_sk120;
};
void SW_JOIN_INNER_TD_7806453(Table &tbl_Filter_TD_8741776_output, Table &tbl_Filter_TD_8984869_output, Table &tbl_JOIN_INNER_TD_7806453_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((sr_returned_date_sk#669 = d_date_sk#120))
    // Left Table: ListBuffer(sr_returned_date_sk#669, sr_customer_sk#672, sr_store_sk#676, sr_return_amt#680)
    // Right Table: ListBuffer(d_date_sk#120)
    // Output Table: ListBuffer(sr_customer_sk#672, sr_store_sk#676, sr_return_amt#680)
    int left_nrow = tbl_Filter_TD_8741776_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8984869_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7806453_key_leftMajor, SW_JOIN_INNER_TD_7806453_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_8741776_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _sr_returned_date_sk669_k = tbl_Filter_TD_8741776_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7806453_key_leftMajor keyA{_sr_returned_date_sk669_k};
            int32_t _sr_returned_date_sk669 = tbl_Filter_TD_8741776_output.getInt32(i, 0);
            int32_t _sr_customer_sk672 = tbl_Filter_TD_8741776_output.getInt32(i, 1);
            int32_t _sr_store_sk676 = tbl_Filter_TD_8741776_output.getInt32(i, 2);
            int64_t _sr_return_amt680 = tbl_Filter_TD_8741776_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_7806453_payload_leftMajor payloadA{_sr_returned_date_sk669, _sr_customer_sk672, _sr_store_sk676, _sr_return_amt680};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8984869_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_8984869_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7806453_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _sr_returned_date_sk669 = (it->second)._sr_returned_date_sk669;
                int32_t _sr_customer_sk672 = (it->second)._sr_customer_sk672;
                int32_t _sr_store_sk676 = (it->second)._sr_store_sk676;
                int64_t _sr_return_amt680 = (it->second)._sr_return_amt680;
                int32_t _d_date_sk120 = tbl_Filter_TD_8984869_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_7806453_output.setInt32(r, 0, _sr_customer_sk672);
                tbl_JOIN_INNER_TD_7806453_output.setInt32(r, 1, _sr_store_sk676);
                tbl_JOIN_INNER_TD_7806453_output.setInt64(r, 2, _sr_return_amt680);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7806453_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7806453_key_rightMajor, SW_JOIN_INNER_TD_7806453_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8984869_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_8984869_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7806453_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_8984869_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7806453_payload_rightMajor payloadA{_d_date_sk120};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8741776_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _sr_returned_date_sk669_k = tbl_Filter_TD_8741776_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7806453_key_rightMajor{_sr_returned_date_sk669_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _sr_returned_date_sk669 = tbl_Filter_TD_8741776_output.getInt32(i, 0);
                int32_t _sr_customer_sk672 = tbl_Filter_TD_8741776_output.getInt32(i, 1);
                int32_t _sr_store_sk676 = tbl_Filter_TD_8741776_output.getInt32(i, 2);
                int64_t _sr_return_amt680 = tbl_Filter_TD_8741776_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_7806453_output.setInt32(r, 0, _sr_customer_sk672);
                tbl_JOIN_INNER_TD_7806453_output.setInt32(r, 1, _sr_store_sk676);
                tbl_JOIN_INNER_TD_7806453_output.setInt64(r, 2, _sr_return_amt680);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7806453_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7806453_output #Row: " << tbl_JOIN_INNER_TD_7806453_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7839758(Table &tbl_SerializeFromObject_TD_8495458_input, Table &tbl_Filter_TD_7839758_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#126) AND (d_year#126 = 2000)) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8495458_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_8495458_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_8495458_input.getInt32(i, 0);
        if (((_d_year126!= 0) && (_d_year126 == 2000)) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_8495458_input.getInt32(i, 0);
            tbl_Filter_TD_7839758_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_7839758_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7839758_output #Row: " << tbl_Filter_TD_7839758_output.getNumRow() << std::endl;
}

void SW_Filter_TD_731356(Table &tbl_SerializeFromObject_TD_8876312_input, Table &tbl_Filter_TD_731356_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(sr_returned_date_sk#669) AND (isnotnull(sr_store_sk#676) AND isnotnull(sr_customer_sk#672))))
    // Input: ListBuffer(sr_returned_date_sk#669, sr_customer_sk#672, sr_store_sk#676, sr_return_amt#680)
    // Output: ListBuffer(sr_returned_date_sk#669, sr_customer_sk#672, sr_store_sk#676, sr_return_amt#680)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8876312_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _sr_returned_date_sk669 = tbl_SerializeFromObject_TD_8876312_input.getInt32(i, 0);
        int32_t _sr_store_sk676 = tbl_SerializeFromObject_TD_8876312_input.getInt32(i, 2);
        int32_t _sr_customer_sk672 = tbl_SerializeFromObject_TD_8876312_input.getInt32(i, 1);
        if ((_sr_returned_date_sk669!= 0) && ((_sr_store_sk676!= 0) && (_sr_customer_sk672!= 0))) {
            int32_t _sr_returned_date_sk669_t = tbl_SerializeFromObject_TD_8876312_input.getInt32(i, 0);
            tbl_Filter_TD_731356_output.setInt32(r, 0, _sr_returned_date_sk669_t);
            int32_t _sr_customer_sk672_t = tbl_SerializeFromObject_TD_8876312_input.getInt32(i, 1);
            tbl_Filter_TD_731356_output.setInt32(r, 1, _sr_customer_sk672_t);
            int32_t _sr_store_sk676_t = tbl_SerializeFromObject_TD_8876312_input.getInt32(i, 2);
            tbl_Filter_TD_731356_output.setInt32(r, 2, _sr_store_sk676_t);
            int64_t _sr_return_amt680_t = tbl_SerializeFromObject_TD_8876312_input.getInt64(i, 3);
            tbl_Filter_TD_731356_output.setInt64(r, 3, _sr_return_amt680_t);
            r++;
        }
    }
    tbl_Filter_TD_731356_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_731356_output #Row: " << tbl_Filter_TD_731356_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_6815148_key {
    int32_t _sr_customer_sk672;
    int32_t _sr_store_sk676;
    bool operator==(const SW_Aggregate_TD_6815148_key& other) const { return (_sr_customer_sk672 == other._sr_customer_sk672) && (_sr_store_sk676 == other._sr_store_sk676); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_6815148_key> {
    std::size_t operator() (const SW_Aggregate_TD_6815148_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._sr_customer_sk672)) + (hash<int32_t>()(k._sr_store_sk676));
    }
};
}
struct SW_Aggregate_TD_6815148_payload {
    int32_t _ctr_store_sk3546;
    int64_t _ctr_total_return3547_sum_0;
};
void SW_Aggregate_TD_6815148(Table &tbl_JOIN_INNER_TD_7806453_output, Table &tbl_Aggregate_TD_6815148_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(sr_customer_sk#672, sr_store_sk#676, sr_store_sk#676 AS ctr_store_sk#3546, MakeDecimal(sum(UnscaledValue(sr_return_amt#680)),17,2) AS ctr_total_return#3547)
    // Input: ListBuffer(sr_customer_sk#672, sr_store_sk#676, sr_return_amt#680)
    // Output: ListBuffer(ctr_store_sk#3546, ctr_total_return#3547)
    std::unordered_map<SW_Aggregate_TD_6815148_key, SW_Aggregate_TD_6815148_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_7806453_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _sr_customer_sk672 = tbl_JOIN_INNER_TD_7806453_output.getInt32(i, 0);
        int32_t _sr_store_sk676 = tbl_JOIN_INNER_TD_7806453_output.getInt32(i, 1);
        int64_t _sr_return_amt680 = tbl_JOIN_INNER_TD_7806453_output.getInt64(i, 2);
        SW_Aggregate_TD_6815148_key k{_sr_customer_sk672, _sr_store_sk676};
        int32_t _ctr_store_sk3546 = _sr_store_sk676;
        int64_t _ctr_total_return3547_sum_0 = _sr_return_amt680;
        SW_Aggregate_TD_6815148_payload p{_ctr_store_sk3546, _ctr_total_return3547_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._ctr_total_return3547_sum_0 + _ctr_total_return3547_sum_0;
            p._ctr_total_return3547_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _sr_customer_sk672 not required in the output table
        // _sr_store_sk676 not required in the output table
        tbl_Aggregate_TD_6815148_output.setInt32(r, 0, (it.second)._ctr_store_sk3546);
        int64_t _ctr_total_return3547 = (it.second)._ctr_total_return3547_sum_0;
        tbl_Aggregate_TD_6815148_output.setInt64(r, 1, _ctr_total_return3547);
        ++r;
    }
    tbl_Aggregate_TD_6815148_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_6815148_output #Row: " << tbl_Aggregate_TD_6815148_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6717294_key_leftMajor {
    int32_t _sr_returned_date_sk669;
    bool operator==(const SW_JOIN_INNER_TD_6717294_key_leftMajor& other) const {
        return ((_sr_returned_date_sk669 == other._sr_returned_date_sk669));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6717294_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6717294_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._sr_returned_date_sk669));
    }
};
}
struct SW_JOIN_INNER_TD_6717294_payload_leftMajor {
    int32_t _sr_returned_date_sk669;
    int32_t _sr_customer_sk672;
    int32_t _sr_store_sk676;
    int64_t _sr_return_amt680;
};
struct SW_JOIN_INNER_TD_6717294_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_6717294_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6717294_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6717294_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_6717294_payload_rightMajor {
    int32_t _d_date_sk120;
};
void SW_JOIN_INNER_TD_6717294(Table &tbl_Filter_TD_731356_output, Table &tbl_Filter_TD_7839758_output, Table &tbl_JOIN_INNER_TD_6717294_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((sr_returned_date_sk#669 = d_date_sk#120))
    // Left Table: ListBuffer(sr_returned_date_sk#669, sr_customer_sk#672, sr_store_sk#676, sr_return_amt#680)
    // Right Table: ListBuffer(d_date_sk#120)
    // Output Table: ListBuffer(sr_customer_sk#672, sr_store_sk#676, sr_return_amt#680)
    int left_nrow = tbl_Filter_TD_731356_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7839758_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6717294_key_leftMajor, SW_JOIN_INNER_TD_6717294_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_731356_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _sr_returned_date_sk669_k = tbl_Filter_TD_731356_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6717294_key_leftMajor keyA{_sr_returned_date_sk669_k};
            int32_t _sr_returned_date_sk669 = tbl_Filter_TD_731356_output.getInt32(i, 0);
            int32_t _sr_customer_sk672 = tbl_Filter_TD_731356_output.getInt32(i, 1);
            int32_t _sr_store_sk676 = tbl_Filter_TD_731356_output.getInt32(i, 2);
            int64_t _sr_return_amt680 = tbl_Filter_TD_731356_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_6717294_payload_leftMajor payloadA{_sr_returned_date_sk669, _sr_customer_sk672, _sr_store_sk676, _sr_return_amt680};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7839758_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_7839758_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6717294_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _sr_returned_date_sk669 = (it->second)._sr_returned_date_sk669;
                int32_t _sr_customer_sk672 = (it->second)._sr_customer_sk672;
                int32_t _sr_store_sk676 = (it->second)._sr_store_sk676;
                int64_t _sr_return_amt680 = (it->second)._sr_return_amt680;
                int32_t _d_date_sk120 = tbl_Filter_TD_7839758_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_6717294_output.setInt32(r, 0, _sr_customer_sk672);
                tbl_JOIN_INNER_TD_6717294_output.setInt32(r, 1, _sr_store_sk676);
                tbl_JOIN_INNER_TD_6717294_output.setInt64(r, 2, _sr_return_amt680);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6717294_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6717294_key_rightMajor, SW_JOIN_INNER_TD_6717294_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7839758_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_7839758_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6717294_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_7839758_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6717294_payload_rightMajor payloadA{_d_date_sk120};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_731356_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _sr_returned_date_sk669_k = tbl_Filter_TD_731356_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6717294_key_rightMajor{_sr_returned_date_sk669_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _sr_returned_date_sk669 = tbl_Filter_TD_731356_output.getInt32(i, 0);
                int32_t _sr_customer_sk672 = tbl_Filter_TD_731356_output.getInt32(i, 1);
                int32_t _sr_store_sk676 = tbl_Filter_TD_731356_output.getInt32(i, 2);
                int64_t _sr_return_amt680 = tbl_Filter_TD_731356_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_6717294_output.setInt32(r, 0, _sr_customer_sk672);
                tbl_JOIN_INNER_TD_6717294_output.setInt32(r, 1, _sr_store_sk676);
                tbl_JOIN_INNER_TD_6717294_output.setInt64(r, 2, _sr_return_amt680);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6717294_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6717294_output #Row: " << tbl_JOIN_INNER_TD_6717294_output.getNumRow() << std::endl;
}

typedef int32_t SW_Aggregate_TD_5668083_key;
struct SW_Aggregate_TD_5668083_payload {
    int64_t _123550_avg_0;
    int32_t _ctr_store_sk35463626;
};
void SW_Aggregate_TD_5668083(Table &tbl_Aggregate_TD_6815148_output, Table &tbl_Aggregate_TD_5668083_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(ctr_store_sk#3546, CheckOverflow((promote_precision(avg(ctr_total_return#3547)) * 1.200000), DecimalType(24,7), true) AS (avg(ctr_total_return) * 1.2)#3550, ctr_store_sk#3546 AS ctr_store_sk#3546#3626)
    // Input: ListBuffer(ctr_store_sk#3546, ctr_total_return#3547)
    // Output: ListBuffer((avg(ctr_total_return) * 1.2)#3550, ctr_store_sk#3546#3626)
    std::unordered_map<SW_Aggregate_TD_5668083_key, SW_Aggregate_TD_5668083_payload> ht1;
    int nrow1 = tbl_Aggregate_TD_6815148_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ctr_store_sk3546 = tbl_Aggregate_TD_6815148_output.getInt32(i, 0);
        int64_t _ctr_total_return3547 = tbl_Aggregate_TD_6815148_output.getInt64(i, 1);
        SW_Aggregate_TD_5668083_key k = _ctr_store_sk3546;
        int64_t _123550_avg_0 = _ctr_total_return3547;
        int32_t _ctr_store_sk35463626 = _ctr_store_sk3546;
        SW_Aggregate_TD_5668083_payload p{_123550_avg_0, _ctr_store_sk35463626};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t avg_0 = ((it->second)._123550_avg_0 + _123550_avg_0);
            p._123550_avg_0 = avg_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _ctr_store_sk3546 not required in the output table
        int64_t _123550 = ((it.second)._123550_avg_0 / nrow1 * 1.200000);
        tbl_Aggregate_TD_5668083_output.setInt64(r, 0, _123550);
        tbl_Aggregate_TD_5668083_output.setInt32(r, 1, (it.second)._ctr_store_sk35463626);
        ++r;
    }
    tbl_Aggregate_TD_5668083_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_5668083_output #Row: " << tbl_Aggregate_TD_5668083_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_5380173_key {
    int32_t _sr_customer_sk672;
    int32_t _sr_store_sk676;
    bool operator==(const SW_Aggregate_TD_5380173_key& other) const { return (_sr_customer_sk672 == other._sr_customer_sk672) && (_sr_store_sk676 == other._sr_store_sk676); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_5380173_key> {
    std::size_t operator() (const SW_Aggregate_TD_5380173_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._sr_customer_sk672)) + (hash<int32_t>()(k._sr_store_sk676));
    }
};
}
struct SW_Aggregate_TD_5380173_payload {
    int32_t _ctr_customer_sk3545;
    int32_t _ctr_store_sk3546;
    int64_t _ctr_total_return3547_sum_0;
};
void SW_Aggregate_TD_5380173(Table &tbl_JOIN_INNER_TD_6717294_output, Table &tbl_Aggregate_TD_5380173_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(sr_customer_sk#672, sr_store_sk#676, sr_customer_sk#672 AS ctr_customer_sk#3545, sr_store_sk#676 AS ctr_store_sk#3546, MakeDecimal(sum(UnscaledValue(sr_return_amt#680)),17,2) AS ctr_total_return#3547)
    // Input: ListBuffer(sr_customer_sk#672, sr_store_sk#676, sr_return_amt#680)
    // Output: ListBuffer(ctr_customer_sk#3545, ctr_store_sk#3546, ctr_total_return#3547)
    std::unordered_map<SW_Aggregate_TD_5380173_key, SW_Aggregate_TD_5380173_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_6717294_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _sr_customer_sk672 = tbl_JOIN_INNER_TD_6717294_output.getInt32(i, 0);
        int32_t _sr_store_sk676 = tbl_JOIN_INNER_TD_6717294_output.getInt32(i, 1);
        int64_t _sr_return_amt680 = tbl_JOIN_INNER_TD_6717294_output.getInt64(i, 2);
        SW_Aggregate_TD_5380173_key k{_sr_customer_sk672, _sr_store_sk676};
        int32_t _ctr_customer_sk3545 = _sr_customer_sk672;
        int32_t _ctr_store_sk3546 = _sr_store_sk676;
        int64_t _ctr_total_return3547_sum_0 = _sr_return_amt680;
        SW_Aggregate_TD_5380173_payload p{_ctr_customer_sk3545, _ctr_store_sk3546, _ctr_total_return3547_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._ctr_total_return3547_sum_0 + _ctr_total_return3547_sum_0;
            p._ctr_total_return3547_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _sr_customer_sk672 not required in the output table
        // _sr_store_sk676 not required in the output table
        tbl_Aggregate_TD_5380173_output.setInt32(r, 0, (it.second)._ctr_customer_sk3545);
        tbl_Aggregate_TD_5380173_output.setInt32(r, 1, (it.second)._ctr_store_sk3546);
        int64_t _ctr_total_return3547 = (it.second)._ctr_total_return3547_sum_0;
        tbl_Aggregate_TD_5380173_output.setInt64(r, 2, _ctr_total_return3547);
        ++r;
    }
    tbl_Aggregate_TD_5380173_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_5380173_output #Row: " << tbl_Aggregate_TD_5380173_output.getNumRow() << std::endl;
}

void SW_Filter_TD_4955885(Table &tbl_Aggregate_TD_5668083_output, Table &tbl_Filter_TD_4955885_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull((avg(ctr_total_return) * 1.2)#3550))
    // Input: ListBuffer((avg(ctr_total_return) * 1.2)#3550, ctr_store_sk#3546#3626)
    // Output: ListBuffer((avg(ctr_total_return) * 1.2)#3550, ctr_store_sk#3546#3626)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_5668083_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _123550 = tbl_Aggregate_TD_5668083_output.getInt64(i, 0);
        if (_123550!= 0) {
            int64_t _123550_t = tbl_Aggregate_TD_5668083_output.getInt64(i, 0);
            tbl_Filter_TD_4955885_output.setInt64(r, 0, _123550_t);
            int32_t _ctr_store_sk35463626_t = tbl_Aggregate_TD_5668083_output.getInt32(i, 1);
            tbl_Filter_TD_4955885_output.setInt32(r, 1, _ctr_store_sk35463626_t);
            r++;
        }
    }
    tbl_Filter_TD_4955885_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4955885_output #Row: " << tbl_Filter_TD_4955885_output.getNumRow() << std::endl;
}

void SW_Filter_TD_432961(Table &tbl_Aggregate_TD_5380173_output, Table &tbl_Filter_TD_432961_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ctr_total_return#3547))
    // Input: ListBuffer(ctr_customer_sk#3545, ctr_store_sk#3546, ctr_total_return#3547)
    // Output: ListBuffer(ctr_customer_sk#3545, ctr_store_sk#3546, ctr_total_return#3547)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_5380173_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ctr_total_return3547 = tbl_Aggregate_TD_5380173_output.getInt64(i, 2);
        if (_ctr_total_return3547!= 0) {
            int32_t _ctr_customer_sk3545_t = tbl_Aggregate_TD_5380173_output.getInt32(i, 0);
            tbl_Filter_TD_432961_output.setInt32(r, 0, _ctr_customer_sk3545_t);
            int32_t _ctr_store_sk3546_t = tbl_Aggregate_TD_5380173_output.getInt32(i, 1);
            tbl_Filter_TD_432961_output.setInt32(r, 1, _ctr_store_sk3546_t);
            int64_t _ctr_total_return3547_t = tbl_Aggregate_TD_5380173_output.getInt64(i, 2);
            tbl_Filter_TD_432961_output.setInt64(r, 2, _ctr_total_return3547_t);
            r++;
        }
    }
    tbl_Filter_TD_432961_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_432961_output #Row: " << tbl_Filter_TD_432961_output.getNumRow() << std::endl;
}

void SW_Filter_TD_3343425(Table &tbl_SerializeFromObject_TD_4143755_input, Table &tbl_Filter_TD_3343425_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(s_state#402) AND (s_state#402 = TN)) AND isnotnull(s_store_sk#378)))
    // Input: ListBuffer(s_store_sk#378, s_state#402)
    // Output: ListBuffer(s_store_sk#378)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_4143755_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_state402 = tbl_SerializeFromObject_TD_4143755_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _s_store_sk378 = tbl_SerializeFromObject_TD_4143755_input.getInt32(i, 0);
        if ((_s_state402.data() != "NULL" && (std::string(_s_state402.data()) == "TN")) && (_s_store_sk378!= 0)) {
            int32_t _s_store_sk378_t = tbl_SerializeFromObject_TD_4143755_input.getInt32(i, 0);
            tbl_Filter_TD_3343425_output.setInt32(r, 0, _s_store_sk378_t);
            r++;
        }
    }
    tbl_Filter_TD_3343425_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_3343425_output #Row: " << tbl_Filter_TD_3343425_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_3587777_key_leftMajor {
    int32_t _ctr_store_sk3546;
    bool operator==(const SW_JOIN_INNER_TD_3587777_key_leftMajor& other) const {
        return ((_ctr_store_sk3546 == other._ctr_store_sk3546));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3587777_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3587777_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ctr_store_sk3546));
    }
};
}
struct SW_JOIN_INNER_TD_3587777_payload_leftMajor {
    int32_t _ctr_customer_sk3545;
    int32_t _ctr_store_sk3546;
    int64_t _ctr_total_return3547;
};
struct SW_JOIN_INNER_TD_3587777_key_rightMajor {
    int32_t _ctr_store_sk35463626;
    bool operator==(const SW_JOIN_INNER_TD_3587777_key_rightMajor& other) const {
        return ((_ctr_store_sk35463626 == other._ctr_store_sk35463626));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3587777_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3587777_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ctr_store_sk35463626));
    }
};
}
struct SW_JOIN_INNER_TD_3587777_payload_rightMajor {
    int64_t _123550;
    int32_t _ctr_store_sk35463626;
};
void SW_JOIN_INNER_TD_3587777(Table &tbl_Filter_TD_432961_output, Table &tbl_Filter_TD_4955885_output, Table &tbl_JOIN_INNER_TD_3587777_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((cast(ctr_total_return#3547 as decimal(24,7)) > (avg(ctr_total_return) * 1.2)#3550) AND (ctr_store_sk#3546 = ctr_store_sk#3546#3626)))
    // Left Table: ListBuffer(ctr_customer_sk#3545, ctr_store_sk#3546, ctr_total_return#3547)
    // Right Table: ListBuffer((avg(ctr_total_return) * 1.2)#3550, ctr_store_sk#3546#3626)
    // Output Table: ListBuffer(ctr_customer_sk#3545, ctr_store_sk#3546, ctr_total_return#3547)
    int left_nrow = tbl_Filter_TD_432961_output.getNumRow();
    int right_nrow = tbl_Filter_TD_4955885_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3587777_key_leftMajor, SW_JOIN_INNER_TD_3587777_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_432961_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ctr_store_sk3546_k = tbl_Filter_TD_432961_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_3587777_key_leftMajor keyA{_ctr_store_sk3546_k};
            int32_t _ctr_customer_sk3545 = tbl_Filter_TD_432961_output.getInt32(i, 0);
            int32_t _ctr_store_sk3546 = tbl_Filter_TD_432961_output.getInt32(i, 1);
            int64_t _ctr_total_return3547 = tbl_Filter_TD_432961_output.getInt64(i, 2);
            SW_JOIN_INNER_TD_3587777_payload_leftMajor payloadA{_ctr_customer_sk3545, _ctr_store_sk3546, _ctr_total_return3547};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_4955885_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ctr_store_sk35463626_k = tbl_Filter_TD_4955885_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3587777_key_leftMajor{_ctr_store_sk35463626_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ctr_customer_sk3545 = (it->second)._ctr_customer_sk3545;
                int32_t _ctr_store_sk3546 = (it->second)._ctr_store_sk3546;
                int64_t _ctr_total_return3547 = (it->second)._ctr_total_return3547;
                int64_t _123550 = tbl_Filter_TD_4955885_output.getInt64(i, 0);
                int32_t _ctr_store_sk35463626 = tbl_Filter_TD_4955885_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_3587777_output.setInt32(r, 0, _ctr_customer_sk3545);
                tbl_JOIN_INNER_TD_3587777_output.setInt32(r, 1, _ctr_store_sk3546);
                tbl_JOIN_INNER_TD_3587777_output.setInt64(r, 2, _ctr_total_return3547);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3587777_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3587777_key_rightMajor, SW_JOIN_INNER_TD_3587777_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_4955885_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ctr_store_sk35463626_k = tbl_Filter_TD_4955885_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_3587777_key_rightMajor keyA{_ctr_store_sk35463626_k};
            int64_t _123550 = tbl_Filter_TD_4955885_output.getInt64(i, 0);
            int32_t _ctr_store_sk35463626 = tbl_Filter_TD_4955885_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_3587777_payload_rightMajor payloadA{_123550, _ctr_store_sk35463626};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_432961_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ctr_store_sk3546_k = tbl_Filter_TD_432961_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3587777_key_rightMajor{_ctr_store_sk3546_k});
            auto it = its.first;
            while (it != its.second) {
                int64_t _123550 = (it->second)._123550;
                int32_t _ctr_store_sk35463626 = (it->second)._ctr_store_sk35463626;
                int32_t _ctr_customer_sk3545 = tbl_Filter_TD_432961_output.getInt32(i, 0);
                int32_t _ctr_store_sk3546 = tbl_Filter_TD_432961_output.getInt32(i, 1);
                int64_t _ctr_total_return3547 = tbl_Filter_TD_432961_output.getInt64(i, 2);
                tbl_JOIN_INNER_TD_3587777_output.setInt32(r, 0, _ctr_customer_sk3545);
                tbl_JOIN_INNER_TD_3587777_output.setInt32(r, 1, _ctr_store_sk3546);
                tbl_JOIN_INNER_TD_3587777_output.setInt64(r, 2, _ctr_total_return3547);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3587777_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_3587777_output #Row: " << tbl_JOIN_INNER_TD_3587777_output.getNumRow() << std::endl;
}

void SW_Filter_TD_2130844(Table &tbl_SerializeFromObject_TD_3147357_input, Table &tbl_Filter_TD_2130844_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(c_customer_sk#0))
    // Input: ListBuffer(c_customer_sk#0, c_customer_id#1)
    // Output: ListBuffer(c_customer_sk#0, c_customer_id#1)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_3147357_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk0 = tbl_SerializeFromObject_TD_3147357_input.getInt32(i, 0);
        if (_c_customer_sk0!= 0) {
            int32_t _c_customer_sk0_t = tbl_SerializeFromObject_TD_3147357_input.getInt32(i, 0);
            tbl_Filter_TD_2130844_output.setInt32(r, 0, _c_customer_sk0_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_t = tbl_SerializeFromObject_TD_3147357_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_2130844_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_customer_id1_t);
            r++;
        }
    }
    tbl_Filter_TD_2130844_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2130844_output #Row: " << tbl_Filter_TD_2130844_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_2840998_key_leftMajor {
    int32_t _ctr_store_sk3546;
    bool operator==(const SW_JOIN_INNER_TD_2840998_key_leftMajor& other) const {
        return ((_ctr_store_sk3546 == other._ctr_store_sk3546));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_2840998_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_2840998_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ctr_store_sk3546));
    }
};
}
struct SW_JOIN_INNER_TD_2840998_payload_leftMajor {
    int32_t _ctr_customer_sk3545;
    int32_t _ctr_store_sk3546;
    int64_t _ctr_total_return3547;
};
struct SW_JOIN_INNER_TD_2840998_key_rightMajor {
    int32_t _s_store_sk378;
    bool operator==(const SW_JOIN_INNER_TD_2840998_key_rightMajor& other) const {
        return ((_s_store_sk378 == other._s_store_sk378));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_2840998_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_2840998_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_store_sk378));
    }
};
}
struct SW_JOIN_INNER_TD_2840998_payload_rightMajor {
    int32_t _s_store_sk378;
};
void SW_JOIN_INNER_TD_2840998(Table &tbl_JOIN_INNER_TD_3587777_output, Table &tbl_Filter_TD_3343425_output, Table &tbl_JOIN_INNER_TD_2840998_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((s_store_sk#378 = ctr_store_sk#3546))
    // Left Table: ListBuffer(ctr_customer_sk#3545, ctr_store_sk#3546, ctr_total_return#3547)
    // Right Table: ListBuffer(s_store_sk#378)
    // Output Table: ListBuffer(ctr_customer_sk#3545, ctr_total_return#3547)
    int left_nrow = tbl_JOIN_INNER_TD_3587777_output.getNumRow();
    int right_nrow = tbl_Filter_TD_3343425_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_2840998_key_leftMajor, SW_JOIN_INNER_TD_2840998_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_3587777_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ctr_store_sk3546_k = tbl_JOIN_INNER_TD_3587777_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_2840998_key_leftMajor keyA{_ctr_store_sk3546_k};
            int32_t _ctr_customer_sk3545 = tbl_JOIN_INNER_TD_3587777_output.getInt32(i, 0);
            int32_t _ctr_store_sk3546 = tbl_JOIN_INNER_TD_3587777_output.getInt32(i, 1);
            int64_t _ctr_total_return3547 = tbl_JOIN_INNER_TD_3587777_output.getInt64(i, 2);
            SW_JOIN_INNER_TD_2840998_payload_leftMajor payloadA{_ctr_customer_sk3545, _ctr_store_sk3546, _ctr_total_return3547};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_3343425_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_3343425_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_2840998_key_leftMajor{_s_store_sk378_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ctr_customer_sk3545 = (it->second)._ctr_customer_sk3545;
                int32_t _ctr_store_sk3546 = (it->second)._ctr_store_sk3546;
                int64_t _ctr_total_return3547 = (it->second)._ctr_total_return3547;
                int32_t _s_store_sk378 = tbl_Filter_TD_3343425_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_2840998_output.setInt32(r, 0, _ctr_customer_sk3545);
                tbl_JOIN_INNER_TD_2840998_output.setInt64(r, 1, _ctr_total_return3547);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_2840998_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_2840998_key_rightMajor, SW_JOIN_INNER_TD_2840998_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_3343425_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_3343425_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_2840998_key_rightMajor keyA{_s_store_sk378_k};
            int32_t _s_store_sk378 = tbl_Filter_TD_3343425_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_2840998_payload_rightMajor payloadA{_s_store_sk378};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_3587777_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ctr_store_sk3546_k = tbl_JOIN_INNER_TD_3587777_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_2840998_key_rightMajor{_ctr_store_sk3546_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _s_store_sk378 = (it->second)._s_store_sk378;
                int32_t _ctr_customer_sk3545 = tbl_JOIN_INNER_TD_3587777_output.getInt32(i, 0);
                int32_t _ctr_store_sk3546 = tbl_JOIN_INNER_TD_3587777_output.getInt32(i, 1);
                int64_t _ctr_total_return3547 = tbl_JOIN_INNER_TD_3587777_output.getInt64(i, 2);
                tbl_JOIN_INNER_TD_2840998_output.setInt32(r, 0, _ctr_customer_sk3545);
                tbl_JOIN_INNER_TD_2840998_output.setInt64(r, 1, _ctr_total_return3547);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_2840998_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_2840998_output #Row: " << tbl_JOIN_INNER_TD_2840998_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_1751278_key_leftMajor {
    int32_t _ctr_customer_sk3545;
    bool operator==(const SW_JOIN_INNER_TD_1751278_key_leftMajor& other) const {
        return ((_ctr_customer_sk3545 == other._ctr_customer_sk3545));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_1751278_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_1751278_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ctr_customer_sk3545));
    }
};
}
struct SW_JOIN_INNER_TD_1751278_payload_leftMajor {
    int32_t _ctr_customer_sk3545;
    int64_t _ctr_total_return3547;
};
struct SW_JOIN_INNER_TD_1751278_key_rightMajor {
    int32_t _c_customer_sk0;
    bool operator==(const SW_JOIN_INNER_TD_1751278_key_rightMajor& other) const {
        return ((_c_customer_sk0 == other._c_customer_sk0));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_1751278_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_1751278_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk0));
    }
};
}
struct SW_JOIN_INNER_TD_1751278_payload_rightMajor {
    int32_t _c_customer_sk0;
    std::string _c_customer_id1;
};
void SW_JOIN_INNER_TD_1751278(Table &tbl_JOIN_INNER_TD_2840998_output, Table &tbl_Filter_TD_2130844_output, Table &tbl_JOIN_INNER_TD_1751278_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ctr_customer_sk#3545 = c_customer_sk#0))
    // Left Table: ListBuffer(ctr_customer_sk#3545, ctr_total_return#3547)
    // Right Table: ListBuffer(c_customer_sk#0, c_customer_id#1)
    // Output Table: ListBuffer(c_customer_id#1, ctr_total_return#3547)
    int left_nrow = tbl_JOIN_INNER_TD_2840998_output.getNumRow();
    int right_nrow = tbl_Filter_TD_2130844_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_1751278_key_leftMajor, SW_JOIN_INNER_TD_1751278_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_2840998_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ctr_customer_sk3545_k = tbl_JOIN_INNER_TD_2840998_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_1751278_key_leftMajor keyA{_ctr_customer_sk3545_k};
            int32_t _ctr_customer_sk3545 = tbl_JOIN_INNER_TD_2840998_output.getInt32(i, 0);
            int64_t _ctr_total_return3547 = tbl_JOIN_INNER_TD_2840998_output.getInt64(i, 1);
            SW_JOIN_INNER_TD_1751278_payload_leftMajor payloadA{_ctr_customer_sk3545, _ctr_total_return3547};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_2130844_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_2130844_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_1751278_key_leftMajor{_c_customer_sk0_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ctr_customer_sk3545 = (it->second)._ctr_customer_sk3545;
                int64_t _ctr_total_return3547 = (it->second)._ctr_total_return3547;
                int32_t _c_customer_sk0 = tbl_Filter_TD_2130844_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n = tbl_Filter_TD_2130844_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_customer_id1 = std::string(_c_customer_id1_n.data());
                tbl_JOIN_INNER_TD_1751278_output.setInt64(r, 1, _ctr_total_return3547);
                tbl_JOIN_INNER_TD_1751278_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id1_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_1751278_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_1751278_key_rightMajor, SW_JOIN_INNER_TD_1751278_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_2130844_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_2130844_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_1751278_key_rightMajor keyA{_c_customer_sk0_k};
            int32_t _c_customer_sk0 = tbl_Filter_TD_2130844_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n = tbl_Filter_TD_2130844_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_customer_id1 = std::string(_c_customer_id1_n.data());
            SW_JOIN_INNER_TD_1751278_payload_rightMajor payloadA{_c_customer_sk0, _c_customer_id1};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_2840998_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ctr_customer_sk3545_k = tbl_JOIN_INNER_TD_2840998_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_1751278_key_rightMajor{_ctr_customer_sk3545_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk0 = (it->second)._c_customer_sk0;
                std::string _c_customer_id1 = (it->second)._c_customer_id1;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n{};
                memcpy(_c_customer_id1_n.data(), (_c_customer_id1).data(), (_c_customer_id1).length());
                int32_t _ctr_customer_sk3545 = tbl_JOIN_INNER_TD_2840998_output.getInt32(i, 0);
                int64_t _ctr_total_return3547 = tbl_JOIN_INNER_TD_2840998_output.getInt64(i, 1);
                tbl_JOIN_INNER_TD_1751278_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id1_n);
                tbl_JOIN_INNER_TD_1751278_output.setInt64(r, 1, _ctr_total_return3547);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_1751278_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_1751278_output #Row: " << tbl_JOIN_INNER_TD_1751278_output.getNumRow() << std::endl;
}

void SW_Sort_TD_0580320(Table &tbl_JOIN_INNER_TD_1751278_output, Table &tbl_Sort_TD_0580320_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(c_customer_id#1 ASC NULLS FIRST)
    // Input: ListBuffer(c_customer_id#1, ctr_total_return#3547)
    // Output: ListBuffer(c_customer_id#1, ctr_total_return#3547)
    struct SW_Sort_TD_0580320Row {
        std::string _c_customer_id1;
        int64_t _ctr_total_return3547;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_0580320Row& a, const SW_Sort_TD_0580320Row& b) const { return 
 (a._c_customer_id1 < b._c_customer_id1); 
}
    }SW_Sort_TD_0580320_order; 

    int nrow1 = tbl_JOIN_INNER_TD_1751278_output.getNumRow();
    std::vector<SW_Sort_TD_0580320Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1 = tbl_JOIN_INNER_TD_1751278_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        int64_t _ctr_total_return3547 = tbl_JOIN_INNER_TD_1751278_output.getInt64(i, 1);
        SW_Sort_TD_0580320Row t = {std::string(_c_customer_id1.data()),_ctr_total_return3547};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_0580320_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1{};
        memcpy(_c_customer_id1.data(), (it._c_customer_id1).data(), (it._c_customer_id1).length());
        tbl_Sort_TD_0580320_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _c_customer_id1);
        tbl_Sort_TD_0580320_output.setInt64(r, 1, it._ctr_total_return3547);
        if (r < 10) {
            std::cout << (it._c_customer_id1).data() << " " << it._ctr_total_return3547 << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_0580320_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_0580320_output #Row: " << tbl_Sort_TD_0580320_output.getNumRow() << std::endl;
}

