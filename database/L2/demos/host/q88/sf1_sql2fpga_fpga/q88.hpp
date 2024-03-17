#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_11501915(Table &tbl_SerializeFromObject_TD_1233021_input, Table &tbl_Filter_TD_11501915_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((((hd_dep_count#3578 = 4) AND (hd_vehicle_count#3579 <= 6)) OR ((hd_dep_count#3578 = 2) AND (hd_vehicle_count#3579 <= 4))) OR ((hd_dep_count#3578 = 0) AND (hd_vehicle_count#3579 <= 2))) AND isnotnull(hd_demo_sk#3575)))
    // Input: ListBuffer(hd_demo_sk#3575, hd_dep_count#3578, hd_vehicle_count#3579)
    // Output: ListBuffer(hd_demo_sk#3575)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1233021_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _hd_dep_count3578 = tbl_SerializeFromObject_TD_1233021_input.getInt32(i, 1);
        int32_t _hd_vehicle_count3579 = tbl_SerializeFromObject_TD_1233021_input.getInt32(i, 2);
        int32_t _hd_demo_sk3575 = tbl_SerializeFromObject_TD_1233021_input.getInt32(i, 0);
        if (((((_hd_dep_count3578 == 4) && (_hd_vehicle_count3579 <= 6)) || ((_hd_dep_count3578 == 2) && (_hd_vehicle_count3579 <= 4))) || ((_hd_dep_count3578 == 0) && (_hd_vehicle_count3579 <= 2))) && (_hd_demo_sk3575!= 0)) {
            int32_t _hd_demo_sk3575_t = tbl_SerializeFromObject_TD_1233021_input.getInt32(i, 0);
            tbl_Filter_TD_11501915_output.setInt32(r, 0, _hd_demo_sk3575_t);
            r++;
        }
    }
    tbl_Filter_TD_11501915_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11501915_output #Row: " << tbl_Filter_TD_11501915_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11494174(Table &tbl_SerializeFromObject_TD_12265143_input, Table &tbl_Filter_TD_11494174_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_hdemo_sk#3557) AND (isnotnull(ss_sold_time_sk#3553) AND isnotnull(ss_store_sk#3559))))
    // Input: ListBuffer(ss_sold_time_sk#3553, ss_hdemo_sk#3557, ss_store_sk#3559)
    // Output: ListBuffer(ss_sold_time_sk#3553, ss_hdemo_sk#3557, ss_store_sk#3559)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12265143_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_hdemo_sk3557 = tbl_SerializeFromObject_TD_12265143_input.getInt32(i, 1);
        int32_t _ss_sold_time_sk3553 = tbl_SerializeFromObject_TD_12265143_input.getInt32(i, 0);
        int32_t _ss_store_sk3559 = tbl_SerializeFromObject_TD_12265143_input.getInt32(i, 2);
        if ((_ss_hdemo_sk3557!= 0) && ((_ss_sold_time_sk3553!= 0) && (_ss_store_sk3559!= 0))) {
            int32_t _ss_sold_time_sk3553_t = tbl_SerializeFromObject_TD_12265143_input.getInt32(i, 0);
            tbl_Filter_TD_11494174_output.setInt32(r, 0, _ss_sold_time_sk3553_t);
            int32_t _ss_hdemo_sk3557_t = tbl_SerializeFromObject_TD_12265143_input.getInt32(i, 1);
            tbl_Filter_TD_11494174_output.setInt32(r, 1, _ss_hdemo_sk3557_t);
            int32_t _ss_store_sk3559_t = tbl_SerializeFromObject_TD_12265143_input.getInt32(i, 2);
            tbl_Filter_TD_11494174_output.setInt32(r, 2, _ss_store_sk3559_t);
            r++;
        }
    }
    tbl_Filter_TD_11494174_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11494174_output #Row: " << tbl_Filter_TD_11494174_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11863624(Table &tbl_SerializeFromObject_TD_12427169_input, Table &tbl_Filter_TD_11863624_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((((hd_dep_count#207 = 4) AND (hd_vehicle_count#208 <= 6)) OR ((hd_dep_count#207 = 2) AND (hd_vehicle_count#208 <= 4))) OR ((hd_dep_count#207 = 0) AND (hd_vehicle_count#208 <= 2))) AND isnotnull(hd_demo_sk#204)))
    // Input: ListBuffer(hd_demo_sk#204, hd_dep_count#207, hd_vehicle_count#208)
    // Output: ListBuffer(hd_demo_sk#204)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12427169_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _hd_dep_count207 = tbl_SerializeFromObject_TD_12427169_input.getInt32(i, 1);
        int32_t _hd_vehicle_count208 = tbl_SerializeFromObject_TD_12427169_input.getInt32(i, 2);
        int32_t _hd_demo_sk204 = tbl_SerializeFromObject_TD_12427169_input.getInt32(i, 0);
        if (((((_hd_dep_count207 == 4) && (_hd_vehicle_count208 <= 6)) || ((_hd_dep_count207 == 2) && (_hd_vehicle_count208 <= 4))) || ((_hd_dep_count207 == 0) && (_hd_vehicle_count208 <= 2))) && (_hd_demo_sk204!= 0)) {
            int32_t _hd_demo_sk204_t = tbl_SerializeFromObject_TD_12427169_input.getInt32(i, 0);
            tbl_Filter_TD_11863624_output.setInt32(r, 0, _hd_demo_sk204_t);
            r++;
        }
    }
    tbl_Filter_TD_11863624_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11863624_output #Row: " << tbl_Filter_TD_11863624_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11825044(Table &tbl_SerializeFromObject_TD_12473315_input, Table &tbl_Filter_TD_11825044_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_hdemo_sk#1211) AND (isnotnull(ss_sold_time_sk#1207) AND isnotnull(ss_store_sk#1213))))
    // Input: ListBuffer(ss_sold_time_sk#1207, ss_hdemo_sk#1211, ss_store_sk#1213)
    // Output: ListBuffer(ss_sold_time_sk#1207, ss_hdemo_sk#1211, ss_store_sk#1213)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12473315_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_hdemo_sk1211 = tbl_SerializeFromObject_TD_12473315_input.getInt32(i, 1);
        int32_t _ss_sold_time_sk1207 = tbl_SerializeFromObject_TD_12473315_input.getInt32(i, 0);
        int32_t _ss_store_sk1213 = tbl_SerializeFromObject_TD_12473315_input.getInt32(i, 2);
        if ((_ss_hdemo_sk1211!= 0) && ((_ss_sold_time_sk1207!= 0) && (_ss_store_sk1213!= 0))) {
            int32_t _ss_sold_time_sk1207_t = tbl_SerializeFromObject_TD_12473315_input.getInt32(i, 0);
            tbl_Filter_TD_11825044_output.setInt32(r, 0, _ss_sold_time_sk1207_t);
            int32_t _ss_hdemo_sk1211_t = tbl_SerializeFromObject_TD_12473315_input.getInt32(i, 1);
            tbl_Filter_TD_11825044_output.setInt32(r, 1, _ss_hdemo_sk1211_t);
            int32_t _ss_store_sk1213_t = tbl_SerializeFromObject_TD_12473315_input.getInt32(i, 2);
            tbl_Filter_TD_11825044_output.setInt32(r, 2, _ss_store_sk1213_t);
            r++;
        }
    }
    tbl_Filter_TD_11825044_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11825044_output #Row: " << tbl_Filter_TD_11825044_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10112030(Table &tbl_SerializeFromObject_TD_11248910_input, Table &tbl_Filter_TD_10112030_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((((hd_dep_count#3645 = 4) AND (hd_vehicle_count#3646 <= 6)) OR ((hd_dep_count#3645 = 2) AND (hd_vehicle_count#3646 <= 4))) OR ((hd_dep_count#3645 = 0) AND (hd_vehicle_count#3646 <= 2))) AND isnotnull(hd_demo_sk#3642)))
    // Input: ListBuffer(hd_demo_sk#3642, hd_dep_count#3645, hd_vehicle_count#3646)
    // Output: ListBuffer(hd_demo_sk#3642)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11248910_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _hd_dep_count3645 = tbl_SerializeFromObject_TD_11248910_input.getInt32(i, 1);
        int32_t _hd_vehicle_count3646 = tbl_SerializeFromObject_TD_11248910_input.getInt32(i, 2);
        int32_t _hd_demo_sk3642 = tbl_SerializeFromObject_TD_11248910_input.getInt32(i, 0);
        if (((((_hd_dep_count3645 == 4) && (_hd_vehicle_count3646 <= 6)) || ((_hd_dep_count3645 == 2) && (_hd_vehicle_count3646 <= 4))) || ((_hd_dep_count3645 == 0) && (_hd_vehicle_count3646 <= 2))) && (_hd_demo_sk3642!= 0)) {
            int32_t _hd_demo_sk3642_t = tbl_SerializeFromObject_TD_11248910_input.getInt32(i, 0);
            tbl_Filter_TD_10112030_output.setInt32(r, 0, _hd_demo_sk3642_t);
            r++;
        }
    }
    tbl_Filter_TD_10112030_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10112030_output #Row: " << tbl_Filter_TD_10112030_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10930230(Table &tbl_SerializeFromObject_TD_11840076_input, Table &tbl_Filter_TD_10930230_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_hdemo_sk#3624) AND (isnotnull(ss_sold_time_sk#3620) AND isnotnull(ss_store_sk#3626))))
    // Input: ListBuffer(ss_sold_time_sk#3620, ss_hdemo_sk#3624, ss_store_sk#3626)
    // Output: ListBuffer(ss_sold_time_sk#3620, ss_hdemo_sk#3624, ss_store_sk#3626)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11840076_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_hdemo_sk3624 = tbl_SerializeFromObject_TD_11840076_input.getInt32(i, 1);
        int32_t _ss_sold_time_sk3620 = tbl_SerializeFromObject_TD_11840076_input.getInt32(i, 0);
        int32_t _ss_store_sk3626 = tbl_SerializeFromObject_TD_11840076_input.getInt32(i, 2);
        if ((_ss_hdemo_sk3624!= 0) && ((_ss_sold_time_sk3620!= 0) && (_ss_store_sk3626!= 0))) {
            int32_t _ss_sold_time_sk3620_t = tbl_SerializeFromObject_TD_11840076_input.getInt32(i, 0);
            tbl_Filter_TD_10930230_output.setInt32(r, 0, _ss_sold_time_sk3620_t);
            int32_t _ss_hdemo_sk3624_t = tbl_SerializeFromObject_TD_11840076_input.getInt32(i, 1);
            tbl_Filter_TD_10930230_output.setInt32(r, 1, _ss_hdemo_sk3624_t);
            int32_t _ss_store_sk3626_t = tbl_SerializeFromObject_TD_11840076_input.getInt32(i, 2);
            tbl_Filter_TD_10930230_output.setInt32(r, 2, _ss_store_sk3626_t);
            r++;
        }
    }
    tbl_Filter_TD_10930230_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10930230_output #Row: " << tbl_Filter_TD_10930230_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10773494(Table &tbl_SerializeFromObject_TD_11646343_input, Table &tbl_Filter_TD_10773494_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(t_hour#3583) AND isnotnull(t_minute#3584)) AND ((t_hour#3583 = 9) AND (t_minute#3584 < 30))) AND isnotnull(t_time_sk#3580)))
    // Input: ListBuffer(t_time_sk#3580, t_hour#3583, t_minute#3584)
    // Output: ListBuffer(t_time_sk#3580)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11646343_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _t_hour3583 = tbl_SerializeFromObject_TD_11646343_input.getInt32(i, 1);
        int32_t _t_minute3584 = tbl_SerializeFromObject_TD_11646343_input.getInt32(i, 2);
        int32_t _t_time_sk3580 = tbl_SerializeFromObject_TD_11646343_input.getInt32(i, 0);
        if ((((_t_hour3583!= 0) && (_t_minute3584!= 0)) && ((_t_hour3583 == 9) && (_t_minute3584 < 30))) && (_t_time_sk3580!= 0)) {
            int32_t _t_time_sk3580_t = tbl_SerializeFromObject_TD_11646343_input.getInt32(i, 0);
            tbl_Filter_TD_10773494_output.setInt32(r, 0, _t_time_sk3580_t);
            r++;
        }
    }
    tbl_Filter_TD_10773494_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10773494_output #Row: " << tbl_Filter_TD_10773494_output.getNumRow() << std::endl;
}


