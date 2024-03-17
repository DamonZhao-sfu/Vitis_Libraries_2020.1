#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_12881251(Table &tbl_SerializeFromObject_TD_13186167_input, Table &tbl_Filter_TD_12881251_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(i_category#4676) AND (i_category#4676 = Books)) AND isnotnull(i_item_sk#4664)) AND (((isnotnull(i_brand_id#4671) AND isnotnull(i_class_id#4673)) AND isnotnull(i_category_id#4675)) AND isnotnull(i_manufact_id#4677))))
    // Input: ListBuffer(i_item_sk#4664, i_brand_id#4671, i_class_id#4673, i_category_id#4675, i_manufact_id#4677, i_category#4676)
    // Output: ListBuffer(i_item_sk#4664, i_brand_id#4671, i_class_id#4673, i_category_id#4675, i_manufact_id#4677)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13186167_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category4676 = tbl_SerializeFromObject_TD_13186167_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        int32_t _i_item_sk4664 = tbl_SerializeFromObject_TD_13186167_input.getInt32(i, 0);
        int32_t _i_brand_id4671 = tbl_SerializeFromObject_TD_13186167_input.getInt32(i, 1);
        int32_t _i_class_id4673 = tbl_SerializeFromObject_TD_13186167_input.getInt32(i, 2);
        int32_t _i_category_id4675 = tbl_SerializeFromObject_TD_13186167_input.getInt32(i, 3);
        int32_t _i_manufact_id4677 = tbl_SerializeFromObject_TD_13186167_input.getInt32(i, 4);
        if (((_i_category4676.data() != "NULL" && (std::string(_i_category4676.data()) == "Books")) && (_i_item_sk4664!= 0)) && ((((_i_brand_id4671!= 0) && (_i_class_id4673!= 0)) && (_i_category_id4675!= 0)) && (_i_manufact_id4677!= 0))) {
            int32_t _i_item_sk4664_t = tbl_SerializeFromObject_TD_13186167_input.getInt32(i, 0);
            tbl_Filter_TD_12881251_output.setInt32(r, 0, _i_item_sk4664_t);
            int32_t _i_brand_id4671_t = tbl_SerializeFromObject_TD_13186167_input.getInt32(i, 1);
            tbl_Filter_TD_12881251_output.setInt32(r, 1, _i_brand_id4671_t);
            int32_t _i_class_id4673_t = tbl_SerializeFromObject_TD_13186167_input.getInt32(i, 2);
            tbl_Filter_TD_12881251_output.setInt32(r, 2, _i_class_id4673_t);
            int32_t _i_category_id4675_t = tbl_SerializeFromObject_TD_13186167_input.getInt32(i, 3);
            tbl_Filter_TD_12881251_output.setInt32(r, 3, _i_category_id4675_t);
            int32_t _i_manufact_id4677_t = tbl_SerializeFromObject_TD_13186167_input.getInt32(i, 4);
            tbl_Filter_TD_12881251_output.setInt32(r, 4, _i_manufact_id4677_t);
            r++;
        }
    }
    tbl_Filter_TD_12881251_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12881251_output #Row: " << tbl_Filter_TD_12881251_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12741275(Table &tbl_SerializeFromObject_TD_13650294_input, Table &tbl_Filter_TD_12741275_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_item_sk#4633) AND isnotnull(ws_sold_date_sk#4630)))
    // Input: ListBuffer(ws_sold_date_sk#4630, ws_item_sk#4633, ws_order_number#4647L, ws_quantity#4648, ws_ext_sales_price#4653)
    // Output: ListBuffer(ws_sold_date_sk#4630, ws_item_sk#4633, ws_order_number#4647L, ws_quantity#4648, ws_ext_sales_price#4653)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13650294_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_item_sk4633 = tbl_SerializeFromObject_TD_13650294_input.getInt32(i, 1);
        int32_t _ws_sold_date_sk4630 = tbl_SerializeFromObject_TD_13650294_input.getInt32(i, 0);
        if ((_ws_item_sk4633!= 0) && (_ws_sold_date_sk4630!= 0)) {
            int32_t _ws_sold_date_sk4630_t = tbl_SerializeFromObject_TD_13650294_input.getInt32(i, 0);
            tbl_Filter_TD_12741275_output.setInt32(r, 0, _ws_sold_date_sk4630_t);
            int32_t _ws_item_sk4633_t = tbl_SerializeFromObject_TD_13650294_input.getInt32(i, 1);
            tbl_Filter_TD_12741275_output.setInt32(r, 1, _ws_item_sk4633_t);
            int64_t _ws_order_number4647L_t = tbl_SerializeFromObject_TD_13650294_input.getInt64(i, 2);
            tbl_Filter_TD_12741275_output.setInt64(r, 2, _ws_order_number4647L_t);
            int32_t _ws_quantity4648_t = tbl_SerializeFromObject_TD_13650294_input.getInt32(i, 3);
            tbl_Filter_TD_12741275_output.setInt32(r, 3, _ws_quantity4648_t);
            int64_t _ws_ext_sales_price4653_t = tbl_SerializeFromObject_TD_13650294_input.getInt64(i, 4);
            tbl_Filter_TD_12741275_output.setInt64(r, 4, _ws_ext_sales_price4653_t);
            r++;
        }
    }
    tbl_Filter_TD_12741275_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12741275_output #Row: " << tbl_Filter_TD_12741275_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12246209(Table &tbl_SerializeFromObject_TD_13207901_input, Table &tbl_Filter_TD_12246209_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(i_category#4572) AND (i_category#4572 = Books)) AND isnotnull(i_item_sk#4560)) AND (((isnotnull(i_brand_id#4567) AND isnotnull(i_class_id#4569)) AND isnotnull(i_category_id#4571)) AND isnotnull(i_manufact_id#4573))))
    // Input: ListBuffer(i_item_sk#4560, i_brand_id#4567, i_class_id#4569, i_category_id#4571, i_manufact_id#4573, i_category#4572)
    // Output: ListBuffer(i_item_sk#4560, i_brand_id#4567, i_class_id#4569, i_category_id#4571, i_manufact_id#4573)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13207901_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category4572 = tbl_SerializeFromObject_TD_13207901_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        int32_t _i_item_sk4560 = tbl_SerializeFromObject_TD_13207901_input.getInt32(i, 0);
        int32_t _i_brand_id4567 = tbl_SerializeFromObject_TD_13207901_input.getInt32(i, 1);
        int32_t _i_class_id4569 = tbl_SerializeFromObject_TD_13207901_input.getInt32(i, 2);
        int32_t _i_category_id4571 = tbl_SerializeFromObject_TD_13207901_input.getInt32(i, 3);
        int32_t _i_manufact_id4573 = tbl_SerializeFromObject_TD_13207901_input.getInt32(i, 4);
        if (((_i_category4572.data() != "NULL" && (std::string(_i_category4572.data()) == "Books")) && (_i_item_sk4560!= 0)) && ((((_i_brand_id4567!= 0) && (_i_class_id4569!= 0)) && (_i_category_id4571!= 0)) && (_i_manufact_id4573!= 0))) {
            int32_t _i_item_sk4560_t = tbl_SerializeFromObject_TD_13207901_input.getInt32(i, 0);
            tbl_Filter_TD_12246209_output.setInt32(r, 0, _i_item_sk4560_t);
            int32_t _i_brand_id4567_t = tbl_SerializeFromObject_TD_13207901_input.getInt32(i, 1);
            tbl_Filter_TD_12246209_output.setInt32(r, 1, _i_brand_id4567_t);
            int32_t _i_class_id4569_t = tbl_SerializeFromObject_TD_13207901_input.getInt32(i, 2);
            tbl_Filter_TD_12246209_output.setInt32(r, 2, _i_class_id4569_t);
            int32_t _i_category_id4571_t = tbl_SerializeFromObject_TD_13207901_input.getInt32(i, 3);
            tbl_Filter_TD_12246209_output.setInt32(r, 3, _i_category_id4571_t);
            int32_t _i_manufact_id4573_t = tbl_SerializeFromObject_TD_13207901_input.getInt32(i, 4);
            tbl_Filter_TD_12246209_output.setInt32(r, 4, _i_manufact_id4573_t);
            r++;
        }
    }
    tbl_Filter_TD_12246209_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12246209_output #Row: " << tbl_Filter_TD_12246209_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12349655(Table &tbl_SerializeFromObject_TD_13788587_input, Table &tbl_Filter_TD_12349655_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_item_sk#4539) AND isnotnull(ss_sold_date_sk#4537)))
    // Input: ListBuffer(ss_sold_date_sk#4537, ss_item_sk#4539, ss_ticket_number#4546L, ss_quantity#4547, ss_ext_sales_price#4552)
    // Output: ListBuffer(ss_sold_date_sk#4537, ss_item_sk#4539, ss_ticket_number#4546L, ss_quantity#4547, ss_ext_sales_price#4552)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13788587_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_item_sk4539 = tbl_SerializeFromObject_TD_13788587_input.getInt32(i, 1);
        int32_t _ss_sold_date_sk4537 = tbl_SerializeFromObject_TD_13788587_input.getInt32(i, 0);
        if ((_ss_item_sk4539!= 0) && (_ss_sold_date_sk4537!= 0)) {
            int32_t _ss_sold_date_sk4537_t = tbl_SerializeFromObject_TD_13788587_input.getInt32(i, 0);
            tbl_Filter_TD_12349655_output.setInt32(r, 0, _ss_sold_date_sk4537_t);
            int32_t _ss_item_sk4539_t = tbl_SerializeFromObject_TD_13788587_input.getInt32(i, 1);
            tbl_Filter_TD_12349655_output.setInt32(r, 1, _ss_item_sk4539_t);
            int64_t _ss_ticket_number4546L_t = tbl_SerializeFromObject_TD_13788587_input.getInt64(i, 2);
            tbl_Filter_TD_12349655_output.setInt64(r, 2, _ss_ticket_number4546L_t);
            int32_t _ss_quantity4547_t = tbl_SerializeFromObject_TD_13788587_input.getInt32(i, 3);
            tbl_Filter_TD_12349655_output.setInt32(r, 3, _ss_quantity4547_t);
            int64_t _ss_ext_sales_price4552_t = tbl_SerializeFromObject_TD_13788587_input.getInt64(i, 4);
            tbl_Filter_TD_12349655_output.setInt64(r, 4, _ss_ext_sales_price4552_t);
            r++;
        }
    }
    tbl_Filter_TD_12349655_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12349655_output #Row: " << tbl_Filter_TD_12349655_output.getNumRow() << std::endl;
}

void SW_Filter_TD_1270854(Table &tbl_SerializeFromObject_TD_13916556_input, Table &tbl_Filter_TD_1270854_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(i_category#4472) AND (i_category#4472 = Books)) AND isnotnull(i_item_sk#4460)) AND (((isnotnull(i_brand_id#4467) AND isnotnull(i_class_id#4469)) AND isnotnull(i_category_id#4471)) AND isnotnull(i_manufact_id#4473))))
    // Input: ListBuffer(i_item_sk#4460, i_brand_id#4467, i_class_id#4469, i_category_id#4471, i_manufact_id#4473, i_category#4472)
    // Output: ListBuffer(i_item_sk#4460, i_brand_id#4467, i_class_id#4469, i_category_id#4471, i_manufact_id#4473)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13916556_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category4472 = tbl_SerializeFromObject_TD_13916556_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        int32_t _i_item_sk4460 = tbl_SerializeFromObject_TD_13916556_input.getInt32(i, 0);
        int32_t _i_brand_id4467 = tbl_SerializeFromObject_TD_13916556_input.getInt32(i, 1);
        int32_t _i_class_id4469 = tbl_SerializeFromObject_TD_13916556_input.getInt32(i, 2);
        int32_t _i_category_id4471 = tbl_SerializeFromObject_TD_13916556_input.getInt32(i, 3);
        int32_t _i_manufact_id4473 = tbl_SerializeFromObject_TD_13916556_input.getInt32(i, 4);
        if (((_i_category4472.data() != "NULL" && (std::string(_i_category4472.data()) == "Books")) && (_i_item_sk4460!= 0)) && ((((_i_brand_id4467!= 0) && (_i_class_id4469!= 0)) && (_i_category_id4471!= 0)) && (_i_manufact_id4473!= 0))) {
            int32_t _i_item_sk4460_t = tbl_SerializeFromObject_TD_13916556_input.getInt32(i, 0);
            tbl_Filter_TD_1270854_output.setInt32(r, 0, _i_item_sk4460_t);
            int32_t _i_brand_id4467_t = tbl_SerializeFromObject_TD_13916556_input.getInt32(i, 1);
            tbl_Filter_TD_1270854_output.setInt32(r, 1, _i_brand_id4467_t);
            int32_t _i_class_id4469_t = tbl_SerializeFromObject_TD_13916556_input.getInt32(i, 2);
            tbl_Filter_TD_1270854_output.setInt32(r, 2, _i_class_id4469_t);
            int32_t _i_category_id4471_t = tbl_SerializeFromObject_TD_13916556_input.getInt32(i, 3);
            tbl_Filter_TD_1270854_output.setInt32(r, 3, _i_category_id4471_t);
            int32_t _i_manufact_id4473_t = tbl_SerializeFromObject_TD_13916556_input.getInt32(i, 4);
            tbl_Filter_TD_1270854_output.setInt32(r, 4, _i_manufact_id4473_t);
            r++;
        }
    }
    tbl_Filter_TD_1270854_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1270854_output #Row: " << tbl_Filter_TD_1270854_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12968394(Table &tbl_SerializeFromObject_TD_13386576_input, Table &tbl_Filter_TD_12968394_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cs_item_sk#4441) AND isnotnull(cs_sold_date_sk#4426)))
    // Input: ListBuffer(cs_sold_date_sk#4426, cs_item_sk#4441, cs_order_number#4443L, cs_quantity#4444, cs_ext_sales_price#4449)
    // Output: ListBuffer(cs_sold_date_sk#4426, cs_item_sk#4441, cs_order_number#4443L, cs_quantity#4444, cs_ext_sales_price#4449)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13386576_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_item_sk4441 = tbl_SerializeFromObject_TD_13386576_input.getInt32(i, 1);
        int32_t _cs_sold_date_sk4426 = tbl_SerializeFromObject_TD_13386576_input.getInt32(i, 0);
        if ((_cs_item_sk4441!= 0) && (_cs_sold_date_sk4426!= 0)) {
            int32_t _cs_sold_date_sk4426_t = tbl_SerializeFromObject_TD_13386576_input.getInt32(i, 0);
            tbl_Filter_TD_12968394_output.setInt32(r, 0, _cs_sold_date_sk4426_t);
            int32_t _cs_item_sk4441_t = tbl_SerializeFromObject_TD_13386576_input.getInt32(i, 1);
            tbl_Filter_TD_12968394_output.setInt32(r, 1, _cs_item_sk4441_t);
            int64_t _cs_order_number4443L_t = tbl_SerializeFromObject_TD_13386576_input.getInt64(i, 2);
            tbl_Filter_TD_12968394_output.setInt64(r, 2, _cs_order_number4443L_t);
            int32_t _cs_quantity4444_t = tbl_SerializeFromObject_TD_13386576_input.getInt32(i, 3);
            tbl_Filter_TD_12968394_output.setInt32(r, 3, _cs_quantity4444_t);
            int64_t _cs_ext_sales_price4449_t = tbl_SerializeFromObject_TD_13386576_input.getInt64(i, 4);
            tbl_Filter_TD_12968394_output.setInt64(r, 4, _cs_ext_sales_price4449_t);
            r++;
        }
    }
    tbl_Filter_TD_12968394_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12968394_output #Row: " << tbl_Filter_TD_12968394_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12301909(Table &tbl_SerializeFromObject_TD_13679127_input, Table &tbl_Filter_TD_12301909_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(i_category#3620) AND (i_category#3620 = Books)) AND isnotnull(i_item_sk#3608)) AND (((isnotnull(i_brand_id#3615) AND isnotnull(i_class_id#3617)) AND isnotnull(i_category_id#3619)) AND isnotnull(i_manufact_id#3621))))
    // Input: ListBuffer(i_item_sk#3608, i_brand_id#3615, i_class_id#3617, i_category_id#3619, i_manufact_id#3621, i_category#3620)
    // Output: ListBuffer(i_item_sk#3608, i_brand_id#3615, i_class_id#3617, i_category_id#3619, i_manufact_id#3621)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13679127_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category3620 = tbl_SerializeFromObject_TD_13679127_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        int32_t _i_item_sk3608 = tbl_SerializeFromObject_TD_13679127_input.getInt32(i, 0);
        int32_t _i_brand_id3615 = tbl_SerializeFromObject_TD_13679127_input.getInt32(i, 1);
        int32_t _i_class_id3617 = tbl_SerializeFromObject_TD_13679127_input.getInt32(i, 2);
        int32_t _i_category_id3619 = tbl_SerializeFromObject_TD_13679127_input.getInt32(i, 3);
        int32_t _i_manufact_id3621 = tbl_SerializeFromObject_TD_13679127_input.getInt32(i, 4);
        if (((_i_category3620.data() != "NULL" && (std::string(_i_category3620.data()) == "Books")) && (_i_item_sk3608!= 0)) && ((((_i_brand_id3615!= 0) && (_i_class_id3617!= 0)) && (_i_category_id3619!= 0)) && (_i_manufact_id3621!= 0))) {
            int32_t _i_item_sk3608_t = tbl_SerializeFromObject_TD_13679127_input.getInt32(i, 0);
            tbl_Filter_TD_12301909_output.setInt32(r, 0, _i_item_sk3608_t);
            int32_t _i_brand_id3615_t = tbl_SerializeFromObject_TD_13679127_input.getInt32(i, 1);
            tbl_Filter_TD_12301909_output.setInt32(r, 1, _i_brand_id3615_t);
            int32_t _i_class_id3617_t = tbl_SerializeFromObject_TD_13679127_input.getInt32(i, 2);
            tbl_Filter_TD_12301909_output.setInt32(r, 2, _i_class_id3617_t);
            int32_t _i_category_id3619_t = tbl_SerializeFromObject_TD_13679127_input.getInt32(i, 3);
            tbl_Filter_TD_12301909_output.setInt32(r, 3, _i_category_id3619_t);
            int32_t _i_manufact_id3621_t = tbl_SerializeFromObject_TD_13679127_input.getInt32(i, 4);
            tbl_Filter_TD_12301909_output.setInt32(r, 4, _i_manufact_id3621_t);
            r++;
        }
    }
    tbl_Filter_TD_12301909_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12301909_output #Row: " << tbl_Filter_TD_12301909_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12460154(Table &tbl_SerializeFromObject_TD_13634156_input, Table &tbl_Filter_TD_12460154_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_item_sk#732) AND isnotnull(ws_sold_date_sk#729)))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_order_number#746L, ws_quantity#747, ws_ext_sales_price#752)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_order_number#746L, ws_quantity#747, ws_ext_sales_price#752)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13634156_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_item_sk732 = tbl_SerializeFromObject_TD_13634156_input.getInt32(i, 1);
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_13634156_input.getInt32(i, 0);
        if ((_ws_item_sk732!= 0) && (_ws_sold_date_sk729!= 0)) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_13634156_input.getInt32(i, 0);
            tbl_Filter_TD_12460154_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_item_sk732_t = tbl_SerializeFromObject_TD_13634156_input.getInt32(i, 1);
            tbl_Filter_TD_12460154_output.setInt32(r, 1, _ws_item_sk732_t);
            int64_t _ws_order_number746L_t = tbl_SerializeFromObject_TD_13634156_input.getInt64(i, 2);
            tbl_Filter_TD_12460154_output.setInt64(r, 2, _ws_order_number746L_t);
            int32_t _ws_quantity747_t = tbl_SerializeFromObject_TD_13634156_input.getInt32(i, 3);
            tbl_Filter_TD_12460154_output.setInt32(r, 3, _ws_quantity747_t);
            int64_t _ws_ext_sales_price752_t = tbl_SerializeFromObject_TD_13634156_input.getInt64(i, 4);
            tbl_Filter_TD_12460154_output.setInt64(r, 4, _ws_ext_sales_price752_t);
            r++;
        }
    }
    tbl_Filter_TD_12460154_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12460154_output #Row: " << tbl_Filter_TD_12460154_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12968861(Table &tbl_SerializeFromObject_TD_13698675_input, Table &tbl_Filter_TD_12968861_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(i_category#3570) AND (i_category#3570 = Books)) AND isnotnull(i_item_sk#3558)) AND (((isnotnull(i_brand_id#3565) AND isnotnull(i_class_id#3567)) AND isnotnull(i_category_id#3569)) AND isnotnull(i_manufact_id#3571))))
    // Input: ListBuffer(i_item_sk#3558, i_brand_id#3565, i_class_id#3567, i_category_id#3569, i_manufact_id#3571, i_category#3570)
    // Output: ListBuffer(i_item_sk#3558, i_brand_id#3565, i_class_id#3567, i_category_id#3569, i_manufact_id#3571)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13698675_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category3570 = tbl_SerializeFromObject_TD_13698675_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        int32_t _i_item_sk3558 = tbl_SerializeFromObject_TD_13698675_input.getInt32(i, 0);
        int32_t _i_brand_id3565 = tbl_SerializeFromObject_TD_13698675_input.getInt32(i, 1);
        int32_t _i_class_id3567 = tbl_SerializeFromObject_TD_13698675_input.getInt32(i, 2);
        int32_t _i_category_id3569 = tbl_SerializeFromObject_TD_13698675_input.getInt32(i, 3);
        int32_t _i_manufact_id3571 = tbl_SerializeFromObject_TD_13698675_input.getInt32(i, 4);
        if (((_i_category3570.data() != "NULL" && (std::string(_i_category3570.data()) == "Books")) && (_i_item_sk3558!= 0)) && ((((_i_brand_id3565!= 0) && (_i_class_id3567!= 0)) && (_i_category_id3569!= 0)) && (_i_manufact_id3571!= 0))) {
            int32_t _i_item_sk3558_t = tbl_SerializeFromObject_TD_13698675_input.getInt32(i, 0);
            tbl_Filter_TD_12968861_output.setInt32(r, 0, _i_item_sk3558_t);
            int32_t _i_brand_id3565_t = tbl_SerializeFromObject_TD_13698675_input.getInt32(i, 1);
            tbl_Filter_TD_12968861_output.setInt32(r, 1, _i_brand_id3565_t);
            int32_t _i_class_id3567_t = tbl_SerializeFromObject_TD_13698675_input.getInt32(i, 2);
            tbl_Filter_TD_12968861_output.setInt32(r, 2, _i_class_id3567_t);
            int32_t _i_category_id3569_t = tbl_SerializeFromObject_TD_13698675_input.getInt32(i, 3);
            tbl_Filter_TD_12968861_output.setInt32(r, 3, _i_category_id3569_t);
            int32_t _i_manufact_id3571_t = tbl_SerializeFromObject_TD_13698675_input.getInt32(i, 4);
            tbl_Filter_TD_12968861_output.setInt32(r, 4, _i_manufact_id3571_t);
            r++;
        }
    }
    tbl_Filter_TD_12968861_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12968861_output #Row: " << tbl_Filter_TD_12968861_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12304293(Table &tbl_SerializeFromObject_TD_13666961_input, Table &tbl_Filter_TD_12304293_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_item_sk#1208) AND isnotnull(ss_sold_date_sk#1206)))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_ticket_number#1215L, ss_quantity#1216, ss_ext_sales_price#1221)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_ticket_number#1215L, ss_quantity#1216, ss_ext_sales_price#1221)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13666961_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_13666961_input.getInt32(i, 1);
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_13666961_input.getInt32(i, 0);
        if ((_ss_item_sk1208!= 0) && (_ss_sold_date_sk1206!= 0)) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_13666961_input.getInt32(i, 0);
            tbl_Filter_TD_12304293_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_13666961_input.getInt32(i, 1);
            tbl_Filter_TD_12304293_output.setInt32(r, 1, _ss_item_sk1208_t);
            int64_t _ss_ticket_number1215L_t = tbl_SerializeFromObject_TD_13666961_input.getInt64(i, 2);
            tbl_Filter_TD_12304293_output.setInt64(r, 2, _ss_ticket_number1215L_t);
            int32_t _ss_quantity1216_t = tbl_SerializeFromObject_TD_13666961_input.getInt32(i, 3);
            tbl_Filter_TD_12304293_output.setInt32(r, 3, _ss_quantity1216_t);
            int64_t _ss_ext_sales_price1221_t = tbl_SerializeFromObject_TD_13666961_input.getInt64(i, 4);
            tbl_Filter_TD_12304293_output.setInt64(r, 4, _ss_ext_sales_price1221_t);
            r++;
        }
    }
    tbl_Filter_TD_12304293_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12304293_output #Row: " << tbl_Filter_TD_12304293_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12265825(Table &tbl_SerializeFromObject_TD_13648438_input, Table &tbl_Filter_TD_12265825_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(i_category#240) AND (i_category#240 = Books)) AND isnotnull(i_item_sk#228)) AND (((isnotnull(i_brand_id#235) AND isnotnull(i_class_id#237)) AND isnotnull(i_category_id#239)) AND isnotnull(i_manufact_id#241))))
    // Input: ListBuffer(i_item_sk#228, i_brand_id#235, i_class_id#237, i_category_id#239, i_manufact_id#241, i_category#240)
    // Output: ListBuffer(i_item_sk#228, i_brand_id#235, i_class_id#237, i_category_id#239, i_manufact_id#241)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13648438_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category240 = tbl_SerializeFromObject_TD_13648438_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_13648438_input.getInt32(i, 0);
        int32_t _i_brand_id235 = tbl_SerializeFromObject_TD_13648438_input.getInt32(i, 1);
        int32_t _i_class_id237 = tbl_SerializeFromObject_TD_13648438_input.getInt32(i, 2);
        int32_t _i_category_id239 = tbl_SerializeFromObject_TD_13648438_input.getInt32(i, 3);
        int32_t _i_manufact_id241 = tbl_SerializeFromObject_TD_13648438_input.getInt32(i, 4);
        if (((_i_category240.data() != "NULL" && (std::string(_i_category240.data()) == "Books")) && (_i_item_sk228!= 0)) && ((((_i_brand_id235!= 0) && (_i_class_id237!= 0)) && (_i_category_id239!= 0)) && (_i_manufact_id241!= 0))) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_13648438_input.getInt32(i, 0);
            tbl_Filter_TD_12265825_output.setInt32(r, 0, _i_item_sk228_t);
            int32_t _i_brand_id235_t = tbl_SerializeFromObject_TD_13648438_input.getInt32(i, 1);
            tbl_Filter_TD_12265825_output.setInt32(r, 1, _i_brand_id235_t);
            int32_t _i_class_id237_t = tbl_SerializeFromObject_TD_13648438_input.getInt32(i, 2);
            tbl_Filter_TD_12265825_output.setInt32(r, 2, _i_class_id237_t);
            int32_t _i_category_id239_t = tbl_SerializeFromObject_TD_13648438_input.getInt32(i, 3);
            tbl_Filter_TD_12265825_output.setInt32(r, 3, _i_category_id239_t);
            int32_t _i_manufact_id241_t = tbl_SerializeFromObject_TD_13648438_input.getInt32(i, 4);
            tbl_Filter_TD_12265825_output.setInt32(r, 4, _i_manufact_id241_t);
            r++;
        }
    }
    tbl_Filter_TD_12265825_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12265825_output #Row: " << tbl_Filter_TD_12265825_output.getNumRow() << std::endl;
}

