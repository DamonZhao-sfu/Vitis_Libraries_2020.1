#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_9411587(Table &tbl_SerializeFromObject_TD_10336437_input, Table &tbl_Filter_TD_9411587_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_year#3620) AND isnotnull(d_moy#3622)) AND ((d_year#3620 = 1998) AND (d_moy#3622 = 5))) AND isnotnull(d_date_sk#3614)))
    // Input: ListBuffer(d_date_sk#3614, d_year#3620, d_moy#3622)
    // Output: ListBuffer(d_date_sk#3614)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10336437_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3620 = tbl_SerializeFromObject_TD_10336437_input.getInt32(i, 1);
        int32_t _d_moy3622 = tbl_SerializeFromObject_TD_10336437_input.getInt32(i, 2);
        int32_t _d_date_sk3614 = tbl_SerializeFromObject_TD_10336437_input.getInt32(i, 0);
        if ((((_d_year3620!= 0) && (_d_moy3622!= 0)) && ((_d_year3620 == 1998) && (_d_moy3622 == 5))) && (_d_date_sk3614!= 0)) {
            int32_t _d_date_sk3614_t = tbl_SerializeFromObject_TD_10336437_input.getInt32(i, 0);
            tbl_Filter_TD_9411587_output.setInt32(r, 0, _d_date_sk3614_t);
            r++;
        }
    }
    tbl_Filter_TD_9411587_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9411587_output #Row: " << tbl_Filter_TD_9411587_output.getNumRow() << std::endl;
}

