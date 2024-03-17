#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_11309608(Table &tbl_SerializeFromObject_TD_1283330_input, Table &tbl_Filter_TD_11309608_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(wr_order_number#844L) AND isnotnull(wr_item_sk#833)))
    // Input: ListBuffer(wr_item_sk#833, wr_order_number#844L)
    // Output: ListBuffer(wr_item_sk#833, wr_order_number#844L)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1283330_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _wr_order_number844L = tbl_SerializeFromObject_TD_1283330_input.getInt64(i, 1);
        int32_t _wr_item_sk833 = tbl_SerializeFromObject_TD_1283330_input.getInt32(i, 0);
        if ((_wr_order_number844L!= 0) && (_wr_item_sk833!= 0)) {
            int32_t _wr_item_sk833_t = tbl_SerializeFromObject_TD_1283330_input.getInt32(i, 0);
            tbl_Filter_TD_11309608_output.setInt32(r, 0, _wr_item_sk833_t);
            int64_t _wr_order_number844L_t = tbl_SerializeFromObject_TD_1283330_input.getInt64(i, 1);
            tbl_Filter_TD_11309608_output.setInt64(r, 1, _wr_order_number844L_t);
            r++;
        }
    }
    tbl_Filter_TD_11309608_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11309608_output #Row: " << tbl_Filter_TD_11309608_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11691082(Table &tbl_SerializeFromObject_TD_12435085_input, Table &tbl_Filter_TD_11691082_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ws_sold_date_sk#729) AND isnotnull(ws_item_sk#732)) AND isnotnull(ws_bill_customer_sk#733)))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_bill_customer_sk#733, ws_order_number#746L, ws_quantity#747, ws_wholesale_cost#748, ws_sales_price#750)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_bill_customer_sk#733, ws_order_number#746L, ws_quantity#747, ws_wholesale_cost#748, ws_sales_price#750)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12435085_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_12435085_input.getInt32(i, 0);
        int32_t _ws_item_sk732 = tbl_SerializeFromObject_TD_12435085_input.getInt32(i, 1);
        int32_t _ws_bill_customer_sk733 = tbl_SerializeFromObject_TD_12435085_input.getInt32(i, 2);
        if (((_ws_sold_date_sk729!= 0) && (_ws_item_sk732!= 0)) && (_ws_bill_customer_sk733!= 0)) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_12435085_input.getInt32(i, 0);
            tbl_Filter_TD_11691082_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_item_sk732_t = tbl_SerializeFromObject_TD_12435085_input.getInt32(i, 1);
            tbl_Filter_TD_11691082_output.setInt32(r, 1, _ws_item_sk732_t);
            int32_t _ws_bill_customer_sk733_t = tbl_SerializeFromObject_TD_12435085_input.getInt32(i, 2);
            tbl_Filter_TD_11691082_output.setInt32(r, 2, _ws_bill_customer_sk733_t);
            int64_t _ws_order_number746L_t = tbl_SerializeFromObject_TD_12435085_input.getInt64(i, 3);
            tbl_Filter_TD_11691082_output.setInt64(r, 3, _ws_order_number746L_t);
            int32_t _ws_quantity747_t = tbl_SerializeFromObject_TD_12435085_input.getInt32(i, 4);
            tbl_Filter_TD_11691082_output.setInt32(r, 4, _ws_quantity747_t);
            int64_t _ws_wholesale_cost748_t = tbl_SerializeFromObject_TD_12435085_input.getInt64(i, 5);
            tbl_Filter_TD_11691082_output.setInt64(r, 5, _ws_wholesale_cost748_t);
            int64_t _ws_sales_price750_t = tbl_SerializeFromObject_TD_12435085_input.getInt64(i, 6);
            tbl_Filter_TD_11691082_output.setInt64(r, 6, _ws_sales_price750_t);
            r++;
        }
    }
    tbl_Filter_TD_11691082_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11691082_output #Row: " << tbl_Filter_TD_11691082_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11109600(Table &tbl_SerializeFromObject_TD_12520073_input, Table &tbl_Filter_TD_11109600_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(sr_ticket_number#678L) AND isnotnull(sr_item_sk#671)))
    // Input: ListBuffer(sr_item_sk#671, sr_ticket_number#678L)
    // Output: ListBuffer(sr_item_sk#671, sr_ticket_number#678L)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12520073_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sr_ticket_number678L = tbl_SerializeFromObject_TD_12520073_input.getInt64(i, 1);
        int32_t _sr_item_sk671 = tbl_SerializeFromObject_TD_12520073_input.getInt32(i, 0);
        if ((_sr_ticket_number678L!= 0) && (_sr_item_sk671!= 0)) {
            int32_t _sr_item_sk671_t = tbl_SerializeFromObject_TD_12520073_input.getInt32(i, 0);
            tbl_Filter_TD_11109600_output.setInt32(r, 0, _sr_item_sk671_t);
            int64_t _sr_ticket_number678L_t = tbl_SerializeFromObject_TD_12520073_input.getInt64(i, 1);
            tbl_Filter_TD_11109600_output.setInt64(r, 1, _sr_ticket_number678L_t);
            r++;
        }
    }
    tbl_Filter_TD_11109600_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11109600_output #Row: " << tbl_Filter_TD_11109600_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11239235(Table &tbl_SerializeFromObject_TD_12731183_input, Table &tbl_Filter_TD_11239235_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ss_sold_date_sk#1206))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209, ss_ticket_number#1215L, ss_quantity#1216, ss_wholesale_cost#1217, ss_sales_price#1219)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209, ss_ticket_number#1215L, ss_quantity#1216, ss_wholesale_cost#1217, ss_sales_price#1219)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12731183_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_12731183_input.getInt32(i, 0);
        if (_ss_sold_date_sk1206!= 0) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_12731183_input.getInt32(i, 0);
            tbl_Filter_TD_11239235_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_12731183_input.getInt32(i, 1);
            tbl_Filter_TD_11239235_output.setInt32(r, 1, _ss_item_sk1208_t);
            int32_t _ss_customer_sk1209_t = tbl_SerializeFromObject_TD_12731183_input.getInt32(i, 2);
            tbl_Filter_TD_11239235_output.setInt32(r, 2, _ss_customer_sk1209_t);
            int64_t _ss_ticket_number1215L_t = tbl_SerializeFromObject_TD_12731183_input.getInt64(i, 3);
            tbl_Filter_TD_11239235_output.setInt64(r, 3, _ss_ticket_number1215L_t);
            int32_t _ss_quantity1216_t = tbl_SerializeFromObject_TD_12731183_input.getInt32(i, 4);
            tbl_Filter_TD_11239235_output.setInt32(r, 4, _ss_quantity1216_t);
            int64_t _ss_wholesale_cost1217_t = tbl_SerializeFromObject_TD_12731183_input.getInt64(i, 5);
            tbl_Filter_TD_11239235_output.setInt64(r, 5, _ss_wholesale_cost1217_t);
            int64_t _ss_sales_price1219_t = tbl_SerializeFromObject_TD_12731183_input.getInt64(i, 6);
            tbl_Filter_TD_11239235_output.setInt64(r, 6, _ss_sales_price1219_t);
            r++;
        }
    }
    tbl_Filter_TD_11239235_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11239235_output #Row: " << tbl_Filter_TD_11239235_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10105006(Table &tbl_SerializeFromObject_TD_11905275_input, Table &tbl_Filter_TD_10105006_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cr_order_number#1039L) AND isnotnull(cr_item_sk#1025)))
    // Input: ListBuffer(cr_item_sk#1025, cr_order_number#1039L)
    // Output: ListBuffer(cr_item_sk#1025, cr_order_number#1039L)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11905275_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _cr_order_number1039L = tbl_SerializeFromObject_TD_11905275_input.getInt64(i, 1);
        int32_t _cr_item_sk1025 = tbl_SerializeFromObject_TD_11905275_input.getInt32(i, 0);
        if ((_cr_order_number1039L!= 0) && (_cr_item_sk1025!= 0)) {
            int32_t _cr_item_sk1025_t = tbl_SerializeFromObject_TD_11905275_input.getInt32(i, 0);
            tbl_Filter_TD_10105006_output.setInt32(r, 0, _cr_item_sk1025_t);
            int64_t _cr_order_number1039L_t = tbl_SerializeFromObject_TD_11905275_input.getInt64(i, 1);
            tbl_Filter_TD_10105006_output.setInt64(r, 1, _cr_order_number1039L_t);
            r++;
        }
    }
    tbl_Filter_TD_10105006_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10105006_output #Row: " << tbl_Filter_TD_10105006_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10942672(Table &tbl_SerializeFromObject_TD_11867361_input, Table &tbl_Filter_TD_10942672_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(cs_sold_date_sk#1104) AND isnotnull(cs_item_sk#1119)) AND isnotnull(cs_bill_customer_sk#1107)))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_item_sk#1119, cs_order_number#1121L, cs_quantity#1122, cs_wholesale_cost#1123, cs_sales_price#1125)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_item_sk#1119, cs_order_number#1121L, cs_quantity#1122, cs_wholesale_cost#1123, cs_sales_price#1125)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11867361_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_11867361_input.getInt32(i, 0);
        int32_t _cs_item_sk1119 = tbl_SerializeFromObject_TD_11867361_input.getInt32(i, 2);
        int32_t _cs_bill_customer_sk1107 = tbl_SerializeFromObject_TD_11867361_input.getInt32(i, 1);
        if (((_cs_sold_date_sk1104!= 0) && (_cs_item_sk1119!= 0)) && (_cs_bill_customer_sk1107!= 0)) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_11867361_input.getInt32(i, 0);
            tbl_Filter_TD_10942672_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int32_t _cs_bill_customer_sk1107_t = tbl_SerializeFromObject_TD_11867361_input.getInt32(i, 1);
            tbl_Filter_TD_10942672_output.setInt32(r, 1, _cs_bill_customer_sk1107_t);
            int32_t _cs_item_sk1119_t = tbl_SerializeFromObject_TD_11867361_input.getInt32(i, 2);
            tbl_Filter_TD_10942672_output.setInt32(r, 2, _cs_item_sk1119_t);
            int64_t _cs_order_number1121L_t = tbl_SerializeFromObject_TD_11867361_input.getInt64(i, 3);
            tbl_Filter_TD_10942672_output.setInt64(r, 3, _cs_order_number1121L_t);
            int32_t _cs_quantity1122_t = tbl_SerializeFromObject_TD_11867361_input.getInt32(i, 4);
            tbl_Filter_TD_10942672_output.setInt32(r, 4, _cs_quantity1122_t);
            int64_t _cs_wholesale_cost1123_t = tbl_SerializeFromObject_TD_11867361_input.getInt64(i, 5);
            tbl_Filter_TD_10942672_output.setInt64(r, 5, _cs_wholesale_cost1123_t);
            int64_t _cs_sales_price1125_t = tbl_SerializeFromObject_TD_11867361_input.getInt64(i, 6);
            tbl_Filter_TD_10942672_output.setInt64(r, 6, _cs_sales_price1125_t);
            r++;
        }
    }
    tbl_Filter_TD_10942672_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10942672_output #Row: " << tbl_Filter_TD_10942672_output.getNumRow() << std::endl;
}




