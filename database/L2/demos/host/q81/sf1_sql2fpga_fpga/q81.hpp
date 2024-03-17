#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_1130081(Table &tbl_SerializeFromObject_TD_12172702_input, Table &tbl_Filter_TD_1130081_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#126) AND (d_year#126 = 2000)) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12172702_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_12172702_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_12172702_input.getInt32(i, 0);
        if (((_d_year126!= 0) && (_d_year126 == 2000)) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_12172702_input.getInt32(i, 0);
            tbl_Filter_TD_1130081_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_1130081_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1130081_output #Row: " << tbl_Filter_TD_1130081_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11864297(Table &tbl_SerializeFromObject_TD_12306076_input, Table &tbl_Filter_TD_11864297_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cr_returned_date_sk#1023) AND isnotnull(cr_returning_addr_sk#1033)))
    // Input: ListBuffer(cr_returned_date_sk#1023, cr_returning_customer_sk#1030, cr_returning_addr_sk#1033, cr_return_amt_inc_tax#1043)
    // Output: ListBuffer(cr_returned_date_sk#1023, cr_returning_customer_sk#1030, cr_returning_addr_sk#1033, cr_return_amt_inc_tax#1043)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12306076_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cr_returned_date_sk1023 = tbl_SerializeFromObject_TD_12306076_input.getInt32(i, 0);
        int32_t _cr_returning_addr_sk1033 = tbl_SerializeFromObject_TD_12306076_input.getInt32(i, 2);
        if ((_cr_returned_date_sk1023!= 0) && (_cr_returning_addr_sk1033!= 0)) {
            int32_t _cr_returned_date_sk1023_t = tbl_SerializeFromObject_TD_12306076_input.getInt32(i, 0);
            tbl_Filter_TD_11864297_output.setInt32(r, 0, _cr_returned_date_sk1023_t);
            int32_t _cr_returning_customer_sk1030_t = tbl_SerializeFromObject_TD_12306076_input.getInt32(i, 1);
            tbl_Filter_TD_11864297_output.setInt32(r, 1, _cr_returning_customer_sk1030_t);
            int32_t _cr_returning_addr_sk1033_t = tbl_SerializeFromObject_TD_12306076_input.getInt32(i, 2);
            tbl_Filter_TD_11864297_output.setInt32(r, 2, _cr_returning_addr_sk1033_t);
            int64_t _cr_return_amt_inc_tax1043_t = tbl_SerializeFromObject_TD_12306076_input.getInt64(i, 3);
            tbl_Filter_TD_11864297_output.setInt64(r, 3, _cr_return_amt_inc_tax1043_t);
            r++;
        }
    }
    tbl_Filter_TD_11864297_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11864297_output #Row: " << tbl_Filter_TD_11864297_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10834331(Table &tbl_SerializeFromObject_TD_11499528_input, Table &tbl_Filter_TD_10834331_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ca_address_sk#54) AND isnotnull(ca_state#62)))
    // Input: ListBuffer(ca_address_sk#54, ca_state#62)
    // Output: ListBuffer(ca_address_sk#54, ca_state#62)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11499528_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ca_address_sk54 = tbl_SerializeFromObject_TD_11499528_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _ca_state62 = tbl_SerializeFromObject_TD_11499528_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_ca_address_sk54!= 0) && (_ca_state62.data() != "NULL")) {
            int32_t _ca_address_sk54_t = tbl_SerializeFromObject_TD_11499528_input.getInt32(i, 0);
            tbl_Filter_TD_10834331_output.setInt32(r, 0, _ca_address_sk54_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_t = tbl_SerializeFromObject_TD_11499528_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_10834331_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_state62_t);
            r++;
        }
    }
    tbl_Filter_TD_10834331_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10834331_output #Row: " << tbl_Filter_TD_10834331_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_1014727_key_leftMajor {
    int32_t _cr_returned_date_sk1023;
    bool operator==(const SW_JOIN_INNER_TD_1014727_key_leftMajor& other) const {
        return ((_cr_returned_date_sk1023 == other._cr_returned_date_sk1023));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_1014727_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_1014727_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cr_returned_date_sk1023));
    }
};
}
struct SW_JOIN_INNER_TD_1014727_payload_leftMajor {
    int32_t _cr_returned_date_sk1023;
    int32_t _cr_returning_customer_sk1030;
    int32_t _cr_returning_addr_sk1033;
    int64_t _cr_return_amt_inc_tax1043;
};
struct SW_JOIN_INNER_TD_1014727_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_1014727_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_1014727_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_1014727_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_1014727_payload_rightMajor {
    int32_t _d_date_sk120;
};
void SW_JOIN_INNER_TD_1014727(Table &tbl_Filter_TD_11864297_output, Table &tbl_Filter_TD_1130081_output, Table &tbl_JOIN_INNER_TD_1014727_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cr_returned_date_sk#1023 = d_date_sk#120))
    // Left Table: ListBuffer(cr_returned_date_sk#1023, cr_returning_customer_sk#1030, cr_returning_addr_sk#1033, cr_return_amt_inc_tax#1043)
    // Right Table: ListBuffer(d_date_sk#120)
    // Output Table: ListBuffer(cr_returning_customer_sk#1030, cr_returning_addr_sk#1033, cr_return_amt_inc_tax#1043)
    int left_nrow = tbl_Filter_TD_11864297_output.getNumRow();
    int right_nrow = tbl_Filter_TD_1130081_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_1014727_key_leftMajor, SW_JOIN_INNER_TD_1014727_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_11864297_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cr_returned_date_sk1023_k = tbl_Filter_TD_11864297_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_1014727_key_leftMajor keyA{_cr_returned_date_sk1023_k};
            int32_t _cr_returned_date_sk1023 = tbl_Filter_TD_11864297_output.getInt32(i, 0);
            int32_t _cr_returning_customer_sk1030 = tbl_Filter_TD_11864297_output.getInt32(i, 1);
            int32_t _cr_returning_addr_sk1033 = tbl_Filter_TD_11864297_output.getInt32(i, 2);
            int64_t _cr_return_amt_inc_tax1043 = tbl_Filter_TD_11864297_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_1014727_payload_leftMajor payloadA{_cr_returned_date_sk1023, _cr_returning_customer_sk1030, _cr_returning_addr_sk1033, _cr_return_amt_inc_tax1043};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_1130081_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_1130081_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_1014727_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cr_returned_date_sk1023 = (it->second)._cr_returned_date_sk1023;
                int32_t _cr_returning_customer_sk1030 = (it->second)._cr_returning_customer_sk1030;
                int32_t _cr_returning_addr_sk1033 = (it->second)._cr_returning_addr_sk1033;
                int64_t _cr_return_amt_inc_tax1043 = (it->second)._cr_return_amt_inc_tax1043;
                int32_t _d_date_sk120 = tbl_Filter_TD_1130081_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_1014727_output.setInt32(r, 0, _cr_returning_customer_sk1030);
                tbl_JOIN_INNER_TD_1014727_output.setInt32(r, 1, _cr_returning_addr_sk1033);
                tbl_JOIN_INNER_TD_1014727_output.setInt64(r, 2, _cr_return_amt_inc_tax1043);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_1014727_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_1014727_key_rightMajor, SW_JOIN_INNER_TD_1014727_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_1130081_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_1130081_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_1014727_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_1130081_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_1014727_payload_rightMajor payloadA{_d_date_sk120};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_11864297_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cr_returned_date_sk1023_k = tbl_Filter_TD_11864297_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_1014727_key_rightMajor{_cr_returned_date_sk1023_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _cr_returned_date_sk1023 = tbl_Filter_TD_11864297_output.getInt32(i, 0);
                int32_t _cr_returning_customer_sk1030 = tbl_Filter_TD_11864297_output.getInt32(i, 1);
                int32_t _cr_returning_addr_sk1033 = tbl_Filter_TD_11864297_output.getInt32(i, 2);
                int64_t _cr_return_amt_inc_tax1043 = tbl_Filter_TD_11864297_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_1014727_output.setInt32(r, 0, _cr_returning_customer_sk1030);
                tbl_JOIN_INNER_TD_1014727_output.setInt32(r, 1, _cr_returning_addr_sk1033);
                tbl_JOIN_INNER_TD_1014727_output.setInt64(r, 2, _cr_return_amt_inc_tax1043);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_1014727_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_1014727_output #Row: " << tbl_JOIN_INNER_TD_1014727_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10141018(Table &tbl_SerializeFromObject_TD_11710837_input, Table &tbl_Filter_TD_10141018_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#126) AND (d_year#126 = 2000)) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11710837_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_11710837_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_11710837_input.getInt32(i, 0);
        if (((_d_year126!= 0) && (_d_year126 == 2000)) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_11710837_input.getInt32(i, 0);
            tbl_Filter_TD_10141018_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_10141018_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10141018_output #Row: " << tbl_Filter_TD_10141018_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10717046(Table &tbl_SerializeFromObject_TD_11857059_input, Table &tbl_Filter_TD_10717046_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(cr_returned_date_sk#1023) AND isnotnull(cr_returning_addr_sk#1033)) AND isnotnull(cr_returning_customer_sk#1030)))
    // Input: ListBuffer(cr_returned_date_sk#1023, cr_returning_customer_sk#1030, cr_returning_addr_sk#1033, cr_return_amt_inc_tax#1043)
    // Output: ListBuffer(cr_returned_date_sk#1023, cr_returning_customer_sk#1030, cr_returning_addr_sk#1033, cr_return_amt_inc_tax#1043)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11857059_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cr_returned_date_sk1023 = tbl_SerializeFromObject_TD_11857059_input.getInt32(i, 0);
        int32_t _cr_returning_addr_sk1033 = tbl_SerializeFromObject_TD_11857059_input.getInt32(i, 2);
        int32_t _cr_returning_customer_sk1030 = tbl_SerializeFromObject_TD_11857059_input.getInt32(i, 1);
        if (((_cr_returned_date_sk1023!= 0) && (_cr_returning_addr_sk1033!= 0)) && (_cr_returning_customer_sk1030!= 0)) {
            int32_t _cr_returned_date_sk1023_t = tbl_SerializeFromObject_TD_11857059_input.getInt32(i, 0);
            tbl_Filter_TD_10717046_output.setInt32(r, 0, _cr_returned_date_sk1023_t);
            int32_t _cr_returning_customer_sk1030_t = tbl_SerializeFromObject_TD_11857059_input.getInt32(i, 1);
            tbl_Filter_TD_10717046_output.setInt32(r, 1, _cr_returning_customer_sk1030_t);
            int32_t _cr_returning_addr_sk1033_t = tbl_SerializeFromObject_TD_11857059_input.getInt32(i, 2);
            tbl_Filter_TD_10717046_output.setInt32(r, 2, _cr_returning_addr_sk1033_t);
            int64_t _cr_return_amt_inc_tax1043_t = tbl_SerializeFromObject_TD_11857059_input.getInt64(i, 3);
            tbl_Filter_TD_10717046_output.setInt64(r, 3, _cr_return_amt_inc_tax1043_t);
            r++;
        }
    }
    tbl_Filter_TD_10717046_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10717046_output #Row: " << tbl_Filter_TD_10717046_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_9877513_key_leftMajor {
    int32_t _cr_returning_addr_sk1033;
    bool operator==(const SW_JOIN_INNER_TD_9877513_key_leftMajor& other) const {
        return ((_cr_returning_addr_sk1033 == other._cr_returning_addr_sk1033));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9877513_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9877513_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cr_returning_addr_sk1033));
    }
};
}
struct SW_JOIN_INNER_TD_9877513_payload_leftMajor {
    int32_t _cr_returning_customer_sk1030;
    int32_t _cr_returning_addr_sk1033;
    int64_t _cr_return_amt_inc_tax1043;
};
struct SW_JOIN_INNER_TD_9877513_key_rightMajor {
    int32_t _ca_address_sk54;
    bool operator==(const SW_JOIN_INNER_TD_9877513_key_rightMajor& other) const {
        return ((_ca_address_sk54 == other._ca_address_sk54));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9877513_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9877513_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk54));
    }
};
}
struct SW_JOIN_INNER_TD_9877513_payload_rightMajor {
    int32_t _ca_address_sk54;
    std::string _ca_state62;
};
void SW_JOIN_INNER_TD_9877513(Table &tbl_JOIN_INNER_TD_1014727_output, Table &tbl_Filter_TD_10834331_output, Table &tbl_JOIN_INNER_TD_9877513_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cr_returning_addr_sk#1033 = ca_address_sk#54))
    // Left Table: ListBuffer(cr_returning_customer_sk#1030, cr_returning_addr_sk#1033, cr_return_amt_inc_tax#1043)
    // Right Table: ListBuffer(ca_address_sk#54, ca_state#62)
    // Output Table: ListBuffer(cr_returning_customer_sk#1030, cr_return_amt_inc_tax#1043, ca_state#62)
    int left_nrow = tbl_JOIN_INNER_TD_1014727_output.getNumRow();
    int right_nrow = tbl_Filter_TD_10834331_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9877513_key_leftMajor, SW_JOIN_INNER_TD_9877513_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_1014727_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cr_returning_addr_sk1033_k = tbl_JOIN_INNER_TD_1014727_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_9877513_key_leftMajor keyA{_cr_returning_addr_sk1033_k};
            int32_t _cr_returning_customer_sk1030 = tbl_JOIN_INNER_TD_1014727_output.getInt32(i, 0);
            int32_t _cr_returning_addr_sk1033 = tbl_JOIN_INNER_TD_1014727_output.getInt32(i, 1);
            int64_t _cr_return_amt_inc_tax1043 = tbl_JOIN_INNER_TD_1014727_output.getInt64(i, 2);
            SW_JOIN_INNER_TD_9877513_payload_leftMajor payloadA{_cr_returning_customer_sk1030, _cr_returning_addr_sk1033, _cr_return_amt_inc_tax1043};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_10834331_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_10834331_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9877513_key_leftMajor{_ca_address_sk54_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cr_returning_customer_sk1030 = (it->second)._cr_returning_customer_sk1030;
                int32_t _cr_returning_addr_sk1033 = (it->second)._cr_returning_addr_sk1033;
                int64_t _cr_return_amt_inc_tax1043 = (it->second)._cr_return_amt_inc_tax1043;
                int32_t _ca_address_sk54 = tbl_Filter_TD_10834331_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_Filter_TD_10834331_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_state62 = std::string(_ca_state62_n.data());
                tbl_JOIN_INNER_TD_9877513_output.setInt32(r, 0, _cr_returning_customer_sk1030);
                tbl_JOIN_INNER_TD_9877513_output.setInt64(r, 1, _cr_return_amt_inc_tax1043);
                tbl_JOIN_INNER_TD_9877513_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_state62_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9877513_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9877513_key_rightMajor, SW_JOIN_INNER_TD_9877513_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_10834331_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_10834331_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_9877513_key_rightMajor keyA{_ca_address_sk54_k};
            int32_t _ca_address_sk54 = tbl_Filter_TD_10834331_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_Filter_TD_10834331_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_state62 = std::string(_ca_state62_n.data());
            SW_JOIN_INNER_TD_9877513_payload_rightMajor payloadA{_ca_address_sk54, _ca_state62};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_1014727_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cr_returning_addr_sk1033_k = tbl_JOIN_INNER_TD_1014727_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9877513_key_rightMajor{_cr_returning_addr_sk1033_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk54 = (it->second)._ca_address_sk54;
                std::string _ca_state62 = (it->second)._ca_state62;
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n{};
                memcpy(_ca_state62_n.data(), (_ca_state62).data(), (_ca_state62).length());
                int32_t _cr_returning_customer_sk1030 = tbl_JOIN_INNER_TD_1014727_output.getInt32(i, 0);
                int32_t _cr_returning_addr_sk1033 = tbl_JOIN_INNER_TD_1014727_output.getInt32(i, 1);
                int64_t _cr_return_amt_inc_tax1043 = tbl_JOIN_INNER_TD_1014727_output.getInt64(i, 2);
                tbl_JOIN_INNER_TD_9877513_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_state62_n);
                tbl_JOIN_INNER_TD_9877513_output.setInt32(r, 0, _cr_returning_customer_sk1030);
                tbl_JOIN_INNER_TD_9877513_output.setInt64(r, 1, _cr_return_amt_inc_tax1043);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9877513_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_9877513_output #Row: " << tbl_JOIN_INNER_TD_9877513_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9440346(Table &tbl_SerializeFromObject_TD_10698458_input, Table &tbl_Filter_TD_9440346_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ca_address_sk#54) AND isnotnull(ca_state#62)))
    // Input: ListBuffer(ca_address_sk#54, ca_state#62)
    // Output: ListBuffer(ca_address_sk#54, ca_state#62)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10698458_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ca_address_sk54 = tbl_SerializeFromObject_TD_10698458_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _ca_state62 = tbl_SerializeFromObject_TD_10698458_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_ca_address_sk54!= 0) && (_ca_state62.data() != "NULL")) {
            int32_t _ca_address_sk54_t = tbl_SerializeFromObject_TD_10698458_input.getInt32(i, 0);
            tbl_Filter_TD_9440346_output.setInt32(r, 0, _ca_address_sk54_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_t = tbl_SerializeFromObject_TD_10698458_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_9440346_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_state62_t);
            r++;
        }
    }
    tbl_Filter_TD_9440346_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9440346_output #Row: " << tbl_Filter_TD_9440346_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_934066_key_leftMajor {
    int32_t _cr_returned_date_sk1023;
    bool operator==(const SW_JOIN_INNER_TD_934066_key_leftMajor& other) const {
        return ((_cr_returned_date_sk1023 == other._cr_returned_date_sk1023));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_934066_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_934066_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cr_returned_date_sk1023));
    }
};
}
struct SW_JOIN_INNER_TD_934066_payload_leftMajor {
    int32_t _cr_returned_date_sk1023;
    int32_t _cr_returning_customer_sk1030;
    int32_t _cr_returning_addr_sk1033;
    int64_t _cr_return_amt_inc_tax1043;
};
struct SW_JOIN_INNER_TD_934066_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_934066_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_934066_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_934066_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_934066_payload_rightMajor {
    int32_t _d_date_sk120;
};
void SW_JOIN_INNER_TD_934066(Table &tbl_Filter_TD_10717046_output, Table &tbl_Filter_TD_10141018_output, Table &tbl_JOIN_INNER_TD_934066_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cr_returned_date_sk#1023 = d_date_sk#120))
    // Left Table: ListBuffer(cr_returned_date_sk#1023, cr_returning_customer_sk#1030, cr_returning_addr_sk#1033, cr_return_amt_inc_tax#1043)
    // Right Table: ListBuffer(d_date_sk#120)
    // Output Table: ListBuffer(cr_returning_customer_sk#1030, cr_returning_addr_sk#1033, cr_return_amt_inc_tax#1043)
    int left_nrow = tbl_Filter_TD_10717046_output.getNumRow();
    int right_nrow = tbl_Filter_TD_10141018_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_934066_key_leftMajor, SW_JOIN_INNER_TD_934066_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_10717046_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cr_returned_date_sk1023_k = tbl_Filter_TD_10717046_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_934066_key_leftMajor keyA{_cr_returned_date_sk1023_k};
            int32_t _cr_returned_date_sk1023 = tbl_Filter_TD_10717046_output.getInt32(i, 0);
            int32_t _cr_returning_customer_sk1030 = tbl_Filter_TD_10717046_output.getInt32(i, 1);
            int32_t _cr_returning_addr_sk1033 = tbl_Filter_TD_10717046_output.getInt32(i, 2);
            int64_t _cr_return_amt_inc_tax1043 = tbl_Filter_TD_10717046_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_934066_payload_leftMajor payloadA{_cr_returned_date_sk1023, _cr_returning_customer_sk1030, _cr_returning_addr_sk1033, _cr_return_amt_inc_tax1043};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_10141018_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_10141018_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_934066_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cr_returned_date_sk1023 = (it->second)._cr_returned_date_sk1023;
                int32_t _cr_returning_customer_sk1030 = (it->second)._cr_returning_customer_sk1030;
                int32_t _cr_returning_addr_sk1033 = (it->second)._cr_returning_addr_sk1033;
                int64_t _cr_return_amt_inc_tax1043 = (it->second)._cr_return_amt_inc_tax1043;
                int32_t _d_date_sk120 = tbl_Filter_TD_10141018_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_934066_output.setInt32(r, 0, _cr_returning_customer_sk1030);
                tbl_JOIN_INNER_TD_934066_output.setInt32(r, 1, _cr_returning_addr_sk1033);
                tbl_JOIN_INNER_TD_934066_output.setInt64(r, 2, _cr_return_amt_inc_tax1043);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_934066_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_934066_key_rightMajor, SW_JOIN_INNER_TD_934066_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_10141018_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_10141018_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_934066_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_10141018_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_934066_payload_rightMajor payloadA{_d_date_sk120};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_10717046_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cr_returned_date_sk1023_k = tbl_Filter_TD_10717046_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_934066_key_rightMajor{_cr_returned_date_sk1023_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _cr_returned_date_sk1023 = tbl_Filter_TD_10717046_output.getInt32(i, 0);
                int32_t _cr_returning_customer_sk1030 = tbl_Filter_TD_10717046_output.getInt32(i, 1);
                int32_t _cr_returning_addr_sk1033 = tbl_Filter_TD_10717046_output.getInt32(i, 2);
                int64_t _cr_return_amt_inc_tax1043 = tbl_Filter_TD_10717046_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_934066_output.setInt32(r, 0, _cr_returning_customer_sk1030);
                tbl_JOIN_INNER_TD_934066_output.setInt32(r, 1, _cr_returning_addr_sk1033);
                tbl_JOIN_INNER_TD_934066_output.setInt64(r, 2, _cr_return_amt_inc_tax1043);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_934066_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_934066_output #Row: " << tbl_JOIN_INNER_TD_934066_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_8307166_key {
    int32_t _cr_returning_customer_sk1030;
    std::string _ca_state62;
    bool operator==(const SW_Aggregate_TD_8307166_key& other) const { return (_cr_returning_customer_sk1030 == other._cr_returning_customer_sk1030) && (_ca_state62 == other._ca_state62); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_8307166_key> {
    std::size_t operator() (const SW_Aggregate_TD_8307166_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cr_returning_customer_sk1030)) + (hash<string>()(k._ca_state62));
    }
};
}
struct SW_Aggregate_TD_8307166_payload {
    std::string _ctr_state4047;
    int64_t _ctr_total_return4048_sum_0;
};
void SW_Aggregate_TD_8307166(Table &tbl_JOIN_INNER_TD_9877513_output, Table &tbl_Aggregate_TD_8307166_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(cr_returning_customer_sk#1030, ca_state#62, ca_state#62 AS ctr_state#4047, MakeDecimal(sum(UnscaledValue(cr_return_amt_inc_tax#1043)),17,2) AS ctr_total_return#4048)
    // Input: ListBuffer(cr_returning_customer_sk#1030, cr_return_amt_inc_tax#1043, ca_state#62)
    // Output: ListBuffer(ctr_state#4047, ctr_total_return#4048)
    std::unordered_map<SW_Aggregate_TD_8307166_key, SW_Aggregate_TD_8307166_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_9877513_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cr_returning_customer_sk1030 = tbl_JOIN_INNER_TD_9877513_output.getInt32(i, 0);
        int64_t _cr_return_amt_inc_tax1043 = tbl_JOIN_INNER_TD_9877513_output.getInt64(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _ca_state62 = tbl_JOIN_INNER_TD_9877513_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        SW_Aggregate_TD_8307166_key k{_cr_returning_customer_sk1030, std::string(_ca_state62.data())};
        std::array<char, TPCDS_READ_MAX + 1> _ctr_state4047 = _ca_state62;
        int64_t _ctr_total_return4048_sum_0 = _cr_return_amt_inc_tax1043;
        SW_Aggregate_TD_8307166_payload p{std::string(_ctr_state4047.data()), _ctr_total_return4048_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._ctr_total_return4048_sum_0 + _ctr_total_return4048_sum_0;
            p._ctr_total_return4048_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _cr_returning_customer_sk1030 not required in the output table
        // _ca_state62 not required in the output table
        std::array<char, TPCDS_READ_MAX + 1> _ctr_state4047_n{};
        memcpy(_ctr_state4047_n.data(), (it.second)._ctr_state4047.data(), (it.second)._ctr_state4047.length());
        tbl_Aggregate_TD_8307166_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ctr_state4047_n);
        int64_t _ctr_total_return4048 = (it.second)._ctr_total_return4048_sum_0;
        tbl_Aggregate_TD_8307166_output.setInt64(r, 1, _ctr_total_return4048);
        ++r;
    }
    tbl_Aggregate_TD_8307166_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_8307166_output #Row: " << tbl_Aggregate_TD_8307166_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8829719_key_leftMajor {
    int32_t _cr_returning_addr_sk1033;
    bool operator==(const SW_JOIN_INNER_TD_8829719_key_leftMajor& other) const {
        return ((_cr_returning_addr_sk1033 == other._cr_returning_addr_sk1033));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8829719_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8829719_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cr_returning_addr_sk1033));
    }
};
}
struct SW_JOIN_INNER_TD_8829719_payload_leftMajor {
    int32_t _cr_returning_customer_sk1030;
    int32_t _cr_returning_addr_sk1033;
    int64_t _cr_return_amt_inc_tax1043;
};
struct SW_JOIN_INNER_TD_8829719_key_rightMajor {
    int32_t _ca_address_sk54;
    bool operator==(const SW_JOIN_INNER_TD_8829719_key_rightMajor& other) const {
        return ((_ca_address_sk54 == other._ca_address_sk54));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8829719_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8829719_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk54));
    }
};
}
struct SW_JOIN_INNER_TD_8829719_payload_rightMajor {
    int32_t _ca_address_sk54;
    std::string _ca_state62;
};
void SW_JOIN_INNER_TD_8829719(Table &tbl_JOIN_INNER_TD_934066_output, Table &tbl_Filter_TD_9440346_output, Table &tbl_JOIN_INNER_TD_8829719_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cr_returning_addr_sk#1033 = ca_address_sk#54))
    // Left Table: ListBuffer(cr_returning_customer_sk#1030, cr_returning_addr_sk#1033, cr_return_amt_inc_tax#1043)
    // Right Table: ListBuffer(ca_address_sk#54, ca_state#62)
    // Output Table: ListBuffer(cr_returning_customer_sk#1030, cr_return_amt_inc_tax#1043, ca_state#62)
    int left_nrow = tbl_JOIN_INNER_TD_934066_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9440346_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8829719_key_leftMajor, SW_JOIN_INNER_TD_8829719_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_934066_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cr_returning_addr_sk1033_k = tbl_JOIN_INNER_TD_934066_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_8829719_key_leftMajor keyA{_cr_returning_addr_sk1033_k};
            int32_t _cr_returning_customer_sk1030 = tbl_JOIN_INNER_TD_934066_output.getInt32(i, 0);
            int32_t _cr_returning_addr_sk1033 = tbl_JOIN_INNER_TD_934066_output.getInt32(i, 1);
            int64_t _cr_return_amt_inc_tax1043 = tbl_JOIN_INNER_TD_934066_output.getInt64(i, 2);
            SW_JOIN_INNER_TD_8829719_payload_leftMajor payloadA{_cr_returning_customer_sk1030, _cr_returning_addr_sk1033, _cr_return_amt_inc_tax1043};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9440346_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_9440346_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8829719_key_leftMajor{_ca_address_sk54_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cr_returning_customer_sk1030 = (it->second)._cr_returning_customer_sk1030;
                int32_t _cr_returning_addr_sk1033 = (it->second)._cr_returning_addr_sk1033;
                int64_t _cr_return_amt_inc_tax1043 = (it->second)._cr_return_amt_inc_tax1043;
                int32_t _ca_address_sk54 = tbl_Filter_TD_9440346_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_Filter_TD_9440346_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_state62 = std::string(_ca_state62_n.data());
                tbl_JOIN_INNER_TD_8829719_output.setInt32(r, 0, _cr_returning_customer_sk1030);
                tbl_JOIN_INNER_TD_8829719_output.setInt64(r, 1, _cr_return_amt_inc_tax1043);
                tbl_JOIN_INNER_TD_8829719_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_state62_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8829719_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8829719_key_rightMajor, SW_JOIN_INNER_TD_8829719_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9440346_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_9440346_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8829719_key_rightMajor keyA{_ca_address_sk54_k};
            int32_t _ca_address_sk54 = tbl_Filter_TD_9440346_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_Filter_TD_9440346_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_state62 = std::string(_ca_state62_n.data());
            SW_JOIN_INNER_TD_8829719_payload_rightMajor payloadA{_ca_address_sk54, _ca_state62};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_934066_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cr_returning_addr_sk1033_k = tbl_JOIN_INNER_TD_934066_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8829719_key_rightMajor{_cr_returning_addr_sk1033_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk54 = (it->second)._ca_address_sk54;
                std::string _ca_state62 = (it->second)._ca_state62;
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n{};
                memcpy(_ca_state62_n.data(), (_ca_state62).data(), (_ca_state62).length());
                int32_t _cr_returning_customer_sk1030 = tbl_JOIN_INNER_TD_934066_output.getInt32(i, 0);
                int32_t _cr_returning_addr_sk1033 = tbl_JOIN_INNER_TD_934066_output.getInt32(i, 1);
                int64_t _cr_return_amt_inc_tax1043 = tbl_JOIN_INNER_TD_934066_output.getInt64(i, 2);
                tbl_JOIN_INNER_TD_8829719_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_state62_n);
                tbl_JOIN_INNER_TD_8829719_output.setInt32(r, 0, _cr_returning_customer_sk1030);
                tbl_JOIN_INNER_TD_8829719_output.setInt64(r, 1, _cr_return_amt_inc_tax1043);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8829719_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8829719_output #Row: " << tbl_JOIN_INNER_TD_8829719_output.getNumRow() << std::endl;
}

typedef std::string SW_Aggregate_TD_7419266_key;
struct SW_Aggregate_TD_7419266_payload {
    int64_t _124064_avg_0;
    std::string _ctr_state40474216;
};
void SW_Aggregate_TD_7419266(Table &tbl_Aggregate_TD_8307166_output, Table &tbl_Aggregate_TD_7419266_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(ctr_state#4047, CheckOverflow((promote_precision(avg(ctr_total_return#4048)) * 1.200000), DecimalType(24,7), true) AS (avg(ctr_total_return) * 1.2)#4064, ctr_state#4047 AS ctr_state#4047#4216)
    // Input: ListBuffer(ctr_state#4047, ctr_total_return#4048)
    // Output: ListBuffer((avg(ctr_total_return) * 1.2)#4064, ctr_state#4047#4216)
    std::unordered_map<SW_Aggregate_TD_7419266_key, SW_Aggregate_TD_7419266_payload> ht1;
    int nrow1 = tbl_Aggregate_TD_8307166_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _ctr_state4047 = tbl_Aggregate_TD_8307166_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        int64_t _ctr_total_return4048 = tbl_Aggregate_TD_8307166_output.getInt64(i, 1);
        SW_Aggregate_TD_7419266_key k = std::string(_ctr_state4047.data());
        int64_t _124064_avg_0 = _ctr_total_return4048;
        std::array<char, TPCDS_READ_MAX + 1> _ctr_state40474216 = _ctr_state4047;
        SW_Aggregate_TD_7419266_payload p{_124064_avg_0, std::string(_ctr_state40474216.data())};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t avg_0 = ((it->second)._124064_avg_0 + _124064_avg_0);
            p._124064_avg_0 = avg_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _ctr_state4047 not required in the output table
        int64_t _124064 = ((it.second)._124064_avg_0 / nrow1 * 1.200000);
        tbl_Aggregate_TD_7419266_output.setInt64(r, 0, _124064);
        std::array<char, TPCDS_READ_MAX + 1> _ctr_state40474216_n{};
        memcpy(_ctr_state40474216_n.data(), (it.second)._ctr_state40474216.data(), (it.second)._ctr_state40474216.length());
        tbl_Aggregate_TD_7419266_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ctr_state40474216_n);
        ++r;
    }
    tbl_Aggregate_TD_7419266_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_7419266_output #Row: " << tbl_Aggregate_TD_7419266_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_740845_key {
    int32_t _cr_returning_customer_sk1030;
    std::string _ca_state62;
    bool operator==(const SW_Aggregate_TD_740845_key& other) const { return (_cr_returning_customer_sk1030 == other._cr_returning_customer_sk1030) && (_ca_state62 == other._ca_state62); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_740845_key> {
    std::size_t operator() (const SW_Aggregate_TD_740845_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cr_returning_customer_sk1030)) + (hash<string>()(k._ca_state62));
    }
};
}
struct SW_Aggregate_TD_740845_payload {
    int32_t _ctr_customer_sk4046;
    std::string _ctr_state4047;
    int64_t _ctr_total_return4048_sum_0;
};
void SW_Aggregate_TD_740845(Table &tbl_JOIN_INNER_TD_8829719_output, Table &tbl_Aggregate_TD_740845_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(cr_returning_customer_sk#1030, ca_state#62, cr_returning_customer_sk#1030 AS ctr_customer_sk#4046, ca_state#62 AS ctr_state#4047, MakeDecimal(sum(UnscaledValue(cr_return_amt_inc_tax#1043)),17,2) AS ctr_total_return#4048)
    // Input: ListBuffer(cr_returning_customer_sk#1030, cr_return_amt_inc_tax#1043, ca_state#62)
    // Output: ListBuffer(ctr_customer_sk#4046, ctr_state#4047, ctr_total_return#4048)
    std::unordered_map<SW_Aggregate_TD_740845_key, SW_Aggregate_TD_740845_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_8829719_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cr_returning_customer_sk1030 = tbl_JOIN_INNER_TD_8829719_output.getInt32(i, 0);
        int64_t _cr_return_amt_inc_tax1043 = tbl_JOIN_INNER_TD_8829719_output.getInt64(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _ca_state62 = tbl_JOIN_INNER_TD_8829719_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        SW_Aggregate_TD_740845_key k{_cr_returning_customer_sk1030, std::string(_ca_state62.data())};
        int32_t _ctr_customer_sk4046 = _cr_returning_customer_sk1030;
        std::array<char, TPCDS_READ_MAX + 1> _ctr_state4047 = _ca_state62;
        int64_t _ctr_total_return4048_sum_0 = _cr_return_amt_inc_tax1043;
        SW_Aggregate_TD_740845_payload p{_ctr_customer_sk4046, std::string(_ctr_state4047.data()), _ctr_total_return4048_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._ctr_total_return4048_sum_0 + _ctr_total_return4048_sum_0;
            p._ctr_total_return4048_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _cr_returning_customer_sk1030 not required in the output table
        // _ca_state62 not required in the output table
        tbl_Aggregate_TD_740845_output.setInt32(r, 0, (it.second)._ctr_customer_sk4046);
        std::array<char, TPCDS_READ_MAX + 1> _ctr_state4047_n{};
        memcpy(_ctr_state4047_n.data(), (it.second)._ctr_state4047.data(), (it.second)._ctr_state4047.length());
        tbl_Aggregate_TD_740845_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ctr_state4047_n);
        int64_t _ctr_total_return4048 = (it.second)._ctr_total_return4048_sum_0;
        tbl_Aggregate_TD_740845_output.setInt64(r, 2, _ctr_total_return4048);
        ++r;
    }
    tbl_Aggregate_TD_740845_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_740845_output #Row: " << tbl_Aggregate_TD_740845_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6330250(Table &tbl_Aggregate_TD_7419266_output, Table &tbl_Filter_TD_6330250_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull((avg(ctr_total_return) * 1.2)#4064))
    // Input: ListBuffer((avg(ctr_total_return) * 1.2)#4064, ctr_state#4047#4216)
    // Output: ListBuffer((avg(ctr_total_return) * 1.2)#4064, ctr_state#4047#4216)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_7419266_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _124064 = tbl_Aggregate_TD_7419266_output.getInt64(i, 0);
        if (_124064!= 0) {
            int64_t _124064_t = tbl_Aggregate_TD_7419266_output.getInt64(i, 0);
            tbl_Filter_TD_6330250_output.setInt64(r, 0, _124064_t);
            std::array<char, TPCDS_READ_MAX + 1> _ctr_state40474216_t = tbl_Aggregate_TD_7419266_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_6330250_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ctr_state40474216_t);
            r++;
        }
    }
    tbl_Filter_TD_6330250_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6330250_output #Row: " << tbl_Filter_TD_6330250_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6893028(Table &tbl_Aggregate_TD_740845_output, Table &tbl_Filter_TD_6893028_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ctr_total_return#4048))
    // Input: ListBuffer(ctr_customer_sk#4046, ctr_state#4047, ctr_total_return#4048)
    // Output: ListBuffer(ctr_customer_sk#4046, ctr_state#4047, ctr_total_return#4048)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_740845_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ctr_total_return4048 = tbl_Aggregate_TD_740845_output.getInt64(i, 2);
        if (_ctr_total_return4048!= 0) {
            int32_t _ctr_customer_sk4046_t = tbl_Aggregate_TD_740845_output.getInt32(i, 0);
            tbl_Filter_TD_6893028_output.setInt32(r, 0, _ctr_customer_sk4046_t);
            std::array<char, TPCDS_READ_MAX + 1> _ctr_state4047_t = tbl_Aggregate_TD_740845_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_6893028_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ctr_state4047_t);
            int64_t _ctr_total_return4048_t = tbl_Aggregate_TD_740845_output.getInt64(i, 2);
            tbl_Filter_TD_6893028_output.setInt64(r, 2, _ctr_total_return4048_t);
            r++;
        }
    }
    tbl_Filter_TD_6893028_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6893028_output #Row: " << tbl_Filter_TD_6893028_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5743616(Table &tbl_SerializeFromObject_TD_6317840_input, Table &tbl_Filter_TD_5743616_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(c_customer_sk#0) AND isnotnull(c_current_addr_sk#4)))
    // Input: ListBuffer(c_customer_sk#0, c_customer_id#1, c_current_addr_sk#4, c_salutation#7, c_first_name#8, c_last_name#9)
    // Output: ListBuffer(c_customer_sk#0, c_customer_id#1, c_current_addr_sk#4, c_salutation#7, c_first_name#8, c_last_name#9)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6317840_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk0 = tbl_SerializeFromObject_TD_6317840_input.getInt32(i, 0);
        int32_t _c_current_addr_sk4 = tbl_SerializeFromObject_TD_6317840_input.getInt32(i, 2);
        if ((_c_customer_sk0!= 0) && (_c_current_addr_sk4!= 0)) {
            int32_t _c_customer_sk0_t = tbl_SerializeFromObject_TD_6317840_input.getInt32(i, 0);
            tbl_Filter_TD_5743616_output.setInt32(r, 0, _c_customer_sk0_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_t = tbl_SerializeFromObject_TD_6317840_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_5743616_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_customer_id1_t);
            int32_t _c_current_addr_sk4_t = tbl_SerializeFromObject_TD_6317840_input.getInt32(i, 2);
            tbl_Filter_TD_5743616_output.setInt32(r, 2, _c_current_addr_sk4_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_salutation7_t = tbl_SerializeFromObject_TD_6317840_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_5743616_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_salutation7_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_t = tbl_SerializeFromObject_TD_6317840_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            tbl_Filter_TD_5743616_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_first_name8_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_t = tbl_SerializeFromObject_TD_6317840_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            tbl_Filter_TD_5743616_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_last_name9_t);
            r++;
        }
    }
    tbl_Filter_TD_5743616_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5743616_output #Row: " << tbl_Filter_TD_5743616_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5107319_key_leftMajor {
    std::string _ctr_state4047;
    bool operator==(const SW_JOIN_INNER_TD_5107319_key_leftMajor& other) const {
        return ((_ctr_state4047 == other._ctr_state4047));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5107319_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5107319_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._ctr_state4047));
    }
};
}
struct SW_JOIN_INNER_TD_5107319_payload_leftMajor {
    int32_t _ctr_customer_sk4046;
    std::string _ctr_state4047;
    int64_t _ctr_total_return4048;
};
struct SW_JOIN_INNER_TD_5107319_key_rightMajor {
    std::string _ctr_state40474216;
    bool operator==(const SW_JOIN_INNER_TD_5107319_key_rightMajor& other) const {
        return ((_ctr_state40474216 == other._ctr_state40474216));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5107319_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5107319_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._ctr_state40474216));
    }
};
}
struct SW_JOIN_INNER_TD_5107319_payload_rightMajor {
    int64_t _124064;
    std::string _ctr_state40474216;
};
void SW_JOIN_INNER_TD_5107319(Table &tbl_Filter_TD_6893028_output, Table &tbl_Filter_TD_6330250_output, Table &tbl_JOIN_INNER_TD_5107319_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((cast(ctr_total_return#4048 as decimal(24,7)) > (avg(ctr_total_return) * 1.2)#4064) AND (ctr_state#4047 = ctr_state#4047#4216)))
    // Left Table: ListBuffer(ctr_customer_sk#4046, ctr_state#4047, ctr_total_return#4048)
    // Right Table: ListBuffer((avg(ctr_total_return) * 1.2)#4064, ctr_state#4047#4216)
    // Output Table: ListBuffer(ctr_customer_sk#4046, ctr_total_return#4048)
    int left_nrow = tbl_Filter_TD_6893028_output.getNumRow();
    int right_nrow = tbl_Filter_TD_6330250_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5107319_key_leftMajor, SW_JOIN_INNER_TD_5107319_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_6893028_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ctr_state4047_k_n = tbl_Filter_TD_6893028_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ctr_state4047_k = std::string(_ctr_state4047_k_n.data());
            SW_JOIN_INNER_TD_5107319_key_leftMajor keyA{_ctr_state4047_k};
            int32_t _ctr_customer_sk4046 = tbl_Filter_TD_6893028_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ctr_state4047_n = tbl_Filter_TD_6893028_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ctr_state4047 = std::string(_ctr_state4047_n.data());
            int64_t _ctr_total_return4048 = tbl_Filter_TD_6893028_output.getInt64(i, 2);
            SW_JOIN_INNER_TD_5107319_payload_leftMajor payloadA{_ctr_customer_sk4046, _ctr_state4047, _ctr_total_return4048};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6330250_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ctr_state40474216_k_n = tbl_Filter_TD_6330250_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ctr_state40474216_k = std::string(_ctr_state40474216_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5107319_key_leftMajor{_ctr_state40474216_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ctr_customer_sk4046 = (it->second)._ctr_customer_sk4046;
                std::string _ctr_state4047 = (it->second)._ctr_state4047;
                std::array<char, TPCDS_READ_MAX + 1> _ctr_state4047_n{};
                memcpy(_ctr_state4047_n.data(), (_ctr_state4047).data(), (_ctr_state4047).length());
                int64_t _ctr_total_return4048 = (it->second)._ctr_total_return4048;
                int64_t _124064 = tbl_Filter_TD_6330250_output.getInt64(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ctr_state40474216_n = tbl_Filter_TD_6330250_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ctr_state40474216 = std::string(_ctr_state40474216_n.data());
                tbl_JOIN_INNER_TD_5107319_output.setInt32(r, 0, _ctr_customer_sk4046);
                tbl_JOIN_INNER_TD_5107319_output.setInt64(r, 1, _ctr_total_return4048);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5107319_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5107319_key_rightMajor, SW_JOIN_INNER_TD_5107319_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_6330250_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ctr_state40474216_k_n = tbl_Filter_TD_6330250_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ctr_state40474216_k = std::string(_ctr_state40474216_k_n.data());
            SW_JOIN_INNER_TD_5107319_key_rightMajor keyA{_ctr_state40474216_k};
            int64_t _124064 = tbl_Filter_TD_6330250_output.getInt64(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ctr_state40474216_n = tbl_Filter_TD_6330250_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ctr_state40474216 = std::string(_ctr_state40474216_n.data());
            SW_JOIN_INNER_TD_5107319_payload_rightMajor payloadA{_124064, _ctr_state40474216};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6893028_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ctr_state4047_k_n = tbl_Filter_TD_6893028_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ctr_state4047_k = std::string(_ctr_state4047_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5107319_key_rightMajor{_ctr_state4047_k});
            auto it = its.first;
            while (it != its.second) {
                int64_t _124064 = (it->second)._124064;
                std::string _ctr_state40474216 = (it->second)._ctr_state40474216;
                std::array<char, TPCDS_READ_MAX + 1> _ctr_state40474216_n{};
                memcpy(_ctr_state40474216_n.data(), (_ctr_state40474216).data(), (_ctr_state40474216).length());
                int32_t _ctr_customer_sk4046 = tbl_Filter_TD_6893028_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ctr_state4047_n = tbl_Filter_TD_6893028_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ctr_state4047 = std::string(_ctr_state4047_n.data());
                int64_t _ctr_total_return4048 = tbl_Filter_TD_6893028_output.getInt64(i, 2);
                tbl_JOIN_INNER_TD_5107319_output.setInt32(r, 0, _ctr_customer_sk4046);
                tbl_JOIN_INNER_TD_5107319_output.setInt64(r, 1, _ctr_total_return4048);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5107319_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5107319_output #Row: " << tbl_JOIN_INNER_TD_5107319_output.getNumRow() << std::endl;
}

void SW_Filter_TD_4388490(Table &tbl_SerializeFromObject_TD_58837_input, Table &tbl_Filter_TD_4388490_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ca_state#4057) AND (ca_state#4057 = GA)) AND isnotnull(ca_address_sk#4049)))
    // Input: ListBuffer(ca_address_sk#4049, ca_street_number#4051, ca_street_name#4052, ca_street_type#4053, ca_suite_number#4054, ca_city#4055, ca_county#4056, ca_state#4057, ca_zip#4058, ca_country#4059, ca_gmt_offset#4060, ca_location_type#4061)
    // Output: ListBuffer(ca_address_sk#4049, ca_street_number#4051, ca_street_name#4052, ca_street_type#4053, ca_suite_number#4054, ca_city#4055, ca_county#4056, ca_state#4057, ca_zip#4058, ca_country#4059, ca_gmt_offset#4060, ca_location_type#4061)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_58837_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_state4057 = tbl_SerializeFromObject_TD_58837_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
        int32_t _ca_address_sk4049 = tbl_SerializeFromObject_TD_58837_input.getInt32(i, 0);
        if (((_ca_state4057.data() != "NULL") && (std::string(_ca_state4057.data()) == "GA")) && (_ca_address_sk4049!= 0)) {
            int32_t _ca_address_sk4049_t = tbl_SerializeFromObject_TD_58837_input.getInt32(i, 0);
            tbl_Filter_TD_4388490_output.setInt32(r, 0, _ca_address_sk4049_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_number4051_t = tbl_SerializeFromObject_TD_58837_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_4388490_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_street_number4051_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_name4052_t = tbl_SerializeFromObject_TD_58837_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_4388490_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_street_name4052_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_type4053_t = tbl_SerializeFromObject_TD_58837_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_4388490_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_street_type4053_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_suite_number4054_t = tbl_SerializeFromObject_TD_58837_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            tbl_Filter_TD_4388490_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _ca_suite_number4054_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_city4055_t = tbl_SerializeFromObject_TD_58837_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            tbl_Filter_TD_4388490_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _ca_city4055_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_county4056_t = tbl_SerializeFromObject_TD_58837_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            tbl_Filter_TD_4388490_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _ca_county4056_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_state4057_t = tbl_SerializeFromObject_TD_58837_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            tbl_Filter_TD_4388490_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _ca_state4057_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip4058_t = tbl_SerializeFromObject_TD_58837_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
            tbl_Filter_TD_4388490_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _ca_zip4058_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_country4059_t = tbl_SerializeFromObject_TD_58837_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            tbl_Filter_TD_4388490_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _ca_country4059_t);
            int64_t _ca_gmt_offset4060_t = tbl_SerializeFromObject_TD_58837_input.getInt64(i, 10);
            tbl_Filter_TD_4388490_output.setInt64(r, 10, _ca_gmt_offset4060_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_location_type4061_t = tbl_SerializeFromObject_TD_58837_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
            tbl_Filter_TD_4388490_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _ca_location_type4061_t);
            r++;
        }
    }
    tbl_Filter_TD_4388490_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4388490_output #Row: " << tbl_Filter_TD_4388490_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4460001_key_leftMajor {
    int32_t _ctr_customer_sk4046;
    bool operator==(const SW_JOIN_INNER_TD_4460001_key_leftMajor& other) const {
        return ((_ctr_customer_sk4046 == other._ctr_customer_sk4046));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4460001_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4460001_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ctr_customer_sk4046));
    }
};
}
struct SW_JOIN_INNER_TD_4460001_payload_leftMajor {
    int32_t _ctr_customer_sk4046;
    int64_t _ctr_total_return4048;
};
struct SW_JOIN_INNER_TD_4460001_key_rightMajor {
    int32_t _c_customer_sk0;
    bool operator==(const SW_JOIN_INNER_TD_4460001_key_rightMajor& other) const {
        return ((_c_customer_sk0 == other._c_customer_sk0));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4460001_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4460001_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk0));
    }
};
}
struct SW_JOIN_INNER_TD_4460001_payload_rightMajor {
    int32_t _c_customer_sk0;
    std::string _c_customer_id1;
    int32_t _c_current_addr_sk4;
    std::string _c_salutation7;
    std::string _c_first_name8;
    std::string _c_last_name9;
};
void SW_JOIN_INNER_TD_4460001(Table &tbl_JOIN_INNER_TD_5107319_output, Table &tbl_Filter_TD_5743616_output, Table &tbl_JOIN_INNER_TD_4460001_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ctr_customer_sk#4046 = c_customer_sk#0))
    // Left Table: ListBuffer(ctr_customer_sk#4046, ctr_total_return#4048)
    // Right Table: ListBuffer(c_customer_sk#0, c_customer_id#1, c_current_addr_sk#4, c_salutation#7, c_first_name#8, c_last_name#9)
    // Output Table: ListBuffer(ctr_total_return#4048, c_customer_id#1, c_current_addr_sk#4, c_salutation#7, c_first_name#8, c_last_name#9)
    int left_nrow = tbl_JOIN_INNER_TD_5107319_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5743616_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4460001_key_leftMajor, SW_JOIN_INNER_TD_4460001_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_5107319_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ctr_customer_sk4046_k = tbl_JOIN_INNER_TD_5107319_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4460001_key_leftMajor keyA{_ctr_customer_sk4046_k};
            int32_t _ctr_customer_sk4046 = tbl_JOIN_INNER_TD_5107319_output.getInt32(i, 0);
            int64_t _ctr_total_return4048 = tbl_JOIN_INNER_TD_5107319_output.getInt64(i, 1);
            SW_JOIN_INNER_TD_4460001_payload_leftMajor payloadA{_ctr_customer_sk4046, _ctr_total_return4048};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5743616_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_5743616_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4460001_key_leftMajor{_c_customer_sk0_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ctr_customer_sk4046 = (it->second)._ctr_customer_sk4046;
                int64_t _ctr_total_return4048 = (it->second)._ctr_total_return4048;
                int32_t _c_customer_sk0 = tbl_Filter_TD_5743616_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n = tbl_Filter_TD_5743616_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_customer_id1 = std::string(_c_customer_id1_n.data());
                int32_t _c_current_addr_sk4 = tbl_Filter_TD_5743616_output.getInt32(i, 2);
                std::array<char, TPCDS_READ_MAX + 1> _c_salutation7_n = tbl_Filter_TD_5743616_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_salutation7 = std::string(_c_salutation7_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_Filter_TD_5743616_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_first_name8 = std::string(_c_first_name8_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_Filter_TD_5743616_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _c_last_name9 = std::string(_c_last_name9_n.data());
                tbl_JOIN_INNER_TD_4460001_output.setInt64(r, 0, _ctr_total_return4048);
                tbl_JOIN_INNER_TD_4460001_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_customer_id1_n);
                tbl_JOIN_INNER_TD_4460001_output.setInt32(r, 2, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_4460001_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_salutation7_n);
                tbl_JOIN_INNER_TD_4460001_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_first_name8_n);
                tbl_JOIN_INNER_TD_4460001_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_last_name9_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4460001_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4460001_key_rightMajor, SW_JOIN_INNER_TD_4460001_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5743616_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_5743616_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4460001_key_rightMajor keyA{_c_customer_sk0_k};
            int32_t _c_customer_sk0 = tbl_Filter_TD_5743616_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n = tbl_Filter_TD_5743616_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_customer_id1 = std::string(_c_customer_id1_n.data());
            int32_t _c_current_addr_sk4 = tbl_Filter_TD_5743616_output.getInt32(i, 2);
            std::array<char, TPCDS_READ_MAX + 1> _c_salutation7_n = tbl_Filter_TD_5743616_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_salutation7 = std::string(_c_salutation7_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_Filter_TD_5743616_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_first_name8 = std::string(_c_first_name8_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_Filter_TD_5743616_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _c_last_name9 = std::string(_c_last_name9_n.data());
            SW_JOIN_INNER_TD_4460001_payload_rightMajor payloadA{_c_customer_sk0, _c_customer_id1, _c_current_addr_sk4, _c_salutation7, _c_first_name8, _c_last_name9};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_5107319_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ctr_customer_sk4046_k = tbl_JOIN_INNER_TD_5107319_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4460001_key_rightMajor{_ctr_customer_sk4046_k});
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
                int32_t _ctr_customer_sk4046 = tbl_JOIN_INNER_TD_5107319_output.getInt32(i, 0);
                int64_t _ctr_total_return4048 = tbl_JOIN_INNER_TD_5107319_output.getInt64(i, 1);
                tbl_JOIN_INNER_TD_4460001_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_customer_id1_n);
                tbl_JOIN_INNER_TD_4460001_output.setInt32(r, 2, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_4460001_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_salutation7_n);
                tbl_JOIN_INNER_TD_4460001_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_first_name8_n);
                tbl_JOIN_INNER_TD_4460001_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_last_name9_n);
                tbl_JOIN_INNER_TD_4460001_output.setInt64(r, 0, _ctr_total_return4048);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4460001_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4460001_output #Row: " << tbl_JOIN_INNER_TD_4460001_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_3236528_key_leftMajor {
    int32_t _c_current_addr_sk4;
    bool operator==(const SW_JOIN_INNER_TD_3236528_key_leftMajor& other) const {
        return ((_c_current_addr_sk4 == other._c_current_addr_sk4));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3236528_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3236528_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_current_addr_sk4));
    }
};
}
struct SW_JOIN_INNER_TD_3236528_payload_leftMajor {
    int64_t _ctr_total_return4048;
    std::string _c_customer_id1;
    int32_t _c_current_addr_sk4;
    std::string _c_salutation7;
    std::string _c_first_name8;
    std::string _c_last_name9;
};
struct SW_JOIN_INNER_TD_3236528_key_rightMajor {
    int32_t _ca_address_sk4049;
    bool operator==(const SW_JOIN_INNER_TD_3236528_key_rightMajor& other) const {
        return ((_ca_address_sk4049 == other._ca_address_sk4049));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3236528_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3236528_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk4049));
    }
};
}
struct SW_JOIN_INNER_TD_3236528_payload_rightMajor {
    int32_t _ca_address_sk4049;
    std::string _ca_street_number4051;
    std::string _ca_street_name4052;
    std::string _ca_street_type4053;
    std::string _ca_suite_number4054;
    std::string _ca_city4055;
    std::string _ca_county4056;
    std::string _ca_state4057;
    std::string _ca_zip4058;
    std::string _ca_country4059;
    int64_t _ca_gmt_offset4060;
    std::string _ca_location_type4061;
};
void SW_JOIN_INNER_TD_3236528(Table &tbl_JOIN_INNER_TD_4460001_output, Table &tbl_Filter_TD_4388490_output, Table &tbl_JOIN_INNER_TD_3236528_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ca_address_sk#4049 = c_current_addr_sk#4))
    // Left Table: ListBuffer(ctr_total_return#4048, c_customer_id#1, c_current_addr_sk#4, c_salutation#7, c_first_name#8, c_last_name#9)
    // Right Table: ListBuffer(ca_address_sk#4049, ca_street_number#4051, ca_street_name#4052, ca_street_type#4053, ca_suite_number#4054, ca_city#4055, ca_county#4056, ca_state#4057, ca_zip#4058, ca_country#4059, ca_gmt_offset#4060, ca_location_type#4061)
    // Output Table: ListBuffer(c_customer_id#1, c_salutation#7, c_first_name#8, c_last_name#9, ca_street_number#4051, ca_street_name#4052, ca_street_type#4053, ca_suite_number#4054, ca_city#4055, ca_county#4056, ca_state#4057, ca_zip#4058, ca_country#4059, ca_gmt_offset#4060, ca_location_type#4061, ctr_total_return#4048)
    int left_nrow = tbl_JOIN_INNER_TD_4460001_output.getNumRow();
    int right_nrow = tbl_Filter_TD_4388490_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3236528_key_leftMajor, SW_JOIN_INNER_TD_3236528_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_4460001_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_current_addr_sk4_k = tbl_JOIN_INNER_TD_4460001_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_3236528_key_leftMajor keyA{_c_current_addr_sk4_k};
            int64_t _ctr_total_return4048 = tbl_JOIN_INNER_TD_4460001_output.getInt64(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n = tbl_JOIN_INNER_TD_4460001_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_customer_id1 = std::string(_c_customer_id1_n.data());
            int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_4460001_output.getInt32(i, 2);
            std::array<char, TPCDS_READ_MAX + 1> _c_salutation7_n = tbl_JOIN_INNER_TD_4460001_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_salutation7 = std::string(_c_salutation7_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_JOIN_INNER_TD_4460001_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_first_name8 = std::string(_c_first_name8_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_JOIN_INNER_TD_4460001_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _c_last_name9 = std::string(_c_last_name9_n.data());
            SW_JOIN_INNER_TD_3236528_payload_leftMajor payloadA{_ctr_total_return4048, _c_customer_id1, _c_current_addr_sk4, _c_salutation7, _c_first_name8, _c_last_name9};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_4388490_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk4049_k = tbl_Filter_TD_4388490_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3236528_key_leftMajor{_ca_address_sk4049_k});
            auto it = its.first;
            while (it != its.second) {
                int64_t _ctr_total_return4048 = (it->second)._ctr_total_return4048;
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
                int32_t _ca_address_sk4049 = tbl_Filter_TD_4388490_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number4051_n = tbl_Filter_TD_4388490_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_street_number4051 = std::string(_ca_street_number4051_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name4052_n = tbl_Filter_TD_4388490_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _ca_street_name4052 = std::string(_ca_street_name4052_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_type4053_n = tbl_Filter_TD_4388490_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _ca_street_type4053 = std::string(_ca_street_type4053_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_suite_number4054_n = tbl_Filter_TD_4388490_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _ca_suite_number4054 = std::string(_ca_suite_number4054_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_city4055_n = tbl_Filter_TD_4388490_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _ca_city4055 = std::string(_ca_city4055_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_county4056_n = tbl_Filter_TD_4388490_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _ca_county4056 = std::string(_ca_county4056_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_state4057_n = tbl_Filter_TD_4388490_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _ca_state4057 = std::string(_ca_state4057_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip4058_n = tbl_Filter_TD_4388490_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
                std::string _ca_zip4058 = std::string(_ca_zip4058_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_country4059_n = tbl_Filter_TD_4388490_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
                std::string _ca_country4059 = std::string(_ca_country4059_n.data());
                int64_t _ca_gmt_offset4060 = tbl_Filter_TD_4388490_output.getInt64(i, 10);
                std::array<char, TPCDS_READ_MAX + 1> _ca_location_type4061_n = tbl_Filter_TD_4388490_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
                std::string _ca_location_type4061 = std::string(_ca_location_type4061_n.data());
                tbl_JOIN_INNER_TD_3236528_output.setInt64(r, 15, _ctr_total_return4048);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id1_n);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_salutation7_n);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name8_n);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name9_n);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _ca_street_number4051_n);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _ca_street_name4052_n);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _ca_street_type4053_n);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _ca_suite_number4054_n);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _ca_city4055_n);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _ca_county4056_n);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _ca_state4057_n);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _ca_zip4058_n);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _ca_country4059_n);
                tbl_JOIN_INNER_TD_3236528_output.setInt64(r, 13, _ca_gmt_offset4060);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 14, _ca_location_type4061_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3236528_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3236528_key_rightMajor, SW_JOIN_INNER_TD_3236528_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_4388490_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk4049_k = tbl_Filter_TD_4388490_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3236528_key_rightMajor keyA{_ca_address_sk4049_k};
            int32_t _ca_address_sk4049 = tbl_Filter_TD_4388490_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_number4051_n = tbl_Filter_TD_4388490_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_street_number4051 = std::string(_ca_street_number4051_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_name4052_n = tbl_Filter_TD_4388490_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _ca_street_name4052 = std::string(_ca_street_name4052_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_type4053_n = tbl_Filter_TD_4388490_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _ca_street_type4053 = std::string(_ca_street_type4053_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_suite_number4054_n = tbl_Filter_TD_4388490_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _ca_suite_number4054 = std::string(_ca_suite_number4054_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_city4055_n = tbl_Filter_TD_4388490_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _ca_city4055 = std::string(_ca_city4055_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_county4056_n = tbl_Filter_TD_4388490_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _ca_county4056 = std::string(_ca_county4056_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_state4057_n = tbl_Filter_TD_4388490_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _ca_state4057 = std::string(_ca_state4057_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip4058_n = tbl_Filter_TD_4388490_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
            std::string _ca_zip4058 = std::string(_ca_zip4058_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_country4059_n = tbl_Filter_TD_4388490_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            std::string _ca_country4059 = std::string(_ca_country4059_n.data());
            int64_t _ca_gmt_offset4060 = tbl_Filter_TD_4388490_output.getInt64(i, 10);
            std::array<char, TPCDS_READ_MAX + 1> _ca_location_type4061_n = tbl_Filter_TD_4388490_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
            std::string _ca_location_type4061 = std::string(_ca_location_type4061_n.data());
            SW_JOIN_INNER_TD_3236528_payload_rightMajor payloadA{_ca_address_sk4049, _ca_street_number4051, _ca_street_name4052, _ca_street_type4053, _ca_suite_number4054, _ca_city4055, _ca_county4056, _ca_state4057, _ca_zip4058, _ca_country4059, _ca_gmt_offset4060, _ca_location_type4061};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_4460001_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_current_addr_sk4_k = tbl_JOIN_INNER_TD_4460001_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3236528_key_rightMajor{_c_current_addr_sk4_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk4049 = (it->second)._ca_address_sk4049;
                std::string _ca_street_number4051 = (it->second)._ca_street_number4051;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number4051_n{};
                memcpy(_ca_street_number4051_n.data(), (_ca_street_number4051).data(), (_ca_street_number4051).length());
                std::string _ca_street_name4052 = (it->second)._ca_street_name4052;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name4052_n{};
                memcpy(_ca_street_name4052_n.data(), (_ca_street_name4052).data(), (_ca_street_name4052).length());
                std::string _ca_street_type4053 = (it->second)._ca_street_type4053;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_type4053_n{};
                memcpy(_ca_street_type4053_n.data(), (_ca_street_type4053).data(), (_ca_street_type4053).length());
                std::string _ca_suite_number4054 = (it->second)._ca_suite_number4054;
                std::array<char, TPCDS_READ_MAX + 1> _ca_suite_number4054_n{};
                memcpy(_ca_suite_number4054_n.data(), (_ca_suite_number4054).data(), (_ca_suite_number4054).length());
                std::string _ca_city4055 = (it->second)._ca_city4055;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city4055_n{};
                memcpy(_ca_city4055_n.data(), (_ca_city4055).data(), (_ca_city4055).length());
                std::string _ca_county4056 = (it->second)._ca_county4056;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county4056_n{};
                memcpy(_ca_county4056_n.data(), (_ca_county4056).data(), (_ca_county4056).length());
                std::string _ca_state4057 = (it->second)._ca_state4057;
                std::array<char, TPCDS_READ_MAX + 1> _ca_state4057_n{};
                memcpy(_ca_state4057_n.data(), (_ca_state4057).data(), (_ca_state4057).length());
                std::string _ca_zip4058 = (it->second)._ca_zip4058;
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip4058_n{};
                memcpy(_ca_zip4058_n.data(), (_ca_zip4058).data(), (_ca_zip4058).length());
                std::string _ca_country4059 = (it->second)._ca_country4059;
                std::array<char, TPCDS_READ_MAX + 1> _ca_country4059_n{};
                memcpy(_ca_country4059_n.data(), (_ca_country4059).data(), (_ca_country4059).length());
                int64_t _ca_gmt_offset4060 = (it->second)._ca_gmt_offset4060;
                std::string _ca_location_type4061 = (it->second)._ca_location_type4061;
                std::array<char, TPCDS_READ_MAX + 1> _ca_location_type4061_n{};
                memcpy(_ca_location_type4061_n.data(), (_ca_location_type4061).data(), (_ca_location_type4061).length());
                int64_t _ctr_total_return4048 = tbl_JOIN_INNER_TD_4460001_output.getInt64(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n = tbl_JOIN_INNER_TD_4460001_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_customer_id1 = std::string(_c_customer_id1_n.data());
                int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_4460001_output.getInt32(i, 2);
                std::array<char, TPCDS_READ_MAX + 1> _c_salutation7_n = tbl_JOIN_INNER_TD_4460001_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_salutation7 = std::string(_c_salutation7_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_JOIN_INNER_TD_4460001_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_first_name8 = std::string(_c_first_name8_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_JOIN_INNER_TD_4460001_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _c_last_name9 = std::string(_c_last_name9_n.data());
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _ca_street_number4051_n);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _ca_street_name4052_n);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _ca_street_type4053_n);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _ca_suite_number4054_n);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _ca_city4055_n);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _ca_county4056_n);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _ca_state4057_n);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _ca_zip4058_n);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _ca_country4059_n);
                tbl_JOIN_INNER_TD_3236528_output.setInt64(r, 13, _ca_gmt_offset4060);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 14, _ca_location_type4061_n);
                tbl_JOIN_INNER_TD_3236528_output.setInt64(r, 15, _ctr_total_return4048);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id1_n);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_salutation7_n);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name8_n);
                tbl_JOIN_INNER_TD_3236528_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name9_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3236528_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_3236528_output #Row: " << tbl_JOIN_INNER_TD_3236528_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2924774(Table &tbl_JOIN_INNER_TD_3236528_output, Table &tbl_Sort_TD_2924774_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(c_customer_id#1 ASC NULLS FIRST, c_salutation#7 ASC NULLS FIRST, c_first_name#8 ASC NULLS FIRST, c_last_name#9 ASC NULLS FIRST, ca_street_number#4051 ASC NULLS FIRST, ca_street_name#4052 ASC NULLS FIRST, ca_street_type#4053 ASC NULLS FIRST, ca_suite_number#4054 ASC NULLS FIRST, ca_city#4055 ASC NULLS FIRST, ca_county#4056 ASC NULLS FIRST, ca_state#4057 ASC NULLS FIRST, ca_zip#4058 ASC NULLS FIRST, ca_country#4059 ASC NULLS FIRST, ca_gmt_offset#4060 ASC NULLS FIRST, ca_location_type#4061 ASC NULLS FIRST, ctr_total_return#4048 ASC NULLS FIRST)
    // Input: ListBuffer(c_customer_id#1, c_salutation#7, c_first_name#8, c_last_name#9, ca_street_number#4051, ca_street_name#4052, ca_street_type#4053, ca_suite_number#4054, ca_city#4055, ca_county#4056, ca_state#4057, ca_zip#4058, ca_country#4059, ca_gmt_offset#4060, ca_location_type#4061, ctr_total_return#4048)
    // Output: ListBuffer(c_customer_id#1, c_salutation#7, c_first_name#8, c_last_name#9, ca_street_number#4051, ca_street_name#4052, ca_street_type#4053, ca_suite_number#4054, ca_city#4055, ca_county#4056, ca_state#4057, ca_zip#4058, ca_country#4059, ca_gmt_offset#4060, ca_location_type#4061, ctr_total_return#4048)
    struct SW_Sort_TD_2924774Row {
        std::string _c_customer_id1;
        std::string _c_salutation7;
        std::string _c_first_name8;
        std::string _c_last_name9;
        std::string _ca_street_number4051;
        std::string _ca_street_name4052;
        std::string _ca_street_type4053;
        std::string _ca_suite_number4054;
        std::string _ca_city4055;
        std::string _ca_county4056;
        std::string _ca_state4057;
        std::string _ca_zip4058;
        std::string _ca_country4059;
        int64_t _ca_gmt_offset4060;
        std::string _ca_location_type4061;
        int64_t _ctr_total_return4048;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2924774Row& a, const SW_Sort_TD_2924774Row& b) const { return 
 (a._c_customer_id1 < b._c_customer_id1) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 < b._c_salutation7)) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 == b._c_salutation7) && (a._c_first_name8 < b._c_first_name8)) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 == b._c_salutation7) && (a._c_first_name8 == b._c_first_name8) && (a._c_last_name9 < b._c_last_name9)) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 == b._c_salutation7) && (a._c_first_name8 == b._c_first_name8) && (a._c_last_name9 == b._c_last_name9) && (a._ca_street_number4051 < b._ca_street_number4051)) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 == b._c_salutation7) && (a._c_first_name8 == b._c_first_name8) && (a._c_last_name9 == b._c_last_name9) && (a._ca_street_number4051 == b._ca_street_number4051) && (a._ca_street_name4052 < b._ca_street_name4052)) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 == b._c_salutation7) && (a._c_first_name8 == b._c_first_name8) && (a._c_last_name9 == b._c_last_name9) && (a._ca_street_number4051 == b._ca_street_number4051) && (a._ca_street_name4052 == b._ca_street_name4052) && (a._ca_street_type4053 < b._ca_street_type4053)) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 == b._c_salutation7) && (a._c_first_name8 == b._c_first_name8) && (a._c_last_name9 == b._c_last_name9) && (a._ca_street_number4051 == b._ca_street_number4051) && (a._ca_street_name4052 == b._ca_street_name4052) && (a._ca_street_type4053 == b._ca_street_type4053) && (a._ca_suite_number4054 < b._ca_suite_number4054)) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 == b._c_salutation7) && (a._c_first_name8 == b._c_first_name8) && (a._c_last_name9 == b._c_last_name9) && (a._ca_street_number4051 == b._ca_street_number4051) && (a._ca_street_name4052 == b._ca_street_name4052) && (a._ca_street_type4053 == b._ca_street_type4053) && (a._ca_suite_number4054 == b._ca_suite_number4054) && (a._ca_city4055 < b._ca_city4055)) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 == b._c_salutation7) && (a._c_first_name8 == b._c_first_name8) && (a._c_last_name9 == b._c_last_name9) && (a._ca_street_number4051 == b._ca_street_number4051) && (a._ca_street_name4052 == b._ca_street_name4052) && (a._ca_street_type4053 == b._ca_street_type4053) && (a._ca_suite_number4054 == b._ca_suite_number4054) && (a._ca_city4055 == b._ca_city4055) && (a._ca_county4056 < b._ca_county4056)) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 == b._c_salutation7) && (a._c_first_name8 == b._c_first_name8) && (a._c_last_name9 == b._c_last_name9) && (a._ca_street_number4051 == b._ca_street_number4051) && (a._ca_street_name4052 == b._ca_street_name4052) && (a._ca_street_type4053 == b._ca_street_type4053) && (a._ca_suite_number4054 == b._ca_suite_number4054) && (a._ca_city4055 == b._ca_city4055) && (a._ca_county4056 == b._ca_county4056) && (a._ca_state4057 < b._ca_state4057)) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 == b._c_salutation7) && (a._c_first_name8 == b._c_first_name8) && (a._c_last_name9 == b._c_last_name9) && (a._ca_street_number4051 == b._ca_street_number4051) && (a._ca_street_name4052 == b._ca_street_name4052) && (a._ca_street_type4053 == b._ca_street_type4053) && (a._ca_suite_number4054 == b._ca_suite_number4054) && (a._ca_city4055 == b._ca_city4055) && (a._ca_county4056 == b._ca_county4056) && (a._ca_state4057 == b._ca_state4057) && (a._ca_zip4058 < b._ca_zip4058)) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 == b._c_salutation7) && (a._c_first_name8 == b._c_first_name8) && (a._c_last_name9 == b._c_last_name9) && (a._ca_street_number4051 == b._ca_street_number4051) && (a._ca_street_name4052 == b._ca_street_name4052) && (a._ca_street_type4053 == b._ca_street_type4053) && (a._ca_suite_number4054 == b._ca_suite_number4054) && (a._ca_city4055 == b._ca_city4055) && (a._ca_county4056 == b._ca_county4056) && (a._ca_state4057 == b._ca_state4057) && (a._ca_zip4058 == b._ca_zip4058) && (a._ca_country4059 < b._ca_country4059)) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 == b._c_salutation7) && (a._c_first_name8 == b._c_first_name8) && (a._c_last_name9 == b._c_last_name9) && (a._ca_street_number4051 == b._ca_street_number4051) && (a._ca_street_name4052 == b._ca_street_name4052) && (a._ca_street_type4053 == b._ca_street_type4053) && (a._ca_suite_number4054 == b._ca_suite_number4054) && (a._ca_city4055 == b._ca_city4055) && (a._ca_county4056 == b._ca_county4056) && (a._ca_state4057 == b._ca_state4057) && (a._ca_zip4058 == b._ca_zip4058) && (a._ca_country4059 == b._ca_country4059) && (a._ca_gmt_offset4060 < b._ca_gmt_offset4060)) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 == b._c_salutation7) && (a._c_first_name8 == b._c_first_name8) && (a._c_last_name9 == b._c_last_name9) && (a._ca_street_number4051 == b._ca_street_number4051) && (a._ca_street_name4052 == b._ca_street_name4052) && (a._ca_street_type4053 == b._ca_street_type4053) && (a._ca_suite_number4054 == b._ca_suite_number4054) && (a._ca_city4055 == b._ca_city4055) && (a._ca_county4056 == b._ca_county4056) && (a._ca_state4057 == b._ca_state4057) && (a._ca_zip4058 == b._ca_zip4058) && (a._ca_country4059 == b._ca_country4059) && (a._ca_gmt_offset4060 == b._ca_gmt_offset4060) && (a._ca_location_type4061 < b._ca_location_type4061)) || 
 ((a._c_customer_id1 == b._c_customer_id1) && (a._c_salutation7 == b._c_salutation7) && (a._c_first_name8 == b._c_first_name8) && (a._c_last_name9 == b._c_last_name9) && (a._ca_street_number4051 == b._ca_street_number4051) && (a._ca_street_name4052 == b._ca_street_name4052) && (a._ca_street_type4053 == b._ca_street_type4053) && (a._ca_suite_number4054 == b._ca_suite_number4054) && (a._ca_city4055 == b._ca_city4055) && (a._ca_county4056 == b._ca_county4056) && (a._ca_state4057 == b._ca_state4057) && (a._ca_zip4058 == b._ca_zip4058) && (a._ca_country4059 == b._ca_country4059) && (a._ca_gmt_offset4060 == b._ca_gmt_offset4060) && (a._ca_location_type4061 == b._ca_location_type4061) && (a._ctr_total_return4048 < b._ctr_total_return4048)); 
}
    }SW_Sort_TD_2924774_order; 

    int nrow1 = tbl_JOIN_INNER_TD_3236528_output.getNumRow();
    std::vector<SW_Sort_TD_2924774Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1 = tbl_JOIN_INNER_TD_3236528_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_salutation7 = tbl_JOIN_INNER_TD_3236528_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8 = tbl_JOIN_INNER_TD_3236528_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9 = tbl_JOIN_INNER_TD_3236528_output.getcharN<char, TPCDS_READ_MAX +1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _ca_street_number4051 = tbl_JOIN_INNER_TD_3236528_output.getcharN<char, TPCDS_READ_MAX +1>(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _ca_street_name4052 = tbl_JOIN_INNER_TD_3236528_output.getcharN<char, TPCDS_READ_MAX +1>(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _ca_street_type4053 = tbl_JOIN_INNER_TD_3236528_output.getcharN<char, TPCDS_READ_MAX +1>(i, 6);
        std::array<char, TPCDS_READ_MAX + 1> _ca_suite_number4054 = tbl_JOIN_INNER_TD_3236528_output.getcharN<char, TPCDS_READ_MAX +1>(i, 7);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city4055 = tbl_JOIN_INNER_TD_3236528_output.getcharN<char, TPCDS_READ_MAX +1>(i, 8);
        std::array<char, TPCDS_READ_MAX + 1> _ca_county4056 = tbl_JOIN_INNER_TD_3236528_output.getcharN<char, TPCDS_READ_MAX +1>(i, 9);
        std::array<char, TPCDS_READ_MAX + 1> _ca_state4057 = tbl_JOIN_INNER_TD_3236528_output.getcharN<char, TPCDS_READ_MAX +1>(i, 10);
        std::array<char, TPCDS_READ_MAX + 1> _ca_zip4058 = tbl_JOIN_INNER_TD_3236528_output.getcharN<char, TPCDS_READ_MAX +1>(i, 11);
        std::array<char, TPCDS_READ_MAX + 1> _ca_country4059 = tbl_JOIN_INNER_TD_3236528_output.getcharN<char, TPCDS_READ_MAX +1>(i, 12);
        int64_t _ca_gmt_offset4060 = tbl_JOIN_INNER_TD_3236528_output.getInt64(i, 13);
        std::array<char, TPCDS_READ_MAX + 1> _ca_location_type4061 = tbl_JOIN_INNER_TD_3236528_output.getcharN<char, TPCDS_READ_MAX +1>(i, 14);
        int64_t _ctr_total_return4048 = tbl_JOIN_INNER_TD_3236528_output.getInt64(i, 15);
        SW_Sort_TD_2924774Row t = {std::string(_c_customer_id1.data()),std::string(_c_salutation7.data()),std::string(_c_first_name8.data()),std::string(_c_last_name9.data()),std::string(_ca_street_number4051.data()),std::string(_ca_street_name4052.data()),std::string(_ca_street_type4053.data()),std::string(_ca_suite_number4054.data()),std::string(_ca_city4055.data()),std::string(_ca_county4056.data()),std::string(_ca_state4057.data()),std::string(_ca_zip4058.data()),std::string(_ca_country4059.data()),_ca_gmt_offset4060,std::string(_ca_location_type4061.data()),_ctr_total_return4048};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2924774_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1{};
        memcpy(_c_customer_id1.data(), (it._c_customer_id1).data(), (it._c_customer_id1).length());
        tbl_Sort_TD_2924774_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _c_customer_id1);
        std::array<char, TPCDS_READ_MAX + 1> _c_salutation7{};
        memcpy(_c_salutation7.data(), (it._c_salutation7).data(), (it._c_salutation7).length());
        tbl_Sort_TD_2924774_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _c_salutation7);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8{};
        memcpy(_c_first_name8.data(), (it._c_first_name8).data(), (it._c_first_name8).length());
        tbl_Sort_TD_2924774_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _c_first_name8);
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9{};
        memcpy(_c_last_name9.data(), (it._c_last_name9).data(), (it._c_last_name9).length());
        tbl_Sort_TD_2924774_output.setcharN<char, TPCDS_READ_MAX +1>(r, 3, _c_last_name9);
        std::array<char, TPCDS_READ_MAX + 1> _ca_street_number4051{};
        memcpy(_ca_street_number4051.data(), (it._ca_street_number4051).data(), (it._ca_street_number4051).length());
        tbl_Sort_TD_2924774_output.setcharN<char, TPCDS_READ_MAX +1>(r, 4, _ca_street_number4051);
        std::array<char, TPCDS_READ_MAX + 1> _ca_street_name4052{};
        memcpy(_ca_street_name4052.data(), (it._ca_street_name4052).data(), (it._ca_street_name4052).length());
        tbl_Sort_TD_2924774_output.setcharN<char, TPCDS_READ_MAX +1>(r, 5, _ca_street_name4052);
        std::array<char, TPCDS_READ_MAX + 1> _ca_street_type4053{};
        memcpy(_ca_street_type4053.data(), (it._ca_street_type4053).data(), (it._ca_street_type4053).length());
        tbl_Sort_TD_2924774_output.setcharN<char, TPCDS_READ_MAX +1>(r, 6, _ca_street_type4053);
        std::array<char, TPCDS_READ_MAX + 1> _ca_suite_number4054{};
        memcpy(_ca_suite_number4054.data(), (it._ca_suite_number4054).data(), (it._ca_suite_number4054).length());
        tbl_Sort_TD_2924774_output.setcharN<char, TPCDS_READ_MAX +1>(r, 7, _ca_suite_number4054);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city4055{};
        memcpy(_ca_city4055.data(), (it._ca_city4055).data(), (it._ca_city4055).length());
        tbl_Sort_TD_2924774_output.setcharN<char, TPCDS_READ_MAX +1>(r, 8, _ca_city4055);
        std::array<char, TPCDS_READ_MAX + 1> _ca_county4056{};
        memcpy(_ca_county4056.data(), (it._ca_county4056).data(), (it._ca_county4056).length());
        tbl_Sort_TD_2924774_output.setcharN<char, TPCDS_READ_MAX +1>(r, 9, _ca_county4056);
        std::array<char, TPCDS_READ_MAX + 1> _ca_state4057{};
        memcpy(_ca_state4057.data(), (it._ca_state4057).data(), (it._ca_state4057).length());
        tbl_Sort_TD_2924774_output.setcharN<char, TPCDS_READ_MAX +1>(r, 10, _ca_state4057);
        std::array<char, TPCDS_READ_MAX + 1> _ca_zip4058{};
        memcpy(_ca_zip4058.data(), (it._ca_zip4058).data(), (it._ca_zip4058).length());
        tbl_Sort_TD_2924774_output.setcharN<char, TPCDS_READ_MAX +1>(r, 11, _ca_zip4058);
        std::array<char, TPCDS_READ_MAX + 1> _ca_country4059{};
        memcpy(_ca_country4059.data(), (it._ca_country4059).data(), (it._ca_country4059).length());
        tbl_Sort_TD_2924774_output.setcharN<char, TPCDS_READ_MAX +1>(r, 12, _ca_country4059);
        tbl_Sort_TD_2924774_output.setInt64(r, 13, it._ca_gmt_offset4060);
        std::array<char, TPCDS_READ_MAX + 1> _ca_location_type4061{};
        memcpy(_ca_location_type4061.data(), (it._ca_location_type4061).data(), (it._ca_location_type4061).length());
        tbl_Sort_TD_2924774_output.setcharN<char, TPCDS_READ_MAX +1>(r, 14, _ca_location_type4061);
        tbl_Sort_TD_2924774_output.setInt64(r, 15, it._ctr_total_return4048);
        if (r < 10) {
            std::cout << (it._c_customer_id1).data() << " " << (it._c_salutation7).data() << " " << (it._c_first_name8).data() << " " << (it._c_last_name9).data() << " " << (it._ca_street_number4051).data() << " " << (it._ca_street_name4052).data() << " " << (it._ca_street_type4053).data() << " " << (it._ca_suite_number4054).data() << " " << (it._ca_city4055).data() << " " << (it._ca_county4056).data() << " " << (it._ca_state4057).data() << " " << (it._ca_zip4058).data() << " " << (it._ca_country4059).data() << " " << it._ca_gmt_offset4060 << " " << (it._ca_location_type4061).data() << " " << it._ctr_total_return4048 << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_2924774_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2924774_output #Row: " << tbl_Sort_TD_2924774_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_165892(Table &tbl_Sort_TD_2924774_output, Table &tbl_LocalLimit_TD_165892_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(c_customer_id#1, c_salutation#7, c_first_name#8, c_last_name#9, ca_street_number#4051, ca_street_name#4052, ca_street_type#4053, ca_suite_number#4054, ca_city#4055, ca_county#4056, ca_state#4057, ca_zip#4058, ca_country#4059, ca_gmt_offset#4060, ca_location_type#4061, ctr_total_return#4048)
    // Output: ListBuffer(c_customer_id#1, c_salutation#7, c_first_name#8, c_last_name#9, ca_street_number#4051, ca_street_name#4052, ca_street_type#4053, ca_suite_number#4054, ca_city#4055, ca_county#4056, ca_state#4057, ca_zip#4058, ca_country#4059, ca_gmt_offset#4060, ca_location_type#4061, ctr_total_return#4048)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n = tbl_Sort_TD_2924774_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_165892_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id1_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_salutation7_n = tbl_Sort_TD_2924774_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_165892_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_salutation7_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_Sort_TD_2924774_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_LocalLimit_TD_165892_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name8_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_Sort_TD_2924774_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_LocalLimit_TD_165892_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name9_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_street_number4051_n = tbl_Sort_TD_2924774_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        tbl_LocalLimit_TD_165892_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _ca_street_number4051_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_street_name4052_n = tbl_Sort_TD_2924774_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        tbl_LocalLimit_TD_165892_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _ca_street_name4052_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_street_type4053_n = tbl_Sort_TD_2924774_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        tbl_LocalLimit_TD_165892_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _ca_street_type4053_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_suite_number4054_n = tbl_Sort_TD_2924774_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
        tbl_LocalLimit_TD_165892_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _ca_suite_number4054_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city4055_n = tbl_Sort_TD_2924774_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
        tbl_LocalLimit_TD_165892_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _ca_city4055_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_county4056_n = tbl_Sort_TD_2924774_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
        tbl_LocalLimit_TD_165892_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _ca_county4056_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_state4057_n = tbl_Sort_TD_2924774_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
        tbl_LocalLimit_TD_165892_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _ca_state4057_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_zip4058_n = tbl_Sort_TD_2924774_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
        tbl_LocalLimit_TD_165892_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _ca_zip4058_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_country4059_n = tbl_Sort_TD_2924774_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 12);
        tbl_LocalLimit_TD_165892_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _ca_country4059_n);
        tbl_LocalLimit_TD_165892_output.setInt64(r, 13, tbl_Sort_TD_2924774_output.getInt64(i, 13));
        std::array<char, TPCDS_READ_MAX + 1> _ca_location_type4061_n = tbl_Sort_TD_2924774_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 14);
        tbl_LocalLimit_TD_165892_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 14, _ca_location_type4061_n);
        tbl_LocalLimit_TD_165892_output.setInt64(r, 15, tbl_Sort_TD_2924774_output.getInt64(i, 15));
        r++;
    }
    tbl_LocalLimit_TD_165892_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_165892_output #Row: " << tbl_LocalLimit_TD_165892_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0505574(Table &tbl_LocalLimit_TD_165892_output, Table &tbl_GlobalLimit_TD_0505574_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(c_customer_id#1, c_salutation#7, c_first_name#8, c_last_name#9, ca_street_number#4051, ca_street_name#4052, ca_street_type#4053, ca_suite_number#4054, ca_city#4055, ca_county#4056, ca_state#4057, ca_zip#4058, ca_country#4059, ca_gmt_offset#4060, ca_location_type#4061, ctr_total_return#4048)
    // Output: ListBuffer(c_customer_id#1, c_salutation#7, c_first_name#8, c_last_name#9, ca_street_number#4051, ca_street_name#4052, ca_street_type#4053, ca_suite_number#4054, ca_city#4055, ca_county#4056, ca_state#4057, ca_zip#4058, ca_country#4059, ca_gmt_offset#4060, ca_location_type#4061, ctr_total_return#4048)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n = tbl_LocalLimit_TD_165892_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0505574_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id1_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_salutation7_n = tbl_LocalLimit_TD_165892_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_0505574_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_salutation7_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_LocalLimit_TD_165892_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_GlobalLimit_TD_0505574_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name8_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_LocalLimit_TD_165892_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_GlobalLimit_TD_0505574_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name9_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_street_number4051_n = tbl_LocalLimit_TD_165892_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        tbl_GlobalLimit_TD_0505574_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _ca_street_number4051_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_street_name4052_n = tbl_LocalLimit_TD_165892_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        tbl_GlobalLimit_TD_0505574_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _ca_street_name4052_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_street_type4053_n = tbl_LocalLimit_TD_165892_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        tbl_GlobalLimit_TD_0505574_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _ca_street_type4053_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_suite_number4054_n = tbl_LocalLimit_TD_165892_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
        tbl_GlobalLimit_TD_0505574_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _ca_suite_number4054_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city4055_n = tbl_LocalLimit_TD_165892_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
        tbl_GlobalLimit_TD_0505574_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _ca_city4055_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_county4056_n = tbl_LocalLimit_TD_165892_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
        tbl_GlobalLimit_TD_0505574_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _ca_county4056_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_state4057_n = tbl_LocalLimit_TD_165892_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
        tbl_GlobalLimit_TD_0505574_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _ca_state4057_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_zip4058_n = tbl_LocalLimit_TD_165892_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
        tbl_GlobalLimit_TD_0505574_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _ca_zip4058_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_country4059_n = tbl_LocalLimit_TD_165892_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 12);
        tbl_GlobalLimit_TD_0505574_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _ca_country4059_n);
        tbl_GlobalLimit_TD_0505574_output.setInt64(r, 13, tbl_LocalLimit_TD_165892_output.getInt64(i, 13));
        std::array<char, TPCDS_READ_MAX + 1> _ca_location_type4061_n = tbl_LocalLimit_TD_165892_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 14);
        tbl_GlobalLimit_TD_0505574_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 14, _ca_location_type4061_n);
        tbl_GlobalLimit_TD_0505574_output.setInt64(r, 15, tbl_LocalLimit_TD_165892_output.getInt64(i, 15));
        r++;
    }
    tbl_GlobalLimit_TD_0505574_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0505574_output #Row: " << tbl_GlobalLimit_TD_0505574_output.getNumRow() << std::endl;
}

