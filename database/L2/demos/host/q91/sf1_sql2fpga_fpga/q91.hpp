#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_8688461(Table &tbl_SerializeFromObject_TD_972257_input, Table &tbl_Filter_TD_8688461_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cr_call_center_sk#1034) AND (isnotnull(cr_returned_date_sk#1023) AND isnotnull(cr_returning_customer_sk#1030))))
    // Input: ListBuffer(cr_returned_date_sk#1023, cr_returning_customer_sk#1030, cr_call_center_sk#1034, cr_net_loss#1049)
    // Output: ListBuffer(cr_returned_date_sk#1023, cr_returning_customer_sk#1030, cr_call_center_sk#1034, cr_net_loss#1049)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_972257_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cr_call_center_sk1034 = tbl_SerializeFromObject_TD_972257_input.getInt32(i, 2);
        int32_t _cr_returned_date_sk1023 = tbl_SerializeFromObject_TD_972257_input.getInt32(i, 0);
        int32_t _cr_returning_customer_sk1030 = tbl_SerializeFromObject_TD_972257_input.getInt32(i, 1);
        if ((_cr_call_center_sk1034!= 0) && ((_cr_returned_date_sk1023!= 0) && (_cr_returning_customer_sk1030!= 0))) {
            int32_t _cr_returned_date_sk1023_t = tbl_SerializeFromObject_TD_972257_input.getInt32(i, 0);
            tbl_Filter_TD_8688461_output.setInt32(r, 0, _cr_returned_date_sk1023_t);
            int32_t _cr_returning_customer_sk1030_t = tbl_SerializeFromObject_TD_972257_input.getInt32(i, 1);
            tbl_Filter_TD_8688461_output.setInt32(r, 1, _cr_returning_customer_sk1030_t);
            int32_t _cr_call_center_sk1034_t = tbl_SerializeFromObject_TD_972257_input.getInt32(i, 2);
            tbl_Filter_TD_8688461_output.setInt32(r, 2, _cr_call_center_sk1034_t);
            int64_t _cr_net_loss1049_t = tbl_SerializeFromObject_TD_972257_input.getInt64(i, 3);
            tbl_Filter_TD_8688461_output.setInt64(r, 3, _cr_net_loss1049_t);
            r++;
        }
    }
    tbl_Filter_TD_8688461_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8688461_output #Row: " << tbl_Filter_TD_8688461_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8268033(Table &tbl_SerializeFromObject_TD_9547899_input, Table &tbl_Filter_TD_8268033_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(cc_call_center_sk#903))
    // Input: ListBuffer(cc_call_center_sk#903, cc_call_center_id#904, cc_name#909, cc_manager#914)
    // Output: ListBuffer(cc_call_center_sk#903, cc_call_center_id#904, cc_name#909, cc_manager#914)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9547899_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cc_call_center_sk903 = tbl_SerializeFromObject_TD_9547899_input.getInt32(i, 0);
        if (_cc_call_center_sk903!= 0) {
            int32_t _cc_call_center_sk903_t = tbl_SerializeFromObject_TD_9547899_input.getInt32(i, 0);
            tbl_Filter_TD_8268033_output.setInt32(r, 0, _cc_call_center_sk903_t);
            std::array<char, TPCDS_READ_MAX + 1> _cc_call_center_id904_t = tbl_SerializeFromObject_TD_9547899_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_8268033_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cc_call_center_id904_t);
            std::array<char, TPCDS_READ_MAX + 1> _cc_name909_t = tbl_SerializeFromObject_TD_9547899_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_8268033_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_name909_t);
            std::array<char, TPCDS_READ_MAX + 1> _cc_manager914_t = tbl_SerializeFromObject_TD_9547899_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_8268033_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _cc_manager914_t);
            r++;
        }
    }
    tbl_Filter_TD_8268033_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8268033_output #Row: " << tbl_Filter_TD_8268033_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7498066(Table &tbl_SerializeFromObject_TD_8108689_input, Table &tbl_Filter_TD_7498066_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_year#126) AND isnotnull(d_moy#128)) AND ((d_year#126 = 1998) AND (d_moy#128 = 11))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126, d_moy#128)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8108689_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_8108689_input.getInt32(i, 1);
        int32_t _d_moy128 = tbl_SerializeFromObject_TD_8108689_input.getInt32(i, 2);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_8108689_input.getInt32(i, 0);
        if ((((_d_year126!= 0) && (_d_moy128!= 0)) && ((_d_year126 == 1998) && (_d_moy128 == 11))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_8108689_input.getInt32(i, 0);
            tbl_Filter_TD_7498066_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_7498066_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7498066_output #Row: " << tbl_Filter_TD_7498066_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_7560810_key_leftMajor {
    int32_t _cc_call_center_sk903;
    bool operator==(const SW_JOIN_INNER_TD_7560810_key_leftMajor& other) const {
        return ((_cc_call_center_sk903 == other._cc_call_center_sk903));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7560810_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7560810_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cc_call_center_sk903));
    }
};
}
struct SW_JOIN_INNER_TD_7560810_payload_leftMajor {
    int32_t _cc_call_center_sk903;
    std::string _cc_call_center_id904;
    std::string _cc_name909;
    std::string _cc_manager914;
};
struct SW_JOIN_INNER_TD_7560810_key_rightMajor {
    int32_t _cr_call_center_sk1034;
    bool operator==(const SW_JOIN_INNER_TD_7560810_key_rightMajor& other) const {
        return ((_cr_call_center_sk1034 == other._cr_call_center_sk1034));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7560810_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7560810_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cr_call_center_sk1034));
    }
};
}
struct SW_JOIN_INNER_TD_7560810_payload_rightMajor {
    int32_t _cr_returned_date_sk1023;
    int32_t _cr_returning_customer_sk1030;
    int32_t _cr_call_center_sk1034;
    int64_t _cr_net_loss1049;
};
void SW_JOIN_INNER_TD_7560810(Table &tbl_Filter_TD_8268033_output, Table &tbl_Filter_TD_8688461_output, Table &tbl_JOIN_INNER_TD_7560810_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cr_call_center_sk#1034 = cc_call_center_sk#903))
    // Left Table: ListBuffer(cc_call_center_sk#903, cc_call_center_id#904, cc_name#909, cc_manager#914)
    // Right Table: ListBuffer(cr_returned_date_sk#1023, cr_returning_customer_sk#1030, cr_call_center_sk#1034, cr_net_loss#1049)
    // Output Table: ListBuffer(cc_call_center_id#904, cc_name#909, cc_manager#914, cr_returned_date_sk#1023, cr_returning_customer_sk#1030, cr_net_loss#1049)
    int left_nrow = tbl_Filter_TD_8268033_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8688461_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7560810_key_leftMajor, SW_JOIN_INNER_TD_7560810_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_8268033_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cc_call_center_sk903_k = tbl_Filter_TD_8268033_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7560810_key_leftMajor keyA{_cc_call_center_sk903_k};
            int32_t _cc_call_center_sk903 = tbl_Filter_TD_8268033_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _cc_call_center_id904_n = tbl_Filter_TD_8268033_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cc_call_center_id904 = std::string(_cc_call_center_id904_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_Filter_TD_8268033_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _cc_name909 = std::string(_cc_name909_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cc_manager914_n = tbl_Filter_TD_8268033_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _cc_manager914 = std::string(_cc_manager914_n.data());
            SW_JOIN_INNER_TD_7560810_payload_leftMajor payloadA{_cc_call_center_sk903, _cc_call_center_id904, _cc_name909, _cc_manager914};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8688461_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cr_call_center_sk1034_k = tbl_Filter_TD_8688461_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7560810_key_leftMajor{_cr_call_center_sk1034_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cc_call_center_sk903 = (it->second)._cc_call_center_sk903;
                std::string _cc_call_center_id904 = (it->second)._cc_call_center_id904;
                std::array<char, TPCDS_READ_MAX + 1> _cc_call_center_id904_n{};
                memcpy(_cc_call_center_id904_n.data(), (_cc_call_center_id904).data(), (_cc_call_center_id904).length());
                std::string _cc_name909 = (it->second)._cc_name909;
                std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n{};
                memcpy(_cc_name909_n.data(), (_cc_name909).data(), (_cc_name909).length());
                std::string _cc_manager914 = (it->second)._cc_manager914;
                std::array<char, TPCDS_READ_MAX + 1> _cc_manager914_n{};
                memcpy(_cc_manager914_n.data(), (_cc_manager914).data(), (_cc_manager914).length());
                int32_t _cr_returned_date_sk1023 = tbl_Filter_TD_8688461_output.getInt32(i, 0);
                int32_t _cr_returning_customer_sk1030 = tbl_Filter_TD_8688461_output.getInt32(i, 1);
                int32_t _cr_call_center_sk1034 = tbl_Filter_TD_8688461_output.getInt32(i, 2);
                int64_t _cr_net_loss1049 = tbl_Filter_TD_8688461_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_7560810_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _cc_call_center_id904_n);
                tbl_JOIN_INNER_TD_7560810_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cc_name909_n);
                tbl_JOIN_INNER_TD_7560810_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_manager914_n);
                tbl_JOIN_INNER_TD_7560810_output.setInt32(r, 3, _cr_returned_date_sk1023);
                tbl_JOIN_INNER_TD_7560810_output.setInt32(r, 4, _cr_returning_customer_sk1030);
                tbl_JOIN_INNER_TD_7560810_output.setInt64(r, 5, _cr_net_loss1049);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7560810_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7560810_key_rightMajor, SW_JOIN_INNER_TD_7560810_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8688461_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cr_call_center_sk1034_k = tbl_Filter_TD_8688461_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_7560810_key_rightMajor keyA{_cr_call_center_sk1034_k};
            int32_t _cr_returned_date_sk1023 = tbl_Filter_TD_8688461_output.getInt32(i, 0);
            int32_t _cr_returning_customer_sk1030 = tbl_Filter_TD_8688461_output.getInt32(i, 1);
            int32_t _cr_call_center_sk1034 = tbl_Filter_TD_8688461_output.getInt32(i, 2);
            int64_t _cr_net_loss1049 = tbl_Filter_TD_8688461_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_7560810_payload_rightMajor payloadA{_cr_returned_date_sk1023, _cr_returning_customer_sk1030, _cr_call_center_sk1034, _cr_net_loss1049};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8268033_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cc_call_center_sk903_k = tbl_Filter_TD_8268033_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7560810_key_rightMajor{_cc_call_center_sk903_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cr_returned_date_sk1023 = (it->second)._cr_returned_date_sk1023;
                int32_t _cr_returning_customer_sk1030 = (it->second)._cr_returning_customer_sk1030;
                int32_t _cr_call_center_sk1034 = (it->second)._cr_call_center_sk1034;
                int64_t _cr_net_loss1049 = (it->second)._cr_net_loss1049;
                int32_t _cc_call_center_sk903 = tbl_Filter_TD_8268033_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _cc_call_center_id904_n = tbl_Filter_TD_8268033_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _cc_call_center_id904 = std::string(_cc_call_center_id904_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_Filter_TD_8268033_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _cc_name909 = std::string(_cc_name909_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cc_manager914_n = tbl_Filter_TD_8268033_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _cc_manager914 = std::string(_cc_manager914_n.data());
                tbl_JOIN_INNER_TD_7560810_output.setInt32(r, 3, _cr_returned_date_sk1023);
                tbl_JOIN_INNER_TD_7560810_output.setInt32(r, 4, _cr_returning_customer_sk1030);
                tbl_JOIN_INNER_TD_7560810_output.setInt64(r, 5, _cr_net_loss1049);
                tbl_JOIN_INNER_TD_7560810_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _cc_call_center_id904_n);
                tbl_JOIN_INNER_TD_7560810_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cc_name909_n);
                tbl_JOIN_INNER_TD_7560810_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_manager914_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7560810_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7560810_output #Row: " << tbl_JOIN_INNER_TD_7560810_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6657760(Table &tbl_SerializeFromObject_TD_7657806_input, Table &tbl_Filter_TD_6657760_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(c_customer_sk#0) AND isnotnull(c_current_addr_sk#4)) AND (isnotnull(c_current_cdemo_sk#2) AND isnotnull(c_current_hdemo_sk#3))))
    // Input: ListBuffer(c_customer_sk#0, c_current_cdemo_sk#2, c_current_hdemo_sk#3, c_current_addr_sk#4)
    // Output: ListBuffer(c_customer_sk#0, c_current_cdemo_sk#2, c_current_hdemo_sk#3, c_current_addr_sk#4)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7657806_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk0 = tbl_SerializeFromObject_TD_7657806_input.getInt32(i, 0);
        int32_t _c_current_addr_sk4 = tbl_SerializeFromObject_TD_7657806_input.getInt32(i, 3);
        int32_t _c_current_cdemo_sk2 = tbl_SerializeFromObject_TD_7657806_input.getInt32(i, 1);
        int32_t _c_current_hdemo_sk3 = tbl_SerializeFromObject_TD_7657806_input.getInt32(i, 2);
        if (((_c_customer_sk0!= 0) && (_c_current_addr_sk4!= 0)) && ((_c_current_cdemo_sk2!= 0) && (_c_current_hdemo_sk3!= 0))) {
            int32_t _c_customer_sk0_t = tbl_SerializeFromObject_TD_7657806_input.getInt32(i, 0);
            tbl_Filter_TD_6657760_output.setInt32(r, 0, _c_customer_sk0_t);
            int32_t _c_current_cdemo_sk2_t = tbl_SerializeFromObject_TD_7657806_input.getInt32(i, 1);
            tbl_Filter_TD_6657760_output.setInt32(r, 1, _c_current_cdemo_sk2_t);
            int32_t _c_current_hdemo_sk3_t = tbl_SerializeFromObject_TD_7657806_input.getInt32(i, 2);
            tbl_Filter_TD_6657760_output.setInt32(r, 2, _c_current_hdemo_sk3_t);
            int32_t _c_current_addr_sk4_t = tbl_SerializeFromObject_TD_7657806_input.getInt32(i, 3);
            tbl_Filter_TD_6657760_output.setInt32(r, 3, _c_current_addr_sk4_t);
            r++;
        }
    }
    tbl_Filter_TD_6657760_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6657760_output #Row: " << tbl_Filter_TD_6657760_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6187097_key_leftMajor {
    int32_t _cr_returned_date_sk1023;
    bool operator==(const SW_JOIN_INNER_TD_6187097_key_leftMajor& other) const {
        return ((_cr_returned_date_sk1023 == other._cr_returned_date_sk1023));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6187097_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6187097_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cr_returned_date_sk1023));
    }
};
}
struct SW_JOIN_INNER_TD_6187097_payload_leftMajor {
    std::string _cc_call_center_id904;
    std::string _cc_name909;
    std::string _cc_manager914;
    int32_t _cr_returned_date_sk1023;
    int32_t _cr_returning_customer_sk1030;
    int64_t _cr_net_loss1049;
};
struct SW_JOIN_INNER_TD_6187097_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_6187097_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6187097_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6187097_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_6187097_payload_rightMajor {
    int32_t _d_date_sk120;
};
void SW_JOIN_INNER_TD_6187097(Table &tbl_JOIN_INNER_TD_7560810_output, Table &tbl_Filter_TD_7498066_output, Table &tbl_JOIN_INNER_TD_6187097_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cr_returned_date_sk#1023 = d_date_sk#120))
    // Left Table: ListBuffer(cc_call_center_id#904, cc_name#909, cc_manager#914, cr_returned_date_sk#1023, cr_returning_customer_sk#1030, cr_net_loss#1049)
    // Right Table: ListBuffer(d_date_sk#120)
    // Output Table: ListBuffer(cc_call_center_id#904, cc_name#909, cc_manager#914, cr_returning_customer_sk#1030, cr_net_loss#1049)
    int left_nrow = tbl_JOIN_INNER_TD_7560810_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7498066_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6187097_key_leftMajor, SW_JOIN_INNER_TD_6187097_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7560810_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cr_returned_date_sk1023_k = tbl_JOIN_INNER_TD_7560810_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_6187097_key_leftMajor keyA{_cr_returned_date_sk1023_k};
            std::array<char, TPCDS_READ_MAX + 1> _cc_call_center_id904_n = tbl_JOIN_INNER_TD_7560810_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _cc_call_center_id904 = std::string(_cc_call_center_id904_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_JOIN_INNER_TD_7560810_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cc_name909 = std::string(_cc_name909_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cc_manager914_n = tbl_JOIN_INNER_TD_7560810_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _cc_manager914 = std::string(_cc_manager914_n.data());
            int32_t _cr_returned_date_sk1023 = tbl_JOIN_INNER_TD_7560810_output.getInt32(i, 3);
            int32_t _cr_returning_customer_sk1030 = tbl_JOIN_INNER_TD_7560810_output.getInt32(i, 4);
            int64_t _cr_net_loss1049 = tbl_JOIN_INNER_TD_7560810_output.getInt64(i, 5);
            SW_JOIN_INNER_TD_6187097_payload_leftMajor payloadA{_cc_call_center_id904, _cc_name909, _cc_manager914, _cr_returned_date_sk1023, _cr_returning_customer_sk1030, _cr_net_loss1049};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7498066_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_7498066_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6187097_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _cc_call_center_id904 = (it->second)._cc_call_center_id904;
                std::array<char, TPCDS_READ_MAX + 1> _cc_call_center_id904_n{};
                memcpy(_cc_call_center_id904_n.data(), (_cc_call_center_id904).data(), (_cc_call_center_id904).length());
                std::string _cc_name909 = (it->second)._cc_name909;
                std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n{};
                memcpy(_cc_name909_n.data(), (_cc_name909).data(), (_cc_name909).length());
                std::string _cc_manager914 = (it->second)._cc_manager914;
                std::array<char, TPCDS_READ_MAX + 1> _cc_manager914_n{};
                memcpy(_cc_manager914_n.data(), (_cc_manager914).data(), (_cc_manager914).length());
                int32_t _cr_returned_date_sk1023 = (it->second)._cr_returned_date_sk1023;
                int32_t _cr_returning_customer_sk1030 = (it->second)._cr_returning_customer_sk1030;
                int64_t _cr_net_loss1049 = (it->second)._cr_net_loss1049;
                int32_t _d_date_sk120 = tbl_Filter_TD_7498066_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_6187097_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _cc_call_center_id904_n);
                tbl_JOIN_INNER_TD_6187097_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cc_name909_n);
                tbl_JOIN_INNER_TD_6187097_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_manager914_n);
                tbl_JOIN_INNER_TD_6187097_output.setInt32(r, 3, _cr_returning_customer_sk1030);
                tbl_JOIN_INNER_TD_6187097_output.setInt64(r, 4, _cr_net_loss1049);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6187097_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6187097_key_rightMajor, SW_JOIN_INNER_TD_6187097_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7498066_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_7498066_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6187097_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_7498066_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6187097_payload_rightMajor payloadA{_d_date_sk120};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7560810_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cr_returned_date_sk1023_k = tbl_JOIN_INNER_TD_7560810_output.getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6187097_key_rightMajor{_cr_returned_date_sk1023_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                std::array<char, TPCDS_READ_MAX + 1> _cc_call_center_id904_n = tbl_JOIN_INNER_TD_7560810_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _cc_call_center_id904 = std::string(_cc_call_center_id904_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_JOIN_INNER_TD_7560810_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _cc_name909 = std::string(_cc_name909_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cc_manager914_n = tbl_JOIN_INNER_TD_7560810_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _cc_manager914 = std::string(_cc_manager914_n.data());
                int32_t _cr_returned_date_sk1023 = tbl_JOIN_INNER_TD_7560810_output.getInt32(i, 3);
                int32_t _cr_returning_customer_sk1030 = tbl_JOIN_INNER_TD_7560810_output.getInt32(i, 4);
                int64_t _cr_net_loss1049 = tbl_JOIN_INNER_TD_7560810_output.getInt64(i, 5);
                tbl_JOIN_INNER_TD_6187097_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _cc_call_center_id904_n);
                tbl_JOIN_INNER_TD_6187097_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cc_name909_n);
                tbl_JOIN_INNER_TD_6187097_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_manager914_n);
                tbl_JOIN_INNER_TD_6187097_output.setInt32(r, 3, _cr_returning_customer_sk1030);
                tbl_JOIN_INNER_TD_6187097_output.setInt64(r, 4, _cr_net_loss1049);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6187097_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6187097_output #Row: " << tbl_JOIN_INNER_TD_6187097_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5729786(Table &tbl_SerializeFromObject_TD_6796319_input, Table &tbl_Filter_TD_5729786_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ca_gmt_offset#65) AND (ca_gmt_offset#65 = -7.00)) AND isnotnull(ca_address_sk#54)))
    // Input: ListBuffer(ca_address_sk#54, ca_gmt_offset#65)
    // Output: ListBuffer(ca_address_sk#54)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6796319_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ca_gmt_offset65 = tbl_SerializeFromObject_TD_6796319_input.getInt64(i, 1);
        int32_t _ca_address_sk54 = tbl_SerializeFromObject_TD_6796319_input.getInt32(i, 0);
        if (((_ca_gmt_offset65!= 0) && (_ca_gmt_offset65 == -7.00)) && (_ca_address_sk54!= 0)) {
            int32_t _ca_address_sk54_t = tbl_SerializeFromObject_TD_6796319_input.getInt32(i, 0);
            tbl_Filter_TD_5729786_output.setInt32(r, 0, _ca_address_sk54_t);
            r++;
        }
    }
    tbl_Filter_TD_5729786_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5729786_output #Row: " << tbl_Filter_TD_5729786_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5104859_key_leftMajor {
    int32_t _cr_returning_customer_sk1030;
    bool operator==(const SW_JOIN_INNER_TD_5104859_key_leftMajor& other) const {
        return ((_cr_returning_customer_sk1030 == other._cr_returning_customer_sk1030));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5104859_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5104859_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cr_returning_customer_sk1030));
    }
};
}
struct SW_JOIN_INNER_TD_5104859_payload_leftMajor {
    std::string _cc_call_center_id904;
    std::string _cc_name909;
    std::string _cc_manager914;
    int32_t _cr_returning_customer_sk1030;
    int64_t _cr_net_loss1049;
};
struct SW_JOIN_INNER_TD_5104859_key_rightMajor {
    int32_t _c_customer_sk0;
    bool operator==(const SW_JOIN_INNER_TD_5104859_key_rightMajor& other) const {
        return ((_c_customer_sk0 == other._c_customer_sk0));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5104859_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5104859_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk0));
    }
};
}
struct SW_JOIN_INNER_TD_5104859_payload_rightMajor {
    int32_t _c_customer_sk0;
    int32_t _c_current_cdemo_sk2;
    int32_t _c_current_hdemo_sk3;
    int32_t _c_current_addr_sk4;
};
void SW_JOIN_INNER_TD_5104859(Table &tbl_JOIN_INNER_TD_6187097_output, Table &tbl_Filter_TD_6657760_output, Table &tbl_JOIN_INNER_TD_5104859_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cr_returning_customer_sk#1030 = c_customer_sk#0))
    // Left Table: ListBuffer(cc_call_center_id#904, cc_name#909, cc_manager#914, cr_returning_customer_sk#1030, cr_net_loss#1049)
    // Right Table: ListBuffer(c_customer_sk#0, c_current_cdemo_sk#2, c_current_hdemo_sk#3, c_current_addr_sk#4)
    // Output Table: ListBuffer(cc_call_center_id#904, cc_name#909, cc_manager#914, cr_net_loss#1049, c_current_cdemo_sk#2, c_current_hdemo_sk#3, c_current_addr_sk#4)
    int left_nrow = tbl_JOIN_INNER_TD_6187097_output.getNumRow();
    int right_nrow = tbl_Filter_TD_6657760_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5104859_key_leftMajor, SW_JOIN_INNER_TD_5104859_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_6187097_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cr_returning_customer_sk1030_k = tbl_JOIN_INNER_TD_6187097_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_5104859_key_leftMajor keyA{_cr_returning_customer_sk1030_k};
            std::array<char, TPCDS_READ_MAX + 1> _cc_call_center_id904_n = tbl_JOIN_INNER_TD_6187097_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _cc_call_center_id904 = std::string(_cc_call_center_id904_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_JOIN_INNER_TD_6187097_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cc_name909 = std::string(_cc_name909_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cc_manager914_n = tbl_JOIN_INNER_TD_6187097_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _cc_manager914 = std::string(_cc_manager914_n.data());
            int32_t _cr_returning_customer_sk1030 = tbl_JOIN_INNER_TD_6187097_output.getInt32(i, 3);
            int64_t _cr_net_loss1049 = tbl_JOIN_INNER_TD_6187097_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_5104859_payload_leftMajor payloadA{_cc_call_center_id904, _cc_name909, _cc_manager914, _cr_returning_customer_sk1030, _cr_net_loss1049};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6657760_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_6657760_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5104859_key_leftMajor{_c_customer_sk0_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _cc_call_center_id904 = (it->second)._cc_call_center_id904;
                std::array<char, TPCDS_READ_MAX + 1> _cc_call_center_id904_n{};
                memcpy(_cc_call_center_id904_n.data(), (_cc_call_center_id904).data(), (_cc_call_center_id904).length());
                std::string _cc_name909 = (it->second)._cc_name909;
                std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n{};
                memcpy(_cc_name909_n.data(), (_cc_name909).data(), (_cc_name909).length());
                std::string _cc_manager914 = (it->second)._cc_manager914;
                std::array<char, TPCDS_READ_MAX + 1> _cc_manager914_n{};
                memcpy(_cc_manager914_n.data(), (_cc_manager914).data(), (_cc_manager914).length());
                int32_t _cr_returning_customer_sk1030 = (it->second)._cr_returning_customer_sk1030;
                int64_t _cr_net_loss1049 = (it->second)._cr_net_loss1049;
                int32_t _c_customer_sk0 = tbl_Filter_TD_6657760_output.getInt32(i, 0);
                int32_t _c_current_cdemo_sk2 = tbl_Filter_TD_6657760_output.getInt32(i, 1);
                int32_t _c_current_hdemo_sk3 = tbl_Filter_TD_6657760_output.getInt32(i, 2);
                int32_t _c_current_addr_sk4 = tbl_Filter_TD_6657760_output.getInt32(i, 3);
                tbl_JOIN_INNER_TD_5104859_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _cc_call_center_id904_n);
                tbl_JOIN_INNER_TD_5104859_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cc_name909_n);
                tbl_JOIN_INNER_TD_5104859_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_manager914_n);
                tbl_JOIN_INNER_TD_5104859_output.setInt64(r, 3, _cr_net_loss1049);
                tbl_JOIN_INNER_TD_5104859_output.setInt32(r, 4, _c_current_cdemo_sk2);
                tbl_JOIN_INNER_TD_5104859_output.setInt32(r, 5, _c_current_hdemo_sk3);
                tbl_JOIN_INNER_TD_5104859_output.setInt32(r, 6, _c_current_addr_sk4);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5104859_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5104859_key_rightMajor, SW_JOIN_INNER_TD_5104859_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_6657760_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_6657760_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5104859_key_rightMajor keyA{_c_customer_sk0_k};
            int32_t _c_customer_sk0 = tbl_Filter_TD_6657760_output.getInt32(i, 0);
            int32_t _c_current_cdemo_sk2 = tbl_Filter_TD_6657760_output.getInt32(i, 1);
            int32_t _c_current_hdemo_sk3 = tbl_Filter_TD_6657760_output.getInt32(i, 2);
            int32_t _c_current_addr_sk4 = tbl_Filter_TD_6657760_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_5104859_payload_rightMajor payloadA{_c_customer_sk0, _c_current_cdemo_sk2, _c_current_hdemo_sk3, _c_current_addr_sk4};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_6187097_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cr_returning_customer_sk1030_k = tbl_JOIN_INNER_TD_6187097_output.getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5104859_key_rightMajor{_cr_returning_customer_sk1030_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk0 = (it->second)._c_customer_sk0;
                int32_t _c_current_cdemo_sk2 = (it->second)._c_current_cdemo_sk2;
                int32_t _c_current_hdemo_sk3 = (it->second)._c_current_hdemo_sk3;
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                std::array<char, TPCDS_READ_MAX + 1> _cc_call_center_id904_n = tbl_JOIN_INNER_TD_6187097_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _cc_call_center_id904 = std::string(_cc_call_center_id904_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_JOIN_INNER_TD_6187097_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _cc_name909 = std::string(_cc_name909_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cc_manager914_n = tbl_JOIN_INNER_TD_6187097_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _cc_manager914 = std::string(_cc_manager914_n.data());
                int32_t _cr_returning_customer_sk1030 = tbl_JOIN_INNER_TD_6187097_output.getInt32(i, 3);
                int64_t _cr_net_loss1049 = tbl_JOIN_INNER_TD_6187097_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_5104859_output.setInt32(r, 4, _c_current_cdemo_sk2);
                tbl_JOIN_INNER_TD_5104859_output.setInt32(r, 5, _c_current_hdemo_sk3);
                tbl_JOIN_INNER_TD_5104859_output.setInt32(r, 6, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_5104859_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _cc_call_center_id904_n);
                tbl_JOIN_INNER_TD_5104859_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cc_name909_n);
                tbl_JOIN_INNER_TD_5104859_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_manager914_n);
                tbl_JOIN_INNER_TD_5104859_output.setInt64(r, 3, _cr_net_loss1049);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5104859_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5104859_output #Row: " << tbl_JOIN_INNER_TD_5104859_output.getNumRow() << std::endl;
}

void SW_Filter_TD_4110362(Table &tbl_SerializeFromObject_TD_5745377_input, Table &tbl_Filter_TD_4110362_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((((cd_marital_status#95 = M) AND (cd_education_status#96 = Unknown)) OR ((cd_marital_status#95 = W) AND (cd_education_status#96 = Advanced Degree))) AND isnotnull(cd_demo_sk#93)))
    // Input: ListBuffer(cd_demo_sk#93, cd_marital_status#95, cd_education_status#96)
    // Output: ListBuffer(cd_demo_sk#93, cd_marital_status#95, cd_education_status#96)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5745377_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95 = tbl_SerializeFromObject_TD_5745377_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96 = tbl_SerializeFromObject_TD_5745377_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        int32_t _cd_demo_sk93 = tbl_SerializeFromObject_TD_5745377_input.getInt32(i, 0);
        if ((((std::string(_cd_marital_status95.data()) == "M") && (std::string(_cd_education_status96.data()) == "Unknown")) || ((std::string(_cd_marital_status95.data()) == "W") && (std::string(_cd_education_status96.data()) == "Advanced Degree"))) && (_cd_demo_sk93!= 0)) {
            int32_t _cd_demo_sk93_t = tbl_SerializeFromObject_TD_5745377_input.getInt32(i, 0);
            tbl_Filter_TD_4110362_output.setInt32(r, 0, _cd_demo_sk93_t);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_t = tbl_SerializeFromObject_TD_5745377_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_4110362_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cd_marital_status95_t);
            std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_t = tbl_SerializeFromObject_TD_5745377_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_4110362_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cd_education_status96_t);
            r++;
        }
    }
    tbl_Filter_TD_4110362_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4110362_output #Row: " << tbl_Filter_TD_4110362_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4723814_key_leftMajor {
    int32_t _c_current_addr_sk4;
    bool operator==(const SW_JOIN_INNER_TD_4723814_key_leftMajor& other) const {
        return ((_c_current_addr_sk4 == other._c_current_addr_sk4));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4723814_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4723814_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_current_addr_sk4));
    }
};
}
struct SW_JOIN_INNER_TD_4723814_payload_leftMajor {
    std::string _cc_call_center_id904;
    std::string _cc_name909;
    std::string _cc_manager914;
    int64_t _cr_net_loss1049;
    int32_t _c_current_cdemo_sk2;
    int32_t _c_current_hdemo_sk3;
    int32_t _c_current_addr_sk4;
};
struct SW_JOIN_INNER_TD_4723814_key_rightMajor {
    int32_t _ca_address_sk54;
    bool operator==(const SW_JOIN_INNER_TD_4723814_key_rightMajor& other) const {
        return ((_ca_address_sk54 == other._ca_address_sk54));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4723814_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4723814_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk54));
    }
};
}
struct SW_JOIN_INNER_TD_4723814_payload_rightMajor {
    int32_t _ca_address_sk54;
};
void SW_JOIN_INNER_TD_4723814(Table &tbl_JOIN_INNER_TD_5104859_output, Table &tbl_Filter_TD_5729786_output, Table &tbl_JOIN_INNER_TD_4723814_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ca_address_sk#54 = c_current_addr_sk#4))
    // Left Table: ListBuffer(cc_call_center_id#904, cc_name#909, cc_manager#914, cr_net_loss#1049, c_current_cdemo_sk#2, c_current_hdemo_sk#3, c_current_addr_sk#4)
    // Right Table: ListBuffer(ca_address_sk#54)
    // Output Table: ListBuffer(cc_call_center_id#904, cc_name#909, cc_manager#914, cr_net_loss#1049, c_current_cdemo_sk#2, c_current_hdemo_sk#3)
    int left_nrow = tbl_JOIN_INNER_TD_5104859_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5729786_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4723814_key_leftMajor, SW_JOIN_INNER_TD_4723814_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_5104859_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_current_addr_sk4_k = tbl_JOIN_INNER_TD_5104859_output.getInt32(i, 6);
            SW_JOIN_INNER_TD_4723814_key_leftMajor keyA{_c_current_addr_sk4_k};
            std::array<char, TPCDS_READ_MAX + 1> _cc_call_center_id904_n = tbl_JOIN_INNER_TD_5104859_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _cc_call_center_id904 = std::string(_cc_call_center_id904_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_JOIN_INNER_TD_5104859_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cc_name909 = std::string(_cc_name909_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cc_manager914_n = tbl_JOIN_INNER_TD_5104859_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _cc_manager914 = std::string(_cc_manager914_n.data());
            int64_t _cr_net_loss1049 = tbl_JOIN_INNER_TD_5104859_output.getInt64(i, 3);
            int32_t _c_current_cdemo_sk2 = tbl_JOIN_INNER_TD_5104859_output.getInt32(i, 4);
            int32_t _c_current_hdemo_sk3 = tbl_JOIN_INNER_TD_5104859_output.getInt32(i, 5);
            int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_5104859_output.getInt32(i, 6);
            SW_JOIN_INNER_TD_4723814_payload_leftMajor payloadA{_cc_call_center_id904, _cc_name909, _cc_manager914, _cr_net_loss1049, _c_current_cdemo_sk2, _c_current_hdemo_sk3, _c_current_addr_sk4};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5729786_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_5729786_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4723814_key_leftMajor{_ca_address_sk54_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _cc_call_center_id904 = (it->second)._cc_call_center_id904;
                std::array<char, TPCDS_READ_MAX + 1> _cc_call_center_id904_n{};
                memcpy(_cc_call_center_id904_n.data(), (_cc_call_center_id904).data(), (_cc_call_center_id904).length());
                std::string _cc_name909 = (it->second)._cc_name909;
                std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n{};
                memcpy(_cc_name909_n.data(), (_cc_name909).data(), (_cc_name909).length());
                std::string _cc_manager914 = (it->second)._cc_manager914;
                std::array<char, TPCDS_READ_MAX + 1> _cc_manager914_n{};
                memcpy(_cc_manager914_n.data(), (_cc_manager914).data(), (_cc_manager914).length());
                int64_t _cr_net_loss1049 = (it->second)._cr_net_loss1049;
                int32_t _c_current_cdemo_sk2 = (it->second)._c_current_cdemo_sk2;
                int32_t _c_current_hdemo_sk3 = (it->second)._c_current_hdemo_sk3;
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                int32_t _ca_address_sk54 = tbl_Filter_TD_5729786_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_4723814_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _cc_call_center_id904_n);
                tbl_JOIN_INNER_TD_4723814_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cc_name909_n);
                tbl_JOIN_INNER_TD_4723814_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_manager914_n);
                tbl_JOIN_INNER_TD_4723814_output.setInt64(r, 3, _cr_net_loss1049);
                tbl_JOIN_INNER_TD_4723814_output.setInt32(r, 4, _c_current_cdemo_sk2);
                tbl_JOIN_INNER_TD_4723814_output.setInt32(r, 5, _c_current_hdemo_sk3);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4723814_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4723814_key_rightMajor, SW_JOIN_INNER_TD_4723814_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5729786_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_5729786_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4723814_key_rightMajor keyA{_ca_address_sk54_k};
            int32_t _ca_address_sk54 = tbl_Filter_TD_5729786_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4723814_payload_rightMajor payloadA{_ca_address_sk54};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_5104859_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_current_addr_sk4_k = tbl_JOIN_INNER_TD_5104859_output.getInt32(i, 6);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4723814_key_rightMajor{_c_current_addr_sk4_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk54 = (it->second)._ca_address_sk54;
                std::array<char, TPCDS_READ_MAX + 1> _cc_call_center_id904_n = tbl_JOIN_INNER_TD_5104859_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _cc_call_center_id904 = std::string(_cc_call_center_id904_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_JOIN_INNER_TD_5104859_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _cc_name909 = std::string(_cc_name909_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cc_manager914_n = tbl_JOIN_INNER_TD_5104859_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _cc_manager914 = std::string(_cc_manager914_n.data());
                int64_t _cr_net_loss1049 = tbl_JOIN_INNER_TD_5104859_output.getInt64(i, 3);
                int32_t _c_current_cdemo_sk2 = tbl_JOIN_INNER_TD_5104859_output.getInt32(i, 4);
                int32_t _c_current_hdemo_sk3 = tbl_JOIN_INNER_TD_5104859_output.getInt32(i, 5);
                int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_5104859_output.getInt32(i, 6);
                tbl_JOIN_INNER_TD_4723814_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _cc_call_center_id904_n);
                tbl_JOIN_INNER_TD_4723814_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cc_name909_n);
                tbl_JOIN_INNER_TD_4723814_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_manager914_n);
                tbl_JOIN_INNER_TD_4723814_output.setInt64(r, 3, _cr_net_loss1049);
                tbl_JOIN_INNER_TD_4723814_output.setInt32(r, 4, _c_current_cdemo_sk2);
                tbl_JOIN_INNER_TD_4723814_output.setInt32(r, 5, _c_current_hdemo_sk3);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4723814_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4723814_output #Row: " << tbl_JOIN_INNER_TD_4723814_output.getNumRow() << std::endl;
}