void SW_Filter_TD_9807504(Table &tbl_SerializeFromObject_TD_10623568_input, Table &tbl_Filter_TD_9807504_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(d_date_sk#120) AND ((d_year#126 = 2000) AND isnotnull(d_year#126))))
    // Input: ListBuffer(d_date_sk#120, d_year#126)
    // Output: ListBuffer(d_date_sk#120, d_year#126)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10623568_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_10623568_input.getInt32(i, 0);
        int32_t _d_year126 = tbl_SerializeFromObject_TD_10623568_input.getInt32(i, 1);
        if ((_d_date_sk120!= 0) && ((_d_year126 == 2000) && (_d_year126!= 0))) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_10623568_input.getInt32(i, 0);
            tbl_Filter_TD_9807504_output.setInt32(r, 0, _d_date_sk120_t);
            int32_t _d_year126_t = tbl_SerializeFromObject_TD_10623568_input.getInt32(i, 1);
            tbl_Filter_TD_9807504_output.setInt32(r, 1, _d_year126_t);
            r++;
        }
    }
    tbl_Filter_TD_9807504_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9807504_output #Row: " << tbl_Filter_TD_9807504_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9909549(Table &tbl_JOIN_LEFTOUTER_TD_10452759_output, Table &tbl_Filter_TD_9909549_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnull(wr_order_number#844L))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_bill_customer_sk#733, ws_quantity#747, ws_wholesale_cost#748, ws_sales_price#750, wr_order_number#844L)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_bill_customer_sk#733, ws_quantity#747, ws_wholesale_cost#748, ws_sales_price#750)
    int r = 0;
    int nrow1 = tbl_JOIN_LEFTOUTER_TD_10452759_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _wr_order_number844L = tbl_JOIN_LEFTOUTER_TD_10452759_output.getInt64(i, 6);
        if (_wr_order_number844L == 0) {
            int32_t _ws_sold_date_sk729_t = tbl_JOIN_LEFTOUTER_TD_10452759_output.getInt32(i, 0);
            tbl_Filter_TD_9909549_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_item_sk732_t = tbl_JOIN_LEFTOUTER_TD_10452759_output.getInt32(i, 1);
            tbl_Filter_TD_9909549_output.setInt32(r, 1, _ws_item_sk732_t);
            int32_t _ws_bill_customer_sk733_t = tbl_JOIN_LEFTOUTER_TD_10452759_output.getInt32(i, 2);
            tbl_Filter_TD_9909549_output.setInt32(r, 2, _ws_bill_customer_sk733_t);
            int32_t _ws_quantity747_t = tbl_JOIN_LEFTOUTER_TD_10452759_output.getInt32(i, 3);
            tbl_Filter_TD_9909549_output.setInt32(r, 3, _ws_quantity747_t);
            int64_t _ws_wholesale_cost748_t = tbl_JOIN_LEFTOUTER_TD_10452759_output.getInt64(i, 4);
            tbl_Filter_TD_9909549_output.setInt64(r, 4, _ws_wholesale_cost748_t);
            int64_t _ws_sales_price750_t = tbl_JOIN_LEFTOUTER_TD_10452759_output.getInt64(i, 5);
            tbl_Filter_TD_9909549_output.setInt64(r, 5, _ws_sales_price750_t);
            r++;
        }
    }
    tbl_Filter_TD_9909549_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9909549_output #Row: " << tbl_Filter_TD_9909549_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9947940(Table &tbl_SerializeFromObject_TD_10497773_input, Table &tbl_Filter_TD_9947940_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#4309) AND (d_year#4309 = 2000)) AND isnotnull(d_date_sk#4303)))
    // Input: ListBuffer(d_date_sk#4303, d_year#4309)
    // Output: ListBuffer(d_date_sk#4303, d_year#4309)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10497773_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year4309 = tbl_SerializeFromObject_TD_10497773_input.getInt32(i, 1);
        int32_t _d_date_sk4303 = tbl_SerializeFromObject_TD_10497773_input.getInt32(i, 0);
        if (((_d_year4309!= 0) && (_d_year4309 == 2000)) && (_d_date_sk4303!= 0)) {
            int32_t _d_date_sk4303_t = tbl_SerializeFromObject_TD_10497773_input.getInt32(i, 0);
            tbl_Filter_TD_9947940_output.setInt32(r, 0, _d_date_sk4303_t);
            int32_t _d_year4309_t = tbl_SerializeFromObject_TD_10497773_input.getInt32(i, 1);
            tbl_Filter_TD_9947940_output.setInt32(r, 1, _d_year4309_t);
            r++;
        }
    }
    tbl_Filter_TD_9947940_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9947940_output #Row: " << tbl_Filter_TD_9947940_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9112927(Table &tbl_JOIN_LEFTOUTER_TD_10794663_output, Table &tbl_Filter_TD_9112927_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnull(sr_ticket_number#678L))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209, ss_quantity#1216, ss_wholesale_cost#1217, ss_sales_price#1219, sr_ticket_number#678L)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209, ss_quantity#1216, ss_wholesale_cost#1217, ss_sales_price#1219)
    int r = 0;
    int nrow1 = tbl_JOIN_LEFTOUTER_TD_10794663_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sr_ticket_number678L = tbl_JOIN_LEFTOUTER_TD_10794663_output.getInt64(i, 6);
        if (_sr_ticket_number678L == 0) {
            int32_t _ss_sold_date_sk1206_t = tbl_JOIN_LEFTOUTER_TD_10794663_output.getInt32(i, 0);
            tbl_Filter_TD_9112927_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_JOIN_LEFTOUTER_TD_10794663_output.getInt32(i, 1);
            tbl_Filter_TD_9112927_output.setInt32(r, 1, _ss_item_sk1208_t);
            int32_t _ss_customer_sk1209_t = tbl_JOIN_LEFTOUTER_TD_10794663_output.getInt32(i, 2);
            tbl_Filter_TD_9112927_output.setInt32(r, 2, _ss_customer_sk1209_t);
            int32_t _ss_quantity1216_t = tbl_JOIN_LEFTOUTER_TD_10794663_output.getInt32(i, 3);
            tbl_Filter_TD_9112927_output.setInt32(r, 3, _ss_quantity1216_t);
            int64_t _ss_wholesale_cost1217_t = tbl_JOIN_LEFTOUTER_TD_10794663_output.getInt64(i, 4);
            tbl_Filter_TD_9112927_output.setInt64(r, 4, _ss_wholesale_cost1217_t);
            int64_t _ss_sales_price1219_t = tbl_JOIN_LEFTOUTER_TD_10794663_output.getInt64(i, 5);
            tbl_Filter_TD_9112927_output.setInt64(r, 5, _ss_sales_price1219_t);
            r++;
        }
    }
    tbl_Filter_TD_9112927_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9112927_output #Row: " << tbl_Filter_TD_9112927_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8740746(Table &tbl_SerializeFromObject_TD_9423601_input, Table &tbl_Filter_TD_8740746_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(d_date_sk#4275) AND ((d_year#4281 = 2000) AND isnotnull(d_year#4281))))
    // Input: ListBuffer(d_date_sk#4275, d_year#4281)
    // Output: ListBuffer(d_date_sk#4275, d_year#4281)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9423601_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date_sk4275 = tbl_SerializeFromObject_TD_9423601_input.getInt32(i, 0);
        int32_t _d_year4281 = tbl_SerializeFromObject_TD_9423601_input.getInt32(i, 1);
        if ((_d_date_sk4275!= 0) && ((_d_year4281 == 2000) && (_d_year4281!= 0))) {
            int32_t _d_date_sk4275_t = tbl_SerializeFromObject_TD_9423601_input.getInt32(i, 0);
            tbl_Filter_TD_8740746_output.setInt32(r, 0, _d_date_sk4275_t);
            int32_t _d_year4281_t = tbl_SerializeFromObject_TD_9423601_input.getInt32(i, 1);
            tbl_Filter_TD_8740746_output.setInt32(r, 1, _d_year4281_t);
            r++;
        }
    }
    tbl_Filter_TD_8740746_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8740746_output #Row: " << tbl_Filter_TD_8740746_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8532339(Table &tbl_JOIN_LEFTOUTER_TD_9190274_output, Table &tbl_Filter_TD_8532339_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnull(cr_order_number#1039L))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_item_sk#1119, cs_quantity#1122, cs_wholesale_cost#1123, cs_sales_price#1125, cr_order_number#1039L)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_item_sk#1119, cs_quantity#1122, cs_wholesale_cost#1123, cs_sales_price#1125)
    int r = 0;
    int nrow1 = tbl_JOIN_LEFTOUTER_TD_9190274_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _cr_order_number1039L = tbl_JOIN_LEFTOUTER_TD_9190274_output.getInt64(i, 6);
        if (_cr_order_number1039L == 0) {
            int32_t _cs_sold_date_sk1104_t = tbl_JOIN_LEFTOUTER_TD_9190274_output.getInt32(i, 0);
            tbl_Filter_TD_8532339_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int32_t _cs_bill_customer_sk1107_t = tbl_JOIN_LEFTOUTER_TD_9190274_output.getInt32(i, 1);
            tbl_Filter_TD_8532339_output.setInt32(r, 1, _cs_bill_customer_sk1107_t);
            int32_t _cs_item_sk1119_t = tbl_JOIN_LEFTOUTER_TD_9190274_output.getInt32(i, 2);
            tbl_Filter_TD_8532339_output.setInt32(r, 2, _cs_item_sk1119_t);
            int32_t _cs_quantity1122_t = tbl_JOIN_LEFTOUTER_TD_9190274_output.getInt32(i, 3);
            tbl_Filter_TD_8532339_output.setInt32(r, 3, _cs_quantity1122_t);
            int64_t _cs_wholesale_cost1123_t = tbl_JOIN_LEFTOUTER_TD_9190274_output.getInt64(i, 4);
            tbl_Filter_TD_8532339_output.setInt64(r, 4, _cs_wholesale_cost1123_t);
            int64_t _cs_sales_price1125_t = tbl_JOIN_LEFTOUTER_TD_9190274_output.getInt64(i, 5);
            tbl_Filter_TD_8532339_output.setInt64(r, 5, _cs_sales_price1125_t);
            r++;
        }
    }
    tbl_Filter_TD_8532339_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8532339_output #Row: " << tbl_Filter_TD_8532339_output.getNumRow() << std::endl;
}




