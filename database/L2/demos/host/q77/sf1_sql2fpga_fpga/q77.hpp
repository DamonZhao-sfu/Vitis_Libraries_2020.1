#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_11223248(Table &tbl_SerializeFromObject_TD_12223447_input, Table &tbl_Filter_TD_11223248_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_date#3713) AND ((d_date#3713 >= 2000-08-23) AND (d_date#3713 <= 2000-09-22))) AND isnotnull(d_date_sk#3711)))
    // Input: ListBuffer(d_date_sk#3711, d_date#3713)
    // Output: ListBuffer(d_date_sk#3711)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12223447_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date3713 = tbl_SerializeFromObject_TD_12223447_input.getInt32(i, 1);
        int32_t _d_date_sk3711 = tbl_SerializeFromObject_TD_12223447_input.getInt32(i, 0);
        if (((_d_date3713!= 0) && ((_d_date3713 >= 20000823) && (_d_date3713 <= 20000922))) && (_d_date_sk3711!= 0)) {
            int32_t _d_date_sk3711_t = tbl_SerializeFromObject_TD_12223447_input.getInt32(i, 0);
            tbl_Filter_TD_11223248_output.setInt32(r, 0, _d_date_sk3711_t);
            r++;
        }
    }
    tbl_Filter_TD_11223248_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11223248_output #Row: " << tbl_Filter_TD_11223248_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11118799(Table &tbl_SerializeFromObject_TD_12305071_input, Table &tbl_Filter_TD_11118799_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(wr_returned_date_sk#831) AND isnotnull(wr_web_page_sk#842)))
    // Input: ListBuffer(wr_returned_date_sk#831, wr_web_page_sk#842, wr_return_amt#846, wr_net_loss#854)
    // Output: ListBuffer(wr_returned_date_sk#831, wr_web_page_sk#842, wr_return_amt#846, wr_net_loss#854)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12305071_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _wr_returned_date_sk831 = tbl_SerializeFromObject_TD_12305071_input.getInt32(i, 0);
        int32_t _wr_web_page_sk842 = tbl_SerializeFromObject_TD_12305071_input.getInt32(i, 1);
        if ((_wr_returned_date_sk831!= 0) && (_wr_web_page_sk842!= 0)) {
            int32_t _wr_returned_date_sk831_t = tbl_SerializeFromObject_TD_12305071_input.getInt32(i, 0);
            tbl_Filter_TD_11118799_output.setInt32(r, 0, _wr_returned_date_sk831_t);
            int32_t _wr_web_page_sk842_t = tbl_SerializeFromObject_TD_12305071_input.getInt32(i, 1);
            tbl_Filter_TD_11118799_output.setInt32(r, 1, _wr_web_page_sk842_t);
            int64_t _wr_return_amt846_t = tbl_SerializeFromObject_TD_12305071_input.getInt64(i, 2);
            tbl_Filter_TD_11118799_output.setInt64(r, 2, _wr_return_amt846_t);
            int64_t _wr_net_loss854_t = tbl_SerializeFromObject_TD_12305071_input.getInt64(i, 3);
            tbl_Filter_TD_11118799_output.setInt64(r, 3, _wr_net_loss854_t);
            r++;
        }
    }
    tbl_Filter_TD_11118799_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11118799_output #Row: " << tbl_Filter_TD_11118799_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11210199(Table &tbl_SerializeFromObject_TD_1291518_input, Table &tbl_Filter_TD_11210199_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_date#3685) AND ((d_date#3685 >= 2000-08-23) AND (d_date#3685 <= 2000-09-22))) AND isnotnull(d_date_sk#3683)))
    // Input: ListBuffer(d_date_sk#3683, d_date#3685)
    // Output: ListBuffer(d_date_sk#3683)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1291518_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date3685 = tbl_SerializeFromObject_TD_1291518_input.getInt32(i, 1);
        int32_t _d_date_sk3683 = tbl_SerializeFromObject_TD_1291518_input.getInt32(i, 0);
        if (((_d_date3685!= 0) && ((_d_date3685 >= 20000823) && (_d_date3685 <= 20000922))) && (_d_date_sk3683!= 0)) {
            int32_t _d_date_sk3683_t = tbl_SerializeFromObject_TD_1291518_input.getInt32(i, 0);
            tbl_Filter_TD_11210199_output.setInt32(r, 0, _d_date_sk3683_t);
            r++;
        }
    }
    tbl_Filter_TD_11210199_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11210199_output #Row: " << tbl_Filter_TD_11210199_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11281364(Table &tbl_SerializeFromObject_TD_12791368_input, Table &tbl_Filter_TD_11281364_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_sold_date_sk#729) AND isnotnull(ws_web_page_sk#741)))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_web_page_sk#741, ws_ext_sales_price#752, ws_net_profit#762)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_web_page_sk#741, ws_ext_sales_price#752, ws_net_profit#762)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12791368_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_12791368_input.getInt32(i, 0);
        int32_t _ws_web_page_sk741 = tbl_SerializeFromObject_TD_12791368_input.getInt32(i, 1);
        if ((_ws_sold_date_sk729!= 0) && (_ws_web_page_sk741!= 0)) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_12791368_input.getInt32(i, 0);
            tbl_Filter_TD_11281364_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_web_page_sk741_t = tbl_SerializeFromObject_TD_12791368_input.getInt32(i, 1);
            tbl_Filter_TD_11281364_output.setInt32(r, 1, _ws_web_page_sk741_t);
            int64_t _ws_ext_sales_price752_t = tbl_SerializeFromObject_TD_12791368_input.getInt64(i, 2);
            tbl_Filter_TD_11281364_output.setInt64(r, 2, _ws_ext_sales_price752_t);
            int64_t _ws_net_profit762_t = tbl_SerializeFromObject_TD_12791368_input.getInt64(i, 3);
            tbl_Filter_TD_11281364_output.setInt64(r, 3, _ws_net_profit762_t);
            r++;
        }
    }
    tbl_Filter_TD_11281364_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11281364_output #Row: " << tbl_Filter_TD_11281364_output.getNumRow() << std::endl;
}

