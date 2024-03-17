#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_14434599(Table &tbl_SerializeFromObject_TD_15419224_input, Table &tbl_Filter_TD_14434599_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_item_sk#1208) AND (isnotnull(ss_sold_date_sk#1206) AND isnotnull(ss_store_sk#1213))))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_store_sk#1213, ss_sales_price#1219)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_store_sk#1213, ss_sales_price#1219)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_15419224_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_15419224_input.getInt32(i, 1);
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_15419224_input.getInt32(i, 0);
        int32_t _ss_store_sk1213 = tbl_SerializeFromObject_TD_15419224_input.getInt32(i, 2);
        if ((_ss_item_sk1208!= 0) && ((_ss_sold_date_sk1206!= 0) && (_ss_store_sk1213!= 0))) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_15419224_input.getInt32(i, 0);
            tbl_Filter_TD_14434599_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_15419224_input.getInt32(i, 1);
            tbl_Filter_TD_14434599_output.setInt32(r, 1, _ss_item_sk1208_t);
            int32_t _ss_store_sk1213_t = tbl_SerializeFromObject_TD_15419224_input.getInt32(i, 2);
            tbl_Filter_TD_14434599_output.setInt32(r, 2, _ss_store_sk1213_t);
            int64_t _ss_sales_price1219_t = tbl_SerializeFromObject_TD_15419224_input.getInt64(i, 3);
            tbl_Filter_TD_14434599_output.setInt64(r, 3, _ss_sales_price1219_t);
            r++;
        }
    }
    tbl_Filter_TD_14434599_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_14434599_output #Row: " << tbl_Filter_TD_14434599_output.getNumRow() << std::endl;
}

void SW_Filter_TD_14208171(Table &tbl_SerializeFromObject_TD_15398144_input, Table &tbl_Filter_TD_14208171_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(i_item_sk#228) AND (isnotnull(i_category#240) AND isnotnull(i_brand#236))))
    // Input: ListBuffer(i_item_sk#228, i_brand#236, i_category#240)
    // Output: ListBuffer(i_item_sk#228, i_brand#236, i_category#240)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_15398144_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_15398144_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_category240 = tbl_SerializeFromObject_TD_15398144_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236 = tbl_SerializeFromObject_TD_15398144_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_i_item_sk228!= 0) && (_i_category240.data() != "NULL" && _i_brand236.data() != "NULL")) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_15398144_input.getInt32(i, 0);
            tbl_Filter_TD_14208171_output.setInt32(r, 0, _i_item_sk228_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_t = tbl_SerializeFromObject_TD_15398144_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_14208171_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand236_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_t = tbl_SerializeFromObject_TD_15398144_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_14208171_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_category240_t);
            r++;
        }
    }
    tbl_Filter_TD_14208171_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_14208171_output #Row: " << tbl_Filter_TD_14208171_output.getNumRow() << std::endl;
}

