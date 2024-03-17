#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_6125439(Table &tbl_SerializeFromObject_TD_7671180_input, Table &tbl_Filter_TD_6125439_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_date#3584) AND ((d_date#3584 >= 2000-01-27) AND (d_date#3584 <= 2000-04-26))) AND isnotnull(d_date_sk#3582)))
    // Input: ListBuffer(d_date_sk#3582, d_date#3584)
    // Output: ListBuffer(d_date_sk#3582)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7671180_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date3584 = tbl_SerializeFromObject_TD_7671180_input.getInt32(i, 1);
        int32_t _d_date_sk3582 = tbl_SerializeFromObject_TD_7671180_input.getInt32(i, 0);
        if (((_d_date3584!= 0) && ((_d_date3584 >= 20000127) && (_d_date3584 <= 20000426))) && (_d_date_sk3582!= 0)) {
            int32_t _d_date_sk3582_t = tbl_SerializeFromObject_TD_7671180_input.getInt32(i, 0);
            tbl_Filter_TD_6125439_output.setInt32(r, 0, _d_date_sk3582_t);
            r++;
        }
    }
    tbl_Filter_TD_6125439_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6125439_output #Row: " << tbl_Filter_TD_6125439_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6257412(Table &tbl_SerializeFromObject_TD_7346119_input, Table &tbl_Filter_TD_6257412_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_sold_date_sk#3548) AND isnotnull(ws_item_sk#3551)))
    // Input: ListBuffer(ws_sold_date_sk#3548, ws_item_sk#3551, ws_ext_discount_amt#3570)
    // Output: ListBuffer(ws_sold_date_sk#3548, ws_item_sk#3551, ws_ext_discount_amt#3570)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7346119_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_sold_date_sk3548 = tbl_SerializeFromObject_TD_7346119_input.getInt32(i, 0);
        int32_t _ws_item_sk3551 = tbl_SerializeFromObject_TD_7346119_input.getInt32(i, 1);
        if ((_ws_sold_date_sk3548!= 0) && (_ws_item_sk3551!= 0)) {
            int32_t _ws_sold_date_sk3548_t = tbl_SerializeFromObject_TD_7346119_input.getInt32(i, 0);
            tbl_Filter_TD_6257412_output.setInt32(r, 0, _ws_sold_date_sk3548_t);
            int32_t _ws_item_sk3551_t = tbl_SerializeFromObject_TD_7346119_input.getInt32(i, 1);
            tbl_Filter_TD_6257412_output.setInt32(r, 1, _ws_item_sk3551_t);
            int64_t _ws_ext_discount_amt3570_t = tbl_SerializeFromObject_TD_7346119_input.getInt64(i, 2);
            tbl_Filter_TD_6257412_output.setInt64(r, 2, _ws_ext_discount_amt3570_t);
            r++;
        }
    }
    tbl_Filter_TD_6257412_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6257412_output #Row: " << tbl_Filter_TD_6257412_output.getNumRow() << std::endl;
}


void SW_Aggregate_TD_4463533_consolidate(Table &tbl_Aggregate_TD_4463533_output_preprocess, Table &tbl_Aggregate_TD_4463533_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_4463533_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int64_t _avgws_ext_discount_amt3547 = tbl_Aggregate_TD_4463533_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_4463533_output.setInt64(r, 0, _avgws_ext_discount_amt3547);
        int32_t _ws_item_sk3551 = tbl_Aggregate_TD_4463533_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_4463533_output.setInt32(r, 1, _ws_item_sk3551);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_4463533_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_4463533_output #Row: " << tbl_Aggregate_TD_4463533_output.getNumRow() << std::endl;
}

void SW_Filter_TD_4774196(Table &tbl_SerializeFromObject_TD_5497117_input, Table &tbl_Filter_TD_4774196_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(i_manufact_id#241) AND (i_manufact_id#241 = 350)) AND isnotnull(i_item_sk#228)))
    // Input: ListBuffer(i_item_sk#228, i_manufact_id#241)
    // Output: ListBuffer(i_item_sk#228)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5497117_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_manufact_id241 = tbl_SerializeFromObject_TD_5497117_input.getInt32(i, 1);
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_5497117_input.getInt32(i, 0);
        if (((_i_manufact_id241!= 0) && (_i_manufact_id241 == 350)) && (_i_item_sk228!= 0)) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_5497117_input.getInt32(i, 0);
            tbl_Filter_TD_4774196_output.setInt32(r, 0, _i_item_sk228_t);
            r++;
        }
    }
    tbl_Filter_TD_4774196_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4774196_output #Row: " << tbl_Filter_TD_4774196_output.getNumRow() << std::endl;
}

