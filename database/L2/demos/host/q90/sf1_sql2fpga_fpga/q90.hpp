#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_69504(Table &tbl_SerializeFromObject_TD_7214634_input, Table &tbl_Filter_TD_69504_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(hd_dep_count#3584) AND (hd_dep_count#3584 = 6)) AND isnotnull(hd_demo_sk#3581)))
    // Input: ListBuffer(hd_demo_sk#3581, hd_dep_count#3584)
    // Output: ListBuffer(hd_demo_sk#3581)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7214634_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _hd_dep_count3584 = tbl_SerializeFromObject_TD_7214634_input.getInt32(i, 1);
        int32_t _hd_demo_sk3581 = tbl_SerializeFromObject_TD_7214634_input.getInt32(i, 0);
        if (((_hd_dep_count3584!= 0) && (_hd_dep_count3584 == 6)) && (_hd_demo_sk3581!= 0)) {
            int32_t _hd_demo_sk3581_t = tbl_SerializeFromObject_TD_7214634_input.getInt32(i, 0);
            tbl_Filter_TD_69504_output.setInt32(r, 0, _hd_demo_sk3581_t);
            r++;
        }
    }
    tbl_Filter_TD_69504_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_69504_output #Row: " << tbl_Filter_TD_69504_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6871743(Table &tbl_SerializeFromObject_TD_7681509_input, Table &tbl_Filter_TD_6871743_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_ship_hdemo_sk#3557) AND (isnotnull(ws_sold_time_sk#3548) AND isnotnull(ws_web_page_sk#3559))))
    // Input: ListBuffer(ws_sold_time_sk#3548, ws_ship_hdemo_sk#3557, ws_web_page_sk#3559)
    // Output: ListBuffer(ws_sold_time_sk#3548, ws_ship_hdemo_sk#3557, ws_web_page_sk#3559)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7681509_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_ship_hdemo_sk3557 = tbl_SerializeFromObject_TD_7681509_input.getInt32(i, 1);
        int32_t _ws_sold_time_sk3548 = tbl_SerializeFromObject_TD_7681509_input.getInt32(i, 0);
        int32_t _ws_web_page_sk3559 = tbl_SerializeFromObject_TD_7681509_input.getInt32(i, 2);
        if ((_ws_ship_hdemo_sk3557!= 0) && ((_ws_sold_time_sk3548!= 0) && (_ws_web_page_sk3559!= 0))) {
            int32_t _ws_sold_time_sk3548_t = tbl_SerializeFromObject_TD_7681509_input.getInt32(i, 0);
            tbl_Filter_TD_6871743_output.setInt32(r, 0, _ws_sold_time_sk3548_t);
            int32_t _ws_ship_hdemo_sk3557_t = tbl_SerializeFromObject_TD_7681509_input.getInt32(i, 1);
            tbl_Filter_TD_6871743_output.setInt32(r, 1, _ws_ship_hdemo_sk3557_t);
            int32_t _ws_web_page_sk3559_t = tbl_SerializeFromObject_TD_7681509_input.getInt32(i, 2);
            tbl_Filter_TD_6871743_output.setInt32(r, 2, _ws_web_page_sk3559_t);
            r++;
        }
    }
    tbl_Filter_TD_6871743_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6871743_output #Row: " << tbl_Filter_TD_6871743_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6791015(Table &tbl_SerializeFromObject_TD_7883869_input, Table &tbl_Filter_TD_6791015_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(hd_dep_count#207) AND (hd_dep_count#207 = 6)) AND isnotnull(hd_demo_sk#204)))
    // Input: ListBuffer(hd_demo_sk#204, hd_dep_count#207)
    // Output: ListBuffer(hd_demo_sk#204)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7883869_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _hd_dep_count207 = tbl_SerializeFromObject_TD_7883869_input.getInt32(i, 1);
        int32_t _hd_demo_sk204 = tbl_SerializeFromObject_TD_7883869_input.getInt32(i, 0);
        if (((_hd_dep_count207!= 0) && (_hd_dep_count207 == 6)) && (_hd_demo_sk204!= 0)) {
            int32_t _hd_demo_sk204_t = tbl_SerializeFromObject_TD_7883869_input.getInt32(i, 0);
            tbl_Filter_TD_6791015_output.setInt32(r, 0, _hd_demo_sk204_t);
            r++;
        }
    }
    tbl_Filter_TD_6791015_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6791015_output #Row: " << tbl_Filter_TD_6791015_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6639300(Table &tbl_SerializeFromObject_TD_785125_input, Table &tbl_Filter_TD_6639300_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_ship_hdemo_sk#739) AND (isnotnull(ws_sold_time_sk#730) AND isnotnull(ws_web_page_sk#741))))
    // Input: ListBuffer(ws_sold_time_sk#730, ws_ship_hdemo_sk#739, ws_web_page_sk#741)
    // Output: ListBuffer(ws_sold_time_sk#730, ws_ship_hdemo_sk#739, ws_web_page_sk#741)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_785125_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_ship_hdemo_sk739 = tbl_SerializeFromObject_TD_785125_input.getInt32(i, 1);
        int32_t _ws_sold_time_sk730 = tbl_SerializeFromObject_TD_785125_input.getInt32(i, 0);
        int32_t _ws_web_page_sk741 = tbl_SerializeFromObject_TD_785125_input.getInt32(i, 2);
        if ((_ws_ship_hdemo_sk739!= 0) && ((_ws_sold_time_sk730!= 0) && (_ws_web_page_sk741!= 0))) {
            int32_t _ws_sold_time_sk730_t = tbl_SerializeFromObject_TD_785125_input.getInt32(i, 0);
            tbl_Filter_TD_6639300_output.setInt32(r, 0, _ws_sold_time_sk730_t);
            int32_t _ws_ship_hdemo_sk739_t = tbl_SerializeFromObject_TD_785125_input.getInt32(i, 1);
            tbl_Filter_TD_6639300_output.setInt32(r, 1, _ws_ship_hdemo_sk739_t);
            int32_t _ws_web_page_sk741_t = tbl_SerializeFromObject_TD_785125_input.getInt32(i, 2);
            tbl_Filter_TD_6639300_output.setInt32(r, 2, _ws_web_page_sk741_t);
            r++;
        }
    }
    tbl_Filter_TD_6639300_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6639300_output #Row: " << tbl_Filter_TD_6639300_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5362484(Table &tbl_SerializeFromObject_TD_6428190_input, Table &tbl_Filter_TD_5362484_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(t_hour#3589) AND ((t_hour#3589 >= 19) AND (t_hour#3589 <= 20))) AND isnotnull(t_time_sk#3586)))
    // Input: ListBuffer(t_time_sk#3586, t_hour#3589)
    // Output: ListBuffer(t_time_sk#3586)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6428190_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _t_hour3589 = tbl_SerializeFromObject_TD_6428190_input.getInt32(i, 1);
        int32_t _t_time_sk3586 = tbl_SerializeFromObject_TD_6428190_input.getInt32(i, 0);
        if (((_t_hour3589!= 0) && ((_t_hour3589 >= 19) && (_t_hour3589 <= 20))) && (_t_time_sk3586!= 0)) {
            int32_t _t_time_sk3586_t = tbl_SerializeFromObject_TD_6428190_input.getInt32(i, 0);
            tbl_Filter_TD_5362484_output.setInt32(r, 0, _t_time_sk3586_t);
            r++;
        }
    }
    tbl_Filter_TD_5362484_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5362484_output #Row: " << tbl_Filter_TD_5362484_output.getNumRow() << std::endl;
}


