#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_10831283(Table &tbl_SerializeFromObject_TD_11305067_input, Table &tbl_Filter_TD_10831283_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_month_seq#123) AND ((d_month_seq#123 >= 1200) AND (d_month_seq#123 <= 1211))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126, d_moy#128, d_qoy#130, d_month_seq#123)
    // Output: ListBuffer(d_date_sk#120, d_year#126, d_moy#128, d_qoy#130)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11305067_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_month_seq123 = tbl_SerializeFromObject_TD_11305067_input.getInt32(i, 4);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_11305067_input.getInt32(i, 0);
        if (((_d_month_seq123!= 0) && ((_d_month_seq123 >= 1200) && (_d_month_seq123 <= 1211))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_11305067_input.getInt32(i, 0);
            tbl_Filter_TD_10831283_output.setInt32(r, 0, _d_date_sk120_t);
            int32_t _d_year126_t = tbl_SerializeFromObject_TD_11305067_input.getInt32(i, 1);
            tbl_Filter_TD_10831283_output.setInt32(r, 1, _d_year126_t);
            int32_t _d_moy128_t = tbl_SerializeFromObject_TD_11305067_input.getInt32(i, 2);
            tbl_Filter_TD_10831283_output.setInt32(r, 2, _d_moy128_t);
            int32_t _d_qoy130_t = tbl_SerializeFromObject_TD_11305067_input.getInt32(i, 3);
            tbl_Filter_TD_10831283_output.setInt32(r, 3, _d_qoy130_t);
            r++;
        }
    }
    tbl_Filter_TD_10831283_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10831283_output #Row: " << tbl_Filter_TD_10831283_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10597889(Table &tbl_SerializeFromObject_TD_11245076_input, Table &tbl_Filter_TD_10597889_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_sold_date_sk#1206) AND (isnotnull(ss_store_sk#1213) AND isnotnull(ss_item_sk#1208))))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_store_sk#1213, ss_quantity#1216, ss_sales_price#1219)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_store_sk#1213, ss_quantity#1216, ss_sales_price#1219)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11245076_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_11245076_input.getInt32(i, 0);
        int32_t _ss_store_sk1213 = tbl_SerializeFromObject_TD_11245076_input.getInt32(i, 2);
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_11245076_input.getInt32(i, 1);
        if ((_ss_sold_date_sk1206!= 0) && ((_ss_store_sk1213!= 0) && (_ss_item_sk1208!= 0))) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_11245076_input.getInt32(i, 0);
            tbl_Filter_TD_10597889_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_11245076_input.getInt32(i, 1);
            tbl_Filter_TD_10597889_output.setInt32(r, 1, _ss_item_sk1208_t);
            int32_t _ss_store_sk1213_t = tbl_SerializeFromObject_TD_11245076_input.getInt32(i, 2);
            tbl_Filter_TD_10597889_output.setInt32(r, 2, _ss_store_sk1213_t);
            int32_t _ss_quantity1216_t = tbl_SerializeFromObject_TD_11245076_input.getInt32(i, 3);
            tbl_Filter_TD_10597889_output.setInt32(r, 3, _ss_quantity1216_t);
            int64_t _ss_sales_price1219_t = tbl_SerializeFromObject_TD_11245076_input.getInt64(i, 4);
            tbl_Filter_TD_10597889_output.setInt64(r, 4, _ss_sales_price1219_t);
            r++;
        }
    }
    tbl_Filter_TD_10597889_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10597889_output #Row: " << tbl_Filter_TD_10597889_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9243902(Table &tbl_SerializeFromObject_TD_10649466_input, Table &tbl_Filter_TD_9243902_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(s_store_sk#378))
    // Input: ListBuffer(s_store_sk#378, s_store_id#379)
    // Output: ListBuffer(s_store_sk#378, s_store_id#379)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10649466_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _s_store_sk378 = tbl_SerializeFromObject_TD_10649466_input.getInt32(i, 0);
        if (_s_store_sk378!= 0) {
            int32_t _s_store_sk378_t = tbl_SerializeFromObject_TD_10649466_input.getInt32(i, 0);
            tbl_Filter_TD_9243902_output.setInt32(r, 0, _s_store_sk378_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_t = tbl_SerializeFromObject_TD_10649466_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_9243902_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_store_id379_t);
            r++;
        }
    }
    tbl_Filter_TD_9243902_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9243902_output #Row: " << tbl_Filter_TD_9243902_output.getNumRow() << std::endl;
}