void SW_Filter_TD_1145(Table &tbl_SerializeFromObject_TD_12794166_input, Table &tbl_Filter_TD_1145_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_date#3572) AND ((d_date#3572 >= 2000-08-23) AND (d_date#3572 <= 2000-09-22))) AND isnotnull(d_date_sk#3570)))
    // Input: ListBuffer(d_date_sk#3570, d_date#3572)
    // Output: ListBuffer(d_date_sk#3570)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12794166_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date3572 = tbl_SerializeFromObject_TD_12794166_input.getInt32(i, 1);
        int32_t _d_date_sk3570 = tbl_SerializeFromObject_TD_12794166_input.getInt32(i, 0);
        if (((_d_date3572!= 0) && ((_d_date3572 >= 20000823) && (_d_date3572 <= 20000922))) && (_d_date_sk3570!= 0)) {
            int32_t _d_date_sk3570_t = tbl_SerializeFromObject_TD_12794166_input.getInt32(i, 0);
            tbl_Filter_TD_1145_output.setInt32(r, 0, _d_date_sk3570_t);
            r++;
        }
    }
    tbl_Filter_TD_1145_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1145_output #Row: " << tbl_Filter_TD_1145_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11226393(Table &tbl_SerializeFromObject_TD_12935067_input, Table &tbl_Filter_TD_11226393_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(sr_returned_date_sk#669) AND isnotnull(sr_store_sk#676)))
    // Input: ListBuffer(sr_returned_date_sk#669, sr_store_sk#676, sr_return_amt#680, sr_net_loss#688)
    // Output: ListBuffer(sr_returned_date_sk#669, sr_store_sk#676, sr_return_amt#680, sr_net_loss#688)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12935067_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _sr_returned_date_sk669 = tbl_SerializeFromObject_TD_12935067_input.getInt32(i, 0);
        int32_t _sr_store_sk676 = tbl_SerializeFromObject_TD_12935067_input.getInt32(i, 1);
        if ((_sr_returned_date_sk669!= 0) && (_sr_store_sk676!= 0)) {
            int32_t _sr_returned_date_sk669_t = tbl_SerializeFromObject_TD_12935067_input.getInt32(i, 0);
            tbl_Filter_TD_11226393_output.setInt32(r, 0, _sr_returned_date_sk669_t);
            int32_t _sr_store_sk676_t = tbl_SerializeFromObject_TD_12935067_input.getInt32(i, 1);
            tbl_Filter_TD_11226393_output.setInt32(r, 1, _sr_store_sk676_t);
            int64_t _sr_return_amt680_t = tbl_SerializeFromObject_TD_12935067_input.getInt64(i, 2);
            tbl_Filter_TD_11226393_output.setInt64(r, 2, _sr_return_amt680_t);
            int64_t _sr_net_loss688_t = tbl_SerializeFromObject_TD_12935067_input.getInt64(i, 3);
            tbl_Filter_TD_11226393_output.setInt64(r, 3, _sr_net_loss688_t);
            r++;
        }
    }
    tbl_Filter_TD_11226393_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11226393_output #Row: " << tbl_Filter_TD_11226393_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11687332(Table &tbl_SerializeFromObject_TD_12783138_input, Table &tbl_Filter_TD_11687332_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_date#122) AND ((d_date#122 >= 2000-08-23) AND (d_date#122 <= 2000-09-22))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_date#122)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12783138_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date122 = tbl_SerializeFromObject_TD_12783138_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_12783138_input.getInt32(i, 0);
        if (((_d_date122!= 0) && ((_d_date122 >= 20000823) && (_d_date122 <= 20000922))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_12783138_input.getInt32(i, 0);
            tbl_Filter_TD_11687332_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_11687332_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11687332_output #Row: " << tbl_Filter_TD_11687332_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11932688(Table &tbl_SerializeFromObject_TD_12887464_input, Table &tbl_Filter_TD_11932688_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_sold_date_sk#1206) AND isnotnull(ss_store_sk#1213)))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_store_sk#1213, ss_ext_sales_price#1221, ss_net_profit#1228)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_store_sk#1213, ss_ext_sales_price#1221, ss_net_profit#1228)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12887464_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_12887464_input.getInt32(i, 0);
        int32_t _ss_store_sk1213 = tbl_SerializeFromObject_TD_12887464_input.getInt32(i, 1);
        if ((_ss_sold_date_sk1206!= 0) && (_ss_store_sk1213!= 0)) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_12887464_input.getInt32(i, 0);
            tbl_Filter_TD_11932688_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_store_sk1213_t = tbl_SerializeFromObject_TD_12887464_input.getInt32(i, 1);
            tbl_Filter_TD_11932688_output.setInt32(r, 1, _ss_store_sk1213_t);
            int64_t _ss_ext_sales_price1221_t = tbl_SerializeFromObject_TD_12887464_input.getInt64(i, 2);
            tbl_Filter_TD_11932688_output.setInt64(r, 2, _ss_ext_sales_price1221_t);
            int64_t _ss_net_profit1228_t = tbl_SerializeFromObject_TD_12887464_input.getInt64(i, 3);
            tbl_Filter_TD_11932688_output.setInt64(r, 3, _ss_net_profit1228_t);
            r++;
        }
    }
    tbl_Filter_TD_11932688_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11932688_output #Row: " << tbl_Filter_TD_11932688_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10626660(Table &tbl_SerializeFromObject_TD_11223040_input, Table &tbl_Filter_TD_10626660_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(wp_web_page_sk#3739))
    // Input: ListBuffer(wp_web_page_sk#3739)
    // Output: ListBuffer(wp_web_page_sk#3739)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11223040_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _wp_web_page_sk3739 = tbl_SerializeFromObject_TD_11223040_input.getInt32(i, 0);
        if (_wp_web_page_sk3739!= 0) {
            int32_t _wp_web_page_sk3739_t = tbl_SerializeFromObject_TD_11223040_input.getInt32(i, 0);
            tbl_Filter_TD_10626660_output.setInt32(r, 0, _wp_web_page_sk3739_t);
            r++;
        }
    }
    tbl_Filter_TD_10626660_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10626660_output #Row: " << tbl_Filter_TD_10626660_output.getNumRow() << std::endl;
}


