#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_23711028(Table &tbl_SerializeFromObject_TD_24761971_input, Table &tbl_Filter_TD_23711028_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cr_item_sk#4837) AND isnotnull(cr_order_number#4851L)))
    // Input: ListBuffer(cr_item_sk#4837, cr_order_number#4851L, cr_refunded_cash#4858, cr_reversed_charge#4859, cr_store_credit#4860)
    // Output: ListBuffer(cr_item_sk#4837, cr_order_number#4851L, cr_refunded_cash#4858, cr_reversed_charge#4859, cr_store_credit#4860)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_24761971_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cr_item_sk4837 = tbl_SerializeFromObject_TD_24761971_input.getInt32(i, 0);
        int64_t _cr_order_number4851L = tbl_SerializeFromObject_TD_24761971_input.getInt64(i, 1);
        if ((_cr_item_sk4837!= 0) && (_cr_order_number4851L!= 0)) {
            int32_t _cr_item_sk4837_t = tbl_SerializeFromObject_TD_24761971_input.getInt32(i, 0);
            tbl_Filter_TD_23711028_output.setInt32(r, 0, _cr_item_sk4837_t);
            int64_t _cr_order_number4851L_t = tbl_SerializeFromObject_TD_24761971_input.getInt64(i, 1);
            tbl_Filter_TD_23711028_output.setInt64(r, 1, _cr_order_number4851L_t);
            int64_t _cr_refunded_cash4858_t = tbl_SerializeFromObject_TD_24761971_input.getInt64(i, 2);
            tbl_Filter_TD_23711028_output.setInt64(r, 2, _cr_refunded_cash4858_t);
            int64_t _cr_reversed_charge4859_t = tbl_SerializeFromObject_TD_24761971_input.getInt64(i, 3);
            tbl_Filter_TD_23711028_output.setInt64(r, 3, _cr_reversed_charge4859_t);
            int64_t _cr_store_credit4860_t = tbl_SerializeFromObject_TD_24761971_input.getInt64(i, 4);
            tbl_Filter_TD_23711028_output.setInt64(r, 4, _cr_store_credit4860_t);
            r++;
        }
    }
    tbl_Filter_TD_23711028_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_23711028_output #Row: " << tbl_Filter_TD_23711028_output.getNumRow() << std::endl;
}

void SW_Filter_TD_23478920(Table &tbl_SerializeFromObject_TD_24104912_input, Table &tbl_Filter_TD_23478920_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cs_item_sk#4816) AND isnotnull(cs_order_number#4818L)))
    // Input: ListBuffer(cs_item_sk#4816, cs_order_number#4818L, cs_ext_list_price#4826)
    // Output: ListBuffer(cs_item_sk#4816, cs_order_number#4818L, cs_ext_list_price#4826)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_24104912_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_item_sk4816 = tbl_SerializeFromObject_TD_24104912_input.getInt32(i, 0);
        int64_t _cs_order_number4818L = tbl_SerializeFromObject_TD_24104912_input.getInt64(i, 1);
        if ((_cs_item_sk4816!= 0) && (_cs_order_number4818L!= 0)) {
            int32_t _cs_item_sk4816_t = tbl_SerializeFromObject_TD_24104912_input.getInt32(i, 0);
            tbl_Filter_TD_23478920_output.setInt32(r, 0, _cs_item_sk4816_t);
            int64_t _cs_order_number4818L_t = tbl_SerializeFromObject_TD_24104912_input.getInt64(i, 1);
            tbl_Filter_TD_23478920_output.setInt64(r, 1, _cs_order_number4818L_t);
            int64_t _cs_ext_list_price4826_t = tbl_SerializeFromObject_TD_24104912_input.getInt64(i, 2);
            tbl_Filter_TD_23478920_output.setInt64(r, 2, _cs_ext_list_price4826_t);
            r++;
        }
    }
    tbl_Filter_TD_23478920_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_23478920_output #Row: " << tbl_Filter_TD_23478920_output.getNumRow() << std::endl;
}

void SW_Filter_TD_23493262(Table &tbl_SerializeFromObject_TD_24454546_input, Table &tbl_Filter_TD_23493262_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cr_item_sk#1025) AND isnotnull(cr_order_number#1039L)))
    // Input: ListBuffer(cr_item_sk#1025, cr_order_number#1039L, cr_refunded_cash#1046, cr_reversed_charge#1047, cr_store_credit#1048)
    // Output: ListBuffer(cr_item_sk#1025, cr_order_number#1039L, cr_refunded_cash#1046, cr_reversed_charge#1047, cr_store_credit#1048)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_24454546_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cr_item_sk1025 = tbl_SerializeFromObject_TD_24454546_input.getInt32(i, 0);
        int64_t _cr_order_number1039L = tbl_SerializeFromObject_TD_24454546_input.getInt64(i, 1);
        if ((_cr_item_sk1025!= 0) && (_cr_order_number1039L!= 0)) {
            int32_t _cr_item_sk1025_t = tbl_SerializeFromObject_TD_24454546_input.getInt32(i, 0);
            tbl_Filter_TD_23493262_output.setInt32(r, 0, _cr_item_sk1025_t);
            int64_t _cr_order_number1039L_t = tbl_SerializeFromObject_TD_24454546_input.getInt64(i, 1);
            tbl_Filter_TD_23493262_output.setInt64(r, 1, _cr_order_number1039L_t);
            int64_t _cr_refunded_cash1046_t = tbl_SerializeFromObject_TD_24454546_input.getInt64(i, 2);
            tbl_Filter_TD_23493262_output.setInt64(r, 2, _cr_refunded_cash1046_t);
            int64_t _cr_reversed_charge1047_t = tbl_SerializeFromObject_TD_24454546_input.getInt64(i, 3);
            tbl_Filter_TD_23493262_output.setInt64(r, 3, _cr_reversed_charge1047_t);
            int64_t _cr_store_credit1048_t = tbl_SerializeFromObject_TD_24454546_input.getInt64(i, 4);
            tbl_Filter_TD_23493262_output.setInt64(r, 4, _cr_store_credit1048_t);
            r++;
        }
    }
    tbl_Filter_TD_23493262_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_23493262_output #Row: " << tbl_Filter_TD_23493262_output.getNumRow() << std::endl;
}

void SW_Filter_TD_23520356(Table &tbl_SerializeFromObject_TD_24709735_input, Table &tbl_Filter_TD_23520356_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cs_item_sk#1119) AND isnotnull(cs_order_number#1121L)))
    // Input: ListBuffer(cs_item_sk#1119, cs_order_number#1121L, cs_ext_list_price#1129)
    // Output: ListBuffer(cs_item_sk#1119, cs_order_number#1121L, cs_ext_list_price#1129)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_24709735_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_item_sk1119 = tbl_SerializeFromObject_TD_24709735_input.getInt32(i, 0);
        int64_t _cs_order_number1121L = tbl_SerializeFromObject_TD_24709735_input.getInt64(i, 1);
        if ((_cs_item_sk1119!= 0) && (_cs_order_number1121L!= 0)) {
            int32_t _cs_item_sk1119_t = tbl_SerializeFromObject_TD_24709735_input.getInt32(i, 0);
            tbl_Filter_TD_23520356_output.setInt32(r, 0, _cs_item_sk1119_t);
            int64_t _cs_order_number1121L_t = tbl_SerializeFromObject_TD_24709735_input.getInt64(i, 1);
            tbl_Filter_TD_23520356_output.setInt64(r, 1, _cs_order_number1121L_t);
            int64_t _cs_ext_list_price1129_t = tbl_SerializeFromObject_TD_24709735_input.getInt64(i, 2);
            tbl_Filter_TD_23520356_output.setInt64(r, 2, _cs_ext_list_price1129_t);
            r++;
        }
    }
    tbl_Filter_TD_23520356_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_23520356_output #Row: " << tbl_Filter_TD_23520356_output.getNumRow() << std::endl;
}



void SW_Aggregate_TD_21170493_consolidate(Table &tbl_Aggregate_TD_21170493_output_preprocess, Table &tbl_Aggregate_TD_21170493_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_21170493_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _cs_item_sk4816 = tbl_Aggregate_TD_21170493_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_21170493_output.setInt32(r, 0, _cs_item_sk4816);
        int64_t _sale3549 = tbl_Aggregate_TD_21170493_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_21170493_output.setInt64(r, 1, _sale3549);
        int64_t _refund3550 = tbl_Aggregate_TD_21170493_output_preprocess.combineInt64(r, 9, 1);
        tbl_Aggregate_TD_21170493_output.setInt64(r, 2, _refund3550);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_21170493_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_21170493_output #Row: " << tbl_Aggregate_TD_21170493_output.getNumRow() << std::endl;
}

void SW_Filter_TD_21831586(Table &tbl_SerializeFromObject_TD_22126571_input, Table &tbl_Filter_TD_21831586_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(sr_item_sk#4783) AND isnotnull(sr_ticket_number#4790L)))
    // Input: ListBuffer(sr_item_sk#4783, sr_ticket_number#4790L)
    // Output: ListBuffer(sr_item_sk#4783, sr_ticket_number#4790L)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_22126571_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _sr_item_sk4783 = tbl_SerializeFromObject_TD_22126571_input.getInt32(i, 0);
        int64_t _sr_ticket_number4790L = tbl_SerializeFromObject_TD_22126571_input.getInt64(i, 1);
        if ((_sr_item_sk4783!= 0) && (_sr_ticket_number4790L!= 0)) {
            int32_t _sr_item_sk4783_t = tbl_SerializeFromObject_TD_22126571_input.getInt32(i, 0);
            tbl_Filter_TD_21831586_output.setInt32(r, 0, _sr_item_sk4783_t);
            int64_t _sr_ticket_number4790L_t = tbl_SerializeFromObject_TD_22126571_input.getInt64(i, 1);
            tbl_Filter_TD_21831586_output.setInt64(r, 1, _sr_ticket_number4790L_t);
            r++;
        }
    }
    tbl_Filter_TD_21831586_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_21831586_output #Row: " << tbl_Filter_TD_21831586_output.getNumRow() << std::endl;
}

void SW_Filter_TD_21248971(Table &tbl_SerializeFromObject_TD_22217702_input, Table &tbl_Filter_TD_21248971_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((((isnotnull(ss_item_sk#4760) AND isnotnull(ss_ticket_number#4767L)) AND isnotnull(ss_sold_date_sk#4758)) AND (isnotnull(ss_store_sk#4765) AND isnotnull(ss_customer_sk#4761))) AND isnotnull(ss_cdemo_sk#4762)) AND ((isnotnull(ss_promo_sk#4766) AND isnotnull(ss_hdemo_sk#4763)) AND isnotnull(ss_addr_sk#4764))))
    // Input: ListBuffer(ss_sold_date_sk#4758, ss_item_sk#4760, ss_customer_sk#4761, ss_cdemo_sk#4762, ss_hdemo_sk#4763, ss_addr_sk#4764, ss_store_sk#4765, ss_promo_sk#4766, ss_ticket_number#4767L, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777)
    // Output: ListBuffer(ss_sold_date_sk#4758, ss_item_sk#4760, ss_customer_sk#4761, ss_cdemo_sk#4762, ss_hdemo_sk#4763, ss_addr_sk#4764, ss_store_sk#4765, ss_promo_sk#4766, ss_ticket_number#4767L, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_22217702_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_item_sk4760 = tbl_SerializeFromObject_TD_22217702_input.getInt32(i, 1);
        int64_t _ss_ticket_number4767L = tbl_SerializeFromObject_TD_22217702_input.getInt64(i, 8);
        int32_t _ss_sold_date_sk4758 = tbl_SerializeFromObject_TD_22217702_input.getInt32(i, 0);
        int32_t _ss_store_sk4765 = tbl_SerializeFromObject_TD_22217702_input.getInt32(i, 6);
        int32_t _ss_customer_sk4761 = tbl_SerializeFromObject_TD_22217702_input.getInt32(i, 2);
        int32_t _ss_cdemo_sk4762 = tbl_SerializeFromObject_TD_22217702_input.getInt32(i, 3);
        int32_t _ss_promo_sk4766 = tbl_SerializeFromObject_TD_22217702_input.getInt32(i, 7);
        int32_t _ss_hdemo_sk4763 = tbl_SerializeFromObject_TD_22217702_input.getInt32(i, 4);
        int32_t _ss_addr_sk4764 = tbl_SerializeFromObject_TD_22217702_input.getInt32(i, 5);
        if ((((((_ss_item_sk4760!= 0) && (_ss_ticket_number4767L!= 0)) && (_ss_sold_date_sk4758!= 0)) && ((_ss_store_sk4765!= 0) && (_ss_customer_sk4761!= 0))) && (_ss_cdemo_sk4762!= 0)) && (((_ss_promo_sk4766!= 0) && (_ss_hdemo_sk4763!= 0)) && (_ss_addr_sk4764!= 0))) {
            int32_t _ss_sold_date_sk4758_t = tbl_SerializeFromObject_TD_22217702_input.getInt32(i, 0);
            tbl_Filter_TD_21248971_output.setInt32(r, 0, _ss_sold_date_sk4758_t);
            int32_t _ss_item_sk4760_t = tbl_SerializeFromObject_TD_22217702_input.getInt32(i, 1);
            tbl_Filter_TD_21248971_output.setInt32(r, 1, _ss_item_sk4760_t);
            int32_t _ss_customer_sk4761_t = tbl_SerializeFromObject_TD_22217702_input.getInt32(i, 2);
            tbl_Filter_TD_21248971_output.setInt32(r, 2, _ss_customer_sk4761_t);
            int32_t _ss_cdemo_sk4762_t = tbl_SerializeFromObject_TD_22217702_input.getInt32(i, 3);
            tbl_Filter_TD_21248971_output.setInt32(r, 3, _ss_cdemo_sk4762_t);
            int32_t _ss_hdemo_sk4763_t = tbl_SerializeFromObject_TD_22217702_input.getInt32(i, 4);
            tbl_Filter_TD_21248971_output.setInt32(r, 4, _ss_hdemo_sk4763_t);
            int32_t _ss_addr_sk4764_t = tbl_SerializeFromObject_TD_22217702_input.getInt32(i, 5);
            tbl_Filter_TD_21248971_output.setInt32(r, 5, _ss_addr_sk4764_t);
            int32_t _ss_store_sk4765_t = tbl_SerializeFromObject_TD_22217702_input.getInt32(i, 6);
            tbl_Filter_TD_21248971_output.setInt32(r, 6, _ss_store_sk4765_t);
            int32_t _ss_promo_sk4766_t = tbl_SerializeFromObject_TD_22217702_input.getInt32(i, 7);
            tbl_Filter_TD_21248971_output.setInt32(r, 7, _ss_promo_sk4766_t);
            int64_t _ss_ticket_number4767L_t = tbl_SerializeFromObject_TD_22217702_input.getInt64(i, 8);
            tbl_Filter_TD_21248971_output.setInt64(r, 8, _ss_ticket_number4767L_t);
            int64_t _ss_wholesale_cost4769_t = tbl_SerializeFromObject_TD_22217702_input.getInt64(i, 9);
            tbl_Filter_TD_21248971_output.setInt64(r, 9, _ss_wholesale_cost4769_t);
            int64_t _ss_list_price4770_t = tbl_SerializeFromObject_TD_22217702_input.getInt64(i, 10);
            tbl_Filter_TD_21248971_output.setInt64(r, 10, _ss_list_price4770_t);
            int64_t _ss_coupon_amt4777_t = tbl_SerializeFromObject_TD_22217702_input.getInt64(i, 11);
            tbl_Filter_TD_21248971_output.setInt64(r, 11, _ss_coupon_amt4777_t);
            r++;
        }
    }
    tbl_Filter_TD_21248971_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_21248971_output #Row: " << tbl_Filter_TD_21248971_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_2133729_consolidate(Table &tbl_Aggregate_TD_2133729_output_preprocess, Table &tbl_Aggregate_TD_2133729_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_2133729_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _cs_item_sk1119 = tbl_Aggregate_TD_2133729_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_2133729_output.setInt32(r, 0, _cs_item_sk1119);
        int64_t _sale3549 = tbl_Aggregate_TD_2133729_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_2133729_output.setInt64(r, 1, _sale3549);
        int64_t _refund3550 = tbl_Aggregate_TD_2133729_output_preprocess.combineInt64(r, 9, 1);
        tbl_Aggregate_TD_2133729_output.setInt64(r, 2, _refund3550);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_2133729_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_2133729_output #Row: " << tbl_Aggregate_TD_2133729_output.getNumRow() << std::endl;
}

void SW_Filter_TD_21797575(Table &tbl_SerializeFromObject_TD_22773205_input, Table &tbl_Filter_TD_21797575_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(sr_item_sk#671) AND isnotnull(sr_ticket_number#678L)))
    // Input: ListBuffer(sr_item_sk#671, sr_ticket_number#678L)
    // Output: ListBuffer(sr_item_sk#671, sr_ticket_number#678L)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_22773205_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _sr_item_sk671 = tbl_SerializeFromObject_TD_22773205_input.getInt32(i, 0);
        int64_t _sr_ticket_number678L = tbl_SerializeFromObject_TD_22773205_input.getInt64(i, 1);
        if ((_sr_item_sk671!= 0) && (_sr_ticket_number678L!= 0)) {
            int32_t _sr_item_sk671_t = tbl_SerializeFromObject_TD_22773205_input.getInt32(i, 0);
            tbl_Filter_TD_21797575_output.setInt32(r, 0, _sr_item_sk671_t);
            int64_t _sr_ticket_number678L_t = tbl_SerializeFromObject_TD_22773205_input.getInt64(i, 1);
            tbl_Filter_TD_21797575_output.setInt64(r, 1, _sr_ticket_number678L_t);
            r++;
        }
    }
    tbl_Filter_TD_21797575_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_21797575_output #Row: " << tbl_Filter_TD_21797575_output.getNumRow() << std::endl;
}

void SW_Filter_TD_21713546(Table &tbl_SerializeFromObject_TD_22959783_input, Table &tbl_Filter_TD_21713546_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((((isnotnull(ss_item_sk#1208) AND isnotnull(ss_ticket_number#1215L)) AND isnotnull(ss_sold_date_sk#1206)) AND (isnotnull(ss_store_sk#1213) AND isnotnull(ss_customer_sk#1209))) AND isnotnull(ss_cdemo_sk#1210)) AND ((isnotnull(ss_promo_sk#1214) AND isnotnull(ss_hdemo_sk#1211)) AND isnotnull(ss_addr_sk#1212))))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_store_sk#1213, ss_promo_sk#1214, ss_ticket_number#1215L, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_store_sk#1213, ss_promo_sk#1214, ss_ticket_number#1215L, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_22959783_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_22959783_input.getInt32(i, 1);
        int64_t _ss_ticket_number1215L = tbl_SerializeFromObject_TD_22959783_input.getInt64(i, 8);
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_22959783_input.getInt32(i, 0);
        int32_t _ss_store_sk1213 = tbl_SerializeFromObject_TD_22959783_input.getInt32(i, 6);
        int32_t _ss_customer_sk1209 = tbl_SerializeFromObject_TD_22959783_input.getInt32(i, 2);
        int32_t _ss_cdemo_sk1210 = tbl_SerializeFromObject_TD_22959783_input.getInt32(i, 3);
        int32_t _ss_promo_sk1214 = tbl_SerializeFromObject_TD_22959783_input.getInt32(i, 7);
        int32_t _ss_hdemo_sk1211 = tbl_SerializeFromObject_TD_22959783_input.getInt32(i, 4);
        int32_t _ss_addr_sk1212 = tbl_SerializeFromObject_TD_22959783_input.getInt32(i, 5);
        if ((((((_ss_item_sk1208!= 0) && (_ss_ticket_number1215L!= 0)) && (_ss_sold_date_sk1206!= 0)) && ((_ss_store_sk1213!= 0) && (_ss_customer_sk1209!= 0))) && (_ss_cdemo_sk1210!= 0)) && (((_ss_promo_sk1214!= 0) && (_ss_hdemo_sk1211!= 0)) && (_ss_addr_sk1212!= 0))) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_22959783_input.getInt32(i, 0);
            tbl_Filter_TD_21713546_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_22959783_input.getInt32(i, 1);
            tbl_Filter_TD_21713546_output.setInt32(r, 1, _ss_item_sk1208_t);
            int32_t _ss_customer_sk1209_t = tbl_SerializeFromObject_TD_22959783_input.getInt32(i, 2);
            tbl_Filter_TD_21713546_output.setInt32(r, 2, _ss_customer_sk1209_t);
            int32_t _ss_cdemo_sk1210_t = tbl_SerializeFromObject_TD_22959783_input.getInt32(i, 3);
            tbl_Filter_TD_21713546_output.setInt32(r, 3, _ss_cdemo_sk1210_t);
            int32_t _ss_hdemo_sk1211_t = tbl_SerializeFromObject_TD_22959783_input.getInt32(i, 4);
            tbl_Filter_TD_21713546_output.setInt32(r, 4, _ss_hdemo_sk1211_t);
            int32_t _ss_addr_sk1212_t = tbl_SerializeFromObject_TD_22959783_input.getInt32(i, 5);
            tbl_Filter_TD_21713546_output.setInt32(r, 5, _ss_addr_sk1212_t);
            int32_t _ss_store_sk1213_t = tbl_SerializeFromObject_TD_22959783_input.getInt32(i, 6);
            tbl_Filter_TD_21713546_output.setInt32(r, 6, _ss_store_sk1213_t);
            int32_t _ss_promo_sk1214_t = tbl_SerializeFromObject_TD_22959783_input.getInt32(i, 7);
            tbl_Filter_TD_21713546_output.setInt32(r, 7, _ss_promo_sk1214_t);
            int64_t _ss_ticket_number1215L_t = tbl_SerializeFromObject_TD_22959783_input.getInt64(i, 8);
            tbl_Filter_TD_21713546_output.setInt64(r, 8, _ss_ticket_number1215L_t);
            int64_t _ss_wholesale_cost1217_t = tbl_SerializeFromObject_TD_22959783_input.getInt64(i, 9);
            tbl_Filter_TD_21713546_output.setInt64(r, 9, _ss_wholesale_cost1217_t);
            int64_t _ss_list_price1218_t = tbl_SerializeFromObject_TD_22959783_input.getInt64(i, 10);
            tbl_Filter_TD_21713546_output.setInt64(r, 10, _ss_list_price1218_t);
            int64_t _ss_coupon_amt1225_t = tbl_SerializeFromObject_TD_22959783_input.getInt64(i, 11);
            tbl_Filter_TD_21713546_output.setInt64(r, 11, _ss_coupon_amt1225_t);
            r++;
        }
    }
    tbl_Filter_TD_21713546_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_21713546_output #Row: " << tbl_Filter_TD_21713546_output.getNumRow() << std::endl;
}

void SW_Filter_TD_20489126(Table &tbl_Aggregate_TD_21170493_output, Table &tbl_Filter_TD_20489126_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(sale#3549) AND (cast(sale#3549 as decimal(21,2)) > CheckOverflow((2.00 * promote_precision(refund#3550)), DecimalType(21,2), true))))
    // Input: ListBuffer(cs_item_sk#4816, sale#3549, refund#3550)
    // Output: ListBuffer(cs_item_sk#4816)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_21170493_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sale3549 = tbl_Aggregate_TD_21170493_output.getInt64(i, 1);
        int64_t _refund3550 = tbl_Aggregate_TD_21170493_output.getInt64(i, 2);
        if ((_sale3549!= 0) && (_sale3549 > (2.00 * _refund3550))) {
            int32_t _cs_item_sk4816_t = tbl_Aggregate_TD_21170493_output.getInt32(i, 0);
            tbl_Filter_TD_20489126_output.setInt32(r, 0, _cs_item_sk4816_t);
            r++;
        }
    }
    tbl_Filter_TD_20489126_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_20489126_output #Row: " << tbl_Filter_TD_20489126_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_20362010_key_leftMajor {
    int32_t _ss_item_sk4760;
    int64_t _ss_ticket_number4767L;
    bool operator==(const SW_JOIN_INNER_TD_20362010_key_leftMajor& other) const {
        return ((_ss_item_sk4760 == other._ss_item_sk4760) && (_ss_ticket_number4767L == other._ss_ticket_number4767L));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_20362010_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_20362010_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk4760)) + (hash<int64_t>()(k._ss_ticket_number4767L));
    }
};
}
struct SW_JOIN_INNER_TD_20362010_payload_leftMajor {
    int32_t _ss_sold_date_sk4758;
    int32_t _ss_item_sk4760;
    int32_t _ss_customer_sk4761;
    int32_t _ss_cdemo_sk4762;
    int32_t _ss_hdemo_sk4763;
    int32_t _ss_addr_sk4764;
    int32_t _ss_store_sk4765;
    int32_t _ss_promo_sk4766;
    int64_t _ss_ticket_number4767L;
    int64_t _ss_wholesale_cost4769;
    int64_t _ss_list_price4770;
    int64_t _ss_coupon_amt4777;
};
struct SW_JOIN_INNER_TD_20362010_key_rightMajor {
    int32_t _sr_item_sk4783;
    int64_t _sr_ticket_number4790L;
    bool operator==(const SW_JOIN_INNER_TD_20362010_key_rightMajor& other) const {
        return ((_sr_item_sk4783 == other._sr_item_sk4783) && (_sr_ticket_number4790L == other._sr_ticket_number4790L));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_20362010_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_20362010_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._sr_item_sk4783)) + (hash<int64_t>()(k._sr_ticket_number4790L));
    }
};
}
struct SW_JOIN_INNER_TD_20362010_payload_rightMajor {
    int32_t _sr_item_sk4783;
    int64_t _sr_ticket_number4790L;
};
void SW_JOIN_INNER_TD_20362010(Table &tbl_Filter_TD_21248971_output, Table &tbl_Filter_TD_21831586_output, Table &tbl_JOIN_INNER_TD_20362010_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((ss_item_sk#4760 = sr_item_sk#4783) AND (ss_ticket_number#4767L = sr_ticket_number#4790L)))
    // Left Table: ListBuffer(ss_sold_date_sk#4758, ss_item_sk#4760, ss_customer_sk#4761, ss_cdemo_sk#4762, ss_hdemo_sk#4763, ss_addr_sk#4764, ss_store_sk#4765, ss_promo_sk#4766, ss_ticket_number#4767L, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777)
    // Right Table: ListBuffer(sr_item_sk#4783, sr_ticket_number#4790L)
    // Output Table: ListBuffer(ss_sold_date_sk#4758, ss_item_sk#4760, ss_customer_sk#4761, ss_cdemo_sk#4762, ss_hdemo_sk#4763, ss_addr_sk#4764, ss_store_sk#4765, ss_promo_sk#4766, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777)
    int left_nrow = tbl_Filter_TD_21248971_output.getNumRow();
    int right_nrow = tbl_Filter_TD_21831586_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_20362010_key_leftMajor, SW_JOIN_INNER_TD_20362010_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_21248971_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk4760_k = tbl_Filter_TD_21248971_output.getInt32(i, 1);
            int64_t _ss_ticket_number4767L_k = tbl_Filter_TD_21248971_output.getInt64(i, 8);
            SW_JOIN_INNER_TD_20362010_key_leftMajor keyA{_ss_item_sk4760_k, _ss_ticket_number4767L_k};
            int32_t _ss_sold_date_sk4758 = tbl_Filter_TD_21248971_output.getInt32(i, 0);
            int32_t _ss_item_sk4760 = tbl_Filter_TD_21248971_output.getInt32(i, 1);
            int32_t _ss_customer_sk4761 = tbl_Filter_TD_21248971_output.getInt32(i, 2);
            int32_t _ss_cdemo_sk4762 = tbl_Filter_TD_21248971_output.getInt32(i, 3);
            int32_t _ss_hdemo_sk4763 = tbl_Filter_TD_21248971_output.getInt32(i, 4);
            int32_t _ss_addr_sk4764 = tbl_Filter_TD_21248971_output.getInt32(i, 5);
            int32_t _ss_store_sk4765 = tbl_Filter_TD_21248971_output.getInt32(i, 6);
            int32_t _ss_promo_sk4766 = tbl_Filter_TD_21248971_output.getInt32(i, 7);
            int64_t _ss_ticket_number4767L = tbl_Filter_TD_21248971_output.getInt64(i, 8);
            int64_t _ss_wholesale_cost4769 = tbl_Filter_TD_21248971_output.getInt64(i, 9);
            int64_t _ss_list_price4770 = tbl_Filter_TD_21248971_output.getInt64(i, 10);
            int64_t _ss_coupon_amt4777 = tbl_Filter_TD_21248971_output.getInt64(i, 11);
            SW_JOIN_INNER_TD_20362010_payload_leftMajor payloadA{_ss_sold_date_sk4758, _ss_item_sk4760, _ss_customer_sk4761, _ss_cdemo_sk4762, _ss_hdemo_sk4763, _ss_addr_sk4764, _ss_store_sk4765, _ss_promo_sk4766, _ss_ticket_number4767L, _ss_wholesale_cost4769, _ss_list_price4770, _ss_coupon_amt4777};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_21831586_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _sr_item_sk4783_k = tbl_Filter_TD_21831586_output.getInt32(i, 0);
            int64_t _sr_ticket_number4790L_k = tbl_Filter_TD_21831586_output.getInt64(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_20362010_key_leftMajor{_sr_item_sk4783_k, _sr_ticket_number4790L_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk4758 = (it->second)._ss_sold_date_sk4758;
                int32_t _ss_item_sk4760 = (it->second)._ss_item_sk4760;
                int32_t _ss_customer_sk4761 = (it->second)._ss_customer_sk4761;
                int32_t _ss_cdemo_sk4762 = (it->second)._ss_cdemo_sk4762;
                int32_t _ss_hdemo_sk4763 = (it->second)._ss_hdemo_sk4763;
                int32_t _ss_addr_sk4764 = (it->second)._ss_addr_sk4764;
                int32_t _ss_store_sk4765 = (it->second)._ss_store_sk4765;
                int32_t _ss_promo_sk4766 = (it->second)._ss_promo_sk4766;
                int64_t _ss_ticket_number4767L = (it->second)._ss_ticket_number4767L;
                int64_t _ss_wholesale_cost4769 = (it->second)._ss_wholesale_cost4769;
                int64_t _ss_list_price4770 = (it->second)._ss_list_price4770;
                int64_t _ss_coupon_amt4777 = (it->second)._ss_coupon_amt4777;
                int32_t _sr_item_sk4783 = tbl_Filter_TD_21831586_output.getInt32(i, 0);
                int64_t _sr_ticket_number4790L = tbl_Filter_TD_21831586_output.getInt64(i, 1);
                tbl_JOIN_INNER_TD_20362010_output.setInt32(r, 0, _ss_sold_date_sk4758);
                tbl_JOIN_INNER_TD_20362010_output.setInt32(r, 1, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_20362010_output.setInt32(r, 2, _ss_customer_sk4761);
                tbl_JOIN_INNER_TD_20362010_output.setInt32(r, 3, _ss_cdemo_sk4762);
                tbl_JOIN_INNER_TD_20362010_output.setInt32(r, 4, _ss_hdemo_sk4763);
                tbl_JOIN_INNER_TD_20362010_output.setInt32(r, 5, _ss_addr_sk4764);
                tbl_JOIN_INNER_TD_20362010_output.setInt32(r, 6, _ss_store_sk4765);
                tbl_JOIN_INNER_TD_20362010_output.setInt32(r, 7, _ss_promo_sk4766);
                tbl_JOIN_INNER_TD_20362010_output.setInt64(r, 8, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_20362010_output.setInt64(r, 9, _ss_list_price4770);
                tbl_JOIN_INNER_TD_20362010_output.setInt64(r, 10, _ss_coupon_amt4777);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_20362010_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_20362010_key_rightMajor, SW_JOIN_INNER_TD_20362010_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_21831586_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _sr_item_sk4783_k = tbl_Filter_TD_21831586_output.getInt32(i, 0);
            int64_t _sr_ticket_number4790L_k = tbl_Filter_TD_21831586_output.getInt64(i, 1);
            SW_JOIN_INNER_TD_20362010_key_rightMajor keyA{_sr_item_sk4783_k, _sr_ticket_number4790L_k};
            int32_t _sr_item_sk4783 = tbl_Filter_TD_21831586_output.getInt32(i, 0);
            int64_t _sr_ticket_number4790L = tbl_Filter_TD_21831586_output.getInt64(i, 1);
            SW_JOIN_INNER_TD_20362010_payload_rightMajor payloadA{_sr_item_sk4783, _sr_ticket_number4790L};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_21248971_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk4760_k = tbl_Filter_TD_21248971_output.getInt32(i, 1);
            int64_t _ss_ticket_number4767L_k = tbl_Filter_TD_21248971_output.getInt64(i, 8);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_20362010_key_rightMajor{_ss_item_sk4760_k, _ss_ticket_number4767L_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _sr_item_sk4783 = (it->second)._sr_item_sk4783;
                int64_t _sr_ticket_number4790L = (it->second)._sr_ticket_number4790L;
                int32_t _ss_sold_date_sk4758 = tbl_Filter_TD_21248971_output.getInt32(i, 0);
                int32_t _ss_item_sk4760 = tbl_Filter_TD_21248971_output.getInt32(i, 1);
                int32_t _ss_customer_sk4761 = tbl_Filter_TD_21248971_output.getInt32(i, 2);
                int32_t _ss_cdemo_sk4762 = tbl_Filter_TD_21248971_output.getInt32(i, 3);
                int32_t _ss_hdemo_sk4763 = tbl_Filter_TD_21248971_output.getInt32(i, 4);
                int32_t _ss_addr_sk4764 = tbl_Filter_TD_21248971_output.getInt32(i, 5);
                int32_t _ss_store_sk4765 = tbl_Filter_TD_21248971_output.getInt32(i, 6);
                int32_t _ss_promo_sk4766 = tbl_Filter_TD_21248971_output.getInt32(i, 7);
                int64_t _ss_ticket_number4767L = tbl_Filter_TD_21248971_output.getInt64(i, 8);
                int64_t _ss_wholesale_cost4769 = tbl_Filter_TD_21248971_output.getInt64(i, 9);
                int64_t _ss_list_price4770 = tbl_Filter_TD_21248971_output.getInt64(i, 10);
                int64_t _ss_coupon_amt4777 = tbl_Filter_TD_21248971_output.getInt64(i, 11);
                tbl_JOIN_INNER_TD_20362010_output.setInt32(r, 0, _ss_sold_date_sk4758);
                tbl_JOIN_INNER_TD_20362010_output.setInt32(r, 1, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_20362010_output.setInt32(r, 2, _ss_customer_sk4761);
                tbl_JOIN_INNER_TD_20362010_output.setInt32(r, 3, _ss_cdemo_sk4762);
                tbl_JOIN_INNER_TD_20362010_output.setInt32(r, 4, _ss_hdemo_sk4763);
                tbl_JOIN_INNER_TD_20362010_output.setInt32(r, 5, _ss_addr_sk4764);
                tbl_JOIN_INNER_TD_20362010_output.setInt32(r, 6, _ss_store_sk4765);
                tbl_JOIN_INNER_TD_20362010_output.setInt32(r, 7, _ss_promo_sk4766);
                tbl_JOIN_INNER_TD_20362010_output.setInt64(r, 8, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_20362010_output.setInt64(r, 9, _ss_list_price4770);
                tbl_JOIN_INNER_TD_20362010_output.setInt64(r, 10, _ss_coupon_amt4777);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_20362010_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_20362010_output #Row: " << tbl_JOIN_INNER_TD_20362010_output.getNumRow() << std::endl;
}

void SW_Filter_TD_20877354(Table &tbl_Aggregate_TD_2133729_output, Table &tbl_Filter_TD_20877354_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(sale#3549) AND (cast(sale#3549 as decimal(21,2)) > CheckOverflow((2.00 * promote_precision(refund#3550)), DecimalType(21,2), true))))
    // Input: ListBuffer(cs_item_sk#1119, sale#3549, refund#3550)
    // Output: ListBuffer(cs_item_sk#1119)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_2133729_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sale3549 = tbl_Aggregate_TD_2133729_output.getInt64(i, 1);
        int64_t _refund3550 = tbl_Aggregate_TD_2133729_output.getInt64(i, 2);
        if ((_sale3549!= 0) && (_sale3549 > (2.00 * _refund3550))) {
            int32_t _cs_item_sk1119_t = tbl_Aggregate_TD_2133729_output.getInt32(i, 0);
            tbl_Filter_TD_20877354_output.setInt32(r, 0, _cs_item_sk1119_t);
            r++;
        }
    }
    tbl_Filter_TD_20877354_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_20877354_output #Row: " << tbl_Filter_TD_20877354_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_2032998_key_leftMajor {
    int32_t _ss_item_sk1208;
    int64_t _ss_ticket_number1215L;
    bool operator==(const SW_JOIN_INNER_TD_2032998_key_leftMajor& other) const {
        return ((_ss_item_sk1208 == other._ss_item_sk1208) && (_ss_ticket_number1215L == other._ss_ticket_number1215L));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_2032998_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_2032998_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk1208)) + (hash<int64_t>()(k._ss_ticket_number1215L));
    }
};
}
struct SW_JOIN_INNER_TD_2032998_payload_leftMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_item_sk1208;
    int32_t _ss_customer_sk1209;
    int32_t _ss_cdemo_sk1210;
    int32_t _ss_hdemo_sk1211;
    int32_t _ss_addr_sk1212;
    int32_t _ss_store_sk1213;
    int32_t _ss_promo_sk1214;
    int64_t _ss_ticket_number1215L;
    int64_t _ss_wholesale_cost1217;
    int64_t _ss_list_price1218;
    int64_t _ss_coupon_amt1225;
};
struct SW_JOIN_INNER_TD_2032998_key_rightMajor {
    int32_t _sr_item_sk671;
    int64_t _sr_ticket_number678L;
    bool operator==(const SW_JOIN_INNER_TD_2032998_key_rightMajor& other) const {
        return ((_sr_item_sk671 == other._sr_item_sk671) && (_sr_ticket_number678L == other._sr_ticket_number678L));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_2032998_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_2032998_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._sr_item_sk671)) + (hash<int64_t>()(k._sr_ticket_number678L));
    }
};
}
struct SW_JOIN_INNER_TD_2032998_payload_rightMajor {
    int32_t _sr_item_sk671;
    int64_t _sr_ticket_number678L;
};
void SW_JOIN_INNER_TD_2032998(Table &tbl_Filter_TD_21713546_output, Table &tbl_Filter_TD_21797575_output, Table &tbl_JOIN_INNER_TD_2032998_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((ss_item_sk#1208 = sr_item_sk#671) AND (ss_ticket_number#1215L = sr_ticket_number#678L)))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_store_sk#1213, ss_promo_sk#1214, ss_ticket_number#1215L, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225)
    // Right Table: ListBuffer(sr_item_sk#671, sr_ticket_number#678L)
    // Output Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_store_sk#1213, ss_promo_sk#1214, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225)
    int left_nrow = tbl_Filter_TD_21713546_output.getNumRow();
    int right_nrow = tbl_Filter_TD_21797575_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_2032998_key_leftMajor, SW_JOIN_INNER_TD_2032998_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_21713546_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk1208_k = tbl_Filter_TD_21713546_output.getInt32(i, 1);
            int64_t _ss_ticket_number1215L_k = tbl_Filter_TD_21713546_output.getInt64(i, 8);
            SW_JOIN_INNER_TD_2032998_key_leftMajor keyA{_ss_item_sk1208_k, _ss_ticket_number1215L_k};
            int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_21713546_output.getInt32(i, 0);
            int32_t _ss_item_sk1208 = tbl_Filter_TD_21713546_output.getInt32(i, 1);
            int32_t _ss_customer_sk1209 = tbl_Filter_TD_21713546_output.getInt32(i, 2);
            int32_t _ss_cdemo_sk1210 = tbl_Filter_TD_21713546_output.getInt32(i, 3);
            int32_t _ss_hdemo_sk1211 = tbl_Filter_TD_21713546_output.getInt32(i, 4);
            int32_t _ss_addr_sk1212 = tbl_Filter_TD_21713546_output.getInt32(i, 5);
            int32_t _ss_store_sk1213 = tbl_Filter_TD_21713546_output.getInt32(i, 6);
            int32_t _ss_promo_sk1214 = tbl_Filter_TD_21713546_output.getInt32(i, 7);
            int64_t _ss_ticket_number1215L = tbl_Filter_TD_21713546_output.getInt64(i, 8);
            int64_t _ss_wholesale_cost1217 = tbl_Filter_TD_21713546_output.getInt64(i, 9);
            int64_t _ss_list_price1218 = tbl_Filter_TD_21713546_output.getInt64(i, 10);
            int64_t _ss_coupon_amt1225 = tbl_Filter_TD_21713546_output.getInt64(i, 11);
            SW_JOIN_INNER_TD_2032998_payload_leftMajor payloadA{_ss_sold_date_sk1206, _ss_item_sk1208, _ss_customer_sk1209, _ss_cdemo_sk1210, _ss_hdemo_sk1211, _ss_addr_sk1212, _ss_store_sk1213, _ss_promo_sk1214, _ss_ticket_number1215L, _ss_wholesale_cost1217, _ss_list_price1218, _ss_coupon_amt1225};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_21797575_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _sr_item_sk671_k = tbl_Filter_TD_21797575_output.getInt32(i, 0);
            int64_t _sr_ticket_number678L_k = tbl_Filter_TD_21797575_output.getInt64(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_2032998_key_leftMajor{_sr_item_sk671_k, _sr_ticket_number678L_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                int32_t _ss_cdemo_sk1210 = (it->second)._ss_cdemo_sk1210;
                int32_t _ss_hdemo_sk1211 = (it->second)._ss_hdemo_sk1211;
                int32_t _ss_addr_sk1212 = (it->second)._ss_addr_sk1212;
                int32_t _ss_store_sk1213 = (it->second)._ss_store_sk1213;
                int32_t _ss_promo_sk1214 = (it->second)._ss_promo_sk1214;
                int64_t _ss_ticket_number1215L = (it->second)._ss_ticket_number1215L;
                int64_t _ss_wholesale_cost1217 = (it->second)._ss_wholesale_cost1217;
                int64_t _ss_list_price1218 = (it->second)._ss_list_price1218;
                int64_t _ss_coupon_amt1225 = (it->second)._ss_coupon_amt1225;
                int32_t _sr_item_sk671 = tbl_Filter_TD_21797575_output.getInt32(i, 0);
                int64_t _sr_ticket_number678L = tbl_Filter_TD_21797575_output.getInt64(i, 1);
                tbl_JOIN_INNER_TD_2032998_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_2032998_output.setInt32(r, 1, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_2032998_output.setInt32(r, 2, _ss_customer_sk1209);
                tbl_JOIN_INNER_TD_2032998_output.setInt32(r, 3, _ss_cdemo_sk1210);
                tbl_JOIN_INNER_TD_2032998_output.setInt32(r, 4, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_2032998_output.setInt32(r, 5, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_2032998_output.setInt32(r, 6, _ss_store_sk1213);
                tbl_JOIN_INNER_TD_2032998_output.setInt32(r, 7, _ss_promo_sk1214);
                tbl_JOIN_INNER_TD_2032998_output.setInt64(r, 8, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_2032998_output.setInt64(r, 9, _ss_list_price1218);
                tbl_JOIN_INNER_TD_2032998_output.setInt64(r, 10, _ss_coupon_amt1225);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_2032998_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_2032998_key_rightMajor, SW_JOIN_INNER_TD_2032998_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_21797575_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _sr_item_sk671_k = tbl_Filter_TD_21797575_output.getInt32(i, 0);
            int64_t _sr_ticket_number678L_k = tbl_Filter_TD_21797575_output.getInt64(i, 1);
            SW_JOIN_INNER_TD_2032998_key_rightMajor keyA{_sr_item_sk671_k, _sr_ticket_number678L_k};
            int32_t _sr_item_sk671 = tbl_Filter_TD_21797575_output.getInt32(i, 0);
            int64_t _sr_ticket_number678L = tbl_Filter_TD_21797575_output.getInt64(i, 1);
            SW_JOIN_INNER_TD_2032998_payload_rightMajor payloadA{_sr_item_sk671, _sr_ticket_number678L};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_21713546_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk1208_k = tbl_Filter_TD_21713546_output.getInt32(i, 1);
            int64_t _ss_ticket_number1215L_k = tbl_Filter_TD_21713546_output.getInt64(i, 8);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_2032998_key_rightMajor{_ss_item_sk1208_k, _ss_ticket_number1215L_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _sr_item_sk671 = (it->second)._sr_item_sk671;
                int64_t _sr_ticket_number678L = (it->second)._sr_ticket_number678L;
                int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_21713546_output.getInt32(i, 0);
                int32_t _ss_item_sk1208 = tbl_Filter_TD_21713546_output.getInt32(i, 1);
                int32_t _ss_customer_sk1209 = tbl_Filter_TD_21713546_output.getInt32(i, 2);
                int32_t _ss_cdemo_sk1210 = tbl_Filter_TD_21713546_output.getInt32(i, 3);
                int32_t _ss_hdemo_sk1211 = tbl_Filter_TD_21713546_output.getInt32(i, 4);
                int32_t _ss_addr_sk1212 = tbl_Filter_TD_21713546_output.getInt32(i, 5);
                int32_t _ss_store_sk1213 = tbl_Filter_TD_21713546_output.getInt32(i, 6);
                int32_t _ss_promo_sk1214 = tbl_Filter_TD_21713546_output.getInt32(i, 7);
                int64_t _ss_ticket_number1215L = tbl_Filter_TD_21713546_output.getInt64(i, 8);
                int64_t _ss_wholesale_cost1217 = tbl_Filter_TD_21713546_output.getInt64(i, 9);
                int64_t _ss_list_price1218 = tbl_Filter_TD_21713546_output.getInt64(i, 10);
                int64_t _ss_coupon_amt1225 = tbl_Filter_TD_21713546_output.getInt64(i, 11);
                tbl_JOIN_INNER_TD_2032998_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_2032998_output.setInt32(r, 1, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_2032998_output.setInt32(r, 2, _ss_customer_sk1209);
                tbl_JOIN_INNER_TD_2032998_output.setInt32(r, 3, _ss_cdemo_sk1210);
                tbl_JOIN_INNER_TD_2032998_output.setInt32(r, 4, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_2032998_output.setInt32(r, 5, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_2032998_output.setInt32(r, 6, _ss_store_sk1213);
                tbl_JOIN_INNER_TD_2032998_output.setInt32(r, 7, _ss_promo_sk1214);
                tbl_JOIN_INNER_TD_2032998_output.setInt64(r, 8, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_2032998_output.setInt64(r, 9, _ss_list_price1218);
                tbl_JOIN_INNER_TD_2032998_output.setInt64(r, 10, _ss_coupon_amt1225);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_2032998_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_2032998_output #Row: " << tbl_JOIN_INNER_TD_2032998_output.getNumRow() << std::endl;
}

void SW_Filter_TD_19132336(Table &tbl_SerializeFromObject_TD_2011150_input, Table &tbl_Filter_TD_19132336_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#4868) AND (d_year#4868 = 2000)) AND isnotnull(d_date_sk#4862)))
    // Input: ListBuffer(d_date_sk#4862, d_year#4868)
    // Output: ListBuffer(d_date_sk#4862, d_year#4868)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_2011150_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year4868 = tbl_SerializeFromObject_TD_2011150_input.getInt32(i, 1);
        int32_t _d_date_sk4862 = tbl_SerializeFromObject_TD_2011150_input.getInt32(i, 0);
        if (((_d_year4868!= 0) && (_d_year4868 == 2000)) && (_d_date_sk4862!= 0)) {
            int32_t _d_date_sk4862_t = tbl_SerializeFromObject_TD_2011150_input.getInt32(i, 0);
            tbl_Filter_TD_19132336_output.setInt32(r, 0, _d_date_sk4862_t);
            int32_t _d_year4868_t = tbl_SerializeFromObject_TD_2011150_input.getInt32(i, 1);
            tbl_Filter_TD_19132336_output.setInt32(r, 1, _d_year4868_t);
            r++;
        }
    }
    tbl_Filter_TD_19132336_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_19132336_output #Row: " << tbl_Filter_TD_19132336_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_19390320_key_leftMajor {
    int32_t _ss_item_sk4760;
    bool operator==(const SW_JOIN_INNER_TD_19390320_key_leftMajor& other) const {
        return ((_ss_item_sk4760 == other._ss_item_sk4760));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_19390320_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_19390320_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk4760));
    }
};
}
struct SW_JOIN_INNER_TD_19390320_payload_leftMajor {
    int32_t _ss_sold_date_sk4758;
    int32_t _ss_item_sk4760;
    int32_t _ss_customer_sk4761;
    int32_t _ss_cdemo_sk4762;
    int32_t _ss_hdemo_sk4763;
    int32_t _ss_addr_sk4764;
    int32_t _ss_store_sk4765;
    int32_t _ss_promo_sk4766;
    int64_t _ss_wholesale_cost4769;
    int64_t _ss_list_price4770;
    int64_t _ss_coupon_amt4777;
};
struct SW_JOIN_INNER_TD_19390320_key_rightMajor {
    int32_t _cs_item_sk4816;
    bool operator==(const SW_JOIN_INNER_TD_19390320_key_rightMajor& other) const {
        return ((_cs_item_sk4816 == other._cs_item_sk4816));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_19390320_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_19390320_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_item_sk4816));
    }
};
}
struct SW_JOIN_INNER_TD_19390320_payload_rightMajor {
    int32_t _cs_item_sk4816;
};
void SW_JOIN_INNER_TD_19390320(Table &tbl_JOIN_INNER_TD_20362010_output, Table &tbl_Filter_TD_20489126_output, Table &tbl_JOIN_INNER_TD_19390320_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_item_sk#4760 = cs_item_sk#4816))
    // Left Table: ListBuffer(ss_sold_date_sk#4758, ss_item_sk#4760, ss_customer_sk#4761, ss_cdemo_sk#4762, ss_hdemo_sk#4763, ss_addr_sk#4764, ss_store_sk#4765, ss_promo_sk#4766, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777)
    // Right Table: ListBuffer(cs_item_sk#4816)
    // Output Table: ListBuffer(ss_sold_date_sk#4758, ss_item_sk#4760, ss_customer_sk#4761, ss_cdemo_sk#4762, ss_hdemo_sk#4763, ss_addr_sk#4764, ss_store_sk#4765, ss_promo_sk#4766, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777)
    int left_nrow = tbl_JOIN_INNER_TD_20362010_output.getNumRow();
    int right_nrow = tbl_Filter_TD_20489126_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_19390320_key_leftMajor, SW_JOIN_INNER_TD_19390320_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_20362010_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk4760_k = tbl_JOIN_INNER_TD_20362010_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_19390320_key_leftMajor keyA{_ss_item_sk4760_k};
            int32_t _ss_sold_date_sk4758 = tbl_JOIN_INNER_TD_20362010_output.getInt32(i, 0);
            int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_20362010_output.getInt32(i, 1);
            int32_t _ss_customer_sk4761 = tbl_JOIN_INNER_TD_20362010_output.getInt32(i, 2);
            int32_t _ss_cdemo_sk4762 = tbl_JOIN_INNER_TD_20362010_output.getInt32(i, 3);
            int32_t _ss_hdemo_sk4763 = tbl_JOIN_INNER_TD_20362010_output.getInt32(i, 4);
            int32_t _ss_addr_sk4764 = tbl_JOIN_INNER_TD_20362010_output.getInt32(i, 5);
            int32_t _ss_store_sk4765 = tbl_JOIN_INNER_TD_20362010_output.getInt32(i, 6);
            int32_t _ss_promo_sk4766 = tbl_JOIN_INNER_TD_20362010_output.getInt32(i, 7);
            int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_20362010_output.getInt64(i, 8);
            int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_20362010_output.getInt64(i, 9);
            int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_20362010_output.getInt64(i, 10);
            SW_JOIN_INNER_TD_19390320_payload_leftMajor payloadA{_ss_sold_date_sk4758, _ss_item_sk4760, _ss_customer_sk4761, _ss_cdemo_sk4762, _ss_hdemo_sk4763, _ss_addr_sk4764, _ss_store_sk4765, _ss_promo_sk4766, _ss_wholesale_cost4769, _ss_list_price4770, _ss_coupon_amt4777};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_20489126_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_item_sk4816_k = tbl_Filter_TD_20489126_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_19390320_key_leftMajor{_cs_item_sk4816_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk4758 = (it->second)._ss_sold_date_sk4758;
                int32_t _ss_item_sk4760 = (it->second)._ss_item_sk4760;
                int32_t _ss_customer_sk4761 = (it->second)._ss_customer_sk4761;
                int32_t _ss_cdemo_sk4762 = (it->second)._ss_cdemo_sk4762;
                int32_t _ss_hdemo_sk4763 = (it->second)._ss_hdemo_sk4763;
                int32_t _ss_addr_sk4764 = (it->second)._ss_addr_sk4764;
                int32_t _ss_store_sk4765 = (it->second)._ss_store_sk4765;
                int32_t _ss_promo_sk4766 = (it->second)._ss_promo_sk4766;
                int64_t _ss_wholesale_cost4769 = (it->second)._ss_wholesale_cost4769;
                int64_t _ss_list_price4770 = (it->second)._ss_list_price4770;
                int64_t _ss_coupon_amt4777 = (it->second)._ss_coupon_amt4777;
                int32_t _cs_item_sk4816 = tbl_Filter_TD_20489126_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_19390320_output.setInt32(r, 0, _ss_sold_date_sk4758);
                tbl_JOIN_INNER_TD_19390320_output.setInt32(r, 1, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_19390320_output.setInt32(r, 2, _ss_customer_sk4761);
                tbl_JOIN_INNER_TD_19390320_output.setInt32(r, 3, _ss_cdemo_sk4762);
                tbl_JOIN_INNER_TD_19390320_output.setInt32(r, 4, _ss_hdemo_sk4763);
                tbl_JOIN_INNER_TD_19390320_output.setInt32(r, 5, _ss_addr_sk4764);
                tbl_JOIN_INNER_TD_19390320_output.setInt32(r, 6, _ss_store_sk4765);
                tbl_JOIN_INNER_TD_19390320_output.setInt32(r, 7, _ss_promo_sk4766);
                tbl_JOIN_INNER_TD_19390320_output.setInt64(r, 8, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_19390320_output.setInt64(r, 9, _ss_list_price4770);
                tbl_JOIN_INNER_TD_19390320_output.setInt64(r, 10, _ss_coupon_amt4777);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_19390320_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_19390320_key_rightMajor, SW_JOIN_INNER_TD_19390320_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_20489126_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_item_sk4816_k = tbl_Filter_TD_20489126_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_19390320_key_rightMajor keyA{_cs_item_sk4816_k};
            int32_t _cs_item_sk4816 = tbl_Filter_TD_20489126_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_19390320_payload_rightMajor payloadA{_cs_item_sk4816};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_20362010_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk4760_k = tbl_JOIN_INNER_TD_20362010_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_19390320_key_rightMajor{_ss_item_sk4760_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_item_sk4816 = (it->second)._cs_item_sk4816;
                int32_t _ss_sold_date_sk4758 = tbl_JOIN_INNER_TD_20362010_output.getInt32(i, 0);
                int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_20362010_output.getInt32(i, 1);
                int32_t _ss_customer_sk4761 = tbl_JOIN_INNER_TD_20362010_output.getInt32(i, 2);
                int32_t _ss_cdemo_sk4762 = tbl_JOIN_INNER_TD_20362010_output.getInt32(i, 3);
                int32_t _ss_hdemo_sk4763 = tbl_JOIN_INNER_TD_20362010_output.getInt32(i, 4);
                int32_t _ss_addr_sk4764 = tbl_JOIN_INNER_TD_20362010_output.getInt32(i, 5);
                int32_t _ss_store_sk4765 = tbl_JOIN_INNER_TD_20362010_output.getInt32(i, 6);
                int32_t _ss_promo_sk4766 = tbl_JOIN_INNER_TD_20362010_output.getInt32(i, 7);
                int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_20362010_output.getInt64(i, 8);
                int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_20362010_output.getInt64(i, 9);
                int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_20362010_output.getInt64(i, 10);
                tbl_JOIN_INNER_TD_19390320_output.setInt32(r, 0, _ss_sold_date_sk4758);
                tbl_JOIN_INNER_TD_19390320_output.setInt32(r, 1, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_19390320_output.setInt32(r, 2, _ss_customer_sk4761);
                tbl_JOIN_INNER_TD_19390320_output.setInt32(r, 3, _ss_cdemo_sk4762);
                tbl_JOIN_INNER_TD_19390320_output.setInt32(r, 4, _ss_hdemo_sk4763);
                tbl_JOIN_INNER_TD_19390320_output.setInt32(r, 5, _ss_addr_sk4764);
                tbl_JOIN_INNER_TD_19390320_output.setInt32(r, 6, _ss_store_sk4765);
                tbl_JOIN_INNER_TD_19390320_output.setInt32(r, 7, _ss_promo_sk4766);
                tbl_JOIN_INNER_TD_19390320_output.setInt64(r, 8, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_19390320_output.setInt64(r, 9, _ss_list_price4770);
                tbl_JOIN_INNER_TD_19390320_output.setInt64(r, 10, _ss_coupon_amt4777);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_19390320_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_19390320_output #Row: " << tbl_JOIN_INNER_TD_19390320_output.getNumRow() << std::endl;
}

void SW_Filter_TD_19514965(Table &tbl_SerializeFromObject_TD_20256349_input, Table &tbl_Filter_TD_19514965_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#126) AND (d_year#126 = 1999)) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126)
    // Output: ListBuffer(d_date_sk#120, d_year#126)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_20256349_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_20256349_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_20256349_input.getInt32(i, 0);
        if (((_d_year126!= 0) && (_d_year126 == 1999)) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_20256349_input.getInt32(i, 0);
            tbl_Filter_TD_19514965_output.setInt32(r, 0, _d_date_sk120_t);
            int32_t _d_year126_t = tbl_SerializeFromObject_TD_20256349_input.getInt32(i, 1);
            tbl_Filter_TD_19514965_output.setInt32(r, 1, _d_year126_t);
            r++;
        }
    }
    tbl_Filter_TD_19514965_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_19514965_output #Row: " << tbl_Filter_TD_19514965_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_19871408_key_leftMajor {
    int32_t _ss_item_sk1208;
    bool operator==(const SW_JOIN_INNER_TD_19871408_key_leftMajor& other) const {
        return ((_ss_item_sk1208 == other._ss_item_sk1208));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_19871408_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_19871408_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk1208));
    }
};
}
struct SW_JOIN_INNER_TD_19871408_payload_leftMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_item_sk1208;
    int32_t _ss_customer_sk1209;
    int32_t _ss_cdemo_sk1210;
    int32_t _ss_hdemo_sk1211;
    int32_t _ss_addr_sk1212;
    int32_t _ss_store_sk1213;
    int32_t _ss_promo_sk1214;
    int64_t _ss_wholesale_cost1217;
    int64_t _ss_list_price1218;
    int64_t _ss_coupon_amt1225;
};
struct SW_JOIN_INNER_TD_19871408_key_rightMajor {
    int32_t _cs_item_sk1119;
    bool operator==(const SW_JOIN_INNER_TD_19871408_key_rightMajor& other) const {
        return ((_cs_item_sk1119 == other._cs_item_sk1119));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_19871408_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_19871408_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_item_sk1119));
    }
};
}
struct SW_JOIN_INNER_TD_19871408_payload_rightMajor {
    int32_t _cs_item_sk1119;
};
void SW_JOIN_INNER_TD_19871408(Table &tbl_JOIN_INNER_TD_2032998_output, Table &tbl_Filter_TD_20877354_output, Table &tbl_JOIN_INNER_TD_19871408_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_item_sk#1208 = cs_item_sk#1119))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_store_sk#1213, ss_promo_sk#1214, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225)
    // Right Table: ListBuffer(cs_item_sk#1119)
    // Output Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_store_sk#1213, ss_promo_sk#1214, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225)
    int left_nrow = tbl_JOIN_INNER_TD_2032998_output.getNumRow();
    int right_nrow = tbl_Filter_TD_20877354_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_19871408_key_leftMajor, SW_JOIN_INNER_TD_19871408_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_2032998_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_2032998_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_19871408_key_leftMajor keyA{_ss_item_sk1208_k};
            int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_2032998_output.getInt32(i, 0);
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_2032998_output.getInt32(i, 1);
            int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_2032998_output.getInt32(i, 2);
            int32_t _ss_cdemo_sk1210 = tbl_JOIN_INNER_TD_2032998_output.getInt32(i, 3);
            int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_2032998_output.getInt32(i, 4);
            int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_2032998_output.getInt32(i, 5);
            int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_2032998_output.getInt32(i, 6);
            int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_2032998_output.getInt32(i, 7);
            int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_2032998_output.getInt64(i, 8);
            int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_2032998_output.getInt64(i, 9);
            int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_2032998_output.getInt64(i, 10);
            SW_JOIN_INNER_TD_19871408_payload_leftMajor payloadA{_ss_sold_date_sk1206, _ss_item_sk1208, _ss_customer_sk1209, _ss_cdemo_sk1210, _ss_hdemo_sk1211, _ss_addr_sk1212, _ss_store_sk1213, _ss_promo_sk1214, _ss_wholesale_cost1217, _ss_list_price1218, _ss_coupon_amt1225};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_20877354_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_item_sk1119_k = tbl_Filter_TD_20877354_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_19871408_key_leftMajor{_cs_item_sk1119_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                int32_t _ss_cdemo_sk1210 = (it->second)._ss_cdemo_sk1210;
                int32_t _ss_hdemo_sk1211 = (it->second)._ss_hdemo_sk1211;
                int32_t _ss_addr_sk1212 = (it->second)._ss_addr_sk1212;
                int32_t _ss_store_sk1213 = (it->second)._ss_store_sk1213;
                int32_t _ss_promo_sk1214 = (it->second)._ss_promo_sk1214;
                int64_t _ss_wholesale_cost1217 = (it->second)._ss_wholesale_cost1217;
                int64_t _ss_list_price1218 = (it->second)._ss_list_price1218;
                int64_t _ss_coupon_amt1225 = (it->second)._ss_coupon_amt1225;
                int32_t _cs_item_sk1119 = tbl_Filter_TD_20877354_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_19871408_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_19871408_output.setInt32(r, 1, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_19871408_output.setInt32(r, 2, _ss_customer_sk1209);
                tbl_JOIN_INNER_TD_19871408_output.setInt32(r, 3, _ss_cdemo_sk1210);
                tbl_JOIN_INNER_TD_19871408_output.setInt32(r, 4, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_19871408_output.setInt32(r, 5, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_19871408_output.setInt32(r, 6, _ss_store_sk1213);
                tbl_JOIN_INNER_TD_19871408_output.setInt32(r, 7, _ss_promo_sk1214);
                tbl_JOIN_INNER_TD_19871408_output.setInt64(r, 8, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_19871408_output.setInt64(r, 9, _ss_list_price1218);
                tbl_JOIN_INNER_TD_19871408_output.setInt64(r, 10, _ss_coupon_amt1225);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_19871408_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_19871408_key_rightMajor, SW_JOIN_INNER_TD_19871408_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_20877354_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_item_sk1119_k = tbl_Filter_TD_20877354_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_19871408_key_rightMajor keyA{_cs_item_sk1119_k};
            int32_t _cs_item_sk1119 = tbl_Filter_TD_20877354_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_19871408_payload_rightMajor payloadA{_cs_item_sk1119};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_2032998_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_2032998_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_19871408_key_rightMajor{_ss_item_sk1208_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_item_sk1119 = (it->second)._cs_item_sk1119;
                int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_2032998_output.getInt32(i, 0);
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_2032998_output.getInt32(i, 1);
                int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_2032998_output.getInt32(i, 2);
                int32_t _ss_cdemo_sk1210 = tbl_JOIN_INNER_TD_2032998_output.getInt32(i, 3);
                int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_2032998_output.getInt32(i, 4);
                int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_2032998_output.getInt32(i, 5);
                int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_2032998_output.getInt32(i, 6);
                int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_2032998_output.getInt32(i, 7);
                int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_2032998_output.getInt64(i, 8);
                int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_2032998_output.getInt64(i, 9);
                int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_2032998_output.getInt64(i, 10);
                tbl_JOIN_INNER_TD_19871408_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_19871408_output.setInt32(r, 1, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_19871408_output.setInt32(r, 2, _ss_customer_sk1209);
                tbl_JOIN_INNER_TD_19871408_output.setInt32(r, 3, _ss_cdemo_sk1210);
                tbl_JOIN_INNER_TD_19871408_output.setInt32(r, 4, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_19871408_output.setInt32(r, 5, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_19871408_output.setInt32(r, 6, _ss_store_sk1213);
                tbl_JOIN_INNER_TD_19871408_output.setInt32(r, 7, _ss_promo_sk1214);
                tbl_JOIN_INNER_TD_19871408_output.setInt64(r, 8, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_19871408_output.setInt64(r, 9, _ss_list_price1218);
                tbl_JOIN_INNER_TD_19871408_output.setInt64(r, 10, _ss_coupon_amt1225);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_19871408_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_19871408_output #Row: " << tbl_JOIN_INNER_TD_19871408_output.getNumRow() << std::endl;
}

void SW_Filter_TD_18157257(Table &tbl_SerializeFromObject_TD_19226242_input, Table &tbl_Filter_TD_18157257_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(s_store_sk#4946) AND (isnotnull(s_store_name#4951) AND isnotnull(s_zip#4971))))
    // Input: ListBuffer(s_store_sk#4946, s_store_name#4951, s_zip#4971)
    // Output: ListBuffer(s_store_sk#4946, s_store_name#4951, s_zip#4971)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_19226242_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _s_store_sk4946 = tbl_SerializeFromObject_TD_19226242_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951 = tbl_SerializeFromObject_TD_19226242_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _s_zip4971 = tbl_SerializeFromObject_TD_19226242_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        if ((_s_store_sk4946!= 0) && (_s_store_name4951.data() != "NULL" && _s_zip4971.data() != "NULL")) {
            int32_t _s_store_sk4946_t = tbl_SerializeFromObject_TD_19226242_input.getInt32(i, 0);
            tbl_Filter_TD_18157257_output.setInt32(r, 0, _s_store_sk4946_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_t = tbl_SerializeFromObject_TD_19226242_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_18157257_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_store_name4951_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_t = tbl_SerializeFromObject_TD_19226242_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_18157257_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_zip4971_t);
            r++;
        }
    }
    tbl_Filter_TD_18157257_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_18157257_output #Row: " << tbl_Filter_TD_18157257_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_18378634_key_leftMajor {
    int32_t _ss_sold_date_sk4758;
    bool operator==(const SW_JOIN_INNER_TD_18378634_key_leftMajor& other) const {
        return ((_ss_sold_date_sk4758 == other._ss_sold_date_sk4758));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_18378634_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_18378634_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_sold_date_sk4758));
    }
};
}
struct SW_JOIN_INNER_TD_18378634_payload_leftMajor {
    int32_t _ss_sold_date_sk4758;
    int32_t _ss_item_sk4760;
    int32_t _ss_customer_sk4761;
    int32_t _ss_cdemo_sk4762;
    int32_t _ss_hdemo_sk4763;
    int32_t _ss_addr_sk4764;
    int32_t _ss_store_sk4765;
    int32_t _ss_promo_sk4766;
    int64_t _ss_wholesale_cost4769;
    int64_t _ss_list_price4770;
    int64_t _ss_coupon_amt4777;
};
struct SW_JOIN_INNER_TD_18378634_key_rightMajor {
    int32_t _d_date_sk4862;
    bool operator==(const SW_JOIN_INNER_TD_18378634_key_rightMajor& other) const {
        return ((_d_date_sk4862 == other._d_date_sk4862));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_18378634_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_18378634_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk4862));
    }
};
}
struct SW_JOIN_INNER_TD_18378634_payload_rightMajor {
    int32_t _d_date_sk4862;
    int32_t _d_year4868;
};
void SW_JOIN_INNER_TD_18378634(Table &tbl_JOIN_INNER_TD_19390320_output, Table &tbl_Filter_TD_19132336_output, Table &tbl_JOIN_INNER_TD_18378634_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#4758 = d_date_sk#4862))
    // Left Table: ListBuffer(ss_sold_date_sk#4758, ss_item_sk#4760, ss_customer_sk#4761, ss_cdemo_sk#4762, ss_hdemo_sk#4763, ss_addr_sk#4764, ss_store_sk#4765, ss_promo_sk#4766, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777)
    // Right Table: ListBuffer(d_date_sk#4862, d_year#4868)
    // Output Table: ListBuffer(ss_item_sk#4760, ss_customer_sk#4761, ss_cdemo_sk#4762, ss_hdemo_sk#4763, ss_addr_sk#4764, ss_store_sk#4765, ss_promo_sk#4766, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868)
    int left_nrow = tbl_JOIN_INNER_TD_19390320_output.getNumRow();
    int right_nrow = tbl_Filter_TD_19132336_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_18378634_key_leftMajor, SW_JOIN_INNER_TD_18378634_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_19390320_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_sold_date_sk4758_k = tbl_JOIN_INNER_TD_19390320_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_18378634_key_leftMajor keyA{_ss_sold_date_sk4758_k};
            int32_t _ss_sold_date_sk4758 = tbl_JOIN_INNER_TD_19390320_output.getInt32(i, 0);
            int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_19390320_output.getInt32(i, 1);
            int32_t _ss_customer_sk4761 = tbl_JOIN_INNER_TD_19390320_output.getInt32(i, 2);
            int32_t _ss_cdemo_sk4762 = tbl_JOIN_INNER_TD_19390320_output.getInt32(i, 3);
            int32_t _ss_hdemo_sk4763 = tbl_JOIN_INNER_TD_19390320_output.getInt32(i, 4);
            int32_t _ss_addr_sk4764 = tbl_JOIN_INNER_TD_19390320_output.getInt32(i, 5);
            int32_t _ss_store_sk4765 = tbl_JOIN_INNER_TD_19390320_output.getInt32(i, 6);
            int32_t _ss_promo_sk4766 = tbl_JOIN_INNER_TD_19390320_output.getInt32(i, 7);
            int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_19390320_output.getInt64(i, 8);
            int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_19390320_output.getInt64(i, 9);
            int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_19390320_output.getInt64(i, 10);
            SW_JOIN_INNER_TD_18378634_payload_leftMajor payloadA{_ss_sold_date_sk4758, _ss_item_sk4760, _ss_customer_sk4761, _ss_cdemo_sk4762, _ss_hdemo_sk4763, _ss_addr_sk4764, _ss_store_sk4765, _ss_promo_sk4766, _ss_wholesale_cost4769, _ss_list_price4770, _ss_coupon_amt4777};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_19132336_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk4862_k = tbl_Filter_TD_19132336_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_18378634_key_leftMajor{_d_date_sk4862_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk4758 = (it->second)._ss_sold_date_sk4758;
                int32_t _ss_item_sk4760 = (it->second)._ss_item_sk4760;
                int32_t _ss_customer_sk4761 = (it->second)._ss_customer_sk4761;
                int32_t _ss_cdemo_sk4762 = (it->second)._ss_cdemo_sk4762;
                int32_t _ss_hdemo_sk4763 = (it->second)._ss_hdemo_sk4763;
                int32_t _ss_addr_sk4764 = (it->second)._ss_addr_sk4764;
                int32_t _ss_store_sk4765 = (it->second)._ss_store_sk4765;
                int32_t _ss_promo_sk4766 = (it->second)._ss_promo_sk4766;
                int64_t _ss_wholesale_cost4769 = (it->second)._ss_wholesale_cost4769;
                int64_t _ss_list_price4770 = (it->second)._ss_list_price4770;
                int64_t _ss_coupon_amt4777 = (it->second)._ss_coupon_amt4777;
                int32_t _d_date_sk4862 = tbl_Filter_TD_19132336_output.getInt32(i, 0);
                int32_t _d_year4868 = tbl_Filter_TD_19132336_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_18378634_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_18378634_output.setInt32(r, 1, _ss_customer_sk4761);
                tbl_JOIN_INNER_TD_18378634_output.setInt32(r, 2, _ss_cdemo_sk4762);
                tbl_JOIN_INNER_TD_18378634_output.setInt32(r, 3, _ss_hdemo_sk4763);
                tbl_JOIN_INNER_TD_18378634_output.setInt32(r, 4, _ss_addr_sk4764);
                tbl_JOIN_INNER_TD_18378634_output.setInt32(r, 5, _ss_store_sk4765);
                tbl_JOIN_INNER_TD_18378634_output.setInt32(r, 6, _ss_promo_sk4766);
                tbl_JOIN_INNER_TD_18378634_output.setInt64(r, 7, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_18378634_output.setInt64(r, 8, _ss_list_price4770);
                tbl_JOIN_INNER_TD_18378634_output.setInt64(r, 9, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_18378634_output.setInt32(r, 10, _d_year4868);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_18378634_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_18378634_key_rightMajor, SW_JOIN_INNER_TD_18378634_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_19132336_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk4862_k = tbl_Filter_TD_19132336_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_18378634_key_rightMajor keyA{_d_date_sk4862_k};
            int32_t _d_date_sk4862 = tbl_Filter_TD_19132336_output.getInt32(i, 0);
            int32_t _d_year4868 = tbl_Filter_TD_19132336_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_18378634_payload_rightMajor payloadA{_d_date_sk4862, _d_year4868};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_19390320_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_sold_date_sk4758_k = tbl_JOIN_INNER_TD_19390320_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_18378634_key_rightMajor{_ss_sold_date_sk4758_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk4862 = (it->second)._d_date_sk4862;
                int32_t _d_year4868 = (it->second)._d_year4868;
                int32_t _ss_sold_date_sk4758 = tbl_JOIN_INNER_TD_19390320_output.getInt32(i, 0);
                int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_19390320_output.getInt32(i, 1);
                int32_t _ss_customer_sk4761 = tbl_JOIN_INNER_TD_19390320_output.getInt32(i, 2);
                int32_t _ss_cdemo_sk4762 = tbl_JOIN_INNER_TD_19390320_output.getInt32(i, 3);
                int32_t _ss_hdemo_sk4763 = tbl_JOIN_INNER_TD_19390320_output.getInt32(i, 4);
                int32_t _ss_addr_sk4764 = tbl_JOIN_INNER_TD_19390320_output.getInt32(i, 5);
                int32_t _ss_store_sk4765 = tbl_JOIN_INNER_TD_19390320_output.getInt32(i, 6);
                int32_t _ss_promo_sk4766 = tbl_JOIN_INNER_TD_19390320_output.getInt32(i, 7);
                int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_19390320_output.getInt64(i, 8);
                int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_19390320_output.getInt64(i, 9);
                int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_19390320_output.getInt64(i, 10);
                tbl_JOIN_INNER_TD_18378634_output.setInt32(r, 10, _d_year4868);
                tbl_JOIN_INNER_TD_18378634_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_18378634_output.setInt32(r, 1, _ss_customer_sk4761);
                tbl_JOIN_INNER_TD_18378634_output.setInt32(r, 2, _ss_cdemo_sk4762);
                tbl_JOIN_INNER_TD_18378634_output.setInt32(r, 3, _ss_hdemo_sk4763);
                tbl_JOIN_INNER_TD_18378634_output.setInt32(r, 4, _ss_addr_sk4764);
                tbl_JOIN_INNER_TD_18378634_output.setInt32(r, 5, _ss_store_sk4765);
                tbl_JOIN_INNER_TD_18378634_output.setInt32(r, 6, _ss_promo_sk4766);
                tbl_JOIN_INNER_TD_18378634_output.setInt64(r, 7, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_18378634_output.setInt64(r, 8, _ss_list_price4770);
                tbl_JOIN_INNER_TD_18378634_output.setInt64(r, 9, _ss_coupon_amt4777);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_18378634_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_18378634_output #Row: " << tbl_JOIN_INNER_TD_18378634_output.getNumRow() << std::endl;
}

void SW_Filter_TD_18921231(Table &tbl_SerializeFromObject_TD_19986180_input, Table &tbl_Filter_TD_18921231_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(s_store_sk#378) AND (isnotnull(s_store_name#383) AND isnotnull(s_zip#403))))
    // Input: ListBuffer(s_store_sk#378, s_store_name#383, s_zip#403)
    // Output: ListBuffer(s_store_sk#378, s_store_name#383, s_zip#403)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_19986180_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _s_store_sk378 = tbl_SerializeFromObject_TD_19986180_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383 = tbl_SerializeFromObject_TD_19986180_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _s_zip403 = tbl_SerializeFromObject_TD_19986180_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        if ((_s_store_sk378!= 0) && (_s_store_name383.data() != "NULL" && _s_zip403.data() != "NULL")) {
            int32_t _s_store_sk378_t = tbl_SerializeFromObject_TD_19986180_input.getInt32(i, 0);
            tbl_Filter_TD_18921231_output.setInt32(r, 0, _s_store_sk378_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_t = tbl_SerializeFromObject_TD_19986180_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_18921231_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_store_name383_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_zip403_t = tbl_SerializeFromObject_TD_19986180_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_18921231_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _s_zip403_t);
            r++;
        }
    }
    tbl_Filter_TD_18921231_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_18921231_output #Row: " << tbl_Filter_TD_18921231_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_18402844_key_leftMajor {
    int32_t _ss_sold_date_sk1206;
    bool operator==(const SW_JOIN_INNER_TD_18402844_key_leftMajor& other) const {
        return ((_ss_sold_date_sk1206 == other._ss_sold_date_sk1206));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_18402844_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_18402844_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_sold_date_sk1206));
    }
};
}
struct SW_JOIN_INNER_TD_18402844_payload_leftMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_item_sk1208;
    int32_t _ss_customer_sk1209;
    int32_t _ss_cdemo_sk1210;
    int32_t _ss_hdemo_sk1211;
    int32_t _ss_addr_sk1212;
    int32_t _ss_store_sk1213;
    int32_t _ss_promo_sk1214;
    int64_t _ss_wholesale_cost1217;
    int64_t _ss_list_price1218;
    int64_t _ss_coupon_amt1225;
};
struct SW_JOIN_INNER_TD_18402844_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_18402844_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_18402844_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_18402844_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_18402844_payload_rightMajor {
    int32_t _d_date_sk120;
    int32_t _d_year126;
};
void SW_JOIN_INNER_TD_18402844(Table &tbl_JOIN_INNER_TD_19871408_output, Table &tbl_Filter_TD_19514965_output, Table &tbl_JOIN_INNER_TD_18402844_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#1206 = d_date_sk#120))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_store_sk#1213, ss_promo_sk#1214, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225)
    // Right Table: ListBuffer(d_date_sk#120, d_year#126)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_customer_sk#1209, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_store_sk#1213, ss_promo_sk#1214, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126)
    int left_nrow = tbl_JOIN_INNER_TD_19871408_output.getNumRow();
    int right_nrow = tbl_Filter_TD_19514965_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_18402844_key_leftMajor, SW_JOIN_INNER_TD_18402844_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_19871408_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_JOIN_INNER_TD_19871408_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_18402844_key_leftMajor keyA{_ss_sold_date_sk1206_k};
            int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_19871408_output.getInt32(i, 0);
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_19871408_output.getInt32(i, 1);
            int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_19871408_output.getInt32(i, 2);
            int32_t _ss_cdemo_sk1210 = tbl_JOIN_INNER_TD_19871408_output.getInt32(i, 3);
            int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_19871408_output.getInt32(i, 4);
            int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_19871408_output.getInt32(i, 5);
            int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_19871408_output.getInt32(i, 6);
            int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_19871408_output.getInt32(i, 7);
            int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_19871408_output.getInt64(i, 8);
            int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_19871408_output.getInt64(i, 9);
            int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_19871408_output.getInt64(i, 10);
            SW_JOIN_INNER_TD_18402844_payload_leftMajor payloadA{_ss_sold_date_sk1206, _ss_item_sk1208, _ss_customer_sk1209, _ss_cdemo_sk1210, _ss_hdemo_sk1211, _ss_addr_sk1212, _ss_store_sk1213, _ss_promo_sk1214, _ss_wholesale_cost1217, _ss_list_price1218, _ss_coupon_amt1225};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_19514965_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_19514965_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_18402844_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                int32_t _ss_cdemo_sk1210 = (it->second)._ss_cdemo_sk1210;
                int32_t _ss_hdemo_sk1211 = (it->second)._ss_hdemo_sk1211;
                int32_t _ss_addr_sk1212 = (it->second)._ss_addr_sk1212;
                int32_t _ss_store_sk1213 = (it->second)._ss_store_sk1213;
                int32_t _ss_promo_sk1214 = (it->second)._ss_promo_sk1214;
                int64_t _ss_wholesale_cost1217 = (it->second)._ss_wholesale_cost1217;
                int64_t _ss_list_price1218 = (it->second)._ss_list_price1218;
                int64_t _ss_coupon_amt1225 = (it->second)._ss_coupon_amt1225;
                int32_t _d_date_sk120 = tbl_Filter_TD_19514965_output.getInt32(i, 0);
                int32_t _d_year126 = tbl_Filter_TD_19514965_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_18402844_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_18402844_output.setInt32(r, 1, _ss_customer_sk1209);
                tbl_JOIN_INNER_TD_18402844_output.setInt32(r, 2, _ss_cdemo_sk1210);
                tbl_JOIN_INNER_TD_18402844_output.setInt32(r, 3, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_18402844_output.setInt32(r, 4, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_18402844_output.setInt32(r, 5, _ss_store_sk1213);
                tbl_JOIN_INNER_TD_18402844_output.setInt32(r, 6, _ss_promo_sk1214);
                tbl_JOIN_INNER_TD_18402844_output.setInt64(r, 7, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_18402844_output.setInt64(r, 8, _ss_list_price1218);
                tbl_JOIN_INNER_TD_18402844_output.setInt64(r, 9, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_18402844_output.setInt32(r, 10, _d_year126);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_18402844_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_18402844_key_rightMajor, SW_JOIN_INNER_TD_18402844_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_19514965_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_19514965_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_18402844_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_19514965_output.getInt32(i, 0);
            int32_t _d_year126 = tbl_Filter_TD_19514965_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_18402844_payload_rightMajor payloadA{_d_date_sk120, _d_year126};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_19871408_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_JOIN_INNER_TD_19871408_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_18402844_key_rightMajor{_ss_sold_date_sk1206_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _d_year126 = (it->second)._d_year126;
                int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_19871408_output.getInt32(i, 0);
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_19871408_output.getInt32(i, 1);
                int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_19871408_output.getInt32(i, 2);
                int32_t _ss_cdemo_sk1210 = tbl_JOIN_INNER_TD_19871408_output.getInt32(i, 3);
                int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_19871408_output.getInt32(i, 4);
                int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_19871408_output.getInt32(i, 5);
                int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_19871408_output.getInt32(i, 6);
                int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_19871408_output.getInt32(i, 7);
                int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_19871408_output.getInt64(i, 8);
                int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_19871408_output.getInt64(i, 9);
                int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_19871408_output.getInt64(i, 10);
                tbl_JOIN_INNER_TD_18402844_output.setInt32(r, 10, _d_year126);
                tbl_JOIN_INNER_TD_18402844_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_18402844_output.setInt32(r, 1, _ss_customer_sk1209);
                tbl_JOIN_INNER_TD_18402844_output.setInt32(r, 2, _ss_cdemo_sk1210);
                tbl_JOIN_INNER_TD_18402844_output.setInt32(r, 3, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_18402844_output.setInt32(r, 4, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_18402844_output.setInt32(r, 5, _ss_store_sk1213);
                tbl_JOIN_INNER_TD_18402844_output.setInt32(r, 6, _ss_promo_sk1214);
                tbl_JOIN_INNER_TD_18402844_output.setInt64(r, 7, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_18402844_output.setInt64(r, 8, _ss_list_price1218);
                tbl_JOIN_INNER_TD_18402844_output.setInt64(r, 9, _ss_coupon_amt1225);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_18402844_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_18402844_output #Row: " << tbl_JOIN_INNER_TD_18402844_output.getNumRow() << std::endl;
}

void SW_Filter_TD_17952307(Table &tbl_SerializeFromObject_TD_18797728_input, Table &tbl_Filter_TD_17952307_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(c_customer_sk#4975) AND ((isnotnull(c_first_sales_date_sk#4981) AND isnotnull(c_first_shipto_date_sk#4980)) AND isnotnull(c_current_cdemo_sk#4977))) AND (isnotnull(c_current_hdemo_sk#4978) AND isnotnull(c_current_addr_sk#4979))))
    // Input: ListBuffer(c_customer_sk#4975, c_current_cdemo_sk#4977, c_current_hdemo_sk#4978, c_current_addr_sk#4979, c_first_shipto_date_sk#4980, c_first_sales_date_sk#4981)
    // Output: ListBuffer(c_customer_sk#4975, c_current_cdemo_sk#4977, c_current_hdemo_sk#4978, c_current_addr_sk#4979, c_first_shipto_date_sk#4980, c_first_sales_date_sk#4981)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_18797728_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk4975 = tbl_SerializeFromObject_TD_18797728_input.getInt32(i, 0);
        int32_t _c_first_sales_date_sk4981 = tbl_SerializeFromObject_TD_18797728_input.getInt32(i, 5);
        int32_t _c_first_shipto_date_sk4980 = tbl_SerializeFromObject_TD_18797728_input.getInt32(i, 4);
        int32_t _c_current_cdemo_sk4977 = tbl_SerializeFromObject_TD_18797728_input.getInt32(i, 1);
        int32_t _c_current_hdemo_sk4978 = tbl_SerializeFromObject_TD_18797728_input.getInt32(i, 2);
        int32_t _c_current_addr_sk4979 = tbl_SerializeFromObject_TD_18797728_input.getInt32(i, 3);
        if (((_c_customer_sk4975!= 0) && (((_c_first_sales_date_sk4981!= 0) && (_c_first_shipto_date_sk4980!= 0)) && (_c_current_cdemo_sk4977!= 0))) && ((_c_current_hdemo_sk4978!= 0) && (_c_current_addr_sk4979!= 0))) {
            int32_t _c_customer_sk4975_t = tbl_SerializeFromObject_TD_18797728_input.getInt32(i, 0);
            tbl_Filter_TD_17952307_output.setInt32(r, 0, _c_customer_sk4975_t);
            int32_t _c_current_cdemo_sk4977_t = tbl_SerializeFromObject_TD_18797728_input.getInt32(i, 1);
            tbl_Filter_TD_17952307_output.setInt32(r, 1, _c_current_cdemo_sk4977_t);
            int32_t _c_current_hdemo_sk4978_t = tbl_SerializeFromObject_TD_18797728_input.getInt32(i, 2);
            tbl_Filter_TD_17952307_output.setInt32(r, 2, _c_current_hdemo_sk4978_t);
            int32_t _c_current_addr_sk4979_t = tbl_SerializeFromObject_TD_18797728_input.getInt32(i, 3);
            tbl_Filter_TD_17952307_output.setInt32(r, 3, _c_current_addr_sk4979_t);
            int32_t _c_first_shipto_date_sk4980_t = tbl_SerializeFromObject_TD_18797728_input.getInt32(i, 4);
            tbl_Filter_TD_17952307_output.setInt32(r, 4, _c_first_shipto_date_sk4980_t);
            int32_t _c_first_sales_date_sk4981_t = tbl_SerializeFromObject_TD_18797728_input.getInt32(i, 5);
            tbl_Filter_TD_17952307_output.setInt32(r, 5, _c_first_sales_date_sk4981_t);
            r++;
        }
    }
    tbl_Filter_TD_17952307_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_17952307_output #Row: " << tbl_Filter_TD_17952307_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_17330885_key_leftMajor {
    int32_t _ss_store_sk4765;
    bool operator==(const SW_JOIN_INNER_TD_17330885_key_leftMajor& other) const {
        return ((_ss_store_sk4765 == other._ss_store_sk4765));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_17330885_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_17330885_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_store_sk4765));
    }
};
}
struct SW_JOIN_INNER_TD_17330885_payload_leftMajor {
    int32_t _ss_item_sk4760;
    int32_t _ss_customer_sk4761;
    int32_t _ss_cdemo_sk4762;
    int32_t _ss_hdemo_sk4763;
    int32_t _ss_addr_sk4764;
    int32_t _ss_store_sk4765;
    int32_t _ss_promo_sk4766;
    int64_t _ss_wholesale_cost4769;
    int64_t _ss_list_price4770;
    int64_t _ss_coupon_amt4777;
    int32_t _d_year4868;
};
struct SW_JOIN_INNER_TD_17330885_key_rightMajor {
    int32_t _s_store_sk4946;
    bool operator==(const SW_JOIN_INNER_TD_17330885_key_rightMajor& other) const {
        return ((_s_store_sk4946 == other._s_store_sk4946));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_17330885_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_17330885_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_store_sk4946));
    }
};
}
struct SW_JOIN_INNER_TD_17330885_payload_rightMajor {
    int32_t _s_store_sk4946;
    std::string _s_store_name4951;
    std::string _s_zip4971;
};
void SW_JOIN_INNER_TD_17330885(Table &tbl_JOIN_INNER_TD_18378634_output, Table &tbl_Filter_TD_18157257_output, Table &tbl_JOIN_INNER_TD_17330885_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_store_sk#4765 = s_store_sk#4946))
    // Left Table: ListBuffer(ss_item_sk#4760, ss_customer_sk#4761, ss_cdemo_sk#4762, ss_hdemo_sk#4763, ss_addr_sk#4764, ss_store_sk#4765, ss_promo_sk#4766, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868)
    // Right Table: ListBuffer(s_store_sk#4946, s_store_name#4951, s_zip#4971)
    // Output Table: ListBuffer(ss_item_sk#4760, ss_customer_sk#4761, ss_cdemo_sk#4762, ss_hdemo_sk#4763, ss_addr_sk#4764, ss_promo_sk#4766, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971)
    int left_nrow = tbl_JOIN_INNER_TD_18378634_output.getNumRow();
    int right_nrow = tbl_Filter_TD_18157257_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_17330885_key_leftMajor, SW_JOIN_INNER_TD_17330885_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_18378634_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_store_sk4765_k = tbl_JOIN_INNER_TD_18378634_output.getInt32(i, 5);
            SW_JOIN_INNER_TD_17330885_key_leftMajor keyA{_ss_store_sk4765_k};
            int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_18378634_output.getInt32(i, 0);
            int32_t _ss_customer_sk4761 = tbl_JOIN_INNER_TD_18378634_output.getInt32(i, 1);
            int32_t _ss_cdemo_sk4762 = tbl_JOIN_INNER_TD_18378634_output.getInt32(i, 2);
            int32_t _ss_hdemo_sk4763 = tbl_JOIN_INNER_TD_18378634_output.getInt32(i, 3);
            int32_t _ss_addr_sk4764 = tbl_JOIN_INNER_TD_18378634_output.getInt32(i, 4);
            int32_t _ss_store_sk4765 = tbl_JOIN_INNER_TD_18378634_output.getInt32(i, 5);
            int32_t _ss_promo_sk4766 = tbl_JOIN_INNER_TD_18378634_output.getInt32(i, 6);
            int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_18378634_output.getInt64(i, 7);
            int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_18378634_output.getInt64(i, 8);
            int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_18378634_output.getInt64(i, 9);
            int32_t _d_year4868 = tbl_JOIN_INNER_TD_18378634_output.getInt32(i, 10);
            SW_JOIN_INNER_TD_17330885_payload_leftMajor payloadA{_ss_item_sk4760, _ss_customer_sk4761, _ss_cdemo_sk4762, _ss_hdemo_sk4763, _ss_addr_sk4764, _ss_store_sk4765, _ss_promo_sk4766, _ss_wholesale_cost4769, _ss_list_price4770, _ss_coupon_amt4777, _d_year4868};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_18157257_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_store_sk4946_k = tbl_Filter_TD_18157257_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_17330885_key_leftMajor{_s_store_sk4946_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk4760 = (it->second)._ss_item_sk4760;
                int32_t _ss_customer_sk4761 = (it->second)._ss_customer_sk4761;
                int32_t _ss_cdemo_sk4762 = (it->second)._ss_cdemo_sk4762;
                int32_t _ss_hdemo_sk4763 = (it->second)._ss_hdemo_sk4763;
                int32_t _ss_addr_sk4764 = (it->second)._ss_addr_sk4764;
                int32_t _ss_store_sk4765 = (it->second)._ss_store_sk4765;
                int32_t _ss_promo_sk4766 = (it->second)._ss_promo_sk4766;
                int64_t _ss_wholesale_cost4769 = (it->second)._ss_wholesale_cost4769;
                int64_t _ss_list_price4770 = (it->second)._ss_list_price4770;
                int64_t _ss_coupon_amt4777 = (it->second)._ss_coupon_amt4777;
                int32_t _d_year4868 = (it->second)._d_year4868;
                int32_t _s_store_sk4946 = tbl_Filter_TD_18157257_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_Filter_TD_18157257_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_Filter_TD_18157257_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _s_zip4971 = std::string(_s_zip4971_n.data());
                tbl_JOIN_INNER_TD_17330885_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_17330885_output.setInt32(r, 1, _ss_customer_sk4761);
                tbl_JOIN_INNER_TD_17330885_output.setInt32(r, 2, _ss_cdemo_sk4762);
                tbl_JOIN_INNER_TD_17330885_output.setInt32(r, 3, _ss_hdemo_sk4763);
                tbl_JOIN_INNER_TD_17330885_output.setInt32(r, 4, _ss_addr_sk4764);
                tbl_JOIN_INNER_TD_17330885_output.setInt32(r, 5, _ss_promo_sk4766);
                tbl_JOIN_INNER_TD_17330885_output.setInt64(r, 6, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_17330885_output.setInt64(r, 7, _ss_list_price4770);
                tbl_JOIN_INNER_TD_17330885_output.setInt64(r, 8, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_17330885_output.setInt32(r, 9, _d_year4868);
                tbl_JOIN_INNER_TD_17330885_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_17330885_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _s_zip4971_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_17330885_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_17330885_key_rightMajor, SW_JOIN_INNER_TD_17330885_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_18157257_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_store_sk4946_k = tbl_Filter_TD_18157257_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_17330885_key_rightMajor keyA{_s_store_sk4946_k};
            int32_t _s_store_sk4946 = tbl_Filter_TD_18157257_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_Filter_TD_18157257_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_Filter_TD_18157257_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _s_zip4971 = std::string(_s_zip4971_n.data());
            SW_JOIN_INNER_TD_17330885_payload_rightMajor payloadA{_s_store_sk4946, _s_store_name4951, _s_zip4971};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_18378634_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_store_sk4765_k = tbl_JOIN_INNER_TD_18378634_output.getInt32(i, 5);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_17330885_key_rightMajor{_ss_store_sk4765_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _s_store_sk4946 = (it->second)._s_store_sk4946;
                std::string _s_store_name4951 = (it->second)._s_store_name4951;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n{};
                memcpy(_s_store_name4951_n.data(), (_s_store_name4951).data(), (_s_store_name4951).length());
                std::string _s_zip4971 = (it->second)._s_zip4971;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n{};
                memcpy(_s_zip4971_n.data(), (_s_zip4971).data(), (_s_zip4971).length());
                int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_18378634_output.getInt32(i, 0);
                int32_t _ss_customer_sk4761 = tbl_JOIN_INNER_TD_18378634_output.getInt32(i, 1);
                int32_t _ss_cdemo_sk4762 = tbl_JOIN_INNER_TD_18378634_output.getInt32(i, 2);
                int32_t _ss_hdemo_sk4763 = tbl_JOIN_INNER_TD_18378634_output.getInt32(i, 3);
                int32_t _ss_addr_sk4764 = tbl_JOIN_INNER_TD_18378634_output.getInt32(i, 4);
                int32_t _ss_store_sk4765 = tbl_JOIN_INNER_TD_18378634_output.getInt32(i, 5);
                int32_t _ss_promo_sk4766 = tbl_JOIN_INNER_TD_18378634_output.getInt32(i, 6);
                int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_18378634_output.getInt64(i, 7);
                int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_18378634_output.getInt64(i, 8);
                int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_18378634_output.getInt64(i, 9);
                int32_t _d_year4868 = tbl_JOIN_INNER_TD_18378634_output.getInt32(i, 10);
                tbl_JOIN_INNER_TD_17330885_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_17330885_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _s_zip4971_n);
                tbl_JOIN_INNER_TD_17330885_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_17330885_output.setInt32(r, 1, _ss_customer_sk4761);
                tbl_JOIN_INNER_TD_17330885_output.setInt32(r, 2, _ss_cdemo_sk4762);
                tbl_JOIN_INNER_TD_17330885_output.setInt32(r, 3, _ss_hdemo_sk4763);
                tbl_JOIN_INNER_TD_17330885_output.setInt32(r, 4, _ss_addr_sk4764);
                tbl_JOIN_INNER_TD_17330885_output.setInt32(r, 5, _ss_promo_sk4766);
                tbl_JOIN_INNER_TD_17330885_output.setInt64(r, 6, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_17330885_output.setInt64(r, 7, _ss_list_price4770);
                tbl_JOIN_INNER_TD_17330885_output.setInt64(r, 8, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_17330885_output.setInt32(r, 9, _d_year4868);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_17330885_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_17330885_output #Row: " << tbl_JOIN_INNER_TD_17330885_output.getNumRow() << std::endl;
}

void SW_Filter_TD_17180494(Table &tbl_SerializeFromObject_TD_18137679_input, Table &tbl_Filter_TD_17180494_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(c_customer_sk#0) AND ((isnotnull(c_first_sales_date_sk#6) AND isnotnull(c_first_shipto_date_sk#5)) AND isnotnull(c_current_cdemo_sk#2))) AND (isnotnull(c_current_hdemo_sk#3) AND isnotnull(c_current_addr_sk#4))))
    // Input: ListBuffer(c_customer_sk#0, c_current_cdemo_sk#2, c_current_hdemo_sk#3, c_current_addr_sk#4, c_first_shipto_date_sk#5, c_first_sales_date_sk#6)
    // Output: ListBuffer(c_customer_sk#0, c_current_cdemo_sk#2, c_current_hdemo_sk#3, c_current_addr_sk#4, c_first_shipto_date_sk#5, c_first_sales_date_sk#6)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_18137679_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk0 = tbl_SerializeFromObject_TD_18137679_input.getInt32(i, 0);
        int32_t _c_first_sales_date_sk6 = tbl_SerializeFromObject_TD_18137679_input.getInt32(i, 5);
        int32_t _c_first_shipto_date_sk5 = tbl_SerializeFromObject_TD_18137679_input.getInt32(i, 4);
        int32_t _c_current_cdemo_sk2 = tbl_SerializeFromObject_TD_18137679_input.getInt32(i, 1);
        int32_t _c_current_hdemo_sk3 = tbl_SerializeFromObject_TD_18137679_input.getInt32(i, 2);
        int32_t _c_current_addr_sk4 = tbl_SerializeFromObject_TD_18137679_input.getInt32(i, 3);
        if (((_c_customer_sk0!= 0) && (((_c_first_sales_date_sk6!= 0) && (_c_first_shipto_date_sk5!= 0)) && (_c_current_cdemo_sk2!= 0))) && ((_c_current_hdemo_sk3!= 0) && (_c_current_addr_sk4!= 0))) {
            int32_t _c_customer_sk0_t = tbl_SerializeFromObject_TD_18137679_input.getInt32(i, 0);
            tbl_Filter_TD_17180494_output.setInt32(r, 0, _c_customer_sk0_t);
            int32_t _c_current_cdemo_sk2_t = tbl_SerializeFromObject_TD_18137679_input.getInt32(i, 1);
            tbl_Filter_TD_17180494_output.setInt32(r, 1, _c_current_cdemo_sk2_t);
            int32_t _c_current_hdemo_sk3_t = tbl_SerializeFromObject_TD_18137679_input.getInt32(i, 2);
            tbl_Filter_TD_17180494_output.setInt32(r, 2, _c_current_hdemo_sk3_t);
            int32_t _c_current_addr_sk4_t = tbl_SerializeFromObject_TD_18137679_input.getInt32(i, 3);
            tbl_Filter_TD_17180494_output.setInt32(r, 3, _c_current_addr_sk4_t);
            int32_t _c_first_shipto_date_sk5_t = tbl_SerializeFromObject_TD_18137679_input.getInt32(i, 4);
            tbl_Filter_TD_17180494_output.setInt32(r, 4, _c_first_shipto_date_sk5_t);
            int32_t _c_first_sales_date_sk6_t = tbl_SerializeFromObject_TD_18137679_input.getInt32(i, 5);
            tbl_Filter_TD_17180494_output.setInt32(r, 5, _c_first_sales_date_sk6_t);
            r++;
        }
    }
    tbl_Filter_TD_17180494_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_17180494_output #Row: " << tbl_Filter_TD_17180494_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_17102777_key_leftMajor {
    int32_t _ss_store_sk1213;
    bool operator==(const SW_JOIN_INNER_TD_17102777_key_leftMajor& other) const {
        return ((_ss_store_sk1213 == other._ss_store_sk1213));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_17102777_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_17102777_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_store_sk1213));
    }
};
}
struct SW_JOIN_INNER_TD_17102777_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int32_t _ss_customer_sk1209;
    int32_t _ss_cdemo_sk1210;
    int32_t _ss_hdemo_sk1211;
    int32_t _ss_addr_sk1212;
    int32_t _ss_store_sk1213;
    int32_t _ss_promo_sk1214;
    int64_t _ss_wholesale_cost1217;
    int64_t _ss_list_price1218;
    int64_t _ss_coupon_amt1225;
    int32_t _d_year126;
};
struct SW_JOIN_INNER_TD_17102777_key_rightMajor {
    int32_t _s_store_sk378;
    bool operator==(const SW_JOIN_INNER_TD_17102777_key_rightMajor& other) const {
        return ((_s_store_sk378 == other._s_store_sk378));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_17102777_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_17102777_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_store_sk378));
    }
};
}
struct SW_JOIN_INNER_TD_17102777_payload_rightMajor {
    int32_t _s_store_sk378;
    std::string _s_store_name383;
    std::string _s_zip403;
};
void SW_JOIN_INNER_TD_17102777(Table &tbl_JOIN_INNER_TD_18402844_output, Table &tbl_Filter_TD_18921231_output, Table &tbl_JOIN_INNER_TD_17102777_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_store_sk#1213 = s_store_sk#378))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_customer_sk#1209, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_store_sk#1213, ss_promo_sk#1214, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126)
    // Right Table: ListBuffer(s_store_sk#378, s_store_name#383, s_zip#403)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_customer_sk#1209, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_promo_sk#1214, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403)
    int left_nrow = tbl_JOIN_INNER_TD_18402844_output.getNumRow();
    int right_nrow = tbl_Filter_TD_18921231_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_17102777_key_leftMajor, SW_JOIN_INNER_TD_17102777_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_18402844_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_store_sk1213_k = tbl_JOIN_INNER_TD_18402844_output.getInt32(i, 5);
            SW_JOIN_INNER_TD_17102777_key_leftMajor keyA{_ss_store_sk1213_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_18402844_output.getInt32(i, 0);
            int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_18402844_output.getInt32(i, 1);
            int32_t _ss_cdemo_sk1210 = tbl_JOIN_INNER_TD_18402844_output.getInt32(i, 2);
            int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_18402844_output.getInt32(i, 3);
            int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_18402844_output.getInt32(i, 4);
            int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_18402844_output.getInt32(i, 5);
            int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_18402844_output.getInt32(i, 6);
            int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_18402844_output.getInt64(i, 7);
            int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_18402844_output.getInt64(i, 8);
            int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_18402844_output.getInt64(i, 9);
            int32_t _d_year126 = tbl_JOIN_INNER_TD_18402844_output.getInt32(i, 10);
            SW_JOIN_INNER_TD_17102777_payload_leftMajor payloadA{_ss_item_sk1208, _ss_customer_sk1209, _ss_cdemo_sk1210, _ss_hdemo_sk1211, _ss_addr_sk1212, _ss_store_sk1213, _ss_promo_sk1214, _ss_wholesale_cost1217, _ss_list_price1218, _ss_coupon_amt1225, _d_year126};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_18921231_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_18921231_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_17102777_key_leftMajor{_s_store_sk378_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                int32_t _ss_cdemo_sk1210 = (it->second)._ss_cdemo_sk1210;
                int32_t _ss_hdemo_sk1211 = (it->second)._ss_hdemo_sk1211;
                int32_t _ss_addr_sk1212 = (it->second)._ss_addr_sk1212;
                int32_t _ss_store_sk1213 = (it->second)._ss_store_sk1213;
                int32_t _ss_promo_sk1214 = (it->second)._ss_promo_sk1214;
                int64_t _ss_wholesale_cost1217 = (it->second)._ss_wholesale_cost1217;
                int64_t _ss_list_price1218 = (it->second)._ss_list_price1218;
                int64_t _ss_coupon_amt1225 = (it->second)._ss_coupon_amt1225;
                int32_t _d_year126 = (it->second)._d_year126;
                int32_t _s_store_sk378 = tbl_Filter_TD_18921231_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_Filter_TD_18921231_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _s_store_name383 = std::string(_s_store_name383_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_Filter_TD_18921231_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _s_zip403 = std::string(_s_zip403_n.data());
                tbl_JOIN_INNER_TD_17102777_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_17102777_output.setInt32(r, 1, _ss_customer_sk1209);
                tbl_JOIN_INNER_TD_17102777_output.setInt32(r, 2, _ss_cdemo_sk1210);
                tbl_JOIN_INNER_TD_17102777_output.setInt32(r, 3, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_17102777_output.setInt32(r, 4, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_17102777_output.setInt32(r, 5, _ss_promo_sk1214);
                tbl_JOIN_INNER_TD_17102777_output.setInt64(r, 6, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_17102777_output.setInt64(r, 7, _ss_list_price1218);
                tbl_JOIN_INNER_TD_17102777_output.setInt64(r, 8, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_17102777_output.setInt32(r, 9, _d_year126);
                tbl_JOIN_INNER_TD_17102777_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _s_store_name383_n);
                tbl_JOIN_INNER_TD_17102777_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _s_zip403_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_17102777_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_17102777_key_rightMajor, SW_JOIN_INNER_TD_17102777_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_18921231_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_18921231_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_17102777_key_rightMajor keyA{_s_store_sk378_k};
            int32_t _s_store_sk378 = tbl_Filter_TD_18921231_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_Filter_TD_18921231_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _s_store_name383 = std::string(_s_store_name383_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_Filter_TD_18921231_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _s_zip403 = std::string(_s_zip403_n.data());
            SW_JOIN_INNER_TD_17102777_payload_rightMajor payloadA{_s_store_sk378, _s_store_name383, _s_zip403};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_18402844_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_store_sk1213_k = tbl_JOIN_INNER_TD_18402844_output.getInt32(i, 5);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_17102777_key_rightMajor{_ss_store_sk1213_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _s_store_sk378 = (it->second)._s_store_sk378;
                std::string _s_store_name383 = (it->second)._s_store_name383;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n{};
                memcpy(_s_store_name383_n.data(), (_s_store_name383).data(), (_s_store_name383).length());
                std::string _s_zip403 = (it->second)._s_zip403;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n{};
                memcpy(_s_zip403_n.data(), (_s_zip403).data(), (_s_zip403).length());
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_18402844_output.getInt32(i, 0);
                int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_18402844_output.getInt32(i, 1);
                int32_t _ss_cdemo_sk1210 = tbl_JOIN_INNER_TD_18402844_output.getInt32(i, 2);
                int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_18402844_output.getInt32(i, 3);
                int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_18402844_output.getInt32(i, 4);
                int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_18402844_output.getInt32(i, 5);
                int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_18402844_output.getInt32(i, 6);
                int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_18402844_output.getInt64(i, 7);
                int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_18402844_output.getInt64(i, 8);
                int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_18402844_output.getInt64(i, 9);
                int32_t _d_year126 = tbl_JOIN_INNER_TD_18402844_output.getInt32(i, 10);
                tbl_JOIN_INNER_TD_17102777_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _s_store_name383_n);
                tbl_JOIN_INNER_TD_17102777_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _s_zip403_n);
                tbl_JOIN_INNER_TD_17102777_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_17102777_output.setInt32(r, 1, _ss_customer_sk1209);
                tbl_JOIN_INNER_TD_17102777_output.setInt32(r, 2, _ss_cdemo_sk1210);
                tbl_JOIN_INNER_TD_17102777_output.setInt32(r, 3, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_17102777_output.setInt32(r, 4, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_17102777_output.setInt32(r, 5, _ss_promo_sk1214);
                tbl_JOIN_INNER_TD_17102777_output.setInt64(r, 6, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_17102777_output.setInt64(r, 7, _ss_list_price1218);
                tbl_JOIN_INNER_TD_17102777_output.setInt64(r, 8, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_17102777_output.setInt32(r, 9, _d_year126);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_17102777_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_17102777_output #Row: " << tbl_JOIN_INNER_TD_17102777_output.getNumRow() << std::endl;
}

void SW_Filter_TD_16382357(Table &tbl_SerializeFromObject_TD_17244473_input, Table &tbl_Filter_TD_16382357_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(d_date_sk#4890))
    // Input: ListBuffer(d_date_sk#4890, d_year#4896)
    // Output: ListBuffer(d_date_sk#4890, d_year#4896)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_17244473_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date_sk4890 = tbl_SerializeFromObject_TD_17244473_input.getInt32(i, 0);
        if (_d_date_sk4890!= 0) {
            int32_t _d_date_sk4890_t = tbl_SerializeFromObject_TD_17244473_input.getInt32(i, 0);
            tbl_Filter_TD_16382357_output.setInt32(r, 0, _d_date_sk4890_t);
            int32_t _d_year4896_t = tbl_SerializeFromObject_TD_17244473_input.getInt32(i, 1);
            tbl_Filter_TD_16382357_output.setInt32(r, 1, _d_year4896_t);
            r++;
        }
    }
    tbl_Filter_TD_16382357_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_16382357_output #Row: " << tbl_Filter_TD_16382357_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_16134853_key_leftMajor {
    int32_t _ss_customer_sk4761;
    bool operator==(const SW_JOIN_INNER_TD_16134853_key_leftMajor& other) const {
        return ((_ss_customer_sk4761 == other._ss_customer_sk4761));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_16134853_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_16134853_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_customer_sk4761));
    }
};
}
struct SW_JOIN_INNER_TD_16134853_payload_leftMajor {
    int32_t _ss_item_sk4760;
    int32_t _ss_customer_sk4761;
    int32_t _ss_cdemo_sk4762;
    int32_t _ss_hdemo_sk4763;
    int32_t _ss_addr_sk4764;
    int32_t _ss_promo_sk4766;
    int64_t _ss_wholesale_cost4769;
    int64_t _ss_list_price4770;
    int64_t _ss_coupon_amt4777;
    int32_t _d_year4868;
    std::string _s_store_name4951;
    std::string _s_zip4971;
};
struct SW_JOIN_INNER_TD_16134853_key_rightMajor {
    int32_t _c_customer_sk4975;
    bool operator==(const SW_JOIN_INNER_TD_16134853_key_rightMajor& other) const {
        return ((_c_customer_sk4975 == other._c_customer_sk4975));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_16134853_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_16134853_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk4975));
    }
};
}
struct SW_JOIN_INNER_TD_16134853_payload_rightMajor {
    int32_t _c_customer_sk4975;
    int32_t _c_current_cdemo_sk4977;
    int32_t _c_current_hdemo_sk4978;
    int32_t _c_current_addr_sk4979;
    int32_t _c_first_shipto_date_sk4980;
    int32_t _c_first_sales_date_sk4981;
};
void SW_JOIN_INNER_TD_16134853(Table &tbl_JOIN_INNER_TD_17330885_output, Table &tbl_Filter_TD_17952307_output, Table &tbl_JOIN_INNER_TD_16134853_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_customer_sk#4761 = c_customer_sk#4975))
    // Left Table: ListBuffer(ss_item_sk#4760, ss_customer_sk#4761, ss_cdemo_sk#4762, ss_hdemo_sk#4763, ss_addr_sk#4764, ss_promo_sk#4766, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971)
    // Right Table: ListBuffer(c_customer_sk#4975, c_current_cdemo_sk#4977, c_current_hdemo_sk#4978, c_current_addr_sk#4979, c_first_shipto_date_sk#4980, c_first_sales_date_sk#4981)
    // Output Table: ListBuffer(ss_item_sk#4760, ss_cdemo_sk#4762, ss_hdemo_sk#4763, ss_addr_sk#4764, ss_promo_sk#4766, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971, c_current_cdemo_sk#4977, c_current_hdemo_sk#4978, c_current_addr_sk#4979, c_first_shipto_date_sk#4980, c_first_sales_date_sk#4981)
    int left_nrow = tbl_JOIN_INNER_TD_17330885_output.getNumRow();
    int right_nrow = tbl_Filter_TD_17952307_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_16134853_key_leftMajor, SW_JOIN_INNER_TD_16134853_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_17330885_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_customer_sk4761_k = tbl_JOIN_INNER_TD_17330885_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_16134853_key_leftMajor keyA{_ss_customer_sk4761_k};
            int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_17330885_output.getInt32(i, 0);
            int32_t _ss_customer_sk4761 = tbl_JOIN_INNER_TD_17330885_output.getInt32(i, 1);
            int32_t _ss_cdemo_sk4762 = tbl_JOIN_INNER_TD_17330885_output.getInt32(i, 2);
            int32_t _ss_hdemo_sk4763 = tbl_JOIN_INNER_TD_17330885_output.getInt32(i, 3);
            int32_t _ss_addr_sk4764 = tbl_JOIN_INNER_TD_17330885_output.getInt32(i, 4);
            int32_t _ss_promo_sk4766 = tbl_JOIN_INNER_TD_17330885_output.getInt32(i, 5);
            int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_17330885_output.getInt64(i, 6);
            int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_17330885_output.getInt64(i, 7);
            int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_17330885_output.getInt64(i, 8);
            int32_t _d_year4868 = tbl_JOIN_INNER_TD_17330885_output.getInt32(i, 9);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_17330885_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_17330885_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
            std::string _s_zip4971 = std::string(_s_zip4971_n.data());
            SW_JOIN_INNER_TD_16134853_payload_leftMajor payloadA{_ss_item_sk4760, _ss_customer_sk4761, _ss_cdemo_sk4762, _ss_hdemo_sk4763, _ss_addr_sk4764, _ss_promo_sk4766, _ss_wholesale_cost4769, _ss_list_price4770, _ss_coupon_amt4777, _d_year4868, _s_store_name4951, _s_zip4971};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_17952307_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk4975_k = tbl_Filter_TD_17952307_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_16134853_key_leftMajor{_c_customer_sk4975_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk4760 = (it->second)._ss_item_sk4760;
                int32_t _ss_customer_sk4761 = (it->second)._ss_customer_sk4761;
                int32_t _ss_cdemo_sk4762 = (it->second)._ss_cdemo_sk4762;
                int32_t _ss_hdemo_sk4763 = (it->second)._ss_hdemo_sk4763;
                int32_t _ss_addr_sk4764 = (it->second)._ss_addr_sk4764;
                int32_t _ss_promo_sk4766 = (it->second)._ss_promo_sk4766;
                int64_t _ss_wholesale_cost4769 = (it->second)._ss_wholesale_cost4769;
                int64_t _ss_list_price4770 = (it->second)._ss_list_price4770;
                int64_t _ss_coupon_amt4777 = (it->second)._ss_coupon_amt4777;
                int32_t _d_year4868 = (it->second)._d_year4868;
                std::string _s_store_name4951 = (it->second)._s_store_name4951;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n{};
                memcpy(_s_store_name4951_n.data(), (_s_store_name4951).data(), (_s_store_name4951).length());
                std::string _s_zip4971 = (it->second)._s_zip4971;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n{};
                memcpy(_s_zip4971_n.data(), (_s_zip4971).data(), (_s_zip4971).length());
                int32_t _c_customer_sk4975 = tbl_Filter_TD_17952307_output.getInt32(i, 0);
                int32_t _c_current_cdemo_sk4977 = tbl_Filter_TD_17952307_output.getInt32(i, 1);
                int32_t _c_current_hdemo_sk4978 = tbl_Filter_TD_17952307_output.getInt32(i, 2);
                int32_t _c_current_addr_sk4979 = tbl_Filter_TD_17952307_output.getInt32(i, 3);
                int32_t _c_first_shipto_date_sk4980 = tbl_Filter_TD_17952307_output.getInt32(i, 4);
                int32_t _c_first_sales_date_sk4981 = tbl_Filter_TD_17952307_output.getInt32(i, 5);
                tbl_JOIN_INNER_TD_16134853_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_16134853_output.setInt32(r, 1, _ss_cdemo_sk4762);
                tbl_JOIN_INNER_TD_16134853_output.setInt32(r, 2, _ss_hdemo_sk4763);
                tbl_JOIN_INNER_TD_16134853_output.setInt32(r, 3, _ss_addr_sk4764);
                tbl_JOIN_INNER_TD_16134853_output.setInt32(r, 4, _ss_promo_sk4766);
                tbl_JOIN_INNER_TD_16134853_output.setInt64(r, 5, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_16134853_output.setInt64(r, 6, _ss_list_price4770);
                tbl_JOIN_INNER_TD_16134853_output.setInt64(r, 7, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_16134853_output.setInt32(r, 8, _d_year4868);
                tbl_JOIN_INNER_TD_16134853_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_16134853_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _s_zip4971_n);
                tbl_JOIN_INNER_TD_16134853_output.setInt32(r, 11, _c_current_cdemo_sk4977);
                tbl_JOIN_INNER_TD_16134853_output.setInt32(r, 12, _c_current_hdemo_sk4978);
                tbl_JOIN_INNER_TD_16134853_output.setInt32(r, 13, _c_current_addr_sk4979);
                tbl_JOIN_INNER_TD_16134853_output.setInt32(r, 14, _c_first_shipto_date_sk4980);
                tbl_JOIN_INNER_TD_16134853_output.setInt32(r, 15, _c_first_sales_date_sk4981);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_16134853_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_16134853_key_rightMajor, SW_JOIN_INNER_TD_16134853_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_17952307_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk4975_k = tbl_Filter_TD_17952307_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_16134853_key_rightMajor keyA{_c_customer_sk4975_k};
            int32_t _c_customer_sk4975 = tbl_Filter_TD_17952307_output.getInt32(i, 0);
            int32_t _c_current_cdemo_sk4977 = tbl_Filter_TD_17952307_output.getInt32(i, 1);
            int32_t _c_current_hdemo_sk4978 = tbl_Filter_TD_17952307_output.getInt32(i, 2);
            int32_t _c_current_addr_sk4979 = tbl_Filter_TD_17952307_output.getInt32(i, 3);
            int32_t _c_first_shipto_date_sk4980 = tbl_Filter_TD_17952307_output.getInt32(i, 4);
            int32_t _c_first_sales_date_sk4981 = tbl_Filter_TD_17952307_output.getInt32(i, 5);
            SW_JOIN_INNER_TD_16134853_payload_rightMajor payloadA{_c_customer_sk4975, _c_current_cdemo_sk4977, _c_current_hdemo_sk4978, _c_current_addr_sk4979, _c_first_shipto_date_sk4980, _c_first_sales_date_sk4981};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_17330885_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_customer_sk4761_k = tbl_JOIN_INNER_TD_17330885_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_16134853_key_rightMajor{_ss_customer_sk4761_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk4975 = (it->second)._c_customer_sk4975;
                int32_t _c_current_cdemo_sk4977 = (it->second)._c_current_cdemo_sk4977;
                int32_t _c_current_hdemo_sk4978 = (it->second)._c_current_hdemo_sk4978;
                int32_t _c_current_addr_sk4979 = (it->second)._c_current_addr_sk4979;
                int32_t _c_first_shipto_date_sk4980 = (it->second)._c_first_shipto_date_sk4980;
                int32_t _c_first_sales_date_sk4981 = (it->second)._c_first_sales_date_sk4981;
                int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_17330885_output.getInt32(i, 0);
                int32_t _ss_customer_sk4761 = tbl_JOIN_INNER_TD_17330885_output.getInt32(i, 1);
                int32_t _ss_cdemo_sk4762 = tbl_JOIN_INNER_TD_17330885_output.getInt32(i, 2);
                int32_t _ss_hdemo_sk4763 = tbl_JOIN_INNER_TD_17330885_output.getInt32(i, 3);
                int32_t _ss_addr_sk4764 = tbl_JOIN_INNER_TD_17330885_output.getInt32(i, 4);
                int32_t _ss_promo_sk4766 = tbl_JOIN_INNER_TD_17330885_output.getInt32(i, 5);
                int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_17330885_output.getInt64(i, 6);
                int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_17330885_output.getInt64(i, 7);
                int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_17330885_output.getInt64(i, 8);
                int32_t _d_year4868 = tbl_JOIN_INNER_TD_17330885_output.getInt32(i, 9);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_17330885_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
                std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_17330885_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
                std::string _s_zip4971 = std::string(_s_zip4971_n.data());
                tbl_JOIN_INNER_TD_16134853_output.setInt32(r, 11, _c_current_cdemo_sk4977);
                tbl_JOIN_INNER_TD_16134853_output.setInt32(r, 12, _c_current_hdemo_sk4978);
                tbl_JOIN_INNER_TD_16134853_output.setInt32(r, 13, _c_current_addr_sk4979);
                tbl_JOIN_INNER_TD_16134853_output.setInt32(r, 14, _c_first_shipto_date_sk4980);
                tbl_JOIN_INNER_TD_16134853_output.setInt32(r, 15, _c_first_sales_date_sk4981);
                tbl_JOIN_INNER_TD_16134853_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_16134853_output.setInt32(r, 1, _ss_cdemo_sk4762);
                tbl_JOIN_INNER_TD_16134853_output.setInt32(r, 2, _ss_hdemo_sk4763);
                tbl_JOIN_INNER_TD_16134853_output.setInt32(r, 3, _ss_addr_sk4764);
                tbl_JOIN_INNER_TD_16134853_output.setInt32(r, 4, _ss_promo_sk4766);
                tbl_JOIN_INNER_TD_16134853_output.setInt64(r, 5, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_16134853_output.setInt64(r, 6, _ss_list_price4770);
                tbl_JOIN_INNER_TD_16134853_output.setInt64(r, 7, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_16134853_output.setInt32(r, 8, _d_year4868);
                tbl_JOIN_INNER_TD_16134853_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_16134853_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _s_zip4971_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_16134853_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_16134853_output #Row: " << tbl_JOIN_INNER_TD_16134853_output.getNumRow() << std::endl;
}

void SW_Filter_TD_16426838(Table &tbl_SerializeFromObject_TD_1799058_input, Table &tbl_Filter_TD_16426838_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(d_date_sk#3570))
    // Input: ListBuffer(d_date_sk#3570, d_year#3576)
    // Output: ListBuffer(d_date_sk#3570, d_year#3576)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1799058_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date_sk3570 = tbl_SerializeFromObject_TD_1799058_input.getInt32(i, 0);
        if (_d_date_sk3570!= 0) {
            int32_t _d_date_sk3570_t = tbl_SerializeFromObject_TD_1799058_input.getInt32(i, 0);
            tbl_Filter_TD_16426838_output.setInt32(r, 0, _d_date_sk3570_t);
            int32_t _d_year3576_t = tbl_SerializeFromObject_TD_1799058_input.getInt32(i, 1);
            tbl_Filter_TD_16426838_output.setInt32(r, 1, _d_year3576_t);
            r++;
        }
    }
    tbl_Filter_TD_16426838_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_16426838_output #Row: " << tbl_Filter_TD_16426838_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_16633534_key_leftMajor {
    int32_t _ss_customer_sk1209;
    bool operator==(const SW_JOIN_INNER_TD_16633534_key_leftMajor& other) const {
        return ((_ss_customer_sk1209 == other._ss_customer_sk1209));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_16633534_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_16633534_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_customer_sk1209));
    }
};
}
struct SW_JOIN_INNER_TD_16633534_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int32_t _ss_customer_sk1209;
    int32_t _ss_cdemo_sk1210;
    int32_t _ss_hdemo_sk1211;
    int32_t _ss_addr_sk1212;
    int32_t _ss_promo_sk1214;
    int64_t _ss_wholesale_cost1217;
    int64_t _ss_list_price1218;
    int64_t _ss_coupon_amt1225;
    int32_t _d_year126;
    std::string _s_store_name383;
    std::string _s_zip403;
};
struct SW_JOIN_INNER_TD_16633534_key_rightMajor {
    int32_t _c_customer_sk0;
    bool operator==(const SW_JOIN_INNER_TD_16633534_key_rightMajor& other) const {
        return ((_c_customer_sk0 == other._c_customer_sk0));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_16633534_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_16633534_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk0));
    }
};
}
struct SW_JOIN_INNER_TD_16633534_payload_rightMajor {
    int32_t _c_customer_sk0;
    int32_t _c_current_cdemo_sk2;
    int32_t _c_current_hdemo_sk3;
    int32_t _c_current_addr_sk4;
    int32_t _c_first_shipto_date_sk5;
    int32_t _c_first_sales_date_sk6;
};
void SW_JOIN_INNER_TD_16633534(Table &tbl_JOIN_INNER_TD_17102777_output, Table &tbl_Filter_TD_17180494_output, Table &tbl_JOIN_INNER_TD_16633534_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_customer_sk#1209 = c_customer_sk#0))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_customer_sk#1209, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_promo_sk#1214, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403)
    // Right Table: ListBuffer(c_customer_sk#0, c_current_cdemo_sk#2, c_current_hdemo_sk#3, c_current_addr_sk#4, c_first_shipto_date_sk#5, c_first_sales_date_sk#6)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_promo_sk#1214, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403, c_current_cdemo_sk#2, c_current_hdemo_sk#3, c_current_addr_sk#4, c_first_shipto_date_sk#5, c_first_sales_date_sk#6)
    int left_nrow = tbl_JOIN_INNER_TD_17102777_output.getNumRow();
    int right_nrow = tbl_Filter_TD_17180494_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_16633534_key_leftMajor, SW_JOIN_INNER_TD_16633534_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_17102777_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_customer_sk1209_k = tbl_JOIN_INNER_TD_17102777_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_16633534_key_leftMajor keyA{_ss_customer_sk1209_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_17102777_output.getInt32(i, 0);
            int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_17102777_output.getInt32(i, 1);
            int32_t _ss_cdemo_sk1210 = tbl_JOIN_INNER_TD_17102777_output.getInt32(i, 2);
            int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_17102777_output.getInt32(i, 3);
            int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_17102777_output.getInt32(i, 4);
            int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_17102777_output.getInt32(i, 5);
            int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_17102777_output.getInt64(i, 6);
            int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_17102777_output.getInt64(i, 7);
            int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_17102777_output.getInt64(i, 8);
            int32_t _d_year126 = tbl_JOIN_INNER_TD_17102777_output.getInt32(i, 9);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_17102777_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            std::string _s_store_name383 = std::string(_s_store_name383_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_17102777_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
            std::string _s_zip403 = std::string(_s_zip403_n.data());
            SW_JOIN_INNER_TD_16633534_payload_leftMajor payloadA{_ss_item_sk1208, _ss_customer_sk1209, _ss_cdemo_sk1210, _ss_hdemo_sk1211, _ss_addr_sk1212, _ss_promo_sk1214, _ss_wholesale_cost1217, _ss_list_price1218, _ss_coupon_amt1225, _d_year126, _s_store_name383, _s_zip403};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_17180494_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_17180494_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_16633534_key_leftMajor{_c_customer_sk0_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                int32_t _ss_cdemo_sk1210 = (it->second)._ss_cdemo_sk1210;
                int32_t _ss_hdemo_sk1211 = (it->second)._ss_hdemo_sk1211;
                int32_t _ss_addr_sk1212 = (it->second)._ss_addr_sk1212;
                int32_t _ss_promo_sk1214 = (it->second)._ss_promo_sk1214;
                int64_t _ss_wholesale_cost1217 = (it->second)._ss_wholesale_cost1217;
                int64_t _ss_list_price1218 = (it->second)._ss_list_price1218;
                int64_t _ss_coupon_amt1225 = (it->second)._ss_coupon_amt1225;
                int32_t _d_year126 = (it->second)._d_year126;
                std::string _s_store_name383 = (it->second)._s_store_name383;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n{};
                memcpy(_s_store_name383_n.data(), (_s_store_name383).data(), (_s_store_name383).length());
                std::string _s_zip403 = (it->second)._s_zip403;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n{};
                memcpy(_s_zip403_n.data(), (_s_zip403).data(), (_s_zip403).length());
                int32_t _c_customer_sk0 = tbl_Filter_TD_17180494_output.getInt32(i, 0);
                int32_t _c_current_cdemo_sk2 = tbl_Filter_TD_17180494_output.getInt32(i, 1);
                int32_t _c_current_hdemo_sk3 = tbl_Filter_TD_17180494_output.getInt32(i, 2);
                int32_t _c_current_addr_sk4 = tbl_Filter_TD_17180494_output.getInt32(i, 3);
                int32_t _c_first_shipto_date_sk5 = tbl_Filter_TD_17180494_output.getInt32(i, 4);
                int32_t _c_first_sales_date_sk6 = tbl_Filter_TD_17180494_output.getInt32(i, 5);
                tbl_JOIN_INNER_TD_16633534_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_16633534_output.setInt32(r, 1, _ss_cdemo_sk1210);
                tbl_JOIN_INNER_TD_16633534_output.setInt32(r, 2, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_16633534_output.setInt32(r, 3, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_16633534_output.setInt32(r, 4, _ss_promo_sk1214);
                tbl_JOIN_INNER_TD_16633534_output.setInt64(r, 5, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_16633534_output.setInt64(r, 6, _ss_list_price1218);
                tbl_JOIN_INNER_TD_16633534_output.setInt64(r, 7, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_16633534_output.setInt32(r, 8, _d_year126);
                tbl_JOIN_INNER_TD_16633534_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_store_name383_n);
                tbl_JOIN_INNER_TD_16633534_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _s_zip403_n);
                tbl_JOIN_INNER_TD_16633534_output.setInt32(r, 11, _c_current_cdemo_sk2);
                tbl_JOIN_INNER_TD_16633534_output.setInt32(r, 12, _c_current_hdemo_sk3);
                tbl_JOIN_INNER_TD_16633534_output.setInt32(r, 13, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_16633534_output.setInt32(r, 14, _c_first_shipto_date_sk5);
                tbl_JOIN_INNER_TD_16633534_output.setInt32(r, 15, _c_first_sales_date_sk6);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_16633534_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_16633534_key_rightMajor, SW_JOIN_INNER_TD_16633534_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_17180494_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_17180494_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_16633534_key_rightMajor keyA{_c_customer_sk0_k};
            int32_t _c_customer_sk0 = tbl_Filter_TD_17180494_output.getInt32(i, 0);
            int32_t _c_current_cdemo_sk2 = tbl_Filter_TD_17180494_output.getInt32(i, 1);
            int32_t _c_current_hdemo_sk3 = tbl_Filter_TD_17180494_output.getInt32(i, 2);
            int32_t _c_current_addr_sk4 = tbl_Filter_TD_17180494_output.getInt32(i, 3);
            int32_t _c_first_shipto_date_sk5 = tbl_Filter_TD_17180494_output.getInt32(i, 4);
            int32_t _c_first_sales_date_sk6 = tbl_Filter_TD_17180494_output.getInt32(i, 5);
            SW_JOIN_INNER_TD_16633534_payload_rightMajor payloadA{_c_customer_sk0, _c_current_cdemo_sk2, _c_current_hdemo_sk3, _c_current_addr_sk4, _c_first_shipto_date_sk5, _c_first_sales_date_sk6};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_17102777_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_customer_sk1209_k = tbl_JOIN_INNER_TD_17102777_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_16633534_key_rightMajor{_ss_customer_sk1209_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk0 = (it->second)._c_customer_sk0;
                int32_t _c_current_cdemo_sk2 = (it->second)._c_current_cdemo_sk2;
                int32_t _c_current_hdemo_sk3 = (it->second)._c_current_hdemo_sk3;
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                int32_t _c_first_shipto_date_sk5 = (it->second)._c_first_shipto_date_sk5;
                int32_t _c_first_sales_date_sk6 = (it->second)._c_first_sales_date_sk6;
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_17102777_output.getInt32(i, 0);
                int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_17102777_output.getInt32(i, 1);
                int32_t _ss_cdemo_sk1210 = tbl_JOIN_INNER_TD_17102777_output.getInt32(i, 2);
                int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_17102777_output.getInt32(i, 3);
                int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_17102777_output.getInt32(i, 4);
                int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_17102777_output.getInt32(i, 5);
                int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_17102777_output.getInt64(i, 6);
                int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_17102777_output.getInt64(i, 7);
                int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_17102777_output.getInt64(i, 8);
                int32_t _d_year126 = tbl_JOIN_INNER_TD_17102777_output.getInt32(i, 9);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_17102777_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
                std::string _s_store_name383 = std::string(_s_store_name383_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_17102777_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
                std::string _s_zip403 = std::string(_s_zip403_n.data());
                tbl_JOIN_INNER_TD_16633534_output.setInt32(r, 11, _c_current_cdemo_sk2);
                tbl_JOIN_INNER_TD_16633534_output.setInt32(r, 12, _c_current_hdemo_sk3);
                tbl_JOIN_INNER_TD_16633534_output.setInt32(r, 13, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_16633534_output.setInt32(r, 14, _c_first_shipto_date_sk5);
                tbl_JOIN_INNER_TD_16633534_output.setInt32(r, 15, _c_first_sales_date_sk6);
                tbl_JOIN_INNER_TD_16633534_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_16633534_output.setInt32(r, 1, _ss_cdemo_sk1210);
                tbl_JOIN_INNER_TD_16633534_output.setInt32(r, 2, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_16633534_output.setInt32(r, 3, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_16633534_output.setInt32(r, 4, _ss_promo_sk1214);
                tbl_JOIN_INNER_TD_16633534_output.setInt64(r, 5, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_16633534_output.setInt64(r, 6, _ss_list_price1218);
                tbl_JOIN_INNER_TD_16633534_output.setInt64(r, 7, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_16633534_output.setInt32(r, 8, _d_year126);
                tbl_JOIN_INNER_TD_16633534_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_store_name383_n);
                tbl_JOIN_INNER_TD_16633534_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _s_zip403_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_16633534_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_16633534_output #Row: " << tbl_JOIN_INNER_TD_16633534_output.getNumRow() << std::endl;
}

void SW_Filter_TD_15892114(Table &tbl_SerializeFromObject_TD_16553257_input, Table &tbl_Filter_TD_15892114_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(d_date_sk#4918))
    // Input: ListBuffer(d_date_sk#4918, d_year#4924)
    // Output: ListBuffer(d_date_sk#4918, d_year#4924)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_16553257_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date_sk4918 = tbl_SerializeFromObject_TD_16553257_input.getInt32(i, 0);
        if (_d_date_sk4918!= 0) {
            int32_t _d_date_sk4918_t = tbl_SerializeFromObject_TD_16553257_input.getInt32(i, 0);
            tbl_Filter_TD_15892114_output.setInt32(r, 0, _d_date_sk4918_t);
            int32_t _d_year4924_t = tbl_SerializeFromObject_TD_16553257_input.getInt32(i, 1);
            tbl_Filter_TD_15892114_output.setInt32(r, 1, _d_year4924_t);
            r++;
        }
    }
    tbl_Filter_TD_15892114_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_15892114_output #Row: " << tbl_Filter_TD_15892114_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_15257714_key_leftMajor {
    int32_t _c_first_sales_date_sk4981;
    bool operator==(const SW_JOIN_INNER_TD_15257714_key_leftMajor& other) const {
        return ((_c_first_sales_date_sk4981 == other._c_first_sales_date_sk4981));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_15257714_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_15257714_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_first_sales_date_sk4981));
    }
};
}
struct SW_JOIN_INNER_TD_15257714_payload_leftMajor {
    int32_t _ss_item_sk4760;
    int32_t _ss_cdemo_sk4762;
    int32_t _ss_hdemo_sk4763;
    int32_t _ss_addr_sk4764;
    int32_t _ss_promo_sk4766;
    int64_t _ss_wholesale_cost4769;
    int64_t _ss_list_price4770;
    int64_t _ss_coupon_amt4777;
    int32_t _d_year4868;
    std::string _s_store_name4951;
    std::string _s_zip4971;
    int32_t _c_current_cdemo_sk4977;
    int32_t _c_current_hdemo_sk4978;
    int32_t _c_current_addr_sk4979;
    int32_t _c_first_shipto_date_sk4980;
    int32_t _c_first_sales_date_sk4981;
};
struct SW_JOIN_INNER_TD_15257714_key_rightMajor {
    int32_t _d_date_sk4890;
    bool operator==(const SW_JOIN_INNER_TD_15257714_key_rightMajor& other) const {
        return ((_d_date_sk4890 == other._d_date_sk4890));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_15257714_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_15257714_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk4890));
    }
};
}
struct SW_JOIN_INNER_TD_15257714_payload_rightMajor {
    int32_t _d_date_sk4890;
    int32_t _d_year4896;
};
void SW_JOIN_INNER_TD_15257714(Table &tbl_JOIN_INNER_TD_16134853_output, Table &tbl_Filter_TD_16382357_output, Table &tbl_JOIN_INNER_TD_15257714_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((c_first_sales_date_sk#4981 = d_date_sk#4890))
    // Left Table: ListBuffer(ss_item_sk#4760, ss_cdemo_sk#4762, ss_hdemo_sk#4763, ss_addr_sk#4764, ss_promo_sk#4766, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971, c_current_cdemo_sk#4977, c_current_hdemo_sk#4978, c_current_addr_sk#4979, c_first_shipto_date_sk#4980, c_first_sales_date_sk#4981)
    // Right Table: ListBuffer(d_date_sk#4890, d_year#4896)
    // Output Table: ListBuffer(ss_item_sk#4760, ss_cdemo_sk#4762, ss_hdemo_sk#4763, ss_addr_sk#4764, ss_promo_sk#4766, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971, c_current_cdemo_sk#4977, c_current_hdemo_sk#4978, c_current_addr_sk#4979, c_first_shipto_date_sk#4980, d_year#4896)
    int left_nrow = tbl_JOIN_INNER_TD_16134853_output.getNumRow();
    int right_nrow = tbl_Filter_TD_16382357_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_15257714_key_leftMajor, SW_JOIN_INNER_TD_15257714_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_16134853_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_first_sales_date_sk4981_k = tbl_JOIN_INNER_TD_16134853_output.getInt32(i, 15);
            SW_JOIN_INNER_TD_15257714_key_leftMajor keyA{_c_first_sales_date_sk4981_k};
            int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_16134853_output.getInt32(i, 0);
            int32_t _ss_cdemo_sk4762 = tbl_JOIN_INNER_TD_16134853_output.getInt32(i, 1);
            int32_t _ss_hdemo_sk4763 = tbl_JOIN_INNER_TD_16134853_output.getInt32(i, 2);
            int32_t _ss_addr_sk4764 = tbl_JOIN_INNER_TD_16134853_output.getInt32(i, 3);
            int32_t _ss_promo_sk4766 = tbl_JOIN_INNER_TD_16134853_output.getInt32(i, 4);
            int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_16134853_output.getInt64(i, 5);
            int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_16134853_output.getInt64(i, 6);
            int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_16134853_output.getInt64(i, 7);
            int32_t _d_year4868 = tbl_JOIN_INNER_TD_16134853_output.getInt32(i, 8);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_16134853_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_16134853_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            std::string _s_zip4971 = std::string(_s_zip4971_n.data());
            int32_t _c_current_cdemo_sk4977 = tbl_JOIN_INNER_TD_16134853_output.getInt32(i, 11);
            int32_t _c_current_hdemo_sk4978 = tbl_JOIN_INNER_TD_16134853_output.getInt32(i, 12);
            int32_t _c_current_addr_sk4979 = tbl_JOIN_INNER_TD_16134853_output.getInt32(i, 13);
            int32_t _c_first_shipto_date_sk4980 = tbl_JOIN_INNER_TD_16134853_output.getInt32(i, 14);
            int32_t _c_first_sales_date_sk4981 = tbl_JOIN_INNER_TD_16134853_output.getInt32(i, 15);
            SW_JOIN_INNER_TD_15257714_payload_leftMajor payloadA{_ss_item_sk4760, _ss_cdemo_sk4762, _ss_hdemo_sk4763, _ss_addr_sk4764, _ss_promo_sk4766, _ss_wholesale_cost4769, _ss_list_price4770, _ss_coupon_amt4777, _d_year4868, _s_store_name4951, _s_zip4971, _c_current_cdemo_sk4977, _c_current_hdemo_sk4978, _c_current_addr_sk4979, _c_first_shipto_date_sk4980, _c_first_sales_date_sk4981};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_16382357_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk4890_k = tbl_Filter_TD_16382357_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_15257714_key_leftMajor{_d_date_sk4890_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk4760 = (it->second)._ss_item_sk4760;
                int32_t _ss_cdemo_sk4762 = (it->second)._ss_cdemo_sk4762;
                int32_t _ss_hdemo_sk4763 = (it->second)._ss_hdemo_sk4763;
                int32_t _ss_addr_sk4764 = (it->second)._ss_addr_sk4764;
                int32_t _ss_promo_sk4766 = (it->second)._ss_promo_sk4766;
                int64_t _ss_wholesale_cost4769 = (it->second)._ss_wholesale_cost4769;
                int64_t _ss_list_price4770 = (it->second)._ss_list_price4770;
                int64_t _ss_coupon_amt4777 = (it->second)._ss_coupon_amt4777;
                int32_t _d_year4868 = (it->second)._d_year4868;
                std::string _s_store_name4951 = (it->second)._s_store_name4951;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n{};
                memcpy(_s_store_name4951_n.data(), (_s_store_name4951).data(), (_s_store_name4951).length());
                std::string _s_zip4971 = (it->second)._s_zip4971;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n{};
                memcpy(_s_zip4971_n.data(), (_s_zip4971).data(), (_s_zip4971).length());
                int32_t _c_current_cdemo_sk4977 = (it->second)._c_current_cdemo_sk4977;
                int32_t _c_current_hdemo_sk4978 = (it->second)._c_current_hdemo_sk4978;
                int32_t _c_current_addr_sk4979 = (it->second)._c_current_addr_sk4979;
                int32_t _c_first_shipto_date_sk4980 = (it->second)._c_first_shipto_date_sk4980;
                int32_t _c_first_sales_date_sk4981 = (it->second)._c_first_sales_date_sk4981;
                int32_t _d_date_sk4890 = tbl_Filter_TD_16382357_output.getInt32(i, 0);
                int32_t _d_year4896 = tbl_Filter_TD_16382357_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_15257714_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_15257714_output.setInt32(r, 1, _ss_cdemo_sk4762);
                tbl_JOIN_INNER_TD_15257714_output.setInt32(r, 2, _ss_hdemo_sk4763);
                tbl_JOIN_INNER_TD_15257714_output.setInt32(r, 3, _ss_addr_sk4764);
                tbl_JOIN_INNER_TD_15257714_output.setInt32(r, 4, _ss_promo_sk4766);
                tbl_JOIN_INNER_TD_15257714_output.setInt64(r, 5, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_15257714_output.setInt64(r, 6, _ss_list_price4770);
                tbl_JOIN_INNER_TD_15257714_output.setInt64(r, 7, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_15257714_output.setInt32(r, 8, _d_year4868);
                tbl_JOIN_INNER_TD_15257714_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_15257714_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _s_zip4971_n);
                tbl_JOIN_INNER_TD_15257714_output.setInt32(r, 11, _c_current_cdemo_sk4977);
                tbl_JOIN_INNER_TD_15257714_output.setInt32(r, 12, _c_current_hdemo_sk4978);
                tbl_JOIN_INNER_TD_15257714_output.setInt32(r, 13, _c_current_addr_sk4979);
                tbl_JOIN_INNER_TD_15257714_output.setInt32(r, 14, _c_first_shipto_date_sk4980);
                tbl_JOIN_INNER_TD_15257714_output.setInt32(r, 15, _d_year4896);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_15257714_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_15257714_key_rightMajor, SW_JOIN_INNER_TD_15257714_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_16382357_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk4890_k = tbl_Filter_TD_16382357_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_15257714_key_rightMajor keyA{_d_date_sk4890_k};
            int32_t _d_date_sk4890 = tbl_Filter_TD_16382357_output.getInt32(i, 0);
            int32_t _d_year4896 = tbl_Filter_TD_16382357_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_15257714_payload_rightMajor payloadA{_d_date_sk4890, _d_year4896};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_16134853_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_first_sales_date_sk4981_k = tbl_JOIN_INNER_TD_16134853_output.getInt32(i, 15);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_15257714_key_rightMajor{_c_first_sales_date_sk4981_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk4890 = (it->second)._d_date_sk4890;
                int32_t _d_year4896 = (it->second)._d_year4896;
                int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_16134853_output.getInt32(i, 0);
                int32_t _ss_cdemo_sk4762 = tbl_JOIN_INNER_TD_16134853_output.getInt32(i, 1);
                int32_t _ss_hdemo_sk4763 = tbl_JOIN_INNER_TD_16134853_output.getInt32(i, 2);
                int32_t _ss_addr_sk4764 = tbl_JOIN_INNER_TD_16134853_output.getInt32(i, 3);
                int32_t _ss_promo_sk4766 = tbl_JOIN_INNER_TD_16134853_output.getInt32(i, 4);
                int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_16134853_output.getInt64(i, 5);
                int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_16134853_output.getInt64(i, 6);
                int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_16134853_output.getInt64(i, 7);
                int32_t _d_year4868 = tbl_JOIN_INNER_TD_16134853_output.getInt32(i, 8);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_16134853_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
                std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_16134853_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
                std::string _s_zip4971 = std::string(_s_zip4971_n.data());
                int32_t _c_current_cdemo_sk4977 = tbl_JOIN_INNER_TD_16134853_output.getInt32(i, 11);
                int32_t _c_current_hdemo_sk4978 = tbl_JOIN_INNER_TD_16134853_output.getInt32(i, 12);
                int32_t _c_current_addr_sk4979 = tbl_JOIN_INNER_TD_16134853_output.getInt32(i, 13);
                int32_t _c_first_shipto_date_sk4980 = tbl_JOIN_INNER_TD_16134853_output.getInt32(i, 14);
                int32_t _c_first_sales_date_sk4981 = tbl_JOIN_INNER_TD_16134853_output.getInt32(i, 15);
                tbl_JOIN_INNER_TD_15257714_output.setInt32(r, 15, _d_year4896);
                tbl_JOIN_INNER_TD_15257714_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_15257714_output.setInt32(r, 1, _ss_cdemo_sk4762);
                tbl_JOIN_INNER_TD_15257714_output.setInt32(r, 2, _ss_hdemo_sk4763);
                tbl_JOIN_INNER_TD_15257714_output.setInt32(r, 3, _ss_addr_sk4764);
                tbl_JOIN_INNER_TD_15257714_output.setInt32(r, 4, _ss_promo_sk4766);
                tbl_JOIN_INNER_TD_15257714_output.setInt64(r, 5, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_15257714_output.setInt64(r, 6, _ss_list_price4770);
                tbl_JOIN_INNER_TD_15257714_output.setInt64(r, 7, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_15257714_output.setInt32(r, 8, _d_year4868);
                tbl_JOIN_INNER_TD_15257714_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_15257714_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _s_zip4971_n);
                tbl_JOIN_INNER_TD_15257714_output.setInt32(r, 11, _c_current_cdemo_sk4977);
                tbl_JOIN_INNER_TD_15257714_output.setInt32(r, 12, _c_current_hdemo_sk4978);
                tbl_JOIN_INNER_TD_15257714_output.setInt32(r, 13, _c_current_addr_sk4979);
                tbl_JOIN_INNER_TD_15257714_output.setInt32(r, 14, _c_first_shipto_date_sk4980);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_15257714_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_15257714_output #Row: " << tbl_JOIN_INNER_TD_15257714_output.getNumRow() << std::endl;
}

void SW_Filter_TD_15770298(Table &tbl_SerializeFromObject_TD_1695065_input, Table &tbl_Filter_TD_15770298_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(d_date_sk#3598))
    // Input: ListBuffer(d_date_sk#3598, d_year#3604)
    // Output: ListBuffer(d_date_sk#3598, d_year#3604)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1695065_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date_sk3598 = tbl_SerializeFromObject_TD_1695065_input.getInt32(i, 0);
        if (_d_date_sk3598!= 0) {
            int32_t _d_date_sk3598_t = tbl_SerializeFromObject_TD_1695065_input.getInt32(i, 0);
            tbl_Filter_TD_15770298_output.setInt32(r, 0, _d_date_sk3598_t);
            int32_t _d_year3604_t = tbl_SerializeFromObject_TD_1695065_input.getInt32(i, 1);
            tbl_Filter_TD_15770298_output.setInt32(r, 1, _d_year3604_t);
            r++;
        }
    }
    tbl_Filter_TD_15770298_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_15770298_output #Row: " << tbl_Filter_TD_15770298_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_15907739_key_leftMajor {
    int32_t _c_first_sales_date_sk6;
    bool operator==(const SW_JOIN_INNER_TD_15907739_key_leftMajor& other) const {
        return ((_c_first_sales_date_sk6 == other._c_first_sales_date_sk6));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_15907739_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_15907739_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_first_sales_date_sk6));
    }
};
}
struct SW_JOIN_INNER_TD_15907739_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int32_t _ss_cdemo_sk1210;
    int32_t _ss_hdemo_sk1211;
    int32_t _ss_addr_sk1212;
    int32_t _ss_promo_sk1214;
    int64_t _ss_wholesale_cost1217;
    int64_t _ss_list_price1218;
    int64_t _ss_coupon_amt1225;
    int32_t _d_year126;
    std::string _s_store_name383;
    std::string _s_zip403;
    int32_t _c_current_cdemo_sk2;
    int32_t _c_current_hdemo_sk3;
    int32_t _c_current_addr_sk4;
    int32_t _c_first_shipto_date_sk5;
    int32_t _c_first_sales_date_sk6;
};
struct SW_JOIN_INNER_TD_15907739_key_rightMajor {
    int32_t _d_date_sk3570;
    bool operator==(const SW_JOIN_INNER_TD_15907739_key_rightMajor& other) const {
        return ((_d_date_sk3570 == other._d_date_sk3570));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_15907739_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_15907739_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk3570));
    }
};
}
struct SW_JOIN_INNER_TD_15907739_payload_rightMajor {
    int32_t _d_date_sk3570;
    int32_t _d_year3576;
};
void SW_JOIN_INNER_TD_15907739(Table &tbl_JOIN_INNER_TD_16633534_output, Table &tbl_Filter_TD_16426838_output, Table &tbl_JOIN_INNER_TD_15907739_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((c_first_sales_date_sk#6 = d_date_sk#3570))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_promo_sk#1214, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403, c_current_cdemo_sk#2, c_current_hdemo_sk#3, c_current_addr_sk#4, c_first_shipto_date_sk#5, c_first_sales_date_sk#6)
    // Right Table: ListBuffer(d_date_sk#3570, d_year#3576)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_promo_sk#1214, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403, c_current_cdemo_sk#2, c_current_hdemo_sk#3, c_current_addr_sk#4, c_first_shipto_date_sk#5, d_year#3576)
    int left_nrow = tbl_JOIN_INNER_TD_16633534_output.getNumRow();
    int right_nrow = tbl_Filter_TD_16426838_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_15907739_key_leftMajor, SW_JOIN_INNER_TD_15907739_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_16633534_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_first_sales_date_sk6_k = tbl_JOIN_INNER_TD_16633534_output.getInt32(i, 15);
            SW_JOIN_INNER_TD_15907739_key_leftMajor keyA{_c_first_sales_date_sk6_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_16633534_output.getInt32(i, 0);
            int32_t _ss_cdemo_sk1210 = tbl_JOIN_INNER_TD_16633534_output.getInt32(i, 1);
            int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_16633534_output.getInt32(i, 2);
            int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_16633534_output.getInt32(i, 3);
            int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_16633534_output.getInt32(i, 4);
            int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_16633534_output.getInt64(i, 5);
            int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_16633534_output.getInt64(i, 6);
            int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_16633534_output.getInt64(i, 7);
            int32_t _d_year126 = tbl_JOIN_INNER_TD_16633534_output.getInt32(i, 8);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_16633534_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            std::string _s_store_name383 = std::string(_s_store_name383_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_16633534_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            std::string _s_zip403 = std::string(_s_zip403_n.data());
            int32_t _c_current_cdemo_sk2 = tbl_JOIN_INNER_TD_16633534_output.getInt32(i, 11);
            int32_t _c_current_hdemo_sk3 = tbl_JOIN_INNER_TD_16633534_output.getInt32(i, 12);
            int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_16633534_output.getInt32(i, 13);
            int32_t _c_first_shipto_date_sk5 = tbl_JOIN_INNER_TD_16633534_output.getInt32(i, 14);
            int32_t _c_first_sales_date_sk6 = tbl_JOIN_INNER_TD_16633534_output.getInt32(i, 15);
            SW_JOIN_INNER_TD_15907739_payload_leftMajor payloadA{_ss_item_sk1208, _ss_cdemo_sk1210, _ss_hdemo_sk1211, _ss_addr_sk1212, _ss_promo_sk1214, _ss_wholesale_cost1217, _ss_list_price1218, _ss_coupon_amt1225, _d_year126, _s_store_name383, _s_zip403, _c_current_cdemo_sk2, _c_current_hdemo_sk3, _c_current_addr_sk4, _c_first_shipto_date_sk5, _c_first_sales_date_sk6};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_16426838_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk3570_k = tbl_Filter_TD_16426838_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_15907739_key_leftMajor{_d_date_sk3570_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_cdemo_sk1210 = (it->second)._ss_cdemo_sk1210;
                int32_t _ss_hdemo_sk1211 = (it->second)._ss_hdemo_sk1211;
                int32_t _ss_addr_sk1212 = (it->second)._ss_addr_sk1212;
                int32_t _ss_promo_sk1214 = (it->second)._ss_promo_sk1214;
                int64_t _ss_wholesale_cost1217 = (it->second)._ss_wholesale_cost1217;
                int64_t _ss_list_price1218 = (it->second)._ss_list_price1218;
                int64_t _ss_coupon_amt1225 = (it->second)._ss_coupon_amt1225;
                int32_t _d_year126 = (it->second)._d_year126;
                std::string _s_store_name383 = (it->second)._s_store_name383;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n{};
                memcpy(_s_store_name383_n.data(), (_s_store_name383).data(), (_s_store_name383).length());
                std::string _s_zip403 = (it->second)._s_zip403;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n{};
                memcpy(_s_zip403_n.data(), (_s_zip403).data(), (_s_zip403).length());
                int32_t _c_current_cdemo_sk2 = (it->second)._c_current_cdemo_sk2;
                int32_t _c_current_hdemo_sk3 = (it->second)._c_current_hdemo_sk3;
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                int32_t _c_first_shipto_date_sk5 = (it->second)._c_first_shipto_date_sk5;
                int32_t _c_first_sales_date_sk6 = (it->second)._c_first_sales_date_sk6;
                int32_t _d_date_sk3570 = tbl_Filter_TD_16426838_output.getInt32(i, 0);
                int32_t _d_year3576 = tbl_Filter_TD_16426838_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_15907739_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_15907739_output.setInt32(r, 1, _ss_cdemo_sk1210);
                tbl_JOIN_INNER_TD_15907739_output.setInt32(r, 2, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_15907739_output.setInt32(r, 3, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_15907739_output.setInt32(r, 4, _ss_promo_sk1214);
                tbl_JOIN_INNER_TD_15907739_output.setInt64(r, 5, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_15907739_output.setInt64(r, 6, _ss_list_price1218);
                tbl_JOIN_INNER_TD_15907739_output.setInt64(r, 7, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_15907739_output.setInt32(r, 8, _d_year126);
                tbl_JOIN_INNER_TD_15907739_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_store_name383_n);
                tbl_JOIN_INNER_TD_15907739_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _s_zip403_n);
                tbl_JOIN_INNER_TD_15907739_output.setInt32(r, 11, _c_current_cdemo_sk2);
                tbl_JOIN_INNER_TD_15907739_output.setInt32(r, 12, _c_current_hdemo_sk3);
                tbl_JOIN_INNER_TD_15907739_output.setInt32(r, 13, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_15907739_output.setInt32(r, 14, _c_first_shipto_date_sk5);
                tbl_JOIN_INNER_TD_15907739_output.setInt32(r, 15, _d_year3576);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_15907739_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_15907739_key_rightMajor, SW_JOIN_INNER_TD_15907739_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_16426838_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk3570_k = tbl_Filter_TD_16426838_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_15907739_key_rightMajor keyA{_d_date_sk3570_k};
            int32_t _d_date_sk3570 = tbl_Filter_TD_16426838_output.getInt32(i, 0);
            int32_t _d_year3576 = tbl_Filter_TD_16426838_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_15907739_payload_rightMajor payloadA{_d_date_sk3570, _d_year3576};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_16633534_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_first_sales_date_sk6_k = tbl_JOIN_INNER_TD_16633534_output.getInt32(i, 15);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_15907739_key_rightMajor{_c_first_sales_date_sk6_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk3570 = (it->second)._d_date_sk3570;
                int32_t _d_year3576 = (it->second)._d_year3576;
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_16633534_output.getInt32(i, 0);
                int32_t _ss_cdemo_sk1210 = tbl_JOIN_INNER_TD_16633534_output.getInt32(i, 1);
                int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_16633534_output.getInt32(i, 2);
                int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_16633534_output.getInt32(i, 3);
                int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_16633534_output.getInt32(i, 4);
                int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_16633534_output.getInt64(i, 5);
                int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_16633534_output.getInt64(i, 6);
                int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_16633534_output.getInt64(i, 7);
                int32_t _d_year126 = tbl_JOIN_INNER_TD_16633534_output.getInt32(i, 8);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_16633534_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
                std::string _s_store_name383 = std::string(_s_store_name383_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_16633534_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
                std::string _s_zip403 = std::string(_s_zip403_n.data());
                int32_t _c_current_cdemo_sk2 = tbl_JOIN_INNER_TD_16633534_output.getInt32(i, 11);
                int32_t _c_current_hdemo_sk3 = tbl_JOIN_INNER_TD_16633534_output.getInt32(i, 12);
                int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_16633534_output.getInt32(i, 13);
                int32_t _c_first_shipto_date_sk5 = tbl_JOIN_INNER_TD_16633534_output.getInt32(i, 14);
                int32_t _c_first_sales_date_sk6 = tbl_JOIN_INNER_TD_16633534_output.getInt32(i, 15);
                tbl_JOIN_INNER_TD_15907739_output.setInt32(r, 15, _d_year3576);
                tbl_JOIN_INNER_TD_15907739_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_15907739_output.setInt32(r, 1, _ss_cdemo_sk1210);
                tbl_JOIN_INNER_TD_15907739_output.setInt32(r, 2, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_15907739_output.setInt32(r, 3, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_15907739_output.setInt32(r, 4, _ss_promo_sk1214);
                tbl_JOIN_INNER_TD_15907739_output.setInt64(r, 5, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_15907739_output.setInt64(r, 6, _ss_list_price1218);
                tbl_JOIN_INNER_TD_15907739_output.setInt64(r, 7, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_15907739_output.setInt32(r, 8, _d_year126);
                tbl_JOIN_INNER_TD_15907739_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_store_name383_n);
                tbl_JOIN_INNER_TD_15907739_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _s_zip403_n);
                tbl_JOIN_INNER_TD_15907739_output.setInt32(r, 11, _c_current_cdemo_sk2);
                tbl_JOIN_INNER_TD_15907739_output.setInt32(r, 12, _c_current_hdemo_sk3);
                tbl_JOIN_INNER_TD_15907739_output.setInt32(r, 13, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_15907739_output.setInt32(r, 14, _c_first_shipto_date_sk5);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_15907739_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_15907739_output #Row: " << tbl_JOIN_INNER_TD_15907739_output.getNumRow() << std::endl;
}

void SW_Filter_TD_14721747(Table &tbl_SerializeFromObject_TD_15202776_input, Table &tbl_Filter_TD_14721747_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cd_demo_sk#4993) AND isnotnull(cd_marital_status#4995)))
    // Input: ListBuffer(cd_demo_sk#4993, cd_marital_status#4995)
    // Output: ListBuffer(cd_demo_sk#4993, cd_marital_status#4995)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_15202776_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cd_demo_sk4993 = tbl_SerializeFromObject_TD_15202776_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status4995 = tbl_SerializeFromObject_TD_15202776_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_cd_demo_sk4993!= 0) && _cd_marital_status4995.data() != "NULL") {
            int32_t _cd_demo_sk4993_t = tbl_SerializeFromObject_TD_15202776_input.getInt32(i, 0);
            tbl_Filter_TD_14721747_output.setInt32(r, 0, _cd_demo_sk4993_t);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status4995_t = tbl_SerializeFromObject_TD_15202776_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_14721747_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cd_marital_status4995_t);
            r++;
        }
    }
    tbl_Filter_TD_14721747_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_14721747_output #Row: " << tbl_Filter_TD_14721747_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_14747919_key_leftMajor {
    int32_t _c_first_shipto_date_sk4980;
    bool operator==(const SW_JOIN_INNER_TD_14747919_key_leftMajor& other) const {
        return ((_c_first_shipto_date_sk4980 == other._c_first_shipto_date_sk4980));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_14747919_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_14747919_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_first_shipto_date_sk4980));
    }
};
}
struct SW_JOIN_INNER_TD_14747919_payload_leftMajor {
    int32_t _ss_item_sk4760;
    int32_t _ss_cdemo_sk4762;
    int32_t _ss_hdemo_sk4763;
    int32_t _ss_addr_sk4764;
    int32_t _ss_promo_sk4766;
    int64_t _ss_wholesale_cost4769;
    int64_t _ss_list_price4770;
    int64_t _ss_coupon_amt4777;
    int32_t _d_year4868;
    std::string _s_store_name4951;
    std::string _s_zip4971;
    int32_t _c_current_cdemo_sk4977;
    int32_t _c_current_hdemo_sk4978;
    int32_t _c_current_addr_sk4979;
    int32_t _c_first_shipto_date_sk4980;
    int32_t _d_year4896;
};
struct SW_JOIN_INNER_TD_14747919_key_rightMajor {
    int32_t _d_date_sk4918;
    bool operator==(const SW_JOIN_INNER_TD_14747919_key_rightMajor& other) const {
        return ((_d_date_sk4918 == other._d_date_sk4918));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_14747919_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_14747919_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk4918));
    }
};
}
struct SW_JOIN_INNER_TD_14747919_payload_rightMajor {
    int32_t _d_date_sk4918;
    int32_t _d_year4924;
};
void SW_JOIN_INNER_TD_14747919(Table &tbl_JOIN_INNER_TD_15257714_output, Table &tbl_Filter_TD_15892114_output, Table &tbl_JOIN_INNER_TD_14747919_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((c_first_shipto_date_sk#4980 = d_date_sk#4918))
    // Left Table: ListBuffer(ss_item_sk#4760, ss_cdemo_sk#4762, ss_hdemo_sk#4763, ss_addr_sk#4764, ss_promo_sk#4766, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971, c_current_cdemo_sk#4977, c_current_hdemo_sk#4978, c_current_addr_sk#4979, c_first_shipto_date_sk#4980, d_year#4896)
    // Right Table: ListBuffer(d_date_sk#4918, d_year#4924)
    // Output Table: ListBuffer(ss_item_sk#4760, ss_cdemo_sk#4762, ss_hdemo_sk#4763, ss_addr_sk#4764, ss_promo_sk#4766, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971, c_current_cdemo_sk#4977, c_current_hdemo_sk#4978, c_current_addr_sk#4979, d_year#4896, d_year#4924)
    int left_nrow = tbl_JOIN_INNER_TD_15257714_output.getNumRow();
    int right_nrow = tbl_Filter_TD_15892114_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_14747919_key_leftMajor, SW_JOIN_INNER_TD_14747919_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_15257714_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_first_shipto_date_sk4980_k = tbl_JOIN_INNER_TD_15257714_output.getInt32(i, 14);
            SW_JOIN_INNER_TD_14747919_key_leftMajor keyA{_c_first_shipto_date_sk4980_k};
            int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_15257714_output.getInt32(i, 0);
            int32_t _ss_cdemo_sk4762 = tbl_JOIN_INNER_TD_15257714_output.getInt32(i, 1);
            int32_t _ss_hdemo_sk4763 = tbl_JOIN_INNER_TD_15257714_output.getInt32(i, 2);
            int32_t _ss_addr_sk4764 = tbl_JOIN_INNER_TD_15257714_output.getInt32(i, 3);
            int32_t _ss_promo_sk4766 = tbl_JOIN_INNER_TD_15257714_output.getInt32(i, 4);
            int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_15257714_output.getInt64(i, 5);
            int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_15257714_output.getInt64(i, 6);
            int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_15257714_output.getInt64(i, 7);
            int32_t _d_year4868 = tbl_JOIN_INNER_TD_15257714_output.getInt32(i, 8);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_15257714_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_15257714_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            std::string _s_zip4971 = std::string(_s_zip4971_n.data());
            int32_t _c_current_cdemo_sk4977 = tbl_JOIN_INNER_TD_15257714_output.getInt32(i, 11);
            int32_t _c_current_hdemo_sk4978 = tbl_JOIN_INNER_TD_15257714_output.getInt32(i, 12);
            int32_t _c_current_addr_sk4979 = tbl_JOIN_INNER_TD_15257714_output.getInt32(i, 13);
            int32_t _c_first_shipto_date_sk4980 = tbl_JOIN_INNER_TD_15257714_output.getInt32(i, 14);
            int32_t _d_year4896 = tbl_JOIN_INNER_TD_15257714_output.getInt32(i, 15);
            SW_JOIN_INNER_TD_14747919_payload_leftMajor payloadA{_ss_item_sk4760, _ss_cdemo_sk4762, _ss_hdemo_sk4763, _ss_addr_sk4764, _ss_promo_sk4766, _ss_wholesale_cost4769, _ss_list_price4770, _ss_coupon_amt4777, _d_year4868, _s_store_name4951, _s_zip4971, _c_current_cdemo_sk4977, _c_current_hdemo_sk4978, _c_current_addr_sk4979, _c_first_shipto_date_sk4980, _d_year4896};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_15892114_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk4918_k = tbl_Filter_TD_15892114_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_14747919_key_leftMajor{_d_date_sk4918_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk4760 = (it->second)._ss_item_sk4760;
                int32_t _ss_cdemo_sk4762 = (it->second)._ss_cdemo_sk4762;
                int32_t _ss_hdemo_sk4763 = (it->second)._ss_hdemo_sk4763;
                int32_t _ss_addr_sk4764 = (it->second)._ss_addr_sk4764;
                int32_t _ss_promo_sk4766 = (it->second)._ss_promo_sk4766;
                int64_t _ss_wholesale_cost4769 = (it->second)._ss_wholesale_cost4769;
                int64_t _ss_list_price4770 = (it->second)._ss_list_price4770;
                int64_t _ss_coupon_amt4777 = (it->second)._ss_coupon_amt4777;
                int32_t _d_year4868 = (it->second)._d_year4868;
                std::string _s_store_name4951 = (it->second)._s_store_name4951;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n{};
                memcpy(_s_store_name4951_n.data(), (_s_store_name4951).data(), (_s_store_name4951).length());
                std::string _s_zip4971 = (it->second)._s_zip4971;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n{};
                memcpy(_s_zip4971_n.data(), (_s_zip4971).data(), (_s_zip4971).length());
                int32_t _c_current_cdemo_sk4977 = (it->second)._c_current_cdemo_sk4977;
                int32_t _c_current_hdemo_sk4978 = (it->second)._c_current_hdemo_sk4978;
                int32_t _c_current_addr_sk4979 = (it->second)._c_current_addr_sk4979;
                int32_t _c_first_shipto_date_sk4980 = (it->second)._c_first_shipto_date_sk4980;
                int32_t _d_year4896 = (it->second)._d_year4896;
                int32_t _d_date_sk4918 = tbl_Filter_TD_15892114_output.getInt32(i, 0);
                int32_t _d_year4924 = tbl_Filter_TD_15892114_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_14747919_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_14747919_output.setInt32(r, 1, _ss_cdemo_sk4762);
                tbl_JOIN_INNER_TD_14747919_output.setInt32(r, 2, _ss_hdemo_sk4763);
                tbl_JOIN_INNER_TD_14747919_output.setInt32(r, 3, _ss_addr_sk4764);
                tbl_JOIN_INNER_TD_14747919_output.setInt32(r, 4, _ss_promo_sk4766);
                tbl_JOIN_INNER_TD_14747919_output.setInt64(r, 5, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_14747919_output.setInt64(r, 6, _ss_list_price4770);
                tbl_JOIN_INNER_TD_14747919_output.setInt64(r, 7, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_14747919_output.setInt32(r, 8, _d_year4868);
                tbl_JOIN_INNER_TD_14747919_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_14747919_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _s_zip4971_n);
                tbl_JOIN_INNER_TD_14747919_output.setInt32(r, 11, _c_current_cdemo_sk4977);
                tbl_JOIN_INNER_TD_14747919_output.setInt32(r, 12, _c_current_hdemo_sk4978);
                tbl_JOIN_INNER_TD_14747919_output.setInt32(r, 13, _c_current_addr_sk4979);
                tbl_JOIN_INNER_TD_14747919_output.setInt32(r, 14, _d_year4896);
                tbl_JOIN_INNER_TD_14747919_output.setInt32(r, 15, _d_year4924);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_14747919_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_14747919_key_rightMajor, SW_JOIN_INNER_TD_14747919_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_15892114_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk4918_k = tbl_Filter_TD_15892114_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_14747919_key_rightMajor keyA{_d_date_sk4918_k};
            int32_t _d_date_sk4918 = tbl_Filter_TD_15892114_output.getInt32(i, 0);
            int32_t _d_year4924 = tbl_Filter_TD_15892114_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_14747919_payload_rightMajor payloadA{_d_date_sk4918, _d_year4924};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_15257714_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_first_shipto_date_sk4980_k = tbl_JOIN_INNER_TD_15257714_output.getInt32(i, 14);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_14747919_key_rightMajor{_c_first_shipto_date_sk4980_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk4918 = (it->second)._d_date_sk4918;
                int32_t _d_year4924 = (it->second)._d_year4924;
                int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_15257714_output.getInt32(i, 0);
                int32_t _ss_cdemo_sk4762 = tbl_JOIN_INNER_TD_15257714_output.getInt32(i, 1);
                int32_t _ss_hdemo_sk4763 = tbl_JOIN_INNER_TD_15257714_output.getInt32(i, 2);
                int32_t _ss_addr_sk4764 = tbl_JOIN_INNER_TD_15257714_output.getInt32(i, 3);
                int32_t _ss_promo_sk4766 = tbl_JOIN_INNER_TD_15257714_output.getInt32(i, 4);
                int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_15257714_output.getInt64(i, 5);
                int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_15257714_output.getInt64(i, 6);
                int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_15257714_output.getInt64(i, 7);
                int32_t _d_year4868 = tbl_JOIN_INNER_TD_15257714_output.getInt32(i, 8);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_15257714_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
                std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_15257714_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
                std::string _s_zip4971 = std::string(_s_zip4971_n.data());
                int32_t _c_current_cdemo_sk4977 = tbl_JOIN_INNER_TD_15257714_output.getInt32(i, 11);
                int32_t _c_current_hdemo_sk4978 = tbl_JOIN_INNER_TD_15257714_output.getInt32(i, 12);
                int32_t _c_current_addr_sk4979 = tbl_JOIN_INNER_TD_15257714_output.getInt32(i, 13);
                int32_t _c_first_shipto_date_sk4980 = tbl_JOIN_INNER_TD_15257714_output.getInt32(i, 14);
                int32_t _d_year4896 = tbl_JOIN_INNER_TD_15257714_output.getInt32(i, 15);
                tbl_JOIN_INNER_TD_14747919_output.setInt32(r, 15, _d_year4924);
                tbl_JOIN_INNER_TD_14747919_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_14747919_output.setInt32(r, 1, _ss_cdemo_sk4762);
                tbl_JOIN_INNER_TD_14747919_output.setInt32(r, 2, _ss_hdemo_sk4763);
                tbl_JOIN_INNER_TD_14747919_output.setInt32(r, 3, _ss_addr_sk4764);
                tbl_JOIN_INNER_TD_14747919_output.setInt32(r, 4, _ss_promo_sk4766);
                tbl_JOIN_INNER_TD_14747919_output.setInt64(r, 5, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_14747919_output.setInt64(r, 6, _ss_list_price4770);
                tbl_JOIN_INNER_TD_14747919_output.setInt64(r, 7, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_14747919_output.setInt32(r, 8, _d_year4868);
                tbl_JOIN_INNER_TD_14747919_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_14747919_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _s_zip4971_n);
                tbl_JOIN_INNER_TD_14747919_output.setInt32(r, 11, _c_current_cdemo_sk4977);
                tbl_JOIN_INNER_TD_14747919_output.setInt32(r, 12, _c_current_hdemo_sk4978);
                tbl_JOIN_INNER_TD_14747919_output.setInt32(r, 13, _c_current_addr_sk4979);
                tbl_JOIN_INNER_TD_14747919_output.setInt32(r, 14, _d_year4896);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_14747919_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_14747919_output #Row: " << tbl_JOIN_INNER_TD_14747919_output.getNumRow() << std::endl;
}

void SW_Filter_TD_14892724(Table &tbl_SerializeFromObject_TD_15734826_input, Table &tbl_Filter_TD_14892724_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cd_demo_sk#93) AND isnotnull(cd_marital_status#95)))
    // Input: ListBuffer(cd_demo_sk#93, cd_marital_status#95)
    // Output: ListBuffer(cd_demo_sk#93, cd_marital_status#95)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_15734826_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cd_demo_sk93 = tbl_SerializeFromObject_TD_15734826_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95 = tbl_SerializeFromObject_TD_15734826_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_cd_demo_sk93!= 0) && _cd_marital_status95.data() != "NULL") {
            int32_t _cd_demo_sk93_t = tbl_SerializeFromObject_TD_15734826_input.getInt32(i, 0);
            tbl_Filter_TD_14892724_output.setInt32(r, 0, _cd_demo_sk93_t);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_t = tbl_SerializeFromObject_TD_15734826_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_14892724_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cd_marital_status95_t);
            r++;
        }
    }
    tbl_Filter_TD_14892724_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_14892724_output #Row: " << tbl_Filter_TD_14892724_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_14267925_key_leftMajor {
    int32_t _c_first_shipto_date_sk5;
    bool operator==(const SW_JOIN_INNER_TD_14267925_key_leftMajor& other) const {
        return ((_c_first_shipto_date_sk5 == other._c_first_shipto_date_sk5));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_14267925_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_14267925_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_first_shipto_date_sk5));
    }
};
}
struct SW_JOIN_INNER_TD_14267925_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int32_t _ss_cdemo_sk1210;
    int32_t _ss_hdemo_sk1211;
    int32_t _ss_addr_sk1212;
    int32_t _ss_promo_sk1214;
    int64_t _ss_wholesale_cost1217;
    int64_t _ss_list_price1218;
    int64_t _ss_coupon_amt1225;
    int32_t _d_year126;
    std::string _s_store_name383;
    std::string _s_zip403;
    int32_t _c_current_cdemo_sk2;
    int32_t _c_current_hdemo_sk3;
    int32_t _c_current_addr_sk4;
    int32_t _c_first_shipto_date_sk5;
    int32_t _d_year3576;
};
struct SW_JOIN_INNER_TD_14267925_key_rightMajor {
    int32_t _d_date_sk3598;
    bool operator==(const SW_JOIN_INNER_TD_14267925_key_rightMajor& other) const {
        return ((_d_date_sk3598 == other._d_date_sk3598));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_14267925_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_14267925_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk3598));
    }
};
}
struct SW_JOIN_INNER_TD_14267925_payload_rightMajor {
    int32_t _d_date_sk3598;
    int32_t _d_year3604;
};
void SW_JOIN_INNER_TD_14267925(Table &tbl_JOIN_INNER_TD_15907739_output, Table &tbl_Filter_TD_15770298_output, Table &tbl_JOIN_INNER_TD_14267925_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((c_first_shipto_date_sk#5 = d_date_sk#3598))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_promo_sk#1214, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403, c_current_cdemo_sk#2, c_current_hdemo_sk#3, c_current_addr_sk#4, c_first_shipto_date_sk#5, d_year#3576)
    // Right Table: ListBuffer(d_date_sk#3598, d_year#3604)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_promo_sk#1214, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403, c_current_cdemo_sk#2, c_current_hdemo_sk#3, c_current_addr_sk#4, d_year#3576, d_year#3604)
    int left_nrow = tbl_JOIN_INNER_TD_15907739_output.getNumRow();
    int right_nrow = tbl_Filter_TD_15770298_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_14267925_key_leftMajor, SW_JOIN_INNER_TD_14267925_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_15907739_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_first_shipto_date_sk5_k = tbl_JOIN_INNER_TD_15907739_output.getInt32(i, 14);
            SW_JOIN_INNER_TD_14267925_key_leftMajor keyA{_c_first_shipto_date_sk5_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_15907739_output.getInt32(i, 0);
            int32_t _ss_cdemo_sk1210 = tbl_JOIN_INNER_TD_15907739_output.getInt32(i, 1);
            int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_15907739_output.getInt32(i, 2);
            int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_15907739_output.getInt32(i, 3);
            int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_15907739_output.getInt32(i, 4);
            int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_15907739_output.getInt64(i, 5);
            int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_15907739_output.getInt64(i, 6);
            int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_15907739_output.getInt64(i, 7);
            int32_t _d_year126 = tbl_JOIN_INNER_TD_15907739_output.getInt32(i, 8);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_15907739_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            std::string _s_store_name383 = std::string(_s_store_name383_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_15907739_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            std::string _s_zip403 = std::string(_s_zip403_n.data());
            int32_t _c_current_cdemo_sk2 = tbl_JOIN_INNER_TD_15907739_output.getInt32(i, 11);
            int32_t _c_current_hdemo_sk3 = tbl_JOIN_INNER_TD_15907739_output.getInt32(i, 12);
            int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_15907739_output.getInt32(i, 13);
            int32_t _c_first_shipto_date_sk5 = tbl_JOIN_INNER_TD_15907739_output.getInt32(i, 14);
            int32_t _d_year3576 = tbl_JOIN_INNER_TD_15907739_output.getInt32(i, 15);
            SW_JOIN_INNER_TD_14267925_payload_leftMajor payloadA{_ss_item_sk1208, _ss_cdemo_sk1210, _ss_hdemo_sk1211, _ss_addr_sk1212, _ss_promo_sk1214, _ss_wholesale_cost1217, _ss_list_price1218, _ss_coupon_amt1225, _d_year126, _s_store_name383, _s_zip403, _c_current_cdemo_sk2, _c_current_hdemo_sk3, _c_current_addr_sk4, _c_first_shipto_date_sk5, _d_year3576};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_15770298_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk3598_k = tbl_Filter_TD_15770298_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_14267925_key_leftMajor{_d_date_sk3598_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_cdemo_sk1210 = (it->second)._ss_cdemo_sk1210;
                int32_t _ss_hdemo_sk1211 = (it->second)._ss_hdemo_sk1211;
                int32_t _ss_addr_sk1212 = (it->second)._ss_addr_sk1212;
                int32_t _ss_promo_sk1214 = (it->second)._ss_promo_sk1214;
                int64_t _ss_wholesale_cost1217 = (it->second)._ss_wholesale_cost1217;
                int64_t _ss_list_price1218 = (it->second)._ss_list_price1218;
                int64_t _ss_coupon_amt1225 = (it->second)._ss_coupon_amt1225;
                int32_t _d_year126 = (it->second)._d_year126;
                std::string _s_store_name383 = (it->second)._s_store_name383;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n{};
                memcpy(_s_store_name383_n.data(), (_s_store_name383).data(), (_s_store_name383).length());
                std::string _s_zip403 = (it->second)._s_zip403;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n{};
                memcpy(_s_zip403_n.data(), (_s_zip403).data(), (_s_zip403).length());
                int32_t _c_current_cdemo_sk2 = (it->second)._c_current_cdemo_sk2;
                int32_t _c_current_hdemo_sk3 = (it->second)._c_current_hdemo_sk3;
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                int32_t _c_first_shipto_date_sk5 = (it->second)._c_first_shipto_date_sk5;
                int32_t _d_year3576 = (it->second)._d_year3576;
                int32_t _d_date_sk3598 = tbl_Filter_TD_15770298_output.getInt32(i, 0);
                int32_t _d_year3604 = tbl_Filter_TD_15770298_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_14267925_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_14267925_output.setInt32(r, 1, _ss_cdemo_sk1210);
                tbl_JOIN_INNER_TD_14267925_output.setInt32(r, 2, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_14267925_output.setInt32(r, 3, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_14267925_output.setInt32(r, 4, _ss_promo_sk1214);
                tbl_JOIN_INNER_TD_14267925_output.setInt64(r, 5, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_14267925_output.setInt64(r, 6, _ss_list_price1218);
                tbl_JOIN_INNER_TD_14267925_output.setInt64(r, 7, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_14267925_output.setInt32(r, 8, _d_year126);
                tbl_JOIN_INNER_TD_14267925_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_store_name383_n);
                tbl_JOIN_INNER_TD_14267925_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _s_zip403_n);
                tbl_JOIN_INNER_TD_14267925_output.setInt32(r, 11, _c_current_cdemo_sk2);
                tbl_JOIN_INNER_TD_14267925_output.setInt32(r, 12, _c_current_hdemo_sk3);
                tbl_JOIN_INNER_TD_14267925_output.setInt32(r, 13, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_14267925_output.setInt32(r, 14, _d_year3576);
                tbl_JOIN_INNER_TD_14267925_output.setInt32(r, 15, _d_year3604);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_14267925_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_14267925_key_rightMajor, SW_JOIN_INNER_TD_14267925_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_15770298_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk3598_k = tbl_Filter_TD_15770298_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_14267925_key_rightMajor keyA{_d_date_sk3598_k};
            int32_t _d_date_sk3598 = tbl_Filter_TD_15770298_output.getInt32(i, 0);
            int32_t _d_year3604 = tbl_Filter_TD_15770298_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_14267925_payload_rightMajor payloadA{_d_date_sk3598, _d_year3604};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_15907739_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_first_shipto_date_sk5_k = tbl_JOIN_INNER_TD_15907739_output.getInt32(i, 14);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_14267925_key_rightMajor{_c_first_shipto_date_sk5_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk3598 = (it->second)._d_date_sk3598;
                int32_t _d_year3604 = (it->second)._d_year3604;
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_15907739_output.getInt32(i, 0);
                int32_t _ss_cdemo_sk1210 = tbl_JOIN_INNER_TD_15907739_output.getInt32(i, 1);
                int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_15907739_output.getInt32(i, 2);
                int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_15907739_output.getInt32(i, 3);
                int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_15907739_output.getInt32(i, 4);
                int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_15907739_output.getInt64(i, 5);
                int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_15907739_output.getInt64(i, 6);
                int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_15907739_output.getInt64(i, 7);
                int32_t _d_year126 = tbl_JOIN_INNER_TD_15907739_output.getInt32(i, 8);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_15907739_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
                std::string _s_store_name383 = std::string(_s_store_name383_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_15907739_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
                std::string _s_zip403 = std::string(_s_zip403_n.data());
                int32_t _c_current_cdemo_sk2 = tbl_JOIN_INNER_TD_15907739_output.getInt32(i, 11);
                int32_t _c_current_hdemo_sk3 = tbl_JOIN_INNER_TD_15907739_output.getInt32(i, 12);
                int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_15907739_output.getInt32(i, 13);
                int32_t _c_first_shipto_date_sk5 = tbl_JOIN_INNER_TD_15907739_output.getInt32(i, 14);
                int32_t _d_year3576 = tbl_JOIN_INNER_TD_15907739_output.getInt32(i, 15);
                tbl_JOIN_INNER_TD_14267925_output.setInt32(r, 15, _d_year3604);
                tbl_JOIN_INNER_TD_14267925_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_14267925_output.setInt32(r, 1, _ss_cdemo_sk1210);
                tbl_JOIN_INNER_TD_14267925_output.setInt32(r, 2, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_14267925_output.setInt32(r, 3, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_14267925_output.setInt32(r, 4, _ss_promo_sk1214);
                tbl_JOIN_INNER_TD_14267925_output.setInt64(r, 5, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_14267925_output.setInt64(r, 6, _ss_list_price1218);
                tbl_JOIN_INNER_TD_14267925_output.setInt64(r, 7, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_14267925_output.setInt32(r, 8, _d_year126);
                tbl_JOIN_INNER_TD_14267925_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_store_name383_n);
                tbl_JOIN_INNER_TD_14267925_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _s_zip403_n);
                tbl_JOIN_INNER_TD_14267925_output.setInt32(r, 11, _c_current_cdemo_sk2);
                tbl_JOIN_INNER_TD_14267925_output.setInt32(r, 12, _c_current_hdemo_sk3);
                tbl_JOIN_INNER_TD_14267925_output.setInt32(r, 13, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_14267925_output.setInt32(r, 14, _d_year3576);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_14267925_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_14267925_output #Row: " << tbl_JOIN_INNER_TD_14267925_output.getNumRow() << std::endl;
}

void SW_Filter_TD_13655875(Table &tbl_SerializeFromObject_TD_14299454_input, Table &tbl_Filter_TD_13655875_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cd_demo_sk#5002) AND isnotnull(cd_marital_status#5004)))
    // Input: ListBuffer(cd_demo_sk#5002, cd_marital_status#5004)
    // Output: ListBuffer(cd_demo_sk#5002, cd_marital_status#5004)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_14299454_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cd_demo_sk5002 = tbl_SerializeFromObject_TD_14299454_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status5004 = tbl_SerializeFromObject_TD_14299454_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_cd_demo_sk5002!= 0) && _cd_marital_status5004.data() != "NULL") {
            int32_t _cd_demo_sk5002_t = tbl_SerializeFromObject_TD_14299454_input.getInt32(i, 0);
            tbl_Filter_TD_13655875_output.setInt32(r, 0, _cd_demo_sk5002_t);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status5004_t = tbl_SerializeFromObject_TD_14299454_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_13655875_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cd_marital_status5004_t);
            r++;
        }
    }
    tbl_Filter_TD_13655875_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_13655875_output #Row: " << tbl_Filter_TD_13655875_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_13369006_key_leftMajor {
    int32_t _ss_cdemo_sk4762;
    bool operator==(const SW_JOIN_INNER_TD_13369006_key_leftMajor& other) const {
        return ((_ss_cdemo_sk4762 == other._ss_cdemo_sk4762));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_13369006_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_13369006_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_cdemo_sk4762));
    }
};
}
struct SW_JOIN_INNER_TD_13369006_payload_leftMajor {
    int32_t _ss_item_sk4760;
    int32_t _ss_cdemo_sk4762;
    int32_t _ss_hdemo_sk4763;
    int32_t _ss_addr_sk4764;
    int32_t _ss_promo_sk4766;
    int64_t _ss_wholesale_cost4769;
    int64_t _ss_list_price4770;
    int64_t _ss_coupon_amt4777;
    int32_t _d_year4868;
    std::string _s_store_name4951;
    std::string _s_zip4971;
    int32_t _c_current_cdemo_sk4977;
    int32_t _c_current_hdemo_sk4978;
    int32_t _c_current_addr_sk4979;
    int32_t _d_year4896;
    int32_t _d_year4924;
};
struct SW_JOIN_INNER_TD_13369006_key_rightMajor {
    int32_t _cd_demo_sk4993;
    bool operator==(const SW_JOIN_INNER_TD_13369006_key_rightMajor& other) const {
        return ((_cd_demo_sk4993 == other._cd_demo_sk4993));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_13369006_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_13369006_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cd_demo_sk4993));
    }
};
}
struct SW_JOIN_INNER_TD_13369006_payload_rightMajor {
    int32_t _cd_demo_sk4993;
    std::string _cd_marital_status4995;
};
void SW_JOIN_INNER_TD_13369006(Table &tbl_JOIN_INNER_TD_14747919_output, Table &tbl_Filter_TD_14721747_output, Table &tbl_JOIN_INNER_TD_13369006_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_cdemo_sk#4762 = cd_demo_sk#4993))
    // Left Table: ListBuffer(ss_item_sk#4760, ss_cdemo_sk#4762, ss_hdemo_sk#4763, ss_addr_sk#4764, ss_promo_sk#4766, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971, c_current_cdemo_sk#4977, c_current_hdemo_sk#4978, c_current_addr_sk#4979, d_year#4896, d_year#4924)
    // Right Table: ListBuffer(cd_demo_sk#4993, cd_marital_status#4995)
    // Output Table: ListBuffer(ss_item_sk#4760, ss_hdemo_sk#4763, ss_addr_sk#4764, ss_promo_sk#4766, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971, c_current_cdemo_sk#4977, c_current_hdemo_sk#4978, c_current_addr_sk#4979, d_year#4896, d_year#4924, cd_marital_status#4995)
    int left_nrow = tbl_JOIN_INNER_TD_14747919_output.getNumRow();
    int right_nrow = tbl_Filter_TD_14721747_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_13369006_key_leftMajor, SW_JOIN_INNER_TD_13369006_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_14747919_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_cdemo_sk4762_k = tbl_JOIN_INNER_TD_14747919_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_13369006_key_leftMajor keyA{_ss_cdemo_sk4762_k};
            int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_14747919_output.getInt32(i, 0);
            int32_t _ss_cdemo_sk4762 = tbl_JOIN_INNER_TD_14747919_output.getInt32(i, 1);
            int32_t _ss_hdemo_sk4763 = tbl_JOIN_INNER_TD_14747919_output.getInt32(i, 2);
            int32_t _ss_addr_sk4764 = tbl_JOIN_INNER_TD_14747919_output.getInt32(i, 3);
            int32_t _ss_promo_sk4766 = tbl_JOIN_INNER_TD_14747919_output.getInt32(i, 4);
            int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_14747919_output.getInt64(i, 5);
            int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_14747919_output.getInt64(i, 6);
            int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_14747919_output.getInt64(i, 7);
            int32_t _d_year4868 = tbl_JOIN_INNER_TD_14747919_output.getInt32(i, 8);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_14747919_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_14747919_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            std::string _s_zip4971 = std::string(_s_zip4971_n.data());
            int32_t _c_current_cdemo_sk4977 = tbl_JOIN_INNER_TD_14747919_output.getInt32(i, 11);
            int32_t _c_current_hdemo_sk4978 = tbl_JOIN_INNER_TD_14747919_output.getInt32(i, 12);
            int32_t _c_current_addr_sk4979 = tbl_JOIN_INNER_TD_14747919_output.getInt32(i, 13);
            int32_t _d_year4896 = tbl_JOIN_INNER_TD_14747919_output.getInt32(i, 14);
            int32_t _d_year4924 = tbl_JOIN_INNER_TD_14747919_output.getInt32(i, 15);
            SW_JOIN_INNER_TD_13369006_payload_leftMajor payloadA{_ss_item_sk4760, _ss_cdemo_sk4762, _ss_hdemo_sk4763, _ss_addr_sk4764, _ss_promo_sk4766, _ss_wholesale_cost4769, _ss_list_price4770, _ss_coupon_amt4777, _d_year4868, _s_store_name4951, _s_zip4971, _c_current_cdemo_sk4977, _c_current_hdemo_sk4978, _c_current_addr_sk4979, _d_year4896, _d_year4924};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_14721747_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cd_demo_sk4993_k = tbl_Filter_TD_14721747_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_13369006_key_leftMajor{_cd_demo_sk4993_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk4760 = (it->second)._ss_item_sk4760;
                int32_t _ss_cdemo_sk4762 = (it->second)._ss_cdemo_sk4762;
                int32_t _ss_hdemo_sk4763 = (it->second)._ss_hdemo_sk4763;
                int32_t _ss_addr_sk4764 = (it->second)._ss_addr_sk4764;
                int32_t _ss_promo_sk4766 = (it->second)._ss_promo_sk4766;
                int64_t _ss_wholesale_cost4769 = (it->second)._ss_wholesale_cost4769;
                int64_t _ss_list_price4770 = (it->second)._ss_list_price4770;
                int64_t _ss_coupon_amt4777 = (it->second)._ss_coupon_amt4777;
                int32_t _d_year4868 = (it->second)._d_year4868;
                std::string _s_store_name4951 = (it->second)._s_store_name4951;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n{};
                memcpy(_s_store_name4951_n.data(), (_s_store_name4951).data(), (_s_store_name4951).length());
                std::string _s_zip4971 = (it->second)._s_zip4971;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n{};
                memcpy(_s_zip4971_n.data(), (_s_zip4971).data(), (_s_zip4971).length());
                int32_t _c_current_cdemo_sk4977 = (it->second)._c_current_cdemo_sk4977;
                int32_t _c_current_hdemo_sk4978 = (it->second)._c_current_hdemo_sk4978;
                int32_t _c_current_addr_sk4979 = (it->second)._c_current_addr_sk4979;
                int32_t _d_year4896 = (it->second)._d_year4896;
                int32_t _d_year4924 = (it->second)._d_year4924;
                int32_t _cd_demo_sk4993 = tbl_Filter_TD_14721747_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status4995_n = tbl_Filter_TD_14721747_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _cd_marital_status4995 = std::string(_cd_marital_status4995_n.data());
                tbl_JOIN_INNER_TD_13369006_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_13369006_output.setInt32(r, 1, _ss_hdemo_sk4763);
                tbl_JOIN_INNER_TD_13369006_output.setInt32(r, 2, _ss_addr_sk4764);
                tbl_JOIN_INNER_TD_13369006_output.setInt32(r, 3, _ss_promo_sk4766);
                tbl_JOIN_INNER_TD_13369006_output.setInt64(r, 4, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_13369006_output.setInt64(r, 5, _ss_list_price4770);
                tbl_JOIN_INNER_TD_13369006_output.setInt64(r, 6, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_13369006_output.setInt32(r, 7, _d_year4868);
                tbl_JOIN_INNER_TD_13369006_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_13369006_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_zip4971_n);
                tbl_JOIN_INNER_TD_13369006_output.setInt32(r, 10, _c_current_cdemo_sk4977);
                tbl_JOIN_INNER_TD_13369006_output.setInt32(r, 11, _c_current_hdemo_sk4978);
                tbl_JOIN_INNER_TD_13369006_output.setInt32(r, 12, _c_current_addr_sk4979);
                tbl_JOIN_INNER_TD_13369006_output.setInt32(r, 13, _d_year4896);
                tbl_JOIN_INNER_TD_13369006_output.setInt32(r, 14, _d_year4924);
                tbl_JOIN_INNER_TD_13369006_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 15, _cd_marital_status4995_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_13369006_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_13369006_key_rightMajor, SW_JOIN_INNER_TD_13369006_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_14721747_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cd_demo_sk4993_k = tbl_Filter_TD_14721747_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_13369006_key_rightMajor keyA{_cd_demo_sk4993_k};
            int32_t _cd_demo_sk4993 = tbl_Filter_TD_14721747_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status4995_n = tbl_Filter_TD_14721747_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cd_marital_status4995 = std::string(_cd_marital_status4995_n.data());
            SW_JOIN_INNER_TD_13369006_payload_rightMajor payloadA{_cd_demo_sk4993, _cd_marital_status4995};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_14747919_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_cdemo_sk4762_k = tbl_JOIN_INNER_TD_14747919_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_13369006_key_rightMajor{_ss_cdemo_sk4762_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cd_demo_sk4993 = (it->second)._cd_demo_sk4993;
                std::string _cd_marital_status4995 = (it->second)._cd_marital_status4995;
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status4995_n{};
                memcpy(_cd_marital_status4995_n.data(), (_cd_marital_status4995).data(), (_cd_marital_status4995).length());
                int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_14747919_output.getInt32(i, 0);
                int32_t _ss_cdemo_sk4762 = tbl_JOIN_INNER_TD_14747919_output.getInt32(i, 1);
                int32_t _ss_hdemo_sk4763 = tbl_JOIN_INNER_TD_14747919_output.getInt32(i, 2);
                int32_t _ss_addr_sk4764 = tbl_JOIN_INNER_TD_14747919_output.getInt32(i, 3);
                int32_t _ss_promo_sk4766 = tbl_JOIN_INNER_TD_14747919_output.getInt32(i, 4);
                int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_14747919_output.getInt64(i, 5);
                int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_14747919_output.getInt64(i, 6);
                int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_14747919_output.getInt64(i, 7);
                int32_t _d_year4868 = tbl_JOIN_INNER_TD_14747919_output.getInt32(i, 8);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_14747919_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
                std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_14747919_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
                std::string _s_zip4971 = std::string(_s_zip4971_n.data());
                int32_t _c_current_cdemo_sk4977 = tbl_JOIN_INNER_TD_14747919_output.getInt32(i, 11);
                int32_t _c_current_hdemo_sk4978 = tbl_JOIN_INNER_TD_14747919_output.getInt32(i, 12);
                int32_t _c_current_addr_sk4979 = tbl_JOIN_INNER_TD_14747919_output.getInt32(i, 13);
                int32_t _d_year4896 = tbl_JOIN_INNER_TD_14747919_output.getInt32(i, 14);
                int32_t _d_year4924 = tbl_JOIN_INNER_TD_14747919_output.getInt32(i, 15);
                tbl_JOIN_INNER_TD_13369006_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 15, _cd_marital_status4995_n);
                tbl_JOIN_INNER_TD_13369006_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_13369006_output.setInt32(r, 1, _ss_hdemo_sk4763);
                tbl_JOIN_INNER_TD_13369006_output.setInt32(r, 2, _ss_addr_sk4764);
                tbl_JOIN_INNER_TD_13369006_output.setInt32(r, 3, _ss_promo_sk4766);
                tbl_JOIN_INNER_TD_13369006_output.setInt64(r, 4, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_13369006_output.setInt64(r, 5, _ss_list_price4770);
                tbl_JOIN_INNER_TD_13369006_output.setInt64(r, 6, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_13369006_output.setInt32(r, 7, _d_year4868);
                tbl_JOIN_INNER_TD_13369006_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_13369006_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_zip4971_n);
                tbl_JOIN_INNER_TD_13369006_output.setInt32(r, 10, _c_current_cdemo_sk4977);
                tbl_JOIN_INNER_TD_13369006_output.setInt32(r, 11, _c_current_hdemo_sk4978);
                tbl_JOIN_INNER_TD_13369006_output.setInt32(r, 12, _c_current_addr_sk4979);
                tbl_JOIN_INNER_TD_13369006_output.setInt32(r, 13, _d_year4896);
                tbl_JOIN_INNER_TD_13369006_output.setInt32(r, 14, _d_year4924);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_13369006_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_13369006_output #Row: " << tbl_JOIN_INNER_TD_13369006_output.getNumRow() << std::endl;
}

void SW_Filter_TD_13256744(Table &tbl_SerializeFromObject_TD_14853068_input, Table &tbl_Filter_TD_13256744_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cd_demo_sk#3626) AND isnotnull(cd_marital_status#3628)))
    // Input: ListBuffer(cd_demo_sk#3626, cd_marital_status#3628)
    // Output: ListBuffer(cd_demo_sk#3626, cd_marital_status#3628)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_14853068_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cd_demo_sk3626 = tbl_SerializeFromObject_TD_14853068_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status3628 = tbl_SerializeFromObject_TD_14853068_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_cd_demo_sk3626!= 0) && _cd_marital_status3628.data() != "NULL") {
            int32_t _cd_demo_sk3626_t = tbl_SerializeFromObject_TD_14853068_input.getInt32(i, 0);
            tbl_Filter_TD_13256744_output.setInt32(r, 0, _cd_demo_sk3626_t);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status3628_t = tbl_SerializeFromObject_TD_14853068_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_13256744_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cd_marital_status3628_t);
            r++;
        }
    }
    tbl_Filter_TD_13256744_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_13256744_output #Row: " << tbl_Filter_TD_13256744_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_13600633_key_leftMajor {
    int32_t _ss_cdemo_sk1210;
    bool operator==(const SW_JOIN_INNER_TD_13600633_key_leftMajor& other) const {
        return ((_ss_cdemo_sk1210 == other._ss_cdemo_sk1210));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_13600633_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_13600633_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_cdemo_sk1210));
    }
};
}
struct SW_JOIN_INNER_TD_13600633_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int32_t _ss_cdemo_sk1210;
    int32_t _ss_hdemo_sk1211;
    int32_t _ss_addr_sk1212;
    int32_t _ss_promo_sk1214;
    int64_t _ss_wholesale_cost1217;
    int64_t _ss_list_price1218;
    int64_t _ss_coupon_amt1225;
    int32_t _d_year126;
    std::string _s_store_name383;
    std::string _s_zip403;
    int32_t _c_current_cdemo_sk2;
    int32_t _c_current_hdemo_sk3;
    int32_t _c_current_addr_sk4;
    int32_t _d_year3576;
    int32_t _d_year3604;
};
struct SW_JOIN_INNER_TD_13600633_key_rightMajor {
    int32_t _cd_demo_sk93;
    bool operator==(const SW_JOIN_INNER_TD_13600633_key_rightMajor& other) const {
        return ((_cd_demo_sk93 == other._cd_demo_sk93));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_13600633_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_13600633_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cd_demo_sk93));
    }
};
}
struct SW_JOIN_INNER_TD_13600633_payload_rightMajor {
    int32_t _cd_demo_sk93;
    std::string _cd_marital_status95;
};
void SW_JOIN_INNER_TD_13600633(Table &tbl_JOIN_INNER_TD_14267925_output, Table &tbl_Filter_TD_14892724_output, Table &tbl_JOIN_INNER_TD_13600633_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_cdemo_sk#1210 = cd_demo_sk#93))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_promo_sk#1214, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403, c_current_cdemo_sk#2, c_current_hdemo_sk#3, c_current_addr_sk#4, d_year#3576, d_year#3604)
    // Right Table: ListBuffer(cd_demo_sk#93, cd_marital_status#95)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_promo_sk#1214, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403, c_current_cdemo_sk#2, c_current_hdemo_sk#3, c_current_addr_sk#4, d_year#3576, d_year#3604, cd_marital_status#95)
    int left_nrow = tbl_JOIN_INNER_TD_14267925_output.getNumRow();
    int right_nrow = tbl_Filter_TD_14892724_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_13600633_key_leftMajor, SW_JOIN_INNER_TD_13600633_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_14267925_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_cdemo_sk1210_k = tbl_JOIN_INNER_TD_14267925_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_13600633_key_leftMajor keyA{_ss_cdemo_sk1210_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_14267925_output.getInt32(i, 0);
            int32_t _ss_cdemo_sk1210 = tbl_JOIN_INNER_TD_14267925_output.getInt32(i, 1);
            int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_14267925_output.getInt32(i, 2);
            int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_14267925_output.getInt32(i, 3);
            int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_14267925_output.getInt32(i, 4);
            int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_14267925_output.getInt64(i, 5);
            int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_14267925_output.getInt64(i, 6);
            int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_14267925_output.getInt64(i, 7);
            int32_t _d_year126 = tbl_JOIN_INNER_TD_14267925_output.getInt32(i, 8);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_14267925_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            std::string _s_store_name383 = std::string(_s_store_name383_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_14267925_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            std::string _s_zip403 = std::string(_s_zip403_n.data());
            int32_t _c_current_cdemo_sk2 = tbl_JOIN_INNER_TD_14267925_output.getInt32(i, 11);
            int32_t _c_current_hdemo_sk3 = tbl_JOIN_INNER_TD_14267925_output.getInt32(i, 12);
            int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_14267925_output.getInt32(i, 13);
            int32_t _d_year3576 = tbl_JOIN_INNER_TD_14267925_output.getInt32(i, 14);
            int32_t _d_year3604 = tbl_JOIN_INNER_TD_14267925_output.getInt32(i, 15);
            SW_JOIN_INNER_TD_13600633_payload_leftMajor payloadA{_ss_item_sk1208, _ss_cdemo_sk1210, _ss_hdemo_sk1211, _ss_addr_sk1212, _ss_promo_sk1214, _ss_wholesale_cost1217, _ss_list_price1218, _ss_coupon_amt1225, _d_year126, _s_store_name383, _s_zip403, _c_current_cdemo_sk2, _c_current_hdemo_sk3, _c_current_addr_sk4, _d_year3576, _d_year3604};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_14892724_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cd_demo_sk93_k = tbl_Filter_TD_14892724_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_13600633_key_leftMajor{_cd_demo_sk93_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_cdemo_sk1210 = (it->second)._ss_cdemo_sk1210;
                int32_t _ss_hdemo_sk1211 = (it->second)._ss_hdemo_sk1211;
                int32_t _ss_addr_sk1212 = (it->second)._ss_addr_sk1212;
                int32_t _ss_promo_sk1214 = (it->second)._ss_promo_sk1214;
                int64_t _ss_wholesale_cost1217 = (it->second)._ss_wholesale_cost1217;
                int64_t _ss_list_price1218 = (it->second)._ss_list_price1218;
                int64_t _ss_coupon_amt1225 = (it->second)._ss_coupon_amt1225;
                int32_t _d_year126 = (it->second)._d_year126;
                std::string _s_store_name383 = (it->second)._s_store_name383;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n{};
                memcpy(_s_store_name383_n.data(), (_s_store_name383).data(), (_s_store_name383).length());
                std::string _s_zip403 = (it->second)._s_zip403;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n{};
                memcpy(_s_zip403_n.data(), (_s_zip403).data(), (_s_zip403).length());
                int32_t _c_current_cdemo_sk2 = (it->second)._c_current_cdemo_sk2;
                int32_t _c_current_hdemo_sk3 = (it->second)._c_current_hdemo_sk3;
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                int32_t _d_year3576 = (it->second)._d_year3576;
                int32_t _d_year3604 = (it->second)._d_year3604;
                int32_t _cd_demo_sk93 = tbl_Filter_TD_14892724_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n = tbl_Filter_TD_14892724_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _cd_marital_status95 = std::string(_cd_marital_status95_n.data());
                tbl_JOIN_INNER_TD_13600633_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_13600633_output.setInt32(r, 1, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_13600633_output.setInt32(r, 2, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_13600633_output.setInt32(r, 3, _ss_promo_sk1214);
                tbl_JOIN_INNER_TD_13600633_output.setInt64(r, 4, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_13600633_output.setInt64(r, 5, _ss_list_price1218);
                tbl_JOIN_INNER_TD_13600633_output.setInt64(r, 6, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_13600633_output.setInt32(r, 7, _d_year126);
                tbl_JOIN_INNER_TD_13600633_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _s_store_name383_n);
                tbl_JOIN_INNER_TD_13600633_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_zip403_n);
                tbl_JOIN_INNER_TD_13600633_output.setInt32(r, 10, _c_current_cdemo_sk2);
                tbl_JOIN_INNER_TD_13600633_output.setInt32(r, 11, _c_current_hdemo_sk3);
                tbl_JOIN_INNER_TD_13600633_output.setInt32(r, 12, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_13600633_output.setInt32(r, 13, _d_year3576);
                tbl_JOIN_INNER_TD_13600633_output.setInt32(r, 14, _d_year3604);
                tbl_JOIN_INNER_TD_13600633_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 15, _cd_marital_status95_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_13600633_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_13600633_key_rightMajor, SW_JOIN_INNER_TD_13600633_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_14892724_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cd_demo_sk93_k = tbl_Filter_TD_14892724_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_13600633_key_rightMajor keyA{_cd_demo_sk93_k};
            int32_t _cd_demo_sk93 = tbl_Filter_TD_14892724_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n = tbl_Filter_TD_14892724_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cd_marital_status95 = std::string(_cd_marital_status95_n.data());
            SW_JOIN_INNER_TD_13600633_payload_rightMajor payloadA{_cd_demo_sk93, _cd_marital_status95};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_14267925_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_cdemo_sk1210_k = tbl_JOIN_INNER_TD_14267925_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_13600633_key_rightMajor{_ss_cdemo_sk1210_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cd_demo_sk93 = (it->second)._cd_demo_sk93;
                std::string _cd_marital_status95 = (it->second)._cd_marital_status95;
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n{};
                memcpy(_cd_marital_status95_n.data(), (_cd_marital_status95).data(), (_cd_marital_status95).length());
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_14267925_output.getInt32(i, 0);
                int32_t _ss_cdemo_sk1210 = tbl_JOIN_INNER_TD_14267925_output.getInt32(i, 1);
                int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_14267925_output.getInt32(i, 2);
                int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_14267925_output.getInt32(i, 3);
                int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_14267925_output.getInt32(i, 4);
                int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_14267925_output.getInt64(i, 5);
                int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_14267925_output.getInt64(i, 6);
                int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_14267925_output.getInt64(i, 7);
                int32_t _d_year126 = tbl_JOIN_INNER_TD_14267925_output.getInt32(i, 8);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_14267925_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
                std::string _s_store_name383 = std::string(_s_store_name383_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_14267925_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
                std::string _s_zip403 = std::string(_s_zip403_n.data());
                int32_t _c_current_cdemo_sk2 = tbl_JOIN_INNER_TD_14267925_output.getInt32(i, 11);
                int32_t _c_current_hdemo_sk3 = tbl_JOIN_INNER_TD_14267925_output.getInt32(i, 12);
                int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_14267925_output.getInt32(i, 13);
                int32_t _d_year3576 = tbl_JOIN_INNER_TD_14267925_output.getInt32(i, 14);
                int32_t _d_year3604 = tbl_JOIN_INNER_TD_14267925_output.getInt32(i, 15);
                tbl_JOIN_INNER_TD_13600633_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 15, _cd_marital_status95_n);
                tbl_JOIN_INNER_TD_13600633_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_13600633_output.setInt32(r, 1, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_13600633_output.setInt32(r, 2, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_13600633_output.setInt32(r, 3, _ss_promo_sk1214);
                tbl_JOIN_INNER_TD_13600633_output.setInt64(r, 4, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_13600633_output.setInt64(r, 5, _ss_list_price1218);
                tbl_JOIN_INNER_TD_13600633_output.setInt64(r, 6, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_13600633_output.setInt32(r, 7, _d_year126);
                tbl_JOIN_INNER_TD_13600633_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _s_store_name383_n);
                tbl_JOIN_INNER_TD_13600633_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_zip403_n);
                tbl_JOIN_INNER_TD_13600633_output.setInt32(r, 10, _c_current_cdemo_sk2);
                tbl_JOIN_INNER_TD_13600633_output.setInt32(r, 11, _c_current_hdemo_sk3);
                tbl_JOIN_INNER_TD_13600633_output.setInt32(r, 12, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_13600633_output.setInt32(r, 13, _d_year3576);
                tbl_JOIN_INNER_TD_13600633_output.setInt32(r, 14, _d_year3604);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_13600633_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_13600633_output #Row: " << tbl_JOIN_INNER_TD_13600633_output.getNumRow() << std::endl;
}

void SW_Filter_TD_124448(Table &tbl_SerializeFromObject_TD_13452394_input, Table &tbl_Filter_TD_124448_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(p_promo_sk#5011))
    // Input: ListBuffer(p_promo_sk#5011)
    // Output: ListBuffer(p_promo_sk#5011)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13452394_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _p_promo_sk5011 = tbl_SerializeFromObject_TD_13452394_input.getInt32(i, 0);
        if (_p_promo_sk5011!= 0) {
            int32_t _p_promo_sk5011_t = tbl_SerializeFromObject_TD_13452394_input.getInt32(i, 0);
            tbl_Filter_TD_124448_output.setInt32(r, 0, _p_promo_sk5011_t);
            r++;
        }
    }
    tbl_Filter_TD_124448_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_124448_output #Row: " << tbl_Filter_TD_124448_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_12273451_key_leftMajor {
    int32_t _c_current_cdemo_sk4977;
    std::string _cd_marital_status4995;
    bool operator==(const SW_JOIN_INNER_TD_12273451_key_leftMajor& other) const {
        return ((_c_current_cdemo_sk4977 == other._c_current_cdemo_sk4977) && (_cd_marital_status4995 == other._cd_marital_status4995));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_12273451_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_12273451_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_current_cdemo_sk4977));
    }
};
}
struct SW_JOIN_INNER_TD_12273451_payload_leftMajor {
    int32_t _ss_item_sk4760;
    int32_t _ss_hdemo_sk4763;
    int32_t _ss_addr_sk4764;
    int32_t _ss_promo_sk4766;
    int64_t _ss_wholesale_cost4769;
    int64_t _ss_list_price4770;
    int64_t _ss_coupon_amt4777;
    int32_t _d_year4868;
    std::string _s_store_name4951;
    std::string _s_zip4971;
    int32_t _c_current_cdemo_sk4977;
    int32_t _c_current_hdemo_sk4978;
    int32_t _c_current_addr_sk4979;
    int32_t _d_year4896;
    int32_t _d_year4924;
    std::string _cd_marital_status4995;
};
struct SW_JOIN_INNER_TD_12273451_key_rightMajor {
    int32_t _cd_demo_sk5002;
    std::string _cd_marital_status5004;
    bool operator==(const SW_JOIN_INNER_TD_12273451_key_rightMajor& other) const {
        return ((_cd_demo_sk5002 == other._cd_demo_sk5002) && (_cd_marital_status5004 == other._cd_marital_status5004));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_12273451_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_12273451_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cd_demo_sk5002));
    }
};
}
struct SW_JOIN_INNER_TD_12273451_payload_rightMajor {
    int32_t _cd_demo_sk5002;
    std::string _cd_marital_status5004;
};
void SW_JOIN_INNER_TD_12273451(Table &tbl_JOIN_INNER_TD_13369006_output, Table &tbl_Filter_TD_13655875_output, Table &tbl_JOIN_INNER_TD_12273451_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((c_current_cdemo_sk#4977 = cd_demo_sk#5002) AND NOT (cd_marital_status#4995 = cd_marital_status#5004)))
    // Left Table: ListBuffer(ss_item_sk#4760, ss_hdemo_sk#4763, ss_addr_sk#4764, ss_promo_sk#4766, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971, c_current_cdemo_sk#4977, c_current_hdemo_sk#4978, c_current_addr_sk#4979, d_year#4896, d_year#4924, cd_marital_status#4995)
    // Right Table: ListBuffer(cd_demo_sk#5002, cd_marital_status#5004)
    // Output Table: ListBuffer(ss_item_sk#4760, ss_hdemo_sk#4763, ss_addr_sk#4764, ss_promo_sk#4766, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971, c_current_hdemo_sk#4978, c_current_addr_sk#4979, d_year#4896, d_year#4924)
    int left_nrow = tbl_JOIN_INNER_TD_13369006_output.getNumRow();
    int right_nrow = tbl_Filter_TD_13655875_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_12273451_key_leftMajor, SW_JOIN_INNER_TD_12273451_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_13369006_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_current_cdemo_sk4977_k = tbl_JOIN_INNER_TD_13369006_output.getInt32(i, 10);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status4995_k_n = tbl_JOIN_INNER_TD_13369006_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
            std::string _cd_marital_status4995_k = std::string(_cd_marital_status4995_k_n.data());
            SW_JOIN_INNER_TD_12273451_key_leftMajor keyA{_c_current_cdemo_sk4977_k, _cd_marital_status4995_k};
            int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_13369006_output.getInt32(i, 0);
            int32_t _ss_hdemo_sk4763 = tbl_JOIN_INNER_TD_13369006_output.getInt32(i, 1);
            int32_t _ss_addr_sk4764 = tbl_JOIN_INNER_TD_13369006_output.getInt32(i, 2);
            int32_t _ss_promo_sk4766 = tbl_JOIN_INNER_TD_13369006_output.getInt32(i, 3);
            int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_13369006_output.getInt64(i, 4);
            int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_13369006_output.getInt64(i, 5);
            int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_13369006_output.getInt64(i, 6);
            int32_t _d_year4868 = tbl_JOIN_INNER_TD_13369006_output.getInt32(i, 7);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_13369006_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
            std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_13369006_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            std::string _s_zip4971 = std::string(_s_zip4971_n.data());
            int32_t _c_current_cdemo_sk4977 = tbl_JOIN_INNER_TD_13369006_output.getInt32(i, 10);
            int32_t _c_current_hdemo_sk4978 = tbl_JOIN_INNER_TD_13369006_output.getInt32(i, 11);
            int32_t _c_current_addr_sk4979 = tbl_JOIN_INNER_TD_13369006_output.getInt32(i, 12);
            int32_t _d_year4896 = tbl_JOIN_INNER_TD_13369006_output.getInt32(i, 13);
            int32_t _d_year4924 = tbl_JOIN_INNER_TD_13369006_output.getInt32(i, 14);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status4995_n = tbl_JOIN_INNER_TD_13369006_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
            std::string _cd_marital_status4995 = std::string(_cd_marital_status4995_n.data());
            SW_JOIN_INNER_TD_12273451_payload_leftMajor payloadA{_ss_item_sk4760, _ss_hdemo_sk4763, _ss_addr_sk4764, _ss_promo_sk4766, _ss_wholesale_cost4769, _ss_list_price4770, _ss_coupon_amt4777, _d_year4868, _s_store_name4951, _s_zip4971, _c_current_cdemo_sk4977, _c_current_hdemo_sk4978, _c_current_addr_sk4979, _d_year4896, _d_year4924, _cd_marital_status4995};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_13655875_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cd_demo_sk5002_k = tbl_Filter_TD_13655875_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status5004_k_n = tbl_Filter_TD_13655875_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cd_marital_status5004_k = std::string(_cd_marital_status5004_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_12273451_key_leftMajor{_cd_demo_sk5002_k, _cd_marital_status5004_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk4760 = (it->second)._ss_item_sk4760;
                int32_t _ss_hdemo_sk4763 = (it->second)._ss_hdemo_sk4763;
                int32_t _ss_addr_sk4764 = (it->second)._ss_addr_sk4764;
                int32_t _ss_promo_sk4766 = (it->second)._ss_promo_sk4766;
                int64_t _ss_wholesale_cost4769 = (it->second)._ss_wholesale_cost4769;
                int64_t _ss_list_price4770 = (it->second)._ss_list_price4770;
                int64_t _ss_coupon_amt4777 = (it->second)._ss_coupon_amt4777;
                int32_t _d_year4868 = (it->second)._d_year4868;
                std::string _s_store_name4951 = (it->second)._s_store_name4951;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n{};
                memcpy(_s_store_name4951_n.data(), (_s_store_name4951).data(), (_s_store_name4951).length());
                std::string _s_zip4971 = (it->second)._s_zip4971;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n{};
                memcpy(_s_zip4971_n.data(), (_s_zip4971).data(), (_s_zip4971).length());
                int32_t _c_current_cdemo_sk4977 = (it->second)._c_current_cdemo_sk4977;
                int32_t _c_current_hdemo_sk4978 = (it->second)._c_current_hdemo_sk4978;
                int32_t _c_current_addr_sk4979 = (it->second)._c_current_addr_sk4979;
                int32_t _d_year4896 = (it->second)._d_year4896;
                int32_t _d_year4924 = (it->second)._d_year4924;
                std::string _cd_marital_status4995 = (it->second)._cd_marital_status4995;
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status4995_n{};
                memcpy(_cd_marital_status4995_n.data(), (_cd_marital_status4995).data(), (_cd_marital_status4995).length());
                int32_t _cd_demo_sk5002 = tbl_Filter_TD_13655875_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status5004_n = tbl_Filter_TD_13655875_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _cd_marital_status5004 = std::string(_cd_marital_status5004_n.data());
                tbl_JOIN_INNER_TD_12273451_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_12273451_output.setInt32(r, 1, _ss_hdemo_sk4763);
                tbl_JOIN_INNER_TD_12273451_output.setInt32(r, 2, _ss_addr_sk4764);
                tbl_JOIN_INNER_TD_12273451_output.setInt32(r, 3, _ss_promo_sk4766);
                tbl_JOIN_INNER_TD_12273451_output.setInt64(r, 4, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_12273451_output.setInt64(r, 5, _ss_list_price4770);
                tbl_JOIN_INNER_TD_12273451_output.setInt64(r, 6, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_12273451_output.setInt32(r, 7, _d_year4868);
                tbl_JOIN_INNER_TD_12273451_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_12273451_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_zip4971_n);
                tbl_JOIN_INNER_TD_12273451_output.setInt32(r, 10, _c_current_hdemo_sk4978);
                tbl_JOIN_INNER_TD_12273451_output.setInt32(r, 11, _c_current_addr_sk4979);
                tbl_JOIN_INNER_TD_12273451_output.setInt32(r, 12, _d_year4896);
                tbl_JOIN_INNER_TD_12273451_output.setInt32(r, 13, _d_year4924);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_12273451_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_12273451_key_rightMajor, SW_JOIN_INNER_TD_12273451_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_13655875_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cd_demo_sk5002_k = tbl_Filter_TD_13655875_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status5004_k_n = tbl_Filter_TD_13655875_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cd_marital_status5004_k = std::string(_cd_marital_status5004_k_n.data());
            SW_JOIN_INNER_TD_12273451_key_rightMajor keyA{_cd_demo_sk5002_k, _cd_marital_status5004_k};
            int32_t _cd_demo_sk5002 = tbl_Filter_TD_13655875_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status5004_n = tbl_Filter_TD_13655875_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cd_marital_status5004 = std::string(_cd_marital_status5004_n.data());
            SW_JOIN_INNER_TD_12273451_payload_rightMajor payloadA{_cd_demo_sk5002, _cd_marital_status5004};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_13369006_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_current_cdemo_sk4977_k = tbl_JOIN_INNER_TD_13369006_output.getInt32(i, 10);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status4995_k_n = tbl_JOIN_INNER_TD_13369006_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
            std::string _cd_marital_status4995_k = std::string(_cd_marital_status4995_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_12273451_key_rightMajor{_c_current_cdemo_sk4977_k, _cd_marital_status4995_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cd_demo_sk5002 = (it->second)._cd_demo_sk5002;
                std::string _cd_marital_status5004 = (it->second)._cd_marital_status5004;
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status5004_n{};
                memcpy(_cd_marital_status5004_n.data(), (_cd_marital_status5004).data(), (_cd_marital_status5004).length());
                int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_13369006_output.getInt32(i, 0);
                int32_t _ss_hdemo_sk4763 = tbl_JOIN_INNER_TD_13369006_output.getInt32(i, 1);
                int32_t _ss_addr_sk4764 = tbl_JOIN_INNER_TD_13369006_output.getInt32(i, 2);
                int32_t _ss_promo_sk4766 = tbl_JOIN_INNER_TD_13369006_output.getInt32(i, 3);
                int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_13369006_output.getInt64(i, 4);
                int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_13369006_output.getInt64(i, 5);
                int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_13369006_output.getInt64(i, 6);
                int32_t _d_year4868 = tbl_JOIN_INNER_TD_13369006_output.getInt32(i, 7);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_13369006_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
                std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_13369006_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
                std::string _s_zip4971 = std::string(_s_zip4971_n.data());
                int32_t _c_current_cdemo_sk4977 = tbl_JOIN_INNER_TD_13369006_output.getInt32(i, 10);
                int32_t _c_current_hdemo_sk4978 = tbl_JOIN_INNER_TD_13369006_output.getInt32(i, 11);
                int32_t _c_current_addr_sk4979 = tbl_JOIN_INNER_TD_13369006_output.getInt32(i, 12);
                int32_t _d_year4896 = tbl_JOIN_INNER_TD_13369006_output.getInt32(i, 13);
                int32_t _d_year4924 = tbl_JOIN_INNER_TD_13369006_output.getInt32(i, 14);
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status4995_n = tbl_JOIN_INNER_TD_13369006_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
                std::string _cd_marital_status4995 = std::string(_cd_marital_status4995_n.data());
                tbl_JOIN_INNER_TD_12273451_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_12273451_output.setInt32(r, 1, _ss_hdemo_sk4763);
                tbl_JOIN_INNER_TD_12273451_output.setInt32(r, 2, _ss_addr_sk4764);
                tbl_JOIN_INNER_TD_12273451_output.setInt32(r, 3, _ss_promo_sk4766);
                tbl_JOIN_INNER_TD_12273451_output.setInt64(r, 4, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_12273451_output.setInt64(r, 5, _ss_list_price4770);
                tbl_JOIN_INNER_TD_12273451_output.setInt64(r, 6, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_12273451_output.setInt32(r, 7, _d_year4868);
                tbl_JOIN_INNER_TD_12273451_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_12273451_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_zip4971_n);
                tbl_JOIN_INNER_TD_12273451_output.setInt32(r, 10, _c_current_hdemo_sk4978);
                tbl_JOIN_INNER_TD_12273451_output.setInt32(r, 11, _c_current_addr_sk4979);
                tbl_JOIN_INNER_TD_12273451_output.setInt32(r, 12, _d_year4896);
                tbl_JOIN_INNER_TD_12273451_output.setInt32(r, 13, _d_year4924);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_12273451_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_12273451_output #Row: " << tbl_JOIN_INNER_TD_12273451_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12174597(Table &tbl_SerializeFromObject_TD_13651411_input, Table &tbl_Filter_TD_12174597_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(p_promo_sk#294))
    // Input: ListBuffer(p_promo_sk#294)
    // Output: ListBuffer(p_promo_sk#294)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13651411_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _p_promo_sk294 = tbl_SerializeFromObject_TD_13651411_input.getInt32(i, 0);
        if (_p_promo_sk294!= 0) {
            int32_t _p_promo_sk294_t = tbl_SerializeFromObject_TD_13651411_input.getInt32(i, 0);
            tbl_Filter_TD_12174597_output.setInt32(r, 0, _p_promo_sk294_t);
            r++;
        }
    }
    tbl_Filter_TD_12174597_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12174597_output #Row: " << tbl_Filter_TD_12174597_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_12115296_key_leftMajor {
    int32_t _c_current_cdemo_sk2;
    std::string _cd_marital_status95;
    bool operator==(const SW_JOIN_INNER_TD_12115296_key_leftMajor& other) const {
        return ((_c_current_cdemo_sk2 == other._c_current_cdemo_sk2) && (_cd_marital_status95 == other._cd_marital_status95));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_12115296_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_12115296_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_current_cdemo_sk2));
    }
};
}
struct SW_JOIN_INNER_TD_12115296_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int32_t _ss_hdemo_sk1211;
    int32_t _ss_addr_sk1212;
    int32_t _ss_promo_sk1214;
    int64_t _ss_wholesale_cost1217;
    int64_t _ss_list_price1218;
    int64_t _ss_coupon_amt1225;
    int32_t _d_year126;
    std::string _s_store_name383;
    std::string _s_zip403;
    int32_t _c_current_cdemo_sk2;
    int32_t _c_current_hdemo_sk3;
    int32_t _c_current_addr_sk4;
    int32_t _d_year3576;
    int32_t _d_year3604;
    std::string _cd_marital_status95;
};
struct SW_JOIN_INNER_TD_12115296_key_rightMajor {
    int32_t _cd_demo_sk3626;
    std::string _cd_marital_status3628;
    bool operator==(const SW_JOIN_INNER_TD_12115296_key_rightMajor& other) const {
        return ((_cd_demo_sk3626 == other._cd_demo_sk3626) && (_cd_marital_status3628 == other._cd_marital_status3628));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_12115296_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_12115296_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cd_demo_sk3626));
    }
};
}
struct SW_JOIN_INNER_TD_12115296_payload_rightMajor {
    int32_t _cd_demo_sk3626;
    std::string _cd_marital_status3628;
};
void SW_JOIN_INNER_TD_12115296(Table &tbl_JOIN_INNER_TD_13600633_output, Table &tbl_Filter_TD_13256744_output, Table &tbl_JOIN_INNER_TD_12115296_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((c_current_cdemo_sk#2 = cd_demo_sk#3626) AND NOT (cd_marital_status#95 = cd_marital_status#3628)))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_promo_sk#1214, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403, c_current_cdemo_sk#2, c_current_hdemo_sk#3, c_current_addr_sk#4, d_year#3576, d_year#3604, cd_marital_status#95)
    // Right Table: ListBuffer(cd_demo_sk#3626, cd_marital_status#3628)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_promo_sk#1214, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403, c_current_hdemo_sk#3, c_current_addr_sk#4, d_year#3576, d_year#3604)
    int left_nrow = tbl_JOIN_INNER_TD_13600633_output.getNumRow();
    int right_nrow = tbl_Filter_TD_13256744_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_12115296_key_leftMajor, SW_JOIN_INNER_TD_12115296_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_13600633_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_current_cdemo_sk2_k = tbl_JOIN_INNER_TD_13600633_output.getInt32(i, 10);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_k_n = tbl_JOIN_INNER_TD_13600633_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
            std::string _cd_marital_status95_k = std::string(_cd_marital_status95_k_n.data());
            SW_JOIN_INNER_TD_12115296_key_leftMajor keyA{_c_current_cdemo_sk2_k, _cd_marital_status95_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_13600633_output.getInt32(i, 0);
            int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_13600633_output.getInt32(i, 1);
            int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_13600633_output.getInt32(i, 2);
            int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_13600633_output.getInt32(i, 3);
            int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_13600633_output.getInt64(i, 4);
            int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_13600633_output.getInt64(i, 5);
            int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_13600633_output.getInt64(i, 6);
            int32_t _d_year126 = tbl_JOIN_INNER_TD_13600633_output.getInt32(i, 7);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_13600633_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
            std::string _s_store_name383 = std::string(_s_store_name383_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_13600633_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            std::string _s_zip403 = std::string(_s_zip403_n.data());
            int32_t _c_current_cdemo_sk2 = tbl_JOIN_INNER_TD_13600633_output.getInt32(i, 10);
            int32_t _c_current_hdemo_sk3 = tbl_JOIN_INNER_TD_13600633_output.getInt32(i, 11);
            int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_13600633_output.getInt32(i, 12);
            int32_t _d_year3576 = tbl_JOIN_INNER_TD_13600633_output.getInt32(i, 13);
            int32_t _d_year3604 = tbl_JOIN_INNER_TD_13600633_output.getInt32(i, 14);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n = tbl_JOIN_INNER_TD_13600633_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
            std::string _cd_marital_status95 = std::string(_cd_marital_status95_n.data());
            SW_JOIN_INNER_TD_12115296_payload_leftMajor payloadA{_ss_item_sk1208, _ss_hdemo_sk1211, _ss_addr_sk1212, _ss_promo_sk1214, _ss_wholesale_cost1217, _ss_list_price1218, _ss_coupon_amt1225, _d_year126, _s_store_name383, _s_zip403, _c_current_cdemo_sk2, _c_current_hdemo_sk3, _c_current_addr_sk4, _d_year3576, _d_year3604, _cd_marital_status95};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_13256744_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cd_demo_sk3626_k = tbl_Filter_TD_13256744_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status3628_k_n = tbl_Filter_TD_13256744_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cd_marital_status3628_k = std::string(_cd_marital_status3628_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_12115296_key_leftMajor{_cd_demo_sk3626_k, _cd_marital_status3628_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_hdemo_sk1211 = (it->second)._ss_hdemo_sk1211;
                int32_t _ss_addr_sk1212 = (it->second)._ss_addr_sk1212;
                int32_t _ss_promo_sk1214 = (it->second)._ss_promo_sk1214;
                int64_t _ss_wholesale_cost1217 = (it->second)._ss_wholesale_cost1217;
                int64_t _ss_list_price1218 = (it->second)._ss_list_price1218;
                int64_t _ss_coupon_amt1225 = (it->second)._ss_coupon_amt1225;
                int32_t _d_year126 = (it->second)._d_year126;
                std::string _s_store_name383 = (it->second)._s_store_name383;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n{};
                memcpy(_s_store_name383_n.data(), (_s_store_name383).data(), (_s_store_name383).length());
                std::string _s_zip403 = (it->second)._s_zip403;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n{};
                memcpy(_s_zip403_n.data(), (_s_zip403).data(), (_s_zip403).length());
                int32_t _c_current_cdemo_sk2 = (it->second)._c_current_cdemo_sk2;
                int32_t _c_current_hdemo_sk3 = (it->second)._c_current_hdemo_sk3;
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                int32_t _d_year3576 = (it->second)._d_year3576;
                int32_t _d_year3604 = (it->second)._d_year3604;
                std::string _cd_marital_status95 = (it->second)._cd_marital_status95;
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n{};
                memcpy(_cd_marital_status95_n.data(), (_cd_marital_status95).data(), (_cd_marital_status95).length());
                int32_t _cd_demo_sk3626 = tbl_Filter_TD_13256744_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status3628_n = tbl_Filter_TD_13256744_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _cd_marital_status3628 = std::string(_cd_marital_status3628_n.data());
                tbl_JOIN_INNER_TD_12115296_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_12115296_output.setInt32(r, 1, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_12115296_output.setInt32(r, 2, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_12115296_output.setInt32(r, 3, _ss_promo_sk1214);
                tbl_JOIN_INNER_TD_12115296_output.setInt64(r, 4, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_12115296_output.setInt64(r, 5, _ss_list_price1218);
                tbl_JOIN_INNER_TD_12115296_output.setInt64(r, 6, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_12115296_output.setInt32(r, 7, _d_year126);
                tbl_JOIN_INNER_TD_12115296_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _s_store_name383_n);
                tbl_JOIN_INNER_TD_12115296_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_zip403_n);
                tbl_JOIN_INNER_TD_12115296_output.setInt32(r, 10, _c_current_hdemo_sk3);
                tbl_JOIN_INNER_TD_12115296_output.setInt32(r, 11, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_12115296_output.setInt32(r, 12, _d_year3576);
                tbl_JOIN_INNER_TD_12115296_output.setInt32(r, 13, _d_year3604);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_12115296_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_12115296_key_rightMajor, SW_JOIN_INNER_TD_12115296_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_13256744_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cd_demo_sk3626_k = tbl_Filter_TD_13256744_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status3628_k_n = tbl_Filter_TD_13256744_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cd_marital_status3628_k = std::string(_cd_marital_status3628_k_n.data());
            SW_JOIN_INNER_TD_12115296_key_rightMajor keyA{_cd_demo_sk3626_k, _cd_marital_status3628_k};
            int32_t _cd_demo_sk3626 = tbl_Filter_TD_13256744_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status3628_n = tbl_Filter_TD_13256744_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cd_marital_status3628 = std::string(_cd_marital_status3628_n.data());
            SW_JOIN_INNER_TD_12115296_payload_rightMajor payloadA{_cd_demo_sk3626, _cd_marital_status3628};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_13600633_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_current_cdemo_sk2_k = tbl_JOIN_INNER_TD_13600633_output.getInt32(i, 10);
            std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_k_n = tbl_JOIN_INNER_TD_13600633_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
            std::string _cd_marital_status95_k = std::string(_cd_marital_status95_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_12115296_key_rightMajor{_c_current_cdemo_sk2_k, _cd_marital_status95_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cd_demo_sk3626 = (it->second)._cd_demo_sk3626;
                std::string _cd_marital_status3628 = (it->second)._cd_marital_status3628;
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status3628_n{};
                memcpy(_cd_marital_status3628_n.data(), (_cd_marital_status3628).data(), (_cd_marital_status3628).length());
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_13600633_output.getInt32(i, 0);
                int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_13600633_output.getInt32(i, 1);
                int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_13600633_output.getInt32(i, 2);
                int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_13600633_output.getInt32(i, 3);
                int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_13600633_output.getInt64(i, 4);
                int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_13600633_output.getInt64(i, 5);
                int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_13600633_output.getInt64(i, 6);
                int32_t _d_year126 = tbl_JOIN_INNER_TD_13600633_output.getInt32(i, 7);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_13600633_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
                std::string _s_store_name383 = std::string(_s_store_name383_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_13600633_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
                std::string _s_zip403 = std::string(_s_zip403_n.data());
                int32_t _c_current_cdemo_sk2 = tbl_JOIN_INNER_TD_13600633_output.getInt32(i, 10);
                int32_t _c_current_hdemo_sk3 = tbl_JOIN_INNER_TD_13600633_output.getInt32(i, 11);
                int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_13600633_output.getInt32(i, 12);
                int32_t _d_year3576 = tbl_JOIN_INNER_TD_13600633_output.getInt32(i, 13);
                int32_t _d_year3604 = tbl_JOIN_INNER_TD_13600633_output.getInt32(i, 14);
                std::array<char, TPCDS_READ_MAX + 1> _cd_marital_status95_n = tbl_JOIN_INNER_TD_13600633_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
                std::string _cd_marital_status95 = std::string(_cd_marital_status95_n.data());
                tbl_JOIN_INNER_TD_12115296_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_12115296_output.setInt32(r, 1, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_12115296_output.setInt32(r, 2, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_12115296_output.setInt32(r, 3, _ss_promo_sk1214);
                tbl_JOIN_INNER_TD_12115296_output.setInt64(r, 4, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_12115296_output.setInt64(r, 5, _ss_list_price1218);
                tbl_JOIN_INNER_TD_12115296_output.setInt64(r, 6, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_12115296_output.setInt32(r, 7, _d_year126);
                tbl_JOIN_INNER_TD_12115296_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _s_store_name383_n);
                tbl_JOIN_INNER_TD_12115296_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _s_zip403_n);
                tbl_JOIN_INNER_TD_12115296_output.setInt32(r, 10, _c_current_hdemo_sk3);
                tbl_JOIN_INNER_TD_12115296_output.setInt32(r, 11, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_12115296_output.setInt32(r, 12, _d_year3576);
                tbl_JOIN_INNER_TD_12115296_output.setInt32(r, 13, _d_year3604);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_12115296_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_12115296_output #Row: " << tbl_JOIN_INNER_TD_12115296_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11557957(Table &tbl_SerializeFromObject_TD_12679417_input, Table &tbl_Filter_TD_11557957_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(hd_demo_sk#5030) AND isnotnull(hd_income_band_sk#5031)))
    // Input: ListBuffer(hd_demo_sk#5030, hd_income_band_sk#5031)
    // Output: ListBuffer(hd_demo_sk#5030, hd_income_band_sk#5031)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12679417_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _hd_demo_sk5030 = tbl_SerializeFromObject_TD_12679417_input.getInt32(i, 0);
        int32_t _hd_income_band_sk5031 = tbl_SerializeFromObject_TD_12679417_input.getInt32(i, 1);
        if ((_hd_demo_sk5030!= 0) && (_hd_income_band_sk5031!= 0)) {
            int32_t _hd_demo_sk5030_t = tbl_SerializeFromObject_TD_12679417_input.getInt32(i, 0);
            tbl_Filter_TD_11557957_output.setInt32(r, 0, _hd_demo_sk5030_t);
            int32_t _hd_income_band_sk5031_t = tbl_SerializeFromObject_TD_12679417_input.getInt32(i, 1);
            tbl_Filter_TD_11557957_output.setInt32(r, 1, _hd_income_band_sk5031_t);
            r++;
        }
    }
    tbl_Filter_TD_11557957_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11557957_output #Row: " << tbl_Filter_TD_11557957_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_11493165_key_leftMajor {
    int32_t _ss_promo_sk4766;
    bool operator==(const SW_JOIN_INNER_TD_11493165_key_leftMajor& other) const {
        return ((_ss_promo_sk4766 == other._ss_promo_sk4766));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11493165_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11493165_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_promo_sk4766));
    }
};
}
struct SW_JOIN_INNER_TD_11493165_payload_leftMajor {
    int32_t _ss_item_sk4760;
    int32_t _ss_hdemo_sk4763;
    int32_t _ss_addr_sk4764;
    int32_t _ss_promo_sk4766;
    int64_t _ss_wholesale_cost4769;
    int64_t _ss_list_price4770;
    int64_t _ss_coupon_amt4777;
    int32_t _d_year4868;
    std::string _s_store_name4951;
    std::string _s_zip4971;
    int32_t _c_current_hdemo_sk4978;
    int32_t _c_current_addr_sk4979;
    int32_t _d_year4896;
    int32_t _d_year4924;
};
struct SW_JOIN_INNER_TD_11493165_key_rightMajor {
    int32_t _p_promo_sk5011;
    bool operator==(const SW_JOIN_INNER_TD_11493165_key_rightMajor& other) const {
        return ((_p_promo_sk5011 == other._p_promo_sk5011));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11493165_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11493165_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._p_promo_sk5011));
    }
};
}
struct SW_JOIN_INNER_TD_11493165_payload_rightMajor {
    int32_t _p_promo_sk5011;
};
void SW_JOIN_INNER_TD_11493165(Table &tbl_JOIN_INNER_TD_12273451_output, Table &tbl_Filter_TD_124448_output, Table &tbl_JOIN_INNER_TD_11493165_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_promo_sk#4766 = p_promo_sk#5011))
    // Left Table: ListBuffer(ss_item_sk#4760, ss_hdemo_sk#4763, ss_addr_sk#4764, ss_promo_sk#4766, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971, c_current_hdemo_sk#4978, c_current_addr_sk#4979, d_year#4896, d_year#4924)
    // Right Table: ListBuffer(p_promo_sk#5011)
    // Output Table: ListBuffer(ss_item_sk#4760, ss_hdemo_sk#4763, ss_addr_sk#4764, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971, c_current_hdemo_sk#4978, c_current_addr_sk#4979, d_year#4896, d_year#4924)
    int left_nrow = tbl_JOIN_INNER_TD_12273451_output.getNumRow();
    int right_nrow = tbl_Filter_TD_124448_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11493165_key_leftMajor, SW_JOIN_INNER_TD_11493165_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_12273451_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_promo_sk4766_k = tbl_JOIN_INNER_TD_12273451_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_11493165_key_leftMajor keyA{_ss_promo_sk4766_k};
            int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_12273451_output.getInt32(i, 0);
            int32_t _ss_hdemo_sk4763 = tbl_JOIN_INNER_TD_12273451_output.getInt32(i, 1);
            int32_t _ss_addr_sk4764 = tbl_JOIN_INNER_TD_12273451_output.getInt32(i, 2);
            int32_t _ss_promo_sk4766 = tbl_JOIN_INNER_TD_12273451_output.getInt32(i, 3);
            int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_12273451_output.getInt64(i, 4);
            int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_12273451_output.getInt64(i, 5);
            int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_12273451_output.getInt64(i, 6);
            int32_t _d_year4868 = tbl_JOIN_INNER_TD_12273451_output.getInt32(i, 7);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_12273451_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
            std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_12273451_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            std::string _s_zip4971 = std::string(_s_zip4971_n.data());
            int32_t _c_current_hdemo_sk4978 = tbl_JOIN_INNER_TD_12273451_output.getInt32(i, 10);
            int32_t _c_current_addr_sk4979 = tbl_JOIN_INNER_TD_12273451_output.getInt32(i, 11);
            int32_t _d_year4896 = tbl_JOIN_INNER_TD_12273451_output.getInt32(i, 12);
            int32_t _d_year4924 = tbl_JOIN_INNER_TD_12273451_output.getInt32(i, 13);
            SW_JOIN_INNER_TD_11493165_payload_leftMajor payloadA{_ss_item_sk4760, _ss_hdemo_sk4763, _ss_addr_sk4764, _ss_promo_sk4766, _ss_wholesale_cost4769, _ss_list_price4770, _ss_coupon_amt4777, _d_year4868, _s_store_name4951, _s_zip4971, _c_current_hdemo_sk4978, _c_current_addr_sk4979, _d_year4896, _d_year4924};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_124448_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _p_promo_sk5011_k = tbl_Filter_TD_124448_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11493165_key_leftMajor{_p_promo_sk5011_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk4760 = (it->second)._ss_item_sk4760;
                int32_t _ss_hdemo_sk4763 = (it->second)._ss_hdemo_sk4763;
                int32_t _ss_addr_sk4764 = (it->second)._ss_addr_sk4764;
                int32_t _ss_promo_sk4766 = (it->second)._ss_promo_sk4766;
                int64_t _ss_wholesale_cost4769 = (it->second)._ss_wholesale_cost4769;
                int64_t _ss_list_price4770 = (it->second)._ss_list_price4770;
                int64_t _ss_coupon_amt4777 = (it->second)._ss_coupon_amt4777;
                int32_t _d_year4868 = (it->second)._d_year4868;
                std::string _s_store_name4951 = (it->second)._s_store_name4951;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n{};
                memcpy(_s_store_name4951_n.data(), (_s_store_name4951).data(), (_s_store_name4951).length());
                std::string _s_zip4971 = (it->second)._s_zip4971;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n{};
                memcpy(_s_zip4971_n.data(), (_s_zip4971).data(), (_s_zip4971).length());
                int32_t _c_current_hdemo_sk4978 = (it->second)._c_current_hdemo_sk4978;
                int32_t _c_current_addr_sk4979 = (it->second)._c_current_addr_sk4979;
                int32_t _d_year4896 = (it->second)._d_year4896;
                int32_t _d_year4924 = (it->second)._d_year4924;
                int32_t _p_promo_sk5011 = tbl_Filter_TD_124448_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_11493165_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_11493165_output.setInt32(r, 1, _ss_hdemo_sk4763);
                tbl_JOIN_INNER_TD_11493165_output.setInt32(r, 2, _ss_addr_sk4764);
                tbl_JOIN_INNER_TD_11493165_output.setInt64(r, 3, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_11493165_output.setInt64(r, 4, _ss_list_price4770);
                tbl_JOIN_INNER_TD_11493165_output.setInt64(r, 5, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_11493165_output.setInt32(r, 6, _d_year4868);
                tbl_JOIN_INNER_TD_11493165_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_11493165_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _s_zip4971_n);
                tbl_JOIN_INNER_TD_11493165_output.setInt32(r, 9, _c_current_hdemo_sk4978);
                tbl_JOIN_INNER_TD_11493165_output.setInt32(r, 10, _c_current_addr_sk4979);
                tbl_JOIN_INNER_TD_11493165_output.setInt32(r, 11, _d_year4896);
                tbl_JOIN_INNER_TD_11493165_output.setInt32(r, 12, _d_year4924);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11493165_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11493165_key_rightMajor, SW_JOIN_INNER_TD_11493165_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_124448_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _p_promo_sk5011_k = tbl_Filter_TD_124448_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_11493165_key_rightMajor keyA{_p_promo_sk5011_k};
            int32_t _p_promo_sk5011 = tbl_Filter_TD_124448_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_11493165_payload_rightMajor payloadA{_p_promo_sk5011};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_12273451_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_promo_sk4766_k = tbl_JOIN_INNER_TD_12273451_output.getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11493165_key_rightMajor{_ss_promo_sk4766_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _p_promo_sk5011 = (it->second)._p_promo_sk5011;
                int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_12273451_output.getInt32(i, 0);
                int32_t _ss_hdemo_sk4763 = tbl_JOIN_INNER_TD_12273451_output.getInt32(i, 1);
                int32_t _ss_addr_sk4764 = tbl_JOIN_INNER_TD_12273451_output.getInt32(i, 2);
                int32_t _ss_promo_sk4766 = tbl_JOIN_INNER_TD_12273451_output.getInt32(i, 3);
                int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_12273451_output.getInt64(i, 4);
                int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_12273451_output.getInt64(i, 5);
                int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_12273451_output.getInt64(i, 6);
                int32_t _d_year4868 = tbl_JOIN_INNER_TD_12273451_output.getInt32(i, 7);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_12273451_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
                std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_12273451_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
                std::string _s_zip4971 = std::string(_s_zip4971_n.data());
                int32_t _c_current_hdemo_sk4978 = tbl_JOIN_INNER_TD_12273451_output.getInt32(i, 10);
                int32_t _c_current_addr_sk4979 = tbl_JOIN_INNER_TD_12273451_output.getInt32(i, 11);
                int32_t _d_year4896 = tbl_JOIN_INNER_TD_12273451_output.getInt32(i, 12);
                int32_t _d_year4924 = tbl_JOIN_INNER_TD_12273451_output.getInt32(i, 13);
                tbl_JOIN_INNER_TD_11493165_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_11493165_output.setInt32(r, 1, _ss_hdemo_sk4763);
                tbl_JOIN_INNER_TD_11493165_output.setInt32(r, 2, _ss_addr_sk4764);
                tbl_JOIN_INNER_TD_11493165_output.setInt64(r, 3, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_11493165_output.setInt64(r, 4, _ss_list_price4770);
                tbl_JOIN_INNER_TD_11493165_output.setInt64(r, 5, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_11493165_output.setInt32(r, 6, _d_year4868);
                tbl_JOIN_INNER_TD_11493165_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_11493165_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _s_zip4971_n);
                tbl_JOIN_INNER_TD_11493165_output.setInt32(r, 9, _c_current_hdemo_sk4978);
                tbl_JOIN_INNER_TD_11493165_output.setInt32(r, 10, _c_current_addr_sk4979);
                tbl_JOIN_INNER_TD_11493165_output.setInt32(r, 11, _d_year4896);
                tbl_JOIN_INNER_TD_11493165_output.setInt32(r, 12, _d_year4924);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11493165_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_11493165_output #Row: " << tbl_JOIN_INNER_TD_11493165_output.getNumRow() << std::endl;
}

void SW_Filter_TD_1117050(Table &tbl_SerializeFromObject_TD_12986662_input, Table &tbl_Filter_TD_1117050_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(hd_demo_sk#204) AND isnotnull(hd_income_band_sk#205)))
    // Input: ListBuffer(hd_demo_sk#204, hd_income_band_sk#205)
    // Output: ListBuffer(hd_demo_sk#204, hd_income_band_sk#205)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12986662_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _hd_demo_sk204 = tbl_SerializeFromObject_TD_12986662_input.getInt32(i, 0);
        int32_t _hd_income_band_sk205 = tbl_SerializeFromObject_TD_12986662_input.getInt32(i, 1);
        if ((_hd_demo_sk204!= 0) && (_hd_income_band_sk205!= 0)) {
            int32_t _hd_demo_sk204_t = tbl_SerializeFromObject_TD_12986662_input.getInt32(i, 0);
            tbl_Filter_TD_1117050_output.setInt32(r, 0, _hd_demo_sk204_t);
            int32_t _hd_income_band_sk205_t = tbl_SerializeFromObject_TD_12986662_input.getInt32(i, 1);
            tbl_Filter_TD_1117050_output.setInt32(r, 1, _hd_income_band_sk205_t);
            r++;
        }
    }
    tbl_Filter_TD_1117050_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1117050_output #Row: " << tbl_Filter_TD_1117050_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_11526036_key_leftMajor {
    int32_t _ss_promo_sk1214;
    bool operator==(const SW_JOIN_INNER_TD_11526036_key_leftMajor& other) const {
        return ((_ss_promo_sk1214 == other._ss_promo_sk1214));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11526036_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11526036_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_promo_sk1214));
    }
};
}
struct SW_JOIN_INNER_TD_11526036_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int32_t _ss_hdemo_sk1211;
    int32_t _ss_addr_sk1212;
    int32_t _ss_promo_sk1214;
    int64_t _ss_wholesale_cost1217;
    int64_t _ss_list_price1218;
    int64_t _ss_coupon_amt1225;
    int32_t _d_year126;
    std::string _s_store_name383;
    std::string _s_zip403;
    int32_t _c_current_hdemo_sk3;
    int32_t _c_current_addr_sk4;
    int32_t _d_year3576;
    int32_t _d_year3604;
};
struct SW_JOIN_INNER_TD_11526036_key_rightMajor {
    int32_t _p_promo_sk294;
    bool operator==(const SW_JOIN_INNER_TD_11526036_key_rightMajor& other) const {
        return ((_p_promo_sk294 == other._p_promo_sk294));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11526036_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11526036_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._p_promo_sk294));
    }
};
}
struct SW_JOIN_INNER_TD_11526036_payload_rightMajor {
    int32_t _p_promo_sk294;
};
void SW_JOIN_INNER_TD_11526036(Table &tbl_JOIN_INNER_TD_12115296_output, Table &tbl_Filter_TD_12174597_output, Table &tbl_JOIN_INNER_TD_11526036_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_promo_sk#1214 = p_promo_sk#294))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_promo_sk#1214, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403, c_current_hdemo_sk#3, c_current_addr_sk#4, d_year#3576, d_year#3604)
    // Right Table: ListBuffer(p_promo_sk#294)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403, c_current_hdemo_sk#3, c_current_addr_sk#4, d_year#3576, d_year#3604)
    int left_nrow = tbl_JOIN_INNER_TD_12115296_output.getNumRow();
    int right_nrow = tbl_Filter_TD_12174597_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11526036_key_leftMajor, SW_JOIN_INNER_TD_11526036_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_12115296_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_promo_sk1214_k = tbl_JOIN_INNER_TD_12115296_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_11526036_key_leftMajor keyA{_ss_promo_sk1214_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_12115296_output.getInt32(i, 0);
            int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_12115296_output.getInt32(i, 1);
            int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_12115296_output.getInt32(i, 2);
            int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_12115296_output.getInt32(i, 3);
            int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_12115296_output.getInt64(i, 4);
            int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_12115296_output.getInt64(i, 5);
            int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_12115296_output.getInt64(i, 6);
            int32_t _d_year126 = tbl_JOIN_INNER_TD_12115296_output.getInt32(i, 7);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_12115296_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
            std::string _s_store_name383 = std::string(_s_store_name383_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_12115296_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            std::string _s_zip403 = std::string(_s_zip403_n.data());
            int32_t _c_current_hdemo_sk3 = tbl_JOIN_INNER_TD_12115296_output.getInt32(i, 10);
            int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_12115296_output.getInt32(i, 11);
            int32_t _d_year3576 = tbl_JOIN_INNER_TD_12115296_output.getInt32(i, 12);
            int32_t _d_year3604 = tbl_JOIN_INNER_TD_12115296_output.getInt32(i, 13);
            SW_JOIN_INNER_TD_11526036_payload_leftMajor payloadA{_ss_item_sk1208, _ss_hdemo_sk1211, _ss_addr_sk1212, _ss_promo_sk1214, _ss_wholesale_cost1217, _ss_list_price1218, _ss_coupon_amt1225, _d_year126, _s_store_name383, _s_zip403, _c_current_hdemo_sk3, _c_current_addr_sk4, _d_year3576, _d_year3604};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_12174597_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _p_promo_sk294_k = tbl_Filter_TD_12174597_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11526036_key_leftMajor{_p_promo_sk294_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_hdemo_sk1211 = (it->second)._ss_hdemo_sk1211;
                int32_t _ss_addr_sk1212 = (it->second)._ss_addr_sk1212;
                int32_t _ss_promo_sk1214 = (it->second)._ss_promo_sk1214;
                int64_t _ss_wholesale_cost1217 = (it->second)._ss_wholesale_cost1217;
                int64_t _ss_list_price1218 = (it->second)._ss_list_price1218;
                int64_t _ss_coupon_amt1225 = (it->second)._ss_coupon_amt1225;
                int32_t _d_year126 = (it->second)._d_year126;
                std::string _s_store_name383 = (it->second)._s_store_name383;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n{};
                memcpy(_s_store_name383_n.data(), (_s_store_name383).data(), (_s_store_name383).length());
                std::string _s_zip403 = (it->second)._s_zip403;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n{};
                memcpy(_s_zip403_n.data(), (_s_zip403).data(), (_s_zip403).length());
                int32_t _c_current_hdemo_sk3 = (it->second)._c_current_hdemo_sk3;
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                int32_t _d_year3576 = (it->second)._d_year3576;
                int32_t _d_year3604 = (it->second)._d_year3604;
                int32_t _p_promo_sk294 = tbl_Filter_TD_12174597_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_11526036_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_11526036_output.setInt32(r, 1, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_11526036_output.setInt32(r, 2, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_11526036_output.setInt64(r, 3, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_11526036_output.setInt64(r, 4, _ss_list_price1218);
                tbl_JOIN_INNER_TD_11526036_output.setInt64(r, 5, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_11526036_output.setInt32(r, 6, _d_year126);
                tbl_JOIN_INNER_TD_11526036_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_store_name383_n);
                tbl_JOIN_INNER_TD_11526036_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _s_zip403_n);
                tbl_JOIN_INNER_TD_11526036_output.setInt32(r, 9, _c_current_hdemo_sk3);
                tbl_JOIN_INNER_TD_11526036_output.setInt32(r, 10, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_11526036_output.setInt32(r, 11, _d_year3576);
                tbl_JOIN_INNER_TD_11526036_output.setInt32(r, 12, _d_year3604);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11526036_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11526036_key_rightMajor, SW_JOIN_INNER_TD_11526036_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_12174597_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _p_promo_sk294_k = tbl_Filter_TD_12174597_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_11526036_key_rightMajor keyA{_p_promo_sk294_k};
            int32_t _p_promo_sk294 = tbl_Filter_TD_12174597_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_11526036_payload_rightMajor payloadA{_p_promo_sk294};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_12115296_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_promo_sk1214_k = tbl_JOIN_INNER_TD_12115296_output.getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11526036_key_rightMajor{_ss_promo_sk1214_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _p_promo_sk294 = (it->second)._p_promo_sk294;
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_12115296_output.getInt32(i, 0);
                int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_12115296_output.getInt32(i, 1);
                int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_12115296_output.getInt32(i, 2);
                int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_12115296_output.getInt32(i, 3);
                int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_12115296_output.getInt64(i, 4);
                int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_12115296_output.getInt64(i, 5);
                int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_12115296_output.getInt64(i, 6);
                int32_t _d_year126 = tbl_JOIN_INNER_TD_12115296_output.getInt32(i, 7);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_12115296_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
                std::string _s_store_name383 = std::string(_s_store_name383_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_12115296_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
                std::string _s_zip403 = std::string(_s_zip403_n.data());
                int32_t _c_current_hdemo_sk3 = tbl_JOIN_INNER_TD_12115296_output.getInt32(i, 10);
                int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_12115296_output.getInt32(i, 11);
                int32_t _d_year3576 = tbl_JOIN_INNER_TD_12115296_output.getInt32(i, 12);
                int32_t _d_year3604 = tbl_JOIN_INNER_TD_12115296_output.getInt32(i, 13);
                tbl_JOIN_INNER_TD_11526036_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_11526036_output.setInt32(r, 1, _ss_hdemo_sk1211);
                tbl_JOIN_INNER_TD_11526036_output.setInt32(r, 2, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_11526036_output.setInt64(r, 3, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_11526036_output.setInt64(r, 4, _ss_list_price1218);
                tbl_JOIN_INNER_TD_11526036_output.setInt64(r, 5, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_11526036_output.setInt32(r, 6, _d_year126);
                tbl_JOIN_INNER_TD_11526036_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_store_name383_n);
                tbl_JOIN_INNER_TD_11526036_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _s_zip403_n);
                tbl_JOIN_INNER_TD_11526036_output.setInt32(r, 9, _c_current_hdemo_sk3);
                tbl_JOIN_INNER_TD_11526036_output.setInt32(r, 10, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_11526036_output.setInt32(r, 11, _d_year3576);
                tbl_JOIN_INNER_TD_11526036_output.setInt32(r, 12, _d_year3604);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11526036_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_11526036_output #Row: " << tbl_JOIN_INNER_TD_11526036_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10762193(Table &tbl_SerializeFromObject_TD_11758762_input, Table &tbl_Filter_TD_10762193_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(hd_demo_sk#5035) AND isnotnull(hd_income_band_sk#5036)))
    // Input: ListBuffer(hd_demo_sk#5035, hd_income_band_sk#5036)
    // Output: ListBuffer(hd_demo_sk#5035, hd_income_band_sk#5036)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11758762_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _hd_demo_sk5035 = tbl_SerializeFromObject_TD_11758762_input.getInt32(i, 0);
        int32_t _hd_income_band_sk5036 = tbl_SerializeFromObject_TD_11758762_input.getInt32(i, 1);
        if ((_hd_demo_sk5035!= 0) && (_hd_income_band_sk5036!= 0)) {
            int32_t _hd_demo_sk5035_t = tbl_SerializeFromObject_TD_11758762_input.getInt32(i, 0);
            tbl_Filter_TD_10762193_output.setInt32(r, 0, _hd_demo_sk5035_t);
            int32_t _hd_income_band_sk5036_t = tbl_SerializeFromObject_TD_11758762_input.getInt32(i, 1);
            tbl_Filter_TD_10762193_output.setInt32(r, 1, _hd_income_band_sk5036_t);
            r++;
        }
    }
    tbl_Filter_TD_10762193_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10762193_output #Row: " << tbl_Filter_TD_10762193_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_10951912_key_leftMajor {
    int32_t _ss_hdemo_sk4763;
    bool operator==(const SW_JOIN_INNER_TD_10951912_key_leftMajor& other) const {
        return ((_ss_hdemo_sk4763 == other._ss_hdemo_sk4763));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10951912_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10951912_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_hdemo_sk4763));
    }
};
}
struct SW_JOIN_INNER_TD_10951912_payload_leftMajor {
    int32_t _ss_item_sk4760;
    int32_t _ss_hdemo_sk4763;
    int32_t _ss_addr_sk4764;
    int64_t _ss_wholesale_cost4769;
    int64_t _ss_list_price4770;
    int64_t _ss_coupon_amt4777;
    int32_t _d_year4868;
    std::string _s_store_name4951;
    std::string _s_zip4971;
    int32_t _c_current_hdemo_sk4978;
    int32_t _c_current_addr_sk4979;
    int32_t _d_year4896;
    int32_t _d_year4924;
};
struct SW_JOIN_INNER_TD_10951912_key_rightMajor {
    int32_t _hd_demo_sk5030;
    bool operator==(const SW_JOIN_INNER_TD_10951912_key_rightMajor& other) const {
        return ((_hd_demo_sk5030 == other._hd_demo_sk5030));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10951912_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10951912_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._hd_demo_sk5030));
    }
};
}
struct SW_JOIN_INNER_TD_10951912_payload_rightMajor {
    int32_t _hd_demo_sk5030;
    int32_t _hd_income_band_sk5031;
};
void SW_JOIN_INNER_TD_10951912(Table &tbl_JOIN_INNER_TD_11493165_output, Table &tbl_Filter_TD_11557957_output, Table &tbl_JOIN_INNER_TD_10951912_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_hdemo_sk#4763 = hd_demo_sk#5030))
    // Left Table: ListBuffer(ss_item_sk#4760, ss_hdemo_sk#4763, ss_addr_sk#4764, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971, c_current_hdemo_sk#4978, c_current_addr_sk#4979, d_year#4896, d_year#4924)
    // Right Table: ListBuffer(hd_demo_sk#5030, hd_income_band_sk#5031)
    // Output Table: ListBuffer(ss_item_sk#4760, ss_addr_sk#4764, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971, c_current_hdemo_sk#4978, c_current_addr_sk#4979, d_year#4896, d_year#4924, hd_income_band_sk#5031)
    int left_nrow = tbl_JOIN_INNER_TD_11493165_output.getNumRow();
    int right_nrow = tbl_Filter_TD_11557957_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10951912_key_leftMajor, SW_JOIN_INNER_TD_10951912_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_11493165_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_hdemo_sk4763_k = tbl_JOIN_INNER_TD_11493165_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_10951912_key_leftMajor keyA{_ss_hdemo_sk4763_k};
            int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_11493165_output.getInt32(i, 0);
            int32_t _ss_hdemo_sk4763 = tbl_JOIN_INNER_TD_11493165_output.getInt32(i, 1);
            int32_t _ss_addr_sk4764 = tbl_JOIN_INNER_TD_11493165_output.getInt32(i, 2);
            int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_11493165_output.getInt64(i, 3);
            int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_11493165_output.getInt64(i, 4);
            int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_11493165_output.getInt64(i, 5);
            int32_t _d_year4868 = tbl_JOIN_INNER_TD_11493165_output.getInt32(i, 6);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_11493165_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_11493165_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
            std::string _s_zip4971 = std::string(_s_zip4971_n.data());
            int32_t _c_current_hdemo_sk4978 = tbl_JOIN_INNER_TD_11493165_output.getInt32(i, 9);
            int32_t _c_current_addr_sk4979 = tbl_JOIN_INNER_TD_11493165_output.getInt32(i, 10);
            int32_t _d_year4896 = tbl_JOIN_INNER_TD_11493165_output.getInt32(i, 11);
            int32_t _d_year4924 = tbl_JOIN_INNER_TD_11493165_output.getInt32(i, 12);
            SW_JOIN_INNER_TD_10951912_payload_leftMajor payloadA{_ss_item_sk4760, _ss_hdemo_sk4763, _ss_addr_sk4764, _ss_wholesale_cost4769, _ss_list_price4770, _ss_coupon_amt4777, _d_year4868, _s_store_name4951, _s_zip4971, _c_current_hdemo_sk4978, _c_current_addr_sk4979, _d_year4896, _d_year4924};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_11557957_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _hd_demo_sk5030_k = tbl_Filter_TD_11557957_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10951912_key_leftMajor{_hd_demo_sk5030_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk4760 = (it->second)._ss_item_sk4760;
                int32_t _ss_hdemo_sk4763 = (it->second)._ss_hdemo_sk4763;
                int32_t _ss_addr_sk4764 = (it->second)._ss_addr_sk4764;
                int64_t _ss_wholesale_cost4769 = (it->second)._ss_wholesale_cost4769;
                int64_t _ss_list_price4770 = (it->second)._ss_list_price4770;
                int64_t _ss_coupon_amt4777 = (it->second)._ss_coupon_amt4777;
                int32_t _d_year4868 = (it->second)._d_year4868;
                std::string _s_store_name4951 = (it->second)._s_store_name4951;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n{};
                memcpy(_s_store_name4951_n.data(), (_s_store_name4951).data(), (_s_store_name4951).length());
                std::string _s_zip4971 = (it->second)._s_zip4971;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n{};
                memcpy(_s_zip4971_n.data(), (_s_zip4971).data(), (_s_zip4971).length());
                int32_t _c_current_hdemo_sk4978 = (it->second)._c_current_hdemo_sk4978;
                int32_t _c_current_addr_sk4979 = (it->second)._c_current_addr_sk4979;
                int32_t _d_year4896 = (it->second)._d_year4896;
                int32_t _d_year4924 = (it->second)._d_year4924;
                int32_t _hd_demo_sk5030 = tbl_Filter_TD_11557957_output.getInt32(i, 0);
                int32_t _hd_income_band_sk5031 = tbl_Filter_TD_11557957_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_10951912_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_10951912_output.setInt32(r, 1, _ss_addr_sk4764);
                tbl_JOIN_INNER_TD_10951912_output.setInt64(r, 2, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_10951912_output.setInt64(r, 3, _ss_list_price4770);
                tbl_JOIN_INNER_TD_10951912_output.setInt64(r, 4, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_10951912_output.setInt32(r, 5, _d_year4868);
                tbl_JOIN_INNER_TD_10951912_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_10951912_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_zip4971_n);
                tbl_JOIN_INNER_TD_10951912_output.setInt32(r, 8, _c_current_hdemo_sk4978);
                tbl_JOIN_INNER_TD_10951912_output.setInt32(r, 9, _c_current_addr_sk4979);
                tbl_JOIN_INNER_TD_10951912_output.setInt32(r, 10, _d_year4896);
                tbl_JOIN_INNER_TD_10951912_output.setInt32(r, 11, _d_year4924);
                tbl_JOIN_INNER_TD_10951912_output.setInt32(r, 12, _hd_income_band_sk5031);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10951912_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10951912_key_rightMajor, SW_JOIN_INNER_TD_10951912_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_11557957_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _hd_demo_sk5030_k = tbl_Filter_TD_11557957_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_10951912_key_rightMajor keyA{_hd_demo_sk5030_k};
            int32_t _hd_demo_sk5030 = tbl_Filter_TD_11557957_output.getInt32(i, 0);
            int32_t _hd_income_band_sk5031 = tbl_Filter_TD_11557957_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_10951912_payload_rightMajor payloadA{_hd_demo_sk5030, _hd_income_band_sk5031};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_11493165_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_hdemo_sk4763_k = tbl_JOIN_INNER_TD_11493165_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10951912_key_rightMajor{_ss_hdemo_sk4763_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _hd_demo_sk5030 = (it->second)._hd_demo_sk5030;
                int32_t _hd_income_band_sk5031 = (it->second)._hd_income_band_sk5031;
                int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_11493165_output.getInt32(i, 0);
                int32_t _ss_hdemo_sk4763 = tbl_JOIN_INNER_TD_11493165_output.getInt32(i, 1);
                int32_t _ss_addr_sk4764 = tbl_JOIN_INNER_TD_11493165_output.getInt32(i, 2);
                int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_11493165_output.getInt64(i, 3);
                int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_11493165_output.getInt64(i, 4);
                int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_11493165_output.getInt64(i, 5);
                int32_t _d_year4868 = tbl_JOIN_INNER_TD_11493165_output.getInt32(i, 6);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_11493165_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_11493165_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
                std::string _s_zip4971 = std::string(_s_zip4971_n.data());
                int32_t _c_current_hdemo_sk4978 = tbl_JOIN_INNER_TD_11493165_output.getInt32(i, 9);
                int32_t _c_current_addr_sk4979 = tbl_JOIN_INNER_TD_11493165_output.getInt32(i, 10);
                int32_t _d_year4896 = tbl_JOIN_INNER_TD_11493165_output.getInt32(i, 11);
                int32_t _d_year4924 = tbl_JOIN_INNER_TD_11493165_output.getInt32(i, 12);
                tbl_JOIN_INNER_TD_10951912_output.setInt32(r, 12, _hd_income_band_sk5031);
                tbl_JOIN_INNER_TD_10951912_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_10951912_output.setInt32(r, 1, _ss_addr_sk4764);
                tbl_JOIN_INNER_TD_10951912_output.setInt64(r, 2, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_10951912_output.setInt64(r, 3, _ss_list_price4770);
                tbl_JOIN_INNER_TD_10951912_output.setInt64(r, 4, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_10951912_output.setInt32(r, 5, _d_year4868);
                tbl_JOIN_INNER_TD_10951912_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_10951912_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_zip4971_n);
                tbl_JOIN_INNER_TD_10951912_output.setInt32(r, 8, _c_current_hdemo_sk4978);
                tbl_JOIN_INNER_TD_10951912_output.setInt32(r, 9, _c_current_addr_sk4979);
                tbl_JOIN_INNER_TD_10951912_output.setInt32(r, 10, _d_year4896);
                tbl_JOIN_INNER_TD_10951912_output.setInt32(r, 11, _d_year4924);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10951912_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_10951912_output #Row: " << tbl_JOIN_INNER_TD_10951912_output.getNumRow() << std::endl;
}

void SW_Filter_TD_1015392(Table &tbl_SerializeFromObject_TD_11703170_input, Table &tbl_Filter_TD_1015392_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(hd_demo_sk#3635) AND isnotnull(hd_income_band_sk#3636)))
    // Input: ListBuffer(hd_demo_sk#3635, hd_income_band_sk#3636)
    // Output: ListBuffer(hd_demo_sk#3635, hd_income_band_sk#3636)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11703170_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _hd_demo_sk3635 = tbl_SerializeFromObject_TD_11703170_input.getInt32(i, 0);
        int32_t _hd_income_band_sk3636 = tbl_SerializeFromObject_TD_11703170_input.getInt32(i, 1);
        if ((_hd_demo_sk3635!= 0) && (_hd_income_band_sk3636!= 0)) {
            int32_t _hd_demo_sk3635_t = tbl_SerializeFromObject_TD_11703170_input.getInt32(i, 0);
            tbl_Filter_TD_1015392_output.setInt32(r, 0, _hd_demo_sk3635_t);
            int32_t _hd_income_band_sk3636_t = tbl_SerializeFromObject_TD_11703170_input.getInt32(i, 1);
            tbl_Filter_TD_1015392_output.setInt32(r, 1, _hd_income_band_sk3636_t);
            r++;
        }
    }
    tbl_Filter_TD_1015392_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1015392_output #Row: " << tbl_Filter_TD_1015392_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_10446614_key_leftMajor {
    int32_t _ss_hdemo_sk1211;
    bool operator==(const SW_JOIN_INNER_TD_10446614_key_leftMajor& other) const {
        return ((_ss_hdemo_sk1211 == other._ss_hdemo_sk1211));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10446614_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10446614_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_hdemo_sk1211));
    }
};
}
struct SW_JOIN_INNER_TD_10446614_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int32_t _ss_hdemo_sk1211;
    int32_t _ss_addr_sk1212;
    int64_t _ss_wholesale_cost1217;
    int64_t _ss_list_price1218;
    int64_t _ss_coupon_amt1225;
    int32_t _d_year126;
    std::string _s_store_name383;
    std::string _s_zip403;
    int32_t _c_current_hdemo_sk3;
    int32_t _c_current_addr_sk4;
    int32_t _d_year3576;
    int32_t _d_year3604;
};
struct SW_JOIN_INNER_TD_10446614_key_rightMajor {
    int32_t _hd_demo_sk204;
    bool operator==(const SW_JOIN_INNER_TD_10446614_key_rightMajor& other) const {
        return ((_hd_demo_sk204 == other._hd_demo_sk204));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10446614_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10446614_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._hd_demo_sk204));
    }
};
}
struct SW_JOIN_INNER_TD_10446614_payload_rightMajor {
    int32_t _hd_demo_sk204;
    int32_t _hd_income_band_sk205;
};
void SW_JOIN_INNER_TD_10446614(Table &tbl_JOIN_INNER_TD_11526036_output, Table &tbl_Filter_TD_1117050_output, Table &tbl_JOIN_INNER_TD_10446614_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_hdemo_sk#1211 = hd_demo_sk#204))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403, c_current_hdemo_sk#3, c_current_addr_sk#4, d_year#3576, d_year#3604)
    // Right Table: ListBuffer(hd_demo_sk#204, hd_income_band_sk#205)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_addr_sk#1212, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403, c_current_hdemo_sk#3, c_current_addr_sk#4, d_year#3576, d_year#3604, hd_income_band_sk#205)
    int left_nrow = tbl_JOIN_INNER_TD_11526036_output.getNumRow();
    int right_nrow = tbl_Filter_TD_1117050_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10446614_key_leftMajor, SW_JOIN_INNER_TD_10446614_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_11526036_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_hdemo_sk1211_k = tbl_JOIN_INNER_TD_11526036_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_10446614_key_leftMajor keyA{_ss_hdemo_sk1211_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_11526036_output.getInt32(i, 0);
            int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_11526036_output.getInt32(i, 1);
            int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_11526036_output.getInt32(i, 2);
            int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_11526036_output.getInt64(i, 3);
            int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_11526036_output.getInt64(i, 4);
            int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_11526036_output.getInt64(i, 5);
            int32_t _d_year126 = tbl_JOIN_INNER_TD_11526036_output.getInt32(i, 6);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_11526036_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _s_store_name383 = std::string(_s_store_name383_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_11526036_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
            std::string _s_zip403 = std::string(_s_zip403_n.data());
            int32_t _c_current_hdemo_sk3 = tbl_JOIN_INNER_TD_11526036_output.getInt32(i, 9);
            int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_11526036_output.getInt32(i, 10);
            int32_t _d_year3576 = tbl_JOIN_INNER_TD_11526036_output.getInt32(i, 11);
            int32_t _d_year3604 = tbl_JOIN_INNER_TD_11526036_output.getInt32(i, 12);
            SW_JOIN_INNER_TD_10446614_payload_leftMajor payloadA{_ss_item_sk1208, _ss_hdemo_sk1211, _ss_addr_sk1212, _ss_wholesale_cost1217, _ss_list_price1218, _ss_coupon_amt1225, _d_year126, _s_store_name383, _s_zip403, _c_current_hdemo_sk3, _c_current_addr_sk4, _d_year3576, _d_year3604};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_1117050_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _hd_demo_sk204_k = tbl_Filter_TD_1117050_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10446614_key_leftMajor{_hd_demo_sk204_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_hdemo_sk1211 = (it->second)._ss_hdemo_sk1211;
                int32_t _ss_addr_sk1212 = (it->second)._ss_addr_sk1212;
                int64_t _ss_wholesale_cost1217 = (it->second)._ss_wholesale_cost1217;
                int64_t _ss_list_price1218 = (it->second)._ss_list_price1218;
                int64_t _ss_coupon_amt1225 = (it->second)._ss_coupon_amt1225;
                int32_t _d_year126 = (it->second)._d_year126;
                std::string _s_store_name383 = (it->second)._s_store_name383;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n{};
                memcpy(_s_store_name383_n.data(), (_s_store_name383).data(), (_s_store_name383).length());
                std::string _s_zip403 = (it->second)._s_zip403;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n{};
                memcpy(_s_zip403_n.data(), (_s_zip403).data(), (_s_zip403).length());
                int32_t _c_current_hdemo_sk3 = (it->second)._c_current_hdemo_sk3;
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                int32_t _d_year3576 = (it->second)._d_year3576;
                int32_t _d_year3604 = (it->second)._d_year3604;
                int32_t _hd_demo_sk204 = tbl_Filter_TD_1117050_output.getInt32(i, 0);
                int32_t _hd_income_band_sk205 = tbl_Filter_TD_1117050_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_10446614_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_10446614_output.setInt32(r, 1, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_10446614_output.setInt64(r, 2, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_10446614_output.setInt64(r, 3, _ss_list_price1218);
                tbl_JOIN_INNER_TD_10446614_output.setInt64(r, 4, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_10446614_output.setInt32(r, 5, _d_year126);
                tbl_JOIN_INNER_TD_10446614_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_store_name383_n);
                tbl_JOIN_INNER_TD_10446614_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_zip403_n);
                tbl_JOIN_INNER_TD_10446614_output.setInt32(r, 8, _c_current_hdemo_sk3);
                tbl_JOIN_INNER_TD_10446614_output.setInt32(r, 9, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_10446614_output.setInt32(r, 10, _d_year3576);
                tbl_JOIN_INNER_TD_10446614_output.setInt32(r, 11, _d_year3604);
                tbl_JOIN_INNER_TD_10446614_output.setInt32(r, 12, _hd_income_band_sk205);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10446614_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10446614_key_rightMajor, SW_JOIN_INNER_TD_10446614_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_1117050_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _hd_demo_sk204_k = tbl_Filter_TD_1117050_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_10446614_key_rightMajor keyA{_hd_demo_sk204_k};
            int32_t _hd_demo_sk204 = tbl_Filter_TD_1117050_output.getInt32(i, 0);
            int32_t _hd_income_band_sk205 = tbl_Filter_TD_1117050_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_10446614_payload_rightMajor payloadA{_hd_demo_sk204, _hd_income_band_sk205};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_11526036_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_hdemo_sk1211_k = tbl_JOIN_INNER_TD_11526036_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10446614_key_rightMajor{_ss_hdemo_sk1211_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _hd_demo_sk204 = (it->second)._hd_demo_sk204;
                int32_t _hd_income_band_sk205 = (it->second)._hd_income_band_sk205;
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_11526036_output.getInt32(i, 0);
                int32_t _ss_hdemo_sk1211 = tbl_JOIN_INNER_TD_11526036_output.getInt32(i, 1);
                int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_11526036_output.getInt32(i, 2);
                int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_11526036_output.getInt64(i, 3);
                int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_11526036_output.getInt64(i, 4);
                int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_11526036_output.getInt64(i, 5);
                int32_t _d_year126 = tbl_JOIN_INNER_TD_11526036_output.getInt32(i, 6);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_11526036_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _s_store_name383 = std::string(_s_store_name383_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_11526036_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
                std::string _s_zip403 = std::string(_s_zip403_n.data());
                int32_t _c_current_hdemo_sk3 = tbl_JOIN_INNER_TD_11526036_output.getInt32(i, 9);
                int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_11526036_output.getInt32(i, 10);
                int32_t _d_year3576 = tbl_JOIN_INNER_TD_11526036_output.getInt32(i, 11);
                int32_t _d_year3604 = tbl_JOIN_INNER_TD_11526036_output.getInt32(i, 12);
                tbl_JOIN_INNER_TD_10446614_output.setInt32(r, 12, _hd_income_band_sk205);
                tbl_JOIN_INNER_TD_10446614_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_10446614_output.setInt32(r, 1, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_10446614_output.setInt64(r, 2, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_10446614_output.setInt64(r, 3, _ss_list_price1218);
                tbl_JOIN_INNER_TD_10446614_output.setInt64(r, 4, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_10446614_output.setInt32(r, 5, _d_year126);
                tbl_JOIN_INNER_TD_10446614_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_store_name383_n);
                tbl_JOIN_INNER_TD_10446614_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_zip403_n);
                tbl_JOIN_INNER_TD_10446614_output.setInt32(r, 8, _c_current_hdemo_sk3);
                tbl_JOIN_INNER_TD_10446614_output.setInt32(r, 9, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_10446614_output.setInt32(r, 10, _d_year3576);
                tbl_JOIN_INNER_TD_10446614_output.setInt32(r, 11, _d_year3604);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10446614_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_10446614_output #Row: " << tbl_JOIN_INNER_TD_10446614_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9328766(Table &tbl_SerializeFromObject_TD_10706938_input, Table &tbl_Filter_TD_9328766_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ca_address_sk#5040))
    // Input: ListBuffer(ca_address_sk#5040, ca_street_number#5042, ca_street_name#5043, ca_city#5046, ca_zip#5049)
    // Output: ListBuffer(ca_address_sk#5040, ca_street_number#5042, ca_street_name#5043, ca_city#5046, ca_zip#5049)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10706938_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ca_address_sk5040 = tbl_SerializeFromObject_TD_10706938_input.getInt32(i, 0);
        if (_ca_address_sk5040!= 0) {
            int32_t _ca_address_sk5040_t = tbl_SerializeFromObject_TD_10706938_input.getInt32(i, 0);
            tbl_Filter_TD_9328766_output.setInt32(r, 0, _ca_address_sk5040_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5042_t = tbl_SerializeFromObject_TD_10706938_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_9328766_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_street_number5042_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5043_t = tbl_SerializeFromObject_TD_10706938_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_9328766_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_street_name5043_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_city5046_t = tbl_SerializeFromObject_TD_10706938_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_9328766_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_city5046_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip5049_t = tbl_SerializeFromObject_TD_10706938_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            tbl_Filter_TD_9328766_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _ca_zip5049_t);
            r++;
        }
    }
    tbl_Filter_TD_9328766_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9328766_output #Row: " << tbl_Filter_TD_9328766_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_9425844_key_leftMajor {
    int32_t _c_current_hdemo_sk4978;
    bool operator==(const SW_JOIN_INNER_TD_9425844_key_leftMajor& other) const {
        return ((_c_current_hdemo_sk4978 == other._c_current_hdemo_sk4978));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9425844_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9425844_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_current_hdemo_sk4978));
    }
};
}
struct SW_JOIN_INNER_TD_9425844_payload_leftMajor {
    int32_t _ss_item_sk4760;
    int32_t _ss_addr_sk4764;
    int64_t _ss_wholesale_cost4769;
    int64_t _ss_list_price4770;
    int64_t _ss_coupon_amt4777;
    int32_t _d_year4868;
    std::string _s_store_name4951;
    std::string _s_zip4971;
    int32_t _c_current_hdemo_sk4978;
    int32_t _c_current_addr_sk4979;
    int32_t _d_year4896;
    int32_t _d_year4924;
    int32_t _hd_income_band_sk5031;
};
struct SW_JOIN_INNER_TD_9425844_key_rightMajor {
    int32_t _hd_demo_sk5035;
    bool operator==(const SW_JOIN_INNER_TD_9425844_key_rightMajor& other) const {
        return ((_hd_demo_sk5035 == other._hd_demo_sk5035));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9425844_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9425844_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._hd_demo_sk5035));
    }
};
}
struct SW_JOIN_INNER_TD_9425844_payload_rightMajor {
    int32_t _hd_demo_sk5035;
    int32_t _hd_income_band_sk5036;
};
void SW_JOIN_INNER_TD_9425844(Table &tbl_JOIN_INNER_TD_10951912_output, Table &tbl_Filter_TD_10762193_output, Table &tbl_JOIN_INNER_TD_9425844_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((c_current_hdemo_sk#4978 = hd_demo_sk#5035))
    // Left Table: ListBuffer(ss_item_sk#4760, ss_addr_sk#4764, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971, c_current_hdemo_sk#4978, c_current_addr_sk#4979, d_year#4896, d_year#4924, hd_income_band_sk#5031)
    // Right Table: ListBuffer(hd_demo_sk#5035, hd_income_band_sk#5036)
    // Output Table: ListBuffer(ss_item_sk#4760, ss_addr_sk#4764, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971, c_current_addr_sk#4979, d_year#4896, d_year#4924, hd_income_band_sk#5031, hd_income_band_sk#5036)
    int left_nrow = tbl_JOIN_INNER_TD_10951912_output.getNumRow();
    int right_nrow = tbl_Filter_TD_10762193_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9425844_key_leftMajor, SW_JOIN_INNER_TD_9425844_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_10951912_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_current_hdemo_sk4978_k = tbl_JOIN_INNER_TD_10951912_output.getInt32(i, 8);
            SW_JOIN_INNER_TD_9425844_key_leftMajor keyA{_c_current_hdemo_sk4978_k};
            int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_10951912_output.getInt32(i, 0);
            int32_t _ss_addr_sk4764 = tbl_JOIN_INNER_TD_10951912_output.getInt32(i, 1);
            int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_10951912_output.getInt64(i, 2);
            int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_10951912_output.getInt64(i, 3);
            int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_10951912_output.getInt64(i, 4);
            int32_t _d_year4868 = tbl_JOIN_INNER_TD_10951912_output.getInt32(i, 5);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_10951912_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_10951912_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _s_zip4971 = std::string(_s_zip4971_n.data());
            int32_t _c_current_hdemo_sk4978 = tbl_JOIN_INNER_TD_10951912_output.getInt32(i, 8);
            int32_t _c_current_addr_sk4979 = tbl_JOIN_INNER_TD_10951912_output.getInt32(i, 9);
            int32_t _d_year4896 = tbl_JOIN_INNER_TD_10951912_output.getInt32(i, 10);
            int32_t _d_year4924 = tbl_JOIN_INNER_TD_10951912_output.getInt32(i, 11);
            int32_t _hd_income_band_sk5031 = tbl_JOIN_INNER_TD_10951912_output.getInt32(i, 12);
            SW_JOIN_INNER_TD_9425844_payload_leftMajor payloadA{_ss_item_sk4760, _ss_addr_sk4764, _ss_wholesale_cost4769, _ss_list_price4770, _ss_coupon_amt4777, _d_year4868, _s_store_name4951, _s_zip4971, _c_current_hdemo_sk4978, _c_current_addr_sk4979, _d_year4896, _d_year4924, _hd_income_band_sk5031};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_10762193_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _hd_demo_sk5035_k = tbl_Filter_TD_10762193_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9425844_key_leftMajor{_hd_demo_sk5035_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk4760 = (it->second)._ss_item_sk4760;
                int32_t _ss_addr_sk4764 = (it->second)._ss_addr_sk4764;
                int64_t _ss_wholesale_cost4769 = (it->second)._ss_wholesale_cost4769;
                int64_t _ss_list_price4770 = (it->second)._ss_list_price4770;
                int64_t _ss_coupon_amt4777 = (it->second)._ss_coupon_amt4777;
                int32_t _d_year4868 = (it->second)._d_year4868;
                std::string _s_store_name4951 = (it->second)._s_store_name4951;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n{};
                memcpy(_s_store_name4951_n.data(), (_s_store_name4951).data(), (_s_store_name4951).length());
                std::string _s_zip4971 = (it->second)._s_zip4971;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n{};
                memcpy(_s_zip4971_n.data(), (_s_zip4971).data(), (_s_zip4971).length());
                int32_t _c_current_hdemo_sk4978 = (it->second)._c_current_hdemo_sk4978;
                int32_t _c_current_addr_sk4979 = (it->second)._c_current_addr_sk4979;
                int32_t _d_year4896 = (it->second)._d_year4896;
                int32_t _d_year4924 = (it->second)._d_year4924;
                int32_t _hd_income_band_sk5031 = (it->second)._hd_income_band_sk5031;
                int32_t _hd_demo_sk5035 = tbl_Filter_TD_10762193_output.getInt32(i, 0);
                int32_t _hd_income_band_sk5036 = tbl_Filter_TD_10762193_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_9425844_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_9425844_output.setInt32(r, 1, _ss_addr_sk4764);
                tbl_JOIN_INNER_TD_9425844_output.setInt64(r, 2, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_9425844_output.setInt64(r, 3, _ss_list_price4770);
                tbl_JOIN_INNER_TD_9425844_output.setInt64(r, 4, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_9425844_output.setInt32(r, 5, _d_year4868);
                tbl_JOIN_INNER_TD_9425844_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_9425844_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_zip4971_n);
                tbl_JOIN_INNER_TD_9425844_output.setInt32(r, 8, _c_current_addr_sk4979);
                tbl_JOIN_INNER_TD_9425844_output.setInt32(r, 9, _d_year4896);
                tbl_JOIN_INNER_TD_9425844_output.setInt32(r, 10, _d_year4924);
                tbl_JOIN_INNER_TD_9425844_output.setInt32(r, 11, _hd_income_band_sk5031);
                tbl_JOIN_INNER_TD_9425844_output.setInt32(r, 12, _hd_income_band_sk5036);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9425844_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9425844_key_rightMajor, SW_JOIN_INNER_TD_9425844_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_10762193_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _hd_demo_sk5035_k = tbl_Filter_TD_10762193_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_9425844_key_rightMajor keyA{_hd_demo_sk5035_k};
            int32_t _hd_demo_sk5035 = tbl_Filter_TD_10762193_output.getInt32(i, 0);
            int32_t _hd_income_band_sk5036 = tbl_Filter_TD_10762193_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_9425844_payload_rightMajor payloadA{_hd_demo_sk5035, _hd_income_band_sk5036};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_10951912_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_current_hdemo_sk4978_k = tbl_JOIN_INNER_TD_10951912_output.getInt32(i, 8);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9425844_key_rightMajor{_c_current_hdemo_sk4978_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _hd_demo_sk5035 = (it->second)._hd_demo_sk5035;
                int32_t _hd_income_band_sk5036 = (it->second)._hd_income_band_sk5036;
                int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_10951912_output.getInt32(i, 0);
                int32_t _ss_addr_sk4764 = tbl_JOIN_INNER_TD_10951912_output.getInt32(i, 1);
                int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_10951912_output.getInt64(i, 2);
                int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_10951912_output.getInt64(i, 3);
                int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_10951912_output.getInt64(i, 4);
                int32_t _d_year4868 = tbl_JOIN_INNER_TD_10951912_output.getInt32(i, 5);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_10951912_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_10951912_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _s_zip4971 = std::string(_s_zip4971_n.data());
                int32_t _c_current_hdemo_sk4978 = tbl_JOIN_INNER_TD_10951912_output.getInt32(i, 8);
                int32_t _c_current_addr_sk4979 = tbl_JOIN_INNER_TD_10951912_output.getInt32(i, 9);
                int32_t _d_year4896 = tbl_JOIN_INNER_TD_10951912_output.getInt32(i, 10);
                int32_t _d_year4924 = tbl_JOIN_INNER_TD_10951912_output.getInt32(i, 11);
                int32_t _hd_income_band_sk5031 = tbl_JOIN_INNER_TD_10951912_output.getInt32(i, 12);
                tbl_JOIN_INNER_TD_9425844_output.setInt32(r, 12, _hd_income_band_sk5036);
                tbl_JOIN_INNER_TD_9425844_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_9425844_output.setInt32(r, 1, _ss_addr_sk4764);
                tbl_JOIN_INNER_TD_9425844_output.setInt64(r, 2, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_9425844_output.setInt64(r, 3, _ss_list_price4770);
                tbl_JOIN_INNER_TD_9425844_output.setInt64(r, 4, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_9425844_output.setInt32(r, 5, _d_year4868);
                tbl_JOIN_INNER_TD_9425844_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_9425844_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_zip4971_n);
                tbl_JOIN_INNER_TD_9425844_output.setInt32(r, 8, _c_current_addr_sk4979);
                tbl_JOIN_INNER_TD_9425844_output.setInt32(r, 9, _d_year4896);
                tbl_JOIN_INNER_TD_9425844_output.setInt32(r, 10, _d_year4924);
                tbl_JOIN_INNER_TD_9425844_output.setInt32(r, 11, _hd_income_band_sk5031);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9425844_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_9425844_output #Row: " << tbl_JOIN_INNER_TD_9425844_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9772283(Table &tbl_SerializeFromObject_TD_1065428_input, Table &tbl_Filter_TD_9772283_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ca_address_sk#54))
    // Input: ListBuffer(ca_address_sk#54, ca_street_number#56, ca_street_name#57, ca_city#60, ca_zip#63)
    // Output: ListBuffer(ca_address_sk#54, ca_street_number#56, ca_street_name#57, ca_city#60, ca_zip#63)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1065428_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ca_address_sk54 = tbl_SerializeFromObject_TD_1065428_input.getInt32(i, 0);
        if (_ca_address_sk54!= 0) {
            int32_t _ca_address_sk54_t = tbl_SerializeFromObject_TD_1065428_input.getInt32(i, 0);
            tbl_Filter_TD_9772283_output.setInt32(r, 0, _ca_address_sk54_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_number56_t = tbl_SerializeFromObject_TD_1065428_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_9772283_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_street_number56_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_name57_t = tbl_SerializeFromObject_TD_1065428_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_9772283_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_street_name57_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_city60_t = tbl_SerializeFromObject_TD_1065428_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_9772283_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_city60_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_t = tbl_SerializeFromObject_TD_1065428_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            tbl_Filter_TD_9772283_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _ca_zip63_t);
            r++;
        }
    }
    tbl_Filter_TD_9772283_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9772283_output #Row: " << tbl_Filter_TD_9772283_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_9678884_key_leftMajor {
    int32_t _c_current_hdemo_sk3;
    bool operator==(const SW_JOIN_INNER_TD_9678884_key_leftMajor& other) const {
        return ((_c_current_hdemo_sk3 == other._c_current_hdemo_sk3));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9678884_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9678884_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_current_hdemo_sk3));
    }
};
}
struct SW_JOIN_INNER_TD_9678884_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int32_t _ss_addr_sk1212;
    int64_t _ss_wholesale_cost1217;
    int64_t _ss_list_price1218;
    int64_t _ss_coupon_amt1225;
    int32_t _d_year126;
    std::string _s_store_name383;
    std::string _s_zip403;
    int32_t _c_current_hdemo_sk3;
    int32_t _c_current_addr_sk4;
    int32_t _d_year3576;
    int32_t _d_year3604;
    int32_t _hd_income_band_sk205;
};
struct SW_JOIN_INNER_TD_9678884_key_rightMajor {
    int32_t _hd_demo_sk3635;
    bool operator==(const SW_JOIN_INNER_TD_9678884_key_rightMajor& other) const {
        return ((_hd_demo_sk3635 == other._hd_demo_sk3635));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9678884_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9678884_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._hd_demo_sk3635));
    }
};
}
struct SW_JOIN_INNER_TD_9678884_payload_rightMajor {
    int32_t _hd_demo_sk3635;
    int32_t _hd_income_band_sk3636;
};
void SW_JOIN_INNER_TD_9678884(Table &tbl_JOIN_INNER_TD_10446614_output, Table &tbl_Filter_TD_1015392_output, Table &tbl_JOIN_INNER_TD_9678884_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((c_current_hdemo_sk#3 = hd_demo_sk#3635))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_addr_sk#1212, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403, c_current_hdemo_sk#3, c_current_addr_sk#4, d_year#3576, d_year#3604, hd_income_band_sk#205)
    // Right Table: ListBuffer(hd_demo_sk#3635, hd_income_band_sk#3636)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_addr_sk#1212, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403, c_current_addr_sk#4, d_year#3576, d_year#3604, hd_income_band_sk#205, hd_income_band_sk#3636)
    int left_nrow = tbl_JOIN_INNER_TD_10446614_output.getNumRow();
    int right_nrow = tbl_Filter_TD_1015392_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9678884_key_leftMajor, SW_JOIN_INNER_TD_9678884_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_10446614_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_current_hdemo_sk3_k = tbl_JOIN_INNER_TD_10446614_output.getInt32(i, 8);
            SW_JOIN_INNER_TD_9678884_key_leftMajor keyA{_c_current_hdemo_sk3_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_10446614_output.getInt32(i, 0);
            int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_10446614_output.getInt32(i, 1);
            int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_10446614_output.getInt64(i, 2);
            int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_10446614_output.getInt64(i, 3);
            int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_10446614_output.getInt64(i, 4);
            int32_t _d_year126 = tbl_JOIN_INNER_TD_10446614_output.getInt32(i, 5);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_10446614_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _s_store_name383 = std::string(_s_store_name383_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_10446614_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _s_zip403 = std::string(_s_zip403_n.data());
            int32_t _c_current_hdemo_sk3 = tbl_JOIN_INNER_TD_10446614_output.getInt32(i, 8);
            int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_10446614_output.getInt32(i, 9);
            int32_t _d_year3576 = tbl_JOIN_INNER_TD_10446614_output.getInt32(i, 10);
            int32_t _d_year3604 = tbl_JOIN_INNER_TD_10446614_output.getInt32(i, 11);
            int32_t _hd_income_band_sk205 = tbl_JOIN_INNER_TD_10446614_output.getInt32(i, 12);
            SW_JOIN_INNER_TD_9678884_payload_leftMajor payloadA{_ss_item_sk1208, _ss_addr_sk1212, _ss_wholesale_cost1217, _ss_list_price1218, _ss_coupon_amt1225, _d_year126, _s_store_name383, _s_zip403, _c_current_hdemo_sk3, _c_current_addr_sk4, _d_year3576, _d_year3604, _hd_income_band_sk205};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_1015392_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _hd_demo_sk3635_k = tbl_Filter_TD_1015392_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9678884_key_leftMajor{_hd_demo_sk3635_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_addr_sk1212 = (it->second)._ss_addr_sk1212;
                int64_t _ss_wholesale_cost1217 = (it->second)._ss_wholesale_cost1217;
                int64_t _ss_list_price1218 = (it->second)._ss_list_price1218;
                int64_t _ss_coupon_amt1225 = (it->second)._ss_coupon_amt1225;
                int32_t _d_year126 = (it->second)._d_year126;
                std::string _s_store_name383 = (it->second)._s_store_name383;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n{};
                memcpy(_s_store_name383_n.data(), (_s_store_name383).data(), (_s_store_name383).length());
                std::string _s_zip403 = (it->second)._s_zip403;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n{};
                memcpy(_s_zip403_n.data(), (_s_zip403).data(), (_s_zip403).length());
                int32_t _c_current_hdemo_sk3 = (it->second)._c_current_hdemo_sk3;
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                int32_t _d_year3576 = (it->second)._d_year3576;
                int32_t _d_year3604 = (it->second)._d_year3604;
                int32_t _hd_income_band_sk205 = (it->second)._hd_income_band_sk205;
                int32_t _hd_demo_sk3635 = tbl_Filter_TD_1015392_output.getInt32(i, 0);
                int32_t _hd_income_band_sk3636 = tbl_Filter_TD_1015392_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_9678884_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_9678884_output.setInt32(r, 1, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_9678884_output.setInt64(r, 2, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_9678884_output.setInt64(r, 3, _ss_list_price1218);
                tbl_JOIN_INNER_TD_9678884_output.setInt64(r, 4, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_9678884_output.setInt32(r, 5, _d_year126);
                tbl_JOIN_INNER_TD_9678884_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_store_name383_n);
                tbl_JOIN_INNER_TD_9678884_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_zip403_n);
                tbl_JOIN_INNER_TD_9678884_output.setInt32(r, 8, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_9678884_output.setInt32(r, 9, _d_year3576);
                tbl_JOIN_INNER_TD_9678884_output.setInt32(r, 10, _d_year3604);
                tbl_JOIN_INNER_TD_9678884_output.setInt32(r, 11, _hd_income_band_sk205);
                tbl_JOIN_INNER_TD_9678884_output.setInt32(r, 12, _hd_income_band_sk3636);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9678884_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9678884_key_rightMajor, SW_JOIN_INNER_TD_9678884_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_1015392_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _hd_demo_sk3635_k = tbl_Filter_TD_1015392_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_9678884_key_rightMajor keyA{_hd_demo_sk3635_k};
            int32_t _hd_demo_sk3635 = tbl_Filter_TD_1015392_output.getInt32(i, 0);
            int32_t _hd_income_band_sk3636 = tbl_Filter_TD_1015392_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_9678884_payload_rightMajor payloadA{_hd_demo_sk3635, _hd_income_band_sk3636};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_10446614_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_current_hdemo_sk3_k = tbl_JOIN_INNER_TD_10446614_output.getInt32(i, 8);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9678884_key_rightMajor{_c_current_hdemo_sk3_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _hd_demo_sk3635 = (it->second)._hd_demo_sk3635;
                int32_t _hd_income_band_sk3636 = (it->second)._hd_income_band_sk3636;
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_10446614_output.getInt32(i, 0);
                int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_10446614_output.getInt32(i, 1);
                int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_10446614_output.getInt64(i, 2);
                int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_10446614_output.getInt64(i, 3);
                int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_10446614_output.getInt64(i, 4);
                int32_t _d_year126 = tbl_JOIN_INNER_TD_10446614_output.getInt32(i, 5);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_10446614_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _s_store_name383 = std::string(_s_store_name383_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_10446614_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _s_zip403 = std::string(_s_zip403_n.data());
                int32_t _c_current_hdemo_sk3 = tbl_JOIN_INNER_TD_10446614_output.getInt32(i, 8);
                int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_10446614_output.getInt32(i, 9);
                int32_t _d_year3576 = tbl_JOIN_INNER_TD_10446614_output.getInt32(i, 10);
                int32_t _d_year3604 = tbl_JOIN_INNER_TD_10446614_output.getInt32(i, 11);
                int32_t _hd_income_band_sk205 = tbl_JOIN_INNER_TD_10446614_output.getInt32(i, 12);
                tbl_JOIN_INNER_TD_9678884_output.setInt32(r, 12, _hd_income_band_sk3636);
                tbl_JOIN_INNER_TD_9678884_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_9678884_output.setInt32(r, 1, _ss_addr_sk1212);
                tbl_JOIN_INNER_TD_9678884_output.setInt64(r, 2, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_9678884_output.setInt64(r, 3, _ss_list_price1218);
                tbl_JOIN_INNER_TD_9678884_output.setInt64(r, 4, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_9678884_output.setInt32(r, 5, _d_year126);
                tbl_JOIN_INNER_TD_9678884_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_store_name383_n);
                tbl_JOIN_INNER_TD_9678884_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_zip403_n);
                tbl_JOIN_INNER_TD_9678884_output.setInt32(r, 8, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_9678884_output.setInt32(r, 9, _d_year3576);
                tbl_JOIN_INNER_TD_9678884_output.setInt32(r, 10, _d_year3604);
                tbl_JOIN_INNER_TD_9678884_output.setInt32(r, 11, _hd_income_band_sk205);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9678884_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_9678884_output #Row: " << tbl_JOIN_INNER_TD_9678884_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8103123(Table &tbl_SerializeFromObject_TD_9446210_input, Table &tbl_Filter_TD_8103123_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ca_address_sk#5053))
    // Input: ListBuffer(ca_address_sk#5053, ca_street_number#5055, ca_street_name#5056, ca_city#5059, ca_zip#5062)
    // Output: ListBuffer(ca_address_sk#5053, ca_street_number#5055, ca_street_name#5056, ca_city#5059, ca_zip#5062)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9446210_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ca_address_sk5053 = tbl_SerializeFromObject_TD_9446210_input.getInt32(i, 0);
        if (_ca_address_sk5053!= 0) {
            int32_t _ca_address_sk5053_t = tbl_SerializeFromObject_TD_9446210_input.getInt32(i, 0);
            tbl_Filter_TD_8103123_output.setInt32(r, 0, _ca_address_sk5053_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5055_t = tbl_SerializeFromObject_TD_9446210_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_8103123_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_street_number5055_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5056_t = tbl_SerializeFromObject_TD_9446210_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_8103123_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_street_name5056_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_city5059_t = tbl_SerializeFromObject_TD_9446210_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_8103123_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_city5059_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip5062_t = tbl_SerializeFromObject_TD_9446210_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            tbl_Filter_TD_8103123_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _ca_zip5062_t);
            r++;
        }
    }
    tbl_Filter_TD_8103123_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8103123_output #Row: " << tbl_Filter_TD_8103123_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8966505_key_leftMajor {
    int32_t _ss_addr_sk4764;
    bool operator==(const SW_JOIN_INNER_TD_8966505_key_leftMajor& other) const {
        return ((_ss_addr_sk4764 == other._ss_addr_sk4764));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8966505_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8966505_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_addr_sk4764));
    }
};
}
struct SW_JOIN_INNER_TD_8966505_payload_leftMajor {
    int32_t _ss_item_sk4760;
    int32_t _ss_addr_sk4764;
    int64_t _ss_wholesale_cost4769;
    int64_t _ss_list_price4770;
    int64_t _ss_coupon_amt4777;
    int32_t _d_year4868;
    std::string _s_store_name4951;
    std::string _s_zip4971;
    int32_t _c_current_addr_sk4979;
    int32_t _d_year4896;
    int32_t _d_year4924;
    int32_t _hd_income_band_sk5031;
    int32_t _hd_income_band_sk5036;
};
struct SW_JOIN_INNER_TD_8966505_key_rightMajor {
    int32_t _ca_address_sk5040;
    bool operator==(const SW_JOIN_INNER_TD_8966505_key_rightMajor& other) const {
        return ((_ca_address_sk5040 == other._ca_address_sk5040));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8966505_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8966505_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk5040));
    }
};
}
struct SW_JOIN_INNER_TD_8966505_payload_rightMajor {
    int32_t _ca_address_sk5040;
    std::string _ca_street_number5042;
    std::string _ca_street_name5043;
    std::string _ca_city5046;
    std::string _ca_zip5049;
};
void SW_JOIN_INNER_TD_8966505(Table &tbl_JOIN_INNER_TD_9425844_output, Table &tbl_Filter_TD_9328766_output, Table &tbl_JOIN_INNER_TD_8966505_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_addr_sk#4764 = ca_address_sk#5040))
    // Left Table: ListBuffer(ss_item_sk#4760, ss_addr_sk#4764, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971, c_current_addr_sk#4979, d_year#4896, d_year#4924, hd_income_band_sk#5031, hd_income_band_sk#5036)
    // Right Table: ListBuffer(ca_address_sk#5040, ca_street_number#5042, ca_street_name#5043, ca_city#5046, ca_zip#5049)
    // Output Table: ListBuffer(ss_item_sk#4760, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971, c_current_addr_sk#4979, d_year#4896, d_year#4924, hd_income_band_sk#5031, hd_income_band_sk#5036, ca_street_number#5042, ca_street_name#5043, ca_city#5046, ca_zip#5049)
    int left_nrow = tbl_JOIN_INNER_TD_9425844_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9328766_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8966505_key_leftMajor, SW_JOIN_INNER_TD_8966505_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_9425844_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_addr_sk4764_k = tbl_JOIN_INNER_TD_9425844_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_8966505_key_leftMajor keyA{_ss_addr_sk4764_k};
            int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_9425844_output.getInt32(i, 0);
            int32_t _ss_addr_sk4764 = tbl_JOIN_INNER_TD_9425844_output.getInt32(i, 1);
            int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_9425844_output.getInt64(i, 2);
            int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_9425844_output.getInt64(i, 3);
            int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_9425844_output.getInt64(i, 4);
            int32_t _d_year4868 = tbl_JOIN_INNER_TD_9425844_output.getInt32(i, 5);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_9425844_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_9425844_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _s_zip4971 = std::string(_s_zip4971_n.data());
            int32_t _c_current_addr_sk4979 = tbl_JOIN_INNER_TD_9425844_output.getInt32(i, 8);
            int32_t _d_year4896 = tbl_JOIN_INNER_TD_9425844_output.getInt32(i, 9);
            int32_t _d_year4924 = tbl_JOIN_INNER_TD_9425844_output.getInt32(i, 10);
            int32_t _hd_income_band_sk5031 = tbl_JOIN_INNER_TD_9425844_output.getInt32(i, 11);
            int32_t _hd_income_band_sk5036 = tbl_JOIN_INNER_TD_9425844_output.getInt32(i, 12);
            SW_JOIN_INNER_TD_8966505_payload_leftMajor payloadA{_ss_item_sk4760, _ss_addr_sk4764, _ss_wholesale_cost4769, _ss_list_price4770, _ss_coupon_amt4777, _d_year4868, _s_store_name4951, _s_zip4971, _c_current_addr_sk4979, _d_year4896, _d_year4924, _hd_income_band_sk5031, _hd_income_band_sk5036};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9328766_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk5040_k = tbl_Filter_TD_9328766_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8966505_key_leftMajor{_ca_address_sk5040_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk4760 = (it->second)._ss_item_sk4760;
                int32_t _ss_addr_sk4764 = (it->second)._ss_addr_sk4764;
                int64_t _ss_wholesale_cost4769 = (it->second)._ss_wholesale_cost4769;
                int64_t _ss_list_price4770 = (it->second)._ss_list_price4770;
                int64_t _ss_coupon_amt4777 = (it->second)._ss_coupon_amt4777;
                int32_t _d_year4868 = (it->second)._d_year4868;
                std::string _s_store_name4951 = (it->second)._s_store_name4951;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n{};
                memcpy(_s_store_name4951_n.data(), (_s_store_name4951).data(), (_s_store_name4951).length());
                std::string _s_zip4971 = (it->second)._s_zip4971;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n{};
                memcpy(_s_zip4971_n.data(), (_s_zip4971).data(), (_s_zip4971).length());
                int32_t _c_current_addr_sk4979 = (it->second)._c_current_addr_sk4979;
                int32_t _d_year4896 = (it->second)._d_year4896;
                int32_t _d_year4924 = (it->second)._d_year4924;
                int32_t _hd_income_band_sk5031 = (it->second)._hd_income_band_sk5031;
                int32_t _hd_income_band_sk5036 = (it->second)._hd_income_band_sk5036;
                int32_t _ca_address_sk5040 = tbl_Filter_TD_9328766_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5042_n = tbl_Filter_TD_9328766_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_street_number5042 = std::string(_ca_street_number5042_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5043_n = tbl_Filter_TD_9328766_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _ca_street_name5043 = std::string(_ca_street_name5043_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_city5046_n = tbl_Filter_TD_9328766_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _ca_city5046 = std::string(_ca_city5046_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip5049_n = tbl_Filter_TD_9328766_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _ca_zip5049 = std::string(_ca_zip5049_n.data());
                tbl_JOIN_INNER_TD_8966505_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_8966505_output.setInt64(r, 1, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_8966505_output.setInt64(r, 2, _ss_list_price4770);
                tbl_JOIN_INNER_TD_8966505_output.setInt64(r, 3, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_8966505_output.setInt32(r, 4, _d_year4868);
                tbl_JOIN_INNER_TD_8966505_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_8966505_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_zip4971_n);
                tbl_JOIN_INNER_TD_8966505_output.setInt32(r, 7, _c_current_addr_sk4979);
                tbl_JOIN_INNER_TD_8966505_output.setInt32(r, 8, _d_year4896);
                tbl_JOIN_INNER_TD_8966505_output.setInt32(r, 9, _d_year4924);
                tbl_JOIN_INNER_TD_8966505_output.setInt32(r, 10, _hd_income_band_sk5031);
                tbl_JOIN_INNER_TD_8966505_output.setInt32(r, 11, _hd_income_band_sk5036);
                tbl_JOIN_INNER_TD_8966505_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _ca_street_number5042_n);
                tbl_JOIN_INNER_TD_8966505_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 13, _ca_street_name5043_n);
                tbl_JOIN_INNER_TD_8966505_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 14, _ca_city5046_n);
                tbl_JOIN_INNER_TD_8966505_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 15, _ca_zip5049_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8966505_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8966505_key_rightMajor, SW_JOIN_INNER_TD_8966505_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9328766_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk5040_k = tbl_Filter_TD_9328766_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8966505_key_rightMajor keyA{_ca_address_sk5040_k};
            int32_t _ca_address_sk5040 = tbl_Filter_TD_9328766_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5042_n = tbl_Filter_TD_9328766_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_street_number5042 = std::string(_ca_street_number5042_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5043_n = tbl_Filter_TD_9328766_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _ca_street_name5043 = std::string(_ca_street_name5043_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_city5046_n = tbl_Filter_TD_9328766_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _ca_city5046 = std::string(_ca_city5046_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip5049_n = tbl_Filter_TD_9328766_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _ca_zip5049 = std::string(_ca_zip5049_n.data());
            SW_JOIN_INNER_TD_8966505_payload_rightMajor payloadA{_ca_address_sk5040, _ca_street_number5042, _ca_street_name5043, _ca_city5046, _ca_zip5049};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_9425844_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_addr_sk4764_k = tbl_JOIN_INNER_TD_9425844_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8966505_key_rightMajor{_ss_addr_sk4764_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk5040 = (it->second)._ca_address_sk5040;
                std::string _ca_street_number5042 = (it->second)._ca_street_number5042;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5042_n{};
                memcpy(_ca_street_number5042_n.data(), (_ca_street_number5042).data(), (_ca_street_number5042).length());
                std::string _ca_street_name5043 = (it->second)._ca_street_name5043;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5043_n{};
                memcpy(_ca_street_name5043_n.data(), (_ca_street_name5043).data(), (_ca_street_name5043).length());
                std::string _ca_city5046 = (it->second)._ca_city5046;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city5046_n{};
                memcpy(_ca_city5046_n.data(), (_ca_city5046).data(), (_ca_city5046).length());
                std::string _ca_zip5049 = (it->second)._ca_zip5049;
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip5049_n{};
                memcpy(_ca_zip5049_n.data(), (_ca_zip5049).data(), (_ca_zip5049).length());
                int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_9425844_output.getInt32(i, 0);
                int32_t _ss_addr_sk4764 = tbl_JOIN_INNER_TD_9425844_output.getInt32(i, 1);
                int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_9425844_output.getInt64(i, 2);
                int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_9425844_output.getInt64(i, 3);
                int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_9425844_output.getInt64(i, 4);
                int32_t _d_year4868 = tbl_JOIN_INNER_TD_9425844_output.getInt32(i, 5);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_9425844_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_9425844_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _s_zip4971 = std::string(_s_zip4971_n.data());
                int32_t _c_current_addr_sk4979 = tbl_JOIN_INNER_TD_9425844_output.getInt32(i, 8);
                int32_t _d_year4896 = tbl_JOIN_INNER_TD_9425844_output.getInt32(i, 9);
                int32_t _d_year4924 = tbl_JOIN_INNER_TD_9425844_output.getInt32(i, 10);
                int32_t _hd_income_band_sk5031 = tbl_JOIN_INNER_TD_9425844_output.getInt32(i, 11);
                int32_t _hd_income_band_sk5036 = tbl_JOIN_INNER_TD_9425844_output.getInt32(i, 12);
                tbl_JOIN_INNER_TD_8966505_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _ca_street_number5042_n);
                tbl_JOIN_INNER_TD_8966505_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 13, _ca_street_name5043_n);
                tbl_JOIN_INNER_TD_8966505_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 14, _ca_city5046_n);
                tbl_JOIN_INNER_TD_8966505_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 15, _ca_zip5049_n);
                tbl_JOIN_INNER_TD_8966505_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_8966505_output.setInt64(r, 1, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_8966505_output.setInt64(r, 2, _ss_list_price4770);
                tbl_JOIN_INNER_TD_8966505_output.setInt64(r, 3, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_8966505_output.setInt32(r, 4, _d_year4868);
                tbl_JOIN_INNER_TD_8966505_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_8966505_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_zip4971_n);
                tbl_JOIN_INNER_TD_8966505_output.setInt32(r, 7, _c_current_addr_sk4979);
                tbl_JOIN_INNER_TD_8966505_output.setInt32(r, 8, _d_year4896);
                tbl_JOIN_INNER_TD_8966505_output.setInt32(r, 9, _d_year4924);
                tbl_JOIN_INNER_TD_8966505_output.setInt32(r, 10, _hd_income_band_sk5031);
                tbl_JOIN_INNER_TD_8966505_output.setInt32(r, 11, _hd_income_band_sk5036);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8966505_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8966505_output #Row: " << tbl_JOIN_INNER_TD_8966505_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8585812(Table &tbl_SerializeFromObject_TD_9859896_input, Table &tbl_Filter_TD_8585812_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ca_address_sk#3640))
    // Input: ListBuffer(ca_address_sk#3640, ca_street_number#3642, ca_street_name#3643, ca_city#3646, ca_zip#3649)
    // Output: ListBuffer(ca_address_sk#3640, ca_street_number#3642, ca_street_name#3643, ca_city#3646, ca_zip#3649)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9859896_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ca_address_sk3640 = tbl_SerializeFromObject_TD_9859896_input.getInt32(i, 0);
        if (_ca_address_sk3640!= 0) {
            int32_t _ca_address_sk3640_t = tbl_SerializeFromObject_TD_9859896_input.getInt32(i, 0);
            tbl_Filter_TD_8585812_output.setInt32(r, 0, _ca_address_sk3640_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_number3642_t = tbl_SerializeFromObject_TD_9859896_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_8585812_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_street_number3642_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_name3643_t = tbl_SerializeFromObject_TD_9859896_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_8585812_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_street_name3643_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_city3646_t = tbl_SerializeFromObject_TD_9859896_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            tbl_Filter_TD_8585812_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_city3646_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip3649_t = tbl_SerializeFromObject_TD_9859896_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            tbl_Filter_TD_8585812_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _ca_zip3649_t);
            r++;
        }
    }
    tbl_Filter_TD_8585812_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8585812_output #Row: " << tbl_Filter_TD_8585812_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8755957_key_leftMajor {
    int32_t _ss_addr_sk1212;
    bool operator==(const SW_JOIN_INNER_TD_8755957_key_leftMajor& other) const {
        return ((_ss_addr_sk1212 == other._ss_addr_sk1212));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8755957_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8755957_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_addr_sk1212));
    }
};
}
struct SW_JOIN_INNER_TD_8755957_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int32_t _ss_addr_sk1212;
    int64_t _ss_wholesale_cost1217;
    int64_t _ss_list_price1218;
    int64_t _ss_coupon_amt1225;
    int32_t _d_year126;
    std::string _s_store_name383;
    std::string _s_zip403;
    int32_t _c_current_addr_sk4;
    int32_t _d_year3576;
    int32_t _d_year3604;
    int32_t _hd_income_band_sk205;
    int32_t _hd_income_band_sk3636;
};
struct SW_JOIN_INNER_TD_8755957_key_rightMajor {
    int32_t _ca_address_sk54;
    bool operator==(const SW_JOIN_INNER_TD_8755957_key_rightMajor& other) const {
        return ((_ca_address_sk54 == other._ca_address_sk54));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8755957_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8755957_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk54));
    }
};
}
struct SW_JOIN_INNER_TD_8755957_payload_rightMajor {
    int32_t _ca_address_sk54;
    std::string _ca_street_number56;
    std::string _ca_street_name57;
    std::string _ca_city60;
    std::string _ca_zip63;
};
void SW_JOIN_INNER_TD_8755957(Table &tbl_JOIN_INNER_TD_9678884_output, Table &tbl_Filter_TD_9772283_output, Table &tbl_JOIN_INNER_TD_8755957_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_addr_sk#1212 = ca_address_sk#54))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_addr_sk#1212, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403, c_current_addr_sk#4, d_year#3576, d_year#3604, hd_income_band_sk#205, hd_income_band_sk#3636)
    // Right Table: ListBuffer(ca_address_sk#54, ca_street_number#56, ca_street_name#57, ca_city#60, ca_zip#63)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403, c_current_addr_sk#4, d_year#3576, d_year#3604, hd_income_band_sk#205, hd_income_band_sk#3636, ca_street_number#56, ca_street_name#57, ca_city#60, ca_zip#63)
    int left_nrow = tbl_JOIN_INNER_TD_9678884_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9772283_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8755957_key_leftMajor, SW_JOIN_INNER_TD_8755957_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_9678884_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_addr_sk1212_k = tbl_JOIN_INNER_TD_9678884_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_8755957_key_leftMajor keyA{_ss_addr_sk1212_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_9678884_output.getInt32(i, 0);
            int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_9678884_output.getInt32(i, 1);
            int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_9678884_output.getInt64(i, 2);
            int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_9678884_output.getInt64(i, 3);
            int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_9678884_output.getInt64(i, 4);
            int32_t _d_year126 = tbl_JOIN_INNER_TD_9678884_output.getInt32(i, 5);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_9678884_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _s_store_name383 = std::string(_s_store_name383_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_9678884_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _s_zip403 = std::string(_s_zip403_n.data());
            int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_9678884_output.getInt32(i, 8);
            int32_t _d_year3576 = tbl_JOIN_INNER_TD_9678884_output.getInt32(i, 9);
            int32_t _d_year3604 = tbl_JOIN_INNER_TD_9678884_output.getInt32(i, 10);
            int32_t _hd_income_band_sk205 = tbl_JOIN_INNER_TD_9678884_output.getInt32(i, 11);
            int32_t _hd_income_band_sk3636 = tbl_JOIN_INNER_TD_9678884_output.getInt32(i, 12);
            SW_JOIN_INNER_TD_8755957_payload_leftMajor payloadA{_ss_item_sk1208, _ss_addr_sk1212, _ss_wholesale_cost1217, _ss_list_price1218, _ss_coupon_amt1225, _d_year126, _s_store_name383, _s_zip403, _c_current_addr_sk4, _d_year3576, _d_year3604, _hd_income_band_sk205, _hd_income_band_sk3636};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9772283_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_9772283_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8755957_key_leftMajor{_ca_address_sk54_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_addr_sk1212 = (it->second)._ss_addr_sk1212;
                int64_t _ss_wholesale_cost1217 = (it->second)._ss_wholesale_cost1217;
                int64_t _ss_list_price1218 = (it->second)._ss_list_price1218;
                int64_t _ss_coupon_amt1225 = (it->second)._ss_coupon_amt1225;
                int32_t _d_year126 = (it->second)._d_year126;
                std::string _s_store_name383 = (it->second)._s_store_name383;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n{};
                memcpy(_s_store_name383_n.data(), (_s_store_name383).data(), (_s_store_name383).length());
                std::string _s_zip403 = (it->second)._s_zip403;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n{};
                memcpy(_s_zip403_n.data(), (_s_zip403).data(), (_s_zip403).length());
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                int32_t _d_year3576 = (it->second)._d_year3576;
                int32_t _d_year3604 = (it->second)._d_year3604;
                int32_t _hd_income_band_sk205 = (it->second)._hd_income_band_sk205;
                int32_t _hd_income_band_sk3636 = (it->second)._hd_income_band_sk3636;
                int32_t _ca_address_sk54 = tbl_Filter_TD_9772283_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number56_n = tbl_Filter_TD_9772283_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_street_number56 = std::string(_ca_street_number56_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name57_n = tbl_Filter_TD_9772283_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _ca_street_name57 = std::string(_ca_street_name57_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n = tbl_Filter_TD_9772283_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _ca_city60 = std::string(_ca_city60_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n = tbl_Filter_TD_9772283_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _ca_zip63 = std::string(_ca_zip63_n.data());
                tbl_JOIN_INNER_TD_8755957_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_8755957_output.setInt64(r, 1, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_8755957_output.setInt64(r, 2, _ss_list_price1218);
                tbl_JOIN_INNER_TD_8755957_output.setInt64(r, 3, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_8755957_output.setInt32(r, 4, _d_year126);
                tbl_JOIN_INNER_TD_8755957_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_store_name383_n);
                tbl_JOIN_INNER_TD_8755957_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_zip403_n);
                tbl_JOIN_INNER_TD_8755957_output.setInt32(r, 7, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_8755957_output.setInt32(r, 8, _d_year3576);
                tbl_JOIN_INNER_TD_8755957_output.setInt32(r, 9, _d_year3604);
                tbl_JOIN_INNER_TD_8755957_output.setInt32(r, 10, _hd_income_band_sk205);
                tbl_JOIN_INNER_TD_8755957_output.setInt32(r, 11, _hd_income_band_sk3636);
                tbl_JOIN_INNER_TD_8755957_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _ca_street_number56_n);
                tbl_JOIN_INNER_TD_8755957_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 13, _ca_street_name57_n);
                tbl_JOIN_INNER_TD_8755957_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 14, _ca_city60_n);
                tbl_JOIN_INNER_TD_8755957_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 15, _ca_zip63_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8755957_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8755957_key_rightMajor, SW_JOIN_INNER_TD_8755957_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9772283_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_9772283_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8755957_key_rightMajor keyA{_ca_address_sk54_k};
            int32_t _ca_address_sk54 = tbl_Filter_TD_9772283_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_number56_n = tbl_Filter_TD_9772283_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_street_number56 = std::string(_ca_street_number56_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_name57_n = tbl_Filter_TD_9772283_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _ca_street_name57 = std::string(_ca_street_name57_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n = tbl_Filter_TD_9772283_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _ca_city60 = std::string(_ca_city60_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n = tbl_Filter_TD_9772283_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _ca_zip63 = std::string(_ca_zip63_n.data());
            SW_JOIN_INNER_TD_8755957_payload_rightMajor payloadA{_ca_address_sk54, _ca_street_number56, _ca_street_name57, _ca_city60, _ca_zip63};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_9678884_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_addr_sk1212_k = tbl_JOIN_INNER_TD_9678884_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8755957_key_rightMajor{_ss_addr_sk1212_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk54 = (it->second)._ca_address_sk54;
                std::string _ca_street_number56 = (it->second)._ca_street_number56;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number56_n{};
                memcpy(_ca_street_number56_n.data(), (_ca_street_number56).data(), (_ca_street_number56).length());
                std::string _ca_street_name57 = (it->second)._ca_street_name57;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name57_n{};
                memcpy(_ca_street_name57_n.data(), (_ca_street_name57).data(), (_ca_street_name57).length());
                std::string _ca_city60 = (it->second)._ca_city60;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n{};
                memcpy(_ca_city60_n.data(), (_ca_city60).data(), (_ca_city60).length());
                std::string _ca_zip63 = (it->second)._ca_zip63;
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n{};
                memcpy(_ca_zip63_n.data(), (_ca_zip63).data(), (_ca_zip63).length());
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_9678884_output.getInt32(i, 0);
                int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_9678884_output.getInt32(i, 1);
                int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_9678884_output.getInt64(i, 2);
                int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_9678884_output.getInt64(i, 3);
                int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_9678884_output.getInt64(i, 4);
                int32_t _d_year126 = tbl_JOIN_INNER_TD_9678884_output.getInt32(i, 5);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_9678884_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _s_store_name383 = std::string(_s_store_name383_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_9678884_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _s_zip403 = std::string(_s_zip403_n.data());
                int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_9678884_output.getInt32(i, 8);
                int32_t _d_year3576 = tbl_JOIN_INNER_TD_9678884_output.getInt32(i, 9);
                int32_t _d_year3604 = tbl_JOIN_INNER_TD_9678884_output.getInt32(i, 10);
                int32_t _hd_income_band_sk205 = tbl_JOIN_INNER_TD_9678884_output.getInt32(i, 11);
                int32_t _hd_income_band_sk3636 = tbl_JOIN_INNER_TD_9678884_output.getInt32(i, 12);
                tbl_JOIN_INNER_TD_8755957_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _ca_street_number56_n);
                tbl_JOIN_INNER_TD_8755957_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 13, _ca_street_name57_n);
                tbl_JOIN_INNER_TD_8755957_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 14, _ca_city60_n);
                tbl_JOIN_INNER_TD_8755957_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 15, _ca_zip63_n);
                tbl_JOIN_INNER_TD_8755957_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_8755957_output.setInt64(r, 1, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_8755957_output.setInt64(r, 2, _ss_list_price1218);
                tbl_JOIN_INNER_TD_8755957_output.setInt64(r, 3, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_8755957_output.setInt32(r, 4, _d_year126);
                tbl_JOIN_INNER_TD_8755957_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_store_name383_n);
                tbl_JOIN_INNER_TD_8755957_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_zip403_n);
                tbl_JOIN_INNER_TD_8755957_output.setInt32(r, 7, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_8755957_output.setInt32(r, 8, _d_year3576);
                tbl_JOIN_INNER_TD_8755957_output.setInt32(r, 9, _d_year3604);
                tbl_JOIN_INNER_TD_8755957_output.setInt32(r, 10, _hd_income_band_sk205);
                tbl_JOIN_INNER_TD_8755957_output.setInt32(r, 11, _hd_income_band_sk3636);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8755957_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8755957_output #Row: " << tbl_JOIN_INNER_TD_8755957_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7895840(Table &tbl_SerializeFromObject_TD_8407051_input, Table &tbl_Filter_TD_7895840_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ib_income_band_sk#5066))
    // Input: ListBuffer(ib_income_band_sk#5066)
    // Output: ListBuffer(ib_income_band_sk#5066)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8407051_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ib_income_band_sk5066 = tbl_SerializeFromObject_TD_8407051_input.getInt32(i, 0);
        if (_ib_income_band_sk5066!= 0) {
            int32_t _ib_income_band_sk5066_t = tbl_SerializeFromObject_TD_8407051_input.getInt32(i, 0);
            tbl_Filter_TD_7895840_output.setInt32(r, 0, _ib_income_band_sk5066_t);
            r++;
        }
    }
    tbl_Filter_TD_7895840_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7895840_output #Row: " << tbl_Filter_TD_7895840_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_7719384_key_leftMajor {
    int32_t _c_current_addr_sk4979;
    bool operator==(const SW_JOIN_INNER_TD_7719384_key_leftMajor& other) const {
        return ((_c_current_addr_sk4979 == other._c_current_addr_sk4979));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7719384_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7719384_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_current_addr_sk4979));
    }
};
}
struct SW_JOIN_INNER_TD_7719384_payload_leftMajor {
    int32_t _ss_item_sk4760;
    int64_t _ss_wholesale_cost4769;
    int64_t _ss_list_price4770;
    int64_t _ss_coupon_amt4777;
    int32_t _d_year4868;
    std::string _s_store_name4951;
    std::string _s_zip4971;
    int32_t _c_current_addr_sk4979;
    int32_t _d_year4896;
    int32_t _d_year4924;
    int32_t _hd_income_band_sk5031;
    int32_t _hd_income_band_sk5036;
    std::string _ca_street_number5042;
    std::string _ca_street_name5043;
    std::string _ca_city5046;
    std::string _ca_zip5049;
};
struct SW_JOIN_INNER_TD_7719384_key_rightMajor {
    int32_t _ca_address_sk5053;
    bool operator==(const SW_JOIN_INNER_TD_7719384_key_rightMajor& other) const {
        return ((_ca_address_sk5053 == other._ca_address_sk5053));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7719384_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7719384_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk5053));
    }
};
}
struct SW_JOIN_INNER_TD_7719384_payload_rightMajor {
    int32_t _ca_address_sk5053;
    std::string _ca_street_number5055;
    std::string _ca_street_name5056;
    std::string _ca_city5059;
    std::string _ca_zip5062;
};
void SW_JOIN_INNER_TD_7719384(Table &tbl_JOIN_INNER_TD_8966505_output, Table &tbl_Filter_TD_8103123_output, Table &tbl_JOIN_INNER_TD_7719384_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((c_current_addr_sk#4979 = ca_address_sk#5053))
    // Left Table: ListBuffer(ss_item_sk#4760, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971, c_current_addr_sk#4979, d_year#4896, d_year#4924, hd_income_band_sk#5031, hd_income_band_sk#5036, ca_street_number#5042, ca_street_name#5043, ca_city#5046, ca_zip#5049)
    // Right Table: ListBuffer(ca_address_sk#5053, ca_street_number#5055, ca_street_name#5056, ca_city#5059, ca_zip#5062)
    // Output Table: ListBuffer(ss_item_sk#4760, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971, d_year#4896, d_year#4924, hd_income_band_sk#5031, hd_income_band_sk#5036, ca_street_number#5042, ca_street_name#5043, ca_city#5046, ca_zip#5049, ca_street_number#5055, ca_street_name#5056, ca_city#5059, ca_zip#5062)
    int left_nrow = tbl_JOIN_INNER_TD_8966505_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8103123_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7719384_key_leftMajor, SW_JOIN_INNER_TD_7719384_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_8966505_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_current_addr_sk4979_k = tbl_JOIN_INNER_TD_8966505_output.getInt32(i, 7);
            SW_JOIN_INNER_TD_7719384_key_leftMajor keyA{_c_current_addr_sk4979_k};
            int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_8966505_output.getInt32(i, 0);
            int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_8966505_output.getInt64(i, 1);
            int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_8966505_output.getInt64(i, 2);
            int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_8966505_output.getInt64(i, 3);
            int32_t _d_year4868 = tbl_JOIN_INNER_TD_8966505_output.getInt32(i, 4);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_8966505_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_8966505_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _s_zip4971 = std::string(_s_zip4971_n.data());
            int32_t _c_current_addr_sk4979 = tbl_JOIN_INNER_TD_8966505_output.getInt32(i, 7);
            int32_t _d_year4896 = tbl_JOIN_INNER_TD_8966505_output.getInt32(i, 8);
            int32_t _d_year4924 = tbl_JOIN_INNER_TD_8966505_output.getInt32(i, 9);
            int32_t _hd_income_band_sk5031 = tbl_JOIN_INNER_TD_8966505_output.getInt32(i, 10);
            int32_t _hd_income_band_sk5036 = tbl_JOIN_INNER_TD_8966505_output.getInt32(i, 11);
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5042_n = tbl_JOIN_INNER_TD_8966505_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 12);
            std::string _ca_street_number5042 = std::string(_ca_street_number5042_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5043_n = tbl_JOIN_INNER_TD_8966505_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 13);
            std::string _ca_street_name5043 = std::string(_ca_street_name5043_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_city5046_n = tbl_JOIN_INNER_TD_8966505_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 14);
            std::string _ca_city5046 = std::string(_ca_city5046_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip5049_n = tbl_JOIN_INNER_TD_8966505_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
            std::string _ca_zip5049 = std::string(_ca_zip5049_n.data());
            SW_JOIN_INNER_TD_7719384_payload_leftMajor payloadA{_ss_item_sk4760, _ss_wholesale_cost4769, _ss_list_price4770, _ss_coupon_amt4777, _d_year4868, _s_store_name4951, _s_zip4971, _c_current_addr_sk4979, _d_year4896, _d_year4924, _hd_income_band_sk5031, _hd_income_band_sk5036, _ca_street_number5042, _ca_street_name5043, _ca_city5046, _ca_zip5049};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8103123_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk5053_k = tbl_Filter_TD_8103123_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7719384_key_leftMajor{_ca_address_sk5053_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk4760 = (it->second)._ss_item_sk4760;
                int64_t _ss_wholesale_cost4769 = (it->second)._ss_wholesale_cost4769;
                int64_t _ss_list_price4770 = (it->second)._ss_list_price4770;
                int64_t _ss_coupon_amt4777 = (it->second)._ss_coupon_amt4777;
                int32_t _d_year4868 = (it->second)._d_year4868;
                std::string _s_store_name4951 = (it->second)._s_store_name4951;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n{};
                memcpy(_s_store_name4951_n.data(), (_s_store_name4951).data(), (_s_store_name4951).length());
                std::string _s_zip4971 = (it->second)._s_zip4971;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n{};
                memcpy(_s_zip4971_n.data(), (_s_zip4971).data(), (_s_zip4971).length());
                int32_t _c_current_addr_sk4979 = (it->second)._c_current_addr_sk4979;
                int32_t _d_year4896 = (it->second)._d_year4896;
                int32_t _d_year4924 = (it->second)._d_year4924;
                int32_t _hd_income_band_sk5031 = (it->second)._hd_income_band_sk5031;
                int32_t _hd_income_band_sk5036 = (it->second)._hd_income_band_sk5036;
                std::string _ca_street_number5042 = (it->second)._ca_street_number5042;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5042_n{};
                memcpy(_ca_street_number5042_n.data(), (_ca_street_number5042).data(), (_ca_street_number5042).length());
                std::string _ca_street_name5043 = (it->second)._ca_street_name5043;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5043_n{};
                memcpy(_ca_street_name5043_n.data(), (_ca_street_name5043).data(), (_ca_street_name5043).length());
                std::string _ca_city5046 = (it->second)._ca_city5046;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city5046_n{};
                memcpy(_ca_city5046_n.data(), (_ca_city5046).data(), (_ca_city5046).length());
                std::string _ca_zip5049 = (it->second)._ca_zip5049;
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip5049_n{};
                memcpy(_ca_zip5049_n.data(), (_ca_zip5049).data(), (_ca_zip5049).length());
                int32_t _ca_address_sk5053 = tbl_Filter_TD_8103123_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5055_n = tbl_Filter_TD_8103123_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_street_number5055 = std::string(_ca_street_number5055_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5056_n = tbl_Filter_TD_8103123_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _ca_street_name5056 = std::string(_ca_street_name5056_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_city5059_n = tbl_Filter_TD_8103123_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _ca_city5059 = std::string(_ca_city5059_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip5062_n = tbl_Filter_TD_8103123_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _ca_zip5062 = std::string(_ca_zip5062_n.data());
                tbl_JOIN_INNER_TD_7719384_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_7719384_output.setInt64(r, 1, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_7719384_output.setInt64(r, 2, _ss_list_price4770);
                tbl_JOIN_INNER_TD_7719384_output.setInt64(r, 3, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_7719384_output.setInt32(r, 4, _d_year4868);
                tbl_JOIN_INNER_TD_7719384_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_7719384_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_zip4971_n);
                tbl_JOIN_INNER_TD_7719384_output.setInt32(r, 7, _d_year4896);
                tbl_JOIN_INNER_TD_7719384_output.setInt32(r, 8, _d_year4924);
                tbl_JOIN_INNER_TD_7719384_output.setInt32(r, 9, _hd_income_band_sk5031);
                tbl_JOIN_INNER_TD_7719384_output.setInt32(r, 10, _hd_income_band_sk5036);
                tbl_JOIN_INNER_TD_7719384_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _ca_street_number5042_n);
                tbl_JOIN_INNER_TD_7719384_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _ca_street_name5043_n);
                tbl_JOIN_INNER_TD_7719384_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 13, _ca_city5046_n);
                tbl_JOIN_INNER_TD_7719384_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 14, _ca_zip5049_n);
                tbl_JOIN_INNER_TD_7719384_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 15, _ca_street_number5055_n);
                tbl_JOIN_INNER_TD_7719384_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 16, _ca_street_name5056_n);
                tbl_JOIN_INNER_TD_7719384_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 17, _ca_city5059_n);
                tbl_JOIN_INNER_TD_7719384_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 18, _ca_zip5062_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7719384_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7719384_key_rightMajor, SW_JOIN_INNER_TD_7719384_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8103123_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk5053_k = tbl_Filter_TD_8103123_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7719384_key_rightMajor keyA{_ca_address_sk5053_k};
            int32_t _ca_address_sk5053 = tbl_Filter_TD_8103123_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5055_n = tbl_Filter_TD_8103123_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_street_number5055 = std::string(_ca_street_number5055_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5056_n = tbl_Filter_TD_8103123_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _ca_street_name5056 = std::string(_ca_street_name5056_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_city5059_n = tbl_Filter_TD_8103123_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _ca_city5059 = std::string(_ca_city5059_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip5062_n = tbl_Filter_TD_8103123_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _ca_zip5062 = std::string(_ca_zip5062_n.data());
            SW_JOIN_INNER_TD_7719384_payload_rightMajor payloadA{_ca_address_sk5053, _ca_street_number5055, _ca_street_name5056, _ca_city5059, _ca_zip5062};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_8966505_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_current_addr_sk4979_k = tbl_JOIN_INNER_TD_8966505_output.getInt32(i, 7);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7719384_key_rightMajor{_c_current_addr_sk4979_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk5053 = (it->second)._ca_address_sk5053;
                std::string _ca_street_number5055 = (it->second)._ca_street_number5055;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5055_n{};
                memcpy(_ca_street_number5055_n.data(), (_ca_street_number5055).data(), (_ca_street_number5055).length());
                std::string _ca_street_name5056 = (it->second)._ca_street_name5056;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5056_n{};
                memcpy(_ca_street_name5056_n.data(), (_ca_street_name5056).data(), (_ca_street_name5056).length());
                std::string _ca_city5059 = (it->second)._ca_city5059;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city5059_n{};
                memcpy(_ca_city5059_n.data(), (_ca_city5059).data(), (_ca_city5059).length());
                std::string _ca_zip5062 = (it->second)._ca_zip5062;
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip5062_n{};
                memcpy(_ca_zip5062_n.data(), (_ca_zip5062).data(), (_ca_zip5062).length());
                int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_8966505_output.getInt32(i, 0);
                int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_8966505_output.getInt64(i, 1);
                int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_8966505_output.getInt64(i, 2);
                int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_8966505_output.getInt64(i, 3);
                int32_t _d_year4868 = tbl_JOIN_INNER_TD_8966505_output.getInt32(i, 4);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_8966505_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_8966505_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _s_zip4971 = std::string(_s_zip4971_n.data());
                int32_t _c_current_addr_sk4979 = tbl_JOIN_INNER_TD_8966505_output.getInt32(i, 7);
                int32_t _d_year4896 = tbl_JOIN_INNER_TD_8966505_output.getInt32(i, 8);
                int32_t _d_year4924 = tbl_JOIN_INNER_TD_8966505_output.getInt32(i, 9);
                int32_t _hd_income_band_sk5031 = tbl_JOIN_INNER_TD_8966505_output.getInt32(i, 10);
                int32_t _hd_income_band_sk5036 = tbl_JOIN_INNER_TD_8966505_output.getInt32(i, 11);
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5042_n = tbl_JOIN_INNER_TD_8966505_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 12);
                std::string _ca_street_number5042 = std::string(_ca_street_number5042_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5043_n = tbl_JOIN_INNER_TD_8966505_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 13);
                std::string _ca_street_name5043 = std::string(_ca_street_name5043_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_city5046_n = tbl_JOIN_INNER_TD_8966505_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 14);
                std::string _ca_city5046 = std::string(_ca_city5046_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip5049_n = tbl_JOIN_INNER_TD_8966505_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
                std::string _ca_zip5049 = std::string(_ca_zip5049_n.data());
                tbl_JOIN_INNER_TD_7719384_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 15, _ca_street_number5055_n);
                tbl_JOIN_INNER_TD_7719384_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 16, _ca_street_name5056_n);
                tbl_JOIN_INNER_TD_7719384_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 17, _ca_city5059_n);
                tbl_JOIN_INNER_TD_7719384_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 18, _ca_zip5062_n);
                tbl_JOIN_INNER_TD_7719384_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_7719384_output.setInt64(r, 1, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_7719384_output.setInt64(r, 2, _ss_list_price4770);
                tbl_JOIN_INNER_TD_7719384_output.setInt64(r, 3, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_7719384_output.setInt32(r, 4, _d_year4868);
                tbl_JOIN_INNER_TD_7719384_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_7719384_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_zip4971_n);
                tbl_JOIN_INNER_TD_7719384_output.setInt32(r, 7, _d_year4896);
                tbl_JOIN_INNER_TD_7719384_output.setInt32(r, 8, _d_year4924);
                tbl_JOIN_INNER_TD_7719384_output.setInt32(r, 9, _hd_income_band_sk5031);
                tbl_JOIN_INNER_TD_7719384_output.setInt32(r, 10, _hd_income_band_sk5036);
                tbl_JOIN_INNER_TD_7719384_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _ca_street_number5042_n);
                tbl_JOIN_INNER_TD_7719384_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _ca_street_name5043_n);
                tbl_JOIN_INNER_TD_7719384_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 13, _ca_city5046_n);
                tbl_JOIN_INNER_TD_7719384_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 14, _ca_zip5049_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7719384_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7719384_output #Row: " << tbl_JOIN_INNER_TD_7719384_output.getNumRow() << std::endl;
}

void SW_Filter_TD_727362(Table &tbl_SerializeFromObject_TD_8344879_input, Table &tbl_Filter_TD_727362_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ib_income_band_sk#219))
    // Input: ListBuffer(ib_income_band_sk#219)
    // Output: ListBuffer(ib_income_band_sk#219)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8344879_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ib_income_band_sk219 = tbl_SerializeFromObject_TD_8344879_input.getInt32(i, 0);
        if (_ib_income_band_sk219!= 0) {
            int32_t _ib_income_band_sk219_t = tbl_SerializeFromObject_TD_8344879_input.getInt32(i, 0);
            tbl_Filter_TD_727362_output.setInt32(r, 0, _ib_income_band_sk219_t);
            r++;
        }
    }
    tbl_Filter_TD_727362_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_727362_output #Row: " << tbl_Filter_TD_727362_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_74545_key_leftMajor {
    int32_t _c_current_addr_sk4;
    bool operator==(const SW_JOIN_INNER_TD_74545_key_leftMajor& other) const {
        return ((_c_current_addr_sk4 == other._c_current_addr_sk4));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_74545_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_74545_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_current_addr_sk4));
    }
};
}
struct SW_JOIN_INNER_TD_74545_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int64_t _ss_wholesale_cost1217;
    int64_t _ss_list_price1218;
    int64_t _ss_coupon_amt1225;
    int32_t _d_year126;
    std::string _s_store_name383;
    std::string _s_zip403;
    int32_t _c_current_addr_sk4;
    int32_t _d_year3576;
    int32_t _d_year3604;
    int32_t _hd_income_band_sk205;
    int32_t _hd_income_band_sk3636;
    std::string _ca_street_number56;
    std::string _ca_street_name57;
    std::string _ca_city60;
    std::string _ca_zip63;
};
struct SW_JOIN_INNER_TD_74545_key_rightMajor {
    int32_t _ca_address_sk3640;
    bool operator==(const SW_JOIN_INNER_TD_74545_key_rightMajor& other) const {
        return ((_ca_address_sk3640 == other._ca_address_sk3640));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_74545_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_74545_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk3640));
    }
};
}
struct SW_JOIN_INNER_TD_74545_payload_rightMajor {
    int32_t _ca_address_sk3640;
    std::string _ca_street_number3642;
    std::string _ca_street_name3643;
    std::string _ca_city3646;
    std::string _ca_zip3649;
};
void SW_JOIN_INNER_TD_74545(Table &tbl_JOIN_INNER_TD_8755957_output, Table &tbl_Filter_TD_8585812_output, Table &tbl_JOIN_INNER_TD_74545_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((c_current_addr_sk#4 = ca_address_sk#3640))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403, c_current_addr_sk#4, d_year#3576, d_year#3604, hd_income_band_sk#205, hd_income_band_sk#3636, ca_street_number#56, ca_street_name#57, ca_city#60, ca_zip#63)
    // Right Table: ListBuffer(ca_address_sk#3640, ca_street_number#3642, ca_street_name#3643, ca_city#3646, ca_zip#3649)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403, d_year#3576, d_year#3604, hd_income_band_sk#205, hd_income_band_sk#3636, ca_street_number#56, ca_street_name#57, ca_city#60, ca_zip#63, ca_street_number#3642, ca_street_name#3643, ca_city#3646, ca_zip#3649)
    int left_nrow = tbl_JOIN_INNER_TD_8755957_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8585812_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_74545_key_leftMajor, SW_JOIN_INNER_TD_74545_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_8755957_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_current_addr_sk4_k = tbl_JOIN_INNER_TD_8755957_output.getInt32(i, 7);
            SW_JOIN_INNER_TD_74545_key_leftMajor keyA{_c_current_addr_sk4_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_8755957_output.getInt32(i, 0);
            int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_8755957_output.getInt64(i, 1);
            int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_8755957_output.getInt64(i, 2);
            int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_8755957_output.getInt64(i, 3);
            int32_t _d_year126 = tbl_JOIN_INNER_TD_8755957_output.getInt32(i, 4);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_8755957_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _s_store_name383 = std::string(_s_store_name383_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_8755957_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _s_zip403 = std::string(_s_zip403_n.data());
            int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_8755957_output.getInt32(i, 7);
            int32_t _d_year3576 = tbl_JOIN_INNER_TD_8755957_output.getInt32(i, 8);
            int32_t _d_year3604 = tbl_JOIN_INNER_TD_8755957_output.getInt32(i, 9);
            int32_t _hd_income_band_sk205 = tbl_JOIN_INNER_TD_8755957_output.getInt32(i, 10);
            int32_t _hd_income_band_sk3636 = tbl_JOIN_INNER_TD_8755957_output.getInt32(i, 11);
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_number56_n = tbl_JOIN_INNER_TD_8755957_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 12);
            std::string _ca_street_number56 = std::string(_ca_street_number56_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_name57_n = tbl_JOIN_INNER_TD_8755957_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 13);
            std::string _ca_street_name57 = std::string(_ca_street_name57_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n = tbl_JOIN_INNER_TD_8755957_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 14);
            std::string _ca_city60 = std::string(_ca_city60_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n = tbl_JOIN_INNER_TD_8755957_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
            std::string _ca_zip63 = std::string(_ca_zip63_n.data());
            SW_JOIN_INNER_TD_74545_payload_leftMajor payloadA{_ss_item_sk1208, _ss_wholesale_cost1217, _ss_list_price1218, _ss_coupon_amt1225, _d_year126, _s_store_name383, _s_zip403, _c_current_addr_sk4, _d_year3576, _d_year3604, _hd_income_band_sk205, _hd_income_band_sk3636, _ca_street_number56, _ca_street_name57, _ca_city60, _ca_zip63};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8585812_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk3640_k = tbl_Filter_TD_8585812_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_74545_key_leftMajor{_ca_address_sk3640_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int64_t _ss_wholesale_cost1217 = (it->second)._ss_wholesale_cost1217;
                int64_t _ss_list_price1218 = (it->second)._ss_list_price1218;
                int64_t _ss_coupon_amt1225 = (it->second)._ss_coupon_amt1225;
                int32_t _d_year126 = (it->second)._d_year126;
                std::string _s_store_name383 = (it->second)._s_store_name383;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n{};
                memcpy(_s_store_name383_n.data(), (_s_store_name383).data(), (_s_store_name383).length());
                std::string _s_zip403 = (it->second)._s_zip403;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n{};
                memcpy(_s_zip403_n.data(), (_s_zip403).data(), (_s_zip403).length());
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                int32_t _d_year3576 = (it->second)._d_year3576;
                int32_t _d_year3604 = (it->second)._d_year3604;
                int32_t _hd_income_band_sk205 = (it->second)._hd_income_band_sk205;
                int32_t _hd_income_band_sk3636 = (it->second)._hd_income_band_sk3636;
                std::string _ca_street_number56 = (it->second)._ca_street_number56;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number56_n{};
                memcpy(_ca_street_number56_n.data(), (_ca_street_number56).data(), (_ca_street_number56).length());
                std::string _ca_street_name57 = (it->second)._ca_street_name57;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name57_n{};
                memcpy(_ca_street_name57_n.data(), (_ca_street_name57).data(), (_ca_street_name57).length());
                std::string _ca_city60 = (it->second)._ca_city60;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n{};
                memcpy(_ca_city60_n.data(), (_ca_city60).data(), (_ca_city60).length());
                std::string _ca_zip63 = (it->second)._ca_zip63;
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n{};
                memcpy(_ca_zip63_n.data(), (_ca_zip63).data(), (_ca_zip63).length());
                int32_t _ca_address_sk3640 = tbl_Filter_TD_8585812_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number3642_n = tbl_Filter_TD_8585812_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_street_number3642 = std::string(_ca_street_number3642_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name3643_n = tbl_Filter_TD_8585812_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _ca_street_name3643 = std::string(_ca_street_name3643_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_city3646_n = tbl_Filter_TD_8585812_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _ca_city3646 = std::string(_ca_city3646_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip3649_n = tbl_Filter_TD_8585812_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _ca_zip3649 = std::string(_ca_zip3649_n.data());
                tbl_JOIN_INNER_TD_74545_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_74545_output.setInt64(r, 1, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_74545_output.setInt64(r, 2, _ss_list_price1218);
                tbl_JOIN_INNER_TD_74545_output.setInt64(r, 3, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_74545_output.setInt32(r, 4, _d_year126);
                tbl_JOIN_INNER_TD_74545_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_store_name383_n);
                tbl_JOIN_INNER_TD_74545_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_zip403_n);
                tbl_JOIN_INNER_TD_74545_output.setInt32(r, 7, _d_year3576);
                tbl_JOIN_INNER_TD_74545_output.setInt32(r, 8, _d_year3604);
                tbl_JOIN_INNER_TD_74545_output.setInt32(r, 9, _hd_income_band_sk205);
                tbl_JOIN_INNER_TD_74545_output.setInt32(r, 10, _hd_income_band_sk3636);
                tbl_JOIN_INNER_TD_74545_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _ca_street_number56_n);
                tbl_JOIN_INNER_TD_74545_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _ca_street_name57_n);
                tbl_JOIN_INNER_TD_74545_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 13, _ca_city60_n);
                tbl_JOIN_INNER_TD_74545_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 14, _ca_zip63_n);
                tbl_JOIN_INNER_TD_74545_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 15, _ca_street_number3642_n);
                tbl_JOIN_INNER_TD_74545_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 16, _ca_street_name3643_n);
                tbl_JOIN_INNER_TD_74545_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 17, _ca_city3646_n);
                tbl_JOIN_INNER_TD_74545_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 18, _ca_zip3649_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_74545_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_74545_key_rightMajor, SW_JOIN_INNER_TD_74545_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8585812_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk3640_k = tbl_Filter_TD_8585812_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_74545_key_rightMajor keyA{_ca_address_sk3640_k};
            int32_t _ca_address_sk3640 = tbl_Filter_TD_8585812_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_number3642_n = tbl_Filter_TD_8585812_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_street_number3642 = std::string(_ca_street_number3642_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_name3643_n = tbl_Filter_TD_8585812_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _ca_street_name3643 = std::string(_ca_street_name3643_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_city3646_n = tbl_Filter_TD_8585812_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _ca_city3646 = std::string(_ca_city3646_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip3649_n = tbl_Filter_TD_8585812_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _ca_zip3649 = std::string(_ca_zip3649_n.data());
            SW_JOIN_INNER_TD_74545_payload_rightMajor payloadA{_ca_address_sk3640, _ca_street_number3642, _ca_street_name3643, _ca_city3646, _ca_zip3649};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_8755957_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_current_addr_sk4_k = tbl_JOIN_INNER_TD_8755957_output.getInt32(i, 7);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_74545_key_rightMajor{_c_current_addr_sk4_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk3640 = (it->second)._ca_address_sk3640;
                std::string _ca_street_number3642 = (it->second)._ca_street_number3642;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number3642_n{};
                memcpy(_ca_street_number3642_n.data(), (_ca_street_number3642).data(), (_ca_street_number3642).length());
                std::string _ca_street_name3643 = (it->second)._ca_street_name3643;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name3643_n{};
                memcpy(_ca_street_name3643_n.data(), (_ca_street_name3643).data(), (_ca_street_name3643).length());
                std::string _ca_city3646 = (it->second)._ca_city3646;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city3646_n{};
                memcpy(_ca_city3646_n.data(), (_ca_city3646).data(), (_ca_city3646).length());
                std::string _ca_zip3649 = (it->second)._ca_zip3649;
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip3649_n{};
                memcpy(_ca_zip3649_n.data(), (_ca_zip3649).data(), (_ca_zip3649).length());
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_8755957_output.getInt32(i, 0);
                int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_8755957_output.getInt64(i, 1);
                int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_8755957_output.getInt64(i, 2);
                int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_8755957_output.getInt64(i, 3);
                int32_t _d_year126 = tbl_JOIN_INNER_TD_8755957_output.getInt32(i, 4);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_8755957_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _s_store_name383 = std::string(_s_store_name383_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_8755957_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _s_zip403 = std::string(_s_zip403_n.data());
                int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_8755957_output.getInt32(i, 7);
                int32_t _d_year3576 = tbl_JOIN_INNER_TD_8755957_output.getInt32(i, 8);
                int32_t _d_year3604 = tbl_JOIN_INNER_TD_8755957_output.getInt32(i, 9);
                int32_t _hd_income_band_sk205 = tbl_JOIN_INNER_TD_8755957_output.getInt32(i, 10);
                int32_t _hd_income_band_sk3636 = tbl_JOIN_INNER_TD_8755957_output.getInt32(i, 11);
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number56_n = tbl_JOIN_INNER_TD_8755957_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 12);
                std::string _ca_street_number56 = std::string(_ca_street_number56_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name57_n = tbl_JOIN_INNER_TD_8755957_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 13);
                std::string _ca_street_name57 = std::string(_ca_street_name57_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n = tbl_JOIN_INNER_TD_8755957_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 14);
                std::string _ca_city60 = std::string(_ca_city60_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n = tbl_JOIN_INNER_TD_8755957_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
                std::string _ca_zip63 = std::string(_ca_zip63_n.data());
                tbl_JOIN_INNER_TD_74545_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 15, _ca_street_number3642_n);
                tbl_JOIN_INNER_TD_74545_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 16, _ca_street_name3643_n);
                tbl_JOIN_INNER_TD_74545_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 17, _ca_city3646_n);
                tbl_JOIN_INNER_TD_74545_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 18, _ca_zip3649_n);
                tbl_JOIN_INNER_TD_74545_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_74545_output.setInt64(r, 1, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_74545_output.setInt64(r, 2, _ss_list_price1218);
                tbl_JOIN_INNER_TD_74545_output.setInt64(r, 3, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_74545_output.setInt32(r, 4, _d_year126);
                tbl_JOIN_INNER_TD_74545_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_store_name383_n);
                tbl_JOIN_INNER_TD_74545_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_zip403_n);
                tbl_JOIN_INNER_TD_74545_output.setInt32(r, 7, _d_year3576);
                tbl_JOIN_INNER_TD_74545_output.setInt32(r, 8, _d_year3604);
                tbl_JOIN_INNER_TD_74545_output.setInt32(r, 9, _hd_income_band_sk205);
                tbl_JOIN_INNER_TD_74545_output.setInt32(r, 10, _hd_income_band_sk3636);
                tbl_JOIN_INNER_TD_74545_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _ca_street_number56_n);
                tbl_JOIN_INNER_TD_74545_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _ca_street_name57_n);
                tbl_JOIN_INNER_TD_74545_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 13, _ca_city60_n);
                tbl_JOIN_INNER_TD_74545_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 14, _ca_zip63_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_74545_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_74545_output #Row: " << tbl_JOIN_INNER_TD_74545_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6220581(Table &tbl_SerializeFromObject_TD_7880239_input, Table &tbl_Filter_TD_6220581_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ib_income_band_sk#5069))
    // Input: ListBuffer(ib_income_band_sk#5069)
    // Output: ListBuffer(ib_income_band_sk#5069)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7880239_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ib_income_band_sk5069 = tbl_SerializeFromObject_TD_7880239_input.getInt32(i, 0);
        if (_ib_income_band_sk5069!= 0) {
            int32_t _ib_income_band_sk5069_t = tbl_SerializeFromObject_TD_7880239_input.getInt32(i, 0);
            tbl_Filter_TD_6220581_output.setInt32(r, 0, _ib_income_band_sk5069_t);
            r++;
        }
    }
    tbl_Filter_TD_6220581_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6220581_output #Row: " << tbl_Filter_TD_6220581_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6838150_key_leftMajor {
    int32_t _hd_income_band_sk5031;
    bool operator==(const SW_JOIN_INNER_TD_6838150_key_leftMajor& other) const {
        return ((_hd_income_band_sk5031 == other._hd_income_band_sk5031));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6838150_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6838150_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._hd_income_band_sk5031));
    }
};
}
struct SW_JOIN_INNER_TD_6838150_payload_leftMajor {
    int32_t _ss_item_sk4760;
    int64_t _ss_wholesale_cost4769;
    int64_t _ss_list_price4770;
    int64_t _ss_coupon_amt4777;
    int32_t _d_year4868;
    std::string _s_store_name4951;
    std::string _s_zip4971;
    int32_t _d_year4896;
    int32_t _d_year4924;
    int32_t _hd_income_band_sk5031;
    int32_t _hd_income_band_sk5036;
    std::string _ca_street_number5042;
    std::string _ca_street_name5043;
    std::string _ca_city5046;
    std::string _ca_zip5049;
    std::string _ca_street_number5055;
    std::string _ca_street_name5056;
    std::string _ca_city5059;
    std::string _ca_zip5062;
};
struct SW_JOIN_INNER_TD_6838150_key_rightMajor {
    int32_t _ib_income_band_sk5066;
    bool operator==(const SW_JOIN_INNER_TD_6838150_key_rightMajor& other) const {
        return ((_ib_income_band_sk5066 == other._ib_income_band_sk5066));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6838150_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6838150_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ib_income_band_sk5066));
    }
};
}
struct SW_JOIN_INNER_TD_6838150_payload_rightMajor {
    int32_t _ib_income_band_sk5066;
};
void SW_JOIN_INNER_TD_6838150(Table &tbl_JOIN_INNER_TD_7719384_output, Table &tbl_Filter_TD_7895840_output, Table &tbl_JOIN_INNER_TD_6838150_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((hd_income_band_sk#5031 = ib_income_band_sk#5066))
    // Left Table: ListBuffer(ss_item_sk#4760, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971, d_year#4896, d_year#4924, hd_income_band_sk#5031, hd_income_band_sk#5036, ca_street_number#5042, ca_street_name#5043, ca_city#5046, ca_zip#5049, ca_street_number#5055, ca_street_name#5056, ca_city#5059, ca_zip#5062)
    // Right Table: ListBuffer(ib_income_band_sk#5066)
    // Output Table: ListBuffer(ss_item_sk#4760, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971, d_year#4896, d_year#4924, hd_income_band_sk#5036, ca_street_number#5042, ca_street_name#5043, ca_city#5046, ca_zip#5049, ca_street_number#5055, ca_street_name#5056, ca_city#5059, ca_zip#5062)
    int left_nrow = tbl_JOIN_INNER_TD_7719384_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7895840_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6838150_key_leftMajor, SW_JOIN_INNER_TD_6838150_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7719384_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _hd_income_band_sk5031_k = tbl_JOIN_INNER_TD_7719384_output.getInt32(i, 9);
            SW_JOIN_INNER_TD_6838150_key_leftMajor keyA{_hd_income_band_sk5031_k};
            int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_7719384_output.getInt32(i, 0);
            int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_7719384_output.getInt64(i, 1);
            int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_7719384_output.getInt64(i, 2);
            int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_7719384_output.getInt64(i, 3);
            int32_t _d_year4868 = tbl_JOIN_INNER_TD_7719384_output.getInt32(i, 4);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_7719384_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_7719384_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _s_zip4971 = std::string(_s_zip4971_n.data());
            int32_t _d_year4896 = tbl_JOIN_INNER_TD_7719384_output.getInt32(i, 7);
            int32_t _d_year4924 = tbl_JOIN_INNER_TD_7719384_output.getInt32(i, 8);
            int32_t _hd_income_band_sk5031 = tbl_JOIN_INNER_TD_7719384_output.getInt32(i, 9);
            int32_t _hd_income_band_sk5036 = tbl_JOIN_INNER_TD_7719384_output.getInt32(i, 10);
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5042_n = tbl_JOIN_INNER_TD_7719384_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
            std::string _ca_street_number5042 = std::string(_ca_street_number5042_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5043_n = tbl_JOIN_INNER_TD_7719384_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 12);
            std::string _ca_street_name5043 = std::string(_ca_street_name5043_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_city5046_n = tbl_JOIN_INNER_TD_7719384_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 13);
            std::string _ca_city5046 = std::string(_ca_city5046_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip5049_n = tbl_JOIN_INNER_TD_7719384_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 14);
            std::string _ca_zip5049 = std::string(_ca_zip5049_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5055_n = tbl_JOIN_INNER_TD_7719384_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
            std::string _ca_street_number5055 = std::string(_ca_street_number5055_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5056_n = tbl_JOIN_INNER_TD_7719384_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 16);
            std::string _ca_street_name5056 = std::string(_ca_street_name5056_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_city5059_n = tbl_JOIN_INNER_TD_7719384_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 17);
            std::string _ca_city5059 = std::string(_ca_city5059_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip5062_n = tbl_JOIN_INNER_TD_7719384_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 18);
            std::string _ca_zip5062 = std::string(_ca_zip5062_n.data());
            SW_JOIN_INNER_TD_6838150_payload_leftMajor payloadA{_ss_item_sk4760, _ss_wholesale_cost4769, _ss_list_price4770, _ss_coupon_amt4777, _d_year4868, _s_store_name4951, _s_zip4971, _d_year4896, _d_year4924, _hd_income_band_sk5031, _hd_income_band_sk5036, _ca_street_number5042, _ca_street_name5043, _ca_city5046, _ca_zip5049, _ca_street_number5055, _ca_street_name5056, _ca_city5059, _ca_zip5062};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7895840_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ib_income_band_sk5066_k = tbl_Filter_TD_7895840_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6838150_key_leftMajor{_ib_income_band_sk5066_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk4760 = (it->second)._ss_item_sk4760;
                int64_t _ss_wholesale_cost4769 = (it->second)._ss_wholesale_cost4769;
                int64_t _ss_list_price4770 = (it->second)._ss_list_price4770;
                int64_t _ss_coupon_amt4777 = (it->second)._ss_coupon_amt4777;
                int32_t _d_year4868 = (it->second)._d_year4868;
                std::string _s_store_name4951 = (it->second)._s_store_name4951;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n{};
                memcpy(_s_store_name4951_n.data(), (_s_store_name4951).data(), (_s_store_name4951).length());
                std::string _s_zip4971 = (it->second)._s_zip4971;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n{};
                memcpy(_s_zip4971_n.data(), (_s_zip4971).data(), (_s_zip4971).length());
                int32_t _d_year4896 = (it->second)._d_year4896;
                int32_t _d_year4924 = (it->second)._d_year4924;
                int32_t _hd_income_band_sk5031 = (it->second)._hd_income_band_sk5031;
                int32_t _hd_income_band_sk5036 = (it->second)._hd_income_band_sk5036;
                std::string _ca_street_number5042 = (it->second)._ca_street_number5042;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5042_n{};
                memcpy(_ca_street_number5042_n.data(), (_ca_street_number5042).data(), (_ca_street_number5042).length());
                std::string _ca_street_name5043 = (it->second)._ca_street_name5043;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5043_n{};
                memcpy(_ca_street_name5043_n.data(), (_ca_street_name5043).data(), (_ca_street_name5043).length());
                std::string _ca_city5046 = (it->second)._ca_city5046;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city5046_n{};
                memcpy(_ca_city5046_n.data(), (_ca_city5046).data(), (_ca_city5046).length());
                std::string _ca_zip5049 = (it->second)._ca_zip5049;
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip5049_n{};
                memcpy(_ca_zip5049_n.data(), (_ca_zip5049).data(), (_ca_zip5049).length());
                std::string _ca_street_number5055 = (it->second)._ca_street_number5055;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5055_n{};
                memcpy(_ca_street_number5055_n.data(), (_ca_street_number5055).data(), (_ca_street_number5055).length());
                std::string _ca_street_name5056 = (it->second)._ca_street_name5056;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5056_n{};
                memcpy(_ca_street_name5056_n.data(), (_ca_street_name5056).data(), (_ca_street_name5056).length());
                std::string _ca_city5059 = (it->second)._ca_city5059;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city5059_n{};
                memcpy(_ca_city5059_n.data(), (_ca_city5059).data(), (_ca_city5059).length());
                std::string _ca_zip5062 = (it->second)._ca_zip5062;
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip5062_n{};
                memcpy(_ca_zip5062_n.data(), (_ca_zip5062).data(), (_ca_zip5062).length());
                int32_t _ib_income_band_sk5066 = tbl_Filter_TD_7895840_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_6838150_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_6838150_output.setInt64(r, 1, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_6838150_output.setInt64(r, 2, _ss_list_price4770);
                tbl_JOIN_INNER_TD_6838150_output.setInt64(r, 3, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_6838150_output.setInt32(r, 4, _d_year4868);
                tbl_JOIN_INNER_TD_6838150_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_6838150_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_zip4971_n);
                tbl_JOIN_INNER_TD_6838150_output.setInt32(r, 7, _d_year4896);
                tbl_JOIN_INNER_TD_6838150_output.setInt32(r, 8, _d_year4924);
                tbl_JOIN_INNER_TD_6838150_output.setInt32(r, 9, _hd_income_band_sk5036);
                tbl_JOIN_INNER_TD_6838150_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _ca_street_number5042_n);
                tbl_JOIN_INNER_TD_6838150_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _ca_street_name5043_n);
                tbl_JOIN_INNER_TD_6838150_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _ca_city5046_n);
                tbl_JOIN_INNER_TD_6838150_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 13, _ca_zip5049_n);
                tbl_JOIN_INNER_TD_6838150_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 14, _ca_street_number5055_n);
                tbl_JOIN_INNER_TD_6838150_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 15, _ca_street_name5056_n);
                tbl_JOIN_INNER_TD_6838150_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 16, _ca_city5059_n);
                tbl_JOIN_INNER_TD_6838150_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 17, _ca_zip5062_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6838150_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6838150_key_rightMajor, SW_JOIN_INNER_TD_6838150_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7895840_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ib_income_band_sk5066_k = tbl_Filter_TD_7895840_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6838150_key_rightMajor keyA{_ib_income_band_sk5066_k};
            int32_t _ib_income_band_sk5066 = tbl_Filter_TD_7895840_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6838150_payload_rightMajor payloadA{_ib_income_band_sk5066};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7719384_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _hd_income_band_sk5031_k = tbl_JOIN_INNER_TD_7719384_output.getInt32(i, 9);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6838150_key_rightMajor{_hd_income_band_sk5031_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ib_income_band_sk5066 = (it->second)._ib_income_band_sk5066;
                int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_7719384_output.getInt32(i, 0);
                int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_7719384_output.getInt64(i, 1);
                int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_7719384_output.getInt64(i, 2);
                int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_7719384_output.getInt64(i, 3);
                int32_t _d_year4868 = tbl_JOIN_INNER_TD_7719384_output.getInt32(i, 4);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_7719384_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_7719384_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _s_zip4971 = std::string(_s_zip4971_n.data());
                int32_t _d_year4896 = tbl_JOIN_INNER_TD_7719384_output.getInt32(i, 7);
                int32_t _d_year4924 = tbl_JOIN_INNER_TD_7719384_output.getInt32(i, 8);
                int32_t _hd_income_band_sk5031 = tbl_JOIN_INNER_TD_7719384_output.getInt32(i, 9);
                int32_t _hd_income_band_sk5036 = tbl_JOIN_INNER_TD_7719384_output.getInt32(i, 10);
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5042_n = tbl_JOIN_INNER_TD_7719384_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
                std::string _ca_street_number5042 = std::string(_ca_street_number5042_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5043_n = tbl_JOIN_INNER_TD_7719384_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 12);
                std::string _ca_street_name5043 = std::string(_ca_street_name5043_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_city5046_n = tbl_JOIN_INNER_TD_7719384_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 13);
                std::string _ca_city5046 = std::string(_ca_city5046_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip5049_n = tbl_JOIN_INNER_TD_7719384_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 14);
                std::string _ca_zip5049 = std::string(_ca_zip5049_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5055_n = tbl_JOIN_INNER_TD_7719384_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
                std::string _ca_street_number5055 = std::string(_ca_street_number5055_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5056_n = tbl_JOIN_INNER_TD_7719384_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 16);
                std::string _ca_street_name5056 = std::string(_ca_street_name5056_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_city5059_n = tbl_JOIN_INNER_TD_7719384_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 17);
                std::string _ca_city5059 = std::string(_ca_city5059_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip5062_n = tbl_JOIN_INNER_TD_7719384_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 18);
                std::string _ca_zip5062 = std::string(_ca_zip5062_n.data());
                tbl_JOIN_INNER_TD_6838150_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_6838150_output.setInt64(r, 1, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_6838150_output.setInt64(r, 2, _ss_list_price4770);
                tbl_JOIN_INNER_TD_6838150_output.setInt64(r, 3, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_6838150_output.setInt32(r, 4, _d_year4868);
                tbl_JOIN_INNER_TD_6838150_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_6838150_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_zip4971_n);
                tbl_JOIN_INNER_TD_6838150_output.setInt32(r, 7, _d_year4896);
                tbl_JOIN_INNER_TD_6838150_output.setInt32(r, 8, _d_year4924);
                tbl_JOIN_INNER_TD_6838150_output.setInt32(r, 9, _hd_income_band_sk5036);
                tbl_JOIN_INNER_TD_6838150_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _ca_street_number5042_n);
                tbl_JOIN_INNER_TD_6838150_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _ca_street_name5043_n);
                tbl_JOIN_INNER_TD_6838150_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _ca_city5046_n);
                tbl_JOIN_INNER_TD_6838150_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 13, _ca_zip5049_n);
                tbl_JOIN_INNER_TD_6838150_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 14, _ca_street_number5055_n);
                tbl_JOIN_INNER_TD_6838150_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 15, _ca_street_name5056_n);
                tbl_JOIN_INNER_TD_6838150_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 16, _ca_city5059_n);
                tbl_JOIN_INNER_TD_6838150_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 17, _ca_zip5062_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6838150_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6838150_output #Row: " << tbl_JOIN_INNER_TD_6838150_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6461371(Table &tbl_SerializeFromObject_TD_7194992_input, Table &tbl_Filter_TD_6461371_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ib_income_band_sk#3653))
    // Input: ListBuffer(ib_income_band_sk#3653)
    // Output: ListBuffer(ib_income_band_sk#3653)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7194992_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ib_income_band_sk3653 = tbl_SerializeFromObject_TD_7194992_input.getInt32(i, 0);
        if (_ib_income_band_sk3653!= 0) {
            int32_t _ib_income_band_sk3653_t = tbl_SerializeFromObject_TD_7194992_input.getInt32(i, 0);
            tbl_Filter_TD_6461371_output.setInt32(r, 0, _ib_income_band_sk3653_t);
            r++;
        }
    }
    tbl_Filter_TD_6461371_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6461371_output #Row: " << tbl_Filter_TD_6461371_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_653599_key_leftMajor {
    int32_t _hd_income_band_sk205;
    bool operator==(const SW_JOIN_INNER_TD_653599_key_leftMajor& other) const {
        return ((_hd_income_band_sk205 == other._hd_income_band_sk205));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_653599_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_653599_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._hd_income_band_sk205));
    }
};
}
struct SW_JOIN_INNER_TD_653599_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int64_t _ss_wholesale_cost1217;
    int64_t _ss_list_price1218;
    int64_t _ss_coupon_amt1225;
    int32_t _d_year126;
    std::string _s_store_name383;
    std::string _s_zip403;
    int32_t _d_year3576;
    int32_t _d_year3604;
    int32_t _hd_income_band_sk205;
    int32_t _hd_income_band_sk3636;
    std::string _ca_street_number56;
    std::string _ca_street_name57;
    std::string _ca_city60;
    std::string _ca_zip63;
    std::string _ca_street_number3642;
    std::string _ca_street_name3643;
    std::string _ca_city3646;
    std::string _ca_zip3649;
};
struct SW_JOIN_INNER_TD_653599_key_rightMajor {
    int32_t _ib_income_band_sk219;
    bool operator==(const SW_JOIN_INNER_TD_653599_key_rightMajor& other) const {
        return ((_ib_income_band_sk219 == other._ib_income_band_sk219));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_653599_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_653599_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ib_income_band_sk219));
    }
};
}
struct SW_JOIN_INNER_TD_653599_payload_rightMajor {
    int32_t _ib_income_band_sk219;
};
void SW_JOIN_INNER_TD_653599(Table &tbl_JOIN_INNER_TD_74545_output, Table &tbl_Filter_TD_727362_output, Table &tbl_JOIN_INNER_TD_653599_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((hd_income_band_sk#205 = ib_income_band_sk#219))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403, d_year#3576, d_year#3604, hd_income_band_sk#205, hd_income_band_sk#3636, ca_street_number#56, ca_street_name#57, ca_city#60, ca_zip#63, ca_street_number#3642, ca_street_name#3643, ca_city#3646, ca_zip#3649)
    // Right Table: ListBuffer(ib_income_band_sk#219)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403, d_year#3576, d_year#3604, hd_income_band_sk#3636, ca_street_number#56, ca_street_name#57, ca_city#60, ca_zip#63, ca_street_number#3642, ca_street_name#3643, ca_city#3646, ca_zip#3649)
    int left_nrow = tbl_JOIN_INNER_TD_74545_output.getNumRow();
    int right_nrow = tbl_Filter_TD_727362_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_653599_key_leftMajor, SW_JOIN_INNER_TD_653599_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_74545_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _hd_income_band_sk205_k = tbl_JOIN_INNER_TD_74545_output.getInt32(i, 9);
            SW_JOIN_INNER_TD_653599_key_leftMajor keyA{_hd_income_band_sk205_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_74545_output.getInt32(i, 0);
            int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_74545_output.getInt64(i, 1);
            int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_74545_output.getInt64(i, 2);
            int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_74545_output.getInt64(i, 3);
            int32_t _d_year126 = tbl_JOIN_INNER_TD_74545_output.getInt32(i, 4);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_74545_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _s_store_name383 = std::string(_s_store_name383_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_74545_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _s_zip403 = std::string(_s_zip403_n.data());
            int32_t _d_year3576 = tbl_JOIN_INNER_TD_74545_output.getInt32(i, 7);
            int32_t _d_year3604 = tbl_JOIN_INNER_TD_74545_output.getInt32(i, 8);
            int32_t _hd_income_band_sk205 = tbl_JOIN_INNER_TD_74545_output.getInt32(i, 9);
            int32_t _hd_income_band_sk3636 = tbl_JOIN_INNER_TD_74545_output.getInt32(i, 10);
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_number56_n = tbl_JOIN_INNER_TD_74545_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
            std::string _ca_street_number56 = std::string(_ca_street_number56_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_name57_n = tbl_JOIN_INNER_TD_74545_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 12);
            std::string _ca_street_name57 = std::string(_ca_street_name57_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n = tbl_JOIN_INNER_TD_74545_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 13);
            std::string _ca_city60 = std::string(_ca_city60_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n = tbl_JOIN_INNER_TD_74545_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 14);
            std::string _ca_zip63 = std::string(_ca_zip63_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_number3642_n = tbl_JOIN_INNER_TD_74545_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
            std::string _ca_street_number3642 = std::string(_ca_street_number3642_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_name3643_n = tbl_JOIN_INNER_TD_74545_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 16);
            std::string _ca_street_name3643 = std::string(_ca_street_name3643_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_city3646_n = tbl_JOIN_INNER_TD_74545_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 17);
            std::string _ca_city3646 = std::string(_ca_city3646_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip3649_n = tbl_JOIN_INNER_TD_74545_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 18);
            std::string _ca_zip3649 = std::string(_ca_zip3649_n.data());
            SW_JOIN_INNER_TD_653599_payload_leftMajor payloadA{_ss_item_sk1208, _ss_wholesale_cost1217, _ss_list_price1218, _ss_coupon_amt1225, _d_year126, _s_store_name383, _s_zip403, _d_year3576, _d_year3604, _hd_income_band_sk205, _hd_income_band_sk3636, _ca_street_number56, _ca_street_name57, _ca_city60, _ca_zip63, _ca_street_number3642, _ca_street_name3643, _ca_city3646, _ca_zip3649};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_727362_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ib_income_band_sk219_k = tbl_Filter_TD_727362_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_653599_key_leftMajor{_ib_income_band_sk219_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int64_t _ss_wholesale_cost1217 = (it->second)._ss_wholesale_cost1217;
                int64_t _ss_list_price1218 = (it->second)._ss_list_price1218;
                int64_t _ss_coupon_amt1225 = (it->second)._ss_coupon_amt1225;
                int32_t _d_year126 = (it->second)._d_year126;
                std::string _s_store_name383 = (it->second)._s_store_name383;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n{};
                memcpy(_s_store_name383_n.data(), (_s_store_name383).data(), (_s_store_name383).length());
                std::string _s_zip403 = (it->second)._s_zip403;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n{};
                memcpy(_s_zip403_n.data(), (_s_zip403).data(), (_s_zip403).length());
                int32_t _d_year3576 = (it->second)._d_year3576;
                int32_t _d_year3604 = (it->second)._d_year3604;
                int32_t _hd_income_band_sk205 = (it->second)._hd_income_band_sk205;
                int32_t _hd_income_band_sk3636 = (it->second)._hd_income_band_sk3636;
                std::string _ca_street_number56 = (it->second)._ca_street_number56;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number56_n{};
                memcpy(_ca_street_number56_n.data(), (_ca_street_number56).data(), (_ca_street_number56).length());
                std::string _ca_street_name57 = (it->second)._ca_street_name57;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name57_n{};
                memcpy(_ca_street_name57_n.data(), (_ca_street_name57).data(), (_ca_street_name57).length());
                std::string _ca_city60 = (it->second)._ca_city60;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n{};
                memcpy(_ca_city60_n.data(), (_ca_city60).data(), (_ca_city60).length());
                std::string _ca_zip63 = (it->second)._ca_zip63;
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n{};
                memcpy(_ca_zip63_n.data(), (_ca_zip63).data(), (_ca_zip63).length());
                std::string _ca_street_number3642 = (it->second)._ca_street_number3642;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number3642_n{};
                memcpy(_ca_street_number3642_n.data(), (_ca_street_number3642).data(), (_ca_street_number3642).length());
                std::string _ca_street_name3643 = (it->second)._ca_street_name3643;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name3643_n{};
                memcpy(_ca_street_name3643_n.data(), (_ca_street_name3643).data(), (_ca_street_name3643).length());
                std::string _ca_city3646 = (it->second)._ca_city3646;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city3646_n{};
                memcpy(_ca_city3646_n.data(), (_ca_city3646).data(), (_ca_city3646).length());
                std::string _ca_zip3649 = (it->second)._ca_zip3649;
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip3649_n{};
                memcpy(_ca_zip3649_n.data(), (_ca_zip3649).data(), (_ca_zip3649).length());
                int32_t _ib_income_band_sk219 = tbl_Filter_TD_727362_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_653599_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_653599_output.setInt64(r, 1, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_653599_output.setInt64(r, 2, _ss_list_price1218);
                tbl_JOIN_INNER_TD_653599_output.setInt64(r, 3, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_653599_output.setInt32(r, 4, _d_year126);
                tbl_JOIN_INNER_TD_653599_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_store_name383_n);
                tbl_JOIN_INNER_TD_653599_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_zip403_n);
                tbl_JOIN_INNER_TD_653599_output.setInt32(r, 7, _d_year3576);
                tbl_JOIN_INNER_TD_653599_output.setInt32(r, 8, _d_year3604);
                tbl_JOIN_INNER_TD_653599_output.setInt32(r, 9, _hd_income_band_sk3636);
                tbl_JOIN_INNER_TD_653599_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _ca_street_number56_n);
                tbl_JOIN_INNER_TD_653599_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _ca_street_name57_n);
                tbl_JOIN_INNER_TD_653599_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _ca_city60_n);
                tbl_JOIN_INNER_TD_653599_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 13, _ca_zip63_n);
                tbl_JOIN_INNER_TD_653599_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 14, _ca_street_number3642_n);
                tbl_JOIN_INNER_TD_653599_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 15, _ca_street_name3643_n);
                tbl_JOIN_INNER_TD_653599_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 16, _ca_city3646_n);
                tbl_JOIN_INNER_TD_653599_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 17, _ca_zip3649_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_653599_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_653599_key_rightMajor, SW_JOIN_INNER_TD_653599_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_727362_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ib_income_band_sk219_k = tbl_Filter_TD_727362_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_653599_key_rightMajor keyA{_ib_income_band_sk219_k};
            int32_t _ib_income_band_sk219 = tbl_Filter_TD_727362_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_653599_payload_rightMajor payloadA{_ib_income_band_sk219};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_74545_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _hd_income_band_sk205_k = tbl_JOIN_INNER_TD_74545_output.getInt32(i, 9);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_653599_key_rightMajor{_hd_income_band_sk205_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ib_income_band_sk219 = (it->second)._ib_income_band_sk219;
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_74545_output.getInt32(i, 0);
                int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_74545_output.getInt64(i, 1);
                int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_74545_output.getInt64(i, 2);
                int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_74545_output.getInt64(i, 3);
                int32_t _d_year126 = tbl_JOIN_INNER_TD_74545_output.getInt32(i, 4);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_74545_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _s_store_name383 = std::string(_s_store_name383_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_74545_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _s_zip403 = std::string(_s_zip403_n.data());
                int32_t _d_year3576 = tbl_JOIN_INNER_TD_74545_output.getInt32(i, 7);
                int32_t _d_year3604 = tbl_JOIN_INNER_TD_74545_output.getInt32(i, 8);
                int32_t _hd_income_band_sk205 = tbl_JOIN_INNER_TD_74545_output.getInt32(i, 9);
                int32_t _hd_income_band_sk3636 = tbl_JOIN_INNER_TD_74545_output.getInt32(i, 10);
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number56_n = tbl_JOIN_INNER_TD_74545_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
                std::string _ca_street_number56 = std::string(_ca_street_number56_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name57_n = tbl_JOIN_INNER_TD_74545_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 12);
                std::string _ca_street_name57 = std::string(_ca_street_name57_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n = tbl_JOIN_INNER_TD_74545_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 13);
                std::string _ca_city60 = std::string(_ca_city60_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n = tbl_JOIN_INNER_TD_74545_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 14);
                std::string _ca_zip63 = std::string(_ca_zip63_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number3642_n = tbl_JOIN_INNER_TD_74545_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
                std::string _ca_street_number3642 = std::string(_ca_street_number3642_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name3643_n = tbl_JOIN_INNER_TD_74545_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 16);
                std::string _ca_street_name3643 = std::string(_ca_street_name3643_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_city3646_n = tbl_JOIN_INNER_TD_74545_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 17);
                std::string _ca_city3646 = std::string(_ca_city3646_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip3649_n = tbl_JOIN_INNER_TD_74545_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 18);
                std::string _ca_zip3649 = std::string(_ca_zip3649_n.data());
                tbl_JOIN_INNER_TD_653599_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_653599_output.setInt64(r, 1, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_653599_output.setInt64(r, 2, _ss_list_price1218);
                tbl_JOIN_INNER_TD_653599_output.setInt64(r, 3, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_653599_output.setInt32(r, 4, _d_year126);
                tbl_JOIN_INNER_TD_653599_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_store_name383_n);
                tbl_JOIN_INNER_TD_653599_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_zip403_n);
                tbl_JOIN_INNER_TD_653599_output.setInt32(r, 7, _d_year3576);
                tbl_JOIN_INNER_TD_653599_output.setInt32(r, 8, _d_year3604);
                tbl_JOIN_INNER_TD_653599_output.setInt32(r, 9, _hd_income_band_sk3636);
                tbl_JOIN_INNER_TD_653599_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _ca_street_number56_n);
                tbl_JOIN_INNER_TD_653599_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _ca_street_name57_n);
                tbl_JOIN_INNER_TD_653599_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _ca_city60_n);
                tbl_JOIN_INNER_TD_653599_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 13, _ca_zip63_n);
                tbl_JOIN_INNER_TD_653599_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 14, _ca_street_number3642_n);
                tbl_JOIN_INNER_TD_653599_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 15, _ca_street_name3643_n);
                tbl_JOIN_INNER_TD_653599_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 16, _ca_city3646_n);
                tbl_JOIN_INNER_TD_653599_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 17, _ca_zip3649_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_653599_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_653599_output #Row: " << tbl_JOIN_INNER_TD_653599_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5514808(Table &tbl_SerializeFromObject_TD_6423713_input, Table &tbl_Filter_TD_5514808_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(i_current_price#5077) AND ((((i_color#5089 IN (purple,burlywood,indian,spring,floral,medium) AND (i_current_price#5077 >= 64.00)) AND (i_current_price#5077 <= 74.00)) AND (i_current_price#5077 >= 65.00)) AND (i_current_price#5077 <= 79.00))) AND isnotnull(i_item_sk#5072)))
    // Input: ListBuffer(i_item_sk#5072, i_product_name#5093, i_current_price#5077, i_color#5089)
    // Output: ListBuffer(i_item_sk#5072, i_product_name#5093)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6423713_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _i_current_price5077 = tbl_SerializeFromObject_TD_6423713_input.getInt64(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _i_color5089 = tbl_SerializeFromObject_TD_6423713_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        int32_t _i_item_sk5072 = tbl_SerializeFromObject_TD_6423713_input.getInt32(i, 0);
        auto reuse_col_str_662 = std::string(_i_color5089.data());
        if (((_i_current_price5077!= 0) && ((((((reuse_col_str_662 == "purple") || (reuse_col_str_662 == "burlywood") || (reuse_col_str_662 == "indian") || (reuse_col_str_662 == "spring") || (reuse_col_str_662 == "floral") || (reuse_col_str_662 == "medium") || (0)) && (_i_current_price5077 >= 64.00)) && (_i_current_price5077 <= 74.00)) && (_i_current_price5077 >= 65.00)) && (_i_current_price5077 <= 79.00))) && (_i_item_sk5072!= 0)) {
            int32_t _i_item_sk5072_t = tbl_SerializeFromObject_TD_6423713_input.getInt32(i, 0);
            tbl_Filter_TD_5514808_output.setInt32(r, 0, _i_item_sk5072_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_product_name5093_t = tbl_SerializeFromObject_TD_6423713_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_5514808_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_product_name5093_t);
            r++;
        }
    }
    tbl_Filter_TD_5514808_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5514808_output #Row: " << tbl_Filter_TD_5514808_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5724624_key_leftMajor {
    int32_t _hd_income_band_sk5036;
    bool operator==(const SW_JOIN_INNER_TD_5724624_key_leftMajor& other) const {
        return ((_hd_income_band_sk5036 == other._hd_income_band_sk5036));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5724624_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5724624_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._hd_income_band_sk5036));
    }
};
}
struct SW_JOIN_INNER_TD_5724624_payload_leftMajor {
    int32_t _ss_item_sk4760;
    int64_t _ss_wholesale_cost4769;
    int64_t _ss_list_price4770;
    int64_t _ss_coupon_amt4777;
    int32_t _d_year4868;
    std::string _s_store_name4951;
    std::string _s_zip4971;
    int32_t _d_year4896;
    int32_t _d_year4924;
    int32_t _hd_income_band_sk5036;
    std::string _ca_street_number5042;
    std::string _ca_street_name5043;
    std::string _ca_city5046;
    std::string _ca_zip5049;
    std::string _ca_street_number5055;
    std::string _ca_street_name5056;
    std::string _ca_city5059;
    std::string _ca_zip5062;
};
struct SW_JOIN_INNER_TD_5724624_key_rightMajor {
    int32_t _ib_income_band_sk5069;
    bool operator==(const SW_JOIN_INNER_TD_5724624_key_rightMajor& other) const {
        return ((_ib_income_band_sk5069 == other._ib_income_band_sk5069));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5724624_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5724624_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ib_income_band_sk5069));
    }
};
}
struct SW_JOIN_INNER_TD_5724624_payload_rightMajor {
    int32_t _ib_income_band_sk5069;
};
void SW_JOIN_INNER_TD_5724624(Table &tbl_JOIN_INNER_TD_6838150_output, Table &tbl_Filter_TD_6220581_output, Table &tbl_JOIN_INNER_TD_5724624_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((hd_income_band_sk#5036 = ib_income_band_sk#5069))
    // Left Table: ListBuffer(ss_item_sk#4760, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971, d_year#4896, d_year#4924, hd_income_band_sk#5036, ca_street_number#5042, ca_street_name#5043, ca_city#5046, ca_zip#5049, ca_street_number#5055, ca_street_name#5056, ca_city#5059, ca_zip#5062)
    // Right Table: ListBuffer(ib_income_band_sk#5069)
    // Output Table: ListBuffer(ss_item_sk#4760, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971, d_year#4896, d_year#4924, ca_street_number#5042, ca_street_name#5043, ca_city#5046, ca_zip#5049, ca_street_number#5055, ca_street_name#5056, ca_city#5059, ca_zip#5062)
    int left_nrow = tbl_JOIN_INNER_TD_6838150_output.getNumRow();
    int right_nrow = tbl_Filter_TD_6220581_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5724624_key_leftMajor, SW_JOIN_INNER_TD_5724624_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_6838150_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _hd_income_band_sk5036_k = tbl_JOIN_INNER_TD_6838150_output.getInt32(i, 9);
            SW_JOIN_INNER_TD_5724624_key_leftMajor keyA{_hd_income_band_sk5036_k};
            int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_6838150_output.getInt32(i, 0);
            int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_6838150_output.getInt64(i, 1);
            int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_6838150_output.getInt64(i, 2);
            int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_6838150_output.getInt64(i, 3);
            int32_t _d_year4868 = tbl_JOIN_INNER_TD_6838150_output.getInt32(i, 4);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_6838150_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_6838150_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _s_zip4971 = std::string(_s_zip4971_n.data());
            int32_t _d_year4896 = tbl_JOIN_INNER_TD_6838150_output.getInt32(i, 7);
            int32_t _d_year4924 = tbl_JOIN_INNER_TD_6838150_output.getInt32(i, 8);
            int32_t _hd_income_band_sk5036 = tbl_JOIN_INNER_TD_6838150_output.getInt32(i, 9);
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5042_n = tbl_JOIN_INNER_TD_6838150_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            std::string _ca_street_number5042 = std::string(_ca_street_number5042_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5043_n = tbl_JOIN_INNER_TD_6838150_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
            std::string _ca_street_name5043 = std::string(_ca_street_name5043_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_city5046_n = tbl_JOIN_INNER_TD_6838150_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 12);
            std::string _ca_city5046 = std::string(_ca_city5046_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip5049_n = tbl_JOIN_INNER_TD_6838150_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 13);
            std::string _ca_zip5049 = std::string(_ca_zip5049_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5055_n = tbl_JOIN_INNER_TD_6838150_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 14);
            std::string _ca_street_number5055 = std::string(_ca_street_number5055_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5056_n = tbl_JOIN_INNER_TD_6838150_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
            std::string _ca_street_name5056 = std::string(_ca_street_name5056_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_city5059_n = tbl_JOIN_INNER_TD_6838150_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 16);
            std::string _ca_city5059 = std::string(_ca_city5059_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip5062_n = tbl_JOIN_INNER_TD_6838150_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 17);
            std::string _ca_zip5062 = std::string(_ca_zip5062_n.data());
            SW_JOIN_INNER_TD_5724624_payload_leftMajor payloadA{_ss_item_sk4760, _ss_wholesale_cost4769, _ss_list_price4770, _ss_coupon_amt4777, _d_year4868, _s_store_name4951, _s_zip4971, _d_year4896, _d_year4924, _hd_income_band_sk5036, _ca_street_number5042, _ca_street_name5043, _ca_city5046, _ca_zip5049, _ca_street_number5055, _ca_street_name5056, _ca_city5059, _ca_zip5062};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6220581_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ib_income_band_sk5069_k = tbl_Filter_TD_6220581_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5724624_key_leftMajor{_ib_income_band_sk5069_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk4760 = (it->second)._ss_item_sk4760;
                int64_t _ss_wholesale_cost4769 = (it->second)._ss_wholesale_cost4769;
                int64_t _ss_list_price4770 = (it->second)._ss_list_price4770;
                int64_t _ss_coupon_amt4777 = (it->second)._ss_coupon_amt4777;
                int32_t _d_year4868 = (it->second)._d_year4868;
                std::string _s_store_name4951 = (it->second)._s_store_name4951;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n{};
                memcpy(_s_store_name4951_n.data(), (_s_store_name4951).data(), (_s_store_name4951).length());
                std::string _s_zip4971 = (it->second)._s_zip4971;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n{};
                memcpy(_s_zip4971_n.data(), (_s_zip4971).data(), (_s_zip4971).length());
                int32_t _d_year4896 = (it->second)._d_year4896;
                int32_t _d_year4924 = (it->second)._d_year4924;
                int32_t _hd_income_band_sk5036 = (it->second)._hd_income_band_sk5036;
                std::string _ca_street_number5042 = (it->second)._ca_street_number5042;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5042_n{};
                memcpy(_ca_street_number5042_n.data(), (_ca_street_number5042).data(), (_ca_street_number5042).length());
                std::string _ca_street_name5043 = (it->second)._ca_street_name5043;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5043_n{};
                memcpy(_ca_street_name5043_n.data(), (_ca_street_name5043).data(), (_ca_street_name5043).length());
                std::string _ca_city5046 = (it->second)._ca_city5046;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city5046_n{};
                memcpy(_ca_city5046_n.data(), (_ca_city5046).data(), (_ca_city5046).length());
                std::string _ca_zip5049 = (it->second)._ca_zip5049;
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip5049_n{};
                memcpy(_ca_zip5049_n.data(), (_ca_zip5049).data(), (_ca_zip5049).length());
                std::string _ca_street_number5055 = (it->second)._ca_street_number5055;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5055_n{};
                memcpy(_ca_street_number5055_n.data(), (_ca_street_number5055).data(), (_ca_street_number5055).length());
                std::string _ca_street_name5056 = (it->second)._ca_street_name5056;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5056_n{};
                memcpy(_ca_street_name5056_n.data(), (_ca_street_name5056).data(), (_ca_street_name5056).length());
                std::string _ca_city5059 = (it->second)._ca_city5059;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city5059_n{};
                memcpy(_ca_city5059_n.data(), (_ca_city5059).data(), (_ca_city5059).length());
                std::string _ca_zip5062 = (it->second)._ca_zip5062;
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip5062_n{};
                memcpy(_ca_zip5062_n.data(), (_ca_zip5062).data(), (_ca_zip5062).length());
                int32_t _ib_income_band_sk5069 = tbl_Filter_TD_6220581_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_5724624_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_5724624_output.setInt64(r, 1, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_5724624_output.setInt64(r, 2, _ss_list_price4770);
                tbl_JOIN_INNER_TD_5724624_output.setInt64(r, 3, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_5724624_output.setInt32(r, 4, _d_year4868);
                tbl_JOIN_INNER_TD_5724624_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_5724624_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_zip4971_n);
                tbl_JOIN_INNER_TD_5724624_output.setInt32(r, 7, _d_year4896);
                tbl_JOIN_INNER_TD_5724624_output.setInt32(r, 8, _d_year4924);
                tbl_JOIN_INNER_TD_5724624_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _ca_street_number5042_n);
                tbl_JOIN_INNER_TD_5724624_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _ca_street_name5043_n);
                tbl_JOIN_INNER_TD_5724624_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _ca_city5046_n);
                tbl_JOIN_INNER_TD_5724624_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _ca_zip5049_n);
                tbl_JOIN_INNER_TD_5724624_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 13, _ca_street_number5055_n);
                tbl_JOIN_INNER_TD_5724624_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 14, _ca_street_name5056_n);
                tbl_JOIN_INNER_TD_5724624_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 15, _ca_city5059_n);
                tbl_JOIN_INNER_TD_5724624_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 16, _ca_zip5062_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5724624_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5724624_key_rightMajor, SW_JOIN_INNER_TD_5724624_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_6220581_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ib_income_band_sk5069_k = tbl_Filter_TD_6220581_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5724624_key_rightMajor keyA{_ib_income_band_sk5069_k};
            int32_t _ib_income_band_sk5069 = tbl_Filter_TD_6220581_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5724624_payload_rightMajor payloadA{_ib_income_band_sk5069};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_6838150_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _hd_income_band_sk5036_k = tbl_JOIN_INNER_TD_6838150_output.getInt32(i, 9);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5724624_key_rightMajor{_hd_income_band_sk5036_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ib_income_band_sk5069 = (it->second)._ib_income_band_sk5069;
                int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_6838150_output.getInt32(i, 0);
                int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_6838150_output.getInt64(i, 1);
                int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_6838150_output.getInt64(i, 2);
                int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_6838150_output.getInt64(i, 3);
                int32_t _d_year4868 = tbl_JOIN_INNER_TD_6838150_output.getInt32(i, 4);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_6838150_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_6838150_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _s_zip4971 = std::string(_s_zip4971_n.data());
                int32_t _d_year4896 = tbl_JOIN_INNER_TD_6838150_output.getInt32(i, 7);
                int32_t _d_year4924 = tbl_JOIN_INNER_TD_6838150_output.getInt32(i, 8);
                int32_t _hd_income_band_sk5036 = tbl_JOIN_INNER_TD_6838150_output.getInt32(i, 9);
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5042_n = tbl_JOIN_INNER_TD_6838150_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
                std::string _ca_street_number5042 = std::string(_ca_street_number5042_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5043_n = tbl_JOIN_INNER_TD_6838150_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
                std::string _ca_street_name5043 = std::string(_ca_street_name5043_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_city5046_n = tbl_JOIN_INNER_TD_6838150_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 12);
                std::string _ca_city5046 = std::string(_ca_city5046_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip5049_n = tbl_JOIN_INNER_TD_6838150_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 13);
                std::string _ca_zip5049 = std::string(_ca_zip5049_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5055_n = tbl_JOIN_INNER_TD_6838150_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 14);
                std::string _ca_street_number5055 = std::string(_ca_street_number5055_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5056_n = tbl_JOIN_INNER_TD_6838150_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
                std::string _ca_street_name5056 = std::string(_ca_street_name5056_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_city5059_n = tbl_JOIN_INNER_TD_6838150_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 16);
                std::string _ca_city5059 = std::string(_ca_city5059_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip5062_n = tbl_JOIN_INNER_TD_6838150_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 17);
                std::string _ca_zip5062 = std::string(_ca_zip5062_n.data());
                tbl_JOIN_INNER_TD_5724624_output.setInt32(r, 0, _ss_item_sk4760);
                tbl_JOIN_INNER_TD_5724624_output.setInt64(r, 1, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_5724624_output.setInt64(r, 2, _ss_list_price4770);
                tbl_JOIN_INNER_TD_5724624_output.setInt64(r, 3, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_5724624_output.setInt32(r, 4, _d_year4868);
                tbl_JOIN_INNER_TD_5724624_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_5724624_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_zip4971_n);
                tbl_JOIN_INNER_TD_5724624_output.setInt32(r, 7, _d_year4896);
                tbl_JOIN_INNER_TD_5724624_output.setInt32(r, 8, _d_year4924);
                tbl_JOIN_INNER_TD_5724624_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _ca_street_number5042_n);
                tbl_JOIN_INNER_TD_5724624_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _ca_street_name5043_n);
                tbl_JOIN_INNER_TD_5724624_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _ca_city5046_n);
                tbl_JOIN_INNER_TD_5724624_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _ca_zip5049_n);
                tbl_JOIN_INNER_TD_5724624_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 13, _ca_street_number5055_n);
                tbl_JOIN_INNER_TD_5724624_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 14, _ca_street_name5056_n);
                tbl_JOIN_INNER_TD_5724624_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 15, _ca_city5059_n);
                tbl_JOIN_INNER_TD_5724624_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 16, _ca_zip5062_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5724624_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5724624_output #Row: " << tbl_JOIN_INNER_TD_5724624_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5748863(Table &tbl_SerializeFromObject_TD_6648753_input, Table &tbl_Filter_TD_5748863_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(i_current_price#233) AND ((((i_color#245 IN (purple,burlywood,indian,spring,floral,medium) AND (i_current_price#233 >= 64.00)) AND (i_current_price#233 <= 74.00)) AND (i_current_price#233 >= 65.00)) AND (i_current_price#233 <= 79.00))) AND isnotnull(i_item_sk#228)))
    // Input: ListBuffer(i_item_sk#228, i_product_name#249, i_current_price#233, i_color#245)
    // Output: ListBuffer(i_item_sk#228, i_product_name#249)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6648753_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _i_current_price233 = tbl_SerializeFromObject_TD_6648753_input.getInt64(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _i_color245 = tbl_SerializeFromObject_TD_6648753_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_6648753_input.getInt32(i, 0);
        auto reuse_col_str_180 = std::string(_i_color245.data());
        if (((_i_current_price233!= 0) && ((((((reuse_col_str_180 == "purple") || (reuse_col_str_180 == "burlywood") || (reuse_col_str_180 == "indian") || (reuse_col_str_180 == "spring") || (reuse_col_str_180 == "floral") || (reuse_col_str_180 == "medium") || (0)) && (_i_current_price233 >= 64.00)) && (_i_current_price233 <= 74.00)) && (_i_current_price233 >= 65.00)) && (_i_current_price233 <= 79.00))) && (_i_item_sk228!= 0)) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_6648753_input.getInt32(i, 0);
            tbl_Filter_TD_5748863_output.setInt32(r, 0, _i_item_sk228_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_product_name249_t = tbl_SerializeFromObject_TD_6648753_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_5748863_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_product_name249_t);
            r++;
        }
    }
    tbl_Filter_TD_5748863_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5748863_output #Row: " << tbl_Filter_TD_5748863_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5927078_key_leftMajor {
    int32_t _hd_income_band_sk3636;
    bool operator==(const SW_JOIN_INNER_TD_5927078_key_leftMajor& other) const {
        return ((_hd_income_band_sk3636 == other._hd_income_band_sk3636));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5927078_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5927078_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._hd_income_band_sk3636));
    }
};
}
struct SW_JOIN_INNER_TD_5927078_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int64_t _ss_wholesale_cost1217;
    int64_t _ss_list_price1218;
    int64_t _ss_coupon_amt1225;
    int32_t _d_year126;
    std::string _s_store_name383;
    std::string _s_zip403;
    int32_t _d_year3576;
    int32_t _d_year3604;
    int32_t _hd_income_band_sk3636;
    std::string _ca_street_number56;
    std::string _ca_street_name57;
    std::string _ca_city60;
    std::string _ca_zip63;
    std::string _ca_street_number3642;
    std::string _ca_street_name3643;
    std::string _ca_city3646;
    std::string _ca_zip3649;
};
struct SW_JOIN_INNER_TD_5927078_key_rightMajor {
    int32_t _ib_income_band_sk3653;
    bool operator==(const SW_JOIN_INNER_TD_5927078_key_rightMajor& other) const {
        return ((_ib_income_band_sk3653 == other._ib_income_band_sk3653));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5927078_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5927078_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ib_income_band_sk3653));
    }
};
}
struct SW_JOIN_INNER_TD_5927078_payload_rightMajor {
    int32_t _ib_income_band_sk3653;
};
void SW_JOIN_INNER_TD_5927078(Table &tbl_JOIN_INNER_TD_653599_output, Table &tbl_Filter_TD_6461371_output, Table &tbl_JOIN_INNER_TD_5927078_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((hd_income_band_sk#3636 = ib_income_band_sk#3653))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403, d_year#3576, d_year#3604, hd_income_band_sk#3636, ca_street_number#56, ca_street_name#57, ca_city#60, ca_zip#63, ca_street_number#3642, ca_street_name#3643, ca_city#3646, ca_zip#3649)
    // Right Table: ListBuffer(ib_income_band_sk#3653)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403, d_year#3576, d_year#3604, ca_street_number#56, ca_street_name#57, ca_city#60, ca_zip#63, ca_street_number#3642, ca_street_name#3643, ca_city#3646, ca_zip#3649)
    int left_nrow = tbl_JOIN_INNER_TD_653599_output.getNumRow();
    int right_nrow = tbl_Filter_TD_6461371_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5927078_key_leftMajor, SW_JOIN_INNER_TD_5927078_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_653599_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _hd_income_band_sk3636_k = tbl_JOIN_INNER_TD_653599_output.getInt32(i, 9);
            SW_JOIN_INNER_TD_5927078_key_leftMajor keyA{_hd_income_band_sk3636_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_653599_output.getInt32(i, 0);
            int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_653599_output.getInt64(i, 1);
            int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_653599_output.getInt64(i, 2);
            int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_653599_output.getInt64(i, 3);
            int32_t _d_year126 = tbl_JOIN_INNER_TD_653599_output.getInt32(i, 4);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_653599_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _s_store_name383 = std::string(_s_store_name383_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_653599_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _s_zip403 = std::string(_s_zip403_n.data());
            int32_t _d_year3576 = tbl_JOIN_INNER_TD_653599_output.getInt32(i, 7);
            int32_t _d_year3604 = tbl_JOIN_INNER_TD_653599_output.getInt32(i, 8);
            int32_t _hd_income_band_sk3636 = tbl_JOIN_INNER_TD_653599_output.getInt32(i, 9);
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_number56_n = tbl_JOIN_INNER_TD_653599_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            std::string _ca_street_number56 = std::string(_ca_street_number56_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_name57_n = tbl_JOIN_INNER_TD_653599_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
            std::string _ca_street_name57 = std::string(_ca_street_name57_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n = tbl_JOIN_INNER_TD_653599_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 12);
            std::string _ca_city60 = std::string(_ca_city60_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n = tbl_JOIN_INNER_TD_653599_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 13);
            std::string _ca_zip63 = std::string(_ca_zip63_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_number3642_n = tbl_JOIN_INNER_TD_653599_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 14);
            std::string _ca_street_number3642 = std::string(_ca_street_number3642_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_name3643_n = tbl_JOIN_INNER_TD_653599_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
            std::string _ca_street_name3643 = std::string(_ca_street_name3643_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_city3646_n = tbl_JOIN_INNER_TD_653599_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 16);
            std::string _ca_city3646 = std::string(_ca_city3646_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip3649_n = tbl_JOIN_INNER_TD_653599_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 17);
            std::string _ca_zip3649 = std::string(_ca_zip3649_n.data());
            SW_JOIN_INNER_TD_5927078_payload_leftMajor payloadA{_ss_item_sk1208, _ss_wholesale_cost1217, _ss_list_price1218, _ss_coupon_amt1225, _d_year126, _s_store_name383, _s_zip403, _d_year3576, _d_year3604, _hd_income_band_sk3636, _ca_street_number56, _ca_street_name57, _ca_city60, _ca_zip63, _ca_street_number3642, _ca_street_name3643, _ca_city3646, _ca_zip3649};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6461371_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ib_income_band_sk3653_k = tbl_Filter_TD_6461371_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5927078_key_leftMajor{_ib_income_band_sk3653_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int64_t _ss_wholesale_cost1217 = (it->second)._ss_wholesale_cost1217;
                int64_t _ss_list_price1218 = (it->second)._ss_list_price1218;
                int64_t _ss_coupon_amt1225 = (it->second)._ss_coupon_amt1225;
                int32_t _d_year126 = (it->second)._d_year126;
                std::string _s_store_name383 = (it->second)._s_store_name383;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n{};
                memcpy(_s_store_name383_n.data(), (_s_store_name383).data(), (_s_store_name383).length());
                std::string _s_zip403 = (it->second)._s_zip403;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n{};
                memcpy(_s_zip403_n.data(), (_s_zip403).data(), (_s_zip403).length());
                int32_t _d_year3576 = (it->second)._d_year3576;
                int32_t _d_year3604 = (it->second)._d_year3604;
                int32_t _hd_income_band_sk3636 = (it->second)._hd_income_band_sk3636;
                std::string _ca_street_number56 = (it->second)._ca_street_number56;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number56_n{};
                memcpy(_ca_street_number56_n.data(), (_ca_street_number56).data(), (_ca_street_number56).length());
                std::string _ca_street_name57 = (it->second)._ca_street_name57;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name57_n{};
                memcpy(_ca_street_name57_n.data(), (_ca_street_name57).data(), (_ca_street_name57).length());
                std::string _ca_city60 = (it->second)._ca_city60;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n{};
                memcpy(_ca_city60_n.data(), (_ca_city60).data(), (_ca_city60).length());
                std::string _ca_zip63 = (it->second)._ca_zip63;
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n{};
                memcpy(_ca_zip63_n.data(), (_ca_zip63).data(), (_ca_zip63).length());
                std::string _ca_street_number3642 = (it->second)._ca_street_number3642;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number3642_n{};
                memcpy(_ca_street_number3642_n.data(), (_ca_street_number3642).data(), (_ca_street_number3642).length());
                std::string _ca_street_name3643 = (it->second)._ca_street_name3643;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name3643_n{};
                memcpy(_ca_street_name3643_n.data(), (_ca_street_name3643).data(), (_ca_street_name3643).length());
                std::string _ca_city3646 = (it->second)._ca_city3646;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city3646_n{};
                memcpy(_ca_city3646_n.data(), (_ca_city3646).data(), (_ca_city3646).length());
                std::string _ca_zip3649 = (it->second)._ca_zip3649;
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip3649_n{};
                memcpy(_ca_zip3649_n.data(), (_ca_zip3649).data(), (_ca_zip3649).length());
                int32_t _ib_income_band_sk3653 = tbl_Filter_TD_6461371_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_5927078_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_5927078_output.setInt64(r, 1, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_5927078_output.setInt64(r, 2, _ss_list_price1218);
                tbl_JOIN_INNER_TD_5927078_output.setInt64(r, 3, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_5927078_output.setInt32(r, 4, _d_year126);
                tbl_JOIN_INNER_TD_5927078_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_store_name383_n);
                tbl_JOIN_INNER_TD_5927078_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_zip403_n);
                tbl_JOIN_INNER_TD_5927078_output.setInt32(r, 7, _d_year3576);
                tbl_JOIN_INNER_TD_5927078_output.setInt32(r, 8, _d_year3604);
                tbl_JOIN_INNER_TD_5927078_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _ca_street_number56_n);
                tbl_JOIN_INNER_TD_5927078_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _ca_street_name57_n);
                tbl_JOIN_INNER_TD_5927078_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _ca_city60_n);
                tbl_JOIN_INNER_TD_5927078_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _ca_zip63_n);
                tbl_JOIN_INNER_TD_5927078_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 13, _ca_street_number3642_n);
                tbl_JOIN_INNER_TD_5927078_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 14, _ca_street_name3643_n);
                tbl_JOIN_INNER_TD_5927078_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 15, _ca_city3646_n);
                tbl_JOIN_INNER_TD_5927078_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 16, _ca_zip3649_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5927078_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5927078_key_rightMajor, SW_JOIN_INNER_TD_5927078_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_6461371_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ib_income_band_sk3653_k = tbl_Filter_TD_6461371_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5927078_key_rightMajor keyA{_ib_income_band_sk3653_k};
            int32_t _ib_income_band_sk3653 = tbl_Filter_TD_6461371_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5927078_payload_rightMajor payloadA{_ib_income_band_sk3653};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_653599_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _hd_income_band_sk3636_k = tbl_JOIN_INNER_TD_653599_output.getInt32(i, 9);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5927078_key_rightMajor{_hd_income_band_sk3636_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ib_income_band_sk3653 = (it->second)._ib_income_band_sk3653;
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_653599_output.getInt32(i, 0);
                int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_653599_output.getInt64(i, 1);
                int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_653599_output.getInt64(i, 2);
                int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_653599_output.getInt64(i, 3);
                int32_t _d_year126 = tbl_JOIN_INNER_TD_653599_output.getInt32(i, 4);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_653599_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _s_store_name383 = std::string(_s_store_name383_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_653599_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _s_zip403 = std::string(_s_zip403_n.data());
                int32_t _d_year3576 = tbl_JOIN_INNER_TD_653599_output.getInt32(i, 7);
                int32_t _d_year3604 = tbl_JOIN_INNER_TD_653599_output.getInt32(i, 8);
                int32_t _hd_income_band_sk3636 = tbl_JOIN_INNER_TD_653599_output.getInt32(i, 9);
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number56_n = tbl_JOIN_INNER_TD_653599_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
                std::string _ca_street_number56 = std::string(_ca_street_number56_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name57_n = tbl_JOIN_INNER_TD_653599_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
                std::string _ca_street_name57 = std::string(_ca_street_name57_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n = tbl_JOIN_INNER_TD_653599_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 12);
                std::string _ca_city60 = std::string(_ca_city60_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n = tbl_JOIN_INNER_TD_653599_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 13);
                std::string _ca_zip63 = std::string(_ca_zip63_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number3642_n = tbl_JOIN_INNER_TD_653599_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 14);
                std::string _ca_street_number3642 = std::string(_ca_street_number3642_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name3643_n = tbl_JOIN_INNER_TD_653599_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
                std::string _ca_street_name3643 = std::string(_ca_street_name3643_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_city3646_n = tbl_JOIN_INNER_TD_653599_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 16);
                std::string _ca_city3646 = std::string(_ca_city3646_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip3649_n = tbl_JOIN_INNER_TD_653599_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 17);
                std::string _ca_zip3649 = std::string(_ca_zip3649_n.data());
                tbl_JOIN_INNER_TD_5927078_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_5927078_output.setInt64(r, 1, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_5927078_output.setInt64(r, 2, _ss_list_price1218);
                tbl_JOIN_INNER_TD_5927078_output.setInt64(r, 3, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_5927078_output.setInt32(r, 4, _d_year126);
                tbl_JOIN_INNER_TD_5927078_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_store_name383_n);
                tbl_JOIN_INNER_TD_5927078_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_zip403_n);
                tbl_JOIN_INNER_TD_5927078_output.setInt32(r, 7, _d_year3576);
                tbl_JOIN_INNER_TD_5927078_output.setInt32(r, 8, _d_year3604);
                tbl_JOIN_INNER_TD_5927078_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _ca_street_number56_n);
                tbl_JOIN_INNER_TD_5927078_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _ca_street_name57_n);
                tbl_JOIN_INNER_TD_5927078_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _ca_city60_n);
                tbl_JOIN_INNER_TD_5927078_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _ca_zip63_n);
                tbl_JOIN_INNER_TD_5927078_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 13, _ca_street_number3642_n);
                tbl_JOIN_INNER_TD_5927078_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 14, _ca_street_name3643_n);
                tbl_JOIN_INNER_TD_5927078_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 15, _ca_city3646_n);
                tbl_JOIN_INNER_TD_5927078_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 16, _ca_zip3649_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5927078_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5927078_output #Row: " << tbl_JOIN_INNER_TD_5927078_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4452906_key_leftMajor {
    int32_t _ss_item_sk4760;
    bool operator==(const SW_JOIN_INNER_TD_4452906_key_leftMajor& other) const {
        return ((_ss_item_sk4760 == other._ss_item_sk4760));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4452906_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4452906_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk4760));
    }
};
}
struct SW_JOIN_INNER_TD_4452906_payload_leftMajor {
    int32_t _ss_item_sk4760;
    int64_t _ss_wholesale_cost4769;
    int64_t _ss_list_price4770;
    int64_t _ss_coupon_amt4777;
    int32_t _d_year4868;
    std::string _s_store_name4951;
    std::string _s_zip4971;
    int32_t _d_year4896;
    int32_t _d_year4924;
    std::string _ca_street_number5042;
    std::string _ca_street_name5043;
    std::string _ca_city5046;
    std::string _ca_zip5049;
    std::string _ca_street_number5055;
    std::string _ca_street_name5056;
    std::string _ca_city5059;
    std::string _ca_zip5062;
};
struct SW_JOIN_INNER_TD_4452906_key_rightMajor {
    int32_t _i_item_sk5072;
    bool operator==(const SW_JOIN_INNER_TD_4452906_key_rightMajor& other) const {
        return ((_i_item_sk5072 == other._i_item_sk5072));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4452906_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4452906_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk5072));
    }
};
}
struct SW_JOIN_INNER_TD_4452906_payload_rightMajor {
    int32_t _i_item_sk5072;
    std::string _i_product_name5093;
};
void SW_JOIN_INNER_TD_4452906(Table &tbl_JOIN_INNER_TD_5724624_output, Table &tbl_Filter_TD_5514808_output, Table &tbl_JOIN_INNER_TD_4452906_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_item_sk#4760 = i_item_sk#5072))
    // Left Table: ListBuffer(ss_item_sk#4760, ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, s_store_name#4951, s_zip#4971, d_year#4896, d_year#4924, ca_street_number#5042, ca_street_name#5043, ca_city#5046, ca_zip#5049, ca_street_number#5055, ca_street_name#5056, ca_city#5059, ca_zip#5062)
    // Right Table: ListBuffer(i_item_sk#5072, i_product_name#5093)
    // Output Table: ListBuffer(ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, d_year#4896, d_year#4924, s_store_name#4951, s_zip#4971, ca_street_number#5042, ca_street_name#5043, ca_city#5046, ca_zip#5049, ca_street_number#5055, ca_street_name#5056, ca_city#5059, ca_zip#5062, i_item_sk#5072, i_product_name#5093)
    int left_nrow = tbl_JOIN_INNER_TD_5724624_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5514808_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4452906_key_leftMajor, SW_JOIN_INNER_TD_4452906_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_5724624_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk4760_k = tbl_JOIN_INNER_TD_5724624_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4452906_key_leftMajor keyA{_ss_item_sk4760_k};
            int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_5724624_output.getInt32(i, 0);
            int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_5724624_output.getInt64(i, 1);
            int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_5724624_output.getInt64(i, 2);
            int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_5724624_output.getInt64(i, 3);
            int32_t _d_year4868 = tbl_JOIN_INNER_TD_5724624_output.getInt32(i, 4);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_5724624_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_5724624_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _s_zip4971 = std::string(_s_zip4971_n.data());
            int32_t _d_year4896 = tbl_JOIN_INNER_TD_5724624_output.getInt32(i, 7);
            int32_t _d_year4924 = tbl_JOIN_INNER_TD_5724624_output.getInt32(i, 8);
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5042_n = tbl_JOIN_INNER_TD_5724624_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            std::string _ca_street_number5042 = std::string(_ca_street_number5042_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5043_n = tbl_JOIN_INNER_TD_5724624_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            std::string _ca_street_name5043 = std::string(_ca_street_name5043_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_city5046_n = tbl_JOIN_INNER_TD_5724624_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
            std::string _ca_city5046 = std::string(_ca_city5046_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip5049_n = tbl_JOIN_INNER_TD_5724624_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 12);
            std::string _ca_zip5049 = std::string(_ca_zip5049_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5055_n = tbl_JOIN_INNER_TD_5724624_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 13);
            std::string _ca_street_number5055 = std::string(_ca_street_number5055_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5056_n = tbl_JOIN_INNER_TD_5724624_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 14);
            std::string _ca_street_name5056 = std::string(_ca_street_name5056_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_city5059_n = tbl_JOIN_INNER_TD_5724624_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
            std::string _ca_city5059 = std::string(_ca_city5059_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip5062_n = tbl_JOIN_INNER_TD_5724624_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 16);
            std::string _ca_zip5062 = std::string(_ca_zip5062_n.data());
            SW_JOIN_INNER_TD_4452906_payload_leftMajor payloadA{_ss_item_sk4760, _ss_wholesale_cost4769, _ss_list_price4770, _ss_coupon_amt4777, _d_year4868, _s_store_name4951, _s_zip4971, _d_year4896, _d_year4924, _ca_street_number5042, _ca_street_name5043, _ca_city5046, _ca_zip5049, _ca_street_number5055, _ca_street_name5056, _ca_city5059, _ca_zip5062};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5514808_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk5072_k = tbl_Filter_TD_5514808_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4452906_key_leftMajor{_i_item_sk5072_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk4760 = (it->second)._ss_item_sk4760;
                int64_t _ss_wholesale_cost4769 = (it->second)._ss_wholesale_cost4769;
                int64_t _ss_list_price4770 = (it->second)._ss_list_price4770;
                int64_t _ss_coupon_amt4777 = (it->second)._ss_coupon_amt4777;
                int32_t _d_year4868 = (it->second)._d_year4868;
                std::string _s_store_name4951 = (it->second)._s_store_name4951;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n{};
                memcpy(_s_store_name4951_n.data(), (_s_store_name4951).data(), (_s_store_name4951).length());
                std::string _s_zip4971 = (it->second)._s_zip4971;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n{};
                memcpy(_s_zip4971_n.data(), (_s_zip4971).data(), (_s_zip4971).length());
                int32_t _d_year4896 = (it->second)._d_year4896;
                int32_t _d_year4924 = (it->second)._d_year4924;
                std::string _ca_street_number5042 = (it->second)._ca_street_number5042;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5042_n{};
                memcpy(_ca_street_number5042_n.data(), (_ca_street_number5042).data(), (_ca_street_number5042).length());
                std::string _ca_street_name5043 = (it->second)._ca_street_name5043;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5043_n{};
                memcpy(_ca_street_name5043_n.data(), (_ca_street_name5043).data(), (_ca_street_name5043).length());
                std::string _ca_city5046 = (it->second)._ca_city5046;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city5046_n{};
                memcpy(_ca_city5046_n.data(), (_ca_city5046).data(), (_ca_city5046).length());
                std::string _ca_zip5049 = (it->second)._ca_zip5049;
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip5049_n{};
                memcpy(_ca_zip5049_n.data(), (_ca_zip5049).data(), (_ca_zip5049).length());
                std::string _ca_street_number5055 = (it->second)._ca_street_number5055;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5055_n{};
                memcpy(_ca_street_number5055_n.data(), (_ca_street_number5055).data(), (_ca_street_number5055).length());
                std::string _ca_street_name5056 = (it->second)._ca_street_name5056;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5056_n{};
                memcpy(_ca_street_name5056_n.data(), (_ca_street_name5056).data(), (_ca_street_name5056).length());
                std::string _ca_city5059 = (it->second)._ca_city5059;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city5059_n{};
                memcpy(_ca_city5059_n.data(), (_ca_city5059).data(), (_ca_city5059).length());
                std::string _ca_zip5062 = (it->second)._ca_zip5062;
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip5062_n{};
                memcpy(_ca_zip5062_n.data(), (_ca_zip5062).data(), (_ca_zip5062).length());
                int32_t _i_item_sk5072 = tbl_Filter_TD_5514808_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_product_name5093_n = tbl_Filter_TD_5514808_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_product_name5093 = std::string(_i_product_name5093_n.data());
                tbl_JOIN_INNER_TD_4452906_output.setInt64(r, 0, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_4452906_output.setInt64(r, 1, _ss_list_price4770);
                tbl_JOIN_INNER_TD_4452906_output.setInt64(r, 2, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_4452906_output.setInt32(r, 3, _d_year4868);
                tbl_JOIN_INNER_TD_4452906_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_4452906_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_zip4971_n);
                tbl_JOIN_INNER_TD_4452906_output.setInt32(r, 4, _d_year4896);
                tbl_JOIN_INNER_TD_4452906_output.setInt32(r, 5, _d_year4924);
                tbl_JOIN_INNER_TD_4452906_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _ca_street_number5042_n);
                tbl_JOIN_INNER_TD_4452906_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _ca_street_name5043_n);
                tbl_JOIN_INNER_TD_4452906_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _ca_city5046_n);
                tbl_JOIN_INNER_TD_4452906_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _ca_zip5049_n);
                tbl_JOIN_INNER_TD_4452906_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _ca_street_number5055_n);
                tbl_JOIN_INNER_TD_4452906_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 13, _ca_street_name5056_n);
                tbl_JOIN_INNER_TD_4452906_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 14, _ca_city5059_n);
                tbl_JOIN_INNER_TD_4452906_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 15, _ca_zip5062_n);
                tbl_JOIN_INNER_TD_4452906_output.setInt32(r, 16, _i_item_sk5072);
                tbl_JOIN_INNER_TD_4452906_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 17, _i_product_name5093_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4452906_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4452906_key_rightMajor, SW_JOIN_INNER_TD_4452906_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5514808_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk5072_k = tbl_Filter_TD_5514808_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4452906_key_rightMajor keyA{_i_item_sk5072_k};
            int32_t _i_item_sk5072 = tbl_Filter_TD_5514808_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_product_name5093_n = tbl_Filter_TD_5514808_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_product_name5093 = std::string(_i_product_name5093_n.data());
            SW_JOIN_INNER_TD_4452906_payload_rightMajor payloadA{_i_item_sk5072, _i_product_name5093};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_5724624_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk4760_k = tbl_JOIN_INNER_TD_5724624_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4452906_key_rightMajor{_ss_item_sk4760_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk5072 = (it->second)._i_item_sk5072;
                std::string _i_product_name5093 = (it->second)._i_product_name5093;
                std::array<char, TPCDS_READ_MAX + 1> _i_product_name5093_n{};
                memcpy(_i_product_name5093_n.data(), (_i_product_name5093).data(), (_i_product_name5093).length());
                int32_t _ss_item_sk4760 = tbl_JOIN_INNER_TD_5724624_output.getInt32(i, 0);
                int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_5724624_output.getInt64(i, 1);
                int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_5724624_output.getInt64(i, 2);
                int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_5724624_output.getInt64(i, 3);
                int32_t _d_year4868 = tbl_JOIN_INNER_TD_5724624_output.getInt32(i, 4);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951_n = tbl_JOIN_INNER_TD_5724624_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _s_store_name4951 = std::string(_s_store_name4951_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip4971_n = tbl_JOIN_INNER_TD_5724624_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _s_zip4971 = std::string(_s_zip4971_n.data());
                int32_t _d_year4896 = tbl_JOIN_INNER_TD_5724624_output.getInt32(i, 7);
                int32_t _d_year4924 = tbl_JOIN_INNER_TD_5724624_output.getInt32(i, 8);
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5042_n = tbl_JOIN_INNER_TD_5724624_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
                std::string _ca_street_number5042 = std::string(_ca_street_number5042_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5043_n = tbl_JOIN_INNER_TD_5724624_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
                std::string _ca_street_name5043 = std::string(_ca_street_name5043_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_city5046_n = tbl_JOIN_INNER_TD_5724624_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
                std::string _ca_city5046 = std::string(_ca_city5046_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip5049_n = tbl_JOIN_INNER_TD_5724624_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 12);
                std::string _ca_zip5049 = std::string(_ca_zip5049_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5055_n = tbl_JOIN_INNER_TD_5724624_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 13);
                std::string _ca_street_number5055 = std::string(_ca_street_number5055_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5056_n = tbl_JOIN_INNER_TD_5724624_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 14);
                std::string _ca_street_name5056 = std::string(_ca_street_name5056_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_city5059_n = tbl_JOIN_INNER_TD_5724624_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
                std::string _ca_city5059 = std::string(_ca_city5059_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip5062_n = tbl_JOIN_INNER_TD_5724624_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 16);
                std::string _ca_zip5062 = std::string(_ca_zip5062_n.data());
                tbl_JOIN_INNER_TD_4452906_output.setInt32(r, 16, _i_item_sk5072);
                tbl_JOIN_INNER_TD_4452906_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 17, _i_product_name5093_n);
                tbl_JOIN_INNER_TD_4452906_output.setInt64(r, 0, _ss_wholesale_cost4769);
                tbl_JOIN_INNER_TD_4452906_output.setInt64(r, 1, _ss_list_price4770);
                tbl_JOIN_INNER_TD_4452906_output.setInt64(r, 2, _ss_coupon_amt4777);
                tbl_JOIN_INNER_TD_4452906_output.setInt32(r, 3, _d_year4868);
                tbl_JOIN_INNER_TD_4452906_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_store_name4951_n);
                tbl_JOIN_INNER_TD_4452906_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_zip4971_n);
                tbl_JOIN_INNER_TD_4452906_output.setInt32(r, 4, _d_year4896);
                tbl_JOIN_INNER_TD_4452906_output.setInt32(r, 5, _d_year4924);
                tbl_JOIN_INNER_TD_4452906_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _ca_street_number5042_n);
                tbl_JOIN_INNER_TD_4452906_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _ca_street_name5043_n);
                tbl_JOIN_INNER_TD_4452906_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _ca_city5046_n);
                tbl_JOIN_INNER_TD_4452906_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _ca_zip5049_n);
                tbl_JOIN_INNER_TD_4452906_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _ca_street_number5055_n);
                tbl_JOIN_INNER_TD_4452906_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 13, _ca_street_name5056_n);
                tbl_JOIN_INNER_TD_4452906_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 14, _ca_city5059_n);
                tbl_JOIN_INNER_TD_4452906_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 15, _ca_zip5062_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4452906_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4452906_output #Row: " << tbl_JOIN_INNER_TD_4452906_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4338385_key_leftMajor {
    int32_t _ss_item_sk1208;
    bool operator==(const SW_JOIN_INNER_TD_4338385_key_leftMajor& other) const {
        return ((_ss_item_sk1208 == other._ss_item_sk1208));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4338385_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4338385_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk1208));
    }
};
}
struct SW_JOIN_INNER_TD_4338385_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int64_t _ss_wholesale_cost1217;
    int64_t _ss_list_price1218;
    int64_t _ss_coupon_amt1225;
    int32_t _d_year126;
    std::string _s_store_name383;
    std::string _s_zip403;
    int32_t _d_year3576;
    int32_t _d_year3604;
    std::string _ca_street_number56;
    std::string _ca_street_name57;
    std::string _ca_city60;
    std::string _ca_zip63;
    std::string _ca_street_number3642;
    std::string _ca_street_name3643;
    std::string _ca_city3646;
    std::string _ca_zip3649;
};
struct SW_JOIN_INNER_TD_4338385_key_rightMajor {
    int32_t _i_item_sk228;
    bool operator==(const SW_JOIN_INNER_TD_4338385_key_rightMajor& other) const {
        return ((_i_item_sk228 == other._i_item_sk228));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4338385_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4338385_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk228));
    }
};
}
struct SW_JOIN_INNER_TD_4338385_payload_rightMajor {
    int32_t _i_item_sk228;
    std::string _i_product_name249;
};
void SW_JOIN_INNER_TD_4338385(Table &tbl_JOIN_INNER_TD_5927078_output, Table &tbl_Filter_TD_5748863_output, Table &tbl_JOIN_INNER_TD_4338385_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_item_sk#1208 = i_item_sk#228))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, s_store_name#383, s_zip#403, d_year#3576, d_year#3604, ca_street_number#56, ca_street_name#57, ca_city#60, ca_zip#63, ca_street_number#3642, ca_street_name#3643, ca_city#3646, ca_zip#3649)
    // Right Table: ListBuffer(i_item_sk#228, i_product_name#249)
    // Output Table: ListBuffer(ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, d_year#3576, d_year#3604, s_store_name#383, s_zip#403, ca_street_number#56, ca_street_name#57, ca_city#60, ca_zip#63, ca_street_number#3642, ca_street_name#3643, ca_city#3646, ca_zip#3649, i_item_sk#228, i_product_name#249)
    int left_nrow = tbl_JOIN_INNER_TD_5927078_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5748863_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4338385_key_leftMajor, SW_JOIN_INNER_TD_4338385_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_5927078_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_5927078_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4338385_key_leftMajor keyA{_ss_item_sk1208_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_5927078_output.getInt32(i, 0);
            int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_5927078_output.getInt64(i, 1);
            int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_5927078_output.getInt64(i, 2);
            int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_5927078_output.getInt64(i, 3);
            int32_t _d_year126 = tbl_JOIN_INNER_TD_5927078_output.getInt32(i, 4);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_5927078_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _s_store_name383 = std::string(_s_store_name383_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_5927078_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _s_zip403 = std::string(_s_zip403_n.data());
            int32_t _d_year3576 = tbl_JOIN_INNER_TD_5927078_output.getInt32(i, 7);
            int32_t _d_year3604 = tbl_JOIN_INNER_TD_5927078_output.getInt32(i, 8);
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_number56_n = tbl_JOIN_INNER_TD_5927078_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            std::string _ca_street_number56 = std::string(_ca_street_number56_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_name57_n = tbl_JOIN_INNER_TD_5927078_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            std::string _ca_street_name57 = std::string(_ca_street_name57_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n = tbl_JOIN_INNER_TD_5927078_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
            std::string _ca_city60 = std::string(_ca_city60_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n = tbl_JOIN_INNER_TD_5927078_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 12);
            std::string _ca_zip63 = std::string(_ca_zip63_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_number3642_n = tbl_JOIN_INNER_TD_5927078_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 13);
            std::string _ca_street_number3642 = std::string(_ca_street_number3642_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_street_name3643_n = tbl_JOIN_INNER_TD_5927078_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 14);
            std::string _ca_street_name3643 = std::string(_ca_street_name3643_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_city3646_n = tbl_JOIN_INNER_TD_5927078_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
            std::string _ca_city3646 = std::string(_ca_city3646_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_zip3649_n = tbl_JOIN_INNER_TD_5927078_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 16);
            std::string _ca_zip3649 = std::string(_ca_zip3649_n.data());
            SW_JOIN_INNER_TD_4338385_payload_leftMajor payloadA{_ss_item_sk1208, _ss_wholesale_cost1217, _ss_list_price1218, _ss_coupon_amt1225, _d_year126, _s_store_name383, _s_zip403, _d_year3576, _d_year3604, _ca_street_number56, _ca_street_name57, _ca_city60, _ca_zip63, _ca_street_number3642, _ca_street_name3643, _ca_city3646, _ca_zip3649};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5748863_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_5748863_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4338385_key_leftMajor{_i_item_sk228_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int64_t _ss_wholesale_cost1217 = (it->second)._ss_wholesale_cost1217;
                int64_t _ss_list_price1218 = (it->second)._ss_list_price1218;
                int64_t _ss_coupon_amt1225 = (it->second)._ss_coupon_amt1225;
                int32_t _d_year126 = (it->second)._d_year126;
                std::string _s_store_name383 = (it->second)._s_store_name383;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n{};
                memcpy(_s_store_name383_n.data(), (_s_store_name383).data(), (_s_store_name383).length());
                std::string _s_zip403 = (it->second)._s_zip403;
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n{};
                memcpy(_s_zip403_n.data(), (_s_zip403).data(), (_s_zip403).length());
                int32_t _d_year3576 = (it->second)._d_year3576;
                int32_t _d_year3604 = (it->second)._d_year3604;
                std::string _ca_street_number56 = (it->second)._ca_street_number56;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number56_n{};
                memcpy(_ca_street_number56_n.data(), (_ca_street_number56).data(), (_ca_street_number56).length());
                std::string _ca_street_name57 = (it->second)._ca_street_name57;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name57_n{};
                memcpy(_ca_street_name57_n.data(), (_ca_street_name57).data(), (_ca_street_name57).length());
                std::string _ca_city60 = (it->second)._ca_city60;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n{};
                memcpy(_ca_city60_n.data(), (_ca_city60).data(), (_ca_city60).length());
                std::string _ca_zip63 = (it->second)._ca_zip63;
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n{};
                memcpy(_ca_zip63_n.data(), (_ca_zip63).data(), (_ca_zip63).length());
                std::string _ca_street_number3642 = (it->second)._ca_street_number3642;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number3642_n{};
                memcpy(_ca_street_number3642_n.data(), (_ca_street_number3642).data(), (_ca_street_number3642).length());
                std::string _ca_street_name3643 = (it->second)._ca_street_name3643;
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name3643_n{};
                memcpy(_ca_street_name3643_n.data(), (_ca_street_name3643).data(), (_ca_street_name3643).length());
                std::string _ca_city3646 = (it->second)._ca_city3646;
                std::array<char, TPCDS_READ_MAX + 1> _ca_city3646_n{};
                memcpy(_ca_city3646_n.data(), (_ca_city3646).data(), (_ca_city3646).length());
                std::string _ca_zip3649 = (it->second)._ca_zip3649;
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip3649_n{};
                memcpy(_ca_zip3649_n.data(), (_ca_zip3649).data(), (_ca_zip3649).length());
                int32_t _i_item_sk228 = tbl_Filter_TD_5748863_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_product_name249_n = tbl_Filter_TD_5748863_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_product_name249 = std::string(_i_product_name249_n.data());
                tbl_JOIN_INNER_TD_4338385_output.setInt64(r, 0, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_4338385_output.setInt64(r, 1, _ss_list_price1218);
                tbl_JOIN_INNER_TD_4338385_output.setInt64(r, 2, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_4338385_output.setInt32(r, 3, _d_year126);
                tbl_JOIN_INNER_TD_4338385_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_store_name383_n);
                tbl_JOIN_INNER_TD_4338385_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_zip403_n);
                tbl_JOIN_INNER_TD_4338385_output.setInt32(r, 4, _d_year3576);
                tbl_JOIN_INNER_TD_4338385_output.setInt32(r, 5, _d_year3604);
                tbl_JOIN_INNER_TD_4338385_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _ca_street_number56_n);
                tbl_JOIN_INNER_TD_4338385_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _ca_street_name57_n);
                tbl_JOIN_INNER_TD_4338385_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _ca_city60_n);
                tbl_JOIN_INNER_TD_4338385_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _ca_zip63_n);
                tbl_JOIN_INNER_TD_4338385_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _ca_street_number3642_n);
                tbl_JOIN_INNER_TD_4338385_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 13, _ca_street_name3643_n);
                tbl_JOIN_INNER_TD_4338385_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 14, _ca_city3646_n);
                tbl_JOIN_INNER_TD_4338385_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 15, _ca_zip3649_n);
                tbl_JOIN_INNER_TD_4338385_output.setInt32(r, 16, _i_item_sk228);
                tbl_JOIN_INNER_TD_4338385_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 17, _i_product_name249_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4338385_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4338385_key_rightMajor, SW_JOIN_INNER_TD_4338385_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5748863_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_5748863_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4338385_key_rightMajor keyA{_i_item_sk228_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_5748863_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_product_name249_n = tbl_Filter_TD_5748863_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_product_name249 = std::string(_i_product_name249_n.data());
            SW_JOIN_INNER_TD_4338385_payload_rightMajor payloadA{_i_item_sk228, _i_product_name249};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_5927078_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_5927078_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4338385_key_rightMajor{_ss_item_sk1208_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                std::string _i_product_name249 = (it->second)._i_product_name249;
                std::array<char, TPCDS_READ_MAX + 1> _i_product_name249_n{};
                memcpy(_i_product_name249_n.data(), (_i_product_name249).data(), (_i_product_name249).length());
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_5927078_output.getInt32(i, 0);
                int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_5927078_output.getInt64(i, 1);
                int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_5927078_output.getInt64(i, 2);
                int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_5927078_output.getInt64(i, 3);
                int32_t _d_year126 = tbl_JOIN_INNER_TD_5927078_output.getInt32(i, 4);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_name383_n = tbl_JOIN_INNER_TD_5927078_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _s_store_name383 = std::string(_s_store_name383_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_zip403_n = tbl_JOIN_INNER_TD_5927078_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _s_zip403 = std::string(_s_zip403_n.data());
                int32_t _d_year3576 = tbl_JOIN_INNER_TD_5927078_output.getInt32(i, 7);
                int32_t _d_year3604 = tbl_JOIN_INNER_TD_5927078_output.getInt32(i, 8);
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number56_n = tbl_JOIN_INNER_TD_5927078_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
                std::string _ca_street_number56 = std::string(_ca_street_number56_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name57_n = tbl_JOIN_INNER_TD_5927078_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
                std::string _ca_street_name57 = std::string(_ca_street_name57_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_city60_n = tbl_JOIN_INNER_TD_5927078_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
                std::string _ca_city60 = std::string(_ca_city60_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip63_n = tbl_JOIN_INNER_TD_5927078_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 12);
                std::string _ca_zip63 = std::string(_ca_zip63_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_number3642_n = tbl_JOIN_INNER_TD_5927078_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 13);
                std::string _ca_street_number3642 = std::string(_ca_street_number3642_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_street_name3643_n = tbl_JOIN_INNER_TD_5927078_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 14);
                std::string _ca_street_name3643 = std::string(_ca_street_name3643_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_city3646_n = tbl_JOIN_INNER_TD_5927078_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
                std::string _ca_city3646 = std::string(_ca_city3646_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_zip3649_n = tbl_JOIN_INNER_TD_5927078_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 16);
                std::string _ca_zip3649 = std::string(_ca_zip3649_n.data());
                tbl_JOIN_INNER_TD_4338385_output.setInt32(r, 16, _i_item_sk228);
                tbl_JOIN_INNER_TD_4338385_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 17, _i_product_name249_n);
                tbl_JOIN_INNER_TD_4338385_output.setInt64(r, 0, _ss_wholesale_cost1217);
                tbl_JOIN_INNER_TD_4338385_output.setInt64(r, 1, _ss_list_price1218);
                tbl_JOIN_INNER_TD_4338385_output.setInt64(r, 2, _ss_coupon_amt1225);
                tbl_JOIN_INNER_TD_4338385_output.setInt32(r, 3, _d_year126);
                tbl_JOIN_INNER_TD_4338385_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_store_name383_n);
                tbl_JOIN_INNER_TD_4338385_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _s_zip403_n);
                tbl_JOIN_INNER_TD_4338385_output.setInt32(r, 4, _d_year3576);
                tbl_JOIN_INNER_TD_4338385_output.setInt32(r, 5, _d_year3604);
                tbl_JOIN_INNER_TD_4338385_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _ca_street_number56_n);
                tbl_JOIN_INNER_TD_4338385_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _ca_street_name57_n);
                tbl_JOIN_INNER_TD_4338385_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _ca_city60_n);
                tbl_JOIN_INNER_TD_4338385_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _ca_zip63_n);
                tbl_JOIN_INNER_TD_4338385_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 12, _ca_street_number3642_n);
                tbl_JOIN_INNER_TD_4338385_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 13, _ca_street_name3643_n);
                tbl_JOIN_INNER_TD_4338385_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 14, _ca_city3646_n);
                tbl_JOIN_INNER_TD_4338385_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 15, _ca_zip3649_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4338385_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4338385_output #Row: " << tbl_JOIN_INNER_TD_4338385_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_3248686_key {
    std::string _i_product_name5093;
    int32_t _i_item_sk5072;
    std::string _s_store_name4951;
    std::string _s_zip4971;
    std::string _ca_street_number5042;
    std::string _ca_street_name5043;
    std::string _ca_city5046;
    std::string _ca_zip5049;
    std::string _ca_street_number5055;
    std::string _ca_street_name5056;
    std::string _ca_city5059;
    std::string _ca_zip5062;
    int32_t _d_year4868;
    int32_t _d_year4896;
    int32_t _d_year4924;
    bool operator==(const SW_Aggregate_TD_3248686_key& other) const { return (_i_product_name5093 == other._i_product_name5093) && (_i_item_sk5072 == other._i_item_sk5072) && (_s_store_name4951 == other._s_store_name4951) && (_s_zip4971 == other._s_zip4971) && (_ca_street_number5042 == other._ca_street_number5042) && (_ca_street_name5043 == other._ca_street_name5043) && (_ca_city5046 == other._ca_city5046) && (_ca_zip5049 == other._ca_zip5049) && (_ca_street_number5055 == other._ca_street_number5055) && (_ca_street_name5056 == other._ca_street_name5056) && (_ca_city5059 == other._ca_city5059) && (_ca_zip5062 == other._ca_zip5062) && (_d_year4868 == other._d_year4868) && (_d_year4896 == other._d_year4896) && (_d_year4924 == other._d_year4924); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_3248686_key> {
    std::size_t operator() (const SW_Aggregate_TD_3248686_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_product_name5093)) + (hash<int32_t>()(k._i_item_sk5072)) + (hash<string>()(k._s_store_name4951)) + (hash<string>()(k._s_zip4971)) + (hash<string>()(k._ca_street_number5042)) + (hash<string>()(k._ca_street_name5043)) + (hash<string>()(k._ca_city5046)) + (hash<string>()(k._ca_zip5049)) + (hash<string>()(k._ca_street_number5055)) + (hash<string>()(k._ca_street_name5056)) + (hash<string>()(k._ca_city5059)) + (hash<string>()(k._ca_zip5062)) + (hash<int32_t>()(k._d_year4868)) + (hash<int32_t>()(k._d_year4896)) + (hash<int32_t>()(k._d_year4924));
    }
};
}
struct SW_Aggregate_TD_3248686_payload {
    int32_t _item_sk3665;
    std::string _store_name3666;
    std::string _store_zip3667;
    int32_t _syear3676;
    int64_t _cnt3679L_count_0;
    int64_t _s13680_sum_1;
    int64_t _s23681_sum_2;
    int64_t _s33682_sum_3;
};
void SW_Aggregate_TD_3248686(Table &tbl_JOIN_INNER_TD_4452906_output, Table &tbl_Aggregate_TD_3248686_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(i_product_name#5093, i_item_sk#5072, s_store_name#4951, s_zip#4971, ca_street_number#5042, ca_street_name#5043, ca_city#5046, ca_zip#5049, ca_street_number#5055, ca_street_name#5056, ca_city#5059, ca_zip#5062, d_year#4868, d_year#4896, d_year#4924, i_item_sk#5072 AS item_sk#3665, s_store_name#4951 AS store_name#3666, s_zip#4971 AS store_zip#3667, d_year#4868 AS syear#3676, count(1) AS cnt#3679L, MakeDecimal(sum(UnscaledValue(ss_wholesale_cost#4769)),17,2) AS s1#3680, MakeDecimal(sum(UnscaledValue(ss_list_price#4770)),17,2) AS s2#3681, MakeDecimal(sum(UnscaledValue(ss_coupon_amt#4777)),17,2) AS s3#3682)
    // Input: ListBuffer(ss_wholesale_cost#4769, ss_list_price#4770, ss_coupon_amt#4777, d_year#4868, d_year#4896, d_year#4924, s_store_name#4951, s_zip#4971, ca_street_number#5042, ca_street_name#5043, ca_city#5046, ca_zip#5049, ca_street_number#5055, ca_street_name#5056, ca_city#5059, ca_zip#5062, i_item_sk#5072, i_product_name#5093)
    // Output: ListBuffer(item_sk#3665, store_name#3666, store_zip#3667, syear#3676, cnt#3679L, s1#3680, s2#3681, s3#3682)
    std::unordered_map<SW_Aggregate_TD_3248686_key, SW_Aggregate_TD_3248686_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_4452906_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ss_wholesale_cost4769 = tbl_JOIN_INNER_TD_4452906_output.getInt64(i, 0);
        int64_t _ss_list_price4770 = tbl_JOIN_INNER_TD_4452906_output.getInt64(i, 1);
        int64_t _ss_coupon_amt4777 = tbl_JOIN_INNER_TD_4452906_output.getInt64(i, 2);
        int32_t _d_year4868 = tbl_JOIN_INNER_TD_4452906_output.getInt32(i, 3);
        int32_t _d_year4896 = tbl_JOIN_INNER_TD_4452906_output.getInt32(i, 4);
        int32_t _d_year4924 = tbl_JOIN_INNER_TD_4452906_output.getInt32(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name4951 = tbl_JOIN_INNER_TD_4452906_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        std::array<char, TPCDS_READ_MAX + 1> _s_zip4971 = tbl_JOIN_INNER_TD_4452906_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
        std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5042 = tbl_JOIN_INNER_TD_4452906_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
        std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5043 = tbl_JOIN_INNER_TD_4452906_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city5046 = tbl_JOIN_INNER_TD_4452906_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
        std::array<char, TPCDS_READ_MAX + 1> _ca_zip5049 = tbl_JOIN_INNER_TD_4452906_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
        std::array<char, TPCDS_READ_MAX + 1> _ca_street_number5055 = tbl_JOIN_INNER_TD_4452906_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 12);
        std::array<char, TPCDS_READ_MAX + 1> _ca_street_name5056 = tbl_JOIN_INNER_TD_4452906_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 13);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city5059 = tbl_JOIN_INNER_TD_4452906_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 14);
        std::array<char, TPCDS_READ_MAX + 1> _ca_zip5062 = tbl_JOIN_INNER_TD_4452906_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
        int32_t _i_item_sk5072 = tbl_JOIN_INNER_TD_4452906_output.getInt32(i, 16);
        std::array<char, TPCDS_READ_MAX + 1> _i_product_name5093 = tbl_JOIN_INNER_TD_4452906_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 17);
        SW_Aggregate_TD_3248686_key k{std::string(_i_product_name5093.data()), _i_item_sk5072, std::string(_s_store_name4951.data()), std::string(_s_zip4971.data()), std::string(_ca_street_number5042.data()), std::string(_ca_street_name5043.data()), std::string(_ca_city5046.data()), std::string(_ca_zip5049.data()), std::string(_ca_street_number5055.data()), std::string(_ca_street_name5056.data()), std::string(_ca_city5059.data()), std::string(_ca_zip5062.data()), _d_year4868, _d_year4896, _d_year4924};
        int32_t _item_sk3665 = _i_item_sk5072;
        std::array<char, TPCDS_READ_MAX + 1> _store_name3666 = _s_store_name4951;
        std::array<char, TPCDS_READ_MAX + 1> _store_zip3667 = _s_zip4971;
        int32_t _syear3676 = _d_year4868;
        int64_t _cnt3679L_count_0 = 1 != 0 ? 1 : 0;
        int64_t _s13680_sum_1 = _ss_wholesale_cost4769;
        int64_t _s23681_sum_2 = _ss_list_price4770;
        int64_t _s33682_sum_3 = _ss_coupon_amt4777;
        SW_Aggregate_TD_3248686_payload p{_item_sk3665, std::string(_store_name3666.data()), std::string(_store_zip3667.data()), _syear3676, _cnt3679L_count_0, _s13680_sum_1, _s23681_sum_2, _s33682_sum_3};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t count_0 = (it->second)._cnt3679L_count_0 + _cnt3679L_count_0;
            p._cnt3679L_count_0 = count_0;
            int64_t sum_1 = (it->second)._s13680_sum_1 + _s13680_sum_1;
            p._s13680_sum_1 = sum_1;
            int64_t sum_2 = (it->second)._s23681_sum_2 + _s23681_sum_2;
            p._s23681_sum_2 = sum_2;
            int64_t sum_3 = (it->second)._s33682_sum_3 + _s33682_sum_3;
            p._s33682_sum_3 = sum_3;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _i_product_name5093 not required in the output table
        // _i_item_sk5072 not required in the output table
        // _s_store_name4951 not required in the output table
        // _s_zip4971 not required in the output table
        // _ca_street_number5042 not required in the output table
        // _ca_street_name5043 not required in the output table
        // _ca_city5046 not required in the output table
        // _ca_zip5049 not required in the output table
        // _ca_street_number5055 not required in the output table
        // _ca_street_name5056 not required in the output table
        // _ca_city5059 not required in the output table
        // _ca_zip5062 not required in the output table
        // _d_year4868 not required in the output table
        // _d_year4896 not required in the output table
        // _d_year4924 not required in the output table
        tbl_Aggregate_TD_3248686_output.setInt32(r, 0, (it.second)._item_sk3665);
        std::array<char, TPCDS_READ_MAX + 1> _store_name3666_n{};
        memcpy(_store_name3666_n.data(), (it.second)._store_name3666.data(), (it.second)._store_name3666.length());
        tbl_Aggregate_TD_3248686_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _store_name3666_n);
        std::array<char, TPCDS_READ_MAX + 1> _store_zip3667_n{};
        memcpy(_store_zip3667_n.data(), (it.second)._store_zip3667.data(), (it.second)._store_zip3667.length());
        tbl_Aggregate_TD_3248686_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _store_zip3667_n);
        tbl_Aggregate_TD_3248686_output.setInt32(r, 3, (it.second)._syear3676);
        int64_t _cnt3679L = (it.second)._cnt3679L_count_0;
        tbl_Aggregate_TD_3248686_output.setInt64(r, 4, _cnt3679L);
        int64_t _s13680 = (it.second)._s13680_sum_1;
        tbl_Aggregate_TD_3248686_output.setInt64(r, 5, _s13680);
        int64_t _s23681 = (it.second)._s23681_sum_2;
        tbl_Aggregate_TD_3248686_output.setInt64(r, 6, _s23681);
        int64_t _s33682 = (it.second)._s33682_sum_3;
        tbl_Aggregate_TD_3248686_output.setInt64(r, 7, _s33682);
        ++r;
    }
    tbl_Aggregate_TD_3248686_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_3248686_output #Row: " << tbl_Aggregate_TD_3248686_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_3607278_key {
    std::string _i_product_name249;
    int32_t _i_item_sk228;
    std::string _s_store_name383;
    std::string _s_zip403;
    std::string _ca_street_number56;
    std::string _ca_street_name57;
    std::string _ca_city60;
    std::string _ca_zip63;
    std::string _ca_street_number3642;
    std::string _ca_street_name3643;
    std::string _ca_city3646;
    std::string _ca_zip3649;
    int32_t _d_year126;
    int32_t _d_year3576;
    int32_t _d_year3604;
    bool operator==(const SW_Aggregate_TD_3607278_key& other) const { return (_i_product_name249 == other._i_product_name249) && (_i_item_sk228 == other._i_item_sk228) && (_s_store_name383 == other._s_store_name383) && (_s_zip403 == other._s_zip403) && (_ca_street_number56 == other._ca_street_number56) && (_ca_street_name57 == other._ca_street_name57) && (_ca_city60 == other._ca_city60) && (_ca_zip63 == other._ca_zip63) && (_ca_street_number3642 == other._ca_street_number3642) && (_ca_street_name3643 == other._ca_street_name3643) && (_ca_city3646 == other._ca_city3646) && (_ca_zip3649 == other._ca_zip3649) && (_d_year126 == other._d_year126) && (_d_year3576 == other._d_year3576) && (_d_year3604 == other._d_year3604); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_3607278_key> {
    std::size_t operator() (const SW_Aggregate_TD_3607278_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_product_name249)) + (hash<int32_t>()(k._i_item_sk228)) + (hash<string>()(k._s_store_name383)) + (hash<string>()(k._s_zip403)) + (hash<string>()(k._ca_street_number56)) + (hash<string>()(k._ca_street_name57)) + (hash<string>()(k._ca_city60)) + (hash<string>()(k._ca_zip63)) + (hash<string>()(k._ca_street_number3642)) + (hash<string>()(k._ca_street_name3643)) + (hash<string>()(k._ca_city3646)) + (hash<string>()(k._ca_zip3649)) + (hash<int32_t>()(k._d_year126)) + (hash<int32_t>()(k._d_year3576)) + (hash<int32_t>()(k._d_year3604));
    }
};
}
struct SW_Aggregate_TD_3607278_payload {
    std::string _product_name3551;
    int32_t _item_sk3552;
    std::string _store_name3553;
    std::string _store_zip3554;
    std::string _b_street_number3555;
    std::string _b_streen_name3556;
    std::string _b_city3557;
    std::string _b_zip3558;
    std::string _c_street_number3559;
    std::string _c_street_name3560;
    std::string _c_city3561;
    std::string _c_zip3562;
    int32_t _syear3563;
    int64_t _cnt3566L_count_0;
    int64_t _s13567_sum_1;
    int64_t _s23568_sum_2;
    int64_t _s33569_sum_3;
};
void SW_Aggregate_TD_3607278(Table &tbl_JOIN_INNER_TD_4338385_output, Table &tbl_Aggregate_TD_3607278_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(i_product_name#249, i_item_sk#228, s_store_name#383, s_zip#403, ca_street_number#56, ca_street_name#57, ca_city#60, ca_zip#63, ca_street_number#3642, ca_street_name#3643, ca_city#3646, ca_zip#3649, d_year#126, d_year#3576, d_year#3604, i_product_name#249 AS product_name#3551, i_item_sk#228 AS item_sk#3552, s_store_name#383 AS store_name#3553, s_zip#403 AS store_zip#3554, ca_street_number#56 AS b_street_number#3555, ca_street_name#57 AS b_streen_name#3556, ca_city#60 AS b_city#3557, ca_zip#63 AS b_zip#3558, ca_street_number#3642 AS c_street_number#3559, ca_street_name#3643 AS c_street_name#3560, ca_city#3646 AS c_city#3561, ca_zip#3649 AS c_zip#3562, d_year#126 AS syear#3563, count(1) AS cnt#3566L, MakeDecimal(sum(UnscaledValue(ss_wholesale_cost#1217)),17,2) AS s1#3567, MakeDecimal(sum(UnscaledValue(ss_list_price#1218)),17,2) AS s2#3568, MakeDecimal(sum(UnscaledValue(ss_coupon_amt#1225)),17,2) AS s3#3569)
    // Input: ListBuffer(ss_wholesale_cost#1217, ss_list_price#1218, ss_coupon_amt#1225, d_year#126, d_year#3576, d_year#3604, s_store_name#383, s_zip#403, ca_street_number#56, ca_street_name#57, ca_city#60, ca_zip#63, ca_street_number#3642, ca_street_name#3643, ca_city#3646, ca_zip#3649, i_item_sk#228, i_product_name#249)
    // Output: ListBuffer(product_name#3551, item_sk#3552, store_name#3553, store_zip#3554, b_street_number#3555, b_streen_name#3556, b_city#3557, b_zip#3558, c_street_number#3559, c_street_name#3560, c_city#3561, c_zip#3562, syear#3563, cnt#3566L, s1#3567, s2#3568, s3#3569)
    std::unordered_map<SW_Aggregate_TD_3607278_key, SW_Aggregate_TD_3607278_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_4338385_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ss_wholesale_cost1217 = tbl_JOIN_INNER_TD_4338385_output.getInt64(i, 0);
        int64_t _ss_list_price1218 = tbl_JOIN_INNER_TD_4338385_output.getInt64(i, 1);
        int64_t _ss_coupon_amt1225 = tbl_JOIN_INNER_TD_4338385_output.getInt64(i, 2);
        int32_t _d_year126 = tbl_JOIN_INNER_TD_4338385_output.getInt32(i, 3);
        int32_t _d_year3576 = tbl_JOIN_INNER_TD_4338385_output.getInt32(i, 4);
        int32_t _d_year3604 = tbl_JOIN_INNER_TD_4338385_output.getInt32(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383 = tbl_JOIN_INNER_TD_4338385_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        std::array<char, TPCDS_READ_MAX + 1> _s_zip403 = tbl_JOIN_INNER_TD_4338385_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
        std::array<char, TPCDS_READ_MAX + 1> _ca_street_number56 = tbl_JOIN_INNER_TD_4338385_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
        std::array<char, TPCDS_READ_MAX + 1> _ca_street_name57 = tbl_JOIN_INNER_TD_4338385_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city60 = tbl_JOIN_INNER_TD_4338385_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
        std::array<char, TPCDS_READ_MAX + 1> _ca_zip63 = tbl_JOIN_INNER_TD_4338385_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
        std::array<char, TPCDS_READ_MAX + 1> _ca_street_number3642 = tbl_JOIN_INNER_TD_4338385_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 12);
        std::array<char, TPCDS_READ_MAX + 1> _ca_street_name3643 = tbl_JOIN_INNER_TD_4338385_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 13);
        std::array<char, TPCDS_READ_MAX + 1> _ca_city3646 = tbl_JOIN_INNER_TD_4338385_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 14);
        std::array<char, TPCDS_READ_MAX + 1> _ca_zip3649 = tbl_JOIN_INNER_TD_4338385_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 15);
        int32_t _i_item_sk228 = tbl_JOIN_INNER_TD_4338385_output.getInt32(i, 16);
        std::array<char, TPCDS_READ_MAX + 1> _i_product_name249 = tbl_JOIN_INNER_TD_4338385_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 17);
        SW_Aggregate_TD_3607278_key k{std::string(_i_product_name249.data()), _i_item_sk228, std::string(_s_store_name383.data()), std::string(_s_zip403.data()), std::string(_ca_street_number56.data()), std::string(_ca_street_name57.data()), std::string(_ca_city60.data()), std::string(_ca_zip63.data()), std::string(_ca_street_number3642.data()), std::string(_ca_street_name3643.data()), std::string(_ca_city3646.data()), std::string(_ca_zip3649.data()), _d_year126, _d_year3576, _d_year3604};
        std::array<char, TPCDS_READ_MAX + 1> _product_name3551 = _i_product_name249;
        int32_t _item_sk3552 = _i_item_sk228;
        std::array<char, TPCDS_READ_MAX + 1> _store_name3553 = _s_store_name383;
        std::array<char, TPCDS_READ_MAX + 1> _store_zip3554 = _s_zip403;
        std::array<char, TPCDS_READ_MAX + 1> _b_street_number3555 = _ca_street_number56;
        std::array<char, TPCDS_READ_MAX + 1> _b_streen_name3556 = _ca_street_name57;
        std::array<char, TPCDS_READ_MAX + 1> _b_city3557 = _ca_city60;
        std::array<char, TPCDS_READ_MAX + 1> _b_zip3558 = _ca_zip63;
        std::array<char, TPCDS_READ_MAX + 1> _c_street_number3559 = _ca_street_number3642;
        std::array<char, TPCDS_READ_MAX + 1> _c_street_name3560 = _ca_street_name3643;
        std::array<char, TPCDS_READ_MAX + 1> _c_city3561 = _ca_city3646;
        std::array<char, TPCDS_READ_MAX + 1> _c_zip3562 = _ca_zip3649;
        int32_t _syear3563 = _d_year126;
        int64_t _cnt3566L_count_0 = 1 != 0 ? 1 : 0;
        int64_t _s13567_sum_1 = _ss_wholesale_cost1217;
        int64_t _s23568_sum_2 = _ss_list_price1218;
        int64_t _s33569_sum_3 = _ss_coupon_amt1225;
        SW_Aggregate_TD_3607278_payload p{std::string(_product_name3551.data()), _item_sk3552, std::string(_store_name3553.data()), std::string(_store_zip3554.data()), std::string(_b_street_number3555.data()), std::string(_b_streen_name3556.data()), std::string(_b_city3557.data()), std::string(_b_zip3558.data()), std::string(_c_street_number3559.data()), std::string(_c_street_name3560.data()), std::string(_c_city3561.data()), std::string(_c_zip3562.data()), _syear3563, _cnt3566L_count_0, _s13567_sum_1, _s23568_sum_2, _s33569_sum_3};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t count_0 = (it->second)._cnt3566L_count_0 + _cnt3566L_count_0;
            p._cnt3566L_count_0 = count_0;
            int64_t sum_1 = (it->second)._s13567_sum_1 + _s13567_sum_1;
            p._s13567_sum_1 = sum_1;
            int64_t sum_2 = (it->second)._s23568_sum_2 + _s23568_sum_2;
            p._s23568_sum_2 = sum_2;
            int64_t sum_3 = (it->second)._s33569_sum_3 + _s33569_sum_3;
            p._s33569_sum_3 = sum_3;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _i_product_name249 not required in the output table
        // _i_item_sk228 not required in the output table
        // _s_store_name383 not required in the output table
        // _s_zip403 not required in the output table
        // _ca_street_number56 not required in the output table
        // _ca_street_name57 not required in the output table
        // _ca_city60 not required in the output table
        // _ca_zip63 not required in the output table
        // _ca_street_number3642 not required in the output table
        // _ca_street_name3643 not required in the output table
        // _ca_city3646 not required in the output table
        // _ca_zip3649 not required in the output table
        // _d_year126 not required in the output table
        // _d_year3576 not required in the output table
        // _d_year3604 not required in the output table
        std::array<char, TPCDS_READ_MAX + 1> _product_name3551_n{};
        memcpy(_product_name3551_n.data(), (it.second)._product_name3551.data(), (it.second)._product_name3551.length());
        tbl_Aggregate_TD_3607278_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _product_name3551_n);
        tbl_Aggregate_TD_3607278_output.setInt32(r, 1, (it.second)._item_sk3552);
        std::array<char, TPCDS_READ_MAX + 1> _store_name3553_n{};
        memcpy(_store_name3553_n.data(), (it.second)._store_name3553.data(), (it.second)._store_name3553.length());
        tbl_Aggregate_TD_3607278_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _store_name3553_n);
        std::array<char, TPCDS_READ_MAX + 1> _store_zip3554_n{};
        memcpy(_store_zip3554_n.data(), (it.second)._store_zip3554.data(), (it.second)._store_zip3554.length());
        tbl_Aggregate_TD_3607278_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _store_zip3554_n);
        std::array<char, TPCDS_READ_MAX + 1> _b_street_number3555_n{};
        memcpy(_b_street_number3555_n.data(), (it.second)._b_street_number3555.data(), (it.second)._b_street_number3555.length());
        tbl_Aggregate_TD_3607278_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _b_street_number3555_n);
        std::array<char, TPCDS_READ_MAX + 1> _b_streen_name3556_n{};
        memcpy(_b_streen_name3556_n.data(), (it.second)._b_streen_name3556.data(), (it.second)._b_streen_name3556.length());
        tbl_Aggregate_TD_3607278_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _b_streen_name3556_n);
        std::array<char, TPCDS_READ_MAX + 1> _b_city3557_n{};
        memcpy(_b_city3557_n.data(), (it.second)._b_city3557.data(), (it.second)._b_city3557.length());
        tbl_Aggregate_TD_3607278_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _b_city3557_n);
        std::array<char, TPCDS_READ_MAX + 1> _b_zip3558_n{};
        memcpy(_b_zip3558_n.data(), (it.second)._b_zip3558.data(), (it.second)._b_zip3558.length());
        tbl_Aggregate_TD_3607278_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _b_zip3558_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_street_number3559_n{};
        memcpy(_c_street_number3559_n.data(), (it.second)._c_street_number3559.data(), (it.second)._c_street_number3559.length());
        tbl_Aggregate_TD_3607278_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _c_street_number3559_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_street_name3560_n{};
        memcpy(_c_street_name3560_n.data(), (it.second)._c_street_name3560.data(), (it.second)._c_street_name3560.length());
        tbl_Aggregate_TD_3607278_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _c_street_name3560_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_city3561_n{};
        memcpy(_c_city3561_n.data(), (it.second)._c_city3561.data(), (it.second)._c_city3561.length());
        tbl_Aggregate_TD_3607278_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _c_city3561_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_zip3562_n{};
        memcpy(_c_zip3562_n.data(), (it.second)._c_zip3562.data(), (it.second)._c_zip3562.length());
        tbl_Aggregate_TD_3607278_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 11, _c_zip3562_n);
        tbl_Aggregate_TD_3607278_output.setInt32(r, 12, (it.second)._syear3563);
        int64_t _cnt3566L = (it.second)._cnt3566L_count_0;
        tbl_Aggregate_TD_3607278_output.setInt64(r, 13, _cnt3566L);
        int64_t _s13567 = (it.second)._s13567_sum_1;
        tbl_Aggregate_TD_3607278_output.setInt64(r, 14, _s13567);
        int64_t _s23568 = (it.second)._s23568_sum_2;
        tbl_Aggregate_TD_3607278_output.setInt64(r, 15, _s23568);
        int64_t _s33569 = (it.second)._s33569_sum_3;
        tbl_Aggregate_TD_3607278_output.setInt64(r, 16, _s33569);
        ++r;
    }
    tbl_Aggregate_TD_3607278_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_3607278_output #Row: " << tbl_Aggregate_TD_3607278_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_2710081_key_leftMajor {
    int32_t _item_sk3552;
    std::string _store_name3553;
    std::string _store_zip3554;
    bool operator==(const SW_JOIN_INNER_TD_2710081_key_leftMajor& other) const {
        return ((_item_sk3552 == other._item_sk3552) && (_store_name3553 == other._store_name3553) && (_store_zip3554 == other._store_zip3554));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_2710081_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_2710081_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._item_sk3552)) + (hash<string>()(k._store_name3553)) + (hash<string>()(k._store_zip3554));
    }
};
}
struct SW_JOIN_INNER_TD_2710081_payload_leftMajor {
    std::string _product_name3551;
    int32_t _item_sk3552;
    std::string _store_name3553;
    std::string _store_zip3554;
    std::string _b_street_number3555;
    std::string _b_streen_name3556;
    std::string _b_city3557;
    std::string _b_zip3558;
    std::string _c_street_number3559;
    std::string _c_street_name3560;
    std::string _c_city3561;
    std::string _c_zip3562;
    int32_t _syear3563;
    int64_t _cnt3566L;
    int64_t _s13567;
    int64_t _s23568;
    int64_t _s33569;
};
struct SW_JOIN_INNER_TD_2710081_key_rightMajor {
    int32_t _item_sk3665;
    std::string _store_name3666;
    std::string _store_zip3667;
    bool operator==(const SW_JOIN_INNER_TD_2710081_key_rightMajor& other) const {
        return ((_item_sk3665 == other._item_sk3665) && (_store_name3666 == other._store_name3666) && (_store_zip3667 == other._store_zip3667));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_2710081_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_2710081_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._item_sk3665)) + (hash<string>()(k._store_name3666)) + (hash<string>()(k._store_zip3667));
    }
};
}
struct SW_JOIN_INNER_TD_2710081_payload_rightMajor {
    int32_t _item_sk3665;
    std::string _store_name3666;
    std::string _store_zip3667;
    int32_t _syear3676;
    int64_t _cnt3679L;
    int64_t _s13680;
    int64_t _s23681;
    int64_t _s33682;
};
void SW_JOIN_INNER_TD_2710081(Table &tbl_Aggregate_TD_3607278_output, Table &tbl_Aggregate_TD_3248686_output, Table &tbl_JOIN_INNER_TD_2710081_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((((item_sk#3552 = item_sk#3665) AND (cnt#3679L <= cnt#3566L)) AND (store_name#3553 = store_name#3666)) AND (store_zip#3554 = store_zip#3667)))
    // Left Table: ListBuffer(product_name#3551, item_sk#3552, store_name#3553, store_zip#3554, b_street_number#3555, b_streen_name#3556, b_city#3557, b_zip#3558, c_street_number#3559, c_street_name#3560, c_city#3561, c_zip#3562, syear#3563, cnt#3566L, s1#3567, s2#3568, s3#3569)
    // Right Table: ListBuffer(item_sk#3665, store_name#3666, store_zip#3667, syear#3676, cnt#3679L, s1#3680, s2#3681, s3#3682)
    // Output Table: ListBuffer(product_name#3551, store_name#3553, store_zip#3554, b_street_number#3555, b_streen_name#3556, b_city#3557, b_zip#3558, c_street_number#3559, c_street_name#3560, c_city#3561, c_zip#3562, syear#3563, cnt#3566L, s1#3567, s2#3568, s3#3569, s1#3680, s2#3681, s3#3682, syear#3676, cnt#3679L)
    int left_nrow = tbl_Aggregate_TD_3607278_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_3248686_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_2710081_key_leftMajor, SW_JOIN_INNER_TD_2710081_payload_leftMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_3607278_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _item_sk3552_k = tbl_Aggregate_TD_3607278_output.getInt32(i, 1);
            std::array<char, TPCDS_READ_MAX + 1> _store_name3553_k_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _store_name3553_k = std::string(_store_name3553_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _store_zip3554_k_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _store_zip3554_k = std::string(_store_zip3554_k_n.data());
            SW_JOIN_INNER_TD_2710081_key_leftMajor keyA{_item_sk3552_k, _store_name3553_k, _store_zip3554_k};
            std::array<char, TPCDS_READ_MAX + 1> _product_name3551_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _product_name3551 = std::string(_product_name3551_n.data());
            int32_t _item_sk3552 = tbl_Aggregate_TD_3607278_output.getInt32(i, 1);
            std::array<char, TPCDS_READ_MAX + 1> _store_name3553_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _store_name3553 = std::string(_store_name3553_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _store_zip3554_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _store_zip3554 = std::string(_store_zip3554_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _b_street_number3555_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _b_street_number3555 = std::string(_b_street_number3555_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _b_streen_name3556_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _b_streen_name3556 = std::string(_b_streen_name3556_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _b_city3557_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _b_city3557 = std::string(_b_city3557_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _b_zip3558_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
            std::string _b_zip3558 = std::string(_b_zip3558_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_street_number3559_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
            std::string _c_street_number3559 = std::string(_c_street_number3559_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_street_name3560_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
            std::string _c_street_name3560 = std::string(_c_street_name3560_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_city3561_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
            std::string _c_city3561 = std::string(_c_city3561_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_zip3562_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
            std::string _c_zip3562 = std::string(_c_zip3562_n.data());
            int32_t _syear3563 = tbl_Aggregate_TD_3607278_output.getInt32(i, 12);
            int64_t _cnt3566L = tbl_Aggregate_TD_3607278_output.getInt64(i, 13);
            int64_t _s13567 = tbl_Aggregate_TD_3607278_output.getInt64(i, 14);
            int64_t _s23568 = tbl_Aggregate_TD_3607278_output.getInt64(i, 15);
            int64_t _s33569 = tbl_Aggregate_TD_3607278_output.getInt64(i, 16);
            SW_JOIN_INNER_TD_2710081_payload_leftMajor payloadA{_product_name3551, _item_sk3552, _store_name3553, _store_zip3554, _b_street_number3555, _b_streen_name3556, _b_city3557, _b_zip3558, _c_street_number3559, _c_street_name3560, _c_city3561, _c_zip3562, _syear3563, _cnt3566L, _s13567, _s23568, _s33569};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_3248686_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _item_sk3665_k = tbl_Aggregate_TD_3248686_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _store_name3666_k_n = tbl_Aggregate_TD_3248686_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _store_name3666_k = std::string(_store_name3666_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _store_zip3667_k_n = tbl_Aggregate_TD_3248686_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _store_zip3667_k = std::string(_store_zip3667_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_2710081_key_leftMajor{_item_sk3665_k, _store_name3666_k, _store_zip3667_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _product_name3551 = (it->second)._product_name3551;
                std::array<char, TPCDS_READ_MAX + 1> _product_name3551_n{};
                memcpy(_product_name3551_n.data(), (_product_name3551).data(), (_product_name3551).length());
                int32_t _item_sk3552 = (it->second)._item_sk3552;
                std::string _store_name3553 = (it->second)._store_name3553;
                std::array<char, TPCDS_READ_MAX + 1> _store_name3553_n{};
                memcpy(_store_name3553_n.data(), (_store_name3553).data(), (_store_name3553).length());
                std::string _store_zip3554 = (it->second)._store_zip3554;
                std::array<char, TPCDS_READ_MAX + 1> _store_zip3554_n{};
                memcpy(_store_zip3554_n.data(), (_store_zip3554).data(), (_store_zip3554).length());
                std::string _b_street_number3555 = (it->second)._b_street_number3555;
                std::array<char, TPCDS_READ_MAX + 1> _b_street_number3555_n{};
                memcpy(_b_street_number3555_n.data(), (_b_street_number3555).data(), (_b_street_number3555).length());
                std::string _b_streen_name3556 = (it->second)._b_streen_name3556;
                std::array<char, TPCDS_READ_MAX + 1> _b_streen_name3556_n{};
                memcpy(_b_streen_name3556_n.data(), (_b_streen_name3556).data(), (_b_streen_name3556).length());
                std::string _b_city3557 = (it->second)._b_city3557;
                std::array<char, TPCDS_READ_MAX + 1> _b_city3557_n{};
                memcpy(_b_city3557_n.data(), (_b_city3557).data(), (_b_city3557).length());
                std::string _b_zip3558 = (it->second)._b_zip3558;
                std::array<char, TPCDS_READ_MAX + 1> _b_zip3558_n{};
                memcpy(_b_zip3558_n.data(), (_b_zip3558).data(), (_b_zip3558).length());
                std::string _c_street_number3559 = (it->second)._c_street_number3559;
                std::array<char, TPCDS_READ_MAX + 1> _c_street_number3559_n{};
                memcpy(_c_street_number3559_n.data(), (_c_street_number3559).data(), (_c_street_number3559).length());
                std::string _c_street_name3560 = (it->second)._c_street_name3560;
                std::array<char, TPCDS_READ_MAX + 1> _c_street_name3560_n{};
                memcpy(_c_street_name3560_n.data(), (_c_street_name3560).data(), (_c_street_name3560).length());
                std::string _c_city3561 = (it->second)._c_city3561;
                std::array<char, TPCDS_READ_MAX + 1> _c_city3561_n{};
                memcpy(_c_city3561_n.data(), (_c_city3561).data(), (_c_city3561).length());
                std::string _c_zip3562 = (it->second)._c_zip3562;
                std::array<char, TPCDS_READ_MAX + 1> _c_zip3562_n{};
                memcpy(_c_zip3562_n.data(), (_c_zip3562).data(), (_c_zip3562).length());
                int32_t _syear3563 = (it->second)._syear3563;
                int64_t _cnt3566L = (it->second)._cnt3566L;
                int64_t _s13567 = (it->second)._s13567;
                int64_t _s23568 = (it->second)._s23568;
                int64_t _s33569 = (it->second)._s33569;
                int32_t _item_sk3665 = tbl_Aggregate_TD_3248686_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _store_name3666_n = tbl_Aggregate_TD_3248686_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _store_name3666 = std::string(_store_name3666_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _store_zip3667_n = tbl_Aggregate_TD_3248686_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _store_zip3667 = std::string(_store_zip3667_n.data());
                int32_t _syear3676 = tbl_Aggregate_TD_3248686_output.getInt32(i, 3);
                int64_t _cnt3679L = tbl_Aggregate_TD_3248686_output.getInt64(i, 4);
                int64_t _s13680 = tbl_Aggregate_TD_3248686_output.getInt64(i, 5);
                int64_t _s23681 = tbl_Aggregate_TD_3248686_output.getInt64(i, 6);
                int64_t _s33682 = tbl_Aggregate_TD_3248686_output.getInt64(i, 7);
                tbl_JOIN_INNER_TD_2710081_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _product_name3551_n);
                tbl_JOIN_INNER_TD_2710081_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _store_name3553_n);
                tbl_JOIN_INNER_TD_2710081_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _store_zip3554_n);
                tbl_JOIN_INNER_TD_2710081_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _b_street_number3555_n);
                tbl_JOIN_INNER_TD_2710081_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _b_streen_name3556_n);
                tbl_JOIN_INNER_TD_2710081_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _b_city3557_n);
                tbl_JOIN_INNER_TD_2710081_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _b_zip3558_n);
                tbl_JOIN_INNER_TD_2710081_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _c_street_number3559_n);
                tbl_JOIN_INNER_TD_2710081_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _c_street_name3560_n);
                tbl_JOIN_INNER_TD_2710081_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _c_city3561_n);
                tbl_JOIN_INNER_TD_2710081_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _c_zip3562_n);
                tbl_JOIN_INNER_TD_2710081_output.setInt32(r, 11, _syear3563);
                tbl_JOIN_INNER_TD_2710081_output.setInt64(r, 12, _cnt3566L);
                tbl_JOIN_INNER_TD_2710081_output.setInt64(r, 13, _s13567);
                tbl_JOIN_INNER_TD_2710081_output.setInt64(r, 14, _s23568);
                tbl_JOIN_INNER_TD_2710081_output.setInt64(r, 15, _s33569);
                tbl_JOIN_INNER_TD_2710081_output.setInt32(r, 19, _syear3676);
                tbl_JOIN_INNER_TD_2710081_output.setInt64(r, 20, _cnt3679L);
                tbl_JOIN_INNER_TD_2710081_output.setInt64(r, 16, _s13680);
                tbl_JOIN_INNER_TD_2710081_output.setInt64(r, 17, _s23681);
                tbl_JOIN_INNER_TD_2710081_output.setInt64(r, 18, _s33682);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_2710081_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_2710081_key_rightMajor, SW_JOIN_INNER_TD_2710081_payload_rightMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_3248686_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _item_sk3665_k = tbl_Aggregate_TD_3248686_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _store_name3666_k_n = tbl_Aggregate_TD_3248686_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _store_name3666_k = std::string(_store_name3666_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _store_zip3667_k_n = tbl_Aggregate_TD_3248686_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _store_zip3667_k = std::string(_store_zip3667_k_n.data());
            SW_JOIN_INNER_TD_2710081_key_rightMajor keyA{_item_sk3665_k, _store_name3666_k, _store_zip3667_k};
            int32_t _item_sk3665 = tbl_Aggregate_TD_3248686_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _store_name3666_n = tbl_Aggregate_TD_3248686_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _store_name3666 = std::string(_store_name3666_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _store_zip3667_n = tbl_Aggregate_TD_3248686_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _store_zip3667 = std::string(_store_zip3667_n.data());
            int32_t _syear3676 = tbl_Aggregate_TD_3248686_output.getInt32(i, 3);
            int64_t _cnt3679L = tbl_Aggregate_TD_3248686_output.getInt64(i, 4);
            int64_t _s13680 = tbl_Aggregate_TD_3248686_output.getInt64(i, 5);
            int64_t _s23681 = tbl_Aggregate_TD_3248686_output.getInt64(i, 6);
            int64_t _s33682 = tbl_Aggregate_TD_3248686_output.getInt64(i, 7);
            SW_JOIN_INNER_TD_2710081_payload_rightMajor payloadA{_item_sk3665, _store_name3666, _store_zip3667, _syear3676, _cnt3679L, _s13680, _s23681, _s33682};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_3607278_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _item_sk3552_k = tbl_Aggregate_TD_3607278_output.getInt32(i, 1);
            std::array<char, TPCDS_READ_MAX + 1> _store_name3553_k_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _store_name3553_k = std::string(_store_name3553_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _store_zip3554_k_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _store_zip3554_k = std::string(_store_zip3554_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_2710081_key_rightMajor{_item_sk3552_k, _store_name3553_k, _store_zip3554_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _item_sk3665 = (it->second)._item_sk3665;
                std::string _store_name3666 = (it->second)._store_name3666;
                std::array<char, TPCDS_READ_MAX + 1> _store_name3666_n{};
                memcpy(_store_name3666_n.data(), (_store_name3666).data(), (_store_name3666).length());
                std::string _store_zip3667 = (it->second)._store_zip3667;
                std::array<char, TPCDS_READ_MAX + 1> _store_zip3667_n{};
                memcpy(_store_zip3667_n.data(), (_store_zip3667).data(), (_store_zip3667).length());
                int32_t _syear3676 = (it->second)._syear3676;
                int64_t _cnt3679L = (it->second)._cnt3679L;
                int64_t _s13680 = (it->second)._s13680;
                int64_t _s23681 = (it->second)._s23681;
                int64_t _s33682 = (it->second)._s33682;
                std::array<char, TPCDS_READ_MAX + 1> _product_name3551_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _product_name3551 = std::string(_product_name3551_n.data());
                int32_t _item_sk3552 = tbl_Aggregate_TD_3607278_output.getInt32(i, 1);
                std::array<char, TPCDS_READ_MAX + 1> _store_name3553_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _store_name3553 = std::string(_store_name3553_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _store_zip3554_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _store_zip3554 = std::string(_store_zip3554_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _b_street_number3555_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _b_street_number3555 = std::string(_b_street_number3555_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _b_streen_name3556_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _b_streen_name3556 = std::string(_b_streen_name3556_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _b_city3557_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _b_city3557 = std::string(_b_city3557_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _b_zip3558_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
                std::string _b_zip3558 = std::string(_b_zip3558_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_street_number3559_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
                std::string _c_street_number3559 = std::string(_c_street_number3559_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_street_name3560_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
                std::string _c_street_name3560 = std::string(_c_street_name3560_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_city3561_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
                std::string _c_city3561 = std::string(_c_city3561_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_zip3562_n = tbl_Aggregate_TD_3607278_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 11);
                std::string _c_zip3562 = std::string(_c_zip3562_n.data());
                int32_t _syear3563 = tbl_Aggregate_TD_3607278_output.getInt32(i, 12);
                int64_t _cnt3566L = tbl_Aggregate_TD_3607278_output.getInt64(i, 13);
                int64_t _s13567 = tbl_Aggregate_TD_3607278_output.getInt64(i, 14);
                int64_t _s23568 = tbl_Aggregate_TD_3607278_output.getInt64(i, 15);
                int64_t _s33569 = tbl_Aggregate_TD_3607278_output.getInt64(i, 16);
                tbl_JOIN_INNER_TD_2710081_output.setInt32(r, 19, _syear3676);
                tbl_JOIN_INNER_TD_2710081_output.setInt64(r, 20, _cnt3679L);
                tbl_JOIN_INNER_TD_2710081_output.setInt64(r, 16, _s13680);
                tbl_JOIN_INNER_TD_2710081_output.setInt64(r, 17, _s23681);
                tbl_JOIN_INNER_TD_2710081_output.setInt64(r, 18, _s33682);
                tbl_JOIN_INNER_TD_2710081_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _product_name3551_n);
                tbl_JOIN_INNER_TD_2710081_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _store_name3553_n);
                tbl_JOIN_INNER_TD_2710081_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _store_zip3554_n);
                tbl_JOIN_INNER_TD_2710081_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _b_street_number3555_n);
                tbl_JOIN_INNER_TD_2710081_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _b_streen_name3556_n);
                tbl_JOIN_INNER_TD_2710081_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _b_city3557_n);
                tbl_JOIN_INNER_TD_2710081_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _b_zip3558_n);
                tbl_JOIN_INNER_TD_2710081_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 7, _c_street_number3559_n);
                tbl_JOIN_INNER_TD_2710081_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 8, _c_street_name3560_n);
                tbl_JOIN_INNER_TD_2710081_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 9, _c_city3561_n);
                tbl_JOIN_INNER_TD_2710081_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 10, _c_zip3562_n);
                tbl_JOIN_INNER_TD_2710081_output.setInt32(r, 11, _syear3563);
                tbl_JOIN_INNER_TD_2710081_output.setInt64(r, 12, _cnt3566L);
                tbl_JOIN_INNER_TD_2710081_output.setInt64(r, 13, _s13567);
                tbl_JOIN_INNER_TD_2710081_output.setInt64(r, 14, _s23568);
                tbl_JOIN_INNER_TD_2710081_output.setInt64(r, 15, _s33569);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_2710081_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_2710081_output #Row: " << tbl_JOIN_INNER_TD_2710081_output.getNumRow() << std::endl;
}

void SW_Project_TD_1260547(Table &tbl_JOIN_INNER_TD_2710081_output, Table &tbl_Project_TD_1260547_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(s1#3680 AS cs2_s1#3544, s2#3681 AS cs2_s2#3545, s3#3682 AS cs2_s3#3546, syear#3676 AS cs2_syear#3547, cnt#3679L AS cs2_cnt#3548L)
    // Input: ListBuffer(product_name#3551, store_name#3553, store_zip#3554, b_street_number#3555, b_streen_name#3556, b_city#3557, b_zip#3558, c_street_number#3559, c_street_name#3560, c_city#3561, c_zip#3562, syear#3563, cnt#3566L, s1#3567, s2#3568, s3#3569, s1#3680, s2#3681, s3#3682, syear#3676, cnt#3679L)
    // Output: ListBuffer(product_name#3551, store_name#3553, store_zip#3554, b_street_number#3555, b_streen_name#3556, b_city#3557, b_zip#3558, c_street_number#3559, c_street_name#3560, c_city#3561, c_zip#3562, syear#3563, cnt#3566L, s1#3567, s2#3568, s3#3569, cs2_s1#3544, cs2_s2#3545, cs2_s3#3546, cs2_syear#3547, cs2_cnt#3548L, cnt#3679L)
    int nrow1 = tbl_JOIN_INNER_TD_2710081_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _product_name3551 = tbl_JOIN_INNER_TD_2710081_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _store_name3553 = tbl_JOIN_INNER_TD_2710081_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _store_zip3554 = tbl_JOIN_INNER_TD_2710081_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _b_street_number3555 = tbl_JOIN_INNER_TD_2710081_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _b_streen_name3556 = tbl_JOIN_INNER_TD_2710081_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _b_city3557 = tbl_JOIN_INNER_TD_2710081_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _b_zip3558 = tbl_JOIN_INNER_TD_2710081_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
        std::array<char, TPCDS_READ_MAX + 1> _c_street_number3559 = tbl_JOIN_INNER_TD_2710081_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 7);
        std::array<char, TPCDS_READ_MAX + 1> _c_street_name3560 = tbl_JOIN_INNER_TD_2710081_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 8);
        std::array<char, TPCDS_READ_MAX + 1> _c_city3561 = tbl_JOIN_INNER_TD_2710081_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 9);
        std::array<char, TPCDS_READ_MAX + 1> _c_zip3562 = tbl_JOIN_INNER_TD_2710081_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 10);
        int32_t _syear3563 = tbl_JOIN_INNER_TD_2710081_output.getInt32(i, 11);
        int64_t _cnt3566L = tbl_JOIN_INNER_TD_2710081_output.getInt64(i, 12);
        int64_t _s13567 = tbl_JOIN_INNER_TD_2710081_output.getInt64(i, 13);
        int64_t _s23568 = tbl_JOIN_INNER_TD_2710081_output.getInt64(i, 14);
        int64_t _s33569 = tbl_JOIN_INNER_TD_2710081_output.getInt64(i, 15);
        int64_t _s13680 = tbl_JOIN_INNER_TD_2710081_output.getInt64(i, 16);
        int64_t _s23681 = tbl_JOIN_INNER_TD_2710081_output.getInt64(i, 17);
        int64_t _s33682 = tbl_JOIN_INNER_TD_2710081_output.getInt64(i, 18);
        int32_t _syear3676 = tbl_JOIN_INNER_TD_2710081_output.getInt32(i, 19);
        int64_t _cnt3679L = tbl_JOIN_INNER_TD_2710081_output.getInt64(i, 20);
        int64_t _cs2_s13544 = _s13680;
        tbl_Project_TD_1260547_output.setInt64(i, 16, _cs2_s13544);
        int64_t _cs2_s23545 = _s23681;
        tbl_Project_TD_1260547_output.setInt64(i, 17, _cs2_s23545);
        int64_t _cs2_s33546 = _s33682;
        tbl_Project_TD_1260547_output.setInt64(i, 18, _cs2_s33546);
        int32_t _cs2_syear3547 = _syear3676;
        tbl_Project_TD_1260547_output.setInt32(i, 19, _cs2_syear3547);
        int64_t _cs2_cnt3548L = _cnt3679L;
        tbl_Project_TD_1260547_output.setInt64(i, 20, _cs2_cnt3548L);
        tbl_Project_TD_1260547_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 0, _product_name3551);
        tbl_Project_TD_1260547_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 1, _store_name3553);
        tbl_Project_TD_1260547_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 2, _store_zip3554);
        tbl_Project_TD_1260547_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 3, _b_street_number3555);
        tbl_Project_TD_1260547_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 4, _b_streen_name3556);
        tbl_Project_TD_1260547_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 5, _b_city3557);
        tbl_Project_TD_1260547_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 6, _b_zip3558);
        tbl_Project_TD_1260547_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 7, _c_street_number3559);
        tbl_Project_TD_1260547_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 8, _c_street_name3560);
        tbl_Project_TD_1260547_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 9, _c_city3561);
        tbl_Project_TD_1260547_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 10, _c_zip3562);
        tbl_Project_TD_1260547_output.setInt32(i, 11, _syear3563);
        tbl_Project_TD_1260547_output.setInt64(i, 12, _cnt3566L);
        tbl_Project_TD_1260547_output.setInt64(i, 13, _s13567);
        tbl_Project_TD_1260547_output.setInt64(i, 14, _s23568);
        tbl_Project_TD_1260547_output.setInt64(i, 15, _s33569);
        tbl_Project_TD_1260547_output.setInt64(i, 21, _cnt3679L);
    }
    tbl_Project_TD_1260547_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_1260547_output #Row: " << tbl_Project_TD_1260547_output.getNumRow() << std::endl;
}

void SW_Sort_TD_0976842(Table &tbl_Project_TD_1260547_output, Table &tbl_Sort_TD_0976842_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(product_name#3551 ASC NULLS FIRST, store_name#3553 ASC NULLS FIRST, cnt#3679L ASC NULLS FIRST)
    // Input: ListBuffer(product_name#3551, store_name#3553, store_zip#3554, b_street_number#3555, b_streen_name#3556, b_city#3557, b_zip#3558, c_street_number#3559, c_street_name#3560, c_city#3561, c_zip#3562, syear#3563, cnt#3566L, s1#3567, s2#3568, s3#3569, cs2_s1#3544, cs2_s2#3545, cs2_s3#3546, cs2_syear#3547, cs2_cnt#3548L, cnt#3679L)
    // Output: ListBuffer(product_name#3551, store_name#3553, store_zip#3554, b_street_number#3555, b_streen_name#3556, b_city#3557, b_zip#3558, c_street_number#3559, c_street_name#3560, c_city#3561, c_zip#3562, syear#3563, cnt#3566L, s1#3567, s2#3568, s3#3569, cs2_s1#3544, cs2_s2#3545, cs2_s3#3546, cs2_syear#3547, cs2_cnt#3548L, cnt#3679L)
    struct SW_Sort_TD_0976842Row {
        std::string _product_name3551;
        std::string _store_name3553;
        std::string _store_zip3554;
        std::string _b_street_number3555;
        std::string _b_streen_name3556;
        std::string _b_city3557;
        std::string _b_zip3558;
        std::string _c_street_number3559;
        std::string _c_street_name3560;
        std::string _c_city3561;
        std::string _c_zip3562;
        int32_t _syear3563;
        int64_t _cnt3566L;
        int64_t _s13567;
        int64_t _s23568;
        int64_t _s33569;
        int64_t _cs2_s13544;
        int64_t _cs2_s23545;
        int64_t _cs2_s33546;
        int32_t _cs2_syear3547;
        int64_t _cs2_cnt3548L;
        int64_t _cnt3679L;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_0976842Row& a, const SW_Sort_TD_0976842Row& b) const { return 
 (a._product_name3551 < b._product_name3551) || 
 ((a._product_name3551 == b._product_name3551) && (a._store_name3553 < b._store_name3553)) || 
 ((a._product_name3551 == b._product_name3551) && (a._store_name3553 == b._store_name3553) && (a._cnt3679L < b._cnt3679L)); 
}
    }SW_Sort_TD_0976842_order; 

    int nrow1 = tbl_Project_TD_1260547_output.getNumRow();
    std::vector<SW_Sort_TD_0976842Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _product_name3551 = tbl_Project_TD_1260547_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _store_name3553 = tbl_Project_TD_1260547_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _store_zip3554 = tbl_Project_TD_1260547_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _b_street_number3555 = tbl_Project_TD_1260547_output.getcharN<char, TPCDS_READ_MAX +1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _b_streen_name3556 = tbl_Project_TD_1260547_output.getcharN<char, TPCDS_READ_MAX +1>(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _b_city3557 = tbl_Project_TD_1260547_output.getcharN<char, TPCDS_READ_MAX +1>(i, 5);
        std::array<char, TPCDS_READ_MAX + 1> _b_zip3558 = tbl_Project_TD_1260547_output.getcharN<char, TPCDS_READ_MAX +1>(i, 6);
        std::array<char, TPCDS_READ_MAX + 1> _c_street_number3559 = tbl_Project_TD_1260547_output.getcharN<char, TPCDS_READ_MAX +1>(i, 7);
        std::array<char, TPCDS_READ_MAX + 1> _c_street_name3560 = tbl_Project_TD_1260547_output.getcharN<char, TPCDS_READ_MAX +1>(i, 8);
        std::array<char, TPCDS_READ_MAX + 1> _c_city3561 = tbl_Project_TD_1260547_output.getcharN<char, TPCDS_READ_MAX +1>(i, 9);
        std::array<char, TPCDS_READ_MAX + 1> _c_zip3562 = tbl_Project_TD_1260547_output.getcharN<char, TPCDS_READ_MAX +1>(i, 10);
        int32_t _syear3563 = tbl_Project_TD_1260547_output.getInt32(i, 11);
        int64_t _cnt3566L = tbl_Project_TD_1260547_output.getInt64(i, 12);
        int64_t _s13567 = tbl_Project_TD_1260547_output.getInt64(i, 13);
        int64_t _s23568 = tbl_Project_TD_1260547_output.getInt64(i, 14);
        int64_t _s33569 = tbl_Project_TD_1260547_output.getInt64(i, 15);
        int64_t _cs2_s13544 = tbl_Project_TD_1260547_output.getInt64(i, 16);
        int64_t _cs2_s23545 = tbl_Project_TD_1260547_output.getInt64(i, 17);
        int64_t _cs2_s33546 = tbl_Project_TD_1260547_output.getInt64(i, 18);
        int32_t _cs2_syear3547 = tbl_Project_TD_1260547_output.getInt32(i, 19);
        int64_t _cs2_cnt3548L = tbl_Project_TD_1260547_output.getInt64(i, 20);
        int64_t _cnt3679L = tbl_Project_TD_1260547_output.getInt64(i, 21);
        SW_Sort_TD_0976842Row t = {std::string(_product_name3551.data()),std::string(_store_name3553.data()),std::string(_store_zip3554.data()),std::string(_b_street_number3555.data()),std::string(_b_streen_name3556.data()),std::string(_b_city3557.data()),std::string(_b_zip3558.data()),std::string(_c_street_number3559.data()),std::string(_c_street_name3560.data()),std::string(_c_city3561.data()),std::string(_c_zip3562.data()),_syear3563,_cnt3566L,_s13567,_s23568,_s33569,_cs2_s13544,_cs2_s23545,_cs2_s33546,_cs2_syear3547,_cs2_cnt3548L,_cnt3679L};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_0976842_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _product_name3551{};
        memcpy(_product_name3551.data(), (it._product_name3551).data(), (it._product_name3551).length());
        tbl_Sort_TD_0976842_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _product_name3551);
        std::array<char, TPCDS_READ_MAX + 1> _store_name3553{};
        memcpy(_store_name3553.data(), (it._store_name3553).data(), (it._store_name3553).length());
        tbl_Sort_TD_0976842_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _store_name3553);
        std::array<char, TPCDS_READ_MAX + 1> _store_zip3554{};
        memcpy(_store_zip3554.data(), (it._store_zip3554).data(), (it._store_zip3554).length());
        tbl_Sort_TD_0976842_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _store_zip3554);
        std::array<char, TPCDS_READ_MAX + 1> _b_street_number3555{};
        memcpy(_b_street_number3555.data(), (it._b_street_number3555).data(), (it._b_street_number3555).length());
        tbl_Sort_TD_0976842_output.setcharN<char, TPCDS_READ_MAX +1>(r, 3, _b_street_number3555);
        std::array<char, TPCDS_READ_MAX + 1> _b_streen_name3556{};
        memcpy(_b_streen_name3556.data(), (it._b_streen_name3556).data(), (it._b_streen_name3556).length());
        tbl_Sort_TD_0976842_output.setcharN<char, TPCDS_READ_MAX +1>(r, 4, _b_streen_name3556);
        std::array<char, TPCDS_READ_MAX + 1> _b_city3557{};
        memcpy(_b_city3557.data(), (it._b_city3557).data(), (it._b_city3557).length());
        tbl_Sort_TD_0976842_output.setcharN<char, TPCDS_READ_MAX +1>(r, 5, _b_city3557);
        std::array<char, TPCDS_READ_MAX + 1> _b_zip3558{};
        memcpy(_b_zip3558.data(), (it._b_zip3558).data(), (it._b_zip3558).length());
        tbl_Sort_TD_0976842_output.setcharN<char, TPCDS_READ_MAX +1>(r, 6, _b_zip3558);
        std::array<char, TPCDS_READ_MAX + 1> _c_street_number3559{};
        memcpy(_c_street_number3559.data(), (it._c_street_number3559).data(), (it._c_street_number3559).length());
        tbl_Sort_TD_0976842_output.setcharN<char, TPCDS_READ_MAX +1>(r, 7, _c_street_number3559);
        std::array<char, TPCDS_READ_MAX + 1> _c_street_name3560{};
        memcpy(_c_street_name3560.data(), (it._c_street_name3560).data(), (it._c_street_name3560).length());
        tbl_Sort_TD_0976842_output.setcharN<char, TPCDS_READ_MAX +1>(r, 8, _c_street_name3560);
        std::array<char, TPCDS_READ_MAX + 1> _c_city3561{};
        memcpy(_c_city3561.data(), (it._c_city3561).data(), (it._c_city3561).length());
        tbl_Sort_TD_0976842_output.setcharN<char, TPCDS_READ_MAX +1>(r, 9, _c_city3561);
        std::array<char, TPCDS_READ_MAX + 1> _c_zip3562{};
        memcpy(_c_zip3562.data(), (it._c_zip3562).data(), (it._c_zip3562).length());
        tbl_Sort_TD_0976842_output.setcharN<char, TPCDS_READ_MAX +1>(r, 10, _c_zip3562);
        tbl_Sort_TD_0976842_output.setInt32(r, 11, it._syear3563);
        tbl_Sort_TD_0976842_output.setInt64(r, 12, it._cnt3566L);
        tbl_Sort_TD_0976842_output.setInt64(r, 13, it._s13567);
        tbl_Sort_TD_0976842_output.setInt64(r, 14, it._s23568);
        tbl_Sort_TD_0976842_output.setInt64(r, 15, it._s33569);
        tbl_Sort_TD_0976842_output.setInt64(r, 16, it._cs2_s13544);
        tbl_Sort_TD_0976842_output.setInt64(r, 17, it._cs2_s23545);
        tbl_Sort_TD_0976842_output.setInt64(r, 18, it._cs2_s33546);
        tbl_Sort_TD_0976842_output.setInt32(r, 19, it._cs2_syear3547);
        tbl_Sort_TD_0976842_output.setInt64(r, 20, it._cs2_cnt3548L);
        tbl_Sort_TD_0976842_output.setInt64(r, 21, it._cnt3679L);
        if (r < 10) {
            std::cout << (it._product_name3551).data() << " " << (it._store_name3553).data() << " " << (it._store_zip3554).data() << " " << (it._b_street_number3555).data() << " " << (it._b_streen_name3556).data() << " " << (it._b_city3557).data() << " " << (it._b_zip3558).data() << " " << (it._c_street_number3559).data() << " " << (it._c_street_name3560).data() << " " << (it._c_city3561).data() << " " << (it._c_zip3562).data() << " " << it._syear3563 << " " << it._cnt3566L << " " << it._s13567 << " " << it._s23568 << " " << it._s33569 << " " << it._cs2_s13544 << " " << it._cs2_s23545 << " " << it._cs2_s33546 << " " << it._cs2_syear3547 << " " << it._cs2_cnt3548L << " " << it._cnt3679L << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_0976842_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_0976842_output #Row: " << tbl_Sort_TD_0976842_output.getNumRow() << std::endl;
}

