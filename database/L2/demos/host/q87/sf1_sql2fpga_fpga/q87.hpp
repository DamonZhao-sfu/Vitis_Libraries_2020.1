#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_8493865(Table &tbl_SerializeFromObject_TD_9538659_input, Table &tbl_Filter_TD_8493865_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_month_seq#3547) AND ((d_month_seq#3547 >= 1200) AND (d_month_seq#3547 <= 1211))) AND isnotnull(d_date_sk#3544)))
    // Input: ListBuffer(d_date_sk#3544, d_date#3546, d_month_seq#3547)
    // Output: ListBuffer(d_date_sk#3544, d_date#3546)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9538659_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_month_seq3547 = tbl_SerializeFromObject_TD_9538659_input.getInt32(i, 2);
        int32_t _d_date_sk3544 = tbl_SerializeFromObject_TD_9538659_input.getInt32(i, 0);
        if (((_d_month_seq3547!= 0) && ((_d_month_seq3547 >= 1200) && (_d_month_seq3547 <= 1211))) && (_d_date_sk3544!= 0)) {
            int32_t _d_date_sk3544_t = tbl_SerializeFromObject_TD_9538659_input.getInt32(i, 0);
            tbl_Filter_TD_8493865_output.setInt32(r, 0, _d_date_sk3544_t);
            int32_t _d_date3546_t = tbl_SerializeFromObject_TD_9538659_input.getInt32(i, 1);
            tbl_Filter_TD_8493865_output.setInt32(r, 1, _d_date3546_t);
            r++;
        }
    }
    tbl_Filter_TD_8493865_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8493865_output #Row: " << tbl_Filter_TD_8493865_output.getNumRow() << std::endl;
}

void SW_Filter_TD_863215(Table &tbl_SerializeFromObject_TD_9868367_input, Table &tbl_Filter_TD_863215_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cs_sold_date_sk#1104) AND isnotnull(cs_bill_customer_sk#1107)))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9868367_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_9868367_input.getInt32(i, 0);
        int32_t _cs_bill_customer_sk1107 = tbl_SerializeFromObject_TD_9868367_input.getInt32(i, 1);
        if ((_cs_sold_date_sk1104!= 0) && (_cs_bill_customer_sk1107!= 0)) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_9868367_input.getInt32(i, 0);
            tbl_Filter_TD_863215_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int32_t _cs_bill_customer_sk1107_t = tbl_SerializeFromObject_TD_9868367_input.getInt32(i, 1);
            tbl_Filter_TD_863215_output.setInt32(r, 1, _cs_bill_customer_sk1107_t);
            r++;
        }
    }
    tbl_Filter_TD_863215_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_863215_output #Row: " << tbl_Filter_TD_863215_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8451687(Table &tbl_SerializeFromObject_TD_9267166_input, Table &tbl_Filter_TD_8451687_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_month_seq#123) AND ((d_month_seq#123 >= 1200) AND (d_month_seq#123 <= 1211))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_date#122, d_month_seq#123)
    // Output: ListBuffer(d_date_sk#120, d_date#122)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9267166_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_month_seq123 = tbl_SerializeFromObject_TD_9267166_input.getInt32(i, 2);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_9267166_input.getInt32(i, 0);
        if (((_d_month_seq123!= 0) && ((_d_month_seq123 >= 1200) && (_d_month_seq123 <= 1211))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_9267166_input.getInt32(i, 0);
            tbl_Filter_TD_8451687_output.setInt32(r, 0, _d_date_sk120_t);
            int32_t _d_date122_t = tbl_SerializeFromObject_TD_9267166_input.getInt32(i, 1);
            tbl_Filter_TD_8451687_output.setInt32(r, 1, _d_date122_t);
            r++;
        }
    }
    tbl_Filter_TD_8451687_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8451687_output #Row: " << tbl_Filter_TD_8451687_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8264333(Table &tbl_SerializeFromObject_TD_9514605_input, Table &tbl_Filter_TD_8264333_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_sold_date_sk#1206) AND isnotnull(ss_customer_sk#1209)))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_customer_sk#1209)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_customer_sk#1209)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9514605_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_9514605_input.getInt32(i, 0);
        int32_t _ss_customer_sk1209 = tbl_SerializeFromObject_TD_9514605_input.getInt32(i, 1);
        if ((_ss_sold_date_sk1206!= 0) && (_ss_customer_sk1209!= 0)) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_9514605_input.getInt32(i, 0);
            tbl_Filter_TD_8264333_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_customer_sk1209_t = tbl_SerializeFromObject_TD_9514605_input.getInt32(i, 1);
            tbl_Filter_TD_8264333_output.setInt32(r, 1, _ss_customer_sk1209_t);
            r++;
        }
    }
    tbl_Filter_TD_8264333_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8264333_output #Row: " << tbl_Filter_TD_8264333_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7165466(Table &tbl_SerializeFromObject_TD_833767_input, Table &tbl_Filter_TD_7165466_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(c_customer_sk#3572))
    // Input: ListBuffer(c_customer_sk#3572, c_first_name#3580, c_last_name#3581)
    // Output: ListBuffer(c_customer_sk#3572, c_first_name#3580, c_last_name#3581)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_833767_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk3572 = tbl_SerializeFromObject_TD_833767_input.getInt32(i, 0);
        if (_c_customer_sk3572!= 0) {
            int32_t _c_customer_sk3572_t = tbl_SerializeFromObject_TD_833767_input.getInt32(i, 0);
            tbl_Filter_TD_7165466_output.setInt32(r, 0, _c_customer_sk3572_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name3580_t = tbl_SerializeFromObject_TD_833767_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_7165466_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name3580_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name3581_t = tbl_SerializeFromObject_TD_833767_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_7165466_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name3581_t);
            r++;
        }
    }
    tbl_Filter_TD_7165466_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7165466_output #Row: " << tbl_Filter_TD_7165466_output.getNumRow() << std::endl;
}


