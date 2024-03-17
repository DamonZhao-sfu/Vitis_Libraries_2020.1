#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_9687484(Table &tbl_SerializeFromObject_TD_10681810_input, Table &tbl_Filter_TD_9687484_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_item_sk#1208) AND (isnotnull(ss_sold_date_sk#1206) AND isnotnull(ss_store_sk#1213))))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_store_sk#1213, ss_sales_price#1219)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_store_sk#1213, ss_sales_price#1219)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10681810_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_10681810_input.getInt32(i, 1);
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_10681810_input.getInt32(i, 0);
        int32_t _ss_store_sk1213 = tbl_SerializeFromObject_TD_10681810_input.getInt32(i, 2);
        if ((_ss_item_sk1208!= 0) && ((_ss_sold_date_sk1206!= 0) && (_ss_store_sk1213!= 0))) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_10681810_input.getInt32(i, 0);
            tbl_Filter_TD_9687484_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_10681810_input.getInt32(i, 1);
            tbl_Filter_TD_9687484_output.setInt32(r, 1, _ss_item_sk1208_t);
            int32_t _ss_store_sk1213_t = tbl_SerializeFromObject_TD_10681810_input.getInt32(i, 2);
            tbl_Filter_TD_9687484_output.setInt32(r, 2, _ss_store_sk1213_t);
            int64_t _ss_sales_price1219_t = tbl_SerializeFromObject_TD_10681810_input.getInt64(i, 3);
            tbl_Filter_TD_9687484_output.setInt64(r, 3, _ss_sales_price1219_t);
            r++;
        }
    }
    tbl_Filter_TD_9687484_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9687484_output #Row: " << tbl_Filter_TD_9687484_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9228880(Table &tbl_SerializeFromObject_TD_10947373_input, Table &tbl_Filter_TD_9228880_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((((i_category#240 IN (Books,Children,Electronics) AND i_class#238 IN (personal,portable,reference,self-help)) AND i_brand#236 IN (scholaramalgamalg #14,scholaramalgamalg #7,exportiunivamalg #9,scholaramalgamalg #9)) OR ((i_category#240 IN (Women,Music,Men) AND i_class#238 IN (accessories,classical,fragrances,pants)) AND i_brand#236 IN (amalgimporto #1,edu packscholar #1,exportiimporto #1,importoamalg #1))) AND isnotnull(i_item_sk#228)))
    // Input: ListBuffer(i_item_sk#228, i_manager_id#248, i_category#240, i_class#238, i_brand#236)
    // Output: ListBuffer(i_item_sk#228, i_manager_id#248)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10947373_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category240 = tbl_SerializeFromObject_TD_10947373_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _i_class238 = tbl_SerializeFromObject_TD_10947373_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _i_brand236 = tbl_SerializeFromObject_TD_10947373_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_10947373_input.getInt32(i, 0);
        auto reuse_col_str_714 = std::string(_i_category240.data());
        auto reuse_col_str_223 = std::string(_i_class238.data());
        auto reuse_col_str_458 = std::string(_i_brand236.data());
        auto reuse_col_str_271 = std::string(_i_category240.data());
        auto reuse_col_str_801 = std::string(_i_class238.data());
        auto reuse_col_str_616 = std::string(_i_brand236.data());
        if ((((((reuse_col_str_714 == "Books") || (reuse_col_str_714 == "Children") || (reuse_col_str_714 == "Electronics") || (0)) && ((reuse_col_str_223 == "personal") || (reuse_col_str_223 == "portable") || (reuse_col_str_223 == "reference") || (reuse_col_str_223 == "self-help") || (0))) && ((reuse_col_str_458 == "scholaramalgamalg #14") || (reuse_col_str_458 == "scholaramalgamalg #7") || (reuse_col_str_458 == "exportiunivamalg #9") || (reuse_col_str_458 == "scholaramalgamalg #9") || (0))) || ((((reuse_col_str_271 == "Women") || (reuse_col_str_271 == "Music") || (reuse_col_str_271 == "Men") || (0)) && ((reuse_col_str_801 == "accessories") || (reuse_col_str_801 == "classical") || (reuse_col_str_801 == "fragrances") || (reuse_col_str_801 == "pants") || (0))) && ((reuse_col_str_616 == "amalgimporto #1") || (reuse_col_str_616 == "edu packscholar #1") || (reuse_col_str_616 == "exportiimporto #1") || (reuse_col_str_616 == "importoamalg #1") || (0)))) && (_i_item_sk228!= 0)) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_10947373_input.getInt32(i, 0);
            tbl_Filter_TD_9228880_output.setInt32(r, 0, _i_item_sk228_t);
            int32_t _i_manager_id248_t = tbl_SerializeFromObject_TD_10947373_input.getInt32(i, 1);
            tbl_Filter_TD_9228880_output.setInt32(r, 1, _i_manager_id248_t);
            r++;
        }
    }
    tbl_Filter_TD_9228880_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9228880_output #Row: " << tbl_Filter_TD_9228880_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8214873(Table &tbl_SerializeFromObject_TD_9988462_input, Table &tbl_Filter_TD_8214873_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((d_month_seq#123 INSET 1200, 1201, 1202, 1203, 1204, 1205, 1206, 1207, 1208, 1209, 1210, 1211 AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_moy#128, d_month_seq#123)
    // Output: ListBuffer(d_date_sk#120, d_moy#128)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9988462_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_month_seq123 = tbl_SerializeFromObject_TD_9988462_input.getInt32(i, 2);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_9988462_input.getInt32(i, 0);
        std::vector<int32_t>vec_413 = {
        1210,1208,1209,1204,1201,1203,1207,1200,1211,1206,1202,1205
        };
        bool elementExists = std::find(vec_413.begin(), vec_413.end(),_d_month_seq123) != vec_413.end();
        if (((elementExists) || (0)) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_9988462_input.getInt32(i, 0);
            tbl_Filter_TD_8214873_output.setInt32(r, 0, _d_date_sk120_t);
            int32_t _d_moy128_t = tbl_SerializeFromObject_TD_9988462_input.getInt32(i, 1);
            tbl_Filter_TD_8214873_output.setInt32(r, 1, _d_moy128_t);
            r++;
        }
    }
    tbl_Filter_TD_8214873_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8214873_output #Row: " << tbl_Filter_TD_8214873_output.getNumRow() << std::endl;
}


