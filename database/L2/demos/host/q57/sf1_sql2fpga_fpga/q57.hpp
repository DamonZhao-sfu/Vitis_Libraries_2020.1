#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_14476204(Table &tbl_SerializeFromObject_TD_15139586_input, Table &tbl_Filter_TD_14476204_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cs_item_sk#1119) AND (isnotnull(cs_sold_date_sk#1104) AND isnotnull(cs_call_center_sk#1115))))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_call_center_sk#1115, cs_item_sk#1119, cs_sales_price#1125)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_call_center_sk#1115, cs_item_sk#1119, cs_sales_price#1125)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_15139586_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_item_sk1119 = tbl_SerializeFromObject_TD_15139586_input.getInt32(i, 2);
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_15139586_input.getInt32(i, 0);
        int32_t _cs_call_center_sk1115 = tbl_SerializeFromObject_TD_15139586_input.getInt32(i, 1);
        if ((_cs_item_sk1119!= 0) && ((_cs_sold_date_sk1104!= 0) && (_cs_call_center_sk1115!= 0))) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_15139586_input.getInt32(i, 0);
            tbl_Filter_TD_14476204_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int32_t _cs_call_center_sk1115_t = tbl_SerializeFromObject_TD_15139586_input.getInt32(i, 1);
            tbl_Filter_TD_14476204_output.setInt32(r, 1, _cs_call_center_sk1115_t);
            int32_t _cs_item_sk1119_t = tbl_SerializeFromObject_TD_15139586_input.getInt32(i, 2);
            tbl_Filter_TD_14476204_output.setInt32(r, 2, _cs_item_sk1119_t);
            int64_t _cs_sales_price1125_t = tbl_SerializeFromObject_TD_15139586_input.getInt64(i, 3);
            tbl_Filter_TD_14476204_output.setInt64(r, 3, _cs_sales_price1125_t);
            r++;
        }
    }
    tbl_Filter_TD_14476204_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_14476204_output #Row: " << tbl_Filter_TD_14476204_output.getNumRow() << std::endl;
}

void SW_Filter_TD_14929180(Table &tbl_SerializeFromObject_TD_15806479_input, Table &tbl_Filter_TD_14929180_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(i_item_sk#228) AND (isnotnull(i_category#240) AND isnotnull(i_brand#236))))
    // Input: ListBuffer(i_item_sk#228, i_brand#236, i_category#240)
    // Output: ListBuffer(i_item_sk#228, i_brand#236, i_category#240)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_15806479_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_15806479_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_category240 = tbl_SerializeFromObject_TD_15806479_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236 = tbl_SerializeFromObject_TD_15806479_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_i_item_sk228!= 0) && (_i_category240.data() != "NULL" && _i_brand236.data() != "NULL")) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_15806479_input.getInt32(i, 0);
            tbl_Filter_TD_14929180_output.setInt32(r, 0, _i_item_sk228_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_t = tbl_SerializeFromObject_TD_15806479_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_14929180_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand236_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_t = tbl_SerializeFromObject_TD_15806479_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_14929180_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_category240_t);
            r++;
        }
    }
    tbl_Filter_TD_14929180_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_14929180_output #Row: " << tbl_Filter_TD_14929180_output.getNumRow() << std::endl;
}

void SW_Filter_TD_13806451(Table &tbl_SerializeFromObject_TD_14673181_input, Table &tbl_Filter_TD_13806451_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((((d_year#126 = 1999) OR ((d_year#126 = 1998) AND (d_moy#128 = 12))) OR ((d_year#126 = 2000) AND (d_moy#128 = 1))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126, d_moy#128)
    // Output: ListBuffer(d_date_sk#120, d_year#126, d_moy#128)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_14673181_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_14673181_input.getInt32(i, 1);
        int32_t _d_moy128 = tbl_SerializeFromObject_TD_14673181_input.getInt32(i, 2);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_14673181_input.getInt32(i, 0);
        if ((((_d_year126 == 1999) || ((_d_year126 == 1998) && (_d_moy128 == 12))) || ((_d_year126 == 2000) && (_d_moy128 == 1))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_14673181_input.getInt32(i, 0);
            tbl_Filter_TD_13806451_output.setInt32(r, 0, _d_date_sk120_t);
            int32_t _d_year126_t = tbl_SerializeFromObject_TD_14673181_input.getInt32(i, 1);
            tbl_Filter_TD_13806451_output.setInt32(r, 1, _d_year126_t);
            int32_t _d_moy128_t = tbl_SerializeFromObject_TD_14673181_input.getInt32(i, 2);
            tbl_Filter_TD_13806451_output.setInt32(r, 2, _d_moy128_t);
            r++;
        }
    }
    tbl_Filter_TD_13806451_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_13806451_output #Row: " << tbl_Filter_TD_13806451_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_13115189_key_leftMajor {
    int32_t _i_item_sk228;
    bool operator==(const SW_JOIN_INNER_TD_13115189_key_leftMajor& other) const {
        return ((_i_item_sk228 == other._i_item_sk228));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_13115189_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_13115189_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk228));
    }
};
}
struct SW_JOIN_INNER_TD_13115189_payload_leftMajor {
    int32_t _i_item_sk228;
    std::string _i_brand236;
    std::string _i_category240;
};
struct SW_JOIN_INNER_TD_13115189_key_rightMajor {
    int32_t _cs_item_sk1119;
    bool operator==(const SW_JOIN_INNER_TD_13115189_key_rightMajor& other) const {
        return ((_cs_item_sk1119 == other._cs_item_sk1119));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_13115189_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_13115189_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_item_sk1119));
    }
};
}
struct SW_JOIN_INNER_TD_13115189_payload_rightMajor {
    int32_t _cs_sold_date_sk1104;
    int32_t _cs_call_center_sk1115;
    int32_t _cs_item_sk1119;
    int64_t _cs_sales_price1125;
};
void SW_JOIN_INNER_TD_13115189(Table &tbl_Filter_TD_14929180_output, Table &tbl_Filter_TD_14476204_output, Table &tbl_JOIN_INNER_TD_13115189_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_item_sk#1119 = i_item_sk#228))
    // Left Table: ListBuffer(i_item_sk#228, i_brand#236, i_category#240)
    // Right Table: ListBuffer(cs_sold_date_sk#1104, cs_call_center_sk#1115, cs_item_sk#1119, cs_sales_price#1125)
    // Output Table: ListBuffer(i_brand#236, i_category#240, cs_sold_date_sk#1104, cs_call_center_sk#1115, cs_sales_price#1125)
    int left_nrow = tbl_Filter_TD_14929180_output.getNumRow();
    int right_nrow = tbl_Filter_TD_14476204_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_13115189_key_leftMajor, SW_JOIN_INNER_TD_13115189_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_14929180_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_14929180_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_13115189_key_leftMajor keyA{_i_item_sk228_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_14929180_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_Filter_TD_14929180_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand236 = std::string(_i_brand236_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_Filter_TD_14929180_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _i_category240 = std::string(_i_category240_n.data());
            SW_JOIN_INNER_TD_13115189_payload_leftMajor payloadA{_i_item_sk228, _i_brand236, _i_category240};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_14476204_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_item_sk1119_k = tbl_Filter_TD_14476204_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_13115189_key_leftMajor{_cs_item_sk1119_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                std::string _i_brand236 = (it->second)._i_brand236;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n{};
                memcpy(_i_brand236_n.data(), (_i_brand236).data(), (_i_brand236).length());
                std::string _i_category240 = (it->second)._i_category240;
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n{};
                memcpy(_i_category240_n.data(), (_i_category240).data(), (_i_category240).length());
                int32_t _cs_sold_date_sk1104 = tbl_Filter_TD_14476204_output.getInt32(i, 0);
                int32_t _cs_call_center_sk1115 = tbl_Filter_TD_14476204_output.getInt32(i, 1);
                int32_t _cs_item_sk1119 = tbl_Filter_TD_14476204_output.getInt32(i, 2);
                int64_t _cs_sales_price1125 = tbl_Filter_TD_14476204_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_13115189_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand236_n);
                tbl_JOIN_INNER_TD_13115189_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category240_n);
                tbl_JOIN_INNER_TD_13115189_output.setInt32(r, 2, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_13115189_output.setInt32(r, 3, _cs_call_center_sk1115);
                tbl_JOIN_INNER_TD_13115189_output.setInt64(r, 4, _cs_sales_price1125);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_13115189_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_13115189_key_rightMajor, SW_JOIN_INNER_TD_13115189_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_14476204_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_item_sk1119_k = tbl_Filter_TD_14476204_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_13115189_key_rightMajor keyA{_cs_item_sk1119_k};
            int32_t _cs_sold_date_sk1104 = tbl_Filter_TD_14476204_output.getInt32(i, 0);
            int32_t _cs_call_center_sk1115 = tbl_Filter_TD_14476204_output.getInt32(i, 1);
            int32_t _cs_item_sk1119 = tbl_Filter_TD_14476204_output.getInt32(i, 2);
            int64_t _cs_sales_price1125 = tbl_Filter_TD_14476204_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_13115189_payload_rightMajor payloadA{_cs_sold_date_sk1104, _cs_call_center_sk1115, _cs_item_sk1119, _cs_sales_price1125};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_14929180_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_14929180_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_13115189_key_rightMajor{_i_item_sk228_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk1104 = (it->second)._cs_sold_date_sk1104;
                int32_t _cs_call_center_sk1115 = (it->second)._cs_call_center_sk1115;
                int32_t _cs_item_sk1119 = (it->second)._cs_item_sk1119;
                int64_t _cs_sales_price1125 = (it->second)._cs_sales_price1125;
                int32_t _i_item_sk228 = tbl_Filter_TD_14929180_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_Filter_TD_14929180_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_brand236 = std::string(_i_brand236_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_Filter_TD_14929180_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _i_category240 = std::string(_i_category240_n.data());
                tbl_JOIN_INNER_TD_13115189_output.setInt32(r, 2, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_13115189_output.setInt32(r, 3, _cs_call_center_sk1115);
                tbl_JOIN_INNER_TD_13115189_output.setInt64(r, 4, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_13115189_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand236_n);
                tbl_JOIN_INNER_TD_13115189_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category240_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_13115189_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_13115189_output #Row: " << tbl_JOIN_INNER_TD_13115189_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12327273(Table &tbl_SerializeFromObject_TD_13134184_input, Table &tbl_Filter_TD_12327273_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(cs_item_sk#4389) AND isnotnull(cs_sold_date_sk#4374)) AND isnotnull(cs_call_center_sk#4385)))
    // Input: ListBuffer(cs_sold_date_sk#4374, cs_call_center_sk#4385, cs_item_sk#4389, cs_sales_price#4395)
    // Output: ListBuffer(cs_sold_date_sk#4374, cs_call_center_sk#4385, cs_item_sk#4389, cs_sales_price#4395)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13134184_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_item_sk4389 = tbl_SerializeFromObject_TD_13134184_input.getInt32(i, 2);
        int32_t _cs_sold_date_sk4374 = tbl_SerializeFromObject_TD_13134184_input.getInt32(i, 0);
        int32_t _cs_call_center_sk4385 = tbl_SerializeFromObject_TD_13134184_input.getInt32(i, 1);
        if (((_cs_item_sk4389!= 0) && (_cs_sold_date_sk4374!= 0)) && (_cs_call_center_sk4385!= 0)) {
            int32_t _cs_sold_date_sk4374_t = tbl_SerializeFromObject_TD_13134184_input.getInt32(i, 0);
            tbl_Filter_TD_12327273_output.setInt32(r, 0, _cs_sold_date_sk4374_t);
            int32_t _cs_call_center_sk4385_t = tbl_SerializeFromObject_TD_13134184_input.getInt32(i, 1);
            tbl_Filter_TD_12327273_output.setInt32(r, 1, _cs_call_center_sk4385_t);
            int32_t _cs_item_sk4389_t = tbl_SerializeFromObject_TD_13134184_input.getInt32(i, 2);
            tbl_Filter_TD_12327273_output.setInt32(r, 2, _cs_item_sk4389_t);
            int64_t _cs_sales_price4395_t = tbl_SerializeFromObject_TD_13134184_input.getInt64(i, 3);
            tbl_Filter_TD_12327273_output.setInt64(r, 3, _cs_sales_price4395_t);
            r++;
        }
    }
    tbl_Filter_TD_12327273_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12327273_output #Row: " << tbl_Filter_TD_12327273_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12627067(Table &tbl_SerializeFromObject_TD_13178687_input, Table &tbl_Filter_TD_12627067_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(i_item_sk#4352) AND (isnotnull(i_category#4364) AND isnotnull(i_brand#4360))))
    // Input: ListBuffer(i_item_sk#4352, i_brand#4360, i_category#4364)
    // Output: ListBuffer(i_item_sk#4352, i_brand#4360, i_category#4364)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13178687_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk4352 = tbl_SerializeFromObject_TD_13178687_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_category4364 = tbl_SerializeFromObject_TD_13178687_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand4360 = tbl_SerializeFromObject_TD_13178687_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_i_item_sk4352!= 0) && (_i_category4364.data() != "NULL" && _i_brand4360.data() != "NULL")) {
            int32_t _i_item_sk4352_t = tbl_SerializeFromObject_TD_13178687_input.getInt32(i, 0);
            tbl_Filter_TD_12627067_output.setInt32(r, 0, _i_item_sk4352_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4360_t = tbl_SerializeFromObject_TD_13178687_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_12627067_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand4360_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_category4364_t = tbl_SerializeFromObject_TD_13178687_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_12627067_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_category4364_t);
            r++;
        }
    }
    tbl_Filter_TD_12627067_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12627067_output #Row: " << tbl_Filter_TD_12627067_output.getNumRow() << std::endl;
}

void SW_Filter_TD_1271702(Table &tbl_SerializeFromObject_TD_13444029_input, Table &tbl_Filter_TD_1271702_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cc_call_center_sk#903) AND isnotnull(cc_name#909)))
    // Input: ListBuffer(cc_call_center_sk#903, cc_name#909)
    // Output: ListBuffer(cc_call_center_sk#903, cc_name#909)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13444029_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cc_call_center_sk903 = tbl_SerializeFromObject_TD_13444029_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name909 = tbl_SerializeFromObject_TD_13444029_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_cc_call_center_sk903!= 0) && _cc_name909.data() != "NULL") {
            int32_t _cc_call_center_sk903_t = tbl_SerializeFromObject_TD_13444029_input.getInt32(i, 0);
            tbl_Filter_TD_1271702_output.setInt32(r, 0, _cc_call_center_sk903_t);
            std::array<char, TPCDS_READ_MAX + 1> _cc_name909_t = tbl_SerializeFromObject_TD_13444029_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_1271702_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cc_name909_t);
            r++;
        }
    }
    tbl_Filter_TD_1271702_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1271702_output #Row: " << tbl_Filter_TD_1271702_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_12967486_key_leftMajor {
    int32_t _cs_sold_date_sk1104;
    bool operator==(const SW_JOIN_INNER_TD_12967486_key_leftMajor& other) const {
        return ((_cs_sold_date_sk1104 == other._cs_sold_date_sk1104));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_12967486_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_12967486_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_sold_date_sk1104));
    }
};
}
struct SW_JOIN_INNER_TD_12967486_payload_leftMajor {
    std::string _i_brand236;
    std::string _i_category240;
    int32_t _cs_sold_date_sk1104;
    int32_t _cs_call_center_sk1115;
    int64_t _cs_sales_price1125;
};
struct SW_JOIN_INNER_TD_12967486_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_12967486_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_12967486_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_12967486_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_12967486_payload_rightMajor {
    int32_t _d_date_sk120;
    int32_t _d_year126;
    int32_t _d_moy128;
};
void SW_JOIN_INNER_TD_12967486(Table &tbl_JOIN_INNER_TD_13115189_output, Table &tbl_Filter_TD_13806451_output, Table &tbl_JOIN_INNER_TD_12967486_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_sold_date_sk#1104 = d_date_sk#120))
    // Left Table: ListBuffer(i_brand#236, i_category#240, cs_sold_date_sk#1104, cs_call_center_sk#1115, cs_sales_price#1125)
    // Right Table: ListBuffer(d_date_sk#120, d_year#126, d_moy#128)
    // Output Table: ListBuffer(i_brand#236, i_category#240, cs_call_center_sk#1115, cs_sales_price#1125, d_year#126, d_moy#128)
    int left_nrow = tbl_JOIN_INNER_TD_13115189_output.getNumRow();
    int right_nrow = tbl_Filter_TD_13806451_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_12967486_key_leftMajor, SW_JOIN_INNER_TD_12967486_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_13115189_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_sold_date_sk1104_k = tbl_JOIN_INNER_TD_13115189_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_12967486_key_leftMajor keyA{_cs_sold_date_sk1104_k};
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_JOIN_INNER_TD_13115189_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_brand236 = std::string(_i_brand236_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_JOIN_INNER_TD_13115189_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_category240 = std::string(_i_category240_n.data());
            int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_13115189_output.getInt32(i, 2);
            int32_t _cs_call_center_sk1115 = tbl_JOIN_INNER_TD_13115189_output.getInt32(i, 3);
            int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_13115189_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_12967486_payload_leftMajor payloadA{_i_brand236, _i_category240, _cs_sold_date_sk1104, _cs_call_center_sk1115, _cs_sales_price1125};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_13806451_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_13806451_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_12967486_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _i_brand236 = (it->second)._i_brand236;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n{};
                memcpy(_i_brand236_n.data(), (_i_brand236).data(), (_i_brand236).length());
                std::string _i_category240 = (it->second)._i_category240;
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n{};
                memcpy(_i_category240_n.data(), (_i_category240).data(), (_i_category240).length());
                int32_t _cs_sold_date_sk1104 = (it->second)._cs_sold_date_sk1104;
                int32_t _cs_call_center_sk1115 = (it->second)._cs_call_center_sk1115;
                int64_t _cs_sales_price1125 = (it->second)._cs_sales_price1125;
                int32_t _d_date_sk120 = tbl_Filter_TD_13806451_output.getInt32(i, 0);
                int32_t _d_year126 = tbl_Filter_TD_13806451_output.getInt32(i, 1);
                int32_t _d_moy128 = tbl_Filter_TD_13806451_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_12967486_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand236_n);
                tbl_JOIN_INNER_TD_12967486_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category240_n);
                tbl_JOIN_INNER_TD_12967486_output.setInt32(r, 2, _cs_call_center_sk1115);
                tbl_JOIN_INNER_TD_12967486_output.setInt64(r, 3, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_12967486_output.setInt32(r, 4, _d_year126);
                tbl_JOIN_INNER_TD_12967486_output.setInt32(r, 5, _d_moy128);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_12967486_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_12967486_key_rightMajor, SW_JOIN_INNER_TD_12967486_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_13806451_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_13806451_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_12967486_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_13806451_output.getInt32(i, 0);
            int32_t _d_year126 = tbl_Filter_TD_13806451_output.getInt32(i, 1);
            int32_t _d_moy128 = tbl_Filter_TD_13806451_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_12967486_payload_rightMajor payloadA{_d_date_sk120, _d_year126, _d_moy128};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_13115189_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_sold_date_sk1104_k = tbl_JOIN_INNER_TD_13115189_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_12967486_key_rightMajor{_cs_sold_date_sk1104_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _d_year126 = (it->second)._d_year126;
                int32_t _d_moy128 = (it->second)._d_moy128;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_JOIN_INNER_TD_13115189_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _i_brand236 = std::string(_i_brand236_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_JOIN_INNER_TD_13115189_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_category240 = std::string(_i_category240_n.data());
                int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_13115189_output.getInt32(i, 2);
                int32_t _cs_call_center_sk1115 = tbl_JOIN_INNER_TD_13115189_output.getInt32(i, 3);
                int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_13115189_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_12967486_output.setInt32(r, 4, _d_year126);
                tbl_JOIN_INNER_TD_12967486_output.setInt32(r, 5, _d_moy128);
                tbl_JOIN_INNER_TD_12967486_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand236_n);
                tbl_JOIN_INNER_TD_12967486_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category240_n);
                tbl_JOIN_INNER_TD_12967486_output.setInt32(r, 2, _cs_call_center_sk1115);
                tbl_JOIN_INNER_TD_12967486_output.setInt64(r, 3, _cs_sales_price1125);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_12967486_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_12967486_output #Row: " << tbl_JOIN_INNER_TD_12967486_output.getNumRow() << std::endl;
}

