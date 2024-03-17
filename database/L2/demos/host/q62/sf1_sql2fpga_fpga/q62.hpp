#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_9368299(Table &tbl_SerializeFromObject_TD_10814938_input, Table &tbl_Filter_TD_9368299_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(w_warehouse_sk#495))
    // Input: ListBuffer(w_warehouse_sk#495, w_warehouse_name#497)
    // Output: ListBuffer(w_warehouse_sk#495, w_warehouse_name#497)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10814938_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _w_warehouse_sk495 = tbl_SerializeFromObject_TD_10814938_input.getInt32(i, 0);
        if (_w_warehouse_sk495!= 0) {
            int32_t _w_warehouse_sk495_t = tbl_SerializeFromObject_TD_10814938_input.getInt32(i, 0);
            tbl_Filter_TD_9368299_output.setInt32(r, 0, _w_warehouse_sk495_t);
            std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_t = tbl_SerializeFromObject_TD_10814938_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_9368299_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _w_warehouse_name497_t);
            r++;
        }
    }
    tbl_Filter_TD_9368299_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9368299_output #Row: " << tbl_Filter_TD_9368299_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9315014(Table &tbl_SerializeFromObject_TD_10454510_input, Table &tbl_Filter_TD_9315014_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ws_warehouse_sk#744) AND isnotnull(ws_ship_mode_sk#743)) AND (isnotnull(ws_web_site_sk#742) AND isnotnull(ws_ship_date_sk#731))))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_ship_date_sk#731, ws_web_site_sk#742, ws_ship_mode_sk#743, ws_warehouse_sk#744)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_ship_date_sk#731, ws_web_site_sk#742, ws_ship_mode_sk#743, ws_warehouse_sk#744)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10454510_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_warehouse_sk744 = tbl_SerializeFromObject_TD_10454510_input.getInt32(i, 4);
        int32_t _ws_ship_mode_sk743 = tbl_SerializeFromObject_TD_10454510_input.getInt32(i, 3);
        int32_t _ws_web_site_sk742 = tbl_SerializeFromObject_TD_10454510_input.getInt32(i, 2);
        int32_t _ws_ship_date_sk731 = tbl_SerializeFromObject_TD_10454510_input.getInt32(i, 1);
        if (((_ws_warehouse_sk744!= 0) && (_ws_ship_mode_sk743!= 0)) && ((_ws_web_site_sk742!= 0) && (_ws_ship_date_sk731!= 0))) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_10454510_input.getInt32(i, 0);
            tbl_Filter_TD_9315014_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_ship_date_sk731_t = tbl_SerializeFromObject_TD_10454510_input.getInt32(i, 1);
            tbl_Filter_TD_9315014_output.setInt32(r, 1, _ws_ship_date_sk731_t);
            int32_t _ws_web_site_sk742_t = tbl_SerializeFromObject_TD_10454510_input.getInt32(i, 2);
            tbl_Filter_TD_9315014_output.setInt32(r, 2, _ws_web_site_sk742_t);
            int32_t _ws_ship_mode_sk743_t = tbl_SerializeFromObject_TD_10454510_input.getInt32(i, 3);
            tbl_Filter_TD_9315014_output.setInt32(r, 3, _ws_ship_mode_sk743_t);
            int32_t _ws_warehouse_sk744_t = tbl_SerializeFromObject_TD_10454510_input.getInt32(i, 4);
            tbl_Filter_TD_9315014_output.setInt32(r, 4, _ws_warehouse_sk744_t);
            r++;
        }
    }
    tbl_Filter_TD_9315014_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9315014_output #Row: " << tbl_Filter_TD_9315014_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8263398(Table &tbl_SerializeFromObject_TD_9910388_input, Table &tbl_Filter_TD_8263398_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(sm_ship_mode_sk#360))
    // Input: ListBuffer(sm_ship_mode_sk#360, sm_type#362)
    // Output: ListBuffer(sm_ship_mode_sk#360, sm_type#362)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9910388_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _sm_ship_mode_sk360 = tbl_SerializeFromObject_TD_9910388_input.getInt32(i, 0);
        if (_sm_ship_mode_sk360!= 0) {
            int32_t _sm_ship_mode_sk360_t = tbl_SerializeFromObject_TD_9910388_input.getInt32(i, 0);
            tbl_Filter_TD_8263398_output.setInt32(r, 0, _sm_ship_mode_sk360_t);
            std::array<char, TPCDS_READ_MAX + 1> _sm_type362_t = tbl_SerializeFromObject_TD_9910388_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_8263398_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _sm_type362_t);
            r++;
        }
    }
    tbl_Filter_TD_8263398_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8263398_output #Row: " << tbl_Filter_TD_8263398_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8555322_key_leftMajor {
    int32_t _ws_warehouse_sk744;
    bool operator==(const SW_JOIN_INNER_TD_8555322_key_leftMajor& other) const {
        return ((_ws_warehouse_sk744 == other._ws_warehouse_sk744));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8555322_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8555322_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_warehouse_sk744));
    }
};
}
struct SW_JOIN_INNER_TD_8555322_payload_leftMajor {
    int32_t _ws_sold_date_sk729;
    int32_t _ws_ship_date_sk731;
    int32_t _ws_web_site_sk742;
    int32_t _ws_ship_mode_sk743;
    int32_t _ws_warehouse_sk744;
};
struct SW_JOIN_INNER_TD_8555322_key_rightMajor {
    int32_t _w_warehouse_sk495;
    bool operator==(const SW_JOIN_INNER_TD_8555322_key_rightMajor& other) const {
        return ((_w_warehouse_sk495 == other._w_warehouse_sk495));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8555322_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8555322_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._w_warehouse_sk495));
    }
};
}
struct SW_JOIN_INNER_TD_8555322_payload_rightMajor {
    int32_t _w_warehouse_sk495;
    std::string _w_warehouse_name497;
};
void SW_JOIN_INNER_TD_8555322(Table &tbl_Filter_TD_9315014_output, Table &tbl_Filter_TD_9368299_output, Table &tbl_JOIN_INNER_TD_8555322_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_warehouse_sk#744 = w_warehouse_sk#495))
    // Left Table: ListBuffer(ws_sold_date_sk#729, ws_ship_date_sk#731, ws_web_site_sk#742, ws_ship_mode_sk#743, ws_warehouse_sk#744)
    // Right Table: ListBuffer(w_warehouse_sk#495, w_warehouse_name#497)
    // Output Table: ListBuffer(ws_sold_date_sk#729, ws_ship_date_sk#731, ws_web_site_sk#742, ws_ship_mode_sk#743, w_warehouse_name#497)
    int left_nrow = tbl_Filter_TD_9315014_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9368299_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8555322_key_leftMajor, SW_JOIN_INNER_TD_8555322_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_9315014_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_warehouse_sk744_k = tbl_Filter_TD_9315014_output.getInt32(i, 4);
            SW_JOIN_INNER_TD_8555322_key_leftMajor keyA{_ws_warehouse_sk744_k};
            int32_t _ws_sold_date_sk729 = tbl_Filter_TD_9315014_output.getInt32(i, 0);
            int32_t _ws_ship_date_sk731 = tbl_Filter_TD_9315014_output.getInt32(i, 1);
            int32_t _ws_web_site_sk742 = tbl_Filter_TD_9315014_output.getInt32(i, 2);
            int32_t _ws_ship_mode_sk743 = tbl_Filter_TD_9315014_output.getInt32(i, 3);
            int32_t _ws_warehouse_sk744 = tbl_Filter_TD_9315014_output.getInt32(i, 4);
            SW_JOIN_INNER_TD_8555322_payload_leftMajor payloadA{_ws_sold_date_sk729, _ws_ship_date_sk731, _ws_web_site_sk742, _ws_ship_mode_sk743, _ws_warehouse_sk744};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9368299_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _w_warehouse_sk495_k = tbl_Filter_TD_9368299_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8555322_key_leftMajor{_w_warehouse_sk495_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_date_sk729 = (it->second)._ws_sold_date_sk729;
                int32_t _ws_ship_date_sk731 = (it->second)._ws_ship_date_sk731;
                int32_t _ws_web_site_sk742 = (it->second)._ws_web_site_sk742;
                int32_t _ws_ship_mode_sk743 = (it->second)._ws_ship_mode_sk743;
                int32_t _ws_warehouse_sk744 = (it->second)._ws_warehouse_sk744;
                int32_t _w_warehouse_sk495 = tbl_Filter_TD_9368299_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_Filter_TD_9368299_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
                tbl_JOIN_INNER_TD_8555322_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_8555322_output.setInt32(r, 1, _ws_ship_date_sk731);
                tbl_JOIN_INNER_TD_8555322_output.setInt32(r, 2, _ws_web_site_sk742);
                tbl_JOIN_INNER_TD_8555322_output.setInt32(r, 3, _ws_ship_mode_sk743);
                tbl_JOIN_INNER_TD_8555322_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _w_warehouse_name497_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8555322_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8555322_key_rightMajor, SW_JOIN_INNER_TD_8555322_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9368299_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _w_warehouse_sk495_k = tbl_Filter_TD_9368299_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8555322_key_rightMajor keyA{_w_warehouse_sk495_k};
            int32_t _w_warehouse_sk495 = tbl_Filter_TD_9368299_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_Filter_TD_9368299_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
            SW_JOIN_INNER_TD_8555322_payload_rightMajor payloadA{_w_warehouse_sk495, _w_warehouse_name497};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9315014_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_warehouse_sk744_k = tbl_Filter_TD_9315014_output.getInt32(i, 4);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8555322_key_rightMajor{_ws_warehouse_sk744_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _w_warehouse_sk495 = (it->second)._w_warehouse_sk495;
                std::string _w_warehouse_name497 = (it->second)._w_warehouse_name497;
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n{};
                memcpy(_w_warehouse_name497_n.data(), (_w_warehouse_name497).data(), (_w_warehouse_name497).length());
                int32_t _ws_sold_date_sk729 = tbl_Filter_TD_9315014_output.getInt32(i, 0);
                int32_t _ws_ship_date_sk731 = tbl_Filter_TD_9315014_output.getInt32(i, 1);
                int32_t _ws_web_site_sk742 = tbl_Filter_TD_9315014_output.getInt32(i, 2);
                int32_t _ws_ship_mode_sk743 = tbl_Filter_TD_9315014_output.getInt32(i, 3);
                int32_t _ws_warehouse_sk744 = tbl_Filter_TD_9315014_output.getInt32(i, 4);
                tbl_JOIN_INNER_TD_8555322_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _w_warehouse_name497_n);
                tbl_JOIN_INNER_TD_8555322_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_8555322_output.setInt32(r, 1, _ws_ship_date_sk731);
                tbl_JOIN_INNER_TD_8555322_output.setInt32(r, 2, _ws_web_site_sk742);
                tbl_JOIN_INNER_TD_8555322_output.setInt32(r, 3, _ws_ship_mode_sk743);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8555322_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8555322_output #Row: " << tbl_JOIN_INNER_TD_8555322_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7910097(Table &tbl_SerializeFromObject_TD_8942264_input, Table &tbl_Filter_TD_7910097_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(web_site_sk#537))
    // Input: ListBuffer(web_site_sk#537, web_name#541)
    // Output: ListBuffer(web_site_sk#537, web_name#541)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8942264_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _web_site_sk537 = tbl_SerializeFromObject_TD_8942264_input.getInt32(i, 0);
        if (_web_site_sk537!= 0) {
            int32_t _web_site_sk537_t = tbl_SerializeFromObject_TD_8942264_input.getInt32(i, 0);
            tbl_Filter_TD_7910097_output.setInt32(r, 0, _web_site_sk537_t);
            std::array<char, TPCDS_READ_MAX + 1> _web_name541_t = tbl_SerializeFromObject_TD_8942264_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_7910097_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _web_name541_t);
            r++;
        }
    }
    tbl_Filter_TD_7910097_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7910097_output #Row: " << tbl_Filter_TD_7910097_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_7941240_key_leftMajor {
    int32_t _ws_ship_mode_sk743;
    bool operator==(const SW_JOIN_INNER_TD_7941240_key_leftMajor& other) const {
        return ((_ws_ship_mode_sk743 == other._ws_ship_mode_sk743));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7941240_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7941240_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_ship_mode_sk743));
    }
};
}
struct SW_JOIN_INNER_TD_7941240_payload_leftMajor {
    int32_t _ws_sold_date_sk729;
    int32_t _ws_ship_date_sk731;
    int32_t _ws_web_site_sk742;
    int32_t _ws_ship_mode_sk743;
    std::string _w_warehouse_name497;
};
struct SW_JOIN_INNER_TD_7941240_key_rightMajor {
    int32_t _sm_ship_mode_sk360;
    bool operator==(const SW_JOIN_INNER_TD_7941240_key_rightMajor& other) const {
        return ((_sm_ship_mode_sk360 == other._sm_ship_mode_sk360));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7941240_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7941240_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._sm_ship_mode_sk360));
    }
};
}
struct SW_JOIN_INNER_TD_7941240_payload_rightMajor {
    int32_t _sm_ship_mode_sk360;
    std::string _sm_type362;
};
void SW_JOIN_INNER_TD_7941240(Table &tbl_JOIN_INNER_TD_8555322_output, Table &tbl_Filter_TD_8263398_output, Table &tbl_JOIN_INNER_TD_7941240_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_ship_mode_sk#743 = sm_ship_mode_sk#360))
    // Left Table: ListBuffer(ws_sold_date_sk#729, ws_ship_date_sk#731, ws_web_site_sk#742, ws_ship_mode_sk#743, w_warehouse_name#497)
    // Right Table: ListBuffer(sm_ship_mode_sk#360, sm_type#362)
    // Output Table: ListBuffer(ws_sold_date_sk#729, ws_ship_date_sk#731, ws_web_site_sk#742, w_warehouse_name#497, sm_type#362)
    int left_nrow = tbl_JOIN_INNER_TD_8555322_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8263398_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7941240_key_leftMajor, SW_JOIN_INNER_TD_7941240_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_8555322_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_ship_mode_sk743_k = tbl_JOIN_INNER_TD_8555322_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_7941240_key_leftMajor keyA{_ws_ship_mode_sk743_k};
            int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_8555322_output.getInt32(i, 0);
            int32_t _ws_ship_date_sk731 = tbl_JOIN_INNER_TD_8555322_output.getInt32(i, 1);
            int32_t _ws_web_site_sk742 = tbl_JOIN_INNER_TD_8555322_output.getInt32(i, 2);
            int32_t _ws_ship_mode_sk743 = tbl_JOIN_INNER_TD_8555322_output.getInt32(i, 3);
            std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_JOIN_INNER_TD_8555322_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
            SW_JOIN_INNER_TD_7941240_payload_leftMajor payloadA{_ws_sold_date_sk729, _ws_ship_date_sk731, _ws_web_site_sk742, _ws_ship_mode_sk743, _w_warehouse_name497};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8263398_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _sm_ship_mode_sk360_k = tbl_Filter_TD_8263398_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7941240_key_leftMajor{_sm_ship_mode_sk360_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_date_sk729 = (it->second)._ws_sold_date_sk729;
                int32_t _ws_ship_date_sk731 = (it->second)._ws_ship_date_sk731;
                int32_t _ws_web_site_sk742 = (it->second)._ws_web_site_sk742;
                int32_t _ws_ship_mode_sk743 = (it->second)._ws_ship_mode_sk743;
                std::string _w_warehouse_name497 = (it->second)._w_warehouse_name497;
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n{};
                memcpy(_w_warehouse_name497_n.data(), (_w_warehouse_name497).data(), (_w_warehouse_name497).length());
                int32_t _sm_ship_mode_sk360 = tbl_Filter_TD_8263398_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _sm_type362_n = tbl_Filter_TD_8263398_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _sm_type362 = std::string(_sm_type362_n.data());
                tbl_JOIN_INNER_TD_7941240_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_7941240_output.setInt32(r, 1, _ws_ship_date_sk731);
                tbl_JOIN_INNER_TD_7941240_output.setInt32(r, 2, _ws_web_site_sk742);
                tbl_JOIN_INNER_TD_7941240_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _w_warehouse_name497_n);
                tbl_JOIN_INNER_TD_7941240_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _sm_type362_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7941240_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7941240_key_rightMajor, SW_JOIN_INNER_TD_7941240_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8263398_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _sm_ship_mode_sk360_k = tbl_Filter_TD_8263398_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7941240_key_rightMajor keyA{_sm_ship_mode_sk360_k};
            int32_t _sm_ship_mode_sk360 = tbl_Filter_TD_8263398_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _sm_type362_n = tbl_Filter_TD_8263398_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _sm_type362 = std::string(_sm_type362_n.data());
            SW_JOIN_INNER_TD_7941240_payload_rightMajor payloadA{_sm_ship_mode_sk360, _sm_type362};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_8555322_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_ship_mode_sk743_k = tbl_JOIN_INNER_TD_8555322_output.getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7941240_key_rightMajor{_ws_ship_mode_sk743_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _sm_ship_mode_sk360 = (it->second)._sm_ship_mode_sk360;
                std::string _sm_type362 = (it->second)._sm_type362;
                std::array<char, TPCDS_READ_MAX + 1> _sm_type362_n{};
                memcpy(_sm_type362_n.data(), (_sm_type362).data(), (_sm_type362).length());
                int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_8555322_output.getInt32(i, 0);
                int32_t _ws_ship_date_sk731 = tbl_JOIN_INNER_TD_8555322_output.getInt32(i, 1);
                int32_t _ws_web_site_sk742 = tbl_JOIN_INNER_TD_8555322_output.getInt32(i, 2);
                int32_t _ws_ship_mode_sk743 = tbl_JOIN_INNER_TD_8555322_output.getInt32(i, 3);
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_JOIN_INNER_TD_8555322_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
                tbl_JOIN_INNER_TD_7941240_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _sm_type362_n);
                tbl_JOIN_INNER_TD_7941240_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_7941240_output.setInt32(r, 1, _ws_ship_date_sk731);
                tbl_JOIN_INNER_TD_7941240_output.setInt32(r, 2, _ws_web_site_sk742);
                tbl_JOIN_INNER_TD_7941240_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _w_warehouse_name497_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7941240_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7941240_output #Row: " << tbl_JOIN_INNER_TD_7941240_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6757077(Table &tbl_SerializeFromObject_TD_7767525_input, Table &tbl_Filter_TD_6757077_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_month_seq#123) AND ((d_month_seq#123 >= 1200) AND (d_month_seq#123 <= 1211))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_month_seq#123)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7767525_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_month_seq123 = tbl_SerializeFromObject_TD_7767525_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_7767525_input.getInt32(i, 0);
        if (((_d_month_seq123!= 0) && ((_d_month_seq123 >= 1200) && (_d_month_seq123 <= 1211))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_7767525_input.getInt32(i, 0);
            tbl_Filter_TD_6757077_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_6757077_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6757077_output #Row: " << tbl_Filter_TD_6757077_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6100287_key_leftMajor {
    int32_t _ws_web_site_sk742;
    bool operator==(const SW_JOIN_INNER_TD_6100287_key_leftMajor& other) const {
        return ((_ws_web_site_sk742 == other._ws_web_site_sk742));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6100287_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6100287_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_web_site_sk742));
    }
};
}
struct SW_JOIN_INNER_TD_6100287_payload_leftMajor {
    int32_t _ws_sold_date_sk729;
    int32_t _ws_ship_date_sk731;
    int32_t _ws_web_site_sk742;
    std::string _w_warehouse_name497;
    std::string _sm_type362;
};
struct SW_JOIN_INNER_TD_6100287_key_rightMajor {
    int32_t _web_site_sk537;
    bool operator==(const SW_JOIN_INNER_TD_6100287_key_rightMajor& other) const {
        return ((_web_site_sk537 == other._web_site_sk537));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6100287_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6100287_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._web_site_sk537));
    }
};
}
struct SW_JOIN_INNER_TD_6100287_payload_rightMajor {
    int32_t _web_site_sk537;
    std::string _web_name541;
};
void SW_JOIN_INNER_TD_6100287(Table &tbl_JOIN_INNER_TD_7941240_output, Table &tbl_Filter_TD_7910097_output, Table &tbl_JOIN_INNER_TD_6100287_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_web_site_sk#742 = web_site_sk#537))
    // Left Table: ListBuffer(ws_sold_date_sk#729, ws_ship_date_sk#731, ws_web_site_sk#742, w_warehouse_name#497, sm_type#362)
    // Right Table: ListBuffer(web_site_sk#537, web_name#541)
    // Output Table: ListBuffer(ws_sold_date_sk#729, ws_ship_date_sk#731, w_warehouse_name#497, sm_type#362, web_name#541)
    int left_nrow = tbl_JOIN_INNER_TD_7941240_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7910097_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6100287_key_leftMajor, SW_JOIN_INNER_TD_6100287_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7941240_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_web_site_sk742_k = tbl_JOIN_INNER_TD_7941240_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_6100287_key_leftMajor keyA{_ws_web_site_sk742_k};
            int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_7941240_output.getInt32(i, 0);
            int32_t _ws_ship_date_sk731 = tbl_JOIN_INNER_TD_7941240_output.getInt32(i, 1);
            int32_t _ws_web_site_sk742 = tbl_JOIN_INNER_TD_7941240_output.getInt32(i, 2);
            std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_JOIN_INNER_TD_7941240_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _sm_type362_n = tbl_JOIN_INNER_TD_7941240_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _sm_type362 = std::string(_sm_type362_n.data());
            SW_JOIN_INNER_TD_6100287_payload_leftMajor payloadA{_ws_sold_date_sk729, _ws_ship_date_sk731, _ws_web_site_sk742, _w_warehouse_name497, _sm_type362};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7910097_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _web_site_sk537_k = tbl_Filter_TD_7910097_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6100287_key_leftMajor{_web_site_sk537_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_date_sk729 = (it->second)._ws_sold_date_sk729;
                int32_t _ws_ship_date_sk731 = (it->second)._ws_ship_date_sk731;
                int32_t _ws_web_site_sk742 = (it->second)._ws_web_site_sk742;
                std::string _w_warehouse_name497 = (it->second)._w_warehouse_name497;
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n{};
                memcpy(_w_warehouse_name497_n.data(), (_w_warehouse_name497).data(), (_w_warehouse_name497).length());
                std::string _sm_type362 = (it->second)._sm_type362;
                std::array<char, TPCDS_READ_MAX + 1> _sm_type362_n{};
                memcpy(_sm_type362_n.data(), (_sm_type362).data(), (_sm_type362).length());
                int32_t _web_site_sk537 = tbl_Filter_TD_7910097_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _web_name541_n = tbl_Filter_TD_7910097_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _web_name541 = std::string(_web_name541_n.data());
                tbl_JOIN_INNER_TD_6100287_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_6100287_output.setInt32(r, 1, _ws_ship_date_sk731);
                tbl_JOIN_INNER_TD_6100287_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _w_warehouse_name497_n);
                tbl_JOIN_INNER_TD_6100287_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _sm_type362_n);
                tbl_JOIN_INNER_TD_6100287_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _web_name541_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6100287_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6100287_key_rightMajor, SW_JOIN_INNER_TD_6100287_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7910097_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _web_site_sk537_k = tbl_Filter_TD_7910097_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6100287_key_rightMajor keyA{_web_site_sk537_k};
            int32_t _web_site_sk537 = tbl_Filter_TD_7910097_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _web_name541_n = tbl_Filter_TD_7910097_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _web_name541 = std::string(_web_name541_n.data());
            SW_JOIN_INNER_TD_6100287_payload_rightMajor payloadA{_web_site_sk537, _web_name541};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7941240_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_web_site_sk742_k = tbl_JOIN_INNER_TD_7941240_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6100287_key_rightMajor{_ws_web_site_sk742_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _web_site_sk537 = (it->second)._web_site_sk537;
                std::string _web_name541 = (it->second)._web_name541;
                std::array<char, TPCDS_READ_MAX + 1> _web_name541_n{};
                memcpy(_web_name541_n.data(), (_web_name541).data(), (_web_name541).length());
                int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_7941240_output.getInt32(i, 0);
                int32_t _ws_ship_date_sk731 = tbl_JOIN_INNER_TD_7941240_output.getInt32(i, 1);
                int32_t _ws_web_site_sk742 = tbl_JOIN_INNER_TD_7941240_output.getInt32(i, 2);
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_JOIN_INNER_TD_7941240_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _sm_type362_n = tbl_JOIN_INNER_TD_7941240_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _sm_type362 = std::string(_sm_type362_n.data());
                tbl_JOIN_INNER_TD_6100287_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _web_name541_n);
                tbl_JOIN_INNER_TD_6100287_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_6100287_output.setInt32(r, 1, _ws_ship_date_sk731);
                tbl_JOIN_INNER_TD_6100287_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _w_warehouse_name497_n);
                tbl_JOIN_INNER_TD_6100287_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _sm_type362_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6100287_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6100287_output #Row: " << tbl_JOIN_INNER_TD_6100287_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5764510_key_leftMajor {
    int32_t _ws_ship_date_sk731;
    bool operator==(const SW_JOIN_INNER_TD_5764510_key_leftMajor& other) const {
        return ((_ws_ship_date_sk731 == other._ws_ship_date_sk731));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5764510_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5764510_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_ship_date_sk731));
    }
};
}
struct SW_JOIN_INNER_TD_5764510_payload_leftMajor {
    int32_t _ws_sold_date_sk729;
    int32_t _ws_ship_date_sk731;
    std::string _w_warehouse_name497;
    std::string _sm_type362;
    std::string _web_name541;
};
struct SW_JOIN_INNER_TD_5764510_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_5764510_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5764510_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5764510_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_5764510_payload_rightMajor {
    int32_t _d_date_sk120;
};
void SW_JOIN_INNER_TD_5764510(Table &tbl_JOIN_INNER_TD_6100287_output, Table &tbl_Filter_TD_6757077_output, Table &tbl_JOIN_INNER_TD_5764510_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_ship_date_sk#731 = d_date_sk#120))
    // Left Table: ListBuffer(ws_sold_date_sk#729, ws_ship_date_sk#731, w_warehouse_name#497, sm_type#362, web_name#541)
    // Right Table: ListBuffer(d_date_sk#120)
    // Output Table: ListBuffer(ws_sold_date_sk#729, ws_ship_date_sk#731, sm_type#362, web_name#541, w_warehouse_name#497)
    int left_nrow = tbl_JOIN_INNER_TD_6100287_output.getNumRow();
    int right_nrow = tbl_Filter_TD_6757077_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5764510_key_leftMajor, SW_JOIN_INNER_TD_5764510_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_6100287_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_ship_date_sk731_k = tbl_JOIN_INNER_TD_6100287_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_5764510_key_leftMajor keyA{_ws_ship_date_sk731_k};
            int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_6100287_output.getInt32(i, 0);
            int32_t _ws_ship_date_sk731 = tbl_JOIN_INNER_TD_6100287_output.getInt32(i, 1);
            std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_JOIN_INNER_TD_6100287_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _sm_type362_n = tbl_JOIN_INNER_TD_6100287_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _sm_type362 = std::string(_sm_type362_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _web_name541_n = tbl_JOIN_INNER_TD_6100287_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _web_name541 = std::string(_web_name541_n.data());
            SW_JOIN_INNER_TD_5764510_payload_leftMajor payloadA{_ws_sold_date_sk729, _ws_ship_date_sk731, _w_warehouse_name497, _sm_type362, _web_name541};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6757077_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_6757077_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5764510_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_date_sk729 = (it->second)._ws_sold_date_sk729;
                int32_t _ws_ship_date_sk731 = (it->second)._ws_ship_date_sk731;
                std::string _w_warehouse_name497 = (it->second)._w_warehouse_name497;
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n{};
                memcpy(_w_warehouse_name497_n.data(), (_w_warehouse_name497).data(), (_w_warehouse_name497).length());
                std::string _sm_type362 = (it->second)._sm_type362;
                std::array<char, TPCDS_READ_MAX + 1> _sm_type362_n{};
                memcpy(_sm_type362_n.data(), (_sm_type362).data(), (_sm_type362).length());
                std::string _web_name541 = (it->second)._web_name541;
                std::array<char, TPCDS_READ_MAX + 1> _web_name541_n{};
                memcpy(_web_name541_n.data(), (_web_name541).data(), (_web_name541).length());
                int32_t _d_date_sk120 = tbl_Filter_TD_6757077_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_5764510_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_5764510_output.setInt32(r, 1, _ws_ship_date_sk731);
                tbl_JOIN_INNER_TD_5764510_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _w_warehouse_name497_n);
                tbl_JOIN_INNER_TD_5764510_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _sm_type362_n);
                tbl_JOIN_INNER_TD_5764510_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _web_name541_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5764510_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5764510_key_rightMajor, SW_JOIN_INNER_TD_5764510_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_6757077_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_6757077_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5764510_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_6757077_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5764510_payload_rightMajor payloadA{_d_date_sk120};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_6100287_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_ship_date_sk731_k = tbl_JOIN_INNER_TD_6100287_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5764510_key_rightMajor{_ws_ship_date_sk731_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_6100287_output.getInt32(i, 0);
                int32_t _ws_ship_date_sk731 = tbl_JOIN_INNER_TD_6100287_output.getInt32(i, 1);
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_JOIN_INNER_TD_6100287_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _sm_type362_n = tbl_JOIN_INNER_TD_6100287_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _sm_type362 = std::string(_sm_type362_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _web_name541_n = tbl_JOIN_INNER_TD_6100287_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _web_name541 = std::string(_web_name541_n.data());
                tbl_JOIN_INNER_TD_5764510_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_5764510_output.setInt32(r, 1, _ws_ship_date_sk731);
                tbl_JOIN_INNER_TD_5764510_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _w_warehouse_name497_n);
                tbl_JOIN_INNER_TD_5764510_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _sm_type362_n);
                tbl_JOIN_INNER_TD_5764510_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _web_name541_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5764510_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5764510_output #Row: " << tbl_JOIN_INNER_TD_5764510_output.getNumRow() << std::endl;
}

