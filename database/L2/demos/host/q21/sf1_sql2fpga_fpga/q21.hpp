#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_8969129(Table &tbl_SerializeFromObject_TD_9286651_input, Table &tbl_Filter_TD_8969129_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(w_warehouse_sk#495))
    // Input: ListBuffer(w_warehouse_sk#495, w_warehouse_name#497)
    // Output: ListBuffer(w_warehouse_sk#495, w_warehouse_name#497)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9286651_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _w_warehouse_sk495 = tbl_SerializeFromObject_TD_9286651_input.getInt32(i, 0);
        if (_w_warehouse_sk495!= 0) {
            int32_t _w_warehouse_sk495_t = tbl_SerializeFromObject_TD_9286651_input.getInt32(i, 0);
            tbl_Filter_TD_8969129_output.setInt32(r, 0, _w_warehouse_sk495_t);
            std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_t = tbl_SerializeFromObject_TD_9286651_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_8969129_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _w_warehouse_name497_t);
            r++;
        }
    }
    tbl_Filter_TD_8969129_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8969129_output #Row: " << tbl_Filter_TD_8969129_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8562041(Table &tbl_SerializeFromObject_TD_9969271_input, Table &tbl_Filter_TD_8562041_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(inv_warehouse_sk#659) AND (isnotnull(inv_item_sk#658) AND isnotnull(inv_date_sk#657))))
    // Input: ListBuffer(inv_date_sk#657, inv_item_sk#658, inv_warehouse_sk#659, inv_quantity_on_hand#660)
    // Output: ListBuffer(inv_date_sk#657, inv_item_sk#658, inv_warehouse_sk#659, inv_quantity_on_hand#660)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9969271_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _inv_warehouse_sk659 = tbl_SerializeFromObject_TD_9969271_input.getInt32(i, 2);
        int32_t _inv_item_sk658 = tbl_SerializeFromObject_TD_9969271_input.getInt32(i, 1);
        int32_t _inv_date_sk657 = tbl_SerializeFromObject_TD_9969271_input.getInt32(i, 0);
        if ((_inv_warehouse_sk659!= 0) && ((_inv_item_sk658!= 0) && (_inv_date_sk657!= 0))) {
            int32_t _inv_date_sk657_t = tbl_SerializeFromObject_TD_9969271_input.getInt32(i, 0);
            tbl_Filter_TD_8562041_output.setInt32(r, 0, _inv_date_sk657_t);
            int32_t _inv_item_sk658_t = tbl_SerializeFromObject_TD_9969271_input.getInt32(i, 1);
            tbl_Filter_TD_8562041_output.setInt32(r, 1, _inv_item_sk658_t);
            int32_t _inv_warehouse_sk659_t = tbl_SerializeFromObject_TD_9969271_input.getInt32(i, 2);
            tbl_Filter_TD_8562041_output.setInt32(r, 2, _inv_warehouse_sk659_t);
            int32_t _inv_quantity_on_hand660_t = tbl_SerializeFromObject_TD_9969271_input.getInt32(i, 3);
            tbl_Filter_TD_8562041_output.setInt32(r, 3, _inv_quantity_on_hand660_t);
            r++;
        }
    }
    tbl_Filter_TD_8562041_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8562041_output #Row: " << tbl_Filter_TD_8562041_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7227204(Table &tbl_SerializeFromObject_TD_8809267_input, Table &tbl_Filter_TD_7227204_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(i_current_price#233) AND ((i_current_price#233 >= 0.99) AND (i_current_price#233 <= 1.49))) AND isnotnull(i_item_sk#228)))
    // Input: ListBuffer(i_item_sk#228, i_item_id#229, i_current_price#233)
    // Output: ListBuffer(i_item_sk#228, i_item_id#229)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8809267_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _i_current_price233 = tbl_SerializeFromObject_TD_8809267_input.getInt64(i, 2);
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_8809267_input.getInt32(i, 0);
        if (((_i_current_price233!= 0) && ((_i_current_price233 >= 0.99) && (_i_current_price233 <= 1.49))) && (_i_item_sk228!= 0)) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_8809267_input.getInt32(i, 0);
            tbl_Filter_TD_7227204_output.setInt32(r, 0, _i_item_sk228_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_t = tbl_SerializeFromObject_TD_8809267_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_7227204_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id229_t);
            r++;
        }
    }
    tbl_Filter_TD_7227204_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7227204_output #Row: " << tbl_Filter_TD_7227204_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_7304750_key_leftMajor {
    int32_t _inv_warehouse_sk659;
    bool operator==(const SW_JOIN_INNER_TD_7304750_key_leftMajor& other) const {
        return ((_inv_warehouse_sk659 == other._inv_warehouse_sk659));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7304750_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7304750_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._inv_warehouse_sk659));
    }
};
}
struct SW_JOIN_INNER_TD_7304750_payload_leftMajor {
    int32_t _inv_date_sk657;
    int32_t _inv_item_sk658;
    int32_t _inv_warehouse_sk659;
    int32_t _inv_quantity_on_hand660;
};
struct SW_JOIN_INNER_TD_7304750_key_rightMajor {
    int32_t _w_warehouse_sk495;
    bool operator==(const SW_JOIN_INNER_TD_7304750_key_rightMajor& other) const {
        return ((_w_warehouse_sk495 == other._w_warehouse_sk495));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7304750_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7304750_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._w_warehouse_sk495));
    }
};
}
struct SW_JOIN_INNER_TD_7304750_payload_rightMajor {
    int32_t _w_warehouse_sk495;
    std::string _w_warehouse_name497;
};
void SW_JOIN_INNER_TD_7304750(Table &tbl_Filter_TD_8562041_output, Table &tbl_Filter_TD_8969129_output, Table &tbl_JOIN_INNER_TD_7304750_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((inv_warehouse_sk#659 = w_warehouse_sk#495))
    // Left Table: ListBuffer(inv_date_sk#657, inv_item_sk#658, inv_warehouse_sk#659, inv_quantity_on_hand#660)
    // Right Table: ListBuffer(w_warehouse_sk#495, w_warehouse_name#497)
    // Output Table: ListBuffer(inv_date_sk#657, inv_item_sk#658, inv_quantity_on_hand#660, w_warehouse_name#497)
    int left_nrow = tbl_Filter_TD_8562041_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8969129_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7304750_key_leftMajor, SW_JOIN_INNER_TD_7304750_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_8562041_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _inv_warehouse_sk659_k = tbl_Filter_TD_8562041_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_7304750_key_leftMajor keyA{_inv_warehouse_sk659_k};
            int32_t _inv_date_sk657 = tbl_Filter_TD_8562041_output.getInt32(i, 0);
            int32_t _inv_item_sk658 = tbl_Filter_TD_8562041_output.getInt32(i, 1);
            int32_t _inv_warehouse_sk659 = tbl_Filter_TD_8562041_output.getInt32(i, 2);
            int32_t _inv_quantity_on_hand660 = tbl_Filter_TD_8562041_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_7304750_payload_leftMajor payloadA{_inv_date_sk657, _inv_item_sk658, _inv_warehouse_sk659, _inv_quantity_on_hand660};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8969129_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _w_warehouse_sk495_k = tbl_Filter_TD_8969129_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7304750_key_leftMajor{_w_warehouse_sk495_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _inv_date_sk657 = (it->second)._inv_date_sk657;
                int32_t _inv_item_sk658 = (it->second)._inv_item_sk658;
                int32_t _inv_warehouse_sk659 = (it->second)._inv_warehouse_sk659;
                int32_t _inv_quantity_on_hand660 = (it->second)._inv_quantity_on_hand660;
                int32_t _w_warehouse_sk495 = tbl_Filter_TD_8969129_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_Filter_TD_8969129_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
                tbl_JOIN_INNER_TD_7304750_output.setInt32(r, 0, _inv_date_sk657);
                tbl_JOIN_INNER_TD_7304750_output.setInt32(r, 1, _inv_item_sk658);
                tbl_JOIN_INNER_TD_7304750_output.setInt32(r, 2, _inv_quantity_on_hand660);
                tbl_JOIN_INNER_TD_7304750_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _w_warehouse_name497_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7304750_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7304750_key_rightMajor, SW_JOIN_INNER_TD_7304750_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8969129_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _w_warehouse_sk495_k = tbl_Filter_TD_8969129_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7304750_key_rightMajor keyA{_w_warehouse_sk495_k};
            int32_t _w_warehouse_sk495 = tbl_Filter_TD_8969129_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_Filter_TD_8969129_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
            SW_JOIN_INNER_TD_7304750_payload_rightMajor payloadA{_w_warehouse_sk495, _w_warehouse_name497};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8562041_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _inv_warehouse_sk659_k = tbl_Filter_TD_8562041_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7304750_key_rightMajor{_inv_warehouse_sk659_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _w_warehouse_sk495 = (it->second)._w_warehouse_sk495;
                std::string _w_warehouse_name497 = (it->second)._w_warehouse_name497;
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n{};
                memcpy(_w_warehouse_name497_n.data(), (_w_warehouse_name497).data(), (_w_warehouse_name497).length());
                int32_t _inv_date_sk657 = tbl_Filter_TD_8562041_output.getInt32(i, 0);
                int32_t _inv_item_sk658 = tbl_Filter_TD_8562041_output.getInt32(i, 1);
                int32_t _inv_warehouse_sk659 = tbl_Filter_TD_8562041_output.getInt32(i, 2);
                int32_t _inv_quantity_on_hand660 = tbl_Filter_TD_8562041_output.getInt32(i, 3);
                tbl_JOIN_INNER_TD_7304750_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _w_warehouse_name497_n);
                tbl_JOIN_INNER_TD_7304750_output.setInt32(r, 0, _inv_date_sk657);
                tbl_JOIN_INNER_TD_7304750_output.setInt32(r, 1, _inv_item_sk658);
                tbl_JOIN_INNER_TD_7304750_output.setInt32(r, 2, _inv_quantity_on_hand660);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7304750_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7304750_output #Row: " << tbl_JOIN_INNER_TD_7304750_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6896397(Table &tbl_SerializeFromObject_TD_7952618_input, Table &tbl_Filter_TD_6896397_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_date#122) AND ((d_date#122 >= 2000-02-10) AND (d_date#122 <= 2000-04-10))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_date#122)
    // Output: ListBuffer(d_date_sk#120, d_date#122)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7952618_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date122 = tbl_SerializeFromObject_TD_7952618_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_7952618_input.getInt32(i, 0);
        if (((_d_date122!= 0) && ((_d_date122 >= 20000210) && (_d_date122 <= 20000410))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_7952618_input.getInt32(i, 0);
            tbl_Filter_TD_6896397_output.setInt32(r, 0, _d_date_sk120_t);
            int32_t _d_date122_t = tbl_SerializeFromObject_TD_7952618_input.getInt32(i, 1);
            tbl_Filter_TD_6896397_output.setInt32(r, 1, _d_date122_t);
            r++;
        }
    }
    tbl_Filter_TD_6896397_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6896397_output #Row: " << tbl_Filter_TD_6896397_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6218165_key_leftMajor {
    int32_t _inv_item_sk658;
    bool operator==(const SW_JOIN_INNER_TD_6218165_key_leftMajor& other) const {
        return ((_inv_item_sk658 == other._inv_item_sk658));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6218165_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6218165_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._inv_item_sk658));
    }
};
}
struct SW_JOIN_INNER_TD_6218165_payload_leftMajor {
    int32_t _inv_date_sk657;
    int32_t _inv_item_sk658;
    int32_t _inv_quantity_on_hand660;
    std::string _w_warehouse_name497;
};
struct SW_JOIN_INNER_TD_6218165_key_rightMajor {
    int32_t _i_item_sk228;
    bool operator==(const SW_JOIN_INNER_TD_6218165_key_rightMajor& other) const {
        return ((_i_item_sk228 == other._i_item_sk228));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6218165_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6218165_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk228));
    }
};
}
struct SW_JOIN_INNER_TD_6218165_payload_rightMajor {
    int32_t _i_item_sk228;
    std::string _i_item_id229;
};
void SW_JOIN_INNER_TD_6218165(Table &tbl_JOIN_INNER_TD_7304750_output, Table &tbl_Filter_TD_7227204_output, Table &tbl_JOIN_INNER_TD_6218165_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((i_item_sk#228 = inv_item_sk#658))
    // Left Table: ListBuffer(inv_date_sk#657, inv_item_sk#658, inv_quantity_on_hand#660, w_warehouse_name#497)
    // Right Table: ListBuffer(i_item_sk#228, i_item_id#229)
    // Output Table: ListBuffer(inv_date_sk#657, inv_quantity_on_hand#660, w_warehouse_name#497, i_item_id#229)
    int left_nrow = tbl_JOIN_INNER_TD_7304750_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7227204_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6218165_key_leftMajor, SW_JOIN_INNER_TD_6218165_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7304750_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _inv_item_sk658_k = tbl_JOIN_INNER_TD_7304750_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_6218165_key_leftMajor keyA{_inv_item_sk658_k};
            int32_t _inv_date_sk657 = tbl_JOIN_INNER_TD_7304750_output.getInt32(i, 0);
            int32_t _inv_item_sk658 = tbl_JOIN_INNER_TD_7304750_output.getInt32(i, 1);
            int32_t _inv_quantity_on_hand660 = tbl_JOIN_INNER_TD_7304750_output.getInt32(i, 2);
            std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_JOIN_INNER_TD_7304750_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
            SW_JOIN_INNER_TD_6218165_payload_leftMajor payloadA{_inv_date_sk657, _inv_item_sk658, _inv_quantity_on_hand660, _w_warehouse_name497};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7227204_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_7227204_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6218165_key_leftMajor{_i_item_sk228_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _inv_date_sk657 = (it->second)._inv_date_sk657;
                int32_t _inv_item_sk658 = (it->second)._inv_item_sk658;
                int32_t _inv_quantity_on_hand660 = (it->second)._inv_quantity_on_hand660;
                std::string _w_warehouse_name497 = (it->second)._w_warehouse_name497;
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n{};
                memcpy(_w_warehouse_name497_n.data(), (_w_warehouse_name497).data(), (_w_warehouse_name497).length());
                int32_t _i_item_sk228 = tbl_Filter_TD_7227204_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_Filter_TD_7227204_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_item_id229 = std::string(_i_item_id229_n.data());
                tbl_JOIN_INNER_TD_6218165_output.setInt32(r, 0, _inv_date_sk657);
                tbl_JOIN_INNER_TD_6218165_output.setInt32(r, 1, _inv_quantity_on_hand660);
                tbl_JOIN_INNER_TD_6218165_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _w_warehouse_name497_n);
                tbl_JOIN_INNER_TD_6218165_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _i_item_id229_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6218165_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6218165_key_rightMajor, SW_JOIN_INNER_TD_6218165_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7227204_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_7227204_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6218165_key_rightMajor keyA{_i_item_sk228_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_7227204_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_Filter_TD_7227204_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_item_id229 = std::string(_i_item_id229_n.data());
            SW_JOIN_INNER_TD_6218165_payload_rightMajor payloadA{_i_item_sk228, _i_item_id229};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7304750_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _inv_item_sk658_k = tbl_JOIN_INNER_TD_7304750_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6218165_key_rightMajor{_inv_item_sk658_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                std::string _i_item_id229 = (it->second)._i_item_id229;
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n{};
                memcpy(_i_item_id229_n.data(), (_i_item_id229).data(), (_i_item_id229).length());
                int32_t _inv_date_sk657 = tbl_JOIN_INNER_TD_7304750_output.getInt32(i, 0);
                int32_t _inv_item_sk658 = tbl_JOIN_INNER_TD_7304750_output.getInt32(i, 1);
                int32_t _inv_quantity_on_hand660 = tbl_JOIN_INNER_TD_7304750_output.getInt32(i, 2);
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_JOIN_INNER_TD_7304750_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
                tbl_JOIN_INNER_TD_6218165_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _i_item_id229_n);
                tbl_JOIN_INNER_TD_6218165_output.setInt32(r, 0, _inv_date_sk657);
                tbl_JOIN_INNER_TD_6218165_output.setInt32(r, 1, _inv_quantity_on_hand660);
                tbl_JOIN_INNER_TD_6218165_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _w_warehouse_name497_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6218165_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6218165_output #Row: " << tbl_JOIN_INNER_TD_6218165_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5737030_key_leftMajor {
    int32_t _inv_date_sk657;
    bool operator==(const SW_JOIN_INNER_TD_5737030_key_leftMajor& other) const {
        return ((_inv_date_sk657 == other._inv_date_sk657));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5737030_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5737030_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._inv_date_sk657));
    }
};
}
struct SW_JOIN_INNER_TD_5737030_payload_leftMajor {
    int32_t _inv_date_sk657;
    int32_t _inv_quantity_on_hand660;
    std::string _w_warehouse_name497;
    std::string _i_item_id229;
};
struct SW_JOIN_INNER_TD_5737030_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_5737030_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5737030_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5737030_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_5737030_payload_rightMajor {
    int32_t _d_date_sk120;
    int32_t _d_date122;
};
void SW_JOIN_INNER_TD_5737030(Table &tbl_JOIN_INNER_TD_6218165_output, Table &tbl_Filter_TD_6896397_output, Table &tbl_JOIN_INNER_TD_5737030_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((inv_date_sk#657 = d_date_sk#120))
    // Left Table: ListBuffer(inv_date_sk#657, inv_quantity_on_hand#660, w_warehouse_name#497, i_item_id#229)
    // Right Table: ListBuffer(d_date_sk#120, d_date#122)
    // Output Table: ListBuffer(inv_quantity_on_hand#660, w_warehouse_name#497, i_item_id#229, d_date#122)
    int left_nrow = tbl_JOIN_INNER_TD_6218165_output.getNumRow();
    int right_nrow = tbl_Filter_TD_6896397_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5737030_key_leftMajor, SW_JOIN_INNER_TD_5737030_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_6218165_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _inv_date_sk657_k = tbl_JOIN_INNER_TD_6218165_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5737030_key_leftMajor keyA{_inv_date_sk657_k};
            int32_t _inv_date_sk657 = tbl_JOIN_INNER_TD_6218165_output.getInt32(i, 0);
            int32_t _inv_quantity_on_hand660 = tbl_JOIN_INNER_TD_6218165_output.getInt32(i, 1);
            std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_JOIN_INNER_TD_6218165_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_JOIN_INNER_TD_6218165_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _i_item_id229 = std::string(_i_item_id229_n.data());
            SW_JOIN_INNER_TD_5737030_payload_leftMajor payloadA{_inv_date_sk657, _inv_quantity_on_hand660, _w_warehouse_name497, _i_item_id229};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6896397_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_6896397_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5737030_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _inv_date_sk657 = (it->second)._inv_date_sk657;
                int32_t _inv_quantity_on_hand660 = (it->second)._inv_quantity_on_hand660;
                std::string _w_warehouse_name497 = (it->second)._w_warehouse_name497;
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n{};
                memcpy(_w_warehouse_name497_n.data(), (_w_warehouse_name497).data(), (_w_warehouse_name497).length());
                std::string _i_item_id229 = (it->second)._i_item_id229;
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n{};
                memcpy(_i_item_id229_n.data(), (_i_item_id229).data(), (_i_item_id229).length());
                int32_t _d_date_sk120 = tbl_Filter_TD_6896397_output.getInt32(i, 0);
                int32_t _d_date122 = tbl_Filter_TD_6896397_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_5737030_output.setInt32(r, 0, _inv_quantity_on_hand660);
                tbl_JOIN_INNER_TD_5737030_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _w_warehouse_name497_n);
                tbl_JOIN_INNER_TD_5737030_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_item_id229_n);
                tbl_JOIN_INNER_TD_5737030_output.setInt32(r, 3, _d_date122);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5737030_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5737030_key_rightMajor, SW_JOIN_INNER_TD_5737030_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_6896397_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_6896397_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5737030_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_6896397_output.getInt32(i, 0);
            int32_t _d_date122 = tbl_Filter_TD_6896397_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_5737030_payload_rightMajor payloadA{_d_date_sk120, _d_date122};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_6218165_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _inv_date_sk657_k = tbl_JOIN_INNER_TD_6218165_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5737030_key_rightMajor{_inv_date_sk657_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _d_date122 = (it->second)._d_date122;
                int32_t _inv_date_sk657 = tbl_JOIN_INNER_TD_6218165_output.getInt32(i, 0);
                int32_t _inv_quantity_on_hand660 = tbl_JOIN_INNER_TD_6218165_output.getInt32(i, 1);
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_JOIN_INNER_TD_6218165_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_JOIN_INNER_TD_6218165_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _i_item_id229 = std::string(_i_item_id229_n.data());
                tbl_JOIN_INNER_TD_5737030_output.setInt32(r, 3, _d_date122);
                tbl_JOIN_INNER_TD_5737030_output.setInt32(r, 0, _inv_quantity_on_hand660);
                tbl_JOIN_INNER_TD_5737030_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _w_warehouse_name497_n);
                tbl_JOIN_INNER_TD_5737030_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_item_id229_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5737030_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5737030_output #Row: " << tbl_JOIN_INNER_TD_5737030_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_4230421_key {
    std::string _w_warehouse_name497;
    std::string _i_item_id229;
    bool operator==(const SW_Aggregate_TD_4230421_key& other) const { return (_w_warehouse_name497 == other._w_warehouse_name497) && (_i_item_id229 == other._i_item_id229); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_4230421_key> {
    std::size_t operator() (const SW_Aggregate_TD_4230421_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._w_warehouse_name497)) + (hash<string>()(k._i_item_id229));
    }
};
}
struct SW_Aggregate_TD_4230421_payload {
    int64_t _inv_before3544L_sum_0;
    int64_t _inv_after3545L_sum_1;
};
void SW_Aggregate_TD_4230421(Table &tbl_JOIN_INNER_TD_5737030_output, Table &tbl_Aggregate_TD_4230421_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(w_warehouse_name#497, i_item_id#229, sum(CASE WHEN (d_date#122 < 2000-03-11) THEN inv_quantity_on_hand#660 ELSE 0 END) AS inv_before#3544L, sum(CASE WHEN (d_date#122 >= 2000-03-11) THEN inv_quantity_on_hand#660 ELSE 0 END) AS inv_after#3545L)
    // Input: ListBuffer(inv_quantity_on_hand#660, w_warehouse_name#497, i_item_id#229, d_date#122)
    // Output: ListBuffer(w_warehouse_name#497, i_item_id#229, inv_before#3544L, inv_after#3545L)
    std::unordered_map<SW_Aggregate_TD_4230421_key, SW_Aggregate_TD_4230421_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_5737030_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _inv_quantity_on_hand660 = tbl_JOIN_INNER_TD_5737030_output.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497 = tbl_JOIN_INNER_TD_5737030_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229 = tbl_JOIN_INNER_TD_5737030_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        int32_t _d_date122 = tbl_JOIN_INNER_TD_5737030_output.getInt32(i, 3);
        SW_Aggregate_TD_4230421_key k{std::string(_w_warehouse_name497.data()), std::string(_i_item_id229.data())};
        int64_t _inv_before3544L_sum_0 = (_d_date122 < 2000-03-11) ? _inv_quantity_on_hand660 : 0;
        int64_t _inv_after3545L_sum_1 = (_d_date122 >= 2000-03-11) ? _inv_quantity_on_hand660 : 0;
        SW_Aggregate_TD_4230421_payload p{_inv_before3544L_sum_0, _inv_after3545L_sum_1};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._inv_before3544L_sum_0 + _inv_before3544L_sum_0;
            p._inv_before3544L_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._inv_after3545L_sum_1 + _inv_after3545L_sum_1;
            p._inv_after3545L_sum_1 = sum_1;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497{};
        memcpy(_w_warehouse_name497.data(), ((it.first)._w_warehouse_name497).data(), ((it.first)._w_warehouse_name497).length());
        tbl_Aggregate_TD_4230421_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _w_warehouse_name497);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229{};
        memcpy(_i_item_id229.data(), ((it.first)._i_item_id229).data(), ((it.first)._i_item_id229).length());
        tbl_Aggregate_TD_4230421_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id229);
        int64_t _inv_before3544L = (it.second)._inv_before3544L_sum_0;
        tbl_Aggregate_TD_4230421_output.setInt64(r, 2, _inv_before3544L);
        int64_t _inv_after3545L = (it.second)._inv_after3545L_sum_1;
        tbl_Aggregate_TD_4230421_output.setInt64(r, 3, _inv_after3545L);
        ++r;
    }
    tbl_Aggregate_TD_4230421_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_4230421_output #Row: " << tbl_Aggregate_TD_4230421_output.getNumRow() << std::endl;
}

