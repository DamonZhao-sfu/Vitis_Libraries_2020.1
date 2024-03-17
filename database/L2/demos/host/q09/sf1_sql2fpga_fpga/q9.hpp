#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_2736300(Table &tbl_SerializeFromObject_TD_3511965_input, Table &tbl_Filter_TD_2736300_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_quantity#9489) AND ((ss_quantity#9489 >= 81) AND (ss_quantity#9489 <= 100))))
    // Input: ListBuffer(ss_net_paid#9499, ss_quantity#9489)
    // Output: ListBuffer(ss_net_paid#9499)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_3511965_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_quantity9489 = tbl_SerializeFromObject_TD_3511965_input.getInt32(i, 1);
        if ((_ss_quantity9489!= 0) && ((_ss_quantity9489 >= 81) && (_ss_quantity9489 <= 100))) {
            int64_t _ss_net_paid9499_t = tbl_SerializeFromObject_TD_3511965_input.getInt64(i, 0);
            tbl_Filter_TD_2736300_output.setInt64(r, 0, _ss_net_paid9499_t);
            r++;
        }
    }
    tbl_Filter_TD_2736300_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2736300_output #Row: " << tbl_Filter_TD_2736300_output.getNumRow() << std::endl;
}

void SW_Filter_TD_2480680(Table &tbl_SerializeFromObject_TD_3892127_input, Table &tbl_Filter_TD_2480680_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_quantity#9466) AND ((ss_quantity#9466 >= 81) AND (ss_quantity#9466 <= 100))))
    // Input: ListBuffer(ss_ext_discount_amt#9470, ss_quantity#9466)
    // Output: ListBuffer(ss_ext_discount_amt#9470)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_3892127_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_quantity9466 = tbl_SerializeFromObject_TD_3892127_input.getInt32(i, 1);
        if ((_ss_quantity9466!= 0) && ((_ss_quantity9466 >= 81) && (_ss_quantity9466 <= 100))) {
            int64_t _ss_ext_discount_amt9470_t = tbl_SerializeFromObject_TD_3892127_input.getInt64(i, 0);
            tbl_Filter_TD_2480680_output.setInt64(r, 0, _ss_ext_discount_amt9470_t);
            r++;
        }
    }
    tbl_Filter_TD_2480680_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2480680_output #Row: " << tbl_Filter_TD_2480680_output.getNumRow() << std::endl;
}

void SW_Filter_TD_2144689(Table &tbl_SerializeFromObject_TD_3514886_input, Table &tbl_Filter_TD_2144689_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_quantity#9443) AND ((ss_quantity#9443 >= 81) AND (ss_quantity#9443 <= 100))))
    // Input: ListBuffer(ss_sold_date_sk#9433, ss_sold_time_sk#9434, ss_item_sk#9435, ss_customer_sk#9436, ss_cdemo_sk#9437, ss_hdemo_sk#9438, ss_addr_sk#9439, ss_store_sk#9440, ss_promo_sk#9441, ss_ticket_number#9442L, ss_quantity#9443, ss_wholesale_cost#9444, ss_list_price#9445, ss_sales_price#9446, ss_ext_discount_amt#9447, ss_ext_sales_price#9448, ss_ext_wholesale_cost#9449, ss_ext_list_price#9450, ss_ext_tax#9451, ss_coupon_amt#9452, ss_net_paid#9453, ss_net_paid_inc_tax#9454, ss_net_profit#9455)
    // Output: ListBuffer(ss_sold_date_sk#9433, ss_sold_time_sk#9434, ss_item_sk#9435, ss_customer_sk#9436, ss_cdemo_sk#9437, ss_hdemo_sk#9438, ss_addr_sk#9439, ss_store_sk#9440, ss_promo_sk#9441, ss_ticket_number#9442L, ss_quantity#9443, ss_wholesale_cost#9444, ss_list_price#9445, ss_sales_price#9446, ss_ext_discount_amt#9447, ss_ext_sales_price#9448, ss_ext_wholesale_cost#9449, ss_ext_list_price#9450, ss_ext_tax#9451, ss_coupon_amt#9452, ss_net_paid#9453, ss_net_paid_inc_tax#9454, ss_net_profit#9455)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_3514886_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_quantity9443 = tbl_SerializeFromObject_TD_3514886_input.getInt32(i, 10);
        if ((_ss_quantity9443!= 0) && ((_ss_quantity9443 >= 81) && (_ss_quantity9443 <= 100))) {
            int32_t _ss_sold_date_sk9433_t = tbl_SerializeFromObject_TD_3514886_input.getInt32(i, 0);
            tbl_Filter_TD_2144689_output.setInt32(r, 0, _ss_sold_date_sk9433_t);
            int32_t _ss_sold_time_sk9434_t = tbl_SerializeFromObject_TD_3514886_input.getInt32(i, 1);
            tbl_Filter_TD_2144689_output.setInt32(r, 1, _ss_sold_time_sk9434_t);
            int32_t _ss_item_sk9435_t = tbl_SerializeFromObject_TD_3514886_input.getInt32(i, 2);
            tbl_Filter_TD_2144689_output.setInt32(r, 2, _ss_item_sk9435_t);
            int32_t _ss_customer_sk9436_t = tbl_SerializeFromObject_TD_3514886_input.getInt32(i, 3);
            tbl_Filter_TD_2144689_output.setInt32(r, 3, _ss_customer_sk9436_t);
            int32_t _ss_cdemo_sk9437_t = tbl_SerializeFromObject_TD_3514886_input.getInt32(i, 4);
            tbl_Filter_TD_2144689_output.setInt32(r, 4, _ss_cdemo_sk9437_t);
            int32_t _ss_hdemo_sk9438_t = tbl_SerializeFromObject_TD_3514886_input.getInt32(i, 5);
            tbl_Filter_TD_2144689_output.setInt32(r, 5, _ss_hdemo_sk9438_t);
            int32_t _ss_addr_sk9439_t = tbl_SerializeFromObject_TD_3514886_input.getInt32(i, 6);
            tbl_Filter_TD_2144689_output.setInt32(r, 6, _ss_addr_sk9439_t);
            int32_t _ss_store_sk9440_t = tbl_SerializeFromObject_TD_3514886_input.getInt32(i, 7);
            tbl_Filter_TD_2144689_output.setInt32(r, 7, _ss_store_sk9440_t);
            int32_t _ss_promo_sk9441_t = tbl_SerializeFromObject_TD_3514886_input.getInt32(i, 8);
            tbl_Filter_TD_2144689_output.setInt32(r, 8, _ss_promo_sk9441_t);
            int64_t _ss_ticket_number9442L_t = tbl_SerializeFromObject_TD_3514886_input.getInt64(i, 9);
            tbl_Filter_TD_2144689_output.setInt64(r, 9, _ss_ticket_number9442L_t);
            int32_t _ss_quantity9443_t = tbl_SerializeFromObject_TD_3514886_input.getInt32(i, 10);
            tbl_Filter_TD_2144689_output.setInt32(r, 10, _ss_quantity9443_t);
            int64_t _ss_wholesale_cost9444_t = tbl_SerializeFromObject_TD_3514886_input.getInt64(i, 11);
            tbl_Filter_TD_2144689_output.setInt64(r, 11, _ss_wholesale_cost9444_t);
            int64_t _ss_list_price9445_t = tbl_SerializeFromObject_TD_3514886_input.getInt64(i, 12);
            tbl_Filter_TD_2144689_output.setInt64(r, 12, _ss_list_price9445_t);
            int64_t _ss_sales_price9446_t = tbl_SerializeFromObject_TD_3514886_input.getInt64(i, 13);
            tbl_Filter_TD_2144689_output.setInt64(r, 13, _ss_sales_price9446_t);
            int64_t _ss_ext_discount_amt9447_t = tbl_SerializeFromObject_TD_3514886_input.getInt64(i, 14);
            tbl_Filter_TD_2144689_output.setInt64(r, 14, _ss_ext_discount_amt9447_t);
            int64_t _ss_ext_sales_price9448_t = tbl_SerializeFromObject_TD_3514886_input.getInt64(i, 15);
            tbl_Filter_TD_2144689_output.setInt64(r, 15, _ss_ext_sales_price9448_t);
            int64_t _ss_ext_wholesale_cost9449_t = tbl_SerializeFromObject_TD_3514886_input.getInt64(i, 16);
            tbl_Filter_TD_2144689_output.setInt64(r, 16, _ss_ext_wholesale_cost9449_t);
            int64_t _ss_ext_list_price9450_t = tbl_SerializeFromObject_TD_3514886_input.getInt64(i, 17);
            tbl_Filter_TD_2144689_output.setInt64(r, 17, _ss_ext_list_price9450_t);
            int64_t _ss_ext_tax9451_t = tbl_SerializeFromObject_TD_3514886_input.getInt64(i, 18);
            tbl_Filter_TD_2144689_output.setInt64(r, 18, _ss_ext_tax9451_t);
            int64_t _ss_coupon_amt9452_t = tbl_SerializeFromObject_TD_3514886_input.getInt64(i, 19);
            tbl_Filter_TD_2144689_output.setInt64(r, 19, _ss_coupon_amt9452_t);
            int64_t _ss_net_paid9453_t = tbl_SerializeFromObject_TD_3514886_input.getInt64(i, 20);
            tbl_Filter_TD_2144689_output.setInt64(r, 20, _ss_net_paid9453_t);
            int64_t _ss_net_paid_inc_tax9454_t = tbl_SerializeFromObject_TD_3514886_input.getInt64(i, 21);
            tbl_Filter_TD_2144689_output.setInt64(r, 21, _ss_net_paid_inc_tax9454_t);
            int64_t _ss_net_profit9455_t = tbl_SerializeFromObject_TD_3514886_input.getInt64(i, 22);
            tbl_Filter_TD_2144689_output.setInt64(r, 22, _ss_net_profit9455_t);
            r++;
        }
    }
    tbl_Filter_TD_2144689_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2144689_output #Row: " << tbl_Filter_TD_2144689_output.getNumRow() << std::endl;
}

void SW_Filter_TD_2902889(Table &tbl_SerializeFromObject_TD_3844515_input, Table &tbl_Filter_TD_2902889_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_quantity#9420) AND ((ss_quantity#9420 >= 61) AND (ss_quantity#9420 <= 80))))
    // Input: ListBuffer(ss_net_paid#9430, ss_quantity#9420)
    // Output: ListBuffer(ss_net_paid#9430)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_3844515_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_quantity9420 = tbl_SerializeFromObject_TD_3844515_input.getInt32(i, 1);
        if ((_ss_quantity9420!= 0) && ((_ss_quantity9420 >= 61) && (_ss_quantity9420 <= 80))) {
            int64_t _ss_net_paid9430_t = tbl_SerializeFromObject_TD_3844515_input.getInt64(i, 0);
            tbl_Filter_TD_2902889_output.setInt64(r, 0, _ss_net_paid9430_t);
            r++;
        }
    }
    tbl_Filter_TD_2902889_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2902889_output #Row: " << tbl_Filter_TD_2902889_output.getNumRow() << std::endl;
}