void SW_Filter_TD_1193880(Table &tbl_SerializeFromObject_TD_12261048_input, Table &tbl_Filter_TD_1193880_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(cs_item_sk#4509) AND isnotnull(cs_sold_date_sk#4494)) AND isnotnull(cs_call_center_sk#4505)))
    // Input: ListBuffer(cs_sold_date_sk#4494, cs_call_center_sk#4505, cs_item_sk#4509, cs_sales_price#4515)
    // Output: ListBuffer(cs_sold_date_sk#4494, cs_call_center_sk#4505, cs_item_sk#4509, cs_sales_price#4515)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12261048_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_item_sk4509 = tbl_SerializeFromObject_TD_12261048_input.getInt32(i, 2);
        int32_t _cs_sold_date_sk4494 = tbl_SerializeFromObject_TD_12261048_input.getInt32(i, 0);
        int32_t _cs_call_center_sk4505 = tbl_SerializeFromObject_TD_12261048_input.getInt32(i, 1);
        if (((_cs_item_sk4509!= 0) && (_cs_sold_date_sk4494!= 0)) && (_cs_call_center_sk4505!= 0)) {
            int32_t _cs_sold_date_sk4494_t = tbl_SerializeFromObject_TD_12261048_input.getInt32(i, 0);
            tbl_Filter_TD_1193880_output.setInt32(r, 0, _cs_sold_date_sk4494_t);
            int32_t _cs_call_center_sk4505_t = tbl_SerializeFromObject_TD_12261048_input.getInt32(i, 1);
            tbl_Filter_TD_1193880_output.setInt32(r, 1, _cs_call_center_sk4505_t);
            int32_t _cs_item_sk4509_t = tbl_SerializeFromObject_TD_12261048_input.getInt32(i, 2);
            tbl_Filter_TD_1193880_output.setInt32(r, 2, _cs_item_sk4509_t);
            int64_t _cs_sales_price4515_t = tbl_SerializeFromObject_TD_12261048_input.getInt64(i, 3);
            tbl_Filter_TD_1193880_output.setInt64(r, 3, _cs_sales_price4515_t);
            r++;
        }
    }
    tbl_Filter_TD_1193880_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1193880_output #Row: " << tbl_Filter_TD_1193880_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11715245(Table &tbl_SerializeFromObject_TD_12818095_input, Table &tbl_Filter_TD_11715245_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(i_item_sk#4472) AND (isnotnull(i_category#4484) AND isnotnull(i_brand#4480))))
    // Input: ListBuffer(i_item_sk#4472, i_brand#4480, i_category#4484)
    // Output: ListBuffer(i_item_sk#4472, i_brand#4480, i_category#4484)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12818095_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk4472 = tbl_SerializeFromObject_TD_12818095_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_category4484 = tbl_SerializeFromObject_TD_12818095_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand4480 = tbl_SerializeFromObject_TD_12818095_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_i_item_sk4472!= 0) && (_i_category4484.data() != "NULL" && _i_brand4480.data() != "NULL")) {
            int32_t _i_item_sk4472_t = tbl_SerializeFromObject_TD_12818095_input.getInt32(i, 0);
            tbl_Filter_TD_11715245_output.setInt32(r, 0, _i_item_sk4472_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4480_t = tbl_SerializeFromObject_TD_12818095_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_11715245_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand4480_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_category4484_t = tbl_SerializeFromObject_TD_12818095_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_11715245_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_category4484_t);
            r++;
        }
    }
    tbl_Filter_TD_11715245_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11715245_output #Row: " << tbl_Filter_TD_11715245_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11656057(Table &tbl_SerializeFromObject_TD_12856143_input, Table &tbl_Filter_TD_11656057_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((((d_year#4414 = 1999) OR ((d_year#4414 = 1998) AND (d_moy#4416 = 12))) OR ((d_year#4414 = 2000) AND (d_moy#4416 = 1))) AND isnotnull(d_date_sk#4408)))
    // Input: ListBuffer(d_date_sk#4408, d_year#4414, d_moy#4416)
    // Output: ListBuffer(d_date_sk#4408, d_year#4414, d_moy#4416)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12856143_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year4414 = tbl_SerializeFromObject_TD_12856143_input.getInt32(i, 1);
        int32_t _d_moy4416 = tbl_SerializeFromObject_TD_12856143_input.getInt32(i, 2);
        int32_t _d_date_sk4408 = tbl_SerializeFromObject_TD_12856143_input.getInt32(i, 0);
        if ((((_d_year4414 == 1999) || ((_d_year4414 == 1998) && (_d_moy4416 == 12))) || ((_d_year4414 == 2000) && (_d_moy4416 == 1))) && (_d_date_sk4408!= 0)) {
            int32_t _d_date_sk4408_t = tbl_SerializeFromObject_TD_12856143_input.getInt32(i, 0);
            tbl_Filter_TD_11656057_output.setInt32(r, 0, _d_date_sk4408_t);
            int32_t _d_year4414_t = tbl_SerializeFromObject_TD_12856143_input.getInt32(i, 1);
            tbl_Filter_TD_11656057_output.setInt32(r, 1, _d_year4414_t);
            int32_t _d_moy4416_t = tbl_SerializeFromObject_TD_12856143_input.getInt32(i, 2);
            tbl_Filter_TD_11656057_output.setInt32(r, 2, _d_moy4416_t);
            r++;
        }
    }
    tbl_Filter_TD_11656057_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11656057_output #Row: " << tbl_Filter_TD_11656057_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_11646117_key_leftMajor {
    int32_t _i_item_sk4352;
    bool operator==(const SW_JOIN_INNER_TD_11646117_key_leftMajor& other) const {
        return ((_i_item_sk4352 == other._i_item_sk4352));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11646117_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11646117_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk4352));
    }
};
}
struct SW_JOIN_INNER_TD_11646117_payload_leftMajor {
    int32_t _i_item_sk4352;
    std::string _i_brand4360;
    std::string _i_category4364;
};
struct SW_JOIN_INNER_TD_11646117_key_rightMajor {
    int32_t _cs_item_sk4389;
    bool operator==(const SW_JOIN_INNER_TD_11646117_key_rightMajor& other) const {
        return ((_cs_item_sk4389 == other._cs_item_sk4389));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11646117_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11646117_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_item_sk4389));
    }
};
}
struct SW_JOIN_INNER_TD_11646117_payload_rightMajor {
    int32_t _cs_sold_date_sk4374;
    int32_t _cs_call_center_sk4385;
    int32_t _cs_item_sk4389;
    int64_t _cs_sales_price4395;
};
void SW_JOIN_INNER_TD_11646117(Table &tbl_Filter_TD_12627067_output, Table &tbl_Filter_TD_12327273_output, Table &tbl_JOIN_INNER_TD_11646117_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_item_sk#4389 = i_item_sk#4352))
    // Left Table: ListBuffer(i_item_sk#4352, i_brand#4360, i_category#4364)
    // Right Table: ListBuffer(cs_sold_date_sk#4374, cs_call_center_sk#4385, cs_item_sk#4389, cs_sales_price#4395)
    // Output Table: ListBuffer(i_brand#4360, i_category#4364, cs_sold_date_sk#4374, cs_call_center_sk#4385, cs_sales_price#4395)
    int left_nrow = tbl_Filter_TD_12627067_output.getNumRow();
    int right_nrow = tbl_Filter_TD_12327273_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11646117_key_leftMajor, SW_JOIN_INNER_TD_11646117_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_12627067_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk4352_k = tbl_Filter_TD_12627067_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_11646117_key_leftMajor keyA{_i_item_sk4352_k};
            int32_t _i_item_sk4352 = tbl_Filter_TD_12627067_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4360_n = tbl_Filter_TD_12627067_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand4360 = std::string(_i_brand4360_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_category4364_n = tbl_Filter_TD_12627067_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _i_category4364 = std::string(_i_category4364_n.data());
            SW_JOIN_INNER_TD_11646117_payload_leftMajor payloadA{_i_item_sk4352, _i_brand4360, _i_category4364};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_12327273_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_item_sk4389_k = tbl_Filter_TD_12327273_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11646117_key_leftMajor{_cs_item_sk4389_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk4352 = (it->second)._i_item_sk4352;
                std::string _i_brand4360 = (it->second)._i_brand4360;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4360_n{};
                memcpy(_i_brand4360_n.data(), (_i_brand4360).data(), (_i_brand4360).length());
                std::string _i_category4364 = (it->second)._i_category4364;
                std::array<char, TPCDS_READ_MAX + 1> _i_category4364_n{};
                memcpy(_i_category4364_n.data(), (_i_category4364).data(), (_i_category4364).length());
                int32_t _cs_sold_date_sk4374 = tbl_Filter_TD_12327273_output.getInt32(i, 0);
                int32_t _cs_call_center_sk4385 = tbl_Filter_TD_12327273_output.getInt32(i, 1);
                int32_t _cs_item_sk4389 = tbl_Filter_TD_12327273_output.getInt32(i, 2);
                int64_t _cs_sales_price4395 = tbl_Filter_TD_12327273_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_11646117_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand4360_n);
                tbl_JOIN_INNER_TD_11646117_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category4364_n);
                tbl_JOIN_INNER_TD_11646117_output.setInt32(r, 2, _cs_sold_date_sk4374);
                tbl_JOIN_INNER_TD_11646117_output.setInt32(r, 3, _cs_call_center_sk4385);
                tbl_JOIN_INNER_TD_11646117_output.setInt64(r, 4, _cs_sales_price4395);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11646117_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11646117_key_rightMajor, SW_JOIN_INNER_TD_11646117_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_12327273_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_item_sk4389_k = tbl_Filter_TD_12327273_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_11646117_key_rightMajor keyA{_cs_item_sk4389_k};
            int32_t _cs_sold_date_sk4374 = tbl_Filter_TD_12327273_output.getInt32(i, 0);
            int32_t _cs_call_center_sk4385 = tbl_Filter_TD_12327273_output.getInt32(i, 1);
            int32_t _cs_item_sk4389 = tbl_Filter_TD_12327273_output.getInt32(i, 2);
            int64_t _cs_sales_price4395 = tbl_Filter_TD_12327273_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_11646117_payload_rightMajor payloadA{_cs_sold_date_sk4374, _cs_call_center_sk4385, _cs_item_sk4389, _cs_sales_price4395};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_12627067_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk4352_k = tbl_Filter_TD_12627067_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11646117_key_rightMajor{_i_item_sk4352_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk4374 = (it->second)._cs_sold_date_sk4374;
                int32_t _cs_call_center_sk4385 = (it->second)._cs_call_center_sk4385;
                int32_t _cs_item_sk4389 = (it->second)._cs_item_sk4389;
                int64_t _cs_sales_price4395 = (it->second)._cs_sales_price4395;
                int32_t _i_item_sk4352 = tbl_Filter_TD_12627067_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4360_n = tbl_Filter_TD_12627067_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_brand4360 = std::string(_i_brand4360_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_category4364_n = tbl_Filter_TD_12627067_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _i_category4364 = std::string(_i_category4364_n.data());
                tbl_JOIN_INNER_TD_11646117_output.setInt32(r, 2, _cs_sold_date_sk4374);
                tbl_JOIN_INNER_TD_11646117_output.setInt32(r, 3, _cs_call_center_sk4385);
                tbl_JOIN_INNER_TD_11646117_output.setInt64(r, 4, _cs_sales_price4395);
                tbl_JOIN_INNER_TD_11646117_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand4360_n);
                tbl_JOIN_INNER_TD_11646117_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category4364_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11646117_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_11646117_output #Row: " << tbl_JOIN_INNER_TD_11646117_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_113015_key_leftMajor {
    int32_t _cs_call_center_sk1115;
    bool operator==(const SW_JOIN_INNER_TD_113015_key_leftMajor& other) const {
        return ((_cs_call_center_sk1115 == other._cs_call_center_sk1115));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_113015_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_113015_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_call_center_sk1115));
    }
};
}
struct SW_JOIN_INNER_TD_113015_payload_leftMajor {
    std::string _i_brand236;
    std::string _i_category240;
    int32_t _cs_call_center_sk1115;
    int64_t _cs_sales_price1125;
    int32_t _d_year126;
    int32_t _d_moy128;
};
struct SW_JOIN_INNER_TD_113015_key_rightMajor {
    int32_t _cc_call_center_sk903;
    bool operator==(const SW_JOIN_INNER_TD_113015_key_rightMajor& other) const {
        return ((_cc_call_center_sk903 == other._cc_call_center_sk903));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_113015_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_113015_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cc_call_center_sk903));
    }
};
}
struct SW_JOIN_INNER_TD_113015_payload_rightMajor {
    int32_t _cc_call_center_sk903;
    std::string _cc_name909;
};
void SW_JOIN_INNER_TD_113015(Table &tbl_JOIN_INNER_TD_12967486_output, Table &tbl_Filter_TD_1271702_output, Table &tbl_JOIN_INNER_TD_113015_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cc_call_center_sk#903 = cs_call_center_sk#1115))
    // Left Table: ListBuffer(i_brand#236, i_category#240, cs_call_center_sk#1115, cs_sales_price#1125, d_year#126, d_moy#128)
    // Right Table: ListBuffer(cc_call_center_sk#903, cc_name#909)
    // Output Table: ListBuffer(i_brand#236, i_category#240, cs_sales_price#1125, d_year#126, d_moy#128, cc_name#909)
    int left_nrow = tbl_JOIN_INNER_TD_12967486_output.getNumRow();
    int right_nrow = tbl_Filter_TD_1271702_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_113015_key_leftMajor, SW_JOIN_INNER_TD_113015_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_12967486_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_call_center_sk1115_k = tbl_JOIN_INNER_TD_12967486_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_113015_key_leftMajor keyA{_cs_call_center_sk1115_k};
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_JOIN_INNER_TD_12967486_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_brand236 = std::string(_i_brand236_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_JOIN_INNER_TD_12967486_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_category240 = std::string(_i_category240_n.data());
            int32_t _cs_call_center_sk1115 = tbl_JOIN_INNER_TD_12967486_output.getInt32(i, 2);
            int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_12967486_output.getInt64(i, 3);
            int32_t _d_year126 = tbl_JOIN_INNER_TD_12967486_output.getInt32(i, 4);
            int32_t _d_moy128 = tbl_JOIN_INNER_TD_12967486_output.getInt32(i, 5);
            SW_JOIN_INNER_TD_113015_payload_leftMajor payloadA{_i_brand236, _i_category240, _cs_call_center_sk1115, _cs_sales_price1125, _d_year126, _d_moy128};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_1271702_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cc_call_center_sk903_k = tbl_Filter_TD_1271702_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_113015_key_leftMajor{_cc_call_center_sk903_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _i_brand236 = (it->second)._i_brand236;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n{};
                memcpy(_i_brand236_n.data(), (_i_brand236).data(), (_i_brand236).length());
                std::string _i_category240 = (it->second)._i_category240;
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n{};
                memcpy(_i_category240_n.data(), (_i_category240).data(), (_i_category240).length());
                int32_t _cs_call_center_sk1115 = (it->second)._cs_call_center_sk1115;
                int64_t _cs_sales_price1125 = (it->second)._cs_sales_price1125;
                int32_t _d_year126 = (it->second)._d_year126;
                int32_t _d_moy128 = (it->second)._d_moy128;
                int32_t _cc_call_center_sk903 = tbl_Filter_TD_1271702_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_Filter_TD_1271702_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _cc_name909 = std::string(_cc_name909_n.data());
                tbl_JOIN_INNER_TD_113015_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand236_n);
                tbl_JOIN_INNER_TD_113015_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category240_n);
                tbl_JOIN_INNER_TD_113015_output.setInt64(r, 2, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_113015_output.setInt32(r, 3, _d_year126);
                tbl_JOIN_INNER_TD_113015_output.setInt32(r, 4, _d_moy128);
                tbl_JOIN_INNER_TD_113015_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _cc_name909_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_113015_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_113015_key_rightMajor, SW_JOIN_INNER_TD_113015_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_1271702_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cc_call_center_sk903_k = tbl_Filter_TD_1271702_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_113015_key_rightMajor keyA{_cc_call_center_sk903_k};
            int32_t _cc_call_center_sk903 = tbl_Filter_TD_1271702_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_Filter_TD_1271702_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cc_name909 = std::string(_cc_name909_n.data());
            SW_JOIN_INNER_TD_113015_payload_rightMajor payloadA{_cc_call_center_sk903, _cc_name909};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_12967486_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_call_center_sk1115_k = tbl_JOIN_INNER_TD_12967486_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_113015_key_rightMajor{_cs_call_center_sk1115_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cc_call_center_sk903 = (it->second)._cc_call_center_sk903;
                std::string _cc_name909 = (it->second)._cc_name909;
                std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n{};
                memcpy(_cc_name909_n.data(), (_cc_name909).data(), (_cc_name909).length());
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_JOIN_INNER_TD_12967486_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _i_brand236 = std::string(_i_brand236_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_JOIN_INNER_TD_12967486_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_category240 = std::string(_i_category240_n.data());
                int32_t _cs_call_center_sk1115 = tbl_JOIN_INNER_TD_12967486_output.getInt32(i, 2);
                int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_12967486_output.getInt64(i, 3);
                int32_t _d_year126 = tbl_JOIN_INNER_TD_12967486_output.getInt32(i, 4);
                int32_t _d_moy128 = tbl_JOIN_INNER_TD_12967486_output.getInt32(i, 5);
                tbl_JOIN_INNER_TD_113015_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _cc_name909_n);
                tbl_JOIN_INNER_TD_113015_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand236_n);
                tbl_JOIN_INNER_TD_113015_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category240_n);
                tbl_JOIN_INNER_TD_113015_output.setInt64(r, 2, _cs_sales_price1125);
                tbl_JOIN_INNER_TD_113015_output.setInt32(r, 3, _d_year126);
                tbl_JOIN_INNER_TD_113015_output.setInt32(r, 4, _d_moy128);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_113015_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_113015_output #Row: " << tbl_JOIN_INNER_TD_113015_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10827249(Table &tbl_SerializeFromObject_TD_11476877_input, Table &tbl_Filter_TD_10827249_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((((d_year#4534 = 1999) OR ((d_year#4534 = 1998) AND (d_moy#4536 = 12))) OR ((d_year#4534 = 2000) AND (d_moy#4536 = 1))) AND isnotnull(d_date_sk#4528)))
    // Input: ListBuffer(d_date_sk#4528, d_year#4534, d_moy#4536)
    // Output: ListBuffer(d_date_sk#4528, d_year#4534, d_moy#4536)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11476877_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year4534 = tbl_SerializeFromObject_TD_11476877_input.getInt32(i, 1);
        int32_t _d_moy4536 = tbl_SerializeFromObject_TD_11476877_input.getInt32(i, 2);
        int32_t _d_date_sk4528 = tbl_SerializeFromObject_TD_11476877_input.getInt32(i, 0);
        if ((((_d_year4534 == 1999) || ((_d_year4534 == 1998) && (_d_moy4536 == 12))) || ((_d_year4534 == 2000) && (_d_moy4536 == 1))) && (_d_date_sk4528!= 0)) {
            int32_t _d_date_sk4528_t = tbl_SerializeFromObject_TD_11476877_input.getInt32(i, 0);
            tbl_Filter_TD_10827249_output.setInt32(r, 0, _d_date_sk4528_t);
            int32_t _d_year4534_t = tbl_SerializeFromObject_TD_11476877_input.getInt32(i, 1);
            tbl_Filter_TD_10827249_output.setInt32(r, 1, _d_year4534_t);
            int32_t _d_moy4536_t = tbl_SerializeFromObject_TD_11476877_input.getInt32(i, 2);
            tbl_Filter_TD_10827249_output.setInt32(r, 2, _d_moy4536_t);
            r++;
        }
    }
    tbl_Filter_TD_10827249_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10827249_output #Row: " << tbl_Filter_TD_10827249_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_10332289_key_leftMajor {
    int32_t _i_item_sk4472;
    bool operator==(const SW_JOIN_INNER_TD_10332289_key_leftMajor& other) const {
        return ((_i_item_sk4472 == other._i_item_sk4472));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10332289_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10332289_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk4472));
    }
};
}
struct SW_JOIN_INNER_TD_10332289_payload_leftMajor {
    int32_t _i_item_sk4472;
    std::string _i_brand4480;
    std::string _i_category4484;
};
struct SW_JOIN_INNER_TD_10332289_key_rightMajor {
    int32_t _cs_item_sk4509;
    bool operator==(const SW_JOIN_INNER_TD_10332289_key_rightMajor& other) const {
        return ((_cs_item_sk4509 == other._cs_item_sk4509));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10332289_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10332289_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_item_sk4509));
    }
};
}
struct SW_JOIN_INNER_TD_10332289_payload_rightMajor {
    int32_t _cs_sold_date_sk4494;
    int32_t _cs_call_center_sk4505;
    int32_t _cs_item_sk4509;
    int64_t _cs_sales_price4515;
};
void SW_JOIN_INNER_TD_10332289(Table &tbl_Filter_TD_11715245_output, Table &tbl_Filter_TD_1193880_output, Table &tbl_JOIN_INNER_TD_10332289_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_item_sk#4509 = i_item_sk#4472))
    // Left Table: ListBuffer(i_item_sk#4472, i_brand#4480, i_category#4484)
    // Right Table: ListBuffer(cs_sold_date_sk#4494, cs_call_center_sk#4505, cs_item_sk#4509, cs_sales_price#4515)
    // Output Table: ListBuffer(i_brand#4480, i_category#4484, cs_sold_date_sk#4494, cs_call_center_sk#4505, cs_sales_price#4515)
    int left_nrow = tbl_Filter_TD_11715245_output.getNumRow();
    int right_nrow = tbl_Filter_TD_1193880_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10332289_key_leftMajor, SW_JOIN_INNER_TD_10332289_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_11715245_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk4472_k = tbl_Filter_TD_11715245_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_10332289_key_leftMajor keyA{_i_item_sk4472_k};
            int32_t _i_item_sk4472 = tbl_Filter_TD_11715245_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4480_n = tbl_Filter_TD_11715245_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand4480 = std::string(_i_brand4480_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_category4484_n = tbl_Filter_TD_11715245_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _i_category4484 = std::string(_i_category4484_n.data());
            SW_JOIN_INNER_TD_10332289_payload_leftMajor payloadA{_i_item_sk4472, _i_brand4480, _i_category4484};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_1193880_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_item_sk4509_k = tbl_Filter_TD_1193880_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10332289_key_leftMajor{_cs_item_sk4509_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk4472 = (it->second)._i_item_sk4472;
                std::string _i_brand4480 = (it->second)._i_brand4480;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4480_n{};
                memcpy(_i_brand4480_n.data(), (_i_brand4480).data(), (_i_brand4480).length());
                std::string _i_category4484 = (it->second)._i_category4484;
                std::array<char, TPCDS_READ_MAX + 1> _i_category4484_n{};
                memcpy(_i_category4484_n.data(), (_i_category4484).data(), (_i_category4484).length());
                int32_t _cs_sold_date_sk4494 = tbl_Filter_TD_1193880_output.getInt32(i, 0);
                int32_t _cs_call_center_sk4505 = tbl_Filter_TD_1193880_output.getInt32(i, 1);
                int32_t _cs_item_sk4509 = tbl_Filter_TD_1193880_output.getInt32(i, 2);
                int64_t _cs_sales_price4515 = tbl_Filter_TD_1193880_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_10332289_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand4480_n);
                tbl_JOIN_INNER_TD_10332289_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category4484_n);
                tbl_JOIN_INNER_TD_10332289_output.setInt32(r, 2, _cs_sold_date_sk4494);
                tbl_JOIN_INNER_TD_10332289_output.setInt32(r, 3, _cs_call_center_sk4505);
                tbl_JOIN_INNER_TD_10332289_output.setInt64(r, 4, _cs_sales_price4515);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10332289_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10332289_key_rightMajor, SW_JOIN_INNER_TD_10332289_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_1193880_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_item_sk4509_k = tbl_Filter_TD_1193880_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_10332289_key_rightMajor keyA{_cs_item_sk4509_k};
            int32_t _cs_sold_date_sk4494 = tbl_Filter_TD_1193880_output.getInt32(i, 0);
            int32_t _cs_call_center_sk4505 = tbl_Filter_TD_1193880_output.getInt32(i, 1);
            int32_t _cs_item_sk4509 = tbl_Filter_TD_1193880_output.getInt32(i, 2);
            int64_t _cs_sales_price4515 = tbl_Filter_TD_1193880_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_10332289_payload_rightMajor payloadA{_cs_sold_date_sk4494, _cs_call_center_sk4505, _cs_item_sk4509, _cs_sales_price4515};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_11715245_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk4472_k = tbl_Filter_TD_11715245_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10332289_key_rightMajor{_i_item_sk4472_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk4494 = (it->second)._cs_sold_date_sk4494;
                int32_t _cs_call_center_sk4505 = (it->second)._cs_call_center_sk4505;
                int32_t _cs_item_sk4509 = (it->second)._cs_item_sk4509;
                int64_t _cs_sales_price4515 = (it->second)._cs_sales_price4515;
                int32_t _i_item_sk4472 = tbl_Filter_TD_11715245_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4480_n = tbl_Filter_TD_11715245_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_brand4480 = std::string(_i_brand4480_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_category4484_n = tbl_Filter_TD_11715245_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _i_category4484 = std::string(_i_category4484_n.data());
                tbl_JOIN_INNER_TD_10332289_output.setInt32(r, 2, _cs_sold_date_sk4494);
                tbl_JOIN_INNER_TD_10332289_output.setInt32(r, 3, _cs_call_center_sk4505);
                tbl_JOIN_INNER_TD_10332289_output.setInt64(r, 4, _cs_sales_price4515);
                tbl_JOIN_INNER_TD_10332289_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand4480_n);
                tbl_JOIN_INNER_TD_10332289_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category4484_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10332289_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_10332289_output #Row: " << tbl_JOIN_INNER_TD_10332289_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10422941(Table &tbl_SerializeFromObject_TD_11945483_input, Table &tbl_Filter_TD_10422941_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cc_call_center_sk#4436) AND isnotnull(cc_name#4442)))
    // Input: ListBuffer(cc_call_center_sk#4436, cc_name#4442)
    // Output: ListBuffer(cc_call_center_sk#4436, cc_name#4442)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11945483_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cc_call_center_sk4436 = tbl_SerializeFromObject_TD_11945483_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name4442 = tbl_SerializeFromObject_TD_11945483_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_cc_call_center_sk4436!= 0) && _cc_name4442.data() != "NULL") {
            int32_t _cc_call_center_sk4436_t = tbl_SerializeFromObject_TD_11945483_input.getInt32(i, 0);
            tbl_Filter_TD_10422941_output.setInt32(r, 0, _cc_call_center_sk4436_t);
            std::array<char, TPCDS_READ_MAX + 1> _cc_name4442_t = tbl_SerializeFromObject_TD_11945483_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_10422941_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cc_name4442_t);
            r++;
        }
    }
    tbl_Filter_TD_10422941_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10422941_output #Row: " << tbl_Filter_TD_10422941_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_10462332_key_leftMajor {
    int32_t _cs_sold_date_sk4374;
    bool operator==(const SW_JOIN_INNER_TD_10462332_key_leftMajor& other) const {
        return ((_cs_sold_date_sk4374 == other._cs_sold_date_sk4374));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10462332_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10462332_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_sold_date_sk4374));
    }
};
}
struct SW_JOIN_INNER_TD_10462332_payload_leftMajor {
    std::string _i_brand4360;
    std::string _i_category4364;
    int32_t _cs_sold_date_sk4374;
    int32_t _cs_call_center_sk4385;
    int64_t _cs_sales_price4395;
};
struct SW_JOIN_INNER_TD_10462332_key_rightMajor {
    int32_t _d_date_sk4408;
    bool operator==(const SW_JOIN_INNER_TD_10462332_key_rightMajor& other) const {
        return ((_d_date_sk4408 == other._d_date_sk4408));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10462332_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10462332_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk4408));
    }
};
}
struct SW_JOIN_INNER_TD_10462332_payload_rightMajor {
    int32_t _d_date_sk4408;
    int32_t _d_year4414;
    int32_t _d_moy4416;
};
void SW_JOIN_INNER_TD_10462332(Table &tbl_JOIN_INNER_TD_11646117_output, Table &tbl_Filter_TD_11656057_output, Table &tbl_JOIN_INNER_TD_10462332_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_sold_date_sk#4374 = d_date_sk#4408))
    // Left Table: ListBuffer(i_brand#4360, i_category#4364, cs_sold_date_sk#4374, cs_call_center_sk#4385, cs_sales_price#4395)
    // Right Table: ListBuffer(d_date_sk#4408, d_year#4414, d_moy#4416)
    // Output Table: ListBuffer(i_brand#4360, i_category#4364, cs_call_center_sk#4385, cs_sales_price#4395, d_year#4414, d_moy#4416)
    int left_nrow = tbl_JOIN_INNER_TD_11646117_output.getNumRow();
    int right_nrow = tbl_Filter_TD_11656057_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10462332_key_leftMajor, SW_JOIN_INNER_TD_10462332_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_11646117_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_sold_date_sk4374_k = tbl_JOIN_INNER_TD_11646117_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_10462332_key_leftMajor keyA{_cs_sold_date_sk4374_k};
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4360_n = tbl_JOIN_INNER_TD_11646117_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_brand4360 = std::string(_i_brand4360_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_category4364_n = tbl_JOIN_INNER_TD_11646117_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_category4364 = std::string(_i_category4364_n.data());
            int32_t _cs_sold_date_sk4374 = tbl_JOIN_INNER_TD_11646117_output.getInt32(i, 2);
            int32_t _cs_call_center_sk4385 = tbl_JOIN_INNER_TD_11646117_output.getInt32(i, 3);
            int64_t _cs_sales_price4395 = tbl_JOIN_INNER_TD_11646117_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_10462332_payload_leftMajor payloadA{_i_brand4360, _i_category4364, _cs_sold_date_sk4374, _cs_call_center_sk4385, _cs_sales_price4395};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_11656057_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk4408_k = tbl_Filter_TD_11656057_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10462332_key_leftMajor{_d_date_sk4408_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _i_brand4360 = (it->second)._i_brand4360;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4360_n{};
                memcpy(_i_brand4360_n.data(), (_i_brand4360).data(), (_i_brand4360).length());
                std::string _i_category4364 = (it->second)._i_category4364;
                std::array<char, TPCDS_READ_MAX + 1> _i_category4364_n{};
                memcpy(_i_category4364_n.data(), (_i_category4364).data(), (_i_category4364).length());
                int32_t _cs_sold_date_sk4374 = (it->second)._cs_sold_date_sk4374;
                int32_t _cs_call_center_sk4385 = (it->second)._cs_call_center_sk4385;
                int64_t _cs_sales_price4395 = (it->second)._cs_sales_price4395;
                int32_t _d_date_sk4408 = tbl_Filter_TD_11656057_output.getInt32(i, 0);
                int32_t _d_year4414 = tbl_Filter_TD_11656057_output.getInt32(i, 1);
                int32_t _d_moy4416 = tbl_Filter_TD_11656057_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_10462332_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand4360_n);
                tbl_JOIN_INNER_TD_10462332_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category4364_n);
                tbl_JOIN_INNER_TD_10462332_output.setInt32(r, 2, _cs_call_center_sk4385);
                tbl_JOIN_INNER_TD_10462332_output.setInt64(r, 3, _cs_sales_price4395);
                tbl_JOIN_INNER_TD_10462332_output.setInt32(r, 4, _d_year4414);
                tbl_JOIN_INNER_TD_10462332_output.setInt32(r, 5, _d_moy4416);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10462332_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10462332_key_rightMajor, SW_JOIN_INNER_TD_10462332_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_11656057_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk4408_k = tbl_Filter_TD_11656057_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_10462332_key_rightMajor keyA{_d_date_sk4408_k};
            int32_t _d_date_sk4408 = tbl_Filter_TD_11656057_output.getInt32(i, 0);
            int32_t _d_year4414 = tbl_Filter_TD_11656057_output.getInt32(i, 1);
            int32_t _d_moy4416 = tbl_Filter_TD_11656057_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_10462332_payload_rightMajor payloadA{_d_date_sk4408, _d_year4414, _d_moy4416};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_11646117_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_sold_date_sk4374_k = tbl_JOIN_INNER_TD_11646117_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10462332_key_rightMajor{_cs_sold_date_sk4374_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk4408 = (it->second)._d_date_sk4408;
                int32_t _d_year4414 = (it->second)._d_year4414;
                int32_t _d_moy4416 = (it->second)._d_moy4416;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4360_n = tbl_JOIN_INNER_TD_11646117_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _i_brand4360 = std::string(_i_brand4360_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_category4364_n = tbl_JOIN_INNER_TD_11646117_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_category4364 = std::string(_i_category4364_n.data());
                int32_t _cs_sold_date_sk4374 = tbl_JOIN_INNER_TD_11646117_output.getInt32(i, 2);
                int32_t _cs_call_center_sk4385 = tbl_JOIN_INNER_TD_11646117_output.getInt32(i, 3);
                int64_t _cs_sales_price4395 = tbl_JOIN_INNER_TD_11646117_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_10462332_output.setInt32(r, 4, _d_year4414);
                tbl_JOIN_INNER_TD_10462332_output.setInt32(r, 5, _d_moy4416);
                tbl_JOIN_INNER_TD_10462332_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand4360_n);
                tbl_JOIN_INNER_TD_10462332_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category4364_n);
                tbl_JOIN_INNER_TD_10462332_output.setInt32(r, 2, _cs_call_center_sk4385);
                tbl_JOIN_INNER_TD_10462332_output.setInt64(r, 3, _cs_sales_price4395);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10462332_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_10462332_output #Row: " << tbl_JOIN_INNER_TD_10462332_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_10376037_key {
    std::string _i_category240;
    std::string _i_brand236;
    std::string _cc_name909;
    int32_t _d_year126;
    int32_t _d_moy128;
    bool operator==(const SW_Aggregate_TD_10376037_key& other) const { return (_i_category240 == other._i_category240) && (_i_brand236 == other._i_brand236) && (_cc_name909 == other._cc_name909) && (_d_year126 == other._d_year126) && (_d_moy128 == other._d_moy128); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_10376037_key> {
    std::size_t operator() (const SW_Aggregate_TD_10376037_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_category240)) + (hash<string>()(k._i_brand236)) + (hash<string>()(k._cc_name909)) + (hash<int32_t>()(k._d_year126)) + (hash<int32_t>()(k._d_moy128));
    }
};
}
struct SW_Aggregate_TD_10376037_payload {
    int64_t _sum_sales3544_sum_0;
    int64_t __w03558_sum_1;
};
void SW_Aggregate_TD_10376037(Table &tbl_JOIN_INNER_TD_113015_output, Table &tbl_Aggregate_TD_10376037_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(i_category#240, i_brand#236, cc_name#909, d_year#126, d_moy#128, MakeDecimal(sum(UnscaledValue(cs_sales_price#1125)),17,2) AS sum_sales#3544, MakeDecimal(sum(UnscaledValue(cs_sales_price#1125)),17,2) AS _w0#3558)
    // Input: ListBuffer(i_brand#236, i_category#240, cs_sales_price#1125, d_year#126, d_moy#128, cc_name#909)
    // Output: ListBuffer(i_category#240, i_brand#236, cc_name#909, d_year#126, d_moy#128, sum_sales#3544, _w0#3558)
    std::unordered_map<SW_Aggregate_TD_10376037_key, SW_Aggregate_TD_10376037_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_113015_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236 = tbl_JOIN_INNER_TD_113015_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_category240 = tbl_JOIN_INNER_TD_113015_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_113015_output.getInt64(i, 2);
        int32_t _d_year126 = tbl_JOIN_INNER_TD_113015_output.getInt32(i, 3);
        int32_t _d_moy128 = tbl_JOIN_INNER_TD_113015_output.getInt32(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name909 = tbl_JOIN_INNER_TD_113015_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        SW_Aggregate_TD_10376037_key k{std::string(_i_category240.data()), std::string(_i_brand236.data()), std::string(_cc_name909.data()), _d_year126, _d_moy128};
        int64_t _sum_sales3544_sum_0 = _cs_sales_price1125;
        int64_t __w03558_sum_1 = _cs_sales_price1125;
        SW_Aggregate_TD_10376037_payload p{_sum_sales3544_sum_0, __w03558_sum_1};
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
        tbl_Aggregate_TD_10376037_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category240);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236{};
        memcpy(_i_brand236.data(), ((it.first)._i_brand236).data(), ((it.first)._i_brand236).length());
        tbl_Aggregate_TD_10376037_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand236);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name909{};
        memcpy(_cc_name909.data(), ((it.first)._cc_name909).data(), ((it.first)._cc_name909).length());
        tbl_Aggregate_TD_10376037_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_name909);
        tbl_Aggregate_TD_10376037_output.setInt32(r, 3, (it.first)._d_year126);
        tbl_Aggregate_TD_10376037_output.setInt32(r, 4, (it.first)._d_moy128);
        int64_t _sum_sales3544 = (it.second)._sum_sales3544_sum_0;
        tbl_Aggregate_TD_10376037_output.setInt64(r, 5, _sum_sales3544);
        int64_t __w03558 = (it.second).__w03558_sum_1;
        tbl_Aggregate_TD_10376037_output.setInt64(r, 6, __w03558);
        ++r;
    }
    tbl_Aggregate_TD_10376037_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_10376037_output #Row: " << tbl_Aggregate_TD_10376037_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9968509(Table &tbl_SerializeFromObject_TD_10909689_input, Table &tbl_Filter_TD_9968509_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cc_call_center_sk#4556) AND isnotnull(cc_name#4562)))
    // Input: ListBuffer(cc_call_center_sk#4556, cc_name#4562)
    // Output: ListBuffer(cc_call_center_sk#4556, cc_name#4562)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10909689_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cc_call_center_sk4556 = tbl_SerializeFromObject_TD_10909689_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name4562 = tbl_SerializeFromObject_TD_10909689_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_cc_call_center_sk4556!= 0) && _cc_name4562.data() != "NULL") {
            int32_t _cc_call_center_sk4556_t = tbl_SerializeFromObject_TD_10909689_input.getInt32(i, 0);
            tbl_Filter_TD_9968509_output.setInt32(r, 0, _cc_call_center_sk4556_t);
            std::array<char, TPCDS_READ_MAX + 1> _cc_name4562_t = tbl_SerializeFromObject_TD_10909689_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_9968509_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cc_name4562_t);
            r++;
        }
    }
    tbl_Filter_TD_9968509_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9968509_output #Row: " << tbl_Filter_TD_9968509_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_9514904_key_leftMajor {
    int32_t _cs_sold_date_sk4494;
    bool operator==(const SW_JOIN_INNER_TD_9514904_key_leftMajor& other) const {
        return ((_cs_sold_date_sk4494 == other._cs_sold_date_sk4494));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9514904_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9514904_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_sold_date_sk4494));
    }
};
}
struct SW_JOIN_INNER_TD_9514904_payload_leftMajor {
    std::string _i_brand4480;
    std::string _i_category4484;
    int32_t _cs_sold_date_sk4494;
    int32_t _cs_call_center_sk4505;
    int64_t _cs_sales_price4515;
};
struct SW_JOIN_INNER_TD_9514904_key_rightMajor {
    int32_t _d_date_sk4528;
    bool operator==(const SW_JOIN_INNER_TD_9514904_key_rightMajor& other) const {
        return ((_d_date_sk4528 == other._d_date_sk4528));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9514904_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9514904_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk4528));
    }
};
}
struct SW_JOIN_INNER_TD_9514904_payload_rightMajor {
    int32_t _d_date_sk4528;
    int32_t _d_year4534;
    int32_t _d_moy4536;
};
void SW_JOIN_INNER_TD_9514904(Table &tbl_JOIN_INNER_TD_10332289_output, Table &tbl_Filter_TD_10827249_output, Table &tbl_JOIN_INNER_TD_9514904_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_sold_date_sk#4494 = d_date_sk#4528))
    // Left Table: ListBuffer(i_brand#4480, i_category#4484, cs_sold_date_sk#4494, cs_call_center_sk#4505, cs_sales_price#4515)
    // Right Table: ListBuffer(d_date_sk#4528, d_year#4534, d_moy#4536)
    // Output Table: ListBuffer(i_brand#4480, i_category#4484, cs_call_center_sk#4505, cs_sales_price#4515, d_year#4534, d_moy#4536)
    int left_nrow = tbl_JOIN_INNER_TD_10332289_output.getNumRow();
    int right_nrow = tbl_Filter_TD_10827249_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9514904_key_leftMajor, SW_JOIN_INNER_TD_9514904_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_10332289_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_sold_date_sk4494_k = tbl_JOIN_INNER_TD_10332289_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_9514904_key_leftMajor keyA{_cs_sold_date_sk4494_k};
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4480_n = tbl_JOIN_INNER_TD_10332289_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_brand4480 = std::string(_i_brand4480_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_category4484_n = tbl_JOIN_INNER_TD_10332289_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_category4484 = std::string(_i_category4484_n.data());
            int32_t _cs_sold_date_sk4494 = tbl_JOIN_INNER_TD_10332289_output.getInt32(i, 2);
            int32_t _cs_call_center_sk4505 = tbl_JOIN_INNER_TD_10332289_output.getInt32(i, 3);
            int64_t _cs_sales_price4515 = tbl_JOIN_INNER_TD_10332289_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_9514904_payload_leftMajor payloadA{_i_brand4480, _i_category4484, _cs_sold_date_sk4494, _cs_call_center_sk4505, _cs_sales_price4515};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_10827249_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk4528_k = tbl_Filter_TD_10827249_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9514904_key_leftMajor{_d_date_sk4528_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _i_brand4480 = (it->second)._i_brand4480;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4480_n{};
                memcpy(_i_brand4480_n.data(), (_i_brand4480).data(), (_i_brand4480).length());
                std::string _i_category4484 = (it->second)._i_category4484;
                std::array<char, TPCDS_READ_MAX + 1> _i_category4484_n{};
                memcpy(_i_category4484_n.data(), (_i_category4484).data(), (_i_category4484).length());
                int32_t _cs_sold_date_sk4494 = (it->second)._cs_sold_date_sk4494;
                int32_t _cs_call_center_sk4505 = (it->second)._cs_call_center_sk4505;
                int64_t _cs_sales_price4515 = (it->second)._cs_sales_price4515;
                int32_t _d_date_sk4528 = tbl_Filter_TD_10827249_output.getInt32(i, 0);
                int32_t _d_year4534 = tbl_Filter_TD_10827249_output.getInt32(i, 1);
                int32_t _d_moy4536 = tbl_Filter_TD_10827249_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_9514904_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand4480_n);
                tbl_JOIN_INNER_TD_9514904_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category4484_n);
                tbl_JOIN_INNER_TD_9514904_output.setInt32(r, 2, _cs_call_center_sk4505);
                tbl_JOIN_INNER_TD_9514904_output.setInt64(r, 3, _cs_sales_price4515);
                tbl_JOIN_INNER_TD_9514904_output.setInt32(r, 4, _d_year4534);
                tbl_JOIN_INNER_TD_9514904_output.setInt32(r, 5, _d_moy4536);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9514904_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9514904_key_rightMajor, SW_JOIN_INNER_TD_9514904_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_10827249_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk4528_k = tbl_Filter_TD_10827249_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_9514904_key_rightMajor keyA{_d_date_sk4528_k};
            int32_t _d_date_sk4528 = tbl_Filter_TD_10827249_output.getInt32(i, 0);
            int32_t _d_year4534 = tbl_Filter_TD_10827249_output.getInt32(i, 1);
            int32_t _d_moy4536 = tbl_Filter_TD_10827249_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_9514904_payload_rightMajor payloadA{_d_date_sk4528, _d_year4534, _d_moy4536};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_10332289_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_sold_date_sk4494_k = tbl_JOIN_INNER_TD_10332289_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9514904_key_rightMajor{_cs_sold_date_sk4494_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk4528 = (it->second)._d_date_sk4528;
                int32_t _d_year4534 = (it->second)._d_year4534;
                int32_t _d_moy4536 = (it->second)._d_moy4536;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4480_n = tbl_JOIN_INNER_TD_10332289_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _i_brand4480 = std::string(_i_brand4480_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_category4484_n = tbl_JOIN_INNER_TD_10332289_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_category4484 = std::string(_i_category4484_n.data());
                int32_t _cs_sold_date_sk4494 = tbl_JOIN_INNER_TD_10332289_output.getInt32(i, 2);
                int32_t _cs_call_center_sk4505 = tbl_JOIN_INNER_TD_10332289_output.getInt32(i, 3);
                int64_t _cs_sales_price4515 = tbl_JOIN_INNER_TD_10332289_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_9514904_output.setInt32(r, 4, _d_year4534);
                tbl_JOIN_INNER_TD_9514904_output.setInt32(r, 5, _d_moy4536);
                tbl_JOIN_INNER_TD_9514904_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand4480_n);
                tbl_JOIN_INNER_TD_9514904_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category4484_n);
                tbl_JOIN_INNER_TD_9514904_output.setInt32(r, 2, _cs_call_center_sk4505);
                tbl_JOIN_INNER_TD_9514904_output.setInt64(r, 3, _cs_sales_price4515);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9514904_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_9514904_output #Row: " << tbl_JOIN_INNER_TD_9514904_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_9160603_key_leftMajor {
    int32_t _cs_call_center_sk4385;
    bool operator==(const SW_JOIN_INNER_TD_9160603_key_leftMajor& other) const {
        return ((_cs_call_center_sk4385 == other._cs_call_center_sk4385));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9160603_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9160603_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_call_center_sk4385));
    }
};
}
struct SW_JOIN_INNER_TD_9160603_payload_leftMajor {
    std::string _i_brand4360;
    std::string _i_category4364;
    int32_t _cs_call_center_sk4385;
    int64_t _cs_sales_price4395;
    int32_t _d_year4414;
    int32_t _d_moy4416;
};
struct SW_JOIN_INNER_TD_9160603_key_rightMajor {
    int32_t _cc_call_center_sk4436;
    bool operator==(const SW_JOIN_INNER_TD_9160603_key_rightMajor& other) const {
        return ((_cc_call_center_sk4436 == other._cc_call_center_sk4436));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9160603_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9160603_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cc_call_center_sk4436));
    }
};
}
struct SW_JOIN_INNER_TD_9160603_payload_rightMajor {
    int32_t _cc_call_center_sk4436;
    std::string _cc_name4442;
};
void SW_JOIN_INNER_TD_9160603(Table &tbl_JOIN_INNER_TD_10462332_output, Table &tbl_Filter_TD_10422941_output, Table &tbl_JOIN_INNER_TD_9160603_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cc_call_center_sk#4436 = cs_call_center_sk#4385))
    // Left Table: ListBuffer(i_brand#4360, i_category#4364, cs_call_center_sk#4385, cs_sales_price#4395, d_year#4414, d_moy#4416)
    // Right Table: ListBuffer(cc_call_center_sk#4436, cc_name#4442)
    // Output Table: ListBuffer(i_brand#4360, i_category#4364, cs_sales_price#4395, d_year#4414, d_moy#4416, cc_name#4442)
    int left_nrow = tbl_JOIN_INNER_TD_10462332_output.getNumRow();
    int right_nrow = tbl_Filter_TD_10422941_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9160603_key_leftMajor, SW_JOIN_INNER_TD_9160603_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_10462332_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_call_center_sk4385_k = tbl_JOIN_INNER_TD_10462332_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_9160603_key_leftMajor keyA{_cs_call_center_sk4385_k};
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4360_n = tbl_JOIN_INNER_TD_10462332_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_brand4360 = std::string(_i_brand4360_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_category4364_n = tbl_JOIN_INNER_TD_10462332_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_category4364 = std::string(_i_category4364_n.data());
            int32_t _cs_call_center_sk4385 = tbl_JOIN_INNER_TD_10462332_output.getInt32(i, 2);
            int64_t _cs_sales_price4395 = tbl_JOIN_INNER_TD_10462332_output.getInt64(i, 3);
            int32_t _d_year4414 = tbl_JOIN_INNER_TD_10462332_output.getInt32(i, 4);
            int32_t _d_moy4416 = tbl_JOIN_INNER_TD_10462332_output.getInt32(i, 5);
            SW_JOIN_INNER_TD_9160603_payload_leftMajor payloadA{_i_brand4360, _i_category4364, _cs_call_center_sk4385, _cs_sales_price4395, _d_year4414, _d_moy4416};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_10422941_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cc_call_center_sk4436_k = tbl_Filter_TD_10422941_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9160603_key_leftMajor{_cc_call_center_sk4436_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _i_brand4360 = (it->second)._i_brand4360;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4360_n{};
                memcpy(_i_brand4360_n.data(), (_i_brand4360).data(), (_i_brand4360).length());
                std::string _i_category4364 = (it->second)._i_category4364;
                std::array<char, TPCDS_READ_MAX + 1> _i_category4364_n{};
                memcpy(_i_category4364_n.data(), (_i_category4364).data(), (_i_category4364).length());
                int32_t _cs_call_center_sk4385 = (it->second)._cs_call_center_sk4385;
                int64_t _cs_sales_price4395 = (it->second)._cs_sales_price4395;
                int32_t _d_year4414 = (it->second)._d_year4414;
                int32_t _d_moy4416 = (it->second)._d_moy4416;
                int32_t _cc_call_center_sk4436 = tbl_Filter_TD_10422941_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _cc_name4442_n = tbl_Filter_TD_10422941_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _cc_name4442 = std::string(_cc_name4442_n.data());
                tbl_JOIN_INNER_TD_9160603_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand4360_n);
                tbl_JOIN_INNER_TD_9160603_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category4364_n);
                tbl_JOIN_INNER_TD_9160603_output.setInt64(r, 2, _cs_sales_price4395);
                tbl_JOIN_INNER_TD_9160603_output.setInt32(r, 3, _d_year4414);
                tbl_JOIN_INNER_TD_9160603_output.setInt32(r, 4, _d_moy4416);
                tbl_JOIN_INNER_TD_9160603_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _cc_name4442_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9160603_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9160603_key_rightMajor, SW_JOIN_INNER_TD_9160603_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_10422941_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cc_call_center_sk4436_k = tbl_Filter_TD_10422941_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_9160603_key_rightMajor keyA{_cc_call_center_sk4436_k};
            int32_t _cc_call_center_sk4436 = tbl_Filter_TD_10422941_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _cc_name4442_n = tbl_Filter_TD_10422941_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cc_name4442 = std::string(_cc_name4442_n.data());
            SW_JOIN_INNER_TD_9160603_payload_rightMajor payloadA{_cc_call_center_sk4436, _cc_name4442};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_10462332_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_call_center_sk4385_k = tbl_JOIN_INNER_TD_10462332_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9160603_key_rightMajor{_cs_call_center_sk4385_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cc_call_center_sk4436 = (it->second)._cc_call_center_sk4436;
                std::string _cc_name4442 = (it->second)._cc_name4442;
                std::array<char, TPCDS_READ_MAX + 1> _cc_name4442_n{};
                memcpy(_cc_name4442_n.data(), (_cc_name4442).data(), (_cc_name4442).length());
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4360_n = tbl_JOIN_INNER_TD_10462332_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _i_brand4360 = std::string(_i_brand4360_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_category4364_n = tbl_JOIN_INNER_TD_10462332_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_category4364 = std::string(_i_category4364_n.data());
                int32_t _cs_call_center_sk4385 = tbl_JOIN_INNER_TD_10462332_output.getInt32(i, 2);
                int64_t _cs_sales_price4395 = tbl_JOIN_INNER_TD_10462332_output.getInt64(i, 3);
                int32_t _d_year4414 = tbl_JOIN_INNER_TD_10462332_output.getInt32(i, 4);
                int32_t _d_moy4416 = tbl_JOIN_INNER_TD_10462332_output.getInt32(i, 5);
                tbl_JOIN_INNER_TD_9160603_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _cc_name4442_n);
                tbl_JOIN_INNER_TD_9160603_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand4360_n);
                tbl_JOIN_INNER_TD_9160603_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category4364_n);
                tbl_JOIN_INNER_TD_9160603_output.setInt64(r, 2, _cs_sales_price4395);
                tbl_JOIN_INNER_TD_9160603_output.setInt32(r, 3, _d_year4414);
                tbl_JOIN_INNER_TD_9160603_output.setInt32(r, 4, _d_moy4416);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9160603_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_9160603_output #Row: " << tbl_JOIN_INNER_TD_9160603_output.getNumRow() << std::endl;
}