void SW_Filter_TD_8431695(Table &tbl_SerializeFromObject_TD_928953_input, Table &tbl_Filter_TD_8431695_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#228))
    // Input: ListBuffer(i_item_sk#228, i_brand#236, i_class#238, i_category#240, i_product_name#249)
    // Output: ListBuffer(i_item_sk#228, i_brand#236, i_class#238, i_category#240, i_product_name#249)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_928953_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_928953_input.getInt32(i, 0);
        if (_i_item_sk228!= 0) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_928953_input.getInt32(i, 0);
            tbl_Filter_TD_8431695_output.setInt32(r, 0, _i_item_sk228_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_t = tbl_SerializeFromObject_TD_928953_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_8431695_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand236_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_class238_t = tbl_SerializeFromObject_TD_928953_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_8431695_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_class238_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_t = tbl_SerializeFromObject_TD_928953_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_8431695_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _i_category240_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_product_name249_t = tbl_SerializeFromObject_TD_928953_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            tbl_Filter_TD_8431695_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _i_product_name249_t);
            r++;
        }
    }
    tbl_Filter_TD_8431695_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8431695_output #Row: " << tbl_Filter_TD_8431695_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8235201_key_leftMajor {
    int32_t _ss_store_sk1213;
    bool operator==(const SW_JOIN_INNER_TD_8235201_key_leftMajor& other) const {
        return ((_ss_store_sk1213 == other._ss_store_sk1213));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8235201_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8235201_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_store_sk1213));
    }
};
}
struct SW_JOIN_INNER_TD_8235201_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int32_t _ss_store_sk1213;
    int32_t _ss_quantity1216;
    int64_t _ss_sales_price1219;
    int32_t _d_year126;
    int32_t _d_moy128;
    int32_t _d_qoy130;
};
struct SW_JOIN_INNER_TD_8235201_key_rightMajor {
    int32_t _s_store_sk378;
    bool operator==(const SW_JOIN_INNER_TD_8235201_key_rightMajor& other) const {
        return ((_s_store_sk378 == other._s_store_sk378));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8235201_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8235201_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_store_sk378));
    }
};
}
struct SW_JOIN_INNER_TD_8235201_payload_rightMajor {
    int32_t _s_store_sk378;
    std::string _s_store_id379;
};
void SW_JOIN_INNER_TD_8235201(Table &tbl_JOIN_INNER_TD_9293512_output, Table &tbl_Filter_TD_9243902_output, Table &tbl_JOIN_INNER_TD_8235201_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_store_sk#1213 = s_store_sk#378))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_store_sk#1213, ss_quantity#1216, ss_sales_price#1219, d_year#126, d_moy#128, d_qoy#130)
    // Right Table: ListBuffer(s_store_sk#378, s_store_id#379)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_quantity#1216, ss_sales_price#1219, d_year#126, d_moy#128, d_qoy#130, s_store_id#379)
    int left_nrow = tbl_JOIN_INNER_TD_9293512_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9243902_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8235201_key_leftMajor, SW_JOIN_INNER_TD_8235201_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_9293512_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_store_sk1213_k = tbl_JOIN_INNER_TD_9293512_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_8235201_key_leftMajor keyA{_ss_store_sk1213_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_9293512_output.getInt32(i, 0);
            int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_9293512_output.getInt32(i, 1);
            int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_9293512_output.getInt32(i, 2);
            int64_t _ss_sales_price1219 = tbl_JOIN_INNER_TD_9293512_output.getInt64(i, 3);
            int32_t _d_year126 = tbl_JOIN_INNER_TD_9293512_output.getInt32(i, 4);
            int32_t _d_moy128 = tbl_JOIN_INNER_TD_9293512_output.getInt32(i, 5);
            int32_t _d_qoy130 = tbl_JOIN_INNER_TD_9293512_output.getInt32(i, 6);
            SW_JOIN_INNER_TD_8235201_payload_leftMajor payloadA{_ss_item_sk1208, _ss_store_sk1213, _ss_quantity1216, _ss_sales_price1219, _d_year126, _d_moy128, _d_qoy130};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9243902_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_9243902_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8235201_key_leftMajor{_s_store_sk378_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_store_sk1213 = (it->second)._ss_store_sk1213;
                int32_t _ss_quantity1216 = (it->second)._ss_quantity1216;
                int64_t _ss_sales_price1219 = (it->second)._ss_sales_price1219;
                int32_t _d_year126 = (it->second)._d_year126;
                int32_t _d_moy128 = (it->second)._d_moy128;
                int32_t _d_qoy130 = (it->second)._d_qoy130;
                int32_t _s_store_sk378 = tbl_Filter_TD_9243902_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_n = tbl_Filter_TD_9243902_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _s_store_id379 = std::string(_s_store_id379_n.data());
                tbl_JOIN_INNER_TD_8235201_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_8235201_output.setInt32(r, 1, _ss_quantity1216);
                tbl_JOIN_INNER_TD_8235201_output.setInt64(r, 2, _ss_sales_price1219);
                tbl_JOIN_INNER_TD_8235201_output.setInt32(r, 3, _d_year126);
                tbl_JOIN_INNER_TD_8235201_output.setInt32(r, 4, _d_moy128);
                tbl_JOIN_INNER_TD_8235201_output.setInt32(r, 5, _d_qoy130);
                tbl_JOIN_INNER_TD_8235201_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_store_id379_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8235201_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8235201_key_rightMajor, SW_JOIN_INNER_TD_8235201_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9243902_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_9243902_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8235201_key_rightMajor keyA{_s_store_sk378_k};
            int32_t _s_store_sk378 = tbl_Filter_TD_9243902_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_n = tbl_Filter_TD_9243902_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _s_store_id379 = std::string(_s_store_id379_n.data());
            SW_JOIN_INNER_TD_8235201_payload_rightMajor payloadA{_s_store_sk378, _s_store_id379};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_9293512_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_store_sk1213_k = tbl_JOIN_INNER_TD_9293512_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8235201_key_rightMajor{_ss_store_sk1213_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _s_store_sk378 = (it->second)._s_store_sk378;
                std::string _s_store_id379 = (it->second)._s_store_id379;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_n{};
                memcpy(_s_store_id379_n.data(), (_s_store_id379).data(), (_s_store_id379).length());
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_9293512_output.getInt32(i, 0);
                int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_9293512_output.getInt32(i, 1);
                int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_9293512_output.getInt32(i, 2);
                int64_t _ss_sales_price1219 = tbl_JOIN_INNER_TD_9293512_output.getInt64(i, 3);
                int32_t _d_year126 = tbl_JOIN_INNER_TD_9293512_output.getInt32(i, 4);
                int32_t _d_moy128 = tbl_JOIN_INNER_TD_9293512_output.getInt32(i, 5);
                int32_t _d_qoy130 = tbl_JOIN_INNER_TD_9293512_output.getInt32(i, 6);
                tbl_JOIN_INNER_TD_8235201_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_store_id379_n);
                tbl_JOIN_INNER_TD_8235201_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_8235201_output.setInt32(r, 1, _ss_quantity1216);
                tbl_JOIN_INNER_TD_8235201_output.setInt64(r, 2, _ss_sales_price1219);
                tbl_JOIN_INNER_TD_8235201_output.setInt32(r, 3, _d_year126);
                tbl_JOIN_INNER_TD_8235201_output.setInt32(r, 4, _d_moy128);
                tbl_JOIN_INNER_TD_8235201_output.setInt32(r, 5, _d_qoy130);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8235201_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8235201_output #Row: " << tbl_JOIN_INNER_TD_8235201_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_7528358_key_leftMajor {
    int32_t _ss_item_sk1208;
    bool operator==(const SW_JOIN_INNER_TD_7528358_key_leftMajor& other) const {
        return ((_ss_item_sk1208 == other._ss_item_sk1208));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7528358_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7528358_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk1208));
    }
};
}
struct SW_JOIN_INNER_TD_7528358_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int32_t _ss_quantity1216;
    int64_t _ss_sales_price1219;
    int32_t _d_year126;
    int32_t _d_moy128;
    int32_t _d_qoy130;
    std::string _s_store_id379;
};
struct SW_JOIN_INNER_TD_7528358_key_rightMajor {
    int32_t _i_item_sk228;
    bool operator==(const SW_JOIN_INNER_TD_7528358_key_rightMajor& other) const {
        return ((_i_item_sk228 == other._i_item_sk228));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7528358_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7528358_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk228));
    }
};
}
struct SW_JOIN_INNER_TD_7528358_payload_rightMajor {
    int32_t _i_item_sk228;
    std::string _i_brand236;
    std::string _i_class238;
    std::string _i_category240;
    std::string _i_product_name249;
};
void SW_JOIN_INNER_TD_7528358(Table &tbl_JOIN_INNER_TD_8235201_output, Table &tbl_Filter_TD_8431695_output, Table &tbl_JOIN_INNER_TD_7528358_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_item_sk#1208 = i_item_sk#228))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_quantity#1216, ss_sales_price#1219, d_year#126, d_moy#128, d_qoy#130, s_store_id#379)
    // Right Table: ListBuffer(i_item_sk#228, i_brand#236, i_class#238, i_category#240, i_product_name#249)
    // Output Table: ListBuffer(ss_quantity#1216, ss_sales_price#1219, i_category#240, i_class#238, i_brand#236, i_product_name#249, d_year#126, d_qoy#130, d_moy#128, s_store_id#379)
    int left_nrow = tbl_JOIN_INNER_TD_8235201_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8431695_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7528358_key_leftMajor, SW_JOIN_INNER_TD_7528358_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_8235201_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_8235201_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7528358_key_leftMajor keyA{_ss_item_sk1208_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_8235201_output.getInt32(i, 0);
            int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_8235201_output.getInt32(i, 1);
            int64_t _ss_sales_price1219 = tbl_JOIN_INNER_TD_8235201_output.getInt64(i, 2);
            int32_t _d_year126 = tbl_JOIN_INNER_TD_8235201_output.getInt32(i, 3);
            int32_t _d_moy128 = tbl_JOIN_INNER_TD_8235201_output.getInt32(i, 4);
            int32_t _d_qoy130 = tbl_JOIN_INNER_TD_8235201_output.getInt32(i, 5);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_n = tbl_JOIN_INNER_TD_8235201_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _s_store_id379 = std::string(_s_store_id379_n.data());
            SW_JOIN_INNER_TD_7528358_payload_leftMajor payloadA{_ss_item_sk1208, _ss_quantity1216, _ss_sales_price1219, _d_year126, _d_moy128, _d_qoy130, _s_store_id379};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8431695_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_8431695_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7528358_key_leftMajor{_i_item_sk228_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_quantity1216 = (it->second)._ss_quantity1216;
                int64_t _ss_sales_price1219 = (it->second)._ss_sales_price1219;
                int32_t _d_year126 = (it->second)._d_year126;
                int32_t _d_moy128 = (it->second)._d_moy128;
                int32_t _d_qoy130 = (it->second)._d_qoy130;
                std::string _s_store_id379 = (it->second)._s_store_id379;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_n{};
                memcpy(_s_store_id379_n.data(), (_s_store_id379).data(), (_s_store_id379).length());
                int32_t _i_item_sk228 = tbl_Filter_TD_8431695_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_Filter_TD_8431695_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_brand236 = std::string(_i_brand236_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_class238_n = tbl_Filter_TD_8431695_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _i_class238 = std::string(_i_class238_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_Filter_TD_8431695_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _i_category240 = std::string(_i_category240_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_product_name249_n = tbl_Filter_TD_8431695_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _i_product_name249 = std::string(_i_product_name249_n.data());
                tbl_JOIN_INNER_TD_7528358_output.setInt32(r, 0, _ss_quantity1216);
                tbl_JOIN_INNER_TD_7528358_output.setInt64(r, 1, _ss_sales_price1219);
                tbl_JOIN_INNER_TD_7528358_output.setInt32(r, 6, _d_year126);
                tbl_JOIN_INNER_TD_7528358_output.setInt32(r, 8, _d_moy128);
                tbl_JOIN_INNER_TD_7528358_output.setInt32(r, 7, _d_qoy130);
                tbl_JOIN_INNER_TD_7528358_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_store_id379_n);
                tbl_JOIN_INNER_TD_7528358_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _i_brand236_n);
                tbl_JOIN_INNER_TD_7528358_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _i_class238_n);
                tbl_JOIN_INNER_TD_7528358_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_category240_n);
                tbl_JOIN_INNER_TD_7528358_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _i_product_name249_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7528358_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7528358_key_rightMajor, SW_JOIN_INNER_TD_7528358_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8431695_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_8431695_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7528358_key_rightMajor keyA{_i_item_sk228_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_8431695_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_Filter_TD_8431695_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand236 = std::string(_i_brand236_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_class238_n = tbl_Filter_TD_8431695_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _i_class238 = std::string(_i_class238_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_Filter_TD_8431695_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _i_category240 = std::string(_i_category240_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_product_name249_n = tbl_Filter_TD_8431695_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _i_product_name249 = std::string(_i_product_name249_n.data());
            SW_JOIN_INNER_TD_7528358_payload_rightMajor payloadA{_i_item_sk228, _i_brand236, _i_class238, _i_category240, _i_product_name249};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_8235201_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_8235201_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7528358_key_rightMajor{_ss_item_sk1208_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                std::string _i_brand236 = (it->second)._i_brand236;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n{};
                memcpy(_i_brand236_n.data(), (_i_brand236).data(), (_i_brand236).length());
                std::string _i_class238 = (it->second)._i_class238;
                std::array<char, TPCDS_READ_MAX + 1> _i_class238_n{};
                memcpy(_i_class238_n.data(), (_i_class238).data(), (_i_class238).length());
                std::string _i_category240 = (it->second)._i_category240;
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n{};
                memcpy(_i_category240_n.data(), (_i_category240).data(), (_i_category240).length());
                std::string _i_product_name249 = (it->second)._i_product_name249;
                std::array<char, TPCDS_READ_MAX + 1> _i_product_name249_n{};
                memcpy(_i_product_name249_n.data(), (_i_product_name249).data(), (_i_product_name249).length());
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_8235201_output.getInt32(i, 0);
                int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_8235201_output.getInt32(i, 1);
                int64_t _ss_sales_price1219 = tbl_JOIN_INNER_TD_8235201_output.getInt64(i, 2);
                int32_t _d_year126 = tbl_JOIN_INNER_TD_8235201_output.getInt32(i, 3);
                int32_t _d_moy128 = tbl_JOIN_INNER_TD_8235201_output.getInt32(i, 4);
                int32_t _d_qoy130 = tbl_JOIN_INNER_TD_8235201_output.getInt32(i, 5);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_n = tbl_JOIN_INNER_TD_8235201_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _s_store_id379 = std::string(_s_store_id379_n.data());
                tbl_JOIN_INNER_TD_7528358_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _i_brand236_n);
                tbl_JOIN_INNER_TD_7528358_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _i_class238_n);
                tbl_JOIN_INNER_TD_7528358_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_category240_n);
                tbl_JOIN_INNER_TD_7528358_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _i_product_name249_n);
                tbl_JOIN_INNER_TD_7528358_output.setInt32(r, 0, _ss_quantity1216);
                tbl_JOIN_INNER_TD_7528358_output.setInt64(r, 1, _ss_sales_price1219);
                tbl_JOIN_INNER_TD_7528358_output.setInt32(r, 6, _d_year126);
                tbl_JOIN_INNER_TD_7528358_output.setInt32(r, 8, _d_moy128);
                tbl_JOIN_INNER_TD_7528358_output.setInt32(r, 7, _d_qoy130);
                tbl_JOIN_INNER_TD_7528358_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_store_id379_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7528358_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7528358_output #Row: " << tbl_JOIN_INNER_TD_7528358_output.getNumRow() << std::endl;
}

void SW_Expand_TD_6238310(Table &tbl_JOIN_INNER_TD_7528358_output, Table &tbl_Expand_TD_6238310_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Expand
    // Operation: ListBuffer(Expand)
    // Input: ListBuffer(ss_quantity#1216, ss_sales_price#1219, i_category#240, i_class#238, i_brand#236, i_product_name#249, d_year#126, d_qoy#130, d_moy#128, s_store_id#379)
    // Output: ListBuffer(ss_quantity#1216, ss_sales_price#1219, i_category#3558, i_class#3559, i_brand#3560, i_product_name#3561, d_year#3562, d_qoy#3563, d_moy#3564, s_store_id#3565, spark_grouping_id#3557L)
    std::cout << "tbl_Expand_TD_6238310_output #Row: " << tbl_Expand_TD_6238310_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_5527344_key {
    std::string _i_category3558;
    std::string _i_class3559;
    std::string _i_brand3560;
    std::string _i_product_name3561;
    int32_t _d_year3562;
    int32_t _d_qoy3563;
    int32_t _d_moy3564;
    std::string _s_store_id3565;
    int64_t _spark_grouping_id3557L;
    bool operator==(const SW_Aggregate_TD_5527344_key& other) const { return (_i_category3558 == other._i_category3558) && (_i_class3559 == other._i_class3559) && (_i_brand3560 == other._i_brand3560) && (_i_product_name3561 == other._i_product_name3561) && (_d_year3562 == other._d_year3562) && (_d_qoy3563 == other._d_qoy3563) && (_d_moy3564 == other._d_moy3564) && (_s_store_id3565 == other._s_store_id3565) && (_spark_grouping_id3557L == other._spark_grouping_id3557L); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_5527344_key> {
    std::size_t operator() (const SW_Aggregate_TD_5527344_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_category3558)) + (hash<string>()(k._i_class3559)) + (hash<string>()(k._i_brand3560)) + (hash<string>()(k._i_product_name3561)) + (hash<int32_t>()(k._d_year3562)) + (hash<int32_t>()(k._d_qoy3563)) + (hash<int32_t>()(k._d_moy3564)) + (hash<string>()(k._s_store_id3565)) + (hash<int64_t>()(k._spark_grouping_id3557L));
    }
};
}
struct SW_Aggregate_TD_5527344_payload {
    int64_t _sumsales3544_sum_0;
};
void SW_Aggregate_TD_5527344(Table &tbl_Expand_TD_6238310_output, Table &tbl_Aggregate_TD_5527344_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(i_category#3558, i_class#3559, i_brand#3560, i_product_name#3561, d_year#3562, d_qoy#3563, d_moy#3564, s_store_id#3565, spark_grouping_id#3557L, sum(coalesce(CheckOverflow((promote_precision(cast(ss_sales_price#1219 as decimal(12,2))) * promote_precision(cast(cast(ss_quantity#1216 as decimal(10,0)) as decimal(12,2)))), DecimalType(18,2), true), 0.00)) AS sumsales#3544)
    // Input: ListBuffer(ss_quantity#1216, ss_sales_price#1219, i_category#3558, i_class#3559, i_brand#3560, i_product_name#3561, d_year#3562, d_qoy#3563, d_moy#3564, s_store_id#3565, spark_grouping_id#3557L)
    // Output: ListBuffer(i_category#3558, i_class#3559, i_brand#3560, i_product_name#3561, d_year#3562, d_qoy#3563, d_moy#3564, s_store_id#3565, sumsales#3544)
    std::unordered_map<SW_Aggregate_TD_5527344_key, SW_Aggregate_TD_5527344_payload> ht1;
    int nrow1 = tbl_Expand_TD_6238310_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_quantity1216 = tbl_Expand_TD_6238310_output.getInt32(i, 0);
        int64_t _ss_sales_price1219 = tbl_Expand_TD_6238310_output.getInt64(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _i_category3558 = tbl_Expand_TD_6238310_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _i_class3559 = tbl_Expand_TD_6238310_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand3560 = tbl_Expand_TD_6238310_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _i_product_name3561 = tbl_Expand_TD_6238310_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        int32_t _d_year3562 = tbl_Expand_TD_6238310_output.getInt32(i, 6);
        int32_t _d_qoy3563 = tbl_Expand_TD_6238310_output.getInt32(i, 7);
        int32_t _d_moy3564 = tbl_Expand_TD_6238310_output.getInt32(i, 8);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_id3565 = tbl_Expand_TD_6238310_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
        int64_t _spark_grouping_id3557L = tbl_Expand_TD_6238310_output.getInt64(i, 10);
        SW_Aggregate_TD_5527344_key k{std::string(_i_category3558.data()), std::string(_i_class3559.data()), std::string(_i_brand3560.data()), std::string(_i_product_name3561.data()), _d_year3562, _d_qoy3563, _d_moy3564, std::string(_s_store_id3565.data()), _spark_grouping_id3557L};
        int64_t _sumsales3544_sum_0 = (_ss_sales_price1219 * _ss_quantity1216) != 0 ? (_ss_sales_price1219 * _ss_quantity1216) : 0.00;
        SW_Aggregate_TD_5527344_payload p{_sumsales3544_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._sumsales3544_sum_0 + _sumsales3544_sum_0;
            p._sumsales3544_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category3558{};
        memcpy(_i_category3558.data(), ((it.first)._i_category3558).data(), ((it.first)._i_category3558).length());
        tbl_Aggregate_TD_5527344_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category3558);
        std::array<char, TPCDS_READ_MAX + 1> _i_class3559{};
        memcpy(_i_class3559.data(), ((it.first)._i_class3559).data(), ((it.first)._i_class3559).length());
        tbl_Aggregate_TD_5527344_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_class3559);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand3560{};
        memcpy(_i_brand3560.data(), ((it.first)._i_brand3560).data(), ((it.first)._i_brand3560).length());
        tbl_Aggregate_TD_5527344_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_brand3560);
        std::array<char, TPCDS_READ_MAX + 1> _i_product_name3561{};
        memcpy(_i_product_name3561.data(), ((it.first)._i_product_name3561).data(), ((it.first)._i_product_name3561).length());
        tbl_Aggregate_TD_5527344_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _i_product_name3561);
        tbl_Aggregate_TD_5527344_output.setInt32(r, 4, (it.first)._d_year3562);
        tbl_Aggregate_TD_5527344_output.setInt32(r, 5, (it.first)._d_qoy3563);
        tbl_Aggregate_TD_5527344_output.setInt32(r, 6, (it.first)._d_moy3564);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_id3565{};
        memcpy(_s_store_id3565.data(), ((it.first)._s_store_id3565).data(), ((it.first)._s_store_id3565).length());
        tbl_Aggregate_TD_5527344_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_store_id3565);
        // _spark_grouping_id3557L not required in the output table
        int64_t _sumsales3544 = (it.second)._sumsales3544_sum_0;
        tbl_Aggregate_TD_5527344_output.setInt64(r, 8, _sumsales3544);
        ++r;
    }
    tbl_Aggregate_TD_5527344_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_5527344_output #Row: " << tbl_Aggregate_TD_5527344_output.getNumRow() << std::endl;
}

