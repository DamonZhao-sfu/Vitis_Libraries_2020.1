#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_446761(Table &tbl_SerializeFromObject_TD_5917850_input, Table &tbl_Filter_TD_446761_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_month_seq#3733) AND ((d_month_seq#3733 >= 1200) AND (d_month_seq#3733 <= 1211))) AND isnotnull(d_date_sk#3730)))
    // Input: ListBuffer(d_date_sk#3730, d_month_seq#3733)
    // Output: ListBuffer(d_date_sk#3730)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5917850_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_month_seq3733 = tbl_SerializeFromObject_TD_5917850_input.getInt32(i, 1);
        int32_t _d_date_sk3730 = tbl_SerializeFromObject_TD_5917850_input.getInt32(i, 0);
        if (((_d_month_seq3733!= 0) && ((_d_month_seq3733 >= 1200) && (_d_month_seq3733 <= 1211))) && (_d_date_sk3730!= 0)) {
            int32_t _d_date_sk3730_t = tbl_SerializeFromObject_TD_5917850_input.getInt32(i, 0);
            tbl_Filter_TD_446761_output.setInt32(r, 0, _d_date_sk3730_t);
            r++;
        }
    }
    tbl_Filter_TD_446761_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_446761_output #Row: " << tbl_Filter_TD_446761_output.getNumRow() << std::endl;
}

void SW_Filter_TD_4420490(Table &tbl_SerializeFromObject_TD_5317840_input, Table &tbl_Filter_TD_4420490_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(cs_sold_date_sk#1104))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_item_sk#1119)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_item_sk#1119)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5317840_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_5317840_input.getInt32(i, 0);
        if (_cs_sold_date_sk1104!= 0) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_5317840_input.getInt32(i, 0);
            tbl_Filter_TD_4420490_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int32_t _cs_bill_customer_sk1107_t = tbl_SerializeFromObject_TD_5317840_input.getInt32(i, 1);
            tbl_Filter_TD_4420490_output.setInt32(r, 1, _cs_bill_customer_sk1107_t);
            int32_t _cs_item_sk1119_t = tbl_SerializeFromObject_TD_5317840_input.getInt32(i, 2);
            tbl_Filter_TD_4420490_output.setInt32(r, 2, _cs_item_sk1119_t);
            r++;
        }
    }
    tbl_Filter_TD_4420490_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4420490_output #Row: " << tbl_Filter_TD_4420490_output.getNumRow() << std::endl;
}

