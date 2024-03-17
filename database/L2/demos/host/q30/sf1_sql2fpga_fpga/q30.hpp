#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_1184101(Table &tbl_SerializeFromObject_TD_12313967_input, Table &tbl_Filter_TD_1184101_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#126) AND (d_year#126 = 2002)) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12313967_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_12313967_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_12313967_input.getInt32(i, 0);
        if (((_d_year126!= 0) && (_d_year126 == 2002)) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_12313967_input.getInt32(i, 0);
            tbl_Filter_TD_1184101_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_1184101_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1184101_output #Row: " << tbl_Filter_TD_1184101_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11560775(Table &tbl_SerializeFromObject_TD_12940974_input, Table &tbl_Filter_TD_11560775_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(wr_returned_date_sk#831) AND isnotnull(wr_returning_addr_sk#841)))
    // Input: ListBuffer(wr_returned_date_sk#831, wr_returning_customer_sk#838, wr_returning_addr_sk#841, wr_return_amt#846)
    // Output: ListBuffer(wr_returned_date_sk#831, wr_returning_customer_sk#838, wr_returning_addr_sk#841, wr_return_amt#846)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12940974_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _wr_returned_date_sk831 = tbl_SerializeFromObject_TD_12940974_input.getInt32(i, 0);
        int32_t _wr_returning_addr_sk841 = tbl_SerializeFromObject_TD_12940974_input.getInt32(i, 2);
        if ((_wr_returned_date_sk831!= 0) && (_wr_returning_addr_sk841!= 0)) {
            int32_t _wr_returned_date_sk831_t = tbl_SerializeFromObject_TD_12940974_input.getInt32(i, 0);
            tbl_Filter_TD_11560775_output.setInt32(r, 0, _wr_returned_date_sk831_t);
            int32_t _wr_returning_customer_sk838_t = tbl_SerializeFromObject_TD_12940974_input.getInt32(i, 1);
            tbl_Filter_TD_11560775_output.setInt32(r, 1, _wr_returning_customer_sk838_t);
            int32_t _wr_returning_addr_sk841_t = tbl_SerializeFromObject_TD_12940974_input.getInt32(i, 2);
            tbl_Filter_TD_11560775_output.setInt32(r, 2, _wr_returning_addr_sk841_t);
            int64_t _wr_return_amt846_t = tbl_SerializeFromObject_TD_12940974_input.getInt64(i, 3);
            tbl_Filter_TD_11560775_output.setInt64(r, 3, _wr_return_amt846_t);
            r++;
        }
    }
    tbl_Filter_TD_11560775_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11560775_output #Row: " << tbl_Filter_TD_11560775_output.getNumRow() << std::endl;
}

void SW_Filter_TD_1050616(Table &tbl_SerializeFromObject_TD_11716935_input, Table &tbl_Filter_TD_1050616_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ca_address_sk#54) AND isnotnull(ca_state#62)))
    // Input: ListBuffer(ca_address_sk#54, ca_state#62)
    // Output: ListBuffer(ca_address_sk#54, ca_state#62)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11716935_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ca_address_sk54 = tbl_SerializeFromObject_TD_11716935_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _ca_state62 = tbl_SerializeFromObject_TD_11716935_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_ca_address_sk54!= 0) && _ca_state62.data() != "NULL") {
            int32_t _ca_address_sk54_t = tbl_SerializeFromObject_TD_11716935_input.getInt32(i, 0);
            tbl_Filter_TD_1050616_output.setInt32(r, 0, _ca_address_sk54_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_t = tbl_SerializeFromObject_TD_11716935_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_1050616_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_state62_t);
            r++;
        }
    }
    tbl_Filter_TD_1050616_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1050616_output #Row: " << tbl_Filter_TD_1050616_output.getNumRow() << std::endl;
}