void SW_Filter_TD_13912779(Table &tbl_SerializeFromObject_TD_14802568_input, Table &tbl_Filter_TD_13912779_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((((d_year#126 = 1999) OR ((d_year#126 = 1998) AND (d_moy#128 = 12))) OR ((d_year#126 = 2000) AND (d_moy#128 = 1))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126, d_moy#128)
    // Output: ListBuffer(d_date_sk#120, d_year#126, d_moy#128)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_14802568_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_14802568_input.getInt32(i, 1);
        int32_t _d_moy128 = tbl_SerializeFromObject_TD_14802568_input.getInt32(i, 2);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_14802568_input.getInt32(i, 0);
        if ((((_d_year126 == 1999) || ((_d_year126 == 1998) && (_d_moy128 == 12))) || ((_d_year126 == 2000) && (_d_moy128 == 1))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_14802568_input.getInt32(i, 0);
            tbl_Filter_TD_13912779_output.setInt32(r, 0, _d_date_sk120_t);
            int32_t _d_year126_t = tbl_SerializeFromObject_TD_14802568_input.getInt32(i, 1);
            tbl_Filter_TD_13912779_output.setInt32(r, 1, _d_year126_t);
            int32_t _d_moy128_t = tbl_SerializeFromObject_TD_14802568_input.getInt32(i, 2);
            tbl_Filter_TD_13912779_output.setInt32(r, 2, _d_moy128_t);
            r++;
        }
    }
    tbl_Filter_TD_13912779_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_13912779_output #Row: " << tbl_Filter_TD_13912779_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_13515608_key_leftMajor {
    int32_t _i_item_sk228;
    bool operator==(const SW_JOIN_INNER_TD_13515608_key_leftMajor& other) const {
        return ((_i_item_sk228 == other._i_item_sk228));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_13515608_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_13515608_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk228));
    }
};
}
struct SW_JOIN_INNER_TD_13515608_payload_leftMajor {
    int32_t _i_item_sk228;
    std::string _i_brand236;
    std::string _i_category240;
};
struct SW_JOIN_INNER_TD_13515608_key_rightMajor {
    int32_t _ss_item_sk1208;
    bool operator==(const SW_JOIN_INNER_TD_13515608_key_rightMajor& other) const {
        return ((_ss_item_sk1208 == other._ss_item_sk1208));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_13515608_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_13515608_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk1208));
    }
};
}
struct SW_JOIN_INNER_TD_13515608_payload_rightMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_item_sk1208;
    int32_t _ss_store_sk1213;
    int64_t _ss_sales_price1219;
};
void SW_JOIN_INNER_TD_13515608(Table &tbl_Filter_TD_14208171_output, Table &tbl_Filter_TD_14434599_output, Table &tbl_JOIN_INNER_TD_13515608_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_item_sk#1208 = i_item_sk#228))
    // Left Table: ListBuffer(i_item_sk#228, i_brand#236, i_category#240)
    // Right Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_store_sk#1213, ss_sales_price#1219)
    // Output Table: ListBuffer(i_brand#236, i_category#240, ss_sold_date_sk#1206, ss_store_sk#1213, ss_sales_price#1219)
    int left_nrow = tbl_Filter_TD_14208171_output.getNumRow();
    int right_nrow = tbl_Filter_TD_14434599_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_13515608_key_leftMajor, SW_JOIN_INNER_TD_13515608_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_14208171_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_14208171_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_13515608_key_leftMajor keyA{_i_item_sk228_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_14208171_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_Filter_TD_14208171_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand236 = std::string(_i_brand236_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_Filter_TD_14208171_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _i_category240 = std::string(_i_category240_n.data());
            SW_JOIN_INNER_TD_13515608_payload_leftMajor payloadA{_i_item_sk228, _i_brand236, _i_category240};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_14434599_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk1208_k = tbl_Filter_TD_14434599_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_13515608_key_leftMajor{_ss_item_sk1208_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                std::string _i_brand236 = (it->second)._i_brand236;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n{};
                memcpy(_i_brand236_n.data(), (_i_brand236).data(), (_i_brand236).length());
                std::string _i_category240 = (it->second)._i_category240;
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n{};
                memcpy(_i_category240_n.data(), (_i_category240).data(), (_i_category240).length());
                int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_14434599_output.getInt32(i, 0);
                int32_t _ss_item_sk1208 = tbl_Filter_TD_14434599_output.getInt32(i, 1);
                int32_t _ss_store_sk1213 = tbl_Filter_TD_14434599_output.getInt32(i, 2);
                int64_t _ss_sales_price1219 = tbl_Filter_TD_14434599_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_13515608_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand236_n);
                tbl_JOIN_INNER_TD_13515608_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category240_n);
                tbl_JOIN_INNER_TD_13515608_output.setInt32(r, 2, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_13515608_output.setInt32(r, 3, _ss_store_sk1213);
                tbl_JOIN_INNER_TD_13515608_output.setInt64(r, 4, _ss_sales_price1219);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_13515608_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_13515608_key_rightMajor, SW_JOIN_INNER_TD_13515608_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_14434599_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk1208_k = tbl_Filter_TD_14434599_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_13515608_key_rightMajor keyA{_ss_item_sk1208_k};
            int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_14434599_output.getInt32(i, 0);
            int32_t _ss_item_sk1208 = tbl_Filter_TD_14434599_output.getInt32(i, 1);
            int32_t _ss_store_sk1213 = tbl_Filter_TD_14434599_output.getInt32(i, 2);
            int64_t _ss_sales_price1219 = tbl_Filter_TD_14434599_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_13515608_payload_rightMajor payloadA{_ss_sold_date_sk1206, _ss_item_sk1208, _ss_store_sk1213, _ss_sales_price1219};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_14208171_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_14208171_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_13515608_key_rightMajor{_i_item_sk228_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_store_sk1213 = (it->second)._ss_store_sk1213;
                int64_t _ss_sales_price1219 = (it->second)._ss_sales_price1219;
                int32_t _i_item_sk228 = tbl_Filter_TD_14208171_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_Filter_TD_14208171_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_brand236 = std::string(_i_brand236_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_Filter_TD_14208171_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _i_category240 = std::string(_i_category240_n.data());
                tbl_JOIN_INNER_TD_13515608_output.setInt32(r, 2, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_13515608_output.setInt32(r, 3, _ss_store_sk1213);
                tbl_JOIN_INNER_TD_13515608_output.setInt64(r, 4, _ss_sales_price1219);
                tbl_JOIN_INNER_TD_13515608_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand236_n);
                tbl_JOIN_INNER_TD_13515608_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category240_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_13515608_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_13515608_output #Row: " << tbl_JOIN_INNER_TD_13515608_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12810859(Table &tbl_SerializeFromObject_TD_13911383_input, Table &tbl_Filter_TD_12810859_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ss_item_sk#4332) AND isnotnull(ss_sold_date_sk#4330)) AND isnotnull(ss_store_sk#4337)))
    // Input: ListBuffer(ss_sold_date_sk#4330, ss_item_sk#4332, ss_store_sk#4337, ss_sales_price#4343)
    // Output: ListBuffer(ss_sold_date_sk#4330, ss_item_sk#4332, ss_store_sk#4337, ss_sales_price#4343)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13911383_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_item_sk4332 = tbl_SerializeFromObject_TD_13911383_input.getInt32(i, 1);
        int32_t _ss_sold_date_sk4330 = tbl_SerializeFromObject_TD_13911383_input.getInt32(i, 0);
        int32_t _ss_store_sk4337 = tbl_SerializeFromObject_TD_13911383_input.getInt32(i, 2);
        if (((_ss_item_sk4332!= 0) && (_ss_sold_date_sk4330!= 0)) && (_ss_store_sk4337!= 0)) {
            int32_t _ss_sold_date_sk4330_t = tbl_SerializeFromObject_TD_13911383_input.getInt32(i, 0);
            tbl_Filter_TD_12810859_output.setInt32(r, 0, _ss_sold_date_sk4330_t);
            int32_t _ss_item_sk4332_t = tbl_SerializeFromObject_TD_13911383_input.getInt32(i, 1);
            tbl_Filter_TD_12810859_output.setInt32(r, 1, _ss_item_sk4332_t);
            int32_t _ss_store_sk4337_t = tbl_SerializeFromObject_TD_13911383_input.getInt32(i, 2);
            tbl_Filter_TD_12810859_output.setInt32(r, 2, _ss_store_sk4337_t);
            int64_t _ss_sales_price4343_t = tbl_SerializeFromObject_TD_13911383_input.getInt64(i, 3);
            tbl_Filter_TD_12810859_output.setInt64(r, 3, _ss_sales_price4343_t);
            r++;
        }
    }
    tbl_Filter_TD_12810859_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12810859_output #Row: " << tbl_Filter_TD_12810859_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12274745(Table &tbl_SerializeFromObject_TD_13534262_input, Table &tbl_Filter_TD_12274745_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(i_item_sk#4308) AND (isnotnull(i_category#4320) AND isnotnull(i_brand#4316))))
    // Input: ListBuffer(i_item_sk#4308, i_brand#4316, i_category#4320)
    // Output: ListBuffer(i_item_sk#4308, i_brand#4316, i_category#4320)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13534262_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk4308 = tbl_SerializeFromObject_TD_13534262_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_category4320 = tbl_SerializeFromObject_TD_13534262_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand4316 = tbl_SerializeFromObject_TD_13534262_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_i_item_sk4308!= 0) && (_i_category4320.data() != "NULL" && _i_brand4316.data() != "NULL")) {
            int32_t _i_item_sk4308_t = tbl_SerializeFromObject_TD_13534262_input.getInt32(i, 0);
            tbl_Filter_TD_12274745_output.setInt32(r, 0, _i_item_sk4308_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4316_t = tbl_SerializeFromObject_TD_13534262_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_12274745_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand4316_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_category4320_t = tbl_SerializeFromObject_TD_13534262_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_12274745_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_category4320_t);
            r++;
        }
    }
    tbl_Filter_TD_12274745_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12274745_output #Row: " << tbl_Filter_TD_12274745_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12735478(Table &tbl_SerializeFromObject_TD_13383862_input, Table &tbl_Filter_TD_12735478_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(s_store_sk#378) AND (isnotnull(s_store_name#383) AND isnotnull(s_company_name#395))))
    // Input: ListBuffer(s_store_sk#378, s_store_name#383, s_company_name#395)
    // Output: ListBuffer(s_store_sk#378, s_store_name#383, s_company_name#395)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13383862_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _s_store_sk378 = tbl_SerializeFromObject_TD_13383862_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383 = tbl_SerializeFromObject_TD_13383862_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _s_company_name395 = tbl_SerializeFromObject_TD_13383862_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        if ((_s_store_sk378!= 0) && (_s_store_name383.data() != "NULL" && _s_company_name395.data() != "NULL")) {
            int32_t _s_store_sk378_t = tbl_SerializeFromObject_TD_13383862_input.getInt32(i, 0);
            tbl_Filter_TD_12735478_output.setInt32(r, 0, _s_store_sk378_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_t = tbl_SerializeFromObject_TD_13383862_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_12735478_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_store_name383_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_company_name395_t = tbl_SerializeFromObject_TD_13383862_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_12735478_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_company_name395_t);
            r++;
        }
    }
    tbl_Filter_TD_12735478_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12735478_output #Row: " << tbl_Filter_TD_12735478_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_12974871_key_leftMajor {
    int32_t _ss_sold_date_sk1206;
    bool operator==(const SW_JOIN_INNER_TD_12974871_key_leftMajor& other) const {
        return ((_ss_sold_date_sk1206 == other._ss_sold_date_sk1206));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_12974871_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_12974871_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_sold_date_sk1206));
    }
};
}
struct SW_JOIN_INNER_TD_12974871_payload_leftMajor {
    std::string _i_brand236;
    std::string _i_category240;
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_store_sk1213;
    int64_t _ss_sales_price1219;
};
struct SW_JOIN_INNER_TD_12974871_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_12974871_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_12974871_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_12974871_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_12974871_payload_rightMajor {
    int32_t _d_date_sk120;
    int32_t _d_year126;
    int32_t _d_moy128;
};
void SW_JOIN_INNER_TD_12974871(Table &tbl_JOIN_INNER_TD_13515608_output, Table &tbl_Filter_TD_13912779_output, Table &tbl_JOIN_INNER_TD_12974871_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#1206 = d_date_sk#120))
    // Left Table: ListBuffer(i_brand#236, i_category#240, ss_sold_date_sk#1206, ss_store_sk#1213, ss_sales_price#1219)
    // Right Table: ListBuffer(d_date_sk#120, d_year#126, d_moy#128)
    // Output Table: ListBuffer(i_brand#236, i_category#240, ss_store_sk#1213, ss_sales_price#1219, d_year#126, d_moy#128)
    int left_nrow = tbl_JOIN_INNER_TD_13515608_output.getNumRow();
    int right_nrow = tbl_Filter_TD_13912779_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_12974871_key_leftMajor, SW_JOIN_INNER_TD_12974871_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_13515608_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_JOIN_INNER_TD_13515608_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_12974871_key_leftMajor keyA{_ss_sold_date_sk1206_k};
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_JOIN_INNER_TD_13515608_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_brand236 = std::string(_i_brand236_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_JOIN_INNER_TD_13515608_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_category240 = std::string(_i_category240_n.data());
            int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_13515608_output.getInt32(i, 2);
            int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_13515608_output.getInt32(i, 3);
            int64_t _ss_sales_price1219 = tbl_JOIN_INNER_TD_13515608_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_12974871_payload_leftMajor payloadA{_i_brand236, _i_category240, _ss_sold_date_sk1206, _ss_store_sk1213, _ss_sales_price1219};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_13912779_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_13912779_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_12974871_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _i_brand236 = (it->second)._i_brand236;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n{};
                memcpy(_i_brand236_n.data(), (_i_brand236).data(), (_i_brand236).length());
                std::string _i_category240 = (it->second)._i_category240;
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n{};
                memcpy(_i_category240_n.data(), (_i_category240).data(), (_i_category240).length());
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_store_sk1213 = (it->second)._ss_store_sk1213;
                int64_t _ss_sales_price1219 = (it->second)._ss_sales_price1219;
                int32_t _d_date_sk120 = tbl_Filter_TD_13912779_output.getInt32(i, 0);
                int32_t _d_year126 = tbl_Filter_TD_13912779_output.getInt32(i, 1);
                int32_t _d_moy128 = tbl_Filter_TD_13912779_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_12974871_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand236_n);
                tbl_JOIN_INNER_TD_12974871_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category240_n);
                tbl_JOIN_INNER_TD_12974871_output.setInt32(r, 2, _ss_store_sk1213);
                tbl_JOIN_INNER_TD_12974871_output.setInt64(r, 3, _ss_sales_price1219);
                tbl_JOIN_INNER_TD_12974871_output.setInt32(r, 4, _d_year126);
                tbl_JOIN_INNER_TD_12974871_output.setInt32(r, 5, _d_moy128);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_12974871_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_12974871_key_rightMajor, SW_JOIN_INNER_TD_12974871_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_13912779_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_13912779_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_12974871_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_13912779_output.getInt32(i, 0);
            int32_t _d_year126 = tbl_Filter_TD_13912779_output.getInt32(i, 1);
            int32_t _d_moy128 = tbl_Filter_TD_13912779_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_12974871_payload_rightMajor payloadA{_d_date_sk120, _d_year126, _d_moy128};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_13515608_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_JOIN_INNER_TD_13515608_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_12974871_key_rightMajor{_ss_sold_date_sk1206_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _d_year126 = (it->second)._d_year126;
                int32_t _d_moy128 = (it->second)._d_moy128;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_JOIN_INNER_TD_13515608_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _i_brand236 = std::string(_i_brand236_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_JOIN_INNER_TD_13515608_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_category240 = std::string(_i_category240_n.data());
                int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_13515608_output.getInt32(i, 2);
                int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_13515608_output.getInt32(i, 3);
                int64_t _ss_sales_price1219 = tbl_JOIN_INNER_TD_13515608_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_12974871_output.setInt32(r, 4, _d_year126);
                tbl_JOIN_INNER_TD_12974871_output.setInt32(r, 5, _d_moy128);
                tbl_JOIN_INNER_TD_12974871_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand236_n);
                tbl_JOIN_INNER_TD_12974871_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category240_n);
                tbl_JOIN_INNER_TD_12974871_output.setInt32(r, 2, _ss_store_sk1213);
                tbl_JOIN_INNER_TD_12974871_output.setInt64(r, 3, _ss_sales_price1219);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_12974871_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_12974871_output #Row: " << tbl_JOIN_INNER_TD_12974871_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11987487(Table &tbl_SerializeFromObject_TD_12430691_input, Table &tbl_Filter_TD_11987487_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ss_item_sk#4439) AND isnotnull(ss_sold_date_sk#4437)) AND isnotnull(ss_store_sk#4444)))
    // Input: ListBuffer(ss_sold_date_sk#4437, ss_item_sk#4439, ss_store_sk#4444, ss_sales_price#4450)
    // Output: ListBuffer(ss_sold_date_sk#4437, ss_item_sk#4439, ss_store_sk#4444, ss_sales_price#4450)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12430691_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_item_sk4439 = tbl_SerializeFromObject_TD_12430691_input.getInt32(i, 1);
        int32_t _ss_sold_date_sk4437 = tbl_SerializeFromObject_TD_12430691_input.getInt32(i, 0);
        int32_t _ss_store_sk4444 = tbl_SerializeFromObject_TD_12430691_input.getInt32(i, 2);
        if (((_ss_item_sk4439!= 0) && (_ss_sold_date_sk4437!= 0)) && (_ss_store_sk4444!= 0)) {
            int32_t _ss_sold_date_sk4437_t = tbl_SerializeFromObject_TD_12430691_input.getInt32(i, 0);
            tbl_Filter_TD_11987487_output.setInt32(r, 0, _ss_sold_date_sk4437_t);
            int32_t _ss_item_sk4439_t = tbl_SerializeFromObject_TD_12430691_input.getInt32(i, 1);
            tbl_Filter_TD_11987487_output.setInt32(r, 1, _ss_item_sk4439_t);
            int32_t _ss_store_sk4444_t = tbl_SerializeFromObject_TD_12430691_input.getInt32(i, 2);
            tbl_Filter_TD_11987487_output.setInt32(r, 2, _ss_store_sk4444_t);
            int64_t _ss_sales_price4450_t = tbl_SerializeFromObject_TD_12430691_input.getInt64(i, 3);
            tbl_Filter_TD_11987487_output.setInt64(r, 3, _ss_sales_price4450_t);
            r++;
        }
    }
    tbl_Filter_TD_11987487_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11987487_output #Row: " << tbl_Filter_TD_11987487_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11686420(Table &tbl_SerializeFromObject_TD_12145072_input, Table &tbl_Filter_TD_11686420_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(i_item_sk#4415) AND (isnotnull(i_category#4427) AND isnotnull(i_brand#4423))))
    // Input: ListBuffer(i_item_sk#4415, i_brand#4423, i_category#4427)
    // Output: ListBuffer(i_item_sk#4415, i_brand#4423, i_category#4427)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12145072_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk4415 = tbl_SerializeFromObject_TD_12145072_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_category4427 = tbl_SerializeFromObject_TD_12145072_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand4423 = tbl_SerializeFromObject_TD_12145072_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_i_item_sk4415!= 0) && (_i_category4427.data() != "NULL" && _i_brand4423.data() != "NULL")) {
            int32_t _i_item_sk4415_t = tbl_SerializeFromObject_TD_12145072_input.getInt32(i, 0);
            tbl_Filter_TD_11686420_output.setInt32(r, 0, _i_item_sk4415_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4423_t = tbl_SerializeFromObject_TD_12145072_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_11686420_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand4423_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_category4427_t = tbl_SerializeFromObject_TD_12145072_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_11686420_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_category4427_t);
            r++;
        }
    }
    tbl_Filter_TD_11686420_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11686420_output #Row: " << tbl_Filter_TD_11686420_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11848688(Table &tbl_SerializeFromObject_TD_1212713_input, Table &tbl_Filter_TD_11848688_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((((d_year#4359 = 1999) OR ((d_year#4359 = 1998) AND (d_moy#4361 = 12))) OR ((d_year#4359 = 2000) AND (d_moy#4361 = 1))) AND isnotnull(d_date_sk#4353)))
    // Input: ListBuffer(d_date_sk#4353, d_year#4359, d_moy#4361)
    // Output: ListBuffer(d_date_sk#4353, d_year#4359, d_moy#4361)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1212713_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year4359 = tbl_SerializeFromObject_TD_1212713_input.getInt32(i, 1);
        int32_t _d_moy4361 = tbl_SerializeFromObject_TD_1212713_input.getInt32(i, 2);
        int32_t _d_date_sk4353 = tbl_SerializeFromObject_TD_1212713_input.getInt32(i, 0);
        if ((((_d_year4359 == 1999) || ((_d_year4359 == 1998) && (_d_moy4361 == 12))) || ((_d_year4359 == 2000) && (_d_moy4361 == 1))) && (_d_date_sk4353!= 0)) {
            int32_t _d_date_sk4353_t = tbl_SerializeFromObject_TD_1212713_input.getInt32(i, 0);
            tbl_Filter_TD_11848688_output.setInt32(r, 0, _d_date_sk4353_t);
            int32_t _d_year4359_t = tbl_SerializeFromObject_TD_1212713_input.getInt32(i, 1);
            tbl_Filter_TD_11848688_output.setInt32(r, 1, _d_year4359_t);
            int32_t _d_moy4361_t = tbl_SerializeFromObject_TD_1212713_input.getInt32(i, 2);
            tbl_Filter_TD_11848688_output.setInt32(r, 2, _d_moy4361_t);
            r++;
        }
    }
    tbl_Filter_TD_11848688_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11848688_output #Row: " << tbl_Filter_TD_11848688_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_11650222_key_leftMajor {
    int32_t _i_item_sk4308;
    bool operator==(const SW_JOIN_INNER_TD_11650222_key_leftMajor& other) const {
        return ((_i_item_sk4308 == other._i_item_sk4308));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11650222_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11650222_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk4308));
    }
};
}
struct SW_JOIN_INNER_TD_11650222_payload_leftMajor {
    int32_t _i_item_sk4308;
    std::string _i_brand4316;
    std::string _i_category4320;
};
struct SW_JOIN_INNER_TD_11650222_key_rightMajor {
    int32_t _ss_item_sk4332;
    bool operator==(const SW_JOIN_INNER_TD_11650222_key_rightMajor& other) const {
        return ((_ss_item_sk4332 == other._ss_item_sk4332));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11650222_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11650222_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk4332));
    }
};
}
struct SW_JOIN_INNER_TD_11650222_payload_rightMajor {
    int32_t _ss_sold_date_sk4330;
    int32_t _ss_item_sk4332;
    int32_t _ss_store_sk4337;
    int64_t _ss_sales_price4343;
};
void SW_JOIN_INNER_TD_11650222(Table &tbl_Filter_TD_12274745_output, Table &tbl_Filter_TD_12810859_output, Table &tbl_JOIN_INNER_TD_11650222_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_item_sk#4332 = i_item_sk#4308))
    // Left Table: ListBuffer(i_item_sk#4308, i_brand#4316, i_category#4320)
    // Right Table: ListBuffer(ss_sold_date_sk#4330, ss_item_sk#4332, ss_store_sk#4337, ss_sales_price#4343)
    // Output Table: ListBuffer(i_brand#4316, i_category#4320, ss_sold_date_sk#4330, ss_store_sk#4337, ss_sales_price#4343)
    int left_nrow = tbl_Filter_TD_12274745_output.getNumRow();
    int right_nrow = tbl_Filter_TD_12810859_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11650222_key_leftMajor, SW_JOIN_INNER_TD_11650222_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_12274745_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk4308_k = tbl_Filter_TD_12274745_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_11650222_key_leftMajor keyA{_i_item_sk4308_k};
            int32_t _i_item_sk4308 = tbl_Filter_TD_12274745_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4316_n = tbl_Filter_TD_12274745_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand4316 = std::string(_i_brand4316_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_category4320_n = tbl_Filter_TD_12274745_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _i_category4320 = std::string(_i_category4320_n.data());
            SW_JOIN_INNER_TD_11650222_payload_leftMajor payloadA{_i_item_sk4308, _i_brand4316, _i_category4320};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_12810859_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk4332_k = tbl_Filter_TD_12810859_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11650222_key_leftMajor{_ss_item_sk4332_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk4308 = (it->second)._i_item_sk4308;
                std::string _i_brand4316 = (it->second)._i_brand4316;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4316_n{};
                memcpy(_i_brand4316_n.data(), (_i_brand4316).data(), (_i_brand4316).length());
                std::string _i_category4320 = (it->second)._i_category4320;
                std::array<char, TPCDS_READ_MAX + 1> _i_category4320_n{};
                memcpy(_i_category4320_n.data(), (_i_category4320).data(), (_i_category4320).length());
                int32_t _ss_sold_date_sk4330 = tbl_Filter_TD_12810859_output.getInt32(i, 0);
                int32_t _ss_item_sk4332 = tbl_Filter_TD_12810859_output.getInt32(i, 1);
                int32_t _ss_store_sk4337 = tbl_Filter_TD_12810859_output.getInt32(i, 2);
                int64_t _ss_sales_price4343 = tbl_Filter_TD_12810859_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_11650222_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand4316_n);
                tbl_JOIN_INNER_TD_11650222_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category4320_n);
                tbl_JOIN_INNER_TD_11650222_output.setInt32(r, 2, _ss_sold_date_sk4330);
                tbl_JOIN_INNER_TD_11650222_output.setInt32(r, 3, _ss_store_sk4337);
                tbl_JOIN_INNER_TD_11650222_output.setInt64(r, 4, _ss_sales_price4343);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11650222_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11650222_key_rightMajor, SW_JOIN_INNER_TD_11650222_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_12810859_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk4332_k = tbl_Filter_TD_12810859_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_11650222_key_rightMajor keyA{_ss_item_sk4332_k};
            int32_t _ss_sold_date_sk4330 = tbl_Filter_TD_12810859_output.getInt32(i, 0);
            int32_t _ss_item_sk4332 = tbl_Filter_TD_12810859_output.getInt32(i, 1);
            int32_t _ss_store_sk4337 = tbl_Filter_TD_12810859_output.getInt32(i, 2);
            int64_t _ss_sales_price4343 = tbl_Filter_TD_12810859_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_11650222_payload_rightMajor payloadA{_ss_sold_date_sk4330, _ss_item_sk4332, _ss_store_sk4337, _ss_sales_price4343};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_12274745_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk4308_k = tbl_Filter_TD_12274745_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11650222_key_rightMajor{_i_item_sk4308_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk4330 = (it->second)._ss_sold_date_sk4330;
                int32_t _ss_item_sk4332 = (it->second)._ss_item_sk4332;
                int32_t _ss_store_sk4337 = (it->second)._ss_store_sk4337;
                int64_t _ss_sales_price4343 = (it->second)._ss_sales_price4343;
                int32_t _i_item_sk4308 = tbl_Filter_TD_12274745_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4316_n = tbl_Filter_TD_12274745_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_brand4316 = std::string(_i_brand4316_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_category4320_n = tbl_Filter_TD_12274745_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _i_category4320 = std::string(_i_category4320_n.data());
                tbl_JOIN_INNER_TD_11650222_output.setInt32(r, 2, _ss_sold_date_sk4330);
                tbl_JOIN_INNER_TD_11650222_output.setInt32(r, 3, _ss_store_sk4337);
                tbl_JOIN_INNER_TD_11650222_output.setInt64(r, 4, _ss_sales_price4343);
                tbl_JOIN_INNER_TD_11650222_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand4316_n);
                tbl_JOIN_INNER_TD_11650222_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category4320_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11650222_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_11650222_output #Row: " << tbl_JOIN_INNER_TD_11650222_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_11976272_key_leftMajor {
    int32_t _ss_store_sk1213;
    bool operator==(const SW_JOIN_INNER_TD_11976272_key_leftMajor& other) const {
        return ((_ss_store_sk1213 == other._ss_store_sk1213));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11976272_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11976272_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_store_sk1213));
    }
};
}
struct SW_JOIN_INNER_TD_11976272_payload_leftMajor {
    std::string _i_brand236;
    std::string _i_category240;
    int32_t _ss_store_sk1213;
    int64_t _ss_sales_price1219;
    int32_t _d_year126;
    int32_t _d_moy128;
};
struct SW_JOIN_INNER_TD_11976272_key_rightMajor {
    int32_t _s_store_sk378;
    bool operator==(const SW_JOIN_INNER_TD_11976272_key_rightMajor& other) const {
        return ((_s_store_sk378 == other._s_store_sk378));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11976272_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11976272_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_store_sk378));
    }
};
}
struct SW_JOIN_INNER_TD_11976272_payload_rightMajor {
    int32_t _s_store_sk378;
    std::string _s_store_name383;
    std::string _s_company_name395;
};
void SW_JOIN_INNER_TD_11976272(Table &tbl_JOIN_INNER_TD_12974871_output, Table &tbl_Filter_TD_12735478_output, Table &tbl_JOIN_INNER_TD_11976272_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_store_sk#1213 = s_store_sk#378))
    // Left Table: ListBuffer(i_brand#236, i_category#240, ss_store_sk#1213, ss_sales_price#1219, d_year#126, d_moy#128)
    // Right Table: ListBuffer(s_store_sk#378, s_store_name#383, s_company_name#395)
    // Output Table: ListBuffer(i_brand#236, i_category#240, ss_sales_price#1219, d_year#126, d_moy#128, s_store_name#383, s_company_name#395)
    int left_nrow = tbl_JOIN_INNER_TD_12974871_output.getNumRow();
    int right_nrow = tbl_Filter_TD_12735478_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11976272_key_leftMajor, SW_JOIN_INNER_TD_11976272_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_12974871_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_store_sk1213_k = tbl_JOIN_INNER_TD_12974871_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_11976272_key_leftMajor keyA{_ss_store_sk1213_k};
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_JOIN_INNER_TD_12974871_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_brand236 = std::string(_i_brand236_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_JOIN_INNER_TD_12974871_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_category240 = std::string(_i_category240_n.data());
            int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_12974871_output.getInt32(i, 2);
            int64_t _ss_sales_price1219 = tbl_JOIN_INNER_TD_12974871_output.getInt64(i, 3);
            int32_t _d_year126 = tbl_JOIN_INNER_TD_12974871_output.getInt32(i, 4);
            int32_t _d_moy128 = tbl_JOIN_INNER_TD_12974871_output.getInt32(i, 5);
            SW_JOIN_INNER_TD_11976272_payload_leftMajor payloadA{_i_brand236, _i_category240, _ss_store_sk1213, _ss_sales_price1219, _d_year126, _d_moy128};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_12735478_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_12735478_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11976272_key_leftMajor{_s_store_sk378_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _i_brand236 = (it->second)._i_brand236;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n{};
                memcpy(_i_brand236_n.data(), (_i_brand236).data(), (_i_brand236).length());
                std::string _i_category240 = (it->second)._i_category240;
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n{};
                memcpy(_i_category240_n.data(), (_i_category240).data(), (_i_category240).length());
                int32_t _ss_store_sk1213 = (it->second)._ss_store_sk1213;
                int64_t _ss_sales_price1219 = (it->second)._ss_sales_price1219;
                int32_t _d_year126 = (it->second)._d_year126;
                int32_t _d_moy128 = (it->second)._d_moy128;
                int32_t _s_store_sk378 = tbl_Filter_TD_12735478_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_Filter_TD_12735478_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _s_store_name383 = std::string(_s_store_name383_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_company_name395_n = tbl_Filter_TD_12735478_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _s_company_name395 = std::string(_s_company_name395_n.data());
                tbl_JOIN_INNER_TD_11976272_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand236_n);
                tbl_JOIN_INNER_TD_11976272_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category240_n);
                tbl_JOIN_INNER_TD_11976272_output.setInt64(r, 2, _ss_sales_price1219);
                tbl_JOIN_INNER_TD_11976272_output.setInt32(r, 3, _d_year126);
                tbl_JOIN_INNER_TD_11976272_output.setInt32(r, 4, _d_moy128);
                tbl_JOIN_INNER_TD_11976272_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_store_name383_n);
                tbl_JOIN_INNER_TD_11976272_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_company_name395_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11976272_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11976272_key_rightMajor, SW_JOIN_INNER_TD_11976272_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_12735478_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_12735478_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_11976272_key_rightMajor keyA{_s_store_sk378_k};
            int32_t _s_store_sk378 = tbl_Filter_TD_12735478_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_Filter_TD_12735478_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _s_store_name383 = std::string(_s_store_name383_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_company_name395_n = tbl_Filter_TD_12735478_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _s_company_name395 = std::string(_s_company_name395_n.data());
            SW_JOIN_INNER_TD_11976272_payload_rightMajor payloadA{_s_store_sk378, _s_store_name383, _s_company_name395};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_12974871_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_store_sk1213_k = tbl_JOIN_INNER_TD_12974871_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11976272_key_rightMajor{_ss_store_sk1213_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _s_store_sk378 = (it->second)._s_store_sk378;
                std::string _s_store_name383 = (it->second)._s_store_name383;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n{};
                memcpy(_s_store_name383_n.data(), (_s_store_name383).data(), (_s_store_name383).length());
                std::string _s_company_name395 = (it->second)._s_company_name395;
                std::array<char, TPCDS_READ_MAX + 1> _s_company_name395_n{};
                memcpy(_s_company_name395_n.data(), (_s_company_name395).data(), (_s_company_name395).length());
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_JOIN_INNER_TD_12974871_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _i_brand236 = std::string(_i_brand236_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_JOIN_INNER_TD_12974871_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_category240 = std::string(_i_category240_n.data());
                int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_12974871_output.getInt32(i, 2);
                int64_t _ss_sales_price1219 = tbl_JOIN_INNER_TD_12974871_output.getInt64(i, 3);
                int32_t _d_year126 = tbl_JOIN_INNER_TD_12974871_output.getInt32(i, 4);
                int32_t _d_moy128 = tbl_JOIN_INNER_TD_12974871_output.getInt32(i, 5);
                tbl_JOIN_INNER_TD_11976272_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_store_name383_n);
                tbl_JOIN_INNER_TD_11976272_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_company_name395_n);
                tbl_JOIN_INNER_TD_11976272_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand236_n);
                tbl_JOIN_INNER_TD_11976272_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category240_n);
                tbl_JOIN_INNER_TD_11976272_output.setInt64(r, 2, _ss_sales_price1219);
                tbl_JOIN_INNER_TD_11976272_output.setInt32(r, 3, _d_year126);
                tbl_JOIN_INNER_TD_11976272_output.setInt32(r, 4, _d_moy128);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11976272_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_11976272_output #Row: " << tbl_JOIN_INNER_TD_11976272_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10754913(Table &tbl_SerializeFromObject_TD_11779885_input, Table &tbl_Filter_TD_10754913_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((((d_year#4466 = 1999) OR ((d_year#4466 = 1998) AND (d_moy#4468 = 12))) OR ((d_year#4466 = 2000) AND (d_moy#4468 = 1))) AND isnotnull(d_date_sk#4460)))
    // Input: ListBuffer(d_date_sk#4460, d_year#4466, d_moy#4468)
    // Output: ListBuffer(d_date_sk#4460, d_year#4466, d_moy#4468)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11779885_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year4466 = tbl_SerializeFromObject_TD_11779885_input.getInt32(i, 1);
        int32_t _d_moy4468 = tbl_SerializeFromObject_TD_11779885_input.getInt32(i, 2);
        int32_t _d_date_sk4460 = tbl_SerializeFromObject_TD_11779885_input.getInt32(i, 0);
        if ((((_d_year4466 == 1999) || ((_d_year4466 == 1998) && (_d_moy4468 == 12))) || ((_d_year4466 == 2000) && (_d_moy4468 == 1))) && (_d_date_sk4460!= 0)) {
            int32_t _d_date_sk4460_t = tbl_SerializeFromObject_TD_11779885_input.getInt32(i, 0);
            tbl_Filter_TD_10754913_output.setInt32(r, 0, _d_date_sk4460_t);
            int32_t _d_year4466_t = tbl_SerializeFromObject_TD_11779885_input.getInt32(i, 1);
            tbl_Filter_TD_10754913_output.setInt32(r, 1, _d_year4466_t);
            int32_t _d_moy4468_t = tbl_SerializeFromObject_TD_11779885_input.getInt32(i, 2);
            tbl_Filter_TD_10754913_output.setInt32(r, 2, _d_moy4468_t);
            r++;
        }
    }
    tbl_Filter_TD_10754913_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10754913_output #Row: " << tbl_Filter_TD_10754913_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_10575406_key_leftMajor {
    int32_t _i_item_sk4415;
    bool operator==(const SW_JOIN_INNER_TD_10575406_key_leftMajor& other) const {
        return ((_i_item_sk4415 == other._i_item_sk4415));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10575406_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10575406_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk4415));
    }
};
}
struct SW_JOIN_INNER_TD_10575406_payload_leftMajor {
    int32_t _i_item_sk4415;
    std::string _i_brand4423;
    std::string _i_category4427;
};
struct SW_JOIN_INNER_TD_10575406_key_rightMajor {
    int32_t _ss_item_sk4439;
    bool operator==(const SW_JOIN_INNER_TD_10575406_key_rightMajor& other) const {
        return ((_ss_item_sk4439 == other._ss_item_sk4439));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10575406_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10575406_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk4439));
    }
};
}
struct SW_JOIN_INNER_TD_10575406_payload_rightMajor {
    int32_t _ss_sold_date_sk4437;
    int32_t _ss_item_sk4439;
    int32_t _ss_store_sk4444;
    int64_t _ss_sales_price4450;
};
void SW_JOIN_INNER_TD_10575406(Table &tbl_Filter_TD_11686420_output, Table &tbl_Filter_TD_11987487_output, Table &tbl_JOIN_INNER_TD_10575406_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_item_sk#4439 = i_item_sk#4415))
    // Left Table: ListBuffer(i_item_sk#4415, i_brand#4423, i_category#4427)
    // Right Table: ListBuffer(ss_sold_date_sk#4437, ss_item_sk#4439, ss_store_sk#4444, ss_sales_price#4450)
    // Output Table: ListBuffer(i_brand#4423, i_category#4427, ss_sold_date_sk#4437, ss_store_sk#4444, ss_sales_price#4450)
    int left_nrow = tbl_Filter_TD_11686420_output.getNumRow();
    int right_nrow = tbl_Filter_TD_11987487_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10575406_key_leftMajor, SW_JOIN_INNER_TD_10575406_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_11686420_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk4415_k = tbl_Filter_TD_11686420_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_10575406_key_leftMajor keyA{_i_item_sk4415_k};
            int32_t _i_item_sk4415 = tbl_Filter_TD_11686420_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4423_n = tbl_Filter_TD_11686420_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand4423 = std::string(_i_brand4423_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_category4427_n = tbl_Filter_TD_11686420_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _i_category4427 = std::string(_i_category4427_n.data());
            SW_JOIN_INNER_TD_10575406_payload_leftMajor payloadA{_i_item_sk4415, _i_brand4423, _i_category4427};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_11987487_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk4439_k = tbl_Filter_TD_11987487_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10575406_key_leftMajor{_ss_item_sk4439_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk4415 = (it->second)._i_item_sk4415;
                std::string _i_brand4423 = (it->second)._i_brand4423;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4423_n{};
                memcpy(_i_brand4423_n.data(), (_i_brand4423).data(), (_i_brand4423).length());
                std::string _i_category4427 = (it->second)._i_category4427;
                std::array<char, TPCDS_READ_MAX + 1> _i_category4427_n{};
                memcpy(_i_category4427_n.data(), (_i_category4427).data(), (_i_category4427).length());
                int32_t _ss_sold_date_sk4437 = tbl_Filter_TD_11987487_output.getInt32(i, 0);
                int32_t _ss_item_sk4439 = tbl_Filter_TD_11987487_output.getInt32(i, 1);
                int32_t _ss_store_sk4444 = tbl_Filter_TD_11987487_output.getInt32(i, 2);
                int64_t _ss_sales_price4450 = tbl_Filter_TD_11987487_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_10575406_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand4423_n);
                tbl_JOIN_INNER_TD_10575406_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category4427_n);
                tbl_JOIN_INNER_TD_10575406_output.setInt32(r, 2, _ss_sold_date_sk4437);
                tbl_JOIN_INNER_TD_10575406_output.setInt32(r, 3, _ss_store_sk4444);
                tbl_JOIN_INNER_TD_10575406_output.setInt64(r, 4, _ss_sales_price4450);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10575406_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10575406_key_rightMajor, SW_JOIN_INNER_TD_10575406_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_11987487_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk4439_k = tbl_Filter_TD_11987487_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_10575406_key_rightMajor keyA{_ss_item_sk4439_k};
            int32_t _ss_sold_date_sk4437 = tbl_Filter_TD_11987487_output.getInt32(i, 0);
            int32_t _ss_item_sk4439 = tbl_Filter_TD_11987487_output.getInt32(i, 1);
            int32_t _ss_store_sk4444 = tbl_Filter_TD_11987487_output.getInt32(i, 2);
            int64_t _ss_sales_price4450 = tbl_Filter_TD_11987487_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_10575406_payload_rightMajor payloadA{_ss_sold_date_sk4437, _ss_item_sk4439, _ss_store_sk4444, _ss_sales_price4450};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_11686420_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk4415_k = tbl_Filter_TD_11686420_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10575406_key_rightMajor{_i_item_sk4415_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk4437 = (it->second)._ss_sold_date_sk4437;
                int32_t _ss_item_sk4439 = (it->second)._ss_item_sk4439;
                int32_t _ss_store_sk4444 = (it->second)._ss_store_sk4444;
                int64_t _ss_sales_price4450 = (it->second)._ss_sales_price4450;
                int32_t _i_item_sk4415 = tbl_Filter_TD_11686420_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4423_n = tbl_Filter_TD_11686420_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_brand4423 = std::string(_i_brand4423_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_category4427_n = tbl_Filter_TD_11686420_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _i_category4427 = std::string(_i_category4427_n.data());
                tbl_JOIN_INNER_TD_10575406_output.setInt32(r, 2, _ss_sold_date_sk4437);
                tbl_JOIN_INNER_TD_10575406_output.setInt32(r, 3, _ss_store_sk4444);
                tbl_JOIN_INNER_TD_10575406_output.setInt64(r, 4, _ss_sales_price4450);
                tbl_JOIN_INNER_TD_10575406_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand4423_n);
                tbl_JOIN_INNER_TD_10575406_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category4427_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10575406_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_10575406_output #Row: " << tbl_JOIN_INNER_TD_10575406_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10808472(Table &tbl_SerializeFromObject_TD_11511324_input, Table &tbl_Filter_TD_10808472_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(s_store_sk#4381) AND (isnotnull(s_store_name#4386) AND isnotnull(s_company_name#4398))))
    // Input: ListBuffer(s_store_sk#4381, s_store_name#4386, s_company_name#4398)
    // Output: ListBuffer(s_store_sk#4381, s_store_name#4386, s_company_name#4398)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11511324_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _s_store_sk4381 = tbl_SerializeFromObject_TD_11511324_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name4386 = tbl_SerializeFromObject_TD_11511324_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _s_company_name4398 = tbl_SerializeFromObject_TD_11511324_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        if ((_s_store_sk4381!= 0) && (_s_store_name4386.data() != "NULL" && _s_company_name4398.data() != "NULL")) {
            int32_t _s_store_sk4381_t = tbl_SerializeFromObject_TD_11511324_input.getInt32(i, 0);
            tbl_Filter_TD_10808472_output.setInt32(r, 0, _s_store_sk4381_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name4386_t = tbl_SerializeFromObject_TD_11511324_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_10808472_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_store_name4386_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_company_name4398_t = tbl_SerializeFromObject_TD_11511324_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_10808472_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_company_name4398_t);
            r++;
        }
    }
    tbl_Filter_TD_10808472_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10808472_output #Row: " << tbl_Filter_TD_10808472_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_10880607_key_leftMajor {
    int32_t _ss_sold_date_sk4330;
    bool operator==(const SW_JOIN_INNER_TD_10880607_key_leftMajor& other) const {
        return ((_ss_sold_date_sk4330 == other._ss_sold_date_sk4330));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10880607_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10880607_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_sold_date_sk4330));
    }
};
}
struct SW_JOIN_INNER_TD_10880607_payload_leftMajor {
    std::string _i_brand4316;
    std::string _i_category4320;
    int32_t _ss_sold_date_sk4330;
    int32_t _ss_store_sk4337;
    int64_t _ss_sales_price4343;
};
struct SW_JOIN_INNER_TD_10880607_key_rightMajor {
    int32_t _d_date_sk4353;
    bool operator==(const SW_JOIN_INNER_TD_10880607_key_rightMajor& other) const {
        return ((_d_date_sk4353 == other._d_date_sk4353));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10880607_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10880607_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk4353));
    }
};
}
struct SW_JOIN_INNER_TD_10880607_payload_rightMajor {
    int32_t _d_date_sk4353;
    int32_t _d_year4359;
    int32_t _d_moy4361;
};
void SW_JOIN_INNER_TD_10880607(Table &tbl_JOIN_INNER_TD_11650222_output, Table &tbl_Filter_TD_11848688_output, Table &tbl_JOIN_INNER_TD_10880607_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#4330 = d_date_sk#4353))
    // Left Table: ListBuffer(i_brand#4316, i_category#4320, ss_sold_date_sk#4330, ss_store_sk#4337, ss_sales_price#4343)
    // Right Table: ListBuffer(d_date_sk#4353, d_year#4359, d_moy#4361)
    // Output Table: ListBuffer(i_brand#4316, i_category#4320, ss_store_sk#4337, ss_sales_price#4343, d_year#4359, d_moy#4361)
    int left_nrow = tbl_JOIN_INNER_TD_11650222_output.getNumRow();
    int right_nrow = tbl_Filter_TD_11848688_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10880607_key_leftMajor, SW_JOIN_INNER_TD_10880607_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_11650222_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_sold_date_sk4330_k = tbl_JOIN_INNER_TD_11650222_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_10880607_key_leftMajor keyA{_ss_sold_date_sk4330_k};
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4316_n = tbl_JOIN_INNER_TD_11650222_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_brand4316 = std::string(_i_brand4316_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_category4320_n = tbl_JOIN_INNER_TD_11650222_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_category4320 = std::string(_i_category4320_n.data());
            int32_t _ss_sold_date_sk4330 = tbl_JOIN_INNER_TD_11650222_output.getInt32(i, 2);
            int32_t _ss_store_sk4337 = tbl_JOIN_INNER_TD_11650222_output.getInt32(i, 3);
            int64_t _ss_sales_price4343 = tbl_JOIN_INNER_TD_11650222_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_10880607_payload_leftMajor payloadA{_i_brand4316, _i_category4320, _ss_sold_date_sk4330, _ss_store_sk4337, _ss_sales_price4343};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_11848688_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk4353_k = tbl_Filter_TD_11848688_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10880607_key_leftMajor{_d_date_sk4353_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _i_brand4316 = (it->second)._i_brand4316;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4316_n{};
                memcpy(_i_brand4316_n.data(), (_i_brand4316).data(), (_i_brand4316).length());
                std::string _i_category4320 = (it->second)._i_category4320;
                std::array<char, TPCDS_READ_MAX + 1> _i_category4320_n{};
                memcpy(_i_category4320_n.data(), (_i_category4320).data(), (_i_category4320).length());
                int32_t _ss_sold_date_sk4330 = (it->second)._ss_sold_date_sk4330;
                int32_t _ss_store_sk4337 = (it->second)._ss_store_sk4337;
                int64_t _ss_sales_price4343 = (it->second)._ss_sales_price4343;
                int32_t _d_date_sk4353 = tbl_Filter_TD_11848688_output.getInt32(i, 0);
                int32_t _d_year4359 = tbl_Filter_TD_11848688_output.getInt32(i, 1);
                int32_t _d_moy4361 = tbl_Filter_TD_11848688_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_10880607_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand4316_n);
                tbl_JOIN_INNER_TD_10880607_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category4320_n);
                tbl_JOIN_INNER_TD_10880607_output.setInt32(r, 2, _ss_store_sk4337);
                tbl_JOIN_INNER_TD_10880607_output.setInt64(r, 3, _ss_sales_price4343);
                tbl_JOIN_INNER_TD_10880607_output.setInt32(r, 4, _d_year4359);
                tbl_JOIN_INNER_TD_10880607_output.setInt32(r, 5, _d_moy4361);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10880607_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10880607_key_rightMajor, SW_JOIN_INNER_TD_10880607_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_11848688_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk4353_k = tbl_Filter_TD_11848688_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_10880607_key_rightMajor keyA{_d_date_sk4353_k};
            int32_t _d_date_sk4353 = tbl_Filter_TD_11848688_output.getInt32(i, 0);
            int32_t _d_year4359 = tbl_Filter_TD_11848688_output.getInt32(i, 1);
            int32_t _d_moy4361 = tbl_Filter_TD_11848688_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_10880607_payload_rightMajor payloadA{_d_date_sk4353, _d_year4359, _d_moy4361};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_11650222_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_sold_date_sk4330_k = tbl_JOIN_INNER_TD_11650222_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10880607_key_rightMajor{_ss_sold_date_sk4330_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk4353 = (it->second)._d_date_sk4353;
                int32_t _d_year4359 = (it->second)._d_year4359;
                int32_t _d_moy4361 = (it->second)._d_moy4361;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4316_n = tbl_JOIN_INNER_TD_11650222_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _i_brand4316 = std::string(_i_brand4316_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_category4320_n = tbl_JOIN_INNER_TD_11650222_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_category4320 = std::string(_i_category4320_n.data());
                int32_t _ss_sold_date_sk4330 = tbl_JOIN_INNER_TD_11650222_output.getInt32(i, 2);
                int32_t _ss_store_sk4337 = tbl_JOIN_INNER_TD_11650222_output.getInt32(i, 3);
                int64_t _ss_sales_price4343 = tbl_JOIN_INNER_TD_11650222_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_10880607_output.setInt32(r, 4, _d_year4359);
                tbl_JOIN_INNER_TD_10880607_output.setInt32(r, 5, _d_moy4361);
                tbl_JOIN_INNER_TD_10880607_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand4316_n);
                tbl_JOIN_INNER_TD_10880607_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category4320_n);
                tbl_JOIN_INNER_TD_10880607_output.setInt32(r, 2, _ss_store_sk4337);
                tbl_JOIN_INNER_TD_10880607_output.setInt64(r, 3, _ss_sales_price4343);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10880607_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_10880607_output #Row: " << tbl_JOIN_INNER_TD_10880607_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_10406594_key {
    std::string _i_category240;
    std::string _i_brand236;
    std::string _s_store_name383;
    std::string _s_company_name395;
    int32_t _d_year126;
    int32_t _d_moy128;
    bool operator==(const SW_Aggregate_TD_10406594_key& other) const { return (_i_category240 == other._i_category240) && (_i_brand236 == other._i_brand236) && (_s_store_name383 == other._s_store_name383) && (_s_company_name395 == other._s_company_name395) && (_d_year126 == other._d_year126) && (_d_moy128 == other._d_moy128); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_10406594_key> {
    std::size_t operator() (const SW_Aggregate_TD_10406594_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_category240)) + (hash<string>()(k._i_brand236)) + (hash<string>()(k._s_store_name383)) + (hash<string>()(k._s_company_name395)) + (hash<int32_t>()(k._d_year126)) + (hash<int32_t>()(k._d_moy128));
    }
};
}
struct SW_Aggregate_TD_10406594_payload {
    int64_t _sum_sales3544_sum_0;
    int64_t __w03558_sum_1;
};
void SW_Aggregate_TD_10406594(Table &tbl_JOIN_INNER_TD_11976272_output, Table &tbl_Aggregate_TD_10406594_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(i_category#240, i_brand#236, s_store_name#383, s_company_name#395, d_year#126, d_moy#128, MakeDecimal(sum(UnscaledValue(ss_sales_price#1219)),17,2) AS sum_sales#3544, MakeDecimal(sum(UnscaledValue(ss_sales_price#1219)),17,2) AS _w0#3558)
    // Input: ListBuffer(i_brand#236, i_category#240, ss_sales_price#1219, d_year#126, d_moy#128, s_store_name#383, s_company_name#395)
    // Output: ListBuffer(i_category#240, i_brand#236, s_store_name#383, s_company_name#395, d_year#126, d_moy#128, sum_sales#3544, _w0#3558)
    std::unordered_map<SW_Aggregate_TD_10406594_key, SW_Aggregate_TD_10406594_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_11976272_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236 = tbl_JOIN_INNER_TD_11976272_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_category240 = tbl_JOIN_INNER_TD_11976272_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int64_t _ss_sales_price1219 = tbl_JOIN_INNER_TD_11976272_output.getInt64(i, 2);
        int32_t _d_year126 = tbl_JOIN_INNER_TD_11976272_output.getInt32(i, 3);
        int32_t _d_moy128 = tbl_JOIN_INNER_TD_11976272_output.getInt32(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383 = tbl_JOIN_INNER_TD_11976272_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _s_company_name395 = tbl_JOIN_INNER_TD_11976272_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        SW_Aggregate_TD_10406594_key k{std::string(_i_category240.data()), std::string(_i_brand236.data()), std::string(_s_store_name383.data()), std::string(_s_company_name395.data()), _d_year126, _d_moy128};
        int64_t _sum_sales3544_sum_0 = _ss_sales_price1219;
        int64_t __w03558_sum_1 = _ss_sales_price1219;
        SW_Aggregate_TD_10406594_payload p{_sum_sales3544_sum_0, __w03558_sum_1};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._sum_sales3544_sum_0 + _sum_sales3544_sum_0;
            p._sum_sales3544_sum_0 = sum_0;
            int64_t sum_1 = (it->second).__w03558_sum_1 + __w03558_sum_1;
            p.__w03558_sum_1 = sum_1;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category240{};
        memcpy(_i_category240.data(), ((it.first)._i_category240).data(), ((it.first)._i_category240).length());
        tbl_Aggregate_TD_10406594_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category240);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236{};
        memcpy(_i_brand236.data(), ((it.first)._i_brand236).data(), ((it.first)._i_brand236).length());
        tbl_Aggregate_TD_10406594_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand236);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383{};
        memcpy(_s_store_name383.data(), ((it.first)._s_store_name383).data(), ((it.first)._s_store_name383).length());
        tbl_Aggregate_TD_10406594_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_store_name383);
        std::array<char, TPCDS_READ_MAX + 1> _s_company_name395{};
        memcpy(_s_company_name395.data(), ((it.first)._s_company_name395).data(), ((it.first)._s_company_name395).length());
        tbl_Aggregate_TD_10406594_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _s_company_name395);
        tbl_Aggregate_TD_10406594_output.setInt32(r, 4, (it.first)._d_year126);
        tbl_Aggregate_TD_10406594_output.setInt32(r, 5, (it.first)._d_moy128);
        int64_t _sum_sales3544 = (it.second)._sum_sales3544_sum_0;
        tbl_Aggregate_TD_10406594_output.setInt64(r, 6, _sum_sales3544);
        int64_t __w03558 = (it.second).__w03558_sum_1;
        tbl_Aggregate_TD_10406594_output.setInt64(r, 7, __w03558);
        ++r;
    }
    tbl_Aggregate_TD_10406594_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_10406594_output #Row: " << tbl_Aggregate_TD_10406594_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9100061(Table &tbl_SerializeFromObject_TD_1058800_input, Table &tbl_Filter_TD_9100061_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(s_store_sk#4488) AND (isnotnull(s_store_name#4493) AND isnotnull(s_company_name#4505))))
    // Input: ListBuffer(s_store_sk#4488, s_store_name#4493, s_company_name#4505)
    // Output: ListBuffer(s_store_sk#4488, s_store_name#4493, s_company_name#4505)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1058800_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _s_store_sk4488 = tbl_SerializeFromObject_TD_1058800_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name4493 = tbl_SerializeFromObject_TD_1058800_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _s_company_name4505 = tbl_SerializeFromObject_TD_1058800_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        if ((_s_store_sk4488!= 0) && (_s_store_name4493.data() != "NULL" && _s_company_name4505.data() != "NULL")) {
            int32_t _s_store_sk4488_t = tbl_SerializeFromObject_TD_1058800_input.getInt32(i, 0);
            tbl_Filter_TD_9100061_output.setInt32(r, 0, _s_store_sk4488_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name4493_t = tbl_SerializeFromObject_TD_1058800_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_9100061_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_store_name4493_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_company_name4505_t = tbl_SerializeFromObject_TD_1058800_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_9100061_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_company_name4505_t);
            r++;
        }
    }
    tbl_Filter_TD_9100061_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9100061_output #Row: " << tbl_Filter_TD_9100061_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_9435922_key_leftMajor {
    int32_t _ss_sold_date_sk4437;
    bool operator==(const SW_JOIN_INNER_TD_9435922_key_leftMajor& other) const {
        return ((_ss_sold_date_sk4437 == other._ss_sold_date_sk4437));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9435922_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9435922_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_sold_date_sk4437));
    }
};
}
struct SW_JOIN_INNER_TD_9435922_payload_leftMajor {
    std::string _i_brand4423;
    std::string _i_category4427;
    int32_t _ss_sold_date_sk4437;
    int32_t _ss_store_sk4444;
    int64_t _ss_sales_price4450;
};
struct SW_JOIN_INNER_TD_9435922_key_rightMajor {
    int32_t _d_date_sk4460;
    bool operator==(const SW_JOIN_INNER_TD_9435922_key_rightMajor& other) const {
        return ((_d_date_sk4460 == other._d_date_sk4460));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9435922_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9435922_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk4460));
    }
};
}
struct SW_JOIN_INNER_TD_9435922_payload_rightMajor {
    int32_t _d_date_sk4460;
    int32_t _d_year4466;
    int32_t _d_moy4468;
};
void SW_JOIN_INNER_TD_9435922(Table &tbl_JOIN_INNER_TD_10575406_output, Table &tbl_Filter_TD_10754913_output, Table &tbl_JOIN_INNER_TD_9435922_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#4437 = d_date_sk#4460))
    // Left Table: ListBuffer(i_brand#4423, i_category#4427, ss_sold_date_sk#4437, ss_store_sk#4444, ss_sales_price#4450)
    // Right Table: ListBuffer(d_date_sk#4460, d_year#4466, d_moy#4468)
    // Output Table: ListBuffer(i_brand#4423, i_category#4427, ss_store_sk#4444, ss_sales_price#4450, d_year#4466, d_moy#4468)
    int left_nrow = tbl_JOIN_INNER_TD_10575406_output.getNumRow();
    int right_nrow = tbl_Filter_TD_10754913_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9435922_key_leftMajor, SW_JOIN_INNER_TD_9435922_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_10575406_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_sold_date_sk4437_k = tbl_JOIN_INNER_TD_10575406_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_9435922_key_leftMajor keyA{_ss_sold_date_sk4437_k};
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4423_n = tbl_JOIN_INNER_TD_10575406_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_brand4423 = std::string(_i_brand4423_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_category4427_n = tbl_JOIN_INNER_TD_10575406_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_category4427 = std::string(_i_category4427_n.data());
            int32_t _ss_sold_date_sk4437 = tbl_JOIN_INNER_TD_10575406_output.getInt32(i, 2);
            int32_t _ss_store_sk4444 = tbl_JOIN_INNER_TD_10575406_output.getInt32(i, 3);
            int64_t _ss_sales_price4450 = tbl_JOIN_INNER_TD_10575406_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_9435922_payload_leftMajor payloadA{_i_brand4423, _i_category4427, _ss_sold_date_sk4437, _ss_store_sk4444, _ss_sales_price4450};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_10754913_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk4460_k = tbl_Filter_TD_10754913_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9435922_key_leftMajor{_d_date_sk4460_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _i_brand4423 = (it->second)._i_brand4423;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4423_n{};
                memcpy(_i_brand4423_n.data(), (_i_brand4423).data(), (_i_brand4423).length());
                std::string _i_category4427 = (it->second)._i_category4427;
                std::array<char, TPCDS_READ_MAX + 1> _i_category4427_n{};
                memcpy(_i_category4427_n.data(), (_i_category4427).data(), (_i_category4427).length());
                int32_t _ss_sold_date_sk4437 = (it->second)._ss_sold_date_sk4437;
                int32_t _ss_store_sk4444 = (it->second)._ss_store_sk4444;
                int64_t _ss_sales_price4450 = (it->second)._ss_sales_price4450;
                int32_t _d_date_sk4460 = tbl_Filter_TD_10754913_output.getInt32(i, 0);
                int32_t _d_year4466 = tbl_Filter_TD_10754913_output.getInt32(i, 1);
                int32_t _d_moy4468 = tbl_Filter_TD_10754913_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_9435922_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand4423_n);
                tbl_JOIN_INNER_TD_9435922_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category4427_n);
                tbl_JOIN_INNER_TD_9435922_output.setInt32(r, 2, _ss_store_sk4444);
                tbl_JOIN_INNER_TD_9435922_output.setInt64(r, 3, _ss_sales_price4450);
                tbl_JOIN_INNER_TD_9435922_output.setInt32(r, 4, _d_year4466);
                tbl_JOIN_INNER_TD_9435922_output.setInt32(r, 5, _d_moy4468);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9435922_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9435922_key_rightMajor, SW_JOIN_INNER_TD_9435922_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_10754913_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk4460_k = tbl_Filter_TD_10754913_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_9435922_key_rightMajor keyA{_d_date_sk4460_k};
            int32_t _d_date_sk4460 = tbl_Filter_TD_10754913_output.getInt32(i, 0);
            int32_t _d_year4466 = tbl_Filter_TD_10754913_output.getInt32(i, 1);
            int32_t _d_moy4468 = tbl_Filter_TD_10754913_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_9435922_payload_rightMajor payloadA{_d_date_sk4460, _d_year4466, _d_moy4468};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_10575406_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_sold_date_sk4437_k = tbl_JOIN_INNER_TD_10575406_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9435922_key_rightMajor{_ss_sold_date_sk4437_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk4460 = (it->second)._d_date_sk4460;
                int32_t _d_year4466 = (it->second)._d_year4466;
                int32_t _d_moy4468 = (it->second)._d_moy4468;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4423_n = tbl_JOIN_INNER_TD_10575406_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _i_brand4423 = std::string(_i_brand4423_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_category4427_n = tbl_JOIN_INNER_TD_10575406_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_category4427 = std::string(_i_category4427_n.data());
                int32_t _ss_sold_date_sk4437 = tbl_JOIN_INNER_TD_10575406_output.getInt32(i, 2);
                int32_t _ss_store_sk4444 = tbl_JOIN_INNER_TD_10575406_output.getInt32(i, 3);
                int64_t _ss_sales_price4450 = tbl_JOIN_INNER_TD_10575406_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_9435922_output.setInt32(r, 4, _d_year4466);
                tbl_JOIN_INNER_TD_9435922_output.setInt32(r, 5, _d_moy4468);
                tbl_JOIN_INNER_TD_9435922_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand4423_n);
                tbl_JOIN_INNER_TD_9435922_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category4427_n);
                tbl_JOIN_INNER_TD_9435922_output.setInt32(r, 2, _ss_store_sk4444);
                tbl_JOIN_INNER_TD_9435922_output.setInt64(r, 3, _ss_sales_price4450);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9435922_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_9435922_output #Row: " << tbl_JOIN_INNER_TD_9435922_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_9135593_key_leftMajor {
    int32_t _ss_store_sk4337;
    bool operator==(const SW_JOIN_INNER_TD_9135593_key_leftMajor& other) const {
        return ((_ss_store_sk4337 == other._ss_store_sk4337));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9135593_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9135593_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_store_sk4337));
    }
};
}
struct SW_JOIN_INNER_TD_9135593_payload_leftMajor {
    std::string _i_brand4316;
    std::string _i_category4320;
    int32_t _ss_store_sk4337;
    int64_t _ss_sales_price4343;
    int32_t _d_year4359;
    int32_t _d_moy4361;
};
struct SW_JOIN_INNER_TD_9135593_key_rightMajor {
    int32_t _s_store_sk4381;
    bool operator==(const SW_JOIN_INNER_TD_9135593_key_rightMajor& other) const {
        return ((_s_store_sk4381 == other._s_store_sk4381));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9135593_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9135593_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_store_sk4381));
    }
};
}
struct SW_JOIN_INNER_TD_9135593_payload_rightMajor {
    int32_t _s_store_sk4381;
    std::string _s_store_name4386;
    std::string _s_company_name4398;
};
void SW_JOIN_INNER_TD_9135593(Table &tbl_JOIN_INNER_TD_10880607_output, Table &tbl_Filter_TD_10808472_output, Table &tbl_JOIN_INNER_TD_9135593_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_store_sk#4337 = s_store_sk#4381))
    // Left Table: ListBuffer(i_brand#4316, i_category#4320, ss_store_sk#4337, ss_sales_price#4343, d_year#4359, d_moy#4361)
    // Right Table: ListBuffer(s_store_sk#4381, s_store_name#4386, s_company_name#4398)
    // Output Table: ListBuffer(i_brand#4316, i_category#4320, ss_sales_price#4343, d_year#4359, d_moy#4361, s_store_name#4386, s_company_name#4398)
    int left_nrow = tbl_JOIN_INNER_TD_10880607_output.getNumRow();
    int right_nrow = tbl_Filter_TD_10808472_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9135593_key_leftMajor, SW_JOIN_INNER_TD_9135593_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_10880607_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_store_sk4337_k = tbl_JOIN_INNER_TD_10880607_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_9135593_key_leftMajor keyA{_ss_store_sk4337_k};
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4316_n = tbl_JOIN_INNER_TD_10880607_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_brand4316 = std::string(_i_brand4316_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_category4320_n = tbl_JOIN_INNER_TD_10880607_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_category4320 = std::string(_i_category4320_n.data());
            int32_t _ss_store_sk4337 = tbl_JOIN_INNER_TD_10880607_output.getInt32(i, 2);
            int64_t _ss_sales_price4343 = tbl_JOIN_INNER_TD_10880607_output.getInt64(i, 3);
            int32_t _d_year4359 = tbl_JOIN_INNER_TD_10880607_output.getInt32(i, 4);
            int32_t _d_moy4361 = tbl_JOIN_INNER_TD_10880607_output.getInt32(i, 5);
            SW_JOIN_INNER_TD_9135593_payload_leftMajor payloadA{_i_brand4316, _i_category4320, _ss_store_sk4337, _ss_sales_price4343, _d_year4359, _d_moy4361};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_10808472_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_store_sk4381_k = tbl_Filter_TD_10808472_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9135593_key_leftMajor{_s_store_sk4381_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _i_brand4316 = (it->second)._i_brand4316;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4316_n{};
                memcpy(_i_brand4316_n.data(), (_i_brand4316).data(), (_i_brand4316).length());
                std::string _i_category4320 = (it->second)._i_category4320;
                std::array<char, TPCDS_READ_MAX + 1> _i_category4320_n{};
                memcpy(_i_category4320_n.data(), (_i_category4320).data(), (_i_category4320).length());
                int32_t _ss_store_sk4337 = (it->second)._ss_store_sk4337;
                int64_t _ss_sales_price4343 = (it->second)._ss_sales_price4343;
                int32_t _d_year4359 = (it->second)._d_year4359;
                int32_t _d_moy4361 = (it->second)._d_moy4361;
                int32_t _s_store_sk4381 = tbl_Filter_TD_10808472_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4386_n = tbl_Filter_TD_10808472_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _s_store_name4386 = std::string(_s_store_name4386_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_company_name4398_n = tbl_Filter_TD_10808472_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _s_company_name4398 = std::string(_s_company_name4398_n.data());
                tbl_JOIN_INNER_TD_9135593_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand4316_n);
                tbl_JOIN_INNER_TD_9135593_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category4320_n);
                tbl_JOIN_INNER_TD_9135593_output.setInt64(r, 2, _ss_sales_price4343);
                tbl_JOIN_INNER_TD_9135593_output.setInt32(r, 3, _d_year4359);
                tbl_JOIN_INNER_TD_9135593_output.setInt32(r, 4, _d_moy4361);
                tbl_JOIN_INNER_TD_9135593_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_store_name4386_n);
                tbl_JOIN_INNER_TD_9135593_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_company_name4398_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9135593_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9135593_key_rightMajor, SW_JOIN_INNER_TD_9135593_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_10808472_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_store_sk4381_k = tbl_Filter_TD_10808472_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_9135593_key_rightMajor keyA{_s_store_sk4381_k};
            int32_t _s_store_sk4381 = tbl_Filter_TD_10808472_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name4386_n = tbl_Filter_TD_10808472_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _s_store_name4386 = std::string(_s_store_name4386_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_company_name4398_n = tbl_Filter_TD_10808472_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _s_company_name4398 = std::string(_s_company_name4398_n.data());
            SW_JOIN_INNER_TD_9135593_payload_rightMajor payloadA{_s_store_sk4381, _s_store_name4386, _s_company_name4398};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_10880607_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_store_sk4337_k = tbl_JOIN_INNER_TD_10880607_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9135593_key_rightMajor{_ss_store_sk4337_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _s_store_sk4381 = (it->second)._s_store_sk4381;
                std::string _s_store_name4386 = (it->second)._s_store_name4386;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4386_n{};
                memcpy(_s_store_name4386_n.data(), (_s_store_name4386).data(), (_s_store_name4386).length());
                std::string _s_company_name4398 = (it->second)._s_company_name4398;
                std::array<char, TPCDS_READ_MAX + 1> _s_company_name4398_n{};
                memcpy(_s_company_name4398_n.data(), (_s_company_name4398).data(), (_s_company_name4398).length());
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4316_n = tbl_JOIN_INNER_TD_10880607_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _i_brand4316 = std::string(_i_brand4316_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_category4320_n = tbl_JOIN_INNER_TD_10880607_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_category4320 = std::string(_i_category4320_n.data());
                int32_t _ss_store_sk4337 = tbl_JOIN_INNER_TD_10880607_output.getInt32(i, 2);
                int64_t _ss_sales_price4343 = tbl_JOIN_INNER_TD_10880607_output.getInt64(i, 3);
                int32_t _d_year4359 = tbl_JOIN_INNER_TD_10880607_output.getInt32(i, 4);
                int32_t _d_moy4361 = tbl_JOIN_INNER_TD_10880607_output.getInt32(i, 5);
                tbl_JOIN_INNER_TD_9135593_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_store_name4386_n);
                tbl_JOIN_INNER_TD_9135593_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_company_name4398_n);
                tbl_JOIN_INNER_TD_9135593_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand4316_n);
                tbl_JOIN_INNER_TD_9135593_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category4320_n);
                tbl_JOIN_INNER_TD_9135593_output.setInt64(r, 2, _ss_sales_price4343);
                tbl_JOIN_INNER_TD_9135593_output.setInt32(r, 3, _d_year4359);
                tbl_JOIN_INNER_TD_9135593_output.setInt32(r, 4, _d_moy4361);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9135593_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_9135593_output #Row: " << tbl_JOIN_INNER_TD_9135593_output.getNumRow() << std::endl;
}