void SW_Filter_TD_2839080(Table &tbl_SerializeFromObject_TD_3204386_input, Table &tbl_Filter_TD_2839080_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_quantity#9397) AND ((ss_quantity#9397 >= 61) AND (ss_quantity#9397 <= 80))))
    // Input: ListBuffer(ss_ext_discount_amt#9401, ss_quantity#9397)
    // Output: ListBuffer(ss_ext_discount_amt#9401)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_3204386_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_quantity9397 = tbl_SerializeFromObject_TD_3204386_input.getInt32(i, 1);
        if ((_ss_quantity9397!= 0) && ((_ss_quantity9397 >= 61) && (_ss_quantity9397 <= 80))) {
            int64_t _ss_ext_discount_amt9401_t = tbl_SerializeFromObject_TD_3204386_input.getInt64(i, 0);
            tbl_Filter_TD_2839080_output.setInt64(r, 0, _ss_ext_discount_amt9401_t);
            r++;
        }
    }
    tbl_Filter_TD_2839080_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2839080_output #Row: " << tbl_Filter_TD_2839080_output.getNumRow() << std::endl;
}

void SW_Filter_TD_2487201(Table &tbl_SerializeFromObject_TD_3844841_input, Table &tbl_Filter_TD_2487201_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_quantity#9374) AND ((ss_quantity#9374 >= 61) AND (ss_quantity#9374 <= 80))))
    // Input: ListBuffer(ss_sold_date_sk#9364, ss_sold_time_sk#9365, ss_item_sk#9366, ss_customer_sk#9367, ss_cdemo_sk#9368, ss_hdemo_sk#9369, ss_addr_sk#9370, ss_store_sk#9371, ss_promo_sk#9372, ss_ticket_number#9373L, ss_quantity#9374, ss_wholesale_cost#9375, ss_list_price#9376, ss_sales_price#9377, ss_ext_discount_amt#9378, ss_ext_sales_price#9379, ss_ext_wholesale_cost#9380, ss_ext_list_price#9381, ss_ext_tax#9382, ss_coupon_amt#9383, ss_net_paid#9384, ss_net_paid_inc_tax#9385, ss_net_profit#9386)
    // Output: ListBuffer(ss_sold_date_sk#9364, ss_sold_time_sk#9365, ss_item_sk#9366, ss_customer_sk#9367, ss_cdemo_sk#9368, ss_hdemo_sk#9369, ss_addr_sk#9370, ss_store_sk#9371, ss_promo_sk#9372, ss_ticket_number#9373L, ss_quantity#9374, ss_wholesale_cost#9375, ss_list_price#9376, ss_sales_price#9377, ss_ext_discount_amt#9378, ss_ext_sales_price#9379, ss_ext_wholesale_cost#9380, ss_ext_list_price#9381, ss_ext_tax#9382, ss_coupon_amt#9383, ss_net_paid#9384, ss_net_paid_inc_tax#9385, ss_net_profit#9386)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_3844841_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_quantity9374 = tbl_SerializeFromObject_TD_3844841_input.getInt32(i, 10);
        if ((_ss_quantity9374!= 0) && ((_ss_quantity9374 >= 61) && (_ss_quantity9374 <= 80))) {
            int32_t _ss_sold_date_sk9364_t = tbl_SerializeFromObject_TD_3844841_input.getInt32(i, 0);
            tbl_Filter_TD_2487201_output.setInt32(r, 0, _ss_sold_date_sk9364_t);
            int32_t _ss_sold_time_sk9365_t = tbl_SerializeFromObject_TD_3844841_input.getInt32(i, 1);
            tbl_Filter_TD_2487201_output.setInt32(r, 1, _ss_sold_time_sk9365_t);
            int32_t _ss_item_sk9366_t = tbl_SerializeFromObject_TD_3844841_input.getInt32(i, 2);
            tbl_Filter_TD_2487201_output.setInt32(r, 2, _ss_item_sk9366_t);
            int32_t _ss_customer_sk9367_t = tbl_SerializeFromObject_TD_3844841_input.getInt32(i, 3);
            tbl_Filter_TD_2487201_output.setInt32(r, 3, _ss_customer_sk9367_t);
            int32_t _ss_cdemo_sk9368_t = tbl_SerializeFromObject_TD_3844841_input.getInt32(i, 4);
            tbl_Filter_TD_2487201_output.setInt32(r, 4, _ss_cdemo_sk9368_t);
            int32_t _ss_hdemo_sk9369_t = tbl_SerializeFromObject_TD_3844841_input.getInt32(i, 5);
            tbl_Filter_TD_2487201_output.setInt32(r, 5, _ss_hdemo_sk9369_t);
            int32_t _ss_addr_sk9370_t = tbl_SerializeFromObject_TD_3844841_input.getInt32(i, 6);
            tbl_Filter_TD_2487201_output.setInt32(r, 6, _ss_addr_sk9370_t);
            int32_t _ss_store_sk9371_t = tbl_SerializeFromObject_TD_3844841_input.getInt32(i, 7);
            tbl_Filter_TD_2487201_output.setInt32(r, 7, _ss_store_sk9371_t);
            int32_t _ss_promo_sk9372_t = tbl_SerializeFromObject_TD_3844841_input.getInt32(i, 8);
            tbl_Filter_TD_2487201_output.setInt32(r, 8, _ss_promo_sk9372_t);
            int64_t _ss_ticket_number9373L_t = tbl_SerializeFromObject_TD_3844841_input.getInt64(i, 9);
            tbl_Filter_TD_2487201_output.setInt64(r, 9, _ss_ticket_number9373L_t);
            int32_t _ss_quantity9374_t = tbl_SerializeFromObject_TD_3844841_input.getInt32(i, 10);
            tbl_Filter_TD_2487201_output.setInt32(r, 10, _ss_quantity9374_t);
            int64_t _ss_wholesale_cost9375_t = tbl_SerializeFromObject_TD_3844841_input.getInt64(i, 11);
            tbl_Filter_TD_2487201_output.setInt64(r, 11, _ss_wholesale_cost9375_t);
            int64_t _ss_list_price9376_t = tbl_SerializeFromObject_TD_3844841_input.getInt64(i, 12);
            tbl_Filter_TD_2487201_output.setInt64(r, 12, _ss_list_price9376_t);
            int64_t _ss_sales_price9377_t = tbl_SerializeFromObject_TD_3844841_input.getInt64(i, 13);
            tbl_Filter_TD_2487201_output.setInt64(r, 13, _ss_sales_price9377_t);
            int64_t _ss_ext_discount_amt9378_t = tbl_SerializeFromObject_TD_3844841_input.getInt64(i, 14);
            tbl_Filter_TD_2487201_output.setInt64(r, 14, _ss_ext_discount_amt9378_t);
            int64_t _ss_ext_sales_price9379_t = tbl_SerializeFromObject_TD_3844841_input.getInt64(i, 15);
            tbl_Filter_TD_2487201_output.setInt64(r, 15, _ss_ext_sales_price9379_t);
            int64_t _ss_ext_wholesale_cost9380_t = tbl_SerializeFromObject_TD_3844841_input.getInt64(i, 16);
            tbl_Filter_TD_2487201_output.setInt64(r, 16, _ss_ext_wholesale_cost9380_t);
            int64_t _ss_ext_list_price9381_t = tbl_SerializeFromObject_TD_3844841_input.getInt64(i, 17);
            tbl_Filter_TD_2487201_output.setInt64(r, 17, _ss_ext_list_price9381_t);
            int64_t _ss_ext_tax9382_t = tbl_SerializeFromObject_TD_3844841_input.getInt64(i, 18);
            tbl_Filter_TD_2487201_output.setInt64(r, 18, _ss_ext_tax9382_t);
            int64_t _ss_coupon_amt9383_t = tbl_SerializeFromObject_TD_3844841_input.getInt64(i, 19);
            tbl_Filter_TD_2487201_output.setInt64(r, 19, _ss_coupon_amt9383_t);
            int64_t _ss_net_paid9384_t = tbl_SerializeFromObject_TD_3844841_input.getInt64(i, 20);
            tbl_Filter_TD_2487201_output.setInt64(r, 20, _ss_net_paid9384_t);
            int64_t _ss_net_paid_inc_tax9385_t = tbl_SerializeFromObject_TD_3844841_input.getInt64(i, 21);
            tbl_Filter_TD_2487201_output.setInt64(r, 21, _ss_net_paid_inc_tax9385_t);
            int64_t _ss_net_profit9386_t = tbl_SerializeFromObject_TD_3844841_input.getInt64(i, 22);
            tbl_Filter_TD_2487201_output.setInt64(r, 22, _ss_net_profit9386_t);
            r++;
        }
    }
    tbl_Filter_TD_2487201_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2487201_output #Row: " << tbl_Filter_TD_2487201_output.getNumRow() << std::endl;
}

void SW_Filter_TD_2279938(Table &tbl_SerializeFromObject_TD_3416277_input, Table &tbl_Filter_TD_2279938_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_quantity#9351) AND ((ss_quantity#9351 >= 41) AND (ss_quantity#9351 <= 60))))
    // Input: ListBuffer(ss_net_paid#9361, ss_quantity#9351)
    // Output: ListBuffer(ss_net_paid#9361)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_3416277_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_quantity9351 = tbl_SerializeFromObject_TD_3416277_input.getInt32(i, 1);
        if ((_ss_quantity9351!= 0) && ((_ss_quantity9351 >= 41) && (_ss_quantity9351 <= 60))) {
            int64_t _ss_net_paid9361_t = tbl_SerializeFromObject_TD_3416277_input.getInt64(i, 0);
            tbl_Filter_TD_2279938_output.setInt64(r, 0, _ss_net_paid9361_t);
            r++;
        }
    }
    tbl_Filter_TD_2279938_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2279938_output #Row: " << tbl_Filter_TD_2279938_output.getNumRow() << std::endl;
}

void SW_Filter_TD_234100(Table &tbl_SerializeFromObject_TD_3204179_input, Table &tbl_Filter_TD_234100_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_quantity#9328) AND ((ss_quantity#9328 >= 41) AND (ss_quantity#9328 <= 60))))
    // Input: ListBuffer(ss_ext_discount_amt#9332, ss_quantity#9328)
    // Output: ListBuffer(ss_ext_discount_amt#9332)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_3204179_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_quantity9328 = tbl_SerializeFromObject_TD_3204179_input.getInt32(i, 1);
        if ((_ss_quantity9328!= 0) && ((_ss_quantity9328 >= 41) && (_ss_quantity9328 <= 60))) {
            int64_t _ss_ext_discount_amt9332_t = tbl_SerializeFromObject_TD_3204179_input.getInt64(i, 0);
            tbl_Filter_TD_234100_output.setInt64(r, 0, _ss_ext_discount_amt9332_t);
            r++;
        }
    }
    tbl_Filter_TD_234100_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_234100_output #Row: " << tbl_Filter_TD_234100_output.getNumRow() << std::endl;
}

