#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_7369543(Table &tbl_SerializeFromObject_TD_8813871_input, Table &tbl_Filter_TD_7369543_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_moy#3968) AND isnotnull(d_year#3966)) AND ((d_moy#3968 = 11) AND (d_year#3966 = 1999))) AND isnotnull(d_date_sk#3960)))
    // Input: ListBuffer(d_date_sk#3960, d_moy#3968, d_year#3966)
    // Output: ListBuffer(d_date_sk#3960)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8813871_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_moy3968 = tbl_SerializeFromObject_TD_8813871_input.getInt32(i, 1);
        int32_t _d_year3966 = tbl_SerializeFromObject_TD_8813871_input.getInt32(i, 2);
        int32_t _d_date_sk3960 = tbl_SerializeFromObject_TD_8813871_input.getInt32(i, 0);
        if ((((_d_moy3968!= 0) && (_d_year3966!= 0)) && ((_d_moy3968 == 11) && (_d_year3966 == 1999))) && (_d_date_sk3960!= 0)) {
            int32_t _d_date_sk3960_t = tbl_SerializeFromObject_TD_8813871_input.getInt32(i, 0);
            tbl_Filter_TD_7369543_output.setInt32(r, 0, _d_date_sk3960_t);
            r++;
        }
    }
    tbl_Filter_TD_7369543_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7369543_output #Row: " << tbl_Filter_TD_7369543_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7416657(Table &tbl_SerializeFromObject_TD_8556038_input, Table &tbl_Filter_TD_7416657_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_sold_date_sk#1206) AND (isnotnull(ss_item_sk#1208) AND isnotnull(ss_sold_time_sk#1207))))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_sold_time_sk#1207, ss_item_sk#1208, ss_ext_sales_price#1221)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_sold_time_sk#1207, ss_item_sk#1208, ss_ext_sales_price#1221)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8556038_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_8556038_input.getInt32(i, 0);
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_8556038_input.getInt32(i, 2);
        int32_t _ss_sold_time_sk1207 = tbl_SerializeFromObject_TD_8556038_input.getInt32(i, 1);
        if ((_ss_sold_date_sk1206!= 0) && ((_ss_item_sk1208!= 0) && (_ss_sold_time_sk1207!= 0))) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_8556038_input.getInt32(i, 0);
            tbl_Filter_TD_7416657_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_sold_time_sk1207_t = tbl_SerializeFromObject_TD_8556038_input.getInt32(i, 1);
            tbl_Filter_TD_7416657_output.setInt32(r, 1, _ss_sold_time_sk1207_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_8556038_input.getInt32(i, 2);
            tbl_Filter_TD_7416657_output.setInt32(r, 2, _ss_item_sk1208_t);
            int64_t _ss_ext_sales_price1221_t = tbl_SerializeFromObject_TD_8556038_input.getInt64(i, 3);
            tbl_Filter_TD_7416657_output.setInt64(r, 3, _ss_ext_sales_price1221_t);
            r++;
        }
    }
    tbl_Filter_TD_7416657_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7416657_output #Row: " << tbl_Filter_TD_7416657_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7697127(Table &tbl_SerializeFromObject_TD_8620034_input, Table &tbl_Filter_TD_7697127_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_moy#3940) AND isnotnull(d_year#3938)) AND ((d_moy#3940 = 11) AND (d_year#3938 = 1999))) AND isnotnull(d_date_sk#3932)))
    // Input: ListBuffer(d_date_sk#3932, d_moy#3940, d_year#3938)
    // Output: ListBuffer(d_date_sk#3932)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8620034_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_moy3940 = tbl_SerializeFromObject_TD_8620034_input.getInt32(i, 1);
        int32_t _d_year3938 = tbl_SerializeFromObject_TD_8620034_input.getInt32(i, 2);
        int32_t _d_date_sk3932 = tbl_SerializeFromObject_TD_8620034_input.getInt32(i, 0);
        if ((((_d_moy3940!= 0) && (_d_year3938!= 0)) && ((_d_moy3940 == 11) && (_d_year3938 == 1999))) && (_d_date_sk3932!= 0)) {
            int32_t _d_date_sk3932_t = tbl_SerializeFromObject_TD_8620034_input.getInt32(i, 0);
            tbl_Filter_TD_7697127_output.setInt32(r, 0, _d_date_sk3932_t);
            r++;
        }
    }
    tbl_Filter_TD_7697127_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7697127_output #Row: " << tbl_Filter_TD_7697127_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7490330(Table &tbl_SerializeFromObject_TD_8690146_input, Table &tbl_Filter_TD_7490330_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cs_sold_date_sk#1104) AND (isnotnull(cs_item_sk#1119) AND isnotnull(cs_sold_time_sk#1105))))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_sold_time_sk#1105, cs_item_sk#1119, cs_ext_sales_price#1127)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_sold_time_sk#1105, cs_item_sk#1119, cs_ext_sales_price#1127)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8690146_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_8690146_input.getInt32(i, 0);
        int32_t _cs_item_sk1119 = tbl_SerializeFromObject_TD_8690146_input.getInt32(i, 2);
        int32_t _cs_sold_time_sk1105 = tbl_SerializeFromObject_TD_8690146_input.getInt32(i, 1);
        if ((_cs_sold_date_sk1104!= 0) && ((_cs_item_sk1119!= 0) && (_cs_sold_time_sk1105!= 0))) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_8690146_input.getInt32(i, 0);
            tbl_Filter_TD_7490330_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int32_t _cs_sold_time_sk1105_t = tbl_SerializeFromObject_TD_8690146_input.getInt32(i, 1);
            tbl_Filter_TD_7490330_output.setInt32(r, 1, _cs_sold_time_sk1105_t);
            int32_t _cs_item_sk1119_t = tbl_SerializeFromObject_TD_8690146_input.getInt32(i, 2);
            tbl_Filter_TD_7490330_output.setInt32(r, 2, _cs_item_sk1119_t);
            int64_t _cs_ext_sales_price1127_t = tbl_SerializeFromObject_TD_8690146_input.getInt64(i, 3);
            tbl_Filter_TD_7490330_output.setInt64(r, 3, _cs_ext_sales_price1127_t);
            r++;
        }
    }
    tbl_Filter_TD_7490330_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7490330_output #Row: " << tbl_Filter_TD_7490330_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7772714(Table &tbl_SerializeFromObject_TD_8241330_input, Table &tbl_Filter_TD_7772714_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_moy#128) AND isnotnull(d_year#126)) AND ((d_moy#128 = 11) AND (d_year#126 = 1999))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_moy#128, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8241330_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_moy128 = tbl_SerializeFromObject_TD_8241330_input.getInt32(i, 1);
        int32_t _d_year126 = tbl_SerializeFromObject_TD_8241330_input.getInt32(i, 2);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_8241330_input.getInt32(i, 0);
        if ((((_d_moy128!= 0) && (_d_year126!= 0)) && ((_d_moy128 == 11) && (_d_year126 == 1999))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_8241330_input.getInt32(i, 0);
            tbl_Filter_TD_7772714_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_7772714_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7772714_output #Row: " << tbl_Filter_TD_7772714_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7675179(Table &tbl_SerializeFromObject_TD_8504978_input, Table &tbl_Filter_TD_7675179_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_sold_date_sk#729) AND (isnotnull(ws_item_sk#732) AND isnotnull(ws_sold_time_sk#730))))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_sold_time_sk#730, ws_item_sk#732, ws_ext_sales_price#752)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_sold_time_sk#730, ws_item_sk#732, ws_ext_sales_price#752)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8504978_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_8504978_input.getInt32(i, 0);
        int32_t _ws_item_sk732 = tbl_SerializeFromObject_TD_8504978_input.getInt32(i, 2);
        int32_t _ws_sold_time_sk730 = tbl_SerializeFromObject_TD_8504978_input.getInt32(i, 1);
        if ((_ws_sold_date_sk729!= 0) && ((_ws_item_sk732!= 0) && (_ws_sold_time_sk730!= 0))) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_8504978_input.getInt32(i, 0);
            tbl_Filter_TD_7675179_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_sold_time_sk730_t = tbl_SerializeFromObject_TD_8504978_input.getInt32(i, 1);
            tbl_Filter_TD_7675179_output.setInt32(r, 1, _ws_sold_time_sk730_t);
            int32_t _ws_item_sk732_t = tbl_SerializeFromObject_TD_8504978_input.getInt32(i, 2);
            tbl_Filter_TD_7675179_output.setInt32(r, 2, _ws_item_sk732_t);
            int64_t _ws_ext_sales_price752_t = tbl_SerializeFromObject_TD_8504978_input.getInt64(i, 3);
            tbl_Filter_TD_7675179_output.setInt64(r, 3, _ws_ext_sales_price752_t);
            r++;
        }
    }
    tbl_Filter_TD_7675179_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7675179_output #Row: " << tbl_Filter_TD_7675179_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6577483_key_leftMajor {
    int32_t _ss_sold_date_sk1206;
    bool operator==(const SW_JOIN_INNER_TD_6577483_key_leftMajor& other) const {
        return ((_ss_sold_date_sk1206 == other._ss_sold_date_sk1206));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6577483_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6577483_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_sold_date_sk1206));
    }
};
}
struct SW_JOIN_INNER_TD_6577483_payload_leftMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_sold_time_sk1207;
    int32_t _ss_item_sk1208;
    int64_t _ss_ext_sales_price1221;
};
struct SW_JOIN_INNER_TD_6577483_key_rightMajor {
    int32_t _d_date_sk3960;
    bool operator==(const SW_JOIN_INNER_TD_6577483_key_rightMajor& other) const {
        return ((_d_date_sk3960 == other._d_date_sk3960));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6577483_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6577483_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk3960));
    }
};
}
struct SW_JOIN_INNER_TD_6577483_payload_rightMajor {
    int32_t _d_date_sk3960;
};
void SW_JOIN_INNER_TD_6577483(Table &tbl_Filter_TD_7416657_output, Table &tbl_Filter_TD_7369543_output, Table &tbl_JOIN_INNER_TD_6577483_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((d_date_sk#3960 = ss_sold_date_sk#1206))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_sold_time_sk#1207, ss_item_sk#1208, ss_ext_sales_price#1221)
    // Right Table: ListBuffer(d_date_sk#3960)
    // Output Table: ListBuffer(ss_ext_sales_price#1221, ss_item_sk#1208, ss_sold_time_sk#1207)
    int left_nrow = tbl_Filter_TD_7416657_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7369543_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6577483_key_leftMajor, SW_JOIN_INNER_TD_6577483_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_7416657_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_Filter_TD_7416657_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6577483_key_leftMajor keyA{_ss_sold_date_sk1206_k};
            int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_7416657_output.getInt32(i, 0);
            int32_t _ss_sold_time_sk1207 = tbl_Filter_TD_7416657_output.getInt32(i, 1);
            int32_t _ss_item_sk1208 = tbl_Filter_TD_7416657_output.getInt32(i, 2);
            int64_t _ss_ext_sales_price1221 = tbl_Filter_TD_7416657_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_6577483_payload_leftMajor payloadA{_ss_sold_date_sk1206, _ss_sold_time_sk1207, _ss_item_sk1208, _ss_ext_sales_price1221};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7369543_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk3960_k = tbl_Filter_TD_7369543_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6577483_key_leftMajor{_d_date_sk3960_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_sold_time_sk1207 = (it->second)._ss_sold_time_sk1207;
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int32_t _d_date_sk3960 = tbl_Filter_TD_7369543_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_6577483_output.setInt32(r, 2, _ss_sold_time_sk1207);
                tbl_JOIN_INNER_TD_6577483_output.setInt32(r, 1, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_6577483_output.setInt64(r, 0, _ss_ext_sales_price1221);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6577483_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6577483_key_rightMajor, SW_JOIN_INNER_TD_6577483_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7369543_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk3960_k = tbl_Filter_TD_7369543_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6577483_key_rightMajor keyA{_d_date_sk3960_k};
            int32_t _d_date_sk3960 = tbl_Filter_TD_7369543_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6577483_payload_rightMajor payloadA{_d_date_sk3960};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7416657_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_Filter_TD_7416657_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6577483_key_rightMajor{_ss_sold_date_sk1206_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk3960 = (it->second)._d_date_sk3960;
                int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_7416657_output.getInt32(i, 0);
                int32_t _ss_sold_time_sk1207 = tbl_Filter_TD_7416657_output.getInt32(i, 1);
                int32_t _ss_item_sk1208 = tbl_Filter_TD_7416657_output.getInt32(i, 2);
                int64_t _ss_ext_sales_price1221 = tbl_Filter_TD_7416657_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_6577483_output.setInt32(r, 2, _ss_sold_time_sk1207);
                tbl_JOIN_INNER_TD_6577483_output.setInt32(r, 1, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_6577483_output.setInt64(r, 0, _ss_ext_sales_price1221);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6577483_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6577483_output #Row: " << tbl_JOIN_INNER_TD_6577483_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6463096_key_leftMajor {
    int32_t _cs_sold_date_sk1104;
    bool operator==(const SW_JOIN_INNER_TD_6463096_key_leftMajor& other) const {
        return ((_cs_sold_date_sk1104 == other._cs_sold_date_sk1104));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6463096_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6463096_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_sold_date_sk1104));
    }
};
}
struct SW_JOIN_INNER_TD_6463096_payload_leftMajor {
    int32_t _cs_sold_date_sk1104;
    int32_t _cs_sold_time_sk1105;
    int32_t _cs_item_sk1119;
    int64_t _cs_ext_sales_price1127;
};
struct SW_JOIN_INNER_TD_6463096_key_rightMajor {
    int32_t _d_date_sk3932;
    bool operator==(const SW_JOIN_INNER_TD_6463096_key_rightMajor& other) const {
        return ((_d_date_sk3932 == other._d_date_sk3932));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6463096_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6463096_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk3932));
    }
};
}
struct SW_JOIN_INNER_TD_6463096_payload_rightMajor {
    int32_t _d_date_sk3932;
};
void SW_JOIN_INNER_TD_6463096(Table &tbl_Filter_TD_7490330_output, Table &tbl_Filter_TD_7697127_output, Table &tbl_JOIN_INNER_TD_6463096_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((d_date_sk#3932 = cs_sold_date_sk#1104))
    // Left Table: ListBuffer(cs_sold_date_sk#1104, cs_sold_time_sk#1105, cs_item_sk#1119, cs_ext_sales_price#1127)
    // Right Table: ListBuffer(d_date_sk#3932)
    // Output Table: ListBuffer(cs_ext_sales_price#1127, cs_item_sk#1119, cs_sold_time_sk#1105)
    int left_nrow = tbl_Filter_TD_7490330_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7697127_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6463096_key_leftMajor, SW_JOIN_INNER_TD_6463096_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_7490330_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_sold_date_sk1104_k = tbl_Filter_TD_7490330_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6463096_key_leftMajor keyA{_cs_sold_date_sk1104_k};
            int32_t _cs_sold_date_sk1104 = tbl_Filter_TD_7490330_output.getInt32(i, 0);
            int32_t _cs_sold_time_sk1105 = tbl_Filter_TD_7490330_output.getInt32(i, 1);
            int32_t _cs_item_sk1119 = tbl_Filter_TD_7490330_output.getInt32(i, 2);
            int64_t _cs_ext_sales_price1127 = tbl_Filter_TD_7490330_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_6463096_payload_leftMajor payloadA{_cs_sold_date_sk1104, _cs_sold_time_sk1105, _cs_item_sk1119, _cs_ext_sales_price1127};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7697127_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk3932_k = tbl_Filter_TD_7697127_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6463096_key_leftMajor{_d_date_sk3932_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk1104 = (it->second)._cs_sold_date_sk1104;
                int32_t _cs_sold_time_sk1105 = (it->second)._cs_sold_time_sk1105;
                int32_t _cs_item_sk1119 = (it->second)._cs_item_sk1119;
                int64_t _cs_ext_sales_price1127 = (it->second)._cs_ext_sales_price1127;
                int32_t _d_date_sk3932 = tbl_Filter_TD_7697127_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_6463096_output.setInt32(r, 2, _cs_sold_time_sk1105);
                tbl_JOIN_INNER_TD_6463096_output.setInt32(r, 1, _cs_item_sk1119);
                tbl_JOIN_INNER_TD_6463096_output.setInt64(r, 0, _cs_ext_sales_price1127);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6463096_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6463096_key_rightMajor, SW_JOIN_INNER_TD_6463096_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7697127_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk3932_k = tbl_Filter_TD_7697127_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6463096_key_rightMajor keyA{_d_date_sk3932_k};
            int32_t _d_date_sk3932 = tbl_Filter_TD_7697127_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6463096_payload_rightMajor payloadA{_d_date_sk3932};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7490330_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_sold_date_sk1104_k = tbl_Filter_TD_7490330_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6463096_key_rightMajor{_cs_sold_date_sk1104_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk3932 = (it->second)._d_date_sk3932;
                int32_t _cs_sold_date_sk1104 = tbl_Filter_TD_7490330_output.getInt32(i, 0);
                int32_t _cs_sold_time_sk1105 = tbl_Filter_TD_7490330_output.getInt32(i, 1);
                int32_t _cs_item_sk1119 = tbl_Filter_TD_7490330_output.getInt32(i, 2);
                int64_t _cs_ext_sales_price1127 = tbl_Filter_TD_7490330_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_6463096_output.setInt32(r, 2, _cs_sold_time_sk1105);
                tbl_JOIN_INNER_TD_6463096_output.setInt32(r, 1, _cs_item_sk1119);
                tbl_JOIN_INNER_TD_6463096_output.setInt64(r, 0, _cs_ext_sales_price1127);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6463096_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6463096_output #Row: " << tbl_JOIN_INNER_TD_6463096_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_646046_key_leftMajor {
    int32_t _ws_sold_date_sk729;
    bool operator==(const SW_JOIN_INNER_TD_646046_key_leftMajor& other) const {
        return ((_ws_sold_date_sk729 == other._ws_sold_date_sk729));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_646046_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_646046_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_sold_date_sk729));
    }
};
}
struct SW_JOIN_INNER_TD_646046_payload_leftMajor {
    int32_t _ws_sold_date_sk729;
    int32_t _ws_sold_time_sk730;
    int32_t _ws_item_sk732;
    int64_t _ws_ext_sales_price752;
};
struct SW_JOIN_INNER_TD_646046_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_646046_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_646046_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_646046_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_646046_payload_rightMajor {
    int32_t _d_date_sk120;
};
void SW_JOIN_INNER_TD_646046(Table &tbl_Filter_TD_7675179_output, Table &tbl_Filter_TD_7772714_output, Table &tbl_JOIN_INNER_TD_646046_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((d_date_sk#120 = ws_sold_date_sk#729))
    // Left Table: ListBuffer(ws_sold_date_sk#729, ws_sold_time_sk#730, ws_item_sk#732, ws_ext_sales_price#752)
    // Right Table: ListBuffer(d_date_sk#120)
    // Output Table: ListBuffer(ws_ext_sales_price#752, ws_item_sk#732, ws_sold_time_sk#730)
    int left_nrow = tbl_Filter_TD_7675179_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7772714_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_646046_key_leftMajor, SW_JOIN_INNER_TD_646046_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_7675179_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_sold_date_sk729_k = tbl_Filter_TD_7675179_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_646046_key_leftMajor keyA{_ws_sold_date_sk729_k};
            int32_t _ws_sold_date_sk729 = tbl_Filter_TD_7675179_output.getInt32(i, 0);
            int32_t _ws_sold_time_sk730 = tbl_Filter_TD_7675179_output.getInt32(i, 1);
            int32_t _ws_item_sk732 = tbl_Filter_TD_7675179_output.getInt32(i, 2);
            int64_t _ws_ext_sales_price752 = tbl_Filter_TD_7675179_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_646046_payload_leftMajor payloadA{_ws_sold_date_sk729, _ws_sold_time_sk730, _ws_item_sk732, _ws_ext_sales_price752};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7772714_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_7772714_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_646046_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_date_sk729 = (it->second)._ws_sold_date_sk729;
                int32_t _ws_sold_time_sk730 = (it->second)._ws_sold_time_sk730;
                int32_t _ws_item_sk732 = (it->second)._ws_item_sk732;
                int64_t _ws_ext_sales_price752 = (it->second)._ws_ext_sales_price752;
                int32_t _d_date_sk120 = tbl_Filter_TD_7772714_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_646046_output.setInt32(r, 2, _ws_sold_time_sk730);
                tbl_JOIN_INNER_TD_646046_output.setInt32(r, 1, _ws_item_sk732);
                tbl_JOIN_INNER_TD_646046_output.setInt64(r, 0, _ws_ext_sales_price752);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_646046_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_646046_key_rightMajor, SW_JOIN_INNER_TD_646046_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7772714_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_7772714_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_646046_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_7772714_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_646046_payload_rightMajor payloadA{_d_date_sk120};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7675179_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_sold_date_sk729_k = tbl_Filter_TD_7675179_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_646046_key_rightMajor{_ws_sold_date_sk729_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _ws_sold_date_sk729 = tbl_Filter_TD_7675179_output.getInt32(i, 0);
                int32_t _ws_sold_time_sk730 = tbl_Filter_TD_7675179_output.getInt32(i, 1);
                int32_t _ws_item_sk732 = tbl_Filter_TD_7675179_output.getInt32(i, 2);
                int64_t _ws_ext_sales_price752 = tbl_Filter_TD_7675179_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_646046_output.setInt32(r, 2, _ws_sold_time_sk730);
                tbl_JOIN_INNER_TD_646046_output.setInt32(r, 1, _ws_item_sk732);
                tbl_JOIN_INNER_TD_646046_output.setInt64(r, 0, _ws_ext_sales_price752);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_646046_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_646046_output #Row: " << tbl_JOIN_INNER_TD_646046_output.getNumRow() << std::endl;
}

void SW_Project_TD_516911(Table &tbl_JOIN_INNER_TD_6577483_output, Table &tbl_Project_TD_516911_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(ss_ext_sales_price#1221 AS ext_price#3925, ss_item_sk#1208 AS sold_item_sk#3927, ss_sold_time_sk#1207 AS time_sk#3928)
    // Input: ListBuffer(ss_ext_sales_price#1221, ss_item_sk#1208, ss_sold_time_sk#1207)
    // Output: ListBuffer(ext_price#3925, sold_item_sk#3927, time_sk#3928)
    int nrow1 = tbl_JOIN_INNER_TD_6577483_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_6577483_output.getInt64(i, 0);
        int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_6577483_output.getInt32(i, 1);
        int32_t _ss_sold_time_sk1207 = tbl_JOIN_INNER_TD_6577483_output.getInt32(i, 2);
        int64_t _ext_price3925 = _ss_ext_sales_price1221;
        tbl_Project_TD_516911_output.setInt64(i, 0, _ext_price3925);
        int32_t _sold_item_sk3927 = _ss_item_sk1208;
        tbl_Project_TD_516911_output.setInt32(i, 1, _sold_item_sk3927);
        int32_t _time_sk3928 = _ss_sold_time_sk1207;
        tbl_Project_TD_516911_output.setInt32(i, 2, _time_sk3928);
    }
    tbl_Project_TD_516911_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_516911_output #Row: " << tbl_Project_TD_516911_output.getNumRow() << std::endl;
}

void SW_Project_TD_5188579(Table &tbl_JOIN_INNER_TD_6463096_output, Table &tbl_Project_TD_5188579_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(cs_ext_sales_price#1127 AS ext_price#3921, cs_item_sk#1119 AS sold_item_sk#3923, cs_sold_time_sk#1105 AS time_sk#3924)
    // Input: ListBuffer(cs_ext_sales_price#1127, cs_item_sk#1119, cs_sold_time_sk#1105)
    // Output: ListBuffer(ext_price#3921, sold_item_sk#3923, time_sk#3924)
    int nrow1 = tbl_JOIN_INNER_TD_6463096_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _cs_ext_sales_price1127 = tbl_JOIN_INNER_TD_6463096_output.getInt64(i, 0);
        int32_t _cs_item_sk1119 = tbl_JOIN_INNER_TD_6463096_output.getInt32(i, 1);
        int32_t _cs_sold_time_sk1105 = tbl_JOIN_INNER_TD_6463096_output.getInt32(i, 2);
        int64_t _ext_price3921 = _cs_ext_sales_price1127;
        tbl_Project_TD_5188579_output.setInt64(i, 0, _ext_price3921);
        int32_t _sold_item_sk3923 = _cs_item_sk1119;
        tbl_Project_TD_5188579_output.setInt32(i, 1, _sold_item_sk3923);
        int32_t _time_sk3924 = _cs_sold_time_sk1105;
        tbl_Project_TD_5188579_output.setInt32(i, 2, _time_sk3924);
    }
    tbl_Project_TD_5188579_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_5188579_output #Row: " << tbl_Project_TD_5188579_output.getNumRow() << std::endl;
}

void SW_Project_TD_5746317(Table &tbl_JOIN_INNER_TD_646046_output, Table &tbl_Project_TD_5746317_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(ws_ext_sales_price#752 AS ext_price#3917, ws_item_sk#732 AS sold_item_sk#3919, ws_sold_time_sk#730 AS time_sk#3920)
    // Input: ListBuffer(ws_ext_sales_price#752, ws_item_sk#732, ws_sold_time_sk#730)
    // Output: ListBuffer(ext_price#3917, sold_item_sk#3919, time_sk#3920)
    int nrow1 = tbl_JOIN_INNER_TD_646046_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ws_ext_sales_price752 = tbl_JOIN_INNER_TD_646046_output.getInt64(i, 0);
        int32_t _ws_item_sk732 = tbl_JOIN_INNER_TD_646046_output.getInt32(i, 1);
        int32_t _ws_sold_time_sk730 = tbl_JOIN_INNER_TD_646046_output.getInt32(i, 2);
        int64_t _ext_price3917 = _ws_ext_sales_price752;
        tbl_Project_TD_5746317_output.setInt64(i, 0, _ext_price3917);
        int32_t _sold_item_sk3919 = _ws_item_sk732;
        tbl_Project_TD_5746317_output.setInt32(i, 1, _sold_item_sk3919);
        int32_t _time_sk3920 = _ws_sold_time_sk730;
        tbl_Project_TD_5746317_output.setInt32(i, 2, _time_sk3920);
    }
    tbl_Project_TD_5746317_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_5746317_output #Row: " << tbl_Project_TD_5746317_output.getNumRow() << std::endl;
}

void SW_Union_TD_4542419(Table &tbl_Project_TD_5746317_output, Table &tbl_Project_TD_5188579_output, Table &tbl_Project_TD_516911_output, Table &tbl_Union_TD_4542419_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Union
    // Operation: ListBuffer(List(UNION))
    // Output Table: ListBuffer(ext_price#3917, sold_item_sk#3919, time_sk#3920)
    int r = 0;
    int row0 = tbl_Project_TD_5746317_output.getNumRow();
    for (int i = 0; i < row0; i++) {
        tbl_Union_TD_4542419_output.setInt32(r, 0, tbl_Project_TD_5746317_output.getInt64(i, 0));
        tbl_Union_TD_4542419_output.setInt32(r, 1, tbl_Project_TD_5746317_output.getInt32(i, 1));
        tbl_Union_TD_4542419_output.setInt32(r, 2, tbl_Project_TD_5746317_output.getInt32(i, 2));
        ++r;
    }
    int row1 = tbl_Project_TD_5188579_output.getNumRow();
    for (int i = 0; i < row1; i++) {
        tbl_Union_TD_4542419_output.setInt32(r, 0, tbl_Project_TD_5188579_output.getInt64(i, 0));
        tbl_Union_TD_4542419_output.setInt32(r, 1, tbl_Project_TD_5188579_output.getInt32(i, 1));
        tbl_Union_TD_4542419_output.setInt32(r, 2, tbl_Project_TD_5188579_output.getInt32(i, 2));
        ++r;
    }
    int row2 = tbl_Project_TD_516911_output.getNumRow();
    for (int i = 0; i < row2; i++) {
        tbl_Union_TD_4542419_output.setInt32(r, 0, tbl_Project_TD_516911_output.getInt64(i, 0));
        tbl_Union_TD_4542419_output.setInt32(r, 1, tbl_Project_TD_516911_output.getInt32(i, 1));
        tbl_Union_TD_4542419_output.setInt32(r, 2, tbl_Project_TD_516911_output.getInt32(i, 2));
        ++r;
    }
    tbl_Union_TD_4542419_output.setNumRow(r);
    std::cout << "tbl_Union_TD_4542419_output #Row: " << tbl_Union_TD_4542419_output.getNumRow() << std::endl;
}

void SW_Filter_TD_4891119(Table &tbl_SerializeFromObject_TD_5483920_input, Table &tbl_Filter_TD_4891119_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(i_manager_id#248) AND (i_manager_id#248 = 1)) AND isnotnull(i_item_sk#228)))
    // Input: ListBuffer(i_item_sk#228, i_brand_id#235, i_brand#236, i_manager_id#248)
    // Output: ListBuffer(i_item_sk#228, i_brand_id#235, i_brand#236)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5483920_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_manager_id248 = tbl_SerializeFromObject_TD_5483920_input.getInt32(i, 3);
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_5483920_input.getInt32(i, 0);
        if (((_i_manager_id248!= 0) && (_i_manager_id248 == 1)) && (_i_item_sk228!= 0)) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_5483920_input.getInt32(i, 0);
            tbl_Filter_TD_4891119_output.setInt32(r, 0, _i_item_sk228_t);
            int32_t _i_brand_id235_t = tbl_SerializeFromObject_TD_5483920_input.getInt32(i, 1);
            tbl_Filter_TD_4891119_output.setInt32(r, 1, _i_brand_id235_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_t = tbl_SerializeFromObject_TD_5483920_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_4891119_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_brand236_t);
            r++;
        }
    }
    tbl_Filter_TD_4891119_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4891119_output #Row: " << tbl_Filter_TD_4891119_output.getNumRow() << std::endl;
}

void SW_Filter_TD_3228522(Table &tbl_SerializeFromObject_TD_4839560_input, Table &tbl_Filter_TD_3228522_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((t_meal_time#474 = breakfast) OR (t_meal_time#474 = dinner)) AND isnotnull(t_time_sk#465)))
    // Input: ListBuffer(t_time_sk#465, t_hour#468, t_minute#469, t_meal_time#474)
    // Output: ListBuffer(t_time_sk#465, t_hour#468, t_minute#469)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_4839560_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _t_meal_time474 = tbl_SerializeFromObject_TD_4839560_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        int32_t _t_time_sk465 = tbl_SerializeFromObject_TD_4839560_input.getInt32(i, 0);
        if (((std::string(_t_meal_time474.data()) == "breakfast") || (std::string(_t_meal_time474.data()) == "dinner")) && (_t_time_sk465!= 0)) {
            int32_t _t_time_sk465_t = tbl_SerializeFromObject_TD_4839560_input.getInt32(i, 0);
            tbl_Filter_TD_3228522_output.setInt32(r, 0, _t_time_sk465_t);
            int32_t _t_hour468_t = tbl_SerializeFromObject_TD_4839560_input.getInt32(i, 1);
            tbl_Filter_TD_3228522_output.setInt32(r, 1, _t_hour468_t);
            int32_t _t_minute469_t = tbl_SerializeFromObject_TD_4839560_input.getInt32(i, 2);
            tbl_Filter_TD_3228522_output.setInt32(r, 2, _t_minute469_t);
            r++;
        }
    }
    tbl_Filter_TD_3228522_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_3228522_output #Row: " << tbl_Filter_TD_3228522_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_3329195_key_leftMajor {
    int32_t _i_item_sk228;
    bool operator==(const SW_JOIN_INNER_TD_3329195_key_leftMajor& other) const {
        return ((_i_item_sk228 == other._i_item_sk228));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3329195_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3329195_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk228));
    }
};
}
struct SW_JOIN_INNER_TD_3329195_payload_leftMajor {
    int32_t _i_item_sk228;
    int32_t _i_brand_id235;
    std::string _i_brand236;
};
struct SW_JOIN_INNER_TD_3329195_key_rightMajor {
    int32_t _sold_item_sk3919;
    bool operator==(const SW_JOIN_INNER_TD_3329195_key_rightMajor& other) const {
        return ((_sold_item_sk3919 == other._sold_item_sk3919));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3329195_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3329195_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._sold_item_sk3919));
    }
};
}
struct SW_JOIN_INNER_TD_3329195_payload_rightMajor {
    int64_t _ext_price3917;
    int32_t _sold_item_sk3919;
    int32_t _time_sk3920;
};
void SW_JOIN_INNER_TD_3329195(Table &tbl_Filter_TD_4891119_output, Table &tbl_Union_TD_4542419_output, Table &tbl_JOIN_INNER_TD_3329195_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((sold_item_sk#3919 = i_item_sk#228))
    // Left Table: ListBuffer(i_item_sk#228, i_brand_id#235, i_brand#236)
    // Right Table: ListBuffer(ext_price#3917, sold_item_sk#3919, time_sk#3920)
    // Output Table: ListBuffer(i_brand_id#235, i_brand#236, ext_price#3917, time_sk#3920)
    int left_nrow = tbl_Filter_TD_4891119_output.getNumRow();
    int right_nrow = tbl_Union_TD_4542419_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3329195_key_leftMajor, SW_JOIN_INNER_TD_3329195_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_4891119_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_4891119_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3329195_key_leftMajor keyA{_i_item_sk228_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_4891119_output.getInt32(i, 0);
            int32_t _i_brand_id235 = tbl_Filter_TD_4891119_output.getInt32(i, 1);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_Filter_TD_4891119_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _i_brand236 = std::string(_i_brand236_n.data());
            SW_JOIN_INNER_TD_3329195_payload_leftMajor payloadA{_i_item_sk228, _i_brand_id235, _i_brand236};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Union_TD_4542419_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _sold_item_sk3919_k = tbl_Union_TD_4542419_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3329195_key_leftMajor{_sold_item_sk3919_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                int32_t _i_brand_id235 = (it->second)._i_brand_id235;
                std::string _i_brand236 = (it->second)._i_brand236;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n{};
                memcpy(_i_brand236_n.data(), (_i_brand236).data(), (_i_brand236).length());
                int64_t _ext_price3917 = tbl_Union_TD_4542419_output.getInt64(i, 0);
                int32_t _sold_item_sk3919 = tbl_Union_TD_4542419_output.getInt32(i, 1);
                int32_t _time_sk3920 = tbl_Union_TD_4542419_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_3329195_output.setInt32(r, 0, _i_brand_id235);
                tbl_JOIN_INNER_TD_3329195_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand236_n);
                tbl_JOIN_INNER_TD_3329195_output.setInt64(r, 2, _ext_price3917);
                tbl_JOIN_INNER_TD_3329195_output.setInt32(r, 3, _time_sk3920);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3329195_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3329195_key_rightMajor, SW_JOIN_INNER_TD_3329195_payload_rightMajor> ht1;
        int nrow1 = tbl_Union_TD_4542419_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _sold_item_sk3919_k = tbl_Union_TD_4542419_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_3329195_key_rightMajor keyA{_sold_item_sk3919_k};
            int64_t _ext_price3917 = tbl_Union_TD_4542419_output.getInt64(i, 0);
            int32_t _sold_item_sk3919 = tbl_Union_TD_4542419_output.getInt32(i, 1);
            int32_t _time_sk3920 = tbl_Union_TD_4542419_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_3329195_payload_rightMajor payloadA{_ext_price3917, _sold_item_sk3919, _time_sk3920};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_4891119_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_4891119_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3329195_key_rightMajor{_i_item_sk228_k});
            auto it = its.first;
            while (it != its.second) {
                int64_t _ext_price3917 = (it->second)._ext_price3917;
                int32_t _sold_item_sk3919 = (it->second)._sold_item_sk3919;
                int32_t _time_sk3920 = (it->second)._time_sk3920;
                int32_t _i_item_sk228 = tbl_Filter_TD_4891119_output.getInt32(i, 0);
                int32_t _i_brand_id235 = tbl_Filter_TD_4891119_output.getInt32(i, 1);
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_Filter_TD_4891119_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _i_brand236 = std::string(_i_brand236_n.data());
                tbl_JOIN_INNER_TD_3329195_output.setInt64(r, 2, _ext_price3917);
                tbl_JOIN_INNER_TD_3329195_output.setInt32(r, 3, _time_sk3920);
                tbl_JOIN_INNER_TD_3329195_output.setInt32(r, 0, _i_brand_id235);
                tbl_JOIN_INNER_TD_3329195_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand236_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3329195_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_3329195_output #Row: " << tbl_JOIN_INNER_TD_3329195_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_2111129_key_leftMajor {
    int32_t _time_sk3920;
    bool operator==(const SW_JOIN_INNER_TD_2111129_key_leftMajor& other) const {
        return ((_time_sk3920 == other._time_sk3920));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_2111129_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_2111129_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._time_sk3920));
    }
};
}
struct SW_JOIN_INNER_TD_2111129_payload_leftMajor {
    int32_t _i_brand_id235;
    std::string _i_brand236;
    int64_t _ext_price3917;
    int32_t _time_sk3920;
};
struct SW_JOIN_INNER_TD_2111129_key_rightMajor {
    int32_t _t_time_sk465;
    bool operator==(const SW_JOIN_INNER_TD_2111129_key_rightMajor& other) const {
        return ((_t_time_sk465 == other._t_time_sk465));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_2111129_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_2111129_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._t_time_sk465));
    }
};
}
struct SW_JOIN_INNER_TD_2111129_payload_rightMajor {
    int32_t _t_time_sk465;
    int32_t _t_hour468;
    int32_t _t_minute469;
};
void SW_JOIN_INNER_TD_2111129(Table &tbl_JOIN_INNER_TD_3329195_output, Table &tbl_Filter_TD_3228522_output, Table &tbl_JOIN_INNER_TD_2111129_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((time_sk#3920 = t_time_sk#465))
    // Left Table: ListBuffer(i_brand_id#235, i_brand#236, ext_price#3917, time_sk#3920)
    // Right Table: ListBuffer(t_time_sk#465, t_hour#468, t_minute#469)
    // Output Table: ListBuffer(i_brand_id#235, i_brand#236, ext_price#3917, t_hour#468, t_minute#469)
    int left_nrow = tbl_JOIN_INNER_TD_3329195_output.getNumRow();
    int right_nrow = tbl_Filter_TD_3228522_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_2111129_key_leftMajor, SW_JOIN_INNER_TD_2111129_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_3329195_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _time_sk3920_k = tbl_JOIN_INNER_TD_3329195_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_2111129_key_leftMajor keyA{_time_sk3920_k};
            int32_t _i_brand_id235 = tbl_JOIN_INNER_TD_3329195_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_JOIN_INNER_TD_3329195_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand236 = std::string(_i_brand236_n.data());
            int64_t _ext_price3917 = tbl_JOIN_INNER_TD_3329195_output.getInt64(i, 2);
            int32_t _time_sk3920 = tbl_JOIN_INNER_TD_3329195_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_2111129_payload_leftMajor payloadA{_i_brand_id235, _i_brand236, _ext_price3917, _time_sk3920};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_3228522_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _t_time_sk465_k = tbl_Filter_TD_3228522_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_2111129_key_leftMajor{_t_time_sk465_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_brand_id235 = (it->second)._i_brand_id235;
                std::string _i_brand236 = (it->second)._i_brand236;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n{};
                memcpy(_i_brand236_n.data(), (_i_brand236).data(), (_i_brand236).length());
                int64_t _ext_price3917 = (it->second)._ext_price3917;
                int32_t _time_sk3920 = (it->second)._time_sk3920;
                int32_t _t_time_sk465 = tbl_Filter_TD_3228522_output.getInt32(i, 0);
                int32_t _t_hour468 = tbl_Filter_TD_3228522_output.getInt32(i, 1);
                int32_t _t_minute469 = tbl_Filter_TD_3228522_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_2111129_output.setInt32(r, 0, _i_brand_id235);
                tbl_JOIN_INNER_TD_2111129_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand236_n);
                tbl_JOIN_INNER_TD_2111129_output.setInt64(r, 2, _ext_price3917);
                tbl_JOIN_INNER_TD_2111129_output.setInt32(r, 3, _t_hour468);
                tbl_JOIN_INNER_TD_2111129_output.setInt32(r, 4, _t_minute469);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_2111129_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_2111129_key_rightMajor, SW_JOIN_INNER_TD_2111129_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_3228522_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _t_time_sk465_k = tbl_Filter_TD_3228522_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_2111129_key_rightMajor keyA{_t_time_sk465_k};
            int32_t _t_time_sk465 = tbl_Filter_TD_3228522_output.getInt32(i, 0);
            int32_t _t_hour468 = tbl_Filter_TD_3228522_output.getInt32(i, 1);
            int32_t _t_minute469 = tbl_Filter_TD_3228522_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_2111129_payload_rightMajor payloadA{_t_time_sk465, _t_hour468, _t_minute469};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_3329195_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _time_sk3920_k = tbl_JOIN_INNER_TD_3329195_output.getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_2111129_key_rightMajor{_time_sk3920_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _t_time_sk465 = (it->second)._t_time_sk465;
                int32_t _t_hour468 = (it->second)._t_hour468;
                int32_t _t_minute469 = (it->second)._t_minute469;
                int32_t _i_brand_id235 = tbl_JOIN_INNER_TD_3329195_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_JOIN_INNER_TD_3329195_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_brand236 = std::string(_i_brand236_n.data());
                int64_t _ext_price3917 = tbl_JOIN_INNER_TD_3329195_output.getInt64(i, 2);
                int32_t _time_sk3920 = tbl_JOIN_INNER_TD_3329195_output.getInt32(i, 3);
                tbl_JOIN_INNER_TD_2111129_output.setInt32(r, 3, _t_hour468);
                tbl_JOIN_INNER_TD_2111129_output.setInt32(r, 4, _t_minute469);
                tbl_JOIN_INNER_TD_2111129_output.setInt32(r, 0, _i_brand_id235);
                tbl_JOIN_INNER_TD_2111129_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand236_n);
                tbl_JOIN_INNER_TD_2111129_output.setInt64(r, 2, _ext_price3917);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_2111129_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_2111129_output #Row: " << tbl_JOIN_INNER_TD_2111129_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_1621060_key {
    std::string _i_brand236;
    int32_t _i_brand_id235;
    int32_t _t_hour468;
    int32_t _t_minute469;
    bool operator==(const SW_Aggregate_TD_1621060_key& other) const { return (_i_brand236 == other._i_brand236) && (_i_brand_id235 == other._i_brand_id235) && (_t_hour468 == other._t_hour468) && (_t_minute469 == other._t_minute469); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_1621060_key> {
    std::size_t operator() (const SW_Aggregate_TD_1621060_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_brand236)) + (hash<int32_t>()(k._i_brand_id235)) + (hash<int32_t>()(k._t_hour468)) + (hash<int32_t>()(k._t_minute469));
    }
};
}
struct SW_Aggregate_TD_1621060_payload {
    int32_t _brand_id3929;
    std::string _brand3930;
    int64_t _ext_price3931_sum_0;
};
void SW_Aggregate_TD_1621060(Table &tbl_JOIN_INNER_TD_2111129_output, Table &tbl_Aggregate_TD_1621060_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(i_brand#236, i_brand_id#235, t_hour#468, t_minute#469, i_brand_id#235 AS brand_id#3929, i_brand#236 AS brand#3930, MakeDecimal(sum(UnscaledValue(ext_price#3917)),17,2) AS ext_price#3931)
    // Input: ListBuffer(i_brand_id#235, i_brand#236, ext_price#3917, t_hour#468, t_minute#469)
    // Output: ListBuffer(brand_id#3929, brand#3930, t_hour#468, t_minute#469, ext_price#3931)
    std::unordered_map<SW_Aggregate_TD_1621060_key, SW_Aggregate_TD_1621060_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_2111129_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_brand_id235 = tbl_JOIN_INNER_TD_2111129_output.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236 = tbl_JOIN_INNER_TD_2111129_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int64_t _ext_price3917 = tbl_JOIN_INNER_TD_2111129_output.getInt64(i, 2);
        int32_t _t_hour468 = tbl_JOIN_INNER_TD_2111129_output.getInt32(i, 3);
        int32_t _t_minute469 = tbl_JOIN_INNER_TD_2111129_output.getInt32(i, 4);
        SW_Aggregate_TD_1621060_key k{std::string(_i_brand236.data()), _i_brand_id235, _t_hour468, _t_minute469};
        int32_t _brand_id3929 = _i_brand_id235;
        std::array<char, TPCDS_READ_MAX + 1> _brand3930 = _i_brand236;
        int64_t _ext_price3931_sum_0 = _ext_price3917;
        SW_Aggregate_TD_1621060_payload p{_brand_id3929, std::string(_brand3930.data()), _ext_price3931_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._ext_price3931_sum_0 + _ext_price3931_sum_0;
            p._ext_price3931_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _i_brand236 not required in the output table
        // _i_brand_id235 not required in the output table
        tbl_Aggregate_TD_1621060_output.setInt32(r, 2, (it.first)._t_hour468);
        tbl_Aggregate_TD_1621060_output.setInt32(r, 3, (it.first)._t_minute469);
        tbl_Aggregate_TD_1621060_output.setInt32(r, 0, (it.second)._brand_id3929);
        std::array<char, TPCDS_READ_MAX + 1> _brand3930_n{};
        memcpy(_brand3930_n.data(), (it.second)._brand3930.data(), (it.second)._brand3930.length());
        tbl_Aggregate_TD_1621060_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _brand3930_n);
        int64_t _ext_price3931 = (it.second)._ext_price3931_sum_0;
        tbl_Aggregate_TD_1621060_output.setInt64(r, 4, _ext_price3931);
        ++r;
    }
    tbl_Aggregate_TD_1621060_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_1621060_output #Row: " << tbl_Aggregate_TD_1621060_output.getNumRow() << std::endl;
}

void SW_Sort_TD_0434544(Table &tbl_Aggregate_TD_1621060_output, Table &tbl_Sort_TD_0434544_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(brand_id#3929 ASC NULLS FIRST)
    // Input: ListBuffer(brand_id#3929, brand#3930, t_hour#468, t_minute#469, ext_price#3931)
    // Output: ListBuffer(brand_id#3929, brand#3930, t_hour#468, t_minute#469, ext_price#3931)
    struct SW_Sort_TD_0434544Row {
        int32_t _brand_id3929;
        std::string _brand3930;
        int32_t _t_hour468;
        int32_t _t_minute469;
        int64_t _ext_price3931;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_0434544Row& a, const SW_Sort_TD_0434544Row& b) const { return 
 (a._brand_id3929 < b._brand_id3929); 
}
    }SW_Sort_TD_0434544_order; 

    int nrow1 = tbl_Aggregate_TD_1621060_output.getNumRow();
    std::vector<SW_Sort_TD_0434544Row> rows;
    for (int i = 0; i < nrow1; i++) {
        int32_t _brand_id3929 = tbl_Aggregate_TD_1621060_output.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _brand3930 = tbl_Aggregate_TD_1621060_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        int32_t _t_hour468 = tbl_Aggregate_TD_1621060_output.getInt32(i, 2);
        int32_t _t_minute469 = tbl_Aggregate_TD_1621060_output.getInt32(i, 3);
        int64_t _ext_price3931 = tbl_Aggregate_TD_1621060_output.getInt64(i, 4);
        SW_Sort_TD_0434544Row t = {_brand_id3929,std::string(_brand3930.data()),_t_hour468,_t_minute469,_ext_price3931};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_0434544_order);
    int r = 0;
    for (auto& it : rows) {
        tbl_Sort_TD_0434544_output.setInt32(r, 0, it._brand_id3929);
        std::array<char, TPCDS_READ_MAX + 1> _brand3930{};
        memcpy(_brand3930.data(), (it._brand3930).data(), (it._brand3930).length());
        tbl_Sort_TD_0434544_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _brand3930);
        tbl_Sort_TD_0434544_output.setInt32(r, 2, it._t_hour468);
        tbl_Sort_TD_0434544_output.setInt32(r, 3, it._t_minute469);
        tbl_Sort_TD_0434544_output.setInt64(r, 4, it._ext_price3931);
        if (r < 10) {
            std::cout << it._brand_id3929 << " " << (it._brand3930).data() << " " << it._t_hour468 << " " << it._t_minute469 << " " << it._ext_price3931 << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_0434544_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_0434544_output #Row: " << tbl_Sort_TD_0434544_output.getNumRow() << std::endl;
}