void SW_Window_TD_9144530(Table &tbl_Aggregate_TD_10406594_output, Table &tbl_Window_TD_9144530_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Window
    // Operation: ListBuffer(rank(d_year#126, d_moy#128) windowspecdefinition(i_category#240, i_brand#236, s_store_name#383, s_company_name#395, d_year#126 ASC NULLS FIRST, d_moy#128 ASC NULLS FIRST, specifiedwindowframe(RowFrame, unboundedpreceding$(), currentrow$())) AS rn#3546)
    // Input: ListBuffer(i_category#240, i_brand#236, s_store_name#383, s_company_name#395, d_year#126, d_moy#128, sum_sales#3544, _w0#3558)
    // Output: ListBuffer(i_category#240, i_brand#236, s_store_name#383, s_company_name#395, d_year#126, d_moy#128, sum_sales#3544, _w0#3558, rn#3546)
    struct SW_Window_TD_9144530Row {
        std::string _i_category240;
        std::string _i_brand236;
        std::string _s_store_name383;
        std::string _s_company_name395;
        int32_t _d_year126;
        int32_t _d_moy128;
        int64_t _sum_sales3544;
        int64_t __w03558;
    }; 

    int nrow = tbl_Aggregate_TD_10406594_output.getNumRow();
    std::vector<SW_Window_TD_9144530Row> rows0;
    int r = 0;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category240 = tbl_Aggregate_TD_10406594_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        tbl_Window_TD_9144530_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _i_category240);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236 = tbl_Aggregate_TD_10406594_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        tbl_Window_TD_9144530_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _i_brand236);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383 = tbl_Aggregate_TD_10406594_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        tbl_Window_TD_9144530_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _s_store_name383);
        std::array<char, TPCDS_READ_MAX + 1> _s_company_name395 = tbl_Aggregate_TD_10406594_output.getcharN<char, TPCDS_READ_MAX +1>(i, 3);
        tbl_Window_TD_9144530_output.setcharN<char, TPCDS_READ_MAX +1>(r, 3, _s_company_name395);
        int32_t _d_year126 = tbl_Aggregate_TD_10406594_output.getInt32(i, 4);
        tbl_Window_TD_9144530_output.setInt32(r, 4,_d_year126);
        int32_t _d_moy128 = tbl_Aggregate_TD_10406594_output.getInt32(i, 5);
        tbl_Window_TD_9144530_output.setInt32(r, 5,_d_moy128);
        int64_t _sum_sales3544 = tbl_Aggregate_TD_10406594_output.getInt64(i, 6);
        tbl_Window_TD_9144530_output.setInt64(r, 6,_sum_sales3544);
        int64_t __w03558 = tbl_Aggregate_TD_10406594_output.getInt64(i, 7);
        tbl_Window_TD_9144530_output.setInt64(r, 7,__w03558);
        r++;
        SW_Window_TD_9144530Row t = {std::string(_i_category240.data()),std::string(_i_brand236.data()),std::string(_s_store_name383.data()),std::string(_s_company_name395.data()),_d_year126,_d_moy128,_sum_sales3544,__w03558};
        rows0.push_back(t);
    }
    struct {
        bool operator()(const SW_Window_TD_9144530Row& a, const SW_Window_TD_9144530Row& b) const { return 
(a._i_category240 < b._i_category240) || 
 ((a._i_category240 == b._i_category240) && (a._i_brand236 < b._i_brand236)) || 
 ((a._i_category240 == b._i_category240) && (a._i_brand236 == b._i_brand236) && (a._s_store_name383 < b._s_store_name383)) || 
 ((a._i_category240 == b._i_category240) && (a._i_brand236 == b._i_brand236) && (a._s_store_name383 == b._s_store_name383) && (a._s_company_name395 < b._s_company_name395)) || 
 ((a._i_category240 == b._i_category240) && (a._i_brand236 == b._i_brand236) && (a._s_store_name383 == b._s_store_name383) && (a._s_company_name395 == b._s_company_name395) && (a._d_year126 < b._d_year126)) || 
 ((a._i_category240 == b._i_category240) && (a._i_brand236 == b._i_brand236) && (a._s_store_name383 == b._s_store_name383) && (a._s_company_name395 == b._s_company_name395) && (a._d_year126 == b._d_year126) && (a._d_moy128 < b._d_moy128)); 
}
    }SW_Window_TD_9144530_order0; 

    std::sort(rows0.begin(), rows0.end(), SW_Window_TD_9144530_order0);
    std::vector<int32_t> ranks0(rows0.size(), 0);
    int32_t currentRank0 = 0;
    int32_t currentPartitionCount0 = 1;
    bool isSamePartition0 = true;
    bool isSameOrderKey0 = true;
    if (!rows0.empty()) {;
      ranks0[0] = ++currentRank0;
    };
    for (int i = 1; i< rows0.size(); i++) {
        isSamePartition0 = ( rows0[i]._i_category240 == rows0[i-1]._i_category240 && rows0[i]._i_brand236 == rows0[i-1]._i_brand236 && rows0[i]._s_store_name383 == rows0[i-1]._s_store_name383 && rows0[i]._s_company_name395 == rows0[i-1]._s_company_name395);
        isSameOrderKey0 = ( rows0[i]._d_year126 == rows0[i-1]._d_year126 && rows0[i]._d_moy128 == rows0[i-1]._d_moy128);
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
        tbl_Window_TD_9144530_output.setInt32(r, 8, ranks0[i]);
    }
    tbl_Window_TD_9144530_output.setNumRow(r);
    std::cout << "tbl_Window_TD_9144530_output #Row: " << tbl_Window_TD_9144530_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8400276_key_leftMajor {
    int32_t _ss_store_sk4444;
    bool operator==(const SW_JOIN_INNER_TD_8400276_key_leftMajor& other) const {
        return ((_ss_store_sk4444 == other._ss_store_sk4444));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8400276_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8400276_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_store_sk4444));
    }
};
}
struct SW_JOIN_INNER_TD_8400276_payload_leftMajor {
    std::string _i_brand4423;
    std::string _i_category4427;
    int32_t _ss_store_sk4444;
    int64_t _ss_sales_price4450;
    int32_t _d_year4466;
    int32_t _d_moy4468;
};
struct SW_JOIN_INNER_TD_8400276_key_rightMajor {
    int32_t _s_store_sk4488;
    bool operator==(const SW_JOIN_INNER_TD_8400276_key_rightMajor& other) const {
        return ((_s_store_sk4488 == other._s_store_sk4488));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8400276_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8400276_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_store_sk4488));
    }
};
}
struct SW_JOIN_INNER_TD_8400276_payload_rightMajor {
    int32_t _s_store_sk4488;
    std::string _s_store_name4493;
    std::string _s_company_name4505;
};
void SW_JOIN_INNER_TD_8400276(Table &tbl_JOIN_INNER_TD_9435922_output, Table &tbl_Filter_TD_9100061_output, Table &tbl_JOIN_INNER_TD_8400276_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_store_sk#4444 = s_store_sk#4488))
    // Left Table: ListBuffer(i_brand#4423, i_category#4427, ss_store_sk#4444, ss_sales_price#4450, d_year#4466, d_moy#4468)
    // Right Table: ListBuffer(s_store_sk#4488, s_store_name#4493, s_company_name#4505)
    // Output Table: ListBuffer(i_brand#4423, i_category#4427, ss_sales_price#4450, d_year#4466, d_moy#4468, s_store_name#4493, s_company_name#4505)
    int left_nrow = tbl_JOIN_INNER_TD_9435922_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9100061_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8400276_key_leftMajor, SW_JOIN_INNER_TD_8400276_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_9435922_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_store_sk4444_k = tbl_JOIN_INNER_TD_9435922_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_8400276_key_leftMajor keyA{_ss_store_sk4444_k};
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4423_n = tbl_JOIN_INNER_TD_9435922_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_brand4423 = std::string(_i_brand4423_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_category4427_n = tbl_JOIN_INNER_TD_9435922_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_category4427 = std::string(_i_category4427_n.data());
            int32_t _ss_store_sk4444 = tbl_JOIN_INNER_TD_9435922_output.getInt32(i, 2);
            int64_t _ss_sales_price4450 = tbl_JOIN_INNER_TD_9435922_output.getInt64(i, 3);
            int32_t _d_year4466 = tbl_JOIN_INNER_TD_9435922_output.getInt32(i, 4);
            int32_t _d_moy4468 = tbl_JOIN_INNER_TD_9435922_output.getInt32(i, 5);
            SW_JOIN_INNER_TD_8400276_payload_leftMajor payloadA{_i_brand4423, _i_category4427, _ss_store_sk4444, _ss_sales_price4450, _d_year4466, _d_moy4468};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9100061_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_store_sk4488_k = tbl_Filter_TD_9100061_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8400276_key_leftMajor{_s_store_sk4488_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _i_brand4423 = (it->second)._i_brand4423;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4423_n{};
                memcpy(_i_brand4423_n.data(), (_i_brand4423).data(), (_i_brand4423).length());
                std::string _i_category4427 = (it->second)._i_category4427;
                std::array<char, TPCDS_READ_MAX + 1> _i_category4427_n{};
                memcpy(_i_category4427_n.data(), (_i_category4427).data(), (_i_category4427).length());
                int32_t _ss_store_sk4444 = (it->second)._ss_store_sk4444;
                int64_t _ss_sales_price4450 = (it->second)._ss_sales_price4450;
                int32_t _d_year4466 = (it->second)._d_year4466;
                int32_t _d_moy4468 = (it->second)._d_moy4468;
                int32_t _s_store_sk4488 = tbl_Filter_TD_9100061_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4493_n = tbl_Filter_TD_9100061_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _s_store_name4493 = std::string(_s_store_name4493_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_company_name4505_n = tbl_Filter_TD_9100061_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _s_company_name4505 = std::string(_s_company_name4505_n.data());
                tbl_JOIN_INNER_TD_8400276_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand4423_n);
                tbl_JOIN_INNER_TD_8400276_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category4427_n);
                tbl_JOIN_INNER_TD_8400276_output.setInt64(r, 2, _ss_sales_price4450);
                tbl_JOIN_INNER_TD_8400276_output.setInt32(r, 3, _d_year4466);
                tbl_JOIN_INNER_TD_8400276_output.setInt32(r, 4, _d_moy4468);
                tbl_JOIN_INNER_TD_8400276_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_store_name4493_n);
                tbl_JOIN_INNER_TD_8400276_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_company_name4505_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8400276_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8400276_key_rightMajor, SW_JOIN_INNER_TD_8400276_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9100061_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_store_sk4488_k = tbl_Filter_TD_9100061_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8400276_key_rightMajor keyA{_s_store_sk4488_k};
            int32_t _s_store_sk4488 = tbl_Filter_TD_9100061_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name4493_n = tbl_Filter_TD_9100061_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _s_store_name4493 = std::string(_s_store_name4493_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_company_name4505_n = tbl_Filter_TD_9100061_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _s_company_name4505 = std::string(_s_company_name4505_n.data());
            SW_JOIN_INNER_TD_8400276_payload_rightMajor payloadA{_s_store_sk4488, _s_store_name4493, _s_company_name4505};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_9435922_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_store_sk4444_k = tbl_JOIN_INNER_TD_9435922_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8400276_key_rightMajor{_ss_store_sk4444_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _s_store_sk4488 = (it->second)._s_store_sk4488;
                std::string _s_store_name4493 = (it->second)._s_store_name4493;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4493_n{};
                memcpy(_s_store_name4493_n.data(), (_s_store_name4493).data(), (_s_store_name4493).length());
                std::string _s_company_name4505 = (it->second)._s_company_name4505;
                std::array<char, TPCDS_READ_MAX + 1> _s_company_name4505_n{};
                memcpy(_s_company_name4505_n.data(), (_s_company_name4505).data(), (_s_company_name4505).length());
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4423_n = tbl_JOIN_INNER_TD_9435922_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _i_brand4423 = std::string(_i_brand4423_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_category4427_n = tbl_JOIN_INNER_TD_9435922_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_category4427 = std::string(_i_category4427_n.data());
                int32_t _ss_store_sk4444 = tbl_JOIN_INNER_TD_9435922_output.getInt32(i, 2);
                int64_t _ss_sales_price4450 = tbl_JOIN_INNER_TD_9435922_output.getInt64(i, 3);
                int32_t _d_year4466 = tbl_JOIN_INNER_TD_9435922_output.getInt32(i, 4);
                int32_t _d_moy4468 = tbl_JOIN_INNER_TD_9435922_output.getInt32(i, 5);
                tbl_JOIN_INNER_TD_8400276_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_store_name4493_n);
                tbl_JOIN_INNER_TD_8400276_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_company_name4505_n);
                tbl_JOIN_INNER_TD_8400276_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand4423_n);
                tbl_JOIN_INNER_TD_8400276_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category4427_n);
                tbl_JOIN_INNER_TD_8400276_output.setInt64(r, 2, _ss_sales_price4450);
                tbl_JOIN_INNER_TD_8400276_output.setInt32(r, 3, _d_year4466);
                tbl_JOIN_INNER_TD_8400276_output.setInt32(r, 4, _d_moy4468);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8400276_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8400276_output #Row: " << tbl_JOIN_INNER_TD_8400276_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_8602438_key {
    std::string _i_category4320;
    std::string _i_brand4316;
    std::string _s_store_name4386;
    std::string _s_company_name4398;
    int32_t _d_year4359;
    int32_t _d_moy4361;
    bool operator==(const SW_Aggregate_TD_8602438_key& other) const { return (_i_category4320 == other._i_category4320) && (_i_brand4316 == other._i_brand4316) && (_s_store_name4386 == other._s_store_name4386) && (_s_company_name4398 == other._s_company_name4398) && (_d_year4359 == other._d_year4359) && (_d_moy4361 == other._d_moy4361); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_8602438_key> {
    std::size_t operator() (const SW_Aggregate_TD_8602438_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_category4320)) + (hash<string>()(k._i_brand4316)) + (hash<string>()(k._s_store_name4386)) + (hash<string>()(k._s_company_name4398)) + (hash<int32_t>()(k._d_year4359)) + (hash<int32_t>()(k._d_moy4361));
    }
};
}
struct SW_Aggregate_TD_8602438_payload {
    int64_t _sum_sales3544_sum_0;
};
void SW_Aggregate_TD_8602438(Table &tbl_JOIN_INNER_TD_9135593_output, Table &tbl_Aggregate_TD_8602438_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(i_category#4320, i_brand#4316, s_store_name#4386, s_company_name#4398, d_year#4359, d_moy#4361, MakeDecimal(sum(UnscaledValue(ss_sales_price#4343)),17,2) AS sum_sales#3544)
    // Input: ListBuffer(i_brand#4316, i_category#4320, ss_sales_price#4343, d_year#4359, d_moy#4361, s_store_name#4386, s_company_name#4398)
    // Output: ListBuffer(i_category#4320, i_brand#4316, s_store_name#4386, s_company_name#4398, d_year#4359, d_moy#4361, sum_sales#3544)
    std::unordered_map<SW_Aggregate_TD_8602438_key, SW_Aggregate_TD_8602438_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_9135593_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_brand4316 = tbl_JOIN_INNER_TD_9135593_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_category4320 = tbl_JOIN_INNER_TD_9135593_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int64_t _ss_sales_price4343 = tbl_JOIN_INNER_TD_9135593_output.getInt64(i, 2);
        int32_t _d_year4359 = tbl_JOIN_INNER_TD_9135593_output.getInt32(i, 3);
        int32_t _d_moy4361 = tbl_JOIN_INNER_TD_9135593_output.getInt32(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name4386 = tbl_JOIN_INNER_TD_9135593_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _s_company_name4398 = tbl_JOIN_INNER_TD_9135593_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        SW_Aggregate_TD_8602438_key k{std::string(_i_category4320.data()), std::string(_i_brand4316.data()), std::string(_s_store_name4386.data()), std::string(_s_company_name4398.data()), _d_year4359, _d_moy4361};
        int64_t _sum_sales3544_sum_0 = _ss_sales_price4343;
        SW_Aggregate_TD_8602438_payload p{_sum_sales3544_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._sum_sales3544_sum_0 + _sum_sales3544_sum_0;
            p._sum_sales3544_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category4320{};
        memcpy(_i_category4320.data(), ((it.first)._i_category4320).data(), ((it.first)._i_category4320).length());
        tbl_Aggregate_TD_8602438_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category4320);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand4316{};
        memcpy(_i_brand4316.data(), ((it.first)._i_brand4316).data(), ((it.first)._i_brand4316).length());
        tbl_Aggregate_TD_8602438_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand4316);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name4386{};
        memcpy(_s_store_name4386.data(), ((it.first)._s_store_name4386).data(), ((it.first)._s_store_name4386).length());
        tbl_Aggregate_TD_8602438_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_store_name4386);
        std::array<char, TPCDS_READ_MAX + 1> _s_company_name4398{};
        memcpy(_s_company_name4398.data(), ((it.first)._s_company_name4398).data(), ((it.first)._s_company_name4398).length());
        tbl_Aggregate_TD_8602438_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _s_company_name4398);
        tbl_Aggregate_TD_8602438_output.setInt32(r, 4, (it.first)._d_year4359);
        tbl_Aggregate_TD_8602438_output.setInt32(r, 5, (it.first)._d_moy4361);
        int64_t _sum_sales3544 = (it.second)._sum_sales3544_sum_0;
        tbl_Aggregate_TD_8602438_output.setInt64(r, 6, _sum_sales3544);
        ++r;
    }
    tbl_Aggregate_TD_8602438_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_8602438_output #Row: " << tbl_Aggregate_TD_8602438_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8717904(Table &tbl_Window_TD_9144530_output, Table &tbl_Filter_TD_8717904_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(d_year#126) AND (d_year#126 = 1999)))
    // Input: ListBuffer(i_category#240, i_brand#236, s_store_name#383, s_company_name#395, d_year#126, d_moy#128, sum_sales#3544, _w0#3558, rn#3546)
    // Output: ListBuffer(i_category#240, i_brand#236, s_store_name#383, s_company_name#395, d_year#126, d_moy#128, sum_sales#3544, _w0#3558, rn#3546)
    int r = 0;
    int nrow1 = tbl_Window_TD_9144530_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_Window_TD_9144530_output.getInt32(i, 4);
        if ((_d_year126!= 0) && (_d_year126 == 1999)) {
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_t = tbl_Window_TD_9144530_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            tbl_Filter_TD_8717904_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category240_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_t = tbl_Window_TD_9144530_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_8717904_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand236_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_t = tbl_Window_TD_9144530_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_8717904_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_store_name383_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_company_name395_t = tbl_Window_TD_9144530_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_8717904_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _s_company_name395_t);
            int32_t _d_year126_t = tbl_Window_TD_9144530_output.getInt32(i, 4);
            tbl_Filter_TD_8717904_output.setInt32(r, 4, _d_year126_t);
            int32_t _d_moy128_t = tbl_Window_TD_9144530_output.getInt32(i, 5);
            tbl_Filter_TD_8717904_output.setInt32(r, 5, _d_moy128_t);
            int64_t _sum_sales3544_t = tbl_Window_TD_9144530_output.getInt64(i, 6);
            tbl_Filter_TD_8717904_output.setInt64(r, 6, _sum_sales3544_t);
            int64_t __w03558_t = tbl_Window_TD_9144530_output.getInt64(i, 7);
            tbl_Filter_TD_8717904_output.setInt64(r, 7, __w03558_t);
            int32_t _rn3546_t = tbl_Window_TD_9144530_output.getInt32(i, 8);
            tbl_Filter_TD_8717904_output.setInt32(r, 8, _rn3546_t);
            r++;
        }
    }
    tbl_Filter_TD_8717904_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8717904_output #Row: " << tbl_Filter_TD_8717904_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_7672439_key {
    std::string _i_category4427;
    std::string _i_brand4423;
    std::string _s_store_name4493;
    std::string _s_company_name4505;
    int32_t _d_year4466;
    int32_t _d_moy4468;
    bool operator==(const SW_Aggregate_TD_7672439_key& other) const { return (_i_category4427 == other._i_category4427) && (_i_brand4423 == other._i_brand4423) && (_s_store_name4493 == other._s_store_name4493) && (_s_company_name4505 == other._s_company_name4505) && (_d_year4466 == other._d_year4466) && (_d_moy4468 == other._d_moy4468); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_7672439_key> {
    std::size_t operator() (const SW_Aggregate_TD_7672439_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_category4427)) + (hash<string>()(k._i_brand4423)) + (hash<string>()(k._s_store_name4493)) + (hash<string>()(k._s_company_name4505)) + (hash<int32_t>()(k._d_year4466)) + (hash<int32_t>()(k._d_moy4468));
    }
};
}
struct SW_Aggregate_TD_7672439_payload {
    int64_t _sum_sales3544_sum_0;
};
void SW_Aggregate_TD_7672439(Table &tbl_JOIN_INNER_TD_8400276_output, Table &tbl_Aggregate_TD_7672439_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(i_category#4427, i_brand#4423, s_store_name#4493, s_company_name#4505, d_year#4466, d_moy#4468, MakeDecimal(sum(UnscaledValue(ss_sales_price#4450)),17,2) AS sum_sales#3544)
    // Input: ListBuffer(i_brand#4423, i_category#4427, ss_sales_price#4450, d_year#4466, d_moy#4468, s_store_name#4493, s_company_name#4505)
    // Output: ListBuffer(i_category#4427, i_brand#4423, s_store_name#4493, s_company_name#4505, d_year#4466, d_moy#4468, sum_sales#3544)
    std::unordered_map<SW_Aggregate_TD_7672439_key, SW_Aggregate_TD_7672439_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_8400276_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_brand4423 = tbl_JOIN_INNER_TD_8400276_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_category4427 = tbl_JOIN_INNER_TD_8400276_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int64_t _ss_sales_price4450 = tbl_JOIN_INNER_TD_8400276_output.getInt64(i, 2);
        int32_t _d_year4466 = tbl_JOIN_INNER_TD_8400276_output.getInt32(i, 3);
        int32_t _d_moy4468 = tbl_JOIN_INNER_TD_8400276_output.getInt32(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name4493 = tbl_JOIN_INNER_TD_8400276_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _s_company_name4505 = tbl_JOIN_INNER_TD_8400276_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        SW_Aggregate_TD_7672439_key k{std::string(_i_category4427.data()), std::string(_i_brand4423.data()), std::string(_s_store_name4493.data()), std::string(_s_company_name4505.data()), _d_year4466, _d_moy4468};
        int64_t _sum_sales3544_sum_0 = _ss_sales_price4450;
        SW_Aggregate_TD_7672439_payload p{_sum_sales3544_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._sum_sales3544_sum_0 + _sum_sales3544_sum_0;
            p._sum_sales3544_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category4427{};
        memcpy(_i_category4427.data(), ((it.first)._i_category4427).data(), ((it.first)._i_category4427).length());
        tbl_Aggregate_TD_7672439_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category4427);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand4423{};
        memcpy(_i_brand4423.data(), ((it.first)._i_brand4423).data(), ((it.first)._i_brand4423).length());
        tbl_Aggregate_TD_7672439_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand4423);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name4493{};
        memcpy(_s_store_name4493.data(), ((it.first)._s_store_name4493).data(), ((it.first)._s_store_name4493).length());
        tbl_Aggregate_TD_7672439_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_store_name4493);
        std::array<char, TPCDS_READ_MAX + 1> _s_company_name4505{};
        memcpy(_s_company_name4505.data(), ((it.first)._s_company_name4505).data(), ((it.first)._s_company_name4505).length());
        tbl_Aggregate_TD_7672439_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _s_company_name4505);
        tbl_Aggregate_TD_7672439_output.setInt32(r, 4, (it.first)._d_year4466);
        tbl_Aggregate_TD_7672439_output.setInt32(r, 5, (it.first)._d_moy4468);
        int64_t _sum_sales3544 = (it.second)._sum_sales3544_sum_0;
        tbl_Aggregate_TD_7672439_output.setInt64(r, 6, _sum_sales3544);
        ++r;
    }
    tbl_Aggregate_TD_7672439_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_7672439_output #Row: " << tbl_Aggregate_TD_7672439_output.getNumRow() << std::endl;
}