void SW_Filter_TD_5853126(Table &tbl_SerializeFromObject_TD_6903122_input, Table &tbl_Filter_TD_5853126_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(t_hour#468) AND ((t_hour#468 >= 8) AND (t_hour#468 <= 9))) AND isnotnull(t_time_sk#465)))
    // Input: ListBuffer(t_time_sk#465, t_hour#468)
    // Output: ListBuffer(t_time_sk#465)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6903122_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _t_hour468 = tbl_SerializeFromObject_TD_6903122_input.getInt32(i, 1);
        int32_t _t_time_sk465 = tbl_SerializeFromObject_TD_6903122_input.getInt32(i, 0);
        if (((_t_hour468!= 0) && ((_t_hour468 >= 8) && (_t_hour468 <= 9))) && (_t_time_sk465!= 0)) {
            int32_t _t_time_sk465_t = tbl_SerializeFromObject_TD_6903122_input.getInt32(i, 0);
            tbl_Filter_TD_5853126_output.setInt32(r, 0, _t_time_sk465_t);
            r++;
        }
    }
    tbl_Filter_TD_5853126_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5853126_output #Row: " << tbl_Filter_TD_5853126_output.getNumRow() << std::endl;
}


void SW_Filter_TD_4575207(Table &tbl_SerializeFromObject_TD_5457751_input, Table &tbl_Filter_TD_4575207_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(wp_char_count#3606) AND ((wp_char_count#3606 >= 5000) AND (wp_char_count#3606 <= 5200))) AND isnotnull(wp_web_page_sk#3596)))
    // Input: ListBuffer(wp_web_page_sk#3596, wp_char_count#3606)
    // Output: ListBuffer(wp_web_page_sk#3596)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5457751_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _wp_char_count3606 = tbl_SerializeFromObject_TD_5457751_input.getInt32(i, 1);
        int32_t _wp_web_page_sk3596 = tbl_SerializeFromObject_TD_5457751_input.getInt32(i, 0);
        if (((_wp_char_count3606!= 0) && ((_wp_char_count3606 >= 5000) && (_wp_char_count3606 <= 5200))) && (_wp_web_page_sk3596!= 0)) {
            int32_t _wp_web_page_sk3596_t = tbl_SerializeFromObject_TD_5457751_input.getInt32(i, 0);
            tbl_Filter_TD_4575207_output.setInt32(r, 0, _wp_web_page_sk3596_t);
            r++;
        }
    }
    tbl_Filter_TD_4575207_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4575207_output #Row: " << tbl_Filter_TD_4575207_output.getNumRow() << std::endl;
}