void SW_Window_TD_9852472(Table &tbl_Aggregate_TD_10376037_output, Table &tbl_Window_TD_9852472_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Window
    // Operation: ListBuffer(rank(d_year#126, d_moy#128) windowspecdefinition(i_category#240, i_brand#236, cc_name#909, d_year#126 ASC NULLS FIRST, d_moy#128 ASC NULLS FIRST, specifiedwindowframe(RowFrame, unboundedpreceding$(), currentrow$())) AS rn#3546)
    // Input: ListBuffer(i_category#240, i_brand#236, cc_name#909, d_year#126, d_moy#128, sum_sales#3544, _w0#3558)
    // Output: ListBuffer(i_category#240, i_brand#236, cc_name#909, d_year#126, d_moy#128, sum_sales#3544, _w0#3558, rn#3546)
    struct SW_Window_TD_9852472Row {
        std::string _i_category240;
        std::string _i_brand236;
        std::string _cc_name909;
        int32_t _d_year126;
        int32_t _d_moy128;
        int64_t _sum_sales3544;
        int64_t __w03558;
    }; 

    int nrow = tbl_Aggregate_TD_10376037_output.getNumRow();
    std::vector<SW_Window_TD_9852472Row> rows0;
    int r = 0;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category240 = tbl_Aggregate_TD_10376037_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        tbl_Window_TD_9852472_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _i_category240);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236 = tbl_Aggregate_TD_10376037_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        tbl_Window_TD_9852472_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _i_brand236);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name909 = tbl_Aggregate_TD_10376037_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        tbl_Window_TD_9852472_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _cc_name909);
        int32_t _d_year126 = tbl_Aggregate_TD_10376037_output.getInt32(i, 3);
        tbl_Window_TD_9852472_output.setInt32(r, 3,_d_year126);
        int32_t _d_moy128 = tbl_Aggregate_TD_10376037_output.getInt32(i, 4);
        tbl_Window_TD_9852472_output.setInt32(r, 4,_d_moy128);
        int64_t _sum_sales3544 = tbl_Aggregate_TD_10376037_output.getInt64(i, 5);
        tbl_Window_TD_9852472_output.setInt64(r, 5,_sum_sales3544);
        int64_t __w03558 = tbl_Aggregate_TD_10376037_output.getInt64(i, 6);
        tbl_Window_TD_9852472_output.setInt64(r, 6,__w03558);
        r++;
        SW_Window_TD_9852472Row t = {std::string(_i_category240.data()),std::string(_i_brand236.data()),std::string(_cc_name909.data()),_d_year126,_d_moy128,_sum_sales3544,__w03558};
        rows0.push_back(t);
    }
    struct {
        bool operator()(const SW_Window_TD_9852472Row& a, const SW_Window_TD_9852472Row& b) const { return 
(a._i_category240 < b._i_category240) || 
 ((a._i_category240 == b._i_category240) && (a._i_brand236 < b._i_brand236)) || 
 ((a._i_category240 == b._i_category240) && (a._i_brand236 == b._i_brand236) && (a._cc_name909 < b._cc_name909)) || 
 ((a._i_category240 == b._i_category240) && (a._i_brand236 == b._i_brand236) && (a._cc_name909 == b._cc_name909) && (a._d_year126 < b._d_year126)) || 
 ((a._i_category240 == b._i_category240) && (a._i_brand236 == b._i_brand236) && (a._cc_name909 == b._cc_name909) && (a._d_year126 == b._d_year126) && (a._d_moy128 < b._d_moy128)); 
}
    }SW_Window_TD_9852472_order0; 

    std::sort(rows0.begin(), rows0.end(), SW_Window_TD_9852472_order0);
    std::vector<int32_t> ranks0(rows0.size(), 0);
    int32_t currentRank0 = 0;
    int32_t currentPartitionCount0 = 1;
    bool isSamePartition0 = true;
    bool isSameOrderKey0 = true;
    if (!rows0.empty()) {;
      ranks0[0] = ++currentRank0;
    };
    for (int i = 1; i< rows0.size(); i++) {
        isSamePartition0 = ( rows0[i]._i_category240 == rows0[i-1]._i_category240 && rows0[i]._i_brand236 == rows0[i-1]._i_brand236 && rows0[i]._cc_name909 == rows0[i-1]._cc_name909);
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
        tbl_Window_TD_9852472_output.setInt32(r, 7, ranks0[i]);
    }
    tbl_Window_TD_9852472_output.setNumRow(r);
    std::cout << "tbl_Window_TD_9852472_output #Row: " << tbl_Window_TD_9852472_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8589361_key_leftMajor {
    int32_t _cs_call_center_sk4505;
    bool operator==(const SW_JOIN_INNER_TD_8589361_key_leftMajor& other) const {
        return ((_cs_call_center_sk4505 == other._cs_call_center_sk4505));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8589361_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8589361_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_call_center_sk4505));
    }
};
}
struct SW_JOIN_INNER_TD_8589361_payload_leftMajor {
    std::string _i_brand4480;
    std::string _i_category4484;
    int32_t _cs_call_center_sk4505;
    int64_t _cs_sales_price4515;
    int32_t _d_year4534;
    int32_t _d_moy4536;
};
struct SW_JOIN_INNER_TD_8589361_key_rightMajor {
    int32_t _cc_call_center_sk4556;
    bool operator==(const SW_JOIN_INNER_TD_8589361_key_rightMajor& other) const {
        return ((_cc_call_center_sk4556 == other._cc_call_center_sk4556));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8589361_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8589361_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cc_call_center_sk4556));
    }
};
}
struct SW_JOIN_INNER_TD_8589361_payload_rightMajor {
    int32_t _cc_call_center_sk4556;
    std::string _cc_name4562;
};
void SW_JOIN_INNER_TD_8589361(Table &tbl_JOIN_INNER_TD_9514904_output, Table &tbl_Filter_TD_9968509_output, Table &tbl_JOIN_INNER_TD_8589361_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cc_call_center_sk#4556 = cs_call_center_sk#4505))
    // Left Table: ListBuffer(i_brand#4480, i_category#4484, cs_call_center_sk#4505, cs_sales_price#4515, d_year#4534, d_moy#4536)
    // Right Table: ListBuffer(cc_call_center_sk#4556, cc_name#4562)
    // Output Table: ListBuffer(i_brand#4480, i_category#4484, cs_sales_price#4515, d_year#4534, d_moy#4536, cc_name#4562)
    int left_nrow = tbl_JOIN_INNER_TD_9514904_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9968509_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8589361_key_leftMajor, SW_JOIN_INNER_TD_8589361_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_9514904_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_call_center_sk4505_k = tbl_JOIN_INNER_TD_9514904_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_8589361_key_leftMajor keyA{_cs_call_center_sk4505_k};
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4480_n = tbl_JOIN_INNER_TD_9514904_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_brand4480 = std::string(_i_brand4480_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_category4484_n = tbl_JOIN_INNER_TD_9514904_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_category4484 = std::string(_i_category4484_n.data());
            int32_t _cs_call_center_sk4505 = tbl_JOIN_INNER_TD_9514904_output.getInt32(i, 2);
            int64_t _cs_sales_price4515 = tbl_JOIN_INNER_TD_9514904_output.getInt64(i, 3);
            int32_t _d_year4534 = tbl_JOIN_INNER_TD_9514904_output.getInt32(i, 4);
            int32_t _d_moy4536 = tbl_JOIN_INNER_TD_9514904_output.getInt32(i, 5);
            SW_JOIN_INNER_TD_8589361_payload_leftMajor payloadA{_i_brand4480, _i_category4484, _cs_call_center_sk4505, _cs_sales_price4515, _d_year4534, _d_moy4536};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9968509_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cc_call_center_sk4556_k = tbl_Filter_TD_9968509_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8589361_key_leftMajor{_cc_call_center_sk4556_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _i_brand4480 = (it->second)._i_brand4480;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4480_n{};
                memcpy(_i_brand4480_n.data(), (_i_brand4480).data(), (_i_brand4480).length());
                std::string _i_category4484 = (it->second)._i_category4484;
                std::array<char, TPCDS_READ_MAX + 1> _i_category4484_n{};
                memcpy(_i_category4484_n.data(), (_i_category4484).data(), (_i_category4484).length());
                int32_t _cs_call_center_sk4505 = (it->second)._cs_call_center_sk4505;
                int64_t _cs_sales_price4515 = (it->second)._cs_sales_price4515;
                int32_t _d_year4534 = (it->second)._d_year4534;
                int32_t _d_moy4536 = (it->second)._d_moy4536;
                int32_t _cc_call_center_sk4556 = tbl_Filter_TD_9968509_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _cc_name4562_n = tbl_Filter_TD_9968509_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _cc_name4562 = std::string(_cc_name4562_n.data());
                tbl_JOIN_INNER_TD_8589361_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand4480_n);
                tbl_JOIN_INNER_TD_8589361_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category4484_n);
                tbl_JOIN_INNER_TD_8589361_output.setInt64(r, 2, _cs_sales_price4515);
                tbl_JOIN_INNER_TD_8589361_output.setInt32(r, 3, _d_year4534);
                tbl_JOIN_INNER_TD_8589361_output.setInt32(r, 4, _d_moy4536);
                tbl_JOIN_INNER_TD_8589361_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _cc_name4562_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8589361_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8589361_key_rightMajor, SW_JOIN_INNER_TD_8589361_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9968509_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cc_call_center_sk4556_k = tbl_Filter_TD_9968509_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8589361_key_rightMajor keyA{_cc_call_center_sk4556_k};
            int32_t _cc_call_center_sk4556 = tbl_Filter_TD_9968509_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _cc_name4562_n = tbl_Filter_TD_9968509_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cc_name4562 = std::string(_cc_name4562_n.data());
            SW_JOIN_INNER_TD_8589361_payload_rightMajor payloadA{_cc_call_center_sk4556, _cc_name4562};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_9514904_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_call_center_sk4505_k = tbl_JOIN_INNER_TD_9514904_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8589361_key_rightMajor{_cs_call_center_sk4505_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cc_call_center_sk4556 = (it->second)._cc_call_center_sk4556;
                std::string _cc_name4562 = (it->second)._cc_name4562;
                std::array<char, TPCDS_READ_MAX + 1> _cc_name4562_n{};
                memcpy(_cc_name4562_n.data(), (_cc_name4562).data(), (_cc_name4562).length());
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4480_n = tbl_JOIN_INNER_TD_9514904_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _i_brand4480 = std::string(_i_brand4480_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_category4484_n = tbl_JOIN_INNER_TD_9514904_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_category4484 = std::string(_i_category4484_n.data());
                int32_t _cs_call_center_sk4505 = tbl_JOIN_INNER_TD_9514904_output.getInt32(i, 2);
                int64_t _cs_sales_price4515 = tbl_JOIN_INNER_TD_9514904_output.getInt64(i, 3);
                int32_t _d_year4534 = tbl_JOIN_INNER_TD_9514904_output.getInt32(i, 4);
                int32_t _d_moy4536 = tbl_JOIN_INNER_TD_9514904_output.getInt32(i, 5);
                tbl_JOIN_INNER_TD_8589361_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _cc_name4562_n);
                tbl_JOIN_INNER_TD_8589361_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_brand4480_n);
                tbl_JOIN_INNER_TD_8589361_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category4484_n);
                tbl_JOIN_INNER_TD_8589361_output.setInt64(r, 2, _cs_sales_price4515);
                tbl_JOIN_INNER_TD_8589361_output.setInt32(r, 3, _d_year4534);
                tbl_JOIN_INNER_TD_8589361_output.setInt32(r, 4, _d_moy4536);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8589361_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8589361_output #Row: " << tbl_JOIN_INNER_TD_8589361_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_8279717_key {
    std::string _i_category4364;
    std::string _i_brand4360;
    std::string _cc_name4442;
    int32_t _d_year4414;
    int32_t _d_moy4416;
    bool operator==(const SW_Aggregate_TD_8279717_key& other) const { return (_i_category4364 == other._i_category4364) && (_i_brand4360 == other._i_brand4360) && (_cc_name4442 == other._cc_name4442) && (_d_year4414 == other._d_year4414) && (_d_moy4416 == other._d_moy4416); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_8279717_key> {
    std::size_t operator() (const SW_Aggregate_TD_8279717_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_category4364)) + (hash<string>()(k._i_brand4360)) + (hash<string>()(k._cc_name4442)) + (hash<int32_t>()(k._d_year4414)) + (hash<int32_t>()(k._d_moy4416));
    }
};
}
struct SW_Aggregate_TD_8279717_payload {
    int64_t _sum_sales3544_sum_0;
};
void SW_Aggregate_TD_8279717(Table &tbl_JOIN_INNER_TD_9160603_output, Table &tbl_Aggregate_TD_8279717_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(i_category#4364, i_brand#4360, cc_name#4442, d_year#4414, d_moy#4416, MakeDecimal(sum(UnscaledValue(cs_sales_price#4395)),17,2) AS sum_sales#3544)
    // Input: ListBuffer(i_brand#4360, i_category#4364, cs_sales_price#4395, d_year#4414, d_moy#4416, cc_name#4442)
    // Output: ListBuffer(i_category#4364, i_brand#4360, cc_name#4442, d_year#4414, d_moy#4416, sum_sales#3544)
    std::unordered_map<SW_Aggregate_TD_8279717_key, SW_Aggregate_TD_8279717_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_9160603_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_brand4360 = tbl_JOIN_INNER_TD_9160603_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_category4364 = tbl_JOIN_INNER_TD_9160603_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int64_t _cs_sales_price4395 = tbl_JOIN_INNER_TD_9160603_output.getInt64(i, 2);
        int32_t _d_year4414 = tbl_JOIN_INNER_TD_9160603_output.getInt32(i, 3);
        int32_t _d_moy4416 = tbl_JOIN_INNER_TD_9160603_output.getInt32(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name4442 = tbl_JOIN_INNER_TD_9160603_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        SW_Aggregate_TD_8279717_key k{std::string(_i_category4364.data()), std::string(_i_brand4360.data()), std::string(_cc_name4442.data()), _d_year4414, _d_moy4416};
        int64_t _sum_sales3544_sum_0 = _cs_sales_price4395;
        SW_Aggregate_TD_8279717_payload p{_sum_sales3544_sum_0};
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
        std::array<char, TPCDS_READ_MAX + 1> _i_category4364{};
        memcpy(_i_category4364.data(), ((it.first)._i_category4364).data(), ((it.first)._i_category4364).length());
        tbl_Aggregate_TD_8279717_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category4364);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand4360{};
        memcpy(_i_brand4360.data(), ((it.first)._i_brand4360).data(), ((it.first)._i_brand4360).length());
        tbl_Aggregate_TD_8279717_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand4360);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name4442{};
        memcpy(_cc_name4442.data(), ((it.first)._cc_name4442).data(), ((it.first)._cc_name4442).length());
        tbl_Aggregate_TD_8279717_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_name4442);
        tbl_Aggregate_TD_8279717_output.setInt32(r, 3, (it.first)._d_year4414);
        tbl_Aggregate_TD_8279717_output.setInt32(r, 4, (it.first)._d_moy4416);
        int64_t _sum_sales3544 = (it.second)._sum_sales3544_sum_0;
        tbl_Aggregate_TD_8279717_output.setInt64(r, 5, _sum_sales3544);
        ++r;
    }
    tbl_Aggregate_TD_8279717_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_8279717_output #Row: " << tbl_Aggregate_TD_8279717_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8164128(Table &tbl_Window_TD_9852472_output, Table &tbl_Filter_TD_8164128_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(d_year#126) AND (d_year#126 = 1999)))
    // Input: ListBuffer(i_category#240, i_brand#236, cc_name#909, d_year#126, d_moy#128, sum_sales#3544, _w0#3558, rn#3546)
    // Output: ListBuffer(i_category#240, i_brand#236, cc_name#909, d_year#126, d_moy#128, sum_sales#3544, _w0#3558, rn#3546)
    int r = 0;
    int nrow1 = tbl_Window_TD_9852472_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_Window_TD_9852472_output.getInt32(i, 3);
        if ((_d_year126!= 0) && (_d_year126 == 1999)) {
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_t = tbl_Window_TD_9852472_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            tbl_Filter_TD_8164128_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category240_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_t = tbl_Window_TD_9852472_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_8164128_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand236_t);
            std::array<char, TPCDS_READ_MAX + 1> _cc_name909_t = tbl_Window_TD_9852472_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_8164128_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_name909_t);
            int32_t _d_year126_t = tbl_Window_TD_9852472_output.getInt32(i, 3);
            tbl_Filter_TD_8164128_output.setInt32(r, 3, _d_year126_t);
            int32_t _d_moy128_t = tbl_Window_TD_9852472_output.getInt32(i, 4);
            tbl_Filter_TD_8164128_output.setInt32(r, 4, _d_moy128_t);
            int64_t _sum_sales3544_t = tbl_Window_TD_9852472_output.getInt64(i, 5);
            tbl_Filter_TD_8164128_output.setInt64(r, 5, _sum_sales3544_t);
            int64_t __w03558_t = tbl_Window_TD_9852472_output.getInt64(i, 6);
            tbl_Filter_TD_8164128_output.setInt64(r, 6, __w03558_t);
            int32_t _rn3546_t = tbl_Window_TD_9852472_output.getInt32(i, 7);
            tbl_Filter_TD_8164128_output.setInt32(r, 7, _rn3546_t);
            r++;
        }
    }
    tbl_Filter_TD_8164128_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8164128_output #Row: " << tbl_Filter_TD_8164128_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_7738360_key {
    std::string _i_category4484;
    std::string _i_brand4480;
    std::string _cc_name4562;
    int32_t _d_year4534;
    int32_t _d_moy4536;
    bool operator==(const SW_Aggregate_TD_7738360_key& other) const { return (_i_category4484 == other._i_category4484) && (_i_brand4480 == other._i_brand4480) && (_cc_name4562 == other._cc_name4562) && (_d_year4534 == other._d_year4534) && (_d_moy4536 == other._d_moy4536); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_7738360_key> {
    std::size_t operator() (const SW_Aggregate_TD_7738360_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_category4484)) + (hash<string>()(k._i_brand4480)) + (hash<string>()(k._cc_name4562)) + (hash<int32_t>()(k._d_year4534)) + (hash<int32_t>()(k._d_moy4536));
    }
};
}
struct SW_Aggregate_TD_7738360_payload {
    int64_t _sum_sales3544_sum_0;
};
void SW_Aggregate_TD_7738360(Table &tbl_JOIN_INNER_TD_8589361_output, Table &tbl_Aggregate_TD_7738360_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(i_category#4484, i_brand#4480, cc_name#4562, d_year#4534, d_moy#4536, MakeDecimal(sum(UnscaledValue(cs_sales_price#4515)),17,2) AS sum_sales#3544)
    // Input: ListBuffer(i_brand#4480, i_category#4484, cs_sales_price#4515, d_year#4534, d_moy#4536, cc_name#4562)
    // Output: ListBuffer(i_category#4484, i_brand#4480, cc_name#4562, d_year#4534, d_moy#4536, sum_sales#3544)
    std::unordered_map<SW_Aggregate_TD_7738360_key, SW_Aggregate_TD_7738360_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_8589361_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_brand4480 = tbl_JOIN_INNER_TD_8589361_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_category4484 = tbl_JOIN_INNER_TD_8589361_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int64_t _cs_sales_price4515 = tbl_JOIN_INNER_TD_8589361_output.getInt64(i, 2);
        int32_t _d_year4534 = tbl_JOIN_INNER_TD_8589361_output.getInt32(i, 3);
        int32_t _d_moy4536 = tbl_JOIN_INNER_TD_8589361_output.getInt32(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name4562 = tbl_JOIN_INNER_TD_8589361_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        SW_Aggregate_TD_7738360_key k{std::string(_i_category4484.data()), std::string(_i_brand4480.data()), std::string(_cc_name4562.data()), _d_year4534, _d_moy4536};
        int64_t _sum_sales3544_sum_0 = _cs_sales_price4515;
        SW_Aggregate_TD_7738360_payload p{_sum_sales3544_sum_0};
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
        std::array<char, TPCDS_READ_MAX + 1> _i_category4484{};
        memcpy(_i_category4484.data(), ((it.first)._i_category4484).data(), ((it.first)._i_category4484).length());
        tbl_Aggregate_TD_7738360_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category4484);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand4480{};
        memcpy(_i_brand4480.data(), ((it.first)._i_brand4480).data(), ((it.first)._i_brand4480).length());
        tbl_Aggregate_TD_7738360_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand4480);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name4562{};
        memcpy(_cc_name4562.data(), ((it.first)._cc_name4562).data(), ((it.first)._cc_name4562).length());
        tbl_Aggregate_TD_7738360_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_name4562);
        tbl_Aggregate_TD_7738360_output.setInt32(r, 3, (it.first)._d_year4534);
        tbl_Aggregate_TD_7738360_output.setInt32(r, 4, (it.first)._d_moy4536);
        int64_t _sum_sales3544 = (it.second)._sum_sales3544_sum_0;
        tbl_Aggregate_TD_7738360_output.setInt64(r, 5, _sum_sales3544);
        ++r;
    }
    tbl_Aggregate_TD_7738360_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_7738360_output #Row: " << tbl_Aggregate_TD_7738360_output.getNumRow() << std::endl;
}

