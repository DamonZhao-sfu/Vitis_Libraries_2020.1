#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_9905864(Table &tbl_SerializeFromObject_TD_10676252_input, Table &tbl_Filter_TD_9905864_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_year#3620) AND isnotnull(d_moy#3622)) AND ((d_year#3620 = 1998) AND (d_moy#3622 = 9))) AND isnotnull(d_date_sk#3614)))
    // Input: ListBuffer(d_date_sk#3614, d_year#3620, d_moy#3622)
    // Output: ListBuffer(d_date_sk#3614)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10676252_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3620 = tbl_SerializeFromObject_TD_10676252_input.getInt32(i, 1);
        int32_t _d_moy3622 = tbl_SerializeFromObject_TD_10676252_input.getInt32(i, 2);
        int32_t _d_date_sk3614 = tbl_SerializeFromObject_TD_10676252_input.getInt32(i, 0);
        if ((((_d_year3620!= 0) && (_d_moy3622!= 0)) && ((_d_year3620 == 1998) && (_d_moy3622 == 9))) && (_d_date_sk3614!= 0)) {
            int32_t _d_date_sk3614_t = tbl_SerializeFromObject_TD_10676252_input.getInt32(i, 0);
            tbl_Filter_TD_9905864_output.setInt32(r, 0, _d_date_sk3614_t);
            r++;
        }
    }
    tbl_Filter_TD_9905864_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9905864_output #Row: " << tbl_Filter_TD_9905864_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9848935(Table &tbl_SerializeFromObject_TD_10881630_input, Table &tbl_Filter_TD_9848935_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_sold_date_sk#729) AND (isnotnull(ws_bill_addr_sk#736) AND isnotnull(ws_item_sk#732))))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_bill_addr_sk#736, ws_ext_sales_price#752)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_bill_addr_sk#736, ws_ext_sales_price#752)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10881630_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_10881630_input.getInt32(i, 0);
        int32_t _ws_bill_addr_sk736 = tbl_SerializeFromObject_TD_10881630_input.getInt32(i, 2);
        int32_t _ws_item_sk732 = tbl_SerializeFromObject_TD_10881630_input.getInt32(i, 1);
        if ((_ws_sold_date_sk729!= 0) && ((_ws_bill_addr_sk736!= 0) && (_ws_item_sk732!= 0))) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_10881630_input.getInt32(i, 0);
            tbl_Filter_TD_9848935_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_item_sk732_t = tbl_SerializeFromObject_TD_10881630_input.getInt32(i, 1);
            tbl_Filter_TD_9848935_output.setInt32(r, 1, _ws_item_sk732_t);
            int32_t _ws_bill_addr_sk736_t = tbl_SerializeFromObject_TD_10881630_input.getInt32(i, 2);
            tbl_Filter_TD_9848935_output.setInt32(r, 2, _ws_bill_addr_sk736_t);
            int64_t _ws_ext_sales_price752_t = tbl_SerializeFromObject_TD_10881630_input.getInt64(i, 3);
            tbl_Filter_TD_9848935_output.setInt64(r, 3, _ws_ext_sales_price752_t);
            r++;
        }
    }
    tbl_Filter_TD_9848935_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9848935_output #Row: " << tbl_Filter_TD_9848935_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9921276(Table &tbl_SerializeFromObject_TD_10452129_input, Table &tbl_Filter_TD_9921276_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_year#3557) AND isnotnull(d_moy#3559)) AND ((d_year#3557 = 1998) AND (d_moy#3559 = 9))) AND isnotnull(d_date_sk#3551)))
    // Input: ListBuffer(d_date_sk#3551, d_year#3557, d_moy#3559)
    // Output: ListBuffer(d_date_sk#3551)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10452129_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3557 = tbl_SerializeFromObject_TD_10452129_input.getInt32(i, 1);
        int32_t _d_moy3559 = tbl_SerializeFromObject_TD_10452129_input.getInt32(i, 2);
        int32_t _d_date_sk3551 = tbl_SerializeFromObject_TD_10452129_input.getInt32(i, 0);
        if ((((_d_year3557!= 0) && (_d_moy3559!= 0)) && ((_d_year3557 == 1998) && (_d_moy3559 == 9))) && (_d_date_sk3551!= 0)) {
            int32_t _d_date_sk3551_t = tbl_SerializeFromObject_TD_10452129_input.getInt32(i, 0);
            tbl_Filter_TD_9921276_output.setInt32(r, 0, _d_date_sk3551_t);
            r++;
        }
    }
    tbl_Filter_TD_9921276_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9921276_output #Row: " << tbl_Filter_TD_9921276_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9573092(Table &tbl_SerializeFromObject_TD_1079370_input, Table &tbl_Filter_TD_9573092_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cs_sold_date_sk#1104) AND (isnotnull(cs_bill_addr_sk#1110) AND isnotnull(cs_item_sk#1119))))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_bill_addr_sk#1110, cs_item_sk#1119, cs_ext_sales_price#1127)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_bill_addr_sk#1110, cs_item_sk#1119, cs_ext_sales_price#1127)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1079370_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_1079370_input.getInt32(i, 0);
        int32_t _cs_bill_addr_sk1110 = tbl_SerializeFromObject_TD_1079370_input.getInt32(i, 1);
        int32_t _cs_item_sk1119 = tbl_SerializeFromObject_TD_1079370_input.getInt32(i, 2);
        if ((_cs_sold_date_sk1104!= 0) && ((_cs_bill_addr_sk1110!= 0) && (_cs_item_sk1119!= 0))) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_1079370_input.getInt32(i, 0);
            tbl_Filter_TD_9573092_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int32_t _cs_bill_addr_sk1110_t = tbl_SerializeFromObject_TD_1079370_input.getInt32(i, 1);
            tbl_Filter_TD_9573092_output.setInt32(r, 1, _cs_bill_addr_sk1110_t);
            int32_t _cs_item_sk1119_t = tbl_SerializeFromObject_TD_1079370_input.getInt32(i, 2);
            tbl_Filter_TD_9573092_output.setInt32(r, 2, _cs_item_sk1119_t);
            int64_t _cs_ext_sales_price1127_t = tbl_SerializeFromObject_TD_1079370_input.getInt64(i, 3);
            tbl_Filter_TD_9573092_output.setInt64(r, 3, _cs_ext_sales_price1127_t);
            r++;
        }
    }
    tbl_Filter_TD_9573092_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9573092_output #Row: " << tbl_Filter_TD_9573092_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9696288(Table &tbl_SerializeFromObject_TD_10428004_input, Table &tbl_Filter_TD_9696288_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_year#126) AND isnotnull(d_moy#128)) AND ((d_year#126 = 1998) AND (d_moy#128 = 9))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126, d_moy#128)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10428004_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_10428004_input.getInt32(i, 1);
        int32_t _d_moy128 = tbl_SerializeFromObject_TD_10428004_input.getInt32(i, 2);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_10428004_input.getInt32(i, 0);
        if ((((_d_year126!= 0) && (_d_moy128!= 0)) && ((_d_year126 == 1998) && (_d_moy128 == 9))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_10428004_input.getInt32(i, 0);
            tbl_Filter_TD_9696288_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_9696288_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9696288_output #Row: " << tbl_Filter_TD_9696288_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9373438(Table &tbl_SerializeFromObject_TD_10408232_input, Table &tbl_Filter_TD_9373438_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_sold_date_sk#1206) AND (isnotnull(ss_addr_sk#1212) AND isnotnull(ss_item_sk#1208))))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_addr_sk#1212, ss_ext_sales_price#1221)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_addr_sk#1212, ss_ext_sales_price#1221)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10408232_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_10408232_input.getInt32(i, 0);
        int32_t _ss_addr_sk1212 = tbl_SerializeFromObject_TD_10408232_input.getInt32(i, 2);
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_10408232_input.getInt32(i, 1);
        if ((_ss_sold_date_sk1206!= 0) && ((_ss_addr_sk1212!= 0) && (_ss_item_sk1208!= 0))) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_10408232_input.getInt32(i, 0);
            tbl_Filter_TD_9373438_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_10408232_input.getInt32(i, 1);
            tbl_Filter_TD_9373438_output.setInt32(r, 1, _ss_item_sk1208_t);
            int32_t _ss_addr_sk1212_t = tbl_SerializeFromObject_TD_10408232_input.getInt32(i, 2);
            tbl_Filter_TD_9373438_output.setInt32(r, 2, _ss_addr_sk1212_t);
            int64_t _ss_ext_sales_price1221_t = tbl_SerializeFromObject_TD_10408232_input.getInt64(i, 3);
            tbl_Filter_TD_9373438_output.setInt64(r, 3, _ss_ext_sales_price1221_t);
            r++;
        }
    }
    tbl_Filter_TD_9373438_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9373438_output #Row: " << tbl_Filter_TD_9373438_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8188749(Table &tbl_SerializeFromObject_TD_9187609_input, Table &tbl_Filter_TD_8188749_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(i_category#3733) AND (i_category#3733 = Music)))
    // Input: ListBuffer(i_item_id#3722, i_category#3733)
    // Output: ListBuffer(i_item_id#3722)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9187609_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category3733 = tbl_SerializeFromObject_TD_9187609_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if (_i_category3733.data() != "NULL" && (std::string(_i_category3733.data()) == "Music")) {
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id3722_t = tbl_SerializeFromObject_TD_9187609_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            tbl_Filter_TD_8188749_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id3722_t);
            r++;
        }
    }
    tbl_Filter_TD_8188749_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8188749_output #Row: " << tbl_Filter_TD_8188749_output.getNumRow() << std::endl;
}

