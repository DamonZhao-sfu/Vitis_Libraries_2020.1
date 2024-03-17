#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_9237991(Table &tbl_SerializeFromObject_TD_1072979_input, Table &tbl_Filter_TD_9237991_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_month_seq#3573) AND ((d_month_seq#3573 >= 1176) AND (d_month_seq#3573 <= 1187))) AND isnotnull(d_date_sk#3570)))
    // Input: ListBuffer(d_date_sk#3570, d_month_seq#3573)
    // Output: ListBuffer(d_date_sk#3570)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1072979_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_month_seq3573 = tbl_SerializeFromObject_TD_1072979_input.getInt32(i, 1);
        int32_t _d_date_sk3570 = tbl_SerializeFromObject_TD_1072979_input.getInt32(i, 0);
        if (((_d_month_seq3573!= 0) && ((_d_month_seq3573 >= 1176) && (_d_month_seq3573 <= 1187))) && (_d_date_sk3570!= 0)) {
            int32_t _d_date_sk3570_t = tbl_SerializeFromObject_TD_1072979_input.getInt32(i, 0);
            tbl_Filter_TD_9237991_output.setInt32(r, 0, _d_date_sk3570_t);
            r++;
        }
    }
    tbl_Filter_TD_9237991_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9237991_output #Row: " << tbl_Filter_TD_9237991_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9172885(Table &tbl_SerializeFromObject_TD_10722735_input, Table &tbl_Filter_TD_9172885_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ss_sold_date_sk#3547) AND isnotnull(ss_store_sk#3554)) AND isnotnull(ss_item_sk#3549)))
    // Input: ListBuffer(ss_sold_date_sk#3547, ss_item_sk#3549, ss_store_sk#3554, ss_sales_price#3560)
    // Output: ListBuffer(ss_sold_date_sk#3547, ss_item_sk#3549, ss_store_sk#3554, ss_sales_price#3560)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10722735_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk3547 = tbl_SerializeFromObject_TD_10722735_input.getInt32(i, 0);
        int32_t _ss_store_sk3554 = tbl_SerializeFromObject_TD_10722735_input.getInt32(i, 2);
        int32_t _ss_item_sk3549 = tbl_SerializeFromObject_TD_10722735_input.getInt32(i, 1);
        if (((_ss_sold_date_sk3547!= 0) && (_ss_store_sk3554!= 0)) && (_ss_item_sk3549!= 0)) {
            int32_t _ss_sold_date_sk3547_t = tbl_SerializeFromObject_TD_10722735_input.getInt32(i, 0);
            tbl_Filter_TD_9172885_output.setInt32(r, 0, _ss_sold_date_sk3547_t);
            int32_t _ss_item_sk3549_t = tbl_SerializeFromObject_TD_10722735_input.getInt32(i, 1);
            tbl_Filter_TD_9172885_output.setInt32(r, 1, _ss_item_sk3549_t);
            int32_t _ss_store_sk3554_t = tbl_SerializeFromObject_TD_10722735_input.getInt32(i, 2);
            tbl_Filter_TD_9172885_output.setInt32(r, 2, _ss_store_sk3554_t);
            int64_t _ss_sales_price3560_t = tbl_SerializeFromObject_TD_10722735_input.getInt64(i, 3);
            tbl_Filter_TD_9172885_output.setInt64(r, 3, _ss_sales_price3560_t);
            r++;
        }
    }
    tbl_Filter_TD_9172885_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9172885_output #Row: " << tbl_Filter_TD_9172885_output.getNumRow() << std::endl;
}