void SW_Filter_TD_2634644(Table &tbl_SerializeFromObject_TD_3845752_input, Table &tbl_Filter_TD_2634644_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_quantity#9305) AND ((ss_quantity#9305 >= 41) AND (ss_quantity#9305 <= 60))))
    // Input: ListBuffer(ss_sold_date_sk#9295, ss_sold_time_sk#9296, ss_item_sk#9297, ss_customer_sk#9298, ss_cdemo_sk#9299, ss_hdemo_sk#9300, ss_addr_sk#9301, ss_store_sk#9302, ss_promo_sk#9303, ss_ticket_number#9304L, ss_quantity#9305, ss_wholesale_cost#9306, ss_list_price#9307, ss_sales_price#9308, ss_ext_discount_amt#9309, ss_ext_sales_price#9310, ss_ext_wholesale_cost#9311, ss_ext_list_price#9312, ss_ext_tax#9313, ss_coupon_amt#9314, ss_net_paid#9315, ss_net_paid_inc_tax#9316, ss_net_profit#9317)
    // Output: ListBuffer(ss_sold_date_sk#9295, ss_sold_time_sk#9296, ss_item_sk#9297, ss_customer_sk#9298, ss_cdemo_sk#9299, ss_hdemo_sk#9300, ss_addr_sk#9301, ss_store_sk#9302, ss_promo_sk#9303, ss_ticket_number#9304L, ss_quantity#9305, ss_wholesale_cost#9306, ss_list_price#9307, ss_sales_price#9308, ss_ext_discount_amt#9309, ss_ext_sales_price#9310, ss_ext_wholesale_cost#9311, ss_ext_list_price#9312, ss_ext_tax#9313, ss_coupon_amt#9314, ss_net_paid#9315, ss_net_paid_inc_tax#9316, ss_net_profit#9317)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_3845752_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_quantity9305 = tbl_SerializeFromObject_TD_3845752_input.getInt32(i, 10);
        if ((_ss_quantity9305!= 0) && ((_ss_quantity9305 >= 41) && (_ss_quantity9305 <= 60))) {
            int32_t _ss_sold_date_sk9295_t = tbl_SerializeFromObject_TD_3845752_input.getInt32(i, 0);
            tbl_Filter_TD_2634644_output.setInt32(r, 0, _ss_sold_date_sk9295_t);
            int32_t _ss_sold_time_sk9296_t = tbl_SerializeFromObject_TD_3845752_input.getInt32(i, 1);
            tbl_Filter_TD_2634644_output.setInt32(r, 1, _ss_sold_time_sk9296_t);
            int32_t _ss_item_sk9297_t = tbl_SerializeFromObject_TD_3845752_input.getInt32(i, 2);
            tbl_Filter_TD_2634644_output.setInt32(r, 2, _ss_item_sk9297_t);
            int32_t _ss_customer_sk9298_t = tbl_SerializeFromObject_TD_3845752_input.getInt32(i, 3);
            tbl_Filter_TD_2634644_output.setInt32(r, 3, _ss_customer_sk9298_t);
            int32_t _ss_cdemo_sk9299_t = tbl_SerializeFromObject_TD_3845752_input.getInt32(i, 4);
            tbl_Filter_TD_2634644_output.setInt32(r, 4, _ss_cdemo_sk9299_t);
            int32_t _ss_hdemo_sk9300_t = tbl_SerializeFromObject_TD_3845752_input.getInt32(i, 5);
            tbl_Filter_TD_2634644_output.setInt32(r, 5, _ss_hdemo_sk9300_t);
            int32_t _ss_addr_sk9301_t = tbl_SerializeFromObject_TD_3845752_input.getInt32(i, 6);
            tbl_Filter_TD_2634644_output.setInt32(r, 6, _ss_addr_sk9301_t);
            int32_t _ss_store_sk9302_t = tbl_SerializeFromObject_TD_3845752_input.getInt32(i, 7);
            tbl_Filter_TD_2634644_output.setInt32(r, 7, _ss_store_sk9302_t);
            int32_t _ss_promo_sk9303_t = tbl_SerializeFromObject_TD_3845752_input.getInt32(i, 8);
            tbl_Filter_TD_2634644_output.setInt32(r, 8, _ss_promo_sk9303_t);
            int64_t _ss_ticket_number9304L_t = tbl_SerializeFromObject_TD_3845752_input.getInt64(i, 9);
            tbl_Filter_TD_2634644_output.setInt64(r, 9, _ss_ticket_number9304L_t);
            int32_t _ss_quantity9305_t = tbl_SerializeFromObject_TD_3845752_input.getInt32(i, 10);
            tbl_Filter_TD_2634644_output.setInt32(r, 10, _ss_quantity9305_t);
            int64_t _ss_wholesale_cost9306_t = tbl_SerializeFromObject_TD_3845752_input.getInt64(i, 11);
            tbl_Filter_TD_2634644_output.setInt64(r, 11, _ss_wholesale_cost9306_t);
            int64_t _ss_list_price9307_t = tbl_SerializeFromObject_TD_3845752_input.getInt64(i, 12);
            tbl_Filter_TD_2634644_output.setInt64(r, 12, _ss_list_price9307_t);
            int64_t _ss_sales_price9308_t = tbl_SerializeFromObject_TD_3845752_input.getInt64(i, 13);
            tbl_Filter_TD_2634644_output.setInt64(r, 13, _ss_sales_price9308_t);
            int64_t _ss_ext_discount_amt9309_t = tbl_SerializeFromObject_TD_3845752_input.getInt64(i, 14);
            tbl_Filter_TD_2634644_output.setInt64(r, 14, _ss_ext_discount_amt9309_t);
            int64_t _ss_ext_sales_price9310_t = tbl_SerializeFromObject_TD_3845752_input.getInt64(i, 15);
            tbl_Filter_TD_2634644_output.setInt64(r, 15, _ss_ext_sales_price9310_t);
            int64_t _ss_ext_wholesale_cost9311_t = tbl_SerializeFromObject_TD_3845752_input.getInt64(i, 16);
            tbl_Filter_TD_2634644_output.setInt64(r, 16, _ss_ext_wholesale_cost9311_t);
            int64_t _ss_ext_list_price9312_t = tbl_SerializeFromObject_TD_3845752_input.getInt64(i, 17);
            tbl_Filter_TD_2634644_output.setInt64(r, 17, _ss_ext_list_price9312_t);
            int64_t _ss_ext_tax9313_t = tbl_SerializeFromObject_TD_3845752_input.getInt64(i, 18);
            tbl_Filter_TD_2634644_output.setInt64(r, 18, _ss_ext_tax9313_t);
            int64_t _ss_coupon_amt9314_t = tbl_SerializeFromObject_TD_3845752_input.getInt64(i, 19);
            tbl_Filter_TD_2634644_output.setInt64(r, 19, _ss_coupon_amt9314_t);
            int64_t _ss_net_paid9315_t = tbl_SerializeFromObject_TD_3845752_input.getInt64(i, 20);
            tbl_Filter_TD_2634644_output.setInt64(r, 20, _ss_net_paid9315_t);
            int64_t _ss_net_paid_inc_tax9316_t = tbl_SerializeFromObject_TD_3845752_input.getInt64(i, 21);
            tbl_Filter_TD_2634644_output.setInt64(r, 21, _ss_net_paid_inc_tax9316_t);
            int64_t _ss_net_profit9317_t = tbl_SerializeFromObject_TD_3845752_input.getInt64(i, 22);
            tbl_Filter_TD_2634644_output.setInt64(r, 22, _ss_net_profit9317_t);
            r++;
        }
    }
    tbl_Filter_TD_2634644_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2634644_output #Row: " << tbl_Filter_TD_2634644_output.getNumRow() << std::endl;
}

void SW_Filter_TD_2457007(Table &tbl_SerializeFromObject_TD_3146485_input, Table &tbl_Filter_TD_2457007_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_quantity#9282) AND ((ss_quantity#9282 >= 21) AND (ss_quantity#9282 <= 40))))
    // Input: ListBuffer(ss_net_paid#9292, ss_quantity#9282)
    // Output: ListBuffer(ss_net_paid#9292)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_3146485_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_quantity9282 = tbl_SerializeFromObject_TD_3146485_input.getInt32(i, 1);
        if ((_ss_quantity9282!= 0) && ((_ss_quantity9282 >= 21) && (_ss_quantity9282 <= 40))) {
            int64_t _ss_net_paid9292_t = tbl_SerializeFromObject_TD_3146485_input.getInt64(i, 0);
            tbl_Filter_TD_2457007_output.setInt64(r, 0, _ss_net_paid9292_t);
            r++;
        }
    }
    tbl_Filter_TD_2457007_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2457007_output #Row: " << tbl_Filter_TD_2457007_output.getNumRow() << std::endl;
}

void SW_Filter_TD_2948317(Table &tbl_SerializeFromObject_TD_3129152_input, Table &tbl_Filter_TD_2948317_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_quantity#9259) AND ((ss_quantity#9259 >= 21) AND (ss_quantity#9259 <= 40))))
    // Input: ListBuffer(ss_ext_discount_amt#9263, ss_quantity#9259)
    // Output: ListBuffer(ss_ext_discount_amt#9263)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_3129152_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_quantity9259 = tbl_SerializeFromObject_TD_3129152_input.getInt32(i, 1);
        if ((_ss_quantity9259!= 0) && ((_ss_quantity9259 >= 21) && (_ss_quantity9259 <= 40))) {
            int64_t _ss_ext_discount_amt9263_t = tbl_SerializeFromObject_TD_3129152_input.getInt64(i, 0);
            tbl_Filter_TD_2948317_output.setInt64(r, 0, _ss_ext_discount_amt9263_t);
            r++;
        }
    }
    tbl_Filter_TD_2948317_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2948317_output #Row: " << tbl_Filter_TD_2948317_output.getNumRow() << std::endl;
}