void SW_Filter_TD_864645(Table &tbl_SerializeFromObject_TD_9274214_input, Table &tbl_Filter_TD_864645_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#3655))
    // Input: ListBuffer(i_item_sk#3655, i_item_id#3656)
    // Output: ListBuffer(i_item_sk#3655, i_item_id#3656)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9274214_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk3655 = tbl_SerializeFromObject_TD_9274214_input.getInt32(i, 0);
        if (_i_item_sk3655!= 0) {
            int32_t _i_item_sk3655_t = tbl_SerializeFromObject_TD_9274214_input.getInt32(i, 0);
            tbl_Filter_TD_864645_output.setInt32(r, 0, _i_item_sk3655_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id3656_t = tbl_SerializeFromObject_TD_9274214_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_864645_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id3656_t);
            r++;
        }
    }
    tbl_Filter_TD_864645_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_864645_output #Row: " << tbl_Filter_TD_864645_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8312215(Table &tbl_SerializeFromObject_TD_9208467_input, Table &tbl_Filter_TD_8312215_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ca_gmt_offset#3653) AND (ca_gmt_offset#3653 = -5.00)) AND isnotnull(ca_address_sk#3642)))
    // Input: ListBuffer(ca_address_sk#3642, ca_gmt_offset#3653)
    // Output: ListBuffer(ca_address_sk#3642)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9208467_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ca_gmt_offset3653 = tbl_SerializeFromObject_TD_9208467_input.getInt64(i, 1);
        int32_t _ca_address_sk3642 = tbl_SerializeFromObject_TD_9208467_input.getInt32(i, 0);
        if (((_ca_gmt_offset3653!= 0) && (_ca_gmt_offset3653 == -5.00)) && (_ca_address_sk3642!= 0)) {
            int32_t _ca_address_sk3642_t = tbl_SerializeFromObject_TD_9208467_input.getInt32(i, 0);
            tbl_Filter_TD_8312215_output.setInt32(r, 0, _ca_address_sk3642_t);
            r++;
        }
    }
    tbl_Filter_TD_8312215_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8312215_output #Row: " << tbl_Filter_TD_8312215_output.getNumRow() << std::endl;
}


