#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_10589704(Table &tbl_SerializeFromObject_TD_11967105_input, Table &tbl_Filter_TD_10589704_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((d_dow#127 IN (6,0) AND d_year#126 IN (1999,2000,2001)) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_dow#127, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11967105_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_dow127 = tbl_SerializeFromObject_TD_11967105_input.getInt32(i, 1);
        int32_t _d_year126 = tbl_SerializeFromObject_TD_11967105_input.getInt32(i, 2);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_11967105_input.getInt32(i, 0);
        auto reuse_col_str_56 = _d_dow127;
        auto reuse_col_str_874 = _d_year126;
        if ((((reuse_col_str_56 == 6) || (reuse_col_str_56 == 0) || (0)) && ((reuse_col_str_874 == 1999) || (reuse_col_str_874 == 2000) || (reuse_col_str_874 == 2001) || (0))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_11967105_input.getInt32(i, 0);
            tbl_Filter_TD_10589704_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_10589704_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10589704_output #Row: " << tbl_Filter_TD_10589704_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10331539(Table &tbl_SerializeFromObject_TD_11663159_input, Table &tbl_Filter_TD_10331539_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ss_sold_date_sk#1206) AND isnotnull(ss_store_sk#1213)) AND ((isnotnull(ss_hdemo_sk#1211) AND isnotnull(ss_addr_sk#1212)) AND isnotnull(ss_customer_sk#1209))))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_customer_sk#1209, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_store_sk#1213, ss_ticket_number#1215L, ss_coupon_amt#1225, ss_net_profit#1228)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_customer_sk#1209, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_store_sk#1213, ss_ticket_number#1215L, ss_coupon_amt#1225, ss_net_profit#1228)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11663159_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_11663159_input.getInt32(i, 0);
        int32_t _ss_store_sk1213 = tbl_SerializeFromObject_TD_11663159_input.getInt32(i, 4);
        int32_t _ss_hdemo_sk1211 = tbl_SerializeFromObject_TD_11663159_input.getInt32(i, 2);
        int32_t _ss_addr_sk1212 = tbl_SerializeFromObject_TD_11663159_input.getInt32(i, 3);
        int32_t _ss_customer_sk1209 = tbl_SerializeFromObject_TD_11663159_input.getInt32(i, 1);
        if (((_ss_sold_date_sk1206!= 0) && (_ss_store_sk1213!= 0)) && (((_ss_hdemo_sk1211!= 0) && (_ss_addr_sk1212!= 0)) && (_ss_customer_sk1209!= 0))) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_11663159_input.getInt32(i, 0);
            tbl_Filter_TD_10331539_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_customer_sk1209_t = tbl_SerializeFromObject_TD_11663159_input.getInt32(i, 1);
            tbl_Filter_TD_10331539_output.setInt32(r, 1, _ss_customer_sk1209_t);
            int32_t _ss_hdemo_sk1211_t = tbl_SerializeFromObject_TD_11663159_input.getInt32(i, 2);
            tbl_Filter_TD_10331539_output.setInt32(r, 2, _ss_hdemo_sk1211_t);
            int32_t _ss_addr_sk1212_t = tbl_SerializeFromObject_TD_11663159_input.getInt32(i, 3);
            tbl_Filter_TD_10331539_output.setInt32(r, 3, _ss_addr_sk1212_t);
            int32_t _ss_store_sk1213_t = tbl_SerializeFromObject_TD_11663159_input.getInt32(i, 4);
            tbl_Filter_TD_10331539_output.setInt32(r, 4, _ss_store_sk1213_t);
            int64_t _ss_ticket_number1215L_t = tbl_SerializeFromObject_TD_11663159_input.getInt64(i, 5);
            tbl_Filter_TD_10331539_output.setInt64(r, 5, _ss_ticket_number1215L_t);
            int64_t _ss_coupon_amt1225_t = tbl_SerializeFromObject_TD_11663159_input.getInt64(i, 6);
            tbl_Filter_TD_10331539_output.setInt64(r, 6, _ss_coupon_amt1225_t);
            int64_t _ss_net_profit1228_t = tbl_SerializeFromObject_TD_11663159_input.getInt64(i, 7);
            tbl_Filter_TD_10331539_output.setInt64(r, 7, _ss_net_profit1228_t);
            r++;
        }
    }
    tbl_Filter_TD_10331539_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10331539_output #Row: " << tbl_Filter_TD_10331539_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9798814(Table &tbl_SerializeFromObject_TD_10797235_input, Table &tbl_Filter_TD_9798814_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((s_city#400 IN (Fairview,Midway) AND isnotnull(s_store_sk#378)))
    // Input: ListBuffer(s_store_sk#378, s_city#400)
    // Output: ListBuffer(s_store_sk#378)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10797235_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_city400 = tbl_SerializeFromObject_TD_10797235_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _s_store_sk378 = tbl_SerializeFromObject_TD_10797235_input.getInt32(i, 0);
        auto reuse_col_str_307 = std::string(_s_city400.data());
        if (((reuse_col_str_307 == "Fairview") || (reuse_col_str_307 == "Midway") || (0)) && (_s_store_sk378!= 0)) {
            int32_t _s_store_sk378_t = tbl_SerializeFromObject_TD_10797235_input.getInt32(i, 0);
            tbl_Filter_TD_9798814_output.setInt32(r, 0, _s_store_sk378_t);
            r++;
        }
    }
    tbl_Filter_TD_9798814_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9798814_output #Row: " << tbl_Filter_TD_9798814_output.getNumRow() << std::endl;
}


