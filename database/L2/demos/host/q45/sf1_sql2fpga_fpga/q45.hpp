#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_10556224(Table &tbl_SerializeFromObject_TD_11394399_input, Table &tbl_Filter_TD_10556224_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(c_customer_sk#0) AND isnotnull(c_current_addr_sk#4)))
    // Input: ListBuffer(c_customer_sk#0, c_current_addr_sk#4)
    // Output: ListBuffer(c_customer_sk#0, c_current_addr_sk#4)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11394399_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk0 = tbl_SerializeFromObject_TD_11394399_input.getInt32(i, 0);
        int32_t _c_current_addr_sk4 = tbl_SerializeFromObject_TD_11394399_input.getInt32(i, 1);
        if ((_c_customer_sk0!= 0) && (_c_current_addr_sk4!= 0)) {
            int32_t _c_customer_sk0_t = tbl_SerializeFromObject_TD_11394399_input.getInt32(i, 0);
            tbl_Filter_TD_10556224_output.setInt32(r, 0, _c_customer_sk0_t);
            int32_t _c_current_addr_sk4_t = tbl_SerializeFromObject_TD_11394399_input.getInt32(i, 1);
            tbl_Filter_TD_10556224_output.setInt32(r, 1, _c_current_addr_sk4_t);
            r++;
        }
    }
    tbl_Filter_TD_10556224_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10556224_output #Row: " << tbl_Filter_TD_10556224_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10495730(Table &tbl_SerializeFromObject_TD_11463406_input, Table &tbl_Filter_TD_10495730_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_bill_customer_sk#733) AND (isnotnull(ws_sold_date_sk#729) AND isnotnull(ws_item_sk#732))))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_bill_customer_sk#733, ws_sales_price#750)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_bill_customer_sk#733, ws_sales_price#750)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11463406_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_bill_customer_sk733 = tbl_SerializeFromObject_TD_11463406_input.getInt32(i, 2);
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_11463406_input.getInt32(i, 0);
        int32_t _ws_item_sk732 = tbl_SerializeFromObject_TD_11463406_input.getInt32(i, 1);
        if ((_ws_bill_customer_sk733!= 0) && ((_ws_sold_date_sk729!= 0) && (_ws_item_sk732!= 0))) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_11463406_input.getInt32(i, 0);
            tbl_Filter_TD_10495730_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_item_sk732_t = tbl_SerializeFromObject_TD_11463406_input.getInt32(i, 1);
            tbl_Filter_TD_10495730_output.setInt32(r, 1, _ws_item_sk732_t);
            int32_t _ws_bill_customer_sk733_t = tbl_SerializeFromObject_TD_11463406_input.getInt32(i, 2);
            tbl_Filter_TD_10495730_output.setInt32(r, 2, _ws_bill_customer_sk733_t);
            int64_t _ws_sales_price750_t = tbl_SerializeFromObject_TD_11463406_input.getInt64(i, 3);
            tbl_Filter_TD_10495730_output.setInt64(r, 3, _ws_sales_price750_t);
            r++;
        }
    }
    tbl_Filter_TD_10495730_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10495730_output #Row: " << tbl_Filter_TD_10495730_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9681038(Table &tbl_SerializeFromObject_TD_10258774_input, Table &tbl_Filter_TD_9681038_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ca_address_sk#54))
    // Input: ListBuffer(ca_address_sk#54, ca_city#60, ca_zip#63)
    // Output: ListBuffer(ca_address_sk#54, ca_city#60, ca_zip#63)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10258774_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ca_address_sk54 = tbl_SerializeFromObject_TD_10258774_input.getInt32(i, 0);
        if (_ca_address_sk54!= 0) {
            int32_t _ca_address_sk54_t = tbl_SerializeFromObject_TD_10258774_input.getInt32(i, 0);
            tbl_Filter_TD_9681038_output.setInt32(r, 0, _ca_address_sk54_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_city60_t = tbl_SerializeFromObject_TD_10258774_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_9681038_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_city60_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_t = tbl_SerializeFromObject_TD_10258774_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_9681038_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_zip63_t);
            r++;
        }
    }
    tbl_Filter_TD_9681038_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9681038_output #Row: " << tbl_Filter_TD_9681038_output.getNumRow() << std::endl;
}


