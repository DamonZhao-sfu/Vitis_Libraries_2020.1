#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_6793448(Table &tbl_SerializeFromObject_TD_7182984_input, Table &tbl_Filter_TD_6793448_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(cs_ship_date_sk#1106) AND isnotnull(cs_ship_addr_sk#1114)) AND isnotnull(cs_call_center_sk#1115)))
    // Input: ListBuffer(cs_ship_date_sk#1106, cs_ship_addr_sk#1114, cs_call_center_sk#1115, cs_warehouse_sk#1118, cs_order_number#1121L, cs_ext_ship_cost#1132, cs_net_profit#1137)
    // Output: ListBuffer(cs_ship_date_sk#1106, cs_ship_addr_sk#1114, cs_call_center_sk#1115, cs_warehouse_sk#1118, cs_order_number#1121L, cs_ext_ship_cost#1132, cs_net_profit#1137)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7182984_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_ship_date_sk1106 = tbl_SerializeFromObject_TD_7182984_input.getInt32(i, 0);
        int32_t _cs_ship_addr_sk1114 = tbl_SerializeFromObject_TD_7182984_input.getInt32(i, 1);
        int32_t _cs_call_center_sk1115 = tbl_SerializeFromObject_TD_7182984_input.getInt32(i, 2);
        if (((_cs_ship_date_sk1106!= 0) && (_cs_ship_addr_sk1114!= 0)) && (_cs_call_center_sk1115!= 0)) {
            int32_t _cs_ship_date_sk1106_t = tbl_SerializeFromObject_TD_7182984_input.getInt32(i, 0);
            tbl_Filter_TD_6793448_output.setInt32(r, 0, _cs_ship_date_sk1106_t);
            int32_t _cs_ship_addr_sk1114_t = tbl_SerializeFromObject_TD_7182984_input.getInt32(i, 1);
            tbl_Filter_TD_6793448_output.setInt32(r, 1, _cs_ship_addr_sk1114_t);
            int32_t _cs_call_center_sk1115_t = tbl_SerializeFromObject_TD_7182984_input.getInt32(i, 2);
            tbl_Filter_TD_6793448_output.setInt32(r, 2, _cs_call_center_sk1115_t);
            int32_t _cs_warehouse_sk1118_t = tbl_SerializeFromObject_TD_7182984_input.getInt32(i, 3);
            tbl_Filter_TD_6793448_output.setInt32(r, 3, _cs_warehouse_sk1118_t);
            int64_t _cs_order_number1121L_t = tbl_SerializeFromObject_TD_7182984_input.getInt64(i, 4);
            tbl_Filter_TD_6793448_output.setInt64(r, 4, _cs_order_number1121L_t);
            int64_t _cs_ext_ship_cost1132_t = tbl_SerializeFromObject_TD_7182984_input.getInt64(i, 5);
            tbl_Filter_TD_6793448_output.setInt64(r, 5, _cs_ext_ship_cost1132_t);
            int64_t _cs_net_profit1137_t = tbl_SerializeFromObject_TD_7182984_input.getInt64(i, 6);
            tbl_Filter_TD_6793448_output.setInt64(r, 6, _cs_net_profit1137_t);
            r++;
        }
    }
    tbl_Filter_TD_6793448_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6793448_output #Row: " << tbl_Filter_TD_6793448_output.getNumRow() << std::endl;
}


