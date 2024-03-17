#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_1197701(Table &tbl_SerializeFromObject_TD_12116079_input, Table &tbl_Filter_TD_1197701_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(sr_customer_sk#672) AND isnotnull(sr_item_sk#671)) AND isnotnull(sr_ticket_number#678L)) AND isnotnull(sr_returned_date_sk#669)))
    // Input: ListBuffer(sr_returned_date_sk#669, sr_item_sk#671, sr_customer_sk#672, sr_ticket_number#678L, sr_return_quantity#679)
    // Output: ListBuffer(sr_returned_date_sk#669, sr_item_sk#671, sr_customer_sk#672, sr_ticket_number#678L, sr_return_quantity#679)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12116079_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _sr_customer_sk672 = tbl_SerializeFromObject_TD_12116079_input.getInt32(i, 2);
        int32_t _sr_item_sk671 = tbl_SerializeFromObject_TD_12116079_input.getInt32(i, 1);
        int64_t _sr_ticket_number678L = tbl_SerializeFromObject_TD_12116079_input.getInt64(i, 3);
        int32_t _sr_returned_date_sk669 = tbl_SerializeFromObject_TD_12116079_input.getInt32(i, 0);
        if ((((_sr_customer_sk672!= 0) && (_sr_item_sk671!= 0)) && (_sr_ticket_number678L!= 0)) && (_sr_returned_date_sk669!= 0)) {
            int32_t _sr_returned_date_sk669_t = tbl_SerializeFromObject_TD_12116079_input.getInt32(i, 0);
            tbl_Filter_TD_1197701_output.setInt32(r, 0, _sr_returned_date_sk669_t);
            int32_t _sr_item_sk671_t = tbl_SerializeFromObject_TD_12116079_input.getInt32(i, 1);
            tbl_Filter_TD_1197701_output.setInt32(r, 1, _sr_item_sk671_t);
            int32_t _sr_customer_sk672_t = tbl_SerializeFromObject_TD_12116079_input.getInt32(i, 2);
            tbl_Filter_TD_1197701_output.setInt32(r, 2, _sr_customer_sk672_t);
            int64_t _sr_ticket_number678L_t = tbl_SerializeFromObject_TD_12116079_input.getInt64(i, 3);
            tbl_Filter_TD_1197701_output.setInt64(r, 3, _sr_ticket_number678L_t);
            int32_t _sr_return_quantity679_t = tbl_SerializeFromObject_TD_12116079_input.getInt32(i, 4);
            tbl_Filter_TD_1197701_output.setInt32(r, 4, _sr_return_quantity679_t);
            r++;
        }
    }
    tbl_Filter_TD_1197701_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1197701_output #Row: " << tbl_Filter_TD_1197701_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11489820(Table &tbl_SerializeFromObject_TD_12301244_input, Table &tbl_Filter_TD_11489820_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(ss_customer_sk#1209) AND isnotnull(ss_item_sk#1208)) AND isnotnull(ss_ticket_number#1215L)) AND (isnotnull(ss_sold_date_sk#1206) AND isnotnull(ss_store_sk#1213))))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209, ss_store_sk#1213, ss_ticket_number#1215L, ss_quantity#1216)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209, ss_store_sk#1213, ss_ticket_number#1215L, ss_quantity#1216)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12301244_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_customer_sk1209 = tbl_SerializeFromObject_TD_12301244_input.getInt32(i, 2);
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_12301244_input.getInt32(i, 1);
        int64_t _ss_ticket_number1215L = tbl_SerializeFromObject_TD_12301244_input.getInt64(i, 4);
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_12301244_input.getInt32(i, 0);
        int32_t _ss_store_sk1213 = tbl_SerializeFromObject_TD_12301244_input.getInt32(i, 3);
        if ((((_ss_customer_sk1209!= 0) && (_ss_item_sk1208!= 0)) && (_ss_ticket_number1215L!= 0)) && ((_ss_sold_date_sk1206!= 0) && (_ss_store_sk1213!= 0))) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_12301244_input.getInt32(i, 0);
            tbl_Filter_TD_11489820_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_12301244_input.getInt32(i, 1);
            tbl_Filter_TD_11489820_output.setInt32(r, 1, _ss_item_sk1208_t);
            int32_t _ss_customer_sk1209_t = tbl_SerializeFromObject_TD_12301244_input.getInt32(i, 2);
            tbl_Filter_TD_11489820_output.setInt32(r, 2, _ss_customer_sk1209_t);
            int32_t _ss_store_sk1213_t = tbl_SerializeFromObject_TD_12301244_input.getInt32(i, 3);
            tbl_Filter_TD_11489820_output.setInt32(r, 3, _ss_store_sk1213_t);
            int64_t _ss_ticket_number1215L_t = tbl_SerializeFromObject_TD_12301244_input.getInt64(i, 4);
            tbl_Filter_TD_11489820_output.setInt64(r, 4, _ss_ticket_number1215L_t);
            int32_t _ss_quantity1216_t = tbl_SerializeFromObject_TD_12301244_input.getInt32(i, 5);
            tbl_Filter_TD_11489820_output.setInt32(r, 5, _ss_quantity1216_t);
            r++;
        }
    }
    tbl_Filter_TD_11489820_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11489820_output #Row: " << tbl_Filter_TD_11489820_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10109488(Table &tbl_SerializeFromObject_TD_11247689_input, Table &tbl_Filter_TD_10109488_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(cs_bill_customer_sk#1107) AND isnotnull(cs_item_sk#1119)) AND isnotnull(cs_sold_date_sk#1104)))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_item_sk#1119, cs_quantity#1122)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_item_sk#1119, cs_quantity#1122)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11247689_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_bill_customer_sk1107 = tbl_SerializeFromObject_TD_11247689_input.getInt32(i, 1);
        int32_t _cs_item_sk1119 = tbl_SerializeFromObject_TD_11247689_input.getInt32(i, 2);
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_11247689_input.getInt32(i, 0);
        if (((_cs_bill_customer_sk1107!= 0) && (_cs_item_sk1119!= 0)) && (_cs_sold_date_sk1104!= 0)) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_11247689_input.getInt32(i, 0);
            tbl_Filter_TD_10109488_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int32_t _cs_bill_customer_sk1107_t = tbl_SerializeFromObject_TD_11247689_input.getInt32(i, 1);
            tbl_Filter_TD_10109488_output.setInt32(r, 1, _cs_bill_customer_sk1107_t);
            int32_t _cs_item_sk1119_t = tbl_SerializeFromObject_TD_11247689_input.getInt32(i, 2);
            tbl_Filter_TD_10109488_output.setInt32(r, 2, _cs_item_sk1119_t);
            int32_t _cs_quantity1122_t = tbl_SerializeFromObject_TD_11247689_input.getInt32(i, 3);
            tbl_Filter_TD_10109488_output.setInt32(r, 3, _cs_quantity1122_t);
            r++;
        }
    }
    tbl_Filter_TD_10109488_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10109488_output #Row: " << tbl_Filter_TD_10109488_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_10202533_key_leftMajor {
    int32_t _ss_customer_sk1209;
    int32_t _ss_item_sk1208;
    int64_t _ss_ticket_number1215L;
    bool operator==(const SW_JOIN_INNER_TD_10202533_key_leftMajor& other) const {
        return ((_ss_customer_sk1209 == other._ss_customer_sk1209) && (_ss_item_sk1208 == other._ss_item_sk1208) && (_ss_ticket_number1215L == other._ss_ticket_number1215L));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10202533_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10202533_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_customer_sk1209)) + (hash<int32_t>()(k._ss_item_sk1208)) + (hash<int64_t>()(k._ss_ticket_number1215L));
    }
};
}
struct SW_JOIN_INNER_TD_10202533_payload_leftMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_item_sk1208;
    int32_t _ss_customer_sk1209;
    int32_t _ss_store_sk1213;
    int64_t _ss_ticket_number1215L;
    int32_t _ss_quantity1216;
};
struct SW_JOIN_INNER_TD_10202533_key_rightMajor {
    int32_t _sr_customer_sk672;
    int32_t _sr_item_sk671;
    int64_t _sr_ticket_number678L;
    bool operator==(const SW_JOIN_INNER_TD_10202533_key_rightMajor& other) const {
        return ((_sr_customer_sk672 == other._sr_customer_sk672) && (_sr_item_sk671 == other._sr_item_sk671) && (_sr_ticket_number678L == other._sr_ticket_number678L));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10202533_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10202533_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._sr_customer_sk672)) + (hash<int32_t>()(k._sr_item_sk671)) + (hash<int64_t>()(k._sr_ticket_number678L));
    }
};
}
struct SW_JOIN_INNER_TD_10202533_payload_rightMajor {
    int32_t _sr_returned_date_sk669;
    int32_t _sr_item_sk671;
    int32_t _sr_customer_sk672;
    int64_t _sr_ticket_number678L;
    int32_t _sr_return_quantity679;
};
void SW_JOIN_INNER_TD_10202533(Table &tbl_Filter_TD_11489820_output, Table &tbl_Filter_TD_1197701_output, Table &tbl_JOIN_INNER_TD_10202533_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((((ss_customer_sk#1209 = sr_customer_sk#672) AND (ss_item_sk#1208 = sr_item_sk#671)) AND (ss_ticket_number#1215L = sr_ticket_number#678L)))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209, ss_store_sk#1213, ss_ticket_number#1215L, ss_quantity#1216)
    // Right Table: ListBuffer(sr_returned_date_sk#669, sr_item_sk#671, sr_customer_sk#672, sr_ticket_number#678L, sr_return_quantity#679)
    // Output Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_store_sk#1213, ss_quantity#1216, sr_returned_date_sk#669, sr_item_sk#671, sr_customer_sk#672, sr_return_quantity#679)
    int left_nrow = tbl_Filter_TD_11489820_output.getNumRow();
    int right_nrow = tbl_Filter_TD_1197701_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10202533_key_leftMajor, SW_JOIN_INNER_TD_10202533_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_11489820_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_customer_sk1209_k = tbl_Filter_TD_11489820_output.getInt32(i, 2);
            int32_t _ss_item_sk1208_k = tbl_Filter_TD_11489820_output.getInt32(i, 1);
            int64_t _ss_ticket_number1215L_k = tbl_Filter_TD_11489820_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_10202533_key_leftMajor keyA{_ss_customer_sk1209_k, _ss_item_sk1208_k, _ss_ticket_number1215L_k};
            int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_11489820_output.getInt32(i, 0);
            int32_t _ss_item_sk1208 = tbl_Filter_TD_11489820_output.getInt32(i, 1);
            int32_t _ss_customer_sk1209 = tbl_Filter_TD_11489820_output.getInt32(i, 2);
            int32_t _ss_store_sk1213 = tbl_Filter_TD_11489820_output.getInt32(i, 3);
            int64_t _ss_ticket_number1215L = tbl_Filter_TD_11489820_output.getInt64(i, 4);
            int32_t _ss_quantity1216 = tbl_Filter_TD_11489820_output.getInt32(i, 5);
            SW_JOIN_INNER_TD_10202533_payload_leftMajor payloadA{_ss_sold_date_sk1206, _ss_item_sk1208, _ss_customer_sk1209, _ss_store_sk1213, _ss_ticket_number1215L, _ss_quantity1216};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_1197701_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _sr_customer_sk672_k = tbl_Filter_TD_1197701_output.getInt32(i, 2);
            int32_t _sr_item_sk671_k = tbl_Filter_TD_1197701_output.getInt32(i, 1);
            int64_t _sr_ticket_number678L_k = tbl_Filter_TD_1197701_output.getInt64(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10202533_key_leftMajor{_sr_customer_sk672_k, _sr_item_sk671_k, _sr_ticket_number678L_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                int32_t _ss_store_sk1213 = (it->second)._ss_store_sk1213;
                int64_t _ss_ticket_number1215L = (it->second)._ss_ticket_number1215L;
                int32_t _ss_quantity1216 = (it->second)._ss_quantity1216;
                int32_t _sr_returned_date_sk669 = tbl_Filter_TD_1197701_output.getInt32(i, 0);
                int32_t _sr_item_sk671 = tbl_Filter_TD_1197701_output.getInt32(i, 1);
                int32_t _sr_customer_sk672 = tbl_Filter_TD_1197701_output.getInt32(i, 2);
                int64_t _sr_ticket_number678L = tbl_Filter_TD_1197701_output.getInt64(i, 3);
                int32_t _sr_return_quantity679 = tbl_Filter_TD_1197701_output.getInt32(i, 4);
                tbl_JOIN_INNER_TD_10202533_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_10202533_output.setInt32(r, 1, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_10202533_output.setInt32(r, 2, _ss_store_sk1213);
                tbl_JOIN_INNER_TD_10202533_output.setInt32(r, 3, _ss_quantity1216);
                tbl_JOIN_INNER_TD_10202533_output.setInt32(r, 4, _sr_returned_date_sk669);
                tbl_JOIN_INNER_TD_10202533_output.setInt32(r, 5, _sr_item_sk671);
                tbl_JOIN_INNER_TD_10202533_output.setInt32(r, 6, _sr_customer_sk672);
                tbl_JOIN_INNER_TD_10202533_output.setInt32(r, 7, _sr_return_quantity679);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10202533_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10202533_key_rightMajor, SW_JOIN_INNER_TD_10202533_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_1197701_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _sr_customer_sk672_k = tbl_Filter_TD_1197701_output.getInt32(i, 2);
            int32_t _sr_item_sk671_k = tbl_Filter_TD_1197701_output.getInt32(i, 1);
            int64_t _sr_ticket_number678L_k = tbl_Filter_TD_1197701_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_10202533_key_rightMajor keyA{_sr_customer_sk672_k, _sr_item_sk671_k, _sr_ticket_number678L_k};
            int32_t _sr_returned_date_sk669 = tbl_Filter_TD_1197701_output.getInt32(i, 0);
            int32_t _sr_item_sk671 = tbl_Filter_TD_1197701_output.getInt32(i, 1);
            int32_t _sr_customer_sk672 = tbl_Filter_TD_1197701_output.getInt32(i, 2);
            int64_t _sr_ticket_number678L = tbl_Filter_TD_1197701_output.getInt64(i, 3);
            int32_t _sr_return_quantity679 = tbl_Filter_TD_1197701_output.getInt32(i, 4);
            SW_JOIN_INNER_TD_10202533_payload_rightMajor payloadA{_sr_returned_date_sk669, _sr_item_sk671, _sr_customer_sk672, _sr_ticket_number678L, _sr_return_quantity679};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_11489820_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_customer_sk1209_k = tbl_Filter_TD_11489820_output.getInt32(i, 2);
            int32_t _ss_item_sk1208_k = tbl_Filter_TD_11489820_output.getInt32(i, 1);
            int64_t _ss_ticket_number1215L_k = tbl_Filter_TD_11489820_output.getInt64(i, 4);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10202533_key_rightMajor{_ss_customer_sk1209_k, _ss_item_sk1208_k, _ss_ticket_number1215L_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _sr_returned_date_sk669 = (it->second)._sr_returned_date_sk669;
                int32_t _sr_item_sk671 = (it->second)._sr_item_sk671;
                int32_t _sr_customer_sk672 = (it->second)._sr_customer_sk672;
                int64_t _sr_ticket_number678L = (it->second)._sr_ticket_number678L;
                int32_t _sr_return_quantity679 = (it->second)._sr_return_quantity679;
                int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_11489820_output.getInt32(i, 0);
                int32_t _ss_item_sk1208 = tbl_Filter_TD_11489820_output.getInt32(i, 1);
                int32_t _ss_customer_sk1209 = tbl_Filter_TD_11489820_output.getInt32(i, 2);
                int32_t _ss_store_sk1213 = tbl_Filter_TD_11489820_output.getInt32(i, 3);
                int64_t _ss_ticket_number1215L = tbl_Filter_TD_11489820_output.getInt64(i, 4);
                int32_t _ss_quantity1216 = tbl_Filter_TD_11489820_output.getInt32(i, 5);
                tbl_JOIN_INNER_TD_10202533_output.setInt32(r, 4, _sr_returned_date_sk669);
                tbl_JOIN_INNER_TD_10202533_output.setInt32(r, 5, _sr_item_sk671);
                tbl_JOIN_INNER_TD_10202533_output.setInt32(r, 6, _sr_customer_sk672);
                tbl_JOIN_INNER_TD_10202533_output.setInt32(r, 7, _sr_return_quantity679);
                tbl_JOIN_INNER_TD_10202533_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_10202533_output.setInt32(r, 1, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_10202533_output.setInt32(r, 2, _ss_store_sk1213);
                tbl_JOIN_INNER_TD_10202533_output.setInt32(r, 3, _ss_quantity1216);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10202533_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_10202533_output #Row: " << tbl_JOIN_INNER_TD_10202533_output.getNumRow() << std::endl;
}

void SW_Filter_TD_911781(Table &tbl_SerializeFromObject_TD_10502506_input, Table &tbl_Filter_TD_911781_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_quarter_name#135) AND (d_quarter_name#135 = 2001Q1)) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_quarter_name#135)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10502506_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _d_quarter_name135 = tbl_SerializeFromObject_TD_10502506_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_10502506_input.getInt32(i, 0);
        if ((_d_quarter_name135.data() != "NULL" && (std::string(_d_quarter_name135.data()) == "2001Q1")) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_10502506_input.getInt32(i, 0);
            tbl_Filter_TD_911781_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_911781_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_911781_output #Row: " << tbl_Filter_TD_911781_output.getNumRow() << std::endl;
}


void SW_Filter_TD_8850597(Table &tbl_SerializeFromObject_TD_9557744_input, Table &tbl_Filter_TD_8850597_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((d_quarter_name#3565 IN (2001Q1,2001Q2,2001Q3) AND isnotnull(d_date_sk#3550)))
    // Input: ListBuffer(d_date_sk#3550, d_quarter_name#3565)
    // Output: ListBuffer(d_date_sk#3550)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9557744_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _d_quarter_name3565 = tbl_SerializeFromObject_TD_9557744_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _d_date_sk3550 = tbl_SerializeFromObject_TD_9557744_input.getInt32(i, 0);
        auto reuse_col_str_774 = std::string(_d_quarter_name3565.data());
        if (((reuse_col_str_774 == "2001Q1") || (reuse_col_str_774 == "2001Q2") || (reuse_col_str_774 == "2001Q3") || (0)) && (_d_date_sk3550!= 0)) {
            int32_t _d_date_sk3550_t = tbl_SerializeFromObject_TD_9557744_input.getInt32(i, 0);
            tbl_Filter_TD_8850597_output.setInt32(r, 0, _d_date_sk3550_t);
            r++;
        }
    }
    tbl_Filter_TD_8850597_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8850597_output #Row: " << tbl_Filter_TD_8850597_output.getNumRow() << std::endl;
}


void SW_Filter_TD_7232045(Table &tbl_SerializeFromObject_TD_8296782_input, Table &tbl_Filter_TD_7232045_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((d_quarter_name#3593 IN (2001Q1,2001Q2,2001Q3) AND isnotnull(d_date_sk#3578)))
    // Input: ListBuffer(d_date_sk#3578, d_quarter_name#3593)
    // Output: ListBuffer(d_date_sk#3578)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8296782_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _d_quarter_name3593 = tbl_SerializeFromObject_TD_8296782_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _d_date_sk3578 = tbl_SerializeFromObject_TD_8296782_input.getInt32(i, 0);
        auto reuse_col_str_871 = std::string(_d_quarter_name3593.data());
        if (((reuse_col_str_871 == "2001Q1") || (reuse_col_str_871 == "2001Q2") || (reuse_col_str_871 == "2001Q3") || (0)) && (_d_date_sk3578!= 0)) {
            int32_t _d_date_sk3578_t = tbl_SerializeFromObject_TD_8296782_input.getInt32(i, 0);
            tbl_Filter_TD_7232045_output.setInt32(r, 0, _d_date_sk3578_t);
            r++;
        }
    }
    tbl_Filter_TD_7232045_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7232045_output #Row: " << tbl_Filter_TD_7232045_output.getNumRow() << std::endl;
}


void SW_Filter_TD_631201(Table &tbl_SerializeFromObject_TD_7400112_input, Table &tbl_Filter_TD_631201_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(s_store_sk#378))
    // Input: ListBuffer(s_store_sk#378, s_state#402)
    // Output: ListBuffer(s_store_sk#378, s_state#402)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7400112_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _s_store_sk378 = tbl_SerializeFromObject_TD_7400112_input.getInt32(i, 0);
        if (_s_store_sk378!= 0) {
            int32_t _s_store_sk378_t = tbl_SerializeFromObject_TD_7400112_input.getInt32(i, 0);
            tbl_Filter_TD_631201_output.setInt32(r, 0, _s_store_sk378_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_state402_t = tbl_SerializeFromObject_TD_7400112_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_631201_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_state402_t);
            r++;
        }
    }
    tbl_Filter_TD_631201_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_631201_output #Row: " << tbl_Filter_TD_631201_output.getNumRow() << std::endl;
}


void SW_Filter_TD_5707128(Table &tbl_SerializeFromObject_TD_6408587_input, Table &tbl_Filter_TD_5707128_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#228))
    // Input: ListBuffer(i_item_sk#228, i_item_id#229, i_item_desc#232)
    // Output: ListBuffer(i_item_sk#228, i_item_id#229, i_item_desc#232)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6408587_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_6408587_input.getInt32(i, 0);
        if (_i_item_sk228!= 0) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_6408587_input.getInt32(i, 0);
            tbl_Filter_TD_5707128_output.setInt32(r, 0, _i_item_sk228_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_t = tbl_SerializeFromObject_TD_6408587_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_5707128_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id229_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_t = tbl_SerializeFromObject_TD_6408587_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_5707128_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_item_desc232_t);
            r++;
        }
    }
    tbl_Filter_TD_5707128_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5707128_output #Row: " << tbl_Filter_TD_5707128_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5192827_key_leftMajor {
    int32_t _ss_store_sk1213;
    bool operator==(const SW_JOIN_INNER_TD_5192827_key_leftMajor& other) const {
        return ((_ss_store_sk1213 == other._ss_store_sk1213));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5192827_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5192827_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_store_sk1213));
    }
};
}
struct SW_JOIN_INNER_TD_5192827_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int32_t _ss_store_sk1213;
    int32_t _ss_quantity1216;
    int32_t _sr_return_quantity679;
    int32_t _cs_quantity1122;
};
struct SW_JOIN_INNER_TD_5192827_key_rightMajor {
    int32_t _s_store_sk378;
    bool operator==(const SW_JOIN_INNER_TD_5192827_key_rightMajor& other) const {
        return ((_s_store_sk378 == other._s_store_sk378));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5192827_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5192827_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_store_sk378));
    }
};
}
struct SW_JOIN_INNER_TD_5192827_payload_rightMajor {
    int32_t _s_store_sk378;
    std::string _s_state402;
};
void SW_JOIN_INNER_TD_5192827(Table &tbl_JOIN_INNER_TD_6555791_output, Table &tbl_Filter_TD_631201_output, Table &tbl_JOIN_INNER_TD_5192827_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((s_store_sk#378 = ss_store_sk#1213))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_store_sk#1213, ss_quantity#1216, sr_return_quantity#679, cs_quantity#1122)
    // Right Table: ListBuffer(s_store_sk#378, s_state#402)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_quantity#1216, sr_return_quantity#679, cs_quantity#1122, s_state#402)
    int left_nrow = tbl_JOIN_INNER_TD_6555791_output.getNumRow();
    int right_nrow = tbl_Filter_TD_631201_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5192827_key_leftMajor, SW_JOIN_INNER_TD_5192827_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_6555791_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_store_sk1213_k = tbl_JOIN_INNER_TD_6555791_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_5192827_key_leftMajor keyA{_ss_store_sk1213_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_6555791_output.getInt32(i, 0);
            int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_6555791_output.getInt32(i, 1);
            int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_6555791_output.getInt32(i, 2);
            int32_t _sr_return_quantity679 = tbl_JOIN_INNER_TD_6555791_output.getInt32(i, 3);
            int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_6555791_output.getInt32(i, 4);
            SW_JOIN_INNER_TD_5192827_payload_leftMajor payloadA{_ss_item_sk1208, _ss_store_sk1213, _ss_quantity1216, _sr_return_quantity679, _cs_quantity1122};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_631201_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_631201_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5192827_key_leftMajor{_s_store_sk378_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_store_sk1213 = (it->second)._ss_store_sk1213;
                int32_t _ss_quantity1216 = (it->second)._ss_quantity1216;
                int32_t _sr_return_quantity679 = (it->second)._sr_return_quantity679;
                int32_t _cs_quantity1122 = (it->second)._cs_quantity1122;
                int32_t _s_store_sk378 = tbl_Filter_TD_631201_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _s_state402_n = tbl_Filter_TD_631201_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _s_state402 = std::string(_s_state402_n.data());
                tbl_JOIN_INNER_TD_5192827_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_5192827_output.setInt32(r, 1, _ss_quantity1216);
                tbl_JOIN_INNER_TD_5192827_output.setInt32(r, 2, _sr_return_quantity679);
                tbl_JOIN_INNER_TD_5192827_output.setInt32(r, 3, _cs_quantity1122);
                tbl_JOIN_INNER_TD_5192827_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _s_state402_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5192827_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5192827_key_rightMajor, SW_JOIN_INNER_TD_5192827_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_631201_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_631201_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5192827_key_rightMajor keyA{_s_store_sk378_k};
            int32_t _s_store_sk378 = tbl_Filter_TD_631201_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _s_state402_n = tbl_Filter_TD_631201_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _s_state402 = std::string(_s_state402_n.data());
            SW_JOIN_INNER_TD_5192827_payload_rightMajor payloadA{_s_store_sk378, _s_state402};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_6555791_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_store_sk1213_k = tbl_JOIN_INNER_TD_6555791_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5192827_key_rightMajor{_ss_store_sk1213_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _s_store_sk378 = (it->second)._s_store_sk378;
                std::string _s_state402 = (it->second)._s_state402;
                std::array<char, TPCDS_READ_MAX + 1> _s_state402_n{};
                memcpy(_s_state402_n.data(), (_s_state402).data(), (_s_state402).length());
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_6555791_output.getInt32(i, 0);
                int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_6555791_output.getInt32(i, 1);
                int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_6555791_output.getInt32(i, 2);
                int32_t _sr_return_quantity679 = tbl_JOIN_INNER_TD_6555791_output.getInt32(i, 3);
                int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_6555791_output.getInt32(i, 4);
                tbl_JOIN_INNER_TD_5192827_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _s_state402_n);
                tbl_JOIN_INNER_TD_5192827_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_5192827_output.setInt32(r, 1, _ss_quantity1216);
                tbl_JOIN_INNER_TD_5192827_output.setInt32(r, 2, _sr_return_quantity679);
                tbl_JOIN_INNER_TD_5192827_output.setInt32(r, 3, _cs_quantity1122);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5192827_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5192827_output #Row: " << tbl_JOIN_INNER_TD_5192827_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4457812_key_leftMajor {
    int32_t _ss_item_sk1208;
    bool operator==(const SW_JOIN_INNER_TD_4457812_key_leftMajor& other) const {
        return ((_ss_item_sk1208 == other._ss_item_sk1208));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4457812_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4457812_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk1208));
    }
};
}
struct SW_JOIN_INNER_TD_4457812_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int32_t _ss_quantity1216;
    int32_t _sr_return_quantity679;
    int32_t _cs_quantity1122;
    std::string _s_state402;
};
struct SW_JOIN_INNER_TD_4457812_key_rightMajor {
    int32_t _i_item_sk228;
    bool operator==(const SW_JOIN_INNER_TD_4457812_key_rightMajor& other) const {
        return ((_i_item_sk228 == other._i_item_sk228));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4457812_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4457812_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk228));
    }
};
}
struct SW_JOIN_INNER_TD_4457812_payload_rightMajor {
    int32_t _i_item_sk228;
    std::string _i_item_id229;
    std::string _i_item_desc232;
};
void SW_JOIN_INNER_TD_4457812(Table &tbl_JOIN_INNER_TD_5192827_output, Table &tbl_Filter_TD_5707128_output, Table &tbl_JOIN_INNER_TD_4457812_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((i_item_sk#228 = ss_item_sk#1208))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_quantity#1216, sr_return_quantity#679, cs_quantity#1122, s_state#402)
    // Right Table: ListBuffer(i_item_sk#228, i_item_id#229, i_item_desc#232)
    // Output Table: ListBuffer(ss_quantity#1216, sr_return_quantity#679, cs_quantity#1122, s_state#402, i_item_id#229, i_item_desc#232)
    int left_nrow = tbl_JOIN_INNER_TD_5192827_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5707128_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4457812_key_leftMajor, SW_JOIN_INNER_TD_4457812_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_5192827_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_5192827_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4457812_key_leftMajor keyA{_ss_item_sk1208_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_5192827_output.getInt32(i, 0);
            int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_5192827_output.getInt32(i, 1);
            int32_t _sr_return_quantity679 = tbl_JOIN_INNER_TD_5192827_output.getInt32(i, 2);
            int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_5192827_output.getInt32(i, 3);
            std::array<char, TPCDS_READ_MAX + 1> _s_state402_n = tbl_JOIN_INNER_TD_5192827_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _s_state402 = std::string(_s_state402_n.data());
            SW_JOIN_INNER_TD_4457812_payload_leftMajor payloadA{_ss_item_sk1208, _ss_quantity1216, _sr_return_quantity679, _cs_quantity1122, _s_state402};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5707128_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_5707128_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4457812_key_leftMajor{_i_item_sk228_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_quantity1216 = (it->second)._ss_quantity1216;
                int32_t _sr_return_quantity679 = (it->second)._sr_return_quantity679;
                int32_t _cs_quantity1122 = (it->second)._cs_quantity1122;
                std::string _s_state402 = (it->second)._s_state402;
                std::array<char, TPCDS_READ_MAX + 1> _s_state402_n{};
                memcpy(_s_state402_n.data(), (_s_state402).data(), (_s_state402).length());
                int32_t _i_item_sk228 = tbl_Filter_TD_5707128_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_Filter_TD_5707128_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_item_id229 = std::string(_i_item_id229_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n = tbl_Filter_TD_5707128_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _i_item_desc232 = std::string(_i_item_desc232_n.data());
                tbl_JOIN_INNER_TD_4457812_output.setInt32(r, 0, _ss_quantity1216);
                tbl_JOIN_INNER_TD_4457812_output.setInt32(r, 1, _sr_return_quantity679);
                tbl_JOIN_INNER_TD_4457812_output.setInt32(r, 2, _cs_quantity1122);
                tbl_JOIN_INNER_TD_4457812_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _s_state402_n);
                tbl_JOIN_INNER_TD_4457812_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _i_item_id229_n);
                tbl_JOIN_INNER_TD_4457812_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _i_item_desc232_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4457812_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4457812_key_rightMajor, SW_JOIN_INNER_TD_4457812_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5707128_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_5707128_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4457812_key_rightMajor keyA{_i_item_sk228_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_5707128_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_Filter_TD_5707128_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_item_id229 = std::string(_i_item_id229_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n = tbl_Filter_TD_5707128_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _i_item_desc232 = std::string(_i_item_desc232_n.data());
            SW_JOIN_INNER_TD_4457812_payload_rightMajor payloadA{_i_item_sk228, _i_item_id229, _i_item_desc232};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_5192827_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_5192827_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4457812_key_rightMajor{_ss_item_sk1208_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                std::string _i_item_id229 = (it->second)._i_item_id229;
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n{};
                memcpy(_i_item_id229_n.data(), (_i_item_id229).data(), (_i_item_id229).length());
                std::string _i_item_desc232 = (it->second)._i_item_desc232;
                std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n{};
                memcpy(_i_item_desc232_n.data(), (_i_item_desc232).data(), (_i_item_desc232).length());
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_5192827_output.getInt32(i, 0);
                int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_5192827_output.getInt32(i, 1);
                int32_t _sr_return_quantity679 = tbl_JOIN_INNER_TD_5192827_output.getInt32(i, 2);
                int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_5192827_output.getInt32(i, 3);
                std::array<char, TPCDS_READ_MAX + 1> _s_state402_n = tbl_JOIN_INNER_TD_5192827_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _s_state402 = std::string(_s_state402_n.data());
                tbl_JOIN_INNER_TD_4457812_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _i_item_id229_n);
                tbl_JOIN_INNER_TD_4457812_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _i_item_desc232_n);
                tbl_JOIN_INNER_TD_4457812_output.setInt32(r, 0, _ss_quantity1216);
                tbl_JOIN_INNER_TD_4457812_output.setInt32(r, 1, _sr_return_quantity679);
                tbl_JOIN_INNER_TD_4457812_output.setInt32(r, 2, _cs_quantity1122);
                tbl_JOIN_INNER_TD_4457812_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _s_state402_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4457812_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4457812_output #Row: " << tbl_JOIN_INNER_TD_4457812_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_339190_key {
    std::string _i_item_id229;
    std::string _i_item_desc232;
    std::string _s_state402;
    bool operator==(const SW_Aggregate_TD_339190_key& other) const { return (_i_item_id229 == other._i_item_id229) && (_i_item_desc232 == other._i_item_desc232) && (_s_state402 == other._s_state402); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_339190_key> {
    std::size_t operator() (const SW_Aggregate_TD_339190_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_item_id229)) + (hash<string>()(k._i_item_desc232)) + (hash<string>()(k._s_state402));
    }
};
}
struct SW_Aggregate_TD_339190_payload {
    int64_t _store_sales_quantitycount3544L_count_0;
    int64_t _store_sales_quantityave3545_avg_1;
    int64_t _as_store_returns_quantitycount3546L_count_2;
    int64_t _as_store_returns_quantityave3547_avg_3;
    int64_t _catalog_sales_quantitycount3548L_count_4;
    int64_t _catalog_sales_quantityave3549_avg_5;
};
void SW_Aggregate_TD_339190(Table &tbl_JOIN_INNER_TD_4457812_output, Table &tbl_Aggregate_TD_339190_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(i_item_id#229, i_item_desc#232, s_state#402, count(ss_quantity#1216) AS store_sales_quantitycount#3544L, avg(ss_quantity#1216) AS store_sales_quantityave#3545, count(sr_return_quantity#679) AS as_store_returns_quantitycount#3546L, avg(sr_return_quantity#679) AS as_store_returns_quantityave#3547, count(cs_quantity#1122) AS catalog_sales_quantitycount#3548L, avg(cs_quantity#1122) AS catalog_sales_quantityave#3549)
    // Input: ListBuffer(ss_quantity#1216, sr_return_quantity#679, cs_quantity#1122, s_state#402, i_item_id#229, i_item_desc#232)
    // Output: ListBuffer(i_item_id#229, i_item_desc#232, s_state#402, store_sales_quantitycount#3544L, store_sales_quantityave#3545, as_store_returns_quantitycount#3546L, as_store_returns_quantityave#3547, catalog_sales_quantitycount#3548L, catalog_sales_quantityave#3549)
    std::unordered_map<SW_Aggregate_TD_339190_key, SW_Aggregate_TD_339190_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_4457812_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_4457812_output.getInt32(i, 0);
        int32_t _sr_return_quantity679 = tbl_JOIN_INNER_TD_4457812_output.getInt32(i, 1);
        int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_4457812_output.getInt32(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _s_state402 = tbl_JOIN_INNER_TD_4457812_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229 = tbl_JOIN_INNER_TD_4457812_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232 = tbl_JOIN_INNER_TD_4457812_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        SW_Aggregate_TD_339190_key k{std::string(_i_item_id229.data()), std::string(_i_item_desc232.data()), std::string(_s_state402.data())};
        int64_t _store_sales_quantitycount3544L_count_0 = _ss_quantity1216 != 0 ? 1 : 0;
        int64_t _store_sales_quantityave3545_avg_1 = _ss_quantity1216;
        int64_t _as_store_returns_quantitycount3546L_count_2 = _sr_return_quantity679 != 0 ? 1 : 0;
        int64_t _as_store_returns_quantityave3547_avg_3 = _sr_return_quantity679;
        int64_t _catalog_sales_quantitycount3548L_count_4 = _cs_quantity1122 != 0 ? 1 : 0;
        int64_t _catalog_sales_quantityave3549_avg_5 = _cs_quantity1122;
        SW_Aggregate_TD_339190_payload p{_store_sales_quantitycount3544L_count_0, _store_sales_quantityave3545_avg_1, _as_store_returns_quantitycount3546L_count_2, _as_store_returns_quantityave3547_avg_3, _catalog_sales_quantitycount3548L_count_4, _catalog_sales_quantityave3549_avg_5};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t count_0 = (it->second)._store_sales_quantitycount3544L_count_0 + _store_sales_quantitycount3544L_count_0;
            p._store_sales_quantitycount3544L_count_0 = count_0;
            int64_t avg_1 = ((it->second)._store_sales_quantityave3545_avg_1 + _store_sales_quantityave3545_avg_1);
            p._store_sales_quantityave3545_avg_1 = avg_1;
            int64_t count_2 = (it->second)._as_store_returns_quantitycount3546L_count_2 + _as_store_returns_quantitycount3546L_count_2;
            p._as_store_returns_quantitycount3546L_count_2 = count_2;
            int64_t avg_3 = ((it->second)._as_store_returns_quantityave3547_avg_3 + _as_store_returns_quantityave3547_avg_3);
            p._as_store_returns_quantityave3547_avg_3 = avg_3;
            int64_t count_4 = (it->second)._catalog_sales_quantitycount3548L_count_4 + _catalog_sales_quantitycount3548L_count_4;
            p._catalog_sales_quantitycount3548L_count_4 = count_4;
            int64_t avg_5 = ((it->second)._catalog_sales_quantityave3549_avg_5 + _catalog_sales_quantityave3549_avg_5);
            p._catalog_sales_quantityave3549_avg_5 = avg_5;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229{};
        memcpy(_i_item_id229.data(), ((it.first)._i_item_id229).data(), ((it.first)._i_item_id229).length());
        tbl_Aggregate_TD_339190_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id229);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232{};
        memcpy(_i_item_desc232.data(), ((it.first)._i_item_desc232).data(), ((it.first)._i_item_desc232).length());
        tbl_Aggregate_TD_339190_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_desc232);
        std::array<char, TPCDS_READ_MAX + 1> _s_state402{};
        memcpy(_s_state402.data(), ((it.first)._s_state402).data(), ((it.first)._s_state402).length());
        tbl_Aggregate_TD_339190_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_state402);
        int64_t _store_sales_quantitycount3544L = (it.second)._store_sales_quantitycount3544L_count_0;
        tbl_Aggregate_TD_339190_output.setInt64(r, 3, _store_sales_quantitycount3544L);
        int64_t _store_sales_quantityave3545 = (it.second)._store_sales_quantityave3545_avg_1 / nrow1;
        tbl_Aggregate_TD_339190_output.setInt64(r, 4, _store_sales_quantityave3545);
        int64_t _as_store_returns_quantitycount3546L = (it.second)._as_store_returns_quantitycount3546L_count_2;
        tbl_Aggregate_TD_339190_output.setInt64(r, 5, _as_store_returns_quantitycount3546L);
        int64_t _as_store_returns_quantityave3547 = (it.second)._as_store_returns_quantityave3547_avg_3 / nrow1;
        tbl_Aggregate_TD_339190_output.setInt64(r, 6, _as_store_returns_quantityave3547);
        int64_t _catalog_sales_quantitycount3548L = (it.second)._catalog_sales_quantitycount3548L_count_4;
        tbl_Aggregate_TD_339190_output.setInt64(r, 7, _catalog_sales_quantitycount3548L);
        int64_t _catalog_sales_quantityave3549 = (it.second)._catalog_sales_quantityave3549_avg_5 / nrow1;
        tbl_Aggregate_TD_339190_output.setInt64(r, 8, _catalog_sales_quantityave3549);
        ++r;
    }
    tbl_Aggregate_TD_339190_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_339190_output #Row: " << tbl_Aggregate_TD_339190_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2886361(Table &tbl_Aggregate_TD_339190_output, Table &tbl_Sort_TD_2886361_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(i_item_id#229 ASC NULLS FIRST, i_item_desc#232 ASC NULLS FIRST, s_state#402 ASC NULLS FIRST)
    // Input: ListBuffer(i_item_id#229, i_item_desc#232, s_state#402, store_sales_quantitycount#3544L, store_sales_quantityave#3545, as_store_returns_quantitycount#3546L, as_store_returns_quantityave#3547, catalog_sales_quantitycount#3548L, catalog_sales_quantityave#3549)
    // Output: ListBuffer(i_item_id#229, i_item_desc#232, s_state#402, store_sales_quantitycount#3544L, store_sales_quantityave#3545, as_store_returns_quantitycount#3546L, as_store_returns_quantityave#3547, catalog_sales_quantitycount#3548L, catalog_sales_quantityave#3549)
    struct SW_Sort_TD_2886361Row {
        std::string _i_item_id229;
        std::string _i_item_desc232;
        std::string _s_state402;
        int64_t _store_sales_quantitycount3544L;
        int64_t _store_sales_quantityave3545;
        int64_t _as_store_returns_quantitycount3546L;
        int64_t _as_store_returns_quantityave3547;
        int64_t _catalog_sales_quantitycount3548L;
        int64_t _catalog_sales_quantityave3549;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2886361Row& a, const SW_Sort_TD_2886361Row& b) const { return 
 (a._i_item_id229 < b._i_item_id229) || 
 ((a._i_item_id229 == b._i_item_id229) && (a._i_item_desc232 < b._i_item_desc232)) || 
 ((a._i_item_id229 == b._i_item_id229) && (a._i_item_desc232 == b._i_item_desc232) && (a._s_state402 < b._s_state402)); 
}
    }SW_Sort_TD_2886361_order; 

    int nrow1 = tbl_Aggregate_TD_339190_output.getNumRow();
    std::vector<SW_Sort_TD_2886361Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229 = tbl_Aggregate_TD_339190_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232 = tbl_Aggregate_TD_339190_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _s_state402 = tbl_Aggregate_TD_339190_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        int64_t _store_sales_quantitycount3544L = tbl_Aggregate_TD_339190_output.getInt64(i, 3);
        int32_t _store_sales_quantityave3545 = tbl_Aggregate_TD_339190_output.getInt32(i, 4);
        int64_t _as_store_returns_quantitycount3546L = tbl_Aggregate_TD_339190_output.getInt64(i, 5);
        int32_t _as_store_returns_quantityave3547 = tbl_Aggregate_TD_339190_output.getInt32(i, 6);
        int64_t _catalog_sales_quantitycount3548L = tbl_Aggregate_TD_339190_output.getInt64(i, 7);
        int32_t _catalog_sales_quantityave3549 = tbl_Aggregate_TD_339190_output.getInt32(i, 8);
        SW_Sort_TD_2886361Row t = {std::string(_i_item_id229.data()),std::string(_i_item_desc232.data()),std::string(_s_state402.data()),_store_sales_quantitycount3544L,_store_sales_quantityave3545,_as_store_returns_quantitycount3546L,_as_store_returns_quantityave3547,_catalog_sales_quantitycount3548L,_catalog_sales_quantityave3549};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2886361_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229{};
        memcpy(_i_item_id229.data(), (it._i_item_id229).data(), (it._i_item_id229).length());
        tbl_Sort_TD_2886361_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _i_item_id229);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232{};
        memcpy(_i_item_desc232.data(), (it._i_item_desc232).data(), (it._i_item_desc232).length());
        tbl_Sort_TD_2886361_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _i_item_desc232);
        std::array<char, TPCDS_READ_MAX + 1> _s_state402{};
        memcpy(_s_state402.data(), (it._s_state402).data(), (it._s_state402).length());
        tbl_Sort_TD_2886361_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _s_state402);
        tbl_Sort_TD_2886361_output.setInt64(r, 3, it._store_sales_quantitycount3544L);
        tbl_Sort_TD_2886361_output.setInt32(r, 4, it._store_sales_quantityave3545);
        tbl_Sort_TD_2886361_output.setInt64(r, 5, it._as_store_returns_quantitycount3546L);
        tbl_Sort_TD_2886361_output.setInt32(r, 6, it._as_store_returns_quantityave3547);
        tbl_Sort_TD_2886361_output.setInt64(r, 7, it._catalog_sales_quantitycount3548L);
        tbl_Sort_TD_2886361_output.setInt32(r, 8, it._catalog_sales_quantityave3549);
        ++r;
    }
    tbl_Sort_TD_2886361_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2886361_output #Row: " << tbl_Sort_TD_2886361_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_110708(Table &tbl_Sort_TD_2886361_output, Table &tbl_LocalLimit_TD_110708_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(i_item_id#229, i_item_desc#232, s_state#402, store_sales_quantitycount#3544L, store_sales_quantityave#3545, as_store_returns_quantitycount#3546L, as_store_returns_quantityave#3547, catalog_sales_quantitycount#3548L, catalog_sales_quantityave#3549)
    // Output: ListBuffer(i_item_id#229, i_item_desc#232, s_state#402, store_sales_quantitycount#3544L, store_sales_quantityave#3545, as_store_returns_quantitycount#3546L, as_store_returns_quantityave#3547, catalog_sales_quantitycount#3548L, catalog_sales_quantityave#3549)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_Sort_TD_2886361_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_110708_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id229_n);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n = tbl_Sort_TD_2886361_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_110708_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_desc232_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_state402_n = tbl_Sort_TD_2886361_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_LocalLimit_TD_110708_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_state402_n);
        tbl_LocalLimit_TD_110708_output.setInt64(r, 3, tbl_Sort_TD_2886361_output.getInt64(i, 3));
        tbl_LocalLimit_TD_110708_output.setInt64(r, 4, tbl_Sort_TD_2886361_output.getInt64(i, 4));
        tbl_LocalLimit_TD_110708_output.setInt64(r, 5, tbl_Sort_TD_2886361_output.getInt64(i, 5));
        tbl_LocalLimit_TD_110708_output.setInt64(r, 6, tbl_Sort_TD_2886361_output.getInt64(i, 6));
        tbl_LocalLimit_TD_110708_output.setInt64(r, 7, tbl_Sort_TD_2886361_output.getInt64(i, 7));
        tbl_LocalLimit_TD_110708_output.setInt64(r, 8, tbl_Sort_TD_2886361_output.getInt64(i, 8));
        r++;
    }
    tbl_LocalLimit_TD_110708_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_110708_output #Row: " << tbl_LocalLimit_TD_110708_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0702997(Table &tbl_LocalLimit_TD_110708_output, Table &tbl_GlobalLimit_TD_0702997_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(i_item_id#229, i_item_desc#232, s_state#402, store_sales_quantitycount#3544L, store_sales_quantityave#3545, as_store_returns_quantitycount#3546L, as_store_returns_quantityave#3547, catalog_sales_quantitycount#3548L, catalog_sales_quantityave#3549)
    // Output: ListBuffer(i_item_id#229, i_item_desc#232, s_state#402, store_sales_quantitycount#3544L, store_sales_quantityave#3545, as_store_returns_quantitycount#3546L, as_store_returns_quantityave#3547, catalog_sales_quantitycount#3548L, catalog_sales_quantityave#3549)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_LocalLimit_TD_110708_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0702997_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id229_n);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n = tbl_LocalLimit_TD_110708_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_0702997_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_desc232_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_state402_n = tbl_LocalLimit_TD_110708_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_GlobalLimit_TD_0702997_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_state402_n);
        tbl_GlobalLimit_TD_0702997_output.setInt64(r, 3, tbl_LocalLimit_TD_110708_output.getInt64(i, 3));
        tbl_GlobalLimit_TD_0702997_output.setInt64(r, 4, tbl_LocalLimit_TD_110708_output.getInt64(i, 4));
        tbl_GlobalLimit_TD_0702997_output.setInt64(r, 5, tbl_LocalLimit_TD_110708_output.getInt64(i, 5));
        tbl_GlobalLimit_TD_0702997_output.setInt64(r, 6, tbl_LocalLimit_TD_110708_output.getInt64(i, 6));
        tbl_GlobalLimit_TD_0702997_output.setInt64(r, 7, tbl_LocalLimit_TD_110708_output.getInt64(i, 7));
        tbl_GlobalLimit_TD_0702997_output.setInt64(r, 8, tbl_LocalLimit_TD_110708_output.getInt64(i, 8));
        r++;
    }
    tbl_GlobalLimit_TD_0702997_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0702997_output #Row: " << tbl_GlobalLimit_TD_0702997_output.getNumRow() << std::endl;
}