void SW_Filter_TD_4964076(Table &tbl_SerializeFromObject_TD_5502004_input, Table &tbl_Filter_TD_4964076_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(wp_char_count#625) AND ((wp_char_count#625 >= 5000) AND (wp_char_count#625 <= 5200))) AND isnotnull(wp_web_page_sk#615)))
    // Input: ListBuffer(wp_web_page_sk#615, wp_char_count#625)
    // Output: ListBuffer(wp_web_page_sk#615)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5502004_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _wp_char_count625 = tbl_SerializeFromObject_TD_5502004_input.getInt32(i, 1);
        int32_t _wp_web_page_sk615 = tbl_SerializeFromObject_TD_5502004_input.getInt32(i, 0);
        if (((_wp_char_count625!= 0) && ((_wp_char_count625 >= 5000) && (_wp_char_count625 <= 5200))) && (_wp_web_page_sk615!= 0)) {
            int32_t _wp_web_page_sk615_t = tbl_SerializeFromObject_TD_5502004_input.getInt32(i, 0);
            tbl_Filter_TD_4964076_output.setInt32(r, 0, _wp_web_page_sk615_t);
            r++;
        }
    }
    tbl_Filter_TD_4964076_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4964076_output #Row: " << tbl_Filter_TD_4964076_output.getNumRow() << std::endl;
}