void SW_Window_TD_7331027(Table &tbl_Aggregate_TD_8279717_output, Table &tbl_Window_TD_7331027_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Window
    // Operation: ListBuffer(rank(d_year#4414, d_moy#4416) windowspecdefinition(i_category#4364, i_brand#4360, cc_name#4442, d_year#4414 ASC NULLS FIRST, d_moy#4416 ASC NULLS FIRST, specifiedwindowframe(RowFrame, unboundedpreceding$(), currentrow$())) AS rn#4471)
    // Input: ListBuffer(i_category#4364, i_brand#4360, cc_name#4442, d_year#4414, d_moy#4416, sum_sales#3544)
    // Output: ListBuffer(i_category#4364, i_brand#4360, cc_name#4442, d_year#4414, d_moy#4416, sum_sales#3544, rn#4471)
    struct SW_Window_TD_7331027Row {
        std::string _i_category4364;
        std::string _i_brand4360;
        std::string _cc_name4442;
        int32_t _d_year4414;
        int32_t _d_moy4416;
        int64_t _sum_sales3544;
    }; 

    int nrow = tbl_Aggregate_TD_8279717_output.getNumRow();
    std::vector<SW_Window_TD_7331027Row> rows0;
    int r = 0;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category4364 = tbl_Aggregate_TD_8279717_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        tbl_Window_TD_7331027_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _i_category4364);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand4360 = tbl_Aggregate_TD_8279717_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        tbl_Window_TD_7331027_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _i_brand4360);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name4442 = tbl_Aggregate_TD_8279717_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        tbl_Window_TD_7331027_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _cc_name4442);
        int32_t _d_year4414 = tbl_Aggregate_TD_8279717_output.getInt32(i, 3);
        tbl_Window_TD_7331027_output.setInt32(r, 3,_d_year4414);
        int32_t _d_moy4416 = tbl_Aggregate_TD_8279717_output.getInt32(i, 4);
        tbl_Window_TD_7331027_output.setInt32(r, 4,_d_moy4416);
        int64_t _sum_sales3544 = tbl_Aggregate_TD_8279717_output.getInt64(i, 5);
        tbl_Window_TD_7331027_output.setInt64(r, 5,_sum_sales3544);
        r++;
        SW_Window_TD_7331027Row t = {std::string(_i_category4364.data()),std::string(_i_brand4360.data()),std::string(_cc_name4442.data()),_d_year4414,_d_moy4416,_sum_sales3544};
        rows0.push_back(t);
    }
    struct {
        bool operator()(const SW_Window_TD_7331027Row& a, const SW_Window_TD_7331027Row& b) const { return 
(a._i_category4364 < b._i_category4364) || 
 ((a._i_category4364 == b._i_category4364) && (a._i_brand4360 < b._i_brand4360)) || 
 ((a._i_category4364 == b._i_category4364) && (a._i_brand4360 == b._i_brand4360) && (a._cc_name4442 < b._cc_name4442)) || 
 ((a._i_category4364 == b._i_category4364) && (a._i_brand4360 == b._i_brand4360) && (a._cc_name4442 == b._cc_name4442) && (a._d_year4414 < b._d_year4414)) || 
 ((a._i_category4364 == b._i_category4364) && (a._i_brand4360 == b._i_brand4360) && (a._cc_name4442 == b._cc_name4442) && (a._d_year4414 == b._d_year4414) && (a._d_moy4416 < b._d_moy4416)); 
}
    }SW_Window_TD_7331027_order0; 

    std::sort(rows0.begin(), rows0.end(), SW_Window_TD_7331027_order0);
    std::vector<int32_t> ranks0(rows0.size(), 0);
    int32_t currentRank0 = 0;
    int32_t currentPartitionCount0 = 1;
    bool isSamePartition0 = true;
    bool isSameOrderKey0 = true;
    if (!rows0.empty()) {;
      ranks0[0] = ++currentRank0;
    };
    for (int i = 1; i< rows0.size(); i++) {
        isSamePartition0 = ( rows0[i]._i_category4364 == rows0[i-1]._i_category4364 && rows0[i]._i_brand4360 == rows0[i-1]._i_brand4360 && rows0[i]._cc_name4442 == rows0[i-1]._cc_name4442);
        isSameOrderKey0 = ( rows0[i]._d_year4414 == rows0[i-1]._d_year4414 && rows0[i]._d_moy4416 == rows0[i-1]._d_moy4416);
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
        tbl_Window_TD_7331027_output.setInt32(r, 6, ranks0[i]);
    }
    tbl_Window_TD_7331027_output.setNumRow(r);
    std::cout << "tbl_Window_TD_7331027_output #Row: " << tbl_Window_TD_7331027_output.getNumRow() << std::endl;
}