void SW_Filter_TD_8125778(Table &tbl_SerializeFromObject_TD_9396460_input, Table &tbl_Filter_TD_8125778_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(i_category#3711) AND (i_category#3711 = Music)))
    // Input: ListBuffer(i_item_id#3700, i_category#3711)
    // Output: ListBuffer(i_item_id#3700)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9396460_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category3711 = tbl_SerializeFromObject_TD_9396460_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if (_i_category3711.data() != "NULL" && (std::string(_i_category3711.data()) == "Music")) {
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id3700_t = tbl_SerializeFromObject_TD_9396460_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            tbl_Filter_TD_8125778_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id3700_t);
            r++;
        }
    }
    tbl_Filter_TD_8125778_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8125778_output #Row: " << tbl_Filter_TD_8125778_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8631630(Table &tbl_SerializeFromObject_TD_9316845_input, Table &tbl_Filter_TD_8631630_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#3592))
    // Input: ListBuffer(i_item_sk#3592, i_item_id#3593)
    // Output: ListBuffer(i_item_sk#3592, i_item_id#3593)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9316845_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk3592 = tbl_SerializeFromObject_TD_9316845_input.getInt32(i, 0);
        if (_i_item_sk3592!= 0) {
            int32_t _i_item_sk3592_t = tbl_SerializeFromObject_TD_9316845_input.getInt32(i, 0);
            tbl_Filter_TD_8631630_output.setInt32(r, 0, _i_item_sk3592_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id3593_t = tbl_SerializeFromObject_TD_9316845_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_8631630_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id3593_t);
            r++;
        }
    }
    tbl_Filter_TD_8631630_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8631630_output #Row: " << tbl_Filter_TD_8631630_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8836925(Table &tbl_SerializeFromObject_TD_9982138_input, Table &tbl_Filter_TD_8836925_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ca_gmt_offset#3590) AND (ca_gmt_offset#3590 = -5.00)) AND isnotnull(ca_address_sk#3579)))
    // Input: ListBuffer(ca_address_sk#3579, ca_gmt_offset#3590)
    // Output: ListBuffer(ca_address_sk#3579)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9982138_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ca_gmt_offset3590 = tbl_SerializeFromObject_TD_9982138_input.getInt64(i, 1);
        int32_t _ca_address_sk3579 = tbl_SerializeFromObject_TD_9982138_input.getInt32(i, 0);
        if (((_ca_gmt_offset3590!= 0) && (_ca_gmt_offset3590 == -5.00)) && (_ca_address_sk3579!= 0)) {
            int32_t _ca_address_sk3579_t = tbl_SerializeFromObject_TD_9982138_input.getInt32(i, 0);
            tbl_Filter_TD_8836925_output.setInt32(r, 0, _ca_address_sk3579_t);
            r++;
        }
    }
    tbl_Filter_TD_8836925_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8836925_output #Row: " << tbl_Filter_TD_8836925_output.getNumRow() << std::endl;
}


void SW_Filter_TD_8719793(Table &tbl_SerializeFromObject_TD_9760548_input, Table &tbl_Filter_TD_8719793_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(i_category#3689) AND (i_category#3689 = Music)))
    // Input: ListBuffer(i_item_id#3678, i_category#3689)
    // Output: ListBuffer(i_item_id#3678)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9760548_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category3689 = tbl_SerializeFromObject_TD_9760548_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if (_i_category3689.data() != "NULL" && (std::string(_i_category3689.data()) == "Music")) {
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id3678_t = tbl_SerializeFromObject_TD_9760548_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            tbl_Filter_TD_8719793_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id3678_t);
            r++;
        }
    }
    tbl_Filter_TD_8719793_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8719793_output #Row: " << tbl_Filter_TD_8719793_output.getNumRow() << std::endl;
}

void SW_Filter_TD_876093(Table &tbl_SerializeFromObject_TD_9324260_input, Table &tbl_Filter_TD_876093_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#228))
    // Input: ListBuffer(i_item_sk#228, i_item_id#229)
    // Output: ListBuffer(i_item_sk#228, i_item_id#229)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9324260_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_9324260_input.getInt32(i, 0);
        if (_i_item_sk228!= 0) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_9324260_input.getInt32(i, 0);
            tbl_Filter_TD_876093_output.setInt32(r, 0, _i_item_sk228_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_t = tbl_SerializeFromObject_TD_9324260_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_876093_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id229_t);
            r++;
        }
    }
    tbl_Filter_TD_876093_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_876093_output #Row: " << tbl_Filter_TD_876093_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8267550(Table &tbl_SerializeFromObject_TD_9327842_input, Table &tbl_Filter_TD_8267550_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ca_gmt_offset#65) AND (ca_gmt_offset#65 = -5.00)) AND isnotnull(ca_address_sk#54)))
    // Input: ListBuffer(ca_address_sk#54, ca_gmt_offset#65)
    // Output: ListBuffer(ca_address_sk#54)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9327842_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ca_gmt_offset65 = tbl_SerializeFromObject_TD_9327842_input.getInt64(i, 1);
        int32_t _ca_address_sk54 = tbl_SerializeFromObject_TD_9327842_input.getInt32(i, 0);
        if (((_ca_gmt_offset65!= 0) && (_ca_gmt_offset65 == -5.00)) && (_ca_address_sk54!= 0)) {
            int32_t _ca_address_sk54_t = tbl_SerializeFromObject_TD_9327842_input.getInt32(i, 0);
            tbl_Filter_TD_8267550_output.setInt32(r, 0, _ca_address_sk54_t);
            r++;
        }
    }
    tbl_Filter_TD_8267550_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8267550_output #Row: " << tbl_Filter_TD_8267550_output.getNumRow() << std::endl;
}


struct SW_JOIN_LEFTSEMI_TD_794456_key_leftMajor {
    std::string _i_item_id3656;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_794456_key_leftMajor& other) const {
        return ((_i_item_id3656 == other._i_item_id3656));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_794456_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_794456_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_item_id3656));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_794456_payload_leftMajor {
    int32_t _i_item_sk3655;
    std::string _i_item_id3656;
};
struct SW_JOIN_LEFTSEMI_TD_794456_key_rightMajor {
    std::string _i_item_id3722;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_794456_key_rightMajor& other) const {
        return ((_i_item_id3722 == other._i_item_id3722));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_794456_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_794456_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_item_id3722));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_794456_payload_rightMajor {
    std::string _i_item_id3722;
};
void SW_JOIN_LEFTSEMI_TD_794456(Table &tbl_Filter_TD_864645_output, Table &tbl_Filter_TD_8188749_output, Table &tbl_JOIN_LEFTSEMI_TD_794456_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTSEMI
    // Operation: ListBuffer((i_item_id#3656 = i_item_id#3722))
    // Left Table: ListBuffer(i_item_sk#3655, i_item_id#3656)
    // Right Table: ListBuffer(i_item_id#3722)
    // Output Table: ListBuffer(i_item_sk#3655, i_item_id#3656)
    int left_nrow = tbl_Filter_TD_864645_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8188749_output.getNumRow();
        std::unordered_map<SW_JOIN_LEFTSEMI_TD_794456_key_rightMajor, SW_JOIN_LEFTSEMI_TD_794456_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8188749_output.getNumRow();
        int nrow2 = tbl_Filter_TD_864645_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id3722_k_n = tbl_Filter_TD_8188749_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_item_id3722_k = std::string(_i_item_id3722_k_n.data());
            SW_JOIN_LEFTSEMI_TD_794456_key_rightMajor keyA{_i_item_id3722_k};
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id3722_n = tbl_Filter_TD_8188749_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_item_id3722 = std::string(_i_item_id3722_n.data());
            SW_JOIN_LEFTSEMI_TD_794456_payload_rightMajor payloadA{_i_item_id3722};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id3656_k_n = tbl_Filter_TD_864645_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_item_id3656_k = std::string(_i_item_id3656_k_n.data());
            auto it = ht1.find(SW_JOIN_LEFTSEMI_TD_794456_key_rightMajor{_i_item_id3656_k});
            if (it != ht1.end()) {
                int32_t _i_item_sk3655 = tbl_Filter_TD_864645_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id3656 = tbl_Filter_TD_864645_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                tbl_JOIN_LEFTSEMI_TD_794456_output.setInt32(r, 0, _i_item_sk3655);
                tbl_JOIN_LEFTSEMI_TD_794456_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id3656);
                r++;
            }
        }
        tbl_JOIN_LEFTSEMI_TD_794456_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTSEMI_TD_794456_output #Row: " << tbl_JOIN_LEFTSEMI_TD_794456_output.getNumRow() << std::endl;
}