void SW_Project_TD_488822(Table &tbl_JOIN_INNER_TD_5764510_output, Table &tbl_Project_TD_488822_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(substr(w_warehouse_name#497, 1, 20) AS _groupingexpression#3646)
    // Input: ListBuffer(ws_sold_date_sk#729, ws_ship_date_sk#731, sm_type#362, web_name#541, w_warehouse_name#497)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_ship_date_sk#731, sm_type#362, web_name#541, _groupingexpression#3646)
    int nrow1 = tbl_JOIN_INNER_TD_5764510_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_5764510_output.getInt32(i, 0);
        int32_t _ws_ship_date_sk731 = tbl_JOIN_INNER_TD_5764510_output.getInt32(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _sm_type362 = tbl_JOIN_INNER_TD_5764510_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _web_name541 = tbl_JOIN_INNER_TD_5764510_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497 = tbl_JOIN_INNER_TD_5764510_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        std::string __groupingexpression3646_str = std::string(_w_warehouse_name497.data()).substr(0, 20);
        std::array<char, TPCDS_READ_MAX + 1> __groupingexpression3646{};
        memcpy(__groupingexpression3646.data(), __groupingexpression3646_str.data(), (__groupingexpression3646_str).length());
        tbl_Project_TD_488822_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 4, __groupingexpression3646);
        tbl_Project_TD_488822_output.setInt32(i, 0, _ws_sold_date_sk729);
        tbl_Project_TD_488822_output.setInt32(i, 1, _ws_ship_date_sk731);
        tbl_Project_TD_488822_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 2, _sm_type362);
        tbl_Project_TD_488822_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 3, _web_name541);
    }
    tbl_Project_TD_488822_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_488822_output #Row: " << tbl_Project_TD_488822_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_3269919_key {
    std::string __groupingexpression3646;
    std::string _sm_type362;
    std::string _web_name541;
    bool operator==(const SW_Aggregate_TD_3269919_key& other) const { return (__groupingexpression3646 == other.__groupingexpression3646) && (_sm_type362 == other._sm_type362) && (_web_name541 == other._web_name541); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_3269919_key> {
    std::size_t operator() (const SW_Aggregate_TD_3269919_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k.__groupingexpression3646)) + (hash<string>()(k._sm_type362)) + (hash<string>()(k._web_name541));
    }
};
}
struct SW_Aggregate_TD_3269919_payload {
    std::string substr_w_warehouse_name_1_20;
    int64_t _days3544L_sum_0;
    int64_t _days3545L_sum_1;
    int64_t _days3546L_sum_2;
    int64_t _days3547L_sum_3;
    int64_t _days3548L_sum_4;
};
void SW_Aggregate_TD_3269919(Table &tbl_Project_TD_488822_output, Table &tbl_Aggregate_TD_3269919_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(_groupingexpression#3646, sm_type#362, web_name#541, _groupingexpression#3646 AS substr(w_warehouse_name, 1, 20)#3554, sum(CASE WHEN ((ws_ship_date_sk#731 - ws_sold_date_sk#729) <= 30) THEN 1 ELSE 0 END) AS 30 days#3544L, sum(CASE WHEN (((ws_ship_date_sk#731 - ws_sold_date_sk#729) > 30) AND ((ws_ship_date_sk#731 - ws_sold_date_sk#729) <= 60)) THEN 1 ELSE 0 END) AS 31-60 days#3545L, sum(CASE WHEN (((ws_ship_date_sk#731 - ws_sold_date_sk#729) > 60) AND ((ws_ship_date_sk#731 - ws_sold_date_sk#729) <= 90)) THEN 1 ELSE 0 END) AS 61-90 days#3546L, sum(CASE WHEN (((ws_ship_date_sk#731 - ws_sold_date_sk#729) > 90) AND ((ws_ship_date_sk#731 - ws_sold_date_sk#729) <= 120)) THEN 1 ELSE 0 END) AS 91-120 days#3547L, sum(CASE WHEN ((ws_ship_date_sk#731 - ws_sold_date_sk#729) > 120) THEN 1 ELSE 0 END) AS >120 days#3548L)
    // Input: ListBuffer(ws_sold_date_sk#729, ws_ship_date_sk#731, sm_type#362, web_name#541, _groupingexpression#3646)
    // Output: ListBuffer(substr(w_warehouse_name, 1, 20)#3554, sm_type#362, web_name#541, 30 days#3544L, 31-60 days#3545L, 61-90 days#3546L, 91-120 days#3547L, >120 days#3548L)
    std::unordered_map<SW_Aggregate_TD_3269919_key, SW_Aggregate_TD_3269919_payload> ht1;
    int nrow1 = tbl_Project_TD_488822_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_sold_date_sk729 = tbl_Project_TD_488822_output.getInt32(i, 0);
        int32_t _ws_ship_date_sk731 = tbl_Project_TD_488822_output.getInt32(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _sm_type362 = tbl_Project_TD_488822_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _web_name541 = tbl_Project_TD_488822_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> __groupingexpression3646 = tbl_Project_TD_488822_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        SW_Aggregate_TD_3269919_key k{std::string(__groupingexpression3646.data()), std::string(_sm_type362.data()), std::string(_web_name541.data())};
        std::array<char, TPCDS_READ_MAX + 1> substr_w_warehouse_name_1_20 = __groupingexpression3646;
        int64_t _days3544L_sum_0 = ((_ws_ship_date_sk731 - _ws_sold_date_sk729) <= 30) ? 1 : 0;
        int64_t _days3545L_sum_1 = (((_ws_ship_date_sk731 - _ws_sold_date_sk729) > 30) && ((_ws_ship_date_sk731 - _ws_sold_date_sk729) <= 60)) ? 1 : 0;
        int64_t _days3546L_sum_2 = (((_ws_ship_date_sk731 - _ws_sold_date_sk729) > 60) && ((_ws_ship_date_sk731 - _ws_sold_date_sk729) <= 90)) ? 1 : 0;
        int64_t _days3547L_sum_3 = (((_ws_ship_date_sk731 - _ws_sold_date_sk729) > 90) && ((_ws_ship_date_sk731 - _ws_sold_date_sk729) <= 120)) ? 1 : 0;
        int64_t _days3548L_sum_4 = ((_ws_ship_date_sk731 - _ws_sold_date_sk729) > 120) ? 1 : 0;
        SW_Aggregate_TD_3269919_payload p{std::string(substr_w_warehouse_name_1_20.data()), _days3544L_sum_0, _days3545L_sum_1, _days3546L_sum_2, _days3547L_sum_3, _days3548L_sum_4};
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
        tbl_Aggregate_TD_3269919_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _sm_type362);
        std::array<char, TPCDS_READ_MAX + 1> _web_name541{};
        memcpy(_web_name541.data(), ((it.first)._web_name541).data(), ((it.first)._web_name541).length());
        tbl_Aggregate_TD_3269919_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _web_name541);
        std::array<char, TPCDS_READ_MAX + 1> substr_w_warehouse_name_1_20_n{};
        memcpy(substr_w_warehouse_name_1_20_n.data(), (it.second).substr_w_warehouse_name_1_20.data(), (it.second).substr_w_warehouse_name_1_20.length());
        tbl_Aggregate_TD_3269919_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, substr_w_warehouse_name_1_20_n);
        int64_t _days3544L = (it.second)._days3544L_sum_0;
        tbl_Aggregate_TD_3269919_output.setInt64(r, 3, _days3544L);
        int64_t _days3545L = (it.second)._days3545L_sum_1;
        tbl_Aggregate_TD_3269919_output.setInt64(r, 4, _days3545L);
        int64_t _days3546L = (it.second)._days3546L_sum_2;
        tbl_Aggregate_TD_3269919_output.setInt64(r, 5, _days3546L);
        int64_t _days3547L = (it.second)._days3547L_sum_3;
        tbl_Aggregate_TD_3269919_output.setInt64(r, 6, _days3547L);
        int64_t _days3548L = (it.second)._days3548L_sum_4;
        tbl_Aggregate_TD_3269919_output.setInt64(r, 7, _days3548L);
        ++r;
    }
    tbl_Aggregate_TD_3269919_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_3269919_output #Row: " << tbl_Aggregate_TD_3269919_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2270030(Table &tbl_Aggregate_TD_3269919_output, Table &tbl_Sort_TD_2270030_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(substr(w_warehouse_name, 1, 20)#3554 ASC NULLS FIRST, sm_type#362 ASC NULLS FIRST, web_name#541 ASC NULLS FIRST)
    // Input: ListBuffer(substr(w_warehouse_name, 1, 20)#3554, sm_type#362, web_name#541, 30 days#3544L, 31-60 days#3545L, 61-90 days#3546L, 91-120 days#3547L, >120 days#3548L)
    // Output: ListBuffer(substr(w_warehouse_name, 1, 20)#3554, sm_type#362, web_name#541, 30 days#3544L, 31-60 days#3545L, 61-90 days#3546L, 91-120 days#3547L, >120 days#3548L)
    struct SW_Sort_TD_2270030Row {
        std::string substr_w_warehouse_name_1_20;
        std::string _sm_type362;
        std::string _web_name541;
        int64_t _days3544L;
        int64_t _days3545L;
        int64_t _days3546L;
        int64_t _days3547L;
        int64_t _days3548L;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2270030Row& a, const SW_Sort_TD_2270030Row& b) const { return 
 (a.substr_w_warehouse_name_1_20 < b.substr_w_warehouse_name_1_20) || 
 ((a.substr_w_warehouse_name_1_20 == b.substr_w_warehouse_name_1_20) && (a._sm_type362 < b._sm_type362)) || 
 ((a.substr_w_warehouse_name_1_20 == b.substr_w_warehouse_name_1_20) && (a._sm_type362 == b._sm_type362) && (a._web_name541 < b._web_name541)); 
}
    }SW_Sort_TD_2270030_order; 

    int nrow1 = tbl_Aggregate_TD_3269919_output.getNumRow();
    std::vector<SW_Sort_TD_2270030Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> substr_w_warehouse_name_1_20 = tbl_Aggregate_TD_3269919_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _sm_type362 = tbl_Aggregate_TD_3269919_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _web_name541 = tbl_Aggregate_TD_3269919_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        int64_t _days3544L = tbl_Aggregate_TD_3269919_output.getInt64(i, 3);
        int64_t _days3545L = tbl_Aggregate_TD_3269919_output.getInt64(i, 4);
        int64_t _days3546L = tbl_Aggregate_TD_3269919_output.getInt64(i, 5);
        int64_t _days3547L = tbl_Aggregate_TD_3269919_output.getInt64(i, 6);
        int64_t _days3548L = tbl_Aggregate_TD_3269919_output.getInt64(i, 7);
        SW_Sort_TD_2270030Row t = {std::string(substr_w_warehouse_name_1_20.data()),std::string(_sm_type362.data()),std::string(_web_name541.data()),_days3544L,_days3545L,_days3546L,_days3547L,_days3548L};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2270030_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> substr_w_warehouse_name_1_20{};
        memcpy(substr_w_warehouse_name_1_20.data(), (it.substr_w_warehouse_name_1_20).data(), (it.substr_w_warehouse_name_1_20).length());
        tbl_Sort_TD_2270030_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, substr_w_warehouse_name_1_20);
        std::array<char, TPCDS_READ_MAX + 1> _sm_type362{};
        memcpy(_sm_type362.data(), (it._sm_type362).data(), (it._sm_type362).length());
        tbl_Sort_TD_2270030_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _sm_type362);
        std::array<char, TPCDS_READ_MAX + 1> _web_name541{};
        memcpy(_web_name541.data(), (it._web_name541).data(), (it._web_name541).length());
        tbl_Sort_TD_2270030_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _web_name541);
        tbl_Sort_TD_2270030_output.setInt64(r, 3, it._days3544L);
        tbl_Sort_TD_2270030_output.setInt64(r, 4, it._days3545L);
        tbl_Sort_TD_2270030_output.setInt64(r, 5, it._days3546L);
        tbl_Sort_TD_2270030_output.setInt64(r, 6, it._days3547L);
        tbl_Sort_TD_2270030_output.setInt64(r, 7, it._days3548L);
        ++r;
    }
    tbl_Sort_TD_2270030_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2270030_output #Row: " << tbl_Sort_TD_2270030_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1152328(Table &tbl_Sort_TD_2270030_output, Table &tbl_LocalLimit_TD_1152328_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(substr(w_warehouse_name, 1, 20)#3554, sm_type#362, web_name#541, 30 days#3544L, 31-60 days#3545L, 61-90 days#3546L, 91-120 days#3547L, >120 days#3548L)
    // Output: ListBuffer(substr(w_warehouse_name, 1, 20)#3554, sm_type#362, web_name#541, 30 days#3544L, 31-60 days#3545L, 61-90 days#3546L, 91-120 days#3547L, >120 days#3548L)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> substr_w_warehouse_name_1_20_n = tbl_Sort_TD_2270030_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1152328_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, substr_w_warehouse_name_1_20_n);
        std::array<char, TPCDS_READ_MAX + 1> _sm_type362_n = tbl_Sort_TD_2270030_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_1152328_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _sm_type362_n);
        std::array<char, TPCDS_READ_MAX + 1> _web_name541_n = tbl_Sort_TD_2270030_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_LocalLimit_TD_1152328_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _web_name541_n);
        tbl_LocalLimit_TD_1152328_output.setInt64(r, 3, tbl_Sort_TD_2270030_output.getInt64(i, 3));
        tbl_LocalLimit_TD_1152328_output.setInt64(r, 4, tbl_Sort_TD_2270030_output.getInt64(i, 4));
        tbl_LocalLimit_TD_1152328_output.setInt64(r, 5, tbl_Sort_TD_2270030_output.getInt64(i, 5));
        tbl_LocalLimit_TD_1152328_output.setInt64(r, 6, tbl_Sort_TD_2270030_output.getInt64(i, 6));
        tbl_LocalLimit_TD_1152328_output.setInt64(r, 7, tbl_Sort_TD_2270030_output.getInt64(i, 7));
        r++;
    }
    tbl_LocalLimit_TD_1152328_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1152328_output #Row: " << tbl_LocalLimit_TD_1152328_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0581969(Table &tbl_LocalLimit_TD_1152328_output, Table &tbl_GlobalLimit_TD_0581969_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(substr(w_warehouse_name, 1, 20)#3554, sm_type#362, web_name#541, 30 days#3544L, 31-60 days#3545L, 61-90 days#3546L, 91-120 days#3547L, >120 days#3548L)
    // Output: ListBuffer(substr(w_warehouse_name, 1, 20)#3554, sm_type#362, web_name#541, 30 days#3544L, 31-60 days#3545L, 61-90 days#3546L, 91-120 days#3547L, >120 days#3548L)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> substr_w_warehouse_name_1_20_n = tbl_LocalLimit_TD_1152328_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0581969_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, substr_w_warehouse_name_1_20_n);
        std::array<char, TPCDS_READ_MAX + 1> _sm_type362_n = tbl_LocalLimit_TD_1152328_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_0581969_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _sm_type362_n);
        std::array<char, TPCDS_READ_MAX + 1> _web_name541_n = tbl_LocalLimit_TD_1152328_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_GlobalLimit_TD_0581969_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _web_name541_n);
        tbl_GlobalLimit_TD_0581969_output.setInt64(r, 3, tbl_LocalLimit_TD_1152328_output.getInt64(i, 3));
        tbl_GlobalLimit_TD_0581969_output.setInt64(r, 4, tbl_LocalLimit_TD_1152328_output.getInt64(i, 4));
        tbl_GlobalLimit_TD_0581969_output.setInt64(r, 5, tbl_LocalLimit_TD_1152328_output.getInt64(i, 5));
        tbl_GlobalLimit_TD_0581969_output.setInt64(r, 6, tbl_LocalLimit_TD_1152328_output.getInt64(i, 6));
        tbl_GlobalLimit_TD_0581969_output.setInt64(r, 7, tbl_LocalLimit_TD_1152328_output.getInt64(i, 7));
        r++;
    }
    tbl_GlobalLimit_TD_0581969_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0581969_output #Row: " << tbl_GlobalLimit_TD_0581969_output.getNumRow() << std::endl;
}