void SW_Filter_TD_7521533(Table &tbl_SerializeFromObject_TD_8296862_input, Table &tbl_Filter_TD_7521533_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_month_seq#123) AND ((d_month_seq#123 >= 1176) AND (d_month_seq#123 <= 1187))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_month_seq#123)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8296862_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_month_seq123 = tbl_SerializeFromObject_TD_8296862_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_8296862_input.getInt32(i, 0);
        if (((_d_month_seq123!= 0) && ((_d_month_seq123 >= 1176) && (_d_month_seq123 <= 1187))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_8296862_input.getInt32(i, 0);
            tbl_Filter_TD_7521533_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_7521533_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7521533_output #Row: " << tbl_Filter_TD_7521533_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7758790(Table &tbl_SerializeFromObject_TD_8764101_input, Table &tbl_Filter_TD_7758790_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_sold_date_sk#1206) AND isnotnull(ss_store_sk#1213)))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_store_sk#1213, ss_sales_price#1219)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_store_sk#1213, ss_sales_price#1219)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8764101_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_8764101_input.getInt32(i, 0);
        int32_t _ss_store_sk1213 = tbl_SerializeFromObject_TD_8764101_input.getInt32(i, 2);
        if ((_ss_sold_date_sk1206!= 0) && (_ss_store_sk1213!= 0)) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_8764101_input.getInt32(i, 0);
            tbl_Filter_TD_7758790_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_8764101_input.getInt32(i, 1);
            tbl_Filter_TD_7758790_output.setInt32(r, 1, _ss_item_sk1208_t);
            int32_t _ss_store_sk1213_t = tbl_SerializeFromObject_TD_8764101_input.getInt32(i, 2);
            tbl_Filter_TD_7758790_output.setInt32(r, 2, _ss_store_sk1213_t);
            int64_t _ss_sales_price1219_t = tbl_SerializeFromObject_TD_8764101_input.getInt64(i, 3);
            tbl_Filter_TD_7758790_output.setInt64(r, 3, _ss_sales_price1219_t);
            r++;
        }
    }
    tbl_Filter_TD_7758790_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7758790_output #Row: " << tbl_Filter_TD_7758790_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_762968_consolidate(Table &tbl_Aggregate_TD_762968_output_preprocess, Table &tbl_Aggregate_TD_762968_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_762968_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _ss_store_sk3554 = tbl_Aggregate_TD_762968_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_762968_output.setInt32(r, 0, _ss_store_sk3554);
        int32_t _ss_item_sk3549 = tbl_Aggregate_TD_762968_output_preprocess.getInt32(r, 6);
        tbl_Aggregate_TD_762968_output.setInt32(r, 1, _ss_item_sk3549);
        int64_t _revenue3546 = tbl_Aggregate_TD_762968_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_762968_output.setInt64(r, 2, _revenue3546);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_762968_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_762968_output #Row: " << tbl_Aggregate_TD_762968_output.getNumRow() << std::endl;
}


