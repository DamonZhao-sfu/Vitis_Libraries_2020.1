#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_12635927(Table &tbl_SerializeFromObject_TD_13656927_input, Table &tbl_Filter_TD_12635927_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ws_item_sk#8457) AND isnotnull(ws_order_number#8471L)) AND isnotnull(ws_web_site_sk#8467)))
    // Input: ListBuffer(ws_item_sk#8457, ws_web_site_sk#8467, ws_order_number#8471L)
    // Output: ListBuffer(ws_item_sk#8457, ws_web_site_sk#8467, ws_order_number#8471L)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13656927_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_item_sk8457 = tbl_SerializeFromObject_TD_13656927_input.getInt32(i, 0);
        int64_t _ws_order_number8471L = tbl_SerializeFromObject_TD_13656927_input.getInt64(i, 2);
        int32_t _ws_web_site_sk8467 = tbl_SerializeFromObject_TD_13656927_input.getInt32(i, 1);
        if (((_ws_item_sk8457!= 0) && (_ws_order_number8471L!= 0)) && (_ws_web_site_sk8467!= 0)) {
            int32_t _ws_item_sk8457_t = tbl_SerializeFromObject_TD_13656927_input.getInt32(i, 0);
            tbl_Filter_TD_12635927_output.setInt32(r, 0, _ws_item_sk8457_t);
            int32_t _ws_web_site_sk8467_t = tbl_SerializeFromObject_TD_13656927_input.getInt32(i, 1);
            tbl_Filter_TD_12635927_output.setInt32(r, 1, _ws_web_site_sk8467_t);
            int64_t _ws_order_number8471L_t = tbl_SerializeFromObject_TD_13656927_input.getInt64(i, 2);
            tbl_Filter_TD_12635927_output.setInt64(r, 2, _ws_order_number8471L_t);
            r++;
        }
    }
    tbl_Filter_TD_12635927_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12635927_output #Row: " << tbl_Filter_TD_12635927_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12427417(Table &tbl_SerializeFromObject_TD_13939313_input, Table &tbl_Filter_TD_12427417_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(wr_returned_date_sk#831))
    // Input: ListBuffer(wr_returned_date_sk#831, wr_item_sk#833, wr_order_number#844L, wr_return_amt#846, wr_net_loss#854)
    // Output: ListBuffer(wr_returned_date_sk#831, wr_item_sk#833, wr_order_number#844L, wr_return_amt#846, wr_net_loss#854)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13939313_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _wr_returned_date_sk831 = tbl_SerializeFromObject_TD_13939313_input.getInt32(i, 0);
        if (_wr_returned_date_sk831!= 0) {
            int32_t _wr_returned_date_sk831_t = tbl_SerializeFromObject_TD_13939313_input.getInt32(i, 0);
            tbl_Filter_TD_12427417_output.setInt32(r, 0, _wr_returned_date_sk831_t);
            int32_t _wr_item_sk833_t = tbl_SerializeFromObject_TD_13939313_input.getInt32(i, 1);
            tbl_Filter_TD_12427417_output.setInt32(r, 1, _wr_item_sk833_t);
            int64_t _wr_order_number844L_t = tbl_SerializeFromObject_TD_13939313_input.getInt64(i, 2);
            tbl_Filter_TD_12427417_output.setInt64(r, 2, _wr_order_number844L_t);
            int64_t _wr_return_amt846_t = tbl_SerializeFromObject_TD_13939313_input.getInt64(i, 3);
            tbl_Filter_TD_12427417_output.setInt64(r, 3, _wr_return_amt846_t);
            int64_t _wr_net_loss854_t = tbl_SerializeFromObject_TD_13939313_input.getInt64(i, 4);
            tbl_Filter_TD_12427417_output.setInt64(r, 4, _wr_net_loss854_t);
            r++;
        }
    }
    tbl_Filter_TD_12427417_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12427417_output #Row: " << tbl_Filter_TD_12427417_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_11320228_key_leftMajor {
    int32_t _wr_item_sk833;
    int64_t _wr_order_number844L;
    bool operator==(const SW_JOIN_INNER_TD_11320228_key_leftMajor& other) const {
        return ((_wr_item_sk833 == other._wr_item_sk833) && (_wr_order_number844L == other._wr_order_number844L));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11320228_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11320228_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._wr_item_sk833)) + (hash<int64_t>()(k._wr_order_number844L));
    }
};
}
struct SW_JOIN_INNER_TD_11320228_payload_leftMajor {
    int32_t _wr_returned_date_sk831;
    int32_t _wr_item_sk833;
    int64_t _wr_order_number844L;
    int64_t _wr_return_amt846;
    int64_t _wr_net_loss854;
};
struct SW_JOIN_INNER_TD_11320228_key_rightMajor {
    int32_t _ws_item_sk8457;
    int64_t _ws_order_number8471L;
    bool operator==(const SW_JOIN_INNER_TD_11320228_key_rightMajor& other) const {
        return ((_ws_item_sk8457 == other._ws_item_sk8457) && (_ws_order_number8471L == other._ws_order_number8471L));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11320228_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11320228_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_item_sk8457)) + (hash<int64_t>()(k._ws_order_number8471L));
    }
};
}
struct SW_JOIN_INNER_TD_11320228_payload_rightMajor {
    int32_t _ws_item_sk8457;
    int32_t _ws_web_site_sk8467;
    int64_t _ws_order_number8471L;
};
void SW_JOIN_INNER_TD_11320228(Table &tbl_Filter_TD_12427417_output, Table &tbl_Filter_TD_12635927_output, Table &tbl_JOIN_INNER_TD_11320228_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((wr_item_sk#833 = ws_item_sk#8457) AND (wr_order_number#844L = ws_order_number#8471L)))
    // Left Table: ListBuffer(wr_returned_date_sk#831, wr_item_sk#833, wr_order_number#844L, wr_return_amt#846, wr_net_loss#854)
    // Right Table: ListBuffer(ws_item_sk#8457, ws_web_site_sk#8467, ws_order_number#8471L)
    // Output Table: ListBuffer(ws_web_site_sk#8467, wr_returned_date_sk#831, wr_return_amt#846, wr_net_loss#854)
    int left_nrow = tbl_Filter_TD_12427417_output.getNumRow();
    int right_nrow = tbl_Filter_TD_12635927_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11320228_key_leftMajor, SW_JOIN_INNER_TD_11320228_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_12427417_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _wr_item_sk833_k = tbl_Filter_TD_12427417_output.getInt32(i, 1);
            int64_t _wr_order_number844L_k = tbl_Filter_TD_12427417_output.getInt64(i, 2);
            SW_JOIN_INNER_TD_11320228_key_leftMajor keyA{_wr_item_sk833_k, _wr_order_number844L_k};
            int32_t _wr_returned_date_sk831 = tbl_Filter_TD_12427417_output.getInt32(i, 0);
            int32_t _wr_item_sk833 = tbl_Filter_TD_12427417_output.getInt32(i, 1);
            int64_t _wr_order_number844L = tbl_Filter_TD_12427417_output.getInt64(i, 2);
            int64_t _wr_return_amt846 = tbl_Filter_TD_12427417_output.getInt64(i, 3);
            int64_t _wr_net_loss854 = tbl_Filter_TD_12427417_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_11320228_payload_leftMajor payloadA{_wr_returned_date_sk831, _wr_item_sk833, _wr_order_number844L, _wr_return_amt846, _wr_net_loss854};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_12635927_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_item_sk8457_k = tbl_Filter_TD_12635927_output.getInt32(i, 0);
            int64_t _ws_order_number8471L_k = tbl_Filter_TD_12635927_output.getInt64(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11320228_key_leftMajor{_ws_item_sk8457_k, _ws_order_number8471L_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _wr_returned_date_sk831 = (it->second)._wr_returned_date_sk831;
                int32_t _wr_item_sk833 = (it->second)._wr_item_sk833;
                int64_t _wr_order_number844L = (it->second)._wr_order_number844L;
                int64_t _wr_return_amt846 = (it->second)._wr_return_amt846;
                int64_t _wr_net_loss854 = (it->second)._wr_net_loss854;
                int32_t _ws_item_sk8457 = tbl_Filter_TD_12635927_output.getInt32(i, 0);
                int32_t _ws_web_site_sk8467 = tbl_Filter_TD_12635927_output.getInt32(i, 1);
                int64_t _ws_order_number8471L = tbl_Filter_TD_12635927_output.getInt64(i, 2);
                tbl_JOIN_INNER_TD_11320228_output.setInt32(r, 1, _wr_returned_date_sk831);
                tbl_JOIN_INNER_TD_11320228_output.setInt64(r, 2, _wr_return_amt846);
                tbl_JOIN_INNER_TD_11320228_output.setInt64(r, 3, _wr_net_loss854);
                tbl_JOIN_INNER_TD_11320228_output.setInt32(r, 0, _ws_web_site_sk8467);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11320228_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11320228_key_rightMajor, SW_JOIN_INNER_TD_11320228_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_12635927_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_item_sk8457_k = tbl_Filter_TD_12635927_output.getInt32(i, 0);
            int64_t _ws_order_number8471L_k = tbl_Filter_TD_12635927_output.getInt64(i, 2);
            SW_JOIN_INNER_TD_11320228_key_rightMajor keyA{_ws_item_sk8457_k, _ws_order_number8471L_k};
            int32_t _ws_item_sk8457 = tbl_Filter_TD_12635927_output.getInt32(i, 0);
            int32_t _ws_web_site_sk8467 = tbl_Filter_TD_12635927_output.getInt32(i, 1);
            int64_t _ws_order_number8471L = tbl_Filter_TD_12635927_output.getInt64(i, 2);
            SW_JOIN_INNER_TD_11320228_payload_rightMajor payloadA{_ws_item_sk8457, _ws_web_site_sk8467, _ws_order_number8471L};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_12427417_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _wr_item_sk833_k = tbl_Filter_TD_12427417_output.getInt32(i, 1);
            int64_t _wr_order_number844L_k = tbl_Filter_TD_12427417_output.getInt64(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11320228_key_rightMajor{_wr_item_sk833_k, _wr_order_number844L_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_item_sk8457 = (it->second)._ws_item_sk8457;
                int32_t _ws_web_site_sk8467 = (it->second)._ws_web_site_sk8467;
                int64_t _ws_order_number8471L = (it->second)._ws_order_number8471L;
                int32_t _wr_returned_date_sk831 = tbl_Filter_TD_12427417_output.getInt32(i, 0);
                int32_t _wr_item_sk833 = tbl_Filter_TD_12427417_output.getInt32(i, 1);
                int64_t _wr_order_number844L = tbl_Filter_TD_12427417_output.getInt64(i, 2);
                int64_t _wr_return_amt846 = tbl_Filter_TD_12427417_output.getInt64(i, 3);
                int64_t _wr_net_loss854 = tbl_Filter_TD_12427417_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_11320228_output.setInt32(r, 0, _ws_web_site_sk8467);
                tbl_JOIN_INNER_TD_11320228_output.setInt32(r, 1, _wr_returned_date_sk831);
                tbl_JOIN_INNER_TD_11320228_output.setInt64(r, 2, _wr_return_amt846);
                tbl_JOIN_INNER_TD_11320228_output.setInt64(r, 3, _wr_net_loss854);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11320228_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_11320228_output #Row: " << tbl_JOIN_INNER_TD_11320228_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11190108(Table &tbl_SerializeFromObject_TD_12208814_input, Table &tbl_Filter_TD_11190108_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_sold_date_sk#729) AND isnotnull(ws_web_site_sk#742)))
    // Input: ListBuffer(ws_web_site_sk#742, ws_sold_date_sk#729, ws_ext_sales_price#752, ws_net_profit#762)
    // Output: ListBuffer(ws_web_site_sk#742, ws_sold_date_sk#729, ws_ext_sales_price#752, ws_net_profit#762)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12208814_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_12208814_input.getInt32(i, 1);
        int32_t _ws_web_site_sk742 = tbl_SerializeFromObject_TD_12208814_input.getInt32(i, 0);
        if ((_ws_sold_date_sk729!= 0) && (_ws_web_site_sk742!= 0)) {
            int32_t _ws_web_site_sk742_t = tbl_SerializeFromObject_TD_12208814_input.getInt32(i, 0);
            tbl_Filter_TD_11190108_output.setInt32(r, 0, _ws_web_site_sk742_t);
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_12208814_input.getInt32(i, 1);
            tbl_Filter_TD_11190108_output.setInt32(r, 1, _ws_sold_date_sk729_t);
            int64_t _ws_ext_sales_price752_t = tbl_SerializeFromObject_TD_12208814_input.getInt64(i, 2);
            tbl_Filter_TD_11190108_output.setInt64(r, 2, _ws_ext_sales_price752_t);
            int64_t _ws_net_profit762_t = tbl_SerializeFromObject_TD_12208814_input.getInt64(i, 3);
            tbl_Filter_TD_11190108_output.setInt64(r, 3, _ws_net_profit762_t);
            r++;
        }
    }
    tbl_Filter_TD_11190108_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11190108_output #Row: " << tbl_Filter_TD_11190108_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11173530(Table &tbl_SerializeFromObject_TD_12330595_input, Table &tbl_Filter_TD_11173530_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cr_returned_date_sk#1023) AND isnotnull(cr_catalog_page_sk#1035)))
    // Input: ListBuffer(cr_catalog_page_sk#1035, cr_returned_date_sk#1023, cr_return_amount#1041, cr_net_loss#1049)
    // Output: ListBuffer(cr_catalog_page_sk#1035, cr_returned_date_sk#1023, cr_return_amount#1041, cr_net_loss#1049)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12330595_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cr_returned_date_sk1023 = tbl_SerializeFromObject_TD_12330595_input.getInt32(i, 1);
        int32_t _cr_catalog_page_sk1035 = tbl_SerializeFromObject_TD_12330595_input.getInt32(i, 0);
        if ((_cr_returned_date_sk1023!= 0) && (_cr_catalog_page_sk1035!= 0)) {
            int32_t _cr_catalog_page_sk1035_t = tbl_SerializeFromObject_TD_12330595_input.getInt32(i, 0);
            tbl_Filter_TD_11173530_output.setInt32(r, 0, _cr_catalog_page_sk1035_t);
            int32_t _cr_returned_date_sk1023_t = tbl_SerializeFromObject_TD_12330595_input.getInt32(i, 1);
            tbl_Filter_TD_11173530_output.setInt32(r, 1, _cr_returned_date_sk1023_t);
            int64_t _cr_return_amount1041_t = tbl_SerializeFromObject_TD_12330595_input.getInt64(i, 2);
            tbl_Filter_TD_11173530_output.setInt64(r, 2, _cr_return_amount1041_t);
            int64_t _cr_net_loss1049_t = tbl_SerializeFromObject_TD_12330595_input.getInt64(i, 3);
            tbl_Filter_TD_11173530_output.setInt64(r, 3, _cr_net_loss1049_t);
            r++;
        }
    }
    tbl_Filter_TD_11173530_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11173530_output #Row: " << tbl_Filter_TD_11173530_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11644099(Table &tbl_SerializeFromObject_TD_12121952_input, Table &tbl_Filter_TD_11644099_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cs_sold_date_sk#1104) AND isnotnull(cs_catalog_page_sk#1116)))
    // Input: ListBuffer(cs_catalog_page_sk#1116, cs_sold_date_sk#1104, cs_ext_sales_price#1127, cs_net_profit#1137)
    // Output: ListBuffer(cs_catalog_page_sk#1116, cs_sold_date_sk#1104, cs_ext_sales_price#1127, cs_net_profit#1137)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12121952_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_12121952_input.getInt32(i, 1);
        int32_t _cs_catalog_page_sk1116 = tbl_SerializeFromObject_TD_12121952_input.getInt32(i, 0);
        if ((_cs_sold_date_sk1104!= 0) && (_cs_catalog_page_sk1116!= 0)) {
            int32_t _cs_catalog_page_sk1116_t = tbl_SerializeFromObject_TD_12121952_input.getInt32(i, 0);
            tbl_Filter_TD_11644099_output.setInt32(r, 0, _cs_catalog_page_sk1116_t);
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_12121952_input.getInt32(i, 1);
            tbl_Filter_TD_11644099_output.setInt32(r, 1, _cs_sold_date_sk1104_t);
            int64_t _cs_ext_sales_price1127_t = tbl_SerializeFromObject_TD_12121952_input.getInt64(i, 2);
            tbl_Filter_TD_11644099_output.setInt64(r, 2, _cs_ext_sales_price1127_t);
            int64_t _cs_net_profit1137_t = tbl_SerializeFromObject_TD_12121952_input.getInt64(i, 3);
            tbl_Filter_TD_11644099_output.setInt64(r, 3, _cs_net_profit1137_t);
            r++;
        }
    }
    tbl_Filter_TD_11644099_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11644099_output #Row: " << tbl_Filter_TD_11644099_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11519105(Table &tbl_SerializeFromObject_TD_1242456_input, Table &tbl_Filter_TD_11519105_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(sr_returned_date_sk#669) AND isnotnull(sr_store_sk#676)))
    // Input: ListBuffer(sr_store_sk#676, sr_returned_date_sk#669, sr_return_amt#680, sr_net_loss#688)
    // Output: ListBuffer(sr_store_sk#676, sr_returned_date_sk#669, sr_return_amt#680, sr_net_loss#688)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1242456_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _sr_returned_date_sk669 = tbl_SerializeFromObject_TD_1242456_input.getInt32(i, 1);
        int32_t _sr_store_sk676 = tbl_SerializeFromObject_TD_1242456_input.getInt32(i, 0);
        if ((_sr_returned_date_sk669!= 0) && (_sr_store_sk676!= 0)) {
            int32_t _sr_store_sk676_t = tbl_SerializeFromObject_TD_1242456_input.getInt32(i, 0);
            tbl_Filter_TD_11519105_output.setInt32(r, 0, _sr_store_sk676_t);
            int32_t _sr_returned_date_sk669_t = tbl_SerializeFromObject_TD_1242456_input.getInt32(i, 1);
            tbl_Filter_TD_11519105_output.setInt32(r, 1, _sr_returned_date_sk669_t);
            int64_t _sr_return_amt680_t = tbl_SerializeFromObject_TD_1242456_input.getInt64(i, 2);
            tbl_Filter_TD_11519105_output.setInt64(r, 2, _sr_return_amt680_t);
            int64_t _sr_net_loss688_t = tbl_SerializeFromObject_TD_1242456_input.getInt64(i, 3);
            tbl_Filter_TD_11519105_output.setInt64(r, 3, _sr_net_loss688_t);
            r++;
        }
    }
    tbl_Filter_TD_11519105_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11519105_output #Row: " << tbl_Filter_TD_11519105_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11183378(Table &tbl_SerializeFromObject_TD_12914841_input, Table &tbl_Filter_TD_11183378_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_sold_date_sk#1206) AND isnotnull(ss_store_sk#1213)))
    // Input: ListBuffer(ss_store_sk#1213, ss_sold_date_sk#1206, ss_ext_sales_price#1221, ss_net_profit#1228)
    // Output: ListBuffer(ss_store_sk#1213, ss_sold_date_sk#1206, ss_ext_sales_price#1221, ss_net_profit#1228)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12914841_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_12914841_input.getInt32(i, 1);
        int32_t _ss_store_sk1213 = tbl_SerializeFromObject_TD_12914841_input.getInt32(i, 0);
        if ((_ss_sold_date_sk1206!= 0) && (_ss_store_sk1213!= 0)) {
            int32_t _ss_store_sk1213_t = tbl_SerializeFromObject_TD_12914841_input.getInt32(i, 0);
            tbl_Filter_TD_11183378_output.setInt32(r, 0, _ss_store_sk1213_t);
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_12914841_input.getInt32(i, 1);
            tbl_Filter_TD_11183378_output.setInt32(r, 1, _ss_sold_date_sk1206_t);
            int64_t _ss_ext_sales_price1221_t = tbl_SerializeFromObject_TD_12914841_input.getInt64(i, 2);
            tbl_Filter_TD_11183378_output.setInt64(r, 2, _ss_ext_sales_price1221_t);
            int64_t _ss_net_profit1228_t = tbl_SerializeFromObject_TD_12914841_input.getInt64(i, 3);
            tbl_Filter_TD_11183378_output.setInt64(r, 3, _ss_net_profit1228_t);
            r++;
        }
    }
    tbl_Filter_TD_11183378_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11183378_output #Row: " << tbl_Filter_TD_11183378_output.getNumRow() << std::endl;
}

void SW_Project_TD_10926061(Table &tbl_JOIN_INNER_TD_11320228_output, Table &tbl_Project_TD_10926061_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(ws_web_site_sk#8467 AS wsr_web_site_sk#8416, wr_returned_date_sk#831 AS date_sk#8417, 0.00 AS sales_price#8418, 0.00 AS profit#8419, wr_return_amt#846 AS return_amt#8420, wr_net_loss#854 AS net_loss#8421)
    // Input: ListBuffer(ws_web_site_sk#8467, wr_returned_date_sk#831, wr_return_amt#846, wr_net_loss#854)
    // Output: ListBuffer(wsr_web_site_sk#8416, date_sk#8417, sales_price#8418, profit#8419, return_amt#8420, net_loss#8421)
    int nrow1 = tbl_JOIN_INNER_TD_11320228_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_web_site_sk8467 = tbl_JOIN_INNER_TD_11320228_output.getInt32(i, 0);
        int32_t _wr_returned_date_sk831 = tbl_JOIN_INNER_TD_11320228_output.getInt32(i, 1);
        int64_t _wr_return_amt846 = tbl_JOIN_INNER_TD_11320228_output.getInt64(i, 2);
        int64_t _wr_net_loss854 = tbl_JOIN_INNER_TD_11320228_output.getInt64(i, 3);
        int32_t _wsr_web_site_sk8416 = _ws_web_site_sk8467;
        tbl_Project_TD_10926061_output.setInt32(i, 0, _wsr_web_site_sk8416);
        int32_t _date_sk8417 = _wr_returned_date_sk831;
        tbl_Project_TD_10926061_output.setInt32(i, 1, _date_sk8417);
        int64_t _sales_price8418 = 0.00;
        tbl_Project_TD_10926061_output.setInt64(i, 2, _sales_price8418);
        int64_t _profit8419 = 0.00;
        tbl_Project_TD_10926061_output.setInt64(i, 3, _profit8419);
        int64_t _return_amt8420 = _wr_return_amt846;
        tbl_Project_TD_10926061_output.setInt64(i, 4, _return_amt8420);
        int64_t _net_loss8421 = _wr_net_loss854;
        tbl_Project_TD_10926061_output.setInt64(i, 5, _net_loss8421);
    }
    tbl_Project_TD_10926061_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_10926061_output #Row: " << tbl_Project_TD_10926061_output.getNumRow() << std::endl;
}

void SW_Project_TD_10400972(Table &tbl_Filter_TD_11190108_output, Table &tbl_Project_TD_10400972_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(ws_web_site_sk#742 AS wsr_web_site_sk#8410, ws_sold_date_sk#729 AS date_sk#8411, ws_ext_sales_price#752 AS sales_price#8412, ws_net_profit#762 AS profit#8413, 0.00 AS return_amt#8414, 0.00 AS net_loss#8415)
    // Input: ListBuffer(ws_web_site_sk#742, ws_sold_date_sk#729, ws_ext_sales_price#752, ws_net_profit#762)
    // Output: ListBuffer(wsr_web_site_sk#8410, date_sk#8411, sales_price#8412, profit#8413, return_amt#8414, net_loss#8415)
    int nrow1 = tbl_Filter_TD_11190108_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_web_site_sk742 = tbl_Filter_TD_11190108_output.getInt32(i, 0);
        int32_t _ws_sold_date_sk729 = tbl_Filter_TD_11190108_output.getInt32(i, 1);
        int64_t _ws_ext_sales_price752 = tbl_Filter_TD_11190108_output.getInt64(i, 2);
        int64_t _ws_net_profit762 = tbl_Filter_TD_11190108_output.getInt64(i, 3);
        int32_t _wsr_web_site_sk8410 = _ws_web_site_sk742;
        tbl_Project_TD_10400972_output.setInt32(i, 0, _wsr_web_site_sk8410);
        int32_t _date_sk8411 = _ws_sold_date_sk729;
        tbl_Project_TD_10400972_output.setInt32(i, 1, _date_sk8411);
        int64_t _sales_price8412 = _ws_ext_sales_price752;
        tbl_Project_TD_10400972_output.setInt64(i, 2, _sales_price8412);
        int64_t _profit8413 = _ws_net_profit762;
        tbl_Project_TD_10400972_output.setInt64(i, 3, _profit8413);
        int64_t _return_amt8414 = 0.00;
        tbl_Project_TD_10400972_output.setInt64(i, 4, _return_amt8414);
        int64_t _net_loss8415 = 0.00;
        tbl_Project_TD_10400972_output.setInt64(i, 5, _net_loss8415);
    }
    tbl_Project_TD_10400972_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_10400972_output #Row: " << tbl_Project_TD_10400972_output.getNumRow() << std::endl;
}

void SW_Project_TD_10950398(Table &tbl_Filter_TD_11173530_output, Table &tbl_Project_TD_10950398_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(cr_catalog_page_sk#1035 AS page_sk#8400, cr_returned_date_sk#1023 AS date_sk#8401, 0.00 AS sales_price#8402, 0.00 AS profit#8403, cr_return_amount#1041 AS return_amt#8404, cr_net_loss#1049 AS net_loss#8405)
    // Input: ListBuffer(cr_catalog_page_sk#1035, cr_returned_date_sk#1023, cr_return_amount#1041, cr_net_loss#1049)
    // Output: ListBuffer(page_sk#8400, date_sk#8401, sales_price#8402, profit#8403, return_amt#8404, net_loss#8405)
    int nrow1 = tbl_Filter_TD_11173530_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cr_catalog_page_sk1035 = tbl_Filter_TD_11173530_output.getInt32(i, 0);
        int32_t _cr_returned_date_sk1023 = tbl_Filter_TD_11173530_output.getInt32(i, 1);
        int64_t _cr_return_amount1041 = tbl_Filter_TD_11173530_output.getInt64(i, 2);
        int64_t _cr_net_loss1049 = tbl_Filter_TD_11173530_output.getInt64(i, 3);
        int32_t _page_sk8400 = _cr_catalog_page_sk1035;
        tbl_Project_TD_10950398_output.setInt32(i, 0, _page_sk8400);
        int32_t _date_sk8401 = _cr_returned_date_sk1023;
        tbl_Project_TD_10950398_output.setInt32(i, 1, _date_sk8401);
        int64_t _sales_price8402 = 0.00;
        tbl_Project_TD_10950398_output.setInt64(i, 2, _sales_price8402);
        int64_t _profit8403 = 0.00;
        tbl_Project_TD_10950398_output.setInt64(i, 3, _profit8403);
        int64_t _return_amt8404 = _cr_return_amount1041;
        tbl_Project_TD_10950398_output.setInt64(i, 4, _return_amt8404);
        int64_t _net_loss8405 = _cr_net_loss1049;
        tbl_Project_TD_10950398_output.setInt64(i, 5, _net_loss8405);
    }
    tbl_Project_TD_10950398_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_10950398_output #Row: " << tbl_Project_TD_10950398_output.getNumRow() << std::endl;
}

void SW_Project_TD_10840291(Table &tbl_Filter_TD_11644099_output, Table &tbl_Project_TD_10840291_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(cs_catalog_page_sk#1116 AS page_sk#8394, cs_sold_date_sk#1104 AS date_sk#8395, cs_ext_sales_price#1127 AS sales_price#8396, cs_net_profit#1137 AS profit#8397, 0.00 AS return_amt#8398, 0.00 AS net_loss#8399)
    // Input: ListBuffer(cs_catalog_page_sk#1116, cs_sold_date_sk#1104, cs_ext_sales_price#1127, cs_net_profit#1137)
    // Output: ListBuffer(page_sk#8394, date_sk#8395, sales_price#8396, profit#8397, return_amt#8398, net_loss#8399)
    int nrow1 = tbl_Filter_TD_11644099_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_catalog_page_sk1116 = tbl_Filter_TD_11644099_output.getInt32(i, 0);
        int32_t _cs_sold_date_sk1104 = tbl_Filter_TD_11644099_output.getInt32(i, 1);
        int64_t _cs_ext_sales_price1127 = tbl_Filter_TD_11644099_output.getInt64(i, 2);
        int64_t _cs_net_profit1137 = tbl_Filter_TD_11644099_output.getInt64(i, 3);
        int32_t _page_sk8394 = _cs_catalog_page_sk1116;
        tbl_Project_TD_10840291_output.setInt32(i, 0, _page_sk8394);
        int32_t _date_sk8395 = _cs_sold_date_sk1104;
        tbl_Project_TD_10840291_output.setInt32(i, 1, _date_sk8395);
        int64_t _sales_price8396 = _cs_ext_sales_price1127;
        tbl_Project_TD_10840291_output.setInt64(i, 2, _sales_price8396);
        int64_t _profit8397 = _cs_net_profit1137;
        tbl_Project_TD_10840291_output.setInt64(i, 3, _profit8397);
        int64_t _return_amt8398 = 0.00;
        tbl_Project_TD_10840291_output.setInt64(i, 4, _return_amt8398);
        int64_t _net_loss8399 = 0.00;
        tbl_Project_TD_10840291_output.setInt64(i, 5, _net_loss8399);
    }
    tbl_Project_TD_10840291_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_10840291_output #Row: " << tbl_Project_TD_10840291_output.getNumRow() << std::endl;
}

void SW_Project_TD_10240760(Table &tbl_Filter_TD_11519105_output, Table &tbl_Project_TD_10240760_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(sr_store_sk#676 AS store_sk#8384, sr_returned_date_sk#669 AS date_sk#8385, 0.00 AS sales_price#8386, 0.00 AS profit#8387, sr_return_amt#680 AS return_amt#8388, sr_net_loss#688 AS net_loss#8389)
    // Input: ListBuffer(sr_store_sk#676, sr_returned_date_sk#669, sr_return_amt#680, sr_net_loss#688)
    // Output: ListBuffer(store_sk#8384, date_sk#8385, sales_price#8386, profit#8387, return_amt#8388, net_loss#8389)
    int nrow1 = tbl_Filter_TD_11519105_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _sr_store_sk676 = tbl_Filter_TD_11519105_output.getInt32(i, 0);
        int32_t _sr_returned_date_sk669 = tbl_Filter_TD_11519105_output.getInt32(i, 1);
        int64_t _sr_return_amt680 = tbl_Filter_TD_11519105_output.getInt64(i, 2);
        int64_t _sr_net_loss688 = tbl_Filter_TD_11519105_output.getInt64(i, 3);
        int32_t _store_sk8384 = _sr_store_sk676;
        tbl_Project_TD_10240760_output.setInt32(i, 0, _store_sk8384);
        int32_t _date_sk8385 = _sr_returned_date_sk669;
        tbl_Project_TD_10240760_output.setInt32(i, 1, _date_sk8385);
        int64_t _sales_price8386 = 0.00;
        tbl_Project_TD_10240760_output.setInt64(i, 2, _sales_price8386);
        int64_t _profit8387 = 0.00;
        tbl_Project_TD_10240760_output.setInt64(i, 3, _profit8387);
        int64_t _return_amt8388 = _sr_return_amt680;
        tbl_Project_TD_10240760_output.setInt64(i, 4, _return_amt8388);
        int64_t _net_loss8389 = _sr_net_loss688;
        tbl_Project_TD_10240760_output.setInt64(i, 5, _net_loss8389);
    }
    tbl_Project_TD_10240760_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_10240760_output #Row: " << tbl_Project_TD_10240760_output.getNumRow() << std::endl;
}

void SW_Project_TD_10341667(Table &tbl_Filter_TD_11183378_output, Table &tbl_Project_TD_10341667_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(ss_store_sk#1213 AS store_sk#8378, ss_sold_date_sk#1206 AS date_sk#8379, ss_ext_sales_price#1221 AS sales_price#8380, ss_net_profit#1228 AS profit#8381, 0.00 AS return_amt#8382, 0.00 AS net_loss#8383)
    // Input: ListBuffer(ss_store_sk#1213, ss_sold_date_sk#1206, ss_ext_sales_price#1221, ss_net_profit#1228)
    // Output: ListBuffer(store_sk#8378, date_sk#8379, sales_price#8380, profit#8381, return_amt#8382, net_loss#8383)
    int nrow1 = tbl_Filter_TD_11183378_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_store_sk1213 = tbl_Filter_TD_11183378_output.getInt32(i, 0);
        int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_11183378_output.getInt32(i, 1);
        int64_t _ss_ext_sales_price1221 = tbl_Filter_TD_11183378_output.getInt64(i, 2);
        int64_t _ss_net_profit1228 = tbl_Filter_TD_11183378_output.getInt64(i, 3);
        int32_t _store_sk8378 = _ss_store_sk1213;
        tbl_Project_TD_10341667_output.setInt32(i, 0, _store_sk8378);
        int32_t _date_sk8379 = _ss_sold_date_sk1206;
        tbl_Project_TD_10341667_output.setInt32(i, 1, _date_sk8379);
        int64_t _sales_price8380 = _ss_ext_sales_price1221;
        tbl_Project_TD_10341667_output.setInt64(i, 2, _sales_price8380);
        int64_t _profit8381 = _ss_net_profit1228;
        tbl_Project_TD_10341667_output.setInt64(i, 3, _profit8381);
        int64_t _return_amt8382 = 0.00;
        tbl_Project_TD_10341667_output.setInt64(i, 4, _return_amt8382);
        int64_t _net_loss8383 = 0.00;
        tbl_Project_TD_10341667_output.setInt64(i, 5, _net_loss8383);
    }
    tbl_Project_TD_10341667_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_10341667_output #Row: " << tbl_Project_TD_10341667_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9834949(Table &tbl_SerializeFromObject_TD_10939837_input, Table &tbl_Filter_TD_9834949_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_date#8490) AND ((d_date#8490 >= 2000-08-23) AND (d_date#8490 <= 2000-09-06))) AND isnotnull(d_date_sk#8488)))
    // Input: ListBuffer(d_date_sk#8488, d_date#8490)
    // Output: ListBuffer(d_date_sk#8488)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10939837_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date8490 = tbl_SerializeFromObject_TD_10939837_input.getInt32(i, 1);
        int32_t _d_date_sk8488 = tbl_SerializeFromObject_TD_10939837_input.getInt32(i, 0);
        if (((_d_date8490!= 0) && ((_d_date8490 >= 20000823) && (_d_date8490 <= 20000906))) && (_d_date_sk8488!= 0)) {
            int32_t _d_date_sk8488_t = tbl_SerializeFromObject_TD_10939837_input.getInt32(i, 0);
            tbl_Filter_TD_9834949_output.setInt32(r, 0, _d_date_sk8488_t);
            r++;
        }
    }
    tbl_Filter_TD_9834949_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9834949_output #Row: " << tbl_Filter_TD_9834949_output.getNumRow() << std::endl;
}