void SW_Filter_TD_10407068(Table &tbl_SerializeFromObject_TD_11139299_input, Table &tbl_Filter_TD_10407068_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(t_hour#468) AND isnotnull(t_minute#469)) AND ((t_hour#468 = 8) AND (t_minute#469 >= 30))) AND isnotnull(t_time_sk#465)))
    // Input: ListBuffer(t_time_sk#465, t_hour#468, t_minute#469)
    // Output: ListBuffer(t_time_sk#465)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11139299_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _t_hour468 = tbl_SerializeFromObject_TD_11139299_input.getInt32(i, 1);
        int32_t _t_minute469 = tbl_SerializeFromObject_TD_11139299_input.getInt32(i, 2);
        int32_t _t_time_sk465 = tbl_SerializeFromObject_TD_11139299_input.getInt32(i, 0);
        if ((((_t_hour468!= 0) && (_t_minute469!= 0)) && ((_t_hour468 == 8) && (_t_minute469 >= 30))) && (_t_time_sk465!= 0)) {
            int32_t _t_time_sk465_t = tbl_SerializeFromObject_TD_11139299_input.getInt32(i, 0);
            tbl_Filter_TD_10407068_output.setInt32(r, 0, _t_time_sk465_t);
            r++;
        }
    }
    tbl_Filter_TD_10407068_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10407068_output #Row: " << tbl_Filter_TD_10407068_output.getNumRow() << std::endl;
}


