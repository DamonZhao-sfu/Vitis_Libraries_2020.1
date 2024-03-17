#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_8273266(Table &tbl_SerializeFromObject_TD_9189504_input, Table &tbl_Filter_TD_8273266_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(sr_ticket_number#678L) AND isnotnull(sr_item_sk#671)) AND isnotnull(sr_customer_sk#672)) AND isnotnull(sr_returned_date_sk#669)))
    // Input: ListBuffer(sr_returned_date_sk#669, sr_item_sk#671, sr_customer_sk#672, sr_ticket_number#678L)
    // Output: ListBuffer(sr_returned_date_sk#669, sr_item_sk#671, sr_customer_sk#672, sr_ticket_number#678L)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9189504_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sr_ticket_number678L = tbl_SerializeFromObject_TD_9189504_input.getInt64(i, 3);
        int32_t _sr_item_sk671 = tbl_SerializeFromObject_TD_9189504_input.getInt32(i, 1);
        int32_t _sr_customer_sk672 = tbl_SerializeFromObject_TD_9189504_input.getInt32(i, 2);
        int32_t _sr_returned_date_sk669 = tbl_SerializeFromObject_TD_9189504_input.getInt32(i, 0);
        if ((((_sr_ticket_number678L!= 0) && (_sr_item_sk671!= 0)) && (_sr_customer_sk672!= 0)) && (_sr_returned_date_sk669!= 0)) {
            int32_t _sr_returned_date_sk669_t = tbl_SerializeFromObject_TD_9189504_input.getInt32(i, 0);
            tbl_Filter_TD_8273266_output.setInt32(r, 0, _sr_returned_date_sk669_t);
            int32_t _sr_item_sk671_t = tbl_SerializeFromObject_TD_9189504_input.getInt32(i, 1);
            tbl_Filter_TD_8273266_output.setInt32(r, 1, _sr_item_sk671_t);
            int32_t _sr_customer_sk672_t = tbl_SerializeFromObject_TD_9189504_input.getInt32(i, 2);
            tbl_Filter_TD_8273266_output.setInt32(r, 2, _sr_customer_sk672_t);
            int64_t _sr_ticket_number678L_t = tbl_SerializeFromObject_TD_9189504_input.getInt64(i, 3);
            tbl_Filter_TD_8273266_output.setInt64(r, 3, _sr_ticket_number678L_t);
            r++;
        }
    }
    tbl_Filter_TD_8273266_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8273266_output #Row: " << tbl_Filter_TD_8273266_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8778206(Table &tbl_SerializeFromObject_TD_9888251_input, Table &tbl_Filter_TD_8778206_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((((isnotnull(ss_ticket_number#1215L) AND isnotnull(ss_item_sk#1208)) AND isnotnull(ss_customer_sk#1209)) AND isnotnull(ss_store_sk#1213)) AND isnotnull(ss_sold_date_sk#1206)))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209, ss_store_sk#1213, ss_ticket_number#1215L)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209, ss_store_sk#1213, ss_ticket_number#1215L)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9888251_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ss_ticket_number1215L = tbl_SerializeFromObject_TD_9888251_input.getInt64(i, 4);
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_9888251_input.getInt32(i, 1);
        int32_t _ss_customer_sk1209 = tbl_SerializeFromObject_TD_9888251_input.getInt32(i, 2);
        int32_t _ss_store_sk1213 = tbl_SerializeFromObject_TD_9888251_input.getInt32(i, 3);
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_9888251_input.getInt32(i, 0);
        if (((((_ss_ticket_number1215L!= 0) && (_ss_item_sk1208!= 0)) && (_ss_customer_sk1209!= 0)) && (_ss_store_sk1213!= 0)) && (_ss_sold_date_sk1206!= 0)) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_9888251_input.getInt32(i, 0);
            tbl_Filter_TD_8778206_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_9888251_input.getInt32(i, 1);
            tbl_Filter_TD_8778206_output.setInt32(r, 1, _ss_item_sk1208_t);
            int32_t _ss_customer_sk1209_t = tbl_SerializeFromObject_TD_9888251_input.getInt32(i, 2);
            tbl_Filter_TD_8778206_output.setInt32(r, 2, _ss_customer_sk1209_t);
            int32_t _ss_store_sk1213_t = tbl_SerializeFromObject_TD_9888251_input.getInt32(i, 3);
            tbl_Filter_TD_8778206_output.setInt32(r, 3, _ss_store_sk1213_t);
            int64_t _ss_ticket_number1215L_t = tbl_SerializeFromObject_TD_9888251_input.getInt64(i, 4);
            tbl_Filter_TD_8778206_output.setInt64(r, 4, _ss_ticket_number1215L_t);
            r++;
        }
    }
    tbl_Filter_TD_8778206_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8778206_output #Row: " << tbl_Filter_TD_8778206_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7731477(Table &tbl_SerializeFromObject_TD_8830283_input, Table &tbl_Filter_TD_7731477_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(s_store_sk#378))
    // Input: ListBuffer(s_store_sk#378, s_store_name#383, s_company_id#394, s_street_number#396, s_street_name#397, s_street_type#398, s_suite_number#399, s_city#400, s_county#401, s_state#402, s_zip#403)
    // Output: ListBuffer(s_store_sk#378, s_store_name#383, s_company_id#394, s_street_number#396, s_street_name#397, s_street_type#398, s_suite_number#399, s_city#400, s_county#401, s_state#402, s_zip#403)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8830283_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _s_store_sk378 = tbl_SerializeFromObject_TD_8830283_input.getInt32(i, 0);
        if (_s_store_sk378!= 0) {
            int32_t _s_store_sk378_t = tbl_SerializeFromObject_TD_8830283_input.getInt32(i, 0);
            tbl_Filter_TD_7731477_output.setInt32(r, 0, _s_store_sk378_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_t = tbl_SerializeFromObject_TD_8830283_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_7731477_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_store_name383_t);
            int32_t _s_company_id394_t = tbl_SerializeFromObject_TD_8830283_input.getInt32(i, 2);
            tbl_Filter_TD_7731477_output.setInt32(r, 2, _s_company_id394_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_street_number396_t = tbl_SerializeFromObject_TD_8830283_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_7731477_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _s_street_number396_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_street_name397_t = tbl_SerializeFromObject_TD_8830283_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            tbl_Filter_TD_7731477_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _s_street_name397_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_street_type398_t = tbl_SerializeFromObject_TD_8830283_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            tbl_Filter_TD_7731477_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_street_type398_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_suite_number399_t = tbl_SerializeFromObject_TD_8830283_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            tbl_Filter_TD_7731477_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_suite_number399_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_city400_t = tbl_SerializeFromObject_TD_8830283_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            tbl_Filter_TD_7731477_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_city400_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_county401_t = tbl_SerializeFromObject_TD_8830283_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
            tbl_Filter_TD_7731477_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _s_county401_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_state402_t = tbl_SerializeFromObject_TD_8830283_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            tbl_Filter_TD_7731477_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_state402_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_zip403_t = tbl_SerializeFromObject_TD_8830283_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            tbl_Filter_TD_7731477_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _s_zip403_t);
            r++;
        }
    }
    tbl_Filter_TD_7731477_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7731477_output #Row: " << tbl_Filter_TD_7731477_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_7222960_key_leftMajor {
    int64_t _ss_ticket_number1215L;
    int32_t _ss_item_sk1208;
    int32_t _ss_customer_sk1209;
    bool operator==(const SW_JOIN_INNER_TD_7222960_key_leftMajor& other) const {
        return ((_ss_ticket_number1215L == other._ss_ticket_number1215L) && (_ss_item_sk1208 == other._ss_item_sk1208) && (_ss_customer_sk1209 == other._ss_customer_sk1209));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7222960_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7222960_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int64_t>()(k._ss_ticket_number1215L)) + (hash<int32_t>()(k._ss_item_sk1208)) + (hash<int32_t>()(k._ss_customer_sk1209));
    }
};
}
struct SW_JOIN_INNER_TD_7222960_payload_leftMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_item_sk1208;
    int32_t _ss_customer_sk1209;
    int32_t _ss_store_sk1213;
    int64_t _ss_ticket_number1215L;
};
struct SW_JOIN_INNER_TD_7222960_key_rightMajor {
    int64_t _sr_ticket_number678L;
    int32_t _sr_item_sk671;
    int32_t _sr_customer_sk672;
    bool operator==(const SW_JOIN_INNER_TD_7222960_key_rightMajor& other) const {
        return ((_sr_ticket_number678L == other._sr_ticket_number678L) && (_sr_item_sk671 == other._sr_item_sk671) && (_sr_customer_sk672 == other._sr_customer_sk672));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7222960_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7222960_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int64_t>()(k._sr_ticket_number678L)) + (hash<int32_t>()(k._sr_item_sk671)) + (hash<int32_t>()(k._sr_customer_sk672));
    }
};
}
struct SW_JOIN_INNER_TD_7222960_payload_rightMajor {
    int32_t _sr_returned_date_sk669;
    int32_t _sr_item_sk671;
    int32_t _sr_customer_sk672;
    int64_t _sr_ticket_number678L;
};
void SW_JOIN_INNER_TD_7222960(Table &tbl_Filter_TD_8778206_output, Table &tbl_Filter_TD_8273266_output, Table &tbl_JOIN_INNER_TD_7222960_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((((ss_ticket_number#1215L = sr_ticket_number#678L) AND (ss_item_sk#1208 = sr_item_sk#671)) AND (ss_customer_sk#1209 = sr_customer_sk#672)))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209, ss_store_sk#1213, ss_ticket_number#1215L)
    // Right Table: ListBuffer(sr_returned_date_sk#669, sr_item_sk#671, sr_customer_sk#672, sr_ticket_number#678L)
    // Output Table: ListBuffer(ss_sold_date_sk#1206, ss_store_sk#1213, sr_returned_date_sk#669)
    int left_nrow = tbl_Filter_TD_8778206_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8273266_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7222960_key_leftMajor, SW_JOIN_INNER_TD_7222960_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_8778206_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int64_t _ss_ticket_number1215L_k = tbl_Filter_TD_8778206_output.getInt64(i, 4);
            int32_t _ss_item_sk1208_k = tbl_Filter_TD_8778206_output.getInt32(i, 1);
            int32_t _ss_customer_sk1209_k = tbl_Filter_TD_8778206_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_7222960_key_leftMajor keyA{_ss_ticket_number1215L_k, _ss_item_sk1208_k, _ss_customer_sk1209_k};
            int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_8778206_output.getInt32(i, 0);
            int32_t _ss_item_sk1208 = tbl_Filter_TD_8778206_output.getInt32(i, 1);
            int32_t _ss_customer_sk1209 = tbl_Filter_TD_8778206_output.getInt32(i, 2);
            int32_t _ss_store_sk1213 = tbl_Filter_TD_8778206_output.getInt32(i, 3);
            int64_t _ss_ticket_number1215L = tbl_Filter_TD_8778206_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_7222960_payload_leftMajor payloadA{_ss_sold_date_sk1206, _ss_item_sk1208, _ss_customer_sk1209, _ss_store_sk1213, _ss_ticket_number1215L};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8273266_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int64_t _sr_ticket_number678L_k = tbl_Filter_TD_8273266_output.getInt64(i, 3);
            int32_t _sr_item_sk671_k = tbl_Filter_TD_8273266_output.getInt32(i, 1);
            int32_t _sr_customer_sk672_k = tbl_Filter_TD_8273266_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7222960_key_leftMajor{_sr_ticket_number678L_k, _sr_item_sk671_k, _sr_customer_sk672_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                int32_t _ss_store_sk1213 = (it->second)._ss_store_sk1213;
                int64_t _ss_ticket_number1215L = (it->second)._ss_ticket_number1215L;
                int32_t _sr_returned_date_sk669 = tbl_Filter_TD_8273266_output.getInt32(i, 0);
                int32_t _sr_item_sk671 = tbl_Filter_TD_8273266_output.getInt32(i, 1);
                int32_t _sr_customer_sk672 = tbl_Filter_TD_8273266_output.getInt32(i, 2);
                int64_t _sr_ticket_number678L = tbl_Filter_TD_8273266_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_7222960_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_7222960_output.setInt32(r, 1, _ss_store_sk1213);
                tbl_JOIN_INNER_TD_7222960_output.setInt32(r, 2, _sr_returned_date_sk669);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7222960_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7222960_key_rightMajor, SW_JOIN_INNER_TD_7222960_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8273266_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int64_t _sr_ticket_number678L_k = tbl_Filter_TD_8273266_output.getInt64(i, 3);
            int32_t _sr_item_sk671_k = tbl_Filter_TD_8273266_output.getInt32(i, 1);
            int32_t _sr_customer_sk672_k = tbl_Filter_TD_8273266_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_7222960_key_rightMajor keyA{_sr_ticket_number678L_k, _sr_item_sk671_k, _sr_customer_sk672_k};
            int32_t _sr_returned_date_sk669 = tbl_Filter_TD_8273266_output.getInt32(i, 0);
            int32_t _sr_item_sk671 = tbl_Filter_TD_8273266_output.getInt32(i, 1);
            int32_t _sr_customer_sk672 = tbl_Filter_TD_8273266_output.getInt32(i, 2);
            int64_t _sr_ticket_number678L = tbl_Filter_TD_8273266_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_7222960_payload_rightMajor payloadA{_sr_returned_date_sk669, _sr_item_sk671, _sr_customer_sk672, _sr_ticket_number678L};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8778206_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int64_t _ss_ticket_number1215L_k = tbl_Filter_TD_8778206_output.getInt64(i, 4);
            int32_t _ss_item_sk1208_k = tbl_Filter_TD_8778206_output.getInt32(i, 1);
            int32_t _ss_customer_sk1209_k = tbl_Filter_TD_8778206_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7222960_key_rightMajor{_ss_ticket_number1215L_k, _ss_item_sk1208_k, _ss_customer_sk1209_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _sr_returned_date_sk669 = (it->second)._sr_returned_date_sk669;
                int32_t _sr_item_sk671 = (it->second)._sr_item_sk671;
                int32_t _sr_customer_sk672 = (it->second)._sr_customer_sk672;
                int64_t _sr_ticket_number678L = (it->second)._sr_ticket_number678L;
                int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_8778206_output.getInt32(i, 0);
                int32_t _ss_item_sk1208 = tbl_Filter_TD_8778206_output.getInt32(i, 1);
                int32_t _ss_customer_sk1209 = tbl_Filter_TD_8778206_output.getInt32(i, 2);
                int32_t _ss_store_sk1213 = tbl_Filter_TD_8778206_output.getInt32(i, 3);
                int64_t _ss_ticket_number1215L = tbl_Filter_TD_8778206_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_7222960_output.setInt32(r, 2, _sr_returned_date_sk669);
                tbl_JOIN_INNER_TD_7222960_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_7222960_output.setInt32(r, 1, _ss_store_sk1213);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7222960_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7222960_output #Row: " << tbl_JOIN_INNER_TD_7222960_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6167012(Table &tbl_SerializeFromObject_TD_716473_input, Table &tbl_Filter_TD_6167012_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(d_date_sk#120))
    // Input: ListBuffer(d_date_sk#120)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_716473_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_716473_input.getInt32(i, 0);
        if (_d_date_sk120!= 0) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_716473_input.getInt32(i, 0);
            tbl_Filter_TD_6167012_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_6167012_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6167012_output #Row: " << tbl_Filter_TD_6167012_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6935557_key_leftMajor {
    int32_t _ss_store_sk1213;
    bool operator==(const SW_JOIN_INNER_TD_6935557_key_leftMajor& other) const {
        return ((_ss_store_sk1213 == other._ss_store_sk1213));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6935557_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6935557_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_store_sk1213));
    }
};
}
struct SW_JOIN_INNER_TD_6935557_payload_leftMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_store_sk1213;
    int32_t _sr_returned_date_sk669;
};
struct SW_JOIN_INNER_TD_6935557_key_rightMajor {
    int32_t _s_store_sk378;
    bool operator==(const SW_JOIN_INNER_TD_6935557_key_rightMajor& other) const {
        return ((_s_store_sk378 == other._s_store_sk378));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6935557_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6935557_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_store_sk378));
    }
};
}
struct SW_JOIN_INNER_TD_6935557_payload_rightMajor {
    int32_t _s_store_sk378;
    std::string _s_store_name383;
    int32_t _s_company_id394;
    std::string _s_street_number396;
    std::string _s_street_name397;
    std::string _s_street_type398;
    std::string _s_suite_number399;
    std::string _s_city400;
    std::string _s_county401;
    std::string _s_state402;
    std::string _s_zip403;
};
void SW_JOIN_INNER_TD_6935557(Table &tbl_JOIN_INNER_TD_7222960_output, Table &tbl_Filter_TD_7731477_output, Table &tbl_JOIN_INNER_TD_6935557_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_store_sk#1213 = s_store_sk#378))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_store_sk#1213, sr_returned_date_sk#669)
    // Right Table: ListBuffer(s_store_sk#378, s_store_name#383, s_company_id#394, s_street_number#396, s_street_name#397, s_street_type#398, s_suite_number#399, s_city#400, s_county#401, s_state#402, s_zip#403)
    // Output Table: ListBuffer(ss_sold_date_sk#1206, sr_returned_date_sk#669, s_store_name#383, s_company_id#394, s_street_number#396, s_street_name#397, s_street_type#398, s_suite_number#399, s_city#400, s_county#401, s_state#402, s_zip#403)
    int left_nrow = tbl_JOIN_INNER_TD_7222960_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7731477_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6935557_key_leftMajor, SW_JOIN_INNER_TD_6935557_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7222960_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_store_sk1213_k = tbl_JOIN_INNER_TD_7222960_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_6935557_key_leftMajor keyA{_ss_store_sk1213_k};
            int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_7222960_output.getInt32(i, 0);
            int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_7222960_output.getInt32(i, 1);
            int32_t _sr_returned_date_sk669 = tbl_JOIN_INNER_TD_7222960_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_6935557_payload_leftMajor payloadA{_ss_sold_date_sk1206, _ss_store_sk1213, _sr_returned_date_sk669};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7731477_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_7731477_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6935557_key_leftMajor{_s_store_sk378_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_store_sk1213 = (it->second)._ss_store_sk1213;
                int32_t _sr_returned_date_sk669 = (it->second)._sr_returned_date_sk669;
                int32_t _s_store_sk378 = tbl_Filter_TD_7731477_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_Filter_TD_7731477_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _s_store_name383 = std::string(_s_store_name383_n.data());
                int32_t _s_company_id394 = tbl_Filter_TD_7731477_output.getInt32(i, 2);
                std::array<char, TPCDS_READ_MAX + 1> _s_street_number396_n = tbl_Filter_TD_7731477_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _s_street_number396 = std::string(_s_street_number396_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_street_name397_n = tbl_Filter_TD_7731477_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _s_street_name397 = std::string(_s_street_name397_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_street_type398_n = tbl_Filter_TD_7731477_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _s_street_type398 = std::string(_s_street_type398_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_suite_number399_n = tbl_Filter_TD_7731477_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _s_suite_number399 = std::string(_s_suite_number399_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_city400_n = tbl_Filter_TD_7731477_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _s_city400 = std::string(_s_city400_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_county401_n = tbl_Filter_TD_7731477_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
                std::string _s_county401 = std::string(_s_county401_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_state402_n = tbl_Filter_TD_7731477_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
                std::string _s_state402 = std::string(_s_state402_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_Filter_TD_7731477_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
                std::string _s_zip403 = std::string(_s_zip403_n.data());
                tbl_JOIN_INNER_TD_6935557_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_6935557_output.setInt32(r, 1, _sr_returned_date_sk669);
                tbl_JOIN_INNER_TD_6935557_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_store_name383_n);
                tbl_JOIN_INNER_TD_6935557_output.setInt32(r, 3, _s_company_id394);
                tbl_JOIN_INNER_TD_6935557_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _s_street_number396_n);
                tbl_JOIN_INNER_TD_6935557_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_street_name397_n);
                tbl_JOIN_INNER_TD_6935557_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_street_type398_n);
                tbl_JOIN_INNER_TD_6935557_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_suite_number399_n);
                tbl_JOIN_INNER_TD_6935557_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _s_city400_n);
                tbl_JOIN_INNER_TD_6935557_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_county401_n);
                tbl_JOIN_INNER_TD_6935557_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _s_state402_n);
                tbl_JOIN_INNER_TD_6935557_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _s_zip403_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6935557_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6935557_key_rightMajor, SW_JOIN_INNER_TD_6935557_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7731477_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_7731477_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6935557_key_rightMajor keyA{_s_store_sk378_k};
            int32_t _s_store_sk378 = tbl_Filter_TD_7731477_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_Filter_TD_7731477_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _s_store_name383 = std::string(_s_store_name383_n.data());
            int32_t _s_company_id394 = tbl_Filter_TD_7731477_output.getInt32(i, 2);
            std::array<char, TPCDS_READ_MAX + 1> _s_street_number396_n = tbl_Filter_TD_7731477_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _s_street_number396 = std::string(_s_street_number396_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_street_name397_n = tbl_Filter_TD_7731477_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _s_street_name397 = std::string(_s_street_name397_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_street_type398_n = tbl_Filter_TD_7731477_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _s_street_type398 = std::string(_s_street_type398_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_suite_number399_n = tbl_Filter_TD_7731477_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _s_suite_number399 = std::string(_s_suite_number399_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_city400_n = tbl_Filter_TD_7731477_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _s_city400 = std::string(_s_city400_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_county401_n = tbl_Filter_TD_7731477_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
            std::string _s_county401 = std::string(_s_county401_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_state402_n = tbl_Filter_TD_7731477_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            std::string _s_state402 = std::string(_s_state402_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_Filter_TD_7731477_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            std::string _s_zip403 = std::string(_s_zip403_n.data());
            SW_JOIN_INNER_TD_6935557_payload_rightMajor payloadA{_s_store_sk378, _s_store_name383, _s_company_id394, _s_street_number396, _s_street_name397, _s_street_type398, _s_suite_number399, _s_city400, _s_county401, _s_state402, _s_zip403};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7222960_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_store_sk1213_k = tbl_JOIN_INNER_TD_7222960_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6935557_key_rightMajor{_ss_store_sk1213_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _s_store_sk378 = (it->second)._s_store_sk378;
                std::string _s_store_name383 = (it->second)._s_store_name383;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n{};
                memcpy(_s_store_name383_n.data(), (_s_store_name383).data(), (_s_store_name383).length());
                int32_t _s_company_id394 = (it->second)._s_company_id394;
                std::string _s_street_number396 = (it->second)._s_street_number396;
                std::array<char, TPCDS_READ_MAX + 1> _s_street_number396_n{};
                memcpy(_s_street_number396_n.data(), (_s_street_number396).data(), (_s_street_number396).length());
                std::string _s_street_name397 = (it->second)._s_street_name397;
                std::array<char, TPCDS_READ_MAX + 1> _s_street_name397_n{};
                memcpy(_s_street_name397_n.data(), (_s_street_name397).data(), (_s_street_name397).length());
                std::string _s_street_type398 = (it->second)._s_street_type398;
                std::array<char, TPCDS_READ_MAX + 1> _s_street_type398_n{};
                memcpy(_s_street_type398_n.data(), (_s_street_type398).data(), (_s_street_type398).length());
                std::string _s_suite_number399 = (it->second)._s_suite_number399;
                std::array<char, TPCDS_READ_MAX + 1> _s_suite_number399_n{};
                memcpy(_s_suite_number399_n.data(), (_s_suite_number399).data(), (_s_suite_number399).length());
                std::string _s_city400 = (it->second)._s_city400;
                std::array<char, TPCDS_READ_MAX + 1> _s_city400_n{};
                memcpy(_s_city400_n.data(), (_s_city400).data(), (_s_city400).length());
                std::string _s_county401 = (it->second)._s_county401;
                std::array<char, TPCDS_READ_MAX + 1> _s_county401_n{};
                memcpy(_s_county401_n.data(), (_s_county401).data(), (_s_county401).length());
                std::string _s_state402 = (it->second)._s_state402;
                std::array<char, TPCDS_READ_MAX + 1> _s_state402_n{};
                memcpy(_s_state402_n.data(), (_s_state402).data(), (_s_state402).length());
                std::string _s_zip403 = (it->second)._s_zip403;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n{};
                memcpy(_s_zip403_n.data(), (_s_zip403).data(), (_s_zip403).length());
                int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_7222960_output.getInt32(i, 0);
                int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_7222960_output.getInt32(i, 1);
                int32_t _sr_returned_date_sk669 = tbl_JOIN_INNER_TD_7222960_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_6935557_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_store_name383_n);
                tbl_JOIN_INNER_TD_6935557_output.setInt32(r, 3, _s_company_id394);
                tbl_JOIN_INNER_TD_6935557_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _s_street_number396_n);
                tbl_JOIN_INNER_TD_6935557_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_street_name397_n);
                tbl_JOIN_INNER_TD_6935557_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_street_type398_n);
                tbl_JOIN_INNER_TD_6935557_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_suite_number399_n);
                tbl_JOIN_INNER_TD_6935557_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _s_city400_n);
                tbl_JOIN_INNER_TD_6935557_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_county401_n);
                tbl_JOIN_INNER_TD_6935557_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _s_state402_n);
                tbl_JOIN_INNER_TD_6935557_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _s_zip403_n);
                tbl_JOIN_INNER_TD_6935557_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_6935557_output.setInt32(r, 1, _sr_returned_date_sk669);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6935557_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6935557_output #Row: " << tbl_JOIN_INNER_TD_6935557_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5961219(Table &tbl_SerializeFromObject_TD_6633768_input, Table &tbl_Filter_TD_5961219_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_year#3555) AND isnotnull(d_moy#3557)) AND ((d_year#3555 = 2001) AND (d_moy#3557 = 8))) AND isnotnull(d_date_sk#3549)))
    // Input: ListBuffer(d_date_sk#3549, d_year#3555, d_moy#3557)
    // Output: ListBuffer(d_date_sk#3549)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6633768_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3555 = tbl_SerializeFromObject_TD_6633768_input.getInt32(i, 1);
        int32_t _d_moy3557 = tbl_SerializeFromObject_TD_6633768_input.getInt32(i, 2);
        int32_t _d_date_sk3549 = tbl_SerializeFromObject_TD_6633768_input.getInt32(i, 0);
        if ((((_d_year3555!= 0) && (_d_moy3557!= 0)) && ((_d_year3555 == 2001) && (_d_moy3557 == 8))) && (_d_date_sk3549!= 0)) {
            int32_t _d_date_sk3549_t = tbl_SerializeFromObject_TD_6633768_input.getInt32(i, 0);
            tbl_Filter_TD_5961219_output.setInt32(r, 0, _d_date_sk3549_t);
            r++;
        }
    }
    tbl_Filter_TD_5961219_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5961219_output #Row: " << tbl_Filter_TD_5961219_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5558590_key_leftMajor {
    int32_t _ss_sold_date_sk1206;
    bool operator==(const SW_JOIN_INNER_TD_5558590_key_leftMajor& other) const {
        return ((_ss_sold_date_sk1206 == other._ss_sold_date_sk1206));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5558590_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5558590_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_sold_date_sk1206));
    }
};
}
struct SW_JOIN_INNER_TD_5558590_payload_leftMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _sr_returned_date_sk669;
    std::string _s_store_name383;
    int32_t _s_company_id394;
    std::string _s_street_number396;
    std::string _s_street_name397;
    std::string _s_street_type398;
    std::string _s_suite_number399;
    std::string _s_city400;
    std::string _s_county401;
    std::string _s_state402;
    std::string _s_zip403;
};
struct SW_JOIN_INNER_TD_5558590_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_5558590_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5558590_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5558590_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_5558590_payload_rightMajor {
    int32_t _d_date_sk120;
};
void SW_JOIN_INNER_TD_5558590(Table &tbl_JOIN_INNER_TD_6935557_output, Table &tbl_Filter_TD_6167012_output, Table &tbl_JOIN_INNER_TD_5558590_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#1206 = d_date_sk#120))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, sr_returned_date_sk#669, s_store_name#383, s_company_id#394, s_street_number#396, s_street_name#397, s_street_type#398, s_suite_number#399, s_city#400, s_county#401, s_state#402, s_zip#403)
    // Right Table: ListBuffer(d_date_sk#120)
    // Output Table: ListBuffer(ss_sold_date_sk#1206, sr_returned_date_sk#669, s_store_name#383, s_company_id#394, s_street_number#396, s_street_name#397, s_street_type#398, s_suite_number#399, s_city#400, s_county#401, s_state#402, s_zip#403)
    int left_nrow = tbl_JOIN_INNER_TD_6935557_output.getNumRow();
    int right_nrow = tbl_Filter_TD_6167012_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5558590_key_leftMajor, SW_JOIN_INNER_TD_5558590_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_6935557_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_JOIN_INNER_TD_6935557_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5558590_key_leftMajor keyA{_ss_sold_date_sk1206_k};
            int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_6935557_output.getInt32(i, 0);
            int32_t _sr_returned_date_sk669 = tbl_JOIN_INNER_TD_6935557_output.getInt32(i, 1);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_6935557_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _s_store_name383 = std::string(_s_store_name383_n.data());
            int32_t _s_company_id394 = tbl_JOIN_INNER_TD_6935557_output.getInt32(i, 3);
            std::array<char, TPCDS_READ_MAX + 1> _s_street_number396_n = tbl_JOIN_INNER_TD_6935557_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _s_street_number396 = std::string(_s_street_number396_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_street_name397_n = tbl_JOIN_INNER_TD_6935557_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _s_street_name397 = std::string(_s_street_name397_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_street_type398_n = tbl_JOIN_INNER_TD_6935557_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _s_street_type398 = std::string(_s_street_type398_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_suite_number399_n = tbl_JOIN_INNER_TD_6935557_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _s_suite_number399 = std::string(_s_suite_number399_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_city400_n = tbl_JOIN_INNER_TD_6935557_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
            std::string _s_city400 = std::string(_s_city400_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_county401_n = tbl_JOIN_INNER_TD_6935557_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            std::string _s_county401 = std::string(_s_county401_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_state402_n = tbl_JOIN_INNER_TD_6935557_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            std::string _s_state402 = std::string(_s_state402_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_6935557_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
            std::string _s_zip403 = std::string(_s_zip403_n.data());
            SW_JOIN_INNER_TD_5558590_payload_leftMajor payloadA{_ss_sold_date_sk1206, _sr_returned_date_sk669, _s_store_name383, _s_company_id394, _s_street_number396, _s_street_name397, _s_street_type398, _s_suite_number399, _s_city400, _s_county401, _s_state402, _s_zip403};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6167012_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_6167012_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5558590_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _sr_returned_date_sk669 = (it->second)._sr_returned_date_sk669;
                std::string _s_store_name383 = (it->second)._s_store_name383;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n{};
                memcpy(_s_store_name383_n.data(), (_s_store_name383).data(), (_s_store_name383).length());
                int32_t _s_company_id394 = (it->second)._s_company_id394;
                std::string _s_street_number396 = (it->second)._s_street_number396;
                std::array<char, TPCDS_READ_MAX + 1> _s_street_number396_n{};
                memcpy(_s_street_number396_n.data(), (_s_street_number396).data(), (_s_street_number396).length());
                std::string _s_street_name397 = (it->second)._s_street_name397;
                std::array<char, TPCDS_READ_MAX + 1> _s_street_name397_n{};
                memcpy(_s_street_name397_n.data(), (_s_street_name397).data(), (_s_street_name397).length());
                std::string _s_street_type398 = (it->second)._s_street_type398;
                std::array<char, TPCDS_READ_MAX + 1> _s_street_type398_n{};
                memcpy(_s_street_type398_n.data(), (_s_street_type398).data(), (_s_street_type398).length());
                std::string _s_suite_number399 = (it->second)._s_suite_number399;
                std::array<char, TPCDS_READ_MAX + 1> _s_suite_number399_n{};
                memcpy(_s_suite_number399_n.data(), (_s_suite_number399).data(), (_s_suite_number399).length());
                std::string _s_city400 = (it->second)._s_city400;
                std::array<char, TPCDS_READ_MAX + 1> _s_city400_n{};
                memcpy(_s_city400_n.data(), (_s_city400).data(), (_s_city400).length());
                std::string _s_county401 = (it->second)._s_county401;
                std::array<char, TPCDS_READ_MAX + 1> _s_county401_n{};
                memcpy(_s_county401_n.data(), (_s_county401).data(), (_s_county401).length());
                std::string _s_state402 = (it->second)._s_state402;
                std::array<char, TPCDS_READ_MAX + 1> _s_state402_n{};
                memcpy(_s_state402_n.data(), (_s_state402).data(), (_s_state402).length());
                std::string _s_zip403 = (it->second)._s_zip403;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n{};
                memcpy(_s_zip403_n.data(), (_s_zip403).data(), (_s_zip403).length());
                int32_t _d_date_sk120 = tbl_Filter_TD_6167012_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_5558590_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_5558590_output.setInt32(r, 1, _sr_returned_date_sk669);
                tbl_JOIN_INNER_TD_5558590_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_store_name383_n);
                tbl_JOIN_INNER_TD_5558590_output.setInt32(r, 3, _s_company_id394);
                tbl_JOIN_INNER_TD_5558590_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _s_street_number396_n);
                tbl_JOIN_INNER_TD_5558590_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_street_name397_n);
                tbl_JOIN_INNER_TD_5558590_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_street_type398_n);
                tbl_JOIN_INNER_TD_5558590_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_suite_number399_n);
                tbl_JOIN_INNER_TD_5558590_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _s_city400_n);
                tbl_JOIN_INNER_TD_5558590_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_county401_n);
                tbl_JOIN_INNER_TD_5558590_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _s_state402_n);
                tbl_JOIN_INNER_TD_5558590_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _s_zip403_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5558590_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5558590_key_rightMajor, SW_JOIN_INNER_TD_5558590_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_6167012_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_6167012_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5558590_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_6167012_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5558590_payload_rightMajor payloadA{_d_date_sk120};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_6935557_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_JOIN_INNER_TD_6935557_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5558590_key_rightMajor{_ss_sold_date_sk1206_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_6935557_output.getInt32(i, 0);
                int32_t _sr_returned_date_sk669 = tbl_JOIN_INNER_TD_6935557_output.getInt32(i, 1);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_6935557_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _s_store_name383 = std::string(_s_store_name383_n.data());
                int32_t _s_company_id394 = tbl_JOIN_INNER_TD_6935557_output.getInt32(i, 3);
                std::array<char, TPCDS_READ_MAX + 1> _s_street_number396_n = tbl_JOIN_INNER_TD_6935557_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _s_street_number396 = std::string(_s_street_number396_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_street_name397_n = tbl_JOIN_INNER_TD_6935557_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _s_street_name397 = std::string(_s_street_name397_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_street_type398_n = tbl_JOIN_INNER_TD_6935557_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _s_street_type398 = std::string(_s_street_type398_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_suite_number399_n = tbl_JOIN_INNER_TD_6935557_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _s_suite_number399 = std::string(_s_suite_number399_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_city400_n = tbl_JOIN_INNER_TD_6935557_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
                std::string _s_city400 = std::string(_s_city400_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_county401_n = tbl_JOIN_INNER_TD_6935557_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
                std::string _s_county401 = std::string(_s_county401_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_state402_n = tbl_JOIN_INNER_TD_6935557_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
                std::string _s_state402 = std::string(_s_state402_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_6935557_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
                std::string _s_zip403 = std::string(_s_zip403_n.data());
                tbl_JOIN_INNER_TD_5558590_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_5558590_output.setInt32(r, 1, _sr_returned_date_sk669);
                tbl_JOIN_INNER_TD_5558590_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_store_name383_n);
                tbl_JOIN_INNER_TD_5558590_output.setInt32(r, 3, _s_company_id394);
                tbl_JOIN_INNER_TD_5558590_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _s_street_number396_n);
                tbl_JOIN_INNER_TD_5558590_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_street_name397_n);
                tbl_JOIN_INNER_TD_5558590_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_street_type398_n);
                tbl_JOIN_INNER_TD_5558590_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_suite_number399_n);
                tbl_JOIN_INNER_TD_5558590_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _s_city400_n);
                tbl_JOIN_INNER_TD_5558590_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_county401_n);
                tbl_JOIN_INNER_TD_5558590_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _s_state402_n);
                tbl_JOIN_INNER_TD_5558590_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _s_zip403_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5558590_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5558590_output #Row: " << tbl_JOIN_INNER_TD_5558590_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4422236_key_leftMajor {
    int32_t _sr_returned_date_sk669;
    bool operator==(const SW_JOIN_INNER_TD_4422236_key_leftMajor& other) const {
        return ((_sr_returned_date_sk669 == other._sr_returned_date_sk669));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4422236_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4422236_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._sr_returned_date_sk669));
    }
};
}
struct SW_JOIN_INNER_TD_4422236_payload_leftMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _sr_returned_date_sk669;
    std::string _s_store_name383;
    int32_t _s_company_id394;
    std::string _s_street_number396;
    std::string _s_street_name397;
    std::string _s_street_type398;
    std::string _s_suite_number399;
    std::string _s_city400;
    std::string _s_county401;
    std::string _s_state402;
    std::string _s_zip403;
};
struct SW_JOIN_INNER_TD_4422236_key_rightMajor {
    int32_t _d_date_sk3549;
    bool operator==(const SW_JOIN_INNER_TD_4422236_key_rightMajor& other) const {
        return ((_d_date_sk3549 == other._d_date_sk3549));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4422236_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4422236_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk3549));
    }
};
}
struct SW_JOIN_INNER_TD_4422236_payload_rightMajor {
    int32_t _d_date_sk3549;
};
void SW_JOIN_INNER_TD_4422236(Table &tbl_JOIN_INNER_TD_5558590_output, Table &tbl_Filter_TD_5961219_output, Table &tbl_JOIN_INNER_TD_4422236_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((sr_returned_date_sk#669 = d_date_sk#3549))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, sr_returned_date_sk#669, s_store_name#383, s_company_id#394, s_street_number#396, s_street_name#397, s_street_type#398, s_suite_number#399, s_city#400, s_county#401, s_state#402, s_zip#403)
    // Right Table: ListBuffer(d_date_sk#3549)
    // Output Table: ListBuffer(ss_sold_date_sk#1206, sr_returned_date_sk#669, s_store_name#383, s_company_id#394, s_street_number#396, s_street_name#397, s_street_type#398, s_suite_number#399, s_city#400, s_county#401, s_state#402, s_zip#403)
    int left_nrow = tbl_JOIN_INNER_TD_5558590_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5961219_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4422236_key_leftMajor, SW_JOIN_INNER_TD_4422236_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_5558590_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _sr_returned_date_sk669_k = tbl_JOIN_INNER_TD_5558590_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_4422236_key_leftMajor keyA{_sr_returned_date_sk669_k};
            int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_5558590_output.getInt32(i, 0);
            int32_t _sr_returned_date_sk669 = tbl_JOIN_INNER_TD_5558590_output.getInt32(i, 1);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_5558590_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _s_store_name383 = std::string(_s_store_name383_n.data());
            int32_t _s_company_id394 = tbl_JOIN_INNER_TD_5558590_output.getInt32(i, 3);
            std::array<char, TPCDS_READ_MAX + 1> _s_street_number396_n = tbl_JOIN_INNER_TD_5558590_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _s_street_number396 = std::string(_s_street_number396_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_street_name397_n = tbl_JOIN_INNER_TD_5558590_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _s_street_name397 = std::string(_s_street_name397_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_street_type398_n = tbl_JOIN_INNER_TD_5558590_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _s_street_type398 = std::string(_s_street_type398_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_suite_number399_n = tbl_JOIN_INNER_TD_5558590_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _s_suite_number399 = std::string(_s_suite_number399_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_city400_n = tbl_JOIN_INNER_TD_5558590_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
            std::string _s_city400 = std::string(_s_city400_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_county401_n = tbl_JOIN_INNER_TD_5558590_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            std::string _s_county401 = std::string(_s_county401_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_state402_n = tbl_JOIN_INNER_TD_5558590_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            std::string _s_state402 = std::string(_s_state402_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_5558590_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
            std::string _s_zip403 = std::string(_s_zip403_n.data());
            SW_JOIN_INNER_TD_4422236_payload_leftMajor payloadA{_ss_sold_date_sk1206, _sr_returned_date_sk669, _s_store_name383, _s_company_id394, _s_street_number396, _s_street_name397, _s_street_type398, _s_suite_number399, _s_city400, _s_county401, _s_state402, _s_zip403};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5961219_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk3549_k = tbl_Filter_TD_5961219_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4422236_key_leftMajor{_d_date_sk3549_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _sr_returned_date_sk669 = (it->second)._sr_returned_date_sk669;
                std::string _s_store_name383 = (it->second)._s_store_name383;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n{};
                memcpy(_s_store_name383_n.data(), (_s_store_name383).data(), (_s_store_name383).length());
                int32_t _s_company_id394 = (it->second)._s_company_id394;
                std::string _s_street_number396 = (it->second)._s_street_number396;
                std::array<char, TPCDS_READ_MAX + 1> _s_street_number396_n{};
                memcpy(_s_street_number396_n.data(), (_s_street_number396).data(), (_s_street_number396).length());
                std::string _s_street_name397 = (it->second)._s_street_name397;
                std::array<char, TPCDS_READ_MAX + 1> _s_street_name397_n{};
                memcpy(_s_street_name397_n.data(), (_s_street_name397).data(), (_s_street_name397).length());
                std::string _s_street_type398 = (it->second)._s_street_type398;
                std::array<char, TPCDS_READ_MAX + 1> _s_street_type398_n{};
                memcpy(_s_street_type398_n.data(), (_s_street_type398).data(), (_s_street_type398).length());
                std::string _s_suite_number399 = (it->second)._s_suite_number399;
                std::array<char, TPCDS_READ_MAX + 1> _s_suite_number399_n{};
                memcpy(_s_suite_number399_n.data(), (_s_suite_number399).data(), (_s_suite_number399).length());
                std::string _s_city400 = (it->second)._s_city400;
                std::array<char, TPCDS_READ_MAX + 1> _s_city400_n{};
                memcpy(_s_city400_n.data(), (_s_city400).data(), (_s_city400).length());
                std::string _s_county401 = (it->second)._s_county401;
                std::array<char, TPCDS_READ_MAX + 1> _s_county401_n{};
                memcpy(_s_county401_n.data(), (_s_county401).data(), (_s_county401).length());
                std::string _s_state402 = (it->second)._s_state402;
                std::array<char, TPCDS_READ_MAX + 1> _s_state402_n{};
                memcpy(_s_state402_n.data(), (_s_state402).data(), (_s_state402).length());
                std::string _s_zip403 = (it->second)._s_zip403;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n{};
                memcpy(_s_zip403_n.data(), (_s_zip403).data(), (_s_zip403).length());
                int32_t _d_date_sk3549 = tbl_Filter_TD_5961219_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_4422236_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_4422236_output.setInt32(r, 1, _sr_returned_date_sk669);
                tbl_JOIN_INNER_TD_4422236_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_store_name383_n);
                tbl_JOIN_INNER_TD_4422236_output.setInt32(r, 3, _s_company_id394);
                tbl_JOIN_INNER_TD_4422236_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _s_street_number396_n);
                tbl_JOIN_INNER_TD_4422236_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_street_name397_n);
                tbl_JOIN_INNER_TD_4422236_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_street_type398_n);
                tbl_JOIN_INNER_TD_4422236_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_suite_number399_n);
                tbl_JOIN_INNER_TD_4422236_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _s_city400_n);
                tbl_JOIN_INNER_TD_4422236_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_county401_n);
                tbl_JOIN_INNER_TD_4422236_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _s_state402_n);
                tbl_JOIN_INNER_TD_4422236_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _s_zip403_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4422236_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4422236_key_rightMajor, SW_JOIN_INNER_TD_4422236_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5961219_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk3549_k = tbl_Filter_TD_5961219_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4422236_key_rightMajor keyA{_d_date_sk3549_k};
            int32_t _d_date_sk3549 = tbl_Filter_TD_5961219_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4422236_payload_rightMajor payloadA{_d_date_sk3549};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_5558590_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _sr_returned_date_sk669_k = tbl_JOIN_INNER_TD_5558590_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4422236_key_rightMajor{_sr_returned_date_sk669_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk3549 = (it->second)._d_date_sk3549;
                int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_5558590_output.getInt32(i, 0);
                int32_t _sr_returned_date_sk669 = tbl_JOIN_INNER_TD_5558590_output.getInt32(i, 1);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_5558590_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _s_store_name383 = std::string(_s_store_name383_n.data());
                int32_t _s_company_id394 = tbl_JOIN_INNER_TD_5558590_output.getInt32(i, 3);
                std::array<char, TPCDS_READ_MAX + 1> _s_street_number396_n = tbl_JOIN_INNER_TD_5558590_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _s_street_number396 = std::string(_s_street_number396_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_street_name397_n = tbl_JOIN_INNER_TD_5558590_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _s_street_name397 = std::string(_s_street_name397_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_street_type398_n = tbl_JOIN_INNER_TD_5558590_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _s_street_type398 = std::string(_s_street_type398_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_suite_number399_n = tbl_JOIN_INNER_TD_5558590_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _s_suite_number399 = std::string(_s_suite_number399_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_city400_n = tbl_JOIN_INNER_TD_5558590_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
                std::string _s_city400 = std::string(_s_city400_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_county401_n = tbl_JOIN_INNER_TD_5558590_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
                std::string _s_county401 = std::string(_s_county401_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_state402_n = tbl_JOIN_INNER_TD_5558590_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
                std::string _s_state402 = std::string(_s_state402_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_5558590_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
                std::string _s_zip403 = std::string(_s_zip403_n.data());
                tbl_JOIN_INNER_TD_4422236_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_4422236_output.setInt32(r, 1, _sr_returned_date_sk669);
                tbl_JOIN_INNER_TD_4422236_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_store_name383_n);
                tbl_JOIN_INNER_TD_4422236_output.setInt32(r, 3, _s_company_id394);
                tbl_JOIN_INNER_TD_4422236_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _s_street_number396_n);
                tbl_JOIN_INNER_TD_4422236_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_street_name397_n);
                tbl_JOIN_INNER_TD_4422236_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_street_type398_n);
                tbl_JOIN_INNER_TD_4422236_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_suite_number399_n);
                tbl_JOIN_INNER_TD_4422236_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _s_city400_n);
                tbl_JOIN_INNER_TD_4422236_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_county401_n);
                tbl_JOIN_INNER_TD_4422236_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _s_state402_n);
                tbl_JOIN_INNER_TD_4422236_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _s_zip403_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4422236_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4422236_output #Row: " << tbl_JOIN_INNER_TD_4422236_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_3396839_key {
    std::string _s_store_name383;
    int32_t _s_company_id394;
    std::string _s_street_number396;
    std::string _s_street_name397;
    std::string _s_street_type398;
    std::string _s_suite_number399;
    std::string _s_city400;
    std::string _s_county401;
    std::string _s_state402;
    std::string _s_zip403;
    bool operator==(const SW_Aggregate_TD_3396839_key& other) const { return (_s_store_name383 == other._s_store_name383) && (_s_company_id394 == other._s_company_id394) && (_s_street_number396 == other._s_street_number396) && (_s_street_name397 == other._s_street_name397) && (_s_street_type398 == other._s_street_type398) && (_s_suite_number399 == other._s_suite_number399) && (_s_city400 == other._s_city400) && (_s_county401 == other._s_county401) && (_s_state402 == other._s_state402) && (_s_zip403 == other._s_zip403); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_3396839_key> {
    std::size_t operator() (const SW_Aggregate_TD_3396839_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._s_store_name383)) + (hash<int32_t>()(k._s_company_id394)) + (hash<string>()(k._s_street_number396)) + (hash<string>()(k._s_street_name397)) + (hash<string>()(k._s_street_type398)) + (hash<string>()(k._s_suite_number399)) + (hash<string>()(k._s_city400)) + (hash<string>()(k._s_county401)) + (hash<string>()(k._s_state402)) + (hash<string>()(k._s_zip403));
    }
};
}
struct SW_Aggregate_TD_3396839_payload {
    int64_t _days3544L_sum_0;
    int64_t _days3545L_sum_1;
    int64_t _days3546L_sum_2;
    int64_t _days3547L_sum_3;
    int64_t _days3548L_sum_4;
};
void SW_Aggregate_TD_3396839(Table &tbl_JOIN_INNER_TD_4422236_output, Table &tbl_Aggregate_TD_3396839_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(s_store_name#383, s_company_id#394, s_street_number#396, s_street_name#397, s_street_type#398, s_suite_number#399, s_city#400, s_county#401, s_state#402, s_zip#403, sum(CASE WHEN ((sr_returned_date_sk#669 - ss_sold_date_sk#1206) <= 30) THEN 1 ELSE 0 END) AS 30 days#3544L, sum(CASE WHEN (((sr_returned_date_sk#669 - ss_sold_date_sk#1206) > 30) AND ((sr_returned_date_sk#669 - ss_sold_date_sk#1206) <= 60)) THEN 1 ELSE 0 END) AS 31-60 days#3545L, sum(CASE WHEN (((sr_returned_date_sk#669 - ss_sold_date_sk#1206) > 60) AND ((sr_returned_date_sk#669 - ss_sold_date_sk#1206) <= 90)) THEN 1 ELSE 0 END) AS 61-90 days#3546L, sum(CASE WHEN (((sr_returned_date_sk#669 - ss_sold_date_sk#1206) > 90) AND ((sr_returned_date_sk#669 - ss_sold_date_sk#1206) <= 120)) THEN 1 ELSE 0 END) AS 91-120 days#3547L, sum(CASE WHEN ((sr_returned_date_sk#669 - ss_sold_date_sk#1206) > 120) THEN 1 ELSE 0 END) AS >120 days#3548L)
    // Input: ListBuffer(ss_sold_date_sk#1206, sr_returned_date_sk#669, s_store_name#383, s_company_id#394, s_street_number#396, s_street_name#397, s_street_type#398, s_suite_number#399, s_city#400, s_county#401, s_state#402, s_zip#403)
    // Output: ListBuffer(s_store_name#383, s_company_id#394, s_street_number#396, s_street_name#397, s_street_type#398, s_suite_number#399, s_city#400, s_county#401, s_state#402, s_zip#403, 30 days#3544L, 31-60 days#3545L, 61-90 days#3546L, 91-120 days#3547L, >120 days#3548L)
    std::unordered_map<SW_Aggregate_TD_3396839_key, SW_Aggregate_TD_3396839_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_4422236_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_4422236_output.getInt32(i, 0);
        int32_t _sr_returned_date_sk669 = tbl_JOIN_INNER_TD_4422236_output.getInt32(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383 = tbl_JOIN_INNER_TD_4422236_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        int32_t _s_company_id394 = tbl_JOIN_INNER_TD_4422236_output.getInt32(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _s_street_number396 = tbl_JOIN_INNER_TD_4422236_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _s_street_name397 = tbl_JOIN_INNER_TD_4422236_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _s_street_type398 = tbl_JOIN_INNER_TD_4422236_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        std::array<char, TPCDS_READ_MAX + 1> _s_suite_number399 = tbl_JOIN_INNER_TD_4422236_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
        std::array<char, TPCDS_READ_MAX + 1> _s_city400 = tbl_JOIN_INNER_TD_4422236_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
        std::array<char, TPCDS_READ_MAX + 1> _s_county401 = tbl_JOIN_INNER_TD_4422236_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
        std::array<char, TPCDS_READ_MAX + 1> _s_state402 = tbl_JOIN_INNER_TD_4422236_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
        std::array<char, TPCDS_READ_MAX + 1> _s_zip403 = tbl_JOIN_INNER_TD_4422236_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
        SW_Aggregate_TD_3396839_key k{std::string(_s_store_name383.data()), _s_company_id394, std::string(_s_street_number396.data()), std::string(_s_street_name397.data()), std::string(_s_street_type398.data()), std::string(_s_suite_number399.data()), std::string(_s_city400.data()), std::string(_s_county401.data()), std::string(_s_state402.data()), std::string(_s_zip403.data())};
        int64_t _days3544L_sum_0 = ((_sr_returned_date_sk669 - _ss_sold_date_sk1206) <= 30) ? 1 : 0;
        int64_t _days3545L_sum_1 = (((_sr_returned_date_sk669 - _ss_sold_date_sk1206) > 30) && ((_sr_returned_date_sk669 - _ss_sold_date_sk1206) <= 60)) ? 1 : 0;
        int64_t _days3546L_sum_2 = (((_sr_returned_date_sk669 - _ss_sold_date_sk1206) > 60) && ((_sr_returned_date_sk669 - _ss_sold_date_sk1206) <= 90)) ? 1 : 0;
        int64_t _days3547L_sum_3 = (((_sr_returned_date_sk669 - _ss_sold_date_sk1206) > 90) && ((_sr_returned_date_sk669 - _ss_sold_date_sk1206) <= 120)) ? 1 : 0;
        int64_t _days3548L_sum_4 = ((_sr_returned_date_sk669 - _ss_sold_date_sk1206) > 120) ? 1 : 0;
        SW_Aggregate_TD_3396839_payload p{_days3544L_sum_0, _days3545L_sum_1, _days3546L_sum_2, _days3547L_sum_3, _days3548L_sum_4};
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
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383{};
        memcpy(_s_store_name383.data(), ((it.first)._s_store_name383).data(), ((it.first)._s_store_name383).length());
        tbl_Aggregate_TD_3396839_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _s_store_name383);
        tbl_Aggregate_TD_3396839_output.setInt32(r, 1, (it.first)._s_company_id394);
        std::array<char, TPCDS_READ_MAX + 1> _s_street_number396{};
        memcpy(_s_street_number396.data(), ((it.first)._s_street_number396).data(), ((it.first)._s_street_number396).length());
        tbl_Aggregate_TD_3396839_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_street_number396);
        std::array<char, TPCDS_READ_MAX + 1> _s_street_name397{};
        memcpy(_s_street_name397.data(), ((it.first)._s_street_name397).data(), ((it.first)._s_street_name397).length());
        tbl_Aggregate_TD_3396839_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _s_street_name397);
        std::array<char, TPCDS_READ_MAX + 1> _s_street_type398{};
        memcpy(_s_street_type398.data(), ((it.first)._s_street_type398).data(), ((it.first)._s_street_type398).length());
        tbl_Aggregate_TD_3396839_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _s_street_type398);
        std::array<char, TPCDS_READ_MAX + 1> _s_suite_number399{};
        memcpy(_s_suite_number399.data(), ((it.first)._s_suite_number399).data(), ((it.first)._s_suite_number399).length());
        tbl_Aggregate_TD_3396839_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_suite_number399);
        std::array<char, TPCDS_READ_MAX + 1> _s_city400{};
        memcpy(_s_city400.data(), ((it.first)._s_city400).data(), ((it.first)._s_city400).length());
        tbl_Aggregate_TD_3396839_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_city400);
        std::array<char, TPCDS_READ_MAX + 1> _s_county401{};
        memcpy(_s_county401.data(), ((it.first)._s_county401).data(), ((it.first)._s_county401).length());
        tbl_Aggregate_TD_3396839_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_county401);
        std::array<char, TPCDS_READ_MAX + 1> _s_state402{};
        memcpy(_s_state402.data(), ((it.first)._s_state402).data(), ((it.first)._s_state402).length());
        tbl_Aggregate_TD_3396839_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _s_state402);
        std::array<char, TPCDS_READ_MAX + 1> _s_zip403{};
        memcpy(_s_zip403.data(), ((it.first)._s_zip403).data(), ((it.first)._s_zip403).length());
        tbl_Aggregate_TD_3396839_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_zip403);
        int64_t _days3544L = (it.second)._days3544L_sum_0;
        tbl_Aggregate_TD_3396839_output.setInt64(r, 10, _days3544L);
        int64_t _days3545L = (it.second)._days3545L_sum_1;
        tbl_Aggregate_TD_3396839_output.setInt64(r, 11, _days3545L);
        int64_t _days3546L = (it.second)._days3546L_sum_2;
        tbl_Aggregate_TD_3396839_output.setInt64(r, 12, _days3546L);
        int64_t _days3547L = (it.second)._days3547L_sum_3;
        tbl_Aggregate_TD_3396839_output.setInt64(r, 13, _days3547L);
        int64_t _days3548L = (it.second)._days3548L_sum_4;
        tbl_Aggregate_TD_3396839_output.setInt64(r, 14, _days3548L);
        ++r;
    }
    tbl_Aggregate_TD_3396839_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_3396839_output #Row: " << tbl_Aggregate_TD_3396839_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2559866(Table &tbl_Aggregate_TD_3396839_output, Table &tbl_Sort_TD_2559866_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(s_store_name#383 ASC NULLS FIRST, s_company_id#394 ASC NULLS FIRST, s_street_number#396 ASC NULLS FIRST, s_street_name#397 ASC NULLS FIRST, s_street_type#398 ASC NULLS FIRST, s_suite_number#399 ASC NULLS FIRST, s_city#400 ASC NULLS FIRST, s_county#401 ASC NULLS FIRST, s_state#402 ASC NULLS FIRST, s_zip#403 ASC NULLS FIRST)
    // Input: ListBuffer(s_store_name#383, s_company_id#394, s_street_number#396, s_street_name#397, s_street_type#398, s_suite_number#399, s_city#400, s_county#401, s_state#402, s_zip#403, 30 days#3544L, 31-60 days#3545L, 61-90 days#3546L, 91-120 days#3547L, >120 days#3548L)
    // Output: ListBuffer(s_store_name#383, s_company_id#394, s_street_number#396, s_street_name#397, s_street_type#398, s_suite_number#399, s_city#400, s_county#401, s_state#402, s_zip#403, 30 days#3544L, 31-60 days#3545L, 61-90 days#3546L, 91-120 days#3547L, >120 days#3548L)
    struct SW_Sort_TD_2559866Row {
        std::string _s_store_name383;
        int32_t _s_company_id394;
        std::string _s_street_number396;
        std::string _s_street_name397;
        std::string _s_street_type398;
        std::string _s_suite_number399;
        std::string _s_city400;
        std::string _s_county401;
        std::string _s_state402;
        std::string _s_zip403;
        int64_t _days3544L;
        int64_t _days3545L;
        int64_t _days3546L;
        int64_t _days3547L;
        int64_t _days3548L;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2559866Row& a, const SW_Sort_TD_2559866Row& b) const { return 
 (a._s_store_name383 < b._s_store_name383) || 
 ((a._s_store_name383 == b._s_store_name383) && (a._s_company_id394 < b._s_company_id394)) || 
 ((a._s_store_name383 == b._s_store_name383) && (a._s_company_id394 == b._s_company_id394) && (a._s_street_number396 < b._s_street_number396)) || 
 ((a._s_store_name383 == b._s_store_name383) && (a._s_company_id394 == b._s_company_id394) && (a._s_street_number396 == b._s_street_number396) && (a._s_street_name397 < b._s_street_name397)) || 
 ((a._s_store_name383 == b._s_store_name383) && (a._s_company_id394 == b._s_company_id394) && (a._s_street_number396 == b._s_street_number396) && (a._s_street_name397 == b._s_street_name397) && (a._s_street_type398 < b._s_street_type398)) || 
 ((a._s_store_name383 == b._s_store_name383) && (a._s_company_id394 == b._s_company_id394) && (a._s_street_number396 == b._s_street_number396) && (a._s_street_name397 == b._s_street_name397) && (a._s_street_type398 == b._s_street_type398) && (a._s_suite_number399 < b._s_suite_number399)) || 
 ((a._s_store_name383 == b._s_store_name383) && (a._s_company_id394 == b._s_company_id394) && (a._s_street_number396 == b._s_street_number396) && (a._s_street_name397 == b._s_street_name397) && (a._s_street_type398 == b._s_street_type398) && (a._s_suite_number399 == b._s_suite_number399) && (a._s_city400 < b._s_city400)) || 
 ((a._s_store_name383 == b._s_store_name383) && (a._s_company_id394 == b._s_company_id394) && (a._s_street_number396 == b._s_street_number396) && (a._s_street_name397 == b._s_street_name397) && (a._s_street_type398 == b._s_street_type398) && (a._s_suite_number399 == b._s_suite_number399) && (a._s_city400 == b._s_city400) && (a._s_county401 < b._s_county401)) || 
 ((a._s_store_name383 == b._s_store_name383) && (a._s_company_id394 == b._s_company_id394) && (a._s_street_number396 == b._s_street_number396) && (a._s_street_name397 == b._s_street_name397) && (a._s_street_type398 == b._s_street_type398) && (a._s_suite_number399 == b._s_suite_number399) && (a._s_city400 == b._s_city400) && (a._s_county401 == b._s_county401) && (a._s_state402 < b._s_state402)) || 
 ((a._s_store_name383 == b._s_store_name383) && (a._s_company_id394 == b._s_company_id394) && (a._s_street_number396 == b._s_street_number396) && (a._s_street_name397 == b._s_street_name397) && (a._s_street_type398 == b._s_street_type398) && (a._s_suite_number399 == b._s_suite_number399) && (a._s_city400 == b._s_city400) && (a._s_county401 == b._s_county401) && (a._s_state402 == b._s_state402) && (a._s_zip403 < b._s_zip403)); 
}
    }SW_Sort_TD_2559866_order; 

    int nrow1 = tbl_Aggregate_TD_3396839_output.getNumRow();
    std::vector<SW_Sort_TD_2559866Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383 = tbl_Aggregate_TD_3396839_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        int32_t _s_company_id394 = tbl_Aggregate_TD_3396839_output.getInt32(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _s_street_number396 = tbl_Aggregate_TD_3396839_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _s_street_name397 = tbl_Aggregate_TD_3396839_output.getcharN<char, TPCDS_READ_MAX +1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _s_street_type398 = tbl_Aggregate_TD_3396839_output.getcharN<char, TPCDS_READ_MAX +1>(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _s_suite_number399 = tbl_Aggregate_TD_3396839_output.getcharN<char, TPCDS_READ_MAX +1>(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _s_city400 = tbl_Aggregate_TD_3396839_output.getcharN<char, TPCDS_READ_MAX +1>(i, 6);
        std::array<char, TPCDS_READ_MAX + 1> _s_county401 = tbl_Aggregate_TD_3396839_output.getcharN<char, TPCDS_READ_MAX +1>(i, 7);
        std::array<char, TPCDS_READ_MAX + 1> _s_state402 = tbl_Aggregate_TD_3396839_output.getcharN<char, TPCDS_READ_MAX +1>(i, 8);
        std::array<char, TPCDS_READ_MAX + 1> _s_zip403 = tbl_Aggregate_TD_3396839_output.getcharN<char, TPCDS_READ_MAX +1>(i, 9);
        int64_t _days3544L = tbl_Aggregate_TD_3396839_output.getInt64(i, 10);
        int64_t _days3545L = tbl_Aggregate_TD_3396839_output.getInt64(i, 11);
        int64_t _days3546L = tbl_Aggregate_TD_3396839_output.getInt64(i, 12);
        int64_t _days3547L = tbl_Aggregate_TD_3396839_output.getInt64(i, 13);
        int64_t _days3548L = tbl_Aggregate_TD_3396839_output.getInt64(i, 14);
        SW_Sort_TD_2559866Row t = {std::string(_s_store_name383.data()),_s_company_id394,std::string(_s_street_number396.data()),std::string(_s_street_name397.data()),std::string(_s_street_type398.data()),std::string(_s_suite_number399.data()),std::string(_s_city400.data()),std::string(_s_county401.data()),std::string(_s_state402.data()),std::string(_s_zip403.data()),_days3544L,_days3545L,_days3546L,_days3547L,_days3548L};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2559866_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383{};
        memcpy(_s_store_name383.data(), (it._s_store_name383).data(), (it._s_store_name383).length());
        tbl_Sort_TD_2559866_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _s_store_name383);
        tbl_Sort_TD_2559866_output.setInt32(r, 1, it._s_company_id394);
        std::array<char, TPCDS_READ_MAX + 1> _s_street_number396{};
        memcpy(_s_street_number396.data(), (it._s_street_number396).data(), (it._s_street_number396).length());
        tbl_Sort_TD_2559866_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _s_street_number396);
        std::array<char, TPCDS_READ_MAX + 1> _s_street_name397{};
        memcpy(_s_street_name397.data(), (it._s_street_name397).data(), (it._s_street_name397).length());
        tbl_Sort_TD_2559866_output.setcharN<char, TPCDS_READ_MAX +1>(r, 3, _s_street_name397);
        std::array<char, TPCDS_READ_MAX + 1> _s_street_type398{};
        memcpy(_s_street_type398.data(), (it._s_street_type398).data(), (it._s_street_type398).length());
        tbl_Sort_TD_2559866_output.setcharN<char, TPCDS_READ_MAX +1>(r, 4, _s_street_type398);
        std::array<char, TPCDS_READ_MAX + 1> _s_suite_number399{};
        memcpy(_s_suite_number399.data(), (it._s_suite_number399).data(), (it._s_suite_number399).length());
        tbl_Sort_TD_2559866_output.setcharN<char, TPCDS_READ_MAX +1>(r, 5, _s_suite_number399);
        std::array<char, TPCDS_READ_MAX + 1> _s_city400{};
        memcpy(_s_city400.data(), (it._s_city400).data(), (it._s_city400).length());
        tbl_Sort_TD_2559866_output.setcharN<char, TPCDS_READ_MAX +1>(r, 6, _s_city400);
        std::array<char, TPCDS_READ_MAX + 1> _s_county401{};
        memcpy(_s_county401.data(), (it._s_county401).data(), (it._s_county401).length());
        tbl_Sort_TD_2559866_output.setcharN<char, TPCDS_READ_MAX +1>(r, 7, _s_county401);
        std::array<char, TPCDS_READ_MAX + 1> _s_state402{};
        memcpy(_s_state402.data(), (it._s_state402).data(), (it._s_state402).length());
        tbl_Sort_TD_2559866_output.setcharN<char, TPCDS_READ_MAX +1>(r, 8, _s_state402);
        std::array<char, TPCDS_READ_MAX + 1> _s_zip403{};
        memcpy(_s_zip403.data(), (it._s_zip403).data(), (it._s_zip403).length());
        tbl_Sort_TD_2559866_output.setcharN<char, TPCDS_READ_MAX +1>(r, 9, _s_zip403);
        tbl_Sort_TD_2559866_output.setInt64(r, 10, it._days3544L);
        tbl_Sort_TD_2559866_output.setInt64(r, 11, it._days3545L);
        tbl_Sort_TD_2559866_output.setInt64(r, 12, it._days3546L);
        tbl_Sort_TD_2559866_output.setInt64(r, 13, it._days3547L);
        tbl_Sort_TD_2559866_output.setInt64(r, 14, it._days3548L);
        ++r;
    }
    tbl_Sort_TD_2559866_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2559866_output #Row: " << tbl_Sort_TD_2559866_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1902271(Table &tbl_Sort_TD_2559866_output, Table &tbl_LocalLimit_TD_1902271_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(s_store_name#383, s_company_id#394, s_street_number#396, s_street_name#397, s_street_type#398, s_suite_number#399, s_city#400, s_county#401, s_state#402, s_zip#403, 30 days#3544L, 31-60 days#3545L, 61-90 days#3546L, 91-120 days#3547L, >120 days#3548L)
    // Output: ListBuffer(s_store_name#383, s_company_id#394, s_street_number#396, s_street_name#397, s_street_type#398, s_suite_number#399, s_city#400, s_county#401, s_state#402, s_zip#403, 30 days#3544L, 31-60 days#3545L, 61-90 days#3546L, 91-120 days#3547L, >120 days#3548L)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_Sort_TD_2559866_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1902271_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _s_store_name383_n);
        tbl_LocalLimit_TD_1902271_output.setInt32(r, 1, tbl_Sort_TD_2559866_output.getInt32(i, 1));
        std::array<char, TPCDS_READ_MAX + 1> _s_street_number396_n = tbl_Sort_TD_2559866_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_LocalLimit_TD_1902271_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_street_number396_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_street_name397_n = tbl_Sort_TD_2559866_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_LocalLimit_TD_1902271_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _s_street_name397_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_street_type398_n = tbl_Sort_TD_2559866_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        tbl_LocalLimit_TD_1902271_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _s_street_type398_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_suite_number399_n = tbl_Sort_TD_2559866_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        tbl_LocalLimit_TD_1902271_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_suite_number399_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_city400_n = tbl_Sort_TD_2559866_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        tbl_LocalLimit_TD_1902271_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_city400_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_county401_n = tbl_Sort_TD_2559866_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
        tbl_LocalLimit_TD_1902271_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_county401_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_state402_n = tbl_Sort_TD_2559866_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
        tbl_LocalLimit_TD_1902271_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _s_state402_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_Sort_TD_2559866_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
        tbl_LocalLimit_TD_1902271_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_zip403_n);
        tbl_LocalLimit_TD_1902271_output.setInt64(r, 10, tbl_Sort_TD_2559866_output.getInt64(i, 10));
        tbl_LocalLimit_TD_1902271_output.setInt64(r, 11, tbl_Sort_TD_2559866_output.getInt64(i, 11));
        tbl_LocalLimit_TD_1902271_output.setInt64(r, 12, tbl_Sort_TD_2559866_output.getInt64(i, 12));
        tbl_LocalLimit_TD_1902271_output.setInt64(r, 13, tbl_Sort_TD_2559866_output.getInt64(i, 13));
        tbl_LocalLimit_TD_1902271_output.setInt64(r, 14, tbl_Sort_TD_2559866_output.getInt64(i, 14));
        r++;
    }
    tbl_LocalLimit_TD_1902271_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1902271_output #Row: " << tbl_LocalLimit_TD_1902271_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0856848(Table &tbl_LocalLimit_TD_1902271_output, Table &tbl_GlobalLimit_TD_0856848_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(s_store_name#383, s_company_id#394, s_street_number#396, s_street_name#397, s_street_type#398, s_suite_number#399, s_city#400, s_county#401, s_state#402, s_zip#403, 30 days#3544L, 31-60 days#3545L, 61-90 days#3546L, 91-120 days#3547L, >120 days#3548L)
    // Output: ListBuffer(s_store_name#383, s_company_id#394, s_street_number#396, s_street_name#397, s_street_type#398, s_suite_number#399, s_city#400, s_county#401, s_state#402, s_zip#403, 30 days#3544L, 31-60 days#3545L, 61-90 days#3546L, 91-120 days#3547L, >120 days#3548L)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_LocalLimit_TD_1902271_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0856848_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _s_store_name383_n);
        tbl_GlobalLimit_TD_0856848_output.setInt32(r, 1, tbl_LocalLimit_TD_1902271_output.getInt32(i, 1));
        std::array<char, TPCDS_READ_MAX + 1> _s_street_number396_n = tbl_LocalLimit_TD_1902271_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_GlobalLimit_TD_0856848_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_street_number396_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_street_name397_n = tbl_LocalLimit_TD_1902271_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_GlobalLimit_TD_0856848_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _s_street_name397_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_street_type398_n = tbl_LocalLimit_TD_1902271_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        tbl_GlobalLimit_TD_0856848_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _s_street_type398_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_suite_number399_n = tbl_LocalLimit_TD_1902271_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        tbl_GlobalLimit_TD_0856848_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_suite_number399_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_city400_n = tbl_LocalLimit_TD_1902271_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        tbl_GlobalLimit_TD_0856848_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_city400_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_county401_n = tbl_LocalLimit_TD_1902271_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
        tbl_GlobalLimit_TD_0856848_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_county401_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_state402_n = tbl_LocalLimit_TD_1902271_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
        tbl_GlobalLimit_TD_0856848_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _s_state402_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_LocalLimit_TD_1902271_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
        tbl_GlobalLimit_TD_0856848_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_zip403_n);
        tbl_GlobalLimit_TD_0856848_output.setInt64(r, 10, tbl_LocalLimit_TD_1902271_output.getInt64(i, 10));
        tbl_GlobalLimit_TD_0856848_output.setInt64(r, 11, tbl_LocalLimit_TD_1902271_output.getInt64(i, 11));
        tbl_GlobalLimit_TD_0856848_output.setInt64(r, 12, tbl_LocalLimit_TD_1902271_output.getInt64(i, 12));
        tbl_GlobalLimit_TD_0856848_output.setInt64(r, 13, tbl_LocalLimit_TD_1902271_output.getInt64(i, 13));
        tbl_GlobalLimit_TD_0856848_output.setInt64(r, 14, tbl_LocalLimit_TD_1902271_output.getInt64(i, 14));
        r++;
    }
    tbl_GlobalLimit_TD_0856848_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0856848_output #Row: " << tbl_GlobalLimit_TD_0856848_output.getNumRow() << std::endl;
}