void SW_Filter_TD_7677050(Table &tbl_SerializeFromObject_TD_8925315_input, Table &tbl_Filter_TD_7677050_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(c_customer_sk#0))
    // Input: ListBuffer(c_customer_sk#0, c_first_name#8, c_last_name#9)
    // Output: ListBuffer(c_customer_sk#0, c_first_name#8, c_last_name#9)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8925315_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk0 = tbl_SerializeFromObject_TD_8925315_input.getInt32(i, 0);
        if (_c_customer_sk0!= 0) {
            int32_t _c_customer_sk0_t = tbl_SerializeFromObject_TD_8925315_input.getInt32(i, 0);
            tbl_Filter_TD_7677050_output.setInt32(r, 0, _c_customer_sk0_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_t = tbl_SerializeFromObject_TD_8925315_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_7677050_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_t = tbl_SerializeFromObject_TD_8925315_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_7677050_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name9_t);
            r++;
        }
    }
    tbl_Filter_TD_7677050_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7677050_output #Row: " << tbl_Filter_TD_7677050_output.getNumRow() << std::endl;
}


void SW_Filter_TD_6781690(Table &tbl_SerializeFromObject_TD_7625798_input, Table &tbl_Filter_TD_6781690_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_month_seq#3593) AND ((d_month_seq#3593 >= 1200) AND (d_month_seq#3593 <= 1211))) AND isnotnull(d_date_sk#3590)))
    // Input: ListBuffer(d_date_sk#3590, d_date#3592, d_month_seq#3593)
    // Output: ListBuffer(d_date_sk#3590, d_date#3592)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7625798_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_month_seq3593 = tbl_SerializeFromObject_TD_7625798_input.getInt32(i, 2);
        int32_t _d_date_sk3590 = tbl_SerializeFromObject_TD_7625798_input.getInt32(i, 0);
        if (((_d_month_seq3593!= 0) && ((_d_month_seq3593 >= 1200) && (_d_month_seq3593 <= 1211))) && (_d_date_sk3590!= 0)) {
            int32_t _d_date_sk3590_t = tbl_SerializeFromObject_TD_7625798_input.getInt32(i, 0);
            tbl_Filter_TD_6781690_output.setInt32(r, 0, _d_date_sk3590_t);
            int32_t _d_date3592_t = tbl_SerializeFromObject_TD_7625798_input.getInt32(i, 1);
            tbl_Filter_TD_6781690_output.setInt32(r, 1, _d_date3592_t);
            r++;
        }
    }
    tbl_Filter_TD_6781690_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6781690_output #Row: " << tbl_Filter_TD_6781690_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6134278(Table &tbl_SerializeFromObject_TD_7816642_input, Table &tbl_Filter_TD_6134278_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_sold_date_sk#729) AND isnotnull(ws_bill_customer_sk#733)))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_bill_customer_sk#733)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_bill_customer_sk#733)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7816642_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_7816642_input.getInt32(i, 0);
        int32_t _ws_bill_customer_sk733 = tbl_SerializeFromObject_TD_7816642_input.getInt32(i, 1);
        if ((_ws_sold_date_sk729!= 0) && (_ws_bill_customer_sk733!= 0)) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_7816642_input.getInt32(i, 0);
            tbl_Filter_TD_6134278_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_bill_customer_sk733_t = tbl_SerializeFromObject_TD_7816642_input.getInt32(i, 1);
            tbl_Filter_TD_6134278_output.setInt32(r, 1, _ws_bill_customer_sk733_t);
            r++;
        }
    }
    tbl_Filter_TD_6134278_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6134278_output #Row: " << tbl_Filter_TD_6134278_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6411803_key_leftMajor {
    int32_t _cs_bill_customer_sk1107;
    bool operator==(const SW_JOIN_INNER_TD_6411803_key_leftMajor& other) const {
        return ((_cs_bill_customer_sk1107 == other._cs_bill_customer_sk1107));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6411803_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6411803_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_bill_customer_sk1107));
    }
};
}
struct SW_JOIN_INNER_TD_6411803_payload_leftMajor {
    int32_t _cs_bill_customer_sk1107;
    int32_t _d_date3546;
};
struct SW_JOIN_INNER_TD_6411803_key_rightMajor {
    int32_t _c_customer_sk3572;
    bool operator==(const SW_JOIN_INNER_TD_6411803_key_rightMajor& other) const {
        return ((_c_customer_sk3572 == other._c_customer_sk3572));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6411803_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6411803_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk3572));
    }
};
}
struct SW_JOIN_INNER_TD_6411803_payload_rightMajor {
    int32_t _c_customer_sk3572;
    std::string _c_first_name3580;
    std::string _c_last_name3581;
};
void SW_JOIN_INNER_TD_6411803(Table &tbl_JOIN_INNER_TD_7485296_output, Table &tbl_Filter_TD_7165466_output, Table &tbl_JOIN_INNER_TD_6411803_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_bill_customer_sk#1107 = c_customer_sk#3572))
    // Left Table: ListBuffer(cs_bill_customer_sk#1107, d_date#3546)
    // Right Table: ListBuffer(c_customer_sk#3572, c_first_name#3580, c_last_name#3581)
    // Output Table: ListBuffer(c_last_name#3581, c_first_name#3580, d_date#3546)
    int left_nrow = tbl_JOIN_INNER_TD_7485296_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7165466_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6411803_key_leftMajor, SW_JOIN_INNER_TD_6411803_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7485296_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_bill_customer_sk1107_k = tbl_JOIN_INNER_TD_7485296_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6411803_key_leftMajor keyA{_cs_bill_customer_sk1107_k};
            int32_t _cs_bill_customer_sk1107 = tbl_JOIN_INNER_TD_7485296_output.getInt32(i, 0);
            int32_t _d_date3546 = tbl_JOIN_INNER_TD_7485296_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_6411803_payload_leftMajor payloadA{_cs_bill_customer_sk1107, _d_date3546};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7165466_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk3572_k = tbl_Filter_TD_7165466_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6411803_key_leftMajor{_c_customer_sk3572_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_bill_customer_sk1107 = (it->second)._cs_bill_customer_sk1107;
                int32_t _d_date3546 = (it->second)._d_date3546;
                int32_t _c_customer_sk3572 = tbl_Filter_TD_7165466_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name3580_n = tbl_Filter_TD_7165466_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_first_name3580 = std::string(_c_first_name3580_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name3581_n = tbl_Filter_TD_7165466_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_last_name3581 = std::string(_c_last_name3581_n.data());
                tbl_JOIN_INNER_TD_6411803_output.setInt32(r, 2, _d_date3546);
                tbl_JOIN_INNER_TD_6411803_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name3580_n);
                tbl_JOIN_INNER_TD_6411803_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name3581_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6411803_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6411803_key_rightMajor, SW_JOIN_INNER_TD_6411803_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7165466_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk3572_k = tbl_Filter_TD_7165466_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6411803_key_rightMajor keyA{_c_customer_sk3572_k};
            int32_t _c_customer_sk3572 = tbl_Filter_TD_7165466_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name3580_n = tbl_Filter_TD_7165466_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_first_name3580 = std::string(_c_first_name3580_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name3581_n = tbl_Filter_TD_7165466_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_last_name3581 = std::string(_c_last_name3581_n.data());
            SW_JOIN_INNER_TD_6411803_payload_rightMajor payloadA{_c_customer_sk3572, _c_first_name3580, _c_last_name3581};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7485296_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_bill_customer_sk1107_k = tbl_JOIN_INNER_TD_7485296_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6411803_key_rightMajor{_cs_bill_customer_sk1107_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk3572 = (it->second)._c_customer_sk3572;
                std::string _c_first_name3580 = (it->second)._c_first_name3580;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name3580_n{};
                memcpy(_c_first_name3580_n.data(), (_c_first_name3580).data(), (_c_first_name3580).length());
                std::string _c_last_name3581 = (it->second)._c_last_name3581;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name3581_n{};
                memcpy(_c_last_name3581_n.data(), (_c_last_name3581).data(), (_c_last_name3581).length());
                int32_t _cs_bill_customer_sk1107 = tbl_JOIN_INNER_TD_7485296_output.getInt32(i, 0);
                int32_t _d_date3546 = tbl_JOIN_INNER_TD_7485296_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_6411803_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name3580_n);
                tbl_JOIN_INNER_TD_6411803_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name3581_n);
                tbl_JOIN_INNER_TD_6411803_output.setInt32(r, 2, _d_date3546);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6411803_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6411803_output #Row: " << tbl_JOIN_INNER_TD_6411803_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6410541_key_leftMajor {
    int32_t _ss_customer_sk1209;
    bool operator==(const SW_JOIN_INNER_TD_6410541_key_leftMajor& other) const {
        return ((_ss_customer_sk1209 == other._ss_customer_sk1209));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6410541_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6410541_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_customer_sk1209));
    }
};
}
struct SW_JOIN_INNER_TD_6410541_payload_leftMajor {
    int32_t _ss_customer_sk1209;
    int32_t _d_date122;
};
struct SW_JOIN_INNER_TD_6410541_key_rightMajor {
    int32_t _c_customer_sk0;
    bool operator==(const SW_JOIN_INNER_TD_6410541_key_rightMajor& other) const {
        return ((_c_customer_sk0 == other._c_customer_sk0));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6410541_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6410541_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk0));
    }
};
}
struct SW_JOIN_INNER_TD_6410541_payload_rightMajor {
    int32_t _c_customer_sk0;
    std::string _c_first_name8;
    std::string _c_last_name9;
};
void SW_JOIN_INNER_TD_6410541(Table &tbl_JOIN_INNER_TD_7237780_output, Table &tbl_Filter_TD_7677050_output, Table &tbl_JOIN_INNER_TD_6410541_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_customer_sk#1209 = c_customer_sk#0))
    // Left Table: ListBuffer(ss_customer_sk#1209, d_date#122)
    // Right Table: ListBuffer(c_customer_sk#0, c_first_name#8, c_last_name#9)
    // Output Table: ListBuffer(c_last_name#9, c_first_name#8, d_date#122)
    int left_nrow = tbl_JOIN_INNER_TD_7237780_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7677050_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6410541_key_leftMajor, SW_JOIN_INNER_TD_6410541_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7237780_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_customer_sk1209_k = tbl_JOIN_INNER_TD_7237780_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6410541_key_leftMajor keyA{_ss_customer_sk1209_k};
            int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_7237780_output.getInt32(i, 0);
            int32_t _d_date122 = tbl_JOIN_INNER_TD_7237780_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_6410541_payload_leftMajor payloadA{_ss_customer_sk1209, _d_date122};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7677050_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_7677050_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6410541_key_leftMajor{_c_customer_sk0_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                int32_t _d_date122 = (it->second)._d_date122;
                int32_t _c_customer_sk0 = tbl_Filter_TD_7677050_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_Filter_TD_7677050_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_first_name8 = std::string(_c_first_name8_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_Filter_TD_7677050_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_last_name9 = std::string(_c_last_name9_n.data());
                tbl_JOIN_INNER_TD_6410541_output.setInt32(r, 2, _d_date122);
                tbl_JOIN_INNER_TD_6410541_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
                tbl_JOIN_INNER_TD_6410541_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name9_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6410541_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6410541_key_rightMajor, SW_JOIN_INNER_TD_6410541_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7677050_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_7677050_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6410541_key_rightMajor keyA{_c_customer_sk0_k};
            int32_t _c_customer_sk0 = tbl_Filter_TD_7677050_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_Filter_TD_7677050_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_first_name8 = std::string(_c_first_name8_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_Filter_TD_7677050_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_last_name9 = std::string(_c_last_name9_n.data());
            SW_JOIN_INNER_TD_6410541_payload_rightMajor payloadA{_c_customer_sk0, _c_first_name8, _c_last_name9};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7237780_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_customer_sk1209_k = tbl_JOIN_INNER_TD_7237780_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6410541_key_rightMajor{_ss_customer_sk1209_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk0 = (it->second)._c_customer_sk0;
                std::string _c_first_name8 = (it->second)._c_first_name8;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n{};
                memcpy(_c_first_name8_n.data(), (_c_first_name8).data(), (_c_first_name8).length());
                std::string _c_last_name9 = (it->second)._c_last_name9;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n{};
                memcpy(_c_last_name9_n.data(), (_c_last_name9).data(), (_c_last_name9).length());
                int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_7237780_output.getInt32(i, 0);
                int32_t _d_date122 = tbl_JOIN_INNER_TD_7237780_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_6410541_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
                tbl_JOIN_INNER_TD_6410541_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name9_n);
                tbl_JOIN_INNER_TD_6410541_output.setInt32(r, 2, _d_date122);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6410541_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6410541_output #Row: " << tbl_JOIN_INNER_TD_6410541_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5495216(Table &tbl_SerializeFromObject_TD_6409310_input, Table &tbl_Filter_TD_5495216_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(c_customer_sk#3618))
    // Input: ListBuffer(c_customer_sk#3618, c_first_name#3626, c_last_name#3627)
    // Output: ListBuffer(c_customer_sk#3618, c_first_name#3626, c_last_name#3627)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6409310_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk3618 = tbl_SerializeFromObject_TD_6409310_input.getInt32(i, 0);
        if (_c_customer_sk3618!= 0) {
            int32_t _c_customer_sk3618_t = tbl_SerializeFromObject_TD_6409310_input.getInt32(i, 0);
            tbl_Filter_TD_5495216_output.setInt32(r, 0, _c_customer_sk3618_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name3626_t = tbl_SerializeFromObject_TD_6409310_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_5495216_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name3626_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name3627_t = tbl_SerializeFromObject_TD_6409310_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_5495216_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name3627_t);
            r++;
        }
    }
    tbl_Filter_TD_5495216_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5495216_output #Row: " << tbl_Filter_TD_5495216_output.getNumRow() << std::endl;
}


struct SW_Aggregate_TD_5916216_key {
    std::string _c_last_name3581;
    std::string _c_first_name3580;
    int32_t _d_date3546;
    bool operator==(const SW_Aggregate_TD_5916216_key& other) const { return (_c_last_name3581 == other._c_last_name3581) && (_c_first_name3580 == other._c_first_name3580) && (_d_date3546 == other._d_date3546); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_5916216_key> {
    std::size_t operator() (const SW_Aggregate_TD_5916216_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._c_last_name3581)) + (hash<string>()(k._c_first_name3580)) + (hash<int32_t>()(k._d_date3546));
    }
};
}
struct SW_Aggregate_TD_5916216_payload {
};
void SW_Aggregate_TD_5916216(Table &tbl_JOIN_INNER_TD_6411803_output, Table &tbl_Aggregate_TD_5916216_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_last_name#3581, c_first_name#3580, d_date#3546)
    // Input: ListBuffer(c_last_name#3581, c_first_name#3580, d_date#3546)
    // Output: ListBuffer(c_last_name#3581, c_first_name#3580, d_date#3546)
    std::unordered_map<SW_Aggregate_TD_5916216_key, SW_Aggregate_TD_5916216_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_6411803_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name3581 = tbl_JOIN_INNER_TD_6411803_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name3580 = tbl_JOIN_INNER_TD_6411803_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _d_date3546 = tbl_JOIN_INNER_TD_6411803_output.getInt32(i, 2);
        SW_Aggregate_TD_5916216_key k{std::string(_c_last_name3581.data()), std::string(_c_first_name3580.data()), _d_date3546};
        SW_Aggregate_TD_5916216_payload p{};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name3581{};
        memcpy(_c_last_name3581.data(), ((it.first)._c_last_name3581).data(), ((it.first)._c_last_name3581).length());
        tbl_Aggregate_TD_5916216_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name3581);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name3580{};
        memcpy(_c_first_name3580.data(), ((it.first)._c_first_name3580).data(), ((it.first)._c_first_name3580).length());
        tbl_Aggregate_TD_5916216_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name3580);
        tbl_Aggregate_TD_5916216_output.setInt32(r, 2, (it.first)._d_date3546);
        ++r;
    }
    tbl_Aggregate_TD_5916216_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_5916216_output #Row: " << tbl_Aggregate_TD_5916216_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_5334987_key {
    std::string _c_last_name9;
    std::string _c_first_name8;
    int32_t _d_date122;
    bool operator==(const SW_Aggregate_TD_5334987_key& other) const { return (_c_last_name9 == other._c_last_name9) && (_c_first_name8 == other._c_first_name8) && (_d_date122 == other._d_date122); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_5334987_key> {
    std::size_t operator() (const SW_Aggregate_TD_5334987_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._c_last_name9)) + (hash<string>()(k._c_first_name8)) + (hash<int32_t>()(k._d_date122));
    }
};
}
struct SW_Aggregate_TD_5334987_payload {
};
void SW_Aggregate_TD_5334987(Table &tbl_JOIN_INNER_TD_6410541_output, Table &tbl_Aggregate_TD_5334987_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_last_name#9, c_first_name#8, d_date#122)
    // Input: ListBuffer(c_last_name#9, c_first_name#8, d_date#122)
    // Output: ListBuffer(c_last_name#9, c_first_name#8, d_date#122)
    std::unordered_map<SW_Aggregate_TD_5334987_key, SW_Aggregate_TD_5334987_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_6410541_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9 = tbl_JOIN_INNER_TD_6410541_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8 = tbl_JOIN_INNER_TD_6410541_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _d_date122 = tbl_JOIN_INNER_TD_6410541_output.getInt32(i, 2);
        SW_Aggregate_TD_5334987_key k{std::string(_c_last_name9.data()), std::string(_c_first_name8.data()), _d_date122};
        SW_Aggregate_TD_5334987_payload p{};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9{};
        memcpy(_c_last_name9.data(), ((it.first)._c_last_name9).data(), ((it.first)._c_last_name9).length());
        tbl_Aggregate_TD_5334987_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name9);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8{};
        memcpy(_c_first_name8.data(), ((it.first)._c_first_name8).data(), ((it.first)._c_first_name8).length());
        tbl_Aggregate_TD_5334987_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8);
        tbl_Aggregate_TD_5334987_output.setInt32(r, 2, (it.first)._d_date122);
        ++r;
    }
    tbl_Aggregate_TD_5334987_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_5334987_output #Row: " << tbl_Aggregate_TD_5334987_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4561328_key_leftMajor {
    int32_t _ws_bill_customer_sk733;
    bool operator==(const SW_JOIN_INNER_TD_4561328_key_leftMajor& other) const {
        return ((_ws_bill_customer_sk733 == other._ws_bill_customer_sk733));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4561328_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4561328_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_bill_customer_sk733));
    }
};
}
struct SW_JOIN_INNER_TD_4561328_payload_leftMajor {
    int32_t _ws_bill_customer_sk733;
    int32_t _d_date3592;
};
struct SW_JOIN_INNER_TD_4561328_key_rightMajor {
    int32_t _c_customer_sk3618;
    bool operator==(const SW_JOIN_INNER_TD_4561328_key_rightMajor& other) const {
        return ((_c_customer_sk3618 == other._c_customer_sk3618));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4561328_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4561328_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk3618));
    }
};
}
struct SW_JOIN_INNER_TD_4561328_payload_rightMajor {
    int32_t _c_customer_sk3618;
    std::string _c_first_name3626;
    std::string _c_last_name3627;
};
void SW_JOIN_INNER_TD_4561328(Table &tbl_JOIN_INNER_TD_5148663_output, Table &tbl_Filter_TD_5495216_output, Table &tbl_JOIN_INNER_TD_4561328_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_bill_customer_sk#733 = c_customer_sk#3618))
    // Left Table: ListBuffer(ws_bill_customer_sk#733, d_date#3592)
    // Right Table: ListBuffer(c_customer_sk#3618, c_first_name#3626, c_last_name#3627)
    // Output Table: ListBuffer(c_last_name#3627, c_first_name#3626, d_date#3592)
    int left_nrow = tbl_JOIN_INNER_TD_5148663_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5495216_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4561328_key_leftMajor, SW_JOIN_INNER_TD_4561328_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_5148663_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_bill_customer_sk733_k = tbl_JOIN_INNER_TD_5148663_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4561328_key_leftMajor keyA{_ws_bill_customer_sk733_k};
            int32_t _ws_bill_customer_sk733 = tbl_JOIN_INNER_TD_5148663_output.getInt32(i, 0);
            int32_t _d_date3592 = tbl_JOIN_INNER_TD_5148663_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_4561328_payload_leftMajor payloadA{_ws_bill_customer_sk733, _d_date3592};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5495216_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk3618_k = tbl_Filter_TD_5495216_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4561328_key_leftMajor{_c_customer_sk3618_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_bill_customer_sk733 = (it->second)._ws_bill_customer_sk733;
                int32_t _d_date3592 = (it->second)._d_date3592;
                int32_t _c_customer_sk3618 = tbl_Filter_TD_5495216_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name3626_n = tbl_Filter_TD_5495216_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_first_name3626 = std::string(_c_first_name3626_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name3627_n = tbl_Filter_TD_5495216_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_last_name3627 = std::string(_c_last_name3627_n.data());
                tbl_JOIN_INNER_TD_4561328_output.setInt32(r, 2, _d_date3592);
                tbl_JOIN_INNER_TD_4561328_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name3626_n);
                tbl_JOIN_INNER_TD_4561328_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name3627_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4561328_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4561328_key_rightMajor, SW_JOIN_INNER_TD_4561328_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5495216_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk3618_k = tbl_Filter_TD_5495216_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4561328_key_rightMajor keyA{_c_customer_sk3618_k};
            int32_t _c_customer_sk3618 = tbl_Filter_TD_5495216_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name3626_n = tbl_Filter_TD_5495216_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_first_name3626 = std::string(_c_first_name3626_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name3627_n = tbl_Filter_TD_5495216_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_last_name3627 = std::string(_c_last_name3627_n.data());
            SW_JOIN_INNER_TD_4561328_payload_rightMajor payloadA{_c_customer_sk3618, _c_first_name3626, _c_last_name3627};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_5148663_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_bill_customer_sk733_k = tbl_JOIN_INNER_TD_5148663_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4561328_key_rightMajor{_ws_bill_customer_sk733_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk3618 = (it->second)._c_customer_sk3618;
                std::string _c_first_name3626 = (it->second)._c_first_name3626;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name3626_n{};
                memcpy(_c_first_name3626_n.data(), (_c_first_name3626).data(), (_c_first_name3626).length());
                std::string _c_last_name3627 = (it->second)._c_last_name3627;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name3627_n{};
                memcpy(_c_last_name3627_n.data(), (_c_last_name3627).data(), (_c_last_name3627).length());
                int32_t _ws_bill_customer_sk733 = tbl_JOIN_INNER_TD_5148663_output.getInt32(i, 0);
                int32_t _d_date3592 = tbl_JOIN_INNER_TD_5148663_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_4561328_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name3626_n);
                tbl_JOIN_INNER_TD_4561328_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name3627_n);
                tbl_JOIN_INNER_TD_4561328_output.setInt32(r, 2, _d_date3592);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4561328_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4561328_output #Row: " << tbl_JOIN_INNER_TD_4561328_output.getNumRow() << std::endl;
}

struct SW_JOIN_LEFTANTI_TD_4900814_key_leftMajor {
    std::string _c_last_name9;
    std::string _c_first_name8;
    int32_t _d_date122;
    bool operator==(const SW_JOIN_LEFTANTI_TD_4900814_key_leftMajor& other) const {
        return ((_c_last_name9 == other._c_last_name9) && (_c_first_name8 == other._c_first_name8) && (_d_date122 == other._d_date122));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTANTI_TD_4900814_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_LEFTANTI_TD_4900814_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._c_last_name9)) + (hash<string>()(k._c_first_name8)) + (hash<int32_t>()(k._d_date122));
    }
};
}
struct SW_JOIN_LEFTANTI_TD_4900814_payload_leftMajor {
    std::string _c_last_name9;
    std::string _c_first_name8;
    int32_t _d_date122;
};
struct SW_JOIN_LEFTANTI_TD_4900814_key_rightMajor {
    std::string _c_last_name3581;
    std::string _c_first_name3580;
    int32_t _d_date3546;
    bool operator==(const SW_JOIN_LEFTANTI_TD_4900814_key_rightMajor& other) const {
        return ((_c_last_name3581 == other._c_last_name3581) && (_c_first_name3580 == other._c_first_name3580) && (_d_date3546 == other._d_date3546));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTANTI_TD_4900814_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_LEFTANTI_TD_4900814_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._c_last_name3581)) + (hash<string>()(k._c_first_name3580)) + (hash<int32_t>()(k._d_date3546));
    }
};
}
struct SW_JOIN_LEFTANTI_TD_4900814_payload_rightMajor {
    std::string _c_last_name3581;
    std::string _c_first_name3580;
    int32_t _d_date3546;
};
void SW_JOIN_LEFTANTI_TD_4900814(Table &tbl_Aggregate_TD_5334987_output, Table &tbl_Aggregate_TD_5916216_output, Table &tbl_JOIN_LEFTANTI_TD_4900814_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTANTI
    // Operation: ListBuffer((((c_last_name#9 <=> c_last_name#3581) AND (c_first_name#8 <=> c_first_name#3580)) AND (d_date#122 <=> d_date#3546)))
    // Left Table: ListBuffer(c_last_name#9, c_first_name#8, d_date#122)
    // Right Table: ListBuffer(c_last_name#3581, c_first_name#3580, d_date#3546)
    // Output Table: ListBuffer(c_last_name#9, c_first_name#8, d_date#122)
    int left_nrow = tbl_Aggregate_TD_5334987_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_5916216_output.getNumRow();
        std::unordered_map<SW_JOIN_LEFTANTI_TD_4900814_key_rightMajor, SW_JOIN_LEFTANTI_TD_4900814_payload_rightMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_5916216_output.getNumRow();
        int nrow2 = tbl_Aggregate_TD_5334987_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name3581_k_n = tbl_Aggregate_TD_5916216_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _c_last_name3581_k = std::string(_c_last_name3581_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name3580_k_n = tbl_Aggregate_TD_5916216_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_first_name3580_k = std::string(_c_first_name3580_k_n.data());
            int32_t _d_date3546_k = tbl_Aggregate_TD_5916216_output.getInt32(i, 2);
            SW_JOIN_LEFTANTI_TD_4900814_key_rightMajor keyA{_c_last_name3581_k, _c_first_name3580_k, _d_date3546_k};
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name3581_n = tbl_Aggregate_TD_5916216_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _c_last_name3581 = std::string(_c_last_name3581_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name3580_n = tbl_Aggregate_TD_5916216_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_first_name3580 = std::string(_c_first_name3580_n.data());
            int32_t _d_date3546 = tbl_Aggregate_TD_5916216_output.getInt32(i, 2);
            SW_JOIN_LEFTANTI_TD_4900814_payload_rightMajor payloadA{_c_last_name3581, _c_first_name3580, _d_date3546};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_k_n = tbl_Aggregate_TD_5334987_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _c_last_name9_k = std::string(_c_last_name9_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_k_n = tbl_Aggregate_TD_5334987_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_first_name8_k = std::string(_c_first_name8_k_n.data());
            int32_t _d_date122_k = tbl_Aggregate_TD_5334987_output.getInt32(i, 2);
            auto it = ht1.find(SW_JOIN_LEFTANTI_TD_4900814_key_rightMajor{_c_last_name9_k, _c_first_name8_k, _d_date122_k});
            if (it == ht1.end()) {
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9 = tbl_Aggregate_TD_5334987_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8 = tbl_Aggregate_TD_5334987_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                int32_t _d_date122 = tbl_Aggregate_TD_5334987_output.getInt32(i, 2);
                tbl_JOIN_LEFTANTI_TD_4900814_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name9);
                tbl_JOIN_LEFTANTI_TD_4900814_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8);
                tbl_JOIN_LEFTANTI_TD_4900814_output.setInt32(r, 2, _d_date122);
                r++;
            }
        }
        tbl_JOIN_LEFTANTI_TD_4900814_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTANTI_TD_4900814_output #Row: " << tbl_JOIN_LEFTANTI_TD_4900814_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_3711086_key {
    std::string _c_last_name3627;
    std::string _c_first_name3626;
    int32_t _d_date3592;
    bool operator==(const SW_Aggregate_TD_3711086_key& other) const { return (_c_last_name3627 == other._c_last_name3627) && (_c_first_name3626 == other._c_first_name3626) && (_d_date3592 == other._d_date3592); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_3711086_key> {
    std::size_t operator() (const SW_Aggregate_TD_3711086_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._c_last_name3627)) + (hash<string>()(k._c_first_name3626)) + (hash<int32_t>()(k._d_date3592));
    }
};
}
struct SW_Aggregate_TD_3711086_payload {
};
void SW_Aggregate_TD_3711086(Table &tbl_JOIN_INNER_TD_4561328_output, Table &tbl_Aggregate_TD_3711086_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_last_name#3627, c_first_name#3626, d_date#3592)
    // Input: ListBuffer(c_last_name#3627, c_first_name#3626, d_date#3592)
    // Output: ListBuffer(c_last_name#3627, c_first_name#3626, d_date#3592)
    std::unordered_map<SW_Aggregate_TD_3711086_key, SW_Aggregate_TD_3711086_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_4561328_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name3627 = tbl_JOIN_INNER_TD_4561328_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name3626 = tbl_JOIN_INNER_TD_4561328_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _d_date3592 = tbl_JOIN_INNER_TD_4561328_output.getInt32(i, 2);
        SW_Aggregate_TD_3711086_key k{std::string(_c_last_name3627.data()), std::string(_c_first_name3626.data()), _d_date3592};
        SW_Aggregate_TD_3711086_payload p{};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name3627{};
        memcpy(_c_last_name3627.data(), ((it.first)._c_last_name3627).data(), ((it.first)._c_last_name3627).length());
        tbl_Aggregate_TD_3711086_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name3627);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name3626{};
        memcpy(_c_first_name3626.data(), ((it.first)._c_first_name3626).data(), ((it.first)._c_first_name3626).length());
        tbl_Aggregate_TD_3711086_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name3626);
        tbl_Aggregate_TD_3711086_output.setInt32(r, 2, (it.first)._d_date3592);
        ++r;
    }
    tbl_Aggregate_TD_3711086_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_3711086_output #Row: " << tbl_Aggregate_TD_3711086_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_35404_key {
    std::string _c_last_name9;
    std::string _c_first_name8;
    int32_t _d_date122;
    bool operator==(const SW_Aggregate_TD_35404_key& other) const { return (_c_last_name9 == other._c_last_name9) && (_c_first_name8 == other._c_first_name8) && (_d_date122 == other._d_date122); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_35404_key> {
    std::size_t operator() (const SW_Aggregate_TD_35404_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._c_last_name9)) + (hash<string>()(k._c_first_name8)) + (hash<int32_t>()(k._d_date122));
    }
};
}
struct SW_Aggregate_TD_35404_payload {
};
void SW_Aggregate_TD_35404(Table &tbl_JOIN_LEFTANTI_TD_4900814_output, Table &tbl_Aggregate_TD_35404_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_last_name#9, c_first_name#8, d_date#122)
    // Input: ListBuffer(c_last_name#9, c_first_name#8, d_date#122)
    // Output: ListBuffer(c_last_name#9, c_first_name#8, d_date#122)
    std::unordered_map<SW_Aggregate_TD_35404_key, SW_Aggregate_TD_35404_payload> ht1;
    int nrow1 = tbl_JOIN_LEFTANTI_TD_4900814_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9 = tbl_JOIN_LEFTANTI_TD_4900814_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8 = tbl_JOIN_LEFTANTI_TD_4900814_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _d_date122 = tbl_JOIN_LEFTANTI_TD_4900814_output.getInt32(i, 2);
        SW_Aggregate_TD_35404_key k{std::string(_c_last_name9.data()), std::string(_c_first_name8.data()), _d_date122};
        SW_Aggregate_TD_35404_payload p{};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9{};
        memcpy(_c_last_name9.data(), ((it.first)._c_last_name9).data(), ((it.first)._c_last_name9).length());
        tbl_Aggregate_TD_35404_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name9);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8{};
        memcpy(_c_first_name8.data(), ((it.first)._c_first_name8).data(), ((it.first)._c_first_name8).length());
        tbl_Aggregate_TD_35404_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8);
        tbl_Aggregate_TD_35404_output.setInt32(r, 2, (it.first)._d_date122);
        ++r;
    }
    tbl_Aggregate_TD_35404_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_35404_output #Row: " << tbl_Aggregate_TD_35404_output.getNumRow() << std::endl;
}