void SW_Filter_TD_4694564(Table &tbl_SerializeFromObject_TD_5596905_input, Table &tbl_Filter_TD_4694564_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_date#122) AND ((d_date#122 >= 2002-02-01) AND (d_date#122 <= 2002-04-02))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_date#122)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5596905_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date122 = tbl_SerializeFromObject_TD_5596905_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_5596905_input.getInt32(i, 0);
        if (((_d_date122!= 0) && ((_d_date122 >= 20020201) && (_d_date122 <= 20020402))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_5596905_input.getInt32(i, 0);
            tbl_Filter_TD_4694564_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_4694564_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4694564_output #Row: " << tbl_Filter_TD_4694564_output.getNumRow() << std::endl;
}


void SW_Filter_TD_3340251(Table &tbl_SerializeFromObject_TD_4155524_input, Table &tbl_Filter_TD_3340251_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ca_state#62) AND (ca_state#62 = GA)) AND isnotnull(ca_address_sk#54)))
    // Input: ListBuffer(ca_address_sk#54, ca_state#62)
    // Output: ListBuffer(ca_address_sk#54)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_4155524_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_state62 = tbl_SerializeFromObject_TD_4155524_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _ca_address_sk54 = tbl_SerializeFromObject_TD_4155524_input.getInt32(i, 0);
        if ((_ca_state62.data() != "NULL" && (std::string(_ca_state62.data()) == "GA")) && (_ca_address_sk54!= 0)) {
            int32_t _ca_address_sk54_t = tbl_SerializeFromObject_TD_4155524_input.getInt32(i, 0);
            tbl_Filter_TD_3340251_output.setInt32(r, 0, _ca_address_sk54_t);
            r++;
        }
    }
    tbl_Filter_TD_3340251_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_3340251_output #Row: " << tbl_Filter_TD_3340251_output.getNumRow() << std::endl;
}


void SW_Filter_TD_2432498(Table &tbl_SerializeFromObject_TD_3412899_input, Table &tbl_Filter_TD_2432498_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(cc_county#928) AND (cc_county#928 = Williamson County)) AND isnotnull(cc_call_center_sk#903)))
    // Input: ListBuffer(cc_call_center_sk#903, cc_county#928)
    // Output: ListBuffer(cc_call_center_sk#903)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_3412899_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _cc_county928 = tbl_SerializeFromObject_TD_3412899_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _cc_call_center_sk903 = tbl_SerializeFromObject_TD_3412899_input.getInt32(i, 0);
        if ((_cc_county928.data() != "NULL" && (std::string(_cc_county928.data()) == "Williamson County")) && (_cc_call_center_sk903!= 0)) {
            int32_t _cc_call_center_sk903_t = tbl_SerializeFromObject_TD_3412899_input.getInt32(i, 0);
            tbl_Filter_TD_2432498_output.setInt32(r, 0, _cc_call_center_sk903_t);
            r++;
        }
    }
    tbl_Filter_TD_2432498_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2432498_output #Row: " << tbl_Filter_TD_2432498_output.getNumRow() << std::endl;
}



void SW_Aggregate_TD_0403217(Table &tbl_JOIN_INNER_TD_1729688_output, Table &tbl_Aggregate_TD_0403217_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(count(distinct cs_order_number#1121L) AS order count#3544L, MakeDecimal(sum(UnscaledValue(cs_ext_ship_cost#1132)),17,2) AS total shipping cost#3545, MakeDecimal(sum(UnscaledValue(cs_net_profit#1137)),17,2) AS total net profit#3546)
    // Input: ListBuffer(cs_order_number#1121L, cs_ext_ship_cost#1132, cs_net_profit#1137)
    // Output: ListBuffer(order count#3544L, total shipping cost#3545, total net profit#3546)
    int64_t count_0 = 0;
    int64_t sum_1 = 0;
    int64_t sum_2 = 0;
    int nrow1 = tbl_JOIN_INNER_TD_1729688_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _cs_order_number1121L = tbl_JOIN_INNER_TD_1729688_output.getInt64(i, 0);
        int64_t _cs_ext_ship_cost1132 = tbl_JOIN_INNER_TD_1729688_output.getInt64(i, 1);
        int64_t _cs_net_profit1137 = tbl_JOIN_INNER_TD_1729688_output.getInt64(i, 2);
        int64_t _count3544L_count_0 = _cs_order_number1121L;
        int64_t _cost3545_sum_1 = _cs_ext_ship_cost1132;
        int64_t _profit3546_sum_2 = _cs_net_profit1137;
        count_0 += _count3544L_count_0;
        sum_1 += _cost3545_sum_1;
        sum_2 += _profit3546_sum_2;
    }
    int r = 0;
    int64_t _count3544L = count_0;
    tbl_Aggregate_TD_0403217_output.setInt64(r++, 0, _count3544L);
    int64_t _cost3545 = sum_1;
    tbl_Aggregate_TD_0403217_output.setInt64(r++, 1, _cost3545);
    int64_t _profit3546 = sum_2;
    tbl_Aggregate_TD_0403217_output.setInt64(r++, 2, _profit3546);
    tbl_Aggregate_TD_0403217_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_0403217_output #Row: " << tbl_Aggregate_TD_0403217_output.getNumRow() << std::endl;
}