void SW_Filter_TD_4752553(Table &tbl_SerializeFromObject_TD_5180935_input, Table &tbl_Filter_TD_4752553_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_month_seq#123) AND ((d_month_seq#123 >= 1200) AND (d_month_seq#123 <= 1211))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_month_seq#123)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5180935_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_month_seq123 = tbl_SerializeFromObject_TD_5180935_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_5180935_input.getInt32(i, 0);
        if (((_d_month_seq123!= 0) && ((_d_month_seq123 >= 1200) && (_d_month_seq123 <= 1211))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_5180935_input.getInt32(i, 0);
            tbl_Filter_TD_4752553_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_4752553_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4752553_output #Row: " << tbl_Filter_TD_4752553_output.getNumRow() << std::endl;
}

void SW_Filter_TD_4866947(Table &tbl_SerializeFromObject_TD_5101142_input, Table &tbl_Filter_TD_4866947_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ss_sold_date_sk#1206))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5101142_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_5101142_input.getInt32(i, 0);
        if (_ss_sold_date_sk1206!= 0) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_5101142_input.getInt32(i, 0);
            tbl_Filter_TD_4866947_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_5101142_input.getInt32(i, 1);
            tbl_Filter_TD_4866947_output.setInt32(r, 1, _ss_item_sk1208_t);
            int32_t _ss_customer_sk1209_t = tbl_SerializeFromObject_TD_5101142_input.getInt32(i, 2);
            tbl_Filter_TD_4866947_output.setInt32(r, 2, _ss_customer_sk1209_t);
            r++;
        }
    }
    tbl_Filter_TD_4866947_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4866947_output #Row: " << tbl_Filter_TD_4866947_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_3222611_key_leftMajor {
    int32_t _cs_sold_date_sk1104;
    bool operator==(const SW_JOIN_INNER_TD_3222611_key_leftMajor& other) const {
        return ((_cs_sold_date_sk1104 == other._cs_sold_date_sk1104));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3222611_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3222611_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_sold_date_sk1104));
    }
};
}
struct SW_JOIN_INNER_TD_3222611_payload_leftMajor {
    int32_t _cs_sold_date_sk1104;
    int32_t _cs_bill_customer_sk1107;
    int32_t _cs_item_sk1119;
};
struct SW_JOIN_INNER_TD_3222611_key_rightMajor {
    int32_t _d_date_sk3730;
    bool operator==(const SW_JOIN_INNER_TD_3222611_key_rightMajor& other) const {
        return ((_d_date_sk3730 == other._d_date_sk3730));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3222611_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3222611_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk3730));
    }
};
}
struct SW_JOIN_INNER_TD_3222611_payload_rightMajor {
    int32_t _d_date_sk3730;
};
void SW_JOIN_INNER_TD_3222611(Table &tbl_Filter_TD_4420490_output, Table &tbl_Filter_TD_446761_output, Table &tbl_JOIN_INNER_TD_3222611_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_sold_date_sk#1104 = d_date_sk#3730))
    // Left Table: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_item_sk#1119)
    // Right Table: ListBuffer(d_date_sk#3730)
    // Output Table: ListBuffer(cs_bill_customer_sk#1107, cs_item_sk#1119)
    int left_nrow = tbl_Filter_TD_4420490_output.getNumRow();
    int right_nrow = tbl_Filter_TD_446761_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3222611_key_leftMajor, SW_JOIN_INNER_TD_3222611_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_4420490_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_sold_date_sk1104_k = tbl_Filter_TD_4420490_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3222611_key_leftMajor keyA{_cs_sold_date_sk1104_k};
            int32_t _cs_sold_date_sk1104 = tbl_Filter_TD_4420490_output.getInt32(i, 0);
            int32_t _cs_bill_customer_sk1107 = tbl_Filter_TD_4420490_output.getInt32(i, 1);
            int32_t _cs_item_sk1119 = tbl_Filter_TD_4420490_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_3222611_payload_leftMajor payloadA{_cs_sold_date_sk1104, _cs_bill_customer_sk1107, _cs_item_sk1119};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_446761_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk3730_k = tbl_Filter_TD_446761_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3222611_key_leftMajor{_d_date_sk3730_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk1104 = (it->second)._cs_sold_date_sk1104;
                int32_t _cs_bill_customer_sk1107 = (it->second)._cs_bill_customer_sk1107;
                int32_t _cs_item_sk1119 = (it->second)._cs_item_sk1119;
                int32_t _d_date_sk3730 = tbl_Filter_TD_446761_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_3222611_output.setInt32(r, 0, _cs_bill_customer_sk1107);
                tbl_JOIN_INNER_TD_3222611_output.setInt32(r, 1, _cs_item_sk1119);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3222611_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3222611_key_rightMajor, SW_JOIN_INNER_TD_3222611_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_446761_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk3730_k = tbl_Filter_TD_446761_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3222611_key_rightMajor keyA{_d_date_sk3730_k};
            int32_t _d_date_sk3730 = tbl_Filter_TD_446761_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3222611_payload_rightMajor payloadA{_d_date_sk3730};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_4420490_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_sold_date_sk1104_k = tbl_Filter_TD_4420490_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3222611_key_rightMajor{_cs_sold_date_sk1104_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk3730 = (it->second)._d_date_sk3730;
                int32_t _cs_sold_date_sk1104 = tbl_Filter_TD_4420490_output.getInt32(i, 0);
                int32_t _cs_bill_customer_sk1107 = tbl_Filter_TD_4420490_output.getInt32(i, 1);
                int32_t _cs_item_sk1119 = tbl_Filter_TD_4420490_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_3222611_output.setInt32(r, 0, _cs_bill_customer_sk1107);
                tbl_JOIN_INNER_TD_3222611_output.setInt32(r, 1, _cs_item_sk1119);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3222611_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_3222611_output #Row: " << tbl_JOIN_INNER_TD_3222611_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_3179392_key_leftMajor {
    int32_t _ss_sold_date_sk1206;
    bool operator==(const SW_JOIN_INNER_TD_3179392_key_leftMajor& other) const {
        return ((_ss_sold_date_sk1206 == other._ss_sold_date_sk1206));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3179392_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3179392_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_sold_date_sk1206));
    }
};
}
struct SW_JOIN_INNER_TD_3179392_payload_leftMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_item_sk1208;
    int32_t _ss_customer_sk1209;
};
struct SW_JOIN_INNER_TD_3179392_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_3179392_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3179392_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3179392_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_3179392_payload_rightMajor {
    int32_t _d_date_sk120;
};
void SW_JOIN_INNER_TD_3179392(Table &tbl_Filter_TD_4866947_output, Table &tbl_Filter_TD_4752553_output, Table &tbl_JOIN_INNER_TD_3179392_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#1206 = d_date_sk#120))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209)
    // Right Table: ListBuffer(d_date_sk#120)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_customer_sk#1209)
    int left_nrow = tbl_Filter_TD_4866947_output.getNumRow();
    int right_nrow = tbl_Filter_TD_4752553_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3179392_key_leftMajor, SW_JOIN_INNER_TD_3179392_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_4866947_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_Filter_TD_4866947_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3179392_key_leftMajor keyA{_ss_sold_date_sk1206_k};
            int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_4866947_output.getInt32(i, 0);
            int32_t _ss_item_sk1208 = tbl_Filter_TD_4866947_output.getInt32(i, 1);
            int32_t _ss_customer_sk1209 = tbl_Filter_TD_4866947_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_3179392_payload_leftMajor payloadA{_ss_sold_date_sk1206, _ss_item_sk1208, _ss_customer_sk1209};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_4752553_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_4752553_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3179392_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                int32_t _d_date_sk120 = tbl_Filter_TD_4752553_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_3179392_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_3179392_output.setInt32(r, 1, _ss_customer_sk1209);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3179392_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3179392_key_rightMajor, SW_JOIN_INNER_TD_3179392_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_4752553_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_4752553_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3179392_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_4752553_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3179392_payload_rightMajor payloadA{_d_date_sk120};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_4866947_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_Filter_TD_4866947_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3179392_key_rightMajor{_ss_sold_date_sk1206_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_4866947_output.getInt32(i, 0);
                int32_t _ss_item_sk1208 = tbl_Filter_TD_4866947_output.getInt32(i, 1);
                int32_t _ss_customer_sk1209 = tbl_Filter_TD_4866947_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_3179392_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_3179392_output.setInt32(r, 1, _ss_customer_sk1209);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3179392_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_3179392_output #Row: " << tbl_JOIN_INNER_TD_3179392_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_2546754_key {
    int32_t _cs_bill_customer_sk1107;
    int32_t _cs_item_sk1119;
    bool operator==(const SW_Aggregate_TD_2546754_key& other) const { return (_cs_bill_customer_sk1107 == other._cs_bill_customer_sk1107) && (_cs_item_sk1119 == other._cs_item_sk1119); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_2546754_key> {
    std::size_t operator() (const SW_Aggregate_TD_2546754_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_bill_customer_sk1107)) + (hash<int32_t>()(k._cs_item_sk1119));
    }
};
}
struct SW_Aggregate_TD_2546754_payload {
    int32_t _customer_sk3728;
    int32_t _item_sk3729;
};
void SW_Aggregate_TD_2546754(Table &tbl_JOIN_INNER_TD_3222611_output, Table &tbl_Aggregate_TD_2546754_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(cs_bill_customer_sk#1107, cs_item_sk#1119, cs_bill_customer_sk#1107 AS customer_sk#3728, cs_item_sk#1119 AS item_sk#3729)
    // Input: ListBuffer(cs_bill_customer_sk#1107, cs_item_sk#1119)
    // Output: ListBuffer(customer_sk#3728, item_sk#3729)
    std::unordered_map<SW_Aggregate_TD_2546754_key, SW_Aggregate_TD_2546754_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_3222611_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_bill_customer_sk1107 = tbl_JOIN_INNER_TD_3222611_output.getInt32(i, 0);
        int32_t _cs_item_sk1119 = tbl_JOIN_INNER_TD_3222611_output.getInt32(i, 1);
        SW_Aggregate_TD_2546754_key k{_cs_bill_customer_sk1107, _cs_item_sk1119};
        int32_t _customer_sk3728 = _cs_bill_customer_sk1107;
        int32_t _item_sk3729 = _cs_item_sk1119;
        SW_Aggregate_TD_2546754_payload p{_customer_sk3728, _item_sk3729};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _cs_bill_customer_sk1107 not required in the output table
        // _cs_item_sk1119 not required in the output table
        tbl_Aggregate_TD_2546754_output.setInt32(r, 0, (it.second)._customer_sk3728);
        tbl_Aggregate_TD_2546754_output.setInt32(r, 1, (it.second)._item_sk3729);
        ++r;
    }
    tbl_Aggregate_TD_2546754_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_2546754_output #Row: " << tbl_Aggregate_TD_2546754_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_2677304_key {
    int32_t _ss_customer_sk1209;
    int32_t _ss_item_sk1208;
    bool operator==(const SW_Aggregate_TD_2677304_key& other) const { return (_ss_customer_sk1209 == other._ss_customer_sk1209) && (_ss_item_sk1208 == other._ss_item_sk1208); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_2677304_key> {
    std::size_t operator() (const SW_Aggregate_TD_2677304_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_customer_sk1209)) + (hash<int32_t>()(k._ss_item_sk1208));
    }
};
}
struct SW_Aggregate_TD_2677304_payload {
    int32_t _customer_sk3726;
    int32_t _item_sk3727;
};
void SW_Aggregate_TD_2677304(Table &tbl_JOIN_INNER_TD_3179392_output, Table &tbl_Aggregate_TD_2677304_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(ss_customer_sk#1209, ss_item_sk#1208, ss_customer_sk#1209 AS customer_sk#3726, ss_item_sk#1208 AS item_sk#3727)
    // Input: ListBuffer(ss_item_sk#1208, ss_customer_sk#1209)
    // Output: ListBuffer(customer_sk#3726, item_sk#3727)
    std::unordered_map<SW_Aggregate_TD_2677304_key, SW_Aggregate_TD_2677304_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_3179392_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_3179392_output.getInt32(i, 0);
        int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_3179392_output.getInt32(i, 1);
        SW_Aggregate_TD_2677304_key k{_ss_customer_sk1209, _ss_item_sk1208};
        int32_t _customer_sk3726 = _ss_customer_sk1209;
        int32_t _item_sk3727 = _ss_item_sk1208;
        SW_Aggregate_TD_2677304_payload p{_customer_sk3726, _item_sk3727};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _ss_customer_sk1209 not required in the output table
        // _ss_item_sk1208 not required in the output table
        tbl_Aggregate_TD_2677304_output.setInt32(r, 0, (it.second)._customer_sk3726);
        tbl_Aggregate_TD_2677304_output.setInt32(r, 1, (it.second)._item_sk3727);
        ++r;
    }
    tbl_Aggregate_TD_2677304_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_2677304_output #Row: " << tbl_Aggregate_TD_2677304_output.getNumRow() << std::endl;
}

