#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_9591377(Table &tbl_SerializeFromObject_TD_10562796_input, Table &tbl_Filter_TD_9591377_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#126) AND (d_year#126 = 2001)) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10562796_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_10562796_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_10562796_input.getInt32(i, 0);
        if (((_d_year126!= 0) && (_d_year126 == 2001)) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_10562796_input.getInt32(i, 0);
            tbl_Filter_TD_9591377_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_9591377_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9591377_output #Row: " << tbl_Filter_TD_9591377_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9291015(Table &tbl_SerializeFromObject_TD_10367580_input, Table &tbl_Filter_TD_9291015_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_sold_date_sk#1206) AND (isnotnull(ss_item_sk#1208) AND isnotnull(ss_store_sk#1213))))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_store_sk#1213, ss_ext_sales_price#1221, ss_net_profit#1228)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_store_sk#1213, ss_ext_sales_price#1221, ss_net_profit#1228)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10367580_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_10367580_input.getInt32(i, 0);
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_10367580_input.getInt32(i, 1);
        int32_t _ss_store_sk1213 = tbl_SerializeFromObject_TD_10367580_input.getInt32(i, 2);
        if ((_ss_sold_date_sk1206!= 0) && ((_ss_item_sk1208!= 0) && (_ss_store_sk1213!= 0))) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_10367580_input.getInt32(i, 0);
            tbl_Filter_TD_9291015_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_10367580_input.getInt32(i, 1);
            tbl_Filter_TD_9291015_output.setInt32(r, 1, _ss_item_sk1208_t);
            int32_t _ss_store_sk1213_t = tbl_SerializeFromObject_TD_10367580_input.getInt32(i, 2);
            tbl_Filter_TD_9291015_output.setInt32(r, 2, _ss_store_sk1213_t);
            int64_t _ss_ext_sales_price1221_t = tbl_SerializeFromObject_TD_10367580_input.getInt64(i, 3);
            tbl_Filter_TD_9291015_output.setInt64(r, 3, _ss_ext_sales_price1221_t);
            int64_t _ss_net_profit1228_t = tbl_SerializeFromObject_TD_10367580_input.getInt64(i, 4);
            tbl_Filter_TD_9291015_output.setInt64(r, 4, _ss_net_profit1228_t);
            r++;
        }
    }
    tbl_Filter_TD_9291015_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9291015_output #Row: " << tbl_Filter_TD_9291015_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8555915(Table &tbl_SerializeFromObject_TD_996716_input, Table &tbl_Filter_TD_8555915_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#228))
    // Input: ListBuffer(i_item_sk#228, i_class#238, i_category#240)
    // Output: ListBuffer(i_item_sk#228, i_class#238, i_category#240)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_996716_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_996716_input.getInt32(i, 0);
        if (_i_item_sk228!= 0) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_996716_input.getInt32(i, 0);
            tbl_Filter_TD_8555915_output.setInt32(r, 0, _i_item_sk228_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_class238_t = tbl_SerializeFromObject_TD_996716_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_8555915_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_class238_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_t = tbl_SerializeFromObject_TD_996716_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_8555915_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_category240_t);
            r++;
        }
    }
    tbl_Filter_TD_8555915_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8555915_output #Row: " << tbl_Filter_TD_8555915_output.getNumRow() << std::endl;
}


