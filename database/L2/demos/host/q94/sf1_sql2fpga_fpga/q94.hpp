#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_6146319(Table &tbl_SerializeFromObject_TD_7728411_input, Table &tbl_Filter_TD_6146319_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ws_ship_date_sk#731) AND isnotnull(ws_ship_addr_sk#740)) AND isnotnull(ws_web_site_sk#742)))
    // Input: ListBuffer(ws_ship_date_sk#731, ws_ship_addr_sk#740, ws_web_site_sk#742, ws_warehouse_sk#744, ws_order_number#746L, ws_ext_ship_cost#757, ws_net_profit#762)
    // Output: ListBuffer(ws_ship_date_sk#731, ws_ship_addr_sk#740, ws_web_site_sk#742, ws_warehouse_sk#744, ws_order_number#746L, ws_ext_ship_cost#757, ws_net_profit#762)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7728411_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_ship_date_sk731 = tbl_SerializeFromObject_TD_7728411_input.getInt32(i, 0);
        int32_t _ws_ship_addr_sk740 = tbl_SerializeFromObject_TD_7728411_input.getInt32(i, 1);
        int32_t _ws_web_site_sk742 = tbl_SerializeFromObject_TD_7728411_input.getInt32(i, 2);
        if (((_ws_ship_date_sk731!= 0) && (_ws_ship_addr_sk740!= 0)) && (_ws_web_site_sk742!= 0)) {
            int32_t _ws_ship_date_sk731_t = tbl_SerializeFromObject_TD_7728411_input.getInt32(i, 0);
            tbl_Filter_TD_6146319_output.setInt32(r, 0, _ws_ship_date_sk731_t);
            int32_t _ws_ship_addr_sk740_t = tbl_SerializeFromObject_TD_7728411_input.getInt32(i, 1);
            tbl_Filter_TD_6146319_output.setInt32(r, 1, _ws_ship_addr_sk740_t);
            int32_t _ws_web_site_sk742_t = tbl_SerializeFromObject_TD_7728411_input.getInt32(i, 2);
            tbl_Filter_TD_6146319_output.setInt32(r, 2, _ws_web_site_sk742_t);
            int32_t _ws_warehouse_sk744_t = tbl_SerializeFromObject_TD_7728411_input.getInt32(i, 3);
            tbl_Filter_TD_6146319_output.setInt32(r, 3, _ws_warehouse_sk744_t);
            int64_t _ws_order_number746L_t = tbl_SerializeFromObject_TD_7728411_input.getInt64(i, 4);
            tbl_Filter_TD_6146319_output.setInt64(r, 4, _ws_order_number746L_t);
            int64_t _ws_ext_ship_cost757_t = tbl_SerializeFromObject_TD_7728411_input.getInt64(i, 5);
            tbl_Filter_TD_6146319_output.setInt64(r, 5, _ws_ext_ship_cost757_t);
            int64_t _ws_net_profit762_t = tbl_SerializeFromObject_TD_7728411_input.getInt64(i, 6);
            tbl_Filter_TD_6146319_output.setInt64(r, 6, _ws_net_profit762_t);
            r++;
        }
    }
    tbl_Filter_TD_6146319_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6146319_output #Row: " << tbl_Filter_TD_6146319_output.getNumRow() << std::endl;
}


