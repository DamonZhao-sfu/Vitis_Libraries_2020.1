#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_10545828(Table &tbl_SerializeFromObject_TD_11744465_input, Table &tbl_Filter_TD_10545828_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_bill_customer_sk#4987) AND isnotnull(ws_sold_date_sk#4983)))
    // Input: ListBuffer(ws_sold_date_sk#4983, ws_bill_customer_sk#4987, ws_ext_discount_amt#5005, ws_ext_list_price#5008)
    // Output: ListBuffer(ws_sold_date_sk#4983, ws_bill_customer_sk#4987, ws_ext_discount_amt#5005, ws_ext_list_price#5008)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11744465_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_bill_customer_sk4987 = tbl_SerializeFromObject_TD_11744465_input.getInt32(i, 1);
        int32_t _ws_sold_date_sk4983 = tbl_SerializeFromObject_TD_11744465_input.getInt32(i, 0);
        if ((_ws_bill_customer_sk4987!= 0) && (_ws_sold_date_sk4983!= 0)) {
            int32_t _ws_sold_date_sk4983_t = tbl_SerializeFromObject_TD_11744465_input.getInt32(i, 0);
            tbl_Filter_TD_10545828_output.setInt32(r, 0, _ws_sold_date_sk4983_t);
            int32_t _ws_bill_customer_sk4987_t = tbl_SerializeFromObject_TD_11744465_input.getInt32(i, 1);
            tbl_Filter_TD_10545828_output.setInt32(r, 1, _ws_bill_customer_sk4987_t);
            int64_t _ws_ext_discount_amt5005_t = tbl_SerializeFromObject_TD_11744465_input.getInt64(i, 2);
            tbl_Filter_TD_10545828_output.setInt64(r, 2, _ws_ext_discount_amt5005_t);
            int64_t _ws_ext_list_price5008_t = tbl_SerializeFromObject_TD_11744465_input.getInt64(i, 3);
            tbl_Filter_TD_10545828_output.setInt64(r, 3, _ws_ext_list_price5008_t);
            r++;
        }
    }
    tbl_Filter_TD_10545828_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10545828_output #Row: " << tbl_Filter_TD_10545828_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10973120(Table &tbl_SerializeFromObject_TD_11986773_input, Table &tbl_Filter_TD_10973120_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(c_customer_sk#4965) AND isnotnull(c_customer_id#4966)))
    // Input: ListBuffer(c_customer_sk#4965, c_customer_id#4966, c_first_name#4973, c_last_name#4974, c_preferred_cust_flag#4975, c_birth_country#4979, c_login#4980, c_email_address#4981)
    // Output: ListBuffer(c_customer_sk#4965, c_customer_id#4966, c_first_name#4973, c_last_name#4974, c_preferred_cust_flag#4975, c_birth_country#4979, c_login#4980, c_email_address#4981)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11986773_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk4965 = tbl_SerializeFromObject_TD_11986773_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id4966 = tbl_SerializeFromObject_TD_11986773_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_c_customer_sk4965!= 0) && _c_customer_id4966.data() != "NULL") {
            int32_t _c_customer_sk4965_t = tbl_SerializeFromObject_TD_11986773_input.getInt32(i, 0);
            tbl_Filter_TD_10973120_output.setInt32(r, 0, _c_customer_sk4965_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id4966_t = tbl_SerializeFromObject_TD_11986773_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_10973120_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_customer_id4966_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name4973_t = tbl_SerializeFromObject_TD_11986773_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_10973120_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name4973_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name4974_t = tbl_SerializeFromObject_TD_11986773_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_10973120_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name4974_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag4975_t = tbl_SerializeFromObject_TD_11986773_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            tbl_Filter_TD_10973120_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_preferred_cust_flag4975_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country4979_t = tbl_SerializeFromObject_TD_11986773_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            tbl_Filter_TD_10973120_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_birth_country4979_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_login4980_t = tbl_SerializeFromObject_TD_11986773_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            tbl_Filter_TD_10973120_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_login4980_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address4981_t = tbl_SerializeFromObject_TD_11986773_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            tbl_Filter_TD_10973120_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _c_email_address4981_t);
            r++;
        }
    }
    tbl_Filter_TD_10973120_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10973120_output #Row: " << tbl_Filter_TD_10973120_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10519755(Table &tbl_SerializeFromObject_TD_1155822_input, Table &tbl_Filter_TD_10519755_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_customer_sk#1209) AND isnotnull(ss_sold_date_sk#1206)))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_customer_sk#1209, ss_ext_discount_amt#1220, ss_ext_list_price#1223)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_customer_sk#1209, ss_ext_discount_amt#1220, ss_ext_list_price#1223)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1155822_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_customer_sk1209 = tbl_SerializeFromObject_TD_1155822_input.getInt32(i, 1);
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_1155822_input.getInt32(i, 0);
        if ((_ss_customer_sk1209!= 0) && (_ss_sold_date_sk1206!= 0)) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_1155822_input.getInt32(i, 0);
            tbl_Filter_TD_10519755_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_customer_sk1209_t = tbl_SerializeFromObject_TD_1155822_input.getInt32(i, 1);
            tbl_Filter_TD_10519755_output.setInt32(r, 1, _ss_customer_sk1209_t);
            int64_t _ss_ext_discount_amt1220_t = tbl_SerializeFromObject_TD_1155822_input.getInt64(i, 2);
            tbl_Filter_TD_10519755_output.setInt64(r, 2, _ss_ext_discount_amt1220_t);
            int64_t _ss_ext_list_price1223_t = tbl_SerializeFromObject_TD_1155822_input.getInt64(i, 3);
            tbl_Filter_TD_10519755_output.setInt64(r, 3, _ss_ext_list_price1223_t);
            r++;
        }
    }
    tbl_Filter_TD_10519755_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10519755_output #Row: " << tbl_Filter_TD_10519755_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10622175(Table &tbl_SerializeFromObject_TD_11930203_input, Table &tbl_Filter_TD_10622175_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(c_customer_sk#0) AND isnotnull(c_customer_id#1)))
    // Input: ListBuffer(c_customer_sk#0, c_customer_id#1, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_country#14, c_login#15, c_email_address#16)
    // Output: ListBuffer(c_customer_sk#0, c_customer_id#1, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_country#14, c_login#15, c_email_address#16)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11930203_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk0 = tbl_SerializeFromObject_TD_11930203_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1 = tbl_SerializeFromObject_TD_11930203_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_c_customer_sk0!= 0) && _c_customer_id1.data() != "NULL") {
            int32_t _c_customer_sk0_t = tbl_SerializeFromObject_TD_11930203_input.getInt32(i, 0);
            tbl_Filter_TD_10622175_output.setInt32(r, 0, _c_customer_sk0_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_t = tbl_SerializeFromObject_TD_11930203_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_10622175_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_customer_id1_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_t = tbl_SerializeFromObject_TD_11930203_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_10622175_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name8_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_t = tbl_SerializeFromObject_TD_11930203_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_10622175_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name9_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_t = tbl_SerializeFromObject_TD_11930203_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            tbl_Filter_TD_10622175_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_preferred_cust_flag10_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country14_t = tbl_SerializeFromObject_TD_11930203_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            tbl_Filter_TD_10622175_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_birth_country14_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_login15_t = tbl_SerializeFromObject_TD_11930203_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            tbl_Filter_TD_10622175_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_login15_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address16_t = tbl_SerializeFromObject_TD_11930203_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            tbl_Filter_TD_10622175_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _c_email_address16_t);
            r++;
        }
    }
    tbl_Filter_TD_10622175_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10622175_output #Row: " << tbl_Filter_TD_10622175_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9817279(Table &tbl_SerializeFromObject_TD_10382272_input, Table &tbl_Filter_TD_9817279_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#5023) AND (d_year#5023 = 2001)) AND isnotnull(d_date_sk#5017)))
    // Input: ListBuffer(d_date_sk#5017, d_year#5023)
    // Output: ListBuffer(d_date_sk#5017, d_year#5023)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10382272_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year5023 = tbl_SerializeFromObject_TD_10382272_input.getInt32(i, 1);
        int32_t _d_date_sk5017 = tbl_SerializeFromObject_TD_10382272_input.getInt32(i, 0);
        if (((_d_year5023!= 0) && (_d_year5023 == 2001)) && (_d_date_sk5017!= 0)) {
            int32_t _d_date_sk5017_t = tbl_SerializeFromObject_TD_10382272_input.getInt32(i, 0);
            tbl_Filter_TD_9817279_output.setInt32(r, 0, _d_date_sk5017_t);
            int32_t _d_year5023_t = tbl_SerializeFromObject_TD_10382272_input.getInt32(i, 1);
            tbl_Filter_TD_9817279_output.setInt32(r, 1, _d_year5023_t);
            r++;
        }
    }
    tbl_Filter_TD_9817279_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9817279_output #Row: " << tbl_Filter_TD_9817279_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_9216480_key_leftMajor {
    int32_t _c_customer_sk4965;
    bool operator==(const SW_JOIN_INNER_TD_9216480_key_leftMajor& other) const {
        return ((_c_customer_sk4965 == other._c_customer_sk4965));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9216480_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9216480_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk4965));
    }
};
}
struct SW_JOIN_INNER_TD_9216480_payload_leftMajor {
    int32_t _c_customer_sk4965;
    std::string _c_customer_id4966;
    std::string _c_first_name4973;
    std::string _c_last_name4974;
    std::string _c_preferred_cust_flag4975;
    std::string _c_birth_country4979;
    std::string _c_login4980;
    std::string _c_email_address4981;
};
struct SW_JOIN_INNER_TD_9216480_key_rightMajor {
    int32_t _ws_bill_customer_sk4987;
    bool operator==(const SW_JOIN_INNER_TD_9216480_key_rightMajor& other) const {
        return ((_ws_bill_customer_sk4987 == other._ws_bill_customer_sk4987));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9216480_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9216480_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_bill_customer_sk4987));
    }
};
}
struct SW_JOIN_INNER_TD_9216480_payload_rightMajor {
    int32_t _ws_sold_date_sk4983;
    int32_t _ws_bill_customer_sk4987;
    int64_t _ws_ext_discount_amt5005;
    int64_t _ws_ext_list_price5008;
};
void SW_JOIN_INNER_TD_9216480(Table &tbl_Filter_TD_10973120_output, Table &tbl_Filter_TD_10545828_output, Table &tbl_JOIN_INNER_TD_9216480_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((c_customer_sk#4965 = ws_bill_customer_sk#4987))
    // Left Table: ListBuffer(c_customer_sk#4965, c_customer_id#4966, c_first_name#4973, c_last_name#4974, c_preferred_cust_flag#4975, c_birth_country#4979, c_login#4980, c_email_address#4981)
    // Right Table: ListBuffer(ws_sold_date_sk#4983, ws_bill_customer_sk#4987, ws_ext_discount_amt#5005, ws_ext_list_price#5008)
    // Output Table: ListBuffer(c_customer_id#4966, c_first_name#4973, c_last_name#4974, c_preferred_cust_flag#4975, c_birth_country#4979, c_login#4980, c_email_address#4981, ws_sold_date_sk#4983, ws_ext_discount_amt#5005, ws_ext_list_price#5008)
    int left_nrow = tbl_Filter_TD_10973120_output.getNumRow();
    int right_nrow = tbl_Filter_TD_10545828_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9216480_key_leftMajor, SW_JOIN_INNER_TD_9216480_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_10973120_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk4965_k = tbl_Filter_TD_10973120_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_9216480_key_leftMajor keyA{_c_customer_sk4965_k};
            int32_t _c_customer_sk4965 = tbl_Filter_TD_10973120_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id4966_n = tbl_Filter_TD_10973120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_customer_id4966 = std::string(_c_customer_id4966_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name4973_n = tbl_Filter_TD_10973120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_first_name4973 = std::string(_c_first_name4973_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name4974_n = tbl_Filter_TD_10973120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_last_name4974 = std::string(_c_last_name4974_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag4975_n = tbl_Filter_TD_10973120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_preferred_cust_flag4975 = std::string(_c_preferred_cust_flag4975_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country4979_n = tbl_Filter_TD_10973120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _c_birth_country4979 = std::string(_c_birth_country4979_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_login4980_n = tbl_Filter_TD_10973120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _c_login4980 = std::string(_c_login4980_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address4981_n = tbl_Filter_TD_10973120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _c_email_address4981 = std::string(_c_email_address4981_n.data());
            SW_JOIN_INNER_TD_9216480_payload_leftMajor payloadA{_c_customer_sk4965, _c_customer_id4966, _c_first_name4973, _c_last_name4974, _c_preferred_cust_flag4975, _c_birth_country4979, _c_login4980, _c_email_address4981};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_10545828_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_bill_customer_sk4987_k = tbl_Filter_TD_10545828_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9216480_key_leftMajor{_ws_bill_customer_sk4987_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk4965 = (it->second)._c_customer_sk4965;
                std::string _c_customer_id4966 = (it->second)._c_customer_id4966;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id4966_n{};
                memcpy(_c_customer_id4966_n.data(), (_c_customer_id4966).data(), (_c_customer_id4966).length());
                std::string _c_first_name4973 = (it->second)._c_first_name4973;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name4973_n{};
                memcpy(_c_first_name4973_n.data(), (_c_first_name4973).data(), (_c_first_name4973).length());
                std::string _c_last_name4974 = (it->second)._c_last_name4974;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name4974_n{};
                memcpy(_c_last_name4974_n.data(), (_c_last_name4974).data(), (_c_last_name4974).length());
                std::string _c_preferred_cust_flag4975 = (it->second)._c_preferred_cust_flag4975;
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag4975_n{};
                memcpy(_c_preferred_cust_flag4975_n.data(), (_c_preferred_cust_flag4975).data(), (_c_preferred_cust_flag4975).length());
                std::string _c_birth_country4979 = (it->second)._c_birth_country4979;
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country4979_n{};
                memcpy(_c_birth_country4979_n.data(), (_c_birth_country4979).data(), (_c_birth_country4979).length());
                std::string _c_login4980 = (it->second)._c_login4980;
                std::array<char, TPCDS_READ_MAX + 1> _c_login4980_n{};
                memcpy(_c_login4980_n.data(), (_c_login4980).data(), (_c_login4980).length());
                std::string _c_email_address4981 = (it->second)._c_email_address4981;
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address4981_n{};
                memcpy(_c_email_address4981_n.data(), (_c_email_address4981).data(), (_c_email_address4981).length());
                int32_t _ws_sold_date_sk4983 = tbl_Filter_TD_10545828_output.getInt32(i, 0);
                int32_t _ws_bill_customer_sk4987 = tbl_Filter_TD_10545828_output.getInt32(i, 1);
                int64_t _ws_ext_discount_amt5005 = tbl_Filter_TD_10545828_output.getInt64(i, 2);
                int64_t _ws_ext_list_price5008 = tbl_Filter_TD_10545828_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_9216480_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id4966_n);
                tbl_JOIN_INNER_TD_9216480_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name4973_n);
                tbl_JOIN_INNER_TD_9216480_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name4974_n);
                tbl_JOIN_INNER_TD_9216480_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag4975_n);
                tbl_JOIN_INNER_TD_9216480_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country4979_n);
                tbl_JOIN_INNER_TD_9216480_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login4980_n);
                tbl_JOIN_INNER_TD_9216480_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address4981_n);
                tbl_JOIN_INNER_TD_9216480_output.setInt32(r, 7, _ws_sold_date_sk4983);
                tbl_JOIN_INNER_TD_9216480_output.setInt64(r, 8, _ws_ext_discount_amt5005);
                tbl_JOIN_INNER_TD_9216480_output.setInt64(r, 9, _ws_ext_list_price5008);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9216480_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9216480_key_rightMajor, SW_JOIN_INNER_TD_9216480_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_10545828_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_bill_customer_sk4987_k = tbl_Filter_TD_10545828_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_9216480_key_rightMajor keyA{_ws_bill_customer_sk4987_k};
            int32_t _ws_sold_date_sk4983 = tbl_Filter_TD_10545828_output.getInt32(i, 0);
            int32_t _ws_bill_customer_sk4987 = tbl_Filter_TD_10545828_output.getInt32(i, 1);
            int64_t _ws_ext_discount_amt5005 = tbl_Filter_TD_10545828_output.getInt64(i, 2);
            int64_t _ws_ext_list_price5008 = tbl_Filter_TD_10545828_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_9216480_payload_rightMajor payloadA{_ws_sold_date_sk4983, _ws_bill_customer_sk4987, _ws_ext_discount_amt5005, _ws_ext_list_price5008};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_10973120_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk4965_k = tbl_Filter_TD_10973120_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9216480_key_rightMajor{_c_customer_sk4965_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_date_sk4983 = (it->second)._ws_sold_date_sk4983;
                int32_t _ws_bill_customer_sk4987 = (it->second)._ws_bill_customer_sk4987;
                int64_t _ws_ext_discount_amt5005 = (it->second)._ws_ext_discount_amt5005;
                int64_t _ws_ext_list_price5008 = (it->second)._ws_ext_list_price5008;
                int32_t _c_customer_sk4965 = tbl_Filter_TD_10973120_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id4966_n = tbl_Filter_TD_10973120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_customer_id4966 = std::string(_c_customer_id4966_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name4973_n = tbl_Filter_TD_10973120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_first_name4973 = std::string(_c_first_name4973_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name4974_n = tbl_Filter_TD_10973120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_last_name4974 = std::string(_c_last_name4974_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag4975_n = tbl_Filter_TD_10973120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_preferred_cust_flag4975 = std::string(_c_preferred_cust_flag4975_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country4979_n = tbl_Filter_TD_10973120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _c_birth_country4979 = std::string(_c_birth_country4979_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_login4980_n = tbl_Filter_TD_10973120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _c_login4980 = std::string(_c_login4980_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address4981_n = tbl_Filter_TD_10973120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _c_email_address4981 = std::string(_c_email_address4981_n.data());
                tbl_JOIN_INNER_TD_9216480_output.setInt32(r, 7, _ws_sold_date_sk4983);
                tbl_JOIN_INNER_TD_9216480_output.setInt64(r, 8, _ws_ext_discount_amt5005);
                tbl_JOIN_INNER_TD_9216480_output.setInt64(r, 9, _ws_ext_list_price5008);
                tbl_JOIN_INNER_TD_9216480_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id4966_n);
                tbl_JOIN_INNER_TD_9216480_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name4973_n);
                tbl_JOIN_INNER_TD_9216480_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name4974_n);
                tbl_JOIN_INNER_TD_9216480_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag4975_n);
                tbl_JOIN_INNER_TD_9216480_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country4979_n);
                tbl_JOIN_INNER_TD_9216480_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login4980_n);
                tbl_JOIN_INNER_TD_9216480_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address4981_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9216480_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_9216480_output #Row: " << tbl_JOIN_INNER_TD_9216480_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9426441(Table &tbl_SerializeFromObject_TD_10409304_input, Table &tbl_Filter_TD_9426441_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_customer_sk#4758) AND isnotnull(ss_sold_date_sk#4755)))
    // Input: ListBuffer(ss_sold_date_sk#4755, ss_customer_sk#4758, ss_ext_discount_amt#4769, ss_ext_list_price#4772)
    // Output: ListBuffer(ss_sold_date_sk#4755, ss_customer_sk#4758, ss_ext_discount_amt#4769, ss_ext_list_price#4772)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10409304_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_customer_sk4758 = tbl_SerializeFromObject_TD_10409304_input.getInt32(i, 1);
        int32_t _ss_sold_date_sk4755 = tbl_SerializeFromObject_TD_10409304_input.getInt32(i, 0);
        if ((_ss_customer_sk4758!= 0) && (_ss_sold_date_sk4755!= 0)) {
            int32_t _ss_sold_date_sk4755_t = tbl_SerializeFromObject_TD_10409304_input.getInt32(i, 0);
            tbl_Filter_TD_9426441_output.setInt32(r, 0, _ss_sold_date_sk4755_t);
            int32_t _ss_customer_sk4758_t = tbl_SerializeFromObject_TD_10409304_input.getInt32(i, 1);
            tbl_Filter_TD_9426441_output.setInt32(r, 1, _ss_customer_sk4758_t);
            int64_t _ss_ext_discount_amt4769_t = tbl_SerializeFromObject_TD_10409304_input.getInt64(i, 2);
            tbl_Filter_TD_9426441_output.setInt64(r, 2, _ss_ext_discount_amt4769_t);
            int64_t _ss_ext_list_price4772_t = tbl_SerializeFromObject_TD_10409304_input.getInt64(i, 3);
            tbl_Filter_TD_9426441_output.setInt64(r, 3, _ss_ext_list_price4772_t);
            r++;
        }
    }
    tbl_Filter_TD_9426441_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9426441_output #Row: " << tbl_Filter_TD_9426441_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9366196(Table &tbl_SerializeFromObject_TD_10366823_input, Table &tbl_Filter_TD_9366196_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(c_customer_sk#4737) AND isnotnull(c_customer_id#4738)))
    // Input: ListBuffer(c_customer_sk#4737, c_customer_id#4738, c_first_name#4745, c_last_name#4746, c_preferred_cust_flag#4747, c_birth_country#4751, c_login#4752, c_email_address#4753)
    // Output: ListBuffer(c_customer_sk#4737, c_customer_id#4738, c_first_name#4745, c_last_name#4746, c_preferred_cust_flag#4747, c_birth_country#4751, c_login#4752, c_email_address#4753)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10366823_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk4737 = tbl_SerializeFromObject_TD_10366823_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id4738 = tbl_SerializeFromObject_TD_10366823_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_c_customer_sk4737!= 0) && _c_customer_id4738.data() != "NULL") {
            int32_t _c_customer_sk4737_t = tbl_SerializeFromObject_TD_10366823_input.getInt32(i, 0);
            tbl_Filter_TD_9366196_output.setInt32(r, 0, _c_customer_sk4737_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id4738_t = tbl_SerializeFromObject_TD_10366823_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_9366196_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_customer_id4738_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name4745_t = tbl_SerializeFromObject_TD_10366823_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_9366196_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name4745_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name4746_t = tbl_SerializeFromObject_TD_10366823_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_9366196_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name4746_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag4747_t = tbl_SerializeFromObject_TD_10366823_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            tbl_Filter_TD_9366196_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_preferred_cust_flag4747_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country4751_t = tbl_SerializeFromObject_TD_10366823_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            tbl_Filter_TD_9366196_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_birth_country4751_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_login4752_t = tbl_SerializeFromObject_TD_10366823_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            tbl_Filter_TD_9366196_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_login4752_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address4753_t = tbl_SerializeFromObject_TD_10366823_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            tbl_Filter_TD_9366196_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _c_email_address4753_t);
            r++;
        }
    }
    tbl_Filter_TD_9366196_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9366196_output #Row: " << tbl_Filter_TD_9366196_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9254929(Table &tbl_SerializeFromObject_TD_10905710_input, Table &tbl_Filter_TD_9254929_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#126) AND (d_year#126 = 2001)) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126)
    // Output: ListBuffer(d_date_sk#120, d_year#126)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10905710_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_10905710_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_10905710_input.getInt32(i, 0);
        if (((_d_year126!= 0) && (_d_year126 == 2001)) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_10905710_input.getInt32(i, 0);
            tbl_Filter_TD_9254929_output.setInt32(r, 0, _d_date_sk120_t);
            int32_t _d_year126_t = tbl_SerializeFromObject_TD_10905710_input.getInt32(i, 1);
            tbl_Filter_TD_9254929_output.setInt32(r, 1, _d_year126_t);
            r++;
        }
    }
    tbl_Filter_TD_9254929_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9254929_output #Row: " << tbl_Filter_TD_9254929_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_9611703_key_leftMajor {
    int32_t _c_customer_sk0;
    bool operator==(const SW_JOIN_INNER_TD_9611703_key_leftMajor& other) const {
        return ((_c_customer_sk0 == other._c_customer_sk0));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9611703_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9611703_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk0));
    }
};
}
struct SW_JOIN_INNER_TD_9611703_payload_leftMajor {
    int32_t _c_customer_sk0;
    std::string _c_customer_id1;
    std::string _c_first_name8;
    std::string _c_last_name9;
    std::string _c_preferred_cust_flag10;
    std::string _c_birth_country14;
    std::string _c_login15;
    std::string _c_email_address16;
};
struct SW_JOIN_INNER_TD_9611703_key_rightMajor {
    int32_t _ss_customer_sk1209;
    bool operator==(const SW_JOIN_INNER_TD_9611703_key_rightMajor& other) const {
        return ((_ss_customer_sk1209 == other._ss_customer_sk1209));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9611703_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9611703_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_customer_sk1209));
    }
};
}
struct SW_JOIN_INNER_TD_9611703_payload_rightMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_customer_sk1209;
    int64_t _ss_ext_discount_amt1220;
    int64_t _ss_ext_list_price1223;
};
void SW_JOIN_INNER_TD_9611703(Table &tbl_Filter_TD_10622175_output, Table &tbl_Filter_TD_10519755_output, Table &tbl_JOIN_INNER_TD_9611703_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((c_customer_sk#0 = ss_customer_sk#1209))
    // Left Table: ListBuffer(c_customer_sk#0, c_customer_id#1, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_country#14, c_login#15, c_email_address#16)
    // Right Table: ListBuffer(ss_sold_date_sk#1206, ss_customer_sk#1209, ss_ext_discount_amt#1220, ss_ext_list_price#1223)
    // Output Table: ListBuffer(c_customer_id#1, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_country#14, c_login#15, c_email_address#16, ss_sold_date_sk#1206, ss_ext_discount_amt#1220, ss_ext_list_price#1223)
    int left_nrow = tbl_Filter_TD_10622175_output.getNumRow();
    int right_nrow = tbl_Filter_TD_10519755_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9611703_key_leftMajor, SW_JOIN_INNER_TD_9611703_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_10622175_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_10622175_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_9611703_key_leftMajor keyA{_c_customer_sk0_k};
            int32_t _c_customer_sk0 = tbl_Filter_TD_10622175_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n = tbl_Filter_TD_10622175_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_customer_id1 = std::string(_c_customer_id1_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_Filter_TD_10622175_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_first_name8 = std::string(_c_first_name8_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_Filter_TD_10622175_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_last_name9 = std::string(_c_last_name9_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_n = tbl_Filter_TD_10622175_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_preferred_cust_flag10 = std::string(_c_preferred_cust_flag10_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country14_n = tbl_Filter_TD_10622175_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _c_birth_country14 = std::string(_c_birth_country14_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_login15_n = tbl_Filter_TD_10622175_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _c_login15 = std::string(_c_login15_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address16_n = tbl_Filter_TD_10622175_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _c_email_address16 = std::string(_c_email_address16_n.data());
            SW_JOIN_INNER_TD_9611703_payload_leftMajor payloadA{_c_customer_sk0, _c_customer_id1, _c_first_name8, _c_last_name9, _c_preferred_cust_flag10, _c_birth_country14, _c_login15, _c_email_address16};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_10519755_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_customer_sk1209_k = tbl_Filter_TD_10519755_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9611703_key_leftMajor{_ss_customer_sk1209_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk0 = (it->second)._c_customer_sk0;
                std::string _c_customer_id1 = (it->second)._c_customer_id1;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n{};
                memcpy(_c_customer_id1_n.data(), (_c_customer_id1).data(), (_c_customer_id1).length());
                std::string _c_first_name8 = (it->second)._c_first_name8;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n{};
                memcpy(_c_first_name8_n.data(), (_c_first_name8).data(), (_c_first_name8).length());
                std::string _c_last_name9 = (it->second)._c_last_name9;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n{};
                memcpy(_c_last_name9_n.data(), (_c_last_name9).data(), (_c_last_name9).length());
                std::string _c_preferred_cust_flag10 = (it->second)._c_preferred_cust_flag10;
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_n{};
                memcpy(_c_preferred_cust_flag10_n.data(), (_c_preferred_cust_flag10).data(), (_c_preferred_cust_flag10).length());
                std::string _c_birth_country14 = (it->second)._c_birth_country14;
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country14_n{};
                memcpy(_c_birth_country14_n.data(), (_c_birth_country14).data(), (_c_birth_country14).length());
                std::string _c_login15 = (it->second)._c_login15;
                std::array<char, TPCDS_READ_MAX + 1> _c_login15_n{};
                memcpy(_c_login15_n.data(), (_c_login15).data(), (_c_login15).length());
                std::string _c_email_address16 = (it->second)._c_email_address16;
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address16_n{};
                memcpy(_c_email_address16_n.data(), (_c_email_address16).data(), (_c_email_address16).length());
                int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_10519755_output.getInt32(i, 0);
                int32_t _ss_customer_sk1209 = tbl_Filter_TD_10519755_output.getInt32(i, 1);
                int64_t _ss_ext_discount_amt1220 = tbl_Filter_TD_10519755_output.getInt64(i, 2);
                int64_t _ss_ext_list_price1223 = tbl_Filter_TD_10519755_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_9611703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id1_n);
                tbl_JOIN_INNER_TD_9611703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
                tbl_JOIN_INNER_TD_9611703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name9_n);
                tbl_JOIN_INNER_TD_9611703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag10_n);
                tbl_JOIN_INNER_TD_9611703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country14_n);
                tbl_JOIN_INNER_TD_9611703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login15_n);
                tbl_JOIN_INNER_TD_9611703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address16_n);
                tbl_JOIN_INNER_TD_9611703_output.setInt32(r, 7, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_9611703_output.setInt64(r, 8, _ss_ext_discount_amt1220);
                tbl_JOIN_INNER_TD_9611703_output.setInt64(r, 9, _ss_ext_list_price1223);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9611703_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9611703_key_rightMajor, SW_JOIN_INNER_TD_9611703_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_10519755_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_customer_sk1209_k = tbl_Filter_TD_10519755_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_9611703_key_rightMajor keyA{_ss_customer_sk1209_k};
            int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_10519755_output.getInt32(i, 0);
            int32_t _ss_customer_sk1209 = tbl_Filter_TD_10519755_output.getInt32(i, 1);
            int64_t _ss_ext_discount_amt1220 = tbl_Filter_TD_10519755_output.getInt64(i, 2);
            int64_t _ss_ext_list_price1223 = tbl_Filter_TD_10519755_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_9611703_payload_rightMajor payloadA{_ss_sold_date_sk1206, _ss_customer_sk1209, _ss_ext_discount_amt1220, _ss_ext_list_price1223};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_10622175_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_10622175_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9611703_key_rightMajor{_c_customer_sk0_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                int64_t _ss_ext_discount_amt1220 = (it->second)._ss_ext_discount_amt1220;
                int64_t _ss_ext_list_price1223 = (it->second)._ss_ext_list_price1223;
                int32_t _c_customer_sk0 = tbl_Filter_TD_10622175_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n = tbl_Filter_TD_10622175_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_customer_id1 = std::string(_c_customer_id1_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_Filter_TD_10622175_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_first_name8 = std::string(_c_first_name8_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_Filter_TD_10622175_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_last_name9 = std::string(_c_last_name9_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_n = tbl_Filter_TD_10622175_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_preferred_cust_flag10 = std::string(_c_preferred_cust_flag10_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country14_n = tbl_Filter_TD_10622175_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _c_birth_country14 = std::string(_c_birth_country14_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_login15_n = tbl_Filter_TD_10622175_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _c_login15 = std::string(_c_login15_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address16_n = tbl_Filter_TD_10622175_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _c_email_address16 = std::string(_c_email_address16_n.data());
                tbl_JOIN_INNER_TD_9611703_output.setInt32(r, 7, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_9611703_output.setInt64(r, 8, _ss_ext_discount_amt1220);
                tbl_JOIN_INNER_TD_9611703_output.setInt64(r, 9, _ss_ext_list_price1223);
                tbl_JOIN_INNER_TD_9611703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id1_n);
                tbl_JOIN_INNER_TD_9611703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
                tbl_JOIN_INNER_TD_9611703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name9_n);
                tbl_JOIN_INNER_TD_9611703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag10_n);
                tbl_JOIN_INNER_TD_9611703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country14_n);
                tbl_JOIN_INNER_TD_9611703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login15_n);
                tbl_JOIN_INNER_TD_9611703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address16_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9611703_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_9611703_output #Row: " << tbl_JOIN_INNER_TD_9611703_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8385547_key_leftMajor {
    int32_t _ws_sold_date_sk4983;
    bool operator==(const SW_JOIN_INNER_TD_8385547_key_leftMajor& other) const {
        return ((_ws_sold_date_sk4983 == other._ws_sold_date_sk4983));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8385547_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8385547_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_sold_date_sk4983));
    }
};
}
struct SW_JOIN_INNER_TD_8385547_payload_leftMajor {
    std::string _c_customer_id4966;
    std::string _c_first_name4973;
    std::string _c_last_name4974;
    std::string _c_preferred_cust_flag4975;
    std::string _c_birth_country4979;
    std::string _c_login4980;
    std::string _c_email_address4981;
    int32_t _ws_sold_date_sk4983;
    int64_t _ws_ext_discount_amt5005;
    int64_t _ws_ext_list_price5008;
};
struct SW_JOIN_INNER_TD_8385547_key_rightMajor {
    int32_t _d_date_sk5017;
    bool operator==(const SW_JOIN_INNER_TD_8385547_key_rightMajor& other) const {
        return ((_d_date_sk5017 == other._d_date_sk5017));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8385547_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8385547_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk5017));
    }
};
}
struct SW_JOIN_INNER_TD_8385547_payload_rightMajor {
    int32_t _d_date_sk5017;
    int32_t _d_year5023;
};
void SW_JOIN_INNER_TD_8385547(Table &tbl_JOIN_INNER_TD_9216480_output, Table &tbl_Filter_TD_9817279_output, Table &tbl_JOIN_INNER_TD_8385547_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_sold_date_sk#4983 = d_date_sk#5017))
    // Left Table: ListBuffer(c_customer_id#4966, c_first_name#4973, c_last_name#4974, c_preferred_cust_flag#4975, c_birth_country#4979, c_login#4980, c_email_address#4981, ws_sold_date_sk#4983, ws_ext_discount_amt#5005, ws_ext_list_price#5008)
    // Right Table: ListBuffer(d_date_sk#5017, d_year#5023)
    // Output Table: ListBuffer(c_customer_id#4966, c_first_name#4973, c_last_name#4974, c_preferred_cust_flag#4975, c_birth_country#4979, c_login#4980, c_email_address#4981, ws_ext_discount_amt#5005, ws_ext_list_price#5008, d_year#5023)
    int left_nrow = tbl_JOIN_INNER_TD_9216480_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9817279_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8385547_key_leftMajor, SW_JOIN_INNER_TD_8385547_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_9216480_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_sold_date_sk4983_k = tbl_JOIN_INNER_TD_9216480_output.getInt32(i, 7);
            SW_JOIN_INNER_TD_8385547_key_leftMajor keyA{_ws_sold_date_sk4983_k};
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id4966_n = tbl_JOIN_INNER_TD_9216480_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _c_customer_id4966 = std::string(_c_customer_id4966_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name4973_n = tbl_JOIN_INNER_TD_9216480_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_first_name4973 = std::string(_c_first_name4973_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name4974_n = tbl_JOIN_INNER_TD_9216480_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_last_name4974 = std::string(_c_last_name4974_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag4975_n = tbl_JOIN_INNER_TD_9216480_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_preferred_cust_flag4975 = std::string(_c_preferred_cust_flag4975_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country4979_n = tbl_JOIN_INNER_TD_9216480_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_birth_country4979 = std::string(_c_birth_country4979_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_login4980_n = tbl_JOIN_INNER_TD_9216480_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _c_login4980 = std::string(_c_login4980_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address4981_n = tbl_JOIN_INNER_TD_9216480_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _c_email_address4981 = std::string(_c_email_address4981_n.data());
            int32_t _ws_sold_date_sk4983 = tbl_JOIN_INNER_TD_9216480_output.getInt32(i, 7);
            int64_t _ws_ext_discount_amt5005 = tbl_JOIN_INNER_TD_9216480_output.getInt64(i, 8);
            int64_t _ws_ext_list_price5008 = tbl_JOIN_INNER_TD_9216480_output.getInt64(i, 9);
            SW_JOIN_INNER_TD_8385547_payload_leftMajor payloadA{_c_customer_id4966, _c_first_name4973, _c_last_name4974, _c_preferred_cust_flag4975, _c_birth_country4979, _c_login4980, _c_email_address4981, _ws_sold_date_sk4983, _ws_ext_discount_amt5005, _ws_ext_list_price5008};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9817279_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk5017_k = tbl_Filter_TD_9817279_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8385547_key_leftMajor{_d_date_sk5017_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _c_customer_id4966 = (it->second)._c_customer_id4966;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id4966_n{};
                memcpy(_c_customer_id4966_n.data(), (_c_customer_id4966).data(), (_c_customer_id4966).length());
                std::string _c_first_name4973 = (it->second)._c_first_name4973;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name4973_n{};
                memcpy(_c_first_name4973_n.data(), (_c_first_name4973).data(), (_c_first_name4973).length());
                std::string _c_last_name4974 = (it->second)._c_last_name4974;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name4974_n{};
                memcpy(_c_last_name4974_n.data(), (_c_last_name4974).data(), (_c_last_name4974).length());
                std::string _c_preferred_cust_flag4975 = (it->second)._c_preferred_cust_flag4975;
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag4975_n{};
                memcpy(_c_preferred_cust_flag4975_n.data(), (_c_preferred_cust_flag4975).data(), (_c_preferred_cust_flag4975).length());
                std::string _c_birth_country4979 = (it->second)._c_birth_country4979;
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country4979_n{};
                memcpy(_c_birth_country4979_n.data(), (_c_birth_country4979).data(), (_c_birth_country4979).length());
                std::string _c_login4980 = (it->second)._c_login4980;
                std::array<char, TPCDS_READ_MAX + 1> _c_login4980_n{};
                memcpy(_c_login4980_n.data(), (_c_login4980).data(), (_c_login4980).length());
                std::string _c_email_address4981 = (it->second)._c_email_address4981;
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address4981_n{};
                memcpy(_c_email_address4981_n.data(), (_c_email_address4981).data(), (_c_email_address4981).length());
                int32_t _ws_sold_date_sk4983 = (it->second)._ws_sold_date_sk4983;
                int64_t _ws_ext_discount_amt5005 = (it->second)._ws_ext_discount_amt5005;
                int64_t _ws_ext_list_price5008 = (it->second)._ws_ext_list_price5008;
                int32_t _d_date_sk5017 = tbl_Filter_TD_9817279_output.getInt32(i, 0);
                int32_t _d_year5023 = tbl_Filter_TD_9817279_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_8385547_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id4966_n);
                tbl_JOIN_INNER_TD_8385547_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name4973_n);
                tbl_JOIN_INNER_TD_8385547_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name4974_n);
                tbl_JOIN_INNER_TD_8385547_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag4975_n);
                tbl_JOIN_INNER_TD_8385547_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country4979_n);
                tbl_JOIN_INNER_TD_8385547_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login4980_n);
                tbl_JOIN_INNER_TD_8385547_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address4981_n);
                tbl_JOIN_INNER_TD_8385547_output.setInt64(r, 7, _ws_ext_discount_amt5005);
                tbl_JOIN_INNER_TD_8385547_output.setInt64(r, 8, _ws_ext_list_price5008);
                tbl_JOIN_INNER_TD_8385547_output.setInt32(r, 9, _d_year5023);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8385547_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8385547_key_rightMajor, SW_JOIN_INNER_TD_8385547_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9817279_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk5017_k = tbl_Filter_TD_9817279_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8385547_key_rightMajor keyA{_d_date_sk5017_k};
            int32_t _d_date_sk5017 = tbl_Filter_TD_9817279_output.getInt32(i, 0);
            int32_t _d_year5023 = tbl_Filter_TD_9817279_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_8385547_payload_rightMajor payloadA{_d_date_sk5017, _d_year5023};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_9216480_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_sold_date_sk4983_k = tbl_JOIN_INNER_TD_9216480_output.getInt32(i, 7);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8385547_key_rightMajor{_ws_sold_date_sk4983_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk5017 = (it->second)._d_date_sk5017;
                int32_t _d_year5023 = (it->second)._d_year5023;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id4966_n = tbl_JOIN_INNER_TD_9216480_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _c_customer_id4966 = std::string(_c_customer_id4966_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name4973_n = tbl_JOIN_INNER_TD_9216480_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_first_name4973 = std::string(_c_first_name4973_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name4974_n = tbl_JOIN_INNER_TD_9216480_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_last_name4974 = std::string(_c_last_name4974_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag4975_n = tbl_JOIN_INNER_TD_9216480_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_preferred_cust_flag4975 = std::string(_c_preferred_cust_flag4975_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country4979_n = tbl_JOIN_INNER_TD_9216480_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_birth_country4979 = std::string(_c_birth_country4979_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_login4980_n = tbl_JOIN_INNER_TD_9216480_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _c_login4980 = std::string(_c_login4980_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address4981_n = tbl_JOIN_INNER_TD_9216480_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _c_email_address4981 = std::string(_c_email_address4981_n.data());
                int32_t _ws_sold_date_sk4983 = tbl_JOIN_INNER_TD_9216480_output.getInt32(i, 7);
                int64_t _ws_ext_discount_amt5005 = tbl_JOIN_INNER_TD_9216480_output.getInt64(i, 8);
                int64_t _ws_ext_list_price5008 = tbl_JOIN_INNER_TD_9216480_output.getInt64(i, 9);
                tbl_JOIN_INNER_TD_8385547_output.setInt32(r, 9, _d_year5023);
                tbl_JOIN_INNER_TD_8385547_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id4966_n);
                tbl_JOIN_INNER_TD_8385547_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name4973_n);
                tbl_JOIN_INNER_TD_8385547_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name4974_n);
                tbl_JOIN_INNER_TD_8385547_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag4975_n);
                tbl_JOIN_INNER_TD_8385547_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country4979_n);
                tbl_JOIN_INNER_TD_8385547_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login4980_n);
                tbl_JOIN_INNER_TD_8385547_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address4981_n);
                tbl_JOIN_INNER_TD_8385547_output.setInt64(r, 7, _ws_ext_discount_amt5005);
                tbl_JOIN_INNER_TD_8385547_output.setInt64(r, 8, _ws_ext_list_price5008);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8385547_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8385547_output #Row: " << tbl_JOIN_INNER_TD_8385547_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8239347(Table &tbl_SerializeFromObject_TD_9552601_input, Table &tbl_Filter_TD_8239347_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#4784) AND (d_year#4784 = 2002)) AND isnotnull(d_date_sk#4778)))
    // Input: ListBuffer(d_date_sk#4778, d_year#4784)
    // Output: ListBuffer(d_date_sk#4778, d_year#4784)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9552601_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year4784 = tbl_SerializeFromObject_TD_9552601_input.getInt32(i, 1);
        int32_t _d_date_sk4778 = tbl_SerializeFromObject_TD_9552601_input.getInt32(i, 0);
        if (((_d_year4784!= 0) && (_d_year4784 == 2002)) && (_d_date_sk4778!= 0)) {
            int32_t _d_date_sk4778_t = tbl_SerializeFromObject_TD_9552601_input.getInt32(i, 0);
            tbl_Filter_TD_8239347_output.setInt32(r, 0, _d_date_sk4778_t);
            int32_t _d_year4784_t = tbl_SerializeFromObject_TD_9552601_input.getInt32(i, 1);
            tbl_Filter_TD_8239347_output.setInt32(r, 1, _d_year4784_t);
            r++;
        }
    }
    tbl_Filter_TD_8239347_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8239347_output #Row: " << tbl_Filter_TD_8239347_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8588445_key_leftMajor {
    int32_t _c_customer_sk4737;
    bool operator==(const SW_JOIN_INNER_TD_8588445_key_leftMajor& other) const {
        return ((_c_customer_sk4737 == other._c_customer_sk4737));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8588445_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8588445_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk4737));
    }
};
}
struct SW_JOIN_INNER_TD_8588445_payload_leftMajor {
    int32_t _c_customer_sk4737;
    std::string _c_customer_id4738;
    std::string _c_first_name4745;
    std::string _c_last_name4746;
    std::string _c_preferred_cust_flag4747;
    std::string _c_birth_country4751;
    std::string _c_login4752;
    std::string _c_email_address4753;
};
struct SW_JOIN_INNER_TD_8588445_key_rightMajor {
    int32_t _ss_customer_sk4758;
    bool operator==(const SW_JOIN_INNER_TD_8588445_key_rightMajor& other) const {
        return ((_ss_customer_sk4758 == other._ss_customer_sk4758));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8588445_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8588445_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_customer_sk4758));
    }
};
}
struct SW_JOIN_INNER_TD_8588445_payload_rightMajor {
    int32_t _ss_sold_date_sk4755;
    int32_t _ss_customer_sk4758;
    int64_t _ss_ext_discount_amt4769;
    int64_t _ss_ext_list_price4772;
};
void SW_JOIN_INNER_TD_8588445(Table &tbl_Filter_TD_9366196_output, Table &tbl_Filter_TD_9426441_output, Table &tbl_JOIN_INNER_TD_8588445_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((c_customer_sk#4737 = ss_customer_sk#4758))
    // Left Table: ListBuffer(c_customer_sk#4737, c_customer_id#4738, c_first_name#4745, c_last_name#4746, c_preferred_cust_flag#4747, c_birth_country#4751, c_login#4752, c_email_address#4753)
    // Right Table: ListBuffer(ss_sold_date_sk#4755, ss_customer_sk#4758, ss_ext_discount_amt#4769, ss_ext_list_price#4772)
    // Output Table: ListBuffer(c_customer_id#4738, c_first_name#4745, c_last_name#4746, c_preferred_cust_flag#4747, c_birth_country#4751, c_login#4752, c_email_address#4753, ss_sold_date_sk#4755, ss_ext_discount_amt#4769, ss_ext_list_price#4772)
    int left_nrow = tbl_Filter_TD_9366196_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9426441_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8588445_key_leftMajor, SW_JOIN_INNER_TD_8588445_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_9366196_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk4737_k = tbl_Filter_TD_9366196_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8588445_key_leftMajor keyA{_c_customer_sk4737_k};
            int32_t _c_customer_sk4737 = tbl_Filter_TD_9366196_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id4738_n = tbl_Filter_TD_9366196_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_customer_id4738 = std::string(_c_customer_id4738_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name4745_n = tbl_Filter_TD_9366196_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_first_name4745 = std::string(_c_first_name4745_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name4746_n = tbl_Filter_TD_9366196_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_last_name4746 = std::string(_c_last_name4746_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag4747_n = tbl_Filter_TD_9366196_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_preferred_cust_flag4747 = std::string(_c_preferred_cust_flag4747_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country4751_n = tbl_Filter_TD_9366196_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _c_birth_country4751 = std::string(_c_birth_country4751_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_login4752_n = tbl_Filter_TD_9366196_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _c_login4752 = std::string(_c_login4752_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address4753_n = tbl_Filter_TD_9366196_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _c_email_address4753 = std::string(_c_email_address4753_n.data());
            SW_JOIN_INNER_TD_8588445_payload_leftMajor payloadA{_c_customer_sk4737, _c_customer_id4738, _c_first_name4745, _c_last_name4746, _c_preferred_cust_flag4747, _c_birth_country4751, _c_login4752, _c_email_address4753};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9426441_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_customer_sk4758_k = tbl_Filter_TD_9426441_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8588445_key_leftMajor{_ss_customer_sk4758_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk4737 = (it->second)._c_customer_sk4737;
                std::string _c_customer_id4738 = (it->second)._c_customer_id4738;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id4738_n{};
                memcpy(_c_customer_id4738_n.data(), (_c_customer_id4738).data(), (_c_customer_id4738).length());
                std::string _c_first_name4745 = (it->second)._c_first_name4745;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name4745_n{};
                memcpy(_c_first_name4745_n.data(), (_c_first_name4745).data(), (_c_first_name4745).length());
                std::string _c_last_name4746 = (it->second)._c_last_name4746;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name4746_n{};
                memcpy(_c_last_name4746_n.data(), (_c_last_name4746).data(), (_c_last_name4746).length());
                std::string _c_preferred_cust_flag4747 = (it->second)._c_preferred_cust_flag4747;
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag4747_n{};
                memcpy(_c_preferred_cust_flag4747_n.data(), (_c_preferred_cust_flag4747).data(), (_c_preferred_cust_flag4747).length());
                std::string _c_birth_country4751 = (it->second)._c_birth_country4751;
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country4751_n{};
                memcpy(_c_birth_country4751_n.data(), (_c_birth_country4751).data(), (_c_birth_country4751).length());
                std::string _c_login4752 = (it->second)._c_login4752;
                std::array<char, TPCDS_READ_MAX + 1> _c_login4752_n{};
                memcpy(_c_login4752_n.data(), (_c_login4752).data(), (_c_login4752).length());
                std::string _c_email_address4753 = (it->second)._c_email_address4753;
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address4753_n{};
                memcpy(_c_email_address4753_n.data(), (_c_email_address4753).data(), (_c_email_address4753).length());
                int32_t _ss_sold_date_sk4755 = tbl_Filter_TD_9426441_output.getInt32(i, 0);
                int32_t _ss_customer_sk4758 = tbl_Filter_TD_9426441_output.getInt32(i, 1);
                int64_t _ss_ext_discount_amt4769 = tbl_Filter_TD_9426441_output.getInt64(i, 2);
                int64_t _ss_ext_list_price4772 = tbl_Filter_TD_9426441_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_8588445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id4738_n);
                tbl_JOIN_INNER_TD_8588445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name4745_n);
                tbl_JOIN_INNER_TD_8588445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name4746_n);
                tbl_JOIN_INNER_TD_8588445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag4747_n);
                tbl_JOIN_INNER_TD_8588445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country4751_n);
                tbl_JOIN_INNER_TD_8588445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login4752_n);
                tbl_JOIN_INNER_TD_8588445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address4753_n);
                tbl_JOIN_INNER_TD_8588445_output.setInt32(r, 7, _ss_sold_date_sk4755);
                tbl_JOIN_INNER_TD_8588445_output.setInt64(r, 8, _ss_ext_discount_amt4769);
                tbl_JOIN_INNER_TD_8588445_output.setInt64(r, 9, _ss_ext_list_price4772);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8588445_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8588445_key_rightMajor, SW_JOIN_INNER_TD_8588445_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9426441_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_customer_sk4758_k = tbl_Filter_TD_9426441_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_8588445_key_rightMajor keyA{_ss_customer_sk4758_k};
            int32_t _ss_sold_date_sk4755 = tbl_Filter_TD_9426441_output.getInt32(i, 0);
            int32_t _ss_customer_sk4758 = tbl_Filter_TD_9426441_output.getInt32(i, 1);
            int64_t _ss_ext_discount_amt4769 = tbl_Filter_TD_9426441_output.getInt64(i, 2);
            int64_t _ss_ext_list_price4772 = tbl_Filter_TD_9426441_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_8588445_payload_rightMajor payloadA{_ss_sold_date_sk4755, _ss_customer_sk4758, _ss_ext_discount_amt4769, _ss_ext_list_price4772};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9366196_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk4737_k = tbl_Filter_TD_9366196_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8588445_key_rightMajor{_c_customer_sk4737_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk4755 = (it->second)._ss_sold_date_sk4755;
                int32_t _ss_customer_sk4758 = (it->second)._ss_customer_sk4758;
                int64_t _ss_ext_discount_amt4769 = (it->second)._ss_ext_discount_amt4769;
                int64_t _ss_ext_list_price4772 = (it->second)._ss_ext_list_price4772;
                int32_t _c_customer_sk4737 = tbl_Filter_TD_9366196_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id4738_n = tbl_Filter_TD_9366196_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_customer_id4738 = std::string(_c_customer_id4738_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name4745_n = tbl_Filter_TD_9366196_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_first_name4745 = std::string(_c_first_name4745_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name4746_n = tbl_Filter_TD_9366196_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_last_name4746 = std::string(_c_last_name4746_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag4747_n = tbl_Filter_TD_9366196_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_preferred_cust_flag4747 = std::string(_c_preferred_cust_flag4747_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country4751_n = tbl_Filter_TD_9366196_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _c_birth_country4751 = std::string(_c_birth_country4751_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_login4752_n = tbl_Filter_TD_9366196_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _c_login4752 = std::string(_c_login4752_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address4753_n = tbl_Filter_TD_9366196_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _c_email_address4753 = std::string(_c_email_address4753_n.data());
                tbl_JOIN_INNER_TD_8588445_output.setInt32(r, 7, _ss_sold_date_sk4755);
                tbl_JOIN_INNER_TD_8588445_output.setInt64(r, 8, _ss_ext_discount_amt4769);
                tbl_JOIN_INNER_TD_8588445_output.setInt64(r, 9, _ss_ext_list_price4772);
                tbl_JOIN_INNER_TD_8588445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id4738_n);
                tbl_JOIN_INNER_TD_8588445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name4745_n);
                tbl_JOIN_INNER_TD_8588445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name4746_n);
                tbl_JOIN_INNER_TD_8588445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag4747_n);
                tbl_JOIN_INNER_TD_8588445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country4751_n);
                tbl_JOIN_INNER_TD_8588445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login4752_n);
                tbl_JOIN_INNER_TD_8588445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address4753_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8588445_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8588445_output #Row: " << tbl_JOIN_INNER_TD_8588445_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8661755_key_leftMajor {
    int32_t _ss_sold_date_sk1206;
    bool operator==(const SW_JOIN_INNER_TD_8661755_key_leftMajor& other) const {
        return ((_ss_sold_date_sk1206 == other._ss_sold_date_sk1206));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8661755_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8661755_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_sold_date_sk1206));
    }
};
}
struct SW_JOIN_INNER_TD_8661755_payload_leftMajor {
    std::string _c_customer_id1;
    std::string _c_first_name8;
    std::string _c_last_name9;
    std::string _c_preferred_cust_flag10;
    std::string _c_birth_country14;
    std::string _c_login15;
    std::string _c_email_address16;
    int32_t _ss_sold_date_sk1206;
    int64_t _ss_ext_discount_amt1220;
    int64_t _ss_ext_list_price1223;
};
struct SW_JOIN_INNER_TD_8661755_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_8661755_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8661755_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8661755_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_8661755_payload_rightMajor {
    int32_t _d_date_sk120;
    int32_t _d_year126;
};
void SW_JOIN_INNER_TD_8661755(Table &tbl_JOIN_INNER_TD_9611703_output, Table &tbl_Filter_TD_9254929_output, Table &tbl_JOIN_INNER_TD_8661755_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#1206 = d_date_sk#120))
    // Left Table: ListBuffer(c_customer_id#1, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_country#14, c_login#15, c_email_address#16, ss_sold_date_sk#1206, ss_ext_discount_amt#1220, ss_ext_list_price#1223)
    // Right Table: ListBuffer(d_date_sk#120, d_year#126)
    // Output Table: ListBuffer(c_customer_id#1, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_country#14, c_login#15, c_email_address#16, ss_ext_discount_amt#1220, ss_ext_list_price#1223, d_year#126)
    int left_nrow = tbl_JOIN_INNER_TD_9611703_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9254929_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8661755_key_leftMajor, SW_JOIN_INNER_TD_8661755_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_9611703_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_JOIN_INNER_TD_9611703_output.getInt32(i, 7);
            SW_JOIN_INNER_TD_8661755_key_leftMajor keyA{_ss_sold_date_sk1206_k};
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n = tbl_JOIN_INNER_TD_9611703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _c_customer_id1 = std::string(_c_customer_id1_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_JOIN_INNER_TD_9611703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_first_name8 = std::string(_c_first_name8_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_JOIN_INNER_TD_9611703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_last_name9 = std::string(_c_last_name9_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_n = tbl_JOIN_INNER_TD_9611703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_preferred_cust_flag10 = std::string(_c_preferred_cust_flag10_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country14_n = tbl_JOIN_INNER_TD_9611703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_birth_country14 = std::string(_c_birth_country14_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_login15_n = tbl_JOIN_INNER_TD_9611703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _c_login15 = std::string(_c_login15_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address16_n = tbl_JOIN_INNER_TD_9611703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _c_email_address16 = std::string(_c_email_address16_n.data());
            int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_9611703_output.getInt32(i, 7);
            int64_t _ss_ext_discount_amt1220 = tbl_JOIN_INNER_TD_9611703_output.getInt64(i, 8);
            int64_t _ss_ext_list_price1223 = tbl_JOIN_INNER_TD_9611703_output.getInt64(i, 9);
            SW_JOIN_INNER_TD_8661755_payload_leftMajor payloadA{_c_customer_id1, _c_first_name8, _c_last_name9, _c_preferred_cust_flag10, _c_birth_country14, _c_login15, _c_email_address16, _ss_sold_date_sk1206, _ss_ext_discount_amt1220, _ss_ext_list_price1223};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9254929_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_9254929_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8661755_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _c_customer_id1 = (it->second)._c_customer_id1;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n{};
                memcpy(_c_customer_id1_n.data(), (_c_customer_id1).data(), (_c_customer_id1).length());
                std::string _c_first_name8 = (it->second)._c_first_name8;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n{};
                memcpy(_c_first_name8_n.data(), (_c_first_name8).data(), (_c_first_name8).length());
                std::string _c_last_name9 = (it->second)._c_last_name9;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n{};
                memcpy(_c_last_name9_n.data(), (_c_last_name9).data(), (_c_last_name9).length());
                std::string _c_preferred_cust_flag10 = (it->second)._c_preferred_cust_flag10;
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_n{};
                memcpy(_c_preferred_cust_flag10_n.data(), (_c_preferred_cust_flag10).data(), (_c_preferred_cust_flag10).length());
                std::string _c_birth_country14 = (it->second)._c_birth_country14;
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country14_n{};
                memcpy(_c_birth_country14_n.data(), (_c_birth_country14).data(), (_c_birth_country14).length());
                std::string _c_login15 = (it->second)._c_login15;
                std::array<char, TPCDS_READ_MAX + 1> _c_login15_n{};
                memcpy(_c_login15_n.data(), (_c_login15).data(), (_c_login15).length());
                std::string _c_email_address16 = (it->second)._c_email_address16;
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address16_n{};
                memcpy(_c_email_address16_n.data(), (_c_email_address16).data(), (_c_email_address16).length());
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int64_t _ss_ext_discount_amt1220 = (it->second)._ss_ext_discount_amt1220;
                int64_t _ss_ext_list_price1223 = (it->second)._ss_ext_list_price1223;
                int32_t _d_date_sk120 = tbl_Filter_TD_9254929_output.getInt32(i, 0);
                int32_t _d_year126 = tbl_Filter_TD_9254929_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_8661755_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id1_n);
                tbl_JOIN_INNER_TD_8661755_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
                tbl_JOIN_INNER_TD_8661755_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name9_n);
                tbl_JOIN_INNER_TD_8661755_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag10_n);
                tbl_JOIN_INNER_TD_8661755_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country14_n);
                tbl_JOIN_INNER_TD_8661755_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login15_n);
                tbl_JOIN_INNER_TD_8661755_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address16_n);
                tbl_JOIN_INNER_TD_8661755_output.setInt64(r, 7, _ss_ext_discount_amt1220);
                tbl_JOIN_INNER_TD_8661755_output.setInt64(r, 8, _ss_ext_list_price1223);
                tbl_JOIN_INNER_TD_8661755_output.setInt32(r, 9, _d_year126);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8661755_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8661755_key_rightMajor, SW_JOIN_INNER_TD_8661755_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9254929_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_9254929_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8661755_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_9254929_output.getInt32(i, 0);
            int32_t _d_year126 = tbl_Filter_TD_9254929_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_8661755_payload_rightMajor payloadA{_d_date_sk120, _d_year126};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_9611703_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_JOIN_INNER_TD_9611703_output.getInt32(i, 7);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8661755_key_rightMajor{_ss_sold_date_sk1206_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _d_year126 = (it->second)._d_year126;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n = tbl_JOIN_INNER_TD_9611703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _c_customer_id1 = std::string(_c_customer_id1_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_JOIN_INNER_TD_9611703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_first_name8 = std::string(_c_first_name8_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_JOIN_INNER_TD_9611703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_last_name9 = std::string(_c_last_name9_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_n = tbl_JOIN_INNER_TD_9611703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_preferred_cust_flag10 = std::string(_c_preferred_cust_flag10_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country14_n = tbl_JOIN_INNER_TD_9611703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_birth_country14 = std::string(_c_birth_country14_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_login15_n = tbl_JOIN_INNER_TD_9611703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _c_login15 = std::string(_c_login15_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address16_n = tbl_JOIN_INNER_TD_9611703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _c_email_address16 = std::string(_c_email_address16_n.data());
                int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_9611703_output.getInt32(i, 7);
                int64_t _ss_ext_discount_amt1220 = tbl_JOIN_INNER_TD_9611703_output.getInt64(i, 8);
                int64_t _ss_ext_list_price1223 = tbl_JOIN_INNER_TD_9611703_output.getInt64(i, 9);
                tbl_JOIN_INNER_TD_8661755_output.setInt32(r, 9, _d_year126);
                tbl_JOIN_INNER_TD_8661755_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id1_n);
                tbl_JOIN_INNER_TD_8661755_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
                tbl_JOIN_INNER_TD_8661755_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name9_n);
                tbl_JOIN_INNER_TD_8661755_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag10_n);
                tbl_JOIN_INNER_TD_8661755_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country14_n);
                tbl_JOIN_INNER_TD_8661755_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login15_n);
                tbl_JOIN_INNER_TD_8661755_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address16_n);
                tbl_JOIN_INNER_TD_8661755_output.setInt64(r, 7, _ss_ext_discount_amt1220);
                tbl_JOIN_INNER_TD_8661755_output.setInt64(r, 8, _ss_ext_list_price1223);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8661755_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8661755_output #Row: " << tbl_JOIN_INNER_TD_8661755_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7147492(Table &tbl_SerializeFromObject_TD_8163070_input, Table &tbl_Filter_TD_7147492_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_bill_customer_sk#5146) AND isnotnull(ws_sold_date_sk#5142)))
    // Input: ListBuffer(ws_sold_date_sk#5142, ws_bill_customer_sk#5146, ws_ext_discount_amt#5164, ws_ext_list_price#5167)
    // Output: ListBuffer(ws_sold_date_sk#5142, ws_bill_customer_sk#5146, ws_ext_discount_amt#5164, ws_ext_list_price#5167)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8163070_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_bill_customer_sk5146 = tbl_SerializeFromObject_TD_8163070_input.getInt32(i, 1);
        int32_t _ws_sold_date_sk5142 = tbl_SerializeFromObject_TD_8163070_input.getInt32(i, 0);
        if ((_ws_bill_customer_sk5146!= 0) && (_ws_sold_date_sk5142!= 0)) {
            int32_t _ws_sold_date_sk5142_t = tbl_SerializeFromObject_TD_8163070_input.getInt32(i, 0);
            tbl_Filter_TD_7147492_output.setInt32(r, 0, _ws_sold_date_sk5142_t);
            int32_t _ws_bill_customer_sk5146_t = tbl_SerializeFromObject_TD_8163070_input.getInt32(i, 1);
            tbl_Filter_TD_7147492_output.setInt32(r, 1, _ws_bill_customer_sk5146_t);
            int64_t _ws_ext_discount_amt5164_t = tbl_SerializeFromObject_TD_8163070_input.getInt64(i, 2);
            tbl_Filter_TD_7147492_output.setInt64(r, 2, _ws_ext_discount_amt5164_t);
            int64_t _ws_ext_list_price5167_t = tbl_SerializeFromObject_TD_8163070_input.getInt64(i, 3);
            tbl_Filter_TD_7147492_output.setInt64(r, 3, _ws_ext_list_price5167_t);
            r++;
        }
    }
    tbl_Filter_TD_7147492_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7147492_output #Row: " << tbl_Filter_TD_7147492_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7965326(Table &tbl_SerializeFromObject_TD_8391444_input, Table &tbl_Filter_TD_7965326_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(c_customer_sk#5124) AND isnotnull(c_customer_id#5125)))
    // Input: ListBuffer(c_customer_sk#5124, c_customer_id#5125, c_first_name#5132, c_last_name#5133, c_preferred_cust_flag#5134, c_birth_country#5138, c_login#5139, c_email_address#5140)
    // Output: ListBuffer(c_customer_sk#5124, c_customer_id#5125, c_first_name#5132, c_last_name#5133, c_preferred_cust_flag#5134, c_birth_country#5138, c_login#5139, c_email_address#5140)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8391444_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk5124 = tbl_SerializeFromObject_TD_8391444_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id5125 = tbl_SerializeFromObject_TD_8391444_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_c_customer_sk5124!= 0) && _c_customer_id5125.data() != "NULL") {
            int32_t _c_customer_sk5124_t = tbl_SerializeFromObject_TD_8391444_input.getInt32(i, 0);
            tbl_Filter_TD_7965326_output.setInt32(r, 0, _c_customer_sk5124_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id5125_t = tbl_SerializeFromObject_TD_8391444_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_7965326_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_customer_id5125_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name5132_t = tbl_SerializeFromObject_TD_8391444_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_7965326_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name5132_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name5133_t = tbl_SerializeFromObject_TD_8391444_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_7965326_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name5133_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag5134_t = tbl_SerializeFromObject_TD_8391444_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            tbl_Filter_TD_7965326_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_preferred_cust_flag5134_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country5138_t = tbl_SerializeFromObject_TD_8391444_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            tbl_Filter_TD_7965326_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_birth_country5138_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_login5139_t = tbl_SerializeFromObject_TD_8391444_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            tbl_Filter_TD_7965326_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_login5139_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address5140_t = tbl_SerializeFromObject_TD_8391444_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            tbl_Filter_TD_7965326_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _c_email_address5140_t);
            r++;
        }
    }
    tbl_Filter_TD_7965326_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7965326_output #Row: " << tbl_Filter_TD_7965326_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_7692608_key {
    std::string _c_customer_id4966;
    std::string _c_first_name4973;
    std::string _c_last_name4974;
    std::string _c_preferred_cust_flag4975;
    std::string _c_birth_country4979;
    std::string _c_login4980;
    std::string _c_email_address4981;
    int32_t _d_year5023;
    bool operator==(const SW_Aggregate_TD_7692608_key& other) const { return (_c_customer_id4966 == other._c_customer_id4966) && (_c_first_name4973 == other._c_first_name4973) && (_c_last_name4974 == other._c_last_name4974) && (_c_preferred_cust_flag4975 == other._c_preferred_cust_flag4975) && (_c_birth_country4979 == other._c_birth_country4979) && (_c_login4980 == other._c_login4980) && (_c_email_address4981 == other._c_email_address4981) && (_d_year5023 == other._d_year5023); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_7692608_key> {
    std::size_t operator() (const SW_Aggregate_TD_7692608_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._c_customer_id4966)) + (hash<string>()(k._c_first_name4973)) + (hash<string>()(k._c_last_name4974)) + (hash<string>()(k._c_preferred_cust_flag4975)) + (hash<string>()(k._c_birth_country4979)) + (hash<string>()(k._c_login4980)) + (hash<string>()(k._c_email_address4981)) + (hash<int32_t>()(k._d_year5023));
    }
};
}
struct SW_Aggregate_TD_7692608_payload {
    std::string _customer_id3554;
    int64_t _year_total3562_sum_0;
};
void SW_Aggregate_TD_7692608(Table &tbl_JOIN_INNER_TD_8385547_output, Table &tbl_Aggregate_TD_7692608_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_customer_id#4966, c_first_name#4973, c_last_name#4974, c_preferred_cust_flag#4975, c_birth_country#4979, c_login#4980, c_email_address#4981, d_year#5023, c_customer_id#4966 AS customer_id#3554, MakeDecimal(sum(UnscaledValue(CheckOverflow((promote_precision(cast(ws_ext_list_price#5008 as decimal(8,2))) - promote_precision(cast(ws_ext_discount_amt#5005 as decimal(8,2)))), DecimalType(8,2), true))),18,2) AS year_total#3562)
    // Input: ListBuffer(c_customer_id#4966, c_first_name#4973, c_last_name#4974, c_preferred_cust_flag#4975, c_birth_country#4979, c_login#4980, c_email_address#4981, ws_ext_discount_amt#5005, ws_ext_list_price#5008, d_year#5023)
    // Output: ListBuffer(customer_id#3554, year_total#3562)
    std::unordered_map<SW_Aggregate_TD_7692608_key, SW_Aggregate_TD_7692608_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_8385547_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id4966 = tbl_JOIN_INNER_TD_8385547_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name4973 = tbl_JOIN_INNER_TD_8385547_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name4974 = tbl_JOIN_INNER_TD_8385547_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag4975 = tbl_JOIN_INNER_TD_8385547_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _c_birth_country4979 = tbl_JOIN_INNER_TD_8385547_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _c_login4980 = tbl_JOIN_INNER_TD_8385547_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _c_email_address4981 = tbl_JOIN_INNER_TD_8385547_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        int64_t _ws_ext_discount_amt5005 = tbl_JOIN_INNER_TD_8385547_output.getInt64(i, 7);
        int64_t _ws_ext_list_price5008 = tbl_JOIN_INNER_TD_8385547_output.getInt64(i, 8);
        int32_t _d_year5023 = tbl_JOIN_INNER_TD_8385547_output.getInt32(i, 9);
        SW_Aggregate_TD_7692608_key k{std::string(_c_customer_id4966.data()), std::string(_c_first_name4973.data()), std::string(_c_last_name4974.data()), std::string(_c_preferred_cust_flag4975.data()), std::string(_c_birth_country4979.data()), std::string(_c_login4980.data()), std::string(_c_email_address4981.data()), _d_year5023};
        std::array<char, TPCDS_READ_MAX + 1> _customer_id3554 = _c_customer_id4966;
        int64_t _year_total3562_sum_0 = (_ws_ext_list_price5008 - _ws_ext_discount_amt5005);
        SW_Aggregate_TD_7692608_payload p{std::string(_customer_id3554.data()), _year_total3562_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._year_total3562_sum_0 + _year_total3562_sum_0;
            p._year_total3562_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _c_customer_id4966 not required in the output table
        // _c_first_name4973 not required in the output table
        // _c_last_name4974 not required in the output table
        // _c_preferred_cust_flag4975 not required in the output table
        // _c_birth_country4979 not required in the output table
        // _c_login4980 not required in the output table
        // _c_email_address4981 not required in the output table
        // _d_year5023 not required in the output table
        std::array<char, TPCDS_READ_MAX + 1> _customer_id3554_n{};
        memcpy(_customer_id3554_n.data(), (it.second)._customer_id3554.data(), (it.second)._customer_id3554.length());
        tbl_Aggregate_TD_7692608_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id3554_n);
        int64_t _year_total3562 = (it.second)._year_total3562_sum_0;
        tbl_Aggregate_TD_7692608_output.setInt64(r, 1, _year_total3562);
        ++r;
    }
    tbl_Aggregate_TD_7692608_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_7692608_output #Row: " << tbl_Aggregate_TD_7692608_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_7619669_key_leftMajor {
    int32_t _ss_sold_date_sk4755;
    bool operator==(const SW_JOIN_INNER_TD_7619669_key_leftMajor& other) const {
        return ((_ss_sold_date_sk4755 == other._ss_sold_date_sk4755));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7619669_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7619669_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_sold_date_sk4755));
    }
};
}
struct SW_JOIN_INNER_TD_7619669_payload_leftMajor {
    std::string _c_customer_id4738;
    std::string _c_first_name4745;
    std::string _c_last_name4746;
    std::string _c_preferred_cust_flag4747;
    std::string _c_birth_country4751;
    std::string _c_login4752;
    std::string _c_email_address4753;
    int32_t _ss_sold_date_sk4755;
    int64_t _ss_ext_discount_amt4769;
    int64_t _ss_ext_list_price4772;
};
struct SW_JOIN_INNER_TD_7619669_key_rightMajor {
    int32_t _d_date_sk4778;
    bool operator==(const SW_JOIN_INNER_TD_7619669_key_rightMajor& other) const {
        return ((_d_date_sk4778 == other._d_date_sk4778));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7619669_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7619669_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk4778));
    }
};
}
struct SW_JOIN_INNER_TD_7619669_payload_rightMajor {
    int32_t _d_date_sk4778;
    int32_t _d_year4784;
};
void SW_JOIN_INNER_TD_7619669(Table &tbl_JOIN_INNER_TD_8588445_output, Table &tbl_Filter_TD_8239347_output, Table &tbl_JOIN_INNER_TD_7619669_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#4755 = d_date_sk#4778))
    // Left Table: ListBuffer(c_customer_id#4738, c_first_name#4745, c_last_name#4746, c_preferred_cust_flag#4747, c_birth_country#4751, c_login#4752, c_email_address#4753, ss_sold_date_sk#4755, ss_ext_discount_amt#4769, ss_ext_list_price#4772)
    // Right Table: ListBuffer(d_date_sk#4778, d_year#4784)
    // Output Table: ListBuffer(c_customer_id#4738, c_first_name#4745, c_last_name#4746, c_preferred_cust_flag#4747, c_birth_country#4751, c_login#4752, c_email_address#4753, ss_ext_discount_amt#4769, ss_ext_list_price#4772, d_year#4784)
    int left_nrow = tbl_JOIN_INNER_TD_8588445_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8239347_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7619669_key_leftMajor, SW_JOIN_INNER_TD_7619669_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_8588445_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_sold_date_sk4755_k = tbl_JOIN_INNER_TD_8588445_output.getInt32(i, 7);
            SW_JOIN_INNER_TD_7619669_key_leftMajor keyA{_ss_sold_date_sk4755_k};
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id4738_n = tbl_JOIN_INNER_TD_8588445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _c_customer_id4738 = std::string(_c_customer_id4738_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name4745_n = tbl_JOIN_INNER_TD_8588445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_first_name4745 = std::string(_c_first_name4745_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name4746_n = tbl_JOIN_INNER_TD_8588445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_last_name4746 = std::string(_c_last_name4746_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag4747_n = tbl_JOIN_INNER_TD_8588445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_preferred_cust_flag4747 = std::string(_c_preferred_cust_flag4747_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country4751_n = tbl_JOIN_INNER_TD_8588445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_birth_country4751 = std::string(_c_birth_country4751_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_login4752_n = tbl_JOIN_INNER_TD_8588445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _c_login4752 = std::string(_c_login4752_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address4753_n = tbl_JOIN_INNER_TD_8588445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _c_email_address4753 = std::string(_c_email_address4753_n.data());
            int32_t _ss_sold_date_sk4755 = tbl_JOIN_INNER_TD_8588445_output.getInt32(i, 7);
            int64_t _ss_ext_discount_amt4769 = tbl_JOIN_INNER_TD_8588445_output.getInt64(i, 8);
            int64_t _ss_ext_list_price4772 = tbl_JOIN_INNER_TD_8588445_output.getInt64(i, 9);
            SW_JOIN_INNER_TD_7619669_payload_leftMajor payloadA{_c_customer_id4738, _c_first_name4745, _c_last_name4746, _c_preferred_cust_flag4747, _c_birth_country4751, _c_login4752, _c_email_address4753, _ss_sold_date_sk4755, _ss_ext_discount_amt4769, _ss_ext_list_price4772};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8239347_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk4778_k = tbl_Filter_TD_8239347_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7619669_key_leftMajor{_d_date_sk4778_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _c_customer_id4738 = (it->second)._c_customer_id4738;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id4738_n{};
                memcpy(_c_customer_id4738_n.data(), (_c_customer_id4738).data(), (_c_customer_id4738).length());
                std::string _c_first_name4745 = (it->second)._c_first_name4745;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name4745_n{};
                memcpy(_c_first_name4745_n.data(), (_c_first_name4745).data(), (_c_first_name4745).length());
                std::string _c_last_name4746 = (it->second)._c_last_name4746;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name4746_n{};
                memcpy(_c_last_name4746_n.data(), (_c_last_name4746).data(), (_c_last_name4746).length());
                std::string _c_preferred_cust_flag4747 = (it->second)._c_preferred_cust_flag4747;
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag4747_n{};
                memcpy(_c_preferred_cust_flag4747_n.data(), (_c_preferred_cust_flag4747).data(), (_c_preferred_cust_flag4747).length());
                std::string _c_birth_country4751 = (it->second)._c_birth_country4751;
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country4751_n{};
                memcpy(_c_birth_country4751_n.data(), (_c_birth_country4751).data(), (_c_birth_country4751).length());
                std::string _c_login4752 = (it->second)._c_login4752;
                std::array<char, TPCDS_READ_MAX + 1> _c_login4752_n{};
                memcpy(_c_login4752_n.data(), (_c_login4752).data(), (_c_login4752).length());
                std::string _c_email_address4753 = (it->second)._c_email_address4753;
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address4753_n{};
                memcpy(_c_email_address4753_n.data(), (_c_email_address4753).data(), (_c_email_address4753).length());
                int32_t _ss_sold_date_sk4755 = (it->second)._ss_sold_date_sk4755;
                int64_t _ss_ext_discount_amt4769 = (it->second)._ss_ext_discount_amt4769;
                int64_t _ss_ext_list_price4772 = (it->second)._ss_ext_list_price4772;
                int32_t _d_date_sk4778 = tbl_Filter_TD_8239347_output.getInt32(i, 0);
                int32_t _d_year4784 = tbl_Filter_TD_8239347_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_7619669_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id4738_n);
                tbl_JOIN_INNER_TD_7619669_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name4745_n);
                tbl_JOIN_INNER_TD_7619669_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name4746_n);
                tbl_JOIN_INNER_TD_7619669_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag4747_n);
                tbl_JOIN_INNER_TD_7619669_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country4751_n);
                tbl_JOIN_INNER_TD_7619669_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login4752_n);
                tbl_JOIN_INNER_TD_7619669_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address4753_n);
                tbl_JOIN_INNER_TD_7619669_output.setInt64(r, 7, _ss_ext_discount_amt4769);
                tbl_JOIN_INNER_TD_7619669_output.setInt64(r, 8, _ss_ext_list_price4772);
                tbl_JOIN_INNER_TD_7619669_output.setInt32(r, 9, _d_year4784);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7619669_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7619669_key_rightMajor, SW_JOIN_INNER_TD_7619669_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8239347_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk4778_k = tbl_Filter_TD_8239347_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7619669_key_rightMajor keyA{_d_date_sk4778_k};
            int32_t _d_date_sk4778 = tbl_Filter_TD_8239347_output.getInt32(i, 0);
            int32_t _d_year4784 = tbl_Filter_TD_8239347_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_7619669_payload_rightMajor payloadA{_d_date_sk4778, _d_year4784};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_8588445_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_sold_date_sk4755_k = tbl_JOIN_INNER_TD_8588445_output.getInt32(i, 7);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7619669_key_rightMajor{_ss_sold_date_sk4755_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk4778 = (it->second)._d_date_sk4778;
                int32_t _d_year4784 = (it->second)._d_year4784;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id4738_n = tbl_JOIN_INNER_TD_8588445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _c_customer_id4738 = std::string(_c_customer_id4738_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name4745_n = tbl_JOIN_INNER_TD_8588445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_first_name4745 = std::string(_c_first_name4745_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name4746_n = tbl_JOIN_INNER_TD_8588445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_last_name4746 = std::string(_c_last_name4746_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag4747_n = tbl_JOIN_INNER_TD_8588445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_preferred_cust_flag4747 = std::string(_c_preferred_cust_flag4747_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country4751_n = tbl_JOIN_INNER_TD_8588445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_birth_country4751 = std::string(_c_birth_country4751_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_login4752_n = tbl_JOIN_INNER_TD_8588445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _c_login4752 = std::string(_c_login4752_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address4753_n = tbl_JOIN_INNER_TD_8588445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _c_email_address4753 = std::string(_c_email_address4753_n.data());
                int32_t _ss_sold_date_sk4755 = tbl_JOIN_INNER_TD_8588445_output.getInt32(i, 7);
                int64_t _ss_ext_discount_amt4769 = tbl_JOIN_INNER_TD_8588445_output.getInt64(i, 8);
                int64_t _ss_ext_list_price4772 = tbl_JOIN_INNER_TD_8588445_output.getInt64(i, 9);
                tbl_JOIN_INNER_TD_7619669_output.setInt32(r, 9, _d_year4784);
                tbl_JOIN_INNER_TD_7619669_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id4738_n);
                tbl_JOIN_INNER_TD_7619669_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name4745_n);
                tbl_JOIN_INNER_TD_7619669_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name4746_n);
                tbl_JOIN_INNER_TD_7619669_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag4747_n);
                tbl_JOIN_INNER_TD_7619669_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country4751_n);
                tbl_JOIN_INNER_TD_7619669_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login4752_n);
                tbl_JOIN_INNER_TD_7619669_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address4753_n);
                tbl_JOIN_INNER_TD_7619669_output.setInt64(r, 7, _ss_ext_discount_amt4769);
                tbl_JOIN_INNER_TD_7619669_output.setInt64(r, 8, _ss_ext_list_price4772);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7619669_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7619669_output #Row: " << tbl_JOIN_INNER_TD_7619669_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_7565087_key {
    std::string _c_customer_id1;
    std::string _c_first_name8;
    std::string _c_last_name9;
    std::string _c_preferred_cust_flag10;
    std::string _c_birth_country14;
    std::string _c_login15;
    std::string _c_email_address16;
    int32_t _d_year126;
    bool operator==(const SW_Aggregate_TD_7565087_key& other) const { return (_c_customer_id1 == other._c_customer_id1) && (_c_first_name8 == other._c_first_name8) && (_c_last_name9 == other._c_last_name9) && (_c_preferred_cust_flag10 == other._c_preferred_cust_flag10) && (_c_birth_country14 == other._c_birth_country14) && (_c_login15 == other._c_login15) && (_c_email_address16 == other._c_email_address16) && (_d_year126 == other._d_year126); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_7565087_key> {
    std::size_t operator() (const SW_Aggregate_TD_7565087_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._c_customer_id1)) + (hash<string>()(k._c_first_name8)) + (hash<string>()(k._c_last_name9)) + (hash<string>()(k._c_preferred_cust_flag10)) + (hash<string>()(k._c_birth_country14)) + (hash<string>()(k._c_login15)) + (hash<string>()(k._c_email_address16)) + (hash<int32_t>()(k._d_year126));
    }
};
}
struct SW_Aggregate_TD_7565087_payload {
    std::string _customer_id3544;
    int64_t _year_total3552_sum_0;
};
void SW_Aggregate_TD_7565087(Table &tbl_JOIN_INNER_TD_8661755_output, Table &tbl_Aggregate_TD_7565087_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_customer_id#1, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_country#14, c_login#15, c_email_address#16, d_year#126, c_customer_id#1 AS customer_id#3544, MakeDecimal(sum(UnscaledValue(CheckOverflow((promote_precision(cast(ss_ext_list_price#1223 as decimal(8,2))) - promote_precision(cast(ss_ext_discount_amt#1220 as decimal(8,2)))), DecimalType(8,2), true))),18,2) AS year_total#3552)
    // Input: ListBuffer(c_customer_id#1, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_country#14, c_login#15, c_email_address#16, ss_ext_discount_amt#1220, ss_ext_list_price#1223, d_year#126)
    // Output: ListBuffer(customer_id#3544, year_total#3552)
    std::unordered_map<SW_Aggregate_TD_7565087_key, SW_Aggregate_TD_7565087_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_8661755_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1 = tbl_JOIN_INNER_TD_8661755_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8 = tbl_JOIN_INNER_TD_8661755_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9 = tbl_JOIN_INNER_TD_8661755_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10 = tbl_JOIN_INNER_TD_8661755_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _c_birth_country14 = tbl_JOIN_INNER_TD_8661755_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _c_login15 = tbl_JOIN_INNER_TD_8661755_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _c_email_address16 = tbl_JOIN_INNER_TD_8661755_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        int64_t _ss_ext_discount_amt1220 = tbl_JOIN_INNER_TD_8661755_output.getInt64(i, 7);
        int64_t _ss_ext_list_price1223 = tbl_JOIN_INNER_TD_8661755_output.getInt64(i, 8);
        int32_t _d_year126 = tbl_JOIN_INNER_TD_8661755_output.getInt32(i, 9);
        SW_Aggregate_TD_7565087_key k{std::string(_c_customer_id1.data()), std::string(_c_first_name8.data()), std::string(_c_last_name9.data()), std::string(_c_preferred_cust_flag10.data()), std::string(_c_birth_country14.data()), std::string(_c_login15.data()), std::string(_c_email_address16.data()), _d_year126};
        std::array<char, TPCDS_READ_MAX + 1> _customer_id3544 = _c_customer_id1;
        int64_t _year_total3552_sum_0 = (_ss_ext_list_price1223 - _ss_ext_discount_amt1220);
        SW_Aggregate_TD_7565087_payload p{std::string(_customer_id3544.data()), _year_total3552_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._year_total3552_sum_0 + _year_total3552_sum_0;
            p._year_total3552_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _c_customer_id1 not required in the output table
        // _c_first_name8 not required in the output table
        // _c_last_name9 not required in the output table
        // _c_preferred_cust_flag10 not required in the output table
        // _c_birth_country14 not required in the output table
        // _c_login15 not required in the output table
        // _c_email_address16 not required in the output table
        // _d_year126 not required in the output table
        std::array<char, TPCDS_READ_MAX + 1> _customer_id3544_n{};
        memcpy(_customer_id3544_n.data(), (it.second)._customer_id3544.data(), (it.second)._customer_id3544.length());
        tbl_Aggregate_TD_7565087_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id3544_n);
        int64_t _year_total3552 = (it.second)._year_total3552_sum_0;
        tbl_Aggregate_TD_7565087_output.setInt64(r, 1, _year_total3552);
        ++r;
    }
    tbl_Aggregate_TD_7565087_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_7565087_output #Row: " << tbl_Aggregate_TD_7565087_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6644775(Table &tbl_SerializeFromObject_TD_7697996_input, Table &tbl_Filter_TD_6644775_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#5182) AND (d_year#5182 = 2002)) AND isnotnull(d_date_sk#5176)))
    // Input: ListBuffer(d_date_sk#5176, d_year#5182)
    // Output: ListBuffer(d_date_sk#5176, d_year#5182)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7697996_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year5182 = tbl_SerializeFromObject_TD_7697996_input.getInt32(i, 1);
        int32_t _d_date_sk5176 = tbl_SerializeFromObject_TD_7697996_input.getInt32(i, 0);
        if (((_d_year5182!= 0) && (_d_year5182 == 2002)) && (_d_date_sk5176!= 0)) {
            int32_t _d_date_sk5176_t = tbl_SerializeFromObject_TD_7697996_input.getInt32(i, 0);
            tbl_Filter_TD_6644775_output.setInt32(r, 0, _d_date_sk5176_t);
            int32_t _d_year5182_t = tbl_SerializeFromObject_TD_7697996_input.getInt32(i, 1);
            tbl_Filter_TD_6644775_output.setInt32(r, 1, _d_year5182_t);
            r++;
        }
    }
    tbl_Filter_TD_6644775_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6644775_output #Row: " << tbl_Filter_TD_6644775_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6611510_key_leftMajor {
    int32_t _c_customer_sk5124;
    bool operator==(const SW_JOIN_INNER_TD_6611510_key_leftMajor& other) const {
        return ((_c_customer_sk5124 == other._c_customer_sk5124));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6611510_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6611510_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk5124));
    }
};
}
struct SW_JOIN_INNER_TD_6611510_payload_leftMajor {
    int32_t _c_customer_sk5124;
    std::string _c_customer_id5125;
    std::string _c_first_name5132;
    std::string _c_last_name5133;
    std::string _c_preferred_cust_flag5134;
    std::string _c_birth_country5138;
    std::string _c_login5139;
    std::string _c_email_address5140;
};
struct SW_JOIN_INNER_TD_6611510_key_rightMajor {
    int32_t _ws_bill_customer_sk5146;
    bool operator==(const SW_JOIN_INNER_TD_6611510_key_rightMajor& other) const {
        return ((_ws_bill_customer_sk5146 == other._ws_bill_customer_sk5146));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6611510_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6611510_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_bill_customer_sk5146));
    }
};
}
struct SW_JOIN_INNER_TD_6611510_payload_rightMajor {
    int32_t _ws_sold_date_sk5142;
    int32_t _ws_bill_customer_sk5146;
    int64_t _ws_ext_discount_amt5164;
    int64_t _ws_ext_list_price5167;
};
void SW_JOIN_INNER_TD_6611510(Table &tbl_Filter_TD_7965326_output, Table &tbl_Filter_TD_7147492_output, Table &tbl_JOIN_INNER_TD_6611510_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((c_customer_sk#5124 = ws_bill_customer_sk#5146))
    // Left Table: ListBuffer(c_customer_sk#5124, c_customer_id#5125, c_first_name#5132, c_last_name#5133, c_preferred_cust_flag#5134, c_birth_country#5138, c_login#5139, c_email_address#5140)
    // Right Table: ListBuffer(ws_sold_date_sk#5142, ws_bill_customer_sk#5146, ws_ext_discount_amt#5164, ws_ext_list_price#5167)
    // Output Table: ListBuffer(c_customer_id#5125, c_first_name#5132, c_last_name#5133, c_preferred_cust_flag#5134, c_birth_country#5138, c_login#5139, c_email_address#5140, ws_sold_date_sk#5142, ws_ext_discount_amt#5164, ws_ext_list_price#5167)
    int left_nrow = tbl_Filter_TD_7965326_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7147492_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6611510_key_leftMajor, SW_JOIN_INNER_TD_6611510_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_7965326_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk5124_k = tbl_Filter_TD_7965326_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6611510_key_leftMajor keyA{_c_customer_sk5124_k};
            int32_t _c_customer_sk5124 = tbl_Filter_TD_7965326_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id5125_n = tbl_Filter_TD_7965326_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_customer_id5125 = std::string(_c_customer_id5125_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name5132_n = tbl_Filter_TD_7965326_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_first_name5132 = std::string(_c_first_name5132_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name5133_n = tbl_Filter_TD_7965326_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_last_name5133 = std::string(_c_last_name5133_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag5134_n = tbl_Filter_TD_7965326_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_preferred_cust_flag5134 = std::string(_c_preferred_cust_flag5134_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country5138_n = tbl_Filter_TD_7965326_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _c_birth_country5138 = std::string(_c_birth_country5138_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_login5139_n = tbl_Filter_TD_7965326_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _c_login5139 = std::string(_c_login5139_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address5140_n = tbl_Filter_TD_7965326_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _c_email_address5140 = std::string(_c_email_address5140_n.data());
            SW_JOIN_INNER_TD_6611510_payload_leftMajor payloadA{_c_customer_sk5124, _c_customer_id5125, _c_first_name5132, _c_last_name5133, _c_preferred_cust_flag5134, _c_birth_country5138, _c_login5139, _c_email_address5140};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7147492_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_bill_customer_sk5146_k = tbl_Filter_TD_7147492_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6611510_key_leftMajor{_ws_bill_customer_sk5146_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk5124 = (it->second)._c_customer_sk5124;
                std::string _c_customer_id5125 = (it->second)._c_customer_id5125;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id5125_n{};
                memcpy(_c_customer_id5125_n.data(), (_c_customer_id5125).data(), (_c_customer_id5125).length());
                std::string _c_first_name5132 = (it->second)._c_first_name5132;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name5132_n{};
                memcpy(_c_first_name5132_n.data(), (_c_first_name5132).data(), (_c_first_name5132).length());
                std::string _c_last_name5133 = (it->second)._c_last_name5133;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name5133_n{};
                memcpy(_c_last_name5133_n.data(), (_c_last_name5133).data(), (_c_last_name5133).length());
                std::string _c_preferred_cust_flag5134 = (it->second)._c_preferred_cust_flag5134;
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag5134_n{};
                memcpy(_c_preferred_cust_flag5134_n.data(), (_c_preferred_cust_flag5134).data(), (_c_preferred_cust_flag5134).length());
                std::string _c_birth_country5138 = (it->second)._c_birth_country5138;
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country5138_n{};
                memcpy(_c_birth_country5138_n.data(), (_c_birth_country5138).data(), (_c_birth_country5138).length());
                std::string _c_login5139 = (it->second)._c_login5139;
                std::array<char, TPCDS_READ_MAX + 1> _c_login5139_n{};
                memcpy(_c_login5139_n.data(), (_c_login5139).data(), (_c_login5139).length());
                std::string _c_email_address5140 = (it->second)._c_email_address5140;
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address5140_n{};
                memcpy(_c_email_address5140_n.data(), (_c_email_address5140).data(), (_c_email_address5140).length());
                int32_t _ws_sold_date_sk5142 = tbl_Filter_TD_7147492_output.getInt32(i, 0);
                int32_t _ws_bill_customer_sk5146 = tbl_Filter_TD_7147492_output.getInt32(i, 1);
                int64_t _ws_ext_discount_amt5164 = tbl_Filter_TD_7147492_output.getInt64(i, 2);
                int64_t _ws_ext_list_price5167 = tbl_Filter_TD_7147492_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_6611510_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id5125_n);
                tbl_JOIN_INNER_TD_6611510_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name5132_n);
                tbl_JOIN_INNER_TD_6611510_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name5133_n);
                tbl_JOIN_INNER_TD_6611510_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag5134_n);
                tbl_JOIN_INNER_TD_6611510_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country5138_n);
                tbl_JOIN_INNER_TD_6611510_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login5139_n);
                tbl_JOIN_INNER_TD_6611510_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address5140_n);
                tbl_JOIN_INNER_TD_6611510_output.setInt32(r, 7, _ws_sold_date_sk5142);
                tbl_JOIN_INNER_TD_6611510_output.setInt64(r, 8, _ws_ext_discount_amt5164);
                tbl_JOIN_INNER_TD_6611510_output.setInt64(r, 9, _ws_ext_list_price5167);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6611510_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6611510_key_rightMajor, SW_JOIN_INNER_TD_6611510_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7147492_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_bill_customer_sk5146_k = tbl_Filter_TD_7147492_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_6611510_key_rightMajor keyA{_ws_bill_customer_sk5146_k};
            int32_t _ws_sold_date_sk5142 = tbl_Filter_TD_7147492_output.getInt32(i, 0);
            int32_t _ws_bill_customer_sk5146 = tbl_Filter_TD_7147492_output.getInt32(i, 1);
            int64_t _ws_ext_discount_amt5164 = tbl_Filter_TD_7147492_output.getInt64(i, 2);
            int64_t _ws_ext_list_price5167 = tbl_Filter_TD_7147492_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_6611510_payload_rightMajor payloadA{_ws_sold_date_sk5142, _ws_bill_customer_sk5146, _ws_ext_discount_amt5164, _ws_ext_list_price5167};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7965326_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk5124_k = tbl_Filter_TD_7965326_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6611510_key_rightMajor{_c_customer_sk5124_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_date_sk5142 = (it->second)._ws_sold_date_sk5142;
                int32_t _ws_bill_customer_sk5146 = (it->second)._ws_bill_customer_sk5146;
                int64_t _ws_ext_discount_amt5164 = (it->second)._ws_ext_discount_amt5164;
                int64_t _ws_ext_list_price5167 = (it->second)._ws_ext_list_price5167;
                int32_t _c_customer_sk5124 = tbl_Filter_TD_7965326_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id5125_n = tbl_Filter_TD_7965326_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_customer_id5125 = std::string(_c_customer_id5125_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name5132_n = tbl_Filter_TD_7965326_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_first_name5132 = std::string(_c_first_name5132_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name5133_n = tbl_Filter_TD_7965326_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_last_name5133 = std::string(_c_last_name5133_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag5134_n = tbl_Filter_TD_7965326_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_preferred_cust_flag5134 = std::string(_c_preferred_cust_flag5134_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country5138_n = tbl_Filter_TD_7965326_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _c_birth_country5138 = std::string(_c_birth_country5138_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_login5139_n = tbl_Filter_TD_7965326_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _c_login5139 = std::string(_c_login5139_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address5140_n = tbl_Filter_TD_7965326_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _c_email_address5140 = std::string(_c_email_address5140_n.data());
                tbl_JOIN_INNER_TD_6611510_output.setInt32(r, 7, _ws_sold_date_sk5142);
                tbl_JOIN_INNER_TD_6611510_output.setInt64(r, 8, _ws_ext_discount_amt5164);
                tbl_JOIN_INNER_TD_6611510_output.setInt64(r, 9, _ws_ext_list_price5167);
                tbl_JOIN_INNER_TD_6611510_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id5125_n);
                tbl_JOIN_INNER_TD_6611510_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name5132_n);
                tbl_JOIN_INNER_TD_6611510_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name5133_n);
                tbl_JOIN_INNER_TD_6611510_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag5134_n);
                tbl_JOIN_INNER_TD_6611510_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country5138_n);
                tbl_JOIN_INNER_TD_6611510_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login5139_n);
                tbl_JOIN_INNER_TD_6611510_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address5140_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6611510_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6611510_output #Row: " << tbl_JOIN_INNER_TD_6611510_output.getNumRow() << std::endl;
}

void SW_Filter_TD_636853(Table &tbl_Aggregate_TD_7692608_output, Table &tbl_Filter_TD_636853_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(year_total#3562) AND (year_total#3562 > 0.00)))
    // Input: ListBuffer(customer_id#3554, year_total#3562)
    // Output: ListBuffer(customer_id#3554, year_total#3562)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_7692608_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _year_total3562 = tbl_Aggregate_TD_7692608_output.getInt64(i, 1);
        if ((_year_total3562!= 0) && (_year_total3562 > 0.00)) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id3554_t = tbl_Aggregate_TD_7692608_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            tbl_Filter_TD_636853_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id3554_t);
            int64_t _year_total3562_t = tbl_Aggregate_TD_7692608_output.getInt64(i, 1);
            tbl_Filter_TD_636853_output.setInt64(r, 1, _year_total3562_t);
            r++;
        }
    }
    tbl_Filter_TD_636853_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_636853_output #Row: " << tbl_Filter_TD_636853_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_6923041_key {
    std::string _c_customer_id4738;
    std::string _c_first_name4745;
    std::string _c_last_name4746;
    std::string _c_preferred_cust_flag4747;
    std::string _c_birth_country4751;
    std::string _c_login4752;
    std::string _c_email_address4753;
    int32_t _d_year4784;
    bool operator==(const SW_Aggregate_TD_6923041_key& other) const { return (_c_customer_id4738 == other._c_customer_id4738) && (_c_first_name4745 == other._c_first_name4745) && (_c_last_name4746 == other._c_last_name4746) && (_c_preferred_cust_flag4747 == other._c_preferred_cust_flag4747) && (_c_birth_country4751 == other._c_birth_country4751) && (_c_login4752 == other._c_login4752) && (_c_email_address4753 == other._c_email_address4753) && (_d_year4784 == other._d_year4784); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_6923041_key> {
    std::size_t operator() (const SW_Aggregate_TD_6923041_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._c_customer_id4738)) + (hash<string>()(k._c_first_name4745)) + (hash<string>()(k._c_last_name4746)) + (hash<string>()(k._c_preferred_cust_flag4747)) + (hash<string>()(k._c_birth_country4751)) + (hash<string>()(k._c_login4752)) + (hash<string>()(k._c_email_address4753)) + (hash<int32_t>()(k._d_year4784));
    }
};
}
struct SW_Aggregate_TD_6923041_payload {
    std::string _customer_id3612;
    std::string _customer_first_name3613;
    std::string _customer_last_name3614;
    std::string _customer_preferred_cust_flag3615;
    int64_t _year_total3620_sum_0;
};
void SW_Aggregate_TD_6923041(Table &tbl_JOIN_INNER_TD_7619669_output, Table &tbl_Aggregate_TD_6923041_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_customer_id#4738, c_first_name#4745, c_last_name#4746, c_preferred_cust_flag#4747, c_birth_country#4751, c_login#4752, c_email_address#4753, d_year#4784, c_customer_id#4738 AS customer_id#3612, c_first_name#4745 AS customer_first_name#3613, c_last_name#4746 AS customer_last_name#3614, c_preferred_cust_flag#4747 AS customer_preferred_cust_flag#3615, MakeDecimal(sum(UnscaledValue(CheckOverflow((promote_precision(cast(ss_ext_list_price#4772 as decimal(8,2))) - promote_precision(cast(ss_ext_discount_amt#4769 as decimal(8,2)))), DecimalType(8,2), true))),18,2) AS year_total#3620)
    // Input: ListBuffer(c_customer_id#4738, c_first_name#4745, c_last_name#4746, c_preferred_cust_flag#4747, c_birth_country#4751, c_login#4752, c_email_address#4753, ss_ext_discount_amt#4769, ss_ext_list_price#4772, d_year#4784)
    // Output: ListBuffer(customer_id#3612, customer_first_name#3613, customer_last_name#3614, customer_preferred_cust_flag#3615, year_total#3620)
    std::unordered_map<SW_Aggregate_TD_6923041_key, SW_Aggregate_TD_6923041_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_7619669_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id4738 = tbl_JOIN_INNER_TD_7619669_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name4745 = tbl_JOIN_INNER_TD_7619669_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name4746 = tbl_JOIN_INNER_TD_7619669_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag4747 = tbl_JOIN_INNER_TD_7619669_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _c_birth_country4751 = tbl_JOIN_INNER_TD_7619669_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _c_login4752 = tbl_JOIN_INNER_TD_7619669_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _c_email_address4753 = tbl_JOIN_INNER_TD_7619669_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        int64_t _ss_ext_discount_amt4769 = tbl_JOIN_INNER_TD_7619669_output.getInt64(i, 7);
        int64_t _ss_ext_list_price4772 = tbl_JOIN_INNER_TD_7619669_output.getInt64(i, 8);
        int32_t _d_year4784 = tbl_JOIN_INNER_TD_7619669_output.getInt32(i, 9);
        SW_Aggregate_TD_6923041_key k{std::string(_c_customer_id4738.data()), std::string(_c_first_name4745.data()), std::string(_c_last_name4746.data()), std::string(_c_preferred_cust_flag4747.data()), std::string(_c_birth_country4751.data()), std::string(_c_login4752.data()), std::string(_c_email_address4753.data()), _d_year4784};
        std::array<char, TPCDS_READ_MAX + 1> _customer_id3612 = _c_customer_id4738;
        std::array<char, TPCDS_READ_MAX + 1> _customer_first_name3613 = _c_first_name4745;
        std::array<char, TPCDS_READ_MAX + 1> _customer_last_name3614 = _c_last_name4746;
        std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag3615 = _c_preferred_cust_flag4747;
        int64_t _year_total3620_sum_0 = (_ss_ext_list_price4772 - _ss_ext_discount_amt4769);
        SW_Aggregate_TD_6923041_payload p{std::string(_customer_id3612.data()), std::string(_customer_first_name3613.data()), std::string(_customer_last_name3614.data()), std::string(_customer_preferred_cust_flag3615.data()), _year_total3620_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._year_total3620_sum_0 + _year_total3620_sum_0;
            p._year_total3620_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _c_customer_id4738 not required in the output table
        // _c_first_name4745 not required in the output table
        // _c_last_name4746 not required in the output table
        // _c_preferred_cust_flag4747 not required in the output table
        // _c_birth_country4751 not required in the output table
        // _c_login4752 not required in the output table
        // _c_email_address4753 not required in the output table
        // _d_year4784 not required in the output table
        std::array<char, TPCDS_READ_MAX + 1> _customer_id3612_n{};
        memcpy(_customer_id3612_n.data(), (it.second)._customer_id3612.data(), (it.second)._customer_id3612.length());
        tbl_Aggregate_TD_6923041_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id3612_n);
        std::array<char, TPCDS_READ_MAX + 1> _customer_first_name3613_n{};
        memcpy(_customer_first_name3613_n.data(), (it.second)._customer_first_name3613.data(), (it.second)._customer_first_name3613.length());
        tbl_Aggregate_TD_6923041_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _customer_first_name3613_n);
        std::array<char, TPCDS_READ_MAX + 1> _customer_last_name3614_n{};
        memcpy(_customer_last_name3614_n.data(), (it.second)._customer_last_name3614.data(), (it.second)._customer_last_name3614.length());
        tbl_Aggregate_TD_6923041_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _customer_last_name3614_n);
        std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag3615_n{};
        memcpy(_customer_preferred_cust_flag3615_n.data(), (it.second)._customer_preferred_cust_flag3615.data(), (it.second)._customer_preferred_cust_flag3615.length());
        tbl_Aggregate_TD_6923041_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _customer_preferred_cust_flag3615_n);
        int64_t _year_total3620 = (it.second)._year_total3620_sum_0;
        tbl_Aggregate_TD_6923041_output.setInt64(r, 4, _year_total3620);
        ++r;
    }
    tbl_Aggregate_TD_6923041_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_6923041_output #Row: " << tbl_Aggregate_TD_6923041_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6520850(Table &tbl_Aggregate_TD_7565087_output, Table &tbl_Filter_TD_6520850_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(year_total#3552) AND (year_total#3552 > 0.00)))
    // Input: ListBuffer(customer_id#3544, year_total#3552)
    // Output: ListBuffer(customer_id#3544, year_total#3552)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_7565087_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _year_total3552 = tbl_Aggregate_TD_7565087_output.getInt64(i, 1);
        if ((_year_total3552!= 0) && (_year_total3552 > 0.00)) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id3544_t = tbl_Aggregate_TD_7565087_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            tbl_Filter_TD_6520850_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id3544_t);
            int64_t _year_total3552_t = tbl_Aggregate_TD_7565087_output.getInt64(i, 1);
            tbl_Filter_TD_6520850_output.setInt64(r, 1, _year_total3552_t);
            r++;
        }
    }
    tbl_Filter_TD_6520850_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6520850_output #Row: " << tbl_Filter_TD_6520850_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5887108_key_leftMajor {
    int32_t _ws_sold_date_sk5142;
    bool operator==(const SW_JOIN_INNER_TD_5887108_key_leftMajor& other) const {
        return ((_ws_sold_date_sk5142 == other._ws_sold_date_sk5142));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5887108_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5887108_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_sold_date_sk5142));
    }
};
}
struct SW_JOIN_INNER_TD_5887108_payload_leftMajor {
    std::string _c_customer_id5125;
    std::string _c_first_name5132;
    std::string _c_last_name5133;
    std::string _c_preferred_cust_flag5134;
    std::string _c_birth_country5138;
    std::string _c_login5139;
    std::string _c_email_address5140;
    int32_t _ws_sold_date_sk5142;
    int64_t _ws_ext_discount_amt5164;
    int64_t _ws_ext_list_price5167;
};
struct SW_JOIN_INNER_TD_5887108_key_rightMajor {
    int32_t _d_date_sk5176;
    bool operator==(const SW_JOIN_INNER_TD_5887108_key_rightMajor& other) const {
        return ((_d_date_sk5176 == other._d_date_sk5176));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5887108_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5887108_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk5176));
    }
};
}
struct SW_JOIN_INNER_TD_5887108_payload_rightMajor {
    int32_t _d_date_sk5176;
    int32_t _d_year5182;
};
void SW_JOIN_INNER_TD_5887108(Table &tbl_JOIN_INNER_TD_6611510_output, Table &tbl_Filter_TD_6644775_output, Table &tbl_JOIN_INNER_TD_5887108_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_sold_date_sk#5142 = d_date_sk#5176))
    // Left Table: ListBuffer(c_customer_id#5125, c_first_name#5132, c_last_name#5133, c_preferred_cust_flag#5134, c_birth_country#5138, c_login#5139, c_email_address#5140, ws_sold_date_sk#5142, ws_ext_discount_amt#5164, ws_ext_list_price#5167)
    // Right Table: ListBuffer(d_date_sk#5176, d_year#5182)
    // Output Table: ListBuffer(c_customer_id#5125, c_first_name#5132, c_last_name#5133, c_preferred_cust_flag#5134, c_birth_country#5138, c_login#5139, c_email_address#5140, ws_ext_discount_amt#5164, ws_ext_list_price#5167, d_year#5182)
    int left_nrow = tbl_JOIN_INNER_TD_6611510_output.getNumRow();
    int right_nrow = tbl_Filter_TD_6644775_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5887108_key_leftMajor, SW_JOIN_INNER_TD_5887108_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_6611510_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_sold_date_sk5142_k = tbl_JOIN_INNER_TD_6611510_output.getInt32(i, 7);
            SW_JOIN_INNER_TD_5887108_key_leftMajor keyA{_ws_sold_date_sk5142_k};
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id5125_n = tbl_JOIN_INNER_TD_6611510_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _c_customer_id5125 = std::string(_c_customer_id5125_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name5132_n = tbl_JOIN_INNER_TD_6611510_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_first_name5132 = std::string(_c_first_name5132_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name5133_n = tbl_JOIN_INNER_TD_6611510_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_last_name5133 = std::string(_c_last_name5133_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag5134_n = tbl_JOIN_INNER_TD_6611510_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_preferred_cust_flag5134 = std::string(_c_preferred_cust_flag5134_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country5138_n = tbl_JOIN_INNER_TD_6611510_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_birth_country5138 = std::string(_c_birth_country5138_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_login5139_n = tbl_JOIN_INNER_TD_6611510_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _c_login5139 = std::string(_c_login5139_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address5140_n = tbl_JOIN_INNER_TD_6611510_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _c_email_address5140 = std::string(_c_email_address5140_n.data());
            int32_t _ws_sold_date_sk5142 = tbl_JOIN_INNER_TD_6611510_output.getInt32(i, 7);
            int64_t _ws_ext_discount_amt5164 = tbl_JOIN_INNER_TD_6611510_output.getInt64(i, 8);
            int64_t _ws_ext_list_price5167 = tbl_JOIN_INNER_TD_6611510_output.getInt64(i, 9);
            SW_JOIN_INNER_TD_5887108_payload_leftMajor payloadA{_c_customer_id5125, _c_first_name5132, _c_last_name5133, _c_preferred_cust_flag5134, _c_birth_country5138, _c_login5139, _c_email_address5140, _ws_sold_date_sk5142, _ws_ext_discount_amt5164, _ws_ext_list_price5167};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6644775_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk5176_k = tbl_Filter_TD_6644775_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5887108_key_leftMajor{_d_date_sk5176_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _c_customer_id5125 = (it->second)._c_customer_id5125;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id5125_n{};
                memcpy(_c_customer_id5125_n.data(), (_c_customer_id5125).data(), (_c_customer_id5125).length());
                std::string _c_first_name5132 = (it->second)._c_first_name5132;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name5132_n{};
                memcpy(_c_first_name5132_n.data(), (_c_first_name5132).data(), (_c_first_name5132).length());
                std::string _c_last_name5133 = (it->second)._c_last_name5133;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name5133_n{};
                memcpy(_c_last_name5133_n.data(), (_c_last_name5133).data(), (_c_last_name5133).length());
                std::string _c_preferred_cust_flag5134 = (it->second)._c_preferred_cust_flag5134;
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag5134_n{};
                memcpy(_c_preferred_cust_flag5134_n.data(), (_c_preferred_cust_flag5134).data(), (_c_preferred_cust_flag5134).length());
                std::string _c_birth_country5138 = (it->second)._c_birth_country5138;
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country5138_n{};
                memcpy(_c_birth_country5138_n.data(), (_c_birth_country5138).data(), (_c_birth_country5138).length());
                std::string _c_login5139 = (it->second)._c_login5139;
                std::array<char, TPCDS_READ_MAX + 1> _c_login5139_n{};
                memcpy(_c_login5139_n.data(), (_c_login5139).data(), (_c_login5139).length());
                std::string _c_email_address5140 = (it->second)._c_email_address5140;
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address5140_n{};
                memcpy(_c_email_address5140_n.data(), (_c_email_address5140).data(), (_c_email_address5140).length());
                int32_t _ws_sold_date_sk5142 = (it->second)._ws_sold_date_sk5142;
                int64_t _ws_ext_discount_amt5164 = (it->second)._ws_ext_discount_amt5164;
                int64_t _ws_ext_list_price5167 = (it->second)._ws_ext_list_price5167;
                int32_t _d_date_sk5176 = tbl_Filter_TD_6644775_output.getInt32(i, 0);
                int32_t _d_year5182 = tbl_Filter_TD_6644775_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_5887108_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id5125_n);
                tbl_JOIN_INNER_TD_5887108_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name5132_n);
                tbl_JOIN_INNER_TD_5887108_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name5133_n);
                tbl_JOIN_INNER_TD_5887108_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag5134_n);
                tbl_JOIN_INNER_TD_5887108_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country5138_n);
                tbl_JOIN_INNER_TD_5887108_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login5139_n);
                tbl_JOIN_INNER_TD_5887108_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address5140_n);
                tbl_JOIN_INNER_TD_5887108_output.setInt64(r, 7, _ws_ext_discount_amt5164);
                tbl_JOIN_INNER_TD_5887108_output.setInt64(r, 8, _ws_ext_list_price5167);
                tbl_JOIN_INNER_TD_5887108_output.setInt32(r, 9, _d_year5182);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5887108_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5887108_key_rightMajor, SW_JOIN_INNER_TD_5887108_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_6644775_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk5176_k = tbl_Filter_TD_6644775_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5887108_key_rightMajor keyA{_d_date_sk5176_k};
            int32_t _d_date_sk5176 = tbl_Filter_TD_6644775_output.getInt32(i, 0);
            int32_t _d_year5182 = tbl_Filter_TD_6644775_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_5887108_payload_rightMajor payloadA{_d_date_sk5176, _d_year5182};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_6611510_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_sold_date_sk5142_k = tbl_JOIN_INNER_TD_6611510_output.getInt32(i, 7);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5887108_key_rightMajor{_ws_sold_date_sk5142_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk5176 = (it->second)._d_date_sk5176;
                int32_t _d_year5182 = (it->second)._d_year5182;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id5125_n = tbl_JOIN_INNER_TD_6611510_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _c_customer_id5125 = std::string(_c_customer_id5125_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name5132_n = tbl_JOIN_INNER_TD_6611510_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_first_name5132 = std::string(_c_first_name5132_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name5133_n = tbl_JOIN_INNER_TD_6611510_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_last_name5133 = std::string(_c_last_name5133_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag5134_n = tbl_JOIN_INNER_TD_6611510_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_preferred_cust_flag5134 = std::string(_c_preferred_cust_flag5134_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country5138_n = tbl_JOIN_INNER_TD_6611510_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_birth_country5138 = std::string(_c_birth_country5138_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_login5139_n = tbl_JOIN_INNER_TD_6611510_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _c_login5139 = std::string(_c_login5139_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address5140_n = tbl_JOIN_INNER_TD_6611510_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _c_email_address5140 = std::string(_c_email_address5140_n.data());
                int32_t _ws_sold_date_sk5142 = tbl_JOIN_INNER_TD_6611510_output.getInt32(i, 7);
                int64_t _ws_ext_discount_amt5164 = tbl_JOIN_INNER_TD_6611510_output.getInt64(i, 8);
                int64_t _ws_ext_list_price5167 = tbl_JOIN_INNER_TD_6611510_output.getInt64(i, 9);
                tbl_JOIN_INNER_TD_5887108_output.setInt32(r, 9, _d_year5182);
                tbl_JOIN_INNER_TD_5887108_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id5125_n);
                tbl_JOIN_INNER_TD_5887108_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name5132_n);
                tbl_JOIN_INNER_TD_5887108_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name5133_n);
                tbl_JOIN_INNER_TD_5887108_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag5134_n);
                tbl_JOIN_INNER_TD_5887108_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country5138_n);
                tbl_JOIN_INNER_TD_5887108_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login5139_n);
                tbl_JOIN_INNER_TD_5887108_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address5140_n);
                tbl_JOIN_INNER_TD_5887108_output.setInt64(r, 7, _ws_ext_discount_amt5164);
                tbl_JOIN_INNER_TD_5887108_output.setInt64(r, 8, _ws_ext_list_price5167);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5887108_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5887108_output #Row: " << tbl_JOIN_INNER_TD_5887108_output.getNumRow() << std::endl;
}