struct SW_Aggregate_TD_7416502_key {
    int32_t _d_year126;
    int32_t _ws_item_sk732;
    int32_t _ws_bill_customer_sk733;
    bool operator==(const SW_Aggregate_TD_7416502_key& other) const { return (_d_year126 == other._d_year126) && (_ws_item_sk732 == other._ws_item_sk732) && (_ws_bill_customer_sk733 == other._ws_bill_customer_sk733); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_7416502_key> {
    std::size_t operator() (const SW_Aggregate_TD_7416502_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_year126)) + (hash<int32_t>()(k._ws_item_sk732)) + (hash<int32_t>()(k._ws_bill_customer_sk733));
    }
};
}
struct SW_Aggregate_TD_7416502_payload {
    int32_t _ws_sold_year4261;
    int32_t _ws_customer_sk4262;
    int64_t _ws_qty4263L_sum_0;
    int64_t _ws_wc4264_sum_1;
    int64_t _ws_sp4265_sum_2;
};
void SW_Aggregate_TD_7416502(Table &tbl_JOIN_INNER_TD_8497666_output, Table &tbl_Aggregate_TD_7416502_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(d_year#126, ws_item_sk#732, ws_bill_customer_sk#733, d_year#126 AS ws_sold_year#4261, ws_bill_customer_sk#733 AS ws_customer_sk#4262, sum(ws_quantity#747) AS ws_qty#4263L, MakeDecimal(sum(UnscaledValue(ws_wholesale_cost#748)),17,2) AS ws_wc#4264, MakeDecimal(sum(UnscaledValue(ws_sales_price#750)),17,2) AS ws_sp#4265)
    // Input: ListBuffer(ws_item_sk#732, ws_bill_customer_sk#733, ws_quantity#747, ws_wholesale_cost#748, ws_sales_price#750, d_year#126)
    // Output: ListBuffer(ws_sold_year#4261, ws_item_sk#732, ws_customer_sk#4262, ws_qty#4263L, ws_wc#4264, ws_sp#4265)
    std::unordered_map<SW_Aggregate_TD_7416502_key, SW_Aggregate_TD_7416502_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_8497666_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_item_sk732 = tbl_JOIN_INNER_TD_8497666_output.getInt32(i, 0);
        int32_t _ws_bill_customer_sk733 = tbl_JOIN_INNER_TD_8497666_output.getInt32(i, 1);
        int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_8497666_output.getInt32(i, 2);
        int64_t _ws_wholesale_cost748 = tbl_JOIN_INNER_TD_8497666_output.getInt64(i, 3);
        int64_t _ws_sales_price750 = tbl_JOIN_INNER_TD_8497666_output.getInt64(i, 4);
        int32_t _d_year126 = tbl_JOIN_INNER_TD_8497666_output.getInt32(i, 5);
        SW_Aggregate_TD_7416502_key k{_d_year126, _ws_item_sk732, _ws_bill_customer_sk733};
        int32_t _ws_sold_year4261 = _d_year126;
        int32_t _ws_customer_sk4262 = _ws_bill_customer_sk733;
        int64_t _ws_qty4263L_sum_0 = _ws_quantity747;
        int64_t _ws_wc4264_sum_1 = _ws_wholesale_cost748;
        int64_t _ws_sp4265_sum_2 = _ws_sales_price750;
        SW_Aggregate_TD_7416502_payload p{_ws_sold_year4261, _ws_customer_sk4262, _ws_qty4263L_sum_0, _ws_wc4264_sum_1, _ws_sp4265_sum_2};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._ws_qty4263L_sum_0 + _ws_qty4263L_sum_0;
            p._ws_qty4263L_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._ws_wc4264_sum_1 + _ws_wc4264_sum_1;
            p._ws_wc4264_sum_1 = sum_1;
            int64_t sum_2 = (it->second)._ws_sp4265_sum_2 + _ws_sp4265_sum_2;
            p._ws_sp4265_sum_2 = sum_2;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _d_year126 not required in the output table
        tbl_Aggregate_TD_7416502_output.setInt32(r, 1, (it.first)._ws_item_sk732);
        // _ws_bill_customer_sk733 not required in the output table
        tbl_Aggregate_TD_7416502_output.setInt32(r, 0, (it.second)._ws_sold_year4261);
        tbl_Aggregate_TD_7416502_output.setInt32(r, 2, (it.second)._ws_customer_sk4262);
        int64_t _ws_qty4263L = (it.second)._ws_qty4263L_sum_0;
        tbl_Aggregate_TD_7416502_output.setInt64(r, 3, _ws_qty4263L);
        int64_t _ws_wc4264 = (it.second)._ws_wc4264_sum_1;
        tbl_Aggregate_TD_7416502_output.setInt64(r, 4, _ws_wc4264);
        int64_t _ws_sp4265 = (it.second)._ws_sp4265_sum_2;
        tbl_Aggregate_TD_7416502_output.setInt64(r, 5, _ws_sp4265);
        ++r;
    }
    tbl_Aggregate_TD_7416502_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_7416502_output #Row: " << tbl_Aggregate_TD_7416502_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_7527825_key {
    int32_t _d_year4309;
    int32_t _ss_item_sk1208;
    int32_t _ss_customer_sk1209;
    bool operator==(const SW_Aggregate_TD_7527825_key& other) const { return (_d_year4309 == other._d_year4309) && (_ss_item_sk1208 == other._ss_item_sk1208) && (_ss_customer_sk1209 == other._ss_customer_sk1209); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_7527825_key> {
    std::size_t operator() (const SW_Aggregate_TD_7527825_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_year4309)) + (hash<int32_t>()(k._ss_item_sk1208)) + (hash<int32_t>()(k._ss_customer_sk1209));
    }
};
}
struct SW_Aggregate_TD_7527825_payload {
    int32_t _ss_sold_year4271;
    int64_t _ss_qty4272L_sum_0;
    int64_t _ss_wc4273_sum_1;
    int64_t _ss_sp4274_sum_2;
};
void SW_Aggregate_TD_7527825(Table &tbl_JOIN_INNER_TD_8752431_output, Table &tbl_Aggregate_TD_7527825_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(d_year#4309, ss_item_sk#1208, ss_customer_sk#1209, d_year#4309 AS ss_sold_year#4271, sum(ss_quantity#1216) AS ss_qty#4272L, MakeDecimal(sum(UnscaledValue(ss_wholesale_cost#1217)),17,2) AS ss_wc#4273, MakeDecimal(sum(UnscaledValue(ss_sales_price#1219)),17,2) AS ss_sp#4274)
    // Input: ListBuffer(ss_item_sk#1208, ss_customer_sk#1209, ss_quantity#1216, ss_wholesale_cost#1217, ss_sales_price#1219, d_year#4309)
    // Output: ListBuffer(ss_sold_year#4271, ss_item_sk#1208, ss_customer_sk#1209, ss_qty#4272L, ss_wc#4273, ss_sp#4274)
    std::unordered_map<SW_Aggregate_TD_7527825_key, SW_Aggregate_TD_7527825_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_8752431_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_8752431_output.getInt32(i, 0);
        int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_8752431_output.getInt32(i, 1);
        int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_8752431_output.getInt32(i, 2);
        int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_8752431_output.getInt64(i, 3);
        int64_t _ss_sales_price1219 = tbl_JOIN_INNER_TD_8752431_output.getInt64(i, 4);
        int32_t _d_year4309 = tbl_JOIN_INNER_TD_8752431_output.getInt32(i, 5);
        SW_Aggregate_TD_7527825_key k{_d_year4309, _ss_item_sk1208, _ss_customer_sk1209};
        int32_t _ss_sold_year4271 = _d_year4309;
        int64_t _ss_qty4272L_sum_0 = _ss_quantity1216;
        int64_t _ss_wc4273_sum_1 = _ss_wholesale_cost1217;
        int64_t _ss_sp4274_sum_2 = _ss_sales_price1219;
        SW_Aggregate_TD_7527825_payload p{_ss_sold_year4271, _ss_qty4272L_sum_0, _ss_wc4273_sum_1, _ss_sp4274_sum_2};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._ss_qty4272L_sum_0 + _ss_qty4272L_sum_0;
            p._ss_qty4272L_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._ss_wc4273_sum_1 + _ss_wc4273_sum_1;
            p._ss_wc4273_sum_1 = sum_1;
            int64_t sum_2 = (it->second)._ss_sp4274_sum_2 + _ss_sp4274_sum_2;
            p._ss_sp4274_sum_2 = sum_2;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _d_year4309 not required in the output table
        tbl_Aggregate_TD_7527825_output.setInt32(r, 1, (it.first)._ss_item_sk1208);
        tbl_Aggregate_TD_7527825_output.setInt32(r, 2, (it.first)._ss_customer_sk1209);
        tbl_Aggregate_TD_7527825_output.setInt32(r, 0, (it.second)._ss_sold_year4271);
        int64_t _ss_qty4272L = (it.second)._ss_qty4272L_sum_0;
        tbl_Aggregate_TD_7527825_output.setInt64(r, 3, _ss_qty4272L);
        int64_t _ss_wc4273 = (it.second)._ss_wc4273_sum_1;
        tbl_Aggregate_TD_7527825_output.setInt64(r, 4, _ss_wc4273);
        int64_t _ss_sp4274 = (it.second)._ss_sp4274_sum_2;
        tbl_Aggregate_TD_7527825_output.setInt64(r, 5, _ss_sp4274);
        ++r;
    }
    tbl_Aggregate_TD_7527825_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_7527825_output #Row: " << tbl_Aggregate_TD_7527825_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_6327308_key {
    int32_t _d_year4281;
    int32_t _cs_item_sk1119;
    int32_t _cs_bill_customer_sk1107;
    bool operator==(const SW_Aggregate_TD_6327308_key& other) const { return (_d_year4281 == other._d_year4281) && (_cs_item_sk1119 == other._cs_item_sk1119) && (_cs_bill_customer_sk1107 == other._cs_bill_customer_sk1107); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_6327308_key> {
    std::size_t operator() (const SW_Aggregate_TD_6327308_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_year4281)) + (hash<int32_t>()(k._cs_item_sk1119)) + (hash<int32_t>()(k._cs_bill_customer_sk1107));
    }
};
}
struct SW_Aggregate_TD_6327308_payload {
    int32_t _cs_sold_year4266;
    int32_t _cs_customer_sk4267;
    int64_t _cs_qty4268L_sum_0;
    int64_t _cs_wc4269_sum_1;
    int64_t _cs_sp4270_sum_2;
};
void SW_Aggregate_TD_6327308(Table &tbl_JOIN_INNER_TD_7958840_output, Table &tbl_Aggregate_TD_6327308_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(d_year#4281, cs_item_sk#1119, cs_bill_customer_sk#1107, d_year#4281 AS cs_sold_year#4266, cs_bill_customer_sk#1107 AS cs_customer_sk#4267, sum(cs_quantity#1122) AS cs_qty#4268L, MakeDecimal(sum(UnscaledValue(cs_wholesale_cost#1123)),17,2) AS cs_wc#4269, MakeDecimal(sum(UnscaledValue(cs_sales_price#1125)),17,2) AS cs_sp#4270)
    // Input: ListBuffer(cs_bill_customer_sk#1107, cs_item_sk#1119, cs_quantity#1122, cs_wholesale_cost#1123, cs_sales_price#1125, d_year#4281)
    // Output: ListBuffer(cs_sold_year#4266, cs_item_sk#1119, cs_customer_sk#4267, cs_qty#4268L, cs_wc#4269, cs_sp#4270)
    std::unordered_map<SW_Aggregate_TD_6327308_key, SW_Aggregate_TD_6327308_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_7958840_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_bill_customer_sk1107 = tbl_JOIN_INNER_TD_7958840_output.getInt32(i, 0);
        int32_t _cs_item_sk1119 = tbl_JOIN_INNER_TD_7958840_output.getInt32(i, 1);
        int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_7958840_output.getInt32(i, 2);
        int64_t _cs_wholesale_cost1123 = tbl_JOIN_INNER_TD_7958840_output.getInt64(i, 3);
        int64_t _cs_sales_price1125 = tbl_JOIN_INNER_TD_7958840_output.getInt64(i, 4);
        int32_t _d_year4281 = tbl_JOIN_INNER_TD_7958840_output.getInt32(i, 5);
        SW_Aggregate_TD_6327308_key k{_d_year4281, _cs_item_sk1119, _cs_bill_customer_sk1107};
        int32_t _cs_sold_year4266 = _d_year4281;
        int32_t _cs_customer_sk4267 = _cs_bill_customer_sk1107;
        int64_t _cs_qty4268L_sum_0 = _cs_quantity1122;
        int64_t _cs_wc4269_sum_1 = _cs_wholesale_cost1123;
        int64_t _cs_sp4270_sum_2 = _cs_sales_price1125;
        SW_Aggregate_TD_6327308_payload p{_cs_sold_year4266, _cs_customer_sk4267, _cs_qty4268L_sum_0, _cs_wc4269_sum_1, _cs_sp4270_sum_2};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._cs_qty4268L_sum_0 + _cs_qty4268L_sum_0;
            p._cs_qty4268L_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._cs_wc4269_sum_1 + _cs_wc4269_sum_1;
            p._cs_wc4269_sum_1 = sum_1;
            int64_t sum_2 = (it->second)._cs_sp4270_sum_2 + _cs_sp4270_sum_2;
            p._cs_sp4270_sum_2 = sum_2;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _d_year4281 not required in the output table
        tbl_Aggregate_TD_6327308_output.setInt32(r, 1, (it.first)._cs_item_sk1119);
        // _cs_bill_customer_sk1107 not required in the output table
        tbl_Aggregate_TD_6327308_output.setInt32(r, 0, (it.second)._cs_sold_year4266);
        tbl_Aggregate_TD_6327308_output.setInt32(r, 2, (it.second)._cs_customer_sk4267);
        int64_t _cs_qty4268L = (it.second)._cs_qty4268L_sum_0;
        tbl_Aggregate_TD_6327308_output.setInt64(r, 3, _cs_qty4268L);
        int64_t _cs_wc4269 = (it.second)._cs_wc4269_sum_1;
        tbl_Aggregate_TD_6327308_output.setInt64(r, 4, _cs_wc4269);
        int64_t _cs_sp4270 = (it.second)._cs_sp4270_sum_2;
        tbl_Aggregate_TD_6327308_output.setInt64(r, 5, _cs_sp4270);
        ++r;
    }
    tbl_Aggregate_TD_6327308_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_6327308_output #Row: " << tbl_Aggregate_TD_6327308_output.getNumRow() << std::endl;
}

