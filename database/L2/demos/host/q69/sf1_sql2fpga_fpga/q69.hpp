#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_10489898(Table &tbl_SerializeFromObject_TD_11725638_input, Table &tbl_Filter_TD_10489898_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_year#126) AND isnotnull(d_moy#128)) AND (((d_year#126 = 2001) AND (d_moy#128 >= 4)) AND (d_moy#128 <= 6))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126, d_moy#128)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11725638_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_11725638_input.getInt32(i, 1);
        int32_t _d_moy128 = tbl_SerializeFromObject_TD_11725638_input.getInt32(i, 2);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_11725638_input.getInt32(i, 0);
        if ((((_d_year126!= 0) && (_d_moy128!= 0)) && (((_d_year126 == 2001) && (_d_moy128 >= 4)) && (_d_moy128 <= 6))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_11725638_input.getInt32(i, 0);
            tbl_Filter_TD_10489898_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_10489898_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10489898_output #Row: " << tbl_Filter_TD_10489898_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10902294(Table &tbl_SerializeFromObject_TD_11655553_input, Table &tbl_Filter_TD_10902294_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ss_sold_date_sk#1206))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_customer_sk#1209)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_customer_sk#1209)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11655553_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_11655553_input.getInt32(i, 0);
        if (_ss_sold_date_sk1206!= 0) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_11655553_input.getInt32(i, 0);
            tbl_Filter_TD_10902294_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_customer_sk1209_t = tbl_SerializeFromObject_TD_11655553_input.getInt32(i, 1);
            tbl_Filter_TD_10902294_output.setInt32(r, 1, _ss_customer_sk1209_t);
            r++;
        }
    }
    tbl_Filter_TD_10902294_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10902294_output #Row: " << tbl_Filter_TD_10902294_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9364528(Table &tbl_SerializeFromObject_TD_10490214_input, Table &tbl_Filter_TD_9364528_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_year#3559) AND isnotnull(d_moy#3561)) AND (((d_year#3559 = 2001) AND (d_moy#3561 >= 4)) AND (d_moy#3561 <= 6))) AND isnotnull(d_date_sk#3553)))
    // Input: ListBuffer(d_date_sk#3553, d_year#3559, d_moy#3561)
    // Output: ListBuffer(d_date_sk#3553)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10490214_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3559 = tbl_SerializeFromObject_TD_10490214_input.getInt32(i, 1);
        int32_t _d_moy3561 = tbl_SerializeFromObject_TD_10490214_input.getInt32(i, 2);
        int32_t _d_date_sk3553 = tbl_SerializeFromObject_TD_10490214_input.getInt32(i, 0);
        if ((((_d_year3559!= 0) && (_d_moy3561!= 0)) && (((_d_year3559 == 2001) && (_d_moy3561 >= 4)) && (_d_moy3561 <= 6))) && (_d_date_sk3553!= 0)) {
            int32_t _d_date_sk3553_t = tbl_SerializeFromObject_TD_10490214_input.getInt32(i, 0);
            tbl_Filter_TD_9364528_output.setInt32(r, 0, _d_date_sk3553_t);
            r++;
        }
    }
    tbl_Filter_TD_9364528_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9364528_output #Row: " << tbl_Filter_TD_9364528_output.getNumRow() << std::endl;
}

void SW_Filter_TD_982088(Table &tbl_SerializeFromObject_TD_10337341_input, Table &tbl_Filter_TD_982088_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ws_sold_date_sk#729))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_bill_customer_sk#733)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_bill_customer_sk#733)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10337341_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_10337341_input.getInt32(i, 0);
        if (_ws_sold_date_sk729!= 0) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_10337341_input.getInt32(i, 0);
            tbl_Filter_TD_982088_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_bill_customer_sk733_t = tbl_SerializeFromObject_TD_10337341_input.getInt32(i, 1);
            tbl_Filter_TD_982088_output.setInt32(r, 1, _ws_bill_customer_sk733_t);
            r++;
        }
    }
    tbl_Filter_TD_982088_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_982088_output #Row: " << tbl_Filter_TD_982088_output.getNumRow() << std::endl;
}