void SW_Window_TD_74072(Table &tbl_Aggregate_TD_8602438_output, Table &tbl_Window_TD_74072_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Window
    // Operation: ListBuffer(rank(d_year#4359, d_moy#4361) windowspecdefinition(i_category#4320, i_brand#4316, s_store_name#4386, s_company_name#4398, d_year#4359 ASC NULLS FIRST, d_moy#4361 ASC NULLS FIRST, specifiedwindowframe(RowFrame, unboundedpreceding$(), currentrow$())) AS rn#4414)
    // Input: ListBuffer(i_category#4320, i_brand#4316, s_store_name#4386, s_company_name#4398, d_year#4359, d_moy#4361, sum_sales#3544)
    // Output: ListBuffer(i_category#4320, i_brand#4316, s_store_name#4386, s_company_name#4398, d_year#4359, d_moy#4361, sum_sales#3544, rn#4414)
    struct SW_Window_TD_74072Row {
        std::string _i_category4320;
        std::string _i_brand4316;
        std::string _s_store_name4386;
        std::string _s_company_name4398;
        int32_t _d_year4359;
        int32_t _d_moy4361;
        int64_t _sum_sales3544;
    }; 

    int nrow = tbl_Aggregate_TD_8602438_output.getNumRow();
    std::vector<SW_Window_TD_74072Row> rows0;
    int r = 0;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category4320 = tbl_Aggregate_TD_8602438_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        tbl_Window_TD_74072_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _i_category4320);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand4316 = tbl_Aggregate_TD_8602438_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        tbl_Window_TD_74072_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _i_brand4316);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name4386 = tbl_Aggregate_TD_8602438_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        tbl_Window_TD_74072_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _s_store_name4386);
        std::array<char, TPCDS_READ_MAX + 1> _s_company_name4398 = tbl_Aggregate_TD_8602438_output.getcharN<char, TPCDS_READ_MAX +1>(i, 3);
        tbl_Window_TD_74072_output.setcharN<char, TPCDS_READ_MAX +1>(r, 3, _s_company_name4398);
        int32_t _d_year4359 = tbl_Aggregate_TD_8602438_output.getInt32(i, 4);
        tbl_Window_TD_74072_output.setInt32(r, 4,_d_year4359);
        int32_t _d_moy4361 = tbl_Aggregate_TD_8602438_output.getInt32(i, 5);
        tbl_Window_TD_74072_output.setInt32(r, 5,_d_moy4361);
        int64_t _sum_sales3544 = tbl_Aggregate_TD_8602438_output.getInt64(i, 6);
        tbl_Window_TD_74072_output.setInt64(r, 6,_sum_sales3544);
        r++;
        SW_Window_TD_74072Row t = {std::string(_i_category4320.data()),std::string(_i_brand4316.data()),std::string(_s_store_name4386.data()),std::string(_s_company_name4398.data()),_d_year4359,_d_moy4361,_sum_sales3544};
        rows0.push_back(t);
    }
    struct {
        bool operator()(const SW_Window_TD_74072Row& a, const SW_Window_TD_74072Row& b) const { return 
(a._i_category4320 < b._i_category4320) || 
 ((a._i_category4320 == b._i_category4320) && (a._i_brand4316 < b._i_brand4316)) || 
 ((a._i_category4320 == b._i_category4320) && (a._i_brand4316 == b._i_brand4316) && (a._s_store_name4386 < b._s_store_name4386)) || 
 ((a._i_category4320 == b._i_category4320) && (a._i_brand4316 == b._i_brand4316) && (a._s_store_name4386 == b._s_store_name4386) && (a._s_company_name4398 < b._s_company_name4398)) || 
 ((a._i_category4320 == b._i_category4320) && (a._i_brand4316 == b._i_brand4316) && (a._s_store_name4386 == b._s_store_name4386) && (a._s_company_name4398 == b._s_company_name4398) && (a._d_year4359 < b._d_year4359)) || 
 ((a._i_category4320 == b._i_category4320) && (a._i_brand4316 == b._i_brand4316) && (a._s_store_name4386 == b._s_store_name4386) && (a._s_company_name4398 == b._s_company_name4398) && (a._d_year4359 == b._d_year4359) && (a._d_moy4361 < b._d_moy4361)); 
}
    }SW_Window_TD_74072_order0; 

    std::sort(rows0.begin(), rows0.end(), SW_Window_TD_74072_order0);
    std::vector<int32_t> ranks0(rows0.size(), 0);
    int32_t currentRank0 = 0;
    int32_t currentPartitionCount0 = 1;
    bool isSamePartition0 = true;
    bool isSameOrderKey0 = true;
    if (!rows0.empty()) {;
      ranks0[0] = ++currentRank0;
    };
    for (int i = 1; i< rows0.size(); i++) {
        isSamePartition0 = ( rows0[i]._i_category4320 == rows0[i-1]._i_category4320 && rows0[i]._i_brand4316 == rows0[i-1]._i_brand4316 && rows0[i]._s_store_name4386 == rows0[i-1]._s_store_name4386 && rows0[i]._s_company_name4398 == rows0[i-1]._s_company_name4398);
        isSameOrderKey0 = ( rows0[i]._d_year4359 == rows0[i-1]._d_year4359 && rows0[i]._d_moy4361 == rows0[i-1]._d_moy4361);
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
        tbl_Window_TD_74072_output.setInt32(r, 7, ranks0[i]);
    }
    tbl_Window_TD_74072_output.setNumRow(r);
    std::cout << "tbl_Window_TD_74072_output #Row: " << tbl_Window_TD_74072_output.getNumRow() << std::endl;
}

