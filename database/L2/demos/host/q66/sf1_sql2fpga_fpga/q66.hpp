#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_1054168(Table &tbl_SerializeFromObject_TD_11544265_input, Table &tbl_Filter_TD_1054168_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(w_warehouse_sk#3632))
    // Input: ListBuffer(w_warehouse_sk#3632, w_warehouse_name#3634, w_warehouse_sq_ft#3635, w_city#3640, w_county#3641, w_state#3642, w_country#3644)
    // Output: ListBuffer(w_warehouse_sk#3632, w_warehouse_name#3634, w_warehouse_sq_ft#3635, w_city#3640, w_county#3641, w_state#3642, w_country#3644)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11544265_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _w_warehouse_sk3632 = tbl_SerializeFromObject_TD_11544265_input.getInt32(i, 0);
        if (_w_warehouse_sk3632!= 0) {
            int32_t _w_warehouse_sk3632_t = tbl_SerializeFromObject_TD_11544265_input.getInt32(i, 0);
            tbl_Filter_TD_1054168_output.setInt32(r, 0, _w_warehouse_sk3632_t);
            std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name3634_t = tbl_SerializeFromObject_TD_11544265_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_1054168_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _w_warehouse_name3634_t);
            int32_t _w_warehouse_sq_ft3635_t = tbl_SerializeFromObject_TD_11544265_input.getInt32(i, 2);
            tbl_Filter_TD_1054168_output.setInt32(r, 2, _w_warehouse_sq_ft3635_t);
            std::array<char, TPCDS_READ_MAX + 1> _w_city3640_t = tbl_SerializeFromObject_TD_11544265_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_1054168_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _w_city3640_t);
            std::array<char, TPCDS_READ_MAX + 1> _w_county3641_t = tbl_SerializeFromObject_TD_11544265_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            tbl_Filter_TD_1054168_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _w_county3641_t);
            std::array<char, TPCDS_READ_MAX + 1> _w_state3642_t = tbl_SerializeFromObject_TD_11544265_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            tbl_Filter_TD_1054168_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _w_state3642_t);
            std::array<char, TPCDS_READ_MAX + 1> _w_country3644_t = tbl_SerializeFromObject_TD_11544265_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            tbl_Filter_TD_1054168_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _w_country3644_t);
            r++;
        }
    }
    tbl_Filter_TD_1054168_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1054168_output #Row: " << tbl_Filter_TD_1054168_output.getNumRow() << std::endl;
}