void SW_Window_TD_4776193(Table &tbl_Aggregate_TD_5527344_output, Table &tbl_Window_TD_4776193_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Window
    // Operation: ListBuffer(rank(sumsales#3544) windowspecdefinition(i_category#3558, sumsales#3544 DESC NULLS LAST, specifiedwindowframe(RowFrame, unboundedpreceding$(), currentrow$())) AS rk#3545)
    // Input: ListBuffer(i_category#3558, i_class#3559, i_brand#3560, i_product_name#3561, d_year#3562, d_qoy#3563, d_moy#3564, s_store_id#3565, sumsales#3544)
    // Output: ListBuffer(i_category#3558, i_class#3559, i_brand#3560, i_product_name#3561, d_year#3562, d_qoy#3563, d_moy#3564, s_store_id#3565, sumsales#3544, rk#3545)
    struct SW_Window_TD_4776193Row {
        std::string _i_category3558;
        std::string _i_class3559;
        std::string _i_brand3560;
        std::string _i_product_name3561;
        int32_t _d_year3562;
        int32_t _d_qoy3563;
        int32_t _d_moy3564;
        std::string _s_store_id3565;
        int64_t _sumsales3544;
    }; 

    int nrow = tbl_Aggregate_TD_5527344_output.getNumRow();
    std::vector<SW_Window_TD_4776193Row> rows0;
    int r = 0;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category3558 = tbl_Aggregate_TD_5527344_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        tbl_Window_TD_4776193_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _i_category3558);
        std::array<char, TPCDS_READ_MAX + 1> _i_class3559 = tbl_Aggregate_TD_5527344_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        tbl_Window_TD_4776193_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _i_class3559);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand3560 = tbl_Aggregate_TD_5527344_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        tbl_Window_TD_4776193_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _i_brand3560);
        std::array<char, TPCDS_READ_MAX + 1> _i_product_name3561 = tbl_Aggregate_TD_5527344_output.getcharN<char, TPCDS_READ_MAX +1>(i, 3);
        tbl_Window_TD_4776193_output.setcharN<char, TPCDS_READ_MAX +1>(r, 3, _i_product_name3561);
        int32_t _d_year3562 = tbl_Aggregate_TD_5527344_output.getInt32(i, 4);
        tbl_Window_TD_4776193_output.setInt32(r, 4,_d_year3562);
        int32_t _d_qoy3563 = tbl_Aggregate_TD_5527344_output.getInt32(i, 5);
        tbl_Window_TD_4776193_output.setInt32(r, 5,_d_qoy3563);
        int32_t _d_moy3564 = tbl_Aggregate_TD_5527344_output.getInt32(i, 6);
        tbl_Window_TD_4776193_output.setInt32(r, 6,_d_moy3564);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_id3565 = tbl_Aggregate_TD_5527344_output.getcharN<char, TPCDS_READ_MAX +1>(i, 7);
        tbl_Window_TD_4776193_output.setcharN<char, TPCDS_READ_MAX +1>(r, 7, _s_store_id3565);
        int64_t _sumsales3544 = tbl_Aggregate_TD_5527344_output.getInt64(i, 8);
        tbl_Window_TD_4776193_output.setInt64(r, 8,_sumsales3544);
        r++;
        SW_Window_TD_4776193Row t = {std::string(_i_category3558.data()),std::string(_i_class3559.data()),std::string(_i_brand3560.data()),std::string(_i_product_name3561.data()),_d_year3562,_d_qoy3563,_d_moy3564,std::string(_s_store_id3565.data()),_sumsales3544};
        rows0.push_back(t);
    }
    struct {
        bool operator()(const SW_Window_TD_4776193Row& a, const SW_Window_TD_4776193Row& b) const { return 
(a._i_category3558 < b._i_category3558) || 
 ((a._i_category3558 == b._i_category3558) && (a._sumsales3544 > b._sumsales3544)); 
}
    }SW_Window_TD_4776193_order0; 

    std::sort(rows0.begin(), rows0.end(), SW_Window_TD_4776193_order0);
    std::vector<int32_t> ranks0(rows0.size(), 0);
    int32_t currentRank0 = 0;
    int32_t currentPartitionCount0 = 1;
    bool isSamePartition0 = true;
    bool isSameOrderKey0 = true;
    if (!rows0.empty()) {;
      ranks0[0] = ++currentRank0;
    };
    for (int i = 1; i< rows0.size(); i++) {
        isSamePartition0 = ( rows0[i]._i_category3558 == rows0[i-1]._i_category3558);
        isSameOrderKey0 = ( rows0[i]._sumsales3544 == rows0[i-1]._sumsales3544);
        currentPartitionCount0++;
        if (isSamePartition0&& !isSameOrderKey0) {
            currentRank0 = currentPartitionCount0;
        } else if (!isSamePartition0) {
            currentPartitionCount0 = 1;
            currentRank0 = currentPartitionCount0;
        }
        ranks0[i] = currentRank0;
    }
    for (int i = 0; i< nrow; i++) {
        tbl_Window_TD_4776193_output.setInt32(r, 9, ranks0[i]);
    }
    tbl_Window_TD_4776193_output.setNumRow(r);
    std::cout << "tbl_Window_TD_4776193_output #Row: " << tbl_Window_TD_4776193_output.getNumRow() << std::endl;
}