void SW_Filter_TD_7998377(Table &tbl_SerializeFromObject_TD_8119232_input, Table &tbl_Filter_TD_7998377_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(s_state#402) AND (s_state#402 = TN)) AND isnotnull(s_store_sk#378)))
    // Input: ListBuffer(s_store_sk#378, s_state#402)
    // Output: ListBuffer(s_store_sk#378)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8119232_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_state402 = tbl_SerializeFromObject_TD_8119232_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _s_store_sk378 = tbl_SerializeFromObject_TD_8119232_input.getInt32(i, 0);
        if ((_s_state402.data() != "NULL" && (std::string(_s_state402.data()) == "TN")) && (_s_store_sk378!= 0)) {
            int32_t _s_store_sk378_t = tbl_SerializeFromObject_TD_8119232_input.getInt32(i, 0);
            tbl_Filter_TD_7998377_output.setInt32(r, 0, _s_store_sk378_t);
            r++;
        }
    }
    tbl_Filter_TD_7998377_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7998377_output #Row: " << tbl_Filter_TD_7998377_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_7367178_key_leftMajor {
    int32_t _ss_item_sk1208;
    bool operator==(const SW_JOIN_INNER_TD_7367178_key_leftMajor& other) const {
        return ((_ss_item_sk1208 == other._ss_item_sk1208));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7367178_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7367178_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk1208));
    }
};
}
struct SW_JOIN_INNER_TD_7367178_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int32_t _ss_store_sk1213;
    int64_t _ss_ext_sales_price1221;
    int64_t _ss_net_profit1228;
};
struct SW_JOIN_INNER_TD_7367178_key_rightMajor {
    int32_t _i_item_sk228;
    bool operator==(const SW_JOIN_INNER_TD_7367178_key_rightMajor& other) const {
        return ((_i_item_sk228 == other._i_item_sk228));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7367178_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7367178_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk228));
    }
};
}
struct SW_JOIN_INNER_TD_7367178_payload_rightMajor {
    int32_t _i_item_sk228;
    std::string _i_class238;
    std::string _i_category240;
};
void SW_JOIN_INNER_TD_7367178(Table &tbl_JOIN_INNER_TD_8999891_output, Table &tbl_Filter_TD_8555915_output, Table &tbl_JOIN_INNER_TD_7367178_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((i_item_sk#228 = ss_item_sk#1208))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_store_sk#1213, ss_ext_sales_price#1221, ss_net_profit#1228)
    // Right Table: ListBuffer(i_item_sk#228, i_class#238, i_category#240)
    // Output Table: ListBuffer(ss_store_sk#1213, ss_ext_sales_price#1221, ss_net_profit#1228, i_class#238, i_category#240)
    int left_nrow = tbl_JOIN_INNER_TD_8999891_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8555915_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7367178_key_leftMajor, SW_JOIN_INNER_TD_7367178_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_8999891_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_8999891_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7367178_key_leftMajor keyA{_ss_item_sk1208_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_8999891_output.getInt32(i, 0);
            int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_8999891_output.getInt32(i, 1);
            int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_8999891_output.getInt64(i, 2);
            int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_8999891_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_7367178_payload_leftMajor payloadA{_ss_item_sk1208, _ss_store_sk1213, _ss_ext_sales_price1221, _ss_net_profit1228};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8555915_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_8555915_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7367178_key_leftMajor{_i_item_sk228_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_store_sk1213 = (it->second)._ss_store_sk1213;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int64_t _ss_net_profit1228 = (it->second)._ss_net_profit1228;
                int32_t _i_item_sk228 = tbl_Filter_TD_8555915_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_class238_n = tbl_Filter_TD_8555915_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_class238 = std::string(_i_class238_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_Filter_TD_8555915_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _i_category240 = std::string(_i_category240_n.data());
                tbl_JOIN_INNER_TD_7367178_output.setInt32(r, 0, _ss_store_sk1213);
                tbl_JOIN_INNER_TD_7367178_output.setInt64(r, 1, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_7367178_output.setInt64(r, 2, _ss_net_profit1228);
                tbl_JOIN_INNER_TD_7367178_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _i_class238_n);
                tbl_JOIN_INNER_TD_7367178_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _i_category240_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7367178_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7367178_key_rightMajor, SW_JOIN_INNER_TD_7367178_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8555915_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_8555915_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7367178_key_rightMajor keyA{_i_item_sk228_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_8555915_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_class238_n = tbl_Filter_TD_8555915_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_class238 = std::string(_i_class238_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_Filter_TD_8555915_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _i_category240 = std::string(_i_category240_n.data());
            SW_JOIN_INNER_TD_7367178_payload_rightMajor payloadA{_i_item_sk228, _i_class238, _i_category240};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_8999891_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_8999891_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7367178_key_rightMajor{_ss_item_sk1208_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                std::string _i_class238 = (it->second)._i_class238;
                std::array<char, TPCDS_READ_MAX + 1> _i_class238_n{};
                memcpy(_i_class238_n.data(), (_i_class238).data(), (_i_class238).length());
                std::string _i_category240 = (it->second)._i_category240;
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n{};
                memcpy(_i_category240_n.data(), (_i_category240).data(), (_i_category240).length());
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_8999891_output.getInt32(i, 0);
                int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_8999891_output.getInt32(i, 1);
                int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_8999891_output.getInt64(i, 2);
                int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_8999891_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_7367178_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _i_class238_n);
                tbl_JOIN_INNER_TD_7367178_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _i_category240_n);
                tbl_JOIN_INNER_TD_7367178_output.setInt32(r, 0, _ss_store_sk1213);
                tbl_JOIN_INNER_TD_7367178_output.setInt64(r, 1, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_7367178_output.setInt64(r, 2, _ss_net_profit1228);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7367178_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7367178_output #Row: " << tbl_JOIN_INNER_TD_7367178_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6960671_key_leftMajor {
    int32_t _ss_store_sk1213;
    bool operator==(const SW_JOIN_INNER_TD_6960671_key_leftMajor& other) const {
        return ((_ss_store_sk1213 == other._ss_store_sk1213));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6960671_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6960671_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_store_sk1213));
    }
};
}
struct SW_JOIN_INNER_TD_6960671_payload_leftMajor {
    int32_t _ss_store_sk1213;
    int64_t _ss_ext_sales_price1221;
    int64_t _ss_net_profit1228;
    std::string _i_class238;
    std::string _i_category240;
};
struct SW_JOIN_INNER_TD_6960671_key_rightMajor {
    int32_t _s_store_sk378;
    bool operator==(const SW_JOIN_INNER_TD_6960671_key_rightMajor& other) const {
        return ((_s_store_sk378 == other._s_store_sk378));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6960671_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6960671_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_store_sk378));
    }
};
}
struct SW_JOIN_INNER_TD_6960671_payload_rightMajor {
    int32_t _s_store_sk378;
};
void SW_JOIN_INNER_TD_6960671(Table &tbl_JOIN_INNER_TD_7367178_output, Table &tbl_Filter_TD_7998377_output, Table &tbl_JOIN_INNER_TD_6960671_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((s_store_sk#378 = ss_store_sk#1213))
    // Left Table: ListBuffer(ss_store_sk#1213, ss_ext_sales_price#1221, ss_net_profit#1228, i_class#238, i_category#240)
    // Right Table: ListBuffer(s_store_sk#378)
    // Output Table: ListBuffer(ss_ext_sales_price#1221, ss_net_profit#1228, i_category#240, i_class#238)
    int left_nrow = tbl_JOIN_INNER_TD_7367178_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7998377_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6960671_key_leftMajor, SW_JOIN_INNER_TD_6960671_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7367178_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_store_sk1213_k = tbl_JOIN_INNER_TD_7367178_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6960671_key_leftMajor keyA{_ss_store_sk1213_k};
            int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_7367178_output.getInt32(i, 0);
            int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_7367178_output.getInt64(i, 1);
            int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_7367178_output.getInt64(i, 2);
            std::array<char, TPCDS_READ_MAX + 1> _i_class238_n = tbl_JOIN_INNER_TD_7367178_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _i_class238 = std::string(_i_class238_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_JOIN_INNER_TD_7367178_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _i_category240 = std::string(_i_category240_n.data());
            SW_JOIN_INNER_TD_6960671_payload_leftMajor payloadA{_ss_store_sk1213, _ss_ext_sales_price1221, _ss_net_profit1228, _i_class238, _i_category240};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7998377_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_7998377_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6960671_key_leftMajor{_s_store_sk378_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_store_sk1213 = (it->second)._ss_store_sk1213;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int64_t _ss_net_profit1228 = (it->second)._ss_net_profit1228;
                std::string _i_class238 = (it->second)._i_class238;
                std::array<char, TPCDS_READ_MAX + 1> _i_class238_n{};
                memcpy(_i_class238_n.data(), (_i_class238).data(), (_i_class238).length());
                std::string _i_category240 = (it->second)._i_category240;
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n{};
                memcpy(_i_category240_n.data(), (_i_category240).data(), (_i_category240).length());
                int32_t _s_store_sk378 = tbl_Filter_TD_7998377_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_6960671_output.setInt64(r, 0, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_6960671_output.setInt64(r, 1, _ss_net_profit1228);
                tbl_JOIN_INNER_TD_6960671_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _i_class238_n);
                tbl_JOIN_INNER_TD_6960671_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_category240_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6960671_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6960671_key_rightMajor, SW_JOIN_INNER_TD_6960671_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7998377_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_7998377_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6960671_key_rightMajor keyA{_s_store_sk378_k};
            int32_t _s_store_sk378 = tbl_Filter_TD_7998377_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6960671_payload_rightMajor payloadA{_s_store_sk378};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7367178_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_store_sk1213_k = tbl_JOIN_INNER_TD_7367178_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6960671_key_rightMajor{_ss_store_sk1213_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _s_store_sk378 = (it->second)._s_store_sk378;
                int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_7367178_output.getInt32(i, 0);
                int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_7367178_output.getInt64(i, 1);
                int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_7367178_output.getInt64(i, 2);
                std::array<char, TPCDS_READ_MAX + 1> _i_class238_n = tbl_JOIN_INNER_TD_7367178_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _i_class238 = std::string(_i_class238_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_JOIN_INNER_TD_7367178_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _i_category240 = std::string(_i_category240_n.data());
                tbl_JOIN_INNER_TD_6960671_output.setInt64(r, 0, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_6960671_output.setInt64(r, 1, _ss_net_profit1228);
                tbl_JOIN_INNER_TD_6960671_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _i_class238_n);
                tbl_JOIN_INNER_TD_6960671_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_category240_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6960671_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6960671_output #Row: " << tbl_JOIN_INNER_TD_6960671_output.getNumRow() << std::endl;
}

void SW_Expand_TD_5642293(Table &tbl_JOIN_INNER_TD_6960671_output, Table &tbl_Expand_TD_5642293_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Expand
    // Operation: ListBuffer(Expand)
    // Input: ListBuffer(ss_ext_sales_price#1221, ss_net_profit#1228, i_category#240, i_class#238)
    // Output: ListBuffer(ss_ext_sales_price#1221, ss_net_profit#1228, i_category#3556, i_class#3557, spark_grouping_id#3555L)
    std::cout << "tbl_Expand_TD_5642293_output #Row: " << tbl_Expand_TD_5642293_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_4374802_key {
    std::string _i_category3556;
    std::string _i_class3557;
    int64_t _spark_grouping_id3555L;
    bool operator==(const SW_Aggregate_TD_4374802_key& other) const { return (_i_category3556 == other._i_category3556) && (_i_class3557 == other._i_class3557) && (_spark_grouping_id3555L == other._spark_grouping_id3555L); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_4374802_key> {
    std::size_t operator() (const SW_Aggregate_TD_4374802_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_category3556)) + (hash<string>()(k._i_class3557)) + (hash<int64_t>()(k._spark_grouping_id3555L));
    }
};
}
struct SW_Aggregate_TD_4374802_payload {
    int64_t _gross_margin3544_sum_0;
    int64_t _gross_margin3544_sum_1;
    int32_t _lochierarchy3545;
    int32_t __w13570;
    std::string __w23571;
    int64_t __w33572_sum_2;
    int64_t __w33572_sum_3;
};
void SW_Aggregate_TD_4374802(Table &tbl_Expand_TD_5642293_output, Table &tbl_Aggregate_TD_4374802_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(i_category#3556, i_class#3557, spark_grouping_id#3555L, CheckOverflow((promote_precision(MakeDecimal(sum(UnscaledValue(ss_net_profit#1228)),17,2)) / promote_precision(MakeDecimal(sum(UnscaledValue(ss_ext_sales_price#1221)),17,2))), DecimalType(37,20), true) AS gross_margin#3544, (cast((shiftright(spark_grouping_id#3555L, 1) & 1) as tinyint) + cast((shiftright(spark_grouping_id#3555L, 0) & 1) as tinyint)) AS lochierarchy#3545, (cast((shiftright(spark_grouping_id#3555L, 1) & 1) as tinyint) + cast((shiftright(spark_grouping_id#3555L, 0) & 1) as tinyint)) AS _w1#3570, CASE WHEN (cast((shiftright(spark_grouping_id#3555L, 0) & 1) as tinyint) = 0) THEN i_category#3556 END AS _w2#3571, CheckOverflow((promote_precision(MakeDecimal(sum(UnscaledValue(ss_net_profit#1228)),17,2)) / promote_precision(MakeDecimal(sum(UnscaledValue(ss_ext_sales_price#1221)),17,2))), DecimalType(37,20), true) AS _w3#3572)
    // Input: ListBuffer(ss_ext_sales_price#1221, ss_net_profit#1228, i_category#3556, i_class#3557, spark_grouping_id#3555L)
    // Output: ListBuffer(gross_margin#3544, i_category#3556, i_class#3557, lochierarchy#3545, _w1#3570, _w2#3571, _w3#3572)
    std::unordered_map<SW_Aggregate_TD_4374802_key, SW_Aggregate_TD_4374802_payload> ht1;
    int nrow1 = tbl_Expand_TD_5642293_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ss_ext_sales_price1221 = tbl_Expand_TD_5642293_output.getInt64(i, 0);
        int64_t _ss_net_profit1228 = tbl_Expand_TD_5642293_output.getInt64(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _i_category3556 = tbl_Expand_TD_5642293_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _i_class3557 = tbl_Expand_TD_5642293_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        int64_t _spark_grouping_id3555L = tbl_Expand_TD_5642293_output.getInt64(i, 4);
        SW_Aggregate_TD_4374802_key k{std::string(_i_category3556.data()), std::string(_i_class3557.data()), _spark_grouping_id3555L};
        int64_t _gross_margin3544_sum_0 = _ss_net_profit1228;
        int64_t _gross_margin3544_sum_1 = _ss_ext_sales_price1221;
        int32_t _lochierarchy3545 = (_spark_grouping_id3555L + _spark_grouping_id3555L);
        int32_t __w13570 = (_spark_grouping_id3555L + _spark_grouping_id3555L);
        std::array<char, TPCDS_READ_MAX + 1> __w23571 = (_spark_grouping_id3555L == 0) ? _i_category3556 : 1;
        int64_t __w33572_sum_2 = _ss_net_profit1228;
        int64_t __w33572_sum_3 = _ss_ext_sales_price1221;
        SW_Aggregate_TD_4374802_payload p{_gross_margin3544_sum_0, _gross_margin3544_sum_1, _lochierarchy3545, __w13570, std::string(__w23571.data()), __w33572_sum_2, __w33572_sum_3};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._gross_margin3544_sum_0 + _gross_margin3544_sum_0;
            p._gross_margin3544_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._gross_margin3544_sum_1 + _gross_margin3544_sum_1;
            p._gross_margin3544_sum_1 = sum_1;
            int64_t sum_2 = (it->second).__w33572_sum_2 + __w33572_sum_2;
            p.__w33572_sum_2 = sum_2;
            int64_t sum_3 = (it->second).__w33572_sum_3 + __w33572_sum_3;
            p.__w33572_sum_3 = sum_3;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category3556{};
        memcpy(_i_category3556.data(), ((it.first)._i_category3556).data(), ((it.first)._i_category3556).length());
        tbl_Aggregate_TD_4374802_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category3556);
        std::array<char, TPCDS_READ_MAX + 1> _i_class3557{};
        memcpy(_i_class3557.data(), ((it.first)._i_class3557).data(), ((it.first)._i_class3557).length());
        tbl_Aggregate_TD_4374802_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_class3557);
        // _spark_grouping_id3555L not required in the output table
        int64_t _gross_margin3544 = ((it.second)._gross_margin3544_sum_0 / (it.second)._gross_margin3544_sum_1);
        tbl_Aggregate_TD_4374802_output.setInt64(r, 0, _gross_margin3544);
        tbl_Aggregate_TD_4374802_output.setInt32(r, 3, (it.second)._lochierarchy3545);
        tbl_Aggregate_TD_4374802_output.setInt32(r, 4, (it.second).__w13570);
        tbl_Aggregate_TD_4374802_output.setInt64(r, 5, (it.second).__w23571);
        int64_t __w33572 = ((it.second).__w33572_sum_2 / (it.second).__w33572_sum_3);
        tbl_Aggregate_TD_4374802_output.setInt64(r, 6, __w33572);
        ++r;
    }
    tbl_Aggregate_TD_4374802_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_4374802_output #Row: " << tbl_Aggregate_TD_4374802_output.getNumRow() << std::endl;
}

void SW_Window_TD_3768571(Table &tbl_Aggregate_TD_4374802_output, Table &tbl_Window_TD_3768571_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Window
    // Operation: ListBuffer(rank(_w3#3572) windowspecdefinition(_w1#3570, _w2#3571, _w3#3572 ASC NULLS FIRST, specifiedwindowframe(RowFrame, unboundedpreceding$(), currentrow$())) AS rank_within_parent#3546)
    // Input: ListBuffer(gross_margin#3544, i_category#3556, i_class#3557, lochierarchy#3545, _w1#3570, _w2#3571, _w3#3572)
    // Output: ListBuffer(gross_margin#3544, i_category#3556, i_class#3557, lochierarchy#3545, _w1#3570, _w2#3571, _w3#3572, rank_within_parent#3546)
    struct SW_Window_TD_3768571Row {
        int64_t _gross_margin3544;
        std::string _i_category3556;
        std::string _i_class3557;
        int32_t _lochierarchy3545;
        int32_t __w13570;
        int64_t __w23571;
        int64_t __w33572;
    }; 

    int nrow = tbl_Aggregate_TD_4374802_output.getNumRow();
    std::vector<SW_Window_TD_3768571Row> rows0;
    int r = 0;
    for (int i = 0; i < nrow; i++) {
        int64_t _gross_margin3544 = tbl_Aggregate_TD_4374802_output.getInt64(i, 0);
        tbl_Window_TD_3768571_output.setInt64(r, 0,_gross_margin3544);
        std::array<char, TPCDS_READ_MAX + 1> _i_category3556 = tbl_Aggregate_TD_4374802_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        tbl_Window_TD_3768571_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _i_category3556);
        std::array<char, TPCDS_READ_MAX + 1> _i_class3557 = tbl_Aggregate_TD_4374802_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        tbl_Window_TD_3768571_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _i_class3557);
        int32_t _lochierarchy3545 = tbl_Aggregate_TD_4374802_output.getInt32(i, 3);
        tbl_Window_TD_3768571_output.setInt32(r, 3,_lochierarchy3545);
        int32_t __w13570 = tbl_Aggregate_TD_4374802_output.getInt32(i, 4);
        tbl_Window_TD_3768571_output.setInt32(r, 4,__w13570);
        int64_t __w23571 = tbl_Aggregate_TD_4374802_output.getInt64(i, 5);
        tbl_Window_TD_3768571_output.setInt64(r, 5,__w23571);
        int64_t __w33572 = tbl_Aggregate_TD_4374802_output.getInt64(i, 6);
        tbl_Window_TD_3768571_output.setInt64(r, 6,__w33572);
        r++;
        SW_Window_TD_3768571Row t = {_gross_margin3544,std::string(_i_category3556.data()),std::string(_i_class3557.data()),_lochierarchy3545,__w13570,__w23571,__w33572};
        rows0.push_back(t);
    }
    struct {
        bool operator()(const SW_Window_TD_3768571Row& a, const SW_Window_TD_3768571Row& b) const { return 
(a.__w13570 < b.__w13570) || 
 ((a.__w13570 == b.__w13570) && (a.__w23571 < b.__w23571)) || 
 ((a.__w13570 == b.__w13570) && (a.__w23571 == b.__w23571) && (a.__w33572 < b.__w33572)); 
}
    }SW_Window_TD_3768571_order0; 

    std::sort(rows0.begin(), rows0.end(), SW_Window_TD_3768571_order0);
    std::vector<int32_t> ranks0(rows0.size(), 0);
    int32_t currentRank0 = 0;
    int32_t currentPartitionCount0 = 1;
    bool isSamePartition0 = true;
    bool isSameOrderKey0 = true;
    if (!rows0.empty()) {;
      ranks0[0] = ++currentRank0;
    };
    for (int i = 1; i< rows0.size(); i++) {
        isSamePartition0 = ( rows0[i].__w13570 == rows0[i-1].__w13570 && rows0[i].__w23571 == rows0[i-1].__w23571);
        isSameOrderKey0 = ( rows0[i].__w33572 == rows0[i-1].__w33572);
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
        tbl_Window_TD_3768571_output.setInt32(r, 7, ranks0[i]);
    }
    tbl_Window_TD_3768571_output.setNumRow(r);
    std::cout << "tbl_Window_TD_3768571_output #Row: " << tbl_Window_TD_3768571_output.getNumRow() << std::endl;
}

void SW_Sort_TD_294355(Table &tbl_Window_TD_3768571_output, Table &tbl_Sort_TD_294355_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(lochierarchy#3545 DESC NULLS LAST, CASE WHEN (lochierarchy#3545 = 0) THEN i_category#3556 END ASC NULLS FIRST, rank_within_parent#3546 ASC NULLS FIRST)
    // Input: ListBuffer(gross_margin#3544, i_category#3556, i_class#3557, lochierarchy#3545, _w1#3570, _w2#3571, _w3#3572, rank_within_parent#3546)
    // Output: ListBuffer(gross_margin#3544, i_category#3556, i_class#3557, lochierarchy#3545, rank_within_parent#3546)
    struct SW_Sort_TD_294355Row {
        int64_t _gross_margin3544;
        std::string _i_category3556;
        std::string _i_class3557;
        int32_t _lochierarchy3545;
        int32_t __w13570;
        int64_t __w23571;
        int64_t __w33572;
        int32_t _rank_within_parent3546;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_294355Row& a, const SW_Sort_TD_294355Row& b) const { return 
 (a._lochierarchy3545 > b._lochierarchy3545) || 
 ((a._lochierarchy3545 == b._lochierarchy3545) && (a._lochierarchy3545 < b._lochierarchy3545)) || 
 ((a._lochierarchy3545 == b._lochierarchy3545) && (a._lochierarchy3545 == b._lochierarchy3545) && (a._rank_within_parent3546 < b._rank_within_parent3546)); 
}
    }SW_Sort_TD_294355_order; 

    int nrow1 = tbl_Window_TD_3768571_output.getNumRow();
    std::vector<SW_Sort_TD_294355Row> rows;
    for (int i = 0; i < nrow1; i++) {
        int64_t _gross_margin3544 = tbl_Window_TD_3768571_output.getInt64(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_category3556 = tbl_Window_TD_3768571_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _i_class3557 = tbl_Window_TD_3768571_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        int32_t _lochierarchy3545 = tbl_Window_TD_3768571_output.getInt32(i, 3);
        int32_t __w13570 = tbl_Window_TD_3768571_output.getInt32(i, 4);
        int64_t __w23571 = tbl_Window_TD_3768571_output.getInt64(i, 5);
        int64_t __w33572 = tbl_Window_TD_3768571_output.getInt64(i, 6);
        int32_t _rank_within_parent3546 = tbl_Window_TD_3768571_output.getInt32(i, 7);
        SW_Sort_TD_294355Row t = {_gross_margin3544,std::string(_i_category3556.data()),std::string(_i_class3557.data()),_lochierarchy3545,__w13570,__w23571,__w33572,_rank_within_parent3546};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_294355_order);
    int r = 0;
    for (auto& it : rows) {
        tbl_Sort_TD_294355_output.setInt64(r, 0, it._gross_margin3544);
        std::array<char, TPCDS_READ_MAX + 1> _i_category3556{};
        memcpy(_i_category3556.data(), (it._i_category3556).data(), (it._i_category3556).length());
        tbl_Sort_TD_294355_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _i_category3556);
        std::array<char, TPCDS_READ_MAX + 1> _i_class3557{};
        memcpy(_i_class3557.data(), (it._i_class3557).data(), (it._i_class3557).length());
        tbl_Sort_TD_294355_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _i_class3557);
        tbl_Sort_TD_294355_output.setInt32(r, 3, it._lochierarchy3545);
        tbl_Sort_TD_294355_output.setInt32(r, 4, it._rank_within_parent3546);
        ++r;
    }
    tbl_Sort_TD_294355_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_294355_output #Row: " << tbl_Sort_TD_294355_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_147152(Table &tbl_Sort_TD_294355_output, Table &tbl_LocalLimit_TD_147152_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(gross_margin#3544, i_category#3556, i_class#3557, lochierarchy#3545, rank_within_parent#3546)
    // Output: ListBuffer(gross_margin#3544, i_category#3556, i_class#3557, lochierarchy#3545, rank_within_parent#3546)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        tbl_LocalLimit_TD_147152_output.setInt64(r, 0, tbl_Sort_TD_294355_output.getInt64(i, 0));
        std::array<char, TPCDS_READ_MAX + 1> _i_category3556_n = tbl_Sort_TD_294355_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_147152_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category3556_n);
        std::array<char, TPCDS_READ_MAX + 1> _i_class3557_n = tbl_Sort_TD_294355_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_LocalLimit_TD_147152_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_class3557_n);
        tbl_LocalLimit_TD_147152_output.setInt32(r, 3, tbl_Sort_TD_294355_output.getInt32(i, 3));
        tbl_LocalLimit_TD_147152_output.setInt32(r, 4, tbl_Sort_TD_294355_output.getInt32(i, 4));
        r++;
    }
    tbl_LocalLimit_TD_147152_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_147152_output #Row: " << tbl_LocalLimit_TD_147152_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0739015(Table &tbl_LocalLimit_TD_147152_output, Table &tbl_GlobalLimit_TD_0739015_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(gross_margin#3544, i_category#3556, i_class#3557, lochierarchy#3545, rank_within_parent#3546)
    // Output: ListBuffer(gross_margin#3544, i_category#3556, i_class#3557, lochierarchy#3545, rank_within_parent#3546)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        tbl_GlobalLimit_TD_0739015_output.setInt64(r, 0, tbl_LocalLimit_TD_147152_output.getInt64(i, 0));
        std::array<char, TPCDS_READ_MAX + 1> _i_category3556_n = tbl_LocalLimit_TD_147152_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_0739015_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category3556_n);
        std::array<char, TPCDS_READ_MAX + 1> _i_class3557_n = tbl_LocalLimit_TD_147152_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_GlobalLimit_TD_0739015_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_class3557_n);
        tbl_GlobalLimit_TD_0739015_output.setInt32(r, 3, tbl_LocalLimit_TD_147152_output.getInt32(i, 3));
        tbl_GlobalLimit_TD_0739015_output.setInt32(r, 4, tbl_LocalLimit_TD_147152_output.getInt32(i, 4));
        r++;
    }
    tbl_GlobalLimit_TD_0739015_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0739015_output #Row: " << tbl_GlobalLimit_TD_0739015_output.getNumRow() << std::endl;
}