void SW_Filter_TD_973621(Table &tbl_SerializeFromObject_TD_10310544_input, Table &tbl_Filter_TD_973621_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_sold_date_sk#729) AND (isnotnull(ws_bill_addr_sk#736) AND isnotnull(ws_item_sk#732))))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_bill_addr_sk#736, ws_ext_sales_price#752)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_bill_addr_sk#736, ws_ext_sales_price#752)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10310544_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_10310544_input.getInt32(i, 0);
        int32_t _ws_bill_addr_sk736 = tbl_SerializeFromObject_TD_10310544_input.getInt32(i, 2);
        int32_t _ws_item_sk732 = tbl_SerializeFromObject_TD_10310544_input.getInt32(i, 1);
        if ((_ws_sold_date_sk729!= 0) && ((_ws_bill_addr_sk736!= 0) && (_ws_item_sk732!= 0))) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_10310544_input.getInt32(i, 0);
            tbl_Filter_TD_973621_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_item_sk732_t = tbl_SerializeFromObject_TD_10310544_input.getInt32(i, 1);
            tbl_Filter_TD_973621_output.setInt32(r, 1, _ws_item_sk732_t);
            int32_t _ws_bill_addr_sk736_t = tbl_SerializeFromObject_TD_10310544_input.getInt32(i, 2);
            tbl_Filter_TD_973621_output.setInt32(r, 2, _ws_bill_addr_sk736_t);
            int64_t _ws_ext_sales_price752_t = tbl_SerializeFromObject_TD_10310544_input.getInt64(i, 3);
            tbl_Filter_TD_973621_output.setInt64(r, 3, _ws_ext_sales_price752_t);
            r++;
        }
    }
    tbl_Filter_TD_973621_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_973621_output #Row: " << tbl_Filter_TD_973621_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9443408(Table &tbl_SerializeFromObject_TD_10451965_input, Table &tbl_Filter_TD_9443408_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_year#3557) AND isnotnull(d_moy#3559)) AND ((d_year#3557 = 1998) AND (d_moy#3559 = 5))) AND isnotnull(d_date_sk#3551)))
    // Input: ListBuffer(d_date_sk#3551, d_year#3557, d_moy#3559)
    // Output: ListBuffer(d_date_sk#3551)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10451965_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3557 = tbl_SerializeFromObject_TD_10451965_input.getInt32(i, 1);
        int32_t _d_moy3559 = tbl_SerializeFromObject_TD_10451965_input.getInt32(i, 2);
        int32_t _d_date_sk3551 = tbl_SerializeFromObject_TD_10451965_input.getInt32(i, 0);
        if ((((_d_year3557!= 0) && (_d_moy3559!= 0)) && ((_d_year3557 == 1998) && (_d_moy3559 == 5))) && (_d_date_sk3551!= 0)) {
            int32_t _d_date_sk3551_t = tbl_SerializeFromObject_TD_10451965_input.getInt32(i, 0);
            tbl_Filter_TD_9443408_output.setInt32(r, 0, _d_date_sk3551_t);
            r++;
        }
    }
    tbl_Filter_TD_9443408_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9443408_output #Row: " << tbl_Filter_TD_9443408_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9305145(Table &tbl_SerializeFromObject_TD_10815152_input, Table &tbl_Filter_TD_9305145_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cs_sold_date_sk#1104) AND (isnotnull(cs_bill_addr_sk#1110) AND isnotnull(cs_item_sk#1119))))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_bill_addr_sk#1110, cs_item_sk#1119, cs_ext_sales_price#1127)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_bill_addr_sk#1110, cs_item_sk#1119, cs_ext_sales_price#1127)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10815152_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_10815152_input.getInt32(i, 0);
        int32_t _cs_bill_addr_sk1110 = tbl_SerializeFromObject_TD_10815152_input.getInt32(i, 1);
        int32_t _cs_item_sk1119 = tbl_SerializeFromObject_TD_10815152_input.getInt32(i, 2);
        if ((_cs_sold_date_sk1104!= 0) && ((_cs_bill_addr_sk1110!= 0) && (_cs_item_sk1119!= 0))) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_10815152_input.getInt32(i, 0);
            tbl_Filter_TD_9305145_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int32_t _cs_bill_addr_sk1110_t = tbl_SerializeFromObject_TD_10815152_input.getInt32(i, 1);
            tbl_Filter_TD_9305145_output.setInt32(r, 1, _cs_bill_addr_sk1110_t);
            int32_t _cs_item_sk1119_t = tbl_SerializeFromObject_TD_10815152_input.getInt32(i, 2);
            tbl_Filter_TD_9305145_output.setInt32(r, 2, _cs_item_sk1119_t);
            int64_t _cs_ext_sales_price1127_t = tbl_SerializeFromObject_TD_10815152_input.getInt64(i, 3);
            tbl_Filter_TD_9305145_output.setInt64(r, 3, _cs_ext_sales_price1127_t);
            r++;
        }
    }
    tbl_Filter_TD_9305145_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9305145_output #Row: " << tbl_Filter_TD_9305145_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9816920(Table &tbl_SerializeFromObject_TD_1029519_input, Table &tbl_Filter_TD_9816920_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_year#126) AND isnotnull(d_moy#128)) AND ((d_year#126 = 1998) AND (d_moy#128 = 5))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126, d_moy#128)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1029519_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_1029519_input.getInt32(i, 1);
        int32_t _d_moy128 = tbl_SerializeFromObject_TD_1029519_input.getInt32(i, 2);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_1029519_input.getInt32(i, 0);
        if ((((_d_year126!= 0) && (_d_moy128!= 0)) && ((_d_year126 == 1998) && (_d_moy128 == 5))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_1029519_input.getInt32(i, 0);
            tbl_Filter_TD_9816920_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_9816920_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9816920_output #Row: " << tbl_Filter_TD_9816920_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9812505(Table &tbl_SerializeFromObject_TD_10635206_input, Table &tbl_Filter_TD_9812505_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_sold_date_sk#1206) AND (isnotnull(ss_addr_sk#1212) AND isnotnull(ss_item_sk#1208))))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_addr_sk#1212, ss_ext_sales_price#1221)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_addr_sk#1212, ss_ext_sales_price#1221)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10635206_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_10635206_input.getInt32(i, 0);
        int32_t _ss_addr_sk1212 = tbl_SerializeFromObject_TD_10635206_input.getInt32(i, 2);
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_10635206_input.getInt32(i, 1);
        if ((_ss_sold_date_sk1206!= 0) && ((_ss_addr_sk1212!= 0) && (_ss_item_sk1208!= 0))) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_10635206_input.getInt32(i, 0);
            tbl_Filter_TD_9812505_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_10635206_input.getInt32(i, 1);
            tbl_Filter_TD_9812505_output.setInt32(r, 1, _ss_item_sk1208_t);
            int32_t _ss_addr_sk1212_t = tbl_SerializeFromObject_TD_10635206_input.getInt32(i, 2);
            tbl_Filter_TD_9812505_output.setInt32(r, 2, _ss_addr_sk1212_t);
            int64_t _ss_ext_sales_price1221_t = tbl_SerializeFromObject_TD_10635206_input.getInt64(i, 3);
            tbl_Filter_TD_9812505_output.setInt64(r, 3, _ss_ext_sales_price1221_t);
            r++;
        }
    }
    tbl_Filter_TD_9812505_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9812505_output #Row: " << tbl_Filter_TD_9812505_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8693444(Table &tbl_SerializeFromObject_TD_981526_input, Table &tbl_Filter_TD_8693444_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(i_category#3733) AND (i_category#3733 = Electronics)))
    // Input: ListBuffer(i_manufact_id#3734, i_category#3733)
    // Output: ListBuffer(i_manufact_id#3734)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_981526_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category3733 = tbl_SerializeFromObject_TD_981526_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if (_i_category3733.data() != "NULL" && (std::string(_i_category3733.data()) == "Electronics")) {
            int32_t _i_manufact_id3734_t = tbl_SerializeFromObject_TD_981526_input.getInt32(i, 0);
            tbl_Filter_TD_8693444_output.setInt32(r, 0, _i_manufact_id3734_t);
            r++;
        }
    }
    tbl_Filter_TD_8693444_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8693444_output #Row: " << tbl_Filter_TD_8693444_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8603282(Table &tbl_SerializeFromObject_TD_9714270_input, Table &tbl_Filter_TD_8603282_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#3655))
    // Input: ListBuffer(i_item_sk#3655, i_manufact_id#3668)
    // Output: ListBuffer(i_item_sk#3655, i_manufact_id#3668)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9714270_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk3655 = tbl_SerializeFromObject_TD_9714270_input.getInt32(i, 0);
        if (_i_item_sk3655!= 0) {
            int32_t _i_item_sk3655_t = tbl_SerializeFromObject_TD_9714270_input.getInt32(i, 0);
            tbl_Filter_TD_8603282_output.setInt32(r, 0, _i_item_sk3655_t);
            int32_t _i_manufact_id3668_t = tbl_SerializeFromObject_TD_9714270_input.getInt32(i, 1);
            tbl_Filter_TD_8603282_output.setInt32(r, 1, _i_manufact_id3668_t);
            r++;
        }
    }
    tbl_Filter_TD_8603282_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8603282_output #Row: " << tbl_Filter_TD_8603282_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8154288(Table &tbl_SerializeFromObject_TD_9706056_input, Table &tbl_Filter_TD_8154288_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ca_gmt_offset#3653) AND (ca_gmt_offset#3653 = -5.00)) AND isnotnull(ca_address_sk#3642)))
    // Input: ListBuffer(ca_address_sk#3642, ca_gmt_offset#3653)
    // Output: ListBuffer(ca_address_sk#3642)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9706056_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ca_gmt_offset3653 = tbl_SerializeFromObject_TD_9706056_input.getInt64(i, 1);
        int32_t _ca_address_sk3642 = tbl_SerializeFromObject_TD_9706056_input.getInt32(i, 0);
        if (((_ca_gmt_offset3653!= 0) && (_ca_gmt_offset3653 == -5.00)) && (_ca_address_sk3642!= 0)) {
            int32_t _ca_address_sk3642_t = tbl_SerializeFromObject_TD_9706056_input.getInt32(i, 0);
            tbl_Filter_TD_8154288_output.setInt32(r, 0, _ca_address_sk3642_t);
            r++;
        }
    }
    tbl_Filter_TD_8154288_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8154288_output #Row: " << tbl_Filter_TD_8154288_output.getNumRow() << std::endl;
}


