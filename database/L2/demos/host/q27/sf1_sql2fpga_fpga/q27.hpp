#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_9913329(Table &tbl_SerializeFromObject_TD_10579768_input, Table &tbl_Filter_TD_9913329_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((((isnotnull(cd_gender#94) AND isnotnull(cd_marital_status#95)) AND isnotnull(cd_education_status#96)) AND (((cd_gender#94 = M) AND (cd_marital_status#95 = S)) AND (cd_education_status#96 = College))) AND isnotnull(cd_demo_sk#93)))
    // Input: ListBuffer(cd_demo_sk#93, cd_gender#94, cd_marital_status#95, cd_education_status#96)
    // Output: ListBuffer(cd_demo_sk#93)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10579768_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _cd_gender94 = tbl_SerializeFromObject_TD_10579768_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95 = tbl_SerializeFromObject_TD_10579768_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96 = tbl_SerializeFromObject_TD_10579768_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        int32_t _cd_demo_sk93 = tbl_SerializeFromObject_TD_10579768_input.getInt32(i, 0);
        if ((((_cd_gender94.data() != "NULL" && _cd_marital_status95.data() != "NULL") && _cd_education_status96.data() != "NULL") && (((std::string(_cd_gender94.data()) == "M") && (std::string(_cd_marital_status95.data()) == "S")) && (std::string(_cd_education_status96.data()) == "College"))) && (_cd_demo_sk93!= 0)) {
            int32_t _cd_demo_sk93_t = tbl_SerializeFromObject_TD_10579768_input.getInt32(i, 0);
            tbl_Filter_TD_9913329_output.setInt32(r, 0, _cd_demo_sk93_t);
            r++;
        }
    }
    tbl_Filter_TD_9913329_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9913329_output #Row: " << tbl_Filter_TD_9913329_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9310488(Table &tbl_SerializeFromObject_TD_10328485_input, Table &tbl_Filter_TD_9310488_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ss_cdemo_sk#1210) AND isnotnull(ss_sold_date_sk#1206)) AND (isnotnull(ss_store_sk#1213) AND isnotnull(ss_item_sk#1208))))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_cdemo_sk#1210, ss_store_sk#1213, ss_quantity#1216, ss_list_price#1218, ss_sales_price#1219, ss_coupon_amt#1225)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_cdemo_sk#1210, ss_store_sk#1213, ss_quantity#1216, ss_list_price#1218, ss_sales_price#1219, ss_coupon_amt#1225)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10328485_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_cdemo_sk1210 = tbl_SerializeFromObject_TD_10328485_input.getInt32(i, 2);
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_10328485_input.getInt32(i, 0);
        int32_t _ss_store_sk1213 = tbl_SerializeFromObject_TD_10328485_input.getInt32(i, 3);
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_10328485_input.getInt32(i, 1);
        if (((_ss_cdemo_sk1210!= 0) && (_ss_sold_date_sk1206!= 0)) && ((_ss_store_sk1213!= 0) && (_ss_item_sk1208!= 0))) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_10328485_input.getInt32(i, 0);
            tbl_Filter_TD_9310488_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_10328485_input.getInt32(i, 1);
            tbl_Filter_TD_9310488_output.setInt32(r, 1, _ss_item_sk1208_t);
            int32_t _ss_cdemo_sk1210_t = tbl_SerializeFromObject_TD_10328485_input.getInt32(i, 2);
            tbl_Filter_TD_9310488_output.setInt32(r, 2, _ss_cdemo_sk1210_t);
            int32_t _ss_store_sk1213_t = tbl_SerializeFromObject_TD_10328485_input.getInt32(i, 3);
            tbl_Filter_TD_9310488_output.setInt32(r, 3, _ss_store_sk1213_t);
            int32_t _ss_quantity1216_t = tbl_SerializeFromObject_TD_10328485_input.getInt32(i, 4);
            tbl_Filter_TD_9310488_output.setInt32(r, 4, _ss_quantity1216_t);
            int64_t _ss_list_price1218_t = tbl_SerializeFromObject_TD_10328485_input.getInt64(i, 5);
            tbl_Filter_TD_9310488_output.setInt64(r, 5, _ss_list_price1218_t);
            int64_t _ss_sales_price1219_t = tbl_SerializeFromObject_TD_10328485_input.getInt64(i, 6);
            tbl_Filter_TD_9310488_output.setInt64(r, 6, _ss_sales_price1219_t);
            int64_t _ss_coupon_amt1225_t = tbl_SerializeFromObject_TD_10328485_input.getInt64(i, 7);
            tbl_Filter_TD_9310488_output.setInt64(r, 7, _ss_coupon_amt1225_t);
            r++;
        }
    }
    tbl_Filter_TD_9310488_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9310488_output #Row: " << tbl_Filter_TD_9310488_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8464956(Table &tbl_SerializeFromObject_TD_9644014_input, Table &tbl_Filter_TD_8464956_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#126) AND (d_year#126 = 2002)) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9644014_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_9644014_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_9644014_input.getInt32(i, 0);
        if (((_d_year126!= 0) && (_d_year126 == 2002)) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_9644014_input.getInt32(i, 0);
            tbl_Filter_TD_8464956_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_8464956_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8464956_output #Row: " << tbl_Filter_TD_8464956_output.getNumRow() << std::endl;
}