void SW_Filter_TD_9875328(Table &tbl_SerializeFromObject_TD_10692572_input, Table &tbl_Filter_TD_9875328_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(c_current_addr_sk#4) AND isnotnull(c_current_cdemo_sk#2)))
    // Input: ListBuffer(c_customer_sk#0, c_current_cdemo_sk#2, c_current_addr_sk#4)
    // Output: ListBuffer(c_customer_sk#0, c_current_cdemo_sk#2, c_current_addr_sk#4)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10692572_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_current_addr_sk4 = tbl_SerializeFromObject_TD_10692572_input.getInt32(i, 2);
        int32_t _c_current_cdemo_sk2 = tbl_SerializeFromObject_TD_10692572_input.getInt32(i, 1);
        if ((_c_current_addr_sk4!= 0) && (_c_current_cdemo_sk2!= 0)) {
            int32_t _c_customer_sk0_t = tbl_SerializeFromObject_TD_10692572_input.getInt32(i, 0);
            tbl_Filter_TD_9875328_output.setInt32(r, 0, _c_customer_sk0_t);
            int32_t _c_current_cdemo_sk2_t = tbl_SerializeFromObject_TD_10692572_input.getInt32(i, 1);
            tbl_Filter_TD_9875328_output.setInt32(r, 1, _c_current_cdemo_sk2_t);
            int32_t _c_current_addr_sk4_t = tbl_SerializeFromObject_TD_10692572_input.getInt32(i, 2);
            tbl_Filter_TD_9875328_output.setInt32(r, 2, _c_current_addr_sk4_t);
            r++;
        }
    }
    tbl_Filter_TD_9875328_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9875328_output #Row: " << tbl_Filter_TD_9875328_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8385324(Table &tbl_SerializeFromObject_TD_9412864_input, Table &tbl_Filter_TD_8385324_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_year#3587) AND isnotnull(d_moy#3589)) AND (((d_year#3587 = 2001) AND (d_moy#3589 >= 4)) AND (d_moy#3589 <= 6))) AND isnotnull(d_date_sk#3581)))
    // Input: ListBuffer(d_date_sk#3581, d_year#3587, d_moy#3589)
    // Output: ListBuffer(d_date_sk#3581)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9412864_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3587 = tbl_SerializeFromObject_TD_9412864_input.getInt32(i, 1);
        int32_t _d_moy3589 = tbl_SerializeFromObject_TD_9412864_input.getInt32(i, 2);
        int32_t _d_date_sk3581 = tbl_SerializeFromObject_TD_9412864_input.getInt32(i, 0);
        if ((((_d_year3587!= 0) && (_d_moy3589!= 0)) && (((_d_year3587 == 2001) && (_d_moy3589 >= 4)) && (_d_moy3589 <= 6))) && (_d_date_sk3581!= 0)) {
            int32_t _d_date_sk3581_t = tbl_SerializeFromObject_TD_9412864_input.getInt32(i, 0);
            tbl_Filter_TD_8385324_output.setInt32(r, 0, _d_date_sk3581_t);
            r++;
        }
    }
    tbl_Filter_TD_8385324_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8385324_output #Row: " << tbl_Filter_TD_8385324_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8877333(Table &tbl_SerializeFromObject_TD_9446430_input, Table &tbl_Filter_TD_8877333_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(cs_sold_date_sk#1104))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_ship_customer_sk#1111)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_ship_customer_sk#1111)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9446430_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_9446430_input.getInt32(i, 0);
        if (_cs_sold_date_sk1104!= 0) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_9446430_input.getInt32(i, 0);
            tbl_Filter_TD_8877333_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int32_t _cs_ship_customer_sk1111_t = tbl_SerializeFromObject_TD_9446430_input.getInt32(i, 1);
            tbl_Filter_TD_8877333_output.setInt32(r, 1, _cs_ship_customer_sk1111_t);
            r++;
        }
    }
    tbl_Filter_TD_8877333_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8877333_output #Row: " << tbl_Filter_TD_8877333_output.getNumRow() << std::endl;
}