struct SW_JOIN_LEFTSEMI_TD_7822991_key_leftMajor {
    std::string _i_item_id3593;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_7822991_key_leftMajor& other) const {
        return ((_i_item_id3593 == other._i_item_id3593));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_7822991_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_7822991_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_item_id3593));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_7822991_payload_leftMajor {
    int32_t _i_item_sk3592;
    std::string _i_item_id3593;
};
struct SW_JOIN_LEFTSEMI_TD_7822991_key_rightMajor {
    std::string _i_item_id3700;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_7822991_key_rightMajor& other) const {
        return ((_i_item_id3700 == other._i_item_id3700));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_7822991_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_7822991_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_item_id3700));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_7822991_payload_rightMajor {
    std::string _i_item_id3700;
};
void SW_JOIN_LEFTSEMI_TD_7822991(Table &tbl_Filter_TD_8631630_output, Table &tbl_Filter_TD_8125778_output, Table &tbl_JOIN_LEFTSEMI_TD_7822991_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTSEMI
    // Operation: ListBuffer((i_item_id#3593 = i_item_id#3700))
    // Left Table: ListBuffer(i_item_sk#3592, i_item_id#3593)
    // Right Table: ListBuffer(i_item_id#3700)
    // Output Table: ListBuffer(i_item_sk#3592, i_item_id#3593)
    int left_nrow = tbl_Filter_TD_8631630_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8125778_output.getNumRow();
        std::unordered_map<SW_JOIN_LEFTSEMI_TD_7822991_key_rightMajor, SW_JOIN_LEFTSEMI_TD_7822991_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8125778_output.getNumRow();
        int nrow2 = tbl_Filter_TD_8631630_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id3700_k_n = tbl_Filter_TD_8125778_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_item_id3700_k = std::string(_i_item_id3700_k_n.data());
            SW_JOIN_LEFTSEMI_TD_7822991_key_rightMajor keyA{_i_item_id3700_k};
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id3700_n = tbl_Filter_TD_8125778_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_item_id3700 = std::string(_i_item_id3700_n.data());
            SW_JOIN_LEFTSEMI_TD_7822991_payload_rightMajor payloadA{_i_item_id3700};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id3593_k_n = tbl_Filter_TD_8631630_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_item_id3593_k = std::string(_i_item_id3593_k_n.data());
            auto it = ht1.find(SW_JOIN_LEFTSEMI_TD_7822991_key_rightMajor{_i_item_id3593_k});
            if (it != ht1.end()) {
                int32_t _i_item_sk3592 = tbl_Filter_TD_8631630_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id3593 = tbl_Filter_TD_8631630_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                tbl_JOIN_LEFTSEMI_TD_7822991_output.setInt32(r, 0, _i_item_sk3592);
                tbl_JOIN_LEFTSEMI_TD_7822991_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id3593);
                r++;
            }
        }
        tbl_JOIN_LEFTSEMI_TD_7822991_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTSEMI_TD_7822991_output #Row: " << tbl_JOIN_LEFTSEMI_TD_7822991_output.getNumRow() << std::endl;
}


struct SW_JOIN_LEFTSEMI_TD_7600525_key_leftMajor {
    std::string _i_item_id229;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_7600525_key_leftMajor& other) const {
        return ((_i_item_id229 == other._i_item_id229));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_7600525_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_7600525_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_item_id229));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_7600525_payload_leftMajor {
    int32_t _i_item_sk228;
    std::string _i_item_id229;
};
struct SW_JOIN_LEFTSEMI_TD_7600525_key_rightMajor {
    std::string _i_item_id3678;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_7600525_key_rightMajor& other) const {
        return ((_i_item_id3678 == other._i_item_id3678));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_7600525_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_7600525_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_item_id3678));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_7600525_payload_rightMajor {
    std::string _i_item_id3678;
};
void SW_JOIN_LEFTSEMI_TD_7600525(Table &tbl_Filter_TD_876093_output, Table &tbl_Filter_TD_8719793_output, Table &tbl_JOIN_LEFTSEMI_TD_7600525_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTSEMI
    // Operation: ListBuffer((i_item_id#229 = i_item_id#3678))
    // Left Table: ListBuffer(i_item_sk#228, i_item_id#229)
    // Right Table: ListBuffer(i_item_id#3678)
    // Output Table: ListBuffer(i_item_sk#228, i_item_id#229)
    int left_nrow = tbl_Filter_TD_876093_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8719793_output.getNumRow();
        std::unordered_map<SW_JOIN_LEFTSEMI_TD_7600525_key_rightMajor, SW_JOIN_LEFTSEMI_TD_7600525_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8719793_output.getNumRow();
        int nrow2 = tbl_Filter_TD_876093_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id3678_k_n = tbl_Filter_TD_8719793_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_item_id3678_k = std::string(_i_item_id3678_k_n.data());
            SW_JOIN_LEFTSEMI_TD_7600525_key_rightMajor keyA{_i_item_id3678_k};
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id3678_n = tbl_Filter_TD_8719793_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_item_id3678 = std::string(_i_item_id3678_n.data());
            SW_JOIN_LEFTSEMI_TD_7600525_payload_rightMajor payloadA{_i_item_id3678};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_k_n = tbl_Filter_TD_876093_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_item_id229_k = std::string(_i_item_id229_k_n.data());
            auto it = ht1.find(SW_JOIN_LEFTSEMI_TD_7600525_key_rightMajor{_i_item_id229_k});
            if (it != ht1.end()) {
                int32_t _i_item_sk228 = tbl_Filter_TD_876093_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id229 = tbl_Filter_TD_876093_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                tbl_JOIN_LEFTSEMI_TD_7600525_output.setInt32(r, 0, _i_item_sk228);
                tbl_JOIN_LEFTSEMI_TD_7600525_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id229);
                r++;
            }
        }
        tbl_JOIN_LEFTSEMI_TD_7600525_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTSEMI_TD_7600525_output #Row: " << tbl_JOIN_LEFTSEMI_TD_7600525_output.getNumRow() << std::endl;
}