void SW_Filter_TD_8926590(Table &tbl_SerializeFromObject_TD_9102889_input, Table &tbl_Filter_TD_8926590_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((hd_dep_count#207 = 4) OR (hd_vehicle_count#208 = 3)) AND isnotnull(hd_demo_sk#204)))
    // Input: ListBuffer(hd_demo_sk#204, hd_dep_count#207, hd_vehicle_count#208)
    // Output: ListBuffer(hd_demo_sk#204)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9102889_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _hd_dep_count207 = tbl_SerializeFromObject_TD_9102889_input.getInt32(i, 1);
        int32_t _hd_vehicle_count208 = tbl_SerializeFromObject_TD_9102889_input.getInt32(i, 2);
        int32_t _hd_demo_sk204 = tbl_SerializeFromObject_TD_9102889_input.getInt32(i, 0);
        if (((_hd_dep_count207 == 4) || (_hd_vehicle_count208 == 3)) && (_hd_demo_sk204!= 0)) {
            int32_t _hd_demo_sk204_t = tbl_SerializeFromObject_TD_9102889_input.getInt32(i, 0);
            tbl_Filter_TD_8926590_output.setInt32(r, 0, _hd_demo_sk204_t);
            r++;
        }
    }
    tbl_Filter_TD_8926590_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8926590_output #Row: " << tbl_Filter_TD_8926590_output.getNumRow() << std::endl;
}


void SW_Filter_TD_7114843(Table &tbl_SerializeFromObject_TD_8895912_input, Table &tbl_Filter_TD_7114843_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ca_address_sk#54) AND isnotnull(ca_city#60)))
    // Input: ListBuffer(ca_address_sk#54, ca_city#60)
    // Output: ListBuffer(ca_address_sk#54, ca_city#60)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8895912_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ca_address_sk54 = tbl_SerializeFromObject_TD_8895912_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city60 = tbl_SerializeFromObject_TD_8895912_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_ca_address_sk54!= 0) && _ca_city60.data() != "NULL") {
            int32_t _ca_address_sk54_t = tbl_SerializeFromObject_TD_8895912_input.getInt32(i, 0);
            tbl_Filter_TD_7114843_output.setInt32(r, 0, _ca_address_sk54_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_city60_t = tbl_SerializeFromObject_TD_8895912_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_7114843_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_city60_t);
            r++;
        }
    }
    tbl_Filter_TD_7114843_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7114843_output #Row: " << tbl_Filter_TD_7114843_output.getNumRow() << std::endl;
}