void SW_Filter_TD_2578037(Table &tbl_SerializeFromObject_TD_3582417_input, Table &tbl_Filter_TD_2578037_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_quantity#9236) AND ((ss_quantity#9236 >= 21) AND (ss_quantity#9236 <= 40))))
    // Input: ListBuffer(ss_sold_date_sk#9226, ss_sold_time_sk#9227, ss_item_sk#9228, ss_customer_sk#9229, ss_cdemo_sk#9230, ss_hdemo_sk#9231, ss_addr_sk#9232, ss_store_sk#9233, ss_promo_sk#9234, ss_ticket_number#9235L, ss_quantity#9236, ss_wholesale_cost#9237, ss_list_price#9238, ss_sales_price#9239, ss_ext_discount_amt#9240, ss_ext_sales_price#9241, ss_ext_wholesale_cost#9242, ss_ext_list_price#9243, ss_ext_tax#9244, ss_coupon_amt#9245, ss_net_paid#9246, ss_net_paid_inc_tax#9247, ss_net_profit#9248)
    // Output: ListBuffer(ss_sold_date_sk#9226, ss_sold_time_sk#9227, ss_item_sk#9228, ss_customer_sk#9229, ss_cdemo_sk#9230, ss_hdemo_sk#9231, ss_addr_sk#9232, ss_store_sk#9233, ss_promo_sk#9234, ss_ticket_number#9235L, ss_quantity#9236, ss_wholesale_cost#9237, ss_list_price#9238, ss_sales_price#9239, ss_ext_discount_amt#9240, ss_ext_sales_price#9241, ss_ext_wholesale_cost#9242, ss_ext_list_price#9243, ss_ext_tax#9244, ss_coupon_amt#9245, ss_net_paid#9246, ss_net_paid_inc_tax#9247, ss_net_profit#9248)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_3582417_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_quantity9236 = tbl_SerializeFromObject_TD_3582417_input.getInt32(i, 10);
        if ((_ss_quantity9236!= 0) && ((_ss_quantity9236 >= 21) && (_ss_quantity9236 <= 40))) {
            int32_t _ss_sold_date_sk9226_t = tbl_SerializeFromObject_TD_3582417_input.getInt32(i, 0);
            tbl_Filter_TD_2578037_output.setInt32(r, 0, _ss_sold_date_sk9226_t);
            int32_t _ss_sold_time_sk9227_t = tbl_SerializeFromObject_TD_3582417_input.getInt32(i, 1);
            tbl_Filter_TD_2578037_output.setInt32(r, 1, _ss_sold_time_sk9227_t);
            int32_t _ss_item_sk9228_t = tbl_SerializeFromObject_TD_3582417_input.getInt32(i, 2);
            tbl_Filter_TD_2578037_output.setInt32(r, 2, _ss_item_sk9228_t);
            int32_t _ss_customer_sk9229_t = tbl_SerializeFromObject_TD_3582417_input.getInt32(i, 3);
            tbl_Filter_TD_2578037_output.setInt32(r, 3, _ss_customer_sk9229_t);
            int32_t _ss_cdemo_sk9230_t = tbl_SerializeFromObject_TD_3582417_input.getInt32(i, 4);
            tbl_Filter_TD_2578037_output.setInt32(r, 4, _ss_cdemo_sk9230_t);
            int32_t _ss_hdemo_sk9231_t = tbl_SerializeFromObject_TD_3582417_input.getInt32(i, 5);
            tbl_Filter_TD_2578037_output.setInt32(r, 5, _ss_hdemo_sk9231_t);
            int32_t _ss_addr_sk9232_t = tbl_SerializeFromObject_TD_3582417_input.getInt32(i, 6);
            tbl_Filter_TD_2578037_output.setInt32(r, 6, _ss_addr_sk9232_t);
            int32_t _ss_store_sk9233_t = tbl_SerializeFromObject_TD_3582417_input.getInt32(i, 7);
            tbl_Filter_TD_2578037_output.setInt32(r, 7, _ss_store_sk9233_t);
            int32_t _ss_promo_sk9234_t = tbl_SerializeFromObject_TD_3582417_input.getInt32(i, 8);
            tbl_Filter_TD_2578037_output.setInt32(r, 8, _ss_promo_sk9234_t);
            int64_t _ss_ticket_number9235L_t = tbl_SerializeFromObject_TD_3582417_input.getInt64(i, 9);
            tbl_Filter_TD_2578037_output.setInt64(r, 9, _ss_ticket_number9235L_t);
            int32_t _ss_quantity9236_t = tbl_SerializeFromObject_TD_3582417_input.getInt32(i, 10);
            tbl_Filter_TD_2578037_output.setInt32(r, 10, _ss_quantity9236_t);
            int64_t _ss_wholesale_cost9237_t = tbl_SerializeFromObject_TD_3582417_input.getInt64(i, 11);
            tbl_Filter_TD_2578037_output.setInt64(r, 11, _ss_wholesale_cost9237_t);
            int64_t _ss_list_price9238_t = tbl_SerializeFromObject_TD_3582417_input.getInt64(i, 12);
            tbl_Filter_TD_2578037_output.setInt64(r, 12, _ss_list_price9238_t);
            int64_t _ss_sales_price9239_t = tbl_SerializeFromObject_TD_3582417_input.getInt64(i, 13);
            tbl_Filter_TD_2578037_output.setInt64(r, 13, _ss_sales_price9239_t);
            int64_t _ss_ext_discount_amt9240_t = tbl_SerializeFromObject_TD_3582417_input.getInt64(i, 14);
            tbl_Filter_TD_2578037_output.setInt64(r, 14, _ss_ext_discount_amt9240_t);
            int64_t _ss_ext_sales_price9241_t = tbl_SerializeFromObject_TD_3582417_input.getInt64(i, 15);
            tbl_Filter_TD_2578037_output.setInt64(r, 15, _ss_ext_sales_price9241_t);
            int64_t _ss_ext_wholesale_cost9242_t = tbl_SerializeFromObject_TD_3582417_input.getInt64(i, 16);
            tbl_Filter_TD_2578037_output.setInt64(r, 16, _ss_ext_wholesale_cost9242_t);
            int64_t _ss_ext_list_price9243_t = tbl_SerializeFromObject_TD_3582417_input.getInt64(i, 17);
            tbl_Filter_TD_2578037_output.setInt64(r, 17, _ss_ext_list_price9243_t);
            int64_t _ss_ext_tax9244_t = tbl_SerializeFromObject_TD_3582417_input.getInt64(i, 18);
            tbl_Filter_TD_2578037_output.setInt64(r, 18, _ss_ext_tax9244_t);
            int64_t _ss_coupon_amt9245_t = tbl_SerializeFromObject_TD_3582417_input.getInt64(i, 19);
            tbl_Filter_TD_2578037_output.setInt64(r, 19, _ss_coupon_amt9245_t);
            int64_t _ss_net_paid9246_t = tbl_SerializeFromObject_TD_3582417_input.getInt64(i, 20);
            tbl_Filter_TD_2578037_output.setInt64(r, 20, _ss_net_paid9246_t);
            int64_t _ss_net_paid_inc_tax9247_t = tbl_SerializeFromObject_TD_3582417_input.getInt64(i, 21);
            tbl_Filter_TD_2578037_output.setInt64(r, 21, _ss_net_paid_inc_tax9247_t);
            int64_t _ss_net_profit9248_t = tbl_SerializeFromObject_TD_3582417_input.getInt64(i, 22);
            tbl_Filter_TD_2578037_output.setInt64(r, 22, _ss_net_profit9248_t);
            r++;
        }
    }
    tbl_Filter_TD_2578037_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2578037_output #Row: " << tbl_Filter_TD_2578037_output.getNumRow() << std::endl;
}

void SW_Filter_TD_2153204(Table &tbl_SerializeFromObject_TD_3666916_input, Table &tbl_Filter_TD_2153204_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_quantity#9213) AND ((ss_quantity#9213 >= 1) AND (ss_quantity#9213 <= 20))))
    // Input: ListBuffer(ss_net_paid#9223, ss_quantity#9213)
    // Output: ListBuffer(ss_net_paid#9223)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_3666916_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_quantity9213 = tbl_SerializeFromObject_TD_3666916_input.getInt32(i, 1);
        if ((_ss_quantity9213!= 0) && ((_ss_quantity9213 >= 1) && (_ss_quantity9213 <= 20))) {
            int64_t _ss_net_paid9223_t = tbl_SerializeFromObject_TD_3666916_input.getInt64(i, 0);
            tbl_Filter_TD_2153204_output.setInt64(r, 0, _ss_net_paid9223_t);
            r++;
        }
    }
    tbl_Filter_TD_2153204_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2153204_output #Row: " << tbl_Filter_TD_2153204_output.getNumRow() << std::endl;
}

void SW_Filter_TD_2332879(Table &tbl_SerializeFromObject_TD_3698144_input, Table &tbl_Filter_TD_2332879_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_quantity#9190) AND ((ss_quantity#9190 >= 1) AND (ss_quantity#9190 <= 20))))
    // Input: ListBuffer(ss_ext_discount_amt#9194, ss_quantity#9190)
    // Output: ListBuffer(ss_ext_discount_amt#9194)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_3698144_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_quantity9190 = tbl_SerializeFromObject_TD_3698144_input.getInt32(i, 1);
        if ((_ss_quantity9190!= 0) && ((_ss_quantity9190 >= 1) && (_ss_quantity9190 <= 20))) {
            int64_t _ss_ext_discount_amt9194_t = tbl_SerializeFromObject_TD_3698144_input.getInt64(i, 0);
            tbl_Filter_TD_2332879_output.setInt64(r, 0, _ss_ext_discount_amt9194_t);
            r++;
        }
    }
    tbl_Filter_TD_2332879_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2332879_output #Row: " << tbl_Filter_TD_2332879_output.getNumRow() << std::endl;
}