void SW_Window_TD_7140839(Table &tbl_Filter_TD_8717904_output, Table &tbl_Window_TD_7140839_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Window
    // Operation: ListBuffer(avg(_w0#3558) windowspecdefinition(i_category#240, i_brand#236, s_store_name#383, s_company_name#395, d_year#126, specifiedwindowframe(RowFrame, unboundedpreceding$(), unboundedfollowing$())) AS avg_monthly_sales#3545)
    // Input: ListBuffer(i_category#240, i_brand#236, s_store_name#383, s_company_name#395, d_year#126, d_moy#128, sum_sales#3544, _w0#3558, rn#3546)
    // Output: ListBuffer(i_category#240, i_brand#236, s_store_name#383, s_company_name#395, d_year#126, d_moy#128, sum_sales#3544, _w0#3558, rn#3546, avg_monthly_sales#3545)
    struct SW_Window_TD_7140839Row {
        std::string _i_category240;
        std::string _i_brand236;
        std::string _s_store_name383;
        std::string _s_company_name395;
        int32_t _d_year126;
        int32_t _d_moy128;
        int64_t _sum_sales3544;
        int64_t __w03558;
        int32_t _rn3546;
    }; 

    int nrow = tbl_Filter_TD_8717904_output.getNumRow();
    std::vector<SW_Window_TD_7140839Row> rows0;
    int r = 0;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category240 = tbl_Filter_TD_8717904_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        tbl_Window_TD_7140839_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _i_category240);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236 = tbl_Filter_TD_8717904_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        tbl_Window_TD_7140839_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _i_brand236);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383 = tbl_Filter_TD_8717904_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        tbl_Window_TD_7140839_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _s_store_name383);
        std::array<char, TPCDS_READ_MAX + 1> _s_company_name395 = tbl_Filter_TD_8717904_output.getcharN<char, TPCDS_READ_MAX +1>(i, 3);
        tbl_Window_TD_7140839_output.setcharN<char, TPCDS_READ_MAX +1>(r, 3, _s_company_name395);
        int32_t _d_year126 = tbl_Filter_TD_8717904_output.getInt32(i, 4);
        tbl_Window_TD_7140839_output.setInt32(r, 4,_d_year126);
        int32_t _d_moy128 = tbl_Filter_TD_8717904_output.getInt32(i, 5);
        tbl_Window_TD_7140839_output.setInt32(r, 5,_d_moy128);
        int64_t _sum_sales3544 = tbl_Filter_TD_8717904_output.getInt64(i, 6);
        tbl_Window_TD_7140839_output.setInt64(r, 6,_sum_sales3544);
        int64_t __w03558 = tbl_Filter_TD_8717904_output.getInt64(i, 7);
        tbl_Window_TD_7140839_output.setInt64(r, 7,__w03558);
        int32_t _rn3546 = tbl_Filter_TD_8717904_output.getInt32(i, 8);
        tbl_Window_TD_7140839_output.setInt32(r, 8,_rn3546);
        r++;
        SW_Window_TD_7140839Row t = {std::string(_i_category240.data()),std::string(_i_brand236.data()),std::string(_s_store_name383.data()),std::string(_s_company_name395.data()),_d_year126,_d_moy128,_sum_sales3544,__w03558,_rn3546};
        rows0.push_back(t);
    }
    struct {
        bool operator()(const SW_Window_TD_7140839Row& a, const SW_Window_TD_7140839Row& b) const { return 
(a._i_category240 < b._i_category240) || 
 ((a._i_category240 == b._i_category240) && (a._i_brand236 < b._i_brand236)) || 
 ((a._i_category240 == b._i_category240) && (a._i_brand236 == b._i_brand236) && (a._s_store_name383 < b._s_store_name383)) || 
 ((a._i_category240 == b._i_category240) && (a._i_brand236 == b._i_brand236) && (a._s_store_name383 == b._s_store_name383) && (a._s_company_name395 < b._s_company_name395)) || 
 ((a._i_category240 == b._i_category240) && (a._i_brand236 == b._i_brand236) && (a._s_store_name383 == b._s_store_name383) && (a._s_company_name395 == b._s_company_name395) && (a._d_year126 < b._d_year126)); 
}
    }SW_Window_TD_7140839_order0; 

    std::sort(rows0.begin(), rows0.end(), SW_Window_TD_7140839_order0);
    int64_t sum0 = 0;
    int64_t currentRow0 = 0;
    std::string current_i_category2400 = "";
    std::string current_i_brand2360 = "";
    std::string current_s_store_name3830 = "";
    std::string current_s_company_name3950 = "";
    int32_t current_d_year1260 = std::numeric_limits<int32_t>::min();
    for (auto& it : rows0) {
        if (current_i_category2400 != it._i_category240 || current_i_brand2360 != it._i_brand236 || current_s_store_name3830 != it._s_store_name383 || current_s_company_name3950 != it._s_company_name395 || current_d_year1260 != it._d_year126) {
            sum0 = 0;
            currentRow0 = 0;
            current_i_category2400 = it._i_category240;
            current_i_brand2360 = it._i_brand236;
            current_s_store_name3830 = it._s_store_name383;
            current_s_company_name3950 = it._s_company_name395;
            current_d_year1260 = it._d_year126;
        }
        sum0 += it.__w03558;
        currentRow0 +=1;
        tbl_Window_TD_7140839_output.setInt64(r, 9, sum0 / currentRow0 );
    }
    tbl_Window_TD_7140839_output.setNumRow(r);
    std::cout << "tbl_Window_TD_7140839_output #Row: " << tbl_Window_TD_7140839_output.getNumRow() << std::endl;
}