struct SW_JOIN_LEFTANTI_TD_2524386_key_leftMajor {
    std::string _c_last_name9;
    std::string _c_first_name8;
    int32_t _d_date122;
    bool operator==(const SW_JOIN_LEFTANTI_TD_2524386_key_leftMajor& other) const {
        return ((_c_last_name9 == other._c_last_name9) && (_c_first_name8 == other._c_first_name8) && (_d_date122 == other._d_date122));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTANTI_TD_2524386_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_LEFTANTI_TD_2524386_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._c_last_name9)) + (hash<string>()(k._c_first_name8)) + (hash<int32_t>()(k._d_date122));
    }
};
}
struct SW_JOIN_LEFTANTI_TD_2524386_payload_leftMajor {
    std::string _c_last_name9;
    std::string _c_first_name8;
    int32_t _d_date122;
};
struct SW_JOIN_LEFTANTI_TD_2524386_key_rightMajor {
    std::string _c_last_name3627;
    std::string _c_first_name3626;
    int32_t _d_date3592;
    bool operator==(const SW_JOIN_LEFTANTI_TD_2524386_key_rightMajor& other) const {
        return ((_c_last_name3627 == other._c_last_name3627) && (_c_first_name3626 == other._c_first_name3626) && (_d_date3592 == other._d_date3592));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTANTI_TD_2524386_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_LEFTANTI_TD_2524386_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._c_last_name3627)) + (hash<string>()(k._c_first_name3626)) + (hash<int32_t>()(k._d_date3592));
    }
};
}
struct SW_JOIN_LEFTANTI_TD_2524386_payload_rightMajor {
    std::string _c_last_name3627;
    std::string _c_first_name3626;
    int32_t _d_date3592;
};
void SW_JOIN_LEFTANTI_TD_2524386(Table &tbl_Aggregate_TD_35404_output, Table &tbl_Aggregate_TD_3711086_output, Table &tbl_JOIN_LEFTANTI_TD_2524386_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTANTI
    // Operation: ListBuffer((((c_last_name#9 <=> c_last_name#3627) AND (c_first_name#8 <=> c_first_name#3626)) AND (d_date#122 <=> d_date#3592)))
    // Left Table: ListBuffer(c_last_name#9, c_first_name#8, d_date#122)
    // Right Table: ListBuffer(c_last_name#3627, c_first_name#3626, d_date#3592)
    // Output Table: ListBuffer(c_last_name#9, c_first_name#8, d_date#122)
    int left_nrow = tbl_Aggregate_TD_35404_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_3711086_output.getNumRow();
        std::unordered_map<SW_JOIN_LEFTANTI_TD_2524386_key_rightMajor, SW_JOIN_LEFTANTI_TD_2524386_payload_rightMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_3711086_output.getNumRow();
        int nrow2 = tbl_Aggregate_TD_35404_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name3627_k_n = tbl_Aggregate_TD_3711086_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _c_last_name3627_k = std::string(_c_last_name3627_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name3626_k_n = tbl_Aggregate_TD_3711086_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_first_name3626_k = std::string(_c_first_name3626_k_n.data());
            int32_t _d_date3592_k = tbl_Aggregate_TD_3711086_output.getInt32(i, 2);
            SW_JOIN_LEFTANTI_TD_2524386_key_rightMajor keyA{_c_last_name3627_k, _c_first_name3626_k, _d_date3592_k};
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name3627_n = tbl_Aggregate_TD_3711086_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _c_last_name3627 = std::string(_c_last_name3627_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name3626_n = tbl_Aggregate_TD_3711086_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_first_name3626 = std::string(_c_first_name3626_n.data());
            int32_t _d_date3592 = tbl_Aggregate_TD_3711086_output.getInt32(i, 2);
            SW_JOIN_LEFTANTI_TD_2524386_payload_rightMajor payloadA{_c_last_name3627, _c_first_name3626, _d_date3592};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_k_n = tbl_Aggregate_TD_35404_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _c_last_name9_k = std::string(_c_last_name9_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_k_n = tbl_Aggregate_TD_35404_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_first_name8_k = std::string(_c_first_name8_k_n.data());
            int32_t _d_date122_k = tbl_Aggregate_TD_35404_output.getInt32(i, 2);
            auto it = ht1.find(SW_JOIN_LEFTANTI_TD_2524386_key_rightMajor{_c_last_name9_k, _c_first_name8_k, _d_date122_k});
            if (it == ht1.end()) {
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9 = tbl_Aggregate_TD_35404_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8 = tbl_Aggregate_TD_35404_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                int32_t _d_date122 = tbl_Aggregate_TD_35404_output.getInt32(i, 2);
                tbl_JOIN_LEFTANTI_TD_2524386_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name9);
                tbl_JOIN_LEFTANTI_TD_2524386_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8);
                tbl_JOIN_LEFTANTI_TD_2524386_output.setInt32(r, 2, _d_date122);
                r++;
            }
        }
        tbl_JOIN_LEFTANTI_TD_2524386_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTANTI_TD_2524386_output #Row: " << tbl_JOIN_LEFTANTI_TD_2524386_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_1795115_key {
    std::string _c_last_name9;
    std::string _c_first_name8;
    int32_t _d_date122;
    bool operator==(const SW_Aggregate_TD_1795115_key& other) const { return (_c_last_name9 == other._c_last_name9) && (_c_first_name8 == other._c_first_name8) && (_d_date122 == other._d_date122); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_1795115_key> {
    std::size_t operator() (const SW_Aggregate_TD_1795115_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._c_last_name9)) + (hash<string>()(k._c_first_name8)) + (hash<int32_t>()(k._d_date122));
    }
};
}
struct SW_Aggregate_TD_1795115_payload {
};
void SW_Aggregate_TD_1795115(Table &tbl_JOIN_LEFTANTI_TD_2524386_output, Table &tbl_Aggregate_TD_1795115_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_last_name#9, c_first_name#8, d_date#122)
    // Input: ListBuffer(c_last_name#9, c_first_name#8, d_date#122)
    // Output: ListBuffer(c_last_name#9, c_first_name#8, d_date#122)
    std::unordered_map<SW_Aggregate_TD_1795115_key, SW_Aggregate_TD_1795115_payload> ht1;
    int nrow1 = tbl_JOIN_LEFTANTI_TD_2524386_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9 = tbl_JOIN_LEFTANTI_TD_2524386_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8 = tbl_JOIN_LEFTANTI_TD_2524386_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _d_date122 = tbl_JOIN_LEFTANTI_TD_2524386_output.getInt32(i, 2);
        SW_Aggregate_TD_1795115_key k{std::string(_c_last_name9.data()), std::string(_c_first_name8.data()), _d_date122};
        SW_Aggregate_TD_1795115_payload p{};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9{};
        memcpy(_c_last_name9.data(), ((it.first)._c_last_name9).data(), ((it.first)._c_last_name9).length());
        tbl_Aggregate_TD_1795115_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name9);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8{};
        memcpy(_c_first_name8.data(), ((it.first)._c_first_name8).data(), ((it.first)._c_first_name8).length());
        tbl_Aggregate_TD_1795115_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8);
        tbl_Aggregate_TD_1795115_output.setInt32(r, 2, (it.first)._d_date122);
        ++r;
    }
    tbl_Aggregate_TD_1795115_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_1795115_output #Row: " << tbl_Aggregate_TD_1795115_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_058870(Table &tbl_Aggregate_TD_1795115_output, Table &tbl_Aggregate_TD_058870_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(count(1) AS count(1)#3637L)
    // Input: ListBuffer(c_last_name#9, c_first_name#8, d_date#122)
    // Output: ListBuffer(count(1)#3637L)
    int64_t count_0 = 0;
    int nrow1 = tbl_Aggregate_TD_1795115_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9 = tbl_Aggregate_TD_1795115_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8 = tbl_Aggregate_TD_1795115_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _d_date122 = tbl_Aggregate_TD_1795115_output.getInt32(i, 2);
        int64_t _count13637L_count_0 = 1;
        count_0 += _count13637L_count_0;
    }
    int r = 0;
    int64_t _count13637L = count_0;
    tbl_Aggregate_TD_058870_output.setInt64(r++, 0, _count13637L);
    tbl_Aggregate_TD_058870_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_058870_output #Row: " << tbl_Aggregate_TD_058870_output.getNumRow() << std::endl;
}

