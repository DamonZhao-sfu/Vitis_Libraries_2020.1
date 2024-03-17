#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_6222323(Table &tbl_SerializeFromObject_TD_7411555_input, Table &tbl_Filter_TD_6222323_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(s_store_sk#378))
    // Input: ListBuffer(s_store_sk#378)
    // Output: ListBuffer(s_store_sk#378)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7411555_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _s_store_sk378 = tbl_SerializeFromObject_TD_7411555_input.getInt32(i, 0);
        if (_s_store_sk378!= 0) {
            int32_t _s_store_sk378_t = tbl_SerializeFromObject_TD_7411555_input.getInt32(i, 0);
            tbl_Filter_TD_6222323_output.setInt32(r, 0, _s_store_sk378_t);
            r++;
        }
    }
    tbl_Filter_TD_6222323_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6222323_output #Row: " << tbl_Filter_TD_6222323_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6882769(Table &tbl_SerializeFromObject_TD_7568957_input, Table &tbl_Filter_TD_6882769_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ss_store_sk#1213) AND (((isnotnull(ss_addr_sk#1212) AND isnotnull(ss_sold_date_sk#1206)) AND isnotnull(ss_cdemo_sk#1210)) AND isnotnull(ss_hdemo_sk#1211))) AND ((((ss_net_profit#1228 >= 100.00) AND (ss_net_profit#1228 <= 200.00)) OR ((ss_net_profit#1228 >= 150.00) AND (ss_net_profit#1228 <= 300.00))) OR ((ss_net_profit#1228 >= 50.00) AND (ss_net_profit#1228 <= 250.00)))))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_store_sk#1213, ss_quantity#1216, ss_ext_sales_price#1221, ss_ext_wholesale_cost#1222, ss_net_profit#1228)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_store_sk#1213, ss_quantity#1216, ss_ext_sales_price#1221, ss_ext_wholesale_cost#1222, ss_net_profit#1228)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7568957_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_store_sk1213 = tbl_SerializeFromObject_TD_7568957_input.getInt32(i, 4);
        int32_t _ss_addr_sk1212 = tbl_SerializeFromObject_TD_7568957_input.getInt32(i, 3);
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_7568957_input.getInt32(i, 0);
        int32_t _ss_cdemo_sk1210 = tbl_SerializeFromObject_TD_7568957_input.getInt32(i, 1);
        int32_t _ss_hdemo_sk1211 = tbl_SerializeFromObject_TD_7568957_input.getInt32(i, 2);
        int64_t _ss_net_profit1228 = tbl_SerializeFromObject_TD_7568957_input.getInt64(i, 8);
        if (((_ss_store_sk1213!= 0) && ((((_ss_addr_sk1212!= 0) && (_ss_sold_date_sk1206!= 0)) && (_ss_cdemo_sk1210!= 0)) && (_ss_hdemo_sk1211!= 0))) && ((((_ss_net_profit1228 >= 100.00) && (_ss_net_profit1228 <= 200.00)) || ((_ss_net_profit1228 >= 150.00) && (_ss_net_profit1228 <= 300.00))) || ((_ss_net_profit1228 >= 50.00) && (_ss_net_profit1228 <= 250.00)))) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_7568957_input.getInt32(i, 0);
            tbl_Filter_TD_6882769_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_cdemo_sk1210_t = tbl_SerializeFromObject_TD_7568957_input.getInt32(i, 1);
            tbl_Filter_TD_6882769_output.setInt32(r, 1, _ss_cdemo_sk1210_t);
            int32_t _ss_hdemo_sk1211_t = tbl_SerializeFromObject_TD_7568957_input.getInt32(i, 2);
            tbl_Filter_TD_6882769_output.setInt32(r, 2, _ss_hdemo_sk1211_t);
            int32_t _ss_addr_sk1212_t = tbl_SerializeFromObject_TD_7568957_input.getInt32(i, 3);
            tbl_Filter_TD_6882769_output.setInt32(r, 3, _ss_addr_sk1212_t);
            int32_t _ss_store_sk1213_t = tbl_SerializeFromObject_TD_7568957_input.getInt32(i, 4);
            tbl_Filter_TD_6882769_output.setInt32(r, 4, _ss_store_sk1213_t);
            int32_t _ss_quantity1216_t = tbl_SerializeFromObject_TD_7568957_input.getInt32(i, 5);
            tbl_Filter_TD_6882769_output.setInt32(r, 5, _ss_quantity1216_t);
            int64_t _ss_ext_sales_price1221_t = tbl_SerializeFromObject_TD_7568957_input.getInt64(i, 6);
            tbl_Filter_TD_6882769_output.setInt64(r, 6, _ss_ext_sales_price1221_t);
            int64_t _ss_ext_wholesale_cost1222_t = tbl_SerializeFromObject_TD_7568957_input.getInt64(i, 7);
            tbl_Filter_TD_6882769_output.setInt64(r, 7, _ss_ext_wholesale_cost1222_t);
            int64_t _ss_net_profit1228_t = tbl_SerializeFromObject_TD_7568957_input.getInt64(i, 8);
            tbl_Filter_TD_6882769_output.setInt64(r, 8, _ss_net_profit1228_t);
            r++;
        }
    }
    tbl_Filter_TD_6882769_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6882769_output #Row: " << tbl_Filter_TD_6882769_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5170556(Table &tbl_SerializeFromObject_TD_6366082_input, Table &tbl_Filter_TD_5170556_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(ca_country#64) AND (ca_country#64 = United States)) AND isnotnull(ca_address_sk#54)) AND ((ca_state#62 IN (TX,OH) OR ca_state#62 IN (OR,NM,KY)) OR ca_state#62 IN (VA,TX,MS))))
    // Input: ListBuffer(ca_address_sk#54, ca_state#62, ca_country#64)
    // Output: ListBuffer(ca_address_sk#54, ca_state#62)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6366082_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_country64 = tbl_SerializeFromObject_TD_6366082_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        int32_t _ca_address_sk54 = tbl_SerializeFromObject_TD_6366082_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _ca_state62 = tbl_SerializeFromObject_TD_6366082_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        auto reuse_col_str_151 = std::string(_ca_state62.data());
        auto reuse_col_str_526 = std::string(_ca_state62.data());
        auto reuse_col_str_585 = std::string(_ca_state62.data());
        if ((((_ca_country64.data() != "NULL") && (std::string(_ca_country64.data()) == "United States")) && (_ca_address_sk54!= 0)) && ((((reuse_col_str_151 == "TX") || (reuse_col_str_151 == "OH") || (0)) || ((reuse_col_str_526 == "OR") || (reuse_col_str_526 == "NM") || (reuse_col_str_526 == "KY") || (0))) || ((reuse_col_str_585 == "VA") || (reuse_col_str_585 == "TX") || (reuse_col_str_585 == "MS") || (0)))) {
            int32_t _ca_address_sk54_t = tbl_SerializeFromObject_TD_6366082_input.getInt32(i, 0);
            tbl_Filter_TD_5170556_output.setInt32(r, 0, _ca_address_sk54_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_t = tbl_SerializeFromObject_TD_6366082_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_5170556_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_state62_t);
            r++;
        }
    }
    tbl_Filter_TD_5170556_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5170556_output #Row: " << tbl_Filter_TD_5170556_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5401243_key_leftMajor {
    int32_t _ss_store_sk1213;
    bool operator==(const SW_JOIN_INNER_TD_5401243_key_leftMajor& other) const {
        return ((_ss_store_sk1213 == other._ss_store_sk1213));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5401243_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5401243_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_store_sk1213));
    }
};
}
struct SW_JOIN_INNER_TD_5401243_payload_leftMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_cdemo_sk1210;
    int32_t _ss_hdemo_sk1211;
    int32_t _ss_addr_sk1212;
    int32_t _ss_store_sk1213;
    int32_t _ss_quantity1216;
    int64_t _ss_ext_sales_price1221;
    int64_t _ss_ext_wholesale_cost1222;
    int64_t _ss_net_profit1228;
};
struct SW_JOIN_INNER_TD_5401243_key_rightMajor {
    int32_t _s_store_sk378;
    bool operator==(const SW_JOIN_INNER_TD_5401243_key_rightMajor& other) const {
        return ((_s_store_sk378 == other._s_store_sk378));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5401243_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5401243_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_store_sk378));
    }
};
}
struct SW_JOIN_INNER_TD_5401243_payload_rightMajor {
    int32_t _s_store_sk378;
};
void SW_JOIN_INNER_TD_5401243(Table &tbl_Filter_TD_6882769_output, Table &tbl_Filter_TD_6222323_output, Table &tbl_JOIN_INNER_TD_5401243_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((s_store_sk#378 = ss_store_sk#1213))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_store_sk#1213, ss_quantity#1216, ss_ext_sales_price#1221, ss_ext_wholesale_cost#1222, ss_net_profit#1228)
    // Right Table: ListBuffer(s_store_sk#378)
    // Output Table: ListBuffer(ss_sold_date_sk#1206, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_quantity#1216, ss_ext_sales_price#1221, ss_ext_wholesale_cost#1222, ss_net_profit#1228)
    int left_nrow = tbl_Filter_TD_6882769_output.getNumRow();
    int right_nrow = tbl_Filter_TD_6222323_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5401243_key_leftMajor, SW_JOIN_INNER_TD_5401243_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_6882769_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_store_sk1213_k = tbl_Filter_TD_6882769_output.getInt32(i, 4);
            SW_JOIN_INNER_TD_5401243_key_leftMajor keyA{_ss_store_sk1213_k};
            int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_6882769_output.getInt32(i, 0);
            int32_t _ss_cdemo_sk1210 = tbl_Filter_TD_6882769_output.getInt32(i, 1);
            int32_t _ss_hdemo_sk1211 = tbl_Filter_TD_6882769_output.getInt32(i, 2);
            int32_t _ss_addr_sk1212 = tbl_Filter_TD_6882769_output.getInt32(i, 3);
            int32_t _ss_store_sk1213 = tbl_Filter_TD_6882769_output.getInt32(i, 4);
            int32_t _ss_quantity1216 = tbl_Filter_TD_6882769_output.getInt32(i, 5);
            int64_t _ss_ext_sales_price1221 = tbl_Filter_TD_6882769_output.getInt64(i, 6);
            int64_t _ss_ext_wholesale_cost1222 = tbl_Filter_TD_6882769_output.getInt64(i, 7);
            int64_t _ss_net_profit1228 = tbl_Filter_TD_6882769_output.getInt64(i, 8);
            SW_JOIN_INNER_TD_5401243_payload_leftMajor payloadA{_ss_sold_date_sk1206, _ss_cdemo_sk1210, _ss_hdemo_sk1211, _ss_addr_sk1212, _ss_store_sk1213, _ss_quantity1216, _ss_ext_sales_price1221, _ss_ext_wholesale_cost1222, _ss_net_profit1228};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6222323_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_6222323_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5401243_key_leftMajor{_s_store_sk378_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_cdemo_sk1210 = (it->second)._ss_cdemo_sk1210;
                int32_t _ss_hdemo_sk1211 = (it->second)._ss_hdemo_sk1211;
                int32_t _ss_addr_sk1212 = (it->second)._ss_addr_sk1212;
                int32_t _ss_store_sk1213 = (it->second)._ss_store_sk1213;
                int32_t _ss_quantity1216 = (it->second)._ss_quantity1216;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int64_t _ss_ext_wholesale_cost1222 = (it->second)._ss_ext_wholesale_cost1222;
                int64_t _ss_net_profit1228 = (it->second)._ss_net_profit1228;
                int32_t _s_store_sk378 = tbl_Filter_TD_6222323_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_5401243_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_5401243_output.setInt32(r, 1, _ss_cdemo_sk1210);
                tbl_JOIN_INNER_TD_5401243_output.setInt32(r, 2, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_5401243_output.setInt32(r, 3, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_5401243_output.setInt32(r, 4, _ss_quantity1216);
                tbl_JOIN_INNER_TD_5401243_output.setInt64(r, 5, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_5401243_output.setInt64(r, 6, _ss_ext_wholesale_cost1222);
                tbl_JOIN_INNER_TD_5401243_output.setInt64(r, 7, _ss_net_profit1228);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5401243_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5401243_key_rightMajor, SW_JOIN_INNER_TD_5401243_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_6222323_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_6222323_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5401243_key_rightMajor keyA{_s_store_sk378_k};
            int32_t _s_store_sk378 = tbl_Filter_TD_6222323_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5401243_payload_rightMajor payloadA{_s_store_sk378};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6882769_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_store_sk1213_k = tbl_Filter_TD_6882769_output.getInt32(i, 4);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5401243_key_rightMajor{_ss_store_sk1213_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _s_store_sk378 = (it->second)._s_store_sk378;
                int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_6882769_output.getInt32(i, 0);
                int32_t _ss_cdemo_sk1210 = tbl_Filter_TD_6882769_output.getInt32(i, 1);
                int32_t _ss_hdemo_sk1211 = tbl_Filter_TD_6882769_output.getInt32(i, 2);
                int32_t _ss_addr_sk1212 = tbl_Filter_TD_6882769_output.getInt32(i, 3);
                int32_t _ss_store_sk1213 = tbl_Filter_TD_6882769_output.getInt32(i, 4);
                int32_t _ss_quantity1216 = tbl_Filter_TD_6882769_output.getInt32(i, 5);
                int64_t _ss_ext_sales_price1221 = tbl_Filter_TD_6882769_output.getInt64(i, 6);
                int64_t _ss_ext_wholesale_cost1222 = tbl_Filter_TD_6882769_output.getInt64(i, 7);
                int64_t _ss_net_profit1228 = tbl_Filter_TD_6882769_output.getInt64(i, 8);
                tbl_JOIN_INNER_TD_5401243_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_5401243_output.setInt32(r, 1, _ss_cdemo_sk1210);
                tbl_JOIN_INNER_TD_5401243_output.setInt32(r, 2, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_5401243_output.setInt32(r, 3, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_5401243_output.setInt32(r, 4, _ss_quantity1216);
                tbl_JOIN_INNER_TD_5401243_output.setInt64(r, 5, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_5401243_output.setInt64(r, 6, _ss_ext_wholesale_cost1222);
                tbl_JOIN_INNER_TD_5401243_output.setInt64(r, 7, _ss_net_profit1228);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5401243_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5401243_output #Row: " << tbl_JOIN_INNER_TD_5401243_output.getNumRow() << std::endl;
}

void SW_Filter_TD_421869(Table &tbl_SerializeFromObject_TD_5546898_input, Table &tbl_Filter_TD_421869_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#126) AND (d_year#126 = 2001)) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5546898_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_5546898_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_5546898_input.getInt32(i, 0);
        if (((_d_year126!= 0) && (_d_year126 == 2001)) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_5546898_input.getInt32(i, 0);
            tbl_Filter_TD_421869_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_421869_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_421869_output #Row: " << tbl_Filter_TD_421869_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4768430_key_leftMajor {
    int32_t _ss_addr_sk1212;
    bool operator==(const SW_JOIN_INNER_TD_4768430_key_leftMajor& other) const {
        return ((_ss_addr_sk1212 == other._ss_addr_sk1212));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4768430_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4768430_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_addr_sk1212));
    }
};
}
struct SW_JOIN_INNER_TD_4768430_payload_leftMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_cdemo_sk1210;
    int32_t _ss_hdemo_sk1211;
    int32_t _ss_addr_sk1212;
    int32_t _ss_quantity1216;
    int64_t _ss_ext_sales_price1221;
    int64_t _ss_ext_wholesale_cost1222;
    int64_t _ss_net_profit1228;
};
struct SW_JOIN_INNER_TD_4768430_key_rightMajor {
    int32_t _ca_address_sk54;
    bool operator==(const SW_JOIN_INNER_TD_4768430_key_rightMajor& other) const {
        return ((_ca_address_sk54 == other._ca_address_sk54));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4768430_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4768430_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk54));
    }
};
}
struct SW_JOIN_INNER_TD_4768430_payload_rightMajor {
    int32_t _ca_address_sk54;
    std::string _ca_state62;
};
void SW_JOIN_INNER_TD_4768430(Table &tbl_JOIN_INNER_TD_5401243_output, Table &tbl_Filter_TD_5170556_output, Table &tbl_JOIN_INNER_TD_4768430_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((ss_addr_sk#1212 = ca_address_sk#54) AND ((((ca_state#62 IN (TX,OH) AND (ss_net_profit#1228 >= 100.00)) AND (ss_net_profit#1228 <= 200.00)) OR ((ca_state#62 IN (OR,NM,KY) AND (ss_net_profit#1228 >= 150.00)) AND (ss_net_profit#1228 <= 300.00))) OR ((ca_state#62 IN (VA,TX,MS) AND (ss_net_profit#1228 >= 50.00)) AND (ss_net_profit#1228 <= 250.00)))))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_quantity#1216, ss_ext_sales_price#1221, ss_ext_wholesale_cost#1222, ss_net_profit#1228)
    // Right Table: ListBuffer(ca_address_sk#54, ca_state#62)
    // Output Table: ListBuffer(ss_sold_date_sk#1206, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_quantity#1216, ss_ext_sales_price#1221, ss_ext_wholesale_cost#1222)
    int left_nrow = tbl_JOIN_INNER_TD_5401243_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5170556_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4768430_key_leftMajor, SW_JOIN_INNER_TD_4768430_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_5401243_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_addr_sk1212_k = tbl_JOIN_INNER_TD_5401243_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_4768430_key_leftMajor keyA{_ss_addr_sk1212_k};
            int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_5401243_output.getInt32(i, 0);
            int32_t _ss_cdemo_sk1210 = tbl_JOIN_INNER_TD_5401243_output.getInt32(i, 1);
            int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_5401243_output.getInt32(i, 2);
            int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_5401243_output.getInt32(i, 3);
            int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_5401243_output.getInt32(i, 4);
            int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_5401243_output.getInt64(i, 5);
            int64_t _ss_ext_wholesale_cost1222 = tbl_JOIN_INNER_TD_5401243_output.getInt64(i, 6);
            int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_5401243_output.getInt64(i, 7);
            SW_JOIN_INNER_TD_4768430_payload_leftMajor payloadA{_ss_sold_date_sk1206, _ss_cdemo_sk1210, _ss_hdemo_sk1211, _ss_addr_sk1212, _ss_quantity1216, _ss_ext_sales_price1221, _ss_ext_wholesale_cost1222, _ss_net_profit1228};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5170556_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_5170556_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4768430_key_leftMajor{_ca_address_sk54_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_cdemo_sk1210 = (it->second)._ss_cdemo_sk1210;
                int32_t _ss_hdemo_sk1211 = (it->second)._ss_hdemo_sk1211;
                int32_t _ss_addr_sk1212 = (it->second)._ss_addr_sk1212;
                int32_t _ss_quantity1216 = (it->second)._ss_quantity1216;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int64_t _ss_ext_wholesale_cost1222 = (it->second)._ss_ext_wholesale_cost1222;
                int64_t _ss_net_profit1228 = (it->second)._ss_net_profit1228;
                int32_t _ca_address_sk54 = tbl_Filter_TD_5170556_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_Filter_TD_5170556_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_state62 = std::string(_ca_state62_n.data());
                tbl_JOIN_INNER_TD_4768430_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_4768430_output.setInt32(r, 1, _ss_cdemo_sk1210);
                tbl_JOIN_INNER_TD_4768430_output.setInt32(r, 2, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_4768430_output.setInt32(r, 3, _ss_quantity1216);
                tbl_JOIN_INNER_TD_4768430_output.setInt64(r, 4, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_4768430_output.setInt64(r, 5, _ss_ext_wholesale_cost1222);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4768430_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4768430_key_rightMajor, SW_JOIN_INNER_TD_4768430_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5170556_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_5170556_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4768430_key_rightMajor keyA{_ca_address_sk54_k};
            int32_t _ca_address_sk54 = tbl_Filter_TD_5170556_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_Filter_TD_5170556_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_state62 = std::string(_ca_state62_n.data());
            SW_JOIN_INNER_TD_4768430_payload_rightMajor payloadA{_ca_address_sk54, _ca_state62};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_5401243_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_addr_sk1212_k = tbl_JOIN_INNER_TD_5401243_output.getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4768430_key_rightMajor{_ss_addr_sk1212_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk54 = (it->second)._ca_address_sk54;
                std::string _ca_state62 = (it->second)._ca_state62;
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n{};
                memcpy(_ca_state62_n.data(), (_ca_state62).data(), (_ca_state62).length());
                int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_5401243_output.getInt32(i, 0);
                int32_t _ss_cdemo_sk1210 = tbl_JOIN_INNER_TD_5401243_output.getInt32(i, 1);
                int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_5401243_output.getInt32(i, 2);
                int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_5401243_output.getInt32(i, 3);
                int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_5401243_output.getInt32(i, 4);
                int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_5401243_output.getInt64(i, 5);
                int64_t _ss_ext_wholesale_cost1222 = tbl_JOIN_INNER_TD_5401243_output.getInt64(i, 6);
                int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_5401243_output.getInt64(i, 7);
                tbl_JOIN_INNER_TD_4768430_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_4768430_output.setInt32(r, 1, _ss_cdemo_sk1210);
                tbl_JOIN_INNER_TD_4768430_output.setInt32(r, 2, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_4768430_output.setInt32(r, 3, _ss_quantity1216);
                tbl_JOIN_INNER_TD_4768430_output.setInt64(r, 4, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_4768430_output.setInt64(r, 5, _ss_ext_wholesale_cost1222);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4768430_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4768430_output #Row: " << tbl_JOIN_INNER_TD_4768430_output.getNumRow() << std::endl;
}

void SW_Filter_TD_3998484(Table &tbl_SerializeFromObject_TD_4447020_input, Table &tbl_Filter_TD_3998484_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cd_demo_sk#93) AND ((((cd_marital_status#95 = M) AND (cd_education_status#96 = Advanced Degree)) OR ((cd_marital_status#95 = S) AND (cd_education_status#96 = College))) OR ((cd_marital_status#95 = W) AND (cd_education_status#96 = 2 yr Degree)))))
    // Input: ListBuffer(cd_demo_sk#93, cd_marital_status#95, cd_education_status#96)
    // Output: ListBuffer(cd_demo_sk#93, cd_marital_status#95, cd_education_status#96)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_4447020_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cd_demo_sk93 = tbl_SerializeFromObject_TD_4447020_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95 = tbl_SerializeFromObject_TD_4447020_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96 = tbl_SerializeFromObject_TD_4447020_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        if ((_cd_demo_sk93!= 0) && ((((std::string(_cd_marital_status95.data()) == "M") && (std::string(_cd_education_status96.data()) == "Advanced Degree")) || ((std::string(_cd_marital_status95.data()) == "S") && (std::string(_cd_education_status96.data()) == "College"))) || ((std::string(_cd_marital_status95.data()) == "W") && (std::string(_cd_education_status96.data()) == "2 yr Degree")))) {
            int32_t _cd_demo_sk93_t = tbl_SerializeFromObject_TD_4447020_input.getInt32(i, 0);
            tbl_Filter_TD_3998484_output.setInt32(r, 0, _cd_demo_sk93_t);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_t = tbl_SerializeFromObject_TD_4447020_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_3998484_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cd_marital_status95_t);
            std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_t = tbl_SerializeFromObject_TD_4447020_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_3998484_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cd_education_status96_t);
            r++;
        }
    }
    tbl_Filter_TD_3998484_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_3998484_output #Row: " << tbl_Filter_TD_3998484_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_3672673_key_leftMajor {
    int32_t _ss_sold_date_sk1206;
    bool operator==(const SW_JOIN_INNER_TD_3672673_key_leftMajor& other) const {
        return ((_ss_sold_date_sk1206 == other._ss_sold_date_sk1206));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3672673_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3672673_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_sold_date_sk1206));
    }
};
}
struct SW_JOIN_INNER_TD_3672673_payload_leftMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_cdemo_sk1210;
    int32_t _ss_hdemo_sk1211;
    int32_t _ss_quantity1216;
    int64_t _ss_ext_sales_price1221;
    int64_t _ss_ext_wholesale_cost1222;
};
struct SW_JOIN_INNER_TD_3672673_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_3672673_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3672673_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3672673_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_3672673_payload_rightMajor {
    int32_t _d_date_sk120;
};
void SW_JOIN_INNER_TD_3672673(Table &tbl_JOIN_INNER_TD_4768430_output, Table &tbl_Filter_TD_421869_output, Table &tbl_JOIN_INNER_TD_3672673_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#1206 = d_date_sk#120))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_quantity#1216, ss_ext_sales_price#1221, ss_ext_wholesale_cost#1222)
    // Right Table: ListBuffer(d_date_sk#120)
    // Output Table: ListBuffer(ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_quantity#1216, ss_ext_sales_price#1221, ss_ext_wholesale_cost#1222)
    int left_nrow = tbl_JOIN_INNER_TD_4768430_output.getNumRow();
    int right_nrow = tbl_Filter_TD_421869_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3672673_key_leftMajor, SW_JOIN_INNER_TD_3672673_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_4768430_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_JOIN_INNER_TD_4768430_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3672673_key_leftMajor keyA{_ss_sold_date_sk1206_k};
            int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_4768430_output.getInt32(i, 0);
            int32_t _ss_cdemo_sk1210 = tbl_JOIN_INNER_TD_4768430_output.getInt32(i, 1);
            int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_4768430_output.getInt32(i, 2);
            int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_4768430_output.getInt32(i, 3);
            int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_4768430_output.getInt64(i, 4);
            int64_t _ss_ext_wholesale_cost1222 = tbl_JOIN_INNER_TD_4768430_output.getInt64(i, 5);
            SW_JOIN_INNER_TD_3672673_payload_leftMajor payloadA{_ss_sold_date_sk1206, _ss_cdemo_sk1210, _ss_hdemo_sk1211, _ss_quantity1216, _ss_ext_sales_price1221, _ss_ext_wholesale_cost1222};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_421869_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_421869_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3672673_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_cdemo_sk1210 = (it->second)._ss_cdemo_sk1210;
                int32_t _ss_hdemo_sk1211 = (it->second)._ss_hdemo_sk1211;
                int32_t _ss_quantity1216 = (it->second)._ss_quantity1216;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int64_t _ss_ext_wholesale_cost1222 = (it->second)._ss_ext_wholesale_cost1222;
                int32_t _d_date_sk120 = tbl_Filter_TD_421869_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_3672673_output.setInt32(r, 0, _ss_cdemo_sk1210);
                tbl_JOIN_INNER_TD_3672673_output.setInt32(r, 1, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_3672673_output.setInt32(r, 2, _ss_quantity1216);
                tbl_JOIN_INNER_TD_3672673_output.setInt64(r, 3, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_3672673_output.setInt64(r, 4, _ss_ext_wholesale_cost1222);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3672673_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3672673_key_rightMajor, SW_JOIN_INNER_TD_3672673_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_421869_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_421869_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3672673_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_421869_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3672673_payload_rightMajor payloadA{_d_date_sk120};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_4768430_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_JOIN_INNER_TD_4768430_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3672673_key_rightMajor{_ss_sold_date_sk1206_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_4768430_output.getInt32(i, 0);
                int32_t _ss_cdemo_sk1210 = tbl_JOIN_INNER_TD_4768430_output.getInt32(i, 1);
                int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_4768430_output.getInt32(i, 2);
                int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_4768430_output.getInt32(i, 3);
                int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_4768430_output.getInt64(i, 4);
                int64_t _ss_ext_wholesale_cost1222 = tbl_JOIN_INNER_TD_4768430_output.getInt64(i, 5);
                tbl_JOIN_INNER_TD_3672673_output.setInt32(r, 0, _ss_cdemo_sk1210);
                tbl_JOIN_INNER_TD_3672673_output.setInt32(r, 1, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_3672673_output.setInt32(r, 2, _ss_quantity1216);
                tbl_JOIN_INNER_TD_3672673_output.setInt64(r, 3, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_3672673_output.setInt64(r, 4, _ss_ext_wholesale_cost1222);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3672673_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_3672673_output #Row: " << tbl_JOIN_INNER_TD_3672673_output.getNumRow() << std::endl;
}

void SW_Filter_TD_2319273(Table &tbl_SerializeFromObject_TD_3706291_input, Table &tbl_Filter_TD_2319273_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(hd_demo_sk#204) AND (((hd_dep_count#207 = 3) OR (hd_dep_count#207 = 1)) OR (hd_dep_count#207 = 1))))
    // Input: ListBuffer(hd_demo_sk#204, hd_dep_count#207)
    // Output: ListBuffer(hd_demo_sk#204, hd_dep_count#207)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_3706291_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _hd_demo_sk204 = tbl_SerializeFromObject_TD_3706291_input.getInt32(i, 0);
        int32_t _hd_dep_count207 = tbl_SerializeFromObject_TD_3706291_input.getInt32(i, 1);
        if ((_hd_demo_sk204!= 0) && (((_hd_dep_count207 == 3) || (_hd_dep_count207 == 1)) || (_hd_dep_count207 == 1))) {
            int32_t _hd_demo_sk204_t = tbl_SerializeFromObject_TD_3706291_input.getInt32(i, 0);
            tbl_Filter_TD_2319273_output.setInt32(r, 0, _hd_demo_sk204_t);
            int32_t _hd_dep_count207_t = tbl_SerializeFromObject_TD_3706291_input.getInt32(i, 1);
            tbl_Filter_TD_2319273_output.setInt32(r, 1, _hd_dep_count207_t);
            r++;
        }
    }
    tbl_Filter_TD_2319273_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2319273_output #Row: " << tbl_Filter_TD_2319273_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_2211379_key_leftMajor {
    int32_t _ss_cdemo_sk1210;
    bool operator==(const SW_JOIN_INNER_TD_2211379_key_leftMajor& other) const {
        return ((_ss_cdemo_sk1210 == other._ss_cdemo_sk1210));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_2211379_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_2211379_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_cdemo_sk1210));
    }
};
}
struct SW_JOIN_INNER_TD_2211379_payload_leftMajor {
    int32_t _ss_cdemo_sk1210;
    int32_t _ss_hdemo_sk1211;
    int32_t _ss_quantity1216;
    int64_t _ss_ext_sales_price1221;
    int64_t _ss_ext_wholesale_cost1222;
};
struct SW_JOIN_INNER_TD_2211379_key_rightMajor {
    int32_t _cd_demo_sk93;
    bool operator==(const SW_JOIN_INNER_TD_2211379_key_rightMajor& other) const {
        return ((_cd_demo_sk93 == other._cd_demo_sk93));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_2211379_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_2211379_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cd_demo_sk93));
    }
};
}
struct SW_JOIN_INNER_TD_2211379_payload_rightMajor {
    int32_t _cd_demo_sk93;
    std::string _cd_marital_status95;
    std::string _cd_education_status96;
};
void SW_JOIN_INNER_TD_2211379(Table &tbl_JOIN_INNER_TD_3672673_output, Table &tbl_Filter_TD_3998484_output, Table &tbl_JOIN_INNER_TD_2211379_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cd_demo_sk#93 = ss_cdemo_sk#1210))
    // Left Table: ListBuffer(ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_quantity#1216, ss_ext_sales_price#1221, ss_ext_wholesale_cost#1222)
    // Right Table: ListBuffer(cd_demo_sk#93, cd_marital_status#95, cd_education_status#96)
    // Output Table: ListBuffer(ss_hdemo_sk#1211, ss_quantity#1216, ss_ext_sales_price#1221, ss_ext_wholesale_cost#1222, cd_marital_status#95, cd_education_status#96)
    int left_nrow = tbl_JOIN_INNER_TD_3672673_output.getNumRow();
    int right_nrow = tbl_Filter_TD_3998484_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_2211379_key_leftMajor, SW_JOIN_INNER_TD_2211379_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_3672673_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_cdemo_sk1210_k = tbl_JOIN_INNER_TD_3672673_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_2211379_key_leftMajor keyA{_ss_cdemo_sk1210_k};
            int32_t _ss_cdemo_sk1210 = tbl_JOIN_INNER_TD_3672673_output.getInt32(i, 0);
            int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_3672673_output.getInt32(i, 1);
            int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_3672673_output.getInt32(i, 2);
            int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_3672673_output.getInt64(i, 3);
            int64_t _ss_ext_wholesale_cost1222 = tbl_JOIN_INNER_TD_3672673_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_2211379_payload_leftMajor payloadA{_ss_cdemo_sk1210, _ss_hdemo_sk1211, _ss_quantity1216, _ss_ext_sales_price1221, _ss_ext_wholesale_cost1222};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_3998484_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cd_demo_sk93_k = tbl_Filter_TD_3998484_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_2211379_key_leftMajor{_cd_demo_sk93_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_cdemo_sk1210 = (it->second)._ss_cdemo_sk1210;
                int32_t _ss_hdemo_sk1211 = (it->second)._ss_hdemo_sk1211;
                int32_t _ss_quantity1216 = (it->second)._ss_quantity1216;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int64_t _ss_ext_wholesale_cost1222 = (it->second)._ss_ext_wholesale_cost1222;
                int32_t _cd_demo_sk93 = tbl_Filter_TD_3998484_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n = tbl_Filter_TD_3998484_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _cd_marital_status95 = std::string(_cd_marital_status95_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_n = tbl_Filter_TD_3998484_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _cd_education_status96 = std::string(_cd_education_status96_n.data());
                tbl_JOIN_INNER_TD_2211379_output.setInt32(r, 0, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_2211379_output.setInt32(r, 1, _ss_quantity1216);
                tbl_JOIN_INNER_TD_2211379_output.setInt64(r, 2, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_2211379_output.setInt64(r, 3, _ss_ext_wholesale_cost1222);
                tbl_JOIN_INNER_TD_2211379_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _cd_marital_status95_n);
                tbl_JOIN_INNER_TD_2211379_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _cd_education_status96_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_2211379_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_2211379_key_rightMajor, SW_JOIN_INNER_TD_2211379_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_3998484_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cd_demo_sk93_k = tbl_Filter_TD_3998484_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_2211379_key_rightMajor keyA{_cd_demo_sk93_k};
            int32_t _cd_demo_sk93 = tbl_Filter_TD_3998484_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n = tbl_Filter_TD_3998484_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cd_marital_status95 = std::string(_cd_marital_status95_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_n = tbl_Filter_TD_3998484_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _cd_education_status96 = std::string(_cd_education_status96_n.data());
            SW_JOIN_INNER_TD_2211379_payload_rightMajor payloadA{_cd_demo_sk93, _cd_marital_status95, _cd_education_status96};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_3672673_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_cdemo_sk1210_k = tbl_JOIN_INNER_TD_3672673_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_2211379_key_rightMajor{_ss_cdemo_sk1210_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cd_demo_sk93 = (it->second)._cd_demo_sk93;
                std::string _cd_marital_status95 = (it->second)._cd_marital_status95;
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n{};
                memcpy(_cd_marital_status95_n.data(), (_cd_marital_status95).data(), (_cd_marital_status95).length());
                std::string _cd_education_status96 = (it->second)._cd_education_status96;
                std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_n{};
                memcpy(_cd_education_status96_n.data(), (_cd_education_status96).data(), (_cd_education_status96).length());
                int32_t _ss_cdemo_sk1210 = tbl_JOIN_INNER_TD_3672673_output.getInt32(i, 0);
                int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_3672673_output.getInt32(i, 1);
                int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_3672673_output.getInt32(i, 2);
                int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_3672673_output.getInt64(i, 3);
                int64_t _ss_ext_wholesale_cost1222 = tbl_JOIN_INNER_TD_3672673_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_2211379_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _cd_marital_status95_n);
                tbl_JOIN_INNER_TD_2211379_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _cd_education_status96_n);
                tbl_JOIN_INNER_TD_2211379_output.setInt32(r, 0, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_2211379_output.setInt32(r, 1, _ss_quantity1216);
                tbl_JOIN_INNER_TD_2211379_output.setInt64(r, 2, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_2211379_output.setInt64(r, 3, _ss_ext_wholesale_cost1222);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_2211379_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_2211379_output #Row: " << tbl_JOIN_INNER_TD_2211379_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_1560680_key_leftMajor {
    int32_t _ss_hdemo_sk1211;
    bool operator==(const SW_JOIN_INNER_TD_1560680_key_leftMajor& other) const {
        return ((_ss_hdemo_sk1211 == other._ss_hdemo_sk1211));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_1560680_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_1560680_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_hdemo_sk1211));
    }
};
}
struct SW_JOIN_INNER_TD_1560680_payload_leftMajor {
    int32_t _ss_hdemo_sk1211;
    int32_t _ss_quantity1216;
    int64_t _ss_ext_sales_price1221;
    int64_t _ss_ext_wholesale_cost1222;
    std::string _cd_marital_status95;
    std::string _cd_education_status96;
};
struct SW_JOIN_INNER_TD_1560680_key_rightMajor {
    int32_t _hd_demo_sk204;
    bool operator==(const SW_JOIN_INNER_TD_1560680_key_rightMajor& other) const {
        return ((_hd_demo_sk204 == other._hd_demo_sk204));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_1560680_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_1560680_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._hd_demo_sk204));
    }
};
}
struct SW_JOIN_INNER_TD_1560680_payload_rightMajor {
    int32_t _hd_demo_sk204;
    int32_t _hd_dep_count207;
};
void SW_JOIN_INNER_TD_1560680(Table &tbl_JOIN_INNER_TD_2211379_output, Table &tbl_Filter_TD_2319273_output, Table &tbl_JOIN_INNER_TD_1560680_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((ss_hdemo_sk#1211 = hd_demo_sk#204) AND (((((cd_marital_status#95 = M) AND (cd_education_status#96 = Advanced Degree)) AND (hd_dep_count#207 = 3)) OR (((cd_marital_status#95 = S) AND (cd_education_status#96 = College)) AND (hd_dep_count#207 = 1))) OR (((cd_marital_status#95 = W) AND (cd_education_status#96 = 2 yr Degree)) AND (hd_dep_count#207 = 1)))))
    // Left Table: ListBuffer(ss_hdemo_sk#1211, ss_quantity#1216, ss_ext_sales_price#1221, ss_ext_wholesale_cost#1222, cd_marital_status#95, cd_education_status#96)
    // Right Table: ListBuffer(hd_demo_sk#204, hd_dep_count#207)
    // Output Table: ListBuffer(ss_quantity#1216, ss_ext_sales_price#1221, ss_ext_wholesale_cost#1222)
    int left_nrow = tbl_JOIN_INNER_TD_2211379_output.getNumRow();
    int right_nrow = tbl_Filter_TD_2319273_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_1560680_key_leftMajor, SW_JOIN_INNER_TD_1560680_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_2211379_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_hdemo_sk1211_k = tbl_JOIN_INNER_TD_2211379_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_1560680_key_leftMajor keyA{_ss_hdemo_sk1211_k};
            int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_2211379_output.getInt32(i, 0);
            int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_2211379_output.getInt32(i, 1);
            int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_2211379_output.getInt64(i, 2);
            int64_t _ss_ext_wholesale_cost1222 = tbl_JOIN_INNER_TD_2211379_output.getInt64(i, 3);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n = tbl_JOIN_INNER_TD_2211379_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _cd_marital_status95 = std::string(_cd_marital_status95_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_n = tbl_JOIN_INNER_TD_2211379_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _cd_education_status96 = std::string(_cd_education_status96_n.data());
            SW_JOIN_INNER_TD_1560680_payload_leftMajor payloadA{_ss_hdemo_sk1211, _ss_quantity1216, _ss_ext_sales_price1221, _ss_ext_wholesale_cost1222, _cd_marital_status95, _cd_education_status96};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_2319273_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _hd_demo_sk204_k = tbl_Filter_TD_2319273_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_1560680_key_leftMajor{_hd_demo_sk204_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_hdemo_sk1211 = (it->second)._ss_hdemo_sk1211;
                int32_t _ss_quantity1216 = (it->second)._ss_quantity1216;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int64_t _ss_ext_wholesale_cost1222 = (it->second)._ss_ext_wholesale_cost1222;
                std::string _cd_marital_status95 = (it->second)._cd_marital_status95;
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n{};
                memcpy(_cd_marital_status95_n.data(), (_cd_marital_status95).data(), (_cd_marital_status95).length());
                std::string _cd_education_status96 = (it->second)._cd_education_status96;
                std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_n{};
                memcpy(_cd_education_status96_n.data(), (_cd_education_status96).data(), (_cd_education_status96).length());
                int32_t _hd_demo_sk204 = tbl_Filter_TD_2319273_output.getInt32(i, 0);
                int32_t _hd_dep_count207 = tbl_Filter_TD_2319273_output.getInt32(i, 1);
                if (((((_cd_marital_status95 == "M") && (_cd_education_status96 == "Advanced Degree")) && (_hd_dep_count207 == 3)) || (((_cd_marital_status95 == "S") && (_cd_education_status96 == "College")) && (_hd_dep_count207 == 1))) || (((_cd_marital_status95 == "W") && (_cd_education_status96 == "2 yr Degree")) && (_hd_dep_count207 == 1))) {
                    tbl_JOIN_INNER_TD_1560680_output.setInt32(r, 0, _ss_quantity1216);
                    tbl_JOIN_INNER_TD_1560680_output.setInt64(r, 1, _ss_ext_sales_price1221);
                    tbl_JOIN_INNER_TD_1560680_output.setInt64(r, 2, _ss_ext_wholesale_cost1222);
                    r++;
                }
                it++;
            }
        }
        tbl_JOIN_INNER_TD_1560680_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_1560680_key_rightMajor, SW_JOIN_INNER_TD_1560680_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_2319273_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _hd_demo_sk204_k = tbl_Filter_TD_2319273_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_1560680_key_rightMajor keyA{_hd_demo_sk204_k};
            int32_t _hd_demo_sk204 = tbl_Filter_TD_2319273_output.getInt32(i, 0);
            int32_t _hd_dep_count207 = tbl_Filter_TD_2319273_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_1560680_payload_rightMajor payloadA{_hd_demo_sk204, _hd_dep_count207};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_2211379_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_hdemo_sk1211_k = tbl_JOIN_INNER_TD_2211379_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_1560680_key_rightMajor{_ss_hdemo_sk1211_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _hd_demo_sk204 = (it->second)._hd_demo_sk204;
                int32_t _hd_dep_count207 = (it->second)._hd_dep_count207;
                int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_2211379_output.getInt32(i, 0);
                int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_2211379_output.getInt32(i, 1);
                int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_2211379_output.getInt64(i, 2);
                int64_t _ss_ext_wholesale_cost1222 = tbl_JOIN_INNER_TD_2211379_output.getInt64(i, 3);
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n = tbl_JOIN_INNER_TD_2211379_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _cd_marital_status95 = std::string(_cd_marital_status95_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_n = tbl_JOIN_INNER_TD_2211379_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _cd_education_status96 = std::string(_cd_education_status96_n.data());
                if (((((_cd_marital_status95 == "M") && (_cd_education_status96 == "Advanced Degree")) && (_hd_dep_count207 == 3)) || (((_cd_marital_status95 == "S") && (_cd_education_status96 == "College")) && (_hd_dep_count207 == 1))) || (((_cd_marital_status95 == "W") && (_cd_education_status96 == "2 yr Degree")) && (_hd_dep_count207 == 1))) {
                    tbl_JOIN_INNER_TD_1560680_output.setInt32(r, 0, _ss_quantity1216);
                    tbl_JOIN_INNER_TD_1560680_output.setInt64(r, 1, _ss_ext_sales_price1221);
                    tbl_JOIN_INNER_TD_1560680_output.setInt64(r, 2, _ss_ext_wholesale_cost1222);
                    r++;
                }
                it++;
            }
        }
        tbl_JOIN_INNER_TD_1560680_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_1560680_output #Row: " << tbl_JOIN_INNER_TD_1560680_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_0266099(Table &tbl_JOIN_INNER_TD_1560680_output, Table &tbl_Aggregate_TD_0266099_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(avg(ss_quantity#1216) AS avg(ss_quantity)#3941, cast((avg(UnscaledValue(ss_ext_sales_price#1221)) / 100.0) as decimal(11,6)) AS avg(ss_ext_sales_price)#3942, cast((avg(UnscaledValue(ss_ext_wholesale_cost#1222)) / 100.0) as decimal(11,6)) AS avg(ss_ext_wholesale_cost)#3943, MakeDecimal(sum(UnscaledValue(ss_ext_wholesale_cost#1222)),17,2) AS sum(ss_ext_wholesale_cost)#3944)
    // Input: ListBuffer(ss_quantity#1216, ss_ext_sales_price#1221, ss_ext_wholesale_cost#1222)
    // Output: ListBuffer(avg(ss_quantity)#3941, avg(ss_ext_sales_price)#3942, avg(ss_ext_wholesale_cost)#3943, sum(ss_ext_wholesale_cost)#3944)
    int64_t avg_0 = 0;
    int64_t avg_1 = 0;
    int64_t avg_2 = 0;
    int64_t sum_3 = 0;
    int nrow1 = tbl_JOIN_INNER_TD_1560680_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_1560680_output.getInt32(i, 0);
        int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_1560680_output.getInt64(i, 1);
        int64_t _ss_ext_wholesale_cost1222 = tbl_JOIN_INNER_TD_1560680_output.getInt64(i, 2);
        int64_t _avgss_quantity3941_avg_0 = _ss_quantity1216;
        int64_t _avgss_ext_sales_price3942_avg_1 = _ss_ext_sales_price1221;
        int64_t _avgss_ext_wholesale_cost3943_avg_2 = _ss_ext_wholesale_cost1222;
        int64_t _sumss_ext_wholesale_cost3944_sum_3 = _ss_ext_wholesale_cost1222;
        avg_0 = (avg_0 + _avgss_quantity3941_avg_0);
        avg_1 = (avg_1 + _avgss_ext_sales_price3942_avg_1);
        avg_2 = (avg_2 + _avgss_ext_wholesale_cost3943_avg_2);
        sum_3 += _sumss_ext_wholesale_cost3944_sum_3;
    }
    int r = 0;
    int64_t _avgss_quantity3941 = avg_0 / nrow1;
    tbl_Aggregate_TD_0266099_output.setInt64(r++, 0, _avgss_quantity3941);
    int64_t _avgss_ext_sales_price3942 = (avg_1 / nrow1 / 100.0);
    tbl_Aggregate_TD_0266099_output.setInt64(r++, 1, _avgss_ext_sales_price3942);
    int64_t _avgss_ext_wholesale_cost3943 = (avg_2 / nrow1 / 100.0);
    tbl_Aggregate_TD_0266099_output.setInt64(r++, 2, _avgss_ext_wholesale_cost3943);
    int64_t _sumss_ext_wholesale_cost3944 = sum_3;
    tbl_Aggregate_TD_0266099_output.setInt64(r++, 3, _sumss_ext_wholesale_cost3944);
    tbl_Aggregate_TD_0266099_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_0266099_output #Row: " << tbl_Aggregate_TD_0266099_output.getNumRow() << std::endl;
}