void SW_Filter_TD_10136224(Table &tbl_SerializeFromObject_TD_11461628_input, Table &tbl_Filter_TD_10136224_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(wp_web_page_sk#615))
    // Input: ListBuffer(wp_web_page_sk#615)
    // Output: ListBuffer(wp_web_page_sk#615)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11461628_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _wp_web_page_sk615 = tbl_SerializeFromObject_TD_11461628_input.getInt32(i, 0);
        if (_wp_web_page_sk615!= 0) {
            int32_t _wp_web_page_sk615_t = tbl_SerializeFromObject_TD_11461628_input.getInt32(i, 0);
            tbl_Filter_TD_10136224_output.setInt32(r, 0, _wp_web_page_sk615_t);
            r++;
        }
    }
    tbl_Filter_TD_10136224_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10136224_output #Row: " << tbl_Filter_TD_10136224_output.getNumRow() << std::endl;
}


void SW_Filter_TD_10899949(Table &tbl_SerializeFromObject_TD_11524432_input, Table &tbl_Filter_TD_10899949_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_date#3657) AND ((d_date#3657 >= 2000-08-23) AND (d_date#3657 <= 2000-09-22))) AND isnotnull(d_date_sk#3655)))
    // Input: ListBuffer(d_date_sk#3655, d_date#3657)
    // Output: ListBuffer(d_date_sk#3655)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11524432_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date3657 = tbl_SerializeFromObject_TD_11524432_input.getInt32(i, 1);
        int32_t _d_date_sk3655 = tbl_SerializeFromObject_TD_11524432_input.getInt32(i, 0);
        if (((_d_date3657!= 0) && ((_d_date3657 >= 20000823) && (_d_date3657 <= 20000922))) && (_d_date_sk3655!= 0)) {
            int32_t _d_date_sk3655_t = tbl_SerializeFromObject_TD_11524432_input.getInt32(i, 0);
            tbl_Filter_TD_10899949_output.setInt32(r, 0, _d_date_sk3655_t);
            r++;
        }
    }
    tbl_Filter_TD_10899949_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10899949_output #Row: " << tbl_Filter_TD_10899949_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10188919(Table &tbl_SerializeFromObject_TD_1153545_input, Table &tbl_Filter_TD_10188919_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(cr_returned_date_sk#1023))
    // Input: ListBuffer(cr_returned_date_sk#1023, cr_call_center_sk#1034, cr_return_amount#1041, cr_net_loss#1049)
    // Output: ListBuffer(cr_returned_date_sk#1023, cr_call_center_sk#1034, cr_return_amount#1041, cr_net_loss#1049)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1153545_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cr_returned_date_sk1023 = tbl_SerializeFromObject_TD_1153545_input.getInt32(i, 0);
        if (_cr_returned_date_sk1023!= 0) {
            int32_t _cr_returned_date_sk1023_t = tbl_SerializeFromObject_TD_1153545_input.getInt32(i, 0);
            tbl_Filter_TD_10188919_output.setInt32(r, 0, _cr_returned_date_sk1023_t);
            int32_t _cr_call_center_sk1034_t = tbl_SerializeFromObject_TD_1153545_input.getInt32(i, 1);
            tbl_Filter_TD_10188919_output.setInt32(r, 1, _cr_call_center_sk1034_t);
            int64_t _cr_return_amount1041_t = tbl_SerializeFromObject_TD_1153545_input.getInt64(i, 2);
            tbl_Filter_TD_10188919_output.setInt64(r, 2, _cr_return_amount1041_t);
            int64_t _cr_net_loss1049_t = tbl_SerializeFromObject_TD_1153545_input.getInt64(i, 3);
            tbl_Filter_TD_10188919_output.setInt64(r, 3, _cr_net_loss1049_t);
            r++;
        }
    }
    tbl_Filter_TD_10188919_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10188919_output #Row: " << tbl_Filter_TD_10188919_output.getNumRow() << std::endl;
}