void SW_Filter_TD_6774424(Table &tbl_SerializeFromObject_TD_7871697_input, Table &tbl_Filter_TD_6774424_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((ca_state#62 IN (KY,GA,NM) AND isnotnull(ca_address_sk#54)))
    // Input: ListBuffer(ca_address_sk#54, ca_state#62)
    // Output: ListBuffer(ca_address_sk#54)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7871697_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_state62 = tbl_SerializeFromObject_TD_7871697_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _ca_address_sk54 = tbl_SerializeFromObject_TD_7871697_input.getInt32(i, 0);
        auto reuse_col_str_503 = std::string(_ca_state62.data());
        if (((reuse_col_str_503 == "KY") || (reuse_col_str_503 == "GA") || (reuse_col_str_503 == "NM") || (0)) && (_ca_address_sk54!= 0)) {
            int32_t _ca_address_sk54_t = tbl_SerializeFromObject_TD_7871697_input.getInt32(i, 0);
            tbl_Filter_TD_6774424_output.setInt32(r, 0, _ca_address_sk54_t);
            r++;
        }
    }
    tbl_Filter_TD_6774424_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6774424_output #Row: " << tbl_Filter_TD_6774424_output.getNumRow() << std::endl;
}


void SW_Filter_TD_5392010(Table &tbl_SerializeFromObject_TD_6681835_input, Table &tbl_Filter_TD_5392010_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(cd_demo_sk#93))
    // Input: ListBuffer(cd_demo_sk#93, cd_gender#94, cd_marital_status#95, cd_education_status#96, cd_purchase_estimate#97, cd_credit_rating#98)
    // Output: ListBuffer(cd_demo_sk#93, cd_gender#94, cd_marital_status#95, cd_education_status#96, cd_purchase_estimate#97, cd_credit_rating#98)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6681835_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cd_demo_sk93 = tbl_SerializeFromObject_TD_6681835_input.getInt32(i, 0);
        if (_cd_demo_sk93!= 0) {
            int32_t _cd_demo_sk93_t = tbl_SerializeFromObject_TD_6681835_input.getInt32(i, 0);
            tbl_Filter_TD_5392010_output.setInt32(r, 0, _cd_demo_sk93_t);
            std::array<char, TPCDS_READ_MAX + 1> _cd_gender94_t = tbl_SerializeFromObject_TD_6681835_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_5392010_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cd_gender94_t);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_t = tbl_SerializeFromObject_TD_6681835_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_5392010_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cd_marital_status95_t);
            std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_t = tbl_SerializeFromObject_TD_6681835_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_5392010_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _cd_education_status96_t);
            int32_t _cd_purchase_estimate97_t = tbl_SerializeFromObject_TD_6681835_input.getInt32(i, 4);
            tbl_Filter_TD_5392010_output.setInt32(r, 4, _cd_purchase_estimate97_t);
            std::array<char, TPCDS_READ_MAX + 1> _cd_credit_rating98_t = tbl_SerializeFromObject_TD_6681835_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            tbl_Filter_TD_5392010_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _cd_credit_rating98_t);
            r++;
        }
    }
    tbl_Filter_TD_5392010_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5392010_output #Row: " << tbl_Filter_TD_5392010_output.getNumRow() << std::endl;
}