void SW_Filter_TD_7646483(Table &tbl_SerializeFromObject_TD_8699779_input, Table &tbl_Filter_TD_7646483_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(s_state#402) AND (s_state#402 = TN)) AND isnotnull(s_store_sk#378)))
    // Input: ListBuffer(s_store_sk#378, s_state#402)
    // Output: ListBuffer(s_store_sk#378, s_state#402)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8699779_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_state402 = tbl_SerializeFromObject_TD_8699779_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _s_store_sk378 = tbl_SerializeFromObject_TD_8699779_input.getInt32(i, 0);
        if ((_s_state402.data() != "NULL" && (std::string(_s_state402.data()) == "TN")) && (_s_store_sk378!= 0)) {
            int32_t _s_store_sk378_t = tbl_SerializeFromObject_TD_8699779_input.getInt32(i, 0);
            tbl_Filter_TD_7646483_output.setInt32(r, 0, _s_store_sk378_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_state402_t = tbl_SerializeFromObject_TD_8699779_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_7646483_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_state402_t);
            r++;
        }
    }
    tbl_Filter_TD_7646483_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7646483_output #Row: " << tbl_Filter_TD_7646483_output.getNumRow() << std::endl;
}


void SW_Filter_TD_685002(Table &tbl_SerializeFromObject_TD_778862_input, Table &tbl_Filter_TD_685002_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#228))
    // Input: ListBuffer(i_item_sk#228, i_item_id#229)
    // Output: ListBuffer(i_item_sk#228, i_item_id#229)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_778862_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_778862_input.getInt32(i, 0);
        if (_i_item_sk228!= 0) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_778862_input.getInt32(i, 0);
            tbl_Filter_TD_685002_output.setInt32(r, 0, _i_item_sk228_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_t = tbl_SerializeFromObject_TD_778862_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_685002_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id229_t);
            r++;
        }
    }
    tbl_Filter_TD_685002_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_685002_output #Row: " << tbl_Filter_TD_685002_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6356181_key_leftMajor {
    int32_t _ss_store_sk1213;
    bool operator==(const SW_JOIN_INNER_TD_6356181_key_leftMajor& other) const {
        return ((_ss_store_sk1213 == other._ss_store_sk1213));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6356181_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6356181_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_store_sk1213));
    }
};
}
struct SW_JOIN_INNER_TD_6356181_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int32_t _ss_store_sk1213;
    int32_t _ss_quantity1216;
    int64_t _ss_list_price1218;
    int64_t _ss_sales_price1219;
    int64_t _ss_coupon_amt1225;
};
struct SW_JOIN_INNER_TD_6356181_key_rightMajor {
    int32_t _s_store_sk378;
    bool operator==(const SW_JOIN_INNER_TD_6356181_key_rightMajor& other) const {
        return ((_s_store_sk378 == other._s_store_sk378));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6356181_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6356181_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_store_sk378));
    }
};
}
struct SW_JOIN_INNER_TD_6356181_payload_rightMajor {
    int32_t _s_store_sk378;
    std::string _s_state402;
};
void SW_JOIN_INNER_TD_6356181(Table &tbl_JOIN_INNER_TD_7348578_output, Table &tbl_Filter_TD_7646483_output, Table &tbl_JOIN_INNER_TD_6356181_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_store_sk#1213 = s_store_sk#378))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_store_sk#1213, ss_quantity#1216, ss_list_price#1218, ss_sales_price#1219, ss_coupon_amt#1225)
    // Right Table: ListBuffer(s_store_sk#378, s_state#402)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_quantity#1216, ss_list_price#1218, ss_sales_price#1219, ss_coupon_amt#1225, s_state#402)
    int left_nrow = tbl_JOIN_INNER_TD_7348578_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7646483_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6356181_key_leftMajor, SW_JOIN_INNER_TD_6356181_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7348578_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_store_sk1213_k = tbl_JOIN_INNER_TD_7348578_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_6356181_key_leftMajor keyA{_ss_store_sk1213_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_7348578_output.getInt32(i, 0);
            int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_7348578_output.getInt32(i, 1);
            int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_7348578_output.getInt32(i, 2);
            int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_7348578_output.getInt64(i, 3);
            int64_t _ss_sales_price1219 = tbl_JOIN_INNER_TD_7348578_output.getInt64(i, 4);
            int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_7348578_output.getInt64(i, 5);
            SW_JOIN_INNER_TD_6356181_payload_leftMajor payloadA{_ss_item_sk1208, _ss_store_sk1213, _ss_quantity1216, _ss_list_price1218, _ss_sales_price1219, _ss_coupon_amt1225};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7646483_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_7646483_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6356181_key_leftMajor{_s_store_sk378_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_store_sk1213 = (it->second)._ss_store_sk1213;
                int32_t _ss_quantity1216 = (it->second)._ss_quantity1216;
                int64_t _ss_list_price1218 = (it->second)._ss_list_price1218;
                int64_t _ss_sales_price1219 = (it->second)._ss_sales_price1219;
                int64_t _ss_coupon_amt1225 = (it->second)._ss_coupon_amt1225;
                int32_t _s_store_sk378 = tbl_Filter_TD_7646483_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _s_state402_n = tbl_Filter_TD_7646483_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _s_state402 = std::string(_s_state402_n.data());
                tbl_JOIN_INNER_TD_6356181_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_6356181_output.setInt32(r, 1, _ss_quantity1216);
                tbl_JOIN_INNER_TD_6356181_output.setInt64(r, 2, _ss_list_price1218);
                tbl_JOIN_INNER_TD_6356181_output.setInt64(r, 3, _ss_sales_price1219);
                tbl_JOIN_INNER_TD_6356181_output.setInt64(r, 4, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_6356181_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_state402_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6356181_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6356181_key_rightMajor, SW_JOIN_INNER_TD_6356181_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7646483_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_7646483_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6356181_key_rightMajor keyA{_s_store_sk378_k};
            int32_t _s_store_sk378 = tbl_Filter_TD_7646483_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _s_state402_n = tbl_Filter_TD_7646483_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _s_state402 = std::string(_s_state402_n.data());
            SW_JOIN_INNER_TD_6356181_payload_rightMajor payloadA{_s_store_sk378, _s_state402};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7348578_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_store_sk1213_k = tbl_JOIN_INNER_TD_7348578_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6356181_key_rightMajor{_ss_store_sk1213_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _s_store_sk378 = (it->second)._s_store_sk378;
                std::string _s_state402 = (it->second)._s_state402;
                std::array<char, TPCDS_READ_MAX + 1> _s_state402_n{};
                memcpy(_s_state402_n.data(), (_s_state402).data(), (_s_state402).length());
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_7348578_output.getInt32(i, 0);
                int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_7348578_output.getInt32(i, 1);
                int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_7348578_output.getInt32(i, 2);
                int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_7348578_output.getInt64(i, 3);
                int64_t _ss_sales_price1219 = tbl_JOIN_INNER_TD_7348578_output.getInt64(i, 4);
                int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_7348578_output.getInt64(i, 5);
                tbl_JOIN_INNER_TD_6356181_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_state402_n);
                tbl_JOIN_INNER_TD_6356181_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_6356181_output.setInt32(r, 1, _ss_quantity1216);
                tbl_JOIN_INNER_TD_6356181_output.setInt64(r, 2, _ss_list_price1218);
                tbl_JOIN_INNER_TD_6356181_output.setInt64(r, 3, _ss_sales_price1219);
                tbl_JOIN_INNER_TD_6356181_output.setInt64(r, 4, _ss_coupon_amt1225);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6356181_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6356181_output #Row: " << tbl_JOIN_INNER_TD_6356181_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5947504_key_leftMajor {
    int32_t _ss_item_sk1208;
    bool operator==(const SW_JOIN_INNER_TD_5947504_key_leftMajor& other) const {
        return ((_ss_item_sk1208 == other._ss_item_sk1208));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5947504_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5947504_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk1208));
    }
};
}
struct SW_JOIN_INNER_TD_5947504_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int32_t _ss_quantity1216;
    int64_t _ss_list_price1218;
    int64_t _ss_sales_price1219;
    int64_t _ss_coupon_amt1225;
    std::string _s_state402;
};
struct SW_JOIN_INNER_TD_5947504_key_rightMajor {
    int32_t _i_item_sk228;
    bool operator==(const SW_JOIN_INNER_TD_5947504_key_rightMajor& other) const {
        return ((_i_item_sk228 == other._i_item_sk228));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5947504_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5947504_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk228));
    }
};
}
struct SW_JOIN_INNER_TD_5947504_payload_rightMajor {
    int32_t _i_item_sk228;
    std::string _i_item_id229;
};
void SW_JOIN_INNER_TD_5947504(Table &tbl_JOIN_INNER_TD_6356181_output, Table &tbl_Filter_TD_685002_output, Table &tbl_JOIN_INNER_TD_5947504_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_item_sk#1208 = i_item_sk#228))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_quantity#1216, ss_list_price#1218, ss_sales_price#1219, ss_coupon_amt#1225, s_state#402)
    // Right Table: ListBuffer(i_item_sk#228, i_item_id#229)
    // Output Table: ListBuffer(ss_quantity#1216, ss_list_price#1218, ss_sales_price#1219, ss_coupon_amt#1225, i_item_id#229, s_state#402)
    int left_nrow = tbl_JOIN_INNER_TD_6356181_output.getNumRow();
    int right_nrow = tbl_Filter_TD_685002_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5947504_key_leftMajor, SW_JOIN_INNER_TD_5947504_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_6356181_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_6356181_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5947504_key_leftMajor keyA{_ss_item_sk1208_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_6356181_output.getInt32(i, 0);
            int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_6356181_output.getInt32(i, 1);
            int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_6356181_output.getInt64(i, 2);
            int64_t _ss_sales_price1219 = tbl_JOIN_INNER_TD_6356181_output.getInt64(i, 3);
            int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_6356181_output.getInt64(i, 4);
            std::array<char, TPCDS_READ_MAX + 1> _s_state402_n = tbl_JOIN_INNER_TD_6356181_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _s_state402 = std::string(_s_state402_n.data());
            SW_JOIN_INNER_TD_5947504_payload_leftMajor payloadA{_ss_item_sk1208, _ss_quantity1216, _ss_list_price1218, _ss_sales_price1219, _ss_coupon_amt1225, _s_state402};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_685002_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_685002_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5947504_key_leftMajor{_i_item_sk228_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_quantity1216 = (it->second)._ss_quantity1216;
                int64_t _ss_list_price1218 = (it->second)._ss_list_price1218;
                int64_t _ss_sales_price1219 = (it->second)._ss_sales_price1219;
                int64_t _ss_coupon_amt1225 = (it->second)._ss_coupon_amt1225;
                std::string _s_state402 = (it->second)._s_state402;
                std::array<char, TPCDS_READ_MAX + 1> _s_state402_n{};
                memcpy(_s_state402_n.data(), (_s_state402).data(), (_s_state402).length());
                int32_t _i_item_sk228 = tbl_Filter_TD_685002_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_Filter_TD_685002_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_item_id229 = std::string(_i_item_id229_n.data());
                tbl_JOIN_INNER_TD_5947504_output.setInt32(r, 0, _ss_quantity1216);
                tbl_JOIN_INNER_TD_5947504_output.setInt64(r, 1, _ss_list_price1218);
                tbl_JOIN_INNER_TD_5947504_output.setInt64(r, 2, _ss_sales_price1219);
                tbl_JOIN_INNER_TD_5947504_output.setInt64(r, 3, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_5947504_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_state402_n);
                tbl_JOIN_INNER_TD_5947504_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _i_item_id229_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5947504_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5947504_key_rightMajor, SW_JOIN_INNER_TD_5947504_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_685002_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_685002_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5947504_key_rightMajor keyA{_i_item_sk228_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_685002_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_Filter_TD_685002_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_item_id229 = std::string(_i_item_id229_n.data());
            SW_JOIN_INNER_TD_5947504_payload_rightMajor payloadA{_i_item_sk228, _i_item_id229};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_6356181_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_6356181_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5947504_key_rightMajor{_ss_item_sk1208_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                std::string _i_item_id229 = (it->second)._i_item_id229;
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n{};
                memcpy(_i_item_id229_n.data(), (_i_item_id229).data(), (_i_item_id229).length());
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_6356181_output.getInt32(i, 0);
                int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_6356181_output.getInt32(i, 1);
                int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_6356181_output.getInt64(i, 2);
                int64_t _ss_sales_price1219 = tbl_JOIN_INNER_TD_6356181_output.getInt64(i, 3);
                int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_6356181_output.getInt64(i, 4);
                std::array<char, TPCDS_READ_MAX + 1> _s_state402_n = tbl_JOIN_INNER_TD_6356181_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _s_state402 = std::string(_s_state402_n.data());
                tbl_JOIN_INNER_TD_5947504_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _i_item_id229_n);
                tbl_JOIN_INNER_TD_5947504_output.setInt32(r, 0, _ss_quantity1216);
                tbl_JOIN_INNER_TD_5947504_output.setInt64(r, 1, _ss_list_price1218);
                tbl_JOIN_INNER_TD_5947504_output.setInt64(r, 2, _ss_sales_price1219);
                tbl_JOIN_INNER_TD_5947504_output.setInt64(r, 3, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_5947504_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_state402_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5947504_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5947504_output #Row: " << tbl_JOIN_INNER_TD_5947504_output.getNumRow() << std::endl;
}

void SW_Expand_TD_4857594(Table &tbl_JOIN_INNER_TD_5947504_output, Table &tbl_Expand_TD_4857594_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Expand
    // Operation: ListBuffer(Expand)
    // Input: ListBuffer(ss_quantity#1216, ss_list_price#1218, ss_sales_price#1219, ss_coupon_amt#1225, i_item_id#229, s_state#402)
    // Output: ListBuffer(ss_quantity#1216, ss_list_price#1218, ss_sales_price#1219, ss_coupon_amt#1225, i_item_id#3556, s_state#3557, spark_grouping_id#3555L)
    std::cout << "tbl_Expand_TD_4857594_output #Row: " << tbl_Expand_TD_4857594_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_3494765_key {
    std::string _i_item_id3556;
    std::string _s_state3557;
    int64_t _spark_grouping_id3555L;
    bool operator==(const SW_Aggregate_TD_3494765_key& other) const { return (_i_item_id3556 == other._i_item_id3556) && (_s_state3557 == other._s_state3557) && (_spark_grouping_id3555L == other._spark_grouping_id3555L); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_3494765_key> {
    std::size_t operator() (const SW_Aggregate_TD_3494765_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_item_id3556)) + (hash<string>()(k._s_state3557)) + (hash<int64_t>()(k._spark_grouping_id3555L));
    }
};
}
struct SW_Aggregate_TD_3494765_payload {
    int32_t _g_state3544;
    int64_t _agg13545_avg_0;
    int64_t _agg23546_avg_1;
    int64_t _agg33547_avg_2;
    int64_t _agg43548_avg_3;
};
void SW_Aggregate_TD_3494765(Table &tbl_Expand_TD_4857594_output, Table &tbl_Aggregate_TD_3494765_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(i_item_id#3556, s_state#3557, spark_grouping_id#3555L, cast((shiftright(spark_grouping_id#3555L, 0) & 1) as tinyint) AS g_state#3544, avg(ss_quantity#1216) AS agg1#3545, cast((avg(UnscaledValue(ss_list_price#1218)) / 100.0) as decimal(11,6)) AS agg2#3546, cast((avg(UnscaledValue(ss_coupon_amt#1225)) / 100.0) as decimal(11,6)) AS agg3#3547, cast((avg(UnscaledValue(ss_sales_price#1219)) / 100.0) as decimal(11,6)) AS agg4#3548)
    // Input: ListBuffer(ss_quantity#1216, ss_list_price#1218, ss_sales_price#1219, ss_coupon_amt#1225, i_item_id#3556, s_state#3557, spark_grouping_id#3555L)
    // Output: ListBuffer(i_item_id#3556, s_state#3557, g_state#3544, agg1#3545, agg2#3546, agg3#3547, agg4#3548)
    std::unordered_map<SW_Aggregate_TD_3494765_key, SW_Aggregate_TD_3494765_payload> ht1;
    int nrow1 = tbl_Expand_TD_4857594_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_quantity1216 = tbl_Expand_TD_4857594_output.getInt32(i, 0);
        int64_t _ss_list_price1218 = tbl_Expand_TD_4857594_output.getInt64(i, 1);
        int64_t _ss_sales_price1219 = tbl_Expand_TD_4857594_output.getInt64(i, 2);
        int64_t _ss_coupon_amt1225 = tbl_Expand_TD_4857594_output.getInt64(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id3556 = tbl_Expand_TD_4857594_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _s_state3557 = tbl_Expand_TD_4857594_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        int64_t _spark_grouping_id3555L = tbl_Expand_TD_4857594_output.getInt64(i, 6);
        SW_Aggregate_TD_3494765_key k{std::string(_i_item_id3556.data()), std::string(_s_state3557.data()), _spark_grouping_id3555L};
        int32_t _g_state3544 = _spark_grouping_id3555L;
        int64_t _agg13545_avg_0 = _ss_quantity1216;
        int64_t _agg23546_avg_1 = _ss_list_price1218;
        int64_t _agg33547_avg_2 = _ss_coupon_amt1225;
        int64_t _agg43548_avg_3 = _ss_sales_price1219;
        SW_Aggregate_TD_3494765_payload p{_g_state3544, _agg13545_avg_0, _agg23546_avg_1, _agg33547_avg_2, _agg43548_avg_3};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t avg_0 = ((it->second)._agg13545_avg_0 + _agg13545_avg_0);
            p._agg13545_avg_0 = avg_0;
            int64_t avg_1 = ((it->second)._agg23546_avg_1 + _agg23546_avg_1);
            p._agg23546_avg_1 = avg_1;
            int64_t avg_2 = ((it->second)._agg33547_avg_2 + _agg33547_avg_2);
            p._agg33547_avg_2 = avg_2;
            int64_t avg_3 = ((it->second)._agg43548_avg_3 + _agg43548_avg_3);
            p._agg43548_avg_3 = avg_3;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id3556{};
        memcpy(_i_item_id3556.data(), ((it.first)._i_item_id3556).data(), ((it.first)._i_item_id3556).length());
        tbl_Aggregate_TD_3494765_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id3556);
        std::array<char, TPCDS_READ_MAX + 1> _s_state3557{};
        memcpy(_s_state3557.data(), ((it.first)._s_state3557).data(), ((it.first)._s_state3557).length());
        tbl_Aggregate_TD_3494765_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_state3557);
        // _spark_grouping_id3555L not required in the output table
        tbl_Aggregate_TD_3494765_output.setInt32(r, 2, (it.second)._g_state3544);
        int64_t _agg13545 = (it.second)._agg13545_avg_0 / nrow1;
        tbl_Aggregate_TD_3494765_output.setInt64(r, 3, _agg13545);
        int64_t _agg23546 = ((it.second)._agg23546_avg_1 / nrow1 / 100.0);
        tbl_Aggregate_TD_3494765_output.setInt64(r, 4, _agg23546);
        int64_t _agg33547 = ((it.second)._agg33547_avg_2 / nrow1 / 100.0);
        tbl_Aggregate_TD_3494765_output.setInt64(r, 5, _agg33547);
        int64_t _agg43548 = ((it.second)._agg43548_avg_3 / nrow1 / 100.0);
        tbl_Aggregate_TD_3494765_output.setInt64(r, 6, _agg43548);
        ++r;
    }
    tbl_Aggregate_TD_3494765_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_3494765_output #Row: " << tbl_Aggregate_TD_3494765_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2827164(Table &tbl_Aggregate_TD_3494765_output, Table &tbl_Sort_TD_2827164_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(i_item_id#3556 ASC NULLS FIRST, s_state#3557 ASC NULLS FIRST)
    // Input: ListBuffer(i_item_id#3556, s_state#3557, g_state#3544, agg1#3545, agg2#3546, agg3#3547, agg4#3548)
    // Output: ListBuffer(i_item_id#3556, s_state#3557, g_state#3544, agg1#3545, agg2#3546, agg3#3547, agg4#3548)
    struct SW_Sort_TD_2827164Row {
        std::string _i_item_id3556;
        std::string _s_state3557;
        int32_t _g_state3544;
        int64_t _agg13545;
        int64_t _agg23546;
        int64_t _agg33547;
        int64_t _agg43548;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2827164Row& a, const SW_Sort_TD_2827164Row& b) const { return 
 (a._i_item_id3556 < b._i_item_id3556) || 
 ((a._i_item_id3556 == b._i_item_id3556) && (a._s_state3557 < b._s_state3557)); 
}
    }SW_Sort_TD_2827164_order; 

    int nrow1 = tbl_Aggregate_TD_3494765_output.getNumRow();
    std::vector<SW_Sort_TD_2827164Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id3556 = tbl_Aggregate_TD_3494765_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _s_state3557 = tbl_Aggregate_TD_3494765_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        int32_t _g_state3544 = tbl_Aggregate_TD_3494765_output.getInt32(i, 2);
        int32_t _agg13545 = tbl_Aggregate_TD_3494765_output.getInt32(i, 3);
        int64_t _agg23546 = tbl_Aggregate_TD_3494765_output.getInt64(i, 4);
        int64_t _agg33547 = tbl_Aggregate_TD_3494765_output.getInt64(i, 5);
        int64_t _agg43548 = tbl_Aggregate_TD_3494765_output.getInt64(i, 6);
        SW_Sort_TD_2827164Row t = {std::string(_i_item_id3556.data()),std::string(_s_state3557.data()),_g_state3544,_agg13545,_agg23546,_agg33547,_agg43548};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2827164_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id3556{};
        memcpy(_i_item_id3556.data(), (it._i_item_id3556).data(), (it._i_item_id3556).length());
        tbl_Sort_TD_2827164_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _i_item_id3556);
        std::array<char, TPCDS_READ_MAX + 1> _s_state3557{};
        memcpy(_s_state3557.data(), (it._s_state3557).data(), (it._s_state3557).length());
        tbl_Sort_TD_2827164_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _s_state3557);
        tbl_Sort_TD_2827164_output.setInt32(r, 2, it._g_state3544);
        tbl_Sort_TD_2827164_output.setInt32(r, 3, it._agg13545);
        tbl_Sort_TD_2827164_output.setInt64(r, 4, it._agg23546);
        tbl_Sort_TD_2827164_output.setInt64(r, 5, it._agg33547);
        tbl_Sort_TD_2827164_output.setInt64(r, 6, it._agg43548);
        ++r;
    }
    tbl_Sort_TD_2827164_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2827164_output #Row: " << tbl_Sort_TD_2827164_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1216500(Table &tbl_Sort_TD_2827164_output, Table &tbl_LocalLimit_TD_1216500_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(i_item_id#3556, s_state#3557, g_state#3544, agg1#3545, agg2#3546, agg3#3547, agg4#3548)
    // Output: ListBuffer(i_item_id#3556, s_state#3557, g_state#3544, agg1#3545, agg2#3546, agg3#3547, agg4#3548)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id3556_n = tbl_Sort_TD_2827164_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1216500_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id3556_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_state3557_n = tbl_Sort_TD_2827164_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_1216500_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_state3557_n);
        tbl_LocalLimit_TD_1216500_output.setInt32(r, 2, tbl_Sort_TD_2827164_output.getInt32(i, 2));
        tbl_LocalLimit_TD_1216500_output.setInt64(r, 3, tbl_Sort_TD_2827164_output.getInt64(i, 3));
        tbl_LocalLimit_TD_1216500_output.setInt64(r, 4, tbl_Sort_TD_2827164_output.getInt64(i, 4));
        tbl_LocalLimit_TD_1216500_output.setInt64(r, 5, tbl_Sort_TD_2827164_output.getInt64(i, 5));
        tbl_LocalLimit_TD_1216500_output.setInt64(r, 6, tbl_Sort_TD_2827164_output.getInt64(i, 6));
        r++;
    }
    tbl_LocalLimit_TD_1216500_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1216500_output #Row: " << tbl_LocalLimit_TD_1216500_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0318897(Table &tbl_LocalLimit_TD_1216500_output, Table &tbl_GlobalLimit_TD_0318897_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(i_item_id#3556, s_state#3557, g_state#3544, agg1#3545, agg2#3546, agg3#3547, agg4#3548)
    // Output: ListBuffer(i_item_id#3556, s_state#3557, g_state#3544, agg1#3545, agg2#3546, agg3#3547, agg4#3548)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id3556_n = tbl_LocalLimit_TD_1216500_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0318897_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id3556_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_state3557_n = tbl_LocalLimit_TD_1216500_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_0318897_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_state3557_n);
        tbl_GlobalLimit_TD_0318897_output.setInt32(r, 2, tbl_LocalLimit_TD_1216500_output.getInt32(i, 2));
        tbl_GlobalLimit_TD_0318897_output.setInt64(r, 3, tbl_LocalLimit_TD_1216500_output.getInt64(i, 3));
        tbl_GlobalLimit_TD_0318897_output.setInt64(r, 4, tbl_LocalLimit_TD_1216500_output.getInt64(i, 4));
        tbl_GlobalLimit_TD_0318897_output.setInt64(r, 5, tbl_LocalLimit_TD_1216500_output.getInt64(i, 5));
        tbl_GlobalLimit_TD_0318897_output.setInt64(r, 6, tbl_LocalLimit_TD_1216500_output.getInt64(i, 6));
        r++;
    }
    tbl_GlobalLimit_TD_0318897_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0318897_output #Row: " << tbl_GlobalLimit_TD_0318897_output.getNumRow() << std::endl;
}