void SW_Filter_TD_9721109(Table &tbl_SerializeFromObject_TD_10384773_input, Table &tbl_Filter_TD_9721109_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((((hd_dep_count#3712 = 4) AND (hd_vehicle_count#3713 <= 6)) OR ((hd_dep_count#3712 = 2) AND (hd_vehicle_count#3713 <= 4))) OR ((hd_dep_count#3712 = 0) AND (hd_vehicle_count#3713 <= 2))) AND isnotnull(hd_demo_sk#3709)))
    // Input: ListBuffer(hd_demo_sk#3709, hd_dep_count#3712, hd_vehicle_count#3713)
    // Output: ListBuffer(hd_demo_sk#3709)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10384773_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _hd_dep_count3712 = tbl_SerializeFromObject_TD_10384773_input.getInt32(i, 1);
        int32_t _hd_vehicle_count3713 = tbl_SerializeFromObject_TD_10384773_input.getInt32(i, 2);
        int32_t _hd_demo_sk3709 = tbl_SerializeFromObject_TD_10384773_input.getInt32(i, 0);
        if (((((_hd_dep_count3712 == 4) && (_hd_vehicle_count3713 <= 6)) || ((_hd_dep_count3712 == 2) && (_hd_vehicle_count3713 <= 4))) || ((_hd_dep_count3712 == 0) && (_hd_vehicle_count3713 <= 2))) && (_hd_demo_sk3709!= 0)) {
            int32_t _hd_demo_sk3709_t = tbl_SerializeFromObject_TD_10384773_input.getInt32(i, 0);
            tbl_Filter_TD_9721109_output.setInt32(r, 0, _hd_demo_sk3709_t);
            r++;
        }
    }
    tbl_Filter_TD_9721109_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9721109_output #Row: " << tbl_Filter_TD_9721109_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9731454(Table &tbl_SerializeFromObject_TD_1039924_input, Table &tbl_Filter_TD_9731454_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_hdemo_sk#3691) AND (isnotnull(ss_sold_time_sk#3687) AND isnotnull(ss_store_sk#3693))))
    // Input: ListBuffer(ss_sold_time_sk#3687, ss_hdemo_sk#3691, ss_store_sk#3693)
    // Output: ListBuffer(ss_sold_time_sk#3687, ss_hdemo_sk#3691, ss_store_sk#3693)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1039924_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_hdemo_sk3691 = tbl_SerializeFromObject_TD_1039924_input.getInt32(i, 1);
        int32_t _ss_sold_time_sk3687 = tbl_SerializeFromObject_TD_1039924_input.getInt32(i, 0);
        int32_t _ss_store_sk3693 = tbl_SerializeFromObject_TD_1039924_input.getInt32(i, 2);
        if ((_ss_hdemo_sk3691!= 0) && ((_ss_sold_time_sk3687!= 0) && (_ss_store_sk3693!= 0))) {
            int32_t _ss_sold_time_sk3687_t = tbl_SerializeFromObject_TD_1039924_input.getInt32(i, 0);
            tbl_Filter_TD_9731454_output.setInt32(r, 0, _ss_sold_time_sk3687_t);
            int32_t _ss_hdemo_sk3691_t = tbl_SerializeFromObject_TD_1039924_input.getInt32(i, 1);
            tbl_Filter_TD_9731454_output.setInt32(r, 1, _ss_hdemo_sk3691_t);
            int32_t _ss_store_sk3693_t = tbl_SerializeFromObject_TD_1039924_input.getInt32(i, 2);
            tbl_Filter_TD_9731454_output.setInt32(r, 2, _ss_store_sk3693_t);
            r++;
        }
    }
    tbl_Filter_TD_9731454_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9731454_output #Row: " << tbl_Filter_TD_9731454_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9706559(Table &tbl_SerializeFromObject_TD_10560310_input, Table &tbl_Filter_TD_9706559_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(t_hour#3650) AND isnotnull(t_minute#3651)) AND ((t_hour#3650 = 9) AND (t_minute#3651 >= 30))) AND isnotnull(t_time_sk#3647)))
    // Input: ListBuffer(t_time_sk#3647, t_hour#3650, t_minute#3651)
    // Output: ListBuffer(t_time_sk#3647)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10560310_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _t_hour3650 = tbl_SerializeFromObject_TD_10560310_input.getInt32(i, 1);
        int32_t _t_minute3651 = tbl_SerializeFromObject_TD_10560310_input.getInt32(i, 2);
        int32_t _t_time_sk3647 = tbl_SerializeFromObject_TD_10560310_input.getInt32(i, 0);
        if ((((_t_hour3650!= 0) && (_t_minute3651!= 0)) && ((_t_hour3650 == 9) && (_t_minute3651 >= 30))) && (_t_time_sk3647!= 0)) {
            int32_t _t_time_sk3647_t = tbl_SerializeFromObject_TD_10560310_input.getInt32(i, 0);
            tbl_Filter_TD_9706559_output.setInt32(r, 0, _t_time_sk3647_t);
            r++;
        }
    }
    tbl_Filter_TD_9706559_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9706559_output #Row: " << tbl_Filter_TD_9706559_output.getNumRow() << std::endl;
}


void SW_Filter_TD_9704552(Table &tbl_SerializeFromObject_TD_10678969_input, Table &tbl_Filter_TD_9704552_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(s_store_name#3595) AND (s_store_name#3595 = ese)) AND isnotnull(s_store_sk#3590)))
    // Input: ListBuffer(s_store_sk#3590, s_store_name#3595)
    // Output: ListBuffer(s_store_sk#3590)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10678969_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name3595 = tbl_SerializeFromObject_TD_10678969_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _s_store_sk3590 = tbl_SerializeFromObject_TD_10678969_input.getInt32(i, 0);
        if ((_s_store_name3595.data() != "NULL" && (std::string(_s_store_name3595.data()) == "ese")) && (_s_store_sk3590!= 0)) {
            int32_t _s_store_sk3590_t = tbl_SerializeFromObject_TD_10678969_input.getInt32(i, 0);
            tbl_Filter_TD_9704552_output.setInt32(r, 0, _s_store_sk3590_t);
            r++;
        }
    }
    tbl_Filter_TD_9704552_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9704552_output #Row: " << tbl_Filter_TD_9704552_output.getNumRow() << std::endl;
}


void SW_Filter_TD_9319524(Table &tbl_SerializeFromObject_TD_10826019_input, Table &tbl_Filter_TD_9319524_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(s_store_name#383) AND (s_store_name#383 = ese)) AND isnotnull(s_store_sk#378)))
    // Input: ListBuffer(s_store_sk#378, s_store_name#383)
    // Output: ListBuffer(s_store_sk#378)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10826019_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name383 = tbl_SerializeFromObject_TD_10826019_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _s_store_sk378 = tbl_SerializeFromObject_TD_10826019_input.getInt32(i, 0);
        if ((_s_store_name383.data() != "NULL" && (std::string(_s_store_name383.data()) == "ese")) && (_s_store_sk378!= 0)) {
            int32_t _s_store_sk378_t = tbl_SerializeFromObject_TD_10826019_input.getInt32(i, 0);
            tbl_Filter_TD_9319524_output.setInt32(r, 0, _s_store_sk378_t);
            r++;
        }
    }
    tbl_Filter_TD_9319524_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9319524_output #Row: " << tbl_Filter_TD_9319524_output.getNumRow() << std::endl;
}


void SW_Filter_TD_8550963(Table &tbl_SerializeFromObject_TD_9324654_input, Table &tbl_Filter_TD_8550963_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((((hd_dep_count#3779 = 4) AND (hd_vehicle_count#3780 <= 6)) OR ((hd_dep_count#3779 = 2) AND (hd_vehicle_count#3780 <= 4))) OR ((hd_dep_count#3779 = 0) AND (hd_vehicle_count#3780 <= 2))) AND isnotnull(hd_demo_sk#3776)))
    // Input: ListBuffer(hd_demo_sk#3776, hd_dep_count#3779, hd_vehicle_count#3780)
    // Output: ListBuffer(hd_demo_sk#3776)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9324654_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _hd_dep_count3779 = tbl_SerializeFromObject_TD_9324654_input.getInt32(i, 1);
        int32_t _hd_vehicle_count3780 = tbl_SerializeFromObject_TD_9324654_input.getInt32(i, 2);
        int32_t _hd_demo_sk3776 = tbl_SerializeFromObject_TD_9324654_input.getInt32(i, 0);
        if (((((_hd_dep_count3779 == 4) && (_hd_vehicle_count3780 <= 6)) || ((_hd_dep_count3779 == 2) && (_hd_vehicle_count3780 <= 4))) || ((_hd_dep_count3779 == 0) && (_hd_vehicle_count3780 <= 2))) && (_hd_demo_sk3776!= 0)) {
            int32_t _hd_demo_sk3776_t = tbl_SerializeFromObject_TD_9324654_input.getInt32(i, 0);
            tbl_Filter_TD_8550963_output.setInt32(r, 0, _hd_demo_sk3776_t);
            r++;
        }
    }
    tbl_Filter_TD_8550963_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8550963_output #Row: " << tbl_Filter_TD_8550963_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8395884(Table &tbl_SerializeFromObject_TD_910318_input, Table &tbl_Filter_TD_8395884_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_hdemo_sk#3758) AND (isnotnull(ss_sold_time_sk#3754) AND isnotnull(ss_store_sk#3760))))
    // Input: ListBuffer(ss_sold_time_sk#3754, ss_hdemo_sk#3758, ss_store_sk#3760)
    // Output: ListBuffer(ss_sold_time_sk#3754, ss_hdemo_sk#3758, ss_store_sk#3760)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_910318_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_hdemo_sk3758 = tbl_SerializeFromObject_TD_910318_input.getInt32(i, 1);
        int32_t _ss_sold_time_sk3754 = tbl_SerializeFromObject_TD_910318_input.getInt32(i, 0);
        int32_t _ss_store_sk3760 = tbl_SerializeFromObject_TD_910318_input.getInt32(i, 2);
        if ((_ss_hdemo_sk3758!= 0) && ((_ss_sold_time_sk3754!= 0) && (_ss_store_sk3760!= 0))) {
            int32_t _ss_sold_time_sk3754_t = tbl_SerializeFromObject_TD_910318_input.getInt32(i, 0);
            tbl_Filter_TD_8395884_output.setInt32(r, 0, _ss_sold_time_sk3754_t);
            int32_t _ss_hdemo_sk3758_t = tbl_SerializeFromObject_TD_910318_input.getInt32(i, 1);
            tbl_Filter_TD_8395884_output.setInt32(r, 1, _ss_hdemo_sk3758_t);
            int32_t _ss_store_sk3760_t = tbl_SerializeFromObject_TD_910318_input.getInt32(i, 2);
            tbl_Filter_TD_8395884_output.setInt32(r, 2, _ss_store_sk3760_t);
            r++;
        }
    }
    tbl_Filter_TD_8395884_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8395884_output #Row: " << tbl_Filter_TD_8395884_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8123668(Table &tbl_SerializeFromObject_TD_9320282_input, Table &tbl_Filter_TD_8123668_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(t_hour#3717) AND isnotnull(t_minute#3718)) AND ((t_hour#3717 = 10) AND (t_minute#3718 < 30))) AND isnotnull(t_time_sk#3714)))
    // Input: ListBuffer(t_time_sk#3714, t_hour#3717, t_minute#3718)
    // Output: ListBuffer(t_time_sk#3714)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9320282_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _t_hour3717 = tbl_SerializeFromObject_TD_9320282_input.getInt32(i, 1);
        int32_t _t_minute3718 = tbl_SerializeFromObject_TD_9320282_input.getInt32(i, 2);
        int32_t _t_time_sk3714 = tbl_SerializeFromObject_TD_9320282_input.getInt32(i, 0);
        if ((((_t_hour3717!= 0) && (_t_minute3718!= 0)) && ((_t_hour3717 == 10) && (_t_minute3718 < 30))) && (_t_time_sk3714!= 0)) {
            int32_t _t_time_sk3714_t = tbl_SerializeFromObject_TD_9320282_input.getInt32(i, 0);
            tbl_Filter_TD_8123668_output.setInt32(r, 0, _t_time_sk3714_t);
            r++;
        }
    }
    tbl_Filter_TD_8123668_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8123668_output #Row: " << tbl_Filter_TD_8123668_output.getNumRow() << std::endl;
}


void SW_Filter_TD_8558615(Table &tbl_SerializeFromObject_TD_9568378_input, Table &tbl_Filter_TD_8558615_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(s_store_name#3662) AND (s_store_name#3662 = ese)) AND isnotnull(s_store_sk#3657)))
    // Input: ListBuffer(s_store_sk#3657, s_store_name#3662)
    // Output: ListBuffer(s_store_sk#3657)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9568378_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name3662 = tbl_SerializeFromObject_TD_9568378_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _s_store_sk3657 = tbl_SerializeFromObject_TD_9568378_input.getInt32(i, 0);
        if ((_s_store_name3662.data() != "NULL" && (std::string(_s_store_name3662.data()) == "ese")) && (_s_store_sk3657!= 0)) {
            int32_t _s_store_sk3657_t = tbl_SerializeFromObject_TD_9568378_input.getInt32(i, 0);
            tbl_Filter_TD_8558615_output.setInt32(r, 0, _s_store_sk3657_t);
            r++;
        }
    }
    tbl_Filter_TD_8558615_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8558615_output #Row: " << tbl_Filter_TD_8558615_output.getNumRow() << std::endl;
}




void SW_Filter_TD_7643990(Table &tbl_SerializeFromObject_TD_8986814_input, Table &tbl_Filter_TD_7643990_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((((hd_dep_count#3846 = 4) AND (hd_vehicle_count#3847 <= 6)) OR ((hd_dep_count#3846 = 2) AND (hd_vehicle_count#3847 <= 4))) OR ((hd_dep_count#3846 = 0) AND (hd_vehicle_count#3847 <= 2))) AND isnotnull(hd_demo_sk#3843)))
    // Input: ListBuffer(hd_demo_sk#3843, hd_dep_count#3846, hd_vehicle_count#3847)
    // Output: ListBuffer(hd_demo_sk#3843)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8986814_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _hd_dep_count3846 = tbl_SerializeFromObject_TD_8986814_input.getInt32(i, 1);
        int32_t _hd_vehicle_count3847 = tbl_SerializeFromObject_TD_8986814_input.getInt32(i, 2);
        int32_t _hd_demo_sk3843 = tbl_SerializeFromObject_TD_8986814_input.getInt32(i, 0);
        if (((((_hd_dep_count3846 == 4) && (_hd_vehicle_count3847 <= 6)) || ((_hd_dep_count3846 == 2) && (_hd_vehicle_count3847 <= 4))) || ((_hd_dep_count3846 == 0) && (_hd_vehicle_count3847 <= 2))) && (_hd_demo_sk3843!= 0)) {
            int32_t _hd_demo_sk3843_t = tbl_SerializeFromObject_TD_8986814_input.getInt32(i, 0);
            tbl_Filter_TD_7643990_output.setInt32(r, 0, _hd_demo_sk3843_t);
            r++;
        }
    }
    tbl_Filter_TD_7643990_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7643990_output #Row: " << tbl_Filter_TD_7643990_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7710378(Table &tbl_SerializeFromObject_TD_8678517_input, Table &tbl_Filter_TD_7710378_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_hdemo_sk#3825) AND (isnotnull(ss_sold_time_sk#3821) AND isnotnull(ss_store_sk#3827))))
    // Input: ListBuffer(ss_sold_time_sk#3821, ss_hdemo_sk#3825, ss_store_sk#3827)
    // Output: ListBuffer(ss_sold_time_sk#3821, ss_hdemo_sk#3825, ss_store_sk#3827)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8678517_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_hdemo_sk3825 = tbl_SerializeFromObject_TD_8678517_input.getInt32(i, 1);
        int32_t _ss_sold_time_sk3821 = tbl_SerializeFromObject_TD_8678517_input.getInt32(i, 0);
        int32_t _ss_store_sk3827 = tbl_SerializeFromObject_TD_8678517_input.getInt32(i, 2);
        if ((_ss_hdemo_sk3825!= 0) && ((_ss_sold_time_sk3821!= 0) && (_ss_store_sk3827!= 0))) {
            int32_t _ss_sold_time_sk3821_t = tbl_SerializeFromObject_TD_8678517_input.getInt32(i, 0);
            tbl_Filter_TD_7710378_output.setInt32(r, 0, _ss_sold_time_sk3821_t);
            int32_t _ss_hdemo_sk3825_t = tbl_SerializeFromObject_TD_8678517_input.getInt32(i, 1);
            tbl_Filter_TD_7710378_output.setInt32(r, 1, _ss_hdemo_sk3825_t);
            int32_t _ss_store_sk3827_t = tbl_SerializeFromObject_TD_8678517_input.getInt32(i, 2);
            tbl_Filter_TD_7710378_output.setInt32(r, 2, _ss_store_sk3827_t);
            r++;
        }
    }
    tbl_Filter_TD_7710378_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7710378_output #Row: " << tbl_Filter_TD_7710378_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7632249(Table &tbl_SerializeFromObject_TD_8210534_input, Table &tbl_Filter_TD_7632249_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(t_hour#3784) AND isnotnull(t_minute#3785)) AND ((t_hour#3784 = 10) AND (t_minute#3785 >= 30))) AND isnotnull(t_time_sk#3781)))
    // Input: ListBuffer(t_time_sk#3781, t_hour#3784, t_minute#3785)
    // Output: ListBuffer(t_time_sk#3781)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8210534_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _t_hour3784 = tbl_SerializeFromObject_TD_8210534_input.getInt32(i, 1);
        int32_t _t_minute3785 = tbl_SerializeFromObject_TD_8210534_input.getInt32(i, 2);
        int32_t _t_time_sk3781 = tbl_SerializeFromObject_TD_8210534_input.getInt32(i, 0);
        if ((((_t_hour3784!= 0) && (_t_minute3785!= 0)) && ((_t_hour3784 == 10) && (_t_minute3785 >= 30))) && (_t_time_sk3781!= 0)) {
            int32_t _t_time_sk3781_t = tbl_SerializeFromObject_TD_8210534_input.getInt32(i, 0);
            tbl_Filter_TD_7632249_output.setInt32(r, 0, _t_time_sk3781_t);
            r++;
        }
    }
    tbl_Filter_TD_7632249_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7632249_output #Row: " << tbl_Filter_TD_7632249_output.getNumRow() << std::endl;
}


void SW_Filter_TD_725548(Table &tbl_SerializeFromObject_TD_8488467_input, Table &tbl_Filter_TD_725548_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(s_store_name#3729) AND (s_store_name#3729 = ese)) AND isnotnull(s_store_sk#3724)))
    // Input: ListBuffer(s_store_sk#3724, s_store_name#3729)
    // Output: ListBuffer(s_store_sk#3724)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8488467_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name3729 = tbl_SerializeFromObject_TD_8488467_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _s_store_sk3724 = tbl_SerializeFromObject_TD_8488467_input.getInt32(i, 0);
        if ((_s_store_name3729.data() != "NULL" && (std::string(_s_store_name3729.data()) == "ese")) && (_s_store_sk3724!= 0)) {
            int32_t _s_store_sk3724_t = tbl_SerializeFromObject_TD_8488467_input.getInt32(i, 0);
            tbl_Filter_TD_725548_output.setInt32(r, 0, _s_store_sk3724_t);
            r++;
        }
    }
    tbl_Filter_TD_725548_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_725548_output #Row: " << tbl_Filter_TD_725548_output.getNumRow() << std::endl;
}



void SW_Aggregate_TD_7988832(Table &tbl_JOIN_INNER_TD_8393357_output, Table &tbl_Aggregate_TD_7988832_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(count(1) AS h9_to_9_30#3545L)
    // Input: ListBuffer(ss_store_sk#3559, s_store_sk#3590)
    // Output: ListBuffer(h9_to_9_30#3545L)
    int64_t count_0 = 0;
    int nrow1 = tbl_JOIN_INNER_TD_8393357_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_store_sk3559 = tbl_JOIN_INNER_TD_8393357_output.getInt32(i, 0);
        int32_t _s_store_sk3590 = tbl_JOIN_INNER_TD_8393357_output.getInt32(i, 1);
        int64_t _h9_to_9_303545L_count_0 = 1;
        count_0 += _h9_to_9_303545L_count_0;
    }
    int r = 0;
    int64_t _h9_to_9_303545L = count_0;
    tbl_Aggregate_TD_7988832_output.setInt64(r++, 0, _h9_to_9_303545L);
    tbl_Aggregate_TD_7988832_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_7988832_output #Row: " << tbl_Aggregate_TD_7988832_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_7359641(Table &tbl_JOIN_INNER_TD_8444716_output, Table &tbl_Aggregate_TD_7359641_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(count(1) AS h8_30_to_9#3544L)
    // Input: ListBuffer(ss_store_sk#1213, s_store_sk#378)
    // Output: ListBuffer(h8_30_to_9#3544L)
    int64_t count_0 = 0;
    int nrow1 = tbl_JOIN_INNER_TD_8444716_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_8444716_output.getInt32(i, 0);
        int32_t _s_store_sk378 = tbl_JOIN_INNER_TD_8444716_output.getInt32(i, 1);
        int64_t _h8_30_to_93544L_count_0 = 1;
        count_0 += _h8_30_to_93544L_count_0;
    }
    int r = 0;
    int64_t _h8_30_to_93544L = count_0;
    tbl_Aggregate_TD_7359641_output.setInt64(r++, 0, _h8_30_to_93544L);
    tbl_Aggregate_TD_7359641_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_7359641_output #Row: " << tbl_Aggregate_TD_7359641_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6510134(Table &tbl_SerializeFromObject_TD_7430105_input, Table &tbl_Filter_TD_6510134_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((((hd_dep_count#3913 = 4) AND (hd_vehicle_count#3914 <= 6)) OR ((hd_dep_count#3913 = 2) AND (hd_vehicle_count#3914 <= 4))) OR ((hd_dep_count#3913 = 0) AND (hd_vehicle_count#3914 <= 2))) AND isnotnull(hd_demo_sk#3910)))
    // Input: ListBuffer(hd_demo_sk#3910, hd_dep_count#3913, hd_vehicle_count#3914)
    // Output: ListBuffer(hd_demo_sk#3910)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7430105_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _hd_dep_count3913 = tbl_SerializeFromObject_TD_7430105_input.getInt32(i, 1);
        int32_t _hd_vehicle_count3914 = tbl_SerializeFromObject_TD_7430105_input.getInt32(i, 2);
        int32_t _hd_demo_sk3910 = tbl_SerializeFromObject_TD_7430105_input.getInt32(i, 0);
        if (((((_hd_dep_count3913 == 4) && (_hd_vehicle_count3914 <= 6)) || ((_hd_dep_count3913 == 2) && (_hd_vehicle_count3914 <= 4))) || ((_hd_dep_count3913 == 0) && (_hd_vehicle_count3914 <= 2))) && (_hd_demo_sk3910!= 0)) {
            int32_t _hd_demo_sk3910_t = tbl_SerializeFromObject_TD_7430105_input.getInt32(i, 0);
            tbl_Filter_TD_6510134_output.setInt32(r, 0, _hd_demo_sk3910_t);
            r++;
        }
    }
    tbl_Filter_TD_6510134_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6510134_output #Row: " << tbl_Filter_TD_6510134_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6868889(Table &tbl_SerializeFromObject_TD_7705973_input, Table &tbl_Filter_TD_6868889_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_hdemo_sk#3892) AND (isnotnull(ss_sold_time_sk#3888) AND isnotnull(ss_store_sk#3894))))
    // Input: ListBuffer(ss_sold_time_sk#3888, ss_hdemo_sk#3892, ss_store_sk#3894)
    // Output: ListBuffer(ss_sold_time_sk#3888, ss_hdemo_sk#3892, ss_store_sk#3894)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7705973_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_hdemo_sk3892 = tbl_SerializeFromObject_TD_7705973_input.getInt32(i, 1);
        int32_t _ss_sold_time_sk3888 = tbl_SerializeFromObject_TD_7705973_input.getInt32(i, 0);
        int32_t _ss_store_sk3894 = tbl_SerializeFromObject_TD_7705973_input.getInt32(i, 2);
        if ((_ss_hdemo_sk3892!= 0) && ((_ss_sold_time_sk3888!= 0) && (_ss_store_sk3894!= 0))) {
            int32_t _ss_sold_time_sk3888_t = tbl_SerializeFromObject_TD_7705973_input.getInt32(i, 0);
            tbl_Filter_TD_6868889_output.setInt32(r, 0, _ss_sold_time_sk3888_t);
            int32_t _ss_hdemo_sk3892_t = tbl_SerializeFromObject_TD_7705973_input.getInt32(i, 1);
            tbl_Filter_TD_6868889_output.setInt32(r, 1, _ss_hdemo_sk3892_t);
            int32_t _ss_store_sk3894_t = tbl_SerializeFromObject_TD_7705973_input.getInt32(i, 2);
            tbl_Filter_TD_6868889_output.setInt32(r, 2, _ss_store_sk3894_t);
            r++;
        }
    }
    tbl_Filter_TD_6868889_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6868889_output #Row: " << tbl_Filter_TD_6868889_output.getNumRow() << std::endl;
}