void SW_Filter_TD_3950469(Table &tbl_Aggregate_TD_4230421_output, Table &tbl_Filter_TD_3950469_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(inv_before#3544L) AND isnotnull(inv_after#3545L)) AND (((inv_before#3544L > 0) AND ((cast(inv_after#3545L as double) / cast(inv_before#3544L as double)) >= 0.666667)) AND ((cast(inv_after#3545L as double) / cast(inv_before#3544L as double)) <= 1.5))))
    // Input: ListBuffer(w_warehouse_name#497, i_item_id#229, inv_before#3544L, inv_after#3545L)
    // Output: ListBuffer(w_warehouse_name#497, i_item_id#229, inv_before#3544L, inv_after#3545L)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_4230421_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _inv_before3544L = tbl_Aggregate_TD_4230421_output.getInt64(i, 2);
        int64_t _inv_after3545L = tbl_Aggregate_TD_4230421_output.getInt64(i, 3);
        if (((_inv_before3544L!= 0) && (_inv_after3545L!= 0)) && (((_inv_before3544L > 0) && (_inv_after3545L >= 0.666667)) && (_inv_after3545L <= 1.5))) {
            std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_t = tbl_Aggregate_TD_4230421_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            tbl_Filter_TD_3950469_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _w_warehouse_name497_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_t = tbl_Aggregate_TD_4230421_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_3950469_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id229_t);
            int64_t _inv_before3544L_t = tbl_Aggregate_TD_4230421_output.getInt64(i, 2);
            tbl_Filter_TD_3950469_output.setInt64(r, 2, _inv_before3544L_t);
            int64_t _inv_after3545L_t = tbl_Aggregate_TD_4230421_output.getInt64(i, 3);
            tbl_Filter_TD_3950469_output.setInt64(r, 3, _inv_after3545L_t);
            r++;
        }
    }
    tbl_Filter_TD_3950469_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_3950469_output #Row: " << tbl_Filter_TD_3950469_output.getNumRow() << std::endl;
}