void SW_Filter_TD_6709673(Table &tbl_Aggregate_TD_762968_output, Table &tbl_Filter_TD_6709673_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(revenue#3546))
    // Input: ListBuffer(ss_store_sk#3554, ss_item_sk#3549, revenue#3546)
    // Output: ListBuffer(ss_store_sk#3554, ss_item_sk#3549, revenue#3546)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_762968_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _revenue3546 = tbl_Aggregate_TD_762968_output.getInt64(i, 2);
        if (_revenue3546!= 0) {
            int32_t _ss_store_sk3554_t = tbl_Aggregate_TD_762968_output.getInt32(i, 0);
            tbl_Filter_TD_6709673_output.setInt32(r, 0, _ss_store_sk3554_t);
            int32_t _ss_item_sk3549_t = tbl_Aggregate_TD_762968_output.getInt32(i, 1);
            tbl_Filter_TD_6709673_output.setInt32(r, 1, _ss_item_sk3549_t);
            int64_t _revenue3546_t = tbl_Aggregate_TD_762968_output.getInt64(i, 2);
            tbl_Filter_TD_6709673_output.setInt64(r, 2, _revenue3546_t);
            r++;
        }
    }
    tbl_Filter_TD_6709673_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6709673_output #Row: " << tbl_Filter_TD_6709673_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6930836(Table &tbl_SerializeFromObject_TD_7661880_input, Table &tbl_Filter_TD_6930836_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(s_store_sk#378))
    // Input: ListBuffer(s_store_sk#378, s_store_name#383)
    // Output: ListBuffer(s_store_sk#378, s_store_name#383)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7661880_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _s_store_sk378 = tbl_SerializeFromObject_TD_7661880_input.getInt32(i, 0);
        if (_s_store_sk378!= 0) {
            int32_t _s_store_sk378_t = tbl_SerializeFromObject_TD_7661880_input.getInt32(i, 0);
            tbl_Filter_TD_6930836_output.setInt32(r, 0, _s_store_sk378_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_t = tbl_SerializeFromObject_TD_7661880_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_6930836_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_store_name383_t);
            r++;
        }
    }
    tbl_Filter_TD_6930836_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6930836_output #Row: " << tbl_Filter_TD_6930836_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_5599450_consolidate(Table &tbl_Aggregate_TD_5599450_output_preprocess, Table &tbl_Aggregate_TD_5599450_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_5599450_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _ss_store_sk1213 = tbl_Aggregate_TD_5599450_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_5599450_output.setInt32(r, 0, _ss_store_sk1213);
        int64_t _revenue3544 = tbl_Aggregate_TD_5599450_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_5599450_output.setInt64(r, 1, _revenue3544);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_5599450_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_5599450_output #Row: " << tbl_Aggregate_TD_5599450_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5811715(Table &tbl_SerializeFromObject_TD_6713419_input, Table &tbl_Filter_TD_5811715_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#228))
    // Input: ListBuffer(i_item_sk#228, i_item_desc#232, i_current_price#233, i_wholesale_cost#234, i_brand#236)
    // Output: ListBuffer(i_item_sk#228, i_item_desc#232, i_current_price#233, i_wholesale_cost#234, i_brand#236)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6713419_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_6713419_input.getInt32(i, 0);
        if (_i_item_sk228!= 0) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_6713419_input.getInt32(i, 0);
            tbl_Filter_TD_5811715_output.setInt32(r, 0, _i_item_sk228_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_t = tbl_SerializeFromObject_TD_6713419_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_5811715_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_desc232_t);
            int64_t _i_current_price233_t = tbl_SerializeFromObject_TD_6713419_input.getInt64(i, 2);
            tbl_Filter_TD_5811715_output.setInt64(r, 2, _i_current_price233_t);
            int64_t _i_wholesale_cost234_t = tbl_SerializeFromObject_TD_6713419_input.getInt64(i, 3);
            tbl_Filter_TD_5811715_output.setInt64(r, 3, _i_wholesale_cost234_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_t = tbl_SerializeFromObject_TD_6713419_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            tbl_Filter_TD_5811715_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _i_brand236_t);
            r++;
        }
    }
    tbl_Filter_TD_5811715_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5811715_output #Row: " << tbl_Filter_TD_5811715_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5306576_key_leftMajor {
    int32_t _s_store_sk378;
    bool operator==(const SW_JOIN_INNER_TD_5306576_key_leftMajor& other) const {
        return ((_s_store_sk378 == other._s_store_sk378));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5306576_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5306576_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_store_sk378));
    }
};
}
struct SW_JOIN_INNER_TD_5306576_payload_leftMajor {
    int32_t _s_store_sk378;
    std::string _s_store_name383;
};
struct SW_JOIN_INNER_TD_5306576_key_rightMajor {
    int32_t _ss_store_sk3554;
    bool operator==(const SW_JOIN_INNER_TD_5306576_key_rightMajor& other) const {
        return ((_ss_store_sk3554 == other._ss_store_sk3554));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5306576_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5306576_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_store_sk3554));
    }
};
}
struct SW_JOIN_INNER_TD_5306576_payload_rightMajor {
    int32_t _ss_store_sk3554;
    int32_t _ss_item_sk3549;
    int64_t _revenue3546;
};
void SW_JOIN_INNER_TD_5306576(Table &tbl_Filter_TD_6930836_output, Table &tbl_Filter_TD_6709673_output, Table &tbl_JOIN_INNER_TD_5306576_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((s_store_sk#378 = ss_store_sk#3554))
    // Left Table: ListBuffer(s_store_sk#378, s_store_name#383)
    // Right Table: ListBuffer(ss_store_sk#3554, ss_item_sk#3549, revenue#3546)
    // Output Table: ListBuffer(s_store_name#383, ss_store_sk#3554, ss_item_sk#3549, revenue#3546)
    int left_nrow = tbl_Filter_TD_6930836_output.getNumRow();
    int right_nrow = tbl_Filter_TD_6709673_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5306576_key_leftMajor, SW_JOIN_INNER_TD_5306576_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_6930836_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_6930836_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5306576_key_leftMajor keyA{_s_store_sk378_k};
            int32_t _s_store_sk378 = tbl_Filter_TD_6930836_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_Filter_TD_6930836_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _s_store_name383 = std::string(_s_store_name383_n.data());
            SW_JOIN_INNER_TD_5306576_payload_leftMajor payloadA{_s_store_sk378, _s_store_name383};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6709673_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_store_sk3554_k = tbl_Filter_TD_6709673_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5306576_key_leftMajor{_ss_store_sk3554_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _s_store_sk378 = (it->second)._s_store_sk378;
                std::string _s_store_name383 = (it->second)._s_store_name383;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n{};
                memcpy(_s_store_name383_n.data(), (_s_store_name383).data(), (_s_store_name383).length());
                int32_t _ss_store_sk3554 = tbl_Filter_TD_6709673_output.getInt32(i, 0);
                int32_t _ss_item_sk3549 = tbl_Filter_TD_6709673_output.getInt32(i, 1);
                int64_t _revenue3546 = tbl_Filter_TD_6709673_output.getInt64(i, 2);
                tbl_JOIN_INNER_TD_5306576_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _s_store_name383_n);
                tbl_JOIN_INNER_TD_5306576_output.setInt32(r, 1, _ss_store_sk3554);
                tbl_JOIN_INNER_TD_5306576_output.setInt32(r, 2, _ss_item_sk3549);
                tbl_JOIN_INNER_TD_5306576_output.setInt64(r, 3, _revenue3546);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5306576_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5306576_key_rightMajor, SW_JOIN_INNER_TD_5306576_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_6709673_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_store_sk3554_k = tbl_Filter_TD_6709673_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5306576_key_rightMajor keyA{_ss_store_sk3554_k};
            int32_t _ss_store_sk3554 = tbl_Filter_TD_6709673_output.getInt32(i, 0);
            int32_t _ss_item_sk3549 = tbl_Filter_TD_6709673_output.getInt32(i, 1);
            int64_t _revenue3546 = tbl_Filter_TD_6709673_output.getInt64(i, 2);
            SW_JOIN_INNER_TD_5306576_payload_rightMajor payloadA{_ss_store_sk3554, _ss_item_sk3549, _revenue3546};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6930836_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_6930836_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5306576_key_rightMajor{_s_store_sk378_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_store_sk3554 = (it->second)._ss_store_sk3554;
                int32_t _ss_item_sk3549 = (it->second)._ss_item_sk3549;
                int64_t _revenue3546 = (it->second)._revenue3546;
                int32_t _s_store_sk378 = tbl_Filter_TD_6930836_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_Filter_TD_6930836_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _s_store_name383 = std::string(_s_store_name383_n.data());
                tbl_JOIN_INNER_TD_5306576_output.setInt32(r, 1, _ss_store_sk3554);
                tbl_JOIN_INNER_TD_5306576_output.setInt32(r, 2, _ss_item_sk3549);
                tbl_JOIN_INNER_TD_5306576_output.setInt64(r, 3, _revenue3546);
                tbl_JOIN_INNER_TD_5306576_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _s_store_name383_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5306576_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5306576_output #Row: " << tbl_JOIN_INNER_TD_5306576_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_4332386_consolidate(Table &tbl_Aggregate_TD_4332386_output_preprocess, Table &tbl_Aggregate_TD_4332386_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_4332386_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _ss_store_sk1213 = tbl_Aggregate_TD_4332386_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_4332386_output.setInt32(r, 0, _ss_store_sk1213);
        int64_t _ave3545 = tbl_Aggregate_TD_4332386_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_4332386_output.setInt64(r, 1, _ave3545);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_4332386_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_4332386_output #Row: " << tbl_Aggregate_TD_4332386_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4754884_key_leftMajor {
    int32_t _ss_item_sk3549;
    bool operator==(const SW_JOIN_INNER_TD_4754884_key_leftMajor& other) const {
        return ((_ss_item_sk3549 == other._ss_item_sk3549));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4754884_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4754884_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk3549));
    }
};
}
struct SW_JOIN_INNER_TD_4754884_payload_leftMajor {
    std::string _s_store_name383;
    int32_t _ss_store_sk3554;
    int32_t _ss_item_sk3549;
    int64_t _revenue3546;
};
struct SW_JOIN_INNER_TD_4754884_key_rightMajor {
    int32_t _i_item_sk228;
    bool operator==(const SW_JOIN_INNER_TD_4754884_key_rightMajor& other) const {
        return ((_i_item_sk228 == other._i_item_sk228));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4754884_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4754884_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk228));
    }
};
}
struct SW_JOIN_INNER_TD_4754884_payload_rightMajor {
    int32_t _i_item_sk228;
    std::string _i_item_desc232;
    int64_t _i_current_price233;
    int64_t _i_wholesale_cost234;
    std::string _i_brand236;
};
void SW_JOIN_INNER_TD_4754884(Table &tbl_JOIN_INNER_TD_5306576_output, Table &tbl_Filter_TD_5811715_output, Table &tbl_JOIN_INNER_TD_4754884_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((i_item_sk#228 = ss_item_sk#3549))
    // Left Table: ListBuffer(s_store_name#383, ss_store_sk#3554, ss_item_sk#3549, revenue#3546)
    // Right Table: ListBuffer(i_item_sk#228, i_item_desc#232, i_current_price#233, i_wholesale_cost#234, i_brand#236)
    // Output Table: ListBuffer(s_store_name#383, ss_store_sk#3554, revenue#3546, i_item_desc#232, i_current_price#233, i_wholesale_cost#234, i_brand#236)
    int left_nrow = tbl_JOIN_INNER_TD_5306576_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5811715_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4754884_key_leftMajor, SW_JOIN_INNER_TD_4754884_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_5306576_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk3549_k = tbl_JOIN_INNER_TD_5306576_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_4754884_key_leftMajor keyA{_ss_item_sk3549_k};
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_5306576_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _s_store_name383 = std::string(_s_store_name383_n.data());
            int32_t _ss_store_sk3554 = tbl_JOIN_INNER_TD_5306576_output.getInt32(i, 1);
            int32_t _ss_item_sk3549 = tbl_JOIN_INNER_TD_5306576_output.getInt32(i, 2);
            int64_t _revenue3546 = tbl_JOIN_INNER_TD_5306576_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_4754884_payload_leftMajor payloadA{_s_store_name383, _ss_store_sk3554, _ss_item_sk3549, _revenue3546};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5811715_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_5811715_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4754884_key_leftMajor{_i_item_sk228_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _s_store_name383 = (it->second)._s_store_name383;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n{};
                memcpy(_s_store_name383_n.data(), (_s_store_name383).data(), (_s_store_name383).length());
                int32_t _ss_store_sk3554 = (it->second)._ss_store_sk3554;
                int32_t _ss_item_sk3549 = (it->second)._ss_item_sk3549;
                int64_t _revenue3546 = (it->second)._revenue3546;
                int32_t _i_item_sk228 = tbl_Filter_TD_5811715_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n = tbl_Filter_TD_5811715_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_item_desc232 = std::string(_i_item_desc232_n.data());
                int64_t _i_current_price233 = tbl_Filter_TD_5811715_output.getInt64(i, 2);
                int64_t _i_wholesale_cost234 = tbl_Filter_TD_5811715_output.getInt64(i, 3);
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_Filter_TD_5811715_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _i_brand236 = std::string(_i_brand236_n.data());
                tbl_JOIN_INNER_TD_4754884_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _s_store_name383_n);
                tbl_JOIN_INNER_TD_4754884_output.setInt32(r, 1, _ss_store_sk3554);
                tbl_JOIN_INNER_TD_4754884_output.setInt64(r, 2, _revenue3546);
                tbl_JOIN_INNER_TD_4754884_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _i_item_desc232_n);
                tbl_JOIN_INNER_TD_4754884_output.setInt64(r, 4, _i_current_price233);
                tbl_JOIN_INNER_TD_4754884_output.setInt64(r, 5, _i_wholesale_cost234);
                tbl_JOIN_INNER_TD_4754884_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _i_brand236_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4754884_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4754884_key_rightMajor, SW_JOIN_INNER_TD_4754884_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5811715_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_5811715_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4754884_key_rightMajor keyA{_i_item_sk228_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_5811715_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n = tbl_Filter_TD_5811715_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_item_desc232 = std::string(_i_item_desc232_n.data());
            int64_t _i_current_price233 = tbl_Filter_TD_5811715_output.getInt64(i, 2);
            int64_t _i_wholesale_cost234 = tbl_Filter_TD_5811715_output.getInt64(i, 3);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_Filter_TD_5811715_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _i_brand236 = std::string(_i_brand236_n.data());
            SW_JOIN_INNER_TD_4754884_payload_rightMajor payloadA{_i_item_sk228, _i_item_desc232, _i_current_price233, _i_wholesale_cost234, _i_brand236};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_5306576_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk3549_k = tbl_JOIN_INNER_TD_5306576_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4754884_key_rightMajor{_ss_item_sk3549_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                std::string _i_item_desc232 = (it->second)._i_item_desc232;
                std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n{};
                memcpy(_i_item_desc232_n.data(), (_i_item_desc232).data(), (_i_item_desc232).length());
                int64_t _i_current_price233 = (it->second)._i_current_price233;
                int64_t _i_wholesale_cost234 = (it->second)._i_wholesale_cost234;
                std::string _i_brand236 = (it->second)._i_brand236;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n{};
                memcpy(_i_brand236_n.data(), (_i_brand236).data(), (_i_brand236).length());
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_5306576_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _s_store_name383 = std::string(_s_store_name383_n.data());
                int32_t _ss_store_sk3554 = tbl_JOIN_INNER_TD_5306576_output.getInt32(i, 1);
                int32_t _ss_item_sk3549 = tbl_JOIN_INNER_TD_5306576_output.getInt32(i, 2);
                int64_t _revenue3546 = tbl_JOIN_INNER_TD_5306576_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_4754884_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _i_item_desc232_n);
                tbl_JOIN_INNER_TD_4754884_output.setInt64(r, 4, _i_current_price233);
                tbl_JOIN_INNER_TD_4754884_output.setInt64(r, 5, _i_wholesale_cost234);
                tbl_JOIN_INNER_TD_4754884_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _i_brand236_n);
                tbl_JOIN_INNER_TD_4754884_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _s_store_name383_n);
                tbl_JOIN_INNER_TD_4754884_output.setInt32(r, 1, _ss_store_sk3554);
                tbl_JOIN_INNER_TD_4754884_output.setInt64(r, 2, _revenue3546);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4754884_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4754884_output #Row: " << tbl_JOIN_INNER_TD_4754884_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_3745615_key_leftMajor {
    int32_t _ss_store_sk3554;
    bool operator==(const SW_JOIN_INNER_TD_3745615_key_leftMajor& other) const {
        return ((_ss_store_sk3554 == other._ss_store_sk3554));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3745615_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3745615_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_store_sk3554));
    }
};
}
struct SW_JOIN_INNER_TD_3745615_payload_leftMajor {
    std::string _s_store_name383;
    int32_t _ss_store_sk3554;
    int64_t _revenue3546;
    std::string _i_item_desc232;
    int64_t _i_current_price233;
    int64_t _i_wholesale_cost234;
    std::string _i_brand236;
};
struct SW_JOIN_INNER_TD_3745615_key_rightMajor {
    int32_t _ss_store_sk1213;
    bool operator==(const SW_JOIN_INNER_TD_3745615_key_rightMajor& other) const {
        return ((_ss_store_sk1213 == other._ss_store_sk1213));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3745615_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3745615_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_store_sk1213));
    }
};
}
struct SW_JOIN_INNER_TD_3745615_payload_rightMajor {
    int32_t _ss_store_sk1213;
    int64_t _ave3545;
};
void SW_JOIN_INNER_TD_3745615(Table &tbl_JOIN_INNER_TD_4754884_output, Table &tbl_Aggregate_TD_4332386_output, Table &tbl_JOIN_INNER_TD_3745615_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((ss_store_sk#1213 = ss_store_sk#3554) AND (cast(revenue#3546 as decimal(23,7)) <= CheckOverflow((0.100000 * promote_precision(ave#3545)), DecimalType(23,7), true))))
    // Left Table: ListBuffer(s_store_name#383, ss_store_sk#3554, revenue#3546, i_item_desc#232, i_current_price#233, i_wholesale_cost#234, i_brand#236)
    // Right Table: ListBuffer(ss_store_sk#1213, ave#3545)
    // Output Table: ListBuffer(s_store_name#383, i_item_desc#232, revenue#3546, i_current_price#233, i_wholesale_cost#234, i_brand#236)
    int left_nrow = tbl_JOIN_INNER_TD_4754884_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_4332386_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3745615_key_leftMajor, SW_JOIN_INNER_TD_3745615_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_4754884_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_store_sk3554_k = tbl_JOIN_INNER_TD_4754884_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_3745615_key_leftMajor keyA{_ss_store_sk3554_k};
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_4754884_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _s_store_name383 = std::string(_s_store_name383_n.data());
            int32_t _ss_store_sk3554 = tbl_JOIN_INNER_TD_4754884_output.getInt32(i, 1);
            int64_t _revenue3546 = tbl_JOIN_INNER_TD_4754884_output.getInt64(i, 2);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n = tbl_JOIN_INNER_TD_4754884_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _i_item_desc232 = std::string(_i_item_desc232_n.data());
            int64_t _i_current_price233 = tbl_JOIN_INNER_TD_4754884_output.getInt64(i, 4);
            int64_t _i_wholesale_cost234 = tbl_JOIN_INNER_TD_4754884_output.getInt64(i, 5);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_JOIN_INNER_TD_4754884_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _i_brand236 = std::string(_i_brand236_n.data());
            SW_JOIN_INNER_TD_3745615_payload_leftMajor payloadA{_s_store_name383, _ss_store_sk3554, _revenue3546, _i_item_desc232, _i_current_price233, _i_wholesale_cost234, _i_brand236};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_4332386_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_store_sk1213_k = tbl_Aggregate_TD_4332386_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3745615_key_leftMajor{_ss_store_sk1213_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _s_store_name383 = (it->second)._s_store_name383;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n{};
                memcpy(_s_store_name383_n.data(), (_s_store_name383).data(), (_s_store_name383).length());
                int32_t _ss_store_sk3554 = (it->second)._ss_store_sk3554;
                int64_t _revenue3546 = (it->second)._revenue3546;
                std::string _i_item_desc232 = (it->second)._i_item_desc232;
                std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n{};
                memcpy(_i_item_desc232_n.data(), (_i_item_desc232).data(), (_i_item_desc232).length());
                int64_t _i_current_price233 = (it->second)._i_current_price233;
                int64_t _i_wholesale_cost234 = (it->second)._i_wholesale_cost234;
                std::string _i_brand236 = (it->second)._i_brand236;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n{};
                memcpy(_i_brand236_n.data(), (_i_brand236).data(), (_i_brand236).length());
                int32_t _ss_store_sk1213 = tbl_Aggregate_TD_4332386_output.getInt32(i, 0);
                int64_t _ave3545 = tbl_Aggregate_TD_4332386_output.getInt64(i, 1);
                tbl_JOIN_INNER_TD_3745615_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _s_store_name383_n);
                tbl_JOIN_INNER_TD_3745615_output.setInt64(r, 2, _revenue3546);
                tbl_JOIN_INNER_TD_3745615_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_desc232_n);
                tbl_JOIN_INNER_TD_3745615_output.setInt64(r, 3, _i_current_price233);
                tbl_JOIN_INNER_TD_3745615_output.setInt64(r, 4, _i_wholesale_cost234);
                tbl_JOIN_INNER_TD_3745615_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _i_brand236_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3745615_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3745615_key_rightMajor, SW_JOIN_INNER_TD_3745615_payload_rightMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_4332386_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_store_sk1213_k = tbl_Aggregate_TD_4332386_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3745615_key_rightMajor keyA{_ss_store_sk1213_k};
            int32_t _ss_store_sk1213 = tbl_Aggregate_TD_4332386_output.getInt32(i, 0);
            int64_t _ave3545 = tbl_Aggregate_TD_4332386_output.getInt64(i, 1);
            SW_JOIN_INNER_TD_3745615_payload_rightMajor payloadA{_ss_store_sk1213, _ave3545};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_4754884_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_store_sk3554_k = tbl_JOIN_INNER_TD_4754884_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3745615_key_rightMajor{_ss_store_sk3554_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_store_sk1213 = (it->second)._ss_store_sk1213;
                int64_t _ave3545 = (it->second)._ave3545;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_4754884_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _s_store_name383 = std::string(_s_store_name383_n.data());
                int32_t _ss_store_sk3554 = tbl_JOIN_INNER_TD_4754884_output.getInt32(i, 1);
                int64_t _revenue3546 = tbl_JOIN_INNER_TD_4754884_output.getInt64(i, 2);
                std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n = tbl_JOIN_INNER_TD_4754884_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _i_item_desc232 = std::string(_i_item_desc232_n.data());
                int64_t _i_current_price233 = tbl_JOIN_INNER_TD_4754884_output.getInt64(i, 4);
                int64_t _i_wholesale_cost234 = tbl_JOIN_INNER_TD_4754884_output.getInt64(i, 5);
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_JOIN_INNER_TD_4754884_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _i_brand236 = std::string(_i_brand236_n.data());
                tbl_JOIN_INNER_TD_3745615_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _s_store_name383_n);
                tbl_JOIN_INNER_TD_3745615_output.setInt64(r, 2, _revenue3546);
                tbl_JOIN_INNER_TD_3745615_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_desc232_n);
                tbl_JOIN_INNER_TD_3745615_output.setInt64(r, 3, _i_current_price233);
                tbl_JOIN_INNER_TD_3745615_output.setInt64(r, 4, _i_wholesale_cost234);
                tbl_JOIN_INNER_TD_3745615_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _i_brand236_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3745615_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_3745615_output #Row: " << tbl_JOIN_INNER_TD_3745615_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2360197(Table &tbl_JOIN_INNER_TD_3745615_output, Table &tbl_Sort_TD_2360197_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(s_store_name#383 ASC NULLS FIRST, i_item_desc#232 ASC NULLS FIRST)
    // Input: ListBuffer(s_store_name#383, i_item_desc#232, revenue#3546, i_current_price#233, i_wholesale_cost#234, i_brand#236)
    // Output: ListBuffer(s_store_name#383, i_item_desc#232, revenue#3546, i_current_price#233, i_wholesale_cost#234, i_brand#236)
    struct SW_Sort_TD_2360197Row {
        std::string _s_store_name383;
        std::string _i_item_desc232;
        int64_t _revenue3546;
        int64_t _i_current_price233;
        int64_t _i_wholesale_cost234;
        std::string _i_brand236;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2360197Row& a, const SW_Sort_TD_2360197Row& b) const { return 
 (a._s_store_name383 < b._s_store_name383) || 
 ((a._s_store_name383 == b._s_store_name383) && (a._i_item_desc232 < b._i_item_desc232)); 
}
    }SW_Sort_TD_2360197_order; 

    int nrow1 = tbl_JOIN_INNER_TD_3745615_output.getNumRow();
    std::vector<SW_Sort_TD_2360197Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383 = tbl_JOIN_INNER_TD_3745615_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232 = tbl_JOIN_INNER_TD_3745615_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        int64_t _revenue3546 = tbl_JOIN_INNER_TD_3745615_output.getInt64(i, 2);
        int64_t _i_current_price233 = tbl_JOIN_INNER_TD_3745615_output.getInt64(i, 3);
        int64_t _i_wholesale_cost234 = tbl_JOIN_INNER_TD_3745615_output.getInt64(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236 = tbl_JOIN_INNER_TD_3745615_output.getcharN<char, TPCDS_READ_MAX +1>(i, 5);
        SW_Sort_TD_2360197Row t = {std::string(_s_store_name383.data()),std::string(_i_item_desc232.data()),_revenue3546,_i_current_price233,_i_wholesale_cost234,std::string(_i_brand236.data())};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2360197_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383{};
        memcpy(_s_store_name383.data(), (it._s_store_name383).data(), (it._s_store_name383).length());
        tbl_Sort_TD_2360197_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _s_store_name383);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232{};
        memcpy(_i_item_desc232.data(), (it._i_item_desc232).data(), (it._i_item_desc232).length());
        tbl_Sort_TD_2360197_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _i_item_desc232);
        tbl_Sort_TD_2360197_output.setInt64(r, 2, it._revenue3546);
        tbl_Sort_TD_2360197_output.setInt64(r, 3, it._i_current_price233);
        tbl_Sort_TD_2360197_output.setInt64(r, 4, it._i_wholesale_cost234);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236{};
        memcpy(_i_brand236.data(), (it._i_brand236).data(), (it._i_brand236).length());
        tbl_Sort_TD_2360197_output.setcharN<char, TPCDS_READ_MAX +1>(r, 5, _i_brand236);
        ++r;
    }
    tbl_Sort_TD_2360197_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2360197_output #Row: " << tbl_Sort_TD_2360197_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1586279(Table &tbl_Sort_TD_2360197_output, Table &tbl_LocalLimit_TD_1586279_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(s_store_name#383, i_item_desc#232, revenue#3546, i_current_price#233, i_wholesale_cost#234, i_brand#236)
    // Output: ListBuffer(s_store_name#383, i_item_desc#232, revenue#3546, i_current_price#233, i_wholesale_cost#234, i_brand#236)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_Sort_TD_2360197_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1586279_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _s_store_name383_n);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n = tbl_Sort_TD_2360197_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_1586279_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_desc232_n);
        tbl_LocalLimit_TD_1586279_output.setInt64(r, 2, tbl_Sort_TD_2360197_output.getInt64(i, 2));
        tbl_LocalLimit_TD_1586279_output.setInt64(r, 3, tbl_Sort_TD_2360197_output.getInt64(i, 3));
        tbl_LocalLimit_TD_1586279_output.setInt64(r, 4, tbl_Sort_TD_2360197_output.getInt64(i, 4));
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_Sort_TD_2360197_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        tbl_LocalLimit_TD_1586279_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _i_brand236_n);
        r++;
    }
    tbl_LocalLimit_TD_1586279_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1586279_output #Row: " << tbl_LocalLimit_TD_1586279_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0437713(Table &tbl_LocalLimit_TD_1586279_output, Table &tbl_GlobalLimit_TD_0437713_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(s_store_name#383, i_item_desc#232, revenue#3546, i_current_price#233, i_wholesale_cost#234, i_brand#236)
    // Output: ListBuffer(s_store_name#383, i_item_desc#232, revenue#3546, i_current_price#233, i_wholesale_cost#234, i_brand#236)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_LocalLimit_TD_1586279_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0437713_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _s_store_name383_n);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n = tbl_LocalLimit_TD_1586279_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_0437713_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_desc232_n);
        tbl_GlobalLimit_TD_0437713_output.setInt64(r, 2, tbl_LocalLimit_TD_1586279_output.getInt64(i, 2));
        tbl_GlobalLimit_TD_0437713_output.setInt64(r, 3, tbl_LocalLimit_TD_1586279_output.getInt64(i, 3));
        tbl_GlobalLimit_TD_0437713_output.setInt64(r, 4, tbl_LocalLimit_TD_1586279_output.getInt64(i, 4));
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_LocalLimit_TD_1586279_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        tbl_GlobalLimit_TD_0437713_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _i_brand236_n);
        r++;
    }
    tbl_GlobalLimit_TD_0437713_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0437713_output #Row: " << tbl_GlobalLimit_TD_0437713_output.getNumRow() << std::endl;
}