void SW_Filter_TD_8388173(Table &tbl_SerializeFromObject_TD_9501720_input, Table &tbl_Filter_TD_8388173_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_qoy#130) AND isnotnull(d_year#126)) AND ((d_qoy#130 = 2) AND (d_year#126 = 2001))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_qoy#130, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9501720_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_qoy130 = tbl_SerializeFromObject_TD_9501720_input.getInt32(i, 1);
        int32_t _d_year126 = tbl_SerializeFromObject_TD_9501720_input.getInt32(i, 2);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_9501720_input.getInt32(i, 0);
        if ((((_d_qoy130!= 0) && (_d_year126!= 0)) && ((_d_qoy130 == 2) && (_d_year126 == 2001))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_9501720_input.getInt32(i, 0);
            tbl_Filter_TD_8388173_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_8388173_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8388173_output #Row: " << tbl_Filter_TD_8388173_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8551704_key_leftMajor {
    int32_t _c_current_addr_sk4;
    bool operator==(const SW_JOIN_INNER_TD_8551704_key_leftMajor& other) const {
        return ((_c_current_addr_sk4 == other._c_current_addr_sk4));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8551704_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8551704_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_current_addr_sk4));
    }
};
}
struct SW_JOIN_INNER_TD_8551704_payload_leftMajor {
    int32_t _ws_sold_date_sk729;
    int32_t _ws_item_sk732;
    int64_t _ws_sales_price750;
    int32_t _c_current_addr_sk4;
};
struct SW_JOIN_INNER_TD_8551704_key_rightMajor {
    int32_t _ca_address_sk54;
    bool operator==(const SW_JOIN_INNER_TD_8551704_key_rightMajor& other) const {
        return ((_ca_address_sk54 == other._ca_address_sk54));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8551704_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8551704_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk54));
    }
};
}
struct SW_JOIN_INNER_TD_8551704_payload_rightMajor {
    int32_t _ca_address_sk54;
    std::string _ca_city60;
    std::string _ca_zip63;
};
void SW_JOIN_INNER_TD_8551704(Table &tbl_JOIN_INNER_TD_9659581_output, Table &tbl_Filter_TD_9681038_output, Table &tbl_JOIN_INNER_TD_8551704_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((c_current_addr_sk#4 = ca_address_sk#54))
    // Left Table: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_sales_price#750, c_current_addr_sk#4)
    // Right Table: ListBuffer(ca_address_sk#54, ca_city#60, ca_zip#63)
    // Output Table: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_sales_price#750, ca_city#60, ca_zip#63)
    int left_nrow = tbl_JOIN_INNER_TD_9659581_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9681038_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8551704_key_leftMajor, SW_JOIN_INNER_TD_8551704_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_9659581_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_current_addr_sk4_k = tbl_JOIN_INNER_TD_9659581_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_8551704_key_leftMajor keyA{_c_current_addr_sk4_k};
            int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_9659581_output.getInt32(i, 0);
            int32_t _ws_item_sk732 = tbl_JOIN_INNER_TD_9659581_output.getInt32(i, 1);
            int64_t _ws_sales_price750 = tbl_JOIN_INNER_TD_9659581_output.getInt64(i, 2);
            int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_9659581_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_8551704_payload_leftMajor payloadA{_ws_sold_date_sk729, _ws_item_sk732, _ws_sales_price750, _c_current_addr_sk4};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9681038_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_9681038_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8551704_key_leftMajor{_ca_address_sk54_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_date_sk729 = (it->second)._ws_sold_date_sk729;
                int32_t _ws_item_sk732 = (it->second)._ws_item_sk732;
                int64_t _ws_sales_price750 = (it->second)._ws_sales_price750;
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                int32_t _ca_address_sk54 = tbl_Filter_TD_9681038_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n = tbl_Filter_TD_9681038_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_city60 = std::string(_ca_city60_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n = tbl_Filter_TD_9681038_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _ca_zip63 = std::string(_ca_zip63_n.data());
                tbl_JOIN_INNER_TD_8551704_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_8551704_output.setInt32(r, 1, _ws_item_sk732);
                tbl_JOIN_INNER_TD_8551704_output.setInt64(r, 2, _ws_sales_price750);
                tbl_JOIN_INNER_TD_8551704_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_city60_n);
                tbl_JOIN_INNER_TD_8551704_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _ca_zip63_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8551704_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8551704_key_rightMajor, SW_JOIN_INNER_TD_8551704_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9681038_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_9681038_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8551704_key_rightMajor keyA{_ca_address_sk54_k};
            int32_t _ca_address_sk54 = tbl_Filter_TD_9681038_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n = tbl_Filter_TD_9681038_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_city60 = std::string(_ca_city60_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n = tbl_Filter_TD_9681038_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _ca_zip63 = std::string(_ca_zip63_n.data());
            SW_JOIN_INNER_TD_8551704_payload_rightMajor payloadA{_ca_address_sk54, _ca_city60, _ca_zip63};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_9659581_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_current_addr_sk4_k = tbl_JOIN_INNER_TD_9659581_output.getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8551704_key_rightMajor{_c_current_addr_sk4_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk54 = (it->second)._ca_address_sk54;
                std::string _ca_city60 = (it->second)._ca_city60;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n{};
                memcpy(_ca_city60_n.data(), (_ca_city60).data(), (_ca_city60).length());
                std::string _ca_zip63 = (it->second)._ca_zip63;
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n{};
                memcpy(_ca_zip63_n.data(), (_ca_zip63).data(), (_ca_zip63).length());
                int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_9659581_output.getInt32(i, 0);
                int32_t _ws_item_sk732 = tbl_JOIN_INNER_TD_9659581_output.getInt32(i, 1);
                int64_t _ws_sales_price750 = tbl_JOIN_INNER_TD_9659581_output.getInt64(i, 2);
                int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_9659581_output.getInt32(i, 3);
                tbl_JOIN_INNER_TD_8551704_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_city60_n);
                tbl_JOIN_INNER_TD_8551704_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _ca_zip63_n);
                tbl_JOIN_INNER_TD_8551704_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_8551704_output.setInt32(r, 1, _ws_item_sk732);
                tbl_JOIN_INNER_TD_8551704_output.setInt64(r, 2, _ws_sales_price750);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8551704_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8551704_output #Row: " << tbl_JOIN_INNER_TD_8551704_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7573511(Table &tbl_SerializeFromObject_TD_8996797_input, Table &tbl_Filter_TD_7573511_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#228))
    // Input: ListBuffer(i_item_sk#228, i_item_id#229)
    // Output: ListBuffer(i_item_sk#228, i_item_id#229)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8996797_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_8996797_input.getInt32(i, 0);
        if (_i_item_sk228!= 0) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_8996797_input.getInt32(i, 0);
            tbl_Filter_TD_7573511_output.setInt32(r, 0, _i_item_sk228_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_t = tbl_SerializeFromObject_TD_8996797_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_7573511_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id229_t);
            r++;
        }
    }
    tbl_Filter_TD_7573511_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7573511_output #Row: " << tbl_Filter_TD_7573511_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_7695168_key_leftMajor {
    int32_t _ws_sold_date_sk729;
    bool operator==(const SW_JOIN_INNER_TD_7695168_key_leftMajor& other) const {
        return ((_ws_sold_date_sk729 == other._ws_sold_date_sk729));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7695168_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7695168_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_sold_date_sk729));
    }
};
}
struct SW_JOIN_INNER_TD_7695168_payload_leftMajor {
    int32_t _ws_sold_date_sk729;
    int32_t _ws_item_sk732;
    int64_t _ws_sales_price750;
    std::string _ca_city60;
    std::string _ca_zip63;
};
struct SW_JOIN_INNER_TD_7695168_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_7695168_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7695168_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7695168_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_7695168_payload_rightMajor {
    int32_t _d_date_sk120;
};
void SW_JOIN_INNER_TD_7695168(Table &tbl_JOIN_INNER_TD_8551704_output, Table &tbl_Filter_TD_8388173_output, Table &tbl_JOIN_INNER_TD_7695168_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_sold_date_sk#729 = d_date_sk#120))
    // Left Table: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_sales_price#750, ca_city#60, ca_zip#63)
    // Right Table: ListBuffer(d_date_sk#120)
    // Output Table: ListBuffer(ws_item_sk#732, ws_sales_price#750, ca_city#60, ca_zip#63)
    int left_nrow = tbl_JOIN_INNER_TD_8551704_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8388173_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7695168_key_leftMajor, SW_JOIN_INNER_TD_7695168_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_8551704_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_sold_date_sk729_k = tbl_JOIN_INNER_TD_8551704_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7695168_key_leftMajor keyA{_ws_sold_date_sk729_k};
            int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_8551704_output.getInt32(i, 0);
            int32_t _ws_item_sk732 = tbl_JOIN_INNER_TD_8551704_output.getInt32(i, 1);
            int64_t _ws_sales_price750 = tbl_JOIN_INNER_TD_8551704_output.getInt64(i, 2);
            std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n = tbl_JOIN_INNER_TD_8551704_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _ca_city60 = std::string(_ca_city60_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n = tbl_JOIN_INNER_TD_8551704_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _ca_zip63 = std::string(_ca_zip63_n.data());
            SW_JOIN_INNER_TD_7695168_payload_leftMajor payloadA{_ws_sold_date_sk729, _ws_item_sk732, _ws_sales_price750, _ca_city60, _ca_zip63};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8388173_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_8388173_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7695168_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_date_sk729 = (it->second)._ws_sold_date_sk729;
                int32_t _ws_item_sk732 = (it->second)._ws_item_sk732;
                int64_t _ws_sales_price750 = (it->second)._ws_sales_price750;
                std::string _ca_city60 = (it->second)._ca_city60;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n{};
                memcpy(_ca_city60_n.data(), (_ca_city60).data(), (_ca_city60).length());
                std::string _ca_zip63 = (it->second)._ca_zip63;
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n{};
                memcpy(_ca_zip63_n.data(), (_ca_zip63).data(), (_ca_zip63).length());
                int32_t _d_date_sk120 = tbl_Filter_TD_8388173_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_7695168_output.setInt32(r, 0, _ws_item_sk732);
                tbl_JOIN_INNER_TD_7695168_output.setInt64(r, 1, _ws_sales_price750);
                tbl_JOIN_INNER_TD_7695168_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_city60_n);
                tbl_JOIN_INNER_TD_7695168_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_zip63_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7695168_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7695168_key_rightMajor, SW_JOIN_INNER_TD_7695168_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8388173_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_8388173_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7695168_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_8388173_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7695168_payload_rightMajor payloadA{_d_date_sk120};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_8551704_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_sold_date_sk729_k = tbl_JOIN_INNER_TD_8551704_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7695168_key_rightMajor{_ws_sold_date_sk729_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_8551704_output.getInt32(i, 0);
                int32_t _ws_item_sk732 = tbl_JOIN_INNER_TD_8551704_output.getInt32(i, 1);
                int64_t _ws_sales_price750 = tbl_JOIN_INNER_TD_8551704_output.getInt64(i, 2);
                std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n = tbl_JOIN_INNER_TD_8551704_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _ca_city60 = std::string(_ca_city60_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n = tbl_JOIN_INNER_TD_8551704_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _ca_zip63 = std::string(_ca_zip63_n.data());
                tbl_JOIN_INNER_TD_7695168_output.setInt32(r, 0, _ws_item_sk732);
                tbl_JOIN_INNER_TD_7695168_output.setInt64(r, 1, _ws_sales_price750);
                tbl_JOIN_INNER_TD_7695168_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_city60_n);
                tbl_JOIN_INNER_TD_7695168_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_zip63_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7695168_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7695168_output #Row: " << tbl_JOIN_INNER_TD_7695168_output.getNumRow() << std::endl;
}

void SW_Filter_TD_69059(Table &tbl_SerializeFromObject_TD_730314_input, Table &tbl_Filter_TD_69059_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(i_item_sk#3545 IN (2,3,5,7,11,13,17,19,23,29))
    // Input: ListBuffer(i_item_id#3546, i_item_sk#3545)
    // Output: ListBuffer(i_item_id#3546)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_730314_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk3545 = tbl_SerializeFromObject_TD_730314_input.getInt32(i, 1);
        auto reuse_col_str_251 = _i_item_sk3545;
        if ((reuse_col_str_251 == 2) || (reuse_col_str_251 == 3) || (reuse_col_str_251 == 5) || (reuse_col_str_251 == 7) || (reuse_col_str_251 == 11) || (reuse_col_str_251 == 13) || (reuse_col_str_251 == 17) || (reuse_col_str_251 == 19) || (reuse_col_str_251 == 23) || (reuse_col_str_251 == 29) || (0)) {
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id3546_t = tbl_SerializeFromObject_TD_730314_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            tbl_Filter_TD_69059_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id3546_t);
            r++;
        }
    }
    tbl_Filter_TD_69059_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_69059_output #Row: " << tbl_Filter_TD_69059_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6781537_key_leftMajor {
    int32_t _ws_item_sk732;
    bool operator==(const SW_JOIN_INNER_TD_6781537_key_leftMajor& other) const {
        return ((_ws_item_sk732 == other._ws_item_sk732));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6781537_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6781537_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_item_sk732));
    }
};
}
struct SW_JOIN_INNER_TD_6781537_payload_leftMajor {
    int32_t _ws_item_sk732;
    int64_t _ws_sales_price750;
    std::string _ca_city60;
    std::string _ca_zip63;
};
struct SW_JOIN_INNER_TD_6781537_key_rightMajor {
    int32_t _i_item_sk228;
    bool operator==(const SW_JOIN_INNER_TD_6781537_key_rightMajor& other) const {
        return ((_i_item_sk228 == other._i_item_sk228));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6781537_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6781537_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk228));
    }
};
}
struct SW_JOIN_INNER_TD_6781537_payload_rightMajor {
    int32_t _i_item_sk228;
    std::string _i_item_id229;
};
void SW_JOIN_INNER_TD_6781537(Table &tbl_JOIN_INNER_TD_7695168_output, Table &tbl_Filter_TD_7573511_output, Table &tbl_JOIN_INNER_TD_6781537_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_item_sk#732 = i_item_sk#228))
    // Left Table: ListBuffer(ws_item_sk#732, ws_sales_price#750, ca_city#60, ca_zip#63)
    // Right Table: ListBuffer(i_item_sk#228, i_item_id#229)
    // Output Table: ListBuffer(ws_sales_price#750, ca_city#60, ca_zip#63, i_item_id#229)
    int left_nrow = tbl_JOIN_INNER_TD_7695168_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7573511_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6781537_key_leftMajor, SW_JOIN_INNER_TD_6781537_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7695168_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_item_sk732_k = tbl_JOIN_INNER_TD_7695168_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6781537_key_leftMajor keyA{_ws_item_sk732_k};
            int32_t _ws_item_sk732 = tbl_JOIN_INNER_TD_7695168_output.getInt32(i, 0);
            int64_t _ws_sales_price750 = tbl_JOIN_INNER_TD_7695168_output.getInt64(i, 1);
            std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n = tbl_JOIN_INNER_TD_7695168_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _ca_city60 = std::string(_ca_city60_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n = tbl_JOIN_INNER_TD_7695168_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _ca_zip63 = std::string(_ca_zip63_n.data());
            SW_JOIN_INNER_TD_6781537_payload_leftMajor payloadA{_ws_item_sk732, _ws_sales_price750, _ca_city60, _ca_zip63};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7573511_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_7573511_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6781537_key_leftMajor{_i_item_sk228_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_item_sk732 = (it->second)._ws_item_sk732;
                int64_t _ws_sales_price750 = (it->second)._ws_sales_price750;
                std::string _ca_city60 = (it->second)._ca_city60;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n{};
                memcpy(_ca_city60_n.data(), (_ca_city60).data(), (_ca_city60).length());
                std::string _ca_zip63 = (it->second)._ca_zip63;
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n{};
                memcpy(_ca_zip63_n.data(), (_ca_zip63).data(), (_ca_zip63).length());
                int32_t _i_item_sk228 = tbl_Filter_TD_7573511_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_Filter_TD_7573511_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_item_id229 = std::string(_i_item_id229_n.data());
                tbl_JOIN_INNER_TD_6781537_output.setInt64(r, 0, _ws_sales_price750);
                tbl_JOIN_INNER_TD_6781537_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_city60_n);
                tbl_JOIN_INNER_TD_6781537_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_zip63_n);
                tbl_JOIN_INNER_TD_6781537_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _i_item_id229_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6781537_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6781537_key_rightMajor, SW_JOIN_INNER_TD_6781537_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7573511_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_7573511_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6781537_key_rightMajor keyA{_i_item_sk228_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_7573511_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_Filter_TD_7573511_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_item_id229 = std::string(_i_item_id229_n.data());
            SW_JOIN_INNER_TD_6781537_payload_rightMajor payloadA{_i_item_sk228, _i_item_id229};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7695168_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_item_sk732_k = tbl_JOIN_INNER_TD_7695168_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6781537_key_rightMajor{_ws_item_sk732_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                std::string _i_item_id229 = (it->second)._i_item_id229;
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n{};
                memcpy(_i_item_id229_n.data(), (_i_item_id229).data(), (_i_item_id229).length());
                int32_t _ws_item_sk732 = tbl_JOIN_INNER_TD_7695168_output.getInt32(i, 0);
                int64_t _ws_sales_price750 = tbl_JOIN_INNER_TD_7695168_output.getInt64(i, 1);
                std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n = tbl_JOIN_INNER_TD_7695168_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _ca_city60 = std::string(_ca_city60_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n = tbl_JOIN_INNER_TD_7695168_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _ca_zip63 = std::string(_ca_zip63_n.data());
                tbl_JOIN_INNER_TD_6781537_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _i_item_id229_n);
                tbl_JOIN_INNER_TD_6781537_output.setInt64(r, 0, _ws_sales_price750);
                tbl_JOIN_INNER_TD_6781537_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_city60_n);
                tbl_JOIN_INNER_TD_6781537_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_zip63_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6781537_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6781537_output #Row: " << tbl_JOIN_INNER_TD_6781537_output.getNumRow() << std::endl;
}

struct SW_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_key_leftMajor {
    std::string _i_item_id229;
    bool operator==(const SW_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_key_leftMajor& other) const {
        return ((_i_item_id229 == other._i_item_id229));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_item_id229));
    }
};
}
struct SW_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_payload_leftMajor {
    int64_t _ws_sales_price750;
    std::string _ca_city60;
    std::string _ca_zip63;
    std::string _i_item_id229;
};
struct SW_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_key_rightMajor {
    std::string _i_item_id3546;
    bool operator==(const SW_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_key_rightMajor& other) const {
        return ((_i_item_id3546 == other._i_item_id3546));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_item_id3546));
    }
};
}
struct SW_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_payload_rightMajor {
    std::string _i_item_id3546;
};
void SW_JOIN_EXISTENCEJOINEXISTS3600_TD_587761(Table &tbl_JOIN_INNER_TD_6781537_output, Table &tbl_Filter_TD_69059_output, Table &tbl_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_EXISTENCEJOINEXISTS3600
    // Operation: ListBuffer((i_item_id#229 = i_item_id#3546))
    // Left Table: ListBuffer(ws_sales_price#750, ca_city#60, ca_zip#63, i_item_id#229)
    // Right Table: ListBuffer(i_item_id#3546)
    // Output Table: ListBuffer(ws_sales_price#750, ca_city#60, ca_zip#63, exists#3600)
    int left_nrow = tbl_JOIN_INNER_TD_6781537_output.getNumRow();
    int right_nrow = tbl_Filter_TD_69059_output.getNumRow();
    std::unordered_map<SW_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_key_rightMajor, SW_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_payload_rightMajor> ht1;
    int nrow1 = tbl_Filter_TD_69059_output.getNumRow();
    int nrow2 = tbl_JOIN_INNER_TD_6781537_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id3546_k_n = tbl_Filter_TD_69059_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::string _i_item_id3546_k = std::string(_i_item_id3546_k_n.data());
        SW_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_key_rightMajor keyA{_i_item_id3546_k};
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id3546_n = tbl_Filter_TD_69059_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::string _i_item_id3546 = std::string(_i_item_id3546_n.data());
        SW_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_payload_rightMajor payloadA{_i_item_id3546};
        ht1.insert(std::make_pair(keyA, payloadA));
    }
    int r = 0;
    for (int i = 0; i < nrow2; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_k_n = tbl_JOIN_INNER_TD_6781537_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        std::string _i_item_id229_k = std::string(_i_item_id229_k_n.data());
        auto it = ht1.find(SW_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_key_rightMajor{_i_item_id229_k});
        if (it != ht1.end()) {
            int64_t _ws_sales_price750 = tbl_JOIN_INNER_TD_6781537_output.getInt64(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_city60 = tbl_JOIN_INNER_TD_6781537_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip63 = tbl_JOIN_INNER_TD_6781537_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id229 = tbl_JOIN_INNER_TD_6781537_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_output.setInt64(r, 0, _ws_sales_price750);
            tbl_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_city60);
            tbl_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_zip63);
            tbl_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_output.setInt32(r, 3, 1);
            r++;
        }
    }
    tbl_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_output.setNumRow(r);
    std::cout << "tbl_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_output #Row: " << tbl_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_output.getNumRow() << std::endl;
}