void SW_Window_TD_7405474(Table &tbl_Filter_TD_8164128_output, Table &tbl_Window_TD_7405474_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Window
    // Operation: ListBuffer(avg(_w0#3558) windowspecdefinition(i_category#240, i_brand#236, cc_name#909, d_year#126, specifiedwindowframe(RowFrame, unboundedpreceding$(), unboundedfollowing$())) AS avg_monthly_sales#3545)
    // Input: ListBuffer(i_category#240, i_brand#236, cc_name#909, d_year#126, d_moy#128, sum_sales#3544, _w0#3558, rn#3546)
    // Output: ListBuffer(i_category#240, i_brand#236, cc_name#909, d_year#126, d_moy#128, sum_sales#3544, _w0#3558, rn#3546, avg_monthly_sales#3545)
    struct SW_Window_TD_7405474Row {
        std::string _i_category240;
        std::string _i_brand236;
        std::string _cc_name909;
        int32_t _d_year126;
        int32_t _d_moy128;
        int64_t _sum_sales3544;
        int64_t __w03558;
        int32_t _rn3546;
    }; 

    int nrow = tbl_Filter_TD_8164128_output.getNumRow();
    std::vector<SW_Window_TD_7405474Row> rows0;
    int r = 0;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category240 = tbl_Filter_TD_8164128_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        tbl_Window_TD_7405474_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _i_category240);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236 = tbl_Filter_TD_8164128_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        tbl_Window_TD_7405474_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _i_brand236);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name909 = tbl_Filter_TD_8164128_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        tbl_Window_TD_7405474_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _cc_name909);
        int32_t _d_year126 = tbl_Filter_TD_8164128_output.getInt32(i, 3);
        tbl_Window_TD_7405474_output.setInt32(r, 3,_d_year126);
        int32_t _d_moy128 = tbl_Filter_TD_8164128_output.getInt32(i, 4);
        tbl_Window_TD_7405474_output.setInt32(r, 4,_d_moy128);
        int64_t _sum_sales3544 = tbl_Filter_TD_8164128_output.getInt64(i, 5);
        tbl_Window_TD_7405474_output.setInt64(r, 5,_sum_sales3544);
        int64_t __w03558 = tbl_Filter_TD_8164128_output.getInt64(i, 6);
        tbl_Window_TD_7405474_output.setInt64(r, 6,__w03558);
        int32_t _rn3546 = tbl_Filter_TD_8164128_output.getInt32(i, 7);
        tbl_Window_TD_7405474_output.setInt32(r, 7,_rn3546);
        r++;
        SW_Window_TD_7405474Row t = {std::string(_i_category240.data()),std::string(_i_brand236.data()),std::string(_cc_name909.data()),_d_year126,_d_moy128,_sum_sales3544,__w03558,_rn3546};
        rows0.push_back(t);
    }
    struct {
        bool operator()(const SW_Window_TD_7405474Row& a, const SW_Window_TD_7405474Row& b) const { return 
(a._i_category240 < b._i_category240) || 
 ((a._i_category240 == b._i_category240) && (a._i_brand236 < b._i_brand236)) || 
 ((a._i_category240 == b._i_category240) && (a._i_brand236 == b._i_brand236) && (a._cc_name909 < b._cc_name909)) || 
 ((a._i_category240 == b._i_category240) && (a._i_brand236 == b._i_brand236) && (a._cc_name909 == b._cc_name909) && (a._d_year126 < b._d_year126)); 
}
    }SW_Window_TD_7405474_order0; 

    std::sort(rows0.begin(), rows0.end(), SW_Window_TD_7405474_order0);
    int64_t sum0 = 0;
    int64_t currentRow0 = 0;
    std::string current_i_category2400 = "";
    std::string current_i_brand2360 = "";
    std::string current_cc_name9090 = "";
    int32_t current_d_year1260 = std::numeric_limits<int32_t>::min();
    for (auto& it : rows0) {
        if (current_i_category2400 != it._i_category240 || current_i_brand2360 != it._i_brand236 || current_cc_name9090 != it._cc_name909 || current_d_year1260 != it._d_year126) {
            sum0 = 0;
            currentRow0 = 0;
            current_i_category2400 = it._i_category240;
            current_i_brand2360 = it._i_brand236;
            current_cc_name9090 = it._cc_name909;
            current_d_year1260 = it._d_year126;
        }
        sum0 += it.__w03558;
        currentRow0 +=1;
        tbl_Window_TD_7405474_output.setInt64(r, 8, sum0 / currentRow0 );
    }
    tbl_Window_TD_7405474_output.setNumRow(r);
    std::cout << "tbl_Window_TD_7405474_output #Row: " << tbl_Window_TD_7405474_output.getNumRow() << std::endl;
}