void SW_Aggregate_TD_233819(Table &tbl_JOIN_INNER_TD_3747960_output, Table &tbl_Aggregate_TD_233819_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(count(1) AS pmc#3545L)
    // Input: ListBuffer(ws_web_page_sk#3559, wp_web_page_sk#3596)
    // Output: ListBuffer(pmc#3545L)
    int64_t count_0 = 0;
    int nrow1 = tbl_JOIN_INNER_TD_3747960_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_web_page_sk3559 = tbl_JOIN_INNER_TD_3747960_output.getInt32(i, 0);
        int32_t _wp_web_page_sk3596 = tbl_JOIN_INNER_TD_3747960_output.getInt32(i, 1);
        int64_t _pmc3545L_count_0 = 1;
        count_0 += _pmc3545L_count_0;
    }
    int r = 0;
    int64_t _pmc3545L = count_0;
    tbl_Aggregate_TD_233819_output.setInt64(r++, 0, _pmc3545L);
    tbl_Aggregate_TD_233819_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_233819_output #Row: " << tbl_Aggregate_TD_233819_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_2774199(Table &tbl_JOIN_INNER_TD_3686188_output, Table &tbl_Aggregate_TD_2774199_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(count(1) AS amc#3544L)
    // Input: ListBuffer(ws_web_page_sk#741, wp_web_page_sk#615)
    // Output: ListBuffer(amc#3544L)
    int64_t count_0 = 0;
    int nrow1 = tbl_JOIN_INNER_TD_3686188_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_web_page_sk741 = tbl_JOIN_INNER_TD_3686188_output.getInt32(i, 0);
        int32_t _wp_web_page_sk615 = tbl_JOIN_INNER_TD_3686188_output.getInt32(i, 1);
        int64_t _amc3544L_count_0 = 1;
        count_0 += _amc3544L_count_0;
    }
    int r = 0;
    int64_t _amc3544L = count_0;
    tbl_Aggregate_TD_2774199_output.setInt64(r++, 0, _amc3544L);
    tbl_Aggregate_TD_2774199_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_2774199_output #Row: " << tbl_Aggregate_TD_2774199_output.getNumRow() << std::endl;
}

void SW_JOIN_CROSS_TD_1827726(Table &tbl_Aggregate_TD_2774199_output, Table &tbl_Aggregate_TD_233819_output, Table &tbl_JOIN_CROSS_TD_1827726_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_CROSS
    // Operation: ListBuffer(JOIN_CROSS)
    // Left Table: ListBuffer(amc#3544L)
    // Right Table: ListBuffer(pmc#3545L)
    // Output Table: ListBuffer(amc#3544L, pmc#3545L)
    int left_nrow = tbl_Aggregate_TD_2774199_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_233819_output.getNumRow();
    long r = 0;
    for (int i = 0; i < left_nrow; i++) {
        for (int j = 0; j < right_nrow; j++) {
            tbl_JOIN_CROSS_TD_1827726_output.setInt64(r, 0, tbl_Aggregate_TD_2774199_output.getInt64(i, 0));
            tbl_JOIN_CROSS_TD_1827726_output.setInt64(r, 1, tbl_Aggregate_TD_233819_output.getInt64(j, 0));
            ++r;
        }
    }
    tbl_JOIN_CROSS_TD_1827726_output.setNumRow(r);
    std::cout << "tbl_JOIN_CROSS_TD_1827726_output #Row: " << tbl_JOIN_CROSS_TD_1827726_output.getNumRow() << std::endl;
}

void SW_Project_TD_0381653(Table &tbl_JOIN_CROSS_TD_1827726_output, Table &tbl_Project_TD_0381653_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(CheckOverflow((promote_precision(cast(amc#3544L as decimal(15,4))) / promote_precision(cast(pmc#3545L as decimal(15,4)))), DecimalType(35,20), true) AS am_pm_ratio#3546)
    // Input: ListBuffer(amc#3544L, pmc#3545L)
    // Output: ListBuffer(am_pm_ratio#3546)
    int nrow1 = tbl_JOIN_CROSS_TD_1827726_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _amc3544L = tbl_JOIN_CROSS_TD_1827726_output.getInt64(i, 0);
        int64_t _pmc3545L = tbl_JOIN_CROSS_TD_1827726_output.getInt64(i, 1);
        int64_t _am_pm_ratio3546 = (_amc3544L / _pmc3545L);
        tbl_Project_TD_0381653_output.setInt64(i, 0, _am_pm_ratio3546);
    }
    tbl_Project_TD_0381653_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_0381653_output #Row: " << tbl_Project_TD_0381653_output.getNumRow() << std::endl;
}

