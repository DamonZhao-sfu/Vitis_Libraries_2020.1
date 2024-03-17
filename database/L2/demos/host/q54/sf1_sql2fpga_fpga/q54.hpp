#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_15942981(Table &tbl_SerializeFromObject_TD_16194364_input, Table &tbl_Filter_TD_15942981_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_item_sk#732) AND (isnotnull(ws_sold_date_sk#729) AND isnotnull(ws_bill_customer_sk#733))))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_bill_customer_sk#733, ws_item_sk#732)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_bill_customer_sk#733, ws_item_sk#732)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_16194364_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_item_sk732 = tbl_SerializeFromObject_TD_16194364_input.getInt32(i, 2);
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_16194364_input.getInt32(i, 0);
        int32_t _ws_bill_customer_sk733 = tbl_SerializeFromObject_TD_16194364_input.getInt32(i, 1);
        if ((_ws_item_sk732!= 0) && ((_ws_sold_date_sk729!= 0) && (_ws_bill_customer_sk733!= 0))) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_16194364_input.getInt32(i, 0);
            tbl_Filter_TD_15942981_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_bill_customer_sk733_t = tbl_SerializeFromObject_TD_16194364_input.getInt32(i, 1);
            tbl_Filter_TD_15942981_output.setInt32(r, 1, _ws_bill_customer_sk733_t);
            int32_t _ws_item_sk732_t = tbl_SerializeFromObject_TD_16194364_input.getInt32(i, 2);
            tbl_Filter_TD_15942981_output.setInt32(r, 2, _ws_item_sk732_t);
            r++;
        }
    }
    tbl_Filter_TD_15942981_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_15942981_output #Row: " << tbl_Filter_TD_15942981_output.getNumRow() << std::endl;
}

void SW_Filter_TD_15417386(Table &tbl_SerializeFromObject_TD_16713508_input, Table &tbl_Filter_TD_15417386_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cs_item_sk#1119) AND (isnotnull(cs_sold_date_sk#1104) AND isnotnull(cs_bill_customer_sk#1107))))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_item_sk#1119)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_item_sk#1119)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_16713508_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_item_sk1119 = tbl_SerializeFromObject_TD_16713508_input.getInt32(i, 2);
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_16713508_input.getInt32(i, 0);
        int32_t _cs_bill_customer_sk1107 = tbl_SerializeFromObject_TD_16713508_input.getInt32(i, 1);
        if ((_cs_item_sk1119!= 0) && ((_cs_sold_date_sk1104!= 0) && (_cs_bill_customer_sk1107!= 0))) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_16713508_input.getInt32(i, 0);
            tbl_Filter_TD_15417386_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int32_t _cs_bill_customer_sk1107_t = tbl_SerializeFromObject_TD_16713508_input.getInt32(i, 1);
            tbl_Filter_TD_15417386_output.setInt32(r, 1, _cs_bill_customer_sk1107_t);
            int32_t _cs_item_sk1119_t = tbl_SerializeFromObject_TD_16713508_input.getInt32(i, 2);
            tbl_Filter_TD_15417386_output.setInt32(r, 2, _cs_item_sk1119_t);
            r++;
        }
    }
    tbl_Filter_TD_15417386_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_15417386_output #Row: " << tbl_Filter_TD_15417386_output.getNumRow() << std::endl;
}

void SW_Project_TD_14411667(Table &tbl_Filter_TD_15942981_output, Table &tbl_Project_TD_14411667_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(ws_sold_date_sk#729 AS sold_date_sk#3549, ws_bill_customer_sk#733 AS customer_sk#3550, ws_item_sk#732 AS item_sk#3551)
    // Input: ListBuffer(ws_sold_date_sk#729, ws_bill_customer_sk#733, ws_item_sk#732)
    // Output: ListBuffer(sold_date_sk#3549, customer_sk#3550, item_sk#3551)
    int nrow1 = tbl_Filter_TD_15942981_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_sold_date_sk729 = tbl_Filter_TD_15942981_output.getInt32(i, 0);
        int32_t _ws_bill_customer_sk733 = tbl_Filter_TD_15942981_output.getInt32(i, 1);
        int32_t _ws_item_sk732 = tbl_Filter_TD_15942981_output.getInt32(i, 2);
        int32_t _sold_date_sk3549 = _ws_sold_date_sk729;
        tbl_Project_TD_14411667_output.setInt32(i, 0, _sold_date_sk3549);
        int32_t _customer_sk3550 = _ws_bill_customer_sk733;
        tbl_Project_TD_14411667_output.setInt32(i, 1, _customer_sk3550);
        int32_t _item_sk3551 = _ws_item_sk732;
        tbl_Project_TD_14411667_output.setInt32(i, 2, _item_sk3551);
    }
    tbl_Project_TD_14411667_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_14411667_output #Row: " << tbl_Project_TD_14411667_output.getNumRow() << std::endl;
}

