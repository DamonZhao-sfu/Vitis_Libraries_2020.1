#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_7656596(Table &tbl_SerializeFromObject_TD_849963_input, Table &tbl_Filter_TD_7656596_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(inv_quantity_on_hand#660) AND ((inv_quantity_on_hand#660 >= 100) AND (inv_quantity_on_hand#660 <= 500))) AND (isnotnull(inv_item_sk#658) AND isnotnull(inv_date_sk#657))))
    // Input: ListBuffer(inv_date_sk#657, inv_item_sk#658, inv_quantity_on_hand#660)
    // Output: ListBuffer(inv_date_sk#657, inv_item_sk#658)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_849963_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _inv_quantity_on_hand660 = tbl_SerializeFromObject_TD_849963_input.getInt32(i, 2);
        int32_t _inv_item_sk658 = tbl_SerializeFromObject_TD_849963_input.getInt32(i, 1);
        int32_t _inv_date_sk657 = tbl_SerializeFromObject_TD_849963_input.getInt32(i, 0);
        if (((_inv_quantity_on_hand660!= 0) && ((_inv_quantity_on_hand660 >= 100) && (_inv_quantity_on_hand660 <= 500))) && ((_inv_item_sk658!= 0) && (_inv_date_sk657!= 0))) {
            int32_t _inv_date_sk657_t = tbl_SerializeFromObject_TD_849963_input.getInt32(i, 0);
            tbl_Filter_TD_7656596_output.setInt32(r, 0, _inv_date_sk657_t);
            int32_t _inv_item_sk658_t = tbl_SerializeFromObject_TD_849963_input.getInt32(i, 1);
            tbl_Filter_TD_7656596_output.setInt32(r, 1, _inv_item_sk658_t);
            r++;
        }
    }
    tbl_Filter_TD_7656596_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7656596_output #Row: " << tbl_Filter_TD_7656596_output.getNumRow() << std::endl;
}

