#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_7739985(Table &tbl_SerializeFromObject_TD_815489_input, Table &tbl_Filter_TD_7739985_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((((d_dom#129 >= 1) AND (d_dom#129 <= 3)) OR ((d_dom#129 >= 25) AND (d_dom#129 <= 28))) AND d_year#126 IN (1999,2000,2001)) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_dom#129, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_815489_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_dom129 = tbl_SerializeFromObject_TD_815489_input.getInt32(i, 1);
        int32_t _d_year126 = tbl_SerializeFromObject_TD_815489_input.getInt32(i, 2);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_815489_input.getInt32(i, 0);
        auto reuse_col_str_934 = _d_year126;
        if (((((_d_dom129 >= 1) && (_d_dom129 <= 3)) || ((_d_dom129 >= 25) && (_d_dom129 <= 28))) && ((reuse_col_str_934 == 1999) || (reuse_col_str_934 == 2000) || (reuse_col_str_934 == 2001) || (0))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_815489_input.getInt32(i, 0);
            tbl_Filter_TD_7739985_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_7739985_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7739985_output #Row: " << tbl_Filter_TD_7739985_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7991912(Table &tbl_SerializeFromObject_TD_8451563_input, Table &tbl_Filter_TD_7991912_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_sold_date_sk#1206) AND ((isnotnull(ss_store_sk#1213) AND isnotnull(ss_hdemo_sk#1211)) AND isnotnull(ss_customer_sk#1209))))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_customer_sk#1209, ss_hdemo_sk#1211, ss_store_sk#1213, ss_ticket_number#1215L)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_customer_sk#1209, ss_hdemo_sk#1211, ss_store_sk#1213, ss_ticket_number#1215L)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8451563_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_8451563_input.getInt32(i, 0);
        int32_t _ss_store_sk1213 = tbl_SerializeFromObject_TD_8451563_input.getInt32(i, 3);
        int32_t _ss_hdemo_sk1211 = tbl_SerializeFromObject_TD_8451563_input.getInt32(i, 2);
        int32_t _ss_customer_sk1209 = tbl_SerializeFromObject_TD_8451563_input.getInt32(i, 1);
        if ((_ss_sold_date_sk1206!= 0) && (((_ss_store_sk1213!= 0) && (_ss_hdemo_sk1211!= 0)) && (_ss_customer_sk1209!= 0))) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_8451563_input.getInt32(i, 0);
            tbl_Filter_TD_7991912_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_customer_sk1209_t = tbl_SerializeFromObject_TD_8451563_input.getInt32(i, 1);
            tbl_Filter_TD_7991912_output.setInt32(r, 1, _ss_customer_sk1209_t);
            int32_t _ss_hdemo_sk1211_t = tbl_SerializeFromObject_TD_8451563_input.getInt32(i, 2);
            tbl_Filter_TD_7991912_output.setInt32(r, 2, _ss_hdemo_sk1211_t);
            int32_t _ss_store_sk1213_t = tbl_SerializeFromObject_TD_8451563_input.getInt32(i, 3);
            tbl_Filter_TD_7991912_output.setInt32(r, 3, _ss_store_sk1213_t);
            int64_t _ss_ticket_number1215L_t = tbl_SerializeFromObject_TD_8451563_input.getInt64(i, 4);
            tbl_Filter_TD_7991912_output.setInt64(r, 4, _ss_ticket_number1215L_t);
            r++;
        }
    }
    tbl_Filter_TD_7991912_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7991912_output #Row: " << tbl_Filter_TD_7991912_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6377917(Table &tbl_SerializeFromObject_TD_7752946_input, Table &tbl_Filter_TD_6377917_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(s_county#401) AND (s_county#401 = Williamson County)) AND isnotnull(s_store_sk#378)))
    // Input: ListBuffer(s_store_sk#378, s_county#401)
    // Output: ListBuffer(s_store_sk#378)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7752946_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_county401 = tbl_SerializeFromObject_TD_7752946_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _s_store_sk378 = tbl_SerializeFromObject_TD_7752946_input.getInt32(i, 0);
        if ((_s_county401.data() != "NULL" && (std::string(_s_county401.data()) == "Williamson County")) && (_s_store_sk378!= 0)) {
            int32_t _s_store_sk378_t = tbl_SerializeFromObject_TD_7752946_input.getInt32(i, 0);
            tbl_Filter_TD_6377917_output.setInt32(r, 0, _s_store_sk378_t);
            r++;
        }
    }
    tbl_Filter_TD_6377917_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6377917_output #Row: " << tbl_Filter_TD_6377917_output.getNumRow() << std::endl;
}