void SW_Project_TD_14575890(Table &tbl_Filter_TD_15417386_output, Table &tbl_Project_TD_14575890_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(cs_sold_date_sk#1104 AS sold_date_sk#3546, cs_bill_customer_sk#1107 AS customer_sk#3547, cs_item_sk#1119 AS item_sk#3548)
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_item_sk#1119)
    // Output: ListBuffer(sold_date_sk#3546, customer_sk#3547, item_sk#3548)
    int nrow1 = tbl_Filter_TD_15417386_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_sold_date_sk1104 = tbl_Filter_TD_15417386_output.getInt32(i, 0);
        int32_t _cs_bill_customer_sk1107 = tbl_Filter_TD_15417386_output.getInt32(i, 1);
        int32_t _cs_item_sk1119 = tbl_Filter_TD_15417386_output.getInt32(i, 2);
        int32_t _sold_date_sk3546 = _cs_sold_date_sk1104;
        tbl_Project_TD_14575890_output.setInt32(i, 0, _sold_date_sk3546);
        int32_t _customer_sk3547 = _cs_bill_customer_sk1107;
        tbl_Project_TD_14575890_output.setInt32(i, 1, _customer_sk3547);
        int32_t _item_sk3548 = _cs_item_sk1119;
        tbl_Project_TD_14575890_output.setInt32(i, 2, _item_sk3548);
    }
    tbl_Project_TD_14575890_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_14575890_output #Row: " << tbl_Project_TD_14575890_output.getNumRow() << std::endl;
}

void SW_Filter_TD_13998184(Table &tbl_SerializeFromObject_TD_14698106_input, Table &tbl_Filter_TD_13998184_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(i_category#240) AND isnotnull(i_class#238)) AND ((i_category#240 = Women) AND (i_class#238 = maternity))) AND isnotnull(i_item_sk#228)))
    // Input: ListBuffer(i_item_sk#228, i_category#240, i_class#238)
    // Output: ListBuffer(i_item_sk#228)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_14698106_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category240 = tbl_SerializeFromObject_TD_14698106_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _i_class238 = tbl_SerializeFromObject_TD_14698106_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_14698106_input.getInt32(i, 0);
        if (((_i_category240.data() != "NULL" && _i_class238.data() != "NULL") && ((std::string(_i_category240.data()) == "Women") && (std::string(_i_class238.data()) == "maternity"))) && (_i_item_sk228!= 0)) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_14698106_input.getInt32(i, 0);
            tbl_Filter_TD_13998184_output.setInt32(r, 0, _i_item_sk228_t);
            r++;
        }
    }
    tbl_Filter_TD_13998184_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_13998184_output #Row: " << tbl_Filter_TD_13998184_output.getNumRow() << std::endl;
}