void SW_Filter_TD_1046563(Table &tbl_SerializeFromObject_TD_11299306_input, Table &tbl_Filter_TD_1046563_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_date#3629) AND ((d_date#3629 >= 2000-08-23) AND (d_date#3629 <= 2000-09-22))) AND isnotnull(d_date_sk#3627)))
    // Input: ListBuffer(d_date_sk#3627, d_date#3629)
    // Output: ListBuffer(d_date_sk#3627)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11299306_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date3629 = tbl_SerializeFromObject_TD_11299306_input.getInt32(i, 1);
        int32_t _d_date_sk3627 = tbl_SerializeFromObject_TD_11299306_input.getInt32(i, 0);
        if (((_d_date3629!= 0) && ((_d_date3629 >= 20000823) && (_d_date3629 <= 20000922))) && (_d_date_sk3627!= 0)) {
            int32_t _d_date_sk3627_t = tbl_SerializeFromObject_TD_11299306_input.getInt32(i, 0);
            tbl_Filter_TD_1046563_output.setInt32(r, 0, _d_date_sk3627_t);
            r++;
        }
    }
    tbl_Filter_TD_1046563_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1046563_output #Row: " << tbl_Filter_TD_1046563_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10197211(Table &tbl_SerializeFromObject_TD_11279308_input, Table &tbl_Filter_TD_10197211_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(cs_sold_date_sk#1104))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_call_center_sk#1115, cs_ext_sales_price#1127, cs_net_profit#1137)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_call_center_sk#1115, cs_ext_sales_price#1127, cs_net_profit#1137)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11279308_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_11279308_input.getInt32(i, 0);
        if (_cs_sold_date_sk1104!= 0) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_11279308_input.getInt32(i, 0);
            tbl_Filter_TD_10197211_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int32_t _cs_call_center_sk1115_t = tbl_SerializeFromObject_TD_11279308_input.getInt32(i, 1);
            tbl_Filter_TD_10197211_output.setInt32(r, 1, _cs_call_center_sk1115_t);
            int64_t _cs_ext_sales_price1127_t = tbl_SerializeFromObject_TD_11279308_input.getInt64(i, 2);
            tbl_Filter_TD_10197211_output.setInt64(r, 2, _cs_ext_sales_price1127_t);
            int64_t _cs_net_profit1137_t = tbl_SerializeFromObject_TD_11279308_input.getInt64(i, 3);
            tbl_Filter_TD_10197211_output.setInt64(r, 3, _cs_net_profit1137_t);
            r++;
        }
    }
    tbl_Filter_TD_10197211_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10197211_output #Row: " << tbl_Filter_TD_10197211_output.getNumRow() << std::endl;
}

void SW_Filter_TD_1044974(Table &tbl_SerializeFromObject_TD_11249664_input, Table &tbl_Filter_TD_1044974_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(s_store_sk#3598))
    // Input: ListBuffer(s_store_sk#3598)
    // Output: ListBuffer(s_store_sk#3598)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11249664_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _s_store_sk3598 = tbl_SerializeFromObject_TD_11249664_input.getInt32(i, 0);
        if (_s_store_sk3598!= 0) {
            int32_t _s_store_sk3598_t = tbl_SerializeFromObject_TD_11249664_input.getInt32(i, 0);
            tbl_Filter_TD_1044974_output.setInt32(r, 0, _s_store_sk3598_t);
            r++;
        }
    }
    tbl_Filter_TD_1044974_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1044974_output #Row: " << tbl_Filter_TD_1044974_output.getNumRow() << std::endl;
}


void SW_Filter_TD_10535472(Table &tbl_SerializeFromObject_TD_11586100_input, Table &tbl_Filter_TD_10535472_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(s_store_sk#378))
    // Input: ListBuffer(s_store_sk#378)
    // Output: ListBuffer(s_store_sk#378)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11586100_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _s_store_sk378 = tbl_SerializeFromObject_TD_11586100_input.getInt32(i, 0);
        if (_s_store_sk378!= 0) {
            int32_t _s_store_sk378_t = tbl_SerializeFromObject_TD_11586100_input.getInt32(i, 0);
            tbl_Filter_TD_10535472_output.setInt32(r, 0, _s_store_sk378_t);
            r++;
        }
    }
    tbl_Filter_TD_10535472_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10535472_output #Row: " << tbl_Filter_TD_10535472_output.getNumRow() << std::endl;
}








void SW_Aggregate_TD_8922127_consolidate(Table &tbl_Aggregate_TD_8922127_output_preprocess, Table &tbl_Aggregate_TD_8922127_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_8922127_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _wp_web_page_sk3739 = tbl_Aggregate_TD_8922127_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_8922127_output.setInt32(r, 0, _wp_web_page_sk3739);
        int64_t _returns3568 = tbl_Aggregate_TD_8922127_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_8922127_output.setInt64(r, 1, _returns3568);
        int64_t _profit_loss3569 = tbl_Aggregate_TD_8922127_output_preprocess.combineInt64(r, 9, 1);
        tbl_Aggregate_TD_8922127_output.setInt64(r, 2, _profit_loss3569);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_8922127_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_8922127_output #Row: " << tbl_Aggregate_TD_8922127_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_8707443_consolidate(Table &tbl_Aggregate_TD_8707443_output_preprocess, Table &tbl_Aggregate_TD_8707443_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_8707443_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _wp_web_page_sk615 = tbl_Aggregate_TD_8707443_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_8707443_output.setInt32(r, 0, _wp_web_page_sk615);
        int64_t _sales3566 = tbl_Aggregate_TD_8707443_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_8707443_output.setInt64(r, 1, _sales3566);
        int64_t _profit3567 = tbl_Aggregate_TD_8707443_output_preprocess.combineInt64(r, 9, 1);
        tbl_Aggregate_TD_8707443_output.setInt64(r, 2, _profit3567);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_8707443_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_8707443_output #Row: " << tbl_Aggregate_TD_8707443_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_858490_consolidate(Table &tbl_Aggregate_TD_858490_output_preprocess, Table &tbl_Aggregate_TD_858490_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_858490_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int64_t _returns3564 = tbl_Aggregate_TD_858490_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_858490_output.setInt64(r, 0, _returns3564);
        int64_t _profit_loss3565 = tbl_Aggregate_TD_858490_output_preprocess.combineInt64(r, 9, 1);
        tbl_Aggregate_TD_858490_output.setInt64(r, 1, _profit_loss3565);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_858490_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_858490_output #Row: " << tbl_Aggregate_TD_858490_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_8763895_consolidate(Table &tbl_Aggregate_TD_8763895_output_preprocess, Table &tbl_Aggregate_TD_8763895_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_8763895_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _cs_call_center_sk1115 = tbl_Aggregate_TD_8763895_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_8763895_output.setInt32(r, 0, _cs_call_center_sk1115);
        int64_t _sales3562 = tbl_Aggregate_TD_8763895_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_8763895_output.setInt64(r, 1, _sales3562);
        int64_t _profit3563 = tbl_Aggregate_TD_8763895_output_preprocess.combineInt64(r, 9, 1);
        tbl_Aggregate_TD_8763895_output.setInt64(r, 2, _profit3563);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_8763895_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_8763895_output #Row: " << tbl_Aggregate_TD_8763895_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_8360457_consolidate(Table &tbl_Aggregate_TD_8360457_output_preprocess, Table &tbl_Aggregate_TD_8360457_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_8360457_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _s_store_sk3598 = tbl_Aggregate_TD_8360457_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_8360457_output.setInt32(r, 0, _s_store_sk3598);
        int64_t _returns3560 = tbl_Aggregate_TD_8360457_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_8360457_output.setInt64(r, 1, _returns3560);
        int64_t _profit_loss3561 = tbl_Aggregate_TD_8360457_output_preprocess.combineInt64(r, 9, 1);
        tbl_Aggregate_TD_8360457_output.setInt64(r, 2, _profit_loss3561);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_8360457_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_8360457_output #Row: " << tbl_Aggregate_TD_8360457_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_8981652_consolidate(Table &tbl_Aggregate_TD_8981652_output_preprocess, Table &tbl_Aggregate_TD_8981652_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_8981652_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _s_store_sk378 = tbl_Aggregate_TD_8981652_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_8981652_output.setInt32(r, 0, _s_store_sk378);
        int64_t _sales3558 = tbl_Aggregate_TD_8981652_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_8981652_output.setInt64(r, 1, _sales3558);
        int64_t _profit3559 = tbl_Aggregate_TD_8981652_output_preprocess.combineInt64(r, 9, 1);
        tbl_Aggregate_TD_8981652_output.setInt64(r, 2, _profit3559);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_8981652_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_8981652_output #Row: " << tbl_Aggregate_TD_8981652_output.getNumRow() << std::endl;
}