void SW_Filter_TD_1278768(Table &tbl_SerializeFromObject_TD_13951278_input, Table &tbl_Filter_TD_1278768_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cs_item_sk#1119) AND isnotnull(cs_sold_date_sk#1104)))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119, cs_order_number#1121L, cs_quantity#1122, cs_ext_sales_price#1127)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119, cs_order_number#1121L, cs_quantity#1122, cs_ext_sales_price#1127)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13951278_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_item_sk1119 = tbl_SerializeFromObject_TD_13951278_input.getInt32(i, 1);
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_13951278_input.getInt32(i, 0);
        if ((_cs_item_sk1119!= 0) && (_cs_sold_date_sk1104!= 0)) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_13951278_input.getInt32(i, 0);
            tbl_Filter_TD_1278768_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int32_t _cs_item_sk1119_t = tbl_SerializeFromObject_TD_13951278_input.getInt32(i, 1);
            tbl_Filter_TD_1278768_output.setInt32(r, 1, _cs_item_sk1119_t);
            int64_t _cs_order_number1121L_t = tbl_SerializeFromObject_TD_13951278_input.getInt64(i, 2);
            tbl_Filter_TD_1278768_output.setInt64(r, 2, _cs_order_number1121L_t);
            int32_t _cs_quantity1122_t = tbl_SerializeFromObject_TD_13951278_input.getInt32(i, 3);
            tbl_Filter_TD_1278768_output.setInt32(r, 3, _cs_quantity1122_t);
            int64_t _cs_ext_sales_price1127_t = tbl_SerializeFromObject_TD_13951278_input.getInt64(i, 4);
            tbl_Filter_TD_1278768_output.setInt64(r, 4, _cs_ext_sales_price1127_t);
            r++;
        }
    }
    tbl_Filter_TD_1278768_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1278768_output #Row: " << tbl_Filter_TD_1278768_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11196108(Table &tbl_SerializeFromObject_TD_12141446_input, Table &tbl_Filter_TD_11196108_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#4692) AND (d_year#4692 = 2001)) AND isnotnull(d_date_sk#4686)))
    // Input: ListBuffer(d_date_sk#4686, d_year#4692)
    // Output: ListBuffer(d_date_sk#4686, d_year#4692)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12141446_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year4692 = tbl_SerializeFromObject_TD_12141446_input.getInt32(i, 1);
        int32_t _d_date_sk4686 = tbl_SerializeFromObject_TD_12141446_input.getInt32(i, 0);
        if (((_d_year4692!= 0) && (_d_year4692 == 2001)) && (_d_date_sk4686!= 0)) {
            int32_t _d_date_sk4686_t = tbl_SerializeFromObject_TD_12141446_input.getInt32(i, 0);
            tbl_Filter_TD_11196108_output.setInt32(r, 0, _d_date_sk4686_t);
            int32_t _d_year4692_t = tbl_SerializeFromObject_TD_12141446_input.getInt32(i, 1);
            tbl_Filter_TD_11196108_output.setInt32(r, 1, _d_year4692_t);
            r++;
        }
    }
    tbl_Filter_TD_11196108_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11196108_output #Row: " << tbl_Filter_TD_11196108_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_11243517_key_leftMajor {
    int32_t _ws_item_sk4633;
    bool operator==(const SW_JOIN_INNER_TD_11243517_key_leftMajor& other) const {
        return ((_ws_item_sk4633 == other._ws_item_sk4633));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11243517_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11243517_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_item_sk4633));
    }
};
}
struct SW_JOIN_INNER_TD_11243517_payload_leftMajor {
    int32_t _ws_sold_date_sk4630;
    int32_t _ws_item_sk4633;
    int64_t _ws_order_number4647L;
    int32_t _ws_quantity4648;
    int64_t _ws_ext_sales_price4653;
};
struct SW_JOIN_INNER_TD_11243517_key_rightMajor {
    int32_t _i_item_sk4664;
    bool operator==(const SW_JOIN_INNER_TD_11243517_key_rightMajor& other) const {
        return ((_i_item_sk4664 == other._i_item_sk4664));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11243517_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11243517_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk4664));
    }
};
}
struct SW_JOIN_INNER_TD_11243517_payload_rightMajor {
    int32_t _i_item_sk4664;
    int32_t _i_brand_id4671;
    int32_t _i_class_id4673;
    int32_t _i_category_id4675;
    int32_t _i_manufact_id4677;
};
void SW_JOIN_INNER_TD_11243517(Table &tbl_Filter_TD_12741275_output, Table &tbl_Filter_TD_12881251_output, Table &tbl_JOIN_INNER_TD_11243517_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((i_item_sk#4664 = ws_item_sk#4633))
    // Left Table: ListBuffer(ws_sold_date_sk#4630, ws_item_sk#4633, ws_order_number#4647L, ws_quantity#4648, ws_ext_sales_price#4653)
    // Right Table: ListBuffer(i_item_sk#4664, i_brand_id#4671, i_class_id#4673, i_category_id#4675, i_manufact_id#4677)
    // Output Table: ListBuffer(ws_sold_date_sk#4630, ws_item_sk#4633, ws_order_number#4647L, ws_quantity#4648, ws_ext_sales_price#4653, i_brand_id#4671, i_class_id#4673, i_category_id#4675, i_manufact_id#4677)
    int left_nrow = tbl_Filter_TD_12741275_output.getNumRow();
    int right_nrow = tbl_Filter_TD_12881251_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11243517_key_leftMajor, SW_JOIN_INNER_TD_11243517_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_12741275_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_item_sk4633_k = tbl_Filter_TD_12741275_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_11243517_key_leftMajor keyA{_ws_item_sk4633_k};
            int32_t _ws_sold_date_sk4630 = tbl_Filter_TD_12741275_output.getInt32(i, 0);
            int32_t _ws_item_sk4633 = tbl_Filter_TD_12741275_output.getInt32(i, 1);
            int64_t _ws_order_number4647L = tbl_Filter_TD_12741275_output.getInt64(i, 2);
            int32_t _ws_quantity4648 = tbl_Filter_TD_12741275_output.getInt32(i, 3);
            int64_t _ws_ext_sales_price4653 = tbl_Filter_TD_12741275_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_11243517_payload_leftMajor payloadA{_ws_sold_date_sk4630, _ws_item_sk4633, _ws_order_number4647L, _ws_quantity4648, _ws_ext_sales_price4653};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_12881251_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk4664_k = tbl_Filter_TD_12881251_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11243517_key_leftMajor{_i_item_sk4664_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_date_sk4630 = (it->second)._ws_sold_date_sk4630;
                int32_t _ws_item_sk4633 = (it->second)._ws_item_sk4633;
                int64_t _ws_order_number4647L = (it->second)._ws_order_number4647L;
                int32_t _ws_quantity4648 = (it->second)._ws_quantity4648;
                int64_t _ws_ext_sales_price4653 = (it->second)._ws_ext_sales_price4653;
                int32_t _i_item_sk4664 = tbl_Filter_TD_12881251_output.getInt32(i, 0);
                int32_t _i_brand_id4671 = tbl_Filter_TD_12881251_output.getInt32(i, 1);
                int32_t _i_class_id4673 = tbl_Filter_TD_12881251_output.getInt32(i, 2);
                int32_t _i_category_id4675 = tbl_Filter_TD_12881251_output.getInt32(i, 3);
                int32_t _i_manufact_id4677 = tbl_Filter_TD_12881251_output.getInt32(i, 4);
                tbl_JOIN_INNER_TD_11243517_output.setInt32(r, 0, _ws_sold_date_sk4630);
                tbl_JOIN_INNER_TD_11243517_output.setInt32(r, 1, _ws_item_sk4633);
                tbl_JOIN_INNER_TD_11243517_output.setInt64(r, 2, _ws_order_number4647L);
                tbl_JOIN_INNER_TD_11243517_output.setInt32(r, 3, _ws_quantity4648);
                tbl_JOIN_INNER_TD_11243517_output.setInt64(r, 4, _ws_ext_sales_price4653);
                tbl_JOIN_INNER_TD_11243517_output.setInt32(r, 5, _i_brand_id4671);
                tbl_JOIN_INNER_TD_11243517_output.setInt32(r, 6, _i_class_id4673);
                tbl_JOIN_INNER_TD_11243517_output.setInt32(r, 7, _i_category_id4675);
                tbl_JOIN_INNER_TD_11243517_output.setInt32(r, 8, _i_manufact_id4677);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11243517_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11243517_key_rightMajor, SW_JOIN_INNER_TD_11243517_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_12881251_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk4664_k = tbl_Filter_TD_12881251_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_11243517_key_rightMajor keyA{_i_item_sk4664_k};
            int32_t _i_item_sk4664 = tbl_Filter_TD_12881251_output.getInt32(i, 0);
            int32_t _i_brand_id4671 = tbl_Filter_TD_12881251_output.getInt32(i, 1);
            int32_t _i_class_id4673 = tbl_Filter_TD_12881251_output.getInt32(i, 2);
            int32_t _i_category_id4675 = tbl_Filter_TD_12881251_output.getInt32(i, 3);
            int32_t _i_manufact_id4677 = tbl_Filter_TD_12881251_output.getInt32(i, 4);
            SW_JOIN_INNER_TD_11243517_payload_rightMajor payloadA{_i_item_sk4664, _i_brand_id4671, _i_class_id4673, _i_category_id4675, _i_manufact_id4677};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_12741275_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_item_sk4633_k = tbl_Filter_TD_12741275_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11243517_key_rightMajor{_ws_item_sk4633_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk4664 = (it->second)._i_item_sk4664;
                int32_t _i_brand_id4671 = (it->second)._i_brand_id4671;
                int32_t _i_class_id4673 = (it->second)._i_class_id4673;
                int32_t _i_category_id4675 = (it->second)._i_category_id4675;
                int32_t _i_manufact_id4677 = (it->second)._i_manufact_id4677;
                int32_t _ws_sold_date_sk4630 = tbl_Filter_TD_12741275_output.getInt32(i, 0);
                int32_t _ws_item_sk4633 = tbl_Filter_TD_12741275_output.getInt32(i, 1);
                int64_t _ws_order_number4647L = tbl_Filter_TD_12741275_output.getInt64(i, 2);
                int32_t _ws_quantity4648 = tbl_Filter_TD_12741275_output.getInt32(i, 3);
                int64_t _ws_ext_sales_price4653 = tbl_Filter_TD_12741275_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_11243517_output.setInt32(r, 5, _i_brand_id4671);
                tbl_JOIN_INNER_TD_11243517_output.setInt32(r, 6, _i_class_id4673);
                tbl_JOIN_INNER_TD_11243517_output.setInt32(r, 7, _i_category_id4675);
                tbl_JOIN_INNER_TD_11243517_output.setInt32(r, 8, _i_manufact_id4677);
                tbl_JOIN_INNER_TD_11243517_output.setInt32(r, 0, _ws_sold_date_sk4630);
                tbl_JOIN_INNER_TD_11243517_output.setInt32(r, 1, _ws_item_sk4633);
                tbl_JOIN_INNER_TD_11243517_output.setInt64(r, 2, _ws_order_number4647L);
                tbl_JOIN_INNER_TD_11243517_output.setInt32(r, 3, _ws_quantity4648);
                tbl_JOIN_INNER_TD_11243517_output.setInt64(r, 4, _ws_ext_sales_price4653);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11243517_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_11243517_output #Row: " << tbl_JOIN_INNER_TD_11243517_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11485295(Table &tbl_SerializeFromObject_TD_12935935_input, Table &tbl_Filter_TD_11485295_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#4588) AND (d_year#4588 = 2001)) AND isnotnull(d_date_sk#4582)))
    // Input: ListBuffer(d_date_sk#4582, d_year#4588)
    // Output: ListBuffer(d_date_sk#4582, d_year#4588)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12935935_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year4588 = tbl_SerializeFromObject_TD_12935935_input.getInt32(i, 1);
        int32_t _d_date_sk4582 = tbl_SerializeFromObject_TD_12935935_input.getInt32(i, 0);
        if (((_d_year4588!= 0) && (_d_year4588 == 2001)) && (_d_date_sk4582!= 0)) {
            int32_t _d_date_sk4582_t = tbl_SerializeFromObject_TD_12935935_input.getInt32(i, 0);
            tbl_Filter_TD_11485295_output.setInt32(r, 0, _d_date_sk4582_t);
            int32_t _d_year4588_t = tbl_SerializeFromObject_TD_12935935_input.getInt32(i, 1);
            tbl_Filter_TD_11485295_output.setInt32(r, 1, _d_year4588_t);
            r++;
        }
    }
    tbl_Filter_TD_11485295_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11485295_output #Row: " << tbl_Filter_TD_11485295_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_11321498_key_leftMajor {
    int32_t _ss_item_sk4539;
    bool operator==(const SW_JOIN_INNER_TD_11321498_key_leftMajor& other) const {
        return ((_ss_item_sk4539 == other._ss_item_sk4539));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11321498_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11321498_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk4539));
    }
};
}
struct SW_JOIN_INNER_TD_11321498_payload_leftMajor {
    int32_t _ss_sold_date_sk4537;
    int32_t _ss_item_sk4539;
    int64_t _ss_ticket_number4546L;
    int32_t _ss_quantity4547;
    int64_t _ss_ext_sales_price4552;
};
struct SW_JOIN_INNER_TD_11321498_key_rightMajor {
    int32_t _i_item_sk4560;
    bool operator==(const SW_JOIN_INNER_TD_11321498_key_rightMajor& other) const {
        return ((_i_item_sk4560 == other._i_item_sk4560));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11321498_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11321498_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk4560));
    }
};
}
struct SW_JOIN_INNER_TD_11321498_payload_rightMajor {
    int32_t _i_item_sk4560;
    int32_t _i_brand_id4567;
    int32_t _i_class_id4569;
    int32_t _i_category_id4571;
    int32_t _i_manufact_id4573;
};
void SW_JOIN_INNER_TD_11321498(Table &tbl_Filter_TD_12349655_output, Table &tbl_Filter_TD_12246209_output, Table &tbl_JOIN_INNER_TD_11321498_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((i_item_sk#4560 = ss_item_sk#4539))
    // Left Table: ListBuffer(ss_sold_date_sk#4537, ss_item_sk#4539, ss_ticket_number#4546L, ss_quantity#4547, ss_ext_sales_price#4552)
    // Right Table: ListBuffer(i_item_sk#4560, i_brand_id#4567, i_class_id#4569, i_category_id#4571, i_manufact_id#4573)
    // Output Table: ListBuffer(ss_sold_date_sk#4537, ss_item_sk#4539, ss_ticket_number#4546L, ss_quantity#4547, ss_ext_sales_price#4552, i_brand_id#4567, i_class_id#4569, i_category_id#4571, i_manufact_id#4573)
    int left_nrow = tbl_Filter_TD_12349655_output.getNumRow();
    int right_nrow = tbl_Filter_TD_12246209_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11321498_key_leftMajor, SW_JOIN_INNER_TD_11321498_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_12349655_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk4539_k = tbl_Filter_TD_12349655_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_11321498_key_leftMajor keyA{_ss_item_sk4539_k};
            int32_t _ss_sold_date_sk4537 = tbl_Filter_TD_12349655_output.getInt32(i, 0);
            int32_t _ss_item_sk4539 = tbl_Filter_TD_12349655_output.getInt32(i, 1);
            int64_t _ss_ticket_number4546L = tbl_Filter_TD_12349655_output.getInt64(i, 2);
            int32_t _ss_quantity4547 = tbl_Filter_TD_12349655_output.getInt32(i, 3);
            int64_t _ss_ext_sales_price4552 = tbl_Filter_TD_12349655_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_11321498_payload_leftMajor payloadA{_ss_sold_date_sk4537, _ss_item_sk4539, _ss_ticket_number4546L, _ss_quantity4547, _ss_ext_sales_price4552};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_12246209_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk4560_k = tbl_Filter_TD_12246209_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11321498_key_leftMajor{_i_item_sk4560_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk4537 = (it->second)._ss_sold_date_sk4537;
                int32_t _ss_item_sk4539 = (it->second)._ss_item_sk4539;
                int64_t _ss_ticket_number4546L = (it->second)._ss_ticket_number4546L;
                int32_t _ss_quantity4547 = (it->second)._ss_quantity4547;
                int64_t _ss_ext_sales_price4552 = (it->second)._ss_ext_sales_price4552;
                int32_t _i_item_sk4560 = tbl_Filter_TD_12246209_output.getInt32(i, 0);
                int32_t _i_brand_id4567 = tbl_Filter_TD_12246209_output.getInt32(i, 1);
                int32_t _i_class_id4569 = tbl_Filter_TD_12246209_output.getInt32(i, 2);
                int32_t _i_category_id4571 = tbl_Filter_TD_12246209_output.getInt32(i, 3);
                int32_t _i_manufact_id4573 = tbl_Filter_TD_12246209_output.getInt32(i, 4);
                tbl_JOIN_INNER_TD_11321498_output.setInt32(r, 0, _ss_sold_date_sk4537);
                tbl_JOIN_INNER_TD_11321498_output.setInt32(r, 1, _ss_item_sk4539);
                tbl_JOIN_INNER_TD_11321498_output.setInt64(r, 2, _ss_ticket_number4546L);
                tbl_JOIN_INNER_TD_11321498_output.setInt32(r, 3, _ss_quantity4547);
                tbl_JOIN_INNER_TD_11321498_output.setInt64(r, 4, _ss_ext_sales_price4552);
                tbl_JOIN_INNER_TD_11321498_output.setInt32(r, 5, _i_brand_id4567);
                tbl_JOIN_INNER_TD_11321498_output.setInt32(r, 6, _i_class_id4569);
                tbl_JOIN_INNER_TD_11321498_output.setInt32(r, 7, _i_category_id4571);
                tbl_JOIN_INNER_TD_11321498_output.setInt32(r, 8, _i_manufact_id4573);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11321498_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11321498_key_rightMajor, SW_JOIN_INNER_TD_11321498_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_12246209_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk4560_k = tbl_Filter_TD_12246209_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_11321498_key_rightMajor keyA{_i_item_sk4560_k};
            int32_t _i_item_sk4560 = tbl_Filter_TD_12246209_output.getInt32(i, 0);
            int32_t _i_brand_id4567 = tbl_Filter_TD_12246209_output.getInt32(i, 1);
            int32_t _i_class_id4569 = tbl_Filter_TD_12246209_output.getInt32(i, 2);
            int32_t _i_category_id4571 = tbl_Filter_TD_12246209_output.getInt32(i, 3);
            int32_t _i_manufact_id4573 = tbl_Filter_TD_12246209_output.getInt32(i, 4);
            SW_JOIN_INNER_TD_11321498_payload_rightMajor payloadA{_i_item_sk4560, _i_brand_id4567, _i_class_id4569, _i_category_id4571, _i_manufact_id4573};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_12349655_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk4539_k = tbl_Filter_TD_12349655_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11321498_key_rightMajor{_ss_item_sk4539_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk4560 = (it->second)._i_item_sk4560;
                int32_t _i_brand_id4567 = (it->second)._i_brand_id4567;
                int32_t _i_class_id4569 = (it->second)._i_class_id4569;
                int32_t _i_category_id4571 = (it->second)._i_category_id4571;
                int32_t _i_manufact_id4573 = (it->second)._i_manufact_id4573;
                int32_t _ss_sold_date_sk4537 = tbl_Filter_TD_12349655_output.getInt32(i, 0);
                int32_t _ss_item_sk4539 = tbl_Filter_TD_12349655_output.getInt32(i, 1);
                int64_t _ss_ticket_number4546L = tbl_Filter_TD_12349655_output.getInt64(i, 2);
                int32_t _ss_quantity4547 = tbl_Filter_TD_12349655_output.getInt32(i, 3);
                int64_t _ss_ext_sales_price4552 = tbl_Filter_TD_12349655_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_11321498_output.setInt32(r, 5, _i_brand_id4567);
                tbl_JOIN_INNER_TD_11321498_output.setInt32(r, 6, _i_class_id4569);
                tbl_JOIN_INNER_TD_11321498_output.setInt32(r, 7, _i_category_id4571);
                tbl_JOIN_INNER_TD_11321498_output.setInt32(r, 8, _i_manufact_id4573);
                tbl_JOIN_INNER_TD_11321498_output.setInt32(r, 0, _ss_sold_date_sk4537);
                tbl_JOIN_INNER_TD_11321498_output.setInt32(r, 1, _ss_item_sk4539);
                tbl_JOIN_INNER_TD_11321498_output.setInt64(r, 2, _ss_ticket_number4546L);
                tbl_JOIN_INNER_TD_11321498_output.setInt32(r, 3, _ss_quantity4547);
                tbl_JOIN_INNER_TD_11321498_output.setInt64(r, 4, _ss_ext_sales_price4552);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11321498_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_11321498_output #Row: " << tbl_JOIN_INNER_TD_11321498_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11546642(Table &tbl_SerializeFromObject_TD_12876421_input, Table &tbl_Filter_TD_11546642_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#4488) AND (d_year#4488 = 2001)) AND isnotnull(d_date_sk#4482)))
    // Input: ListBuffer(d_date_sk#4482, d_year#4488)
    // Output: ListBuffer(d_date_sk#4482, d_year#4488)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12876421_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year4488 = tbl_SerializeFromObject_TD_12876421_input.getInt32(i, 1);
        int32_t _d_date_sk4482 = tbl_SerializeFromObject_TD_12876421_input.getInt32(i, 0);
        if (((_d_year4488!= 0) && (_d_year4488 == 2001)) && (_d_date_sk4482!= 0)) {
            int32_t _d_date_sk4482_t = tbl_SerializeFromObject_TD_12876421_input.getInt32(i, 0);
            tbl_Filter_TD_11546642_output.setInt32(r, 0, _d_date_sk4482_t);
            int32_t _d_year4488_t = tbl_SerializeFromObject_TD_12876421_input.getInt32(i, 1);
            tbl_Filter_TD_11546642_output.setInt32(r, 1, _d_year4488_t);
            r++;
        }
    }
    tbl_Filter_TD_11546642_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11546642_output #Row: " << tbl_Filter_TD_11546642_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_11469408_key_leftMajor {
    int32_t _cs_item_sk4441;
    bool operator==(const SW_JOIN_INNER_TD_11469408_key_leftMajor& other) const {
        return ((_cs_item_sk4441 == other._cs_item_sk4441));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11469408_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11469408_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_item_sk4441));
    }
};
}
struct SW_JOIN_INNER_TD_11469408_payload_leftMajor {
    int32_t _cs_sold_date_sk4426;
    int32_t _cs_item_sk4441;
    int64_t _cs_order_number4443L;
    int32_t _cs_quantity4444;
    int64_t _cs_ext_sales_price4449;
};
struct SW_JOIN_INNER_TD_11469408_key_rightMajor {
    int32_t _i_item_sk4460;
    bool operator==(const SW_JOIN_INNER_TD_11469408_key_rightMajor& other) const {
        return ((_i_item_sk4460 == other._i_item_sk4460));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11469408_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11469408_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk4460));
    }
};
}
struct SW_JOIN_INNER_TD_11469408_payload_rightMajor {
    int32_t _i_item_sk4460;
    int32_t _i_brand_id4467;
    int32_t _i_class_id4469;
    int32_t _i_category_id4471;
    int32_t _i_manufact_id4473;
};
void SW_JOIN_INNER_TD_11469408(Table &tbl_Filter_TD_12968394_output, Table &tbl_Filter_TD_1270854_output, Table &tbl_JOIN_INNER_TD_11469408_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((i_item_sk#4460 = cs_item_sk#4441))
    // Left Table: ListBuffer(cs_sold_date_sk#4426, cs_item_sk#4441, cs_order_number#4443L, cs_quantity#4444, cs_ext_sales_price#4449)
    // Right Table: ListBuffer(i_item_sk#4460, i_brand_id#4467, i_class_id#4469, i_category_id#4471, i_manufact_id#4473)
    // Output Table: ListBuffer(cs_sold_date_sk#4426, cs_item_sk#4441, cs_order_number#4443L, cs_quantity#4444, cs_ext_sales_price#4449, i_brand_id#4467, i_class_id#4469, i_category_id#4471, i_manufact_id#4473)
    int left_nrow = tbl_Filter_TD_12968394_output.getNumRow();
    int right_nrow = tbl_Filter_TD_1270854_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11469408_key_leftMajor, SW_JOIN_INNER_TD_11469408_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_12968394_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_item_sk4441_k = tbl_Filter_TD_12968394_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_11469408_key_leftMajor keyA{_cs_item_sk4441_k};
            int32_t _cs_sold_date_sk4426 = tbl_Filter_TD_12968394_output.getInt32(i, 0);
            int32_t _cs_item_sk4441 = tbl_Filter_TD_12968394_output.getInt32(i, 1);
            int64_t _cs_order_number4443L = tbl_Filter_TD_12968394_output.getInt64(i, 2);
            int32_t _cs_quantity4444 = tbl_Filter_TD_12968394_output.getInt32(i, 3);
            int64_t _cs_ext_sales_price4449 = tbl_Filter_TD_12968394_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_11469408_payload_leftMajor payloadA{_cs_sold_date_sk4426, _cs_item_sk4441, _cs_order_number4443L, _cs_quantity4444, _cs_ext_sales_price4449};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_1270854_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk4460_k = tbl_Filter_TD_1270854_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11469408_key_leftMajor{_i_item_sk4460_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk4426 = (it->second)._cs_sold_date_sk4426;
                int32_t _cs_item_sk4441 = (it->second)._cs_item_sk4441;
                int64_t _cs_order_number4443L = (it->second)._cs_order_number4443L;
                int32_t _cs_quantity4444 = (it->second)._cs_quantity4444;
                int64_t _cs_ext_sales_price4449 = (it->second)._cs_ext_sales_price4449;
                int32_t _i_item_sk4460 = tbl_Filter_TD_1270854_output.getInt32(i, 0);
                int32_t _i_brand_id4467 = tbl_Filter_TD_1270854_output.getInt32(i, 1);
                int32_t _i_class_id4469 = tbl_Filter_TD_1270854_output.getInt32(i, 2);
                int32_t _i_category_id4471 = tbl_Filter_TD_1270854_output.getInt32(i, 3);
                int32_t _i_manufact_id4473 = tbl_Filter_TD_1270854_output.getInt32(i, 4);
                tbl_JOIN_INNER_TD_11469408_output.setInt32(r, 0, _cs_sold_date_sk4426);
                tbl_JOIN_INNER_TD_11469408_output.setInt32(r, 1, _cs_item_sk4441);
                tbl_JOIN_INNER_TD_11469408_output.setInt64(r, 2, _cs_order_number4443L);
                tbl_JOIN_INNER_TD_11469408_output.setInt32(r, 3, _cs_quantity4444);
                tbl_JOIN_INNER_TD_11469408_output.setInt64(r, 4, _cs_ext_sales_price4449);
                tbl_JOIN_INNER_TD_11469408_output.setInt32(r, 5, _i_brand_id4467);
                tbl_JOIN_INNER_TD_11469408_output.setInt32(r, 6, _i_class_id4469);
                tbl_JOIN_INNER_TD_11469408_output.setInt32(r, 7, _i_category_id4471);
                tbl_JOIN_INNER_TD_11469408_output.setInt32(r, 8, _i_manufact_id4473);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11469408_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11469408_key_rightMajor, SW_JOIN_INNER_TD_11469408_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_1270854_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk4460_k = tbl_Filter_TD_1270854_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_11469408_key_rightMajor keyA{_i_item_sk4460_k};
            int32_t _i_item_sk4460 = tbl_Filter_TD_1270854_output.getInt32(i, 0);
            int32_t _i_brand_id4467 = tbl_Filter_TD_1270854_output.getInt32(i, 1);
            int32_t _i_class_id4469 = tbl_Filter_TD_1270854_output.getInt32(i, 2);
            int32_t _i_category_id4471 = tbl_Filter_TD_1270854_output.getInt32(i, 3);
            int32_t _i_manufact_id4473 = tbl_Filter_TD_1270854_output.getInt32(i, 4);
            SW_JOIN_INNER_TD_11469408_payload_rightMajor payloadA{_i_item_sk4460, _i_brand_id4467, _i_class_id4469, _i_category_id4471, _i_manufact_id4473};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_12968394_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_item_sk4441_k = tbl_Filter_TD_12968394_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11469408_key_rightMajor{_cs_item_sk4441_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk4460 = (it->second)._i_item_sk4460;
                int32_t _i_brand_id4467 = (it->second)._i_brand_id4467;
                int32_t _i_class_id4469 = (it->second)._i_class_id4469;
                int32_t _i_category_id4471 = (it->second)._i_category_id4471;
                int32_t _i_manufact_id4473 = (it->second)._i_manufact_id4473;
                int32_t _cs_sold_date_sk4426 = tbl_Filter_TD_12968394_output.getInt32(i, 0);
                int32_t _cs_item_sk4441 = tbl_Filter_TD_12968394_output.getInt32(i, 1);
                int64_t _cs_order_number4443L = tbl_Filter_TD_12968394_output.getInt64(i, 2);
                int32_t _cs_quantity4444 = tbl_Filter_TD_12968394_output.getInt32(i, 3);
                int64_t _cs_ext_sales_price4449 = tbl_Filter_TD_12968394_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_11469408_output.setInt32(r, 5, _i_brand_id4467);
                tbl_JOIN_INNER_TD_11469408_output.setInt32(r, 6, _i_class_id4469);
                tbl_JOIN_INNER_TD_11469408_output.setInt32(r, 7, _i_category_id4471);
                tbl_JOIN_INNER_TD_11469408_output.setInt32(r, 8, _i_manufact_id4473);
                tbl_JOIN_INNER_TD_11469408_output.setInt32(r, 0, _cs_sold_date_sk4426);
                tbl_JOIN_INNER_TD_11469408_output.setInt32(r, 1, _cs_item_sk4441);
                tbl_JOIN_INNER_TD_11469408_output.setInt64(r, 2, _cs_order_number4443L);
                tbl_JOIN_INNER_TD_11469408_output.setInt32(r, 3, _cs_quantity4444);
                tbl_JOIN_INNER_TD_11469408_output.setInt64(r, 4, _cs_ext_sales_price4449);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11469408_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_11469408_output #Row: " << tbl_JOIN_INNER_TD_11469408_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11291823(Table &tbl_SerializeFromObject_TD_12818793_input, Table &tbl_Filter_TD_11291823_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3636) AND (d_year#3636 = 2002)) AND isnotnull(d_date_sk#3630)))
    // Input: ListBuffer(d_date_sk#3630, d_year#3636)
    // Output: ListBuffer(d_date_sk#3630, d_year#3636)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12818793_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3636 = tbl_SerializeFromObject_TD_12818793_input.getInt32(i, 1);
        int32_t _d_date_sk3630 = tbl_SerializeFromObject_TD_12818793_input.getInt32(i, 0);
        if (((_d_year3636!= 0) && (_d_year3636 == 2002)) && (_d_date_sk3630!= 0)) {
            int32_t _d_date_sk3630_t = tbl_SerializeFromObject_TD_12818793_input.getInt32(i, 0);
            tbl_Filter_TD_11291823_output.setInt32(r, 0, _d_date_sk3630_t);
            int32_t _d_year3636_t = tbl_SerializeFromObject_TD_12818793_input.getInt32(i, 1);
            tbl_Filter_TD_11291823_output.setInt32(r, 1, _d_year3636_t);
            r++;
        }
    }
    tbl_Filter_TD_11291823_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11291823_output #Row: " << tbl_Filter_TD_11291823_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_11650737_key_leftMajor {
    int32_t _ws_item_sk732;
    bool operator==(const SW_JOIN_INNER_TD_11650737_key_leftMajor& other) const {
        return ((_ws_item_sk732 == other._ws_item_sk732));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11650737_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11650737_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_item_sk732));
    }
};
}
struct SW_JOIN_INNER_TD_11650737_payload_leftMajor {
    int32_t _ws_sold_date_sk729;
    int32_t _ws_item_sk732;
    int64_t _ws_order_number746L;
    int32_t _ws_quantity747;
    int64_t _ws_ext_sales_price752;
};
struct SW_JOIN_INNER_TD_11650737_key_rightMajor {
    int32_t _i_item_sk3608;
    bool operator==(const SW_JOIN_INNER_TD_11650737_key_rightMajor& other) const {
        return ((_i_item_sk3608 == other._i_item_sk3608));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11650737_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11650737_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk3608));
    }
};
}
struct SW_JOIN_INNER_TD_11650737_payload_rightMajor {
    int32_t _i_item_sk3608;
    int32_t _i_brand_id3615;
    int32_t _i_class_id3617;
    int32_t _i_category_id3619;
    int32_t _i_manufact_id3621;
};
void SW_JOIN_INNER_TD_11650737(Table &tbl_Filter_TD_12460154_output, Table &tbl_Filter_TD_12301909_output, Table &tbl_JOIN_INNER_TD_11650737_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((i_item_sk#3608 = ws_item_sk#732))
    // Left Table: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_order_number#746L, ws_quantity#747, ws_ext_sales_price#752)
    // Right Table: ListBuffer(i_item_sk#3608, i_brand_id#3615, i_class_id#3617, i_category_id#3619, i_manufact_id#3621)
    // Output Table: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_order_number#746L, ws_quantity#747, ws_ext_sales_price#752, i_brand_id#3615, i_class_id#3617, i_category_id#3619, i_manufact_id#3621)
    int left_nrow = tbl_Filter_TD_12460154_output.getNumRow();
    int right_nrow = tbl_Filter_TD_12301909_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11650737_key_leftMajor, SW_JOIN_INNER_TD_11650737_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_12460154_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_item_sk732_k = tbl_Filter_TD_12460154_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_11650737_key_leftMajor keyA{_ws_item_sk732_k};
            int32_t _ws_sold_date_sk729 = tbl_Filter_TD_12460154_output.getInt32(i, 0);
            int32_t _ws_item_sk732 = tbl_Filter_TD_12460154_output.getInt32(i, 1);
            int64_t _ws_order_number746L = tbl_Filter_TD_12460154_output.getInt64(i, 2);
            int32_t _ws_quantity747 = tbl_Filter_TD_12460154_output.getInt32(i, 3);
            int64_t _ws_ext_sales_price752 = tbl_Filter_TD_12460154_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_11650737_payload_leftMajor payloadA{_ws_sold_date_sk729, _ws_item_sk732, _ws_order_number746L, _ws_quantity747, _ws_ext_sales_price752};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_12301909_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk3608_k = tbl_Filter_TD_12301909_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11650737_key_leftMajor{_i_item_sk3608_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_date_sk729 = (it->second)._ws_sold_date_sk729;
                int32_t _ws_item_sk732 = (it->second)._ws_item_sk732;
                int64_t _ws_order_number746L = (it->second)._ws_order_number746L;
                int32_t _ws_quantity747 = (it->second)._ws_quantity747;
                int64_t _ws_ext_sales_price752 = (it->second)._ws_ext_sales_price752;
                int32_t _i_item_sk3608 = tbl_Filter_TD_12301909_output.getInt32(i, 0);
                int32_t _i_brand_id3615 = tbl_Filter_TD_12301909_output.getInt32(i, 1);
                int32_t _i_class_id3617 = tbl_Filter_TD_12301909_output.getInt32(i, 2);
                int32_t _i_category_id3619 = tbl_Filter_TD_12301909_output.getInt32(i, 3);
                int32_t _i_manufact_id3621 = tbl_Filter_TD_12301909_output.getInt32(i, 4);
                tbl_JOIN_INNER_TD_11650737_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_11650737_output.setInt32(r, 1, _ws_item_sk732);
                tbl_JOIN_INNER_TD_11650737_output.setInt64(r, 2, _ws_order_number746L);
                tbl_JOIN_INNER_TD_11650737_output.setInt32(r, 3, _ws_quantity747);
                tbl_JOIN_INNER_TD_11650737_output.setInt64(r, 4, _ws_ext_sales_price752);
                tbl_JOIN_INNER_TD_11650737_output.setInt32(r, 5, _i_brand_id3615);
                tbl_JOIN_INNER_TD_11650737_output.setInt32(r, 6, _i_class_id3617);
                tbl_JOIN_INNER_TD_11650737_output.setInt32(r, 7, _i_category_id3619);
                tbl_JOIN_INNER_TD_11650737_output.setInt32(r, 8, _i_manufact_id3621);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11650737_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11650737_key_rightMajor, SW_JOIN_INNER_TD_11650737_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_12301909_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk3608_k = tbl_Filter_TD_12301909_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_11650737_key_rightMajor keyA{_i_item_sk3608_k};
            int32_t _i_item_sk3608 = tbl_Filter_TD_12301909_output.getInt32(i, 0);
            int32_t _i_brand_id3615 = tbl_Filter_TD_12301909_output.getInt32(i, 1);
            int32_t _i_class_id3617 = tbl_Filter_TD_12301909_output.getInt32(i, 2);
            int32_t _i_category_id3619 = tbl_Filter_TD_12301909_output.getInt32(i, 3);
            int32_t _i_manufact_id3621 = tbl_Filter_TD_12301909_output.getInt32(i, 4);
            SW_JOIN_INNER_TD_11650737_payload_rightMajor payloadA{_i_item_sk3608, _i_brand_id3615, _i_class_id3617, _i_category_id3619, _i_manufact_id3621};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_12460154_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_item_sk732_k = tbl_Filter_TD_12460154_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11650737_key_rightMajor{_ws_item_sk732_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk3608 = (it->second)._i_item_sk3608;
                int32_t _i_brand_id3615 = (it->second)._i_brand_id3615;
                int32_t _i_class_id3617 = (it->second)._i_class_id3617;
                int32_t _i_category_id3619 = (it->second)._i_category_id3619;
                int32_t _i_manufact_id3621 = (it->second)._i_manufact_id3621;
                int32_t _ws_sold_date_sk729 = tbl_Filter_TD_12460154_output.getInt32(i, 0);
                int32_t _ws_item_sk732 = tbl_Filter_TD_12460154_output.getInt32(i, 1);
                int64_t _ws_order_number746L = tbl_Filter_TD_12460154_output.getInt64(i, 2);
                int32_t _ws_quantity747 = tbl_Filter_TD_12460154_output.getInt32(i, 3);
                int64_t _ws_ext_sales_price752 = tbl_Filter_TD_12460154_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_11650737_output.setInt32(r, 5, _i_brand_id3615);
                tbl_JOIN_INNER_TD_11650737_output.setInt32(r, 6, _i_class_id3617);
                tbl_JOIN_INNER_TD_11650737_output.setInt32(r, 7, _i_category_id3619);
                tbl_JOIN_INNER_TD_11650737_output.setInt32(r, 8, _i_manufact_id3621);
                tbl_JOIN_INNER_TD_11650737_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_11650737_output.setInt32(r, 1, _ws_item_sk732);
                tbl_JOIN_INNER_TD_11650737_output.setInt64(r, 2, _ws_order_number746L);
                tbl_JOIN_INNER_TD_11650737_output.setInt32(r, 3, _ws_quantity747);
                tbl_JOIN_INNER_TD_11650737_output.setInt64(r, 4, _ws_ext_sales_price752);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11650737_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_11650737_output #Row: " << tbl_JOIN_INNER_TD_11650737_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11126261(Table &tbl_SerializeFromObject_TD_12757823_input, Table &tbl_Filter_TD_11126261_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3586) AND (d_year#3586 = 2002)) AND isnotnull(d_date_sk#3580)))
    // Input: ListBuffer(d_date_sk#3580, d_year#3586)
    // Output: ListBuffer(d_date_sk#3580, d_year#3586)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12757823_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3586 = tbl_SerializeFromObject_TD_12757823_input.getInt32(i, 1);
        int32_t _d_date_sk3580 = tbl_SerializeFromObject_TD_12757823_input.getInt32(i, 0);
        if (((_d_year3586!= 0) && (_d_year3586 == 2002)) && (_d_date_sk3580!= 0)) {
            int32_t _d_date_sk3580_t = tbl_SerializeFromObject_TD_12757823_input.getInt32(i, 0);
            tbl_Filter_TD_11126261_output.setInt32(r, 0, _d_date_sk3580_t);
            int32_t _d_year3586_t = tbl_SerializeFromObject_TD_12757823_input.getInt32(i, 1);
            tbl_Filter_TD_11126261_output.setInt32(r, 1, _d_year3586_t);
            r++;
        }
    }
    tbl_Filter_TD_11126261_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11126261_output #Row: " << tbl_Filter_TD_11126261_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_11868273_key_leftMajor {
    int32_t _ss_item_sk1208;
    bool operator==(const SW_JOIN_INNER_TD_11868273_key_leftMajor& other) const {
        return ((_ss_item_sk1208 == other._ss_item_sk1208));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11868273_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11868273_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk1208));
    }
};
}
struct SW_JOIN_INNER_TD_11868273_payload_leftMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_item_sk1208;
    int64_t _ss_ticket_number1215L;
    int32_t _ss_quantity1216;
    int64_t _ss_ext_sales_price1221;
};
struct SW_JOIN_INNER_TD_11868273_key_rightMajor {
    int32_t _i_item_sk3558;
    bool operator==(const SW_JOIN_INNER_TD_11868273_key_rightMajor& other) const {
        return ((_i_item_sk3558 == other._i_item_sk3558));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11868273_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11868273_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk3558));
    }
};
}
struct SW_JOIN_INNER_TD_11868273_payload_rightMajor {
    int32_t _i_item_sk3558;
    int32_t _i_brand_id3565;
    int32_t _i_class_id3567;
    int32_t _i_category_id3569;
    int32_t _i_manufact_id3571;
};
void SW_JOIN_INNER_TD_11868273(Table &tbl_Filter_TD_12304293_output, Table &tbl_Filter_TD_12968861_output, Table &tbl_JOIN_INNER_TD_11868273_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((i_item_sk#3558 = ss_item_sk#1208))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_ticket_number#1215L, ss_quantity#1216, ss_ext_sales_price#1221)
    // Right Table: ListBuffer(i_item_sk#3558, i_brand_id#3565, i_class_id#3567, i_category_id#3569, i_manufact_id#3571)
    // Output Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_ticket_number#1215L, ss_quantity#1216, ss_ext_sales_price#1221, i_brand_id#3565, i_class_id#3567, i_category_id#3569, i_manufact_id#3571)
    int left_nrow = tbl_Filter_TD_12304293_output.getNumRow();
    int right_nrow = tbl_Filter_TD_12968861_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11868273_key_leftMajor, SW_JOIN_INNER_TD_11868273_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_12304293_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk1208_k = tbl_Filter_TD_12304293_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_11868273_key_leftMajor keyA{_ss_item_sk1208_k};
            int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_12304293_output.getInt32(i, 0);
            int32_t _ss_item_sk1208 = tbl_Filter_TD_12304293_output.getInt32(i, 1);
            int64_t _ss_ticket_number1215L = tbl_Filter_TD_12304293_output.getInt64(i, 2);
            int32_t _ss_quantity1216 = tbl_Filter_TD_12304293_output.getInt32(i, 3);
            int64_t _ss_ext_sales_price1221 = tbl_Filter_TD_12304293_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_11868273_payload_leftMajor payloadA{_ss_sold_date_sk1206, _ss_item_sk1208, _ss_ticket_number1215L, _ss_quantity1216, _ss_ext_sales_price1221};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_12968861_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk3558_k = tbl_Filter_TD_12968861_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11868273_key_leftMajor{_i_item_sk3558_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int64_t _ss_ticket_number1215L = (it->second)._ss_ticket_number1215L;
                int32_t _ss_quantity1216 = (it->second)._ss_quantity1216;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int32_t _i_item_sk3558 = tbl_Filter_TD_12968861_output.getInt32(i, 0);
                int32_t _i_brand_id3565 = tbl_Filter_TD_12968861_output.getInt32(i, 1);
                int32_t _i_class_id3567 = tbl_Filter_TD_12968861_output.getInt32(i, 2);
                int32_t _i_category_id3569 = tbl_Filter_TD_12968861_output.getInt32(i, 3);
                int32_t _i_manufact_id3571 = tbl_Filter_TD_12968861_output.getInt32(i, 4);
                tbl_JOIN_INNER_TD_11868273_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_11868273_output.setInt32(r, 1, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_11868273_output.setInt64(r, 2, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_11868273_output.setInt32(r, 3, _ss_quantity1216);
                tbl_JOIN_INNER_TD_11868273_output.setInt64(r, 4, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_11868273_output.setInt32(r, 5, _i_brand_id3565);
                tbl_JOIN_INNER_TD_11868273_output.setInt32(r, 6, _i_class_id3567);
                tbl_JOIN_INNER_TD_11868273_output.setInt32(r, 7, _i_category_id3569);
                tbl_JOIN_INNER_TD_11868273_output.setInt32(r, 8, _i_manufact_id3571);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11868273_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11868273_key_rightMajor, SW_JOIN_INNER_TD_11868273_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_12968861_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk3558_k = tbl_Filter_TD_12968861_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_11868273_key_rightMajor keyA{_i_item_sk3558_k};
            int32_t _i_item_sk3558 = tbl_Filter_TD_12968861_output.getInt32(i, 0);
            int32_t _i_brand_id3565 = tbl_Filter_TD_12968861_output.getInt32(i, 1);
            int32_t _i_class_id3567 = tbl_Filter_TD_12968861_output.getInt32(i, 2);
            int32_t _i_category_id3569 = tbl_Filter_TD_12968861_output.getInt32(i, 3);
            int32_t _i_manufact_id3571 = tbl_Filter_TD_12968861_output.getInt32(i, 4);
            SW_JOIN_INNER_TD_11868273_payload_rightMajor payloadA{_i_item_sk3558, _i_brand_id3565, _i_class_id3567, _i_category_id3569, _i_manufact_id3571};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_12304293_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk1208_k = tbl_Filter_TD_12304293_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11868273_key_rightMajor{_ss_item_sk1208_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk3558 = (it->second)._i_item_sk3558;
                int32_t _i_brand_id3565 = (it->second)._i_brand_id3565;
                int32_t _i_class_id3567 = (it->second)._i_class_id3567;
                int32_t _i_category_id3569 = (it->second)._i_category_id3569;
                int32_t _i_manufact_id3571 = (it->second)._i_manufact_id3571;
                int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_12304293_output.getInt32(i, 0);
                int32_t _ss_item_sk1208 = tbl_Filter_TD_12304293_output.getInt32(i, 1);
                int64_t _ss_ticket_number1215L = tbl_Filter_TD_12304293_output.getInt64(i, 2);
                int32_t _ss_quantity1216 = tbl_Filter_TD_12304293_output.getInt32(i, 3);
                int64_t _ss_ext_sales_price1221 = tbl_Filter_TD_12304293_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_11868273_output.setInt32(r, 5, _i_brand_id3565);
                tbl_JOIN_INNER_TD_11868273_output.setInt32(r, 6, _i_class_id3567);
                tbl_JOIN_INNER_TD_11868273_output.setInt32(r, 7, _i_category_id3569);
                tbl_JOIN_INNER_TD_11868273_output.setInt32(r, 8, _i_manufact_id3571);
                tbl_JOIN_INNER_TD_11868273_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_11868273_output.setInt32(r, 1, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_11868273_output.setInt64(r, 2, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_11868273_output.setInt32(r, 3, _ss_quantity1216);
                tbl_JOIN_INNER_TD_11868273_output.setInt64(r, 4, _ss_ext_sales_price1221);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11868273_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_11868273_output #Row: " << tbl_JOIN_INNER_TD_11868273_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11781310(Table &tbl_SerializeFromObject_TD_12955447_input, Table &tbl_Filter_TD_11781310_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#126) AND (d_year#126 = 2002)) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126)
    // Output: ListBuffer(d_date_sk#120, d_year#126)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12955447_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_12955447_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_12955447_input.getInt32(i, 0);
        if (((_d_year126!= 0) && (_d_year126 == 2002)) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_12955447_input.getInt32(i, 0);
            tbl_Filter_TD_11781310_output.setInt32(r, 0, _d_date_sk120_t);
            int32_t _d_year126_t = tbl_SerializeFromObject_TD_12955447_input.getInt32(i, 1);
            tbl_Filter_TD_11781310_output.setInt32(r, 1, _d_year126_t);
            r++;
        }
    }
    tbl_Filter_TD_11781310_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11781310_output #Row: " << tbl_Filter_TD_11781310_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_11627645_key_leftMajor {
    int32_t _cs_item_sk1119;
    bool operator==(const SW_JOIN_INNER_TD_11627645_key_leftMajor& other) const {
        return ((_cs_item_sk1119 == other._cs_item_sk1119));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11627645_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11627645_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_item_sk1119));
    }
};
}
struct SW_JOIN_INNER_TD_11627645_payload_leftMajor {
    int32_t _cs_sold_date_sk1104;
    int32_t _cs_item_sk1119;
    int64_t _cs_order_number1121L;
    int32_t _cs_quantity1122;
    int64_t _cs_ext_sales_price1127;
};
struct SW_JOIN_INNER_TD_11627645_key_rightMajor {
    int32_t _i_item_sk228;
    bool operator==(const SW_JOIN_INNER_TD_11627645_key_rightMajor& other) const {
        return ((_i_item_sk228 == other._i_item_sk228));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_11627645_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_11627645_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk228));
    }
};
}
struct SW_JOIN_INNER_TD_11627645_payload_rightMajor {
    int32_t _i_item_sk228;
    int32_t _i_brand_id235;
    int32_t _i_class_id237;
    int32_t _i_category_id239;
    int32_t _i_manufact_id241;
};
void SW_JOIN_INNER_TD_11627645(Table &tbl_Filter_TD_1278768_output, Table &tbl_Filter_TD_12265825_output, Table &tbl_JOIN_INNER_TD_11627645_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((i_item_sk#228 = cs_item_sk#1119))
    // Left Table: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119, cs_order_number#1121L, cs_quantity#1122, cs_ext_sales_price#1127)
    // Right Table: ListBuffer(i_item_sk#228, i_brand_id#235, i_class_id#237, i_category_id#239, i_manufact_id#241)
    // Output Table: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119, cs_order_number#1121L, cs_quantity#1122, cs_ext_sales_price#1127, i_brand_id#235, i_class_id#237, i_category_id#239, i_manufact_id#241)
    int left_nrow = tbl_Filter_TD_1278768_output.getNumRow();
    int right_nrow = tbl_Filter_TD_12265825_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11627645_key_leftMajor, SW_JOIN_INNER_TD_11627645_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_1278768_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_item_sk1119_k = tbl_Filter_TD_1278768_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_11627645_key_leftMajor keyA{_cs_item_sk1119_k};
            int32_t _cs_sold_date_sk1104 = tbl_Filter_TD_1278768_output.getInt32(i, 0);
            int32_t _cs_item_sk1119 = tbl_Filter_TD_1278768_output.getInt32(i, 1);
            int64_t _cs_order_number1121L = tbl_Filter_TD_1278768_output.getInt64(i, 2);
            int32_t _cs_quantity1122 = tbl_Filter_TD_1278768_output.getInt32(i, 3);
            int64_t _cs_ext_sales_price1127 = tbl_Filter_TD_1278768_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_11627645_payload_leftMajor payloadA{_cs_sold_date_sk1104, _cs_item_sk1119, _cs_order_number1121L, _cs_quantity1122, _cs_ext_sales_price1127};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_12265825_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_12265825_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11627645_key_leftMajor{_i_item_sk228_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk1104 = (it->second)._cs_sold_date_sk1104;
                int32_t _cs_item_sk1119 = (it->second)._cs_item_sk1119;
                int64_t _cs_order_number1121L = (it->second)._cs_order_number1121L;
                int32_t _cs_quantity1122 = (it->second)._cs_quantity1122;
                int64_t _cs_ext_sales_price1127 = (it->second)._cs_ext_sales_price1127;
                int32_t _i_item_sk228 = tbl_Filter_TD_12265825_output.getInt32(i, 0);
                int32_t _i_brand_id235 = tbl_Filter_TD_12265825_output.getInt32(i, 1);
                int32_t _i_class_id237 = tbl_Filter_TD_12265825_output.getInt32(i, 2);
                int32_t _i_category_id239 = tbl_Filter_TD_12265825_output.getInt32(i, 3);
                int32_t _i_manufact_id241 = tbl_Filter_TD_12265825_output.getInt32(i, 4);
                tbl_JOIN_INNER_TD_11627645_output.setInt32(r, 0, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_11627645_output.setInt32(r, 1, _cs_item_sk1119);
                tbl_JOIN_INNER_TD_11627645_output.setInt64(r, 2, _cs_order_number1121L);
                tbl_JOIN_INNER_TD_11627645_output.setInt32(r, 3, _cs_quantity1122);
                tbl_JOIN_INNER_TD_11627645_output.setInt64(r, 4, _cs_ext_sales_price1127);
                tbl_JOIN_INNER_TD_11627645_output.setInt32(r, 5, _i_brand_id235);
                tbl_JOIN_INNER_TD_11627645_output.setInt32(r, 6, _i_class_id237);
                tbl_JOIN_INNER_TD_11627645_output.setInt32(r, 7, _i_category_id239);
                tbl_JOIN_INNER_TD_11627645_output.setInt32(r, 8, _i_manufact_id241);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11627645_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_11627645_key_rightMajor, SW_JOIN_INNER_TD_11627645_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_12265825_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_12265825_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_11627645_key_rightMajor keyA{_i_item_sk228_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_12265825_output.getInt32(i, 0);
            int32_t _i_brand_id235 = tbl_Filter_TD_12265825_output.getInt32(i, 1);
            int32_t _i_class_id237 = tbl_Filter_TD_12265825_output.getInt32(i, 2);
            int32_t _i_category_id239 = tbl_Filter_TD_12265825_output.getInt32(i, 3);
            int32_t _i_manufact_id241 = tbl_Filter_TD_12265825_output.getInt32(i, 4);
            SW_JOIN_INNER_TD_11627645_payload_rightMajor payloadA{_i_item_sk228, _i_brand_id235, _i_class_id237, _i_category_id239, _i_manufact_id241};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_1278768_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_item_sk1119_k = tbl_Filter_TD_1278768_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_11627645_key_rightMajor{_cs_item_sk1119_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                int32_t _i_brand_id235 = (it->second)._i_brand_id235;
                int32_t _i_class_id237 = (it->second)._i_class_id237;
                int32_t _i_category_id239 = (it->second)._i_category_id239;
                int32_t _i_manufact_id241 = (it->second)._i_manufact_id241;
                int32_t _cs_sold_date_sk1104 = tbl_Filter_TD_1278768_output.getInt32(i, 0);
                int32_t _cs_item_sk1119 = tbl_Filter_TD_1278768_output.getInt32(i, 1);
                int64_t _cs_order_number1121L = tbl_Filter_TD_1278768_output.getInt64(i, 2);
                int32_t _cs_quantity1122 = tbl_Filter_TD_1278768_output.getInt32(i, 3);
                int64_t _cs_ext_sales_price1127 = tbl_Filter_TD_1278768_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_11627645_output.setInt32(r, 5, _i_brand_id235);
                tbl_JOIN_INNER_TD_11627645_output.setInt32(r, 6, _i_class_id237);
                tbl_JOIN_INNER_TD_11627645_output.setInt32(r, 7, _i_category_id239);
                tbl_JOIN_INNER_TD_11627645_output.setInt32(r, 8, _i_manufact_id241);
                tbl_JOIN_INNER_TD_11627645_output.setInt32(r, 0, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_11627645_output.setInt32(r, 1, _cs_item_sk1119);
                tbl_JOIN_INNER_TD_11627645_output.setInt64(r, 2, _cs_order_number1121L);
                tbl_JOIN_INNER_TD_11627645_output.setInt32(r, 3, _cs_quantity1122);
                tbl_JOIN_INNER_TD_11627645_output.setInt64(r, 4, _cs_ext_sales_price1127);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_11627645_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_11627645_output #Row: " << tbl_JOIN_INNER_TD_11627645_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10776215(Table &tbl_SerializeFromObject_TD_11542495_input, Table &tbl_Filter_TD_10776215_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(wr_order_number#4727L) AND isnotnull(wr_item_sk#4716)))
    // Input: ListBuffer(wr_item_sk#4716, wr_order_number#4727L, wr_return_quantity#4728, wr_return_amt#4729)
    // Output: ListBuffer(wr_item_sk#4716, wr_order_number#4727L, wr_return_quantity#4728, wr_return_amt#4729)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11542495_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _wr_order_number4727L = tbl_SerializeFromObject_TD_11542495_input.getInt64(i, 1);
        int32_t _wr_item_sk4716 = tbl_SerializeFromObject_TD_11542495_input.getInt32(i, 0);
        if ((_wr_order_number4727L!= 0) && (_wr_item_sk4716!= 0)) {
            int32_t _wr_item_sk4716_t = tbl_SerializeFromObject_TD_11542495_input.getInt32(i, 0);
            tbl_Filter_TD_10776215_output.setInt32(r, 0, _wr_item_sk4716_t);
            int64_t _wr_order_number4727L_t = tbl_SerializeFromObject_TD_11542495_input.getInt64(i, 1);
            tbl_Filter_TD_10776215_output.setInt64(r, 1, _wr_order_number4727L_t);
            int32_t _wr_return_quantity4728_t = tbl_SerializeFromObject_TD_11542495_input.getInt32(i, 2);
            tbl_Filter_TD_10776215_output.setInt32(r, 2, _wr_return_quantity4728_t);
            int64_t _wr_return_amt4729_t = tbl_SerializeFromObject_TD_11542495_input.getInt64(i, 3);
            tbl_Filter_TD_10776215_output.setInt64(r, 3, _wr_return_amt4729_t);
            r++;
        }
    }
    tbl_Filter_TD_10776215_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10776215_output #Row: " << tbl_Filter_TD_10776215_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_10158452_key_leftMajor {
    int32_t _ws_sold_date_sk4630;
    bool operator==(const SW_JOIN_INNER_TD_10158452_key_leftMajor& other) const {
        return ((_ws_sold_date_sk4630 == other._ws_sold_date_sk4630));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10158452_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10158452_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_sold_date_sk4630));
    }
};
}
struct SW_JOIN_INNER_TD_10158452_payload_leftMajor {
    int32_t _ws_sold_date_sk4630;
    int32_t _ws_item_sk4633;
    int64_t _ws_order_number4647L;
    int32_t _ws_quantity4648;
    int64_t _ws_ext_sales_price4653;
    int32_t _i_brand_id4671;
    int32_t _i_class_id4673;
    int32_t _i_category_id4675;
    int32_t _i_manufact_id4677;
};
struct SW_JOIN_INNER_TD_10158452_key_rightMajor {
    int32_t _d_date_sk4686;
    bool operator==(const SW_JOIN_INNER_TD_10158452_key_rightMajor& other) const {
        return ((_d_date_sk4686 == other._d_date_sk4686));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10158452_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10158452_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk4686));
    }
};
}
struct SW_JOIN_INNER_TD_10158452_payload_rightMajor {
    int32_t _d_date_sk4686;
    int32_t _d_year4692;
};
void SW_JOIN_INNER_TD_10158452(Table &tbl_JOIN_INNER_TD_11243517_output, Table &tbl_Filter_TD_11196108_output, Table &tbl_JOIN_INNER_TD_10158452_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((d_date_sk#4686 = ws_sold_date_sk#4630))
    // Left Table: ListBuffer(ws_sold_date_sk#4630, ws_item_sk#4633, ws_order_number#4647L, ws_quantity#4648, ws_ext_sales_price#4653, i_brand_id#4671, i_class_id#4673, i_category_id#4675, i_manufact_id#4677)
    // Right Table: ListBuffer(d_date_sk#4686, d_year#4692)
    // Output Table: ListBuffer(ws_item_sk#4633, ws_order_number#4647L, ws_quantity#4648, ws_ext_sales_price#4653, i_brand_id#4671, i_class_id#4673, i_category_id#4675, i_manufact_id#4677, d_year#4692)
    int left_nrow = tbl_JOIN_INNER_TD_11243517_output.getNumRow();
    int right_nrow = tbl_Filter_TD_11196108_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10158452_key_leftMajor, SW_JOIN_INNER_TD_10158452_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_11243517_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_sold_date_sk4630_k = tbl_JOIN_INNER_TD_11243517_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_10158452_key_leftMajor keyA{_ws_sold_date_sk4630_k};
            int32_t _ws_sold_date_sk4630 = tbl_JOIN_INNER_TD_11243517_output.getInt32(i, 0);
            int32_t _ws_item_sk4633 = tbl_JOIN_INNER_TD_11243517_output.getInt32(i, 1);
            int64_t _ws_order_number4647L = tbl_JOIN_INNER_TD_11243517_output.getInt64(i, 2);
            int32_t _ws_quantity4648 = tbl_JOIN_INNER_TD_11243517_output.getInt32(i, 3);
            int64_t _ws_ext_sales_price4653 = tbl_JOIN_INNER_TD_11243517_output.getInt64(i, 4);
            int32_t _i_brand_id4671 = tbl_JOIN_INNER_TD_11243517_output.getInt32(i, 5);
            int32_t _i_class_id4673 = tbl_JOIN_INNER_TD_11243517_output.getInt32(i, 6);
            int32_t _i_category_id4675 = tbl_JOIN_INNER_TD_11243517_output.getInt32(i, 7);
            int32_t _i_manufact_id4677 = tbl_JOIN_INNER_TD_11243517_output.getInt32(i, 8);
            SW_JOIN_INNER_TD_10158452_payload_leftMajor payloadA{_ws_sold_date_sk4630, _ws_item_sk4633, _ws_order_number4647L, _ws_quantity4648, _ws_ext_sales_price4653, _i_brand_id4671, _i_class_id4673, _i_category_id4675, _i_manufact_id4677};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_11196108_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk4686_k = tbl_Filter_TD_11196108_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10158452_key_leftMajor{_d_date_sk4686_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_date_sk4630 = (it->second)._ws_sold_date_sk4630;
                int32_t _ws_item_sk4633 = (it->second)._ws_item_sk4633;
                int64_t _ws_order_number4647L = (it->second)._ws_order_number4647L;
                int32_t _ws_quantity4648 = (it->second)._ws_quantity4648;
                int64_t _ws_ext_sales_price4653 = (it->second)._ws_ext_sales_price4653;
                int32_t _i_brand_id4671 = (it->second)._i_brand_id4671;
                int32_t _i_class_id4673 = (it->second)._i_class_id4673;
                int32_t _i_category_id4675 = (it->second)._i_category_id4675;
                int32_t _i_manufact_id4677 = (it->second)._i_manufact_id4677;
                int32_t _d_date_sk4686 = tbl_Filter_TD_11196108_output.getInt32(i, 0);
                int32_t _d_year4692 = tbl_Filter_TD_11196108_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_10158452_output.setInt32(r, 0, _ws_item_sk4633);
                tbl_JOIN_INNER_TD_10158452_output.setInt64(r, 1, _ws_order_number4647L);
                tbl_JOIN_INNER_TD_10158452_output.setInt32(r, 2, _ws_quantity4648);
                tbl_JOIN_INNER_TD_10158452_output.setInt64(r, 3, _ws_ext_sales_price4653);
                tbl_JOIN_INNER_TD_10158452_output.setInt32(r, 4, _i_brand_id4671);
                tbl_JOIN_INNER_TD_10158452_output.setInt32(r, 5, _i_class_id4673);
                tbl_JOIN_INNER_TD_10158452_output.setInt32(r, 6, _i_category_id4675);
                tbl_JOIN_INNER_TD_10158452_output.setInt32(r, 7, _i_manufact_id4677);
                tbl_JOIN_INNER_TD_10158452_output.setInt32(r, 8, _d_year4692);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10158452_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10158452_key_rightMajor, SW_JOIN_INNER_TD_10158452_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_11196108_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk4686_k = tbl_Filter_TD_11196108_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_10158452_key_rightMajor keyA{_d_date_sk4686_k};
            int32_t _d_date_sk4686 = tbl_Filter_TD_11196108_output.getInt32(i, 0);
            int32_t _d_year4692 = tbl_Filter_TD_11196108_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_10158452_payload_rightMajor payloadA{_d_date_sk4686, _d_year4692};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_11243517_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_sold_date_sk4630_k = tbl_JOIN_INNER_TD_11243517_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10158452_key_rightMajor{_ws_sold_date_sk4630_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk4686 = (it->second)._d_date_sk4686;
                int32_t _d_year4692 = (it->second)._d_year4692;
                int32_t _ws_sold_date_sk4630 = tbl_JOIN_INNER_TD_11243517_output.getInt32(i, 0);
                int32_t _ws_item_sk4633 = tbl_JOIN_INNER_TD_11243517_output.getInt32(i, 1);
                int64_t _ws_order_number4647L = tbl_JOIN_INNER_TD_11243517_output.getInt64(i, 2);
                int32_t _ws_quantity4648 = tbl_JOIN_INNER_TD_11243517_output.getInt32(i, 3);
                int64_t _ws_ext_sales_price4653 = tbl_JOIN_INNER_TD_11243517_output.getInt64(i, 4);
                int32_t _i_brand_id4671 = tbl_JOIN_INNER_TD_11243517_output.getInt32(i, 5);
                int32_t _i_class_id4673 = tbl_JOIN_INNER_TD_11243517_output.getInt32(i, 6);
                int32_t _i_category_id4675 = tbl_JOIN_INNER_TD_11243517_output.getInt32(i, 7);
                int32_t _i_manufact_id4677 = tbl_JOIN_INNER_TD_11243517_output.getInt32(i, 8);
                tbl_JOIN_INNER_TD_10158452_output.setInt32(r, 8, _d_year4692);
                tbl_JOIN_INNER_TD_10158452_output.setInt32(r, 0, _ws_item_sk4633);
                tbl_JOIN_INNER_TD_10158452_output.setInt64(r, 1, _ws_order_number4647L);
                tbl_JOIN_INNER_TD_10158452_output.setInt32(r, 2, _ws_quantity4648);
                tbl_JOIN_INNER_TD_10158452_output.setInt64(r, 3, _ws_ext_sales_price4653);
                tbl_JOIN_INNER_TD_10158452_output.setInt32(r, 4, _i_brand_id4671);
                tbl_JOIN_INNER_TD_10158452_output.setInt32(r, 5, _i_class_id4673);
                tbl_JOIN_INNER_TD_10158452_output.setInt32(r, 6, _i_category_id4675);
                tbl_JOIN_INNER_TD_10158452_output.setInt32(r, 7, _i_manufact_id4677);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10158452_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_10158452_output #Row: " << tbl_JOIN_INNER_TD_10158452_output.getNumRow() << std::endl;
}

void SW_Filter_TD_1021027(Table &tbl_SerializeFromObject_TD_11213585_input, Table &tbl_Filter_TD_1021027_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(sr_ticket_number#4619L) AND isnotnull(sr_item_sk#4612)))
    // Input: ListBuffer(sr_item_sk#4612, sr_ticket_number#4619L, sr_return_quantity#4620, sr_return_amt#4621)
    // Output: ListBuffer(sr_item_sk#4612, sr_ticket_number#4619L, sr_return_quantity#4620, sr_return_amt#4621)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11213585_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sr_ticket_number4619L = tbl_SerializeFromObject_TD_11213585_input.getInt64(i, 1);
        int32_t _sr_item_sk4612 = tbl_SerializeFromObject_TD_11213585_input.getInt32(i, 0);
        if ((_sr_ticket_number4619L!= 0) && (_sr_item_sk4612!= 0)) {
            int32_t _sr_item_sk4612_t = tbl_SerializeFromObject_TD_11213585_input.getInt32(i, 0);
            tbl_Filter_TD_1021027_output.setInt32(r, 0, _sr_item_sk4612_t);
            int64_t _sr_ticket_number4619L_t = tbl_SerializeFromObject_TD_11213585_input.getInt64(i, 1);
            tbl_Filter_TD_1021027_output.setInt64(r, 1, _sr_ticket_number4619L_t);
            int32_t _sr_return_quantity4620_t = tbl_SerializeFromObject_TD_11213585_input.getInt32(i, 2);
            tbl_Filter_TD_1021027_output.setInt32(r, 2, _sr_return_quantity4620_t);
            int64_t _sr_return_amt4621_t = tbl_SerializeFromObject_TD_11213585_input.getInt64(i, 3);
            tbl_Filter_TD_1021027_output.setInt64(r, 3, _sr_return_amt4621_t);
            r++;
        }
    }
    tbl_Filter_TD_1021027_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1021027_output #Row: " << tbl_Filter_TD_1021027_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_10931863_key_leftMajor {
    int32_t _ss_sold_date_sk4537;
    bool operator==(const SW_JOIN_INNER_TD_10931863_key_leftMajor& other) const {
        return ((_ss_sold_date_sk4537 == other._ss_sold_date_sk4537));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10931863_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10931863_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_sold_date_sk4537));
    }
};
}
struct SW_JOIN_INNER_TD_10931863_payload_leftMajor {
    int32_t _ss_sold_date_sk4537;
    int32_t _ss_item_sk4539;
    int64_t _ss_ticket_number4546L;
    int32_t _ss_quantity4547;
    int64_t _ss_ext_sales_price4552;
    int32_t _i_brand_id4567;
    int32_t _i_class_id4569;
    int32_t _i_category_id4571;
    int32_t _i_manufact_id4573;
};
struct SW_JOIN_INNER_TD_10931863_key_rightMajor {
    int32_t _d_date_sk4582;
    bool operator==(const SW_JOIN_INNER_TD_10931863_key_rightMajor& other) const {
        return ((_d_date_sk4582 == other._d_date_sk4582));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10931863_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10931863_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk4582));
    }
};
}
struct SW_JOIN_INNER_TD_10931863_payload_rightMajor {
    int32_t _d_date_sk4582;
    int32_t _d_year4588;
};
void SW_JOIN_INNER_TD_10931863(Table &tbl_JOIN_INNER_TD_11321498_output, Table &tbl_Filter_TD_11485295_output, Table &tbl_JOIN_INNER_TD_10931863_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((d_date_sk#4582 = ss_sold_date_sk#4537))
    // Left Table: ListBuffer(ss_sold_date_sk#4537, ss_item_sk#4539, ss_ticket_number#4546L, ss_quantity#4547, ss_ext_sales_price#4552, i_brand_id#4567, i_class_id#4569, i_category_id#4571, i_manufact_id#4573)
    // Right Table: ListBuffer(d_date_sk#4582, d_year#4588)
    // Output Table: ListBuffer(ss_item_sk#4539, ss_ticket_number#4546L, ss_quantity#4547, ss_ext_sales_price#4552, i_brand_id#4567, i_class_id#4569, i_category_id#4571, i_manufact_id#4573, d_year#4588)
    int left_nrow = tbl_JOIN_INNER_TD_11321498_output.getNumRow();
    int right_nrow = tbl_Filter_TD_11485295_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10931863_key_leftMajor, SW_JOIN_INNER_TD_10931863_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_11321498_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_sold_date_sk4537_k = tbl_JOIN_INNER_TD_11321498_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_10931863_key_leftMajor keyA{_ss_sold_date_sk4537_k};
            int32_t _ss_sold_date_sk4537 = tbl_JOIN_INNER_TD_11321498_output.getInt32(i, 0);
            int32_t _ss_item_sk4539 = tbl_JOIN_INNER_TD_11321498_output.getInt32(i, 1);
            int64_t _ss_ticket_number4546L = tbl_JOIN_INNER_TD_11321498_output.getInt64(i, 2);
            int32_t _ss_quantity4547 = tbl_JOIN_INNER_TD_11321498_output.getInt32(i, 3);
            int64_t _ss_ext_sales_price4552 = tbl_JOIN_INNER_TD_11321498_output.getInt64(i, 4);
            int32_t _i_brand_id4567 = tbl_JOIN_INNER_TD_11321498_output.getInt32(i, 5);
            int32_t _i_class_id4569 = tbl_JOIN_INNER_TD_11321498_output.getInt32(i, 6);
            int32_t _i_category_id4571 = tbl_JOIN_INNER_TD_11321498_output.getInt32(i, 7);
            int32_t _i_manufact_id4573 = tbl_JOIN_INNER_TD_11321498_output.getInt32(i, 8);
            SW_JOIN_INNER_TD_10931863_payload_leftMajor payloadA{_ss_sold_date_sk4537, _ss_item_sk4539, _ss_ticket_number4546L, _ss_quantity4547, _ss_ext_sales_price4552, _i_brand_id4567, _i_class_id4569, _i_category_id4571, _i_manufact_id4573};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_11485295_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk4582_k = tbl_Filter_TD_11485295_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10931863_key_leftMajor{_d_date_sk4582_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk4537 = (it->second)._ss_sold_date_sk4537;
                int32_t _ss_item_sk4539 = (it->second)._ss_item_sk4539;
                int64_t _ss_ticket_number4546L = (it->second)._ss_ticket_number4546L;
                int32_t _ss_quantity4547 = (it->second)._ss_quantity4547;
                int64_t _ss_ext_sales_price4552 = (it->second)._ss_ext_sales_price4552;
                int32_t _i_brand_id4567 = (it->second)._i_brand_id4567;
                int32_t _i_class_id4569 = (it->second)._i_class_id4569;
                int32_t _i_category_id4571 = (it->second)._i_category_id4571;
                int32_t _i_manufact_id4573 = (it->second)._i_manufact_id4573;
                int32_t _d_date_sk4582 = tbl_Filter_TD_11485295_output.getInt32(i, 0);
                int32_t _d_year4588 = tbl_Filter_TD_11485295_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_10931863_output.setInt32(r, 0, _ss_item_sk4539);
                tbl_JOIN_INNER_TD_10931863_output.setInt64(r, 1, _ss_ticket_number4546L);
                tbl_JOIN_INNER_TD_10931863_output.setInt32(r, 2, _ss_quantity4547);
                tbl_JOIN_INNER_TD_10931863_output.setInt64(r, 3, _ss_ext_sales_price4552);
                tbl_JOIN_INNER_TD_10931863_output.setInt32(r, 4, _i_brand_id4567);
                tbl_JOIN_INNER_TD_10931863_output.setInt32(r, 5, _i_class_id4569);
                tbl_JOIN_INNER_TD_10931863_output.setInt32(r, 6, _i_category_id4571);
                tbl_JOIN_INNER_TD_10931863_output.setInt32(r, 7, _i_manufact_id4573);
                tbl_JOIN_INNER_TD_10931863_output.setInt32(r, 8, _d_year4588);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10931863_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10931863_key_rightMajor, SW_JOIN_INNER_TD_10931863_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_11485295_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk4582_k = tbl_Filter_TD_11485295_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_10931863_key_rightMajor keyA{_d_date_sk4582_k};
            int32_t _d_date_sk4582 = tbl_Filter_TD_11485295_output.getInt32(i, 0);
            int32_t _d_year4588 = tbl_Filter_TD_11485295_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_10931863_payload_rightMajor payloadA{_d_date_sk4582, _d_year4588};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_11321498_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_sold_date_sk4537_k = tbl_JOIN_INNER_TD_11321498_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10931863_key_rightMajor{_ss_sold_date_sk4537_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk4582 = (it->second)._d_date_sk4582;
                int32_t _d_year4588 = (it->second)._d_year4588;
                int32_t _ss_sold_date_sk4537 = tbl_JOIN_INNER_TD_11321498_output.getInt32(i, 0);
                int32_t _ss_item_sk4539 = tbl_JOIN_INNER_TD_11321498_output.getInt32(i, 1);
                int64_t _ss_ticket_number4546L = tbl_JOIN_INNER_TD_11321498_output.getInt64(i, 2);
                int32_t _ss_quantity4547 = tbl_JOIN_INNER_TD_11321498_output.getInt32(i, 3);
                int64_t _ss_ext_sales_price4552 = tbl_JOIN_INNER_TD_11321498_output.getInt64(i, 4);
                int32_t _i_brand_id4567 = tbl_JOIN_INNER_TD_11321498_output.getInt32(i, 5);
                int32_t _i_class_id4569 = tbl_JOIN_INNER_TD_11321498_output.getInt32(i, 6);
                int32_t _i_category_id4571 = tbl_JOIN_INNER_TD_11321498_output.getInt32(i, 7);
                int32_t _i_manufact_id4573 = tbl_JOIN_INNER_TD_11321498_output.getInt32(i, 8);
                tbl_JOIN_INNER_TD_10931863_output.setInt32(r, 8, _d_year4588);
                tbl_JOIN_INNER_TD_10931863_output.setInt32(r, 0, _ss_item_sk4539);
                tbl_JOIN_INNER_TD_10931863_output.setInt64(r, 1, _ss_ticket_number4546L);
                tbl_JOIN_INNER_TD_10931863_output.setInt32(r, 2, _ss_quantity4547);
                tbl_JOIN_INNER_TD_10931863_output.setInt64(r, 3, _ss_ext_sales_price4552);
                tbl_JOIN_INNER_TD_10931863_output.setInt32(r, 4, _i_brand_id4567);
                tbl_JOIN_INNER_TD_10931863_output.setInt32(r, 5, _i_class_id4569);
                tbl_JOIN_INNER_TD_10931863_output.setInt32(r, 6, _i_category_id4571);
                tbl_JOIN_INNER_TD_10931863_output.setInt32(r, 7, _i_manufact_id4573);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10931863_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_10931863_output #Row: " << tbl_JOIN_INNER_TD_10931863_output.getNumRow() << std::endl;
}

void SW_Filter_TD_1062905(Table &tbl_SerializeFromObject_TD_11428191_input, Table &tbl_Filter_TD_1062905_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cr_order_number#4526L) AND isnotnull(cr_item_sk#4512)))
    // Input: ListBuffer(cr_item_sk#4512, cr_order_number#4526L, cr_return_quantity#4527, cr_return_amount#4528)
    // Output: ListBuffer(cr_item_sk#4512, cr_order_number#4526L, cr_return_quantity#4527, cr_return_amount#4528)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11428191_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _cr_order_number4526L = tbl_SerializeFromObject_TD_11428191_input.getInt64(i, 1);
        int32_t _cr_item_sk4512 = tbl_SerializeFromObject_TD_11428191_input.getInt32(i, 0);
        if ((_cr_order_number4526L!= 0) && (_cr_item_sk4512!= 0)) {
            int32_t _cr_item_sk4512_t = tbl_SerializeFromObject_TD_11428191_input.getInt32(i, 0);
            tbl_Filter_TD_1062905_output.setInt32(r, 0, _cr_item_sk4512_t);
            int64_t _cr_order_number4526L_t = tbl_SerializeFromObject_TD_11428191_input.getInt64(i, 1);
            tbl_Filter_TD_1062905_output.setInt64(r, 1, _cr_order_number4526L_t);
            int32_t _cr_return_quantity4527_t = tbl_SerializeFromObject_TD_11428191_input.getInt32(i, 2);
            tbl_Filter_TD_1062905_output.setInt32(r, 2, _cr_return_quantity4527_t);
            int64_t _cr_return_amount4528_t = tbl_SerializeFromObject_TD_11428191_input.getInt64(i, 3);
            tbl_Filter_TD_1062905_output.setInt64(r, 3, _cr_return_amount4528_t);
            r++;
        }
    }
    tbl_Filter_TD_1062905_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1062905_output #Row: " << tbl_Filter_TD_1062905_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_10795304_key_leftMajor {
    int32_t _cs_sold_date_sk4426;
    bool operator==(const SW_JOIN_INNER_TD_10795304_key_leftMajor& other) const {
        return ((_cs_sold_date_sk4426 == other._cs_sold_date_sk4426));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10795304_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10795304_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_sold_date_sk4426));
    }
};
}
struct SW_JOIN_INNER_TD_10795304_payload_leftMajor {
    int32_t _cs_sold_date_sk4426;
    int32_t _cs_item_sk4441;
    int64_t _cs_order_number4443L;
    int32_t _cs_quantity4444;
    int64_t _cs_ext_sales_price4449;
    int32_t _i_brand_id4467;
    int32_t _i_class_id4469;
    int32_t _i_category_id4471;
    int32_t _i_manufact_id4473;
};
struct SW_JOIN_INNER_TD_10795304_key_rightMajor {
    int32_t _d_date_sk4482;
    bool operator==(const SW_JOIN_INNER_TD_10795304_key_rightMajor& other) const {
        return ((_d_date_sk4482 == other._d_date_sk4482));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10795304_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10795304_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk4482));
    }
};
}
struct SW_JOIN_INNER_TD_10795304_payload_rightMajor {
    int32_t _d_date_sk4482;
    int32_t _d_year4488;
};
void SW_JOIN_INNER_TD_10795304(Table &tbl_JOIN_INNER_TD_11469408_output, Table &tbl_Filter_TD_11546642_output, Table &tbl_JOIN_INNER_TD_10795304_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((d_date_sk#4482 = cs_sold_date_sk#4426))
    // Left Table: ListBuffer(cs_sold_date_sk#4426, cs_item_sk#4441, cs_order_number#4443L, cs_quantity#4444, cs_ext_sales_price#4449, i_brand_id#4467, i_class_id#4469, i_category_id#4471, i_manufact_id#4473)
    // Right Table: ListBuffer(d_date_sk#4482, d_year#4488)
    // Output Table: ListBuffer(cs_item_sk#4441, cs_order_number#4443L, cs_quantity#4444, cs_ext_sales_price#4449, i_brand_id#4467, i_class_id#4469, i_category_id#4471, i_manufact_id#4473, d_year#4488)
    int left_nrow = tbl_JOIN_INNER_TD_11469408_output.getNumRow();
    int right_nrow = tbl_Filter_TD_11546642_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10795304_key_leftMajor, SW_JOIN_INNER_TD_10795304_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_11469408_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_sold_date_sk4426_k = tbl_JOIN_INNER_TD_11469408_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_10795304_key_leftMajor keyA{_cs_sold_date_sk4426_k};
            int32_t _cs_sold_date_sk4426 = tbl_JOIN_INNER_TD_11469408_output.getInt32(i, 0);
            int32_t _cs_item_sk4441 = tbl_JOIN_INNER_TD_11469408_output.getInt32(i, 1);
            int64_t _cs_order_number4443L = tbl_JOIN_INNER_TD_11469408_output.getInt64(i, 2);
            int32_t _cs_quantity4444 = tbl_JOIN_INNER_TD_11469408_output.getInt32(i, 3);
            int64_t _cs_ext_sales_price4449 = tbl_JOIN_INNER_TD_11469408_output.getInt64(i, 4);
            int32_t _i_brand_id4467 = tbl_JOIN_INNER_TD_11469408_output.getInt32(i, 5);
            int32_t _i_class_id4469 = tbl_JOIN_INNER_TD_11469408_output.getInt32(i, 6);
            int32_t _i_category_id4471 = tbl_JOIN_INNER_TD_11469408_output.getInt32(i, 7);
            int32_t _i_manufact_id4473 = tbl_JOIN_INNER_TD_11469408_output.getInt32(i, 8);
            SW_JOIN_INNER_TD_10795304_payload_leftMajor payloadA{_cs_sold_date_sk4426, _cs_item_sk4441, _cs_order_number4443L, _cs_quantity4444, _cs_ext_sales_price4449, _i_brand_id4467, _i_class_id4469, _i_category_id4471, _i_manufact_id4473};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_11546642_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk4482_k = tbl_Filter_TD_11546642_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10795304_key_leftMajor{_d_date_sk4482_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk4426 = (it->second)._cs_sold_date_sk4426;
                int32_t _cs_item_sk4441 = (it->second)._cs_item_sk4441;
                int64_t _cs_order_number4443L = (it->second)._cs_order_number4443L;
                int32_t _cs_quantity4444 = (it->second)._cs_quantity4444;
                int64_t _cs_ext_sales_price4449 = (it->second)._cs_ext_sales_price4449;
                int32_t _i_brand_id4467 = (it->second)._i_brand_id4467;
                int32_t _i_class_id4469 = (it->second)._i_class_id4469;
                int32_t _i_category_id4471 = (it->second)._i_category_id4471;
                int32_t _i_manufact_id4473 = (it->second)._i_manufact_id4473;
                int32_t _d_date_sk4482 = tbl_Filter_TD_11546642_output.getInt32(i, 0);
                int32_t _d_year4488 = tbl_Filter_TD_11546642_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_10795304_output.setInt32(r, 0, _cs_item_sk4441);
                tbl_JOIN_INNER_TD_10795304_output.setInt64(r, 1, _cs_order_number4443L);
                tbl_JOIN_INNER_TD_10795304_output.setInt32(r, 2, _cs_quantity4444);
                tbl_JOIN_INNER_TD_10795304_output.setInt64(r, 3, _cs_ext_sales_price4449);
                tbl_JOIN_INNER_TD_10795304_output.setInt32(r, 4, _i_brand_id4467);
                tbl_JOIN_INNER_TD_10795304_output.setInt32(r, 5, _i_class_id4469);
                tbl_JOIN_INNER_TD_10795304_output.setInt32(r, 6, _i_category_id4471);
                tbl_JOIN_INNER_TD_10795304_output.setInt32(r, 7, _i_manufact_id4473);
                tbl_JOIN_INNER_TD_10795304_output.setInt32(r, 8, _d_year4488);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10795304_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10795304_key_rightMajor, SW_JOIN_INNER_TD_10795304_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_11546642_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk4482_k = tbl_Filter_TD_11546642_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_10795304_key_rightMajor keyA{_d_date_sk4482_k};
            int32_t _d_date_sk4482 = tbl_Filter_TD_11546642_output.getInt32(i, 0);
            int32_t _d_year4488 = tbl_Filter_TD_11546642_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_10795304_payload_rightMajor payloadA{_d_date_sk4482, _d_year4488};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_11469408_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_sold_date_sk4426_k = tbl_JOIN_INNER_TD_11469408_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10795304_key_rightMajor{_cs_sold_date_sk4426_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk4482 = (it->second)._d_date_sk4482;
                int32_t _d_year4488 = (it->second)._d_year4488;
                int32_t _cs_sold_date_sk4426 = tbl_JOIN_INNER_TD_11469408_output.getInt32(i, 0);
                int32_t _cs_item_sk4441 = tbl_JOIN_INNER_TD_11469408_output.getInt32(i, 1);
                int64_t _cs_order_number4443L = tbl_JOIN_INNER_TD_11469408_output.getInt64(i, 2);
                int32_t _cs_quantity4444 = tbl_JOIN_INNER_TD_11469408_output.getInt32(i, 3);
                int64_t _cs_ext_sales_price4449 = tbl_JOIN_INNER_TD_11469408_output.getInt64(i, 4);
                int32_t _i_brand_id4467 = tbl_JOIN_INNER_TD_11469408_output.getInt32(i, 5);
                int32_t _i_class_id4469 = tbl_JOIN_INNER_TD_11469408_output.getInt32(i, 6);
                int32_t _i_category_id4471 = tbl_JOIN_INNER_TD_11469408_output.getInt32(i, 7);
                int32_t _i_manufact_id4473 = tbl_JOIN_INNER_TD_11469408_output.getInt32(i, 8);
                tbl_JOIN_INNER_TD_10795304_output.setInt32(r, 8, _d_year4488);
                tbl_JOIN_INNER_TD_10795304_output.setInt32(r, 0, _cs_item_sk4441);
                tbl_JOIN_INNER_TD_10795304_output.setInt64(r, 1, _cs_order_number4443L);
                tbl_JOIN_INNER_TD_10795304_output.setInt32(r, 2, _cs_quantity4444);
                tbl_JOIN_INNER_TD_10795304_output.setInt64(r, 3, _cs_ext_sales_price4449);
                tbl_JOIN_INNER_TD_10795304_output.setInt32(r, 4, _i_brand_id4467);
                tbl_JOIN_INNER_TD_10795304_output.setInt32(r, 5, _i_class_id4469);
                tbl_JOIN_INNER_TD_10795304_output.setInt32(r, 6, _i_category_id4471);
                tbl_JOIN_INNER_TD_10795304_output.setInt32(r, 7, _i_manufact_id4473);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10795304_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_10795304_output #Row: " << tbl_JOIN_INNER_TD_10795304_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10332983(Table &tbl_SerializeFromObject_TD_11105343_input, Table &tbl_Filter_TD_10332983_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(wr_order_number#844L) AND isnotnull(wr_item_sk#833)))
    // Input: ListBuffer(wr_item_sk#833, wr_order_number#844L, wr_return_quantity#845, wr_return_amt#846)
    // Output: ListBuffer(wr_item_sk#833, wr_order_number#844L, wr_return_quantity#845, wr_return_amt#846)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11105343_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _wr_order_number844L = tbl_SerializeFromObject_TD_11105343_input.getInt64(i, 1);
        int32_t _wr_item_sk833 = tbl_SerializeFromObject_TD_11105343_input.getInt32(i, 0);
        if ((_wr_order_number844L!= 0) && (_wr_item_sk833!= 0)) {
            int32_t _wr_item_sk833_t = tbl_SerializeFromObject_TD_11105343_input.getInt32(i, 0);
            tbl_Filter_TD_10332983_output.setInt32(r, 0, _wr_item_sk833_t);
            int64_t _wr_order_number844L_t = tbl_SerializeFromObject_TD_11105343_input.getInt64(i, 1);
            tbl_Filter_TD_10332983_output.setInt64(r, 1, _wr_order_number844L_t);
            int32_t _wr_return_quantity845_t = tbl_SerializeFromObject_TD_11105343_input.getInt32(i, 2);
            tbl_Filter_TD_10332983_output.setInt32(r, 2, _wr_return_quantity845_t);
            int64_t _wr_return_amt846_t = tbl_SerializeFromObject_TD_11105343_input.getInt64(i, 3);
            tbl_Filter_TD_10332983_output.setInt64(r, 3, _wr_return_amt846_t);
            r++;
        }
    }
    tbl_Filter_TD_10332983_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10332983_output #Row: " << tbl_Filter_TD_10332983_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_10636324_key_leftMajor {
    int32_t _ws_sold_date_sk729;
    bool operator==(const SW_JOIN_INNER_TD_10636324_key_leftMajor& other) const {
        return ((_ws_sold_date_sk729 == other._ws_sold_date_sk729));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10636324_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10636324_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_sold_date_sk729));
    }
};
}
struct SW_JOIN_INNER_TD_10636324_payload_leftMajor {
    int32_t _ws_sold_date_sk729;
    int32_t _ws_item_sk732;
    int64_t _ws_order_number746L;
    int32_t _ws_quantity747;
    int64_t _ws_ext_sales_price752;
    int32_t _i_brand_id3615;
    int32_t _i_class_id3617;
    int32_t _i_category_id3619;
    int32_t _i_manufact_id3621;
};
struct SW_JOIN_INNER_TD_10636324_key_rightMajor {
    int32_t _d_date_sk3630;
    bool operator==(const SW_JOIN_INNER_TD_10636324_key_rightMajor& other) const {
        return ((_d_date_sk3630 == other._d_date_sk3630));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10636324_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10636324_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk3630));
    }
};
}
struct SW_JOIN_INNER_TD_10636324_payload_rightMajor {
    int32_t _d_date_sk3630;
    int32_t _d_year3636;
};
void SW_JOIN_INNER_TD_10636324(Table &tbl_JOIN_INNER_TD_11650737_output, Table &tbl_Filter_TD_11291823_output, Table &tbl_JOIN_INNER_TD_10636324_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((d_date_sk#3630 = ws_sold_date_sk#729))
    // Left Table: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_order_number#746L, ws_quantity#747, ws_ext_sales_price#752, i_brand_id#3615, i_class_id#3617, i_category_id#3619, i_manufact_id#3621)
    // Right Table: ListBuffer(d_date_sk#3630, d_year#3636)
    // Output Table: ListBuffer(ws_item_sk#732, ws_order_number#746L, ws_quantity#747, ws_ext_sales_price#752, i_brand_id#3615, i_class_id#3617, i_category_id#3619, i_manufact_id#3621, d_year#3636)
    int left_nrow = tbl_JOIN_INNER_TD_11650737_output.getNumRow();
    int right_nrow = tbl_Filter_TD_11291823_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10636324_key_leftMajor, SW_JOIN_INNER_TD_10636324_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_11650737_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_sold_date_sk729_k = tbl_JOIN_INNER_TD_11650737_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_10636324_key_leftMajor keyA{_ws_sold_date_sk729_k};
            int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_11650737_output.getInt32(i, 0);
            int32_t _ws_item_sk732 = tbl_JOIN_INNER_TD_11650737_output.getInt32(i, 1);
            int64_t _ws_order_number746L = tbl_JOIN_INNER_TD_11650737_output.getInt64(i, 2);
            int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_11650737_output.getInt32(i, 3);
            int64_t _ws_ext_sales_price752 = tbl_JOIN_INNER_TD_11650737_output.getInt64(i, 4);
            int32_t _i_brand_id3615 = tbl_JOIN_INNER_TD_11650737_output.getInt32(i, 5);
            int32_t _i_class_id3617 = tbl_JOIN_INNER_TD_11650737_output.getInt32(i, 6);
            int32_t _i_category_id3619 = tbl_JOIN_INNER_TD_11650737_output.getInt32(i, 7);
            int32_t _i_manufact_id3621 = tbl_JOIN_INNER_TD_11650737_output.getInt32(i, 8);
            SW_JOIN_INNER_TD_10636324_payload_leftMajor payloadA{_ws_sold_date_sk729, _ws_item_sk732, _ws_order_number746L, _ws_quantity747, _ws_ext_sales_price752, _i_brand_id3615, _i_class_id3617, _i_category_id3619, _i_manufact_id3621};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_11291823_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk3630_k = tbl_Filter_TD_11291823_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10636324_key_leftMajor{_d_date_sk3630_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_date_sk729 = (it->second)._ws_sold_date_sk729;
                int32_t _ws_item_sk732 = (it->second)._ws_item_sk732;
                int64_t _ws_order_number746L = (it->second)._ws_order_number746L;
                int32_t _ws_quantity747 = (it->second)._ws_quantity747;
                int64_t _ws_ext_sales_price752 = (it->second)._ws_ext_sales_price752;
                int32_t _i_brand_id3615 = (it->second)._i_brand_id3615;
                int32_t _i_class_id3617 = (it->second)._i_class_id3617;
                int32_t _i_category_id3619 = (it->second)._i_category_id3619;
                int32_t _i_manufact_id3621 = (it->second)._i_manufact_id3621;
                int32_t _d_date_sk3630 = tbl_Filter_TD_11291823_output.getInt32(i, 0);
                int32_t _d_year3636 = tbl_Filter_TD_11291823_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_10636324_output.setInt32(r, 0, _ws_item_sk732);
                tbl_JOIN_INNER_TD_10636324_output.setInt64(r, 1, _ws_order_number746L);
                tbl_JOIN_INNER_TD_10636324_output.setInt32(r, 2, _ws_quantity747);
                tbl_JOIN_INNER_TD_10636324_output.setInt64(r, 3, _ws_ext_sales_price752);
                tbl_JOIN_INNER_TD_10636324_output.setInt32(r, 4, _i_brand_id3615);
                tbl_JOIN_INNER_TD_10636324_output.setInt32(r, 5, _i_class_id3617);
                tbl_JOIN_INNER_TD_10636324_output.setInt32(r, 6, _i_category_id3619);
                tbl_JOIN_INNER_TD_10636324_output.setInt32(r, 7, _i_manufact_id3621);
                tbl_JOIN_INNER_TD_10636324_output.setInt32(r, 8, _d_year3636);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10636324_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10636324_key_rightMajor, SW_JOIN_INNER_TD_10636324_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_11291823_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk3630_k = tbl_Filter_TD_11291823_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_10636324_key_rightMajor keyA{_d_date_sk3630_k};
            int32_t _d_date_sk3630 = tbl_Filter_TD_11291823_output.getInt32(i, 0);
            int32_t _d_year3636 = tbl_Filter_TD_11291823_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_10636324_payload_rightMajor payloadA{_d_date_sk3630, _d_year3636};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_11650737_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_sold_date_sk729_k = tbl_JOIN_INNER_TD_11650737_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10636324_key_rightMajor{_ws_sold_date_sk729_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk3630 = (it->second)._d_date_sk3630;
                int32_t _d_year3636 = (it->second)._d_year3636;
                int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_11650737_output.getInt32(i, 0);
                int32_t _ws_item_sk732 = tbl_JOIN_INNER_TD_11650737_output.getInt32(i, 1);
                int64_t _ws_order_number746L = tbl_JOIN_INNER_TD_11650737_output.getInt64(i, 2);
                int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_11650737_output.getInt32(i, 3);
                int64_t _ws_ext_sales_price752 = tbl_JOIN_INNER_TD_11650737_output.getInt64(i, 4);
                int32_t _i_brand_id3615 = tbl_JOIN_INNER_TD_11650737_output.getInt32(i, 5);
                int32_t _i_class_id3617 = tbl_JOIN_INNER_TD_11650737_output.getInt32(i, 6);
                int32_t _i_category_id3619 = tbl_JOIN_INNER_TD_11650737_output.getInt32(i, 7);
                int32_t _i_manufact_id3621 = tbl_JOIN_INNER_TD_11650737_output.getInt32(i, 8);
                tbl_JOIN_INNER_TD_10636324_output.setInt32(r, 8, _d_year3636);
                tbl_JOIN_INNER_TD_10636324_output.setInt32(r, 0, _ws_item_sk732);
                tbl_JOIN_INNER_TD_10636324_output.setInt64(r, 1, _ws_order_number746L);
                tbl_JOIN_INNER_TD_10636324_output.setInt32(r, 2, _ws_quantity747);
                tbl_JOIN_INNER_TD_10636324_output.setInt64(r, 3, _ws_ext_sales_price752);
                tbl_JOIN_INNER_TD_10636324_output.setInt32(r, 4, _i_brand_id3615);
                tbl_JOIN_INNER_TD_10636324_output.setInt32(r, 5, _i_class_id3617);
                tbl_JOIN_INNER_TD_10636324_output.setInt32(r, 6, _i_category_id3619);
                tbl_JOIN_INNER_TD_10636324_output.setInt32(r, 7, _i_manufact_id3621);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10636324_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_10636324_output #Row: " << tbl_JOIN_INNER_TD_10636324_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10273351(Table &tbl_SerializeFromObject_TD_11832329_input, Table &tbl_Filter_TD_10273351_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(sr_ticket_number#678L) AND isnotnull(sr_item_sk#671)))
    // Input: ListBuffer(sr_item_sk#671, sr_ticket_number#678L, sr_return_quantity#679, sr_return_amt#680)
    // Output: ListBuffer(sr_item_sk#671, sr_ticket_number#678L, sr_return_quantity#679, sr_return_amt#680)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11832329_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sr_ticket_number678L = tbl_SerializeFromObject_TD_11832329_input.getInt64(i, 1);
        int32_t _sr_item_sk671 = tbl_SerializeFromObject_TD_11832329_input.getInt32(i, 0);
        if ((_sr_ticket_number678L!= 0) && (_sr_item_sk671!= 0)) {
            int32_t _sr_item_sk671_t = tbl_SerializeFromObject_TD_11832329_input.getInt32(i, 0);
            tbl_Filter_TD_10273351_output.setInt32(r, 0, _sr_item_sk671_t);
            int64_t _sr_ticket_number678L_t = tbl_SerializeFromObject_TD_11832329_input.getInt64(i, 1);
            tbl_Filter_TD_10273351_output.setInt64(r, 1, _sr_ticket_number678L_t);
            int32_t _sr_return_quantity679_t = tbl_SerializeFromObject_TD_11832329_input.getInt32(i, 2);
            tbl_Filter_TD_10273351_output.setInt32(r, 2, _sr_return_quantity679_t);
            int64_t _sr_return_amt680_t = tbl_SerializeFromObject_TD_11832329_input.getInt64(i, 3);
            tbl_Filter_TD_10273351_output.setInt64(r, 3, _sr_return_amt680_t);
            r++;
        }
    }
    tbl_Filter_TD_10273351_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10273351_output #Row: " << tbl_Filter_TD_10273351_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_10968541_key_leftMajor {
    int32_t _ss_sold_date_sk1206;
    bool operator==(const SW_JOIN_INNER_TD_10968541_key_leftMajor& other) const {
        return ((_ss_sold_date_sk1206 == other._ss_sold_date_sk1206));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10968541_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10968541_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_sold_date_sk1206));
    }
};
}
struct SW_JOIN_INNER_TD_10968541_payload_leftMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_item_sk1208;
    int64_t _ss_ticket_number1215L;
    int32_t _ss_quantity1216;
    int64_t _ss_ext_sales_price1221;
    int32_t _i_brand_id3565;
    int32_t _i_class_id3567;
    int32_t _i_category_id3569;
    int32_t _i_manufact_id3571;
};
struct SW_JOIN_INNER_TD_10968541_key_rightMajor {
    int32_t _d_date_sk3580;
    bool operator==(const SW_JOIN_INNER_TD_10968541_key_rightMajor& other) const {
        return ((_d_date_sk3580 == other._d_date_sk3580));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10968541_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10968541_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk3580));
    }
};
}
struct SW_JOIN_INNER_TD_10968541_payload_rightMajor {
    int32_t _d_date_sk3580;
    int32_t _d_year3586;
};
void SW_JOIN_INNER_TD_10968541(Table &tbl_JOIN_INNER_TD_11868273_output, Table &tbl_Filter_TD_11126261_output, Table &tbl_JOIN_INNER_TD_10968541_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((d_date_sk#3580 = ss_sold_date_sk#1206))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_ticket_number#1215L, ss_quantity#1216, ss_ext_sales_price#1221, i_brand_id#3565, i_class_id#3567, i_category_id#3569, i_manufact_id#3571)
    // Right Table: ListBuffer(d_date_sk#3580, d_year#3586)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_ticket_number#1215L, ss_quantity#1216, ss_ext_sales_price#1221, i_brand_id#3565, i_class_id#3567, i_category_id#3569, i_manufact_id#3571, d_year#3586)
    int left_nrow = tbl_JOIN_INNER_TD_11868273_output.getNumRow();
    int right_nrow = tbl_Filter_TD_11126261_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10968541_key_leftMajor, SW_JOIN_INNER_TD_10968541_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_11868273_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_JOIN_INNER_TD_11868273_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_10968541_key_leftMajor keyA{_ss_sold_date_sk1206_k};
            int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_11868273_output.getInt32(i, 0);
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_11868273_output.getInt32(i, 1);
            int64_t _ss_ticket_number1215L = tbl_JOIN_INNER_TD_11868273_output.getInt64(i, 2);
            int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_11868273_output.getInt32(i, 3);
            int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_11868273_output.getInt64(i, 4);
            int32_t _i_brand_id3565 = tbl_JOIN_INNER_TD_11868273_output.getInt32(i, 5);
            int32_t _i_class_id3567 = tbl_JOIN_INNER_TD_11868273_output.getInt32(i, 6);
            int32_t _i_category_id3569 = tbl_JOIN_INNER_TD_11868273_output.getInt32(i, 7);
            int32_t _i_manufact_id3571 = tbl_JOIN_INNER_TD_11868273_output.getInt32(i, 8);
            SW_JOIN_INNER_TD_10968541_payload_leftMajor payloadA{_ss_sold_date_sk1206, _ss_item_sk1208, _ss_ticket_number1215L, _ss_quantity1216, _ss_ext_sales_price1221, _i_brand_id3565, _i_class_id3567, _i_category_id3569, _i_manufact_id3571};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_11126261_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk3580_k = tbl_Filter_TD_11126261_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10968541_key_leftMajor{_d_date_sk3580_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int64_t _ss_ticket_number1215L = (it->second)._ss_ticket_number1215L;
                int32_t _ss_quantity1216 = (it->second)._ss_quantity1216;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int32_t _i_brand_id3565 = (it->second)._i_brand_id3565;
                int32_t _i_class_id3567 = (it->second)._i_class_id3567;
                int32_t _i_category_id3569 = (it->second)._i_category_id3569;
                int32_t _i_manufact_id3571 = (it->second)._i_manufact_id3571;
                int32_t _d_date_sk3580 = tbl_Filter_TD_11126261_output.getInt32(i, 0);
                int32_t _d_year3586 = tbl_Filter_TD_11126261_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_10968541_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_10968541_output.setInt64(r, 1, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_10968541_output.setInt32(r, 2, _ss_quantity1216);
                tbl_JOIN_INNER_TD_10968541_output.setInt64(r, 3, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_10968541_output.setInt32(r, 4, _i_brand_id3565);
                tbl_JOIN_INNER_TD_10968541_output.setInt32(r, 5, _i_class_id3567);
                tbl_JOIN_INNER_TD_10968541_output.setInt32(r, 6, _i_category_id3569);
                tbl_JOIN_INNER_TD_10968541_output.setInt32(r, 7, _i_manufact_id3571);
                tbl_JOIN_INNER_TD_10968541_output.setInt32(r, 8, _d_year3586);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10968541_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10968541_key_rightMajor, SW_JOIN_INNER_TD_10968541_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_11126261_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk3580_k = tbl_Filter_TD_11126261_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_10968541_key_rightMajor keyA{_d_date_sk3580_k};
            int32_t _d_date_sk3580 = tbl_Filter_TD_11126261_output.getInt32(i, 0);
            int32_t _d_year3586 = tbl_Filter_TD_11126261_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_10968541_payload_rightMajor payloadA{_d_date_sk3580, _d_year3586};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_11868273_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_JOIN_INNER_TD_11868273_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10968541_key_rightMajor{_ss_sold_date_sk1206_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk3580 = (it->second)._d_date_sk3580;
                int32_t _d_year3586 = (it->second)._d_year3586;
                int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_11868273_output.getInt32(i, 0);
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_11868273_output.getInt32(i, 1);
                int64_t _ss_ticket_number1215L = tbl_JOIN_INNER_TD_11868273_output.getInt64(i, 2);
                int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_11868273_output.getInt32(i, 3);
                int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_11868273_output.getInt64(i, 4);
                int32_t _i_brand_id3565 = tbl_JOIN_INNER_TD_11868273_output.getInt32(i, 5);
                int32_t _i_class_id3567 = tbl_JOIN_INNER_TD_11868273_output.getInt32(i, 6);
                int32_t _i_category_id3569 = tbl_JOIN_INNER_TD_11868273_output.getInt32(i, 7);
                int32_t _i_manufact_id3571 = tbl_JOIN_INNER_TD_11868273_output.getInt32(i, 8);
                tbl_JOIN_INNER_TD_10968541_output.setInt32(r, 8, _d_year3586);
                tbl_JOIN_INNER_TD_10968541_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_10968541_output.setInt64(r, 1, _ss_ticket_number1215L);
                tbl_JOIN_INNER_TD_10968541_output.setInt32(r, 2, _ss_quantity1216);
                tbl_JOIN_INNER_TD_10968541_output.setInt64(r, 3, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_10968541_output.setInt32(r, 4, _i_brand_id3565);
                tbl_JOIN_INNER_TD_10968541_output.setInt32(r, 5, _i_class_id3567);
                tbl_JOIN_INNER_TD_10968541_output.setInt32(r, 6, _i_category_id3569);
                tbl_JOIN_INNER_TD_10968541_output.setInt32(r, 7, _i_manufact_id3571);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10968541_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_10968541_output #Row: " << tbl_JOIN_INNER_TD_10968541_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10619629(Table &tbl_SerializeFromObject_TD_11308853_input, Table &tbl_Filter_TD_10619629_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cr_order_number#1039L) AND isnotnull(cr_item_sk#1025)))
    // Input: ListBuffer(cr_item_sk#1025, cr_order_number#1039L, cr_return_quantity#1040, cr_return_amount#1041)
    // Output: ListBuffer(cr_item_sk#1025, cr_order_number#1039L, cr_return_quantity#1040, cr_return_amount#1041)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11308853_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _cr_order_number1039L = tbl_SerializeFromObject_TD_11308853_input.getInt64(i, 1);
        int32_t _cr_item_sk1025 = tbl_SerializeFromObject_TD_11308853_input.getInt32(i, 0);
        if ((_cr_order_number1039L!= 0) && (_cr_item_sk1025!= 0)) {
            int32_t _cr_item_sk1025_t = tbl_SerializeFromObject_TD_11308853_input.getInt32(i, 0);
            tbl_Filter_TD_10619629_output.setInt32(r, 0, _cr_item_sk1025_t);
            int64_t _cr_order_number1039L_t = tbl_SerializeFromObject_TD_11308853_input.getInt64(i, 1);
            tbl_Filter_TD_10619629_output.setInt64(r, 1, _cr_order_number1039L_t);
            int32_t _cr_return_quantity1040_t = tbl_SerializeFromObject_TD_11308853_input.getInt32(i, 2);
            tbl_Filter_TD_10619629_output.setInt32(r, 2, _cr_return_quantity1040_t);
            int64_t _cr_return_amount1041_t = tbl_SerializeFromObject_TD_11308853_input.getInt64(i, 3);
            tbl_Filter_TD_10619629_output.setInt64(r, 3, _cr_return_amount1041_t);
            r++;
        }
    }
    tbl_Filter_TD_10619629_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10619629_output #Row: " << tbl_Filter_TD_10619629_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_10170990_key_leftMajor {
    int32_t _cs_sold_date_sk1104;
    bool operator==(const SW_JOIN_INNER_TD_10170990_key_leftMajor& other) const {
        return ((_cs_sold_date_sk1104 == other._cs_sold_date_sk1104));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10170990_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10170990_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_sold_date_sk1104));
    }
};
}
struct SW_JOIN_INNER_TD_10170990_payload_leftMajor {
    int32_t _cs_sold_date_sk1104;
    int32_t _cs_item_sk1119;
    int64_t _cs_order_number1121L;
    int32_t _cs_quantity1122;
    int64_t _cs_ext_sales_price1127;
    int32_t _i_brand_id235;
    int32_t _i_class_id237;
    int32_t _i_category_id239;
    int32_t _i_manufact_id241;
};
struct SW_JOIN_INNER_TD_10170990_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_10170990_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_10170990_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_10170990_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_10170990_payload_rightMajor {
    int32_t _d_date_sk120;
    int32_t _d_year126;
};
void SW_JOIN_INNER_TD_10170990(Table &tbl_JOIN_INNER_TD_11627645_output, Table &tbl_Filter_TD_11781310_output, Table &tbl_JOIN_INNER_TD_10170990_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((d_date_sk#120 = cs_sold_date_sk#1104))
    // Left Table: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119, cs_order_number#1121L, cs_quantity#1122, cs_ext_sales_price#1127, i_brand_id#235, i_class_id#237, i_category_id#239, i_manufact_id#241)
    // Right Table: ListBuffer(d_date_sk#120, d_year#126)
    // Output Table: ListBuffer(cs_item_sk#1119, cs_order_number#1121L, cs_quantity#1122, cs_ext_sales_price#1127, i_brand_id#235, i_class_id#237, i_category_id#239, i_manufact_id#241, d_year#126)
    int left_nrow = tbl_JOIN_INNER_TD_11627645_output.getNumRow();
    int right_nrow = tbl_Filter_TD_11781310_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10170990_key_leftMajor, SW_JOIN_INNER_TD_10170990_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_11627645_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_sold_date_sk1104_k = tbl_JOIN_INNER_TD_11627645_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_10170990_key_leftMajor keyA{_cs_sold_date_sk1104_k};
            int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_11627645_output.getInt32(i, 0);
            int32_t _cs_item_sk1119 = tbl_JOIN_INNER_TD_11627645_output.getInt32(i, 1);
            int64_t _cs_order_number1121L = tbl_JOIN_INNER_TD_11627645_output.getInt64(i, 2);
            int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_11627645_output.getInt32(i, 3);
            int64_t _cs_ext_sales_price1127 = tbl_JOIN_INNER_TD_11627645_output.getInt64(i, 4);
            int32_t _i_brand_id235 = tbl_JOIN_INNER_TD_11627645_output.getInt32(i, 5);
            int32_t _i_class_id237 = tbl_JOIN_INNER_TD_11627645_output.getInt32(i, 6);
            int32_t _i_category_id239 = tbl_JOIN_INNER_TD_11627645_output.getInt32(i, 7);
            int32_t _i_manufact_id241 = tbl_JOIN_INNER_TD_11627645_output.getInt32(i, 8);
            SW_JOIN_INNER_TD_10170990_payload_leftMajor payloadA{_cs_sold_date_sk1104, _cs_item_sk1119, _cs_order_number1121L, _cs_quantity1122, _cs_ext_sales_price1127, _i_brand_id235, _i_class_id237, _i_category_id239, _i_manufact_id241};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_11781310_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_11781310_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10170990_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk1104 = (it->second)._cs_sold_date_sk1104;
                int32_t _cs_item_sk1119 = (it->second)._cs_item_sk1119;
                int64_t _cs_order_number1121L = (it->second)._cs_order_number1121L;
                int32_t _cs_quantity1122 = (it->second)._cs_quantity1122;
                int64_t _cs_ext_sales_price1127 = (it->second)._cs_ext_sales_price1127;
                int32_t _i_brand_id235 = (it->second)._i_brand_id235;
                int32_t _i_class_id237 = (it->second)._i_class_id237;
                int32_t _i_category_id239 = (it->second)._i_category_id239;
                int32_t _i_manufact_id241 = (it->second)._i_manufact_id241;
                int32_t _d_date_sk120 = tbl_Filter_TD_11781310_output.getInt32(i, 0);
                int32_t _d_year126 = tbl_Filter_TD_11781310_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_10170990_output.setInt32(r, 0, _cs_item_sk1119);
                tbl_JOIN_INNER_TD_10170990_output.setInt64(r, 1, _cs_order_number1121L);
                tbl_JOIN_INNER_TD_10170990_output.setInt32(r, 2, _cs_quantity1122);
                tbl_JOIN_INNER_TD_10170990_output.setInt64(r, 3, _cs_ext_sales_price1127);
                tbl_JOIN_INNER_TD_10170990_output.setInt32(r, 4, _i_brand_id235);
                tbl_JOIN_INNER_TD_10170990_output.setInt32(r, 5, _i_class_id237);
                tbl_JOIN_INNER_TD_10170990_output.setInt32(r, 6, _i_category_id239);
                tbl_JOIN_INNER_TD_10170990_output.setInt32(r, 7, _i_manufact_id241);
                tbl_JOIN_INNER_TD_10170990_output.setInt32(r, 8, _d_year126);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10170990_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_10170990_key_rightMajor, SW_JOIN_INNER_TD_10170990_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_11781310_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_11781310_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_10170990_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_11781310_output.getInt32(i, 0);
            int32_t _d_year126 = tbl_Filter_TD_11781310_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_10170990_payload_rightMajor payloadA{_d_date_sk120, _d_year126};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_11627645_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_sold_date_sk1104_k = tbl_JOIN_INNER_TD_11627645_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_10170990_key_rightMajor{_cs_sold_date_sk1104_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _d_year126 = (it->second)._d_year126;
                int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_11627645_output.getInt32(i, 0);
                int32_t _cs_item_sk1119 = tbl_JOIN_INNER_TD_11627645_output.getInt32(i, 1);
                int64_t _cs_order_number1121L = tbl_JOIN_INNER_TD_11627645_output.getInt64(i, 2);
                int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_11627645_output.getInt32(i, 3);
                int64_t _cs_ext_sales_price1127 = tbl_JOIN_INNER_TD_11627645_output.getInt64(i, 4);
                int32_t _i_brand_id235 = tbl_JOIN_INNER_TD_11627645_output.getInt32(i, 5);
                int32_t _i_class_id237 = tbl_JOIN_INNER_TD_11627645_output.getInt32(i, 6);
                int32_t _i_category_id239 = tbl_JOIN_INNER_TD_11627645_output.getInt32(i, 7);
                int32_t _i_manufact_id241 = tbl_JOIN_INNER_TD_11627645_output.getInt32(i, 8);
                tbl_JOIN_INNER_TD_10170990_output.setInt32(r, 8, _d_year126);
                tbl_JOIN_INNER_TD_10170990_output.setInt32(r, 0, _cs_item_sk1119);
                tbl_JOIN_INNER_TD_10170990_output.setInt64(r, 1, _cs_order_number1121L);
                tbl_JOIN_INNER_TD_10170990_output.setInt32(r, 2, _cs_quantity1122);
                tbl_JOIN_INNER_TD_10170990_output.setInt64(r, 3, _cs_ext_sales_price1127);
                tbl_JOIN_INNER_TD_10170990_output.setInt32(r, 4, _i_brand_id235);
                tbl_JOIN_INNER_TD_10170990_output.setInt32(r, 5, _i_class_id237);
                tbl_JOIN_INNER_TD_10170990_output.setInt32(r, 6, _i_category_id239);
                tbl_JOIN_INNER_TD_10170990_output.setInt32(r, 7, _i_manufact_id241);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_10170990_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_10170990_output #Row: " << tbl_JOIN_INNER_TD_10170990_output.getNumRow() << std::endl;
}

struct SW_JOIN_LEFTOUTER_TD_9282254_key {
    int64_t _wr_order_number4727L;
    int32_t _wr_item_sk4716;
    bool operator==(const SW_JOIN_LEFTOUTER_TD_9282254_key& other) const {
        return ((_wr_order_number4727L == other._wr_order_number4727L) && (_wr_item_sk4716 == other._wr_item_sk4716));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTOUTER_TD_9282254_key> {
    std::size_t operator() (const SW_JOIN_LEFTOUTER_TD_9282254_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int64_t>()(k._wr_order_number4727L)) + (hash<int32_t>()(k._wr_item_sk4716));
    }
};
}
struct SW_JOIN_LEFTOUTER_TD_9282254_payload {
    int32_t _wr_item_sk4716;
    int64_t _wr_order_number4727L;
    int32_t _wr_return_quantity4728;
    int64_t _wr_return_amt4729;
};
void SW_JOIN_LEFTOUTER_TD_9282254(Table &tbl_JOIN_INNER_TD_10158452_output, Table &tbl_Filter_TD_10776215_output, Table &tbl_JOIN_LEFTOUTER_TD_9282254_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTOUTER
    // Operation: ListBuffer(((ws_order_number#4647L = wr_order_number#4727L) AND (ws_item_sk#4633 = wr_item_sk#4716)))
    // Left Table: ListBuffer(ws_item_sk#4633, ws_order_number#4647L, ws_quantity#4648, ws_ext_sales_price#4653, i_brand_id#4671, i_class_id#4673, i_category_id#4675, i_manufact_id#4677, d_year#4692)
    // Right Table: ListBuffer(wr_item_sk#4716, wr_order_number#4727L, wr_return_quantity#4728, wr_return_amt#4729)
    // Output Table: ListBuffer(d_year#4692, i_brand_id#4671, i_class_id#4673, i_category_id#4675, i_manufact_id#4677, ws_quantity#4648, wr_return_quantity#4728, ws_ext_sales_price#4653, wr_return_amt#4729)
    std::unordered_multimap<SW_JOIN_LEFTOUTER_TD_9282254_key, SW_JOIN_LEFTOUTER_TD_9282254_payload> ht1;
    int nrow1 = tbl_Filter_TD_10776215_output.getNumRow();
    int nrow2 = tbl_JOIN_INNER_TD_10158452_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _wr_order_number4727L_k = tbl_Filter_TD_10776215_output.getInt64(i, 1);
        int32_t _wr_item_sk4716_k = tbl_Filter_TD_10776215_output.getInt32(i, 0);
        SW_JOIN_LEFTOUTER_TD_9282254_key keyA{_wr_order_number4727L_k, _wr_item_sk4716_k};
        int32_t _wr_item_sk4716 = tbl_Filter_TD_10776215_output.getInt32(i, 0);
        int64_t _wr_order_number4727L = tbl_Filter_TD_10776215_output.getInt64(i, 1);
        int32_t _wr_return_quantity4728 = tbl_Filter_TD_10776215_output.getInt32(i, 2);
        int64_t _wr_return_amt4729 = tbl_Filter_TD_10776215_output.getInt64(i, 3);
        SW_JOIN_LEFTOUTER_TD_9282254_payload payloadA{_wr_item_sk4716, _wr_order_number4727L, _wr_return_quantity4728, _wr_return_amt4729};
        ht1.insert(std::make_pair(keyA, payloadA));
    }
    int r = 0;
    for (int i = 0; i < nrow2; i++) {
        int64_t _ws_order_number4647L_k = tbl_JOIN_INNER_TD_10158452_output.getInt64(i, 1);
        int32_t _ws_item_sk4633_k = tbl_JOIN_INNER_TD_10158452_output.getInt32(i, 0);
        auto it = ht1.find(SW_JOIN_LEFTOUTER_TD_9282254_key{_ws_order_number4647L_k, _ws_item_sk4633_k});
        int32_t _ws_item_sk4633 = tbl_JOIN_INNER_TD_10158452_output.getInt32(i, 0);
        int64_t _ws_order_number4647L = tbl_JOIN_INNER_TD_10158452_output.getInt64(i, 1);
        int32_t _ws_quantity4648 = tbl_JOIN_INNER_TD_10158452_output.getInt32(i, 2);
        int64_t _ws_ext_sales_price4653 = tbl_JOIN_INNER_TD_10158452_output.getInt64(i, 3);
        int32_t _i_brand_id4671 = tbl_JOIN_INNER_TD_10158452_output.getInt32(i, 4);
        int32_t _i_class_id4673 = tbl_JOIN_INNER_TD_10158452_output.getInt32(i, 5);
        int32_t _i_category_id4675 = tbl_JOIN_INNER_TD_10158452_output.getInt32(i, 6);
        int32_t _i_manufact_id4677 = tbl_JOIN_INNER_TD_10158452_output.getInt32(i, 7);
        int32_t _d_year4692 = tbl_JOIN_INNER_TD_10158452_output.getInt32(i, 8);
        if (it != ht1.end()) {
            auto its = ht1.equal_range(SW_JOIN_LEFTOUTER_TD_9282254_key{_ws_order_number4647L_k, _ws_item_sk4633_k});
            auto it_it = its.first;
            while (it_it != its.second) {
                int32_t _wr_item_sk4716 = (it_it->second)._wr_item_sk4716;
                int64_t _wr_order_number4727L = (it_it->second)._wr_order_number4727L;
                int32_t _wr_return_quantity4728 = (it_it->second)._wr_return_quantity4728;
                int64_t _wr_return_amt4729 = (it_it->second)._wr_return_amt4729;
                tbl_JOIN_LEFTOUTER_TD_9282254_output.setInt32(r, 6, _wr_return_quantity4728);
                tbl_JOIN_LEFTOUTER_TD_9282254_output.setInt64(r, 8, _wr_return_amt4729);
                tbl_JOIN_LEFTOUTER_TD_9282254_output.setInt32(r, 5, _ws_quantity4648);
                tbl_JOIN_LEFTOUTER_TD_9282254_output.setInt64(r, 7, _ws_ext_sales_price4653);
                tbl_JOIN_LEFTOUTER_TD_9282254_output.setInt32(r, 1, _i_brand_id4671);
                tbl_JOIN_LEFTOUTER_TD_9282254_output.setInt32(r, 2, _i_class_id4673);
                tbl_JOIN_LEFTOUTER_TD_9282254_output.setInt32(r, 3, _i_category_id4675);
                tbl_JOIN_LEFTOUTER_TD_9282254_output.setInt32(r, 4, _i_manufact_id4677);
                tbl_JOIN_LEFTOUTER_TD_9282254_output.setInt32(r, 0, _d_year4692);
                it_it++;
                r++;
            }
        } else {
            tbl_JOIN_LEFTOUTER_TD_9282254_output.setInt32(r, 5, _ws_quantity4648);
            tbl_JOIN_LEFTOUTER_TD_9282254_output.setInt64(r, 7, _ws_ext_sales_price4653);
            tbl_JOIN_LEFTOUTER_TD_9282254_output.setInt32(r, 1, _i_brand_id4671);
            tbl_JOIN_LEFTOUTER_TD_9282254_output.setInt32(r, 2, _i_class_id4673);
            tbl_JOIN_LEFTOUTER_TD_9282254_output.setInt32(r, 3, _i_category_id4675);
            tbl_JOIN_LEFTOUTER_TD_9282254_output.setInt32(r, 4, _i_manufact_id4677);
            tbl_JOIN_LEFTOUTER_TD_9282254_output.setInt32(r, 0, _d_year4692);
            r++;
        }
    }
    tbl_JOIN_LEFTOUTER_TD_9282254_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTOUTER_TD_9282254_output #Row: " << tbl_JOIN_LEFTOUTER_TD_9282254_output.getNumRow() << std::endl;
}

struct SW_JOIN_LEFTOUTER_TD_9732787_key {
    int64_t _sr_ticket_number4619L;
    int32_t _sr_item_sk4612;
    bool operator==(const SW_JOIN_LEFTOUTER_TD_9732787_key& other) const {
        return ((_sr_ticket_number4619L == other._sr_ticket_number4619L) && (_sr_item_sk4612 == other._sr_item_sk4612));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTOUTER_TD_9732787_key> {
    std::size_t operator() (const SW_JOIN_LEFTOUTER_TD_9732787_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int64_t>()(k._sr_ticket_number4619L)) + (hash<int32_t>()(k._sr_item_sk4612));
    }
};
}
struct SW_JOIN_LEFTOUTER_TD_9732787_payload {
    int32_t _sr_item_sk4612;
    int64_t _sr_ticket_number4619L;
    int32_t _sr_return_quantity4620;
    int64_t _sr_return_amt4621;
};
void SW_JOIN_LEFTOUTER_TD_9732787(Table &tbl_JOIN_INNER_TD_10931863_output, Table &tbl_Filter_TD_1021027_output, Table &tbl_JOIN_LEFTOUTER_TD_9732787_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTOUTER
    // Operation: ListBuffer(((ss_ticket_number#4546L = sr_ticket_number#4619L) AND (ss_item_sk#4539 = sr_item_sk#4612)))
    // Left Table: ListBuffer(ss_item_sk#4539, ss_ticket_number#4546L, ss_quantity#4547, ss_ext_sales_price#4552, i_brand_id#4567, i_class_id#4569, i_category_id#4571, i_manufact_id#4573, d_year#4588)
    // Right Table: ListBuffer(sr_item_sk#4612, sr_ticket_number#4619L, sr_return_quantity#4620, sr_return_amt#4621)
    // Output Table: ListBuffer(d_year#4588, i_brand_id#4567, i_class_id#4569, i_category_id#4571, i_manufact_id#4573, ss_quantity#4547, sr_return_quantity#4620, ss_ext_sales_price#4552, sr_return_amt#4621)
    std::unordered_multimap<SW_JOIN_LEFTOUTER_TD_9732787_key, SW_JOIN_LEFTOUTER_TD_9732787_payload> ht1;
    int nrow1 = tbl_Filter_TD_1021027_output.getNumRow();
    int nrow2 = tbl_JOIN_INNER_TD_10931863_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sr_ticket_number4619L_k = tbl_Filter_TD_1021027_output.getInt64(i, 1);
        int32_t _sr_item_sk4612_k = tbl_Filter_TD_1021027_output.getInt32(i, 0);
        SW_JOIN_LEFTOUTER_TD_9732787_key keyA{_sr_ticket_number4619L_k, _sr_item_sk4612_k};
        int32_t _sr_item_sk4612 = tbl_Filter_TD_1021027_output.getInt32(i, 0);
        int64_t _sr_ticket_number4619L = tbl_Filter_TD_1021027_output.getInt64(i, 1);
        int32_t _sr_return_quantity4620 = tbl_Filter_TD_1021027_output.getInt32(i, 2);
        int64_t _sr_return_amt4621 = tbl_Filter_TD_1021027_output.getInt64(i, 3);
        SW_JOIN_LEFTOUTER_TD_9732787_payload payloadA{_sr_item_sk4612, _sr_ticket_number4619L, _sr_return_quantity4620, _sr_return_amt4621};
        ht1.insert(std::make_pair(keyA, payloadA));
    }
    int r = 0;
    for (int i = 0; i < nrow2; i++) {
        int64_t _ss_ticket_number4546L_k = tbl_JOIN_INNER_TD_10931863_output.getInt64(i, 1);
        int32_t _ss_item_sk4539_k = tbl_JOIN_INNER_TD_10931863_output.getInt32(i, 0);
        auto it = ht1.find(SW_JOIN_LEFTOUTER_TD_9732787_key{_ss_ticket_number4546L_k, _ss_item_sk4539_k});
        int32_t _ss_item_sk4539 = tbl_JOIN_INNER_TD_10931863_output.getInt32(i, 0);
        int64_t _ss_ticket_number4546L = tbl_JOIN_INNER_TD_10931863_output.getInt64(i, 1);
        int32_t _ss_quantity4547 = tbl_JOIN_INNER_TD_10931863_output.getInt32(i, 2);
        int64_t _ss_ext_sales_price4552 = tbl_JOIN_INNER_TD_10931863_output.getInt64(i, 3);
        int32_t _i_brand_id4567 = tbl_JOIN_INNER_TD_10931863_output.getInt32(i, 4);
        int32_t _i_class_id4569 = tbl_JOIN_INNER_TD_10931863_output.getInt32(i, 5);
        int32_t _i_category_id4571 = tbl_JOIN_INNER_TD_10931863_output.getInt32(i, 6);
        int32_t _i_manufact_id4573 = tbl_JOIN_INNER_TD_10931863_output.getInt32(i, 7);
        int32_t _d_year4588 = tbl_JOIN_INNER_TD_10931863_output.getInt32(i, 8);
        if (it != ht1.end()) {
            auto its = ht1.equal_range(SW_JOIN_LEFTOUTER_TD_9732787_key{_ss_ticket_number4546L_k, _ss_item_sk4539_k});
            auto it_it = its.first;
            while (it_it != its.second) {
                int32_t _sr_item_sk4612 = (it_it->second)._sr_item_sk4612;
                int64_t _sr_ticket_number4619L = (it_it->second)._sr_ticket_number4619L;
                int32_t _sr_return_quantity4620 = (it_it->second)._sr_return_quantity4620;
                int64_t _sr_return_amt4621 = (it_it->second)._sr_return_amt4621;
                tbl_JOIN_LEFTOUTER_TD_9732787_output.setInt32(r, 6, _sr_return_quantity4620);
                tbl_JOIN_LEFTOUTER_TD_9732787_output.setInt64(r, 8, _sr_return_amt4621);
                tbl_JOIN_LEFTOUTER_TD_9732787_output.setInt32(r, 5, _ss_quantity4547);
                tbl_JOIN_LEFTOUTER_TD_9732787_output.setInt64(r, 7, _ss_ext_sales_price4552);
                tbl_JOIN_LEFTOUTER_TD_9732787_output.setInt32(r, 1, _i_brand_id4567);
                tbl_JOIN_LEFTOUTER_TD_9732787_output.setInt32(r, 2, _i_class_id4569);
                tbl_JOIN_LEFTOUTER_TD_9732787_output.setInt32(r, 3, _i_category_id4571);
                tbl_JOIN_LEFTOUTER_TD_9732787_output.setInt32(r, 4, _i_manufact_id4573);
                tbl_JOIN_LEFTOUTER_TD_9732787_output.setInt32(r, 0, _d_year4588);
                it_it++;
                r++;
            }
        } else {
            tbl_JOIN_LEFTOUTER_TD_9732787_output.setInt32(r, 5, _ss_quantity4547);
            tbl_JOIN_LEFTOUTER_TD_9732787_output.setInt64(r, 7, _ss_ext_sales_price4552);
            tbl_JOIN_LEFTOUTER_TD_9732787_output.setInt32(r, 1, _i_brand_id4567);
            tbl_JOIN_LEFTOUTER_TD_9732787_output.setInt32(r, 2, _i_class_id4569);
            tbl_JOIN_LEFTOUTER_TD_9732787_output.setInt32(r, 3, _i_category_id4571);
            tbl_JOIN_LEFTOUTER_TD_9732787_output.setInt32(r, 4, _i_manufact_id4573);
            tbl_JOIN_LEFTOUTER_TD_9732787_output.setInt32(r, 0, _d_year4588);
            r++;
        }
    }
    tbl_JOIN_LEFTOUTER_TD_9732787_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTOUTER_TD_9732787_output #Row: " << tbl_JOIN_LEFTOUTER_TD_9732787_output.getNumRow() << std::endl;
}

struct SW_JOIN_LEFTOUTER_TD_9932501_key {
    int64_t _cr_order_number4526L;
    int32_t _cr_item_sk4512;
    bool operator==(const SW_JOIN_LEFTOUTER_TD_9932501_key& other) const {
        return ((_cr_order_number4526L == other._cr_order_number4526L) && (_cr_item_sk4512 == other._cr_item_sk4512));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTOUTER_TD_9932501_key> {
    std::size_t operator() (const SW_JOIN_LEFTOUTER_TD_9932501_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int64_t>()(k._cr_order_number4526L)) + (hash<int32_t>()(k._cr_item_sk4512));
    }
};
}
struct SW_JOIN_LEFTOUTER_TD_9932501_payload {
    int32_t _cr_item_sk4512;
    int64_t _cr_order_number4526L;
    int32_t _cr_return_quantity4527;
    int64_t _cr_return_amount4528;
};
void SW_JOIN_LEFTOUTER_TD_9932501(Table &tbl_JOIN_INNER_TD_10795304_output, Table &tbl_Filter_TD_1062905_output, Table &tbl_JOIN_LEFTOUTER_TD_9932501_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTOUTER
    // Operation: ListBuffer(((cs_order_number#4443L = cr_order_number#4526L) AND (cs_item_sk#4441 = cr_item_sk#4512)))
    // Left Table: ListBuffer(cs_item_sk#4441, cs_order_number#4443L, cs_quantity#4444, cs_ext_sales_price#4449, i_brand_id#4467, i_class_id#4469, i_category_id#4471, i_manufact_id#4473, d_year#4488)
    // Right Table: ListBuffer(cr_item_sk#4512, cr_order_number#4526L, cr_return_quantity#4527, cr_return_amount#4528)
    // Output Table: ListBuffer(d_year#4488, i_brand_id#4467, i_class_id#4469, i_category_id#4471, i_manufact_id#4473, cs_quantity#4444, cr_return_quantity#4527, cs_ext_sales_price#4449, cr_return_amount#4528)
    std::unordered_multimap<SW_JOIN_LEFTOUTER_TD_9932501_key, SW_JOIN_LEFTOUTER_TD_9932501_payload> ht1;
    int nrow1 = tbl_Filter_TD_1062905_output.getNumRow();
    int nrow2 = tbl_JOIN_INNER_TD_10795304_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _cr_order_number4526L_k = tbl_Filter_TD_1062905_output.getInt64(i, 1);
        int32_t _cr_item_sk4512_k = tbl_Filter_TD_1062905_output.getInt32(i, 0);
        SW_JOIN_LEFTOUTER_TD_9932501_key keyA{_cr_order_number4526L_k, _cr_item_sk4512_k};
        int32_t _cr_item_sk4512 = tbl_Filter_TD_1062905_output.getInt32(i, 0);
        int64_t _cr_order_number4526L = tbl_Filter_TD_1062905_output.getInt64(i, 1);
        int32_t _cr_return_quantity4527 = tbl_Filter_TD_1062905_output.getInt32(i, 2);
        int64_t _cr_return_amount4528 = tbl_Filter_TD_1062905_output.getInt64(i, 3);
        SW_JOIN_LEFTOUTER_TD_9932501_payload payloadA{_cr_item_sk4512, _cr_order_number4526L, _cr_return_quantity4527, _cr_return_amount4528};
        ht1.insert(std::make_pair(keyA, payloadA));
    }
    int r = 0;
    for (int i = 0; i < nrow2; i++) {
        int64_t _cs_order_number4443L_k = tbl_JOIN_INNER_TD_10795304_output.getInt64(i, 1);
        int32_t _cs_item_sk4441_k = tbl_JOIN_INNER_TD_10795304_output.getInt32(i, 0);
        auto it = ht1.find(SW_JOIN_LEFTOUTER_TD_9932501_key{_cs_order_number4443L_k, _cs_item_sk4441_k});
        int32_t _cs_item_sk4441 = tbl_JOIN_INNER_TD_10795304_output.getInt32(i, 0);
        int64_t _cs_order_number4443L = tbl_JOIN_INNER_TD_10795304_output.getInt64(i, 1);
        int32_t _cs_quantity4444 = tbl_JOIN_INNER_TD_10795304_output.getInt32(i, 2);
        int64_t _cs_ext_sales_price4449 = tbl_JOIN_INNER_TD_10795304_output.getInt64(i, 3);
        int32_t _i_brand_id4467 = tbl_JOIN_INNER_TD_10795304_output.getInt32(i, 4);
        int32_t _i_class_id4469 = tbl_JOIN_INNER_TD_10795304_output.getInt32(i, 5);
        int32_t _i_category_id4471 = tbl_JOIN_INNER_TD_10795304_output.getInt32(i, 6);
        int32_t _i_manufact_id4473 = tbl_JOIN_INNER_TD_10795304_output.getInt32(i, 7);
        int32_t _d_year4488 = tbl_JOIN_INNER_TD_10795304_output.getInt32(i, 8);
        if (it != ht1.end()) {
            auto its = ht1.equal_range(SW_JOIN_LEFTOUTER_TD_9932501_key{_cs_order_number4443L_k, _cs_item_sk4441_k});
            auto it_it = its.first;
            while (it_it != its.second) {
                int32_t _cr_item_sk4512 = (it_it->second)._cr_item_sk4512;
                int64_t _cr_order_number4526L = (it_it->second)._cr_order_number4526L;
                int32_t _cr_return_quantity4527 = (it_it->second)._cr_return_quantity4527;
                int64_t _cr_return_amount4528 = (it_it->second)._cr_return_amount4528;
                tbl_JOIN_LEFTOUTER_TD_9932501_output.setInt32(r, 6, _cr_return_quantity4527);
                tbl_JOIN_LEFTOUTER_TD_9932501_output.setInt64(r, 8, _cr_return_amount4528);
                tbl_JOIN_LEFTOUTER_TD_9932501_output.setInt32(r, 5, _cs_quantity4444);
                tbl_JOIN_LEFTOUTER_TD_9932501_output.setInt64(r, 7, _cs_ext_sales_price4449);
                tbl_JOIN_LEFTOUTER_TD_9932501_output.setInt32(r, 1, _i_brand_id4467);
                tbl_JOIN_LEFTOUTER_TD_9932501_output.setInt32(r, 2, _i_class_id4469);
                tbl_JOIN_LEFTOUTER_TD_9932501_output.setInt32(r, 3, _i_category_id4471);
                tbl_JOIN_LEFTOUTER_TD_9932501_output.setInt32(r, 4, _i_manufact_id4473);
                tbl_JOIN_LEFTOUTER_TD_9932501_output.setInt32(r, 0, _d_year4488);
                it_it++;
                r++;
            }
        } else {
            tbl_JOIN_LEFTOUTER_TD_9932501_output.setInt32(r, 5, _cs_quantity4444);
            tbl_JOIN_LEFTOUTER_TD_9932501_output.setInt64(r, 7, _cs_ext_sales_price4449);
            tbl_JOIN_LEFTOUTER_TD_9932501_output.setInt32(r, 1, _i_brand_id4467);
            tbl_JOIN_LEFTOUTER_TD_9932501_output.setInt32(r, 2, _i_class_id4469);
            tbl_JOIN_LEFTOUTER_TD_9932501_output.setInt32(r, 3, _i_category_id4471);
            tbl_JOIN_LEFTOUTER_TD_9932501_output.setInt32(r, 4, _i_manufact_id4473);
            tbl_JOIN_LEFTOUTER_TD_9932501_output.setInt32(r, 0, _d_year4488);
            r++;
        }
    }
    tbl_JOIN_LEFTOUTER_TD_9932501_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTOUTER_TD_9932501_output #Row: " << tbl_JOIN_LEFTOUTER_TD_9932501_output.getNumRow() << std::endl;
}

struct SW_JOIN_LEFTOUTER_TD_9408405_key {
    int64_t _wr_order_number844L;
    int32_t _wr_item_sk833;
    bool operator==(const SW_JOIN_LEFTOUTER_TD_9408405_key& other) const {
        return ((_wr_order_number844L == other._wr_order_number844L) && (_wr_item_sk833 == other._wr_item_sk833));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTOUTER_TD_9408405_key> {
    std::size_t operator() (const SW_JOIN_LEFTOUTER_TD_9408405_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int64_t>()(k._wr_order_number844L)) + (hash<int32_t>()(k._wr_item_sk833));
    }
};
}
struct SW_JOIN_LEFTOUTER_TD_9408405_payload {
    int32_t _wr_item_sk833;
    int64_t _wr_order_number844L;
    int32_t _wr_return_quantity845;
    int64_t _wr_return_amt846;
};
void SW_JOIN_LEFTOUTER_TD_9408405(Table &tbl_JOIN_INNER_TD_10636324_output, Table &tbl_Filter_TD_10332983_output, Table &tbl_JOIN_LEFTOUTER_TD_9408405_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTOUTER
    // Operation: ListBuffer(((ws_order_number#746L = wr_order_number#844L) AND (ws_item_sk#732 = wr_item_sk#833)))
    // Left Table: ListBuffer(ws_item_sk#732, ws_order_number#746L, ws_quantity#747, ws_ext_sales_price#752, i_brand_id#3615, i_class_id#3617, i_category_id#3619, i_manufact_id#3621, d_year#3636)
    // Right Table: ListBuffer(wr_item_sk#833, wr_order_number#844L, wr_return_quantity#845, wr_return_amt#846)
    // Output Table: ListBuffer(d_year#3636, i_brand_id#3615, i_class_id#3617, i_category_id#3619, i_manufact_id#3621, ws_quantity#747, wr_return_quantity#845, ws_ext_sales_price#752, wr_return_amt#846)
    std::unordered_multimap<SW_JOIN_LEFTOUTER_TD_9408405_key, SW_JOIN_LEFTOUTER_TD_9408405_payload> ht1;
    int nrow1 = tbl_Filter_TD_10332983_output.getNumRow();
    int nrow2 = tbl_JOIN_INNER_TD_10636324_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _wr_order_number844L_k = tbl_Filter_TD_10332983_output.getInt64(i, 1);
        int32_t _wr_item_sk833_k = tbl_Filter_TD_10332983_output.getInt32(i, 0);
        SW_JOIN_LEFTOUTER_TD_9408405_key keyA{_wr_order_number844L_k, _wr_item_sk833_k};
        int32_t _wr_item_sk833 = tbl_Filter_TD_10332983_output.getInt32(i, 0);
        int64_t _wr_order_number844L = tbl_Filter_TD_10332983_output.getInt64(i, 1);
        int32_t _wr_return_quantity845 = tbl_Filter_TD_10332983_output.getInt32(i, 2);
        int64_t _wr_return_amt846 = tbl_Filter_TD_10332983_output.getInt64(i, 3);
        SW_JOIN_LEFTOUTER_TD_9408405_payload payloadA{_wr_item_sk833, _wr_order_number844L, _wr_return_quantity845, _wr_return_amt846};
        ht1.insert(std::make_pair(keyA, payloadA));
    }
    int r = 0;
    for (int i = 0; i < nrow2; i++) {
        int64_t _ws_order_number746L_k = tbl_JOIN_INNER_TD_10636324_output.getInt64(i, 1);
        int32_t _ws_item_sk732_k = tbl_JOIN_INNER_TD_10636324_output.getInt32(i, 0);
        auto it = ht1.find(SW_JOIN_LEFTOUTER_TD_9408405_key{_ws_order_number746L_k, _ws_item_sk732_k});
        int32_t _ws_item_sk732 = tbl_JOIN_INNER_TD_10636324_output.getInt32(i, 0);
        int64_t _ws_order_number746L = tbl_JOIN_INNER_TD_10636324_output.getInt64(i, 1);
        int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_10636324_output.getInt32(i, 2);
        int64_t _ws_ext_sales_price752 = tbl_JOIN_INNER_TD_10636324_output.getInt64(i, 3);
        int32_t _i_brand_id3615 = tbl_JOIN_INNER_TD_10636324_output.getInt32(i, 4);
        int32_t _i_class_id3617 = tbl_JOIN_INNER_TD_10636324_output.getInt32(i, 5);
        int32_t _i_category_id3619 = tbl_JOIN_INNER_TD_10636324_output.getInt32(i, 6);
        int32_t _i_manufact_id3621 = tbl_JOIN_INNER_TD_10636324_output.getInt32(i, 7);
        int32_t _d_year3636 = tbl_JOIN_INNER_TD_10636324_output.getInt32(i, 8);
        if (it != ht1.end()) {
            auto its = ht1.equal_range(SW_JOIN_LEFTOUTER_TD_9408405_key{_ws_order_number746L_k, _ws_item_sk732_k});
            auto it_it = its.first;
            while (it_it != its.second) {
                int32_t _wr_item_sk833 = (it_it->second)._wr_item_sk833;
                int64_t _wr_order_number844L = (it_it->second)._wr_order_number844L;
                int32_t _wr_return_quantity845 = (it_it->second)._wr_return_quantity845;
                int64_t _wr_return_amt846 = (it_it->second)._wr_return_amt846;
                tbl_JOIN_LEFTOUTER_TD_9408405_output.setInt32(r, 6, _wr_return_quantity845);
                tbl_JOIN_LEFTOUTER_TD_9408405_output.setInt64(r, 8, _wr_return_amt846);
                tbl_JOIN_LEFTOUTER_TD_9408405_output.setInt32(r, 5, _ws_quantity747);
                tbl_JOIN_LEFTOUTER_TD_9408405_output.setInt64(r, 7, _ws_ext_sales_price752);
                tbl_JOIN_LEFTOUTER_TD_9408405_output.setInt32(r, 1, _i_brand_id3615);
                tbl_JOIN_LEFTOUTER_TD_9408405_output.setInt32(r, 2, _i_class_id3617);
                tbl_JOIN_LEFTOUTER_TD_9408405_output.setInt32(r, 3, _i_category_id3619);
                tbl_JOIN_LEFTOUTER_TD_9408405_output.setInt32(r, 4, _i_manufact_id3621);
                tbl_JOIN_LEFTOUTER_TD_9408405_output.setInt32(r, 0, _d_year3636);
                it_it++;
                r++;
            }
        } else {
            tbl_JOIN_LEFTOUTER_TD_9408405_output.setInt32(r, 5, _ws_quantity747);
            tbl_JOIN_LEFTOUTER_TD_9408405_output.setInt64(r, 7, _ws_ext_sales_price752);
            tbl_JOIN_LEFTOUTER_TD_9408405_output.setInt32(r, 1, _i_brand_id3615);
            tbl_JOIN_LEFTOUTER_TD_9408405_output.setInt32(r, 2, _i_class_id3617);
            tbl_JOIN_LEFTOUTER_TD_9408405_output.setInt32(r, 3, _i_category_id3619);
            tbl_JOIN_LEFTOUTER_TD_9408405_output.setInt32(r, 4, _i_manufact_id3621);
            tbl_JOIN_LEFTOUTER_TD_9408405_output.setInt32(r, 0, _d_year3636);
            r++;
        }
    }
    tbl_JOIN_LEFTOUTER_TD_9408405_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTOUTER_TD_9408405_output #Row: " << tbl_JOIN_LEFTOUTER_TD_9408405_output.getNumRow() << std::endl;
}

struct SW_JOIN_LEFTOUTER_TD_9954081_key {
    int64_t _sr_ticket_number678L;
    int32_t _sr_item_sk671;
    bool operator==(const SW_JOIN_LEFTOUTER_TD_9954081_key& other) const {
        return ((_sr_ticket_number678L == other._sr_ticket_number678L) && (_sr_item_sk671 == other._sr_item_sk671));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTOUTER_TD_9954081_key> {
    std::size_t operator() (const SW_JOIN_LEFTOUTER_TD_9954081_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int64_t>()(k._sr_ticket_number678L)) + (hash<int32_t>()(k._sr_item_sk671));
    }
};
}
struct SW_JOIN_LEFTOUTER_TD_9954081_payload {
    int32_t _sr_item_sk671;
    int64_t _sr_ticket_number678L;
    int32_t _sr_return_quantity679;
    int64_t _sr_return_amt680;
};
void SW_JOIN_LEFTOUTER_TD_9954081(Table &tbl_JOIN_INNER_TD_10968541_output, Table &tbl_Filter_TD_10273351_output, Table &tbl_JOIN_LEFTOUTER_TD_9954081_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTOUTER
    // Operation: ListBuffer(((ss_ticket_number#1215L = sr_ticket_number#678L) AND (ss_item_sk#1208 = sr_item_sk#671)))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_ticket_number#1215L, ss_quantity#1216, ss_ext_sales_price#1221, i_brand_id#3565, i_class_id#3567, i_category_id#3569, i_manufact_id#3571, d_year#3586)
    // Right Table: ListBuffer(sr_item_sk#671, sr_ticket_number#678L, sr_return_quantity#679, sr_return_amt#680)
    // Output Table: ListBuffer(d_year#3586, i_brand_id#3565, i_class_id#3567, i_category_id#3569, i_manufact_id#3571, ss_quantity#1216, sr_return_quantity#679, ss_ext_sales_price#1221, sr_return_amt#680)
    std::unordered_multimap<SW_JOIN_LEFTOUTER_TD_9954081_key, SW_JOIN_LEFTOUTER_TD_9954081_payload> ht1;
    int nrow1 = tbl_Filter_TD_10273351_output.getNumRow();
    int nrow2 = tbl_JOIN_INNER_TD_10968541_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sr_ticket_number678L_k = tbl_Filter_TD_10273351_output.getInt64(i, 1);
        int32_t _sr_item_sk671_k = tbl_Filter_TD_10273351_output.getInt32(i, 0);
        SW_JOIN_LEFTOUTER_TD_9954081_key keyA{_sr_ticket_number678L_k, _sr_item_sk671_k};
        int32_t _sr_item_sk671 = tbl_Filter_TD_10273351_output.getInt32(i, 0);
        int64_t _sr_ticket_number678L = tbl_Filter_TD_10273351_output.getInt64(i, 1);
        int32_t _sr_return_quantity679 = tbl_Filter_TD_10273351_output.getInt32(i, 2);
        int64_t _sr_return_amt680 = tbl_Filter_TD_10273351_output.getInt64(i, 3);
        SW_JOIN_LEFTOUTER_TD_9954081_payload payloadA{_sr_item_sk671, _sr_ticket_number678L, _sr_return_quantity679, _sr_return_amt680};
        ht1.insert(std::make_pair(keyA, payloadA));
    }
    int r = 0;
    for (int i = 0; i < nrow2; i++) {
        int64_t _ss_ticket_number1215L_k = tbl_JOIN_INNER_TD_10968541_output.getInt64(i, 1);
        int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_10968541_output.getInt32(i, 0);
        auto it = ht1.find(SW_JOIN_LEFTOUTER_TD_9954081_key{_ss_ticket_number1215L_k, _ss_item_sk1208_k});
        int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_10968541_output.getInt32(i, 0);
        int64_t _ss_ticket_number1215L = tbl_JOIN_INNER_TD_10968541_output.getInt64(i, 1);
        int32_t _ss_quantity1216 = tbl_JOIN_INNER_TD_10968541_output.getInt32(i, 2);
        int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_10968541_output.getInt64(i, 3);
        int32_t _i_brand_id3565 = tbl_JOIN_INNER_TD_10968541_output.getInt32(i, 4);
        int32_t _i_class_id3567 = tbl_JOIN_INNER_TD_10968541_output.getInt32(i, 5);
        int32_t _i_category_id3569 = tbl_JOIN_INNER_TD_10968541_output.getInt32(i, 6);
        int32_t _i_manufact_id3571 = tbl_JOIN_INNER_TD_10968541_output.getInt32(i, 7);
        int32_t _d_year3586 = tbl_JOIN_INNER_TD_10968541_output.getInt32(i, 8);
        if (it != ht1.end()) {
            auto its = ht1.equal_range(SW_JOIN_LEFTOUTER_TD_9954081_key{_ss_ticket_number1215L_k, _ss_item_sk1208_k});
            auto it_it = its.first;
            while (it_it != its.second) {
                int32_t _sr_item_sk671 = (it_it->second)._sr_item_sk671;
                int64_t _sr_ticket_number678L = (it_it->second)._sr_ticket_number678L;
                int32_t _sr_return_quantity679 = (it_it->second)._sr_return_quantity679;
                int64_t _sr_return_amt680 = (it_it->second)._sr_return_amt680;
                tbl_JOIN_LEFTOUTER_TD_9954081_output.setInt32(r, 6, _sr_return_quantity679);
                tbl_JOIN_LEFTOUTER_TD_9954081_output.setInt64(r, 8, _sr_return_amt680);
                tbl_JOIN_LEFTOUTER_TD_9954081_output.setInt32(r, 5, _ss_quantity1216);
                tbl_JOIN_LEFTOUTER_TD_9954081_output.setInt64(r, 7, _ss_ext_sales_price1221);
                tbl_JOIN_LEFTOUTER_TD_9954081_output.setInt32(r, 1, _i_brand_id3565);
                tbl_JOIN_LEFTOUTER_TD_9954081_output.setInt32(r, 2, _i_class_id3567);
                tbl_JOIN_LEFTOUTER_TD_9954081_output.setInt32(r, 3, _i_category_id3569);
                tbl_JOIN_LEFTOUTER_TD_9954081_output.setInt32(r, 4, _i_manufact_id3571);
                tbl_JOIN_LEFTOUTER_TD_9954081_output.setInt32(r, 0, _d_year3586);
                it_it++;
                r++;
            }
        } else {
            tbl_JOIN_LEFTOUTER_TD_9954081_output.setInt32(r, 5, _ss_quantity1216);
            tbl_JOIN_LEFTOUTER_TD_9954081_output.setInt64(r, 7, _ss_ext_sales_price1221);
            tbl_JOIN_LEFTOUTER_TD_9954081_output.setInt32(r, 1, _i_brand_id3565);
            tbl_JOIN_LEFTOUTER_TD_9954081_output.setInt32(r, 2, _i_class_id3567);
            tbl_JOIN_LEFTOUTER_TD_9954081_output.setInt32(r, 3, _i_category_id3569);
            tbl_JOIN_LEFTOUTER_TD_9954081_output.setInt32(r, 4, _i_manufact_id3571);
            tbl_JOIN_LEFTOUTER_TD_9954081_output.setInt32(r, 0, _d_year3586);
            r++;
        }
    }
    tbl_JOIN_LEFTOUTER_TD_9954081_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTOUTER_TD_9954081_output #Row: " << tbl_JOIN_LEFTOUTER_TD_9954081_output.getNumRow() << std::endl;
}

struct SW_JOIN_LEFTOUTER_TD_9685430_key {
    int64_t _cr_order_number1039L;
    int32_t _cr_item_sk1025;
    bool operator==(const SW_JOIN_LEFTOUTER_TD_9685430_key& other) const {
        return ((_cr_order_number1039L == other._cr_order_number1039L) && (_cr_item_sk1025 == other._cr_item_sk1025));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTOUTER_TD_9685430_key> {
    std::size_t operator() (const SW_JOIN_LEFTOUTER_TD_9685430_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int64_t>()(k._cr_order_number1039L)) + (hash<int32_t>()(k._cr_item_sk1025));
    }
};
}
struct SW_JOIN_LEFTOUTER_TD_9685430_payload {
    int32_t _cr_item_sk1025;
    int64_t _cr_order_number1039L;
    int32_t _cr_return_quantity1040;
    int64_t _cr_return_amount1041;
};
void SW_JOIN_LEFTOUTER_TD_9685430(Table &tbl_JOIN_INNER_TD_10170990_output, Table &tbl_Filter_TD_10619629_output, Table &tbl_JOIN_LEFTOUTER_TD_9685430_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTOUTER
    // Operation: ListBuffer(((cs_order_number#1121L = cr_order_number#1039L) AND (cs_item_sk#1119 = cr_item_sk#1025)))
    // Left Table: ListBuffer(cs_item_sk#1119, cs_order_number#1121L, cs_quantity#1122, cs_ext_sales_price#1127, i_brand_id#235, i_class_id#237, i_category_id#239, i_manufact_id#241, d_year#126)
    // Right Table: ListBuffer(cr_item_sk#1025, cr_order_number#1039L, cr_return_quantity#1040, cr_return_amount#1041)
    // Output Table: ListBuffer(d_year#126, i_brand_id#235, i_class_id#237, i_category_id#239, i_manufact_id#241, cs_quantity#1122, cr_return_quantity#1040, cs_ext_sales_price#1127, cr_return_amount#1041)
    std::unordered_multimap<SW_JOIN_LEFTOUTER_TD_9685430_key, SW_JOIN_LEFTOUTER_TD_9685430_payload> ht1;
    int nrow1 = tbl_Filter_TD_10619629_output.getNumRow();
    int nrow2 = tbl_JOIN_INNER_TD_10170990_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _cr_order_number1039L_k = tbl_Filter_TD_10619629_output.getInt64(i, 1);
        int32_t _cr_item_sk1025_k = tbl_Filter_TD_10619629_output.getInt32(i, 0);
        SW_JOIN_LEFTOUTER_TD_9685430_key keyA{_cr_order_number1039L_k, _cr_item_sk1025_k};
        int32_t _cr_item_sk1025 = tbl_Filter_TD_10619629_output.getInt32(i, 0);
        int64_t _cr_order_number1039L = tbl_Filter_TD_10619629_output.getInt64(i, 1);
        int32_t _cr_return_quantity1040 = tbl_Filter_TD_10619629_output.getInt32(i, 2);
        int64_t _cr_return_amount1041 = tbl_Filter_TD_10619629_output.getInt64(i, 3);
        SW_JOIN_LEFTOUTER_TD_9685430_payload payloadA{_cr_item_sk1025, _cr_order_number1039L, _cr_return_quantity1040, _cr_return_amount1041};
        ht1.insert(std::make_pair(keyA, payloadA));
    }
    int r = 0;
    for (int i = 0; i < nrow2; i++) {
        int64_t _cs_order_number1121L_k = tbl_JOIN_INNER_TD_10170990_output.getInt64(i, 1);
        int32_t _cs_item_sk1119_k = tbl_JOIN_INNER_TD_10170990_output.getInt32(i, 0);
        auto it = ht1.find(SW_JOIN_LEFTOUTER_TD_9685430_key{_cs_order_number1121L_k, _cs_item_sk1119_k});
        int32_t _cs_item_sk1119 = tbl_JOIN_INNER_TD_10170990_output.getInt32(i, 0);
        int64_t _cs_order_number1121L = tbl_JOIN_INNER_TD_10170990_output.getInt64(i, 1);
        int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_10170990_output.getInt32(i, 2);
        int64_t _cs_ext_sales_price1127 = tbl_JOIN_INNER_TD_10170990_output.getInt64(i, 3);
        int32_t _i_brand_id235 = tbl_JOIN_INNER_TD_10170990_output.getInt32(i, 4);
        int32_t _i_class_id237 = tbl_JOIN_INNER_TD_10170990_output.getInt32(i, 5);
        int32_t _i_category_id239 = tbl_JOIN_INNER_TD_10170990_output.getInt32(i, 6);
        int32_t _i_manufact_id241 = tbl_JOIN_INNER_TD_10170990_output.getInt32(i, 7);
        int32_t _d_year126 = tbl_JOIN_INNER_TD_10170990_output.getInt32(i, 8);
        if (it != ht1.end()) {
            auto its = ht1.equal_range(SW_JOIN_LEFTOUTER_TD_9685430_key{_cs_order_number1121L_k, _cs_item_sk1119_k});
            auto it_it = its.first;
            while (it_it != its.second) {
                int32_t _cr_item_sk1025 = (it_it->second)._cr_item_sk1025;
                int64_t _cr_order_number1039L = (it_it->second)._cr_order_number1039L;
                int32_t _cr_return_quantity1040 = (it_it->second)._cr_return_quantity1040;
                int64_t _cr_return_amount1041 = (it_it->second)._cr_return_amount1041;
                tbl_JOIN_LEFTOUTER_TD_9685430_output.setInt32(r, 6, _cr_return_quantity1040);
                tbl_JOIN_LEFTOUTER_TD_9685430_output.setInt64(r, 8, _cr_return_amount1041);
                tbl_JOIN_LEFTOUTER_TD_9685430_output.setInt32(r, 5, _cs_quantity1122);
                tbl_JOIN_LEFTOUTER_TD_9685430_output.setInt64(r, 7, _cs_ext_sales_price1127);
                tbl_JOIN_LEFTOUTER_TD_9685430_output.setInt32(r, 1, _i_brand_id235);
                tbl_JOIN_LEFTOUTER_TD_9685430_output.setInt32(r, 2, _i_class_id237);
                tbl_JOIN_LEFTOUTER_TD_9685430_output.setInt32(r, 3, _i_category_id239);
                tbl_JOIN_LEFTOUTER_TD_9685430_output.setInt32(r, 4, _i_manufact_id241);
                tbl_JOIN_LEFTOUTER_TD_9685430_output.setInt32(r, 0, _d_year126);
                it_it++;
                r++;
            }
        } else {
            tbl_JOIN_LEFTOUTER_TD_9685430_output.setInt32(r, 5, _cs_quantity1122);
            tbl_JOIN_LEFTOUTER_TD_9685430_output.setInt64(r, 7, _cs_ext_sales_price1127);
            tbl_JOIN_LEFTOUTER_TD_9685430_output.setInt32(r, 1, _i_brand_id235);
            tbl_JOIN_LEFTOUTER_TD_9685430_output.setInt32(r, 2, _i_class_id237);
            tbl_JOIN_LEFTOUTER_TD_9685430_output.setInt32(r, 3, _i_category_id239);
            tbl_JOIN_LEFTOUTER_TD_9685430_output.setInt32(r, 4, _i_manufact_id241);
            tbl_JOIN_LEFTOUTER_TD_9685430_output.setInt32(r, 0, _d_year126);
            r++;
        }
    }
    tbl_JOIN_LEFTOUTER_TD_9685430_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTOUTER_TD_9685430_output #Row: " << tbl_JOIN_LEFTOUTER_TD_9685430_output.getNumRow() << std::endl;
}