void SW_Union_TD_13712926(Table &tbl_Project_TD_14575890_output, Table &tbl_Project_TD_14411667_output, Table &tbl_Union_TD_13712926_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Union
    // Operation: ListBuffer(List(UNION))
    // Output Table: ListBuffer(sold_date_sk#3546, customer_sk#3547, item_sk#3548)
    int r = 0;
    int row0 = tbl_Project_TD_14575890_output.getNumRow();
    for (int i = 0; i < row0; i++) {
        tbl_Union_TD_13712926_output.setInt32(r, 0, tbl_Project_TD_14575890_output.getInt32(i, 0));
        tbl_Union_TD_13712926_output.setInt32(r, 1, tbl_Project_TD_14575890_output.getInt32(i, 1));
        tbl_Union_TD_13712926_output.setInt32(r, 2, tbl_Project_TD_14575890_output.getInt32(i, 2));
        ++r;
    }
    int row1 = tbl_Project_TD_14411667_output.getNumRow();
    for (int i = 0; i < row1; i++) {
        tbl_Union_TD_13712926_output.setInt32(r, 0, tbl_Project_TD_14411667_output.getInt32(i, 0));
        tbl_Union_TD_13712926_output.setInt32(r, 1, tbl_Project_TD_14411667_output.getInt32(i, 1));
        tbl_Union_TD_13712926_output.setInt32(r, 2, tbl_Project_TD_14411667_output.getInt32(i, 2));
        ++r;
    }
    tbl_Union_TD_13712926_output.setNumRow(r);
    std::cout << "tbl_Union_TD_13712926_output #Row: " << tbl_Union_TD_13712926_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12895959(Table &tbl_SerializeFromObject_TD_1357148_input, Table &tbl_Filter_TD_12895959_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_moy#128) AND isnotnull(d_year#126)) AND ((d_moy#128 = 12) AND (d_year#126 = 1998))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_moy#128, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1357148_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_moy128 = tbl_SerializeFromObject_TD_1357148_input.getInt32(i, 1);
        int32_t _d_year126 = tbl_SerializeFromObject_TD_1357148_input.getInt32(i, 2);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_1357148_input.getInt32(i, 0);
        if ((((_d_moy128!= 0) && (_d_year126!= 0)) && ((_d_moy128 == 12) && (_d_year126 == 1998))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_1357148_input.getInt32(i, 0);
            tbl_Filter_TD_12895959_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_12895959_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12895959_output #Row: " << tbl_Filter_TD_12895959_output.getNumRow() << std::endl;
}


void SW_Filter_TD_11768305(Table &tbl_SerializeFromObject_TD_12107220_input, Table &tbl_Filter_TD_11768305_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(c_customer_sk#0) AND isnotnull(c_current_addr_sk#4)))
    // Input: ListBuffer(c_customer_sk#0, c_current_addr_sk#4)
    // Output: ListBuffer(c_customer_sk#0, c_current_addr_sk#4)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12107220_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk0 = tbl_SerializeFromObject_TD_12107220_input.getInt32(i, 0);
        int32_t _c_current_addr_sk4 = tbl_SerializeFromObject_TD_12107220_input.getInt32(i, 1);
        if ((_c_customer_sk0!= 0) && (_c_current_addr_sk4!= 0)) {
            int32_t _c_customer_sk0_t = tbl_SerializeFromObject_TD_12107220_input.getInt32(i, 0);
            tbl_Filter_TD_11768305_output.setInt32(r, 0, _c_customer_sk0_t);
            int32_t _c_current_addr_sk4_t = tbl_SerializeFromObject_TD_12107220_input.getInt32(i, 1);
            tbl_Filter_TD_11768305_output.setInt32(r, 1, _c_current_addr_sk4_t);
            r++;
        }
    }
    tbl_Filter_TD_11768305_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11768305_output #Row: " << tbl_Filter_TD_11768305_output.getNumRow() << std::endl;
}



void SW_Filter_TD_9679178(Table &tbl_SerializeFromObject_TD_10345680_input, Table &tbl_Filter_TD_9679178_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3621) AND isnotnull(d_moy#3623)) AND ((d_year#3621 = 1998) AND (d_moy#3623 = 12))))
    // Input: ListBuffer(d_month_seq#3618, d_year#3621, d_moy#3623)
    // Output: ListBuffer(d_month_seq#3618)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10345680_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3621 = tbl_SerializeFromObject_TD_10345680_input.getInt32(i, 1);
        int32_t _d_moy3623 = tbl_SerializeFromObject_TD_10345680_input.getInt32(i, 2);
        if (((_d_year3621!= 0) && (_d_moy3623!= 0)) && ((_d_year3621 == 1998) && (_d_moy3623 == 12))) {
            int32_t _d_month_seq3618_t = tbl_SerializeFromObject_TD_10345680_input.getInt32(i, 0);
            tbl_Filter_TD_9679178_output.setInt32(r, 0, _d_month_seq3618_t);
            r++;
        }
    }
    tbl_Filter_TD_9679178_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9679178_output #Row: " << tbl_Filter_TD_9679178_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9916711(Table &tbl_SerializeFromObject_TD_10746465_input, Table &tbl_Filter_TD_9916711_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3593) AND isnotnull(d_moy#3595)) AND ((d_year#3593 = 1998) AND (d_moy#3595 = 12))))
    // Input: ListBuffer(d_month_seq#3590, d_year#3593, d_moy#3595)
    // Output: ListBuffer(d_month_seq#3590)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10746465_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3593 = tbl_SerializeFromObject_TD_10746465_input.getInt32(i, 1);
        int32_t _d_moy3595 = tbl_SerializeFromObject_TD_10746465_input.getInt32(i, 2);
        if (((_d_year3593!= 0) && (_d_moy3595!= 0)) && ((_d_year3593 == 1998) && (_d_moy3595 == 12))) {
            int32_t _d_month_seq3590_t = tbl_SerializeFromObject_TD_10746465_input.getInt32(i, 0);
            tbl_Filter_TD_9916711_output.setInt32(r, 0, _d_month_seq3590_t);
            r++;
        }
    }
    tbl_Filter_TD_9916711_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9916711_output #Row: " << tbl_Filter_TD_9916711_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9845184(Table &tbl_SerializeFromObject_TD_10516255_input, Table &tbl_Filter_TD_9845184_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_customer_sk#1209) AND isnotnull(ss_sold_date_sk#1206)))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_customer_sk#1209, ss_ext_sales_price#1221)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_customer_sk#1209, ss_ext_sales_price#1221)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10516255_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_customer_sk1209 = tbl_SerializeFromObject_TD_10516255_input.getInt32(i, 1);
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_10516255_input.getInt32(i, 0);
        if ((_ss_customer_sk1209!= 0) && (_ss_sold_date_sk1206!= 0)) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_10516255_input.getInt32(i, 0);
            tbl_Filter_TD_9845184_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_customer_sk1209_t = tbl_SerializeFromObject_TD_10516255_input.getInt32(i, 1);
            tbl_Filter_TD_9845184_output.setInt32(r, 1, _ss_customer_sk1209_t);
            int64_t _ss_ext_sales_price1221_t = tbl_SerializeFromObject_TD_10516255_input.getInt64(i, 2);
            tbl_Filter_TD_9845184_output.setInt64(r, 2, _ss_ext_sales_price1221_t);
            r++;
        }
    }
    tbl_Filter_TD_9845184_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9845184_output #Row: " << tbl_Filter_TD_9845184_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_9953648_consolidate(Table &tbl_Aggregate_TD_9953648_output_preprocess, Table &tbl_Aggregate_TD_9953648_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_9953648_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _c_customer_sk0 = tbl_Aggregate_TD_9953648_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_9953648_output.setInt32(r, 0, _c_customer_sk0);
        int32_t _c_current_addr_sk4 = tbl_Aggregate_TD_9953648_output_preprocess.getInt32(r, 6);
        tbl_Aggregate_TD_9953648_output.setInt32(r, 1, _c_current_addr_sk4);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_9953648_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_9953648_output #Row: " << tbl_Aggregate_TD_9953648_output.getNumRow() << std::endl;
}

