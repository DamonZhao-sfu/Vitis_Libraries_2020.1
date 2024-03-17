#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_7277885(Table &tbl_SerializeFromObject_TD_8204903_input, Table &tbl_Filter_TD_7277885_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(sr_item_sk#671) AND isnotnull(sr_ticket_number#678L)) AND isnotnull(sr_reason_sk#677)))
    // Input: ListBuffer(sr_item_sk#671, sr_reason_sk#677, sr_ticket_number#678L, sr_return_quantity#679)
    // Output: ListBuffer(sr_item_sk#671, sr_reason_sk#677, sr_ticket_number#678L, sr_return_quantity#679)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8204903_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _sr_item_sk671 = tbl_SerializeFromObject_TD_8204903_input.getInt32(i, 0);
        int64_t _sr_ticket_number678L = tbl_SerializeFromObject_TD_8204903_input.getInt64(i, 2);
        int32_t _sr_reason_sk677 = tbl_SerializeFromObject_TD_8204903_input.getInt32(i, 1);
        if (((_sr_item_sk671!= 0) && (_sr_ticket_number678L!= 0)) && (_sr_reason_sk677!= 0)) {
            int32_t _sr_item_sk671_t = tbl_SerializeFromObject_TD_8204903_input.getInt32(i, 0);
            tbl_Filter_TD_7277885_output.setInt32(r, 0, _sr_item_sk671_t);
            int32_t _sr_reason_sk677_t = tbl_SerializeFromObject_TD_8204903_input.getInt32(i, 1);
            tbl_Filter_TD_7277885_output.setInt32(r, 1, _sr_reason_sk677_t);
            int64_t _sr_ticket_number678L_t = tbl_SerializeFromObject_TD_8204903_input.getInt64(i, 2);
            tbl_Filter_TD_7277885_output.setInt64(r, 2, _sr_ticket_number678L_t);
            int32_t _sr_return_quantity679_t = tbl_SerializeFromObject_TD_8204903_input.getInt32(i, 3);
            tbl_Filter_TD_7277885_output.setInt32(r, 3, _sr_return_quantity679_t);
            r++;
        }
    }
    tbl_Filter_TD_7277885_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7277885_output #Row: " << tbl_Filter_TD_7277885_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6912838(Table &tbl_SerializeFromObject_TD_7394520_input, Table &tbl_Filter_TD_6912838_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(r_reason_desc#353) AND (r_reason_desc#353 = reason 28)) AND isnotnull(r_reason_sk#351)))
    // Input: ListBuffer(r_reason_sk#351, r_reason_desc#353)
    // Output: ListBuffer(r_reason_sk#351)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7394520_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _r_reason_desc353 = tbl_SerializeFromObject_TD_7394520_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _r_reason_sk351 = tbl_SerializeFromObject_TD_7394520_input.getInt32(i, 0);
        if ((_r_reason_desc353.data() != "NULL" && (std::string(_r_reason_desc353.data()) == "reason 28")) && (_r_reason_sk351!= 0)) {
            int32_t _r_reason_sk351_t = tbl_SerializeFromObject_TD_7394520_input.getInt32(i, 0);
            tbl_Filter_TD_6912838_output.setInt32(r, 0, _r_reason_sk351_t);
            r++;
        }
    }
    tbl_Filter_TD_6912838_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6912838_output #Row: " << tbl_Filter_TD_6912838_output.getNumRow() << std::endl;
}



