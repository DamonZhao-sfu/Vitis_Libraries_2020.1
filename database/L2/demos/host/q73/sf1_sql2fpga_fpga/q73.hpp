#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_7755182(Table &tbl_SerializeFromObject_TD_8376746_input, Table &tbl_Filter_TD_7755182_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_dom#129) AND (((d_dom#129 >= 1) AND (d_dom#129 <= 2)) AND d_year#126 IN (1999,2000,2001))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_dom#129, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8376746_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_dom129 = tbl_SerializeFromObject_TD_8376746_input.getInt32(i, 1);
        int32_t _d_year126 = tbl_SerializeFromObject_TD_8376746_input.getInt32(i, 2);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_8376746_input.getInt32(i, 0);
        auto reuse_col_str_539 = _d_year126;
        if (((_d_dom129!= 0) && (((_d_dom129 >= 1) && (_d_dom129 <= 2)) && ((reuse_col_str_539 == 1999) || (reuse_col_str_539 == 2000) || (reuse_col_str_539 == 2001) || (0)))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_8376746_input.getInt32(i, 0);
            tbl_Filter_TD_7755182_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_7755182_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7755182_output #Row: " << tbl_Filter_TD_7755182_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7762564(Table &tbl_SerializeFromObject_TD_8512985_input, Table &tbl_Filter_TD_7762564_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_sold_date_sk#1206) AND ((isnotnull(ss_store_sk#1213) AND isnotnull(ss_hdemo_sk#1211)) AND isnotnull(ss_customer_sk#1209))))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_customer_sk#1209, ss_hdemo_sk#1211, ss_store_sk#1213, ss_ticket_number#1215L)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_customer_sk#1209, ss_hdemo_sk#1211, ss_store_sk#1213, ss_ticket_number#1215L)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8512985_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_8512985_input.getInt32(i, 0);
        int32_t _ss_store_sk1213 = tbl_SerializeFromObject_TD_8512985_input.getInt32(i, 3);
        int32_t _ss_hdemo_sk1211 = tbl_SerializeFromObject_TD_8512985_input.getInt32(i, 2);
        int32_t _ss_customer_sk1209 = tbl_SerializeFromObject_TD_8512985_input.getInt32(i, 1);
        if ((_ss_sold_date_sk1206!= 0) && (((_ss_store_sk1213!= 0) && (_ss_hdemo_sk1211!= 0)) && (_ss_customer_sk1209!= 0))) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_8512985_input.getInt32(i, 0);
            tbl_Filter_TD_7762564_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_customer_sk1209_t = tbl_SerializeFromObject_TD_8512985_input.getInt32(i, 1);
            tbl_Filter_TD_7762564_output.setInt32(r, 1, _ss_customer_sk1209_t);
            int32_t _ss_hdemo_sk1211_t = tbl_SerializeFromObject_TD_8512985_input.getInt32(i, 2);
            tbl_Filter_TD_7762564_output.setInt32(r, 2, _ss_hdemo_sk1211_t);
            int32_t _ss_store_sk1213_t = tbl_SerializeFromObject_TD_8512985_input.getInt32(i, 3);
            tbl_Filter_TD_7762564_output.setInt32(r, 3, _ss_store_sk1213_t);
            int64_t _ss_ticket_number1215L_t = tbl_SerializeFromObject_TD_8512985_input.getInt64(i, 4);
            tbl_Filter_TD_7762564_output.setInt64(r, 4, _ss_ticket_number1215L_t);
            r++;
        }
    }
    tbl_Filter_TD_7762564_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7762564_output #Row: " << tbl_Filter_TD_7762564_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6907262(Table &tbl_SerializeFromObject_TD_7231569_input, Table &tbl_Filter_TD_6907262_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((s_county#401 IN (Williamson County,Franklin Parish,Bronx County,Orange County) AND isnotnull(s_store_sk#378)))
    // Input: ListBuffer(s_store_sk#378, s_county#401)
    // Output: ListBuffer(s_store_sk#378)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7231569_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_county401 = tbl_SerializeFromObject_TD_7231569_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _s_store_sk378 = tbl_SerializeFromObject_TD_7231569_input.getInt32(i, 0);
        auto reuse_col_str_404 = std::string(_s_county401.data());
        if (((reuse_col_str_404 == "Williamson County") || (reuse_col_str_404 == "Franklin Parish") || (reuse_col_str_404 == "Bronx County") || (reuse_col_str_404 == "Orange County") || (0)) && (_s_store_sk378!= 0)) {
            int32_t _s_store_sk378_t = tbl_SerializeFromObject_TD_7231569_input.getInt32(i, 0);
            tbl_Filter_TD_6907262_output.setInt32(r, 0, _s_store_sk378_t);
            r++;
        }
    }
    tbl_Filter_TD_6907262_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6907262_output #Row: " << tbl_Filter_TD_6907262_output.getNumRow() << std::endl;
}