void SW_Sort_TD_264578(Table &tbl_Filter_TD_3950469_output, Table &tbl_Sort_TD_264578_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(w_warehouse_name#497 ASC NULLS FIRST, i_item_id#229 ASC NULLS FIRST)
    // Input: ListBuffer(w_warehouse_name#497, i_item_id#229, inv_before#3544L, inv_after#3545L)
    // Output: ListBuffer(w_warehouse_name#497, i_item_id#229, inv_before#3544L, inv_after#3545L)
    struct SW_Sort_TD_264578Row {
        std::string _w_warehouse_name497;
        std::string _i_item_id229;
        int64_t _inv_before3544L;
        int64_t _inv_after3545L;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_264578Row& a, const SW_Sort_TD_264578Row& b) const { return 
 (a._w_warehouse_name497 < b._w_warehouse_name497) || 
 ((a._w_warehouse_name497 == b._w_warehouse_name497) && (a._i_item_id229 < b._i_item_id229)); 
}
    }SW_Sort_TD_264578_order; 

    int nrow1 = tbl_Filter_TD_3950469_output.getNumRow();
    std::vector<SW_Sort_TD_264578Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497 = tbl_Filter_TD_3950469_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229 = tbl_Filter_TD_3950469_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        int64_t _inv_before3544L = tbl_Filter_TD_3950469_output.getInt64(i, 2);
        int64_t _inv_after3545L = tbl_Filter_TD_3950469_output.getInt64(i, 3);
        SW_Sort_TD_264578Row t = {std::string(_w_warehouse_name497.data()),std::string(_i_item_id229.data()),_inv_before3544L,_inv_after3545L};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_264578_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497{};
        memcpy(_w_warehouse_name497.data(), (it._w_warehouse_name497).data(), (it._w_warehouse_name497).length());
        tbl_Sort_TD_264578_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _w_warehouse_name497);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229{};
        memcpy(_i_item_id229.data(), (it._i_item_id229).data(), (it._i_item_id229).length());
        tbl_Sort_TD_264578_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _i_item_id229);
        tbl_Sort_TD_264578_output.setInt64(r, 2, it._inv_before3544L);
        tbl_Sort_TD_264578_output.setInt64(r, 3, it._inv_after3545L);
        ++r;
    }
    tbl_Sort_TD_264578_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_264578_output #Row: " << tbl_Sort_TD_264578_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1953724(Table &tbl_Sort_TD_264578_output, Table &tbl_LocalLimit_TD_1953724_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(w_warehouse_name#497, i_item_id#229, inv_before#3544L, inv_after#3545L)
    // Output: ListBuffer(w_warehouse_name#497, i_item_id#229, inv_before#3544L, inv_after#3545L)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_Sort_TD_264578_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1953724_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _w_warehouse_name497_n);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_Sort_TD_264578_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_1953724_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id229_n);
        tbl_LocalLimit_TD_1953724_output.setInt64(r, 2, tbl_Sort_TD_264578_output.getInt64(i, 2));
        tbl_LocalLimit_TD_1953724_output.setInt64(r, 3, tbl_Sort_TD_264578_output.getInt64(i, 3));
        r++;
    }
    tbl_LocalLimit_TD_1953724_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1953724_output #Row: " << tbl_LocalLimit_TD_1953724_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0564374(Table &tbl_LocalLimit_TD_1953724_output, Table &tbl_GlobalLimit_TD_0564374_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(w_warehouse_name#497, i_item_id#229, inv_before#3544L, inv_after#3545L)
    // Output: ListBuffer(w_warehouse_name#497, i_item_id#229, inv_before#3544L, inv_after#3545L)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_LocalLimit_TD_1953724_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0564374_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _w_warehouse_name497_n);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_LocalLimit_TD_1953724_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_0564374_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id229_n);
        tbl_GlobalLimit_TD_0564374_output.setInt64(r, 2, tbl_LocalLimit_TD_1953724_output.getInt64(i, 2));
        tbl_GlobalLimit_TD_0564374_output.setInt64(r, 3, tbl_LocalLimit_TD_1953724_output.getInt64(i, 3));
        r++;
    }
    tbl_GlobalLimit_TD_0564374_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0564374_output #Row: " << tbl_GlobalLimit_TD_0564374_output.getNumRow() << std::endl;
}