void SW_Filter_TD_7790009(Table &tbl_SerializeFromObject_TD_8635282_input, Table &tbl_Filter_TD_7790009_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(s_store_sk#378))
    // Input: ListBuffer(s_store_sk#378)
    // Output: ListBuffer(s_store_sk#378)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8635282_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _s_store_sk378 = tbl_SerializeFromObject_TD_8635282_input.getInt32(i, 0);
        if (_s_store_sk378!= 0) {
            int32_t _s_store_sk378_t = tbl_SerializeFromObject_TD_8635282_input.getInt32(i, 0);
            tbl_Filter_TD_7790009_output.setInt32(r, 0, _s_store_sk378_t);
            r++;
        }
    }
    tbl_Filter_TD_7790009_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7790009_output #Row: " << tbl_Filter_TD_7790009_output.getNumRow() << std::endl;
}



void SW_Aggregate_TD_5904487_consolidate(Table &tbl_Aggregate_TD_5904487_output_preprocess, Table &tbl_Aggregate_TD_5904487_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_5904487_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _i_manager_id248 = tbl_Aggregate_TD_5904487_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_5904487_output.setInt32(r, 0, _i_manager_id248);
        int64_t _sum_sales3544 = tbl_Aggregate_TD_5904487_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_5904487_output.setInt64(r, 1, _sum_sales3544);
        int64_t __w03549 = tbl_Aggregate_TD_5904487_output_preprocess.combineInt64(r, 9, 1);
        tbl_Aggregate_TD_5904487_output.setInt64(r, 2, __w03549);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_5904487_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_5904487_output #Row: " << tbl_Aggregate_TD_5904487_output.getNumRow() << std::endl;
}