void SW_Union_TD_980579(Table &tbl_Project_TD_10400972_output, Table &tbl_Project_TD_10926061_output, Table &tbl_Union_TD_980579_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Union
    // Operation: ListBuffer(List(UNION))
    // Output Table: ListBuffer(wsr_web_site_sk#8410, date_sk#8411, sales_price#8412, profit#8413, return_amt#8414, net_loss#8415)
    int r = 0;
    int row0 = tbl_Project_TD_10400972_output.getNumRow();
    for (int i = 0; i < row0; i++) {
        tbl_Union_TD_980579_output.setInt32(r, 0, tbl_Project_TD_10400972_output.getInt32(i, 0));
        tbl_Union_TD_980579_output.setInt32(r, 1, tbl_Project_TD_10400972_output.getInt32(i, 1));
        tbl_Union_TD_980579_output.setInt32(r, 2, tbl_Project_TD_10400972_output.getInt64(i, 2));
        tbl_Union_TD_980579_output.setInt32(r, 3, tbl_Project_TD_10400972_output.getInt64(i, 3));
        tbl_Union_TD_980579_output.setInt32(r, 4, tbl_Project_TD_10400972_output.getInt64(i, 4));
        tbl_Union_TD_980579_output.setInt32(r, 5, tbl_Project_TD_10400972_output.getInt64(i, 5));
        ++r;
    }
    int row1 = tbl_Project_TD_10926061_output.getNumRow();
    for (int i = 0; i < row1; i++) {
        tbl_Union_TD_980579_output.setInt32(r, 0, tbl_Project_TD_10926061_output.getInt32(i, 0));
        tbl_Union_TD_980579_output.setInt32(r, 1, tbl_Project_TD_10926061_output.getInt32(i, 1));
        tbl_Union_TD_980579_output.setInt32(r, 2, tbl_Project_TD_10926061_output.getInt64(i, 2));
        tbl_Union_TD_980579_output.setInt32(r, 3, tbl_Project_TD_10926061_output.getInt64(i, 3));
        tbl_Union_TD_980579_output.setInt32(r, 4, tbl_Project_TD_10926061_output.getInt64(i, 4));
        tbl_Union_TD_980579_output.setInt32(r, 5, tbl_Project_TD_10926061_output.getInt64(i, 5));
        ++r;
    }
    tbl_Union_TD_980579_output.setNumRow(r);
    std::cout << "tbl_Union_TD_980579_output #Row: " << tbl_Union_TD_980579_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9539098(Table &tbl_SerializeFromObject_TD_10187856_input, Table &tbl_Filter_TD_9539098_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_date#8428) AND ((d_date#8428 >= 2000-08-23) AND (d_date#8428 <= 2000-09-06))) AND isnotnull(d_date_sk#8426)))
    // Input: ListBuffer(d_date_sk#8426, d_date#8428)
    // Output: ListBuffer(d_date_sk#8426)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10187856_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date8428 = tbl_SerializeFromObject_TD_10187856_input.getInt32(i, 1);
        int32_t _d_date_sk8426 = tbl_SerializeFromObject_TD_10187856_input.getInt32(i, 0);
        if (((_d_date8428!= 0) && ((_d_date8428 >= 20000823) && (_d_date8428 <= 20000906))) && (_d_date_sk8426!= 0)) {
            int32_t _d_date_sk8426_t = tbl_SerializeFromObject_TD_10187856_input.getInt32(i, 0);
            tbl_Filter_TD_9539098_output.setInt32(r, 0, _d_date_sk8426_t);
            r++;
        }
    }
    tbl_Filter_TD_9539098_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9539098_output #Row: " << tbl_Filter_TD_9539098_output.getNumRow() << std::endl;
}