struct SW_JOIN_INNER_TD_629120_key_leftMajor {
    int32_t _ss_addr_sk1212;
    bool operator==(const SW_JOIN_INNER_TD_629120_key_leftMajor& other) const {
        return ((_ss_addr_sk1212 == other._ss_addr_sk1212));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_629120_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_629120_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_addr_sk1212));
    }
};
}
struct SW_JOIN_INNER_TD_629120_payload_leftMajor {
    int32_t _ss_customer_sk1209;
    int32_t _ss_addr_sk1212;
    int64_t _ss_ticket_number1215L;
    int64_t _ss_coupon_amt1225;
    int64_t _ss_net_profit1228;
};
struct SW_JOIN_INNER_TD_629120_key_rightMajor {
    int32_t _ca_address_sk54;
    bool operator==(const SW_JOIN_INNER_TD_629120_key_rightMajor& other) const {
        return ((_ca_address_sk54 == other._ca_address_sk54));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_629120_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_629120_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk54));
    }
};
}
struct SW_JOIN_INNER_TD_629120_payload_rightMajor {
    int32_t _ca_address_sk54;
    std::string _ca_city60;
};
void SW_JOIN_INNER_TD_629120(Table &tbl_JOIN_INNER_TD_7582378_output, Table &tbl_Filter_TD_7114843_output, Table &tbl_JOIN_INNER_TD_629120_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_addr_sk#1212 = ca_address_sk#54))
    // Left Table: ListBuffer(ss_customer_sk#1209, ss_addr_sk#1212, ss_ticket_number#1215L, ss_coupon_amt#1225, ss_net_profit#1228)
    // Right Table: ListBuffer(ca_address_sk#54, ca_city#60)
    // Output Table: ListBuffer(ss_customer_sk#1209, ss_addr_sk#1212, ss_ticket_number#1215L, ss_coupon_amt#1225, ss_net_profit#1228, ca_city#60)
    int left_nrow = tbl_JOIN_INNER_TD_7582378_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7114843_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_629120_key_leftMajor, SW_JOIN_INNER_TD_629120_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7582378_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_addr_sk1212_k = tbl_JOIN_INNER_TD_7582378_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_629120_key_leftMajor keyA{_ss_addr_sk1212_k};
            int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_7582378_output.getInt32(i, 0);
            int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_7582378_output.getInt32(i, 1);
            int64_t _ss_ticket_number1215L = tbl_JOIN_INNER_TD_7582378_output.getInt64(i, 2);
            int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_7582378_output.getInt64(i, 3);
            int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_7582378_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_629120_payload_leftMajor payloadA{_ss_customer_sk1209, _ss_addr_sk1212, _ss_ticket_number1215L, _ss_coupon_amt1225, _ss_net_profit1228};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7114843_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_7114843_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_629120_key_leftMajor{_ca_address_sk54_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                int32_t _ss_addr_sk1212 = (it->second)._ss_addr_sk1212;
                int64_t _ss_ticket_number1215L = (it->second)._ss_ticket_number1215L;
                int64_t _ss_coupon_amt1225 = (it->second)._ss_coupon_amt1225;
                int64_t _ss_net_profit1228 = (it->second)._ss_net_profit1228;
                int32_t _ca_address_sk54 = tbl_Filter_TD_7114843_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n = tbl_Filter_TD_7114843_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_city60 = std::string(_ca_city60_n.data());
                tbl_JOIN_INNER_TD_629120_output.setInt32(r, 0, _ss_customer_sk1209);
                tbl_JOIN_INNER_TD_629120_output.setInt32(r, 1, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_629120_output.setInt64(r, 2, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_629120_output.setInt64(r, 3, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_629120_output.setInt64(r, 4, _ss_net_profit1228);
                tbl_JOIN_INNER_TD_629120_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _ca_city60_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_629120_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_629120_key_rightMajor, SW_JOIN_INNER_TD_629120_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7114843_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_7114843_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_629120_key_rightMajor keyA{_ca_address_sk54_k};
            int32_t _ca_address_sk54 = tbl_Filter_TD_7114843_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n = tbl_Filter_TD_7114843_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_city60 = std::string(_ca_city60_n.data());
            SW_JOIN_INNER_TD_629120_payload_rightMajor payloadA{_ca_address_sk54, _ca_city60};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7582378_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_addr_sk1212_k = tbl_JOIN_INNER_TD_7582378_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_629120_key_rightMajor{_ss_addr_sk1212_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk54 = (it->second)._ca_address_sk54;
                std::string _ca_city60 = (it->second)._ca_city60;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n{};
                memcpy(_ca_city60_n.data(), (_ca_city60).data(), (_ca_city60).length());
                int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_7582378_output.getInt32(i, 0);
                int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_7582378_output.getInt32(i, 1);
                int64_t _ss_ticket_number1215L = tbl_JOIN_INNER_TD_7582378_output.getInt64(i, 2);
                int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_7582378_output.getInt64(i, 3);
                int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_7582378_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_629120_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _ca_city60_n);
                tbl_JOIN_INNER_TD_629120_output.setInt32(r, 0, _ss_customer_sk1209);
                tbl_JOIN_INNER_TD_629120_output.setInt32(r, 1, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_629120_output.setInt64(r, 2, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_629120_output.setInt64(r, 3, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_629120_output.setInt64(r, 4, _ss_net_profit1228);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_629120_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_629120_output #Row: " << tbl_JOIN_INNER_TD_629120_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5796898(Table &tbl_SerializeFromObject_TD_6969397_input, Table &tbl_Filter_TD_5796898_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(c_customer_sk#0) AND isnotnull(c_current_addr_sk#4)))
    // Input: ListBuffer(c_customer_sk#0, c_current_addr_sk#4, c_first_name#8, c_last_name#9)
    // Output: ListBuffer(c_customer_sk#0, c_current_addr_sk#4, c_first_name#8, c_last_name#9)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6969397_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk0 = tbl_SerializeFromObject_TD_6969397_input.getInt32(i, 0);
        int32_t _c_current_addr_sk4 = tbl_SerializeFromObject_TD_6969397_input.getInt32(i, 1);
        if ((_c_customer_sk0!= 0) && (_c_current_addr_sk4!= 0)) {
            int32_t _c_customer_sk0_t = tbl_SerializeFromObject_TD_6969397_input.getInt32(i, 0);
            tbl_Filter_TD_5796898_output.setInt32(r, 0, _c_customer_sk0_t);
            int32_t _c_current_addr_sk4_t = tbl_SerializeFromObject_TD_6969397_input.getInt32(i, 1);
            tbl_Filter_TD_5796898_output.setInt32(r, 1, _c_current_addr_sk4_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_t = tbl_SerializeFromObject_TD_6969397_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_5796898_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name8_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_t = tbl_SerializeFromObject_TD_6969397_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_5796898_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name9_t);
            r++;
        }
    }
    tbl_Filter_TD_5796898_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5796898_output #Row: " << tbl_Filter_TD_5796898_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_5264040_key {
    int64_t _ss_ticket_number1215L;
    int32_t _ss_customer_sk1209;
    int32_t _ss_addr_sk1212;
    std::string _ca_city60;
    bool operator==(const SW_Aggregate_TD_5264040_key& other) const { return (_ss_ticket_number1215L == other._ss_ticket_number1215L) && (_ss_customer_sk1209 == other._ss_customer_sk1209) && (_ss_addr_sk1212 == other._ss_addr_sk1212) && (_ca_city60 == other._ca_city60); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_5264040_key> {
    std::size_t operator() (const SW_Aggregate_TD_5264040_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int64_t>()(k._ss_ticket_number1215L)) + (hash<int32_t>()(k._ss_customer_sk1209)) + (hash<int32_t>()(k._ss_addr_sk1212)) + (hash<string>()(k._ca_city60));
    }
};
}
struct SW_Aggregate_TD_5264040_payload {
    std::string _bought_city3544;
    int64_t _amt3545_sum_0;
    int64_t _profit3546_sum_1;
};
void SW_Aggregate_TD_5264040(Table &tbl_JOIN_INNER_TD_629120_output, Table &tbl_Aggregate_TD_5264040_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(ss_ticket_number#1215L, ss_customer_sk#1209, ss_addr_sk#1212, ca_city#60, ca_city#60 AS bought_city#3544, MakeDecimal(sum(UnscaledValue(ss_coupon_amt#1225)),17,2) AS amt#3545, MakeDecimal(sum(UnscaledValue(ss_net_profit#1228)),17,2) AS profit#3546)
    // Input: ListBuffer(ss_customer_sk#1209, ss_addr_sk#1212, ss_ticket_number#1215L, ss_coupon_amt#1225, ss_net_profit#1228, ca_city#60)
    // Output: ListBuffer(ss_ticket_number#1215L, ss_customer_sk#1209, bought_city#3544, amt#3545, profit#3546)
    std::unordered_map<SW_Aggregate_TD_5264040_key, SW_Aggregate_TD_5264040_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_629120_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_629120_output.getInt32(i, 0);
        int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_629120_output.getInt32(i, 1);
        int64_t _ss_ticket_number1215L = tbl_JOIN_INNER_TD_629120_output.getInt64(i, 2);
        int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_629120_output.getInt64(i, 3);
        int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_629120_output.getInt64(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city60 = tbl_JOIN_INNER_TD_629120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        SW_Aggregate_TD_5264040_key k{_ss_ticket_number1215L, _ss_customer_sk1209, _ss_addr_sk1212, std::string(_ca_city60.data())};
        std::array<char, TPCDS_READ_MAX + 1> _bought_city3544 = _ca_city60;
        int64_t _amt3545_sum_0 = _ss_coupon_amt1225;
        int64_t _profit3546_sum_1 = _ss_net_profit1228;
        SW_Aggregate_TD_5264040_payload p{std::string(_bought_city3544.data()), _amt3545_sum_0, _profit3546_sum_1};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._amt3545_sum_0 + _amt3545_sum_0;
            p._amt3545_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._profit3546_sum_1 + _profit3546_sum_1;
            p._profit3546_sum_1 = sum_1;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        tbl_Aggregate_TD_5264040_output.setInt64(r, 0, (it.first)._ss_ticket_number1215L);
        tbl_Aggregate_TD_5264040_output.setInt32(r, 1, (it.first)._ss_customer_sk1209);
        // _ss_addr_sk1212 not required in the output table
        // _ca_city60 not required in the output table
        std::array<char, TPCDS_READ_MAX + 1> _bought_city3544_n{};
        memcpy(_bought_city3544_n.data(), (it.second)._bought_city3544.data(), (it.second)._bought_city3544.length());
        tbl_Aggregate_TD_5264040_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _bought_city3544_n);
        int64_t _amt3545 = (it.second)._amt3545_sum_0;
        tbl_Aggregate_TD_5264040_output.setInt64(r, 3, _amt3545);
        int64_t _profit3546 = (it.second)._profit3546_sum_1;
        tbl_Aggregate_TD_5264040_output.setInt64(r, 4, _profit3546);
        ++r;
    }
    tbl_Aggregate_TD_5264040_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_5264040_output #Row: " << tbl_Aggregate_TD_5264040_output.getNumRow() << std::endl;
}

void SW_Filter_TD_4502187(Table &tbl_SerializeFromObject_TD_5838757_input, Table &tbl_Filter_TD_4502187_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ca_address_sk#3547) AND isnotnull(ca_city#3553)))
    // Input: ListBuffer(ca_address_sk#3547, ca_city#3553)
    // Output: ListBuffer(ca_address_sk#3547, ca_city#3553)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5838757_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ca_address_sk3547 = tbl_SerializeFromObject_TD_5838757_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city3553 = tbl_SerializeFromObject_TD_5838757_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_ca_address_sk3547!= 0) && _ca_city3553.data() != "NULL") {
            int32_t _ca_address_sk3547_t = tbl_SerializeFromObject_TD_5838757_input.getInt32(i, 0);
            tbl_Filter_TD_4502187_output.setInt32(r, 0, _ca_address_sk3547_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_city3553_t = tbl_SerializeFromObject_TD_5838757_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_4502187_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_city3553_t);
            r++;
        }
    }
    tbl_Filter_TD_4502187_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4502187_output #Row: " << tbl_Filter_TD_4502187_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4588809_key_leftMajor {
    int32_t _ss_customer_sk1209;
    bool operator==(const SW_JOIN_INNER_TD_4588809_key_leftMajor& other) const {
        return ((_ss_customer_sk1209 == other._ss_customer_sk1209));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4588809_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4588809_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_customer_sk1209));
    }
};
}
struct SW_JOIN_INNER_TD_4588809_payload_leftMajor {
    int64_t _ss_ticket_number1215L;
    int32_t _ss_customer_sk1209;
    std::string _bought_city3544;
    int64_t _amt3545;
    int64_t _profit3546;
};
struct SW_JOIN_INNER_TD_4588809_key_rightMajor {
    int32_t _c_customer_sk0;
    bool operator==(const SW_JOIN_INNER_TD_4588809_key_rightMajor& other) const {
        return ((_c_customer_sk0 == other._c_customer_sk0));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4588809_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4588809_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk0));
    }
};
}
struct SW_JOIN_INNER_TD_4588809_payload_rightMajor {
    int32_t _c_customer_sk0;
    int32_t _c_current_addr_sk4;
    std::string _c_first_name8;
    std::string _c_last_name9;
};
void SW_JOIN_INNER_TD_4588809(Table &tbl_Aggregate_TD_5264040_output, Table &tbl_Filter_TD_5796898_output, Table &tbl_JOIN_INNER_TD_4588809_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_customer_sk#1209 = c_customer_sk#0))
    // Left Table: ListBuffer(ss_ticket_number#1215L, ss_customer_sk#1209, bought_city#3544, amt#3545, profit#3546)
    // Right Table: ListBuffer(c_customer_sk#0, c_current_addr_sk#4, c_first_name#8, c_last_name#9)
    // Output Table: ListBuffer(ss_ticket_number#1215L, bought_city#3544, amt#3545, profit#3546, c_current_addr_sk#4, c_first_name#8, c_last_name#9)
    int left_nrow = tbl_Aggregate_TD_5264040_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5796898_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4588809_key_leftMajor, SW_JOIN_INNER_TD_4588809_payload_leftMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_5264040_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_customer_sk1209_k = tbl_Aggregate_TD_5264040_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_4588809_key_leftMajor keyA{_ss_customer_sk1209_k};
            int64_t _ss_ticket_number1215L = tbl_Aggregate_TD_5264040_output.getInt64(i, 0);
            int32_t _ss_customer_sk1209 = tbl_Aggregate_TD_5264040_output.getInt32(i, 1);
            std::array<char, TPCDS_READ_MAX + 1> _bought_city3544_n = tbl_Aggregate_TD_5264040_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _bought_city3544 = std::string(_bought_city3544_n.data());
            int64_t _amt3545 = tbl_Aggregate_TD_5264040_output.getInt64(i, 3);
            int64_t _profit3546 = tbl_Aggregate_TD_5264040_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_4588809_payload_leftMajor payloadA{_ss_ticket_number1215L, _ss_customer_sk1209, _bought_city3544, _amt3545, _profit3546};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5796898_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_5796898_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4588809_key_leftMajor{_c_customer_sk0_k});
            auto it = its.first;
            while (it != its.second) {
                int64_t _ss_ticket_number1215L = (it->second)._ss_ticket_number1215L;
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                std::string _bought_city3544 = (it->second)._bought_city3544;
                std::array<char, TPCDS_READ_MAX + 1> _bought_city3544_n{};
                memcpy(_bought_city3544_n.data(), (_bought_city3544).data(), (_bought_city3544).length());
                int64_t _amt3545 = (it->second)._amt3545;
                int64_t _profit3546 = (it->second)._profit3546;
                int32_t _c_customer_sk0 = tbl_Filter_TD_5796898_output.getInt32(i, 0);
                int32_t _c_current_addr_sk4 = tbl_Filter_TD_5796898_output.getInt32(i, 1);
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_Filter_TD_5796898_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_first_name8 = std::string(_c_first_name8_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_Filter_TD_5796898_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_last_name9 = std::string(_c_last_name9_n.data());
                tbl_JOIN_INNER_TD_4588809_output.setInt64(r, 0, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_4588809_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _bought_city3544_n);
                tbl_JOIN_INNER_TD_4588809_output.setInt64(r, 2, _amt3545);
                tbl_JOIN_INNER_TD_4588809_output.setInt64(r, 3, _profit3546);
                tbl_JOIN_INNER_TD_4588809_output.setInt32(r, 4, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_4588809_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_first_name8_n);
                tbl_JOIN_INNER_TD_4588809_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_last_name9_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4588809_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4588809_key_rightMajor, SW_JOIN_INNER_TD_4588809_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5796898_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_5796898_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4588809_key_rightMajor keyA{_c_customer_sk0_k};
            int32_t _c_customer_sk0 = tbl_Filter_TD_5796898_output.getInt32(i, 0);
            int32_t _c_current_addr_sk4 = tbl_Filter_TD_5796898_output.getInt32(i, 1);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_Filter_TD_5796898_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_first_name8 = std::string(_c_first_name8_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_Filter_TD_5796898_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_last_name9 = std::string(_c_last_name9_n.data());
            SW_JOIN_INNER_TD_4588809_payload_rightMajor payloadA{_c_customer_sk0, _c_current_addr_sk4, _c_first_name8, _c_last_name9};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_5264040_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_customer_sk1209_k = tbl_Aggregate_TD_5264040_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4588809_key_rightMajor{_ss_customer_sk1209_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk0 = (it->second)._c_customer_sk0;
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                std::string _c_first_name8 = (it->second)._c_first_name8;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n{};
                memcpy(_c_first_name8_n.data(), (_c_first_name8).data(), (_c_first_name8).length());
                std::string _c_last_name9 = (it->second)._c_last_name9;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n{};
                memcpy(_c_last_name9_n.data(), (_c_last_name9).data(), (_c_last_name9).length());
                int64_t _ss_ticket_number1215L = tbl_Aggregate_TD_5264040_output.getInt64(i, 0);
                int32_t _ss_customer_sk1209 = tbl_Aggregate_TD_5264040_output.getInt32(i, 1);
                std::array<char, TPCDS_READ_MAX + 1> _bought_city3544_n = tbl_Aggregate_TD_5264040_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _bought_city3544 = std::string(_bought_city3544_n.data());
                int64_t _amt3545 = tbl_Aggregate_TD_5264040_output.getInt64(i, 3);
                int64_t _profit3546 = tbl_Aggregate_TD_5264040_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_4588809_output.setInt32(r, 4, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_4588809_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_first_name8_n);
                tbl_JOIN_INNER_TD_4588809_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_last_name9_n);
                tbl_JOIN_INNER_TD_4588809_output.setInt64(r, 0, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_4588809_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _bought_city3544_n);
                tbl_JOIN_INNER_TD_4588809_output.setInt64(r, 2, _amt3545);
                tbl_JOIN_INNER_TD_4588809_output.setInt64(r, 3, _profit3546);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4588809_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4588809_output #Row: " << tbl_JOIN_INNER_TD_4588809_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_3172888_key_leftMajor {
    int32_t _c_current_addr_sk4;
    std::string _bought_city3544;
    bool operator==(const SW_JOIN_INNER_TD_3172888_key_leftMajor& other) const {
        return ((_c_current_addr_sk4 == other._c_current_addr_sk4) && (_bought_city3544 == other._bought_city3544));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3172888_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3172888_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_current_addr_sk4));
    }
};
}
struct SW_JOIN_INNER_TD_3172888_payload_leftMajor {
    int64_t _ss_ticket_number1215L;
    std::string _bought_city3544;
    int64_t _amt3545;
    int64_t _profit3546;
    int32_t _c_current_addr_sk4;
    std::string _c_first_name8;
    std::string _c_last_name9;
};
struct SW_JOIN_INNER_TD_3172888_key_rightMajor {
    int32_t _ca_address_sk3547;
    std::string _ca_city3553;
    bool operator==(const SW_JOIN_INNER_TD_3172888_key_rightMajor& other) const {
        return ((_ca_address_sk3547 == other._ca_address_sk3547) && (_ca_city3553 == other._ca_city3553));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3172888_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3172888_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk3547));
    }
};
}
struct SW_JOIN_INNER_TD_3172888_payload_rightMajor {
    int32_t _ca_address_sk3547;
    std::string _ca_city3553;
};
void SW_JOIN_INNER_TD_3172888(Table &tbl_JOIN_INNER_TD_4588809_output, Table &tbl_Filter_TD_4502187_output, Table &tbl_JOIN_INNER_TD_3172888_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((c_current_addr_sk#4 = ca_address_sk#3547) AND NOT (ca_city#3553 = bought_city#3544)))
    // Left Table: ListBuffer(ss_ticket_number#1215L, bought_city#3544, amt#3545, profit#3546, c_current_addr_sk#4, c_first_name#8, c_last_name#9)
    // Right Table: ListBuffer(ca_address_sk#3547, ca_city#3553)
    // Output Table: ListBuffer(c_last_name#9, c_first_name#8, ca_city#3553, bought_city#3544, ss_ticket_number#1215L, amt#3545, profit#3546)
    int left_nrow = tbl_JOIN_INNER_TD_4588809_output.getNumRow();
    int right_nrow = tbl_Filter_TD_4502187_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3172888_key_leftMajor, SW_JOIN_INNER_TD_3172888_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_4588809_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_current_addr_sk4_k = tbl_JOIN_INNER_TD_4588809_output.getInt32(i, 4);
            std::array<char, TPCDS_READ_MAX + 1> _bought_city3544_k_n = tbl_JOIN_INNER_TD_4588809_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _bought_city3544_k = std::string(_bought_city3544_k_n.data());
            SW_JOIN_INNER_TD_3172888_key_leftMajor keyA{_c_current_addr_sk4_k, _bought_city3544_k};
            int64_t _ss_ticket_number1215L = tbl_JOIN_INNER_TD_4588809_output.getInt64(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _bought_city3544_n = tbl_JOIN_INNER_TD_4588809_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _bought_city3544 = std::string(_bought_city3544_n.data());
            int64_t _amt3545 = tbl_JOIN_INNER_TD_4588809_output.getInt64(i, 2);
            int64_t _profit3546 = tbl_JOIN_INNER_TD_4588809_output.getInt64(i, 3);
            int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_4588809_output.getInt32(i, 4);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_JOIN_INNER_TD_4588809_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _c_first_name8 = std::string(_c_first_name8_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_JOIN_INNER_TD_4588809_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _c_last_name9 = std::string(_c_last_name9_n.data());
            SW_JOIN_INNER_TD_3172888_payload_leftMajor payloadA{_ss_ticket_number1215L, _bought_city3544, _amt3545, _profit3546, _c_current_addr_sk4, _c_first_name8, _c_last_name9};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_4502187_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk3547_k = tbl_Filter_TD_4502187_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_city3553_k_n = tbl_Filter_TD_4502187_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_city3553_k = std::string(_ca_city3553_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3172888_key_leftMajor{_ca_address_sk3547_k, _ca_city3553_k});
            auto it = its.first;
            while (it != its.second) {
                int64_t _ss_ticket_number1215L = (it->second)._ss_ticket_number1215L;
                std::string _bought_city3544 = (it->second)._bought_city3544;
                std::array<char, TPCDS_READ_MAX + 1> _bought_city3544_n{};
                memcpy(_bought_city3544_n.data(), (_bought_city3544).data(), (_bought_city3544).length());
                int64_t _amt3545 = (it->second)._amt3545;
                int64_t _profit3546 = (it->second)._profit3546;
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                std::string _c_first_name8 = (it->second)._c_first_name8;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n{};
                memcpy(_c_first_name8_n.data(), (_c_first_name8).data(), (_c_first_name8).length());
                std::string _c_last_name9 = (it->second)._c_last_name9;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n{};
                memcpy(_c_last_name9_n.data(), (_c_last_name9).data(), (_c_last_name9).length());
                int32_t _ca_address_sk3547 = tbl_Filter_TD_4502187_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_city3553_n = tbl_Filter_TD_4502187_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_city3553 = std::string(_ca_city3553_n.data());
                tbl_JOIN_INNER_TD_3172888_output.setInt64(r, 4, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_3172888_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _bought_city3544_n);
                tbl_JOIN_INNER_TD_3172888_output.setInt64(r, 5, _amt3545);
                tbl_JOIN_INNER_TD_3172888_output.setInt64(r, 6, _profit3546);
                tbl_JOIN_INNER_TD_3172888_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
                tbl_JOIN_INNER_TD_3172888_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name9_n);
                tbl_JOIN_INNER_TD_3172888_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_city3553_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3172888_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3172888_key_rightMajor, SW_JOIN_INNER_TD_3172888_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_4502187_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk3547_k = tbl_Filter_TD_4502187_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_city3553_k_n = tbl_Filter_TD_4502187_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_city3553_k = std::string(_ca_city3553_k_n.data());
            SW_JOIN_INNER_TD_3172888_key_rightMajor keyA{_ca_address_sk3547_k, _ca_city3553_k};
            int32_t _ca_address_sk3547 = tbl_Filter_TD_4502187_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_city3553_n = tbl_Filter_TD_4502187_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_city3553 = std::string(_ca_city3553_n.data());
            SW_JOIN_INNER_TD_3172888_payload_rightMajor payloadA{_ca_address_sk3547, _ca_city3553};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_4588809_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_current_addr_sk4_k = tbl_JOIN_INNER_TD_4588809_output.getInt32(i, 4);
            std::array<char, TPCDS_READ_MAX + 1> _bought_city3544_k_n = tbl_JOIN_INNER_TD_4588809_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _bought_city3544_k = std::string(_bought_city3544_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3172888_key_rightMajor{_c_current_addr_sk4_k, _bought_city3544_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk3547 = (it->second)._ca_address_sk3547;
                std::string _ca_city3553 = (it->second)._ca_city3553;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city3553_n{};
                memcpy(_ca_city3553_n.data(), (_ca_city3553).data(), (_ca_city3553).length());
                int64_t _ss_ticket_number1215L = tbl_JOIN_INNER_TD_4588809_output.getInt64(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _bought_city3544_n = tbl_JOIN_INNER_TD_4588809_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _bought_city3544 = std::string(_bought_city3544_n.data());
                int64_t _amt3545 = tbl_JOIN_INNER_TD_4588809_output.getInt64(i, 2);
                int64_t _profit3546 = tbl_JOIN_INNER_TD_4588809_output.getInt64(i, 3);
                int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_4588809_output.getInt32(i, 4);
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_JOIN_INNER_TD_4588809_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _c_first_name8 = std::string(_c_first_name8_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_JOIN_INNER_TD_4588809_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _c_last_name9 = std::string(_c_last_name9_n.data());
                tbl_JOIN_INNER_TD_3172888_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_city3553_n);
                tbl_JOIN_INNER_TD_3172888_output.setInt64(r, 4, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_3172888_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _bought_city3544_n);
                tbl_JOIN_INNER_TD_3172888_output.setInt64(r, 5, _amt3545);
                tbl_JOIN_INNER_TD_3172888_output.setInt64(r, 6, _profit3546);
                tbl_JOIN_INNER_TD_3172888_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
                tbl_JOIN_INNER_TD_3172888_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name9_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3172888_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_3172888_output #Row: " << tbl_JOIN_INNER_TD_3172888_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2538629(Table &tbl_JOIN_INNER_TD_3172888_output, Table &tbl_Sort_TD_2538629_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(c_last_name#9 ASC NULLS FIRST, c_first_name#8 ASC NULLS FIRST, ca_city#3553 ASC NULLS FIRST, bought_city#3544 ASC NULLS FIRST, ss_ticket_number#1215L ASC NULLS FIRST)
    // Input: ListBuffer(c_last_name#9, c_first_name#8, ca_city#3553, bought_city#3544, ss_ticket_number#1215L, amt#3545, profit#3546)
    // Output: ListBuffer(c_last_name#9, c_first_name#8, ca_city#3553, bought_city#3544, ss_ticket_number#1215L, amt#3545, profit#3546)
    struct SW_Sort_TD_2538629Row {
        std::string _c_last_name9;
        std::string _c_first_name8;
        std::string _ca_city3553;
        std::string _bought_city3544;
        int64_t _ss_ticket_number1215L;
        int64_t _amt3545;
        int64_t _profit3546;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2538629Row& a, const SW_Sort_TD_2538629Row& b) const { return 
 (a._c_last_name9 < b._c_last_name9) || 
 ((a._c_last_name9 == b._c_last_name9) && (a._c_first_name8 < b._c_first_name8)) || 
 ((a._c_last_name9 == b._c_last_name9) && (a._c_first_name8 == b._c_first_name8) && (a._ca_city3553 < b._ca_city3553)) || 
 ((a._c_last_name9 == b._c_last_name9) && (a._c_first_name8 == b._c_first_name8) && (a._ca_city3553 == b._ca_city3553) && (a._bought_city3544 < b._bought_city3544)) || 
 ((a._c_last_name9 == b._c_last_name9) && (a._c_first_name8 == b._c_first_name8) && (a._ca_city3553 == b._ca_city3553) && (a._bought_city3544 == b._bought_city3544) && (a._ss_ticket_number1215L < b._ss_ticket_number1215L)); 
}
    }SW_Sort_TD_2538629_order; 

    int nrow1 = tbl_JOIN_INNER_TD_3172888_output.getNumRow();
    std::vector<SW_Sort_TD_2538629Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9 = tbl_JOIN_INNER_TD_3172888_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8 = tbl_JOIN_INNER_TD_3172888_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city3553 = tbl_JOIN_INNER_TD_3172888_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _bought_city3544 = tbl_JOIN_INNER_TD_3172888_output.getcharN<char, TPCDS_READ_MAX +1>(i, 3);
        int64_t _ss_ticket_number1215L = tbl_JOIN_INNER_TD_3172888_output.getInt64(i, 4);
        int64_t _amt3545 = tbl_JOIN_INNER_TD_3172888_output.getInt64(i, 5);
        int64_t _profit3546 = tbl_JOIN_INNER_TD_3172888_output.getInt64(i, 6);
        SW_Sort_TD_2538629Row t = {std::string(_c_last_name9.data()),std::string(_c_first_name8.data()),std::string(_ca_city3553.data()),std::string(_bought_city3544.data()),_ss_ticket_number1215L,_amt3545,_profit3546};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2538629_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9{};
        memcpy(_c_last_name9.data(), (it._c_last_name9).data(), (it._c_last_name9).length());
        tbl_Sort_TD_2538629_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _c_last_name9);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8{};
        memcpy(_c_first_name8.data(), (it._c_first_name8).data(), (it._c_first_name8).length());
        tbl_Sort_TD_2538629_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _c_first_name8);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city3553{};
        memcpy(_ca_city3553.data(), (it._ca_city3553).data(), (it._ca_city3553).length());
        tbl_Sort_TD_2538629_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _ca_city3553);
        std::array<char, TPCDS_READ_MAX + 1> _bought_city3544{};
        memcpy(_bought_city3544.data(), (it._bought_city3544).data(), (it._bought_city3544).length());
        tbl_Sort_TD_2538629_output.setcharN<char, TPCDS_READ_MAX +1>(r, 3, _bought_city3544);
        tbl_Sort_TD_2538629_output.setInt64(r, 4, it._ss_ticket_number1215L);
        tbl_Sort_TD_2538629_output.setInt64(r, 5, it._amt3545);
        tbl_Sort_TD_2538629_output.setInt64(r, 6, it._profit3546);
        ++r;
    }
    tbl_Sort_TD_2538629_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2538629_output #Row: " << tbl_Sort_TD_2538629_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1603446(Table &tbl_Sort_TD_2538629_output, Table &tbl_LocalLimit_TD_1603446_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(c_last_name#9, c_first_name#8, ca_city#3553, bought_city#3544, ss_ticket_number#1215L, amt#3545, profit#3546)
    // Output: ListBuffer(c_last_name#9, c_first_name#8, ca_city#3553, bought_city#3544, ss_ticket_number#1215L, amt#3545, profit#3546)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_Sort_TD_2538629_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1603446_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name9_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_Sort_TD_2538629_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_1603446_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city3553_n = tbl_Sort_TD_2538629_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_LocalLimit_TD_1603446_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_city3553_n);
        std::array<char, TPCDS_READ_MAX + 1> _bought_city3544_n = tbl_Sort_TD_2538629_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_LocalLimit_TD_1603446_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _bought_city3544_n);
        tbl_LocalLimit_TD_1603446_output.setInt64(r, 4, tbl_Sort_TD_2538629_output.getInt64(i, 4));
        tbl_LocalLimit_TD_1603446_output.setInt64(r, 5, tbl_Sort_TD_2538629_output.getInt64(i, 5));
        tbl_LocalLimit_TD_1603446_output.setInt64(r, 6, tbl_Sort_TD_2538629_output.getInt64(i, 6));
        r++;
    }
    tbl_LocalLimit_TD_1603446_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1603446_output #Row: " << tbl_LocalLimit_TD_1603446_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0407832(Table &tbl_LocalLimit_TD_1603446_output, Table &tbl_GlobalLimit_TD_0407832_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(c_last_name#9, c_first_name#8, ca_city#3553, bought_city#3544, ss_ticket_number#1215L, amt#3545, profit#3546)
    // Output: ListBuffer(c_last_name#9, c_first_name#8, ca_city#3553, bought_city#3544, ss_ticket_number#1215L, amt#3545, profit#3546)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_LocalLimit_TD_1603446_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0407832_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name9_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_LocalLimit_TD_1603446_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_0407832_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city3553_n = tbl_LocalLimit_TD_1603446_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_GlobalLimit_TD_0407832_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_city3553_n);
        std::array<char, TPCDS_READ_MAX + 1> _bought_city3544_n = tbl_LocalLimit_TD_1603446_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_GlobalLimit_TD_0407832_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _bought_city3544_n);
        tbl_GlobalLimit_TD_0407832_output.setInt64(r, 4, tbl_LocalLimit_TD_1603446_output.getInt64(i, 4));
        tbl_GlobalLimit_TD_0407832_output.setInt64(r, 5, tbl_LocalLimit_TD_1603446_output.getInt64(i, 5));
        tbl_GlobalLimit_TD_0407832_output.setInt64(r, 6, tbl_LocalLimit_TD_1603446_output.getInt64(i, 6));
        r++;
    }
    tbl_GlobalLimit_TD_0407832_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0407832_output #Row: " << tbl_GlobalLimit_TD_0407832_output.getNumRow() << std::endl;
}