void SW_Filter_TD_872308(Table &tbl_SerializeFromObject_TD_9538311_input, Table &tbl_Filter_TD_872308_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(i_category#3711) AND (i_category#3711 = Electronics)))
    // Input: ListBuffer(i_manufact_id#3712, i_category#3711)
    // Output: ListBuffer(i_manufact_id#3712)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9538311_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category3711 = tbl_SerializeFromObject_TD_9538311_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if (_i_category3711.data() != "NULL" && (std::string(_i_category3711.data()) == "Electronics")) {
            int32_t _i_manufact_id3712_t = tbl_SerializeFromObject_TD_9538311_input.getInt32(i, 0);
            tbl_Filter_TD_872308_output.setInt32(r, 0, _i_manufact_id3712_t);
            r++;
        }
    }
    tbl_Filter_TD_872308_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_872308_output #Row: " << tbl_Filter_TD_872308_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8333166(Table &tbl_SerializeFromObject_TD_9385979_input, Table &tbl_Filter_TD_8333166_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#3592))
    // Input: ListBuffer(i_item_sk#3592, i_manufact_id#3605)
    // Output: ListBuffer(i_item_sk#3592, i_manufact_id#3605)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9385979_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk3592 = tbl_SerializeFromObject_TD_9385979_input.getInt32(i, 0);
        if (_i_item_sk3592!= 0) {
            int32_t _i_item_sk3592_t = tbl_SerializeFromObject_TD_9385979_input.getInt32(i, 0);
            tbl_Filter_TD_8333166_output.setInt32(r, 0, _i_item_sk3592_t);
            int32_t _i_manufact_id3605_t = tbl_SerializeFromObject_TD_9385979_input.getInt32(i, 1);
            tbl_Filter_TD_8333166_output.setInt32(r, 1, _i_manufact_id3605_t);
            r++;
        }
    }
    tbl_Filter_TD_8333166_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8333166_output #Row: " << tbl_Filter_TD_8333166_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8614172(Table &tbl_SerializeFromObject_TD_9210785_input, Table &tbl_Filter_TD_8614172_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ca_gmt_offset#3590) AND (ca_gmt_offset#3590 = -5.00)) AND isnotnull(ca_address_sk#3579)))
    // Input: ListBuffer(ca_address_sk#3579, ca_gmt_offset#3590)
    // Output: ListBuffer(ca_address_sk#3579)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9210785_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ca_gmt_offset3590 = tbl_SerializeFromObject_TD_9210785_input.getInt64(i, 1);
        int32_t _ca_address_sk3579 = tbl_SerializeFromObject_TD_9210785_input.getInt32(i, 0);
        if (((_ca_gmt_offset3590!= 0) && (_ca_gmt_offset3590 == -5.00)) && (_ca_address_sk3579!= 0)) {
            int32_t _ca_address_sk3579_t = tbl_SerializeFromObject_TD_9210785_input.getInt32(i, 0);
            tbl_Filter_TD_8614172_output.setInt32(r, 0, _ca_address_sk3579_t);
            r++;
        }
    }
    tbl_Filter_TD_8614172_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8614172_output #Row: " << tbl_Filter_TD_8614172_output.getNumRow() << std::endl;
}


