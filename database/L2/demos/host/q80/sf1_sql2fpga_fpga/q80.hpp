#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_12258539(Table &tbl_SerializeFromObject_TD_13519132_input, Table &tbl_Filter_TD_12258539_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(wr_item_sk#833) AND isnotnull(wr_order_number#844L)))
    // Input: ListBuffer(wr_item_sk#833, wr_order_number#844L, wr_return_amt#846, wr_net_loss#854)
    // Output: ListBuffer(wr_item_sk#833, wr_order_number#844L, wr_return_amt#846, wr_net_loss#854)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13519132_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _wr_item_sk833 = tbl_SerializeFromObject_TD_13519132_input.getInt32(i, 0);
        int64_t _wr_order_number844L = tbl_SerializeFromObject_TD_13519132_input.getInt64(i, 1);
        if ((_wr_item_sk833!= 0) && (_wr_order_number844L!= 0)) {
            int32_t _wr_item_sk833_t = tbl_SerializeFromObject_TD_13519132_input.getInt32(i, 0);
            tbl_Filter_TD_12258539_output.setInt32(r, 0, _wr_item_sk833_t);
            int64_t _wr_order_number844L_t = tbl_SerializeFromObject_TD_13519132_input.getInt64(i, 1);
            tbl_Filter_TD_12258539_output.setInt64(r, 1, _wr_order_number844L_t);
            int64_t _wr_return_amt846_t = tbl_SerializeFromObject_TD_13519132_input.getInt64(i, 2);
            tbl_Filter_TD_12258539_output.setInt64(r, 2, _wr_return_amt846_t);
            int64_t _wr_net_loss854_t = tbl_SerializeFromObject_TD_13519132_input.getInt64(i, 3);
            tbl_Filter_TD_12258539_output.setInt64(r, 3, _wr_net_loss854_t);
            r++;
        }
    }
    tbl_Filter_TD_12258539_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12258539_output #Row: " << tbl_Filter_TD_12258539_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12385515(Table &tbl_SerializeFromObject_TD_1336654_input, Table &tbl_Filter_TD_12385515_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(ws_sold_date_sk#729) AND isnotnull(ws_web_site_sk#742)) AND isnotnull(ws_item_sk#732)) AND isnotnull(ws_promo_sk#745)))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_web_site_sk#742, ws_promo_sk#745, ws_order_number#746L, ws_ext_sales_price#752, ws_net_profit#762)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_web_site_sk#742, ws_promo_sk#745, ws_order_number#746L, ws_ext_sales_price#752, ws_net_profit#762)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1336654_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_1336654_input.getInt32(i, 0);
        int32_t _ws_web_site_sk742 = tbl_SerializeFromObject_TD_1336654_input.getInt32(i, 2);
        int32_t _ws_item_sk732 = tbl_SerializeFromObject_TD_1336654_input.getInt32(i, 1);
        int32_t _ws_promo_sk745 = tbl_SerializeFromObject_TD_1336654_input.getInt32(i, 3);
        if ((((_ws_sold_date_sk729!= 0) && (_ws_web_site_sk742!= 0)) && (_ws_item_sk732!= 0)) && (_ws_promo_sk745!= 0)) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_1336654_input.getInt32(i, 0);
            tbl_Filter_TD_12385515_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_item_sk732_t = tbl_SerializeFromObject_TD_1336654_input.getInt32(i, 1);
            tbl_Filter_TD_12385515_output.setInt32(r, 1, _ws_item_sk732_t);
            int32_t _ws_web_site_sk742_t = tbl_SerializeFromObject_TD_1336654_input.getInt32(i, 2);
            tbl_Filter_TD_12385515_output.setInt32(r, 2, _ws_web_site_sk742_t);
            int32_t _ws_promo_sk745_t = tbl_SerializeFromObject_TD_1336654_input.getInt32(i, 3);
            tbl_Filter_TD_12385515_output.setInt32(r, 3, _ws_promo_sk745_t);
            int64_t _ws_order_number746L_t = tbl_SerializeFromObject_TD_1336654_input.getInt64(i, 4);
            tbl_Filter_TD_12385515_output.setInt64(r, 4, _ws_order_number746L_t);
            int64_t _ws_ext_sales_price752_t = tbl_SerializeFromObject_TD_1336654_input.getInt64(i, 5);
            tbl_Filter_TD_12385515_output.setInt64(r, 5, _ws_ext_sales_price752_t);
            int64_t _ws_net_profit762_t = tbl_SerializeFromObject_TD_1336654_input.getInt64(i, 6);
            tbl_Filter_TD_12385515_output.setInt64(r, 6, _ws_net_profit762_t);
            r++;
        }
    }
    tbl_Filter_TD_12385515_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12385515_output #Row: " << tbl_Filter_TD_12385515_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12846373(Table &tbl_SerializeFromObject_TD_13541115_input, Table &tbl_Filter_TD_12846373_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cr_item_sk#1025) AND isnotnull(cr_order_number#1039L)))
    // Input: ListBuffer(cr_item_sk#1025, cr_order_number#1039L, cr_return_amount#1041, cr_net_loss#1049)
    // Output: ListBuffer(cr_item_sk#1025, cr_order_number#1039L, cr_return_amount#1041, cr_net_loss#1049)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13541115_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cr_item_sk1025 = tbl_SerializeFromObject_TD_13541115_input.getInt32(i, 0);
        int64_t _cr_order_number1039L = tbl_SerializeFromObject_TD_13541115_input.getInt64(i, 1);
        if ((_cr_item_sk1025!= 0) && (_cr_order_number1039L!= 0)) {
            int32_t _cr_item_sk1025_t = tbl_SerializeFromObject_TD_13541115_input.getInt32(i, 0);
            tbl_Filter_TD_12846373_output.setInt32(r, 0, _cr_item_sk1025_t);
            int64_t _cr_order_number1039L_t = tbl_SerializeFromObject_TD_13541115_input.getInt64(i, 1);
            tbl_Filter_TD_12846373_output.setInt64(r, 1, _cr_order_number1039L_t);
            int64_t _cr_return_amount1041_t = tbl_SerializeFromObject_TD_13541115_input.getInt64(i, 2);
            tbl_Filter_TD_12846373_output.setInt64(r, 2, _cr_return_amount1041_t);
            int64_t _cr_net_loss1049_t = tbl_SerializeFromObject_TD_13541115_input.getInt64(i, 3);
            tbl_Filter_TD_12846373_output.setInt64(r, 3, _cr_net_loss1049_t);
            r++;
        }
    }
    tbl_Filter_TD_12846373_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12846373_output #Row: " << tbl_Filter_TD_12846373_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12684117(Table &tbl_SerializeFromObject_TD_13787663_input, Table &tbl_Filter_TD_12684117_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(cs_sold_date_sk#1104) AND isnotnull(cs_catalog_page_sk#1116)) AND isnotnull(cs_item_sk#1119)) AND isnotnull(cs_promo_sk#1120)))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_catalog_page_sk#1116, cs_item_sk#1119, cs_promo_sk#1120, cs_order_number#1121L, cs_ext_sales_price#1127, cs_net_profit#1137)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_catalog_page_sk#1116, cs_item_sk#1119, cs_promo_sk#1120, cs_order_number#1121L, cs_ext_sales_price#1127, cs_net_profit#1137)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13787663_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_13787663_input.getInt32(i, 0);
        int32_t _cs_catalog_page_sk1116 = tbl_SerializeFromObject_TD_13787663_input.getInt32(i, 1);
        int32_t _cs_item_sk1119 = tbl_SerializeFromObject_TD_13787663_input.getInt32(i, 2);
        int32_t _cs_promo_sk1120 = tbl_SerializeFromObject_TD_13787663_input.getInt32(i, 3);
        if ((((_cs_sold_date_sk1104!= 0) && (_cs_catalog_page_sk1116!= 0)) && (_cs_item_sk1119!= 0)) && (_cs_promo_sk1120!= 0)) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_13787663_input.getInt32(i, 0);
            tbl_Filter_TD_12684117_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int32_t _cs_catalog_page_sk1116_t = tbl_SerializeFromObject_TD_13787663_input.getInt32(i, 1);
            tbl_Filter_TD_12684117_output.setInt32(r, 1, _cs_catalog_page_sk1116_t);
            int32_t _cs_item_sk1119_t = tbl_SerializeFromObject_TD_13787663_input.getInt32(i, 2);
            tbl_Filter_TD_12684117_output.setInt32(r, 2, _cs_item_sk1119_t);
            int32_t _cs_promo_sk1120_t = tbl_SerializeFromObject_TD_13787663_input.getInt32(i, 3);
            tbl_Filter_TD_12684117_output.setInt32(r, 3, _cs_promo_sk1120_t);
            int64_t _cs_order_number1121L_t = tbl_SerializeFromObject_TD_13787663_input.getInt64(i, 4);
            tbl_Filter_TD_12684117_output.setInt64(r, 4, _cs_order_number1121L_t);
            int64_t _cs_ext_sales_price1127_t = tbl_SerializeFromObject_TD_13787663_input.getInt64(i, 5);
            tbl_Filter_TD_12684117_output.setInt64(r, 5, _cs_ext_sales_price1127_t);
            int64_t _cs_net_profit1137_t = tbl_SerializeFromObject_TD_13787663_input.getInt64(i, 6);
            tbl_Filter_TD_12684117_output.setInt64(r, 6, _cs_net_profit1137_t);
            r++;
        }
    }
    tbl_Filter_TD_12684117_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12684117_output #Row: " << tbl_Filter_TD_12684117_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12737824(Table &tbl_SerializeFromObject_TD_13406148_input, Table &tbl_Filter_TD_12737824_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(sr_item_sk#671) AND isnotnull(sr_ticket_number#678L)))
    // Input: ListBuffer(sr_item_sk#671, sr_ticket_number#678L, sr_return_amt#680, sr_net_loss#688)
    // Output: ListBuffer(sr_item_sk#671, sr_ticket_number#678L, sr_return_amt#680, sr_net_loss#688)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13406148_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _sr_item_sk671 = tbl_SerializeFromObject_TD_13406148_input.getInt32(i, 0);
        int64_t _sr_ticket_number678L = tbl_SerializeFromObject_TD_13406148_input.getInt64(i, 1);
        if ((_sr_item_sk671!= 0) && (_sr_ticket_number678L!= 0)) {
            int32_t _sr_item_sk671_t = tbl_SerializeFromObject_TD_13406148_input.getInt32(i, 0);
            tbl_Filter_TD_12737824_output.setInt32(r, 0, _sr_item_sk671_t);
            int64_t _sr_ticket_number678L_t = tbl_SerializeFromObject_TD_13406148_input.getInt64(i, 1);
            tbl_Filter_TD_12737824_output.setInt64(r, 1, _sr_ticket_number678L_t);
            int64_t _sr_return_amt680_t = tbl_SerializeFromObject_TD_13406148_input.getInt64(i, 2);
            tbl_Filter_TD_12737824_output.setInt64(r, 2, _sr_return_amt680_t);
            int64_t _sr_net_loss688_t = tbl_SerializeFromObject_TD_13406148_input.getInt64(i, 3);
            tbl_Filter_TD_12737824_output.setInt64(r, 3, _sr_net_loss688_t);
            r++;
        }
    }
    tbl_Filter_TD_12737824_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12737824_output #Row: " << tbl_Filter_TD_12737824_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12213268(Table &tbl_SerializeFromObject_TD_13474202_input, Table &tbl_Filter_TD_12213268_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(ss_sold_date_sk#1206) AND isnotnull(ss_store_sk#1213)) AND isnotnull(ss_item_sk#1208)) AND isnotnull(ss_promo_sk#1214)))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_store_sk#1213, ss_promo_sk#1214, ss_ticket_number#1215L, ss_ext_sales_price#1221, ss_net_profit#1228)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_store_sk#1213, ss_promo_sk#1214, ss_ticket_number#1215L, ss_ext_sales_price#1221, ss_net_profit#1228)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13474202_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_13474202_input.getInt32(i, 0);
        int32_t _ss_store_sk1213 = tbl_SerializeFromObject_TD_13474202_input.getInt32(i, 2);
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_13474202_input.getInt32(i, 1);
        int32_t _ss_promo_sk1214 = tbl_SerializeFromObject_TD_13474202_input.getInt32(i, 3);
        if ((((_ss_sold_date_sk1206!= 0) && (_ss_store_sk1213!= 0)) && (_ss_item_sk1208!= 0)) && (_ss_promo_sk1214!= 0)) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_13474202_input.getInt32(i, 0);
            tbl_Filter_TD_12213268_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_13474202_input.getInt32(i, 1);
            tbl_Filter_TD_12213268_output.setInt32(r, 1, _ss_item_sk1208_t);
            int32_t _ss_store_sk1213_t = tbl_SerializeFromObject_TD_13474202_input.getInt32(i, 2);
            tbl_Filter_TD_12213268_output.setInt32(r, 2, _ss_store_sk1213_t);
            int32_t _ss_promo_sk1214_t = tbl_SerializeFromObject_TD_13474202_input.getInt32(i, 3);
            tbl_Filter_TD_12213268_output.setInt32(r, 3, _ss_promo_sk1214_t);
            int64_t _ss_ticket_number1215L_t = tbl_SerializeFromObject_TD_13474202_input.getInt64(i, 4);
            tbl_Filter_TD_12213268_output.setInt64(r, 4, _ss_ticket_number1215L_t);
            int64_t _ss_ext_sales_price1221_t = tbl_SerializeFromObject_TD_13474202_input.getInt64(i, 5);
            tbl_Filter_TD_12213268_output.setInt64(r, 5, _ss_ext_sales_price1221_t);
            int64_t _ss_net_profit1228_t = tbl_SerializeFromObject_TD_13474202_input.getInt64(i, 6);
            tbl_Filter_TD_12213268_output.setInt64(r, 6, _ss_net_profit1228_t);
            r++;
        }
    }
    tbl_Filter_TD_12213268_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12213268_output #Row: " << tbl_Filter_TD_12213268_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11839303(Table &tbl_SerializeFromObject_TD_12523840_input, Table &tbl_Filter_TD_11839303_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_date#4644) AND ((d_date#4644 >= 2000-08-23) AND (d_date#4644 <= 2000-09-22))) AND isnotnull(d_date_sk#4642)))
    // Input: ListBuffer(d_date_sk#4642, d_date#4644)
    // Output: ListBuffer(d_date_sk#4642)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12523840_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date4644 = tbl_SerializeFromObject_TD_12523840_input.getInt32(i, 1);
        int32_t _d_date_sk4642 = tbl_SerializeFromObject_TD_12523840_input.getInt32(i, 0);
        if (((_d_date4644!= 0) && ((_d_date4644 >= 20000823) && (_d_date4644 <= 20000922))) && (_d_date_sk4642!= 0)) {
            int32_t _d_date_sk4642_t = tbl_SerializeFromObject_TD_12523840_input.getInt32(i, 0);
            tbl_Filter_TD_11839303_output.setInt32(r, 0, _d_date_sk4642_t);
            r++;
        }
    }
    tbl_Filter_TD_11839303_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11839303_output #Row: " << tbl_Filter_TD_11839303_output.getNumRow() << std::endl;
}