void SW_Union_TD_9812863(Table &tbl_Project_TD_10840291_output, Table &tbl_Project_TD_10950398_output, Table &tbl_Union_TD_9812863_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Union
    // Operation: ListBuffer(List(UNION))
    // Output Table: ListBuffer(page_sk#8394, date_sk#8395, sales_price#8396, profit#8397, return_amt#8398, net_loss#8399)
    int r = 0;
    int row0 = tbl_Project_TD_10840291_output.getNumRow();
    for (int i = 0; i < row0; i++) {
        tbl_Union_TD_9812863_output.setInt32(r, 0, tbl_Project_TD_10840291_output.getInt32(i, 0));
        tbl_Union_TD_9812863_output.setInt32(r, 1, tbl_Project_TD_10840291_output.getInt32(i, 1));
        tbl_Union_TD_9812863_output.setInt32(r, 2, tbl_Project_TD_10840291_output.getInt64(i, 2));
        tbl_Union_TD_9812863_output.setInt32(r, 3, tbl_Project_TD_10840291_output.getInt64(i, 3));
        tbl_Union_TD_9812863_output.setInt32(r, 4, tbl_Project_TD_10840291_output.getInt64(i, 4));
        tbl_Union_TD_9812863_output.setInt32(r, 5, tbl_Project_TD_10840291_output.getInt64(i, 5));
        ++r;
    }
    int row1 = tbl_Project_TD_10950398_output.getNumRow();
    for (int i = 0; i < row1; i++) {
        tbl_Union_TD_9812863_output.setInt32(r, 0, tbl_Project_TD_10950398_output.getInt32(i, 0));
        tbl_Union_TD_9812863_output.setInt32(r, 1, tbl_Project_TD_10950398_output.getInt32(i, 1));
        tbl_Union_TD_9812863_output.setInt32(r, 2, tbl_Project_TD_10950398_output.getInt64(i, 2));
        tbl_Union_TD_9812863_output.setInt32(r, 3, tbl_Project_TD_10950398_output.getInt64(i, 3));
        tbl_Union_TD_9812863_output.setInt32(r, 4, tbl_Project_TD_10950398_output.getInt64(i, 4));
        tbl_Union_TD_9812863_output.setInt32(r, 5, tbl_Project_TD_10950398_output.getInt64(i, 5));
        ++r;
    }
    tbl_Union_TD_9812863_output.setNumRow(r);
    std::cout << "tbl_Union_TD_9812863_output #Row: " << tbl_Union_TD_9812863_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9561562(Table &tbl_SerializeFromObject_TD_10649452_input, Table &tbl_Filter_TD_9561562_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_date#122) AND ((d_date#122 >= 2000-08-23) AND (d_date#122 <= 2000-09-06))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_date#122)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10649452_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date122 = tbl_SerializeFromObject_TD_10649452_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_10649452_input.getInt32(i, 0);
        if (((_d_date122!= 0) && ((_d_date122 >= 20000823) && (_d_date122 <= 20000906))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_10649452_input.getInt32(i, 0);
            tbl_Filter_TD_9561562_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_9561562_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9561562_output #Row: " << tbl_Filter_TD_9561562_output.getNumRow() << std::endl;
}

void SW_Union_TD_9523992(Table &tbl_Project_TD_10341667_output, Table &tbl_Project_TD_10240760_output, Table &tbl_Union_TD_9523992_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Union
    // Operation: ListBuffer(List(UNION))
    // Output Table: ListBuffer(store_sk#8378, date_sk#8379, sales_price#8380, profit#8381, return_amt#8382, net_loss#8383)
    int r = 0;
    int row0 = tbl_Project_TD_10341667_output.getNumRow();
    for (int i = 0; i < row0; i++) {
        tbl_Union_TD_9523992_output.setInt32(r, 0, tbl_Project_TD_10341667_output.getInt32(i, 0));
        tbl_Union_TD_9523992_output.setInt32(r, 1, tbl_Project_TD_10341667_output.getInt32(i, 1));
        tbl_Union_TD_9523992_output.setInt32(r, 2, tbl_Project_TD_10341667_output.getInt64(i, 2));
        tbl_Union_TD_9523992_output.setInt32(r, 3, tbl_Project_TD_10341667_output.getInt64(i, 3));
        tbl_Union_TD_9523992_output.setInt32(r, 4, tbl_Project_TD_10341667_output.getInt64(i, 4));
        tbl_Union_TD_9523992_output.setInt32(r, 5, tbl_Project_TD_10341667_output.getInt64(i, 5));
        ++r;
    }
    int row1 = tbl_Project_TD_10240760_output.getNumRow();
    for (int i = 0; i < row1; i++) {
        tbl_Union_TD_9523992_output.setInt32(r, 0, tbl_Project_TD_10240760_output.getInt32(i, 0));
        tbl_Union_TD_9523992_output.setInt32(r, 1, tbl_Project_TD_10240760_output.getInt32(i, 1));
        tbl_Union_TD_9523992_output.setInt32(r, 2, tbl_Project_TD_10240760_output.getInt64(i, 2));
        tbl_Union_TD_9523992_output.setInt32(r, 3, tbl_Project_TD_10240760_output.getInt64(i, 3));
        tbl_Union_TD_9523992_output.setInt32(r, 4, tbl_Project_TD_10240760_output.getInt64(i, 4));
        tbl_Union_TD_9523992_output.setInt32(r, 5, tbl_Project_TD_10240760_output.getInt64(i, 5));
        ++r;
    }
    tbl_Union_TD_9523992_output.setNumRow(r);
    std::cout << "tbl_Union_TD_9523992_output #Row: " << tbl_Union_TD_9523992_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8928910(Table &tbl_SerializeFromObject_TD_9886392_input, Table &tbl_Filter_TD_8928910_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(web_site_sk#537))
    // Input: ListBuffer(web_site_sk#537, web_site_id#538)
    // Output: ListBuffer(web_site_sk#537, web_site_id#538)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9886392_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _web_site_sk537 = tbl_SerializeFromObject_TD_9886392_input.getInt32(i, 0);
        if (_web_site_sk537!= 0) {
            int32_t _web_site_sk537_t = tbl_SerializeFromObject_TD_9886392_input.getInt32(i, 0);
            tbl_Filter_TD_8928910_output.setInt32(r, 0, _web_site_sk537_t);
            std::array<char, TPCDS_READ_MAX + 1> _web_site_id538_t = tbl_SerializeFromObject_TD_9886392_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_8928910_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _web_site_id538_t);
            r++;
        }
    }
    tbl_Filter_TD_8928910_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8928910_output #Row: " << tbl_Filter_TD_8928910_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8828693_key_leftMajor {
    int32_t _date_sk8411;
    bool operator==(const SW_JOIN_INNER_TD_8828693_key_leftMajor& other) const {
        return ((_date_sk8411 == other._date_sk8411));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8828693_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8828693_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._date_sk8411));
    }
};
}
struct SW_JOIN_INNER_TD_8828693_payload_leftMajor {
    int32_t _wsr_web_site_sk8410;
    int32_t _date_sk8411;
    int64_t _sales_price8412;
    int64_t _profit8413;
    int64_t _return_amt8414;
    int64_t _net_loss8415;
};
struct SW_JOIN_INNER_TD_8828693_key_rightMajor {
    int32_t _d_date_sk8488;
    bool operator==(const SW_JOIN_INNER_TD_8828693_key_rightMajor& other) const {
        return ((_d_date_sk8488 == other._d_date_sk8488));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8828693_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8828693_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk8488));
    }
};
}
struct SW_JOIN_INNER_TD_8828693_payload_rightMajor {
    int32_t _d_date_sk8488;
};
void SW_JOIN_INNER_TD_8828693(Table &tbl_Union_TD_980579_output, Table &tbl_Filter_TD_9834949_output, Table &tbl_JOIN_INNER_TD_8828693_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((date_sk#8411 = d_date_sk#8488))
    // Left Table: ListBuffer(wsr_web_site_sk#8410, date_sk#8411, sales_price#8412, profit#8413, return_amt#8414, net_loss#8415)
    // Right Table: ListBuffer(d_date_sk#8488)
    // Output Table: ListBuffer(wsr_web_site_sk#8410, sales_price#8412, profit#8413, return_amt#8414, net_loss#8415)
    int left_nrow = tbl_Union_TD_980579_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9834949_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8828693_key_leftMajor, SW_JOIN_INNER_TD_8828693_payload_leftMajor> ht1;
        int nrow1 = tbl_Union_TD_980579_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _date_sk8411_k = tbl_Union_TD_980579_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_8828693_key_leftMajor keyA{_date_sk8411_k};
            int32_t _wsr_web_site_sk8410 = tbl_Union_TD_980579_output.getInt32(i, 0);
            int32_t _date_sk8411 = tbl_Union_TD_980579_output.getInt32(i, 1);
            int64_t _sales_price8412 = tbl_Union_TD_980579_output.getInt64(i, 2);
            int64_t _profit8413 = tbl_Union_TD_980579_output.getInt64(i, 3);
            int64_t _return_amt8414 = tbl_Union_TD_980579_output.getInt64(i, 4);
            int64_t _net_loss8415 = tbl_Union_TD_980579_output.getInt64(i, 5);
            SW_JOIN_INNER_TD_8828693_payload_leftMajor payloadA{_wsr_web_site_sk8410, _date_sk8411, _sales_price8412, _profit8413, _return_amt8414, _net_loss8415};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9834949_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk8488_k = tbl_Filter_TD_9834949_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8828693_key_leftMajor{_d_date_sk8488_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _wsr_web_site_sk8410 = (it->second)._wsr_web_site_sk8410;
                int32_t _date_sk8411 = (it->second)._date_sk8411;
                int64_t _sales_price8412 = (it->second)._sales_price8412;
                int64_t _profit8413 = (it->second)._profit8413;
                int64_t _return_amt8414 = (it->second)._return_amt8414;
                int64_t _net_loss8415 = (it->second)._net_loss8415;
                int32_t _d_date_sk8488 = tbl_Filter_TD_9834949_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_8828693_output.setInt32(r, 0, _wsr_web_site_sk8410);
                tbl_JOIN_INNER_TD_8828693_output.setInt64(r, 1, _sales_price8412);
                tbl_JOIN_INNER_TD_8828693_output.setInt64(r, 2, _profit8413);
                tbl_JOIN_INNER_TD_8828693_output.setInt64(r, 3, _return_amt8414);
                tbl_JOIN_INNER_TD_8828693_output.setInt64(r, 4, _net_loss8415);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8828693_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8828693_key_rightMajor, SW_JOIN_INNER_TD_8828693_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9834949_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk8488_k = tbl_Filter_TD_9834949_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8828693_key_rightMajor keyA{_d_date_sk8488_k};
            int32_t _d_date_sk8488 = tbl_Filter_TD_9834949_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8828693_payload_rightMajor payloadA{_d_date_sk8488};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Union_TD_980579_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _date_sk8411_k = tbl_Union_TD_980579_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8828693_key_rightMajor{_date_sk8411_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk8488 = (it->second)._d_date_sk8488;
                int32_t _wsr_web_site_sk8410 = tbl_Union_TD_980579_output.getInt32(i, 0);
                int32_t _date_sk8411 = tbl_Union_TD_980579_output.getInt32(i, 1);
                int64_t _sales_price8412 = tbl_Union_TD_980579_output.getInt64(i, 2);
                int64_t _profit8413 = tbl_Union_TD_980579_output.getInt64(i, 3);
                int64_t _return_amt8414 = tbl_Union_TD_980579_output.getInt64(i, 4);
                int64_t _net_loss8415 = tbl_Union_TD_980579_output.getInt64(i, 5);
                tbl_JOIN_INNER_TD_8828693_output.setInt32(r, 0, _wsr_web_site_sk8410);
                tbl_JOIN_INNER_TD_8828693_output.setInt64(r, 1, _sales_price8412);
                tbl_JOIN_INNER_TD_8828693_output.setInt64(r, 2, _profit8413);
                tbl_JOIN_INNER_TD_8828693_output.setInt64(r, 3, _return_amt8414);
                tbl_JOIN_INNER_TD_8828693_output.setInt64(r, 4, _net_loss8415);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8828693_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8828693_output #Row: " << tbl_JOIN_INNER_TD_8828693_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8670372(Table &tbl_SerializeFromObject_TD_9541220_input, Table &tbl_Filter_TD_8670372_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(cp_catalog_page_sk#996))
    // Input: ListBuffer(cp_catalog_page_sk#996, cp_catalog_page_id#997)
    // Output: ListBuffer(cp_catalog_page_sk#996, cp_catalog_page_id#997)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9541220_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cp_catalog_page_sk996 = tbl_SerializeFromObject_TD_9541220_input.getInt32(i, 0);
        if (_cp_catalog_page_sk996!= 0) {
            int32_t _cp_catalog_page_sk996_t = tbl_SerializeFromObject_TD_9541220_input.getInt32(i, 0);
            tbl_Filter_TD_8670372_output.setInt32(r, 0, _cp_catalog_page_sk996_t);
            std::array<char, TPCDS_READ_MAX + 1> _cp_catalog_page_id997_t = tbl_SerializeFromObject_TD_9541220_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_8670372_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cp_catalog_page_id997_t);
            r++;
        }
    }
    tbl_Filter_TD_8670372_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8670372_output #Row: " << tbl_Filter_TD_8670372_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8779433_key_leftMajor {
    int32_t _date_sk8395;
    bool operator==(const SW_JOIN_INNER_TD_8779433_key_leftMajor& other) const {
        return ((_date_sk8395 == other._date_sk8395));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8779433_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8779433_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._date_sk8395));
    }
};
}
struct SW_JOIN_INNER_TD_8779433_payload_leftMajor {
    int32_t _page_sk8394;
    int32_t _date_sk8395;
    int64_t _sales_price8396;
    int64_t _profit8397;
    int64_t _return_amt8398;
    int64_t _net_loss8399;
};
struct SW_JOIN_INNER_TD_8779433_key_rightMajor {
    int32_t _d_date_sk8426;
    bool operator==(const SW_JOIN_INNER_TD_8779433_key_rightMajor& other) const {
        return ((_d_date_sk8426 == other._d_date_sk8426));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8779433_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8779433_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk8426));
    }
};
}
struct SW_JOIN_INNER_TD_8779433_payload_rightMajor {
    int32_t _d_date_sk8426;
};
void SW_JOIN_INNER_TD_8779433(Table &tbl_Union_TD_9812863_output, Table &tbl_Filter_TD_9539098_output, Table &tbl_JOIN_INNER_TD_8779433_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((date_sk#8395 = d_date_sk#8426))
    // Left Table: ListBuffer(page_sk#8394, date_sk#8395, sales_price#8396, profit#8397, return_amt#8398, net_loss#8399)
    // Right Table: ListBuffer(d_date_sk#8426)
    // Output Table: ListBuffer(page_sk#8394, sales_price#8396, profit#8397, return_amt#8398, net_loss#8399)
    int left_nrow = tbl_Union_TD_9812863_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9539098_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8779433_key_leftMajor, SW_JOIN_INNER_TD_8779433_payload_leftMajor> ht1;
        int nrow1 = tbl_Union_TD_9812863_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _date_sk8395_k = tbl_Union_TD_9812863_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_8779433_key_leftMajor keyA{_date_sk8395_k};
            int32_t _page_sk8394 = tbl_Union_TD_9812863_output.getInt32(i, 0);
            int32_t _date_sk8395 = tbl_Union_TD_9812863_output.getInt32(i, 1);
            int64_t _sales_price8396 = tbl_Union_TD_9812863_output.getInt64(i, 2);
            int64_t _profit8397 = tbl_Union_TD_9812863_output.getInt64(i, 3);
            int64_t _return_amt8398 = tbl_Union_TD_9812863_output.getInt64(i, 4);
            int64_t _net_loss8399 = tbl_Union_TD_9812863_output.getInt64(i, 5);
            SW_JOIN_INNER_TD_8779433_payload_leftMajor payloadA{_page_sk8394, _date_sk8395, _sales_price8396, _profit8397, _return_amt8398, _net_loss8399};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9539098_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk8426_k = tbl_Filter_TD_9539098_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8779433_key_leftMajor{_d_date_sk8426_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _page_sk8394 = (it->second)._page_sk8394;
                int32_t _date_sk8395 = (it->second)._date_sk8395;
                int64_t _sales_price8396 = (it->second)._sales_price8396;
                int64_t _profit8397 = (it->second)._profit8397;
                int64_t _return_amt8398 = (it->second)._return_amt8398;
                int64_t _net_loss8399 = (it->second)._net_loss8399;
                int32_t _d_date_sk8426 = tbl_Filter_TD_9539098_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_8779433_output.setInt32(r, 0, _page_sk8394);
                tbl_JOIN_INNER_TD_8779433_output.setInt64(r, 1, _sales_price8396);
                tbl_JOIN_INNER_TD_8779433_output.setInt64(r, 2, _profit8397);
                tbl_JOIN_INNER_TD_8779433_output.setInt64(r, 3, _return_amt8398);
                tbl_JOIN_INNER_TD_8779433_output.setInt64(r, 4, _net_loss8399);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8779433_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8779433_key_rightMajor, SW_JOIN_INNER_TD_8779433_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9539098_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk8426_k = tbl_Filter_TD_9539098_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8779433_key_rightMajor keyA{_d_date_sk8426_k};
            int32_t _d_date_sk8426 = tbl_Filter_TD_9539098_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8779433_payload_rightMajor payloadA{_d_date_sk8426};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Union_TD_9812863_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _date_sk8395_k = tbl_Union_TD_9812863_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8779433_key_rightMajor{_date_sk8395_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk8426 = (it->second)._d_date_sk8426;
                int32_t _page_sk8394 = tbl_Union_TD_9812863_output.getInt32(i, 0);
                int32_t _date_sk8395 = tbl_Union_TD_9812863_output.getInt32(i, 1);
                int64_t _sales_price8396 = tbl_Union_TD_9812863_output.getInt64(i, 2);
                int64_t _profit8397 = tbl_Union_TD_9812863_output.getInt64(i, 3);
                int64_t _return_amt8398 = tbl_Union_TD_9812863_output.getInt64(i, 4);
                int64_t _net_loss8399 = tbl_Union_TD_9812863_output.getInt64(i, 5);
                tbl_JOIN_INNER_TD_8779433_output.setInt32(r, 0, _page_sk8394);
                tbl_JOIN_INNER_TD_8779433_output.setInt64(r, 1, _sales_price8396);
                tbl_JOIN_INNER_TD_8779433_output.setInt64(r, 2, _profit8397);
                tbl_JOIN_INNER_TD_8779433_output.setInt64(r, 3, _return_amt8398);
                tbl_JOIN_INNER_TD_8779433_output.setInt64(r, 4, _net_loss8399);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8779433_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8779433_output #Row: " << tbl_JOIN_INNER_TD_8779433_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8378457(Table &tbl_SerializeFromObject_TD_9326199_input, Table &tbl_Filter_TD_8378457_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(s_store_sk#378))
    // Input: ListBuffer(s_store_sk#378, s_store_id#379)
    // Output: ListBuffer(s_store_sk#378, s_store_id#379)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9326199_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _s_store_sk378 = tbl_SerializeFromObject_TD_9326199_input.getInt32(i, 0);
        if (_s_store_sk378!= 0) {
            int32_t _s_store_sk378_t = tbl_SerializeFromObject_TD_9326199_input.getInt32(i, 0);
            tbl_Filter_TD_8378457_output.setInt32(r, 0, _s_store_sk378_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_t = tbl_SerializeFromObject_TD_9326199_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_8378457_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_store_id379_t);
            r++;
        }
    }
    tbl_Filter_TD_8378457_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8378457_output #Row: " << tbl_Filter_TD_8378457_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8825954_key_leftMajor {
    int32_t _date_sk8379;
    bool operator==(const SW_JOIN_INNER_TD_8825954_key_leftMajor& other) const {
        return ((_date_sk8379 == other._date_sk8379));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8825954_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8825954_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._date_sk8379));
    }
};
}
struct SW_JOIN_INNER_TD_8825954_payload_leftMajor {
    int32_t _store_sk8378;
    int32_t _date_sk8379;
    int64_t _sales_price8380;
    int64_t _profit8381;
    int64_t _return_amt8382;
    int64_t _net_loss8383;
};
struct SW_JOIN_INNER_TD_8825954_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_8825954_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8825954_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8825954_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_8825954_payload_rightMajor {
    int32_t _d_date_sk120;
};
void SW_JOIN_INNER_TD_8825954(Table &tbl_Union_TD_9523992_output, Table &tbl_Filter_TD_9561562_output, Table &tbl_JOIN_INNER_TD_8825954_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((date_sk#8379 = d_date_sk#120))
    // Left Table: ListBuffer(store_sk#8378, date_sk#8379, sales_price#8380, profit#8381, return_amt#8382, net_loss#8383)
    // Right Table: ListBuffer(d_date_sk#120)
    // Output Table: ListBuffer(store_sk#8378, sales_price#8380, profit#8381, return_amt#8382, net_loss#8383)
    int left_nrow = tbl_Union_TD_9523992_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9561562_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8825954_key_leftMajor, SW_JOIN_INNER_TD_8825954_payload_leftMajor> ht1;
        int nrow1 = tbl_Union_TD_9523992_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _date_sk8379_k = tbl_Union_TD_9523992_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_8825954_key_leftMajor keyA{_date_sk8379_k};
            int32_t _store_sk8378 = tbl_Union_TD_9523992_output.getInt32(i, 0);
            int32_t _date_sk8379 = tbl_Union_TD_9523992_output.getInt32(i, 1);
            int64_t _sales_price8380 = tbl_Union_TD_9523992_output.getInt64(i, 2);
            int64_t _profit8381 = tbl_Union_TD_9523992_output.getInt64(i, 3);
            int64_t _return_amt8382 = tbl_Union_TD_9523992_output.getInt64(i, 4);
            int64_t _net_loss8383 = tbl_Union_TD_9523992_output.getInt64(i, 5);
            SW_JOIN_INNER_TD_8825954_payload_leftMajor payloadA{_store_sk8378, _date_sk8379, _sales_price8380, _profit8381, _return_amt8382, _net_loss8383};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9561562_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_9561562_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8825954_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _store_sk8378 = (it->second)._store_sk8378;
                int32_t _date_sk8379 = (it->second)._date_sk8379;
                int64_t _sales_price8380 = (it->second)._sales_price8380;
                int64_t _profit8381 = (it->second)._profit8381;
                int64_t _return_amt8382 = (it->second)._return_amt8382;
                int64_t _net_loss8383 = (it->second)._net_loss8383;
                int32_t _d_date_sk120 = tbl_Filter_TD_9561562_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_8825954_output.setInt32(r, 0, _store_sk8378);
                tbl_JOIN_INNER_TD_8825954_output.setInt64(r, 1, _sales_price8380);
                tbl_JOIN_INNER_TD_8825954_output.setInt64(r, 2, _profit8381);
                tbl_JOIN_INNER_TD_8825954_output.setInt64(r, 3, _return_amt8382);
                tbl_JOIN_INNER_TD_8825954_output.setInt64(r, 4, _net_loss8383);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8825954_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8825954_key_rightMajor, SW_JOIN_INNER_TD_8825954_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9561562_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_9561562_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8825954_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_9561562_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8825954_payload_rightMajor payloadA{_d_date_sk120};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Union_TD_9523992_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _date_sk8379_k = tbl_Union_TD_9523992_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8825954_key_rightMajor{_date_sk8379_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _store_sk8378 = tbl_Union_TD_9523992_output.getInt32(i, 0);
                int32_t _date_sk8379 = tbl_Union_TD_9523992_output.getInt32(i, 1);
                int64_t _sales_price8380 = tbl_Union_TD_9523992_output.getInt64(i, 2);
                int64_t _profit8381 = tbl_Union_TD_9523992_output.getInt64(i, 3);
                int64_t _return_amt8382 = tbl_Union_TD_9523992_output.getInt64(i, 4);
                int64_t _net_loss8383 = tbl_Union_TD_9523992_output.getInt64(i, 5);
                tbl_JOIN_INNER_TD_8825954_output.setInt32(r, 0, _store_sk8378);
                tbl_JOIN_INNER_TD_8825954_output.setInt64(r, 1, _sales_price8380);
                tbl_JOIN_INNER_TD_8825954_output.setInt64(r, 2, _profit8381);
                tbl_JOIN_INNER_TD_8825954_output.setInt64(r, 3, _return_amt8382);
                tbl_JOIN_INNER_TD_8825954_output.setInt64(r, 4, _net_loss8383);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8825954_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8825954_output #Row: " << tbl_JOIN_INNER_TD_8825954_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_7603722_key_leftMajor {
    int32_t _wsr_web_site_sk8410;
    bool operator==(const SW_JOIN_INNER_TD_7603722_key_leftMajor& other) const {
        return ((_wsr_web_site_sk8410 == other._wsr_web_site_sk8410));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7603722_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7603722_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._wsr_web_site_sk8410));
    }
};
}
struct SW_JOIN_INNER_TD_7603722_payload_leftMajor {
    int32_t _wsr_web_site_sk8410;
    int64_t _sales_price8412;
    int64_t _profit8413;
    int64_t _return_amt8414;
    int64_t _net_loss8415;
};
struct SW_JOIN_INNER_TD_7603722_key_rightMajor {
    int32_t _web_site_sk537;
    bool operator==(const SW_JOIN_INNER_TD_7603722_key_rightMajor& other) const {
        return ((_web_site_sk537 == other._web_site_sk537));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7603722_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7603722_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._web_site_sk537));
    }
};
}
struct SW_JOIN_INNER_TD_7603722_payload_rightMajor {
    int32_t _web_site_sk537;
    std::string _web_site_id538;
};
void SW_JOIN_INNER_TD_7603722(Table &tbl_JOIN_INNER_TD_8828693_output, Table &tbl_Filter_TD_8928910_output, Table &tbl_JOIN_INNER_TD_7603722_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((wsr_web_site_sk#8410 = web_site_sk#537))
    // Left Table: ListBuffer(wsr_web_site_sk#8410, sales_price#8412, profit#8413, return_amt#8414, net_loss#8415)
    // Right Table: ListBuffer(web_site_sk#537, web_site_id#538)
    // Output Table: ListBuffer(sales_price#8412, profit#8413, return_amt#8414, net_loss#8415, web_site_id#538)
    int left_nrow = tbl_JOIN_INNER_TD_8828693_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8928910_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7603722_key_leftMajor, SW_JOIN_INNER_TD_7603722_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_8828693_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _wsr_web_site_sk8410_k = tbl_JOIN_INNER_TD_8828693_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7603722_key_leftMajor keyA{_wsr_web_site_sk8410_k};
            int32_t _wsr_web_site_sk8410 = tbl_JOIN_INNER_TD_8828693_output.getInt32(i, 0);
            int64_t _sales_price8412 = tbl_JOIN_INNER_TD_8828693_output.getInt64(i, 1);
            int64_t _profit8413 = tbl_JOIN_INNER_TD_8828693_output.getInt64(i, 2);
            int64_t _return_amt8414 = tbl_JOIN_INNER_TD_8828693_output.getInt64(i, 3);
            int64_t _net_loss8415 = tbl_JOIN_INNER_TD_8828693_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_7603722_payload_leftMajor payloadA{_wsr_web_site_sk8410, _sales_price8412, _profit8413, _return_amt8414, _net_loss8415};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8928910_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _web_site_sk537_k = tbl_Filter_TD_8928910_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7603722_key_leftMajor{_web_site_sk537_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _wsr_web_site_sk8410 = (it->second)._wsr_web_site_sk8410;
                int64_t _sales_price8412 = (it->second)._sales_price8412;
                int64_t _profit8413 = (it->second)._profit8413;
                int64_t _return_amt8414 = (it->second)._return_amt8414;
                int64_t _net_loss8415 = (it->second)._net_loss8415;
                int32_t _web_site_sk537 = tbl_Filter_TD_8928910_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _web_site_id538_n = tbl_Filter_TD_8928910_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _web_site_id538 = std::string(_web_site_id538_n.data());
                tbl_JOIN_INNER_TD_7603722_output.setInt64(r, 0, _sales_price8412);
                tbl_JOIN_INNER_TD_7603722_output.setInt64(r, 1, _profit8413);
                tbl_JOIN_INNER_TD_7603722_output.setInt64(r, 2, _return_amt8414);
                tbl_JOIN_INNER_TD_7603722_output.setInt64(r, 3, _net_loss8415);
                tbl_JOIN_INNER_TD_7603722_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _web_site_id538_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7603722_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7603722_key_rightMajor, SW_JOIN_INNER_TD_7603722_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8928910_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _web_site_sk537_k = tbl_Filter_TD_8928910_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7603722_key_rightMajor keyA{_web_site_sk537_k};
            int32_t _web_site_sk537 = tbl_Filter_TD_8928910_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _web_site_id538_n = tbl_Filter_TD_8928910_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _web_site_id538 = std::string(_web_site_id538_n.data());
            SW_JOIN_INNER_TD_7603722_payload_rightMajor payloadA{_web_site_sk537, _web_site_id538};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_8828693_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _wsr_web_site_sk8410_k = tbl_JOIN_INNER_TD_8828693_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7603722_key_rightMajor{_wsr_web_site_sk8410_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _web_site_sk537 = (it->second)._web_site_sk537;
                std::string _web_site_id538 = (it->second)._web_site_id538;
                std::array<char, TPCDS_READ_MAX + 1> _web_site_id538_n{};
                memcpy(_web_site_id538_n.data(), (_web_site_id538).data(), (_web_site_id538).length());
                int32_t _wsr_web_site_sk8410 = tbl_JOIN_INNER_TD_8828693_output.getInt32(i, 0);
                int64_t _sales_price8412 = tbl_JOIN_INNER_TD_8828693_output.getInt64(i, 1);
                int64_t _profit8413 = tbl_JOIN_INNER_TD_8828693_output.getInt64(i, 2);
                int64_t _return_amt8414 = tbl_JOIN_INNER_TD_8828693_output.getInt64(i, 3);
                int64_t _net_loss8415 = tbl_JOIN_INNER_TD_8828693_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_7603722_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _web_site_id538_n);
                tbl_JOIN_INNER_TD_7603722_output.setInt64(r, 0, _sales_price8412);
                tbl_JOIN_INNER_TD_7603722_output.setInt64(r, 1, _profit8413);
                tbl_JOIN_INNER_TD_7603722_output.setInt64(r, 2, _return_amt8414);
                tbl_JOIN_INNER_TD_7603722_output.setInt64(r, 3, _net_loss8415);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7603722_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7603722_output #Row: " << tbl_JOIN_INNER_TD_7603722_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_7797349_key_leftMajor {
    int32_t _page_sk8394;
    bool operator==(const SW_JOIN_INNER_TD_7797349_key_leftMajor& other) const {
        return ((_page_sk8394 == other._page_sk8394));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7797349_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7797349_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._page_sk8394));
    }
};
}
struct SW_JOIN_INNER_TD_7797349_payload_leftMajor {
    int32_t _page_sk8394;
    int64_t _sales_price8396;
    int64_t _profit8397;
    int64_t _return_amt8398;
    int64_t _net_loss8399;
};
struct SW_JOIN_INNER_TD_7797349_key_rightMajor {
    int32_t _cp_catalog_page_sk996;
    bool operator==(const SW_JOIN_INNER_TD_7797349_key_rightMajor& other) const {
        return ((_cp_catalog_page_sk996 == other._cp_catalog_page_sk996));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7797349_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7797349_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cp_catalog_page_sk996));
    }
};
}
struct SW_JOIN_INNER_TD_7797349_payload_rightMajor {
    int32_t _cp_catalog_page_sk996;
    std::string _cp_catalog_page_id997;
};
void SW_JOIN_INNER_TD_7797349(Table &tbl_JOIN_INNER_TD_8779433_output, Table &tbl_Filter_TD_8670372_output, Table &tbl_JOIN_INNER_TD_7797349_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((page_sk#8394 = cp_catalog_page_sk#996))
    // Left Table: ListBuffer(page_sk#8394, sales_price#8396, profit#8397, return_amt#8398, net_loss#8399)
    // Right Table: ListBuffer(cp_catalog_page_sk#996, cp_catalog_page_id#997)
    // Output Table: ListBuffer(sales_price#8396, profit#8397, return_amt#8398, net_loss#8399, cp_catalog_page_id#997)
    int left_nrow = tbl_JOIN_INNER_TD_8779433_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8670372_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7797349_key_leftMajor, SW_JOIN_INNER_TD_7797349_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_8779433_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _page_sk8394_k = tbl_JOIN_INNER_TD_8779433_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7797349_key_leftMajor keyA{_page_sk8394_k};
            int32_t _page_sk8394 = tbl_JOIN_INNER_TD_8779433_output.getInt32(i, 0);
            int64_t _sales_price8396 = tbl_JOIN_INNER_TD_8779433_output.getInt64(i, 1);
            int64_t _profit8397 = tbl_JOIN_INNER_TD_8779433_output.getInt64(i, 2);
            int64_t _return_amt8398 = tbl_JOIN_INNER_TD_8779433_output.getInt64(i, 3);
            int64_t _net_loss8399 = tbl_JOIN_INNER_TD_8779433_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_7797349_payload_leftMajor payloadA{_page_sk8394, _sales_price8396, _profit8397, _return_amt8398, _net_loss8399};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8670372_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cp_catalog_page_sk996_k = tbl_Filter_TD_8670372_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7797349_key_leftMajor{_cp_catalog_page_sk996_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _page_sk8394 = (it->second)._page_sk8394;
                int64_t _sales_price8396 = (it->second)._sales_price8396;
                int64_t _profit8397 = (it->second)._profit8397;
                int64_t _return_amt8398 = (it->second)._return_amt8398;
                int64_t _net_loss8399 = (it->second)._net_loss8399;
                int32_t _cp_catalog_page_sk996 = tbl_Filter_TD_8670372_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _cp_catalog_page_id997_n = tbl_Filter_TD_8670372_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _cp_catalog_page_id997 = std::string(_cp_catalog_page_id997_n.data());
                tbl_JOIN_INNER_TD_7797349_output.setInt64(r, 0, _sales_price8396);
                tbl_JOIN_INNER_TD_7797349_output.setInt64(r, 1, _profit8397);
                tbl_JOIN_INNER_TD_7797349_output.setInt64(r, 2, _return_amt8398);
                tbl_JOIN_INNER_TD_7797349_output.setInt64(r, 3, _net_loss8399);
                tbl_JOIN_INNER_TD_7797349_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _cp_catalog_page_id997_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7797349_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7797349_key_rightMajor, SW_JOIN_INNER_TD_7797349_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8670372_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cp_catalog_page_sk996_k = tbl_Filter_TD_8670372_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7797349_key_rightMajor keyA{_cp_catalog_page_sk996_k};
            int32_t _cp_catalog_page_sk996 = tbl_Filter_TD_8670372_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _cp_catalog_page_id997_n = tbl_Filter_TD_8670372_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cp_catalog_page_id997 = std::string(_cp_catalog_page_id997_n.data());
            SW_JOIN_INNER_TD_7797349_payload_rightMajor payloadA{_cp_catalog_page_sk996, _cp_catalog_page_id997};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_8779433_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _page_sk8394_k = tbl_JOIN_INNER_TD_8779433_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7797349_key_rightMajor{_page_sk8394_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cp_catalog_page_sk996 = (it->second)._cp_catalog_page_sk996;
                std::string _cp_catalog_page_id997 = (it->second)._cp_catalog_page_id997;
                std::array<char, TPCDS_READ_MAX + 1> _cp_catalog_page_id997_n{};
                memcpy(_cp_catalog_page_id997_n.data(), (_cp_catalog_page_id997).data(), (_cp_catalog_page_id997).length());
                int32_t _page_sk8394 = tbl_JOIN_INNER_TD_8779433_output.getInt32(i, 0);
                int64_t _sales_price8396 = tbl_JOIN_INNER_TD_8779433_output.getInt64(i, 1);
                int64_t _profit8397 = tbl_JOIN_INNER_TD_8779433_output.getInt64(i, 2);
                int64_t _return_amt8398 = tbl_JOIN_INNER_TD_8779433_output.getInt64(i, 3);
                int64_t _net_loss8399 = tbl_JOIN_INNER_TD_8779433_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_7797349_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _cp_catalog_page_id997_n);
                tbl_JOIN_INNER_TD_7797349_output.setInt64(r, 0, _sales_price8396);
                tbl_JOIN_INNER_TD_7797349_output.setInt64(r, 1, _profit8397);
                tbl_JOIN_INNER_TD_7797349_output.setInt64(r, 2, _return_amt8398);
                tbl_JOIN_INNER_TD_7797349_output.setInt64(r, 3, _net_loss8399);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7797349_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7797349_output #Row: " << tbl_JOIN_INNER_TD_7797349_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_7904255_key_leftMajor {
    int32_t _store_sk8378;
    bool operator==(const SW_JOIN_INNER_TD_7904255_key_leftMajor& other) const {
        return ((_store_sk8378 == other._store_sk8378));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7904255_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7904255_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._store_sk8378));
    }
};
}
struct SW_JOIN_INNER_TD_7904255_payload_leftMajor {
    int32_t _store_sk8378;
    int64_t _sales_price8380;
    int64_t _profit8381;
    int64_t _return_amt8382;
    int64_t _net_loss8383;
};
struct SW_JOIN_INNER_TD_7904255_key_rightMajor {
    int32_t _s_store_sk378;
    bool operator==(const SW_JOIN_INNER_TD_7904255_key_rightMajor& other) const {
        return ((_s_store_sk378 == other._s_store_sk378));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7904255_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7904255_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_store_sk378));
    }
};
}
struct SW_JOIN_INNER_TD_7904255_payload_rightMajor {
    int32_t _s_store_sk378;
    std::string _s_store_id379;
};
void SW_JOIN_INNER_TD_7904255(Table &tbl_JOIN_INNER_TD_8825954_output, Table &tbl_Filter_TD_8378457_output, Table &tbl_JOIN_INNER_TD_7904255_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((store_sk#8378 = s_store_sk#378))
    // Left Table: ListBuffer(store_sk#8378, sales_price#8380, profit#8381, return_amt#8382, net_loss#8383)
    // Right Table: ListBuffer(s_store_sk#378, s_store_id#379)
    // Output Table: ListBuffer(sales_price#8380, profit#8381, return_amt#8382, net_loss#8383, s_store_id#379)
    int left_nrow = tbl_JOIN_INNER_TD_8825954_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8378457_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7904255_key_leftMajor, SW_JOIN_INNER_TD_7904255_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_8825954_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _store_sk8378_k = tbl_JOIN_INNER_TD_8825954_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7904255_key_leftMajor keyA{_store_sk8378_k};
            int32_t _store_sk8378 = tbl_JOIN_INNER_TD_8825954_output.getInt32(i, 0);
            int64_t _sales_price8380 = tbl_JOIN_INNER_TD_8825954_output.getInt64(i, 1);
            int64_t _profit8381 = tbl_JOIN_INNER_TD_8825954_output.getInt64(i, 2);
            int64_t _return_amt8382 = tbl_JOIN_INNER_TD_8825954_output.getInt64(i, 3);
            int64_t _net_loss8383 = tbl_JOIN_INNER_TD_8825954_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_7904255_payload_leftMajor payloadA{_store_sk8378, _sales_price8380, _profit8381, _return_amt8382, _net_loss8383};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8378457_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_8378457_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7904255_key_leftMajor{_s_store_sk378_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _store_sk8378 = (it->second)._store_sk8378;
                int64_t _sales_price8380 = (it->second)._sales_price8380;
                int64_t _profit8381 = (it->second)._profit8381;
                int64_t _return_amt8382 = (it->second)._return_amt8382;
                int64_t _net_loss8383 = (it->second)._net_loss8383;
                int32_t _s_store_sk378 = tbl_Filter_TD_8378457_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_n = tbl_Filter_TD_8378457_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _s_store_id379 = std::string(_s_store_id379_n.data());
                tbl_JOIN_INNER_TD_7904255_output.setInt64(r, 0, _sales_price8380);
                tbl_JOIN_INNER_TD_7904255_output.setInt64(r, 1, _profit8381);
                tbl_JOIN_INNER_TD_7904255_output.setInt64(r, 2, _return_amt8382);
                tbl_JOIN_INNER_TD_7904255_output.setInt64(r, 3, _net_loss8383);
                tbl_JOIN_INNER_TD_7904255_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _s_store_id379_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7904255_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7904255_key_rightMajor, SW_JOIN_INNER_TD_7904255_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8378457_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_8378457_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7904255_key_rightMajor keyA{_s_store_sk378_k};
            int32_t _s_store_sk378 = tbl_Filter_TD_8378457_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_n = tbl_Filter_TD_8378457_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _s_store_id379 = std::string(_s_store_id379_n.data());
            SW_JOIN_INNER_TD_7904255_payload_rightMajor payloadA{_s_store_sk378, _s_store_id379};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_8825954_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _store_sk8378_k = tbl_JOIN_INNER_TD_8825954_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7904255_key_rightMajor{_store_sk8378_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _s_store_sk378 = (it->second)._s_store_sk378;
                std::string _s_store_id379 = (it->second)._s_store_id379;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_n{};
                memcpy(_s_store_id379_n.data(), (_s_store_id379).data(), (_s_store_id379).length());
                int32_t _store_sk8378 = tbl_JOIN_INNER_TD_8825954_output.getInt32(i, 0);
                int64_t _sales_price8380 = tbl_JOIN_INNER_TD_8825954_output.getInt64(i, 1);
                int64_t _profit8381 = tbl_JOIN_INNER_TD_8825954_output.getInt64(i, 2);
                int64_t _return_amt8382 = tbl_JOIN_INNER_TD_8825954_output.getInt64(i, 3);
                int64_t _net_loss8383 = tbl_JOIN_INNER_TD_8825954_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_7904255_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _s_store_id379_n);
                tbl_JOIN_INNER_TD_7904255_output.setInt64(r, 0, _sales_price8380);
                tbl_JOIN_INNER_TD_7904255_output.setInt64(r, 1, _profit8381);
                tbl_JOIN_INNER_TD_7904255_output.setInt64(r, 2, _return_amt8382);
                tbl_JOIN_INNER_TD_7904255_output.setInt64(r, 3, _net_loss8383);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7904255_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7904255_output #Row: " << tbl_JOIN_INNER_TD_7904255_output.getNumRow() << std::endl;
}

typedef std::string SW_Aggregate_TD_6713678_key;
struct SW_Aggregate_TD_6713678_payload {
    int64_t _sales8422_sum_0;
    int64_t _returns8424_sum_1;
    int64_t _profit8374_sum_2;
    int64_t _profit8374_sum_3;
    std::string _channel8823;
    std::string _id8824;
};
void SW_Aggregate_TD_6713678(Table &tbl_JOIN_INNER_TD_7603722_output, Table &tbl_Aggregate_TD_6713678_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(web_site_id#538, MakeDecimal(sum(UnscaledValue(sales_price#8412)),17,2) AS sales#8422, MakeDecimal(sum(UnscaledValue(return_amt#8414)),17,2) AS returns#8424, CheckOverflow((promote_precision(cast(MakeDecimal(sum(UnscaledValue(profit#8413)),17,2) as decimal(18,2))) - promote_precision(cast(MakeDecimal(sum(UnscaledValue(net_loss#8415)),17,2) as decimal(18,2)))), DecimalType(18,2), true) AS profit#8374, web channel AS channel#8823, concat(web_site, web_site_id#538) AS id#8824)
    // Input: ListBuffer(sales_price#8412, profit#8413, return_amt#8414, net_loss#8415, web_site_id#538)
    // Output: ListBuffer(sales#8422, returns#8424, profit#8374, channel#8823, id#8824)
    std::unordered_map<SW_Aggregate_TD_6713678_key, SW_Aggregate_TD_6713678_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_7603722_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sales_price8412 = tbl_JOIN_INNER_TD_7603722_output.getInt64(i, 0);
        int64_t _profit8413 = tbl_JOIN_INNER_TD_7603722_output.getInt64(i, 1);
        int64_t _return_amt8414 = tbl_JOIN_INNER_TD_7603722_output.getInt64(i, 2);
        int64_t _net_loss8415 = tbl_JOIN_INNER_TD_7603722_output.getInt64(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _web_site_id538 = tbl_JOIN_INNER_TD_7603722_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        SW_Aggregate_TD_6713678_key k = std::string(_web_site_id538.data());
        int64_t _sales8422_sum_0 = _sales_price8412;
        int64_t _returns8424_sum_1 = _return_amt8414;
        int64_t _profit8374_sum_2 = _profit8413;
        int64_t _profit8374_sum_3 = _net_loss8415;
        std::string _channel8823 = "web channel";
        std::string _id8824 = std::string("web_site").append(std::string(_web_site_id538.data()));
        SW_Aggregate_TD_6713678_payload p{_sales8422_sum_0, _returns8424_sum_1, _profit8374_sum_2, _profit8374_sum_3, std::string(_channel8823.data()), std::string(_id8824.data())};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._sales8422_sum_0 + _sales8422_sum_0;
            p._sales8422_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._returns8424_sum_1 + _returns8424_sum_1;
            p._returns8424_sum_1 = sum_1;
            int64_t sum_2 = (it->second)._profit8374_sum_2 + _profit8374_sum_2;
            p._profit8374_sum_2 = sum_2;
            int64_t sum_3 = (it->second)._profit8374_sum_3 + _profit8374_sum_3;
            p._profit8374_sum_3 = sum_3;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _web_site_id538 not required in the output table
        int64_t _sales8422 = (it.second)._sales8422_sum_0;
        tbl_Aggregate_TD_6713678_output.setInt64(r, 0, _sales8422);
        int64_t _returns8424 = (it.second)._returns8424_sum_1;
        tbl_Aggregate_TD_6713678_output.setInt64(r, 1, _returns8424);
        int64_t _profit8374 = ((it.second)._profit8374_sum_2 - (it.second)._profit8374_sum_3);
        tbl_Aggregate_TD_6713678_output.setInt64(r, 2, _profit8374);
        std::array<char, TPCDS_READ_MAX + 1> _channel8823_n{};
        memcpy(_channel8823_n.data(), (it.second)._channel8823.data(), (it.second)._channel8823.length());
        tbl_Aggregate_TD_6713678_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _channel8823_n);
        std::array<char, TPCDS_READ_MAX + 1> _id8824_n{};
        memcpy(_id8824_n.data(), (it.second)._id8824.data(), (it.second)._id8824.length());
        tbl_Aggregate_TD_6713678_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _id8824_n);
        ++r;
    }
    tbl_Aggregate_TD_6713678_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_6713678_output #Row: " << tbl_Aggregate_TD_6713678_output.getNumRow() << std::endl;
}

typedef std::string SW_Aggregate_TD_6302693_key;
struct SW_Aggregate_TD_6302693_payload {
    int64_t _sales8406_sum_0;
    int64_t _returns8408_sum_1;
    int64_t _profit8371_sum_2;
    int64_t _profit8371_sum_3;
    std::string _channel8821;
    std::string _id8822;
};
void SW_Aggregate_TD_6302693(Table &tbl_JOIN_INNER_TD_7797349_output, Table &tbl_Aggregate_TD_6302693_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(cp_catalog_page_id#997, MakeDecimal(sum(UnscaledValue(sales_price#8396)),17,2) AS sales#8406, MakeDecimal(sum(UnscaledValue(return_amt#8398)),17,2) AS returns#8408, CheckOverflow((promote_precision(cast(MakeDecimal(sum(UnscaledValue(profit#8397)),17,2) as decimal(18,2))) - promote_precision(cast(MakeDecimal(sum(UnscaledValue(net_loss#8399)),17,2) as decimal(18,2)))), DecimalType(18,2), true) AS profit#8371, catalog channel AS channel#8821, concat(catalog_page, cp_catalog_page_id#997) AS id#8822)
    // Input: ListBuffer(sales_price#8396, profit#8397, return_amt#8398, net_loss#8399, cp_catalog_page_id#997)
    // Output: ListBuffer(sales#8406, returns#8408, profit#8371, channel#8821, id#8822)
    std::unordered_map<SW_Aggregate_TD_6302693_key, SW_Aggregate_TD_6302693_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_7797349_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sales_price8396 = tbl_JOIN_INNER_TD_7797349_output.getInt64(i, 0);
        int64_t _profit8397 = tbl_JOIN_INNER_TD_7797349_output.getInt64(i, 1);
        int64_t _return_amt8398 = tbl_JOIN_INNER_TD_7797349_output.getInt64(i, 2);
        int64_t _net_loss8399 = tbl_JOIN_INNER_TD_7797349_output.getInt64(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _cp_catalog_page_id997 = tbl_JOIN_INNER_TD_7797349_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        SW_Aggregate_TD_6302693_key k = std::string(_cp_catalog_page_id997.data());
        int64_t _sales8406_sum_0 = _sales_price8396;
        int64_t _returns8408_sum_1 = _return_amt8398;
        int64_t _profit8371_sum_2 = _profit8397;
        int64_t _profit8371_sum_3 = _net_loss8399;
        std::string _channel8821 = "catalog channel";
        std::string _id8822 = std::string("catalog_page").append(std::string(_cp_catalog_page_id997.data()));
        SW_Aggregate_TD_6302693_payload p{_sales8406_sum_0, _returns8408_sum_1, _profit8371_sum_2, _profit8371_sum_3, std::string(_channel8821.data()), std::string(_id8822.data())};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._sales8406_sum_0 + _sales8406_sum_0;
            p._sales8406_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._returns8408_sum_1 + _returns8408_sum_1;
            p._returns8408_sum_1 = sum_1;
            int64_t sum_2 = (it->second)._profit8371_sum_2 + _profit8371_sum_2;
            p._profit8371_sum_2 = sum_2;
            int64_t sum_3 = (it->second)._profit8371_sum_3 + _profit8371_sum_3;
            p._profit8371_sum_3 = sum_3;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _cp_catalog_page_id997 not required in the output table
        int64_t _sales8406 = (it.second)._sales8406_sum_0;
        tbl_Aggregate_TD_6302693_output.setInt64(r, 0, _sales8406);
        int64_t _returns8408 = (it.second)._returns8408_sum_1;
        tbl_Aggregate_TD_6302693_output.setInt64(r, 1, _returns8408);
        int64_t _profit8371 = ((it.second)._profit8371_sum_2 - (it.second)._profit8371_sum_3);
        tbl_Aggregate_TD_6302693_output.setInt64(r, 2, _profit8371);
        std::array<char, TPCDS_READ_MAX + 1> _channel8821_n{};
        memcpy(_channel8821_n.data(), (it.second)._channel8821.data(), (it.second)._channel8821.length());
        tbl_Aggregate_TD_6302693_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _channel8821_n);
        std::array<char, TPCDS_READ_MAX + 1> _id8822_n{};
        memcpy(_id8822_n.data(), (it.second)._id8822.data(), (it.second)._id8822.length());
        tbl_Aggregate_TD_6302693_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _id8822_n);
        ++r;
    }
    tbl_Aggregate_TD_6302693_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_6302693_output #Row: " << tbl_Aggregate_TD_6302693_output.getNumRow() << std::endl;
}

typedef std::string SW_Aggregate_TD_6804953_key;
struct SW_Aggregate_TD_6804953_payload {
    int64_t _sales8390_sum_0;
    int64_t _returns8392_sum_1;
    int64_t _profit8368_sum_2;
    int64_t _profit8368_sum_3;
    std::string _channel8531;
    std::string _id8532;
};
void SW_Aggregate_TD_6804953(Table &tbl_JOIN_INNER_TD_7904255_output, Table &tbl_Aggregate_TD_6804953_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(s_store_id#379, MakeDecimal(sum(UnscaledValue(sales_price#8380)),17,2) AS sales#8390, MakeDecimal(sum(UnscaledValue(return_amt#8382)),17,2) AS returns#8392, CheckOverflow((promote_precision(cast(MakeDecimal(sum(UnscaledValue(profit#8381)),17,2) as decimal(18,2))) - promote_precision(cast(MakeDecimal(sum(UnscaledValue(net_loss#8383)),17,2) as decimal(18,2)))), DecimalType(18,2), true) AS profit#8368, store channel AS channel#8531, concat(store, s_store_id#379) AS id#8532)
    // Input: ListBuffer(sales_price#8380, profit#8381, return_amt#8382, net_loss#8383, s_store_id#379)
    // Output: ListBuffer(sales#8390, returns#8392, profit#8368, channel#8531, id#8532)
    std::unordered_map<SW_Aggregate_TD_6804953_key, SW_Aggregate_TD_6804953_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_7904255_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sales_price8380 = tbl_JOIN_INNER_TD_7904255_output.getInt64(i, 0);
        int64_t _profit8381 = tbl_JOIN_INNER_TD_7904255_output.getInt64(i, 1);
        int64_t _return_amt8382 = tbl_JOIN_INNER_TD_7904255_output.getInt64(i, 2);
        int64_t _net_loss8383 = tbl_JOIN_INNER_TD_7904255_output.getInt64(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_id379 = tbl_JOIN_INNER_TD_7904255_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        SW_Aggregate_TD_6804953_key k = std::string(_s_store_id379.data());
        int64_t _sales8390_sum_0 = _sales_price8380;
        int64_t _returns8392_sum_1 = _return_amt8382;
        int64_t _profit8368_sum_2 = _profit8381;
        int64_t _profit8368_sum_3 = _net_loss8383;
        std::string _channel8531 = "store channel";
        std::string _id8532 = std::string("store").append(std::string(_s_store_id379.data()));
        SW_Aggregate_TD_6804953_payload p{_sales8390_sum_0, _returns8392_sum_1, _profit8368_sum_2, _profit8368_sum_3, std::string(_channel8531.data()), std::string(_id8532.data())};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._sales8390_sum_0 + _sales8390_sum_0;
            p._sales8390_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._returns8392_sum_1 + _returns8392_sum_1;
            p._returns8392_sum_1 = sum_1;
            int64_t sum_2 = (it->second)._profit8368_sum_2 + _profit8368_sum_2;
            p._profit8368_sum_2 = sum_2;
            int64_t sum_3 = (it->second)._profit8368_sum_3 + _profit8368_sum_3;
            p._profit8368_sum_3 = sum_3;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _s_store_id379 not required in the output table
        int64_t _sales8390 = (it.second)._sales8390_sum_0;
        tbl_Aggregate_TD_6804953_output.setInt64(r, 0, _sales8390);
        int64_t _returns8392 = (it.second)._returns8392_sum_1;
        tbl_Aggregate_TD_6804953_output.setInt64(r, 1, _returns8392);
        int64_t _profit8368 = ((it.second)._profit8368_sum_2 - (it.second)._profit8368_sum_3);
        tbl_Aggregate_TD_6804953_output.setInt64(r, 2, _profit8368);
        std::array<char, TPCDS_READ_MAX + 1> _channel8531_n{};
        memcpy(_channel8531_n.data(), (it.second)._channel8531.data(), (it.second)._channel8531.length());
        tbl_Aggregate_TD_6804953_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _channel8531_n);
        std::array<char, TPCDS_READ_MAX + 1> _id8532_n{};
        memcpy(_id8532_n.data(), (it.second)._id8532.data(), (it.second)._id8532.length());
        tbl_Aggregate_TD_6804953_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _id8532_n);
        ++r;
    }
    tbl_Aggregate_TD_6804953_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_6804953_output #Row: " << tbl_Aggregate_TD_6804953_output.getNumRow() << std::endl;
}