void SW_Project_TD_5144516(Table &tbl_Filter_TD_636853_output, Table &tbl_Project_TD_5144516_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(customer_id#3554 AS customer_id#5045, year_total#3562 AS year_total#5053)
    // Input: ListBuffer(customer_id#3554, year_total#3562)
    // Output: ListBuffer(customer_id#5045, year_total#5053)
    int nrow1 = tbl_Filter_TD_636853_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _customer_id3554 = tbl_Filter_TD_636853_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        int64_t _year_total3562 = tbl_Filter_TD_636853_output.getInt64(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _customer_id5045 = _customer_id3554;
        tbl_Project_TD_5144516_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 0, _customer_id5045);
        int64_t _year_total5053 = _year_total3562;
        tbl_Project_TD_5144516_output.setInt64(i, 1, _year_total5053);
    }
    tbl_Project_TD_5144516_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_5144516_output #Row: " << tbl_Project_TD_5144516_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5762133_key_leftMajor {
    std::string _customer_id3544;
    bool operator==(const SW_JOIN_INNER_TD_5762133_key_leftMajor& other) const {
        return ((_customer_id3544 == other._customer_id3544));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5762133_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5762133_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._customer_id3544));
    }
};
}
struct SW_JOIN_INNER_TD_5762133_payload_leftMajor {
    std::string _customer_id3544;
    int64_t _year_total3552;
};
struct SW_JOIN_INNER_TD_5762133_key_rightMajor {
    std::string _customer_id3612;
    bool operator==(const SW_JOIN_INNER_TD_5762133_key_rightMajor& other) const {
        return ((_customer_id3612 == other._customer_id3612));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5762133_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5762133_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._customer_id3612));
    }
};
}
struct SW_JOIN_INNER_TD_5762133_payload_rightMajor {
    std::string _customer_id3612;
    std::string _customer_first_name3613;
    std::string _customer_last_name3614;
    std::string _customer_preferred_cust_flag3615;
    int64_t _year_total3620;
};
void SW_JOIN_INNER_TD_5762133(Table &tbl_Filter_TD_6520850_output, Table &tbl_Aggregate_TD_6923041_output, Table &tbl_JOIN_INNER_TD_5762133_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((customer_id#3612 = customer_id#3544))
    // Left Table: ListBuffer(customer_id#3544, year_total#3552)
    // Right Table: ListBuffer(customer_id#3612, customer_first_name#3613, customer_last_name#3614, customer_preferred_cust_flag#3615, year_total#3620)
    // Output Table: ListBuffer(customer_id#3544, year_total#3552, customer_id#3612, customer_first_name#3613, customer_last_name#3614, customer_preferred_cust_flag#3615, year_total#3620)
    int left_nrow = tbl_Filter_TD_6520850_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_6923041_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5762133_key_leftMajor, SW_JOIN_INNER_TD_5762133_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_6520850_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id3544_k_n = tbl_Filter_TD_6520850_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id3544_k = std::string(_customer_id3544_k_n.data());
            SW_JOIN_INNER_TD_5762133_key_leftMajor keyA{_customer_id3544_k};
            std::array<char, TPCDS_READ_MAX + 1> _customer_id3544_n = tbl_Filter_TD_6520850_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id3544 = std::string(_customer_id3544_n.data());
            int64_t _year_total3552 = tbl_Filter_TD_6520850_output.getInt64(i, 1);
            SW_JOIN_INNER_TD_5762133_payload_leftMajor payloadA{_customer_id3544, _year_total3552};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_6923041_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id3612_k_n = tbl_Aggregate_TD_6923041_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id3612_k = std::string(_customer_id3612_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5762133_key_leftMajor{_customer_id3612_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _customer_id3544 = (it->second)._customer_id3544;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id3544_n{};
                memcpy(_customer_id3544_n.data(), (_customer_id3544).data(), (_customer_id3544).length());
                int64_t _year_total3552 = (it->second)._year_total3552;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id3612_n = tbl_Aggregate_TD_6923041_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _customer_id3612 = std::string(_customer_id3612_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_first_name3613_n = tbl_Aggregate_TD_6923041_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _customer_first_name3613 = std::string(_customer_first_name3613_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_last_name3614_n = tbl_Aggregate_TD_6923041_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _customer_last_name3614 = std::string(_customer_last_name3614_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag3615_n = tbl_Aggregate_TD_6923041_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _customer_preferred_cust_flag3615 = std::string(_customer_preferred_cust_flag3615_n.data());
                int64_t _year_total3620 = tbl_Aggregate_TD_6923041_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_5762133_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id3544_n);
                tbl_JOIN_INNER_TD_5762133_output.setInt64(r, 1, _year_total3552);
                tbl_JOIN_INNER_TD_5762133_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _customer_id3612_n);
                tbl_JOIN_INNER_TD_5762133_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _customer_first_name3613_n);
                tbl_JOIN_INNER_TD_5762133_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _customer_last_name3614_n);
                tbl_JOIN_INNER_TD_5762133_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _customer_preferred_cust_flag3615_n);
                tbl_JOIN_INNER_TD_5762133_output.setInt64(r, 6, _year_total3620);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5762133_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5762133_key_rightMajor, SW_JOIN_INNER_TD_5762133_payload_rightMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_6923041_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id3612_k_n = tbl_Aggregate_TD_6923041_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id3612_k = std::string(_customer_id3612_k_n.data());
            SW_JOIN_INNER_TD_5762133_key_rightMajor keyA{_customer_id3612_k};
            std::array<char, TPCDS_READ_MAX + 1> _customer_id3612_n = tbl_Aggregate_TD_6923041_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id3612 = std::string(_customer_id3612_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_first_name3613_n = tbl_Aggregate_TD_6923041_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _customer_first_name3613 = std::string(_customer_first_name3613_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_last_name3614_n = tbl_Aggregate_TD_6923041_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _customer_last_name3614 = std::string(_customer_last_name3614_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag3615_n = tbl_Aggregate_TD_6923041_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _customer_preferred_cust_flag3615 = std::string(_customer_preferred_cust_flag3615_n.data());
            int64_t _year_total3620 = tbl_Aggregate_TD_6923041_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_5762133_payload_rightMajor payloadA{_customer_id3612, _customer_first_name3613, _customer_last_name3614, _customer_preferred_cust_flag3615, _year_total3620};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6520850_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id3544_k_n = tbl_Filter_TD_6520850_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id3544_k = std::string(_customer_id3544_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5762133_key_rightMajor{_customer_id3544_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _customer_id3612 = (it->second)._customer_id3612;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id3612_n{};
                memcpy(_customer_id3612_n.data(), (_customer_id3612).data(), (_customer_id3612).length());
                std::string _customer_first_name3613 = (it->second)._customer_first_name3613;
                std::array<char, TPCDS_READ_MAX + 1> _customer_first_name3613_n{};
                memcpy(_customer_first_name3613_n.data(), (_customer_first_name3613).data(), (_customer_first_name3613).length());
                std::string _customer_last_name3614 = (it->second)._customer_last_name3614;
                std::array<char, TPCDS_READ_MAX + 1> _customer_last_name3614_n{};
                memcpy(_customer_last_name3614_n.data(), (_customer_last_name3614).data(), (_customer_last_name3614).length());
                std::string _customer_preferred_cust_flag3615 = (it->second)._customer_preferred_cust_flag3615;
                std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag3615_n{};
                memcpy(_customer_preferred_cust_flag3615_n.data(), (_customer_preferred_cust_flag3615).data(), (_customer_preferred_cust_flag3615).length());
                int64_t _year_total3620 = (it->second)._year_total3620;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id3544_n = tbl_Filter_TD_6520850_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _customer_id3544 = std::string(_customer_id3544_n.data());
                int64_t _year_total3552 = tbl_Filter_TD_6520850_output.getInt64(i, 1);
                tbl_JOIN_INNER_TD_5762133_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _customer_id3612_n);
                tbl_JOIN_INNER_TD_5762133_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _customer_first_name3613_n);
                tbl_JOIN_INNER_TD_5762133_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _customer_last_name3614_n);
                tbl_JOIN_INNER_TD_5762133_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _customer_preferred_cust_flag3615_n);
                tbl_JOIN_INNER_TD_5762133_output.setInt64(r, 6, _year_total3620);
                tbl_JOIN_INNER_TD_5762133_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id3544_n);
                tbl_JOIN_INNER_TD_5762133_output.setInt64(r, 1, _year_total3552);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5762133_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5762133_output #Row: " << tbl_JOIN_INNER_TD_5762133_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_4905961_key {
    std::string _c_customer_id5125;
    std::string _c_first_name5132;
    std::string _c_last_name5133;
    std::string _c_preferred_cust_flag5134;
    std::string _c_birth_country5138;
    std::string _c_login5139;
    std::string _c_email_address5140;
    int32_t _d_year5182;
    bool operator==(const SW_Aggregate_TD_4905961_key& other) const { return (_c_customer_id5125 == other._c_customer_id5125) && (_c_first_name5132 == other._c_first_name5132) && (_c_last_name5133 == other._c_last_name5133) && (_c_preferred_cust_flag5134 == other._c_preferred_cust_flag5134) && (_c_birth_country5138 == other._c_birth_country5138) && (_c_login5139 == other._c_login5139) && (_c_email_address5140 == other._c_email_address5140) && (_d_year5182 == other._d_year5182); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_4905961_key> {
    std::size_t operator() (const SW_Aggregate_TD_4905961_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._c_customer_id5125)) + (hash<string>()(k._c_first_name5132)) + (hash<string>()(k._c_last_name5133)) + (hash<string>()(k._c_preferred_cust_flag5134)) + (hash<string>()(k._c_birth_country5138)) + (hash<string>()(k._c_login5139)) + (hash<string>()(k._c_email_address5140)) + (hash<int32_t>()(k._d_year5182));
    }
};
}
struct SW_Aggregate_TD_4905961_payload {
    std::string _customer_id3632;
    int64_t _year_total3640_sum_0;
};
void SW_Aggregate_TD_4905961(Table &tbl_JOIN_INNER_TD_5887108_output, Table &tbl_Aggregate_TD_4905961_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_customer_id#5125, c_first_name#5132, c_last_name#5133, c_preferred_cust_flag#5134, c_birth_country#5138, c_login#5139, c_email_address#5140, d_year#5182, c_customer_id#5125 AS customer_id#3632, MakeDecimal(sum(UnscaledValue(CheckOverflow((promote_precision(cast(ws_ext_list_price#5167 as decimal(8,2))) - promote_precision(cast(ws_ext_discount_amt#5164 as decimal(8,2)))), DecimalType(8,2), true))),18,2) AS year_total#3640)
    // Input: ListBuffer(c_customer_id#5125, c_first_name#5132, c_last_name#5133, c_preferred_cust_flag#5134, c_birth_country#5138, c_login#5139, c_email_address#5140, ws_ext_discount_amt#5164, ws_ext_list_price#5167, d_year#5182)
    // Output: ListBuffer(customer_id#3632, year_total#3640)
    std::unordered_map<SW_Aggregate_TD_4905961_key, SW_Aggregate_TD_4905961_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_5887108_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id5125 = tbl_JOIN_INNER_TD_5887108_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name5132 = tbl_JOIN_INNER_TD_5887108_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name5133 = tbl_JOIN_INNER_TD_5887108_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag5134 = tbl_JOIN_INNER_TD_5887108_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _c_birth_country5138 = tbl_JOIN_INNER_TD_5887108_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _c_login5139 = tbl_JOIN_INNER_TD_5887108_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _c_email_address5140 = tbl_JOIN_INNER_TD_5887108_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        int64_t _ws_ext_discount_amt5164 = tbl_JOIN_INNER_TD_5887108_output.getInt64(i, 7);
        int64_t _ws_ext_list_price5167 = tbl_JOIN_INNER_TD_5887108_output.getInt64(i, 8);
        int32_t _d_year5182 = tbl_JOIN_INNER_TD_5887108_output.getInt32(i, 9);
        SW_Aggregate_TD_4905961_key k{std::string(_c_customer_id5125.data()), std::string(_c_first_name5132.data()), std::string(_c_last_name5133.data()), std::string(_c_preferred_cust_flag5134.data()), std::string(_c_birth_country5138.data()), std::string(_c_login5139.data()), std::string(_c_email_address5140.data()), _d_year5182};
        std::array<char, TPCDS_READ_MAX + 1> _customer_id3632 = _c_customer_id5125;
        int64_t _year_total3640_sum_0 = (_ws_ext_list_price5167 - _ws_ext_discount_amt5164);
        SW_Aggregate_TD_4905961_payload p{std::string(_customer_id3632.data()), _year_total3640_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._year_total3640_sum_0 + _year_total3640_sum_0;
            p._year_total3640_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _c_customer_id5125 not required in the output table
        // _c_first_name5132 not required in the output table
        // _c_last_name5133 not required in the output table
        // _c_preferred_cust_flag5134 not required in the output table
        // _c_birth_country5138 not required in the output table
        // _c_login5139 not required in the output table
        // _c_email_address5140 not required in the output table
        // _d_year5182 not required in the output table
        std::array<char, TPCDS_READ_MAX + 1> _customer_id3632_n{};
        memcpy(_customer_id3632_n.data(), (it.second)._customer_id3632.data(), (it.second)._customer_id3632.length());
        tbl_Aggregate_TD_4905961_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id3632_n);
        int64_t _year_total3640 = (it.second)._year_total3640_sum_0;
        tbl_Aggregate_TD_4905961_output.setInt64(r, 1, _year_total3640);
        ++r;
    }
    tbl_Aggregate_TD_4905961_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_4905961_output #Row: " << tbl_Aggregate_TD_4905961_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4534120_key_leftMajor {
    std::string _customer_id3544;
    bool operator==(const SW_JOIN_INNER_TD_4534120_key_leftMajor& other) const {
        return ((_customer_id3544 == other._customer_id3544));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4534120_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4534120_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._customer_id3544));
    }
};
}
struct SW_JOIN_INNER_TD_4534120_payload_leftMajor {
    std::string _customer_id3544;
    int64_t _year_total3552;
    std::string _customer_id3612;
    std::string _customer_first_name3613;
    std::string _customer_last_name3614;
    std::string _customer_preferred_cust_flag3615;
    int64_t _year_total3620;
};
struct SW_JOIN_INNER_TD_4534120_key_rightMajor {
    std::string _customer_id5045;
    bool operator==(const SW_JOIN_INNER_TD_4534120_key_rightMajor& other) const {
        return ((_customer_id5045 == other._customer_id5045));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4534120_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4534120_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._customer_id5045));
    }
};
}
struct SW_JOIN_INNER_TD_4534120_payload_rightMajor {
    std::string _customer_id5045;
    int64_t _year_total5053;
};
void SW_JOIN_INNER_TD_4534120(Table &tbl_JOIN_INNER_TD_5762133_output, Table &tbl_Project_TD_5144516_output, Table &tbl_JOIN_INNER_TD_4534120_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((customer_id#3544 = customer_id#5045))
    // Left Table: ListBuffer(customer_id#3544, year_total#3552, customer_id#3612, customer_first_name#3613, customer_last_name#3614, customer_preferred_cust_flag#3615, year_total#3620)
    // Right Table: ListBuffer(customer_id#5045, year_total#5053)
    // Output Table: ListBuffer(customer_id#3544, year_total#3552, customer_id#3612, customer_first_name#3613, customer_last_name#3614, customer_preferred_cust_flag#3615, year_total#3620, year_total#5053)
    int left_nrow = tbl_JOIN_INNER_TD_5762133_output.getNumRow();
    int right_nrow = tbl_Project_TD_5144516_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4534120_key_leftMajor, SW_JOIN_INNER_TD_4534120_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_5762133_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id3544_k_n = tbl_JOIN_INNER_TD_5762133_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id3544_k = std::string(_customer_id3544_k_n.data());
            SW_JOIN_INNER_TD_4534120_key_leftMajor keyA{_customer_id3544_k};
            std::array<char, TPCDS_READ_MAX + 1> _customer_id3544_n = tbl_JOIN_INNER_TD_5762133_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id3544 = std::string(_customer_id3544_n.data());
            int64_t _year_total3552 = tbl_JOIN_INNER_TD_5762133_output.getInt64(i, 1);
            std::array<char, TPCDS_READ_MAX + 1> _customer_id3612_n = tbl_JOIN_INNER_TD_5762133_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _customer_id3612 = std::string(_customer_id3612_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_first_name3613_n = tbl_JOIN_INNER_TD_5762133_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _customer_first_name3613 = std::string(_customer_first_name3613_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_last_name3614_n = tbl_JOIN_INNER_TD_5762133_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _customer_last_name3614 = std::string(_customer_last_name3614_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag3615_n = tbl_JOIN_INNER_TD_5762133_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _customer_preferred_cust_flag3615 = std::string(_customer_preferred_cust_flag3615_n.data());
            int64_t _year_total3620 = tbl_JOIN_INNER_TD_5762133_output.getInt64(i, 6);
            SW_JOIN_INNER_TD_4534120_payload_leftMajor payloadA{_customer_id3544, _year_total3552, _customer_id3612, _customer_first_name3613, _customer_last_name3614, _customer_preferred_cust_flag3615, _year_total3620};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Project_TD_5144516_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id5045_k_n = tbl_Project_TD_5144516_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id5045_k = std::string(_customer_id5045_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4534120_key_leftMajor{_customer_id5045_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _customer_id3544 = (it->second)._customer_id3544;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id3544_n{};
                memcpy(_customer_id3544_n.data(), (_customer_id3544).data(), (_customer_id3544).length());
                int64_t _year_total3552 = (it->second)._year_total3552;
                std::string _customer_id3612 = (it->second)._customer_id3612;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id3612_n{};
                memcpy(_customer_id3612_n.data(), (_customer_id3612).data(), (_customer_id3612).length());
                std::string _customer_first_name3613 = (it->second)._customer_first_name3613;
                std::array<char, TPCDS_READ_MAX + 1> _customer_first_name3613_n{};
                memcpy(_customer_first_name3613_n.data(), (_customer_first_name3613).data(), (_customer_first_name3613).length());
                std::string _customer_last_name3614 = (it->second)._customer_last_name3614;
                std::array<char, TPCDS_READ_MAX + 1> _customer_last_name3614_n{};
                memcpy(_customer_last_name3614_n.data(), (_customer_last_name3614).data(), (_customer_last_name3614).length());
                std::string _customer_preferred_cust_flag3615 = (it->second)._customer_preferred_cust_flag3615;
                std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag3615_n{};
                memcpy(_customer_preferred_cust_flag3615_n.data(), (_customer_preferred_cust_flag3615).data(), (_customer_preferred_cust_flag3615).length());
                int64_t _year_total3620 = (it->second)._year_total3620;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id5045_n = tbl_Project_TD_5144516_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _customer_id5045 = std::string(_customer_id5045_n.data());
                int64_t _year_total5053 = tbl_Project_TD_5144516_output.getInt64(i, 1);
                tbl_JOIN_INNER_TD_4534120_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id3544_n);
                tbl_JOIN_INNER_TD_4534120_output.setInt64(r, 1, _year_total3552);
                tbl_JOIN_INNER_TD_4534120_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _customer_id3612_n);
                tbl_JOIN_INNER_TD_4534120_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _customer_first_name3613_n);
                tbl_JOIN_INNER_TD_4534120_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _customer_last_name3614_n);
                tbl_JOIN_INNER_TD_4534120_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _customer_preferred_cust_flag3615_n);
                tbl_JOIN_INNER_TD_4534120_output.setInt64(r, 6, _year_total3620);
                tbl_JOIN_INNER_TD_4534120_output.setInt64(r, 7, _year_total5053);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4534120_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4534120_key_rightMajor, SW_JOIN_INNER_TD_4534120_payload_rightMajor> ht1;
        int nrow1 = tbl_Project_TD_5144516_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id5045_k_n = tbl_Project_TD_5144516_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id5045_k = std::string(_customer_id5045_k_n.data());
            SW_JOIN_INNER_TD_4534120_key_rightMajor keyA{_customer_id5045_k};
            std::array<char, TPCDS_READ_MAX + 1> _customer_id5045_n = tbl_Project_TD_5144516_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id5045 = std::string(_customer_id5045_n.data());
            int64_t _year_total5053 = tbl_Project_TD_5144516_output.getInt64(i, 1);
            SW_JOIN_INNER_TD_4534120_payload_rightMajor payloadA{_customer_id5045, _year_total5053};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_5762133_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id3544_k_n = tbl_JOIN_INNER_TD_5762133_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id3544_k = std::string(_customer_id3544_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4534120_key_rightMajor{_customer_id3544_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _customer_id5045 = (it->second)._customer_id5045;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id5045_n{};
                memcpy(_customer_id5045_n.data(), (_customer_id5045).data(), (_customer_id5045).length());
                int64_t _year_total5053 = (it->second)._year_total5053;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id3544_n = tbl_JOIN_INNER_TD_5762133_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _customer_id3544 = std::string(_customer_id3544_n.data());
                int64_t _year_total3552 = tbl_JOIN_INNER_TD_5762133_output.getInt64(i, 1);
                std::array<char, TPCDS_READ_MAX + 1> _customer_id3612_n = tbl_JOIN_INNER_TD_5762133_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _customer_id3612 = std::string(_customer_id3612_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_first_name3613_n = tbl_JOIN_INNER_TD_5762133_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _customer_first_name3613 = std::string(_customer_first_name3613_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_last_name3614_n = tbl_JOIN_INNER_TD_5762133_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _customer_last_name3614 = std::string(_customer_last_name3614_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag3615_n = tbl_JOIN_INNER_TD_5762133_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _customer_preferred_cust_flag3615 = std::string(_customer_preferred_cust_flag3615_n.data());
                int64_t _year_total3620 = tbl_JOIN_INNER_TD_5762133_output.getInt64(i, 6);
                tbl_JOIN_INNER_TD_4534120_output.setInt64(r, 7, _year_total5053);
                tbl_JOIN_INNER_TD_4534120_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id3544_n);
                tbl_JOIN_INNER_TD_4534120_output.setInt64(r, 1, _year_total3552);
                tbl_JOIN_INNER_TD_4534120_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _customer_id3612_n);
                tbl_JOIN_INNER_TD_4534120_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _customer_first_name3613_n);
                tbl_JOIN_INNER_TD_4534120_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _customer_last_name3614_n);
                tbl_JOIN_INNER_TD_4534120_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _customer_preferred_cust_flag3615_n);
                tbl_JOIN_INNER_TD_4534120_output.setInt64(r, 6, _year_total3620);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4534120_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4534120_output #Row: " << tbl_JOIN_INNER_TD_4534120_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_3907935_key_leftMajor {
    std::string _customer_id3544;
    bool operator==(const SW_JOIN_INNER_TD_3907935_key_leftMajor& other) const {
        return ((_customer_id3544 == other._customer_id3544));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3907935_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3907935_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._customer_id3544));
    }
};
}
struct SW_JOIN_INNER_TD_3907935_payload_leftMajor {
    std::string _customer_id3544;
    int64_t _year_total3552;
    std::string _customer_id3612;
    std::string _customer_first_name3613;
    std::string _customer_last_name3614;
    std::string _customer_preferred_cust_flag3615;
    int64_t _year_total3620;
    int64_t _year_total5053;
};
struct SW_JOIN_INNER_TD_3907935_key_rightMajor {
    std::string _customer_id3632;
    bool operator==(const SW_JOIN_INNER_TD_3907935_key_rightMajor& other) const {
        return ((_customer_id3632 == other._customer_id3632));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3907935_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3907935_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._customer_id3632));
    }
};
}
struct SW_JOIN_INNER_TD_3907935_payload_rightMajor {
    std::string _customer_id3632;
    int64_t _year_total3640;
};
void SW_JOIN_INNER_TD_3907935(Table &tbl_JOIN_INNER_TD_4534120_output, Table &tbl_Aggregate_TD_4905961_output, Table &tbl_JOIN_INNER_TD_3907935_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((customer_id#3544 = customer_id#3632) AND (CASE WHEN (year_total#5053 > 0.00) THEN CheckOverflow((promote_precision(year_total#3640) / promote_precision(year_total#5053)), DecimalType(38,20), true) ELSE 0E-20 END > CASE WHEN (year_total#3552 > 0.00) THEN CheckOverflow((promote_precision(year_total#3620) / promote_precision(year_total#3552)), DecimalType(38,20), true) ELSE 0E-20 END)))
    // Left Table: ListBuffer(customer_id#3544, year_total#3552, customer_id#3612, customer_first_name#3613, customer_last_name#3614, customer_preferred_cust_flag#3615, year_total#3620, year_total#5053)
    // Right Table: ListBuffer(customer_id#3632, year_total#3640)
    // Output Table: ListBuffer(customer_id#3612, customer_first_name#3613, customer_last_name#3614, customer_preferred_cust_flag#3615)
    int left_nrow = tbl_JOIN_INNER_TD_4534120_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_4905961_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3907935_key_leftMajor, SW_JOIN_INNER_TD_3907935_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_4534120_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id3544_k_n = tbl_JOIN_INNER_TD_4534120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id3544_k = std::string(_customer_id3544_k_n.data());
            SW_JOIN_INNER_TD_3907935_key_leftMajor keyA{_customer_id3544_k};
            std::array<char, TPCDS_READ_MAX + 1> _customer_id3544_n = tbl_JOIN_INNER_TD_4534120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id3544 = std::string(_customer_id3544_n.data());
            int64_t _year_total3552 = tbl_JOIN_INNER_TD_4534120_output.getInt64(i, 1);
            std::array<char, TPCDS_READ_MAX + 1> _customer_id3612_n = tbl_JOIN_INNER_TD_4534120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _customer_id3612 = std::string(_customer_id3612_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_first_name3613_n = tbl_JOIN_INNER_TD_4534120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _customer_first_name3613 = std::string(_customer_first_name3613_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_last_name3614_n = tbl_JOIN_INNER_TD_4534120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _customer_last_name3614 = std::string(_customer_last_name3614_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag3615_n = tbl_JOIN_INNER_TD_4534120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _customer_preferred_cust_flag3615 = std::string(_customer_preferred_cust_flag3615_n.data());
            int64_t _year_total3620 = tbl_JOIN_INNER_TD_4534120_output.getInt64(i, 6);
            int64_t _year_total5053 = tbl_JOIN_INNER_TD_4534120_output.getInt64(i, 7);
            SW_JOIN_INNER_TD_3907935_payload_leftMajor payloadA{_customer_id3544, _year_total3552, _customer_id3612, _customer_first_name3613, _customer_last_name3614, _customer_preferred_cust_flag3615, _year_total3620, _year_total5053};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_4905961_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id3632_k_n = tbl_Aggregate_TD_4905961_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id3632_k = std::string(_customer_id3632_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3907935_key_leftMajor{_customer_id3632_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _customer_id3544 = (it->second)._customer_id3544;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id3544_n{};
                memcpy(_customer_id3544_n.data(), (_customer_id3544).data(), (_customer_id3544).length());
                int64_t _year_total3552 = (it->second)._year_total3552;
                std::string _customer_id3612 = (it->second)._customer_id3612;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id3612_n{};
                memcpy(_customer_id3612_n.data(), (_customer_id3612).data(), (_customer_id3612).length());
                std::string _customer_first_name3613 = (it->second)._customer_first_name3613;
                std::array<char, TPCDS_READ_MAX + 1> _customer_first_name3613_n{};
                memcpy(_customer_first_name3613_n.data(), (_customer_first_name3613).data(), (_customer_first_name3613).length());
                std::string _customer_last_name3614 = (it->second)._customer_last_name3614;
                std::array<char, TPCDS_READ_MAX + 1> _customer_last_name3614_n{};
                memcpy(_customer_last_name3614_n.data(), (_customer_last_name3614).data(), (_customer_last_name3614).length());
                std::string _customer_preferred_cust_flag3615 = (it->second)._customer_preferred_cust_flag3615;
                std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag3615_n{};
                memcpy(_customer_preferred_cust_flag3615_n.data(), (_customer_preferred_cust_flag3615).data(), (_customer_preferred_cust_flag3615).length());
                int64_t _year_total3620 = (it->second)._year_total3620;
                int64_t _year_total5053 = (it->second)._year_total5053;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id3632_n = tbl_Aggregate_TD_4905961_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _customer_id3632 = std::string(_customer_id3632_n.data());
                int64_t _year_total3640 = tbl_Aggregate_TD_4905961_output.getInt64(i, 1);
                tbl_JOIN_INNER_TD_3907935_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id3612_n);
                tbl_JOIN_INNER_TD_3907935_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _customer_first_name3613_n);
                tbl_JOIN_INNER_TD_3907935_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _customer_last_name3614_n);
                tbl_JOIN_INNER_TD_3907935_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _customer_preferred_cust_flag3615_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3907935_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3907935_key_rightMajor, SW_JOIN_INNER_TD_3907935_payload_rightMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_4905961_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id3632_k_n = tbl_Aggregate_TD_4905961_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id3632_k = std::string(_customer_id3632_k_n.data());
            SW_JOIN_INNER_TD_3907935_key_rightMajor keyA{_customer_id3632_k};
            std::array<char, TPCDS_READ_MAX + 1> _customer_id3632_n = tbl_Aggregate_TD_4905961_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id3632 = std::string(_customer_id3632_n.data());
            int64_t _year_total3640 = tbl_Aggregate_TD_4905961_output.getInt64(i, 1);
            SW_JOIN_INNER_TD_3907935_payload_rightMajor payloadA{_customer_id3632, _year_total3640};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_4534120_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id3544_k_n = tbl_JOIN_INNER_TD_4534120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id3544_k = std::string(_customer_id3544_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3907935_key_rightMajor{_customer_id3544_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _customer_id3632 = (it->second)._customer_id3632;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id3632_n{};
                memcpy(_customer_id3632_n.data(), (_customer_id3632).data(), (_customer_id3632).length());
                int64_t _year_total3640 = (it->second)._year_total3640;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id3544_n = tbl_JOIN_INNER_TD_4534120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _customer_id3544 = std::string(_customer_id3544_n.data());
                int64_t _year_total3552 = tbl_JOIN_INNER_TD_4534120_output.getInt64(i, 1);
                std::array<char, TPCDS_READ_MAX + 1> _customer_id3612_n = tbl_JOIN_INNER_TD_4534120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _customer_id3612 = std::string(_customer_id3612_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_first_name3613_n = tbl_JOIN_INNER_TD_4534120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _customer_first_name3613 = std::string(_customer_first_name3613_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_last_name3614_n = tbl_JOIN_INNER_TD_4534120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _customer_last_name3614 = std::string(_customer_last_name3614_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag3615_n = tbl_JOIN_INNER_TD_4534120_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _customer_preferred_cust_flag3615 = std::string(_customer_preferred_cust_flag3615_n.data());
                int64_t _year_total3620 = tbl_JOIN_INNER_TD_4534120_output.getInt64(i, 6);
                int64_t _year_total5053 = tbl_JOIN_INNER_TD_4534120_output.getInt64(i, 7);
                tbl_JOIN_INNER_TD_3907935_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id3612_n);
                tbl_JOIN_INNER_TD_3907935_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _customer_first_name3613_n);
                tbl_JOIN_INNER_TD_3907935_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _customer_last_name3614_n);
                tbl_JOIN_INNER_TD_3907935_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _customer_preferred_cust_flag3615_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3907935_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_3907935_output #Row: " << tbl_JOIN_INNER_TD_3907935_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2445395(Table &tbl_JOIN_INNER_TD_3907935_output, Table &tbl_Sort_TD_2445395_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(customer_id#3612 ASC NULLS FIRST, customer_first_name#3613 ASC NULLS FIRST, customer_last_name#3614 ASC NULLS FIRST, customer_preferred_cust_flag#3615 ASC NULLS FIRST)
    // Input: ListBuffer(customer_id#3612, customer_first_name#3613, customer_last_name#3614, customer_preferred_cust_flag#3615)
    // Output: ListBuffer(customer_id#3612, customer_first_name#3613, customer_last_name#3614, customer_preferred_cust_flag#3615)
    struct SW_Sort_TD_2445395Row {
        std::string _customer_id3612;
        std::string _customer_first_name3613;
        std::string _customer_last_name3614;
        std::string _customer_preferred_cust_flag3615;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2445395Row& a, const SW_Sort_TD_2445395Row& b) const { return 
 (a._customer_id3612 < b._customer_id3612) || 
 ((a._customer_id3612 == b._customer_id3612) && (a._customer_first_name3613 < b._customer_first_name3613)) || 
 ((a._customer_id3612 == b._customer_id3612) && (a._customer_first_name3613 == b._customer_first_name3613) && (a._customer_last_name3614 < b._customer_last_name3614)) || 
 ((a._customer_id3612 == b._customer_id3612) && (a._customer_first_name3613 == b._customer_first_name3613) && (a._customer_last_name3614 == b._customer_last_name3614) && (a._customer_preferred_cust_flag3615 < b._customer_preferred_cust_flag3615)); 
}
    }SW_Sort_TD_2445395_order; 

    int nrow1 = tbl_JOIN_INNER_TD_3907935_output.getNumRow();
    std::vector<SW_Sort_TD_2445395Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _customer_id3612 = tbl_JOIN_INNER_TD_3907935_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _customer_first_name3613 = tbl_JOIN_INNER_TD_3907935_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _customer_last_name3614 = tbl_JOIN_INNER_TD_3907935_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag3615 = tbl_JOIN_INNER_TD_3907935_output.getcharN<char, TPCDS_READ_MAX +1>(i, 3);
        SW_Sort_TD_2445395Row t = {std::string(_customer_id3612.data()),std::string(_customer_first_name3613.data()),std::string(_customer_last_name3614.data()),std::string(_customer_preferred_cust_flag3615.data())};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2445395_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _customer_id3612{};
        memcpy(_customer_id3612.data(), (it._customer_id3612).data(), (it._customer_id3612).length());
        tbl_Sort_TD_2445395_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _customer_id3612);
        std::array<char, TPCDS_READ_MAX + 1> _customer_first_name3613{};
        memcpy(_customer_first_name3613.data(), (it._customer_first_name3613).data(), (it._customer_first_name3613).length());
        tbl_Sort_TD_2445395_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _customer_first_name3613);
        std::array<char, TPCDS_READ_MAX + 1> _customer_last_name3614{};
        memcpy(_customer_last_name3614.data(), (it._customer_last_name3614).data(), (it._customer_last_name3614).length());
        tbl_Sort_TD_2445395_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _customer_last_name3614);
        std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag3615{};
        memcpy(_customer_preferred_cust_flag3615.data(), (it._customer_preferred_cust_flag3615).data(), (it._customer_preferred_cust_flag3615).length());
        tbl_Sort_TD_2445395_output.setcharN<char, TPCDS_READ_MAX +1>(r, 3, _customer_preferred_cust_flag3615);
        ++r;
    }
    tbl_Sort_TD_2445395_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2445395_output #Row: " << tbl_Sort_TD_2445395_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1243487(Table &tbl_Sort_TD_2445395_output, Table &tbl_LocalLimit_TD_1243487_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(customer_id#3612, customer_first_name#3613, customer_last_name#3614, customer_preferred_cust_flag#3615)
    // Output: ListBuffer(customer_id#3612, customer_first_name#3613, customer_last_name#3614, customer_preferred_cust_flag#3615)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _customer_id3612_n = tbl_Sort_TD_2445395_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1243487_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id3612_n);
        std::array<char, TPCDS_READ_MAX + 1> _customer_first_name3613_n = tbl_Sort_TD_2445395_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_1243487_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _customer_first_name3613_n);
        std::array<char, TPCDS_READ_MAX + 1> _customer_last_name3614_n = tbl_Sort_TD_2445395_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_LocalLimit_TD_1243487_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _customer_last_name3614_n);
        std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag3615_n = tbl_Sort_TD_2445395_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_LocalLimit_TD_1243487_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _customer_preferred_cust_flag3615_n);
        r++;
    }
    tbl_LocalLimit_TD_1243487_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1243487_output #Row: " << tbl_LocalLimit_TD_1243487_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0181662(Table &tbl_LocalLimit_TD_1243487_output, Table &tbl_GlobalLimit_TD_0181662_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(customer_id#3612, customer_first_name#3613, customer_last_name#3614, customer_preferred_cust_flag#3615)
    // Output: ListBuffer(customer_id#3612, customer_first_name#3613, customer_last_name#3614, customer_preferred_cust_flag#3615)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _customer_id3612_n = tbl_LocalLimit_TD_1243487_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0181662_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id3612_n);
        std::array<char, TPCDS_READ_MAX + 1> _customer_first_name3613_n = tbl_LocalLimit_TD_1243487_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_0181662_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _customer_first_name3613_n);
        std::array<char, TPCDS_READ_MAX + 1> _customer_last_name3614_n = tbl_LocalLimit_TD_1243487_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_GlobalLimit_TD_0181662_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _customer_last_name3614_n);
        std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag3615_n = tbl_LocalLimit_TD_1243487_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_GlobalLimit_TD_0181662_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _customer_preferred_cust_flag3615_n);
        r++;
    }
    tbl_GlobalLimit_TD_0181662_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0181662_output #Row: " << tbl_GlobalLimit_TD_0181662_output.getNumRow() << std::endl;
}

