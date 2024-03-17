#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_7472290(Table &tbl_SerializeFromObject_TD_8740244_input, Table &tbl_Filter_TD_7472290_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(c_customer_sk#0) AND isnotnull(c_current_addr_sk#4)))
    // Input: ListBuffer(c_customer_sk#0, c_current_addr_sk#4)
    // Output: ListBuffer(c_customer_sk#0, c_current_addr_sk#4)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8740244_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk0 = tbl_SerializeFromObject_TD_8740244_input.getInt32(i, 0);
        int32_t _c_current_addr_sk4 = tbl_SerializeFromObject_TD_8740244_input.getInt32(i, 1);
        if ((_c_customer_sk0!= 0) && (_c_current_addr_sk4!= 0)) {
            int32_t _c_customer_sk0_t = tbl_SerializeFromObject_TD_8740244_input.getInt32(i, 0);
            tbl_Filter_TD_7472290_output.setInt32(r, 0, _c_customer_sk0_t);
            int32_t _c_current_addr_sk4_t = tbl_SerializeFromObject_TD_8740244_input.getInt32(i, 1);
            tbl_Filter_TD_7472290_output.setInt32(r, 1, _c_current_addr_sk4_t);
            r++;
        }
    }
    tbl_Filter_TD_7472290_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7472290_output #Row: " << tbl_Filter_TD_7472290_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7147270(Table &tbl_SerializeFromObject_TD_8863912_input, Table &tbl_Filter_TD_7147270_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cs_bill_customer_sk#1107) AND isnotnull(cs_sold_date_sk#1104)))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_sales_price#1125)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_sales_price#1125)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8863912_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_bill_customer_sk1107 = tbl_SerializeFromObject_TD_8863912_input.getInt32(i, 1);
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_8863912_input.getInt32(i, 0);
        if ((_cs_bill_customer_sk1107!= 0) && (_cs_sold_date_sk1104!= 0)) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_8863912_input.getInt32(i, 0);
            tbl_Filter_TD_7147270_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int32_t _cs_bill_customer_sk1107_t = tbl_SerializeFromObject_TD_8863912_input.getInt32(i, 1);
            tbl_Filter_TD_7147270_output.setInt32(r, 1, _cs_bill_customer_sk1107_t);
            int64_t _cs_sales_price1125_t = tbl_SerializeFromObject_TD_8863912_input.getInt64(i, 2);
            tbl_Filter_TD_7147270_output.setInt64(r, 2, _cs_sales_price1125_t);
            r++;
        }
    }
    tbl_Filter_TD_7147270_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7147270_output #Row: " << tbl_Filter_TD_7147270_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6343756(Table &tbl_SerializeFromObject_TD_7788931_input, Table &tbl_Filter_TD_6343756_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ca_address_sk#54))
    // Input: ListBuffer(ca_address_sk#54, ca_state#62, ca_zip#63)
    // Output: ListBuffer(ca_address_sk#54, ca_state#62, ca_zip#63)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7788931_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ca_address_sk54 = tbl_SerializeFromObject_TD_7788931_input.getInt32(i, 0);
        if (_ca_address_sk54!= 0) {
            int32_t _ca_address_sk54_t = tbl_SerializeFromObject_TD_7788931_input.getInt32(i, 0);
            tbl_Filter_TD_6343756_output.setInt32(r, 0, _ca_address_sk54_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_t = tbl_SerializeFromObject_TD_7788931_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_6343756_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_state62_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_t = tbl_SerializeFromObject_TD_7788931_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_6343756_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_zip63_t);
            r++;
        }
    }
    tbl_Filter_TD_6343756_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6343756_output #Row: " << tbl_Filter_TD_6343756_output.getNumRow() << std::endl;
}