void SW_Filter_TD_621706(Table &tbl_SerializeFromObject_TD_7679477_input, Table &tbl_Filter_TD_621706_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(t_hour#3851) AND isnotnull(t_minute#3852)) AND ((t_hour#3851 = 11) AND (t_minute#3852 < 30))) AND isnotnull(t_time_sk#3848)))
    // Input: ListBuffer(t_time_sk#3848, t_hour#3851, t_minute#3852)
    // Output: ListBuffer(t_time_sk#3848)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7679477_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _t_hour3851 = tbl_SerializeFromObject_TD_7679477_input.getInt32(i, 1);
        int32_t _t_minute3852 = tbl_SerializeFromObject_TD_7679477_input.getInt32(i, 2);
        int32_t _t_time_sk3848 = tbl_SerializeFromObject_TD_7679477_input.getInt32(i, 0);
        if ((((_t_hour3851!= 0) && (_t_minute3852!= 0)) && ((_t_hour3851 == 11) && (_t_minute3852 < 30))) && (_t_time_sk3848!= 0)) {
            int32_t _t_time_sk3848_t = tbl_SerializeFromObject_TD_7679477_input.getInt32(i, 0);
            tbl_Filter_TD_621706_output.setInt32(r, 0, _t_time_sk3848_t);
            r++;
        }
    }
    tbl_Filter_TD_621706_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_621706_output #Row: " << tbl_Filter_TD_621706_output.getNumRow() << std::endl;
}