void SW_Window_TD_4163701(Table &tbl_Aggregate_TD_5904487_output, Table &tbl_Window_TD_4163701_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Window
    // Operation: ListBuffer(avg(_w0#3549) windowspecdefinition(i_manager_id#248, specifiedwindowframe(RowFrame, unboundedpreceding$(), unboundedfollowing$())) AS avg_monthly_sales#3545)
    // Input: ListBuffer(i_manager_id#248, sum_sales#3544, _w0#3549)
    // Output: ListBuffer(i_manager_id#248, sum_sales#3544, _w0#3549, avg_monthly_sales#3545)
    struct SW_Window_TD_4163701Row {
        int32_t _i_manager_id248;
        int64_t _sum_sales3544;
        int64_t __w03549;
    }; 

    int nrow = tbl_Aggregate_TD_5904487_output.getNumRow();
    std::vector<SW_Window_TD_4163701Row> rows0;
    int r = 0;
    for (int i = 0; i < nrow; i++) {
        int32_t _i_manager_id248 = tbl_Aggregate_TD_5904487_output.getInt32(i, 0);
        tbl_Window_TD_4163701_output.setInt32(r, 0,_i_manager_id248);
        int64_t _sum_sales3544 = tbl_Aggregate_TD_5904487_output.getInt64(i, 1);
        tbl_Window_TD_4163701_output.setInt64(r, 1,_sum_sales3544);
        int64_t __w03549 = tbl_Aggregate_TD_5904487_output.getInt64(i, 2);
        tbl_Window_TD_4163701_output.setInt64(r, 2,__w03549);
        r++;
        SW_Window_TD_4163701Row t = {_i_manager_id248,_sum_sales3544,__w03549};
        rows0.push_back(t);
    }
    struct {
        bool operator()(const SW_Window_TD_4163701Row& a, const SW_Window_TD_4163701Row& b) const { return 
(a._i_manager_id248 < b._i_manager_id248); 
}
    }SW_Window_TD_4163701_order0; 

    std::sort(rows0.begin(), rows0.end(), SW_Window_TD_4163701_order0);
    int64_t sum0 = 0;
    int64_t currentRow0 = 0;
    int32_t current_i_manager_id2480 = std::numeric_limits<int32_t>::min();
    for (auto& it : rows0) {
        if (current_i_manager_id2480 != it._i_manager_id248) {
            sum0 = 0;
            currentRow0 = 0;
            current_i_manager_id2480 = it._i_manager_id248;
        }
        sum0 += it.__w03549;
        currentRow0 +=1;
        tbl_Window_TD_4163701_output.setInt64(r, 3, sum0 / currentRow0 );
    }
    tbl_Window_TD_4163701_output.setNumRow(r);
    std::cout << "tbl_Window_TD_4163701_output #Row: " << tbl_Window_TD_4163701_output.getNumRow() << std::endl;
}