void SW_Project_TD_8914491(Table &tbl_JOIN_LEFTOUTER_TD_9282254_output, Table &tbl_Project_TD_8914491_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer((ws_quantity#4648 - coalesce(wr_return_quantity#4728, 0)) AS sales_cnt#3554, CheckOverflow((promote_precision(cast(ws_ext_sales_price#4653 as decimal(8,2))) - promote_precision(cast(coalesce(wr_return_amt#4729, 0.00) as decimal(8,2)))), DecimalType(8,2), true) AS sales_amt#3555)
    // Input: ListBuffer(d_year#4692, i_brand_id#4671, i_class_id#4673, i_category_id#4675, i_manufact_id#4677, ws_quantity#4648, wr_return_quantity#4728, ws_ext_sales_price#4653, wr_return_amt#4729)
    // Output: ListBuffer(d_year#4692, i_brand_id#4671, i_class_id#4673, i_category_id#4675, i_manufact_id#4677, sales_cnt#3554, sales_amt#3555)
    int nrow1 = tbl_JOIN_LEFTOUTER_TD_9282254_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year4692 = tbl_JOIN_LEFTOUTER_TD_9282254_output.getInt32(i, 0);
        int32_t _i_brand_id4671 = tbl_JOIN_LEFTOUTER_TD_9282254_output.getInt32(i, 1);
        int32_t _i_class_id4673 = tbl_JOIN_LEFTOUTER_TD_9282254_output.getInt32(i, 2);
        int32_t _i_category_id4675 = tbl_JOIN_LEFTOUTER_TD_9282254_output.getInt32(i, 3);
        int32_t _i_manufact_id4677 = tbl_JOIN_LEFTOUTER_TD_9282254_output.getInt32(i, 4);
        int32_t _ws_quantity4648 = tbl_JOIN_LEFTOUTER_TD_9282254_output.getInt32(i, 5);
        int32_t _wr_return_quantity4728 = tbl_JOIN_LEFTOUTER_TD_9282254_output.getInt32(i, 6);
        int64_t _ws_ext_sales_price4653 = tbl_JOIN_LEFTOUTER_TD_9282254_output.getInt64(i, 7);
        int64_t _wr_return_amt4729 = tbl_JOIN_LEFTOUTER_TD_9282254_output.getInt64(i, 8);
        int32_t _sales_cnt3554 = (_ws_quantity4648 - _wr_return_quantity4728 != 0 ? _wr_return_quantity4728 : 0);
        tbl_Project_TD_8914491_output.setInt32(i, 5, _sales_cnt3554);
        int64_t _sales_amt3555 = (_ws_ext_sales_price4653 - _wr_return_amt4729 != 0 ? _wr_return_amt4729 : 0.00);
        tbl_Project_TD_8914491_output.setInt64(i, 6, _sales_amt3555);
        tbl_Project_TD_8914491_output.setInt32(i, 0, _d_year4692);
        tbl_Project_TD_8914491_output.setInt32(i, 1, _i_brand_id4671);
        tbl_Project_TD_8914491_output.setInt32(i, 2, _i_class_id4673);
        tbl_Project_TD_8914491_output.setInt32(i, 3, _i_category_id4675);
        tbl_Project_TD_8914491_output.setInt32(i, 4, _i_manufact_id4677);
    }
    tbl_Project_TD_8914491_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_8914491_output #Row: " << tbl_Project_TD_8914491_output.getNumRow() << std::endl;
}

void SW_Project_TD_8980056(Table &tbl_JOIN_LEFTOUTER_TD_9732787_output, Table &tbl_Project_TD_8980056_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer((ss_quantity#4547 - coalesce(sr_return_quantity#4620, 0)) AS sales_cnt#3552, CheckOverflow((promote_precision(cast(ss_ext_sales_price#4552 as decimal(8,2))) - promote_precision(cast(coalesce(sr_return_amt#4621, 0.00) as decimal(8,2)))), DecimalType(8,2), true) AS sales_amt#3553)
    // Input: ListBuffer(d_year#4588, i_brand_id#4567, i_class_id#4569, i_category_id#4571, i_manufact_id#4573, ss_quantity#4547, sr_return_quantity#4620, ss_ext_sales_price#4552, sr_return_amt#4621)
    // Output: ListBuffer(d_year#4588, i_brand_id#4567, i_class_id#4569, i_category_id#4571, i_manufact_id#4573, sales_cnt#3552, sales_amt#3553)
    int nrow1 = tbl_JOIN_LEFTOUTER_TD_9732787_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year4588 = tbl_JOIN_LEFTOUTER_TD_9732787_output.getInt32(i, 0);
        int32_t _i_brand_id4567 = tbl_JOIN_LEFTOUTER_TD_9732787_output.getInt32(i, 1);
        int32_t _i_class_id4569 = tbl_JOIN_LEFTOUTER_TD_9732787_output.getInt32(i, 2);
        int32_t _i_category_id4571 = tbl_JOIN_LEFTOUTER_TD_9732787_output.getInt32(i, 3);
        int32_t _i_manufact_id4573 = tbl_JOIN_LEFTOUTER_TD_9732787_output.getInt32(i, 4);
        int32_t _ss_quantity4547 = tbl_JOIN_LEFTOUTER_TD_9732787_output.getInt32(i, 5);
        int32_t _sr_return_quantity4620 = tbl_JOIN_LEFTOUTER_TD_9732787_output.getInt32(i, 6);
        int64_t _ss_ext_sales_price4552 = tbl_JOIN_LEFTOUTER_TD_9732787_output.getInt64(i, 7);
        int64_t _sr_return_amt4621 = tbl_JOIN_LEFTOUTER_TD_9732787_output.getInt64(i, 8);
        int32_t _sales_cnt3552 = (_ss_quantity4547 - _sr_return_quantity4620 != 0 ? _sr_return_quantity4620 : 0);
        tbl_Project_TD_8980056_output.setInt32(i, 5, _sales_cnt3552);
        int64_t _sales_amt3553 = (_ss_ext_sales_price4552 - _sr_return_amt4621 != 0 ? _sr_return_amt4621 : 0.00);
        tbl_Project_TD_8980056_output.setInt64(i, 6, _sales_amt3553);
        tbl_Project_TD_8980056_output.setInt32(i, 0, _d_year4588);
        tbl_Project_TD_8980056_output.setInt32(i, 1, _i_brand_id4567);
        tbl_Project_TD_8980056_output.setInt32(i, 2, _i_class_id4569);
        tbl_Project_TD_8980056_output.setInt32(i, 3, _i_category_id4571);
        tbl_Project_TD_8980056_output.setInt32(i, 4, _i_manufact_id4573);
    }
    tbl_Project_TD_8980056_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_8980056_output #Row: " << tbl_Project_TD_8980056_output.getNumRow() << std::endl;
}

void SW_Project_TD_8211225(Table &tbl_JOIN_LEFTOUTER_TD_9932501_output, Table &tbl_Project_TD_8211225_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer((cs_quantity#4444 - coalesce(cr_return_quantity#4527, 0)) AS sales_cnt#3550, CheckOverflow((promote_precision(cast(cs_ext_sales_price#4449 as decimal(8,2))) - promote_precision(cast(coalesce(cr_return_amount#4528, 0.00) as decimal(8,2)))), DecimalType(8,2), true) AS sales_amt#3551)
    // Input: ListBuffer(d_year#4488, i_brand_id#4467, i_class_id#4469, i_category_id#4471, i_manufact_id#4473, cs_quantity#4444, cr_return_quantity#4527, cs_ext_sales_price#4449, cr_return_amount#4528)
    // Output: ListBuffer(d_year#4488, i_brand_id#4467, i_class_id#4469, i_category_id#4471, i_manufact_id#4473, sales_cnt#3550, sales_amt#3551)
    int nrow1 = tbl_JOIN_LEFTOUTER_TD_9932501_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year4488 = tbl_JOIN_LEFTOUTER_TD_9932501_output.getInt32(i, 0);
        int32_t _i_brand_id4467 = tbl_JOIN_LEFTOUTER_TD_9932501_output.getInt32(i, 1);
        int32_t _i_class_id4469 = tbl_JOIN_LEFTOUTER_TD_9932501_output.getInt32(i, 2);
        int32_t _i_category_id4471 = tbl_JOIN_LEFTOUTER_TD_9932501_output.getInt32(i, 3);
        int32_t _i_manufact_id4473 = tbl_JOIN_LEFTOUTER_TD_9932501_output.getInt32(i, 4);
        int32_t _cs_quantity4444 = tbl_JOIN_LEFTOUTER_TD_9932501_output.getInt32(i, 5);
        int32_t _cr_return_quantity4527 = tbl_JOIN_LEFTOUTER_TD_9932501_output.getInt32(i, 6);
        int64_t _cs_ext_sales_price4449 = tbl_JOIN_LEFTOUTER_TD_9932501_output.getInt64(i, 7);
        int64_t _cr_return_amount4528 = tbl_JOIN_LEFTOUTER_TD_9932501_output.getInt64(i, 8);
        int32_t _sales_cnt3550 = (_cs_quantity4444 - _cr_return_quantity4527 != 0 ? _cr_return_quantity4527 : 0);
        tbl_Project_TD_8211225_output.setInt32(i, 5, _sales_cnt3550);
        int64_t _sales_amt3551 = (_cs_ext_sales_price4449 - _cr_return_amount4528 != 0 ? _cr_return_amount4528 : 0.00);
        tbl_Project_TD_8211225_output.setInt64(i, 6, _sales_amt3551);
        tbl_Project_TD_8211225_output.setInt32(i, 0, _d_year4488);
        tbl_Project_TD_8211225_output.setInt32(i, 1, _i_brand_id4467);
        tbl_Project_TD_8211225_output.setInt32(i, 2, _i_class_id4469);
        tbl_Project_TD_8211225_output.setInt32(i, 3, _i_category_id4471);
        tbl_Project_TD_8211225_output.setInt32(i, 4, _i_manufact_id4473);
    }
    tbl_Project_TD_8211225_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_8211225_output #Row: " << tbl_Project_TD_8211225_output.getNumRow() << std::endl;
}

void SW_Project_TD_8125147(Table &tbl_JOIN_LEFTOUTER_TD_9408405_output, Table &tbl_Project_TD_8125147_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer((ws_quantity#747 - coalesce(wr_return_quantity#845, 0)) AS sales_cnt#3554, CheckOverflow((promote_precision(cast(ws_ext_sales_price#752 as decimal(8,2))) - promote_precision(cast(coalesce(wr_return_amt#846, 0.00) as decimal(8,2)))), DecimalType(8,2), true) AS sales_amt#3555)
    // Input: ListBuffer(d_year#3636, i_brand_id#3615, i_class_id#3617, i_category_id#3619, i_manufact_id#3621, ws_quantity#747, wr_return_quantity#845, ws_ext_sales_price#752, wr_return_amt#846)
    // Output: ListBuffer(d_year#3636, i_brand_id#3615, i_class_id#3617, i_category_id#3619, i_manufact_id#3621, sales_cnt#3554, sales_amt#3555)
    int nrow1 = tbl_JOIN_LEFTOUTER_TD_9408405_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3636 = tbl_JOIN_LEFTOUTER_TD_9408405_output.getInt32(i, 0);
        int32_t _i_brand_id3615 = tbl_JOIN_LEFTOUTER_TD_9408405_output.getInt32(i, 1);
        int32_t _i_class_id3617 = tbl_JOIN_LEFTOUTER_TD_9408405_output.getInt32(i, 2);
        int32_t _i_category_id3619 = tbl_JOIN_LEFTOUTER_TD_9408405_output.getInt32(i, 3);
        int32_t _i_manufact_id3621 = tbl_JOIN_LEFTOUTER_TD_9408405_output.getInt32(i, 4);
        int32_t _ws_quantity747 = tbl_JOIN_LEFTOUTER_TD_9408405_output.getInt32(i, 5);
        int32_t _wr_return_quantity845 = tbl_JOIN_LEFTOUTER_TD_9408405_output.getInt32(i, 6);
        int64_t _ws_ext_sales_price752 = tbl_JOIN_LEFTOUTER_TD_9408405_output.getInt64(i, 7);
        int64_t _wr_return_amt846 = tbl_JOIN_LEFTOUTER_TD_9408405_output.getInt64(i, 8);
        int32_t _sales_cnt3554 = (_ws_quantity747 - _wr_return_quantity845 != 0 ? _wr_return_quantity845 : 0);
        tbl_Project_TD_8125147_output.setInt32(i, 5, _sales_cnt3554);
        int64_t _sales_amt3555 = (_ws_ext_sales_price752 - _wr_return_amt846 != 0 ? _wr_return_amt846 : 0.00);
        tbl_Project_TD_8125147_output.setInt64(i, 6, _sales_amt3555);
        tbl_Project_TD_8125147_output.setInt32(i, 0, _d_year3636);
        tbl_Project_TD_8125147_output.setInt32(i, 1, _i_brand_id3615);
        tbl_Project_TD_8125147_output.setInt32(i, 2, _i_class_id3617);
        tbl_Project_TD_8125147_output.setInt32(i, 3, _i_category_id3619);
        tbl_Project_TD_8125147_output.setInt32(i, 4, _i_manufact_id3621);
    }
    tbl_Project_TD_8125147_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_8125147_output #Row: " << tbl_Project_TD_8125147_output.getNumRow() << std::endl;
}

void SW_Project_TD_8509641(Table &tbl_JOIN_LEFTOUTER_TD_9954081_output, Table &tbl_Project_TD_8509641_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer((ss_quantity#1216 - coalesce(sr_return_quantity#679, 0)) AS sales_cnt#3552, CheckOverflow((promote_precision(cast(ss_ext_sales_price#1221 as decimal(8,2))) - promote_precision(cast(coalesce(sr_return_amt#680, 0.00) as decimal(8,2)))), DecimalType(8,2), true) AS sales_amt#3553)
    // Input: ListBuffer(d_year#3586, i_brand_id#3565, i_class_id#3567, i_category_id#3569, i_manufact_id#3571, ss_quantity#1216, sr_return_quantity#679, ss_ext_sales_price#1221, sr_return_amt#680)
    // Output: ListBuffer(d_year#3586, i_brand_id#3565, i_class_id#3567, i_category_id#3569, i_manufact_id#3571, sales_cnt#3552, sales_amt#3553)
    int nrow1 = tbl_JOIN_LEFTOUTER_TD_9954081_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3586 = tbl_JOIN_LEFTOUTER_TD_9954081_output.getInt32(i, 0);
        int32_t _i_brand_id3565 = tbl_JOIN_LEFTOUTER_TD_9954081_output.getInt32(i, 1);
        int32_t _i_class_id3567 = tbl_JOIN_LEFTOUTER_TD_9954081_output.getInt32(i, 2);
        int32_t _i_category_id3569 = tbl_JOIN_LEFTOUTER_TD_9954081_output.getInt32(i, 3);
        int32_t _i_manufact_id3571 = tbl_JOIN_LEFTOUTER_TD_9954081_output.getInt32(i, 4);
        int32_t _ss_quantity1216 = tbl_JOIN_LEFTOUTER_TD_9954081_output.getInt32(i, 5);
        int32_t _sr_return_quantity679 = tbl_JOIN_LEFTOUTER_TD_9954081_output.getInt32(i, 6);
        int64_t _ss_ext_sales_price1221 = tbl_JOIN_LEFTOUTER_TD_9954081_output.getInt64(i, 7);
        int64_t _sr_return_amt680 = tbl_JOIN_LEFTOUTER_TD_9954081_output.getInt64(i, 8);
        int32_t _sales_cnt3552 = (_ss_quantity1216 - _sr_return_quantity679 != 0 ? _sr_return_quantity679 : 0);
        tbl_Project_TD_8509641_output.setInt32(i, 5, _sales_cnt3552);
        int64_t _sales_amt3553 = (_ss_ext_sales_price1221 - _sr_return_amt680 != 0 ? _sr_return_amt680 : 0.00);
        tbl_Project_TD_8509641_output.setInt64(i, 6, _sales_amt3553);
        tbl_Project_TD_8509641_output.setInt32(i, 0, _d_year3586);
        tbl_Project_TD_8509641_output.setInt32(i, 1, _i_brand_id3565);
        tbl_Project_TD_8509641_output.setInt32(i, 2, _i_class_id3567);
        tbl_Project_TD_8509641_output.setInt32(i, 3, _i_category_id3569);
        tbl_Project_TD_8509641_output.setInt32(i, 4, _i_manufact_id3571);
    }
    tbl_Project_TD_8509641_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_8509641_output #Row: " << tbl_Project_TD_8509641_output.getNumRow() << std::endl;
}

void SW_Project_TD_8151633(Table &tbl_JOIN_LEFTOUTER_TD_9685430_output, Table &tbl_Project_TD_8151633_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer((cs_quantity#1122 - coalesce(cr_return_quantity#1040, 0)) AS sales_cnt#3550, CheckOverflow((promote_precision(cast(cs_ext_sales_price#1127 as decimal(8,2))) - promote_precision(cast(coalesce(cr_return_amount#1041, 0.00) as decimal(8,2)))), DecimalType(8,2), true) AS sales_amt#3551)
    // Input: ListBuffer(d_year#126, i_brand_id#235, i_class_id#237, i_category_id#239, i_manufact_id#241, cs_quantity#1122, cr_return_quantity#1040, cs_ext_sales_price#1127, cr_return_amount#1041)
    // Output: ListBuffer(d_year#126, i_brand_id#235, i_class_id#237, i_category_id#239, i_manufact_id#241, sales_cnt#3550, sales_amt#3551)
    int nrow1 = tbl_JOIN_LEFTOUTER_TD_9685430_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_JOIN_LEFTOUTER_TD_9685430_output.getInt32(i, 0);
        int32_t _i_brand_id235 = tbl_JOIN_LEFTOUTER_TD_9685430_output.getInt32(i, 1);
        int32_t _i_class_id237 = tbl_JOIN_LEFTOUTER_TD_9685430_output.getInt32(i, 2);
        int32_t _i_category_id239 = tbl_JOIN_LEFTOUTER_TD_9685430_output.getInt32(i, 3);
        int32_t _i_manufact_id241 = tbl_JOIN_LEFTOUTER_TD_9685430_output.getInt32(i, 4);
        int32_t _cs_quantity1122 = tbl_JOIN_LEFTOUTER_TD_9685430_output.getInt32(i, 5);
        int32_t _cr_return_quantity1040 = tbl_JOIN_LEFTOUTER_TD_9685430_output.getInt32(i, 6);
        int64_t _cs_ext_sales_price1127 = tbl_JOIN_LEFTOUTER_TD_9685430_output.getInt64(i, 7);
        int64_t _cr_return_amount1041 = tbl_JOIN_LEFTOUTER_TD_9685430_output.getInt64(i, 8);
        int32_t _sales_cnt3550 = (_cs_quantity1122 - _cr_return_quantity1040 != 0 ? _cr_return_quantity1040 : 0);
        tbl_Project_TD_8151633_output.setInt32(i, 5, _sales_cnt3550);
        int64_t _sales_amt3551 = (_cs_ext_sales_price1127 - _cr_return_amount1041 != 0 ? _cr_return_amount1041 : 0.00);
        tbl_Project_TD_8151633_output.setInt64(i, 6, _sales_amt3551);
        tbl_Project_TD_8151633_output.setInt32(i, 0, _d_year126);
        tbl_Project_TD_8151633_output.setInt32(i, 1, _i_brand_id235);
        tbl_Project_TD_8151633_output.setInt32(i, 2, _i_class_id237);
        tbl_Project_TD_8151633_output.setInt32(i, 3, _i_category_id239);
        tbl_Project_TD_8151633_output.setInt32(i, 4, _i_manufact_id241);
    }
    tbl_Project_TD_8151633_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_8151633_output #Row: " << tbl_Project_TD_8151633_output.getNumRow() << std::endl;
}

void SW_Union_TD_72857(Table &tbl_Project_TD_8211225_output, Table &tbl_Project_TD_8980056_output, Table &tbl_Project_TD_8914491_output, Table &tbl_Union_TD_72857_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Union
    // Operation: ListBuffer(List(UNION))
    // Output Table: ListBuffer(d_year#4488, i_brand_id#4467, i_class_id#4469, i_category_id#4471, i_manufact_id#4473, sales_cnt#3550, sales_amt#3551)
    int r = 0;
    int row0 = tbl_Project_TD_8211225_output.getNumRow();
    for (int i = 0; i < row0; i++) {
        tbl_Union_TD_72857_output.setInt32(r, 0, tbl_Project_TD_8211225_output.getInt32(i, 0));
        tbl_Union_TD_72857_output.setInt32(r, 1, tbl_Project_TD_8211225_output.getInt32(i, 1));
        tbl_Union_TD_72857_output.setInt32(r, 2, tbl_Project_TD_8211225_output.getInt32(i, 2));
        tbl_Union_TD_72857_output.setInt32(r, 3, tbl_Project_TD_8211225_output.getInt32(i, 3));
        tbl_Union_TD_72857_output.setInt32(r, 4, tbl_Project_TD_8211225_output.getInt32(i, 4));
        tbl_Union_TD_72857_output.setInt32(r, 5, tbl_Project_TD_8211225_output.getInt32(i, 5));
        tbl_Union_TD_72857_output.setInt32(r, 6, tbl_Project_TD_8211225_output.getInt64(i, 6));
        ++r;
    }
    int row1 = tbl_Project_TD_8980056_output.getNumRow();
    for (int i = 0; i < row1; i++) {
        tbl_Union_TD_72857_output.setInt32(r, 0, tbl_Project_TD_8980056_output.getInt32(i, 0));
        tbl_Union_TD_72857_output.setInt32(r, 1, tbl_Project_TD_8980056_output.getInt32(i, 1));
        tbl_Union_TD_72857_output.setInt32(r, 2, tbl_Project_TD_8980056_output.getInt32(i, 2));
        tbl_Union_TD_72857_output.setInt32(r, 3, tbl_Project_TD_8980056_output.getInt32(i, 3));
        tbl_Union_TD_72857_output.setInt32(r, 4, tbl_Project_TD_8980056_output.getInt32(i, 4));
        tbl_Union_TD_72857_output.setInt32(r, 5, tbl_Project_TD_8980056_output.getInt32(i, 5));
        tbl_Union_TD_72857_output.setInt32(r, 6, tbl_Project_TD_8980056_output.getInt64(i, 6));
        ++r;
    }
    int row2 = tbl_Project_TD_8914491_output.getNumRow();
    for (int i = 0; i < row2; i++) {
        tbl_Union_TD_72857_output.setInt32(r, 0, tbl_Project_TD_8914491_output.getInt32(i, 0));
        tbl_Union_TD_72857_output.setInt32(r, 1, tbl_Project_TD_8914491_output.getInt32(i, 1));
        tbl_Union_TD_72857_output.setInt32(r, 2, tbl_Project_TD_8914491_output.getInt32(i, 2));
        tbl_Union_TD_72857_output.setInt32(r, 3, tbl_Project_TD_8914491_output.getInt32(i, 3));
        tbl_Union_TD_72857_output.setInt32(r, 4, tbl_Project_TD_8914491_output.getInt32(i, 4));
        tbl_Union_TD_72857_output.setInt32(r, 5, tbl_Project_TD_8914491_output.getInt32(i, 5));
        tbl_Union_TD_72857_output.setInt32(r, 6, tbl_Project_TD_8914491_output.getInt64(i, 6));
        ++r;
    }
    tbl_Union_TD_72857_output.setNumRow(r);
    std::cout << "tbl_Union_TD_72857_output #Row: " << tbl_Union_TD_72857_output.getNumRow() << std::endl;
}

void SW_Union_TD_7483707(Table &tbl_Project_TD_8151633_output, Table &tbl_Project_TD_8509641_output, Table &tbl_Project_TD_8125147_output, Table &tbl_Union_TD_7483707_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Union
    // Operation: ListBuffer(List(UNION))
    // Output Table: ListBuffer(d_year#126, i_brand_id#235, i_class_id#237, i_category_id#239, i_manufact_id#241, sales_cnt#3550, sales_amt#3551)
    int r = 0;
    int row0 = tbl_Project_TD_8151633_output.getNumRow();
    for (int i = 0; i < row0; i++) {
        tbl_Union_TD_7483707_output.setInt32(r, 0, tbl_Project_TD_8151633_output.getInt32(i, 0));
        tbl_Union_TD_7483707_output.setInt32(r, 1, tbl_Project_TD_8151633_output.getInt32(i, 1));
        tbl_Union_TD_7483707_output.setInt32(r, 2, tbl_Project_TD_8151633_output.getInt32(i, 2));
        tbl_Union_TD_7483707_output.setInt32(r, 3, tbl_Project_TD_8151633_output.getInt32(i, 3));
        tbl_Union_TD_7483707_output.setInt32(r, 4, tbl_Project_TD_8151633_output.getInt32(i, 4));
        tbl_Union_TD_7483707_output.setInt32(r, 5, tbl_Project_TD_8151633_output.getInt32(i, 5));
        tbl_Union_TD_7483707_output.setInt32(r, 6, tbl_Project_TD_8151633_output.getInt64(i, 6));
        ++r;
    }
    int row1 = tbl_Project_TD_8509641_output.getNumRow();
    for (int i = 0; i < row1; i++) {
        tbl_Union_TD_7483707_output.setInt32(r, 0, tbl_Project_TD_8509641_output.getInt32(i, 0));
        tbl_Union_TD_7483707_output.setInt32(r, 1, tbl_Project_TD_8509641_output.getInt32(i, 1));
        tbl_Union_TD_7483707_output.setInt32(r, 2, tbl_Project_TD_8509641_output.getInt32(i, 2));
        tbl_Union_TD_7483707_output.setInt32(r, 3, tbl_Project_TD_8509641_output.getInt32(i, 3));
        tbl_Union_TD_7483707_output.setInt32(r, 4, tbl_Project_TD_8509641_output.getInt32(i, 4));
        tbl_Union_TD_7483707_output.setInt32(r, 5, tbl_Project_TD_8509641_output.getInt32(i, 5));
        tbl_Union_TD_7483707_output.setInt32(r, 6, tbl_Project_TD_8509641_output.getInt64(i, 6));
        ++r;
    }
    int row2 = tbl_Project_TD_8125147_output.getNumRow();
    for (int i = 0; i < row2; i++) {
        tbl_Union_TD_7483707_output.setInt32(r, 0, tbl_Project_TD_8125147_output.getInt32(i, 0));
        tbl_Union_TD_7483707_output.setInt32(r, 1, tbl_Project_TD_8125147_output.getInt32(i, 1));
        tbl_Union_TD_7483707_output.setInt32(r, 2, tbl_Project_TD_8125147_output.getInt32(i, 2));
        tbl_Union_TD_7483707_output.setInt32(r, 3, tbl_Project_TD_8125147_output.getInt32(i, 3));
        tbl_Union_TD_7483707_output.setInt32(r, 4, tbl_Project_TD_8125147_output.getInt32(i, 4));
        tbl_Union_TD_7483707_output.setInt32(r, 5, tbl_Project_TD_8125147_output.getInt32(i, 5));
        tbl_Union_TD_7483707_output.setInt32(r, 6, tbl_Project_TD_8125147_output.getInt64(i, 6));
        ++r;
    }
    tbl_Union_TD_7483707_output.setNumRow(r);
    std::cout << "tbl_Union_TD_7483707_output #Row: " << tbl_Union_TD_7483707_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_641603_consolidate(Table &tbl_Aggregate_TD_641603_output_preprocess, Table &tbl_Aggregate_TD_641603_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_641603_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _d_year4488 = tbl_Aggregate_TD_641603_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_641603_output.setInt32(r, 0, _d_year4488);
        int32_t _i_brand_id4467 = tbl_Aggregate_TD_641603_output_preprocess.getInt32(r, 6);
        tbl_Aggregate_TD_641603_output.setInt32(r, 1, _i_brand_id4467);
        int32_t _i_class_id4469 = tbl_Aggregate_TD_641603_output_preprocess.getInt32(r, 5);
        tbl_Aggregate_TD_641603_output.setInt32(r, 2, _i_class_id4469);
        int32_t _i_category_id4471 = tbl_Aggregate_TD_641603_output_preprocess.getInt32(r, 4);
        tbl_Aggregate_TD_641603_output.setInt32(r, 3, _i_category_id4471);
        int32_t _i_manufact_id4473 = tbl_Aggregate_TD_641603_output_preprocess.getInt32(r, 3);
        tbl_Aggregate_TD_641603_output.setInt32(r, 4, _i_manufact_id4473);
        int32_t _sales_cnt3550 = tbl_Aggregate_TD_641603_output_preprocess.getInt32(r, 2);
        tbl_Aggregate_TD_641603_output.setInt32(r, 5, _sales_cnt3550);
        int32_t _sales_amt3551 = tbl_Aggregate_TD_641603_output_preprocess.getInt32(r, 1);
        tbl_Aggregate_TD_641603_output.setInt32(r, 6, _sales_amt3551);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_641603_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_641603_output #Row: " << tbl_Aggregate_TD_641603_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_6604092_consolidate(Table &tbl_Aggregate_TD_6604092_output_preprocess, Table &tbl_Aggregate_TD_6604092_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_6604092_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _d_year126 = tbl_Aggregate_TD_6604092_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_6604092_output.setInt32(r, 0, _d_year126);
        int32_t _i_brand_id235 = tbl_Aggregate_TD_6604092_output_preprocess.getInt32(r, 6);
        tbl_Aggregate_TD_6604092_output.setInt32(r, 1, _i_brand_id235);
        int32_t _i_class_id237 = tbl_Aggregate_TD_6604092_output_preprocess.getInt32(r, 5);
        tbl_Aggregate_TD_6604092_output.setInt32(r, 2, _i_class_id237);
        int32_t _i_category_id239 = tbl_Aggregate_TD_6604092_output_preprocess.getInt32(r, 4);
        tbl_Aggregate_TD_6604092_output.setInt32(r, 3, _i_category_id239);
        int32_t _i_manufact_id241 = tbl_Aggregate_TD_6604092_output_preprocess.getInt32(r, 3);
        tbl_Aggregate_TD_6604092_output.setInt32(r, 4, _i_manufact_id241);
        int32_t _sales_cnt3550 = tbl_Aggregate_TD_6604092_output_preprocess.getInt32(r, 2);
        tbl_Aggregate_TD_6604092_output.setInt32(r, 5, _sales_cnt3550);
        int32_t _sales_amt3551 = tbl_Aggregate_TD_6604092_output_preprocess.getInt32(r, 1);
        tbl_Aggregate_TD_6604092_output.setInt32(r, 6, _sales_amt3551);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_6604092_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_6604092_output #Row: " << tbl_Aggregate_TD_6604092_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_5612354_consolidate(Table &tbl_Aggregate_TD_5612354_output_preprocess, Table &tbl_Aggregate_TD_5612354_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_5612354_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _d_year4488 = tbl_Aggregate_TD_5612354_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_5612354_output.setInt32(r, 0, _d_year4488);
        int32_t _i_brand_id4467 = tbl_Aggregate_TD_5612354_output_preprocess.getInt32(r, 6);
        tbl_Aggregate_TD_5612354_output.setInt32(r, 1, _i_brand_id4467);
        int32_t _i_class_id4469 = tbl_Aggregate_TD_5612354_output_preprocess.getInt32(r, 5);
        tbl_Aggregate_TD_5612354_output.setInt32(r, 2, _i_class_id4469);
        int32_t _i_category_id4471 = tbl_Aggregate_TD_5612354_output_preprocess.getInt32(r, 4);
        tbl_Aggregate_TD_5612354_output.setInt32(r, 3, _i_category_id4471);
        int32_t _i_manufact_id4473 = tbl_Aggregate_TD_5612354_output_preprocess.getInt32(r, 3);
        tbl_Aggregate_TD_5612354_output.setInt32(r, 4, _i_manufact_id4473);
        int64_t _sales_cnt3665L = tbl_Aggregate_TD_5612354_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_5612354_output.setInt64(r, 5, _sales_cnt3665L);
        int64_t _sales_amt3666 = tbl_Aggregate_TD_5612354_output_preprocess.combineInt64(r, 9, 1);
        tbl_Aggregate_TD_5612354_output.setInt64(r, 6, _sales_amt3666);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_5612354_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_5612354_output #Row: " << tbl_Aggregate_TD_5612354_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_5950654_consolidate(Table &tbl_Aggregate_TD_5950654_output_preprocess, Table &tbl_Aggregate_TD_5950654_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_5950654_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _d_year126 = tbl_Aggregate_TD_5950654_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_5950654_output.setInt32(r, 0, _d_year126);
        int32_t _i_brand_id235 = tbl_Aggregate_TD_5950654_output_preprocess.getInt32(r, 6);
        tbl_Aggregate_TD_5950654_output.setInt32(r, 1, _i_brand_id235);
        int32_t _i_class_id237 = tbl_Aggregate_TD_5950654_output_preprocess.getInt32(r, 5);
        tbl_Aggregate_TD_5950654_output.setInt32(r, 2, _i_class_id237);
        int32_t _i_category_id239 = tbl_Aggregate_TD_5950654_output_preprocess.getInt32(r, 4);
        tbl_Aggregate_TD_5950654_output.setInt32(r, 3, _i_category_id239);
        int32_t _i_manufact_id241 = tbl_Aggregate_TD_5950654_output_preprocess.getInt32(r, 3);
        tbl_Aggregate_TD_5950654_output.setInt32(r, 4, _i_manufact_id241);
        int64_t _sales_cnt3556L = tbl_Aggregate_TD_5950654_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_5950654_output.setInt64(r, 5, _sales_cnt3556L);
        int64_t _sales_amt3557 = tbl_Aggregate_TD_5950654_output_preprocess.combineInt64(r, 9, 1);
        tbl_Aggregate_TD_5950654_output.setInt64(r, 6, _sales_amt3557);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_5950654_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_5950654_output #Row: " << tbl_Aggregate_TD_5950654_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4241816_key_leftMajor {
    int32_t _i_brand_id235;
    int32_t _i_class_id237;
    int32_t _i_category_id239;
    int32_t _i_manufact_id241;
    bool operator==(const SW_JOIN_INNER_TD_4241816_key_leftMajor& other) const {
        return ((_i_brand_id235 == other._i_brand_id235) && (_i_class_id237 == other._i_class_id237) && (_i_category_id239 == other._i_category_id239) && (_i_manufact_id241 == other._i_manufact_id241));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4241816_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4241816_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id235)) + (hash<int32_t>()(k._i_class_id237)) + (hash<int32_t>()(k._i_category_id239)) + (hash<int32_t>()(k._i_manufact_id241));
    }
};
}
struct SW_JOIN_INNER_TD_4241816_payload_leftMajor {
    int32_t _d_year126;
    int32_t _i_brand_id235;
    int32_t _i_class_id237;
    int32_t _i_category_id239;
    int32_t _i_manufact_id241;
    int64_t _sales_cnt3556L;
    int64_t _sales_amt3557;
};
struct SW_JOIN_INNER_TD_4241816_key_rightMajor {
    int32_t _i_brand_id4467;
    int32_t _i_class_id4469;
    int32_t _i_category_id4471;
    int32_t _i_manufact_id4473;
    bool operator==(const SW_JOIN_INNER_TD_4241816_key_rightMajor& other) const {
        return ((_i_brand_id4467 == other._i_brand_id4467) && (_i_class_id4469 == other._i_class_id4469) && (_i_category_id4471 == other._i_category_id4471) && (_i_manufact_id4473 == other._i_manufact_id4473));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4241816_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4241816_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id4467)) + (hash<int32_t>()(k._i_class_id4469)) + (hash<int32_t>()(k._i_category_id4471)) + (hash<int32_t>()(k._i_manufact_id4473));
    }
};
}
struct SW_JOIN_INNER_TD_4241816_payload_rightMajor {
    int32_t _d_year4488;
    int32_t _i_brand_id4467;
    int32_t _i_class_id4469;
    int32_t _i_category_id4471;
    int32_t _i_manufact_id4473;
    int64_t _sales_cnt3665L;
    int64_t _sales_amt3666;
};
void SW_JOIN_INNER_TD_4241816(Table &tbl_Aggregate_TD_5950654_output, Table &tbl_Aggregate_TD_5612354_output, Table &tbl_JOIN_INNER_TD_4241816_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((((((i_brand_id#235 = i_brand_id#4467) AND (i_class_id#237 = i_class_id#4469)) AND (i_category_id#239 = i_category_id#4471)) AND (i_manufact_id#241 = i_manufact_id#4473)) AND (CheckOverflow((promote_precision(cast(sales_cnt#3556L as decimal(17,2))) / promote_precision(cast(sales_cnt#3665L as decimal(17,2)))), DecimalType(37,20), true) < 0.90000000000000000000)))
    // Left Table: ListBuffer(d_year#126, i_brand_id#235, i_class_id#237, i_category_id#239, i_manufact_id#241, sales_cnt#3556L, sales_amt#3557)
    // Right Table: ListBuffer(d_year#4488, i_brand_id#4467, i_class_id#4469, i_category_id#4471, i_manufact_id#4473, sales_cnt#3665L, sales_amt#3666)
    // Output Table: ListBuffer(d_year#4488, d_year#126, i_brand_id#235, i_class_id#237, i_category_id#239, i_manufact_id#241, sales_cnt#3665L, sales_cnt#3556L, sales_amt#3557, sales_amt#3666)
    int left_nrow = tbl_Aggregate_TD_5950654_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_5612354_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4241816_key_leftMajor, SW_JOIN_INNER_TD_4241816_payload_leftMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_5950654_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_brand_id235_k = tbl_Aggregate_TD_5950654_output.getInt32(i, 1);
            int32_t _i_class_id237_k = tbl_Aggregate_TD_5950654_output.getInt32(i, 2);
            int32_t _i_category_id239_k = tbl_Aggregate_TD_5950654_output.getInt32(i, 3);
            int32_t _i_manufact_id241_k = tbl_Aggregate_TD_5950654_output.getInt32(i, 4);
            SW_JOIN_INNER_TD_4241816_key_leftMajor keyA{_i_brand_id235_k, _i_class_id237_k, _i_category_id239_k, _i_manufact_id241_k};
            int32_t _d_year126 = tbl_Aggregate_TD_5950654_output.getInt32(i, 0);
            int32_t _i_brand_id235 = tbl_Aggregate_TD_5950654_output.getInt32(i, 1);
            int32_t _i_class_id237 = tbl_Aggregate_TD_5950654_output.getInt32(i, 2);
            int32_t _i_category_id239 = tbl_Aggregate_TD_5950654_output.getInt32(i, 3);
            int32_t _i_manufact_id241 = tbl_Aggregate_TD_5950654_output.getInt32(i, 4);
            int64_t _sales_cnt3556L = tbl_Aggregate_TD_5950654_output.getInt64(i, 5);
            int64_t _sales_amt3557 = tbl_Aggregate_TD_5950654_output.getInt64(i, 6);
            SW_JOIN_INNER_TD_4241816_payload_leftMajor payloadA{_d_year126, _i_brand_id235, _i_class_id237, _i_category_id239, _i_manufact_id241, _sales_cnt3556L, _sales_amt3557};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_5612354_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_brand_id4467_k = tbl_Aggregate_TD_5612354_output.getInt32(i, 1);
            int32_t _i_class_id4469_k = tbl_Aggregate_TD_5612354_output.getInt32(i, 2);
            int32_t _i_category_id4471_k = tbl_Aggregate_TD_5612354_output.getInt32(i, 3);
            int32_t _i_manufact_id4473_k = tbl_Aggregate_TD_5612354_output.getInt32(i, 4);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4241816_key_leftMajor{_i_brand_id4467_k, _i_class_id4469_k, _i_category_id4471_k, _i_manufact_id4473_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_year126 = (it->second)._d_year126;
                int32_t _i_brand_id235 = (it->second)._i_brand_id235;
                int32_t _i_class_id237 = (it->second)._i_class_id237;
                int32_t _i_category_id239 = (it->second)._i_category_id239;
                int32_t _i_manufact_id241 = (it->second)._i_manufact_id241;
                int64_t _sales_cnt3556L = (it->second)._sales_cnt3556L;
                int64_t _sales_amt3557 = (it->second)._sales_amt3557;
                int32_t _d_year4488 = tbl_Aggregate_TD_5612354_output.getInt32(i, 0);
                int32_t _i_brand_id4467 = tbl_Aggregate_TD_5612354_output.getInt32(i, 1);
                int32_t _i_class_id4469 = tbl_Aggregate_TD_5612354_output.getInt32(i, 2);
                int32_t _i_category_id4471 = tbl_Aggregate_TD_5612354_output.getInt32(i, 3);
                int32_t _i_manufact_id4473 = tbl_Aggregate_TD_5612354_output.getInt32(i, 4);
                int64_t _sales_cnt3665L = tbl_Aggregate_TD_5612354_output.getInt64(i, 5);
                int64_t _sales_amt3666 = tbl_Aggregate_TD_5612354_output.getInt64(i, 6);
                if (NULL < 0.90000000000000000000) {
                    tbl_JOIN_INNER_TD_4241816_output.setInt32(r, 1, _d_year126);
                    tbl_JOIN_INNER_TD_4241816_output.setInt32(r, 2, _i_brand_id235);
                    tbl_JOIN_INNER_TD_4241816_output.setInt32(r, 3, _i_class_id237);
                    tbl_JOIN_INNER_TD_4241816_output.setInt32(r, 4, _i_category_id239);
                    tbl_JOIN_INNER_TD_4241816_output.setInt32(r, 5, _i_manufact_id241);
                    tbl_JOIN_INNER_TD_4241816_output.setInt64(r, 7, _sales_cnt3556L);
                    tbl_JOIN_INNER_TD_4241816_output.setInt64(r, 8, _sales_amt3557);
                    tbl_JOIN_INNER_TD_4241816_output.setInt32(r, 0, _d_year4488);
                    tbl_JOIN_INNER_TD_4241816_output.setInt64(r, 6, _sales_cnt3665L);
                    tbl_JOIN_INNER_TD_4241816_output.setInt64(r, 9, _sales_amt3666);
                    r++;
                }
                it++;
            }
        }
        tbl_JOIN_INNER_TD_4241816_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4241816_key_rightMajor, SW_JOIN_INNER_TD_4241816_payload_rightMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_5612354_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_brand_id4467_k = tbl_Aggregate_TD_5612354_output.getInt32(i, 1);
            int32_t _i_class_id4469_k = tbl_Aggregate_TD_5612354_output.getInt32(i, 2);
            int32_t _i_category_id4471_k = tbl_Aggregate_TD_5612354_output.getInt32(i, 3);
            int32_t _i_manufact_id4473_k = tbl_Aggregate_TD_5612354_output.getInt32(i, 4);
            SW_JOIN_INNER_TD_4241816_key_rightMajor keyA{_i_brand_id4467_k, _i_class_id4469_k, _i_category_id4471_k, _i_manufact_id4473_k};
            int32_t _d_year4488 = tbl_Aggregate_TD_5612354_output.getInt32(i, 0);
            int32_t _i_brand_id4467 = tbl_Aggregate_TD_5612354_output.getInt32(i, 1);
            int32_t _i_class_id4469 = tbl_Aggregate_TD_5612354_output.getInt32(i, 2);
            int32_t _i_category_id4471 = tbl_Aggregate_TD_5612354_output.getInt32(i, 3);
            int32_t _i_manufact_id4473 = tbl_Aggregate_TD_5612354_output.getInt32(i, 4);
            int64_t _sales_cnt3665L = tbl_Aggregate_TD_5612354_output.getInt64(i, 5);
            int64_t _sales_amt3666 = tbl_Aggregate_TD_5612354_output.getInt64(i, 6);
            SW_JOIN_INNER_TD_4241816_payload_rightMajor payloadA{_d_year4488, _i_brand_id4467, _i_class_id4469, _i_category_id4471, _i_manufact_id4473, _sales_cnt3665L, _sales_amt3666};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_5950654_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_brand_id235_k = tbl_Aggregate_TD_5950654_output.getInt32(i, 1);
            int32_t _i_class_id237_k = tbl_Aggregate_TD_5950654_output.getInt32(i, 2);
            int32_t _i_category_id239_k = tbl_Aggregate_TD_5950654_output.getInt32(i, 3);
            int32_t _i_manufact_id241_k = tbl_Aggregate_TD_5950654_output.getInt32(i, 4);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4241816_key_rightMajor{_i_brand_id235_k, _i_class_id237_k, _i_category_id239_k, _i_manufact_id241_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_year4488 = (it->second)._d_year4488;
                int32_t _i_brand_id4467 = (it->second)._i_brand_id4467;
                int32_t _i_class_id4469 = (it->second)._i_class_id4469;
                int32_t _i_category_id4471 = (it->second)._i_category_id4471;
                int32_t _i_manufact_id4473 = (it->second)._i_manufact_id4473;
                int64_t _sales_cnt3665L = (it->second)._sales_cnt3665L;
                int64_t _sales_amt3666 = (it->second)._sales_amt3666;
                int32_t _d_year126 = tbl_Aggregate_TD_5950654_output.getInt32(i, 0);
                int32_t _i_brand_id235 = tbl_Aggregate_TD_5950654_output.getInt32(i, 1);
                int32_t _i_class_id237 = tbl_Aggregate_TD_5950654_output.getInt32(i, 2);
                int32_t _i_category_id239 = tbl_Aggregate_TD_5950654_output.getInt32(i, 3);
                int32_t _i_manufact_id241 = tbl_Aggregate_TD_5950654_output.getInt32(i, 4);
                int64_t _sales_cnt3556L = tbl_Aggregate_TD_5950654_output.getInt64(i, 5);
                int64_t _sales_amt3557 = tbl_Aggregate_TD_5950654_output.getInt64(i, 6);
                if (NULL < 0.90000000000000000000) {
                    tbl_JOIN_INNER_TD_4241816_output.setInt32(r, 0, _d_year4488);
                    tbl_JOIN_INNER_TD_4241816_output.setInt64(r, 6, _sales_cnt3665L);
                    tbl_JOIN_INNER_TD_4241816_output.setInt64(r, 9, _sales_amt3666);
                    tbl_JOIN_INNER_TD_4241816_output.setInt32(r, 1, _d_year126);
                    tbl_JOIN_INNER_TD_4241816_output.setInt32(r, 2, _i_brand_id235);
                    tbl_JOIN_INNER_TD_4241816_output.setInt32(r, 3, _i_class_id237);
                    tbl_JOIN_INNER_TD_4241816_output.setInt32(r, 4, _i_category_id239);
                    tbl_JOIN_INNER_TD_4241816_output.setInt32(r, 5, _i_manufact_id241);
                    tbl_JOIN_INNER_TD_4241816_output.setInt64(r, 7, _sales_cnt3556L);
                    tbl_JOIN_INNER_TD_4241816_output.setInt64(r, 8, _sales_amt3557);
                    r++;
                }
                it++;
            }
        }
        tbl_JOIN_INNER_TD_4241816_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4241816_output #Row: " << tbl_JOIN_INNER_TD_4241816_output.getNumRow() << std::endl;
}

void SW_Project_TD_3602289(Table &tbl_JOIN_INNER_TD_4241816_output, Table &tbl_Project_TD_3602289_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(d_year#4488 AS prev_year#3544, d_year#126 AS year#3545, sales_cnt#3665L AS prev_yr_cnt#3546L, sales_cnt#3556L AS curr_yr_cnt#3547L, (sales_cnt#3556L - sales_cnt#3665L) AS sales_cnt_diff#3548L, CheckOverflow((promote_precision(cast(sales_amt#3557 as decimal(19,2))) - promote_precision(cast(sales_amt#3666 as decimal(19,2)))), DecimalType(19,2), true) AS sales_amt_diff#3549)
    // Input: ListBuffer(d_year#4488, d_year#126, i_brand_id#235, i_class_id#237, i_category_id#239, i_manufact_id#241, sales_cnt#3665L, sales_cnt#3556L, sales_amt#3557, sales_amt#3666)
    // Output: ListBuffer(prev_year#3544, year#3545, i_brand_id#235, i_class_id#237, i_category_id#239, i_manufact_id#241, prev_yr_cnt#3546L, curr_yr_cnt#3547L, sales_cnt_diff#3548L, sales_amt_diff#3549)
    int nrow1 = tbl_JOIN_INNER_TD_4241816_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year4488 = tbl_JOIN_INNER_TD_4241816_output.getInt32(i, 0);
        int32_t _d_year126 = tbl_JOIN_INNER_TD_4241816_output.getInt32(i, 1);
        int32_t _i_brand_id235 = tbl_JOIN_INNER_TD_4241816_output.getInt32(i, 2);
        int32_t _i_class_id237 = tbl_JOIN_INNER_TD_4241816_output.getInt32(i, 3);
        int32_t _i_category_id239 = tbl_JOIN_INNER_TD_4241816_output.getInt32(i, 4);
        int32_t _i_manufact_id241 = tbl_JOIN_INNER_TD_4241816_output.getInt32(i, 5);
        int64_t _sales_cnt3665L = tbl_JOIN_INNER_TD_4241816_output.getInt64(i, 6);
        int64_t _sales_cnt3556L = tbl_JOIN_INNER_TD_4241816_output.getInt64(i, 7);
        int64_t _sales_amt3557 = tbl_JOIN_INNER_TD_4241816_output.getInt64(i, 8);
        int64_t _sales_amt3666 = tbl_JOIN_INNER_TD_4241816_output.getInt64(i, 9);
        int32_t _prev_year3544 = _d_year4488;
        tbl_Project_TD_3602289_output.setInt32(i, 0, _prev_year3544);
        int32_t _year3545 = _d_year126;
        tbl_Project_TD_3602289_output.setInt32(i, 1, _year3545);
        int64_t _prev_yr_cnt3546L = _sales_cnt3665L;
        tbl_Project_TD_3602289_output.setInt64(i, 6, _prev_yr_cnt3546L);
        int64_t _curr_yr_cnt3547L = _sales_cnt3556L;
        tbl_Project_TD_3602289_output.setInt64(i, 7, _curr_yr_cnt3547L);
        int64_t _sales_cnt_diff3548L = (_sales_cnt3556L - _sales_cnt3665L);
        tbl_Project_TD_3602289_output.setInt64(i, 8, _sales_cnt_diff3548L);
        int64_t _sales_amt_diff3549 = (_sales_amt3557 - _sales_amt3666);
        tbl_Project_TD_3602289_output.setInt64(i, 9, _sales_amt_diff3549);
        tbl_Project_TD_3602289_output.setInt32(i, 2, _i_brand_id235);
        tbl_Project_TD_3602289_output.setInt32(i, 3, _i_class_id237);
        tbl_Project_TD_3602289_output.setInt32(i, 4, _i_category_id239);
        tbl_Project_TD_3602289_output.setInt32(i, 5, _i_manufact_id241);
    }
    tbl_Project_TD_3602289_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_3602289_output #Row: " << tbl_Project_TD_3602289_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2198469(Table &tbl_Project_TD_3602289_output, Table &tbl_Sort_TD_2198469_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(sales_cnt_diff#3548L ASC NULLS FIRST)
    // Input: ListBuffer(prev_year#3544, year#3545, i_brand_id#235, i_class_id#237, i_category_id#239, i_manufact_id#241, prev_yr_cnt#3546L, curr_yr_cnt#3547L, sales_cnt_diff#3548L, sales_amt_diff#3549)
    // Output: ListBuffer(prev_year#3544, year#3545, i_brand_id#235, i_class_id#237, i_category_id#239, i_manufact_id#241, prev_yr_cnt#3546L, curr_yr_cnt#3547L, sales_cnt_diff#3548L, sales_amt_diff#3549)
    struct SW_Sort_TD_2198469Row {
        int32_t _prev_year3544;
        int32_t _year3545;
        int32_t _i_brand_id235;
        int32_t _i_class_id237;
        int32_t _i_category_id239;
        int32_t _i_manufact_id241;
        int64_t _prev_yr_cnt3546L;
        int64_t _curr_yr_cnt3547L;
        int64_t _sales_cnt_diff3548L;
        int64_t _sales_amt_diff3549;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2198469Row& a, const SW_Sort_TD_2198469Row& b) const { return 
 (a._sales_cnt_diff3548L < b._sales_cnt_diff3548L); 
}
    }SW_Sort_TD_2198469_order; 

    int nrow1 = tbl_Project_TD_3602289_output.getNumRow();
    std::vector<SW_Sort_TD_2198469Row> rows;
    for (int i = 0; i < nrow1; i++) {
        int32_t _prev_year3544 = tbl_Project_TD_3602289_output.getInt32(i, 0);
        int32_t _year3545 = tbl_Project_TD_3602289_output.getInt32(i, 1);
        int32_t _i_brand_id235 = tbl_Project_TD_3602289_output.getInt32(i, 2);
        int32_t _i_class_id237 = tbl_Project_TD_3602289_output.getInt32(i, 3);
        int32_t _i_category_id239 = tbl_Project_TD_3602289_output.getInt32(i, 4);
        int32_t _i_manufact_id241 = tbl_Project_TD_3602289_output.getInt32(i, 5);
        int64_t _prev_yr_cnt3546L = tbl_Project_TD_3602289_output.getInt64(i, 6);
        int64_t _curr_yr_cnt3547L = tbl_Project_TD_3602289_output.getInt64(i, 7);
        int64_t _sales_cnt_diff3548L = tbl_Project_TD_3602289_output.getInt64(i, 8);
        int64_t _sales_amt_diff3549 = tbl_Project_TD_3602289_output.getInt64(i, 9);
        SW_Sort_TD_2198469Row t = {_prev_year3544,_year3545,_i_brand_id235,_i_class_id237,_i_category_id239,_i_manufact_id241,_prev_yr_cnt3546L,_curr_yr_cnt3547L,_sales_cnt_diff3548L,_sales_amt_diff3549};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2198469_order);
    int r = 0;
    for (auto& it : rows) {
        tbl_Sort_TD_2198469_output.setInt32(r, 0, it._prev_year3544);
        tbl_Sort_TD_2198469_output.setInt32(r, 1, it._year3545);
        tbl_Sort_TD_2198469_output.setInt32(r, 2, it._i_brand_id235);
        tbl_Sort_TD_2198469_output.setInt32(r, 3, it._i_class_id237);
        tbl_Sort_TD_2198469_output.setInt32(r, 4, it._i_category_id239);
        tbl_Sort_TD_2198469_output.setInt32(r, 5, it._i_manufact_id241);
        tbl_Sort_TD_2198469_output.setInt64(r, 6, it._prev_yr_cnt3546L);
        tbl_Sort_TD_2198469_output.setInt64(r, 7, it._curr_yr_cnt3547L);
        tbl_Sort_TD_2198469_output.setInt64(r, 8, it._sales_cnt_diff3548L);
        tbl_Sort_TD_2198469_output.setInt64(r, 9, it._sales_amt_diff3549);
        ++r;
    }
    tbl_Sort_TD_2198469_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2198469_output #Row: " << tbl_Sort_TD_2198469_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1422359(Table &tbl_Sort_TD_2198469_output, Table &tbl_LocalLimit_TD_1422359_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(prev_year#3544, year#3545, i_brand_id#235, i_class_id#237, i_category_id#239, i_manufact_id#241, prev_yr_cnt#3546L, curr_yr_cnt#3547L, sales_cnt_diff#3548L, sales_amt_diff#3549)
    // Output: ListBuffer(prev_year#3544, year#3545, i_brand_id#235, i_class_id#237, i_category_id#239, i_manufact_id#241, prev_yr_cnt#3546L, curr_yr_cnt#3547L, sales_cnt_diff#3548L, sales_amt_diff#3549)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        tbl_LocalLimit_TD_1422359_output.setInt32(r, 0, tbl_Sort_TD_2198469_output.getInt32(i, 0));
        tbl_LocalLimit_TD_1422359_output.setInt32(r, 1, tbl_Sort_TD_2198469_output.getInt32(i, 1));
        tbl_LocalLimit_TD_1422359_output.setInt32(r, 2, tbl_Sort_TD_2198469_output.getInt32(i, 2));
        tbl_LocalLimit_TD_1422359_output.setInt32(r, 3, tbl_Sort_TD_2198469_output.getInt32(i, 3));
        tbl_LocalLimit_TD_1422359_output.setInt32(r, 4, tbl_Sort_TD_2198469_output.getInt32(i, 4));
        tbl_LocalLimit_TD_1422359_output.setInt32(r, 5, tbl_Sort_TD_2198469_output.getInt32(i, 5));
        tbl_LocalLimit_TD_1422359_output.setInt64(r, 6, tbl_Sort_TD_2198469_output.getInt64(i, 6));
        tbl_LocalLimit_TD_1422359_output.setInt64(r, 7, tbl_Sort_TD_2198469_output.getInt64(i, 7));
        tbl_LocalLimit_TD_1422359_output.setInt64(r, 8, tbl_Sort_TD_2198469_output.getInt64(i, 8));
        tbl_LocalLimit_TD_1422359_output.setInt64(r, 9, tbl_Sort_TD_2198469_output.getInt64(i, 9));
        r++;
    }
    tbl_LocalLimit_TD_1422359_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1422359_output #Row: " << tbl_LocalLimit_TD_1422359_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0663158(Table &tbl_LocalLimit_TD_1422359_output, Table &tbl_GlobalLimit_TD_0663158_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(prev_year#3544, year#3545, i_brand_id#235, i_class_id#237, i_category_id#239, i_manufact_id#241, prev_yr_cnt#3546L, curr_yr_cnt#3547L, sales_cnt_diff#3548L, sales_amt_diff#3549)
    // Output: ListBuffer(prev_year#3544, year#3545, i_brand_id#235, i_class_id#237, i_category_id#239, i_manufact_id#241, prev_yr_cnt#3546L, curr_yr_cnt#3547L, sales_cnt_diff#3548L, sales_amt_diff#3549)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        tbl_GlobalLimit_TD_0663158_output.setInt32(r, 0, tbl_LocalLimit_TD_1422359_output.getInt32(i, 0));
        tbl_GlobalLimit_TD_0663158_output.setInt32(r, 1, tbl_LocalLimit_TD_1422359_output.getInt32(i, 1));
        tbl_GlobalLimit_TD_0663158_output.setInt32(r, 2, tbl_LocalLimit_TD_1422359_output.getInt32(i, 2));
        tbl_GlobalLimit_TD_0663158_output.setInt32(r, 3, tbl_LocalLimit_TD_1422359_output.getInt32(i, 3));
        tbl_GlobalLimit_TD_0663158_output.setInt32(r, 4, tbl_LocalLimit_TD_1422359_output.getInt32(i, 4));
        tbl_GlobalLimit_TD_0663158_output.setInt32(r, 5, tbl_LocalLimit_TD_1422359_output.getInt32(i, 5));
        tbl_GlobalLimit_TD_0663158_output.setInt64(r, 6, tbl_LocalLimit_TD_1422359_output.getInt64(i, 6));
        tbl_GlobalLimit_TD_0663158_output.setInt64(r, 7, tbl_LocalLimit_TD_1422359_output.getInt64(i, 7));
        tbl_GlobalLimit_TD_0663158_output.setInt64(r, 8, tbl_LocalLimit_TD_1422359_output.getInt64(i, 8));
        tbl_GlobalLimit_TD_0663158_output.setInt64(r, 9, tbl_LocalLimit_TD_1422359_output.getInt64(i, 9));
        r++;
    }
    tbl_GlobalLimit_TD_0663158_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0663158_output #Row: " << tbl_GlobalLimit_TD_0663158_output.getNumRow() << std::endl;
}