void SW_Filter_TD_8428670(Table &tbl_SerializeFromObject_TD_9919217_input, Table &tbl_Filter_TD_8428670_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(i_category#3689) AND (i_category#3689 = Electronics)))
    // Input: ListBuffer(i_manufact_id#3690, i_category#3689)
    // Output: ListBuffer(i_manufact_id#3690)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9919217_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category3689 = tbl_SerializeFromObject_TD_9919217_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if (_i_category3689.data() != "NULL" && (std::string(_i_category3689.data()) == "Electronics")) {
            int32_t _i_manufact_id3690_t = tbl_SerializeFromObject_TD_9919217_input.getInt32(i, 0);
            tbl_Filter_TD_8428670_output.setInt32(r, 0, _i_manufact_id3690_t);
            r++;
        }
    }
    tbl_Filter_TD_8428670_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8428670_output #Row: " << tbl_Filter_TD_8428670_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8207053(Table &tbl_SerializeFromObject_TD_9154893_input, Table &tbl_Filter_TD_8207053_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#228))
    // Input: ListBuffer(i_item_sk#228, i_manufact_id#241)
    // Output: ListBuffer(i_item_sk#228, i_manufact_id#241)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9154893_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_9154893_input.getInt32(i, 0);
        if (_i_item_sk228!= 0) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_9154893_input.getInt32(i, 0);
            tbl_Filter_TD_8207053_output.setInt32(r, 0, _i_item_sk228_t);
            int32_t _i_manufact_id241_t = tbl_SerializeFromObject_TD_9154893_input.getInt32(i, 1);
            tbl_Filter_TD_8207053_output.setInt32(r, 1, _i_manufact_id241_t);
            r++;
        }
    }
    tbl_Filter_TD_8207053_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8207053_output #Row: " << tbl_Filter_TD_8207053_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8631152(Table &tbl_SerializeFromObject_TD_9293274_input, Table &tbl_Filter_TD_8631152_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ca_gmt_offset#65) AND (ca_gmt_offset#65 = -5.00)) AND isnotnull(ca_address_sk#54)))
    // Input: ListBuffer(ca_address_sk#54, ca_gmt_offset#65)
    // Output: ListBuffer(ca_address_sk#54)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9293274_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ca_gmt_offset65 = tbl_SerializeFromObject_TD_9293274_input.getInt64(i, 1);
        int32_t _ca_address_sk54 = tbl_SerializeFromObject_TD_9293274_input.getInt32(i, 0);
        if (((_ca_gmt_offset65!= 0) && (_ca_gmt_offset65 == -5.00)) && (_ca_address_sk54!= 0)) {
            int32_t _ca_address_sk54_t = tbl_SerializeFromObject_TD_9293274_input.getInt32(i, 0);
            tbl_Filter_TD_8631152_output.setInt32(r, 0, _ca_address_sk54_t);
            r++;
        }
    }
    tbl_Filter_TD_8631152_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8631152_output #Row: " << tbl_Filter_TD_8631152_output.getNumRow() << std::endl;
}