void SW_Filter_TD_11592606(Table &tbl_SerializeFromObject_TD_12852394_input, Table &tbl_Filter_TD_11592606_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_date#4575) AND ((d_date#4575 >= 2000-08-23) AND (d_date#4575 <= 2000-09-22))) AND isnotnull(d_date_sk#4573)))
    // Input: ListBuffer(d_date_sk#4573, d_date#4575)
    // Output: ListBuffer(d_date_sk#4573)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12852394_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date4575 = tbl_SerializeFromObject_TD_12852394_input.getInt32(i, 1);
        int32_t _d_date_sk4573 = tbl_SerializeFromObject_TD_12852394_input.getInt32(i, 0);
        if (((_d_date4575!= 0) && ((_d_date4575 >= 20000823) && (_d_date4575 <= 20000922))) && (_d_date_sk4573!= 0)) {
            int32_t _d_date_sk4573_t = tbl_SerializeFromObject_TD_12852394_input.getInt32(i, 0);
            tbl_Filter_TD_11592606_output.setInt32(r, 0, _d_date_sk4573_t);
            r++;
        }
    }
    tbl_Filter_TD_11592606_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11592606_output #Row: " << tbl_Filter_TD_11592606_output.getNumRow() << std::endl;
}


void SW_Filter_TD_11838376(Table &tbl_SerializeFromObject_TD_12875359_input, Table &tbl_Filter_TD_11838376_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_date#122) AND ((d_date#122 >= 2000-08-23) AND (d_date#122 <= 2000-09-22))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_date#122)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12875359_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date122 = tbl_SerializeFromObject_TD_12875359_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_12875359_input.getInt32(i, 0);
        if (((_d_date122!= 0) && ((_d_date122 >= 20000823) && (_d_date122 <= 20000922))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_12875359_input.getInt32(i, 0);
            tbl_Filter_TD_11838376_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_11838376_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11838376_output #Row: " << tbl_Filter_TD_11838376_output.getNumRow() << std::endl;
}


void SW_Filter_TD_10449479(Table &tbl_SerializeFromObject_TD_11102949_input, Table &tbl_Filter_TD_10449479_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(web_site_sk#537))
    // Input: ListBuffer(web_site_sk#537, web_site_id#538)
    // Output: ListBuffer(web_site_sk#537, web_site_id#538)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11102949_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _web_site_sk537 = tbl_SerializeFromObject_TD_11102949_input.getInt32(i, 0);
        if (_web_site_sk537!= 0) {
            int32_t _web_site_sk537_t = tbl_SerializeFromObject_TD_11102949_input.getInt32(i, 0);
            tbl_Filter_TD_10449479_output.setInt32(r, 0, _web_site_sk537_t);
            std::array<char, TPCDS_READ_MAX + 1> _web_site_id538_t = tbl_SerializeFromObject_TD_11102949_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_10449479_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _web_site_id538_t);
            r++;
        }
    }
    tbl_Filter_TD_10449479_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10449479_output #Row: " << tbl_Filter_TD_10449479_output.getNumRow() << std::endl;
}


void SW_Filter_TD_10805972(Table &tbl_SerializeFromObject_TD_11468781_input, Table &tbl_Filter_TD_10805972_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(cp_catalog_page_sk#996))
    // Input: ListBuffer(cp_catalog_page_sk#996, cp_catalog_page_id#997)
    // Output: ListBuffer(cp_catalog_page_sk#996, cp_catalog_page_id#997)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11468781_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cp_catalog_page_sk996 = tbl_SerializeFromObject_TD_11468781_input.getInt32(i, 0);
        if (_cp_catalog_page_sk996!= 0) {
            int32_t _cp_catalog_page_sk996_t = tbl_SerializeFromObject_TD_11468781_input.getInt32(i, 0);
            tbl_Filter_TD_10805972_output.setInt32(r, 0, _cp_catalog_page_sk996_t);
            std::array<char, TPCDS_READ_MAX + 1> _cp_catalog_page_id997_t = tbl_SerializeFromObject_TD_11468781_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_10805972_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _cp_catalog_page_id997_t);
            r++;
        }
    }
    tbl_Filter_TD_10805972_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10805972_output #Row: " << tbl_Filter_TD_10805972_output.getNumRow() << std::endl;
}


void SW_Filter_TD_10841618(Table &tbl_SerializeFromObject_TD_11546211_input, Table &tbl_Filter_TD_10841618_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(s_store_sk#378))
    // Input: ListBuffer(s_store_sk#378, s_store_id#379)
    // Output: ListBuffer(s_store_sk#378, s_store_id#379)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11546211_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _s_store_sk378 = tbl_SerializeFromObject_TD_11546211_input.getInt32(i, 0);
        if (_s_store_sk378!= 0) {
            int32_t _s_store_sk378_t = tbl_SerializeFromObject_TD_11546211_input.getInt32(i, 0);
            tbl_Filter_TD_10841618_output.setInt32(r, 0, _s_store_sk378_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_t = tbl_SerializeFromObject_TD_11546211_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_10841618_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_store_id379_t);
            r++;
        }
    }
    tbl_Filter_TD_10841618_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10841618_output #Row: " << tbl_Filter_TD_10841618_output.getNumRow() << std::endl;
}