void SW_Filter_TD_2674416(Table &tbl_SerializeFromObject_TD_3778761_input, Table &tbl_Filter_TD_2674416_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_quantity#1216) AND ((ss_quantity#1216 >= 1) AND (ss_quantity#1216 <= 20))))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_sold_time_sk#1207, ss_item_sk#1208, ss_customer_sk#1209, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_store_sk#1213, ss_promo_sk#1214, ss_ticket_number#1215L, ss_quantity#1216, ss_wholesale_cost#1217, ss_list_price#1218, ss_sales_price#1219, ss_ext_discount_amt#1220, ss_ext_sales_price#1221, ss_ext_wholesale_cost#1222, ss_ext_list_price#1223, ss_ext_tax#1224, ss_coupon_amt#1225, ss_net_paid#1226, ss_net_paid_inc_tax#1227, ss_net_profit#1228)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_sold_time_sk#1207, ss_item_sk#1208, ss_customer_sk#1209, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_store_sk#1213, ss_promo_sk#1214, ss_ticket_number#1215L, ss_quantity#1216, ss_wholesale_cost#1217, ss_list_price#1218, ss_sales_price#1219, ss_ext_discount_amt#1220, ss_ext_sales_price#1221, ss_ext_wholesale_cost#1222, ss_ext_list_price#1223, ss_ext_tax#1224, ss_coupon_amt#1225, ss_net_paid#1226, ss_net_paid_inc_tax#1227, ss_net_profit#1228)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_3778761_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_quantity1216 = tbl_SerializeFromObject_TD_3778761_input.getInt32(i, 10);
        if ((_ss_quantity1216!= 0) && ((_ss_quantity1216 >= 1) && (_ss_quantity1216 <= 20))) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_3778761_input.getInt32(i, 0);
            tbl_Filter_TD_2674416_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_sold_time_sk1207_t = tbl_SerializeFromObject_TD_3778761_input.getInt32(i, 1);
            tbl_Filter_TD_2674416_output.setInt32(r, 1, _ss_sold_time_sk1207_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_3778761_input.getInt32(i, 2);
            tbl_Filter_TD_2674416_output.setInt32(r, 2, _ss_item_sk1208_t);
            int32_t _ss_customer_sk1209_t = tbl_SerializeFromObject_TD_3778761_input.getInt32(i, 3);
            tbl_Filter_TD_2674416_output.setInt32(r, 3, _ss_customer_sk1209_t);
            int32_t _ss_cdemo_sk1210_t = tbl_SerializeFromObject_TD_3778761_input.getInt32(i, 4);
            tbl_Filter_TD_2674416_output.setInt32(r, 4, _ss_cdemo_sk1210_t);
            int32_t _ss_hdemo_sk1211_t = tbl_SerializeFromObject_TD_3778761_input.getInt32(i, 5);
            tbl_Filter_TD_2674416_output.setInt32(r, 5, _ss_hdemo_sk1211_t);
            int32_t _ss_addr_sk1212_t = tbl_SerializeFromObject_TD_3778761_input.getInt32(i, 6);
            tbl_Filter_TD_2674416_output.setInt32(r, 6, _ss_addr_sk1212_t);
            int32_t _ss_store_sk1213_t = tbl_SerializeFromObject_TD_3778761_input.getInt32(i, 7);
            tbl_Filter_TD_2674416_output.setInt32(r, 7, _ss_store_sk1213_t);
            int32_t _ss_promo_sk1214_t = tbl_SerializeFromObject_TD_3778761_input.getInt32(i, 8);
            tbl_Filter_TD_2674416_output.setInt32(r, 8, _ss_promo_sk1214_t);
            int64_t _ss_ticket_number1215L_t = tbl_SerializeFromObject_TD_3778761_input.getInt64(i, 9);
            tbl_Filter_TD_2674416_output.setInt64(r, 9, _ss_ticket_number1215L_t);
            int32_t _ss_quantity1216_t = tbl_SerializeFromObject_TD_3778761_input.getInt32(i, 10);
            tbl_Filter_TD_2674416_output.setInt32(r, 10, _ss_quantity1216_t);
            int64_t _ss_wholesale_cost1217_t = tbl_SerializeFromObject_TD_3778761_input.getInt64(i, 11);
            tbl_Filter_TD_2674416_output.setInt64(r, 11, _ss_wholesale_cost1217_t);
            int64_t _ss_list_price1218_t = tbl_SerializeFromObject_TD_3778761_input.getInt64(i, 12);
            tbl_Filter_TD_2674416_output.setInt64(r, 12, _ss_list_price1218_t);
            int64_t _ss_sales_price1219_t = tbl_SerializeFromObject_TD_3778761_input.getInt64(i, 13);
            tbl_Filter_TD_2674416_output.setInt64(r, 13, _ss_sales_price1219_t);
            int64_t _ss_ext_discount_amt1220_t = tbl_SerializeFromObject_TD_3778761_input.getInt64(i, 14);
            tbl_Filter_TD_2674416_output.setInt64(r, 14, _ss_ext_discount_amt1220_t);
            int64_t _ss_ext_sales_price1221_t = tbl_SerializeFromObject_TD_3778761_input.getInt64(i, 15);
            tbl_Filter_TD_2674416_output.setInt64(r, 15, _ss_ext_sales_price1221_t);
            int64_t _ss_ext_wholesale_cost1222_t = tbl_SerializeFromObject_TD_3778761_input.getInt64(i, 16);
            tbl_Filter_TD_2674416_output.setInt64(r, 16, _ss_ext_wholesale_cost1222_t);
            int64_t _ss_ext_list_price1223_t = tbl_SerializeFromObject_TD_3778761_input.getInt64(i, 17);
            tbl_Filter_TD_2674416_output.setInt64(r, 17, _ss_ext_list_price1223_t);
            int64_t _ss_ext_tax1224_t = tbl_SerializeFromObject_TD_3778761_input.getInt64(i, 18);
            tbl_Filter_TD_2674416_output.setInt64(r, 18, _ss_ext_tax1224_t);
            int64_t _ss_coupon_amt1225_t = tbl_SerializeFromObject_TD_3778761_input.getInt64(i, 19);
            tbl_Filter_TD_2674416_output.setInt64(r, 19, _ss_coupon_amt1225_t);
            int64_t _ss_net_paid1226_t = tbl_SerializeFromObject_TD_3778761_input.getInt64(i, 20);
            tbl_Filter_TD_2674416_output.setInt64(r, 20, _ss_net_paid1226_t);
            int64_t _ss_net_paid_inc_tax1227_t = tbl_SerializeFromObject_TD_3778761_input.getInt64(i, 21);
            tbl_Filter_TD_2674416_output.setInt64(r, 21, _ss_net_paid_inc_tax1227_t);
            int64_t _ss_net_profit1228_t = tbl_SerializeFromObject_TD_3778761_input.getInt64(i, 22);
            tbl_Filter_TD_2674416_output.setInt64(r, 22, _ss_net_profit1228_t);
            r++;
        }
    }
    tbl_Filter_TD_2674416_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2674416_output #Row: " << tbl_Filter_TD_2674416_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_1807473(Table &tbl_Filter_TD_2736300_output, Table &tbl_Aggregate_TD_1807473_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(cast((avg(UnscaledValue(ss_net_paid#9499)) / 100.0) as decimal(11,6)) AS avg(ss_net_paid)#9179)
    // Input: ListBuffer(ss_net_paid#9499)
    // Output: ListBuffer(avg(ss_net_paid)#9179)
    int64_t avg_0 = 0;
    int nrow1 = tbl_Filter_TD_2736300_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ss_net_paid9499 = tbl_Filter_TD_2736300_output.getInt64(i, 0);
        int64_t _avgss_net_paid9179_avg_0 = _ss_net_paid9499;
        avg_0 = (avg_0 + _avgss_net_paid9179_avg_0);
    }
    int r = 0;
    int64_t _avgss_net_paid9179 = (avg_0 / nrow1 / 100.0);
    tbl_Aggregate_TD_1807473_output.setInt64(r++, 0, _avgss_net_paid9179);
    tbl_Aggregate_TD_1807473_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_1807473_output #Row: " << tbl_Aggregate_TD_1807473_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_137914(Table &tbl_Filter_TD_2480680_output, Table &tbl_Aggregate_TD_137914_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(cast((avg(UnscaledValue(ss_ext_discount_amt#9470)) / 100.0) as decimal(11,6)) AS avg(ss_ext_discount_amt)#9177)
    // Input: ListBuffer(ss_ext_discount_amt#9470)
    // Output: ListBuffer(avg(ss_ext_discount_amt)#9177)
    int64_t avg_0 = 0;
    int nrow1 = tbl_Filter_TD_2480680_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ss_ext_discount_amt9470 = tbl_Filter_TD_2480680_output.getInt64(i, 0);
        int64_t _avgss_ext_discount_amt9177_avg_0 = _ss_ext_discount_amt9470;
        avg_0 = (avg_0 + _avgss_ext_discount_amt9177_avg_0);
    }
    int r = 0;
    int64_t _avgss_ext_discount_amt9177 = (avg_0 / nrow1 / 100.0);
    tbl_Aggregate_TD_137914_output.setInt64(r++, 0, _avgss_ext_discount_amt9177);
    tbl_Aggregate_TD_137914_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_137914_output #Row: " << tbl_Aggregate_TD_137914_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_1879094(Table &tbl_Filter_TD_2144689_output, Table &tbl_Aggregate_TD_1879094_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(count(1) AS count(1)#9175L)
    // Input: ListBuffer(ss_sold_date_sk#9433, ss_sold_time_sk#9434, ss_item_sk#9435, ss_customer_sk#9436, ss_cdemo_sk#9437, ss_hdemo_sk#9438, ss_addr_sk#9439, ss_store_sk#9440, ss_promo_sk#9441, ss_ticket_number#9442L, ss_quantity#9443, ss_wholesale_cost#9444, ss_list_price#9445, ss_sales_price#9446, ss_ext_discount_amt#9447, ss_ext_sales_price#9448, ss_ext_wholesale_cost#9449, ss_ext_list_price#9450, ss_ext_tax#9451, ss_coupon_amt#9452, ss_net_paid#9453, ss_net_paid_inc_tax#9454, ss_net_profit#9455)
    // Output: ListBuffer(count(1)#9175L)
    int64_t count_0 = 0;
    int nrow1 = tbl_Filter_TD_2144689_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk9433 = tbl_Filter_TD_2144689_output.getInt32(i, 0);
        int32_t _ss_sold_time_sk9434 = tbl_Filter_TD_2144689_output.getInt32(i, 1);
        int32_t _ss_item_sk9435 = tbl_Filter_TD_2144689_output.getInt32(i, 2);
        int32_t _ss_customer_sk9436 = tbl_Filter_TD_2144689_output.getInt32(i, 3);
        int32_t _ss_cdemo_sk9437 = tbl_Filter_TD_2144689_output.getInt32(i, 4);
        int32_t _ss_hdemo_sk9438 = tbl_Filter_TD_2144689_output.getInt32(i, 5);
        int32_t _ss_addr_sk9439 = tbl_Filter_TD_2144689_output.getInt32(i, 6);
        int32_t _ss_store_sk9440 = tbl_Filter_TD_2144689_output.getInt32(i, 7);
        int32_t _ss_promo_sk9441 = tbl_Filter_TD_2144689_output.getInt32(i, 8);
        int64_t _ss_ticket_number9442L = tbl_Filter_TD_2144689_output.getInt64(i, 9);
        int32_t _ss_quantity9443 = tbl_Filter_TD_2144689_output.getInt32(i, 10);
        int64_t _ss_wholesale_cost9444 = tbl_Filter_TD_2144689_output.getInt64(i, 11);
        int64_t _ss_list_price9445 = tbl_Filter_TD_2144689_output.getInt64(i, 12);
        int64_t _ss_sales_price9446 = tbl_Filter_TD_2144689_output.getInt64(i, 13);
        int64_t _ss_ext_discount_amt9447 = tbl_Filter_TD_2144689_output.getInt64(i, 14);
        int64_t _ss_ext_sales_price9448 = tbl_Filter_TD_2144689_output.getInt64(i, 15);
        int64_t _ss_ext_wholesale_cost9449 = tbl_Filter_TD_2144689_output.getInt64(i, 16);
        int64_t _ss_ext_list_price9450 = tbl_Filter_TD_2144689_output.getInt64(i, 17);
        int64_t _ss_ext_tax9451 = tbl_Filter_TD_2144689_output.getInt64(i, 18);
        int64_t _ss_coupon_amt9452 = tbl_Filter_TD_2144689_output.getInt64(i, 19);
        int64_t _ss_net_paid9453 = tbl_Filter_TD_2144689_output.getInt64(i, 20);
        int64_t _ss_net_paid_inc_tax9454 = tbl_Filter_TD_2144689_output.getInt64(i, 21);
        int64_t _ss_net_profit9455 = tbl_Filter_TD_2144689_output.getInt64(i, 22);
        int64_t _count19175L_count_0 = 1;
        count_0 += _count19175L_count_0;
    }
    int r = 0;
    int64_t _count19175L = count_0;
    tbl_Aggregate_TD_1879094_output.setInt64(r++, 0, _count19175L);
    tbl_Aggregate_TD_1879094_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_1879094_output #Row: " << tbl_Aggregate_TD_1879094_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_1820383(Table &tbl_Filter_TD_2902889_output, Table &tbl_Aggregate_TD_1820383_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(cast((avg(UnscaledValue(ss_net_paid#9430)) / 100.0) as decimal(11,6)) AS avg(ss_net_paid)#9173)
    // Input: ListBuffer(ss_net_paid#9430)
    // Output: ListBuffer(avg(ss_net_paid)#9173)
    int64_t avg_0 = 0;
    int nrow1 = tbl_Filter_TD_2902889_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ss_net_paid9430 = tbl_Filter_TD_2902889_output.getInt64(i, 0);
        int64_t _avgss_net_paid9173_avg_0 = _ss_net_paid9430;
        avg_0 = (avg_0 + _avgss_net_paid9173_avg_0);
    }
    int r = 0;
    int64_t _avgss_net_paid9173 = (avg_0 / nrow1 / 100.0);
    tbl_Aggregate_TD_1820383_output.setInt64(r++, 0, _avgss_net_paid9173);
    tbl_Aggregate_TD_1820383_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_1820383_output #Row: " << tbl_Aggregate_TD_1820383_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_1658567(Table &tbl_Filter_TD_2839080_output, Table &tbl_Aggregate_TD_1658567_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(cast((avg(UnscaledValue(ss_ext_discount_amt#9401)) / 100.0) as decimal(11,6)) AS avg(ss_ext_discount_amt)#9171)
    // Input: ListBuffer(ss_ext_discount_amt#9401)
    // Output: ListBuffer(avg(ss_ext_discount_amt)#9171)
    int64_t avg_0 = 0;
    int nrow1 = tbl_Filter_TD_2839080_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ss_ext_discount_amt9401 = tbl_Filter_TD_2839080_output.getInt64(i, 0);
        int64_t _avgss_ext_discount_amt9171_avg_0 = _ss_ext_discount_amt9401;
        avg_0 = (avg_0 + _avgss_ext_discount_amt9171_avg_0);
    }
    int r = 0;
    int64_t _avgss_ext_discount_amt9171 = (avg_0 / nrow1 / 100.0);
    tbl_Aggregate_TD_1658567_output.setInt64(r++, 0, _avgss_ext_discount_amt9171);
    tbl_Aggregate_TD_1658567_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_1658567_output #Row: " << tbl_Aggregate_TD_1658567_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_1639105(Table &tbl_Filter_TD_2487201_output, Table &tbl_Aggregate_TD_1639105_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(count(1) AS count(1)#9169L)
    // Input: ListBuffer(ss_sold_date_sk#9364, ss_sold_time_sk#9365, ss_item_sk#9366, ss_customer_sk#9367, ss_cdemo_sk#9368, ss_hdemo_sk#9369, ss_addr_sk#9370, ss_store_sk#9371, ss_promo_sk#9372, ss_ticket_number#9373L, ss_quantity#9374, ss_wholesale_cost#9375, ss_list_price#9376, ss_sales_price#9377, ss_ext_discount_amt#9378, ss_ext_sales_price#9379, ss_ext_wholesale_cost#9380, ss_ext_list_price#9381, ss_ext_tax#9382, ss_coupon_amt#9383, ss_net_paid#9384, ss_net_paid_inc_tax#9385, ss_net_profit#9386)
    // Output: ListBuffer(count(1)#9169L)
    int64_t count_0 = 0;
    int nrow1 = tbl_Filter_TD_2487201_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk9364 = tbl_Filter_TD_2487201_output.getInt32(i, 0);
        int32_t _ss_sold_time_sk9365 = tbl_Filter_TD_2487201_output.getInt32(i, 1);
        int32_t _ss_item_sk9366 = tbl_Filter_TD_2487201_output.getInt32(i, 2);
        int32_t _ss_customer_sk9367 = tbl_Filter_TD_2487201_output.getInt32(i, 3);
        int32_t _ss_cdemo_sk9368 = tbl_Filter_TD_2487201_output.getInt32(i, 4);
        int32_t _ss_hdemo_sk9369 = tbl_Filter_TD_2487201_output.getInt32(i, 5);
        int32_t _ss_addr_sk9370 = tbl_Filter_TD_2487201_output.getInt32(i, 6);
        int32_t _ss_store_sk9371 = tbl_Filter_TD_2487201_output.getInt32(i, 7);
        int32_t _ss_promo_sk9372 = tbl_Filter_TD_2487201_output.getInt32(i, 8);
        int64_t _ss_ticket_number9373L = tbl_Filter_TD_2487201_output.getInt64(i, 9);
        int32_t _ss_quantity9374 = tbl_Filter_TD_2487201_output.getInt32(i, 10);
        int64_t _ss_wholesale_cost9375 = tbl_Filter_TD_2487201_output.getInt64(i, 11);
        int64_t _ss_list_price9376 = tbl_Filter_TD_2487201_output.getInt64(i, 12);
        int64_t _ss_sales_price9377 = tbl_Filter_TD_2487201_output.getInt64(i, 13);
        int64_t _ss_ext_discount_amt9378 = tbl_Filter_TD_2487201_output.getInt64(i, 14);
        int64_t _ss_ext_sales_price9379 = tbl_Filter_TD_2487201_output.getInt64(i, 15);
        int64_t _ss_ext_wholesale_cost9380 = tbl_Filter_TD_2487201_output.getInt64(i, 16);
        int64_t _ss_ext_list_price9381 = tbl_Filter_TD_2487201_output.getInt64(i, 17);
        int64_t _ss_ext_tax9382 = tbl_Filter_TD_2487201_output.getInt64(i, 18);
        int64_t _ss_coupon_amt9383 = tbl_Filter_TD_2487201_output.getInt64(i, 19);
        int64_t _ss_net_paid9384 = tbl_Filter_TD_2487201_output.getInt64(i, 20);
        int64_t _ss_net_paid_inc_tax9385 = tbl_Filter_TD_2487201_output.getInt64(i, 21);
        int64_t _ss_net_profit9386 = tbl_Filter_TD_2487201_output.getInt64(i, 22);
        int64_t _count19169L_count_0 = 1;
        count_0 += _count19169L_count_0;
    }
    int r = 0;
    int64_t _count19169L = count_0;
    tbl_Aggregate_TD_1639105_output.setInt64(r++, 0, _count19169L);
    tbl_Aggregate_TD_1639105_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_1639105_output #Row: " << tbl_Aggregate_TD_1639105_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_1797134(Table &tbl_Filter_TD_2279938_output, Table &tbl_Aggregate_TD_1797134_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(cast((avg(UnscaledValue(ss_net_paid#9361)) / 100.0) as decimal(11,6)) AS avg(ss_net_paid)#9167)
    // Input: ListBuffer(ss_net_paid#9361)
    // Output: ListBuffer(avg(ss_net_paid)#9167)
    int64_t avg_0 = 0;
    int nrow1 = tbl_Filter_TD_2279938_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ss_net_paid9361 = tbl_Filter_TD_2279938_output.getInt64(i, 0);
        int64_t _avgss_net_paid9167_avg_0 = _ss_net_paid9361;
        avg_0 = (avg_0 + _avgss_net_paid9167_avg_0);
    }
    int r = 0;
    int64_t _avgss_net_paid9167 = (avg_0 / nrow1 / 100.0);
    tbl_Aggregate_TD_1797134_output.setInt64(r++, 0, _avgss_net_paid9167);
    tbl_Aggregate_TD_1797134_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_1797134_output #Row: " << tbl_Aggregate_TD_1797134_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_1546826(Table &tbl_Filter_TD_234100_output, Table &tbl_Aggregate_TD_1546826_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(cast((avg(UnscaledValue(ss_ext_discount_amt#9332)) / 100.0) as decimal(11,6)) AS avg(ss_ext_discount_amt)#9165)
    // Input: ListBuffer(ss_ext_discount_amt#9332)
    // Output: ListBuffer(avg(ss_ext_discount_amt)#9165)
    int64_t avg_0 = 0;
    int nrow1 = tbl_Filter_TD_234100_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ss_ext_discount_amt9332 = tbl_Filter_TD_234100_output.getInt64(i, 0);
        int64_t _avgss_ext_discount_amt9165_avg_0 = _ss_ext_discount_amt9332;
        avg_0 = (avg_0 + _avgss_ext_discount_amt9165_avg_0);
    }
    int r = 0;
    int64_t _avgss_ext_discount_amt9165 = (avg_0 / nrow1 / 100.0);
    tbl_Aggregate_TD_1546826_output.setInt64(r++, 0, _avgss_ext_discount_amt9165);
    tbl_Aggregate_TD_1546826_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_1546826_output #Row: " << tbl_Aggregate_TD_1546826_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_1773595(Table &tbl_Filter_TD_2634644_output, Table &tbl_Aggregate_TD_1773595_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(count(1) AS count(1)#9163L)
    // Input: ListBuffer(ss_sold_date_sk#9295, ss_sold_time_sk#9296, ss_item_sk#9297, ss_customer_sk#9298, ss_cdemo_sk#9299, ss_hdemo_sk#9300, ss_addr_sk#9301, ss_store_sk#9302, ss_promo_sk#9303, ss_ticket_number#9304L, ss_quantity#9305, ss_wholesale_cost#9306, ss_list_price#9307, ss_sales_price#9308, ss_ext_discount_amt#9309, ss_ext_sales_price#9310, ss_ext_wholesale_cost#9311, ss_ext_list_price#9312, ss_ext_tax#9313, ss_coupon_amt#9314, ss_net_paid#9315, ss_net_paid_inc_tax#9316, ss_net_profit#9317)
    // Output: ListBuffer(count(1)#9163L)
    int64_t count_0 = 0;
    int nrow1 = tbl_Filter_TD_2634644_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk9295 = tbl_Filter_TD_2634644_output.getInt32(i, 0);
        int32_t _ss_sold_time_sk9296 = tbl_Filter_TD_2634644_output.getInt32(i, 1);
        int32_t _ss_item_sk9297 = tbl_Filter_TD_2634644_output.getInt32(i, 2);
        int32_t _ss_customer_sk9298 = tbl_Filter_TD_2634644_output.getInt32(i, 3);
        int32_t _ss_cdemo_sk9299 = tbl_Filter_TD_2634644_output.getInt32(i, 4);
        int32_t _ss_hdemo_sk9300 = tbl_Filter_TD_2634644_output.getInt32(i, 5);
        int32_t _ss_addr_sk9301 = tbl_Filter_TD_2634644_output.getInt32(i, 6);
        int32_t _ss_store_sk9302 = tbl_Filter_TD_2634644_output.getInt32(i, 7);
        int32_t _ss_promo_sk9303 = tbl_Filter_TD_2634644_output.getInt32(i, 8);
        int64_t _ss_ticket_number9304L = tbl_Filter_TD_2634644_output.getInt64(i, 9);
        int32_t _ss_quantity9305 = tbl_Filter_TD_2634644_output.getInt32(i, 10);
        int64_t _ss_wholesale_cost9306 = tbl_Filter_TD_2634644_output.getInt64(i, 11);
        int64_t _ss_list_price9307 = tbl_Filter_TD_2634644_output.getInt64(i, 12);
        int64_t _ss_sales_price9308 = tbl_Filter_TD_2634644_output.getInt64(i, 13);
        int64_t _ss_ext_discount_amt9309 = tbl_Filter_TD_2634644_output.getInt64(i, 14);
        int64_t _ss_ext_sales_price9310 = tbl_Filter_TD_2634644_output.getInt64(i, 15);
        int64_t _ss_ext_wholesale_cost9311 = tbl_Filter_TD_2634644_output.getInt64(i, 16);
        int64_t _ss_ext_list_price9312 = tbl_Filter_TD_2634644_output.getInt64(i, 17);
        int64_t _ss_ext_tax9313 = tbl_Filter_TD_2634644_output.getInt64(i, 18);
        int64_t _ss_coupon_amt9314 = tbl_Filter_TD_2634644_output.getInt64(i, 19);
        int64_t _ss_net_paid9315 = tbl_Filter_TD_2634644_output.getInt64(i, 20);
        int64_t _ss_net_paid_inc_tax9316 = tbl_Filter_TD_2634644_output.getInt64(i, 21);
        int64_t _ss_net_profit9317 = tbl_Filter_TD_2634644_output.getInt64(i, 22);
        int64_t _count19163L_count_0 = 1;
        count_0 += _count19163L_count_0;
    }
    int r = 0;
    int64_t _count19163L = count_0;
    tbl_Aggregate_TD_1773595_output.setInt64(r++, 0, _count19163L);
    tbl_Aggregate_TD_1773595_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_1773595_output #Row: " << tbl_Aggregate_TD_1773595_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_1688913(Table &tbl_Filter_TD_2457007_output, Table &tbl_Aggregate_TD_1688913_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(cast((avg(UnscaledValue(ss_net_paid#9292)) / 100.0) as decimal(11,6)) AS avg(ss_net_paid)#9161)
    // Input: ListBuffer(ss_net_paid#9292)
    // Output: ListBuffer(avg(ss_net_paid)#9161)
    int64_t avg_0 = 0;
    int nrow1 = tbl_Filter_TD_2457007_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ss_net_paid9292 = tbl_Filter_TD_2457007_output.getInt64(i, 0);
        int64_t _avgss_net_paid9161_avg_0 = _ss_net_paid9292;
        avg_0 = (avg_0 + _avgss_net_paid9161_avg_0);
    }
    int r = 0;
    int64_t _avgss_net_paid9161 = (avg_0 / nrow1 / 100.0);
    tbl_Aggregate_TD_1688913_output.setInt64(r++, 0, _avgss_net_paid9161);
    tbl_Aggregate_TD_1688913_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_1688913_output #Row: " << tbl_Aggregate_TD_1688913_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_1603570(Table &tbl_Filter_TD_2948317_output, Table &tbl_Aggregate_TD_1603570_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(cast((avg(UnscaledValue(ss_ext_discount_amt#9263)) / 100.0) as decimal(11,6)) AS avg(ss_ext_discount_amt)#9159)
    // Input: ListBuffer(ss_ext_discount_amt#9263)
    // Output: ListBuffer(avg(ss_ext_discount_amt)#9159)
    int64_t avg_0 = 0;
    int nrow1 = tbl_Filter_TD_2948317_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ss_ext_discount_amt9263 = tbl_Filter_TD_2948317_output.getInt64(i, 0);
        int64_t _avgss_ext_discount_amt9159_avg_0 = _ss_ext_discount_amt9263;
        avg_0 = (avg_0 + _avgss_ext_discount_amt9159_avg_0);
    }
    int r = 0;
    int64_t _avgss_ext_discount_amt9159 = (avg_0 / nrow1 / 100.0);
    tbl_Aggregate_TD_1603570_output.setInt64(r++, 0, _avgss_ext_discount_amt9159);
    tbl_Aggregate_TD_1603570_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_1603570_output #Row: " << tbl_Aggregate_TD_1603570_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_13942(Table &tbl_Filter_TD_2578037_output, Table &tbl_Aggregate_TD_13942_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(count(1) AS count(1)#9157L)
    // Input: ListBuffer(ss_sold_date_sk#9226, ss_sold_time_sk#9227, ss_item_sk#9228, ss_customer_sk#9229, ss_cdemo_sk#9230, ss_hdemo_sk#9231, ss_addr_sk#9232, ss_store_sk#9233, ss_promo_sk#9234, ss_ticket_number#9235L, ss_quantity#9236, ss_wholesale_cost#9237, ss_list_price#9238, ss_sales_price#9239, ss_ext_discount_amt#9240, ss_ext_sales_price#9241, ss_ext_wholesale_cost#9242, ss_ext_list_price#9243, ss_ext_tax#9244, ss_coupon_amt#9245, ss_net_paid#9246, ss_net_paid_inc_tax#9247, ss_net_profit#9248)
    // Output: ListBuffer(count(1)#9157L)
    int64_t count_0 = 0;
    int nrow1 = tbl_Filter_TD_2578037_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk9226 = tbl_Filter_TD_2578037_output.getInt32(i, 0);
        int32_t _ss_sold_time_sk9227 = tbl_Filter_TD_2578037_output.getInt32(i, 1);
        int32_t _ss_item_sk9228 = tbl_Filter_TD_2578037_output.getInt32(i, 2);
        int32_t _ss_customer_sk9229 = tbl_Filter_TD_2578037_output.getInt32(i, 3);
        int32_t _ss_cdemo_sk9230 = tbl_Filter_TD_2578037_output.getInt32(i, 4);
        int32_t _ss_hdemo_sk9231 = tbl_Filter_TD_2578037_output.getInt32(i, 5);
        int32_t _ss_addr_sk9232 = tbl_Filter_TD_2578037_output.getInt32(i, 6);
        int32_t _ss_store_sk9233 = tbl_Filter_TD_2578037_output.getInt32(i, 7);
        int32_t _ss_promo_sk9234 = tbl_Filter_TD_2578037_output.getInt32(i, 8);
        int64_t _ss_ticket_number9235L = tbl_Filter_TD_2578037_output.getInt64(i, 9);
        int32_t _ss_quantity9236 = tbl_Filter_TD_2578037_output.getInt32(i, 10);
        int64_t _ss_wholesale_cost9237 = tbl_Filter_TD_2578037_output.getInt64(i, 11);
        int64_t _ss_list_price9238 = tbl_Filter_TD_2578037_output.getInt64(i, 12);
        int64_t _ss_sales_price9239 = tbl_Filter_TD_2578037_output.getInt64(i, 13);
        int64_t _ss_ext_discount_amt9240 = tbl_Filter_TD_2578037_output.getInt64(i, 14);
        int64_t _ss_ext_sales_price9241 = tbl_Filter_TD_2578037_output.getInt64(i, 15);
        int64_t _ss_ext_wholesale_cost9242 = tbl_Filter_TD_2578037_output.getInt64(i, 16);
        int64_t _ss_ext_list_price9243 = tbl_Filter_TD_2578037_output.getInt64(i, 17);
        int64_t _ss_ext_tax9244 = tbl_Filter_TD_2578037_output.getInt64(i, 18);
        int64_t _ss_coupon_amt9245 = tbl_Filter_TD_2578037_output.getInt64(i, 19);
        int64_t _ss_net_paid9246 = tbl_Filter_TD_2578037_output.getInt64(i, 20);
        int64_t _ss_net_paid_inc_tax9247 = tbl_Filter_TD_2578037_output.getInt64(i, 21);
        int64_t _ss_net_profit9248 = tbl_Filter_TD_2578037_output.getInt64(i, 22);
        int64_t _count19157L_count_0 = 1;
        count_0 += _count19157L_count_0;
    }
    int r = 0;
    int64_t _count19157L = count_0;
    tbl_Aggregate_TD_13942_output.setInt64(r++, 0, _count19157L);
    tbl_Aggregate_TD_13942_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_13942_output #Row: " << tbl_Aggregate_TD_13942_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_1245632(Table &tbl_Filter_TD_2153204_output, Table &tbl_Aggregate_TD_1245632_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(cast((avg(UnscaledValue(ss_net_paid#9223)) / 100.0) as decimal(11,6)) AS avg(ss_net_paid)#9155)
    // Input: ListBuffer(ss_net_paid#9223)
    // Output: ListBuffer(avg(ss_net_paid)#9155)
    int64_t avg_0 = 0;
    int nrow1 = tbl_Filter_TD_2153204_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ss_net_paid9223 = tbl_Filter_TD_2153204_output.getInt64(i, 0);
        int64_t _avgss_net_paid9155_avg_0 = _ss_net_paid9223;
        avg_0 = (avg_0 + _avgss_net_paid9155_avg_0);
    }
    int r = 0;
    int64_t _avgss_net_paid9155 = (avg_0 / nrow1 / 100.0);
    tbl_Aggregate_TD_1245632_output.setInt64(r++, 0, _avgss_net_paid9155);
    tbl_Aggregate_TD_1245632_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_1245632_output #Row: " << tbl_Aggregate_TD_1245632_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_198396(Table &tbl_Filter_TD_2332879_output, Table &tbl_Aggregate_TD_198396_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(cast((avg(UnscaledValue(ss_ext_discount_amt#9194)) / 100.0) as decimal(11,6)) AS avg(ss_ext_discount_amt)#9153)
    // Input: ListBuffer(ss_ext_discount_amt#9194)
    // Output: ListBuffer(avg(ss_ext_discount_amt)#9153)
    int64_t avg_0 = 0;
    int nrow1 = tbl_Filter_TD_2332879_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ss_ext_discount_amt9194 = tbl_Filter_TD_2332879_output.getInt64(i, 0);
        int64_t _avgss_ext_discount_amt9153_avg_0 = _ss_ext_discount_amt9194;
        avg_0 = (avg_0 + _avgss_ext_discount_amt9153_avg_0);
    }
    int r = 0;
    int64_t _avgss_ext_discount_amt9153 = (avg_0 / nrow1 / 100.0);
    tbl_Aggregate_TD_198396_output.setInt64(r++, 0, _avgss_ext_discount_amt9153);
    tbl_Aggregate_TD_198396_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_198396_output #Row: " << tbl_Aggregate_TD_198396_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_1676151(Table &tbl_Filter_TD_2674416_output, Table &tbl_Aggregate_TD_1676151_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(count(1) AS count(1)#9151L)
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_sold_time_sk#1207, ss_item_sk#1208, ss_customer_sk#1209, ss_cdemo_sk#1210, ss_hdemo_sk#1211, ss_addr_sk#1212, ss_store_sk#1213, ss_promo_sk#1214, ss_ticket_number#1215L, ss_quantity#1216, ss_wholesale_cost#1217, ss_list_price#1218, ss_sales_price#1219, ss_ext_discount_amt#1220, ss_ext_sales_price#1221, ss_ext_wholesale_cost#1222, ss_ext_list_price#1223, ss_ext_tax#1224, ss_coupon_amt#1225, ss_net_paid#1226, ss_net_paid_inc_tax#1227, ss_net_profit#1228)
    // Output: ListBuffer(count(1)#9151L)
    int64_t count_0 = 0;
    int nrow1 = tbl_Filter_TD_2674416_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_2674416_output.getInt32(i, 0);
        int32_t _ss_sold_time_sk1207 = tbl_Filter_TD_2674416_output.getInt32(i, 1);
        int32_t _ss_item_sk1208 = tbl_Filter_TD_2674416_output.getInt32(i, 2);
        int32_t _ss_customer_sk1209 = tbl_Filter_TD_2674416_output.getInt32(i, 3);
        int32_t _ss_cdemo_sk1210 = tbl_Filter_TD_2674416_output.getInt32(i, 4);
        int32_t _ss_hdemo_sk1211 = tbl_Filter_TD_2674416_output.getInt32(i, 5);
        int32_t _ss_addr_sk1212 = tbl_Filter_TD_2674416_output.getInt32(i, 6);
        int32_t _ss_store_sk1213 = tbl_Filter_TD_2674416_output.getInt32(i, 7);
        int32_t _ss_promo_sk1214 = tbl_Filter_TD_2674416_output.getInt32(i, 8);
        int64_t _ss_ticket_number1215L = tbl_Filter_TD_2674416_output.getInt64(i, 9);
        int32_t _ss_quantity1216 = tbl_Filter_TD_2674416_output.getInt32(i, 10);
        int64_t _ss_wholesale_cost1217 = tbl_Filter_TD_2674416_output.getInt64(i, 11);
        int64_t _ss_list_price1218 = tbl_Filter_TD_2674416_output.getInt64(i, 12);
        int64_t _ss_sales_price1219 = tbl_Filter_TD_2674416_output.getInt64(i, 13);
        int64_t _ss_ext_discount_amt1220 = tbl_Filter_TD_2674416_output.getInt64(i, 14);
        int64_t _ss_ext_sales_price1221 = tbl_Filter_TD_2674416_output.getInt64(i, 15);
        int64_t _ss_ext_wholesale_cost1222 = tbl_Filter_TD_2674416_output.getInt64(i, 16);
        int64_t _ss_ext_list_price1223 = tbl_Filter_TD_2674416_output.getInt64(i, 17);
        int64_t _ss_ext_tax1224 = tbl_Filter_TD_2674416_output.getInt64(i, 18);
        int64_t _ss_coupon_amt1225 = tbl_Filter_TD_2674416_output.getInt64(i, 19);
        int64_t _ss_net_paid1226 = tbl_Filter_TD_2674416_output.getInt64(i, 20);
        int64_t _ss_net_paid_inc_tax1227 = tbl_Filter_TD_2674416_output.getInt64(i, 21);
        int64_t _ss_net_profit1228 = tbl_Filter_TD_2674416_output.getInt64(i, 22);
        int64_t _count19151L_count_0 = 1;
        count_0 += _count19151L_count_0;
    }
    int r = 0;
    int64_t _count19151L = count_0;
    tbl_Aggregate_TD_1676151_output.setInt64(r++, 0, _count19151L);
    tbl_Aggregate_TD_1676151_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_1676151_output #Row: " << tbl_Aggregate_TD_1676151_output.getNumRow() << std::endl;
}

