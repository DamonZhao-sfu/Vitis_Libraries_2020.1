#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_12646433(Table &tbl_SerializeFromObject_TD_13357717_input, Table &tbl_Filter_TD_12646433_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cs_bill_customer_sk#7353) AND isnotnull(cs_sold_date_sk#7350)))
    // Input: ListBuffer(cs_sold_date_sk#7350, cs_bill_customer_sk#7353, cs_ext_discount_amt#7372, cs_ext_sales_price#7373, cs_ext_wholesale_cost#7374, cs_ext_list_price#7375)
    // Output: ListBuffer(cs_sold_date_sk#7350, cs_bill_customer_sk#7353, cs_ext_discount_amt#7372, cs_ext_sales_price#7373, cs_ext_wholesale_cost#7374, cs_ext_list_price#7375)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13357717_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_bill_customer_sk7353 = tbl_SerializeFromObject_TD_13357717_input.getInt32(i, 1);
        int32_t _cs_sold_date_sk7350 = tbl_SerializeFromObject_TD_13357717_input.getInt32(i, 0);
        if ((_cs_bill_customer_sk7353!= 0) && (_cs_sold_date_sk7350!= 0)) {
            int32_t _cs_sold_date_sk7350_t = tbl_SerializeFromObject_TD_13357717_input.getInt32(i, 0);
            tbl_Filter_TD_12646433_output.setInt32(r, 0, _cs_sold_date_sk7350_t);
            int32_t _cs_bill_customer_sk7353_t = tbl_SerializeFromObject_TD_13357717_input.getInt32(i, 1);
            tbl_Filter_TD_12646433_output.setInt32(r, 1, _cs_bill_customer_sk7353_t);
            int64_t _cs_ext_discount_amt7372_t = tbl_SerializeFromObject_TD_13357717_input.getInt64(i, 2);
            tbl_Filter_TD_12646433_output.setInt64(r, 2, _cs_ext_discount_amt7372_t);
            int64_t _cs_ext_sales_price7373_t = tbl_SerializeFromObject_TD_13357717_input.getInt64(i, 3);
            tbl_Filter_TD_12646433_output.setInt64(r, 3, _cs_ext_sales_price7373_t);
            int64_t _cs_ext_wholesale_cost7374_t = tbl_SerializeFromObject_TD_13357717_input.getInt64(i, 4);
            tbl_Filter_TD_12646433_output.setInt64(r, 4, _cs_ext_wholesale_cost7374_t);
            int64_t _cs_ext_list_price7375_t = tbl_SerializeFromObject_TD_13357717_input.getInt64(i, 5);
            tbl_Filter_TD_12646433_output.setInt64(r, 5, _cs_ext_list_price7375_t);
            r++;
        }
    }
    tbl_Filter_TD_12646433_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12646433_output #Row: " << tbl_Filter_TD_12646433_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12825046(Table &tbl_SerializeFromObject_TD_13814225_input, Table &tbl_Filter_TD_12825046_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(c_customer_sk#7332) AND isnotnull(c_customer_id#7333)))
    // Input: ListBuffer(c_customer_sk#7332, c_customer_id#7333, c_first_name#7340, c_last_name#7341, c_preferred_cust_flag#7342, c_birth_country#7346, c_login#7347, c_email_address#7348)
    // Output: ListBuffer(c_customer_sk#7332, c_customer_id#7333, c_first_name#7340, c_last_name#7341, c_preferred_cust_flag#7342, c_birth_country#7346, c_login#7347, c_email_address#7348)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13814225_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk7332 = tbl_SerializeFromObject_TD_13814225_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7333 = tbl_SerializeFromObject_TD_13814225_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_c_customer_sk7332!= 0) && _c_customer_id7333.data() != "NULL") {
            int32_t _c_customer_sk7332_t = tbl_SerializeFromObject_TD_13814225_input.getInt32(i, 0);
            tbl_Filter_TD_12825046_output.setInt32(r, 0, _c_customer_sk7332_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7333_t = tbl_SerializeFromObject_TD_13814225_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_12825046_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_customer_id7333_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name7340_t = tbl_SerializeFromObject_TD_13814225_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_12825046_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name7340_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name7341_t = tbl_SerializeFromObject_TD_13814225_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_12825046_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name7341_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7342_t = tbl_SerializeFromObject_TD_13814225_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            tbl_Filter_TD_12825046_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_preferred_cust_flag7342_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7346_t = tbl_SerializeFromObject_TD_13814225_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            tbl_Filter_TD_12825046_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_birth_country7346_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_login7347_t = tbl_SerializeFromObject_TD_13814225_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            tbl_Filter_TD_12825046_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_login7347_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address7348_t = tbl_SerializeFromObject_TD_13814225_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            tbl_Filter_TD_12825046_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _c_email_address7348_t);
            r++;
        }
    }
    tbl_Filter_TD_12825046_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12825046_output #Row: " << tbl_Filter_TD_12825046_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12912549(Table &tbl_SerializeFromObject_TD_13398411_input, Table &tbl_Filter_TD_12912549_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_customer_sk#1209) AND isnotnull(ss_sold_date_sk#1206)))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_customer_sk#1209, ss_ext_discount_amt#1220, ss_ext_sales_price#1221, ss_ext_wholesale_cost#1222, ss_ext_list_price#1223)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_customer_sk#1209, ss_ext_discount_amt#1220, ss_ext_sales_price#1221, ss_ext_wholesale_cost#1222, ss_ext_list_price#1223)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13398411_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_customer_sk1209 = tbl_SerializeFromObject_TD_13398411_input.getInt32(i, 1);
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_13398411_input.getInt32(i, 0);
        if ((_ss_customer_sk1209!= 0) && (_ss_sold_date_sk1206!= 0)) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_13398411_input.getInt32(i, 0);
            tbl_Filter_TD_12912549_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_customer_sk1209_t = tbl_SerializeFromObject_TD_13398411_input.getInt32(i, 1);
            tbl_Filter_TD_12912549_output.setInt32(r, 1, _ss_customer_sk1209_t);
            int64_t _ss_ext_discount_amt1220_t = tbl_SerializeFromObject_TD_13398411_input.getInt64(i, 2);
            tbl_Filter_TD_12912549_output.setInt64(r, 2, _ss_ext_discount_amt1220_t);
            int64_t _ss_ext_sales_price1221_t = tbl_SerializeFromObject_TD_13398411_input.getInt64(i, 3);
            tbl_Filter_TD_12912549_output.setInt64(r, 3, _ss_ext_sales_price1221_t);
            int64_t _ss_ext_wholesale_cost1222_t = tbl_SerializeFromObject_TD_13398411_input.getInt64(i, 4);
            tbl_Filter_TD_12912549_output.setInt64(r, 4, _ss_ext_wholesale_cost1222_t);
            int64_t _ss_ext_list_price1223_t = tbl_SerializeFromObject_TD_13398411_input.getInt64(i, 5);
            tbl_Filter_TD_12912549_output.setInt64(r, 5, _ss_ext_list_price1223_t);
            r++;
        }
    }
    tbl_Filter_TD_12912549_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12912549_output #Row: " << tbl_Filter_TD_12912549_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12786550(Table &tbl_SerializeFromObject_TD_13137578_input, Table &tbl_Filter_TD_12786550_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(c_customer_sk#0) AND isnotnull(c_customer_id#1)))
    // Input: ListBuffer(c_customer_sk#0, c_customer_id#1, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_country#14, c_login#15, c_email_address#16)
    // Output: ListBuffer(c_customer_sk#0, c_customer_id#1, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_country#14, c_login#15, c_email_address#16)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13137578_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk0 = tbl_SerializeFromObject_TD_13137578_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1 = tbl_SerializeFromObject_TD_13137578_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_c_customer_sk0!= 0) && _c_customer_id1.data() != "NULL") {
            int32_t _c_customer_sk0_t = tbl_SerializeFromObject_TD_13137578_input.getInt32(i, 0);
            tbl_Filter_TD_12786550_output.setInt32(r, 0, _c_customer_sk0_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_t = tbl_SerializeFromObject_TD_13137578_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_12786550_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_customer_id1_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_t = tbl_SerializeFromObject_TD_13137578_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_12786550_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name8_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_t = tbl_SerializeFromObject_TD_13137578_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_12786550_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name9_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_t = tbl_SerializeFromObject_TD_13137578_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            tbl_Filter_TD_12786550_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_preferred_cust_flag10_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country14_t = tbl_SerializeFromObject_TD_13137578_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            tbl_Filter_TD_12786550_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_birth_country14_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_login15_t = tbl_SerializeFromObject_TD_13137578_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            tbl_Filter_TD_12786550_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_login15_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address16_t = tbl_SerializeFromObject_TD_13137578_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            tbl_Filter_TD_12786550_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _c_email_address16_t);
            r++;
        }
    }
    tbl_Filter_TD_12786550_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12786550_output #Row: " << tbl_Filter_TD_12786550_output.getNumRow() << std::endl;
}

