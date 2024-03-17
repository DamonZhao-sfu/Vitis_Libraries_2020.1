#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_5163331(Table &tbl_SerializeFromObject_TD_6261022_input, Table &tbl_Filter_TD_5163331_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(s_store_sk#378))
    // Input: ListBuffer(s_store_sk#378)
    // Output: ListBuffer(s_store_sk#378)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6261022_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _s_store_sk378 = tbl_SerializeFromObject_TD_6261022_input.getInt32(i, 0);
        if (_s_store_sk378!= 0) {
            int32_t _s_store_sk378_t = tbl_SerializeFromObject_TD_6261022_input.getInt32(i, 0);
            tbl_Filter_TD_5163331_output.setInt32(r, 0, _s_store_sk378_t);
            r++;
        }
    }
    tbl_Filter_TD_5163331_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5163331_output #Row: " << tbl_Filter_TD_5163331_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5289871(Table &tbl_SerializeFromObject_TD_6722378_input, Table &tbl_Filter_TD_5289871_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(ss_store_sk#1213) AND isnotnull(ss_cdemo_sk#1210)) AND (isnotnull(ss_addr_sk#1212) AND isnotnull(ss_sold_date_sk#1206))) AND ((((ss_net_profit#1228 >= 0.00) AND (ss_net_profit#1228 <= 2000.00)) OR ((ss_net_profit#1228 >= 150.00) AND (ss_net_profit#1228 <= 3000.00))) OR ((ss_net_profit#1228 >= 50.00) AND (ss_net_profit#1228 <= 25000.00)))))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_cdemo_sk#1210, ss_addr_sk#1212, ss_store_sk#1213, ss_quantity#1216, ss_net_profit#1228)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_cdemo_sk#1210, ss_addr_sk#1212, ss_store_sk#1213, ss_quantity#1216, ss_net_profit#1228)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6722378_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_store_sk1213 = tbl_SerializeFromObject_TD_6722378_input.getInt32(i, 3);
        int32_t _ss_cdemo_sk1210 = tbl_SerializeFromObject_TD_6722378_input.getInt32(i, 1);
        int32_t _ss_addr_sk1212 = tbl_SerializeFromObject_TD_6722378_input.getInt32(i, 2);
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_6722378_input.getInt32(i, 0);
        int64_t _ss_net_profit1228 = tbl_SerializeFromObject_TD_6722378_input.getInt64(i, 5);
        if ((((_ss_store_sk1213!= 0) && (_ss_cdemo_sk1210!= 0)) && ((_ss_addr_sk1212!= 0) && (_ss_sold_date_sk1206!= 0))) && ((((_ss_net_profit1228 >= 0.00) && (_ss_net_profit1228 <= 2000.00)) || ((_ss_net_profit1228 >= 150.00) && (_ss_net_profit1228 <= 3000.00))) || ((_ss_net_profit1228 >= 50.00) && (_ss_net_profit1228 <= 25000.00)))) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_6722378_input.getInt32(i, 0);
            tbl_Filter_TD_5289871_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_cdemo_sk1210_t = tbl_SerializeFromObject_TD_6722378_input.getInt32(i, 1);
            tbl_Filter_TD_5289871_output.setInt32(r, 1, _ss_cdemo_sk1210_t);
            int32_t _ss_addr_sk1212_t = tbl_SerializeFromObject_TD_6722378_input.getInt32(i, 2);
            tbl_Filter_TD_5289871_output.setInt32(r, 2, _ss_addr_sk1212_t);
            int32_t _ss_store_sk1213_t = tbl_SerializeFromObject_TD_6722378_input.getInt32(i, 3);
            tbl_Filter_TD_5289871_output.setInt32(r, 3, _ss_store_sk1213_t);
            int32_t _ss_quantity1216_t = tbl_SerializeFromObject_TD_6722378_input.getInt32(i, 4);
            tbl_Filter_TD_5289871_output.setInt32(r, 4, _ss_quantity1216_t);
            int64_t _ss_net_profit1228_t = tbl_SerializeFromObject_TD_6722378_input.getInt64(i, 5);
            tbl_Filter_TD_5289871_output.setInt64(r, 5, _ss_net_profit1228_t);
            r++;
        }
    }
    tbl_Filter_TD_5289871_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5289871_output #Row: " << tbl_Filter_TD_5289871_output.getNumRow() << std::endl;
}