void SW_Window_TD_6765754(Table &tbl_Aggregate_TD_7672439_output, Table &tbl_Window_TD_6765754_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Window
    // Operation: ListBuffer(rank(d_year#4466, d_moy#4468) windowspecdefinition(i_category#4427, i_brand#4423, s_store_name#4493, s_company_name#4505, d_year#4466 ASC NULLS FIRST, d_moy#4468 ASC NULLS FIRST, specifiedwindowframe(RowFrame, unboundedpreceding$(), currentrow$())) AS rn#4521)
    // Input: ListBuffer(i_category#4427, i_brand#4423, s_store_name#4493, s_company_name#4505, d_year#4466, d_moy#4468, sum_sales#3544)
    // Output: ListBuffer(i_category#4427, i_brand#4423, s_store_name#4493, s_company_name#4505, d_year#4466, d_moy#4468, sum_sales#3544, rn#4521)
    struct SW_Window_TD_6765754Row {
        std::string _i_category4427;
        std::string _i_brand4423;
        std::string _s_store_name4493;
        std::string _s_company_name4505;
        int32_t _d_year4466;
        int32_t _d_moy4468;
        int64_t _sum_sales3544;
    }; 

    int nrow = tbl_Aggregate_TD_7672439_output.getNumRow();
    std::vector<SW_Window_TD_6765754Row> rows0;
    int r = 0;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category4427 = tbl_Aggregate_TD_7672439_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        tbl_Window_TD_6765754_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _i_category4427);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand4423 = tbl_Aggregate_TD_7672439_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        tbl_Window_TD_6765754_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _i_brand4423);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name4493 = tbl_Aggregate_TD_7672439_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        tbl_Window_TD_6765754_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _s_store_name4493);
        std::array<char, TPCDS_READ_MAX + 1> _s_company_name4505 = tbl_Aggregate_TD_7672439_output.getcharN<char, TPCDS_READ_MAX +1>(i, 3);
        tbl_Window_TD_6765754_output.setcharN<char, TPCDS_READ_MAX +1>(r, 3, _s_company_name4505);
        int32_t _d_year4466 = tbl_Aggregate_TD_7672439_output.getInt32(i, 4);
        tbl_Window_TD_6765754_output.setInt32(r, 4,_d_year4466);
        int32_t _d_moy4468 = tbl_Aggregate_TD_7672439_output.getInt32(i, 5);
        tbl_Window_TD_6765754_output.setInt32(r, 5,_d_moy4468);
        int64_t _sum_sales3544 = tbl_Aggregate_TD_7672439_output.getInt64(i, 6);
        tbl_Window_TD_6765754_output.setInt64(r, 6,_sum_sales3544);
        r++;
        SW_Window_TD_6765754Row t = {std::string(_i_category4427.data()),std::string(_i_brand4423.data()),std::string(_s_store_name4493.data()),std::string(_s_company_name4505.data()),_d_year4466,_d_moy4468,_sum_sales3544};
        rows0.push_back(t);
    }
    struct {
        bool operator()(const SW_Window_TD_6765754Row& a, const SW_Window_TD_6765754Row& b) const { return 
(a._i_category4427 < b._i_category4427) || 
 ((a._i_category4427 == b._i_category4427) && (a._i_brand4423 < b._i_brand4423)) || 
 ((a._i_category4427 == b._i_category4427) && (a._i_brand4423 == b._i_brand4423) && (a._s_store_name4493 < b._s_store_name4493)) || 
 ((a._i_category4427 == b._i_category4427) && (a._i_brand4423 == b._i_brand4423) && (a._s_store_name4493 == b._s_store_name4493) && (a._s_company_name4505 < b._s_company_name4505)) || 
 ((a._i_category4427 == b._i_category4427) && (a._i_brand4423 == b._i_brand4423) && (a._s_store_name4493 == b._s_store_name4493) && (a._s_company_name4505 == b._s_company_name4505) && (a._d_year4466 < b._d_year4466)) || 
 ((a._i_category4427 == b._i_category4427) && (a._i_brand4423 == b._i_brand4423) && (a._s_store_name4493 == b._s_store_name4493) && (a._s_company_name4505 == b._s_company_name4505) && (a._d_year4466 == b._d_year4466) && (a._d_moy4468 < b._d_moy4468)); 
}
    }SW_Window_TD_6765754_order0; 

    std::sort(rows0.begin(), rows0.end(), SW_Window_TD_6765754_order0);
    std::vector<int32_t> ranks0(rows0.size(), 0);
    int32_t currentRank0 = 0;
    int32_t currentPartitionCount0 = 1;
    bool isSamePartition0 = true;
    bool isSameOrderKey0 = true;
    if (!rows0.empty()) {;
      ranks0[0] = ++currentRank0;
    };
    for (int i = 1; i< rows0.size(); i++) {
        isSamePartition0 = ( rows0[i]._i_category4427 == rows0[i-1]._i_category4427 && rows0[i]._i_brand4423 == rows0[i-1]._i_brand4423 && rows0[i]._s_store_name4493 == rows0[i-1]._s_store_name4493 && rows0[i]._s_company_name4505 == rows0[i-1]._s_company_name4505);
        isSameOrderKey0 = ( rows0[i]._d_year4466 == rows0[i-1]._d_year4466 && rows0[i]._d_moy4468 == rows0[i-1]._d_moy4468);
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
        tbl_Window_TD_6765754_output.setInt32(r, 7, ranks0[i]);
    }
    tbl_Window_TD_6765754_output.setNumRow(r);
    std::cout << "tbl_Window_TD_6765754_output #Row: " << tbl_Window_TD_6765754_output.getNumRow() << std::endl;
}

void SW_Project_TD_6359877(Table &tbl_Window_TD_74072_output, Table &tbl_Project_TD_6359877_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(sum_sales#3544 AS sum_sales#3565)
    // Input: ListBuffer(i_category#4320, i_brand#4316, s_store_name#4386, s_company_name#4398, d_year#4359, d_moy#4361, sum_sales#3544, rn#4414)
    // Output: ListBuffer(i_category#4320, i_brand#4316, s_store_name#4386, s_company_name#4398, sum_sales#3565, rn#4414)
    int nrow1 = tbl_Window_TD_74072_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category4320 = tbl_Window_TD_74072_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand4316 = tbl_Window_TD_74072_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name4386 = tbl_Window_TD_74072_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _s_company_name4398 = tbl_Window_TD_74072_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        int32_t _d_year4359 = tbl_Window_TD_74072_output.getInt32(i, 4);
        int32_t _d_moy4361 = tbl_Window_TD_74072_output.getInt32(i, 5);
        int64_t _sum_sales3544 = tbl_Window_TD_74072_output.getInt64(i, 6);
        int32_t _rn4414 = tbl_Window_TD_74072_output.getInt32(i, 7);
        int64_t _sum_sales3565 = _sum_sales3544;
        tbl_Project_TD_6359877_output.setInt64(i, 4, _sum_sales3565);
        tbl_Project_TD_6359877_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 0, _i_category4320);
        tbl_Project_TD_6359877_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 1, _i_brand4316);
        tbl_Project_TD_6359877_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 2, _s_store_name4386);
        tbl_Project_TD_6359877_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 3, _s_company_name4398);
        tbl_Project_TD_6359877_output.setInt32(i, 5, _rn4414);
    }
    tbl_Project_TD_6359877_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_6359877_output #Row: " << tbl_Project_TD_6359877_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6739433(Table &tbl_Window_TD_7140839_output, Table &tbl_Filter_TD_6739433_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(avg_monthly_sales#3545) AND (avg_monthly_sales#3545 > 0.000000)) AND (CheckOverflow((promote_precision(abs(CheckOverflow((promote_precision(cast(sum_sales#3544 as decimal(22,6))) - promote_precision(cast(avg_monthly_sales#3545 as decimal(22,6)))), DecimalType(22,6), true), false)) / promote_precision(cast(avg_monthly_sales#3545 as decimal(22,6)))), DecimalType(38,16), true) > 0.1000000000000000)))
    // Input: ListBuffer(i_category#240, i_brand#236, s_store_name#383, s_company_name#395, d_year#126, d_moy#128, sum_sales#3544, _w0#3558, rn#3546, avg_monthly_sales#3545)
    // Output: ListBuffer(i_category#240, i_brand#236, s_store_name#383, s_company_name#395, d_year#126, d_moy#128, sum_sales#3544, avg_monthly_sales#3545, rn#3546)
    int r = 0;
    int nrow1 = tbl_Window_TD_7140839_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _avg_monthly_sales3545 = tbl_Window_TD_7140839_output.getInt64(i, 9);
        int64_t _sum_sales3544 = tbl_Window_TD_7140839_output.getInt64(i, 6);
        if (((_avg_monthly_sales3545!= 0) && (_avg_monthly_sales3545 > 0.000000)) && (_sum_sales3544 > 0.1000000000000000)) {
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_t = tbl_Window_TD_7140839_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            tbl_Filter_TD_6739433_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category240_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_t = tbl_Window_TD_7140839_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_6739433_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand236_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_t = tbl_Window_TD_7140839_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_6739433_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_store_name383_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_company_name395_t = tbl_Window_TD_7140839_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_6739433_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _s_company_name395_t);
            int32_t _d_year126_t = tbl_Window_TD_7140839_output.getInt32(i, 4);
            tbl_Filter_TD_6739433_output.setInt32(r, 4, _d_year126_t);
            int32_t _d_moy128_t = tbl_Window_TD_7140839_output.getInt32(i, 5);
            tbl_Filter_TD_6739433_output.setInt32(r, 5, _d_moy128_t);
            int64_t _sum_sales3544_t = tbl_Window_TD_7140839_output.getInt64(i, 6);
            tbl_Filter_TD_6739433_output.setInt64(r, 6, _sum_sales3544_t);
            int64_t _avg_monthly_sales3545_t = tbl_Window_TD_7140839_output.getInt64(i, 9);
            tbl_Filter_TD_6739433_output.setInt64(r, 7, _avg_monthly_sales3545_t);
            int32_t _rn3546_t = tbl_Window_TD_7140839_output.getInt32(i, 8);
            tbl_Filter_TD_6739433_output.setInt32(r, 8, _rn3546_t);
            r++;
        }
    }
    tbl_Filter_TD_6739433_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6739433_output #Row: " << tbl_Filter_TD_6739433_output.getNumRow() << std::endl;
}