void SW_Project_TD_8876293(Table &tbl_Filter_TD_9679178_output, Table &tbl_Project_TD_8876293_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer((d_month_seq#3618 + 3) AS (d_month_seq + 3)#3586)
    // Input: ListBuffer(d_month_seq#3618)
    // Output: ListBuffer((d_month_seq + 3)#3586)
    int nrow1 = tbl_Filter_TD_9679178_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_month_seq3618 = tbl_Filter_TD_9679178_output.getInt32(i, 0);
        int32_t _d_month_seq33586 = (_d_month_seq3618 + 3);
        tbl_Project_TD_8876293_output.setInt32(i, 0, _d_month_seq33586);
    }
    tbl_Project_TD_8876293_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_8876293_output #Row: " << tbl_Project_TD_8876293_output.getNumRow() << std::endl;
}

void SW_Project_TD_8400581(Table &tbl_Filter_TD_9916711_output, Table &tbl_Project_TD_8400581_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer((d_month_seq#3590 + 1) AS (d_month_seq + 1)#3585)
    // Input: ListBuffer(d_month_seq#3590)
    // Output: ListBuffer((d_month_seq + 1)#3585)
    int nrow1 = tbl_Filter_TD_9916711_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_month_seq3590 = tbl_Filter_TD_9916711_output.getInt32(i, 0);
        int32_t _d_month_seq13585 = (_d_month_seq3590 + 1);
        tbl_Project_TD_8400581_output.setInt32(i, 0, _d_month_seq13585);
    }
    tbl_Project_TD_8400581_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_8400581_output #Row: " << tbl_Project_TD_8400581_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8729339(Table &tbl_SerializeFromObject_TD_9680138_input, Table &tbl_Filter_TD_8729339_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ca_address_sk#54) AND (isnotnull(ca_county#61) AND isnotnull(ca_state#62))))
    // Input: ListBuffer(ca_address_sk#54, ca_county#61, ca_state#62)
    // Output: ListBuffer(ca_address_sk#54, ca_county#61, ca_state#62)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9680138_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ca_address_sk54 = tbl_SerializeFromObject_TD_9680138_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _ca_county61 = tbl_SerializeFromObject_TD_9680138_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _ca_state62 = tbl_SerializeFromObject_TD_9680138_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        if ((_ca_address_sk54!= 0) && (_ca_county61.data() != "NULL" && _ca_state62.data() != "NULL")) {
            int32_t _ca_address_sk54_t = tbl_SerializeFromObject_TD_9680138_input.getInt32(i, 0);
            tbl_Filter_TD_8729339_output.setInt32(r, 0, _ca_address_sk54_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_county61_t = tbl_SerializeFromObject_TD_9680138_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_8729339_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_county61_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_t = tbl_SerializeFromObject_TD_9680138_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_8729339_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _ca_state62_t);
            r++;
        }
    }
    tbl_Filter_TD_8729339_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8729339_output #Row: " << tbl_Filter_TD_8729339_output.getNumRow() << std::endl;
}