void SW_Aggregate_TD_5343411_consolidate(Table &tbl_Aggregate_TD_5343411_output_preprocess, Table &tbl_Aggregate_TD_5343411_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_5343411_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _i_manufact_id3668 = tbl_Aggregate_TD_5343411_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_5343411_output.setInt32(r, 0, _i_manufact_id3668);
        int64_t _total_sales3549 = tbl_Aggregate_TD_5343411_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_5343411_output.setInt64(r, 1, _total_sales3549);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_5343411_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_5343411_output #Row: " << tbl_Aggregate_TD_5343411_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_5894224_consolidate(Table &tbl_Aggregate_TD_5894224_output_preprocess, Table &tbl_Aggregate_TD_5894224_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_5894224_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _i_manufact_id3605 = tbl_Aggregate_TD_5894224_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_5894224_output.setInt32(r, 0, _i_manufact_id3605);
        int64_t _total_sales3547 = tbl_Aggregate_TD_5894224_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_5894224_output.setInt64(r, 1, _total_sales3547);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_5894224_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_5894224_output #Row: " << tbl_Aggregate_TD_5894224_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_5453244_consolidate(Table &tbl_Aggregate_TD_5453244_output_preprocess, Table &tbl_Aggregate_TD_5453244_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_5453244_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _i_manufact_id241 = tbl_Aggregate_TD_5453244_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_5453244_output.setInt32(r, 0, _i_manufact_id241);
        int64_t _total_sales3545 = tbl_Aggregate_TD_5453244_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_5453244_output.setInt64(r, 1, _total_sales3545);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_5453244_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_5453244_output #Row: " << tbl_Aggregate_TD_5453244_output.getNumRow() << std::endl;
}