void SW_Filter_TD_456302(Table &tbl_SerializeFromObject_TD_5456146_input, Table &tbl_Filter_TD_456302_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((((cd_marital_status#95 = M) AND (cd_education_status#96 = 4 yr Degree)) OR ((cd_marital_status#95 = D) AND (cd_education_status#96 = 2 yr Degree))) OR ((cd_marital_status#95 = S) AND (cd_education_status#96 = College))) AND isnotnull(cd_demo_sk#93)))
    // Input: ListBuffer(cd_demo_sk#93, cd_marital_status#95, cd_education_status#96)
    // Output: ListBuffer(cd_demo_sk#93)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5456146_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95 = tbl_SerializeFromObject_TD_5456146_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96 = tbl_SerializeFromObject_TD_5456146_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        int32_t _cd_demo_sk93 = tbl_SerializeFromObject_TD_5456146_input.getInt32(i, 0);
        if (((((std::string(_cd_marital_status95.data()) == "M") && (std::string(_cd_education_status96.data()) == "4 yr Degree")) || ((std::string(_cd_marital_status95.data()) == "D") && (std::string(_cd_education_status96.data()) == "2 yr Degree"))) || ((std::string(_cd_marital_status95.data()) == "S") && (std::string(_cd_education_status96.data()) == "College"))) && (_cd_demo_sk93!= 0)) {
            int32_t _cd_demo_sk93_t = tbl_SerializeFromObject_TD_5456146_input.getInt32(i, 0);
            tbl_Filter_TD_456302_output.setInt32(r, 0, _cd_demo_sk93_t);
            r++;
        }
    }
    tbl_Filter_TD_456302_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_456302_output #Row: " << tbl_Filter_TD_456302_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4339933_key_leftMajor {
    int32_t _ss_store_sk1213;
    bool operator==(const SW_JOIN_INNER_TD_4339933_key_leftMajor& other) const {
        return ((_ss_store_sk1213 == other._ss_store_sk1213));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4339933_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4339933_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_store_sk1213));
    }
};
}
struct SW_JOIN_INNER_TD_4339933_payload_leftMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_cdemo_sk1210;
    int32_t _ss_addr_sk1212;
    int32_t _ss_store_sk1213;
    int32_t _ss_quantity1216;
    int64_t _ss_net_profit1228;
};
struct SW_JOIN_INNER_TD_4339933_key_rightMajor {
    int32_t _s_store_sk378;
    bool operator==(const SW_JOIN_INNER_TD_4339933_key_rightMajor& other) const {
        return ((_s_store_sk378 == other._s_store_sk378));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4339933_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4339933_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_store_sk378));
    }
};
}
struct SW_JOIN_INNER_TD_4339933_payload_rightMajor {
    int32_t _s_store_sk378;
};
void SW_JOIN_INNER_TD_4339933(Table &tbl_Filter_TD_5289871_output, Table &tbl_Filter_TD_5163331_output, Table &tbl_JOIN_INNER_TD_4339933_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((s_store_sk#378 = ss_store_sk#1213))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_cdemo_sk#1210, ss_addr_sk#1212, ss_store_sk#1213, ss_quantity#1216, ss_net_profit#1228)
    // Right Table: ListBuffer(s_store_sk#378)
    // Output Table: ListBuffer(ss_sold_date_sk#1206, ss_cdemo_sk#1210, ss_addr_sk#1212, ss_quantity#1216, ss_net_profit#1228)
    int left_nrow = tbl_Filter_TD_5289871_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5163331_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4339933_key_leftMajor, SW_JOIN_INNER_TD_4339933_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_5289871_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_store_sk1213_k = tbl_Filter_TD_5289871_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_4339933_key_leftMajor keyA{_ss_store_sk1213_k};
            int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_5289871_output.getInt32(i, 0);
            int32_t _ss_cdemo_sk1210 = tbl_Filter_TD_5289871_output.getInt32(i, 1);
            int32_t _ss_addr_sk1212 = tbl_Filter_TD_5289871_output.getInt32(i, 2);
            int32_t _ss_store_sk1213 = tbl_Filter_TD_5289871_output.getInt32(i, 3);
            int32_t _ss_quantity1216 = tbl_Filter_TD_5289871_output.getInt32(i, 4);
            int64_t _ss_net_profit1228 = tbl_Filter_TD_5289871_output.getInt64(i, 5);
            SW_JOIN_INNER_TD_4339933_payload_leftMajor payloadA{_ss_sold_date_sk1206, _ss_cdemo_sk1210, _ss_addr_sk1212, _ss_store_sk1213, _ss_quantity1216, _ss_net_profit1228};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5163331_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_5163331_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4339933_key_leftMajor{_s_store_sk378_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_cdemo_sk1210 = (it->second)._ss_cdemo_sk1210;
                int32_t _ss_addr_sk1212 = (it->second)._ss_addr_sk1212;
                int32_t _ss_store_sk1213 = (it->second)._ss_store_sk1213;
                int32_t _ss_quantity1216 = (it->second)._ss_quantity1216;
                int64_t _ss_net_profit1228 = (it->second)._ss_net_profit1228;
                int32_t _s_store_sk378 = tbl_Filter_TD_5163331_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_4339933_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_4339933_output.setInt32(r, 1, _ss_cdemo_sk1210);
                tbl_JOIN_INNER_TD_4339933_output.setInt32(r, 2, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_4339933_output.setInt32(r, 3, _ss_quantity1216);
                tbl_JOIN_INNER_TD_4339933_output.setInt64(r, 4, _ss_net_profit1228);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4339933_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4339933_key_rightMajor, SW_JOIN_INNER_TD_4339933_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5163331_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_5163331_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4339933_key_rightMajor keyA{_s_store_sk378_k};
            int32_t _s_store_sk378 = tbl_Filter_TD_5163331_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4339933_payload_rightMajor payloadA{_s_store_sk378};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5289871_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_store_sk1213_k = tbl_Filter_TD_5289871_output.getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4339933_key_rightMajor{_ss_store_sk1213_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _s_store_sk378 = (it->second)._s_store_sk378;
                int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_5289871_output.getInt32(i, 0);
                int32_t _ss_cdemo_sk1210 = tbl_Filter_TD_5289871_output.getInt32(i, 1);
                int32_t _ss_addr_sk1212 = tbl_Filter_TD_5289871_output.getInt32(i, 2);
                int32_t _ss_store_sk1213 = tbl_Filter_TD_5289871_output.getInt32(i, 3);
                int32_t _ss_quantity1216 = tbl_Filter_TD_5289871_output.getInt32(i, 4);
                int64_t _ss_net_profit1228 = tbl_Filter_TD_5289871_output.getInt64(i, 5);
                tbl_JOIN_INNER_TD_4339933_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_4339933_output.setInt32(r, 1, _ss_cdemo_sk1210);
                tbl_JOIN_INNER_TD_4339933_output.setInt32(r, 2, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_4339933_output.setInt32(r, 3, _ss_quantity1216);
                tbl_JOIN_INNER_TD_4339933_output.setInt64(r, 4, _ss_net_profit1228);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4339933_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4339933_output #Row: " << tbl_JOIN_INNER_TD_4339933_output.getNumRow() << std::endl;
}

void SW_Filter_TD_3502655(Table &tbl_SerializeFromObject_TD_4871625_input, Table &tbl_Filter_TD_3502655_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(ca_country#64) AND (ca_country#64 = United States)) AND isnotnull(ca_address_sk#54)) AND ((ca_state#62 IN (CO,OH,TX) OR ca_state#62 IN (OR,MN,KY)) OR ca_state#62 IN (VA,CA,MS))))
    // Input: ListBuffer(ca_address_sk#54, ca_state#62, ca_country#64)
    // Output: ListBuffer(ca_address_sk#54, ca_state#62)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_4871625_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_country64 = tbl_SerializeFromObject_TD_4871625_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        int32_t _ca_address_sk54 = tbl_SerializeFromObject_TD_4871625_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _ca_state62 = tbl_SerializeFromObject_TD_4871625_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        auto reuse_col_str_929 = std::string(_ca_state62.data());
        auto reuse_col_str_845 = std::string(_ca_state62.data());
        auto reuse_col_str_589 = std::string(_ca_state62.data());
        if ((((_ca_country64.data() != "NULL") && (std::string(_ca_country64.data()) == "United States")) && (_ca_address_sk54!= 0)) && ((((reuse_col_str_929 == "CO") || (reuse_col_str_929 == "OH") || (reuse_col_str_929 == "TX") || (0)) || ((reuse_col_str_845 == "OR") || (reuse_col_str_845 == "MN") || (reuse_col_str_845 == "KY") || (0))) || ((reuse_col_str_589 == "VA") || (reuse_col_str_589 == "CA") || (reuse_col_str_589 == "MS") || (0)))) {
            int32_t _ca_address_sk54_t = tbl_SerializeFromObject_TD_4871625_input.getInt32(i, 0);
            tbl_Filter_TD_3502655_output.setInt32(r, 0, _ca_address_sk54_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_t = tbl_SerializeFromObject_TD_4871625_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_3502655_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_state62_t);
            r++;
        }
    }
    tbl_Filter_TD_3502655_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_3502655_output #Row: " << tbl_Filter_TD_3502655_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_3645887_key_leftMajor {
    int32_t _ss_cdemo_sk1210;
    bool operator==(const SW_JOIN_INNER_TD_3645887_key_leftMajor& other) const {
        return ((_ss_cdemo_sk1210 == other._ss_cdemo_sk1210));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3645887_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3645887_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_cdemo_sk1210));
    }
};
}
struct SW_JOIN_INNER_TD_3645887_payload_leftMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_cdemo_sk1210;
    int32_t _ss_addr_sk1212;
    int32_t _ss_quantity1216;
    int64_t _ss_net_profit1228;
};
struct SW_JOIN_INNER_TD_3645887_key_rightMajor {
    int32_t _cd_demo_sk93;
    bool operator==(const SW_JOIN_INNER_TD_3645887_key_rightMajor& other) const {
        return ((_cd_demo_sk93 == other._cd_demo_sk93));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3645887_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3645887_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cd_demo_sk93));
    }
};
}
struct SW_JOIN_INNER_TD_3645887_payload_rightMajor {
    int32_t _cd_demo_sk93;
};
void SW_JOIN_INNER_TD_3645887(Table &tbl_JOIN_INNER_TD_4339933_output, Table &tbl_Filter_TD_456302_output, Table &tbl_JOIN_INNER_TD_3645887_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cd_demo_sk#93 = ss_cdemo_sk#1210))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_cdemo_sk#1210, ss_addr_sk#1212, ss_quantity#1216, ss_net_profit#1228)
    // Right Table: ListBuffer(cd_demo_sk#93)
    // Output Table: ListBuffer(ss_sold_date_sk#1206, ss_addr_sk#1212, ss_quantity#1216, ss_net_profit#1228)
    int left_nrow = tbl_JOIN_INNER_TD_4339933_output.getNumRow();
    int right_nrow = tbl_Filter_TD_456302_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3645887_key_leftMajor, SW_JOIN_INNER_TD_3645887_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_4339933_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_cdemo_sk1210_k = tbl_JOIN_INNER_TD_4339933_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_3645887_key_leftMajor keyA{_ss_cdemo_sk1210_k};
            int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_4339933_output.getInt32(i, 0);
            int32_t _ss_cdemo_sk1210 = tbl_JOIN_INNER_TD_4339933_output.getInt32(i, 1);
            int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_4339933_output.getInt32(i, 2);
            int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_4339933_output.getInt32(i, 3);
            int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_4339933_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_3645887_payload_leftMajor payloadA{_ss_sold_date_sk1206, _ss_cdemo_sk1210, _ss_addr_sk1212, _ss_quantity1216, _ss_net_profit1228};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_456302_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cd_demo_sk93_k = tbl_Filter_TD_456302_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3645887_key_leftMajor{_cd_demo_sk93_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_cdemo_sk1210 = (it->second)._ss_cdemo_sk1210;
                int32_t _ss_addr_sk1212 = (it->second)._ss_addr_sk1212;
                int32_t _ss_quantity1216 = (it->second)._ss_quantity1216;
                int64_t _ss_net_profit1228 = (it->second)._ss_net_profit1228;
                int32_t _cd_demo_sk93 = tbl_Filter_TD_456302_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_3645887_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_3645887_output.setInt32(r, 1, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_3645887_output.setInt32(r, 2, _ss_quantity1216);
                tbl_JOIN_INNER_TD_3645887_output.setInt64(r, 3, _ss_net_profit1228);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3645887_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3645887_key_rightMajor, SW_JOIN_INNER_TD_3645887_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_456302_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cd_demo_sk93_k = tbl_Filter_TD_456302_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3645887_key_rightMajor keyA{_cd_demo_sk93_k};
            int32_t _cd_demo_sk93 = tbl_Filter_TD_456302_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3645887_payload_rightMajor payloadA{_cd_demo_sk93};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_4339933_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_cdemo_sk1210_k = tbl_JOIN_INNER_TD_4339933_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3645887_key_rightMajor{_ss_cdemo_sk1210_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cd_demo_sk93 = (it->second)._cd_demo_sk93;
                int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_4339933_output.getInt32(i, 0);
                int32_t _ss_cdemo_sk1210 = tbl_JOIN_INNER_TD_4339933_output.getInt32(i, 1);
                int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_4339933_output.getInt32(i, 2);
                int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_4339933_output.getInt32(i, 3);
                int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_4339933_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_3645887_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_3645887_output.setInt32(r, 1, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_3645887_output.setInt32(r, 2, _ss_quantity1216);
                tbl_JOIN_INNER_TD_3645887_output.setInt64(r, 3, _ss_net_profit1228);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3645887_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_3645887_output #Row: " << tbl_JOIN_INNER_TD_3645887_output.getNumRow() << std::endl;
}

void SW_Filter_TD_2957694(Table &tbl_SerializeFromObject_TD_3325149_input, Table &tbl_Filter_TD_2957694_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#126) AND (d_year#126 = 2000)) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_3325149_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_3325149_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_3325149_input.getInt32(i, 0);
        if (((_d_year126!= 0) && (_d_year126 == 2000)) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_3325149_input.getInt32(i, 0);
            tbl_Filter_TD_2957694_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_2957694_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2957694_output #Row: " << tbl_Filter_TD_2957694_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_269188_key_leftMajor {
    int32_t _ss_addr_sk1212;
    bool operator==(const SW_JOIN_INNER_TD_269188_key_leftMajor& other) const {
        return ((_ss_addr_sk1212 == other._ss_addr_sk1212));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_269188_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_269188_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_addr_sk1212));
    }
};
}
struct SW_JOIN_INNER_TD_269188_payload_leftMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_addr_sk1212;
    int32_t _ss_quantity1216;
    int64_t _ss_net_profit1228;
};
struct SW_JOIN_INNER_TD_269188_key_rightMajor {
    int32_t _ca_address_sk54;
    bool operator==(const SW_JOIN_INNER_TD_269188_key_rightMajor& other) const {
        return ((_ca_address_sk54 == other._ca_address_sk54));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_269188_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_269188_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk54));
    }
};
}
struct SW_JOIN_INNER_TD_269188_payload_rightMajor {
    int32_t _ca_address_sk54;
    std::string _ca_state62;
};
void SW_JOIN_INNER_TD_269188(Table &tbl_JOIN_INNER_TD_3645887_output, Table &tbl_Filter_TD_3502655_output, Table &tbl_JOIN_INNER_TD_269188_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((ss_addr_sk#1212 = ca_address_sk#54) AND ((((ca_state#62 IN (CO,OH,TX) AND (ss_net_profit#1228 >= 0.00)) AND (ss_net_profit#1228 <= 2000.00)) OR ((ca_state#62 IN (OR,MN,KY) AND (ss_net_profit#1228 >= 150.00)) AND (ss_net_profit#1228 <= 3000.00))) OR ((ca_state#62 IN (VA,CA,MS) AND (ss_net_profit#1228 >= 50.00)) AND (ss_net_profit#1228 <= 25000.00)))))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_addr_sk#1212, ss_quantity#1216, ss_net_profit#1228)
    // Right Table: ListBuffer(ca_address_sk#54, ca_state#62)
    // Output Table: ListBuffer(ss_sold_date_sk#1206, ss_quantity#1216)
    int left_nrow = tbl_JOIN_INNER_TD_3645887_output.getNumRow();
    int right_nrow = tbl_Filter_TD_3502655_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_269188_key_leftMajor, SW_JOIN_INNER_TD_269188_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_3645887_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_addr_sk1212_k = tbl_JOIN_INNER_TD_3645887_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_269188_key_leftMajor keyA{_ss_addr_sk1212_k};
            int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_3645887_output.getInt32(i, 0);
            int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_3645887_output.getInt32(i, 1);
            int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_3645887_output.getInt32(i, 2);
            int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_3645887_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_269188_payload_leftMajor payloadA{_ss_sold_date_sk1206, _ss_addr_sk1212, _ss_quantity1216, _ss_net_profit1228};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_3502655_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_3502655_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_269188_key_leftMajor{_ca_address_sk54_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_addr_sk1212 = (it->second)._ss_addr_sk1212;
                int32_t _ss_quantity1216 = (it->second)._ss_quantity1216;
                int64_t _ss_net_profit1228 = (it->second)._ss_net_profit1228;
                int32_t _ca_address_sk54 = tbl_Filter_TD_3502655_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_Filter_TD_3502655_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_state62 = std::string(_ca_state62_n.data());
                tbl_JOIN_INNER_TD_269188_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_269188_output.setInt32(r, 1, _ss_quantity1216);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_269188_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_269188_key_rightMajor, SW_JOIN_INNER_TD_269188_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_3502655_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_3502655_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_269188_key_rightMajor keyA{_ca_address_sk54_k};
            int32_t _ca_address_sk54 = tbl_Filter_TD_3502655_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_Filter_TD_3502655_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_state62 = std::string(_ca_state62_n.data());
            SW_JOIN_INNER_TD_269188_payload_rightMajor payloadA{_ca_address_sk54, _ca_state62};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_3645887_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_addr_sk1212_k = tbl_JOIN_INNER_TD_3645887_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_269188_key_rightMajor{_ss_addr_sk1212_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk54 = (it->second)._ca_address_sk54;
                std::string _ca_state62 = (it->second)._ca_state62;
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n{};
                memcpy(_ca_state62_n.data(), (_ca_state62).data(), (_ca_state62).length());
                int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_3645887_output.getInt32(i, 0);
                int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_3645887_output.getInt32(i, 1);
                int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_3645887_output.getInt32(i, 2);
                int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_3645887_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_269188_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_269188_output.setInt32(r, 1, _ss_quantity1216);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_269188_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_269188_output #Row: " << tbl_JOIN_INNER_TD_269188_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_1833252_key_leftMajor {
    int32_t _ss_sold_date_sk1206;
    bool operator==(const SW_JOIN_INNER_TD_1833252_key_leftMajor& other) const {
        return ((_ss_sold_date_sk1206 == other._ss_sold_date_sk1206));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_1833252_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_1833252_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_sold_date_sk1206));
    }
};
}
struct SW_JOIN_INNER_TD_1833252_payload_leftMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_quantity1216;
};
struct SW_JOIN_INNER_TD_1833252_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_1833252_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_1833252_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_1833252_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_1833252_payload_rightMajor {
    int32_t _d_date_sk120;
};
void SW_JOIN_INNER_TD_1833252(Table &tbl_JOIN_INNER_TD_269188_output, Table &tbl_Filter_TD_2957694_output, Table &tbl_JOIN_INNER_TD_1833252_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#1206 = d_date_sk#120))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_quantity#1216)
    // Right Table: ListBuffer(d_date_sk#120)
    // Output Table: ListBuffer(ss_quantity#1216)
    int left_nrow = tbl_JOIN_INNER_TD_269188_output.getNumRow();
    int right_nrow = tbl_Filter_TD_2957694_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_1833252_key_leftMajor, SW_JOIN_INNER_TD_1833252_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_269188_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_JOIN_INNER_TD_269188_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_1833252_key_leftMajor keyA{_ss_sold_date_sk1206_k};
            int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_269188_output.getInt32(i, 0);
            int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_269188_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_1833252_payload_leftMajor payloadA{_ss_sold_date_sk1206, _ss_quantity1216};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_2957694_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_2957694_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_1833252_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_quantity1216 = (it->second)._ss_quantity1216;
                int32_t _d_date_sk120 = tbl_Filter_TD_2957694_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_1833252_output.setInt32(r, 0, _ss_quantity1216);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_1833252_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_1833252_key_rightMajor, SW_JOIN_INNER_TD_1833252_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_2957694_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_2957694_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_1833252_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_2957694_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_1833252_payload_rightMajor payloadA{_d_date_sk120};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_269188_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_JOIN_INNER_TD_269188_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_1833252_key_rightMajor{_ss_sold_date_sk1206_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_269188_output.getInt32(i, 0);
                int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_269188_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_1833252_output.setInt32(r, 0, _ss_quantity1216);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_1833252_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_1833252_output #Row: " << tbl_JOIN_INNER_TD_1833252_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_0670688(Table &tbl_JOIN_INNER_TD_1833252_output, Table &tbl_Aggregate_TD_0670688_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(sum(ss_quantity#1216) AS sum(ss_quantity)#3608L)
    // Input: ListBuffer(ss_quantity#1216)
    // Output: ListBuffer(sum(ss_quantity)#3608L)
    int64_t sum_0 = 0;
    int nrow1 = tbl_JOIN_INNER_TD_1833252_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_1833252_output.getInt32(i, 0);
        int64_t _sumss_quantity3608L_sum_0 = _ss_quantity1216;
        sum_0 += _sumss_quantity3608L_sum_0;
    }
    int r = 0;
    int64_t _sumss_quantity3608L = sum_0;
    tbl_Aggregate_TD_0670688_output.setInt64(r++, 0, _sumss_quantity3608L);
    tbl_Aggregate_TD_0670688_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_0670688_output #Row: " << tbl_Aggregate_TD_0670688_output.getNumRow() << std::endl;
}