void SW_Aggregate_TD_7521203_consolidate(Table &tbl_Aggregate_TD_7521203_output_preprocess, Table &tbl_Aggregate_TD_7521203_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_7521203_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _d_month_seq33586 = tbl_Aggregate_TD_7521203_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_7521203_output.setInt32(r, 0, _d_month_seq33586);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_7521203_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_7521203_output #Row: " << tbl_Aggregate_TD_7521203_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_7805576_consolidate(Table &tbl_Aggregate_TD_7805576_output_preprocess, Table &tbl_Aggregate_TD_7805576_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_7805576_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _d_month_seq13585 = tbl_Aggregate_TD_7805576_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_7805576_output.setInt32(r, 0, _d_month_seq13585);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_7805576_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_7805576_output #Row: " << tbl_Aggregate_TD_7805576_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7534451(Table &tbl_SerializeFromObject_TD_8205186_input, Table &tbl_Filter_TD_7534451_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(s_county#401) AND isnotnull(s_state#402)))
    // Input: ListBuffer(s_county#401, s_state#402)
    // Output: ListBuffer(s_county#401, s_state#402)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8205186_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _s_county401 = tbl_SerializeFromObject_TD_8205186_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _s_state402 = tbl_SerializeFromObject_TD_8205186_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if (_s_county401.data() != "NULL" && _s_state402.data() != "NULL") {
            std::array<char, TPCDS_READ_MAX + 1> _s_county401_t = tbl_SerializeFromObject_TD_8205186_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            tbl_Filter_TD_7534451_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _s_county401_t);
            std::array<char, TPCDS_READ_MAX + 1> _s_state402_t = tbl_SerializeFromObject_TD_8205186_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_7534451_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _s_state402_t);
            r++;
        }
    }
    tbl_Filter_TD_7534451_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7534451_output #Row: " << tbl_Filter_TD_7534451_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_7928320_key_leftMajor {
    int32_t _c_current_addr_sk4;
    bool operator==(const SW_JOIN_INNER_TD_7928320_key_leftMajor& other) const {
        return ((_c_current_addr_sk4 == other._c_current_addr_sk4));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7928320_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7928320_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_current_addr_sk4));
    }
};
}
struct SW_JOIN_INNER_TD_7928320_payload_leftMajor {
    int32_t _c_customer_sk0;
    int32_t _c_current_addr_sk4;
    int32_t _ss_sold_date_sk1206;
    int64_t _ss_ext_sales_price1221;
};
struct SW_JOIN_INNER_TD_7928320_key_rightMajor {
    int32_t _ca_address_sk54;
    bool operator==(const SW_JOIN_INNER_TD_7928320_key_rightMajor& other) const {
        return ((_ca_address_sk54 == other._ca_address_sk54));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7928320_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7928320_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk54));
    }
};
}
struct SW_JOIN_INNER_TD_7928320_payload_rightMajor {
    int32_t _ca_address_sk54;
    std::string _ca_county61;
    std::string _ca_state62;
};
void SW_JOIN_INNER_TD_7928320(Table &tbl_JOIN_INNER_TD_838624_output, Table &tbl_Filter_TD_8729339_output, Table &tbl_JOIN_INNER_TD_7928320_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((c_current_addr_sk#4 = ca_address_sk#54))
    // Left Table: ListBuffer(c_customer_sk#0, c_current_addr_sk#4, ss_sold_date_sk#1206, ss_ext_sales_price#1221)
    // Right Table: ListBuffer(ca_address_sk#54, ca_county#61, ca_state#62)
    // Output Table: ListBuffer(c_customer_sk#0, ss_sold_date_sk#1206, ss_ext_sales_price#1221, ca_county#61, ca_state#62)
    int left_nrow = tbl_JOIN_INNER_TD_838624_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8729339_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7928320_key_leftMajor, SW_JOIN_INNER_TD_7928320_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_838624_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_current_addr_sk4_k = tbl_JOIN_INNER_TD_838624_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_7928320_key_leftMajor keyA{_c_current_addr_sk4_k};
            int32_t _c_customer_sk0 = tbl_JOIN_INNER_TD_838624_output.getInt32(i, 0);
            int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_838624_output.getInt32(i, 1);
            int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_838624_output.getInt32(i, 2);
            int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_838624_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_7928320_payload_leftMajor payloadA{_c_customer_sk0, _c_current_addr_sk4, _ss_sold_date_sk1206, _ss_ext_sales_price1221};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8729339_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_8729339_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7928320_key_leftMajor{_ca_address_sk54_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk0 = (it->second)._c_customer_sk0;
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int32_t _ca_address_sk54 = tbl_Filter_TD_8729339_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n = tbl_Filter_TD_8729339_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_county61 = std::string(_ca_county61_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_Filter_TD_8729339_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _ca_state62 = std::string(_ca_state62_n.data());
                tbl_JOIN_INNER_TD_7928320_output.setInt32(r, 0, _c_customer_sk0);
                tbl_JOIN_INNER_TD_7928320_output.setInt32(r, 1, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_7928320_output.setInt64(r, 2, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_7928320_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_county61_n);
                tbl_JOIN_INNER_TD_7928320_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _ca_state62_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7928320_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7928320_key_rightMajor, SW_JOIN_INNER_TD_7928320_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8729339_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_8729339_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7928320_key_rightMajor keyA{_ca_address_sk54_k};
            int32_t _ca_address_sk54 = tbl_Filter_TD_8729339_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n = tbl_Filter_TD_8729339_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_county61 = std::string(_ca_county61_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_Filter_TD_8729339_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _ca_state62 = std::string(_ca_state62_n.data());
            SW_JOIN_INNER_TD_7928320_payload_rightMajor payloadA{_ca_address_sk54, _ca_county61, _ca_state62};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_838624_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_current_addr_sk4_k = tbl_JOIN_INNER_TD_838624_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7928320_key_rightMajor{_c_current_addr_sk4_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk54 = (it->second)._ca_address_sk54;
                std::string _ca_county61 = (it->second)._ca_county61;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n{};
                memcpy(_ca_county61_n.data(), (_ca_county61).data(), (_ca_county61).length());
                std::string _ca_state62 = (it->second)._ca_state62;
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n{};
                memcpy(_ca_state62_n.data(), (_ca_state62).data(), (_ca_state62).length());
                int32_t _c_customer_sk0 = tbl_JOIN_INNER_TD_838624_output.getInt32(i, 0);
                int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_838624_output.getInt32(i, 1);
                int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_838624_output.getInt32(i, 2);
                int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_838624_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_7928320_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_county61_n);
                tbl_JOIN_INNER_TD_7928320_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _ca_state62_n);
                tbl_JOIN_INNER_TD_7928320_output.setInt32(r, 0, _c_customer_sk0);
                tbl_JOIN_INNER_TD_7928320_output.setInt32(r, 1, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_7928320_output.setInt64(r, 2, _ss_ext_sales_price1221);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7928320_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7928320_output #Row: " << tbl_JOIN_INNER_TD_7928320_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6320172(Table &tbl_SerializeFromObject_TD_7371785_input, Table &tbl_Aggregate_TD_7805576_output, Table &tbl_Aggregate_TD_7521203_output, Table &tbl_Filter_TD_6320172_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_month_seq#3559) AND ((d_month_seq#3559 >= scalar-subquery#3553 []) AND (d_month_seq#3559 <= scalar-subquery#3554 []))) AND isnotnull(d_date_sk#3556)))
    // Input: ListBuffer(d_date_sk#3556, d_month_seq#3559)
    // Output: ListBuffer(d_date_sk#3556)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7371785_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_month_seq3559 = tbl_SerializeFromObject_TD_7371785_input.getInt32(i, 1);
        int32_t _d_date_sk3556 = tbl_SerializeFromObject_TD_7371785_input.getInt32(i, 0);
        if (((_d_month_seq3559!= 0) && ((_d_month_seq3559 >= tbl_Aggregate_TD_7805576_output.getInt32(0, 0)) && (_d_month_seq3559 <= tbl_Aggregate_TD_7805576_output.getInt32(0, 0)))) && (_d_date_sk3556!= 0)) {
            int32_t _d_date_sk3556_t = tbl_SerializeFromObject_TD_7371785_input.getInt32(i, 0);
            tbl_Filter_TD_6320172_output.setInt32(r, 0, _d_date_sk3556_t);
            r++;
        }
    }
    tbl_Filter_TD_6320172_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6320172_output #Row: " << tbl_Filter_TD_6320172_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6724290_key_leftMajor {
    std::string _ca_county61;
    std::string _ca_state62;
    bool operator==(const SW_JOIN_INNER_TD_6724290_key_leftMajor& other) const {
        return ((_ca_county61 == other._ca_county61) && (_ca_state62 == other._ca_state62));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6724290_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6724290_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._ca_county61)) + (hash<string>()(k._ca_state62));
    }
};
}
struct SW_JOIN_INNER_TD_6724290_payload_leftMajor {
    int32_t _c_customer_sk0;
    int32_t _ss_sold_date_sk1206;
    int64_t _ss_ext_sales_price1221;
    std::string _ca_county61;
    std::string _ca_state62;
};
struct SW_JOIN_INNER_TD_6724290_key_rightMajor {
    std::string _s_county401;
    std::string _s_state402;
    bool operator==(const SW_JOIN_INNER_TD_6724290_key_rightMajor& other) const {
        return ((_s_county401 == other._s_county401) && (_s_state402 == other._s_state402));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6724290_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6724290_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._s_county401)) + (hash<string>()(k._s_state402));
    }
};
}
struct SW_JOIN_INNER_TD_6724290_payload_rightMajor {
    std::string _s_county401;
    std::string _s_state402;
};
void SW_JOIN_INNER_TD_6724290(Table &tbl_JOIN_INNER_TD_7928320_output, Table &tbl_Filter_TD_7534451_output, Table &tbl_JOIN_INNER_TD_6724290_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((ca_county#61 = s_county#401) AND (ca_state#62 = s_state#402)))
    // Left Table: ListBuffer(c_customer_sk#0, ss_sold_date_sk#1206, ss_ext_sales_price#1221, ca_county#61, ca_state#62)
    // Right Table: ListBuffer(s_county#401, s_state#402)
    // Output Table: ListBuffer(c_customer_sk#0, ss_sold_date_sk#1206, ss_ext_sales_price#1221)
    int left_nrow = tbl_JOIN_INNER_TD_7928320_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7534451_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6724290_key_leftMajor, SW_JOIN_INNER_TD_6724290_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7928320_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ca_county61_k_n = tbl_JOIN_INNER_TD_7928320_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _ca_county61_k = std::string(_ca_county61_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_k_n = tbl_JOIN_INNER_TD_7928320_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _ca_state62_k = std::string(_ca_state62_k_n.data());
            SW_JOIN_INNER_TD_6724290_key_leftMajor keyA{_ca_county61_k, _ca_state62_k};
            int32_t _c_customer_sk0 = tbl_JOIN_INNER_TD_7928320_output.getInt32(i, 0);
            int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_7928320_output.getInt32(i, 1);
            int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_7928320_output.getInt64(i, 2);
            std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n = tbl_JOIN_INNER_TD_7928320_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _ca_county61 = std::string(_ca_county61_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_JOIN_INNER_TD_7928320_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _ca_state62 = std::string(_ca_state62_n.data());
            SW_JOIN_INNER_TD_6724290_payload_leftMajor payloadA{_c_customer_sk0, _ss_sold_date_sk1206, _ss_ext_sales_price1221, _ca_county61, _ca_state62};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7534451_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _s_county401_k_n = tbl_Filter_TD_7534451_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _s_county401_k = std::string(_s_county401_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_state402_k_n = tbl_Filter_TD_7534451_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _s_state402_k = std::string(_s_state402_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6724290_key_leftMajor{_s_county401_k, _s_state402_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk0 = (it->second)._c_customer_sk0;
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                std::string _ca_county61 = (it->second)._ca_county61;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n{};
                memcpy(_ca_county61_n.data(), (_ca_county61).data(), (_ca_county61).length());
                std::string _ca_state62 = (it->second)._ca_state62;
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n{};
                memcpy(_ca_state62_n.data(), (_ca_state62).data(), (_ca_state62).length());
                std::array<char, TPCDS_READ_MAX + 1> _s_county401_n = tbl_Filter_TD_7534451_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _s_county401 = std::string(_s_county401_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _s_state402_n = tbl_Filter_TD_7534451_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _s_state402 = std::string(_s_state402_n.data());
                tbl_JOIN_INNER_TD_6724290_output.setInt32(r, 0, _c_customer_sk0);
                tbl_JOIN_INNER_TD_6724290_output.setInt32(r, 1, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_6724290_output.setInt64(r, 2, _ss_ext_sales_price1221);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6724290_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6724290_key_rightMajor, SW_JOIN_INNER_TD_6724290_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7534451_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _s_county401_k_n = tbl_Filter_TD_7534451_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _s_county401_k = std::string(_s_county401_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_state402_k_n = tbl_Filter_TD_7534451_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _s_state402_k = std::string(_s_state402_k_n.data());
            SW_JOIN_INNER_TD_6724290_key_rightMajor keyA{_s_county401_k, _s_state402_k};
            std::array<char, TPCDS_READ_MAX + 1> _s_county401_n = tbl_Filter_TD_7534451_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _s_county401 = std::string(_s_county401_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _s_state402_n = tbl_Filter_TD_7534451_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _s_state402 = std::string(_s_state402_n.data());
            SW_JOIN_INNER_TD_6724290_payload_rightMajor payloadA{_s_county401, _s_state402};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7928320_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ca_county61_k_n = tbl_JOIN_INNER_TD_7928320_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _ca_county61_k = std::string(_ca_county61_k_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_k_n = tbl_JOIN_INNER_TD_7928320_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _ca_state62_k = std::string(_ca_state62_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6724290_key_rightMajor{_ca_county61_k, _ca_state62_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _s_county401 = (it->second)._s_county401;
                std::array<char, TPCDS_READ_MAX + 1> _s_county401_n{};
                memcpy(_s_county401_n.data(), (_s_county401).data(), (_s_county401).length());
                std::string _s_state402 = (it->second)._s_state402;
                std::array<char, TPCDS_READ_MAX + 1> _s_state402_n{};
                memcpy(_s_state402_n.data(), (_s_state402).data(), (_s_state402).length());
                int32_t _c_customer_sk0 = tbl_JOIN_INNER_TD_7928320_output.getInt32(i, 0);
                int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_7928320_output.getInt32(i, 1);
                int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_7928320_output.getInt64(i, 2);
                std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n = tbl_JOIN_INNER_TD_7928320_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _ca_county61 = std::string(_ca_county61_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_JOIN_INNER_TD_7928320_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _ca_state62 = std::string(_ca_state62_n.data());
                tbl_JOIN_INNER_TD_6724290_output.setInt32(r, 0, _c_customer_sk0);
                tbl_JOIN_INNER_TD_6724290_output.setInt32(r, 1, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_6724290_output.setInt64(r, 2, _ss_ext_sales_price1221);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6724290_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6724290_output #Row: " << tbl_JOIN_INNER_TD_6724290_output.getNumRow() << std::endl;
}


void SW_Aggregate_TD_4795083_consolidate(Table &tbl_Aggregate_TD_4795083_output_preprocess, Table &tbl_Aggregate_TD_4795083_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_4795083_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _segment3555 = tbl_Aggregate_TD_4795083_output_preprocess.getInt32(r, 0);
        tbl_Aggregate_TD_4795083_output.setInt32(r, 0, _segment3555);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_4795083_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_4795083_output #Row: " << tbl_Aggregate_TD_4795083_output.getNumRow() << std::endl;
}

typedef int32_t SW_Aggregate_TD_325302_key;
struct SW_Aggregate_TD_325302_payload {
    int64_t _num_customers3544L_count_0;
    int32_t _segment_base3545;
};
void SW_Aggregate_TD_325302(Table &tbl_Aggregate_TD_4795083_output, Table &tbl_Aggregate_TD_325302_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(segment#3555, count(1) AS num_customers#3544L, (segment#3555 * 50) AS segment_base#3545)
    // Input: ListBuffer(segment#3555)
    // Output: ListBuffer(segment#3555, num_customers#3544L, segment_base#3545)
    std::unordered_map<SW_Aggregate_TD_325302_key, SW_Aggregate_TD_325302_payload> ht1;
    int nrow1 = tbl_Aggregate_TD_4795083_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _segment3555 = tbl_Aggregate_TD_4795083_output.getInt32(i, 0);
        SW_Aggregate_TD_325302_key k = _segment3555;
        int64_t _num_customers3544L_count_0 = 1 != 0 ? 1 : 0;
        int32_t _segment_base3545 = (_segment3555 * 50);
        SW_Aggregate_TD_325302_payload p{_num_customers3544L_count_0, _segment_base3545};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t count_0 = (it->second)._num_customers3544L_count_0 + _num_customers3544L_count_0;
            p._num_customers3544L_count_0 = count_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        tbl_Aggregate_TD_325302_output.setInt32(r, 0, (it.first));
        int64_t _num_customers3544L = (it.second)._num_customers3544L_count_0;
        tbl_Aggregate_TD_325302_output.setInt64(r, 1, _num_customers3544L);
        tbl_Aggregate_TD_325302_output.setInt32(r, 2, (it.second)._segment_base3545);
        ++r;
    }
    tbl_Aggregate_TD_325302_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_325302_output #Row: " << tbl_Aggregate_TD_325302_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2149954(Table &tbl_Aggregate_TD_325302_output, Table &tbl_Sort_TD_2149954_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(segment#3555 ASC NULLS FIRST, num_customers#3544L ASC NULLS FIRST)
    // Input: ListBuffer(segment#3555, num_customers#3544L, segment_base#3545)
    // Output: ListBuffer(segment#3555, num_customers#3544L, segment_base#3545)
    struct SW_Sort_TD_2149954Row {
        int32_t _segment3555;
        int64_t _num_customers3544L;
        int32_t _segment_base3545;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2149954Row& a, const SW_Sort_TD_2149954Row& b) const { return 
 (a._segment3555 < b._segment3555) || 
 ((a._segment3555 == b._segment3555) && (a._num_customers3544L < b._num_customers3544L)); 
}
    }SW_Sort_TD_2149954_order; 

    int nrow1 = tbl_Aggregate_TD_325302_output.getNumRow();
    std::vector<SW_Sort_TD_2149954Row> rows;
    for (int i = 0; i < nrow1; i++) {
        int32_t _segment3555 = tbl_Aggregate_TD_325302_output.getInt32(i, 0);
        int64_t _num_customers3544L = tbl_Aggregate_TD_325302_output.getInt64(i, 1);
        int32_t _segment_base3545 = tbl_Aggregate_TD_325302_output.getInt32(i, 2);
        SW_Sort_TD_2149954Row t = {_segment3555,_num_customers3544L,_segment_base3545};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2149954_order);
    int r = 0;
    for (auto& it : rows) {
        tbl_Sort_TD_2149954_output.setInt32(r, 0, it._segment3555);
        tbl_Sort_TD_2149954_output.setInt64(r, 1, it._num_customers3544L);
        tbl_Sort_TD_2149954_output.setInt32(r, 2, it._segment_base3545);
        ++r;
    }
    tbl_Sort_TD_2149954_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2149954_output #Row: " << tbl_Sort_TD_2149954_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1325297(Table &tbl_Sort_TD_2149954_output, Table &tbl_LocalLimit_TD_1325297_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(segment#3555, num_customers#3544L, segment_base#3545)
    // Output: ListBuffer(segment#3555, num_customers#3544L, segment_base#3545)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        tbl_LocalLimit_TD_1325297_output.setInt32(r, 0, tbl_Sort_TD_2149954_output.getInt32(i, 0));
        tbl_LocalLimit_TD_1325297_output.setInt64(r, 1, tbl_Sort_TD_2149954_output.getInt64(i, 1));
        tbl_LocalLimit_TD_1325297_output.setInt32(r, 2, tbl_Sort_TD_2149954_output.getInt32(i, 2));
        r++;
    }
    tbl_LocalLimit_TD_1325297_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1325297_output #Row: " << tbl_LocalLimit_TD_1325297_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0179492(Table &tbl_LocalLimit_TD_1325297_output, Table &tbl_GlobalLimit_TD_0179492_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(segment#3555, num_customers#3544L, segment_base#3545)
    // Output: ListBuffer(segment#3555, num_customers#3544L, segment_base#3545)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        tbl_GlobalLimit_TD_0179492_output.setInt32(r, 0, tbl_LocalLimit_TD_1325297_output.getInt32(i, 0));
        tbl_GlobalLimit_TD_0179492_output.setInt64(r, 1, tbl_LocalLimit_TD_1325297_output.getInt64(i, 1));
        tbl_GlobalLimit_TD_0179492_output.setInt32(r, 2, tbl_LocalLimit_TD_1325297_output.getInt32(i, 2));
        r++;
    }
    tbl_GlobalLimit_TD_0179492_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0179492_output #Row: " << tbl_GlobalLimit_TD_0179492_output.getNumRow() << std::endl;
}