void SW_Filter_TD_9570177(Table &tbl_SerializeFromObject_TD_10615885_input, Table &tbl_Filter_TD_9570177_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(i_current_price#4675) AND (i_current_price#4675 > 50.00)) AND isnotnull(i_item_sk#4670)))
    // Input: ListBuffer(i_item_sk#4670, i_current_price#4675)
    // Output: ListBuffer(i_item_sk#4670)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10615885_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _i_current_price4675 = tbl_SerializeFromObject_TD_10615885_input.getInt64(i, 1);
        int32_t _i_item_sk4670 = tbl_SerializeFromObject_TD_10615885_input.getInt32(i, 0);
        if (((_i_current_price4675!= 0) && (_i_current_price4675 > 50.00)) && (_i_item_sk4670!= 0)) {
            int32_t _i_item_sk4670_t = tbl_SerializeFromObject_TD_10615885_input.getInt32(i, 0);
            tbl_Filter_TD_9570177_output.setInt32(r, 0, _i_item_sk4670_t);
            r++;
        }
    }
    tbl_Filter_TD_9570177_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9570177_output #Row: " << tbl_Filter_TD_9570177_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_9261141_key_leftMajor {
    int32_t _ws_web_site_sk742;
    bool operator==(const SW_JOIN_INNER_TD_9261141_key_leftMajor& other) const {
        return ((_ws_web_site_sk742 == other._ws_web_site_sk742));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9261141_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9261141_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_web_site_sk742));
    }
};
}
struct SW_JOIN_INNER_TD_9261141_payload_leftMajor {
    int32_t _ws_item_sk732;
    int32_t _ws_web_site_sk742;
    int32_t _ws_promo_sk745;
    int64_t _ws_ext_sales_price752;
    int64_t _ws_net_profit762;
    int64_t _wr_return_amt846;
    int64_t _wr_net_loss854;
};
struct SW_JOIN_INNER_TD_9261141_key_rightMajor {
    int32_t _web_site_sk537;
    bool operator==(const SW_JOIN_INNER_TD_9261141_key_rightMajor& other) const {
        return ((_web_site_sk537 == other._web_site_sk537));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9261141_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9261141_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._web_site_sk537));
    }
};
}
struct SW_JOIN_INNER_TD_9261141_payload_rightMajor {
    int32_t _web_site_sk537;
    std::string _web_site_id538;
};
void SW_JOIN_INNER_TD_9261141(Table &tbl_JOIN_INNER_TD_10161275_output, Table &tbl_Filter_TD_10449479_output, Table &tbl_JOIN_INNER_TD_9261141_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_web_site_sk#742 = web_site_sk#537))
    // Left Table: ListBuffer(ws_item_sk#732, ws_web_site_sk#742, ws_promo_sk#745, ws_ext_sales_price#752, ws_net_profit#762, wr_return_amt#846, wr_net_loss#854)
    // Right Table: ListBuffer(web_site_sk#537, web_site_id#538)
    // Output Table: ListBuffer(ws_item_sk#732, ws_promo_sk#745, ws_ext_sales_price#752, ws_net_profit#762, wr_return_amt#846, wr_net_loss#854, web_site_id#538)
    int left_nrow = tbl_JOIN_INNER_TD_10161275_output.getNumRow();
    int right_nrow = tbl_Filter_TD_10449479_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9261141_key_leftMajor, SW_JOIN_INNER_TD_9261141_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_10161275_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_web_site_sk742_k = tbl_JOIN_INNER_TD_10161275_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_9261141_key_leftMajor keyA{_ws_web_site_sk742_k};
            int32_t _ws_item_sk732 = tbl_JOIN_INNER_TD_10161275_output.getInt32(i, 0);
            int32_t _ws_web_site_sk742 = tbl_JOIN_INNER_TD_10161275_output.getInt32(i, 1);
            int32_t _ws_promo_sk745 = tbl_JOIN_INNER_TD_10161275_output.getInt32(i, 2);
            int64_t _ws_ext_sales_price752 = tbl_JOIN_INNER_TD_10161275_output.getInt64(i, 3);
            int64_t _ws_net_profit762 = tbl_JOIN_INNER_TD_10161275_output.getInt64(i, 4);
            int64_t _wr_return_amt846 = tbl_JOIN_INNER_TD_10161275_output.getInt64(i, 5);
            int64_t _wr_net_loss854 = tbl_JOIN_INNER_TD_10161275_output.getInt64(i, 6);
            SW_JOIN_INNER_TD_9261141_payload_leftMajor payloadA{_ws_item_sk732, _ws_web_site_sk742, _ws_promo_sk745, _ws_ext_sales_price752, _ws_net_profit762, _wr_return_amt846, _wr_net_loss854};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_10449479_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _web_site_sk537_k = tbl_Filter_TD_10449479_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9261141_key_leftMajor{_web_site_sk537_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_item_sk732 = (it->second)._ws_item_sk732;
                int32_t _ws_web_site_sk742 = (it->second)._ws_web_site_sk742;
                int32_t _ws_promo_sk745 = (it->second)._ws_promo_sk745;
                int64_t _ws_ext_sales_price752 = (it->second)._ws_ext_sales_price752;
                int64_t _ws_net_profit762 = (it->second)._ws_net_profit762;
                int64_t _wr_return_amt846 = (it->second)._wr_return_amt846;
                int64_t _wr_net_loss854 = (it->second)._wr_net_loss854;
                int32_t _web_site_sk537 = tbl_Filter_TD_10449479_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _web_site_id538_n = tbl_Filter_TD_10449479_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _web_site_id538 = std::string(_web_site_id538_n.data());
                tbl_JOIN_INNER_TD_9261141_output.setInt32(r, 0, _ws_item_sk732);
                tbl_JOIN_INNER_TD_9261141_output.setInt32(r, 1, _ws_promo_sk745);
                tbl_JOIN_INNER_TD_9261141_output.setInt64(r, 2, _ws_ext_sales_price752);
                tbl_JOIN_INNER_TD_9261141_output.setInt64(r, 3, _ws_net_profit762);
                tbl_JOIN_INNER_TD_9261141_output.setInt64(r, 4, _wr_return_amt846);
                tbl_JOIN_INNER_TD_9261141_output.setInt64(r, 5, _wr_net_loss854);
                tbl_JOIN_INNER_TD_9261141_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _web_site_id538_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9261141_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9261141_key_rightMajor, SW_JOIN_INNER_TD_9261141_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_10449479_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _web_site_sk537_k = tbl_Filter_TD_10449479_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_9261141_key_rightMajor keyA{_web_site_sk537_k};
            int32_t _web_site_sk537 = tbl_Filter_TD_10449479_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _web_site_id538_n = tbl_Filter_TD_10449479_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _web_site_id538 = std::string(_web_site_id538_n.data());
            SW_JOIN_INNER_TD_9261141_payload_rightMajor payloadA{_web_site_sk537, _web_site_id538};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_10161275_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_web_site_sk742_k = tbl_JOIN_INNER_TD_10161275_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9261141_key_rightMajor{_ws_web_site_sk742_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _web_site_sk537 = (it->second)._web_site_sk537;
                std::string _web_site_id538 = (it->second)._web_site_id538;
                std::array<char, TPCDS_READ_MAX + 1> _web_site_id538_n{};
                memcpy(_web_site_id538_n.data(), (_web_site_id538).data(), (_web_site_id538).length());
                int32_t _ws_item_sk732 = tbl_JOIN_INNER_TD_10161275_output.getInt32(i, 0);
                int32_t _ws_web_site_sk742 = tbl_JOIN_INNER_TD_10161275_output.getInt32(i, 1);
                int32_t _ws_promo_sk745 = tbl_JOIN_INNER_TD_10161275_output.getInt32(i, 2);
                int64_t _ws_ext_sales_price752 = tbl_JOIN_INNER_TD_10161275_output.getInt64(i, 3);
                int64_t _ws_net_profit762 = tbl_JOIN_INNER_TD_10161275_output.getInt64(i, 4);
                int64_t _wr_return_amt846 = tbl_JOIN_INNER_TD_10161275_output.getInt64(i, 5);
                int64_t _wr_net_loss854 = tbl_JOIN_INNER_TD_10161275_output.getInt64(i, 6);
                tbl_JOIN_INNER_TD_9261141_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _web_site_id538_n);
                tbl_JOIN_INNER_TD_9261141_output.setInt32(r, 0, _ws_item_sk732);
                tbl_JOIN_INNER_TD_9261141_output.setInt32(r, 1, _ws_promo_sk745);
                tbl_JOIN_INNER_TD_9261141_output.setInt64(r, 2, _ws_ext_sales_price752);
                tbl_JOIN_INNER_TD_9261141_output.setInt64(r, 3, _ws_net_profit762);
                tbl_JOIN_INNER_TD_9261141_output.setInt64(r, 4, _wr_return_amt846);
                tbl_JOIN_INNER_TD_9261141_output.setInt64(r, 5, _wr_net_loss854);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9261141_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_9261141_output #Row: " << tbl_JOIN_INNER_TD_9261141_output.getNumRow() << std::endl;
}

void SW_Filter_TD_949741(Table &tbl_SerializeFromObject_TD_10840973_input, Table &tbl_Filter_TD_949741_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(i_current_price#4606) AND (i_current_price#4606 > 50.00)) AND isnotnull(i_item_sk#4601)))
    // Input: ListBuffer(i_item_sk#4601, i_current_price#4606)
    // Output: ListBuffer(i_item_sk#4601)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10840973_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _i_current_price4606 = tbl_SerializeFromObject_TD_10840973_input.getInt64(i, 1);
        int32_t _i_item_sk4601 = tbl_SerializeFromObject_TD_10840973_input.getInt32(i, 0);
        if (((_i_current_price4606!= 0) && (_i_current_price4606 > 50.00)) && (_i_item_sk4601!= 0)) {
            int32_t _i_item_sk4601_t = tbl_SerializeFromObject_TD_10840973_input.getInt32(i, 0);
            tbl_Filter_TD_949741_output.setInt32(r, 0, _i_item_sk4601_t);
            r++;
        }
    }
    tbl_Filter_TD_949741_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_949741_output #Row: " << tbl_Filter_TD_949741_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_9809851_key_leftMajor {
    int32_t _cs_catalog_page_sk1116;
    bool operator==(const SW_JOIN_INNER_TD_9809851_key_leftMajor& other) const {
        return ((_cs_catalog_page_sk1116 == other._cs_catalog_page_sk1116));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9809851_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9809851_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_catalog_page_sk1116));
    }
};
}
struct SW_JOIN_INNER_TD_9809851_payload_leftMajor {
    int32_t _cs_catalog_page_sk1116;
    int32_t _cs_item_sk1119;
    int32_t _cs_promo_sk1120;
    int64_t _cs_ext_sales_price1127;
    int64_t _cs_net_profit1137;
    int64_t _cr_return_amount1041;
    int64_t _cr_net_loss1049;
};
struct SW_JOIN_INNER_TD_9809851_key_rightMajor {
    int32_t _cp_catalog_page_sk996;
    bool operator==(const SW_JOIN_INNER_TD_9809851_key_rightMajor& other) const {
        return ((_cp_catalog_page_sk996 == other._cp_catalog_page_sk996));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9809851_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9809851_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cp_catalog_page_sk996));
    }
};
}
struct SW_JOIN_INNER_TD_9809851_payload_rightMajor {
    int32_t _cp_catalog_page_sk996;
    std::string _cp_catalog_page_id997;
};
void SW_JOIN_INNER_TD_9809851(Table &tbl_JOIN_INNER_TD_10664187_output, Table &tbl_Filter_TD_10805972_output, Table &tbl_JOIN_INNER_TD_9809851_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_catalog_page_sk#1116 = cp_catalog_page_sk#996))
    // Left Table: ListBuffer(cs_catalog_page_sk#1116, cs_item_sk#1119, cs_promo_sk#1120, cs_ext_sales_price#1127, cs_net_profit#1137, cr_return_amount#1041, cr_net_loss#1049)
    // Right Table: ListBuffer(cp_catalog_page_sk#996, cp_catalog_page_id#997)
    // Output Table: ListBuffer(cs_item_sk#1119, cs_promo_sk#1120, cs_ext_sales_price#1127, cs_net_profit#1137, cr_return_amount#1041, cr_net_loss#1049, cp_catalog_page_id#997)
    int left_nrow = tbl_JOIN_INNER_TD_10664187_output.getNumRow();
    int right_nrow = tbl_Filter_TD_10805972_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9809851_key_leftMajor, SW_JOIN_INNER_TD_9809851_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_10664187_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_catalog_page_sk1116_k = tbl_JOIN_INNER_TD_10664187_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_9809851_key_leftMajor keyA{_cs_catalog_page_sk1116_k};
            int32_t _cs_catalog_page_sk1116 = tbl_JOIN_INNER_TD_10664187_output.getInt32(i, 0);
            int32_t _cs_item_sk1119 = tbl_JOIN_INNER_TD_10664187_output.getInt32(i, 1);
            int32_t _cs_promo_sk1120 = tbl_JOIN_INNER_TD_10664187_output.getInt32(i, 2);
            int64_t _cs_ext_sales_price1127 = tbl_JOIN_INNER_TD_10664187_output.getInt64(i, 3);
            int64_t _cs_net_profit1137 = tbl_JOIN_INNER_TD_10664187_output.getInt64(i, 4);
            int64_t _cr_return_amount1041 = tbl_JOIN_INNER_TD_10664187_output.getInt64(i, 5);
            int64_t _cr_net_loss1049 = tbl_JOIN_INNER_TD_10664187_output.getInt64(i, 6);
            SW_JOIN_INNER_TD_9809851_payload_leftMajor payloadA{_cs_catalog_page_sk1116, _cs_item_sk1119, _cs_promo_sk1120, _cs_ext_sales_price1127, _cs_net_profit1137, _cr_return_amount1041, _cr_net_loss1049};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_10805972_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cp_catalog_page_sk996_k = tbl_Filter_TD_10805972_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9809851_key_leftMajor{_cp_catalog_page_sk996_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_catalog_page_sk1116 = (it->second)._cs_catalog_page_sk1116;
                int32_t _cs_item_sk1119 = (it->second)._cs_item_sk1119;
                int32_t _cs_promo_sk1120 = (it->second)._cs_promo_sk1120;
                int64_t _cs_ext_sales_price1127 = (it->second)._cs_ext_sales_price1127;
                int64_t _cs_net_profit1137 = (it->second)._cs_net_profit1137;
                int64_t _cr_return_amount1041 = (it->second)._cr_return_amount1041;
                int64_t _cr_net_loss1049 = (it->second)._cr_net_loss1049;
                int32_t _cp_catalog_page_sk996 = tbl_Filter_TD_10805972_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _cp_catalog_page_id997_n = tbl_Filter_TD_10805972_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _cp_catalog_page_id997 = std::string(_cp_catalog_page_id997_n.data());
                tbl_JOIN_INNER_TD_9809851_output.setInt32(r, 0, _cs_item_sk1119);
                tbl_JOIN_INNER_TD_9809851_output.setInt32(r, 1, _cs_promo_sk1120);
                tbl_JOIN_INNER_TD_9809851_output.setInt64(r, 2, _cs_ext_sales_price1127);
                tbl_JOIN_INNER_TD_9809851_output.setInt64(r, 3, _cs_net_profit1137);
                tbl_JOIN_INNER_TD_9809851_output.setInt64(r, 4, _cr_return_amount1041);
                tbl_JOIN_INNER_TD_9809851_output.setInt64(r, 5, _cr_net_loss1049);
                tbl_JOIN_INNER_TD_9809851_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _cp_catalog_page_id997_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9809851_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9809851_key_rightMajor, SW_JOIN_INNER_TD_9809851_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_10805972_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cp_catalog_page_sk996_k = tbl_Filter_TD_10805972_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_9809851_key_rightMajor keyA{_cp_catalog_page_sk996_k};
            int32_t _cp_catalog_page_sk996 = tbl_Filter_TD_10805972_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _cp_catalog_page_id997_n = tbl_Filter_TD_10805972_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _cp_catalog_page_id997 = std::string(_cp_catalog_page_id997_n.data());
            SW_JOIN_INNER_TD_9809851_payload_rightMajor payloadA{_cp_catalog_page_sk996, _cp_catalog_page_id997};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_10664187_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_catalog_page_sk1116_k = tbl_JOIN_INNER_TD_10664187_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9809851_key_rightMajor{_cs_catalog_page_sk1116_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cp_catalog_page_sk996 = (it->second)._cp_catalog_page_sk996;
                std::string _cp_catalog_page_id997 = (it->second)._cp_catalog_page_id997;
                std::array<char, TPCDS_READ_MAX + 1> _cp_catalog_page_id997_n{};
                memcpy(_cp_catalog_page_id997_n.data(), (_cp_catalog_page_id997).data(), (_cp_catalog_page_id997).length());
                int32_t _cs_catalog_page_sk1116 = tbl_JOIN_INNER_TD_10664187_output.getInt32(i, 0);
                int32_t _cs_item_sk1119 = tbl_JOIN_INNER_TD_10664187_output.getInt32(i, 1);
                int32_t _cs_promo_sk1120 = tbl_JOIN_INNER_TD_10664187_output.getInt32(i, 2);
                int64_t _cs_ext_sales_price1127 = tbl_JOIN_INNER_TD_10664187_output.getInt64(i, 3);
                int64_t _cs_net_profit1137 = tbl_JOIN_INNER_TD_10664187_output.getInt64(i, 4);
                int64_t _cr_return_amount1041 = tbl_JOIN_INNER_TD_10664187_output.getInt64(i, 5);
                int64_t _cr_net_loss1049 = tbl_JOIN_INNER_TD_10664187_output.getInt64(i, 6);
                tbl_JOIN_INNER_TD_9809851_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _cp_catalog_page_id997_n);
                tbl_JOIN_INNER_TD_9809851_output.setInt32(r, 0, _cs_item_sk1119);
                tbl_JOIN_INNER_TD_9809851_output.setInt32(r, 1, _cs_promo_sk1120);
                tbl_JOIN_INNER_TD_9809851_output.setInt64(r, 2, _cs_ext_sales_price1127);
                tbl_JOIN_INNER_TD_9809851_output.setInt64(r, 3, _cs_net_profit1137);
                tbl_JOIN_INNER_TD_9809851_output.setInt64(r, 4, _cr_return_amount1041);
                tbl_JOIN_INNER_TD_9809851_output.setInt64(r, 5, _cr_net_loss1049);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9809851_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_9809851_output #Row: " << tbl_JOIN_INNER_TD_9809851_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9190310(Table &tbl_SerializeFromObject_TD_10717886_input, Table &tbl_Filter_TD_9190310_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(i_current_price#233) AND (i_current_price#233 > 50.00)) AND isnotnull(i_item_sk#228)))
    // Input: ListBuffer(i_item_sk#228, i_current_price#233)
    // Output: ListBuffer(i_item_sk#228)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10717886_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _i_current_price233 = tbl_SerializeFromObject_TD_10717886_input.getInt64(i, 1);
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_10717886_input.getInt32(i, 0);
        if (((_i_current_price233!= 0) && (_i_current_price233 > 50.00)) && (_i_item_sk228!= 0)) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_10717886_input.getInt32(i, 0);
            tbl_Filter_TD_9190310_output.setInt32(r, 0, _i_item_sk228_t);
            r++;
        }
    }
    tbl_Filter_TD_9190310_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9190310_output #Row: " << tbl_Filter_TD_9190310_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_9447563_key_leftMajor {
    int32_t _ss_store_sk1213;
    bool operator==(const SW_JOIN_INNER_TD_9447563_key_leftMajor& other) const {
        return ((_ss_store_sk1213 == other._ss_store_sk1213));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9447563_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9447563_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_store_sk1213));
    }
};
}
struct SW_JOIN_INNER_TD_9447563_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int32_t _ss_store_sk1213;
    int32_t _ss_promo_sk1214;
    int64_t _ss_ext_sales_price1221;
    int64_t _ss_net_profit1228;
    int64_t _sr_return_amt680;
    int64_t _sr_net_loss688;
};
struct SW_JOIN_INNER_TD_9447563_key_rightMajor {
    int32_t _s_store_sk378;
    bool operator==(const SW_JOIN_INNER_TD_9447563_key_rightMajor& other) const {
        return ((_s_store_sk378 == other._s_store_sk378));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_9447563_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_9447563_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_store_sk378));
    }
};
}
struct SW_JOIN_INNER_TD_9447563_payload_rightMajor {
    int32_t _s_store_sk378;
    std::string _s_store_id379;
};
void SW_JOIN_INNER_TD_9447563(Table &tbl_JOIN_INNER_TD_10934769_output, Table &tbl_Filter_TD_10841618_output, Table &tbl_JOIN_INNER_TD_9447563_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_store_sk#1213 = s_store_sk#378))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_store_sk#1213, ss_promo_sk#1214, ss_ext_sales_price#1221, ss_net_profit#1228, sr_return_amt#680, sr_net_loss#688)
    // Right Table: ListBuffer(s_store_sk#378, s_store_id#379)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_promo_sk#1214, ss_ext_sales_price#1221, ss_net_profit#1228, sr_return_amt#680, sr_net_loss#688, s_store_id#379)
    int left_nrow = tbl_JOIN_INNER_TD_10934769_output.getNumRow();
    int right_nrow = tbl_Filter_TD_10841618_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9447563_key_leftMajor, SW_JOIN_INNER_TD_9447563_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_10934769_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_store_sk1213_k = tbl_JOIN_INNER_TD_10934769_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_9447563_key_leftMajor keyA{_ss_store_sk1213_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_10934769_output.getInt32(i, 0);
            int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_10934769_output.getInt32(i, 1);
            int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_10934769_output.getInt32(i, 2);
            int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_10934769_output.getInt64(i, 3);
            int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_10934769_output.getInt64(i, 4);
            int64_t _sr_return_amt680 = tbl_JOIN_INNER_TD_10934769_output.getInt64(i, 5);
            int64_t _sr_net_loss688 = tbl_JOIN_INNER_TD_10934769_output.getInt64(i, 6);
            SW_JOIN_INNER_TD_9447563_payload_leftMajor payloadA{_ss_item_sk1208, _ss_store_sk1213, _ss_promo_sk1214, _ss_ext_sales_price1221, _ss_net_profit1228, _sr_return_amt680, _sr_net_loss688};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_10841618_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_10841618_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9447563_key_leftMajor{_s_store_sk378_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_store_sk1213 = (it->second)._ss_store_sk1213;
                int32_t _ss_promo_sk1214 = (it->second)._ss_promo_sk1214;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int64_t _ss_net_profit1228 = (it->second)._ss_net_profit1228;
                int64_t _sr_return_amt680 = (it->second)._sr_return_amt680;
                int64_t _sr_net_loss688 = (it->second)._sr_net_loss688;
                int32_t _s_store_sk378 = tbl_Filter_TD_10841618_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_n = tbl_Filter_TD_10841618_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _s_store_id379 = std::string(_s_store_id379_n.data());
                tbl_JOIN_INNER_TD_9447563_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_9447563_output.setInt32(r, 1, _ss_promo_sk1214);
                tbl_JOIN_INNER_TD_9447563_output.setInt64(r, 2, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_9447563_output.setInt64(r, 3, _ss_net_profit1228);
                tbl_JOIN_INNER_TD_9447563_output.setInt64(r, 4, _sr_return_amt680);
                tbl_JOIN_INNER_TD_9447563_output.setInt64(r, 5, _sr_net_loss688);
                tbl_JOIN_INNER_TD_9447563_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_store_id379_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9447563_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_9447563_key_rightMajor, SW_JOIN_INNER_TD_9447563_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_10841618_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_10841618_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_9447563_key_rightMajor keyA{_s_store_sk378_k};
            int32_t _s_store_sk378 = tbl_Filter_TD_10841618_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_n = tbl_Filter_TD_10841618_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _s_store_id379 = std::string(_s_store_id379_n.data());
            SW_JOIN_INNER_TD_9447563_payload_rightMajor payloadA{_s_store_sk378, _s_store_id379};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_10934769_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_store_sk1213_k = tbl_JOIN_INNER_TD_10934769_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_9447563_key_rightMajor{_ss_store_sk1213_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _s_store_sk378 = (it->second)._s_store_sk378;
                std::string _s_store_id379 = (it->second)._s_store_id379;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_n{};
                memcpy(_s_store_id379_n.data(), (_s_store_id379).data(), (_s_store_id379).length());
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_10934769_output.getInt32(i, 0);
                int32_t _ss_store_sk1213 = tbl_JOIN_INNER_TD_10934769_output.getInt32(i, 1);
                int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_10934769_output.getInt32(i, 2);
                int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_10934769_output.getInt64(i, 3);
                int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_10934769_output.getInt64(i, 4);
                int64_t _sr_return_amt680 = tbl_JOIN_INNER_TD_10934769_output.getInt64(i, 5);
                int64_t _sr_net_loss688 = tbl_JOIN_INNER_TD_10934769_output.getInt64(i, 6);
                tbl_JOIN_INNER_TD_9447563_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 6, _s_store_id379_n);
                tbl_JOIN_INNER_TD_9447563_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_9447563_output.setInt32(r, 1, _ss_promo_sk1214);
                tbl_JOIN_INNER_TD_9447563_output.setInt64(r, 2, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_9447563_output.setInt64(r, 3, _ss_net_profit1228);
                tbl_JOIN_INNER_TD_9447563_output.setInt64(r, 4, _sr_return_amt680);
                tbl_JOIN_INNER_TD_9447563_output.setInt64(r, 5, _sr_net_loss688);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_9447563_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_9447563_output #Row: " << tbl_JOIN_INNER_TD_9447563_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8992697(Table &tbl_SerializeFromObject_TD_9748703_input, Table &tbl_Filter_TD_8992697_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(p_channel_tv#4703) AND (p_channel_tv#4703 = N)) AND isnotnull(p_promo_sk#4692)))
    // Input: ListBuffer(p_promo_sk#4692, p_channel_tv#4703)
    // Output: ListBuffer(p_promo_sk#4692)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9748703_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _p_channel_tv4703 = tbl_SerializeFromObject_TD_9748703_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _p_promo_sk4692 = tbl_SerializeFromObject_TD_9748703_input.getInt32(i, 0);
        if ((_p_channel_tv4703.data() != "NULL" && (std::string(_p_channel_tv4703.data()) == "N")) && (_p_promo_sk4692!= 0)) {
            int32_t _p_promo_sk4692_t = tbl_SerializeFromObject_TD_9748703_input.getInt32(i, 0);
            tbl_Filter_TD_8992697_output.setInt32(r, 0, _p_promo_sk4692_t);
            r++;
        }
    }
    tbl_Filter_TD_8992697_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8992697_output #Row: " << tbl_Filter_TD_8992697_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8859329_key_leftMajor {
    int32_t _ws_item_sk732;
    bool operator==(const SW_JOIN_INNER_TD_8859329_key_leftMajor& other) const {
        return ((_ws_item_sk732 == other._ws_item_sk732));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8859329_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8859329_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_item_sk732));
    }
};
}
struct SW_JOIN_INNER_TD_8859329_payload_leftMajor {
    int32_t _ws_item_sk732;
    int32_t _ws_promo_sk745;
    int64_t _ws_ext_sales_price752;
    int64_t _ws_net_profit762;
    int64_t _wr_return_amt846;
    int64_t _wr_net_loss854;
    std::string _web_site_id538;
};
struct SW_JOIN_INNER_TD_8859329_key_rightMajor {
    int32_t _i_item_sk4670;
    bool operator==(const SW_JOIN_INNER_TD_8859329_key_rightMajor& other) const {
        return ((_i_item_sk4670 == other._i_item_sk4670));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8859329_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8859329_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk4670));
    }
};
}
struct SW_JOIN_INNER_TD_8859329_payload_rightMajor {
    int32_t _i_item_sk4670;
};
void SW_JOIN_INNER_TD_8859329(Table &tbl_JOIN_INNER_TD_9261141_output, Table &tbl_Filter_TD_9570177_output, Table &tbl_JOIN_INNER_TD_8859329_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_item_sk#732 = i_item_sk#4670))
    // Left Table: ListBuffer(ws_item_sk#732, ws_promo_sk#745, ws_ext_sales_price#752, ws_net_profit#762, wr_return_amt#846, wr_net_loss#854, web_site_id#538)
    // Right Table: ListBuffer(i_item_sk#4670)
    // Output Table: ListBuffer(ws_promo_sk#745, ws_ext_sales_price#752, ws_net_profit#762, wr_return_amt#846, wr_net_loss#854, web_site_id#538)
    int left_nrow = tbl_JOIN_INNER_TD_9261141_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9570177_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8859329_key_leftMajor, SW_JOIN_INNER_TD_8859329_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_9261141_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_item_sk732_k = tbl_JOIN_INNER_TD_9261141_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8859329_key_leftMajor keyA{_ws_item_sk732_k};
            int32_t _ws_item_sk732 = tbl_JOIN_INNER_TD_9261141_output.getInt32(i, 0);
            int32_t _ws_promo_sk745 = tbl_JOIN_INNER_TD_9261141_output.getInt32(i, 1);
            int64_t _ws_ext_sales_price752 = tbl_JOIN_INNER_TD_9261141_output.getInt64(i, 2);
            int64_t _ws_net_profit762 = tbl_JOIN_INNER_TD_9261141_output.getInt64(i, 3);
            int64_t _wr_return_amt846 = tbl_JOIN_INNER_TD_9261141_output.getInt64(i, 4);
            int64_t _wr_net_loss854 = tbl_JOIN_INNER_TD_9261141_output.getInt64(i, 5);
            std::array<char, TPCDS_READ_MAX + 1> _web_site_id538_n = tbl_JOIN_INNER_TD_9261141_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _web_site_id538 = std::string(_web_site_id538_n.data());
            SW_JOIN_INNER_TD_8859329_payload_leftMajor payloadA{_ws_item_sk732, _ws_promo_sk745, _ws_ext_sales_price752, _ws_net_profit762, _wr_return_amt846, _wr_net_loss854, _web_site_id538};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9570177_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk4670_k = tbl_Filter_TD_9570177_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8859329_key_leftMajor{_i_item_sk4670_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_item_sk732 = (it->second)._ws_item_sk732;
                int32_t _ws_promo_sk745 = (it->second)._ws_promo_sk745;
                int64_t _ws_ext_sales_price752 = (it->second)._ws_ext_sales_price752;
                int64_t _ws_net_profit762 = (it->second)._ws_net_profit762;
                int64_t _wr_return_amt846 = (it->second)._wr_return_amt846;
                int64_t _wr_net_loss854 = (it->second)._wr_net_loss854;
                std::string _web_site_id538 = (it->second)._web_site_id538;
                std::array<char, TPCDS_READ_MAX + 1> _web_site_id538_n{};
                memcpy(_web_site_id538_n.data(), (_web_site_id538).data(), (_web_site_id538).length());
                int32_t _i_item_sk4670 = tbl_Filter_TD_9570177_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_8859329_output.setInt32(r, 0, _ws_promo_sk745);
                tbl_JOIN_INNER_TD_8859329_output.setInt64(r, 1, _ws_ext_sales_price752);
                tbl_JOIN_INNER_TD_8859329_output.setInt64(r, 2, _ws_net_profit762);
                tbl_JOIN_INNER_TD_8859329_output.setInt64(r, 3, _wr_return_amt846);
                tbl_JOIN_INNER_TD_8859329_output.setInt64(r, 4, _wr_net_loss854);
                tbl_JOIN_INNER_TD_8859329_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _web_site_id538_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8859329_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8859329_key_rightMajor, SW_JOIN_INNER_TD_8859329_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9570177_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk4670_k = tbl_Filter_TD_9570177_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8859329_key_rightMajor keyA{_i_item_sk4670_k};
            int32_t _i_item_sk4670 = tbl_Filter_TD_9570177_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8859329_payload_rightMajor payloadA{_i_item_sk4670};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_9261141_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_item_sk732_k = tbl_JOIN_INNER_TD_9261141_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8859329_key_rightMajor{_ws_item_sk732_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk4670 = (it->second)._i_item_sk4670;
                int32_t _ws_item_sk732 = tbl_JOIN_INNER_TD_9261141_output.getInt32(i, 0);
                int32_t _ws_promo_sk745 = tbl_JOIN_INNER_TD_9261141_output.getInt32(i, 1);
                int64_t _ws_ext_sales_price752 = tbl_JOIN_INNER_TD_9261141_output.getInt64(i, 2);
                int64_t _ws_net_profit762 = tbl_JOIN_INNER_TD_9261141_output.getInt64(i, 3);
                int64_t _wr_return_amt846 = tbl_JOIN_INNER_TD_9261141_output.getInt64(i, 4);
                int64_t _wr_net_loss854 = tbl_JOIN_INNER_TD_9261141_output.getInt64(i, 5);
                std::array<char, TPCDS_READ_MAX + 1> _web_site_id538_n = tbl_JOIN_INNER_TD_9261141_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _web_site_id538 = std::string(_web_site_id538_n.data());
                tbl_JOIN_INNER_TD_8859329_output.setInt32(r, 0, _ws_promo_sk745);
                tbl_JOIN_INNER_TD_8859329_output.setInt64(r, 1, _ws_ext_sales_price752);
                tbl_JOIN_INNER_TD_8859329_output.setInt64(r, 2, _ws_net_profit762);
                tbl_JOIN_INNER_TD_8859329_output.setInt64(r, 3, _wr_return_amt846);
                tbl_JOIN_INNER_TD_8859329_output.setInt64(r, 4, _wr_net_loss854);
                tbl_JOIN_INNER_TD_8859329_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _web_site_id538_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8859329_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8859329_output #Row: " << tbl_JOIN_INNER_TD_8859329_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8291775(Table &tbl_SerializeFromObject_TD_917945_input, Table &tbl_Filter_TD_8291775_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(p_channel_tv#4634) AND (p_channel_tv#4634 = N)) AND isnotnull(p_promo_sk#4623)))
    // Input: ListBuffer(p_promo_sk#4623, p_channel_tv#4634)
    // Output: ListBuffer(p_promo_sk#4623)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_917945_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _p_channel_tv4634 = tbl_SerializeFromObject_TD_917945_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _p_promo_sk4623 = tbl_SerializeFromObject_TD_917945_input.getInt32(i, 0);
        if ((_p_channel_tv4634.data() != "NULL" && (std::string(_p_channel_tv4634.data()) == "N")) && (_p_promo_sk4623!= 0)) {
            int32_t _p_promo_sk4623_t = tbl_SerializeFromObject_TD_917945_input.getInt32(i, 0);
            tbl_Filter_TD_8291775_output.setInt32(r, 0, _p_promo_sk4623_t);
            r++;
        }
    }
    tbl_Filter_TD_8291775_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8291775_output #Row: " << tbl_Filter_TD_8291775_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8531564_key_leftMajor {
    int32_t _cs_item_sk1119;
    bool operator==(const SW_JOIN_INNER_TD_8531564_key_leftMajor& other) const {
        return ((_cs_item_sk1119 == other._cs_item_sk1119));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8531564_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8531564_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_item_sk1119));
    }
};
}
struct SW_JOIN_INNER_TD_8531564_payload_leftMajor {
    int32_t _cs_item_sk1119;
    int32_t _cs_promo_sk1120;
    int64_t _cs_ext_sales_price1127;
    int64_t _cs_net_profit1137;
    int64_t _cr_return_amount1041;
    int64_t _cr_net_loss1049;
    std::string _cp_catalog_page_id997;
};
struct SW_JOIN_INNER_TD_8531564_key_rightMajor {
    int32_t _i_item_sk4601;
    bool operator==(const SW_JOIN_INNER_TD_8531564_key_rightMajor& other) const {
        return ((_i_item_sk4601 == other._i_item_sk4601));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8531564_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8531564_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk4601));
    }
};
}
struct SW_JOIN_INNER_TD_8531564_payload_rightMajor {
    int32_t _i_item_sk4601;
};
void SW_JOIN_INNER_TD_8531564(Table &tbl_JOIN_INNER_TD_9809851_output, Table &tbl_Filter_TD_949741_output, Table &tbl_JOIN_INNER_TD_8531564_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_item_sk#1119 = i_item_sk#4601))
    // Left Table: ListBuffer(cs_item_sk#1119, cs_promo_sk#1120, cs_ext_sales_price#1127, cs_net_profit#1137, cr_return_amount#1041, cr_net_loss#1049, cp_catalog_page_id#997)
    // Right Table: ListBuffer(i_item_sk#4601)
    // Output Table: ListBuffer(cs_promo_sk#1120, cs_ext_sales_price#1127, cs_net_profit#1137, cr_return_amount#1041, cr_net_loss#1049, cp_catalog_page_id#997)
    int left_nrow = tbl_JOIN_INNER_TD_9809851_output.getNumRow();
    int right_nrow = tbl_Filter_TD_949741_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8531564_key_leftMajor, SW_JOIN_INNER_TD_8531564_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_9809851_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_item_sk1119_k = tbl_JOIN_INNER_TD_9809851_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8531564_key_leftMajor keyA{_cs_item_sk1119_k};
            int32_t _cs_item_sk1119 = tbl_JOIN_INNER_TD_9809851_output.getInt32(i, 0);
            int32_t _cs_promo_sk1120 = tbl_JOIN_INNER_TD_9809851_output.getInt32(i, 1);
            int64_t _cs_ext_sales_price1127 = tbl_JOIN_INNER_TD_9809851_output.getInt64(i, 2);
            int64_t _cs_net_profit1137 = tbl_JOIN_INNER_TD_9809851_output.getInt64(i, 3);
            int64_t _cr_return_amount1041 = tbl_JOIN_INNER_TD_9809851_output.getInt64(i, 4);
            int64_t _cr_net_loss1049 = tbl_JOIN_INNER_TD_9809851_output.getInt64(i, 5);
            std::array<char, TPCDS_READ_MAX + 1> _cp_catalog_page_id997_n = tbl_JOIN_INNER_TD_9809851_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _cp_catalog_page_id997 = std::string(_cp_catalog_page_id997_n.data());
            SW_JOIN_INNER_TD_8531564_payload_leftMajor payloadA{_cs_item_sk1119, _cs_promo_sk1120, _cs_ext_sales_price1127, _cs_net_profit1137, _cr_return_amount1041, _cr_net_loss1049, _cp_catalog_page_id997};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_949741_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk4601_k = tbl_Filter_TD_949741_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8531564_key_leftMajor{_i_item_sk4601_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_item_sk1119 = (it->second)._cs_item_sk1119;
                int32_t _cs_promo_sk1120 = (it->second)._cs_promo_sk1120;
                int64_t _cs_ext_sales_price1127 = (it->second)._cs_ext_sales_price1127;
                int64_t _cs_net_profit1137 = (it->second)._cs_net_profit1137;
                int64_t _cr_return_amount1041 = (it->second)._cr_return_amount1041;
                int64_t _cr_net_loss1049 = (it->second)._cr_net_loss1049;
                std::string _cp_catalog_page_id997 = (it->second)._cp_catalog_page_id997;
                std::array<char, TPCDS_READ_MAX + 1> _cp_catalog_page_id997_n{};
                memcpy(_cp_catalog_page_id997_n.data(), (_cp_catalog_page_id997).data(), (_cp_catalog_page_id997).length());
                int32_t _i_item_sk4601 = tbl_Filter_TD_949741_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_8531564_output.setInt32(r, 0, _cs_promo_sk1120);
                tbl_JOIN_INNER_TD_8531564_output.setInt64(r, 1, _cs_ext_sales_price1127);
                tbl_JOIN_INNER_TD_8531564_output.setInt64(r, 2, _cs_net_profit1137);
                tbl_JOIN_INNER_TD_8531564_output.setInt64(r, 3, _cr_return_amount1041);
                tbl_JOIN_INNER_TD_8531564_output.setInt64(r, 4, _cr_net_loss1049);
                tbl_JOIN_INNER_TD_8531564_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _cp_catalog_page_id997_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8531564_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8531564_key_rightMajor, SW_JOIN_INNER_TD_8531564_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_949741_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk4601_k = tbl_Filter_TD_949741_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8531564_key_rightMajor keyA{_i_item_sk4601_k};
            int32_t _i_item_sk4601 = tbl_Filter_TD_949741_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8531564_payload_rightMajor payloadA{_i_item_sk4601};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_9809851_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_item_sk1119_k = tbl_JOIN_INNER_TD_9809851_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8531564_key_rightMajor{_cs_item_sk1119_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk4601 = (it->second)._i_item_sk4601;
                int32_t _cs_item_sk1119 = tbl_JOIN_INNER_TD_9809851_output.getInt32(i, 0);
                int32_t _cs_promo_sk1120 = tbl_JOIN_INNER_TD_9809851_output.getInt32(i, 1);
                int64_t _cs_ext_sales_price1127 = tbl_JOIN_INNER_TD_9809851_output.getInt64(i, 2);
                int64_t _cs_net_profit1137 = tbl_JOIN_INNER_TD_9809851_output.getInt64(i, 3);
                int64_t _cr_return_amount1041 = tbl_JOIN_INNER_TD_9809851_output.getInt64(i, 4);
                int64_t _cr_net_loss1049 = tbl_JOIN_INNER_TD_9809851_output.getInt64(i, 5);
                std::array<char, TPCDS_READ_MAX + 1> _cp_catalog_page_id997_n = tbl_JOIN_INNER_TD_9809851_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _cp_catalog_page_id997 = std::string(_cp_catalog_page_id997_n.data());
                tbl_JOIN_INNER_TD_8531564_output.setInt32(r, 0, _cs_promo_sk1120);
                tbl_JOIN_INNER_TD_8531564_output.setInt64(r, 1, _cs_ext_sales_price1127);
                tbl_JOIN_INNER_TD_8531564_output.setInt64(r, 2, _cs_net_profit1137);
                tbl_JOIN_INNER_TD_8531564_output.setInt64(r, 3, _cr_return_amount1041);
                tbl_JOIN_INNER_TD_8531564_output.setInt64(r, 4, _cr_net_loss1049);
                tbl_JOIN_INNER_TD_8531564_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _cp_catalog_page_id997_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8531564_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8531564_output #Row: " << tbl_JOIN_INNER_TD_8531564_output.getNumRow() << std::endl;
}

void SW_Filter_TD_822743(Table &tbl_SerializeFromObject_TD_9730161_input, Table &tbl_Filter_TD_822743_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(p_channel_tv#305) AND (p_channel_tv#305 = N)) AND isnotnull(p_promo_sk#294)))
    // Input: ListBuffer(p_promo_sk#294, p_channel_tv#305)
    // Output: ListBuffer(p_promo_sk#294)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9730161_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _p_channel_tv305 = tbl_SerializeFromObject_TD_9730161_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _p_promo_sk294 = tbl_SerializeFromObject_TD_9730161_input.getInt32(i, 0);
        if ((_p_channel_tv305.data() != "NULL" && (std::string(_p_channel_tv305.data()) == "N")) && (_p_promo_sk294!= 0)) {
            int32_t _p_promo_sk294_t = tbl_SerializeFromObject_TD_9730161_input.getInt32(i, 0);
            tbl_Filter_TD_822743_output.setInt32(r, 0, _p_promo_sk294_t);
            r++;
        }
    }
    tbl_Filter_TD_822743_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_822743_output #Row: " << tbl_Filter_TD_822743_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8230445_key_leftMajor {
    int32_t _ss_item_sk1208;
    bool operator==(const SW_JOIN_INNER_TD_8230445_key_leftMajor& other) const {
        return ((_ss_item_sk1208 == other._ss_item_sk1208));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8230445_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8230445_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk1208));
    }
};
}
struct SW_JOIN_INNER_TD_8230445_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int32_t _ss_promo_sk1214;
    int64_t _ss_ext_sales_price1221;
    int64_t _ss_net_profit1228;
    int64_t _sr_return_amt680;
    int64_t _sr_net_loss688;
    std::string _s_store_id379;
};
struct SW_JOIN_INNER_TD_8230445_key_rightMajor {
    int32_t _i_item_sk228;
    bool operator==(const SW_JOIN_INNER_TD_8230445_key_rightMajor& other) const {
        return ((_i_item_sk228 == other._i_item_sk228));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8230445_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8230445_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk228));
    }
};
}
struct SW_JOIN_INNER_TD_8230445_payload_rightMajor {
    int32_t _i_item_sk228;
};
void SW_JOIN_INNER_TD_8230445(Table &tbl_JOIN_INNER_TD_9447563_output, Table &tbl_Filter_TD_9190310_output, Table &tbl_JOIN_INNER_TD_8230445_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_item_sk#1208 = i_item_sk#228))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_promo_sk#1214, ss_ext_sales_price#1221, ss_net_profit#1228, sr_return_amt#680, sr_net_loss#688, s_store_id#379)
    // Right Table: ListBuffer(i_item_sk#228)
    // Output Table: ListBuffer(ss_promo_sk#1214, ss_ext_sales_price#1221, ss_net_profit#1228, sr_return_amt#680, sr_net_loss#688, s_store_id#379)
    int left_nrow = tbl_JOIN_INNER_TD_9447563_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9190310_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8230445_key_leftMajor, SW_JOIN_INNER_TD_8230445_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_9447563_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_9447563_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8230445_key_leftMajor keyA{_ss_item_sk1208_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_9447563_output.getInt32(i, 0);
            int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_9447563_output.getInt32(i, 1);
            int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_9447563_output.getInt64(i, 2);
            int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_9447563_output.getInt64(i, 3);
            int64_t _sr_return_amt680 = tbl_JOIN_INNER_TD_9447563_output.getInt64(i, 4);
            int64_t _sr_net_loss688 = tbl_JOIN_INNER_TD_9447563_output.getInt64(i, 5);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_n = tbl_JOIN_INNER_TD_9447563_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
            std::string _s_store_id379 = std::string(_s_store_id379_n.data());
            SW_JOIN_INNER_TD_8230445_payload_leftMajor payloadA{_ss_item_sk1208, _ss_promo_sk1214, _ss_ext_sales_price1221, _ss_net_profit1228, _sr_return_amt680, _sr_net_loss688, _s_store_id379};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9190310_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_9190310_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8230445_key_leftMajor{_i_item_sk228_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_promo_sk1214 = (it->second)._ss_promo_sk1214;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int64_t _ss_net_profit1228 = (it->second)._ss_net_profit1228;
                int64_t _sr_return_amt680 = (it->second)._sr_return_amt680;
                int64_t _sr_net_loss688 = (it->second)._sr_net_loss688;
                std::string _s_store_id379 = (it->second)._s_store_id379;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_n{};
                memcpy(_s_store_id379_n.data(), (_s_store_id379).data(), (_s_store_id379).length());
                int32_t _i_item_sk228 = tbl_Filter_TD_9190310_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_8230445_output.setInt32(r, 0, _ss_promo_sk1214);
                tbl_JOIN_INNER_TD_8230445_output.setInt64(r, 1, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_8230445_output.setInt64(r, 2, _ss_net_profit1228);
                tbl_JOIN_INNER_TD_8230445_output.setInt64(r, 3, _sr_return_amt680);
                tbl_JOIN_INNER_TD_8230445_output.setInt64(r, 4, _sr_net_loss688);
                tbl_JOIN_INNER_TD_8230445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_store_id379_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8230445_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8230445_key_rightMajor, SW_JOIN_INNER_TD_8230445_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9190310_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_9190310_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8230445_key_rightMajor keyA{_i_item_sk228_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_9190310_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8230445_payload_rightMajor payloadA{_i_item_sk228};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_9447563_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_9447563_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8230445_key_rightMajor{_ss_item_sk1208_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_9447563_output.getInt32(i, 0);
                int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_9447563_output.getInt32(i, 1);
                int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_9447563_output.getInt64(i, 2);
                int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_9447563_output.getInt64(i, 3);
                int64_t _sr_return_amt680 = tbl_JOIN_INNER_TD_9447563_output.getInt64(i, 4);
                int64_t _sr_net_loss688 = tbl_JOIN_INNER_TD_9447563_output.getInt64(i, 5);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_n = tbl_JOIN_INNER_TD_9447563_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 6);
                std::string _s_store_id379 = std::string(_s_store_id379_n.data());
                tbl_JOIN_INNER_TD_8230445_output.setInt32(r, 0, _ss_promo_sk1214);
                tbl_JOIN_INNER_TD_8230445_output.setInt64(r, 1, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_8230445_output.setInt64(r, 2, _ss_net_profit1228);
                tbl_JOIN_INNER_TD_8230445_output.setInt64(r, 3, _sr_return_amt680);
                tbl_JOIN_INNER_TD_8230445_output.setInt64(r, 4, _sr_net_loss688);
                tbl_JOIN_INNER_TD_8230445_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _s_store_id379_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8230445_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8230445_output #Row: " << tbl_JOIN_INNER_TD_8230445_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_7114427_key_leftMajor {
    int32_t _ws_promo_sk745;
    bool operator==(const SW_JOIN_INNER_TD_7114427_key_leftMajor& other) const {
        return ((_ws_promo_sk745 == other._ws_promo_sk745));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7114427_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7114427_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_promo_sk745));
    }
};
}
struct SW_JOIN_INNER_TD_7114427_payload_leftMajor {
    int32_t _ws_promo_sk745;
    int64_t _ws_ext_sales_price752;
    int64_t _ws_net_profit762;
    int64_t _wr_return_amt846;
    int64_t _wr_net_loss854;
    std::string _web_site_id538;
};
struct SW_JOIN_INNER_TD_7114427_key_rightMajor {
    int32_t _p_promo_sk4692;
    bool operator==(const SW_JOIN_INNER_TD_7114427_key_rightMajor& other) const {
        return ((_p_promo_sk4692 == other._p_promo_sk4692));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7114427_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7114427_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._p_promo_sk4692));
    }
};
}
struct SW_JOIN_INNER_TD_7114427_payload_rightMajor {
    int32_t _p_promo_sk4692;
};
void SW_JOIN_INNER_TD_7114427(Table &tbl_JOIN_INNER_TD_8859329_output, Table &tbl_Filter_TD_8992697_output, Table &tbl_JOIN_INNER_TD_7114427_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_promo_sk#745 = p_promo_sk#4692))
    // Left Table: ListBuffer(ws_promo_sk#745, ws_ext_sales_price#752, ws_net_profit#762, wr_return_amt#846, wr_net_loss#854, web_site_id#538)
    // Right Table: ListBuffer(p_promo_sk#4692)
    // Output Table: ListBuffer(ws_ext_sales_price#752, ws_net_profit#762, wr_return_amt#846, wr_net_loss#854, web_site_id#538)
    int left_nrow = tbl_JOIN_INNER_TD_8859329_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8992697_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7114427_key_leftMajor, SW_JOIN_INNER_TD_7114427_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_8859329_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_promo_sk745_k = tbl_JOIN_INNER_TD_8859329_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7114427_key_leftMajor keyA{_ws_promo_sk745_k};
            int32_t _ws_promo_sk745 = tbl_JOIN_INNER_TD_8859329_output.getInt32(i, 0);
            int64_t _ws_ext_sales_price752 = tbl_JOIN_INNER_TD_8859329_output.getInt64(i, 1);
            int64_t _ws_net_profit762 = tbl_JOIN_INNER_TD_8859329_output.getInt64(i, 2);
            int64_t _wr_return_amt846 = tbl_JOIN_INNER_TD_8859329_output.getInt64(i, 3);
            int64_t _wr_net_loss854 = tbl_JOIN_INNER_TD_8859329_output.getInt64(i, 4);
            std::array<char, TPCDS_READ_MAX + 1> _web_site_id538_n = tbl_JOIN_INNER_TD_8859329_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _web_site_id538 = std::string(_web_site_id538_n.data());
            SW_JOIN_INNER_TD_7114427_payload_leftMajor payloadA{_ws_promo_sk745, _ws_ext_sales_price752, _ws_net_profit762, _wr_return_amt846, _wr_net_loss854, _web_site_id538};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8992697_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _p_promo_sk4692_k = tbl_Filter_TD_8992697_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7114427_key_leftMajor{_p_promo_sk4692_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_promo_sk745 = (it->second)._ws_promo_sk745;
                int64_t _ws_ext_sales_price752 = (it->second)._ws_ext_sales_price752;
                int64_t _ws_net_profit762 = (it->second)._ws_net_profit762;
                int64_t _wr_return_amt846 = (it->second)._wr_return_amt846;
                int64_t _wr_net_loss854 = (it->second)._wr_net_loss854;
                std::string _web_site_id538 = (it->second)._web_site_id538;
                std::array<char, TPCDS_READ_MAX + 1> _web_site_id538_n{};
                memcpy(_web_site_id538_n.data(), (_web_site_id538).data(), (_web_site_id538).length());
                int32_t _p_promo_sk4692 = tbl_Filter_TD_8992697_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_7114427_output.setInt64(r, 0, _ws_ext_sales_price752);
                tbl_JOIN_INNER_TD_7114427_output.setInt64(r, 1, _ws_net_profit762);
                tbl_JOIN_INNER_TD_7114427_output.setInt64(r, 2, _wr_return_amt846);
                tbl_JOIN_INNER_TD_7114427_output.setInt64(r, 3, _wr_net_loss854);
                tbl_JOIN_INNER_TD_7114427_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _web_site_id538_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7114427_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7114427_key_rightMajor, SW_JOIN_INNER_TD_7114427_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8992697_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _p_promo_sk4692_k = tbl_Filter_TD_8992697_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7114427_key_rightMajor keyA{_p_promo_sk4692_k};
            int32_t _p_promo_sk4692 = tbl_Filter_TD_8992697_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7114427_payload_rightMajor payloadA{_p_promo_sk4692};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_8859329_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_promo_sk745_k = tbl_JOIN_INNER_TD_8859329_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7114427_key_rightMajor{_ws_promo_sk745_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _p_promo_sk4692 = (it->second)._p_promo_sk4692;
                int32_t _ws_promo_sk745 = tbl_JOIN_INNER_TD_8859329_output.getInt32(i, 0);
                int64_t _ws_ext_sales_price752 = tbl_JOIN_INNER_TD_8859329_output.getInt64(i, 1);
                int64_t _ws_net_profit762 = tbl_JOIN_INNER_TD_8859329_output.getInt64(i, 2);
                int64_t _wr_return_amt846 = tbl_JOIN_INNER_TD_8859329_output.getInt64(i, 3);
                int64_t _wr_net_loss854 = tbl_JOIN_INNER_TD_8859329_output.getInt64(i, 4);
                std::array<char, TPCDS_READ_MAX + 1> _web_site_id538_n = tbl_JOIN_INNER_TD_8859329_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _web_site_id538 = std::string(_web_site_id538_n.data());
                tbl_JOIN_INNER_TD_7114427_output.setInt64(r, 0, _ws_ext_sales_price752);
                tbl_JOIN_INNER_TD_7114427_output.setInt64(r, 1, _ws_net_profit762);
                tbl_JOIN_INNER_TD_7114427_output.setInt64(r, 2, _wr_return_amt846);
                tbl_JOIN_INNER_TD_7114427_output.setInt64(r, 3, _wr_net_loss854);
                tbl_JOIN_INNER_TD_7114427_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _web_site_id538_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7114427_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7114427_output #Row: " << tbl_JOIN_INNER_TD_7114427_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_7282618_key_leftMajor {
    int32_t _cs_promo_sk1120;
    bool operator==(const SW_JOIN_INNER_TD_7282618_key_leftMajor& other) const {
        return ((_cs_promo_sk1120 == other._cs_promo_sk1120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7282618_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7282618_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_promo_sk1120));
    }
};
}
struct SW_JOIN_INNER_TD_7282618_payload_leftMajor {
    int32_t _cs_promo_sk1120;
    int64_t _cs_ext_sales_price1127;
    int64_t _cs_net_profit1137;
    int64_t _cr_return_amount1041;
    int64_t _cr_net_loss1049;
    std::string _cp_catalog_page_id997;
};
struct SW_JOIN_INNER_TD_7282618_key_rightMajor {
    int32_t _p_promo_sk4623;
    bool operator==(const SW_JOIN_INNER_TD_7282618_key_rightMajor& other) const {
        return ((_p_promo_sk4623 == other._p_promo_sk4623));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7282618_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7282618_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._p_promo_sk4623));
    }
};
}
struct SW_JOIN_INNER_TD_7282618_payload_rightMajor {
    int32_t _p_promo_sk4623;
};
void SW_JOIN_INNER_TD_7282618(Table &tbl_JOIN_INNER_TD_8531564_output, Table &tbl_Filter_TD_8291775_output, Table &tbl_JOIN_INNER_TD_7282618_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_promo_sk#1120 = p_promo_sk#4623))
    // Left Table: ListBuffer(cs_promo_sk#1120, cs_ext_sales_price#1127, cs_net_profit#1137, cr_return_amount#1041, cr_net_loss#1049, cp_catalog_page_id#997)
    // Right Table: ListBuffer(p_promo_sk#4623)
    // Output Table: ListBuffer(cs_ext_sales_price#1127, cs_net_profit#1137, cr_return_amount#1041, cr_net_loss#1049, cp_catalog_page_id#997)
    int left_nrow = tbl_JOIN_INNER_TD_8531564_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8291775_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7282618_key_leftMajor, SW_JOIN_INNER_TD_7282618_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_8531564_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_promo_sk1120_k = tbl_JOIN_INNER_TD_8531564_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7282618_key_leftMajor keyA{_cs_promo_sk1120_k};
            int32_t _cs_promo_sk1120 = tbl_JOIN_INNER_TD_8531564_output.getInt32(i, 0);
            int64_t _cs_ext_sales_price1127 = tbl_JOIN_INNER_TD_8531564_output.getInt64(i, 1);
            int64_t _cs_net_profit1137 = tbl_JOIN_INNER_TD_8531564_output.getInt64(i, 2);
            int64_t _cr_return_amount1041 = tbl_JOIN_INNER_TD_8531564_output.getInt64(i, 3);
            int64_t _cr_net_loss1049 = tbl_JOIN_INNER_TD_8531564_output.getInt64(i, 4);
            std::array<char, TPCDS_READ_MAX + 1> _cp_catalog_page_id997_n = tbl_JOIN_INNER_TD_8531564_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _cp_catalog_page_id997 = std::string(_cp_catalog_page_id997_n.data());
            SW_JOIN_INNER_TD_7282618_payload_leftMajor payloadA{_cs_promo_sk1120, _cs_ext_sales_price1127, _cs_net_profit1137, _cr_return_amount1041, _cr_net_loss1049, _cp_catalog_page_id997};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8291775_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _p_promo_sk4623_k = tbl_Filter_TD_8291775_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7282618_key_leftMajor{_p_promo_sk4623_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_promo_sk1120 = (it->second)._cs_promo_sk1120;
                int64_t _cs_ext_sales_price1127 = (it->second)._cs_ext_sales_price1127;
                int64_t _cs_net_profit1137 = (it->second)._cs_net_profit1137;
                int64_t _cr_return_amount1041 = (it->second)._cr_return_amount1041;
                int64_t _cr_net_loss1049 = (it->second)._cr_net_loss1049;
                std::string _cp_catalog_page_id997 = (it->second)._cp_catalog_page_id997;
                std::array<char, TPCDS_READ_MAX + 1> _cp_catalog_page_id997_n{};
                memcpy(_cp_catalog_page_id997_n.data(), (_cp_catalog_page_id997).data(), (_cp_catalog_page_id997).length());
                int32_t _p_promo_sk4623 = tbl_Filter_TD_8291775_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_7282618_output.setInt64(r, 0, _cs_ext_sales_price1127);
                tbl_JOIN_INNER_TD_7282618_output.setInt64(r, 1, _cs_net_profit1137);
                tbl_JOIN_INNER_TD_7282618_output.setInt64(r, 2, _cr_return_amount1041);
                tbl_JOIN_INNER_TD_7282618_output.setInt64(r, 3, _cr_net_loss1049);
                tbl_JOIN_INNER_TD_7282618_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _cp_catalog_page_id997_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7282618_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7282618_key_rightMajor, SW_JOIN_INNER_TD_7282618_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8291775_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _p_promo_sk4623_k = tbl_Filter_TD_8291775_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7282618_key_rightMajor keyA{_p_promo_sk4623_k};
            int32_t _p_promo_sk4623 = tbl_Filter_TD_8291775_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7282618_payload_rightMajor payloadA{_p_promo_sk4623};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_8531564_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_promo_sk1120_k = tbl_JOIN_INNER_TD_8531564_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7282618_key_rightMajor{_cs_promo_sk1120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _p_promo_sk4623 = (it->second)._p_promo_sk4623;
                int32_t _cs_promo_sk1120 = tbl_JOIN_INNER_TD_8531564_output.getInt32(i, 0);
                int64_t _cs_ext_sales_price1127 = tbl_JOIN_INNER_TD_8531564_output.getInt64(i, 1);
                int64_t _cs_net_profit1137 = tbl_JOIN_INNER_TD_8531564_output.getInt64(i, 2);
                int64_t _cr_return_amount1041 = tbl_JOIN_INNER_TD_8531564_output.getInt64(i, 3);
                int64_t _cr_net_loss1049 = tbl_JOIN_INNER_TD_8531564_output.getInt64(i, 4);
                std::array<char, TPCDS_READ_MAX + 1> _cp_catalog_page_id997_n = tbl_JOIN_INNER_TD_8531564_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _cp_catalog_page_id997 = std::string(_cp_catalog_page_id997_n.data());
                tbl_JOIN_INNER_TD_7282618_output.setInt64(r, 0, _cs_ext_sales_price1127);
                tbl_JOIN_INNER_TD_7282618_output.setInt64(r, 1, _cs_net_profit1137);
                tbl_JOIN_INNER_TD_7282618_output.setInt64(r, 2, _cr_return_amount1041);
                tbl_JOIN_INNER_TD_7282618_output.setInt64(r, 3, _cr_net_loss1049);
                tbl_JOIN_INNER_TD_7282618_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _cp_catalog_page_id997_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7282618_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7282618_output #Row: " << tbl_JOIN_INNER_TD_7282618_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_7353460_key_leftMajor {
    int32_t _ss_promo_sk1214;
    bool operator==(const SW_JOIN_INNER_TD_7353460_key_leftMajor& other) const {
        return ((_ss_promo_sk1214 == other._ss_promo_sk1214));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7353460_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7353460_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_promo_sk1214));
    }
};
}
struct SW_JOIN_INNER_TD_7353460_payload_leftMajor {
    int32_t _ss_promo_sk1214;
    int64_t _ss_ext_sales_price1221;
    int64_t _ss_net_profit1228;
    int64_t _sr_return_amt680;
    int64_t _sr_net_loss688;
    std::string _s_store_id379;
};
struct SW_JOIN_INNER_TD_7353460_key_rightMajor {
    int32_t _p_promo_sk294;
    bool operator==(const SW_JOIN_INNER_TD_7353460_key_rightMajor& other) const {
        return ((_p_promo_sk294 == other._p_promo_sk294));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7353460_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7353460_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._p_promo_sk294));
    }
};
}
struct SW_JOIN_INNER_TD_7353460_payload_rightMajor {
    int32_t _p_promo_sk294;
};
void SW_JOIN_INNER_TD_7353460(Table &tbl_JOIN_INNER_TD_8230445_output, Table &tbl_Filter_TD_822743_output, Table &tbl_JOIN_INNER_TD_7353460_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_promo_sk#1214 = p_promo_sk#294))
    // Left Table: ListBuffer(ss_promo_sk#1214, ss_ext_sales_price#1221, ss_net_profit#1228, sr_return_amt#680, sr_net_loss#688, s_store_id#379)
    // Right Table: ListBuffer(p_promo_sk#294)
    // Output Table: ListBuffer(ss_ext_sales_price#1221, ss_net_profit#1228, sr_return_amt#680, sr_net_loss#688, s_store_id#379)
    int left_nrow = tbl_JOIN_INNER_TD_8230445_output.getNumRow();
    int right_nrow = tbl_Filter_TD_822743_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7353460_key_leftMajor, SW_JOIN_INNER_TD_7353460_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_8230445_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_promo_sk1214_k = tbl_JOIN_INNER_TD_8230445_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7353460_key_leftMajor keyA{_ss_promo_sk1214_k};
            int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_8230445_output.getInt32(i, 0);
            int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_8230445_output.getInt64(i, 1);
            int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_8230445_output.getInt64(i, 2);
            int64_t _sr_return_amt680 = tbl_JOIN_INNER_TD_8230445_output.getInt64(i, 3);
            int64_t _sr_net_loss688 = tbl_JOIN_INNER_TD_8230445_output.getInt64(i, 4);
            std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_n = tbl_JOIN_INNER_TD_8230445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _s_store_id379 = std::string(_s_store_id379_n.data());
            SW_JOIN_INNER_TD_7353460_payload_leftMajor payloadA{_ss_promo_sk1214, _ss_ext_sales_price1221, _ss_net_profit1228, _sr_return_amt680, _sr_net_loss688, _s_store_id379};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_822743_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _p_promo_sk294_k = tbl_Filter_TD_822743_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7353460_key_leftMajor{_p_promo_sk294_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_promo_sk1214 = (it->second)._ss_promo_sk1214;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int64_t _ss_net_profit1228 = (it->second)._ss_net_profit1228;
                int64_t _sr_return_amt680 = (it->second)._sr_return_amt680;
                int64_t _sr_net_loss688 = (it->second)._sr_net_loss688;
                std::string _s_store_id379 = (it->second)._s_store_id379;
                std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_n{};
                memcpy(_s_store_id379_n.data(), (_s_store_id379).data(), (_s_store_id379).length());
                int32_t _p_promo_sk294 = tbl_Filter_TD_822743_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_7353460_output.setInt64(r, 0, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_7353460_output.setInt64(r, 1, _ss_net_profit1228);
                tbl_JOIN_INNER_TD_7353460_output.setInt64(r, 2, _sr_return_amt680);
                tbl_JOIN_INNER_TD_7353460_output.setInt64(r, 3, _sr_net_loss688);
                tbl_JOIN_INNER_TD_7353460_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _s_store_id379_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7353460_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7353460_key_rightMajor, SW_JOIN_INNER_TD_7353460_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_822743_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _p_promo_sk294_k = tbl_Filter_TD_822743_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7353460_key_rightMajor keyA{_p_promo_sk294_k};
            int32_t _p_promo_sk294 = tbl_Filter_TD_822743_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7353460_payload_rightMajor payloadA{_p_promo_sk294};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_8230445_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_promo_sk1214_k = tbl_JOIN_INNER_TD_8230445_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7353460_key_rightMajor{_ss_promo_sk1214_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _p_promo_sk294 = (it->second)._p_promo_sk294;
                int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_8230445_output.getInt32(i, 0);
                int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_8230445_output.getInt64(i, 1);
                int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_8230445_output.getInt64(i, 2);
                int64_t _sr_return_amt680 = tbl_JOIN_INNER_TD_8230445_output.getInt64(i, 3);
                int64_t _sr_net_loss688 = tbl_JOIN_INNER_TD_8230445_output.getInt64(i, 4);
                std::array<char, TPCDS_READ_MAX + 1> _s_store_id379_n = tbl_JOIN_INNER_TD_8230445_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _s_store_id379 = std::string(_s_store_id379_n.data());
                tbl_JOIN_INNER_TD_7353460_output.setInt64(r, 0, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_7353460_output.setInt64(r, 1, _ss_net_profit1228);
                tbl_JOIN_INNER_TD_7353460_output.setInt64(r, 2, _sr_return_amt680);
                tbl_JOIN_INNER_TD_7353460_output.setInt64(r, 3, _sr_net_loss688);
                tbl_JOIN_INNER_TD_7353460_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _s_store_id379_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7353460_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7353460_output #Row: " << tbl_JOIN_INNER_TD_7353460_output.getNumRow() << std::endl;
}

typedef std::string SW_Aggregate_TD_6790829_key;
struct SW_Aggregate_TD_6790829_payload {
    int64_t _sales4570_sum_0;
    int64_t _returns4571_sum_1;
    int64_t _profit4572_sum_2;
    std::string _channel5057;
    std::string _id5058;
};
void SW_Aggregate_TD_6790829(Table &tbl_JOIN_INNER_TD_7114427_output, Table &tbl_Aggregate_TD_6790829_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(web_site_id#538, MakeDecimal(sum(UnscaledValue(ws_ext_sales_price#752)),17,2) AS sales#4570, sum(coalesce(cast(wr_return_amt#846 as decimal(12,2)), 0.00)) AS returns#4571, sum(CheckOverflow((promote_precision(cast(ws_net_profit#762 as decimal(13,2))) - promote_precision(cast(coalesce(cast(wr_net_loss#854 as decimal(12,2)), 0.00) as decimal(13,2)))), DecimalType(13,2), true)) AS profit#4572, web channel AS channel#5057, concat(web_site, web_site_id#538) AS id#5058)
    // Input: ListBuffer(ws_ext_sales_price#752, ws_net_profit#762, wr_return_amt#846, wr_net_loss#854, web_site_id#538)
    // Output: ListBuffer(sales#4570, returns#4571, profit#4572, channel#5057, id#5058)
    std::unordered_map<SW_Aggregate_TD_6790829_key, SW_Aggregate_TD_6790829_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_7114427_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ws_ext_sales_price752 = tbl_JOIN_INNER_TD_7114427_output.getInt64(i, 0);
        int64_t _ws_net_profit762 = tbl_JOIN_INNER_TD_7114427_output.getInt64(i, 1);
        int64_t _wr_return_amt846 = tbl_JOIN_INNER_TD_7114427_output.getInt64(i, 2);
        int64_t _wr_net_loss854 = tbl_JOIN_INNER_TD_7114427_output.getInt64(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _web_site_id538 = tbl_JOIN_INNER_TD_7114427_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        SW_Aggregate_TD_6790829_key k = std::string(_web_site_id538.data());
        int64_t _sales4570_sum_0 = _ws_ext_sales_price752;
        int64_t _returns4571_sum_1 = _wr_return_amt846 != 0 ? _wr_return_amt846 : 0.00;
        int64_t _profit4572_sum_2 = (_ws_net_profit762 - _wr_net_loss854 != 0 ? _wr_net_loss854 : 0.00);
        std::string _channel5057 = "web channel";
        std::string _id5058 = std::string("web_site").append(std::string(_web_site_id538.data()));
        SW_Aggregate_TD_6790829_payload p{_sales4570_sum_0, _returns4571_sum_1, _profit4572_sum_2, std::string(_channel5057.data()), std::string(_id5058.data())};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._sales4570_sum_0 + _sales4570_sum_0;
            p._sales4570_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._returns4571_sum_1 + _returns4571_sum_1;
            p._returns4571_sum_1 = sum_1;
            int64_t sum_2 = (it->second)._profit4572_sum_2 + _profit4572_sum_2;
            p._profit4572_sum_2 = sum_2;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _web_site_id538 not required in the output table
        int64_t _sales4570 = (it.second)._sales4570_sum_0;
        tbl_Aggregate_TD_6790829_output.setInt64(r, 0, _sales4570);
        int64_t _returns4571 = (it.second)._returns4571_sum_1;
        tbl_Aggregate_TD_6790829_output.setInt64(r, 1, _returns4571);
        int64_t _profit4572 = (it.second)._profit4572_sum_2;
        tbl_Aggregate_TD_6790829_output.setInt64(r, 2, _profit4572);
        std::array<char, TPCDS_READ_MAX + 1> _channel5057_n{};
        memcpy(_channel5057_n.data(), (it.second)._channel5057.data(), (it.second)._channel5057.length());
        tbl_Aggregate_TD_6790829_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _channel5057_n);
        std::array<char, TPCDS_READ_MAX + 1> _id5058_n{};
        memcpy(_id5058_n.data(), (it.second)._id5058.data(), (it.second)._id5058.length());
        tbl_Aggregate_TD_6790829_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _id5058_n);
        ++r;
    }
    tbl_Aggregate_TD_6790829_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_6790829_output #Row: " << tbl_Aggregate_TD_6790829_output.getNumRow() << std::endl;
}

typedef std::string SW_Aggregate_TD_6631003_key;
struct SW_Aggregate_TD_6631003_payload {
    int64_t _sales4567_sum_0;
    int64_t _returns4568_sum_1;
    int64_t _profit4569_sum_2;
    std::string _channel5055;
    std::string _id5056;
};
void SW_Aggregate_TD_6631003(Table &tbl_JOIN_INNER_TD_7282618_output, Table &tbl_Aggregate_TD_6631003_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(cp_catalog_page_id#997, MakeDecimal(sum(UnscaledValue(cs_ext_sales_price#1127)),17,2) AS sales#4567, sum(coalesce(cast(cr_return_amount#1041 as decimal(12,2)), 0.00)) AS returns#4568, sum(CheckOverflow((promote_precision(cast(cs_net_profit#1137 as decimal(13,2))) - promote_precision(cast(coalesce(cast(cr_net_loss#1049 as decimal(12,2)), 0.00) as decimal(13,2)))), DecimalType(13,2), true)) AS profit#4569, catalog channel AS channel#5055, concat(catalog_page, cp_catalog_page_id#997) AS id#5056)
    // Input: ListBuffer(cs_ext_sales_price#1127, cs_net_profit#1137, cr_return_amount#1041, cr_net_loss#1049, cp_catalog_page_id#997)
    // Output: ListBuffer(sales#4567, returns#4568, profit#4569, channel#5055, id#5056)
    std::unordered_map<SW_Aggregate_TD_6631003_key, SW_Aggregate_TD_6631003_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_7282618_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _cs_ext_sales_price1127 = tbl_JOIN_INNER_TD_7282618_output.getInt64(i, 0);
        int64_t _cs_net_profit1137 = tbl_JOIN_INNER_TD_7282618_output.getInt64(i, 1);
        int64_t _cr_return_amount1041 = tbl_JOIN_INNER_TD_7282618_output.getInt64(i, 2);
        int64_t _cr_net_loss1049 = tbl_JOIN_INNER_TD_7282618_output.getInt64(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _cp_catalog_page_id997 = tbl_JOIN_INNER_TD_7282618_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        SW_Aggregate_TD_6631003_key k = std::string(_cp_catalog_page_id997.data());
        int64_t _sales4567_sum_0 = _cs_ext_sales_price1127;
        int64_t _returns4568_sum_1 = _cr_return_amount1041 != 0 ? _cr_return_amount1041 : 0.00;
        int64_t _profit4569_sum_2 = (_cs_net_profit1137 - _cr_net_loss1049 != 0 ? _cr_net_loss1049 : 0.00);
        std::string _channel5055 = "catalog channel";
        std::string _id5056 = std::string("catalog_page").append(std::string(_cp_catalog_page_id997.data()));
        SW_Aggregate_TD_6631003_payload p{_sales4567_sum_0, _returns4568_sum_1, _profit4569_sum_2, std::string(_channel5055.data()), std::string(_id5056.data())};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._sales4567_sum_0 + _sales4567_sum_0;
            p._sales4567_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._returns4568_sum_1 + _returns4568_sum_1;
            p._returns4568_sum_1 = sum_1;
            int64_t sum_2 = (it->second)._profit4569_sum_2 + _profit4569_sum_2;
            p._profit4569_sum_2 = sum_2;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _cp_catalog_page_id997 not required in the output table
        int64_t _sales4567 = (it.second)._sales4567_sum_0;
        tbl_Aggregate_TD_6631003_output.setInt64(r, 0, _sales4567);
        int64_t _returns4568 = (it.second)._returns4568_sum_1;
        tbl_Aggregate_TD_6631003_output.setInt64(r, 1, _returns4568);
        int64_t _profit4569 = (it.second)._profit4569_sum_2;
        tbl_Aggregate_TD_6631003_output.setInt64(r, 2, _profit4569);
        std::array<char, TPCDS_READ_MAX + 1> _channel5055_n{};
        memcpy(_channel5055_n.data(), (it.second)._channel5055.data(), (it.second)._channel5055.length());
        tbl_Aggregate_TD_6631003_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _channel5055_n);
        std::array<char, TPCDS_READ_MAX + 1> _id5056_n{};
        memcpy(_id5056_n.data(), (it.second)._id5056.data(), (it.second)._id5056.length());
        tbl_Aggregate_TD_6631003_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _id5056_n);
        ++r;
    }
    tbl_Aggregate_TD_6631003_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_6631003_output #Row: " << tbl_Aggregate_TD_6631003_output.getNumRow() << std::endl;
}

typedef std::string SW_Aggregate_TD_6197270_key;
struct SW_Aggregate_TD_6197270_payload {
    int64_t _sales4563_sum_0;
    int64_t _returns4564_sum_1;
    int64_t _profit4565_sum_2;
    std::string _channel4723;
    std::string _id4724;
};
void SW_Aggregate_TD_6197270(Table &tbl_JOIN_INNER_TD_7353460_output, Table &tbl_Aggregate_TD_6197270_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(s_store_id#379, MakeDecimal(sum(UnscaledValue(ss_ext_sales_price#1221)),17,2) AS sales#4563, sum(coalesce(cast(sr_return_amt#680 as decimal(12,2)), 0.00)) AS returns#4564, sum(CheckOverflow((promote_precision(cast(ss_net_profit#1228 as decimal(13,2))) - promote_precision(cast(coalesce(cast(sr_net_loss#688 as decimal(12,2)), 0.00) as decimal(13,2)))), DecimalType(13,2), true)) AS profit#4565, store channel AS channel#4723, concat(store, s_store_id#379) AS id#4724)
    // Input: ListBuffer(ss_ext_sales_price#1221, ss_net_profit#1228, sr_return_amt#680, sr_net_loss#688, s_store_id#379)
    // Output: ListBuffer(sales#4563, returns#4564, profit#4565, channel#4723, id#4724)
    std::unordered_map<SW_Aggregate_TD_6197270_key, SW_Aggregate_TD_6197270_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_7353460_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_7353460_output.getInt64(i, 0);
        int64_t _ss_net_profit1228 = tbl_JOIN_INNER_TD_7353460_output.getInt64(i, 1);
        int64_t _sr_return_amt680 = tbl_JOIN_INNER_TD_7353460_output.getInt64(i, 2);
        int64_t _sr_net_loss688 = tbl_JOIN_INNER_TD_7353460_output.getInt64(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _s_store_id379 = tbl_JOIN_INNER_TD_7353460_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        SW_Aggregate_TD_6197270_key k = std::string(_s_store_id379.data());
        int64_t _sales4563_sum_0 = _ss_ext_sales_price1221;
        int64_t _returns4564_sum_1 = _sr_return_amt680 != 0 ? _sr_return_amt680 : 0.00;
        int64_t _profit4565_sum_2 = (_ss_net_profit1228 - _sr_net_loss688 != 0 ? _sr_net_loss688 : 0.00);
        std::string _channel4723 = "store channel";
        std::string _id4724 = std::string("store").append(std::string(_s_store_id379.data()));
        SW_Aggregate_TD_6197270_payload p{_sales4563_sum_0, _returns4564_sum_1, _profit4565_sum_2, std::string(_channel4723.data()), std::string(_id4724.data())};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._sales4563_sum_0 + _sales4563_sum_0;
            p._sales4563_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._returns4564_sum_1 + _returns4564_sum_1;
            p._returns4564_sum_1 = sum_1;
            int64_t sum_2 = (it->second)._profit4565_sum_2 + _profit4565_sum_2;
            p._profit4565_sum_2 = sum_2;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _s_store_id379 not required in the output table
        int64_t _sales4563 = (it.second)._sales4563_sum_0;
        tbl_Aggregate_TD_6197270_output.setInt64(r, 0, _sales4563);
        int64_t _returns4564 = (it.second)._returns4564_sum_1;
        tbl_Aggregate_TD_6197270_output.setInt64(r, 1, _returns4564);
        int64_t _profit4565 = (it.second)._profit4565_sum_2;
        tbl_Aggregate_TD_6197270_output.setInt64(r, 2, _profit4565);
        std::array<char, TPCDS_READ_MAX + 1> _channel4723_n{};
        memcpy(_channel4723_n.data(), (it.second)._channel4723.data(), (it.second)._channel4723.length());
        tbl_Aggregate_TD_6197270_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _channel4723_n);
        std::array<char, TPCDS_READ_MAX + 1> _id4724_n{};
        memcpy(_id4724_n.data(), (it.second)._id4724.data(), (it.second)._id4724.length());
        tbl_Aggregate_TD_6197270_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _id4724_n);
        ++r;
    }
    tbl_Aggregate_TD_6197270_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_6197270_output #Row: " << tbl_Aggregate_TD_6197270_output.getNumRow() << std::endl;
}

void SW_Union_TD_535352(Table &tbl_Aggregate_TD_6197270_output, Table &tbl_Aggregate_TD_6631003_output, Table &tbl_Aggregate_TD_6790829_output, Table &tbl_Union_TD_535352_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Union
    // Operation: ListBuffer(List(UNION))
    // Output Table: ListBuffer(sales#4563, returns#4564, profit#4565, channel#4723, id#4724)
    int r = 0;
    int row0 = tbl_Aggregate_TD_6197270_output.getNumRow();
    for (int i = 0; i < row0; i++) {
        tbl_Union_TD_535352_output.setInt32(r, 0, tbl_Aggregate_TD_6197270_output.getInt64(i, 0));
        tbl_Union_TD_535352_output.setInt32(r, 1, tbl_Aggregate_TD_6197270_output.getInt64(i, 1));
        tbl_Union_TD_535352_output.setInt32(r, 2, tbl_Aggregate_TD_6197270_output.getInt64(i, 2));
        std::array<char, TPCDS_READ_MAX + 1> _channel4723_n = tbl_Union_TD_535352_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_Union_TD_535352_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _channel4723_n);
        std::array<char, TPCDS_READ_MAX + 1> _id4724_n = tbl_Union_TD_535352_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        tbl_Union_TD_535352_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _id4724_n);
        ++r;
    }
    int row1 = tbl_Aggregate_TD_6631003_output.getNumRow();
    for (int i = 0; i < row1; i++) {
        tbl_Union_TD_535352_output.setInt32(r, 0, tbl_Aggregate_TD_6631003_output.getInt64(i, 0));
        tbl_Union_TD_535352_output.setInt32(r, 1, tbl_Aggregate_TD_6631003_output.getInt64(i, 1));
        tbl_Union_TD_535352_output.setInt32(r, 2, tbl_Aggregate_TD_6631003_output.getInt64(i, 2));
        std::array<char, TPCDS_READ_MAX + 1> _channel5055_n = tbl_Union_TD_535352_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_Union_TD_535352_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _channel5055_n);
        std::array<char, TPCDS_READ_MAX + 1> _id5056_n = tbl_Union_TD_535352_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        tbl_Union_TD_535352_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _id5056_n);
        ++r;
    }
    int row2 = tbl_Aggregate_TD_6790829_output.getNumRow();
    for (int i = 0; i < row2; i++) {
        tbl_Union_TD_535352_output.setInt32(r, 0, tbl_Aggregate_TD_6790829_output.getInt64(i, 0));
        tbl_Union_TD_535352_output.setInt32(r, 1, tbl_Aggregate_TD_6790829_output.getInt64(i, 1));
        tbl_Union_TD_535352_output.setInt32(r, 2, tbl_Aggregate_TD_6790829_output.getInt64(i, 2));
        std::array<char, TPCDS_READ_MAX + 1> _channel5057_n = tbl_Union_TD_535352_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        tbl_Union_TD_535352_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _channel5057_n);
        std::array<char, TPCDS_READ_MAX + 1> _id5058_n = tbl_Union_TD_535352_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        tbl_Union_TD_535352_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _id5058_n);
        ++r;
    }
    tbl_Union_TD_535352_output.setNumRow(r);
    std::cout << "tbl_Union_TD_535352_output #Row: " << tbl_Union_TD_535352_output.getNumRow() << std::endl;
}