void SW_Union_TD_5271381(Table &tbl_Aggregate_TD_6804953_output, Table &tbl_Aggregate_TD_6302693_output, Table &tbl_Aggregate_TD_6713678_output, Table &tbl_Union_TD_5271381_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Union
    // Operation: ListBuffer(List(UNION))
    // Output Table: ListBuffer(sales#8390, returns#8392, profit#8368, channel#8531, id#8532)
    int r = 0;
    int row0 = tbl_Aggregate_TD_6804953_output.getNumRow();
    for (int i = 0; i < row0; i++) {
        tbl_Union_TD_5271381_output.setInt32(r, 0, tbl_Aggregate_TD_6804953_output.getInt64(i, 0));
        tbl_Union_TD_5271381_output.setInt32(r, 1, tbl_Aggregate_TD_6804953_output.getInt64(i, 1));
        tbl_Union_TD_5271381_output.setInt32(r, 2, tbl_Aggregate_TD_6804953_output.getInt64(i, 2));
        std::array<char, TPCDS_READ_MAX + 1> _channel8531_n = tbl_Union_TD_5271381_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_Union_TD_5271381_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _channel8531_n);
        std::array<char, TPCDS_READ_MAX + 1> _id8532_n = tbl_Union_TD_5271381_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        tbl_Union_TD_5271381_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _id8532_n);
        ++r;
    }
    int row1 = tbl_Aggregate_TD_6302693_output.getNumRow();
    for (int i = 0; i < row1; i++) {
        tbl_Union_TD_5271381_output.setInt32(r, 0, tbl_Aggregate_TD_6302693_output.getInt64(i, 0));
        tbl_Union_TD_5271381_output.setInt32(r, 1, tbl_Aggregate_TD_6302693_output.getInt64(i, 1));
        tbl_Union_TD_5271381_output.setInt32(r, 2, tbl_Aggregate_TD_6302693_output.getInt64(i, 2));
        std::array<char, TPCDS_READ_MAX + 1> _channel8821_n = tbl_Union_TD_5271381_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_Union_TD_5271381_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _channel8821_n);
        std::array<char, TPCDS_READ_MAX + 1> _id8822_n = tbl_Union_TD_5271381_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        tbl_Union_TD_5271381_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _id8822_n);
        ++r;
    }
    int row2 = tbl_Aggregate_TD_6713678_output.getNumRow();
    for (int i = 0; i < row2; i++) {
        tbl_Union_TD_5271381_output.setInt32(r, 0, tbl_Aggregate_TD_6713678_output.getInt64(i, 0));
        tbl_Union_TD_5271381_output.setInt32(r, 1, tbl_Aggregate_TD_6713678_output.getInt64(i, 1));
        tbl_Union_TD_5271381_output.setInt32(r, 2, tbl_Aggregate_TD_6713678_output.getInt64(i, 2));
        std::array<char, TPCDS_READ_MAX + 1> _channel8823_n = tbl_Union_TD_5271381_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_Union_TD_5271381_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _channel8823_n);
        std::array<char, TPCDS_READ_MAX + 1> _id8824_n = tbl_Union_TD_5271381_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        tbl_Union_TD_5271381_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _id8824_n);
        ++r;
    }
    tbl_Union_TD_5271381_output.setNumRow(r);
    std::cout << "tbl_Union_TD_5271381_output #Row: " << tbl_Union_TD_5271381_output.getNumRow() << std::endl;
}