void SW_Filter_TD_5718803(Table &tbl_SerializeFromObject_TD_6409495_input, Table &tbl_Filter_TD_5718803_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(hd_vehicle_count#208) AND isnotnull(hd_dep_count#207)) AND ((((hd_buy_potential#206 = >10000) OR (hd_buy_potential#206 = unknown)) AND (hd_vehicle_count#208 > 0)) AND ((cast(hd_dep_count#207 as double) / cast(hd_vehicle_count#208 as double)) > 1.0))) AND isnotnull(hd_demo_sk#204)))
    // Input: ListBuffer(hd_demo_sk#204, hd_vehicle_count#208, hd_dep_count#207, hd_buy_potential#206)
    // Output: ListBuffer(hd_demo_sk#204)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6409495_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _hd_vehicle_count208 = tbl_SerializeFromObject_TD_6409495_input.getInt32(i, 1);
        int32_t _hd_dep_count207 = tbl_SerializeFromObject_TD_6409495_input.getInt32(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _hd_buy_potential206 = tbl_SerializeFromObject_TD_6409495_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        int32_t _hd_demo_sk204 = tbl_SerializeFromObject_TD_6409495_input.getInt32(i, 0);
        if ((((_hd_vehicle_count208!= 0) && (_hd_dep_count207!= 0)) && ((((std::string(_hd_buy_potential206.data()) == ">10000") || (std::string(_hd_buy_potential206.data()) == "unknown")) && (_hd_vehicle_count208 > 0)) && (_hd_dep_count207 > 1.0))) && (_hd_demo_sk204!= 0)) {
            int32_t _hd_demo_sk204_t = tbl_SerializeFromObject_TD_6409495_input.getInt32(i, 0);
            tbl_Filter_TD_5718803_output.setInt32(r, 0, _hd_demo_sk204_t);
            r++;
        }
    }
    tbl_Filter_TD_5718803_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5718803_output #Row: " << tbl_Filter_TD_5718803_output.getNumRow() << std::endl;
}



void SW_Aggregate_TD_3379653_consolidate(Table &tbl_Aggregate_TD_3379653_output_preprocess, Table &tbl_Aggregate_TD_3379653_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_3379653_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _ss_ticket_number1215L = tbl_Aggregate_TD_3379653_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_3379653_output.setInt32(r, 0, _ss_ticket_number1215L);
        int32_t _ss_customer_sk1209 = tbl_Aggregate_TD_3379653_output_preprocess.getInt32(r, 6);
        tbl_Aggregate_TD_3379653_output.setInt32(r, 1, _ss_customer_sk1209);
        int32_t _cnt3544L = tbl_Aggregate_TD_3379653_output_preprocess.getInt32(r, 0);
        tbl_Aggregate_TD_3379653_output.setInt32(r, 2, _cnt3544L);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_3379653_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_3379653_output #Row: " << tbl_Aggregate_TD_3379653_output.getNumRow() << std::endl;
}

void SW_Filter_TD_2351272(Table &tbl_SerializeFromObject_TD_372725_input, Table &tbl_Filter_TD_2351272_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(c_customer_sk#0))
    // Input: ListBuffer(c_customer_sk#0, c_salutation#7, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10)
    // Output: ListBuffer(c_customer_sk#0, c_salutation#7, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_372725_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk0 = tbl_SerializeFromObject_TD_372725_input.getInt32(i, 0);
        if (_c_customer_sk0!= 0) {
            int32_t _c_customer_sk0_t = tbl_SerializeFromObject_TD_372725_input.getInt32(i, 0);
            tbl_Filter_TD_2351272_output.setInt32(r, 0, _c_customer_sk0_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_salutation7_t = tbl_SerializeFromObject_TD_372725_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_2351272_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_salutation7_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_t = tbl_SerializeFromObject_TD_372725_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_2351272_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name8_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_t = tbl_SerializeFromObject_TD_372725_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_2351272_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name9_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_t = tbl_SerializeFromObject_TD_372725_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            tbl_Filter_TD_2351272_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_preferred_cust_flag10_t);
            r++;
        }
    }
    tbl_Filter_TD_2351272_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2351272_output #Row: " << tbl_Filter_TD_2351272_output.getNumRow() << std::endl;
}

void SW_Filter_TD_2307795(Table &tbl_Aggregate_TD_3379653_output, Table &tbl_Filter_TD_2307795_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((cnt#3544L >= 1) AND (cnt#3544L <= 5)))
    // Input: ListBuffer(ss_ticket_number#1215L, ss_customer_sk#1209, cnt#3544L)
    // Output: ListBuffer(ss_ticket_number#1215L, ss_customer_sk#1209, cnt#3544L)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_3379653_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _cnt3544L = tbl_Aggregate_TD_3379653_output.getInt64(i, 2);
        if ((_cnt3544L >= 1) && (_cnt3544L <= 5)) {
            int64_t _ss_ticket_number1215L_t = tbl_Aggregate_TD_3379653_output.getInt64(i, 0);
            tbl_Filter_TD_2307795_output.setInt64(r, 0, _ss_ticket_number1215L_t);
            int32_t _ss_customer_sk1209_t = tbl_Aggregate_TD_3379653_output.getInt32(i, 1);
            tbl_Filter_TD_2307795_output.setInt32(r, 1, _ss_customer_sk1209_t);
            int64_t _cnt3544L_t = tbl_Aggregate_TD_3379653_output.getInt64(i, 2);
            tbl_Filter_TD_2307795_output.setInt64(r, 2, _cnt3544L_t);
            r++;
        }
    }
    tbl_Filter_TD_2307795_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2307795_output #Row: " << tbl_Filter_TD_2307795_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_1526490_key_leftMajor {
    int32_t _ss_customer_sk1209;
    bool operator==(const SW_JOIN_INNER_TD_1526490_key_leftMajor& other) const {
        return ((_ss_customer_sk1209 == other._ss_customer_sk1209));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_1526490_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_1526490_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_customer_sk1209));
    }
};
}
struct SW_JOIN_INNER_TD_1526490_payload_leftMajor {
    int64_t _ss_ticket_number1215L;
    int32_t _ss_customer_sk1209;
    int64_t _cnt3544L;
};
struct SW_JOIN_INNER_TD_1526490_key_rightMajor {
    int32_t _c_customer_sk0;
    bool operator==(const SW_JOIN_INNER_TD_1526490_key_rightMajor& other) const {
        return ((_c_customer_sk0 == other._c_customer_sk0));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_1526490_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_1526490_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk0));
    }
};
}
struct SW_JOIN_INNER_TD_1526490_payload_rightMajor {
    int32_t _c_customer_sk0;
    std::string _c_salutation7;
    std::string _c_first_name8;
    std::string _c_last_name9;
    std::string _c_preferred_cust_flag10;
};
void SW_JOIN_INNER_TD_1526490(Table &tbl_Filter_TD_2307795_output, Table &tbl_Filter_TD_2351272_output, Table &tbl_JOIN_INNER_TD_1526490_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_customer_sk#1209 = c_customer_sk#0))
    // Left Table: ListBuffer(ss_ticket_number#1215L, ss_customer_sk#1209, cnt#3544L)
    // Right Table: ListBuffer(c_customer_sk#0, c_salutation#7, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10)
    // Output Table: ListBuffer(c_last_name#9, c_first_name#8, c_salutation#7, c_preferred_cust_flag#10, ss_ticket_number#1215L, cnt#3544L)
    int left_nrow = tbl_Filter_TD_2307795_output.getNumRow();
    int right_nrow = tbl_Filter_TD_2351272_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_1526490_key_leftMajor, SW_JOIN_INNER_TD_1526490_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_2307795_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_customer_sk1209_k = tbl_Filter_TD_2307795_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_1526490_key_leftMajor keyA{_ss_customer_sk1209_k};
            int64_t _ss_ticket_number1215L = tbl_Filter_TD_2307795_output.getInt64(i, 0);
            int32_t _ss_customer_sk1209 = tbl_Filter_TD_2307795_output.getInt32(i, 1);
            int64_t _cnt3544L = tbl_Filter_TD_2307795_output.getInt64(i, 2);
            SW_JOIN_INNER_TD_1526490_payload_leftMajor payloadA{_ss_ticket_number1215L, _ss_customer_sk1209, _cnt3544L};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_2351272_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_2351272_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_1526490_key_leftMajor{_c_customer_sk0_k});
            auto it = its.first;
            while (it != its.second) {
                int64_t _ss_ticket_number1215L = (it->second)._ss_ticket_number1215L;
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                int64_t _cnt3544L = (it->second)._cnt3544L;
                int32_t _c_customer_sk0 = tbl_Filter_TD_2351272_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_salutation7_n = tbl_Filter_TD_2351272_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_salutation7 = std::string(_c_salutation7_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_Filter_TD_2351272_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_first_name8 = std::string(_c_first_name8_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_Filter_TD_2351272_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_last_name9 = std::string(_c_last_name9_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_n = tbl_Filter_TD_2351272_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_preferred_cust_flag10 = std::string(_c_preferred_cust_flag10_n.data());
                tbl_JOIN_INNER_TD_1526490_output.setInt64(r, 4, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_1526490_output.setInt64(r, 5, _cnt3544L);
                tbl_JOIN_INNER_TD_1526490_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_salutation7_n);
                tbl_JOIN_INNER_TD_1526490_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
                tbl_JOIN_INNER_TD_1526490_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name9_n);
                tbl_JOIN_INNER_TD_1526490_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag10_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_1526490_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_1526490_key_rightMajor, SW_JOIN_INNER_TD_1526490_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_2351272_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_2351272_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_1526490_key_rightMajor keyA{_c_customer_sk0_k};
            int32_t _c_customer_sk0 = tbl_Filter_TD_2351272_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _c_salutation7_n = tbl_Filter_TD_2351272_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_salutation7 = std::string(_c_salutation7_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_Filter_TD_2351272_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_first_name8 = std::string(_c_first_name8_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_Filter_TD_2351272_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_last_name9 = std::string(_c_last_name9_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_n = tbl_Filter_TD_2351272_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_preferred_cust_flag10 = std::string(_c_preferred_cust_flag10_n.data());
            SW_JOIN_INNER_TD_1526490_payload_rightMajor payloadA{_c_customer_sk0, _c_salutation7, _c_first_name8, _c_last_name9, _c_preferred_cust_flag10};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_2307795_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_customer_sk1209_k = tbl_Filter_TD_2307795_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_1526490_key_rightMajor{_ss_customer_sk1209_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk0 = (it->second)._c_customer_sk0;
                std::string _c_salutation7 = (it->second)._c_salutation7;
                std::array<char, TPCDS_READ_MAX + 1> _c_salutation7_n{};
                memcpy(_c_salutation7_n.data(), (_c_salutation7).data(), (_c_salutation7).length());
                std::string _c_first_name8 = (it->second)._c_first_name8;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n{};
                memcpy(_c_first_name8_n.data(), (_c_first_name8).data(), (_c_first_name8).length());
                std::string _c_last_name9 = (it->second)._c_last_name9;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n{};
                memcpy(_c_last_name9_n.data(), (_c_last_name9).data(), (_c_last_name9).length());
                std::string _c_preferred_cust_flag10 = (it->second)._c_preferred_cust_flag10;
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_n{};
                memcpy(_c_preferred_cust_flag10_n.data(), (_c_preferred_cust_flag10).data(), (_c_preferred_cust_flag10).length());
                int64_t _ss_ticket_number1215L = tbl_Filter_TD_2307795_output.getInt64(i, 0);
                int32_t _ss_customer_sk1209 = tbl_Filter_TD_2307795_output.getInt32(i, 1);
                int64_t _cnt3544L = tbl_Filter_TD_2307795_output.getInt64(i, 2);
                tbl_JOIN_INNER_TD_1526490_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_salutation7_n);
                tbl_JOIN_INNER_TD_1526490_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
                tbl_JOIN_INNER_TD_1526490_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name9_n);
                tbl_JOIN_INNER_TD_1526490_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag10_n);
                tbl_JOIN_INNER_TD_1526490_output.setInt64(r, 4, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_1526490_output.setInt64(r, 5, _cnt3544L);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_1526490_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_1526490_output #Row: " << tbl_JOIN_INNER_TD_1526490_output.getNumRow() << std::endl;
}

void SW_Sort_TD_0926499(Table &tbl_JOIN_INNER_TD_1526490_output, Table &tbl_Sort_TD_0926499_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(cnt#3544L DESC NULLS LAST, c_last_name#9 ASC NULLS FIRST)
    // Input: ListBuffer(c_last_name#9, c_first_name#8, c_salutation#7, c_preferred_cust_flag#10, ss_ticket_number#1215L, cnt#3544L)
    // Output: ListBuffer(c_last_name#9, c_first_name#8, c_salutation#7, c_preferred_cust_flag#10, ss_ticket_number#1215L, cnt#3544L)
    struct SW_Sort_TD_0926499Row {
        std::string _c_last_name9;
        std::string _c_first_name8;
        std::string _c_salutation7;
        std::string _c_preferred_cust_flag10;
        int64_t _ss_ticket_number1215L;
        int64_t _cnt3544L;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_0926499Row& a, const SW_Sort_TD_0926499Row& b) const { return 
 (a._cnt3544L > b._cnt3544L) || 
 ((a._cnt3544L == b._cnt3544L) && (a._c_last_name9 < b._c_last_name9)); 
}
    }SW_Sort_TD_0926499_order; 

    int nrow1 = tbl_JOIN_INNER_TD_1526490_output.getNumRow();
    std::vector<SW_Sort_TD_0926499Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9 = tbl_JOIN_INNER_TD_1526490_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8 = tbl_JOIN_INNER_TD_1526490_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _c_salutation7 = tbl_JOIN_INNER_TD_1526490_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10 = tbl_JOIN_INNER_TD_1526490_output.getcharN<char, TPCDS_READ_MAX +1>(i, 3);
        int64_t _ss_ticket_number1215L = tbl_JOIN_INNER_TD_1526490_output.getInt64(i, 4);
        int64_t _cnt3544L = tbl_JOIN_INNER_TD_1526490_output.getInt64(i, 5);
        SW_Sort_TD_0926499Row t = {std::string(_c_last_name9.data()),std::string(_c_first_name8.data()),std::string(_c_salutation7.data()),std::string(_c_preferred_cust_flag10.data()),_ss_ticket_number1215L,_cnt3544L};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_0926499_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9{};
        memcpy(_c_last_name9.data(), (it._c_last_name9).data(), (it._c_last_name9).length());
        tbl_Sort_TD_0926499_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _c_last_name9);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8{};
        memcpy(_c_first_name8.data(), (it._c_first_name8).data(), (it._c_first_name8).length());
        tbl_Sort_TD_0926499_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _c_first_name8);
        std::array<char, TPCDS_READ_MAX + 1> _c_salutation7{};
        memcpy(_c_salutation7.data(), (it._c_salutation7).data(), (it._c_salutation7).length());
        tbl_Sort_TD_0926499_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _c_salutation7);
        std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10{};
        memcpy(_c_preferred_cust_flag10.data(), (it._c_preferred_cust_flag10).data(), (it._c_preferred_cust_flag10).length());
        tbl_Sort_TD_0926499_output.setcharN<char, TPCDS_READ_MAX +1>(r, 3, _c_preferred_cust_flag10);
        tbl_Sort_TD_0926499_output.setInt64(r, 4, it._ss_ticket_number1215L);
        tbl_Sort_TD_0926499_output.setInt64(r, 5, it._cnt3544L);
        if (r < 10) {
            std::cout << (it._c_last_name9).data() << " " << (it._c_first_name8).data() << " " << (it._c_salutation7).data() << " " << (it._c_preferred_cust_flag10).data() << " " << it._ss_ticket_number1215L << " " << it._cnt3544L << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_0926499_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_0926499_output #Row: " << tbl_Sort_TD_0926499_output.getNumRow() << std::endl;
}

