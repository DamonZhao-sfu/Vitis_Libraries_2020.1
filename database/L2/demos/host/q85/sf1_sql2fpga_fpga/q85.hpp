#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_11321754(Table &tbl_SerializeFromObject_TD_12141188_input, Table &tbl_Filter_TD_11321754_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(wr_item_sk#833) AND isnotnull(wr_order_number#844L)) AND isnotnull(wr_refunded_cdemo_sk#835)) AND ((isnotnull(wr_returning_cdemo_sk#839) AND isnotnull(wr_refunded_addr_sk#837)) AND isnotnull(wr_reason_sk#843))))
    // Input: ListBuffer(wr_item_sk#833, wr_refunded_cdemo_sk#835, wr_refunded_addr_sk#837, wr_returning_cdemo_sk#839, wr_reason_sk#843, wr_order_number#844L, wr_fee#849, wr_refunded_cash#851)
    // Output: ListBuffer(wr_item_sk#833, wr_refunded_cdemo_sk#835, wr_refunded_addr_sk#837, wr_returning_cdemo_sk#839, wr_reason_sk#843, wr_order_number#844L, wr_fee#849, wr_refunded_cash#851)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12141188_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _wr_item_sk833 = tbl_SerializeFromObject_TD_12141188_input.getInt32(i, 0);
        int64_t _wr_order_number844L = tbl_SerializeFromObject_TD_12141188_input.getInt64(i, 5);
        int32_t _wr_refunded_cdemo_sk835 = tbl_SerializeFromObject_TD_12141188_input.getInt32(i, 1);
        int32_t _wr_returning_cdemo_sk839 = tbl_SerializeFromObject_TD_12141188_input.getInt32(i, 3);
        int32_t _wr_refunded_addr_sk837 = tbl_SerializeFromObject_TD_12141188_input.getInt32(i, 2);
        int32_t _wr_reason_sk843 = tbl_SerializeFromObject_TD_12141188_input.getInt32(i, 4);
        if ((((_wr_item_sk833!= 0) && (_wr_order_number844L!= 0)) && (_wr_refunded_cdemo_sk835!= 0)) && (((_wr_returning_cdemo_sk839!= 0) && (_wr_refunded_addr_sk837!= 0)) && (_wr_reason_sk843!= 0))) {
            int32_t _wr_item_sk833_t = tbl_SerializeFromObject_TD_12141188_input.getInt32(i, 0);
            tbl_Filter_TD_11321754_output.setInt32(r, 0, _wr_item_sk833_t);
            int32_t _wr_refunded_cdemo_sk835_t = tbl_SerializeFromObject_TD_12141188_input.getInt32(i, 1);
            tbl_Filter_TD_11321754_output.setInt32(r, 1, _wr_refunded_cdemo_sk835_t);
            int32_t _wr_refunded_addr_sk837_t = tbl_SerializeFromObject_TD_12141188_input.getInt32(i, 2);
            tbl_Filter_TD_11321754_output.setInt32(r, 2, _wr_refunded_addr_sk837_t);
            int32_t _wr_returning_cdemo_sk839_t = tbl_SerializeFromObject_TD_12141188_input.getInt32(i, 3);
            tbl_Filter_TD_11321754_output.setInt32(r, 3, _wr_returning_cdemo_sk839_t);
            int32_t _wr_reason_sk843_t = tbl_SerializeFromObject_TD_12141188_input.getInt32(i, 4);
            tbl_Filter_TD_11321754_output.setInt32(r, 4, _wr_reason_sk843_t);
            int64_t _wr_order_number844L_t = tbl_SerializeFromObject_TD_12141188_input.getInt64(i, 5);
            tbl_Filter_TD_11321754_output.setInt64(r, 5, _wr_order_number844L_t);
            int64_t _wr_fee849_t = tbl_SerializeFromObject_TD_12141188_input.getInt64(i, 6);
            tbl_Filter_TD_11321754_output.setInt64(r, 6, _wr_fee849_t);
            int64_t _wr_refunded_cash851_t = tbl_SerializeFromObject_TD_12141188_input.getInt64(i, 7);
            tbl_Filter_TD_11321754_output.setInt64(r, 7, _wr_refunded_cash851_t);
            r++;
        }
    }
    tbl_Filter_TD_11321754_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11321754_output #Row: " << tbl_Filter_TD_11321754_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11499683(Table &tbl_SerializeFromObject_TD_12744007_input, Table &tbl_Filter_TD_11499683_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(ws_item_sk#732) AND isnotnull(ws_order_number#746L)) AND isnotnull(ws_web_page_sk#741)) AND isnotnull(ws_sold_date_sk#729)))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_web_page_sk#741, ws_order_number#746L, ws_quantity#747)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_web_page_sk#741, ws_order_number#746L, ws_quantity#747)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12744007_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_item_sk732 = tbl_SerializeFromObject_TD_12744007_input.getInt32(i, 1);
        int64_t _ws_order_number746L = tbl_SerializeFromObject_TD_12744007_input.getInt64(i, 3);
        int32_t _ws_web_page_sk741 = tbl_SerializeFromObject_TD_12744007_input.getInt32(i, 2);
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_12744007_input.getInt32(i, 0);
        if ((((_ws_item_sk732!= 0) && (_ws_order_number746L!= 0)) && (_ws_web_page_sk741!= 0)) && (_ws_sold_date_sk729!= 0)) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_12744007_input.getInt32(i, 0);
            tbl_Filter_TD_11499683_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_item_sk732_t = tbl_SerializeFromObject_TD_12744007_input.getInt32(i, 1);
            tbl_Filter_TD_11499683_output.setInt32(r, 1, _ws_item_sk732_t);
            int32_t _ws_web_page_sk741_t = tbl_SerializeFromObject_TD_12744007_input.getInt32(i, 2);
            tbl_Filter_TD_11499683_output.setInt32(r, 2, _ws_web_page_sk741_t);
            int64_t _ws_order_number746L_t = tbl_SerializeFromObject_TD_12744007_input.getInt64(i, 3);
            tbl_Filter_TD_11499683_output.setInt64(r, 3, _ws_order_number746L_t);
            int32_t _ws_quantity747_t = tbl_SerializeFromObject_TD_12744007_input.getInt32(i, 4);
            tbl_Filter_TD_11499683_output.setInt32(r, 4, _ws_quantity747_t);
            r++;
        }
    }
    tbl_Filter_TD_11499683_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11499683_output #Row: " << tbl_Filter_TD_11499683_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10377597(Table &tbl_SerializeFromObject_TD_11468886_input, Table &tbl_Filter_TD_10377597_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(wp_web_page_sk#615))
    // Input: ListBuffer(wp_web_page_sk#615)
    // Output: ListBuffer(wp_web_page_sk#615)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11468886_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _wp_web_page_sk615 = tbl_SerializeFromObject_TD_11468886_input.getInt32(i, 0);
        if (_wp_web_page_sk615!= 0) {
            int32_t _wp_web_page_sk615_t = tbl_SerializeFromObject_TD_11468886_input.getInt32(i, 0);
            tbl_Filter_TD_10377597_output.setInt32(r, 0, _wp_web_page_sk615_t);
            r++;
        }
    }
    tbl_Filter_TD_10377597_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10377597_output #Row: " << tbl_Filter_TD_10377597_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_10650531_key_leftMajor {
    int32_t _ws_item_sk732;
    int64_t _ws_order_number746L;
    bool operator==(const SW_JOIN_INNER_TD_10650531_key_leftMajor& other) const {
        return ((_ws_item_sk732 == other._ws_item_sk732) && (_ws_order_number746L == other._ws_order_number746L));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10650531_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10650531_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_item_sk732)) + (hash<int64_t>()(k._ws_order_number746L));
    }
};
}
struct SW_JOIN_INNER_TD_10650531_payload_leftMajor {
    int32_t _ws_sold_date_sk729;
    int32_t _ws_item_sk732;
    int32_t _ws_web_page_sk741;
    int64_t _ws_order_number746L;
    int32_t _ws_quantity747;
};
struct SW_JOIN_INNER_TD_10650531_key_rightMajor {
    int32_t _wr_item_sk833;
    int64_t _wr_order_number844L;
    bool operator==(const SW_JOIN_INNER_TD_10650531_key_rightMajor& other) const {
        return ((_wr_item_sk833 == other._wr_item_sk833) && (_wr_order_number844L == other._wr_order_number844L));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10650531_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10650531_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._wr_item_sk833)) + (hash<int64_t>()(k._wr_order_number844L));
    }
};
}
struct SW_JOIN_INNER_TD_10650531_payload_rightMajor {
    int32_t _wr_item_sk833;
    int32_t _wr_refunded_cdemo_sk835;
    int32_t _wr_refunded_addr_sk837;
    int32_t _wr_returning_cdemo_sk839;
    int32_t _wr_reason_sk843;
    int64_t _wr_order_number844L;
    int64_t _wr_fee849;
    int64_t _wr_refunded_cash851;
};
void SW_JOIN_INNER_TD_10650531(Table &tbl_Filter_TD_11499683_output, Table &tbl_Filter_TD_11321754_output, Table &tbl_JOIN_INNER_TD_10650531_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((ws_item_sk#732 = wr_item_sk#833) AND (ws_order_number#746L = wr_order_number#844L)))
    // Left Table: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_web_page_sk#741, ws_order_number#746L, ws_quantity#747)
    // Right Table: ListBuffer(wr_item_sk#833, wr_refunded_cdemo_sk#835, wr_refunded_addr_sk#837, wr_returning_cdemo_sk#839, wr_reason_sk#843, wr_order_number#844L, wr_fee#849, wr_refunded_cash#851)
    // Output Table: ListBuffer(ws_sold_date_sk#729, ws_web_page_sk#741, ws_quantity#747, wr_refunded_cdemo_sk#835, wr_refunded_addr_sk#837, wr_returning_cdemo_sk#839, wr_reason_sk#843, wr_fee#849, wr_refunded_cash#851)
    int left_nrow = tbl_Filter_TD_11499683_output.getNumRow();
    int right_nrow = tbl_Filter_TD_11321754_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10650531_key_leftMajor, SW_JOIN_INNER_TD_10650531_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_11499683_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_item_sk732_k = tbl_Filter_TD_11499683_output.getInt32(i, 1);
            int64_t _ws_order_number746L_k = tbl_Filter_TD_11499683_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_10650531_key_leftMajor keyA{_ws_item_sk732_k, _ws_order_number746L_k};
            int32_t _ws_sold_date_sk729 = tbl_Filter_TD_11499683_output.getInt32(i, 0);
            int32_t _ws_item_sk732 = tbl_Filter_TD_11499683_output.getInt32(i, 1);
            int32_t _ws_web_page_sk741 = tbl_Filter_TD_11499683_output.getInt32(i, 2);
            int64_t _ws_order_number746L = tbl_Filter_TD_11499683_output.getInt64(i, 3);
            int32_t _ws_quantity747 = tbl_Filter_TD_11499683_output.getInt32(i, 4);
            SW_JOIN_INNER_TD_10650531_payload_leftMajor payloadA{_ws_sold_date_sk729, _ws_item_sk732, _ws_web_page_sk741, _ws_order_number746L, _ws_quantity747};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_11321754_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _wr_item_sk833_k = tbl_Filter_TD_11321754_output.getInt32(i, 0);
            int64_t _wr_order_number844L_k = tbl_Filter_TD_11321754_output.getInt64(i, 5);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10650531_key_leftMajor{_wr_item_sk833_k, _wr_order_number844L_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_date_sk729 = (it->second)._ws_sold_date_sk729;
                int32_t _ws_item_sk732 = (it->second)._ws_item_sk732;
                int32_t _ws_web_page_sk741 = (it->second)._ws_web_page_sk741;
                int64_t _ws_order_number746L = (it->second)._ws_order_number746L;
                int32_t _ws_quantity747 = (it->second)._ws_quantity747;
                int32_t _wr_item_sk833 = tbl_Filter_TD_11321754_output.getInt32(i, 0);
                int32_t _wr_refunded_cdemo_sk835 = tbl_Filter_TD_11321754_output.getInt32(i, 1);
                int32_t _wr_refunded_addr_sk837 = tbl_Filter_TD_11321754_output.getInt32(i, 2);
                int32_t _wr_returning_cdemo_sk839 = tbl_Filter_TD_11321754_output.getInt32(i, 3);
                int32_t _wr_reason_sk843 = tbl_Filter_TD_11321754_output.getInt32(i, 4);
                int64_t _wr_order_number844L = tbl_Filter_TD_11321754_output.getInt64(i, 5);
                int64_t _wr_fee849 = tbl_Filter_TD_11321754_output.getInt64(i, 6);
                int64_t _wr_refunded_cash851 = tbl_Filter_TD_11321754_output.getInt64(i, 7);
                tbl_JOIN_INNER_TD_10650531_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_10650531_output.setInt32(r, 1, _ws_web_page_sk741);
                tbl_JOIN_INNER_TD_10650531_output.setInt32(r, 2, _ws_quantity747);
                tbl_JOIN_INNER_TD_10650531_output.setInt32(r, 3, _wr_refunded_cdemo_sk835);
                tbl_JOIN_INNER_TD_10650531_output.setInt32(r, 4, _wr_refunded_addr_sk837);
                tbl_JOIN_INNER_TD_10650531_output.setInt32(r, 5, _wr_returning_cdemo_sk839);
                tbl_JOIN_INNER_TD_10650531_output.setInt32(r, 6, _wr_reason_sk843);
                tbl_JOIN_INNER_TD_10650531_output.setInt64(r, 7, _wr_fee849);
                tbl_JOIN_INNER_TD_10650531_output.setInt64(r, 8, _wr_refunded_cash851);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10650531_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10650531_key_rightMajor, SW_JOIN_INNER_TD_10650531_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_11321754_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _wr_item_sk833_k = tbl_Filter_TD_11321754_output.getInt32(i, 0);
            int64_t _wr_order_number844L_k = tbl_Filter_TD_11321754_output.getInt64(i, 5);
            SW_JOIN_INNER_TD_10650531_key_rightMajor keyA{_wr_item_sk833_k, _wr_order_number844L_k};
            int32_t _wr_item_sk833 = tbl_Filter_TD_11321754_output.getInt32(i, 0);
            int32_t _wr_refunded_cdemo_sk835 = tbl_Filter_TD_11321754_output.getInt32(i, 1);
            int32_t _wr_refunded_addr_sk837 = tbl_Filter_TD_11321754_output.getInt32(i, 2);
            int32_t _wr_returning_cdemo_sk839 = tbl_Filter_TD_11321754_output.getInt32(i, 3);
            int32_t _wr_reason_sk843 = tbl_Filter_TD_11321754_output.getInt32(i, 4);
            int64_t _wr_order_number844L = tbl_Filter_TD_11321754_output.getInt64(i, 5);
            int64_t _wr_fee849 = tbl_Filter_TD_11321754_output.getInt64(i, 6);
            int64_t _wr_refunded_cash851 = tbl_Filter_TD_11321754_output.getInt64(i, 7);
            SW_JOIN_INNER_TD_10650531_payload_rightMajor payloadA{_wr_item_sk833, _wr_refunded_cdemo_sk835, _wr_refunded_addr_sk837, _wr_returning_cdemo_sk839, _wr_reason_sk843, _wr_order_number844L, _wr_fee849, _wr_refunded_cash851};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_11499683_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_item_sk732_k = tbl_Filter_TD_11499683_output.getInt32(i, 1);
            int64_t _ws_order_number746L_k = tbl_Filter_TD_11499683_output.getInt64(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10650531_key_rightMajor{_ws_item_sk732_k, _ws_order_number746L_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _wr_item_sk833 = (it->second)._wr_item_sk833;
                int32_t _wr_refunded_cdemo_sk835 = (it->second)._wr_refunded_cdemo_sk835;
                int32_t _wr_refunded_addr_sk837 = (it->second)._wr_refunded_addr_sk837;
                int32_t _wr_returning_cdemo_sk839 = (it->second)._wr_returning_cdemo_sk839;
                int32_t _wr_reason_sk843 = (it->second)._wr_reason_sk843;
                int64_t _wr_order_number844L = (it->second)._wr_order_number844L;
                int64_t _wr_fee849 = (it->second)._wr_fee849;
                int64_t _wr_refunded_cash851 = (it->second)._wr_refunded_cash851;
                int32_t _ws_sold_date_sk729 = tbl_Filter_TD_11499683_output.getInt32(i, 0);
                int32_t _ws_item_sk732 = tbl_Filter_TD_11499683_output.getInt32(i, 1);
                int32_t _ws_web_page_sk741 = tbl_Filter_TD_11499683_output.getInt32(i, 2);
                int64_t _ws_order_number746L = tbl_Filter_TD_11499683_output.getInt64(i, 3);
                int32_t _ws_quantity747 = tbl_Filter_TD_11499683_output.getInt32(i, 4);
                tbl_JOIN_INNER_TD_10650531_output.setInt32(r, 3, _wr_refunded_cdemo_sk835);
                tbl_JOIN_INNER_TD_10650531_output.setInt32(r, 4, _wr_refunded_addr_sk837);
                tbl_JOIN_INNER_TD_10650531_output.setInt32(r, 5, _wr_returning_cdemo_sk839);
                tbl_JOIN_INNER_TD_10650531_output.setInt32(r, 6, _wr_reason_sk843);
                tbl_JOIN_INNER_TD_10650531_output.setInt64(r, 7, _wr_fee849);
                tbl_JOIN_INNER_TD_10650531_output.setInt64(r, 8, _wr_refunded_cash851);
                tbl_JOIN_INNER_TD_10650531_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_10650531_output.setInt32(r, 1, _ws_web_page_sk741);
                tbl_JOIN_INNER_TD_10650531_output.setInt32(r, 2, _ws_quantity747);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10650531_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_10650531_output #Row: " << tbl_JOIN_INNER_TD_10650531_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9582973(Table &tbl_SerializeFromObject_TD_10827303_input, Table &tbl_Filter_TD_9582973_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((((((cd_marital_status#95 = M) AND (cd_education_status#96 = Advanced Degree)) OR ((cd_marital_status#95 = S) AND (cd_education_status#96 = College))) OR ((cd_marital_status#95 = W) AND (cd_education_status#96 = 2 yr Degree))) AND isnotnull(cd_demo_sk#93)) AND (isnotnull(cd_marital_status#95) AND isnotnull(cd_education_status#96))))
    // Input: ListBuffer(cd_demo_sk#93, cd_marital_status#95, cd_education_status#96)
    // Output: ListBuffer(cd_demo_sk#93, cd_marital_status#95, cd_education_status#96)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10827303_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95 = tbl_SerializeFromObject_TD_10827303_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96 = tbl_SerializeFromObject_TD_10827303_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        int32_t _cd_demo_sk93 = tbl_SerializeFromObject_TD_10827303_input.getInt32(i, 0);
        if ((((((std::string(_cd_marital_status95.data()) == "M") && (std::string(_cd_education_status96.data()) == "Advanced Degree")) || ((std::string(_cd_marital_status95.data()) == "S") && (std::string(_cd_education_status96.data()) == "College"))) || ((std::string(_cd_marital_status95.data()) == "W") && (std::string(_cd_education_status96.data()) == "2 yr Degree"))) && (_cd_demo_sk93!= 0)) && ((_cd_marital_status95.data() != "NULL") && (_cd_education_status96.data() != "NULL"))) {
            int32_t _cd_demo_sk93_t = tbl_SerializeFromObject_TD_10827303_input.getInt32(i, 0);
            tbl_Filter_TD_9582973_output.setInt32(r, 0, _cd_demo_sk93_t);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_t = tbl_SerializeFromObject_TD_10827303_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_9582973_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cd_marital_status95_t);
            std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_t = tbl_SerializeFromObject_TD_10827303_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_9582973_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cd_education_status96_t);
            r++;
        }
    }
    tbl_Filter_TD_9582973_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9582973_output #Row: " << tbl_Filter_TD_9582973_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_9304127_key_leftMajor {
    int32_t _ws_web_page_sk741;
    bool operator==(const SW_JOIN_INNER_TD_9304127_key_leftMajor& other) const {
        return ((_ws_web_page_sk741 == other._ws_web_page_sk741));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9304127_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9304127_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_web_page_sk741));
    }
};
}
struct SW_JOIN_INNER_TD_9304127_payload_leftMajor {
    int32_t _ws_sold_date_sk729;
    int32_t _ws_web_page_sk741;
    int32_t _ws_quantity747;
    int32_t _wr_refunded_cdemo_sk835;
    int32_t _wr_refunded_addr_sk837;
    int32_t _wr_returning_cdemo_sk839;
    int32_t _wr_reason_sk843;
    int64_t _wr_fee849;
    int64_t _wr_refunded_cash851;
};
struct SW_JOIN_INNER_TD_9304127_key_rightMajor {
    int32_t _wp_web_page_sk615;
    bool operator==(const SW_JOIN_INNER_TD_9304127_key_rightMajor& other) const {
        return ((_wp_web_page_sk615 == other._wp_web_page_sk615));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9304127_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9304127_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._wp_web_page_sk615));
    }
};
}
struct SW_JOIN_INNER_TD_9304127_payload_rightMajor {
    int32_t _wp_web_page_sk615;
};
void SW_JOIN_INNER_TD_9304127(Table &tbl_JOIN_INNER_TD_10650531_output, Table &tbl_Filter_TD_10377597_output, Table &tbl_JOIN_INNER_TD_9304127_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_web_page_sk#741 = wp_web_page_sk#615))
    // Left Table: ListBuffer(ws_sold_date_sk#729, ws_web_page_sk#741, ws_quantity#747, wr_refunded_cdemo_sk#835, wr_refunded_addr_sk#837, wr_returning_cdemo_sk#839, wr_reason_sk#843, wr_fee#849, wr_refunded_cash#851)
    // Right Table: ListBuffer(wp_web_page_sk#615)
    // Output Table: ListBuffer(ws_sold_date_sk#729, ws_quantity#747, wr_refunded_cdemo_sk#835, wr_refunded_addr_sk#837, wr_returning_cdemo_sk#839, wr_reason_sk#843, wr_fee#849, wr_refunded_cash#851)
    int left_nrow = tbl_JOIN_INNER_TD_10650531_output.getNumRow();
    int right_nrow = tbl_Filter_TD_10377597_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9304127_key_leftMajor, SW_JOIN_INNER_TD_9304127_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_10650531_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_web_page_sk741_k = tbl_JOIN_INNER_TD_10650531_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_9304127_key_leftMajor keyA{_ws_web_page_sk741_k};
            int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_10650531_output.getInt32(i, 0);
            int32_t _ws_web_page_sk741 = tbl_JOIN_INNER_TD_10650531_output.getInt32(i, 1);
            int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_10650531_output.getInt32(i, 2);
            int32_t _wr_refunded_cdemo_sk835 = tbl_JOIN_INNER_TD_10650531_output.getInt32(i, 3);
            int32_t _wr_refunded_addr_sk837 = tbl_JOIN_INNER_TD_10650531_output.getInt32(i, 4);
            int32_t _wr_returning_cdemo_sk839 = tbl_JOIN_INNER_TD_10650531_output.getInt32(i, 5);
            int32_t _wr_reason_sk843 = tbl_JOIN_INNER_TD_10650531_output.getInt32(i, 6);
            int64_t _wr_fee849 = tbl_JOIN_INNER_TD_10650531_output.getInt64(i, 7);
            int64_t _wr_refunded_cash851 = tbl_JOIN_INNER_TD_10650531_output.getInt64(i, 8);
            SW_JOIN_INNER_TD_9304127_payload_leftMajor payloadA{_ws_sold_date_sk729, _ws_web_page_sk741, _ws_quantity747, _wr_refunded_cdemo_sk835, _wr_refunded_addr_sk837, _wr_returning_cdemo_sk839, _wr_reason_sk843, _wr_fee849, _wr_refunded_cash851};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_10377597_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _wp_web_page_sk615_k = tbl_Filter_TD_10377597_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9304127_key_leftMajor{_wp_web_page_sk615_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_date_sk729 = (it->second)._ws_sold_date_sk729;
                int32_t _ws_web_page_sk741 = (it->second)._ws_web_page_sk741;
                int32_t _ws_quantity747 = (it->second)._ws_quantity747;
                int32_t _wr_refunded_cdemo_sk835 = (it->second)._wr_refunded_cdemo_sk835;
                int32_t _wr_refunded_addr_sk837 = (it->second)._wr_refunded_addr_sk837;
                int32_t _wr_returning_cdemo_sk839 = (it->second)._wr_returning_cdemo_sk839;
                int32_t _wr_reason_sk843 = (it->second)._wr_reason_sk843;
                int64_t _wr_fee849 = (it->second)._wr_fee849;
                int64_t _wr_refunded_cash851 = (it->second)._wr_refunded_cash851;
                int32_t _wp_web_page_sk615 = tbl_Filter_TD_10377597_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_9304127_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_9304127_output.setInt32(r, 1, _ws_quantity747);
                tbl_JOIN_INNER_TD_9304127_output.setInt32(r, 2, _wr_refunded_cdemo_sk835);
                tbl_JOIN_INNER_TD_9304127_output.setInt32(r, 3, _wr_refunded_addr_sk837);
                tbl_JOIN_INNER_TD_9304127_output.setInt32(r, 4, _wr_returning_cdemo_sk839);
                tbl_JOIN_INNER_TD_9304127_output.setInt32(r, 5, _wr_reason_sk843);
                tbl_JOIN_INNER_TD_9304127_output.setInt64(r, 6, _wr_fee849);
                tbl_JOIN_INNER_TD_9304127_output.setInt64(r, 7, _wr_refunded_cash851);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9304127_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9304127_key_rightMajor, SW_JOIN_INNER_TD_9304127_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_10377597_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _wp_web_page_sk615_k = tbl_Filter_TD_10377597_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_9304127_key_rightMajor keyA{_wp_web_page_sk615_k};
            int32_t _wp_web_page_sk615 = tbl_Filter_TD_10377597_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_9304127_payload_rightMajor payloadA{_wp_web_page_sk615};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_10650531_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_web_page_sk741_k = tbl_JOIN_INNER_TD_10650531_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9304127_key_rightMajor{_ws_web_page_sk741_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _wp_web_page_sk615 = (it->second)._wp_web_page_sk615;
                int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_10650531_output.getInt32(i, 0);
                int32_t _ws_web_page_sk741 = tbl_JOIN_INNER_TD_10650531_output.getInt32(i, 1);
                int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_10650531_output.getInt32(i, 2);
                int32_t _wr_refunded_cdemo_sk835 = tbl_JOIN_INNER_TD_10650531_output.getInt32(i, 3);
                int32_t _wr_refunded_addr_sk837 = tbl_JOIN_INNER_TD_10650531_output.getInt32(i, 4);
                int32_t _wr_returning_cdemo_sk839 = tbl_JOIN_INNER_TD_10650531_output.getInt32(i, 5);
                int32_t _wr_reason_sk843 = tbl_JOIN_INNER_TD_10650531_output.getInt32(i, 6);
                int64_t _wr_fee849 = tbl_JOIN_INNER_TD_10650531_output.getInt64(i, 7);
                int64_t _wr_refunded_cash851 = tbl_JOIN_INNER_TD_10650531_output.getInt64(i, 8);
                tbl_JOIN_INNER_TD_9304127_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_9304127_output.setInt32(r, 1, _ws_quantity747);
                tbl_JOIN_INNER_TD_9304127_output.setInt32(r, 2, _wr_refunded_cdemo_sk835);
                tbl_JOIN_INNER_TD_9304127_output.setInt32(r, 3, _wr_refunded_addr_sk837);
                tbl_JOIN_INNER_TD_9304127_output.setInt32(r, 4, _wr_returning_cdemo_sk839);
                tbl_JOIN_INNER_TD_9304127_output.setInt32(r, 5, _wr_reason_sk843);
                tbl_JOIN_INNER_TD_9304127_output.setInt64(r, 6, _wr_fee849);
                tbl_JOIN_INNER_TD_9304127_output.setInt64(r, 7, _wr_refunded_cash851);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9304127_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_9304127_output #Row: " << tbl_JOIN_INNER_TD_9304127_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8713280(Table &tbl_SerializeFromObject_TD_9898241_input, Table &tbl_Filter_TD_8713280_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(cd_demo_sk#3591) AND isnotnull(cd_marital_status#3593)) AND isnotnull(cd_education_status#3594)))
    // Input: ListBuffer(cd_demo_sk#3591, cd_marital_status#3593, cd_education_status#3594)
    // Output: ListBuffer(cd_demo_sk#3591, cd_marital_status#3593, cd_education_status#3594)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9898241_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cd_demo_sk3591 = tbl_SerializeFromObject_TD_9898241_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status3593 = tbl_SerializeFromObject_TD_9898241_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _cd_education_status3594 = tbl_SerializeFromObject_TD_9898241_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        if (((_cd_demo_sk3591!= 0) && (_cd_marital_status3593.data() != "NULL")) && (_cd_education_status3594.data() != "NULL")) {
            int32_t _cd_demo_sk3591_t = tbl_SerializeFromObject_TD_9898241_input.getInt32(i, 0);
            tbl_Filter_TD_8713280_output.setInt32(r, 0, _cd_demo_sk3591_t);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status3593_t = tbl_SerializeFromObject_TD_9898241_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_8713280_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cd_marital_status3593_t);
            std::array<char, TPCDS_READ_MAX + 1> _cd_education_status3594_t = tbl_SerializeFromObject_TD_9898241_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_8713280_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _cd_education_status3594_t);
            r++;
        }
    }
    tbl_Filter_TD_8713280_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8713280_output #Row: " << tbl_Filter_TD_8713280_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8871642_key_leftMajor {
    int32_t _wr_refunded_cdemo_sk835;
    bool operator==(const SW_JOIN_INNER_TD_8871642_key_leftMajor& other) const {
        return ((_wr_refunded_cdemo_sk835 == other._wr_refunded_cdemo_sk835));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8871642_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8871642_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._wr_refunded_cdemo_sk835));
    }
};
}
struct SW_JOIN_INNER_TD_8871642_payload_leftMajor {
    int32_t _ws_sold_date_sk729;
    int32_t _ws_quantity747;
    int32_t _wr_refunded_cdemo_sk835;
    int32_t _wr_refunded_addr_sk837;
    int32_t _wr_returning_cdemo_sk839;
    int32_t _wr_reason_sk843;
    int64_t _wr_fee849;
    int64_t _wr_refunded_cash851;
};
struct SW_JOIN_INNER_TD_8871642_key_rightMajor {
    int32_t _cd_demo_sk93;
    bool operator==(const SW_JOIN_INNER_TD_8871642_key_rightMajor& other) const {
        return ((_cd_demo_sk93 == other._cd_demo_sk93));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8871642_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8871642_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cd_demo_sk93));
    }
};
}
struct SW_JOIN_INNER_TD_8871642_payload_rightMajor {
    int32_t _cd_demo_sk93;
    std::string _cd_marital_status95;
    std::string _cd_education_status96;
};
void SW_JOIN_INNER_TD_8871642(Table &tbl_JOIN_INNER_TD_9304127_output, Table &tbl_Filter_TD_9582973_output, Table &tbl_JOIN_INNER_TD_8871642_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cd_demo_sk#93 = wr_refunded_cdemo_sk#835))
    // Left Table: ListBuffer(ws_sold_date_sk#729, ws_quantity#747, wr_refunded_cdemo_sk#835, wr_refunded_addr_sk#837, wr_returning_cdemo_sk#839, wr_reason_sk#843, wr_fee#849, wr_refunded_cash#851)
    // Right Table: ListBuffer(cd_demo_sk#93, cd_marital_status#95, cd_education_status#96)
    // Output Table: ListBuffer(ws_sold_date_sk#729, ws_quantity#747, wr_refunded_addr_sk#837, wr_returning_cdemo_sk#839, wr_reason_sk#843, wr_fee#849, wr_refunded_cash#851, cd_marital_status#95, cd_education_status#96)
    int left_nrow = tbl_JOIN_INNER_TD_9304127_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9582973_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8871642_key_leftMajor, SW_JOIN_INNER_TD_8871642_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_9304127_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _wr_refunded_cdemo_sk835_k = tbl_JOIN_INNER_TD_9304127_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_8871642_key_leftMajor keyA{_wr_refunded_cdemo_sk835_k};
            int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_9304127_output.getInt32(i, 0);
            int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_9304127_output.getInt32(i, 1);
            int32_t _wr_refunded_cdemo_sk835 = tbl_JOIN_INNER_TD_9304127_output.getInt32(i, 2);
            int32_t _wr_refunded_addr_sk837 = tbl_JOIN_INNER_TD_9304127_output.getInt32(i, 3);
            int32_t _wr_returning_cdemo_sk839 = tbl_JOIN_INNER_TD_9304127_output.getInt32(i, 4);
            int32_t _wr_reason_sk843 = tbl_JOIN_INNER_TD_9304127_output.getInt32(i, 5);
            int64_t _wr_fee849 = tbl_JOIN_INNER_TD_9304127_output.getInt64(i, 6);
            int64_t _wr_refunded_cash851 = tbl_JOIN_INNER_TD_9304127_output.getInt64(i, 7);
            SW_JOIN_INNER_TD_8871642_payload_leftMajor payloadA{_ws_sold_date_sk729, _ws_quantity747, _wr_refunded_cdemo_sk835, _wr_refunded_addr_sk837, _wr_returning_cdemo_sk839, _wr_reason_sk843, _wr_fee849, _wr_refunded_cash851};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9582973_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cd_demo_sk93_k = tbl_Filter_TD_9582973_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8871642_key_leftMajor{_cd_demo_sk93_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_date_sk729 = (it->second)._ws_sold_date_sk729;
                int32_t _ws_quantity747 = (it->second)._ws_quantity747;
                int32_t _wr_refunded_cdemo_sk835 = (it->second)._wr_refunded_cdemo_sk835;
                int32_t _wr_refunded_addr_sk837 = (it->second)._wr_refunded_addr_sk837;
                int32_t _wr_returning_cdemo_sk839 = (it->second)._wr_returning_cdemo_sk839;
                int32_t _wr_reason_sk843 = (it->second)._wr_reason_sk843;
                int64_t _wr_fee849 = (it->second)._wr_fee849;
                int64_t _wr_refunded_cash851 = (it->second)._wr_refunded_cash851;
                int32_t _cd_demo_sk93 = tbl_Filter_TD_9582973_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n = tbl_Filter_TD_9582973_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _cd_marital_status95 = std::string(_cd_marital_status95_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_n = tbl_Filter_TD_9582973_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _cd_education_status96 = std::string(_cd_education_status96_n.data());
                tbl_JOIN_INNER_TD_8871642_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_8871642_output.setInt32(r, 1, _ws_quantity747);
                tbl_JOIN_INNER_TD_8871642_output.setInt32(r, 2, _wr_refunded_addr_sk837);
                tbl_JOIN_INNER_TD_8871642_output.setInt32(r, 3, _wr_returning_cdemo_sk839);
                tbl_JOIN_INNER_TD_8871642_output.setInt32(r, 4, _wr_reason_sk843);
                tbl_JOIN_INNER_TD_8871642_output.setInt64(r, 5, _wr_fee849);
                tbl_JOIN_INNER_TD_8871642_output.setInt64(r, 6, _wr_refunded_cash851);
                tbl_JOIN_INNER_TD_8871642_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _cd_marital_status95_n);
                tbl_JOIN_INNER_TD_8871642_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _cd_education_status96_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8871642_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8871642_key_rightMajor, SW_JOIN_INNER_TD_8871642_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9582973_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cd_demo_sk93_k = tbl_Filter_TD_9582973_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8871642_key_rightMajor keyA{_cd_demo_sk93_k};
            int32_t _cd_demo_sk93 = tbl_Filter_TD_9582973_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n = tbl_Filter_TD_9582973_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cd_marital_status95 = std::string(_cd_marital_status95_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_n = tbl_Filter_TD_9582973_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _cd_education_status96 = std::string(_cd_education_status96_n.data());
            SW_JOIN_INNER_TD_8871642_payload_rightMajor payloadA{_cd_demo_sk93, _cd_marital_status95, _cd_education_status96};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_9304127_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _wr_refunded_cdemo_sk835_k = tbl_JOIN_INNER_TD_9304127_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8871642_key_rightMajor{_wr_refunded_cdemo_sk835_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cd_demo_sk93 = (it->second)._cd_demo_sk93;
                std::string _cd_marital_status95 = (it->second)._cd_marital_status95;
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n{};
                memcpy(_cd_marital_status95_n.data(), (_cd_marital_status95).data(), (_cd_marital_status95).length());
                std::string _cd_education_status96 = (it->second)._cd_education_status96;
                std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_n{};
                memcpy(_cd_education_status96_n.data(), (_cd_education_status96).data(), (_cd_education_status96).length());
                int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_9304127_output.getInt32(i, 0);
                int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_9304127_output.getInt32(i, 1);
                int32_t _wr_refunded_cdemo_sk835 = tbl_JOIN_INNER_TD_9304127_output.getInt32(i, 2);
                int32_t _wr_refunded_addr_sk837 = tbl_JOIN_INNER_TD_9304127_output.getInt32(i, 3);
                int32_t _wr_returning_cdemo_sk839 = tbl_JOIN_INNER_TD_9304127_output.getInt32(i, 4);
                int32_t _wr_reason_sk843 = tbl_JOIN_INNER_TD_9304127_output.getInt32(i, 5);
                int64_t _wr_fee849 = tbl_JOIN_INNER_TD_9304127_output.getInt64(i, 6);
                int64_t _wr_refunded_cash851 = tbl_JOIN_INNER_TD_9304127_output.getInt64(i, 7);
                tbl_JOIN_INNER_TD_8871642_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _cd_marital_status95_n);
                tbl_JOIN_INNER_TD_8871642_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _cd_education_status96_n);
                tbl_JOIN_INNER_TD_8871642_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_8871642_output.setInt32(r, 1, _ws_quantity747);
                tbl_JOIN_INNER_TD_8871642_output.setInt32(r, 2, _wr_refunded_addr_sk837);
                tbl_JOIN_INNER_TD_8871642_output.setInt32(r, 3, _wr_returning_cdemo_sk839);
                tbl_JOIN_INNER_TD_8871642_output.setInt32(r, 4, _wr_reason_sk843);
                tbl_JOIN_INNER_TD_8871642_output.setInt64(r, 5, _wr_fee849);
                tbl_JOIN_INNER_TD_8871642_output.setInt64(r, 6, _wr_refunded_cash851);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8871642_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8871642_output #Row: " << tbl_JOIN_INNER_TD_8871642_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7544516(Table &tbl_SerializeFromObject_TD_8220681_input, Table &tbl_Filter_TD_7544516_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ca_country#64) AND ((ca_country#64 = United States) AND ((ca_state#62 IN (IN,OH,NJ) OR ca_state#62 IN (WI,CT,KY)) OR ca_state#62 IN (LA,IA,AR)))) AND isnotnull(ca_address_sk#54)))
    // Input: ListBuffer(ca_address_sk#54, ca_country#64, ca_state#62)
    // Output: ListBuffer(ca_address_sk#54)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8220681_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_country64 = tbl_SerializeFromObject_TD_8220681_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _ca_state62 = tbl_SerializeFromObject_TD_8220681_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        int32_t _ca_address_sk54 = tbl_SerializeFromObject_TD_8220681_input.getInt32(i, 0);
        auto reuse_col_str_355 = std::string(_ca_state62.data());
        auto reuse_col_str_401 = std::string(_ca_state62.data());
        auto reuse_col_str_200 = std::string(_ca_state62.data());
        if (((_ca_country64.data() != "NULL") && ((std::string(_ca_country64.data()) == "United States") && ((((reuse_col_str_355 == "IN") || (reuse_col_str_355 == "OH") || (reuse_col_str_355 == "NJ") || (0)) || ((reuse_col_str_401 == "WI") || (reuse_col_str_401 == "CT") || (reuse_col_str_401 == "KY") || (0))) || ((reuse_col_str_200 == "LA") || (reuse_col_str_200 == "IA") || (reuse_col_str_200 == "AR") || (0))))) && (_ca_address_sk54!= 0)) {
            int32_t _ca_address_sk54_t = tbl_SerializeFromObject_TD_8220681_input.getInt32(i, 0);
            tbl_Filter_TD_7544516_output.setInt32(r, 0, _ca_address_sk54_t);
            r++;
        }
    }
    tbl_Filter_TD_7544516_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7544516_output #Row: " << tbl_Filter_TD_7544516_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_7458932_key_leftMajor {
    int32_t _wr_returning_cdemo_sk839;
    std::string _cd_marital_status95;
    std::string _cd_education_status96;
    bool operator==(const SW_JOIN_INNER_TD_7458932_key_leftMajor& other) const {
        return ((_wr_returning_cdemo_sk839 == other._wr_returning_cdemo_sk839) && (_cd_marital_status95 == other._cd_marital_status95) && (_cd_education_status96 == other._cd_education_status96));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7458932_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7458932_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._wr_returning_cdemo_sk839)) + (hash<string>()(k._cd_marital_status95)) + (hash<string>()(k._cd_education_status96));
    }
};
}
struct SW_JOIN_INNER_TD_7458932_payload_leftMajor {
    int32_t _ws_sold_date_sk729;
    int32_t _ws_quantity747;
    int32_t _wr_refunded_addr_sk837;
    int32_t _wr_returning_cdemo_sk839;
    int32_t _wr_reason_sk843;
    int64_t _wr_fee849;
    int64_t _wr_refunded_cash851;
    std::string _cd_marital_status95;
    std::string _cd_education_status96;
};
struct SW_JOIN_INNER_TD_7458932_key_rightMajor {
    int32_t _cd_demo_sk3591;
    std::string _cd_marital_status3593;
    std::string _cd_education_status3594;
    bool operator==(const SW_JOIN_INNER_TD_7458932_key_rightMajor& other) const {
        return ((_cd_demo_sk3591 == other._cd_demo_sk3591) && (_cd_marital_status3593 == other._cd_marital_status3593) && (_cd_education_status3594 == other._cd_education_status3594));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7458932_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7458932_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cd_demo_sk3591)) + (hash<string>()(k._cd_marital_status3593)) + (hash<string>()(k._cd_education_status3594));
    }
};
}
struct SW_JOIN_INNER_TD_7458932_payload_rightMajor {
    int32_t _cd_demo_sk3591;
    std::string _cd_marital_status3593;
    std::string _cd_education_status3594;
};
void SW_JOIN_INNER_TD_7458932(Table &tbl_JOIN_INNER_TD_8871642_output, Table &tbl_Filter_TD_8713280_output, Table &tbl_JOIN_INNER_TD_7458932_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((((cd_demo_sk#3591 = wr_returning_cdemo_sk#839) AND (cd_marital_status#95 = cd_marital_status#3593)) AND (cd_education_status#96 = cd_education_status#3594)))
    // Left Table: ListBuffer(ws_sold_date_sk#729, ws_quantity#747, wr_refunded_addr_sk#837, wr_returning_cdemo_sk#839, wr_reason_sk#843, wr_fee#849, wr_refunded_cash#851, cd_marital_status#95, cd_education_status#96)
    // Right Table: ListBuffer(cd_demo_sk#3591, cd_marital_status#3593, cd_education_status#3594)
    // Output Table: ListBuffer(ws_sold_date_sk#729, ws_quantity#747, wr_refunded_addr_sk#837, wr_reason_sk#843, wr_fee#849, wr_refunded_cash#851)
    int left_nrow = tbl_JOIN_INNER_TD_8871642_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8713280_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7458932_key_leftMajor, SW_JOIN_INNER_TD_7458932_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_8871642_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _wr_returning_cdemo_sk839_k = tbl_JOIN_INNER_TD_8871642_output.getInt32(i, 3);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_k_n = tbl_JOIN_INNER_TD_8871642_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _cd_marital_status95_k = std::string(_cd_marital_status95_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_k_n = tbl_JOIN_INNER_TD_8871642_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
            std::string _cd_education_status96_k = std::string(_cd_education_status96_k_n.data());
            SW_JOIN_INNER_TD_7458932_key_leftMajor keyA{_wr_returning_cdemo_sk839_k, _cd_marital_status95_k, _cd_education_status96_k};
            int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_8871642_output.getInt32(i, 0);
            int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_8871642_output.getInt32(i, 1);
            int32_t _wr_refunded_addr_sk837 = tbl_JOIN_INNER_TD_8871642_output.getInt32(i, 2);
            int32_t _wr_returning_cdemo_sk839 = tbl_JOIN_INNER_TD_8871642_output.getInt32(i, 3);
            int32_t _wr_reason_sk843 = tbl_JOIN_INNER_TD_8871642_output.getInt32(i, 4);
            int64_t _wr_fee849 = tbl_JOIN_INNER_TD_8871642_output.getInt64(i, 5);
            int64_t _wr_refunded_cash851 = tbl_JOIN_INNER_TD_8871642_output.getInt64(i, 6);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n = tbl_JOIN_INNER_TD_8871642_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _cd_marital_status95 = std::string(_cd_marital_status95_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_n = tbl_JOIN_INNER_TD_8871642_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
            std::string _cd_education_status96 = std::string(_cd_education_status96_n.data());
            SW_JOIN_INNER_TD_7458932_payload_leftMajor payloadA{_ws_sold_date_sk729, _ws_quantity747, _wr_refunded_addr_sk837, _wr_returning_cdemo_sk839, _wr_reason_sk843, _wr_fee849, _wr_refunded_cash851, _cd_marital_status95, _cd_education_status96};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8713280_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cd_demo_sk3591_k = tbl_Filter_TD_8713280_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status3593_k_n = tbl_Filter_TD_8713280_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cd_marital_status3593_k = std::string(_cd_marital_status3593_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cd_education_status3594_k_n = tbl_Filter_TD_8713280_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _cd_education_status3594_k = std::string(_cd_education_status3594_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7458932_key_leftMajor{_cd_demo_sk3591_k, _cd_marital_status3593_k, _cd_education_status3594_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_date_sk729 = (it->second)._ws_sold_date_sk729;
                int32_t _ws_quantity747 = (it->second)._ws_quantity747;
                int32_t _wr_refunded_addr_sk837 = (it->second)._wr_refunded_addr_sk837;
                int32_t _wr_returning_cdemo_sk839 = (it->second)._wr_returning_cdemo_sk839;
                int32_t _wr_reason_sk843 = (it->second)._wr_reason_sk843;
                int64_t _wr_fee849 = (it->second)._wr_fee849;
                int64_t _wr_refunded_cash851 = (it->second)._wr_refunded_cash851;
                std::string _cd_marital_status95 = (it->second)._cd_marital_status95;
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n{};
                memcpy(_cd_marital_status95_n.data(), (_cd_marital_status95).data(), (_cd_marital_status95).length());
                std::string _cd_education_status96 = (it->second)._cd_education_status96;
                std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_n{};
                memcpy(_cd_education_status96_n.data(), (_cd_education_status96).data(), (_cd_education_status96).length());
                int32_t _cd_demo_sk3591 = tbl_Filter_TD_8713280_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status3593_n = tbl_Filter_TD_8713280_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _cd_marital_status3593 = std::string(_cd_marital_status3593_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cd_education_status3594_n = tbl_Filter_TD_8713280_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _cd_education_status3594 = std::string(_cd_education_status3594_n.data());
                tbl_JOIN_INNER_TD_7458932_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_7458932_output.setInt32(r, 1, _ws_quantity747);
                tbl_JOIN_INNER_TD_7458932_output.setInt32(r, 2, _wr_refunded_addr_sk837);
                tbl_JOIN_INNER_TD_7458932_output.setInt32(r, 3, _wr_reason_sk843);
                tbl_JOIN_INNER_TD_7458932_output.setInt64(r, 4, _wr_fee849);
                tbl_JOIN_INNER_TD_7458932_output.setInt64(r, 5, _wr_refunded_cash851);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7458932_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7458932_key_rightMajor, SW_JOIN_INNER_TD_7458932_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8713280_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cd_demo_sk3591_k = tbl_Filter_TD_8713280_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status3593_k_n = tbl_Filter_TD_8713280_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cd_marital_status3593_k = std::string(_cd_marital_status3593_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cd_education_status3594_k_n = tbl_Filter_TD_8713280_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _cd_education_status3594_k = std::string(_cd_education_status3594_k_n.data());
            SW_JOIN_INNER_TD_7458932_key_rightMajor keyA{_cd_demo_sk3591_k, _cd_marital_status3593_k, _cd_education_status3594_k};
            int32_t _cd_demo_sk3591 = tbl_Filter_TD_8713280_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status3593_n = tbl_Filter_TD_8713280_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cd_marital_status3593 = std::string(_cd_marital_status3593_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cd_education_status3594_n = tbl_Filter_TD_8713280_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _cd_education_status3594 = std::string(_cd_education_status3594_n.data());
            SW_JOIN_INNER_TD_7458932_payload_rightMajor payloadA{_cd_demo_sk3591, _cd_marital_status3593, _cd_education_status3594};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_8871642_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _wr_returning_cdemo_sk839_k = tbl_JOIN_INNER_TD_8871642_output.getInt32(i, 3);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_k_n = tbl_JOIN_INNER_TD_8871642_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _cd_marital_status95_k = std::string(_cd_marital_status95_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_k_n = tbl_JOIN_INNER_TD_8871642_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
            std::string _cd_education_status96_k = std::string(_cd_education_status96_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7458932_key_rightMajor{_wr_returning_cdemo_sk839_k, _cd_marital_status95_k, _cd_education_status96_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cd_demo_sk3591 = (it->second)._cd_demo_sk3591;
                std::string _cd_marital_status3593 = (it->second)._cd_marital_status3593;
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status3593_n{};
                memcpy(_cd_marital_status3593_n.data(), (_cd_marital_status3593).data(), (_cd_marital_status3593).length());
                std::string _cd_education_status3594 = (it->second)._cd_education_status3594;
                std::array<char, TPCDS_READ_MAX + 1> _cd_education_status3594_n{};
                memcpy(_cd_education_status3594_n.data(), (_cd_education_status3594).data(), (_cd_education_status3594).length());
                int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_8871642_output.getInt32(i, 0);
                int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_8871642_output.getInt32(i, 1);
                int32_t _wr_refunded_addr_sk837 = tbl_JOIN_INNER_TD_8871642_output.getInt32(i, 2);
                int32_t _wr_returning_cdemo_sk839 = tbl_JOIN_INNER_TD_8871642_output.getInt32(i, 3);
                int32_t _wr_reason_sk843 = tbl_JOIN_INNER_TD_8871642_output.getInt32(i, 4);
                int64_t _wr_fee849 = tbl_JOIN_INNER_TD_8871642_output.getInt64(i, 5);
                int64_t _wr_refunded_cash851 = tbl_JOIN_INNER_TD_8871642_output.getInt64(i, 6);
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n = tbl_JOIN_INNER_TD_8871642_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _cd_marital_status95 = std::string(_cd_marital_status95_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _cd_education_status96_n = tbl_JOIN_INNER_TD_8871642_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
                std::string _cd_education_status96 = std::string(_cd_education_status96_n.data());
                tbl_JOIN_INNER_TD_7458932_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_7458932_output.setInt32(r, 1, _ws_quantity747);
                tbl_JOIN_INNER_TD_7458932_output.setInt32(r, 2, _wr_refunded_addr_sk837);
                tbl_JOIN_INNER_TD_7458932_output.setInt32(r, 3, _wr_reason_sk843);
                tbl_JOIN_INNER_TD_7458932_output.setInt64(r, 4, _wr_fee849);
                tbl_JOIN_INNER_TD_7458932_output.setInt64(r, 5, _wr_refunded_cash851);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7458932_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7458932_output #Row: " << tbl_JOIN_INNER_TD_7458932_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6220690(Table &tbl_SerializeFromObject_TD_7127349_input, Table &tbl_Filter_TD_6220690_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#126) AND (d_year#126 = 2000)) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7127349_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_7127349_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_7127349_input.getInt32(i, 0);
        if (((_d_year126!= 0) && (_d_year126 == 2000)) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_7127349_input.getInt32(i, 0);
            tbl_Filter_TD_6220690_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_6220690_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6220690_output #Row: " << tbl_Filter_TD_6220690_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6321424_key_leftMajor {
    int32_t _wr_refunded_addr_sk837;
    bool operator==(const SW_JOIN_INNER_TD_6321424_key_leftMajor& other) const {
        return ((_wr_refunded_addr_sk837 == other._wr_refunded_addr_sk837));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6321424_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6321424_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._wr_refunded_addr_sk837));
    }
};
}
struct SW_JOIN_INNER_TD_6321424_payload_leftMajor {
    int32_t _ws_sold_date_sk729;
    int32_t _ws_quantity747;
    int32_t _wr_refunded_addr_sk837;
    int32_t _wr_reason_sk843;
    int64_t _wr_fee849;
    int64_t _wr_refunded_cash851;
};
struct SW_JOIN_INNER_TD_6321424_key_rightMajor {
    int32_t _ca_address_sk54;
    bool operator==(const SW_JOIN_INNER_TD_6321424_key_rightMajor& other) const {
        return ((_ca_address_sk54 == other._ca_address_sk54));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6321424_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6321424_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk54));
    }
};
}
struct SW_JOIN_INNER_TD_6321424_payload_rightMajor {
    int32_t _ca_address_sk54;
};
void SW_JOIN_INNER_TD_6321424(Table &tbl_JOIN_INNER_TD_7458932_output, Table &tbl_Filter_TD_7544516_output, Table &tbl_JOIN_INNER_TD_6321424_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ca_address_sk#54 = wr_refunded_addr_sk#837))
    // Left Table: ListBuffer(ws_sold_date_sk#729, ws_quantity#747, wr_refunded_addr_sk#837, wr_reason_sk#843, wr_fee#849, wr_refunded_cash#851)
    // Right Table: ListBuffer(ca_address_sk#54)
    // Output Table: ListBuffer(ws_sold_date_sk#729, ws_quantity#747, wr_reason_sk#843, wr_fee#849, wr_refunded_cash#851)
    int left_nrow = tbl_JOIN_INNER_TD_7458932_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7544516_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6321424_key_leftMajor, SW_JOIN_INNER_TD_6321424_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7458932_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _wr_refunded_addr_sk837_k = tbl_JOIN_INNER_TD_7458932_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_6321424_key_leftMajor keyA{_wr_refunded_addr_sk837_k};
            int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_7458932_output.getInt32(i, 0);
            int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_7458932_output.getInt32(i, 1);
            int32_t _wr_refunded_addr_sk837 = tbl_JOIN_INNER_TD_7458932_output.getInt32(i, 2);
            int32_t _wr_reason_sk843 = tbl_JOIN_INNER_TD_7458932_output.getInt32(i, 3);
            int64_t _wr_fee849 = tbl_JOIN_INNER_TD_7458932_output.getInt64(i, 4);
            int64_t _wr_refunded_cash851 = tbl_JOIN_INNER_TD_7458932_output.getInt64(i, 5);
            SW_JOIN_INNER_TD_6321424_payload_leftMajor payloadA{_ws_sold_date_sk729, _ws_quantity747, _wr_refunded_addr_sk837, _wr_reason_sk843, _wr_fee849, _wr_refunded_cash851};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7544516_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_7544516_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6321424_key_leftMajor{_ca_address_sk54_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_date_sk729 = (it->second)._ws_sold_date_sk729;
                int32_t _ws_quantity747 = (it->second)._ws_quantity747;
                int32_t _wr_refunded_addr_sk837 = (it->second)._wr_refunded_addr_sk837;
                int32_t _wr_reason_sk843 = (it->second)._wr_reason_sk843;
                int64_t _wr_fee849 = (it->second)._wr_fee849;
                int64_t _wr_refunded_cash851 = (it->second)._wr_refunded_cash851;
                int32_t _ca_address_sk54 = tbl_Filter_TD_7544516_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_6321424_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_6321424_output.setInt32(r, 1, _ws_quantity747);
                tbl_JOIN_INNER_TD_6321424_output.setInt32(r, 2, _wr_reason_sk843);
                tbl_JOIN_INNER_TD_6321424_output.setInt64(r, 3, _wr_fee849);
                tbl_JOIN_INNER_TD_6321424_output.setInt64(r, 4, _wr_refunded_cash851);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6321424_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6321424_key_rightMajor, SW_JOIN_INNER_TD_6321424_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7544516_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_7544516_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6321424_key_rightMajor keyA{_ca_address_sk54_k};
            int32_t _ca_address_sk54 = tbl_Filter_TD_7544516_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6321424_payload_rightMajor payloadA{_ca_address_sk54};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7458932_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _wr_refunded_addr_sk837_k = tbl_JOIN_INNER_TD_7458932_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6321424_key_rightMajor{_wr_refunded_addr_sk837_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk54 = (it->second)._ca_address_sk54;
                int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_7458932_output.getInt32(i, 0);
                int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_7458932_output.getInt32(i, 1);
                int32_t _wr_refunded_addr_sk837 = tbl_JOIN_INNER_TD_7458932_output.getInt32(i, 2);
                int32_t _wr_reason_sk843 = tbl_JOIN_INNER_TD_7458932_output.getInt32(i, 3);
                int64_t _wr_fee849 = tbl_JOIN_INNER_TD_7458932_output.getInt64(i, 4);
                int64_t _wr_refunded_cash851 = tbl_JOIN_INNER_TD_7458932_output.getInt64(i, 5);
                tbl_JOIN_INNER_TD_6321424_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_6321424_output.setInt32(r, 1, _ws_quantity747);
                tbl_JOIN_INNER_TD_6321424_output.setInt32(r, 2, _wr_reason_sk843);
                tbl_JOIN_INNER_TD_6321424_output.setInt64(r, 3, _wr_fee849);
                tbl_JOIN_INNER_TD_6321424_output.setInt64(r, 4, _wr_refunded_cash851);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6321424_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6321424_output #Row: " << tbl_JOIN_INNER_TD_6321424_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5498063(Table &tbl_SerializeFromObject_TD_6840585_input, Table &tbl_Filter_TD_5498063_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(r_reason_sk#351))
    // Input: ListBuffer(r_reason_sk#351, r_reason_desc#353)
    // Output: ListBuffer(r_reason_sk#351, r_reason_desc#353)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6840585_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _r_reason_sk351 = tbl_SerializeFromObject_TD_6840585_input.getInt32(i, 0);
        if (_r_reason_sk351!= 0) {
            int32_t _r_reason_sk351_t = tbl_SerializeFromObject_TD_6840585_input.getInt32(i, 0);
            tbl_Filter_TD_5498063_output.setInt32(r, 0, _r_reason_sk351_t);
            std::array<char, TPCDS_READ_MAX + 1> _r_reason_desc353_t = tbl_SerializeFromObject_TD_6840585_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_5498063_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _r_reason_desc353_t);
            r++;
        }
    }
    tbl_Filter_TD_5498063_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5498063_output #Row: " << tbl_Filter_TD_5498063_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5887610_key_leftMajor {
    int32_t _ws_sold_date_sk729;
    bool operator==(const SW_JOIN_INNER_TD_5887610_key_leftMajor& other) const {
        return ((_ws_sold_date_sk729 == other._ws_sold_date_sk729));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5887610_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5887610_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_sold_date_sk729));
    }
};
}
struct SW_JOIN_INNER_TD_5887610_payload_leftMajor {
    int32_t _ws_sold_date_sk729;
    int32_t _ws_quantity747;
    int32_t _wr_reason_sk843;
    int64_t _wr_fee849;
    int64_t _wr_refunded_cash851;
};
struct SW_JOIN_INNER_TD_5887610_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_5887610_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5887610_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5887610_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_5887610_payload_rightMajor {
    int32_t _d_date_sk120;
};
void SW_JOIN_INNER_TD_5887610(Table &tbl_JOIN_INNER_TD_6321424_output, Table &tbl_Filter_TD_6220690_output, Table &tbl_JOIN_INNER_TD_5887610_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_sold_date_sk#729 = d_date_sk#120))
    // Left Table: ListBuffer(ws_sold_date_sk#729, ws_quantity#747, wr_reason_sk#843, wr_fee#849, wr_refunded_cash#851)
    // Right Table: ListBuffer(d_date_sk#120)
    // Output Table: ListBuffer(ws_quantity#747, wr_reason_sk#843, wr_fee#849, wr_refunded_cash#851)
    int left_nrow = tbl_JOIN_INNER_TD_6321424_output.getNumRow();
    int right_nrow = tbl_Filter_TD_6220690_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5887610_key_leftMajor, SW_JOIN_INNER_TD_5887610_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_6321424_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_sold_date_sk729_k = tbl_JOIN_INNER_TD_6321424_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5887610_key_leftMajor keyA{_ws_sold_date_sk729_k};
            int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_6321424_output.getInt32(i, 0);
            int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_6321424_output.getInt32(i, 1);
            int32_t _wr_reason_sk843 = tbl_JOIN_INNER_TD_6321424_output.getInt32(i, 2);
            int64_t _wr_fee849 = tbl_JOIN_INNER_TD_6321424_output.getInt64(i, 3);
            int64_t _wr_refunded_cash851 = tbl_JOIN_INNER_TD_6321424_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_5887610_payload_leftMajor payloadA{_ws_sold_date_sk729, _ws_quantity747, _wr_reason_sk843, _wr_fee849, _wr_refunded_cash851};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6220690_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_6220690_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5887610_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_date_sk729 = (it->second)._ws_sold_date_sk729;
                int32_t _ws_quantity747 = (it->second)._ws_quantity747;
                int32_t _wr_reason_sk843 = (it->second)._wr_reason_sk843;
                int64_t _wr_fee849 = (it->second)._wr_fee849;
                int64_t _wr_refunded_cash851 = (it->second)._wr_refunded_cash851;
                int32_t _d_date_sk120 = tbl_Filter_TD_6220690_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_5887610_output.setInt32(r, 0, _ws_quantity747);
                tbl_JOIN_INNER_TD_5887610_output.setInt32(r, 1, _wr_reason_sk843);
                tbl_JOIN_INNER_TD_5887610_output.setInt64(r, 2, _wr_fee849);
                tbl_JOIN_INNER_TD_5887610_output.setInt64(r, 3, _wr_refunded_cash851);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5887610_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5887610_key_rightMajor, SW_JOIN_INNER_TD_5887610_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_6220690_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_6220690_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5887610_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_6220690_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5887610_payload_rightMajor payloadA{_d_date_sk120};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_6321424_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_sold_date_sk729_k = tbl_JOIN_INNER_TD_6321424_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5887610_key_rightMajor{_ws_sold_date_sk729_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_6321424_output.getInt32(i, 0);
                int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_6321424_output.getInt32(i, 1);
                int32_t _wr_reason_sk843 = tbl_JOIN_INNER_TD_6321424_output.getInt32(i, 2);
                int64_t _wr_fee849 = tbl_JOIN_INNER_TD_6321424_output.getInt64(i, 3);
                int64_t _wr_refunded_cash851 = tbl_JOIN_INNER_TD_6321424_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_5887610_output.setInt32(r, 0, _ws_quantity747);
                tbl_JOIN_INNER_TD_5887610_output.setInt32(r, 1, _wr_reason_sk843);
                tbl_JOIN_INNER_TD_5887610_output.setInt64(r, 2, _wr_fee849);
                tbl_JOIN_INNER_TD_5887610_output.setInt64(r, 3, _wr_refunded_cash851);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5887610_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5887610_output #Row: " << tbl_JOIN_INNER_TD_5887610_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_488414_key_leftMajor {
    int32_t _wr_reason_sk843;
    bool operator==(const SW_JOIN_INNER_TD_488414_key_leftMajor& other) const {
        return ((_wr_reason_sk843 == other._wr_reason_sk843));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_488414_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_488414_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._wr_reason_sk843));
    }
};
}
struct SW_JOIN_INNER_TD_488414_payload_leftMajor {
    int32_t _ws_quantity747;
    int32_t _wr_reason_sk843;
    int64_t _wr_fee849;
    int64_t _wr_refunded_cash851;
};
struct SW_JOIN_INNER_TD_488414_key_rightMajor {
    int32_t _r_reason_sk351;
    bool operator==(const SW_JOIN_INNER_TD_488414_key_rightMajor& other) const {
        return ((_r_reason_sk351 == other._r_reason_sk351));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_488414_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_488414_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._r_reason_sk351));
    }
};
}
struct SW_JOIN_INNER_TD_488414_payload_rightMajor {
    int32_t _r_reason_sk351;
    std::string _r_reason_desc353;
};
void SW_JOIN_INNER_TD_488414(Table &tbl_JOIN_INNER_TD_5887610_output, Table &tbl_Filter_TD_5498063_output, Table &tbl_JOIN_INNER_TD_488414_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((r_reason_sk#351 = wr_reason_sk#843))
    // Left Table: ListBuffer(ws_quantity#747, wr_reason_sk#843, wr_fee#849, wr_refunded_cash#851)
    // Right Table: ListBuffer(r_reason_sk#351, r_reason_desc#353)
    // Output Table: ListBuffer(ws_quantity#747, wr_fee#849, wr_refunded_cash#851, r_reason_desc#353)
    int left_nrow = tbl_JOIN_INNER_TD_5887610_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5498063_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_488414_key_leftMajor, SW_JOIN_INNER_TD_488414_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_5887610_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _wr_reason_sk843_k = tbl_JOIN_INNER_TD_5887610_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_488414_key_leftMajor keyA{_wr_reason_sk843_k};
            int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_5887610_output.getInt32(i, 0);
            int32_t _wr_reason_sk843 = tbl_JOIN_INNER_TD_5887610_output.getInt32(i, 1);
            int64_t _wr_fee849 = tbl_JOIN_INNER_TD_5887610_output.getInt64(i, 2);
            int64_t _wr_refunded_cash851 = tbl_JOIN_INNER_TD_5887610_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_488414_payload_leftMajor payloadA{_ws_quantity747, _wr_reason_sk843, _wr_fee849, _wr_refunded_cash851};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5498063_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _r_reason_sk351_k = tbl_Filter_TD_5498063_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_488414_key_leftMajor{_r_reason_sk351_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_quantity747 = (it->second)._ws_quantity747;
                int32_t _wr_reason_sk843 = (it->second)._wr_reason_sk843;
                int64_t _wr_fee849 = (it->second)._wr_fee849;
                int64_t _wr_refunded_cash851 = (it->second)._wr_refunded_cash851;
                int32_t _r_reason_sk351 = tbl_Filter_TD_5498063_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _r_reason_desc353_n = tbl_Filter_TD_5498063_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _r_reason_desc353 = std::string(_r_reason_desc353_n.data());
                tbl_JOIN_INNER_TD_488414_output.setInt32(r, 0, _ws_quantity747);
                tbl_JOIN_INNER_TD_488414_output.setInt64(r, 1, _wr_fee849);
                tbl_JOIN_INNER_TD_488414_output.setInt64(r, 2, _wr_refunded_cash851);
                tbl_JOIN_INNER_TD_488414_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _r_reason_desc353_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_488414_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_488414_key_rightMajor, SW_JOIN_INNER_TD_488414_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5498063_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _r_reason_sk351_k = tbl_Filter_TD_5498063_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_488414_key_rightMajor keyA{_r_reason_sk351_k};
            int32_t _r_reason_sk351 = tbl_Filter_TD_5498063_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _r_reason_desc353_n = tbl_Filter_TD_5498063_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _r_reason_desc353 = std::string(_r_reason_desc353_n.data());
            SW_JOIN_INNER_TD_488414_payload_rightMajor payloadA{_r_reason_sk351, _r_reason_desc353};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_5887610_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _wr_reason_sk843_k = tbl_JOIN_INNER_TD_5887610_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_488414_key_rightMajor{_wr_reason_sk843_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _r_reason_sk351 = (it->second)._r_reason_sk351;
                std::string _r_reason_desc353 = (it->second)._r_reason_desc353;
                std::array<char, TPCDS_READ_MAX + 1> _r_reason_desc353_n{};
                memcpy(_r_reason_desc353_n.data(), (_r_reason_desc353).data(), (_r_reason_desc353).length());
                int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_5887610_output.getInt32(i, 0);
                int32_t _wr_reason_sk843 = tbl_JOIN_INNER_TD_5887610_output.getInt32(i, 1);
                int64_t _wr_fee849 = tbl_JOIN_INNER_TD_5887610_output.getInt64(i, 2);
                int64_t _wr_refunded_cash851 = tbl_JOIN_INNER_TD_5887610_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_488414_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _r_reason_desc353_n);
                tbl_JOIN_INNER_TD_488414_output.setInt32(r, 0, _ws_quantity747);
                tbl_JOIN_INNER_TD_488414_output.setInt64(r, 1, _wr_fee849);
                tbl_JOIN_INNER_TD_488414_output.setInt64(r, 2, _wr_refunded_cash851);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_488414_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_488414_output #Row: " << tbl_JOIN_INNER_TD_488414_output.getNumRow() << std::endl;
}

typedef std::string SW_Aggregate_TD_3188024_key;
struct SW_Aggregate_TD_3188024_payload {
    std::string substr_r_reason_desc_1_20;
    int64_t _avgws_quantity3604_avg_0;
    int64_t _avgwr_refunded_cash3605_avg_1;
    int64_t _avgwr_fee3606_avg_2;
};
void SW_Aggregate_TD_3188024(Table &tbl_JOIN_INNER_TD_488414_output, Table &tbl_Aggregate_TD_3188024_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(r_reason_desc#353, substr(r_reason_desc#353, 1, 20) AS substr(r_reason_desc, 1, 20)#3603, avg(ws_quantity#747) AS avg(ws_quantity)#3604, cast((avg(UnscaledValue(wr_refunded_cash#851)) / 100.0) as decimal(11,6)) AS avg(wr_refunded_cash)#3605, cast((avg(UnscaledValue(wr_fee#849)) / 100.0) as decimal(11,6)) AS avg(wr_fee)#3606)
    // Input: ListBuffer(ws_quantity#747, wr_fee#849, wr_refunded_cash#851, r_reason_desc#353)
    // Output: ListBuffer(substr(r_reason_desc, 1, 20)#3603, avg(ws_quantity)#3604, avg(wr_refunded_cash)#3605, avg(wr_fee)#3606)
    std::unordered_map<SW_Aggregate_TD_3188024_key, SW_Aggregate_TD_3188024_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_488414_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_488414_output.getInt32(i, 0);
        int64_t _wr_fee849 = tbl_JOIN_INNER_TD_488414_output.getInt64(i, 1);
        int64_t _wr_refunded_cash851 = tbl_JOIN_INNER_TD_488414_output.getInt64(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _r_reason_desc353 = tbl_JOIN_INNER_TD_488414_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        SW_Aggregate_TD_3188024_key k = std::string(_r_reason_desc353.data());
        std::string substr_r_reason_desc_1_20 = std::string(_r_reason_desc353.data()).substr(0, 20);
        int64_t _avgws_quantity3604_avg_0 = _ws_quantity747;
        int64_t _avgwr_refunded_cash3605_avg_1 = _wr_refunded_cash851;
        int64_t _avgwr_fee3606_avg_2 = _wr_fee849;
        SW_Aggregate_TD_3188024_payload p{std::string(substr_r_reason_desc_1_20.data()), _avgws_quantity3604_avg_0, _avgwr_refunded_cash3605_avg_1, _avgwr_fee3606_avg_2};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t avg_0 = ((it->second)._avgws_quantity3604_avg_0 + _avgws_quantity3604_avg_0);
            p._avgws_quantity3604_avg_0 = avg_0;
            int64_t avg_1 = ((it->second)._avgwr_refunded_cash3605_avg_1 + _avgwr_refunded_cash3605_avg_1);
            p._avgwr_refunded_cash3605_avg_1 = avg_1;
            int64_t avg_2 = ((it->second)._avgwr_fee3606_avg_2 + _avgwr_fee3606_avg_2);
            p._avgwr_fee3606_avg_2 = avg_2;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _r_reason_desc353 not required in the output table
        std::array<char, TPCDS_READ_MAX + 1> substr_r_reason_desc_1_20_n{};
        memcpy(substr_r_reason_desc_1_20_n.data(), (it.second).substr_r_reason_desc_1_20.data(), (it.second).substr_r_reason_desc_1_20.length());
        tbl_Aggregate_TD_3188024_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, substr_r_reason_desc_1_20_n);
        int64_t _avgws_quantity3604 = (it.second)._avgws_quantity3604_avg_0 / nrow1;
        tbl_Aggregate_TD_3188024_output.setInt64(r, 1, _avgws_quantity3604);
        int64_t _avgwr_refunded_cash3605 = ((it.second)._avgwr_refunded_cash3605_avg_1 / nrow1 / 100.0);
        tbl_Aggregate_TD_3188024_output.setInt64(r, 2, _avgwr_refunded_cash3605);
        int64_t _avgwr_fee3606 = ((it.second)._avgwr_fee3606_avg_2 / nrow1 / 100.0);
        tbl_Aggregate_TD_3188024_output.setInt64(r, 3, _avgwr_fee3606);
        ++r;
    }
    tbl_Aggregate_TD_3188024_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_3188024_output #Row: " << tbl_Aggregate_TD_3188024_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2234757(Table &tbl_Aggregate_TD_3188024_output, Table &tbl_Sort_TD_2234757_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(substr(r_reason_desc, 1, 20)#3603 ASC NULLS FIRST)
    // Input: ListBuffer(substr(r_reason_desc, 1, 20)#3603, avg(ws_quantity)#3604, avg(wr_refunded_cash)#3605, avg(wr_fee)#3606)
    // Output: ListBuffer(substr(r_reason_desc, 1, 20)#3603, avg(ws_quantity)#3604, avg(wr_refunded_cash)#3605, avg(wr_fee)#3606)
    struct SW_Sort_TD_2234757Row {
        std::string substr_r_reason_desc_1_20;
        int64_t _avgws_quantity3604;
        int64_t _avgwr_refunded_cash3605;
        int64_t _avgwr_fee3606;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2234757Row& a, const SW_Sort_TD_2234757Row& b) const { return 
 (a.substr_r_reason_desc_1_20 < b.substr_r_reason_desc_1_20); 
}
    }SW_Sort_TD_2234757_order; 

    int nrow1 = tbl_Aggregate_TD_3188024_output.getNumRow();
    std::vector<SW_Sort_TD_2234757Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> substr_r_reason_desc_1_20 = tbl_Aggregate_TD_3188024_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        int32_t _avgws_quantity3604 = tbl_Aggregate_TD_3188024_output.getInt32(i, 1);
        int64_t _avgwr_refunded_cash3605 = tbl_Aggregate_TD_3188024_output.getInt64(i, 2);
        int64_t _avgwr_fee3606 = tbl_Aggregate_TD_3188024_output.getInt64(i, 3);
        SW_Sort_TD_2234757Row t = {std::string(substr_r_reason_desc_1_20.data()),_avgws_quantity3604,_avgwr_refunded_cash3605,_avgwr_fee3606};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2234757_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> substr_r_reason_desc_1_20{};
        memcpy(substr_r_reason_desc_1_20.data(), (it.substr_r_reason_desc_1_20).data(), (it.substr_r_reason_desc_1_20).length());
        tbl_Sort_TD_2234757_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, substr_r_reason_desc_1_20);
        tbl_Sort_TD_2234757_output.setInt32(r, 1, it._avgws_quantity3604);
        tbl_Sort_TD_2234757_output.setInt64(r, 2, it._avgwr_refunded_cash3605);
        tbl_Sort_TD_2234757_output.setInt64(r, 3, it._avgwr_fee3606);
        if (r < 10) {
            std::cout << (it.substr_r_reason_desc_1_20).data() << " " << it._avgws_quantity3604 << " " << it._avgwr_refunded_cash3605 << " " << it._avgwr_fee3606 << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_2234757_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2234757_output #Row: " << tbl_Sort_TD_2234757_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_137117(Table &tbl_Sort_TD_2234757_output, Table &tbl_LocalLimit_TD_137117_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(substr(r_reason_desc, 1, 20)#3603, avg(ws_quantity)#3604, avg(wr_refunded_cash)#3605, avg(wr_fee)#3606)
    // Output: ListBuffer(substr(r_reason_desc, 1, 20)#3603, avg(ws_quantity)#3604, avg(wr_refunded_cash)#3605, avg(wr_fee)#3606)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> substr_r_reason_desc_1_20_n = tbl_Sort_TD_2234757_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_137117_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, substr_r_reason_desc_1_20_n);
        tbl_LocalLimit_TD_137117_output.setInt64(r, 1, tbl_Sort_TD_2234757_output.getInt64(i, 1));
        tbl_LocalLimit_TD_137117_output.setInt64(r, 2, tbl_Sort_TD_2234757_output.getInt64(i, 2));
        tbl_LocalLimit_TD_137117_output.setInt64(r, 3, tbl_Sort_TD_2234757_output.getInt64(i, 3));
        r++;
    }
    tbl_LocalLimit_TD_137117_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_137117_output #Row: " << tbl_LocalLimit_TD_137117_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0464822(Table &tbl_LocalLimit_TD_137117_output, Table &tbl_GlobalLimit_TD_0464822_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(substr(r_reason_desc, 1, 20)#3603, avg(ws_quantity)#3604, avg(wr_refunded_cash)#3605, avg(wr_fee)#3606)
    // Output: ListBuffer(substr(r_reason_desc, 1, 20)#3603, avg(ws_quantity)#3604, avg(wr_refunded_cash)#3605, avg(wr_fee)#3606)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> substr_r_reason_desc_1_20_n = tbl_LocalLimit_TD_137117_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0464822_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, substr_r_reason_desc_1_20_n);
        tbl_GlobalLimit_TD_0464822_output.setInt64(r, 1, tbl_LocalLimit_TD_137117_output.getInt64(i, 1));
        tbl_GlobalLimit_TD_0464822_output.setInt64(r, 2, tbl_LocalLimit_TD_137117_output.getInt64(i, 2));
        tbl_GlobalLimit_TD_0464822_output.setInt64(r, 3, tbl_LocalLimit_TD_137117_output.getInt64(i, 3));
        r++;
    }
    tbl_GlobalLimit_TD_0464822_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0464822_output #Row: " << tbl_GlobalLimit_TD_0464822_output.getNumRow() << std::endl;
}