void SW_JOIN_CROSS_TD_7789765(Table &tbl_Aggregate_TD_8763895_output, Table &tbl_Aggregate_TD_858490_output, Table &tbl_JOIN_CROSS_TD_7789765_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_CROSS
    // Operation: ListBuffer(JOIN_CROSS)
    // Left Table: ListBuffer(cs_call_center_sk#1115, sales#3562, profit#3563)
    // Right Table: ListBuffer(returns#3564, profit_loss#3565)
    // Output Table: ListBuffer(sales#3562, returns#3564, profit#3563, profit_loss#3565, cs_call_center_sk#1115)
    int left_nrow = tbl_Aggregate_TD_8763895_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_858490_output.getNumRow();
    long r = 0;
    for (int i = 0; i < left_nrow; i++) {
        for (int j = 0; j < right_nrow; j++) {
            tbl_JOIN_CROSS_TD_7789765_output.setInt32(r, 0, tbl_Aggregate_TD_8763895_output.getInt32(i, 0));
            tbl_JOIN_CROSS_TD_7789765_output.setInt64(r, 1, tbl_Aggregate_TD_8763895_output.getInt64(i, 1));
            tbl_JOIN_CROSS_TD_7789765_output.setInt64(r, 2, tbl_Aggregate_TD_8763895_output.getInt64(i, 2));
            tbl_JOIN_CROSS_TD_7789765_output.setInt64(r, 3, tbl_Aggregate_TD_858490_output.getInt64(j, 0));
            tbl_JOIN_CROSS_TD_7789765_output.setInt64(r, 4, tbl_Aggregate_TD_858490_output.getInt64(j, 1));
            ++r;
        }
    }
    tbl_JOIN_CROSS_TD_7789765_output.setNumRow(r);
    std::cout << "tbl_JOIN_CROSS_TD_7789765_output #Row: " << tbl_JOIN_CROSS_TD_7789765_output.getNumRow() << std::endl;
}


void SW_Project_TD_6224311(Table &tbl_JOIN_LEFTOUTER_TD_7206188_output, Table &tbl_Project_TD_6224311_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(coalesce(returns#3568, 0.00) AS returns#3553, CheckOverflow((promote_precision(cast(profit#3567 as decimal(18,2))) - promote_precision(cast(coalesce(profit_loss#3569, 0.00) as decimal(18,2)))), DecimalType(18,2), true) AS profit#3554, web channel AS channel#4102, wp_web_page_sk#615 AS id#4103)
    // Input: ListBuffer(sales#3566, returns#3568, profit#3567, profit_loss#3569, wp_web_page_sk#615)
    // Output: ListBuffer(sales#3566, returns#3553, profit#3554, channel#4102, id#4103)
    int nrow1 = tbl_JOIN_LEFTOUTER_TD_7206188_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sales3566 = tbl_JOIN_LEFTOUTER_TD_7206188_output.getInt64(i, 0);
        int64_t _returns3568 = tbl_JOIN_LEFTOUTER_TD_7206188_output.getInt64(i, 1);
        int64_t _profit3567 = tbl_JOIN_LEFTOUTER_TD_7206188_output.getInt64(i, 2);
        int64_t _profit_loss3569 = tbl_JOIN_LEFTOUTER_TD_7206188_output.getInt64(i, 3);
        int32_t _wp_web_page_sk615 = tbl_JOIN_LEFTOUTER_TD_7206188_output.getInt32(i, 4);
        int64_t _returns3553 = _returns3568 != 0 ? _returns3568 : 0.00;
        tbl_Project_TD_6224311_output.setInt64(i, 1, _returns3553);
        int64_t _profit3554 = (_profit3567 - _profit_loss3569 != 0 ? _profit_loss3569 : 0.00);
        tbl_Project_TD_6224311_output.setInt64(i, 2, _profit3554);
        std::string _channel4102_str = "web channel";
        std::array<char, TPCDS_READ_MAX + 1> _channel4102{};
        memcpy(_channel4102.data(), _channel4102_str.data(), (_channel4102_str).length());
        tbl_Project_TD_6224311_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 3, _channel4102);
        int32_t _id4103 = _wp_web_page_sk615;
        tbl_Project_TD_6224311_output.setInt32(i, 4, _id4103);
        tbl_Project_TD_6224311_output.setInt64(i, 0, _sales3566);
    }
    tbl_Project_TD_6224311_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_6224311_output #Row: " << tbl_Project_TD_6224311_output.getNumRow() << std::endl;
}