void SW_Window_TD_6547937(Table &tbl_Aggregate_TD_7738360_output, Table &tbl_Window_TD_6547937_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Window
    // Operation: ListBuffer(rank(d_year#4534, d_moy#4536) windowspecdefinition(i_category#4484, i_brand#4480, cc_name#4562, d_year#4534 ASC NULLS FIRST, d_moy#4536 ASC NULLS FIRST, specifiedwindowframe(RowFrame, unboundedpreceding$(), currentrow$())) AS rn#4591)
    // Input: ListBuffer(i_category#4484, i_brand#4480, cc_name#4562, d_year#4534, d_moy#4536, sum_sales#3544)
    // Output: ListBuffer(i_category#4484, i_brand#4480, cc_name#4562, d_year#4534, d_moy#4536, sum_sales#3544, rn#4591)
    struct SW_Window_TD_6547937Row {
        std::string _i_category4484;
        std::string _i_brand4480;
        std::string _cc_name4562;
        int32_t _d_year4534;
        int32_t _d_moy4536;
        int64_t _sum_sales3544;
    }; 

    int nrow = tbl_Aggregate_TD_7738360_output.getNumRow();
    std::vector<SW_Window_TD_6547937Row> rows0;
    int r = 0;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category4484 = tbl_Aggregate_TD_7738360_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        tbl_Window_TD_6547937_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _i_category4484);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand4480 = tbl_Aggregate_TD_7738360_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        tbl_Window_TD_6547937_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _i_brand4480);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name4562 = tbl_Aggregate_TD_7738360_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        tbl_Window_TD_6547937_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _cc_name4562);
        int32_t _d_year4534 = tbl_Aggregate_TD_7738360_output.getInt32(i, 3);
        tbl_Window_TD_6547937_output.setInt32(r, 3,_d_year4534);
        int32_t _d_moy4536 = tbl_Aggregate_TD_7738360_output.getInt32(i, 4);
        tbl_Window_TD_6547937_output.setInt32(r, 4,_d_moy4536);
        int64_t _sum_sales3544 = tbl_Aggregate_TD_7738360_output.getInt64(i, 5);
        tbl_Window_TD_6547937_output.setInt64(r, 5,_sum_sales3544);
        r++;
        SW_Window_TD_6547937Row t = {std::string(_i_category4484.data()),std::string(_i_brand4480.data()),std::string(_cc_name4562.data()),_d_year4534,_d_moy4536,_sum_sales3544};
        rows0.push_back(t);
    }
    struct {
        bool operator()(const SW_Window_TD_6547937Row& a, const SW_Window_TD_6547937Row& b) const { return 
(a._i_category4484 < b._i_category4484) || 
 ((a._i_category4484 == b._i_category4484) && (a._i_brand4480 < b._i_brand4480)) || 
 ((a._i_category4484 == b._i_category4484) && (a._i_brand4480 == b._i_brand4480) && (a._cc_name4562 < b._cc_name4562)) || 
 ((a._i_category4484 == b._i_category4484) && (a._i_brand4480 == b._i_brand4480) && (a._cc_name4562 == b._cc_name4562) && (a._d_year4534 < b._d_year4534)) || 
 ((a._i_category4484 == b._i_category4484) && (a._i_brand4480 == b._i_brand4480) && (a._cc_name4562 == b._cc_name4562) && (a._d_year4534 == b._d_year4534) && (a._d_moy4536 < b._d_moy4536)); 
}
    }SW_Window_TD_6547937_order0; 

    std::sort(rows0.begin(), rows0.end(), SW_Window_TD_6547937_order0);
    std::vector<int32_t> ranks0(rows0.size(), 0);
    int32_t currentRank0 = 0;
    int32_t currentPartitionCount0 = 1;
    bool isSamePartition0 = true;
    bool isSameOrderKey0 = true;
    if (!rows0.empty()) {;
      ranks0[0] = ++currentRank0;
    };
    for (int i = 1; i< rows0.size(); i++) {
        isSamePartition0 = ( rows0[i]._i_category4484 == rows0[i-1]._i_category4484 && rows0[i]._i_brand4480 == rows0[i-1]._i_brand4480 && rows0[i]._cc_name4562 == rows0[i-1]._cc_name4562);
        isSameOrderKey0 = ( rows0[i]._d_year4534 == rows0[i-1]._d_year4534 && rows0[i]._d_moy4536 == rows0[i-1]._d_moy4536);
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
        tbl_Window_TD_6547937_output.setInt32(r, 6, ranks0[i]);
    }
    tbl_Window_TD_6547937_output.setNumRow(r);
    std::cout << "tbl_Window_TD_6547937_output #Row: " << tbl_Window_TD_6547937_output.getNumRow() << std::endl;
}

void SW_Project_TD_6224007(Table &tbl_Window_TD_7331027_output, Table &tbl_Project_TD_6224007_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(sum_sales#3544 AS sum_sales#3564)
    // Input: ListBuffer(i_category#4364, i_brand#4360, cc_name#4442, d_year#4414, d_moy#4416, sum_sales#3544, rn#4471)
    // Output: ListBuffer(i_category#4364, i_brand#4360, cc_name#4442, sum_sales#3564, rn#4471)
    int nrow1 = tbl_Window_TD_7331027_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category4364 = tbl_Window_TD_7331027_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand4360 = tbl_Window_TD_7331027_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name4442 = tbl_Window_TD_7331027_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        int32_t _d_year4414 = tbl_Window_TD_7331027_output.getInt32(i, 3);
        int32_t _d_moy4416 = tbl_Window_TD_7331027_output.getInt32(i, 4);
        int64_t _sum_sales3544 = tbl_Window_TD_7331027_output.getInt64(i, 5);
        int32_t _rn4471 = tbl_Window_TD_7331027_output.getInt32(i, 6);
        int64_t _sum_sales3564 = _sum_sales3544;
        tbl_Project_TD_6224007_output.setInt64(i, 3, _sum_sales3564);
        tbl_Project_TD_6224007_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 0, _i_category4364);
        tbl_Project_TD_6224007_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 1, _i_brand4360);
        tbl_Project_TD_6224007_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 2, _cc_name4442);
        tbl_Project_TD_6224007_output.setInt32(i, 4, _rn4471);
    }
    tbl_Project_TD_6224007_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_6224007_output #Row: " << tbl_Project_TD_6224007_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6667714(Table &tbl_Window_TD_7405474_output, Table &tbl_Filter_TD_6667714_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(avg_monthly_sales#3545) AND (avg_monthly_sales#3545 > 0.000000)) AND (CheckOverflow((promote_precision(abs(CheckOverflow((promote_precision(cast(sum_sales#3544 as decimal(22,6))) - promote_precision(cast(avg_monthly_sales#3545 as decimal(22,6)))), DecimalType(22,6), true), false)) / promote_precision(cast(avg_monthly_sales#3545 as decimal(22,6)))), DecimalType(38,16), true) > 0.1000000000000000)))
    // Input: ListBuffer(i_category#240, i_brand#236, cc_name#909, d_year#126, d_moy#128, sum_sales#3544, _w0#3558, rn#3546, avg_monthly_sales#3545)
    // Output: ListBuffer(i_category#240, i_brand#236, cc_name#909, d_year#126, d_moy#128, sum_sales#3544, avg_monthly_sales#3545, rn#3546)
    int r = 0;
    int nrow1 = tbl_Window_TD_7405474_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _avg_monthly_sales3545 = tbl_Window_TD_7405474_output.getInt64(i, 8);
        int64_t _sum_sales3544 = tbl_Window_TD_7405474_output.getInt64(i, 5);
        if (((_avg_monthly_sales3545!= 0) && (_avg_monthly_sales3545 > 0.000000)) && (_sum_sales3544 > 0.1000000000000000)) {
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_t = tbl_Window_TD_7405474_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            tbl_Filter_TD_6667714_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category240_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_t = tbl_Window_TD_7405474_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_6667714_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand236_t);
            std::array<char, TPCDS_READ_MAX + 1> _cc_name909_t = tbl_Window_TD_7405474_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_6667714_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_name909_t);
            int32_t _d_year126_t = tbl_Window_TD_7405474_output.getInt32(i, 3);
            tbl_Filter_TD_6667714_output.setInt32(r, 3, _d_year126_t);
            int32_t _d_moy128_t = tbl_Window_TD_7405474_output.getInt32(i, 4);
            tbl_Filter_TD_6667714_output.setInt32(r, 4, _d_moy128_t);
            int64_t _sum_sales3544_t = tbl_Window_TD_7405474_output.getInt64(i, 5);
            tbl_Filter_TD_6667714_output.setInt64(r, 5, _sum_sales3544_t);
            int64_t _avg_monthly_sales3545_t = tbl_Window_TD_7405474_output.getInt64(i, 8);
            tbl_Filter_TD_6667714_output.setInt64(r, 6, _avg_monthly_sales3545_t);
            int32_t _rn3546_t = tbl_Window_TD_7405474_output.getInt32(i, 7);
            tbl_Filter_TD_6667714_output.setInt32(r, 7, _rn3546_t);
            r++;
        }
    }
    tbl_Filter_TD_6667714_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6667714_output #Row: " << tbl_Filter_TD_6667714_output.getNumRow() << std::endl;
}