void SW_Filter_TD_3979165(Table &tbl_SerializeFromObject_TD_4191882_input, Table &tbl_Filter_TD_3979165_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(hd_buy_potential#206) AND StartsWith(hd_buy_potential#206, Unknown)) AND isnotnull(hd_demo_sk#204)))
    // Input: ListBuffer(hd_demo_sk#204, hd_buy_potential#206)
    // Output: ListBuffer(hd_demo_sk#204)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_4191882_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _hd_buy_potential206 = tbl_SerializeFromObject_TD_4191882_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _hd_demo_sk204 = tbl_SerializeFromObject_TD_4191882_input.getInt32(i, 0);
        if ((_hd_buy_potential206.data() != "NULL" && (std::string(_hd_buy_potential206.data()).find("Unknown")==0)) && (_hd_demo_sk204!= 0)) {
            int32_t _hd_demo_sk204_t = tbl_SerializeFromObject_TD_4191882_input.getInt32(i, 0);
            tbl_Filter_TD_3979165_output.setInt32(r, 0, _hd_demo_sk204_t);
            r++;
        }
    }
    tbl_Filter_TD_3979165_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_3979165_output #Row: " << tbl_Filter_TD_3979165_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_3525367_key_leftMajor {
    int32_t _c_current_cdemo_sk2;
    bool operator==(const SW_JOIN_INNER_TD_3525367_key_leftMajor& other) const {
        return ((_c_current_cdemo_sk2 == other._c_current_cdemo_sk2));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3525367_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3525367_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_current_cdemo_sk2));
    }
};
}
struct SW_JOIN_INNER_TD_3525367_payload_leftMajor {
    std::string _cc_call_center_id904;
    std::string _cc_name909;
    std::string _cc_manager914;
    int64_t _cr_net_loss1049;
    int32_t _c_current_cdemo_sk2;
    int32_t _c_current_hdemo_sk3;
};
struct SW_JOIN_INNER_TD_3525367_key_rightMajor {
    int32_t _cd_demo_sk93;
    bool operator==(const SW_JOIN_INNER_TD_3525367_key_rightMajor& other) const {
        return ((_cd_demo_sk93 == other._cd_demo_sk93));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3525367_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3525367_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cd_demo_sk93));
    }
};
}
struct SW_JOIN_INNER_TD_3525367_payload_rightMajor {
    int32_t _cd_demo_sk93;
    std::string _cd_marital_status95;
    std::string _cd_education_status96;
};
void SW_JOIN_INNER_TD_3525367(Table &tbl_JOIN_INNER_TD_4723814_output, Table &tbl_Filter_TD_4110362_output, Table &tbl_JOIN_INNER_TD_3525367_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cd_demo_sk#93 = c_current_cdemo_sk#2))
    // Left Table: ListBuffer(cc_call_center_id#904, cc_name#909, cc_manager#914, cr_net_loss#1049, c_current_cdemo_sk#2, c_current_hdemo_sk#3)
    // Right Table: ListBuffer(cd_demo_sk#93, cd_marital_status#95, cd_education_status#96)
    // Output Table: ListBuffer(cc_call_center_id#904, cc_name#909, cc_manager#914, cr_net_loss#1049, c_current_hdemo_sk#3, cd_marital_status#95, cd_education_status#96)
    int left_nrow = tbl_JOIN_INNER_TD_4723814_output.getNumRow();
    int right_nrow = tbl_Filter_TD_4110362_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3525367_key_leftMajor, SW_JOIN_INNER_TD_3525367_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_4723814_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_current_cdemo_sk2_k = tbl_JOIN_INNER_TD_4723814_output.getInt32(i, 4);
            SW_JOIN_INNER_TD_3525367_key_leftMajor keyA{_c_current_cdemo_sk2_k};
            std::array<char, TPCDS_READ_MAX + 1> _cc_call_center_id904_n = tbl_JOIN_INNER_TD_4723814_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _cc_call_center_id904 = std::string(_cc_call_center_id904_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_JOIN_INNER_TD_4723814_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cc_name909 = std::string(_cc_name909_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cc_manager914_n = tbl_JOIN_INNER_TD_4723814_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _cc_manager914 = std::string(_cc_manager914_n.data());
            int64_t _cr_net_loss1049 = tbl_JOIN_INNER_TD_4723814_output.getInt64(i, 3);
            int32_t _c_current_cdemo_sk2 = tbl_JOIN_INNER_TD_4723814_output.getInt32(i, 4);
            int32_t _c_current_hdemo_sk3 = tbl_JOIN_INNER_TD_4723814_output.getInt32(i, 5);
            SW_JOIN_INNER_TD_3525367_payload_leftMajor payloadA{_cc_call_center_id904, _cc_name909, _cc_manager914, _cr_net_loss1049, _c_current_cdemo_sk2, _c_current_hdemo_sk3};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_4110362_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cd_demo_sk93_k = tbl_Filter_TD_4110362_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3525367_key_leftMajor{_cd_demo_sk93_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _cc_call_center_id904 = (it->second)._cc_call_center_id904;
                std::array<char, TPCDS_READ_MAX + 1> _cc_call_center_id904_n{};
                memcpy(_cc_call_center_id904_n.data(), (_cc_call_center_id904).data(), (_cc_call_center_id904).length());
                std::string _cc_name909 = (it->second)._cc_name909;
                std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n{};
                memcpy(_cc_name909_n.data(), (_cc_name909).data(), (_cc_name909).length());
                std::string _cc_manager914 = (it->second)._cc_manager914;
                std::array<char, TPCDS_READ_MAX + 1> _cc_manager914_n{};
                memcpy(_cc_manager914_n.data(), (_cc_manager914).data(), (_cc_manager914).length());
                int64_t _cr_net_loss1049 = (it->second)._cr_net_loss1049;
                int32_t _c_current_cdemo_sk2 = (it->second)._c_current_cdemo_sk2;
                int32_t _c_current_hdemo_sk3 = (it->second)._c_current_hdemo_sk3;
                int32_t _cd_demo_sk93 = tbl_Filter_TD_4110362_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n = tbl_Filter_TD_4110362_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _cd_marital_status95 = std::string(_cd_marital_status95_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_n = tbl_Filter_TD_4110362_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _cd_education_status96 = std::string(_cd_education_status96_n.data());
                tbl_JOIN_INNER_TD_3525367_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _cc_call_center_id904_n);
                tbl_JOIN_INNER_TD_3525367_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cc_name909_n);
                tbl_JOIN_INNER_TD_3525367_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_manager914_n);
                tbl_JOIN_INNER_TD_3525367_output.setInt64(r, 3, _cr_net_loss1049);
                tbl_JOIN_INNER_TD_3525367_output.setInt32(r, 4, _c_current_hdemo_sk3);
                tbl_JOIN_INNER_TD_3525367_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _cd_marital_status95_n);
                tbl_JOIN_INNER_TD_3525367_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _cd_education_status96_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3525367_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3525367_key_rightMajor, SW_JOIN_INNER_TD_3525367_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_4110362_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cd_demo_sk93_k = tbl_Filter_TD_4110362_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3525367_key_rightMajor keyA{_cd_demo_sk93_k};
            int32_t _cd_demo_sk93 = tbl_Filter_TD_4110362_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n = tbl_Filter_TD_4110362_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cd_marital_status95 = std::string(_cd_marital_status95_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_n = tbl_Filter_TD_4110362_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _cd_education_status96 = std::string(_cd_education_status96_n.data());
            SW_JOIN_INNER_TD_3525367_payload_rightMajor payloadA{_cd_demo_sk93, _cd_marital_status95, _cd_education_status96};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_4723814_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_current_cdemo_sk2_k = tbl_JOIN_INNER_TD_4723814_output.getInt32(i, 4);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3525367_key_rightMajor{_c_current_cdemo_sk2_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cd_demo_sk93 = (it->second)._cd_demo_sk93;
                std::string _cd_marital_status95 = (it->second)._cd_marital_status95;
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n{};
                memcpy(_cd_marital_status95_n.data(), (_cd_marital_status95).data(), (_cd_marital_status95).length());
                std::string _cd_education_status96 = (it->second)._cd_education_status96;
                std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_n{};
                memcpy(_cd_education_status96_n.data(), (_cd_education_status96).data(), (_cd_education_status96).length());
                std::array<char, TPCDS_READ_MAX + 1> _cc_call_center_id904_n = tbl_JOIN_INNER_TD_4723814_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _cc_call_center_id904 = std::string(_cc_call_center_id904_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_JOIN_INNER_TD_4723814_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _cc_name909 = std::string(_cc_name909_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cc_manager914_n = tbl_JOIN_INNER_TD_4723814_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _cc_manager914 = std::string(_cc_manager914_n.data());
                int64_t _cr_net_loss1049 = tbl_JOIN_INNER_TD_4723814_output.getInt64(i, 3);
                int32_t _c_current_cdemo_sk2 = tbl_JOIN_INNER_TD_4723814_output.getInt32(i, 4);
                int32_t _c_current_hdemo_sk3 = tbl_JOIN_INNER_TD_4723814_output.getInt32(i, 5);
                tbl_JOIN_INNER_TD_3525367_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _cd_marital_status95_n);
                tbl_JOIN_INNER_TD_3525367_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _cd_education_status96_n);
                tbl_JOIN_INNER_TD_3525367_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _cc_call_center_id904_n);
                tbl_JOIN_INNER_TD_3525367_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cc_name909_n);
                tbl_JOIN_INNER_TD_3525367_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_manager914_n);
                tbl_JOIN_INNER_TD_3525367_output.setInt64(r, 3, _cr_net_loss1049);
                tbl_JOIN_INNER_TD_3525367_output.setInt32(r, 4, _c_current_hdemo_sk3);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3525367_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_3525367_output #Row: " << tbl_JOIN_INNER_TD_3525367_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_2168164_key_leftMajor {
    int32_t _c_current_hdemo_sk3;
    bool operator==(const SW_JOIN_INNER_TD_2168164_key_leftMajor& other) const {
        return ((_c_current_hdemo_sk3 == other._c_current_hdemo_sk3));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_2168164_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_2168164_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_current_hdemo_sk3));
    }
};
}
struct SW_JOIN_INNER_TD_2168164_payload_leftMajor {
    std::string _cc_call_center_id904;
    std::string _cc_name909;
    std::string _cc_manager914;
    int64_t _cr_net_loss1049;
    int32_t _c_current_hdemo_sk3;
    std::string _cd_marital_status95;
    std::string _cd_education_status96;
};
struct SW_JOIN_INNER_TD_2168164_key_rightMajor {
    int32_t _hd_demo_sk204;
    bool operator==(const SW_JOIN_INNER_TD_2168164_key_rightMajor& other) const {
        return ((_hd_demo_sk204 == other._hd_demo_sk204));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_2168164_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_2168164_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._hd_demo_sk204));
    }
};
}
struct SW_JOIN_INNER_TD_2168164_payload_rightMajor {
    int32_t _hd_demo_sk204;
};
void SW_JOIN_INNER_TD_2168164(Table &tbl_JOIN_INNER_TD_3525367_output, Table &tbl_Filter_TD_3979165_output, Table &tbl_JOIN_INNER_TD_2168164_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((hd_demo_sk#204 = c_current_hdemo_sk#3))
    // Left Table: ListBuffer(cc_call_center_id#904, cc_name#909, cc_manager#914, cr_net_loss#1049, c_current_hdemo_sk#3, cd_marital_status#95, cd_education_status#96)
    // Right Table: ListBuffer(hd_demo_sk#204)
    // Output Table: ListBuffer(cc_call_center_id#904, cc_name#909, cc_manager#914, cr_net_loss#1049, cd_marital_status#95, cd_education_status#96)
    int left_nrow = tbl_JOIN_INNER_TD_3525367_output.getNumRow();
    int right_nrow = tbl_Filter_TD_3979165_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_2168164_key_leftMajor, SW_JOIN_INNER_TD_2168164_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_3525367_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_current_hdemo_sk3_k = tbl_JOIN_INNER_TD_3525367_output.getInt32(i, 4);
            SW_JOIN_INNER_TD_2168164_key_leftMajor keyA{_c_current_hdemo_sk3_k};
            std::array<char, TPCDS_READ_MAX + 1> _cc_call_center_id904_n = tbl_JOIN_INNER_TD_3525367_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _cc_call_center_id904 = std::string(_cc_call_center_id904_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_JOIN_INNER_TD_3525367_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cc_name909 = std::string(_cc_name909_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cc_manager914_n = tbl_JOIN_INNER_TD_3525367_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _cc_manager914 = std::string(_cc_manager914_n.data());
            int64_t _cr_net_loss1049 = tbl_JOIN_INNER_TD_3525367_output.getInt64(i, 3);
            int32_t _c_current_hdemo_sk3 = tbl_JOIN_INNER_TD_3525367_output.getInt32(i, 4);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n = tbl_JOIN_INNER_TD_3525367_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _cd_marital_status95 = std::string(_cd_marital_status95_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_n = tbl_JOIN_INNER_TD_3525367_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _cd_education_status96 = std::string(_cd_education_status96_n.data());
            SW_JOIN_INNER_TD_2168164_payload_leftMajor payloadA{_cc_call_center_id904, _cc_name909, _cc_manager914, _cr_net_loss1049, _c_current_hdemo_sk3, _cd_marital_status95, _cd_education_status96};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_3979165_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _hd_demo_sk204_k = tbl_Filter_TD_3979165_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_2168164_key_leftMajor{_hd_demo_sk204_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _cc_call_center_id904 = (it->second)._cc_call_center_id904;
                std::array<char, TPCDS_READ_MAX + 1> _cc_call_center_id904_n{};
                memcpy(_cc_call_center_id904_n.data(), (_cc_call_center_id904).data(), (_cc_call_center_id904).length());
                std::string _cc_name909 = (it->second)._cc_name909;
                std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n{};
                memcpy(_cc_name909_n.data(), (_cc_name909).data(), (_cc_name909).length());
                std::string _cc_manager914 = (it->second)._cc_manager914;
                std::array<char, TPCDS_READ_MAX + 1> _cc_manager914_n{};
                memcpy(_cc_manager914_n.data(), (_cc_manager914).data(), (_cc_manager914).length());
                int64_t _cr_net_loss1049 = (it->second)._cr_net_loss1049;
                int32_t _c_current_hdemo_sk3 = (it->second)._c_current_hdemo_sk3;
                std::string _cd_marital_status95 = (it->second)._cd_marital_status95;
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n{};
                memcpy(_cd_marital_status95_n.data(), (_cd_marital_status95).data(), (_cd_marital_status95).length());
                std::string _cd_education_status96 = (it->second)._cd_education_status96;
                std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_n{};
                memcpy(_cd_education_status96_n.data(), (_cd_education_status96).data(), (_cd_education_status96).length());
                int32_t _hd_demo_sk204 = tbl_Filter_TD_3979165_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_2168164_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _cc_call_center_id904_n);
                tbl_JOIN_INNER_TD_2168164_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cc_name909_n);
                tbl_JOIN_INNER_TD_2168164_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_manager914_n);
                tbl_JOIN_INNER_TD_2168164_output.setInt64(r, 3, _cr_net_loss1049);
                tbl_JOIN_INNER_TD_2168164_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _cd_marital_status95_n);
                tbl_JOIN_INNER_TD_2168164_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _cd_education_status96_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_2168164_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_2168164_key_rightMajor, SW_JOIN_INNER_TD_2168164_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_3979165_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _hd_demo_sk204_k = tbl_Filter_TD_3979165_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_2168164_key_rightMajor keyA{_hd_demo_sk204_k};
            int32_t _hd_demo_sk204 = tbl_Filter_TD_3979165_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_2168164_payload_rightMajor payloadA{_hd_demo_sk204};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_3525367_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_current_hdemo_sk3_k = tbl_JOIN_INNER_TD_3525367_output.getInt32(i, 4);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_2168164_key_rightMajor{_c_current_hdemo_sk3_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _hd_demo_sk204 = (it->second)._hd_demo_sk204;
                std::array<char, TPCDS_READ_MAX + 1> _cc_call_center_id904_n = tbl_JOIN_INNER_TD_3525367_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _cc_call_center_id904 = std::string(_cc_call_center_id904_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_JOIN_INNER_TD_3525367_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _cc_name909 = std::string(_cc_name909_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cc_manager914_n = tbl_JOIN_INNER_TD_3525367_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _cc_manager914 = std::string(_cc_manager914_n.data());
                int64_t _cr_net_loss1049 = tbl_JOIN_INNER_TD_3525367_output.getInt64(i, 3);
                int32_t _c_current_hdemo_sk3 = tbl_JOIN_INNER_TD_3525367_output.getInt32(i, 4);
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n = tbl_JOIN_INNER_TD_3525367_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _cd_marital_status95 = std::string(_cd_marital_status95_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_n = tbl_JOIN_INNER_TD_3525367_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _cd_education_status96 = std::string(_cd_education_status96_n.data());
                tbl_JOIN_INNER_TD_2168164_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _cc_call_center_id904_n);
                tbl_JOIN_INNER_TD_2168164_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cc_name909_n);
                tbl_JOIN_INNER_TD_2168164_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_manager914_n);
                tbl_JOIN_INNER_TD_2168164_output.setInt64(r, 3, _cr_net_loss1049);
                tbl_JOIN_INNER_TD_2168164_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _cd_marital_status95_n);
                tbl_JOIN_INNER_TD_2168164_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _cd_education_status96_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_2168164_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_2168164_output #Row: " << tbl_JOIN_INNER_TD_2168164_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_1939108_key {
    std::string _cc_call_center_id904;
    std::string _cc_name909;
    std::string _cc_manager914;
    std::string _cd_marital_status95;
    std::string _cd_education_status96;
    bool operator==(const SW_Aggregate_TD_1939108_key& other) const { return (_cc_call_center_id904 == other._cc_call_center_id904) && (_cc_name909 == other._cc_name909) && (_cc_manager914 == other._cc_manager914) && (_cd_marital_status95 == other._cd_marital_status95) && (_cd_education_status96 == other._cd_education_status96); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_1939108_key> {
    std::size_t operator() (const SW_Aggregate_TD_1939108_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._cc_call_center_id904)) + (hash<string>()(k._cc_name909)) + (hash<string>()(k._cc_manager914)) + (hash<string>()(k._cd_marital_status95)) + (hash<string>()(k._cd_education_status96));
    }
};
}
struct SW_Aggregate_TD_1939108_payload {
    std::string _Call_Center3544;
    std::string _Call_Center_Name3545;
    std::string _Manager3546;
    int64_t _Returns_Loss3547_sum_0;
};
void SW_Aggregate_TD_1939108(Table &tbl_JOIN_INNER_TD_2168164_output, Table &tbl_Aggregate_TD_1939108_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(cc_call_center_id#904, cc_name#909, cc_manager#914, cd_marital_status#95, cd_education_status#96, cc_call_center_id#904 AS Call_Center#3544, cc_name#909 AS Call_Center_Name#3545, cc_manager#914 AS Manager#3546, MakeDecimal(sum(UnscaledValue(cr_net_loss#1049)),17,2) AS Returns_Loss#3547)
    // Input: ListBuffer(cc_call_center_id#904, cc_name#909, cc_manager#914, cr_net_loss#1049, cd_marital_status#95, cd_education_status#96)
    // Output: ListBuffer(Call_Center#3544, Call_Center_Name#3545, Manager#3546, Returns_Loss#3547)
    std::unordered_map<SW_Aggregate_TD_1939108_key, SW_Aggregate_TD_1939108_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_2168164_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _cc_call_center_id904 = tbl_JOIN_INNER_TD_2168164_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name909 = tbl_JOIN_INNER_TD_2168164_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _cc_manager914 = tbl_JOIN_INNER_TD_2168164_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        int64_t _cr_net_loss1049 = tbl_JOIN_INNER_TD_2168164_output.getInt64(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95 = tbl_JOIN_INNER_TD_2168164_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96 = tbl_JOIN_INNER_TD_2168164_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        SW_Aggregate_TD_1939108_key k{std::string(_cc_call_center_id904.data()), std::string(_cc_name909.data()), std::string(_cc_manager914.data()), std::string(_cd_marital_status95.data()), std::string(_cd_education_status96.data())};
        std::array<char, TPCDS_READ_MAX + 1> _Call_Center3544 = _cc_call_center_id904;
        std::array<char, TPCDS_READ_MAX + 1> _Call_Center_Name3545 = _cc_name909;
        std::array<char, TPCDS_READ_MAX + 1> _Manager3546 = _cc_manager914;
        int64_t _Returns_Loss3547_sum_0 = _cr_net_loss1049;
        SW_Aggregate_TD_1939108_payload p{std::string(_Call_Center3544.data()), std::string(_Call_Center_Name3545.data()), std::string(_Manager3546.data()), _Returns_Loss3547_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._Returns_Loss3547_sum_0 + _Returns_Loss3547_sum_0;
            p._Returns_Loss3547_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _cc_call_center_id904 not required in the output table
        // _cc_name909 not required in the output table
        // _cc_manager914 not required in the output table
        // _cd_marital_status95 not required in the output table
        // _cd_education_status96 not required in the output table
        std::array<char, TPCDS_READ_MAX + 1> _Call_Center3544_n{};
        memcpy(_Call_Center3544_n.data(), (it.second)._Call_Center3544.data(), (it.second)._Call_Center3544.length());
        tbl_Aggregate_TD_1939108_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _Call_Center3544_n);
        std::array<char, TPCDS_READ_MAX + 1> _Call_Center_Name3545_n{};
        memcpy(_Call_Center_Name3545_n.data(), (it.second)._Call_Center_Name3545.data(), (it.second)._Call_Center_Name3545.length());
        tbl_Aggregate_TD_1939108_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _Call_Center_Name3545_n);
        std::array<char, TPCDS_READ_MAX + 1> _Manager3546_n{};
        memcpy(_Manager3546_n.data(), (it.second)._Manager3546.data(), (it.second)._Manager3546.length());
        tbl_Aggregate_TD_1939108_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _Manager3546_n);
        int64_t _Returns_Loss3547 = (it.second)._Returns_Loss3547_sum_0;
        tbl_Aggregate_TD_1939108_output.setInt64(r, 3, _Returns_Loss3547);
        ++r;
    }
    tbl_Aggregate_TD_1939108_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_1939108_output #Row: " << tbl_Aggregate_TD_1939108_output.getNumRow() << std::endl;
}