struct SW_JOIN_INNER_TD_4103900_key_leftMajor {
    int32_t _c_current_cdemo_sk2;
    bool operator==(const SW_JOIN_INNER_TD_4103900_key_leftMajor& other) const {
        return ((_c_current_cdemo_sk2 == other._c_current_cdemo_sk2));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4103900_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4103900_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_current_cdemo_sk2));
    }
};
}
struct SW_JOIN_INNER_TD_4103900_payload_leftMajor {
    int32_t _c_current_cdemo_sk2;
};
struct SW_JOIN_INNER_TD_4103900_key_rightMajor {
    int32_t _cd_demo_sk93;
    bool operator==(const SW_JOIN_INNER_TD_4103900_key_rightMajor& other) const {
        return ((_cd_demo_sk93 == other._cd_demo_sk93));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4103900_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4103900_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cd_demo_sk93));
    }
};
}
struct SW_JOIN_INNER_TD_4103900_payload_rightMajor {
    int32_t _cd_demo_sk93;
    std::string _cd_gender94;
    std::string _cd_marital_status95;
    std::string _cd_education_status96;
    int32_t _cd_purchase_estimate97;
    std::string _cd_credit_rating98;
};
void SW_JOIN_INNER_TD_4103900(Table &tbl_JOIN_INNER_TD_5163540_output, Table &tbl_Filter_TD_5392010_output, Table &tbl_JOIN_INNER_TD_4103900_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cd_demo_sk#93 = c_current_cdemo_sk#2))
    // Left Table: ListBuffer(c_current_cdemo_sk#2)
    // Right Table: ListBuffer(cd_demo_sk#93, cd_gender#94, cd_marital_status#95, cd_education_status#96, cd_purchase_estimate#97, cd_credit_rating#98)
    // Output Table: ListBuffer(cd_gender#94, cd_marital_status#95, cd_education_status#96, cd_purchase_estimate#97, cd_credit_rating#98)
    int left_nrow = tbl_JOIN_INNER_TD_5163540_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5392010_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4103900_key_leftMajor, SW_JOIN_INNER_TD_4103900_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_5163540_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_current_cdemo_sk2_k = tbl_JOIN_INNER_TD_5163540_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4103900_key_leftMajor keyA{_c_current_cdemo_sk2_k};
            int32_t _c_current_cdemo_sk2 = tbl_JOIN_INNER_TD_5163540_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4103900_payload_leftMajor payloadA{_c_current_cdemo_sk2};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5392010_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cd_demo_sk93_k = tbl_Filter_TD_5392010_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4103900_key_leftMajor{_cd_demo_sk93_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_current_cdemo_sk2 = (it->second)._c_current_cdemo_sk2;
                int32_t _cd_demo_sk93 = tbl_Filter_TD_5392010_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _cd_gender94_n = tbl_Filter_TD_5392010_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _cd_gender94 = std::string(_cd_gender94_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n = tbl_Filter_TD_5392010_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _cd_marital_status95 = std::string(_cd_marital_status95_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_n = tbl_Filter_TD_5392010_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _cd_education_status96 = std::string(_cd_education_status96_n.data());
                int32_t _cd_purchase_estimate97 = tbl_Filter_TD_5392010_output.getInt32(i, 4);
                std::array<char, TPCDS_READ_MAX + 1> _cd_credit_rating98_n = tbl_Filter_TD_5392010_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _cd_credit_rating98 = std::string(_cd_credit_rating98_n.data());
                tbl_JOIN_INNER_TD_4103900_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _cd_gender94_n);
                tbl_JOIN_INNER_TD_4103900_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cd_marital_status95_n);
                tbl_JOIN_INNER_TD_4103900_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cd_education_status96_n);
                tbl_JOIN_INNER_TD_4103900_output.setInt32(r, 3, _cd_purchase_estimate97);
                tbl_JOIN_INNER_TD_4103900_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _cd_credit_rating98_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4103900_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4103900_key_rightMajor, SW_JOIN_INNER_TD_4103900_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5392010_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cd_demo_sk93_k = tbl_Filter_TD_5392010_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4103900_key_rightMajor keyA{_cd_demo_sk93_k};
            int32_t _cd_demo_sk93 = tbl_Filter_TD_5392010_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _cd_gender94_n = tbl_Filter_TD_5392010_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cd_gender94 = std::string(_cd_gender94_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n = tbl_Filter_TD_5392010_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _cd_marital_status95 = std::string(_cd_marital_status95_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_n = tbl_Filter_TD_5392010_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _cd_education_status96 = std::string(_cd_education_status96_n.data());
            int32_t _cd_purchase_estimate97 = tbl_Filter_TD_5392010_output.getInt32(i, 4);
            std::array<char, TPCDS_READ_MAX + 1> _cd_credit_rating98_n = tbl_Filter_TD_5392010_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _cd_credit_rating98 = std::string(_cd_credit_rating98_n.data());
            SW_JOIN_INNER_TD_4103900_payload_rightMajor payloadA{_cd_demo_sk93, _cd_gender94, _cd_marital_status95, _cd_education_status96, _cd_purchase_estimate97, _cd_credit_rating98};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_5163540_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_current_cdemo_sk2_k = tbl_JOIN_INNER_TD_5163540_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4103900_key_rightMajor{_c_current_cdemo_sk2_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cd_demo_sk93 = (it->second)._cd_demo_sk93;
                std::string _cd_gender94 = (it->second)._cd_gender94;
                std::array<char, TPCDS_READ_MAX + 1> _cd_gender94_n{};
                memcpy(_cd_gender94_n.data(), (_cd_gender94).data(), (_cd_gender94).length());
                std::string _cd_marital_status95 = (it->second)._cd_marital_status95;
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n{};
                memcpy(_cd_marital_status95_n.data(), (_cd_marital_status95).data(), (_cd_marital_status95).length());
                std::string _cd_education_status96 = (it->second)._cd_education_status96;
                std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_n{};
                memcpy(_cd_education_status96_n.data(), (_cd_education_status96).data(), (_cd_education_status96).length());
                int32_t _cd_purchase_estimate97 = (it->second)._cd_purchase_estimate97;
                std::string _cd_credit_rating98 = (it->second)._cd_credit_rating98;
                std::array<char, TPCDS_READ_MAX + 1> _cd_credit_rating98_n{};
                memcpy(_cd_credit_rating98_n.data(), (_cd_credit_rating98).data(), (_cd_credit_rating98).length());
                int32_t _c_current_cdemo_sk2 = tbl_JOIN_INNER_TD_5163540_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_4103900_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _cd_gender94_n);
                tbl_JOIN_INNER_TD_4103900_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cd_marital_status95_n);
                tbl_JOIN_INNER_TD_4103900_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cd_education_status96_n);
                tbl_JOIN_INNER_TD_4103900_output.setInt32(r, 3, _cd_purchase_estimate97);
                tbl_JOIN_INNER_TD_4103900_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _cd_credit_rating98_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4103900_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4103900_output #Row: " << tbl_JOIN_INNER_TD_4103900_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_3194621_key {
    std::string _cd_gender94;
    std::string _cd_marital_status95;
    std::string _cd_education_status96;
    int32_t _cd_purchase_estimate97;
    std::string _cd_credit_rating98;
    bool operator==(const SW_Aggregate_TD_3194621_key& other) const { return (_cd_gender94 == other._cd_gender94) && (_cd_marital_status95 == other._cd_marital_status95) && (_cd_education_status96 == other._cd_education_status96) && (_cd_purchase_estimate97 == other._cd_purchase_estimate97) && (_cd_credit_rating98 == other._cd_credit_rating98); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_3194621_key> {
    std::size_t operator() (const SW_Aggregate_TD_3194621_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._cd_gender94)) + (hash<string>()(k._cd_marital_status95)) + (hash<string>()(k._cd_education_status96)) + (hash<int32_t>()(k._cd_purchase_estimate97)) + (hash<string>()(k._cd_credit_rating98));
    }
};
}
struct SW_Aggregate_TD_3194621_payload {
    int64_t _cnt13544L_count_0;
    int64_t _cnt23545L_count_1;
    int64_t _cnt33546L_count_2;
};
void SW_Aggregate_TD_3194621(Table &tbl_JOIN_INNER_TD_4103900_output, Table &tbl_Aggregate_TD_3194621_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(cd_gender#94, cd_marital_status#95, cd_education_status#96, cd_purchase_estimate#97, cd_credit_rating#98, count(1) AS cnt1#3544L, count(1) AS cnt2#3545L, count(1) AS cnt3#3546L)
    // Input: ListBuffer(cd_gender#94, cd_marital_status#95, cd_education_status#96, cd_purchase_estimate#97, cd_credit_rating#98)
    // Output: ListBuffer(cd_gender#94, cd_marital_status#95, cd_education_status#96, cnt1#3544L, cd_purchase_estimate#97, cnt2#3545L, cd_credit_rating#98, cnt3#3546L)
    std::unordered_map<SW_Aggregate_TD_3194621_key, SW_Aggregate_TD_3194621_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_4103900_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _cd_gender94 = tbl_JOIN_INNER_TD_4103900_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95 = tbl_JOIN_INNER_TD_4103900_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96 = tbl_JOIN_INNER_TD_4103900_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        int32_t _cd_purchase_estimate97 = tbl_JOIN_INNER_TD_4103900_output.getInt32(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _cd_credit_rating98 = tbl_JOIN_INNER_TD_4103900_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        SW_Aggregate_TD_3194621_key k{std::string(_cd_gender94.data()), std::string(_cd_marital_status95.data()), std::string(_cd_education_status96.data()), _cd_purchase_estimate97, std::string(_cd_credit_rating98.data())};
        int64_t _cnt13544L_count_0 = 1 != 0 ? 1 : 0;
        int64_t _cnt23545L_count_1 = 1 != 0 ? 1 : 0;
        int64_t _cnt33546L_count_2 = 1 != 0 ? 1 : 0;
        SW_Aggregate_TD_3194621_payload p{_cnt13544L_count_0, _cnt23545L_count_1, _cnt33546L_count_2};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t count_0 = (it->second)._cnt13544L_count_0 + _cnt13544L_count_0;
            p._cnt13544L_count_0 = count_0;
            int64_t count_1 = (it->second)._cnt23545L_count_1 + _cnt23545L_count_1;
            p._cnt23545L_count_1 = count_1;
            int64_t count_2 = (it->second)._cnt33546L_count_2 + _cnt33546L_count_2;
            p._cnt33546L_count_2 = count_2;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _cd_gender94{};
        memcpy(_cd_gender94.data(), ((it.first)._cd_gender94).data(), ((it.first)._cd_gender94).length());
        tbl_Aggregate_TD_3194621_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _cd_gender94);
        std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95{};
        memcpy(_cd_marital_status95.data(), ((it.first)._cd_marital_status95).data(), ((it.first)._cd_marital_status95).length());
        tbl_Aggregate_TD_3194621_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cd_marital_status95);
        std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96{};
        memcpy(_cd_education_status96.data(), ((it.first)._cd_education_status96).data(), ((it.first)._cd_education_status96).length());
        tbl_Aggregate_TD_3194621_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cd_education_status96);
        tbl_Aggregate_TD_3194621_output.setInt32(r, 4, (it.first)._cd_purchase_estimate97);
        std::array<char, TPCDS_READ_MAX + 1> _cd_credit_rating98{};
        memcpy(_cd_credit_rating98.data(), ((it.first)._cd_credit_rating98).data(), ((it.first)._cd_credit_rating98).length());
        tbl_Aggregate_TD_3194621_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _cd_credit_rating98);
        int64_t _cnt13544L = (it.second)._cnt13544L_count_0;
        tbl_Aggregate_TD_3194621_output.setInt64(r, 3, _cnt13544L);
        int64_t _cnt23545L = (it.second)._cnt23545L_count_1;
        tbl_Aggregate_TD_3194621_output.setInt64(r, 5, _cnt23545L);
        int64_t _cnt33546L = (it.second)._cnt33546L_count_2;
        tbl_Aggregate_TD_3194621_output.setInt64(r, 7, _cnt33546L);
        ++r;
    }
    tbl_Aggregate_TD_3194621_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_3194621_output #Row: " << tbl_Aggregate_TD_3194621_output.getNumRow() << std::endl;
}