struct SW_JOIN_FULLOUTER_TD_1314734_key {
    int32_t _customer_sk3728;
    int32_t _item_sk3729;
    bool operator==(const SW_JOIN_FULLOUTER_TD_1314734_key& other) const {
        return ((_customer_sk3728 == other._customer_sk3728) && (_item_sk3729 == other._item_sk3729));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_FULLOUTER_TD_1314734_key> {
    std::size_t operator() (const SW_JOIN_FULLOUTER_TD_1314734_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._customer_sk3728)) + (hash<int32_t>()(k._item_sk3729));
    }
};
}
struct SW_JOIN_FULLOUTER_TD_1314734_payload {
    int32_t _customer_sk3728;
    int32_t _item_sk3729;
};
void SW_JOIN_FULLOUTER_TD_1314734(Table &tbl_Aggregate_TD_2677304_output, Table &tbl_Aggregate_TD_2546754_output, Table &tbl_JOIN_FULLOUTER_TD_1314734_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_FULLOUTER
    // Operation: ListBuffer(((customer_sk#3726 = customer_sk#3728) AND (item_sk#3727 = item_sk#3729)))
    // Left Table: ListBuffer(customer_sk#3726, item_sk#3727)
    // Right Table: ListBuffer(customer_sk#3728, item_sk#3729)
    // Output Table: ListBuffer(customer_sk#3726, customer_sk#3728)
    std::unordered_multimap<SW_JOIN_FULLOUTER_TD_1314734_key, SW_JOIN_FULLOUTER_TD_1314734_payload> ht1;
    std::unordered_map<SW_JOIN_FULLOUTER_TD_1314734_key, bool> matched;
    int nrow1 = tbl_Aggregate_TD_2546754_output.getNumRow();
    int nrow2 = tbl_Aggregate_TD_2677304_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _customer_sk3728_k = tbl_Aggregate_TD_2546754_output.getInt32(i, 0);
        int32_t _item_sk3729_k = tbl_Aggregate_TD_2546754_output.getInt32(i, 1);
        SW_JOIN_FULLOUTER_TD_1314734_key keyA{_customer_sk3728_k, _item_sk3729_k};
        int32_t _customer_sk3728 = tbl_Aggregate_TD_2546754_output.getInt32(i, 0);
        int32_t _item_sk3729 = tbl_Aggregate_TD_2546754_output.getInt32(i, 1);
        SW_JOIN_FULLOUTER_TD_1314734_payload payloadA{_customer_sk3728, _item_sk3729};
        ht1.insert(std::make_pair(keyA, payloadA));
    }
    int r = 0;
    for (int i = 0; i < nrow2; i++) {
        int32_t _customer_sk3726_k = tbl_Aggregate_TD_2677304_output.getInt32(i, 0);
        int32_t _item_sk3727_k = tbl_Aggregate_TD_2677304_output.getInt32(i, 1);
        SW_JOIN_FULLOUTER_TD_1314734_key key {_customer_sk3726_k, _item_sk3727_k};
        auto it = ht1.find(key);
        int32_t _customer_sk3726 = tbl_Aggregate_TD_2677304_output.getInt32(i, 0);
        int32_t _item_sk3727 = tbl_Aggregate_TD_2677304_output.getInt32(i, 1);
        if (it != ht1.end()) {
            auto its = ht1.equal_range(key);
            auto it_it = its.first;
            while (it_it != its.second) {
                int32_t _customer_sk3728 = (it_it->second)._customer_sk3728;
                int32_t _item_sk3729 = (it_it->second)._item_sk3729;
                tbl_JOIN_FULLOUTER_TD_1314734_output.setInt32(r, 1, _customer_sk3728);
                tbl_JOIN_FULLOUTER_TD_1314734_output.setInt32(r, 0, _customer_sk3726);
                it_it++;
                r++;
            }
            matched[key] = true;
        } else {
            tbl_JOIN_FULLOUTER_TD_1314734_output.setInt32(r, 0, _customer_sk3726);
            r++;
        }
    }
    for (const auto& kv : ht1) {
        if (!matched[kv.first]) {
            tbl_JOIN_FULLOUTER_TD_1314734_output.setInt32(r, 1, kv.second._customer_sk3728);
            r++;
        }
    }
    tbl_JOIN_FULLOUTER_TD_1314734_output.setNumRow(r);
    std::cout << "tbl_JOIN_FULLOUTER_TD_1314734_output #Row: " << tbl_JOIN_FULLOUTER_TD_1314734_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_0758201(Table &tbl_JOIN_FULLOUTER_TD_1314734_output, Table &tbl_Aggregate_TD_0758201_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(sum(CASE WHEN (isnotnull(customer_sk#3726) AND isnull(customer_sk#3728)) THEN 1 ELSE 0 END) AS store_only#3723L, sum(CASE WHEN (isnull(customer_sk#3726) AND isnotnull(customer_sk#3728)) THEN 1 ELSE 0 END) AS catalog_only#3724L, sum(CASE WHEN (isnotnull(customer_sk#3726) AND isnotnull(customer_sk#3728)) THEN 1 ELSE 0 END) AS store_and_catalog#3725L)
    // Input: ListBuffer(customer_sk#3726, customer_sk#3728)
    // Output: ListBuffer(store_only#3723L, catalog_only#3724L, store_and_catalog#3725L)
    int64_t sum_0 = 0;
    int64_t sum_1 = 0;
    int64_t sum_2 = 0;
    int nrow1 = tbl_JOIN_FULLOUTER_TD_1314734_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _customer_sk3726 = tbl_JOIN_FULLOUTER_TD_1314734_output.getInt32(i, 0);
        int32_t _customer_sk3728 = tbl_JOIN_FULLOUTER_TD_1314734_output.getInt32(i, 1);
        int64_t _store_only3723L_sum_0 = (_customer_sk3726 && _customer_sk3728) ? 1 : 0;
        int64_t _catalog_only3724L_sum_1 = (_customer_sk3726 && _customer_sk3728) ? 1 : 0;
        int64_t _store_and_catalog3725L_sum_2 = (_customer_sk3726 && _customer_sk3728) ? 1 : 0;
        sum_0 += _store_only3723L_sum_0;
        sum_1 += _catalog_only3724L_sum_1;
        sum_2 += _store_and_catalog3725L_sum_2;
    }
    int r = 0;
    int64_t _store_only3723L = sum_0;
    tbl_Aggregate_TD_0758201_output.setInt64(r++, 0, _store_only3723L);
    int64_t _catalog_only3724L = sum_1;
    tbl_Aggregate_TD_0758201_output.setInt64(r++, 1, _catalog_only3724L);
    int64_t _store_and_catalog3725L = sum_2;
    tbl_Aggregate_TD_0758201_output.setInt64(r++, 2, _store_and_catalog3725L);
    tbl_Aggregate_TD_0758201_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_0758201_output #Row: " << tbl_Aggregate_TD_0758201_output.getNumRow() << std::endl;
}

