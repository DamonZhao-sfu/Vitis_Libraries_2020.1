#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_6363769(Table &tbl_SerializeFromObject_TD_7762907_input, Table &tbl_Filter_TD_6363769_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_sold_date_sk#1206) AND isnotnull(ss_store_sk#1213)))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_store_sk#1213, ss_sales_price#1219)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_store_sk#1213, ss_sales_price#1219)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7762907_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_7762907_input.getInt32(i, 0);
        int32_t _ss_store_sk1213 = tbl_SerializeFromObject_TD_7762907_input.getInt32(i, 1);
        if ((_ss_sold_date_sk1206!= 0) && (_ss_store_sk1213!= 0)) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_7762907_input.getInt32(i, 0);
            tbl_Filter_TD_6363769_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_store_sk1213_t = tbl_SerializeFromObject_TD_7762907_input.getInt32(i, 1);
            tbl_Filter_TD_6363769_output.setInt32(r, 1, _ss_store_sk1213_t);
            int64_t _ss_sales_price1219_t = tbl_SerializeFromObject_TD_7762907_input.getInt64(i, 2);
            tbl_Filter_TD_6363769_output.setInt64(r, 2, _ss_sales_price1219_t);
            r++;
        }
    }
    tbl_Filter_TD_6363769_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6363769_output #Row: " << tbl_Filter_TD_6363769_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6782103(Table &tbl_SerializeFromObject_TD_7724527_input, Table &tbl_Filter_TD_6782103_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#126) AND (d_year#126 = 2000)) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_day_name#134, d_year#126)
    // Output: ListBuffer(d_date_sk#120, d_day_name#134)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7724527_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_7724527_input.getInt32(i, 2);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_7724527_input.getInt32(i, 0);
        if (((_d_year126!= 0) && (_d_year126 == 2000)) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_7724527_input.getInt32(i, 0);
            tbl_Filter_TD_6782103_output.setInt32(r, 0, _d_date_sk120_t);
            std::array<char, TPCDS_READ_MAX + 1> _d_day_name134_t = tbl_SerializeFromObject_TD_7724527_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_6782103_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _d_day_name134_t);
            r++;
        }
    }
    tbl_Filter_TD_6782103_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6782103_output #Row: " << tbl_Filter_TD_6782103_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5157459(Table &tbl_SerializeFromObject_TD_630191_input, Table &tbl_Filter_TD_5157459_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(s_gmt_offset#405) AND (s_gmt_offset#405 = -5.00)) AND isnotnull(s_store_sk#378)))
    // Input: ListBuffer(s_store_sk#378, s_store_id#379, s_store_name#383, s_gmt_offset#405)
    // Output: ListBuffer(s_store_sk#378, s_store_id#379, s_store_name#383)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_630191_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _s_gmt_offset405 = tbl_SerializeFromObject_TD_630191_input.getInt64(i, 3);
        int32_t _s_store_sk378 = tbl_SerializeFromObject_TD_630191_input.getInt32(i, 0);
        if (((_s_gmt_offset405!= 0) && (_s_gmt_offset405 == -5.00)) && (_s_store_sk378!= 0)) {
            int32_t _s_store_sk378_t = tbl_SerializeFromObject_TD_630191_input.getInt32(i, 0);
            tbl_Filter_TD_5157459_output.setInt32(r, 0, _s_store_sk378_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_t = tbl_SerializeFromObject_TD_630191_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_5157459_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_store_id379_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_t = tbl_SerializeFromObject_TD_630191_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_5157459_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_store_name383_t);
            r++;
        }
    }
    tbl_Filter_TD_5157459_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5157459_output #Row: " << tbl_Filter_TD_5157459_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5741773_key_leftMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_5741773_key_leftMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5741773_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5741773_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_5741773_payload_leftMajor {
    int32_t _d_date_sk120;
    std::string _d_day_name134;
};
struct SW_JOIN_INNER_TD_5741773_key_rightMajor {
    int32_t _ss_sold_date_sk1206;
    bool operator==(const SW_JOIN_INNER_TD_5741773_key_rightMajor& other) const {
        return ((_ss_sold_date_sk1206 == other._ss_sold_date_sk1206));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5741773_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5741773_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_sold_date_sk1206));
    }
};
}
struct SW_JOIN_INNER_TD_5741773_payload_rightMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_store_sk1213;
    int64_t _ss_sales_price1219;
};
void SW_JOIN_INNER_TD_5741773(Table &tbl_Filter_TD_6782103_output, Table &tbl_Filter_TD_6363769_output, Table &tbl_JOIN_INNER_TD_5741773_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((d_date_sk#120 = ss_sold_date_sk#1206))
    // Left Table: ListBuffer(d_date_sk#120, d_day_name#134)
    // Right Table: ListBuffer(ss_sold_date_sk#1206, ss_store_sk#1213, ss_sales_price#1219)
    // Output Table: ListBuffer(d_day_name#134, ss_store_sk#1213, ss_sales_price#1219)
    int left_nrow = tbl_Filter_TD_6782103_output.getNumRow();
    int right_nrow = tbl_Filter_TD_6363769_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5741773_key_leftMajor, SW_JOIN_INNER_TD_5741773_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_6782103_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_6782103_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5741773_key_leftMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_6782103_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _d_day_name134_n = tbl_Filter_TD_6782103_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _d_day_name134 = std::string(_d_day_name134_n.data());
            SW_JOIN_INNER_TD_5741773_payload_leftMajor payloadA{_d_date_sk120, _d_day_name134};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6363769_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_Filter_TD_6363769_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5741773_key_leftMajor{_ss_sold_date_sk1206_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                std::string _d_day_name134 = (it->second)._d_day_name134;
                std::array<char, TPCDS_READ_MAX + 1> _d_day_name134_n{};
                memcpy(_d_day_name134_n.data(), (_d_day_name134).data(), (_d_day_name134).length());
                int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_6363769_output.getInt32(i, 0);
                int32_t _ss_store_sk1213 = tbl_Filter_TD_6363769_output.getInt32(i, 1);
                int64_t _ss_sales_price1219 = tbl_Filter_TD_6363769_output.getInt64(i, 2);
                tbl_JOIN_INNER_TD_5741773_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _d_day_name134_n);
                tbl_JOIN_INNER_TD_5741773_output.setInt32(r, 1, _ss_store_sk1213);
                tbl_JOIN_INNER_TD_5741773_output.setInt64(r, 2, _ss_sales_price1219);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5741773_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5741773_key_rightMajor, SW_JOIN_INNER_TD_5741773_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_6363769_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_Filter_TD_6363769_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5741773_key_rightMajor keyA{_ss_sold_date_sk1206_k};
            int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_6363769_output.getInt32(i, 0);
            int32_t _ss_store_sk1213 = tbl_Filter_TD_6363769_output.getInt32(i, 1);
            int64_t _ss_sales_price1219 = tbl_Filter_TD_6363769_output.getInt64(i, 2);
            SW_JOIN_INNER_TD_5741773_payload_rightMajor payloadA{_ss_sold_date_sk1206, _ss_store_sk1213, _ss_sales_price1219};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6782103_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_6782103_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5741773_key_rightMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_store_sk1213 = (it->second)._ss_store_sk1213;
                int64_t _ss_sales_price1219 = (it->second)._ss_sales_price1219;
                int32_t _d_date_sk120 = tbl_Filter_TD_6782103_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _d_day_name134_n = tbl_Filter_TD_6782103_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _d_day_name134 = std::string(_d_day_name134_n.data());
                tbl_JOIN_INNER_TD_5741773_output.setInt32(r, 1, _ss_store_sk1213);
                tbl_JOIN_INNER_TD_5741773_output.setInt64(r, 2, _ss_sales_price1219);
                tbl_JOIN_INNER_TD_5741773_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _d_day_name134_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5741773_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5741773_output #Row: " << tbl_JOIN_INNER_TD_5741773_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4549771_key_leftMajor {
    int32_t _ss_store_sk1213;
    bool operator==(const SW_JOIN_INNER_TD_4549771_key_leftMajor& other) const {
        return ((_ss_store_sk1213 == other._ss_store_sk1213));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4549771_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4549771_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_store_sk1213));
    }
};
}
struct SW_JOIN_INNER_TD_4549771_payload_leftMajor {
    std::string _d_day_name134;
    int32_t _ss_store_sk1213;
    int64_t _ss_sales_price1219;
};
struct SW_JOIN_INNER_TD_4549771_key_rightMajor {
    int32_t _s_store_sk378;
    bool operator==(const SW_JOIN_INNER_TD_4549771_key_rightMajor& other) const {
        return ((_s_store_sk378 == other._s_store_sk378));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4549771_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4549771_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_store_sk378));
    }
};
}
struct SW_JOIN_INNER_TD_4549771_payload_rightMajor {
    int32_t _s_store_sk378;
    std::string _s_store_id379;
    std::string _s_store_name383;
};
void SW_JOIN_INNER_TD_4549771(Table &tbl_JOIN_INNER_TD_5741773_output, Table &tbl_Filter_TD_5157459_output, Table &tbl_JOIN_INNER_TD_4549771_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((s_store_sk#378 = ss_store_sk#1213))
    // Left Table: ListBuffer(d_day_name#134, ss_store_sk#1213, ss_sales_price#1219)
    // Right Table: ListBuffer(s_store_sk#378, s_store_id#379, s_store_name#383)
    // Output Table: ListBuffer(d_day_name#134, ss_sales_price#1219, s_store_id#379, s_store_name#383)
    int left_nrow = tbl_JOIN_INNER_TD_5741773_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5157459_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4549771_key_leftMajor, SW_JOIN_INNER_TD_4549771_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_5741773_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_store_sk1213_k = tbl_JOIN_INNER_TD_5741773_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_4549771_key_leftMajor keyA{_ss_store_sk1213_k};
            std::array<char, TPCDS_READ_MAX + 1> _d_day_name134_n = tbl_JOIN_INNER_TD_5741773_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _d_day_name134 = std::string(_d_day_name134_n.data());
            int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_5741773_output.getInt32(i, 1);
            int64_t _ss_sales_price1219 = tbl_JOIN_INNER_TD_5741773_output.getInt64(i, 2);
            SW_JOIN_INNER_TD_4549771_payload_leftMajor payloadA{_d_day_name134, _ss_store_sk1213, _ss_sales_price1219};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5157459_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_5157459_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4549771_key_leftMajor{_s_store_sk378_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _d_day_name134 = (it->second)._d_day_name134;
                std::array<char, TPCDS_READ_MAX + 1> _d_day_name134_n{};
                memcpy(_d_day_name134_n.data(), (_d_day_name134).data(), (_d_day_name134).length());
                int32_t _ss_store_sk1213 = (it->second)._ss_store_sk1213;
                int64_t _ss_sales_price1219 = (it->second)._ss_sales_price1219;
                int32_t _s_store_sk378 = tbl_Filter_TD_5157459_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_n = tbl_Filter_TD_5157459_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _s_store_id379 = std::string(_s_store_id379_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_Filter_TD_5157459_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _s_store_name383 = std::string(_s_store_name383_n.data());
                tbl_JOIN_INNER_TD_4549771_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _d_day_name134_n);
                tbl_JOIN_INNER_TD_4549771_output.setInt64(r, 1, _ss_sales_price1219);
                tbl_JOIN_INNER_TD_4549771_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_store_id379_n);
                tbl_JOIN_INNER_TD_4549771_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _s_store_name383_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4549771_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4549771_key_rightMajor, SW_JOIN_INNER_TD_4549771_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5157459_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_5157459_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4549771_key_rightMajor keyA{_s_store_sk378_k};
            int32_t _s_store_sk378 = tbl_Filter_TD_5157459_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_n = tbl_Filter_TD_5157459_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _s_store_id379 = std::string(_s_store_id379_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_Filter_TD_5157459_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _s_store_name383 = std::string(_s_store_name383_n.data());
            SW_JOIN_INNER_TD_4549771_payload_rightMajor payloadA{_s_store_sk378, _s_store_id379, _s_store_name383};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_5741773_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_store_sk1213_k = tbl_JOIN_INNER_TD_5741773_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4549771_key_rightMajor{_ss_store_sk1213_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _s_store_sk378 = (it->second)._s_store_sk378;
                std::string _s_store_id379 = (it->second)._s_store_id379;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_n{};
                memcpy(_s_store_id379_n.data(), (_s_store_id379).data(), (_s_store_id379).length());
                std::string _s_store_name383 = (it->second)._s_store_name383;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n{};
                memcpy(_s_store_name383_n.data(), (_s_store_name383).data(), (_s_store_name383).length());
                std::array<char, TPCDS_READ_MAX + 1> _d_day_name134_n = tbl_JOIN_INNER_TD_5741773_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _d_day_name134 = std::string(_d_day_name134_n.data());
                int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_5741773_output.getInt32(i, 1);
                int64_t _ss_sales_price1219 = tbl_JOIN_INNER_TD_5741773_output.getInt64(i, 2);
                tbl_JOIN_INNER_TD_4549771_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_store_id379_n);
                tbl_JOIN_INNER_TD_4549771_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _s_store_name383_n);
                tbl_JOIN_INNER_TD_4549771_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _d_day_name134_n);
                tbl_JOIN_INNER_TD_4549771_output.setInt64(r, 1, _ss_sales_price1219);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4549771_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4549771_output #Row: " << tbl_JOIN_INNER_TD_4549771_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_3204869_key {
    std::string _s_store_name383;
    std::string _s_store_id379;
    bool operator==(const SW_Aggregate_TD_3204869_key& other) const { return (_s_store_name383 == other._s_store_name383) && (_s_store_id379 == other._s_store_id379); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_3204869_key> {
    std::size_t operator() (const SW_Aggregate_TD_3204869_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._s_store_name383)) + (hash<string>()(k._s_store_id379));
    }
};
}
struct SW_Aggregate_TD_3204869_payload {
    int64_t _sun_sales3544_sum_0;
    int64_t _mon_sales3545_sum_1;
    int64_t _tue_sales3546_sum_2;
    int64_t _wed_sales3547_sum_3;
    int64_t _thu_sales3548_sum_4;
    int64_t _fri_sales3549_sum_5;
    int64_t _sat_sales3550_sum_6;
};
void SW_Aggregate_TD_3204869(Table &tbl_JOIN_INNER_TD_4549771_output, Table &tbl_Aggregate_TD_3204869_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(s_store_name#383, s_store_id#379, MakeDecimal(sum(UnscaledValue(CASE WHEN (d_day_name#134 = Sunday) THEN ss_sales_price#1219 END)),17,2) AS sun_sales#3544, MakeDecimal(sum(UnscaledValue(CASE WHEN (d_day_name#134 = Monday) THEN ss_sales_price#1219 END)),17,2) AS mon_sales#3545, MakeDecimal(sum(UnscaledValue(CASE WHEN (d_day_name#134 = Tuesday) THEN ss_sales_price#1219 END)),17,2) AS tue_sales#3546, MakeDecimal(sum(UnscaledValue(CASE WHEN (d_day_name#134 = Wednesday) THEN ss_sales_price#1219 END)),17,2) AS wed_sales#3547, MakeDecimal(sum(UnscaledValue(CASE WHEN (d_day_name#134 = Thursday) THEN ss_sales_price#1219 END)),17,2) AS thu_sales#3548, MakeDecimal(sum(UnscaledValue(CASE WHEN (d_day_name#134 = Friday) THEN ss_sales_price#1219 END)),17,2) AS fri_sales#3549, MakeDecimal(sum(UnscaledValue(CASE WHEN (d_day_name#134 = Saturday) THEN ss_sales_price#1219 END)),17,2) AS sat_sales#3550)
    // Input: ListBuffer(d_day_name#134, ss_sales_price#1219, s_store_id#379, s_store_name#383)
    // Output: ListBuffer(s_store_name#383, s_store_id#379, sun_sales#3544, mon_sales#3545, tue_sales#3546, wed_sales#3547, thu_sales#3548, fri_sales#3549, sat_sales#3550)
    std::unordered_map<SW_Aggregate_TD_3204869_key, SW_Aggregate_TD_3204869_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_4549771_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _d_day_name134 = tbl_JOIN_INNER_TD_4549771_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        int64_t _ss_sales_price1219 = tbl_JOIN_INNER_TD_4549771_output.getInt64(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_id379 = tbl_JOIN_INNER_TD_4549771_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383 = tbl_JOIN_INNER_TD_4549771_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        SW_Aggregate_TD_3204869_key k{std::string(_s_store_name383.data()), std::string(_s_store_id379.data())};
        int64_t _sun_sales3544_sum_0 = (std::string(_d_day_name134.data()) == "Sunday") ? _ss_sales_price1219 : 1;
        int64_t _mon_sales3545_sum_1 = (std::string(_d_day_name134.data()) == "Monday") ? _ss_sales_price1219 : 1;
        int64_t _tue_sales3546_sum_2 = (std::string(_d_day_name134.data()) == "Tuesday") ? _ss_sales_price1219 : 1;
        int64_t _wed_sales3547_sum_3 = (std::string(_d_day_name134.data()) == "Wednesday") ? _ss_sales_price1219 : 1;
        int64_t _thu_sales3548_sum_4 = (std::string(_d_day_name134.data()) == "Thursday") ? _ss_sales_price1219 : 1;
        int64_t _fri_sales3549_sum_5 = (std::string(_d_day_name134.data()) == "Friday") ? _ss_sales_price1219 : 1;
        int64_t _sat_sales3550_sum_6 = (std::string(_d_day_name134.data()) == "Saturday") ? _ss_sales_price1219 : 1;
        SW_Aggregate_TD_3204869_payload p{_sun_sales3544_sum_0, _mon_sales3545_sum_1, _tue_sales3546_sum_2, _wed_sales3547_sum_3, _thu_sales3548_sum_4, _fri_sales3549_sum_5, _sat_sales3550_sum_6};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._sun_sales3544_sum_0 + _sun_sales3544_sum_0;
            p._sun_sales3544_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._mon_sales3545_sum_1 + _mon_sales3545_sum_1;
            p._mon_sales3545_sum_1 = sum_1;
            int64_t sum_2 = (it->second)._tue_sales3546_sum_2 + _tue_sales3546_sum_2;
            p._tue_sales3546_sum_2 = sum_2;
            int64_t sum_3 = (it->second)._wed_sales3547_sum_3 + _wed_sales3547_sum_3;
            p._wed_sales3547_sum_3 = sum_3;
            int64_t sum_4 = (it->second)._thu_sales3548_sum_4 + _thu_sales3548_sum_4;
            p._thu_sales3548_sum_4 = sum_4;
            int64_t sum_5 = (it->second)._fri_sales3549_sum_5 + _fri_sales3549_sum_5;
            p._fri_sales3549_sum_5 = sum_5;
            int64_t sum_6 = (it->second)._sat_sales3550_sum_6 + _sat_sales3550_sum_6;
            p._sat_sales3550_sum_6 = sum_6;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383{};
        memcpy(_s_store_name383.data(), ((it.first)._s_store_name383).data(), ((it.first)._s_store_name383).length());
        tbl_Aggregate_TD_3204869_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _s_store_name383);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_id379{};
        memcpy(_s_store_id379.data(), ((it.first)._s_store_id379).data(), ((it.first)._s_store_id379).length());
        tbl_Aggregate_TD_3204869_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_store_id379);
        int64_t _sun_sales3544 = (it.second)._sun_sales3544_sum_0;
        tbl_Aggregate_TD_3204869_output.setInt64(r, 2, _sun_sales3544);
        int64_t _mon_sales3545 = (it.second)._mon_sales3545_sum_1;
        tbl_Aggregate_TD_3204869_output.setInt64(r, 3, _mon_sales3545);
        int64_t _tue_sales3546 = (it.second)._tue_sales3546_sum_2;
        tbl_Aggregate_TD_3204869_output.setInt64(r, 4, _tue_sales3546);
        int64_t _wed_sales3547 = (it.second)._wed_sales3547_sum_3;
        tbl_Aggregate_TD_3204869_output.setInt64(r, 5, _wed_sales3547);
        int64_t _thu_sales3548 = (it.second)._thu_sales3548_sum_4;
        tbl_Aggregate_TD_3204869_output.setInt64(r, 6, _thu_sales3548);
        int64_t _fri_sales3549 = (it.second)._fri_sales3549_sum_5;
        tbl_Aggregate_TD_3204869_output.setInt64(r, 7, _fri_sales3549);
        int64_t _sat_sales3550 = (it.second)._sat_sales3550_sum_6;
        tbl_Aggregate_TD_3204869_output.setInt64(r, 8, _sat_sales3550);
        ++r;
    }
    tbl_Aggregate_TD_3204869_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_3204869_output #Row: " << tbl_Aggregate_TD_3204869_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2452741(Table &tbl_Aggregate_TD_3204869_output, Table &tbl_Sort_TD_2452741_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(s_store_name#383 ASC NULLS FIRST, s_store_id#379 ASC NULLS FIRST, sun_sales#3544 ASC NULLS FIRST, mon_sales#3545 ASC NULLS FIRST, tue_sales#3546 ASC NULLS FIRST, wed_sales#3547 ASC NULLS FIRST, thu_sales#3548 ASC NULLS FIRST, fri_sales#3549 ASC NULLS FIRST, sat_sales#3550 ASC NULLS FIRST)
    // Input: ListBuffer(s_store_name#383, s_store_id#379, sun_sales#3544, mon_sales#3545, tue_sales#3546, wed_sales#3547, thu_sales#3548, fri_sales#3549, sat_sales#3550)
    // Output: ListBuffer(s_store_name#383, s_store_id#379, sun_sales#3544, mon_sales#3545, tue_sales#3546, wed_sales#3547, thu_sales#3548, fri_sales#3549, sat_sales#3550)
    struct SW_Sort_TD_2452741Row {
        std::string _s_store_name383;
        std::string _s_store_id379;
        int64_t _sun_sales3544;
        int64_t _mon_sales3545;
        int64_t _tue_sales3546;
        int64_t _wed_sales3547;
        int64_t _thu_sales3548;
        int64_t _fri_sales3549;
        int64_t _sat_sales3550;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2452741Row& a, const SW_Sort_TD_2452741Row& b) const { return 
 (a._s_store_name383 < b._s_store_name383) || 
 ((a._s_store_name383 == b._s_store_name383) && (a._s_store_id379 < b._s_store_id379)) || 
 ((a._s_store_name383 == b._s_store_name383) && (a._s_store_id379 == b._s_store_id379) && (a._sun_sales3544 < b._sun_sales3544)) || 
 ((a._s_store_name383 == b._s_store_name383) && (a._s_store_id379 == b._s_store_id379) && (a._sun_sales3544 == b._sun_sales3544) && (a._mon_sales3545 < b._mon_sales3545)) || 
 ((a._s_store_name383 == b._s_store_name383) && (a._s_store_id379 == b._s_store_id379) && (a._sun_sales3544 == b._sun_sales3544) && (a._mon_sales3545 == b._mon_sales3545) && (a._tue_sales3546 < b._tue_sales3546)) || 
 ((a._s_store_name383 == b._s_store_name383) && (a._s_store_id379 == b._s_store_id379) && (a._sun_sales3544 == b._sun_sales3544) && (a._mon_sales3545 == b._mon_sales3545) && (a._tue_sales3546 == b._tue_sales3546) && (a._wed_sales3547 < b._wed_sales3547)) || 
 ((a._s_store_name383 == b._s_store_name383) && (a._s_store_id379 == b._s_store_id379) && (a._sun_sales3544 == b._sun_sales3544) && (a._mon_sales3545 == b._mon_sales3545) && (a._tue_sales3546 == b._tue_sales3546) && (a._wed_sales3547 == b._wed_sales3547) && (a._thu_sales3548 < b._thu_sales3548)) || 
 ((a._s_store_name383 == b._s_store_name383) && (a._s_store_id379 == b._s_store_id379) && (a._sun_sales3544 == b._sun_sales3544) && (a._mon_sales3545 == b._mon_sales3545) && (a._tue_sales3546 == b._tue_sales3546) && (a._wed_sales3547 == b._wed_sales3547) && (a._thu_sales3548 == b._thu_sales3548) && (a._fri_sales3549 < b._fri_sales3549)) || 
 ((a._s_store_name383 == b._s_store_name383) && (a._s_store_id379 == b._s_store_id379) && (a._sun_sales3544 == b._sun_sales3544) && (a._mon_sales3545 == b._mon_sales3545) && (a._tue_sales3546 == b._tue_sales3546) && (a._wed_sales3547 == b._wed_sales3547) && (a._thu_sales3548 == b._thu_sales3548) && (a._fri_sales3549 == b._fri_sales3549) && (a._sat_sales3550 < b._sat_sales3550)); 
}
    }SW_Sort_TD_2452741_order; 

    int nrow1 = tbl_Aggregate_TD_3204869_output.getNumRow();
    std::vector<SW_Sort_TD_2452741Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383 = tbl_Aggregate_TD_3204869_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_id379 = tbl_Aggregate_TD_3204869_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        int64_t _sun_sales3544 = tbl_Aggregate_TD_3204869_output.getInt64(i, 2);
        int64_t _mon_sales3545 = tbl_Aggregate_TD_3204869_output.getInt64(i, 3);
        int64_t _tue_sales3546 = tbl_Aggregate_TD_3204869_output.getInt64(i, 4);
        int64_t _wed_sales3547 = tbl_Aggregate_TD_3204869_output.getInt64(i, 5);
        int64_t _thu_sales3548 = tbl_Aggregate_TD_3204869_output.getInt64(i, 6);
        int64_t _fri_sales3549 = tbl_Aggregate_TD_3204869_output.getInt64(i, 7);
        int64_t _sat_sales3550 = tbl_Aggregate_TD_3204869_output.getInt64(i, 8);
        SW_Sort_TD_2452741Row t = {std::string(_s_store_name383.data()),std::string(_s_store_id379.data()),_sun_sales3544,_mon_sales3545,_tue_sales3546,_wed_sales3547,_thu_sales3548,_fri_sales3549,_sat_sales3550};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2452741_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383{};
        memcpy(_s_store_name383.data(), (it._s_store_name383).data(), (it._s_store_name383).length());
        tbl_Sort_TD_2452741_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _s_store_name383);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_id379{};
        memcpy(_s_store_id379.data(), (it._s_store_id379).data(), (it._s_store_id379).length());
        tbl_Sort_TD_2452741_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _s_store_id379);
        tbl_Sort_TD_2452741_output.setInt64(r, 2, it._sun_sales3544);
        tbl_Sort_TD_2452741_output.setInt64(r, 3, it._mon_sales3545);
        tbl_Sort_TD_2452741_output.setInt64(r, 4, it._tue_sales3546);
        tbl_Sort_TD_2452741_output.setInt64(r, 5, it._wed_sales3547);
        tbl_Sort_TD_2452741_output.setInt64(r, 6, it._thu_sales3548);
        tbl_Sort_TD_2452741_output.setInt64(r, 7, it._fri_sales3549);
        tbl_Sort_TD_2452741_output.setInt64(r, 8, it._sat_sales3550);
        ++r;
    }
    tbl_Sort_TD_2452741_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2452741_output #Row: " << tbl_Sort_TD_2452741_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1112902(Table &tbl_Sort_TD_2452741_output, Table &tbl_LocalLimit_TD_1112902_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(s_store_name#383, s_store_id#379, sun_sales#3544, mon_sales#3545, tue_sales#3546, wed_sales#3547, thu_sales#3548, fri_sales#3549, sat_sales#3550)
    // Output: ListBuffer(s_store_name#383, s_store_id#379, sun_sales#3544, mon_sales#3545, tue_sales#3546, wed_sales#3547, thu_sales#3548, fri_sales#3549, sat_sales#3550)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_Sort_TD_2452741_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1112902_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _s_store_name383_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_n = tbl_Sort_TD_2452741_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_1112902_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_store_id379_n);
        tbl_LocalLimit_TD_1112902_output.setInt64(r, 2, tbl_Sort_TD_2452741_output.getInt64(i, 2));
        tbl_LocalLimit_TD_1112902_output.setInt64(r, 3, tbl_Sort_TD_2452741_output.getInt64(i, 3));
        tbl_LocalLimit_TD_1112902_output.setInt64(r, 4, tbl_Sort_TD_2452741_output.getInt64(i, 4));
        tbl_LocalLimit_TD_1112902_output.setInt64(r, 5, tbl_Sort_TD_2452741_output.getInt64(i, 5));
        tbl_LocalLimit_TD_1112902_output.setInt64(r, 6, tbl_Sort_TD_2452741_output.getInt64(i, 6));
        tbl_LocalLimit_TD_1112902_output.setInt64(r, 7, tbl_Sort_TD_2452741_output.getInt64(i, 7));
        tbl_LocalLimit_TD_1112902_output.setInt64(r, 8, tbl_Sort_TD_2452741_output.getInt64(i, 8));
        r++;
    }
    tbl_LocalLimit_TD_1112902_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1112902_output #Row: " << tbl_LocalLimit_TD_1112902_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0543461(Table &tbl_LocalLimit_TD_1112902_output, Table &tbl_GlobalLimit_TD_0543461_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(s_store_name#383, s_store_id#379, sun_sales#3544, mon_sales#3545, tue_sales#3546, wed_sales#3547, thu_sales#3548, fri_sales#3549, sat_sales#3550)
    // Output: ListBuffer(s_store_name#383, s_store_id#379, sun_sales#3544, mon_sales#3545, tue_sales#3546, wed_sales#3547, thu_sales#3548, fri_sales#3549, sat_sales#3550)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_LocalLimit_TD_1112902_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0543461_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _s_store_name383_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_n = tbl_LocalLimit_TD_1112902_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_0543461_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_store_id379_n);
        tbl_GlobalLimit_TD_0543461_output.setInt64(r, 2, tbl_LocalLimit_TD_1112902_output.getInt64(i, 2));
        tbl_GlobalLimit_TD_0543461_output.setInt64(r, 3, tbl_LocalLimit_TD_1112902_output.getInt64(i, 3));
        tbl_GlobalLimit_TD_0543461_output.setInt64(r, 4, tbl_LocalLimit_TD_1112902_output.getInt64(i, 4));
        tbl_GlobalLimit_TD_0543461_output.setInt64(r, 5, tbl_LocalLimit_TD_1112902_output.getInt64(i, 5));
        tbl_GlobalLimit_TD_0543461_output.setInt64(r, 6, tbl_LocalLimit_TD_1112902_output.getInt64(i, 6));
        tbl_GlobalLimit_TD_0543461_output.setInt64(r, 7, tbl_LocalLimit_TD_1112902_output.getInt64(i, 7));
        tbl_GlobalLimit_TD_0543461_output.setInt64(r, 8, tbl_LocalLimit_TD_1112902_output.getInt64(i, 8));
        r++;
    }
    tbl_GlobalLimit_TD_0543461_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0543461_output #Row: " << tbl_GlobalLimit_TD_0543461_output.getNumRow() << std::endl;
}