void SW_Filter_TD_713861(Table &tbl_SerializeFromObject_TD_8919781_input, Table &tbl_Filter_TD_713861_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((i_manufact_id#241 IN (129,270,821,423) AND isnotnull(i_item_sk#228)))
    // Input: ListBuffer(i_item_sk#228, i_item_id#229, i_item_desc#232, i_current_price#233, i_manufact_id#241)
    // Output: ListBuffer(i_item_sk#228, i_item_id#229, i_item_desc#232, i_current_price#233)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8919781_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_manufact_id241 = tbl_SerializeFromObject_TD_8919781_input.getInt32(i, 4);
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_8919781_input.getInt32(i, 0);
        auto reuse_col_str_586 = _i_manufact_id241;
        if (((reuse_col_str_586 == 129) || (reuse_col_str_586 == 270) || (reuse_col_str_586 == 821) || (reuse_col_str_586 == 423) || (0)) && (_i_item_sk228!= 0)) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_8919781_input.getInt32(i, 0);
            tbl_Filter_TD_713861_output.setInt32(r, 0, _i_item_sk228_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_t = tbl_SerializeFromObject_TD_8919781_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_713861_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id229_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_t = tbl_SerializeFromObject_TD_8919781_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_713861_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_item_desc232_t);
            int64_t _i_current_price233_t = tbl_SerializeFromObject_TD_8919781_input.getInt64(i, 3);
            tbl_Filter_TD_713861_output.setInt64(r, 3, _i_current_price233_t);
            r++;
        }
    }
    tbl_Filter_TD_713861_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_713861_output #Row: " << tbl_Filter_TD_713861_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6971540(Table &tbl_SerializeFromObject_TD_7496951_input, Table &tbl_Filter_TD_6971540_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_date#122) AND ((d_date#122 >= 2000-05-25) AND (d_date#122 <= 2000-07-24))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_date#122)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7496951_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date122 = tbl_SerializeFromObject_TD_7496951_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_7496951_input.getInt32(i, 0);
        if (((_d_date122!= 0) && ((_d_date122 >= 20000525) && (_d_date122 <= 20000724))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_7496951_input.getInt32(i, 0);
            tbl_Filter_TD_6971540_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_6971540_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6971540_output #Row: " << tbl_Filter_TD_6971540_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_627839_key_leftMajor {
    int32_t _i_item_sk228;
    bool operator==(const SW_JOIN_INNER_TD_627839_key_leftMajor& other) const {
        return ((_i_item_sk228 == other._i_item_sk228));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_627839_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_627839_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk228));
    }
};
}
struct SW_JOIN_INNER_TD_627839_payload_leftMajor {
    int32_t _i_item_sk228;
    std::string _i_item_id229;
    std::string _i_item_desc232;
    int64_t _i_current_price233;
};
struct SW_JOIN_INNER_TD_627839_key_rightMajor {
    int32_t _inv_item_sk658;
    bool operator==(const SW_JOIN_INNER_TD_627839_key_rightMajor& other) const {
        return ((_inv_item_sk658 == other._inv_item_sk658));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_627839_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_627839_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._inv_item_sk658));
    }
};
}
struct SW_JOIN_INNER_TD_627839_payload_rightMajor {
    int32_t _inv_date_sk657;
    int32_t _inv_item_sk658;
};
void SW_JOIN_INNER_TD_627839(Table &tbl_Filter_TD_713861_output, Table &tbl_Filter_TD_7656596_output, Table &tbl_JOIN_INNER_TD_627839_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((inv_item_sk#658 = i_item_sk#228))
    // Left Table: ListBuffer(i_item_sk#228, i_item_id#229, i_item_desc#232, i_current_price#233)
    // Right Table: ListBuffer(inv_date_sk#657, inv_item_sk#658)
    // Output Table: ListBuffer(i_item_sk#228, i_item_id#229, i_item_desc#232, i_current_price#233, inv_date_sk#657)
    int left_nrow = tbl_Filter_TD_713861_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7656596_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_627839_key_leftMajor, SW_JOIN_INNER_TD_627839_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_713861_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_713861_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_627839_key_leftMajor keyA{_i_item_sk228_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_713861_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_Filter_TD_713861_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_item_id229 = std::string(_i_item_id229_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n = tbl_Filter_TD_713861_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _i_item_desc232 = std::string(_i_item_desc232_n.data());
            int64_t _i_current_price233 = tbl_Filter_TD_713861_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_627839_payload_leftMajor payloadA{_i_item_sk228, _i_item_id229, _i_item_desc232, _i_current_price233};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7656596_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _inv_item_sk658_k = tbl_Filter_TD_7656596_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_627839_key_leftMajor{_inv_item_sk658_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                std::string _i_item_id229 = (it->second)._i_item_id229;
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n{};
                memcpy(_i_item_id229_n.data(), (_i_item_id229).data(), (_i_item_id229).length());
                std::string _i_item_desc232 = (it->second)._i_item_desc232;
                std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n{};
                memcpy(_i_item_desc232_n.data(), (_i_item_desc232).data(), (_i_item_desc232).length());
                int64_t _i_current_price233 = (it->second)._i_current_price233;
                int32_t _inv_date_sk657 = tbl_Filter_TD_7656596_output.getInt32(i, 0);
                int32_t _inv_item_sk658 = tbl_Filter_TD_7656596_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_627839_output.setInt32(r, 0, _i_item_sk228);
                tbl_JOIN_INNER_TD_627839_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id229_n);
                tbl_JOIN_INNER_TD_627839_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_item_desc232_n);
                tbl_JOIN_INNER_TD_627839_output.setInt64(r, 3, _i_current_price233);
                tbl_JOIN_INNER_TD_627839_output.setInt32(r, 4, _inv_date_sk657);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_627839_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_627839_key_rightMajor, SW_JOIN_INNER_TD_627839_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7656596_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _inv_item_sk658_k = tbl_Filter_TD_7656596_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_627839_key_rightMajor keyA{_inv_item_sk658_k};
            int32_t _inv_date_sk657 = tbl_Filter_TD_7656596_output.getInt32(i, 0);
            int32_t _inv_item_sk658 = tbl_Filter_TD_7656596_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_627839_payload_rightMajor payloadA{_inv_date_sk657, _inv_item_sk658};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_713861_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_713861_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_627839_key_rightMajor{_i_item_sk228_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _inv_date_sk657 = (it->second)._inv_date_sk657;
                int32_t _inv_item_sk658 = (it->second)._inv_item_sk658;
                int32_t _i_item_sk228 = tbl_Filter_TD_713861_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_Filter_TD_713861_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_item_id229 = std::string(_i_item_id229_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n = tbl_Filter_TD_713861_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _i_item_desc232 = std::string(_i_item_desc232_n.data());
                int64_t _i_current_price233 = tbl_Filter_TD_713861_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_627839_output.setInt32(r, 4, _inv_date_sk657);
                tbl_JOIN_INNER_TD_627839_output.setInt32(r, 0, _i_item_sk228);
                tbl_JOIN_INNER_TD_627839_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id229_n);
                tbl_JOIN_INNER_TD_627839_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_item_desc232_n);
                tbl_JOIN_INNER_TD_627839_output.setInt64(r, 3, _i_current_price233);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_627839_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_627839_output #Row: " << tbl_JOIN_INNER_TD_627839_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5734335(Table &tbl_SerializeFromObject_TD_6240181_input, Table &tbl_Filter_TD_5734335_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ss_item_sk#1208))
    // Input: ListBuffer(ss_item_sk#1208)
    // Output: ListBuffer(ss_item_sk#1208)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6240181_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_6240181_input.getInt32(i, 0);
        if (_ss_item_sk1208!= 0) {
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_6240181_input.getInt32(i, 0);
            tbl_Filter_TD_5734335_output.setInt32(r, 0, _ss_item_sk1208_t);
            r++;
        }
    }
    tbl_Filter_TD_5734335_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5734335_output #Row: " << tbl_Filter_TD_5734335_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5821750_key_leftMajor {
    int32_t _inv_date_sk657;
    bool operator==(const SW_JOIN_INNER_TD_5821750_key_leftMajor& other) const {
        return ((_inv_date_sk657 == other._inv_date_sk657));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5821750_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5821750_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._inv_date_sk657));
    }
};
}
struct SW_JOIN_INNER_TD_5821750_payload_leftMajor {
    int32_t _i_item_sk228;
    std::string _i_item_id229;
    std::string _i_item_desc232;
    int64_t _i_current_price233;
    int32_t _inv_date_sk657;
};
struct SW_JOIN_INNER_TD_5821750_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_5821750_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5821750_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5821750_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_5821750_payload_rightMajor {
    int32_t _d_date_sk120;
};
void SW_JOIN_INNER_TD_5821750(Table &tbl_JOIN_INNER_TD_627839_output, Table &tbl_Filter_TD_6971540_output, Table &tbl_JOIN_INNER_TD_5821750_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((d_date_sk#120 = inv_date_sk#657))
    // Left Table: ListBuffer(i_item_sk#228, i_item_id#229, i_item_desc#232, i_current_price#233, inv_date_sk#657)
    // Right Table: ListBuffer(d_date_sk#120)
    // Output Table: ListBuffer(i_item_sk#228, i_item_id#229, i_item_desc#232, i_current_price#233)
    int left_nrow = tbl_JOIN_INNER_TD_627839_output.getNumRow();
    int right_nrow = tbl_Filter_TD_6971540_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5821750_key_leftMajor, SW_JOIN_INNER_TD_5821750_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_627839_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _inv_date_sk657_k = tbl_JOIN_INNER_TD_627839_output.getInt32(i, 4);
            SW_JOIN_INNER_TD_5821750_key_leftMajor keyA{_inv_date_sk657_k};
            int32_t _i_item_sk228 = tbl_JOIN_INNER_TD_627839_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_JOIN_INNER_TD_627839_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_item_id229 = std::string(_i_item_id229_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n = tbl_JOIN_INNER_TD_627839_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _i_item_desc232 = std::string(_i_item_desc232_n.data());
            int64_t _i_current_price233 = tbl_JOIN_INNER_TD_627839_output.getInt64(i, 3);
            int32_t _inv_date_sk657 = tbl_JOIN_INNER_TD_627839_output.getInt32(i, 4);
            SW_JOIN_INNER_TD_5821750_payload_leftMajor payloadA{_i_item_sk228, _i_item_id229, _i_item_desc232, _i_current_price233, _inv_date_sk657};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6971540_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_6971540_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5821750_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                std::string _i_item_id229 = (it->second)._i_item_id229;
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n{};
                memcpy(_i_item_id229_n.data(), (_i_item_id229).data(), (_i_item_id229).length());
                std::string _i_item_desc232 = (it->second)._i_item_desc232;
                std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n{};
                memcpy(_i_item_desc232_n.data(), (_i_item_desc232).data(), (_i_item_desc232).length());
                int64_t _i_current_price233 = (it->second)._i_current_price233;
                int32_t _inv_date_sk657 = (it->second)._inv_date_sk657;
                int32_t _d_date_sk120 = tbl_Filter_TD_6971540_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_5821750_output.setInt32(r, 0, _i_item_sk228);
                tbl_JOIN_INNER_TD_5821750_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id229_n);
                tbl_JOIN_INNER_TD_5821750_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_item_desc232_n);
                tbl_JOIN_INNER_TD_5821750_output.setInt64(r, 3, _i_current_price233);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5821750_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5821750_key_rightMajor, SW_JOIN_INNER_TD_5821750_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_6971540_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_6971540_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5821750_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_6971540_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5821750_payload_rightMajor payloadA{_d_date_sk120};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_627839_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _inv_date_sk657_k = tbl_JOIN_INNER_TD_627839_output.getInt32(i, 4);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5821750_key_rightMajor{_inv_date_sk657_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _i_item_sk228 = tbl_JOIN_INNER_TD_627839_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_JOIN_INNER_TD_627839_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_item_id229 = std::string(_i_item_id229_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n = tbl_JOIN_INNER_TD_627839_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _i_item_desc232 = std::string(_i_item_desc232_n.data());
                int64_t _i_current_price233 = tbl_JOIN_INNER_TD_627839_output.getInt64(i, 3);
                int32_t _inv_date_sk657 = tbl_JOIN_INNER_TD_627839_output.getInt32(i, 4);
                tbl_JOIN_INNER_TD_5821750_output.setInt32(r, 0, _i_item_sk228);
                tbl_JOIN_INNER_TD_5821750_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id229_n);
                tbl_JOIN_INNER_TD_5821750_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_item_desc232_n);
                tbl_JOIN_INNER_TD_5821750_output.setInt64(r, 3, _i_current_price233);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5821750_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5821750_output #Row: " << tbl_JOIN_INNER_TD_5821750_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4106646_key_leftMajor {
    int32_t _i_item_sk228;
    bool operator==(const SW_JOIN_INNER_TD_4106646_key_leftMajor& other) const {
        return ((_i_item_sk228 == other._i_item_sk228));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4106646_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4106646_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk228));
    }
};
}
struct SW_JOIN_INNER_TD_4106646_payload_leftMajor {
    int32_t _i_item_sk228;
    std::string _i_item_id229;
    std::string _i_item_desc232;
    int64_t _i_current_price233;
};
struct SW_JOIN_INNER_TD_4106646_key_rightMajor {
    int32_t _ss_item_sk1208;
    bool operator==(const SW_JOIN_INNER_TD_4106646_key_rightMajor& other) const {
        return ((_ss_item_sk1208 == other._ss_item_sk1208));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4106646_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4106646_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk1208));
    }
};
}
struct SW_JOIN_INNER_TD_4106646_payload_rightMajor {
    int32_t _ss_item_sk1208;
};
void SW_JOIN_INNER_TD_4106646(Table &tbl_JOIN_INNER_TD_5821750_output, Table &tbl_Filter_TD_5734335_output, Table &tbl_JOIN_INNER_TD_4106646_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_item_sk#1208 = i_item_sk#228))
    // Left Table: ListBuffer(i_item_sk#228, i_item_id#229, i_item_desc#232, i_current_price#233)
    // Right Table: ListBuffer(ss_item_sk#1208)
    // Output Table: ListBuffer(i_item_id#229, i_item_desc#232, i_current_price#233)
    int left_nrow = tbl_JOIN_INNER_TD_5821750_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5734335_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4106646_key_leftMajor, SW_JOIN_INNER_TD_4106646_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_5821750_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk228_k = tbl_JOIN_INNER_TD_5821750_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4106646_key_leftMajor keyA{_i_item_sk228_k};
            int32_t _i_item_sk228 = tbl_JOIN_INNER_TD_5821750_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_JOIN_INNER_TD_5821750_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_item_id229 = std::string(_i_item_id229_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n = tbl_JOIN_INNER_TD_5821750_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _i_item_desc232 = std::string(_i_item_desc232_n.data());
            int64_t _i_current_price233 = tbl_JOIN_INNER_TD_5821750_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_4106646_payload_leftMajor payloadA{_i_item_sk228, _i_item_id229, _i_item_desc232, _i_current_price233};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5734335_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk1208_k = tbl_Filter_TD_5734335_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4106646_key_leftMajor{_ss_item_sk1208_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                std::string _i_item_id229 = (it->second)._i_item_id229;
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n{};
                memcpy(_i_item_id229_n.data(), (_i_item_id229).data(), (_i_item_id229).length());
                std::string _i_item_desc232 = (it->second)._i_item_desc232;
                std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n{};
                memcpy(_i_item_desc232_n.data(), (_i_item_desc232).data(), (_i_item_desc232).length());
                int64_t _i_current_price233 = (it->second)._i_current_price233;
                int32_t _ss_item_sk1208 = tbl_Filter_TD_5734335_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_4106646_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id229_n);
                tbl_JOIN_INNER_TD_4106646_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_desc232_n);
                tbl_JOIN_INNER_TD_4106646_output.setInt64(r, 2, _i_current_price233);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4106646_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4106646_key_rightMajor, SW_JOIN_INNER_TD_4106646_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5734335_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk1208_k = tbl_Filter_TD_5734335_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4106646_key_rightMajor keyA{_ss_item_sk1208_k};
            int32_t _ss_item_sk1208 = tbl_Filter_TD_5734335_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4106646_payload_rightMajor payloadA{_ss_item_sk1208};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_5821750_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk228_k = tbl_JOIN_INNER_TD_5821750_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4106646_key_rightMajor{_i_item_sk228_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _i_item_sk228 = tbl_JOIN_INNER_TD_5821750_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_JOIN_INNER_TD_5821750_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_item_id229 = std::string(_i_item_id229_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n = tbl_JOIN_INNER_TD_5821750_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _i_item_desc232 = std::string(_i_item_desc232_n.data());
                int64_t _i_current_price233 = tbl_JOIN_INNER_TD_5821750_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_4106646_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id229_n);
                tbl_JOIN_INNER_TD_4106646_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_desc232_n);
                tbl_JOIN_INNER_TD_4106646_output.setInt64(r, 2, _i_current_price233);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4106646_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4106646_output #Row: " << tbl_JOIN_INNER_TD_4106646_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_3716190_key {
    std::string _i_item_id229;
    std::string _i_item_desc232;
    int64_t _i_current_price233;
    bool operator==(const SW_Aggregate_TD_3716190_key& other) const { return (_i_item_id229 == other._i_item_id229) && (_i_item_desc232 == other._i_item_desc232) && (_i_current_price233 == other._i_current_price233); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_3716190_key> {
    std::size_t operator() (const SW_Aggregate_TD_3716190_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_item_id229)) + (hash<string>()(k._i_item_desc232)) + (hash<int64_t>()(k._i_current_price233));
    }
};
}
struct SW_Aggregate_TD_3716190_payload {
};
void SW_Aggregate_TD_3716190(Table &tbl_JOIN_INNER_TD_4106646_output, Table &tbl_Aggregate_TD_3716190_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(i_item_id#229, i_item_desc#232, i_current_price#233)
    // Input: ListBuffer(i_item_id#229, i_item_desc#232, i_current_price#233)
    // Output: ListBuffer(i_item_id#229, i_item_desc#232, i_current_price#233)
    std::unordered_map<SW_Aggregate_TD_3716190_key, SW_Aggregate_TD_3716190_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_4106646_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229 = tbl_JOIN_INNER_TD_4106646_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232 = tbl_JOIN_INNER_TD_4106646_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int64_t _i_current_price233 = tbl_JOIN_INNER_TD_4106646_output.getInt64(i, 2);
        SW_Aggregate_TD_3716190_key k{std::string(_i_item_id229.data()), std::string(_i_item_desc232.data()), _i_current_price233};
        SW_Aggregate_TD_3716190_payload p{};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229{};
        memcpy(_i_item_id229.data(), ((it.first)._i_item_id229).data(), ((it.first)._i_item_id229).length());
        tbl_Aggregate_TD_3716190_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id229);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232{};
        memcpy(_i_item_desc232.data(), ((it.first)._i_item_desc232).data(), ((it.first)._i_item_desc232).length());
        tbl_Aggregate_TD_3716190_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_desc232);
        tbl_Aggregate_TD_3716190_output.setInt64(r, 2, (it.first)._i_current_price233);
        ++r;
    }
    tbl_Aggregate_TD_3716190_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_3716190_output #Row: " << tbl_Aggregate_TD_3716190_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2302450(Table &tbl_Aggregate_TD_3716190_output, Table &tbl_Sort_TD_2302450_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(i_item_id#229 ASC NULLS FIRST)
    // Input: ListBuffer(i_item_id#229, i_item_desc#232, i_current_price#233)
    // Output: ListBuffer(i_item_id#229, i_item_desc#232, i_current_price#233)
    struct SW_Sort_TD_2302450Row {
        std::string _i_item_id229;
        std::string _i_item_desc232;
        int64_t _i_current_price233;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2302450Row& a, const SW_Sort_TD_2302450Row& b) const { return 
 (a._i_item_id229 < b._i_item_id229); 
}
    }SW_Sort_TD_2302450_order; 

    int nrow1 = tbl_Aggregate_TD_3716190_output.getNumRow();
    std::vector<SW_Sort_TD_2302450Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229 = tbl_Aggregate_TD_3716190_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232 = tbl_Aggregate_TD_3716190_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        int64_t _i_current_price233 = tbl_Aggregate_TD_3716190_output.getInt64(i, 2);
        SW_Sort_TD_2302450Row t = {std::string(_i_item_id229.data()),std::string(_i_item_desc232.data()),_i_current_price233};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2302450_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229{};
        memcpy(_i_item_id229.data(), (it._i_item_id229).data(), (it._i_item_id229).length());
        tbl_Sort_TD_2302450_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _i_item_id229);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232{};
        memcpy(_i_item_desc232.data(), (it._i_item_desc232).data(), (it._i_item_desc232).length());
        tbl_Sort_TD_2302450_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _i_item_desc232);
        tbl_Sort_TD_2302450_output.setInt64(r, 2, it._i_current_price233);
        if (r < 10) {
            std::cout << (it._i_item_id229).data() << " " << (it._i_item_desc232).data() << " " << it._i_current_price233 << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_2302450_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2302450_output #Row: " << tbl_Sort_TD_2302450_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1461457(Table &tbl_Sort_TD_2302450_output, Table &tbl_LocalLimit_TD_1461457_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(i_item_id#229, i_item_desc#232, i_current_price#233)
    // Output: ListBuffer(i_item_id#229, i_item_desc#232, i_current_price#233)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_Sort_TD_2302450_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1461457_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id229_n);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n = tbl_Sort_TD_2302450_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_1461457_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_desc232_n);
        tbl_LocalLimit_TD_1461457_output.setInt64(r, 2, tbl_Sort_TD_2302450_output.getInt64(i, 2));
        r++;
    }
    tbl_LocalLimit_TD_1461457_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1461457_output #Row: " << tbl_LocalLimit_TD_1461457_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0267483(Table &tbl_LocalLimit_TD_1461457_output, Table &tbl_GlobalLimit_TD_0267483_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(i_item_id#229, i_item_desc#232, i_current_price#233)
    // Output: ListBuffer(i_item_id#229, i_item_desc#232, i_current_price#233)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_LocalLimit_TD_1461457_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0267483_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id229_n);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n = tbl_LocalLimit_TD_1461457_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_0267483_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_desc232_n);
        tbl_GlobalLimit_TD_0267483_output.setInt64(r, 2, tbl_LocalLimit_TD_1461457_output.getInt64(i, 2));
        r++;
    }
    tbl_GlobalLimit_TD_0267483_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0267483_output #Row: " << tbl_GlobalLimit_TD_0267483_output.getNumRow() << std::endl;
}