void SW_Filter_TD_5411451(Table &tbl_SerializeFromObject_TD_6644602_input, Table &tbl_Filter_TD_5411451_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_qoy#130) AND isnotnull(d_year#126)) AND ((d_qoy#130 = 2) AND (d_year#126 = 2001))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_qoy#130, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6644602_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_qoy130 = tbl_SerializeFromObject_TD_6644602_input.getInt32(i, 1);
        int32_t _d_year126 = tbl_SerializeFromObject_TD_6644602_input.getInt32(i, 2);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_6644602_input.getInt32(i, 0);
        if ((((_d_qoy130!= 0) && (_d_year126!= 0)) && ((_d_qoy130 == 2) && (_d_year126 == 2001))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_6644602_input.getInt32(i, 0);
            tbl_Filter_TD_5411451_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_5411451_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5411451_output #Row: " << tbl_Filter_TD_5411451_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5755369_key_leftMajor {
    int32_t _c_current_addr_sk4;
    bool operator==(const SW_JOIN_INNER_TD_5755369_key_leftMajor& other) const {
        return ((_c_current_addr_sk4 == other._c_current_addr_sk4));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5755369_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5755369_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_current_addr_sk4));
    }
};
}
struct SW_JOIN_INNER_TD_5755369_payload_leftMajor {
    int32_t _cs_sold_date_sk1104;
    int64_t _cs_sales_price1125;
    int32_t _c_current_addr_sk4;
};
struct SW_JOIN_INNER_TD_5755369_key_rightMajor {
    int32_t _ca_address_sk54;
    bool operator==(const SW_JOIN_INNER_TD_5755369_key_rightMajor& other) const {
        return ((_ca_address_sk54 == other._ca_address_sk54));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5755369_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5755369_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk54));
    }
};
}
struct SW_JOIN_INNER_TD_5755369_payload_rightMajor {
    int32_t _ca_address_sk54;
    std::string _ca_state62;
    std::string _ca_zip63;
};
void SW_JOIN_INNER_TD_5755369(Table &tbl_JOIN_INNER_TD_6478923_output, Table &tbl_Filter_TD_6343756_output, Table &tbl_JOIN_INNER_TD_5755369_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((c_current_addr_sk#4 = ca_address_sk#54) AND ((substr(ca_zip#63, 1, 5) IN (85669,86197,88274,83405,86475,85392,85460,80348,81792) OR ca_state#62 IN (CA,WA,GA)) OR (cs_sales_price#1125 > 500.00))))
    // Left Table: ListBuffer(cs_sold_date_sk#1104, cs_sales_price#1125, c_current_addr_sk#4)
    // Right Table: ListBuffer(ca_address_sk#54, ca_state#62, ca_zip#63)
    // Output Table: ListBuffer(cs_sold_date_sk#1104, cs_sales_price#1125, ca_zip#63)
    int left_nrow = tbl_JOIN_INNER_TD_6478923_output.getNumRow();
    int right_nrow = tbl_Filter_TD_6343756_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5755369_key_leftMajor, SW_JOIN_INNER_TD_5755369_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_6478923_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_current_addr_sk4_k = tbl_JOIN_INNER_TD_6478923_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_5755369_key_leftMajor keyA{_c_current_addr_sk4_k};
            int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_6478923_output.getInt32(i, 0);
            int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_6478923_output.getInt64(i, 1);
            int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_6478923_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_5755369_payload_leftMajor payloadA{_cs_sold_date_sk1104, _cs_sales_price1125, _c_current_addr_sk4};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6343756_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_6343756_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5755369_key_leftMajor{_ca_address_sk54_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk1104 = (it->second)._cs_sold_date_sk1104;
                int64_t _cs_sales_price1125 = (it->second)._cs_sales_price1125;
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                int32_t _ca_address_sk54 = tbl_Filter_TD_6343756_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_Filter_TD_6343756_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_state62 = std::string(_ca_state62_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n = tbl_Filter_TD_6343756_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _ca_zip63 = std::string(_ca_zip63_n.data());
                tbl_JOIN_INNER_TD_5755369_output.setInt32(r, 0, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_5755369_output.setInt64(r, 1, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_5755369_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_zip63_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5755369_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5755369_key_rightMajor, SW_JOIN_INNER_TD_5755369_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_6343756_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_6343756_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5755369_key_rightMajor keyA{_ca_address_sk54_k};
            int32_t _ca_address_sk54 = tbl_Filter_TD_6343756_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_Filter_TD_6343756_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_state62 = std::string(_ca_state62_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n = tbl_Filter_TD_6343756_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _ca_zip63 = std::string(_ca_zip63_n.data());
            SW_JOIN_INNER_TD_5755369_payload_rightMajor payloadA{_ca_address_sk54, _ca_state62, _ca_zip63};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_6478923_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_current_addr_sk4_k = tbl_JOIN_INNER_TD_6478923_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5755369_key_rightMajor{_c_current_addr_sk4_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk54 = (it->second)._ca_address_sk54;
                std::string _ca_state62 = (it->second)._ca_state62;
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n{};
                memcpy(_ca_state62_n.data(), (_ca_state62).data(), (_ca_state62).length());
                std::string _ca_zip63 = (it->second)._ca_zip63;
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n{};
                memcpy(_ca_zip63_n.data(), (_ca_zip63).data(), (_ca_zip63).length());
                int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_6478923_output.getInt32(i, 0);
                int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_6478923_output.getInt64(i, 1);
                int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_6478923_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_5755369_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_zip63_n);
                tbl_JOIN_INNER_TD_5755369_output.setInt32(r, 0, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_5755369_output.setInt64(r, 1, _cs_sales_price1125);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5755369_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5755369_output #Row: " << tbl_JOIN_INNER_TD_5755369_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4785895_key_leftMajor {
    int32_t _cs_sold_date_sk1104;
    bool operator==(const SW_JOIN_INNER_TD_4785895_key_leftMajor& other) const {
        return ((_cs_sold_date_sk1104 == other._cs_sold_date_sk1104));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4785895_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4785895_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_sold_date_sk1104));
    }
};
}
struct SW_JOIN_INNER_TD_4785895_payload_leftMajor {
    int32_t _cs_sold_date_sk1104;
    int64_t _cs_sales_price1125;
    std::string _ca_zip63;
};
struct SW_JOIN_INNER_TD_4785895_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_4785895_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4785895_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4785895_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_4785895_payload_rightMajor {
    int32_t _d_date_sk120;
};
void SW_JOIN_INNER_TD_4785895(Table &tbl_JOIN_INNER_TD_5755369_output, Table &tbl_Filter_TD_5411451_output, Table &tbl_JOIN_INNER_TD_4785895_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_sold_date_sk#1104 = d_date_sk#120))
    // Left Table: ListBuffer(cs_sold_date_sk#1104, cs_sales_price#1125, ca_zip#63)
    // Right Table: ListBuffer(d_date_sk#120)
    // Output Table: ListBuffer(cs_sales_price#1125, ca_zip#63)
    int left_nrow = tbl_JOIN_INNER_TD_5755369_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5411451_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4785895_key_leftMajor, SW_JOIN_INNER_TD_4785895_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_5755369_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_sold_date_sk1104_k = tbl_JOIN_INNER_TD_5755369_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4785895_key_leftMajor keyA{_cs_sold_date_sk1104_k};
            int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_5755369_output.getInt32(i, 0);
            int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_5755369_output.getInt64(i, 1);
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n = tbl_JOIN_INNER_TD_5755369_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _ca_zip63 = std::string(_ca_zip63_n.data());
            SW_JOIN_INNER_TD_4785895_payload_leftMajor payloadA{_cs_sold_date_sk1104, _cs_sales_price1125, _ca_zip63};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5411451_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_5411451_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4785895_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk1104 = (it->second)._cs_sold_date_sk1104;
                int64_t _cs_sales_price1125 = (it->second)._cs_sales_price1125;
                std::string _ca_zip63 = (it->second)._ca_zip63;
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n{};
                memcpy(_ca_zip63_n.data(), (_ca_zip63).data(), (_ca_zip63).length());
                int32_t _d_date_sk120 = tbl_Filter_TD_5411451_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_4785895_output.setInt64(r, 0, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_4785895_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_zip63_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4785895_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4785895_key_rightMajor, SW_JOIN_INNER_TD_4785895_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5411451_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_5411451_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4785895_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_5411451_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4785895_payload_rightMajor payloadA{_d_date_sk120};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_5755369_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_sold_date_sk1104_k = tbl_JOIN_INNER_TD_5755369_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4785895_key_rightMajor{_cs_sold_date_sk1104_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_5755369_output.getInt32(i, 0);
                int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_5755369_output.getInt64(i, 1);
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n = tbl_JOIN_INNER_TD_5755369_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _ca_zip63 = std::string(_ca_zip63_n.data());
                tbl_JOIN_INNER_TD_4785895_output.setInt64(r, 0, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_4785895_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_zip63_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4785895_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4785895_output #Row: " << tbl_JOIN_INNER_TD_4785895_output.getNumRow() << std::endl;
}

typedef std::string SW_Aggregate_TD_3535252_key;
struct SW_Aggregate_TD_3535252_payload {
    int64_t _sumcs_sales_price3545_sum_0;
};
void SW_Aggregate_TD_3535252(Table &tbl_JOIN_INNER_TD_4785895_output, Table &tbl_Aggregate_TD_3535252_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(ca_zip#63, MakeDecimal(sum(UnscaledValue(cs_sales_price#1125)),17,2) AS sum(cs_sales_price)#3545)
    // Input: ListBuffer(cs_sales_price#1125, ca_zip#63)
    // Output: ListBuffer(ca_zip#63, sum(cs_sales_price)#3545)
    std::unordered_map<SW_Aggregate_TD_3535252_key, SW_Aggregate_TD_3535252_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_4785895_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_4785895_output.getInt64(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _ca_zip63 = tbl_JOIN_INNER_TD_4785895_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        SW_Aggregate_TD_3535252_key k = std::string(_ca_zip63.data());
        int64_t _sumcs_sales_price3545_sum_0 = _cs_sales_price1125;
        SW_Aggregate_TD_3535252_payload p{_sumcs_sales_price3545_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._sumcs_sales_price3545_sum_0 + _sumcs_sales_price3545_sum_0;
            p._sumcs_sales_price3545_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_zip63{};
        memcpy(_ca_zip63.data(), (it.first).data(), (it.first).length());
        tbl_Aggregate_TD_3535252_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_zip63);
        int64_t _sumcs_sales_price3545 = (it.second)._sumcs_sales_price3545_sum_0;
        tbl_Aggregate_TD_3535252_output.setInt64(r, 1, _sumcs_sales_price3545);
        ++r;
    }
    tbl_Aggregate_TD_3535252_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_3535252_output #Row: " << tbl_Aggregate_TD_3535252_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2598097(Table &tbl_Aggregate_TD_3535252_output, Table &tbl_Sort_TD_2598097_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(ca_zip#63 ASC NULLS FIRST)
    // Input: ListBuffer(ca_zip#63, sum(cs_sales_price)#3545)
    // Output: ListBuffer(ca_zip#63, sum(cs_sales_price)#3545)
    struct SW_Sort_TD_2598097Row {
        std::string _ca_zip63;
        int64_t _sumcs_sales_price3545;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2598097Row& a, const SW_Sort_TD_2598097Row& b) const { return 
 (a._ca_zip63 < b._ca_zip63); 
}
    }SW_Sort_TD_2598097_order; 

    int nrow1 = tbl_Aggregate_TD_3535252_output.getNumRow();
    std::vector<SW_Sort_TD_2598097Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_zip63 = tbl_Aggregate_TD_3535252_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        int64_t _sumcs_sales_price3545 = tbl_Aggregate_TD_3535252_output.getInt64(i, 1);
        SW_Sort_TD_2598097Row t = {std::string(_ca_zip63.data()),_sumcs_sales_price3545};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2598097_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_zip63{};
        memcpy(_ca_zip63.data(), (it._ca_zip63).data(), (it._ca_zip63).length());
        tbl_Sort_TD_2598097_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _ca_zip63);
        tbl_Sort_TD_2598097_output.setInt64(r, 1, it._sumcs_sales_price3545);
        ++r;
    }
    tbl_Sort_TD_2598097_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2598097_output #Row: " << tbl_Sort_TD_2598097_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1163099(Table &tbl_Sort_TD_2598097_output, Table &tbl_LocalLimit_TD_1163099_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(ca_zip#63, sum(cs_sales_price)#3545)
    // Output: ListBuffer(ca_zip#63, sum(cs_sales_price)#3545)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n = tbl_Sort_TD_2598097_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1163099_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_zip63_n);
        tbl_LocalLimit_TD_1163099_output.setInt64(r, 1, tbl_Sort_TD_2598097_output.getInt64(i, 1));
        r++;
    }
    tbl_LocalLimit_TD_1163099_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1163099_output #Row: " << tbl_LocalLimit_TD_1163099_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0641704(Table &tbl_LocalLimit_TD_1163099_output, Table &tbl_GlobalLimit_TD_0641704_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(ca_zip#63, sum(cs_sales_price)#3545)
    // Output: ListBuffer(ca_zip#63, sum(cs_sales_price)#3545)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n = tbl_LocalLimit_TD_1163099_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0641704_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_zip63_n);
        tbl_GlobalLimit_TD_0641704_output.setInt64(r, 1, tbl_LocalLimit_TD_1163099_output.getInt64(i, 1));
        r++;
    }
    tbl_GlobalLimit_TD_0641704_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0641704_output #Row: " << tbl_GlobalLimit_TD_0641704_output.getNumRow() << std::endl;
}

