#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_6116806(Table &tbl_SerializeFromObject_TD_7317535_input, Table &tbl_Filter_TD_6116806_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_sold_date_sk#1206) AND isnotnull(ss_item_sk#1208)))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_ext_sales_price#1221)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_ext_sales_price#1221)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7317535_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_7317535_input.getInt32(i, 0);
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_7317535_input.getInt32(i, 1);
        if ((_ss_sold_date_sk1206!= 0) && (_ss_item_sk1208!= 0)) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_7317535_input.getInt32(i, 0);
            tbl_Filter_TD_6116806_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_7317535_input.getInt32(i, 1);
            tbl_Filter_TD_6116806_output.setInt32(r, 1, _ss_item_sk1208_t);
            int64_t _ss_ext_sales_price1221_t = tbl_SerializeFromObject_TD_7317535_input.getInt64(i, 2);
            tbl_Filter_TD_6116806_output.setInt64(r, 2, _ss_ext_sales_price1221_t);
            r++;
        }
    }
    tbl_Filter_TD_6116806_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6116806_output #Row: " << tbl_Filter_TD_6116806_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6231194(Table &tbl_SerializeFromObject_TD_7938405_input, Table &tbl_Filter_TD_6231194_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_moy#128) AND isnotnull(d_year#126)) AND ((d_moy#128 = 11) AND (d_year#126 = 2000))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126, d_moy#128)
    // Output: ListBuffer(d_date_sk#120, d_year#126)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7938405_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_moy128 = tbl_SerializeFromObject_TD_7938405_input.getInt32(i, 2);
        int32_t _d_year126 = tbl_SerializeFromObject_TD_7938405_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_7938405_input.getInt32(i, 0);
        if ((((_d_moy128!= 0) && (_d_year126!= 0)) && ((_d_moy128 == 11) && (_d_year126 == 2000))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_7938405_input.getInt32(i, 0);
            tbl_Filter_TD_6231194_output.setInt32(r, 0, _d_date_sk120_t);
            int32_t _d_year126_t = tbl_SerializeFromObject_TD_7938405_input.getInt32(i, 1);
            tbl_Filter_TD_6231194_output.setInt32(r, 1, _d_year126_t);
            r++;
        }
    }
    tbl_Filter_TD_6231194_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6231194_output #Row: " << tbl_Filter_TD_6231194_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5357844(Table &tbl_SerializeFromObject_TD_6458135_input, Table &tbl_Filter_TD_5357844_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(i_manager_id#248) AND (i_manager_id#248 = 1)) AND isnotnull(i_item_sk#228)))
    // Input: ListBuffer(i_item_sk#228, i_brand_id#235, i_brand#236, i_manager_id#248)
    // Output: ListBuffer(i_item_sk#228, i_brand_id#235, i_brand#236)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6458135_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_manager_id248 = tbl_SerializeFromObject_TD_6458135_input.getInt32(i, 3);
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_6458135_input.getInt32(i, 0);
        if (((_i_manager_id248!= 0) && (_i_manager_id248 == 1)) && (_i_item_sk228!= 0)) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_6458135_input.getInt32(i, 0);
            tbl_Filter_TD_5357844_output.setInt32(r, 0, _i_item_sk228_t);
            int32_t _i_brand_id235_t = tbl_SerializeFromObject_TD_6458135_input.getInt32(i, 1);
            tbl_Filter_TD_5357844_output.setInt32(r, 1, _i_brand_id235_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_t = tbl_SerializeFromObject_TD_6458135_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_5357844_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_brand236_t);
            r++;
        }
    }
    tbl_Filter_TD_5357844_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5357844_output #Row: " << tbl_Filter_TD_5357844_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_582576_key_leftMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_582576_key_leftMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_582576_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_582576_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_582576_payload_leftMajor {
    int32_t _d_date_sk120;
    int32_t _d_year126;
};
struct SW_JOIN_INNER_TD_582576_key_rightMajor {
    int32_t _ss_sold_date_sk1206;
    bool operator==(const SW_JOIN_INNER_TD_582576_key_rightMajor& other) const {
        return ((_ss_sold_date_sk1206 == other._ss_sold_date_sk1206));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_582576_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_582576_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_sold_date_sk1206));
    }
};
}
struct SW_JOIN_INNER_TD_582576_payload_rightMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_item_sk1208;
    int64_t _ss_ext_sales_price1221;
};
void SW_JOIN_INNER_TD_582576(Table &tbl_Filter_TD_6231194_output, Table &tbl_Filter_TD_6116806_output, Table &tbl_JOIN_INNER_TD_582576_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((d_date_sk#120 = ss_sold_date_sk#1206))
    // Left Table: ListBuffer(d_date_sk#120, d_year#126)
    // Right Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_ext_sales_price#1221)
    // Output Table: ListBuffer(d_year#126, ss_item_sk#1208, ss_ext_sales_price#1221)
    int left_nrow = tbl_Filter_TD_6231194_output.getNumRow();
    int right_nrow = tbl_Filter_TD_6116806_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_582576_key_leftMajor, SW_JOIN_INNER_TD_582576_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_6231194_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_6231194_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_582576_key_leftMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_6231194_output.getInt32(i, 0);
            int32_t _d_year126 = tbl_Filter_TD_6231194_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_582576_payload_leftMajor payloadA{_d_date_sk120, _d_year126};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6116806_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_Filter_TD_6116806_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_582576_key_leftMajor{_ss_sold_date_sk1206_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _d_year126 = (it->second)._d_year126;
                int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_6116806_output.getInt32(i, 0);
                int32_t _ss_item_sk1208 = tbl_Filter_TD_6116806_output.getInt32(i, 1);
                int64_t _ss_ext_sales_price1221 = tbl_Filter_TD_6116806_output.getInt64(i, 2);
                tbl_JOIN_INNER_TD_582576_output.setInt32(r, 0, _d_year126);
                tbl_JOIN_INNER_TD_582576_output.setInt32(r, 1, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_582576_output.setInt64(r, 2, _ss_ext_sales_price1221);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_582576_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_582576_key_rightMajor, SW_JOIN_INNER_TD_582576_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_6116806_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_Filter_TD_6116806_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_582576_key_rightMajor keyA{_ss_sold_date_sk1206_k};
            int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_6116806_output.getInt32(i, 0);
            int32_t _ss_item_sk1208 = tbl_Filter_TD_6116806_output.getInt32(i, 1);
            int64_t _ss_ext_sales_price1221 = tbl_Filter_TD_6116806_output.getInt64(i, 2);
            SW_JOIN_INNER_TD_582576_payload_rightMajor payloadA{_ss_sold_date_sk1206, _ss_item_sk1208, _ss_ext_sales_price1221};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6231194_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_6231194_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_582576_key_rightMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int32_t _d_date_sk120 = tbl_Filter_TD_6231194_output.getInt32(i, 0);
                int32_t _d_year126 = tbl_Filter_TD_6231194_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_582576_output.setInt32(r, 1, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_582576_output.setInt64(r, 2, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_582576_output.setInt32(r, 0, _d_year126);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_582576_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_582576_output #Row: " << tbl_JOIN_INNER_TD_582576_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4942037_key_leftMajor {
    int32_t _ss_item_sk1208;
    bool operator==(const SW_JOIN_INNER_TD_4942037_key_leftMajor& other) const {
        return ((_ss_item_sk1208 == other._ss_item_sk1208));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4942037_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4942037_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk1208));
    }
};
}
struct SW_JOIN_INNER_TD_4942037_payload_leftMajor {
    int32_t _d_year126;
    int32_t _ss_item_sk1208;
    int64_t _ss_ext_sales_price1221;
};
struct SW_JOIN_INNER_TD_4942037_key_rightMajor {
    int32_t _i_item_sk228;
    bool operator==(const SW_JOIN_INNER_TD_4942037_key_rightMajor& other) const {
        return ((_i_item_sk228 == other._i_item_sk228));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4942037_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4942037_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk228));
    }
};
}
struct SW_JOIN_INNER_TD_4942037_payload_rightMajor {
    int32_t _i_item_sk228;
    int32_t _i_brand_id235;
    std::string _i_brand236;
};
void SW_JOIN_INNER_TD_4942037(Table &tbl_JOIN_INNER_TD_582576_output, Table &tbl_Filter_TD_5357844_output, Table &tbl_JOIN_INNER_TD_4942037_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_item_sk#1208 = i_item_sk#228))
    // Left Table: ListBuffer(d_year#126, ss_item_sk#1208, ss_ext_sales_price#1221)
    // Right Table: ListBuffer(i_item_sk#228, i_brand_id#235, i_brand#236)
    // Output Table: ListBuffer(d_year#126, ss_ext_sales_price#1221, i_brand_id#235, i_brand#236)
    int left_nrow = tbl_JOIN_INNER_TD_582576_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5357844_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4942037_key_leftMajor, SW_JOIN_INNER_TD_4942037_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_582576_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_582576_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_4942037_key_leftMajor keyA{_ss_item_sk1208_k};
            int32_t _d_year126 = tbl_JOIN_INNER_TD_582576_output.getInt32(i, 0);
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_582576_output.getInt32(i, 1);
            int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_582576_output.getInt64(i, 2);
            SW_JOIN_INNER_TD_4942037_payload_leftMajor payloadA{_d_year126, _ss_item_sk1208, _ss_ext_sales_price1221};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5357844_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_5357844_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4942037_key_leftMajor{_i_item_sk228_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_year126 = (it->second)._d_year126;
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int32_t _i_item_sk228 = tbl_Filter_TD_5357844_output.getInt32(i, 0);
                int32_t _i_brand_id235 = tbl_Filter_TD_5357844_output.getInt32(i, 1);
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_Filter_TD_5357844_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _i_brand236 = std::string(_i_brand236_n.data());
                tbl_JOIN_INNER_TD_4942037_output.setInt32(r, 0, _d_year126);
                tbl_JOIN_INNER_TD_4942037_output.setInt64(r, 1, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_4942037_output.setInt32(r, 2, _i_brand_id235);
                tbl_JOIN_INNER_TD_4942037_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _i_brand236_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4942037_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4942037_key_rightMajor, SW_JOIN_INNER_TD_4942037_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5357844_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_5357844_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4942037_key_rightMajor keyA{_i_item_sk228_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_5357844_output.getInt32(i, 0);
            int32_t _i_brand_id235 = tbl_Filter_TD_5357844_output.getInt32(i, 1);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_Filter_TD_5357844_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _i_brand236 = std::string(_i_brand236_n.data());
            SW_JOIN_INNER_TD_4942037_payload_rightMajor payloadA{_i_item_sk228, _i_brand_id235, _i_brand236};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_582576_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_582576_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4942037_key_rightMajor{_ss_item_sk1208_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                int32_t _i_brand_id235 = (it->second)._i_brand_id235;
                std::string _i_brand236 = (it->second)._i_brand236;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n{};
                memcpy(_i_brand236_n.data(), (_i_brand236).data(), (_i_brand236).length());
                int32_t _d_year126 = tbl_JOIN_INNER_TD_582576_output.getInt32(i, 0);
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_582576_output.getInt32(i, 1);
                int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_582576_output.getInt64(i, 2);
                tbl_JOIN_INNER_TD_4942037_output.setInt32(r, 2, _i_brand_id235);
                tbl_JOIN_INNER_TD_4942037_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _i_brand236_n);
                tbl_JOIN_INNER_TD_4942037_output.setInt32(r, 0, _d_year126);
                tbl_JOIN_INNER_TD_4942037_output.setInt64(r, 1, _ss_ext_sales_price1221);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4942037_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4942037_output #Row: " << tbl_JOIN_INNER_TD_4942037_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_3988287_key {
    int32_t _d_year126;
    std::string _i_brand236;
    int32_t _i_brand_id235;
    bool operator==(const SW_Aggregate_TD_3988287_key& other) const { return (_d_year126 == other._d_year126) && (_i_brand236 == other._i_brand236) && (_i_brand_id235 == other._i_brand_id235); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_3988287_key> {
    std::size_t operator() (const SW_Aggregate_TD_3988287_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_year126)) + (hash<string>()(k._i_brand236)) + (hash<int32_t>()(k._i_brand_id235));
    }
};
}
struct SW_Aggregate_TD_3988287_payload {
    int32_t _brand_id3629;
    std::string _brand3630;
    int64_t _ext_price3631_sum_0;
};
void SW_Aggregate_TD_3988287(Table &tbl_JOIN_INNER_TD_4942037_output, Table &tbl_Aggregate_TD_3988287_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(d_year#126, i_brand#236, i_brand_id#235, i_brand_id#235 AS brand_id#3629, i_brand#236 AS brand#3630, MakeDecimal(sum(UnscaledValue(ss_ext_sales_price#1221)),17,2) AS ext_price#3631)
    // Input: ListBuffer(d_year#126, ss_ext_sales_price#1221, i_brand_id#235, i_brand#236)
    // Output: ListBuffer(d_year#126, brand_id#3629, brand#3630, ext_price#3631)
    std::unordered_map<SW_Aggregate_TD_3988287_key, SW_Aggregate_TD_3988287_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_4942037_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_JOIN_INNER_TD_4942037_output.getInt32(i, 0);
        int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_4942037_output.getInt64(i, 1);
        int32_t _i_brand_id235 = tbl_JOIN_INNER_TD_4942037_output.getInt32(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236 = tbl_JOIN_INNER_TD_4942037_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        SW_Aggregate_TD_3988287_key k{_d_year126, std::string(_i_brand236.data()), _i_brand_id235};
        int32_t _brand_id3629 = _i_brand_id235;
        std::array<char, TPCDS_READ_MAX + 1> _brand3630 = _i_brand236;
        int64_t _ext_price3631_sum_0 = _ss_ext_sales_price1221;
        SW_Aggregate_TD_3988287_payload p{_brand_id3629, std::string(_brand3630.data()), _ext_price3631_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._ext_price3631_sum_0 + _ext_price3631_sum_0;
            p._ext_price3631_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        tbl_Aggregate_TD_3988287_output.setInt32(r, 0, (it.first)._d_year126);
        // _i_brand236 not required in the output table
        // _i_brand_id235 not required in the output table
        tbl_Aggregate_TD_3988287_output.setInt32(r, 1, (it.second)._brand_id3629);
        std::array<char, TPCDS_READ_MAX + 1> _brand3630_n{};
        memcpy(_brand3630_n.data(), (it.second)._brand3630.data(), (it.second)._brand3630.length());
        tbl_Aggregate_TD_3988287_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _brand3630_n);
        int64_t _ext_price3631 = (it.second)._ext_price3631_sum_0;
        tbl_Aggregate_TD_3988287_output.setInt64(r, 3, _ext_price3631);
        ++r;
    }
    tbl_Aggregate_TD_3988287_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_3988287_output #Row: " << tbl_Aggregate_TD_3988287_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2937953(Table &tbl_Aggregate_TD_3988287_output, Table &tbl_Sort_TD_2937953_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(d_year#126 ASC NULLS FIRST, brand_id#3629 ASC NULLS FIRST)
    // Input: ListBuffer(d_year#126, brand_id#3629, brand#3630, ext_price#3631)
    // Output: ListBuffer(d_year#126, brand_id#3629, brand#3630, ext_price#3631)
    struct SW_Sort_TD_2937953Row {
        int32_t _d_year126;
        int32_t _brand_id3629;
        std::string _brand3630;
        int64_t _ext_price3631;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2937953Row& a, const SW_Sort_TD_2937953Row& b) const { return 
 (a._d_year126 < b._d_year126) || 
 ((a._d_year126 == b._d_year126) && (a._brand_id3629 < b._brand_id3629)); 
}
    }SW_Sort_TD_2937953_order; 

    int nrow1 = tbl_Aggregate_TD_3988287_output.getNumRow();
    std::vector<SW_Sort_TD_2937953Row> rows;
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_Aggregate_TD_3988287_output.getInt32(i, 0);
        int32_t _brand_id3629 = tbl_Aggregate_TD_3988287_output.getInt32(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _brand3630 = tbl_Aggregate_TD_3988287_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        int64_t _ext_price3631 = tbl_Aggregate_TD_3988287_output.getInt64(i, 3);
        SW_Sort_TD_2937953Row t = {_d_year126,_brand_id3629,std::string(_brand3630.data()),_ext_price3631};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2937953_order);
    int r = 0;
    for (auto& it : rows) {
        tbl_Sort_TD_2937953_output.setInt32(r, 0, it._d_year126);
        tbl_Sort_TD_2937953_output.setInt32(r, 1, it._brand_id3629);
        std::array<char, TPCDS_READ_MAX + 1> _brand3630{};
        memcpy(_brand3630.data(), (it._brand3630).data(), (it._brand3630).length());
        tbl_Sort_TD_2937953_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _brand3630);
        tbl_Sort_TD_2937953_output.setInt64(r, 3, it._ext_price3631);
        if (r < 10) {
            std::cout << it._d_year126 << " " << it._brand_id3629 << " " << (it._brand3630).data() << " " << it._ext_price3631 << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_2937953_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2937953_output #Row: " << tbl_Sort_TD_2937953_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1817293(Table &tbl_Sort_TD_2937953_output, Table &tbl_LocalLimit_TD_1817293_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(d_year#126, brand_id#3629, brand#3630, ext_price#3631)
    // Output: ListBuffer(d_year#126, brand_id#3629, brand#3630, ext_price#3631)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        tbl_LocalLimit_TD_1817293_output.setInt32(r, 0, tbl_Sort_TD_2937953_output.getInt32(i, 0));
        tbl_LocalLimit_TD_1817293_output.setInt32(r, 1, tbl_Sort_TD_2937953_output.getInt32(i, 1));
        std::array<char, TPCDS_READ_MAX + 1> _brand3630_n = tbl_Sort_TD_2937953_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_LocalLimit_TD_1817293_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _brand3630_n);
        tbl_LocalLimit_TD_1817293_output.setInt64(r, 3, tbl_Sort_TD_2937953_output.getInt64(i, 3));
        r++;
    }
    tbl_LocalLimit_TD_1817293_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1817293_output #Row: " << tbl_LocalLimit_TD_1817293_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0352934(Table &tbl_LocalLimit_TD_1817293_output, Table &tbl_GlobalLimit_TD_0352934_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(d_year#126, brand_id#3629, brand#3630, ext_price#3631)
    // Output: ListBuffer(d_year#126, brand_id#3629, brand#3630, ext_price#3631)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        tbl_GlobalLimit_TD_0352934_output.setInt32(r, 0, tbl_LocalLimit_TD_1817293_output.getInt32(i, 0));
        tbl_GlobalLimit_TD_0352934_output.setInt32(r, 1, tbl_LocalLimit_TD_1817293_output.getInt32(i, 1));
        std::array<char, TPCDS_READ_MAX + 1> _brand3630_n = tbl_LocalLimit_TD_1817293_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_GlobalLimit_TD_0352934_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _brand3630_n);
        tbl_GlobalLimit_TD_0352934_output.setInt64(r, 3, tbl_LocalLimit_TD_1817293_output.getInt64(i, 3));
        r++;
    }
    tbl_GlobalLimit_TD_0352934_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0352934_output #Row: " << tbl_GlobalLimit_TD_0352934_output.getNumRow() << std::endl;
}