void SW_Sort_TD_0892685(Table &tbl_Aggregate_TD_1939108_output, Table &tbl_Sort_TD_0892685_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(Returns_Loss#3547 DESC NULLS LAST)
    // Input: ListBuffer(Call_Center#3544, Call_Center_Name#3545, Manager#3546, Returns_Loss#3547)
    // Output: ListBuffer(Call_Center#3544, Call_Center_Name#3545, Manager#3546, Returns_Loss#3547)
    struct SW_Sort_TD_0892685Row {
        std::string _Call_Center3544;
        std::string _Call_Center_Name3545;
        std::string _Manager3546;
        int64_t _Returns_Loss3547;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_0892685Row& a, const SW_Sort_TD_0892685Row& b) const { return 
 (a._Returns_Loss3547 > b._Returns_Loss3547); 
}
    }SW_Sort_TD_0892685_order; 

    int nrow1 = tbl_Aggregate_TD_1939108_output.getNumRow();
    std::vector<SW_Sort_TD_0892685Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _Call_Center3544 = tbl_Aggregate_TD_1939108_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _Call_Center_Name3545 = tbl_Aggregate_TD_1939108_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _Manager3546 = tbl_Aggregate_TD_1939108_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        int64_t _Returns_Loss3547 = tbl_Aggregate_TD_1939108_output.getInt64(i, 3);
        SW_Sort_TD_0892685Row t = {std::string(_Call_Center3544.data()),std::string(_Call_Center_Name3545.data()),std::string(_Manager3546.data()),_Returns_Loss3547};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_0892685_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _Call_Center3544{};
        memcpy(_Call_Center3544.data(), (it._Call_Center3544).data(), (it._Call_Center3544).length());
        tbl_Sort_TD_0892685_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _Call_Center3544);
        std::array<char, TPCDS_READ_MAX + 1> _Call_Center_Name3545{};
        memcpy(_Call_Center_Name3545.data(), (it._Call_Center_Name3545).data(), (it._Call_Center_Name3545).length());
        tbl_Sort_TD_0892685_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _Call_Center_Name3545);
        std::array<char, TPCDS_READ_MAX + 1> _Manager3546{};
        memcpy(_Manager3546.data(), (it._Manager3546).data(), (it._Manager3546).length());
        tbl_Sort_TD_0892685_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _Manager3546);
        tbl_Sort_TD_0892685_output.setInt64(r, 3, it._Returns_Loss3547);
        if (r < 10) {
            std::cout << (it._Call_Center3544).data() << " " << (it._Call_Center_Name3545).data() << " " << (it._Manager3546).data() << " " << it._Returns_Loss3547 << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_0892685_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_0892685_output #Row: " << tbl_Sort_TD_0892685_output.getNumRow() << std::endl;
}

