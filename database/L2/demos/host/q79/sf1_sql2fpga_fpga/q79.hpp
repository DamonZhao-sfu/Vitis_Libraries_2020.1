#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_9830144(Table &tbl_SerializeFromObject_TD_10127397_input, Table &tbl_Filter_TD_9830144_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_dow#127) AND ((d_dow#127 = 1) AND d_year#126 IN (1999,2000,2001))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_dow#127, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10127397_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_dow127 = tbl_SerializeFromObject_TD_10127397_input.getInt32(i, 1);
        int32_t _d_year126 = tbl_SerializeFromObject_TD_10127397_input.getInt32(i, 2);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_10127397_input.getInt32(i, 0);
        auto reuse_col_str_653 = _d_year126;
        if (((_d_dow127!= 0) && ((_d_dow127 == 1) && ((reuse_col_str_653 == 1999) || (reuse_col_str_653 == 2000) || (reuse_col_str_653 == 2001) || (0)))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_10127397_input.getInt32(i, 0);
            tbl_Filter_TD_9830144_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_9830144_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9830144_output #Row: " << tbl_Filter_TD_9830144_output.getNumRow() << std::endl;
}

void SW_Filter_TD_978927(Table &tbl_SerializeFromObject_TD_10845328_input, Table &tbl_Filter_TD_978927_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ss_sold_date_sk#1206) AND isnotnull(ss_store_sk#1213)) AND (isnotnull(ss_hdemo_sk#1211) AND isnotnull(ss_customer_sk#1209))))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_customer_sk#1209, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_store_sk#1213, ss_ticket_number#1215L, ss_coupon_amt#1225, ss_net_profit#1228)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_customer_sk#1209, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_store_sk#1213, ss_ticket_number#1215L, ss_coupon_amt#1225, ss_net_profit#1228)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10845328_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_10845328_input.getInt32(i, 0);
        int32_t _ss_store_sk1213 = tbl_SerializeFromObject_TD_10845328_input.getInt32(i, 4);
        int32_t _ss_hdemo_sk1211 = tbl_SerializeFromObject_TD_10845328_input.getInt32(i, 2);
        int32_t _ss_customer_sk1209 = tbl_SerializeFromObject_TD_10845328_input.getInt32(i, 1);
        if (((_ss_sold_date_sk1206!= 0) && (_ss_store_sk1213!= 0)) && ((_ss_hdemo_sk1211!= 0) && (_ss_customer_sk1209!= 0))) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_10845328_input.getInt32(i, 0);
            tbl_Filter_TD_978927_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_customer_sk1209_t = tbl_SerializeFromObject_TD_10845328_input.getInt32(i, 1);
            tbl_Filter_TD_978927_output.setInt32(r, 1, _ss_customer_sk1209_t);
            int32_t _ss_hdemo_sk1211_t = tbl_SerializeFromObject_TD_10845328_input.getInt32(i, 2);
            tbl_Filter_TD_978927_output.setInt32(r, 2, _ss_hdemo_sk1211_t);
            int32_t _ss_addr_sk1212_t = tbl_SerializeFromObject_TD_10845328_input.getInt32(i, 3);
            tbl_Filter_TD_978927_output.setInt32(r, 3, _ss_addr_sk1212_t);
            int32_t _ss_store_sk1213_t = tbl_SerializeFromObject_TD_10845328_input.getInt32(i, 4);
            tbl_Filter_TD_978927_output.setInt32(r, 4, _ss_store_sk1213_t);
            int64_t _ss_ticket_number1215L_t = tbl_SerializeFromObject_TD_10845328_input.getInt64(i, 5);
            tbl_Filter_TD_978927_output.setInt64(r, 5, _ss_ticket_number1215L_t);
            int64_t _ss_coupon_amt1225_t = tbl_SerializeFromObject_TD_10845328_input.getInt64(i, 6);
            tbl_Filter_TD_978927_output.setInt64(r, 6, _ss_coupon_amt1225_t);
            int64_t _ss_net_profit1228_t = tbl_SerializeFromObject_TD_10845328_input.getInt64(i, 7);
            tbl_Filter_TD_978927_output.setInt64(r, 7, _ss_net_profit1228_t);
            r++;
        }
    }
    tbl_Filter_TD_978927_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_978927_output #Row: " << tbl_Filter_TD_978927_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8889660(Table &tbl_SerializeFromObject_TD_9353951_input, Table &tbl_Filter_TD_8889660_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(s_number_employees#384) AND ((s_number_employees#384 >= 200) AND (s_number_employees#384 <= 295))) AND isnotnull(s_store_sk#378)))
    // Input: ListBuffer(s_store_sk#378, s_city#400, s_number_employees#384)
    // Output: ListBuffer(s_store_sk#378, s_city#400)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9353951_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _s_number_employees384 = tbl_SerializeFromObject_TD_9353951_input.getInt32(i, 2);
        int32_t _s_store_sk378 = tbl_SerializeFromObject_TD_9353951_input.getInt32(i, 0);
        if (((_s_number_employees384!= 0) && ((_s_number_employees384 >= 200) && (_s_number_employees384 <= 295))) && (_s_store_sk378!= 0)) {
            int32_t _s_store_sk378_t = tbl_SerializeFromObject_TD_9353951_input.getInt32(i, 0);
            tbl_Filter_TD_8889660_output.setInt32(r, 0, _s_store_sk378_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_city400_t = tbl_SerializeFromObject_TD_9353951_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_8889660_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_city400_t);
            r++;
        }
    }
    tbl_Filter_TD_8889660_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8889660_output #Row: " << tbl_Filter_TD_8889660_output.getNumRow() << std::endl;
}


