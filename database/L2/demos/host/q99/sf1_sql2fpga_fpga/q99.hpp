#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_9837484(Table &tbl_SerializeFromObject_TD_10543223_input, Table &tbl_Filter_TD_9837484_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(w_warehouse_sk#495))
    // Input: ListBuffer(w_warehouse_sk#495, w_warehouse_name#497)
    // Output: ListBuffer(w_warehouse_sk#495, w_warehouse_name#497)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10543223_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _w_warehouse_sk495 = tbl_SerializeFromObject_TD_10543223_input.getInt32(i, 0);
        if (_w_warehouse_sk495!= 0) {
            int32_t _w_warehouse_sk495_t = tbl_SerializeFromObject_TD_10543223_input.getInt32(i, 0);
            tbl_Filter_TD_9837484_output.setInt32(r, 0, _w_warehouse_sk495_t);
            std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_t = tbl_SerializeFromObject_TD_10543223_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_9837484_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _w_warehouse_name497_t);
            r++;
        }
    }
    tbl_Filter_TD_9837484_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9837484_output #Row: " << tbl_Filter_TD_9837484_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9736564(Table &tbl_SerializeFromObject_TD_10637158_input, Table &tbl_Filter_TD_9736564_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(cs_warehouse_sk#1118) AND isnotnull(cs_ship_mode_sk#1117)) AND (isnotnull(cs_call_center_sk#1115) AND isnotnull(cs_ship_date_sk#1106))))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_ship_date_sk#1106, cs_call_center_sk#1115, cs_ship_mode_sk#1117, cs_warehouse_sk#1118)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_ship_date_sk#1106, cs_call_center_sk#1115, cs_ship_mode_sk#1117, cs_warehouse_sk#1118)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10637158_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_warehouse_sk1118 = tbl_SerializeFromObject_TD_10637158_input.getInt32(i, 4);
        int32_t _cs_ship_mode_sk1117 = tbl_SerializeFromObject_TD_10637158_input.getInt32(i, 3);
        int32_t _cs_call_center_sk1115 = tbl_SerializeFromObject_TD_10637158_input.getInt32(i, 2);
        int32_t _cs_ship_date_sk1106 = tbl_SerializeFromObject_TD_10637158_input.getInt32(i, 1);
        if (((_cs_warehouse_sk1118!= 0) && (_cs_ship_mode_sk1117!= 0)) && ((_cs_call_center_sk1115!= 0) && (_cs_ship_date_sk1106!= 0))) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_10637158_input.getInt32(i, 0);
            tbl_Filter_TD_9736564_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int32_t _cs_ship_date_sk1106_t = tbl_SerializeFromObject_TD_10637158_input.getInt32(i, 1);
            tbl_Filter_TD_9736564_output.setInt32(r, 1, _cs_ship_date_sk1106_t);
            int32_t _cs_call_center_sk1115_t = tbl_SerializeFromObject_TD_10637158_input.getInt32(i, 2);
            tbl_Filter_TD_9736564_output.setInt32(r, 2, _cs_call_center_sk1115_t);
            int32_t _cs_ship_mode_sk1117_t = tbl_SerializeFromObject_TD_10637158_input.getInt32(i, 3);
            tbl_Filter_TD_9736564_output.setInt32(r, 3, _cs_ship_mode_sk1117_t);
            int32_t _cs_warehouse_sk1118_t = tbl_SerializeFromObject_TD_10637158_input.getInt32(i, 4);
            tbl_Filter_TD_9736564_output.setInt32(r, 4, _cs_warehouse_sk1118_t);
            r++;
        }
    }
    tbl_Filter_TD_9736564_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9736564_output #Row: " << tbl_Filter_TD_9736564_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8794558(Table &tbl_SerializeFromObject_TD_9288641_input, Table &tbl_Filter_TD_8794558_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(sm_ship_mode_sk#360))
    // Input: ListBuffer(sm_ship_mode_sk#360, sm_type#362)
    // Output: ListBuffer(sm_ship_mode_sk#360, sm_type#362)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9288641_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _sm_ship_mode_sk360 = tbl_SerializeFromObject_TD_9288641_input.getInt32(i, 0);
        if (_sm_ship_mode_sk360!= 0) {
            int32_t _sm_ship_mode_sk360_t = tbl_SerializeFromObject_TD_9288641_input.getInt32(i, 0);
            tbl_Filter_TD_8794558_output.setInt32(r, 0, _sm_ship_mode_sk360_t);
            std::array<char, TPCDS_READ_MAX + 1> _sm_type362_t = tbl_SerializeFromObject_TD_9288641_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_8794558_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _sm_type362_t);
            r++;
        }
    }
    tbl_Filter_TD_8794558_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8794558_output #Row: " << tbl_Filter_TD_8794558_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8387172_key_leftMajor {
    int32_t _cs_warehouse_sk1118;
    bool operator==(const SW_JOIN_INNER_TD_8387172_key_leftMajor& other) const {
        return ((_cs_warehouse_sk1118 == other._cs_warehouse_sk1118));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8387172_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8387172_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_warehouse_sk1118));
    }
};
}
struct SW_JOIN_INNER_TD_8387172_payload_leftMajor {
    int32_t _cs_sold_date_sk1104;
    int32_t _cs_ship_date_sk1106;
    int32_t _cs_call_center_sk1115;
    int32_t _cs_ship_mode_sk1117;
    int32_t _cs_warehouse_sk1118;
};
struct SW_JOIN_INNER_TD_8387172_key_rightMajor {
    int32_t _w_warehouse_sk495;
    bool operator==(const SW_JOIN_INNER_TD_8387172_key_rightMajor& other) const {
        return ((_w_warehouse_sk495 == other._w_warehouse_sk495));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8387172_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8387172_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._w_warehouse_sk495));
    }
};
}
struct SW_JOIN_INNER_TD_8387172_payload_rightMajor {
    int32_t _w_warehouse_sk495;
    std::string _w_warehouse_name497;
};
void SW_JOIN_INNER_TD_8387172(Table &tbl_Filter_TD_9736564_output, Table &tbl_Filter_TD_9837484_output, Table &tbl_JOIN_INNER_TD_8387172_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_warehouse_sk#1118 = w_warehouse_sk#495))
    // Left Table: ListBuffer(cs_sold_date_sk#1104, cs_ship_date_sk#1106, cs_call_center_sk#1115, cs_ship_mode_sk#1117, cs_warehouse_sk#1118)
    // Right Table: ListBuffer(w_warehouse_sk#495, w_warehouse_name#497)
    // Output Table: ListBuffer(cs_sold_date_sk#1104, cs_ship_date_sk#1106, cs_call_center_sk#1115, cs_ship_mode_sk#1117, w_warehouse_name#497)
    int left_nrow = tbl_Filter_TD_9736564_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9837484_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8387172_key_leftMajor, SW_JOIN_INNER_TD_8387172_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_9736564_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_warehouse_sk1118_k = tbl_Filter_TD_9736564_output.getInt32(i, 4);
            SW_JOIN_INNER_TD_8387172_key_leftMajor keyA{_cs_warehouse_sk1118_k};
            int32_t _cs_sold_date_sk1104 = tbl_Filter_TD_9736564_output.getInt32(i, 0);
            int32_t _cs_ship_date_sk1106 = tbl_Filter_TD_9736564_output.getInt32(i, 1);
            int32_t _cs_call_center_sk1115 = tbl_Filter_TD_9736564_output.getInt32(i, 2);
            int32_t _cs_ship_mode_sk1117 = tbl_Filter_TD_9736564_output.getInt32(i, 3);
            int32_t _cs_warehouse_sk1118 = tbl_Filter_TD_9736564_output.getInt32(i, 4);
            SW_JOIN_INNER_TD_8387172_payload_leftMajor payloadA{_cs_sold_date_sk1104, _cs_ship_date_sk1106, _cs_call_center_sk1115, _cs_ship_mode_sk1117, _cs_warehouse_sk1118};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9837484_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _w_warehouse_sk495_k = tbl_Filter_TD_9837484_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8387172_key_leftMajor{_w_warehouse_sk495_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk1104 = (it->second)._cs_sold_date_sk1104;
                int32_t _cs_ship_date_sk1106 = (it->second)._cs_ship_date_sk1106;
                int32_t _cs_call_center_sk1115 = (it->second)._cs_call_center_sk1115;
                int32_t _cs_ship_mode_sk1117 = (it->second)._cs_ship_mode_sk1117;
                int32_t _cs_warehouse_sk1118 = (it->second)._cs_warehouse_sk1118;
                int32_t _w_warehouse_sk495 = tbl_Filter_TD_9837484_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_Filter_TD_9837484_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
                tbl_JOIN_INNER_TD_8387172_output.setInt32(r, 0, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_8387172_output.setInt32(r, 1, _cs_ship_date_sk1106);
                tbl_JOIN_INNER_TD_8387172_output.setInt32(r, 2, _cs_call_center_sk1115);
                tbl_JOIN_INNER_TD_8387172_output.setInt32(r, 3, _cs_ship_mode_sk1117);
                tbl_JOIN_INNER_TD_8387172_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _w_warehouse_name497_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8387172_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8387172_key_rightMajor, SW_JOIN_INNER_TD_8387172_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9837484_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _w_warehouse_sk495_k = tbl_Filter_TD_9837484_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8387172_key_rightMajor keyA{_w_warehouse_sk495_k};
            int32_t _w_warehouse_sk495 = tbl_Filter_TD_9837484_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_Filter_TD_9837484_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
            SW_JOIN_INNER_TD_8387172_payload_rightMajor payloadA{_w_warehouse_sk495, _w_warehouse_name497};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9736564_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_warehouse_sk1118_k = tbl_Filter_TD_9736564_output.getInt32(i, 4);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8387172_key_rightMajor{_cs_warehouse_sk1118_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _w_warehouse_sk495 = (it->second)._w_warehouse_sk495;
                std::string _w_warehouse_name497 = (it->second)._w_warehouse_name497;
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n{};
                memcpy(_w_warehouse_name497_n.data(), (_w_warehouse_name497).data(), (_w_warehouse_name497).length());
                int32_t _cs_sold_date_sk1104 = tbl_Filter_TD_9736564_output.getInt32(i, 0);
                int32_t _cs_ship_date_sk1106 = tbl_Filter_TD_9736564_output.getInt32(i, 1);
                int32_t _cs_call_center_sk1115 = tbl_Filter_TD_9736564_output.getInt32(i, 2);
                int32_t _cs_ship_mode_sk1117 = tbl_Filter_TD_9736564_output.getInt32(i, 3);
                int32_t _cs_warehouse_sk1118 = tbl_Filter_TD_9736564_output.getInt32(i, 4);
                tbl_JOIN_INNER_TD_8387172_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _w_warehouse_name497_n);
                tbl_JOIN_INNER_TD_8387172_output.setInt32(r, 0, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_8387172_output.setInt32(r, 1, _cs_ship_date_sk1106);
                tbl_JOIN_INNER_TD_8387172_output.setInt32(r, 2, _cs_call_center_sk1115);
                tbl_JOIN_INNER_TD_8387172_output.setInt32(r, 3, _cs_ship_mode_sk1117);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8387172_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8387172_output #Row: " << tbl_JOIN_INNER_TD_8387172_output.getNumRow() << std::endl;
}

void SW_Filter_TD_735959(Table &tbl_SerializeFromObject_TD_8118177_input, Table &tbl_Filter_TD_735959_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(cc_call_center_sk#903))
    // Input: ListBuffer(cc_call_center_sk#903, cc_name#909)
    // Output: ListBuffer(cc_call_center_sk#903, cc_name#909)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8118177_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cc_call_center_sk903 = tbl_SerializeFromObject_TD_8118177_input.getInt32(i, 0);
        if (_cc_call_center_sk903!= 0) {
            int32_t _cc_call_center_sk903_t = tbl_SerializeFromObject_TD_8118177_input.getInt32(i, 0);
            tbl_Filter_TD_735959_output.setInt32(r, 0, _cc_call_center_sk903_t);
            std::array<char, TPCDS_READ_MAX + 1> _cc_name909_t = tbl_SerializeFromObject_TD_8118177_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_735959_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cc_name909_t);
            r++;
        }
    }
    tbl_Filter_TD_735959_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_735959_output #Row: " << tbl_Filter_TD_735959_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_745813_key_leftMajor {
    int32_t _cs_ship_mode_sk1117;
    bool operator==(const SW_JOIN_INNER_TD_745813_key_leftMajor& other) const {
        return ((_cs_ship_mode_sk1117 == other._cs_ship_mode_sk1117));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_745813_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_745813_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_ship_mode_sk1117));
    }
};
}
struct SW_JOIN_INNER_TD_745813_payload_leftMajor {
    int32_t _cs_sold_date_sk1104;
    int32_t _cs_ship_date_sk1106;
    int32_t _cs_call_center_sk1115;
    int32_t _cs_ship_mode_sk1117;
    std::string _w_warehouse_name497;
};
struct SW_JOIN_INNER_TD_745813_key_rightMajor {
    int32_t _sm_ship_mode_sk360;
    bool operator==(const SW_JOIN_INNER_TD_745813_key_rightMajor& other) const {
        return ((_sm_ship_mode_sk360 == other._sm_ship_mode_sk360));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_745813_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_745813_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._sm_ship_mode_sk360));
    }
};
}
struct SW_JOIN_INNER_TD_745813_payload_rightMajor {
    int32_t _sm_ship_mode_sk360;
    std::string _sm_type362;
};
void SW_JOIN_INNER_TD_745813(Table &tbl_JOIN_INNER_TD_8387172_output, Table &tbl_Filter_TD_8794558_output, Table &tbl_JOIN_INNER_TD_745813_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_ship_mode_sk#1117 = sm_ship_mode_sk#360))
    // Left Table: ListBuffer(cs_sold_date_sk#1104, cs_ship_date_sk#1106, cs_call_center_sk#1115, cs_ship_mode_sk#1117, w_warehouse_name#497)
    // Right Table: ListBuffer(sm_ship_mode_sk#360, sm_type#362)
    // Output Table: ListBuffer(cs_sold_date_sk#1104, cs_ship_date_sk#1106, cs_call_center_sk#1115, w_warehouse_name#497, sm_type#362)
    int left_nrow = tbl_JOIN_INNER_TD_8387172_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8794558_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_745813_key_leftMajor, SW_JOIN_INNER_TD_745813_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_8387172_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_ship_mode_sk1117_k = tbl_JOIN_INNER_TD_8387172_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_745813_key_leftMajor keyA{_cs_ship_mode_sk1117_k};
            int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_8387172_output.getInt32(i, 0);
            int32_t _cs_ship_date_sk1106 = tbl_JOIN_INNER_TD_8387172_output.getInt32(i, 1);
            int32_t _cs_call_center_sk1115 = tbl_JOIN_INNER_TD_8387172_output.getInt32(i, 2);
            int32_t _cs_ship_mode_sk1117 = tbl_JOIN_INNER_TD_8387172_output.getInt32(i, 3);
            std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_JOIN_INNER_TD_8387172_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
            SW_JOIN_INNER_TD_745813_payload_leftMajor payloadA{_cs_sold_date_sk1104, _cs_ship_date_sk1106, _cs_call_center_sk1115, _cs_ship_mode_sk1117, _w_warehouse_name497};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8794558_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _sm_ship_mode_sk360_k = tbl_Filter_TD_8794558_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_745813_key_leftMajor{_sm_ship_mode_sk360_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk1104 = (it->second)._cs_sold_date_sk1104;
                int32_t _cs_ship_date_sk1106 = (it->second)._cs_ship_date_sk1106;
                int32_t _cs_call_center_sk1115 = (it->second)._cs_call_center_sk1115;
                int32_t _cs_ship_mode_sk1117 = (it->second)._cs_ship_mode_sk1117;
                std::string _w_warehouse_name497 = (it->second)._w_warehouse_name497;
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n{};
                memcpy(_w_warehouse_name497_n.data(), (_w_warehouse_name497).data(), (_w_warehouse_name497).length());
                int32_t _sm_ship_mode_sk360 = tbl_Filter_TD_8794558_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _sm_type362_n = tbl_Filter_TD_8794558_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _sm_type362 = std::string(_sm_type362_n.data());
                tbl_JOIN_INNER_TD_745813_output.setInt32(r, 0, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_745813_output.setInt32(r, 1, _cs_ship_date_sk1106);
                tbl_JOIN_INNER_TD_745813_output.setInt32(r, 2, _cs_call_center_sk1115);
                tbl_JOIN_INNER_TD_745813_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _w_warehouse_name497_n);
                tbl_JOIN_INNER_TD_745813_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _sm_type362_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_745813_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_745813_key_rightMajor, SW_JOIN_INNER_TD_745813_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8794558_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _sm_ship_mode_sk360_k = tbl_Filter_TD_8794558_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_745813_key_rightMajor keyA{_sm_ship_mode_sk360_k};
            int32_t _sm_ship_mode_sk360 = tbl_Filter_TD_8794558_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _sm_type362_n = tbl_Filter_TD_8794558_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _sm_type362 = std::string(_sm_type362_n.data());
            SW_JOIN_INNER_TD_745813_payload_rightMajor payloadA{_sm_ship_mode_sk360, _sm_type362};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_8387172_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_ship_mode_sk1117_k = tbl_JOIN_INNER_TD_8387172_output.getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_745813_key_rightMajor{_cs_ship_mode_sk1117_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _sm_ship_mode_sk360 = (it->second)._sm_ship_mode_sk360;
                std::string _sm_type362 = (it->second)._sm_type362;
                std::array<char, TPCDS_READ_MAX + 1> _sm_type362_n{};
                memcpy(_sm_type362_n.data(), (_sm_type362).data(), (_sm_type362).length());
                int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_8387172_output.getInt32(i, 0);
                int32_t _cs_ship_date_sk1106 = tbl_JOIN_INNER_TD_8387172_output.getInt32(i, 1);
                int32_t _cs_call_center_sk1115 = tbl_JOIN_INNER_TD_8387172_output.getInt32(i, 2);
                int32_t _cs_ship_mode_sk1117 = tbl_JOIN_INNER_TD_8387172_output.getInt32(i, 3);
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_JOIN_INNER_TD_8387172_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
                tbl_JOIN_INNER_TD_745813_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _sm_type362_n);
                tbl_JOIN_INNER_TD_745813_output.setInt32(r, 0, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_745813_output.setInt32(r, 1, _cs_ship_date_sk1106);
                tbl_JOIN_INNER_TD_745813_output.setInt32(r, 2, _cs_call_center_sk1115);
                tbl_JOIN_INNER_TD_745813_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _w_warehouse_name497_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_745813_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_745813_output #Row: " << tbl_JOIN_INNER_TD_745813_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6791794(Table &tbl_SerializeFromObject_TD_7894001_input, Table &tbl_Filter_TD_6791794_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_month_seq#123) AND ((d_month_seq#123 >= 1200) AND (d_month_seq#123 <= 1211))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_month_seq#123)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7894001_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_month_seq123 = tbl_SerializeFromObject_TD_7894001_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_7894001_input.getInt32(i, 0);
        if (((_d_month_seq123!= 0) && ((_d_month_seq123 >= 1200) && (_d_month_seq123 <= 1211))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_7894001_input.getInt32(i, 0);
            tbl_Filter_TD_6791794_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_6791794_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6791794_output #Row: " << tbl_Filter_TD_6791794_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6388532_key_leftMajor {
    int32_t _cs_call_center_sk1115;
    bool operator==(const SW_JOIN_INNER_TD_6388532_key_leftMajor& other) const {
        return ((_cs_call_center_sk1115 == other._cs_call_center_sk1115));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6388532_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6388532_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_call_center_sk1115));
    }
};
}
struct SW_JOIN_INNER_TD_6388532_payload_leftMajor {
    int32_t _cs_sold_date_sk1104;
    int32_t _cs_ship_date_sk1106;
    int32_t _cs_call_center_sk1115;
    std::string _w_warehouse_name497;
    std::string _sm_type362;
};
struct SW_JOIN_INNER_TD_6388532_key_rightMajor {
    int32_t _cc_call_center_sk903;
    bool operator==(const SW_JOIN_INNER_TD_6388532_key_rightMajor& other) const {
        return ((_cc_call_center_sk903 == other._cc_call_center_sk903));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6388532_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6388532_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cc_call_center_sk903));
    }
};
}
struct SW_JOIN_INNER_TD_6388532_payload_rightMajor {
    int32_t _cc_call_center_sk903;
    std::string _cc_name909;
};
void SW_JOIN_INNER_TD_6388532(Table &tbl_JOIN_INNER_TD_745813_output, Table &tbl_Filter_TD_735959_output, Table &tbl_JOIN_INNER_TD_6388532_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_call_center_sk#1115 = cc_call_center_sk#903))
    // Left Table: ListBuffer(cs_sold_date_sk#1104, cs_ship_date_sk#1106, cs_call_center_sk#1115, w_warehouse_name#497, sm_type#362)
    // Right Table: ListBuffer(cc_call_center_sk#903, cc_name#909)
    // Output Table: ListBuffer(cs_sold_date_sk#1104, cs_ship_date_sk#1106, w_warehouse_name#497, sm_type#362, cc_name#909)
    int left_nrow = tbl_JOIN_INNER_TD_745813_output.getNumRow();
    int right_nrow = tbl_Filter_TD_735959_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6388532_key_leftMajor, SW_JOIN_INNER_TD_6388532_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_745813_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_call_center_sk1115_k = tbl_JOIN_INNER_TD_745813_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_6388532_key_leftMajor keyA{_cs_call_center_sk1115_k};
            int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_745813_output.getInt32(i, 0);
            int32_t _cs_ship_date_sk1106 = tbl_JOIN_INNER_TD_745813_output.getInt32(i, 1);
            int32_t _cs_call_center_sk1115 = tbl_JOIN_INNER_TD_745813_output.getInt32(i, 2);
            std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_JOIN_INNER_TD_745813_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _sm_type362_n = tbl_JOIN_INNER_TD_745813_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _sm_type362 = std::string(_sm_type362_n.data());
            SW_JOIN_INNER_TD_6388532_payload_leftMajor payloadA{_cs_sold_date_sk1104, _cs_ship_date_sk1106, _cs_call_center_sk1115, _w_warehouse_name497, _sm_type362};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_735959_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cc_call_center_sk903_k = tbl_Filter_TD_735959_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6388532_key_leftMajor{_cc_call_center_sk903_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk1104 = (it->second)._cs_sold_date_sk1104;
                int32_t _cs_ship_date_sk1106 = (it->second)._cs_ship_date_sk1106;
                int32_t _cs_call_center_sk1115 = (it->second)._cs_call_center_sk1115;
                std::string _w_warehouse_name497 = (it->second)._w_warehouse_name497;
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n{};
                memcpy(_w_warehouse_name497_n.data(), (_w_warehouse_name497).data(), (_w_warehouse_name497).length());
                std::string _sm_type362 = (it->second)._sm_type362;
                std::array<char, TPCDS_READ_MAX + 1> _sm_type362_n{};
                memcpy(_sm_type362_n.data(), (_sm_type362).data(), (_sm_type362).length());
                int32_t _cc_call_center_sk903 = tbl_Filter_TD_735959_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_Filter_TD_735959_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _cc_name909 = std::string(_cc_name909_n.data());
                tbl_JOIN_INNER_TD_6388532_output.setInt32(r, 0, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_6388532_output.setInt32(r, 1, _cs_ship_date_sk1106);
                tbl_JOIN_INNER_TD_6388532_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _w_warehouse_name497_n);
                tbl_JOIN_INNER_TD_6388532_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _sm_type362_n);
                tbl_JOIN_INNER_TD_6388532_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _cc_name909_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6388532_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6388532_key_rightMajor, SW_JOIN_INNER_TD_6388532_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_735959_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cc_call_center_sk903_k = tbl_Filter_TD_735959_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6388532_key_rightMajor keyA{_cc_call_center_sk903_k};
            int32_t _cc_call_center_sk903 = tbl_Filter_TD_735959_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_Filter_TD_735959_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cc_name909 = std::string(_cc_name909_n.data());
            SW_JOIN_INNER_TD_6388532_payload_rightMajor payloadA{_cc_call_center_sk903, _cc_name909};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_745813_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_call_center_sk1115_k = tbl_JOIN_INNER_TD_745813_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6388532_key_rightMajor{_cs_call_center_sk1115_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cc_call_center_sk903 = (it->second)._cc_call_center_sk903;
                std::string _cc_name909 = (it->second)._cc_name909;
                std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n{};
                memcpy(_cc_name909_n.data(), (_cc_name909).data(), (_cc_name909).length());
                int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_745813_output.getInt32(i, 0);
                int32_t _cs_ship_date_sk1106 = tbl_JOIN_INNER_TD_745813_output.getInt32(i, 1);
                int32_t _cs_call_center_sk1115 = tbl_JOIN_INNER_TD_745813_output.getInt32(i, 2);
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_JOIN_INNER_TD_745813_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _sm_type362_n = tbl_JOIN_INNER_TD_745813_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _sm_type362 = std::string(_sm_type362_n.data());
                tbl_JOIN_INNER_TD_6388532_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _cc_name909_n);
                tbl_JOIN_INNER_TD_6388532_output.setInt32(r, 0, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_6388532_output.setInt32(r, 1, _cs_ship_date_sk1106);
                tbl_JOIN_INNER_TD_6388532_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _w_warehouse_name497_n);
                tbl_JOIN_INNER_TD_6388532_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _sm_type362_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6388532_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6388532_output #Row: " << tbl_JOIN_INNER_TD_6388532_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5276004_key_leftMajor {
    int32_t _cs_ship_date_sk1106;
    bool operator==(const SW_JOIN_INNER_TD_5276004_key_leftMajor& other) const {
        return ((_cs_ship_date_sk1106 == other._cs_ship_date_sk1106));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5276004_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5276004_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_ship_date_sk1106));
    }
};
}
struct SW_JOIN_INNER_TD_5276004_payload_leftMajor {
    int32_t _cs_sold_date_sk1104;
    int32_t _cs_ship_date_sk1106;
    std::string _w_warehouse_name497;
    std::string _sm_type362;
    std::string _cc_name909;
};
struct SW_JOIN_INNER_TD_5276004_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_5276004_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5276004_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5276004_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_5276004_payload_rightMajor {
    int32_t _d_date_sk120;
};
void SW_JOIN_INNER_TD_5276004(Table &tbl_JOIN_INNER_TD_6388532_output, Table &tbl_Filter_TD_6791794_output, Table &tbl_JOIN_INNER_TD_5276004_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_ship_date_sk#1106 = d_date_sk#120))
    // Left Table: ListBuffer(cs_sold_date_sk#1104, cs_ship_date_sk#1106, w_warehouse_name#497, sm_type#362, cc_name#909)
    // Right Table: ListBuffer(d_date_sk#120)
    // Output Table: ListBuffer(cs_sold_date_sk#1104, cs_ship_date_sk#1106, sm_type#362, cc_name#909, w_warehouse_name#497)
    int left_nrow = tbl_JOIN_INNER_TD_6388532_output.getNumRow();
    int right_nrow = tbl_Filter_TD_6791794_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5276004_key_leftMajor, SW_JOIN_INNER_TD_5276004_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_6388532_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_ship_date_sk1106_k = tbl_JOIN_INNER_TD_6388532_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_5276004_key_leftMajor keyA{_cs_ship_date_sk1106_k};
            int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_6388532_output.getInt32(i, 0);
            int32_t _cs_ship_date_sk1106 = tbl_JOIN_INNER_TD_6388532_output.getInt32(i, 1);
            std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_JOIN_INNER_TD_6388532_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _sm_type362_n = tbl_JOIN_INNER_TD_6388532_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _sm_type362 = std::string(_sm_type362_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_JOIN_INNER_TD_6388532_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _cc_name909 = std::string(_cc_name909_n.data());
            SW_JOIN_INNER_TD_5276004_payload_leftMajor payloadA{_cs_sold_date_sk1104, _cs_ship_date_sk1106, _w_warehouse_name497, _sm_type362, _cc_name909};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6791794_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_6791794_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5276004_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk1104 = (it->second)._cs_sold_date_sk1104;
                int32_t _cs_ship_date_sk1106 = (it->second)._cs_ship_date_sk1106;
                std::string _w_warehouse_name497 = (it->second)._w_warehouse_name497;
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n{};
                memcpy(_w_warehouse_name497_n.data(), (_w_warehouse_name497).data(), (_w_warehouse_name497).length());
                std::string _sm_type362 = (it->second)._sm_type362;
                std::array<char, TPCDS_READ_MAX + 1> _sm_type362_n{};
                memcpy(_sm_type362_n.data(), (_sm_type362).data(), (_sm_type362).length());
                std::string _cc_name909 = (it->second)._cc_name909;
                std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n{};
                memcpy(_cc_name909_n.data(), (_cc_name909).data(), (_cc_name909).length());
                int32_t _d_date_sk120 = tbl_Filter_TD_6791794_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_5276004_output.setInt32(r, 0, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_5276004_output.setInt32(r, 1, _cs_ship_date_sk1106);
                tbl_JOIN_INNER_TD_5276004_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _w_warehouse_name497_n);
                tbl_JOIN_INNER_TD_5276004_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _sm_type362_n);
                tbl_JOIN_INNER_TD_5276004_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _cc_name909_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5276004_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5276004_key_rightMajor, SW_JOIN_INNER_TD_5276004_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_6791794_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_6791794_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5276004_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_6791794_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5276004_payload_rightMajor payloadA{_d_date_sk120};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_6388532_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_ship_date_sk1106_k = tbl_JOIN_INNER_TD_6388532_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5276004_key_rightMajor{_cs_ship_date_sk1106_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_6388532_output.getInt32(i, 0);
                int32_t _cs_ship_date_sk1106 = tbl_JOIN_INNER_TD_6388532_output.getInt32(i, 1);
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_JOIN_INNER_TD_6388532_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _sm_type362_n = tbl_JOIN_INNER_TD_6388532_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _sm_type362 = std::string(_sm_type362_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_JOIN_INNER_TD_6388532_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _cc_name909 = std::string(_cc_name909_n.data());
                tbl_JOIN_INNER_TD_5276004_output.setInt32(r, 0, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_5276004_output.setInt32(r, 1, _cs_ship_date_sk1106);
                tbl_JOIN_INNER_TD_5276004_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _w_warehouse_name497_n);
                tbl_JOIN_INNER_TD_5276004_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _sm_type362_n);
                tbl_JOIN_INNER_TD_5276004_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _cc_name909_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5276004_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5276004_output #Row: " << tbl_JOIN_INNER_TD_5276004_output.getNumRow() << std::endl;
}

void SW_Project_TD_471838(Table &tbl_JOIN_INNER_TD_5276004_output, Table &tbl_Project_TD_471838_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(substr(w_warehouse_name#497, 1, 20) AS _groupingexpression#3646)
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_ship_date_sk#1106, sm_type#362, cc_name#909, w_warehouse_name#497)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_ship_date_sk#1106, sm_type#362, cc_name#909, _groupingexpression#3646)
    int nrow1 = tbl_JOIN_INNER_TD_5276004_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_5276004_output.getInt32(i, 0);
        int32_t _cs_ship_date_sk1106 = tbl_JOIN_INNER_TD_5276004_output.getInt32(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _sm_type362 = tbl_JOIN_INNER_TD_5276004_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name909 = tbl_JOIN_INNER_TD_5276004_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497 = tbl_JOIN_INNER_TD_5276004_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        std::string __groupingexpression3646_str = std::string(_w_warehouse_name497.data()).substr(0, 20);
        std::array<char, TPCDS_READ_MAX + 1> __groupingexpression3646{};
        memcpy(__groupingexpression3646.data(), __groupingexpression3646_str.data(), (__groupingexpression3646_str).length());
        tbl_Project_TD_471838_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 4, __groupingexpression3646);
        tbl_Project_TD_471838_output.setInt32(i, 0, _cs_sold_date_sk1104);
        tbl_Project_TD_471838_output.setInt32(i, 1, _cs_ship_date_sk1106);
        tbl_Project_TD_471838_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 2, _sm_type362);
        tbl_Project_TD_471838_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 3, _cc_name909);
    }
    tbl_Project_TD_471838_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_471838_output #Row: " << tbl_Project_TD_471838_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_3984732_key {
    std::string __groupingexpression3646;
    std::string _sm_type362;
    std::string _cc_name909;
    bool operator==(const SW_Aggregate_TD_3984732_key& other) const { return (__groupingexpression3646 == other.__groupingexpression3646) && (_sm_type362 == other._sm_type362) && (_cc_name909 == other._cc_name909); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_3984732_key> {
    std::size_t operator() (const SW_Aggregate_TD_3984732_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k.__groupingexpression3646)) + (hash<string>()(k._sm_type362)) + (hash<string>()(k._cc_name909));
    }
};
}
struct SW_Aggregate_TD_3984732_payload {
    std::string substr_w_warehouse_name_1_20;
    int64_t _days3544L_sum_0;
    int64_t _days3545L_sum_1;
    int64_t _days3546L_sum_2;
    int64_t _days3547L_sum_3;
    int64_t _days3548L_sum_4;
};
void SW_Aggregate_TD_3984732(Table &tbl_Project_TD_471838_output, Table &tbl_Aggregate_TD_3984732_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(_groupingexpression#3646, sm_type#362, cc_name#909, _groupingexpression#3646 AS substr(w_warehouse_name, 1, 20)#3554, sum(CASE WHEN ((cs_ship_date_sk#1106 - cs_sold_date_sk#1104) <= 30) THEN 1 ELSE 0 END) AS 30 days#3544L, sum(CASE WHEN (((cs_ship_date_sk#1106 - cs_sold_date_sk#1104) > 30) AND ((cs_ship_date_sk#1106 - cs_sold_date_sk#1104) <= 60)) THEN 1 ELSE 0 END) AS 31-60 days#3545L, sum(CASE WHEN (((cs_ship_date_sk#1106 - cs_sold_date_sk#1104) > 60) AND ((cs_ship_date_sk#1106 - cs_sold_date_sk#1104) <= 90)) THEN 1 ELSE 0 END) AS 61-90 days#3546L, sum(CASE WHEN (((cs_ship_date_sk#1106 - cs_sold_date_sk#1104) > 90) AND ((cs_ship_date_sk#1106 - cs_sold_date_sk#1104) <= 120)) THEN 1 ELSE 0 END) AS 91-120 days#3547L, sum(CASE WHEN ((cs_ship_date_sk#1106 - cs_sold_date_sk#1104) > 120) THEN 1 ELSE 0 END) AS >120 days#3548L)
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_ship_date_sk#1106, sm_type#362, cc_name#909, _groupingexpression#3646)
    // Output: ListBuffer(substr(w_warehouse_name, 1, 20)#3554, sm_type#362, cc_name#909, 30 days#3544L, 31-60 days#3545L, 61-90 days#3546L, 91-120 days#3547L, >120 days#3548L)
    std::unordered_map<SW_Aggregate_TD_3984732_key, SW_Aggregate_TD_3984732_payload> ht1;
    int nrow1 = tbl_Project_TD_471838_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_sold_date_sk1104 = tbl_Project_TD_471838_output.getInt32(i, 0);
        int32_t _cs_ship_date_sk1106 = tbl_Project_TD_471838_output.getInt32(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _sm_type362 = tbl_Project_TD_471838_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name909 = tbl_Project_TD_471838_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> __groupingexpression3646 = tbl_Project_TD_471838_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        SW_Aggregate_TD_3984732_key k{std::string(__groupingexpression3646.data()), std::string(_sm_type362.data()), std::string(_cc_name909.data())};
        std::array<char, TPCDS_READ_MAX + 1> substr_w_warehouse_name_1_20 = __groupingexpression3646;
        int64_t _days3544L_sum_0 = ((_cs_ship_date_sk1106 - _cs_sold_date_sk1104) <= 30) ? 1 : 0;
        int64_t _days3545L_sum_1 = (((_cs_ship_date_sk1106 - _cs_sold_date_sk1104) > 30) && ((_cs_ship_date_sk1106 - _cs_sold_date_sk1104) <= 60)) ? 1 : 0;
        int64_t _days3546L_sum_2 = (((_cs_ship_date_sk1106 - _cs_sold_date_sk1104) > 60) && ((_cs_ship_date_sk1106 - _cs_sold_date_sk1104) <= 90)) ? 1 : 0;
        int64_t _days3547L_sum_3 = (((_cs_ship_date_sk1106 - _cs_sold_date_sk1104) > 90) && ((_cs_ship_date_sk1106 - _cs_sold_date_sk1104) <= 120)) ? 1 : 0;
        int64_t _days3548L_sum_4 = ((_cs_ship_date_sk1106 - _cs_sold_date_sk1104) > 120) ? 1 : 0;
        SW_Aggregate_TD_3984732_payload p{std::string(substr_w_warehouse_name_1_20.data()), _days3544L_sum_0, _days3545L_sum_1, _days3546L_sum_2, _days3547L_sum_3, _days3548L_sum_4};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._days3544L_sum_0 + _days3544L_sum_0;
            p._days3544L_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._days3545L_sum_1 + _days3545L_sum_1;
            p._days3545L_sum_1 = sum_1;
            int64_t sum_2 = (it->second)._days3546L_sum_2 + _days3546L_sum_2;
            p._days3546L_sum_2 = sum_2;
            int64_t sum_3 = (it->second)._days3547L_sum_3 + _days3547L_sum_3;
            p._days3547L_sum_3 = sum_3;
            int64_t sum_4 = (it->second)._days3548L_sum_4 + _days3548L_sum_4;
            p._days3548L_sum_4 = sum_4;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // __groupingexpression3646 not required in the output table
        std::array<char, TPCDS_READ_MAX + 1> _sm_type362{};
        memcpy(_sm_type362.data(), ((it.first)._sm_type362).data(), ((it.first)._sm_type362).length());
        tbl_Aggregate_TD_3984732_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _sm_type362);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name909{};
        memcpy(_cc_name909.data(), ((it.first)._cc_name909).data(), ((it.first)._cc_name909).length());
        tbl_Aggregate_TD_3984732_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_name909);
        std::array<char, TPCDS_READ_MAX + 1> substr_w_warehouse_name_1_20_n{};
        memcpy(substr_w_warehouse_name_1_20_n.data(), (it.second).substr_w_warehouse_name_1_20.data(), (it.second).substr_w_warehouse_name_1_20.length());
        tbl_Aggregate_TD_3984732_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, substr_w_warehouse_name_1_20_n);
        int64_t _days3544L = (it.second)._days3544L_sum_0;
        tbl_Aggregate_TD_3984732_output.setInt64(r, 3, _days3544L);
        int64_t _days3545L = (it.second)._days3545L_sum_1;
        tbl_Aggregate_TD_3984732_output.setInt64(r, 4, _days3545L);
        int64_t _days3546L = (it.second)._days3546L_sum_2;
        tbl_Aggregate_TD_3984732_output.setInt64(r, 5, _days3546L);
        int64_t _days3547L = (it.second)._days3547L_sum_3;
        tbl_Aggregate_TD_3984732_output.setInt64(r, 6, _days3547L);
        int64_t _days3548L = (it.second)._days3548L_sum_4;
        tbl_Aggregate_TD_3984732_output.setInt64(r, 7, _days3548L);
        ++r;
    }
    tbl_Aggregate_TD_3984732_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_3984732_output #Row: " << tbl_Aggregate_TD_3984732_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2588414(Table &tbl_Aggregate_TD_3984732_output, Table &tbl_Sort_TD_2588414_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(substr(w_warehouse_name, 1, 20)#3554 ASC NULLS FIRST, sm_type#362 ASC NULLS FIRST, cc_name#909 ASC NULLS FIRST)
    // Input: ListBuffer(substr(w_warehouse_name, 1, 20)#3554, sm_type#362, cc_name#909, 30 days#3544L, 31-60 days#3545L, 61-90 days#3546L, 91-120 days#3547L, >120 days#3548L)
    // Output: ListBuffer(substr(w_warehouse_name, 1, 20)#3554, sm_type#362, cc_name#909, 30 days#3544L, 31-60 days#3545L, 61-90 days#3546L, 91-120 days#3547L, >120 days#3548L)
    struct SW_Sort_TD_2588414Row {
        std::string substr_w_warehouse_name_1_20;
        std::string _sm_type362;
        std::string _cc_name909;
        int64_t _days3544L;
        int64_t _days3545L;
        int64_t _days3546L;
        int64_t _days3547L;
        int64_t _days3548L;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2588414Row& a, const SW_Sort_TD_2588414Row& b) const { return 
 (a.substr_w_warehouse_name_1_20 < b.substr_w_warehouse_name_1_20) || 
 ((a.substr_w_warehouse_name_1_20 == b.substr_w_warehouse_name_1_20) && (a._sm_type362 < b._sm_type362)) || 
 ((a.substr_w_warehouse_name_1_20 == b.substr_w_warehouse_name_1_20) && (a._sm_type362 == b._sm_type362) && (a._cc_name909 < b._cc_name909)); 
}
    }SW_Sort_TD_2588414_order; 

    int nrow1 = tbl_Aggregate_TD_3984732_output.getNumRow();
    std::vector<SW_Sort_TD_2588414Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> substr_w_warehouse_name_1_20 = tbl_Aggregate_TD_3984732_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _sm_type362 = tbl_Aggregate_TD_3984732_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name909 = tbl_Aggregate_TD_3984732_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        int64_t _days3544L = tbl_Aggregate_TD_3984732_output.getInt64(i, 3);
        int64_t _days3545L = tbl_Aggregate_TD_3984732_output.getInt64(i, 4);
        int64_t _days3546L = tbl_Aggregate_TD_3984732_output.getInt64(i, 5);
        int64_t _days3547L = tbl_Aggregate_TD_3984732_output.getInt64(i, 6);
        int64_t _days3548L = tbl_Aggregate_TD_3984732_output.getInt64(i, 7);
        SW_Sort_TD_2588414Row t = {std::string(substr_w_warehouse_name_1_20.data()),std::string(_sm_type362.data()),std::string(_cc_name909.data()),_days3544L,_days3545L,_days3546L,_days3547L,_days3548L};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2588414_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> substr_w_warehouse_name_1_20{};
        memcpy(substr_w_warehouse_name_1_20.data(), (it.substr_w_warehouse_name_1_20).data(), (it.substr_w_warehouse_name_1_20).length());
        tbl_Sort_TD_2588414_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, substr_w_warehouse_name_1_20);
        std::array<char, TPCDS_READ_MAX + 1> _sm_type362{};
        memcpy(_sm_type362.data(), (it._sm_type362).data(), (it._sm_type362).length());
        tbl_Sort_TD_2588414_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _sm_type362);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name909{};
        memcpy(_cc_name909.data(), (it._cc_name909).data(), (it._cc_name909).length());
        tbl_Sort_TD_2588414_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _cc_name909);
        tbl_Sort_TD_2588414_output.setInt64(r, 3, it._days3544L);
        tbl_Sort_TD_2588414_output.setInt64(r, 4, it._days3545L);
        tbl_Sort_TD_2588414_output.setInt64(r, 5, it._days3546L);
        tbl_Sort_TD_2588414_output.setInt64(r, 6, it._days3547L);
        tbl_Sort_TD_2588414_output.setInt64(r, 7, it._days3548L);
        ++r;
    }
    tbl_Sort_TD_2588414_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2588414_output #Row: " << tbl_Sort_TD_2588414_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1349029(Table &tbl_Sort_TD_2588414_output, Table &tbl_LocalLimit_TD_1349029_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(substr(w_warehouse_name, 1, 20)#3554, sm_type#362, cc_name#909, 30 days#3544L, 31-60 days#3545L, 61-90 days#3546L, 91-120 days#3547L, >120 days#3548L)
    // Output: ListBuffer(substr(w_warehouse_name, 1, 20)#3554, sm_type#362, cc_name#909, 30 days#3544L, 31-60 days#3545L, 61-90 days#3546L, 91-120 days#3547L, >120 days#3548L)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> substr_w_warehouse_name_1_20_n = tbl_Sort_TD_2588414_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1349029_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, substr_w_warehouse_name_1_20_n);
        std::array<char, TPCDS_READ_MAX + 1> _sm_type362_n = tbl_Sort_TD_2588414_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_1349029_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _sm_type362_n);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_Sort_TD_2588414_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_LocalLimit_TD_1349029_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_name909_n);
        tbl_LocalLimit_TD_1349029_output.setInt64(r, 3, tbl_Sort_TD_2588414_output.getInt64(i, 3));
        tbl_LocalLimit_TD_1349029_output.setInt64(r, 4, tbl_Sort_TD_2588414_output.getInt64(i, 4));
        tbl_LocalLimit_TD_1349029_output.setInt64(r, 5, tbl_Sort_TD_2588414_output.getInt64(i, 5));
        tbl_LocalLimit_TD_1349029_output.setInt64(r, 6, tbl_Sort_TD_2588414_output.getInt64(i, 6));
        tbl_LocalLimit_TD_1349029_output.setInt64(r, 7, tbl_Sort_TD_2588414_output.getInt64(i, 7));
        r++;
    }
    tbl_LocalLimit_TD_1349029_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1349029_output #Row: " << tbl_LocalLimit_TD_1349029_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0227526(Table &tbl_LocalLimit_TD_1349029_output, Table &tbl_GlobalLimit_TD_0227526_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(substr(w_warehouse_name, 1, 20)#3554, sm_type#362, cc_name#909, 30 days#3544L, 31-60 days#3545L, 61-90 days#3546L, 91-120 days#3547L, >120 days#3548L)
    // Output: ListBuffer(substr(w_warehouse_name, 1, 20)#3554, sm_type#362, cc_name#909, 30 days#3544L, 31-60 days#3545L, 61-90 days#3546L, 91-120 days#3547L, >120 days#3548L)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> substr_w_warehouse_name_1_20_n = tbl_LocalLimit_TD_1349029_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0227526_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, substr_w_warehouse_name_1_20_n);
        std::array<char, TPCDS_READ_MAX + 1> _sm_type362_n = tbl_LocalLimit_TD_1349029_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_0227526_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _sm_type362_n);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_LocalLimit_TD_1349029_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_GlobalLimit_TD_0227526_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_name909_n);
        tbl_GlobalLimit_TD_0227526_output.setInt64(r, 3, tbl_LocalLimit_TD_1349029_output.getInt64(i, 3));
        tbl_GlobalLimit_TD_0227526_output.setInt64(r, 4, tbl_LocalLimit_TD_1349029_output.getInt64(i, 4));
        tbl_GlobalLimit_TD_0227526_output.setInt64(r, 5, tbl_LocalLimit_TD_1349029_output.getInt64(i, 5));
        tbl_GlobalLimit_TD_0227526_output.setInt64(r, 6, tbl_LocalLimit_TD_1349029_output.getInt64(i, 6));
        tbl_GlobalLimit_TD_0227526_output.setInt64(r, 7, tbl_LocalLimit_TD_1349029_output.getInt64(i, 7));
        r++;
    }
    tbl_GlobalLimit_TD_0227526_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0227526_output #Row: " << tbl_GlobalLimit_TD_0227526_output.getNumRow() << std::endl;
}