struct SW_JOIN_LEFTOUTER_TD_6605679_key {
    int32_t _ws_sold_year4261;
    int32_t _ws_item_sk732;
    int32_t _ws_customer_sk4262;
    bool operator==(const SW_JOIN_LEFTOUTER_TD_6605679_key& other) const {
        return ((_ws_sold_year4261 == other._ws_sold_year4261) && (_ws_item_sk732 == other._ws_item_sk732) && (_ws_customer_sk4262 == other._ws_customer_sk4262));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTOUTER_TD_6605679_key> {
    std::size_t operator() (const SW_JOIN_LEFTOUTER_TD_6605679_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_sold_year4261)) + (hash<int32_t>()(k._ws_item_sk732)) + (hash<int32_t>()(k._ws_customer_sk4262));
    }
};
}
struct SW_JOIN_LEFTOUTER_TD_6605679_payload {
    int32_t _ws_sold_year4261;
    int32_t _ws_item_sk732;
    int32_t _ws_customer_sk4262;
    int64_t _ws_qty4263L;
    int64_t _ws_wc4264;
    int64_t _ws_sp4265;
};
void SW_JOIN_LEFTOUTER_TD_6605679(Table &tbl_Aggregate_TD_7527825_output, Table &tbl_Aggregate_TD_7416502_output, Table &tbl_JOIN_LEFTOUTER_TD_6605679_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTOUTER
    // Operation: ListBuffer((((ws_sold_year#4261 = ss_sold_year#4271) AND (ws_item_sk#732 = ss_item_sk#1208)) AND (ws_customer_sk#4262 = ss_customer_sk#1209)))
    // Left Table: ListBuffer(ss_sold_year#4271, ss_item_sk#1208, ss_customer_sk#1209, ss_qty#4272L, ss_wc#4273, ss_sp#4274)
    // Right Table: ListBuffer(ws_sold_year#4261, ws_item_sk#732, ws_customer_sk#4262, ws_qty#4263L, ws_wc#4264, ws_sp#4265)
    // Output Table: ListBuffer(ss_sold_year#4271, ss_item_sk#1208, ss_customer_sk#1209, ss_qty#4272L, ss_wc#4273, ss_sp#4274, ws_qty#4263L, ws_wc#4264, ws_sp#4265)
    std::unordered_multimap<SW_JOIN_LEFTOUTER_TD_6605679_key, SW_JOIN_LEFTOUTER_TD_6605679_payload> ht1;
    int nrow1 = tbl_Aggregate_TD_7416502_output.getNumRow();
    int nrow2 = tbl_Aggregate_TD_7527825_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_sold_year4261_k = tbl_Aggregate_TD_7416502_output.getInt32(i, 0);
        int32_t _ws_item_sk732_k = tbl_Aggregate_TD_7416502_output.getInt32(i, 1);
        int32_t _ws_customer_sk4262_k = tbl_Aggregate_TD_7416502_output.getInt32(i, 2);
        SW_JOIN_LEFTOUTER_TD_6605679_key keyA{_ws_sold_year4261_k, _ws_item_sk732_k, _ws_customer_sk4262_k};
        int32_t _ws_sold_year4261 = tbl_Aggregate_TD_7416502_output.getInt32(i, 0);
        int32_t _ws_item_sk732 = tbl_Aggregate_TD_7416502_output.getInt32(i, 1);
        int32_t _ws_customer_sk4262 = tbl_Aggregate_TD_7416502_output.getInt32(i, 2);
        int64_t _ws_qty4263L = tbl_Aggregate_TD_7416502_output.getInt64(i, 3);
        int64_t _ws_wc4264 = tbl_Aggregate_TD_7416502_output.getInt64(i, 4);
        int64_t _ws_sp4265 = tbl_Aggregate_TD_7416502_output.getInt64(i, 5);
        SW_JOIN_LEFTOUTER_TD_6605679_payload payloadA{_ws_sold_year4261, _ws_item_sk732, _ws_customer_sk4262, _ws_qty4263L, _ws_wc4264, _ws_sp4265};
        ht1.insert(std::make_pair(keyA, payloadA));
    }
    int r = 0;
    for (int i = 0; i < nrow2; i++) {
        int32_t _ss_sold_year4271_k = tbl_Aggregate_TD_7527825_output.getInt32(i, 0);
        int32_t _ss_item_sk1208_k = tbl_Aggregate_TD_7527825_output.getInt32(i, 1);
        int32_t _ss_customer_sk1209_k = tbl_Aggregate_TD_7527825_output.getInt32(i, 2);
        auto it = ht1.find(SW_JOIN_LEFTOUTER_TD_6605679_key{_ss_sold_year4271_k, _ss_item_sk1208_k, _ss_customer_sk1209_k});
        int32_t _ss_sold_year4271 = tbl_Aggregate_TD_7527825_output.getInt32(i, 0);
        int32_t _ss_item_sk1208 = tbl_Aggregate_TD_7527825_output.getInt32(i, 1);
        int32_t _ss_customer_sk1209 = tbl_Aggregate_TD_7527825_output.getInt32(i, 2);
        int64_t _ss_qty4272L = tbl_Aggregate_TD_7527825_output.getInt64(i, 3);
        int64_t _ss_wc4273 = tbl_Aggregate_TD_7527825_output.getInt64(i, 4);
        int64_t _ss_sp4274 = tbl_Aggregate_TD_7527825_output.getInt64(i, 5);
        if (it != ht1.end()) {
            auto its = ht1.equal_range(SW_JOIN_LEFTOUTER_TD_6605679_key{_ss_sold_year4271_k, _ss_item_sk1208_k, _ss_customer_sk1209_k});
            auto it_it = its.first;
            while (it_it != its.second) {
                int32_t _ws_sold_year4261 = (it_it->second)._ws_sold_year4261;
                int32_t _ws_item_sk732 = (it_it->second)._ws_item_sk732;
                int32_t _ws_customer_sk4262 = (it_it->second)._ws_customer_sk4262;
                int64_t _ws_qty4263L = (it_it->second)._ws_qty4263L;
                int64_t _ws_wc4264 = (it_it->second)._ws_wc4264;
                int64_t _ws_sp4265 = (it_it->second)._ws_sp4265;
                tbl_JOIN_LEFTOUTER_TD_6605679_output.setInt64(r, 6, _ws_qty4263L);
                tbl_JOIN_LEFTOUTER_TD_6605679_output.setInt64(r, 7, _ws_wc4264);
                tbl_JOIN_LEFTOUTER_TD_6605679_output.setInt64(r, 8, _ws_sp4265);
                tbl_JOIN_LEFTOUTER_TD_6605679_output.setInt32(r, 0, _ss_sold_year4271);
                tbl_JOIN_LEFTOUTER_TD_6605679_output.setInt32(r, 1, _ss_item_sk1208);
                tbl_JOIN_LEFTOUTER_TD_6605679_output.setInt32(r, 2, _ss_customer_sk1209);
                tbl_JOIN_LEFTOUTER_TD_6605679_output.setInt64(r, 3, _ss_qty4272L);
                tbl_JOIN_LEFTOUTER_TD_6605679_output.setInt64(r, 4, _ss_wc4273);
                tbl_JOIN_LEFTOUTER_TD_6605679_output.setInt64(r, 5, _ss_sp4274);
                it_it++;
                r++;
            }
        } else {
            tbl_JOIN_LEFTOUTER_TD_6605679_output.setInt32(r, 0, _ss_sold_year4271);
            tbl_JOIN_LEFTOUTER_TD_6605679_output.setInt32(r, 1, _ss_item_sk1208);
            tbl_JOIN_LEFTOUTER_TD_6605679_output.setInt32(r, 2, _ss_customer_sk1209);
            tbl_JOIN_LEFTOUTER_TD_6605679_output.setInt64(r, 3, _ss_qty4272L);
            tbl_JOIN_LEFTOUTER_TD_6605679_output.setInt64(r, 4, _ss_wc4273);
            tbl_JOIN_LEFTOUTER_TD_6605679_output.setInt64(r, 5, _ss_sp4274);
            r++;
        }
    }
    tbl_JOIN_LEFTOUTER_TD_6605679_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTOUTER_TD_6605679_output #Row: " << tbl_JOIN_LEFTOUTER_TD_6605679_output.getNumRow() << std::endl;
}