void SW_Filter_TD_3982792(Table &tbl_Window_TD_4776193_output, Table &tbl_Filter_TD_3982792_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((rk#3545 <= 100))
    // Input: ListBuffer(i_category#3558, i_class#3559, i_brand#3560, i_product_name#3561, d_year#3562, d_qoy#3563, d_moy#3564, s_store_id#3565, sumsales#3544, rk#3545)
    // Output: ListBuffer(i_category#3558, i_class#3559, i_brand#3560, i_product_name#3561, d_year#3562, d_qoy#3563, d_moy#3564, s_store_id#3565, sumsales#3544, rk#3545)
    int r = 0;
    int nrow1 = tbl_Window_TD_4776193_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _rk3545 = tbl_Window_TD_4776193_output.getInt32(i, 9);
        if (_rk3545 <= 100) {
            std::array<char, TPCDS_READ_MAX + 1> _i_category3558_t = tbl_Window_TD_4776193_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            tbl_Filter_TD_3982792_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category3558_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_class3559_t = tbl_Window_TD_4776193_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_3982792_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_class3559_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand3560_t = tbl_Window_TD_4776193_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_3982792_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_brand3560_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_product_name3561_t = tbl_Window_TD_4776193_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_3982792_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _i_product_name3561_t);
            int32_t _d_year3562_t = tbl_Window_TD_4776193_output.getInt32(i, 4);
            tbl_Filter_TD_3982792_output.setInt32(r, 4, _d_year3562_t);
            int32_t _d_qoy3563_t = tbl_Window_TD_4776193_output.getInt32(i, 5);
            tbl_Filter_TD_3982792_output.setInt32(r, 5, _d_qoy3563_t);
            int32_t _d_moy3564_t = tbl_Window_TD_4776193_output.getInt32(i, 6);
            tbl_Filter_TD_3982792_output.setInt32(r, 6, _d_moy3564_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_id3565_t = tbl_Window_TD_4776193_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            tbl_Filter_TD_3982792_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_store_id3565_t);
            int64_t _sumsales3544_t = tbl_Window_TD_4776193_output.getInt64(i, 8);
            tbl_Filter_TD_3982792_output.setInt64(r, 8, _sumsales3544_t);
            int32_t _rk3545_t = tbl_Window_TD_4776193_output.getInt32(i, 9);
            tbl_Filter_TD_3982792_output.setInt32(r, 9, _rk3545_t);
            r++;
        }
    }
    tbl_Filter_TD_3982792_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_3982792_output #Row: " << tbl_Filter_TD_3982792_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2940586(Table &tbl_Filter_TD_3982792_output, Table &tbl_Sort_TD_2940586_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(i_category#3558 ASC NULLS FIRST, i_class#3559 ASC NULLS FIRST, i_brand#3560 ASC NULLS FIRST, i_product_name#3561 ASC NULLS FIRST, d_year#3562 ASC NULLS FIRST, d_qoy#3563 ASC NULLS FIRST, d_moy#3564 ASC NULLS FIRST, s_store_id#3565 ASC NULLS FIRST, sumsales#3544 ASC NULLS FIRST, rk#3545 ASC NULLS FIRST)
    // Input: ListBuffer(i_category#3558, i_class#3559, i_brand#3560, i_product_name#3561, d_year#3562, d_qoy#3563, d_moy#3564, s_store_id#3565, sumsales#3544, rk#3545)
    // Output: ListBuffer(i_category#3558, i_class#3559, i_brand#3560, i_product_name#3561, d_year#3562, d_qoy#3563, d_moy#3564, s_store_id#3565, sumsales#3544, rk#3545)
    struct SW_Sort_TD_2940586Row {
        std::string _i_category3558;
        std::string _i_class3559;
        std::string _i_brand3560;
        std::string _i_product_name3561;
        int32_t _d_year3562;
        int32_t _d_qoy3563;
        int32_t _d_moy3564;
        std::string _s_store_id3565;
        int64_t _sumsales3544;
        int32_t _rk3545;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2940586Row& a, const SW_Sort_TD_2940586Row& b) const { return 
 (a._i_category3558 < b._i_category3558) || 
 ((a._i_category3558 == b._i_category3558) && (a._i_class3559 < b._i_class3559)) || 
 ((a._i_category3558 == b._i_category3558) && (a._i_class3559 == b._i_class3559) && (a._i_brand3560 < b._i_brand3560)) || 
 ((a._i_category3558 == b._i_category3558) && (a._i_class3559 == b._i_class3559) && (a._i_brand3560 == b._i_brand3560) && (a._i_product_name3561 < b._i_product_name3561)) || 
 ((a._i_category3558 == b._i_category3558) && (a._i_class3559 == b._i_class3559) && (a._i_brand3560 == b._i_brand3560) && (a._i_product_name3561 == b._i_product_name3561) && (a._d_year3562 < b._d_year3562)) || 
 ((a._i_category3558 == b._i_category3558) && (a._i_class3559 == b._i_class3559) && (a._i_brand3560 == b._i_brand3560) && (a._i_product_name3561 == b._i_product_name3561) && (a._d_year3562 == b._d_year3562) && (a._d_qoy3563 < b._d_qoy3563)) || 
 ((a._i_category3558 == b._i_category3558) && (a._i_class3559 == b._i_class3559) && (a._i_brand3560 == b._i_brand3560) && (a._i_product_name3561 == b._i_product_name3561) && (a._d_year3562 == b._d_year3562) && (a._d_qoy3563 == b._d_qoy3563) && (a._d_moy3564 < b._d_moy3564)) || 
 ((a._i_category3558 == b._i_category3558) && (a._i_class3559 == b._i_class3559) && (a._i_brand3560 == b._i_brand3560) && (a._i_product_name3561 == b._i_product_name3561) && (a._d_year3562 == b._d_year3562) && (a._d_qoy3563 == b._d_qoy3563) && (a._d_moy3564 == b._d_moy3564) && (a._s_store_id3565 < b._s_store_id3565)) || 
 ((a._i_category3558 == b._i_category3558) && (a._i_class3559 == b._i_class3559) && (a._i_brand3560 == b._i_brand3560) && (a._i_product_name3561 == b._i_product_name3561) && (a._d_year3562 == b._d_year3562) && (a._d_qoy3563 == b._d_qoy3563) && (a._d_moy3564 == b._d_moy3564) && (a._s_store_id3565 == b._s_store_id3565) && (a._sumsales3544 < b._sumsales3544)) || 
 ((a._i_category3558 == b._i_category3558) && (a._i_class3559 == b._i_class3559) && (a._i_brand3560 == b._i_brand3560) && (a._i_product_name3561 == b._i_product_name3561) && (a._d_year3562 == b._d_year3562) && (a._d_qoy3563 == b._d_qoy3563) && (a._d_moy3564 == b._d_moy3564) && (a._s_store_id3565 == b._s_store_id3565) && (a._sumsales3544 == b._sumsales3544) && (a._rk3545 < b._rk3545)); 
}
    }SW_Sort_TD_2940586_order; 

    int nrow1 = tbl_Filter_TD_3982792_output.getNumRow();
    std::vector<SW_Sort_TD_2940586Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category3558 = tbl_Filter_TD_3982792_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_class3559 = tbl_Filter_TD_3982792_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand3560 = tbl_Filter_TD_3982792_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _i_product_name3561 = tbl_Filter_TD_3982792_output.getcharN<char, TPCDS_READ_MAX +1>(i, 3);
        int32_t _d_year3562 = tbl_Filter_TD_3982792_output.getInt32(i, 4);
        int32_t _d_qoy3563 = tbl_Filter_TD_3982792_output.getInt32(i, 5);
        int32_t _d_moy3564 = tbl_Filter_TD_3982792_output.getInt32(i, 6);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_id3565 = tbl_Filter_TD_3982792_output.getcharN<char, TPCDS_READ_MAX +1>(i, 7);
        int64_t _sumsales3544 = tbl_Filter_TD_3982792_output.getInt64(i, 8);
        int32_t _rk3545 = tbl_Filter_TD_3982792_output.getInt32(i, 9);
        SW_Sort_TD_2940586Row t = {std::string(_i_category3558.data()),std::string(_i_class3559.data()),std::string(_i_brand3560.data()),std::string(_i_product_name3561.data()),_d_year3562,_d_qoy3563,_d_moy3564,std::string(_s_store_id3565.data()),_sumsales3544,_rk3545};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2940586_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category3558{};
        memcpy(_i_category3558.data(), (it._i_category3558).data(), (it._i_category3558).length());
        tbl_Sort_TD_2940586_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _i_category3558);
        std::array<char, TPCDS_READ_MAX + 1> _i_class3559{};
        memcpy(_i_class3559.data(), (it._i_class3559).data(), (it._i_class3559).length());
        tbl_Sort_TD_2940586_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _i_class3559);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand3560{};
        memcpy(_i_brand3560.data(), (it._i_brand3560).data(), (it._i_brand3560).length());
        tbl_Sort_TD_2940586_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _i_brand3560);
        std::array<char, TPCDS_READ_MAX + 1> _i_product_name3561{};
        memcpy(_i_product_name3561.data(), (it._i_product_name3561).data(), (it._i_product_name3561).length());
        tbl_Sort_TD_2940586_output.setcharN<char, TPCDS_READ_MAX +1>(r, 3, _i_product_name3561);
        tbl_Sort_TD_2940586_output.setInt32(r, 4, it._d_year3562);
        tbl_Sort_TD_2940586_output.setInt32(r, 5, it._d_qoy3563);
        tbl_Sort_TD_2940586_output.setInt32(r, 6, it._d_moy3564);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_id3565{};
        memcpy(_s_store_id3565.data(), (it._s_store_id3565).data(), (it._s_store_id3565).length());
        tbl_Sort_TD_2940586_output.setcharN<char, TPCDS_READ_MAX +1>(r, 7, _s_store_id3565);
        tbl_Sort_TD_2940586_output.setInt64(r, 8, it._sumsales3544);
        tbl_Sort_TD_2940586_output.setInt32(r, 9, it._rk3545);
        ++r;
    }
    tbl_Sort_TD_2940586_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2940586_output #Row: " << tbl_Sort_TD_2940586_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1458245(Table &tbl_Sort_TD_2940586_output, Table &tbl_LocalLimit_TD_1458245_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(i_category#3558, i_class#3559, i_brand#3560, i_product_name#3561, d_year#3562, d_qoy#3563, d_moy#3564, s_store_id#3565, sumsales#3544, rk#3545)
    // Output: ListBuffer(i_category#3558, i_class#3559, i_brand#3560, i_product_name#3561, d_year#3562, d_qoy#3563, d_moy#3564, s_store_id#3565, sumsales#3544, rk#3545)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category3558_n = tbl_Sort_TD_2940586_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1458245_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category3558_n);
        std::array<char, TPCDS_READ_MAX + 1> _i_class3559_n = tbl_Sort_TD_2940586_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_1458245_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_class3559_n);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand3560_n = tbl_Sort_TD_2940586_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_LocalLimit_TD_1458245_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_brand3560_n);
        std::array<char, TPCDS_READ_MAX + 1> _i_product_name3561_n = tbl_Sort_TD_2940586_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_LocalLimit_TD_1458245_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _i_product_name3561_n);
        tbl_LocalLimit_TD_1458245_output.setInt32(r, 4, tbl_Sort_TD_2940586_output.getInt32(i, 4));
        tbl_LocalLimit_TD_1458245_output.setInt32(r, 5, tbl_Sort_TD_2940586_output.getInt32(i, 5));
        tbl_LocalLimit_TD_1458245_output.setInt32(r, 6, tbl_Sort_TD_2940586_output.getInt32(i, 6));
        std::array<char, TPCDS_READ_MAX + 1> _s_store_id3565_n = tbl_Sort_TD_2940586_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
        tbl_LocalLimit_TD_1458245_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_store_id3565_n);
        tbl_LocalLimit_TD_1458245_output.setInt64(r, 8, tbl_Sort_TD_2940586_output.getInt64(i, 8));
        tbl_LocalLimit_TD_1458245_output.setInt32(r, 9, tbl_Sort_TD_2940586_output.getInt32(i, 9));
        r++;
    }
    tbl_LocalLimit_TD_1458245_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1458245_output #Row: " << tbl_LocalLimit_TD_1458245_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0215895(Table &tbl_LocalLimit_TD_1458245_output, Table &tbl_GlobalLimit_TD_0215895_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(i_category#3558, i_class#3559, i_brand#3560, i_product_name#3561, d_year#3562, d_qoy#3563, d_moy#3564, s_store_id#3565, sumsales#3544, rk#3545)
    // Output: ListBuffer(i_category#3558, i_class#3559, i_brand#3560, i_product_name#3561, d_year#3562, d_qoy#3563, d_moy#3564, s_store_id#3565, sumsales#3544, rk#3545)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category3558_n = tbl_LocalLimit_TD_1458245_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0215895_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category3558_n);
        std::array<char, TPCDS_READ_MAX + 1> _i_class3559_n = tbl_LocalLimit_TD_1458245_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_0215895_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_class3559_n);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand3560_n = tbl_LocalLimit_TD_1458245_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_GlobalLimit_TD_0215895_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_brand3560_n);
        std::array<char, TPCDS_READ_MAX + 1> _i_product_name3561_n = tbl_LocalLimit_TD_1458245_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_GlobalLimit_TD_0215895_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _i_product_name3561_n);
        tbl_GlobalLimit_TD_0215895_output.setInt32(r, 4, tbl_LocalLimit_TD_1458245_output.getInt32(i, 4));
        tbl_GlobalLimit_TD_0215895_output.setInt32(r, 5, tbl_LocalLimit_TD_1458245_output.getInt32(i, 5));
        tbl_GlobalLimit_TD_0215895_output.setInt32(r, 6, tbl_LocalLimit_TD_1458245_output.getInt32(i, 6));
        std::array<char, TPCDS_READ_MAX + 1> _s_store_id3565_n = tbl_LocalLimit_TD_1458245_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
        tbl_GlobalLimit_TD_0215895_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_store_id3565_n);
        tbl_GlobalLimit_TD_0215895_output.setInt64(r, 8, tbl_LocalLimit_TD_1458245_output.getInt64(i, 8));
        tbl_GlobalLimit_TD_0215895_output.setInt32(r, 9, tbl_LocalLimit_TD_1458245_output.getInt32(i, 9));
        r++;
    }
    tbl_GlobalLimit_TD_0215895_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0215895_output #Row: " << tbl_GlobalLimit_TD_0215895_output.getNumRow() << std::endl;
}