void SW_Filter_TD_477201(Table &tbl_SerializeFromObject_TD_5726134_input, Table &tbl_Filter_TD_477201_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_item_sk#732) AND (isnotnull(ws_ext_discount_amt#751) AND isnotnull(ws_sold_date_sk#729))))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_ext_discount_amt#751)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_ext_discount_amt#751)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5726134_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_item_sk732 = tbl_SerializeFromObject_TD_5726134_input.getInt32(i, 1);
        int64_t _ws_ext_discount_amt751 = tbl_SerializeFromObject_TD_5726134_input.getInt64(i, 2);
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_5726134_input.getInt32(i, 0);
        if ((_ws_item_sk732!= 0) && ((_ws_ext_discount_amt751!= 0) && (_ws_sold_date_sk729!= 0))) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_5726134_input.getInt32(i, 0);
            tbl_Filter_TD_477201_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_item_sk732_t = tbl_SerializeFromObject_TD_5726134_input.getInt32(i, 1);
            tbl_Filter_TD_477201_output.setInt32(r, 1, _ws_item_sk732_t);
            int64_t _ws_ext_discount_amt751_t = tbl_SerializeFromObject_TD_5726134_input.getInt64(i, 2);
            tbl_Filter_TD_477201_output.setInt64(r, 2, _ws_ext_discount_amt751_t);
            r++;
        }
    }
    tbl_Filter_TD_477201_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_477201_output #Row: " << tbl_Filter_TD_477201_output.getNumRow() << std::endl;
}

void SW_Filter_TD_3919242(Table &tbl_Aggregate_TD_4463533_output, Table &tbl_Filter_TD_3919242_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull((1.3 * avg(ws_ext_discount_amt))#3547))
    // Input: ListBuffer((1.3 * avg(ws_ext_discount_amt))#3547, ws_item_sk#3551)
    // Output: ListBuffer((1.3 * avg(ws_ext_discount_amt))#3547, ws_item_sk#3551)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_4463533_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _avgws_ext_discount_amt3547 = tbl_Aggregate_TD_4463533_output.getInt64(i, 0);
        if (_avgws_ext_discount_amt3547!= 0) {
            int64_t _avgws_ext_discount_amt3547_t = tbl_Aggregate_TD_4463533_output.getInt64(i, 0);
            tbl_Filter_TD_3919242_output.setInt64(r, 0, _avgws_ext_discount_amt3547_t);
            int32_t _ws_item_sk3551_t = tbl_Aggregate_TD_4463533_output.getInt32(i, 1);
            tbl_Filter_TD_3919242_output.setInt32(r, 1, _ws_item_sk3551_t);
            r++;
        }
    }
    tbl_Filter_TD_3919242_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_3919242_output #Row: " << tbl_Filter_TD_3919242_output.getNumRow() << std::endl;
}


void SW_Filter_TD_2823943(Table &tbl_SerializeFromObject_TD_3720904_input, Table &tbl_Filter_TD_2823943_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_date#122) AND ((d_date#122 >= 2000-01-27) AND (d_date#122 <= 2000-04-26))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_date#122)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_3720904_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date122 = tbl_SerializeFromObject_TD_3720904_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_3720904_input.getInt32(i, 0);
        if (((_d_date122!= 0) && ((_d_date122 >= 20000127) && (_d_date122 <= 20000426))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_3720904_input.getInt32(i, 0);
            tbl_Filter_TD_2823943_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_2823943_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2823943_output #Row: " << tbl_Filter_TD_2823943_output.getNumRow() << std::endl;
}



void SW_Aggregate_TD_012180(Table &tbl_JOIN_INNER_TD_1785021_output, Table &tbl_Aggregate_TD_012180_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(MakeDecimal(sum(UnscaledValue(ws_ext_discount_amt#751)),17,2) AS Excess Discount Amount#3544)
    // Input: ListBuffer(ws_ext_discount_amt#751)
    // Output: ListBuffer(Excess Discount Amount#3544)
    int64_t sum_0 = 0;
    int nrow1 = tbl_JOIN_INNER_TD_1785021_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ws_ext_discount_amt751 = tbl_JOIN_INNER_TD_1785021_output.getInt64(i, 0);
        int64_t _Amount3544_sum_0 = _ws_ext_discount_amt751;
        sum_0 += _Amount3544_sum_0;
    }
    int r = 0;
    int64_t _Amount3544 = sum_0;
    tbl_Aggregate_TD_012180_output.setInt64(r++, 0, _Amount3544);
    tbl_Aggregate_TD_012180_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_012180_output #Row: " << tbl_Aggregate_TD_012180_output.getNumRow() << std::endl;
}