void SW_Filter_TD_7202907(Table &tbl_SerializeFromObject_TD_8891195_input, Table &tbl_Filter_TD_7202907_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((hd_dep_count#207 = 6) OR (hd_vehicle_count#208 > 2)) AND isnotnull(hd_demo_sk#204)))
    // Input: ListBuffer(hd_demo_sk#204, hd_dep_count#207, hd_vehicle_count#208)
    // Output: ListBuffer(hd_demo_sk#204)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8891195_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _hd_dep_count207 = tbl_SerializeFromObject_TD_8891195_input.getInt32(i, 1);
        int32_t _hd_vehicle_count208 = tbl_SerializeFromObject_TD_8891195_input.getInt32(i, 2);
        int32_t _hd_demo_sk204 = tbl_SerializeFromObject_TD_8891195_input.getInt32(i, 0);
        if (((_hd_dep_count207 == 6) || (_hd_vehicle_count208 > 2)) && (_hd_demo_sk204!= 0)) {
            int32_t _hd_demo_sk204_t = tbl_SerializeFromObject_TD_8891195_input.getInt32(i, 0);
            tbl_Filter_TD_7202907_output.setInt32(r, 0, _hd_demo_sk204_t);
            r++;
        }
    }
    tbl_Filter_TD_7202907_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7202907_output #Row: " << tbl_Filter_TD_7202907_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_7738791_key_leftMajor {
    int32_t _ss_store_sk1213;
    bool operator==(const SW_JOIN_INNER_TD_7738791_key_leftMajor& other) const {
        return ((_ss_store_sk1213 == other._ss_store_sk1213));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7738791_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7738791_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_store_sk1213));
    }
};
}
struct SW_JOIN_INNER_TD_7738791_payload_leftMajor {
    int32_t _ss_customer_sk1209;
    int32_t _ss_hdemo_sk1211;
    int32_t _ss_addr_sk1212;
    int32_t _ss_store_sk1213;
    int64_t _ss_ticket_number1215L;
    int64_t _ss_coupon_amt1225;
    int64_t _ss_net_profit1228;
};
struct SW_JOIN_INNER_TD_7738791_key_rightMajor {
    int32_t _s_store_sk378;
    bool operator==(const SW_JOIN_INNER_TD_7738791_key_rightMajor& other) const {
        return ((_s_store_sk378 == other._s_store_sk378));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7738791_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7738791_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_store_sk378));
    }
};
}
struct SW_JOIN_INNER_TD_7738791_payload_rightMajor {
    int32_t _s_store_sk378;
    std::string _s_city400;
};
void SW_JOIN_INNER_TD_7738791(Table &tbl_JOIN_INNER_TD_8391419_output, Table &tbl_Filter_TD_8889660_output, Table &tbl_JOIN_INNER_TD_7738791_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_store_sk#1213 = s_store_sk#378))
    // Left Table: ListBuffer(ss_customer_sk#1209, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_store_sk#1213, ss_ticket_number#1215L, ss_coupon_amt#1225, ss_net_profit#1228)
    // Right Table: ListBuffer(s_store_sk#378, s_city#400)
    // Output Table: ListBuffer(ss_customer_sk#1209, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_ticket_number#1215L, ss_coupon_amt#1225, ss_net_profit#1228, s_city#400)
    int left_nrow = tbl_JOIN_INNER_TD_8391419_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8889660_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7738791_key_leftMajor, SW_JOIN_INNER_TD_7738791_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_8391419_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_store_sk1213_k = tbl_JOIN_INNER_TD_8391419_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_7738791_key_leftMajor keyA{_ss_store_sk1213_k};
            int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_8391419_output.getInt32(i, 0);
            int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_8391419_output.getInt32(i, 1);
            int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_8391419_output.getInt32(i, 2);
            int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_8391419_output.getInt32(i, 3);
            int64_t _ss_ticket_number1215L = tbl_JOIN_INNER_TD_8391419_output.getInt64(i, 4);
            int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_8391419_output.getInt64(i, 5);
            int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_8391419_output.getInt64(i, 6);
            SW_JOIN_INNER_TD_7738791_payload_leftMajor payloadA{_ss_customer_sk1209, _ss_hdemo_sk1211, _ss_addr_sk1212, _ss_store_sk1213, _ss_ticket_number1215L, _ss_coupon_amt1225, _ss_net_profit1228};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8889660_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_8889660_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7738791_key_leftMajor{_s_store_sk378_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                int32_t _ss_hdemo_sk1211 = (it->second)._ss_hdemo_sk1211;
                int32_t _ss_addr_sk1212 = (it->second)._ss_addr_sk1212;
                int32_t _ss_store_sk1213 = (it->second)._ss_store_sk1213;
                int64_t _ss_ticket_number1215L = (it->second)._ss_ticket_number1215L;
                int64_t _ss_coupon_amt1225 = (it->second)._ss_coupon_amt1225;
                int64_t _ss_net_profit1228 = (it->second)._ss_net_profit1228;
                int32_t _s_store_sk378 = tbl_Filter_TD_8889660_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _s_city400_n = tbl_Filter_TD_8889660_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _s_city400 = std::string(_s_city400_n.data());
                tbl_JOIN_INNER_TD_7738791_output.setInt32(r, 0, _ss_customer_sk1209);
                tbl_JOIN_INNER_TD_7738791_output.setInt32(r, 1, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_7738791_output.setInt32(r, 2, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_7738791_output.setInt64(r, 3, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_7738791_output.setInt64(r, 4, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_7738791_output.setInt64(r, 5, _ss_net_profit1228);
                tbl_JOIN_INNER_TD_7738791_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_city400_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7738791_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7738791_key_rightMajor, SW_JOIN_INNER_TD_7738791_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8889660_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_8889660_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7738791_key_rightMajor keyA{_s_store_sk378_k};
            int32_t _s_store_sk378 = tbl_Filter_TD_8889660_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _s_city400_n = tbl_Filter_TD_8889660_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _s_city400 = std::string(_s_city400_n.data());
            SW_JOIN_INNER_TD_7738791_payload_rightMajor payloadA{_s_store_sk378, _s_city400};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_8391419_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_store_sk1213_k = tbl_JOIN_INNER_TD_8391419_output.getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7738791_key_rightMajor{_ss_store_sk1213_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _s_store_sk378 = (it->second)._s_store_sk378;
                std::string _s_city400 = (it->second)._s_city400;
                std::array<char, TPCDS_READ_MAX + 1> _s_city400_n{};
                memcpy(_s_city400_n.data(), (_s_city400).data(), (_s_city400).length());
                int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_8391419_output.getInt32(i, 0);
                int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_8391419_output.getInt32(i, 1);
                int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_8391419_output.getInt32(i, 2);
                int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_8391419_output.getInt32(i, 3);
                int64_t _ss_ticket_number1215L = tbl_JOIN_INNER_TD_8391419_output.getInt64(i, 4);
                int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_8391419_output.getInt64(i, 5);
                int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_8391419_output.getInt64(i, 6);
                tbl_JOIN_INNER_TD_7738791_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_city400_n);
                tbl_JOIN_INNER_TD_7738791_output.setInt32(r, 0, _ss_customer_sk1209);
                tbl_JOIN_INNER_TD_7738791_output.setInt32(r, 1, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_7738791_output.setInt32(r, 2, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_7738791_output.setInt64(r, 3, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_7738791_output.setInt64(r, 4, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_7738791_output.setInt64(r, 5, _ss_net_profit1228);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7738791_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7738791_output #Row: " << tbl_JOIN_INNER_TD_7738791_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6528034_key_leftMajor {
    int32_t _ss_hdemo_sk1211;
    bool operator==(const SW_JOIN_INNER_TD_6528034_key_leftMajor& other) const {
        return ((_ss_hdemo_sk1211 == other._ss_hdemo_sk1211));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6528034_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6528034_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_hdemo_sk1211));
    }
};
}
struct SW_JOIN_INNER_TD_6528034_payload_leftMajor {
    int32_t _ss_customer_sk1209;
    int32_t _ss_hdemo_sk1211;
    int32_t _ss_addr_sk1212;
    int64_t _ss_ticket_number1215L;
    int64_t _ss_coupon_amt1225;
    int64_t _ss_net_profit1228;
    std::string _s_city400;
};
struct SW_JOIN_INNER_TD_6528034_key_rightMajor {
    int32_t _hd_demo_sk204;
    bool operator==(const SW_JOIN_INNER_TD_6528034_key_rightMajor& other) const {
        return ((_hd_demo_sk204 == other._hd_demo_sk204));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6528034_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6528034_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._hd_demo_sk204));
    }
};
}
struct SW_JOIN_INNER_TD_6528034_payload_rightMajor {
    int32_t _hd_demo_sk204;
};
void SW_JOIN_INNER_TD_6528034(Table &tbl_JOIN_INNER_TD_7738791_output, Table &tbl_Filter_TD_7202907_output, Table &tbl_JOIN_INNER_TD_6528034_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_hdemo_sk#1211 = hd_demo_sk#204))
    // Left Table: ListBuffer(ss_customer_sk#1209, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_ticket_number#1215L, ss_coupon_amt#1225, ss_net_profit#1228, s_city#400)
    // Right Table: ListBuffer(hd_demo_sk#204)
    // Output Table: ListBuffer(ss_customer_sk#1209, ss_addr_sk#1212, ss_ticket_number#1215L, ss_coupon_amt#1225, ss_net_profit#1228, s_city#400)
    int left_nrow = tbl_JOIN_INNER_TD_7738791_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7202907_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6528034_key_leftMajor, SW_JOIN_INNER_TD_6528034_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7738791_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_hdemo_sk1211_k = tbl_JOIN_INNER_TD_7738791_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_6528034_key_leftMajor keyA{_ss_hdemo_sk1211_k};
            int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_7738791_output.getInt32(i, 0);
            int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_7738791_output.getInt32(i, 1);
            int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_7738791_output.getInt32(i, 2);
            int64_t _ss_ticket_number1215L = tbl_JOIN_INNER_TD_7738791_output.getInt64(i, 3);
            int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_7738791_output.getInt64(i, 4);
            int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_7738791_output.getInt64(i, 5);
            std::array<char, TPCDS_READ_MAX + 1> _s_city400_n = tbl_JOIN_INNER_TD_7738791_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _s_city400 = std::string(_s_city400_n.data());
            SW_JOIN_INNER_TD_6528034_payload_leftMajor payloadA{_ss_customer_sk1209, _ss_hdemo_sk1211, _ss_addr_sk1212, _ss_ticket_number1215L, _ss_coupon_amt1225, _ss_net_profit1228, _s_city400};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7202907_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _hd_demo_sk204_k = tbl_Filter_TD_7202907_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6528034_key_leftMajor{_hd_demo_sk204_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                int32_t _ss_hdemo_sk1211 = (it->second)._ss_hdemo_sk1211;
                int32_t _ss_addr_sk1212 = (it->second)._ss_addr_sk1212;
                int64_t _ss_ticket_number1215L = (it->second)._ss_ticket_number1215L;
                int64_t _ss_coupon_amt1225 = (it->second)._ss_coupon_amt1225;
                int64_t _ss_net_profit1228 = (it->second)._ss_net_profit1228;
                std::string _s_city400 = (it->second)._s_city400;
                std::array<char, TPCDS_READ_MAX + 1> _s_city400_n{};
                memcpy(_s_city400_n.data(), (_s_city400).data(), (_s_city400).length());
                int32_t _hd_demo_sk204 = tbl_Filter_TD_7202907_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_6528034_output.setInt32(r, 0, _ss_customer_sk1209);
                tbl_JOIN_INNER_TD_6528034_output.setInt32(r, 1, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_6528034_output.setInt64(r, 2, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_6528034_output.setInt64(r, 3, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_6528034_output.setInt64(r, 4, _ss_net_profit1228);
                tbl_JOIN_INNER_TD_6528034_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_city400_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6528034_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6528034_key_rightMajor, SW_JOIN_INNER_TD_6528034_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7202907_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _hd_demo_sk204_k = tbl_Filter_TD_7202907_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6528034_key_rightMajor keyA{_hd_demo_sk204_k};
            int32_t _hd_demo_sk204 = tbl_Filter_TD_7202907_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6528034_payload_rightMajor payloadA{_hd_demo_sk204};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7738791_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_hdemo_sk1211_k = tbl_JOIN_INNER_TD_7738791_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6528034_key_rightMajor{_ss_hdemo_sk1211_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _hd_demo_sk204 = (it->second)._hd_demo_sk204;
                int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_7738791_output.getInt32(i, 0);
                int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_7738791_output.getInt32(i, 1);
                int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_7738791_output.getInt32(i, 2);
                int64_t _ss_ticket_number1215L = tbl_JOIN_INNER_TD_7738791_output.getInt64(i, 3);
                int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_7738791_output.getInt64(i, 4);
                int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_7738791_output.getInt64(i, 5);
                std::array<char, TPCDS_READ_MAX + 1> _s_city400_n = tbl_JOIN_INNER_TD_7738791_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _s_city400 = std::string(_s_city400_n.data());
                tbl_JOIN_INNER_TD_6528034_output.setInt32(r, 0, _ss_customer_sk1209);
                tbl_JOIN_INNER_TD_6528034_output.setInt32(r, 1, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_6528034_output.setInt64(r, 2, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_6528034_output.setInt64(r, 3, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_6528034_output.setInt64(r, 4, _ss_net_profit1228);
                tbl_JOIN_INNER_TD_6528034_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_city400_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6528034_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6528034_output #Row: " << tbl_JOIN_INNER_TD_6528034_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5980825(Table &tbl_SerializeFromObject_TD_6679178_input, Table &tbl_Filter_TD_5980825_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(c_customer_sk#0))
    // Input: ListBuffer(c_customer_sk#0, c_first_name#8, c_last_name#9)
    // Output: ListBuffer(c_customer_sk#0, c_first_name#8, c_last_name#9)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6679178_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk0 = tbl_SerializeFromObject_TD_6679178_input.getInt32(i, 0);
        if (_c_customer_sk0!= 0) {
            int32_t _c_customer_sk0_t = tbl_SerializeFromObject_TD_6679178_input.getInt32(i, 0);
            tbl_Filter_TD_5980825_output.setInt32(r, 0, _c_customer_sk0_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_t = tbl_SerializeFromObject_TD_6679178_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_5980825_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_t = tbl_SerializeFromObject_TD_6679178_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_5980825_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name9_t);
            r++;
        }
    }
    tbl_Filter_TD_5980825_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5980825_output #Row: " << tbl_Filter_TD_5980825_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_5506717_key {
    int64_t _ss_ticket_number1215L;
    int32_t _ss_customer_sk1209;
    int32_t _ss_addr_sk1212;
    std::string _s_city400;
    bool operator==(const SW_Aggregate_TD_5506717_key& other) const { return (_ss_ticket_number1215L == other._ss_ticket_number1215L) && (_ss_customer_sk1209 == other._ss_customer_sk1209) && (_ss_addr_sk1212 == other._ss_addr_sk1212) && (_s_city400 == other._s_city400); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_5506717_key> {
    std::size_t operator() (const SW_Aggregate_TD_5506717_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int64_t>()(k._ss_ticket_number1215L)) + (hash<int32_t>()(k._ss_customer_sk1209)) + (hash<int32_t>()(k._ss_addr_sk1212)) + (hash<string>()(k._s_city400));
    }
};
}
struct SW_Aggregate_TD_5506717_payload {
    int64_t _amt3544_sum_0;
    int64_t _profit3545_sum_1;
};
void SW_Aggregate_TD_5506717(Table &tbl_JOIN_INNER_TD_6528034_output, Table &tbl_Aggregate_TD_5506717_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(ss_ticket_number#1215L, ss_customer_sk#1209, ss_addr_sk#1212, s_city#400, MakeDecimal(sum(UnscaledValue(ss_coupon_amt#1225)),17,2) AS amt#3544, MakeDecimal(sum(UnscaledValue(ss_net_profit#1228)),17,2) AS profit#3545)
    // Input: ListBuffer(ss_customer_sk#1209, ss_addr_sk#1212, ss_ticket_number#1215L, ss_coupon_amt#1225, ss_net_profit#1228, s_city#400)
    // Output: ListBuffer(ss_ticket_number#1215L, ss_customer_sk#1209, s_city#400, amt#3544, profit#3545)
    std::unordered_map<SW_Aggregate_TD_5506717_key, SW_Aggregate_TD_5506717_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_6528034_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_6528034_output.getInt32(i, 0);
        int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_6528034_output.getInt32(i, 1);
        int64_t _ss_ticket_number1215L = tbl_JOIN_INNER_TD_6528034_output.getInt64(i, 2);
        int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_6528034_output.getInt64(i, 3);
        int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_6528034_output.getInt64(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _s_city400 = tbl_JOIN_INNER_TD_6528034_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        SW_Aggregate_TD_5506717_key k{_ss_ticket_number1215L, _ss_customer_sk1209, _ss_addr_sk1212, std::string(_s_city400.data())};
        int64_t _amt3544_sum_0 = _ss_coupon_amt1225;
        int64_t _profit3545_sum_1 = _ss_net_profit1228;
        SW_Aggregate_TD_5506717_payload p{_amt3544_sum_0, _profit3545_sum_1};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._amt3544_sum_0 + _amt3544_sum_0;
            p._amt3544_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._profit3545_sum_1 + _profit3545_sum_1;
            p._profit3545_sum_1 = sum_1;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        tbl_Aggregate_TD_5506717_output.setInt64(r, 0, (it.first)._ss_ticket_number1215L);
        tbl_Aggregate_TD_5506717_output.setInt32(r, 1, (it.first)._ss_customer_sk1209);
        // _ss_addr_sk1212 not required in the output table
        std::array<char, TPCDS_READ_MAX + 1> _s_city400{};
        memcpy(_s_city400.data(), ((it.first)._s_city400).data(), ((it.first)._s_city400).length());
        tbl_Aggregate_TD_5506717_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_city400);
        int64_t _amt3544 = (it.second)._amt3544_sum_0;
        tbl_Aggregate_TD_5506717_output.setInt64(r, 3, _amt3544);
        int64_t _profit3545 = (it.second)._profit3545_sum_1;
        tbl_Aggregate_TD_5506717_output.setInt64(r, 4, _profit3545);
        ++r;
    }
    tbl_Aggregate_TD_5506717_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_5506717_output #Row: " << tbl_Aggregate_TD_5506717_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4274840_key_leftMajor {
    int32_t _ss_customer_sk1209;
    bool operator==(const SW_JOIN_INNER_TD_4274840_key_leftMajor& other) const {
        return ((_ss_customer_sk1209 == other._ss_customer_sk1209));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4274840_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4274840_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_customer_sk1209));
    }
};
}
struct SW_JOIN_INNER_TD_4274840_payload_leftMajor {
    int64_t _ss_ticket_number1215L;
    int32_t _ss_customer_sk1209;
    std::string _s_city400;
    int64_t _amt3544;
    int64_t _profit3545;
};
struct SW_JOIN_INNER_TD_4274840_key_rightMajor {
    int32_t _c_customer_sk0;
    bool operator==(const SW_JOIN_INNER_TD_4274840_key_rightMajor& other) const {
        return ((_c_customer_sk0 == other._c_customer_sk0));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4274840_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4274840_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk0));
    }
};
}
struct SW_JOIN_INNER_TD_4274840_payload_rightMajor {
    int32_t _c_customer_sk0;
    std::string _c_first_name8;
    std::string _c_last_name9;
};
void SW_JOIN_INNER_TD_4274840(Table &tbl_Aggregate_TD_5506717_output, Table &tbl_Filter_TD_5980825_output, Table &tbl_JOIN_INNER_TD_4274840_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_customer_sk#1209 = c_customer_sk#0))
    // Left Table: ListBuffer(ss_ticket_number#1215L, ss_customer_sk#1209, s_city#400, amt#3544, profit#3545)
    // Right Table: ListBuffer(c_customer_sk#0, c_first_name#8, c_last_name#9)
    // Output Table: ListBuffer(c_last_name#9, c_first_name#8, s_city#400, ss_ticket_number#1215L, amt#3544, profit#3545)
    int left_nrow = tbl_Aggregate_TD_5506717_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5980825_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4274840_key_leftMajor, SW_JOIN_INNER_TD_4274840_payload_leftMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_5506717_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_customer_sk1209_k = tbl_Aggregate_TD_5506717_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_4274840_key_leftMajor keyA{_ss_customer_sk1209_k};
            int64_t _ss_ticket_number1215L = tbl_Aggregate_TD_5506717_output.getInt64(i, 0);
            int32_t _ss_customer_sk1209 = tbl_Aggregate_TD_5506717_output.getInt32(i, 1);
            std::array<char, TPCDS_READ_MAX + 1> _s_city400_n = tbl_Aggregate_TD_5506717_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _s_city400 = std::string(_s_city400_n.data());
            int64_t _amt3544 = tbl_Aggregate_TD_5506717_output.getInt64(i, 3);
            int64_t _profit3545 = tbl_Aggregate_TD_5506717_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_4274840_payload_leftMajor payloadA{_ss_ticket_number1215L, _ss_customer_sk1209, _s_city400, _amt3544, _profit3545};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5980825_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_5980825_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4274840_key_leftMajor{_c_customer_sk0_k});
            auto it = its.first;
            while (it != its.second) {
                int64_t _ss_ticket_number1215L = (it->second)._ss_ticket_number1215L;
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                std::string _s_city400 = (it->second)._s_city400;
                std::array<char, TPCDS_READ_MAX + 1> _s_city400_n{};
                memcpy(_s_city400_n.data(), (_s_city400).data(), (_s_city400).length());
                int64_t _amt3544 = (it->second)._amt3544;
                int64_t _profit3545 = (it->second)._profit3545;
                int32_t _c_customer_sk0 = tbl_Filter_TD_5980825_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_Filter_TD_5980825_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_first_name8 = std::string(_c_first_name8_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_Filter_TD_5980825_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_last_name9 = std::string(_c_last_name9_n.data());
                tbl_JOIN_INNER_TD_4274840_output.setInt64(r, 3, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_4274840_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_city400_n);
                tbl_JOIN_INNER_TD_4274840_output.setInt64(r, 4, _amt3544);
                tbl_JOIN_INNER_TD_4274840_output.setInt64(r, 5, _profit3545);
                tbl_JOIN_INNER_TD_4274840_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
                tbl_JOIN_INNER_TD_4274840_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name9_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4274840_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4274840_key_rightMajor, SW_JOIN_INNER_TD_4274840_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5980825_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_5980825_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4274840_key_rightMajor keyA{_c_customer_sk0_k};
            int32_t _c_customer_sk0 = tbl_Filter_TD_5980825_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_Filter_TD_5980825_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_first_name8 = std::string(_c_first_name8_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_Filter_TD_5980825_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_last_name9 = std::string(_c_last_name9_n.data());
            SW_JOIN_INNER_TD_4274840_payload_rightMajor payloadA{_c_customer_sk0, _c_first_name8, _c_last_name9};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_5506717_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_customer_sk1209_k = tbl_Aggregate_TD_5506717_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4274840_key_rightMajor{_ss_customer_sk1209_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk0 = (it->second)._c_customer_sk0;
                std::string _c_first_name8 = (it->second)._c_first_name8;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n{};
                memcpy(_c_first_name8_n.data(), (_c_first_name8).data(), (_c_first_name8).length());
                std::string _c_last_name9 = (it->second)._c_last_name9;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n{};
                memcpy(_c_last_name9_n.data(), (_c_last_name9).data(), (_c_last_name9).length());
                int64_t _ss_ticket_number1215L = tbl_Aggregate_TD_5506717_output.getInt64(i, 0);
                int32_t _ss_customer_sk1209 = tbl_Aggregate_TD_5506717_output.getInt32(i, 1);
                std::array<char, TPCDS_READ_MAX + 1> _s_city400_n = tbl_Aggregate_TD_5506717_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _s_city400 = std::string(_s_city400_n.data());
                int64_t _amt3544 = tbl_Aggregate_TD_5506717_output.getInt64(i, 3);
                int64_t _profit3545 = tbl_Aggregate_TD_5506717_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_4274840_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
                tbl_JOIN_INNER_TD_4274840_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name9_n);
                tbl_JOIN_INNER_TD_4274840_output.setInt64(r, 3, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_4274840_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_city400_n);
                tbl_JOIN_INNER_TD_4274840_output.setInt64(r, 4, _amt3544);
                tbl_JOIN_INNER_TD_4274840_output.setInt64(r, 5, _profit3545);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4274840_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4274840_output #Row: " << tbl_JOIN_INNER_TD_4274840_output.getNumRow() << std::endl;
}

void SW_Project_TD_3222343(Table &tbl_JOIN_INNER_TD_4274840_output, Table &tbl_Project_TD_3222343_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(substr(s_city#400, 1, 30) AS substr(s_city, 1, 30)#3548)
    // Input: ListBuffer(c_last_name#9, c_first_name#8, s_city#400, ss_ticket_number#1215L, amt#3544, profit#3545)
    // Output: ListBuffer(c_last_name#9, c_first_name#8, substr(s_city, 1, 30)#3548, ss_ticket_number#1215L, amt#3544, profit#3545)
    int nrow1 = tbl_JOIN_INNER_TD_4274840_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9 = tbl_JOIN_INNER_TD_4274840_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8 = tbl_JOIN_INNER_TD_4274840_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _s_city400 = tbl_JOIN_INNER_TD_4274840_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        int64_t _ss_ticket_number1215L = tbl_JOIN_INNER_TD_4274840_output.getInt64(i, 3);
        int64_t _amt3544 = tbl_JOIN_INNER_TD_4274840_output.getInt64(i, 4);
        int64_t _profit3545 = tbl_JOIN_INNER_TD_4274840_output.getInt64(i, 5);
        std::string substr_s_city_1_30_str = std::string(_s_city400.data()).substr(0, 30);
        std::array<char, TPCDS_READ_MAX + 1> substr_s_city_1_30{};
        memcpy(substr_s_city_1_30.data(), substr_s_city_1_30_str.data(), (substr_s_city_1_30_str).length());
        tbl_Project_TD_3222343_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 2, substr_s_city_1_30);
        tbl_Project_TD_3222343_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 0, _c_last_name9);
        tbl_Project_TD_3222343_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 1, _c_first_name8);
        tbl_Project_TD_3222343_output.setInt64(i, 3, _ss_ticket_number1215L);
        tbl_Project_TD_3222343_output.setInt64(i, 4, _amt3544);
        tbl_Project_TD_3222343_output.setInt64(i, 5, _profit3545);
    }
    tbl_Project_TD_3222343_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_3222343_output #Row: " << tbl_Project_TD_3222343_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2609056(Table &tbl_Project_TD_3222343_output, Table &tbl_Sort_TD_2609056_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(c_last_name#9 ASC NULLS FIRST, c_first_name#8 ASC NULLS FIRST, profit#3545 ASC NULLS FIRST)
    // Input: ListBuffer(c_last_name#9, c_first_name#8, substr(s_city, 1, 30)#3548, ss_ticket_number#1215L, amt#3544, profit#3545)
    // Output: ListBuffer(c_last_name#9, c_first_name#8, substr(s_city, 1, 30)#3548, ss_ticket_number#1215L, amt#3544, profit#3545)
    struct SW_Sort_TD_2609056Row {
        std::string _c_last_name9;
        std::string _c_first_name8;
        std::string substr_s_city_1_30;
        int64_t _ss_ticket_number1215L;
        int64_t _amt3544;
        int64_t _profit3545;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2609056Row& a, const SW_Sort_TD_2609056Row& b) const { return 
 (a._c_last_name9 < b._c_last_name9) || 
 ((a._c_last_name9 == b._c_last_name9) && (a._c_first_name8 < b._c_first_name8)) || 
 ((a._c_last_name9 == b._c_last_name9) && (a._c_first_name8 == b._c_first_name8) && (a._profit3545 < b._profit3545)); 
}
    }SW_Sort_TD_2609056_order; 

    int nrow1 = tbl_Project_TD_3222343_output.getNumRow();
    std::vector<SW_Sort_TD_2609056Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9 = tbl_Project_TD_3222343_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8 = tbl_Project_TD_3222343_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> substr_s_city_1_30 = tbl_Project_TD_3222343_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        int64_t _ss_ticket_number1215L = tbl_Project_TD_3222343_output.getInt64(i, 3);
        int64_t _amt3544 = tbl_Project_TD_3222343_output.getInt64(i, 4);
        int64_t _profit3545 = tbl_Project_TD_3222343_output.getInt64(i, 5);
        SW_Sort_TD_2609056Row t = {std::string(_c_last_name9.data()),std::string(_c_first_name8.data()),std::string(substr_s_city_1_30.data()),_ss_ticket_number1215L,_amt3544,_profit3545};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2609056_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9{};
        memcpy(_c_last_name9.data(), (it._c_last_name9).data(), (it._c_last_name9).length());
        tbl_Sort_TD_2609056_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _c_last_name9);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8{};
        memcpy(_c_first_name8.data(), (it._c_first_name8).data(), (it._c_first_name8).length());
        tbl_Sort_TD_2609056_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _c_first_name8);
        std::array<char, TPCDS_READ_MAX + 1> substr_s_city_1_30{};
        memcpy(substr_s_city_1_30.data(), (it.substr_s_city_1_30).data(), (it.substr_s_city_1_30).length());
        tbl_Sort_TD_2609056_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, substr_s_city_1_30);
        tbl_Sort_TD_2609056_output.setInt64(r, 3, it._ss_ticket_number1215L);
        tbl_Sort_TD_2609056_output.setInt64(r, 4, it._amt3544);
        tbl_Sort_TD_2609056_output.setInt64(r, 5, it._profit3545);
        ++r;
    }
    tbl_Sort_TD_2609056_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2609056_output #Row: " << tbl_Sort_TD_2609056_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1569601(Table &tbl_Sort_TD_2609056_output, Table &tbl_LocalLimit_TD_1569601_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(c_last_name#9, c_first_name#8, substr(s_city, 1, 30)#3548, ss_ticket_number#1215L, amt#3544, profit#3545)
    // Output: ListBuffer(c_last_name#9, c_first_name#8, substr(s_city, 1, 30)#3548, ss_ticket_number#1215L, amt#3544, profit#3545)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_Sort_TD_2609056_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1569601_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name9_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_Sort_TD_2609056_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_1569601_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
        std::array<char, TPCDS_READ_MAX + 1> substr_s_city_1_30_n = tbl_Sort_TD_2609056_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_LocalLimit_TD_1569601_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, substr_s_city_1_30_n);
        tbl_LocalLimit_TD_1569601_output.setInt64(r, 3, tbl_Sort_TD_2609056_output.getInt64(i, 3));
        tbl_LocalLimit_TD_1569601_output.setInt64(r, 4, tbl_Sort_TD_2609056_output.getInt64(i, 4));
        tbl_LocalLimit_TD_1569601_output.setInt64(r, 5, tbl_Sort_TD_2609056_output.getInt64(i, 5));
        r++;
    }
    tbl_LocalLimit_TD_1569601_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1569601_output #Row: " << tbl_LocalLimit_TD_1569601_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0429094(Table &tbl_LocalLimit_TD_1569601_output, Table &tbl_GlobalLimit_TD_0429094_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(c_last_name#9, c_first_name#8, substr(s_city, 1, 30)#3548, ss_ticket_number#1215L, amt#3544, profit#3545)
    // Output: ListBuffer(c_last_name#9, c_first_name#8, substr(s_city, 1, 30)#3548, ss_ticket_number#1215L, amt#3544, profit#3545)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_LocalLimit_TD_1569601_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0429094_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name9_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_LocalLimit_TD_1569601_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_0429094_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
        std::array<char, TPCDS_READ_MAX + 1> substr_s_city_1_30_n = tbl_LocalLimit_TD_1569601_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_GlobalLimit_TD_0429094_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, substr_s_city_1_30_n);
        tbl_GlobalLimit_TD_0429094_output.setInt64(r, 3, tbl_LocalLimit_TD_1569601_output.getInt64(i, 3));
        tbl_GlobalLimit_TD_0429094_output.setInt64(r, 4, tbl_LocalLimit_TD_1569601_output.getInt64(i, 4));
        tbl_GlobalLimit_TD_0429094_output.setInt64(r, 5, tbl_LocalLimit_TD_1569601_output.getInt64(i, 5));
        r++;
    }
    tbl_GlobalLimit_TD_0429094_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0429094_output #Row: " << tbl_GlobalLimit_TD_0429094_output.getNumRow() << std::endl;
}