void SW_Project_TD_460116(Table &tbl_JOIN_INNER_TD_5234396_output, Table &tbl_Project_TD_460116_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(CASE WHEN isnotnull(sr_return_quantity#679) THEN CheckOverflow((promote_precision(cast(cast((ss_quantity#1216 - sr_return_quantity#679) as decimal(10,0)) as decimal(12,2))) * promote_precision(cast(ss_sales_price#1219 as decimal(12,2)))), DecimalType(18,2), true) ELSE CheckOverflow((promote_precision(cast(cast(ss_quantity#1216 as decimal(10,0)) as decimal(12,2))) * promote_precision(cast(ss_sales_price#1219 as decimal(12,2)))), DecimalType(18,2), true) END AS act_sales#3544)
    // Input: ListBuffer(ss_customer_sk#1209, sr_return_quantity#679, ss_quantity#1216, ss_sales_price#1219)
    // Output: ListBuffer(ss_customer_sk#1209, act_sales#3544)
    int nrow1 = tbl_JOIN_INNER_TD_5234396_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_5234396_output.getInt32(i, 0);
        int32_t _sr_return_quantity679 = tbl_JOIN_INNER_TD_5234396_output.getInt32(i, 1);
        int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_5234396_output.getInt32(i, 2);
        int64_t _ss_sales_price1219 = tbl_JOIN_INNER_TD_5234396_output.getInt64(i, 3);
        int64_t _act_sales3544 = _sr_return_quantity679 ? ((_ss_quantity1216 - _sr_return_quantity679) * _ss_sales_price1219) : (_ss_quantity1216 * _ss_sales_price1219);
        tbl_Project_TD_460116_output.setInt64(i, 1, _act_sales3544);
        tbl_Project_TD_460116_output.setInt32(i, 0, _ss_customer_sk1209);
    }
    tbl_Project_TD_460116_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_460116_output #Row: " << tbl_Project_TD_460116_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_3854213_consolidate(Table &tbl_Aggregate_TD_3854213_output_preprocess, Table &tbl_Aggregate_TD_3854213_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_3854213_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _ss_customer_sk1209 = tbl_Aggregate_TD_3854213_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_3854213_output.setInt32(r, 0, _ss_customer_sk1209);
        int64_t _sumsales3545 = tbl_Aggregate_TD_3854213_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_3854213_output.setInt64(r, 1, _sumsales3545);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_3854213_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_3854213_output #Row: " << tbl_Aggregate_TD_3854213_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2651440(Table &tbl_Aggregate_TD_3854213_output, Table &tbl_Sort_TD_2651440_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(sumsales#3545 ASC NULLS FIRST, ss_customer_sk#1209 ASC NULLS FIRST)
    // Input: ListBuffer(ss_customer_sk#1209, sumsales#3545)
    // Output: ListBuffer(ss_customer_sk#1209, sumsales#3545)
    struct SW_Sort_TD_2651440Row {
        int32_t _ss_customer_sk1209;
        int64_t _sumsales3545;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2651440Row& a, const SW_Sort_TD_2651440Row& b) const { return 
 (a._sumsales3545 < b._sumsales3545) || 
 ((a._sumsales3545 == b._sumsales3545) && (a._ss_customer_sk1209 < b._ss_customer_sk1209)); 
}
    }SW_Sort_TD_2651440_order; 

    int nrow1 = tbl_Aggregate_TD_3854213_output.getNumRow();
    std::vector<SW_Sort_TD_2651440Row> rows;
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_customer_sk1209 = tbl_Aggregate_TD_3854213_output.getInt32(i, 0);
        int64_t _sumsales3545 = tbl_Aggregate_TD_3854213_output.getInt64(i, 1);
        SW_Sort_TD_2651440Row t = {_ss_customer_sk1209,_sumsales3545};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2651440_order);
    int r = 0;
    for (auto& it : rows) {
        tbl_Sort_TD_2651440_output.setInt32(r, 0, it._ss_customer_sk1209);
        tbl_Sort_TD_2651440_output.setInt64(r, 1, it._sumsales3545);
        ++r;
    }
    tbl_Sort_TD_2651440_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2651440_output #Row: " << tbl_Sort_TD_2651440_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1209798(Table &tbl_Sort_TD_2651440_output, Table &tbl_LocalLimit_TD_1209798_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(ss_customer_sk#1209, sumsales#3545)
    // Output: ListBuffer(ss_customer_sk#1209, sumsales#3545)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        tbl_LocalLimit_TD_1209798_output.setInt32(r, 0, tbl_Sort_TD_2651440_output.getInt32(i, 0));
        tbl_LocalLimit_TD_1209798_output.setInt64(r, 1, tbl_Sort_TD_2651440_output.getInt64(i, 1));
        r++;
    }
    tbl_LocalLimit_TD_1209798_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1209798_output #Row: " << tbl_LocalLimit_TD_1209798_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0183208(Table &tbl_LocalLimit_TD_1209798_output, Table &tbl_GlobalLimit_TD_0183208_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(ss_customer_sk#1209, sumsales#3545)
    // Output: ListBuffer(ss_customer_sk#1209, sumsales#3545)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        tbl_GlobalLimit_TD_0183208_output.setInt32(r, 0, tbl_LocalLimit_TD_1209798_output.getInt32(i, 0));
        tbl_GlobalLimit_TD_0183208_output.setInt64(r, 1, tbl_LocalLimit_TD_1209798_output.getInt64(i, 1));
        r++;
    }
    tbl_GlobalLimit_TD_0183208_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0183208_output #Row: " << tbl_GlobalLimit_TD_0183208_output.getNumRow() << std::endl;
}