void SW_Project_TD_6997933(Table &tbl_JOIN_CROSS_TD_7789765_output, Table &tbl_Project_TD_6997933_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(CheckOverflow((promote_precision(cast(profit#3563 as decimal(18,2))) - promote_precision(cast(profit_loss#3565 as decimal(18,2)))), DecimalType(18,2), true) AS profit#3550, catalog channel AS channel#4100, cs_call_center_sk#1115 AS id#4101)
    // Input: ListBuffer(sales#3562, returns#3564, profit#3563, profit_loss#3565, cs_call_center_sk#1115)
    // Output: ListBuffer(sales#3562, returns#3564, profit#3550, channel#4100, id#4101)
    int nrow1 = tbl_JOIN_CROSS_TD_7789765_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sales3562 = tbl_JOIN_CROSS_TD_7789765_output.getInt64(i, 0);
        int64_t _returns3564 = tbl_JOIN_CROSS_TD_7789765_output.getInt64(i, 1);
        int64_t _profit3563 = tbl_JOIN_CROSS_TD_7789765_output.getInt64(i, 2);
        int64_t _profit_loss3565 = tbl_JOIN_CROSS_TD_7789765_output.getInt64(i, 3);
        int32_t _cs_call_center_sk1115 = tbl_JOIN_CROSS_TD_7789765_output.getInt32(i, 4);
        int64_t _profit3550 = (_profit3563 - _profit_loss3565);
        tbl_Project_TD_6997933_output.setInt64(i, 2, _profit3550);
        std::string _channel4100_str = "catalog channel";
        std::array<char, TPCDS_READ_MAX + 1> _channel4100{};
        memcpy(_channel4100.data(), _channel4100_str.data(), (_channel4100_str).length());
        tbl_Project_TD_6997933_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 3, _channel4100);
        int32_t _id4101 = _cs_call_center_sk1115;
        tbl_Project_TD_6997933_output.setInt32(i, 4, _id4101);
        tbl_Project_TD_6997933_output.setInt64(i, 0, _sales3562);
        tbl_Project_TD_6997933_output.setInt64(i, 1, _returns3564);
    }
    tbl_Project_TD_6997933_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_6997933_output #Row: " << tbl_Project_TD_6997933_output.getNumRow() << std::endl;
}

void SW_Project_TD_6172041(Table &tbl_JOIN_LEFTOUTER_TD_7746880_output, Table &tbl_Project_TD_6172041_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(coalesce(returns#3560, 0.00) AS returns#3546, CheckOverflow((promote_precision(cast(profit#3559 as decimal(18,2))) - promote_precision(cast(coalesce(profit_loss#3561, 0.00) as decimal(18,2)))), DecimalType(18,2), true) AS profit#3547, store channel AS channel#3768, s_store_sk#378 AS id#3769)
    // Input: ListBuffer(sales#3558, returns#3560, profit#3559, profit_loss#3561, s_store_sk#378)
    // Output: ListBuffer(sales#3558, returns#3546, profit#3547, channel#3768, id#3769)
    int nrow1 = tbl_JOIN_LEFTOUTER_TD_7746880_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sales3558 = tbl_JOIN_LEFTOUTER_TD_7746880_output.getInt64(i, 0);
        int64_t _returns3560 = tbl_JOIN_LEFTOUTER_TD_7746880_output.getInt64(i, 1);
        int64_t _profit3559 = tbl_JOIN_LEFTOUTER_TD_7746880_output.getInt64(i, 2);
        int64_t _profit_loss3561 = tbl_JOIN_LEFTOUTER_TD_7746880_output.getInt64(i, 3);
        int32_t _s_store_sk378 = tbl_JOIN_LEFTOUTER_TD_7746880_output.getInt32(i, 4);
        int64_t _returns3546 = _returns3560 != 0 ? _returns3560 : 0.00;
        tbl_Project_TD_6172041_output.setInt64(i, 1, _returns3546);
        int64_t _profit3547 = (_profit3559 - _profit_loss3561 != 0 ? _profit_loss3561 : 0.00);
        tbl_Project_TD_6172041_output.setInt64(i, 2, _profit3547);
        std::string _channel3768_str = "store channel";
        std::array<char, TPCDS_READ_MAX + 1> _channel3768{};
        memcpy(_channel3768.data(), _channel3768_str.data(), (_channel3768_str).length());
        tbl_Project_TD_6172041_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 3, _channel3768);
        int32_t _id3769 = _s_store_sk378;
        tbl_Project_TD_6172041_output.setInt32(i, 4, _id3769);
        tbl_Project_TD_6172041_output.setInt64(i, 0, _sales3558);
    }
    tbl_Project_TD_6172041_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_6172041_output #Row: " << tbl_Project_TD_6172041_output.getNumRow() << std::endl;
}

void SW_Union_TD_5775228(Table &tbl_Project_TD_6172041_output, Table &tbl_Project_TD_6997933_output, Table &tbl_Project_TD_6224311_output, Table &tbl_Union_TD_5775228_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Union
    // Operation: ListBuffer(List(UNION))
    // Output Table: ListBuffer(sales#3558, returns#3546, profit#3547, channel#3768, id#3769)
    int r = 0;
    int row0 = tbl_Project_TD_6172041_output.getNumRow();
    for (int i = 0; i < row0; i++) {
        tbl_Union_TD_5775228_output.setInt32(r, 0, tbl_Project_TD_6172041_output.getInt64(i, 0));
        tbl_Union_TD_5775228_output.setInt32(r, 1, tbl_Project_TD_6172041_output.getInt64(i, 1));
        tbl_Union_TD_5775228_output.setInt32(r, 2, tbl_Project_TD_6172041_output.getInt64(i, 2));
        std::array<char, TPCDS_READ_MAX + 1> _channel3768_n = tbl_Union_TD_5775228_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_Union_TD_5775228_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _channel3768_n);
        tbl_Union_TD_5775228_output.setInt32(r, 4, tbl_Project_TD_6172041_output.getInt32(i, 4));
        ++r;
    }
    int row1 = tbl_Project_TD_6997933_output.getNumRow();
    for (int i = 0; i < row1; i++) {
        tbl_Union_TD_5775228_output.setInt32(r, 0, tbl_Project_TD_6997933_output.getInt64(i, 0));
        tbl_Union_TD_5775228_output.setInt32(r, 1, tbl_Project_TD_6997933_output.getInt64(i, 1));
        tbl_Union_TD_5775228_output.setInt32(r, 2, tbl_Project_TD_6997933_output.getInt64(i, 2));
        std::array<char, TPCDS_READ_MAX + 1> _channel4100_n = tbl_Union_TD_5775228_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_Union_TD_5775228_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _channel4100_n);
        tbl_Union_TD_5775228_output.setInt32(r, 4, tbl_Project_TD_6997933_output.getInt32(i, 4));
        ++r;
    }
    int row2 = tbl_Project_TD_6224311_output.getNumRow();
    for (int i = 0; i < row2; i++) {
        tbl_Union_TD_5775228_output.setInt32(r, 0, tbl_Project_TD_6224311_output.getInt64(i, 0));
        tbl_Union_TD_5775228_output.setInt32(r, 1, tbl_Project_TD_6224311_output.getInt64(i, 1));
        tbl_Union_TD_5775228_output.setInt32(r, 2, tbl_Project_TD_6224311_output.getInt64(i, 2));
        std::array<char, TPCDS_READ_MAX + 1> _channel4102_n = tbl_Union_TD_5775228_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_Union_TD_5775228_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _channel4102_n);
        tbl_Union_TD_5775228_output.setInt32(r, 4, tbl_Project_TD_6224311_output.getInt32(i, 4));
        ++r;
    }
    tbl_Union_TD_5775228_output.setNumRow(r);
    std::cout << "tbl_Union_TD_5775228_output #Row: " << tbl_Union_TD_5775228_output.getNumRow() << std::endl;
}