void SW_Filter_TD_1111564(Table &tbl_SerializeFromObject_TD_12424610_input, Table &tbl_Filter_TD_1111564_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#7390) AND (d_year#7390 = 2001)) AND isnotnull(d_date_sk#7384)))
    // Input: ListBuffer(d_date_sk#7384, d_year#7390)
    // Output: ListBuffer(d_date_sk#7384, d_year#7390)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12424610_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year7390 = tbl_SerializeFromObject_TD_12424610_input.getInt32(i, 1);
        int32_t _d_date_sk7384 = tbl_SerializeFromObject_TD_12424610_input.getInt32(i, 0);
        if (((_d_year7390!= 0) && (_d_year7390 == 2001)) && (_d_date_sk7384!= 0)) {
            int32_t _d_date_sk7384_t = tbl_SerializeFromObject_TD_12424610_input.getInt32(i, 0);
            tbl_Filter_TD_1111564_output.setInt32(r, 0, _d_date_sk7384_t);
            int32_t _d_year7390_t = tbl_SerializeFromObject_TD_12424610_input.getInt32(i, 1);
            tbl_Filter_TD_1111564_output.setInt32(r, 1, _d_year7390_t);
            r++;
        }
    }
    tbl_Filter_TD_1111564_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1111564_output #Row: " << tbl_Filter_TD_1111564_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_11806703_key_leftMajor {
    int32_t _c_customer_sk7332;
    bool operator==(const SW_JOIN_INNER_TD_11806703_key_leftMajor& other) const {
        return ((_c_customer_sk7332 == other._c_customer_sk7332));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11806703_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11806703_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk7332));
    }
};
}
struct SW_JOIN_INNER_TD_11806703_payload_leftMajor {
    int32_t _c_customer_sk7332;
    std::string _c_customer_id7333;
    std::string _c_first_name7340;
    std::string _c_last_name7341;
    std::string _c_preferred_cust_flag7342;
    std::string _c_birth_country7346;
    std::string _c_login7347;
    std::string _c_email_address7348;
};
struct SW_JOIN_INNER_TD_11806703_key_rightMajor {
    int32_t _cs_bill_customer_sk7353;
    bool operator==(const SW_JOIN_INNER_TD_11806703_key_rightMajor& other) const {
        return ((_cs_bill_customer_sk7353 == other._cs_bill_customer_sk7353));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11806703_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11806703_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_bill_customer_sk7353));
    }
};
}
struct SW_JOIN_INNER_TD_11806703_payload_rightMajor {
    int32_t _cs_sold_date_sk7350;
    int32_t _cs_bill_customer_sk7353;
    int64_t _cs_ext_discount_amt7372;
    int64_t _cs_ext_sales_price7373;
    int64_t _cs_ext_wholesale_cost7374;
    int64_t _cs_ext_list_price7375;
};
void SW_JOIN_INNER_TD_11806703(Table &tbl_Filter_TD_12825046_output, Table &tbl_Filter_TD_12646433_output, Table &tbl_JOIN_INNER_TD_11806703_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((c_customer_sk#7332 = cs_bill_customer_sk#7353))
    // Left Table: ListBuffer(c_customer_sk#7332, c_customer_id#7333, c_first_name#7340, c_last_name#7341, c_preferred_cust_flag#7342, c_birth_country#7346, c_login#7347, c_email_address#7348)
    // Right Table: ListBuffer(cs_sold_date_sk#7350, cs_bill_customer_sk#7353, cs_ext_discount_amt#7372, cs_ext_sales_price#7373, cs_ext_wholesale_cost#7374, cs_ext_list_price#7375)
    // Output Table: ListBuffer(c_customer_id#7333, c_first_name#7340, c_last_name#7341, c_preferred_cust_flag#7342, c_birth_country#7346, c_login#7347, c_email_address#7348, cs_sold_date_sk#7350, cs_ext_discount_amt#7372, cs_ext_sales_price#7373, cs_ext_wholesale_cost#7374, cs_ext_list_price#7375)
    int left_nrow = tbl_Filter_TD_12825046_output.getNumRow();
    int right_nrow = tbl_Filter_TD_12646433_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11806703_key_leftMajor, SW_JOIN_INNER_TD_11806703_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_12825046_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk7332_k = tbl_Filter_TD_12825046_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_11806703_key_leftMajor keyA{_c_customer_sk7332_k};
            int32_t _c_customer_sk7332 = tbl_Filter_TD_12825046_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7333_n = tbl_Filter_TD_12825046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_customer_id7333 = std::string(_c_customer_id7333_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name7340_n = tbl_Filter_TD_12825046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_first_name7340 = std::string(_c_first_name7340_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name7341_n = tbl_Filter_TD_12825046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_last_name7341 = std::string(_c_last_name7341_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7342_n = tbl_Filter_TD_12825046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_preferred_cust_flag7342 = std::string(_c_preferred_cust_flag7342_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7346_n = tbl_Filter_TD_12825046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _c_birth_country7346 = std::string(_c_birth_country7346_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_login7347_n = tbl_Filter_TD_12825046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _c_login7347 = std::string(_c_login7347_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address7348_n = tbl_Filter_TD_12825046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _c_email_address7348 = std::string(_c_email_address7348_n.data());
            SW_JOIN_INNER_TD_11806703_payload_leftMajor payloadA{_c_customer_sk7332, _c_customer_id7333, _c_first_name7340, _c_last_name7341, _c_preferred_cust_flag7342, _c_birth_country7346, _c_login7347, _c_email_address7348};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_12646433_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_bill_customer_sk7353_k = tbl_Filter_TD_12646433_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11806703_key_leftMajor{_cs_bill_customer_sk7353_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk7332 = (it->second)._c_customer_sk7332;
                std::string _c_customer_id7333 = (it->second)._c_customer_id7333;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7333_n{};
                memcpy(_c_customer_id7333_n.data(), (_c_customer_id7333).data(), (_c_customer_id7333).length());
                std::string _c_first_name7340 = (it->second)._c_first_name7340;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name7340_n{};
                memcpy(_c_first_name7340_n.data(), (_c_first_name7340).data(), (_c_first_name7340).length());
                std::string _c_last_name7341 = (it->second)._c_last_name7341;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name7341_n{};
                memcpy(_c_last_name7341_n.data(), (_c_last_name7341).data(), (_c_last_name7341).length());
                std::string _c_preferred_cust_flag7342 = (it->second)._c_preferred_cust_flag7342;
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7342_n{};
                memcpy(_c_preferred_cust_flag7342_n.data(), (_c_preferred_cust_flag7342).data(), (_c_preferred_cust_flag7342).length());
                std::string _c_birth_country7346 = (it->second)._c_birth_country7346;
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7346_n{};
                memcpy(_c_birth_country7346_n.data(), (_c_birth_country7346).data(), (_c_birth_country7346).length());
                std::string _c_login7347 = (it->second)._c_login7347;
                std::array<char, TPCDS_READ_MAX + 1> _c_login7347_n{};
                memcpy(_c_login7347_n.data(), (_c_login7347).data(), (_c_login7347).length());
                std::string _c_email_address7348 = (it->second)._c_email_address7348;
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address7348_n{};
                memcpy(_c_email_address7348_n.data(), (_c_email_address7348).data(), (_c_email_address7348).length());
                int32_t _cs_sold_date_sk7350 = tbl_Filter_TD_12646433_output.getInt32(i, 0);
                int32_t _cs_bill_customer_sk7353 = tbl_Filter_TD_12646433_output.getInt32(i, 1);
                int64_t _cs_ext_discount_amt7372 = tbl_Filter_TD_12646433_output.getInt64(i, 2);
                int64_t _cs_ext_sales_price7373 = tbl_Filter_TD_12646433_output.getInt64(i, 3);
                int64_t _cs_ext_wholesale_cost7374 = tbl_Filter_TD_12646433_output.getInt64(i, 4);
                int64_t _cs_ext_list_price7375 = tbl_Filter_TD_12646433_output.getInt64(i, 5);
                tbl_JOIN_INNER_TD_11806703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id7333_n);
                tbl_JOIN_INNER_TD_11806703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name7340_n);
                tbl_JOIN_INNER_TD_11806703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name7341_n);
                tbl_JOIN_INNER_TD_11806703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag7342_n);
                tbl_JOIN_INNER_TD_11806703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country7346_n);
                tbl_JOIN_INNER_TD_11806703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login7347_n);
                tbl_JOIN_INNER_TD_11806703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address7348_n);
                tbl_JOIN_INNER_TD_11806703_output.setInt32(r, 7, _cs_sold_date_sk7350);
                tbl_JOIN_INNER_TD_11806703_output.setInt64(r, 8, _cs_ext_discount_amt7372);
                tbl_JOIN_INNER_TD_11806703_output.setInt64(r, 9, _cs_ext_sales_price7373);
                tbl_JOIN_INNER_TD_11806703_output.setInt64(r, 10, _cs_ext_wholesale_cost7374);
                tbl_JOIN_INNER_TD_11806703_output.setInt64(r, 11, _cs_ext_list_price7375);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11806703_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11806703_key_rightMajor, SW_JOIN_INNER_TD_11806703_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_12646433_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_bill_customer_sk7353_k = tbl_Filter_TD_12646433_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_11806703_key_rightMajor keyA{_cs_bill_customer_sk7353_k};
            int32_t _cs_sold_date_sk7350 = tbl_Filter_TD_12646433_output.getInt32(i, 0);
            int32_t _cs_bill_customer_sk7353 = tbl_Filter_TD_12646433_output.getInt32(i, 1);
            int64_t _cs_ext_discount_amt7372 = tbl_Filter_TD_12646433_output.getInt64(i, 2);
            int64_t _cs_ext_sales_price7373 = tbl_Filter_TD_12646433_output.getInt64(i, 3);
            int64_t _cs_ext_wholesale_cost7374 = tbl_Filter_TD_12646433_output.getInt64(i, 4);
            int64_t _cs_ext_list_price7375 = tbl_Filter_TD_12646433_output.getInt64(i, 5);
            SW_JOIN_INNER_TD_11806703_payload_rightMajor payloadA{_cs_sold_date_sk7350, _cs_bill_customer_sk7353, _cs_ext_discount_amt7372, _cs_ext_sales_price7373, _cs_ext_wholesale_cost7374, _cs_ext_list_price7375};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_12825046_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk7332_k = tbl_Filter_TD_12825046_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11806703_key_rightMajor{_c_customer_sk7332_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk7350 = (it->second)._cs_sold_date_sk7350;
                int32_t _cs_bill_customer_sk7353 = (it->second)._cs_bill_customer_sk7353;
                int64_t _cs_ext_discount_amt7372 = (it->second)._cs_ext_discount_amt7372;
                int64_t _cs_ext_sales_price7373 = (it->second)._cs_ext_sales_price7373;
                int64_t _cs_ext_wholesale_cost7374 = (it->second)._cs_ext_wholesale_cost7374;
                int64_t _cs_ext_list_price7375 = (it->second)._cs_ext_list_price7375;
                int32_t _c_customer_sk7332 = tbl_Filter_TD_12825046_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7333_n = tbl_Filter_TD_12825046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_customer_id7333 = std::string(_c_customer_id7333_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name7340_n = tbl_Filter_TD_12825046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_first_name7340 = std::string(_c_first_name7340_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name7341_n = tbl_Filter_TD_12825046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_last_name7341 = std::string(_c_last_name7341_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7342_n = tbl_Filter_TD_12825046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_preferred_cust_flag7342 = std::string(_c_preferred_cust_flag7342_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7346_n = tbl_Filter_TD_12825046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _c_birth_country7346 = std::string(_c_birth_country7346_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_login7347_n = tbl_Filter_TD_12825046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _c_login7347 = std::string(_c_login7347_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address7348_n = tbl_Filter_TD_12825046_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _c_email_address7348 = std::string(_c_email_address7348_n.data());
                tbl_JOIN_INNER_TD_11806703_output.setInt32(r, 7, _cs_sold_date_sk7350);
                tbl_JOIN_INNER_TD_11806703_output.setInt64(r, 8, _cs_ext_discount_amt7372);
                tbl_JOIN_INNER_TD_11806703_output.setInt64(r, 9, _cs_ext_sales_price7373);
                tbl_JOIN_INNER_TD_11806703_output.setInt64(r, 10, _cs_ext_wholesale_cost7374);
                tbl_JOIN_INNER_TD_11806703_output.setInt64(r, 11, _cs_ext_list_price7375);
                tbl_JOIN_INNER_TD_11806703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id7333_n);
                tbl_JOIN_INNER_TD_11806703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name7340_n);
                tbl_JOIN_INNER_TD_11806703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name7341_n);
                tbl_JOIN_INNER_TD_11806703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag7342_n);
                tbl_JOIN_INNER_TD_11806703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country7346_n);
                tbl_JOIN_INNER_TD_11806703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login7347_n);
                tbl_JOIN_INNER_TD_11806703_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address7348_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11806703_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_11806703_output #Row: " << tbl_JOIN_INNER_TD_11806703_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11770821(Table &tbl_SerializeFromObject_TD_12880131_input, Table &tbl_Filter_TD_11770821_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_customer_sk#7045) AND isnotnull(ss_sold_date_sk#7042)))
    // Input: ListBuffer(ss_sold_date_sk#7042, ss_customer_sk#7045)
    // Output: ListBuffer(ss_sold_date_sk#7042, ss_customer_sk#7045)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12880131_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_customer_sk7045 = tbl_SerializeFromObject_TD_12880131_input.getInt32(i, 1);
        int32_t _ss_sold_date_sk7042 = tbl_SerializeFromObject_TD_12880131_input.getInt32(i, 0);
        if ((_ss_customer_sk7045!= 0) && (_ss_sold_date_sk7042!= 0)) {
            int32_t _ss_sold_date_sk7042_t = tbl_SerializeFromObject_TD_12880131_input.getInt32(i, 0);
            tbl_Filter_TD_11770821_output.setInt32(r, 0, _ss_sold_date_sk7042_t);
            int32_t _ss_customer_sk7045_t = tbl_SerializeFromObject_TD_12880131_input.getInt32(i, 1);
            tbl_Filter_TD_11770821_output.setInt32(r, 1, _ss_customer_sk7045_t);
            r++;
        }
    }
    tbl_Filter_TD_11770821_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11770821_output #Row: " << tbl_Filter_TD_11770821_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11355673(Table &tbl_SerializeFromObject_TD_12145002_input, Table &tbl_Filter_TD_11355673_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(c_customer_sk#7024) AND isnotnull(c_customer_id#7025)))
    // Input: ListBuffer(c_customer_sk#7024, c_customer_id#7025, c_first_name#7032, c_last_name#7033, c_preferred_cust_flag#7034, c_birth_country#7038, c_login#7039, c_email_address#7040)
    // Output: ListBuffer(c_customer_sk#7024, c_customer_id#7025, c_first_name#7032, c_last_name#7033, c_preferred_cust_flag#7034, c_birth_country#7038, c_login#7039, c_email_address#7040)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12145002_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk7024 = tbl_SerializeFromObject_TD_12145002_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7025 = tbl_SerializeFromObject_TD_12145002_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_c_customer_sk7024!= 0) && _c_customer_id7025.data() != "NULL") {
            int32_t _c_customer_sk7024_t = tbl_SerializeFromObject_TD_12145002_input.getInt32(i, 0);
            tbl_Filter_TD_11355673_output.setInt32(r, 0, _c_customer_sk7024_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7025_t = tbl_SerializeFromObject_TD_12145002_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_11355673_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_customer_id7025_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name7032_t = tbl_SerializeFromObject_TD_12145002_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_11355673_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name7032_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name7033_t = tbl_SerializeFromObject_TD_12145002_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_11355673_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name7033_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7034_t = tbl_SerializeFromObject_TD_12145002_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            tbl_Filter_TD_11355673_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_preferred_cust_flag7034_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7038_t = tbl_SerializeFromObject_TD_12145002_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            tbl_Filter_TD_11355673_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_birth_country7038_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_login7039_t = tbl_SerializeFromObject_TD_12145002_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            tbl_Filter_TD_11355673_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_login7039_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address7040_t = tbl_SerializeFromObject_TD_12145002_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            tbl_Filter_TD_11355673_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _c_email_address7040_t);
            r++;
        }
    }
    tbl_Filter_TD_11355673_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11355673_output #Row: " << tbl_Filter_TD_11355673_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11270920(Table &tbl_SerializeFromObject_TD_1224704_input, Table &tbl_Filter_TD_11270920_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#126) AND (d_year#126 = 2001)) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126)
    // Output: ListBuffer(d_date_sk#120, d_year#126)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1224704_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_1224704_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_1224704_input.getInt32(i, 0);
        if (((_d_year126!= 0) && (_d_year126 == 2001)) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_1224704_input.getInt32(i, 0);
            tbl_Filter_TD_11270920_output.setInt32(r, 0, _d_date_sk120_t);
            int32_t _d_year126_t = tbl_SerializeFromObject_TD_1224704_input.getInt32(i, 1);
            tbl_Filter_TD_11270920_output.setInt32(r, 1, _d_year126_t);
            r++;
        }
    }
    tbl_Filter_TD_11270920_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11270920_output #Row: " << tbl_Filter_TD_11270920_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_11823337_key_leftMajor {
    int32_t _c_customer_sk0;
    bool operator==(const SW_JOIN_INNER_TD_11823337_key_leftMajor& other) const {
        return ((_c_customer_sk0 == other._c_customer_sk0));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11823337_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11823337_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk0));
    }
};
}
struct SW_JOIN_INNER_TD_11823337_payload_leftMajor {
    int32_t _c_customer_sk0;
    std::string _c_customer_id1;
    std::string _c_first_name8;
    std::string _c_last_name9;
    std::string _c_preferred_cust_flag10;
    std::string _c_birth_country14;
    std::string _c_login15;
    std::string _c_email_address16;
};
struct SW_JOIN_INNER_TD_11823337_key_rightMajor {
    int32_t _ss_customer_sk1209;
    bool operator==(const SW_JOIN_INNER_TD_11823337_key_rightMajor& other) const {
        return ((_ss_customer_sk1209 == other._ss_customer_sk1209));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11823337_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11823337_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_customer_sk1209));
    }
};
}
struct SW_JOIN_INNER_TD_11823337_payload_rightMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_customer_sk1209;
    int64_t _ss_ext_discount_amt1220;
    int64_t _ss_ext_sales_price1221;
    int64_t _ss_ext_wholesale_cost1222;
    int64_t _ss_ext_list_price1223;
};
void SW_JOIN_INNER_TD_11823337(Table &tbl_Filter_TD_12786550_output, Table &tbl_Filter_TD_12912549_output, Table &tbl_JOIN_INNER_TD_11823337_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((c_customer_sk#0 = ss_customer_sk#1209))
    // Left Table: ListBuffer(c_customer_sk#0, c_customer_id#1, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_country#14, c_login#15, c_email_address#16)
    // Right Table: ListBuffer(ss_sold_date_sk#1206, ss_customer_sk#1209, ss_ext_discount_amt#1220, ss_ext_sales_price#1221, ss_ext_wholesale_cost#1222, ss_ext_list_price#1223)
    // Output Table: ListBuffer(c_customer_id#1, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_country#14, c_login#15, c_email_address#16, ss_sold_date_sk#1206, ss_ext_discount_amt#1220, ss_ext_sales_price#1221, ss_ext_wholesale_cost#1222, ss_ext_list_price#1223)
    int left_nrow = tbl_Filter_TD_12786550_output.getNumRow();
    int right_nrow = tbl_Filter_TD_12912549_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11823337_key_leftMajor, SW_JOIN_INNER_TD_11823337_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_12786550_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_12786550_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_11823337_key_leftMajor keyA{_c_customer_sk0_k};
            int32_t _c_customer_sk0 = tbl_Filter_TD_12786550_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n = tbl_Filter_TD_12786550_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_customer_id1 = std::string(_c_customer_id1_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_Filter_TD_12786550_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_first_name8 = std::string(_c_first_name8_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_Filter_TD_12786550_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_last_name9 = std::string(_c_last_name9_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_n = tbl_Filter_TD_12786550_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_preferred_cust_flag10 = std::string(_c_preferred_cust_flag10_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country14_n = tbl_Filter_TD_12786550_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _c_birth_country14 = std::string(_c_birth_country14_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_login15_n = tbl_Filter_TD_12786550_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _c_login15 = std::string(_c_login15_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address16_n = tbl_Filter_TD_12786550_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _c_email_address16 = std::string(_c_email_address16_n.data());
            SW_JOIN_INNER_TD_11823337_payload_leftMajor payloadA{_c_customer_sk0, _c_customer_id1, _c_first_name8, _c_last_name9, _c_preferred_cust_flag10, _c_birth_country14, _c_login15, _c_email_address16};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_12912549_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_customer_sk1209_k = tbl_Filter_TD_12912549_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11823337_key_leftMajor{_ss_customer_sk1209_k});
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
                int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_12912549_output.getInt32(i, 0);
                int32_t _ss_customer_sk1209 = tbl_Filter_TD_12912549_output.getInt32(i, 1);
                int64_t _ss_ext_discount_amt1220 = tbl_Filter_TD_12912549_output.getInt64(i, 2);
                int64_t _ss_ext_sales_price1221 = tbl_Filter_TD_12912549_output.getInt64(i, 3);
                int64_t _ss_ext_wholesale_cost1222 = tbl_Filter_TD_12912549_output.getInt64(i, 4);
                int64_t _ss_ext_list_price1223 = tbl_Filter_TD_12912549_output.getInt64(i, 5);
                tbl_JOIN_INNER_TD_11823337_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id1_n);
                tbl_JOIN_INNER_TD_11823337_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
                tbl_JOIN_INNER_TD_11823337_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name9_n);
                tbl_JOIN_INNER_TD_11823337_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag10_n);
                tbl_JOIN_INNER_TD_11823337_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country14_n);
                tbl_JOIN_INNER_TD_11823337_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login15_n);
                tbl_JOIN_INNER_TD_11823337_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address16_n);
                tbl_JOIN_INNER_TD_11823337_output.setInt32(r, 7, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_11823337_output.setInt64(r, 8, _ss_ext_discount_amt1220);
                tbl_JOIN_INNER_TD_11823337_output.setInt64(r, 9, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_11823337_output.setInt64(r, 10, _ss_ext_wholesale_cost1222);
                tbl_JOIN_INNER_TD_11823337_output.setInt64(r, 11, _ss_ext_list_price1223);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11823337_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11823337_key_rightMajor, SW_JOIN_INNER_TD_11823337_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_12912549_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_customer_sk1209_k = tbl_Filter_TD_12912549_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_11823337_key_rightMajor keyA{_ss_customer_sk1209_k};
            int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_12912549_output.getInt32(i, 0);
            int32_t _ss_customer_sk1209 = tbl_Filter_TD_12912549_output.getInt32(i, 1);
            int64_t _ss_ext_discount_amt1220 = tbl_Filter_TD_12912549_output.getInt64(i, 2);
            int64_t _ss_ext_sales_price1221 = tbl_Filter_TD_12912549_output.getInt64(i, 3);
            int64_t _ss_ext_wholesale_cost1222 = tbl_Filter_TD_12912549_output.getInt64(i, 4);
            int64_t _ss_ext_list_price1223 = tbl_Filter_TD_12912549_output.getInt64(i, 5);
            SW_JOIN_INNER_TD_11823337_payload_rightMajor payloadA{_ss_sold_date_sk1206, _ss_customer_sk1209, _ss_ext_discount_amt1220, _ss_ext_sales_price1221, _ss_ext_wholesale_cost1222, _ss_ext_list_price1223};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_12786550_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_12786550_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11823337_key_rightMajor{_c_customer_sk0_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                int64_t _ss_ext_discount_amt1220 = (it->second)._ss_ext_discount_amt1220;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int64_t _ss_ext_wholesale_cost1222 = (it->second)._ss_ext_wholesale_cost1222;
                int64_t _ss_ext_list_price1223 = (it->second)._ss_ext_list_price1223;
                int32_t _c_customer_sk0 = tbl_Filter_TD_12786550_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n = tbl_Filter_TD_12786550_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_customer_id1 = std::string(_c_customer_id1_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_Filter_TD_12786550_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_first_name8 = std::string(_c_first_name8_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_Filter_TD_12786550_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_last_name9 = std::string(_c_last_name9_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_n = tbl_Filter_TD_12786550_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_preferred_cust_flag10 = std::string(_c_preferred_cust_flag10_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country14_n = tbl_Filter_TD_12786550_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _c_birth_country14 = std::string(_c_birth_country14_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_login15_n = tbl_Filter_TD_12786550_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _c_login15 = std::string(_c_login15_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address16_n = tbl_Filter_TD_12786550_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _c_email_address16 = std::string(_c_email_address16_n.data());
                tbl_JOIN_INNER_TD_11823337_output.setInt32(r, 7, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_11823337_output.setInt64(r, 8, _ss_ext_discount_amt1220);
                tbl_JOIN_INNER_TD_11823337_output.setInt64(r, 9, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_11823337_output.setInt64(r, 10, _ss_ext_wholesale_cost1222);
                tbl_JOIN_INNER_TD_11823337_output.setInt64(r, 11, _ss_ext_list_price1223);
                tbl_JOIN_INNER_TD_11823337_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id1_n);
                tbl_JOIN_INNER_TD_11823337_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
                tbl_JOIN_INNER_TD_11823337_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name9_n);
                tbl_JOIN_INNER_TD_11823337_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag10_n);
                tbl_JOIN_INNER_TD_11823337_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country14_n);
                tbl_JOIN_INNER_TD_11823337_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login15_n);
                tbl_JOIN_INNER_TD_11823337_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address16_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11823337_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_11823337_output #Row: " << tbl_JOIN_INNER_TD_11823337_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10440338(Table &tbl_SerializeFromObject_TD_11911995_input, Table &tbl_Filter_TD_10440338_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_bill_customer_sk#7912) AND isnotnull(ws_sold_date_sk#7908)))
    // Input: ListBuffer(ws_sold_date_sk#7908, ws_bill_customer_sk#7912, ws_ext_discount_amt#7930, ws_ext_sales_price#7931, ws_ext_wholesale_cost#7932, ws_ext_list_price#7933)
    // Output: ListBuffer(ws_sold_date_sk#7908, ws_bill_customer_sk#7912, ws_ext_discount_amt#7930, ws_ext_sales_price#7931, ws_ext_wholesale_cost#7932, ws_ext_list_price#7933)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11911995_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_bill_customer_sk7912 = tbl_SerializeFromObject_TD_11911995_input.getInt32(i, 1);
        int32_t _ws_sold_date_sk7908 = tbl_SerializeFromObject_TD_11911995_input.getInt32(i, 0);
        if ((_ws_bill_customer_sk7912!= 0) && (_ws_sold_date_sk7908!= 0)) {
            int32_t _ws_sold_date_sk7908_t = tbl_SerializeFromObject_TD_11911995_input.getInt32(i, 0);
            tbl_Filter_TD_10440338_output.setInt32(r, 0, _ws_sold_date_sk7908_t);
            int32_t _ws_bill_customer_sk7912_t = tbl_SerializeFromObject_TD_11911995_input.getInt32(i, 1);
            tbl_Filter_TD_10440338_output.setInt32(r, 1, _ws_bill_customer_sk7912_t);
            int64_t _ws_ext_discount_amt7930_t = tbl_SerializeFromObject_TD_11911995_input.getInt64(i, 2);
            tbl_Filter_TD_10440338_output.setInt64(r, 2, _ws_ext_discount_amt7930_t);
            int64_t _ws_ext_sales_price7931_t = tbl_SerializeFromObject_TD_11911995_input.getInt64(i, 3);
            tbl_Filter_TD_10440338_output.setInt64(r, 3, _ws_ext_sales_price7931_t);
            int64_t _ws_ext_wholesale_cost7932_t = tbl_SerializeFromObject_TD_11911995_input.getInt64(i, 4);
            tbl_Filter_TD_10440338_output.setInt64(r, 4, _ws_ext_wholesale_cost7932_t);
            int64_t _ws_ext_list_price7933_t = tbl_SerializeFromObject_TD_11911995_input.getInt64(i, 5);
            tbl_Filter_TD_10440338_output.setInt64(r, 5, _ws_ext_list_price7933_t);
            r++;
        }
    }
    tbl_Filter_TD_10440338_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10440338_output #Row: " << tbl_Filter_TD_10440338_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10966392(Table &tbl_SerializeFromObject_TD_11120933_input, Table &tbl_Filter_TD_10966392_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(c_customer_sk#7890) AND isnotnull(c_customer_id#7891)))
    // Input: ListBuffer(c_customer_sk#7890, c_customer_id#7891, c_first_name#7898, c_last_name#7899, c_preferred_cust_flag#7900, c_birth_country#7904, c_login#7905, c_email_address#7906)
    // Output: ListBuffer(c_customer_sk#7890, c_customer_id#7891, c_first_name#7898, c_last_name#7899, c_preferred_cust_flag#7900, c_birth_country#7904, c_login#7905, c_email_address#7906)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11120933_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk7890 = tbl_SerializeFromObject_TD_11120933_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7891 = tbl_SerializeFromObject_TD_11120933_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_c_customer_sk7890!= 0) && _c_customer_id7891.data() != "NULL") {
            int32_t _c_customer_sk7890_t = tbl_SerializeFromObject_TD_11120933_input.getInt32(i, 0);
            tbl_Filter_TD_10966392_output.setInt32(r, 0, _c_customer_sk7890_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7891_t = tbl_SerializeFromObject_TD_11120933_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_10966392_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_customer_id7891_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name7898_t = tbl_SerializeFromObject_TD_11120933_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_10966392_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name7898_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name7899_t = tbl_SerializeFromObject_TD_11120933_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_10966392_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name7899_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7900_t = tbl_SerializeFromObject_TD_11120933_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            tbl_Filter_TD_10966392_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_preferred_cust_flag7900_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7904_t = tbl_SerializeFromObject_TD_11120933_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            tbl_Filter_TD_10966392_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_birth_country7904_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_login7905_t = tbl_SerializeFromObject_TD_11120933_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            tbl_Filter_TD_10966392_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_login7905_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address7906_t = tbl_SerializeFromObject_TD_11120933_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            tbl_Filter_TD_10966392_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _c_email_address7906_t);
            r++;
        }
    }
    tbl_Filter_TD_10966392_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10966392_output #Row: " << tbl_Filter_TD_10966392_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_10185218_key_leftMajor {
    int32_t _cs_sold_date_sk7350;
    bool operator==(const SW_JOIN_INNER_TD_10185218_key_leftMajor& other) const {
        return ((_cs_sold_date_sk7350 == other._cs_sold_date_sk7350));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10185218_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10185218_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_sold_date_sk7350));
    }
};
}
struct SW_JOIN_INNER_TD_10185218_payload_leftMajor {
    std::string _c_customer_id7333;
    std::string _c_first_name7340;
    std::string _c_last_name7341;
    std::string _c_preferred_cust_flag7342;
    std::string _c_birth_country7346;
    std::string _c_login7347;
    std::string _c_email_address7348;
    int32_t _cs_sold_date_sk7350;
    int64_t _cs_ext_discount_amt7372;
    int64_t _cs_ext_sales_price7373;
    int64_t _cs_ext_wholesale_cost7374;
    int64_t _cs_ext_list_price7375;
};
struct SW_JOIN_INNER_TD_10185218_key_rightMajor {
    int32_t _d_date_sk7384;
    bool operator==(const SW_JOIN_INNER_TD_10185218_key_rightMajor& other) const {
        return ((_d_date_sk7384 == other._d_date_sk7384));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10185218_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10185218_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk7384));
    }
};
}
struct SW_JOIN_INNER_TD_10185218_payload_rightMajor {
    int32_t _d_date_sk7384;
    int32_t _d_year7390;
};
void SW_JOIN_INNER_TD_10185218(Table &tbl_JOIN_INNER_TD_11806703_output, Table &tbl_Filter_TD_1111564_output, Table &tbl_JOIN_INNER_TD_10185218_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_sold_date_sk#7350 = d_date_sk#7384))
    // Left Table: ListBuffer(c_customer_id#7333, c_first_name#7340, c_last_name#7341, c_preferred_cust_flag#7342, c_birth_country#7346, c_login#7347, c_email_address#7348, cs_sold_date_sk#7350, cs_ext_discount_amt#7372, cs_ext_sales_price#7373, cs_ext_wholesale_cost#7374, cs_ext_list_price#7375)
    // Right Table: ListBuffer(d_date_sk#7384, d_year#7390)
    // Output Table: ListBuffer(c_customer_id#7333, c_first_name#7340, c_last_name#7341, c_preferred_cust_flag#7342, c_birth_country#7346, c_login#7347, c_email_address#7348, cs_ext_discount_amt#7372, cs_ext_sales_price#7373, cs_ext_wholesale_cost#7374, cs_ext_list_price#7375, d_year#7390)
    int left_nrow = tbl_JOIN_INNER_TD_11806703_output.getNumRow();
    int right_nrow = tbl_Filter_TD_1111564_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10185218_key_leftMajor, SW_JOIN_INNER_TD_10185218_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_11806703_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_sold_date_sk7350_k = tbl_JOIN_INNER_TD_11806703_output.getInt32(i, 7);
            SW_JOIN_INNER_TD_10185218_key_leftMajor keyA{_cs_sold_date_sk7350_k};
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7333_n = tbl_JOIN_INNER_TD_11806703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _c_customer_id7333 = std::string(_c_customer_id7333_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name7340_n = tbl_JOIN_INNER_TD_11806703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_first_name7340 = std::string(_c_first_name7340_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name7341_n = tbl_JOIN_INNER_TD_11806703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_last_name7341 = std::string(_c_last_name7341_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7342_n = tbl_JOIN_INNER_TD_11806703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_preferred_cust_flag7342 = std::string(_c_preferred_cust_flag7342_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7346_n = tbl_JOIN_INNER_TD_11806703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_birth_country7346 = std::string(_c_birth_country7346_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_login7347_n = tbl_JOIN_INNER_TD_11806703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _c_login7347 = std::string(_c_login7347_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address7348_n = tbl_JOIN_INNER_TD_11806703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _c_email_address7348 = std::string(_c_email_address7348_n.data());
            int32_t _cs_sold_date_sk7350 = tbl_JOIN_INNER_TD_11806703_output.getInt32(i, 7);
            int64_t _cs_ext_discount_amt7372 = tbl_JOIN_INNER_TD_11806703_output.getInt64(i, 8);
            int64_t _cs_ext_sales_price7373 = tbl_JOIN_INNER_TD_11806703_output.getInt64(i, 9);
            int64_t _cs_ext_wholesale_cost7374 = tbl_JOIN_INNER_TD_11806703_output.getInt64(i, 10);
            int64_t _cs_ext_list_price7375 = tbl_JOIN_INNER_TD_11806703_output.getInt64(i, 11);
            SW_JOIN_INNER_TD_10185218_payload_leftMajor payloadA{_c_customer_id7333, _c_first_name7340, _c_last_name7341, _c_preferred_cust_flag7342, _c_birth_country7346, _c_login7347, _c_email_address7348, _cs_sold_date_sk7350, _cs_ext_discount_amt7372, _cs_ext_sales_price7373, _cs_ext_wholesale_cost7374, _cs_ext_list_price7375};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_1111564_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk7384_k = tbl_Filter_TD_1111564_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10185218_key_leftMajor{_d_date_sk7384_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _c_customer_id7333 = (it->second)._c_customer_id7333;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7333_n{};
                memcpy(_c_customer_id7333_n.data(), (_c_customer_id7333).data(), (_c_customer_id7333).length());
                std::string _c_first_name7340 = (it->second)._c_first_name7340;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name7340_n{};
                memcpy(_c_first_name7340_n.data(), (_c_first_name7340).data(), (_c_first_name7340).length());
                std::string _c_last_name7341 = (it->second)._c_last_name7341;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name7341_n{};
                memcpy(_c_last_name7341_n.data(), (_c_last_name7341).data(), (_c_last_name7341).length());
                std::string _c_preferred_cust_flag7342 = (it->second)._c_preferred_cust_flag7342;
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7342_n{};
                memcpy(_c_preferred_cust_flag7342_n.data(), (_c_preferred_cust_flag7342).data(), (_c_preferred_cust_flag7342).length());
                std::string _c_birth_country7346 = (it->second)._c_birth_country7346;
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7346_n{};
                memcpy(_c_birth_country7346_n.data(), (_c_birth_country7346).data(), (_c_birth_country7346).length());
                std::string _c_login7347 = (it->second)._c_login7347;
                std::array<char, TPCDS_READ_MAX + 1> _c_login7347_n{};
                memcpy(_c_login7347_n.data(), (_c_login7347).data(), (_c_login7347).length());
                std::string _c_email_address7348 = (it->second)._c_email_address7348;
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address7348_n{};
                memcpy(_c_email_address7348_n.data(), (_c_email_address7348).data(), (_c_email_address7348).length());
                int32_t _cs_sold_date_sk7350 = (it->second)._cs_sold_date_sk7350;
                int64_t _cs_ext_discount_amt7372 = (it->second)._cs_ext_discount_amt7372;
                int64_t _cs_ext_sales_price7373 = (it->second)._cs_ext_sales_price7373;
                int64_t _cs_ext_wholesale_cost7374 = (it->second)._cs_ext_wholesale_cost7374;
                int64_t _cs_ext_list_price7375 = (it->second)._cs_ext_list_price7375;
                int32_t _d_date_sk7384 = tbl_Filter_TD_1111564_output.getInt32(i, 0);
                int32_t _d_year7390 = tbl_Filter_TD_1111564_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_10185218_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id7333_n);
                tbl_JOIN_INNER_TD_10185218_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name7340_n);
                tbl_JOIN_INNER_TD_10185218_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name7341_n);
                tbl_JOIN_INNER_TD_10185218_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag7342_n);
                tbl_JOIN_INNER_TD_10185218_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country7346_n);
                tbl_JOIN_INNER_TD_10185218_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login7347_n);
                tbl_JOIN_INNER_TD_10185218_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address7348_n);
                tbl_JOIN_INNER_TD_10185218_output.setInt64(r, 7, _cs_ext_discount_amt7372);
                tbl_JOIN_INNER_TD_10185218_output.setInt64(r, 8, _cs_ext_sales_price7373);
                tbl_JOIN_INNER_TD_10185218_output.setInt64(r, 9, _cs_ext_wholesale_cost7374);
                tbl_JOIN_INNER_TD_10185218_output.setInt64(r, 10, _cs_ext_list_price7375);
                tbl_JOIN_INNER_TD_10185218_output.setInt32(r, 11, _d_year7390);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10185218_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10185218_key_rightMajor, SW_JOIN_INNER_TD_10185218_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_1111564_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk7384_k = tbl_Filter_TD_1111564_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_10185218_key_rightMajor keyA{_d_date_sk7384_k};
            int32_t _d_date_sk7384 = tbl_Filter_TD_1111564_output.getInt32(i, 0);
            int32_t _d_year7390 = tbl_Filter_TD_1111564_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_10185218_payload_rightMajor payloadA{_d_date_sk7384, _d_year7390};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_11806703_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_sold_date_sk7350_k = tbl_JOIN_INNER_TD_11806703_output.getInt32(i, 7);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10185218_key_rightMajor{_cs_sold_date_sk7350_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk7384 = (it->second)._d_date_sk7384;
                int32_t _d_year7390 = (it->second)._d_year7390;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7333_n = tbl_JOIN_INNER_TD_11806703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _c_customer_id7333 = std::string(_c_customer_id7333_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name7340_n = tbl_JOIN_INNER_TD_11806703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_first_name7340 = std::string(_c_first_name7340_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name7341_n = tbl_JOIN_INNER_TD_11806703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_last_name7341 = std::string(_c_last_name7341_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7342_n = tbl_JOIN_INNER_TD_11806703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_preferred_cust_flag7342 = std::string(_c_preferred_cust_flag7342_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7346_n = tbl_JOIN_INNER_TD_11806703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_birth_country7346 = std::string(_c_birth_country7346_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_login7347_n = tbl_JOIN_INNER_TD_11806703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _c_login7347 = std::string(_c_login7347_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address7348_n = tbl_JOIN_INNER_TD_11806703_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _c_email_address7348 = std::string(_c_email_address7348_n.data());
                int32_t _cs_sold_date_sk7350 = tbl_JOIN_INNER_TD_11806703_output.getInt32(i, 7);
                int64_t _cs_ext_discount_amt7372 = tbl_JOIN_INNER_TD_11806703_output.getInt64(i, 8);
                int64_t _cs_ext_sales_price7373 = tbl_JOIN_INNER_TD_11806703_output.getInt64(i, 9);
                int64_t _cs_ext_wholesale_cost7374 = tbl_JOIN_INNER_TD_11806703_output.getInt64(i, 10);
                int64_t _cs_ext_list_price7375 = tbl_JOIN_INNER_TD_11806703_output.getInt64(i, 11);
                tbl_JOIN_INNER_TD_10185218_output.setInt32(r, 11, _d_year7390);
                tbl_JOIN_INNER_TD_10185218_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id7333_n);
                tbl_JOIN_INNER_TD_10185218_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name7340_n);
                tbl_JOIN_INNER_TD_10185218_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name7341_n);
                tbl_JOIN_INNER_TD_10185218_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag7342_n);
                tbl_JOIN_INNER_TD_10185218_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country7346_n);
                tbl_JOIN_INNER_TD_10185218_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login7347_n);
                tbl_JOIN_INNER_TD_10185218_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address7348_n);
                tbl_JOIN_INNER_TD_10185218_output.setInt64(r, 7, _cs_ext_discount_amt7372);
                tbl_JOIN_INNER_TD_10185218_output.setInt64(r, 8, _cs_ext_sales_price7373);
                tbl_JOIN_INNER_TD_10185218_output.setInt64(r, 9, _cs_ext_wholesale_cost7374);
                tbl_JOIN_INNER_TD_10185218_output.setInt64(r, 10, _cs_ext_list_price7375);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10185218_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_10185218_output #Row: " << tbl_JOIN_INNER_TD_10185218_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10239172(Table &tbl_SerializeFromObject_TD_11709768_input, Table &tbl_Filter_TD_10239172_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#7071) AND (d_year#7071 = 2002)) AND isnotnull(d_date_sk#7065)))
    // Input: ListBuffer(d_date_sk#7065, d_year#7071)
    // Output: ListBuffer(d_date_sk#7065, d_year#7071)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11709768_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year7071 = tbl_SerializeFromObject_TD_11709768_input.getInt32(i, 1);
        int32_t _d_date_sk7065 = tbl_SerializeFromObject_TD_11709768_input.getInt32(i, 0);
        if (((_d_year7071!= 0) && (_d_year7071 == 2002)) && (_d_date_sk7065!= 0)) {
            int32_t _d_date_sk7065_t = tbl_SerializeFromObject_TD_11709768_input.getInt32(i, 0);
            tbl_Filter_TD_10239172_output.setInt32(r, 0, _d_date_sk7065_t);
            int32_t _d_year7071_t = tbl_SerializeFromObject_TD_11709768_input.getInt32(i, 1);
            tbl_Filter_TD_10239172_output.setInt32(r, 1, _d_year7071_t);
            r++;
        }
    }
    tbl_Filter_TD_10239172_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10239172_output #Row: " << tbl_Filter_TD_10239172_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_10915984_key_leftMajor {
    int32_t _c_customer_sk7024;
    bool operator==(const SW_JOIN_INNER_TD_10915984_key_leftMajor& other) const {
        return ((_c_customer_sk7024 == other._c_customer_sk7024));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10915984_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10915984_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk7024));
    }
};
}
struct SW_JOIN_INNER_TD_10915984_payload_leftMajor {
    int32_t _c_customer_sk7024;
    std::string _c_customer_id7025;
    std::string _c_first_name7032;
    std::string _c_last_name7033;
    std::string _c_preferred_cust_flag7034;
    std::string _c_birth_country7038;
    std::string _c_login7039;
    std::string _c_email_address7040;
};
struct SW_JOIN_INNER_TD_10915984_key_rightMajor {
    int32_t _ss_customer_sk7045;
    bool operator==(const SW_JOIN_INNER_TD_10915984_key_rightMajor& other) const {
        return ((_ss_customer_sk7045 == other._ss_customer_sk7045));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10915984_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10915984_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_customer_sk7045));
    }
};
}
struct SW_JOIN_INNER_TD_10915984_payload_rightMajor {
    int32_t _ss_sold_date_sk7042;
    int32_t _ss_customer_sk7045;
};
void SW_JOIN_INNER_TD_10915984(Table &tbl_Filter_TD_11355673_output, Table &tbl_Filter_TD_11770821_output, Table &tbl_JOIN_INNER_TD_10915984_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((c_customer_sk#7024 = ss_customer_sk#7045))
    // Left Table: ListBuffer(c_customer_sk#7024, c_customer_id#7025, c_first_name#7032, c_last_name#7033, c_preferred_cust_flag#7034, c_birth_country#7038, c_login#7039, c_email_address#7040)
    // Right Table: ListBuffer(ss_sold_date_sk#7042, ss_customer_sk#7045)
    // Output Table: ListBuffer(c_customer_id#7025, c_first_name#7032, c_last_name#7033, c_preferred_cust_flag#7034, c_birth_country#7038, c_login#7039, c_email_address#7040, ss_sold_date_sk#7042)
    int left_nrow = tbl_Filter_TD_11355673_output.getNumRow();
    int right_nrow = tbl_Filter_TD_11770821_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10915984_key_leftMajor, SW_JOIN_INNER_TD_10915984_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_11355673_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk7024_k = tbl_Filter_TD_11355673_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_10915984_key_leftMajor keyA{_c_customer_sk7024_k};
            int32_t _c_customer_sk7024 = tbl_Filter_TD_11355673_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7025_n = tbl_Filter_TD_11355673_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_customer_id7025 = std::string(_c_customer_id7025_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name7032_n = tbl_Filter_TD_11355673_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_first_name7032 = std::string(_c_first_name7032_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name7033_n = tbl_Filter_TD_11355673_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_last_name7033 = std::string(_c_last_name7033_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7034_n = tbl_Filter_TD_11355673_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_preferred_cust_flag7034 = std::string(_c_preferred_cust_flag7034_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7038_n = tbl_Filter_TD_11355673_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _c_birth_country7038 = std::string(_c_birth_country7038_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_login7039_n = tbl_Filter_TD_11355673_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _c_login7039 = std::string(_c_login7039_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address7040_n = tbl_Filter_TD_11355673_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _c_email_address7040 = std::string(_c_email_address7040_n.data());
            SW_JOIN_INNER_TD_10915984_payload_leftMajor payloadA{_c_customer_sk7024, _c_customer_id7025, _c_first_name7032, _c_last_name7033, _c_preferred_cust_flag7034, _c_birth_country7038, _c_login7039, _c_email_address7040};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_11770821_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_customer_sk7045_k = tbl_Filter_TD_11770821_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10915984_key_leftMajor{_ss_customer_sk7045_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk7024 = (it->second)._c_customer_sk7024;
                std::string _c_customer_id7025 = (it->second)._c_customer_id7025;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7025_n{};
                memcpy(_c_customer_id7025_n.data(), (_c_customer_id7025).data(), (_c_customer_id7025).length());
                std::string _c_first_name7032 = (it->second)._c_first_name7032;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name7032_n{};
                memcpy(_c_first_name7032_n.data(), (_c_first_name7032).data(), (_c_first_name7032).length());
                std::string _c_last_name7033 = (it->second)._c_last_name7033;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name7033_n{};
                memcpy(_c_last_name7033_n.data(), (_c_last_name7033).data(), (_c_last_name7033).length());
                std::string _c_preferred_cust_flag7034 = (it->second)._c_preferred_cust_flag7034;
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7034_n{};
                memcpy(_c_preferred_cust_flag7034_n.data(), (_c_preferred_cust_flag7034).data(), (_c_preferred_cust_flag7034).length());
                std::string _c_birth_country7038 = (it->second)._c_birth_country7038;
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7038_n{};
                memcpy(_c_birth_country7038_n.data(), (_c_birth_country7038).data(), (_c_birth_country7038).length());
                std::string _c_login7039 = (it->second)._c_login7039;
                std::array<char, TPCDS_READ_MAX + 1> _c_login7039_n{};
                memcpy(_c_login7039_n.data(), (_c_login7039).data(), (_c_login7039).length());
                std::string _c_email_address7040 = (it->second)._c_email_address7040;
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address7040_n{};
                memcpy(_c_email_address7040_n.data(), (_c_email_address7040).data(), (_c_email_address7040).length());
                int32_t _ss_sold_date_sk7042 = tbl_Filter_TD_11770821_output.getInt32(i, 0);
                int32_t _ss_customer_sk7045 = tbl_Filter_TD_11770821_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_10915984_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id7025_n);
                tbl_JOIN_INNER_TD_10915984_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name7032_n);
                tbl_JOIN_INNER_TD_10915984_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name7033_n);
                tbl_JOIN_INNER_TD_10915984_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag7034_n);
                tbl_JOIN_INNER_TD_10915984_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country7038_n);
                tbl_JOIN_INNER_TD_10915984_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login7039_n);
                tbl_JOIN_INNER_TD_10915984_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address7040_n);
                tbl_JOIN_INNER_TD_10915984_output.setInt32(r, 7, _ss_sold_date_sk7042);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10915984_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10915984_key_rightMajor, SW_JOIN_INNER_TD_10915984_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_11770821_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_customer_sk7045_k = tbl_Filter_TD_11770821_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_10915984_key_rightMajor keyA{_ss_customer_sk7045_k};
            int32_t _ss_sold_date_sk7042 = tbl_Filter_TD_11770821_output.getInt32(i, 0);
            int32_t _ss_customer_sk7045 = tbl_Filter_TD_11770821_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_10915984_payload_rightMajor payloadA{_ss_sold_date_sk7042, _ss_customer_sk7045};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_11355673_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk7024_k = tbl_Filter_TD_11355673_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10915984_key_rightMajor{_c_customer_sk7024_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk7042 = (it->second)._ss_sold_date_sk7042;
                int32_t _ss_customer_sk7045 = (it->second)._ss_customer_sk7045;
                int32_t _c_customer_sk7024 = tbl_Filter_TD_11355673_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7025_n = tbl_Filter_TD_11355673_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_customer_id7025 = std::string(_c_customer_id7025_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name7032_n = tbl_Filter_TD_11355673_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_first_name7032 = std::string(_c_first_name7032_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name7033_n = tbl_Filter_TD_11355673_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_last_name7033 = std::string(_c_last_name7033_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7034_n = tbl_Filter_TD_11355673_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_preferred_cust_flag7034 = std::string(_c_preferred_cust_flag7034_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7038_n = tbl_Filter_TD_11355673_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _c_birth_country7038 = std::string(_c_birth_country7038_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_login7039_n = tbl_Filter_TD_11355673_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _c_login7039 = std::string(_c_login7039_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address7040_n = tbl_Filter_TD_11355673_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _c_email_address7040 = std::string(_c_email_address7040_n.data());
                tbl_JOIN_INNER_TD_10915984_output.setInt32(r, 7, _ss_sold_date_sk7042);
                tbl_JOIN_INNER_TD_10915984_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id7025_n);
                tbl_JOIN_INNER_TD_10915984_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name7032_n);
                tbl_JOIN_INNER_TD_10915984_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name7033_n);
                tbl_JOIN_INNER_TD_10915984_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag7034_n);
                tbl_JOIN_INNER_TD_10915984_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country7038_n);
                tbl_JOIN_INNER_TD_10915984_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login7039_n);
                tbl_JOIN_INNER_TD_10915984_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address7040_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10915984_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_10915984_output #Row: " << tbl_JOIN_INNER_TD_10915984_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_10119634_key_leftMajor {
    int32_t _ss_sold_date_sk1206;
    bool operator==(const SW_JOIN_INNER_TD_10119634_key_leftMajor& other) const {
        return ((_ss_sold_date_sk1206 == other._ss_sold_date_sk1206));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10119634_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10119634_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_sold_date_sk1206));
    }
};
}
struct SW_JOIN_INNER_TD_10119634_payload_leftMajor {
    std::string _c_customer_id1;
    std::string _c_first_name8;
    std::string _c_last_name9;
    std::string _c_preferred_cust_flag10;
    std::string _c_birth_country14;
    std::string _c_login15;
    std::string _c_email_address16;
    int32_t _ss_sold_date_sk1206;
    int64_t _ss_ext_discount_amt1220;
    int64_t _ss_ext_sales_price1221;
    int64_t _ss_ext_wholesale_cost1222;
    int64_t _ss_ext_list_price1223;
};
struct SW_JOIN_INNER_TD_10119634_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_10119634_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10119634_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10119634_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_10119634_payload_rightMajor {
    int32_t _d_date_sk120;
    int32_t _d_year126;
};
void SW_JOIN_INNER_TD_10119634(Table &tbl_JOIN_INNER_TD_11823337_output, Table &tbl_Filter_TD_11270920_output, Table &tbl_JOIN_INNER_TD_10119634_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#1206 = d_date_sk#120))
    // Left Table: ListBuffer(c_customer_id#1, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_country#14, c_login#15, c_email_address#16, ss_sold_date_sk#1206, ss_ext_discount_amt#1220, ss_ext_sales_price#1221, ss_ext_wholesale_cost#1222, ss_ext_list_price#1223)
    // Right Table: ListBuffer(d_date_sk#120, d_year#126)
    // Output Table: ListBuffer(c_customer_id#1, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_country#14, c_login#15, c_email_address#16, ss_ext_discount_amt#1220, ss_ext_sales_price#1221, ss_ext_wholesale_cost#1222, ss_ext_list_price#1223, d_year#126)
    int left_nrow = tbl_JOIN_INNER_TD_11823337_output.getNumRow();
    int right_nrow = tbl_Filter_TD_11270920_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10119634_key_leftMajor, SW_JOIN_INNER_TD_10119634_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_11823337_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_JOIN_INNER_TD_11823337_output.getInt32(i, 7);
            SW_JOIN_INNER_TD_10119634_key_leftMajor keyA{_ss_sold_date_sk1206_k};
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n = tbl_JOIN_INNER_TD_11823337_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _c_customer_id1 = std::string(_c_customer_id1_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_JOIN_INNER_TD_11823337_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_first_name8 = std::string(_c_first_name8_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_JOIN_INNER_TD_11823337_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_last_name9 = std::string(_c_last_name9_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_n = tbl_JOIN_INNER_TD_11823337_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_preferred_cust_flag10 = std::string(_c_preferred_cust_flag10_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country14_n = tbl_JOIN_INNER_TD_11823337_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_birth_country14 = std::string(_c_birth_country14_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_login15_n = tbl_JOIN_INNER_TD_11823337_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _c_login15 = std::string(_c_login15_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address16_n = tbl_JOIN_INNER_TD_11823337_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _c_email_address16 = std::string(_c_email_address16_n.data());
            int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_11823337_output.getInt32(i, 7);
            int64_t _ss_ext_discount_amt1220 = tbl_JOIN_INNER_TD_11823337_output.getInt64(i, 8);
            int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_11823337_output.getInt64(i, 9);
            int64_t _ss_ext_wholesale_cost1222 = tbl_JOIN_INNER_TD_11823337_output.getInt64(i, 10);
            int64_t _ss_ext_list_price1223 = tbl_JOIN_INNER_TD_11823337_output.getInt64(i, 11);
            SW_JOIN_INNER_TD_10119634_payload_leftMajor payloadA{_c_customer_id1, _c_first_name8, _c_last_name9, _c_preferred_cust_flag10, _c_birth_country14, _c_login15, _c_email_address16, _ss_sold_date_sk1206, _ss_ext_discount_amt1220, _ss_ext_sales_price1221, _ss_ext_wholesale_cost1222, _ss_ext_list_price1223};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_11270920_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_11270920_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10119634_key_leftMajor{_d_date_sk120_k});
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
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int64_t _ss_ext_wholesale_cost1222 = (it->second)._ss_ext_wholesale_cost1222;
                int64_t _ss_ext_list_price1223 = (it->second)._ss_ext_list_price1223;
                int32_t _d_date_sk120 = tbl_Filter_TD_11270920_output.getInt32(i, 0);
                int32_t _d_year126 = tbl_Filter_TD_11270920_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_10119634_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id1_n);
                tbl_JOIN_INNER_TD_10119634_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
                tbl_JOIN_INNER_TD_10119634_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name9_n);
                tbl_JOIN_INNER_TD_10119634_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag10_n);
                tbl_JOIN_INNER_TD_10119634_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country14_n);
                tbl_JOIN_INNER_TD_10119634_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login15_n);
                tbl_JOIN_INNER_TD_10119634_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address16_n);
                tbl_JOIN_INNER_TD_10119634_output.setInt64(r, 7, _ss_ext_discount_amt1220);
                tbl_JOIN_INNER_TD_10119634_output.setInt64(r, 8, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_10119634_output.setInt64(r, 9, _ss_ext_wholesale_cost1222);
                tbl_JOIN_INNER_TD_10119634_output.setInt64(r, 10, _ss_ext_list_price1223);
                tbl_JOIN_INNER_TD_10119634_output.setInt32(r, 11, _d_year126);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10119634_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10119634_key_rightMajor, SW_JOIN_INNER_TD_10119634_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_11270920_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_11270920_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_10119634_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_11270920_output.getInt32(i, 0);
            int32_t _d_year126 = tbl_Filter_TD_11270920_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_10119634_payload_rightMajor payloadA{_d_date_sk120, _d_year126};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_11823337_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_JOIN_INNER_TD_11823337_output.getInt32(i, 7);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10119634_key_rightMajor{_ss_sold_date_sk1206_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _d_year126 = (it->second)._d_year126;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1_n = tbl_JOIN_INNER_TD_11823337_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _c_customer_id1 = std::string(_c_customer_id1_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8_n = tbl_JOIN_INNER_TD_11823337_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_first_name8 = std::string(_c_first_name8_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name9_n = tbl_JOIN_INNER_TD_11823337_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_last_name9 = std::string(_c_last_name9_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10_n = tbl_JOIN_INNER_TD_11823337_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_preferred_cust_flag10 = std::string(_c_preferred_cust_flag10_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country14_n = tbl_JOIN_INNER_TD_11823337_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_birth_country14 = std::string(_c_birth_country14_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_login15_n = tbl_JOIN_INNER_TD_11823337_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _c_login15 = std::string(_c_login15_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address16_n = tbl_JOIN_INNER_TD_11823337_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _c_email_address16 = std::string(_c_email_address16_n.data());
                int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_11823337_output.getInt32(i, 7);
                int64_t _ss_ext_discount_amt1220 = tbl_JOIN_INNER_TD_11823337_output.getInt64(i, 8);
                int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_11823337_output.getInt64(i, 9);
                int64_t _ss_ext_wholesale_cost1222 = tbl_JOIN_INNER_TD_11823337_output.getInt64(i, 10);
                int64_t _ss_ext_list_price1223 = tbl_JOIN_INNER_TD_11823337_output.getInt64(i, 11);
                tbl_JOIN_INNER_TD_10119634_output.setInt32(r, 11, _d_year126);
                tbl_JOIN_INNER_TD_10119634_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id1_n);
                tbl_JOIN_INNER_TD_10119634_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8_n);
                tbl_JOIN_INNER_TD_10119634_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name9_n);
                tbl_JOIN_INNER_TD_10119634_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag10_n);
                tbl_JOIN_INNER_TD_10119634_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country14_n);
                tbl_JOIN_INNER_TD_10119634_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login15_n);
                tbl_JOIN_INNER_TD_10119634_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address16_n);
                tbl_JOIN_INNER_TD_10119634_output.setInt64(r, 7, _ss_ext_discount_amt1220);
                tbl_JOIN_INNER_TD_10119634_output.setInt64(r, 8, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_10119634_output.setInt64(r, 9, _ss_ext_wholesale_cost1222);
                tbl_JOIN_INNER_TD_10119634_output.setInt64(r, 10, _ss_ext_list_price1223);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10119634_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_10119634_output #Row: " << tbl_JOIN_INNER_TD_10119634_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9472472(Table &tbl_SerializeFromObject_TD_10827904_input, Table &tbl_Filter_TD_9472472_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#7948) AND (d_year#7948 = 2001)) AND isnotnull(d_date_sk#7942)))
    // Input: ListBuffer(d_date_sk#7942, d_year#7948)
    // Output: ListBuffer(d_date_sk#7942, d_year#7948)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10827904_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year7948 = tbl_SerializeFromObject_TD_10827904_input.getInt32(i, 1);
        int32_t _d_date_sk7942 = tbl_SerializeFromObject_TD_10827904_input.getInt32(i, 0);
        if (((_d_year7948!= 0) && (_d_year7948 == 2001)) && (_d_date_sk7942!= 0)) {
            int32_t _d_date_sk7942_t = tbl_SerializeFromObject_TD_10827904_input.getInt32(i, 0);
            tbl_Filter_TD_9472472_output.setInt32(r, 0, _d_date_sk7942_t);
            int32_t _d_year7948_t = tbl_SerializeFromObject_TD_10827904_input.getInt32(i, 1);
            tbl_Filter_TD_9472472_output.setInt32(r, 1, _d_year7948_t);
            r++;
        }
    }
    tbl_Filter_TD_9472472_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9472472_output #Row: " << tbl_Filter_TD_9472472_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_9827835_key_leftMajor {
    int32_t _c_customer_sk7890;
    bool operator==(const SW_JOIN_INNER_TD_9827835_key_leftMajor& other) const {
        return ((_c_customer_sk7890 == other._c_customer_sk7890));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9827835_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9827835_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk7890));
    }
};
}
struct SW_JOIN_INNER_TD_9827835_payload_leftMajor {
    int32_t _c_customer_sk7890;
    std::string _c_customer_id7891;
    std::string _c_first_name7898;
    std::string _c_last_name7899;
    std::string _c_preferred_cust_flag7900;
    std::string _c_birth_country7904;
    std::string _c_login7905;
    std::string _c_email_address7906;
};
struct SW_JOIN_INNER_TD_9827835_key_rightMajor {
    int32_t _ws_bill_customer_sk7912;
    bool operator==(const SW_JOIN_INNER_TD_9827835_key_rightMajor& other) const {
        return ((_ws_bill_customer_sk7912 == other._ws_bill_customer_sk7912));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9827835_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9827835_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_bill_customer_sk7912));
    }
};
}
struct SW_JOIN_INNER_TD_9827835_payload_rightMajor {
    int32_t _ws_sold_date_sk7908;
    int32_t _ws_bill_customer_sk7912;
    int64_t _ws_ext_discount_amt7930;
    int64_t _ws_ext_sales_price7931;
    int64_t _ws_ext_wholesale_cost7932;
    int64_t _ws_ext_list_price7933;
};
void SW_JOIN_INNER_TD_9827835(Table &tbl_Filter_TD_10966392_output, Table &tbl_Filter_TD_10440338_output, Table &tbl_JOIN_INNER_TD_9827835_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((c_customer_sk#7890 = ws_bill_customer_sk#7912))
    // Left Table: ListBuffer(c_customer_sk#7890, c_customer_id#7891, c_first_name#7898, c_last_name#7899, c_preferred_cust_flag#7900, c_birth_country#7904, c_login#7905, c_email_address#7906)
    // Right Table: ListBuffer(ws_sold_date_sk#7908, ws_bill_customer_sk#7912, ws_ext_discount_amt#7930, ws_ext_sales_price#7931, ws_ext_wholesale_cost#7932, ws_ext_list_price#7933)
    // Output Table: ListBuffer(c_customer_id#7891, c_first_name#7898, c_last_name#7899, c_preferred_cust_flag#7900, c_birth_country#7904, c_login#7905, c_email_address#7906, ws_sold_date_sk#7908, ws_ext_discount_amt#7930, ws_ext_sales_price#7931, ws_ext_wholesale_cost#7932, ws_ext_list_price#7933)
    int left_nrow = tbl_Filter_TD_10966392_output.getNumRow();
    int right_nrow = tbl_Filter_TD_10440338_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9827835_key_leftMajor, SW_JOIN_INNER_TD_9827835_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_10966392_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk7890_k = tbl_Filter_TD_10966392_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_9827835_key_leftMajor keyA{_c_customer_sk7890_k};
            int32_t _c_customer_sk7890 = tbl_Filter_TD_10966392_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7891_n = tbl_Filter_TD_10966392_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_customer_id7891 = std::string(_c_customer_id7891_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name7898_n = tbl_Filter_TD_10966392_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_first_name7898 = std::string(_c_first_name7898_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name7899_n = tbl_Filter_TD_10966392_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_last_name7899 = std::string(_c_last_name7899_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7900_n = tbl_Filter_TD_10966392_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_preferred_cust_flag7900 = std::string(_c_preferred_cust_flag7900_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7904_n = tbl_Filter_TD_10966392_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _c_birth_country7904 = std::string(_c_birth_country7904_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_login7905_n = tbl_Filter_TD_10966392_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _c_login7905 = std::string(_c_login7905_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address7906_n = tbl_Filter_TD_10966392_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _c_email_address7906 = std::string(_c_email_address7906_n.data());
            SW_JOIN_INNER_TD_9827835_payload_leftMajor payloadA{_c_customer_sk7890, _c_customer_id7891, _c_first_name7898, _c_last_name7899, _c_preferred_cust_flag7900, _c_birth_country7904, _c_login7905, _c_email_address7906};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_10440338_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_bill_customer_sk7912_k = tbl_Filter_TD_10440338_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9827835_key_leftMajor{_ws_bill_customer_sk7912_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk7890 = (it->second)._c_customer_sk7890;
                std::string _c_customer_id7891 = (it->second)._c_customer_id7891;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7891_n{};
                memcpy(_c_customer_id7891_n.data(), (_c_customer_id7891).data(), (_c_customer_id7891).length());
                std::string _c_first_name7898 = (it->second)._c_first_name7898;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name7898_n{};
                memcpy(_c_first_name7898_n.data(), (_c_first_name7898).data(), (_c_first_name7898).length());
                std::string _c_last_name7899 = (it->second)._c_last_name7899;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name7899_n{};
                memcpy(_c_last_name7899_n.data(), (_c_last_name7899).data(), (_c_last_name7899).length());
                std::string _c_preferred_cust_flag7900 = (it->second)._c_preferred_cust_flag7900;
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7900_n{};
                memcpy(_c_preferred_cust_flag7900_n.data(), (_c_preferred_cust_flag7900).data(), (_c_preferred_cust_flag7900).length());
                std::string _c_birth_country7904 = (it->second)._c_birth_country7904;
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7904_n{};
                memcpy(_c_birth_country7904_n.data(), (_c_birth_country7904).data(), (_c_birth_country7904).length());
                std::string _c_login7905 = (it->second)._c_login7905;
                std::array<char, TPCDS_READ_MAX + 1> _c_login7905_n{};
                memcpy(_c_login7905_n.data(), (_c_login7905).data(), (_c_login7905).length());
                std::string _c_email_address7906 = (it->second)._c_email_address7906;
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address7906_n{};
                memcpy(_c_email_address7906_n.data(), (_c_email_address7906).data(), (_c_email_address7906).length());
                int32_t _ws_sold_date_sk7908 = tbl_Filter_TD_10440338_output.getInt32(i, 0);
                int32_t _ws_bill_customer_sk7912 = tbl_Filter_TD_10440338_output.getInt32(i, 1);
                int64_t _ws_ext_discount_amt7930 = tbl_Filter_TD_10440338_output.getInt64(i, 2);
                int64_t _ws_ext_sales_price7931 = tbl_Filter_TD_10440338_output.getInt64(i, 3);
                int64_t _ws_ext_wholesale_cost7932 = tbl_Filter_TD_10440338_output.getInt64(i, 4);
                int64_t _ws_ext_list_price7933 = tbl_Filter_TD_10440338_output.getInt64(i, 5);
                tbl_JOIN_INNER_TD_9827835_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id7891_n);
                tbl_JOIN_INNER_TD_9827835_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name7898_n);
                tbl_JOIN_INNER_TD_9827835_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name7899_n);
                tbl_JOIN_INNER_TD_9827835_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag7900_n);
                tbl_JOIN_INNER_TD_9827835_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country7904_n);
                tbl_JOIN_INNER_TD_9827835_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login7905_n);
                tbl_JOIN_INNER_TD_9827835_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address7906_n);
                tbl_JOIN_INNER_TD_9827835_output.setInt32(r, 7, _ws_sold_date_sk7908);
                tbl_JOIN_INNER_TD_9827835_output.setInt64(r, 8, _ws_ext_discount_amt7930);
                tbl_JOIN_INNER_TD_9827835_output.setInt64(r, 9, _ws_ext_sales_price7931);
                tbl_JOIN_INNER_TD_9827835_output.setInt64(r, 10, _ws_ext_wholesale_cost7932);
                tbl_JOIN_INNER_TD_9827835_output.setInt64(r, 11, _ws_ext_list_price7933);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9827835_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9827835_key_rightMajor, SW_JOIN_INNER_TD_9827835_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_10440338_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_bill_customer_sk7912_k = tbl_Filter_TD_10440338_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_9827835_key_rightMajor keyA{_ws_bill_customer_sk7912_k};
            int32_t _ws_sold_date_sk7908 = tbl_Filter_TD_10440338_output.getInt32(i, 0);
            int32_t _ws_bill_customer_sk7912 = tbl_Filter_TD_10440338_output.getInt32(i, 1);
            int64_t _ws_ext_discount_amt7930 = tbl_Filter_TD_10440338_output.getInt64(i, 2);
            int64_t _ws_ext_sales_price7931 = tbl_Filter_TD_10440338_output.getInt64(i, 3);
            int64_t _ws_ext_wholesale_cost7932 = tbl_Filter_TD_10440338_output.getInt64(i, 4);
            int64_t _ws_ext_list_price7933 = tbl_Filter_TD_10440338_output.getInt64(i, 5);
            SW_JOIN_INNER_TD_9827835_payload_rightMajor payloadA{_ws_sold_date_sk7908, _ws_bill_customer_sk7912, _ws_ext_discount_amt7930, _ws_ext_sales_price7931, _ws_ext_wholesale_cost7932, _ws_ext_list_price7933};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_10966392_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk7890_k = tbl_Filter_TD_10966392_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9827835_key_rightMajor{_c_customer_sk7890_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_date_sk7908 = (it->second)._ws_sold_date_sk7908;
                int32_t _ws_bill_customer_sk7912 = (it->second)._ws_bill_customer_sk7912;
                int64_t _ws_ext_discount_amt7930 = (it->second)._ws_ext_discount_amt7930;
                int64_t _ws_ext_sales_price7931 = (it->second)._ws_ext_sales_price7931;
                int64_t _ws_ext_wholesale_cost7932 = (it->second)._ws_ext_wholesale_cost7932;
                int64_t _ws_ext_list_price7933 = (it->second)._ws_ext_list_price7933;
                int32_t _c_customer_sk7890 = tbl_Filter_TD_10966392_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7891_n = tbl_Filter_TD_10966392_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_customer_id7891 = std::string(_c_customer_id7891_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name7898_n = tbl_Filter_TD_10966392_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_first_name7898 = std::string(_c_first_name7898_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name7899_n = tbl_Filter_TD_10966392_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_last_name7899 = std::string(_c_last_name7899_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7900_n = tbl_Filter_TD_10966392_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_preferred_cust_flag7900 = std::string(_c_preferred_cust_flag7900_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7904_n = tbl_Filter_TD_10966392_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _c_birth_country7904 = std::string(_c_birth_country7904_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_login7905_n = tbl_Filter_TD_10966392_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _c_login7905 = std::string(_c_login7905_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address7906_n = tbl_Filter_TD_10966392_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _c_email_address7906 = std::string(_c_email_address7906_n.data());
                tbl_JOIN_INNER_TD_9827835_output.setInt32(r, 7, _ws_sold_date_sk7908);
                tbl_JOIN_INNER_TD_9827835_output.setInt64(r, 8, _ws_ext_discount_amt7930);
                tbl_JOIN_INNER_TD_9827835_output.setInt64(r, 9, _ws_ext_sales_price7931);
                tbl_JOIN_INNER_TD_9827835_output.setInt64(r, 10, _ws_ext_wholesale_cost7932);
                tbl_JOIN_INNER_TD_9827835_output.setInt64(r, 11, _ws_ext_list_price7933);
                tbl_JOIN_INNER_TD_9827835_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id7891_n);
                tbl_JOIN_INNER_TD_9827835_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name7898_n);
                tbl_JOIN_INNER_TD_9827835_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name7899_n);
                tbl_JOIN_INNER_TD_9827835_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag7900_n);
                tbl_JOIN_INNER_TD_9827835_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country7904_n);
                tbl_JOIN_INNER_TD_9827835_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login7905_n);
                tbl_JOIN_INNER_TD_9827835_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address7906_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9827835_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_9827835_output #Row: " << tbl_JOIN_INNER_TD_9827835_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9343399(Table &tbl_SerializeFromObject_TD_1065884_input, Table &tbl_Filter_TD_9343399_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cs_bill_customer_sk#7592) AND isnotnull(cs_sold_date_sk#7589)))
    // Input: ListBuffer(cs_sold_date_sk#7589, cs_bill_customer_sk#7592)
    // Output: ListBuffer(cs_sold_date_sk#7589, cs_bill_customer_sk#7592)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1065884_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_bill_customer_sk7592 = tbl_SerializeFromObject_TD_1065884_input.getInt32(i, 1);
        int32_t _cs_sold_date_sk7589 = tbl_SerializeFromObject_TD_1065884_input.getInt32(i, 0);
        if ((_cs_bill_customer_sk7592!= 0) && (_cs_sold_date_sk7589!= 0)) {
            int32_t _cs_sold_date_sk7589_t = tbl_SerializeFromObject_TD_1065884_input.getInt32(i, 0);
            tbl_Filter_TD_9343399_output.setInt32(r, 0, _cs_sold_date_sk7589_t);
            int32_t _cs_bill_customer_sk7592_t = tbl_SerializeFromObject_TD_1065884_input.getInt32(i, 1);
            tbl_Filter_TD_9343399_output.setInt32(r, 1, _cs_bill_customer_sk7592_t);
            r++;
        }
    }
    tbl_Filter_TD_9343399_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9343399_output #Row: " << tbl_Filter_TD_9343399_output.getNumRow() << std::endl;
}

void SW_Filter_TD_990363(Table &tbl_SerializeFromObject_TD_10360779_input, Table &tbl_Filter_TD_990363_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(c_customer_sk#7571) AND isnotnull(c_customer_id#7572)))
    // Input: ListBuffer(c_customer_sk#7571, c_customer_id#7572, c_first_name#7579, c_last_name#7580, c_preferred_cust_flag#7581, c_birth_country#7585, c_login#7586, c_email_address#7587)
    // Output: ListBuffer(c_customer_sk#7571, c_customer_id#7572, c_first_name#7579, c_last_name#7580, c_preferred_cust_flag#7581, c_birth_country#7585, c_login#7586, c_email_address#7587)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10360779_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk7571 = tbl_SerializeFromObject_TD_10360779_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7572 = tbl_SerializeFromObject_TD_10360779_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_c_customer_sk7571!= 0) && _c_customer_id7572.data() != "NULL") {
            int32_t _c_customer_sk7571_t = tbl_SerializeFromObject_TD_10360779_input.getInt32(i, 0);
            tbl_Filter_TD_990363_output.setInt32(r, 0, _c_customer_sk7571_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7572_t = tbl_SerializeFromObject_TD_10360779_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_990363_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_customer_id7572_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name7579_t = tbl_SerializeFromObject_TD_10360779_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_990363_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name7579_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name7580_t = tbl_SerializeFromObject_TD_10360779_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_990363_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name7580_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7581_t = tbl_SerializeFromObject_TD_10360779_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            tbl_Filter_TD_990363_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_preferred_cust_flag7581_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7585_t = tbl_SerializeFromObject_TD_10360779_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            tbl_Filter_TD_990363_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_birth_country7585_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_login7586_t = tbl_SerializeFromObject_TD_10360779_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            tbl_Filter_TD_990363_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_login7586_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address7587_t = tbl_SerializeFromObject_TD_10360779_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            tbl_Filter_TD_990363_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _c_email_address7587_t);
            r++;
        }
    }
    tbl_Filter_TD_990363_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_990363_output #Row: " << tbl_Filter_TD_990363_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_919589_key {
    std::string _c_customer_id7333;
    std::string _c_first_name7340;
    std::string _c_last_name7341;
    std::string _c_preferred_cust_flag7342;
    std::string _c_birth_country7346;
    std::string _c_login7347;
    std::string _c_email_address7348;
    int32_t _d_year7390;
    bool operator==(const SW_Aggregate_TD_919589_key& other) const { return (_c_customer_id7333 == other._c_customer_id7333) && (_c_first_name7340 == other._c_first_name7340) && (_c_last_name7341 == other._c_last_name7341) && (_c_preferred_cust_flag7342 == other._c_preferred_cust_flag7342) && (_c_birth_country7346 == other._c_birth_country7346) && (_c_login7347 == other._c_login7347) && (_c_email_address7348 == other._c_email_address7348) && (_d_year7390 == other._d_year7390); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_919589_key> {
    std::size_t operator() (const SW_Aggregate_TD_919589_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._c_customer_id7333)) + (hash<string>()(k._c_first_name7340)) + (hash<string>()(k._c_last_name7341)) + (hash<string>()(k._c_preferred_cust_flag7342)) + (hash<string>()(k._c_birth_country7346)) + (hash<string>()(k._c_login7347)) + (hash<string>()(k._c_email_address7348)) + (hash<int32_t>()(k._d_year7390));
    }
};
}
struct SW_Aggregate_TD_919589_payload {
    std::string _customer_id4160;
    int64_t _year_total4168_sum_0;
};
void SW_Aggregate_TD_919589(Table &tbl_JOIN_INNER_TD_10185218_output, Table &tbl_Aggregate_TD_919589_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_customer_id#7333, c_first_name#7340, c_last_name#7341, c_preferred_cust_flag#7342, c_birth_country#7346, c_login#7347, c_email_address#7348, d_year#7390, c_customer_id#7333 AS customer_id#4160, sum(CheckOverflow((promote_precision(CheckOverflow((promote_precision(cast(CheckOverflow((promote_precision(cast(CheckOverflow((promote_precision(cast(cs_ext_list_price#7375 as decimal(8,2))) - promote_precision(cast(cs_ext_wholesale_cost#7374 as decimal(8,2)))), DecimalType(8,2), true) as decimal(9,2))) - promote_precision(cast(cs_ext_discount_amt#7372 as decimal(9,2)))), DecimalType(9,2), true) as decimal(10,2))) + promote_precision(cast(cs_ext_sales_price#7373 as decimal(10,2)))), DecimalType(10,2), true)) / 2.00), DecimalType(14,6), true)) AS year_total#4168)
    // Input: ListBuffer(c_customer_id#7333, c_first_name#7340, c_last_name#7341, c_preferred_cust_flag#7342, c_birth_country#7346, c_login#7347, c_email_address#7348, cs_ext_discount_amt#7372, cs_ext_sales_price#7373, cs_ext_wholesale_cost#7374, cs_ext_list_price#7375, d_year#7390)
    // Output: ListBuffer(customer_id#4160, year_total#4168)
    std::unordered_map<SW_Aggregate_TD_919589_key, SW_Aggregate_TD_919589_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_10185218_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7333 = tbl_JOIN_INNER_TD_10185218_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name7340 = tbl_JOIN_INNER_TD_10185218_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name7341 = tbl_JOIN_INNER_TD_10185218_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7342 = tbl_JOIN_INNER_TD_10185218_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7346 = tbl_JOIN_INNER_TD_10185218_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _c_login7347 = tbl_JOIN_INNER_TD_10185218_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _c_email_address7348 = tbl_JOIN_INNER_TD_10185218_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        int64_t _cs_ext_discount_amt7372 = tbl_JOIN_INNER_TD_10185218_output.getInt64(i, 7);
        int64_t _cs_ext_sales_price7373 = tbl_JOIN_INNER_TD_10185218_output.getInt64(i, 8);
        int64_t _cs_ext_wholesale_cost7374 = tbl_JOIN_INNER_TD_10185218_output.getInt64(i, 9);
        int64_t _cs_ext_list_price7375 = tbl_JOIN_INNER_TD_10185218_output.getInt64(i, 10);
        int32_t _d_year7390 = tbl_JOIN_INNER_TD_10185218_output.getInt32(i, 11);
        SW_Aggregate_TD_919589_key k{std::string(_c_customer_id7333.data()), std::string(_c_first_name7340.data()), std::string(_c_last_name7341.data()), std::string(_c_preferred_cust_flag7342.data()), std::string(_c_birth_country7346.data()), std::string(_c_login7347.data()), std::string(_c_email_address7348.data()), _d_year7390};
        std::array<char, TPCDS_READ_MAX + 1> _customer_id4160 = _c_customer_id7333;
        int64_t _year_total4168_sum_0 = ((((_cs_ext_list_price7375 - _cs_ext_wholesale_cost7374) - _cs_ext_discount_amt7372) + _cs_ext_sales_price7373) / 2.00);
        SW_Aggregate_TD_919589_payload p{std::string(_customer_id4160.data()), _year_total4168_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._year_total4168_sum_0 + _year_total4168_sum_0;
            p._year_total4168_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _c_customer_id7333 not required in the output table
        // _c_first_name7340 not required in the output table
        // _c_last_name7341 not required in the output table
        // _c_preferred_cust_flag7342 not required in the output table
        // _c_birth_country7346 not required in the output table
        // _c_login7347 not required in the output table
        // _c_email_address7348 not required in the output table
        // _d_year7390 not required in the output table
        std::array<char, TPCDS_READ_MAX + 1> _customer_id4160_n{};
        memcpy(_customer_id4160_n.data(), (it.second)._customer_id4160.data(), (it.second)._customer_id4160.length());
        tbl_Aggregate_TD_919589_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id4160_n);
        int64_t _year_total4168 = (it.second)._year_total4168_sum_0;
        tbl_Aggregate_TD_919589_output.setInt64(r, 1, _year_total4168);
        ++r;
    }
    tbl_Aggregate_TD_919589_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_919589_output #Row: " << tbl_Aggregate_TD_919589_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_9331224_key_leftMajor {
    int32_t _ss_sold_date_sk7042;
    bool operator==(const SW_JOIN_INNER_TD_9331224_key_leftMajor& other) const {
        return ((_ss_sold_date_sk7042 == other._ss_sold_date_sk7042));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9331224_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9331224_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_sold_date_sk7042));
    }
};
}
struct SW_JOIN_INNER_TD_9331224_payload_leftMajor {
    std::string _c_customer_id7025;
    std::string _c_first_name7032;
    std::string _c_last_name7033;
    std::string _c_preferred_cust_flag7034;
    std::string _c_birth_country7038;
    std::string _c_login7039;
    std::string _c_email_address7040;
    int32_t _ss_sold_date_sk7042;
};
struct SW_JOIN_INNER_TD_9331224_key_rightMajor {
    int32_t _d_date_sk7065;
    bool operator==(const SW_JOIN_INNER_TD_9331224_key_rightMajor& other) const {
        return ((_d_date_sk7065 == other._d_date_sk7065));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9331224_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9331224_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk7065));
    }
};
}
struct SW_JOIN_INNER_TD_9331224_payload_rightMajor {
    int32_t _d_date_sk7065;
    int32_t _d_year7071;
};
void SW_JOIN_INNER_TD_9331224(Table &tbl_JOIN_INNER_TD_10915984_output, Table &tbl_Filter_TD_10239172_output, Table &tbl_JOIN_INNER_TD_9331224_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#7042 = d_date_sk#7065))
    // Left Table: ListBuffer(c_customer_id#7025, c_first_name#7032, c_last_name#7033, c_preferred_cust_flag#7034, c_birth_country#7038, c_login#7039, c_email_address#7040, ss_sold_date_sk#7042)
    // Right Table: ListBuffer(d_date_sk#7065, d_year#7071)
    // Output Table: ListBuffer(c_customer_id#7025, c_first_name#7032, c_last_name#7033, c_preferred_cust_flag#7034, c_birth_country#7038, c_login#7039, c_email_address#7040, d_year#7071)
    int left_nrow = tbl_JOIN_INNER_TD_10915984_output.getNumRow();
    int right_nrow = tbl_Filter_TD_10239172_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9331224_key_leftMajor, SW_JOIN_INNER_TD_9331224_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_10915984_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_sold_date_sk7042_k = tbl_JOIN_INNER_TD_10915984_output.getInt32(i, 7);
            SW_JOIN_INNER_TD_9331224_key_leftMajor keyA{_ss_sold_date_sk7042_k};
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7025_n = tbl_JOIN_INNER_TD_10915984_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _c_customer_id7025 = std::string(_c_customer_id7025_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name7032_n = tbl_JOIN_INNER_TD_10915984_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_first_name7032 = std::string(_c_first_name7032_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name7033_n = tbl_JOIN_INNER_TD_10915984_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_last_name7033 = std::string(_c_last_name7033_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7034_n = tbl_JOIN_INNER_TD_10915984_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_preferred_cust_flag7034 = std::string(_c_preferred_cust_flag7034_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7038_n = tbl_JOIN_INNER_TD_10915984_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_birth_country7038 = std::string(_c_birth_country7038_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_login7039_n = tbl_JOIN_INNER_TD_10915984_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _c_login7039 = std::string(_c_login7039_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address7040_n = tbl_JOIN_INNER_TD_10915984_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _c_email_address7040 = std::string(_c_email_address7040_n.data());
            int32_t _ss_sold_date_sk7042 = tbl_JOIN_INNER_TD_10915984_output.getInt32(i, 7);
            SW_JOIN_INNER_TD_9331224_payload_leftMajor payloadA{_c_customer_id7025, _c_first_name7032, _c_last_name7033, _c_preferred_cust_flag7034, _c_birth_country7038, _c_login7039, _c_email_address7040, _ss_sold_date_sk7042};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_10239172_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk7065_k = tbl_Filter_TD_10239172_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9331224_key_leftMajor{_d_date_sk7065_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _c_customer_id7025 = (it->second)._c_customer_id7025;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7025_n{};
                memcpy(_c_customer_id7025_n.data(), (_c_customer_id7025).data(), (_c_customer_id7025).length());
                std::string _c_first_name7032 = (it->second)._c_first_name7032;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name7032_n{};
                memcpy(_c_first_name7032_n.data(), (_c_first_name7032).data(), (_c_first_name7032).length());
                std::string _c_last_name7033 = (it->second)._c_last_name7033;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name7033_n{};
                memcpy(_c_last_name7033_n.data(), (_c_last_name7033).data(), (_c_last_name7033).length());
                std::string _c_preferred_cust_flag7034 = (it->second)._c_preferred_cust_flag7034;
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7034_n{};
                memcpy(_c_preferred_cust_flag7034_n.data(), (_c_preferred_cust_flag7034).data(), (_c_preferred_cust_flag7034).length());
                std::string _c_birth_country7038 = (it->second)._c_birth_country7038;
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7038_n{};
                memcpy(_c_birth_country7038_n.data(), (_c_birth_country7038).data(), (_c_birth_country7038).length());
                std::string _c_login7039 = (it->second)._c_login7039;
                std::array<char, TPCDS_READ_MAX + 1> _c_login7039_n{};
                memcpy(_c_login7039_n.data(), (_c_login7039).data(), (_c_login7039).length());
                std::string _c_email_address7040 = (it->second)._c_email_address7040;
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address7040_n{};
                memcpy(_c_email_address7040_n.data(), (_c_email_address7040).data(), (_c_email_address7040).length());
                int32_t _ss_sold_date_sk7042 = (it->second)._ss_sold_date_sk7042;
                int32_t _d_date_sk7065 = tbl_Filter_TD_10239172_output.getInt32(i, 0);
                int32_t _d_year7071 = tbl_Filter_TD_10239172_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_9331224_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id7025_n);
                tbl_JOIN_INNER_TD_9331224_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name7032_n);
                tbl_JOIN_INNER_TD_9331224_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name7033_n);
                tbl_JOIN_INNER_TD_9331224_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag7034_n);
                tbl_JOIN_INNER_TD_9331224_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country7038_n);
                tbl_JOIN_INNER_TD_9331224_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login7039_n);
                tbl_JOIN_INNER_TD_9331224_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address7040_n);
                tbl_JOIN_INNER_TD_9331224_output.setInt32(r, 7, _d_year7071);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9331224_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9331224_key_rightMajor, SW_JOIN_INNER_TD_9331224_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_10239172_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk7065_k = tbl_Filter_TD_10239172_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_9331224_key_rightMajor keyA{_d_date_sk7065_k};
            int32_t _d_date_sk7065 = tbl_Filter_TD_10239172_output.getInt32(i, 0);
            int32_t _d_year7071 = tbl_Filter_TD_10239172_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_9331224_payload_rightMajor payloadA{_d_date_sk7065, _d_year7071};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_10915984_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_sold_date_sk7042_k = tbl_JOIN_INNER_TD_10915984_output.getInt32(i, 7);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9331224_key_rightMajor{_ss_sold_date_sk7042_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk7065 = (it->second)._d_date_sk7065;
                int32_t _d_year7071 = (it->second)._d_year7071;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7025_n = tbl_JOIN_INNER_TD_10915984_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _c_customer_id7025 = std::string(_c_customer_id7025_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name7032_n = tbl_JOIN_INNER_TD_10915984_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_first_name7032 = std::string(_c_first_name7032_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name7033_n = tbl_JOIN_INNER_TD_10915984_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_last_name7033 = std::string(_c_last_name7033_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7034_n = tbl_JOIN_INNER_TD_10915984_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_preferred_cust_flag7034 = std::string(_c_preferred_cust_flag7034_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7038_n = tbl_JOIN_INNER_TD_10915984_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_birth_country7038 = std::string(_c_birth_country7038_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_login7039_n = tbl_JOIN_INNER_TD_10915984_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _c_login7039 = std::string(_c_login7039_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address7040_n = tbl_JOIN_INNER_TD_10915984_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _c_email_address7040 = std::string(_c_email_address7040_n.data());
                int32_t _ss_sold_date_sk7042 = tbl_JOIN_INNER_TD_10915984_output.getInt32(i, 7);
                tbl_JOIN_INNER_TD_9331224_output.setInt32(r, 7, _d_year7071);
                tbl_JOIN_INNER_TD_9331224_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id7025_n);
                tbl_JOIN_INNER_TD_9331224_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name7032_n);
                tbl_JOIN_INNER_TD_9331224_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name7033_n);
                tbl_JOIN_INNER_TD_9331224_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag7034_n);
                tbl_JOIN_INNER_TD_9331224_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country7038_n);
                tbl_JOIN_INNER_TD_9331224_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login7039_n);
                tbl_JOIN_INNER_TD_9331224_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address7040_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9331224_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_9331224_output #Row: " << tbl_JOIN_INNER_TD_9331224_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_9482711_key {
    std::string _c_customer_id1;
    std::string _c_first_name8;
    std::string _c_last_name9;
    std::string _c_preferred_cust_flag10;
    std::string _c_birth_country14;
    std::string _c_login15;
    std::string _c_email_address16;
    int32_t _d_year126;
    bool operator==(const SW_Aggregate_TD_9482711_key& other) const { return (_c_customer_id1 == other._c_customer_id1) && (_c_first_name8 == other._c_first_name8) && (_c_last_name9 == other._c_last_name9) && (_c_preferred_cust_flag10 == other._c_preferred_cust_flag10) && (_c_birth_country14 == other._c_birth_country14) && (_c_login15 == other._c_login15) && (_c_email_address16 == other._c_email_address16) && (_d_year126 == other._d_year126); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_9482711_key> {
    std::size_t operator() (const SW_Aggregate_TD_9482711_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._c_customer_id1)) + (hash<string>()(k._c_first_name8)) + (hash<string>()(k._c_last_name9)) + (hash<string>()(k._c_preferred_cust_flag10)) + (hash<string>()(k._c_birth_country14)) + (hash<string>()(k._c_login15)) + (hash<string>()(k._c_email_address16)) + (hash<int32_t>()(k._d_year126));
    }
};
}
struct SW_Aggregate_TD_9482711_payload {
    std::string _customer_id4150;
    int64_t _year_total4158_sum_0;
};
void SW_Aggregate_TD_9482711(Table &tbl_JOIN_INNER_TD_10119634_output, Table &tbl_Aggregate_TD_9482711_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_customer_id#1, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_country#14, c_login#15, c_email_address#16, d_year#126, c_customer_id#1 AS customer_id#4150, sum(CheckOverflow((promote_precision(CheckOverflow((promote_precision(cast(CheckOverflow((promote_precision(cast(CheckOverflow((promote_precision(cast(ss_ext_list_price#1223 as decimal(8,2))) - promote_precision(cast(ss_ext_wholesale_cost#1222 as decimal(8,2)))), DecimalType(8,2), true) as decimal(9,2))) - promote_precision(cast(ss_ext_discount_amt#1220 as decimal(9,2)))), DecimalType(9,2), true) as decimal(10,2))) + promote_precision(cast(ss_ext_sales_price#1221 as decimal(10,2)))), DecimalType(10,2), true)) / 2.00), DecimalType(14,6), true)) AS year_total#4158)
    // Input: ListBuffer(c_customer_id#1, c_first_name#8, c_last_name#9, c_preferred_cust_flag#10, c_birth_country#14, c_login#15, c_email_address#16, ss_ext_discount_amt#1220, ss_ext_sales_price#1221, ss_ext_wholesale_cost#1222, ss_ext_list_price#1223, d_year#126)
    // Output: ListBuffer(customer_id#4150, year_total#4158)
    std::unordered_map<SW_Aggregate_TD_9482711_key, SW_Aggregate_TD_9482711_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_10119634_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id1 = tbl_JOIN_INNER_TD_10119634_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8 = tbl_JOIN_INNER_TD_10119634_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name9 = tbl_JOIN_INNER_TD_10119634_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag10 = tbl_JOIN_INNER_TD_10119634_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _c_birth_country14 = tbl_JOIN_INNER_TD_10119634_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _c_login15 = tbl_JOIN_INNER_TD_10119634_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _c_email_address16 = tbl_JOIN_INNER_TD_10119634_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        int64_t _ss_ext_discount_amt1220 = tbl_JOIN_INNER_TD_10119634_output.getInt64(i, 7);
        int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_10119634_output.getInt64(i, 8);
        int64_t _ss_ext_wholesale_cost1222 = tbl_JOIN_INNER_TD_10119634_output.getInt64(i, 9);
        int64_t _ss_ext_list_price1223 = tbl_JOIN_INNER_TD_10119634_output.getInt64(i, 10);
        int32_t _d_year126 = tbl_JOIN_INNER_TD_10119634_output.getInt32(i, 11);
        SW_Aggregate_TD_9482711_key k{std::string(_c_customer_id1.data()), std::string(_c_first_name8.data()), std::string(_c_last_name9.data()), std::string(_c_preferred_cust_flag10.data()), std::string(_c_birth_country14.data()), std::string(_c_login15.data()), std::string(_c_email_address16.data()), _d_year126};
        std::array<char, TPCDS_READ_MAX + 1> _customer_id4150 = _c_customer_id1;
        int64_t _year_total4158_sum_0 = ((((_ss_ext_list_price1223 - _ss_ext_wholesale_cost1222) - _ss_ext_discount_amt1220) + _ss_ext_sales_price1221) / 2.00);
        SW_Aggregate_TD_9482711_payload p{std::string(_customer_id4150.data()), _year_total4158_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._year_total4158_sum_0 + _year_total4158_sum_0;
            p._year_total4158_sum_0 = sum_0;
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
        std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_n{};
        memcpy(_customer_id4150_n.data(), (it.second)._customer_id4150.data(), (it.second)._customer_id4150.length());
        tbl_Aggregate_TD_9482711_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id4150_n);
        int64_t _year_total4158 = (it.second)._year_total4158_sum_0;
        tbl_Aggregate_TD_9482711_output.setInt64(r, 1, _year_total4158);
        ++r;
    }
    tbl_Aggregate_TD_9482711_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_9482711_output #Row: " << tbl_Aggregate_TD_9482711_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8303630_key_leftMajor {
    int32_t _ws_sold_date_sk7908;
    bool operator==(const SW_JOIN_INNER_TD_8303630_key_leftMajor& other) const {
        return ((_ws_sold_date_sk7908 == other._ws_sold_date_sk7908));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8303630_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8303630_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_sold_date_sk7908));
    }
};
}
struct SW_JOIN_INNER_TD_8303630_payload_leftMajor {
    std::string _c_customer_id7891;
    std::string _c_first_name7898;
    std::string _c_last_name7899;
    std::string _c_preferred_cust_flag7900;
    std::string _c_birth_country7904;
    std::string _c_login7905;
    std::string _c_email_address7906;
    int32_t _ws_sold_date_sk7908;
    int64_t _ws_ext_discount_amt7930;
    int64_t _ws_ext_sales_price7931;
    int64_t _ws_ext_wholesale_cost7932;
    int64_t _ws_ext_list_price7933;
};
struct SW_JOIN_INNER_TD_8303630_key_rightMajor {
    int32_t _d_date_sk7942;
    bool operator==(const SW_JOIN_INNER_TD_8303630_key_rightMajor& other) const {
        return ((_d_date_sk7942 == other._d_date_sk7942));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8303630_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8303630_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk7942));
    }
};
}
struct SW_JOIN_INNER_TD_8303630_payload_rightMajor {
    int32_t _d_date_sk7942;
    int32_t _d_year7948;
};
void SW_JOIN_INNER_TD_8303630(Table &tbl_JOIN_INNER_TD_9827835_output, Table &tbl_Filter_TD_9472472_output, Table &tbl_JOIN_INNER_TD_8303630_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_sold_date_sk#7908 = d_date_sk#7942))
    // Left Table: ListBuffer(c_customer_id#7891, c_first_name#7898, c_last_name#7899, c_preferred_cust_flag#7900, c_birth_country#7904, c_login#7905, c_email_address#7906, ws_sold_date_sk#7908, ws_ext_discount_amt#7930, ws_ext_sales_price#7931, ws_ext_wholesale_cost#7932, ws_ext_list_price#7933)
    // Right Table: ListBuffer(d_date_sk#7942, d_year#7948)
    // Output Table: ListBuffer(c_customer_id#7891, c_first_name#7898, c_last_name#7899, c_preferred_cust_flag#7900, c_birth_country#7904, c_login#7905, c_email_address#7906, ws_ext_discount_amt#7930, ws_ext_sales_price#7931, ws_ext_wholesale_cost#7932, ws_ext_list_price#7933, d_year#7948)
    int left_nrow = tbl_JOIN_INNER_TD_9827835_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9472472_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8303630_key_leftMajor, SW_JOIN_INNER_TD_8303630_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_9827835_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_sold_date_sk7908_k = tbl_JOIN_INNER_TD_9827835_output.getInt32(i, 7);
            SW_JOIN_INNER_TD_8303630_key_leftMajor keyA{_ws_sold_date_sk7908_k};
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7891_n = tbl_JOIN_INNER_TD_9827835_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _c_customer_id7891 = std::string(_c_customer_id7891_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name7898_n = tbl_JOIN_INNER_TD_9827835_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_first_name7898 = std::string(_c_first_name7898_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name7899_n = tbl_JOIN_INNER_TD_9827835_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_last_name7899 = std::string(_c_last_name7899_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7900_n = tbl_JOIN_INNER_TD_9827835_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_preferred_cust_flag7900 = std::string(_c_preferred_cust_flag7900_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7904_n = tbl_JOIN_INNER_TD_9827835_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_birth_country7904 = std::string(_c_birth_country7904_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_login7905_n = tbl_JOIN_INNER_TD_9827835_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _c_login7905 = std::string(_c_login7905_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address7906_n = tbl_JOIN_INNER_TD_9827835_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _c_email_address7906 = std::string(_c_email_address7906_n.data());
            int32_t _ws_sold_date_sk7908 = tbl_JOIN_INNER_TD_9827835_output.getInt32(i, 7);
            int64_t _ws_ext_discount_amt7930 = tbl_JOIN_INNER_TD_9827835_output.getInt64(i, 8);
            int64_t _ws_ext_sales_price7931 = tbl_JOIN_INNER_TD_9827835_output.getInt64(i, 9);
            int64_t _ws_ext_wholesale_cost7932 = tbl_JOIN_INNER_TD_9827835_output.getInt64(i, 10);
            int64_t _ws_ext_list_price7933 = tbl_JOIN_INNER_TD_9827835_output.getInt64(i, 11);
            SW_JOIN_INNER_TD_8303630_payload_leftMajor payloadA{_c_customer_id7891, _c_first_name7898, _c_last_name7899, _c_preferred_cust_flag7900, _c_birth_country7904, _c_login7905, _c_email_address7906, _ws_sold_date_sk7908, _ws_ext_discount_amt7930, _ws_ext_sales_price7931, _ws_ext_wholesale_cost7932, _ws_ext_list_price7933};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9472472_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk7942_k = tbl_Filter_TD_9472472_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8303630_key_leftMajor{_d_date_sk7942_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _c_customer_id7891 = (it->second)._c_customer_id7891;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7891_n{};
                memcpy(_c_customer_id7891_n.data(), (_c_customer_id7891).data(), (_c_customer_id7891).length());
                std::string _c_first_name7898 = (it->second)._c_first_name7898;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name7898_n{};
                memcpy(_c_first_name7898_n.data(), (_c_first_name7898).data(), (_c_first_name7898).length());
                std::string _c_last_name7899 = (it->second)._c_last_name7899;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name7899_n{};
                memcpy(_c_last_name7899_n.data(), (_c_last_name7899).data(), (_c_last_name7899).length());
                std::string _c_preferred_cust_flag7900 = (it->second)._c_preferred_cust_flag7900;
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7900_n{};
                memcpy(_c_preferred_cust_flag7900_n.data(), (_c_preferred_cust_flag7900).data(), (_c_preferred_cust_flag7900).length());
                std::string _c_birth_country7904 = (it->second)._c_birth_country7904;
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7904_n{};
                memcpy(_c_birth_country7904_n.data(), (_c_birth_country7904).data(), (_c_birth_country7904).length());
                std::string _c_login7905 = (it->second)._c_login7905;
                std::array<char, TPCDS_READ_MAX + 1> _c_login7905_n{};
                memcpy(_c_login7905_n.data(), (_c_login7905).data(), (_c_login7905).length());
                std::string _c_email_address7906 = (it->second)._c_email_address7906;
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address7906_n{};
                memcpy(_c_email_address7906_n.data(), (_c_email_address7906).data(), (_c_email_address7906).length());
                int32_t _ws_sold_date_sk7908 = (it->second)._ws_sold_date_sk7908;
                int64_t _ws_ext_discount_amt7930 = (it->second)._ws_ext_discount_amt7930;
                int64_t _ws_ext_sales_price7931 = (it->second)._ws_ext_sales_price7931;
                int64_t _ws_ext_wholesale_cost7932 = (it->second)._ws_ext_wholesale_cost7932;
                int64_t _ws_ext_list_price7933 = (it->second)._ws_ext_list_price7933;
                int32_t _d_date_sk7942 = tbl_Filter_TD_9472472_output.getInt32(i, 0);
                int32_t _d_year7948 = tbl_Filter_TD_9472472_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_8303630_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id7891_n);
                tbl_JOIN_INNER_TD_8303630_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name7898_n);
                tbl_JOIN_INNER_TD_8303630_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name7899_n);
                tbl_JOIN_INNER_TD_8303630_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag7900_n);
                tbl_JOIN_INNER_TD_8303630_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country7904_n);
                tbl_JOIN_INNER_TD_8303630_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login7905_n);
                tbl_JOIN_INNER_TD_8303630_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address7906_n);
                tbl_JOIN_INNER_TD_8303630_output.setInt64(r, 7, _ws_ext_discount_amt7930);
                tbl_JOIN_INNER_TD_8303630_output.setInt64(r, 8, _ws_ext_sales_price7931);
                tbl_JOIN_INNER_TD_8303630_output.setInt64(r, 9, _ws_ext_wholesale_cost7932);
                tbl_JOIN_INNER_TD_8303630_output.setInt64(r, 10, _ws_ext_list_price7933);
                tbl_JOIN_INNER_TD_8303630_output.setInt32(r, 11, _d_year7948);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8303630_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8303630_key_rightMajor, SW_JOIN_INNER_TD_8303630_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9472472_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk7942_k = tbl_Filter_TD_9472472_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8303630_key_rightMajor keyA{_d_date_sk7942_k};
            int32_t _d_date_sk7942 = tbl_Filter_TD_9472472_output.getInt32(i, 0);
            int32_t _d_year7948 = tbl_Filter_TD_9472472_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_8303630_payload_rightMajor payloadA{_d_date_sk7942, _d_year7948};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_9827835_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_sold_date_sk7908_k = tbl_JOIN_INNER_TD_9827835_output.getInt32(i, 7);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8303630_key_rightMajor{_ws_sold_date_sk7908_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk7942 = (it->second)._d_date_sk7942;
                int32_t _d_year7948 = (it->second)._d_year7948;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7891_n = tbl_JOIN_INNER_TD_9827835_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _c_customer_id7891 = std::string(_c_customer_id7891_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name7898_n = tbl_JOIN_INNER_TD_9827835_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_first_name7898 = std::string(_c_first_name7898_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name7899_n = tbl_JOIN_INNER_TD_9827835_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_last_name7899 = std::string(_c_last_name7899_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7900_n = tbl_JOIN_INNER_TD_9827835_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_preferred_cust_flag7900 = std::string(_c_preferred_cust_flag7900_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7904_n = tbl_JOIN_INNER_TD_9827835_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_birth_country7904 = std::string(_c_birth_country7904_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_login7905_n = tbl_JOIN_INNER_TD_9827835_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _c_login7905 = std::string(_c_login7905_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address7906_n = tbl_JOIN_INNER_TD_9827835_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _c_email_address7906 = std::string(_c_email_address7906_n.data());
                int32_t _ws_sold_date_sk7908 = tbl_JOIN_INNER_TD_9827835_output.getInt32(i, 7);
                int64_t _ws_ext_discount_amt7930 = tbl_JOIN_INNER_TD_9827835_output.getInt64(i, 8);
                int64_t _ws_ext_sales_price7931 = tbl_JOIN_INNER_TD_9827835_output.getInt64(i, 9);
                int64_t _ws_ext_wholesale_cost7932 = tbl_JOIN_INNER_TD_9827835_output.getInt64(i, 10);
                int64_t _ws_ext_list_price7933 = tbl_JOIN_INNER_TD_9827835_output.getInt64(i, 11);
                tbl_JOIN_INNER_TD_8303630_output.setInt32(r, 11, _d_year7948);
                tbl_JOIN_INNER_TD_8303630_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id7891_n);
                tbl_JOIN_INNER_TD_8303630_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name7898_n);
                tbl_JOIN_INNER_TD_8303630_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name7899_n);
                tbl_JOIN_INNER_TD_8303630_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag7900_n);
                tbl_JOIN_INNER_TD_8303630_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country7904_n);
                tbl_JOIN_INNER_TD_8303630_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login7905_n);
                tbl_JOIN_INNER_TD_8303630_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address7906_n);
                tbl_JOIN_INNER_TD_8303630_output.setInt64(r, 7, _ws_ext_discount_amt7930);
                tbl_JOIN_INNER_TD_8303630_output.setInt64(r, 8, _ws_ext_sales_price7931);
                tbl_JOIN_INNER_TD_8303630_output.setInt64(r, 9, _ws_ext_wholesale_cost7932);
                tbl_JOIN_INNER_TD_8303630_output.setInt64(r, 10, _ws_ext_list_price7933);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8303630_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8303630_output #Row: " << tbl_JOIN_INNER_TD_8303630_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8315128(Table &tbl_SerializeFromObject_TD_9401882_input, Table &tbl_Filter_TD_8315128_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#7629) AND (d_year#7629 = 2002)) AND isnotnull(d_date_sk#7623)))
    // Input: ListBuffer(d_date_sk#7623, d_year#7629)
    // Output: ListBuffer(d_date_sk#7623, d_year#7629)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9401882_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year7629 = tbl_SerializeFromObject_TD_9401882_input.getInt32(i, 1);
        int32_t _d_date_sk7623 = tbl_SerializeFromObject_TD_9401882_input.getInt32(i, 0);
        if (((_d_year7629!= 0) && (_d_year7629 == 2002)) && (_d_date_sk7623!= 0)) {
            int32_t _d_date_sk7623_t = tbl_SerializeFromObject_TD_9401882_input.getInt32(i, 0);
            tbl_Filter_TD_8315128_output.setInt32(r, 0, _d_date_sk7623_t);
            int32_t _d_year7629_t = tbl_SerializeFromObject_TD_9401882_input.getInt32(i, 1);
            tbl_Filter_TD_8315128_output.setInt32(r, 1, _d_year7629_t);
            r++;
        }
    }
    tbl_Filter_TD_8315128_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8315128_output #Row: " << tbl_Filter_TD_8315128_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8473697_key_leftMajor {
    int32_t _c_customer_sk7571;
    bool operator==(const SW_JOIN_INNER_TD_8473697_key_leftMajor& other) const {
        return ((_c_customer_sk7571 == other._c_customer_sk7571));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8473697_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8473697_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk7571));
    }
};
}
struct SW_JOIN_INNER_TD_8473697_payload_leftMajor {
    int32_t _c_customer_sk7571;
    std::string _c_customer_id7572;
    std::string _c_first_name7579;
    std::string _c_last_name7580;
    std::string _c_preferred_cust_flag7581;
    std::string _c_birth_country7585;
    std::string _c_login7586;
    std::string _c_email_address7587;
};
struct SW_JOIN_INNER_TD_8473697_key_rightMajor {
    int32_t _cs_bill_customer_sk7592;
    bool operator==(const SW_JOIN_INNER_TD_8473697_key_rightMajor& other) const {
        return ((_cs_bill_customer_sk7592 == other._cs_bill_customer_sk7592));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8473697_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8473697_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_bill_customer_sk7592));
    }
};
}
struct SW_JOIN_INNER_TD_8473697_payload_rightMajor {
    int32_t _cs_sold_date_sk7589;
    int32_t _cs_bill_customer_sk7592;
};
void SW_JOIN_INNER_TD_8473697(Table &tbl_Filter_TD_990363_output, Table &tbl_Filter_TD_9343399_output, Table &tbl_JOIN_INNER_TD_8473697_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((c_customer_sk#7571 = cs_bill_customer_sk#7592))
    // Left Table: ListBuffer(c_customer_sk#7571, c_customer_id#7572, c_first_name#7579, c_last_name#7580, c_preferred_cust_flag#7581, c_birth_country#7585, c_login#7586, c_email_address#7587)
    // Right Table: ListBuffer(cs_sold_date_sk#7589, cs_bill_customer_sk#7592)
    // Output Table: ListBuffer(c_customer_id#7572, c_first_name#7579, c_last_name#7580, c_preferred_cust_flag#7581, c_birth_country#7585, c_login#7586, c_email_address#7587, cs_sold_date_sk#7589)
    int left_nrow = tbl_Filter_TD_990363_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9343399_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8473697_key_leftMajor, SW_JOIN_INNER_TD_8473697_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_990363_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk7571_k = tbl_Filter_TD_990363_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8473697_key_leftMajor keyA{_c_customer_sk7571_k};
            int32_t _c_customer_sk7571 = tbl_Filter_TD_990363_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7572_n = tbl_Filter_TD_990363_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_customer_id7572 = std::string(_c_customer_id7572_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name7579_n = tbl_Filter_TD_990363_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_first_name7579 = std::string(_c_first_name7579_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name7580_n = tbl_Filter_TD_990363_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_last_name7580 = std::string(_c_last_name7580_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7581_n = tbl_Filter_TD_990363_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_preferred_cust_flag7581 = std::string(_c_preferred_cust_flag7581_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7585_n = tbl_Filter_TD_990363_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _c_birth_country7585 = std::string(_c_birth_country7585_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_login7586_n = tbl_Filter_TD_990363_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _c_login7586 = std::string(_c_login7586_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address7587_n = tbl_Filter_TD_990363_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _c_email_address7587 = std::string(_c_email_address7587_n.data());
            SW_JOIN_INNER_TD_8473697_payload_leftMajor payloadA{_c_customer_sk7571, _c_customer_id7572, _c_first_name7579, _c_last_name7580, _c_preferred_cust_flag7581, _c_birth_country7585, _c_login7586, _c_email_address7587};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9343399_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_bill_customer_sk7592_k = tbl_Filter_TD_9343399_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8473697_key_leftMajor{_cs_bill_customer_sk7592_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk7571 = (it->second)._c_customer_sk7571;
                std::string _c_customer_id7572 = (it->second)._c_customer_id7572;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7572_n{};
                memcpy(_c_customer_id7572_n.data(), (_c_customer_id7572).data(), (_c_customer_id7572).length());
                std::string _c_first_name7579 = (it->second)._c_first_name7579;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name7579_n{};
                memcpy(_c_first_name7579_n.data(), (_c_first_name7579).data(), (_c_first_name7579).length());
                std::string _c_last_name7580 = (it->second)._c_last_name7580;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name7580_n{};
                memcpy(_c_last_name7580_n.data(), (_c_last_name7580).data(), (_c_last_name7580).length());
                std::string _c_preferred_cust_flag7581 = (it->second)._c_preferred_cust_flag7581;
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7581_n{};
                memcpy(_c_preferred_cust_flag7581_n.data(), (_c_preferred_cust_flag7581).data(), (_c_preferred_cust_flag7581).length());
                std::string _c_birth_country7585 = (it->second)._c_birth_country7585;
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7585_n{};
                memcpy(_c_birth_country7585_n.data(), (_c_birth_country7585).data(), (_c_birth_country7585).length());
                std::string _c_login7586 = (it->second)._c_login7586;
                std::array<char, TPCDS_READ_MAX + 1> _c_login7586_n{};
                memcpy(_c_login7586_n.data(), (_c_login7586).data(), (_c_login7586).length());
                std::string _c_email_address7587 = (it->second)._c_email_address7587;
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address7587_n{};
                memcpy(_c_email_address7587_n.data(), (_c_email_address7587).data(), (_c_email_address7587).length());
                int32_t _cs_sold_date_sk7589 = tbl_Filter_TD_9343399_output.getInt32(i, 0);
                int32_t _cs_bill_customer_sk7592 = tbl_Filter_TD_9343399_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_8473697_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id7572_n);
                tbl_JOIN_INNER_TD_8473697_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name7579_n);
                tbl_JOIN_INNER_TD_8473697_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name7580_n);
                tbl_JOIN_INNER_TD_8473697_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag7581_n);
                tbl_JOIN_INNER_TD_8473697_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country7585_n);
                tbl_JOIN_INNER_TD_8473697_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login7586_n);
                tbl_JOIN_INNER_TD_8473697_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address7587_n);
                tbl_JOIN_INNER_TD_8473697_output.setInt32(r, 7, _cs_sold_date_sk7589);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8473697_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8473697_key_rightMajor, SW_JOIN_INNER_TD_8473697_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9343399_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_bill_customer_sk7592_k = tbl_Filter_TD_9343399_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_8473697_key_rightMajor keyA{_cs_bill_customer_sk7592_k};
            int32_t _cs_sold_date_sk7589 = tbl_Filter_TD_9343399_output.getInt32(i, 0);
            int32_t _cs_bill_customer_sk7592 = tbl_Filter_TD_9343399_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_8473697_payload_rightMajor payloadA{_cs_sold_date_sk7589, _cs_bill_customer_sk7592};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_990363_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk7571_k = tbl_Filter_TD_990363_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8473697_key_rightMajor{_c_customer_sk7571_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk7589 = (it->second)._cs_sold_date_sk7589;
                int32_t _cs_bill_customer_sk7592 = (it->second)._cs_bill_customer_sk7592;
                int32_t _c_customer_sk7571 = tbl_Filter_TD_990363_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7572_n = tbl_Filter_TD_990363_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_customer_id7572 = std::string(_c_customer_id7572_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name7579_n = tbl_Filter_TD_990363_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_first_name7579 = std::string(_c_first_name7579_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name7580_n = tbl_Filter_TD_990363_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_last_name7580 = std::string(_c_last_name7580_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7581_n = tbl_Filter_TD_990363_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_preferred_cust_flag7581 = std::string(_c_preferred_cust_flag7581_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7585_n = tbl_Filter_TD_990363_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _c_birth_country7585 = std::string(_c_birth_country7585_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_login7586_n = tbl_Filter_TD_990363_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _c_login7586 = std::string(_c_login7586_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address7587_n = tbl_Filter_TD_990363_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _c_email_address7587 = std::string(_c_email_address7587_n.data());
                tbl_JOIN_INNER_TD_8473697_output.setInt32(r, 7, _cs_sold_date_sk7589);
                tbl_JOIN_INNER_TD_8473697_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id7572_n);
                tbl_JOIN_INNER_TD_8473697_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name7579_n);
                tbl_JOIN_INNER_TD_8473697_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name7580_n);
                tbl_JOIN_INNER_TD_8473697_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag7581_n);
                tbl_JOIN_INNER_TD_8473697_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country7585_n);
                tbl_JOIN_INNER_TD_8473697_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login7586_n);
                tbl_JOIN_INNER_TD_8473697_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address7587_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8473697_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8473697_output #Row: " << tbl_JOIN_INNER_TD_8473697_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8183160(Table &tbl_Aggregate_TD_919589_output, Table &tbl_Filter_TD_8183160_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(year_total#4168) AND (year_total#4168 > 0.000000)))
    // Input: ListBuffer(customer_id#4160, year_total#4168)
    // Output: ListBuffer(customer_id#4160)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_919589_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _year_total4168 = tbl_Aggregate_TD_919589_output.getInt64(i, 1);
        if ((_year_total4168!= 0) && (_year_total4168 > 0.000000)) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4160_t = tbl_Aggregate_TD_919589_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            tbl_Filter_TD_8183160_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id4160_t);
            r++;
        }
    }
    tbl_Filter_TD_8183160_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8183160_output #Row: " << tbl_Filter_TD_8183160_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_8273256_key {
    std::string _c_customer_id7025;
    std::string _c_first_name7032;
    std::string _c_last_name7033;
    std::string _c_preferred_cust_flag7034;
    std::string _c_birth_country7038;
    std::string _c_login7039;
    std::string _c_email_address7040;
    int32_t _d_year7071;
    bool operator==(const SW_Aggregate_TD_8273256_key& other) const { return (_c_customer_id7025 == other._c_customer_id7025) && (_c_first_name7032 == other._c_first_name7032) && (_c_last_name7033 == other._c_last_name7033) && (_c_preferred_cust_flag7034 == other._c_preferred_cust_flag7034) && (_c_birth_country7038 == other._c_birth_country7038) && (_c_login7039 == other._c_login7039) && (_c_email_address7040 == other._c_email_address7040) && (_d_year7071 == other._d_year7071); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_8273256_key> {
    std::size_t operator() (const SW_Aggregate_TD_8273256_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._c_customer_id7025)) + (hash<string>()(k._c_first_name7032)) + (hash<string>()(k._c_last_name7033)) + (hash<string>()(k._c_preferred_cust_flag7034)) + (hash<string>()(k._c_birth_country7038)) + (hash<string>()(k._c_login7039)) + (hash<string>()(k._c_email_address7040)) + (hash<int32_t>()(k._d_year7071));
    }
};
}
struct SW_Aggregate_TD_8273256_payload {
    std::string _customer_id4275;
    std::string _customer_first_name4276;
    std::string _customer_last_name4277;
    std::string _customer_preferred_cust_flag4278;
};
void SW_Aggregate_TD_8273256(Table &tbl_JOIN_INNER_TD_9331224_output, Table &tbl_Aggregate_TD_8273256_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_customer_id#7025, c_first_name#7032, c_last_name#7033, c_preferred_cust_flag#7034, c_birth_country#7038, c_login#7039, c_email_address#7040, d_year#7071, c_customer_id#7025 AS customer_id#4275, c_first_name#7032 AS customer_first_name#4276, c_last_name#7033 AS customer_last_name#4277, c_preferred_cust_flag#7034 AS customer_preferred_cust_flag#4278)
    // Input: ListBuffer(c_customer_id#7025, c_first_name#7032, c_last_name#7033, c_preferred_cust_flag#7034, c_birth_country#7038, c_login#7039, c_email_address#7040, d_year#7071)
    // Output: ListBuffer(customer_id#4275, customer_first_name#4276, customer_last_name#4277, customer_preferred_cust_flag#4278)
    std::unordered_map<SW_Aggregate_TD_8273256_key, SW_Aggregate_TD_8273256_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_9331224_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7025 = tbl_JOIN_INNER_TD_9331224_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name7032 = tbl_JOIN_INNER_TD_9331224_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name7033 = tbl_JOIN_INNER_TD_9331224_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7034 = tbl_JOIN_INNER_TD_9331224_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7038 = tbl_JOIN_INNER_TD_9331224_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _c_login7039 = tbl_JOIN_INNER_TD_9331224_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _c_email_address7040 = tbl_JOIN_INNER_TD_9331224_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        int32_t _d_year7071 = tbl_JOIN_INNER_TD_9331224_output.getInt32(i, 7);
        SW_Aggregate_TD_8273256_key k{std::string(_c_customer_id7025.data()), std::string(_c_first_name7032.data()), std::string(_c_last_name7033.data()), std::string(_c_preferred_cust_flag7034.data()), std::string(_c_birth_country7038.data()), std::string(_c_login7039.data()), std::string(_c_email_address7040.data()), _d_year7071};
        std::array<char, TPCDS_READ_MAX + 1> _customer_id4275 = _c_customer_id7025;
        std::array<char, TPCDS_READ_MAX + 1> _customer_first_name4276 = _c_first_name7032;
        std::array<char, TPCDS_READ_MAX + 1> _customer_last_name4277 = _c_last_name7033;
        std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag4278 = _c_preferred_cust_flag7034;
        SW_Aggregate_TD_8273256_payload p{std::string(_customer_id4275.data()), std::string(_customer_first_name4276.data()), std::string(_customer_last_name4277.data()), std::string(_customer_preferred_cust_flag4278.data())};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _c_customer_id7025 not required in the output table
        // _c_first_name7032 not required in the output table
        // _c_last_name7033 not required in the output table
        // _c_preferred_cust_flag7034 not required in the output table
        // _c_birth_country7038 not required in the output table
        // _c_login7039 not required in the output table
        // _c_email_address7040 not required in the output table
        // _d_year7071 not required in the output table
        std::array<char, TPCDS_READ_MAX + 1> _customer_id4275_n{};
        memcpy(_customer_id4275_n.data(), (it.second)._customer_id4275.data(), (it.second)._customer_id4275.length());
        tbl_Aggregate_TD_8273256_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id4275_n);
        std::array<char, TPCDS_READ_MAX + 1> _customer_first_name4276_n{};
        memcpy(_customer_first_name4276_n.data(), (it.second)._customer_first_name4276.data(), (it.second)._customer_first_name4276.length());
        tbl_Aggregate_TD_8273256_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _customer_first_name4276_n);
        std::array<char, TPCDS_READ_MAX + 1> _customer_last_name4277_n{};
        memcpy(_customer_last_name4277_n.data(), (it.second)._customer_last_name4277.data(), (it.second)._customer_last_name4277.length());
        tbl_Aggregate_TD_8273256_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _customer_last_name4277_n);
        std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag4278_n{};
        memcpy(_customer_preferred_cust_flag4278_n.data(), (it.second)._customer_preferred_cust_flag4278.data(), (it.second)._customer_preferred_cust_flag4278.length());
        tbl_Aggregate_TD_8273256_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _customer_preferred_cust_flag4278_n);
        ++r;
    }
    tbl_Aggregate_TD_8273256_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_8273256_output #Row: " << tbl_Aggregate_TD_8273256_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8321963(Table &tbl_Aggregate_TD_9482711_output, Table &tbl_Filter_TD_8321963_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(year_total#4158) AND (year_total#4158 > 0.000000)))
    // Input: ListBuffer(customer_id#4150, year_total#4158)
    // Output: ListBuffer(customer_id#4150)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_9482711_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _year_total4158 = tbl_Aggregate_TD_9482711_output.getInt64(i, 1);
        if ((_year_total4158!= 0) && (_year_total4158 > 0.000000)) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_t = tbl_Aggregate_TD_9482711_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            tbl_Filter_TD_8321963_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id4150_t);
            r++;
        }
    }
    tbl_Filter_TD_8321963_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8321963_output #Row: " << tbl_Filter_TD_8321963_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7195484(Table &tbl_SerializeFromObject_TD_8398758_input, Table &tbl_Filter_TD_7195484_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_bill_customer_sk#8151) AND isnotnull(ws_sold_date_sk#8147)))
    // Input: ListBuffer(ws_sold_date_sk#8147, ws_bill_customer_sk#8151)
    // Output: ListBuffer(ws_sold_date_sk#8147, ws_bill_customer_sk#8151)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8398758_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_bill_customer_sk8151 = tbl_SerializeFromObject_TD_8398758_input.getInt32(i, 1);
        int32_t _ws_sold_date_sk8147 = tbl_SerializeFromObject_TD_8398758_input.getInt32(i, 0);
        if ((_ws_bill_customer_sk8151!= 0) && (_ws_sold_date_sk8147!= 0)) {
            int32_t _ws_sold_date_sk8147_t = tbl_SerializeFromObject_TD_8398758_input.getInt32(i, 0);
            tbl_Filter_TD_7195484_output.setInt32(r, 0, _ws_sold_date_sk8147_t);
            int32_t _ws_bill_customer_sk8151_t = tbl_SerializeFromObject_TD_8398758_input.getInt32(i, 1);
            tbl_Filter_TD_7195484_output.setInt32(r, 1, _ws_bill_customer_sk8151_t);
            r++;
        }
    }
    tbl_Filter_TD_7195484_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7195484_output #Row: " << tbl_Filter_TD_7195484_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7347147(Table &tbl_SerializeFromObject_TD_8806662_input, Table &tbl_Filter_TD_7347147_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(c_customer_sk#8129) AND isnotnull(c_customer_id#8130)))
    // Input: ListBuffer(c_customer_sk#8129, c_customer_id#8130, c_first_name#8137, c_last_name#8138, c_preferred_cust_flag#8139, c_birth_country#8143, c_login#8144, c_email_address#8145)
    // Output: ListBuffer(c_customer_sk#8129, c_customer_id#8130, c_first_name#8137, c_last_name#8138, c_preferred_cust_flag#8139, c_birth_country#8143, c_login#8144, c_email_address#8145)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8806662_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk8129 = tbl_SerializeFromObject_TD_8806662_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id8130 = tbl_SerializeFromObject_TD_8806662_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_c_customer_sk8129!= 0) && _c_customer_id8130.data() != "NULL") {
            int32_t _c_customer_sk8129_t = tbl_SerializeFromObject_TD_8806662_input.getInt32(i, 0);
            tbl_Filter_TD_7347147_output.setInt32(r, 0, _c_customer_sk8129_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id8130_t = tbl_SerializeFromObject_TD_8806662_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_7347147_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_customer_id8130_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8137_t = tbl_SerializeFromObject_TD_8806662_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_7347147_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name8137_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name8138_t = tbl_SerializeFromObject_TD_8806662_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_7347147_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name8138_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag8139_t = tbl_SerializeFromObject_TD_8806662_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            tbl_Filter_TD_7347147_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_preferred_cust_flag8139_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country8143_t = tbl_SerializeFromObject_TD_8806662_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            tbl_Filter_TD_7347147_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_birth_country8143_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_login8144_t = tbl_SerializeFromObject_TD_8806662_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            tbl_Filter_TD_7347147_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_login8144_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address8145_t = tbl_SerializeFromObject_TD_8806662_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            tbl_Filter_TD_7347147_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _c_email_address8145_t);
            r++;
        }
    }
    tbl_Filter_TD_7347147_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7347147_output #Row: " << tbl_Filter_TD_7347147_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_7400563_key {
    std::string _c_customer_id7891;
    std::string _c_first_name7898;
    std::string _c_last_name7899;
    std::string _c_preferred_cust_flag7900;
    std::string _c_birth_country7904;
    std::string _c_login7905;
    std::string _c_email_address7906;
    int32_t _d_year7948;
    bool operator==(const SW_Aggregate_TD_7400563_key& other) const { return (_c_customer_id7891 == other._c_customer_id7891) && (_c_first_name7898 == other._c_first_name7898) && (_c_last_name7899 == other._c_last_name7899) && (_c_preferred_cust_flag7900 == other._c_preferred_cust_flag7900) && (_c_birth_country7904 == other._c_birth_country7904) && (_c_login7905 == other._c_login7905) && (_c_email_address7906 == other._c_email_address7906) && (_d_year7948 == other._d_year7948); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_7400563_key> {
    std::size_t operator() (const SW_Aggregate_TD_7400563_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._c_customer_id7891)) + (hash<string>()(k._c_first_name7898)) + (hash<string>()(k._c_last_name7899)) + (hash<string>()(k._c_preferred_cust_flag7900)) + (hash<string>()(k._c_birth_country7904)) + (hash<string>()(k._c_login7905)) + (hash<string>()(k._c_email_address7906)) + (hash<int32_t>()(k._d_year7948));
    }
};
}
struct SW_Aggregate_TD_7400563_payload {
    std::string _customer_id4170;
    int64_t _year_total4178_sum_0;
};
void SW_Aggregate_TD_7400563(Table &tbl_JOIN_INNER_TD_8303630_output, Table &tbl_Aggregate_TD_7400563_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_customer_id#7891, c_first_name#7898, c_last_name#7899, c_preferred_cust_flag#7900, c_birth_country#7904, c_login#7905, c_email_address#7906, d_year#7948, c_customer_id#7891 AS customer_id#4170, sum(CheckOverflow((promote_precision(CheckOverflow((promote_precision(cast(CheckOverflow((promote_precision(cast(CheckOverflow((promote_precision(cast(ws_ext_list_price#7933 as decimal(8,2))) - promote_precision(cast(ws_ext_wholesale_cost#7932 as decimal(8,2)))), DecimalType(8,2), true) as decimal(9,2))) - promote_precision(cast(ws_ext_discount_amt#7930 as decimal(9,2)))), DecimalType(9,2), true) as decimal(10,2))) + promote_precision(cast(ws_ext_sales_price#7931 as decimal(10,2)))), DecimalType(10,2), true)) / 2.00), DecimalType(14,6), true)) AS year_total#4178)
    // Input: ListBuffer(c_customer_id#7891, c_first_name#7898, c_last_name#7899, c_preferred_cust_flag#7900, c_birth_country#7904, c_login#7905, c_email_address#7906, ws_ext_discount_amt#7930, ws_ext_sales_price#7931, ws_ext_wholesale_cost#7932, ws_ext_list_price#7933, d_year#7948)
    // Output: ListBuffer(customer_id#4170, year_total#4178)
    std::unordered_map<SW_Aggregate_TD_7400563_key, SW_Aggregate_TD_7400563_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_8303630_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7891 = tbl_JOIN_INNER_TD_8303630_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name7898 = tbl_JOIN_INNER_TD_8303630_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name7899 = tbl_JOIN_INNER_TD_8303630_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7900 = tbl_JOIN_INNER_TD_8303630_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7904 = tbl_JOIN_INNER_TD_8303630_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _c_login7905 = tbl_JOIN_INNER_TD_8303630_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _c_email_address7906 = tbl_JOIN_INNER_TD_8303630_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        int64_t _ws_ext_discount_amt7930 = tbl_JOIN_INNER_TD_8303630_output.getInt64(i, 7);
        int64_t _ws_ext_sales_price7931 = tbl_JOIN_INNER_TD_8303630_output.getInt64(i, 8);
        int64_t _ws_ext_wholesale_cost7932 = tbl_JOIN_INNER_TD_8303630_output.getInt64(i, 9);
        int64_t _ws_ext_list_price7933 = tbl_JOIN_INNER_TD_8303630_output.getInt64(i, 10);
        int32_t _d_year7948 = tbl_JOIN_INNER_TD_8303630_output.getInt32(i, 11);
        SW_Aggregate_TD_7400563_key k{std::string(_c_customer_id7891.data()), std::string(_c_first_name7898.data()), std::string(_c_last_name7899.data()), std::string(_c_preferred_cust_flag7900.data()), std::string(_c_birth_country7904.data()), std::string(_c_login7905.data()), std::string(_c_email_address7906.data()), _d_year7948};
        std::array<char, TPCDS_READ_MAX + 1> _customer_id4170 = _c_customer_id7891;
        int64_t _year_total4178_sum_0 = ((((_ws_ext_list_price7933 - _ws_ext_wholesale_cost7932) - _ws_ext_discount_amt7930) + _ws_ext_sales_price7931) / 2.00);
        SW_Aggregate_TD_7400563_payload p{std::string(_customer_id4170.data()), _year_total4178_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._year_total4178_sum_0 + _year_total4178_sum_0;
            p._year_total4178_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _c_customer_id7891 not required in the output table
        // _c_first_name7898 not required in the output table
        // _c_last_name7899 not required in the output table
        // _c_preferred_cust_flag7900 not required in the output table
        // _c_birth_country7904 not required in the output table
        // _c_login7905 not required in the output table
        // _c_email_address7906 not required in the output table
        // _d_year7948 not required in the output table
        std::array<char, TPCDS_READ_MAX + 1> _customer_id4170_n{};
        memcpy(_customer_id4170_n.data(), (it.second)._customer_id4170.data(), (it.second)._customer_id4170.length());
        tbl_Aggregate_TD_7400563_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id4170_n);
        int64_t _year_total4178 = (it.second)._year_total4178_sum_0;
        tbl_Aggregate_TD_7400563_output.setInt64(r, 1, _year_total4178);
        ++r;
    }
    tbl_Aggregate_TD_7400563_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_7400563_output #Row: " << tbl_Aggregate_TD_7400563_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_7196854_key_leftMajor {
    int32_t _cs_sold_date_sk7589;
    bool operator==(const SW_JOIN_INNER_TD_7196854_key_leftMajor& other) const {
        return ((_cs_sold_date_sk7589 == other._cs_sold_date_sk7589));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7196854_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7196854_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_sold_date_sk7589));
    }
};
}
struct SW_JOIN_INNER_TD_7196854_payload_leftMajor {
    std::string _c_customer_id7572;
    std::string _c_first_name7579;
    std::string _c_last_name7580;
    std::string _c_preferred_cust_flag7581;
    std::string _c_birth_country7585;
    std::string _c_login7586;
    std::string _c_email_address7587;
    int32_t _cs_sold_date_sk7589;
};
struct SW_JOIN_INNER_TD_7196854_key_rightMajor {
    int32_t _d_date_sk7623;
    bool operator==(const SW_JOIN_INNER_TD_7196854_key_rightMajor& other) const {
        return ((_d_date_sk7623 == other._d_date_sk7623));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7196854_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7196854_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk7623));
    }
};
}
struct SW_JOIN_INNER_TD_7196854_payload_rightMajor {
    int32_t _d_date_sk7623;
    int32_t _d_year7629;
};
void SW_JOIN_INNER_TD_7196854(Table &tbl_JOIN_INNER_TD_8473697_output, Table &tbl_Filter_TD_8315128_output, Table &tbl_JOIN_INNER_TD_7196854_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_sold_date_sk#7589 = d_date_sk#7623))
    // Left Table: ListBuffer(c_customer_id#7572, c_first_name#7579, c_last_name#7580, c_preferred_cust_flag#7581, c_birth_country#7585, c_login#7586, c_email_address#7587, cs_sold_date_sk#7589)
    // Right Table: ListBuffer(d_date_sk#7623, d_year#7629)
    // Output Table: ListBuffer(c_customer_id#7572, c_first_name#7579, c_last_name#7580, c_preferred_cust_flag#7581, c_birth_country#7585, c_login#7586, c_email_address#7587, d_year#7629)
    int left_nrow = tbl_JOIN_INNER_TD_8473697_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8315128_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7196854_key_leftMajor, SW_JOIN_INNER_TD_7196854_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_8473697_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_sold_date_sk7589_k = tbl_JOIN_INNER_TD_8473697_output.getInt32(i, 7);
            SW_JOIN_INNER_TD_7196854_key_leftMajor keyA{_cs_sold_date_sk7589_k};
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7572_n = tbl_JOIN_INNER_TD_8473697_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _c_customer_id7572 = std::string(_c_customer_id7572_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name7579_n = tbl_JOIN_INNER_TD_8473697_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_first_name7579 = std::string(_c_first_name7579_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name7580_n = tbl_JOIN_INNER_TD_8473697_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_last_name7580 = std::string(_c_last_name7580_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7581_n = tbl_JOIN_INNER_TD_8473697_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_preferred_cust_flag7581 = std::string(_c_preferred_cust_flag7581_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7585_n = tbl_JOIN_INNER_TD_8473697_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_birth_country7585 = std::string(_c_birth_country7585_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_login7586_n = tbl_JOIN_INNER_TD_8473697_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _c_login7586 = std::string(_c_login7586_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address7587_n = tbl_JOIN_INNER_TD_8473697_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _c_email_address7587 = std::string(_c_email_address7587_n.data());
            int32_t _cs_sold_date_sk7589 = tbl_JOIN_INNER_TD_8473697_output.getInt32(i, 7);
            SW_JOIN_INNER_TD_7196854_payload_leftMajor payloadA{_c_customer_id7572, _c_first_name7579, _c_last_name7580, _c_preferred_cust_flag7581, _c_birth_country7585, _c_login7586, _c_email_address7587, _cs_sold_date_sk7589};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8315128_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk7623_k = tbl_Filter_TD_8315128_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7196854_key_leftMajor{_d_date_sk7623_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _c_customer_id7572 = (it->second)._c_customer_id7572;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7572_n{};
                memcpy(_c_customer_id7572_n.data(), (_c_customer_id7572).data(), (_c_customer_id7572).length());
                std::string _c_first_name7579 = (it->second)._c_first_name7579;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name7579_n{};
                memcpy(_c_first_name7579_n.data(), (_c_first_name7579).data(), (_c_first_name7579).length());
                std::string _c_last_name7580 = (it->second)._c_last_name7580;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name7580_n{};
                memcpy(_c_last_name7580_n.data(), (_c_last_name7580).data(), (_c_last_name7580).length());
                std::string _c_preferred_cust_flag7581 = (it->second)._c_preferred_cust_flag7581;
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7581_n{};
                memcpy(_c_preferred_cust_flag7581_n.data(), (_c_preferred_cust_flag7581).data(), (_c_preferred_cust_flag7581).length());
                std::string _c_birth_country7585 = (it->second)._c_birth_country7585;
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7585_n{};
                memcpy(_c_birth_country7585_n.data(), (_c_birth_country7585).data(), (_c_birth_country7585).length());
                std::string _c_login7586 = (it->second)._c_login7586;
                std::array<char, TPCDS_READ_MAX + 1> _c_login7586_n{};
                memcpy(_c_login7586_n.data(), (_c_login7586).data(), (_c_login7586).length());
                std::string _c_email_address7587 = (it->second)._c_email_address7587;
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address7587_n{};
                memcpy(_c_email_address7587_n.data(), (_c_email_address7587).data(), (_c_email_address7587).length());
                int32_t _cs_sold_date_sk7589 = (it->second)._cs_sold_date_sk7589;
                int32_t _d_date_sk7623 = tbl_Filter_TD_8315128_output.getInt32(i, 0);
                int32_t _d_year7629 = tbl_Filter_TD_8315128_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_7196854_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id7572_n);
                tbl_JOIN_INNER_TD_7196854_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name7579_n);
                tbl_JOIN_INNER_TD_7196854_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name7580_n);
                tbl_JOIN_INNER_TD_7196854_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag7581_n);
                tbl_JOIN_INNER_TD_7196854_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country7585_n);
                tbl_JOIN_INNER_TD_7196854_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login7586_n);
                tbl_JOIN_INNER_TD_7196854_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address7587_n);
                tbl_JOIN_INNER_TD_7196854_output.setInt32(r, 7, _d_year7629);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7196854_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7196854_key_rightMajor, SW_JOIN_INNER_TD_7196854_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8315128_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk7623_k = tbl_Filter_TD_8315128_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7196854_key_rightMajor keyA{_d_date_sk7623_k};
            int32_t _d_date_sk7623 = tbl_Filter_TD_8315128_output.getInt32(i, 0);
            int32_t _d_year7629 = tbl_Filter_TD_8315128_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_7196854_payload_rightMajor payloadA{_d_date_sk7623, _d_year7629};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_8473697_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_sold_date_sk7589_k = tbl_JOIN_INNER_TD_8473697_output.getInt32(i, 7);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7196854_key_rightMajor{_cs_sold_date_sk7589_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk7623 = (it->second)._d_date_sk7623;
                int32_t _d_year7629 = (it->second)._d_year7629;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7572_n = tbl_JOIN_INNER_TD_8473697_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _c_customer_id7572 = std::string(_c_customer_id7572_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name7579_n = tbl_JOIN_INNER_TD_8473697_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_first_name7579 = std::string(_c_first_name7579_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name7580_n = tbl_JOIN_INNER_TD_8473697_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_last_name7580 = std::string(_c_last_name7580_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7581_n = tbl_JOIN_INNER_TD_8473697_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_preferred_cust_flag7581 = std::string(_c_preferred_cust_flag7581_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7585_n = tbl_JOIN_INNER_TD_8473697_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_birth_country7585 = std::string(_c_birth_country7585_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_login7586_n = tbl_JOIN_INNER_TD_8473697_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _c_login7586 = std::string(_c_login7586_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address7587_n = tbl_JOIN_INNER_TD_8473697_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _c_email_address7587 = std::string(_c_email_address7587_n.data());
                int32_t _cs_sold_date_sk7589 = tbl_JOIN_INNER_TD_8473697_output.getInt32(i, 7);
                tbl_JOIN_INNER_TD_7196854_output.setInt32(r, 7, _d_year7629);
                tbl_JOIN_INNER_TD_7196854_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id7572_n);
                tbl_JOIN_INNER_TD_7196854_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name7579_n);
                tbl_JOIN_INNER_TD_7196854_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name7580_n);
                tbl_JOIN_INNER_TD_7196854_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag7581_n);
                tbl_JOIN_INNER_TD_7196854_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country7585_n);
                tbl_JOIN_INNER_TD_7196854_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login7586_n);
                tbl_JOIN_INNER_TD_7196854_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address7587_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7196854_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7196854_output #Row: " << tbl_JOIN_INNER_TD_7196854_output.getNumRow() << std::endl;
}

void SW_Project_TD_7309655(Table &tbl_Filter_TD_8183160_output, Table &tbl_Project_TD_7309655_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(customer_id#4160 AS customer_id#7492)
    // Input: ListBuffer(customer_id#4160)
    // Output: ListBuffer(customer_id#7492)
    int nrow1 = tbl_Filter_TD_8183160_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _customer_id4160 = tbl_Filter_TD_8183160_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _customer_id7492 = _customer_id4160;
        tbl_Project_TD_7309655_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 0, _customer_id7492);
    }
    tbl_Project_TD_7309655_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_7309655_output #Row: " << tbl_Project_TD_7309655_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_7228170_key_leftMajor {
    std::string _customer_id4150;
    bool operator==(const SW_JOIN_INNER_TD_7228170_key_leftMajor& other) const {
        return ((_customer_id4150 == other._customer_id4150));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7228170_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7228170_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._customer_id4150));
    }
};
}
struct SW_JOIN_INNER_TD_7228170_payload_leftMajor {
    std::string _customer_id4150;
};
struct SW_JOIN_INNER_TD_7228170_key_rightMajor {
    std::string _customer_id4275;
    bool operator==(const SW_JOIN_INNER_TD_7228170_key_rightMajor& other) const {
        return ((_customer_id4275 == other._customer_id4275));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7228170_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7228170_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._customer_id4275));
    }
};
}
struct SW_JOIN_INNER_TD_7228170_payload_rightMajor {
    std::string _customer_id4275;
    std::string _customer_first_name4276;
    std::string _customer_last_name4277;
    std::string _customer_preferred_cust_flag4278;
};
void SW_JOIN_INNER_TD_7228170(Table &tbl_Filter_TD_8321963_output, Table &tbl_Aggregate_TD_8273256_output, Table &tbl_JOIN_INNER_TD_7228170_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((customer_id#4275 = customer_id#4150))
    // Left Table: ListBuffer(customer_id#4150)
    // Right Table: ListBuffer(customer_id#4275, customer_first_name#4276, customer_last_name#4277, customer_preferred_cust_flag#4278)
    // Output Table: ListBuffer(customer_id#4150, customer_id#4275, customer_first_name#4276, customer_last_name#4277, customer_preferred_cust_flag#4278)
    int left_nrow = tbl_Filter_TD_8321963_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_8273256_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7228170_key_leftMajor, SW_JOIN_INNER_TD_7228170_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_8321963_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_k_n = tbl_Filter_TD_8321963_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id4150_k = std::string(_customer_id4150_k_n.data());
            SW_JOIN_INNER_TD_7228170_key_leftMajor keyA{_customer_id4150_k};
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_n = tbl_Filter_TD_8321963_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id4150 = std::string(_customer_id4150_n.data());
            SW_JOIN_INNER_TD_7228170_payload_leftMajor payloadA{_customer_id4150};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_8273256_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4275_k_n = tbl_Aggregate_TD_8273256_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id4275_k = std::string(_customer_id4275_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7228170_key_leftMajor{_customer_id4275_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _customer_id4150 = (it->second)._customer_id4150;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_n{};
                memcpy(_customer_id4150_n.data(), (_customer_id4150).data(), (_customer_id4150).length());
                std::array<char, TPCDS_READ_MAX + 1> _customer_id4275_n = tbl_Aggregate_TD_8273256_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _customer_id4275 = std::string(_customer_id4275_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_first_name4276_n = tbl_Aggregate_TD_8273256_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _customer_first_name4276 = std::string(_customer_first_name4276_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_last_name4277_n = tbl_Aggregate_TD_8273256_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _customer_last_name4277 = std::string(_customer_last_name4277_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag4278_n = tbl_Aggregate_TD_8273256_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _customer_preferred_cust_flag4278 = std::string(_customer_preferred_cust_flag4278_n.data());
                tbl_JOIN_INNER_TD_7228170_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id4150_n);
                tbl_JOIN_INNER_TD_7228170_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _customer_id4275_n);
                tbl_JOIN_INNER_TD_7228170_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _customer_first_name4276_n);
                tbl_JOIN_INNER_TD_7228170_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _customer_last_name4277_n);
                tbl_JOIN_INNER_TD_7228170_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _customer_preferred_cust_flag4278_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7228170_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7228170_key_rightMajor, SW_JOIN_INNER_TD_7228170_payload_rightMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_8273256_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4275_k_n = tbl_Aggregate_TD_8273256_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id4275_k = std::string(_customer_id4275_k_n.data());
            SW_JOIN_INNER_TD_7228170_key_rightMajor keyA{_customer_id4275_k};
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4275_n = tbl_Aggregate_TD_8273256_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id4275 = std::string(_customer_id4275_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_first_name4276_n = tbl_Aggregate_TD_8273256_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _customer_first_name4276 = std::string(_customer_first_name4276_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_last_name4277_n = tbl_Aggregate_TD_8273256_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _customer_last_name4277 = std::string(_customer_last_name4277_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag4278_n = tbl_Aggregate_TD_8273256_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _customer_preferred_cust_flag4278 = std::string(_customer_preferred_cust_flag4278_n.data());
            SW_JOIN_INNER_TD_7228170_payload_rightMajor payloadA{_customer_id4275, _customer_first_name4276, _customer_last_name4277, _customer_preferred_cust_flag4278};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8321963_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_k_n = tbl_Filter_TD_8321963_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id4150_k = std::string(_customer_id4150_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7228170_key_rightMajor{_customer_id4150_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _customer_id4275 = (it->second)._customer_id4275;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id4275_n{};
                memcpy(_customer_id4275_n.data(), (_customer_id4275).data(), (_customer_id4275).length());
                std::string _customer_first_name4276 = (it->second)._customer_first_name4276;
                std::array<char, TPCDS_READ_MAX + 1> _customer_first_name4276_n{};
                memcpy(_customer_first_name4276_n.data(), (_customer_first_name4276).data(), (_customer_first_name4276).length());
                std::string _customer_last_name4277 = (it->second)._customer_last_name4277;
                std::array<char, TPCDS_READ_MAX + 1> _customer_last_name4277_n{};
                memcpy(_customer_last_name4277_n.data(), (_customer_last_name4277).data(), (_customer_last_name4277).length());
                std::string _customer_preferred_cust_flag4278 = (it->second)._customer_preferred_cust_flag4278;
                std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag4278_n{};
                memcpy(_customer_preferred_cust_flag4278_n.data(), (_customer_preferred_cust_flag4278).data(), (_customer_preferred_cust_flag4278).length());
                std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_n = tbl_Filter_TD_8321963_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _customer_id4150 = std::string(_customer_id4150_n.data());
                tbl_JOIN_INNER_TD_7228170_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _customer_id4275_n);
                tbl_JOIN_INNER_TD_7228170_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _customer_first_name4276_n);
                tbl_JOIN_INNER_TD_7228170_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _customer_last_name4277_n);
                tbl_JOIN_INNER_TD_7228170_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _customer_preferred_cust_flag4278_n);
                tbl_JOIN_INNER_TD_7228170_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id4150_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7228170_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7228170_output #Row: " << tbl_JOIN_INNER_TD_7228170_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6163670(Table &tbl_SerializeFromObject_TD_7850014_input, Table &tbl_Filter_TD_6163670_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#8187) AND (d_year#8187 = 2002)) AND isnotnull(d_date_sk#8181)))
    // Input: ListBuffer(d_date_sk#8181, d_year#8187)
    // Output: ListBuffer(d_date_sk#8181, d_year#8187)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7850014_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year8187 = tbl_SerializeFromObject_TD_7850014_input.getInt32(i, 1);
        int32_t _d_date_sk8181 = tbl_SerializeFromObject_TD_7850014_input.getInt32(i, 0);
        if (((_d_year8187!= 0) && (_d_year8187 == 2002)) && (_d_date_sk8181!= 0)) {
            int32_t _d_date_sk8181_t = tbl_SerializeFromObject_TD_7850014_input.getInt32(i, 0);
            tbl_Filter_TD_6163670_output.setInt32(r, 0, _d_date_sk8181_t);
            int32_t _d_year8187_t = tbl_SerializeFromObject_TD_7850014_input.getInt32(i, 1);
            tbl_Filter_TD_6163670_output.setInt32(r, 1, _d_year8187_t);
            r++;
        }
    }
    tbl_Filter_TD_6163670_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6163670_output #Row: " << tbl_Filter_TD_6163670_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6804084_key_leftMajor {
    int32_t _c_customer_sk8129;
    bool operator==(const SW_JOIN_INNER_TD_6804084_key_leftMajor& other) const {
        return ((_c_customer_sk8129 == other._c_customer_sk8129));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6804084_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6804084_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk8129));
    }
};
}
struct SW_JOIN_INNER_TD_6804084_payload_leftMajor {
    int32_t _c_customer_sk8129;
    std::string _c_customer_id8130;
    std::string _c_first_name8137;
    std::string _c_last_name8138;
    std::string _c_preferred_cust_flag8139;
    std::string _c_birth_country8143;
    std::string _c_login8144;
    std::string _c_email_address8145;
};
struct SW_JOIN_INNER_TD_6804084_key_rightMajor {
    int32_t _ws_bill_customer_sk8151;
    bool operator==(const SW_JOIN_INNER_TD_6804084_key_rightMajor& other) const {
        return ((_ws_bill_customer_sk8151 == other._ws_bill_customer_sk8151));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6804084_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6804084_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_bill_customer_sk8151));
    }
};
}
struct SW_JOIN_INNER_TD_6804084_payload_rightMajor {
    int32_t _ws_sold_date_sk8147;
    int32_t _ws_bill_customer_sk8151;
};
void SW_JOIN_INNER_TD_6804084(Table &tbl_Filter_TD_7347147_output, Table &tbl_Filter_TD_7195484_output, Table &tbl_JOIN_INNER_TD_6804084_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((c_customer_sk#8129 = ws_bill_customer_sk#8151))
    // Left Table: ListBuffer(c_customer_sk#8129, c_customer_id#8130, c_first_name#8137, c_last_name#8138, c_preferred_cust_flag#8139, c_birth_country#8143, c_login#8144, c_email_address#8145)
    // Right Table: ListBuffer(ws_sold_date_sk#8147, ws_bill_customer_sk#8151)
    // Output Table: ListBuffer(c_customer_id#8130, c_first_name#8137, c_last_name#8138, c_preferred_cust_flag#8139, c_birth_country#8143, c_login#8144, c_email_address#8145, ws_sold_date_sk#8147)
    int left_nrow = tbl_Filter_TD_7347147_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7195484_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6804084_key_leftMajor, SW_JOIN_INNER_TD_6804084_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_7347147_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk8129_k = tbl_Filter_TD_7347147_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6804084_key_leftMajor keyA{_c_customer_sk8129_k};
            int32_t _c_customer_sk8129 = tbl_Filter_TD_7347147_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id8130_n = tbl_Filter_TD_7347147_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_customer_id8130 = std::string(_c_customer_id8130_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8137_n = tbl_Filter_TD_7347147_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_first_name8137 = std::string(_c_first_name8137_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name8138_n = tbl_Filter_TD_7347147_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_last_name8138 = std::string(_c_last_name8138_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag8139_n = tbl_Filter_TD_7347147_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_preferred_cust_flag8139 = std::string(_c_preferred_cust_flag8139_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country8143_n = tbl_Filter_TD_7347147_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _c_birth_country8143 = std::string(_c_birth_country8143_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_login8144_n = tbl_Filter_TD_7347147_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _c_login8144 = std::string(_c_login8144_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address8145_n = tbl_Filter_TD_7347147_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _c_email_address8145 = std::string(_c_email_address8145_n.data());
            SW_JOIN_INNER_TD_6804084_payload_leftMajor payloadA{_c_customer_sk8129, _c_customer_id8130, _c_first_name8137, _c_last_name8138, _c_preferred_cust_flag8139, _c_birth_country8143, _c_login8144, _c_email_address8145};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7195484_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_bill_customer_sk8151_k = tbl_Filter_TD_7195484_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6804084_key_leftMajor{_ws_bill_customer_sk8151_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk8129 = (it->second)._c_customer_sk8129;
                std::string _c_customer_id8130 = (it->second)._c_customer_id8130;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id8130_n{};
                memcpy(_c_customer_id8130_n.data(), (_c_customer_id8130).data(), (_c_customer_id8130).length());
                std::string _c_first_name8137 = (it->second)._c_first_name8137;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8137_n{};
                memcpy(_c_first_name8137_n.data(), (_c_first_name8137).data(), (_c_first_name8137).length());
                std::string _c_last_name8138 = (it->second)._c_last_name8138;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name8138_n{};
                memcpy(_c_last_name8138_n.data(), (_c_last_name8138).data(), (_c_last_name8138).length());
                std::string _c_preferred_cust_flag8139 = (it->second)._c_preferred_cust_flag8139;
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag8139_n{};
                memcpy(_c_preferred_cust_flag8139_n.data(), (_c_preferred_cust_flag8139).data(), (_c_preferred_cust_flag8139).length());
                std::string _c_birth_country8143 = (it->second)._c_birth_country8143;
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country8143_n{};
                memcpy(_c_birth_country8143_n.data(), (_c_birth_country8143).data(), (_c_birth_country8143).length());
                std::string _c_login8144 = (it->second)._c_login8144;
                std::array<char, TPCDS_READ_MAX + 1> _c_login8144_n{};
                memcpy(_c_login8144_n.data(), (_c_login8144).data(), (_c_login8144).length());
                std::string _c_email_address8145 = (it->second)._c_email_address8145;
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address8145_n{};
                memcpy(_c_email_address8145_n.data(), (_c_email_address8145).data(), (_c_email_address8145).length());
                int32_t _ws_sold_date_sk8147 = tbl_Filter_TD_7195484_output.getInt32(i, 0);
                int32_t _ws_bill_customer_sk8151 = tbl_Filter_TD_7195484_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_6804084_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id8130_n);
                tbl_JOIN_INNER_TD_6804084_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8137_n);
                tbl_JOIN_INNER_TD_6804084_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name8138_n);
                tbl_JOIN_INNER_TD_6804084_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag8139_n);
                tbl_JOIN_INNER_TD_6804084_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country8143_n);
                tbl_JOIN_INNER_TD_6804084_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login8144_n);
                tbl_JOIN_INNER_TD_6804084_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address8145_n);
                tbl_JOIN_INNER_TD_6804084_output.setInt32(r, 7, _ws_sold_date_sk8147);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6804084_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6804084_key_rightMajor, SW_JOIN_INNER_TD_6804084_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7195484_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_bill_customer_sk8151_k = tbl_Filter_TD_7195484_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_6804084_key_rightMajor keyA{_ws_bill_customer_sk8151_k};
            int32_t _ws_sold_date_sk8147 = tbl_Filter_TD_7195484_output.getInt32(i, 0);
            int32_t _ws_bill_customer_sk8151 = tbl_Filter_TD_7195484_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_6804084_payload_rightMajor payloadA{_ws_sold_date_sk8147, _ws_bill_customer_sk8151};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7347147_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk8129_k = tbl_Filter_TD_7347147_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6804084_key_rightMajor{_c_customer_sk8129_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_date_sk8147 = (it->second)._ws_sold_date_sk8147;
                int32_t _ws_bill_customer_sk8151 = (it->second)._ws_bill_customer_sk8151;
                int32_t _c_customer_sk8129 = tbl_Filter_TD_7347147_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id8130_n = tbl_Filter_TD_7347147_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_customer_id8130 = std::string(_c_customer_id8130_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8137_n = tbl_Filter_TD_7347147_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_first_name8137 = std::string(_c_first_name8137_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name8138_n = tbl_Filter_TD_7347147_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_last_name8138 = std::string(_c_last_name8138_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag8139_n = tbl_Filter_TD_7347147_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_preferred_cust_flag8139 = std::string(_c_preferred_cust_flag8139_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country8143_n = tbl_Filter_TD_7347147_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _c_birth_country8143 = std::string(_c_birth_country8143_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_login8144_n = tbl_Filter_TD_7347147_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _c_login8144 = std::string(_c_login8144_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address8145_n = tbl_Filter_TD_7347147_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _c_email_address8145 = std::string(_c_email_address8145_n.data());
                tbl_JOIN_INNER_TD_6804084_output.setInt32(r, 7, _ws_sold_date_sk8147);
                tbl_JOIN_INNER_TD_6804084_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id8130_n);
                tbl_JOIN_INNER_TD_6804084_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8137_n);
                tbl_JOIN_INNER_TD_6804084_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name8138_n);
                tbl_JOIN_INNER_TD_6804084_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag8139_n);
                tbl_JOIN_INNER_TD_6804084_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country8143_n);
                tbl_JOIN_INNER_TD_6804084_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login8144_n);
                tbl_JOIN_INNER_TD_6804084_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address8145_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6804084_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6804084_output #Row: " << tbl_JOIN_INNER_TD_6804084_output.getNumRow() << std::endl;
}

void SW_Filter_TD_68527(Table &tbl_Aggregate_TD_7400563_output, Table &tbl_Filter_TD_68527_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(year_total#4178) AND (year_total#4178 > 0.000000)))
    // Input: ListBuffer(customer_id#4170, year_total#4178)
    // Output: ListBuffer(customer_id#4170)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_7400563_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _year_total4178 = tbl_Aggregate_TD_7400563_output.getInt64(i, 1);
        if ((_year_total4178!= 0) && (_year_total4178 > 0.000000)) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4170_t = tbl_Aggregate_TD_7400563_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            tbl_Filter_TD_68527_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id4170_t);
            r++;
        }
    }
    tbl_Filter_TD_68527_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_68527_output #Row: " << tbl_Filter_TD_68527_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_6888380_key {
    std::string _c_customer_id7572;
    std::string _c_first_name7579;
    std::string _c_last_name7580;
    std::string _c_preferred_cust_flag7581;
    std::string _c_birth_country7585;
    std::string _c_login7586;
    std::string _c_email_address7587;
    int32_t _d_year7629;
    bool operator==(const SW_Aggregate_TD_6888380_key& other) const { return (_c_customer_id7572 == other._c_customer_id7572) && (_c_first_name7579 == other._c_first_name7579) && (_c_last_name7580 == other._c_last_name7580) && (_c_preferred_cust_flag7581 == other._c_preferred_cust_flag7581) && (_c_birth_country7585 == other._c_birth_country7585) && (_c_login7586 == other._c_login7586) && (_c_email_address7587 == other._c_email_address7587) && (_d_year7629 == other._d_year7629); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_6888380_key> {
    std::size_t operator() (const SW_Aggregate_TD_6888380_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._c_customer_id7572)) + (hash<string>()(k._c_first_name7579)) + (hash<string>()(k._c_last_name7580)) + (hash<string>()(k._c_preferred_cust_flag7581)) + (hash<string>()(k._c_birth_country7585)) + (hash<string>()(k._c_login7586)) + (hash<string>()(k._c_email_address7587)) + (hash<int32_t>()(k._d_year7629));
    }
};
}
struct SW_Aggregate_TD_6888380_payload {
    std::string _customer_id4295;
};
void SW_Aggregate_TD_6888380(Table &tbl_JOIN_INNER_TD_7196854_output, Table &tbl_Aggregate_TD_6888380_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_customer_id#7572, c_first_name#7579, c_last_name#7580, c_preferred_cust_flag#7581, c_birth_country#7585, c_login#7586, c_email_address#7587, d_year#7629, c_customer_id#7572 AS customer_id#4295)
    // Input: ListBuffer(c_customer_id#7572, c_first_name#7579, c_last_name#7580, c_preferred_cust_flag#7581, c_birth_country#7585, c_login#7586, c_email_address#7587, d_year#7629)
    // Output: ListBuffer(customer_id#4295)
    std::unordered_map<SW_Aggregate_TD_6888380_key, SW_Aggregate_TD_6888380_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_7196854_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id7572 = tbl_JOIN_INNER_TD_7196854_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name7579 = tbl_JOIN_INNER_TD_7196854_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name7580 = tbl_JOIN_INNER_TD_7196854_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag7581 = tbl_JOIN_INNER_TD_7196854_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _c_birth_country7585 = tbl_JOIN_INNER_TD_7196854_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _c_login7586 = tbl_JOIN_INNER_TD_7196854_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _c_email_address7587 = tbl_JOIN_INNER_TD_7196854_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        int32_t _d_year7629 = tbl_JOIN_INNER_TD_7196854_output.getInt32(i, 7);
        SW_Aggregate_TD_6888380_key k{std::string(_c_customer_id7572.data()), std::string(_c_first_name7579.data()), std::string(_c_last_name7580.data()), std::string(_c_preferred_cust_flag7581.data()), std::string(_c_birth_country7585.data()), std::string(_c_login7586.data()), std::string(_c_email_address7587.data()), _d_year7629};
        std::array<char, TPCDS_READ_MAX + 1> _customer_id4295 = _c_customer_id7572;
        SW_Aggregate_TD_6888380_payload p{std::string(_customer_id4295.data())};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _c_customer_id7572 not required in the output table
        // _c_first_name7579 not required in the output table
        // _c_last_name7580 not required in the output table
        // _c_preferred_cust_flag7581 not required in the output table
        // _c_birth_country7585 not required in the output table
        // _c_login7586 not required in the output table
        // _c_email_address7587 not required in the output table
        // _d_year7629 not required in the output table
        std::array<char, TPCDS_READ_MAX + 1> _customer_id4295_n{};
        memcpy(_customer_id4295_n.data(), (it.second)._customer_id4295.data(), (it.second)._customer_id4295.length());
        tbl_Aggregate_TD_6888380_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id4295_n);
        ++r;
    }
    tbl_Aggregate_TD_6888380_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_6888380_output #Row: " << tbl_Aggregate_TD_6888380_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6978445_key_leftMajor {
    std::string _customer_id4150;
    bool operator==(const SW_JOIN_INNER_TD_6978445_key_leftMajor& other) const {
        return ((_customer_id4150 == other._customer_id4150));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6978445_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6978445_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._customer_id4150));
    }
};
}
struct SW_JOIN_INNER_TD_6978445_payload_leftMajor {
    std::string _customer_id4150;
    std::string _customer_id4275;
    std::string _customer_first_name4276;
    std::string _customer_last_name4277;
    std::string _customer_preferred_cust_flag4278;
};
struct SW_JOIN_INNER_TD_6978445_key_rightMajor {
    std::string _customer_id7492;
    bool operator==(const SW_JOIN_INNER_TD_6978445_key_rightMajor& other) const {
        return ((_customer_id7492 == other._customer_id7492));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6978445_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6978445_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._customer_id7492));
    }
};
}
struct SW_JOIN_INNER_TD_6978445_payload_rightMajor {
    std::string _customer_id7492;
};
void SW_JOIN_INNER_TD_6978445(Table &tbl_JOIN_INNER_TD_7228170_output, Table &tbl_Project_TD_7309655_output, Table &tbl_JOIN_INNER_TD_6978445_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((customer_id#4150 = customer_id#7492))
    // Left Table: ListBuffer(customer_id#4150, customer_id#4275, customer_first_name#4276, customer_last_name#4277, customer_preferred_cust_flag#4278)
    // Right Table: ListBuffer(customer_id#7492)
    // Output Table: ListBuffer(customer_id#4150, customer_id#4275, customer_first_name#4276, customer_last_name#4277, customer_preferred_cust_flag#4278)
    int left_nrow = tbl_JOIN_INNER_TD_7228170_output.getNumRow();
    int right_nrow = tbl_Project_TD_7309655_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6978445_key_leftMajor, SW_JOIN_INNER_TD_6978445_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7228170_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_k_n = tbl_JOIN_INNER_TD_7228170_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id4150_k = std::string(_customer_id4150_k_n.data());
            SW_JOIN_INNER_TD_6978445_key_leftMajor keyA{_customer_id4150_k};
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_n = tbl_JOIN_INNER_TD_7228170_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id4150 = std::string(_customer_id4150_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4275_n = tbl_JOIN_INNER_TD_7228170_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _customer_id4275 = std::string(_customer_id4275_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_first_name4276_n = tbl_JOIN_INNER_TD_7228170_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _customer_first_name4276 = std::string(_customer_first_name4276_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_last_name4277_n = tbl_JOIN_INNER_TD_7228170_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _customer_last_name4277 = std::string(_customer_last_name4277_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag4278_n = tbl_JOIN_INNER_TD_7228170_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _customer_preferred_cust_flag4278 = std::string(_customer_preferred_cust_flag4278_n.data());
            SW_JOIN_INNER_TD_6978445_payload_leftMajor payloadA{_customer_id4150, _customer_id4275, _customer_first_name4276, _customer_last_name4277, _customer_preferred_cust_flag4278};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Project_TD_7309655_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id7492_k_n = tbl_Project_TD_7309655_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id7492_k = std::string(_customer_id7492_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6978445_key_leftMajor{_customer_id7492_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _customer_id4150 = (it->second)._customer_id4150;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_n{};
                memcpy(_customer_id4150_n.data(), (_customer_id4150).data(), (_customer_id4150).length());
                std::string _customer_id4275 = (it->second)._customer_id4275;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id4275_n{};
                memcpy(_customer_id4275_n.data(), (_customer_id4275).data(), (_customer_id4275).length());
                std::string _customer_first_name4276 = (it->second)._customer_first_name4276;
                std::array<char, TPCDS_READ_MAX + 1> _customer_first_name4276_n{};
                memcpy(_customer_first_name4276_n.data(), (_customer_first_name4276).data(), (_customer_first_name4276).length());
                std::string _customer_last_name4277 = (it->second)._customer_last_name4277;
                std::array<char, TPCDS_READ_MAX + 1> _customer_last_name4277_n{};
                memcpy(_customer_last_name4277_n.data(), (_customer_last_name4277).data(), (_customer_last_name4277).length());
                std::string _customer_preferred_cust_flag4278 = (it->second)._customer_preferred_cust_flag4278;
                std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag4278_n{};
                memcpy(_customer_preferred_cust_flag4278_n.data(), (_customer_preferred_cust_flag4278).data(), (_customer_preferred_cust_flag4278).length());
                std::array<char, TPCDS_READ_MAX + 1> _customer_id7492_n = tbl_Project_TD_7309655_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _customer_id7492 = std::string(_customer_id7492_n.data());
                tbl_JOIN_INNER_TD_6978445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id4150_n);
                tbl_JOIN_INNER_TD_6978445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _customer_id4275_n);
                tbl_JOIN_INNER_TD_6978445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _customer_first_name4276_n);
                tbl_JOIN_INNER_TD_6978445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _customer_last_name4277_n);
                tbl_JOIN_INNER_TD_6978445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _customer_preferred_cust_flag4278_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6978445_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6978445_key_rightMajor, SW_JOIN_INNER_TD_6978445_payload_rightMajor> ht1;
        int nrow1 = tbl_Project_TD_7309655_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id7492_k_n = tbl_Project_TD_7309655_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id7492_k = std::string(_customer_id7492_k_n.data());
            SW_JOIN_INNER_TD_6978445_key_rightMajor keyA{_customer_id7492_k};
            std::array<char, TPCDS_READ_MAX + 1> _customer_id7492_n = tbl_Project_TD_7309655_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id7492 = std::string(_customer_id7492_n.data());
            SW_JOIN_INNER_TD_6978445_payload_rightMajor payloadA{_customer_id7492};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7228170_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_k_n = tbl_JOIN_INNER_TD_7228170_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id4150_k = std::string(_customer_id4150_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6978445_key_rightMajor{_customer_id4150_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _customer_id7492 = (it->second)._customer_id7492;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id7492_n{};
                memcpy(_customer_id7492_n.data(), (_customer_id7492).data(), (_customer_id7492).length());
                std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_n = tbl_JOIN_INNER_TD_7228170_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _customer_id4150 = std::string(_customer_id4150_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_id4275_n = tbl_JOIN_INNER_TD_7228170_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _customer_id4275 = std::string(_customer_id4275_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_first_name4276_n = tbl_JOIN_INNER_TD_7228170_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _customer_first_name4276 = std::string(_customer_first_name4276_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_last_name4277_n = tbl_JOIN_INNER_TD_7228170_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _customer_last_name4277 = std::string(_customer_last_name4277_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag4278_n = tbl_JOIN_INNER_TD_7228170_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _customer_preferred_cust_flag4278 = std::string(_customer_preferred_cust_flag4278_n.data());
                tbl_JOIN_INNER_TD_6978445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id4150_n);
                tbl_JOIN_INNER_TD_6978445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _customer_id4275_n);
                tbl_JOIN_INNER_TD_6978445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _customer_first_name4276_n);
                tbl_JOIN_INNER_TD_6978445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _customer_last_name4277_n);
                tbl_JOIN_INNER_TD_6978445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _customer_preferred_cust_flag4278_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6978445_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6978445_output #Row: " << tbl_JOIN_INNER_TD_6978445_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5399415_key_leftMajor {
    int32_t _ws_sold_date_sk8147;
    bool operator==(const SW_JOIN_INNER_TD_5399415_key_leftMajor& other) const {
        return ((_ws_sold_date_sk8147 == other._ws_sold_date_sk8147));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5399415_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5399415_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_sold_date_sk8147));
    }
};
}
struct SW_JOIN_INNER_TD_5399415_payload_leftMajor {
    std::string _c_customer_id8130;
    std::string _c_first_name8137;
    std::string _c_last_name8138;
    std::string _c_preferred_cust_flag8139;
    std::string _c_birth_country8143;
    std::string _c_login8144;
    std::string _c_email_address8145;
    int32_t _ws_sold_date_sk8147;
};
struct SW_JOIN_INNER_TD_5399415_key_rightMajor {
    int32_t _d_date_sk8181;
    bool operator==(const SW_JOIN_INNER_TD_5399415_key_rightMajor& other) const {
        return ((_d_date_sk8181 == other._d_date_sk8181));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5399415_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5399415_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk8181));
    }
};
}
struct SW_JOIN_INNER_TD_5399415_payload_rightMajor {
    int32_t _d_date_sk8181;
    int32_t _d_year8187;
};
void SW_JOIN_INNER_TD_5399415(Table &tbl_JOIN_INNER_TD_6804084_output, Table &tbl_Filter_TD_6163670_output, Table &tbl_JOIN_INNER_TD_5399415_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_sold_date_sk#8147 = d_date_sk#8181))
    // Left Table: ListBuffer(c_customer_id#8130, c_first_name#8137, c_last_name#8138, c_preferred_cust_flag#8139, c_birth_country#8143, c_login#8144, c_email_address#8145, ws_sold_date_sk#8147)
    // Right Table: ListBuffer(d_date_sk#8181, d_year#8187)
    // Output Table: ListBuffer(c_customer_id#8130, c_first_name#8137, c_last_name#8138, c_preferred_cust_flag#8139, c_birth_country#8143, c_login#8144, c_email_address#8145, d_year#8187)
    int left_nrow = tbl_JOIN_INNER_TD_6804084_output.getNumRow();
    int right_nrow = tbl_Filter_TD_6163670_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5399415_key_leftMajor, SW_JOIN_INNER_TD_5399415_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_6804084_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_sold_date_sk8147_k = tbl_JOIN_INNER_TD_6804084_output.getInt32(i, 7);
            SW_JOIN_INNER_TD_5399415_key_leftMajor keyA{_ws_sold_date_sk8147_k};
            std::array<char, TPCDS_READ_MAX + 1> _c_customer_id8130_n = tbl_JOIN_INNER_TD_6804084_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _c_customer_id8130 = std::string(_c_customer_id8130_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name8137_n = tbl_JOIN_INNER_TD_6804084_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_first_name8137 = std::string(_c_first_name8137_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name8138_n = tbl_JOIN_INNER_TD_6804084_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_last_name8138 = std::string(_c_last_name8138_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag8139_n = tbl_JOIN_INNER_TD_6804084_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_preferred_cust_flag8139 = std::string(_c_preferred_cust_flag8139_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_birth_country8143_n = tbl_JOIN_INNER_TD_6804084_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_birth_country8143 = std::string(_c_birth_country8143_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_login8144_n = tbl_JOIN_INNER_TD_6804084_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _c_login8144 = std::string(_c_login8144_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_email_address8145_n = tbl_JOIN_INNER_TD_6804084_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _c_email_address8145 = std::string(_c_email_address8145_n.data());
            int32_t _ws_sold_date_sk8147 = tbl_JOIN_INNER_TD_6804084_output.getInt32(i, 7);
            SW_JOIN_INNER_TD_5399415_payload_leftMajor payloadA{_c_customer_id8130, _c_first_name8137, _c_last_name8138, _c_preferred_cust_flag8139, _c_birth_country8143, _c_login8144, _c_email_address8145, _ws_sold_date_sk8147};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6163670_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk8181_k = tbl_Filter_TD_6163670_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5399415_key_leftMajor{_d_date_sk8181_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _c_customer_id8130 = (it->second)._c_customer_id8130;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id8130_n{};
                memcpy(_c_customer_id8130_n.data(), (_c_customer_id8130).data(), (_c_customer_id8130).length());
                std::string _c_first_name8137 = (it->second)._c_first_name8137;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8137_n{};
                memcpy(_c_first_name8137_n.data(), (_c_first_name8137).data(), (_c_first_name8137).length());
                std::string _c_last_name8138 = (it->second)._c_last_name8138;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name8138_n{};
                memcpy(_c_last_name8138_n.data(), (_c_last_name8138).data(), (_c_last_name8138).length());
                std::string _c_preferred_cust_flag8139 = (it->second)._c_preferred_cust_flag8139;
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag8139_n{};
                memcpy(_c_preferred_cust_flag8139_n.data(), (_c_preferred_cust_flag8139).data(), (_c_preferred_cust_flag8139).length());
                std::string _c_birth_country8143 = (it->second)._c_birth_country8143;
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country8143_n{};
                memcpy(_c_birth_country8143_n.data(), (_c_birth_country8143).data(), (_c_birth_country8143).length());
                std::string _c_login8144 = (it->second)._c_login8144;
                std::array<char, TPCDS_READ_MAX + 1> _c_login8144_n{};
                memcpy(_c_login8144_n.data(), (_c_login8144).data(), (_c_login8144).length());
                std::string _c_email_address8145 = (it->second)._c_email_address8145;
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address8145_n{};
                memcpy(_c_email_address8145_n.data(), (_c_email_address8145).data(), (_c_email_address8145).length());
                int32_t _ws_sold_date_sk8147 = (it->second)._ws_sold_date_sk8147;
                int32_t _d_date_sk8181 = tbl_Filter_TD_6163670_output.getInt32(i, 0);
                int32_t _d_year8187 = tbl_Filter_TD_6163670_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_5399415_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id8130_n);
                tbl_JOIN_INNER_TD_5399415_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8137_n);
                tbl_JOIN_INNER_TD_5399415_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name8138_n);
                tbl_JOIN_INNER_TD_5399415_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag8139_n);
                tbl_JOIN_INNER_TD_5399415_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country8143_n);
                tbl_JOIN_INNER_TD_5399415_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login8144_n);
                tbl_JOIN_INNER_TD_5399415_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address8145_n);
                tbl_JOIN_INNER_TD_5399415_output.setInt32(r, 7, _d_year8187);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5399415_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5399415_key_rightMajor, SW_JOIN_INNER_TD_5399415_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_6163670_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk8181_k = tbl_Filter_TD_6163670_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5399415_key_rightMajor keyA{_d_date_sk8181_k};
            int32_t _d_date_sk8181 = tbl_Filter_TD_6163670_output.getInt32(i, 0);
            int32_t _d_year8187 = tbl_Filter_TD_6163670_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_5399415_payload_rightMajor payloadA{_d_date_sk8181, _d_year8187};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_6804084_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_sold_date_sk8147_k = tbl_JOIN_INNER_TD_6804084_output.getInt32(i, 7);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5399415_key_rightMajor{_ws_sold_date_sk8147_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk8181 = (it->second)._d_date_sk8181;
                int32_t _d_year8187 = (it->second)._d_year8187;
                std::array<char, TPCDS_READ_MAX + 1> _c_customer_id8130_n = tbl_JOIN_INNER_TD_6804084_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _c_customer_id8130 = std::string(_c_customer_id8130_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name8137_n = tbl_JOIN_INNER_TD_6804084_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_first_name8137 = std::string(_c_first_name8137_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name8138_n = tbl_JOIN_INNER_TD_6804084_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_last_name8138 = std::string(_c_last_name8138_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag8139_n = tbl_JOIN_INNER_TD_6804084_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_preferred_cust_flag8139 = std::string(_c_preferred_cust_flag8139_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_birth_country8143_n = tbl_JOIN_INNER_TD_6804084_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_birth_country8143 = std::string(_c_birth_country8143_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_login8144_n = tbl_JOIN_INNER_TD_6804084_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _c_login8144 = std::string(_c_login8144_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_email_address8145_n = tbl_JOIN_INNER_TD_6804084_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _c_email_address8145 = std::string(_c_email_address8145_n.data());
                int32_t _ws_sold_date_sk8147 = tbl_JOIN_INNER_TD_6804084_output.getInt32(i, 7);
                tbl_JOIN_INNER_TD_5399415_output.setInt32(r, 7, _d_year8187);
                tbl_JOIN_INNER_TD_5399415_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_customer_id8130_n);
                tbl_JOIN_INNER_TD_5399415_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name8137_n);
                tbl_JOIN_INNER_TD_5399415_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name8138_n);
                tbl_JOIN_INNER_TD_5399415_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_preferred_cust_flag8139_n);
                tbl_JOIN_INNER_TD_5399415_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_birth_country8143_n);
                tbl_JOIN_INNER_TD_5399415_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _c_login8144_n);
                tbl_JOIN_INNER_TD_5399415_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _c_email_address8145_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5399415_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5399415_output #Row: " << tbl_JOIN_INNER_TD_5399415_output.getNumRow() << std::endl;
}

void SW_Project_TD_5499769(Table &tbl_Filter_TD_68527_output, Table &tbl_Project_TD_5499769_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(customer_id#4170 AS customer_id#7970)
    // Input: ListBuffer(customer_id#4170)
    // Output: ListBuffer(customer_id#7970)
    int nrow1 = tbl_Filter_TD_68527_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _customer_id4170 = tbl_Filter_TD_68527_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _customer_id7970 = _customer_id4170;
        tbl_Project_TD_5499769_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 0, _customer_id7970);
    }
    tbl_Project_TD_5499769_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_5499769_output #Row: " << tbl_Project_TD_5499769_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_567869_key_leftMajor {
    std::string _customer_id4150;
    bool operator==(const SW_JOIN_INNER_TD_567869_key_leftMajor& other) const {
        return ((_customer_id4150 == other._customer_id4150));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_567869_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_567869_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._customer_id4150));
    }
};
}
struct SW_JOIN_INNER_TD_567869_payload_leftMajor {
    std::string _customer_id4150;
    std::string _customer_id4275;
    std::string _customer_first_name4276;
    std::string _customer_last_name4277;
    std::string _customer_preferred_cust_flag4278;
};
struct SW_JOIN_INNER_TD_567869_key_rightMajor {
    std::string _customer_id4295;
    bool operator==(const SW_JOIN_INNER_TD_567869_key_rightMajor& other) const {
        return ((_customer_id4295 == other._customer_id4295));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_567869_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_567869_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._customer_id4295));
    }
};
}
struct SW_JOIN_INNER_TD_567869_payload_rightMajor {
    std::string _customer_id4295;
};
void SW_JOIN_INNER_TD_567869(Table &tbl_JOIN_INNER_TD_6978445_output, Table &tbl_Aggregate_TD_6888380_output, Table &tbl_JOIN_INNER_TD_567869_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((customer_id#4150 = customer_id#4295))
    // Left Table: ListBuffer(customer_id#4150, customer_id#4275, customer_first_name#4276, customer_last_name#4277, customer_preferred_cust_flag#4278)
    // Right Table: ListBuffer(customer_id#4295)
    // Output Table: ListBuffer(customer_id#4150, customer_id#4275, customer_first_name#4276, customer_last_name#4277, customer_preferred_cust_flag#4278)
    int left_nrow = tbl_JOIN_INNER_TD_6978445_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_6888380_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_567869_key_leftMajor, SW_JOIN_INNER_TD_567869_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_6978445_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_k_n = tbl_JOIN_INNER_TD_6978445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id4150_k = std::string(_customer_id4150_k_n.data());
            SW_JOIN_INNER_TD_567869_key_leftMajor keyA{_customer_id4150_k};
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_n = tbl_JOIN_INNER_TD_6978445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id4150 = std::string(_customer_id4150_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4275_n = tbl_JOIN_INNER_TD_6978445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _customer_id4275 = std::string(_customer_id4275_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_first_name4276_n = tbl_JOIN_INNER_TD_6978445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _customer_first_name4276 = std::string(_customer_first_name4276_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_last_name4277_n = tbl_JOIN_INNER_TD_6978445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _customer_last_name4277 = std::string(_customer_last_name4277_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag4278_n = tbl_JOIN_INNER_TD_6978445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _customer_preferred_cust_flag4278 = std::string(_customer_preferred_cust_flag4278_n.data());
            SW_JOIN_INNER_TD_567869_payload_leftMajor payloadA{_customer_id4150, _customer_id4275, _customer_first_name4276, _customer_last_name4277, _customer_preferred_cust_flag4278};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_6888380_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4295_k_n = tbl_Aggregate_TD_6888380_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id4295_k = std::string(_customer_id4295_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_567869_key_leftMajor{_customer_id4295_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _customer_id4150 = (it->second)._customer_id4150;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_n{};
                memcpy(_customer_id4150_n.data(), (_customer_id4150).data(), (_customer_id4150).length());
                std::string _customer_id4275 = (it->second)._customer_id4275;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id4275_n{};
                memcpy(_customer_id4275_n.data(), (_customer_id4275).data(), (_customer_id4275).length());
                std::string _customer_first_name4276 = (it->second)._customer_first_name4276;
                std::array<char, TPCDS_READ_MAX + 1> _customer_first_name4276_n{};
                memcpy(_customer_first_name4276_n.data(), (_customer_first_name4276).data(), (_customer_first_name4276).length());
                std::string _customer_last_name4277 = (it->second)._customer_last_name4277;
                std::array<char, TPCDS_READ_MAX + 1> _customer_last_name4277_n{};
                memcpy(_customer_last_name4277_n.data(), (_customer_last_name4277).data(), (_customer_last_name4277).length());
                std::string _customer_preferred_cust_flag4278 = (it->second)._customer_preferred_cust_flag4278;
                std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag4278_n{};
                memcpy(_customer_preferred_cust_flag4278_n.data(), (_customer_preferred_cust_flag4278).data(), (_customer_preferred_cust_flag4278).length());
                std::array<char, TPCDS_READ_MAX + 1> _customer_id4295_n = tbl_Aggregate_TD_6888380_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _customer_id4295 = std::string(_customer_id4295_n.data());
                tbl_JOIN_INNER_TD_567869_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id4150_n);
                tbl_JOIN_INNER_TD_567869_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _customer_id4275_n);
                tbl_JOIN_INNER_TD_567869_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _customer_first_name4276_n);
                tbl_JOIN_INNER_TD_567869_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _customer_last_name4277_n);
                tbl_JOIN_INNER_TD_567869_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _customer_preferred_cust_flag4278_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_567869_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_567869_key_rightMajor, SW_JOIN_INNER_TD_567869_payload_rightMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_6888380_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4295_k_n = tbl_Aggregate_TD_6888380_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id4295_k = std::string(_customer_id4295_k_n.data());
            SW_JOIN_INNER_TD_567869_key_rightMajor keyA{_customer_id4295_k};
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4295_n = tbl_Aggregate_TD_6888380_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id4295 = std::string(_customer_id4295_n.data());
            SW_JOIN_INNER_TD_567869_payload_rightMajor payloadA{_customer_id4295};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_6978445_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_k_n = tbl_JOIN_INNER_TD_6978445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id4150_k = std::string(_customer_id4150_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_567869_key_rightMajor{_customer_id4150_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _customer_id4295 = (it->second)._customer_id4295;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id4295_n{};
                memcpy(_customer_id4295_n.data(), (_customer_id4295).data(), (_customer_id4295).length());
                std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_n = tbl_JOIN_INNER_TD_6978445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _customer_id4150 = std::string(_customer_id4150_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_id4275_n = tbl_JOIN_INNER_TD_6978445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _customer_id4275 = std::string(_customer_id4275_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_first_name4276_n = tbl_JOIN_INNER_TD_6978445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _customer_first_name4276 = std::string(_customer_first_name4276_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_last_name4277_n = tbl_JOIN_INNER_TD_6978445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _customer_last_name4277 = std::string(_customer_last_name4277_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag4278_n = tbl_JOIN_INNER_TD_6978445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _customer_preferred_cust_flag4278 = std::string(_customer_preferred_cust_flag4278_n.data());
                tbl_JOIN_INNER_TD_567869_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id4150_n);
                tbl_JOIN_INNER_TD_567869_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _customer_id4275_n);
                tbl_JOIN_INNER_TD_567869_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _customer_first_name4276_n);
                tbl_JOIN_INNER_TD_567869_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _customer_last_name4277_n);
                tbl_JOIN_INNER_TD_567869_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _customer_preferred_cust_flag4278_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_567869_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_567869_output #Row: " << tbl_JOIN_INNER_TD_567869_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_4731680_key {
    std::string _c_customer_id8130;
    std::string _c_first_name8137;
    std::string _c_last_name8138;
    std::string _c_preferred_cust_flag8139;
    std::string _c_birth_country8143;
    std::string _c_login8144;
    std::string _c_email_address8145;
    int32_t _d_year8187;
    bool operator==(const SW_Aggregate_TD_4731680_key& other) const { return (_c_customer_id8130 == other._c_customer_id8130) && (_c_first_name8137 == other._c_first_name8137) && (_c_last_name8138 == other._c_last_name8138) && (_c_preferred_cust_flag8139 == other._c_preferred_cust_flag8139) && (_c_birth_country8143 == other._c_birth_country8143) && (_c_login8144 == other._c_login8144) && (_c_email_address8145 == other._c_email_address8145) && (_d_year8187 == other._d_year8187); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_4731680_key> {
    std::size_t operator() (const SW_Aggregate_TD_4731680_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._c_customer_id8130)) + (hash<string>()(k._c_first_name8137)) + (hash<string>()(k._c_last_name8138)) + (hash<string>()(k._c_preferred_cust_flag8139)) + (hash<string>()(k._c_birth_country8143)) + (hash<string>()(k._c_login8144)) + (hash<string>()(k._c_email_address8145)) + (hash<int32_t>()(k._d_year8187));
    }
};
}
struct SW_Aggregate_TD_4731680_payload {
    std::string _customer_id4315;
};
void SW_Aggregate_TD_4731680(Table &tbl_JOIN_INNER_TD_5399415_output, Table &tbl_Aggregate_TD_4731680_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_customer_id#8130, c_first_name#8137, c_last_name#8138, c_preferred_cust_flag#8139, c_birth_country#8143, c_login#8144, c_email_address#8145, d_year#8187, c_customer_id#8130 AS customer_id#4315)
    // Input: ListBuffer(c_customer_id#8130, c_first_name#8137, c_last_name#8138, c_preferred_cust_flag#8139, c_birth_country#8143, c_login#8144, c_email_address#8145, d_year#8187)
    // Output: ListBuffer(customer_id#4315)
    std::unordered_map<SW_Aggregate_TD_4731680_key, SW_Aggregate_TD_4731680_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_5399415_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_customer_id8130 = tbl_JOIN_INNER_TD_5399415_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name8137 = tbl_JOIN_INNER_TD_5399415_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name8138 = tbl_JOIN_INNER_TD_5399415_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _c_preferred_cust_flag8139 = tbl_JOIN_INNER_TD_5399415_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _c_birth_country8143 = tbl_JOIN_INNER_TD_5399415_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _c_login8144 = tbl_JOIN_INNER_TD_5399415_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _c_email_address8145 = tbl_JOIN_INNER_TD_5399415_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        int32_t _d_year8187 = tbl_JOIN_INNER_TD_5399415_output.getInt32(i, 7);
        SW_Aggregate_TD_4731680_key k{std::string(_c_customer_id8130.data()), std::string(_c_first_name8137.data()), std::string(_c_last_name8138.data()), std::string(_c_preferred_cust_flag8139.data()), std::string(_c_birth_country8143.data()), std::string(_c_login8144.data()), std::string(_c_email_address8145.data()), _d_year8187};
        std::array<char, TPCDS_READ_MAX + 1> _customer_id4315 = _c_customer_id8130;
        SW_Aggregate_TD_4731680_payload p{std::string(_customer_id4315.data())};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _c_customer_id8130 not required in the output table
        // _c_first_name8137 not required in the output table
        // _c_last_name8138 not required in the output table
        // _c_preferred_cust_flag8139 not required in the output table
        // _c_birth_country8143 not required in the output table
        // _c_login8144 not required in the output table
        // _c_email_address8145 not required in the output table
        // _d_year8187 not required in the output table
        std::array<char, TPCDS_READ_MAX + 1> _customer_id4315_n{};
        memcpy(_customer_id4315_n.data(), (it.second)._customer_id4315.data(), (it.second)._customer_id4315.length());
        tbl_Aggregate_TD_4731680_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id4315_n);
        ++r;
    }
    tbl_Aggregate_TD_4731680_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_4731680_output #Row: " << tbl_Aggregate_TD_4731680_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4125986_key_leftMajor {
    std::string _customer_id4150;
    bool operator==(const SW_JOIN_INNER_TD_4125986_key_leftMajor& other) const {
        return ((_customer_id4150 == other._customer_id4150));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4125986_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4125986_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._customer_id4150));
    }
};
}
struct SW_JOIN_INNER_TD_4125986_payload_leftMajor {
    std::string _customer_id4150;
    std::string _customer_id4275;
    std::string _customer_first_name4276;
    std::string _customer_last_name4277;
    std::string _customer_preferred_cust_flag4278;
};
struct SW_JOIN_INNER_TD_4125986_key_rightMajor {
    std::string _customer_id7970;
    bool operator==(const SW_JOIN_INNER_TD_4125986_key_rightMajor& other) const {
        return ((_customer_id7970 == other._customer_id7970));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4125986_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4125986_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._customer_id7970));
    }
};
}
struct SW_JOIN_INNER_TD_4125986_payload_rightMajor {
    std::string _customer_id7970;
};
void SW_JOIN_INNER_TD_4125986(Table &tbl_JOIN_INNER_TD_567869_output, Table &tbl_Project_TD_5499769_output, Table &tbl_JOIN_INNER_TD_4125986_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((customer_id#4150 = customer_id#7970))
    // Left Table: ListBuffer(customer_id#4150, customer_id#4275, customer_first_name#4276, customer_last_name#4277, customer_preferred_cust_flag#4278)
    // Right Table: ListBuffer(customer_id#7970)
    // Output Table: ListBuffer(customer_id#4150, customer_id#4275, customer_first_name#4276, customer_last_name#4277, customer_preferred_cust_flag#4278)
    int left_nrow = tbl_JOIN_INNER_TD_567869_output.getNumRow();
    int right_nrow = tbl_Project_TD_5499769_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4125986_key_leftMajor, SW_JOIN_INNER_TD_4125986_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_567869_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_k_n = tbl_JOIN_INNER_TD_567869_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id4150_k = std::string(_customer_id4150_k_n.data());
            SW_JOIN_INNER_TD_4125986_key_leftMajor keyA{_customer_id4150_k};
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_n = tbl_JOIN_INNER_TD_567869_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id4150 = std::string(_customer_id4150_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4275_n = tbl_JOIN_INNER_TD_567869_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _customer_id4275 = std::string(_customer_id4275_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_first_name4276_n = tbl_JOIN_INNER_TD_567869_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _customer_first_name4276 = std::string(_customer_first_name4276_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_last_name4277_n = tbl_JOIN_INNER_TD_567869_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _customer_last_name4277 = std::string(_customer_last_name4277_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag4278_n = tbl_JOIN_INNER_TD_567869_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _customer_preferred_cust_flag4278 = std::string(_customer_preferred_cust_flag4278_n.data());
            SW_JOIN_INNER_TD_4125986_payload_leftMajor payloadA{_customer_id4150, _customer_id4275, _customer_first_name4276, _customer_last_name4277, _customer_preferred_cust_flag4278};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Project_TD_5499769_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id7970_k_n = tbl_Project_TD_5499769_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id7970_k = std::string(_customer_id7970_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4125986_key_leftMajor{_customer_id7970_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _customer_id4150 = (it->second)._customer_id4150;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_n{};
                memcpy(_customer_id4150_n.data(), (_customer_id4150).data(), (_customer_id4150).length());
                std::string _customer_id4275 = (it->second)._customer_id4275;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id4275_n{};
                memcpy(_customer_id4275_n.data(), (_customer_id4275).data(), (_customer_id4275).length());
                std::string _customer_first_name4276 = (it->second)._customer_first_name4276;
                std::array<char, TPCDS_READ_MAX + 1> _customer_first_name4276_n{};
                memcpy(_customer_first_name4276_n.data(), (_customer_first_name4276).data(), (_customer_first_name4276).length());
                std::string _customer_last_name4277 = (it->second)._customer_last_name4277;
                std::array<char, TPCDS_READ_MAX + 1> _customer_last_name4277_n{};
                memcpy(_customer_last_name4277_n.data(), (_customer_last_name4277).data(), (_customer_last_name4277).length());
                std::string _customer_preferred_cust_flag4278 = (it->second)._customer_preferred_cust_flag4278;
                std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag4278_n{};
                memcpy(_customer_preferred_cust_flag4278_n.data(), (_customer_preferred_cust_flag4278).data(), (_customer_preferred_cust_flag4278).length());
                std::array<char, TPCDS_READ_MAX + 1> _customer_id7970_n = tbl_Project_TD_5499769_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _customer_id7970 = std::string(_customer_id7970_n.data());
                tbl_JOIN_INNER_TD_4125986_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id4150_n);
                tbl_JOIN_INNER_TD_4125986_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _customer_id4275_n);
                tbl_JOIN_INNER_TD_4125986_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _customer_first_name4276_n);
                tbl_JOIN_INNER_TD_4125986_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _customer_last_name4277_n);
                tbl_JOIN_INNER_TD_4125986_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _customer_preferred_cust_flag4278_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4125986_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4125986_key_rightMajor, SW_JOIN_INNER_TD_4125986_payload_rightMajor> ht1;
        int nrow1 = tbl_Project_TD_5499769_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id7970_k_n = tbl_Project_TD_5499769_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id7970_k = std::string(_customer_id7970_k_n.data());
            SW_JOIN_INNER_TD_4125986_key_rightMajor keyA{_customer_id7970_k};
            std::array<char, TPCDS_READ_MAX + 1> _customer_id7970_n = tbl_Project_TD_5499769_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id7970 = std::string(_customer_id7970_n.data());
            SW_JOIN_INNER_TD_4125986_payload_rightMajor payloadA{_customer_id7970};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_567869_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_k_n = tbl_JOIN_INNER_TD_567869_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id4150_k = std::string(_customer_id4150_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4125986_key_rightMajor{_customer_id4150_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _customer_id7970 = (it->second)._customer_id7970;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id7970_n{};
                memcpy(_customer_id7970_n.data(), (_customer_id7970).data(), (_customer_id7970).length());
                std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_n = tbl_JOIN_INNER_TD_567869_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _customer_id4150 = std::string(_customer_id4150_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_id4275_n = tbl_JOIN_INNER_TD_567869_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _customer_id4275 = std::string(_customer_id4275_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_first_name4276_n = tbl_JOIN_INNER_TD_567869_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _customer_first_name4276 = std::string(_customer_first_name4276_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_last_name4277_n = tbl_JOIN_INNER_TD_567869_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _customer_last_name4277 = std::string(_customer_last_name4277_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag4278_n = tbl_JOIN_INNER_TD_567869_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _customer_preferred_cust_flag4278 = std::string(_customer_preferred_cust_flag4278_n.data());
                tbl_JOIN_INNER_TD_4125986_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id4150_n);
                tbl_JOIN_INNER_TD_4125986_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _customer_id4275_n);
                tbl_JOIN_INNER_TD_4125986_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _customer_first_name4276_n);
                tbl_JOIN_INNER_TD_4125986_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _customer_last_name4277_n);
                tbl_JOIN_INNER_TD_4125986_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _customer_preferred_cust_flag4278_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4125986_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4125986_output #Row: " << tbl_JOIN_INNER_TD_4125986_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_3549486_key_leftMajor {
    std::string _customer_id4150;
    bool operator==(const SW_JOIN_INNER_TD_3549486_key_leftMajor& other) const {
        return ((_customer_id4150 == other._customer_id4150));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3549486_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3549486_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._customer_id4150));
    }
};
}
struct SW_JOIN_INNER_TD_3549486_payload_leftMajor {
    std::string _customer_id4150;
    std::string _customer_id4275;
    std::string _customer_first_name4276;
    std::string _customer_last_name4277;
    std::string _customer_preferred_cust_flag4278;
};
struct SW_JOIN_INNER_TD_3549486_key_rightMajor {
    std::string _customer_id4315;
    bool operator==(const SW_JOIN_INNER_TD_3549486_key_rightMajor& other) const {
        return ((_customer_id4315 == other._customer_id4315));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3549486_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3549486_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._customer_id4315));
    }
};
}
struct SW_JOIN_INNER_TD_3549486_payload_rightMajor {
    std::string _customer_id4315;
};
void SW_JOIN_INNER_TD_3549486(Table &tbl_JOIN_INNER_TD_4125986_output, Table &tbl_Aggregate_TD_4731680_output, Table &tbl_JOIN_INNER_TD_3549486_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((customer_id#4150 = customer_id#4315))
    // Left Table: ListBuffer(customer_id#4150, customer_id#4275, customer_first_name#4276, customer_last_name#4277, customer_preferred_cust_flag#4278)
    // Right Table: ListBuffer(customer_id#4315)
    // Output Table: ListBuffer(customer_id#4275, customer_first_name#4276, customer_last_name#4277, customer_preferred_cust_flag#4278)
    int left_nrow = tbl_JOIN_INNER_TD_4125986_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_4731680_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3549486_key_leftMajor, SW_JOIN_INNER_TD_3549486_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_4125986_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_k_n = tbl_JOIN_INNER_TD_4125986_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id4150_k = std::string(_customer_id4150_k_n.data());
            SW_JOIN_INNER_TD_3549486_key_leftMajor keyA{_customer_id4150_k};
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_n = tbl_JOIN_INNER_TD_4125986_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id4150 = std::string(_customer_id4150_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4275_n = tbl_JOIN_INNER_TD_4125986_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _customer_id4275 = std::string(_customer_id4275_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_first_name4276_n = tbl_JOIN_INNER_TD_4125986_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _customer_first_name4276 = std::string(_customer_first_name4276_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_last_name4277_n = tbl_JOIN_INNER_TD_4125986_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _customer_last_name4277 = std::string(_customer_last_name4277_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag4278_n = tbl_JOIN_INNER_TD_4125986_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _customer_preferred_cust_flag4278 = std::string(_customer_preferred_cust_flag4278_n.data());
            SW_JOIN_INNER_TD_3549486_payload_leftMajor payloadA{_customer_id4150, _customer_id4275, _customer_first_name4276, _customer_last_name4277, _customer_preferred_cust_flag4278};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_4731680_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4315_k_n = tbl_Aggregate_TD_4731680_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id4315_k = std::string(_customer_id4315_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3549486_key_leftMajor{_customer_id4315_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _customer_id4150 = (it->second)._customer_id4150;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_n{};
                memcpy(_customer_id4150_n.data(), (_customer_id4150).data(), (_customer_id4150).length());
                std::string _customer_id4275 = (it->second)._customer_id4275;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id4275_n{};
                memcpy(_customer_id4275_n.data(), (_customer_id4275).data(), (_customer_id4275).length());
                std::string _customer_first_name4276 = (it->second)._customer_first_name4276;
                std::array<char, TPCDS_READ_MAX + 1> _customer_first_name4276_n{};
                memcpy(_customer_first_name4276_n.data(), (_customer_first_name4276).data(), (_customer_first_name4276).length());
                std::string _customer_last_name4277 = (it->second)._customer_last_name4277;
                std::array<char, TPCDS_READ_MAX + 1> _customer_last_name4277_n{};
                memcpy(_customer_last_name4277_n.data(), (_customer_last_name4277).data(), (_customer_last_name4277).length());
                std::string _customer_preferred_cust_flag4278 = (it->second)._customer_preferred_cust_flag4278;
                std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag4278_n{};
                memcpy(_customer_preferred_cust_flag4278_n.data(), (_customer_preferred_cust_flag4278).data(), (_customer_preferred_cust_flag4278).length());
                std::array<char, TPCDS_READ_MAX + 1> _customer_id4315_n = tbl_Aggregate_TD_4731680_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _customer_id4315 = std::string(_customer_id4315_n.data());
                tbl_JOIN_INNER_TD_3549486_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id4275_n);
                tbl_JOIN_INNER_TD_3549486_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _customer_first_name4276_n);
                tbl_JOIN_INNER_TD_3549486_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _customer_last_name4277_n);
                tbl_JOIN_INNER_TD_3549486_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _customer_preferred_cust_flag4278_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3549486_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3549486_key_rightMajor, SW_JOIN_INNER_TD_3549486_payload_rightMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_4731680_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4315_k_n = tbl_Aggregate_TD_4731680_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id4315_k = std::string(_customer_id4315_k_n.data());
            SW_JOIN_INNER_TD_3549486_key_rightMajor keyA{_customer_id4315_k};
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4315_n = tbl_Aggregate_TD_4731680_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id4315 = std::string(_customer_id4315_n.data());
            SW_JOIN_INNER_TD_3549486_payload_rightMajor payloadA{_customer_id4315};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_4125986_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_k_n = tbl_JOIN_INNER_TD_4125986_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _customer_id4150_k = std::string(_customer_id4150_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3549486_key_rightMajor{_customer_id4150_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _customer_id4315 = (it->second)._customer_id4315;
                std::array<char, TPCDS_READ_MAX + 1> _customer_id4315_n{};
                memcpy(_customer_id4315_n.data(), (_customer_id4315).data(), (_customer_id4315).length());
                std::array<char, TPCDS_READ_MAX + 1> _customer_id4150_n = tbl_JOIN_INNER_TD_4125986_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _customer_id4150 = std::string(_customer_id4150_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_id4275_n = tbl_JOIN_INNER_TD_4125986_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _customer_id4275 = std::string(_customer_id4275_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_first_name4276_n = tbl_JOIN_INNER_TD_4125986_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _customer_first_name4276 = std::string(_customer_first_name4276_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_last_name4277_n = tbl_JOIN_INNER_TD_4125986_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _customer_last_name4277 = std::string(_customer_last_name4277_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag4278_n = tbl_JOIN_INNER_TD_4125986_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _customer_preferred_cust_flag4278 = std::string(_customer_preferred_cust_flag4278_n.data());
                tbl_JOIN_INNER_TD_3549486_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id4275_n);
                tbl_JOIN_INNER_TD_3549486_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _customer_first_name4276_n);
                tbl_JOIN_INNER_TD_3549486_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _customer_last_name4277_n);
                tbl_JOIN_INNER_TD_3549486_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _customer_preferred_cust_flag4278_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3549486_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_3549486_output #Row: " << tbl_JOIN_INNER_TD_3549486_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2518178(Table &tbl_JOIN_INNER_TD_3549486_output, Table &tbl_Sort_TD_2518178_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(customer_id#4275 ASC NULLS FIRST, customer_first_name#4276 ASC NULLS FIRST, customer_last_name#4277 ASC NULLS FIRST, customer_preferred_cust_flag#4278 ASC NULLS FIRST)
    // Input: ListBuffer(customer_id#4275, customer_first_name#4276, customer_last_name#4277, customer_preferred_cust_flag#4278)
    // Output: ListBuffer(customer_id#4275, customer_first_name#4276, customer_last_name#4277, customer_preferred_cust_flag#4278)
    struct SW_Sort_TD_2518178Row {
        std::string _customer_id4275;
        std::string _customer_first_name4276;
        std::string _customer_last_name4277;
        std::string _customer_preferred_cust_flag4278;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2518178Row& a, const SW_Sort_TD_2518178Row& b) const { return 
 (a._customer_id4275 < b._customer_id4275) || 
 ((a._customer_id4275 == b._customer_id4275) && (a._customer_first_name4276 < b._customer_first_name4276)) || 
 ((a._customer_id4275 == b._customer_id4275) && (a._customer_first_name4276 == b._customer_first_name4276) && (a._customer_last_name4277 < b._customer_last_name4277)) || 
 ((a._customer_id4275 == b._customer_id4275) && (a._customer_first_name4276 == b._customer_first_name4276) && (a._customer_last_name4277 == b._customer_last_name4277) && (a._customer_preferred_cust_flag4278 < b._customer_preferred_cust_flag4278)); 
}
    }SW_Sort_TD_2518178_order; 

    int nrow1 = tbl_JOIN_INNER_TD_3549486_output.getNumRow();
    std::vector<SW_Sort_TD_2518178Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _customer_id4275 = tbl_JOIN_INNER_TD_3549486_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _customer_first_name4276 = tbl_JOIN_INNER_TD_3549486_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _customer_last_name4277 = tbl_JOIN_INNER_TD_3549486_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag4278 = tbl_JOIN_INNER_TD_3549486_output.getcharN<char, TPCDS_READ_MAX +1>(i, 3);
        SW_Sort_TD_2518178Row t = {std::string(_customer_id4275.data()),std::string(_customer_first_name4276.data()),std::string(_customer_last_name4277.data()),std::string(_customer_preferred_cust_flag4278.data())};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2518178_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _customer_id4275{};
        memcpy(_customer_id4275.data(), (it._customer_id4275).data(), (it._customer_id4275).length());
        tbl_Sort_TD_2518178_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _customer_id4275);
        std::array<char, TPCDS_READ_MAX + 1> _customer_first_name4276{};
        memcpy(_customer_first_name4276.data(), (it._customer_first_name4276).data(), (it._customer_first_name4276).length());
        tbl_Sort_TD_2518178_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _customer_first_name4276);
        std::array<char, TPCDS_READ_MAX + 1> _customer_last_name4277{};
        memcpy(_customer_last_name4277.data(), (it._customer_last_name4277).data(), (it._customer_last_name4277).length());
        tbl_Sort_TD_2518178_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _customer_last_name4277);
        std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag4278{};
        memcpy(_customer_preferred_cust_flag4278.data(), (it._customer_preferred_cust_flag4278).data(), (it._customer_preferred_cust_flag4278).length());
        tbl_Sort_TD_2518178_output.setcharN<char, TPCDS_READ_MAX +1>(r, 3, _customer_preferred_cust_flag4278);
        if (r < 10) {
            std::cout << (it._customer_id4275).data() << " " << (it._customer_first_name4276).data() << " " << (it._customer_last_name4277).data() << " " << (it._customer_preferred_cust_flag4278).data() << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_2518178_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2518178_output #Row: " << tbl_Sort_TD_2518178_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1827104(Table &tbl_Sort_TD_2518178_output, Table &tbl_LocalLimit_TD_1827104_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(customer_id#4275, customer_first_name#4276, customer_last_name#4277, customer_preferred_cust_flag#4278)
    // Output: ListBuffer(customer_id#4275, customer_first_name#4276, customer_last_name#4277, customer_preferred_cust_flag#4278)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _customer_id4275_n = tbl_Sort_TD_2518178_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1827104_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id4275_n);
        std::array<char, TPCDS_READ_MAX + 1> _customer_first_name4276_n = tbl_Sort_TD_2518178_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_1827104_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _customer_first_name4276_n);
        std::array<char, TPCDS_READ_MAX + 1> _customer_last_name4277_n = tbl_Sort_TD_2518178_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_LocalLimit_TD_1827104_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _customer_last_name4277_n);
        std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag4278_n = tbl_Sort_TD_2518178_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_LocalLimit_TD_1827104_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _customer_preferred_cust_flag4278_n);
        r++;
    }
    tbl_LocalLimit_TD_1827104_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1827104_output #Row: " << tbl_LocalLimit_TD_1827104_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_094744(Table &tbl_LocalLimit_TD_1827104_output, Table &tbl_GlobalLimit_TD_094744_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(customer_id#4275, customer_first_name#4276, customer_last_name#4277, customer_preferred_cust_flag#4278)
    // Output: ListBuffer(customer_id#4275, customer_first_name#4276, customer_last_name#4277, customer_preferred_cust_flag#4278)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _customer_id4275_n = tbl_LocalLimit_TD_1827104_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_094744_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _customer_id4275_n);
        std::array<char, TPCDS_READ_MAX + 1> _customer_first_name4276_n = tbl_LocalLimit_TD_1827104_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_094744_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _customer_first_name4276_n);
        std::array<char, TPCDS_READ_MAX + 1> _customer_last_name4277_n = tbl_LocalLimit_TD_1827104_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_GlobalLimit_TD_094744_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _customer_last_name4277_n);
        std::array<char, TPCDS_READ_MAX + 1> _customer_preferred_cust_flag4278_n = tbl_LocalLimit_TD_1827104_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_GlobalLimit_TD_094744_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _customer_preferred_cust_flag4278_n);
        r++;
    }
    tbl_GlobalLimit_TD_094744_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_094744_output #Row: " << tbl_GlobalLimit_TD_094744_output.getNumRow() << std::endl;
}

