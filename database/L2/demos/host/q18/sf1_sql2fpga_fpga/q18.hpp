#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_1132354(Table &tbl_SerializeFromObject_TD_12302435_input, Table &tbl_Filter_TD_1132354_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(cd_gender#94) AND isnotnull(cd_education_status#96)) AND ((cd_gender#94 = F) AND (cd_education_status#96 = Unknown))) AND isnotnull(cd_demo_sk#93)))
    // Input: ListBuffer(cd_demo_sk#93, cd_dep_count#99, cd_gender#94, cd_education_status#96)
    // Output: ListBuffer(cd_demo_sk#93, cd_dep_count#99)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12302435_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _cd_gender94 = tbl_SerializeFromObject_TD_12302435_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96 = tbl_SerializeFromObject_TD_12302435_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        int32_t _cd_demo_sk93 = tbl_SerializeFromObject_TD_12302435_input.getInt32(i, 0);
        if (((_cd_gender94.data() != "NULL" && _cd_education_status96.data() != "NULL") && ((std::string(_cd_gender94.data()) == "F") && (std::string(_cd_education_status96.data()) == "Unknown"))) && (_cd_demo_sk93!= 0)) {
            int32_t _cd_demo_sk93_t = tbl_SerializeFromObject_TD_12302435_input.getInt32(i, 0);
            tbl_Filter_TD_1132354_output.setInt32(r, 0, _cd_demo_sk93_t);
            int32_t _cd_dep_count99_t = tbl_SerializeFromObject_TD_12302435_input.getInt32(i, 1);
            tbl_Filter_TD_1132354_output.setInt32(r, 1, _cd_dep_count99_t);
            r++;
        }
    }
    tbl_Filter_TD_1132354_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1132354_output #Row: " << tbl_Filter_TD_1132354_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11717203(Table &tbl_SerializeFromObject_TD_12525558_input, Table &tbl_Filter_TD_11717203_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(cs_bill_cdemo_sk#1108) AND isnotnull(cs_bill_customer_sk#1107)) AND (isnotnull(cs_sold_date_sk#1104) AND isnotnull(cs_item_sk#1119))))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_bill_cdemo_sk#1108, cs_item_sk#1119, cs_quantity#1122, cs_list_price#1124, cs_sales_price#1125, cs_coupon_amt#1131, cs_net_profit#1137)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_bill_cdemo_sk#1108, cs_item_sk#1119, cs_quantity#1122, cs_list_price#1124, cs_sales_price#1125, cs_coupon_amt#1131, cs_net_profit#1137)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12525558_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_bill_cdemo_sk1108 = tbl_SerializeFromObject_TD_12525558_input.getInt32(i, 2);
        int32_t _cs_bill_customer_sk1107 = tbl_SerializeFromObject_TD_12525558_input.getInt32(i, 1);
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_12525558_input.getInt32(i, 0);
        int32_t _cs_item_sk1119 = tbl_SerializeFromObject_TD_12525558_input.getInt32(i, 3);
        if (((_cs_bill_cdemo_sk1108!= 0) && (_cs_bill_customer_sk1107!= 0)) && ((_cs_sold_date_sk1104!= 0) && (_cs_item_sk1119!= 0))) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_12525558_input.getInt32(i, 0);
            tbl_Filter_TD_11717203_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int32_t _cs_bill_customer_sk1107_t = tbl_SerializeFromObject_TD_12525558_input.getInt32(i, 1);
            tbl_Filter_TD_11717203_output.setInt32(r, 1, _cs_bill_customer_sk1107_t);
            int32_t _cs_bill_cdemo_sk1108_t = tbl_SerializeFromObject_TD_12525558_input.getInt32(i, 2);
            tbl_Filter_TD_11717203_output.setInt32(r, 2, _cs_bill_cdemo_sk1108_t);
            int32_t _cs_item_sk1119_t = tbl_SerializeFromObject_TD_12525558_input.getInt32(i, 3);
            tbl_Filter_TD_11717203_output.setInt32(r, 3, _cs_item_sk1119_t);
            int32_t _cs_quantity1122_t = tbl_SerializeFromObject_TD_12525558_input.getInt32(i, 4);
            tbl_Filter_TD_11717203_output.setInt32(r, 4, _cs_quantity1122_t);
            int64_t _cs_list_price1124_t = tbl_SerializeFromObject_TD_12525558_input.getInt64(i, 5);
            tbl_Filter_TD_11717203_output.setInt64(r, 5, _cs_list_price1124_t);
            int64_t _cs_sales_price1125_t = tbl_SerializeFromObject_TD_12525558_input.getInt64(i, 6);
            tbl_Filter_TD_11717203_output.setInt64(r, 6, _cs_sales_price1125_t);
            int64_t _cs_coupon_amt1131_t = tbl_SerializeFromObject_TD_12525558_input.getInt64(i, 7);
            tbl_Filter_TD_11717203_output.setInt64(r, 7, _cs_coupon_amt1131_t);
            int64_t _cs_net_profit1137_t = tbl_SerializeFromObject_TD_12525558_input.getInt64(i, 8);
            tbl_Filter_TD_11717203_output.setInt64(r, 8, _cs_net_profit1137_t);
            r++;
        }
    }
    tbl_Filter_TD_11717203_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11717203_output #Row: " << tbl_Filter_TD_11717203_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10725660(Table &tbl_SerializeFromObject_TD_11936941_input, Table &tbl_Filter_TD_10725660_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((c_birth_month#12 IN (1,6,8,9,12,2) AND isnotnull(c_customer_sk#0)) AND (isnotnull(c_current_cdemo_sk#2) AND isnotnull(c_current_addr_sk#4))))
    // Input: ListBuffer(c_customer_sk#0, c_current_cdemo_sk#2, c_current_addr_sk#4, c_birth_year#13, c_birth_month#12)
    // Output: ListBuffer(c_customer_sk#0, c_current_cdemo_sk#2, c_current_addr_sk#4, c_birth_year#13)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11936941_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_birth_month12 = tbl_SerializeFromObject_TD_11936941_input.getInt32(i, 4);
        int32_t _c_customer_sk0 = tbl_SerializeFromObject_TD_11936941_input.getInt32(i, 0);
        int32_t _c_current_cdemo_sk2 = tbl_SerializeFromObject_TD_11936941_input.getInt32(i, 1);
        int32_t _c_current_addr_sk4 = tbl_SerializeFromObject_TD_11936941_input.getInt32(i, 2);
        auto reuse_col_str_675 = _c_birth_month12;
        if ((((reuse_col_str_675 == 1) || (reuse_col_str_675 == 6) || (reuse_col_str_675 == 8) || (reuse_col_str_675 == 9) || (reuse_col_str_675 == 12) || (reuse_col_str_675 == 2) || (0)) && (_c_customer_sk0!= 0)) && ((_c_current_cdemo_sk2!= 0) && (_c_current_addr_sk4!= 0))) {
            int32_t _c_customer_sk0_t = tbl_SerializeFromObject_TD_11936941_input.getInt32(i, 0);
            tbl_Filter_TD_10725660_output.setInt32(r, 0, _c_customer_sk0_t);
            int32_t _c_current_cdemo_sk2_t = tbl_SerializeFromObject_TD_11936941_input.getInt32(i, 1);
            tbl_Filter_TD_10725660_output.setInt32(r, 1, _c_current_cdemo_sk2_t);
            int32_t _c_current_addr_sk4_t = tbl_SerializeFromObject_TD_11936941_input.getInt32(i, 2);
            tbl_Filter_TD_10725660_output.setInt32(r, 2, _c_current_addr_sk4_t);
            int32_t _c_birth_year13_t = tbl_SerializeFromObject_TD_11936941_input.getInt32(i, 3);
            tbl_Filter_TD_10725660_output.setInt32(r, 3, _c_birth_year13_t);
            r++;
        }
    }
    tbl_Filter_TD_10725660_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10725660_output #Row: " << tbl_Filter_TD_10725660_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_10298733_key_leftMajor {
    int32_t _cs_bill_cdemo_sk1108;
    bool operator==(const SW_JOIN_INNER_TD_10298733_key_leftMajor& other) const {
        return ((_cs_bill_cdemo_sk1108 == other._cs_bill_cdemo_sk1108));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10298733_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10298733_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_bill_cdemo_sk1108));
    }
};
}
struct SW_JOIN_INNER_TD_10298733_payload_leftMajor {
    int32_t _cs_sold_date_sk1104;
    int32_t _cs_bill_customer_sk1107;
    int32_t _cs_bill_cdemo_sk1108;
    int32_t _cs_item_sk1119;
    int32_t _cs_quantity1122;
    int64_t _cs_list_price1124;
    int64_t _cs_sales_price1125;
    int64_t _cs_coupon_amt1131;
    int64_t _cs_net_profit1137;
};
struct SW_JOIN_INNER_TD_10298733_key_rightMajor {
    int32_t _cd_demo_sk93;
    bool operator==(const SW_JOIN_INNER_TD_10298733_key_rightMajor& other) const {
        return ((_cd_demo_sk93 == other._cd_demo_sk93));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10298733_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10298733_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cd_demo_sk93));
    }
};
}
struct SW_JOIN_INNER_TD_10298733_payload_rightMajor {
    int32_t _cd_demo_sk93;
    int32_t _cd_dep_count99;
};
void SW_JOIN_INNER_TD_10298733(Table &tbl_Filter_TD_11717203_output, Table &tbl_Filter_TD_1132354_output, Table &tbl_JOIN_INNER_TD_10298733_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_bill_cdemo_sk#1108 = cd_demo_sk#93))
    // Left Table: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_bill_cdemo_sk#1108, cs_item_sk#1119, cs_quantity#1122, cs_list_price#1124, cs_sales_price#1125, cs_coupon_amt#1131, cs_net_profit#1137)
    // Right Table: ListBuffer(cd_demo_sk#93, cd_dep_count#99)
    // Output Table: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_item_sk#1119, cs_quantity#1122, cs_list_price#1124, cs_sales_price#1125, cs_coupon_amt#1131, cs_net_profit#1137, cd_dep_count#99)
    int left_nrow = tbl_Filter_TD_11717203_output.getNumRow();
    int right_nrow = tbl_Filter_TD_1132354_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10298733_key_leftMajor, SW_JOIN_INNER_TD_10298733_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_11717203_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_bill_cdemo_sk1108_k = tbl_Filter_TD_11717203_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_10298733_key_leftMajor keyA{_cs_bill_cdemo_sk1108_k};
            int32_t _cs_sold_date_sk1104 = tbl_Filter_TD_11717203_output.getInt32(i, 0);
            int32_t _cs_bill_customer_sk1107 = tbl_Filter_TD_11717203_output.getInt32(i, 1);
            int32_t _cs_bill_cdemo_sk1108 = tbl_Filter_TD_11717203_output.getInt32(i, 2);
            int32_t _cs_item_sk1119 = tbl_Filter_TD_11717203_output.getInt32(i, 3);
            int32_t _cs_quantity1122 = tbl_Filter_TD_11717203_output.getInt32(i, 4);
            int64_t _cs_list_price1124 = tbl_Filter_TD_11717203_output.getInt64(i, 5);
            int64_t _cs_sales_price1125 = tbl_Filter_TD_11717203_output.getInt64(i, 6);
            int64_t _cs_coupon_amt1131 = tbl_Filter_TD_11717203_output.getInt64(i, 7);
            int64_t _cs_net_profit1137 = tbl_Filter_TD_11717203_output.getInt64(i, 8);
            SW_JOIN_INNER_TD_10298733_payload_leftMajor payloadA{_cs_sold_date_sk1104, _cs_bill_customer_sk1107, _cs_bill_cdemo_sk1108, _cs_item_sk1119, _cs_quantity1122, _cs_list_price1124, _cs_sales_price1125, _cs_coupon_amt1131, _cs_net_profit1137};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_1132354_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cd_demo_sk93_k = tbl_Filter_TD_1132354_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10298733_key_leftMajor{_cd_demo_sk93_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk1104 = (it->second)._cs_sold_date_sk1104;
                int32_t _cs_bill_customer_sk1107 = (it->second)._cs_bill_customer_sk1107;
                int32_t _cs_bill_cdemo_sk1108 = (it->second)._cs_bill_cdemo_sk1108;
                int32_t _cs_item_sk1119 = (it->second)._cs_item_sk1119;
                int32_t _cs_quantity1122 = (it->second)._cs_quantity1122;
                int64_t _cs_list_price1124 = (it->second)._cs_list_price1124;
                int64_t _cs_sales_price1125 = (it->second)._cs_sales_price1125;
                int64_t _cs_coupon_amt1131 = (it->second)._cs_coupon_amt1131;
                int64_t _cs_net_profit1137 = (it->second)._cs_net_profit1137;
                int32_t _cd_demo_sk93 = tbl_Filter_TD_1132354_output.getInt32(i, 0);
                int32_t _cd_dep_count99 = tbl_Filter_TD_1132354_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_10298733_output.setInt32(r, 0, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_10298733_output.setInt32(r, 1, _cs_bill_customer_sk1107);
                tbl_JOIN_INNER_TD_10298733_output.setInt32(r, 2, _cs_item_sk1119);
                tbl_JOIN_INNER_TD_10298733_output.setInt32(r, 3, _cs_quantity1122);
                tbl_JOIN_INNER_TD_10298733_output.setInt64(r, 4, _cs_list_price1124);
                tbl_JOIN_INNER_TD_10298733_output.setInt64(r, 5, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_10298733_output.setInt64(r, 6, _cs_coupon_amt1131);
                tbl_JOIN_INNER_TD_10298733_output.setInt64(r, 7, _cs_net_profit1137);
                tbl_JOIN_INNER_TD_10298733_output.setInt32(r, 8, _cd_dep_count99);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10298733_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10298733_key_rightMajor, SW_JOIN_INNER_TD_10298733_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_1132354_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cd_demo_sk93_k = tbl_Filter_TD_1132354_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_10298733_key_rightMajor keyA{_cd_demo_sk93_k};
            int32_t _cd_demo_sk93 = tbl_Filter_TD_1132354_output.getInt32(i, 0);
            int32_t _cd_dep_count99 = tbl_Filter_TD_1132354_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_10298733_payload_rightMajor payloadA{_cd_demo_sk93, _cd_dep_count99};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_11717203_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_bill_cdemo_sk1108_k = tbl_Filter_TD_11717203_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10298733_key_rightMajor{_cs_bill_cdemo_sk1108_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cd_demo_sk93 = (it->second)._cd_demo_sk93;
                int32_t _cd_dep_count99 = (it->second)._cd_dep_count99;
                int32_t _cs_sold_date_sk1104 = tbl_Filter_TD_11717203_output.getInt32(i, 0);
                int32_t _cs_bill_customer_sk1107 = tbl_Filter_TD_11717203_output.getInt32(i, 1);
                int32_t _cs_bill_cdemo_sk1108 = tbl_Filter_TD_11717203_output.getInt32(i, 2);
                int32_t _cs_item_sk1119 = tbl_Filter_TD_11717203_output.getInt32(i, 3);
                int32_t _cs_quantity1122 = tbl_Filter_TD_11717203_output.getInt32(i, 4);
                int64_t _cs_list_price1124 = tbl_Filter_TD_11717203_output.getInt64(i, 5);
                int64_t _cs_sales_price1125 = tbl_Filter_TD_11717203_output.getInt64(i, 6);
                int64_t _cs_coupon_amt1131 = tbl_Filter_TD_11717203_output.getInt64(i, 7);
                int64_t _cs_net_profit1137 = tbl_Filter_TD_11717203_output.getInt64(i, 8);
                tbl_JOIN_INNER_TD_10298733_output.setInt32(r, 8, _cd_dep_count99);
                tbl_JOIN_INNER_TD_10298733_output.setInt32(r, 0, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_10298733_output.setInt32(r, 1, _cs_bill_customer_sk1107);
                tbl_JOIN_INNER_TD_10298733_output.setInt32(r, 2, _cs_item_sk1119);
                tbl_JOIN_INNER_TD_10298733_output.setInt32(r, 3, _cs_quantity1122);
                tbl_JOIN_INNER_TD_10298733_output.setInt64(r, 4, _cs_list_price1124);
                tbl_JOIN_INNER_TD_10298733_output.setInt64(r, 5, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_10298733_output.setInt64(r, 6, _cs_coupon_amt1131);
                tbl_JOIN_INNER_TD_10298733_output.setInt64(r, 7, _cs_net_profit1137);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10298733_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_10298733_output #Row: " << tbl_JOIN_INNER_TD_10298733_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9573228(Table &tbl_SerializeFromObject_TD_10769478_input, Table &tbl_Filter_TD_9573228_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(cd_demo_sk#3551))
    // Input: ListBuffer(cd_demo_sk#3551)
    // Output: ListBuffer(cd_demo_sk#3551)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10769478_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cd_demo_sk3551 = tbl_SerializeFromObject_TD_10769478_input.getInt32(i, 0);
        if (_cd_demo_sk3551!= 0) {
            int32_t _cd_demo_sk3551_t = tbl_SerializeFromObject_TD_10769478_input.getInt32(i, 0);
            tbl_Filter_TD_9573228_output.setInt32(r, 0, _cd_demo_sk3551_t);
            r++;
        }
    }
    tbl_Filter_TD_9573228_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9573228_output #Row: " << tbl_Filter_TD_9573228_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_9835286_key_leftMajor {
    int32_t _cs_bill_customer_sk1107;
    bool operator==(const SW_JOIN_INNER_TD_9835286_key_leftMajor& other) const {
        return ((_cs_bill_customer_sk1107 == other._cs_bill_customer_sk1107));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9835286_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9835286_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_bill_customer_sk1107));
    }
};
}
struct SW_JOIN_INNER_TD_9835286_payload_leftMajor {
    int32_t _cs_sold_date_sk1104;
    int32_t _cs_bill_customer_sk1107;
    int32_t _cs_item_sk1119;
    int32_t _cs_quantity1122;
    int64_t _cs_list_price1124;
    int64_t _cs_sales_price1125;
    int64_t _cs_coupon_amt1131;
    int64_t _cs_net_profit1137;
    int32_t _cd_dep_count99;
};
struct SW_JOIN_INNER_TD_9835286_key_rightMajor {
    int32_t _c_customer_sk0;
    bool operator==(const SW_JOIN_INNER_TD_9835286_key_rightMajor& other) const {
        return ((_c_customer_sk0 == other._c_customer_sk0));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9835286_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9835286_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk0));
    }
};
}
struct SW_JOIN_INNER_TD_9835286_payload_rightMajor {
    int32_t _c_customer_sk0;
    int32_t _c_current_cdemo_sk2;
    int32_t _c_current_addr_sk4;
    int32_t _c_birth_year13;
};
void SW_JOIN_INNER_TD_9835286(Table &tbl_JOIN_INNER_TD_10298733_output, Table &tbl_Filter_TD_10725660_output, Table &tbl_JOIN_INNER_TD_9835286_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_bill_customer_sk#1107 = c_customer_sk#0))
    // Left Table: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_item_sk#1119, cs_quantity#1122, cs_list_price#1124, cs_sales_price#1125, cs_coupon_amt#1131, cs_net_profit#1137, cd_dep_count#99)
    // Right Table: ListBuffer(c_customer_sk#0, c_current_cdemo_sk#2, c_current_addr_sk#4, c_birth_year#13)
    // Output Table: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119, cs_quantity#1122, cs_list_price#1124, cs_sales_price#1125, cs_coupon_amt#1131, cs_net_profit#1137, cd_dep_count#99, c_current_cdemo_sk#2, c_current_addr_sk#4, c_birth_year#13)
    int left_nrow = tbl_JOIN_INNER_TD_10298733_output.getNumRow();
    int right_nrow = tbl_Filter_TD_10725660_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9835286_key_leftMajor, SW_JOIN_INNER_TD_9835286_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_10298733_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_bill_customer_sk1107_k = tbl_JOIN_INNER_TD_10298733_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_9835286_key_leftMajor keyA{_cs_bill_customer_sk1107_k};
            int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_10298733_output.getInt32(i, 0);
            int32_t _cs_bill_customer_sk1107 = tbl_JOIN_INNER_TD_10298733_output.getInt32(i, 1);
            int32_t _cs_item_sk1119 = tbl_JOIN_INNER_TD_10298733_output.getInt32(i, 2);
            int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_10298733_output.getInt32(i, 3);
            int64_t _cs_list_price1124 = tbl_JOIN_INNER_TD_10298733_output.getInt64(i, 4);
            int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_10298733_output.getInt64(i, 5);
            int64_t _cs_coupon_amt1131 = tbl_JOIN_INNER_TD_10298733_output.getInt64(i, 6);
            int64_t _cs_net_profit1137 = tbl_JOIN_INNER_TD_10298733_output.getInt64(i, 7);
            int32_t _cd_dep_count99 = tbl_JOIN_INNER_TD_10298733_output.getInt32(i, 8);
            SW_JOIN_INNER_TD_9835286_payload_leftMajor payloadA{_cs_sold_date_sk1104, _cs_bill_customer_sk1107, _cs_item_sk1119, _cs_quantity1122, _cs_list_price1124, _cs_sales_price1125, _cs_coupon_amt1131, _cs_net_profit1137, _cd_dep_count99};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_10725660_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_10725660_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9835286_key_leftMajor{_c_customer_sk0_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk1104 = (it->second)._cs_sold_date_sk1104;
                int32_t _cs_bill_customer_sk1107 = (it->second)._cs_bill_customer_sk1107;
                int32_t _cs_item_sk1119 = (it->second)._cs_item_sk1119;
                int32_t _cs_quantity1122 = (it->second)._cs_quantity1122;
                int64_t _cs_list_price1124 = (it->second)._cs_list_price1124;
                int64_t _cs_sales_price1125 = (it->second)._cs_sales_price1125;
                int64_t _cs_coupon_amt1131 = (it->second)._cs_coupon_amt1131;
                int64_t _cs_net_profit1137 = (it->second)._cs_net_profit1137;
                int32_t _cd_dep_count99 = (it->second)._cd_dep_count99;
                int32_t _c_customer_sk0 = tbl_Filter_TD_10725660_output.getInt32(i, 0);
                int32_t _c_current_cdemo_sk2 = tbl_Filter_TD_10725660_output.getInt32(i, 1);
                int32_t _c_current_addr_sk4 = tbl_Filter_TD_10725660_output.getInt32(i, 2);
                int32_t _c_birth_year13 = tbl_Filter_TD_10725660_output.getInt32(i, 3);
                tbl_JOIN_INNER_TD_9835286_output.setInt32(r, 0, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_9835286_output.setInt32(r, 1, _cs_item_sk1119);
                tbl_JOIN_INNER_TD_9835286_output.setInt32(r, 2, _cs_quantity1122);
                tbl_JOIN_INNER_TD_9835286_output.setInt64(r, 3, _cs_list_price1124);
                tbl_JOIN_INNER_TD_9835286_output.setInt64(r, 4, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_9835286_output.setInt64(r, 5, _cs_coupon_amt1131);
                tbl_JOIN_INNER_TD_9835286_output.setInt64(r, 6, _cs_net_profit1137);
                tbl_JOIN_INNER_TD_9835286_output.setInt32(r, 7, _cd_dep_count99);
                tbl_JOIN_INNER_TD_9835286_output.setInt32(r, 8, _c_current_cdemo_sk2);
                tbl_JOIN_INNER_TD_9835286_output.setInt32(r, 9, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_9835286_output.setInt32(r, 10, _c_birth_year13);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9835286_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9835286_key_rightMajor, SW_JOIN_INNER_TD_9835286_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_10725660_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_10725660_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_9835286_key_rightMajor keyA{_c_customer_sk0_k};
            int32_t _c_customer_sk0 = tbl_Filter_TD_10725660_output.getInt32(i, 0);
            int32_t _c_current_cdemo_sk2 = tbl_Filter_TD_10725660_output.getInt32(i, 1);
            int32_t _c_current_addr_sk4 = tbl_Filter_TD_10725660_output.getInt32(i, 2);
            int32_t _c_birth_year13 = tbl_Filter_TD_10725660_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_9835286_payload_rightMajor payloadA{_c_customer_sk0, _c_current_cdemo_sk2, _c_current_addr_sk4, _c_birth_year13};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_10298733_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_bill_customer_sk1107_k = tbl_JOIN_INNER_TD_10298733_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9835286_key_rightMajor{_cs_bill_customer_sk1107_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk0 = (it->second)._c_customer_sk0;
                int32_t _c_current_cdemo_sk2 = (it->second)._c_current_cdemo_sk2;
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                int32_t _c_birth_year13 = (it->second)._c_birth_year13;
                int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_10298733_output.getInt32(i, 0);
                int32_t _cs_bill_customer_sk1107 = tbl_JOIN_INNER_TD_10298733_output.getInt32(i, 1);
                int32_t _cs_item_sk1119 = tbl_JOIN_INNER_TD_10298733_output.getInt32(i, 2);
                int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_10298733_output.getInt32(i, 3);
                int64_t _cs_list_price1124 = tbl_JOIN_INNER_TD_10298733_output.getInt64(i, 4);
                int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_10298733_output.getInt64(i, 5);
                int64_t _cs_coupon_amt1131 = tbl_JOIN_INNER_TD_10298733_output.getInt64(i, 6);
                int64_t _cs_net_profit1137 = tbl_JOIN_INNER_TD_10298733_output.getInt64(i, 7);
                int32_t _cd_dep_count99 = tbl_JOIN_INNER_TD_10298733_output.getInt32(i, 8);
                tbl_JOIN_INNER_TD_9835286_output.setInt32(r, 8, _c_current_cdemo_sk2);
                tbl_JOIN_INNER_TD_9835286_output.setInt32(r, 9, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_9835286_output.setInt32(r, 10, _c_birth_year13);
                tbl_JOIN_INNER_TD_9835286_output.setInt32(r, 0, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_9835286_output.setInt32(r, 1, _cs_item_sk1119);
                tbl_JOIN_INNER_TD_9835286_output.setInt32(r, 2, _cs_quantity1122);
                tbl_JOIN_INNER_TD_9835286_output.setInt64(r, 3, _cs_list_price1124);
                tbl_JOIN_INNER_TD_9835286_output.setInt64(r, 4, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_9835286_output.setInt64(r, 5, _cs_coupon_amt1131);
                tbl_JOIN_INNER_TD_9835286_output.setInt64(r, 6, _cs_net_profit1137);
                tbl_JOIN_INNER_TD_9835286_output.setInt32(r, 7, _cd_dep_count99);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9835286_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_9835286_output #Row: " << tbl_JOIN_INNER_TD_9835286_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8235861(Table &tbl_SerializeFromObject_TD_9446975_input, Table &tbl_Filter_TD_8235861_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((ca_state#62 IN (MS,IN,ND,OK,NM,VA) AND isnotnull(ca_address_sk#54)))
    // Input: ListBuffer(ca_address_sk#54, ca_county#61, ca_state#62, ca_country#64)
    // Output: ListBuffer(ca_address_sk#54, ca_county#61, ca_state#62, ca_country#64)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9446975_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_state62 = tbl_SerializeFromObject_TD_9446975_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        int32_t _ca_address_sk54 = tbl_SerializeFromObject_TD_9446975_input.getInt32(i, 0);
        auto reuse_col_str_537 = std::string(_ca_state62.data());
        if (((reuse_col_str_537 == "MS") || (reuse_col_str_537 == "IN") || (reuse_col_str_537 == "ND") || (reuse_col_str_537 == "OK") || (reuse_col_str_537 == "NM") || (reuse_col_str_537 == "VA") || (0)) && (_ca_address_sk54!= 0)) {
            int32_t _ca_address_sk54_t = tbl_SerializeFromObject_TD_9446975_input.getInt32(i, 0);
            tbl_Filter_TD_8235861_output.setInt32(r, 0, _ca_address_sk54_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_county61_t = tbl_SerializeFromObject_TD_9446975_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_8235861_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_county61_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_t = tbl_SerializeFromObject_TD_9446975_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_8235861_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_state62_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_country64_t = tbl_SerializeFromObject_TD_9446975_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_8235861_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_country64_t);
            r++;
        }
    }
    tbl_Filter_TD_8235861_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8235861_output #Row: " << tbl_Filter_TD_8235861_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8717419_key_leftMajor {
    int32_t _c_current_cdemo_sk2;
    bool operator==(const SW_JOIN_INNER_TD_8717419_key_leftMajor& other) const {
        return ((_c_current_cdemo_sk2 == other._c_current_cdemo_sk2));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8717419_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8717419_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_current_cdemo_sk2));
    }
};
}
struct SW_JOIN_INNER_TD_8717419_payload_leftMajor {
    int32_t _cs_sold_date_sk1104;
    int32_t _cs_item_sk1119;
    int32_t _cs_quantity1122;
    int64_t _cs_list_price1124;
    int64_t _cs_sales_price1125;
    int64_t _cs_coupon_amt1131;
    int64_t _cs_net_profit1137;
    int32_t _cd_dep_count99;
    int32_t _c_current_cdemo_sk2;
    int32_t _c_current_addr_sk4;
    int32_t _c_birth_year13;
};
struct SW_JOIN_INNER_TD_8717419_key_rightMajor {
    int32_t _cd_demo_sk3551;
    bool operator==(const SW_JOIN_INNER_TD_8717419_key_rightMajor& other) const {
        return ((_cd_demo_sk3551 == other._cd_demo_sk3551));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8717419_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8717419_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cd_demo_sk3551));
    }
};
}
struct SW_JOIN_INNER_TD_8717419_payload_rightMajor {
    int32_t _cd_demo_sk3551;
};
void SW_JOIN_INNER_TD_8717419(Table &tbl_JOIN_INNER_TD_9835286_output, Table &tbl_Filter_TD_9573228_output, Table &tbl_JOIN_INNER_TD_8717419_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((c_current_cdemo_sk#2 = cd_demo_sk#3551))
    // Left Table: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119, cs_quantity#1122, cs_list_price#1124, cs_sales_price#1125, cs_coupon_amt#1131, cs_net_profit#1137, cd_dep_count#99, c_current_cdemo_sk#2, c_current_addr_sk#4, c_birth_year#13)
    // Right Table: ListBuffer(cd_demo_sk#3551)
    // Output Table: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119, cs_quantity#1122, cs_list_price#1124, cs_sales_price#1125, cs_coupon_amt#1131, cs_net_profit#1137, cd_dep_count#99, c_current_addr_sk#4, c_birth_year#13)
    int left_nrow = tbl_JOIN_INNER_TD_9835286_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9573228_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8717419_key_leftMajor, SW_JOIN_INNER_TD_8717419_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_9835286_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_current_cdemo_sk2_k = tbl_JOIN_INNER_TD_9835286_output.getInt32(i, 8);
            SW_JOIN_INNER_TD_8717419_key_leftMajor keyA{_c_current_cdemo_sk2_k};
            int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_9835286_output.getInt32(i, 0);
            int32_t _cs_item_sk1119 = tbl_JOIN_INNER_TD_9835286_output.getInt32(i, 1);
            int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_9835286_output.getInt32(i, 2);
            int64_t _cs_list_price1124 = tbl_JOIN_INNER_TD_9835286_output.getInt64(i, 3);
            int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_9835286_output.getInt64(i, 4);
            int64_t _cs_coupon_amt1131 = tbl_JOIN_INNER_TD_9835286_output.getInt64(i, 5);
            int64_t _cs_net_profit1137 = tbl_JOIN_INNER_TD_9835286_output.getInt64(i, 6);
            int32_t _cd_dep_count99 = tbl_JOIN_INNER_TD_9835286_output.getInt32(i, 7);
            int32_t _c_current_cdemo_sk2 = tbl_JOIN_INNER_TD_9835286_output.getInt32(i, 8);
            int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_9835286_output.getInt32(i, 9);
            int32_t _c_birth_year13 = tbl_JOIN_INNER_TD_9835286_output.getInt32(i, 10);
            SW_JOIN_INNER_TD_8717419_payload_leftMajor payloadA{_cs_sold_date_sk1104, _cs_item_sk1119, _cs_quantity1122, _cs_list_price1124, _cs_sales_price1125, _cs_coupon_amt1131, _cs_net_profit1137, _cd_dep_count99, _c_current_cdemo_sk2, _c_current_addr_sk4, _c_birth_year13};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9573228_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cd_demo_sk3551_k = tbl_Filter_TD_9573228_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8717419_key_leftMajor{_cd_demo_sk3551_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk1104 = (it->second)._cs_sold_date_sk1104;
                int32_t _cs_item_sk1119 = (it->second)._cs_item_sk1119;
                int32_t _cs_quantity1122 = (it->second)._cs_quantity1122;
                int64_t _cs_list_price1124 = (it->second)._cs_list_price1124;
                int64_t _cs_sales_price1125 = (it->second)._cs_sales_price1125;
                int64_t _cs_coupon_amt1131 = (it->second)._cs_coupon_amt1131;
                int64_t _cs_net_profit1137 = (it->second)._cs_net_profit1137;
                int32_t _cd_dep_count99 = (it->second)._cd_dep_count99;
                int32_t _c_current_cdemo_sk2 = (it->second)._c_current_cdemo_sk2;
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                int32_t _c_birth_year13 = (it->second)._c_birth_year13;
                int32_t _cd_demo_sk3551 = tbl_Filter_TD_9573228_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_8717419_output.setInt32(r, 0, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_8717419_output.setInt32(r, 1, _cs_item_sk1119);
                tbl_JOIN_INNER_TD_8717419_output.setInt32(r, 2, _cs_quantity1122);
                tbl_JOIN_INNER_TD_8717419_output.setInt64(r, 3, _cs_list_price1124);
                tbl_JOIN_INNER_TD_8717419_output.setInt64(r, 4, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_8717419_output.setInt64(r, 5, _cs_coupon_amt1131);
                tbl_JOIN_INNER_TD_8717419_output.setInt64(r, 6, _cs_net_profit1137);
                tbl_JOIN_INNER_TD_8717419_output.setInt32(r, 7, _cd_dep_count99);
                tbl_JOIN_INNER_TD_8717419_output.setInt32(r, 8, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_8717419_output.setInt32(r, 9, _c_birth_year13);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8717419_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8717419_key_rightMajor, SW_JOIN_INNER_TD_8717419_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9573228_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cd_demo_sk3551_k = tbl_Filter_TD_9573228_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8717419_key_rightMajor keyA{_cd_demo_sk3551_k};
            int32_t _cd_demo_sk3551 = tbl_Filter_TD_9573228_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8717419_payload_rightMajor payloadA{_cd_demo_sk3551};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_9835286_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_current_cdemo_sk2_k = tbl_JOIN_INNER_TD_9835286_output.getInt32(i, 8);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8717419_key_rightMajor{_c_current_cdemo_sk2_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cd_demo_sk3551 = (it->second)._cd_demo_sk3551;
                int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_9835286_output.getInt32(i, 0);
                int32_t _cs_item_sk1119 = tbl_JOIN_INNER_TD_9835286_output.getInt32(i, 1);
                int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_9835286_output.getInt32(i, 2);
                int64_t _cs_list_price1124 = tbl_JOIN_INNER_TD_9835286_output.getInt64(i, 3);
                int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_9835286_output.getInt64(i, 4);
                int64_t _cs_coupon_amt1131 = tbl_JOIN_INNER_TD_9835286_output.getInt64(i, 5);
                int64_t _cs_net_profit1137 = tbl_JOIN_INNER_TD_9835286_output.getInt64(i, 6);
                int32_t _cd_dep_count99 = tbl_JOIN_INNER_TD_9835286_output.getInt32(i, 7);
                int32_t _c_current_cdemo_sk2 = tbl_JOIN_INNER_TD_9835286_output.getInt32(i, 8);
                int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_9835286_output.getInt32(i, 9);
                int32_t _c_birth_year13 = tbl_JOIN_INNER_TD_9835286_output.getInt32(i, 10);
                tbl_JOIN_INNER_TD_8717419_output.setInt32(r, 0, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_8717419_output.setInt32(r, 1, _cs_item_sk1119);
                tbl_JOIN_INNER_TD_8717419_output.setInt32(r, 2, _cs_quantity1122);
                tbl_JOIN_INNER_TD_8717419_output.setInt64(r, 3, _cs_list_price1124);
                tbl_JOIN_INNER_TD_8717419_output.setInt64(r, 4, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_8717419_output.setInt64(r, 5, _cs_coupon_amt1131);
                tbl_JOIN_INNER_TD_8717419_output.setInt64(r, 6, _cs_net_profit1137);
                tbl_JOIN_INNER_TD_8717419_output.setInt32(r, 7, _cd_dep_count99);
                tbl_JOIN_INNER_TD_8717419_output.setInt32(r, 8, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_8717419_output.setInt32(r, 9, _c_birth_year13);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8717419_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8717419_output #Row: " << tbl_JOIN_INNER_TD_8717419_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7361265(Table &tbl_SerializeFromObject_TD_8678348_input, Table &tbl_Filter_TD_7361265_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#126) AND (d_year#126 = 1998)) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8678348_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_8678348_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_8678348_input.getInt32(i, 0);
        if (((_d_year126!= 0) && (_d_year126 == 1998)) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_8678348_input.getInt32(i, 0);
            tbl_Filter_TD_7361265_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_7361265_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7361265_output #Row: " << tbl_Filter_TD_7361265_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_7582503_key_leftMajor {
    int32_t _c_current_addr_sk4;
    bool operator==(const SW_JOIN_INNER_TD_7582503_key_leftMajor& other) const {
        return ((_c_current_addr_sk4 == other._c_current_addr_sk4));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7582503_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7582503_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_current_addr_sk4));
    }
};
}
struct SW_JOIN_INNER_TD_7582503_payload_leftMajor {
    int32_t _cs_sold_date_sk1104;
    int32_t _cs_item_sk1119;
    int32_t _cs_quantity1122;
    int64_t _cs_list_price1124;
    int64_t _cs_sales_price1125;
    int64_t _cs_coupon_amt1131;
    int64_t _cs_net_profit1137;
    int32_t _cd_dep_count99;
    int32_t _c_current_addr_sk4;
    int32_t _c_birth_year13;
};
struct SW_JOIN_INNER_TD_7582503_key_rightMajor {
    int32_t _ca_address_sk54;
    bool operator==(const SW_JOIN_INNER_TD_7582503_key_rightMajor& other) const {
        return ((_ca_address_sk54 == other._ca_address_sk54));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7582503_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7582503_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk54));
    }
};
}
struct SW_JOIN_INNER_TD_7582503_payload_rightMajor {
    int32_t _ca_address_sk54;
    std::string _ca_county61;
    std::string _ca_state62;
    std::string _ca_country64;
};
void SW_JOIN_INNER_TD_7582503(Table &tbl_JOIN_INNER_TD_8717419_output, Table &tbl_Filter_TD_8235861_output, Table &tbl_JOIN_INNER_TD_7582503_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((c_current_addr_sk#4 = ca_address_sk#54))
    // Left Table: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119, cs_quantity#1122, cs_list_price#1124, cs_sales_price#1125, cs_coupon_amt#1131, cs_net_profit#1137, cd_dep_count#99, c_current_addr_sk#4, c_birth_year#13)
    // Right Table: ListBuffer(ca_address_sk#54, ca_county#61, ca_state#62, ca_country#64)
    // Output Table: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119, cs_quantity#1122, cs_list_price#1124, cs_sales_price#1125, cs_coupon_amt#1131, cs_net_profit#1137, cd_dep_count#99, c_birth_year#13, ca_county#61, ca_state#62, ca_country#64)
    int left_nrow = tbl_JOIN_INNER_TD_8717419_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8235861_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7582503_key_leftMajor, SW_JOIN_INNER_TD_7582503_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_8717419_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_current_addr_sk4_k = tbl_JOIN_INNER_TD_8717419_output.getInt32(i, 8);
            SW_JOIN_INNER_TD_7582503_key_leftMajor keyA{_c_current_addr_sk4_k};
            int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_8717419_output.getInt32(i, 0);
            int32_t _cs_item_sk1119 = tbl_JOIN_INNER_TD_8717419_output.getInt32(i, 1);
            int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_8717419_output.getInt32(i, 2);
            int64_t _cs_list_price1124 = tbl_JOIN_INNER_TD_8717419_output.getInt64(i, 3);
            int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_8717419_output.getInt64(i, 4);
            int64_t _cs_coupon_amt1131 = tbl_JOIN_INNER_TD_8717419_output.getInt64(i, 5);
            int64_t _cs_net_profit1137 = tbl_JOIN_INNER_TD_8717419_output.getInt64(i, 6);
            int32_t _cd_dep_count99 = tbl_JOIN_INNER_TD_8717419_output.getInt32(i, 7);
            int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_8717419_output.getInt32(i, 8);
            int32_t _c_birth_year13 = tbl_JOIN_INNER_TD_8717419_output.getInt32(i, 9);
            SW_JOIN_INNER_TD_7582503_payload_leftMajor payloadA{_cs_sold_date_sk1104, _cs_item_sk1119, _cs_quantity1122, _cs_list_price1124, _cs_sales_price1125, _cs_coupon_amt1131, _cs_net_profit1137, _cd_dep_count99, _c_current_addr_sk4, _c_birth_year13};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8235861_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_8235861_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7582503_key_leftMajor{_ca_address_sk54_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk1104 = (it->second)._cs_sold_date_sk1104;
                int32_t _cs_item_sk1119 = (it->second)._cs_item_sk1119;
                int32_t _cs_quantity1122 = (it->second)._cs_quantity1122;
                int64_t _cs_list_price1124 = (it->second)._cs_list_price1124;
                int64_t _cs_sales_price1125 = (it->second)._cs_sales_price1125;
                int64_t _cs_coupon_amt1131 = (it->second)._cs_coupon_amt1131;
                int64_t _cs_net_profit1137 = (it->second)._cs_net_profit1137;
                int32_t _cd_dep_count99 = (it->second)._cd_dep_count99;
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                int32_t _c_birth_year13 = (it->second)._c_birth_year13;
                int32_t _ca_address_sk54 = tbl_Filter_TD_8235861_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n = tbl_Filter_TD_8235861_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_county61 = std::string(_ca_county61_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_Filter_TD_8235861_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _ca_state62 = std::string(_ca_state62_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_country64_n = tbl_Filter_TD_8235861_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _ca_country64 = std::string(_ca_country64_n.data());
                tbl_JOIN_INNER_TD_7582503_output.setInt32(r, 0, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_7582503_output.setInt32(r, 1, _cs_item_sk1119);
                tbl_JOIN_INNER_TD_7582503_output.setInt32(r, 2, _cs_quantity1122);
                tbl_JOIN_INNER_TD_7582503_output.setInt64(r, 3, _cs_list_price1124);
                tbl_JOIN_INNER_TD_7582503_output.setInt64(r, 4, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_7582503_output.setInt64(r, 5, _cs_coupon_amt1131);
                tbl_JOIN_INNER_TD_7582503_output.setInt64(r, 6, _cs_net_profit1137);
                tbl_JOIN_INNER_TD_7582503_output.setInt32(r, 7, _cd_dep_count99);
                tbl_JOIN_INNER_TD_7582503_output.setInt32(r, 8, _c_birth_year13);
                tbl_JOIN_INNER_TD_7582503_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _ca_county61_n);
                tbl_JOIN_INNER_TD_7582503_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _ca_state62_n);
                tbl_JOIN_INNER_TD_7582503_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _ca_country64_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7582503_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7582503_key_rightMajor, SW_JOIN_INNER_TD_7582503_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8235861_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_8235861_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7582503_key_rightMajor keyA{_ca_address_sk54_k};
            int32_t _ca_address_sk54 = tbl_Filter_TD_8235861_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n = tbl_Filter_TD_8235861_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_county61 = std::string(_ca_county61_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_Filter_TD_8235861_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _ca_state62 = std::string(_ca_state62_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_country64_n = tbl_Filter_TD_8235861_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _ca_country64 = std::string(_ca_country64_n.data());
            SW_JOIN_INNER_TD_7582503_payload_rightMajor payloadA{_ca_address_sk54, _ca_county61, _ca_state62, _ca_country64};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_8717419_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_current_addr_sk4_k = tbl_JOIN_INNER_TD_8717419_output.getInt32(i, 8);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7582503_key_rightMajor{_c_current_addr_sk4_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk54 = (it->second)._ca_address_sk54;
                std::string _ca_county61 = (it->second)._ca_county61;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n{};
                memcpy(_ca_county61_n.data(), (_ca_county61).data(), (_ca_county61).length());
                std::string _ca_state62 = (it->second)._ca_state62;
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n{};
                memcpy(_ca_state62_n.data(), (_ca_state62).data(), (_ca_state62).length());
                std::string _ca_country64 = (it->second)._ca_country64;
                std::array<char, TPCDS_READ_MAX + 1> _ca_country64_n{};
                memcpy(_ca_country64_n.data(), (_ca_country64).data(), (_ca_country64).length());
                int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_8717419_output.getInt32(i, 0);
                int32_t _cs_item_sk1119 = tbl_JOIN_INNER_TD_8717419_output.getInt32(i, 1);
                int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_8717419_output.getInt32(i, 2);
                int64_t _cs_list_price1124 = tbl_JOIN_INNER_TD_8717419_output.getInt64(i, 3);
                int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_8717419_output.getInt64(i, 4);
                int64_t _cs_coupon_amt1131 = tbl_JOIN_INNER_TD_8717419_output.getInt64(i, 5);
                int64_t _cs_net_profit1137 = tbl_JOIN_INNER_TD_8717419_output.getInt64(i, 6);
                int32_t _cd_dep_count99 = tbl_JOIN_INNER_TD_8717419_output.getInt32(i, 7);
                int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_8717419_output.getInt32(i, 8);
                int32_t _c_birth_year13 = tbl_JOIN_INNER_TD_8717419_output.getInt32(i, 9);
                tbl_JOIN_INNER_TD_7582503_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _ca_county61_n);
                tbl_JOIN_INNER_TD_7582503_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _ca_state62_n);
                tbl_JOIN_INNER_TD_7582503_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _ca_country64_n);
                tbl_JOIN_INNER_TD_7582503_output.setInt32(r, 0, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_7582503_output.setInt32(r, 1, _cs_item_sk1119);
                tbl_JOIN_INNER_TD_7582503_output.setInt32(r, 2, _cs_quantity1122);
                tbl_JOIN_INNER_TD_7582503_output.setInt64(r, 3, _cs_list_price1124);
                tbl_JOIN_INNER_TD_7582503_output.setInt64(r, 4, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_7582503_output.setInt64(r, 5, _cs_coupon_amt1131);
                tbl_JOIN_INNER_TD_7582503_output.setInt64(r, 6, _cs_net_profit1137);
                tbl_JOIN_INNER_TD_7582503_output.setInt32(r, 7, _cd_dep_count99);
                tbl_JOIN_INNER_TD_7582503_output.setInt32(r, 8, _c_birth_year13);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7582503_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7582503_output #Row: " << tbl_JOIN_INNER_TD_7582503_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6117315(Table &tbl_SerializeFromObject_TD_7802083_input, Table &tbl_Filter_TD_6117315_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#228))
    // Input: ListBuffer(i_item_sk#228, i_item_id#229)
    // Output: ListBuffer(i_item_sk#228, i_item_id#229)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7802083_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_7802083_input.getInt32(i, 0);
        if (_i_item_sk228!= 0) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_7802083_input.getInt32(i, 0);
            tbl_Filter_TD_6117315_output.setInt32(r, 0, _i_item_sk228_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_t = tbl_SerializeFromObject_TD_7802083_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_6117315_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id229_t);
            r++;
        }
    }
    tbl_Filter_TD_6117315_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6117315_output #Row: " << tbl_Filter_TD_6117315_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6928432_key_leftMajor {
    int32_t _cs_sold_date_sk1104;
    bool operator==(const SW_JOIN_INNER_TD_6928432_key_leftMajor& other) const {
        return ((_cs_sold_date_sk1104 == other._cs_sold_date_sk1104));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6928432_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6928432_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_sold_date_sk1104));
    }
};
}
struct SW_JOIN_INNER_TD_6928432_payload_leftMajor {
    int32_t _cs_sold_date_sk1104;
    int32_t _cs_item_sk1119;
    int32_t _cs_quantity1122;
    int64_t _cs_list_price1124;
    int64_t _cs_sales_price1125;
    int64_t _cs_coupon_amt1131;
    int64_t _cs_net_profit1137;
    int32_t _cd_dep_count99;
    int32_t _c_birth_year13;
    std::string _ca_county61;
    std::string _ca_state62;
    std::string _ca_country64;
};
struct SW_JOIN_INNER_TD_6928432_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_6928432_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6928432_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6928432_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_6928432_payload_rightMajor {
    int32_t _d_date_sk120;
};
void SW_JOIN_INNER_TD_6928432(Table &tbl_JOIN_INNER_TD_7582503_output, Table &tbl_Filter_TD_7361265_output, Table &tbl_JOIN_INNER_TD_6928432_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_sold_date_sk#1104 = d_date_sk#120))
    // Left Table: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119, cs_quantity#1122, cs_list_price#1124, cs_sales_price#1125, cs_coupon_amt#1131, cs_net_profit#1137, cd_dep_count#99, c_birth_year#13, ca_county#61, ca_state#62, ca_country#64)
    // Right Table: ListBuffer(d_date_sk#120)
    // Output Table: ListBuffer(cs_item_sk#1119, cs_quantity#1122, cs_list_price#1124, cs_sales_price#1125, cs_coupon_amt#1131, cs_net_profit#1137, cd_dep_count#99, c_birth_year#13, ca_county#61, ca_state#62, ca_country#64)
    int left_nrow = tbl_JOIN_INNER_TD_7582503_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7361265_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6928432_key_leftMajor, SW_JOIN_INNER_TD_6928432_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7582503_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_sold_date_sk1104_k = tbl_JOIN_INNER_TD_7582503_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6928432_key_leftMajor keyA{_cs_sold_date_sk1104_k};
            int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_7582503_output.getInt32(i, 0);
            int32_t _cs_item_sk1119 = tbl_JOIN_INNER_TD_7582503_output.getInt32(i, 1);
            int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_7582503_output.getInt32(i, 2);
            int64_t _cs_list_price1124 = tbl_JOIN_INNER_TD_7582503_output.getInt64(i, 3);
            int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_7582503_output.getInt64(i, 4);
            int64_t _cs_coupon_amt1131 = tbl_JOIN_INNER_TD_7582503_output.getInt64(i, 5);
            int64_t _cs_net_profit1137 = tbl_JOIN_INNER_TD_7582503_output.getInt64(i, 6);
            int32_t _cd_dep_count99 = tbl_JOIN_INNER_TD_7582503_output.getInt32(i, 7);
            int32_t _c_birth_year13 = tbl_JOIN_INNER_TD_7582503_output.getInt32(i, 8);
            std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n = tbl_JOIN_INNER_TD_7582503_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            std::string _ca_county61 = std::string(_ca_county61_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_JOIN_INNER_TD_7582503_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            std::string _ca_state62 = std::string(_ca_state62_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_country64_n = tbl_JOIN_INNER_TD_7582503_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
            std::string _ca_country64 = std::string(_ca_country64_n.data());
            SW_JOIN_INNER_TD_6928432_payload_leftMajor payloadA{_cs_sold_date_sk1104, _cs_item_sk1119, _cs_quantity1122, _cs_list_price1124, _cs_sales_price1125, _cs_coupon_amt1131, _cs_net_profit1137, _cd_dep_count99, _c_birth_year13, _ca_county61, _ca_state62, _ca_country64};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7361265_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_7361265_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6928432_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk1104 = (it->second)._cs_sold_date_sk1104;
                int32_t _cs_item_sk1119 = (it->second)._cs_item_sk1119;
                int32_t _cs_quantity1122 = (it->second)._cs_quantity1122;
                int64_t _cs_list_price1124 = (it->second)._cs_list_price1124;
                int64_t _cs_sales_price1125 = (it->second)._cs_sales_price1125;
                int64_t _cs_coupon_amt1131 = (it->second)._cs_coupon_amt1131;
                int64_t _cs_net_profit1137 = (it->second)._cs_net_profit1137;
                int32_t _cd_dep_count99 = (it->second)._cd_dep_count99;
                int32_t _c_birth_year13 = (it->second)._c_birth_year13;
                std::string _ca_county61 = (it->second)._ca_county61;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n{};
                memcpy(_ca_county61_n.data(), (_ca_county61).data(), (_ca_county61).length());
                std::string _ca_state62 = (it->second)._ca_state62;
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n{};
                memcpy(_ca_state62_n.data(), (_ca_state62).data(), (_ca_state62).length());
                std::string _ca_country64 = (it->second)._ca_country64;
                std::array<char, TPCDS_READ_MAX + 1> _ca_country64_n{};
                memcpy(_ca_country64_n.data(), (_ca_country64).data(), (_ca_country64).length());
                int32_t _d_date_sk120 = tbl_Filter_TD_7361265_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_6928432_output.setInt32(r, 0, _cs_item_sk1119);
                tbl_JOIN_INNER_TD_6928432_output.setInt32(r, 1, _cs_quantity1122);
                tbl_JOIN_INNER_TD_6928432_output.setInt64(r, 2, _cs_list_price1124);
                tbl_JOIN_INNER_TD_6928432_output.setInt64(r, 3, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_6928432_output.setInt64(r, 4, _cs_coupon_amt1131);
                tbl_JOIN_INNER_TD_6928432_output.setInt64(r, 5, _cs_net_profit1137);
                tbl_JOIN_INNER_TD_6928432_output.setInt32(r, 6, _cd_dep_count99);
                tbl_JOIN_INNER_TD_6928432_output.setInt32(r, 7, _c_birth_year13);
                tbl_JOIN_INNER_TD_6928432_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _ca_county61_n);
                tbl_JOIN_INNER_TD_6928432_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _ca_state62_n);
                tbl_JOIN_INNER_TD_6928432_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _ca_country64_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6928432_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6928432_key_rightMajor, SW_JOIN_INNER_TD_6928432_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7361265_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_7361265_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6928432_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_7361265_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6928432_payload_rightMajor payloadA{_d_date_sk120};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7582503_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_sold_date_sk1104_k = tbl_JOIN_INNER_TD_7582503_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6928432_key_rightMajor{_cs_sold_date_sk1104_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_7582503_output.getInt32(i, 0);
                int32_t _cs_item_sk1119 = tbl_JOIN_INNER_TD_7582503_output.getInt32(i, 1);
                int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_7582503_output.getInt32(i, 2);
                int64_t _cs_list_price1124 = tbl_JOIN_INNER_TD_7582503_output.getInt64(i, 3);
                int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_7582503_output.getInt64(i, 4);
                int64_t _cs_coupon_amt1131 = tbl_JOIN_INNER_TD_7582503_output.getInt64(i, 5);
                int64_t _cs_net_profit1137 = tbl_JOIN_INNER_TD_7582503_output.getInt64(i, 6);
                int32_t _cd_dep_count99 = tbl_JOIN_INNER_TD_7582503_output.getInt32(i, 7);
                int32_t _c_birth_year13 = tbl_JOIN_INNER_TD_7582503_output.getInt32(i, 8);
                std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n = tbl_JOIN_INNER_TD_7582503_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
                std::string _ca_county61 = std::string(_ca_county61_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_JOIN_INNER_TD_7582503_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
                std::string _ca_state62 = std::string(_ca_state62_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_country64_n = tbl_JOIN_INNER_TD_7582503_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
                std::string _ca_country64 = std::string(_ca_country64_n.data());
                tbl_JOIN_INNER_TD_6928432_output.setInt32(r, 0, _cs_item_sk1119);
                tbl_JOIN_INNER_TD_6928432_output.setInt32(r, 1, _cs_quantity1122);
                tbl_JOIN_INNER_TD_6928432_output.setInt64(r, 2, _cs_list_price1124);
                tbl_JOIN_INNER_TD_6928432_output.setInt64(r, 3, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_6928432_output.setInt64(r, 4, _cs_coupon_amt1131);
                tbl_JOIN_INNER_TD_6928432_output.setInt64(r, 5, _cs_net_profit1137);
                tbl_JOIN_INNER_TD_6928432_output.setInt32(r, 6, _cd_dep_count99);
                tbl_JOIN_INNER_TD_6928432_output.setInt32(r, 7, _c_birth_year13);
                tbl_JOIN_INNER_TD_6928432_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _ca_county61_n);
                tbl_JOIN_INNER_TD_6928432_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _ca_state62_n);
                tbl_JOIN_INNER_TD_6928432_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _ca_country64_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6928432_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6928432_output #Row: " << tbl_JOIN_INNER_TD_6928432_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5741847_key_leftMajor {
    int32_t _cs_item_sk1119;
    bool operator==(const SW_JOIN_INNER_TD_5741847_key_leftMajor& other) const {
        return ((_cs_item_sk1119 == other._cs_item_sk1119));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5741847_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5741847_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_item_sk1119));
    }
};
}
struct SW_JOIN_INNER_TD_5741847_payload_leftMajor {
    int32_t _cs_item_sk1119;
    int32_t _cs_quantity1122;
    int64_t _cs_list_price1124;
    int64_t _cs_sales_price1125;
    int64_t _cs_coupon_amt1131;
    int64_t _cs_net_profit1137;
    int32_t _cd_dep_count99;
    int32_t _c_birth_year13;
    std::string _ca_county61;
    std::string _ca_state62;
    std::string _ca_country64;
};
struct SW_JOIN_INNER_TD_5741847_key_rightMajor {
    int32_t _i_item_sk228;
    bool operator==(const SW_JOIN_INNER_TD_5741847_key_rightMajor& other) const {
        return ((_i_item_sk228 == other._i_item_sk228));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5741847_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5741847_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk228));
    }
};
}
struct SW_JOIN_INNER_TD_5741847_payload_rightMajor {
    int32_t _i_item_sk228;
    std::string _i_item_id229;
};
void SW_JOIN_INNER_TD_5741847(Table &tbl_JOIN_INNER_TD_6928432_output, Table &tbl_Filter_TD_6117315_output, Table &tbl_JOIN_INNER_TD_5741847_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_item_sk#1119 = i_item_sk#228))
    // Left Table: ListBuffer(cs_item_sk#1119, cs_quantity#1122, cs_list_price#1124, cs_sales_price#1125, cs_coupon_amt#1131, cs_net_profit#1137, cd_dep_count#99, c_birth_year#13, ca_county#61, ca_state#62, ca_country#64)
    // Right Table: ListBuffer(i_item_sk#228, i_item_id#229)
    // Output Table: ListBuffer(cs_quantity#1122, cs_list_price#1124, cs_sales_price#1125, cs_coupon_amt#1131, cs_net_profit#1137, cd_dep_count#99, c_birth_year#13, i_item_id#229, ca_country#64, ca_state#62, ca_county#61)
    int left_nrow = tbl_JOIN_INNER_TD_6928432_output.getNumRow();
    int right_nrow = tbl_Filter_TD_6117315_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5741847_key_leftMajor, SW_JOIN_INNER_TD_5741847_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_6928432_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_item_sk1119_k = tbl_JOIN_INNER_TD_6928432_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5741847_key_leftMajor keyA{_cs_item_sk1119_k};
            int32_t _cs_item_sk1119 = tbl_JOIN_INNER_TD_6928432_output.getInt32(i, 0);
            int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_6928432_output.getInt32(i, 1);
            int64_t _cs_list_price1124 = tbl_JOIN_INNER_TD_6928432_output.getInt64(i, 2);
            int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_6928432_output.getInt64(i, 3);
            int64_t _cs_coupon_amt1131 = tbl_JOIN_INNER_TD_6928432_output.getInt64(i, 4);
            int64_t _cs_net_profit1137 = tbl_JOIN_INNER_TD_6928432_output.getInt64(i, 5);
            int32_t _cd_dep_count99 = tbl_JOIN_INNER_TD_6928432_output.getInt32(i, 6);
            int32_t _c_birth_year13 = tbl_JOIN_INNER_TD_6928432_output.getInt32(i, 7);
            std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n = tbl_JOIN_INNER_TD_6928432_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
            std::string _ca_county61 = std::string(_ca_county61_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_JOIN_INNER_TD_6928432_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            std::string _ca_state62 = std::string(_ca_state62_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_country64_n = tbl_JOIN_INNER_TD_6928432_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            std::string _ca_country64 = std::string(_ca_country64_n.data());
            SW_JOIN_INNER_TD_5741847_payload_leftMajor payloadA{_cs_item_sk1119, _cs_quantity1122, _cs_list_price1124, _cs_sales_price1125, _cs_coupon_amt1131, _cs_net_profit1137, _cd_dep_count99, _c_birth_year13, _ca_county61, _ca_state62, _ca_country64};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6117315_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_6117315_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5741847_key_leftMajor{_i_item_sk228_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_item_sk1119 = (it->second)._cs_item_sk1119;
                int32_t _cs_quantity1122 = (it->second)._cs_quantity1122;
                int64_t _cs_list_price1124 = (it->second)._cs_list_price1124;
                int64_t _cs_sales_price1125 = (it->second)._cs_sales_price1125;
                int64_t _cs_coupon_amt1131 = (it->second)._cs_coupon_amt1131;
                int64_t _cs_net_profit1137 = (it->second)._cs_net_profit1137;
                int32_t _cd_dep_count99 = (it->second)._cd_dep_count99;
                int32_t _c_birth_year13 = (it->second)._c_birth_year13;
                std::string _ca_county61 = (it->second)._ca_county61;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n{};
                memcpy(_ca_county61_n.data(), (_ca_county61).data(), (_ca_county61).length());
                std::string _ca_state62 = (it->second)._ca_state62;
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n{};
                memcpy(_ca_state62_n.data(), (_ca_state62).data(), (_ca_state62).length());
                std::string _ca_country64 = (it->second)._ca_country64;
                std::array<char, TPCDS_READ_MAX + 1> _ca_country64_n{};
                memcpy(_ca_country64_n.data(), (_ca_country64).data(), (_ca_country64).length());
                int32_t _i_item_sk228 = tbl_Filter_TD_6117315_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_Filter_TD_6117315_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_item_id229 = std::string(_i_item_id229_n.data());
                tbl_JOIN_INNER_TD_5741847_output.setInt32(r, 0, _cs_quantity1122);
                tbl_JOIN_INNER_TD_5741847_output.setInt64(r, 1, _cs_list_price1124);
                tbl_JOIN_INNER_TD_5741847_output.setInt64(r, 2, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_5741847_output.setInt64(r, 3, _cs_coupon_amt1131);
                tbl_JOIN_INNER_TD_5741847_output.setInt64(r, 4, _cs_net_profit1137);
                tbl_JOIN_INNER_TD_5741847_output.setInt32(r, 5, _cd_dep_count99);
                tbl_JOIN_INNER_TD_5741847_output.setInt32(r, 6, _c_birth_year13);
                tbl_JOIN_INNER_TD_5741847_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _ca_county61_n);
                tbl_JOIN_INNER_TD_5741847_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _ca_state62_n);
                tbl_JOIN_INNER_TD_5741847_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _ca_country64_n);
                tbl_JOIN_INNER_TD_5741847_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _i_item_id229_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5741847_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5741847_key_rightMajor, SW_JOIN_INNER_TD_5741847_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_6117315_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_6117315_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5741847_key_rightMajor keyA{_i_item_sk228_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_6117315_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_Filter_TD_6117315_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_item_id229 = std::string(_i_item_id229_n.data());
            SW_JOIN_INNER_TD_5741847_payload_rightMajor payloadA{_i_item_sk228, _i_item_id229};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_6928432_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_item_sk1119_k = tbl_JOIN_INNER_TD_6928432_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5741847_key_rightMajor{_cs_item_sk1119_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                std::string _i_item_id229 = (it->second)._i_item_id229;
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n{};
                memcpy(_i_item_id229_n.data(), (_i_item_id229).data(), (_i_item_id229).length());
                int32_t _cs_item_sk1119 = tbl_JOIN_INNER_TD_6928432_output.getInt32(i, 0);
                int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_6928432_output.getInt32(i, 1);
                int64_t _cs_list_price1124 = tbl_JOIN_INNER_TD_6928432_output.getInt64(i, 2);
                int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_6928432_output.getInt64(i, 3);
                int64_t _cs_coupon_amt1131 = tbl_JOIN_INNER_TD_6928432_output.getInt64(i, 4);
                int64_t _cs_net_profit1137 = tbl_JOIN_INNER_TD_6928432_output.getInt64(i, 5);
                int32_t _cd_dep_count99 = tbl_JOIN_INNER_TD_6928432_output.getInt32(i, 6);
                int32_t _c_birth_year13 = tbl_JOIN_INNER_TD_6928432_output.getInt32(i, 7);
                std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n = tbl_JOIN_INNER_TD_6928432_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
                std::string _ca_county61 = std::string(_ca_county61_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_JOIN_INNER_TD_6928432_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
                std::string _ca_state62 = std::string(_ca_state62_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_country64_n = tbl_JOIN_INNER_TD_6928432_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
                std::string _ca_country64 = std::string(_ca_country64_n.data());
                tbl_JOIN_INNER_TD_5741847_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _i_item_id229_n);
                tbl_JOIN_INNER_TD_5741847_output.setInt32(r, 0, _cs_quantity1122);
                tbl_JOIN_INNER_TD_5741847_output.setInt64(r, 1, _cs_list_price1124);
                tbl_JOIN_INNER_TD_5741847_output.setInt64(r, 2, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_5741847_output.setInt64(r, 3, _cs_coupon_amt1131);
                tbl_JOIN_INNER_TD_5741847_output.setInt64(r, 4, _cs_net_profit1137);
                tbl_JOIN_INNER_TD_5741847_output.setInt32(r, 5, _cd_dep_count99);
                tbl_JOIN_INNER_TD_5741847_output.setInt32(r, 6, _c_birth_year13);
                tbl_JOIN_INNER_TD_5741847_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _ca_county61_n);
                tbl_JOIN_INNER_TD_5741847_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _ca_state62_n);
                tbl_JOIN_INNER_TD_5741847_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _ca_country64_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5741847_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5741847_output #Row: " << tbl_JOIN_INNER_TD_5741847_output.getNumRow() << std::endl;
}

void SW_Expand_TD_4155296(Table &tbl_JOIN_INNER_TD_5741847_output, Table &tbl_Expand_TD_4155296_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Expand
    // Operation: ListBuffer(Expand)
    // Input: ListBuffer(cs_quantity#1122, cs_list_price#1124, cs_sales_price#1125, cs_coupon_amt#1131, cs_net_profit#1137, cd_dep_count#99, c_birth_year#13, i_item_id#229, ca_country#64, ca_state#62, ca_county#61)
    // Output: ListBuffer(cs_quantity#1122, cs_list_price#1124, cs_sales_price#1125, cs_coupon_amt#1131, cs_net_profit#1137, cd_dep_count#99, c_birth_year#13, i_item_id#3572, ca_country#3573, ca_state#3574, ca_county#3575, spark_grouping_id#3571L)
    std::cout << "tbl_Expand_TD_4155296_output #Row: " << tbl_Expand_TD_4155296_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_3249924_key {
    std::string _i_item_id3572;
    std::string _ca_country3573;
    std::string _ca_state3574;
    std::string _ca_county3575;
    int64_t _spark_grouping_id3571L;
    bool operator==(const SW_Aggregate_TD_3249924_key& other) const { return (_i_item_id3572 == other._i_item_id3572) && (_ca_country3573 == other._ca_country3573) && (_ca_state3574 == other._ca_state3574) && (_ca_county3575 == other._ca_county3575) && (_spark_grouping_id3571L == other._spark_grouping_id3571L); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_3249924_key> {
    std::size_t operator() (const SW_Aggregate_TD_3249924_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_item_id3572)) + (hash<string>()(k._ca_country3573)) + (hash<string>()(k._ca_state3574)) + (hash<string>()(k._ca_county3575)) + (hash<int64_t>()(k._spark_grouping_id3571L));
    }
};
}
struct SW_Aggregate_TD_3249924_payload {
    int64_t _agg13544_avg_0;
    int64_t _agg23545_avg_1;
    int64_t _agg33546_avg_2;
    int64_t _agg43547_avg_3;
    int64_t _agg53548_avg_4;
    int64_t _agg63549_avg_5;
    int64_t _agg73550_avg_6;
};
void SW_Aggregate_TD_3249924(Table &tbl_Expand_TD_4155296_output, Table &tbl_Aggregate_TD_3249924_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(i_item_id#3572, ca_country#3573, ca_state#3574, ca_county#3575, spark_grouping_id#3571L, avg(cast(cs_quantity#1122 as decimal(12,2))) AS agg1#3544, avg(cast(cs_list_price#1124 as decimal(12,2))) AS agg2#3545, avg(cast(cs_coupon_amt#1131 as decimal(12,2))) AS agg3#3546, avg(cast(cs_sales_price#1125 as decimal(12,2))) AS agg4#3547, avg(cast(cs_net_profit#1137 as decimal(12,2))) AS agg5#3548, avg(cast(c_birth_year#13 as decimal(12,2))) AS agg6#3549, avg(cast(cd_dep_count#99 as decimal(12,2))) AS agg7#3550)
    // Input: ListBuffer(cs_quantity#1122, cs_list_price#1124, cs_sales_price#1125, cs_coupon_amt#1131, cs_net_profit#1137, cd_dep_count#99, c_birth_year#13, i_item_id#3572, ca_country#3573, ca_state#3574, ca_county#3575, spark_grouping_id#3571L)
    // Output: ListBuffer(i_item_id#3572, ca_country#3573, ca_state#3574, ca_county#3575, agg1#3544, agg2#3545, agg3#3546, agg4#3547, agg5#3548, agg6#3549, agg7#3550)
    std::unordered_map<SW_Aggregate_TD_3249924_key, SW_Aggregate_TD_3249924_payload> ht1;
    int nrow1 = tbl_Expand_TD_4155296_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_quantity1122 = tbl_Expand_TD_4155296_output.getInt32(i, 0);
        int64_t _cs_list_price1124 = tbl_Expand_TD_4155296_output.getInt64(i, 1);
        int64_t _cs_sales_price1125 = tbl_Expand_TD_4155296_output.getInt64(i, 2);
        int64_t _cs_coupon_amt1131 = tbl_Expand_TD_4155296_output.getInt64(i, 3);
        int64_t _cs_net_profit1137 = tbl_Expand_TD_4155296_output.getInt64(i, 4);
        int32_t _cd_dep_count99 = tbl_Expand_TD_4155296_output.getInt32(i, 5);
        int32_t _c_birth_year13 = tbl_Expand_TD_4155296_output.getInt32(i, 6);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id3572 = tbl_Expand_TD_4155296_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
        std::array<char, TPCDS_READ_MAX + 1> _ca_country3573 = tbl_Expand_TD_4155296_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
        std::array<char, TPCDS_READ_MAX + 1> _ca_state3574 = tbl_Expand_TD_4155296_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
        std::array<char, TPCDS_READ_MAX + 1> _ca_county3575 = tbl_Expand_TD_4155296_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
        int64_t _spark_grouping_id3571L = tbl_Expand_TD_4155296_output.getInt64(i, 11);
        SW_Aggregate_TD_3249924_key k{std::string(_i_item_id3572.data()), std::string(_ca_country3573.data()), std::string(_ca_state3574.data()), std::string(_ca_county3575.data()), _spark_grouping_id3571L};
        int64_t _agg13544_avg_0 = _cs_quantity1122;
        int64_t _agg23545_avg_1 = _cs_list_price1124;
        int64_t _agg33546_avg_2 = _cs_coupon_amt1131;
        int64_t _agg43547_avg_3 = _cs_sales_price1125;
        int64_t _agg53548_avg_4 = _cs_net_profit1137;
        int64_t _agg63549_avg_5 = _c_birth_year13;
        int64_t _agg73550_avg_6 = _cd_dep_count99;
        SW_Aggregate_TD_3249924_payload p{_agg13544_avg_0, _agg23545_avg_1, _agg33546_avg_2, _agg43547_avg_3, _agg53548_avg_4, _agg63549_avg_5, _agg73550_avg_6};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t avg_0 = ((it->second)._agg13544_avg_0 + _agg13544_avg_0);
            p._agg13544_avg_0 = avg_0;
            int64_t avg_1 = ((it->second)._agg23545_avg_1 + _agg23545_avg_1);
            p._agg23545_avg_1 = avg_1;
            int64_t avg_2 = ((it->second)._agg33546_avg_2 + _agg33546_avg_2);
            p._agg33546_avg_2 = avg_2;
            int64_t avg_3 = ((it->second)._agg43547_avg_3 + _agg43547_avg_3);
            p._agg43547_avg_3 = avg_3;
            int64_t avg_4 = ((it->second)._agg53548_avg_4 + _agg53548_avg_4);
            p._agg53548_avg_4 = avg_4;
            int64_t avg_5 = ((it->second)._agg63549_avg_5 + _agg63549_avg_5);
            p._agg63549_avg_5 = avg_5;
            int64_t avg_6 = ((it->second)._agg73550_avg_6 + _agg73550_avg_6);
            p._agg73550_avg_6 = avg_6;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id3572{};
        memcpy(_i_item_id3572.data(), ((it.first)._i_item_id3572).data(), ((it.first)._i_item_id3572).length());
        tbl_Aggregate_TD_3249924_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id3572);
        std::array<char, TPCDS_READ_MAX + 1> _ca_country3573{};
        memcpy(_ca_country3573.data(), ((it.first)._ca_country3573).data(), ((it.first)._ca_country3573).length());
        tbl_Aggregate_TD_3249924_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_country3573);
        std::array<char, TPCDS_READ_MAX + 1> _ca_state3574{};
        memcpy(_ca_state3574.data(), ((it.first)._ca_state3574).data(), ((it.first)._ca_state3574).length());
        tbl_Aggregate_TD_3249924_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_state3574);
        std::array<char, TPCDS_READ_MAX + 1> _ca_county3575{};
        memcpy(_ca_county3575.data(), ((it.first)._ca_county3575).data(), ((it.first)._ca_county3575).length());
        tbl_Aggregate_TD_3249924_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_county3575);
        // _spark_grouping_id3571L not required in the output table
        int64_t _agg13544 = (it.second)._agg13544_avg_0 / nrow1;
        tbl_Aggregate_TD_3249924_output.setInt64(r, 4, _agg13544);
        int64_t _agg23545 = (it.second)._agg23545_avg_1 / nrow1;
        tbl_Aggregate_TD_3249924_output.setInt64(r, 5, _agg23545);
        int64_t _agg33546 = (it.second)._agg33546_avg_2 / nrow1;
        tbl_Aggregate_TD_3249924_output.setInt64(r, 6, _agg33546);
        int64_t _agg43547 = (it.second)._agg43547_avg_3 / nrow1;
        tbl_Aggregate_TD_3249924_output.setInt64(r, 7, _agg43547);
        int64_t _agg53548 = (it.second)._agg53548_avg_4 / nrow1;
        tbl_Aggregate_TD_3249924_output.setInt64(r, 8, _agg53548);
        int64_t _agg63549 = (it.second)._agg63549_avg_5 / nrow1;
        tbl_Aggregate_TD_3249924_output.setInt64(r, 9, _agg63549);
        int64_t _agg73550 = (it.second)._agg73550_avg_6 / nrow1;
        tbl_Aggregate_TD_3249924_output.setInt64(r, 10, _agg73550);
        ++r;
    }
    tbl_Aggregate_TD_3249924_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_3249924_output #Row: " << tbl_Aggregate_TD_3249924_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2700404(Table &tbl_Aggregate_TD_3249924_output, Table &tbl_Sort_TD_2700404_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(ca_country#3573 ASC NULLS FIRST, ca_state#3574 ASC NULLS FIRST, ca_county#3575 ASC NULLS FIRST, i_item_id#3572 ASC NULLS FIRST)
    // Input: ListBuffer(i_item_id#3572, ca_country#3573, ca_state#3574, ca_county#3575, agg1#3544, agg2#3545, agg3#3546, agg4#3547, agg5#3548, agg6#3549, agg7#3550)
    // Output: ListBuffer(i_item_id#3572, ca_country#3573, ca_state#3574, ca_county#3575, agg1#3544, agg2#3545, agg3#3546, agg4#3547, agg5#3548, agg6#3549, agg7#3550)
    struct SW_Sort_TD_2700404Row {
        std::string _i_item_id3572;
        std::string _ca_country3573;
        std::string _ca_state3574;
        std::string _ca_county3575;
        int64_t _agg13544;
        int64_t _agg23545;
        int64_t _agg33546;
        int64_t _agg43547;
        int64_t _agg53548;
        int64_t _agg63549;
        int64_t _agg73550;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2700404Row& a, const SW_Sort_TD_2700404Row& b) const { return 
 (a._ca_country3573 < b._ca_country3573) || 
 ((a._ca_country3573 == b._ca_country3573) && (a._ca_state3574 < b._ca_state3574)) || 
 ((a._ca_country3573 == b._ca_country3573) && (a._ca_state3574 == b._ca_state3574) && (a._ca_county3575 < b._ca_county3575)) || 
 ((a._ca_country3573 == b._ca_country3573) && (a._ca_state3574 == b._ca_state3574) && (a._ca_county3575 == b._ca_county3575) && (a._i_item_id3572 < b._i_item_id3572)); 
}
    }SW_Sort_TD_2700404_order; 

    int nrow1 = tbl_Aggregate_TD_3249924_output.getNumRow();
    std::vector<SW_Sort_TD_2700404Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id3572 = tbl_Aggregate_TD_3249924_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _ca_country3573 = tbl_Aggregate_TD_3249924_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _ca_state3574 = tbl_Aggregate_TD_3249924_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _ca_county3575 = tbl_Aggregate_TD_3249924_output.getcharN<char, TPCDS_READ_MAX +1>(i, 3);
        int64_t _agg13544 = tbl_Aggregate_TD_3249924_output.getInt64(i, 4);
        int64_t _agg23545 = tbl_Aggregate_TD_3249924_output.getInt64(i, 5);
        int64_t _agg33546 = tbl_Aggregate_TD_3249924_output.getInt64(i, 6);
        int64_t _agg43547 = tbl_Aggregate_TD_3249924_output.getInt64(i, 7);
        int64_t _agg53548 = tbl_Aggregate_TD_3249924_output.getInt64(i, 8);
        int64_t _agg63549 = tbl_Aggregate_TD_3249924_output.getInt64(i, 9);
        int64_t _agg73550 = tbl_Aggregate_TD_3249924_output.getInt64(i, 10);
        SW_Sort_TD_2700404Row t = {std::string(_i_item_id3572.data()),std::string(_ca_country3573.data()),std::string(_ca_state3574.data()),std::string(_ca_county3575.data()),_agg13544,_agg23545,_agg33546,_agg43547,_agg53548,_agg63549,_agg73550};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2700404_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id3572{};
        memcpy(_i_item_id3572.data(), (it._i_item_id3572).data(), (it._i_item_id3572).length());
        tbl_Sort_TD_2700404_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _i_item_id3572);
        std::array<char, TPCDS_READ_MAX + 1> _ca_country3573{};
        memcpy(_ca_country3573.data(), (it._ca_country3573).data(), (it._ca_country3573).length());
        tbl_Sort_TD_2700404_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _ca_country3573);
        std::array<char, TPCDS_READ_MAX + 1> _ca_state3574{};
        memcpy(_ca_state3574.data(), (it._ca_state3574).data(), (it._ca_state3574).length());
        tbl_Sort_TD_2700404_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _ca_state3574);
        std::array<char, TPCDS_READ_MAX + 1> _ca_county3575{};
        memcpy(_ca_county3575.data(), (it._ca_county3575).data(), (it._ca_county3575).length());
        tbl_Sort_TD_2700404_output.setcharN<char, TPCDS_READ_MAX +1>(r, 3, _ca_county3575);
        tbl_Sort_TD_2700404_output.setInt64(r, 4, it._agg13544);
        tbl_Sort_TD_2700404_output.setInt64(r, 5, it._agg23545);
        tbl_Sort_TD_2700404_output.setInt64(r, 6, it._agg33546);
        tbl_Sort_TD_2700404_output.setInt64(r, 7, it._agg43547);
        tbl_Sort_TD_2700404_output.setInt64(r, 8, it._agg53548);
        tbl_Sort_TD_2700404_output.setInt64(r, 9, it._agg63549);
        tbl_Sort_TD_2700404_output.setInt64(r, 10, it._agg73550);
        ++r;
    }
    tbl_Sort_TD_2700404_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2700404_output #Row: " << tbl_Sort_TD_2700404_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1416138(Table &tbl_Sort_TD_2700404_output, Table &tbl_LocalLimit_TD_1416138_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(i_item_id#3572, ca_country#3573, ca_state#3574, ca_county#3575, agg1#3544, agg2#3545, agg3#3546, agg4#3547, agg5#3548, agg6#3549, agg7#3550)
    // Output: ListBuffer(i_item_id#3572, ca_country#3573, ca_state#3574, ca_county#3575, agg1#3544, agg2#3545, agg3#3546, agg4#3547, agg5#3548, agg6#3549, agg7#3550)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id3572_n = tbl_Sort_TD_2700404_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1416138_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id3572_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_country3573_n = tbl_Sort_TD_2700404_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_1416138_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_country3573_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_state3574_n = tbl_Sort_TD_2700404_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_LocalLimit_TD_1416138_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_state3574_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_county3575_n = tbl_Sort_TD_2700404_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_LocalLimit_TD_1416138_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_county3575_n);
        tbl_LocalLimit_TD_1416138_output.setInt64(r, 4, tbl_Sort_TD_2700404_output.getInt64(i, 4));
        tbl_LocalLimit_TD_1416138_output.setInt64(r, 5, tbl_Sort_TD_2700404_output.getInt64(i, 5));
        tbl_LocalLimit_TD_1416138_output.setInt64(r, 6, tbl_Sort_TD_2700404_output.getInt64(i, 6));
        tbl_LocalLimit_TD_1416138_output.setInt64(r, 7, tbl_Sort_TD_2700404_output.getInt64(i, 7));
        tbl_LocalLimit_TD_1416138_output.setInt64(r, 8, tbl_Sort_TD_2700404_output.getInt64(i, 8));
        tbl_LocalLimit_TD_1416138_output.setInt64(r, 9, tbl_Sort_TD_2700404_output.getInt64(i, 9));
        tbl_LocalLimit_TD_1416138_output.setInt64(r, 10, tbl_Sort_TD_2700404_output.getInt64(i, 10));
        r++;
    }
    tbl_LocalLimit_TD_1416138_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1416138_output #Row: " << tbl_LocalLimit_TD_1416138_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_031669(Table &tbl_LocalLimit_TD_1416138_output, Table &tbl_GlobalLimit_TD_031669_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(i_item_id#3572, ca_country#3573, ca_state#3574, ca_county#3575, agg1#3544, agg2#3545, agg3#3546, agg4#3547, agg5#3548, agg6#3549, agg7#3550)
    // Output: ListBuffer(i_item_id#3572, ca_country#3573, ca_state#3574, ca_county#3575, agg1#3544, agg2#3545, agg3#3546, agg4#3547, agg5#3548, agg6#3549, agg7#3550)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id3572_n = tbl_LocalLimit_TD_1416138_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_031669_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id3572_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_country3573_n = tbl_LocalLimit_TD_1416138_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_031669_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_country3573_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_state3574_n = tbl_LocalLimit_TD_1416138_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_GlobalLimit_TD_031669_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_state3574_n);
        std::array<char, TPCDS_READ_MAX + 1> _ca_county3575_n = tbl_LocalLimit_TD_1416138_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_GlobalLimit_TD_031669_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_county3575_n);
        tbl_GlobalLimit_TD_031669_output.setInt64(r, 4, tbl_LocalLimit_TD_1416138_output.getInt64(i, 4));
        tbl_GlobalLimit_TD_031669_output.setInt64(r, 5, tbl_LocalLimit_TD_1416138_output.getInt64(i, 5));
        tbl_GlobalLimit_TD_031669_output.setInt64(r, 6, tbl_LocalLimit_TD_1416138_output.getInt64(i, 6));
        tbl_GlobalLimit_TD_031669_output.setInt64(r, 7, tbl_LocalLimit_TD_1416138_output.getInt64(i, 7));
        tbl_GlobalLimit_TD_031669_output.setInt64(r, 8, tbl_LocalLimit_TD_1416138_output.getInt64(i, 8));
        tbl_GlobalLimit_TD_031669_output.setInt64(r, 9, tbl_LocalLimit_TD_1416138_output.getInt64(i, 9));
        tbl_GlobalLimit_TD_031669_output.setInt64(r, 10, tbl_LocalLimit_TD_1416138_output.getInt64(i, 10));
        r++;
    }
    tbl_GlobalLimit_TD_031669_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_031669_output #Row: " << tbl_GlobalLimit_TD_031669_output.getNumRow() << std::endl;
}