void SW_Filter_TD_4436273(Table &tbl_SerializeFromObject_TD_5508883_input, Table &tbl_Filter_TD_4436273_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_date#122) AND ((d_date#122 >= 1999-02-01) AND (d_date#122 <= 1999-04-02))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_date#122)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5508883_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date122 = tbl_SerializeFromObject_TD_5508883_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_5508883_input.getInt32(i, 0);
        if (((_d_date122!= 0) && ((_d_date122 >= 19990201) && (_d_date122 <= 19990402))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_5508883_input.getInt32(i, 0);
            tbl_Filter_TD_4436273_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_4436273_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4436273_output #Row: " << tbl_Filter_TD_4436273_output.getNumRow() << std::endl;
}


void SW_Filter_TD_3363199(Table &tbl_SerializeFromObject_TD_4704706_input, Table &tbl_Filter_TD_3363199_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ca_state#62) AND (ca_state#62 = IL)) AND isnotnull(ca_address_sk#54)))
    // Input: ListBuffer(ca_address_sk#54, ca_state#62)
    // Output: ListBuffer(ca_address_sk#54)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_4704706_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_state62 = tbl_SerializeFromObject_TD_4704706_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _ca_address_sk54 = tbl_SerializeFromObject_TD_4704706_input.getInt32(i, 0);
        if ((_ca_state62.data() != "NULL" && (std::string(_ca_state62.data()) == "IL")) && (_ca_address_sk54!= 0)) {
            int32_t _ca_address_sk54_t = tbl_SerializeFromObject_TD_4704706_input.getInt32(i, 0);
            tbl_Filter_TD_3363199_output.setInt32(r, 0, _ca_address_sk54_t);
            r++;
        }
    }
    tbl_Filter_TD_3363199_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_3363199_output #Row: " << tbl_Filter_TD_3363199_output.getNumRow() << std::endl;
}


void SW_Filter_TD_2974057(Table &tbl_SerializeFromObject_TD_3180338_input, Table &tbl_Filter_TD_2974057_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(web_company_name#551) AND (web_company_name#551 = pri)) AND isnotnull(web_site_sk#537)))
    // Input: ListBuffer(web_site_sk#537, web_company_name#551)
    // Output: ListBuffer(web_site_sk#537)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_3180338_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _web_company_name551 = tbl_SerializeFromObject_TD_3180338_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _web_site_sk537 = tbl_SerializeFromObject_TD_3180338_input.getInt32(i, 0);
        if ((_web_company_name551.data() != "NULL" && (std::string(_web_company_name551.data()) == "pri")) && (_web_site_sk537!= 0)) {
            int32_t _web_site_sk537_t = tbl_SerializeFromObject_TD_3180338_input.getInt32(i, 0);
            tbl_Filter_TD_2974057_output.setInt32(r, 0, _web_site_sk537_t);
            r++;
        }
    }
    tbl_Filter_TD_2974057_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2974057_output #Row: " << tbl_Filter_TD_2974057_output.getNumRow() << std::endl;
}



void SW_Aggregate_TD_0312384(Table &tbl_JOIN_INNER_TD_1453782_output, Table &tbl_Aggregate_TD_0312384_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(count(distinct ws_order_number#746L) AS order count#3544L, MakeDecimal(sum(UnscaledValue(ws_ext_ship_cost#757)),17,2) AS total shipping cost#3545, MakeDecimal(sum(UnscaledValue(ws_net_profit#762)),17,2) AS total net profit#3546)
    // Input: ListBuffer(ws_order_number#746L, ws_ext_ship_cost#757, ws_net_profit#762)
    // Output: ListBuffer(order count#3544L, total shipping cost#3545, total net profit#3546)
    int64_t count_0 = 0;
    int64_t sum_1 = 0;
    int64_t sum_2 = 0;
    int nrow1 = tbl_JOIN_INNER_TD_1453782_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ws_order_number746L = tbl_JOIN_INNER_TD_1453782_output.getInt64(i, 0);
        int64_t _ws_ext_ship_cost757 = tbl_JOIN_INNER_TD_1453782_output.getInt64(i, 1);
        int64_t _ws_net_profit762 = tbl_JOIN_INNER_TD_1453782_output.getInt64(i, 2);
        int64_t _count3544L_count_0 = _ws_order_number746L;
        int64_t _cost3545_sum_1 = _ws_ext_ship_cost757;
        int64_t _profit3546_sum_2 = _ws_net_profit762;
        count_0 += _count3544L_count_0;
        sum_1 += _cost3545_sum_1;
        sum_2 += _profit3546_sum_2;
    }
    int r = 0;
    int64_t _count3544L = count_0;
    tbl_Aggregate_TD_0312384_output.setInt64(r++, 0, _count3544L);
    int64_t _cost3545 = sum_1;
    tbl_Aggregate_TD_0312384_output.setInt64(r++, 1, _cost3545);
    int64_t _profit3546 = sum_2;
    tbl_Aggregate_TD_0312384_output.setInt64(r++, 2, _profit3546);
    tbl_Aggregate_TD_0312384_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_0312384_output #Row: " << tbl_Aggregate_TD_0312384_output.getNumRow() << std::endl;
}