void SW_Union_TD_4182112(Table &tbl_Aggregate_TD_5453244_output, Table &tbl_Aggregate_TD_5894224_output, Table &tbl_Aggregate_TD_5343411_output, Table &tbl_Union_TD_4182112_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Union
    // Operation: ListBuffer(List(UNION))
    // Output Table: ListBuffer(i_manufact_id#241, total_sales#3545)
    int r = 0;
    int row0 = tbl_Aggregate_TD_5453244_output.getNumRow();
    for (int i = 0; i < row0; i++) {
        tbl_Union_TD_4182112_output.setInt32(r, 0, tbl_Aggregate_TD_5453244_output.getInt32(i, 0));
        tbl_Union_TD_4182112_output.setInt32(r, 1, tbl_Aggregate_TD_5453244_output.getInt64(i, 1));
        ++r;
    }
    int row1 = tbl_Aggregate_TD_5894224_output.getNumRow();
    for (int i = 0; i < row1; i++) {
        tbl_Union_TD_4182112_output.setInt32(r, 0, tbl_Aggregate_TD_5894224_output.getInt32(i, 0));
        tbl_Union_TD_4182112_output.setInt32(r, 1, tbl_Aggregate_TD_5894224_output.getInt64(i, 1));
        ++r;
    }
    int row2 = tbl_Aggregate_TD_5343411_output.getNumRow();
    for (int i = 0; i < row2; i++) {
        tbl_Union_TD_4182112_output.setInt32(r, 0, tbl_Aggregate_TD_5343411_output.getInt32(i, 0));
        tbl_Union_TD_4182112_output.setInt32(r, 1, tbl_Aggregate_TD_5343411_output.getInt64(i, 1));
        ++r;
    }
    tbl_Union_TD_4182112_output.setNumRow(r);
    std::cout << "tbl_Union_TD_4182112_output #Row: " << tbl_Union_TD_4182112_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_384003_consolidate(Table &tbl_Aggregate_TD_384003_output_preprocess, Table &tbl_Aggregate_TD_384003_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_384003_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _i_manufact_id241 = tbl_Aggregate_TD_384003_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_384003_output.setInt32(r, 0, _i_manufact_id241);
        int64_t _total_sales3544 = tbl_Aggregate_TD_384003_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_384003_output.setInt64(r, 1, _total_sales3544);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_384003_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_384003_output #Row: " << tbl_Aggregate_TD_384003_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2163636(Table &tbl_Aggregate_TD_384003_output, Table &tbl_Sort_TD_2163636_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(total_sales#3544 ASC NULLS FIRST)
    // Input: ListBuffer(i_manufact_id#241, total_sales#3544)
    // Output: ListBuffer(i_manufact_id#241, total_sales#3544)
    struct SW_Sort_TD_2163636Row {
        int32_t _i_manufact_id241;
        int64_t _total_sales3544;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2163636Row& a, const SW_Sort_TD_2163636Row& b) const { return 
 (a._total_sales3544 < b._total_sales3544); 
}
    }SW_Sort_TD_2163636_order; 

    int nrow1 = tbl_Aggregate_TD_384003_output.getNumRow();
    std::vector<SW_Sort_TD_2163636Row> rows;
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_manufact_id241 = tbl_Aggregate_TD_384003_output.getInt32(i, 0);
        int64_t _total_sales3544 = tbl_Aggregate_TD_384003_output.getInt64(i, 1);
        SW_Sort_TD_2163636Row t = {_i_manufact_id241,_total_sales3544};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2163636_order);
    int r = 0;
    for (auto& it : rows) {
        tbl_Sort_TD_2163636_output.setInt32(r, 0, it._i_manufact_id241);
        tbl_Sort_TD_2163636_output.setInt64(r, 1, it._total_sales3544);
        ++r;
    }
    tbl_Sort_TD_2163636_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2163636_output #Row: " << tbl_Sort_TD_2163636_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1982910(Table &tbl_Sort_TD_2163636_output, Table &tbl_LocalLimit_TD_1982910_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(i_manufact_id#241, total_sales#3544)
    // Output: ListBuffer(i_manufact_id#241, total_sales#3544)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        tbl_LocalLimit_TD_1982910_output.setInt32(r, 0, tbl_Sort_TD_2163636_output.getInt32(i, 0));
        tbl_LocalLimit_TD_1982910_output.setInt64(r, 1, tbl_Sort_TD_2163636_output.getInt64(i, 1));
        r++;
    }
    tbl_LocalLimit_TD_1982910_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1982910_output #Row: " << tbl_LocalLimit_TD_1982910_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0979670(Table &tbl_LocalLimit_TD_1982910_output, Table &tbl_GlobalLimit_TD_0979670_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(i_manufact_id#241, total_sales#3544)
    // Output: ListBuffer(i_manufact_id#241, total_sales#3544)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        tbl_GlobalLimit_TD_0979670_output.setInt32(r, 0, tbl_LocalLimit_TD_1982910_output.getInt32(i, 0));
        tbl_GlobalLimit_TD_0979670_output.setInt64(r, 1, tbl_LocalLimit_TD_1982910_output.getInt64(i, 1));
        r++;
    }
    tbl_GlobalLimit_TD_0979670_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0979670_output #Row: " << tbl_GlobalLimit_TD_0979670_output.getNumRow() << std::endl;
}