void SW_Filter_TD_10123525(Table &tbl_SerializeFromObject_TD_11131620_input, Table &tbl_Filter_TD_10123525_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#126) AND (d_year#126 = 2002)) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11131620_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_11131620_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_11131620_input.getInt32(i, 0);
        if (((_d_year126!= 0) && (_d_year126 == 2002)) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_11131620_input.getInt32(i, 0);
            tbl_Filter_TD_10123525_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_10123525_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10123525_output #Row: " << tbl_Filter_TD_10123525_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10910584(Table &tbl_SerializeFromObject_TD_11399790_input, Table &tbl_Filter_TD_10910584_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(wr_returned_date_sk#831) AND isnotnull(wr_returning_addr_sk#841)) AND isnotnull(wr_returning_customer_sk#838)))
    // Input: ListBuffer(wr_returned_date_sk#831, wr_returning_customer_sk#838, wr_returning_addr_sk#841, wr_return_amt#846)
    // Output: ListBuffer(wr_returned_date_sk#831, wr_returning_customer_sk#838, wr_returning_addr_sk#841, wr_return_amt#846)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11399790_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _wr_returned_date_sk831 = tbl_SerializeFromObject_TD_11399790_input.getInt32(i, 0);
        int32_t _wr_returning_addr_sk841 = tbl_SerializeFromObject_TD_11399790_input.getInt32(i, 2);
        int32_t _wr_returning_customer_sk838 = tbl_SerializeFromObject_TD_11399790_input.getInt32(i, 1);
        if (((_wr_returned_date_sk831!= 0) && (_wr_returning_addr_sk841!= 0)) && (_wr_returning_customer_sk838!= 0)) {
            int32_t _wr_returned_date_sk831_t = tbl_SerializeFromObject_TD_11399790_input.getInt32(i, 0);
            tbl_Filter_TD_10910584_output.setInt32(r, 0, _wr_returned_date_sk831_t);
            int32_t _wr_returning_customer_sk838_t = tbl_SerializeFromObject_TD_11399790_input.getInt32(i, 1);
            tbl_Filter_TD_10910584_output.setInt32(r, 1, _wr_returning_customer_sk838_t);
            int32_t _wr_returning_addr_sk841_t = tbl_SerializeFromObject_TD_11399790_input.getInt32(i, 2);
            tbl_Filter_TD_10910584_output.setInt32(r, 2, _wr_returning_addr_sk841_t);
            int64_t _wr_return_amt846_t = tbl_SerializeFromObject_TD_11399790_input.getInt64(i, 3);
            tbl_Filter_TD_10910584_output.setInt64(r, 3, _wr_return_amt846_t);
            r++;
        }
    }
    tbl_Filter_TD_10910584_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10910584_output #Row: " << tbl_Filter_TD_10910584_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_9976930_key_leftMajor {
    int32_t _wr_returning_addr_sk841;
    bool operator==(const SW_JOIN_INNER_TD_9976930_key_leftMajor& other) const {
        return ((_wr_returning_addr_sk841 == other._wr_returning_addr_sk841));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9976930_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9976930_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._wr_returning_addr_sk841));
    }
};
}
struct SW_JOIN_INNER_TD_9976930_payload_leftMajor {
    int32_t _wr_returning_customer_sk838;
    int32_t _wr_returning_addr_sk841;
    int64_t _wr_return_amt846;
};
struct SW_JOIN_INNER_TD_9976930_key_rightMajor {
    int32_t _ca_address_sk54;
    bool operator==(const SW_JOIN_INNER_TD_9976930_key_rightMajor& other) const {
        return ((_ca_address_sk54 == other._ca_address_sk54));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9976930_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9976930_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk54));
    }
};
}
struct SW_JOIN_INNER_TD_9976930_payload_rightMajor {
    int32_t _ca_address_sk54;
    std::string _ca_state62;
};
void SW_JOIN_INNER_TD_9976930(Table &tbl_JOIN_INNER_TD_10280374_output, Table &tbl_Filter_TD_1050616_output, Table &tbl_JOIN_INNER_TD_9976930_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((wr_returning_addr_sk#841 = ca_address_sk#54))
    // Left Table: ListBuffer(wr_returning_customer_sk#838, wr_returning_addr_sk#841, wr_return_amt#846)
    // Right Table: ListBuffer(ca_address_sk#54, ca_state#62)
    // Output Table: ListBuffer(wr_returning_customer_sk#838, wr_return_amt#846, ca_state#62)
    int left_nrow = tbl_JOIN_INNER_TD_10280374_output.getNumRow();
    int right_nrow = tbl_Filter_TD_1050616_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9976930_key_leftMajor, SW_JOIN_INNER_TD_9976930_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_10280374_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _wr_returning_addr_sk841_k = tbl_JOIN_INNER_TD_10280374_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_9976930_key_leftMajor keyA{_wr_returning_addr_sk841_k};
            int32_t _wr_returning_customer_sk838 = tbl_JOIN_INNER_TD_10280374_output.getInt32(i, 0);
            int32_t _wr_returning_addr_sk841 = tbl_JOIN_INNER_TD_10280374_output.getInt32(i, 1);
            int64_t _wr_return_amt846 = tbl_JOIN_INNER_TD_10280374_output.getInt64(i, 2);
            SW_JOIN_INNER_TD_9976930_payload_leftMajor payloadA{_wr_returning_customer_sk838, _wr_returning_addr_sk841, _wr_return_amt846};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_1050616_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_1050616_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9976930_key_leftMajor{_ca_address_sk54_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _wr_returning_customer_sk838 = (it->second)._wr_returning_customer_sk838;
                int32_t _wr_returning_addr_sk841 = (it->second)._wr_returning_addr_sk841;
                int64_t _wr_return_amt846 = (it->second)._wr_return_amt846;
                int32_t _ca_address_sk54 = tbl_Filter_TD_1050616_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_Filter_TD_1050616_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_state62 = std::string(_ca_state62_n.data());
                tbl_JOIN_INNER_TD_9976930_output.setInt32(r, 0, _wr_returning_customer_sk838);
                tbl_JOIN_INNER_TD_9976930_output.setInt64(r, 1, _wr_return_amt846);
                tbl_JOIN_INNER_TD_9976930_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_state62_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9976930_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9976930_key_rightMajor, SW_JOIN_INNER_TD_9976930_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_1050616_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_1050616_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_9976930_key_rightMajor keyA{_ca_address_sk54_k};
            int32_t _ca_address_sk54 = tbl_Filter_TD_1050616_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_Filter_TD_1050616_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_state62 = std::string(_ca_state62_n.data());
            SW_JOIN_INNER_TD_9976930_payload_rightMajor payloadA{_ca_address_sk54, _ca_state62};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_10280374_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _wr_returning_addr_sk841_k = tbl_JOIN_INNER_TD_10280374_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9976930_key_rightMajor{_wr_returning_addr_sk841_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk54 = (it->second)._ca_address_sk54;
                std::string _ca_state62 = (it->second)._ca_state62;
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n{};
                memcpy(_ca_state62_n.data(), (_ca_state62).data(), (_ca_state62).length());
                int32_t _wr_returning_customer_sk838 = tbl_JOIN_INNER_TD_10280374_output.getInt32(i, 0);
                int32_t _wr_returning_addr_sk841 = tbl_JOIN_INNER_TD_10280374_output.getInt32(i, 1);
                int64_t _wr_return_amt846 = tbl_JOIN_INNER_TD_10280374_output.getInt64(i, 2);
                tbl_JOIN_INNER_TD_9976930_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_state62_n);
                tbl_JOIN_INNER_TD_9976930_output.setInt32(r, 0, _wr_returning_customer_sk838);
                tbl_JOIN_INNER_TD_9976930_output.setInt64(r, 1, _wr_return_amt846);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9976930_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_9976930_output #Row: " << tbl_JOIN_INNER_TD_9976930_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9477549(Table &tbl_SerializeFromObject_TD_10545088_input, Table &tbl_Filter_TD_9477549_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ca_address_sk#54) AND isnotnull(ca_state#62)))
    // Input: ListBuffer(ca_address_sk#54, ca_state#62)
    // Output: ListBuffer(ca_address_sk#54, ca_state#62)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10545088_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ca_address_sk54 = tbl_SerializeFromObject_TD_10545088_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _ca_state62 = tbl_SerializeFromObject_TD_10545088_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_ca_address_sk54!= 0) && _ca_state62.data() != "NULL") {
            int32_t _ca_address_sk54_t = tbl_SerializeFromObject_TD_10545088_input.getInt32(i, 0);
            tbl_Filter_TD_9477549_output.setInt32(r, 0, _ca_address_sk54_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_t = tbl_SerializeFromObject_TD_10545088_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_9477549_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_state62_t);
            r++;
        }
    }
    tbl_Filter_TD_9477549_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9477549_output #Row: " << tbl_Filter_TD_9477549_output.getNumRow() << std::endl;
}


struct SW_Aggregate_TD_8936138_key {
    int32_t _wr_returning_customer_sk838;
    std::string _ca_state62;
    bool operator==(const SW_Aggregate_TD_8936138_key& other) const { return (_wr_returning_customer_sk838 == other._wr_returning_customer_sk838) && (_ca_state62 == other._ca_state62); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_8936138_key> {
    std::size_t operator() (const SW_Aggregate_TD_8936138_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._wr_returning_customer_sk838)) + (hash<string>()(k._ca_state62));
    }
};
}
struct SW_Aggregate_TD_8936138_payload {
    std::string _ctr_state3546;
    int64_t _ctr_total_return3547_sum_0;
};
void SW_Aggregate_TD_8936138(Table &tbl_JOIN_INNER_TD_9976930_output, Table &tbl_Aggregate_TD_8936138_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(wr_returning_customer_sk#838, ca_state#62, ca_state#62 AS ctr_state#3546, MakeDecimal(sum(UnscaledValue(wr_return_amt#846)),17,2) AS ctr_total_return#3547)
    // Input: ListBuffer(wr_returning_customer_sk#838, wr_return_amt#846, ca_state#62)
    // Output: ListBuffer(ctr_state#3546, ctr_total_return#3547)
    std::unordered_map<SW_Aggregate_TD_8936138_key, SW_Aggregate_TD_8936138_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_9976930_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _wr_returning_customer_sk838 = tbl_JOIN_INNER_TD_9976930_output.getInt32(i, 0);
        int64_t _wr_return_amt846 = tbl_JOIN_INNER_TD_9976930_output.getInt64(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _ca_state62 = tbl_JOIN_INNER_TD_9976930_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        SW_Aggregate_TD_8936138_key k{_wr_returning_customer_sk838, std::string(_ca_state62.data())};
        std::array<char, TPCDS_READ_MAX + 1> _ctr_state3546 = _ca_state62;
        int64_t _ctr_total_return3547_sum_0 = _wr_return_amt846;
        SW_Aggregate_TD_8936138_payload p{std::string(_ctr_state3546.data()), _ctr_total_return3547_sum_0};
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
        // _wr_returning_customer_sk838 not required in the output table
        // _ca_state62 not required in the output table
        std::array<char, TPCDS_READ_MAX + 1> _ctr_state3546_n{};
        memcpy(_ctr_state3546_n.data(), (it.second)._ctr_state3546.data(), (it.second)._ctr_state3546.length());
        tbl_Aggregate_TD_8936138_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ctr_state3546_n);
        int64_t _ctr_total_return3547 = (it.second)._ctr_total_return3547_sum_0;
        tbl_Aggregate_TD_8936138_output.setInt64(r, 1, _ctr_total_return3547);
        ++r;
    }
    tbl_Aggregate_TD_8936138_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_8936138_output #Row: " << tbl_Aggregate_TD_8936138_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8601458_key_leftMajor {
    int32_t _wr_returning_addr_sk841;
    bool operator==(const SW_JOIN_INNER_TD_8601458_key_leftMajor& other) const {
        return ((_wr_returning_addr_sk841 == other._wr_returning_addr_sk841));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8601458_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8601458_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._wr_returning_addr_sk841));
    }
};
}
struct SW_JOIN_INNER_TD_8601458_payload_leftMajor {
    int32_t _wr_returning_customer_sk838;
    int32_t _wr_returning_addr_sk841;
    int64_t _wr_return_amt846;
};
struct SW_JOIN_INNER_TD_8601458_key_rightMajor {
    int32_t _ca_address_sk54;
    bool operator==(const SW_JOIN_INNER_TD_8601458_key_rightMajor& other) const {
        return ((_ca_address_sk54 == other._ca_address_sk54));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8601458_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8601458_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk54));
    }
};
}
struct SW_JOIN_INNER_TD_8601458_payload_rightMajor {
    int32_t _ca_address_sk54;
    std::string _ca_state62;
};
void SW_JOIN_INNER_TD_8601458(Table &tbl_JOIN_INNER_TD_9405197_output, Table &tbl_Filter_TD_9477549_output, Table &tbl_JOIN_INNER_TD_8601458_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((wr_returning_addr_sk#841 = ca_address_sk#54))
    // Left Table: ListBuffer(wr_returning_customer_sk#838, wr_returning_addr_sk#841, wr_return_amt#846)
    // Right Table: ListBuffer(ca_address_sk#54, ca_state#62)
    // Output Table: ListBuffer(wr_returning_customer_sk#838, wr_return_amt#846, ca_state#62)
    int left_nrow = tbl_JOIN_INNER_TD_9405197_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9477549_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8601458_key_leftMajor, SW_JOIN_INNER_TD_8601458_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_9405197_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _wr_returning_addr_sk841_k = tbl_JOIN_INNER_TD_9405197_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_8601458_key_leftMajor keyA{_wr_returning_addr_sk841_k};
            int32_t _wr_returning_customer_sk838 = tbl_JOIN_INNER_TD_9405197_output.getInt32(i, 0);
            int32_t _wr_returning_addr_sk841 = tbl_JOIN_INNER_TD_9405197_output.getInt32(i, 1);
            int64_t _wr_return_amt846 = tbl_JOIN_INNER_TD_9405197_output.getInt64(i, 2);
            SW_JOIN_INNER_TD_8601458_payload_leftMajor payloadA{_wr_returning_customer_sk838, _wr_returning_addr_sk841, _wr_return_amt846};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9477549_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_9477549_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8601458_key_leftMajor{_ca_address_sk54_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _wr_returning_customer_sk838 = (it->second)._wr_returning_customer_sk838;
                int32_t _wr_returning_addr_sk841 = (it->second)._wr_returning_addr_sk841;
                int64_t _wr_return_amt846 = (it->second)._wr_return_amt846;
                int32_t _ca_address_sk54 = tbl_Filter_TD_9477549_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_Filter_TD_9477549_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_state62 = std::string(_ca_state62_n.data());
                tbl_JOIN_INNER_TD_8601458_output.setInt32(r, 0, _wr_returning_customer_sk838);
                tbl_JOIN_INNER_TD_8601458_output.setInt64(r, 1, _wr_return_amt846);
                tbl_JOIN_INNER_TD_8601458_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_state62_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8601458_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8601458_key_rightMajor, SW_JOIN_INNER_TD_8601458_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9477549_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_9477549_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8601458_key_rightMajor keyA{_ca_address_sk54_k};
            int32_t _ca_address_sk54 = tbl_Filter_TD_9477549_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_Filter_TD_9477549_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_state62 = std::string(_ca_state62_n.data());
            SW_JOIN_INNER_TD_8601458_payload_rightMajor payloadA{_ca_address_sk54, _ca_state62};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_9405197_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _wr_returning_addr_sk841_k = tbl_JOIN_INNER_TD_9405197_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8601458_key_rightMajor{_wr_returning_addr_sk841_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk54 = (it->second)._ca_address_sk54;
                std::string _ca_state62 = (it->second)._ca_state62;
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n{};
                memcpy(_ca_state62_n.data(), (_ca_state62).data(), (_ca_state62).length());
                int32_t _wr_returning_customer_sk838 = tbl_JOIN_INNER_TD_9405197_output.getInt32(i, 0);
                int32_t _wr_returning_addr_sk841 = tbl_JOIN_INNER_TD_9405197_output.getInt32(i, 1);
                int64_t _wr_return_amt846 = tbl_JOIN_INNER_TD_9405197_output.getInt64(i, 2);
                tbl_JOIN_INNER_TD_8601458_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_state62_n);
                tbl_JOIN_INNER_TD_8601458_output.setInt32(r, 0, _wr_returning_customer_sk838);
                tbl_JOIN_INNER_TD_8601458_output.setInt64(r, 1, _wr_return_amt846);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8601458_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8601458_output #Row: " << tbl_JOIN_INNER_TD_8601458_output.getNumRow() << std::endl;
}

typedef std::string SW_Aggregate_TD_7575826_key;
struct SW_Aggregate_TD_7575826_payload {
    int64_t _123563_avg_0;
    std::string _ctr_state35463697;
};
void SW_Aggregate_TD_7575826(Table &tbl_Aggregate_TD_8936138_output, Table &tbl_Aggregate_TD_7575826_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(ctr_state#3546, CheckOverflow((promote_precision(avg(ctr_total_return#3547)) * 1.200000), DecimalType(24,7), true) AS (avg(ctr_total_return) * 1.2)#3563, ctr_state#3546 AS ctr_state#3546#3697)
    // Input: ListBuffer(ctr_state#3546, ctr_total_return#3547)
    // Output: ListBuffer((avg(ctr_total_return) * 1.2)#3563, ctr_state#3546#3697)
    std::unordered_map<SW_Aggregate_TD_7575826_key, SW_Aggregate_TD_7575826_payload> ht1;
    int nrow1 = tbl_Aggregate_TD_8936138_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _ctr_state3546 = tbl_Aggregate_TD_8936138_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        int64_t _ctr_total_return3547 = tbl_Aggregate_TD_8936138_output.getInt64(i, 1);
        SW_Aggregate_TD_7575826_key k = std::string(_ctr_state3546.data());
        int64_t _123563_avg_0 = _ctr_total_return3547;
        std::array<char, TPCDS_READ_MAX + 1> _ctr_state35463697 = _ctr_state3546;
        SW_Aggregate_TD_7575826_payload p{_123563_avg_0, std::string(_ctr_state35463697.data())};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t avg_0 = ((it->second)._123563_avg_0 + _123563_avg_0);
            p._123563_avg_0 = avg_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _ctr_state3546 not required in the output table
        int64_t _123563 = ((it.second)._123563_avg_0 / nrow1 * 1.200000);
        tbl_Aggregate_TD_7575826_output.setInt64(r, 0, _123563);
        std::array<char, TPCDS_READ_MAX + 1> _ctr_state35463697_n{};
        memcpy(_ctr_state35463697_n.data(), (it.second)._ctr_state35463697.data(), (it.second)._ctr_state35463697.length());
        tbl_Aggregate_TD_7575826_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ctr_state35463697_n);
        ++r;
    }
    tbl_Aggregate_TD_7575826_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_7575826_output #Row: " << tbl_Aggregate_TD_7575826_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_7493319_key {
    int32_t _wr_returning_customer_sk838;
    std::string _ca_state62;
    bool operator==(const SW_Aggregate_TD_7493319_key& other) const { return (_wr_returning_customer_sk838 == other._wr_returning_customer_sk838) && (_ca_state62 == other._ca_state62); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_7493319_key> {
    std::size_t operator() (const SW_Aggregate_TD_7493319_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._wr_returning_customer_sk838)) + (hash<string>()(k._ca_state62));
    }
};
}
struct SW_Aggregate_TD_7493319_payload {
    int32_t _ctr_customer_sk3545;
    std::string _ctr_state3546;
    int64_t _ctr_total_return3547_sum_0;
};
void SW_Aggregate_TD_7493319(Table &tbl_JOIN_INNER_TD_8601458_output, Table &tbl_Aggregate_TD_7493319_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(wr_returning_customer_sk#838, ca_state#62, wr_returning_customer_sk#838 AS ctr_customer_sk#3545, ca_state#62 AS ctr_state#3546, MakeDecimal(sum(UnscaledValue(wr_return_amt#846)),17,2) AS ctr_total_return#3547)
    // Input: ListBuffer(wr_returning_customer_sk#838, wr_return_amt#846, ca_state#62)
    // Output: ListBuffer(ctr_customer_sk#3545, ctr_state#3546, ctr_total_return#3547)
    std::unordered_map<SW_Aggregate_TD_7493319_key, SW_Aggregate_TD_7493319_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_8601458_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _wr_returning_customer_sk838 = tbl_JOIN_INNER_TD_8601458_output.getInt32(i, 0);
        int64_t _wr_return_amt846 = tbl_JOIN_INNER_TD_8601458_output.getInt64(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _ca_state62 = tbl_JOIN_INNER_TD_8601458_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        SW_Aggregate_TD_7493319_key k{_wr_returning_customer_sk838, std::string(_ca_state62.data())};
        int32_t _ctr_customer_sk3545 = _wr_returning_customer_sk838;
        std::array<char, TPCDS_READ_MAX + 1> _ctr_state3546 = _ca_state62;
        int64_t _ctr_total_return3547_sum_0 = _wr_return_amt846;
        SW_Aggregate_TD_7493319_payload p{_ctr_customer_sk3545, std::string(_ctr_state3546.data()), _ctr_total_return3547_sum_0};
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
        // _wr_returning_customer_sk838 not required in the output table
        // _ca_state62 not required in the output table
        tbl_Aggregate_TD_7493319_output.setInt32(r, 0, (it.second)._ctr_customer_sk3545);
        std::array<char, TPCDS_READ_MAX + 1> _ctr_state3546_n{};
        memcpy(_ctr_state3546_n.data(), (it.second)._ctr_state3546.data(), (it.second)._ctr_state3546.length());
        tbl_Aggregate_TD_7493319_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ctr_state3546_n);
        int64_t _ctr_total_return3547 = (it.second)._ctr_total_return3547_sum_0;
        tbl_Aggregate_TD_7493319_output.setInt64(r, 2, _ctr_total_return3547);
        ++r;
    }
    tbl_Aggregate_TD_7493319_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_7493319_output #Row: " << tbl_Aggregate_TD_7493319_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6751120(Table &tbl_Aggregate_TD_7575826_output, Table &tbl_Filter_TD_6751120_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull((avg(ctr_total_return) * 1.2)#3563))
    // Input: ListBuffer((avg(ctr_total_return) * 1.2)#3563, ctr_state#3546#3697)
    // Output: ListBuffer((avg(ctr_total_return) * 1.2)#3563, ctr_state#3546#3697)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_7575826_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _123563 = tbl_Aggregate_TD_7575826_output.getInt64(i, 0);
        if (_123563!= 0) {
            int64_t _123563_t = tbl_Aggregate_TD_7575826_output.getInt64(i, 0);
            tbl_Filter_TD_6751120_output.setInt64(r, 0, _123563_t);
            std::array<char, TPCDS_READ_MAX + 1> _ctr_state35463697_t = tbl_Aggregate_TD_7575826_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_6751120_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ctr_state35463697_t);
            r++;
        }
    }
    tbl_Filter_TD_6751120_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6751120_output #Row: " << tbl_Filter_TD_6751120_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6966344(Table &tbl_Aggregate_TD_7493319_output, Table &tbl_Filter_TD_6966344_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ctr_total_return#3547))
    // Input: ListBuffer(ctr_customer_sk#3545, ctr_state#3546, ctr_total_return#3547)
    // Output: ListBuffer(ctr_customer_sk#3545, ctr_state#3546, ctr_total_return#3547)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_7493319_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ctr_total_return3547 = tbl_Aggregate_TD_7493319_output.getInt64(i, 2);
        if (_ctr_total_return3547!= 0) {
            int32_t _ctr_customer_sk3545_t = tbl_Aggregate_TD_7493319_output.getInt32(i, 0);
            tbl_Filter_TD_6966344_output.setInt32(r, 0, _ctr_customer_sk3545_t);
            std::array<char, TPCDS_READ_MAX + 1> _ctr_state3546_t = tbl_Aggregate_TD_7493319_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_6966344_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ctr_state3546_t);
            int64_t _ctr_total_return3547_t = tbl_Aggregate_TD_7493319_output.getInt64(i, 2);
            tbl_Filter_TD_6966344_output.setInt64(r, 2, _ctr_total_return3547_t);
            r++;
        }
    }
    tbl_Filter_TD_6966344_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6966344_output #Row: " << tbl_Filter_TD_6966344_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5834503(Table &tbl_SerializeFromObject_TD_6271956_input, Table &tbl_Filter_TD_5834503_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(c_customer_sk#0) AND isnotnull(c_current_addr_sk#4)))
    // Input: ListBuffer(c_customer_sk#0, c_customer_id#1, c_current_addr_sk#4, c_salutation#7, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_day#11, c_birth_month#12, c_birth_year#13, c_birth_country#14, c_login#15, c_email_address#16, c_last_review_date#17)
    // Output: ListBuffer(c_customer_sk#0, c_customer_id#1, c_current_addr_sk#4, c_salutation#7, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_day#11, c_birth_month#12, c_birth_year#13, c_birth_country#14, c_login#15, c_email_address#16, c_last_review_date#17)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6271956_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk0 = tbl_SerializeFromObject_TD_6271956_input.getInt32(i, 0);
        int32_t _c_current_addr_sk4 = tbl_SerializeFromObject_TD_6271956_input.getInt32(i, 2);
        if ((_c_customer_sk0!= 0) && (_c_current_addr_sk4!= 0)) {
            int32_t _c_customer_sk0_t = tbl_SerializeFromObject_TD_6271956_input.getInt32(i, 0);
            tbl_Filter_TD_5834503_output.setInt32(r, 0, _c_customer_sk0_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_t = tbl_SerializeFromObject_TD_6271956_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_5834503_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_customer_id1_t);
            int32_t _c_current_addr_sk4_t = tbl_SerializeFromObject_TD_6271956_input.getInt32(i, 2);
            tbl_Filter_TD_5834503_output.setInt32(r, 2, _c_current_addr_sk4_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_salutation7_t = tbl_SerializeFromObject_TD_6271956_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_5834503_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_salutation7_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_t = tbl_SerializeFromObject_TD_6271956_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            tbl_Filter_TD_5834503_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_first_name8_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_t = tbl_SerializeFromObject_TD_6271956_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            tbl_Filter_TD_5834503_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_last_name9_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_t = tbl_SerializeFromObject_TD_6271956_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            tbl_Filter_TD_5834503_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_preferred_cust_flag10_t);
            int32_t _c_birth_day11_t = tbl_SerializeFromObject_TD_6271956_input.getInt32(i, 7);
            tbl_Filter_TD_5834503_output.setInt32(r, 7, _c_birth_day11_t);
            int32_t _c_birth_month12_t = tbl_SerializeFromObject_TD_6271956_input.getInt32(i, 8);
            tbl_Filter_TD_5834503_output.setInt32(r, 8, _c_birth_month12_t);
            int32_t _c_birth_year13_t = tbl_SerializeFromObject_TD_6271956_input.getInt32(i, 9);
            tbl_Filter_TD_5834503_output.setInt32(r, 9, _c_birth_year13_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country14_t = tbl_SerializeFromObject_TD_6271956_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            tbl_Filter_TD_5834503_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _c_birth_country14_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_login15_t = tbl_SerializeFromObject_TD_6271956_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
            tbl_Filter_TD_5834503_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _c_login15_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address16_t = tbl_SerializeFromObject_TD_6271956_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 12);
            tbl_Filter_TD_5834503_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _c_email_address16_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_last_review_date17_t = tbl_SerializeFromObject_TD_6271956_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 13);
            tbl_Filter_TD_5834503_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 13, _c_last_review_date17_t);
            r++;
        }
    }
    tbl_Filter_TD_5834503_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5834503_output #Row: " << tbl_Filter_TD_5834503_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5149717_key_leftMajor {
    std::string _ctr_state3546;
    bool operator==(const SW_JOIN_INNER_TD_5149717_key_leftMajor& other) const {
        return ((_ctr_state3546 == other._ctr_state3546));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5149717_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5149717_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._ctr_state3546));
    }
};
}
struct SW_JOIN_INNER_TD_5149717_payload_leftMajor {
    int32_t _ctr_customer_sk3545;
    std::string _ctr_state3546;
    int64_t _ctr_total_return3547;
};
struct SW_JOIN_INNER_TD_5149717_key_rightMajor {
    std::string _ctr_state35463697;
    bool operator==(const SW_JOIN_INNER_TD_5149717_key_rightMajor& other) const {
        return ((_ctr_state35463697 == other._ctr_state35463697));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5149717_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5149717_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._ctr_state35463697));
    }
};
}
struct SW_JOIN_INNER_TD_5149717_payload_rightMajor {
    int64_t _123563;
    std::string _ctr_state35463697;
};
void SW_JOIN_INNER_TD_5149717(Table &tbl_Filter_TD_6966344_output, Table &tbl_Filter_TD_6751120_output, Table &tbl_JOIN_INNER_TD_5149717_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((cast(ctr_total_return#3547 as decimal(24,7)) > (avg(ctr_total_return) * 1.2)#3563) AND (ctr_state#3546 = ctr_state#3546#3697)))
    // Left Table: ListBuffer(ctr_customer_sk#3545, ctr_state#3546, ctr_total_return#3547)
    // Right Table: ListBuffer((avg(ctr_total_return) * 1.2)#3563, ctr_state#3546#3697)
    // Output Table: ListBuffer(ctr_customer_sk#3545, ctr_total_return#3547)
    int left_nrow = tbl_Filter_TD_6966344_output.getNumRow();
    int right_nrow = tbl_Filter_TD_6751120_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5149717_key_leftMajor, SW_JOIN_INNER_TD_5149717_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_6966344_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ctr_state3546_k_n = tbl_Filter_TD_6966344_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ctr_state3546_k = std::string(_ctr_state3546_k_n.data());
            SW_JOIN_INNER_TD_5149717_key_leftMajor keyA{_ctr_state3546_k};
            int32_t _ctr_customer_sk3545 = tbl_Filter_TD_6966344_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ctr_state3546_n = tbl_Filter_TD_6966344_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ctr_state3546 = std::string(_ctr_state3546_n.data());
            int64_t _ctr_total_return3547 = tbl_Filter_TD_6966344_output.getInt64(i, 2);
            SW_JOIN_INNER_TD_5149717_payload_leftMajor payloadA{_ctr_customer_sk3545, _ctr_state3546, _ctr_total_return3547};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6751120_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ctr_state35463697_k_n = tbl_Filter_TD_6751120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ctr_state35463697_k = std::string(_ctr_state35463697_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5149717_key_leftMajor{_ctr_state35463697_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ctr_customer_sk3545 = (it->second)._ctr_customer_sk3545;
                std::string _ctr_state3546 = (it->second)._ctr_state3546;
                std::array<char, TPCDS_READ_MAX + 1> _ctr_state3546_n{};
                memcpy(_ctr_state3546_n.data(), (_ctr_state3546).data(), (_ctr_state3546).length());
                int64_t _ctr_total_return3547 = (it->second)._ctr_total_return3547;
                int64_t _123563 = tbl_Filter_TD_6751120_output.getInt64(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ctr_state35463697_n = tbl_Filter_TD_6751120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ctr_state35463697 = std::string(_ctr_state35463697_n.data());
                tbl_JOIN_INNER_TD_5149717_output.setInt32(r, 0, _ctr_customer_sk3545);
                tbl_JOIN_INNER_TD_5149717_output.setInt64(r, 1, _ctr_total_return3547);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5149717_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5149717_key_rightMajor, SW_JOIN_INNER_TD_5149717_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_6751120_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ctr_state35463697_k_n = tbl_Filter_TD_6751120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ctr_state35463697_k = std::string(_ctr_state35463697_k_n.data());
            SW_JOIN_INNER_TD_5149717_key_rightMajor keyA{_ctr_state35463697_k};
            int64_t _123563 = tbl_Filter_TD_6751120_output.getInt64(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ctr_state35463697_n = tbl_Filter_TD_6751120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ctr_state35463697 = std::string(_ctr_state35463697_n.data());
            SW_JOIN_INNER_TD_5149717_payload_rightMajor payloadA{_123563, _ctr_state35463697};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6966344_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ctr_state3546_k_n = tbl_Filter_TD_6966344_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ctr_state3546_k = std::string(_ctr_state3546_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5149717_key_rightMajor{_ctr_state3546_k});
            auto it = its.first;
            while (it != its.second) {
                int64_t _123563 = (it->second)._123563;
                std::string _ctr_state35463697 = (it->second)._ctr_state35463697;
                std::array<char, TPCDS_READ_MAX + 1> _ctr_state35463697_n{};
                memcpy(_ctr_state35463697_n.data(), (_ctr_state35463697).data(), (_ctr_state35463697).length());
                int32_t _ctr_customer_sk3545 = tbl_Filter_TD_6966344_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ctr_state3546_n = tbl_Filter_TD_6966344_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ctr_state3546 = std::string(_ctr_state3546_n.data());
                int64_t _ctr_total_return3547 = tbl_Filter_TD_6966344_output.getInt64(i, 2);
                tbl_JOIN_INNER_TD_5149717_output.setInt32(r, 0, _ctr_customer_sk3545);
                tbl_JOIN_INNER_TD_5149717_output.setInt64(r, 1, _ctr_total_return3547);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5149717_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5149717_output #Row: " << tbl_JOIN_INNER_TD_5149717_output.getNumRow() << std::endl;
}

void SW_Filter_TD_4514666(Table &tbl_SerializeFromObject_TD_5865613_input, Table &tbl_Filter_TD_4514666_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ca_state#3556) AND (ca_state#3556 = GA)) AND isnotnull(ca_address_sk#3548)))
    // Input: ListBuffer(ca_address_sk#3548, ca_state#3556)
    // Output: ListBuffer(ca_address_sk#3548)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5865613_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_state3556 = tbl_SerializeFromObject_TD_5865613_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _ca_address_sk3548 = tbl_SerializeFromObject_TD_5865613_input.getInt32(i, 0);
        if ((_ca_state3556.data() != "NULL" && (std::string(_ca_state3556.data()) == "GA")) && (_ca_address_sk3548!= 0)) {
            int32_t _ca_address_sk3548_t = tbl_SerializeFromObject_TD_5865613_input.getInt32(i, 0);
            tbl_Filter_TD_4514666_output.setInt32(r, 0, _ca_address_sk3548_t);
            r++;
        }
    }
    tbl_Filter_TD_4514666_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4514666_output #Row: " << tbl_Filter_TD_4514666_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4971542_key_leftMajor {
    int32_t _ctr_customer_sk3545;
    bool operator==(const SW_JOIN_INNER_TD_4971542_key_leftMajor& other) const {
        return ((_ctr_customer_sk3545 == other._ctr_customer_sk3545));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4971542_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4971542_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ctr_customer_sk3545));
    }
};
}
struct SW_JOIN_INNER_TD_4971542_payload_leftMajor {
    int32_t _ctr_customer_sk3545;
    int64_t _ctr_total_return3547;
};
struct SW_JOIN_INNER_TD_4971542_key_rightMajor {
    int32_t _c_customer_sk0;
    bool operator==(const SW_JOIN_INNER_TD_4971542_key_rightMajor& other) const {
        return ((_c_customer_sk0 == other._c_customer_sk0));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4971542_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4971542_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk0));
    }
};
}
struct SW_JOIN_INNER_TD_4971542_payload_rightMajor {
    int32_t _c_customer_sk0;
    std::string _c_customer_id1;
    int32_t _c_current_addr_sk4;
    std::string _c_salutation7;
    std::string _c_first_name8;
    std::string _c_last_name9;
    std::string _c_preferred_cust_flag10;
    int32_t _c_birth_day11;
    int32_t _c_birth_month12;
    int32_t _c_birth_year13;
    std::string _c_birth_country14;
    std::string _c_login15;
    std::string _c_email_address16;
    std::string _c_last_review_date17;
};
void SW_JOIN_INNER_TD_4971542(Table &tbl_JOIN_INNER_TD_5149717_output, Table &tbl_Filter_TD_5834503_output, Table &tbl_JOIN_INNER_TD_4971542_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ctr_customer_sk#3545 = c_customer_sk#0))
    // Left Table: ListBuffer(ctr_customer_sk#3545, ctr_total_return#3547)
    // Right Table: ListBuffer(c_customer_sk#0, c_customer_id#1, c_current_addr_sk#4, c_salutation#7, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_day#11, c_birth_month#12, c_birth_year#13, c_birth_country#14, c_login#15, c_email_address#16, c_last_review_date#17)
    // Output Table: ListBuffer(ctr_total_return#3547, c_customer_id#1, c_current_addr_sk#4, c_salutation#7, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_day#11, c_birth_month#12, c_birth_year#13, c_birth_country#14, c_login#15, c_email_address#16, c_last_review_date#17)
    int left_nrow = tbl_JOIN_INNER_TD_5149717_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5834503_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4971542_key_leftMajor, SW_JOIN_INNER_TD_4971542_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_5149717_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ctr_customer_sk3545_k = tbl_JOIN_INNER_TD_5149717_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4971542_key_leftMajor keyA{_ctr_customer_sk3545_k};
            int32_t _ctr_customer_sk3545 = tbl_JOIN_INNER_TD_5149717_output.getInt32(i, 0);
            int64_t _ctr_total_return3547 = tbl_JOIN_INNER_TD_5149717_output.getInt64(i, 1);
            SW_JOIN_INNER_TD_4971542_payload_leftMajor payloadA{_ctr_customer_sk3545, _ctr_total_return3547};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5834503_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_5834503_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4971542_key_leftMajor{_c_customer_sk0_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ctr_customer_sk3545 = (it->second)._ctr_customer_sk3545;
                int64_t _ctr_total_return3547 = (it->second)._ctr_total_return3547;
                int32_t _c_customer_sk0 = tbl_Filter_TD_5834503_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n = tbl_Filter_TD_5834503_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_customer_id1 = std::string(_c_customer_id1_n.data());
                int32_t _c_current_addr_sk4 = tbl_Filter_TD_5834503_output.getInt32(i, 2);
                std::array<char, TPCDS_READ_MAX + 1> _c_salutation7_n = tbl_Filter_TD_5834503_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_salutation7 = std::string(_c_salutation7_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_Filter_TD_5834503_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_first_name8 = std::string(_c_first_name8_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_Filter_TD_5834503_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _c_last_name9 = std::string(_c_last_name9_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_n = tbl_Filter_TD_5834503_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _c_preferred_cust_flag10 = std::string(_c_preferred_cust_flag10_n.data());
                int32_t _c_birth_day11 = tbl_Filter_TD_5834503_output.getInt32(i, 7);
                int32_t _c_birth_month12 = tbl_Filter_TD_5834503_output.getInt32(i, 8);
                int32_t _c_birth_year13 = tbl_Filter_TD_5834503_output.getInt32(i, 9);
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country14_n = tbl_Filter_TD_5834503_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
                std::string _c_birth_country14 = std::string(_c_birth_country14_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_login15_n = tbl_Filter_TD_5834503_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
                std::string _c_login15 = std::string(_c_login15_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address16_n = tbl_Filter_TD_5834503_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 12);
                std::string _c_email_address16 = std::string(_c_email_address16_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_review_date17_n = tbl_Filter_TD_5834503_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 13);
                std::string _c_last_review_date17 = std::string(_c_last_review_date17_n.data());
                tbl_JOIN_INNER_TD_4971542_output.setInt64(r, 0, _ctr_total_return3547);
                tbl_JOIN_INNER_TD_4971542_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_customer_id1_n);
                tbl_JOIN_INNER_TD_4971542_output.setInt32(r, 2, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_4971542_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_salutation7_n);
                tbl_JOIN_INNER_TD_4971542_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_first_name8_n);
                tbl_JOIN_INNER_TD_4971542_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_last_name9_n);
                tbl_JOIN_INNER_TD_4971542_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_preferred_cust_flag10_n);
                tbl_JOIN_INNER_TD_4971542_output.setInt32(r, 7, _c_birth_day11);
                tbl_JOIN_INNER_TD_4971542_output.setInt32(r, 8, _c_birth_month12);
                tbl_JOIN_INNER_TD_4971542_output.setInt32(r, 9, _c_birth_year13);
                tbl_JOIN_INNER_TD_4971542_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _c_birth_country14_n);
                tbl_JOIN_INNER_TD_4971542_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _c_login15_n);
                tbl_JOIN_INNER_TD_4971542_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _c_email_address16_n);
                tbl_JOIN_INNER_TD_4971542_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 13, _c_last_review_date17_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4971542_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4971542_key_rightMajor, SW_JOIN_INNER_TD_4971542_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5834503_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_5834503_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4971542_key_rightMajor keyA{_c_customer_sk0_k};
            int32_t _c_customer_sk0 = tbl_Filter_TD_5834503_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n = tbl_Filter_TD_5834503_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_customer_id1 = std::string(_c_customer_id1_n.data());
            int32_t _c_current_addr_sk4 = tbl_Filter_TD_5834503_output.getInt32(i, 2);
            std::array<char, TPCDS_READ_MAX + 1> _c_salutation7_n = tbl_Filter_TD_5834503_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_salutation7 = std::string(_c_salutation7_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_Filter_TD_5834503_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_first_name8 = std::string(_c_first_name8_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_Filter_TD_5834503_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _c_last_name9 = std::string(_c_last_name9_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_n = tbl_Filter_TD_5834503_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _c_preferred_cust_flag10 = std::string(_c_preferred_cust_flag10_n.data());
            int32_t _c_birth_day11 = tbl_Filter_TD_5834503_output.getInt32(i, 7);
            int32_t _c_birth_month12 = tbl_Filter_TD_5834503_output.getInt32(i, 8);
            int32_t _c_birth_year13 = tbl_Filter_TD_5834503_output.getInt32(i, 9);
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country14_n = tbl_Filter_TD_5834503_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            std::string _c_birth_country14 = std::string(_c_birth_country14_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_login15_n = tbl_Filter_TD_5834503_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
            std::string _c_login15 = std::string(_c_login15_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address16_n = tbl_Filter_TD_5834503_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 12);
            std::string _c_email_address16 = std::string(_c_email_address16_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_review_date17_n = tbl_Filter_TD_5834503_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 13);
            std::string _c_last_review_date17 = std::string(_c_last_review_date17_n.data());
            SW_JOIN_INNER_TD_4971542_payload_rightMajor payloadA{_c_customer_sk0, _c_customer_id1, _c_current_addr_sk4, _c_salutation7, _c_first_name8, _c_last_name9, _c_preferred_cust_flag10, _c_birth_day11, _c_birth_month12, _c_birth_year13, _c_birth_country14, _c_login15, _c_email_address16, _c_last_review_date17};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_5149717_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ctr_customer_sk3545_k = tbl_JOIN_INNER_TD_5149717_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4971542_key_rightMajor{_ctr_customer_sk3545_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk0 = (it->second)._c_customer_sk0;
                std::string _c_customer_id1 = (it->second)._c_customer_id1;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n{};
                memcpy(_c_customer_id1_n.data(), (_c_customer_id1).data(), (_c_customer_id1).length());
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                std::string _c_salutation7 = (it->second)._c_salutation7;
                std::array<char, TPCDS_READ_MAX + 1> _c_salutation7_n{};
                memcpy(_c_salutation7_n.data(), (_c_salutation7).data(), (_c_salutation7).length());
                std::string _c_first_name8 = (it->second)._c_first_name8;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n{};
                memcpy(_c_first_name8_n.data(), (_c_first_name8).data(), (_c_first_name8).length());
                std::string _c_last_name9 = (it->second)._c_last_name9;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n{};
                memcpy(_c_last_name9_n.data(), (_c_last_name9).data(), (_c_last_name9).length());
                std::string _c_preferred_cust_flag10 = (it->second)._c_preferred_cust_flag10;
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_n{};
                memcpy(_c_preferred_cust_flag10_n.data(), (_c_preferred_cust_flag10).data(), (_c_preferred_cust_flag10).length());
                int32_t _c_birth_day11 = (it->second)._c_birth_day11;
                int32_t _c_birth_month12 = (it->second)._c_birth_month12;
                int32_t _c_birth_year13 = (it->second)._c_birth_year13;
                std::string _c_birth_country14 = (it->second)._c_birth_country14;
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country14_n{};
                memcpy(_c_birth_country14_n.data(), (_c_birth_country14).data(), (_c_birth_country14).length());
                std::string _c_login15 = (it->second)._c_login15;
                std::array<char, TPCDS_READ_MAX + 1> _c_login15_n{};
                memcpy(_c_login15_n.data(), (_c_login15).data(), (_c_login15).length());
                std::string _c_email_address16 = (it->second)._c_email_address16;
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address16_n{};
                memcpy(_c_email_address16_n.data(), (_c_email_address16).data(), (_c_email_address16).length());
                std::string _c_last_review_date17 = (it->second)._c_last_review_date17;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_review_date17_n{};
                memcpy(_c_last_review_date17_n.data(), (_c_last_review_date17).data(), (_c_last_review_date17).length());
                int32_t _ctr_customer_sk3545 = tbl_JOIN_INNER_TD_5149717_output.getInt32(i, 0);
                int64_t _ctr_total_return3547 = tbl_JOIN_INNER_TD_5149717_output.getInt64(i, 1);
                tbl_JOIN_INNER_TD_4971542_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_customer_id1_n);
                tbl_JOIN_INNER_TD_4971542_output.setInt32(r, 2, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_4971542_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_salutation7_n);
                tbl_JOIN_INNER_TD_4971542_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_first_name8_n);
                tbl_JOIN_INNER_TD_4971542_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_last_name9_n);
                tbl_JOIN_INNER_TD_4971542_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_preferred_cust_flag10_n);
                tbl_JOIN_INNER_TD_4971542_output.setInt32(r, 7, _c_birth_day11);
                tbl_JOIN_INNER_TD_4971542_output.setInt32(r, 8, _c_birth_month12);
                tbl_JOIN_INNER_TD_4971542_output.setInt32(r, 9, _c_birth_year13);
                tbl_JOIN_INNER_TD_4971542_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _c_birth_country14_n);
                tbl_JOIN_INNER_TD_4971542_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _c_login15_n);
                tbl_JOIN_INNER_TD_4971542_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _c_email_address16_n);
                tbl_JOIN_INNER_TD_4971542_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 13, _c_last_review_date17_n);
                tbl_JOIN_INNER_TD_4971542_output.setInt64(r, 0, _ctr_total_return3547);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4971542_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4971542_output #Row: " << tbl_JOIN_INNER_TD_4971542_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_3343747_key_leftMajor {
    int32_t _c_current_addr_sk4;
    bool operator==(const SW_JOIN_INNER_TD_3343747_key_leftMajor& other) const {
        return ((_c_current_addr_sk4 == other._c_current_addr_sk4));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3343747_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3343747_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_current_addr_sk4));
    }
};
}
struct SW_JOIN_INNER_TD_3343747_payload_leftMajor {
    int64_t _ctr_total_return3547;
    std::string _c_customer_id1;
    int32_t _c_current_addr_sk4;
    std::string _c_salutation7;
    std::string _c_first_name8;
    std::string _c_last_name9;
    std::string _c_preferred_cust_flag10;
    int32_t _c_birth_day11;
    int32_t _c_birth_month12;
    int32_t _c_birth_year13;
    std::string _c_birth_country14;
    std::string _c_login15;
    std::string _c_email_address16;
    std::string _c_last_review_date17;
};
struct SW_JOIN_INNER_TD_3343747_key_rightMajor {
    int32_t _ca_address_sk3548;
    bool operator==(const SW_JOIN_INNER_TD_3343747_key_rightMajor& other) const {
        return ((_ca_address_sk3548 == other._ca_address_sk3548));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3343747_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3343747_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk3548));
    }
};
}
struct SW_JOIN_INNER_TD_3343747_payload_rightMajor {
    int32_t _ca_address_sk3548;
};
void SW_JOIN_INNER_TD_3343747(Table &tbl_JOIN_INNER_TD_4971542_output, Table &tbl_Filter_TD_4514666_output, Table &tbl_JOIN_INNER_TD_3343747_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ca_address_sk#3548 = c_current_addr_sk#4))
    // Left Table: ListBuffer(ctr_total_return#3547, c_customer_id#1, c_current_addr_sk#4, c_salutation#7, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_day#11, c_birth_month#12, c_birth_year#13, c_birth_country#14, c_login#15, c_email_address#16, c_last_review_date#17)
    // Right Table: ListBuffer(ca_address_sk#3548)
    // Output Table: ListBuffer(c_customer_id#1, c_salutation#7, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_day#11, c_birth_month#12, c_birth_year#13, c_birth_country#14, c_login#15, c_email_address#16, c_last_review_date#17, ctr_total_return#3547)
    int left_nrow = tbl_JOIN_INNER_TD_4971542_output.getNumRow();
    int right_nrow = tbl_Filter_TD_4514666_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3343747_key_leftMajor, SW_JOIN_INNER_TD_3343747_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_4971542_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_current_addr_sk4_k = tbl_JOIN_INNER_TD_4971542_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_3343747_key_leftMajor keyA{_c_current_addr_sk4_k};
            int64_t _ctr_total_return3547 = tbl_JOIN_INNER_TD_4971542_output.getInt64(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n = tbl_JOIN_INNER_TD_4971542_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_customer_id1 = std::string(_c_customer_id1_n.data());
            int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_4971542_output.getInt32(i, 2);
            std::array<char, TPCDS_READ_MAX + 1> _c_salutation7_n = tbl_JOIN_INNER_TD_4971542_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_salutation7 = std::string(_c_salutation7_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_JOIN_INNER_TD_4971542_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_first_name8 = std::string(_c_first_name8_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_JOIN_INNER_TD_4971542_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _c_last_name9 = std::string(_c_last_name9_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_n = tbl_JOIN_INNER_TD_4971542_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _c_preferred_cust_flag10 = std::string(_c_preferred_cust_flag10_n.data());
            int32_t _c_birth_day11 = tbl_JOIN_INNER_TD_4971542_output.getInt32(i, 7);
            int32_t _c_birth_month12 = tbl_JOIN_INNER_TD_4971542_output.getInt32(i, 8);
            int32_t _c_birth_year13 = tbl_JOIN_INNER_TD_4971542_output.getInt32(i, 9);
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country14_n = tbl_JOIN_INNER_TD_4971542_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            std::string _c_birth_country14 = std::string(_c_birth_country14_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_login15_n = tbl_JOIN_INNER_TD_4971542_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
            std::string _c_login15 = std::string(_c_login15_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address16_n = tbl_JOIN_INNER_TD_4971542_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 12);
            std::string _c_email_address16 = std::string(_c_email_address16_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_review_date17_n = tbl_JOIN_INNER_TD_4971542_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 13);
            std::string _c_last_review_date17 = std::string(_c_last_review_date17_n.data());
            SW_JOIN_INNER_TD_3343747_payload_leftMajor payloadA{_ctr_total_return3547, _c_customer_id1, _c_current_addr_sk4, _c_salutation7, _c_first_name8, _c_last_name9, _c_preferred_cust_flag10, _c_birth_day11, _c_birth_month12, _c_birth_year13, _c_birth_country14, _c_login15, _c_email_address16, _c_last_review_date17};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_4514666_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk3548_k = tbl_Filter_TD_4514666_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3343747_key_leftMajor{_ca_address_sk3548_k});
            auto it = its.first;
            while (it != its.second) {
                int64_t _ctr_total_return3547 = (it->second)._ctr_total_return3547;
                std::string _c_customer_id1 = (it->second)._c_customer_id1;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n{};
                memcpy(_c_customer_id1_n.data(), (_c_customer_id1).data(), (_c_customer_id1).length());
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                std::string _c_salutation7 = (it->second)._c_salutation7;
                std::array<char, TPCDS_READ_MAX + 1> _c_salutation7_n{};
                memcpy(_c_salutation7_n.data(), (_c_salutation7).data(), (_c_salutation7).length());
                std::string _c_first_name8 = (it->second)._c_first_name8;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n{};
                memcpy(_c_first_name8_n.data(), (_c_first_name8).data(), (_c_first_name8).length());
                std::string _c_last_name9 = (it->second)._c_last_name9;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n{};
                memcpy(_c_last_name9_n.data(), (_c_last_name9).data(), (_c_last_name9).length());
                std::string _c_preferred_cust_flag10 = (it->second)._c_preferred_cust_flag10;
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_n{};
                memcpy(_c_preferred_cust_flag10_n.data(), (_c_preferred_cust_flag10).data(), (_c_preferred_cust_flag10).length());
                int32_t _c_birth_day11 = (it->second)._c_birth_day11;
                int32_t _c_birth_month12 = (it->second)._c_birth_month12;
                int32_t _c_birth_year13 = (it->second)._c_birth_year13;
                std::string _c_birth_country14 = (it->second)._c_birth_country14;
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country14_n{};
                memcpy(_c_birth_country14_n.data(), (_c_birth_country14).data(), (_c_birth_country14).length());
                std::string _c_login15 = (it->second)._c_login15;
                std::array<char, TPCDS_READ_MAX + 1> _c_login15_n{};
                memcpy(_c_login15_n.data(), (_c_login15).data(), (_c_login15).length());
                std::string _c_email_address16 = (it->second)._c_email_address16;
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address16_n{};
                memcpy(_c_email_address16_n.data(), (_c_email_address16).data(), (_c_email_address16).length());
                std::string _c_last_review_date17 = (it->second)._c_last_review_date17;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_review_date17_n{};
                memcpy(_c_last_review_date17_n.data(), (_c_last_review_date17).data(), (_c_last_review_date17).length());
                int32_t _ca_address_sk3548 = tbl_Filter_TD_4514666_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_3343747_output.setInt64(r, 12, _ctr_total_return3547);
                tbl_JOIN_INNER_TD_3343747_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id1_n);
                tbl_JOIN_INNER_TD_3343747_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_salutation7_n);
                tbl_JOIN_INNER_TD_3343747_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name8_n);
                tbl_JOIN_INNER_TD_3343747_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name9_n);
                tbl_JOIN_INNER_TD_3343747_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_preferred_cust_flag10_n);
                tbl_JOIN_INNER_TD_3343747_output.setInt32(r, 5, _c_birth_day11);
                tbl_JOIN_INNER_TD_3343747_output.setInt32(r, 6, _c_birth_month12);
                tbl_JOIN_INNER_TD_3343747_output.setInt32(r, 7, _c_birth_year13);
                tbl_JOIN_INNER_TD_3343747_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _c_birth_country14_n);
                tbl_JOIN_INNER_TD_3343747_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _c_login15_n);
                tbl_JOIN_INNER_TD_3343747_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _c_email_address16_n);
                tbl_JOIN_INNER_TD_3343747_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _c_last_review_date17_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3343747_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3343747_key_rightMajor, SW_JOIN_INNER_TD_3343747_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_4514666_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk3548_k = tbl_Filter_TD_4514666_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3343747_key_rightMajor keyA{_ca_address_sk3548_k};
            int32_t _ca_address_sk3548 = tbl_Filter_TD_4514666_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3343747_payload_rightMajor payloadA{_ca_address_sk3548};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_4971542_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_current_addr_sk4_k = tbl_JOIN_INNER_TD_4971542_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3343747_key_rightMajor{_c_current_addr_sk4_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk3548 = (it->second)._ca_address_sk3548;
                int64_t _ctr_total_return3547 = tbl_JOIN_INNER_TD_4971542_output.getInt64(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n = tbl_JOIN_INNER_TD_4971542_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_customer_id1 = std::string(_c_customer_id1_n.data());
                int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_4971542_output.getInt32(i, 2);
                std::array<char, TPCDS_READ_MAX + 1> _c_salutation7_n = tbl_JOIN_INNER_TD_4971542_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_salutation7 = std::string(_c_salutation7_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_JOIN_INNER_TD_4971542_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_first_name8 = std::string(_c_first_name8_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_JOIN_INNER_TD_4971542_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _c_last_name9 = std::string(_c_last_name9_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_n = tbl_JOIN_INNER_TD_4971542_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _c_preferred_cust_flag10 = std::string(_c_preferred_cust_flag10_n.data());
                int32_t _c_birth_day11 = tbl_JOIN_INNER_TD_4971542_output.getInt32(i, 7);
                int32_t _c_birth_month12 = tbl_JOIN_INNER_TD_4971542_output.getInt32(i, 8);
                int32_t _c_birth_year13 = tbl_JOIN_INNER_TD_4971542_output.getInt32(i, 9);
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country14_n = tbl_JOIN_INNER_TD_4971542_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
                std::string _c_birth_country14 = std::string(_c_birth_country14_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_login15_n = tbl_JOIN_INNER_TD_4971542_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
                std::string _c_login15 = std::string(_c_login15_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address16_n = tbl_JOIN_INNER_TD_4971542_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 12);
                std::string _c_email_address16 = std::string(_c_email_address16_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_review_date17_n = tbl_JOIN_INNER_TD_4971542_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 13);
                std::string _c_last_review_date17 = std::string(_c_last_review_date17_n.data());
                tbl_JOIN_INNER_TD_3343747_output.setInt64(r, 12, _ctr_total_return3547);
                tbl_JOIN_INNER_TD_3343747_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id1_n);
                tbl_JOIN_INNER_TD_3343747_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_salutation7_n);
                tbl_JOIN_INNER_TD_3343747_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name8_n);
                tbl_JOIN_INNER_TD_3343747_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name9_n);
                tbl_JOIN_INNER_TD_3343747_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_preferred_cust_flag10_n);
                tbl_JOIN_INNER_TD_3343747_output.setInt32(r, 5, _c_birth_day11);
                tbl_JOIN_INNER_TD_3343747_output.setInt32(r, 6, _c_birth_month12);
                tbl_JOIN_INNER_TD_3343747_output.setInt32(r, 7, _c_birth_year13);
                tbl_JOIN_INNER_TD_3343747_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _c_birth_country14_n);
                tbl_JOIN_INNER_TD_3343747_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _c_login15_n);
                tbl_JOIN_INNER_TD_3343747_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _c_email_address16_n);
                tbl_JOIN_INNER_TD_3343747_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _c_last_review_date17_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3343747_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_3343747_output #Row: " << tbl_JOIN_INNER_TD_3343747_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2173178(Table &tbl_JOIN_INNER_TD_3343747_output, Table &tbl_Sort_TD_2173178_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(c_customer_id#1 ASC NULLS FIRST, c_salutation#7 ASC NULLS FIRST, c_first_name#8 ASC NULLS FIRST, c_last_name#9 ASC NULLS FIRST, c_preferred_cust_flag#10 ASC NULLS FIRST, c_birth_day#11 ASC NULLS FIRST, c_birth_month#12 ASC NULLS FIRST, c_birth_year#13 ASC NULLS FIRST, c_birth_country#14 ASC NULLS FIRST, c_login#15 ASC NULLS FIRST, c_email_address#16 ASC NULLS FIRST, c_last_review_date#17 ASC NULLS FIRST, ctr_total_return#3547 ASC NULLS FIRST)
    // Input: ListBuffer(c_customer_id#1, c_salutation#7, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_day#11, c_birth_month#12, c_birth_year#13, c_birth_country#14, c_login#15, c_email_address#16, c_last_review_date#17, ctr_total_return#3547)
    // Output: ListBuffer(c_customer_id#1, c_salutation#7, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_day#11, c_birth_month#12, c_birth_year#13, c_birth_country#14, c_login#15, c_email_address#16, c_last_review_date#17, ctr_total_return#3547)
    struct SW_Sort_TD_2173178Row {
        std::string _c_customer_id1;
        std::string _c_salutation7;
        std::string _c_first_name8;
        std::string _c_last_name9;
        std::string _c_preferred_cust_flag10;
        int32_t _c_birth_day11;
        int32_t _c_birth_month12;
        int32_t _c_birth_year13;
        std::string _c_birth_country14;
        std::string _c_login15;
        std::string _c_email_address16;
        std::string _c_last_review_date17;
        int64_t _ctr_total_return3547;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2173178Row& a, const SW_Sort_TD_2173178Row& b) const { return 
 (a._c_customer_id1 < b._c_customer_id1) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 < b._c_salutation7)) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 == b._c_salutation7) && (a._c_first_name8 < b._c_first_name8)) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 == b._c_salutation7) && (a._c_first_name8 == b._c_first_name8) && (a._c_last_name9 < b._c_last_name9)) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 == b._c_salutation7) && (a._c_first_name8 == b._c_first_name8) && (a._c_last_name9 == b._c_last_name9) && (a._c_preferred_cust_flag10 < b._c_preferred_cust_flag10)) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 == b._c_salutation7) && (a._c_first_name8 == b._c_first_name8) && (a._c_last_name9 == b._c_last_name9) && (a._c_preferred_cust_flag10 == b._c_preferred_cust_flag10) && (a._c_birth_day11 < b._c_birth_day11)) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 == b._c_salutation7) && (a._c_first_name8 == b._c_first_name8) && (a._c_last_name9 == b._c_last_name9) && (a._c_preferred_cust_flag10 == b._c_preferred_cust_flag10) && (a._c_birth_day11 == b._c_birth_day11) && (a._c_birth_month12 < b._c_birth_month12)) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 == b._c_salutation7) && (a._c_first_name8 == b._c_first_name8) && (a._c_last_name9 == b._c_last_name9) && (a._c_preferred_cust_flag10 == b._c_preferred_cust_flag10) && (a._c_birth_day11 == b._c_birth_day11) && (a._c_birth_month12 == b._c_birth_month12) && (a._c_birth_year13 < b._c_birth_year13)) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 == b._c_salutation7) && (a._c_first_name8 == b._c_first_name8) && (a._c_last_name9 == b._c_last_name9) && (a._c_preferred_cust_flag10 == b._c_preferred_cust_flag10) && (a._c_birth_day11 == b._c_birth_day11) && (a._c_birth_month12 == b._c_birth_month12) && (a._c_birth_year13 == b._c_birth_year13) && (a._c_birth_country14 < b._c_birth_country14)) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 == b._c_salutation7) && (a._c_first_name8 == b._c_first_name8) && (a._c_last_name9 == b._c_last_name9) && (a._c_preferred_cust_flag10 == b._c_preferred_cust_flag10) && (a._c_birth_day11 == b._c_birth_day11) && (a._c_birth_month12 == b._c_birth_month12) && (a._c_birth_year13 == b._c_birth_year13) && (a._c_birth_country14 == b._c_birth_country14) && (a._c_login15 < b._c_login15)) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 == b._c_salutation7) && (a._c_first_name8 == b._c_first_name8) && (a._c_last_name9 == b._c_last_name9) && (a._c_preferred_cust_flag10 == b._c_preferred_cust_flag10) && (a._c_birth_day11 == b._c_birth_day11) && (a._c_birth_month12 == b._c_birth_month12) && (a._c_birth_year13 == b._c_birth_year13) && (a._c_birth_country14 == b._c_birth_country14) && (a._c_login15 == b._c_login15) && (a._c_email_address16 < b._c_email_address16)) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 == b._c_salutation7) && (a._c_first_name8 == b._c_first_name8) && (a._c_last_name9 == b._c_last_name9) && (a._c_preferred_cust_flag10 == b._c_preferred_cust_flag10) && (a._c_birth_day11 == b._c_birth_day11) && (a._c_birth_month12 == b._c_birth_month12) && (a._c_birth_year13 == b._c_birth_year13) && (a._c_birth_country14 == b._c_birth_country14) && (a._c_login15 == b._c_login15) && (a._c_email_address16 == b._c_email_address16) && (a._c_last_review_date17 < b._c_last_review_date17)) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 == b._c_salutation7) && (a._c_first_name8 == b._c_first_name8) && (a._c_last_name9 == b._c_last_name9) && (a._c_preferred_cust_flag10 == b._c_preferred_cust_flag10) && (a._c_birth_day11 == b._c_birth_day11) && (a._c_birth_month12 == b._c_birth_month12) && (a._c_birth_year13 == b._c_birth_year13) && (a._c_birth_country14 == b._c_birth_country14) && (a._c_login15 == b._c_login15) && (a._c_email_address16 == b._c_email_address16) && (a._c_last_review_date17 == b._c_last_review_date17) && (a._ctr_total_return3547 < b._ctr_total_return3547)); 
}
    }SW_Sort_TD_2173178_order; 

    int nrow1 = tbl_JOIN_INNER_TD_3343747_output.getNumRow();
    std::vector<SW_Sort_TD_2173178Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1 = tbl_JOIN_INNER_TD_3343747_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_salutation7 = tbl_JOIN_INNER_TD_3343747_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8 = tbl_JOIN_INNER_TD_3343747_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9 = tbl_JOIN_INNER_TD_3343747_output.getcharN<char, TPCDS_READ_MAX +1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10 = tbl_JOIN_INNER_TD_3343747_output.getcharN<char, TPCDS_READ_MAX +1>(i, 4);
        int32_t _c_birth_day11 = tbl_JOIN_INNER_TD_3343747_output.getInt32(i, 5);
        int32_t _c_birth_month12 = tbl_JOIN_INNER_TD_3343747_output.getInt32(i, 6);
        int32_t _c_birth_year13 = tbl_JOIN_INNER_TD_3343747_output.getInt32(i, 7);
        std::array<char, TPCDS_READ_MAX + 1> _c_birth_country14 = tbl_JOIN_INNER_TD_3343747_output.getcharN<char, TPCDS_READ_MAX +1>(i, 8);
        std::array<char, TPCDS_READ_MAX + 1> _c_login15 = tbl_JOIN_INNER_TD_3343747_output.getcharN<char, TPCDS_READ_MAX +1>(i, 9);
        std::array<char, TPCDS_READ_MAX + 1> _c_email_address16 = tbl_JOIN_INNER_TD_3343747_output.getcharN<char, TPCDS_READ_MAX +1>(i, 10);
        std::array<char, TPCDS_READ_MAX + 1> _c_last_review_date17 = tbl_JOIN_INNER_TD_3343747_output.getcharN<char, TPCDS_READ_MAX +1>(i, 11);
        int64_t _ctr_total_return3547 = tbl_JOIN_INNER_TD_3343747_output.getInt64(i, 12);
        SW_Sort_TD_2173178Row t = {std::string(_c_customer_id1.data()),std::string(_c_salutation7.data()),std::string(_c_first_name8.data()),std::string(_c_last_name9.data()),std::string(_c_preferred_cust_flag10.data()),_c_birth_day11,_c_birth_month12,_c_birth_year13,std::string(_c_birth_country14.data()),std::string(_c_login15.data()),std::string(_c_email_address16.data()),std::string(_c_last_review_date17.data()),_ctr_total_return3547};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2173178_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1{};
        memcpy(_c_customer_id1.data(), (it._c_customer_id1).data(), (it._c_customer_id1).length());
        tbl_Sort_TD_2173178_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _c_customer_id1);
        std::array<char, TPCDS_READ_MAX + 1> _c_salutation7{};
        memcpy(_c_salutation7.data(), (it._c_salutation7).data(), (it._c_salutation7).length());
        tbl_Sort_TD_2173178_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _c_salutation7);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8{};
        memcpy(_c_first_name8.data(), (it._c_first_name8).data(), (it._c_first_name8).length());
        tbl_Sort_TD_2173178_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _c_first_name8);
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9{};
        memcpy(_c_last_name9.data(), (it._c_last_name9).data(), (it._c_last_name9).length());
        tbl_Sort_TD_2173178_output.setcharN<char, TPCDS_READ_MAX +1>(r, 3, _c_last_name9);
        std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10{};
        memcpy(_c_preferred_cust_flag10.data(), (it._c_preferred_cust_flag10).data(), (it._c_preferred_cust_flag10).length());
        tbl_Sort_TD_2173178_output.setcharN<char, TPCDS_READ_MAX +1>(r, 4, _c_preferred_cust_flag10);
        tbl_Sort_TD_2173178_output.setInt32(r, 5, it._c_birth_day11);
        tbl_Sort_TD_2173178_output.setInt32(r, 6, it._c_birth_month12);
        tbl_Sort_TD_2173178_output.setInt32(r, 7, it._c_birth_year13);
        std::array<char, TPCDS_READ_MAX + 1> _c_birth_country14{};
        memcpy(_c_birth_country14.data(), (it._c_birth_country14).data(), (it._c_birth_country14).length());
        tbl_Sort_TD_2173178_output.setcharN<char, TPCDS_READ_MAX +1>(r, 8, _c_birth_country14);
        std::array<char, TPCDS_READ_MAX + 1> _c_login15{};
        memcpy(_c_login15.data(), (it._c_login15).data(), (it._c_login15).length());
        tbl_Sort_TD_2173178_output.setcharN<char, TPCDS_READ_MAX +1>(r, 9, _c_login15);
        std::array<char, TPCDS_READ_MAX + 1> _c_email_address16{};
        memcpy(_c_email_address16.data(), (it._c_email_address16).data(), (it._c_email_address16).length());
        tbl_Sort_TD_2173178_output.setcharN<char, TPCDS_READ_MAX +1>(r, 10, _c_email_address16);
        std::array<char, TPCDS_READ_MAX + 1> _c_last_review_date17{};
        memcpy(_c_last_review_date17.data(), (it._c_last_review_date17).data(), (it._c_last_review_date17).length());
        tbl_Sort_TD_2173178_output.setcharN<char, TPCDS_READ_MAX +1>(r, 11, _c_last_review_date17);
        tbl_Sort_TD_2173178_output.setInt64(r, 12, it._ctr_total_return3547);
        ++r;
    }
    tbl_Sort_TD_2173178_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2173178_output #Row: " << tbl_Sort_TD_2173178_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1637703(Table &tbl_Sort_TD_2173178_output, Table &tbl_LocalLimit_TD_1637703_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(c_customer_id#1, c_salutation#7, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_day#11, c_birth_month#12, c_birth_year#13, c_birth_country#14, c_login#15, c_email_address#16, c_last_review_date#17, ctr_total_return#3547)
    // Output: ListBuffer(c_customer_id#1, c_salutation#7, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_day#11, c_birth_month#12, c_birth_year#13, c_birth_country#14, c_login#15, c_email_address#16, c_last_review_date#17, ctr_total_return#3547)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n = tbl_Sort_TD_2173178_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1637703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id1_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_salutation7_n = tbl_Sort_TD_2173178_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_1637703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_salutation7_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_Sort_TD_2173178_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_LocalLimit_TD_1637703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name8_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_Sort_TD_2173178_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_LocalLimit_TD_1637703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name9_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_n = tbl_Sort_TD_2173178_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        tbl_LocalLimit_TD_1637703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_preferred_cust_flag10_n);
        tbl_LocalLimit_TD_1637703_output.setInt32(r, 5, tbl_Sort_TD_2173178_output.getInt32(i, 5));
        tbl_LocalLimit_TD_1637703_output.setInt32(r, 6, tbl_Sort_TD_2173178_output.getInt32(i, 6));
        tbl_LocalLimit_TD_1637703_output.setInt32(r, 7, tbl_Sort_TD_2173178_output.getInt32(i, 7));
        std::array<char, TPCDS_READ_MAX + 1> _c_birth_country14_n = tbl_Sort_TD_2173178_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
        tbl_LocalLimit_TD_1637703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _c_birth_country14_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_login15_n = tbl_Sort_TD_2173178_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
        tbl_LocalLimit_TD_1637703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _c_login15_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_email_address16_n = tbl_Sort_TD_2173178_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
        tbl_LocalLimit_TD_1637703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _c_email_address16_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_last_review_date17_n = tbl_Sort_TD_2173178_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
        tbl_LocalLimit_TD_1637703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _c_last_review_date17_n);
        tbl_LocalLimit_TD_1637703_output.setInt64(r, 12, tbl_Sort_TD_2173178_output.getInt64(i, 12));
        r++;
    }
    tbl_LocalLimit_TD_1637703_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1637703_output #Row: " << tbl_LocalLimit_TD_1637703_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0403706(Table &tbl_LocalLimit_TD_1637703_output, Table &tbl_GlobalLimit_TD_0403706_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(c_customer_id#1, c_salutation#7, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_day#11, c_birth_month#12, c_birth_year#13, c_birth_country#14, c_login#15, c_email_address#16, c_last_review_date#17, ctr_total_return#3547)
    // Output: ListBuffer(c_customer_id#1, c_salutation#7, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_day#11, c_birth_month#12, c_birth_year#13, c_birth_country#14, c_login#15, c_email_address#16, c_last_review_date#17, ctr_total_return#3547)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n = tbl_LocalLimit_TD_1637703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0403706_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id1_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_salutation7_n = tbl_LocalLimit_TD_1637703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_0403706_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_salutation7_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_LocalLimit_TD_1637703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_GlobalLimit_TD_0403706_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name8_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_LocalLimit_TD_1637703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_GlobalLimit_TD_0403706_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name9_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_n = tbl_LocalLimit_TD_1637703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        tbl_GlobalLimit_TD_0403706_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_preferred_cust_flag10_n);
        tbl_GlobalLimit_TD_0403706_output.setInt32(r, 5, tbl_LocalLimit_TD_1637703_output.getInt32(i, 5));
        tbl_GlobalLimit_TD_0403706_output.setInt32(r, 6, tbl_LocalLimit_TD_1637703_output.getInt32(i, 6));
        tbl_GlobalLimit_TD_0403706_output.setInt32(r, 7, tbl_LocalLimit_TD_1637703_output.getInt32(i, 7));
        std::array<char, TPCDS_READ_MAX + 1> _c_birth_country14_n = tbl_LocalLimit_TD_1637703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
        tbl_GlobalLimit_TD_0403706_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _c_birth_country14_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_login15_n = tbl_LocalLimit_TD_1637703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
        tbl_GlobalLimit_TD_0403706_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _c_login15_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_email_address16_n = tbl_LocalLimit_TD_1637703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
        tbl_GlobalLimit_TD_0403706_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _c_email_address16_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_last_review_date17_n = tbl_LocalLimit_TD_1637703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
        tbl_GlobalLimit_TD_0403706_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _c_last_review_date17_n);
        tbl_GlobalLimit_TD_0403706_output.setInt64(r, 12, tbl_LocalLimit_TD_1637703_output.getInt64(i, 12));
        r++;
    }
    tbl_GlobalLimit_TD_0403706_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0403706_output #Row: " << tbl_GlobalLimit_TD_0403706_output.getNumRow() << std::endl;
}