void SW_Expand_TD_4666629(Table &tbl_Union_TD_535352_output, Table &tbl_Expand_TD_4666629_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Expand
    // Operation: ListBuffer(Expand)
    // Input: ListBuffer(sales#4563, returns#4564, profit#4565, channel#4723, id#4724)
    // Output: ListBuffer(sales#4563, returns#4564, profit#4565, channel#4726, id#4727, spark_grouping_id#4725L)
    std::cout << "tbl_Expand_TD_4666629_output #Row: " << tbl_Expand_TD_4666629_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_3486002_key {
    std::string _channel4726;
    std::string _id4727;
    int64_t _spark_grouping_id4725L;
    bool operator==(const SW_Aggregate_TD_3486002_key& other) const { return (_channel4726 == other._channel4726) && (_id4727 == other._id4727) && (_spark_grouping_id4725L == other._spark_grouping_id4725L); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_3486002_key> {
    std::size_t operator() (const SW_Aggregate_TD_3486002_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._channel4726)) + (hash<string>()(k._id4727)) + (hash<int64_t>()(k._spark_grouping_id4725L));
    }
};
}
struct SW_Aggregate_TD_3486002_payload {
    int64_t _sales4559_sum_0;
    int64_t _returns4560_sum_1;
    int64_t _profit4561_sum_2;
};
void SW_Aggregate_TD_3486002(Table &tbl_Expand_TD_4666629_output, Table &tbl_Aggregate_TD_3486002_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(channel#4726, id#4727, spark_grouping_id#4725L, sum(sales#4563) AS sales#4559, sum(returns#4564) AS returns#4560, sum(profit#4565) AS profit#4561)
    // Input: ListBuffer(sales#4563, returns#4564, profit#4565, channel#4726, id#4727, spark_grouping_id#4725L)
    // Output: ListBuffer(channel#4726, id#4727, sales#4559, returns#4560, profit#4561)
    std::unordered_map<SW_Aggregate_TD_3486002_key, SW_Aggregate_TD_3486002_payload> ht1;
    int nrow1 = tbl_Expand_TD_4666629_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sales4563 = tbl_Expand_TD_4666629_output.getInt64(i, 0);
        int64_t _returns4564 = tbl_Expand_TD_4666629_output.getInt64(i, 1);
        int64_t _profit4565 = tbl_Expand_TD_4666629_output.getInt64(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _channel4726 = tbl_Expand_TD_4666629_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _id4727 = tbl_Expand_TD_4666629_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        int64_t _spark_grouping_id4725L = tbl_Expand_TD_4666629_output.getInt64(i, 5);
        SW_Aggregate_TD_3486002_key k{std::string(_channel4726.data()), std::string(_id4727.data()), _spark_grouping_id4725L};
        int64_t _sales4559_sum_0 = _sales4563;
        int64_t _returns4560_sum_1 = _returns4564;
        int64_t _profit4561_sum_2 = _profit4565;
        SW_Aggregate_TD_3486002_payload p{_sales4559_sum_0, _returns4560_sum_1, _profit4561_sum_2};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._sales4559_sum_0 + _sales4559_sum_0;
            p._sales4559_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._returns4560_sum_1 + _returns4560_sum_1;
            p._returns4560_sum_1 = sum_1;
            int64_t sum_2 = (it->second)._profit4561_sum_2 + _profit4561_sum_2;
            p._profit4561_sum_2 = sum_2;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _channel4726{};
        memcpy(_channel4726.data(), ((it.first)._channel4726).data(), ((it.first)._channel4726).length());
        tbl_Aggregate_TD_3486002_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _channel4726);
        std::array<char, TPCDS_READ_MAX + 1> _id4727{};
        memcpy(_id4727.data(), ((it.first)._id4727).data(), ((it.first)._id4727).length());
        tbl_Aggregate_TD_3486002_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _id4727);
        // _spark_grouping_id4725L not required in the output table
        int64_t _sales4559 = (it.second)._sales4559_sum_0;
        tbl_Aggregate_TD_3486002_output.setInt64(r, 2, _sales4559);
        int64_t _returns4560 = (it.second)._returns4560_sum_1;
        tbl_Aggregate_TD_3486002_output.setInt64(r, 3, _returns4560);
        int64_t _profit4561 = (it.second)._profit4561_sum_2;
        tbl_Aggregate_TD_3486002_output.setInt64(r, 4, _profit4561);
        ++r;
    }
    tbl_Aggregate_TD_3486002_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_3486002_output #Row: " << tbl_Aggregate_TD_3486002_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2745446(Table &tbl_Aggregate_TD_3486002_output, Table &tbl_Sort_TD_2745446_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(channel#4726 ASC NULLS FIRST, id#4727 ASC NULLS FIRST)
    // Input: ListBuffer(channel#4726, id#4727, sales#4559, returns#4560, profit#4561)
    // Output: ListBuffer(channel#4726, id#4727, sales#4559, returns#4560, profit#4561)
    struct SW_Sort_TD_2745446Row {
        std::string _channel4726;
        std::string _id4727;
        int64_t _sales4559;
        int64_t _returns4560;
        int64_t _profit4561;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2745446Row& a, const SW_Sort_TD_2745446Row& b) const { return 
 (a._channel4726 < b._channel4726) || 
 ((a._channel4726 == b._channel4726) && (a._id4727 < b._id4727)); 
}
    }SW_Sort_TD_2745446_order; 

    int nrow1 = tbl_Aggregate_TD_3486002_output.getNumRow();
    std::vector<SW_Sort_TD_2745446Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _channel4726 = tbl_Aggregate_TD_3486002_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _id4727 = tbl_Aggregate_TD_3486002_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        int64_t _sales4559 = tbl_Aggregate_TD_3486002_output.getInt64(i, 2);
        int64_t _returns4560 = tbl_Aggregate_TD_3486002_output.getInt64(i, 3);
        int64_t _profit4561 = tbl_Aggregate_TD_3486002_output.getInt64(i, 4);
        SW_Sort_TD_2745446Row t = {std::string(_channel4726.data()),std::string(_id4727.data()),_sales4559,_returns4560,_profit4561};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2745446_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _channel4726{};
        memcpy(_channel4726.data(), (it._channel4726).data(), (it._channel4726).length());
        tbl_Sort_TD_2745446_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _channel4726);
        std::array<char, TPCDS_READ_MAX + 1> _id4727{};
        memcpy(_id4727.data(), (it._id4727).data(), (it._id4727).length());
        tbl_Sort_TD_2745446_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _id4727);
        tbl_Sort_TD_2745446_output.setInt64(r, 2, it._sales4559);
        tbl_Sort_TD_2745446_output.setInt64(r, 3, it._returns4560);
        tbl_Sort_TD_2745446_output.setInt64(r, 4, it._profit4561);
        ++r;
    }
    tbl_Sort_TD_2745446_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2745446_output #Row: " << tbl_Sort_TD_2745446_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1122885(Table &tbl_Sort_TD_2745446_output, Table &tbl_LocalLimit_TD_1122885_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(channel#4726, id#4727, sales#4559, returns#4560, profit#4561)
    // Output: ListBuffer(channel#4726, id#4727, sales#4559, returns#4560, profit#4561)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _channel4726_n = tbl_Sort_TD_2745446_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1122885_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _channel4726_n);
        std::array<char, TPCDS_READ_MAX + 1> _id4727_n = tbl_Sort_TD_2745446_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_1122885_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _id4727_n);
        tbl_LocalLimit_TD_1122885_output.setInt64(r, 2, tbl_Sort_TD_2745446_output.getInt64(i, 2));
        tbl_LocalLimit_TD_1122885_output.setInt64(r, 3, tbl_Sort_TD_2745446_output.getInt64(i, 3));
        tbl_LocalLimit_TD_1122885_output.setInt64(r, 4, tbl_Sort_TD_2745446_output.getInt64(i, 4));
        r++;
    }
    tbl_LocalLimit_TD_1122885_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1122885_output #Row: " << tbl_LocalLimit_TD_1122885_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0481036(Table &tbl_LocalLimit_TD_1122885_output, Table &tbl_GlobalLimit_TD_0481036_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(channel#4726, id#4727, sales#4559, returns#4560, profit#4561)
    // Output: ListBuffer(channel#4726, id#4727, sales#4559, returns#4560, profit#4561)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _channel4726_n = tbl_LocalLimit_TD_1122885_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0481036_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _channel4726_n);
        std::array<char, TPCDS_READ_MAX + 1> _id4727_n = tbl_LocalLimit_TD_1122885_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_0481036_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _id4727_n);
        tbl_GlobalLimit_TD_0481036_output.setInt64(r, 2, tbl_LocalLimit_TD_1122885_output.getInt64(i, 2));
        tbl_GlobalLimit_TD_0481036_output.setInt64(r, 3, tbl_LocalLimit_TD_1122885_output.getInt64(i, 3));
        tbl_GlobalLimit_TD_0481036_output.setInt64(r, 4, tbl_LocalLimit_TD_1122885_output.getInt64(i, 4));
        r++;
    }
    tbl_GlobalLimit_TD_0481036_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0481036_output #Row: " << tbl_GlobalLimit_TD_0481036_output.getNumRow() << std::endl;
}