void SW_Filter_TD_6190390(Table &tbl_SerializeFromObject_TD_7674429_input, Table &tbl_Filter_TD_6190390_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(s_store_name#3796) AND (s_store_name#3796 = ese)) AND isnotnull(s_store_sk#3791)))
    // Input: ListBuffer(s_store_sk#3791, s_store_name#3796)
    // Output: ListBuffer(s_store_sk#3791)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7674429_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name3796 = tbl_SerializeFromObject_TD_7674429_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _s_store_sk3791 = tbl_SerializeFromObject_TD_7674429_input.getInt32(i, 0);
        if ((_s_store_name3796.data() != "NULL" && (std::string(_s_store_name3796.data()) == "ese")) && (_s_store_sk3791!= 0)) {
            int32_t _s_store_sk3791_t = tbl_SerializeFromObject_TD_7674429_input.getInt32(i, 0);
            tbl_Filter_TD_6190390_output.setInt32(r, 0, _s_store_sk3791_t);
            r++;
        }
    }
    tbl_Filter_TD_6190390_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6190390_output #Row: " << tbl_Filter_TD_6190390_output.getNumRow() << std::endl;
}



void SW_Aggregate_TD_6953350(Table &tbl_JOIN_INNER_TD_7143737_output, Table &tbl_Aggregate_TD_6953350_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(count(1) AS h9_30_to_10#3546L)
    // Input: ListBuffer(ss_store_sk#3626, s_store_sk#3657)
    // Output: ListBuffer(h9_30_to_10#3546L)
    int64_t count_0 = 0;
    int nrow1 = tbl_JOIN_INNER_TD_7143737_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_store_sk3626 = tbl_JOIN_INNER_TD_7143737_output.getInt32(i, 0);
        int32_t _s_store_sk3657 = tbl_JOIN_INNER_TD_7143737_output.getInt32(i, 1);
        int64_t _h9_30_to_103546L_count_0 = 1;
        count_0 += _h9_30_to_103546L_count_0;
    }
    int r = 0;
    int64_t _h9_30_to_103546L = count_0;
    tbl_Aggregate_TD_6953350_output.setInt64(r++, 0, _h9_30_to_103546L);
    tbl_Aggregate_TD_6953350_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_6953350_output #Row: " << tbl_Aggregate_TD_6953350_output.getNumRow() << std::endl;
}