struct SW_JOIN_INNER_TD_6561024_key_leftMajor {
    int32_t _ws_item_sk732;
    bool operator==(const SW_JOIN_INNER_TD_6561024_key_leftMajor& other) const {
        return ((_ws_item_sk732 == other._ws_item_sk732));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6561024_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6561024_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_item_sk732));
    }
};
}
struct SW_JOIN_INNER_TD_6561024_payload_leftMajor {
    int32_t _ws_item_sk732;
    int64_t _ws_ext_sales_price752;
};
struct SW_JOIN_INNER_TD_6561024_key_rightMajor {
    int32_t _i_item_sk3655;
    bool operator==(const SW_JOIN_INNER_TD_6561024_key_rightMajor& other) const {
        return ((_i_item_sk3655 == other._i_item_sk3655));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6561024_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6561024_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk3655));
    }
};
}
struct SW_JOIN_INNER_TD_6561024_payload_rightMajor {
    int32_t _i_item_sk3655;
    std::string _i_item_id3656;
};
void SW_JOIN_INNER_TD_6561024(Table &tbl_JOIN_INNER_TD_7719503_output, Table &tbl_JOIN_LEFTSEMI_TD_794456_output, Table &tbl_JOIN_INNER_TD_6561024_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_item_sk#732 = i_item_sk#3655))
    // Left Table: ListBuffer(ws_item_sk#732, ws_ext_sales_price#752)
    // Right Table: ListBuffer(i_item_sk#3655, i_item_id#3656)
    // Output Table: ListBuffer(ws_ext_sales_price#752, i_item_id#3656)
    int left_nrow = tbl_JOIN_INNER_TD_7719503_output.getNumRow();
    int right_nrow = tbl_JOIN_LEFTSEMI_TD_794456_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6561024_key_leftMajor, SW_JOIN_INNER_TD_6561024_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7719503_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_item_sk732_k = tbl_JOIN_INNER_TD_7719503_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6561024_key_leftMajor keyA{_ws_item_sk732_k};
            int32_t _ws_item_sk732 = tbl_JOIN_INNER_TD_7719503_output.getInt32(i, 0);
            int64_t _ws_ext_sales_price752 = tbl_JOIN_INNER_TD_7719503_output.getInt64(i, 1);
            SW_JOIN_INNER_TD_6561024_payload_leftMajor payloadA{_ws_item_sk732, _ws_ext_sales_price752};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_LEFTSEMI_TD_794456_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk3655_k = tbl_JOIN_LEFTSEMI_TD_794456_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6561024_key_leftMajor{_i_item_sk3655_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_item_sk732 = (it->second)._ws_item_sk732;
                int64_t _ws_ext_sales_price752 = (it->second)._ws_ext_sales_price752;
                int32_t _i_item_sk3655 = tbl_JOIN_LEFTSEMI_TD_794456_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id3656_n = tbl_JOIN_LEFTSEMI_TD_794456_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_item_id3656 = std::string(_i_item_id3656_n.data());
                tbl_JOIN_INNER_TD_6561024_output.setInt64(r, 0, _ws_ext_sales_price752);
                tbl_JOIN_INNER_TD_6561024_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id3656_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6561024_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6561024_key_rightMajor, SW_JOIN_INNER_TD_6561024_payload_rightMajor> ht1;
        int nrow1 = tbl_JOIN_LEFTSEMI_TD_794456_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk3655_k = tbl_JOIN_LEFTSEMI_TD_794456_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6561024_key_rightMajor keyA{_i_item_sk3655_k};
            int32_t _i_item_sk3655 = tbl_JOIN_LEFTSEMI_TD_794456_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id3656_n = tbl_JOIN_LEFTSEMI_TD_794456_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_item_id3656 = std::string(_i_item_id3656_n.data());
            SW_JOIN_INNER_TD_6561024_payload_rightMajor payloadA{_i_item_sk3655, _i_item_id3656};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7719503_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_item_sk732_k = tbl_JOIN_INNER_TD_7719503_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6561024_key_rightMajor{_ws_item_sk732_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk3655 = (it->second)._i_item_sk3655;
                std::string _i_item_id3656 = (it->second)._i_item_id3656;
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id3656_n{};
                memcpy(_i_item_id3656_n.data(), (_i_item_id3656).data(), (_i_item_id3656).length());
                int32_t _ws_item_sk732 = tbl_JOIN_INNER_TD_7719503_output.getInt32(i, 0);
                int64_t _ws_ext_sales_price752 = tbl_JOIN_INNER_TD_7719503_output.getInt64(i, 1);
                tbl_JOIN_INNER_TD_6561024_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id3656_n);
                tbl_JOIN_INNER_TD_6561024_output.setInt64(r, 0, _ws_ext_sales_price752);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6561024_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6561024_output #Row: " << tbl_JOIN_INNER_TD_6561024_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6260223_key_leftMajor {
    int32_t _cs_item_sk1119;
    bool operator==(const SW_JOIN_INNER_TD_6260223_key_leftMajor& other) const {
        return ((_cs_item_sk1119 == other._cs_item_sk1119));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6260223_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6260223_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_item_sk1119));
    }
};
}
struct SW_JOIN_INNER_TD_6260223_payload_leftMajor {
    int32_t _cs_item_sk1119;
    int64_t _cs_ext_sales_price1127;
};
struct SW_JOIN_INNER_TD_6260223_key_rightMajor {
    int32_t _i_item_sk3592;
    bool operator==(const SW_JOIN_INNER_TD_6260223_key_rightMajor& other) const {
        return ((_i_item_sk3592 == other._i_item_sk3592));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6260223_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6260223_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk3592));
    }
};
}
struct SW_JOIN_INNER_TD_6260223_payload_rightMajor {
    int32_t _i_item_sk3592;
    std::string _i_item_id3593;
};
void SW_JOIN_INNER_TD_6260223(Table &tbl_JOIN_INNER_TD_7858959_output, Table &tbl_JOIN_LEFTSEMI_TD_7822991_output, Table &tbl_JOIN_INNER_TD_6260223_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_item_sk#1119 = i_item_sk#3592))
    // Left Table: ListBuffer(cs_item_sk#1119, cs_ext_sales_price#1127)
    // Right Table: ListBuffer(i_item_sk#3592, i_item_id#3593)
    // Output Table: ListBuffer(cs_ext_sales_price#1127, i_item_id#3593)
    int left_nrow = tbl_JOIN_INNER_TD_7858959_output.getNumRow();
    int right_nrow = tbl_JOIN_LEFTSEMI_TD_7822991_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6260223_key_leftMajor, SW_JOIN_INNER_TD_6260223_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7858959_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_item_sk1119_k = tbl_JOIN_INNER_TD_7858959_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6260223_key_leftMajor keyA{_cs_item_sk1119_k};
            int32_t _cs_item_sk1119 = tbl_JOIN_INNER_TD_7858959_output.getInt32(i, 0);
            int64_t _cs_ext_sales_price1127 = tbl_JOIN_INNER_TD_7858959_output.getInt64(i, 1);
            SW_JOIN_INNER_TD_6260223_payload_leftMajor payloadA{_cs_item_sk1119, _cs_ext_sales_price1127};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_LEFTSEMI_TD_7822991_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk3592_k = tbl_JOIN_LEFTSEMI_TD_7822991_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6260223_key_leftMajor{_i_item_sk3592_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_item_sk1119 = (it->second)._cs_item_sk1119;
                int64_t _cs_ext_sales_price1127 = (it->second)._cs_ext_sales_price1127;
                int32_t _i_item_sk3592 = tbl_JOIN_LEFTSEMI_TD_7822991_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id3593_n = tbl_JOIN_LEFTSEMI_TD_7822991_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_item_id3593 = std::string(_i_item_id3593_n.data());
                tbl_JOIN_INNER_TD_6260223_output.setInt64(r, 0, _cs_ext_sales_price1127);
                tbl_JOIN_INNER_TD_6260223_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id3593_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6260223_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6260223_key_rightMajor, SW_JOIN_INNER_TD_6260223_payload_rightMajor> ht1;
        int nrow1 = tbl_JOIN_LEFTSEMI_TD_7822991_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk3592_k = tbl_JOIN_LEFTSEMI_TD_7822991_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6260223_key_rightMajor keyA{_i_item_sk3592_k};
            int32_t _i_item_sk3592 = tbl_JOIN_LEFTSEMI_TD_7822991_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id3593_n = tbl_JOIN_LEFTSEMI_TD_7822991_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_item_id3593 = std::string(_i_item_id3593_n.data());
            SW_JOIN_INNER_TD_6260223_payload_rightMajor payloadA{_i_item_sk3592, _i_item_id3593};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7858959_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_item_sk1119_k = tbl_JOIN_INNER_TD_7858959_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6260223_key_rightMajor{_cs_item_sk1119_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk3592 = (it->second)._i_item_sk3592;
                std::string _i_item_id3593 = (it->second)._i_item_id3593;
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id3593_n{};
                memcpy(_i_item_id3593_n.data(), (_i_item_id3593).data(), (_i_item_id3593).length());
                int32_t _cs_item_sk1119 = tbl_JOIN_INNER_TD_7858959_output.getInt32(i, 0);
                int64_t _cs_ext_sales_price1127 = tbl_JOIN_INNER_TD_7858959_output.getInt64(i, 1);
                tbl_JOIN_INNER_TD_6260223_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id3593_n);
                tbl_JOIN_INNER_TD_6260223_output.setInt64(r, 0, _cs_ext_sales_price1127);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6260223_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6260223_output #Row: " << tbl_JOIN_INNER_TD_6260223_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6520657_key_leftMajor {
    int32_t _ss_item_sk1208;
    bool operator==(const SW_JOIN_INNER_TD_6520657_key_leftMajor& other) const {
        return ((_ss_item_sk1208 == other._ss_item_sk1208));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6520657_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6520657_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk1208));
    }
};
}
struct SW_JOIN_INNER_TD_6520657_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int64_t _ss_ext_sales_price1221;
};
struct SW_JOIN_INNER_TD_6520657_key_rightMajor {
    int32_t _i_item_sk228;
    bool operator==(const SW_JOIN_INNER_TD_6520657_key_rightMajor& other) const {
        return ((_i_item_sk228 == other._i_item_sk228));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6520657_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6520657_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk228));
    }
};
}
struct SW_JOIN_INNER_TD_6520657_payload_rightMajor {
    int32_t _i_item_sk228;
    std::string _i_item_id229;
};
void SW_JOIN_INNER_TD_6520657(Table &tbl_JOIN_INNER_TD_7798154_output, Table &tbl_JOIN_LEFTSEMI_TD_7600525_output, Table &tbl_JOIN_INNER_TD_6520657_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_item_sk#1208 = i_item_sk#228))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_ext_sales_price#1221)
    // Right Table: ListBuffer(i_item_sk#228, i_item_id#229)
    // Output Table: ListBuffer(ss_ext_sales_price#1221, i_item_id#229)
    int left_nrow = tbl_JOIN_INNER_TD_7798154_output.getNumRow();
    int right_nrow = tbl_JOIN_LEFTSEMI_TD_7600525_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6520657_key_leftMajor, SW_JOIN_INNER_TD_6520657_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7798154_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_7798154_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6520657_key_leftMajor keyA{_ss_item_sk1208_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_7798154_output.getInt32(i, 0);
            int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_7798154_output.getInt64(i, 1);
            SW_JOIN_INNER_TD_6520657_payload_leftMajor payloadA{_ss_item_sk1208, _ss_ext_sales_price1221};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_LEFTSEMI_TD_7600525_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk228_k = tbl_JOIN_LEFTSEMI_TD_7600525_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6520657_key_leftMajor{_i_item_sk228_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int32_t _i_item_sk228 = tbl_JOIN_LEFTSEMI_TD_7600525_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_JOIN_LEFTSEMI_TD_7600525_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_item_id229 = std::string(_i_item_id229_n.data());
                tbl_JOIN_INNER_TD_6520657_output.setInt64(r, 0, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_6520657_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id229_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6520657_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6520657_key_rightMajor, SW_JOIN_INNER_TD_6520657_payload_rightMajor> ht1;
        int nrow1 = tbl_JOIN_LEFTSEMI_TD_7600525_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk228_k = tbl_JOIN_LEFTSEMI_TD_7600525_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6520657_key_rightMajor keyA{_i_item_sk228_k};
            int32_t _i_item_sk228 = tbl_JOIN_LEFTSEMI_TD_7600525_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_JOIN_LEFTSEMI_TD_7600525_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_item_id229 = std::string(_i_item_id229_n.data());
            SW_JOIN_INNER_TD_6520657_payload_rightMajor payloadA{_i_item_sk228, _i_item_id229};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7798154_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_7798154_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6520657_key_rightMajor{_ss_item_sk1208_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                std::string _i_item_id229 = (it->second)._i_item_id229;
                std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n{};
                memcpy(_i_item_id229_n.data(), (_i_item_id229).data(), (_i_item_id229).length());
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_7798154_output.getInt32(i, 0);
                int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_7798154_output.getInt64(i, 1);
                tbl_JOIN_INNER_TD_6520657_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_id229_n);
                tbl_JOIN_INNER_TD_6520657_output.setInt64(r, 0, _ss_ext_sales_price1221);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6520657_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6520657_output #Row: " << tbl_JOIN_INNER_TD_6520657_output.getNumRow() << std::endl;
}

typedef std::string SW_Aggregate_TD_5792815_key;
struct SW_Aggregate_TD_5792815_payload {
    int64_t _total_sales3549_sum_0;
};
void SW_Aggregate_TD_5792815(Table &tbl_JOIN_INNER_TD_6561024_output, Table &tbl_Aggregate_TD_5792815_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(i_item_id#3656, MakeDecimal(sum(UnscaledValue(ws_ext_sales_price#752)),17,2) AS total_sales#3549)
    // Input: ListBuffer(ws_ext_sales_price#752, i_item_id#3656)
    // Output: ListBuffer(i_item_id#3656, total_sales#3549)
    std::unordered_map<SW_Aggregate_TD_5792815_key, SW_Aggregate_TD_5792815_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_6561024_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ws_ext_sales_price752 = tbl_JOIN_INNER_TD_6561024_output.getInt64(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id3656 = tbl_JOIN_INNER_TD_6561024_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        SW_Aggregate_TD_5792815_key k = std::string(_i_item_id3656.data());
        int64_t _total_sales3549_sum_0 = _ws_ext_sales_price752;
        SW_Aggregate_TD_5792815_payload p{_total_sales3549_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._total_sales3549_sum_0 + _total_sales3549_sum_0;
            p._total_sales3549_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id3656{};
        memcpy(_i_item_id3656.data(), (it.first).data(), (it.first).length());
        tbl_Aggregate_TD_5792815_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id3656);
        int64_t _total_sales3549 = (it.second)._total_sales3549_sum_0;
        tbl_Aggregate_TD_5792815_output.setInt64(r, 1, _total_sales3549);
        ++r;
    }
    tbl_Aggregate_TD_5792815_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_5792815_output #Row: " << tbl_Aggregate_TD_5792815_output.getNumRow() << std::endl;
}

typedef std::string SW_Aggregate_TD_5617076_key;
struct SW_Aggregate_TD_5617076_payload {
    int64_t _total_sales3547_sum_0;
};
void SW_Aggregate_TD_5617076(Table &tbl_JOIN_INNER_TD_6260223_output, Table &tbl_Aggregate_TD_5617076_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(i_item_id#3593, MakeDecimal(sum(UnscaledValue(cs_ext_sales_price#1127)),17,2) AS total_sales#3547)
    // Input: ListBuffer(cs_ext_sales_price#1127, i_item_id#3593)
    // Output: ListBuffer(i_item_id#3593, total_sales#3547)
    std::unordered_map<SW_Aggregate_TD_5617076_key, SW_Aggregate_TD_5617076_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_6260223_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _cs_ext_sales_price1127 = tbl_JOIN_INNER_TD_6260223_output.getInt64(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id3593 = tbl_JOIN_INNER_TD_6260223_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        SW_Aggregate_TD_5617076_key k = std::string(_i_item_id3593.data());
        int64_t _total_sales3547_sum_0 = _cs_ext_sales_price1127;
        SW_Aggregate_TD_5617076_payload p{_total_sales3547_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._total_sales3547_sum_0 + _total_sales3547_sum_0;
            p._total_sales3547_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id3593{};
        memcpy(_i_item_id3593.data(), (it.first).data(), (it.first).length());
        tbl_Aggregate_TD_5617076_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id3593);
        int64_t _total_sales3547 = (it.second)._total_sales3547_sum_0;
        tbl_Aggregate_TD_5617076_output.setInt64(r, 1, _total_sales3547);
        ++r;
    }
    tbl_Aggregate_TD_5617076_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_5617076_output #Row: " << tbl_Aggregate_TD_5617076_output.getNumRow() << std::endl;
}

typedef std::string SW_Aggregate_TD_5879177_key;
struct SW_Aggregate_TD_5879177_payload {
    int64_t _total_sales3545_sum_0;
};
void SW_Aggregate_TD_5879177(Table &tbl_JOIN_INNER_TD_6520657_output, Table &tbl_Aggregate_TD_5879177_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(i_item_id#229, MakeDecimal(sum(UnscaledValue(ss_ext_sales_price#1221)),17,2) AS total_sales#3545)
    // Input: ListBuffer(ss_ext_sales_price#1221, i_item_id#229)
    // Output: ListBuffer(i_item_id#229, total_sales#3545)
    std::unordered_map<SW_Aggregate_TD_5879177_key, SW_Aggregate_TD_5879177_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_6520657_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_6520657_output.getInt64(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229 = tbl_JOIN_INNER_TD_6520657_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        SW_Aggregate_TD_5879177_key k = std::string(_i_item_id229.data());
        int64_t _total_sales3545_sum_0 = _ss_ext_sales_price1221;
        SW_Aggregate_TD_5879177_payload p{_total_sales3545_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._total_sales3545_sum_0 + _total_sales3545_sum_0;
            p._total_sales3545_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229{};
        memcpy(_i_item_id229.data(), (it.first).data(), (it.first).length());
        tbl_Aggregate_TD_5879177_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id229);
        int64_t _total_sales3545 = (it.second)._total_sales3545_sum_0;
        tbl_Aggregate_TD_5879177_output.setInt64(r, 1, _total_sales3545);
        ++r;
    }
    tbl_Aggregate_TD_5879177_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_5879177_output #Row: " << tbl_Aggregate_TD_5879177_output.getNumRow() << std::endl;
}

void SW_Union_TD_4612144(Table &tbl_Aggregate_TD_5879177_output, Table &tbl_Aggregate_TD_5617076_output, Table &tbl_Aggregate_TD_5792815_output, Table &tbl_Union_TD_4612144_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Union
    // Operation: ListBuffer(List(UNION))
    // Output Table: ListBuffer(i_item_id#229, total_sales#3545)
    int r = 0;
    int row0 = tbl_Aggregate_TD_5879177_output.getNumRow();
    for (int i = 0; i < row0; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_Union_TD_4612144_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_Union_TD_4612144_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id229_n);
        tbl_Union_TD_4612144_output.setInt32(r, 1, tbl_Aggregate_TD_5879177_output.getInt64(i, 1));
        ++r;
    }
    int row1 = tbl_Aggregate_TD_5617076_output.getNumRow();
    for (int i = 0; i < row1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id3593_n = tbl_Union_TD_4612144_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_Union_TD_4612144_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id3593_n);
        tbl_Union_TD_4612144_output.setInt32(r, 1, tbl_Aggregate_TD_5617076_output.getInt64(i, 1));
        ++r;
    }
    int row2 = tbl_Aggregate_TD_5792815_output.getNumRow();
    for (int i = 0; i < row2; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id3656_n = tbl_Union_TD_4612144_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_Union_TD_4612144_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id3656_n);
        tbl_Union_TD_4612144_output.setInt32(r, 1, tbl_Aggregate_TD_5792815_output.getInt64(i, 1));
        ++r;
    }
    tbl_Union_TD_4612144_output.setNumRow(r);
    std::cout << "tbl_Union_TD_4612144_output #Row: " << tbl_Union_TD_4612144_output.getNumRow() << std::endl;
}

typedef std::string SW_Aggregate_TD_3933724_key;
struct SW_Aggregate_TD_3933724_payload {
    int64_t _total_sales3544_sum_0;
};
void SW_Aggregate_TD_3933724(Table &tbl_Union_TD_4612144_output, Table &tbl_Aggregate_TD_3933724_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(i_item_id#229, sum(total_sales#3545) AS total_sales#3544)
    // Input: ListBuffer(i_item_id#229, total_sales#3545)
    // Output: ListBuffer(i_item_id#229, total_sales#3544)
    std::unordered_map<SW_Aggregate_TD_3933724_key, SW_Aggregate_TD_3933724_payload> ht1;
    int nrow1 = tbl_Union_TD_4612144_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229 = tbl_Union_TD_4612144_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        int64_t _total_sales3545 = tbl_Union_TD_4612144_output.getInt64(i, 1);
        SW_Aggregate_TD_3933724_key k = std::string(_i_item_id229.data());
        int64_t _total_sales3544_sum_0 = _total_sales3545;
        SW_Aggregate_TD_3933724_payload p{_total_sales3544_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._total_sales3544_sum_0 + _total_sales3544_sum_0;
            p._total_sales3544_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229{};
        memcpy(_i_item_id229.data(), (it.first).data(), (it.first).length());
        tbl_Aggregate_TD_3933724_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id229);
        int64_t _total_sales3544 = (it.second)._total_sales3544_sum_0;
        tbl_Aggregate_TD_3933724_output.setInt64(r, 1, _total_sales3544);
        ++r;
    }
    tbl_Aggregate_TD_3933724_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_3933724_output #Row: " << tbl_Aggregate_TD_3933724_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2924655(Table &tbl_Aggregate_TD_3933724_output, Table &tbl_Sort_TD_2924655_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(i_item_id#229 ASC NULLS FIRST, total_sales#3544 ASC NULLS FIRST)
    // Input: ListBuffer(i_item_id#229, total_sales#3544)
    // Output: ListBuffer(i_item_id#229, total_sales#3544)
    struct SW_Sort_TD_2924655Row {
        std::string _i_item_id229;
        int64_t _total_sales3544;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2924655Row& a, const SW_Sort_TD_2924655Row& b) const { return 
 (a._i_item_id229 < b._i_item_id229) || 
 ((a._i_item_id229 == b._i_item_id229) && (a._total_sales3544 < b._total_sales3544)); 
}
    }SW_Sort_TD_2924655_order; 

    int nrow1 = tbl_Aggregate_TD_3933724_output.getNumRow();
    std::vector<SW_Sort_TD_2924655Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229 = tbl_Aggregate_TD_3933724_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        int64_t _total_sales3544 = tbl_Aggregate_TD_3933724_output.getInt64(i, 1);
        SW_Sort_TD_2924655Row t = {std::string(_i_item_id229.data()),_total_sales3544};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2924655_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229{};
        memcpy(_i_item_id229.data(), (it._i_item_id229).data(), (it._i_item_id229).length());
        tbl_Sort_TD_2924655_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _i_item_id229);
        tbl_Sort_TD_2924655_output.setInt64(r, 1, it._total_sales3544);
        ++r;
    }
    tbl_Sort_TD_2924655_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2924655_output #Row: " << tbl_Sort_TD_2924655_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1867169(Table &tbl_Sort_TD_2924655_output, Table &tbl_LocalLimit_TD_1867169_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(i_item_id#229, total_sales#3544)
    // Output: ListBuffer(i_item_id#229, total_sales#3544)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_Sort_TD_2924655_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1867169_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id229_n);
        tbl_LocalLimit_TD_1867169_output.setInt64(r, 1, tbl_Sort_TD_2924655_output.getInt64(i, 1));
        r++;
    }
    tbl_LocalLimit_TD_1867169_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1867169_output #Row: " << tbl_LocalLimit_TD_1867169_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0799225(Table &tbl_LocalLimit_TD_1867169_output, Table &tbl_GlobalLimit_TD_0799225_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(i_item_id#229, total_sales#3544)
    // Output: ListBuffer(i_item_id#229, total_sales#3544)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_item_id229_n = tbl_LocalLimit_TD_1867169_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0799225_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_item_id229_n);
        tbl_GlobalLimit_TD_0799225_output.setInt64(r, 1, tbl_LocalLimit_TD_1867169_output.getInt64(i, 1));
        r++;
    }
    tbl_GlobalLimit_TD_0799225_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0799225_output #Row: " << tbl_GlobalLimit_TD_0799225_output.getNumRow() << std::endl;
}