void SW_Filter_TD_1048090(Table &tbl_SerializeFromObject_TD_11702404_input, Table &tbl_Filter_TD_1048090_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(cs_warehouse_sk#1118) AND isnotnull(cs_sold_date_sk#1104)) AND (isnotnull(cs_sold_time_sk#1105) AND isnotnull(cs_ship_mode_sk#1117))))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_sold_time_sk#1105, cs_ship_mode_sk#1117, cs_warehouse_sk#1118, cs_quantity#1122, cs_sales_price#1125, cs_net_paid_inc_tax#1134)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_sold_time_sk#1105, cs_ship_mode_sk#1117, cs_warehouse_sk#1118, cs_quantity#1122, cs_sales_price#1125, cs_net_paid_inc_tax#1134)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11702404_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_warehouse_sk1118 = tbl_SerializeFromObject_TD_11702404_input.getInt32(i, 3);
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_11702404_input.getInt32(i, 0);
        int32_t _cs_sold_time_sk1105 = tbl_SerializeFromObject_TD_11702404_input.getInt32(i, 1);
        int32_t _cs_ship_mode_sk1117 = tbl_SerializeFromObject_TD_11702404_input.getInt32(i, 2);
        if (((_cs_warehouse_sk1118!= 0) && (_cs_sold_date_sk1104!= 0)) && ((_cs_sold_time_sk1105!= 0) && (_cs_ship_mode_sk1117!= 0))) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_11702404_input.getInt32(i, 0);
            tbl_Filter_TD_1048090_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int32_t _cs_sold_time_sk1105_t = tbl_SerializeFromObject_TD_11702404_input.getInt32(i, 1);
            tbl_Filter_TD_1048090_output.setInt32(r, 1, _cs_sold_time_sk1105_t);
            int32_t _cs_ship_mode_sk1117_t = tbl_SerializeFromObject_TD_11702404_input.getInt32(i, 2);
            tbl_Filter_TD_1048090_output.setInt32(r, 2, _cs_ship_mode_sk1117_t);
            int32_t _cs_warehouse_sk1118_t = tbl_SerializeFromObject_TD_11702404_input.getInt32(i, 3);
            tbl_Filter_TD_1048090_output.setInt32(r, 3, _cs_warehouse_sk1118_t);
            int32_t _cs_quantity1122_t = tbl_SerializeFromObject_TD_11702404_input.getInt32(i, 4);
            tbl_Filter_TD_1048090_output.setInt32(r, 4, _cs_quantity1122_t);
            int64_t _cs_sales_price1125_t = tbl_SerializeFromObject_TD_11702404_input.getInt64(i, 5);
            tbl_Filter_TD_1048090_output.setInt64(r, 5, _cs_sales_price1125_t);
            int64_t _cs_net_paid_inc_tax1134_t = tbl_SerializeFromObject_TD_11702404_input.getInt64(i, 6);
            tbl_Filter_TD_1048090_output.setInt64(r, 6, _cs_net_paid_inc_tax1134_t);
            r++;
        }
    }
    tbl_Filter_TD_1048090_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1048090_output #Row: " << tbl_Filter_TD_1048090_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10138559(Table &tbl_SerializeFromObject_TD_11232543_input, Table &tbl_Filter_TD_10138559_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(w_warehouse_sk#495))
    // Input: ListBuffer(w_warehouse_sk#495, w_warehouse_name#497, w_warehouse_sq_ft#498, w_city#503, w_county#504, w_state#505, w_country#507)
    // Output: ListBuffer(w_warehouse_sk#495, w_warehouse_name#497, w_warehouse_sq_ft#498, w_city#503, w_county#504, w_state#505, w_country#507)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11232543_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _w_warehouse_sk495 = tbl_SerializeFromObject_TD_11232543_input.getInt32(i, 0);
        if (_w_warehouse_sk495!= 0) {
            int32_t _w_warehouse_sk495_t = tbl_SerializeFromObject_TD_11232543_input.getInt32(i, 0);
            tbl_Filter_TD_10138559_output.setInt32(r, 0, _w_warehouse_sk495_t);
            std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_t = tbl_SerializeFromObject_TD_11232543_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_10138559_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _w_warehouse_name497_t);
            int32_t _w_warehouse_sq_ft498_t = tbl_SerializeFromObject_TD_11232543_input.getInt32(i, 2);
            tbl_Filter_TD_10138559_output.setInt32(r, 2, _w_warehouse_sq_ft498_t);
            std::array<char, TPCDS_READ_MAX + 1> _w_city503_t = tbl_SerializeFromObject_TD_11232543_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_10138559_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _w_city503_t);
            std::array<char, TPCDS_READ_MAX + 1> _w_county504_t = tbl_SerializeFromObject_TD_11232543_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            tbl_Filter_TD_10138559_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _w_county504_t);
            std::array<char, TPCDS_READ_MAX + 1> _w_state505_t = tbl_SerializeFromObject_TD_11232543_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            tbl_Filter_TD_10138559_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _w_state505_t);
            std::array<char, TPCDS_READ_MAX + 1> _w_country507_t = tbl_SerializeFromObject_TD_11232543_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            tbl_Filter_TD_10138559_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _w_country507_t);
            r++;
        }
    }
    tbl_Filter_TD_10138559_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10138559_output #Row: " << tbl_Filter_TD_10138559_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10567282(Table &tbl_SerializeFromObject_TD_11725552_input, Table &tbl_Filter_TD_10567282_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ws_warehouse_sk#744) AND isnotnull(ws_sold_date_sk#729)) AND (isnotnull(ws_sold_time_sk#730) AND isnotnull(ws_ship_mode_sk#743))))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_sold_time_sk#730, ws_ship_mode_sk#743, ws_warehouse_sk#744, ws_quantity#747, ws_ext_sales_price#752, ws_net_paid#758)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_sold_time_sk#730, ws_ship_mode_sk#743, ws_warehouse_sk#744, ws_quantity#747, ws_ext_sales_price#752, ws_net_paid#758)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11725552_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_warehouse_sk744 = tbl_SerializeFromObject_TD_11725552_input.getInt32(i, 3);
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_11725552_input.getInt32(i, 0);
        int32_t _ws_sold_time_sk730 = tbl_SerializeFromObject_TD_11725552_input.getInt32(i, 1);
        int32_t _ws_ship_mode_sk743 = tbl_SerializeFromObject_TD_11725552_input.getInt32(i, 2);
        if (((_ws_warehouse_sk744!= 0) && (_ws_sold_date_sk729!= 0)) && ((_ws_sold_time_sk730!= 0) && (_ws_ship_mode_sk743!= 0))) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_11725552_input.getInt32(i, 0);
            tbl_Filter_TD_10567282_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_sold_time_sk730_t = tbl_SerializeFromObject_TD_11725552_input.getInt32(i, 1);
            tbl_Filter_TD_10567282_output.setInt32(r, 1, _ws_sold_time_sk730_t);
            int32_t _ws_ship_mode_sk743_t = tbl_SerializeFromObject_TD_11725552_input.getInt32(i, 2);
            tbl_Filter_TD_10567282_output.setInt32(r, 2, _ws_ship_mode_sk743_t);
            int32_t _ws_warehouse_sk744_t = tbl_SerializeFromObject_TD_11725552_input.getInt32(i, 3);
            tbl_Filter_TD_10567282_output.setInt32(r, 3, _ws_warehouse_sk744_t);
            int32_t _ws_quantity747_t = tbl_SerializeFromObject_TD_11725552_input.getInt32(i, 4);
            tbl_Filter_TD_10567282_output.setInt32(r, 4, _ws_quantity747_t);
            int64_t _ws_ext_sales_price752_t = tbl_SerializeFromObject_TD_11725552_input.getInt64(i, 5);
            tbl_Filter_TD_10567282_output.setInt64(r, 5, _ws_ext_sales_price752_t);
            int64_t _ws_net_paid758_t = tbl_SerializeFromObject_TD_11725552_input.getInt64(i, 6);
            tbl_Filter_TD_10567282_output.setInt64(r, 6, _ws_net_paid758_t);
            r++;
        }
    }
    tbl_Filter_TD_10567282_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10567282_output #Row: " << tbl_Filter_TD_10567282_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9220854(Table &tbl_SerializeFromObject_TD_10448007_input, Table &tbl_Filter_TD_9220854_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3652) AND (d_year#3652 = 2001)) AND isnotnull(d_date_sk#3646)))
    // Input: ListBuffer(d_date_sk#3646, d_year#3652, d_moy#3654)
    // Output: ListBuffer(d_date_sk#3646, d_year#3652, d_moy#3654)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10448007_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3652 = tbl_SerializeFromObject_TD_10448007_input.getInt32(i, 1);
        int32_t _d_date_sk3646 = tbl_SerializeFromObject_TD_10448007_input.getInt32(i, 0);
        if (((_d_year3652!= 0) && (_d_year3652 == 2001)) && (_d_date_sk3646!= 0)) {
            int32_t _d_date_sk3646_t = tbl_SerializeFromObject_TD_10448007_input.getInt32(i, 0);
            tbl_Filter_TD_9220854_output.setInt32(r, 0, _d_date_sk3646_t);
            int32_t _d_year3652_t = tbl_SerializeFromObject_TD_10448007_input.getInt32(i, 1);
            tbl_Filter_TD_9220854_output.setInt32(r, 1, _d_year3652_t);
            int32_t _d_moy3654_t = tbl_SerializeFromObject_TD_10448007_input.getInt32(i, 2);
            tbl_Filter_TD_9220854_output.setInt32(r, 2, _d_moy3654_t);
            r++;
        }
    }
    tbl_Filter_TD_9220854_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9220854_output #Row: " << tbl_Filter_TD_9220854_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_9386501_key_leftMajor {
    int32_t _cs_warehouse_sk1118;
    bool operator==(const SW_JOIN_INNER_TD_9386501_key_leftMajor& other) const {
        return ((_cs_warehouse_sk1118 == other._cs_warehouse_sk1118));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9386501_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9386501_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_warehouse_sk1118));
    }
};
}
struct SW_JOIN_INNER_TD_9386501_payload_leftMajor {
    int32_t _cs_sold_date_sk1104;
    int32_t _cs_sold_time_sk1105;
    int32_t _cs_ship_mode_sk1117;
    int32_t _cs_warehouse_sk1118;
    int32_t _cs_quantity1122;
    int64_t _cs_sales_price1125;
    int64_t _cs_net_paid_inc_tax1134;
};
struct SW_JOIN_INNER_TD_9386501_key_rightMajor {
    int32_t _w_warehouse_sk3632;
    bool operator==(const SW_JOIN_INNER_TD_9386501_key_rightMajor& other) const {
        return ((_w_warehouse_sk3632 == other._w_warehouse_sk3632));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9386501_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9386501_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._w_warehouse_sk3632));
    }
};
}
struct SW_JOIN_INNER_TD_9386501_payload_rightMajor {
    int32_t _w_warehouse_sk3632;
    std::string _w_warehouse_name3634;
    int32_t _w_warehouse_sq_ft3635;
    std::string _w_city3640;
    std::string _w_county3641;
    std::string _w_state3642;
    std::string _w_country3644;
};
void SW_JOIN_INNER_TD_9386501(Table &tbl_Filter_TD_1048090_output, Table &tbl_Filter_TD_1054168_output, Table &tbl_JOIN_INNER_TD_9386501_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_warehouse_sk#1118 = w_warehouse_sk#3632))
    // Left Table: ListBuffer(cs_sold_date_sk#1104, cs_sold_time_sk#1105, cs_ship_mode_sk#1117, cs_warehouse_sk#1118, cs_quantity#1122, cs_sales_price#1125, cs_net_paid_inc_tax#1134)
    // Right Table: ListBuffer(w_warehouse_sk#3632, w_warehouse_name#3634, w_warehouse_sq_ft#3635, w_city#3640, w_county#3641, w_state#3642, w_country#3644)
    // Output Table: ListBuffer(cs_sold_date_sk#1104, cs_sold_time_sk#1105, cs_ship_mode_sk#1117, cs_quantity#1122, cs_sales_price#1125, cs_net_paid_inc_tax#1134, w_warehouse_name#3634, w_warehouse_sq_ft#3635, w_city#3640, w_county#3641, w_state#3642, w_country#3644)
    int left_nrow = tbl_Filter_TD_1048090_output.getNumRow();
    int right_nrow = tbl_Filter_TD_1054168_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9386501_key_leftMajor, SW_JOIN_INNER_TD_9386501_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_1048090_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_warehouse_sk1118_k = tbl_Filter_TD_1048090_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_9386501_key_leftMajor keyA{_cs_warehouse_sk1118_k};
            int32_t _cs_sold_date_sk1104 = tbl_Filter_TD_1048090_output.getInt32(i, 0);
            int32_t _cs_sold_time_sk1105 = tbl_Filter_TD_1048090_output.getInt32(i, 1);
            int32_t _cs_ship_mode_sk1117 = tbl_Filter_TD_1048090_output.getInt32(i, 2);
            int32_t _cs_warehouse_sk1118 = tbl_Filter_TD_1048090_output.getInt32(i, 3);
            int32_t _cs_quantity1122 = tbl_Filter_TD_1048090_output.getInt32(i, 4);
            int64_t _cs_sales_price1125 = tbl_Filter_TD_1048090_output.getInt64(i, 5);
            int64_t _cs_net_paid_inc_tax1134 = tbl_Filter_TD_1048090_output.getInt64(i, 6);
            SW_JOIN_INNER_TD_9386501_payload_leftMajor payloadA{_cs_sold_date_sk1104, _cs_sold_time_sk1105, _cs_ship_mode_sk1117, _cs_warehouse_sk1118, _cs_quantity1122, _cs_sales_price1125, _cs_net_paid_inc_tax1134};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_1054168_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _w_warehouse_sk3632_k = tbl_Filter_TD_1054168_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9386501_key_leftMajor{_w_warehouse_sk3632_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk1104 = (it->second)._cs_sold_date_sk1104;
                int32_t _cs_sold_time_sk1105 = (it->second)._cs_sold_time_sk1105;
                int32_t _cs_ship_mode_sk1117 = (it->second)._cs_ship_mode_sk1117;
                int32_t _cs_warehouse_sk1118 = (it->second)._cs_warehouse_sk1118;
                int32_t _cs_quantity1122 = (it->second)._cs_quantity1122;
                int64_t _cs_sales_price1125 = (it->second)._cs_sales_price1125;
                int64_t _cs_net_paid_inc_tax1134 = (it->second)._cs_net_paid_inc_tax1134;
                int32_t _w_warehouse_sk3632 = tbl_Filter_TD_1054168_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name3634_n = tbl_Filter_TD_1054168_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _w_warehouse_name3634 = std::string(_w_warehouse_name3634_n.data());
                int32_t _w_warehouse_sq_ft3635 = tbl_Filter_TD_1054168_output.getInt32(i, 2);
                std::array<char, TPCDS_READ_MAX + 1> _w_city3640_n = tbl_Filter_TD_1054168_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _w_city3640 = std::string(_w_city3640_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _w_county3641_n = tbl_Filter_TD_1054168_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _w_county3641 = std::string(_w_county3641_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _w_state3642_n = tbl_Filter_TD_1054168_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _w_state3642 = std::string(_w_state3642_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _w_country3644_n = tbl_Filter_TD_1054168_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _w_country3644 = std::string(_w_country3644_n.data());
                tbl_JOIN_INNER_TD_9386501_output.setInt32(r, 0, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_9386501_output.setInt32(r, 1, _cs_sold_time_sk1105);
                tbl_JOIN_INNER_TD_9386501_output.setInt32(r, 2, _cs_ship_mode_sk1117);
                tbl_JOIN_INNER_TD_9386501_output.setInt32(r, 3, _cs_quantity1122);
                tbl_JOIN_INNER_TD_9386501_output.setInt64(r, 4, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_9386501_output.setInt64(r, 5, _cs_net_paid_inc_tax1134);
                tbl_JOIN_INNER_TD_9386501_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _w_warehouse_name3634_n);
                tbl_JOIN_INNER_TD_9386501_output.setInt32(r, 7, _w_warehouse_sq_ft3635);
                tbl_JOIN_INNER_TD_9386501_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _w_city3640_n);
                tbl_JOIN_INNER_TD_9386501_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _w_county3641_n);
                tbl_JOIN_INNER_TD_9386501_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _w_state3642_n);
                tbl_JOIN_INNER_TD_9386501_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _w_country3644_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9386501_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9386501_key_rightMajor, SW_JOIN_INNER_TD_9386501_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_1054168_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _w_warehouse_sk3632_k = tbl_Filter_TD_1054168_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_9386501_key_rightMajor keyA{_w_warehouse_sk3632_k};
            int32_t _w_warehouse_sk3632 = tbl_Filter_TD_1054168_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name3634_n = tbl_Filter_TD_1054168_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _w_warehouse_name3634 = std::string(_w_warehouse_name3634_n.data());
            int32_t _w_warehouse_sq_ft3635 = tbl_Filter_TD_1054168_output.getInt32(i, 2);
            std::array<char, TPCDS_READ_MAX + 1> _w_city3640_n = tbl_Filter_TD_1054168_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _w_city3640 = std::string(_w_city3640_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _w_county3641_n = tbl_Filter_TD_1054168_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _w_county3641 = std::string(_w_county3641_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _w_state3642_n = tbl_Filter_TD_1054168_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _w_state3642 = std::string(_w_state3642_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _w_country3644_n = tbl_Filter_TD_1054168_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _w_country3644 = std::string(_w_country3644_n.data());
            SW_JOIN_INNER_TD_9386501_payload_rightMajor payloadA{_w_warehouse_sk3632, _w_warehouse_name3634, _w_warehouse_sq_ft3635, _w_city3640, _w_county3641, _w_state3642, _w_country3644};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_1048090_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_warehouse_sk1118_k = tbl_Filter_TD_1048090_output.getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9386501_key_rightMajor{_cs_warehouse_sk1118_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _w_warehouse_sk3632 = (it->second)._w_warehouse_sk3632;
                std::string _w_warehouse_name3634 = (it->second)._w_warehouse_name3634;
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name3634_n{};
                memcpy(_w_warehouse_name3634_n.data(), (_w_warehouse_name3634).data(), (_w_warehouse_name3634).length());
                int32_t _w_warehouse_sq_ft3635 = (it->second)._w_warehouse_sq_ft3635;
                std::string _w_city3640 = (it->second)._w_city3640;
                std::array<char, TPCDS_READ_MAX + 1> _w_city3640_n{};
                memcpy(_w_city3640_n.data(), (_w_city3640).data(), (_w_city3640).length());
                std::string _w_county3641 = (it->second)._w_county3641;
                std::array<char, TPCDS_READ_MAX + 1> _w_county3641_n{};
                memcpy(_w_county3641_n.data(), (_w_county3641).data(), (_w_county3641).length());
                std::string _w_state3642 = (it->second)._w_state3642;
                std::array<char, TPCDS_READ_MAX + 1> _w_state3642_n{};
                memcpy(_w_state3642_n.data(), (_w_state3642).data(), (_w_state3642).length());
                std::string _w_country3644 = (it->second)._w_country3644;
                std::array<char, TPCDS_READ_MAX + 1> _w_country3644_n{};
                memcpy(_w_country3644_n.data(), (_w_country3644).data(), (_w_country3644).length());
                int32_t _cs_sold_date_sk1104 = tbl_Filter_TD_1048090_output.getInt32(i, 0);
                int32_t _cs_sold_time_sk1105 = tbl_Filter_TD_1048090_output.getInt32(i, 1);
                int32_t _cs_ship_mode_sk1117 = tbl_Filter_TD_1048090_output.getInt32(i, 2);
                int32_t _cs_warehouse_sk1118 = tbl_Filter_TD_1048090_output.getInt32(i, 3);
                int32_t _cs_quantity1122 = tbl_Filter_TD_1048090_output.getInt32(i, 4);
                int64_t _cs_sales_price1125 = tbl_Filter_TD_1048090_output.getInt64(i, 5);
                int64_t _cs_net_paid_inc_tax1134 = tbl_Filter_TD_1048090_output.getInt64(i, 6);
                tbl_JOIN_INNER_TD_9386501_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _w_warehouse_name3634_n);
                tbl_JOIN_INNER_TD_9386501_output.setInt32(r, 7, _w_warehouse_sq_ft3635);
                tbl_JOIN_INNER_TD_9386501_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _w_city3640_n);
                tbl_JOIN_INNER_TD_9386501_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _w_county3641_n);
                tbl_JOIN_INNER_TD_9386501_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _w_state3642_n);
                tbl_JOIN_INNER_TD_9386501_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _w_country3644_n);
                tbl_JOIN_INNER_TD_9386501_output.setInt32(r, 0, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_9386501_output.setInt32(r, 1, _cs_sold_time_sk1105);
                tbl_JOIN_INNER_TD_9386501_output.setInt32(r, 2, _cs_ship_mode_sk1117);
                tbl_JOIN_INNER_TD_9386501_output.setInt32(r, 3, _cs_quantity1122);
                tbl_JOIN_INNER_TD_9386501_output.setInt64(r, 4, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_9386501_output.setInt64(r, 5, _cs_net_paid_inc_tax1134);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9386501_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_9386501_output #Row: " << tbl_JOIN_INNER_TD_9386501_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9609467(Table &tbl_SerializeFromObject_TD_10715200_input, Table &tbl_Filter_TD_9609467_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#126) AND (d_year#126 = 2001)) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126, d_moy#128)
    // Output: ListBuffer(d_date_sk#120, d_year#126, d_moy#128)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10715200_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_10715200_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_10715200_input.getInt32(i, 0);
        if (((_d_year126!= 0) && (_d_year126 == 2001)) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_10715200_input.getInt32(i, 0);
            tbl_Filter_TD_9609467_output.setInt32(r, 0, _d_date_sk120_t);
            int32_t _d_year126_t = tbl_SerializeFromObject_TD_10715200_input.getInt32(i, 1);
            tbl_Filter_TD_9609467_output.setInt32(r, 1, _d_year126_t);
            int32_t _d_moy128_t = tbl_SerializeFromObject_TD_10715200_input.getInt32(i, 2);
            tbl_Filter_TD_9609467_output.setInt32(r, 2, _d_moy128_t);
            r++;
        }
    }
    tbl_Filter_TD_9609467_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9609467_output #Row: " << tbl_Filter_TD_9609467_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_9942357_key_leftMajor {
    int32_t _ws_warehouse_sk744;
    bool operator==(const SW_JOIN_INNER_TD_9942357_key_leftMajor& other) const {
        return ((_ws_warehouse_sk744 == other._ws_warehouse_sk744));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9942357_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9942357_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_warehouse_sk744));
    }
};
}
struct SW_JOIN_INNER_TD_9942357_payload_leftMajor {
    int32_t _ws_sold_date_sk729;
    int32_t _ws_sold_time_sk730;
    int32_t _ws_ship_mode_sk743;
    int32_t _ws_warehouse_sk744;
    int32_t _ws_quantity747;
    int64_t _ws_ext_sales_price752;
    int64_t _ws_net_paid758;
};
struct SW_JOIN_INNER_TD_9942357_key_rightMajor {
    int32_t _w_warehouse_sk495;
    bool operator==(const SW_JOIN_INNER_TD_9942357_key_rightMajor& other) const {
        return ((_w_warehouse_sk495 == other._w_warehouse_sk495));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9942357_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9942357_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._w_warehouse_sk495));
    }
};
}
struct SW_JOIN_INNER_TD_9942357_payload_rightMajor {
    int32_t _w_warehouse_sk495;
    std::string _w_warehouse_name497;
    int32_t _w_warehouse_sq_ft498;
    std::string _w_city503;
    std::string _w_county504;
    std::string _w_state505;
    std::string _w_country507;
};
void SW_JOIN_INNER_TD_9942357(Table &tbl_Filter_TD_10567282_output, Table &tbl_Filter_TD_10138559_output, Table &tbl_JOIN_INNER_TD_9942357_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_warehouse_sk#744 = w_warehouse_sk#495))
    // Left Table: ListBuffer(ws_sold_date_sk#729, ws_sold_time_sk#730, ws_ship_mode_sk#743, ws_warehouse_sk#744, ws_quantity#747, ws_ext_sales_price#752, ws_net_paid#758)
    // Right Table: ListBuffer(w_warehouse_sk#495, w_warehouse_name#497, w_warehouse_sq_ft#498, w_city#503, w_county#504, w_state#505, w_country#507)
    // Output Table: ListBuffer(ws_sold_date_sk#729, ws_sold_time_sk#730, ws_ship_mode_sk#743, ws_quantity#747, ws_ext_sales_price#752, ws_net_paid#758, w_warehouse_name#497, w_warehouse_sq_ft#498, w_city#503, w_county#504, w_state#505, w_country#507)
    int left_nrow = tbl_Filter_TD_10567282_output.getNumRow();
    int right_nrow = tbl_Filter_TD_10138559_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9942357_key_leftMajor, SW_JOIN_INNER_TD_9942357_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_10567282_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_warehouse_sk744_k = tbl_Filter_TD_10567282_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_9942357_key_leftMajor keyA{_ws_warehouse_sk744_k};
            int32_t _ws_sold_date_sk729 = tbl_Filter_TD_10567282_output.getInt32(i, 0);
            int32_t _ws_sold_time_sk730 = tbl_Filter_TD_10567282_output.getInt32(i, 1);
            int32_t _ws_ship_mode_sk743 = tbl_Filter_TD_10567282_output.getInt32(i, 2);
            int32_t _ws_warehouse_sk744 = tbl_Filter_TD_10567282_output.getInt32(i, 3);
            int32_t _ws_quantity747 = tbl_Filter_TD_10567282_output.getInt32(i, 4);
            int64_t _ws_ext_sales_price752 = tbl_Filter_TD_10567282_output.getInt64(i, 5);
            int64_t _ws_net_paid758 = tbl_Filter_TD_10567282_output.getInt64(i, 6);
            SW_JOIN_INNER_TD_9942357_payload_leftMajor payloadA{_ws_sold_date_sk729, _ws_sold_time_sk730, _ws_ship_mode_sk743, _ws_warehouse_sk744, _ws_quantity747, _ws_ext_sales_price752, _ws_net_paid758};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_10138559_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _w_warehouse_sk495_k = tbl_Filter_TD_10138559_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9942357_key_leftMajor{_w_warehouse_sk495_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_date_sk729 = (it->second)._ws_sold_date_sk729;
                int32_t _ws_sold_time_sk730 = (it->second)._ws_sold_time_sk730;
                int32_t _ws_ship_mode_sk743 = (it->second)._ws_ship_mode_sk743;
                int32_t _ws_warehouse_sk744 = (it->second)._ws_warehouse_sk744;
                int32_t _ws_quantity747 = (it->second)._ws_quantity747;
                int64_t _ws_ext_sales_price752 = (it->second)._ws_ext_sales_price752;
                int64_t _ws_net_paid758 = (it->second)._ws_net_paid758;
                int32_t _w_warehouse_sk495 = tbl_Filter_TD_10138559_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_Filter_TD_10138559_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
                int32_t _w_warehouse_sq_ft498 = tbl_Filter_TD_10138559_output.getInt32(i, 2);
                std::array<char, TPCDS_READ_MAX + 1> _w_city503_n = tbl_Filter_TD_10138559_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _w_city503 = std::string(_w_city503_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _w_county504_n = tbl_Filter_TD_10138559_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _w_county504 = std::string(_w_county504_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _w_state505_n = tbl_Filter_TD_10138559_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _w_state505 = std::string(_w_state505_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _w_country507_n = tbl_Filter_TD_10138559_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _w_country507 = std::string(_w_country507_n.data());
                tbl_JOIN_INNER_TD_9942357_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_9942357_output.setInt32(r, 1, _ws_sold_time_sk730);
                tbl_JOIN_INNER_TD_9942357_output.setInt32(r, 2, _ws_ship_mode_sk743);
                tbl_JOIN_INNER_TD_9942357_output.setInt32(r, 3, _ws_quantity747);
                tbl_JOIN_INNER_TD_9942357_output.setInt64(r, 4, _ws_ext_sales_price752);
                tbl_JOIN_INNER_TD_9942357_output.setInt64(r, 5, _ws_net_paid758);
                tbl_JOIN_INNER_TD_9942357_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _w_warehouse_name497_n);
                tbl_JOIN_INNER_TD_9942357_output.setInt32(r, 7, _w_warehouse_sq_ft498);
                tbl_JOIN_INNER_TD_9942357_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _w_city503_n);
                tbl_JOIN_INNER_TD_9942357_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _w_county504_n);
                tbl_JOIN_INNER_TD_9942357_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _w_state505_n);
                tbl_JOIN_INNER_TD_9942357_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _w_country507_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9942357_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9942357_key_rightMajor, SW_JOIN_INNER_TD_9942357_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_10138559_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _w_warehouse_sk495_k = tbl_Filter_TD_10138559_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_9942357_key_rightMajor keyA{_w_warehouse_sk495_k};
            int32_t _w_warehouse_sk495 = tbl_Filter_TD_10138559_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_Filter_TD_10138559_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
            int32_t _w_warehouse_sq_ft498 = tbl_Filter_TD_10138559_output.getInt32(i, 2);
            std::array<char, TPCDS_READ_MAX + 1> _w_city503_n = tbl_Filter_TD_10138559_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _w_city503 = std::string(_w_city503_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _w_county504_n = tbl_Filter_TD_10138559_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _w_county504 = std::string(_w_county504_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _w_state505_n = tbl_Filter_TD_10138559_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _w_state505 = std::string(_w_state505_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _w_country507_n = tbl_Filter_TD_10138559_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _w_country507 = std::string(_w_country507_n.data());
            SW_JOIN_INNER_TD_9942357_payload_rightMajor payloadA{_w_warehouse_sk495, _w_warehouse_name497, _w_warehouse_sq_ft498, _w_city503, _w_county504, _w_state505, _w_country507};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_10567282_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_warehouse_sk744_k = tbl_Filter_TD_10567282_output.getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9942357_key_rightMajor{_ws_warehouse_sk744_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _w_warehouse_sk495 = (it->second)._w_warehouse_sk495;
                std::string _w_warehouse_name497 = (it->second)._w_warehouse_name497;
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n{};
                memcpy(_w_warehouse_name497_n.data(), (_w_warehouse_name497).data(), (_w_warehouse_name497).length());
                int32_t _w_warehouse_sq_ft498 = (it->second)._w_warehouse_sq_ft498;
                std::string _w_city503 = (it->second)._w_city503;
                std::array<char, TPCDS_READ_MAX + 1> _w_city503_n{};
                memcpy(_w_city503_n.data(), (_w_city503).data(), (_w_city503).length());
                std::string _w_county504 = (it->second)._w_county504;
                std::array<char, TPCDS_READ_MAX + 1> _w_county504_n{};
                memcpy(_w_county504_n.data(), (_w_county504).data(), (_w_county504).length());
                std::string _w_state505 = (it->second)._w_state505;
                std::array<char, TPCDS_READ_MAX + 1> _w_state505_n{};
                memcpy(_w_state505_n.data(), (_w_state505).data(), (_w_state505).length());
                std::string _w_country507 = (it->second)._w_country507;
                std::array<char, TPCDS_READ_MAX + 1> _w_country507_n{};
                memcpy(_w_country507_n.data(), (_w_country507).data(), (_w_country507).length());
                int32_t _ws_sold_date_sk729 = tbl_Filter_TD_10567282_output.getInt32(i, 0);
                int32_t _ws_sold_time_sk730 = tbl_Filter_TD_10567282_output.getInt32(i, 1);
                int32_t _ws_ship_mode_sk743 = tbl_Filter_TD_10567282_output.getInt32(i, 2);
                int32_t _ws_warehouse_sk744 = tbl_Filter_TD_10567282_output.getInt32(i, 3);
                int32_t _ws_quantity747 = tbl_Filter_TD_10567282_output.getInt32(i, 4);
                int64_t _ws_ext_sales_price752 = tbl_Filter_TD_10567282_output.getInt64(i, 5);
                int64_t _ws_net_paid758 = tbl_Filter_TD_10567282_output.getInt64(i, 6);
                tbl_JOIN_INNER_TD_9942357_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _w_warehouse_name497_n);
                tbl_JOIN_INNER_TD_9942357_output.setInt32(r, 7, _w_warehouse_sq_ft498);
                tbl_JOIN_INNER_TD_9942357_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _w_city503_n);
                tbl_JOIN_INNER_TD_9942357_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _w_county504_n);
                tbl_JOIN_INNER_TD_9942357_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _w_state505_n);
                tbl_JOIN_INNER_TD_9942357_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _w_country507_n);
                tbl_JOIN_INNER_TD_9942357_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_9942357_output.setInt32(r, 1, _ws_sold_time_sk730);
                tbl_JOIN_INNER_TD_9942357_output.setInt32(r, 2, _ws_ship_mode_sk743);
                tbl_JOIN_INNER_TD_9942357_output.setInt32(r, 3, _ws_quantity747);
                tbl_JOIN_INNER_TD_9942357_output.setInt64(r, 4, _ws_ext_sales_price752);
                tbl_JOIN_INNER_TD_9942357_output.setInt64(r, 5, _ws_net_paid758);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9942357_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_9942357_output #Row: " << tbl_JOIN_INNER_TD_9942357_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8812878(Table &tbl_SerializeFromObject_TD_9783073_input, Table &tbl_Filter_TD_8812878_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(t_time#3676) AND ((t_time#3676 >= 30838) AND (t_time#3676 <= 59638))) AND isnotnull(t_time_sk#3674)))
    // Input: ListBuffer(t_time_sk#3674, t_time#3676)
    // Output: ListBuffer(t_time_sk#3674)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9783073_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _t_time3676 = tbl_SerializeFromObject_TD_9783073_input.getInt32(i, 1);
        int32_t _t_time_sk3674 = tbl_SerializeFromObject_TD_9783073_input.getInt32(i, 0);
        if (((_t_time3676!= 0) && ((_t_time3676 >= 30838) && (_t_time3676 <= 59638))) && (_t_time_sk3674!= 0)) {
            int32_t _t_time_sk3674_t = tbl_SerializeFromObject_TD_9783073_input.getInt32(i, 0);
            tbl_Filter_TD_8812878_output.setInt32(r, 0, _t_time_sk3674_t);
            r++;
        }
    }
    tbl_Filter_TD_8812878_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8812878_output #Row: " << tbl_Filter_TD_8812878_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8907863_key_leftMajor {
    int32_t _cs_sold_date_sk1104;
    bool operator==(const SW_JOIN_INNER_TD_8907863_key_leftMajor& other) const {
        return ((_cs_sold_date_sk1104 == other._cs_sold_date_sk1104));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8907863_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8907863_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_sold_date_sk1104));
    }
};
}
struct SW_JOIN_INNER_TD_8907863_payload_leftMajor {
    int32_t _cs_sold_date_sk1104;
    int32_t _cs_sold_time_sk1105;
    int32_t _cs_ship_mode_sk1117;
    int32_t _cs_quantity1122;
    int64_t _cs_sales_price1125;
    int64_t _cs_net_paid_inc_tax1134;
    std::string _w_warehouse_name3634;
    int32_t _w_warehouse_sq_ft3635;
    std::string _w_city3640;
    std::string _w_county3641;
    std::string _w_state3642;
    std::string _w_country3644;
};
struct SW_JOIN_INNER_TD_8907863_key_rightMajor {
    int32_t _d_date_sk3646;
    bool operator==(const SW_JOIN_INNER_TD_8907863_key_rightMajor& other) const {
        return ((_d_date_sk3646 == other._d_date_sk3646));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8907863_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8907863_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk3646));
    }
};
}
struct SW_JOIN_INNER_TD_8907863_payload_rightMajor {
    int32_t _d_date_sk3646;
    int32_t _d_year3652;
    int32_t _d_moy3654;
};
void SW_JOIN_INNER_TD_8907863(Table &tbl_JOIN_INNER_TD_9386501_output, Table &tbl_Filter_TD_9220854_output, Table &tbl_JOIN_INNER_TD_8907863_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_sold_date_sk#1104 = d_date_sk#3646))
    // Left Table: ListBuffer(cs_sold_date_sk#1104, cs_sold_time_sk#1105, cs_ship_mode_sk#1117, cs_quantity#1122, cs_sales_price#1125, cs_net_paid_inc_tax#1134, w_warehouse_name#3634, w_warehouse_sq_ft#3635, w_city#3640, w_county#3641, w_state#3642, w_country#3644)
    // Right Table: ListBuffer(d_date_sk#3646, d_year#3652, d_moy#3654)
    // Output Table: ListBuffer(cs_sold_time_sk#1105, cs_ship_mode_sk#1117, cs_quantity#1122, cs_sales_price#1125, cs_net_paid_inc_tax#1134, w_warehouse_name#3634, w_warehouse_sq_ft#3635, w_city#3640, w_county#3641, w_state#3642, w_country#3644, d_year#3652, d_moy#3654)
    int left_nrow = tbl_JOIN_INNER_TD_9386501_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9220854_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8907863_key_leftMajor, SW_JOIN_INNER_TD_8907863_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_9386501_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_sold_date_sk1104_k = tbl_JOIN_INNER_TD_9386501_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8907863_key_leftMajor keyA{_cs_sold_date_sk1104_k};
            int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_9386501_output.getInt32(i, 0);
            int32_t _cs_sold_time_sk1105 = tbl_JOIN_INNER_TD_9386501_output.getInt32(i, 1);
            int32_t _cs_ship_mode_sk1117 = tbl_JOIN_INNER_TD_9386501_output.getInt32(i, 2);
            int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_9386501_output.getInt32(i, 3);
            int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_9386501_output.getInt64(i, 4);
            int64_t _cs_net_paid_inc_tax1134 = tbl_JOIN_INNER_TD_9386501_output.getInt64(i, 5);
            std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name3634_n = tbl_JOIN_INNER_TD_9386501_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _w_warehouse_name3634 = std::string(_w_warehouse_name3634_n.data());
            int32_t _w_warehouse_sq_ft3635 = tbl_JOIN_INNER_TD_9386501_output.getInt32(i, 7);
            std::array<char, TPCDS_READ_MAX + 1> _w_city3640_n = tbl_JOIN_INNER_TD_9386501_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
            std::string _w_city3640 = std::string(_w_city3640_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _w_county3641_n = tbl_JOIN_INNER_TD_9386501_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            std::string _w_county3641 = std::string(_w_county3641_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _w_state3642_n = tbl_JOIN_INNER_TD_9386501_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            std::string _w_state3642 = std::string(_w_state3642_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _w_country3644_n = tbl_JOIN_INNER_TD_9386501_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
            std::string _w_country3644 = std::string(_w_country3644_n.data());
            SW_JOIN_INNER_TD_8907863_payload_leftMajor payloadA{_cs_sold_date_sk1104, _cs_sold_time_sk1105, _cs_ship_mode_sk1117, _cs_quantity1122, _cs_sales_price1125, _cs_net_paid_inc_tax1134, _w_warehouse_name3634, _w_warehouse_sq_ft3635, _w_city3640, _w_county3641, _w_state3642, _w_country3644};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9220854_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk3646_k = tbl_Filter_TD_9220854_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8907863_key_leftMajor{_d_date_sk3646_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk1104 = (it->second)._cs_sold_date_sk1104;
                int32_t _cs_sold_time_sk1105 = (it->second)._cs_sold_time_sk1105;
                int32_t _cs_ship_mode_sk1117 = (it->second)._cs_ship_mode_sk1117;
                int32_t _cs_quantity1122 = (it->second)._cs_quantity1122;
                int64_t _cs_sales_price1125 = (it->second)._cs_sales_price1125;
                int64_t _cs_net_paid_inc_tax1134 = (it->second)._cs_net_paid_inc_tax1134;
                std::string _w_warehouse_name3634 = (it->second)._w_warehouse_name3634;
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name3634_n{};
                memcpy(_w_warehouse_name3634_n.data(), (_w_warehouse_name3634).data(), (_w_warehouse_name3634).length());
                int32_t _w_warehouse_sq_ft3635 = (it->second)._w_warehouse_sq_ft3635;
                std::string _w_city3640 = (it->second)._w_city3640;
                std::array<char, TPCDS_READ_MAX + 1> _w_city3640_n{};
                memcpy(_w_city3640_n.data(), (_w_city3640).data(), (_w_city3640).length());
                std::string _w_county3641 = (it->second)._w_county3641;
                std::array<char, TPCDS_READ_MAX + 1> _w_county3641_n{};
                memcpy(_w_county3641_n.data(), (_w_county3641).data(), (_w_county3641).length());
                std::string _w_state3642 = (it->second)._w_state3642;
                std::array<char, TPCDS_READ_MAX + 1> _w_state3642_n{};
                memcpy(_w_state3642_n.data(), (_w_state3642).data(), (_w_state3642).length());
                std::string _w_country3644 = (it->second)._w_country3644;
                std::array<char, TPCDS_READ_MAX + 1> _w_country3644_n{};
                memcpy(_w_country3644_n.data(), (_w_country3644).data(), (_w_country3644).length());
                int32_t _d_date_sk3646 = tbl_Filter_TD_9220854_output.getInt32(i, 0);
                int32_t _d_year3652 = tbl_Filter_TD_9220854_output.getInt32(i, 1);
                int32_t _d_moy3654 = tbl_Filter_TD_9220854_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_8907863_output.setInt32(r, 0, _cs_sold_time_sk1105);
                tbl_JOIN_INNER_TD_8907863_output.setInt32(r, 1, _cs_ship_mode_sk1117);
                tbl_JOIN_INNER_TD_8907863_output.setInt32(r, 2, _cs_quantity1122);
                tbl_JOIN_INNER_TD_8907863_output.setInt64(r, 3, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_8907863_output.setInt64(r, 4, _cs_net_paid_inc_tax1134);
                tbl_JOIN_INNER_TD_8907863_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _w_warehouse_name3634_n);
                tbl_JOIN_INNER_TD_8907863_output.setInt32(r, 6, _w_warehouse_sq_ft3635);
                tbl_JOIN_INNER_TD_8907863_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _w_city3640_n);
                tbl_JOIN_INNER_TD_8907863_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _w_county3641_n);
                tbl_JOIN_INNER_TD_8907863_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _w_state3642_n);
                tbl_JOIN_INNER_TD_8907863_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _w_country3644_n);
                tbl_JOIN_INNER_TD_8907863_output.setInt32(r, 11, _d_year3652);
                tbl_JOIN_INNER_TD_8907863_output.setInt32(r, 12, _d_moy3654);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8907863_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8907863_key_rightMajor, SW_JOIN_INNER_TD_8907863_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9220854_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk3646_k = tbl_Filter_TD_9220854_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8907863_key_rightMajor keyA{_d_date_sk3646_k};
            int32_t _d_date_sk3646 = tbl_Filter_TD_9220854_output.getInt32(i, 0);
            int32_t _d_year3652 = tbl_Filter_TD_9220854_output.getInt32(i, 1);
            int32_t _d_moy3654 = tbl_Filter_TD_9220854_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_8907863_payload_rightMajor payloadA{_d_date_sk3646, _d_year3652, _d_moy3654};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_9386501_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_sold_date_sk1104_k = tbl_JOIN_INNER_TD_9386501_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8907863_key_rightMajor{_cs_sold_date_sk1104_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk3646 = (it->second)._d_date_sk3646;
                int32_t _d_year3652 = (it->second)._d_year3652;
                int32_t _d_moy3654 = (it->second)._d_moy3654;
                int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_9386501_output.getInt32(i, 0);
                int32_t _cs_sold_time_sk1105 = tbl_JOIN_INNER_TD_9386501_output.getInt32(i, 1);
                int32_t _cs_ship_mode_sk1117 = tbl_JOIN_INNER_TD_9386501_output.getInt32(i, 2);
                int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_9386501_output.getInt32(i, 3);
                int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_9386501_output.getInt64(i, 4);
                int64_t _cs_net_paid_inc_tax1134 = tbl_JOIN_INNER_TD_9386501_output.getInt64(i, 5);
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name3634_n = tbl_JOIN_INNER_TD_9386501_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _w_warehouse_name3634 = std::string(_w_warehouse_name3634_n.data());
                int32_t _w_warehouse_sq_ft3635 = tbl_JOIN_INNER_TD_9386501_output.getInt32(i, 7);
                std::array<char, TPCDS_READ_MAX + 1> _w_city3640_n = tbl_JOIN_INNER_TD_9386501_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
                std::string _w_city3640 = std::string(_w_city3640_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _w_county3641_n = tbl_JOIN_INNER_TD_9386501_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
                std::string _w_county3641 = std::string(_w_county3641_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _w_state3642_n = tbl_JOIN_INNER_TD_9386501_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
                std::string _w_state3642 = std::string(_w_state3642_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _w_country3644_n = tbl_JOIN_INNER_TD_9386501_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
                std::string _w_country3644 = std::string(_w_country3644_n.data());
                tbl_JOIN_INNER_TD_8907863_output.setInt32(r, 11, _d_year3652);
                tbl_JOIN_INNER_TD_8907863_output.setInt32(r, 12, _d_moy3654);
                tbl_JOIN_INNER_TD_8907863_output.setInt32(r, 0, _cs_sold_time_sk1105);
                tbl_JOIN_INNER_TD_8907863_output.setInt32(r, 1, _cs_ship_mode_sk1117);
                tbl_JOIN_INNER_TD_8907863_output.setInt32(r, 2, _cs_quantity1122);
                tbl_JOIN_INNER_TD_8907863_output.setInt64(r, 3, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_8907863_output.setInt64(r, 4, _cs_net_paid_inc_tax1134);
                tbl_JOIN_INNER_TD_8907863_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _w_warehouse_name3634_n);
                tbl_JOIN_INNER_TD_8907863_output.setInt32(r, 6, _w_warehouse_sq_ft3635);
                tbl_JOIN_INNER_TD_8907863_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _w_city3640_n);
                tbl_JOIN_INNER_TD_8907863_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _w_county3641_n);
                tbl_JOIN_INNER_TD_8907863_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _w_state3642_n);
                tbl_JOIN_INNER_TD_8907863_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _w_country3644_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8907863_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8907863_output #Row: " << tbl_JOIN_INNER_TD_8907863_output.getNumRow() << std::endl;
}

void SW_Filter_TD_888970(Table &tbl_SerializeFromObject_TD_9953389_input, Table &tbl_Filter_TD_888970_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(t_time#467) AND ((t_time#467 >= 30838) AND (t_time#467 <= 59638))) AND isnotnull(t_time_sk#465)))
    // Input: ListBuffer(t_time_sk#465, t_time#467)
    // Output: ListBuffer(t_time_sk#465)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9953389_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _t_time467 = tbl_SerializeFromObject_TD_9953389_input.getInt32(i, 1);
        int32_t _t_time_sk465 = tbl_SerializeFromObject_TD_9953389_input.getInt32(i, 0);
        if (((_t_time467!= 0) && ((_t_time467 >= 30838) && (_t_time467 <= 59638))) && (_t_time_sk465!= 0)) {
            int32_t _t_time_sk465_t = tbl_SerializeFromObject_TD_9953389_input.getInt32(i, 0);
            tbl_Filter_TD_888970_output.setInt32(r, 0, _t_time_sk465_t);
            r++;
        }
    }
    tbl_Filter_TD_888970_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_888970_output #Row: " << tbl_Filter_TD_888970_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8505770_key_leftMajor {
    int32_t _ws_sold_date_sk729;
    bool operator==(const SW_JOIN_INNER_TD_8505770_key_leftMajor& other) const {
        return ((_ws_sold_date_sk729 == other._ws_sold_date_sk729));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8505770_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8505770_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_sold_date_sk729));
    }
};
}
struct SW_JOIN_INNER_TD_8505770_payload_leftMajor {
    int32_t _ws_sold_date_sk729;
    int32_t _ws_sold_time_sk730;
    int32_t _ws_ship_mode_sk743;
    int32_t _ws_quantity747;
    int64_t _ws_ext_sales_price752;
    int64_t _ws_net_paid758;
    std::string _w_warehouse_name497;
    int32_t _w_warehouse_sq_ft498;
    std::string _w_city503;
    std::string _w_county504;
    std::string _w_state505;
    std::string _w_country507;
};
struct SW_JOIN_INNER_TD_8505770_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_8505770_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8505770_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8505770_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_8505770_payload_rightMajor {
    int32_t _d_date_sk120;
    int32_t _d_year126;
    int32_t _d_moy128;
};
void SW_JOIN_INNER_TD_8505770(Table &tbl_JOIN_INNER_TD_9942357_output, Table &tbl_Filter_TD_9609467_output, Table &tbl_JOIN_INNER_TD_8505770_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_sold_date_sk#729 = d_date_sk#120))
    // Left Table: ListBuffer(ws_sold_date_sk#729, ws_sold_time_sk#730, ws_ship_mode_sk#743, ws_quantity#747, ws_ext_sales_price#752, ws_net_paid#758, w_warehouse_name#497, w_warehouse_sq_ft#498, w_city#503, w_county#504, w_state#505, w_country#507)
    // Right Table: ListBuffer(d_date_sk#120, d_year#126, d_moy#128)
    // Output Table: ListBuffer(ws_sold_time_sk#730, ws_ship_mode_sk#743, ws_quantity#747, ws_ext_sales_price#752, ws_net_paid#758, w_warehouse_name#497, w_warehouse_sq_ft#498, w_city#503, w_county#504, w_state#505, w_country#507, d_year#126, d_moy#128)
    int left_nrow = tbl_JOIN_INNER_TD_9942357_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9609467_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8505770_key_leftMajor, SW_JOIN_INNER_TD_8505770_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_9942357_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_sold_date_sk729_k = tbl_JOIN_INNER_TD_9942357_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8505770_key_leftMajor keyA{_ws_sold_date_sk729_k};
            int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_9942357_output.getInt32(i, 0);
            int32_t _ws_sold_time_sk730 = tbl_JOIN_INNER_TD_9942357_output.getInt32(i, 1);
            int32_t _ws_ship_mode_sk743 = tbl_JOIN_INNER_TD_9942357_output.getInt32(i, 2);
            int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_9942357_output.getInt32(i, 3);
            int64_t _ws_ext_sales_price752 = tbl_JOIN_INNER_TD_9942357_output.getInt64(i, 4);
            int64_t _ws_net_paid758 = tbl_JOIN_INNER_TD_9942357_output.getInt64(i, 5);
            std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_JOIN_INNER_TD_9942357_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
            int32_t _w_warehouse_sq_ft498 = tbl_JOIN_INNER_TD_9942357_output.getInt32(i, 7);
            std::array<char, TPCDS_READ_MAX + 1> _w_city503_n = tbl_JOIN_INNER_TD_9942357_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
            std::string _w_city503 = std::string(_w_city503_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _w_county504_n = tbl_JOIN_INNER_TD_9942357_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            std::string _w_county504 = std::string(_w_county504_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _w_state505_n = tbl_JOIN_INNER_TD_9942357_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            std::string _w_state505 = std::string(_w_state505_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _w_country507_n = tbl_JOIN_INNER_TD_9942357_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
            std::string _w_country507 = std::string(_w_country507_n.data());
            SW_JOIN_INNER_TD_8505770_payload_leftMajor payloadA{_ws_sold_date_sk729, _ws_sold_time_sk730, _ws_ship_mode_sk743, _ws_quantity747, _ws_ext_sales_price752, _ws_net_paid758, _w_warehouse_name497, _w_warehouse_sq_ft498, _w_city503, _w_county504, _w_state505, _w_country507};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9609467_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_9609467_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8505770_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_date_sk729 = (it->second)._ws_sold_date_sk729;
                int32_t _ws_sold_time_sk730 = (it->second)._ws_sold_time_sk730;
                int32_t _ws_ship_mode_sk743 = (it->second)._ws_ship_mode_sk743;
                int32_t _ws_quantity747 = (it->second)._ws_quantity747;
                int64_t _ws_ext_sales_price752 = (it->second)._ws_ext_sales_price752;
                int64_t _ws_net_paid758 = (it->second)._ws_net_paid758;
                std::string _w_warehouse_name497 = (it->second)._w_warehouse_name497;
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n{};
                memcpy(_w_warehouse_name497_n.data(), (_w_warehouse_name497).data(), (_w_warehouse_name497).length());
                int32_t _w_warehouse_sq_ft498 = (it->second)._w_warehouse_sq_ft498;
                std::string _w_city503 = (it->second)._w_city503;
                std::array<char, TPCDS_READ_MAX + 1> _w_city503_n{};
                memcpy(_w_city503_n.data(), (_w_city503).data(), (_w_city503).length());
                std::string _w_county504 = (it->second)._w_county504;
                std::array<char, TPCDS_READ_MAX + 1> _w_county504_n{};
                memcpy(_w_county504_n.data(), (_w_county504).data(), (_w_county504).length());
                std::string _w_state505 = (it->second)._w_state505;
                std::array<char, TPCDS_READ_MAX + 1> _w_state505_n{};
                memcpy(_w_state505_n.data(), (_w_state505).data(), (_w_state505).length());
                std::string _w_country507 = (it->second)._w_country507;
                std::array<char, TPCDS_READ_MAX + 1> _w_country507_n{};
                memcpy(_w_country507_n.data(), (_w_country507).data(), (_w_country507).length());
                int32_t _d_date_sk120 = tbl_Filter_TD_9609467_output.getInt32(i, 0);
                int32_t _d_year126 = tbl_Filter_TD_9609467_output.getInt32(i, 1);
                int32_t _d_moy128 = tbl_Filter_TD_9609467_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_8505770_output.setInt32(r, 0, _ws_sold_time_sk730);
                tbl_JOIN_INNER_TD_8505770_output.setInt32(r, 1, _ws_ship_mode_sk743);
                tbl_JOIN_INNER_TD_8505770_output.setInt32(r, 2, _ws_quantity747);
                tbl_JOIN_INNER_TD_8505770_output.setInt64(r, 3, _ws_ext_sales_price752);
                tbl_JOIN_INNER_TD_8505770_output.setInt64(r, 4, _ws_net_paid758);
                tbl_JOIN_INNER_TD_8505770_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _w_warehouse_name497_n);
                tbl_JOIN_INNER_TD_8505770_output.setInt32(r, 6, _w_warehouse_sq_ft498);
                tbl_JOIN_INNER_TD_8505770_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _w_city503_n);
                tbl_JOIN_INNER_TD_8505770_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _w_county504_n);
                tbl_JOIN_INNER_TD_8505770_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _w_state505_n);
                tbl_JOIN_INNER_TD_8505770_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _w_country507_n);
                tbl_JOIN_INNER_TD_8505770_output.setInt32(r, 11, _d_year126);
                tbl_JOIN_INNER_TD_8505770_output.setInt32(r, 12, _d_moy128);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8505770_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8505770_key_rightMajor, SW_JOIN_INNER_TD_8505770_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9609467_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_9609467_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8505770_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_9609467_output.getInt32(i, 0);
            int32_t _d_year126 = tbl_Filter_TD_9609467_output.getInt32(i, 1);
            int32_t _d_moy128 = tbl_Filter_TD_9609467_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_8505770_payload_rightMajor payloadA{_d_date_sk120, _d_year126, _d_moy128};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_9942357_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_sold_date_sk729_k = tbl_JOIN_INNER_TD_9942357_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8505770_key_rightMajor{_ws_sold_date_sk729_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _d_year126 = (it->second)._d_year126;
                int32_t _d_moy128 = (it->second)._d_moy128;
                int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_9942357_output.getInt32(i, 0);
                int32_t _ws_sold_time_sk730 = tbl_JOIN_INNER_TD_9942357_output.getInt32(i, 1);
                int32_t _ws_ship_mode_sk743 = tbl_JOIN_INNER_TD_9942357_output.getInt32(i, 2);
                int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_9942357_output.getInt32(i, 3);
                int64_t _ws_ext_sales_price752 = tbl_JOIN_INNER_TD_9942357_output.getInt64(i, 4);
                int64_t _ws_net_paid758 = tbl_JOIN_INNER_TD_9942357_output.getInt64(i, 5);
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_JOIN_INNER_TD_9942357_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
                int32_t _w_warehouse_sq_ft498 = tbl_JOIN_INNER_TD_9942357_output.getInt32(i, 7);
                std::array<char, TPCDS_READ_MAX + 1> _w_city503_n = tbl_JOIN_INNER_TD_9942357_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
                std::string _w_city503 = std::string(_w_city503_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _w_county504_n = tbl_JOIN_INNER_TD_9942357_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
                std::string _w_county504 = std::string(_w_county504_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _w_state505_n = tbl_JOIN_INNER_TD_9942357_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
                std::string _w_state505 = std::string(_w_state505_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _w_country507_n = tbl_JOIN_INNER_TD_9942357_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
                std::string _w_country507 = std::string(_w_country507_n.data());
                tbl_JOIN_INNER_TD_8505770_output.setInt32(r, 11, _d_year126);
                tbl_JOIN_INNER_TD_8505770_output.setInt32(r, 12, _d_moy128);
                tbl_JOIN_INNER_TD_8505770_output.setInt32(r, 0, _ws_sold_time_sk730);
                tbl_JOIN_INNER_TD_8505770_output.setInt32(r, 1, _ws_ship_mode_sk743);
                tbl_JOIN_INNER_TD_8505770_output.setInt32(r, 2, _ws_quantity747);
                tbl_JOIN_INNER_TD_8505770_output.setInt64(r, 3, _ws_ext_sales_price752);
                tbl_JOIN_INNER_TD_8505770_output.setInt64(r, 4, _ws_net_paid758);
                tbl_JOIN_INNER_TD_8505770_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _w_warehouse_name497_n);
                tbl_JOIN_INNER_TD_8505770_output.setInt32(r, 6, _w_warehouse_sq_ft498);
                tbl_JOIN_INNER_TD_8505770_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _w_city503_n);
                tbl_JOIN_INNER_TD_8505770_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _w_county504_n);
                tbl_JOIN_INNER_TD_8505770_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _w_state505_n);
                tbl_JOIN_INNER_TD_8505770_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _w_country507_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8505770_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8505770_output #Row: " << tbl_JOIN_INNER_TD_8505770_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7222045(Table &tbl_SerializeFromObject_TD_8701910_input, Table &tbl_Filter_TD_7222045_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((sm_carrier#3688 IN (DHL,BARIAN) AND isnotnull(sm_ship_mode_sk#3684)))
    // Input: ListBuffer(sm_ship_mode_sk#3684, sm_carrier#3688)
    // Output: ListBuffer(sm_ship_mode_sk#3684)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8701910_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _sm_carrier3688 = tbl_SerializeFromObject_TD_8701910_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _sm_ship_mode_sk3684 = tbl_SerializeFromObject_TD_8701910_input.getInt32(i, 0);
        auto reuse_col_str_195 = std::string(_sm_carrier3688.data());
        if (((reuse_col_str_195 == "DHL") || (reuse_col_str_195 == "BARIAN") || (0)) && (_sm_ship_mode_sk3684!= 0)) {
            int32_t _sm_ship_mode_sk3684_t = tbl_SerializeFromObject_TD_8701910_input.getInt32(i, 0);
            tbl_Filter_TD_7222045_output.setInt32(r, 0, _sm_ship_mode_sk3684_t);
            r++;
        }
    }
    tbl_Filter_TD_7222045_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7222045_output #Row: " << tbl_Filter_TD_7222045_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_7312336_key_leftMajor {
    int32_t _cs_sold_time_sk1105;
    bool operator==(const SW_JOIN_INNER_TD_7312336_key_leftMajor& other) const {
        return ((_cs_sold_time_sk1105 == other._cs_sold_time_sk1105));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7312336_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7312336_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_sold_time_sk1105));
    }
};
}
struct SW_JOIN_INNER_TD_7312336_payload_leftMajor {
    int32_t _cs_sold_time_sk1105;
    int32_t _cs_ship_mode_sk1117;
    int32_t _cs_quantity1122;
    int64_t _cs_sales_price1125;
    int64_t _cs_net_paid_inc_tax1134;
    std::string _w_warehouse_name3634;
    int32_t _w_warehouse_sq_ft3635;
    std::string _w_city3640;
    std::string _w_county3641;
    std::string _w_state3642;
    std::string _w_country3644;
    int32_t _d_year3652;
    int32_t _d_moy3654;
};
struct SW_JOIN_INNER_TD_7312336_key_rightMajor {
    int32_t _t_time_sk3674;
    bool operator==(const SW_JOIN_INNER_TD_7312336_key_rightMajor& other) const {
        return ((_t_time_sk3674 == other._t_time_sk3674));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7312336_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7312336_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._t_time_sk3674));
    }
};
}
struct SW_JOIN_INNER_TD_7312336_payload_rightMajor {
    int32_t _t_time_sk3674;
};
void SW_JOIN_INNER_TD_7312336(Table &tbl_JOIN_INNER_TD_8907863_output, Table &tbl_Filter_TD_8812878_output, Table &tbl_JOIN_INNER_TD_7312336_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_sold_time_sk#1105 = t_time_sk#3674))
    // Left Table: ListBuffer(cs_sold_time_sk#1105, cs_ship_mode_sk#1117, cs_quantity#1122, cs_sales_price#1125, cs_net_paid_inc_tax#1134, w_warehouse_name#3634, w_warehouse_sq_ft#3635, w_city#3640, w_county#3641, w_state#3642, w_country#3644, d_year#3652, d_moy#3654)
    // Right Table: ListBuffer(t_time_sk#3674)
    // Output Table: ListBuffer(cs_ship_mode_sk#1117, cs_quantity#1122, cs_sales_price#1125, cs_net_paid_inc_tax#1134, w_warehouse_name#3634, w_warehouse_sq_ft#3635, w_city#3640, w_county#3641, w_state#3642, w_country#3644, d_year#3652, d_moy#3654)
    int left_nrow = tbl_JOIN_INNER_TD_8907863_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8812878_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7312336_key_leftMajor, SW_JOIN_INNER_TD_7312336_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_8907863_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_sold_time_sk1105_k = tbl_JOIN_INNER_TD_8907863_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7312336_key_leftMajor keyA{_cs_sold_time_sk1105_k};
            int32_t _cs_sold_time_sk1105 = tbl_JOIN_INNER_TD_8907863_output.getInt32(i, 0);
            int32_t _cs_ship_mode_sk1117 = tbl_JOIN_INNER_TD_8907863_output.getInt32(i, 1);
            int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_8907863_output.getInt32(i, 2);
            int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_8907863_output.getInt64(i, 3);
            int64_t _cs_net_paid_inc_tax1134 = tbl_JOIN_INNER_TD_8907863_output.getInt64(i, 4);
            std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name3634_n = tbl_JOIN_INNER_TD_8907863_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _w_warehouse_name3634 = std::string(_w_warehouse_name3634_n.data());
            int32_t _w_warehouse_sq_ft3635 = tbl_JOIN_INNER_TD_8907863_output.getInt32(i, 6);
            std::array<char, TPCDS_READ_MAX + 1> _w_city3640_n = tbl_JOIN_INNER_TD_8907863_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _w_city3640 = std::string(_w_city3640_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _w_county3641_n = tbl_JOIN_INNER_TD_8907863_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
            std::string _w_county3641 = std::string(_w_county3641_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _w_state3642_n = tbl_JOIN_INNER_TD_8907863_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            std::string _w_state3642 = std::string(_w_state3642_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _w_country3644_n = tbl_JOIN_INNER_TD_8907863_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            std::string _w_country3644 = std::string(_w_country3644_n.data());
            int32_t _d_year3652 = tbl_JOIN_INNER_TD_8907863_output.getInt32(i, 11);
            int32_t _d_moy3654 = tbl_JOIN_INNER_TD_8907863_output.getInt32(i, 12);
            SW_JOIN_INNER_TD_7312336_payload_leftMajor payloadA{_cs_sold_time_sk1105, _cs_ship_mode_sk1117, _cs_quantity1122, _cs_sales_price1125, _cs_net_paid_inc_tax1134, _w_warehouse_name3634, _w_warehouse_sq_ft3635, _w_city3640, _w_county3641, _w_state3642, _w_country3644, _d_year3652, _d_moy3654};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8812878_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _t_time_sk3674_k = tbl_Filter_TD_8812878_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7312336_key_leftMajor{_t_time_sk3674_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_time_sk1105 = (it->second)._cs_sold_time_sk1105;
                int32_t _cs_ship_mode_sk1117 = (it->second)._cs_ship_mode_sk1117;
                int32_t _cs_quantity1122 = (it->second)._cs_quantity1122;
                int64_t _cs_sales_price1125 = (it->second)._cs_sales_price1125;
                int64_t _cs_net_paid_inc_tax1134 = (it->second)._cs_net_paid_inc_tax1134;
                std::string _w_warehouse_name3634 = (it->second)._w_warehouse_name3634;
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name3634_n{};
                memcpy(_w_warehouse_name3634_n.data(), (_w_warehouse_name3634).data(), (_w_warehouse_name3634).length());
                int32_t _w_warehouse_sq_ft3635 = (it->second)._w_warehouse_sq_ft3635;
                std::string _w_city3640 = (it->second)._w_city3640;
                std::array<char, TPCDS_READ_MAX + 1> _w_city3640_n{};
                memcpy(_w_city3640_n.data(), (_w_city3640).data(), (_w_city3640).length());
                std::string _w_county3641 = (it->second)._w_county3641;
                std::array<char, TPCDS_READ_MAX + 1> _w_county3641_n{};
                memcpy(_w_county3641_n.data(), (_w_county3641).data(), (_w_county3641).length());
                std::string _w_state3642 = (it->second)._w_state3642;
                std::array<char, TPCDS_READ_MAX + 1> _w_state3642_n{};
                memcpy(_w_state3642_n.data(), (_w_state3642).data(), (_w_state3642).length());
                std::string _w_country3644 = (it->second)._w_country3644;
                std::array<char, TPCDS_READ_MAX + 1> _w_country3644_n{};
                memcpy(_w_country3644_n.data(), (_w_country3644).data(), (_w_country3644).length());
                int32_t _d_year3652 = (it->second)._d_year3652;
                int32_t _d_moy3654 = (it->second)._d_moy3654;
                int32_t _t_time_sk3674 = tbl_Filter_TD_8812878_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_7312336_output.setInt32(r, 0, _cs_ship_mode_sk1117);
                tbl_JOIN_INNER_TD_7312336_output.setInt32(r, 1, _cs_quantity1122);
                tbl_JOIN_INNER_TD_7312336_output.setInt64(r, 2, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_7312336_output.setInt64(r, 3, _cs_net_paid_inc_tax1134);
                tbl_JOIN_INNER_TD_7312336_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _w_warehouse_name3634_n);
                tbl_JOIN_INNER_TD_7312336_output.setInt32(r, 5, _w_warehouse_sq_ft3635);
                tbl_JOIN_INNER_TD_7312336_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _w_city3640_n);
                tbl_JOIN_INNER_TD_7312336_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _w_county3641_n);
                tbl_JOIN_INNER_TD_7312336_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _w_state3642_n);
                tbl_JOIN_INNER_TD_7312336_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _w_country3644_n);
                tbl_JOIN_INNER_TD_7312336_output.setInt32(r, 10, _d_year3652);
                tbl_JOIN_INNER_TD_7312336_output.setInt32(r, 11, _d_moy3654);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7312336_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7312336_key_rightMajor, SW_JOIN_INNER_TD_7312336_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8812878_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _t_time_sk3674_k = tbl_Filter_TD_8812878_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7312336_key_rightMajor keyA{_t_time_sk3674_k};
            int32_t _t_time_sk3674 = tbl_Filter_TD_8812878_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7312336_payload_rightMajor payloadA{_t_time_sk3674};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_8907863_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_sold_time_sk1105_k = tbl_JOIN_INNER_TD_8907863_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7312336_key_rightMajor{_cs_sold_time_sk1105_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _t_time_sk3674 = (it->second)._t_time_sk3674;
                int32_t _cs_sold_time_sk1105 = tbl_JOIN_INNER_TD_8907863_output.getInt32(i, 0);
                int32_t _cs_ship_mode_sk1117 = tbl_JOIN_INNER_TD_8907863_output.getInt32(i, 1);
                int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_8907863_output.getInt32(i, 2);
                int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_8907863_output.getInt64(i, 3);
                int64_t _cs_net_paid_inc_tax1134 = tbl_JOIN_INNER_TD_8907863_output.getInt64(i, 4);
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name3634_n = tbl_JOIN_INNER_TD_8907863_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _w_warehouse_name3634 = std::string(_w_warehouse_name3634_n.data());
                int32_t _w_warehouse_sq_ft3635 = tbl_JOIN_INNER_TD_8907863_output.getInt32(i, 6);
                std::array<char, TPCDS_READ_MAX + 1> _w_city3640_n = tbl_JOIN_INNER_TD_8907863_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _w_city3640 = std::string(_w_city3640_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _w_county3641_n = tbl_JOIN_INNER_TD_8907863_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
                std::string _w_county3641 = std::string(_w_county3641_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _w_state3642_n = tbl_JOIN_INNER_TD_8907863_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
                std::string _w_state3642 = std::string(_w_state3642_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _w_country3644_n = tbl_JOIN_INNER_TD_8907863_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
                std::string _w_country3644 = std::string(_w_country3644_n.data());
                int32_t _d_year3652 = tbl_JOIN_INNER_TD_8907863_output.getInt32(i, 11);
                int32_t _d_moy3654 = tbl_JOIN_INNER_TD_8907863_output.getInt32(i, 12);
                tbl_JOIN_INNER_TD_7312336_output.setInt32(r, 0, _cs_ship_mode_sk1117);
                tbl_JOIN_INNER_TD_7312336_output.setInt32(r, 1, _cs_quantity1122);
                tbl_JOIN_INNER_TD_7312336_output.setInt64(r, 2, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_7312336_output.setInt64(r, 3, _cs_net_paid_inc_tax1134);
                tbl_JOIN_INNER_TD_7312336_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _w_warehouse_name3634_n);
                tbl_JOIN_INNER_TD_7312336_output.setInt32(r, 5, _w_warehouse_sq_ft3635);
                tbl_JOIN_INNER_TD_7312336_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _w_city3640_n);
                tbl_JOIN_INNER_TD_7312336_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _w_county3641_n);
                tbl_JOIN_INNER_TD_7312336_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _w_state3642_n);
                tbl_JOIN_INNER_TD_7312336_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _w_country3644_n);
                tbl_JOIN_INNER_TD_7312336_output.setInt32(r, 10, _d_year3652);
                tbl_JOIN_INNER_TD_7312336_output.setInt32(r, 11, _d_moy3654);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7312336_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7312336_output #Row: " << tbl_JOIN_INNER_TD_7312336_output.getNumRow() << std::endl;
}