void SW_Project_TD_5357390(Table &tbl_Window_TD_6547937_output, Table &tbl_Project_TD_5357390_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(sum_sales#3544 AS sum_sales#3572)
    // Input: ListBuffer(i_category#4484, i_brand#4480, cc_name#4562, d_year#4534, d_moy#4536, sum_sales#3544, rn#4591)
    // Output: ListBuffer(i_category#4484, i_brand#4480, cc_name#4562, sum_sales#3572, rn#4591)
    int nrow1 = tbl_Window_TD_6547937_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category4484 = tbl_Window_TD_6547937_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand4480 = tbl_Window_TD_6547937_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name4562 = tbl_Window_TD_6547937_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        int32_t _d_year4534 = tbl_Window_TD_6547937_output.getInt32(i, 3);
        int32_t _d_moy4536 = tbl_Window_TD_6547937_output.getInt32(i, 4);
        int64_t _sum_sales3544 = tbl_Window_TD_6547937_output.getInt64(i, 5);
        int32_t _rn4591 = tbl_Window_TD_6547937_output.getInt32(i, 6);
        int64_t _sum_sales3572 = _sum_sales3544;
        tbl_Project_TD_5357390_output.setInt64(i, 3, _sum_sales3572);
        tbl_Project_TD_5357390_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 0, _i_category4484);
        tbl_Project_TD_5357390_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 1, _i_brand4480);
        tbl_Project_TD_5357390_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 2, _cc_name4562);
        tbl_Project_TD_5357390_output.setInt32(i, 4, _rn4591);
    }
    tbl_Project_TD_5357390_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_5357390_output #Row: " << tbl_Project_TD_5357390_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5241974_key_leftMajor {
    std::string _i_category240;
    std::string _i_brand236;
    std::string _cc_name909;
    bool operator==(const SW_JOIN_INNER_TD_5241974_key_leftMajor& other) const {
        return ((_i_category240 == other._i_category240) && (_i_brand236 == other._i_brand236) && (_cc_name909 == other._cc_name909));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5241974_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5241974_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_category240)) + (hash<string>()(k._i_brand236)) + (hash<string>()(k._cc_name909));
    }
};
}
struct SW_JOIN_INNER_TD_5241974_payload_leftMajor {
    std::string _i_category240;
    std::string _i_brand236;
    std::string _cc_name909;
    int32_t _d_year126;
    int32_t _d_moy128;
    int64_t _sum_sales3544;
    int64_t _avg_monthly_sales3545;
    int32_t _rn3546;
};
struct SW_JOIN_INNER_TD_5241974_key_rightMajor {
    std::string _i_category4364;
    std::string _i_brand4360;
    std::string _cc_name4442;
    bool operator==(const SW_JOIN_INNER_TD_5241974_key_rightMajor& other) const {
        return ((_i_category4364 == other._i_category4364) && (_i_brand4360 == other._i_brand4360) && (_cc_name4442 == other._cc_name4442));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5241974_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5241974_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_category4364)) + (hash<string>()(k._i_brand4360)) + (hash<string>()(k._cc_name4442));
    }
};
}
struct SW_JOIN_INNER_TD_5241974_payload_rightMajor {
    std::string _i_category4364;
    std::string _i_brand4360;
    std::string _cc_name4442;
    int64_t _sum_sales3564;
    int32_t _rn4471;
};
void SW_JOIN_INNER_TD_5241974(Table &tbl_Filter_TD_6667714_output, Table &tbl_Project_TD_6224007_output, Table &tbl_JOIN_INNER_TD_5241974_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((((i_category#240 = i_category#4364) AND (i_brand#236 = i_brand#4360)) AND (cc_name#909 = cc_name#4442)) AND (rn#3546 = (rn#4471 + 1))))
    // Left Table: ListBuffer(i_category#240, i_brand#236, cc_name#909, d_year#126, d_moy#128, sum_sales#3544, avg_monthly_sales#3545, rn#3546)
    // Right Table: ListBuffer(i_category#4364, i_brand#4360, cc_name#4442, sum_sales#3564, rn#4471)
    // Output Table: ListBuffer(i_category#240, i_brand#236, cc_name#909, d_year#126, d_moy#128, sum_sales#3544, avg_monthly_sales#3545, rn#3546, sum_sales#3564)
    int left_nrow = tbl_Filter_TD_6667714_output.getNumRow();
    int right_nrow = tbl_Project_TD_6224007_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5241974_key_leftMajor, SW_JOIN_INNER_TD_5241974_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_6667714_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_k_n = tbl_Filter_TD_6667714_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_category240_k = std::string(_i_category240_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_k_n = tbl_Filter_TD_6667714_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand236_k = std::string(_i_brand236_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cc_name909_k_n = tbl_Filter_TD_6667714_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _cc_name909_k = std::string(_cc_name909_k_n.data());
            SW_JOIN_INNER_TD_5241974_key_leftMajor keyA{_i_category240_k, _i_brand236_k, _cc_name909_k};
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_Filter_TD_6667714_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_category240 = std::string(_i_category240_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_Filter_TD_6667714_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand236 = std::string(_i_brand236_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_Filter_TD_6667714_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _cc_name909 = std::string(_cc_name909_n.data());
            int32_t _d_year126 = tbl_Filter_TD_6667714_output.getInt32(i, 3);
            int32_t _d_moy128 = tbl_Filter_TD_6667714_output.getInt32(i, 4);
            int64_t _sum_sales3544 = tbl_Filter_TD_6667714_output.getInt64(i, 5);
            int64_t _avg_monthly_sales3545 = tbl_Filter_TD_6667714_output.getInt64(i, 6);
            int32_t _rn3546 = tbl_Filter_TD_6667714_output.getInt32(i, 7);
            SW_JOIN_INNER_TD_5241974_payload_leftMajor payloadA{_i_category240, _i_brand236, _cc_name909, _d_year126, _d_moy128, _sum_sales3544, _avg_monthly_sales3545, _rn3546};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Project_TD_6224007_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_category4364_k_n = tbl_Project_TD_6224007_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_category4364_k = std::string(_i_category4364_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4360_k_n = tbl_Project_TD_6224007_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand4360_k = std::string(_i_brand4360_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cc_name4442_k_n = tbl_Project_TD_6224007_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _cc_name4442_k = std::string(_cc_name4442_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5241974_key_leftMajor{_i_category4364_k, _i_brand4360_k, _cc_name4442_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _i_category240 = (it->second)._i_category240;
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n{};
                memcpy(_i_category240_n.data(), (_i_category240).data(), (_i_category240).length());
                std::string _i_brand236 = (it->second)._i_brand236;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n{};
                memcpy(_i_brand236_n.data(), (_i_brand236).data(), (_i_brand236).length());
                std::string _cc_name909 = (it->second)._cc_name909;
                std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n{};
                memcpy(_cc_name909_n.data(), (_cc_name909).data(), (_cc_name909).length());
                int32_t _d_year126 = (it->second)._d_year126;
                int32_t _d_moy128 = (it->second)._d_moy128;
                int64_t _sum_sales3544 = (it->second)._sum_sales3544;
                int64_t _avg_monthly_sales3545 = (it->second)._avg_monthly_sales3545;
                int32_t _rn3546 = (it->second)._rn3546;
                std::array<char, TPCDS_READ_MAX + 1> _i_category4364_n = tbl_Project_TD_6224007_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _i_category4364 = std::string(_i_category4364_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4360_n = tbl_Project_TD_6224007_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_brand4360 = std::string(_i_brand4360_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cc_name4442_n = tbl_Project_TD_6224007_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _cc_name4442 = std::string(_cc_name4442_n.data());
                int64_t _sum_sales3564 = tbl_Project_TD_6224007_output.getInt64(i, 3);
                int32_t _rn4471 = tbl_Project_TD_6224007_output.getInt32(i, 4);
                if (_rn3546 == NULL) {
                    tbl_JOIN_INNER_TD_5241974_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category240_n);
                    tbl_JOIN_INNER_TD_5241974_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand236_n);
                    tbl_JOIN_INNER_TD_5241974_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_name909_n);
                    tbl_JOIN_INNER_TD_5241974_output.setInt32(r, 3, _d_year126);
                    tbl_JOIN_INNER_TD_5241974_output.setInt32(r, 4, _d_moy128);
                    tbl_JOIN_INNER_TD_5241974_output.setInt64(r, 5, _sum_sales3544);
                    tbl_JOIN_INNER_TD_5241974_output.setInt64(r, 6, _avg_monthly_sales3545);
                    tbl_JOIN_INNER_TD_5241974_output.setInt32(r, 7, _rn3546);
                    tbl_JOIN_INNER_TD_5241974_output.setInt64(r, 8, _sum_sales3564);
                    r++;
                }
                it++;
            }
        }
        tbl_JOIN_INNER_TD_5241974_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5241974_key_rightMajor, SW_JOIN_INNER_TD_5241974_payload_rightMajor> ht1;
        int nrow1 = tbl_Project_TD_6224007_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_category4364_k_n = tbl_Project_TD_6224007_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_category4364_k = std::string(_i_category4364_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4360_k_n = tbl_Project_TD_6224007_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand4360_k = std::string(_i_brand4360_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cc_name4442_k_n = tbl_Project_TD_6224007_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _cc_name4442_k = std::string(_cc_name4442_k_n.data());
            SW_JOIN_INNER_TD_5241974_key_rightMajor keyA{_i_category4364_k, _i_brand4360_k, _cc_name4442_k};
            std::array<char, TPCDS_READ_MAX + 1> _i_category4364_n = tbl_Project_TD_6224007_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_category4364 = std::string(_i_category4364_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4360_n = tbl_Project_TD_6224007_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand4360 = std::string(_i_brand4360_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cc_name4442_n = tbl_Project_TD_6224007_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _cc_name4442 = std::string(_cc_name4442_n.data());
            int64_t _sum_sales3564 = tbl_Project_TD_6224007_output.getInt64(i, 3);
            int32_t _rn4471 = tbl_Project_TD_6224007_output.getInt32(i, 4);
            SW_JOIN_INNER_TD_5241974_payload_rightMajor payloadA{_i_category4364, _i_brand4360, _cc_name4442, _sum_sales3564, _rn4471};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6667714_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_k_n = tbl_Filter_TD_6667714_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_category240_k = std::string(_i_category240_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_k_n = tbl_Filter_TD_6667714_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand236_k = std::string(_i_brand236_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cc_name909_k_n = tbl_Filter_TD_6667714_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _cc_name909_k = std::string(_cc_name909_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5241974_key_rightMajor{_i_category240_k, _i_brand236_k, _cc_name909_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _i_category4364 = (it->second)._i_category4364;
                std::array<char, TPCDS_READ_MAX + 1> _i_category4364_n{};
                memcpy(_i_category4364_n.data(), (_i_category4364).data(), (_i_category4364).length());
                std::string _i_brand4360 = (it->second)._i_brand4360;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4360_n{};
                memcpy(_i_brand4360_n.data(), (_i_brand4360).data(), (_i_brand4360).length());
                std::string _cc_name4442 = (it->second)._cc_name4442;
                std::array<char, TPCDS_READ_MAX + 1> _cc_name4442_n{};
                memcpy(_cc_name4442_n.data(), (_cc_name4442).data(), (_cc_name4442).length());
                int64_t _sum_sales3564 = (it->second)._sum_sales3564;
                int32_t _rn4471 = (it->second)._rn4471;
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_Filter_TD_6667714_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _i_category240 = std::string(_i_category240_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_Filter_TD_6667714_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_brand236 = std::string(_i_brand236_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_Filter_TD_6667714_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _cc_name909 = std::string(_cc_name909_n.data());
                int32_t _d_year126 = tbl_Filter_TD_6667714_output.getInt32(i, 3);
                int32_t _d_moy128 = tbl_Filter_TD_6667714_output.getInt32(i, 4);
                int64_t _sum_sales3544 = tbl_Filter_TD_6667714_output.getInt64(i, 5);
                int64_t _avg_monthly_sales3545 = tbl_Filter_TD_6667714_output.getInt64(i, 6);
                int32_t _rn3546 = tbl_Filter_TD_6667714_output.getInt32(i, 7);
                if (_rn3546 == NULL) {
                    tbl_JOIN_INNER_TD_5241974_output.setInt64(r, 8, _sum_sales3564);
                    tbl_JOIN_INNER_TD_5241974_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category240_n);
                    tbl_JOIN_INNER_TD_5241974_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand236_n);
                    tbl_JOIN_INNER_TD_5241974_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_name909_n);
                    tbl_JOIN_INNER_TD_5241974_output.setInt32(r, 3, _d_year126);
                    tbl_JOIN_INNER_TD_5241974_output.setInt32(r, 4, _d_moy128);
                    tbl_JOIN_INNER_TD_5241974_output.setInt64(r, 5, _sum_sales3544);
                    tbl_JOIN_INNER_TD_5241974_output.setInt64(r, 6, _avg_monthly_sales3545);
                    tbl_JOIN_INNER_TD_5241974_output.setInt32(r, 7, _rn3546);
                    r++;
                }
                it++;
            }
        }
        tbl_JOIN_INNER_TD_5241974_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5241974_output #Row: " << tbl_JOIN_INNER_TD_5241974_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4632128_key_leftMajor {
    std::string _i_category240;
    std::string _i_brand236;
    std::string _cc_name909;
    int32_t _rn3546;
    bool operator==(const SW_JOIN_INNER_TD_4632128_key_leftMajor& other) const {
        return ((_i_category240 == other._i_category240) && (_i_brand236 == other._i_brand236) && (_cc_name909 == other._cc_name909) && (_rn3546 == other._rn3546));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4632128_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4632128_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_category240)) + (hash<string>()(k._i_brand236)) + (hash<string>()(k._cc_name909)) + (hash<int32_t>()(k._rn3546));
    }
};
}
struct SW_JOIN_INNER_TD_4632128_payload_leftMajor {
    std::string _i_category240;
    std::string _i_brand236;
    std::string _cc_name909;
    int32_t _d_year126;
    int32_t _d_moy128;
    int64_t _sum_sales3544;
    int64_t _avg_monthly_sales3545;
    int32_t _rn3546;
    int64_t _sum_sales3564;
};
struct SW_JOIN_INNER_TD_4632128_key_rightMajor {
    std::string _i_category4484;
    std::string _i_brand4480;
    std::string _cc_name4562;
    int32_t _rn4591;
    bool operator==(const SW_JOIN_INNER_TD_4632128_key_rightMajor& other) const {
        return ((_i_category4484 == other._i_category4484) && (_i_brand4480 == other._i_brand4480) && (_cc_name4562 == other._cc_name4562) && (_rn4591 == other._rn4591));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4632128_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4632128_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_category4484)) + (hash<string>()(k._i_brand4480)) + (hash<string>()(k._cc_name4562)) + (hash<int32_t>()(k._rn4591));
    }
};
}
struct SW_JOIN_INNER_TD_4632128_payload_rightMajor {
    std::string _i_category4484;
    std::string _i_brand4480;
    std::string _cc_name4562;
    int64_t _sum_sales3572;
    int32_t _rn4591;
};
void SW_JOIN_INNER_TD_4632128(Table &tbl_JOIN_INNER_TD_5241974_output, Table &tbl_Project_TD_5357390_output, Table &tbl_JOIN_INNER_TD_4632128_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((((i_category#240 = i_category#4484) AND (i_brand#236 = i_brand#4480)) AND (cc_name#909 = cc_name#4562)) AND (rn#3546 = (rn#4591 - 1))))
    // Left Table: ListBuffer(i_category#240, i_brand#236, cc_name#909, d_year#126, d_moy#128, sum_sales#3544, avg_monthly_sales#3545, rn#3546, sum_sales#3564)
    // Right Table: ListBuffer(i_category#4484, i_brand#4480, cc_name#4562, sum_sales#3572, rn#4591)
    // Output Table: ListBuffer(i_category#240, i_brand#236, cc_name#909, d_year#126, d_moy#128, avg_monthly_sales#3545, sum_sales#3544, sum_sales#3564, sum_sales#3572)
    int left_nrow = tbl_JOIN_INNER_TD_5241974_output.getNumRow();
    int right_nrow = tbl_Project_TD_5357390_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4632128_key_leftMajor, SW_JOIN_INNER_TD_4632128_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_5241974_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_k_n = tbl_JOIN_INNER_TD_5241974_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_category240_k = std::string(_i_category240_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_k_n = tbl_JOIN_INNER_TD_5241974_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand236_k = std::string(_i_brand236_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cc_name909_k_n = tbl_JOIN_INNER_TD_5241974_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _cc_name909_k = std::string(_cc_name909_k_n.data());
            int32_t _rn3546_k = tbl_JOIN_INNER_TD_5241974_output.getInt32(i, 7);
            SW_JOIN_INNER_TD_4632128_key_leftMajor keyA{_i_category240_k, _i_brand236_k, _cc_name909_k, _rn3546_k};
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_JOIN_INNER_TD_5241974_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_category240 = std::string(_i_category240_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_JOIN_INNER_TD_5241974_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand236 = std::string(_i_brand236_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_JOIN_INNER_TD_5241974_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _cc_name909 = std::string(_cc_name909_n.data());
            int32_t _d_year126 = tbl_JOIN_INNER_TD_5241974_output.getInt32(i, 3);
            int32_t _d_moy128 = tbl_JOIN_INNER_TD_5241974_output.getInt32(i, 4);
            int64_t _sum_sales3544 = tbl_JOIN_INNER_TD_5241974_output.getInt64(i, 5);
            int64_t _avg_monthly_sales3545 = tbl_JOIN_INNER_TD_5241974_output.getInt64(i, 6);
            int32_t _rn3546 = tbl_JOIN_INNER_TD_5241974_output.getInt32(i, 7);
            int64_t _sum_sales3564 = tbl_JOIN_INNER_TD_5241974_output.getInt64(i, 8);
            SW_JOIN_INNER_TD_4632128_payload_leftMajor payloadA{_i_category240, _i_brand236, _cc_name909, _d_year126, _d_moy128, _sum_sales3544, _avg_monthly_sales3545, _rn3546, _sum_sales3564};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Project_TD_5357390_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_category4484_k_n = tbl_Project_TD_5357390_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_category4484_k = std::string(_i_category4484_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4480_k_n = tbl_Project_TD_5357390_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand4480_k = std::string(_i_brand4480_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cc_name4562_k_n = tbl_Project_TD_5357390_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _cc_name4562_k = std::string(_cc_name4562_k_n.data());
            int32_t _rn4591_k = tbl_Project_TD_5357390_output.getInt32(i, 4);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4632128_key_leftMajor{_i_category4484_k, _i_brand4480_k, _cc_name4562_k, _rn4591_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _i_category240 = (it->second)._i_category240;
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n{};
                memcpy(_i_category240_n.data(), (_i_category240).data(), (_i_category240).length());
                std::string _i_brand236 = (it->second)._i_brand236;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n{};
                memcpy(_i_brand236_n.data(), (_i_brand236).data(), (_i_brand236).length());
                std::string _cc_name909 = (it->second)._cc_name909;
                std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n{};
                memcpy(_cc_name909_n.data(), (_cc_name909).data(), (_cc_name909).length());
                int32_t _d_year126 = (it->second)._d_year126;
                int32_t _d_moy128 = (it->second)._d_moy128;
                int64_t _sum_sales3544 = (it->second)._sum_sales3544;
                int64_t _avg_monthly_sales3545 = (it->second)._avg_monthly_sales3545;
                int32_t _rn3546 = (it->second)._rn3546;
                int64_t _sum_sales3564 = (it->second)._sum_sales3564;
                std::array<char, TPCDS_READ_MAX + 1> _i_category4484_n = tbl_Project_TD_5357390_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _i_category4484 = std::string(_i_category4484_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4480_n = tbl_Project_TD_5357390_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_brand4480 = std::string(_i_brand4480_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cc_name4562_n = tbl_Project_TD_5357390_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _cc_name4562 = std::string(_cc_name4562_n.data());
                int64_t _sum_sales3572 = tbl_Project_TD_5357390_output.getInt64(i, 3);
                int32_t _rn4591 = tbl_Project_TD_5357390_output.getInt32(i, 4);
                if (_rn3546 == (_rn4591 - 1)) {
                    tbl_JOIN_INNER_TD_4632128_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category240_n);
                    tbl_JOIN_INNER_TD_4632128_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand236_n);
                    tbl_JOIN_INNER_TD_4632128_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_name909_n);
                    tbl_JOIN_INNER_TD_4632128_output.setInt32(r, 3, _d_year126);
                    tbl_JOIN_INNER_TD_4632128_output.setInt32(r, 4, _d_moy128);
                    tbl_JOIN_INNER_TD_4632128_output.setInt64(r, 6, _sum_sales3544);
                    tbl_JOIN_INNER_TD_4632128_output.setInt64(r, 5, _avg_monthly_sales3545);
                    tbl_JOIN_INNER_TD_4632128_output.setInt64(r, 7, _sum_sales3564);
                    tbl_JOIN_INNER_TD_4632128_output.setInt64(r, 8, _sum_sales3572);
                    r++;
                }
                it++;
            }
        }
        tbl_JOIN_INNER_TD_4632128_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4632128_key_rightMajor, SW_JOIN_INNER_TD_4632128_payload_rightMajor> ht1;
        int nrow1 = tbl_Project_TD_5357390_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_category4484_k_n = tbl_Project_TD_5357390_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_category4484_k = std::string(_i_category4484_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4480_k_n = tbl_Project_TD_5357390_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand4480_k = std::string(_i_brand4480_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cc_name4562_k_n = tbl_Project_TD_5357390_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _cc_name4562_k = std::string(_cc_name4562_k_n.data());
            int32_t _rn4591_k = tbl_Project_TD_5357390_output.getInt32(i, 4);
            SW_JOIN_INNER_TD_4632128_key_rightMajor keyA{_i_category4484_k, _i_brand4480_k, _cc_name4562_k, _rn4591_k};
            std::array<char, TPCDS_READ_MAX + 1> _i_category4484_n = tbl_Project_TD_5357390_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_category4484 = std::string(_i_category4484_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_brand4480_n = tbl_Project_TD_5357390_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand4480 = std::string(_i_brand4480_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cc_name4562_n = tbl_Project_TD_5357390_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _cc_name4562 = std::string(_cc_name4562_n.data());
            int64_t _sum_sales3572 = tbl_Project_TD_5357390_output.getInt64(i, 3);
            int32_t _rn4591 = tbl_Project_TD_5357390_output.getInt32(i, 4);
            SW_JOIN_INNER_TD_4632128_payload_rightMajor payloadA{_i_category4484, _i_brand4480, _cc_name4562, _sum_sales3572, _rn4591};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_5241974_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_k_n = tbl_JOIN_INNER_TD_5241974_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_category240_k = std::string(_i_category240_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_brand236_k_n = tbl_JOIN_INNER_TD_5241974_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_brand236_k = std::string(_i_brand236_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cc_name909_k_n = tbl_JOIN_INNER_TD_5241974_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _cc_name909_k = std::string(_cc_name909_k_n.data());
            int32_t _rn3546_k = tbl_JOIN_INNER_TD_5241974_output.getInt32(i, 7);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4632128_key_rightMajor{_i_category240_k, _i_brand236_k, _cc_name909_k, _rn3546_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _i_category4484 = (it->second)._i_category4484;
                std::array<char, TPCDS_READ_MAX + 1> _i_category4484_n{};
                memcpy(_i_category4484_n.data(), (_i_category4484).data(), (_i_category4484).length());
                std::string _i_brand4480 = (it->second)._i_brand4480;
                std::array<char, TPCDS_READ_MAX + 1> _i_brand4480_n{};
                memcpy(_i_brand4480_n.data(), (_i_brand4480).data(), (_i_brand4480).length());
                std::string _cc_name4562 = (it->second)._cc_name4562;
                std::array<char, TPCDS_READ_MAX + 1> _cc_name4562_n{};
                memcpy(_cc_name4562_n.data(), (_cc_name4562).data(), (_cc_name4562).length());
                int64_t _sum_sales3572 = (it->second)._sum_sales3572;
                int32_t _rn4591 = (it->second)._rn4591;
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_JOIN_INNER_TD_5241974_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _i_category240 = std::string(_i_category240_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_JOIN_INNER_TD_5241974_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_brand236 = std::string(_i_brand236_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_JOIN_INNER_TD_5241974_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _cc_name909 = std::string(_cc_name909_n.data());
                int32_t _d_year126 = tbl_JOIN_INNER_TD_5241974_output.getInt32(i, 3);
                int32_t _d_moy128 = tbl_JOIN_INNER_TD_5241974_output.getInt32(i, 4);
                int64_t _sum_sales3544 = tbl_JOIN_INNER_TD_5241974_output.getInt64(i, 5);
                int64_t _avg_monthly_sales3545 = tbl_JOIN_INNER_TD_5241974_output.getInt64(i, 6);
                int32_t _rn3546 = tbl_JOIN_INNER_TD_5241974_output.getInt32(i, 7);
                int64_t _sum_sales3564 = tbl_JOIN_INNER_TD_5241974_output.getInt64(i, 8);
                if (_rn3546 == (_rn4591 - 1)) {
                    tbl_JOIN_INNER_TD_4632128_output.setInt64(r, 8, _sum_sales3572);
                    tbl_JOIN_INNER_TD_4632128_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category240_n);
                    tbl_JOIN_INNER_TD_4632128_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand236_n);
                    tbl_JOIN_INNER_TD_4632128_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_name909_n);
                    tbl_JOIN_INNER_TD_4632128_output.setInt32(r, 3, _d_year126);
                    tbl_JOIN_INNER_TD_4632128_output.setInt32(r, 4, _d_moy128);
                    tbl_JOIN_INNER_TD_4632128_output.setInt64(r, 6, _sum_sales3544);
                    tbl_JOIN_INNER_TD_4632128_output.setInt64(r, 5, _avg_monthly_sales3545);
                    tbl_JOIN_INNER_TD_4632128_output.setInt64(r, 7, _sum_sales3564);
                    r++;
                }
                it++;
            }
        }
        tbl_JOIN_INNER_TD_4632128_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4632128_output #Row: " << tbl_JOIN_INNER_TD_4632128_output.getNumRow() << std::endl;
}

void SW_Project_TD_3902436(Table &tbl_JOIN_INNER_TD_4632128_output, Table &tbl_Project_TD_3902436_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(sum_sales#3564 AS psum#3547, sum_sales#3572 AS nsum#3548)
    // Input: ListBuffer(i_category#240, i_brand#236, cc_name#909, d_year#126, d_moy#128, avg_monthly_sales#3545, sum_sales#3544, sum_sales#3564, sum_sales#3572)
    // Output: ListBuffer(i_category#240, i_brand#236, cc_name#909, d_year#126, d_moy#128, avg_monthly_sales#3545, sum_sales#3544, psum#3547, nsum#3548)
    int nrow1 = tbl_JOIN_INNER_TD_4632128_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category240 = tbl_JOIN_INNER_TD_4632128_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236 = tbl_JOIN_INNER_TD_4632128_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name909 = tbl_JOIN_INNER_TD_4632128_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        int32_t _d_year126 = tbl_JOIN_INNER_TD_4632128_output.getInt32(i, 3);
        int32_t _d_moy128 = tbl_JOIN_INNER_TD_4632128_output.getInt32(i, 4);
        int64_t _avg_monthly_sales3545 = tbl_JOIN_INNER_TD_4632128_output.getInt64(i, 5);
        int64_t _sum_sales3544 = tbl_JOIN_INNER_TD_4632128_output.getInt64(i, 6);
        int64_t _sum_sales3564 = tbl_JOIN_INNER_TD_4632128_output.getInt64(i, 7);
        int64_t _sum_sales3572 = tbl_JOIN_INNER_TD_4632128_output.getInt64(i, 8);
        int64_t _psum3547 = _sum_sales3564;
        tbl_Project_TD_3902436_output.setInt64(i, 7, _psum3547);
        int64_t _nsum3548 = _sum_sales3572;
        tbl_Project_TD_3902436_output.setInt64(i, 8, _nsum3548);
        tbl_Project_TD_3902436_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 0, _i_category240);
        tbl_Project_TD_3902436_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 1, _i_brand236);
        tbl_Project_TD_3902436_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 2, _cc_name909);
        tbl_Project_TD_3902436_output.setInt32(i, 3, _d_year126);
        tbl_Project_TD_3902436_output.setInt32(i, 4, _d_moy128);
        tbl_Project_TD_3902436_output.setInt64(i, 5, _avg_monthly_sales3545);
        tbl_Project_TD_3902436_output.setInt64(i, 6, _sum_sales3544);
    }
    tbl_Project_TD_3902436_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_3902436_output #Row: " << tbl_Project_TD_3902436_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2562001(Table &tbl_Project_TD_3902436_output, Table &tbl_Sort_TD_2562001_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(CheckOverflow((promote_precision(cast(sum_sales#3544 as decimal(22,6))) - promote_precision(cast(avg_monthly_sales#3545 as decimal(22,6)))), DecimalType(22,6), true) ASC NULLS FIRST, cc_name#909 ASC NULLS FIRST)
    // Input: ListBuffer(i_category#240, i_brand#236, cc_name#909, d_year#126, d_moy#128, avg_monthly_sales#3545, sum_sales#3544, psum#3547, nsum#3548)
    // Output: ListBuffer(i_category#240, i_brand#236, cc_name#909, d_year#126, d_moy#128, avg_monthly_sales#3545, sum_sales#3544, psum#3547, nsum#3548)
    struct SW_Sort_TD_2562001Row {
        std::string _i_category240;
        std::string _i_brand236;
        std::string _cc_name909;
        int32_t _d_year126;
        int32_t _d_moy128;
        int64_t _avg_monthly_sales3545;
        int64_t _sum_sales3544;
        int64_t _psum3547;
        int64_t _nsum3548;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2562001Row& a, const SW_Sort_TD_2562001Row& b) const { return 
 (a._true < b._true) || 
 ((a._true == b._true) && (a._cc_name909 < b._cc_name909)); 
}
    }SW_Sort_TD_2562001_order; 

    int nrow1 = tbl_Project_TD_3902436_output.getNumRow();
    std::vector<SW_Sort_TD_2562001Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category240 = tbl_Project_TD_3902436_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236 = tbl_Project_TD_3902436_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name909 = tbl_Project_TD_3902436_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        int32_t _d_year126 = tbl_Project_TD_3902436_output.getInt32(i, 3);
        int32_t _d_moy128 = tbl_Project_TD_3902436_output.getInt32(i, 4);
        int64_t _avg_monthly_sales3545 = tbl_Project_TD_3902436_output.getInt64(i, 5);
        int64_t _sum_sales3544 = tbl_Project_TD_3902436_output.getInt64(i, 6);
        int64_t _psum3547 = tbl_Project_TD_3902436_output.getInt64(i, 7);
        int64_t _nsum3548 = tbl_Project_TD_3902436_output.getInt64(i, 8);
        SW_Sort_TD_2562001Row t = {std::string(_i_category240.data()),std::string(_i_brand236.data()),std::string(_cc_name909.data()),_d_year126,_d_moy128,_avg_monthly_sales3545,_sum_sales3544,_psum3547,_nsum3548};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2562001_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category240{};
        memcpy(_i_category240.data(), (it._i_category240).data(), (it._i_category240).length());
        tbl_Sort_TD_2562001_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _i_category240);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236{};
        memcpy(_i_brand236.data(), (it._i_brand236).data(), (it._i_brand236).length());
        tbl_Sort_TD_2562001_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _i_brand236);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name909{};
        memcpy(_cc_name909.data(), (it._cc_name909).data(), (it._cc_name909).length());
        tbl_Sort_TD_2562001_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _cc_name909);
        tbl_Sort_TD_2562001_output.setInt32(r, 3, it._d_year126);
        tbl_Sort_TD_2562001_output.setInt32(r, 4, it._d_moy128);
        tbl_Sort_TD_2562001_output.setInt64(r, 5, it._avg_monthly_sales3545);
        tbl_Sort_TD_2562001_output.setInt64(r, 6, it._sum_sales3544);
        tbl_Sort_TD_2562001_output.setInt64(r, 7, it._psum3547);
        tbl_Sort_TD_2562001_output.setInt64(r, 8, it._nsum3548);
        ++r;
    }
    tbl_Sort_TD_2562001_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2562001_output #Row: " << tbl_Sort_TD_2562001_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_130890(Table &tbl_Sort_TD_2562001_output, Table &tbl_LocalLimit_TD_130890_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(i_category#240, i_brand#236, cc_name#909, d_year#126, d_moy#128, avg_monthly_sales#3545, sum_sales#3544, psum#3547, nsum#3548)
    // Output: ListBuffer(i_category#240, i_brand#236, cc_name#909, d_year#126, d_moy#128, avg_monthly_sales#3545, sum_sales#3544, psum#3547, nsum#3548)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_Sort_TD_2562001_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_130890_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category240_n);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_Sort_TD_2562001_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_130890_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand236_n);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_Sort_TD_2562001_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_LocalLimit_TD_130890_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_name909_n);
        tbl_LocalLimit_TD_130890_output.setInt32(r, 3, tbl_Sort_TD_2562001_output.getInt32(i, 3));
        tbl_LocalLimit_TD_130890_output.setInt32(r, 4, tbl_Sort_TD_2562001_output.getInt32(i, 4));
        tbl_LocalLimit_TD_130890_output.setInt64(r, 5, tbl_Sort_TD_2562001_output.getInt64(i, 5));
        tbl_LocalLimit_TD_130890_output.setInt64(r, 6, tbl_Sort_TD_2562001_output.getInt64(i, 6));
        tbl_LocalLimit_TD_130890_output.setInt64(r, 7, tbl_Sort_TD_2562001_output.getInt64(i, 7));
        tbl_LocalLimit_TD_130890_output.setInt64(r, 8, tbl_Sort_TD_2562001_output.getInt64(i, 8));
        r++;
    }
    tbl_LocalLimit_TD_130890_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_130890_output #Row: " << tbl_LocalLimit_TD_130890_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0684633(Table &tbl_LocalLimit_TD_130890_output, Table &tbl_GlobalLimit_TD_0684633_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(i_category#240, i_brand#236, cc_name#909, d_year#126, d_moy#128, avg_monthly_sales#3545, sum_sales#3544, psum#3547, nsum#3548)
    // Output: ListBuffer(i_category#240, i_brand#236, cc_name#909, d_year#126, d_moy#128, avg_monthly_sales#3545, sum_sales#3544, psum#3547, nsum#3548)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_LocalLimit_TD_130890_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0684633_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_category240_n);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236_n = tbl_LocalLimit_TD_130890_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_0684633_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_brand236_n);
        std::array<char, TPCDS_READ_MAX + 1> _cc_name909_n = tbl_LocalLimit_TD_130890_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_GlobalLimit_TD_0684633_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cc_name909_n);
        tbl_GlobalLimit_TD_0684633_output.setInt32(r, 3, tbl_LocalLimit_TD_130890_output.getInt32(i, 3));
        tbl_GlobalLimit_TD_0684633_output.setInt32(r, 4, tbl_LocalLimit_TD_130890_output.getInt32(i, 4));
        tbl_GlobalLimit_TD_0684633_output.setInt64(r, 5, tbl_LocalLimit_TD_130890_output.getInt64(i, 5));
        tbl_GlobalLimit_TD_0684633_output.setInt64(r, 6, tbl_LocalLimit_TD_130890_output.getInt64(i, 6));
        tbl_GlobalLimit_TD_0684633_output.setInt64(r, 7, tbl_LocalLimit_TD_130890_output.getInt64(i, 7));
        tbl_GlobalLimit_TD_0684633_output.setInt64(r, 8, tbl_LocalLimit_TD_130890_output.getInt64(i, 8));
        r++;
    }
    tbl_GlobalLimit_TD_0684633_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0684633_output #Row: " << tbl_GlobalLimit_TD_0684633_output.getNumRow() << std::endl;
}