void SW_Sort_TD_210950(Table &tbl_Aggregate_TD_3194621_output, Table &tbl_Sort_TD_210950_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(cd_gender#94 ASC NULLS FIRST, cd_marital_status#95 ASC NULLS FIRST, cd_education_status#96 ASC NULLS FIRST, cd_purchase_estimate#97 ASC NULLS FIRST, cd_credit_rating#98 ASC NULLS FIRST)
    // Input: ListBuffer(cd_gender#94, cd_marital_status#95, cd_education_status#96, cnt1#3544L, cd_purchase_estimate#97, cnt2#3545L, cd_credit_rating#98, cnt3#3546L)
    // Output: ListBuffer(cd_gender#94, cd_marital_status#95, cd_education_status#96, cnt1#3544L, cd_purchase_estimate#97, cnt2#3545L, cd_credit_rating#98, cnt3#3546L)
    struct SW_Sort_TD_210950Row {
        std::string _cd_gender94;
        std::string _cd_marital_status95;
        std::string _cd_education_status96;
        int64_t _cnt13544L;
        int32_t _cd_purchase_estimate97;
        int64_t _cnt23545L;
        std::string _cd_credit_rating98;
        int64_t _cnt33546L;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_210950Row& a, const SW_Sort_TD_210950Row& b) const { return 
 (a._cd_gender94 < b._cd_gender94) || 
 ((a._cd_gender94 == b._cd_gender94) && (a._cd_marital_status95 < b._cd_marital_status95)) || 
 ((a._cd_gender94 == b._cd_gender94) && (a._cd_marital_status95 == b._cd_marital_status95) && (a._cd_education_status96 < b._cd_education_status96)) || 
 ((a._cd_gender94 == b._cd_gender94) && (a._cd_marital_status95 == b._cd_marital_status95) && (a._cd_education_status96 == b._cd_education_status96) && (a._cd_purchase_estimate97 < b._cd_purchase_estimate97)) || 
 ((a._cd_gender94 == b._cd_gender94) && (a._cd_marital_status95 == b._cd_marital_status95) && (a._cd_education_status96 == b._cd_education_status96) && (a._cd_purchase_estimate97 == b._cd_purchase_estimate97) && (a._cd_credit_rating98 < b._cd_credit_rating98)); 
}
    }SW_Sort_TD_210950_order; 

    int nrow1 = tbl_Aggregate_TD_3194621_output.getNumRow();
    std::vector<SW_Sort_TD_210950Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _cd_gender94 = tbl_Aggregate_TD_3194621_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95 = tbl_Aggregate_TD_3194621_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96 = tbl_Aggregate_TD_3194621_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        int64_t _cnt13544L = tbl_Aggregate_TD_3194621_output.getInt64(i, 3);
        int32_t _cd_purchase_estimate97 = tbl_Aggregate_TD_3194621_output.getInt32(i, 4);
        int64_t _cnt23545L = tbl_Aggregate_TD_3194621_output.getInt64(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _cd_credit_rating98 = tbl_Aggregate_TD_3194621_output.getcharN<char, TPCDS_READ_MAX +1>(i, 6);
        int64_t _cnt33546L = tbl_Aggregate_TD_3194621_output.getInt64(i, 7);
        SW_Sort_TD_210950Row t = {std::string(_cd_gender94.data()),std::string(_cd_marital_status95.data()),std::string(_cd_education_status96.data()),_cnt13544L,_cd_purchase_estimate97,_cnt23545L,std::string(_cd_credit_rating98.data()),_cnt33546L};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_210950_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _cd_gender94{};
        memcpy(_cd_gender94.data(), (it._cd_gender94).data(), (it._cd_gender94).length());
        tbl_Sort_TD_210950_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _cd_gender94);
        std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95{};
        memcpy(_cd_marital_status95.data(), (it._cd_marital_status95).data(), (it._cd_marital_status95).length());
        tbl_Sort_TD_210950_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _cd_marital_status95);
        std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96{};
        memcpy(_cd_education_status96.data(), (it._cd_education_status96).data(), (it._cd_education_status96).length());
        tbl_Sort_TD_210950_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _cd_education_status96);
        tbl_Sort_TD_210950_output.setInt64(r, 3, it._cnt13544L);
        tbl_Sort_TD_210950_output.setInt32(r, 4, it._cd_purchase_estimate97);
        tbl_Sort_TD_210950_output.setInt64(r, 5, it._cnt23545L);
        std::array<char, TPCDS_READ_MAX + 1> _cd_credit_rating98{};
        memcpy(_cd_credit_rating98.data(), (it._cd_credit_rating98).data(), (it._cd_credit_rating98).length());
        tbl_Sort_TD_210950_output.setcharN<char, TPCDS_READ_MAX +1>(r, 6, _cd_credit_rating98);
        tbl_Sort_TD_210950_output.setInt64(r, 7, it._cnt33546L);
        ++r;
    }
    tbl_Sort_TD_210950_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_210950_output #Row: " << tbl_Sort_TD_210950_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1636925(Table &tbl_Sort_TD_210950_output, Table &tbl_LocalLimit_TD_1636925_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(cd_gender#94, cd_marital_status#95, cd_education_status#96, cnt1#3544L, cd_purchase_estimate#97, cnt2#3545L, cd_credit_rating#98, cnt3#3546L)
    // Output: ListBuffer(cd_gender#94, cd_marital_status#95, cd_education_status#96, cnt1#3544L, cd_purchase_estimate#97, cnt2#3545L, cd_credit_rating#98, cnt3#3546L)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _cd_gender94_n = tbl_Sort_TD_210950_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1636925_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _cd_gender94_n);
        std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n = tbl_Sort_TD_210950_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_1636925_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cd_marital_status95_n);
        std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_n = tbl_Sort_TD_210950_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_LocalLimit_TD_1636925_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cd_education_status96_n);
        tbl_LocalLimit_TD_1636925_output.setInt64(r, 3, tbl_Sort_TD_210950_output.getInt64(i, 3));
        tbl_LocalLimit_TD_1636925_output.setInt32(r, 4, tbl_Sort_TD_210950_output.getInt32(i, 4));
        tbl_LocalLimit_TD_1636925_output.setInt64(r, 5, tbl_Sort_TD_210950_output.getInt64(i, 5));
        std::array<char, TPCDS_READ_MAX + 1> _cd_credit_rating98_n = tbl_Sort_TD_210950_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        tbl_LocalLimit_TD_1636925_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _cd_credit_rating98_n);
        tbl_LocalLimit_TD_1636925_output.setInt64(r, 7, tbl_Sort_TD_210950_output.getInt64(i, 7));
        r++;
    }
    tbl_LocalLimit_TD_1636925_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1636925_output #Row: " << tbl_LocalLimit_TD_1636925_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0239138(Table &tbl_LocalLimit_TD_1636925_output, Table &tbl_GlobalLimit_TD_0239138_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(cd_gender#94, cd_marital_status#95, cd_education_status#96, cnt1#3544L, cd_purchase_estimate#97, cnt2#3545L, cd_credit_rating#98, cnt3#3546L)
    // Output: ListBuffer(cd_gender#94, cd_marital_status#95, cd_education_status#96, cnt1#3544L, cd_purchase_estimate#97, cnt2#3545L, cd_credit_rating#98, cnt3#3546L)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _cd_gender94_n = tbl_LocalLimit_TD_1636925_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0239138_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _cd_gender94_n);
        std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n = tbl_LocalLimit_TD_1636925_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_0239138_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cd_marital_status95_n);
        std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_n = tbl_LocalLimit_TD_1636925_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_GlobalLimit_TD_0239138_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cd_education_status96_n);
        tbl_GlobalLimit_TD_0239138_output.setInt64(r, 3, tbl_LocalLimit_TD_1636925_output.getInt64(i, 3));
        tbl_GlobalLimit_TD_0239138_output.setInt32(r, 4, tbl_LocalLimit_TD_1636925_output.getInt32(i, 4));
        tbl_GlobalLimit_TD_0239138_output.setInt64(r, 5, tbl_LocalLimit_TD_1636925_output.getInt64(i, 5));
        std::array<char, TPCDS_READ_MAX + 1> _cd_credit_rating98_n = tbl_LocalLimit_TD_1636925_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        tbl_GlobalLimit_TD_0239138_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _cd_credit_rating98_n);
        tbl_GlobalLimit_TD_0239138_output.setInt64(r, 7, tbl_LocalLimit_TD_1636925_output.getInt64(i, 7));
        r++;
    }
    tbl_GlobalLimit_TD_0239138_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0239138_output #Row: " << tbl_GlobalLimit_TD_0239138_output.getNumRow() << std::endl;
}