void SW_Expand_TD_44392(Table &tbl_Union_TD_5775228_output, Table &tbl_Expand_TD_44392_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Expand
    // Operation: ListBuffer(Expand)
    // Input: ListBuffer(sales#3558, returns#3546, profit#3547, channel#3768, id#3769)
    // Output: ListBuffer(sales#3558, returns#3546, profit#3547, channel#3771, id#3772, spark_grouping_id#3770L)
    std::cout << "tbl_Expand_TD_44392_output #Row: " << tbl_Expand_TD_44392_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_3725792_key {
    std::string _channel3771;
    int32_t _id3772;
    int64_t _spark_grouping_id3770L;
    bool operator==(const SW_Aggregate_TD_3725792_key& other) const { return (_channel3771 == other._channel3771) && (_id3772 == other._id3772) && (_spark_grouping_id3770L == other._spark_grouping_id3770L); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_3725792_key> {
    std::size_t operator() (const SW_Aggregate_TD_3725792_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._channel3771)) + (hash<int32_t>()(k._id3772)) + (hash<int64_t>()(k._spark_grouping_id3770L));
    }
};
}
struct SW_Aggregate_TD_3725792_payload {
    int64_t _sales3555_sum_0;
    int64_t _returns3556_sum_1;
    int64_t _profit3557_sum_2;
};
void SW_Aggregate_TD_3725792(Table &tbl_Expand_TD_44392_output, Table &tbl_Aggregate_TD_3725792_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(channel#3771, id#3772, spark_grouping_id#3770L, sum(sales#3558) AS sales#3555, sum(returns#3546) AS returns#3556, sum(profit#3547) AS profit#3557)
    // Input: ListBuffer(sales#3558, returns#3546, profit#3547, channel#3771, id#3772, spark_grouping_id#3770L)
    // Output: ListBuffer(channel#3771, id#3772, sales#3555, returns#3556, profit#3557)
    std::unordered_map<SW_Aggregate_TD_3725792_key, SW_Aggregate_TD_3725792_payload> ht1;
    int nrow1 = tbl_Expand_TD_44392_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sales3558 = tbl_Expand_TD_44392_output.getInt64(i, 0);
        int64_t _returns3546 = tbl_Expand_TD_44392_output.getInt64(i, 1);
        int64_t _profit3547 = tbl_Expand_TD_44392_output.getInt64(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _channel3771 = tbl_Expand_TD_44392_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        int32_t _id3772 = tbl_Expand_TD_44392_output.getInt32(i, 4);
        int64_t _spark_grouping_id3770L = tbl_Expand_TD_44392_output.getInt64(i, 5);
        SW_Aggregate_TD_3725792_key k{std::string(_channel3771.data()), _id3772, _spark_grouping_id3770L};
        int64_t _sales3555_sum_0 = _sales3558;
        int64_t _returns3556_sum_1 = _returns3546;
        int64_t _profit3557_sum_2 = _profit3547;
        SW_Aggregate_TD_3725792_payload p{_sales3555_sum_0, _returns3556_sum_1, _profit3557_sum_2};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._sales3555_sum_0 + _sales3555_sum_0;
            p._sales3555_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._returns3556_sum_1 + _returns3556_sum_1;
            p._returns3556_sum_1 = sum_1;
            int64_t sum_2 = (it->second)._profit3557_sum_2 + _profit3557_sum_2;
            p._profit3557_sum_2 = sum_2;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _channel3771{};
        memcpy(_channel3771.data(), ((it.first)._channel3771).data(), ((it.first)._channel3771).length());
        tbl_Aggregate_TD_3725792_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _channel3771);
        tbl_Aggregate_TD_3725792_output.setInt32(r, 1, (it.first)._id3772);
        // _spark_grouping_id3770L not required in the output table
        int64_t _sales3555 = (it.second)._sales3555_sum_0;
        tbl_Aggregate_TD_3725792_output.setInt64(r, 2, _sales3555);
        int64_t _returns3556 = (it.second)._returns3556_sum_1;
        tbl_Aggregate_TD_3725792_output.setInt64(r, 3, _returns3556);
        int64_t _profit3557 = (it.second)._profit3557_sum_2;
        tbl_Aggregate_TD_3725792_output.setInt64(r, 4, _profit3557);
        ++r;
    }
    tbl_Aggregate_TD_3725792_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_3725792_output #Row: " << tbl_Aggregate_TD_3725792_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2219717(Table &tbl_Aggregate_TD_3725792_output, Table &tbl_Sort_TD_2219717_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(channel#3771 ASC NULLS FIRST, id#3772 ASC NULLS FIRST)
    // Input: ListBuffer(channel#3771, id#3772, sales#3555, returns#3556, profit#3557)
    // Output: ListBuffer(channel#3771, id#3772, sales#3555, returns#3556, profit#3557)
    struct SW_Sort_TD_2219717Row {
        std::string _channel3771;
        int32_t _id3772;
        int64_t _sales3555;
        int64_t _returns3556;
        int64_t _profit3557;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2219717Row& a, const SW_Sort_TD_2219717Row& b) const { return 
 (a._channel3771 < b._channel3771) || 
 ((a._channel3771 == b._channel3771) && (a._id3772 < b._id3772)); 
}
    }SW_Sort_TD_2219717_order; 

    int nrow1 = tbl_Aggregate_TD_3725792_output.getNumRow();
    std::vector<SW_Sort_TD_2219717Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _channel3771 = tbl_Aggregate_TD_3725792_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        int32_t _id3772 = tbl_Aggregate_TD_3725792_output.getInt32(i, 1);
        int64_t _sales3555 = tbl_Aggregate_TD_3725792_output.getInt64(i, 2);
        int64_t _returns3556 = tbl_Aggregate_TD_3725792_output.getInt64(i, 3);
        int64_t _profit3557 = tbl_Aggregate_TD_3725792_output.getInt64(i, 4);
        SW_Sort_TD_2219717Row t = {std::string(_channel3771.data()),_id3772,_sales3555,_returns3556,_profit3557};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2219717_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _channel3771{};
        memcpy(_channel3771.data(), (it._channel3771).data(), (it._channel3771).length());
        tbl_Sort_TD_2219717_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _channel3771);
        tbl_Sort_TD_2219717_output.setInt32(r, 1, it._id3772);
        tbl_Sort_TD_2219717_output.setInt64(r, 2, it._sales3555);
        tbl_Sort_TD_2219717_output.setInt64(r, 3, it._returns3556);
        tbl_Sort_TD_2219717_output.setInt64(r, 4, it._profit3557);
        ++r;
    }
    tbl_Sort_TD_2219717_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2219717_output #Row: " << tbl_Sort_TD_2219717_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1514409(Table &tbl_Sort_TD_2219717_output, Table &tbl_LocalLimit_TD_1514409_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(channel#3771, id#3772, sales#3555, returns#3556, profit#3557)
    // Output: ListBuffer(channel#3771, id#3772, sales#3555, returns#3556, profit#3557)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _channel3771_n = tbl_Sort_TD_2219717_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1514409_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _channel3771_n);
        tbl_LocalLimit_TD_1514409_output.setInt32(r, 1, tbl_Sort_TD_2219717_output.getInt32(i, 1));
        tbl_LocalLimit_TD_1514409_output.setInt64(r, 2, tbl_Sort_TD_2219717_output.getInt64(i, 2));
        tbl_LocalLimit_TD_1514409_output.setInt64(r, 3, tbl_Sort_TD_2219717_output.getInt64(i, 3));
        tbl_LocalLimit_TD_1514409_output.setInt64(r, 4, tbl_Sort_TD_2219717_output.getInt64(i, 4));
        r++;
    }
    tbl_LocalLimit_TD_1514409_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1514409_output #Row: " << tbl_LocalLimit_TD_1514409_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0369527(Table &tbl_LocalLimit_TD_1514409_output, Table &tbl_GlobalLimit_TD_0369527_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(channel#3771, id#3772, sales#3555, returns#3556, profit#3557)
    // Output: ListBuffer(channel#3771, id#3772, sales#3555, returns#3556, profit#3557)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _channel3771_n = tbl_LocalLimit_TD_1514409_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0369527_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _channel3771_n);
        tbl_GlobalLimit_TD_0369527_output.setInt32(r, 1, tbl_LocalLimit_TD_1514409_output.getInt32(i, 1));
        tbl_GlobalLimit_TD_0369527_output.setInt64(r, 2, tbl_LocalLimit_TD_1514409_output.getInt64(i, 2));
        tbl_GlobalLimit_TD_0369527_output.setInt64(r, 3, tbl_LocalLimit_TD_1514409_output.getInt64(i, 3));
        tbl_GlobalLimit_TD_0369527_output.setInt64(r, 4, tbl_LocalLimit_TD_1514409_output.getInt64(i, 4));
        r++;
    }
    tbl_GlobalLimit_TD_0369527_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0369527_output #Row: " << tbl_GlobalLimit_TD_0369527_output.getNumRow() << std::endl;
}