void SW_JOIN_CROSS_TD_6160501(Table &tbl_Aggregate_TD_7359641_output, Table &tbl_Aggregate_TD_7988832_output, Table &tbl_JOIN_CROSS_TD_6160501_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_CROSS
    // Operation: ListBuffer(JOIN_CROSS)
    // Left Table: ListBuffer(h8_30_to_9#3544L)
    // Right Table: ListBuffer(h9_to_9_30#3545L)
    // Output Table: ListBuffer(h8_30_to_9#3544L, h9_to_9_30#3545L)
    int left_nrow = tbl_Aggregate_TD_7359641_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_7988832_output.getNumRow();
    long r = 0;
    for (int i = 0; i < left_nrow; i++) {
        for (int j = 0; j < right_nrow; j++) {
            tbl_JOIN_CROSS_TD_6160501_output.setInt64(r, 0, tbl_Aggregate_TD_7359641_output.getInt64(i, 0));
            tbl_JOIN_CROSS_TD_6160501_output.setInt64(r, 1, tbl_Aggregate_TD_7988832_output.getInt64(j, 0));
            ++r;
        }
    }
    tbl_JOIN_CROSS_TD_6160501_output.setNumRow(r);
    std::cout << "tbl_JOIN_CROSS_TD_6160501_output #Row: " << tbl_JOIN_CROSS_TD_6160501_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5562669(Table &tbl_SerializeFromObject_TD_6203791_input, Table &tbl_Filter_TD_5562669_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((((hd_dep_count#3980 = 4) AND (hd_vehicle_count#3981 <= 6)) OR ((hd_dep_count#3980 = 2) AND (hd_vehicle_count#3981 <= 4))) OR ((hd_dep_count#3980 = 0) AND (hd_vehicle_count#3981 <= 2))) AND isnotnull(hd_demo_sk#3977)))
    // Input: ListBuffer(hd_demo_sk#3977, hd_dep_count#3980, hd_vehicle_count#3981)
    // Output: ListBuffer(hd_demo_sk#3977)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6203791_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _hd_dep_count3980 = tbl_SerializeFromObject_TD_6203791_input.getInt32(i, 1);
        int32_t _hd_vehicle_count3981 = tbl_SerializeFromObject_TD_6203791_input.getInt32(i, 2);
        int32_t _hd_demo_sk3977 = tbl_SerializeFromObject_TD_6203791_input.getInt32(i, 0);
        if (((((_hd_dep_count3980 == 4) && (_hd_vehicle_count3981 <= 6)) || ((_hd_dep_count3980 == 2) && (_hd_vehicle_count3981 <= 4))) || ((_hd_dep_count3980 == 0) && (_hd_vehicle_count3981 <= 2))) && (_hd_demo_sk3977!= 0)) {
            int32_t _hd_demo_sk3977_t = tbl_SerializeFromObject_TD_6203791_input.getInt32(i, 0);
            tbl_Filter_TD_5562669_output.setInt32(r, 0, _hd_demo_sk3977_t);
            r++;
        }
    }
    tbl_Filter_TD_5562669_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5562669_output #Row: " << tbl_Filter_TD_5562669_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5906846(Table &tbl_SerializeFromObject_TD_681115_input, Table &tbl_Filter_TD_5906846_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_hdemo_sk#3959) AND (isnotnull(ss_sold_time_sk#3955) AND isnotnull(ss_store_sk#3961))))
    // Input: ListBuffer(ss_sold_time_sk#3955, ss_hdemo_sk#3959, ss_store_sk#3961)
    // Output: ListBuffer(ss_sold_time_sk#3955, ss_hdemo_sk#3959, ss_store_sk#3961)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_681115_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_hdemo_sk3959 = tbl_SerializeFromObject_TD_681115_input.getInt32(i, 1);
        int32_t _ss_sold_time_sk3955 = tbl_SerializeFromObject_TD_681115_input.getInt32(i, 0);
        int32_t _ss_store_sk3961 = tbl_SerializeFromObject_TD_681115_input.getInt32(i, 2);
        if ((_ss_hdemo_sk3959!= 0) && ((_ss_sold_time_sk3955!= 0) && (_ss_store_sk3961!= 0))) {
            int32_t _ss_sold_time_sk3955_t = tbl_SerializeFromObject_TD_681115_input.getInt32(i, 0);
            tbl_Filter_TD_5906846_output.setInt32(r, 0, _ss_sold_time_sk3955_t);
            int32_t _ss_hdemo_sk3959_t = tbl_SerializeFromObject_TD_681115_input.getInt32(i, 1);
            tbl_Filter_TD_5906846_output.setInt32(r, 1, _ss_hdemo_sk3959_t);
            int32_t _ss_store_sk3961_t = tbl_SerializeFromObject_TD_681115_input.getInt32(i, 2);
            tbl_Filter_TD_5906846_output.setInt32(r, 2, _ss_store_sk3961_t);
            r++;
        }
    }
    tbl_Filter_TD_5906846_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5906846_output #Row: " << tbl_Filter_TD_5906846_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5944573(Table &tbl_SerializeFromObject_TD_6791061_input, Table &tbl_Filter_TD_5944573_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(t_hour#3918) AND isnotnull(t_minute#3919)) AND ((t_hour#3918 = 11) AND (t_minute#3919 >= 30))) AND isnotnull(t_time_sk#3915)))
    // Input: ListBuffer(t_time_sk#3915, t_hour#3918, t_minute#3919)
    // Output: ListBuffer(t_time_sk#3915)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6791061_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _t_hour3918 = tbl_SerializeFromObject_TD_6791061_input.getInt32(i, 1);
        int32_t _t_minute3919 = tbl_SerializeFromObject_TD_6791061_input.getInt32(i, 2);
        int32_t _t_time_sk3915 = tbl_SerializeFromObject_TD_6791061_input.getInt32(i, 0);
        if ((((_t_hour3918!= 0) && (_t_minute3919!= 0)) && ((_t_hour3918 == 11) && (_t_minute3919 >= 30))) && (_t_time_sk3915!= 0)) {
            int32_t _t_time_sk3915_t = tbl_SerializeFromObject_TD_6791061_input.getInt32(i, 0);
            tbl_Filter_TD_5944573_output.setInt32(r, 0, _t_time_sk3915_t);
            r++;
        }
    }
    tbl_Filter_TD_5944573_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5944573_output #Row: " << tbl_Filter_TD_5944573_output.getNumRow() << std::endl;
}


void SW_Filter_TD_5329556(Table &tbl_SerializeFromObject_TD_6424078_input, Table &tbl_Filter_TD_5329556_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(s_store_name#3863) AND (s_store_name#3863 = ese)) AND isnotnull(s_store_sk#3858)))
    // Input: ListBuffer(s_store_sk#3858, s_store_name#3863)
    // Output: ListBuffer(s_store_sk#3858)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6424078_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name3863 = tbl_SerializeFromObject_TD_6424078_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _s_store_sk3858 = tbl_SerializeFromObject_TD_6424078_input.getInt32(i, 0);
        if ((_s_store_name3863.data() != "NULL" && (std::string(_s_store_name3863.data()) == "ese")) && (_s_store_sk3858!= 0)) {
            int32_t _s_store_sk3858_t = tbl_SerializeFromObject_TD_6424078_input.getInt32(i, 0);
            tbl_Filter_TD_5329556_output.setInt32(r, 0, _s_store_sk3858_t);
            r++;
        }
    }
    tbl_Filter_TD_5329556_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5329556_output #Row: " << tbl_Filter_TD_5329556_output.getNumRow() << std::endl;
}



void SW_Aggregate_TD_5162264(Table &tbl_JOIN_INNER_TD_6313985_output, Table &tbl_Aggregate_TD_5162264_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(count(1) AS h10_to_10_30#3547L)
    // Input: ListBuffer(ss_store_sk#3693, s_store_sk#3724)
    // Output: ListBuffer(h10_to_10_30#3547L)
    int64_t count_0 = 0;
    int nrow1 = tbl_JOIN_INNER_TD_6313985_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_store_sk3693 = tbl_JOIN_INNER_TD_6313985_output.getInt32(i, 0);
        int32_t _s_store_sk3724 = tbl_JOIN_INNER_TD_6313985_output.getInt32(i, 1);
        int64_t _h10_to_10_303547L_count_0 = 1;
        count_0 += _h10_to_10_303547L_count_0;
    }
    int r = 0;
    int64_t _h10_to_10_303547L = count_0;
    tbl_Aggregate_TD_5162264_output.setInt64(r++, 0, _h10_to_10_303547L);
    tbl_Aggregate_TD_5162264_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_5162264_output #Row: " << tbl_Aggregate_TD_5162264_output.getNumRow() << std::endl;
}

void SW_JOIN_CROSS_TD_5759888(Table &tbl_JOIN_CROSS_TD_6160501_output, Table &tbl_Aggregate_TD_6953350_output, Table &tbl_JOIN_CROSS_TD_5759888_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_CROSS
    // Operation: ListBuffer(JOIN_CROSS)
    // Left Table: ListBuffer(h8_30_to_9#3544L, h9_to_9_30#3545L)
    // Right Table: ListBuffer(h9_30_to_10#3546L)
    // Output Table: ListBuffer(h8_30_to_9#3544L, h9_to_9_30#3545L, h9_30_to_10#3546L)
    int left_nrow = tbl_JOIN_CROSS_TD_6160501_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_6953350_output.getNumRow();
    long r = 0;
    for (int i = 0; i < left_nrow; i++) {
        for (int j = 0; j < right_nrow; j++) {
            tbl_JOIN_CROSS_TD_5759888_output.setInt64(r, 0, tbl_JOIN_CROSS_TD_6160501_output.getInt64(i, 0));
            tbl_JOIN_CROSS_TD_5759888_output.setInt64(r, 1, tbl_JOIN_CROSS_TD_6160501_output.getInt64(i, 1));
            tbl_JOIN_CROSS_TD_5759888_output.setInt64(r, 2, tbl_Aggregate_TD_6953350_output.getInt64(j, 0));
            ++r;
        }
    }
    tbl_JOIN_CROSS_TD_5759888_output.setNumRow(r);
    std::cout << "tbl_JOIN_CROSS_TD_5759888_output #Row: " << tbl_JOIN_CROSS_TD_5759888_output.getNumRow() << std::endl;
}

void SW_Filter_TD_4107367(Table &tbl_SerializeFromObject_TD_5555205_input, Table &tbl_Filter_TD_4107367_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(t_hour#3985) AND isnotnull(t_minute#3986)) AND ((t_hour#3985 = 12) AND (t_minute#3986 < 30))) AND isnotnull(t_time_sk#3982)))
    // Input: ListBuffer(t_time_sk#3982, t_hour#3985, t_minute#3986)
    // Output: ListBuffer(t_time_sk#3982)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5555205_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _t_hour3985 = tbl_SerializeFromObject_TD_5555205_input.getInt32(i, 1);
        int32_t _t_minute3986 = tbl_SerializeFromObject_TD_5555205_input.getInt32(i, 2);
        int32_t _t_time_sk3982 = tbl_SerializeFromObject_TD_5555205_input.getInt32(i, 0);
        if ((((_t_hour3985!= 0) && (_t_minute3986!= 0)) && ((_t_hour3985 == 12) && (_t_minute3986 < 30))) && (_t_time_sk3982!= 0)) {
            int32_t _t_time_sk3982_t = tbl_SerializeFromObject_TD_5555205_input.getInt32(i, 0);
            tbl_Filter_TD_4107367_output.setInt32(r, 0, _t_time_sk3982_t);
            r++;
        }
    }
    tbl_Filter_TD_4107367_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4107367_output #Row: " << tbl_Filter_TD_4107367_output.getNumRow() << std::endl;
}


void SW_Filter_TD_4532889(Table &tbl_SerializeFromObject_TD_5893686_input, Table &tbl_Filter_TD_4532889_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(s_store_name#3930) AND (s_store_name#3930 = ese)) AND isnotnull(s_store_sk#3925)))
    // Input: ListBuffer(s_store_sk#3925, s_store_name#3930)
    // Output: ListBuffer(s_store_sk#3925)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5893686_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name3930 = tbl_SerializeFromObject_TD_5893686_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _s_store_sk3925 = tbl_SerializeFromObject_TD_5893686_input.getInt32(i, 0);
        if ((_s_store_name3930.data() != "NULL" && (std::string(_s_store_name3930.data()) == "ese")) && (_s_store_sk3925!= 0)) {
            int32_t _s_store_sk3925_t = tbl_SerializeFromObject_TD_5893686_input.getInt32(i, 0);
            tbl_Filter_TD_4532889_output.setInt32(r, 0, _s_store_sk3925_t);
            r++;
        }
    }
    tbl_Filter_TD_4532889_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4532889_output #Row: " << tbl_Filter_TD_4532889_output.getNumRow() << std::endl;
}



void SW_Aggregate_TD_4249092(Table &tbl_JOIN_INNER_TD_5336669_output, Table &tbl_Aggregate_TD_4249092_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(count(1) AS h10_30_to_11#3548L)
    // Input: ListBuffer(ss_store_sk#3760, s_store_sk#3791)
    // Output: ListBuffer(h10_30_to_11#3548L)
    int64_t count_0 = 0;
    int nrow1 = tbl_JOIN_INNER_TD_5336669_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_store_sk3760 = tbl_JOIN_INNER_TD_5336669_output.getInt32(i, 0);
        int32_t _s_store_sk3791 = tbl_JOIN_INNER_TD_5336669_output.getInt32(i, 1);
        int64_t _h10_30_to_113548L_count_0 = 1;
        count_0 += _h10_30_to_113548L_count_0;
    }
    int r = 0;
    int64_t _h10_30_to_113548L = count_0;
    tbl_Aggregate_TD_4249092_output.setInt64(r++, 0, _h10_30_to_113548L);
    tbl_Aggregate_TD_4249092_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_4249092_output #Row: " << tbl_Aggregate_TD_4249092_output.getNumRow() << std::endl;
}

void SW_JOIN_CROSS_TD_4414428(Table &tbl_JOIN_CROSS_TD_5759888_output, Table &tbl_Aggregate_TD_5162264_output, Table &tbl_JOIN_CROSS_TD_4414428_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_CROSS
    // Operation: ListBuffer(JOIN_CROSS)
    // Left Table: ListBuffer(h8_30_to_9#3544L, h9_to_9_30#3545L, h9_30_to_10#3546L)
    // Right Table: ListBuffer(h10_to_10_30#3547L)
    // Output Table: ListBuffer(h8_30_to_9#3544L, h9_to_9_30#3545L, h9_30_to_10#3546L, h10_to_10_30#3547L)
    int left_nrow = tbl_JOIN_CROSS_TD_5759888_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_5162264_output.getNumRow();
    long r = 0;
    for (int i = 0; i < left_nrow; i++) {
        for (int j = 0; j < right_nrow; j++) {
            tbl_JOIN_CROSS_TD_4414428_output.setInt64(r, 0, tbl_JOIN_CROSS_TD_5759888_output.getInt64(i, 0));
            tbl_JOIN_CROSS_TD_4414428_output.setInt64(r, 1, tbl_JOIN_CROSS_TD_5759888_output.getInt64(i, 1));
            tbl_JOIN_CROSS_TD_4414428_output.setInt64(r, 2, tbl_JOIN_CROSS_TD_5759888_output.getInt64(i, 2));
            tbl_JOIN_CROSS_TD_4414428_output.setInt64(r, 3, tbl_Aggregate_TD_5162264_output.getInt64(j, 0));
            ++r;
        }
    }
    tbl_JOIN_CROSS_TD_4414428_output.setNumRow(r);
    std::cout << "tbl_JOIN_CROSS_TD_4414428_output #Row: " << tbl_JOIN_CROSS_TD_4414428_output.getNumRow() << std::endl;
}

void SW_Filter_TD_3373394(Table &tbl_SerializeFromObject_TD_4330522_input, Table &tbl_Filter_TD_3373394_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(s_store_name#3997) AND (s_store_name#3997 = ese)) AND isnotnull(s_store_sk#3992)))
    // Input: ListBuffer(s_store_sk#3992, s_store_name#3997)
    // Output: ListBuffer(s_store_sk#3992)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_4330522_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_store_name3997 = tbl_SerializeFromObject_TD_4330522_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _s_store_sk3992 = tbl_SerializeFromObject_TD_4330522_input.getInt32(i, 0);
        if ((_s_store_name3997.data() != "NULL" && (std::string(_s_store_name3997.data()) == "ese")) && (_s_store_sk3992!= 0)) {
            int32_t _s_store_sk3992_t = tbl_SerializeFromObject_TD_4330522_input.getInt32(i, 0);
            tbl_Filter_TD_3373394_output.setInt32(r, 0, _s_store_sk3992_t);
            r++;
        }
    }
    tbl_Filter_TD_3373394_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_3373394_output #Row: " << tbl_Filter_TD_3373394_output.getNumRow() << std::endl;
}



void SW_Aggregate_TD_3629204(Table &tbl_JOIN_INNER_TD_4705166_output, Table &tbl_Aggregate_TD_3629204_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(count(1) AS h11_to_11_30#3549L)
    // Input: ListBuffer(ss_store_sk#3827, s_store_sk#3858)
    // Output: ListBuffer(h11_to_11_30#3549L)
    int64_t count_0 = 0;
    int nrow1 = tbl_JOIN_INNER_TD_4705166_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_store_sk3827 = tbl_JOIN_INNER_TD_4705166_output.getInt32(i, 0);
        int32_t _s_store_sk3858 = tbl_JOIN_INNER_TD_4705166_output.getInt32(i, 1);
        int64_t _h11_to_11_303549L_count_0 = 1;
        count_0 += _h11_to_11_303549L_count_0;
    }
    int r = 0;
    int64_t _h11_to_11_303549L = count_0;
    tbl_Aggregate_TD_3629204_output.setInt64(r++, 0, _h11_to_11_303549L);
    tbl_Aggregate_TD_3629204_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_3629204_output #Row: " << tbl_Aggregate_TD_3629204_output.getNumRow() << std::endl;
}

void SW_JOIN_CROSS_TD_3927976(Table &tbl_JOIN_CROSS_TD_4414428_output, Table &tbl_Aggregate_TD_4249092_output, Table &tbl_JOIN_CROSS_TD_3927976_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_CROSS
    // Operation: ListBuffer(JOIN_CROSS)
    // Left Table: ListBuffer(h8_30_to_9#3544L, h9_to_9_30#3545L, h9_30_to_10#3546L, h10_to_10_30#3547L)
    // Right Table: ListBuffer(h10_30_to_11#3548L)
    // Output Table: ListBuffer(h8_30_to_9#3544L, h9_to_9_30#3545L, h9_30_to_10#3546L, h10_to_10_30#3547L, h10_30_to_11#3548L)
    int left_nrow = tbl_JOIN_CROSS_TD_4414428_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_4249092_output.getNumRow();
    long r = 0;
    for (int i = 0; i < left_nrow; i++) {
        for (int j = 0; j < right_nrow; j++) {
            tbl_JOIN_CROSS_TD_3927976_output.setInt64(r, 0, tbl_JOIN_CROSS_TD_4414428_output.getInt64(i, 0));
            tbl_JOIN_CROSS_TD_3927976_output.setInt64(r, 1, tbl_JOIN_CROSS_TD_4414428_output.getInt64(i, 1));
            tbl_JOIN_CROSS_TD_3927976_output.setInt64(r, 2, tbl_JOIN_CROSS_TD_4414428_output.getInt64(i, 2));
            tbl_JOIN_CROSS_TD_3927976_output.setInt64(r, 3, tbl_JOIN_CROSS_TD_4414428_output.getInt64(i, 3));
            tbl_JOIN_CROSS_TD_3927976_output.setInt64(r, 4, tbl_Aggregate_TD_4249092_output.getInt64(j, 0));
            ++r;
        }
    }
    tbl_JOIN_CROSS_TD_3927976_output.setNumRow(r);
    std::cout << "tbl_JOIN_CROSS_TD_3927976_output #Row: " << tbl_JOIN_CROSS_TD_3927976_output.getNumRow() << std::endl;
}


void SW_Aggregate_TD_2384017(Table &tbl_JOIN_INNER_TD_3912575_output, Table &tbl_Aggregate_TD_2384017_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(count(1) AS h11_30_to_12#3550L)
    // Input: ListBuffer(ss_store_sk#3894, s_store_sk#3925)
    // Output: ListBuffer(h11_30_to_12#3550L)
    int64_t count_0 = 0;
    int nrow1 = tbl_JOIN_INNER_TD_3912575_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_store_sk3894 = tbl_JOIN_INNER_TD_3912575_output.getInt32(i, 0);
        int32_t _s_store_sk3925 = tbl_JOIN_INNER_TD_3912575_output.getInt32(i, 1);
        int64_t _h11_30_to_123550L_count_0 = 1;
        count_0 += _h11_30_to_123550L_count_0;
    }
    int r = 0;
    int64_t _h11_30_to_123550L = count_0;
    tbl_Aggregate_TD_2384017_output.setInt64(r++, 0, _h11_30_to_123550L);
    tbl_Aggregate_TD_2384017_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_2384017_output #Row: " << tbl_Aggregate_TD_2384017_output.getNumRow() << std::endl;
}

void SW_JOIN_CROSS_TD_2364608(Table &tbl_JOIN_CROSS_TD_3927976_output, Table &tbl_Aggregate_TD_3629204_output, Table &tbl_JOIN_CROSS_TD_2364608_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_CROSS
    // Operation: ListBuffer(JOIN_CROSS)
    // Left Table: ListBuffer(h8_30_to_9#3544L, h9_to_9_30#3545L, h9_30_to_10#3546L, h10_to_10_30#3547L, h10_30_to_11#3548L)
    // Right Table: ListBuffer(h11_to_11_30#3549L)
    // Output Table: ListBuffer(h8_30_to_9#3544L, h9_to_9_30#3545L, h9_30_to_10#3546L, h10_to_10_30#3547L, h10_30_to_11#3548L, h11_to_11_30#3549L)
    int left_nrow = tbl_JOIN_CROSS_TD_3927976_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_3629204_output.getNumRow();
    long r = 0;
    for (int i = 0; i < left_nrow; i++) {
        for (int j = 0; j < right_nrow; j++) {
            tbl_JOIN_CROSS_TD_2364608_output.setInt64(r, 0, tbl_JOIN_CROSS_TD_3927976_output.getInt64(i, 0));
            tbl_JOIN_CROSS_TD_2364608_output.setInt64(r, 1, tbl_JOIN_CROSS_TD_3927976_output.getInt64(i, 1));
            tbl_JOIN_CROSS_TD_2364608_output.setInt64(r, 2, tbl_JOIN_CROSS_TD_3927976_output.getInt64(i, 2));
            tbl_JOIN_CROSS_TD_2364608_output.setInt64(r, 3, tbl_JOIN_CROSS_TD_3927976_output.getInt64(i, 3));
            tbl_JOIN_CROSS_TD_2364608_output.setInt64(r, 4, tbl_JOIN_CROSS_TD_3927976_output.getInt64(i, 4));
            tbl_JOIN_CROSS_TD_2364608_output.setInt64(r, 5, tbl_Aggregate_TD_3629204_output.getInt64(j, 0));
            ++r;
        }
    }
    tbl_JOIN_CROSS_TD_2364608_output.setNumRow(r);
    std::cout << "tbl_JOIN_CROSS_TD_2364608_output #Row: " << tbl_JOIN_CROSS_TD_2364608_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_1840294(Table &tbl_JOIN_INNER_TD_2645078_output, Table &tbl_Aggregate_TD_1840294_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(count(1) AS h12_to_12_30#3551L)
    // Input: ListBuffer(ss_store_sk#3961, s_store_sk#3992)
    // Output: ListBuffer(h12_to_12_30#3551L)
    int64_t count_0 = 0;
    int nrow1 = tbl_JOIN_INNER_TD_2645078_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_store_sk3961 = tbl_JOIN_INNER_TD_2645078_output.getInt32(i, 0);
        int32_t _s_store_sk3992 = tbl_JOIN_INNER_TD_2645078_output.getInt32(i, 1);
        int64_t _h12_to_12_303551L_count_0 = 1;
        count_0 += _h12_to_12_303551L_count_0;
    }
    int r = 0;
    int64_t _h12_to_12_303551L = count_0;
    tbl_Aggregate_TD_1840294_output.setInt64(r++, 0, _h12_to_12_303551L);
    tbl_Aggregate_TD_1840294_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_1840294_output #Row: " << tbl_Aggregate_TD_1840294_output.getNumRow() << std::endl;
}

void SW_JOIN_CROSS_TD_1212895(Table &tbl_JOIN_CROSS_TD_2364608_output, Table &tbl_Aggregate_TD_2384017_output, Table &tbl_JOIN_CROSS_TD_1212895_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_CROSS
    // Operation: ListBuffer(JOIN_CROSS)
    // Left Table: ListBuffer(h8_30_to_9#3544L, h9_to_9_30#3545L, h9_30_to_10#3546L, h10_to_10_30#3547L, h10_30_to_11#3548L, h11_to_11_30#3549L)
    // Right Table: ListBuffer(h11_30_to_12#3550L)
    // Output Table: ListBuffer(h8_30_to_9#3544L, h9_to_9_30#3545L, h9_30_to_10#3546L, h10_to_10_30#3547L, h10_30_to_11#3548L, h11_to_11_30#3549L, h11_30_to_12#3550L)
    int left_nrow = tbl_JOIN_CROSS_TD_2364608_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_2384017_output.getNumRow();
    long r = 0;
    for (int i = 0; i < left_nrow; i++) {
        for (int j = 0; j < right_nrow; j++) {
            tbl_JOIN_CROSS_TD_1212895_output.setInt64(r, 0, tbl_JOIN_CROSS_TD_2364608_output.getInt64(i, 0));
            tbl_JOIN_CROSS_TD_1212895_output.setInt64(r, 1, tbl_JOIN_CROSS_TD_2364608_output.getInt64(i, 1));
            tbl_JOIN_CROSS_TD_1212895_output.setInt64(r, 2, tbl_JOIN_CROSS_TD_2364608_output.getInt64(i, 2));
            tbl_JOIN_CROSS_TD_1212895_output.setInt64(r, 3, tbl_JOIN_CROSS_TD_2364608_output.getInt64(i, 3));
            tbl_JOIN_CROSS_TD_1212895_output.setInt64(r, 4, tbl_JOIN_CROSS_TD_2364608_output.getInt64(i, 4));
            tbl_JOIN_CROSS_TD_1212895_output.setInt64(r, 5, tbl_JOIN_CROSS_TD_2364608_output.getInt64(i, 5));
            tbl_JOIN_CROSS_TD_1212895_output.setInt64(r, 6, tbl_Aggregate_TD_2384017_output.getInt64(j, 0));
            ++r;
        }
    }
    tbl_JOIN_CROSS_TD_1212895_output.setNumRow(r);
    std::cout << "tbl_JOIN_CROSS_TD_1212895_output #Row: " << tbl_JOIN_CROSS_TD_1212895_output.getNumRow() << std::endl;
}

void SW_JOIN_CROSS_TD_086561(Table &tbl_JOIN_CROSS_TD_1212895_output, Table &tbl_Aggregate_TD_1840294_output, Table &tbl_JOIN_CROSS_TD_086561_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_CROSS
    // Operation: ListBuffer(JOIN_CROSS)
    // Left Table: ListBuffer(h8_30_to_9#3544L, h9_to_9_30#3545L, h9_30_to_10#3546L, h10_to_10_30#3547L, h10_30_to_11#3548L, h11_to_11_30#3549L, h11_30_to_12#3550L)
    // Right Table: ListBuffer(h12_to_12_30#3551L)
    // Output Table: ListBuffer(h8_30_to_9#3544L, h9_to_9_30#3545L, h9_30_to_10#3546L, h10_to_10_30#3547L, h10_30_to_11#3548L, h11_to_11_30#3549L, h11_30_to_12#3550L, h12_to_12_30#3551L)
    int left_nrow = tbl_JOIN_CROSS_TD_1212895_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_1840294_output.getNumRow();
    long r = 0;
    for (int i = 0; i < left_nrow; i++) {
        for (int j = 0; j < right_nrow; j++) {
            tbl_JOIN_CROSS_TD_086561_output.setInt64(r, 0, tbl_JOIN_CROSS_TD_1212895_output.getInt64(i, 0));
            tbl_JOIN_CROSS_TD_086561_output.setInt64(r, 1, tbl_JOIN_CROSS_TD_1212895_output.getInt64(i, 1));
            tbl_JOIN_CROSS_TD_086561_output.setInt64(r, 2, tbl_JOIN_CROSS_TD_1212895_output.getInt64(i, 2));
            tbl_JOIN_CROSS_TD_086561_output.setInt64(r, 3, tbl_JOIN_CROSS_TD_1212895_output.getInt64(i, 3));
            tbl_JOIN_CROSS_TD_086561_output.setInt64(r, 4, tbl_JOIN_CROSS_TD_1212895_output.getInt64(i, 4));
            tbl_JOIN_CROSS_TD_086561_output.setInt64(r, 5, tbl_JOIN_CROSS_TD_1212895_output.getInt64(i, 5));
            tbl_JOIN_CROSS_TD_086561_output.setInt64(r, 6, tbl_JOIN_CROSS_TD_1212895_output.getInt64(i, 6));
            tbl_JOIN_CROSS_TD_086561_output.setInt64(r, 7, tbl_Aggregate_TD_1840294_output.getInt64(j, 0));
            ++r;
        }
    }
    tbl_JOIN_CROSS_TD_086561_output.setNumRow(r);
    std::cout << "tbl_JOIN_CROSS_TD_086561_output #Row: " << tbl_JOIN_CROSS_TD_086561_output.getNumRow() << std::endl;
}