void SW_Project_TD_5902046(Table &tbl_Window_TD_6765754_output, Table &tbl_Project_TD_5902046_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(sum_sales#3544 AS sum_sales#3574)
    // Input: ListBuffer(i_category#4427, i_brand#4423, s_store_name#4493, s_company_name#4505, d_year#4466, d_moy#4468, sum_sales#3544, rn#4521)
    // Output: ListBuffer(i_category#4427, i_brand#4423, s_store_name#4493, s_company_name#4505, sum_sales#3574, rn#4521)
    int nrow1 = tbl_Window_TD_6765754_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category4427 = tbl_Window_TD_6765754_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand4423 = tbl_Window_TD_6765754_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name4493 = tbl_Window_TD_6765754_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _s_company_name4505 = tbl_Window_TD_6765754_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        int32_t _d_year4466 = tbl_Window_TD_6765754_output.getInt32(i, 4);
        int32_t _d_moy4468 = tbl_Window_TD_6765754_output.getInt32(i, 5);
        int64_t _sum_sales3544 = tbl_Window_TD_6765754_output.getInt64(i, 6);
        int32_t _rn4521 = tbl_Window_TD_6765754_output.getInt32(i, 7);
        int64_t _sum_sales3574 = _sum_sales3544;
        tbl_Project_TD_5902046_output.setInt64(i, 4, _sum_sales3574);
        tbl_Project_TD_5902046_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 0, _i_category4427);
        tbl_Project_TD_5902046_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 1, _i_brand4423);
        tbl_Project_TD_5902046_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 2, _s_store_name4493);
        tbl_Project_TD_5902046_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 3, _s_company_name4505);
        tbl_Project_TD_5902046_output.setInt32(i, 5, _rn4521);
    }
    tbl_Project_TD_5902046_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_5902046_output #Row: " << tbl_Project_TD_5902046_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5199655_key_leftMajor {
    std::string _i_category240;
    std::string _i_brand236;
    std::string _s_store_name383;
    std::string _s_company_name395;
    bool operator==(const SW_JOIN_INNER_TD_5199655_key_leftMajor& other) const {
        return ((_i_category240 == other._i_category240) && (_i_brand236 == other._i_brand236) && (_s_store_name383 == other._s_store_name383) && (_s_company_name395 == other._s_company_name395));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5199655_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5199655_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_category240)) + (hash<string>()(k._i_brand236)) + (hash<string>()(k._s_store_name383)) + (hash<string>()(k._s_company_name395));
    }
};
}
struct SW_JOIN_INNER_TD_5199655_payload_leftMajor {
    std::string _i_category240;
    std::string _i_brand236;
    std::string _s_store_name383;
    std::string _s_company_name395;
    int32_t _d_year126;
    int32_t _d_moy128;
    int64_t _sum_sales3544;
    int64_t _avg_monthly_sales3545;
    int32_t _rn3546;
};
struct SW_JOIN_INNER_TD_5199655_key_rightMajor {
    std::string _i_category4320;
    std::string _i_brand4316;
    std::string _s_store_name4386;
    std::string _s_company_name4398;
    bool operator==(const SW_JOIN_INNER_TD_5199655_key_rightMajor& other) const {
        return ((_i_category4320 == other._i_category4320) && (_i_brand4316 == other._i_brand4316) && (_s_store_name4386 == other._s_store_name4386) && (_s_company_name4398 == other._s_company_name4398));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5199655_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5199655_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_category4320)) + (hash<string>()(k._i_brand4316)) + (hash<string>()(k._s_store_name4386)) + (hash<string>()(k._s_company_name4398));
    }
};
}
struct SW_JOIN_INNER_TD_5199655_payload_rightMajor {
    std::string _i_category4320;
    std::string _i_brand4316;
    std::string _s_store_name4386;
    std::string _s_company_name4398;
    int64_t _sum_sales3565;
    int32_t _rn4414;
};
void SW_JOIN_INNER_TD_5199655(Table &tbl_Filter_TD_6739433_output, Table &tbl_Project_TD_6359877_output, Table &tbl_JOIN_INNER_TD_5199655_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((((((i_category#240 = i_category#4320) AND (i_brand#236 = i_brand#4316)) AND (s_store_name#383 = s_store_name#4386)) AND (s_company_name#395 = s_company_name#4398)) AND (rn#3546 = (rn#4414 + 1))))
    // Left Table: ListBuffer(i_category#240, i_brand#236, s_store_name#383, s_company_name#395, d_year#126, d_moy#128, sum_sales#3544, avg_monthly_sales#3545, rn#3546)
    // Right Table: ListBuffer(i_category#4320, i_brand#4316, s_store_name#4386, s_company_name#4398, sum_sales#3565, rn#4414)
    // Output Table: ListBuffer(i_category#240, i_brand#236, s_store_name#383, s_company_name#395, d_year#126, d_moy#128, sum_sales#3544, avg_monthly_sales#3545, rn#3546, sum_sales#3565)
    int left_nrow = tbl_Filter_TD_6739433_output.getNumRow();
    int right_nrow = tbl_Project_TD_6359877_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5199655_key_leftMajor, SW_JOIN_INNER_TD_5199655_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_6739433_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_k_n = tbl_Filter_TD_6739433_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_category240_k = std::string(_i_category240_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_k_n = tbl_Filter_TD_6739433_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand236_k = std::string(_i_brand236_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_k_n = tbl_Filter_TD_6739433_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _s_store_name383_k = std::string(_s_store_name383_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_company_name395_k_n = tbl_Filter_TD_6739433_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _s_company_name395_k = std::string(_s_company_name395_k_n.data());
            SW_JOIN_INNER_TD_5199655_key_leftMajor keyA{_i_category240_k, _i_brand236_k, _s_store_name383_k, _s_company_name395_k};
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_Filter_TD_6739433_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_category240 = std::string(_i_category240_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_Filter_TD_6739433_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand236 = std::string(_i_brand236_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_Filter_TD_6739433_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _s_store_name383 = std::string(_s_store_name383_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_company_name395_n = tbl_Filter_TD_6739433_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _s_company_name395 = std::string(_s_company_name395_n.data());
            int32_t _d_year126 = tbl_Filter_TD_6739433_output.getInt32(i, 4);
            int32_t _d_moy128 = tbl_Filter_TD_6739433_output.getInt32(i, 5);
            int64_t _sum_sales3544 = tbl_Filter_TD_6739433_output.getInt64(i, 6);
            int64_t _avg_monthly_sales3545 = tbl_Filter_TD_6739433_output.getInt64(i, 7);
            int32_t _rn3546 = tbl_Filter_TD_6739433_output.getInt32(i, 8);
            SW_JOIN_INNER_TD_5199655_payload_leftMajor payloadA{_i_category240, _i_brand236, _s_store_name383, _s_company_name395, _d_year126, _d_moy128, _sum_sales3544, _avg_monthly_sales3545, _rn3546};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Project_TD_6359877_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_category4320_k_n = tbl_Project_TD_6359877_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_category4320_k = std::string(_i_category4320_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4316_k_n = tbl_Project_TD_6359877_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand4316_k = std::string(_i_brand4316_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name4386_k_n = tbl_Project_TD_6359877_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _s_store_name4386_k = std::string(_s_store_name4386_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_company_name4398_k_n = tbl_Project_TD_6359877_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _s_company_name4398_k = std::string(_s_company_name4398_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5199655_key_leftMajor{_i_category4320_k, _i_brand4316_k, _s_store_name4386_k, _s_company_name4398_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _i_category240 = (it->second)._i_category240;
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n{};
                memcpy(_i_category240_n.data(), (_i_category240).data(), (_i_category240).length());
                std::string _i_brand236 = (it->second)._i_brand236;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n{};
                memcpy(_i_brand236_n.data(), (_i_brand236).data(), (_i_brand236).length());
                std::string _s_store_name383 = (it->second)._s_store_name383;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n{};
                memcpy(_s_store_name383_n.data(), (_s_store_name383).data(), (_s_store_name383).length());
                std::string _s_company_name395 = (it->second)._s_company_name395;
                std::array<char, TPCDS_READ_MAX + 1> _s_company_name395_n{};
                memcpy(_s_company_name395_n.data(), (_s_company_name395).data(), (_s_company_name395).length());
                int32_t _d_year126 = (it->second)._d_year126;
                int32_t _d_moy128 = (it->second)._d_moy128;
                int64_t _sum_sales3544 = (it->second)._sum_sales3544;
                int64_t _avg_monthly_sales3545 = (it->second)._avg_monthly_sales3545;
                int32_t _rn3546 = (it->second)._rn3546;
                std::array<char, TPCDS_READ_MAX + 1> _i_category4320_n = tbl_Project_TD_6359877_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _i_category4320 = std::string(_i_category4320_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4316_n = tbl_Project_TD_6359877_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_brand4316 = std::string(_i_brand4316_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4386_n = tbl_Project_TD_6359877_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _s_store_name4386 = std::string(_s_store_name4386_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_company_name4398_n = tbl_Project_TD_6359877_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _s_company_name4398 = std::string(_s_company_name4398_n.data());
                int64_t _sum_sales3565 = tbl_Project_TD_6359877_output.getInt64(i, 4);
                int32_t _rn4414 = tbl_Project_TD_6359877_output.getInt32(i, 5);
                if (_rn3546 == NULL) {
                    tbl_JOIN_INNER_TD_5199655_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category240_n);
                    tbl_JOIN_INNER_TD_5199655_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand236_n);
                    tbl_JOIN_INNER_TD_5199655_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_store_name383_n);
                    tbl_JOIN_INNER_TD_5199655_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _s_company_name395_n);
                    tbl_JOIN_INNER_TD_5199655_output.setInt32(r, 4, _d_year126);
                    tbl_JOIN_INNER_TD_5199655_output.setInt32(r, 5, _d_moy128);
                    tbl_JOIN_INNER_TD_5199655_output.setInt64(r, 6, _sum_sales3544);
                    tbl_JOIN_INNER_TD_5199655_output.setInt64(r, 7, _avg_monthly_sales3545);
                    tbl_JOIN_INNER_TD_5199655_output.setInt32(r, 8, _rn3546);
                    tbl_JOIN_INNER_TD_5199655_output.setInt64(r, 9, _sum_sales3565);
                    r++;
                }
                it++;
            }
        }
        tbl_JOIN_INNER_TD_5199655_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5199655_key_rightMajor, SW_JOIN_INNER_TD_5199655_payload_rightMajor> ht1;
        int nrow1 = tbl_Project_TD_6359877_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_category4320_k_n = tbl_Project_TD_6359877_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_category4320_k = std::string(_i_category4320_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4316_k_n = tbl_Project_TD_6359877_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand4316_k = std::string(_i_brand4316_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name4386_k_n = tbl_Project_TD_6359877_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _s_store_name4386_k = std::string(_s_store_name4386_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_company_name4398_k_n = tbl_Project_TD_6359877_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _s_company_name4398_k = std::string(_s_company_name4398_k_n.data());
            SW_JOIN_INNER_TD_5199655_key_rightMajor keyA{_i_category4320_k, _i_brand4316_k, _s_store_name4386_k, _s_company_name4398_k};
            std::array<char, TPCDS_READ_MAX + 1> _i_category4320_n = tbl_Project_TD_6359877_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_category4320 = std::string(_i_category4320_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4316_n = tbl_Project_TD_6359877_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand4316 = std::string(_i_brand4316_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name4386_n = tbl_Project_TD_6359877_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _s_store_name4386 = std::string(_s_store_name4386_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_company_name4398_n = tbl_Project_TD_6359877_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _s_company_name4398 = std::string(_s_company_name4398_n.data());
            int64_t _sum_sales3565 = tbl_Project_TD_6359877_output.getInt64(i, 4);
            int32_t _rn4414 = tbl_Project_TD_6359877_output.getInt32(i, 5);
            SW_JOIN_INNER_TD_5199655_payload_rightMajor payloadA{_i_category4320, _i_brand4316, _s_store_name4386, _s_company_name4398, _sum_sales3565, _rn4414};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6739433_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_k_n = tbl_Filter_TD_6739433_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_category240_k = std::string(_i_category240_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_k_n = tbl_Filter_TD_6739433_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand236_k = std::string(_i_brand236_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_k_n = tbl_Filter_TD_6739433_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _s_store_name383_k = std::string(_s_store_name383_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_company_name395_k_n = tbl_Filter_TD_6739433_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _s_company_name395_k = std::string(_s_company_name395_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5199655_key_rightMajor{_i_category240_k, _i_brand236_k, _s_store_name383_k, _s_company_name395_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _i_category4320 = (it->second)._i_category4320;
                std::array<char, TPCDS_READ_MAX + 1> _i_category4320_n{};
                memcpy(_i_category4320_n.data(), (_i_category4320).data(), (_i_category4320).length());
                std::string _i_brand4316 = (it->second)._i_brand4316;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4316_n{};
                memcpy(_i_brand4316_n.data(), (_i_brand4316).data(), (_i_brand4316).length());
                std::string _s_store_name4386 = (it->second)._s_store_name4386;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4386_n{};
                memcpy(_s_store_name4386_n.data(), (_s_store_name4386).data(), (_s_store_name4386).length());
                std::string _s_company_name4398 = (it->second)._s_company_name4398;
                std::array<char, TPCDS_READ_MAX + 1> _s_company_name4398_n{};
                memcpy(_s_company_name4398_n.data(), (_s_company_name4398).data(), (_s_company_name4398).length());
                int64_t _sum_sales3565 = (it->second)._sum_sales3565;
                int32_t _rn4414 = (it->second)._rn4414;
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_Filter_TD_6739433_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _i_category240 = std::string(_i_category240_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_Filter_TD_6739433_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_brand236 = std::string(_i_brand236_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_Filter_TD_6739433_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _s_store_name383 = std::string(_s_store_name383_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_company_name395_n = tbl_Filter_TD_6739433_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _s_company_name395 = std::string(_s_company_name395_n.data());
                int32_t _d_year126 = tbl_Filter_TD_6739433_output.getInt32(i, 4);
                int32_t _d_moy128 = tbl_Filter_TD_6739433_output.getInt32(i, 5);
                int64_t _sum_sales3544 = tbl_Filter_TD_6739433_output.getInt64(i, 6);
                int64_t _avg_monthly_sales3545 = tbl_Filter_TD_6739433_output.getInt64(i, 7);
                int32_t _rn3546 = tbl_Filter_TD_6739433_output.getInt32(i, 8);
                if (_rn3546 == NULL) {
                    tbl_JOIN_INNER_TD_5199655_output.setInt64(r, 9, _sum_sales3565);
                    tbl_JOIN_INNER_TD_5199655_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category240_n);
                    tbl_JOIN_INNER_TD_5199655_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand236_n);
                    tbl_JOIN_INNER_TD_5199655_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_store_name383_n);
                    tbl_JOIN_INNER_TD_5199655_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _s_company_name395_n);
                    tbl_JOIN_INNER_TD_5199655_output.setInt32(r, 4, _d_year126);
                    tbl_JOIN_INNER_TD_5199655_output.setInt32(r, 5, _d_moy128);
                    tbl_JOIN_INNER_TD_5199655_output.setInt64(r, 6, _sum_sales3544);
                    tbl_JOIN_INNER_TD_5199655_output.setInt64(r, 7, _avg_monthly_sales3545);
                    tbl_JOIN_INNER_TD_5199655_output.setInt32(r, 8, _rn3546);
                    r++;
                }
                it++;
            }
        }
        tbl_JOIN_INNER_TD_5199655_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5199655_output #Row: " << tbl_JOIN_INNER_TD_5199655_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4503684_key_leftMajor {
    std::string _i_category240;
    std::string _i_brand236;
    std::string _s_store_name383;
    std::string _s_company_name395;
    int32_t _rn3546;
    bool operator==(const SW_JOIN_INNER_TD_4503684_key_leftMajor& other) const {
        return ((_i_category240 == other._i_category240) && (_i_brand236 == other._i_brand236) && (_s_store_name383 == other._s_store_name383) && (_s_company_name395 == other._s_company_name395) && (_rn3546 == other._rn3546));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4503684_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4503684_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_category240)) + (hash<string>()(k._i_brand236)) + (hash<string>()(k._s_store_name383)) + (hash<string>()(k._s_company_name395)) + (hash<int32_t>()(k._rn3546));
    }
};
}
struct SW_JOIN_INNER_TD_4503684_payload_leftMajor {
    std::string _i_category240;
    std::string _i_brand236;
    std::string _s_store_name383;
    std::string _s_company_name395;
    int32_t _d_year126;
    int32_t _d_moy128;
    int64_t _sum_sales3544;
    int64_t _avg_monthly_sales3545;
    int32_t _rn3546;
    int64_t _sum_sales3565;
};
struct SW_JOIN_INNER_TD_4503684_key_rightMajor {
    std::string _i_category4427;
    std::string _i_brand4423;
    std::string _s_store_name4493;
    std::string _s_company_name4505;
    int32_t _rn4521;
    bool operator==(const SW_JOIN_INNER_TD_4503684_key_rightMajor& other) const {
        return ((_i_category4427 == other._i_category4427) && (_i_brand4423 == other._i_brand4423) && (_s_store_name4493 == other._s_store_name4493) && (_s_company_name4505 == other._s_company_name4505) && (_rn4521 == other._rn4521));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4503684_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4503684_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_category4427)) + (hash<string>()(k._i_brand4423)) + (hash<string>()(k._s_store_name4493)) + (hash<string>()(k._s_company_name4505)) + (hash<int32_t>()(k._rn4521));
    }
};
}
struct SW_JOIN_INNER_TD_4503684_payload_rightMajor {
    std::string _i_category4427;
    std::string _i_brand4423;
    std::string _s_store_name4493;
    std::string _s_company_name4505;
    int64_t _sum_sales3574;
    int32_t _rn4521;
};
void SW_JOIN_INNER_TD_4503684(Table &tbl_JOIN_INNER_TD_5199655_output, Table &tbl_Project_TD_5902046_output, Table &tbl_JOIN_INNER_TD_4503684_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((((((i_category#240 = i_category#4427) AND (i_brand#236 = i_brand#4423)) AND (s_store_name#383 = s_store_name#4493)) AND (s_company_name#395 = s_company_name#4505)) AND (rn#3546 = (rn#4521 - 1))))
    // Left Table: ListBuffer(i_category#240, i_brand#236, s_store_name#383, s_company_name#395, d_year#126, d_moy#128, sum_sales#3544, avg_monthly_sales#3545, rn#3546, sum_sales#3565)
    // Right Table: ListBuffer(i_category#4427, i_brand#4423, s_store_name#4493, s_company_name#4505, sum_sales#3574, rn#4521)
    // Output Table: ListBuffer(i_category#240, i_brand#236, s_store_name#383, s_company_name#395, d_year#126, d_moy#128, avg_monthly_sales#3545, sum_sales#3544, sum_sales#3565, sum_sales#3574)
    int left_nrow = tbl_JOIN_INNER_TD_5199655_output.getNumRow();
    int right_nrow = tbl_Project_TD_5902046_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4503684_key_leftMajor, SW_JOIN_INNER_TD_4503684_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_5199655_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_k_n = tbl_JOIN_INNER_TD_5199655_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_category240_k = std::string(_i_category240_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_k_n = tbl_JOIN_INNER_TD_5199655_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand236_k = std::string(_i_brand236_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_k_n = tbl_JOIN_INNER_TD_5199655_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _s_store_name383_k = std::string(_s_store_name383_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_company_name395_k_n = tbl_JOIN_INNER_TD_5199655_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _s_company_name395_k = std::string(_s_company_name395_k_n.data());
            int32_t _rn3546_k = tbl_JOIN_INNER_TD_5199655_output.getInt32(i, 8);
            SW_JOIN_INNER_TD_4503684_key_leftMajor keyA{_i_category240_k, _i_brand236_k, _s_store_name383_k, _s_company_name395_k, _rn3546_k};
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_JOIN_INNER_TD_5199655_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_category240 = std::string(_i_category240_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_JOIN_INNER_TD_5199655_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand236 = std::string(_i_brand236_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_5199655_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _s_store_name383 = std::string(_s_store_name383_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_company_name395_n = tbl_JOIN_INNER_TD_5199655_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _s_company_name395 = std::string(_s_company_name395_n.data());
            int32_t _d_year126 = tbl_JOIN_INNER_TD_5199655_output.getInt32(i, 4);
            int32_t _d_moy128 = tbl_JOIN_INNER_TD_5199655_output.getInt32(i, 5);
            int64_t _sum_sales3544 = tbl_JOIN_INNER_TD_5199655_output.getInt64(i, 6);
            int64_t _avg_monthly_sales3545 = tbl_JOIN_INNER_TD_5199655_output.getInt64(i, 7);
            int32_t _rn3546 = tbl_JOIN_INNER_TD_5199655_output.getInt32(i, 8);
            int64_t _sum_sales3565 = tbl_JOIN_INNER_TD_5199655_output.getInt64(i, 9);
            SW_JOIN_INNER_TD_4503684_payload_leftMajor payloadA{_i_category240, _i_brand236, _s_store_name383, _s_company_name395, _d_year126, _d_moy128, _sum_sales3544, _avg_monthly_sales3545, _rn3546, _sum_sales3565};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Project_TD_5902046_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_category4427_k_n = tbl_Project_TD_5902046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_category4427_k = std::string(_i_category4427_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4423_k_n = tbl_Project_TD_5902046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand4423_k = std::string(_i_brand4423_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name4493_k_n = tbl_Project_TD_5902046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _s_store_name4493_k = std::string(_s_store_name4493_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_company_name4505_k_n = tbl_Project_TD_5902046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _s_company_name4505_k = std::string(_s_company_name4505_k_n.data());
            int32_t _rn4521_k = tbl_Project_TD_5902046_output.getInt32(i, 5);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4503684_key_leftMajor{_i_category4427_k, _i_brand4423_k, _s_store_name4493_k, _s_company_name4505_k, _rn4521_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _i_category240 = (it->second)._i_category240;
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n{};
                memcpy(_i_category240_n.data(), (_i_category240).data(), (_i_category240).length());
                std::string _i_brand236 = (it->second)._i_brand236;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n{};
                memcpy(_i_brand236_n.data(), (_i_brand236).data(), (_i_brand236).length());
                std::string _s_store_name383 = (it->second)._s_store_name383;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n{};
                memcpy(_s_store_name383_n.data(), (_s_store_name383).data(), (_s_store_name383).length());
                std::string _s_company_name395 = (it->second)._s_company_name395;
                std::array<char, TPCDS_READ_MAX + 1> _s_company_name395_n{};
                memcpy(_s_company_name395_n.data(), (_s_company_name395).data(), (_s_company_name395).length());
                int32_t _d_year126 = (it->second)._d_year126;
                int32_t _d_moy128 = (it->second)._d_moy128;
                int64_t _sum_sales3544 = (it->second)._sum_sales3544;
                int64_t _avg_monthly_sales3545 = (it->second)._avg_monthly_sales3545;
                int32_t _rn3546 = (it->second)._rn3546;
                int64_t _sum_sales3565 = (it->second)._sum_sales3565;
                std::array<char, TPCDS_READ_MAX + 1> _i_category4427_n = tbl_Project_TD_5902046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _i_category4427 = std::string(_i_category4427_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4423_n = tbl_Project_TD_5902046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_brand4423 = std::string(_i_brand4423_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4493_n = tbl_Project_TD_5902046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _s_store_name4493 = std::string(_s_store_name4493_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_company_name4505_n = tbl_Project_TD_5902046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _s_company_name4505 = std::string(_s_company_name4505_n.data());
                int64_t _sum_sales3574 = tbl_Project_TD_5902046_output.getInt64(i, 4);
                int32_t _rn4521 = tbl_Project_TD_5902046_output.getInt32(i, 5);
                if (_rn3546 == (_rn4521 - 1)) {
                    tbl_JOIN_INNER_TD_4503684_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category240_n);
                    tbl_JOIN_INNER_TD_4503684_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand236_n);
                    tbl_JOIN_INNER_TD_4503684_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_store_name383_n);
                    tbl_JOIN_INNER_TD_4503684_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _s_company_name395_n);
                    tbl_JOIN_INNER_TD_4503684_output.setInt32(r, 4, _d_year126);
                    tbl_JOIN_INNER_TD_4503684_output.setInt32(r, 5, _d_moy128);
                    tbl_JOIN_INNER_TD_4503684_output.setInt64(r, 7, _sum_sales3544);
                    tbl_JOIN_INNER_TD_4503684_output.setInt64(r, 6, _avg_monthly_sales3545);
                    tbl_JOIN_INNER_TD_4503684_output.setInt64(r, 8, _sum_sales3565);
                    tbl_JOIN_INNER_TD_4503684_output.setInt64(r, 9, _sum_sales3574);
                    r++;
                }
                it++;
            }
        }
        tbl_JOIN_INNER_TD_4503684_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4503684_key_rightMajor, SW_JOIN_INNER_TD_4503684_payload_rightMajor> ht1;
        int nrow1 = tbl_Project_TD_5902046_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_category4427_k_n = tbl_Project_TD_5902046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_category4427_k = std::string(_i_category4427_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4423_k_n = tbl_Project_TD_5902046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand4423_k = std::string(_i_brand4423_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name4493_k_n = tbl_Project_TD_5902046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _s_store_name4493_k = std::string(_s_store_name4493_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_company_name4505_k_n = tbl_Project_TD_5902046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _s_company_name4505_k = std::string(_s_company_name4505_k_n.data());
            int32_t _rn4521_k = tbl_Project_TD_5902046_output.getInt32(i, 5);
            SW_JOIN_INNER_TD_4503684_key_rightMajor keyA{_i_category4427_k, _i_brand4423_k, _s_store_name4493_k, _s_company_name4505_k, _rn4521_k};
            std::array<char, TPCDS_READ_MAX + 1> _i_category4427_n = tbl_Project_TD_5902046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_category4427 = std::string(_i_category4427_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4423_n = tbl_Project_TD_5902046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand4423 = std::string(_i_brand4423_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name4493_n = tbl_Project_TD_5902046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _s_store_name4493 = std::string(_s_store_name4493_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_company_name4505_n = tbl_Project_TD_5902046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _s_company_name4505 = std::string(_s_company_name4505_n.data());
            int64_t _sum_sales3574 = tbl_Project_TD_5902046_output.getInt64(i, 4);
            int32_t _rn4521 = tbl_Project_TD_5902046_output.getInt32(i, 5);
            SW_JOIN_INNER_TD_4503684_payload_rightMajor payloadA{_i_category4427, _i_brand4423, _s_store_name4493, _s_company_name4505, _sum_sales3574, _rn4521};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_5199655_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_k_n = tbl_JOIN_INNER_TD_5199655_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_category240_k = std::string(_i_category240_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_k_n = tbl_JOIN_INNER_TD_5199655_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand236_k = std::string(_i_brand236_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_k_n = tbl_JOIN_INNER_TD_5199655_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _s_store_name383_k = std::string(_s_store_name383_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_company_name395_k_n = tbl_JOIN_INNER_TD_5199655_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _s_company_name395_k = std::string(_s_company_name395_k_n.data());
            int32_t _rn3546_k = tbl_JOIN_INNER_TD_5199655_output.getInt32(i, 8);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4503684_key_rightMajor{_i_category240_k, _i_brand236_k, _s_store_name383_k, _s_company_name395_k, _rn3546_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _i_category4427 = (it->second)._i_category4427;
                std::array<char, TPCDS_READ_MAX + 1> _i_category4427_n{};
                memcpy(_i_category4427_n.data(), (_i_category4427).data(), (_i_category4427).length());
                std::string _i_brand4423 = (it->second)._i_brand4423;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4423_n{};
                memcpy(_i_brand4423_n.data(), (_i_brand4423).data(), (_i_brand4423).length());
                std::string _s_store_name4493 = (it->second)._s_store_name4493;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4493_n{};
                memcpy(_s_store_name4493_n.data(), (_s_store_name4493).data(), (_s_store_name4493).length());
                std::string _s_company_name4505 = (it->second)._s_company_name4505;
                std::array<char, TPCDS_READ_MAX + 1> _s_company_name4505_n{};
                memcpy(_s_company_name4505_n.data(), (_s_company_name4505).data(), (_s_company_name4505).length());
                int64_t _sum_sales3574 = (it->second)._sum_sales3574;
                int32_t _rn4521 = (it->second)._rn4521;
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_JOIN_INNER_TD_5199655_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _i_category240 = std::string(_i_category240_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_JOIN_INNER_TD_5199655_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_brand236 = std::string(_i_brand236_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_5199655_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _s_store_name383 = std::string(_s_store_name383_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_company_name395_n = tbl_JOIN_INNER_TD_5199655_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _s_company_name395 = std::string(_s_company_name395_n.data());
                int32_t _d_year126 = tbl_JOIN_INNER_TD_5199655_output.getInt32(i, 4);
                int32_t _d_moy128 = tbl_JOIN_INNER_TD_5199655_output.getInt32(i, 5);
                int64_t _sum_sales3544 = tbl_JOIN_INNER_TD_5199655_output.getInt64(i, 6);
                int64_t _avg_monthly_sales3545 = tbl_JOIN_INNER_TD_5199655_output.getInt64(i, 7);
                int32_t _rn3546 = tbl_JOIN_INNER_TD_5199655_output.getInt32(i, 8);
                int64_t _sum_sales3565 = tbl_JOIN_INNER_TD_5199655_output.getInt64(i, 9);
                if (_rn3546 == (_rn4521 - 1)) {
                    tbl_JOIN_INNER_TD_4503684_output.setInt64(r, 9, _sum_sales3574);
                    tbl_JOIN_INNER_TD_4503684_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category240_n);
                    tbl_JOIN_INNER_TD_4503684_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand236_n);
                    tbl_JOIN_INNER_TD_4503684_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_store_name383_n);
                    tbl_JOIN_INNER_TD_4503684_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _s_company_name395_n);
                    tbl_JOIN_INNER_TD_4503684_output.setInt32(r, 4, _d_year126);
                    tbl_JOIN_INNER_TD_4503684_output.setInt32(r, 5, _d_moy128);
                    tbl_JOIN_INNER_TD_4503684_output.setInt64(r, 7, _sum_sales3544);
                    tbl_JOIN_INNER_TD_4503684_output.setInt64(r, 6, _avg_monthly_sales3545);
                    tbl_JOIN_INNER_TD_4503684_output.setInt64(r, 8, _sum_sales3565);
                    r++;
                }
                it++;
            }
        }
        tbl_JOIN_INNER_TD_4503684_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4503684_output #Row: " << tbl_JOIN_INNER_TD_4503684_output.getNumRow() << std::endl;
}

void SW_Project_TD_3149367(Table &tbl_JOIN_INNER_TD_4503684_output, Table &tbl_Project_TD_3149367_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(sum_sales#3565 AS psum#3547, sum_sales#3574 AS nsum#3548)
    // Input: ListBuffer(i_category#240, i_brand#236, s_store_name#383, s_company_name#395, d_year#126, d_moy#128, avg_monthly_sales#3545, sum_sales#3544, sum_sales#3565, sum_sales#3574)
    // Output: ListBuffer(i_category#240, i_brand#236, s_store_name#383, s_company_name#395, d_year#126, d_moy#128, avg_monthly_sales#3545, sum_sales#3544, psum#3547, nsum#3548)
    int nrow1 = tbl_JOIN_INNER_TD_4503684_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category240 = tbl_JOIN_INNER_TD_4503684_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236 = tbl_JOIN_INNER_TD_4503684_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383 = tbl_JOIN_INNER_TD_4503684_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _s_company_name395 = tbl_JOIN_INNER_TD_4503684_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        int32_t _d_year126 = tbl_JOIN_INNER_TD_4503684_output.getInt32(i, 4);
        int32_t _d_moy128 = tbl_JOIN_INNER_TD_4503684_output.getInt32(i, 5);
        int64_t _avg_monthly_sales3545 = tbl_JOIN_INNER_TD_4503684_output.getInt64(i, 6);
        int64_t _sum_sales3544 = tbl_JOIN_INNER_TD_4503684_output.getInt64(i, 7);
        int64_t _sum_sales3565 = tbl_JOIN_INNER_TD_4503684_output.getInt64(i, 8);
        int64_t _sum_sales3574 = tbl_JOIN_INNER_TD_4503684_output.getInt64(i, 9);
        int64_t _psum3547 = _sum_sales3565;
        tbl_Project_TD_3149367_output.setInt64(i, 8, _psum3547);
        int64_t _nsum3548 = _sum_sales3574;
        tbl_Project_TD_3149367_output.setInt64(i, 9, _nsum3548);
        tbl_Project_TD_3149367_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 0, _i_category240);
        tbl_Project_TD_3149367_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 1, _i_brand236);
        tbl_Project_TD_3149367_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 2, _s_store_name383);
        tbl_Project_TD_3149367_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 3, _s_company_name395);
        tbl_Project_TD_3149367_output.setInt32(i, 4, _d_year126);
        tbl_Project_TD_3149367_output.setInt32(i, 5, _d_moy128);
        tbl_Project_TD_3149367_output.setInt64(i, 6, _avg_monthly_sales3545);
        tbl_Project_TD_3149367_output.setInt64(i, 7, _sum_sales3544);
    }
    tbl_Project_TD_3149367_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_3149367_output #Row: " << tbl_Project_TD_3149367_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2151559(Table &tbl_Project_TD_3149367_output, Table &tbl_Sort_TD_2151559_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(CheckOverflow((promote_precision(cast(sum_sales#3544 as decimal(22,6))) - promote_precision(cast(avg_monthly_sales#3545 as decimal(22,6)))), DecimalType(22,6), true) ASC NULLS FIRST, s_store_name#383 ASC NULLS FIRST)
    // Input: ListBuffer(i_category#240, i_brand#236, s_store_name#383, s_company_name#395, d_year#126, d_moy#128, avg_monthly_sales#3545, sum_sales#3544, psum#3547, nsum#3548)
    // Output: ListBuffer(i_category#240, i_brand#236, s_store_name#383, s_company_name#395, d_year#126, d_moy#128, avg_monthly_sales#3545, sum_sales#3544, psum#3547, nsum#3548)
    struct SW_Sort_TD_2151559Row {
        std::string _i_category240;
        std::string _i_brand236;
        std::string _s_store_name383;
        std::string _s_company_name395;
        int32_t _d_year126;
        int32_t _d_moy128;
        int64_t _avg_monthly_sales3545;
        int64_t _sum_sales3544;
        int64_t _psum3547;
        int64_t _nsum3548;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2151559Row& a, const SW_Sort_TD_2151559Row& b) const { return 
 (a._true < b._true) || 
 ((a._true == b._true) && (a._s_store_name383 < b._s_store_name383)); 
}
    }SW_Sort_TD_2151559_order; 

    int nrow1 = tbl_Project_TD_3149367_output.getNumRow();
    std::vector<SW_Sort_TD_2151559Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category240 = tbl_Project_TD_3149367_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236 = tbl_Project_TD_3149367_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383 = tbl_Project_TD_3149367_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _s_company_name395 = tbl_Project_TD_3149367_output.getcharN<char, TPCDS_READ_MAX +1>(i, 3);
        int32_t _d_year126 = tbl_Project_TD_3149367_output.getInt32(i, 4);
        int32_t _d_moy128 = tbl_Project_TD_3149367_output.getInt32(i, 5);
        int64_t _avg_monthly_sales3545 = tbl_Project_TD_3149367_output.getInt64(i, 6);
        int64_t _sum_sales3544 = tbl_Project_TD_3149367_output.getInt64(i, 7);
        int64_t _psum3547 = tbl_Project_TD_3149367_output.getInt64(i, 8);
        int64_t _nsum3548 = tbl_Project_TD_3149367_output.getInt64(i, 9);
        SW_Sort_TD_2151559Row t = {std::string(_i_category240.data()),std::string(_i_brand236.data()),std::string(_s_store_name383.data()),std::string(_s_company_name395.data()),_d_year126,_d_moy128,_avg_monthly_sales3545,_sum_sales3544,_psum3547,_nsum3548};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2151559_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category240{};
        memcpy(_i_category240.data(), (it._i_category240).data(), (it._i_category240).length());
        tbl_Sort_TD_2151559_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _i_category240);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236{};
        memcpy(_i_brand236.data(), (it._i_brand236).data(), (it._i_brand236).length());
        tbl_Sort_TD_2151559_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _i_brand236);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383{};
        memcpy(_s_store_name383.data(), (it._s_store_name383).data(), (it._s_store_name383).length());
        tbl_Sort_TD_2151559_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _s_store_name383);
        std::array<char, TPCDS_READ_MAX + 1> _s_company_name395{};
        memcpy(_s_company_name395.data(), (it._s_company_name395).data(), (it._s_company_name395).length());
        tbl_Sort_TD_2151559_output.setcharN<char, TPCDS_READ_MAX +1>(r, 3, _s_company_name395);
        tbl_Sort_TD_2151559_output.setInt32(r, 4, it._d_year126);
        tbl_Sort_TD_2151559_output.setInt32(r, 5, it._d_moy128);
        tbl_Sort_TD_2151559_output.setInt64(r, 6, it._avg_monthly_sales3545);
        tbl_Sort_TD_2151559_output.setInt64(r, 7, it._sum_sales3544);
        tbl_Sort_TD_2151559_output.setInt64(r, 8, it._psum3547);
        tbl_Sort_TD_2151559_output.setInt64(r, 9, it._nsum3548);
        ++r;
    }
    tbl_Sort_TD_2151559_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2151559_output #Row: " << tbl_Sort_TD_2151559_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1597577(Table &tbl_Sort_TD_2151559_output, Table &tbl_LocalLimit_TD_1597577_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(i_category#240, i_brand#236, s_store_name#383, s_company_name#395, d_year#126, d_moy#128, avg_monthly_sales#3545, sum_sales#3544, psum#3547, nsum#3548)
    // Output: ListBuffer(i_category#240, i_brand#236, s_store_name#383, s_company_name#395, d_year#126, d_moy#128, avg_monthly_sales#3545, sum_sales#3544, psum#3547, nsum#3548)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_Sort_TD_2151559_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1597577_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category240_n);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_Sort_TD_2151559_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_1597577_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand236_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_Sort_TD_2151559_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_LocalLimit_TD_1597577_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_store_name383_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_company_name395_n = tbl_Sort_TD_2151559_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_LocalLimit_TD_1597577_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _s_company_name395_n);
        tbl_LocalLimit_TD_1597577_output.setInt32(r, 4, tbl_Sort_TD_2151559_output.getInt32(i, 4));
        tbl_LocalLimit_TD_1597577_output.setInt32(r, 5, tbl_Sort_TD_2151559_output.getInt32(i, 5));
        tbl_LocalLimit_TD_1597577_output.setInt64(r, 6, tbl_Sort_TD_2151559_output.getInt64(i, 6));
        tbl_LocalLimit_TD_1597577_output.setInt64(r, 7, tbl_Sort_TD_2151559_output.getInt64(i, 7));
        tbl_LocalLimit_TD_1597577_output.setInt64(r, 8, tbl_Sort_TD_2151559_output.getInt64(i, 8));
        tbl_LocalLimit_TD_1597577_output.setInt64(r, 9, tbl_Sort_TD_2151559_output.getInt64(i, 9));
        r++;
    }
    tbl_LocalLimit_TD_1597577_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1597577_output #Row: " << tbl_LocalLimit_TD_1597577_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0457744(Table &tbl_LocalLimit_TD_1597577_output, Table &tbl_GlobalLimit_TD_0457744_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(i_category#240, i_brand#236, s_store_name#383, s_company_name#395, d_year#126, d_moy#128, avg_monthly_sales#3545, sum_sales#3544, psum#3547, nsum#3548)
    // Output: ListBuffer(i_category#240, i_brand#236, s_store_name#383, s_company_name#395, d_year#126, d_moy#128, avg_monthly_sales#3545, sum_sales#3544, psum#3547, nsum#3548)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_LocalLimit_TD_1597577_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0457744_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category240_n);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_LocalLimit_TD_1597577_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_0457744_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand236_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_LocalLimit_TD_1597577_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_GlobalLimit_TD_0457744_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_store_name383_n);
        std::array<char, TPCDS_READ_MAX + 1> _s_company_name395_n = tbl_LocalLimit_TD_1597577_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_GlobalLimit_TD_0457744_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _s_company_name395_n);
        tbl_GlobalLimit_TD_0457744_output.setInt32(r, 4, tbl_LocalLimit_TD_1597577_output.getInt32(i, 4));
        tbl_GlobalLimit_TD_0457744_output.setInt32(r, 5, tbl_LocalLimit_TD_1597577_output.getInt32(i, 5));
        tbl_GlobalLimit_TD_0457744_output.setInt64(r, 6, tbl_LocalLimit_TD_1597577_output.getInt64(i, 6));
        tbl_GlobalLimit_TD_0457744_output.setInt64(r, 7, tbl_LocalLimit_TD_1597577_output.getInt64(i, 7));
        tbl_GlobalLimit_TD_0457744_output.setInt64(r, 8, tbl_LocalLimit_TD_1597577_output.getInt64(i, 8));
        tbl_GlobalLimit_TD_0457744_output.setInt64(r, 9, tbl_LocalLimit_TD_1597577_output.getInt64(i, 9));
        r++;
    }
    tbl_GlobalLimit_TD_0457744_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0457744_output #Row: " << tbl_GlobalLimit_TD_0457744_output.getNumRow() << std::endl;
}