void SW_Filter_TD_1155884(Table &tbl_SerializeFromObject_TD_242771_input, Table &tbl_Filter_TD_1155884_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(r_reason_sk#351) AND (r_reason_sk#351 = 1)))
    // Input: ListBuffer(r_reason_sk#351, r_reason_id#352, r_reason_desc#353)
    // Output: ListBuffer(r_reason_sk#351, r_reason_id#352, r_reason_desc#353)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_242771_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _r_reason_sk351 = tbl_SerializeFromObject_TD_242771_input.getInt32(i, 0);
        if ((_r_reason_sk351!= 0) && (_r_reason_sk351 == 1)) {
            int32_t _r_reason_sk351_t = tbl_SerializeFromObject_TD_242771_input.getInt32(i, 0);
            tbl_Filter_TD_1155884_output.setInt32(r, 0, _r_reason_sk351_t);
            std::array<char, TPCDS_READ_MAX + 1> _r_reason_id352_t = tbl_SerializeFromObject_TD_242771_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_1155884_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _r_reason_id352_t);
            std::array<char, TPCDS_READ_MAX + 1> _r_reason_desc353_t = tbl_SerializeFromObject_TD_242771_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_1155884_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _r_reason_desc353_t);
            r++;
        }
    }
    tbl_Filter_TD_1155884_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1155884_output #Row: " << tbl_Filter_TD_1155884_output.getNumRow() << std::endl;
}