void SW_Filter_TD_748969(Table &tbl_SerializeFromObject_TD_8473429_input, Table &tbl_Filter_TD_748969_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((sm_carrier#364 IN (DHL,BARIAN) AND isnotnull(sm_ship_mode_sk#360)))
    // Input: ListBuffer(sm_ship_mode_sk#360, sm_carrier#364)
    // Output: ListBuffer(sm_ship_mode_sk#360)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8473429_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _sm_carrier364 = tbl_SerializeFromObject_TD_8473429_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _sm_ship_mode_sk360 = tbl_SerializeFromObject_TD_8473429_input.getInt32(i, 0);
        auto reuse_col_str_694 = std::string(_sm_carrier364.data());
        if (((reuse_col_str_694 == "DHL") || (reuse_col_str_694 == "BARIAN") || (0)) && (_sm_ship_mode_sk360!= 0)) {
            int32_t _sm_ship_mode_sk360_t = tbl_SerializeFromObject_TD_8473429_input.getInt32(i, 0);
            tbl_Filter_TD_748969_output.setInt32(r, 0, _sm_ship_mode_sk360_t);
            r++;
        }
    }
    tbl_Filter_TD_748969_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_748969_output #Row: " << tbl_Filter_TD_748969_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_7362851_key_leftMajor {
    int32_t _ws_sold_time_sk730;
    bool operator==(const SW_JOIN_INNER_TD_7362851_key_leftMajor& other) const {
        return ((_ws_sold_time_sk730 == other._ws_sold_time_sk730));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7362851_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7362851_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_sold_time_sk730));
    }
};
}
struct SW_JOIN_INNER_TD_7362851_payload_leftMajor {
    int32_t _ws_sold_time_sk730;
    int32_t _ws_ship_mode_sk743;
    int32_t _ws_quantity747;
    int64_t _ws_ext_sales_price752;
    int64_t _ws_net_paid758;
    std::string _w_warehouse_name497;
    int32_t _w_warehouse_sq_ft498;
    std::string _w_city503;
    std::string _w_county504;
    std::string _w_state505;
    std::string _w_country507;
    int32_t _d_year126;
    int32_t _d_moy128;
};
struct SW_JOIN_INNER_TD_7362851_key_rightMajor {
    int32_t _t_time_sk465;
    bool operator==(const SW_JOIN_INNER_TD_7362851_key_rightMajor& other) const {
        return ((_t_time_sk465 == other._t_time_sk465));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7362851_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7362851_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._t_time_sk465));
    }
};
}
struct SW_JOIN_INNER_TD_7362851_payload_rightMajor {
    int32_t _t_time_sk465;
};
void SW_JOIN_INNER_TD_7362851(Table &tbl_JOIN_INNER_TD_8505770_output, Table &tbl_Filter_TD_888970_output, Table &tbl_JOIN_INNER_TD_7362851_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_sold_time_sk#730 = t_time_sk#465))
    // Left Table: ListBuffer(ws_sold_time_sk#730, ws_ship_mode_sk#743, ws_quantity#747, ws_ext_sales_price#752, ws_net_paid#758, w_warehouse_name#497, w_warehouse_sq_ft#498, w_city#503, w_county#504, w_state#505, w_country#507, d_year#126, d_moy#128)
    // Right Table: ListBuffer(t_time_sk#465)
    // Output Table: ListBuffer(ws_ship_mode_sk#743, ws_quantity#747, ws_ext_sales_price#752, ws_net_paid#758, w_warehouse_name#497, w_warehouse_sq_ft#498, w_city#503, w_county#504, w_state#505, w_country#507, d_year#126, d_moy#128)
    int left_nrow = tbl_JOIN_INNER_TD_8505770_output.getNumRow();
    int right_nrow = tbl_Filter_TD_888970_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7362851_key_leftMajor, SW_JOIN_INNER_TD_7362851_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_8505770_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_sold_time_sk730_k = tbl_JOIN_INNER_TD_8505770_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7362851_key_leftMajor keyA{_ws_sold_time_sk730_k};
            int32_t _ws_sold_time_sk730 = tbl_JOIN_INNER_TD_8505770_output.getInt32(i, 0);
            int32_t _ws_ship_mode_sk743 = tbl_JOIN_INNER_TD_8505770_output.getInt32(i, 1);
            int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_8505770_output.getInt32(i, 2);
            int64_t _ws_ext_sales_price752 = tbl_JOIN_INNER_TD_8505770_output.getInt64(i, 3);
            int64_t _ws_net_paid758 = tbl_JOIN_INNER_TD_8505770_output.getInt64(i, 4);
            std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_JOIN_INNER_TD_8505770_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
            int32_t _w_warehouse_sq_ft498 = tbl_JOIN_INNER_TD_8505770_output.getInt32(i, 6);
            std::array<char, TPCDS_READ_MAX + 1> _w_city503_n = tbl_JOIN_INNER_TD_8505770_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _w_city503 = std::string(_w_city503_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _w_county504_n = tbl_JOIN_INNER_TD_8505770_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
            std::string _w_county504 = std::string(_w_county504_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _w_state505_n = tbl_JOIN_INNER_TD_8505770_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            std::string _w_state505 = std::string(_w_state505_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _w_country507_n = tbl_JOIN_INNER_TD_8505770_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            std::string _w_country507 = std::string(_w_country507_n.data());
            int32_t _d_year126 = tbl_JOIN_INNER_TD_8505770_output.getInt32(i, 11);
            int32_t _d_moy128 = tbl_JOIN_INNER_TD_8505770_output.getInt32(i, 12);
            SW_JOIN_INNER_TD_7362851_payload_leftMajor payloadA{_ws_sold_time_sk730, _ws_ship_mode_sk743, _ws_quantity747, _ws_ext_sales_price752, _ws_net_paid758, _w_warehouse_name497, _w_warehouse_sq_ft498, _w_city503, _w_county504, _w_state505, _w_country507, _d_year126, _d_moy128};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_888970_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _t_time_sk465_k = tbl_Filter_TD_888970_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7362851_key_leftMajor{_t_time_sk465_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_time_sk730 = (it->second)._ws_sold_time_sk730;
                int32_t _ws_ship_mode_sk743 = (it->second)._ws_ship_mode_sk743;
                int32_t _ws_quantity747 = (it->second)._ws_quantity747;
                int64_t _ws_ext_sales_price752 = (it->second)._ws_ext_sales_price752;
                int64_t _ws_net_paid758 = (it->second)._ws_net_paid758;
                std::string _w_warehouse_name497 = (it->second)._w_warehouse_name497;
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n{};
                memcpy(_w_warehouse_name497_n.data(), (_w_warehouse_name497).data(), (_w_warehouse_name497).length());
                int32_t _w_warehouse_sq_ft498 = (it->second)._w_warehouse_sq_ft498;
                std::string _w_city503 = (it->second)._w_city503;
                std::array<char, TPCDS_READ_MAX + 1> _w_city503_n{};
                memcpy(_w_city503_n.data(), (_w_city503).data(), (_w_city503).length());
                std::string _w_county504 = (it->second)._w_county504;
                std::array<char, TPCDS_READ_MAX + 1> _w_county504_n{};
                memcpy(_w_county504_n.data(), (_w_county504).data(), (_w_county504).length());
                std::string _w_state505 = (it->second)._w_state505;
                std::array<char, TPCDS_READ_MAX + 1> _w_state505_n{};
                memcpy(_w_state505_n.data(), (_w_state505).data(), (_w_state505).length());
                std::string _w_country507 = (it->second)._w_country507;
                std::array<char, TPCDS_READ_MAX + 1> _w_country507_n{};
                memcpy(_w_country507_n.data(), (_w_country507).data(), (_w_country507).length());
                int32_t _d_year126 = (it->second)._d_year126;
                int32_t _d_moy128 = (it->second)._d_moy128;
                int32_t _t_time_sk465 = tbl_Filter_TD_888970_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_7362851_output.setInt32(r, 0, _ws_ship_mode_sk743);
                tbl_JOIN_INNER_TD_7362851_output.setInt32(r, 1, _ws_quantity747);
                tbl_JOIN_INNER_TD_7362851_output.setInt64(r, 2, _ws_ext_sales_price752);
                tbl_JOIN_INNER_TD_7362851_output.setInt64(r, 3, _ws_net_paid758);
                tbl_JOIN_INNER_TD_7362851_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _w_warehouse_name497_n);
                tbl_JOIN_INNER_TD_7362851_output.setInt32(r, 5, _w_warehouse_sq_ft498);
                tbl_JOIN_INNER_TD_7362851_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _w_city503_n);
                tbl_JOIN_INNER_TD_7362851_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _w_county504_n);
                tbl_JOIN_INNER_TD_7362851_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _w_state505_n);
                tbl_JOIN_INNER_TD_7362851_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _w_country507_n);
                tbl_JOIN_INNER_TD_7362851_output.setInt32(r, 10, _d_year126);
                tbl_JOIN_INNER_TD_7362851_output.setInt32(r, 11, _d_moy128);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7362851_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7362851_key_rightMajor, SW_JOIN_INNER_TD_7362851_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_888970_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _t_time_sk465_k = tbl_Filter_TD_888970_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7362851_key_rightMajor keyA{_t_time_sk465_k};
            int32_t _t_time_sk465 = tbl_Filter_TD_888970_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7362851_payload_rightMajor payloadA{_t_time_sk465};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_8505770_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_sold_time_sk730_k = tbl_JOIN_INNER_TD_8505770_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7362851_key_rightMajor{_ws_sold_time_sk730_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _t_time_sk465 = (it->second)._t_time_sk465;
                int32_t _ws_sold_time_sk730 = tbl_JOIN_INNER_TD_8505770_output.getInt32(i, 0);
                int32_t _ws_ship_mode_sk743 = tbl_JOIN_INNER_TD_8505770_output.getInt32(i, 1);
                int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_8505770_output.getInt32(i, 2);
                int64_t _ws_ext_sales_price752 = tbl_JOIN_INNER_TD_8505770_output.getInt64(i, 3);
                int64_t _ws_net_paid758 = tbl_JOIN_INNER_TD_8505770_output.getInt64(i, 4);
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_JOIN_INNER_TD_8505770_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
                int32_t _w_warehouse_sq_ft498 = tbl_JOIN_INNER_TD_8505770_output.getInt32(i, 6);
                std::array<char, TPCDS_READ_MAX + 1> _w_city503_n = tbl_JOIN_INNER_TD_8505770_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _w_city503 = std::string(_w_city503_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _w_county504_n = tbl_JOIN_INNER_TD_8505770_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
                std::string _w_county504 = std::string(_w_county504_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _w_state505_n = tbl_JOIN_INNER_TD_8505770_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
                std::string _w_state505 = std::string(_w_state505_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _w_country507_n = tbl_JOIN_INNER_TD_8505770_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
                std::string _w_country507 = std::string(_w_country507_n.data());
                int32_t _d_year126 = tbl_JOIN_INNER_TD_8505770_output.getInt32(i, 11);
                int32_t _d_moy128 = tbl_JOIN_INNER_TD_8505770_output.getInt32(i, 12);
                tbl_JOIN_INNER_TD_7362851_output.setInt32(r, 0, _ws_ship_mode_sk743);
                tbl_JOIN_INNER_TD_7362851_output.setInt32(r, 1, _ws_quantity747);
                tbl_JOIN_INNER_TD_7362851_output.setInt64(r, 2, _ws_ext_sales_price752);
                tbl_JOIN_INNER_TD_7362851_output.setInt64(r, 3, _ws_net_paid758);
                tbl_JOIN_INNER_TD_7362851_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _w_warehouse_name497_n);
                tbl_JOIN_INNER_TD_7362851_output.setInt32(r, 5, _w_warehouse_sq_ft498);
                tbl_JOIN_INNER_TD_7362851_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _w_city503_n);
                tbl_JOIN_INNER_TD_7362851_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _w_county504_n);
                tbl_JOIN_INNER_TD_7362851_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _w_state505_n);
                tbl_JOIN_INNER_TD_7362851_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _w_country507_n);
                tbl_JOIN_INNER_TD_7362851_output.setInt32(r, 10, _d_year126);
                tbl_JOIN_INNER_TD_7362851_output.setInt32(r, 11, _d_moy128);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7362851_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7362851_output #Row: " << tbl_JOIN_INNER_TD_7362851_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6705937_key_leftMajor {
    int32_t _cs_ship_mode_sk1117;
    bool operator==(const SW_JOIN_INNER_TD_6705937_key_leftMajor& other) const {
        return ((_cs_ship_mode_sk1117 == other._cs_ship_mode_sk1117));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6705937_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6705937_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_ship_mode_sk1117));
    }
};
}
struct SW_JOIN_INNER_TD_6705937_payload_leftMajor {
    int32_t _cs_ship_mode_sk1117;
    int32_t _cs_quantity1122;
    int64_t _cs_sales_price1125;
    int64_t _cs_net_paid_inc_tax1134;
    std::string _w_warehouse_name3634;
    int32_t _w_warehouse_sq_ft3635;
    std::string _w_city3640;
    std::string _w_county3641;
    std::string _w_state3642;
    std::string _w_country3644;
    int32_t _d_year3652;
    int32_t _d_moy3654;
};
struct SW_JOIN_INNER_TD_6705937_key_rightMajor {
    int32_t _sm_ship_mode_sk3684;
    bool operator==(const SW_JOIN_INNER_TD_6705937_key_rightMajor& other) const {
        return ((_sm_ship_mode_sk3684 == other._sm_ship_mode_sk3684));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6705937_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6705937_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._sm_ship_mode_sk3684));
    }
};
}
struct SW_JOIN_INNER_TD_6705937_payload_rightMajor {
    int32_t _sm_ship_mode_sk3684;
};
void SW_JOIN_INNER_TD_6705937(Table &tbl_JOIN_INNER_TD_7312336_output, Table &tbl_Filter_TD_7222045_output, Table &tbl_JOIN_INNER_TD_6705937_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_ship_mode_sk#1117 = sm_ship_mode_sk#3684))
    // Left Table: ListBuffer(cs_ship_mode_sk#1117, cs_quantity#1122, cs_sales_price#1125, cs_net_paid_inc_tax#1134, w_warehouse_name#3634, w_warehouse_sq_ft#3635, w_city#3640, w_county#3641, w_state#3642, w_country#3644, d_year#3652, d_moy#3654)
    // Right Table: ListBuffer(sm_ship_mode_sk#3684)
    // Output Table: ListBuffer(cs_quantity#1122, cs_sales_price#1125, cs_net_paid_inc_tax#1134, w_warehouse_name#3634, w_warehouse_sq_ft#3635, w_city#3640, w_county#3641, w_state#3642, w_country#3644, d_year#3652, d_moy#3654)
    int left_nrow = tbl_JOIN_INNER_TD_7312336_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7222045_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6705937_key_leftMajor, SW_JOIN_INNER_TD_6705937_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7312336_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_ship_mode_sk1117_k = tbl_JOIN_INNER_TD_7312336_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6705937_key_leftMajor keyA{_cs_ship_mode_sk1117_k};
            int32_t _cs_ship_mode_sk1117 = tbl_JOIN_INNER_TD_7312336_output.getInt32(i, 0);
            int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_7312336_output.getInt32(i, 1);
            int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_7312336_output.getInt64(i, 2);
            int64_t _cs_net_paid_inc_tax1134 = tbl_JOIN_INNER_TD_7312336_output.getInt64(i, 3);
            std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name3634_n = tbl_JOIN_INNER_TD_7312336_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _w_warehouse_name3634 = std::string(_w_warehouse_name3634_n.data());
            int32_t _w_warehouse_sq_ft3635 = tbl_JOIN_INNER_TD_7312336_output.getInt32(i, 5);
            std::array<char, TPCDS_READ_MAX + 1> _w_city3640_n = tbl_JOIN_INNER_TD_7312336_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _w_city3640 = std::string(_w_city3640_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _w_county3641_n = tbl_JOIN_INNER_TD_7312336_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _w_county3641 = std::string(_w_county3641_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _w_state3642_n = tbl_JOIN_INNER_TD_7312336_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
            std::string _w_state3642 = std::string(_w_state3642_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _w_country3644_n = tbl_JOIN_INNER_TD_7312336_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            std::string _w_country3644 = std::string(_w_country3644_n.data());
            int32_t _d_year3652 = tbl_JOIN_INNER_TD_7312336_output.getInt32(i, 10);
            int32_t _d_moy3654 = tbl_JOIN_INNER_TD_7312336_output.getInt32(i, 11);
            SW_JOIN_INNER_TD_6705937_payload_leftMajor payloadA{_cs_ship_mode_sk1117, _cs_quantity1122, _cs_sales_price1125, _cs_net_paid_inc_tax1134, _w_warehouse_name3634, _w_warehouse_sq_ft3635, _w_city3640, _w_county3641, _w_state3642, _w_country3644, _d_year3652, _d_moy3654};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7222045_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _sm_ship_mode_sk3684_k = tbl_Filter_TD_7222045_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6705937_key_leftMajor{_sm_ship_mode_sk3684_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_ship_mode_sk1117 = (it->second)._cs_ship_mode_sk1117;
                int32_t _cs_quantity1122 = (it->second)._cs_quantity1122;
                int64_t _cs_sales_price1125 = (it->second)._cs_sales_price1125;
                int64_t _cs_net_paid_inc_tax1134 = (it->second)._cs_net_paid_inc_tax1134;
                std::string _w_warehouse_name3634 = (it->second)._w_warehouse_name3634;
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name3634_n{};
                memcpy(_w_warehouse_name3634_n.data(), (_w_warehouse_name3634).data(), (_w_warehouse_name3634).length());
                int32_t _w_warehouse_sq_ft3635 = (it->second)._w_warehouse_sq_ft3635;
                std::string _w_city3640 = (it->second)._w_city3640;
                std::array<char, TPCDS_READ_MAX + 1> _w_city3640_n{};
                memcpy(_w_city3640_n.data(), (_w_city3640).data(), (_w_city3640).length());
                std::string _w_county3641 = (it->second)._w_county3641;
                std::array<char, TPCDS_READ_MAX + 1> _w_county3641_n{};
                memcpy(_w_county3641_n.data(), (_w_county3641).data(), (_w_county3641).length());
                std::string _w_state3642 = (it->second)._w_state3642;
                std::array<char, TPCDS_READ_MAX + 1> _w_state3642_n{};
                memcpy(_w_state3642_n.data(), (_w_state3642).data(), (_w_state3642).length());
                std::string _w_country3644 = (it->second)._w_country3644;
                std::array<char, TPCDS_READ_MAX + 1> _w_country3644_n{};
                memcpy(_w_country3644_n.data(), (_w_country3644).data(), (_w_country3644).length());
                int32_t _d_year3652 = (it->second)._d_year3652;
                int32_t _d_moy3654 = (it->second)._d_moy3654;
                int32_t _sm_ship_mode_sk3684 = tbl_Filter_TD_7222045_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_6705937_output.setInt32(r, 0, _cs_quantity1122);
                tbl_JOIN_INNER_TD_6705937_output.setInt64(r, 1, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_6705937_output.setInt64(r, 2, _cs_net_paid_inc_tax1134);
                tbl_JOIN_INNER_TD_6705937_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _w_warehouse_name3634_n);
                tbl_JOIN_INNER_TD_6705937_output.setInt32(r, 4, _w_warehouse_sq_ft3635);
                tbl_JOIN_INNER_TD_6705937_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _w_city3640_n);
                tbl_JOIN_INNER_TD_6705937_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _w_county3641_n);
                tbl_JOIN_INNER_TD_6705937_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _w_state3642_n);
                tbl_JOIN_INNER_TD_6705937_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _w_country3644_n);
                tbl_JOIN_INNER_TD_6705937_output.setInt32(r, 9, _d_year3652);
                tbl_JOIN_INNER_TD_6705937_output.setInt32(r, 10, _d_moy3654);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6705937_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6705937_key_rightMajor, SW_JOIN_INNER_TD_6705937_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7222045_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _sm_ship_mode_sk3684_k = tbl_Filter_TD_7222045_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6705937_key_rightMajor keyA{_sm_ship_mode_sk3684_k};
            int32_t _sm_ship_mode_sk3684 = tbl_Filter_TD_7222045_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6705937_payload_rightMajor payloadA{_sm_ship_mode_sk3684};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7312336_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_ship_mode_sk1117_k = tbl_JOIN_INNER_TD_7312336_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6705937_key_rightMajor{_cs_ship_mode_sk1117_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _sm_ship_mode_sk3684 = (it->second)._sm_ship_mode_sk3684;
                int32_t _cs_ship_mode_sk1117 = tbl_JOIN_INNER_TD_7312336_output.getInt32(i, 0);
                int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_7312336_output.getInt32(i, 1);
                int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_7312336_output.getInt64(i, 2);
                int64_t _cs_net_paid_inc_tax1134 = tbl_JOIN_INNER_TD_7312336_output.getInt64(i, 3);
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name3634_n = tbl_JOIN_INNER_TD_7312336_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _w_warehouse_name3634 = std::string(_w_warehouse_name3634_n.data());
                int32_t _w_warehouse_sq_ft3635 = tbl_JOIN_INNER_TD_7312336_output.getInt32(i, 5);
                std::array<char, TPCDS_READ_MAX + 1> _w_city3640_n = tbl_JOIN_INNER_TD_7312336_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _w_city3640 = std::string(_w_city3640_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _w_county3641_n = tbl_JOIN_INNER_TD_7312336_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _w_county3641 = std::string(_w_county3641_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _w_state3642_n = tbl_JOIN_INNER_TD_7312336_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
                std::string _w_state3642 = std::string(_w_state3642_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _w_country3644_n = tbl_JOIN_INNER_TD_7312336_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
                std::string _w_country3644 = std::string(_w_country3644_n.data());
                int32_t _d_year3652 = tbl_JOIN_INNER_TD_7312336_output.getInt32(i, 10);
                int32_t _d_moy3654 = tbl_JOIN_INNER_TD_7312336_output.getInt32(i, 11);
                tbl_JOIN_INNER_TD_6705937_output.setInt32(r, 0, _cs_quantity1122);
                tbl_JOIN_INNER_TD_6705937_output.setInt64(r, 1, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_6705937_output.setInt64(r, 2, _cs_net_paid_inc_tax1134);
                tbl_JOIN_INNER_TD_6705937_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _w_warehouse_name3634_n);
                tbl_JOIN_INNER_TD_6705937_output.setInt32(r, 4, _w_warehouse_sq_ft3635);
                tbl_JOIN_INNER_TD_6705937_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _w_city3640_n);
                tbl_JOIN_INNER_TD_6705937_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _w_county3641_n);
                tbl_JOIN_INNER_TD_6705937_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _w_state3642_n);
                tbl_JOIN_INNER_TD_6705937_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _w_country3644_n);
                tbl_JOIN_INNER_TD_6705937_output.setInt32(r, 9, _d_year3652);
                tbl_JOIN_INNER_TD_6705937_output.setInt32(r, 10, _d_moy3654);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6705937_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6705937_output #Row: " << tbl_JOIN_INNER_TD_6705937_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6461642_key_leftMajor {
    int32_t _ws_ship_mode_sk743;
    bool operator==(const SW_JOIN_INNER_TD_6461642_key_leftMajor& other) const {
        return ((_ws_ship_mode_sk743 == other._ws_ship_mode_sk743));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6461642_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6461642_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_ship_mode_sk743));
    }
};
}
struct SW_JOIN_INNER_TD_6461642_payload_leftMajor {
    int32_t _ws_ship_mode_sk743;
    int32_t _ws_quantity747;
    int64_t _ws_ext_sales_price752;
    int64_t _ws_net_paid758;
    std::string _w_warehouse_name497;
    int32_t _w_warehouse_sq_ft498;
    std::string _w_city503;
    std::string _w_county504;
    std::string _w_state505;
    std::string _w_country507;
    int32_t _d_year126;
    int32_t _d_moy128;
};
struct SW_JOIN_INNER_TD_6461642_key_rightMajor {
    int32_t _sm_ship_mode_sk360;
    bool operator==(const SW_JOIN_INNER_TD_6461642_key_rightMajor& other) const {
        return ((_sm_ship_mode_sk360 == other._sm_ship_mode_sk360));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6461642_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6461642_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._sm_ship_mode_sk360));
    }
};
}
struct SW_JOIN_INNER_TD_6461642_payload_rightMajor {
    int32_t _sm_ship_mode_sk360;
};
void SW_JOIN_INNER_TD_6461642(Table &tbl_JOIN_INNER_TD_7362851_output, Table &tbl_Filter_TD_748969_output, Table &tbl_JOIN_INNER_TD_6461642_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_ship_mode_sk#743 = sm_ship_mode_sk#360))
    // Left Table: ListBuffer(ws_ship_mode_sk#743, ws_quantity#747, ws_ext_sales_price#752, ws_net_paid#758, w_warehouse_name#497, w_warehouse_sq_ft#498, w_city#503, w_county#504, w_state#505, w_country#507, d_year#126, d_moy#128)
    // Right Table: ListBuffer(sm_ship_mode_sk#360)
    // Output Table: ListBuffer(ws_quantity#747, ws_ext_sales_price#752, ws_net_paid#758, w_warehouse_name#497, w_warehouse_sq_ft#498, w_city#503, w_county#504, w_state#505, w_country#507, d_year#126, d_moy#128)
    int left_nrow = tbl_JOIN_INNER_TD_7362851_output.getNumRow();
    int right_nrow = tbl_Filter_TD_748969_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6461642_key_leftMajor, SW_JOIN_INNER_TD_6461642_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7362851_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_ship_mode_sk743_k = tbl_JOIN_INNER_TD_7362851_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6461642_key_leftMajor keyA{_ws_ship_mode_sk743_k};
            int32_t _ws_ship_mode_sk743 = tbl_JOIN_INNER_TD_7362851_output.getInt32(i, 0);
            int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_7362851_output.getInt32(i, 1);
            int64_t _ws_ext_sales_price752 = tbl_JOIN_INNER_TD_7362851_output.getInt64(i, 2);
            int64_t _ws_net_paid758 = tbl_JOIN_INNER_TD_7362851_output.getInt64(i, 3);
            std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_JOIN_INNER_TD_7362851_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
            int32_t _w_warehouse_sq_ft498 = tbl_JOIN_INNER_TD_7362851_output.getInt32(i, 5);
            std::array<char, TPCDS_READ_MAX + 1> _w_city503_n = tbl_JOIN_INNER_TD_7362851_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _w_city503 = std::string(_w_city503_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _w_county504_n = tbl_JOIN_INNER_TD_7362851_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _w_county504 = std::string(_w_county504_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _w_state505_n = tbl_JOIN_INNER_TD_7362851_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
            std::string _w_state505 = std::string(_w_state505_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _w_country507_n = tbl_JOIN_INNER_TD_7362851_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            std::string _w_country507 = std::string(_w_country507_n.data());
            int32_t _d_year126 = tbl_JOIN_INNER_TD_7362851_output.getInt32(i, 10);
            int32_t _d_moy128 = tbl_JOIN_INNER_TD_7362851_output.getInt32(i, 11);
            SW_JOIN_INNER_TD_6461642_payload_leftMajor payloadA{_ws_ship_mode_sk743, _ws_quantity747, _ws_ext_sales_price752, _ws_net_paid758, _w_warehouse_name497, _w_warehouse_sq_ft498, _w_city503, _w_county504, _w_state505, _w_country507, _d_year126, _d_moy128};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_748969_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _sm_ship_mode_sk360_k = tbl_Filter_TD_748969_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6461642_key_leftMajor{_sm_ship_mode_sk360_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_ship_mode_sk743 = (it->second)._ws_ship_mode_sk743;
                int32_t _ws_quantity747 = (it->second)._ws_quantity747;
                int64_t _ws_ext_sales_price752 = (it->second)._ws_ext_sales_price752;
                int64_t _ws_net_paid758 = (it->second)._ws_net_paid758;
                std::string _w_warehouse_name497 = (it->second)._w_warehouse_name497;
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n{};
                memcpy(_w_warehouse_name497_n.data(), (_w_warehouse_name497).data(), (_w_warehouse_name497).length());
                int32_t _w_warehouse_sq_ft498 = (it->second)._w_warehouse_sq_ft498;
                std::string _w_city503 = (it->second)._w_city503;
                std::array<char, TPCDS_READ_MAX + 1> _w_city503_n{};
                memcpy(_w_city503_n.data(), (_w_city503).data(), (_w_city503).length());
                std::string _w_county504 = (it->second)._w_county504;
                std::array<char, TPCDS_READ_MAX + 1> _w_county504_n{};
                memcpy(_w_county504_n.data(), (_w_county504).data(), (_w_county504).length());
                std::string _w_state505 = (it->second)._w_state505;
                std::array<char, TPCDS_READ_MAX + 1> _w_state505_n{};
                memcpy(_w_state505_n.data(), (_w_state505).data(), (_w_state505).length());
                std::string _w_country507 = (it->second)._w_country507;
                std::array<char, TPCDS_READ_MAX + 1> _w_country507_n{};
                memcpy(_w_country507_n.data(), (_w_country507).data(), (_w_country507).length());
                int32_t _d_year126 = (it->second)._d_year126;
                int32_t _d_moy128 = (it->second)._d_moy128;
                int32_t _sm_ship_mode_sk360 = tbl_Filter_TD_748969_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_6461642_output.setInt32(r, 0, _ws_quantity747);
                tbl_JOIN_INNER_TD_6461642_output.setInt64(r, 1, _ws_ext_sales_price752);
                tbl_JOIN_INNER_TD_6461642_output.setInt64(r, 2, _ws_net_paid758);
                tbl_JOIN_INNER_TD_6461642_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _w_warehouse_name497_n);
                tbl_JOIN_INNER_TD_6461642_output.setInt32(r, 4, _w_warehouse_sq_ft498);
                tbl_JOIN_INNER_TD_6461642_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _w_city503_n);
                tbl_JOIN_INNER_TD_6461642_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _w_county504_n);
                tbl_JOIN_INNER_TD_6461642_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _w_state505_n);
                tbl_JOIN_INNER_TD_6461642_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _w_country507_n);
                tbl_JOIN_INNER_TD_6461642_output.setInt32(r, 9, _d_year126);
                tbl_JOIN_INNER_TD_6461642_output.setInt32(r, 10, _d_moy128);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6461642_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6461642_key_rightMajor, SW_JOIN_INNER_TD_6461642_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_748969_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _sm_ship_mode_sk360_k = tbl_Filter_TD_748969_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6461642_key_rightMajor keyA{_sm_ship_mode_sk360_k};
            int32_t _sm_ship_mode_sk360 = tbl_Filter_TD_748969_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6461642_payload_rightMajor payloadA{_sm_ship_mode_sk360};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7362851_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_ship_mode_sk743_k = tbl_JOIN_INNER_TD_7362851_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6461642_key_rightMajor{_ws_ship_mode_sk743_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _sm_ship_mode_sk360 = (it->second)._sm_ship_mode_sk360;
                int32_t _ws_ship_mode_sk743 = tbl_JOIN_INNER_TD_7362851_output.getInt32(i, 0);
                int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_7362851_output.getInt32(i, 1);
                int64_t _ws_ext_sales_price752 = tbl_JOIN_INNER_TD_7362851_output.getInt64(i, 2);
                int64_t _ws_net_paid758 = tbl_JOIN_INNER_TD_7362851_output.getInt64(i, 3);
                std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_JOIN_INNER_TD_7362851_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _w_warehouse_name497 = std::string(_w_warehouse_name497_n.data());
                int32_t _w_warehouse_sq_ft498 = tbl_JOIN_INNER_TD_7362851_output.getInt32(i, 5);
                std::array<char, TPCDS_READ_MAX + 1> _w_city503_n = tbl_JOIN_INNER_TD_7362851_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _w_city503 = std::string(_w_city503_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _w_county504_n = tbl_JOIN_INNER_TD_7362851_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _w_county504 = std::string(_w_county504_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _w_state505_n = tbl_JOIN_INNER_TD_7362851_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
                std::string _w_state505 = std::string(_w_state505_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _w_country507_n = tbl_JOIN_INNER_TD_7362851_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
                std::string _w_country507 = std::string(_w_country507_n.data());
                int32_t _d_year126 = tbl_JOIN_INNER_TD_7362851_output.getInt32(i, 10);
                int32_t _d_moy128 = tbl_JOIN_INNER_TD_7362851_output.getInt32(i, 11);
                tbl_JOIN_INNER_TD_6461642_output.setInt32(r, 0, _ws_quantity747);
                tbl_JOIN_INNER_TD_6461642_output.setInt64(r, 1, _ws_ext_sales_price752);
                tbl_JOIN_INNER_TD_6461642_output.setInt64(r, 2, _ws_net_paid758);
                tbl_JOIN_INNER_TD_6461642_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _w_warehouse_name497_n);
                tbl_JOIN_INNER_TD_6461642_output.setInt32(r, 4, _w_warehouse_sq_ft498);
                tbl_JOIN_INNER_TD_6461642_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _w_city503_n);
                tbl_JOIN_INNER_TD_6461642_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _w_county504_n);
                tbl_JOIN_INNER_TD_6461642_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _w_state505_n);
                tbl_JOIN_INNER_TD_6461642_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _w_country507_n);
                tbl_JOIN_INNER_TD_6461642_output.setInt32(r, 9, _d_year126);
                tbl_JOIN_INNER_TD_6461642_output.setInt32(r, 10, _d_moy128);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6461642_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6461642_output #Row: " << tbl_JOIN_INNER_TD_6461642_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_5572054_key {
    std::string _w_warehouse_name3634;
    int32_t _w_warehouse_sq_ft3635;
    std::string _w_city3640;
    std::string _w_county3641;
    std::string _w_state3642;
    std::string _w_country3644;
    int32_t _d_year3652;
    bool operator==(const SW_Aggregate_TD_5572054_key& other) const { return (_w_warehouse_name3634 == other._w_warehouse_name3634) && (_w_warehouse_sq_ft3635 == other._w_warehouse_sq_ft3635) && (_w_city3640 == other._w_city3640) && (_w_county3641 == other._w_county3641) && (_w_state3642 == other._w_state3642) && (_w_country3644 == other._w_country3644) && (_d_year3652 == other._d_year3652); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_5572054_key> {
    std::size_t operator() (const SW_Aggregate_TD_5572054_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._w_warehouse_name3634)) + (hash<int32_t>()(k._w_warehouse_sq_ft3635)) + (hash<string>()(k._w_city3640)) + (hash<string>()(k._w_county3641)) + (hash<string>()(k._w_state3642)) + (hash<string>()(k._w_country3644)) + (hash<int32_t>()(k._d_year3652));
    }
};
}
struct SW_Aggregate_TD_5572054_payload {
    std::string _ship_carriers3570;
    int32_t _year3571;
    int64_t _jan_sales3572_sum_0;
    int64_t _feb_sales3573_sum_1;
    int64_t _mar_sales3574_sum_2;
    int64_t _apr_sales3575_sum_3;
    int64_t _may_sales3576_sum_4;
    int64_t _jun_sales3577_sum_5;
    int64_t _jul_sales3578_sum_6;
    int64_t _aug_sales3579_sum_7;
    int64_t _sep_sales3580_sum_8;
    int64_t _oct_sales3581_sum_9;
    int64_t _nov_sales3582_sum_10;
    int64_t _dec_sales3583_sum_11;
    int64_t _jan_net3584_sum_12;
    int64_t _feb_net3585_sum_13;
    int64_t _mar_net3586_sum_14;
    int64_t _apr_net3587_sum_15;
    int64_t _may_net3588_sum_16;
    int64_t _jun_net3589_sum_17;
    int64_t _jul_net3590_sum_18;
    int64_t _aug_net3591_sum_19;
    int64_t _sep_net3592_sum_20;
    int64_t _oct_net3593_sum_21;
    int64_t _nov_net3594_sum_22;
    int64_t _dec_net3595_sum_23;
};
void SW_Aggregate_TD_5572054(Table &tbl_JOIN_INNER_TD_6705937_output, Table &tbl_Aggregate_TD_5572054_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(w_warehouse_name#3634, w_warehouse_sq_ft#3635, w_city#3640, w_county#3641, w_state#3642, w_country#3644, d_year#3652, DHL,BARIAN AS ship_carriers#3570, d_year#3652 AS year#3571, sum(CASE WHEN (d_moy#3654 = 1) THEN CheckOverflow((promote_precision(cast(cs_sales_price#1125 as decimal(12,2))) * promote_precision(cast(cast(cs_quantity#1122 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS jan_sales#3572, sum(CASE WHEN (d_moy#3654 = 2) THEN CheckOverflow((promote_precision(cast(cs_sales_price#1125 as decimal(12,2))) * promote_precision(cast(cast(cs_quantity#1122 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS feb_sales#3573, sum(CASE WHEN (d_moy#3654 = 3) THEN CheckOverflow((promote_precision(cast(cs_sales_price#1125 as decimal(12,2))) * promote_precision(cast(cast(cs_quantity#1122 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS mar_sales#3574, sum(CASE WHEN (d_moy#3654 = 4) THEN CheckOverflow((promote_precision(cast(cs_sales_price#1125 as decimal(12,2))) * promote_precision(cast(cast(cs_quantity#1122 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS apr_sales#3575, sum(CASE WHEN (d_moy#3654 = 5) THEN CheckOverflow((promote_precision(cast(cs_sales_price#1125 as decimal(12,2))) * promote_precision(cast(cast(cs_quantity#1122 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS may_sales#3576, sum(CASE WHEN (d_moy#3654 = 6) THEN CheckOverflow((promote_precision(cast(cs_sales_price#1125 as decimal(12,2))) * promote_precision(cast(cast(cs_quantity#1122 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS jun_sales#3577, sum(CASE WHEN (d_moy#3654 = 7) THEN CheckOverflow((promote_precision(cast(cs_sales_price#1125 as decimal(12,2))) * promote_precision(cast(cast(cs_quantity#1122 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS jul_sales#3578, sum(CASE WHEN (d_moy#3654 = 8) THEN CheckOverflow((promote_precision(cast(cs_sales_price#1125 as decimal(12,2))) * promote_precision(cast(cast(cs_quantity#1122 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS aug_sales#3579, sum(CASE WHEN (d_moy#3654 = 9) THEN CheckOverflow((promote_precision(cast(cs_sales_price#1125 as decimal(12,2))) * promote_precision(cast(cast(cs_quantity#1122 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS sep_sales#3580, sum(CASE WHEN (d_moy#3654 = 10) THEN CheckOverflow((promote_precision(cast(cs_sales_price#1125 as decimal(12,2))) * promote_precision(cast(cast(cs_quantity#1122 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS oct_sales#3581, sum(CASE WHEN (d_moy#3654 = 11) THEN CheckOverflow((promote_precision(cast(cs_sales_price#1125 as decimal(12,2))) * promote_precision(cast(cast(cs_quantity#1122 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS nov_sales#3582, sum(CASE WHEN (d_moy#3654 = 12) THEN CheckOverflow((promote_precision(cast(cs_sales_price#1125 as decimal(12,2))) * promote_precision(cast(cast(cs_quantity#1122 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS dec_sales#3583, sum(CASE WHEN (d_moy#3654 = 1) THEN CheckOverflow((promote_precision(cast(cs_net_paid_inc_tax#1134 as decimal(12,2))) * promote_precision(cast(cast(cs_quantity#1122 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS jan_net#3584, sum(CASE WHEN (d_moy#3654 = 2) THEN CheckOverflow((promote_precision(cast(cs_net_paid_inc_tax#1134 as decimal(12,2))) * promote_precision(cast(cast(cs_quantity#1122 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS feb_net#3585, sum(CASE WHEN (d_moy#3654 = 3) THEN CheckOverflow((promote_precision(cast(cs_net_paid_inc_tax#1134 as decimal(12,2))) * promote_precision(cast(cast(cs_quantity#1122 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS mar_net#3586, sum(CASE WHEN (d_moy#3654 = 4) THEN CheckOverflow((promote_precision(cast(cs_net_paid_inc_tax#1134 as decimal(12,2))) * promote_precision(cast(cast(cs_quantity#1122 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS apr_net#3587, sum(CASE WHEN (d_moy#3654 = 5) THEN CheckOverflow((promote_precision(cast(cs_net_paid_inc_tax#1134 as decimal(12,2))) * promote_precision(cast(cast(cs_quantity#1122 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS may_net#3588, sum(CASE WHEN (d_moy#3654 = 6) THEN CheckOverflow((promote_precision(cast(cs_net_paid_inc_tax#1134 as decimal(12,2))) * promote_precision(cast(cast(cs_quantity#1122 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS jun_net#3589, sum(CASE WHEN (d_moy#3654 = 7) THEN CheckOverflow((promote_precision(cast(cs_net_paid_inc_tax#1134 as decimal(12,2))) * promote_precision(cast(cast(cs_quantity#1122 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS jul_net#3590, sum(CASE WHEN (d_moy#3654 = 8) THEN CheckOverflow((promote_precision(cast(cs_net_paid_inc_tax#1134 as decimal(12,2))) * promote_precision(cast(cast(cs_quantity#1122 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS aug_net#3591, sum(CASE WHEN (d_moy#3654 = 9) THEN CheckOverflow((promote_precision(cast(cs_net_paid_inc_tax#1134 as decimal(12,2))) * promote_precision(cast(cast(cs_quantity#1122 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS sep_net#3592, sum(CASE WHEN (d_moy#3654 = 10) THEN CheckOverflow((promote_precision(cast(cs_net_paid_inc_tax#1134 as decimal(12,2))) * promote_precision(cast(cast(cs_quantity#1122 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS oct_net#3593, sum(CASE WHEN (d_moy#3654 = 11) THEN CheckOverflow((promote_precision(cast(cs_net_paid_inc_tax#1134 as decimal(12,2))) * promote_precision(cast(cast(cs_quantity#1122 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS nov_net#3594, sum(CASE WHEN (d_moy#3654 = 12) THEN CheckOverflow((promote_precision(cast(cs_net_paid_inc_tax#1134 as decimal(12,2))) * promote_precision(cast(cast(cs_quantity#1122 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS dec_net#3595)
    // Input: ListBuffer(cs_quantity#1122, cs_sales_price#1125, cs_net_paid_inc_tax#1134, w_warehouse_name#3634, w_warehouse_sq_ft#3635, w_city#3640, w_county#3641, w_state#3642, w_country#3644, d_year#3652, d_moy#3654)
    // Output: ListBuffer(w_warehouse_name#3634, w_warehouse_sq_ft#3635, w_city#3640, w_county#3641, w_state#3642, w_country#3644, ship_carriers#3570, year#3571, jan_sales#3572, feb_sales#3573, mar_sales#3574, apr_sales#3575, may_sales#3576, jun_sales#3577, jul_sales#3578, aug_sales#3579, sep_sales#3580, oct_sales#3581, nov_sales#3582, dec_sales#3583, jan_net#3584, feb_net#3585, mar_net#3586, apr_net#3587, may_net#3588, jun_net#3589, jul_net#3590, aug_net#3591, sep_net#3592, oct_net#3593, nov_net#3594, dec_net#3595)
    std::unordered_map<SW_Aggregate_TD_5572054_key, SW_Aggregate_TD_5572054_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_6705937_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_6705937_output.getInt32(i, 0);
        int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_6705937_output.getInt64(i, 1);
        int64_t _cs_net_paid_inc_tax1134 = tbl_JOIN_INNER_TD_6705937_output.getInt64(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name3634 = tbl_JOIN_INNER_TD_6705937_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        int32_t _w_warehouse_sq_ft3635 = tbl_JOIN_INNER_TD_6705937_output.getInt32(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _w_city3640 = tbl_JOIN_INNER_TD_6705937_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _w_county3641 = tbl_JOIN_INNER_TD_6705937_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        std::array<char, TPCDS_READ_MAX + 1> _w_state3642 = tbl_JOIN_INNER_TD_6705937_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
        std::array<char, TPCDS_READ_MAX + 1> _w_country3644 = tbl_JOIN_INNER_TD_6705937_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
        int32_t _d_year3652 = tbl_JOIN_INNER_TD_6705937_output.getInt32(i, 9);
        int32_t _d_moy3654 = tbl_JOIN_INNER_TD_6705937_output.getInt32(i, 10);
        SW_Aggregate_TD_5572054_key k{std::string(_w_warehouse_name3634.data()), _w_warehouse_sq_ft3635, std::string(_w_city3640.data()), std::string(_w_county3641.data()), std::string(_w_state3642.data()), std::string(_w_country3644.data()), _d_year3652};
        std::string _ship_carriers3570 = "DHL,BARIAN";
        int32_t _year3571 = _d_year3652;
        int64_t _jan_sales3572_sum_0 = (_d_moy3654 == 1) ? (_cs_sales_price1125 * _cs_quantity1122) : 0.00;
        int64_t _feb_sales3573_sum_1 = (_d_moy3654 == 2) ? (_cs_sales_price1125 * _cs_quantity1122) : 0.00;
        int64_t _mar_sales3574_sum_2 = (_d_moy3654 == 3) ? (_cs_sales_price1125 * _cs_quantity1122) : 0.00;
        int64_t _apr_sales3575_sum_3 = (_d_moy3654 == 4) ? (_cs_sales_price1125 * _cs_quantity1122) : 0.00;
        int64_t _may_sales3576_sum_4 = (_d_moy3654 == 5) ? (_cs_sales_price1125 * _cs_quantity1122) : 0.00;
        int64_t _jun_sales3577_sum_5 = (_d_moy3654 == 6) ? (_cs_sales_price1125 * _cs_quantity1122) : 0.00;
        int64_t _jul_sales3578_sum_6 = (_d_moy3654 == 7) ? (_cs_sales_price1125 * _cs_quantity1122) : 0.00;
        int64_t _aug_sales3579_sum_7 = (_d_moy3654 == 8) ? (_cs_sales_price1125 * _cs_quantity1122) : 0.00;
        int64_t _sep_sales3580_sum_8 = (_d_moy3654 == 9) ? (_cs_sales_price1125 * _cs_quantity1122) : 0.00;
        int64_t _oct_sales3581_sum_9 = (_d_moy3654 == 10) ? (_cs_sales_price1125 * _cs_quantity1122) : 0.00;
        int64_t _nov_sales3582_sum_10 = (_d_moy3654 == 11) ? (_cs_sales_price1125 * _cs_quantity1122) : 0.00;
        int64_t _dec_sales3583_sum_11 = (_d_moy3654 == 12) ? (_cs_sales_price1125 * _cs_quantity1122) : 0.00;
        int64_t _jan_net3584_sum_12 = (_d_moy3654 == 1) ? (_cs_net_paid_inc_tax1134 * _cs_quantity1122) : 0.00;
        int64_t _feb_net3585_sum_13 = (_d_moy3654 == 2) ? (_cs_net_paid_inc_tax1134 * _cs_quantity1122) : 0.00;
        int64_t _mar_net3586_sum_14 = (_d_moy3654 == 3) ? (_cs_net_paid_inc_tax1134 * _cs_quantity1122) : 0.00;
        int64_t _apr_net3587_sum_15 = (_d_moy3654 == 4) ? (_cs_net_paid_inc_tax1134 * _cs_quantity1122) : 0.00;
        int64_t _may_net3588_sum_16 = (_d_moy3654 == 5) ? (_cs_net_paid_inc_tax1134 * _cs_quantity1122) : 0.00;
        int64_t _jun_net3589_sum_17 = (_d_moy3654 == 6) ? (_cs_net_paid_inc_tax1134 * _cs_quantity1122) : 0.00;
        int64_t _jul_net3590_sum_18 = (_d_moy3654 == 7) ? (_cs_net_paid_inc_tax1134 * _cs_quantity1122) : 0.00;
        int64_t _aug_net3591_sum_19 = (_d_moy3654 == 8) ? (_cs_net_paid_inc_tax1134 * _cs_quantity1122) : 0.00;
        int64_t _sep_net3592_sum_20 = (_d_moy3654 == 9) ? (_cs_net_paid_inc_tax1134 * _cs_quantity1122) : 0.00;
        int64_t _oct_net3593_sum_21 = (_d_moy3654 == 10) ? (_cs_net_paid_inc_tax1134 * _cs_quantity1122) : 0.00;
        int64_t _nov_net3594_sum_22 = (_d_moy3654 == 11) ? (_cs_net_paid_inc_tax1134 * _cs_quantity1122) : 0.00;
        int64_t _dec_net3595_sum_23 = (_d_moy3654 == 12) ? (_cs_net_paid_inc_tax1134 * _cs_quantity1122) : 0.00;
        SW_Aggregate_TD_5572054_payload p{std::string(_ship_carriers3570.data()), _year3571, _jan_sales3572_sum_0, _feb_sales3573_sum_1, _mar_sales3574_sum_2, _apr_sales3575_sum_3, _may_sales3576_sum_4, _jun_sales3577_sum_5, _jul_sales3578_sum_6, _aug_sales3579_sum_7, _sep_sales3580_sum_8, _oct_sales3581_sum_9, _nov_sales3582_sum_10, _dec_sales3583_sum_11, _jan_net3584_sum_12, _feb_net3585_sum_13, _mar_net3586_sum_14, _apr_net3587_sum_15, _may_net3588_sum_16, _jun_net3589_sum_17, _jul_net3590_sum_18, _aug_net3591_sum_19, _sep_net3592_sum_20, _oct_net3593_sum_21, _nov_net3594_sum_22, _dec_net3595_sum_23};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._jan_sales3572_sum_0 + _jan_sales3572_sum_0;
            p._jan_sales3572_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._feb_sales3573_sum_1 + _feb_sales3573_sum_1;
            p._feb_sales3573_sum_1 = sum_1;
            int64_t sum_2 = (it->second)._mar_sales3574_sum_2 + _mar_sales3574_sum_2;
            p._mar_sales3574_sum_2 = sum_2;
            int64_t sum_3 = (it->second)._apr_sales3575_sum_3 + _apr_sales3575_sum_3;
            p._apr_sales3575_sum_3 = sum_3;
            int64_t sum_4 = (it->second)._may_sales3576_sum_4 + _may_sales3576_sum_4;
            p._may_sales3576_sum_4 = sum_4;
            int64_t sum_5 = (it->second)._jun_sales3577_sum_5 + _jun_sales3577_sum_5;
            p._jun_sales3577_sum_5 = sum_5;
            int64_t sum_6 = (it->second)._jul_sales3578_sum_6 + _jul_sales3578_sum_6;
            p._jul_sales3578_sum_6 = sum_6;
            int64_t sum_7 = (it->second)._aug_sales3579_sum_7 + _aug_sales3579_sum_7;
            p._aug_sales3579_sum_7 = sum_7;
            int64_t sum_8 = (it->second)._sep_sales3580_sum_8 + _sep_sales3580_sum_8;
            p._sep_sales3580_sum_8 = sum_8;
            int64_t sum_9 = (it->second)._oct_sales3581_sum_9 + _oct_sales3581_sum_9;
            p._oct_sales3581_sum_9 = sum_9;
            int64_t sum_10 = (it->second)._nov_sales3582_sum_10 + _nov_sales3582_sum_10;
            p._nov_sales3582_sum_10 = sum_10;
            int64_t sum_11 = (it->second)._dec_sales3583_sum_11 + _dec_sales3583_sum_11;
            p._dec_sales3583_sum_11 = sum_11;
            int64_t sum_12 = (it->second)._jan_net3584_sum_12 + _jan_net3584_sum_12;
            p._jan_net3584_sum_12 = sum_12;
            int64_t sum_13 = (it->second)._feb_net3585_sum_13 + _feb_net3585_sum_13;
            p._feb_net3585_sum_13 = sum_13;
            int64_t sum_14 = (it->second)._mar_net3586_sum_14 + _mar_net3586_sum_14;
            p._mar_net3586_sum_14 = sum_14;
            int64_t sum_15 = (it->second)._apr_net3587_sum_15 + _apr_net3587_sum_15;
            p._apr_net3587_sum_15 = sum_15;
            int64_t sum_16 = (it->second)._may_net3588_sum_16 + _may_net3588_sum_16;
            p._may_net3588_sum_16 = sum_16;
            int64_t sum_17 = (it->second)._jun_net3589_sum_17 + _jun_net3589_sum_17;
            p._jun_net3589_sum_17 = sum_17;
            int64_t sum_18 = (it->second)._jul_net3590_sum_18 + _jul_net3590_sum_18;
            p._jul_net3590_sum_18 = sum_18;
            int64_t sum_19 = (it->second)._aug_net3591_sum_19 + _aug_net3591_sum_19;
            p._aug_net3591_sum_19 = sum_19;
            int64_t sum_20 = (it->second)._sep_net3592_sum_20 + _sep_net3592_sum_20;
            p._sep_net3592_sum_20 = sum_20;
            int64_t sum_21 = (it->second)._oct_net3593_sum_21 + _oct_net3593_sum_21;
            p._oct_net3593_sum_21 = sum_21;
            int64_t sum_22 = (it->second)._nov_net3594_sum_22 + _nov_net3594_sum_22;
            p._nov_net3594_sum_22 = sum_22;
            int64_t sum_23 = (it->second)._dec_net3595_sum_23 + _dec_net3595_sum_23;
            p._dec_net3595_sum_23 = sum_23;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name3634{};
        memcpy(_w_warehouse_name3634.data(), ((it.first)._w_warehouse_name3634).data(), ((it.first)._w_warehouse_name3634).length());
        tbl_Aggregate_TD_5572054_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _w_warehouse_name3634);
        tbl_Aggregate_TD_5572054_output.setInt32(r, 1, (it.first)._w_warehouse_sq_ft3635);
        std::array<char, TPCDS_READ_MAX + 1> _w_city3640{};
        memcpy(_w_city3640.data(), ((it.first)._w_city3640).data(), ((it.first)._w_city3640).length());
        tbl_Aggregate_TD_5572054_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _w_city3640);
        std::array<char, TPCDS_READ_MAX + 1> _w_county3641{};
        memcpy(_w_county3641.data(), ((it.first)._w_county3641).data(), ((it.first)._w_county3641).length());
        tbl_Aggregate_TD_5572054_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _w_county3641);
        std::array<char, TPCDS_READ_MAX + 1> _w_state3642{};
        memcpy(_w_state3642.data(), ((it.first)._w_state3642).data(), ((it.first)._w_state3642).length());
        tbl_Aggregate_TD_5572054_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _w_state3642);
        std::array<char, TPCDS_READ_MAX + 1> _w_country3644{};
        memcpy(_w_country3644.data(), ((it.first)._w_country3644).data(), ((it.first)._w_country3644).length());
        tbl_Aggregate_TD_5572054_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _w_country3644);
        // _d_year3652 not required in the output table
        std::array<char, TPCDS_READ_MAX + 1> _ship_carriers3570_n{};
        memcpy(_ship_carriers3570_n.data(), (it.second)._ship_carriers3570.data(), (it.second)._ship_carriers3570.length());
        tbl_Aggregate_TD_5572054_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _ship_carriers3570_n);
        tbl_Aggregate_TD_5572054_output.setInt32(r, 7, (it.second)._year3571);
        int64_t _jan_sales3572 = (it.second)._jan_sales3572_sum_0;
        tbl_Aggregate_TD_5572054_output.setInt64(r, 8, _jan_sales3572);
        int64_t _feb_sales3573 = (it.second)._feb_sales3573_sum_1;
        tbl_Aggregate_TD_5572054_output.setInt64(r, 9, _feb_sales3573);
        int64_t _mar_sales3574 = (it.second)._mar_sales3574_sum_2;
        tbl_Aggregate_TD_5572054_output.setInt64(r, 10, _mar_sales3574);
        int64_t _apr_sales3575 = (it.second)._apr_sales3575_sum_3;
        tbl_Aggregate_TD_5572054_output.setInt64(r, 11, _apr_sales3575);
        int64_t _may_sales3576 = (it.second)._may_sales3576_sum_4;
        tbl_Aggregate_TD_5572054_output.setInt64(r, 12, _may_sales3576);
        int64_t _jun_sales3577 = (it.second)._jun_sales3577_sum_5;
        tbl_Aggregate_TD_5572054_output.setInt64(r, 13, _jun_sales3577);
        int64_t _jul_sales3578 = (it.second)._jul_sales3578_sum_6;
        tbl_Aggregate_TD_5572054_output.setInt64(r, 14, _jul_sales3578);
        int64_t _aug_sales3579 = (it.second)._aug_sales3579_sum_7;
        tbl_Aggregate_TD_5572054_output.setInt64(r, 15, _aug_sales3579);
        int64_t _sep_sales3580 = (it.second)._sep_sales3580_sum_8;
        tbl_Aggregate_TD_5572054_output.setInt64(r, 16, _sep_sales3580);
        int64_t _oct_sales3581 = (it.second)._oct_sales3581_sum_9;
        tbl_Aggregate_TD_5572054_output.setInt64(r, 17, _oct_sales3581);
        int64_t _nov_sales3582 = (it.second)._nov_sales3582_sum_10;
        tbl_Aggregate_TD_5572054_output.setInt64(r, 18, _nov_sales3582);
        int64_t _dec_sales3583 = (it.second)._dec_sales3583_sum_11;
        tbl_Aggregate_TD_5572054_output.setInt64(r, 19, _dec_sales3583);
        int64_t _jan_net3584 = (it.second)._jan_net3584_sum_12;
        tbl_Aggregate_TD_5572054_output.setInt64(r, 20, _jan_net3584);
        int64_t _feb_net3585 = (it.second)._feb_net3585_sum_13;
        tbl_Aggregate_TD_5572054_output.setInt64(r, 21, _feb_net3585);
        int64_t _mar_net3586 = (it.second)._mar_net3586_sum_14;
        tbl_Aggregate_TD_5572054_output.setInt64(r, 22, _mar_net3586);
        int64_t _apr_net3587 = (it.second)._apr_net3587_sum_15;
        tbl_Aggregate_TD_5572054_output.setInt64(r, 23, _apr_net3587);
        int64_t _may_net3588 = (it.second)._may_net3588_sum_16;
        tbl_Aggregate_TD_5572054_output.setInt64(r, 24, _may_net3588);
        int64_t _jun_net3589 = (it.second)._jun_net3589_sum_17;
        tbl_Aggregate_TD_5572054_output.setInt64(r, 25, _jun_net3589);
        int64_t _jul_net3590 = (it.second)._jul_net3590_sum_18;
        tbl_Aggregate_TD_5572054_output.setInt64(r, 26, _jul_net3590);
        int64_t _aug_net3591 = (it.second)._aug_net3591_sum_19;
        tbl_Aggregate_TD_5572054_output.setInt64(r, 27, _aug_net3591);
        int64_t _sep_net3592 = (it.second)._sep_net3592_sum_20;
        tbl_Aggregate_TD_5572054_output.setInt64(r, 28, _sep_net3592);
        int64_t _oct_net3593 = (it.second)._oct_net3593_sum_21;
        tbl_Aggregate_TD_5572054_output.setInt64(r, 29, _oct_net3593);
        int64_t _nov_net3594 = (it.second)._nov_net3594_sum_22;
        tbl_Aggregate_TD_5572054_output.setInt64(r, 30, _nov_net3594);
        int64_t _dec_net3595 = (it.second)._dec_net3595_sum_23;
        tbl_Aggregate_TD_5572054_output.setInt64(r, 31, _dec_net3595);
        ++r;
    }
    tbl_Aggregate_TD_5572054_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_5572054_output #Row: " << tbl_Aggregate_TD_5572054_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_5195105_key {
    std::string _w_warehouse_name497;
    int32_t _w_warehouse_sq_ft498;
    std::string _w_city503;
    std::string _w_county504;
    std::string _w_state505;
    std::string _w_country507;
    int32_t _d_year126;
    bool operator==(const SW_Aggregate_TD_5195105_key& other) const { return (_w_warehouse_name497 == other._w_warehouse_name497) && (_w_warehouse_sq_ft498 == other._w_warehouse_sq_ft498) && (_w_city503 == other._w_city503) && (_w_county504 == other._w_county504) && (_w_state505 == other._w_state505) && (_w_country507 == other._w_country507) && (_d_year126 == other._d_year126); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_5195105_key> {
    std::size_t operator() (const SW_Aggregate_TD_5195105_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._w_warehouse_name497)) + (hash<int32_t>()(k._w_warehouse_sq_ft498)) + (hash<string>()(k._w_city503)) + (hash<string>()(k._w_county504)) + (hash<string>()(k._w_state505)) + (hash<string>()(k._w_country507)) + (hash<int32_t>()(k._d_year126));
    }
};
}
struct SW_Aggregate_TD_5195105_payload {
    std::string _ship_carriers3544;
    int32_t _year3545;
    int64_t _jan_sales3546_sum_0;
    int64_t _feb_sales3547_sum_1;
    int64_t _mar_sales3548_sum_2;
    int64_t _apr_sales3549_sum_3;
    int64_t _may_sales3550_sum_4;
    int64_t _jun_sales3551_sum_5;
    int64_t _jul_sales3552_sum_6;
    int64_t _aug_sales3553_sum_7;
    int64_t _sep_sales3554_sum_8;
    int64_t _oct_sales3555_sum_9;
    int64_t _nov_sales3556_sum_10;
    int64_t _dec_sales3557_sum_11;
    int64_t _jan_net3558_sum_12;
    int64_t _feb_net3559_sum_13;
    int64_t _mar_net3560_sum_14;
    int64_t _apr_net3561_sum_15;
    int64_t _may_net3562_sum_16;
    int64_t _jun_net3563_sum_17;
    int64_t _jul_net3564_sum_18;
    int64_t _aug_net3565_sum_19;
    int64_t _sep_net3566_sum_20;
    int64_t _oct_net3567_sum_21;
    int64_t _nov_net3568_sum_22;
    int64_t _dec_net3569_sum_23;
};
void SW_Aggregate_TD_5195105(Table &tbl_JOIN_INNER_TD_6461642_output, Table &tbl_Aggregate_TD_5195105_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(w_warehouse_name#497, w_warehouse_sq_ft#498, w_city#503, w_county#504, w_state#505, w_country#507, d_year#126, DHL,BARIAN AS ship_carriers#3544, d_year#126 AS year#3545, sum(CASE WHEN (d_moy#128 = 1) THEN CheckOverflow((promote_precision(cast(ws_ext_sales_price#752 as decimal(12,2))) * promote_precision(cast(cast(ws_quantity#747 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS jan_sales#3546, sum(CASE WHEN (d_moy#128 = 2) THEN CheckOverflow((promote_precision(cast(ws_ext_sales_price#752 as decimal(12,2))) * promote_precision(cast(cast(ws_quantity#747 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS feb_sales#3547, sum(CASE WHEN (d_moy#128 = 3) THEN CheckOverflow((promote_precision(cast(ws_ext_sales_price#752 as decimal(12,2))) * promote_precision(cast(cast(ws_quantity#747 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS mar_sales#3548, sum(CASE WHEN (d_moy#128 = 4) THEN CheckOverflow((promote_precision(cast(ws_ext_sales_price#752 as decimal(12,2))) * promote_precision(cast(cast(ws_quantity#747 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS apr_sales#3549, sum(CASE WHEN (d_moy#128 = 5) THEN CheckOverflow((promote_precision(cast(ws_ext_sales_price#752 as decimal(12,2))) * promote_precision(cast(cast(ws_quantity#747 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS may_sales#3550, sum(CASE WHEN (d_moy#128 = 6) THEN CheckOverflow((promote_precision(cast(ws_ext_sales_price#752 as decimal(12,2))) * promote_precision(cast(cast(ws_quantity#747 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS jun_sales#3551, sum(CASE WHEN (d_moy#128 = 7) THEN CheckOverflow((promote_precision(cast(ws_ext_sales_price#752 as decimal(12,2))) * promote_precision(cast(cast(ws_quantity#747 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS jul_sales#3552, sum(CASE WHEN (d_moy#128 = 8) THEN CheckOverflow((promote_precision(cast(ws_ext_sales_price#752 as decimal(12,2))) * promote_precision(cast(cast(ws_quantity#747 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS aug_sales#3553, sum(CASE WHEN (d_moy#128 = 9) THEN CheckOverflow((promote_precision(cast(ws_ext_sales_price#752 as decimal(12,2))) * promote_precision(cast(cast(ws_quantity#747 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS sep_sales#3554, sum(CASE WHEN (d_moy#128 = 10) THEN CheckOverflow((promote_precision(cast(ws_ext_sales_price#752 as decimal(12,2))) * promote_precision(cast(cast(ws_quantity#747 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS oct_sales#3555, sum(CASE WHEN (d_moy#128 = 11) THEN CheckOverflow((promote_precision(cast(ws_ext_sales_price#752 as decimal(12,2))) * promote_precision(cast(cast(ws_quantity#747 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS nov_sales#3556, sum(CASE WHEN (d_moy#128 = 12) THEN CheckOverflow((promote_precision(cast(ws_ext_sales_price#752 as decimal(12,2))) * promote_precision(cast(cast(ws_quantity#747 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS dec_sales#3557, sum(CASE WHEN (d_moy#128 = 1) THEN CheckOverflow((promote_precision(cast(ws_net_paid#758 as decimal(12,2))) * promote_precision(cast(cast(ws_quantity#747 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS jan_net#3558, sum(CASE WHEN (d_moy#128 = 2) THEN CheckOverflow((promote_precision(cast(ws_net_paid#758 as decimal(12,2))) * promote_precision(cast(cast(ws_quantity#747 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS feb_net#3559, sum(CASE WHEN (d_moy#128 = 3) THEN CheckOverflow((promote_precision(cast(ws_net_paid#758 as decimal(12,2))) * promote_precision(cast(cast(ws_quantity#747 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS mar_net#3560, sum(CASE WHEN (d_moy#128 = 4) THEN CheckOverflow((promote_precision(cast(ws_net_paid#758 as decimal(12,2))) * promote_precision(cast(cast(ws_quantity#747 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS apr_net#3561, sum(CASE WHEN (d_moy#128 = 5) THEN CheckOverflow((promote_precision(cast(ws_net_paid#758 as decimal(12,2))) * promote_precision(cast(cast(ws_quantity#747 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS may_net#3562, sum(CASE WHEN (d_moy#128 = 6) THEN CheckOverflow((promote_precision(cast(ws_net_paid#758 as decimal(12,2))) * promote_precision(cast(cast(ws_quantity#747 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS jun_net#3563, sum(CASE WHEN (d_moy#128 = 7) THEN CheckOverflow((promote_precision(cast(ws_net_paid#758 as decimal(12,2))) * promote_precision(cast(cast(ws_quantity#747 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS jul_net#3564, sum(CASE WHEN (d_moy#128 = 8) THEN CheckOverflow((promote_precision(cast(ws_net_paid#758 as decimal(12,2))) * promote_precision(cast(cast(ws_quantity#747 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS aug_net#3565, sum(CASE WHEN (d_moy#128 = 9) THEN CheckOverflow((promote_precision(cast(ws_net_paid#758 as decimal(12,2))) * promote_precision(cast(cast(ws_quantity#747 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS sep_net#3566, sum(CASE WHEN (d_moy#128 = 10) THEN CheckOverflow((promote_precision(cast(ws_net_paid#758 as decimal(12,2))) * promote_precision(cast(cast(ws_quantity#747 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS oct_net#3567, sum(CASE WHEN (d_moy#128 = 11) THEN CheckOverflow((promote_precision(cast(ws_net_paid#758 as decimal(12,2))) * promote_precision(cast(cast(ws_quantity#747 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS nov_net#3568, sum(CASE WHEN (d_moy#128 = 12) THEN CheckOverflow((promote_precision(cast(ws_net_paid#758 as decimal(12,2))) * promote_precision(cast(cast(ws_quantity#747 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true) ELSE 0.00 END) AS dec_net#3569)
    // Input: ListBuffer(ws_quantity#747, ws_ext_sales_price#752, ws_net_paid#758, w_warehouse_name#497, w_warehouse_sq_ft#498, w_city#503, w_county#504, w_state#505, w_country#507, d_year#126, d_moy#128)
    // Output: ListBuffer(w_warehouse_name#497, w_warehouse_sq_ft#498, w_city#503, w_county#504, w_state#505, w_country#507, ship_carriers#3544, year#3545, jan_sales#3546, feb_sales#3547, mar_sales#3548, apr_sales#3549, may_sales#3550, jun_sales#3551, jul_sales#3552, aug_sales#3553, sep_sales#3554, oct_sales#3555, nov_sales#3556, dec_sales#3557, jan_net#3558, feb_net#3559, mar_net#3560, apr_net#3561, may_net#3562, jun_net#3563, jul_net#3564, aug_net#3565, sep_net#3566, oct_net#3567, nov_net#3568, dec_net#3569)
    std::unordered_map<SW_Aggregate_TD_5195105_key, SW_Aggregate_TD_5195105_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_6461642_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_6461642_output.getInt32(i, 0);
        int64_t _ws_ext_sales_price752 = tbl_JOIN_INNER_TD_6461642_output.getInt64(i, 1);
        int64_t _ws_net_paid758 = tbl_JOIN_INNER_TD_6461642_output.getInt64(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497 = tbl_JOIN_INNER_TD_6461642_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        int32_t _w_warehouse_sq_ft498 = tbl_JOIN_INNER_TD_6461642_output.getInt32(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _w_city503 = tbl_JOIN_INNER_TD_6461642_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _w_county504 = tbl_JOIN_INNER_TD_6461642_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        std::array<char, TPCDS_READ_MAX + 1> _w_state505 = tbl_JOIN_INNER_TD_6461642_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
        std::array<char, TPCDS_READ_MAX + 1> _w_country507 = tbl_JOIN_INNER_TD_6461642_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
        int32_t _d_year126 = tbl_JOIN_INNER_TD_6461642_output.getInt32(i, 9);
        int32_t _d_moy128 = tbl_JOIN_INNER_TD_6461642_output.getInt32(i, 10);
        SW_Aggregate_TD_5195105_key k{std::string(_w_warehouse_name497.data()), _w_warehouse_sq_ft498, std::string(_w_city503.data()), std::string(_w_county504.data()), std::string(_w_state505.data()), std::string(_w_country507.data()), _d_year126};
        std::string _ship_carriers3544 = "DHL,BARIAN";
        int32_t _year3545 = _d_year126;
        int64_t _jan_sales3546_sum_0 = (_d_moy128 == 1) ? (_ws_ext_sales_price752 * _ws_quantity747) : 0.00;
        int64_t _feb_sales3547_sum_1 = (_d_moy128 == 2) ? (_ws_ext_sales_price752 * _ws_quantity747) : 0.00;
        int64_t _mar_sales3548_sum_2 = (_d_moy128 == 3) ? (_ws_ext_sales_price752 * _ws_quantity747) : 0.00;
        int64_t _apr_sales3549_sum_3 = (_d_moy128 == 4) ? (_ws_ext_sales_price752 * _ws_quantity747) : 0.00;
        int64_t _may_sales3550_sum_4 = (_d_moy128 == 5) ? (_ws_ext_sales_price752 * _ws_quantity747) : 0.00;
        int64_t _jun_sales3551_sum_5 = (_d_moy128 == 6) ? (_ws_ext_sales_price752 * _ws_quantity747) : 0.00;
        int64_t _jul_sales3552_sum_6 = (_d_moy128 == 7) ? (_ws_ext_sales_price752 * _ws_quantity747) : 0.00;
        int64_t _aug_sales3553_sum_7 = (_d_moy128 == 8) ? (_ws_ext_sales_price752 * _ws_quantity747) : 0.00;
        int64_t _sep_sales3554_sum_8 = (_d_moy128 == 9) ? (_ws_ext_sales_price752 * _ws_quantity747) : 0.00;
        int64_t _oct_sales3555_sum_9 = (_d_moy128 == 10) ? (_ws_ext_sales_price752 * _ws_quantity747) : 0.00;
        int64_t _nov_sales3556_sum_10 = (_d_moy128 == 11) ? (_ws_ext_sales_price752 * _ws_quantity747) : 0.00;
        int64_t _dec_sales3557_sum_11 = (_d_moy128 == 12) ? (_ws_ext_sales_price752 * _ws_quantity747) : 0.00;
        int64_t _jan_net3558_sum_12 = (_d_moy128 == 1) ? (_ws_net_paid758 * _ws_quantity747) : 0.00;
        int64_t _feb_net3559_sum_13 = (_d_moy128 == 2) ? (_ws_net_paid758 * _ws_quantity747) : 0.00;
        int64_t _mar_net3560_sum_14 = (_d_moy128 == 3) ? (_ws_net_paid758 * _ws_quantity747) : 0.00;
        int64_t _apr_net3561_sum_15 = (_d_moy128 == 4) ? (_ws_net_paid758 * _ws_quantity747) : 0.00;
        int64_t _may_net3562_sum_16 = (_d_moy128 == 5) ? (_ws_net_paid758 * _ws_quantity747) : 0.00;
        int64_t _jun_net3563_sum_17 = (_d_moy128 == 6) ? (_ws_net_paid758 * _ws_quantity747) : 0.00;
        int64_t _jul_net3564_sum_18 = (_d_moy128 == 7) ? (_ws_net_paid758 * _ws_quantity747) : 0.00;
        int64_t _aug_net3565_sum_19 = (_d_moy128 == 8) ? (_ws_net_paid758 * _ws_quantity747) : 0.00;
        int64_t _sep_net3566_sum_20 = (_d_moy128 == 9) ? (_ws_net_paid758 * _ws_quantity747) : 0.00;
        int64_t _oct_net3567_sum_21 = (_d_moy128 == 10) ? (_ws_net_paid758 * _ws_quantity747) : 0.00;
        int64_t _nov_net3568_sum_22 = (_d_moy128 == 11) ? (_ws_net_paid758 * _ws_quantity747) : 0.00;
        int64_t _dec_net3569_sum_23 = (_d_moy128 == 12) ? (_ws_net_paid758 * _ws_quantity747) : 0.00;
        SW_Aggregate_TD_5195105_payload p{std::string(_ship_carriers3544.data()), _year3545, _jan_sales3546_sum_0, _feb_sales3547_sum_1, _mar_sales3548_sum_2, _apr_sales3549_sum_3, _may_sales3550_sum_4, _jun_sales3551_sum_5, _jul_sales3552_sum_6, _aug_sales3553_sum_7, _sep_sales3554_sum_8, _oct_sales3555_sum_9, _nov_sales3556_sum_10, _dec_sales3557_sum_11, _jan_net3558_sum_12, _feb_net3559_sum_13, _mar_net3560_sum_14, _apr_net3561_sum_15, _may_net3562_sum_16, _jun_net3563_sum_17, _jul_net3564_sum_18, _aug_net3565_sum_19, _sep_net3566_sum_20, _oct_net3567_sum_21, _nov_net3568_sum_22, _dec_net3569_sum_23};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._jan_sales3546_sum_0 + _jan_sales3546_sum_0;
            p._jan_sales3546_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._feb_sales3547_sum_1 + _feb_sales3547_sum_1;
            p._feb_sales3547_sum_1 = sum_1;
            int64_t sum_2 = (it->second)._mar_sales3548_sum_2 + _mar_sales3548_sum_2;
            p._mar_sales3548_sum_2 = sum_2;
            int64_t sum_3 = (it->second)._apr_sales3549_sum_3 + _apr_sales3549_sum_3;
            p._apr_sales3549_sum_3 = sum_3;
            int64_t sum_4 = (it->second)._may_sales3550_sum_4 + _may_sales3550_sum_4;
            p._may_sales3550_sum_4 = sum_4;
            int64_t sum_5 = (it->second)._jun_sales3551_sum_5 + _jun_sales3551_sum_5;
            p._jun_sales3551_sum_5 = sum_5;
            int64_t sum_6 = (it->second)._jul_sales3552_sum_6 + _jul_sales3552_sum_6;
            p._jul_sales3552_sum_6 = sum_6;
            int64_t sum_7 = (it->second)._aug_sales3553_sum_7 + _aug_sales3553_sum_7;
            p._aug_sales3553_sum_7 = sum_7;
            int64_t sum_8 = (it->second)._sep_sales3554_sum_8 + _sep_sales3554_sum_8;
            p._sep_sales3554_sum_8 = sum_8;
            int64_t sum_9 = (it->second)._oct_sales3555_sum_9 + _oct_sales3555_sum_9;
            p._oct_sales3555_sum_9 = sum_9;
            int64_t sum_10 = (it->second)._nov_sales3556_sum_10 + _nov_sales3556_sum_10;
            p._nov_sales3556_sum_10 = sum_10;
            int64_t sum_11 = (it->second)._dec_sales3557_sum_11 + _dec_sales3557_sum_11;
            p._dec_sales3557_sum_11 = sum_11;
            int64_t sum_12 = (it->second)._jan_net3558_sum_12 + _jan_net3558_sum_12;
            p._jan_net3558_sum_12 = sum_12;
            int64_t sum_13 = (it->second)._feb_net3559_sum_13 + _feb_net3559_sum_13;
            p._feb_net3559_sum_13 = sum_13;
            int64_t sum_14 = (it->second)._mar_net3560_sum_14 + _mar_net3560_sum_14;
            p._mar_net3560_sum_14 = sum_14;
            int64_t sum_15 = (it->second)._apr_net3561_sum_15 + _apr_net3561_sum_15;
            p._apr_net3561_sum_15 = sum_15;
            int64_t sum_16 = (it->second)._may_net3562_sum_16 + _may_net3562_sum_16;
            p._may_net3562_sum_16 = sum_16;
            int64_t sum_17 = (it->second)._jun_net3563_sum_17 + _jun_net3563_sum_17;
            p._jun_net3563_sum_17 = sum_17;
            int64_t sum_18 = (it->second)._jul_net3564_sum_18 + _jul_net3564_sum_18;
            p._jul_net3564_sum_18 = sum_18;
            int64_t sum_19 = (it->second)._aug_net3565_sum_19 + _aug_net3565_sum_19;
            p._aug_net3565_sum_19 = sum_19;
            int64_t sum_20 = (it->second)._sep_net3566_sum_20 + _sep_net3566_sum_20;
            p._sep_net3566_sum_20 = sum_20;
            int64_t sum_21 = (it->second)._oct_net3567_sum_21 + _oct_net3567_sum_21;
            p._oct_net3567_sum_21 = sum_21;
            int64_t sum_22 = (it->second)._nov_net3568_sum_22 + _nov_net3568_sum_22;
            p._nov_net3568_sum_22 = sum_22;
            int64_t sum_23 = (it->second)._dec_net3569_sum_23 + _dec_net3569_sum_23;
            p._dec_net3569_sum_23 = sum_23;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497{};
        memcpy(_w_warehouse_name497.data(), ((it.first)._w_warehouse_name497).data(), ((it.first)._w_warehouse_name497).length());
        tbl_Aggregate_TD_5195105_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _w_warehouse_name497);
        tbl_Aggregate_TD_5195105_output.setInt32(r, 1, (it.first)._w_warehouse_sq_ft498);
        std::array<char, TPCDS_READ_MAX + 1> _w_city503{};
        memcpy(_w_city503.data(), ((it.first)._w_city503).data(), ((it.first)._w_city503).length());
        tbl_Aggregate_TD_5195105_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _w_city503);
        std::array<char, TPCDS_READ_MAX + 1> _w_county504{};
        memcpy(_w_county504.data(), ((it.first)._w_county504).data(), ((it.first)._w_county504).length());
        tbl_Aggregate_TD_5195105_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _w_county504);
        std::array<char, TPCDS_READ_MAX + 1> _w_state505{};
        memcpy(_w_state505.data(), ((it.first)._w_state505).data(), ((it.first)._w_state505).length());
        tbl_Aggregate_TD_5195105_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _w_state505);
        std::array<char, TPCDS_READ_MAX + 1> _w_country507{};
        memcpy(_w_country507.data(), ((it.first)._w_country507).data(), ((it.first)._w_country507).length());
        tbl_Aggregate_TD_5195105_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _w_country507);
        // _d_year126 not required in the output table
        std::array<char, TPCDS_READ_MAX + 1> _ship_carriers3544_n{};
        memcpy(_ship_carriers3544_n.data(), (it.second)._ship_carriers3544.data(), (it.second)._ship_carriers3544.length());
        tbl_Aggregate_TD_5195105_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _ship_carriers3544_n);
        tbl_Aggregate_TD_5195105_output.setInt32(r, 7, (it.second)._year3545);
        int64_t _jan_sales3546 = (it.second)._jan_sales3546_sum_0;
        tbl_Aggregate_TD_5195105_output.setInt64(r, 8, _jan_sales3546);
        int64_t _feb_sales3547 = (it.second)._feb_sales3547_sum_1;
        tbl_Aggregate_TD_5195105_output.setInt64(r, 9, _feb_sales3547);
        int64_t _mar_sales3548 = (it.second)._mar_sales3548_sum_2;
        tbl_Aggregate_TD_5195105_output.setInt64(r, 10, _mar_sales3548);
        int64_t _apr_sales3549 = (it.second)._apr_sales3549_sum_3;
        tbl_Aggregate_TD_5195105_output.setInt64(r, 11, _apr_sales3549);
        int64_t _may_sales3550 = (it.second)._may_sales3550_sum_4;
        tbl_Aggregate_TD_5195105_output.setInt64(r, 12, _may_sales3550);
        int64_t _jun_sales3551 = (it.second)._jun_sales3551_sum_5;
        tbl_Aggregate_TD_5195105_output.setInt64(r, 13, _jun_sales3551);
        int64_t _jul_sales3552 = (it.second)._jul_sales3552_sum_6;
        tbl_Aggregate_TD_5195105_output.setInt64(r, 14, _jul_sales3552);
        int64_t _aug_sales3553 = (it.second)._aug_sales3553_sum_7;
        tbl_Aggregate_TD_5195105_output.setInt64(r, 15, _aug_sales3553);
        int64_t _sep_sales3554 = (it.second)._sep_sales3554_sum_8;
        tbl_Aggregate_TD_5195105_output.setInt64(r, 16, _sep_sales3554);
        int64_t _oct_sales3555 = (it.second)._oct_sales3555_sum_9;
        tbl_Aggregate_TD_5195105_output.setInt64(r, 17, _oct_sales3555);
        int64_t _nov_sales3556 = (it.second)._nov_sales3556_sum_10;
        tbl_Aggregate_TD_5195105_output.setInt64(r, 18, _nov_sales3556);
        int64_t _dec_sales3557 = (it.second)._dec_sales3557_sum_11;
        tbl_Aggregate_TD_5195105_output.setInt64(r, 19, _dec_sales3557);
        int64_t _jan_net3558 = (it.second)._jan_net3558_sum_12;
        tbl_Aggregate_TD_5195105_output.setInt64(r, 20, _jan_net3558);
        int64_t _feb_net3559 = (it.second)._feb_net3559_sum_13;
        tbl_Aggregate_TD_5195105_output.setInt64(r, 21, _feb_net3559);
        int64_t _mar_net3560 = (it.second)._mar_net3560_sum_14;
        tbl_Aggregate_TD_5195105_output.setInt64(r, 22, _mar_net3560);
        int64_t _apr_net3561 = (it.second)._apr_net3561_sum_15;
        tbl_Aggregate_TD_5195105_output.setInt64(r, 23, _apr_net3561);
        int64_t _may_net3562 = (it.second)._may_net3562_sum_16;
        tbl_Aggregate_TD_5195105_output.setInt64(r, 24, _may_net3562);
        int64_t _jun_net3563 = (it.second)._jun_net3563_sum_17;
        tbl_Aggregate_TD_5195105_output.setInt64(r, 25, _jun_net3563);
        int64_t _jul_net3564 = (it.second)._jul_net3564_sum_18;
        tbl_Aggregate_TD_5195105_output.setInt64(r, 26, _jul_net3564);
        int64_t _aug_net3565 = (it.second)._aug_net3565_sum_19;
        tbl_Aggregate_TD_5195105_output.setInt64(r, 27, _aug_net3565);
        int64_t _sep_net3566 = (it.second)._sep_net3566_sum_20;
        tbl_Aggregate_TD_5195105_output.setInt64(r, 28, _sep_net3566);
        int64_t _oct_net3567 = (it.second)._oct_net3567_sum_21;
        tbl_Aggregate_TD_5195105_output.setInt64(r, 29, _oct_net3567);
        int64_t _nov_net3568 = (it.second)._nov_net3568_sum_22;
        tbl_Aggregate_TD_5195105_output.setInt64(r, 30, _nov_net3568);
        int64_t _dec_net3569 = (it.second)._dec_net3569_sum_23;
        tbl_Aggregate_TD_5195105_output.setInt64(r, 31, _dec_net3569);
        ++r;
    }
    tbl_Aggregate_TD_5195105_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_5195105_output #Row: " << tbl_Aggregate_TD_5195105_output.getNumRow() << std::endl;
}