struct SW_JOIN_LEFTOUTER_TD_5348560_key {
    int32_t _cs_sold_year4266;
    int32_t _cs_item_sk1119;
    int32_t _cs_customer_sk4267;
    bool operator==(const SW_JOIN_LEFTOUTER_TD_5348560_key& other) const {
        return ((_cs_sold_year4266 == other._cs_sold_year4266) && (_cs_item_sk1119 == other._cs_item_sk1119) && (_cs_customer_sk4267 == other._cs_customer_sk4267));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTOUTER_TD_5348560_key> {
    std::size_t operator() (const SW_JOIN_LEFTOUTER_TD_5348560_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_sold_year4266)) + (hash<int32_t>()(k._cs_item_sk1119)) + (hash<int32_t>()(k._cs_customer_sk4267));
    }
};
}
struct SW_JOIN_LEFTOUTER_TD_5348560_payload {
    int32_t _cs_sold_year4266;
    int32_t _cs_item_sk1119;
    int32_t _cs_customer_sk4267;
    int64_t _cs_qty4268L;
    int64_t _cs_wc4269;
    int64_t _cs_sp4270;
};
void SW_JOIN_LEFTOUTER_TD_5348560(Table &tbl_JOIN_LEFTOUTER_TD_6605679_output, Table &tbl_Aggregate_TD_6327308_output, Table &tbl_JOIN_LEFTOUTER_TD_5348560_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTOUTER
    // Operation: ListBuffer((((cs_sold_year#4266 = ss_sold_year#4271) AND (cs_item_sk#1119 = ss_item_sk#1208)) AND (cs_customer_sk#4267 = ss_customer_sk#1209)))
    // Left Table: ListBuffer(ss_sold_year#4271, ss_item_sk#1208, ss_customer_sk#1209, ss_qty#4272L, ss_wc#4273, ss_sp#4274, ws_qty#4263L, ws_wc#4264, ws_sp#4265)
    // Right Table: ListBuffer(cs_sold_year#4266, cs_item_sk#1119, cs_customer_sk#4267, cs_qty#4268L, cs_wc#4269, cs_sp#4270)
    // Output Table: ListBuffer(ss_sold_year#4271, ss_item_sk#1208, ss_customer_sk#1209, ss_qty#4272L, ws_qty#4263L, cs_qty#4268L, ss_wc#4273, ss_sp#4274, ws_wc#4264, cs_wc#4269, ws_sp#4265, cs_sp#4270)
    std::unordered_multimap<SW_JOIN_LEFTOUTER_TD_5348560_key, SW_JOIN_LEFTOUTER_TD_5348560_payload> ht1;
    int nrow1 = tbl_Aggregate_TD_6327308_output.getNumRow();
    int nrow2 = tbl_JOIN_LEFTOUTER_TD_6605679_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_sold_year4266_k = tbl_Aggregate_TD_6327308_output.getInt32(i, 0);
        int32_t _cs_item_sk1119_k = tbl_Aggregate_TD_6327308_output.getInt32(i, 1);
        int32_t _cs_customer_sk4267_k = tbl_Aggregate_TD_6327308_output.getInt32(i, 2);
        SW_JOIN_LEFTOUTER_TD_5348560_key keyA{_cs_sold_year4266_k, _cs_item_sk1119_k, _cs_customer_sk4267_k};
        int32_t _cs_sold_year4266 = tbl_Aggregate_TD_6327308_output.getInt32(i, 0);
        int32_t _cs_item_sk1119 = tbl_Aggregate_TD_6327308_output.getInt32(i, 1);
        int32_t _cs_customer_sk4267 = tbl_Aggregate_TD_6327308_output.getInt32(i, 2);
        int64_t _cs_qty4268L = tbl_Aggregate_TD_6327308_output.getInt64(i, 3);
        int64_t _cs_wc4269 = tbl_Aggregate_TD_6327308_output.getInt64(i, 4);
        int64_t _cs_sp4270 = tbl_Aggregate_TD_6327308_output.getInt64(i, 5);
        SW_JOIN_LEFTOUTER_TD_5348560_payload payloadA{_cs_sold_year4266, _cs_item_sk1119, _cs_customer_sk4267, _cs_qty4268L, _cs_wc4269, _cs_sp4270};
        ht1.insert(std::make_pair(keyA, payloadA));
    }
    int r = 0;
    for (int i = 0; i < nrow2; i++) {
        int32_t _ss_sold_year4271_k = tbl_JOIN_LEFTOUTER_TD_6605679_output.getInt32(i, 0);
        int32_t _ss_item_sk1208_k = tbl_JOIN_LEFTOUTER_TD_6605679_output.getInt32(i, 1);
        int32_t _ss_customer_sk1209_k = tbl_JOIN_LEFTOUTER_TD_6605679_output.getInt32(i, 2);
        auto it = ht1.find(SW_JOIN_LEFTOUTER_TD_5348560_key{_ss_sold_year4271_k, _ss_item_sk1208_k, _ss_customer_sk1209_k});
        int32_t _ss_sold_year4271 = tbl_JOIN_LEFTOUTER_TD_6605679_output.getInt32(i, 0);
        int32_t _ss_item_sk1208 = tbl_JOIN_LEFTOUTER_TD_6605679_output.getInt32(i, 1);
        int32_t _ss_customer_sk1209 = tbl_JOIN_LEFTOUTER_TD_6605679_output.getInt32(i, 2);
        int64_t _ss_qty4272L = tbl_JOIN_LEFTOUTER_TD_6605679_output.getInt64(i, 3);
        int64_t _ss_wc4273 = tbl_JOIN_LEFTOUTER_TD_6605679_output.getInt64(i, 4);
        int64_t _ss_sp4274 = tbl_JOIN_LEFTOUTER_TD_6605679_output.getInt64(i, 5);
        int64_t _ws_qty4263L = tbl_JOIN_LEFTOUTER_TD_6605679_output.getInt64(i, 6);
        int64_t _ws_wc4264 = tbl_JOIN_LEFTOUTER_TD_6605679_output.getInt64(i, 7);
        int64_t _ws_sp4265 = tbl_JOIN_LEFTOUTER_TD_6605679_output.getInt64(i, 8);
        if (it != ht1.end()) {
            auto its = ht1.equal_range(SW_JOIN_LEFTOUTER_TD_5348560_key{_ss_sold_year4271_k, _ss_item_sk1208_k, _ss_customer_sk1209_k});
            auto it_it = its.first;
            while (it_it != its.second) {
                int32_t _cs_sold_year4266 = (it_it->second)._cs_sold_year4266;
                int32_t _cs_item_sk1119 = (it_it->second)._cs_item_sk1119;
                int32_t _cs_customer_sk4267 = (it_it->second)._cs_customer_sk4267;
                int64_t _cs_qty4268L = (it_it->second)._cs_qty4268L;
                int64_t _cs_wc4269 = (it_it->second)._cs_wc4269;
                int64_t _cs_sp4270 = (it_it->second)._cs_sp4270;
                tbl_JOIN_LEFTOUTER_TD_5348560_output.setInt64(r, 5, _cs_qty4268L);
                tbl_JOIN_LEFTOUTER_TD_5348560_output.setInt64(r, 9, _cs_wc4269);
                tbl_JOIN_LEFTOUTER_TD_5348560_output.setInt64(r, 11, _cs_sp4270);
                tbl_JOIN_LEFTOUTER_TD_5348560_output.setInt32(r, 0, _ss_sold_year4271);
                tbl_JOIN_LEFTOUTER_TD_5348560_output.setInt32(r, 1, _ss_item_sk1208);
                tbl_JOIN_LEFTOUTER_TD_5348560_output.setInt32(r, 2, _ss_customer_sk1209);
                tbl_JOIN_LEFTOUTER_TD_5348560_output.setInt64(r, 3, _ss_qty4272L);
                tbl_JOIN_LEFTOUTER_TD_5348560_output.setInt64(r, 6, _ss_wc4273);
                tbl_JOIN_LEFTOUTER_TD_5348560_output.setInt64(r, 7, _ss_sp4274);
                tbl_JOIN_LEFTOUTER_TD_5348560_output.setInt64(r, 4, _ws_qty4263L);
                tbl_JOIN_LEFTOUTER_TD_5348560_output.setInt64(r, 8, _ws_wc4264);
                tbl_JOIN_LEFTOUTER_TD_5348560_output.setInt64(r, 10, _ws_sp4265);
                it_it++;
                r++;
            }
        } else {
            tbl_JOIN_LEFTOUTER_TD_5348560_output.setInt32(r, 0, _ss_sold_year4271);
            tbl_JOIN_LEFTOUTER_TD_5348560_output.setInt32(r, 1, _ss_item_sk1208);
            tbl_JOIN_LEFTOUTER_TD_5348560_output.setInt32(r, 2, _ss_customer_sk1209);
            tbl_JOIN_LEFTOUTER_TD_5348560_output.setInt64(r, 3, _ss_qty4272L);
            tbl_JOIN_LEFTOUTER_TD_5348560_output.setInt64(r, 6, _ss_wc4273);
            tbl_JOIN_LEFTOUTER_TD_5348560_output.setInt64(r, 7, _ss_sp4274);
            tbl_JOIN_LEFTOUTER_TD_5348560_output.setInt64(r, 4, _ws_qty4263L);
            tbl_JOIN_LEFTOUTER_TD_5348560_output.setInt64(r, 8, _ws_wc4264);
            tbl_JOIN_LEFTOUTER_TD_5348560_output.setInt64(r, 10, _ws_sp4265);
            r++;
        }
    }
    tbl_JOIN_LEFTOUTER_TD_5348560_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTOUTER_TD_5348560_output #Row: " << tbl_JOIN_LEFTOUTER_TD_5348560_output.getNumRow() << std::endl;
}