void SW_Expand_TD_4449971(Table &tbl_Union_TD_5271381_output, Table &tbl_Expand_TD_4449971_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Expand
    // Operation: ListBuffer(Expand)
    // Input: ListBuffer(sales#8390, returns#8392, profit#8368, channel#8531, id#8532)
    // Output: ListBuffer(sales#8390, returns#8392, profit#8368, channel#8534, id#8535, spark_grouping_id#8533L)
    std::cout << "tbl_Expand_TD_4449971_output #Row: " << tbl_Expand_TD_4449971_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_319948_key {
    std::string _channel8534;
    std::string _id8535;
    int64_t _spark_grouping_id8533L;
    bool operator==(const SW_Aggregate_TD_319948_key& other) const { return (_channel8534 == other._channel8534) && (_id8535 == other._id8535) && (_spark_grouping_id8533L == other._spark_grouping_id8533L); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_319948_key> {
    std::size_t operator() (const SW_Aggregate_TD_319948_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._channel8534)) + (hash<string>()(k._id8535)) + (hash<int64_t>()(k._spark_grouping_id8533L));
    }
};
}
struct SW_Aggregate_TD_319948_payload {
    int64_t _sales8375_sum_0;
    int64_t _returns8376_sum_1;
    int64_t _profit8377_sum_2;
};
void SW_Aggregate_TD_319948(Table &tbl_Expand_TD_4449971_output, Table &tbl_Aggregate_TD_319948_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(channel#8534, id#8535, spark_grouping_id#8533L, sum(sales#8390) AS sales#8375, sum(returns#8392) AS returns#8376, sum(profit#8368) AS profit#8377)
    // Input: ListBuffer(sales#8390, returns#8392, profit#8368, channel#8534, id#8535, spark_grouping_id#8533L)
    // Output: ListBuffer(channel#8534, id#8535, sales#8375, returns#8376, profit#8377)
    std::unordered_map<SW_Aggregate_TD_319948_key, SW_Aggregate_TD_319948_payload> ht1;
    int nrow1 = tbl_Expand_TD_4449971_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sales8390 = tbl_Expand_TD_4449971_output.getInt64(i, 0);
        int64_t _returns8392 = tbl_Expand_TD_4449971_output.getInt64(i, 1);
        int64_t _profit8368 = tbl_Expand_TD_4449971_output.getInt64(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _channel8534 = tbl_Expand_TD_4449971_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _id8535 = tbl_Expand_TD_4449971_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        int64_t _spark_grouping_id8533L = tbl_Expand_TD_4449971_output.getInt64(i, 5);
        SW_Aggregate_TD_319948_key k{std::string(_channel8534.data()), std::string(_id8535.data()), _spark_grouping_id8533L};
        int64_t _sales8375_sum_0 = _sales8390;
        int64_t _returns8376_sum_1 = _returns8392;
        int64_t _profit8377_sum_2 = _profit8368;
        SW_Aggregate_TD_319948_payload p{_sales8375_sum_0, _returns8376_sum_1, _profit8377_sum_2};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._sales8375_sum_0 + _sales8375_sum_0;
            p._sales8375_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._returns8376_sum_1 + _returns8376_sum_1;
            p._returns8376_sum_1 = sum_1;
            int64_t sum_2 = (it->second)._profit8377_sum_2 + _profit8377_sum_2;
            p._profit8377_sum_2 = sum_2;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _channel8534{};
        memcpy(_channel8534.data(), ((it.first)._channel8534).data(), ((it.first)._channel8534).length());
        tbl_Aggregate_TD_319948_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _channel8534);
        std::array<char, TPCDS_READ_MAX + 1> _id8535{};
        memcpy(_id8535.data(), ((it.first)._id8535).data(), ((it.first)._id8535).length());
        tbl_Aggregate_TD_319948_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _id8535);
        // _spark_grouping_id8533L not required in the output table
        int64_t _sales8375 = (it.second)._sales8375_sum_0;
        tbl_Aggregate_TD_319948_output.setInt64(r, 2, _sales8375);
        int64_t _returns8376 = (it.second)._returns8376_sum_1;
        tbl_Aggregate_TD_319948_output.setInt64(r, 3, _returns8376);
        int64_t _profit8377 = (it.second)._profit8377_sum_2;
        tbl_Aggregate_TD_319948_output.setInt64(r, 4, _profit8377);
        ++r;
    }
    tbl_Aggregate_TD_319948_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_319948_output #Row: " << tbl_Aggregate_TD_319948_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2670203(Table &tbl_Aggregate_TD_319948_output, Table &tbl_Sort_TD_2670203_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(channel#8534 ASC NULLS FIRST, id#8535 ASC NULLS FIRST)
    // Input: ListBuffer(channel#8534, id#8535, sales#8375, returns#8376, profit#8377)
    // Output: ListBuffer(channel#8534, id#8535, sales#8375, returns#8376, profit#8377)
    struct SW_Sort_TD_2670203Row {
        std::string _channel8534;
        std::string _id8535;
        int64_t _sales8375;
        int64_t _returns8376;
        int64_t _profit8377;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2670203Row& a, const SW_Sort_TD_2670203Row& b) const { return 
 (a._channel8534 < b._channel8534) || 
 ((a._channel8534 == b._channel8534) && (a._id8535 < b._id8535)); 
}
    }SW_Sort_TD_2670203_order; 

    int nrow1 = tbl_Aggregate_TD_319948_output.getNumRow();
    std::vector<SW_Sort_TD_2670203Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _channel8534 = tbl_Aggregate_TD_319948_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _id8535 = tbl_Aggregate_TD_319948_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        int64_t _sales8375 = tbl_Aggregate_TD_319948_output.getInt64(i, 2);
        int64_t _returns8376 = tbl_Aggregate_TD_319948_output.getInt64(i, 3);
        int64_t _profit8377 = tbl_Aggregate_TD_319948_output.getInt64(i, 4);
        SW_Sort_TD_2670203Row t = {std::string(_channel8534.data()),std::string(_id8535.data()),_sales8375,_returns8376,_profit8377};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2670203_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _channel8534{};
        memcpy(_channel8534.data(), (it._channel8534).data(), (it._channel8534).length());
        tbl_Sort_TD_2670203_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _channel8534);
        std::array<char, TPCDS_READ_MAX + 1> _id8535{};
        memcpy(_id8535.data(), (it._id8535).data(), (it._id8535).length());
        tbl_Sort_TD_2670203_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _id8535);
        tbl_Sort_TD_2670203_output.setInt64(r, 2, it._sales8375);
        tbl_Sort_TD_2670203_output.setInt64(r, 3, it._returns8376);
        tbl_Sort_TD_2670203_output.setInt64(r, 4, it._profit8377);
        if (r < 10) {
            std::cout << (it._channel8534).data() << " " << (it._id8535).data() << " " << it._sales8375 << " " << it._returns8376 << " " << it._profit8377 << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_2670203_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2670203_output #Row: " << tbl_Sort_TD_2670203_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1610557(Table &tbl_Sort_TD_2670203_output, Table &tbl_LocalLimit_TD_1610557_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(channel#8534, id#8535, sales#8375, returns#8376, profit#8377)
    // Output: ListBuffer(channel#8534, id#8535, sales#8375, returns#8376, profit#8377)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _channel8534_n = tbl_Sort_TD_2670203_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1610557_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _channel8534_n);
        std::array<char, TPCDS_READ_MAX + 1> _id8535_n = tbl_Sort_TD_2670203_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_1610557_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _id8535_n);
        tbl_LocalLimit_TD_1610557_output.setInt64(r, 2, tbl_Sort_TD_2670203_output.getInt64(i, 2));
        tbl_LocalLimit_TD_1610557_output.setInt64(r, 3, tbl_Sort_TD_2670203_output.getInt64(i, 3));
        tbl_LocalLimit_TD_1610557_output.setInt64(r, 4, tbl_Sort_TD_2670203_output.getInt64(i, 4));
        r++;
    }
    tbl_LocalLimit_TD_1610557_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1610557_output #Row: " << tbl_LocalLimit_TD_1610557_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0194894(Table &tbl_LocalLimit_TD_1610557_output, Table &tbl_GlobalLimit_TD_0194894_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(channel#8534, id#8535, sales#8375, returns#8376, profit#8377)
    // Output: ListBuffer(channel#8534, id#8535, sales#8375, returns#8376, profit#8377)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _channel8534_n = tbl_LocalLimit_TD_1610557_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0194894_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _channel8534_n);
        std::array<char, TPCDS_READ_MAX + 1> _id8535_n = tbl_LocalLimit_TD_1610557_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_0194894_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _id8535_n);
        tbl_GlobalLimit_TD_0194894_output.setInt64(r, 2, tbl_LocalLimit_TD_1610557_output.getInt64(i, 2));
        tbl_GlobalLimit_TD_0194894_output.setInt64(r, 3, tbl_LocalLimit_TD_1610557_output.getInt64(i, 3));
        tbl_GlobalLimit_TD_0194894_output.setInt64(r, 4, tbl_LocalLimit_TD_1610557_output.getInt64(i, 4));
        r++;
    }
    tbl_GlobalLimit_TD_0194894_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0194894_output #Row: " << tbl_GlobalLimit_TD_0194894_output.getNumRow() << std::endl;
}