void SW_Union_TD_4183185(Table &tbl_Aggregate_TD_5195105_output, Table &tbl_Aggregate_TD_5572054_output, Table &tbl_Union_TD_4183185_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Union
    // Operation: ListBuffer(List(UNION))
    // Output Table: ListBuffer(w_warehouse_name#497, w_warehouse_sq_ft#498, w_city#503, w_county#504, w_state#505, w_country#507, ship_carriers#3544, year#3545, jan_sales#3546, feb_sales#3547, mar_sales#3548, apr_sales#3549, may_sales#3550, jun_sales#3551, jul_sales#3552, aug_sales#3553, sep_sales#3554, oct_sales#3555, nov_sales#3556, dec_sales#3557, jan_net#3558, feb_net#3559, mar_net#3560, apr_net#3561, may_net#3562, jun_net#3563, jul_net#3564, aug_net#3565, sep_net#3566, oct_net#3567, nov_net#3568, dec_net#3569)
    int r = 0;
    int row0 = tbl_Aggregate_TD_5195105_output.getNumRow();
    for (int i = 0; i < row0; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_Union_TD_4183185_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_Union_TD_4183185_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _w_warehouse_name497_n);
        tbl_Union_TD_4183185_output.setInt32(r, 1, tbl_Aggregate_TD_5195105_output.getInt32(i, 1));
        std::array<char, TPCDS_READ_MAX + 1> _w_city503_n = tbl_Union_TD_4183185_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_Union_TD_4183185_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _w_city503_n);
        std::array<char, TPCDS_READ_MAX + 1> _w_county504_n = tbl_Union_TD_4183185_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_Union_TD_4183185_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _w_county504_n);
        std::array<char, TPCDS_READ_MAX + 1> _w_state505_n = tbl_Union_TD_4183185_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        tbl_Union_TD_4183185_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _w_state505_n);
        std::array<char, TPCDS_READ_MAX + 1> _w_country507_n = tbl_Union_TD_4183185_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        tbl_Union_TD_4183185_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _w_country507_n);
        std::array<char, TPCDS_READ_MAX + 1> _ship_carriers3544_n = tbl_Union_TD_4183185_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        tbl_Union_TD_4183185_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _ship_carriers3544_n);
        tbl_Union_TD_4183185_output.setInt32(r, 7, tbl_Aggregate_TD_5195105_output.getInt32(i, 7));
        tbl_Union_TD_4183185_output.setInt32(r, 8, tbl_Aggregate_TD_5195105_output.getInt64(i, 8));
        tbl_Union_TD_4183185_output.setInt32(r, 9, tbl_Aggregate_TD_5195105_output.getInt64(i, 9));
        tbl_Union_TD_4183185_output.setInt32(r, 10, tbl_Aggregate_TD_5195105_output.getInt64(i, 10));
        tbl_Union_TD_4183185_output.setInt32(r, 11, tbl_Aggregate_TD_5195105_output.getInt64(i, 11));
        tbl_Union_TD_4183185_output.setInt32(r, 12, tbl_Aggregate_TD_5195105_output.getInt64(i, 12));
        tbl_Union_TD_4183185_output.setInt32(r, 13, tbl_Aggregate_TD_5195105_output.getInt64(i, 13));
        tbl_Union_TD_4183185_output.setInt32(r, 14, tbl_Aggregate_TD_5195105_output.getInt64(i, 14));
        tbl_Union_TD_4183185_output.setInt32(r, 15, tbl_Aggregate_TD_5195105_output.getInt64(i, 15));
        tbl_Union_TD_4183185_output.setInt32(r, 16, tbl_Aggregate_TD_5195105_output.getInt64(i, 16));
        tbl_Union_TD_4183185_output.setInt32(r, 17, tbl_Aggregate_TD_5195105_output.getInt64(i, 17));
        tbl_Union_TD_4183185_output.setInt32(r, 18, tbl_Aggregate_TD_5195105_output.getInt64(i, 18));
        tbl_Union_TD_4183185_output.setInt32(r, 19, tbl_Aggregate_TD_5195105_output.getInt64(i, 19));
        tbl_Union_TD_4183185_output.setInt32(r, 20, tbl_Aggregate_TD_5195105_output.getInt64(i, 20));
        tbl_Union_TD_4183185_output.setInt32(r, 21, tbl_Aggregate_TD_5195105_output.getInt64(i, 21));
        tbl_Union_TD_4183185_output.setInt32(r, 22, tbl_Aggregate_TD_5195105_output.getInt64(i, 22));
        tbl_Union_TD_4183185_output.setInt32(r, 23, tbl_Aggregate_TD_5195105_output.getInt64(i, 23));
        tbl_Union_TD_4183185_output.setInt32(r, 24, tbl_Aggregate_TD_5195105_output.getInt64(i, 24));
        tbl_Union_TD_4183185_output.setInt32(r, 25, tbl_Aggregate_TD_5195105_output.getInt64(i, 25));
        tbl_Union_TD_4183185_output.setInt32(r, 26, tbl_Aggregate_TD_5195105_output.getInt64(i, 26));
        tbl_Union_TD_4183185_output.setInt32(r, 27, tbl_Aggregate_TD_5195105_output.getInt64(i, 27));
        tbl_Union_TD_4183185_output.setInt32(r, 28, tbl_Aggregate_TD_5195105_output.getInt64(i, 28));
        tbl_Union_TD_4183185_output.setInt32(r, 29, tbl_Aggregate_TD_5195105_output.getInt64(i, 29));
        tbl_Union_TD_4183185_output.setInt32(r, 30, tbl_Aggregate_TD_5195105_output.getInt64(i, 30));
        tbl_Union_TD_4183185_output.setInt32(r, 31, tbl_Aggregate_TD_5195105_output.getInt64(i, 31));
        ++r;
    }
    int row1 = tbl_Aggregate_TD_5572054_output.getNumRow();
    for (int i = 0; i < row1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name3634_n = tbl_Union_TD_4183185_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_Union_TD_4183185_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _w_warehouse_name3634_n);
        tbl_Union_TD_4183185_output.setInt32(r, 1, tbl_Aggregate_TD_5572054_output.getInt32(i, 1));
        std::array<char, TPCDS_READ_MAX + 1> _w_city3640_n = tbl_Union_TD_4183185_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_Union_TD_4183185_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _w_city3640_n);
        std::array<char, TPCDS_READ_MAX + 1> _w_county3641_n = tbl_Union_TD_4183185_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_Union_TD_4183185_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _w_county3641_n);
        std::array<char, TPCDS_READ_MAX + 1> _w_state3642_n = tbl_Union_TD_4183185_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        tbl_Union_TD_4183185_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _w_state3642_n);
        std::array<char, TPCDS_READ_MAX + 1> _w_country3644_n = tbl_Union_TD_4183185_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        tbl_Union_TD_4183185_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _w_country3644_n);
        std::array<char, TPCDS_READ_MAX + 1> _ship_carriers3570_n = tbl_Union_TD_4183185_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        tbl_Union_TD_4183185_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _ship_carriers3570_n);
        tbl_Union_TD_4183185_output.setInt32(r, 7, tbl_Aggregate_TD_5572054_output.getInt32(i, 7));
        tbl_Union_TD_4183185_output.setInt32(r, 8, tbl_Aggregate_TD_5572054_output.getInt64(i, 8));
        tbl_Union_TD_4183185_output.setInt32(r, 9, tbl_Aggregate_TD_5572054_output.getInt64(i, 9));
        tbl_Union_TD_4183185_output.setInt32(r, 10, tbl_Aggregate_TD_5572054_output.getInt64(i, 10));
        tbl_Union_TD_4183185_output.setInt32(r, 11, tbl_Aggregate_TD_5572054_output.getInt64(i, 11));
        tbl_Union_TD_4183185_output.setInt32(r, 12, tbl_Aggregate_TD_5572054_output.getInt64(i, 12));
        tbl_Union_TD_4183185_output.setInt32(r, 13, tbl_Aggregate_TD_5572054_output.getInt64(i, 13));
        tbl_Union_TD_4183185_output.setInt32(r, 14, tbl_Aggregate_TD_5572054_output.getInt64(i, 14));
        tbl_Union_TD_4183185_output.setInt32(r, 15, tbl_Aggregate_TD_5572054_output.getInt64(i, 15));
        tbl_Union_TD_4183185_output.setInt32(r, 16, tbl_Aggregate_TD_5572054_output.getInt64(i, 16));
        tbl_Union_TD_4183185_output.setInt32(r, 17, tbl_Aggregate_TD_5572054_output.getInt64(i, 17));
        tbl_Union_TD_4183185_output.setInt32(r, 18, tbl_Aggregate_TD_5572054_output.getInt64(i, 18));
        tbl_Union_TD_4183185_output.setInt32(r, 19, tbl_Aggregate_TD_5572054_output.getInt64(i, 19));
        tbl_Union_TD_4183185_output.setInt32(r, 20, tbl_Aggregate_TD_5572054_output.getInt64(i, 20));
        tbl_Union_TD_4183185_output.setInt32(r, 21, tbl_Aggregate_TD_5572054_output.getInt64(i, 21));
        tbl_Union_TD_4183185_output.setInt32(r, 22, tbl_Aggregate_TD_5572054_output.getInt64(i, 22));
        tbl_Union_TD_4183185_output.setInt32(r, 23, tbl_Aggregate_TD_5572054_output.getInt64(i, 23));
        tbl_Union_TD_4183185_output.setInt32(r, 24, tbl_Aggregate_TD_5572054_output.getInt64(i, 24));
        tbl_Union_TD_4183185_output.setInt32(r, 25, tbl_Aggregate_TD_5572054_output.getInt64(i, 25));
        tbl_Union_TD_4183185_output.setInt32(r, 26, tbl_Aggregate_TD_5572054_output.getInt64(i, 26));
        tbl_Union_TD_4183185_output.setInt32(r, 27, tbl_Aggregate_TD_5572054_output.getInt64(i, 27));
        tbl_Union_TD_4183185_output.setInt32(r, 28, tbl_Aggregate_TD_5572054_output.getInt64(i, 28));
        tbl_Union_TD_4183185_output.setInt32(r, 29, tbl_Aggregate_TD_5572054_output.getInt64(i, 29));
        tbl_Union_TD_4183185_output.setInt32(r, 30, tbl_Aggregate_TD_5572054_output.getInt64(i, 30));
        tbl_Union_TD_4183185_output.setInt32(r, 31, tbl_Aggregate_TD_5572054_output.getInt64(i, 31));
        ++r;
    }
    tbl_Union_TD_4183185_output.setNumRow(r);
    std::cout << "tbl_Union_TD_4183185_output #Row: " << tbl_Union_TD_4183185_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_3248653_key {
    std::string _w_warehouse_name497;
    int32_t _w_warehouse_sq_ft498;
    std::string _w_city503;
    std::string _w_county504;
    std::string _w_state505;
    std::string _w_country507;
    std::string _ship_carriers3544;
    int32_t _year3545;
    bool operator==(const SW_Aggregate_TD_3248653_key& other) const { return (_w_warehouse_name497 == other._w_warehouse_name497) && (_w_warehouse_sq_ft498 == other._w_warehouse_sq_ft498) && (_w_city503 == other._w_city503) && (_w_county504 == other._w_county504) && (_w_state505 == other._w_state505) && (_w_country507 == other._w_country507) && (_ship_carriers3544 == other._ship_carriers3544) && (_year3545 == other._year3545); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_3248653_key> {
    std::size_t operator() (const SW_Aggregate_TD_3248653_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._w_warehouse_name497)) + (hash<int32_t>()(k._w_warehouse_sq_ft498)) + (hash<string>()(k._w_city503)) + (hash<string>()(k._w_county504)) + (hash<string>()(k._w_state505)) + (hash<string>()(k._w_country507)) + (hash<string>()(k._ship_carriers3544)) + (hash<int32_t>()(k._year3545));
    }
};
}
struct SW_Aggregate_TD_3248653_payload {
    int64_t _jan_sales3596_sum_0;
    int64_t _feb_sales3597_sum_1;
    int64_t _mar_sales3598_sum_2;
    int64_t _apr_sales3599_sum_3;
    int64_t _may_sales3600_sum_4;
    int64_t _jun_sales3601_sum_5;
    int64_t _jul_sales3602_sum_6;
    int64_t _aug_sales3603_sum_7;
    int64_t _sep_sales3604_sum_8;
    int64_t _oct_sales3605_sum_9;
    int64_t _nov_sales3606_sum_10;
    int64_t _dec_sales3607_sum_11;
    int64_t _jan_sales_per_sq_foot3608_sum_12;
    int64_t _feb_sales_per_sq_foot3609_sum_13;
    int64_t _mar_sales_per_sq_foot3610_sum_14;
    int64_t _apr_sales_per_sq_foot3611_sum_15;
    int64_t _may_sales_per_sq_foot3612_sum_16;
    int64_t _jun_sales_per_sq_foot3613_sum_17;
    int64_t _jul_sales_per_sq_foot3614_sum_18;
    int64_t _aug_sales_per_sq_foot3615_sum_19;
    int64_t _sep_sales_per_sq_foot3616_sum_20;
    int64_t _oct_sales_per_sq_foot3617_sum_21;
    int64_t _nov_sales_per_sq_foot3618_sum_22;
    int64_t _dec_sales_per_sq_foot3619_sum_23;
    int64_t _jan_net3620_sum_24;
    int64_t _feb_net3621_sum_25;
    int64_t _mar_net3622_sum_26;
    int64_t _apr_net3623_sum_27;
    int64_t _may_net3624_sum_28;
    int64_t _jun_net3625_sum_29;
    int64_t _jul_net3626_sum_30;
    int64_t _aug_net3627_sum_31;
    int64_t _sep_net3628_sum_32;
    int64_t _oct_net3629_sum_33;
    int64_t _nov_net3630_sum_34;
    int64_t _dec_net3631_sum_35;
};
void SW_Aggregate_TD_3248653(Table &tbl_Union_TD_4183185_output, Table &tbl_Aggregate_TD_3248653_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(w_warehouse_name#497, w_warehouse_sq_ft#498, w_city#503, w_county#504, w_state#505, w_country#507, ship_carriers#3544, year#3545, sum(jan_sales#3546) AS jan_sales#3596, sum(feb_sales#3547) AS feb_sales#3597, sum(mar_sales#3548) AS mar_sales#3598, sum(apr_sales#3549) AS apr_sales#3599, sum(may_sales#3550) AS may_sales#3600, sum(jun_sales#3551) AS jun_sales#3601, sum(jul_sales#3552) AS jul_sales#3602, sum(aug_sales#3553) AS aug_sales#3603, sum(sep_sales#3554) AS sep_sales#3604, sum(oct_sales#3555) AS oct_sales#3605, sum(nov_sales#3556) AS nov_sales#3606, sum(dec_sales#3557) AS dec_sales#3607, sum(CheckOverflow((promote_precision(jan_sales#3546) / promote_precision(cast(cast(w_warehouse_sq_ft#498 as decimal(10,0)) as decimal(28,2)))), DecimalType(38,12), true)) AS jan_sales_per_sq_foot#3608, sum(CheckOverflow((promote_precision(feb_sales#3547) / promote_precision(cast(cast(w_warehouse_sq_ft#498 as decimal(10,0)) as decimal(28,2)))), DecimalType(38,12), true)) AS feb_sales_per_sq_foot#3609, sum(CheckOverflow((promote_precision(mar_sales#3548) / promote_precision(cast(cast(w_warehouse_sq_ft#498 as decimal(10,0)) as decimal(28,2)))), DecimalType(38,12), true)) AS mar_sales_per_sq_foot#3610, sum(CheckOverflow((promote_precision(apr_sales#3549) / promote_precision(cast(cast(w_warehouse_sq_ft#498 as decimal(10,0)) as decimal(28,2)))), DecimalType(38,12), true)) AS apr_sales_per_sq_foot#3611, sum(CheckOverflow((promote_precision(may_sales#3550) / promote_precision(cast(cast(w_warehouse_sq_ft#498 as decimal(10,0)) as decimal(28,2)))), DecimalType(38,12), true)) AS may_sales_per_sq_foot#3612, sum(CheckOverflow((promote_precision(jun_sales#3551) / promote_precision(cast(cast(w_warehouse_sq_ft#498 as decimal(10,0)) as decimal(28,2)))), DecimalType(38,12), true)) AS jun_sales_per_sq_foot#3613, sum(CheckOverflow((promote_precision(jul_sales#3552) / promote_precision(cast(cast(w_warehouse_sq_ft#498 as decimal(10,0)) as decimal(28,2)))), DecimalType(38,12), true)) AS jul_sales_per_sq_foot#3614, sum(CheckOverflow((promote_precision(aug_sales#3553) / promote_precision(cast(cast(w_warehouse_sq_ft#498 as decimal(10,0)) as decimal(28,2)))), DecimalType(38,12), true)) AS aug_sales_per_sq_foot#3615, sum(CheckOverflow((promote_precision(sep_sales#3554) / promote_precision(cast(cast(w_warehouse_sq_ft#498 as decimal(10,0)) as decimal(28,2)))), DecimalType(38,12), true)) AS sep_sales_per_sq_foot#3616, sum(CheckOverflow((promote_precision(oct_sales#3555) / promote_precision(cast(cast(w_warehouse_sq_ft#498 as decimal(10,0)) as decimal(28,2)))), DecimalType(38,12), true)) AS oct_sales_per_sq_foot#3617, sum(CheckOverflow((promote_precision(nov_sales#3556) / promote_precision(cast(cast(w_warehouse_sq_ft#498 as decimal(10,0)) as decimal(28,2)))), DecimalType(38,12), true)) AS nov_sales_per_sq_foot#3618, sum(CheckOverflow((promote_precision(dec_sales#3557) / promote_precision(cast(cast(w_warehouse_sq_ft#498 as decimal(10,0)) as decimal(28,2)))), DecimalType(38,12), true)) AS dec_sales_per_sq_foot#3619, sum(jan_net#3558) AS jan_net#3620, sum(feb_net#3559) AS feb_net#3621, sum(mar_net#3560) AS mar_net#3622, sum(apr_net#3561) AS apr_net#3623, sum(may_net#3562) AS may_net#3624, sum(jun_net#3563) AS jun_net#3625, sum(jul_net#3564) AS jul_net#3626, sum(aug_net#3565) AS aug_net#3627, sum(sep_net#3566) AS sep_net#3628, sum(oct_net#3567) AS oct_net#3629, sum(nov_net#3568) AS nov_net#3630, sum(dec_net#3569) AS dec_net#3631)
    // Input: ListBuffer(w_warehouse_name#497, w_warehouse_sq_ft#498, w_city#503, w_county#504, w_state#505, w_country#507, ship_carriers#3544, year#3545, jan_sales#3546, feb_sales#3547, mar_sales#3548, apr_sales#3549, may_sales#3550, jun_sales#3551, jul_sales#3552, aug_sales#3553, sep_sales#3554, oct_sales#3555, nov_sales#3556, dec_sales#3557, jan_net#3558, feb_net#3559, mar_net#3560, apr_net#3561, may_net#3562, jun_net#3563, jul_net#3564, aug_net#3565, sep_net#3566, oct_net#3567, nov_net#3568, dec_net#3569)
    // Output: ListBuffer(w_warehouse_name#497, w_warehouse_sq_ft#498, w_city#503, w_county#504, w_state#505, w_country#507, ship_carriers#3544, year#3545, jan_sales#3596, feb_sales#3597, mar_sales#3598, apr_sales#3599, may_sales#3600, jun_sales#3601, jul_sales#3602, aug_sales#3603, sep_sales#3604, oct_sales#3605, nov_sales#3606, dec_sales#3607, jan_sales_per_sq_foot#3608, feb_sales_per_sq_foot#3609, mar_sales_per_sq_foot#3610, apr_sales_per_sq_foot#3611, may_sales_per_sq_foot#3612, jun_sales_per_sq_foot#3613, jul_sales_per_sq_foot#3614, aug_sales_per_sq_foot#3615, sep_sales_per_sq_foot#3616, oct_sales_per_sq_foot#3617, nov_sales_per_sq_foot#3618, dec_sales_per_sq_foot#3619, jan_net#3620, feb_net#3621, mar_net#3622, apr_net#3623, may_net#3624, jun_net#3625, jul_net#3626, aug_net#3627, sep_net#3628, oct_net#3629, nov_net#3630, dec_net#3631)
    std::unordered_map<SW_Aggregate_TD_3248653_key, SW_Aggregate_TD_3248653_payload> ht1;
    int nrow1 = tbl_Union_TD_4183185_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497 = tbl_Union_TD_4183185_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        int32_t _w_warehouse_sq_ft498 = tbl_Union_TD_4183185_output.getInt32(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _w_city503 = tbl_Union_TD_4183185_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _w_county504 = tbl_Union_TD_4183185_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _w_state505 = tbl_Union_TD_4183185_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _w_country507 = tbl_Union_TD_4183185_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _ship_carriers3544 = tbl_Union_TD_4183185_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        int32_t _year3545 = tbl_Union_TD_4183185_output.getInt32(i, 7);
        int64_t _jan_sales3546 = tbl_Union_TD_4183185_output.getInt64(i, 8);
        int64_t _feb_sales3547 = tbl_Union_TD_4183185_output.getInt64(i, 9);
        int64_t _mar_sales3548 = tbl_Union_TD_4183185_output.getInt64(i, 10);
        int64_t _apr_sales3549 = tbl_Union_TD_4183185_output.getInt64(i, 11);
        int64_t _may_sales3550 = tbl_Union_TD_4183185_output.getInt64(i, 12);
        int64_t _jun_sales3551 = tbl_Union_TD_4183185_output.getInt64(i, 13);
        int64_t _jul_sales3552 = tbl_Union_TD_4183185_output.getInt64(i, 14);
        int64_t _aug_sales3553 = tbl_Union_TD_4183185_output.getInt64(i, 15);
        int64_t _sep_sales3554 = tbl_Union_TD_4183185_output.getInt64(i, 16);
        int64_t _oct_sales3555 = tbl_Union_TD_4183185_output.getInt64(i, 17);
        int64_t _nov_sales3556 = tbl_Union_TD_4183185_output.getInt64(i, 18);
        int64_t _dec_sales3557 = tbl_Union_TD_4183185_output.getInt64(i, 19);
        int64_t _jan_net3558 = tbl_Union_TD_4183185_output.getInt64(i, 20);
        int64_t _feb_net3559 = tbl_Union_TD_4183185_output.getInt64(i, 21);
        int64_t _mar_net3560 = tbl_Union_TD_4183185_output.getInt64(i, 22);
        int64_t _apr_net3561 = tbl_Union_TD_4183185_output.getInt64(i, 23);
        int64_t _may_net3562 = tbl_Union_TD_4183185_output.getInt64(i, 24);
        int64_t _jun_net3563 = tbl_Union_TD_4183185_output.getInt64(i, 25);
        int64_t _jul_net3564 = tbl_Union_TD_4183185_output.getInt64(i, 26);
        int64_t _aug_net3565 = tbl_Union_TD_4183185_output.getInt64(i, 27);
        int64_t _sep_net3566 = tbl_Union_TD_4183185_output.getInt64(i, 28);
        int64_t _oct_net3567 = tbl_Union_TD_4183185_output.getInt64(i, 29);
        int64_t _nov_net3568 = tbl_Union_TD_4183185_output.getInt64(i, 30);
        int64_t _dec_net3569 = tbl_Union_TD_4183185_output.getInt64(i, 31);
        SW_Aggregate_TD_3248653_key k{std::string(_w_warehouse_name497.data()), _w_warehouse_sq_ft498, std::string(_w_city503.data()), std::string(_w_county504.data()), std::string(_w_state505.data()), std::string(_w_country507.data()), std::string(_ship_carriers3544.data()), _year3545};
        int64_t _jan_sales3596_sum_0 = _jan_sales3546;
        int64_t _feb_sales3597_sum_1 = _feb_sales3547;
        int64_t _mar_sales3598_sum_2 = _mar_sales3548;
        int64_t _apr_sales3599_sum_3 = _apr_sales3549;
        int64_t _may_sales3600_sum_4 = _may_sales3550;
        int64_t _jun_sales3601_sum_5 = _jun_sales3551;
        int64_t _jul_sales3602_sum_6 = _jul_sales3552;
        int64_t _aug_sales3603_sum_7 = _aug_sales3553;
        int64_t _sep_sales3604_sum_8 = _sep_sales3554;
        int64_t _oct_sales3605_sum_9 = _oct_sales3555;
        int64_t _nov_sales3606_sum_10 = _nov_sales3556;
        int64_t _dec_sales3607_sum_11 = _dec_sales3557;
        int64_t _jan_sales_per_sq_foot3608_sum_12 = (_jan_sales3546 / _w_warehouse_sq_ft498);
        int64_t _feb_sales_per_sq_foot3609_sum_13 = (_feb_sales3547 / _w_warehouse_sq_ft498);
        int64_t _mar_sales_per_sq_foot3610_sum_14 = (_mar_sales3548 / _w_warehouse_sq_ft498);
        int64_t _apr_sales_per_sq_foot3611_sum_15 = (_apr_sales3549 / _w_warehouse_sq_ft498);
        int64_t _may_sales_per_sq_foot3612_sum_16 = (_may_sales3550 / _w_warehouse_sq_ft498);
        int64_t _jun_sales_per_sq_foot3613_sum_17 = (_jun_sales3551 / _w_warehouse_sq_ft498);
        int64_t _jul_sales_per_sq_foot3614_sum_18 = (_jul_sales3552 / _w_warehouse_sq_ft498);
        int64_t _aug_sales_per_sq_foot3615_sum_19 = (_aug_sales3553 / _w_warehouse_sq_ft498);
        int64_t _sep_sales_per_sq_foot3616_sum_20 = (_sep_sales3554 / _w_warehouse_sq_ft498);
        int64_t _oct_sales_per_sq_foot3617_sum_21 = (_oct_sales3555 / _w_warehouse_sq_ft498);
        int64_t _nov_sales_per_sq_foot3618_sum_22 = (_nov_sales3556 / _w_warehouse_sq_ft498);
        int64_t _dec_sales_per_sq_foot3619_sum_23 = (_dec_sales3557 / _w_warehouse_sq_ft498);
        int64_t _jan_net3620_sum_24 = _jan_net3558;
        int64_t _feb_net3621_sum_25 = _feb_net3559;
        int64_t _mar_net3622_sum_26 = _mar_net3560;
        int64_t _apr_net3623_sum_27 = _apr_net3561;
        int64_t _may_net3624_sum_28 = _may_net3562;
        int64_t _jun_net3625_sum_29 = _jun_net3563;
        int64_t _jul_net3626_sum_30 = _jul_net3564;
        int64_t _aug_net3627_sum_31 = _aug_net3565;
        int64_t _sep_net3628_sum_32 = _sep_net3566;
        int64_t _oct_net3629_sum_33 = _oct_net3567;
        int64_t _nov_net3630_sum_34 = _nov_net3568;
        int64_t _dec_net3631_sum_35 = _dec_net3569;
        SW_Aggregate_TD_3248653_payload p{_jan_sales3596_sum_0, _feb_sales3597_sum_1, _mar_sales3598_sum_2, _apr_sales3599_sum_3, _may_sales3600_sum_4, _jun_sales3601_sum_5, _jul_sales3602_sum_6, _aug_sales3603_sum_7, _sep_sales3604_sum_8, _oct_sales3605_sum_9, _nov_sales3606_sum_10, _dec_sales3607_sum_11, _jan_sales_per_sq_foot3608_sum_12, _feb_sales_per_sq_foot3609_sum_13, _mar_sales_per_sq_foot3610_sum_14, _apr_sales_per_sq_foot3611_sum_15, _may_sales_per_sq_foot3612_sum_16, _jun_sales_per_sq_foot3613_sum_17, _jul_sales_per_sq_foot3614_sum_18, _aug_sales_per_sq_foot3615_sum_19, _sep_sales_per_sq_foot3616_sum_20, _oct_sales_per_sq_foot3617_sum_21, _nov_sales_per_sq_foot3618_sum_22, _dec_sales_per_sq_foot3619_sum_23, _jan_net3620_sum_24, _feb_net3621_sum_25, _mar_net3622_sum_26, _apr_net3623_sum_27, _may_net3624_sum_28, _jun_net3625_sum_29, _jul_net3626_sum_30, _aug_net3627_sum_31, _sep_net3628_sum_32, _oct_net3629_sum_33, _nov_net3630_sum_34, _dec_net3631_sum_35};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._jan_sales3596_sum_0 + _jan_sales3596_sum_0;
            p._jan_sales3596_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._feb_sales3597_sum_1 + _feb_sales3597_sum_1;
            p._feb_sales3597_sum_1 = sum_1;
            int64_t sum_2 = (it->second)._mar_sales3598_sum_2 + _mar_sales3598_sum_2;
            p._mar_sales3598_sum_2 = sum_2;
            int64_t sum_3 = (it->second)._apr_sales3599_sum_3 + _apr_sales3599_sum_3;
            p._apr_sales3599_sum_3 = sum_3;
            int64_t sum_4 = (it->second)._may_sales3600_sum_4 + _may_sales3600_sum_4;
            p._may_sales3600_sum_4 = sum_4;
            int64_t sum_5 = (it->second)._jun_sales3601_sum_5 + _jun_sales3601_sum_5;
            p._jun_sales3601_sum_5 = sum_5;
            int64_t sum_6 = (it->second)._jul_sales3602_sum_6 + _jul_sales3602_sum_6;
            p._jul_sales3602_sum_6 = sum_6;
            int64_t sum_7 = (it->second)._aug_sales3603_sum_7 + _aug_sales3603_sum_7;
            p._aug_sales3603_sum_7 = sum_7;
            int64_t sum_8 = (it->second)._sep_sales3604_sum_8 + _sep_sales3604_sum_8;
            p._sep_sales3604_sum_8 = sum_8;
            int64_t sum_9 = (it->second)._oct_sales3605_sum_9 + _oct_sales3605_sum_9;
            p._oct_sales3605_sum_9 = sum_9;
            int64_t sum_10 = (it->second)._nov_sales3606_sum_10 + _nov_sales3606_sum_10;
            p._nov_sales3606_sum_10 = sum_10;
            int64_t sum_11 = (it->second)._dec_sales3607_sum_11 + _dec_sales3607_sum_11;
            p._dec_sales3607_sum_11 = sum_11;
            int64_t sum_12 = (it->second)._jan_sales_per_sq_foot3608_sum_12 + _jan_sales_per_sq_foot3608_sum_12;
            p._jan_sales_per_sq_foot3608_sum_12 = sum_12;
            int64_t sum_13 = (it->second)._feb_sales_per_sq_foot3609_sum_13 + _feb_sales_per_sq_foot3609_sum_13;
            p._feb_sales_per_sq_foot3609_sum_13 = sum_13;
            int64_t sum_14 = (it->second)._mar_sales_per_sq_foot3610_sum_14 + _mar_sales_per_sq_foot3610_sum_14;
            p._mar_sales_per_sq_foot3610_sum_14 = sum_14;
            int64_t sum_15 = (it->second)._apr_sales_per_sq_foot3611_sum_15 + _apr_sales_per_sq_foot3611_sum_15;
            p._apr_sales_per_sq_foot3611_sum_15 = sum_15;
            int64_t sum_16 = (it->second)._may_sales_per_sq_foot3612_sum_16 + _may_sales_per_sq_foot3612_sum_16;
            p._may_sales_per_sq_foot3612_sum_16 = sum_16;
            int64_t sum_17 = (it->second)._jun_sales_per_sq_foot3613_sum_17 + _jun_sales_per_sq_foot3613_sum_17;
            p._jun_sales_per_sq_foot3613_sum_17 = sum_17;
            int64_t sum_18 = (it->second)._jul_sales_per_sq_foot3614_sum_18 + _jul_sales_per_sq_foot3614_sum_18;
            p._jul_sales_per_sq_foot3614_sum_18 = sum_18;
            int64_t sum_19 = (it->second)._aug_sales_per_sq_foot3615_sum_19 + _aug_sales_per_sq_foot3615_sum_19;
            p._aug_sales_per_sq_foot3615_sum_19 = sum_19;
            int64_t sum_20 = (it->second)._sep_sales_per_sq_foot3616_sum_20 + _sep_sales_per_sq_foot3616_sum_20;
            p._sep_sales_per_sq_foot3616_sum_20 = sum_20;
            int64_t sum_21 = (it->second)._oct_sales_per_sq_foot3617_sum_21 + _oct_sales_per_sq_foot3617_sum_21;
            p._oct_sales_per_sq_foot3617_sum_21 = sum_21;
            int64_t sum_22 = (it->second)._nov_sales_per_sq_foot3618_sum_22 + _nov_sales_per_sq_foot3618_sum_22;
            p._nov_sales_per_sq_foot3618_sum_22 = sum_22;
            int64_t sum_23 = (it->second)._dec_sales_per_sq_foot3619_sum_23 + _dec_sales_per_sq_foot3619_sum_23;
            p._dec_sales_per_sq_foot3619_sum_23 = sum_23;
            int64_t sum_24 = (it->second)._jan_net3620_sum_24 + _jan_net3620_sum_24;
            p._jan_net3620_sum_24 = sum_24;
            int64_t sum_25 = (it->second)._feb_net3621_sum_25 + _feb_net3621_sum_25;
            p._feb_net3621_sum_25 = sum_25;
            int64_t sum_26 = (it->second)._mar_net3622_sum_26 + _mar_net3622_sum_26;
            p._mar_net3622_sum_26 = sum_26;
            int64_t sum_27 = (it->second)._apr_net3623_sum_27 + _apr_net3623_sum_27;
            p._apr_net3623_sum_27 = sum_27;
            int64_t sum_28 = (it->second)._may_net3624_sum_28 + _may_net3624_sum_28;
            p._may_net3624_sum_28 = sum_28;
            int64_t sum_29 = (it->second)._jun_net3625_sum_29 + _jun_net3625_sum_29;
            p._jun_net3625_sum_29 = sum_29;
            int64_t sum_30 = (it->second)._jul_net3626_sum_30 + _jul_net3626_sum_30;
            p._jul_net3626_sum_30 = sum_30;
            int64_t sum_31 = (it->second)._aug_net3627_sum_31 + _aug_net3627_sum_31;
            p._aug_net3627_sum_31 = sum_31;
            int64_t sum_32 = (it->second)._sep_net3628_sum_32 + _sep_net3628_sum_32;
            p._sep_net3628_sum_32 = sum_32;
            int64_t sum_33 = (it->second)._oct_net3629_sum_33 + _oct_net3629_sum_33;
            p._oct_net3629_sum_33 = sum_33;
            int64_t sum_34 = (it->second)._nov_net3630_sum_34 + _nov_net3630_sum_34;
            p._nov_net3630_sum_34 = sum_34;
            int64_t sum_35 = (it->second)._dec_net3631_sum_35 + _dec_net3631_sum_35;
            p._dec_net3631_sum_35 = sum_35;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497{};
        memcpy(_w_warehouse_name497.data(), ((it.first)._w_warehouse_name497).data(), ((it.first)._w_warehouse_name497).length());
        tbl_Aggregate_TD_3248653_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _w_warehouse_name497);
        tbl_Aggregate_TD_3248653_output.setInt32(r, 1, (it.first)._w_warehouse_sq_ft498);
        std::array<char, TPCDS_READ_MAX + 1> _w_city503{};
        memcpy(_w_city503.data(), ((it.first)._w_city503).data(), ((it.first)._w_city503).length());
        tbl_Aggregate_TD_3248653_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _w_city503);
        std::array<char, TPCDS_READ_MAX + 1> _w_county504{};
        memcpy(_w_county504.data(), ((it.first)._w_county504).data(), ((it.first)._w_county504).length());
        tbl_Aggregate_TD_3248653_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _w_county504);
        std::array<char, TPCDS_READ_MAX + 1> _w_state505{};
        memcpy(_w_state505.data(), ((it.first)._w_state505).data(), ((it.first)._w_state505).length());
        tbl_Aggregate_TD_3248653_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _w_state505);
        std::array<char, TPCDS_READ_MAX + 1> _w_country507{};
        memcpy(_w_country507.data(), ((it.first)._w_country507).data(), ((it.first)._w_country507).length());
        tbl_Aggregate_TD_3248653_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _w_country507);
        std::array<char, TPCDS_READ_MAX + 1> _ship_carriers3544{};
        memcpy(_ship_carriers3544.data(), ((it.first)._ship_carriers3544).data(), ((it.first)._ship_carriers3544).length());
        tbl_Aggregate_TD_3248653_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _ship_carriers3544);
        tbl_Aggregate_TD_3248653_output.setInt32(r, 7, (it.first)._year3545);
        int64_t _jan_sales3596 = (it.second)._jan_sales3596_sum_0;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 8, _jan_sales3596);
        int64_t _feb_sales3597 = (it.second)._feb_sales3597_sum_1;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 9, _feb_sales3597);
        int64_t _mar_sales3598 = (it.second)._mar_sales3598_sum_2;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 10, _mar_sales3598);
        int64_t _apr_sales3599 = (it.second)._apr_sales3599_sum_3;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 11, _apr_sales3599);
        int64_t _may_sales3600 = (it.second)._may_sales3600_sum_4;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 12, _may_sales3600);
        int64_t _jun_sales3601 = (it.second)._jun_sales3601_sum_5;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 13, _jun_sales3601);
        int64_t _jul_sales3602 = (it.second)._jul_sales3602_sum_6;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 14, _jul_sales3602);
        int64_t _aug_sales3603 = (it.second)._aug_sales3603_sum_7;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 15, _aug_sales3603);
        int64_t _sep_sales3604 = (it.second)._sep_sales3604_sum_8;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 16, _sep_sales3604);
        int64_t _oct_sales3605 = (it.second)._oct_sales3605_sum_9;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 17, _oct_sales3605);
        int64_t _nov_sales3606 = (it.second)._nov_sales3606_sum_10;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 18, _nov_sales3606);
        int64_t _dec_sales3607 = (it.second)._dec_sales3607_sum_11;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 19, _dec_sales3607);
        int64_t _jan_sales_per_sq_foot3608 = (it.second)._jan_sales_per_sq_foot3608_sum_12;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 20, _jan_sales_per_sq_foot3608);
        int64_t _feb_sales_per_sq_foot3609 = (it.second)._feb_sales_per_sq_foot3609_sum_13;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 21, _feb_sales_per_sq_foot3609);
        int64_t _mar_sales_per_sq_foot3610 = (it.second)._mar_sales_per_sq_foot3610_sum_14;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 22, _mar_sales_per_sq_foot3610);
        int64_t _apr_sales_per_sq_foot3611 = (it.second)._apr_sales_per_sq_foot3611_sum_15;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 23, _apr_sales_per_sq_foot3611);
        int64_t _may_sales_per_sq_foot3612 = (it.second)._may_sales_per_sq_foot3612_sum_16;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 24, _may_sales_per_sq_foot3612);
        int64_t _jun_sales_per_sq_foot3613 = (it.second)._jun_sales_per_sq_foot3613_sum_17;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 25, _jun_sales_per_sq_foot3613);
        int64_t _jul_sales_per_sq_foot3614 = (it.second)._jul_sales_per_sq_foot3614_sum_18;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 26, _jul_sales_per_sq_foot3614);
        int64_t _aug_sales_per_sq_foot3615 = (it.second)._aug_sales_per_sq_foot3615_sum_19;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 27, _aug_sales_per_sq_foot3615);
        int64_t _sep_sales_per_sq_foot3616 = (it.second)._sep_sales_per_sq_foot3616_sum_20;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 28, _sep_sales_per_sq_foot3616);
        int64_t _oct_sales_per_sq_foot3617 = (it.second)._oct_sales_per_sq_foot3617_sum_21;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 29, _oct_sales_per_sq_foot3617);
        int64_t _nov_sales_per_sq_foot3618 = (it.second)._nov_sales_per_sq_foot3618_sum_22;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 30, _nov_sales_per_sq_foot3618);
        int64_t _dec_sales_per_sq_foot3619 = (it.second)._dec_sales_per_sq_foot3619_sum_23;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 31, _dec_sales_per_sq_foot3619);
        int64_t _jan_net3620 = (it.second)._jan_net3620_sum_24;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 32, _jan_net3620);
        int64_t _feb_net3621 = (it.second)._feb_net3621_sum_25;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 33, _feb_net3621);
        int64_t _mar_net3622 = (it.second)._mar_net3622_sum_26;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 34, _mar_net3622);
        int64_t _apr_net3623 = (it.second)._apr_net3623_sum_27;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 35, _apr_net3623);
        int64_t _may_net3624 = (it.second)._may_net3624_sum_28;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 36, _may_net3624);
        int64_t _jun_net3625 = (it.second)._jun_net3625_sum_29;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 37, _jun_net3625);
        int64_t _jul_net3626 = (it.second)._jul_net3626_sum_30;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 38, _jul_net3626);
        int64_t _aug_net3627 = (it.second)._aug_net3627_sum_31;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 39, _aug_net3627);
        int64_t _sep_net3628 = (it.second)._sep_net3628_sum_32;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 40, _sep_net3628);
        int64_t _oct_net3629 = (it.second)._oct_net3629_sum_33;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 41, _oct_net3629);
        int64_t _nov_net3630 = (it.second)._nov_net3630_sum_34;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 42, _nov_net3630);
        int64_t _dec_net3631 = (it.second)._dec_net3631_sum_35;
        tbl_Aggregate_TD_3248653_output.setInt64(r, 43, _dec_net3631);
        ++r;
    }
    tbl_Aggregate_TD_3248653_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_3248653_output #Row: " << tbl_Aggregate_TD_3248653_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2704870(Table &tbl_Aggregate_TD_3248653_output, Table &tbl_Sort_TD_2704870_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(w_warehouse_name#497 ASC NULLS FIRST)
    // Input: ListBuffer(w_warehouse_name#497, w_warehouse_sq_ft#498, w_city#503, w_county#504, w_state#505, w_country#507, ship_carriers#3544, year#3545, jan_sales#3596, feb_sales#3597, mar_sales#3598, apr_sales#3599, may_sales#3600, jun_sales#3601, jul_sales#3602, aug_sales#3603, sep_sales#3604, oct_sales#3605, nov_sales#3606, dec_sales#3607, jan_sales_per_sq_foot#3608, feb_sales_per_sq_foot#3609, mar_sales_per_sq_foot#3610, apr_sales_per_sq_foot#3611, may_sales_per_sq_foot#3612, jun_sales_per_sq_foot#3613, jul_sales_per_sq_foot#3614, aug_sales_per_sq_foot#3615, sep_sales_per_sq_foot#3616, oct_sales_per_sq_foot#3617, nov_sales_per_sq_foot#3618, dec_sales_per_sq_foot#3619, jan_net#3620, feb_net#3621, mar_net#3622, apr_net#3623, may_net#3624, jun_net#3625, jul_net#3626, aug_net#3627, sep_net#3628, oct_net#3629, nov_net#3630, dec_net#3631)
    // Output: ListBuffer(w_warehouse_name#497, w_warehouse_sq_ft#498, w_city#503, w_county#504, w_state#505, w_country#507, ship_carriers#3544, year#3545, jan_sales#3596, feb_sales#3597, mar_sales#3598, apr_sales#3599, may_sales#3600, jun_sales#3601, jul_sales#3602, aug_sales#3603, sep_sales#3604, oct_sales#3605, nov_sales#3606, dec_sales#3607, jan_sales_per_sq_foot#3608, feb_sales_per_sq_foot#3609, mar_sales_per_sq_foot#3610, apr_sales_per_sq_foot#3611, may_sales_per_sq_foot#3612, jun_sales_per_sq_foot#3613, jul_sales_per_sq_foot#3614, aug_sales_per_sq_foot#3615, sep_sales_per_sq_foot#3616, oct_sales_per_sq_foot#3617, nov_sales_per_sq_foot#3618, dec_sales_per_sq_foot#3619, jan_net#3620, feb_net#3621, mar_net#3622, apr_net#3623, may_net#3624, jun_net#3625, jul_net#3626, aug_net#3627, sep_net#3628, oct_net#3629, nov_net#3630, dec_net#3631)
    struct SW_Sort_TD_2704870Row {
        std::string _w_warehouse_name497;
        int32_t _w_warehouse_sq_ft498;
        std::string _w_city503;
        std::string _w_county504;
        std::string _w_state505;
        std::string _w_country507;
        std::string _ship_carriers3544;
        int32_t _year3545;
        int64_t _jan_sales3596;
        int64_t _feb_sales3597;
        int64_t _mar_sales3598;
        int64_t _apr_sales3599;
        int64_t _may_sales3600;
        int64_t _jun_sales3601;
        int64_t _jul_sales3602;
        int64_t _aug_sales3603;
        int64_t _sep_sales3604;
        int64_t _oct_sales3605;
        int64_t _nov_sales3606;
        int64_t _dec_sales3607;
        int64_t _jan_sales_per_sq_foot3608;
        int64_t _feb_sales_per_sq_foot3609;
        int64_t _mar_sales_per_sq_foot3610;
        int64_t _apr_sales_per_sq_foot3611;
        int64_t _may_sales_per_sq_foot3612;
        int64_t _jun_sales_per_sq_foot3613;
        int64_t _jul_sales_per_sq_foot3614;
        int64_t _aug_sales_per_sq_foot3615;
        int64_t _sep_sales_per_sq_foot3616;
        int64_t _oct_sales_per_sq_foot3617;
        int64_t _nov_sales_per_sq_foot3618;
        int64_t _dec_sales_per_sq_foot3619;
        int64_t _jan_net3620;
        int64_t _feb_net3621;
        int64_t _mar_net3622;
        int64_t _apr_net3623;
        int64_t _may_net3624;
        int64_t _jun_net3625;
        int64_t _jul_net3626;
        int64_t _aug_net3627;
        int64_t _sep_net3628;
        int64_t _oct_net3629;
        int64_t _nov_net3630;
        int64_t _dec_net3631;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2704870Row& a, const SW_Sort_TD_2704870Row& b) const { return 
 (a._w_warehouse_name497 < b._w_warehouse_name497); 
}
    }SW_Sort_TD_2704870_order; 

    int nrow1 = tbl_Aggregate_TD_3248653_output.getNumRow();
    std::vector<SW_Sort_TD_2704870Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497 = tbl_Aggregate_TD_3248653_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        int32_t _w_warehouse_sq_ft498 = tbl_Aggregate_TD_3248653_output.getInt32(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _w_city503 = tbl_Aggregate_TD_3248653_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _w_county504 = tbl_Aggregate_TD_3248653_output.getcharN<char, TPCDS_READ_MAX +1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _w_state505 = tbl_Aggregate_TD_3248653_output.getcharN<char, TPCDS_READ_MAX +1>(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _w_country507 = tbl_Aggregate_TD_3248653_output.getcharN<char, TPCDS_READ_MAX +1>(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _ship_carriers3544 = tbl_Aggregate_TD_3248653_output.getcharN<char, TPCDS_READ_MAX +1>(i, 6);
        int32_t _year3545 = tbl_Aggregate_TD_3248653_output.getInt32(i, 7);
        int64_t _jan_sales3596 = tbl_Aggregate_TD_3248653_output.getInt64(i, 8);
        int64_t _feb_sales3597 = tbl_Aggregate_TD_3248653_output.getInt64(i, 9);
        int64_t _mar_sales3598 = tbl_Aggregate_TD_3248653_output.getInt64(i, 10);
        int64_t _apr_sales3599 = tbl_Aggregate_TD_3248653_output.getInt64(i, 11);
        int64_t _may_sales3600 = tbl_Aggregate_TD_3248653_output.getInt64(i, 12);
        int64_t _jun_sales3601 = tbl_Aggregate_TD_3248653_output.getInt64(i, 13);
        int64_t _jul_sales3602 = tbl_Aggregate_TD_3248653_output.getInt64(i, 14);
        int64_t _aug_sales3603 = tbl_Aggregate_TD_3248653_output.getInt64(i, 15);
        int64_t _sep_sales3604 = tbl_Aggregate_TD_3248653_output.getInt64(i, 16);
        int64_t _oct_sales3605 = tbl_Aggregate_TD_3248653_output.getInt64(i, 17);
        int64_t _nov_sales3606 = tbl_Aggregate_TD_3248653_output.getInt64(i, 18);
        int64_t _dec_sales3607 = tbl_Aggregate_TD_3248653_output.getInt64(i, 19);
        int64_t _jan_sales_per_sq_foot3608 = tbl_Aggregate_TD_3248653_output.getInt64(i, 20);
        int64_t _feb_sales_per_sq_foot3609 = tbl_Aggregate_TD_3248653_output.getInt64(i, 21);
        int64_t _mar_sales_per_sq_foot3610 = tbl_Aggregate_TD_3248653_output.getInt64(i, 22);
        int64_t _apr_sales_per_sq_foot3611 = tbl_Aggregate_TD_3248653_output.getInt64(i, 23);
        int64_t _may_sales_per_sq_foot3612 = tbl_Aggregate_TD_3248653_output.getInt64(i, 24);
        int64_t _jun_sales_per_sq_foot3613 = tbl_Aggregate_TD_3248653_output.getInt64(i, 25);
        int64_t _jul_sales_per_sq_foot3614 = tbl_Aggregate_TD_3248653_output.getInt64(i, 26);
        int64_t _aug_sales_per_sq_foot3615 = tbl_Aggregate_TD_3248653_output.getInt64(i, 27);
        int64_t _sep_sales_per_sq_foot3616 = tbl_Aggregate_TD_3248653_output.getInt64(i, 28);
        int64_t _oct_sales_per_sq_foot3617 = tbl_Aggregate_TD_3248653_output.getInt64(i, 29);
        int64_t _nov_sales_per_sq_foot3618 = tbl_Aggregate_TD_3248653_output.getInt64(i, 30);
        int64_t _dec_sales_per_sq_foot3619 = tbl_Aggregate_TD_3248653_output.getInt64(i, 31);
        int64_t _jan_net3620 = tbl_Aggregate_TD_3248653_output.getInt64(i, 32);
        int64_t _feb_net3621 = tbl_Aggregate_TD_3248653_output.getInt64(i, 33);
        int64_t _mar_net3622 = tbl_Aggregate_TD_3248653_output.getInt64(i, 34);
        int64_t _apr_net3623 = tbl_Aggregate_TD_3248653_output.getInt64(i, 35);
        int64_t _may_net3624 = tbl_Aggregate_TD_3248653_output.getInt64(i, 36);
        int64_t _jun_net3625 = tbl_Aggregate_TD_3248653_output.getInt64(i, 37);
        int64_t _jul_net3626 = tbl_Aggregate_TD_3248653_output.getInt64(i, 38);
        int64_t _aug_net3627 = tbl_Aggregate_TD_3248653_output.getInt64(i, 39);
        int64_t _sep_net3628 = tbl_Aggregate_TD_3248653_output.getInt64(i, 40);
        int64_t _oct_net3629 = tbl_Aggregate_TD_3248653_output.getInt64(i, 41);
        int64_t _nov_net3630 = tbl_Aggregate_TD_3248653_output.getInt64(i, 42);
        int64_t _dec_net3631 = tbl_Aggregate_TD_3248653_output.getInt64(i, 43);
        SW_Sort_TD_2704870Row t = {std::string(_w_warehouse_name497.data()),_w_warehouse_sq_ft498,std::string(_w_city503.data()),std::string(_w_county504.data()),std::string(_w_state505.data()),std::string(_w_country507.data()),std::string(_ship_carriers3544.data()),_year3545,_jan_sales3596,_feb_sales3597,_mar_sales3598,_apr_sales3599,_may_sales3600,_jun_sales3601,_jul_sales3602,_aug_sales3603,_sep_sales3604,_oct_sales3605,_nov_sales3606,_dec_sales3607,_jan_sales_per_sq_foot3608,_feb_sales_per_sq_foot3609,_mar_sales_per_sq_foot3610,_apr_sales_per_sq_foot3611,_may_sales_per_sq_foot3612,_jun_sales_per_sq_foot3613,_jul_sales_per_sq_foot3614,_aug_sales_per_sq_foot3615,_sep_sales_per_sq_foot3616,_oct_sales_per_sq_foot3617,_nov_sales_per_sq_foot3618,_dec_sales_per_sq_foot3619,_jan_net3620,_feb_net3621,_mar_net3622,_apr_net3623,_may_net3624,_jun_net3625,_jul_net3626,_aug_net3627,_sep_net3628,_oct_net3629,_nov_net3630,_dec_net3631};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2704870_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497{};
        memcpy(_w_warehouse_name497.data(), (it._w_warehouse_name497).data(), (it._w_warehouse_name497).length());
        tbl_Sort_TD_2704870_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _w_warehouse_name497);
        tbl_Sort_TD_2704870_output.setInt32(r, 1, it._w_warehouse_sq_ft498);
        std::array<char, TPCDS_READ_MAX + 1> _w_city503{};
        memcpy(_w_city503.data(), (it._w_city503).data(), (it._w_city503).length());
        tbl_Sort_TD_2704870_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _w_city503);
        std::array<char, TPCDS_READ_MAX + 1> _w_county504{};
        memcpy(_w_county504.data(), (it._w_county504).data(), (it._w_county504).length());
        tbl_Sort_TD_2704870_output.setcharN<char, TPCDS_READ_MAX +1>(r, 3, _w_county504);
        std::array<char, TPCDS_READ_MAX + 1> _w_state505{};
        memcpy(_w_state505.data(), (it._w_state505).data(), (it._w_state505).length());
        tbl_Sort_TD_2704870_output.setcharN<char, TPCDS_READ_MAX +1>(r, 4, _w_state505);
        std::array<char, TPCDS_READ_MAX + 1> _w_country507{};
        memcpy(_w_country507.data(), (it._w_country507).data(), (it._w_country507).length());
        tbl_Sort_TD_2704870_output.setcharN<char, TPCDS_READ_MAX +1>(r, 5, _w_country507);
        std::array<char, TPCDS_READ_MAX + 1> _ship_carriers3544{};
        memcpy(_ship_carriers3544.data(), (it._ship_carriers3544).data(), (it._ship_carriers3544).length());
        tbl_Sort_TD_2704870_output.setcharN<char, TPCDS_READ_MAX +1>(r, 6, _ship_carriers3544);
        tbl_Sort_TD_2704870_output.setInt32(r, 7, it._year3545);
        tbl_Sort_TD_2704870_output.setInt64(r, 8, it._jan_sales3596);
        tbl_Sort_TD_2704870_output.setInt64(r, 9, it._feb_sales3597);
        tbl_Sort_TD_2704870_output.setInt64(r, 10, it._mar_sales3598);
        tbl_Sort_TD_2704870_output.setInt64(r, 11, it._apr_sales3599);
        tbl_Sort_TD_2704870_output.setInt64(r, 12, it._may_sales3600);
        tbl_Sort_TD_2704870_output.setInt64(r, 13, it._jun_sales3601);
        tbl_Sort_TD_2704870_output.setInt64(r, 14, it._jul_sales3602);
        tbl_Sort_TD_2704870_output.setInt64(r, 15, it._aug_sales3603);
        tbl_Sort_TD_2704870_output.setInt64(r, 16, it._sep_sales3604);
        tbl_Sort_TD_2704870_output.setInt64(r, 17, it._oct_sales3605);
        tbl_Sort_TD_2704870_output.setInt64(r, 18, it._nov_sales3606);
        tbl_Sort_TD_2704870_output.setInt64(r, 19, it._dec_sales3607);
        tbl_Sort_TD_2704870_output.setInt64(r, 20, it._jan_sales_per_sq_foot3608);
        tbl_Sort_TD_2704870_output.setInt64(r, 21, it._feb_sales_per_sq_foot3609);
        tbl_Sort_TD_2704870_output.setInt64(r, 22, it._mar_sales_per_sq_foot3610);
        tbl_Sort_TD_2704870_output.setInt64(r, 23, it._apr_sales_per_sq_foot3611);
        tbl_Sort_TD_2704870_output.setInt64(r, 24, it._may_sales_per_sq_foot3612);
        tbl_Sort_TD_2704870_output.setInt64(r, 25, it._jun_sales_per_sq_foot3613);
        tbl_Sort_TD_2704870_output.setInt64(r, 26, it._jul_sales_per_sq_foot3614);
        tbl_Sort_TD_2704870_output.setInt64(r, 27, it._aug_sales_per_sq_foot3615);
        tbl_Sort_TD_2704870_output.setInt64(r, 28, it._sep_sales_per_sq_foot3616);
        tbl_Sort_TD_2704870_output.setInt64(r, 29, it._oct_sales_per_sq_foot3617);
        tbl_Sort_TD_2704870_output.setInt64(r, 30, it._nov_sales_per_sq_foot3618);
        tbl_Sort_TD_2704870_output.setInt64(r, 31, it._dec_sales_per_sq_foot3619);
        tbl_Sort_TD_2704870_output.setInt64(r, 32, it._jan_net3620);
        tbl_Sort_TD_2704870_output.setInt64(r, 33, it._feb_net3621);
        tbl_Sort_TD_2704870_output.setInt64(r, 34, it._mar_net3622);
        tbl_Sort_TD_2704870_output.setInt64(r, 35, it._apr_net3623);
        tbl_Sort_TD_2704870_output.setInt64(r, 36, it._may_net3624);
        tbl_Sort_TD_2704870_output.setInt64(r, 37, it._jun_net3625);
        tbl_Sort_TD_2704870_output.setInt64(r, 38, it._jul_net3626);
        tbl_Sort_TD_2704870_output.setInt64(r, 39, it._aug_net3627);
        tbl_Sort_TD_2704870_output.setInt64(r, 40, it._sep_net3628);
        tbl_Sort_TD_2704870_output.setInt64(r, 41, it._oct_net3629);
        tbl_Sort_TD_2704870_output.setInt64(r, 42, it._nov_net3630);
        tbl_Sort_TD_2704870_output.setInt64(r, 43, it._dec_net3631);
        ++r;
    }
    tbl_Sort_TD_2704870_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2704870_output #Row: " << tbl_Sort_TD_2704870_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_137350(Table &tbl_Sort_TD_2704870_output, Table &tbl_LocalLimit_TD_137350_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(w_warehouse_name#497, w_warehouse_sq_ft#498, w_city#503, w_county#504, w_state#505, w_country#507, ship_carriers#3544, year#3545, jan_sales#3596, feb_sales#3597, mar_sales#3598, apr_sales#3599, may_sales#3600, jun_sales#3601, jul_sales#3602, aug_sales#3603, sep_sales#3604, oct_sales#3605, nov_sales#3606, dec_sales#3607, jan_sales_per_sq_foot#3608, feb_sales_per_sq_foot#3609, mar_sales_per_sq_foot#3610, apr_sales_per_sq_foot#3611, may_sales_per_sq_foot#3612, jun_sales_per_sq_foot#3613, jul_sales_per_sq_foot#3614, aug_sales_per_sq_foot#3615, sep_sales_per_sq_foot#3616, oct_sales_per_sq_foot#3617, nov_sales_per_sq_foot#3618, dec_sales_per_sq_foot#3619, jan_net#3620, feb_net#3621, mar_net#3622, apr_net#3623, may_net#3624, jun_net#3625, jul_net#3626, aug_net#3627, sep_net#3628, oct_net#3629, nov_net#3630, dec_net#3631)
    // Output: ListBuffer(w_warehouse_name#497, w_warehouse_sq_ft#498, w_city#503, w_county#504, w_state#505, w_country#507, ship_carriers#3544, year#3545, jan_sales#3596, feb_sales#3597, mar_sales#3598, apr_sales#3599, may_sales#3600, jun_sales#3601, jul_sales#3602, aug_sales#3603, sep_sales#3604, oct_sales#3605, nov_sales#3606, dec_sales#3607, jan_sales_per_sq_foot#3608, feb_sales_per_sq_foot#3609, mar_sales_per_sq_foot#3610, apr_sales_per_sq_foot#3611, may_sales_per_sq_foot#3612, jun_sales_per_sq_foot#3613, jul_sales_per_sq_foot#3614, aug_sales_per_sq_foot#3615, sep_sales_per_sq_foot#3616, oct_sales_per_sq_foot#3617, nov_sales_per_sq_foot#3618, dec_sales_per_sq_foot#3619, jan_net#3620, feb_net#3621, mar_net#3622, apr_net#3623, may_net#3624, jun_net#3625, jul_net#3626, aug_net#3627, sep_net#3628, oct_net#3629, nov_net#3630, dec_net#3631)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_Sort_TD_2704870_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_137350_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _w_warehouse_name497_n);
        tbl_LocalLimit_TD_137350_output.setInt32(r, 1, tbl_Sort_TD_2704870_output.getInt32(i, 1));
        std::array<char, TPCDS_READ_MAX + 1> _w_city503_n = tbl_Sort_TD_2704870_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_LocalLimit_TD_137350_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _w_city503_n);
        std::array<char, TPCDS_READ_MAX + 1> _w_county504_n = tbl_Sort_TD_2704870_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_LocalLimit_TD_137350_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _w_county504_n);
        std::array<char, TPCDS_READ_MAX + 1> _w_state505_n = tbl_Sort_TD_2704870_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        tbl_LocalLimit_TD_137350_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _w_state505_n);
        std::array<char, TPCDS_READ_MAX + 1> _w_country507_n = tbl_Sort_TD_2704870_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        tbl_LocalLimit_TD_137350_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _w_country507_n);
        std::array<char, TPCDS_READ_MAX + 1> _ship_carriers3544_n = tbl_Sort_TD_2704870_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        tbl_LocalLimit_TD_137350_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _ship_carriers3544_n);
        tbl_LocalLimit_TD_137350_output.setInt32(r, 7, tbl_Sort_TD_2704870_output.getInt32(i, 7));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 8, tbl_Sort_TD_2704870_output.getInt64(i, 8));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 9, tbl_Sort_TD_2704870_output.getInt64(i, 9));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 10, tbl_Sort_TD_2704870_output.getInt64(i, 10));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 11, tbl_Sort_TD_2704870_output.getInt64(i, 11));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 12, tbl_Sort_TD_2704870_output.getInt64(i, 12));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 13, tbl_Sort_TD_2704870_output.getInt64(i, 13));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 14, tbl_Sort_TD_2704870_output.getInt64(i, 14));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 15, tbl_Sort_TD_2704870_output.getInt64(i, 15));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 16, tbl_Sort_TD_2704870_output.getInt64(i, 16));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 17, tbl_Sort_TD_2704870_output.getInt64(i, 17));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 18, tbl_Sort_TD_2704870_output.getInt64(i, 18));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 19, tbl_Sort_TD_2704870_output.getInt64(i, 19));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 20, tbl_Sort_TD_2704870_output.getInt64(i, 20));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 21, tbl_Sort_TD_2704870_output.getInt64(i, 21));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 22, tbl_Sort_TD_2704870_output.getInt64(i, 22));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 23, tbl_Sort_TD_2704870_output.getInt64(i, 23));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 24, tbl_Sort_TD_2704870_output.getInt64(i, 24));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 25, tbl_Sort_TD_2704870_output.getInt64(i, 25));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 26, tbl_Sort_TD_2704870_output.getInt64(i, 26));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 27, tbl_Sort_TD_2704870_output.getInt64(i, 27));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 28, tbl_Sort_TD_2704870_output.getInt64(i, 28));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 29, tbl_Sort_TD_2704870_output.getInt64(i, 29));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 30, tbl_Sort_TD_2704870_output.getInt64(i, 30));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 31, tbl_Sort_TD_2704870_output.getInt64(i, 31));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 32, tbl_Sort_TD_2704870_output.getInt64(i, 32));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 33, tbl_Sort_TD_2704870_output.getInt64(i, 33));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 34, tbl_Sort_TD_2704870_output.getInt64(i, 34));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 35, tbl_Sort_TD_2704870_output.getInt64(i, 35));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 36, tbl_Sort_TD_2704870_output.getInt64(i, 36));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 37, tbl_Sort_TD_2704870_output.getInt64(i, 37));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 38, tbl_Sort_TD_2704870_output.getInt64(i, 38));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 39, tbl_Sort_TD_2704870_output.getInt64(i, 39));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 40, tbl_Sort_TD_2704870_output.getInt64(i, 40));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 41, tbl_Sort_TD_2704870_output.getInt64(i, 41));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 42, tbl_Sort_TD_2704870_output.getInt64(i, 42));
        tbl_LocalLimit_TD_137350_output.setInt64(r, 43, tbl_Sort_TD_2704870_output.getInt64(i, 43));
        r++;
    }
    tbl_LocalLimit_TD_137350_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_137350_output #Row: " << tbl_LocalLimit_TD_137350_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_04967(Table &tbl_LocalLimit_TD_137350_output, Table &tbl_GlobalLimit_TD_04967_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(w_warehouse_name#497, w_warehouse_sq_ft#498, w_city#503, w_county#504, w_state#505, w_country#507, ship_carriers#3544, year#3545, jan_sales#3596, feb_sales#3597, mar_sales#3598, apr_sales#3599, may_sales#3600, jun_sales#3601, jul_sales#3602, aug_sales#3603, sep_sales#3604, oct_sales#3605, nov_sales#3606, dec_sales#3607, jan_sales_per_sq_foot#3608, feb_sales_per_sq_foot#3609, mar_sales_per_sq_foot#3610, apr_sales_per_sq_foot#3611, may_sales_per_sq_foot#3612, jun_sales_per_sq_foot#3613, jul_sales_per_sq_foot#3614, aug_sales_per_sq_foot#3615, sep_sales_per_sq_foot#3616, oct_sales_per_sq_foot#3617, nov_sales_per_sq_foot#3618, dec_sales_per_sq_foot#3619, jan_net#3620, feb_net#3621, mar_net#3622, apr_net#3623, may_net#3624, jun_net#3625, jul_net#3626, aug_net#3627, sep_net#3628, oct_net#3629, nov_net#3630, dec_net#3631)
    // Output: ListBuffer(w_warehouse_name#497, w_warehouse_sq_ft#498, w_city#503, w_county#504, w_state#505, w_country#507, ship_carriers#3544, year#3545, jan_sales#3596, feb_sales#3597, mar_sales#3598, apr_sales#3599, may_sales#3600, jun_sales#3601, jul_sales#3602, aug_sales#3603, sep_sales#3604, oct_sales#3605, nov_sales#3606, dec_sales#3607, jan_sales_per_sq_foot#3608, feb_sales_per_sq_foot#3609, mar_sales_per_sq_foot#3610, apr_sales_per_sq_foot#3611, may_sales_per_sq_foot#3612, jun_sales_per_sq_foot#3613, jul_sales_per_sq_foot#3614, aug_sales_per_sq_foot#3615, sep_sales_per_sq_foot#3616, oct_sales_per_sq_foot#3617, nov_sales_per_sq_foot#3618, dec_sales_per_sq_foot#3619, jan_net#3620, feb_net#3621, mar_net#3622, apr_net#3623, may_net#3624, jun_net#3625, jul_net#3626, aug_net#3627, sep_net#3628, oct_net#3629, nov_net#3630, dec_net#3631)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _w_warehouse_name497_n = tbl_LocalLimit_TD_137350_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_04967_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _w_warehouse_name497_n);
        tbl_GlobalLimit_TD_04967_output.setInt32(r, 1, tbl_LocalLimit_TD_137350_output.getInt32(i, 1));
        std::array<char, TPCDS_READ_MAX + 1> _w_city503_n = tbl_LocalLimit_TD_137350_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_GlobalLimit_TD_04967_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _w_city503_n);
        std::array<char, TPCDS_READ_MAX + 1> _w_county504_n = tbl_LocalLimit_TD_137350_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_GlobalLimit_TD_04967_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _w_county504_n);
        std::array<char, TPCDS_READ_MAX + 1> _w_state505_n = tbl_LocalLimit_TD_137350_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        tbl_GlobalLimit_TD_04967_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _w_state505_n);
        std::array<char, TPCDS_READ_MAX + 1> _w_country507_n = tbl_LocalLimit_TD_137350_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        tbl_GlobalLimit_TD_04967_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _w_country507_n);
        std::array<char, TPCDS_READ_MAX + 1> _ship_carriers3544_n = tbl_LocalLimit_TD_137350_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        tbl_GlobalLimit_TD_04967_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _ship_carriers3544_n);
        tbl_GlobalLimit_TD_04967_output.setInt32(r, 7, tbl_LocalLimit_TD_137350_output.getInt32(i, 7));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 8, tbl_LocalLimit_TD_137350_output.getInt64(i, 8));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 9, tbl_LocalLimit_TD_137350_output.getInt64(i, 9));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 10, tbl_LocalLimit_TD_137350_output.getInt64(i, 10));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 11, tbl_LocalLimit_TD_137350_output.getInt64(i, 11));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 12, tbl_LocalLimit_TD_137350_output.getInt64(i, 12));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 13, tbl_LocalLimit_TD_137350_output.getInt64(i, 13));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 14, tbl_LocalLimit_TD_137350_output.getInt64(i, 14));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 15, tbl_LocalLimit_TD_137350_output.getInt64(i, 15));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 16, tbl_LocalLimit_TD_137350_output.getInt64(i, 16));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 17, tbl_LocalLimit_TD_137350_output.getInt64(i, 17));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 18, tbl_LocalLimit_TD_137350_output.getInt64(i, 18));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 19, tbl_LocalLimit_TD_137350_output.getInt64(i, 19));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 20, tbl_LocalLimit_TD_137350_output.getInt64(i, 20));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 21, tbl_LocalLimit_TD_137350_output.getInt64(i, 21));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 22, tbl_LocalLimit_TD_137350_output.getInt64(i, 22));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 23, tbl_LocalLimit_TD_137350_output.getInt64(i, 23));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 24, tbl_LocalLimit_TD_137350_output.getInt64(i, 24));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 25, tbl_LocalLimit_TD_137350_output.getInt64(i, 25));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 26, tbl_LocalLimit_TD_137350_output.getInt64(i, 26));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 27, tbl_LocalLimit_TD_137350_output.getInt64(i, 27));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 28, tbl_LocalLimit_TD_137350_output.getInt64(i, 28));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 29, tbl_LocalLimit_TD_137350_output.getInt64(i, 29));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 30, tbl_LocalLimit_TD_137350_output.getInt64(i, 30));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 31, tbl_LocalLimit_TD_137350_output.getInt64(i, 31));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 32, tbl_LocalLimit_TD_137350_output.getInt64(i, 32));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 33, tbl_LocalLimit_TD_137350_output.getInt64(i, 33));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 34, tbl_LocalLimit_TD_137350_output.getInt64(i, 34));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 35, tbl_LocalLimit_TD_137350_output.getInt64(i, 35));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 36, tbl_LocalLimit_TD_137350_output.getInt64(i, 36));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 37, tbl_LocalLimit_TD_137350_output.getInt64(i, 37));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 38, tbl_LocalLimit_TD_137350_output.getInt64(i, 38));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 39, tbl_LocalLimit_TD_137350_output.getInt64(i, 39));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 40, tbl_LocalLimit_TD_137350_output.getInt64(i, 40));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 41, tbl_LocalLimit_TD_137350_output.getInt64(i, 41));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 42, tbl_LocalLimit_TD_137350_output.getInt64(i, 42));
        tbl_GlobalLimit_TD_04967_output.setInt64(r, 43, tbl_LocalLimit_TD_137350_output.getInt64(i, 43));
        r++;
    }
    tbl_GlobalLimit_TD_04967_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_04967_output #Row: " << tbl_GlobalLimit_TD_04967_output.getNumRow() << std::endl;
}