void SW_Filter_TD_4910441(Table &tbl_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_output, Table &tbl_Filter_TD_4910441_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((substr(ca_zip#63, 1, 5) IN (85669,86197,88274,83405,86475,85392,85460,80348,81792) OR exists#3600))
    // Input: ListBuffer(ws_sales_price#750, ca_city#60, ca_zip#63, exists#3600)
    // Output: ListBuffer(ws_sales_price#750, ca_city#60, ca_zip#63)
    int r = 0;
    int nrow1 = tbl_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_zip63 = tbl_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        int32_t _exists3600 = tbl_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_output.getInt32(i, 3);
        auto reuse_col_str_188 = std::string(_ca_zip63.data()).substr(0, 5);
        if (((reuse_col_str_188 == "85669") || (reuse_col_str_188 == "86197") || (reuse_col_str_188 == "88274") || (reuse_col_str_188 == "83405") || (reuse_col_str_188 == "86475") || (reuse_col_str_188 == "85392") || (reuse_col_str_188 == "85460") || (reuse_col_str_188 == "80348") || (reuse_col_str_188 == "81792") || (0)) || _exists3600) {
            int64_t _ws_sales_price750_t = tbl_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_output.getInt64(i, 0);
            tbl_Filter_TD_4910441_output.setInt64(r, 0, _ws_sales_price750_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_city60_t = tbl_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_4910441_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_city60_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_t = tbl_JOIN_EXISTENCEJOINEXISTS3600_TD_587761_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_4910441_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_zip63_t);
            r++;
        }
    }
    tbl_Filter_TD_4910441_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4910441_output #Row: " << tbl_Filter_TD_4910441_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_3887165_key {
    std::string _ca_zip63;
    std::string _ca_city60;
    bool operator==(const SW_Aggregate_TD_3887165_key& other) const { return (_ca_zip63 == other._ca_zip63) && (_ca_city60 == other._ca_city60); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_3887165_key> {
    std::size_t operator() (const SW_Aggregate_TD_3887165_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._ca_zip63)) + (hash<string>()(k._ca_city60));
    }
};
}
struct SW_Aggregate_TD_3887165_payload {
    int64_t _sumws_sales_price3568_sum_0;
};
void SW_Aggregate_TD_3887165(Table &tbl_Filter_TD_4910441_output, Table &tbl_Aggregate_TD_3887165_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(ca_zip#63, ca_city#60, MakeDecimal(sum(UnscaledValue(ws_sales_price#750)),17,2) AS sum(ws_sales_price)#3568)
    // Input: ListBuffer(ws_sales_price#750, ca_city#60, ca_zip#63)
    // Output: ListBuffer(ca_zip#63, ca_city#60, sum(ws_sales_price)#3568)
    std::unordered_map<SW_Aggregate_TD_3887165_key, SW_Aggregate_TD_3887165_payload> ht1;
    int nrow1 = tbl_Filter_TD_4910441_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ws_sales_price750 = tbl_Filter_TD_4910441_output.getInt64(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city60 = tbl_Filter_TD_4910441_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _ca_zip63 = tbl_Filter_TD_4910441_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        SW_Aggregate_TD_3887165_key k{std::string(_ca_zip63.data()), std::string(_ca_city60.data())};
        int64_t _sumws_sales_price3568_sum_0 = _ws_sales_price750;
        SW_Aggregate_TD_3887165_payload p{_sumws_sales_price3568_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._sumws_sales_price3568_sum_0 + _sumws_sales_price3568_sum_0;
            p._sumws_sales_price3568_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_zip63{};
        memcpy(_ca_zip63.data(), ((it.first)._ca_zip63).data(), ((it.first)._ca_zip63).length());
        tbl_Aggregate_TD_3887165_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_zip63);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city60{};
        memcpy(_ca_city60.data(), ((it.first)._ca_city60).data(), ((it.first)._ca_city60).length());
        tbl_Aggregate_TD_3887165_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_city60);
        int64_t _sumws_sales_price3568 = (it.second)._sumws_sales_price3568_sum_0;
        tbl_Aggregate_TD_3887165_output.setInt64(r, 2, _sumws_sales_price3568);
        ++r;
    }
    tbl_Aggregate_TD_3887165_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_3887165_output #Row: " << tbl_Aggregate_TD_3887165_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2655674(Table &tbl_Aggregate_TD_3887165_output, Table &tbl_Sort_TD_2655674_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(ca_zip#63 ASC NULLS FIRST, ca_city#60 ASC NULLS FIRST)
    // Input: ListBuffer(ca_zip#63, ca_city#60, sum(ws_sales_price)#3568)
    // Output: ListBuffer(ca_zip#63, ca_city#60, sum(ws_sales_price)#3568)
    struct SW_Sort_TD_2655674Row {
        std::string _ca_zip63;
        std::string _ca_city60;
        int64_t _sumws_sales_price3568;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2655674Row& a, const SW_Sort_TD_2655674Row& b) const { return 
 (a._ca_zip63 < b._ca_zip63) || 
 ((a._ca_zip63 == b._ca_zip63) && (a._ca_city60 < b._ca_city60)); 
}
    }SW_Sort_TD_2655674_order; 

    int nrow1 = tbl_Aggregate_TD_3887165_output.getNumRow();
    std::vector<SW_Sort_TD_2655674Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_zip63 = tbl_Aggregate_TD_3887165_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city60 = tbl_Aggregate_TD_3887165_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        int64_t _sumws_sales_price3568 = tbl_Aggregate_TD_3887165_output.getInt64(i, 2);
        SW_Sort_TD_2655674Row t = {std::string(_ca_zip63.data()),std::string(_ca_city60.data()),_sumws_sales_price3568};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2655674_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_zip63{};
        memcpy(_ca_zip63.data(), (it._ca_zip63).data(), (it._ca_zip63).length());
        tbl_Sort_TD_2655674_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _ca_zip63);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city60{};
        memcpy(_ca_city60.data(), (it._ca_city60).data(), (it._ca_city60).length());
        tbl_Sort_TD_2655674_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _ca_city60);
        tbl_Sort_TD_2655674_output.setInt64(r, 2, it._sumws_sales_price3568);
        ++r;
    }
    tbl_Sort_TD_2655674_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2655674_output #Row: " << tbl_Sort_TD_2655674_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1210851(Table &tbl_Sort_TD_2655674_output, Table &tbl_LocalLimit_TD_1210851_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(ca_zip#63, ca_city#60, sum(ws_sales_price)#3568)
    // Output: ListBuffer(ca_zip#63, ca_city#60, sum(ws_sales_price)#3568)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n = tbl_Sort_TD_2655674_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1210851_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_zip63_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n = tbl_Sort_TD_2655674_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_1210851_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_city60_n);
        tbl_LocalLimit_TD_1210851_output.setInt64(r, 2, tbl_Sort_TD_2655674_output.getInt64(i, 2));
        r++;
    }
    tbl_LocalLimit_TD_1210851_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1210851_output #Row: " << tbl_LocalLimit_TD_1210851_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0622700(Table &tbl_LocalLimit_TD_1210851_output, Table &tbl_GlobalLimit_TD_0622700_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(ca_zip#63, ca_city#60, sum(ws_sales_price)#3568)
    // Output: ListBuffer(ca_zip#63, ca_city#60, sum(ws_sales_price)#3568)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n = tbl_LocalLimit_TD_1210851_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0622700_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_zip63_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n = tbl_LocalLimit_TD_1210851_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_0622700_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_city60_n);
        tbl_GlobalLimit_TD_0622700_output.setInt64(r, 2, tbl_LocalLimit_TD_1210851_output.getInt64(i, 2));
        r++;
    }
    tbl_GlobalLimit_TD_0622700_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0622700_output #Row: " << tbl_GlobalLimit_TD_0622700_output.getNumRow() << std::endl;
}