void SW_Project_TD_068088(Table &tbl_Filter_TD_1155884_output, Table &tbl_Aggregate_TD_1676151_output, Table &tbl_Aggregate_TD_198396_output, Table &tbl_Aggregate_TD_1245632_output, Table &tbl_Aggregate_TD_13942_output, Table &tbl_Aggregate_TD_1603570_output, Table &tbl_Aggregate_TD_1688913_output, Table &tbl_Aggregate_TD_1773595_output, Table &tbl_Aggregate_TD_1546826_output, Table &tbl_Aggregate_TD_1797134_output, Table &tbl_Aggregate_TD_1639105_output, Table &tbl_Aggregate_TD_1658567_output, Table &tbl_Aggregate_TD_1820383_output, Table &tbl_Aggregate_TD_1879094_output, Table &tbl_Aggregate_TD_137914_output, Table &tbl_Aggregate_TD_1807473_output, Table &tbl_Project_TD_068088_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(CASE WHEN (scalar-subquery#9130 [] > 74129) THEN scalar-subquery#9131 [] ELSE scalar-subquery#9132 [] END AS bucket1#9133, CASE WHEN (scalar-subquery#9134 [] > 122840) THEN scalar-subquery#9135 [] ELSE scalar-subquery#9136 [] END AS bucket2#9137, CASE WHEN (scalar-subquery#9138 [] > 56580) THEN scalar-subquery#9139 [] ELSE scalar-subquery#9140 [] END AS bucket3#9141, CASE WHEN (scalar-subquery#9142 [] > 10097) THEN scalar-subquery#9143 [] ELSE scalar-subquery#9144 [] END AS bucket4#9145, CASE WHEN (scalar-subquery#9146 [] > 165306) THEN scalar-subquery#9147 [] ELSE scalar-subquery#9148 [] END AS bucket5#9149)
    // Input: ListBuffer(r_reason_sk#351, r_reason_id#352, r_reason_desc#353)
    // Output: ListBuffer(bucket1#9133, bucket2#9137, bucket3#9141, bucket4#9145, bucket5#9149)
    int nrow1 = tbl_Filter_TD_1155884_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _r_reason_sk351 = tbl_Filter_TD_1155884_output.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _r_reason_id352 = tbl_Filter_TD_1155884_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _r_reason_desc353 = tbl_Filter_TD_1155884_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        int64_t _count19151L = tbl_Aggregate_TD_1676151_output.getInt64(0, 0);
        int64_t _avgss_ext_discount_amt9153 = tbl_Aggregate_TD_198396_output.getInt64(0, 0);
        int64_t _avgss_net_paid9155 = tbl_Aggregate_TD_1245632_output.getInt64(0, 0);
        int64_t _count19157L = tbl_Aggregate_TD_13942_output.getInt64(0, 0);
        int64_t _avgss_ext_discount_amt9159 = tbl_Aggregate_TD_1603570_output.getInt64(0, 0);
        int64_t _avgss_net_paid9161 = tbl_Aggregate_TD_1688913_output.getInt64(0, 0);
        int64_t _count19163L = tbl_Aggregate_TD_1773595_output.getInt64(0, 0);
        int64_t _avgss_ext_discount_amt9165 = tbl_Aggregate_TD_1546826_output.getInt64(0, 0);
        int64_t _avgss_net_paid9167 = tbl_Aggregate_TD_1797134_output.getInt64(0, 0);
        int64_t _count19169L = tbl_Aggregate_TD_1639105_output.getInt64(0, 0);
        int64_t _avgss_ext_discount_amt9171 = tbl_Aggregate_TD_1658567_output.getInt64(0, 0);
        int64_t _avgss_net_paid9173 = tbl_Aggregate_TD_1820383_output.getInt64(0, 0);
        int64_t _count19175L = tbl_Aggregate_TD_1879094_output.getInt64(0, 0);
        int64_t _avgss_ext_discount_amt9177 = tbl_Aggregate_TD_137914_output.getInt64(0, 0);
        int64_t _avgss_net_paid9179 = tbl_Aggregate_TD_1807473_output.getInt64(0, 0);
        int64_t _bucket19133 = (_count19151L > 74129) ? _avgss_ext_discount_amt9153 : _avgss_net_paid9155;
        tbl_Project_TD_068088_output.setInt64(i, 0, _bucket19133);
        int64_t _bucket29137 = (_count19157L > 122840) ? _avgss_ext_discount_amt9159 : _avgss_net_paid9161;
        tbl_Project_TD_068088_output.setInt64(i, 1, _bucket29137);
        int64_t _bucket39141 = (_count19163L > 56580) ? _avgss_ext_discount_amt9165 : _avgss_net_paid9167;
        tbl_Project_TD_068088_output.setInt64(i, 2, _bucket39141);
        int64_t _bucket49145 = (_count19169L > 10097) ? _avgss_ext_discount_amt9171 : _avgss_net_paid9173;
        tbl_Project_TD_068088_output.setInt64(i, 3, _bucket49145);
        int64_t _bucket59149 = (_count19175L > 165306) ? _avgss_ext_discount_amt9177 : _avgss_net_paid9179;
        tbl_Project_TD_068088_output.setInt64(i, 4, _bucket59149);
    }
    tbl_Project_TD_068088_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_068088_output #Row: " << tbl_Project_TD_068088_output.getNumRow() << std::endl;
}

