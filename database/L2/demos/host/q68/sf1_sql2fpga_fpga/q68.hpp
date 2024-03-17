#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_1023536(Table &tbl_SerializeFromObject_TD_11966388_input, Table &tbl_Filter_TD_1023536_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_dom#129) AND (((d_dom#129 >= 1) AND (d_dom#129 <= 2)) AND d_year#126 IN (1999,2000,2001))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_dom#129, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11966388_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_dom129 = tbl_SerializeFromObject_TD_11966388_input.getInt32(i, 1);
        int32_t _d_year126 = tbl_SerializeFromObject_TD_11966388_input.getInt32(i, 2);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_11966388_input.getInt32(i, 0);
        auto reuse_col_str_925 = _d_year126;
        if (((_d_dom129!= 0) && (((_d_dom129 >= 1) && (_d_dom129 <= 2)) && ((reuse_col_str_925 == 1999) || (reuse_col_str_925 == 2000) || (reuse_col_str_925 == 2001) || (0)))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_11966388_input.getInt32(i, 0);
            tbl_Filter_TD_1023536_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_1023536_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1023536_output #Row: " << tbl_Filter_TD_1023536_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10446092(Table &tbl_SerializeFromObject_TD_11792256_input, Table &tbl_Filter_TD_10446092_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ss_sold_date_sk#1206) AND isnotnull(ss_store_sk#1213)) AND ((isnotnull(ss_hdemo_sk#1211) AND isnotnull(ss_addr_sk#1212)) AND isnotnull(ss_customer_sk#1209))))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_customer_sk#1209, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_store_sk#1213, ss_ticket_number#1215L, ss_ext_sales_price#1221, ss_ext_list_price#1223, ss_ext_tax#1224)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_customer_sk#1209, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_store_sk#1213, ss_ticket_number#1215L, ss_ext_sales_price#1221, ss_ext_list_price#1223, ss_ext_tax#1224)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11792256_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_11792256_input.getInt32(i, 0);
        int32_t _ss_store_sk1213 = tbl_SerializeFromObject_TD_11792256_input.getInt32(i, 4);
        int32_t _ss_hdemo_sk1211 = tbl_SerializeFromObject_TD_11792256_input.getInt32(i, 2);
        int32_t _ss_addr_sk1212 = tbl_SerializeFromObject_TD_11792256_input.getInt32(i, 3);
        int32_t _ss_customer_sk1209 = tbl_SerializeFromObject_TD_11792256_input.getInt32(i, 1);
        if (((_ss_sold_date_sk1206!= 0) && (_ss_store_sk1213!= 0)) && (((_ss_hdemo_sk1211!= 0) && (_ss_addr_sk1212!= 0)) && (_ss_customer_sk1209!= 0))) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_11792256_input.getInt32(i, 0);
            tbl_Filter_TD_10446092_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_customer_sk1209_t = tbl_SerializeFromObject_TD_11792256_input.getInt32(i, 1);
            tbl_Filter_TD_10446092_output.setInt32(r, 1, _ss_customer_sk1209_t);
            int32_t _ss_hdemo_sk1211_t = tbl_SerializeFromObject_TD_11792256_input.getInt32(i, 2);
            tbl_Filter_TD_10446092_output.setInt32(r, 2, _ss_hdemo_sk1211_t);
            int32_t _ss_addr_sk1212_t = tbl_SerializeFromObject_TD_11792256_input.getInt32(i, 3);
            tbl_Filter_TD_10446092_output.setInt32(r, 3, _ss_addr_sk1212_t);
            int32_t _ss_store_sk1213_t = tbl_SerializeFromObject_TD_11792256_input.getInt32(i, 4);
            tbl_Filter_TD_10446092_output.setInt32(r, 4, _ss_store_sk1213_t);
            int64_t _ss_ticket_number1215L_t = tbl_SerializeFromObject_TD_11792256_input.getInt64(i, 5);
            tbl_Filter_TD_10446092_output.setInt64(r, 5, _ss_ticket_number1215L_t);
            int64_t _ss_ext_sales_price1221_t = tbl_SerializeFromObject_TD_11792256_input.getInt64(i, 6);
            tbl_Filter_TD_10446092_output.setInt64(r, 6, _ss_ext_sales_price1221_t);
            int64_t _ss_ext_list_price1223_t = tbl_SerializeFromObject_TD_11792256_input.getInt64(i, 7);
            tbl_Filter_TD_10446092_output.setInt64(r, 7, _ss_ext_list_price1223_t);
            int64_t _ss_ext_tax1224_t = tbl_SerializeFromObject_TD_11792256_input.getInt64(i, 8);
            tbl_Filter_TD_10446092_output.setInt64(r, 8, _ss_ext_tax1224_t);
            r++;
        }
    }
    tbl_Filter_TD_10446092_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10446092_output #Row: " << tbl_Filter_TD_10446092_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9289066(Table &tbl_SerializeFromObject_TD_10195679_input, Table &tbl_Filter_TD_9289066_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((s_city#400 IN (Midway,Fairview) AND isnotnull(s_store_sk#378)))
    // Input: ListBuffer(s_store_sk#378, s_city#400)
    // Output: ListBuffer(s_store_sk#378)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10195679_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_city400 = tbl_SerializeFromObject_TD_10195679_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _s_store_sk378 = tbl_SerializeFromObject_TD_10195679_input.getInt32(i, 0);
        auto reuse_col_str_621 = std::string(_s_city400.data());
        if (((reuse_col_str_621 == "Midway") || (reuse_col_str_621 == "Fairview") || (0)) && (_s_store_sk378!= 0)) {
            int32_t _s_store_sk378_t = tbl_SerializeFromObject_TD_10195679_input.getInt32(i, 0);
            tbl_Filter_TD_9289066_output.setInt32(r, 0, _s_store_sk378_t);
            r++;
        }
    }
    tbl_Filter_TD_9289066_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9289066_output #Row: " << tbl_Filter_TD_9289066_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_9401357_key_leftMajor {
    int32_t _ss_sold_date_sk1206;
    bool operator==(const SW_JOIN_INNER_TD_9401357_key_leftMajor& other) const {
        return ((_ss_sold_date_sk1206 == other._ss_sold_date_sk1206));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9401357_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9401357_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_sold_date_sk1206));
    }
};
}
struct SW_JOIN_INNER_TD_9401357_payload_leftMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_customer_sk1209;
    int32_t _ss_hdemo_sk1211;
    int32_t _ss_addr_sk1212;
    int32_t _ss_store_sk1213;
    int64_t _ss_ticket_number1215L;
    int64_t _ss_ext_sales_price1221;
    int64_t _ss_ext_list_price1223;
    int64_t _ss_ext_tax1224;
};
struct SW_JOIN_INNER_TD_9401357_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_9401357_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9401357_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9401357_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_9401357_payload_rightMajor {
    int32_t _d_date_sk120;
};
void SW_JOIN_INNER_TD_9401357(Table &tbl_Filter_TD_10446092_output, Table &tbl_Filter_TD_1023536_output, Table &tbl_JOIN_INNER_TD_9401357_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#1206 = d_date_sk#120))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_customer_sk#1209, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_store_sk#1213, ss_ticket_number#1215L, ss_ext_sales_price#1221, ss_ext_list_price#1223, ss_ext_tax#1224)
    // Right Table: ListBuffer(d_date_sk#120)
    // Output Table: ListBuffer(ss_customer_sk#1209, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_store_sk#1213, ss_ticket_number#1215L, ss_ext_sales_price#1221, ss_ext_list_price#1223, ss_ext_tax#1224)
    int left_nrow = tbl_Filter_TD_10446092_output.getNumRow();
    int right_nrow = tbl_Filter_TD_1023536_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9401357_key_leftMajor, SW_JOIN_INNER_TD_9401357_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_10446092_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_Filter_TD_10446092_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_9401357_key_leftMajor keyA{_ss_sold_date_sk1206_k};
            int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_10446092_output.getInt32(i, 0);
            int32_t _ss_customer_sk1209 = tbl_Filter_TD_10446092_output.getInt32(i, 1);
            int32_t _ss_hdemo_sk1211 = tbl_Filter_TD_10446092_output.getInt32(i, 2);
            int32_t _ss_addr_sk1212 = tbl_Filter_TD_10446092_output.getInt32(i, 3);
            int32_t _ss_store_sk1213 = tbl_Filter_TD_10446092_output.getInt32(i, 4);
            int64_t _ss_ticket_number1215L = tbl_Filter_TD_10446092_output.getInt64(i, 5);
            int64_t _ss_ext_sales_price1221 = tbl_Filter_TD_10446092_output.getInt64(i, 6);
            int64_t _ss_ext_list_price1223 = tbl_Filter_TD_10446092_output.getInt64(i, 7);
            int64_t _ss_ext_tax1224 = tbl_Filter_TD_10446092_output.getInt64(i, 8);
            SW_JOIN_INNER_TD_9401357_payload_leftMajor payloadA{_ss_sold_date_sk1206, _ss_customer_sk1209, _ss_hdemo_sk1211, _ss_addr_sk1212, _ss_store_sk1213, _ss_ticket_number1215L, _ss_ext_sales_price1221, _ss_ext_list_price1223, _ss_ext_tax1224};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_1023536_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_1023536_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9401357_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                int32_t _ss_hdemo_sk1211 = (it->second)._ss_hdemo_sk1211;
                int32_t _ss_addr_sk1212 = (it->second)._ss_addr_sk1212;
                int32_t _ss_store_sk1213 = (it->second)._ss_store_sk1213;
                int64_t _ss_ticket_number1215L = (it->second)._ss_ticket_number1215L;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int64_t _ss_ext_list_price1223 = (it->second)._ss_ext_list_price1223;
                int64_t _ss_ext_tax1224 = (it->second)._ss_ext_tax1224;
                int32_t _d_date_sk120 = tbl_Filter_TD_1023536_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_9401357_output.setInt32(r, 0, _ss_customer_sk1209);
                tbl_JOIN_INNER_TD_9401357_output.setInt32(r, 1, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_9401357_output.setInt32(r, 2, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_9401357_output.setInt32(r, 3, _ss_store_sk1213);
                tbl_JOIN_INNER_TD_9401357_output.setInt64(r, 4, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_9401357_output.setInt64(r, 5, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_9401357_output.setInt64(r, 6, _ss_ext_list_price1223);
                tbl_JOIN_INNER_TD_9401357_output.setInt64(r, 7, _ss_ext_tax1224);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9401357_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9401357_key_rightMajor, SW_JOIN_INNER_TD_9401357_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_1023536_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_1023536_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_9401357_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_1023536_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_9401357_payload_rightMajor payloadA{_d_date_sk120};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_10446092_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_Filter_TD_10446092_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9401357_key_rightMajor{_ss_sold_date_sk1206_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_10446092_output.getInt32(i, 0);
                int32_t _ss_customer_sk1209 = tbl_Filter_TD_10446092_output.getInt32(i, 1);
                int32_t _ss_hdemo_sk1211 = tbl_Filter_TD_10446092_output.getInt32(i, 2);
                int32_t _ss_addr_sk1212 = tbl_Filter_TD_10446092_output.getInt32(i, 3);
                int32_t _ss_store_sk1213 = tbl_Filter_TD_10446092_output.getInt32(i, 4);
                int64_t _ss_ticket_number1215L = tbl_Filter_TD_10446092_output.getInt64(i, 5);
                int64_t _ss_ext_sales_price1221 = tbl_Filter_TD_10446092_output.getInt64(i, 6);
                int64_t _ss_ext_list_price1223 = tbl_Filter_TD_10446092_output.getInt64(i, 7);
                int64_t _ss_ext_tax1224 = tbl_Filter_TD_10446092_output.getInt64(i, 8);
                tbl_JOIN_INNER_TD_9401357_output.setInt32(r, 0, _ss_customer_sk1209);
                tbl_JOIN_INNER_TD_9401357_output.setInt32(r, 1, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_9401357_output.setInt32(r, 2, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_9401357_output.setInt32(r, 3, _ss_store_sk1213);
                tbl_JOIN_INNER_TD_9401357_output.setInt64(r, 4, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_9401357_output.setInt64(r, 5, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_9401357_output.setInt64(r, 6, _ss_ext_list_price1223);
                tbl_JOIN_INNER_TD_9401357_output.setInt64(r, 7, _ss_ext_tax1224);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9401357_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_9401357_output #Row: " << tbl_JOIN_INNER_TD_9401357_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8869253(Table &tbl_SerializeFromObject_TD_9167176_input, Table &tbl_Filter_TD_8869253_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((hd_dep_count#207 = 4) OR (hd_vehicle_count#208 = 3)) AND isnotnull(hd_demo_sk#204)))
    // Input: ListBuffer(hd_demo_sk#204, hd_dep_count#207, hd_vehicle_count#208)
    // Output: ListBuffer(hd_demo_sk#204)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9167176_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _hd_dep_count207 = tbl_SerializeFromObject_TD_9167176_input.getInt32(i, 1);
        int32_t _hd_vehicle_count208 = tbl_SerializeFromObject_TD_9167176_input.getInt32(i, 2);
        int32_t _hd_demo_sk204 = tbl_SerializeFromObject_TD_9167176_input.getInt32(i, 0);
        if (((_hd_dep_count207 == 4) || (_hd_vehicle_count208 == 3)) && (_hd_demo_sk204!= 0)) {
            int32_t _hd_demo_sk204_t = tbl_SerializeFromObject_TD_9167176_input.getInt32(i, 0);
            tbl_Filter_TD_8869253_output.setInt32(r, 0, _hd_demo_sk204_t);
            r++;
        }
    }
    tbl_Filter_TD_8869253_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8869253_output #Row: " << tbl_Filter_TD_8869253_output.getNumRow() << std::endl;
}


void SW_Filter_TD_796679(Table &tbl_SerializeFromObject_TD_8155146_input, Table &tbl_Filter_TD_796679_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ca_address_sk#54) AND isnotnull(ca_city#60)))
    // Input: ListBuffer(ca_address_sk#54, ca_city#60)
    // Output: ListBuffer(ca_address_sk#54, ca_city#60)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8155146_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ca_address_sk54 = tbl_SerializeFromObject_TD_8155146_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city60 = tbl_SerializeFromObject_TD_8155146_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_ca_address_sk54!= 0) && _ca_city60.data() != "NULL") {
            int32_t _ca_address_sk54_t = tbl_SerializeFromObject_TD_8155146_input.getInt32(i, 0);
            tbl_Filter_TD_796679_output.setInt32(r, 0, _ca_address_sk54_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_city60_t = tbl_SerializeFromObject_TD_8155146_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_796679_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_city60_t);
            r++;
        }
    }
    tbl_Filter_TD_796679_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_796679_output #Row: " << tbl_Filter_TD_796679_output.getNumRow() << std::endl;
}


struct SW_JOIN_INNER_TD_6187048_key_leftMajor {
    int32_t _ss_addr_sk1212;
    bool operator==(const SW_JOIN_INNER_TD_6187048_key_leftMajor& other) const {
        return ((_ss_addr_sk1212 == other._ss_addr_sk1212));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6187048_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6187048_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_addr_sk1212));
    }
};
}
struct SW_JOIN_INNER_TD_6187048_payload_leftMajor {
    int32_t _ss_customer_sk1209;
    int32_t _ss_addr_sk1212;
    int64_t _ss_ticket_number1215L;
    int64_t _ss_ext_sales_price1221;
    int64_t _ss_ext_list_price1223;
    int64_t _ss_ext_tax1224;
};
struct SW_JOIN_INNER_TD_6187048_key_rightMajor {
    int32_t _ca_address_sk54;
    bool operator==(const SW_JOIN_INNER_TD_6187048_key_rightMajor& other) const {
        return ((_ca_address_sk54 == other._ca_address_sk54));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6187048_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6187048_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk54));
    }
};
}
struct SW_JOIN_INNER_TD_6187048_payload_rightMajor {
    int32_t _ca_address_sk54;
    std::string _ca_city60;
};
void SW_JOIN_INNER_TD_6187048(Table &tbl_JOIN_INNER_TD_7768905_output, Table &tbl_Filter_TD_796679_output, Table &tbl_JOIN_INNER_TD_6187048_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_addr_sk#1212 = ca_address_sk#54))
    // Left Table: ListBuffer(ss_customer_sk#1209, ss_addr_sk#1212, ss_ticket_number#1215L, ss_ext_sales_price#1221, ss_ext_list_price#1223, ss_ext_tax#1224)
    // Right Table: ListBuffer(ca_address_sk#54, ca_city#60)
    // Output Table: ListBuffer(ss_customer_sk#1209, ss_addr_sk#1212, ss_ticket_number#1215L, ss_ext_sales_price#1221, ss_ext_list_price#1223, ss_ext_tax#1224, ca_city#60)
    int left_nrow = tbl_JOIN_INNER_TD_7768905_output.getNumRow();
    int right_nrow = tbl_Filter_TD_796679_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6187048_key_leftMajor, SW_JOIN_INNER_TD_6187048_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7768905_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_addr_sk1212_k = tbl_JOIN_INNER_TD_7768905_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_6187048_key_leftMajor keyA{_ss_addr_sk1212_k};
            int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_7768905_output.getInt32(i, 0);
            int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_7768905_output.getInt32(i, 1);
            int64_t _ss_ticket_number1215L = tbl_JOIN_INNER_TD_7768905_output.getInt64(i, 2);
            int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_7768905_output.getInt64(i, 3);
            int64_t _ss_ext_list_price1223 = tbl_JOIN_INNER_TD_7768905_output.getInt64(i, 4);
            int64_t _ss_ext_tax1224 = tbl_JOIN_INNER_TD_7768905_output.getInt64(i, 5);
            SW_JOIN_INNER_TD_6187048_payload_leftMajor payloadA{_ss_customer_sk1209, _ss_addr_sk1212, _ss_ticket_number1215L, _ss_ext_sales_price1221, _ss_ext_list_price1223, _ss_ext_tax1224};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_796679_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_796679_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6187048_key_leftMajor{_ca_address_sk54_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                int32_t _ss_addr_sk1212 = (it->second)._ss_addr_sk1212;
                int64_t _ss_ticket_number1215L = (it->second)._ss_ticket_number1215L;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int64_t _ss_ext_list_price1223 = (it->second)._ss_ext_list_price1223;
                int64_t _ss_ext_tax1224 = (it->second)._ss_ext_tax1224;
                int32_t _ca_address_sk54 = tbl_Filter_TD_796679_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n = tbl_Filter_TD_796679_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_city60 = std::string(_ca_city60_n.data());
                tbl_JOIN_INNER_TD_6187048_output.setInt32(r, 0, _ss_customer_sk1209);
                tbl_JOIN_INNER_TD_6187048_output.setInt32(r, 1, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_6187048_output.setInt64(r, 2, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_6187048_output.setInt64(r, 3, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_6187048_output.setInt64(r, 4, _ss_ext_list_price1223);
                tbl_JOIN_INNER_TD_6187048_output.setInt64(r, 5, _ss_ext_tax1224);
                tbl_JOIN_INNER_TD_6187048_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _ca_city60_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6187048_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6187048_key_rightMajor, SW_JOIN_INNER_TD_6187048_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_796679_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_796679_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6187048_key_rightMajor keyA{_ca_address_sk54_k};
            int32_t _ca_address_sk54 = tbl_Filter_TD_796679_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n = tbl_Filter_TD_796679_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_city60 = std::string(_ca_city60_n.data());
            SW_JOIN_INNER_TD_6187048_payload_rightMajor payloadA{_ca_address_sk54, _ca_city60};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7768905_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_addr_sk1212_k = tbl_JOIN_INNER_TD_7768905_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6187048_key_rightMajor{_ss_addr_sk1212_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk54 = (it->second)._ca_address_sk54;
                std::string _ca_city60 = (it->second)._ca_city60;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n{};
                memcpy(_ca_city60_n.data(), (_ca_city60).data(), (_ca_city60).length());
                int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_7768905_output.getInt32(i, 0);
                int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_7768905_output.getInt32(i, 1);
                int64_t _ss_ticket_number1215L = tbl_JOIN_INNER_TD_7768905_output.getInt64(i, 2);
                int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_7768905_output.getInt64(i, 3);
                int64_t _ss_ext_list_price1223 = tbl_JOIN_INNER_TD_7768905_output.getInt64(i, 4);
                int64_t _ss_ext_tax1224 = tbl_JOIN_INNER_TD_7768905_output.getInt64(i, 5);
                tbl_JOIN_INNER_TD_6187048_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _ca_city60_n);
                tbl_JOIN_INNER_TD_6187048_output.setInt32(r, 0, _ss_customer_sk1209);
                tbl_JOIN_INNER_TD_6187048_output.setInt32(r, 1, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_6187048_output.setInt64(r, 2, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_6187048_output.setInt64(r, 3, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_6187048_output.setInt64(r, 4, _ss_ext_list_price1223);
                tbl_JOIN_INNER_TD_6187048_output.setInt64(r, 5, _ss_ext_tax1224);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6187048_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6187048_output #Row: " << tbl_JOIN_INNER_TD_6187048_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5896878(Table &tbl_SerializeFromObject_TD_663806_input, Table &tbl_Filter_TD_5896878_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(c_customer_sk#0) AND isnotnull(c_current_addr_sk#4)))
    // Input: ListBuffer(c_customer_sk#0, c_current_addr_sk#4, c_first_name#8, c_last_name#9)
    // Output: ListBuffer(c_customer_sk#0, c_current_addr_sk#4, c_first_name#8, c_last_name#9)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_663806_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk0 = tbl_SerializeFromObject_TD_663806_input.getInt32(i, 0);
        int32_t _c_current_addr_sk4 = tbl_SerializeFromObject_TD_663806_input.getInt32(i, 1);
        if ((_c_customer_sk0!= 0) && (_c_current_addr_sk4!= 0)) {
            int32_t _c_customer_sk0_t = tbl_SerializeFromObject_TD_663806_input.getInt32(i, 0);
            tbl_Filter_TD_5896878_output.setInt32(r, 0, _c_customer_sk0_t);
            int32_t _c_current_addr_sk4_t = tbl_SerializeFromObject_TD_663806_input.getInt32(i, 1);
            tbl_Filter_TD_5896878_output.setInt32(r, 1, _c_current_addr_sk4_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_t = tbl_SerializeFromObject_TD_663806_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_5896878_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name8_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_t = tbl_SerializeFromObject_TD_663806_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_5896878_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name9_t);
            r++;
        }
    }
    tbl_Filter_TD_5896878_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5896878_output #Row: " << tbl_Filter_TD_5896878_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_5312256_key {
    int64_t _ss_ticket_number1215L;
    int32_t _ss_customer_sk1209;
    int32_t _ss_addr_sk1212;
    std::string _ca_city60;
    bool operator==(const SW_Aggregate_TD_5312256_key& other) const { return (_ss_ticket_number1215L == other._ss_ticket_number1215L) && (_ss_customer_sk1209 == other._ss_customer_sk1209) && (_ss_addr_sk1212 == other._ss_addr_sk1212) && (_ca_city60 == other._ca_city60); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_5312256_key> {
    std::size_t operator() (const SW_Aggregate_TD_5312256_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int64_t>()(k._ss_ticket_number1215L)) + (hash<int32_t>()(k._ss_customer_sk1209)) + (hash<int32_t>()(k._ss_addr_sk1212)) + (hash<string>()(k._ca_city60));
    }
};
}
struct SW_Aggregate_TD_5312256_payload {
    std::string _bought_city3544;
    int64_t _extended_price3545_sum_0;
    int64_t _list_price3546_sum_1;
    int64_t _extended_tax3547_sum_2;
};
void SW_Aggregate_TD_5312256(Table &tbl_JOIN_INNER_TD_6187048_output, Table &tbl_Aggregate_TD_5312256_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(ss_ticket_number#1215L, ss_customer_sk#1209, ss_addr_sk#1212, ca_city#60, ca_city#60 AS bought_city#3544, MakeDecimal(sum(UnscaledValue(ss_ext_sales_price#1221)),17,2) AS extended_price#3545, MakeDecimal(sum(UnscaledValue(ss_ext_list_price#1223)),17,2) AS list_price#3546, MakeDecimal(sum(UnscaledValue(ss_ext_tax#1224)),17,2) AS extended_tax#3547)
    // Input: ListBuffer(ss_customer_sk#1209, ss_addr_sk#1212, ss_ticket_number#1215L, ss_ext_sales_price#1221, ss_ext_list_price#1223, ss_ext_tax#1224, ca_city#60)
    // Output: ListBuffer(ss_ticket_number#1215L, ss_customer_sk#1209, bought_city#3544, extended_price#3545, list_price#3546, extended_tax#3547)
    std::unordered_map<SW_Aggregate_TD_5312256_key, SW_Aggregate_TD_5312256_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_6187048_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_6187048_output.getInt32(i, 0);
        int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_6187048_output.getInt32(i, 1);
        int64_t _ss_ticket_number1215L = tbl_JOIN_INNER_TD_6187048_output.getInt64(i, 2);
        int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_6187048_output.getInt64(i, 3);
        int64_t _ss_ext_list_price1223 = tbl_JOIN_INNER_TD_6187048_output.getInt64(i, 4);
        int64_t _ss_ext_tax1224 = tbl_JOIN_INNER_TD_6187048_output.getInt64(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city60 = tbl_JOIN_INNER_TD_6187048_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        SW_Aggregate_TD_5312256_key k{_ss_ticket_number1215L, _ss_customer_sk1209, _ss_addr_sk1212, std::string(_ca_city60.data())};
        std::array<char, TPCDS_READ_MAX + 1> _bought_city3544 = _ca_city60;
        int64_t _extended_price3545_sum_0 = _ss_ext_sales_price1221;
        int64_t _list_price3546_sum_1 = _ss_ext_list_price1223;
        int64_t _extended_tax3547_sum_2 = _ss_ext_tax1224;
        SW_Aggregate_TD_5312256_payload p{std::string(_bought_city3544.data()), _extended_price3545_sum_0, _list_price3546_sum_1, _extended_tax3547_sum_2};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._extended_price3545_sum_0 + _extended_price3545_sum_0;
            p._extended_price3545_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._list_price3546_sum_1 + _list_price3546_sum_1;
            p._list_price3546_sum_1 = sum_1;
            int64_t sum_2 = (it->second)._extended_tax3547_sum_2 + _extended_tax3547_sum_2;
            p._extended_tax3547_sum_2 = sum_2;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        tbl_Aggregate_TD_5312256_output.setInt64(r, 0, (it.first)._ss_ticket_number1215L);
        tbl_Aggregate_TD_5312256_output.setInt32(r, 1, (it.first)._ss_customer_sk1209);
        // _ss_addr_sk1212 not required in the output table
        // _ca_city60 not required in the output table
        std::array<char, TPCDS_READ_MAX + 1> _bought_city3544_n{};
        memcpy(_bought_city3544_n.data(), (it.second)._bought_city3544.data(), (it.second)._bought_city3544.length());
        tbl_Aggregate_TD_5312256_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _bought_city3544_n);
        int64_t _extended_price3545 = (it.second)._extended_price3545_sum_0;
        tbl_Aggregate_TD_5312256_output.setInt64(r, 3, _extended_price3545);
        int64_t _list_price3546 = (it.second)._list_price3546_sum_1;
        tbl_Aggregate_TD_5312256_output.setInt64(r, 4, _list_price3546);
        int64_t _extended_tax3547 = (it.second)._extended_tax3547_sum_2;
        tbl_Aggregate_TD_5312256_output.setInt64(r, 5, _extended_tax3547);
        ++r;
    }
    tbl_Aggregate_TD_5312256_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_5312256_output #Row: " << tbl_Aggregate_TD_5312256_output.getNumRow() << std::endl;
}

void SW_Filter_TD_453726(Table &tbl_SerializeFromObject_TD_5411227_input, Table &tbl_Filter_TD_453726_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ca_address_sk#3548) AND isnotnull(ca_city#3554)))
    // Input: ListBuffer(ca_address_sk#3548, ca_city#3554)
    // Output: ListBuffer(ca_address_sk#3548, ca_city#3554)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5411227_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ca_address_sk3548 = tbl_SerializeFromObject_TD_5411227_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city3554 = tbl_SerializeFromObject_TD_5411227_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_ca_address_sk3548!= 0) && _ca_city3554.data() != "NULL") {
            int32_t _ca_address_sk3548_t = tbl_SerializeFromObject_TD_5411227_input.getInt32(i, 0);
            tbl_Filter_TD_453726_output.setInt32(r, 0, _ca_address_sk3548_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_city3554_t = tbl_SerializeFromObject_TD_5411227_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_453726_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_city3554_t);
            r++;
        }
    }
    tbl_Filter_TD_453726_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_453726_output #Row: " << tbl_Filter_TD_453726_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4311690_key_leftMajor {
    int32_t _ss_customer_sk1209;
    bool operator==(const SW_JOIN_INNER_TD_4311690_key_leftMajor& other) const {
        return ((_ss_customer_sk1209 == other._ss_customer_sk1209));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4311690_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4311690_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_customer_sk1209));
    }
};
}
struct SW_JOIN_INNER_TD_4311690_payload_leftMajor {
    int64_t _ss_ticket_number1215L;
    int32_t _ss_customer_sk1209;
    std::string _bought_city3544;
    int64_t _extended_price3545;
    int64_t _list_price3546;
    int64_t _extended_tax3547;
};
struct SW_JOIN_INNER_TD_4311690_key_rightMajor {
    int32_t _c_customer_sk0;
    bool operator==(const SW_JOIN_INNER_TD_4311690_key_rightMajor& other) const {
        return ((_c_customer_sk0 == other._c_customer_sk0));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4311690_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4311690_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk0));
    }
};
}
struct SW_JOIN_INNER_TD_4311690_payload_rightMajor {
    int32_t _c_customer_sk0;
    int32_t _c_current_addr_sk4;
    std::string _c_first_name8;
    std::string _c_last_name9;
};
void SW_JOIN_INNER_TD_4311690(Table &tbl_Aggregate_TD_5312256_output, Table &tbl_Filter_TD_5896878_output, Table &tbl_JOIN_INNER_TD_4311690_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_customer_sk#1209 = c_customer_sk#0))
    // Left Table: ListBuffer(ss_ticket_number#1215L, ss_customer_sk#1209, bought_city#3544, extended_price#3545, list_price#3546, extended_tax#3547)
    // Right Table: ListBuffer(c_customer_sk#0, c_current_addr_sk#4, c_first_name#8, c_last_name#9)
    // Output Table: ListBuffer(ss_ticket_number#1215L, bought_city#3544, extended_price#3545, list_price#3546, extended_tax#3547, c_current_addr_sk#4, c_first_name#8, c_last_name#9)
    int left_nrow = tbl_Aggregate_TD_5312256_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5896878_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4311690_key_leftMajor, SW_JOIN_INNER_TD_4311690_payload_leftMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_5312256_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_customer_sk1209_k = tbl_Aggregate_TD_5312256_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_4311690_key_leftMajor keyA{_ss_customer_sk1209_k};
            int64_t _ss_ticket_number1215L = tbl_Aggregate_TD_5312256_output.getInt64(i, 0);
            int32_t _ss_customer_sk1209 = tbl_Aggregate_TD_5312256_output.getInt32(i, 1);
            std::array<char, TPCDS_READ_MAX + 1> _bought_city3544_n = tbl_Aggregate_TD_5312256_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _bought_city3544 = std::string(_bought_city3544_n.data());
            int64_t _extended_price3545 = tbl_Aggregate_TD_5312256_output.getInt64(i, 3);
            int64_t _list_price3546 = tbl_Aggregate_TD_5312256_output.getInt64(i, 4);
            int64_t _extended_tax3547 = tbl_Aggregate_TD_5312256_output.getInt64(i, 5);
            SW_JOIN_INNER_TD_4311690_payload_leftMajor payloadA{_ss_ticket_number1215L, _ss_customer_sk1209, _bought_city3544, _extended_price3545, _list_price3546, _extended_tax3547};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5896878_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_5896878_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4311690_key_leftMajor{_c_customer_sk0_k});
            auto it = its.first;
            while (it != its.second) {
                int64_t _ss_ticket_number1215L = (it->second)._ss_ticket_number1215L;
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                std::string _bought_city3544 = (it->second)._bought_city3544;
                std::array<char, TPCDS_READ_MAX + 1> _bought_city3544_n{};
                memcpy(_bought_city3544_n.data(), (_bought_city3544).data(), (_bought_city3544).length());
                int64_t _extended_price3545 = (it->second)._extended_price3545;
                int64_t _list_price3546 = (it->second)._list_price3546;
                int64_t _extended_tax3547 = (it->second)._extended_tax3547;
                int32_t _c_customer_sk0 = tbl_Filter_TD_5896878_output.getInt32(i, 0);
                int32_t _c_current_addr_sk4 = tbl_Filter_TD_5896878_output.getInt32(i, 1);
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_Filter_TD_5896878_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_first_name8 = std::string(_c_first_name8_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_Filter_TD_5896878_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_last_name9 = std::string(_c_last_name9_n.data());
                tbl_JOIN_INNER_TD_4311690_output.setInt64(r, 0, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_4311690_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _bought_city3544_n);
                tbl_JOIN_INNER_TD_4311690_output.setInt64(r, 2, _extended_price3545);
                tbl_JOIN_INNER_TD_4311690_output.setInt64(r, 3, _list_price3546);
                tbl_JOIN_INNER_TD_4311690_output.setInt64(r, 4, _extended_tax3547);
                tbl_JOIN_INNER_TD_4311690_output.setInt32(r, 5, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_4311690_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_first_name8_n);
                tbl_JOIN_INNER_TD_4311690_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _c_last_name9_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4311690_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4311690_key_rightMajor, SW_JOIN_INNER_TD_4311690_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5896878_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_5896878_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4311690_key_rightMajor keyA{_c_customer_sk0_k};
            int32_t _c_customer_sk0 = tbl_Filter_TD_5896878_output.getInt32(i, 0);
            int32_t _c_current_addr_sk4 = tbl_Filter_TD_5896878_output.getInt32(i, 1);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_Filter_TD_5896878_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_first_name8 = std::string(_c_first_name8_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_Filter_TD_5896878_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_last_name9 = std::string(_c_last_name9_n.data());
            SW_JOIN_INNER_TD_4311690_payload_rightMajor payloadA{_c_customer_sk0, _c_current_addr_sk4, _c_first_name8, _c_last_name9};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_5312256_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_customer_sk1209_k = tbl_Aggregate_TD_5312256_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4311690_key_rightMajor{_ss_customer_sk1209_k});
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
                int64_t _ss_ticket_number1215L = tbl_Aggregate_TD_5312256_output.getInt64(i, 0);
                int32_t _ss_customer_sk1209 = tbl_Aggregate_TD_5312256_output.getInt32(i, 1);
                std::array<char, TPCDS_READ_MAX + 1> _bought_city3544_n = tbl_Aggregate_TD_5312256_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _bought_city3544 = std::string(_bought_city3544_n.data());
                int64_t _extended_price3545 = tbl_Aggregate_TD_5312256_output.getInt64(i, 3);
                int64_t _list_price3546 = tbl_Aggregate_TD_5312256_output.getInt64(i, 4);
                int64_t _extended_tax3547 = tbl_Aggregate_TD_5312256_output.getInt64(i, 5);
                tbl_JOIN_INNER_TD_4311690_output.setInt32(r, 5, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_4311690_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_first_name8_n);
                tbl_JOIN_INNER_TD_4311690_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _c_last_name9_n);
                tbl_JOIN_INNER_TD_4311690_output.setInt64(r, 0, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_4311690_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _bought_city3544_n);
                tbl_JOIN_INNER_TD_4311690_output.setInt64(r, 2, _extended_price3545);
                tbl_JOIN_INNER_TD_4311690_output.setInt64(r, 3, _list_price3546);
                tbl_JOIN_INNER_TD_4311690_output.setInt64(r, 4, _extended_tax3547);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4311690_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4311690_output #Row: " << tbl_JOIN_INNER_TD_4311690_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_3503031_key_leftMajor {
    int32_t _c_current_addr_sk4;
    std::string _bought_city3544;
    bool operator==(const SW_JOIN_INNER_TD_3503031_key_leftMajor& other) const {
        return ((_c_current_addr_sk4 == other._c_current_addr_sk4) && (_bought_city3544 == other._bought_city3544));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3503031_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3503031_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_current_addr_sk4));
    }
};
}
struct SW_JOIN_INNER_TD_3503031_payload_leftMajor {
    int64_t _ss_ticket_number1215L;
    std::string _bought_city3544;
    int64_t _extended_price3545;
    int64_t _list_price3546;
    int64_t _extended_tax3547;
    int32_t _c_current_addr_sk4;
    std::string _c_first_name8;
    std::string _c_last_name9;
};
struct SW_JOIN_INNER_TD_3503031_key_rightMajor {
    int32_t _ca_address_sk3548;
    std::string _ca_city3554;
    bool operator==(const SW_JOIN_INNER_TD_3503031_key_rightMajor& other) const {
        return ((_ca_address_sk3548 == other._ca_address_sk3548) && (_ca_city3554 == other._ca_city3554));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3503031_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3503031_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk3548));
    }
};
}
struct SW_JOIN_INNER_TD_3503031_payload_rightMajor {
    int32_t _ca_address_sk3548;
    std::string _ca_city3554;
};
void SW_JOIN_INNER_TD_3503031(Table &tbl_JOIN_INNER_TD_4311690_output, Table &tbl_Filter_TD_453726_output, Table &tbl_JOIN_INNER_TD_3503031_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((c_current_addr_sk#4 = ca_address_sk#3548) AND NOT (ca_city#3554 = bought_city#3544)))
    // Left Table: ListBuffer(ss_ticket_number#1215L, bought_city#3544, extended_price#3545, list_price#3546, extended_tax#3547, c_current_addr_sk#4, c_first_name#8, c_last_name#9)
    // Right Table: ListBuffer(ca_address_sk#3548, ca_city#3554)
    // Output Table: ListBuffer(c_last_name#9, c_first_name#8, ca_city#3554, bought_city#3544, ss_ticket_number#1215L, extended_price#3545, extended_tax#3547, list_price#3546)
    int left_nrow = tbl_JOIN_INNER_TD_4311690_output.getNumRow();
    int right_nrow = tbl_Filter_TD_453726_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3503031_key_leftMajor, SW_JOIN_INNER_TD_3503031_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_4311690_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_current_addr_sk4_k = tbl_JOIN_INNER_TD_4311690_output.getInt32(i, 5);
            std::array<char, TPCDS_READ_MAX + 1> _bought_city3544_k_n = tbl_JOIN_INNER_TD_4311690_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _bought_city3544_k = std::string(_bought_city3544_k_n.data());
            SW_JOIN_INNER_TD_3503031_key_leftMajor keyA{_c_current_addr_sk4_k, _bought_city3544_k};
            int64_t _ss_ticket_number1215L = tbl_JOIN_INNER_TD_4311690_output.getInt64(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _bought_city3544_n = tbl_JOIN_INNER_TD_4311690_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _bought_city3544 = std::string(_bought_city3544_n.data());
            int64_t _extended_price3545 = tbl_JOIN_INNER_TD_4311690_output.getInt64(i, 2);
            int64_t _list_price3546 = tbl_JOIN_INNER_TD_4311690_output.getInt64(i, 3);
            int64_t _extended_tax3547 = tbl_JOIN_INNER_TD_4311690_output.getInt64(i, 4);
            int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_4311690_output.getInt32(i, 5);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_JOIN_INNER_TD_4311690_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _c_first_name8 = std::string(_c_first_name8_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_JOIN_INNER_TD_4311690_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _c_last_name9 = std::string(_c_last_name9_n.data());
            SW_JOIN_INNER_TD_3503031_payload_leftMajor payloadA{_ss_ticket_number1215L, _bought_city3544, _extended_price3545, _list_price3546, _extended_tax3547, _c_current_addr_sk4, _c_first_name8, _c_last_name9};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_453726_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk3548_k = tbl_Filter_TD_453726_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_city3554_k_n = tbl_Filter_TD_453726_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_city3554_k = std::string(_ca_city3554_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3503031_key_leftMajor{_ca_address_sk3548_k, _ca_city3554_k});
            auto it = its.first;
            while (it != its.second) {
                int64_t _ss_ticket_number1215L = (it->second)._ss_ticket_number1215L;
                std::string _bought_city3544 = (it->second)._bought_city3544;
                std::array<char, TPCDS_READ_MAX + 1> _bought_city3544_n{};
                memcpy(_bought_city3544_n.data(), (_bought_city3544).data(), (_bought_city3544).length());
                int64_t _extended_price3545 = (it->second)._extended_price3545;
                int64_t _list_price3546 = (it->second)._list_price3546;
                int64_t _extended_tax3547 = (it->second)._extended_tax3547;
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                std::string _c_first_name8 = (it->second)._c_first_name8;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n{};
                memcpy(_c_first_name8_n.data(), (_c_first_name8).data(), (_c_first_name8).length());
                std::string _c_last_name9 = (it->second)._c_last_name9;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n{};
                memcpy(_c_last_name9_n.data(), (_c_last_name9).data(), (_c_last_name9).length());
                int32_t _ca_address_sk3548 = tbl_Filter_TD_453726_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_city3554_n = tbl_Filter_TD_453726_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_city3554 = std::string(_ca_city3554_n.data());
                tbl_JOIN_INNER_TD_3503031_output.setInt64(r, 4, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_3503031_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _bought_city3544_n);
                tbl_JOIN_INNER_TD_3503031_output.setInt64(r, 5, _extended_price3545);
                tbl_JOIN_INNER_TD_3503031_output.setInt64(r, 7, _list_price3546);
                tbl_JOIN_INNER_TD_3503031_output.setInt64(r, 6, _extended_tax3547);
                tbl_JOIN_INNER_TD_3503031_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
                tbl_JOIN_INNER_TD_3503031_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name9_n);
                tbl_JOIN_INNER_TD_3503031_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_city3554_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3503031_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3503031_key_rightMajor, SW_JOIN_INNER_TD_3503031_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_453726_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk3548_k = tbl_Filter_TD_453726_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_city3554_k_n = tbl_Filter_TD_453726_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_city3554_k = std::string(_ca_city3554_k_n.data());
            SW_JOIN_INNER_TD_3503031_key_rightMajor keyA{_ca_address_sk3548_k, _ca_city3554_k};
            int32_t _ca_address_sk3548 = tbl_Filter_TD_453726_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_city3554_n = tbl_Filter_TD_453726_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_city3554 = std::string(_ca_city3554_n.data());
            SW_JOIN_INNER_TD_3503031_payload_rightMajor payloadA{_ca_address_sk3548, _ca_city3554};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_4311690_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_current_addr_sk4_k = tbl_JOIN_INNER_TD_4311690_output.getInt32(i, 5);
            std::array<char, TPCDS_READ_MAX + 1> _bought_city3544_k_n = tbl_JOIN_INNER_TD_4311690_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _bought_city3544_k = std::string(_bought_city3544_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3503031_key_rightMajor{_c_current_addr_sk4_k, _bought_city3544_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk3548 = (it->second)._ca_address_sk3548;
                std::string _ca_city3554 = (it->second)._ca_city3554;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city3554_n{};
                memcpy(_ca_city3554_n.data(), (_ca_city3554).data(), (_ca_city3554).length());
                int64_t _ss_ticket_number1215L = tbl_JOIN_INNER_TD_4311690_output.getInt64(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _bought_city3544_n = tbl_JOIN_INNER_TD_4311690_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _bought_city3544 = std::string(_bought_city3544_n.data());
                int64_t _extended_price3545 = tbl_JOIN_INNER_TD_4311690_output.getInt64(i, 2);
                int64_t _list_price3546 = tbl_JOIN_INNER_TD_4311690_output.getInt64(i, 3);
                int64_t _extended_tax3547 = tbl_JOIN_INNER_TD_4311690_output.getInt64(i, 4);
                int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_4311690_output.getInt32(i, 5);
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_JOIN_INNER_TD_4311690_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _c_first_name8 = std::string(_c_first_name8_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_JOIN_INNER_TD_4311690_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _c_last_name9 = std::string(_c_last_name9_n.data());
                tbl_JOIN_INNER_TD_3503031_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_city3554_n);
                tbl_JOIN_INNER_TD_3503031_output.setInt64(r, 4, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_3503031_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _bought_city3544_n);
                tbl_JOIN_INNER_TD_3503031_output.setInt64(r, 5, _extended_price3545);
                tbl_JOIN_INNER_TD_3503031_output.setInt64(r, 7, _list_price3546);
                tbl_JOIN_INNER_TD_3503031_output.setInt64(r, 6, _extended_tax3547);
                tbl_JOIN_INNER_TD_3503031_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
                tbl_JOIN_INNER_TD_3503031_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name9_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3503031_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_3503031_output #Row: " << tbl_JOIN_INNER_TD_3503031_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2415189(Table &tbl_JOIN_INNER_TD_3503031_output, Table &tbl_Sort_TD_2415189_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(c_last_name#9 ASC NULLS FIRST, ss_ticket_number#1215L ASC NULLS FIRST)
    // Input: ListBuffer(c_last_name#9, c_first_name#8, ca_city#3554, bought_city#3544, ss_ticket_number#1215L, extended_price#3545, extended_tax#3547, list_price#3546)
    // Output: ListBuffer(c_last_name#9, c_first_name#8, ca_city#3554, bought_city#3544, ss_ticket_number#1215L, extended_price#3545, extended_tax#3547, list_price#3546)
    struct SW_Sort_TD_2415189Row {
        std::string _c_last_name9;
        std::string _c_first_name8;
        std::string _ca_city3554;
        std::string _bought_city3544;
        int64_t _ss_ticket_number1215L;
        int64_t _extended_price3545;
        int64_t _extended_tax3547;
        int64_t _list_price3546;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2415189Row& a, const SW_Sort_TD_2415189Row& b) const { return 
 (a._c_last_name9 < b._c_last_name9) || 
 ((a._c_last_name9 == b._c_last_name9) && (a._ss_ticket_number1215L < b._ss_ticket_number1215L)); 
}
    }SW_Sort_TD_2415189_order; 

    int nrow1 = tbl_JOIN_INNER_TD_3503031_output.getNumRow();
    std::vector<SW_Sort_TD_2415189Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9 = tbl_JOIN_INNER_TD_3503031_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8 = tbl_JOIN_INNER_TD_3503031_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city3554 = tbl_JOIN_INNER_TD_3503031_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _bought_city3544 = tbl_JOIN_INNER_TD_3503031_output.getcharN<char, TPCDS_READ_MAX +1>(i, 3);
        int64_t _ss_ticket_number1215L = tbl_JOIN_INNER_TD_3503031_output.getInt64(i, 4);
        int64_t _extended_price3545 = tbl_JOIN_INNER_TD_3503031_output.getInt64(i, 5);
        int64_t _extended_tax3547 = tbl_JOIN_INNER_TD_3503031_output.getInt64(i, 6);
        int64_t _list_price3546 = tbl_JOIN_INNER_TD_3503031_output.getInt64(i, 7);
        SW_Sort_TD_2415189Row t = {std::string(_c_last_name9.data()),std::string(_c_first_name8.data()),std::string(_ca_city3554.data()),std::string(_bought_city3544.data()),_ss_ticket_number1215L,_extended_price3545,_extended_tax3547,_list_price3546};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2415189_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9{};
        memcpy(_c_last_name9.data(), (it._c_last_name9).data(), (it._c_last_name9).length());
        tbl_Sort_TD_2415189_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _c_last_name9);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8{};
        memcpy(_c_first_name8.data(), (it._c_first_name8).data(), (it._c_first_name8).length());
        tbl_Sort_TD_2415189_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _c_first_name8);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city3554{};
        memcpy(_ca_city3554.data(), (it._ca_city3554).data(), (it._ca_city3554).length());
        tbl_Sort_TD_2415189_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _ca_city3554);
        std::array<char, TPCDS_READ_MAX + 1> _bought_city3544{};
        memcpy(_bought_city3544.data(), (it._bought_city3544).data(), (it._bought_city3544).length());
        tbl_Sort_TD_2415189_output.setcharN<char, TPCDS_READ_MAX +1>(r, 3, _bought_city3544);
        tbl_Sort_TD_2415189_output.setInt64(r, 4, it._ss_ticket_number1215L);
        tbl_Sort_TD_2415189_output.setInt64(r, 5, it._extended_price3545);
        tbl_Sort_TD_2415189_output.setInt64(r, 6, it._extended_tax3547);
        tbl_Sort_TD_2415189_output.setInt64(r, 7, it._list_price3546);
        ++r;
    }
    tbl_Sort_TD_2415189_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2415189_output #Row: " << tbl_Sort_TD_2415189_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1578119(Table &tbl_Sort_TD_2415189_output, Table &tbl_LocalLimit_TD_1578119_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(c_last_name#9, c_first_name#8, ca_city#3554, bought_city#3544, ss_ticket_number#1215L, extended_price#3545, extended_tax#3547, list_price#3546)
    // Output: ListBuffer(c_last_name#9, c_first_name#8, ca_city#3554, bought_city#3544, ss_ticket_number#1215L, extended_price#3545, extended_tax#3547, list_price#3546)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_Sort_TD_2415189_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1578119_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name9_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_Sort_TD_2415189_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_1578119_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city3554_n = tbl_Sort_TD_2415189_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_LocalLimit_TD_1578119_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_city3554_n);
        std::array<char, TPCDS_READ_MAX + 1> _bought_city3544_n = tbl_Sort_TD_2415189_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_LocalLimit_TD_1578119_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _bought_city3544_n);
        tbl_LocalLimit_TD_1578119_output.setInt64(r, 4, tbl_Sort_TD_2415189_output.getInt64(i, 4));
        tbl_LocalLimit_TD_1578119_output.setInt64(r, 5, tbl_Sort_TD_2415189_output.getInt64(i, 5));
        tbl_LocalLimit_TD_1578119_output.setInt64(r, 6, tbl_Sort_TD_2415189_output.getInt64(i, 6));
        tbl_LocalLimit_TD_1578119_output.setInt64(r, 7, tbl_Sort_TD_2415189_output.getInt64(i, 7));
        r++;
    }
    tbl_LocalLimit_TD_1578119_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1578119_output #Row: " << tbl_LocalLimit_TD_1578119_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_083063(Table &tbl_LocalLimit_TD_1578119_output, Table &tbl_GlobalLimit_TD_083063_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(c_last_name#9, c_first_name#8, ca_city#3554, bought_city#3544, ss_ticket_number#1215L, extended_price#3545, extended_tax#3547, list_price#3546)
    // Output: ListBuffer(c_last_name#9, c_first_name#8, ca_city#3554, bought_city#3544, ss_ticket_number#1215L, extended_price#3545, extended_tax#3547, list_price#3546)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_LocalLimit_TD_1578119_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_083063_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name9_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_LocalLimit_TD_1578119_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_083063_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city3554_n = tbl_LocalLimit_TD_1578119_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_GlobalLimit_TD_083063_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_city3554_n);
        std::array<char, TPCDS_READ_MAX + 1> _bought_city3544_n = tbl_LocalLimit_TD_1578119_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_GlobalLimit_TD_083063_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _bought_city3544_n);
        tbl_GlobalLimit_TD_083063_output.setInt64(r, 4, tbl_LocalLimit_TD_1578119_output.getInt64(i, 4));
        tbl_GlobalLimit_TD_083063_output.setInt64(r, 5, tbl_LocalLimit_TD_1578119_output.getInt64(i, 5));
        tbl_GlobalLimit_TD_083063_output.setInt64(r, 6, tbl_LocalLimit_TD_1578119_output.getInt64(i, 6));
        tbl_GlobalLimit_TD_083063_output.setInt64(r, 7, tbl_LocalLimit_TD_1578119_output.getInt64(i, 7));
        r++;
    }
    tbl_GlobalLimit_TD_083063_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_083063_output #Row: " << tbl_GlobalLimit_TD_083063_output.getNumRow() << std::endl;
}

