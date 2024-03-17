#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_5561270(Table &tbl_SerializeFromObject_TD_6857844_input, Table &tbl_Filter_TD_5561270_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((((isnotnull(cd_gender#94) AND isnotnull(cd_marital_status#95)) AND isnotnull(cd_education_status#96)) AND (((cd_gender#94 = M) AND (cd_marital_status#95 = S)) AND (cd_education_status#96 = College))) AND isnotnull(cd_demo_sk#93)))
    // Input: ListBuffer(cd_demo_sk#93, cd_gender#94, cd_marital_status#95, cd_education_status#96)
    // Output: ListBuffer(cd_demo_sk#93)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6857844_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _cd_gender94 = tbl_SerializeFromObject_TD_6857844_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95 = tbl_SerializeFromObject_TD_6857844_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96 = tbl_SerializeFromObject_TD_6857844_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        int32_t _cd_demo_sk93 = tbl_SerializeFromObject_TD_6857844_input.getInt32(i, 0);
        if ((((_cd_gender94.data() != "NULL" && _cd_marital_status95.data() != "NULL") && _cd_education_status96.data() != "NULL") && (((std::string(_cd_gender94.data()) == "M") && (std::string(_cd_marital_status95.data()) == "S")) && (std::string(_cd_education_status96.data()) == "College"))) && (_cd_demo_sk93!= 0)) {
            int32_t _cd_demo_sk93_t = tbl_SerializeFromObject_TD_6857844_input.getInt32(i, 0);
            tbl_Filter_TD_5561270_output.setInt32(r, 0, _cd_demo_sk93_t);
            r++;
        }
    }
    tbl_Filter_TD_5561270_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5561270_output #Row: " << tbl_Filter_TD_5561270_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5568778(Table &tbl_SerializeFromObject_TD_647904_input, Table &tbl_Filter_TD_5568778_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ss_cdemo_sk#1210) AND isnotnull(ss_sold_date_sk#1206)) AND (isnotnull(ss_item_sk#1208) AND isnotnull(ss_promo_sk#1214))))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_cdemo_sk#1210, ss_promo_sk#1214)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_cdemo_sk#1210, ss_promo_sk#1214)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_647904_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_cdemo_sk1210 = tbl_SerializeFromObject_TD_647904_input.getInt32(i, 2);
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_647904_input.getInt32(i, 0);
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_647904_input.getInt32(i, 1);
        int32_t _ss_promo_sk1214 = tbl_SerializeFromObject_TD_647904_input.getInt32(i, 3);
        if (((_ss_cdemo_sk1210!= 0) && (_ss_sold_date_sk1206!= 0)) && ((_ss_item_sk1208!= 0) && (_ss_promo_sk1214!= 0))) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_647904_input.getInt32(i, 0);
            tbl_Filter_TD_5568778_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_647904_input.getInt32(i, 1);
            tbl_Filter_TD_5568778_output.setInt32(r, 1, _ss_item_sk1208_t);
            int32_t _ss_cdemo_sk1210_t = tbl_SerializeFromObject_TD_647904_input.getInt32(i, 2);
            tbl_Filter_TD_5568778_output.setInt32(r, 2, _ss_cdemo_sk1210_t);
            int32_t _ss_promo_sk1214_t = tbl_SerializeFromObject_TD_647904_input.getInt32(i, 3);
            tbl_Filter_TD_5568778_output.setInt32(r, 3, _ss_promo_sk1214_t);
            r++;
        }
    }
    tbl_Filter_TD_5568778_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5568778_output #Row: " << tbl_Filter_TD_5568778_output.getNumRow() << std::endl;
}