void SW_Filter_TD_4962810(Table &tbl_JOIN_LEFTOUTER_TD_5348560_output, Table &tbl_Filter_TD_4962810_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((coalesce(ws_qty#4263L, 0) > 0) OR (coalesce(cs_qty#4268L, 0) > 0)))
    // Input: ListBuffer(ss_sold_year#4271, ss_item_sk#1208, ss_customer_sk#1209, ss_qty#4272L, ws_qty#4263L, cs_qty#4268L, ss_wc#4273, ss_sp#4274, ws_wc#4264, cs_wc#4269, ws_sp#4265, cs_sp#4270)
    // Output: ListBuffer(ss_sold_year#4271, ss_item_sk#1208, ss_customer_sk#1209, ss_qty#4272L, ws_qty#4263L, cs_qty#4268L, ss_wc#4273, ss_sp#4274, ws_wc#4264, cs_wc#4269, ws_sp#4265, cs_sp#4270)
    int r = 0;
    int nrow1 = tbl_JOIN_LEFTOUTER_TD_5348560_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ws_qty4263L = tbl_JOIN_LEFTOUTER_TD_5348560_output.getInt64(i, 4);
        int64_t _cs_qty4268L = tbl_JOIN_LEFTOUTER_TD_5348560_output.getInt64(i, 5);
        if ((_ws_qty4263L > 0) || (_cs_qty4268L > 0)) {
            int32_t _ss_sold_year4271_t = tbl_JOIN_LEFTOUTER_TD_5348560_output.getInt32(i, 0);
            tbl_Filter_TD_4962810_output.setInt32(r, 0, _ss_sold_year4271_t);
            int32_t _ss_item_sk1208_t = tbl_JOIN_LEFTOUTER_TD_5348560_output.getInt32(i, 1);
            tbl_Filter_TD_4962810_output.setInt32(r, 1, _ss_item_sk1208_t);
            int32_t _ss_customer_sk1209_t = tbl_JOIN_LEFTOUTER_TD_5348560_output.getInt32(i, 2);
            tbl_Filter_TD_4962810_output.setInt32(r, 2, _ss_customer_sk1209_t);
            int64_t _ss_qty4272L_t = tbl_JOIN_LEFTOUTER_TD_5348560_output.getInt64(i, 3);
            tbl_Filter_TD_4962810_output.setInt64(r, 3, _ss_qty4272L_t);
            int64_t _ws_qty4263L_t = tbl_JOIN_LEFTOUTER_TD_5348560_output.getInt64(i, 4);
            tbl_Filter_TD_4962810_output.setInt64(r, 4, _ws_qty4263L_t);
            int64_t _cs_qty4268L_t = tbl_JOIN_LEFTOUTER_TD_5348560_output.getInt64(i, 5);
            tbl_Filter_TD_4962810_output.setInt64(r, 5, _cs_qty4268L_t);
            int64_t _ss_wc4273_t = tbl_JOIN_LEFTOUTER_TD_5348560_output.getInt64(i, 6);
            tbl_Filter_TD_4962810_output.setInt64(r, 6, _ss_wc4273_t);
            int64_t _ss_sp4274_t = tbl_JOIN_LEFTOUTER_TD_5348560_output.getInt64(i, 7);
            tbl_Filter_TD_4962810_output.setInt64(r, 7, _ss_sp4274_t);
            int64_t _ws_wc4264_t = tbl_JOIN_LEFTOUTER_TD_5348560_output.getInt64(i, 8);
            tbl_Filter_TD_4962810_output.setInt64(r, 8, _ws_wc4264_t);
            int64_t _cs_wc4269_t = tbl_JOIN_LEFTOUTER_TD_5348560_output.getInt64(i, 9);
            tbl_Filter_TD_4962810_output.setInt64(r, 9, _cs_wc4269_t);
            int64_t _ws_sp4265_t = tbl_JOIN_LEFTOUTER_TD_5348560_output.getInt64(i, 10);
            tbl_Filter_TD_4962810_output.setInt64(r, 10, _ws_sp4265_t);
            int64_t _cs_sp4270_t = tbl_JOIN_LEFTOUTER_TD_5348560_output.getInt64(i, 11);
            tbl_Filter_TD_4962810_output.setInt64(r, 11, _cs_sp4270_t);
            r++;
        }
    }
    tbl_Filter_TD_4962810_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4962810_output #Row: " << tbl_Filter_TD_4962810_output.getNumRow() << std::endl;
}

void SW_Project_TD_3467215(Table &tbl_Filter_TD_4962810_output, Table &tbl_Project_TD_3467215_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(round((cast(ss_qty#4272L as double) / cast((coalesce(ws_qty#4263L, 0) + coalesce(cs_qty#4268L, 0)) as double)), 2) AS ratio#4254, ss_qty#4272L AS store_qty#4255L, ss_wc#4273 AS store_wholesale_cost#4256, ss_sp#4274 AS store_sales_price#4257, (coalesce(ws_qty#4263L, 0) + coalesce(cs_qty#4268L, 0)) AS other_chan_qty#4258L, CheckOverflow((promote_precision(cast(coalesce(ws_wc#4264, 0.00) as decimal(18,2))) + promote_precision(cast(coalesce(cs_wc#4269, 0.00) as decimal(18,2)))), DecimalType(18,2), true) AS other_chan_wholesale_cost#4259, CheckOverflow((promote_precision(cast(coalesce(ws_sp#4265, 0.00) as decimal(18,2))) + promote_precision(cast(coalesce(cs_sp#4270, 0.00) as decimal(18,2)))), DecimalType(18,2), true) AS other_chan_sales_price#4260)
    // Input: ListBuffer(ss_sold_year#4271, ss_item_sk#1208, ss_customer_sk#1209, ss_qty#4272L, ws_qty#4263L, cs_qty#4268L, ss_wc#4273, ss_sp#4274, ws_wc#4264, cs_wc#4269, ws_sp#4265, cs_sp#4270)
    // Output: ListBuffer(ss_sold_year#4271, ss_item_sk#1208, ss_customer_sk#1209, ratio#4254, store_qty#4255L, store_wholesale_cost#4256, store_sales_price#4257, other_chan_qty#4258L, other_chan_wholesale_cost#4259, other_chan_sales_price#4260, ss_qty#4272L, ss_wc#4273, ss_sp#4274)
    int nrow1 = tbl_Filter_TD_4962810_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_year4271 = tbl_Filter_TD_4962810_output.getInt32(i, 0);
        int32_t _ss_item_sk1208 = tbl_Filter_TD_4962810_output.getInt32(i, 1);
        int32_t _ss_customer_sk1209 = tbl_Filter_TD_4962810_output.getInt32(i, 2);
        int64_t _ss_qty4272L = tbl_Filter_TD_4962810_output.getInt64(i, 3);
        int64_t _ws_qty4263L = tbl_Filter_TD_4962810_output.getInt64(i, 4);
        int64_t _cs_qty4268L = tbl_Filter_TD_4962810_output.getInt64(i, 5);
        int64_t _ss_wc4273 = tbl_Filter_TD_4962810_output.getInt64(i, 6);
        int64_t _ss_sp4274 = tbl_Filter_TD_4962810_output.getInt64(i, 7);
        int64_t _ws_wc4264 = tbl_Filter_TD_4962810_output.getInt64(i, 8);
        int64_t _cs_wc4269 = tbl_Filter_TD_4962810_output.getInt64(i, 9);
        int64_t _ws_sp4265 = tbl_Filter_TD_4962810_output.getInt64(i, 10);
        int64_t _cs_sp4270 = tbl_Filter_TD_4962810_output.getInt64(i, 11);
        int64_t _ratio4254 = (_ss_qty4272L / (_ws_qty4263L != 0 ? _ws_qty4263L : 0 + _cs_qty4268L != 0 ? _cs_qty4268L : 0));
        tbl_Project_TD_3467215_output.setInt64(i, 3, _ratio4254);
        int64_t _store_qty4255L = _ss_qty4272L;
        tbl_Project_TD_3467215_output.setInt64(i, 4, _store_qty4255L);
        int64_t _store_wholesale_cost4256 = _ss_wc4273;
        tbl_Project_TD_3467215_output.setInt64(i, 5, _store_wholesale_cost4256);
        int64_t _store_sales_price4257 = _ss_sp4274;
        tbl_Project_TD_3467215_output.setInt64(i, 6, _store_sales_price4257);
        int64_t _other_chan_qty4258L = (_ws_qty4263L != 0 ? _ws_qty4263L : 0 + _cs_qty4268L != 0 ? _cs_qty4268L : 0);
        tbl_Project_TD_3467215_output.setInt64(i, 7, _other_chan_qty4258L);
        int64_t _other_chan_wholesale_cost4259 = (_ws_wc4264 != 0 ? _ws_wc4264 : 0.00 + _cs_wc4269 != 0 ? _cs_wc4269 : 0.00);
        tbl_Project_TD_3467215_output.setInt64(i, 8, _other_chan_wholesale_cost4259);
        int64_t _other_chan_sales_price4260 = (_ws_sp4265 != 0 ? _ws_sp4265 : 0.00 + _cs_sp4270 != 0 ? _cs_sp4270 : 0.00);
        tbl_Project_TD_3467215_output.setInt64(i, 9, _other_chan_sales_price4260);
        tbl_Project_TD_3467215_output.setInt32(i, 0, _ss_sold_year4271);
        tbl_Project_TD_3467215_output.setInt32(i, 1, _ss_item_sk1208);
        tbl_Project_TD_3467215_output.setInt32(i, 2, _ss_customer_sk1209);
        tbl_Project_TD_3467215_output.setInt64(i, 10, _ss_qty4272L);
        tbl_Project_TD_3467215_output.setInt64(i, 11, _ss_wc4273);
        tbl_Project_TD_3467215_output.setInt64(i, 12, _ss_sp4274);
    }
    tbl_Project_TD_3467215_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_3467215_output #Row: " << tbl_Project_TD_3467215_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2920142(Table &tbl_Project_TD_3467215_output, Table &tbl_Sort_TD_2920142_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(ss_sold_year#4271 ASC NULLS FIRST, ss_item_sk#1208 ASC NULLS FIRST, ss_customer_sk#1209 ASC NULLS FIRST, ss_qty#4272L DESC NULLS LAST, ss_wc#4273 DESC NULLS LAST, ss_sp#4274 DESC NULLS LAST, other_chan_qty#4258L ASC NULLS FIRST, other_chan_wholesale_cost#4259 ASC NULLS FIRST, other_chan_sales_price#4260 ASC NULLS FIRST)
    // Input: ListBuffer(ss_sold_year#4271, ss_item_sk#1208, ss_customer_sk#1209, ratio#4254, store_qty#4255L, store_wholesale_cost#4256, store_sales_price#4257, other_chan_qty#4258L, other_chan_wholesale_cost#4259, other_chan_sales_price#4260, ss_qty#4272L, ss_wc#4273, ss_sp#4274)
    // Output: ListBuffer(ss_sold_year#4271, ss_item_sk#1208, ss_customer_sk#1209, ratio#4254, store_qty#4255L, store_wholesale_cost#4256, store_sales_price#4257, other_chan_qty#4258L, other_chan_wholesale_cost#4259, other_chan_sales_price#4260, ss_qty#4272L, ss_wc#4273, ss_sp#4274)
    struct SW_Sort_TD_2920142Row {
        int32_t _ss_sold_year4271;
        int32_t _ss_item_sk1208;
        int32_t _ss_customer_sk1209;
        int64_t _ratio4254;
        int64_t _store_qty4255L;
        int64_t _store_wholesale_cost4256;
        int64_t _store_sales_price4257;
        int64_t _other_chan_qty4258L;
        int64_t _other_chan_wholesale_cost4259;
        int64_t _other_chan_sales_price4260;
        int64_t _ss_qty4272L;
        int64_t _ss_wc4273;
        int64_t _ss_sp4274;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2920142Row& a, const SW_Sort_TD_2920142Row& b) const { return 
 (a._ss_sold_year4271 < b._ss_sold_year4271) || 
 ((a._ss_sold_year4271 == b._ss_sold_year4271) && (a._ss_item_sk1208 < b._ss_item_sk1208)) || 
 ((a._ss_sold_year4271 == b._ss_sold_year4271) && (a._ss_item_sk1208 == b._ss_item_sk1208) && (a._ss_customer_sk1209 < b._ss_customer_sk1209)) || 
 ((a._ss_sold_year4271 == b._ss_sold_year4271) && (a._ss_item_sk1208 == b._ss_item_sk1208) && (a._ss_customer_sk1209 == b._ss_customer_sk1209) && (a._ss_qty4272L > b._ss_qty4272L)) || 
 ((a._ss_sold_year4271 == b._ss_sold_year4271) && (a._ss_item_sk1208 == b._ss_item_sk1208) && (a._ss_customer_sk1209 == b._ss_customer_sk1209) && (a._ss_qty4272L == b._ss_qty4272L) && (a._ss_wc4273 > b._ss_wc4273)) || 
 ((a._ss_sold_year4271 == b._ss_sold_year4271) && (a._ss_item_sk1208 == b._ss_item_sk1208) && (a._ss_customer_sk1209 == b._ss_customer_sk1209) && (a._ss_qty4272L == b._ss_qty4272L) && (a._ss_wc4273 == b._ss_wc4273) && (a._ss_sp4274 > b._ss_sp4274)) || 
 ((a._ss_sold_year4271 == b._ss_sold_year4271) && (a._ss_item_sk1208 == b._ss_item_sk1208) && (a._ss_customer_sk1209 == b._ss_customer_sk1209) && (a._ss_qty4272L == b._ss_qty4272L) && (a._ss_wc4273 == b._ss_wc4273) && (a._ss_sp4274 == b._ss_sp4274) && (a._other_chan_qty4258L < b._other_chan_qty4258L)) || 
 ((a._ss_sold_year4271 == b._ss_sold_year4271) && (a._ss_item_sk1208 == b._ss_item_sk1208) && (a._ss_customer_sk1209 == b._ss_customer_sk1209) && (a._ss_qty4272L == b._ss_qty4272L) && (a._ss_wc4273 == b._ss_wc4273) && (a._ss_sp4274 == b._ss_sp4274) && (a._other_chan_qty4258L == b._other_chan_qty4258L) && (a._other_chan_wholesale_cost4259 < b._other_chan_wholesale_cost4259)) || 
 ((a._ss_sold_year4271 == b._ss_sold_year4271) && (a._ss_item_sk1208 == b._ss_item_sk1208) && (a._ss_customer_sk1209 == b._ss_customer_sk1209) && (a._ss_qty4272L == b._ss_qty4272L) && (a._ss_wc4273 == b._ss_wc4273) && (a._ss_sp4274 == b._ss_sp4274) && (a._other_chan_qty4258L == b._other_chan_qty4258L) && (a._other_chan_wholesale_cost4259 == b._other_chan_wholesale_cost4259) && (a._other_chan_sales_price4260 < b._other_chan_sales_price4260)); 
}
    }SW_Sort_TD_2920142_order; 

    int nrow1 = tbl_Project_TD_3467215_output.getNumRow();
    std::vector<SW_Sort_TD_2920142Row> rows;
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_year4271 = tbl_Project_TD_3467215_output.getInt32(i, 0);
        int32_t _ss_item_sk1208 = tbl_Project_TD_3467215_output.getInt32(i, 1);
        int32_t _ss_customer_sk1209 = tbl_Project_TD_3467215_output.getInt32(i, 2);
        int64_t _ratio4254 = tbl_Project_TD_3467215_output.getInt64(i, 3);
        int64_t _store_qty4255L = tbl_Project_TD_3467215_output.getInt64(i, 4);
        int64_t _store_wholesale_cost4256 = tbl_Project_TD_3467215_output.getInt64(i, 5);
        int64_t _store_sales_price4257 = tbl_Project_TD_3467215_output.getInt64(i, 6);
        int64_t _other_chan_qty4258L = tbl_Project_TD_3467215_output.getInt64(i, 7);
        int64_t _other_chan_wholesale_cost4259 = tbl_Project_TD_3467215_output.getInt64(i, 8);
        int64_t _other_chan_sales_price4260 = tbl_Project_TD_3467215_output.getInt64(i, 9);
        int64_t _ss_qty4272L = tbl_Project_TD_3467215_output.getInt64(i, 10);
        int64_t _ss_wc4273 = tbl_Project_TD_3467215_output.getInt64(i, 11);
        int64_t _ss_sp4274 = tbl_Project_TD_3467215_output.getInt64(i, 12);
        SW_Sort_TD_2920142Row t = {_ss_sold_year4271,_ss_item_sk1208,_ss_customer_sk1209,_ratio4254,_store_qty4255L,_store_wholesale_cost4256,_store_sales_price4257,_other_chan_qty4258L,_other_chan_wholesale_cost4259,_other_chan_sales_price4260,_ss_qty4272L,_ss_wc4273,_ss_sp4274};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2920142_order);
    int r = 0;
    for (auto& it : rows) {
        tbl_Sort_TD_2920142_output.setInt32(r, 0, it._ss_sold_year4271);
        tbl_Sort_TD_2920142_output.setInt32(r, 1, it._ss_item_sk1208);
        tbl_Sort_TD_2920142_output.setInt32(r, 2, it._ss_customer_sk1209);
        tbl_Sort_TD_2920142_output.setInt64(r, 3, it._ratio4254);
        tbl_Sort_TD_2920142_output.setInt64(r, 4, it._store_qty4255L);
        tbl_Sort_TD_2920142_output.setInt64(r, 5, it._store_wholesale_cost4256);
        tbl_Sort_TD_2920142_output.setInt64(r, 6, it._store_sales_price4257);
        tbl_Sort_TD_2920142_output.setInt64(r, 7, it._other_chan_qty4258L);
        tbl_Sort_TD_2920142_output.setInt64(r, 8, it._other_chan_wholesale_cost4259);
        tbl_Sort_TD_2920142_output.setInt64(r, 9, it._other_chan_sales_price4260);
        tbl_Sort_TD_2920142_output.setInt64(r, 10, it._ss_qty4272L);
        tbl_Sort_TD_2920142_output.setInt64(r, 11, it._ss_wc4273);
        tbl_Sort_TD_2920142_output.setInt64(r, 12, it._ss_sp4274);
        ++r;
    }
    tbl_Sort_TD_2920142_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2920142_output #Row: " << tbl_Sort_TD_2920142_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1909826(Table &tbl_Sort_TD_2920142_output, Table &tbl_LocalLimit_TD_1909826_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(ss_sold_year#4271, ss_item_sk#1208, ss_customer_sk#1209, ratio#4254, store_qty#4255L, store_wholesale_cost#4256, store_sales_price#4257, other_chan_qty#4258L, other_chan_wholesale_cost#4259, other_chan_sales_price#4260, ss_qty#4272L, ss_wc#4273, ss_sp#4274)
    // Output: ListBuffer(ss_sold_year#4271, ss_item_sk#1208, ss_customer_sk#1209, ratio#4254, store_qty#4255L, store_wholesale_cost#4256, store_sales_price#4257, other_chan_qty#4258L, other_chan_wholesale_cost#4259, other_chan_sales_price#4260)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        tbl_LocalLimit_TD_1909826_output.setInt32(r, 0, tbl_Sort_TD_2920142_output.getInt32(i, 0));
        tbl_LocalLimit_TD_1909826_output.setInt32(r, 1, tbl_Sort_TD_2920142_output.getInt32(i, 1));
        tbl_LocalLimit_TD_1909826_output.setInt32(r, 2, tbl_Sort_TD_2920142_output.getInt32(i, 2));
        tbl_LocalLimit_TD_1909826_output.setInt64(r, 3, tbl_Sort_TD_2920142_output.getInt64(i, 3));
        tbl_LocalLimit_TD_1909826_output.setInt64(r, 4, tbl_Sort_TD_2920142_output.getInt64(i, 4));
        tbl_LocalLimit_TD_1909826_output.setInt64(r, 5, tbl_Sort_TD_2920142_output.getInt64(i, 5));
        tbl_LocalLimit_TD_1909826_output.setInt64(r, 6, tbl_Sort_TD_2920142_output.getInt64(i, 6));
        tbl_LocalLimit_TD_1909826_output.setInt64(r, 7, tbl_Sort_TD_2920142_output.getInt64(i, 7));
        tbl_LocalLimit_TD_1909826_output.setInt64(r, 8, tbl_Sort_TD_2920142_output.getInt64(i, 8));
        tbl_LocalLimit_TD_1909826_output.setInt64(r, 9, tbl_Sort_TD_2920142_output.getInt64(i, 9));
        r++;
    }
    tbl_LocalLimit_TD_1909826_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1909826_output #Row: " << tbl_LocalLimit_TD_1909826_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0687397(Table &tbl_LocalLimit_TD_1909826_output, Table &tbl_GlobalLimit_TD_0687397_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(ss_sold_year#4271, ss_item_sk#1208, ss_customer_sk#1209, ratio#4254, store_qty#4255L, store_wholesale_cost#4256, store_sales_price#4257, other_chan_qty#4258L, other_chan_wholesale_cost#4259, other_chan_sales_price#4260)
    // Output: ListBuffer(ss_sold_year#4271, ss_item_sk#1208, ss_customer_sk#1209, ratio#4254, store_qty#4255L, store_wholesale_cost#4256, store_sales_price#4257, other_chan_qty#4258L, other_chan_wholesale_cost#4259, other_chan_sales_price#4260)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        tbl_GlobalLimit_TD_0687397_output.setInt32(r, 0, tbl_LocalLimit_TD_1909826_output.getInt32(i, 0));
        tbl_GlobalLimit_TD_0687397_output.setInt32(r, 1, tbl_LocalLimit_TD_1909826_output.getInt32(i, 1));
        tbl_GlobalLimit_TD_0687397_output.setInt32(r, 2, tbl_LocalLimit_TD_1909826_output.getInt32(i, 2));
        tbl_GlobalLimit_TD_0687397_output.setInt64(r, 3, tbl_LocalLimit_TD_1909826_output.getInt64(i, 3));
        tbl_GlobalLimit_TD_0687397_output.setInt64(r, 4, tbl_LocalLimit_TD_1909826_output.getInt64(i, 4));
        tbl_GlobalLimit_TD_0687397_output.setInt64(r, 5, tbl_LocalLimit_TD_1909826_output.getInt64(i, 5));
        tbl_GlobalLimit_TD_0687397_output.setInt64(r, 6, tbl_LocalLimit_TD_1909826_output.getInt64(i, 6));
        tbl_GlobalLimit_TD_0687397_output.setInt64(r, 7, tbl_LocalLimit_TD_1909826_output.getInt64(i, 7));
        tbl_GlobalLimit_TD_0687397_output.setInt64(r, 8, tbl_LocalLimit_TD_1909826_output.getInt64(i, 8));
        tbl_GlobalLimit_TD_0687397_output.setInt64(r, 9, tbl_LocalLimit_TD_1909826_output.getInt64(i, 9));
        r++;
    }
    tbl_GlobalLimit_TD_0687397_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0687397_output #Row: " << tbl_GlobalLimit_TD_0687397_output.getNumRow() << std::endl;
}