void SW_Filter_TD_5615967(Table &tbl_SerializeFromObject_TD_6894735_input, Table &tbl_Filter_TD_5615967_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(hd_vehicle_count#208) AND isnotnull(hd_dep_count#207)) AND ((((hd_buy_potential#206 = >10000) OR (hd_buy_potential#206 = unknown)) AND (hd_vehicle_count#208 > 0)) AND ((cast(hd_dep_count#207 as double) / cast(hd_vehicle_count#208 as double)) > 1.2))) AND isnotnull(hd_demo_sk#204)))
    // Input: ListBuffer(hd_demo_sk#204, hd_vehicle_count#208, hd_dep_count#207, hd_buy_potential#206)
    // Output: ListBuffer(hd_demo_sk#204)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6894735_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _hd_vehicle_count208 = tbl_SerializeFromObject_TD_6894735_input.getInt32(i, 1);
        int32_t _hd_dep_count207 = tbl_SerializeFromObject_TD_6894735_input.getInt32(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _hd_buy_potential206 = tbl_SerializeFromObject_TD_6894735_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        int32_t _hd_demo_sk204 = tbl_SerializeFromObject_TD_6894735_input.getInt32(i, 0);
        if ((((_hd_vehicle_count208!= 0) && (_hd_dep_count207!= 0)) && ((((std::string(_hd_buy_potential206.data()) == ">10000") || (std::string(_hd_buy_potential206.data()) == "unknown")) && (_hd_vehicle_count208 > 0)) && (_hd_dep_count207 > 1.2))) && (_hd_demo_sk204!= 0)) {
            int32_t _hd_demo_sk204_t = tbl_SerializeFromObject_TD_6894735_input.getInt32(i, 0);
            tbl_Filter_TD_5615967_output.setInt32(r, 0, _hd_demo_sk204_t);
            r++;
        }
    }
    tbl_Filter_TD_5615967_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5615967_output #Row: " << tbl_Filter_TD_5615967_output.getNumRow() << std::endl;
}



void SW_Aggregate_TD_3550962_consolidate(Table &tbl_Aggregate_TD_3550962_output_preprocess, Table &tbl_Aggregate_TD_3550962_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_3550962_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _ss_ticket_number1215L = tbl_Aggregate_TD_3550962_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_3550962_output.setInt32(r, 0, _ss_ticket_number1215L);
        int32_t _ss_customer_sk1209 = tbl_Aggregate_TD_3550962_output_preprocess.getInt32(r, 6);
        tbl_Aggregate_TD_3550962_output.setInt32(r, 1, _ss_customer_sk1209);
        int32_t _cnt3544L = tbl_Aggregate_TD_3550962_output_preprocess.getInt32(r, 0);
        tbl_Aggregate_TD_3550962_output.setInt32(r, 2, _cnt3544L);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_3550962_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_3550962_output #Row: " << tbl_Aggregate_TD_3550962_output.getNumRow() << std::endl;
}

void SW_Filter_TD_2279980(Table &tbl_SerializeFromObject_TD_341779_input, Table &tbl_Filter_TD_2279980_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(c_customer_sk#0))
    // Input: ListBuffer(c_customer_sk#0, c_salutation#7, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10)
    // Output: ListBuffer(c_customer_sk#0, c_salutation#7, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_341779_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk0 = tbl_SerializeFromObject_TD_341779_input.getInt32(i, 0);
        if (_c_customer_sk0!= 0) {
            int32_t _c_customer_sk0_t = tbl_SerializeFromObject_TD_341779_input.getInt32(i, 0);
            tbl_Filter_TD_2279980_output.setInt32(r, 0, _c_customer_sk0_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_salutation7_t = tbl_SerializeFromObject_TD_341779_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_2279980_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_salutation7_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_t = tbl_SerializeFromObject_TD_341779_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_2279980_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name8_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_t = tbl_SerializeFromObject_TD_341779_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_2279980_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name9_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_t = tbl_SerializeFromObject_TD_341779_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            tbl_Filter_TD_2279980_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_preferred_cust_flag10_t);
            r++;
        }
    }
    tbl_Filter_TD_2279980_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2279980_output #Row: " << tbl_Filter_TD_2279980_output.getNumRow() << std::endl;
}

void SW_Filter_TD_2684058(Table &tbl_Aggregate_TD_3550962_output, Table &tbl_Filter_TD_2684058_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((cnt#3544L >= 15) AND (cnt#3544L <= 20)))
    // Input: ListBuffer(ss_ticket_number#1215L, ss_customer_sk#1209, cnt#3544L)
    // Output: ListBuffer(ss_ticket_number#1215L, ss_customer_sk#1209, cnt#3544L)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_3550962_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _cnt3544L = tbl_Aggregate_TD_3550962_output.getInt64(i, 2);
        if ((_cnt3544L >= 15) && (_cnt3544L <= 20)) {
            int64_t _ss_ticket_number1215L_t = tbl_Aggregate_TD_3550962_output.getInt64(i, 0);
            tbl_Filter_TD_2684058_output.setInt64(r, 0, _ss_ticket_number1215L_t);
            int32_t _ss_customer_sk1209_t = tbl_Aggregate_TD_3550962_output.getInt32(i, 1);
            tbl_Filter_TD_2684058_output.setInt32(r, 1, _ss_customer_sk1209_t);
            int64_t _cnt3544L_t = tbl_Aggregate_TD_3550962_output.getInt64(i, 2);
            tbl_Filter_TD_2684058_output.setInt64(r, 2, _cnt3544L_t);
            r++;
        }
    }
    tbl_Filter_TD_2684058_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2684058_output #Row: " << tbl_Filter_TD_2684058_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_1289093_key_leftMajor {
    int32_t _ss_customer_sk1209;
    bool operator==(const SW_JOIN_INNER_TD_1289093_key_leftMajor& other) const {
        return ((_ss_customer_sk1209 == other._ss_customer_sk1209));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_1289093_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_1289093_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_customer_sk1209));
    }
};
}
struct SW_JOIN_INNER_TD_1289093_payload_leftMajor {
    int64_t _ss_ticket_number1215L;
    int32_t _ss_customer_sk1209;
    int64_t _cnt3544L;
};
struct SW_JOIN_INNER_TD_1289093_key_rightMajor {
    int32_t _c_customer_sk0;
    bool operator==(const SW_JOIN_INNER_TD_1289093_key_rightMajor& other) const {
        return ((_c_customer_sk0 == other._c_customer_sk0));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_1289093_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_1289093_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk0));
    }
};
}
struct SW_JOIN_INNER_TD_1289093_payload_rightMajor {
    int32_t _c_customer_sk0;
    std::string _c_salutation7;
    std::string _c_first_name8;
    std::string _c_last_name9;
    std::string _c_preferred_cust_flag10;
};
void SW_JOIN_INNER_TD_1289093(Table &tbl_Filter_TD_2684058_output, Table &tbl_Filter_TD_2279980_output, Table &tbl_JOIN_INNER_TD_1289093_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_customer_sk#1209 = c_customer_sk#0))
    // Left Table: ListBuffer(ss_ticket_number#1215L, ss_customer_sk#1209, cnt#3544L)
    // Right Table: ListBuffer(c_customer_sk#0, c_salutation#7, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10)
    // Output Table: ListBuffer(c_last_name#9, c_first_name#8, c_salutation#7, c_preferred_cust_flag#10, ss_ticket_number#1215L, cnt#3544L)
    int left_nrow = tbl_Filter_TD_2684058_output.getNumRow();
    int right_nrow = tbl_Filter_TD_2279980_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_1289093_key_leftMajor, SW_JOIN_INNER_TD_1289093_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_2684058_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_customer_sk1209_k = tbl_Filter_TD_2684058_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_1289093_key_leftMajor keyA{_ss_customer_sk1209_k};
            int64_t _ss_ticket_number1215L = tbl_Filter_TD_2684058_output.getInt64(i, 0);
            int32_t _ss_customer_sk1209 = tbl_Filter_TD_2684058_output.getInt32(i, 1);
            int64_t _cnt3544L = tbl_Filter_TD_2684058_output.getInt64(i, 2);
            SW_JOIN_INNER_TD_1289093_payload_leftMajor payloadA{_ss_ticket_number1215L, _ss_customer_sk1209, _cnt3544L};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_2279980_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_2279980_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_1289093_key_leftMajor{_c_customer_sk0_k});
            auto it = its.first;
            while (it != its.second) {
                int64_t _ss_ticket_number1215L = (it->second)._ss_ticket_number1215L;
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                int64_t _cnt3544L = (it->second)._cnt3544L;
                int32_t _c_customer_sk0 = tbl_Filter_TD_2279980_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_salutation7_n = tbl_Filter_TD_2279980_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_salutation7 = std::string(_c_salutation7_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_Filter_TD_2279980_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_first_name8 = std::string(_c_first_name8_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_Filter_TD_2279980_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_last_name9 = std::string(_c_last_name9_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_n = tbl_Filter_TD_2279980_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_preferred_cust_flag10 = std::string(_c_preferred_cust_flag10_n.data());
                tbl_JOIN_INNER_TD_1289093_output.setInt64(r, 4, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_1289093_output.setInt64(r, 5, _cnt3544L);
                tbl_JOIN_INNER_TD_1289093_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_salutation7_n);
                tbl_JOIN_INNER_TD_1289093_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
                tbl_JOIN_INNER_TD_1289093_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name9_n);
                tbl_JOIN_INNER_TD_1289093_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag10_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_1289093_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_1289093_key_rightMajor, SW_JOIN_INNER_TD_1289093_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_2279980_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_2279980_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_1289093_key_rightMajor keyA{_c_customer_sk0_k};
            int32_t _c_customer_sk0 = tbl_Filter_TD_2279980_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _c_salutation7_n = tbl_Filter_TD_2279980_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_salutation7 = std::string(_c_salutation7_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_Filter_TD_2279980_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_first_name8 = std::string(_c_first_name8_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_Filter_TD_2279980_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_last_name9 = std::string(_c_last_name9_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_n = tbl_Filter_TD_2279980_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_preferred_cust_flag10 = std::string(_c_preferred_cust_flag10_n.data());
            SW_JOIN_INNER_TD_1289093_payload_rightMajor payloadA{_c_customer_sk0, _c_salutation7, _c_first_name8, _c_last_name9, _c_preferred_cust_flag10};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_2684058_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_customer_sk1209_k = tbl_Filter_TD_2684058_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_1289093_key_rightMajor{_ss_customer_sk1209_k});
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
                int64_t _ss_ticket_number1215L = tbl_Filter_TD_2684058_output.getInt64(i, 0);
                int32_t _ss_customer_sk1209 = tbl_Filter_TD_2684058_output.getInt32(i, 1);
                int64_t _cnt3544L = tbl_Filter_TD_2684058_output.getInt64(i, 2);
                tbl_JOIN_INNER_TD_1289093_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_salutation7_n);
                tbl_JOIN_INNER_TD_1289093_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
                tbl_JOIN_INNER_TD_1289093_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name9_n);
                tbl_JOIN_INNER_TD_1289093_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag10_n);
                tbl_JOIN_INNER_TD_1289093_output.setInt64(r, 4, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_1289093_output.setInt64(r, 5, _cnt3544L);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_1289093_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_1289093_output #Row: " << tbl_JOIN_INNER_TD_1289093_output.getNumRow() << std::endl;
}

void SW_Sort_TD_0679127(Table &tbl_JOIN_INNER_TD_1289093_output, Table &tbl_Sort_TD_0679127_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(c_last_name#9 ASC NULLS FIRST, c_first_name#8 ASC NULLS FIRST, c_salutation#7 ASC NULLS FIRST, c_preferred_cust_flag#10 DESC NULLS LAST, ss_ticket_number#1215L ASC NULLS FIRST)
    // Input: ListBuffer(c_last_name#9, c_first_name#8, c_salutation#7, c_preferred_cust_flag#10, ss_ticket_number#1215L, cnt#3544L)
    // Output: ListBuffer(c_last_name#9, c_first_name#8, c_salutation#7, c_preferred_cust_flag#10, ss_ticket_number#1215L, cnt#3544L)
    struct SW_Sort_TD_0679127Row {
        std::string _c_last_name9;
        std::string _c_first_name8;
        std::string _c_salutation7;
        std::string _c_preferred_cust_flag10;
        int64_t _ss_ticket_number1215L;
        int64_t _cnt3544L;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_0679127Row& a, const SW_Sort_TD_0679127Row& b) const { return 
 (a._c_last_name9 < b._c_last_name9) || 
 ((a._c_last_name9 == b._c_last_name9) && (a._c_first_name8 < b._c_first_name8)) || 
 ((a._c_last_name9 == b._c_last_name9) && (a._c_first_name8 == b._c_first_name8) && (a._c_salutation7 < b._c_salutation7)) || 
 ((a._c_last_name9 == b._c_last_name9) && (a._c_first_name8 == b._c_first_name8) && (a._c_salutation7 == b._c_salutation7) && (a._c_preferred_cust_flag10 > b._c_preferred_cust_flag10)) || 
 ((a._c_last_name9 == b._c_last_name9) && (a._c_first_name8 == b._c_first_name8) && (a._c_salutation7 == b._c_salutation7) && (a._c_preferred_cust_flag10 == b._c_preferred_cust_flag10) && (a._ss_ticket_number1215L < b._ss_ticket_number1215L)); 
}
    }SW_Sort_TD_0679127_order; 

    int nrow1 = tbl_JOIN_INNER_TD_1289093_output.getNumRow();
    std::vector<SW_Sort_TD_0679127Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9 = tbl_JOIN_INNER_TD_1289093_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8 = tbl_JOIN_INNER_TD_1289093_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _c_salutation7 = tbl_JOIN_INNER_TD_1289093_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10 = tbl_JOIN_INNER_TD_1289093_output.getcharN<char, TPCDS_READ_MAX +1>(i, 3);
        int64_t _ss_ticket_number1215L = tbl_JOIN_INNER_TD_1289093_output.getInt64(i, 4);
        int64_t _cnt3544L = tbl_JOIN_INNER_TD_1289093_output.getInt64(i, 5);
        SW_Sort_TD_0679127Row t = {std::string(_c_last_name9.data()),std::string(_c_first_name8.data()),std::string(_c_salutation7.data()),std::string(_c_preferred_cust_flag10.data()),_ss_ticket_number1215L,_cnt3544L};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_0679127_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9{};
        memcpy(_c_last_name9.data(), (it._c_last_name9).data(), (it._c_last_name9).length());
        tbl_Sort_TD_0679127_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _c_last_name9);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8{};
        memcpy(_c_first_name8.data(), (it._c_first_name8).data(), (it._c_first_name8).length());
        tbl_Sort_TD_0679127_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _c_first_name8);
        std::array<char, TPCDS_READ_MAX + 1> _c_salutation7{};
        memcpy(_c_salutation7.data(), (it._c_salutation7).data(), (it._c_salutation7).length());
        tbl_Sort_TD_0679127_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _c_salutation7);
        std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10{};
        memcpy(_c_preferred_cust_flag10.data(), (it._c_preferred_cust_flag10).data(), (it._c_preferred_cust_flag10).length());
        tbl_Sort_TD_0679127_output.setcharN<char, TPCDS_READ_MAX +1>(r, 3, _c_preferred_cust_flag10);
        tbl_Sort_TD_0679127_output.setInt64(r, 4, it._ss_ticket_number1215L);
        tbl_Sort_TD_0679127_output.setInt64(r, 5, it._cnt3544L);
        if (r < 10) {
            std::cout << (it._c_last_name9).data() << " " << (it._c_first_name8).data() << " " << (it._c_salutation7).data() << " " << (it._c_preferred_cust_flag10).data() << " " << it._ss_ticket_number1215L << " " << it._cnt3544L << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_0679127_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_0679127_output #Row: " << tbl_Sort_TD_0679127_output.getNumRow() << std::endl;
}