void SW_Filter_TD_3970267(Table &tbl_Window_TD_4163701_output, Table &tbl_Filter_TD_3970267_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(avg_monthly_sales#3545) AND ((avg_monthly_sales#3545 > 0.000000) AND (CheckOverflow((promote_precision(abs(CheckOverflow((promote_precision(cast(sum_sales#3544 as decimal(22,6))) - promote_precision(cast(avg_monthly_sales#3545 as decimal(22,6)))), DecimalType(22,6), true), false)) / promote_precision(cast(avg_monthly_sales#3545 as decimal(22,6)))), DecimalType(38,16), true) > 0.1000000000000000))))
    // Input: ListBuffer(i_manager_id#248, sum_sales#3544, _w0#3549, avg_monthly_sales#3545)
    // Output: ListBuffer(i_manager_id#248, sum_sales#3544, avg_monthly_sales#3545)
    int r = 0;
    int nrow1 = tbl_Window_TD_4163701_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _avg_monthly_sales3545 = tbl_Window_TD_4163701_output.getInt64(i, 3);
        int64_t _sum_sales3544 = tbl_Window_TD_4163701_output.getInt64(i, 1);
        if ((_avg_monthly_sales3545!= 0) && ((_avg_monthly_sales3545 > 0.000000) && (_sum_sales3544 > 0.1000000000000000))) {
            int32_t _i_manager_id248_t = tbl_Window_TD_4163701_output.getInt32(i, 0);
            tbl_Filter_TD_3970267_output.setInt32(r, 0, _i_manager_id248_t);
            int64_t _sum_sales3544_t = tbl_Window_TD_4163701_output.getInt64(i, 1);
            tbl_Filter_TD_3970267_output.setInt64(r, 1, _sum_sales3544_t);
            int64_t _avg_monthly_sales3545_t = tbl_Window_TD_4163701_output.getInt64(i, 3);
            tbl_Filter_TD_3970267_output.setInt64(r, 2, _avg_monthly_sales3545_t);
            r++;
        }
    }
    tbl_Filter_TD_3970267_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_3970267_output #Row: " << tbl_Filter_TD_3970267_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2283574(Table &tbl_Filter_TD_3970267_output, Table &tbl_Sort_TD_2283574_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(i_manager_id#248 ASC NULLS FIRST, avg_monthly_sales#3545 ASC NULLS FIRST, sum_sales#3544 ASC NULLS FIRST)
    // Input: ListBuffer(i_manager_id#248, sum_sales#3544, avg_monthly_sales#3545)
    // Output: ListBuffer(i_manager_id#248, sum_sales#3544, avg_monthly_sales#3545)
    struct SW_Sort_TD_2283574Row {
        int32_t _i_manager_id248;
        int64_t _sum_sales3544;
        int64_t _avg_monthly_sales3545;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2283574Row& a, const SW_Sort_TD_2283574Row& b) const { return 
 (a._i_manager_id248 < b._i_manager_id248) || 
 ((a._i_manager_id248 == b._i_manager_id248) && (a._avg_monthly_sales3545 < b._avg_monthly_sales3545)) || 
 ((a._i_manager_id248 == b._i_manager_id248) && (a._avg_monthly_sales3545 == b._avg_monthly_sales3545) && (a._sum_sales3544 < b._sum_sales3544)); 
}
    }SW_Sort_TD_2283574_order; 

    int nrow1 = tbl_Filter_TD_3970267_output.getNumRow();
    std::vector<SW_Sort_TD_2283574Row> rows;
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_manager_id248 = tbl_Filter_TD_3970267_output.getInt32(i, 0);
        int64_t _sum_sales3544 = tbl_Filter_TD_3970267_output.getInt64(i, 1);
        int64_t _avg_monthly_sales3545 = tbl_Filter_TD_3970267_output.getInt64(i, 2);
        SW_Sort_TD_2283574Row t = {_i_manager_id248,_sum_sales3544,_avg_monthly_sales3545};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2283574_order);
    int r = 0;
    for (auto& it : rows) {
        tbl_Sort_TD_2283574_output.setInt32(r, 0, it._i_manager_id248);
        tbl_Sort_TD_2283574_output.setInt64(r, 1, it._sum_sales3544);
        tbl_Sort_TD_2283574_output.setInt64(r, 2, it._avg_monthly_sales3545);
        ++r;
    }
    tbl_Sort_TD_2283574_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2283574_output #Row: " << tbl_Sort_TD_2283574_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1586201(Table &tbl_Sort_TD_2283574_output, Table &tbl_LocalLimit_TD_1586201_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(i_manager_id#248, sum_sales#3544, avg_monthly_sales#3545)
    // Output: ListBuffer(i_manager_id#248, sum_sales#3544, avg_monthly_sales#3545)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        tbl_LocalLimit_TD_1586201_output.setInt32(r, 0, tbl_Sort_TD_2283574_output.getInt32(i, 0));
        tbl_LocalLimit_TD_1586201_output.setInt64(r, 1, tbl_Sort_TD_2283574_output.getInt64(i, 1));
        tbl_LocalLimit_TD_1586201_output.setInt64(r, 2, tbl_Sort_TD_2283574_output.getInt64(i, 2));
        r++;
    }
    tbl_LocalLimit_TD_1586201_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1586201_output #Row: " << tbl_LocalLimit_TD_1586201_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0427754(Table &tbl_LocalLimit_TD_1586201_output, Table &tbl_GlobalLimit_TD_0427754_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(i_manager_id#248, sum_sales#3544, avg_monthly_sales#3545)
    // Output: ListBuffer(i_manager_id#248, sum_sales#3544, avg_monthly_sales#3545)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        tbl_GlobalLimit_TD_0427754_output.setInt32(r, 0, tbl_LocalLimit_TD_1586201_output.getInt32(i, 0));
        tbl_GlobalLimit_TD_0427754_output.setInt64(r, 1, tbl_LocalLimit_TD_1586201_output.getInt64(i, 1));
        tbl_GlobalLimit_TD_0427754_output.setInt64(r, 2, tbl_LocalLimit_TD_1586201_output.getInt64(i, 2));
        r++;
    }
    tbl_GlobalLimit_TD_0427754_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0427754_output #Row: " << tbl_GlobalLimit_TD_0427754_output.getNumRow() << std::endl;
}