void SW_Filter_TD_4984697(Table &tbl_SerializeFromObject_TD_5789587_input, Table &tbl_Filter_TD_4984697_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#126) AND (d_year#126 = 2000)) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5789587_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_5789587_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_5789587_input.getInt32(i, 0);
        if (((_d_year126!= 0) && (_d_year126 == 2000)) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_5789587_input.getInt32(i, 0);
            tbl_Filter_TD_4984697_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_4984697_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4984697_output #Row: " << tbl_Filter_TD_4984697_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4663801_key_leftMajor {
    int32_t _ss_cdemo_sk1210;
    bool operator==(const SW_JOIN_INNER_TD_4663801_key_leftMajor& other) const {
        return ((_ss_cdemo_sk1210 == other._ss_cdemo_sk1210));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4663801_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4663801_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_cdemo_sk1210));
    }
};
}
struct SW_JOIN_INNER_TD_4663801_payload_leftMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_item_sk1208;
    int32_t _ss_cdemo_sk1210;
    int32_t _ss_promo_sk1214;
};
struct SW_JOIN_INNER_TD_4663801_key_rightMajor {
    int32_t _cd_demo_sk93;
    bool operator==(const SW_JOIN_INNER_TD_4663801_key_rightMajor& other) const {
        return ((_cd_demo_sk93 == other._cd_demo_sk93));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4663801_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4663801_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cd_demo_sk93));
    }
};
}
struct SW_JOIN_INNER_TD_4663801_payload_rightMajor {
    int32_t _cd_demo_sk93;
};
void SW_JOIN_INNER_TD_4663801(Table &tbl_Filter_TD_5568778_output, Table &tbl_Filter_TD_5561270_output, Table &tbl_JOIN_INNER_TD_4663801_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_cdemo_sk#1210 = cd_demo_sk#93))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_cdemo_sk#1210, ss_promo_sk#1214)
    // Right Table: ListBuffer(cd_demo_sk#93)
    // Output Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_promo_sk#1214)
    int left_nrow = tbl_Filter_TD_5568778_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5561270_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4663801_key_leftMajor, SW_JOIN_INNER_TD_4663801_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_5568778_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_cdemo_sk1210_k = tbl_Filter_TD_5568778_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_4663801_key_leftMajor keyA{_ss_cdemo_sk1210_k};
            int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_5568778_output.getInt32(i, 0);
            int32_t _ss_item_sk1208 = tbl_Filter_TD_5568778_output.getInt32(i, 1);
            int32_t _ss_cdemo_sk1210 = tbl_Filter_TD_5568778_output.getInt32(i, 2);
            int32_t _ss_promo_sk1214 = tbl_Filter_TD_5568778_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_4663801_payload_leftMajor payloadA{_ss_sold_date_sk1206, _ss_item_sk1208, _ss_cdemo_sk1210, _ss_promo_sk1214};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5561270_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cd_demo_sk93_k = tbl_Filter_TD_5561270_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4663801_key_leftMajor{_cd_demo_sk93_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_cdemo_sk1210 = (it->second)._ss_cdemo_sk1210;
                int32_t _ss_promo_sk1214 = (it->second)._ss_promo_sk1214;
                int32_t _cd_demo_sk93 = tbl_Filter_TD_5561270_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_4663801_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_4663801_output.setInt32(r, 1, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_4663801_output.setInt32(r, 2, _ss_promo_sk1214);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4663801_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4663801_key_rightMajor, SW_JOIN_INNER_TD_4663801_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5561270_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cd_demo_sk93_k = tbl_Filter_TD_5561270_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4663801_key_rightMajor keyA{_cd_demo_sk93_k};
            int32_t _cd_demo_sk93 = tbl_Filter_TD_5561270_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4663801_payload_rightMajor payloadA{_cd_demo_sk93};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5568778_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_cdemo_sk1210_k = tbl_Filter_TD_5568778_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4663801_key_rightMajor{_ss_cdemo_sk1210_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cd_demo_sk93 = (it->second)._cd_demo_sk93;
                int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_5568778_output.getInt32(i, 0);
                int32_t _ss_item_sk1208 = tbl_Filter_TD_5568778_output.getInt32(i, 1);
                int32_t _ss_cdemo_sk1210 = tbl_Filter_TD_5568778_output.getInt32(i, 2);
                int32_t _ss_promo_sk1214 = tbl_Filter_TD_5568778_output.getInt32(i, 3);
                tbl_JOIN_INNER_TD_4663801_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_4663801_output.setInt32(r, 1, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_4663801_output.setInt32(r, 2, _ss_promo_sk1214);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4663801_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4663801_output #Row: " << tbl_JOIN_INNER_TD_4663801_output.getNumRow() << std::endl;
}

void SW_Filter_TD_3908859(Table &tbl_SerializeFromObject_TD_426962_input, Table &tbl_Filter_TD_3908859_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#228))
    // Input: ListBuffer(i_item_sk#228, i_item_id#229)
    // Output: ListBuffer(i_item_sk#228, i_item_id#229)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_426962_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_426962_input.getInt32(i, 0);
        if (_i_item_sk228!= 0) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_426962_input.getInt32(i, 0);
            tbl_Filter_TD_3908859_output.setInt32(r, 0, _i_item_sk228_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_t = tbl_SerializeFromObject_TD_426962_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_3908859_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id229_t);
            r++;
        }
    }
    tbl_Filter_TD_3908859_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_3908859_output #Row: " << tbl_Filter_TD_3908859_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_3717004_key_leftMajor {
    int32_t _ss_sold_date_sk1206;
    bool operator==(const SW_JOIN_INNER_TD_3717004_key_leftMajor& other) const {
        return ((_ss_sold_date_sk1206 == other._ss_sold_date_sk1206));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3717004_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3717004_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_sold_date_sk1206));
    }
};
}
struct SW_JOIN_INNER_TD_3717004_payload_leftMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_item_sk1208;
    int32_t _ss_promo_sk1214;
};
struct SW_JOIN_INNER_TD_3717004_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_3717004_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3717004_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3717004_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_3717004_payload_rightMajor {
    int32_t _d_date_sk120;
};
void SW_JOIN_INNER_TD_3717004(Table &tbl_JOIN_INNER_TD_4663801_output, Table &tbl_Filter_TD_4984697_output, Table &tbl_JOIN_INNER_TD_3717004_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#1206 = d_date_sk#120))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_promo_sk#1214)
    // Right Table: ListBuffer(d_date_sk#120)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_promo_sk#1214)
    int left_nrow = tbl_JOIN_INNER_TD_4663801_output.getNumRow();
    int right_nrow = tbl_Filter_TD_4984697_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3717004_key_leftMajor, SW_JOIN_INNER_TD_3717004_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_4663801_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_JOIN_INNER_TD_4663801_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3717004_key_leftMajor keyA{_ss_sold_date_sk1206_k};
            int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_4663801_output.getInt32(i, 0);
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_4663801_output.getInt32(i, 1);
            int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_4663801_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_3717004_payload_leftMajor payloadA{_ss_sold_date_sk1206, _ss_item_sk1208, _ss_promo_sk1214};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_4984697_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_4984697_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3717004_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_promo_sk1214 = (it->second)._ss_promo_sk1214;
                int32_t _d_date_sk120 = tbl_Filter_TD_4984697_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_3717004_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_3717004_output.setInt32(r, 1, _ss_promo_sk1214);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3717004_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3717004_key_rightMajor, SW_JOIN_INNER_TD_3717004_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_4984697_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_4984697_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3717004_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_4984697_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3717004_payload_rightMajor payloadA{_d_date_sk120};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_4663801_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_JOIN_INNER_TD_4663801_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3717004_key_rightMajor{_ss_sold_date_sk1206_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_4663801_output.getInt32(i, 0);
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_4663801_output.getInt32(i, 1);
                int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_4663801_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_3717004_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_3717004_output.setInt32(r, 1, _ss_promo_sk1214);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3717004_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_3717004_output #Row: " << tbl_JOIN_INNER_TD_3717004_output.getNumRow() << std::endl;
}

void SW_Filter_TD_2901630(Table &tbl_SerializeFromObject_TD_3724616_input, Table &tbl_Filter_TD_2901630_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((p_channel_email#303 = N) OR (p_channel_event#308 = N)) AND isnotnull(p_promo_sk#294)))
    // Input: ListBuffer(p_promo_sk#294, p_channel_email#303, p_channel_event#308)
    // Output: ListBuffer(p_promo_sk#294)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_3724616_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _p_channel_email303 = tbl_SerializeFromObject_TD_3724616_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _p_channel_event308 = tbl_SerializeFromObject_TD_3724616_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        int32_t _p_promo_sk294 = tbl_SerializeFromObject_TD_3724616_input.getInt32(i, 0);
        if (((std::string(_p_channel_email303.data()) == "N") || (std::string(_p_channel_event308.data()) == "N")) && (_p_promo_sk294!= 0)) {
            int32_t _p_promo_sk294_t = tbl_SerializeFromObject_TD_3724616_input.getInt32(i, 0);
            tbl_Filter_TD_2901630_output.setInt32(r, 0, _p_promo_sk294_t);
            r++;
        }
    }
    tbl_Filter_TD_2901630_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2901630_output #Row: " << tbl_Filter_TD_2901630_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_2604902_key_leftMajor {
    int32_t _ss_item_sk1208;
    bool operator==(const SW_JOIN_INNER_TD_2604902_key_leftMajor& other) const {
        return ((_ss_item_sk1208 == other._ss_item_sk1208));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_2604902_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_2604902_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk1208));
    }
};
}
struct SW_JOIN_INNER_TD_2604902_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int32_t _ss_promo_sk1214;
};
struct SW_JOIN_INNER_TD_2604902_key_rightMajor {
    int32_t _i_item_sk228;
    bool operator==(const SW_JOIN_INNER_TD_2604902_key_rightMajor& other) const {
        return ((_i_item_sk228 == other._i_item_sk228));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_2604902_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_2604902_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk228));
    }
};
}
struct SW_JOIN_INNER_TD_2604902_payload_rightMajor {
    int32_t _i_item_sk228;
    std::string _i_item_id229;
};
void SW_JOIN_INNER_TD_2604902(Table &tbl_JOIN_INNER_TD_3717004_output, Table &tbl_Filter_TD_3908859_output, Table &tbl_JOIN_INNER_TD_2604902_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_item_sk#1208 = i_item_sk#228))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_promo_sk#1214)
    // Right Table: ListBuffer(i_item_sk#228, i_item_id#229)
    // Output Table: ListBuffer(ss_promo_sk#1214, i_item_id#229)
    int left_nrow = tbl_JOIN_INNER_TD_3717004_output.getNumRow();
    int right_nrow = tbl_Filter_TD_3908859_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_2604902_key_leftMajor, SW_JOIN_INNER_TD_2604902_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_3717004_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_3717004_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_2604902_key_leftMajor keyA{_ss_item_sk1208_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_3717004_output.getInt32(i, 0);
            int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_3717004_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_2604902_payload_leftMajor payloadA{_ss_item_sk1208, _ss_promo_sk1214};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_3908859_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_3908859_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_2604902_key_leftMajor{_i_item_sk228_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_promo_sk1214 = (it->second)._ss_promo_sk1214;
                int32_t _i_item_sk228 = tbl_Filter_TD_3908859_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_Filter_TD_3908859_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_item_id229 = std::string(_i_item_id229_n.data());
                tbl_JOIN_INNER_TD_2604902_output.setInt32(r, 0, _ss_promo_sk1214);
                tbl_JOIN_INNER_TD_2604902_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id229_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_2604902_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_2604902_key_rightMajor, SW_JOIN_INNER_TD_2604902_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_3908859_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_3908859_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_2604902_key_rightMajor keyA{_i_item_sk228_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_3908859_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_Filter_TD_3908859_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_item_id229 = std::string(_i_item_id229_n.data());
            SW_JOIN_INNER_TD_2604902_payload_rightMajor payloadA{_i_item_sk228, _i_item_id229};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_3717004_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_3717004_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_2604902_key_rightMajor{_ss_item_sk1208_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                std::string _i_item_id229 = (it->second)._i_item_id229;
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n{};
                memcpy(_i_item_id229_n.data(), (_i_item_id229).data(), (_i_item_id229).length());
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_3717004_output.getInt32(i, 0);
                int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_3717004_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_2604902_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id229_n);
                tbl_JOIN_INNER_TD_2604902_output.setInt32(r, 0, _ss_promo_sk1214);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_2604902_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_2604902_output #Row: " << tbl_JOIN_INNER_TD_2604902_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_116077_key_leftMajor {
    int32_t _ss_promo_sk1214;
    bool operator==(const SW_JOIN_INNER_TD_116077_key_leftMajor& other) const {
        return ((_ss_promo_sk1214 == other._ss_promo_sk1214));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_116077_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_116077_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_promo_sk1214));
    }
};
}
struct SW_JOIN_INNER_TD_116077_payload_leftMajor {
    int32_t _ss_promo_sk1214;
    std::string _i_item_id229;
};
struct SW_JOIN_INNER_TD_116077_key_rightMajor {
    int32_t _p_promo_sk294;
    bool operator==(const SW_JOIN_INNER_TD_116077_key_rightMajor& other) const {
        return ((_p_promo_sk294 == other._p_promo_sk294));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_116077_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_116077_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._p_promo_sk294));
    }
};
}
struct SW_JOIN_INNER_TD_116077_payload_rightMajor {
    int32_t _p_promo_sk294;
};
void SW_JOIN_INNER_TD_116077(Table &tbl_JOIN_INNER_TD_2604902_output, Table &tbl_Filter_TD_2901630_output, Table &tbl_JOIN_INNER_TD_116077_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_promo_sk#1214 = p_promo_sk#294))
    // Left Table: ListBuffer(ss_promo_sk#1214, i_item_id#229)
    // Right Table: ListBuffer(p_promo_sk#294)
    // Output Table: ListBuffer(i_item_id#229)
    int left_nrow = tbl_JOIN_INNER_TD_2604902_output.getNumRow();
    int right_nrow = tbl_Filter_TD_2901630_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_116077_key_leftMajor, SW_JOIN_INNER_TD_116077_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_2604902_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_promo_sk1214_k = tbl_JOIN_INNER_TD_2604902_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_116077_key_leftMajor keyA{_ss_promo_sk1214_k};
            int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_2604902_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_JOIN_INNER_TD_2604902_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_item_id229 = std::string(_i_item_id229_n.data());
            SW_JOIN_INNER_TD_116077_payload_leftMajor payloadA{_ss_promo_sk1214, _i_item_id229};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_2901630_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _p_promo_sk294_k = tbl_Filter_TD_2901630_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_116077_key_leftMajor{_p_promo_sk294_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_promo_sk1214 = (it->second)._ss_promo_sk1214;
                std::string _i_item_id229 = (it->second)._i_item_id229;
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n{};
                memcpy(_i_item_id229_n.data(), (_i_item_id229).data(), (_i_item_id229).length());
                int32_t _p_promo_sk294 = tbl_Filter_TD_2901630_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_116077_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id229_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_116077_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_116077_key_rightMajor, SW_JOIN_INNER_TD_116077_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_2901630_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _p_promo_sk294_k = tbl_Filter_TD_2901630_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_116077_key_rightMajor keyA{_p_promo_sk294_k};
            int32_t _p_promo_sk294 = tbl_Filter_TD_2901630_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_116077_payload_rightMajor payloadA{_p_promo_sk294};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_2604902_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_promo_sk1214_k = tbl_JOIN_INNER_TD_2604902_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_116077_key_rightMajor{_ss_promo_sk1214_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _p_promo_sk294 = (it->second)._p_promo_sk294;
                int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_2604902_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_JOIN_INNER_TD_2604902_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_item_id229 = std::string(_i_item_id229_n.data());
                tbl_JOIN_INNER_TD_116077_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id229_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_116077_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_116077_output #Row: " << tbl_JOIN_INNER_TD_116077_output.getNumRow() << std::endl;
}

void SW_Sort_TD_0403938(Table &tbl_JOIN_INNER_TD_116077_output, Table &tbl_Sort_TD_0403938_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(i_item_id#229 ASC NULLS FIRST)
    // Input: ListBuffer(i_item_id#229)
    // Output: ListBuffer(i_item_id#229)
    struct SW_Sort_TD_0403938Row {
        std::string _i_item_id229;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_0403938Row& a, const SW_Sort_TD_0403938Row& b) const { return 
 (a._i_item_id229 < b._i_item_id229); 
}
    }SW_Sort_TD_0403938_order; 

    int nrow1 = tbl_JOIN_INNER_TD_116077_output.getNumRow();
    std::vector<SW_Sort_TD_0403938Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229 = tbl_JOIN_INNER_TD_116077_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        SW_Sort_TD_0403938Row t = {std::string(_i_item_id229.data())};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_0403938_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229{};
        memcpy(_i_item_id229.data(), (it._i_item_id229).data(), (it._i_item_id229).length());
        tbl_Sort_TD_0403938_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _i_item_id229);
        if (r < 10) {
            std::cout << (it._i_item_id229).data() << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_0403938_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_0403938_output #Row: " << tbl_Sort_TD_0403938_output.getNumRow() << std::endl;
}

