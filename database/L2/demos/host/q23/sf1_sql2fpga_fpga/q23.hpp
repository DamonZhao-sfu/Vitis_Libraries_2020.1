#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_14399817(Table &tbl_SerializeFromObject_TD_15662963_input, Table &tbl_Filter_TD_14399817_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((d_year#126 IN (2000,2001,2002,2003) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_date#122, d_year#126)
    // Output: ListBuffer(d_date_sk#120, d_date#122)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_15662963_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_15662963_input.getInt32(i, 2);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_15662963_input.getInt32(i, 0);
        auto reuse_col_str_698 = _d_year126;
        if (((reuse_col_str_698 == 2000) || (reuse_col_str_698 == 2001) || (reuse_col_str_698 == 2002) || (reuse_col_str_698 == 2003) || (0)) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_15662963_input.getInt32(i, 0);
            tbl_Filter_TD_14399817_output.setInt32(r, 0, _d_date_sk120_t);
            int32_t _d_date122_t = tbl_SerializeFromObject_TD_15662963_input.getInt32(i, 1);
            tbl_Filter_TD_14399817_output.setInt32(r, 1, _d_date122_t);
            r++;
        }
    }
    tbl_Filter_TD_14399817_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_14399817_output #Row: " << tbl_Filter_TD_14399817_output.getNumRow() << std::endl;
}

void SW_Filter_TD_14407716(Table &tbl_SerializeFromObject_TD_15445630_input, Table &tbl_Filter_TD_14407716_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_sold_date_sk#1206) AND isnotnull(ss_item_sk#1208)))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_15445630_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_15445630_input.getInt32(i, 0);
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_15445630_input.getInt32(i, 1);
        if ((_ss_sold_date_sk1206!= 0) && (_ss_item_sk1208!= 0)) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_15445630_input.getInt32(i, 0);
            tbl_Filter_TD_14407716_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_15445630_input.getInt32(i, 1);
            tbl_Filter_TD_14407716_output.setInt32(r, 1, _ss_item_sk1208_t);
            r++;
        }
    }
    tbl_Filter_TD_14407716_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_14407716_output #Row: " << tbl_Filter_TD_14407716_output.getNumRow() << std::endl;
}

void SW_Filter_TD_14165006(Table &tbl_SerializeFromObject_TD_15216586_input, Table &tbl_Filter_TD_14165006_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((d_year#126 IN (2000,2001,2002,2003) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_date#122, d_year#126)
    // Output: ListBuffer(d_date_sk#120, d_date#122)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_15216586_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_15216586_input.getInt32(i, 2);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_15216586_input.getInt32(i, 0);
        auto reuse_col_str_136 = _d_year126;
        if (((reuse_col_str_136 == 2000) || (reuse_col_str_136 == 2001) || (reuse_col_str_136 == 2002) || (reuse_col_str_136 == 2003) || (0)) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_15216586_input.getInt32(i, 0);
            tbl_Filter_TD_14165006_output.setInt32(r, 0, _d_date_sk120_t);
            int32_t _d_date122_t = tbl_SerializeFromObject_TD_15216586_input.getInt32(i, 1);
            tbl_Filter_TD_14165006_output.setInt32(r, 1, _d_date122_t);
            r++;
        }
    }
    tbl_Filter_TD_14165006_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_14165006_output #Row: " << tbl_Filter_TD_14165006_output.getNumRow() << std::endl;
}

void SW_Filter_TD_14640872(Table &tbl_SerializeFromObject_TD_15306391_input, Table &tbl_Filter_TD_14640872_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_sold_date_sk#1206) AND isnotnull(ss_item_sk#1208)))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_15306391_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_15306391_input.getInt32(i, 0);
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_15306391_input.getInt32(i, 1);
        if ((_ss_sold_date_sk1206!= 0) && (_ss_item_sk1208!= 0)) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_15306391_input.getInt32(i, 0);
            tbl_Filter_TD_14640872_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_15306391_input.getInt32(i, 1);
            tbl_Filter_TD_14640872_output.setInt32(r, 1, _ss_item_sk1208_t);
            r++;
        }
    }
    tbl_Filter_TD_14640872_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_14640872_output #Row: " << tbl_Filter_TD_14640872_output.getNumRow() << std::endl;
}

void SW_Filter_TD_13452877(Table &tbl_SerializeFromObject_TD_14255064_input, Table &tbl_Filter_TD_13452877_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(c_customer_sk#0))
    // Input: ListBuffer(c_customer_sk#0)
    // Output: ListBuffer(c_customer_sk#0)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_14255064_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk0 = tbl_SerializeFromObject_TD_14255064_input.getInt32(i, 0);
        if (_c_customer_sk0!= 0) {
            int32_t _c_customer_sk0_t = tbl_SerializeFromObject_TD_14255064_input.getInt32(i, 0);
            tbl_Filter_TD_13452877_output.setInt32(r, 0, _c_customer_sk0_t);
            r++;
        }
    }
    tbl_Filter_TD_13452877_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_13452877_output #Row: " << tbl_Filter_TD_13452877_output.getNumRow() << std::endl;
}

void SW_Filter_TD_13700909(Table &tbl_SerializeFromObject_TD_1443236_input, Table &tbl_Filter_TD_13700909_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_customer_sk#3561) AND isnotnull(ss_sold_date_sk#3558)))
    // Input: ListBuffer(ss_sold_date_sk#3558, ss_customer_sk#3561, ss_quantity#3568, ss_sales_price#3571)
    // Output: ListBuffer(ss_sold_date_sk#3558, ss_customer_sk#3561, ss_quantity#3568, ss_sales_price#3571)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1443236_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_customer_sk3561 = tbl_SerializeFromObject_TD_1443236_input.getInt32(i, 1);
        int32_t _ss_sold_date_sk3558 = tbl_SerializeFromObject_TD_1443236_input.getInt32(i, 0);
        if ((_ss_customer_sk3561!= 0) && (_ss_sold_date_sk3558!= 0)) {
            int32_t _ss_sold_date_sk3558_t = tbl_SerializeFromObject_TD_1443236_input.getInt32(i, 0);
            tbl_Filter_TD_13700909_output.setInt32(r, 0, _ss_sold_date_sk3558_t);
            int32_t _ss_customer_sk3561_t = tbl_SerializeFromObject_TD_1443236_input.getInt32(i, 1);
            tbl_Filter_TD_13700909_output.setInt32(r, 1, _ss_customer_sk3561_t);
            int32_t _ss_quantity3568_t = tbl_SerializeFromObject_TD_1443236_input.getInt32(i, 2);
            tbl_Filter_TD_13700909_output.setInt32(r, 2, _ss_quantity3568_t);
            int64_t _ss_sales_price3571_t = tbl_SerializeFromObject_TD_1443236_input.getInt64(i, 3);
            tbl_Filter_TD_13700909_output.setInt64(r, 3, _ss_sales_price3571_t);
            r++;
        }
    }
    tbl_Filter_TD_13700909_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_13700909_output #Row: " << tbl_Filter_TD_13700909_output.getNumRow() << std::endl;
}

void SW_Filter_TD_1386041(Table &tbl_SerializeFromObject_TD_14532305_input, Table &tbl_Filter_TD_1386041_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(c_customer_sk#0))
    // Input: ListBuffer(c_customer_sk#0)
    // Output: ListBuffer(c_customer_sk#0)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_14532305_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk0 = tbl_SerializeFromObject_TD_14532305_input.getInt32(i, 0);
        if (_c_customer_sk0!= 0) {
            int32_t _c_customer_sk0_t = tbl_SerializeFromObject_TD_14532305_input.getInt32(i, 0);
            tbl_Filter_TD_1386041_output.setInt32(r, 0, _c_customer_sk0_t);
            r++;
        }
    }
    tbl_Filter_TD_1386041_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1386041_output #Row: " << tbl_Filter_TD_1386041_output.getNumRow() << std::endl;
}

void SW_Filter_TD_13647399(Table &tbl_SerializeFromObject_TD_14570327_input, Table &tbl_Filter_TD_13647399_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_customer_sk#3561) AND isnotnull(ss_sold_date_sk#3558)))
    // Input: ListBuffer(ss_sold_date_sk#3558, ss_customer_sk#3561, ss_quantity#3568, ss_sales_price#3571)
    // Output: ListBuffer(ss_sold_date_sk#3558, ss_customer_sk#3561, ss_quantity#3568, ss_sales_price#3571)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_14570327_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_customer_sk3561 = tbl_SerializeFromObject_TD_14570327_input.getInt32(i, 1);
        int32_t _ss_sold_date_sk3558 = tbl_SerializeFromObject_TD_14570327_input.getInt32(i, 0);
        if ((_ss_customer_sk3561!= 0) && (_ss_sold_date_sk3558!= 0)) {
            int32_t _ss_sold_date_sk3558_t = tbl_SerializeFromObject_TD_14570327_input.getInt32(i, 0);
            tbl_Filter_TD_13647399_output.setInt32(r, 0, _ss_sold_date_sk3558_t);
            int32_t _ss_customer_sk3561_t = tbl_SerializeFromObject_TD_14570327_input.getInt32(i, 1);
            tbl_Filter_TD_13647399_output.setInt32(r, 1, _ss_customer_sk3561_t);
            int32_t _ss_quantity3568_t = tbl_SerializeFromObject_TD_14570327_input.getInt32(i, 2);
            tbl_Filter_TD_13647399_output.setInt32(r, 2, _ss_quantity3568_t);
            int64_t _ss_sales_price3571_t = tbl_SerializeFromObject_TD_14570327_input.getInt64(i, 3);
            tbl_Filter_TD_13647399_output.setInt64(r, 3, _ss_sales_price3571_t);
            r++;
        }
    }
    tbl_Filter_TD_13647399_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_13647399_output #Row: " << tbl_Filter_TD_13647399_output.getNumRow() << std::endl;
}

void SW_Filter_TD_13954360(Table &tbl_SerializeFromObject_TD_14566612_input, Table &tbl_Filter_TD_13954360_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#228))
    // Input: ListBuffer(i_item_sk#228, i_item_desc#232)
    // Output: ListBuffer(i_item_sk#228, i_item_desc#232)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_14566612_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_14566612_input.getInt32(i, 0);
        if (_i_item_sk228!= 0) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_14566612_input.getInt32(i, 0);
            tbl_Filter_TD_13954360_output.setInt32(r, 0, _i_item_sk228_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_t = tbl_SerializeFromObject_TD_14566612_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_13954360_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_desc232_t);
            r++;
        }
    }
    tbl_Filter_TD_13954360_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_13954360_output #Row: " << tbl_Filter_TD_13954360_output.getNumRow() << std::endl;
}


void SW_Filter_TD_13469673(Table &tbl_SerializeFromObject_TD_14786228_input, Table &tbl_Filter_TD_13469673_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(c_customer_sk#0))
    // Input: ListBuffer(c_customer_sk#0)
    // Output: ListBuffer(c_customer_sk#0)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_14786228_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk0 = tbl_SerializeFromObject_TD_14786228_input.getInt32(i, 0);
        if (_c_customer_sk0!= 0) {
            int32_t _c_customer_sk0_t = tbl_SerializeFromObject_TD_14786228_input.getInt32(i, 0);
            tbl_Filter_TD_13469673_output.setInt32(r, 0, _c_customer_sk0_t);
            r++;
        }
    }
    tbl_Filter_TD_13469673_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_13469673_output #Row: " << tbl_Filter_TD_13469673_output.getNumRow() << std::endl;
}

void SW_Filter_TD_13702041(Table &tbl_SerializeFromObject_TD_14673856_input, Table &tbl_Filter_TD_13702041_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_customer_sk#3561) AND isnotnull(ss_sold_date_sk#3558)))
    // Input: ListBuffer(ss_sold_date_sk#3558, ss_customer_sk#3561, ss_quantity#3568, ss_sales_price#3571)
    // Output: ListBuffer(ss_sold_date_sk#3558, ss_customer_sk#3561, ss_quantity#3568, ss_sales_price#3571)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_14673856_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_customer_sk3561 = tbl_SerializeFromObject_TD_14673856_input.getInt32(i, 1);
        int32_t _ss_sold_date_sk3558 = tbl_SerializeFromObject_TD_14673856_input.getInt32(i, 0);
        if ((_ss_customer_sk3561!= 0) && (_ss_sold_date_sk3558!= 0)) {
            int32_t _ss_sold_date_sk3558_t = tbl_SerializeFromObject_TD_14673856_input.getInt32(i, 0);
            tbl_Filter_TD_13702041_output.setInt32(r, 0, _ss_sold_date_sk3558_t);
            int32_t _ss_customer_sk3561_t = tbl_SerializeFromObject_TD_14673856_input.getInt32(i, 1);
            tbl_Filter_TD_13702041_output.setInt32(r, 1, _ss_customer_sk3561_t);
            int32_t _ss_quantity3568_t = tbl_SerializeFromObject_TD_14673856_input.getInt32(i, 2);
            tbl_Filter_TD_13702041_output.setInt32(r, 2, _ss_quantity3568_t);
            int64_t _ss_sales_price3571_t = tbl_SerializeFromObject_TD_14673856_input.getInt64(i, 3);
            tbl_Filter_TD_13702041_output.setInt64(r, 3, _ss_sales_price3571_t);
            r++;
        }
    }
    tbl_Filter_TD_13702041_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_13702041_output #Row: " << tbl_Filter_TD_13702041_output.getNumRow() << std::endl;
}

void SW_Filter_TD_13539019(Table &tbl_SerializeFromObject_TD_1452553_input, Table &tbl_Filter_TD_13539019_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(c_customer_sk#0))
    // Input: ListBuffer(c_customer_sk#0)
    // Output: ListBuffer(c_customer_sk#0)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1452553_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk0 = tbl_SerializeFromObject_TD_1452553_input.getInt32(i, 0);
        if (_c_customer_sk0!= 0) {
            int32_t _c_customer_sk0_t = tbl_SerializeFromObject_TD_1452553_input.getInt32(i, 0);
            tbl_Filter_TD_13539019_output.setInt32(r, 0, _c_customer_sk0_t);
            r++;
        }
    }
    tbl_Filter_TD_13539019_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_13539019_output #Row: " << tbl_Filter_TD_13539019_output.getNumRow() << std::endl;
}

void SW_Filter_TD_13366246(Table &tbl_SerializeFromObject_TD_14654455_input, Table &tbl_Filter_TD_13366246_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_customer_sk#3561) AND isnotnull(ss_sold_date_sk#3558)))
    // Input: ListBuffer(ss_sold_date_sk#3558, ss_customer_sk#3561, ss_quantity#3568, ss_sales_price#3571)
    // Output: ListBuffer(ss_sold_date_sk#3558, ss_customer_sk#3561, ss_quantity#3568, ss_sales_price#3571)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_14654455_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_customer_sk3561 = tbl_SerializeFromObject_TD_14654455_input.getInt32(i, 1);
        int32_t _ss_sold_date_sk3558 = tbl_SerializeFromObject_TD_14654455_input.getInt32(i, 0);
        if ((_ss_customer_sk3561!= 0) && (_ss_sold_date_sk3558!= 0)) {
            int32_t _ss_sold_date_sk3558_t = tbl_SerializeFromObject_TD_14654455_input.getInt32(i, 0);
            tbl_Filter_TD_13366246_output.setInt32(r, 0, _ss_sold_date_sk3558_t);
            int32_t _ss_customer_sk3561_t = tbl_SerializeFromObject_TD_14654455_input.getInt32(i, 1);
            tbl_Filter_TD_13366246_output.setInt32(r, 1, _ss_customer_sk3561_t);
            int32_t _ss_quantity3568_t = tbl_SerializeFromObject_TD_14654455_input.getInt32(i, 2);
            tbl_Filter_TD_13366246_output.setInt32(r, 2, _ss_quantity3568_t);
            int64_t _ss_sales_price3571_t = tbl_SerializeFromObject_TD_14654455_input.getInt64(i, 3);
            tbl_Filter_TD_13366246_output.setInt64(r, 3, _ss_sales_price3571_t);
            r++;
        }
    }
    tbl_Filter_TD_13366246_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_13366246_output #Row: " << tbl_Filter_TD_13366246_output.getNumRow() << std::endl;
}

void SW_Filter_TD_1373874(Table &tbl_SerializeFromObject_TD_14800257_input, Table &tbl_Filter_TD_1373874_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#228))
    // Input: ListBuffer(i_item_sk#228, i_item_desc#232)
    // Output: ListBuffer(i_item_sk#228, i_item_desc#232)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_14800257_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_14800257_input.getInt32(i, 0);
        if (_i_item_sk228!= 0) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_14800257_input.getInt32(i, 0);
            tbl_Filter_TD_1373874_output.setInt32(r, 0, _i_item_sk228_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_t = tbl_SerializeFromObject_TD_14800257_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_1373874_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_item_desc232_t);
            r++;
        }
    }
    tbl_Filter_TD_1373874_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1373874_output #Row: " << tbl_Filter_TD_1373874_output.getNumRow() << std::endl;
}


void SW_Filter_TD_12386496(Table &tbl_SerializeFromObject_TD_13541437_input, Table &tbl_Filter_TD_12386496_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((d_year#3587 IN (2000,2001,2002,2003) AND isnotnull(d_date_sk#3581)))
    // Input: ListBuffer(d_date_sk#3581, d_year#3587)
    // Output: ListBuffer(d_date_sk#3581)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13541437_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3587 = tbl_SerializeFromObject_TD_13541437_input.getInt32(i, 1);
        int32_t _d_date_sk3581 = tbl_SerializeFromObject_TD_13541437_input.getInt32(i, 0);
        auto reuse_col_str_797 = _d_year3587;
        if (((reuse_col_str_797 == 2000) || (reuse_col_str_797 == 2001) || (reuse_col_str_797 == 2002) || (reuse_col_str_797 == 2003) || (0)) && (_d_date_sk3581!= 0)) {
            int32_t _d_date_sk3581_t = tbl_SerializeFromObject_TD_13541437_input.getInt32(i, 0);
            tbl_Filter_TD_12386496_output.setInt32(r, 0, _d_date_sk3581_t);
            r++;
        }
    }
    tbl_Filter_TD_12386496_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12386496_output #Row: " << tbl_Filter_TD_12386496_output.getNumRow() << std::endl;
}


void SW_Filter_TD_12901777(Table &tbl_SerializeFromObject_TD_13842382_input, Table &tbl_Filter_TD_12901777_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((d_year#3587 IN (2000,2001,2002,2003) AND isnotnull(d_date_sk#3581)))
    // Input: ListBuffer(d_date_sk#3581, d_year#3587)
    // Output: ListBuffer(d_date_sk#3581)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13842382_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3587 = tbl_SerializeFromObject_TD_13842382_input.getInt32(i, 1);
        int32_t _d_date_sk3581 = tbl_SerializeFromObject_TD_13842382_input.getInt32(i, 0);
        auto reuse_col_str_223 = _d_year3587;
        if (((reuse_col_str_223 == 2000) || (reuse_col_str_223 == 2001) || (reuse_col_str_223 == 2002) || (reuse_col_str_223 == 2003) || (0)) && (_d_date_sk3581!= 0)) {
            int32_t _d_date_sk3581_t = tbl_SerializeFromObject_TD_13842382_input.getInt32(i, 0);
            tbl_Filter_TD_12901777_output.setInt32(r, 0, _d_date_sk3581_t);
            r++;
        }
    }
    tbl_Filter_TD_12901777_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12901777_output #Row: " << tbl_Filter_TD_12901777_output.getNumRow() << std::endl;
}


struct SW_JOIN_INNER_TD_12390969_key_leftMajor {
    int32_t _ss_item_sk1208;
    bool operator==(const SW_JOIN_INNER_TD_12390969_key_leftMajor& other) const {
        return ((_ss_item_sk1208 == other._ss_item_sk1208));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_12390969_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_12390969_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk1208));
    }
};
}
struct SW_JOIN_INNER_TD_12390969_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int32_t _d_date122;
};
struct SW_JOIN_INNER_TD_12390969_key_rightMajor {
    int32_t _i_item_sk228;
    bool operator==(const SW_JOIN_INNER_TD_12390969_key_rightMajor& other) const {
        return ((_i_item_sk228 == other._i_item_sk228));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_12390969_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_12390969_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk228));
    }
};
}
struct SW_JOIN_INNER_TD_12390969_payload_rightMajor {
    int32_t _i_item_sk228;
    std::string _i_item_desc232;
};
void SW_JOIN_INNER_TD_12390969(Table &tbl_JOIN_INNER_TD_13942914_output, Table &tbl_Filter_TD_13954360_output, Table &tbl_JOIN_INNER_TD_12390969_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_item_sk#1208 = i_item_sk#228))
    // Left Table: ListBuffer(ss_item_sk#1208, d_date#122)
    // Right Table: ListBuffer(i_item_sk#228, i_item_desc#232)
    // Output Table: ListBuffer(d_date#122, i_item_sk#228, i_item_desc#232)
    int left_nrow = tbl_JOIN_INNER_TD_13942914_output.getNumRow();
    int right_nrow = tbl_Filter_TD_13954360_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_12390969_key_leftMajor, SW_JOIN_INNER_TD_12390969_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_13942914_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_13942914_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_12390969_key_leftMajor keyA{_ss_item_sk1208_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_13942914_output.getInt32(i, 0);
            int32_t _d_date122 = tbl_JOIN_INNER_TD_13942914_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_12390969_payload_leftMajor payloadA{_ss_item_sk1208, _d_date122};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_13954360_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_13954360_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_12390969_key_leftMajor{_i_item_sk228_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _d_date122 = (it->second)._d_date122;
                int32_t _i_item_sk228 = tbl_Filter_TD_13954360_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n = tbl_Filter_TD_13954360_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_item_desc232 = std::string(_i_item_desc232_n.data());
                tbl_JOIN_INNER_TD_12390969_output.setInt32(r, 0, _d_date122);
                tbl_JOIN_INNER_TD_12390969_output.setInt32(r, 1, _i_item_sk228);
                tbl_JOIN_INNER_TD_12390969_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_item_desc232_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_12390969_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_12390969_key_rightMajor, SW_JOIN_INNER_TD_12390969_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_13954360_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_13954360_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_12390969_key_rightMajor keyA{_i_item_sk228_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_13954360_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n = tbl_Filter_TD_13954360_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_item_desc232 = std::string(_i_item_desc232_n.data());
            SW_JOIN_INNER_TD_12390969_payload_rightMajor payloadA{_i_item_sk228, _i_item_desc232};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_13942914_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_13942914_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_12390969_key_rightMajor{_ss_item_sk1208_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                std::string _i_item_desc232 = (it->second)._i_item_desc232;
                std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n{};
                memcpy(_i_item_desc232_n.data(), (_i_item_desc232).data(), (_i_item_desc232).length());
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_13942914_output.getInt32(i, 0);
                int32_t _d_date122 = tbl_JOIN_INNER_TD_13942914_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_12390969_output.setInt32(r, 1, _i_item_sk228);
                tbl_JOIN_INNER_TD_12390969_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_item_desc232_n);
                tbl_JOIN_INNER_TD_12390969_output.setInt32(r, 0, _d_date122);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_12390969_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_12390969_output #Row: " << tbl_JOIN_INNER_TD_12390969_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12313344(Table &tbl_SerializeFromObject_TD_13259179_input, Table &tbl_Filter_TD_12313344_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((d_year#3587 IN (2000,2001,2002,2003) AND isnotnull(d_date_sk#3581)))
    // Input: ListBuffer(d_date_sk#3581, d_year#3587)
    // Output: ListBuffer(d_date_sk#3581)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13259179_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3587 = tbl_SerializeFromObject_TD_13259179_input.getInt32(i, 1);
        int32_t _d_date_sk3581 = tbl_SerializeFromObject_TD_13259179_input.getInt32(i, 0);
        auto reuse_col_str_103 = _d_year3587;
        if (((reuse_col_str_103 == 2000) || (reuse_col_str_103 == 2001) || (reuse_col_str_103 == 2002) || (reuse_col_str_103 == 2003) || (0)) && (_d_date_sk3581!= 0)) {
            int32_t _d_date_sk3581_t = tbl_SerializeFromObject_TD_13259179_input.getInt32(i, 0);
            tbl_Filter_TD_12313344_output.setInt32(r, 0, _d_date_sk3581_t);
            r++;
        }
    }
    tbl_Filter_TD_12313344_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12313344_output #Row: " << tbl_Filter_TD_12313344_output.getNumRow() << std::endl;
}


void SW_Filter_TD_12691562(Table &tbl_SerializeFromObject_TD_13438014_input, Table &tbl_Filter_TD_12691562_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((d_year#3587 IN (2000,2001,2002,2003) AND isnotnull(d_date_sk#3581)))
    // Input: ListBuffer(d_date_sk#3581, d_year#3587)
    // Output: ListBuffer(d_date_sk#3581)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13438014_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3587 = tbl_SerializeFromObject_TD_13438014_input.getInt32(i, 1);
        int32_t _d_date_sk3581 = tbl_SerializeFromObject_TD_13438014_input.getInt32(i, 0);
        auto reuse_col_str_701 = _d_year3587;
        if (((reuse_col_str_701 == 2000) || (reuse_col_str_701 == 2001) || (reuse_col_str_701 == 2002) || (reuse_col_str_701 == 2003) || (0)) && (_d_date_sk3581!= 0)) {
            int32_t _d_date_sk3581_t = tbl_SerializeFromObject_TD_13438014_input.getInt32(i, 0);
            tbl_Filter_TD_12691562_output.setInt32(r, 0, _d_date_sk3581_t);
            r++;
        }
    }
    tbl_Filter_TD_12691562_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12691562_output #Row: " << tbl_Filter_TD_12691562_output.getNumRow() << std::endl;
}


struct SW_JOIN_INNER_TD_12731607_key_leftMajor {
    int32_t _ss_item_sk1208;
    bool operator==(const SW_JOIN_INNER_TD_12731607_key_leftMajor& other) const {
        return ((_ss_item_sk1208 == other._ss_item_sk1208));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_12731607_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_12731607_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk1208));
    }
};
}
struct SW_JOIN_INNER_TD_12731607_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int32_t _d_date122;
};
struct SW_JOIN_INNER_TD_12731607_key_rightMajor {
    int32_t _i_item_sk228;
    bool operator==(const SW_JOIN_INNER_TD_12731607_key_rightMajor& other) const {
        return ((_i_item_sk228 == other._i_item_sk228));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_12731607_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_12731607_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk228));
    }
};
}
struct SW_JOIN_INNER_TD_12731607_payload_rightMajor {
    int32_t _i_item_sk228;
    std::string _i_item_desc232;
};
void SW_JOIN_INNER_TD_12731607(Table &tbl_JOIN_INNER_TD_13287355_output, Table &tbl_Filter_TD_1373874_output, Table &tbl_JOIN_INNER_TD_12731607_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_item_sk#1208 = i_item_sk#228))
    // Left Table: ListBuffer(ss_item_sk#1208, d_date#122)
    // Right Table: ListBuffer(i_item_sk#228, i_item_desc#232)
    // Output Table: ListBuffer(d_date#122, i_item_sk#228, i_item_desc#232)
    int left_nrow = tbl_JOIN_INNER_TD_13287355_output.getNumRow();
    int right_nrow = tbl_Filter_TD_1373874_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_12731607_key_leftMajor, SW_JOIN_INNER_TD_12731607_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_13287355_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_13287355_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_12731607_key_leftMajor keyA{_ss_item_sk1208_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_13287355_output.getInt32(i, 0);
            int32_t _d_date122 = tbl_JOIN_INNER_TD_13287355_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_12731607_payload_leftMajor payloadA{_ss_item_sk1208, _d_date122};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_1373874_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_1373874_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_12731607_key_leftMajor{_i_item_sk228_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _d_date122 = (it->second)._d_date122;
                int32_t _i_item_sk228 = tbl_Filter_TD_1373874_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n = tbl_Filter_TD_1373874_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_item_desc232 = std::string(_i_item_desc232_n.data());
                tbl_JOIN_INNER_TD_12731607_output.setInt32(r, 0, _d_date122);
                tbl_JOIN_INNER_TD_12731607_output.setInt32(r, 1, _i_item_sk228);
                tbl_JOIN_INNER_TD_12731607_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_item_desc232_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_12731607_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_12731607_key_rightMajor, SW_JOIN_INNER_TD_12731607_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_1373874_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_1373874_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_12731607_key_rightMajor keyA{_i_item_sk228_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_1373874_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n = tbl_Filter_TD_1373874_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_item_desc232 = std::string(_i_item_desc232_n.data());
            SW_JOIN_INNER_TD_12731607_payload_rightMajor payloadA{_i_item_sk228, _i_item_desc232};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_13287355_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_13287355_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_12731607_key_rightMajor{_ss_item_sk1208_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                std::string _i_item_desc232 = (it->second)._i_item_desc232;
                std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232_n{};
                memcpy(_i_item_desc232_n.data(), (_i_item_desc232).data(), (_i_item_desc232).length());
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_13287355_output.getInt32(i, 0);
                int32_t _d_date122 = tbl_JOIN_INNER_TD_13287355_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_12731607_output.setInt32(r, 1, _i_item_sk228);
                tbl_JOIN_INNER_TD_12731607_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_item_desc232_n);
                tbl_JOIN_INNER_TD_12731607_output.setInt32(r, 0, _d_date122);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_12731607_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_12731607_output #Row: " << tbl_JOIN_INNER_TD_12731607_output.getNumRow() << std::endl;
}


void SW_Filter_TD_11760980(Table &tbl_SerializeFromObject_TD_12350645_input, Table &tbl_Filter_TD_11760980_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(c_customer_sk#3632))
    // Input: ListBuffer(c_customer_sk#3632)
    // Output: ListBuffer(c_customer_sk#3632)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12350645_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk3632 = tbl_SerializeFromObject_TD_12350645_input.getInt32(i, 0);
        if (_c_customer_sk3632!= 0) {
            int32_t _c_customer_sk3632_t = tbl_SerializeFromObject_TD_12350645_input.getInt32(i, 0);
            tbl_Filter_TD_11760980_output.setInt32(r, 0, _c_customer_sk3632_t);
            r++;
        }
    }
    tbl_Filter_TD_11760980_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11760980_output #Row: " << tbl_Filter_TD_11760980_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11174320(Table &tbl_SerializeFromObject_TD_12735447_input, Table &tbl_Filter_TD_11174320_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ss_customer_sk#3612))
    // Input: ListBuffer(ss_customer_sk#3612, ss_quantity#3619, ss_sales_price#3622)
    // Output: ListBuffer(ss_customer_sk#3612, ss_quantity#3619, ss_sales_price#3622)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12735447_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_customer_sk3612 = tbl_SerializeFromObject_TD_12735447_input.getInt32(i, 0);
        if (_ss_customer_sk3612!= 0) {
            int32_t _ss_customer_sk3612_t = tbl_SerializeFromObject_TD_12735447_input.getInt32(i, 0);
            tbl_Filter_TD_11174320_output.setInt32(r, 0, _ss_customer_sk3612_t);
            int32_t _ss_quantity3619_t = tbl_SerializeFromObject_TD_12735447_input.getInt32(i, 1);
            tbl_Filter_TD_11174320_output.setInt32(r, 1, _ss_quantity3619_t);
            int64_t _ss_sales_price3622_t = tbl_SerializeFromObject_TD_12735447_input.getInt64(i, 2);
            tbl_Filter_TD_11174320_output.setInt64(r, 2, _ss_sales_price3622_t);
            r++;
        }
    }
    tbl_Filter_TD_11174320_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11174320_output #Row: " << tbl_Filter_TD_11174320_output.getNumRow() << std::endl;
}


void SW_Filter_TD_11871505(Table &tbl_SerializeFromObject_TD_12680534_input, Table &tbl_Filter_TD_11871505_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(c_customer_sk#3632))
    // Input: ListBuffer(c_customer_sk#3632)
    // Output: ListBuffer(c_customer_sk#3632)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12680534_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk3632 = tbl_SerializeFromObject_TD_12680534_input.getInt32(i, 0);
        if (_c_customer_sk3632!= 0) {
            int32_t _c_customer_sk3632_t = tbl_SerializeFromObject_TD_12680534_input.getInt32(i, 0);
            tbl_Filter_TD_11871505_output.setInt32(r, 0, _c_customer_sk3632_t);
            r++;
        }
    }
    tbl_Filter_TD_11871505_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11871505_output #Row: " << tbl_Filter_TD_11871505_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11187752(Table &tbl_SerializeFromObject_TD_12747514_input, Table &tbl_Filter_TD_11187752_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ss_customer_sk#3612))
    // Input: ListBuffer(ss_customer_sk#3612, ss_quantity#3619, ss_sales_price#3622)
    // Output: ListBuffer(ss_customer_sk#3612, ss_quantity#3619, ss_sales_price#3622)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12747514_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_customer_sk3612 = tbl_SerializeFromObject_TD_12747514_input.getInt32(i, 0);
        if (_ss_customer_sk3612!= 0) {
            int32_t _ss_customer_sk3612_t = tbl_SerializeFromObject_TD_12747514_input.getInt32(i, 0);
            tbl_Filter_TD_11187752_output.setInt32(r, 0, _ss_customer_sk3612_t);
            int32_t _ss_quantity3619_t = tbl_SerializeFromObject_TD_12747514_input.getInt32(i, 1);
            tbl_Filter_TD_11187752_output.setInt32(r, 1, _ss_quantity3619_t);
            int64_t _ss_sales_price3622_t = tbl_SerializeFromObject_TD_12747514_input.getInt64(i, 2);
            tbl_Filter_TD_11187752_output.setInt64(r, 2, _ss_sales_price3622_t);
            r++;
        }
    }
    tbl_Filter_TD_11187752_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11187752_output #Row: " << tbl_Filter_TD_11187752_output.getNumRow() << std::endl;
}

void SW_Project_TD_11107252(Table &tbl_JOIN_INNER_TD_12390969_output, Table &tbl_Project_TD_11107252_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(substr(i_item_desc#232, 1, 30) AS _groupingexpression#4009)
    // Input: ListBuffer(d_date#122, i_item_sk#228, i_item_desc#232)
    // Output: ListBuffer(d_date#122, i_item_sk#228, _groupingexpression#4009)
    int nrow1 = tbl_JOIN_INNER_TD_12390969_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date122 = tbl_JOIN_INNER_TD_12390969_output.getInt32(i, 0);
        int32_t _i_item_sk228 = tbl_JOIN_INNER_TD_12390969_output.getInt32(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232 = tbl_JOIN_INNER_TD_12390969_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::string __groupingexpression4009_str = std::string(_i_item_desc232.data()).substr(0, 30);
        std::array<char, TPCDS_READ_MAX + 1> __groupingexpression4009{};
        memcpy(__groupingexpression4009.data(), __groupingexpression4009_str.data(), (__groupingexpression4009_str).length());
        tbl_Project_TD_11107252_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 2, __groupingexpression4009);
        tbl_Project_TD_11107252_output.setInt32(i, 0, _d_date122);
        tbl_Project_TD_11107252_output.setInt32(i, 1, _i_item_sk228);
    }
    tbl_Project_TD_11107252_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_11107252_output #Row: " << tbl_Project_TD_11107252_output.getNumRow() << std::endl;
}


void SW_Filter_TD_11361028(Table &tbl_SerializeFromObject_TD_1223068_input, Table &tbl_Filter_TD_11361028_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(c_customer_sk#3632))
    // Input: ListBuffer(c_customer_sk#3632)
    // Output: ListBuffer(c_customer_sk#3632)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1223068_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk3632 = tbl_SerializeFromObject_TD_1223068_input.getInt32(i, 0);
        if (_c_customer_sk3632!= 0) {
            int32_t _c_customer_sk3632_t = tbl_SerializeFromObject_TD_1223068_input.getInt32(i, 0);
            tbl_Filter_TD_11361028_output.setInt32(r, 0, _c_customer_sk3632_t);
            r++;
        }
    }
    tbl_Filter_TD_11361028_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11361028_output #Row: " << tbl_Filter_TD_11361028_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11510993(Table &tbl_SerializeFromObject_TD_12390145_input, Table &tbl_Filter_TD_11510993_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ss_customer_sk#3612))
    // Input: ListBuffer(ss_customer_sk#3612, ss_quantity#3619, ss_sales_price#3622)
    // Output: ListBuffer(ss_customer_sk#3612, ss_quantity#3619, ss_sales_price#3622)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12390145_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_customer_sk3612 = tbl_SerializeFromObject_TD_12390145_input.getInt32(i, 0);
        if (_ss_customer_sk3612!= 0) {
            int32_t _ss_customer_sk3612_t = tbl_SerializeFromObject_TD_12390145_input.getInt32(i, 0);
            tbl_Filter_TD_11510993_output.setInt32(r, 0, _ss_customer_sk3612_t);
            int32_t _ss_quantity3619_t = tbl_SerializeFromObject_TD_12390145_input.getInt32(i, 1);
            tbl_Filter_TD_11510993_output.setInt32(r, 1, _ss_quantity3619_t);
            int64_t _ss_sales_price3622_t = tbl_SerializeFromObject_TD_12390145_input.getInt64(i, 2);
            tbl_Filter_TD_11510993_output.setInt64(r, 2, _ss_sales_price3622_t);
            r++;
        }
    }
    tbl_Filter_TD_11510993_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11510993_output #Row: " << tbl_Filter_TD_11510993_output.getNumRow() << std::endl;
}


void SW_Filter_TD_11957528(Table &tbl_SerializeFromObject_TD_12783408_input, Table &tbl_Filter_TD_11957528_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(c_customer_sk#3632))
    // Input: ListBuffer(c_customer_sk#3632)
    // Output: ListBuffer(c_customer_sk#3632)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12783408_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk3632 = tbl_SerializeFromObject_TD_12783408_input.getInt32(i, 0);
        if (_c_customer_sk3632!= 0) {
            int32_t _c_customer_sk3632_t = tbl_SerializeFromObject_TD_12783408_input.getInt32(i, 0);
            tbl_Filter_TD_11957528_output.setInt32(r, 0, _c_customer_sk3632_t);
            r++;
        }
    }
    tbl_Filter_TD_11957528_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11957528_output #Row: " << tbl_Filter_TD_11957528_output.getNumRow() << std::endl;
}

void SW_Filter_TD_11726486(Table &tbl_SerializeFromObject_TD_12133188_input, Table &tbl_Filter_TD_11726486_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ss_customer_sk#3612))
    // Input: ListBuffer(ss_customer_sk#3612, ss_quantity#3619, ss_sales_price#3622)
    // Output: ListBuffer(ss_customer_sk#3612, ss_quantity#3619, ss_sales_price#3622)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_12133188_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_customer_sk3612 = tbl_SerializeFromObject_TD_12133188_input.getInt32(i, 0);
        if (_ss_customer_sk3612!= 0) {
            int32_t _ss_customer_sk3612_t = tbl_SerializeFromObject_TD_12133188_input.getInt32(i, 0);
            tbl_Filter_TD_11726486_output.setInt32(r, 0, _ss_customer_sk3612_t);
            int32_t _ss_quantity3619_t = tbl_SerializeFromObject_TD_12133188_input.getInt32(i, 1);
            tbl_Filter_TD_11726486_output.setInt32(r, 1, _ss_quantity3619_t);
            int64_t _ss_sales_price3622_t = tbl_SerializeFromObject_TD_12133188_input.getInt64(i, 2);
            tbl_Filter_TD_11726486_output.setInt64(r, 2, _ss_sales_price3622_t);
            r++;
        }
    }
    tbl_Filter_TD_11726486_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_11726486_output #Row: " << tbl_Filter_TD_11726486_output.getNumRow() << std::endl;
}

void SW_Project_TD_11995959(Table &tbl_JOIN_INNER_TD_12731607_output, Table &tbl_Project_TD_11995959_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(substr(i_item_desc#232, 1, 30) AS _groupingexpression#4008)
    // Input: ListBuffer(d_date#122, i_item_sk#228, i_item_desc#232)
    // Output: ListBuffer(d_date#122, i_item_sk#228, _groupingexpression#4008)
    int nrow1 = tbl_JOIN_INNER_TD_12731607_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date122 = tbl_JOIN_INNER_TD_12731607_output.getInt32(i, 0);
        int32_t _i_item_sk228 = tbl_JOIN_INNER_TD_12731607_output.getInt32(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _i_item_desc232 = tbl_JOIN_INNER_TD_12731607_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::string __groupingexpression4008_str = std::string(_i_item_desc232.data()).substr(0, 30);
        std::array<char, TPCDS_READ_MAX + 1> __groupingexpression4008{};
        memcpy(__groupingexpression4008.data(), __groupingexpression4008_str.data(), (__groupingexpression4008_str).length());
        tbl_Project_TD_11995959_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 2, __groupingexpression4008);
        tbl_Project_TD_11995959_output.setInt32(i, 0, _d_date122);
        tbl_Project_TD_11995959_output.setInt32(i, 1, _i_item_sk228);
    }
    tbl_Project_TD_11995959_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_11995959_output #Row: " << tbl_Project_TD_11995959_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_10391355_consolidate(Table &tbl_Aggregate_TD_10391355_output_preprocess, Table &tbl_Aggregate_TD_10391355_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_10391355_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int64_t _csales3554 = tbl_Aggregate_TD_10391355_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_10391355_output.setInt64(r, 0, _csales3554);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_10391355_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_10391355_output #Row: " << tbl_Aggregate_TD_10391355_output.getNumRow() << std::endl;
}


void SW_Aggregate_TD_10114900_consolidate(Table &tbl_Aggregate_TD_10114900_output_preprocess, Table &tbl_Aggregate_TD_10114900_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_10114900_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int64_t _csales3554 = tbl_Aggregate_TD_10114900_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_10114900_output.setInt64(r, 0, _csales3554);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_10114900_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_10114900_output #Row: " << tbl_Aggregate_TD_10114900_output.getNumRow() << std::endl;
}


struct SW_Aggregate_TD_10874103_key {
    std::string __groupingexpression4009;
    int32_t _i_item_sk228;
    int32_t _d_date122;
    bool operator==(const SW_Aggregate_TD_10874103_key& other) const { return (__groupingexpression4009 == other.__groupingexpression4009) && (_i_item_sk228 == other._i_item_sk228) && (_d_date122 == other._d_date122); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_10874103_key> {
    std::size_t operator() (const SW_Aggregate_TD_10874103_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k.__groupingexpression4009)) + (hash<int32_t>()(k._i_item_sk228)) + (hash<int32_t>()(k._d_date122));
    }
};
}
struct SW_Aggregate_TD_10874103_payload {
    int32_t _item_sk3551;
    int64_t _cnt3553L_count_0;
};
void SW_Aggregate_TD_10874103(Table &tbl_Project_TD_11107252_output, Table &tbl_Aggregate_TD_10874103_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(_groupingexpression#4009, i_item_sk#228, d_date#122, i_item_sk#228 AS item_sk#3551, count(1) AS cnt#3553L)
    // Input: ListBuffer(d_date#122, i_item_sk#228, _groupingexpression#4009)
    // Output: ListBuffer(item_sk#3551, cnt#3553L)
    std::unordered_map<SW_Aggregate_TD_10874103_key, SW_Aggregate_TD_10874103_payload> ht1;
    int nrow1 = tbl_Project_TD_11107252_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date122 = tbl_Project_TD_11107252_output.getInt32(i, 0);
        int32_t _i_item_sk228 = tbl_Project_TD_11107252_output.getInt32(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> __groupingexpression4009 = tbl_Project_TD_11107252_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        SW_Aggregate_TD_10874103_key k{std::string(__groupingexpression4009.data()), _i_item_sk228, _d_date122};
        int32_t _item_sk3551 = _i_item_sk228;
        int64_t _cnt3553L_count_0 = 1 != 0 ? 1 : 0;
        SW_Aggregate_TD_10874103_payload p{_item_sk3551, _cnt3553L_count_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t count_0 = (it->second)._cnt3553L_count_0 + _cnt3553L_count_0;
            p._cnt3553L_count_0 = count_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // __groupingexpression4009 not required in the output table
        // _i_item_sk228 not required in the output table
        // _d_date122 not required in the output table
        tbl_Aggregate_TD_10874103_output.setInt32(r, 0, (it.second)._item_sk3551);
        int64_t _cnt3553L = (it.second)._cnt3553L_count_0;
        tbl_Aggregate_TD_10874103_output.setInt64(r, 1, _cnt3553L);
        ++r;
    }
    tbl_Aggregate_TD_10874103_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_10874103_output #Row: " << tbl_Aggregate_TD_10874103_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_10779337_consolidate(Table &tbl_Aggregate_TD_10779337_output_preprocess, Table &tbl_Aggregate_TD_10779337_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_10779337_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int64_t _csales3554 = tbl_Aggregate_TD_10779337_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_10779337_output.setInt64(r, 0, _csales3554);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_10779337_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_10779337_output #Row: " << tbl_Aggregate_TD_10779337_output.getNumRow() << std::endl;
}


void SW_Aggregate_TD_10940044_consolidate(Table &tbl_Aggregate_TD_10940044_output_preprocess, Table &tbl_Aggregate_TD_10940044_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_10940044_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int64_t _csales3554 = tbl_Aggregate_TD_10940044_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_10940044_output.setInt64(r, 0, _csales3554);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_10940044_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_10940044_output #Row: " << tbl_Aggregate_TD_10940044_output.getNumRow() << std::endl;
}


struct SW_Aggregate_TD_10150991_key {
    std::string __groupingexpression4008;
    int32_t _i_item_sk228;
    int32_t _d_date122;
    bool operator==(const SW_Aggregate_TD_10150991_key& other) const { return (__groupingexpression4008 == other.__groupingexpression4008) && (_i_item_sk228 == other._i_item_sk228) && (_d_date122 == other._d_date122); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_10150991_key> {
    std::size_t operator() (const SW_Aggregate_TD_10150991_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k.__groupingexpression4008)) + (hash<int32_t>()(k._i_item_sk228)) + (hash<int32_t>()(k._d_date122));
    }
};
}
struct SW_Aggregate_TD_10150991_payload {
    int32_t _item_sk3551;
    int64_t _cnt3553L_count_0;
};
void SW_Aggregate_TD_10150991(Table &tbl_Project_TD_11995959_output, Table &tbl_Aggregate_TD_10150991_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(_groupingexpression#4008, i_item_sk#228, d_date#122, i_item_sk#228 AS item_sk#3551, count(1) AS cnt#3553L)
    // Input: ListBuffer(d_date#122, i_item_sk#228, _groupingexpression#4008)
    // Output: ListBuffer(item_sk#3551, cnt#3553L)
    std::unordered_map<SW_Aggregate_TD_10150991_key, SW_Aggregate_TD_10150991_payload> ht1;
    int nrow1 = tbl_Project_TD_11995959_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date122 = tbl_Project_TD_11995959_output.getInt32(i, 0);
        int32_t _i_item_sk228 = tbl_Project_TD_11995959_output.getInt32(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> __groupingexpression4008 = tbl_Project_TD_11995959_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        SW_Aggregate_TD_10150991_key k{std::string(__groupingexpression4008.data()), _i_item_sk228, _d_date122};
        int32_t _item_sk3551 = _i_item_sk228;
        int64_t _cnt3553L_count_0 = 1 != 0 ? 1 : 0;
        SW_Aggregate_TD_10150991_payload p{_item_sk3551, _cnt3553L_count_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t count_0 = (it->second)._cnt3553L_count_0 + _cnt3553L_count_0;
            p._cnt3553L_count_0 = count_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // __groupingexpression4008 not required in the output table
        // _i_item_sk228 not required in the output table
        // _d_date122 not required in the output table
        tbl_Aggregate_TD_10150991_output.setInt32(r, 0, (it.second)._item_sk3551);
        int64_t _cnt3553L = (it.second)._cnt3553L_count_0;
        tbl_Aggregate_TD_10150991_output.setInt64(r, 1, _cnt3553L);
        ++r;
    }
    tbl_Aggregate_TD_10150991_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_10150991_output #Row: " << tbl_Aggregate_TD_10150991_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_9116253(Table &tbl_Aggregate_TD_10391355_output, Table &tbl_Aggregate_TD_9116253_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(max(csales#3554) AS tpcds_cmax#3555)
    // Input: ListBuffer(csales#3554)
    // Output: ListBuffer(tpcds_cmax#3555)
    int64_t max_0 = 0;
    int nrow1 = tbl_Aggregate_TD_10391355_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _csales3554 = tbl_Aggregate_TD_10391355_output.getInt64(i, 0);
        int64_t _tpcds_cmax3555_max_0 = _csales3554;
        max_0 = max_0 < _tpcds_cmax3555_max_0 ? _tpcds_cmax3555_max_0 : max_0;
    }
    int r = 0;
    int64_t _tpcds_cmax3555 = max_0;
    tbl_Aggregate_TD_9116253_output.setInt64(r++, 0, _tpcds_cmax3555);
    tbl_Aggregate_TD_9116253_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_9116253_output #Row: " << tbl_Aggregate_TD_9116253_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_9533960_consolidate(Table &tbl_Aggregate_TD_9533960_output_preprocess, Table &tbl_Aggregate_TD_9533960_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_9533960_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _c_customer_sk3632 = tbl_Aggregate_TD_9533960_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_9533960_output.setInt32(r, 0, _c_customer_sk3632);
        int64_t _ssales3556 = tbl_Aggregate_TD_9533960_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_9533960_output.setInt64(r, 1, _ssales3556);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_9533960_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_9533960_output #Row: " << tbl_Aggregate_TD_9533960_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_9132965(Table &tbl_Aggregate_TD_10114900_output, Table &tbl_Aggregate_TD_9132965_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(max(csales#3554) AS tpcds_cmax#3555)
    // Input: ListBuffer(csales#3554)
    // Output: ListBuffer(tpcds_cmax#3555)
    int64_t max_0 = 0;
    int nrow1 = tbl_Aggregate_TD_10114900_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _csales3554 = tbl_Aggregate_TD_10114900_output.getInt64(i, 0);
        int64_t _tpcds_cmax3555_max_0 = _csales3554;
        max_0 = max_0 < _tpcds_cmax3555_max_0 ? _tpcds_cmax3555_max_0 : max_0;
    }
    int r = 0;
    int64_t _tpcds_cmax3555 = max_0;
    tbl_Aggregate_TD_9132965_output.setInt64(r++, 0, _tpcds_cmax3555);
    tbl_Aggregate_TD_9132965_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_9132965_output #Row: " << tbl_Aggregate_TD_9132965_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_9948690_consolidate(Table &tbl_Aggregate_TD_9948690_output_preprocess, Table &tbl_Aggregate_TD_9948690_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_9948690_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _c_customer_sk3632 = tbl_Aggregate_TD_9948690_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_9948690_output.setInt32(r, 0, _c_customer_sk3632);
        int64_t _ssales3556 = tbl_Aggregate_TD_9948690_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_9948690_output.setInt64(r, 1, _ssales3556);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_9948690_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_9948690_output #Row: " << tbl_Aggregate_TD_9948690_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9735928(Table &tbl_Aggregate_TD_10874103_output, Table &tbl_Filter_TD_9735928_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((cnt#3553L > 4))
    // Input: ListBuffer(item_sk#3551, cnt#3553L)
    // Output: ListBuffer(item_sk#3551)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_10874103_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _cnt3553L = tbl_Aggregate_TD_10874103_output.getInt64(i, 1);
        if (_cnt3553L > 4) {
            int32_t _item_sk3551_t = tbl_Aggregate_TD_10874103_output.getInt32(i, 0);
            tbl_Filter_TD_9735928_output.setInt32(r, 0, _item_sk3551_t);
            r++;
        }
    }
    tbl_Filter_TD_9735928_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9735928_output #Row: " << tbl_Filter_TD_9735928_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9697381(Table &tbl_SerializeFromObject_TD_10269486_input, Table &tbl_Filter_TD_9697381_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_bill_customer_sk#733) AND isnotnull(ws_sold_date_sk#729)))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_bill_customer_sk#733, ws_quantity#747, ws_list_price#749)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_bill_customer_sk#733, ws_quantity#747, ws_list_price#749)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10269486_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_bill_customer_sk733 = tbl_SerializeFromObject_TD_10269486_input.getInt32(i, 2);
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_10269486_input.getInt32(i, 0);
        if ((_ws_bill_customer_sk733!= 0) && (_ws_sold_date_sk729!= 0)) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_10269486_input.getInt32(i, 0);
            tbl_Filter_TD_9697381_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_item_sk732_t = tbl_SerializeFromObject_TD_10269486_input.getInt32(i, 1);
            tbl_Filter_TD_9697381_output.setInt32(r, 1, _ws_item_sk732_t);
            int32_t _ws_bill_customer_sk733_t = tbl_SerializeFromObject_TD_10269486_input.getInt32(i, 2);
            tbl_Filter_TD_9697381_output.setInt32(r, 2, _ws_bill_customer_sk733_t);
            int32_t _ws_quantity747_t = tbl_SerializeFromObject_TD_10269486_input.getInt32(i, 3);
            tbl_Filter_TD_9697381_output.setInt32(r, 3, _ws_quantity747_t);
            int64_t _ws_list_price749_t = tbl_SerializeFromObject_TD_10269486_input.getInt64(i, 4);
            tbl_Filter_TD_9697381_output.setInt64(r, 4, _ws_list_price749_t);
            r++;
        }
    }
    tbl_Filter_TD_9697381_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9697381_output #Row: " << tbl_Filter_TD_9697381_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_9773538(Table &tbl_Aggregate_TD_10779337_output, Table &tbl_Aggregate_TD_9773538_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(max(csales#3554) AS tpcds_cmax#3555)
    // Input: ListBuffer(csales#3554)
    // Output: ListBuffer(tpcds_cmax#3555)
    int64_t max_0 = 0;
    int nrow1 = tbl_Aggregate_TD_10779337_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _csales3554 = tbl_Aggregate_TD_10779337_output.getInt64(i, 0);
        int64_t _tpcds_cmax3555_max_0 = _csales3554;
        max_0 = max_0 < _tpcds_cmax3555_max_0 ? _tpcds_cmax3555_max_0 : max_0;
    }
    int r = 0;
    int64_t _tpcds_cmax3555 = max_0;
    tbl_Aggregate_TD_9773538_output.setInt64(r++, 0, _tpcds_cmax3555);
    tbl_Aggregate_TD_9773538_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_9773538_output #Row: " << tbl_Aggregate_TD_9773538_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_9394832_consolidate(Table &tbl_Aggregate_TD_9394832_output_preprocess, Table &tbl_Aggregate_TD_9394832_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_9394832_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _c_customer_sk3632 = tbl_Aggregate_TD_9394832_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_9394832_output.setInt32(r, 0, _c_customer_sk3632);
        int64_t _ssales3556 = tbl_Aggregate_TD_9394832_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_9394832_output.setInt64(r, 1, _ssales3556);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_9394832_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_9394832_output #Row: " << tbl_Aggregate_TD_9394832_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_9707922(Table &tbl_Aggregate_TD_10940044_output, Table &tbl_Aggregate_TD_9707922_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(max(csales#3554) AS tpcds_cmax#3555)
    // Input: ListBuffer(csales#3554)
    // Output: ListBuffer(tpcds_cmax#3555)
    int64_t max_0 = 0;
    int nrow1 = tbl_Aggregate_TD_10940044_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _csales3554 = tbl_Aggregate_TD_10940044_output.getInt64(i, 0);
        int64_t _tpcds_cmax3555_max_0 = _csales3554;
        max_0 = max_0 < _tpcds_cmax3555_max_0 ? _tpcds_cmax3555_max_0 : max_0;
    }
    int r = 0;
    int64_t _tpcds_cmax3555 = max_0;
    tbl_Aggregate_TD_9707922_output.setInt64(r++, 0, _tpcds_cmax3555);
    tbl_Aggregate_TD_9707922_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_9707922_output #Row: " << tbl_Aggregate_TD_9707922_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_9241296_consolidate(Table &tbl_Aggregate_TD_9241296_output_preprocess, Table &tbl_Aggregate_TD_9241296_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_9241296_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _c_customer_sk3632 = tbl_Aggregate_TD_9241296_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_9241296_output.setInt32(r, 0, _c_customer_sk3632);
        int64_t _ssales3556 = tbl_Aggregate_TD_9241296_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_9241296_output.setInt64(r, 1, _ssales3556);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_9241296_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_9241296_output #Row: " << tbl_Aggregate_TD_9241296_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9527090(Table &tbl_Aggregate_TD_10150991_output, Table &tbl_Filter_TD_9527090_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((cnt#3553L > 4))
    // Input: ListBuffer(item_sk#3551, cnt#3553L)
    // Output: ListBuffer(item_sk#3551)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_10150991_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _cnt3553L = tbl_Aggregate_TD_10150991_output.getInt64(i, 1);
        if (_cnt3553L > 4) {
            int32_t _item_sk3551_t = tbl_Aggregate_TD_10150991_output.getInt32(i, 0);
            tbl_Filter_TD_9527090_output.setInt32(r, 0, _item_sk3551_t);
            r++;
        }
    }
    tbl_Filter_TD_9527090_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9527090_output #Row: " << tbl_Filter_TD_9527090_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9849852(Table &tbl_SerializeFromObject_TD_10110473_input, Table &tbl_Filter_TD_9849852_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cs_bill_customer_sk#1107) AND isnotnull(cs_sold_date_sk#1104)))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_item_sk#1119, cs_quantity#1122, cs_list_price#1124)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_item_sk#1119, cs_quantity#1122, cs_list_price#1124)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10110473_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_bill_customer_sk1107 = tbl_SerializeFromObject_TD_10110473_input.getInt32(i, 1);
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_10110473_input.getInt32(i, 0);
        if ((_cs_bill_customer_sk1107!= 0) && (_cs_sold_date_sk1104!= 0)) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_10110473_input.getInt32(i, 0);
            tbl_Filter_TD_9849852_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int32_t _cs_bill_customer_sk1107_t = tbl_SerializeFromObject_TD_10110473_input.getInt32(i, 1);
            tbl_Filter_TD_9849852_output.setInt32(r, 1, _cs_bill_customer_sk1107_t);
            int32_t _cs_item_sk1119_t = tbl_SerializeFromObject_TD_10110473_input.getInt32(i, 2);
            tbl_Filter_TD_9849852_output.setInt32(r, 2, _cs_item_sk1119_t);
            int32_t _cs_quantity1122_t = tbl_SerializeFromObject_TD_10110473_input.getInt32(i, 3);
            tbl_Filter_TD_9849852_output.setInt32(r, 3, _cs_quantity1122_t);
            int64_t _cs_list_price1124_t = tbl_SerializeFromObject_TD_10110473_input.getInt64(i, 4);
            tbl_Filter_TD_9849852_output.setInt64(r, 4, _cs_list_price1124_t);
            r++;
        }
    }
    tbl_Filter_TD_9849852_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9849852_output #Row: " << tbl_Filter_TD_9849852_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8101406(Table &tbl_Aggregate_TD_9533960_output, Table &tbl_Aggregate_TD_9116253_output, Table &tbl_Filter_TD_8101406_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ssales#3556) AND (cast(ssales#3556 as decimal(38,8)) > CheckOverflow((0.950000 * promote_precision(cast(scalar-subquery#3557 [] as decimal(32,6)))), DecimalType(38,8), true))))
    // Input: ListBuffer(c_customer_sk#3632, ssales#3556)
    // Output: ListBuffer(c_customer_sk#3632)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_9533960_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ssales3556 = tbl_Aggregate_TD_9533960_output.getInt64(i, 1);
        if ((_ssales3556!= 0) && (_ssales3556 > (0.950000 * tbl_Aggregate_TD_9116253_output.getInt64(0, 0)))) {
            int32_t _c_customer_sk3632_t = tbl_Aggregate_TD_9533960_output.getInt32(i, 0);
            tbl_Filter_TD_8101406_output.setInt32(r, 0, _c_customer_sk3632_t);
            r++;
        }
    }
    tbl_Filter_TD_8101406_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8101406_output #Row: " << tbl_Filter_TD_8101406_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8166631(Table &tbl_SerializeFromObject_TD_9255648_input, Table &tbl_Filter_TD_8166631_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(c_customer_sk#3696))
    // Input: ListBuffer(c_customer_sk#3696, c_first_name#3704, c_last_name#3705)
    // Output: ListBuffer(c_customer_sk#3696, c_first_name#3704, c_last_name#3705)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9255648_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk3696 = tbl_SerializeFromObject_TD_9255648_input.getInt32(i, 0);
        if (_c_customer_sk3696!= 0) {
            int32_t _c_customer_sk3696_t = tbl_SerializeFromObject_TD_9255648_input.getInt32(i, 0);
            tbl_Filter_TD_8166631_output.setInt32(r, 0, _c_customer_sk3696_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name3704_t = tbl_SerializeFromObject_TD_9255648_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_8166631_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name3704_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name3705_t = tbl_SerializeFromObject_TD_9255648_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_8166631_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name3705_t);
            r++;
        }
    }
    tbl_Filter_TD_8166631_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8166631_output #Row: " << tbl_Filter_TD_8166631_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8261746(Table &tbl_Aggregate_TD_9948690_output, Table &tbl_Aggregate_TD_9132965_output, Table &tbl_Filter_TD_8261746_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ssales#3556) AND (cast(ssales#3556 as decimal(38,8)) > CheckOverflow((0.950000 * promote_precision(cast(scalar-subquery#3557 [] as decimal(32,6)))), DecimalType(38,8), true))))
    // Input: ListBuffer(c_customer_sk#3632, ssales#3556)
    // Output: ListBuffer(c_customer_sk#3632)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_9948690_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ssales3556 = tbl_Aggregate_TD_9948690_output.getInt64(i, 1);
        if ((_ssales3556!= 0) && (_ssales3556 > (0.950000 * tbl_Aggregate_TD_9132965_output.getInt64(0, 0)))) {
            int32_t _c_customer_sk3632_t = tbl_Aggregate_TD_9948690_output.getInt32(i, 0);
            tbl_Filter_TD_8261746_output.setInt32(r, 0, _c_customer_sk3632_t);
            r++;
        }
    }
    tbl_Filter_TD_8261746_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8261746_output #Row: " << tbl_Filter_TD_8261746_output.getNumRow() << std::endl;
}


void SW_Filter_TD_8479531(Table &tbl_Aggregate_TD_9394832_output, Table &tbl_Aggregate_TD_9773538_output, Table &tbl_Filter_TD_8479531_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ssales#3556) AND (cast(ssales#3556 as decimal(38,8)) > CheckOverflow((0.950000 * promote_precision(cast(scalar-subquery#3557 [] as decimal(32,6)))), DecimalType(38,8), true))))
    // Input: ListBuffer(c_customer_sk#3632, ssales#3556)
    // Output: ListBuffer(c_customer_sk#3632)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_9394832_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ssales3556 = tbl_Aggregate_TD_9394832_output.getInt64(i, 1);
        if ((_ssales3556!= 0) && (_ssales3556 > (0.950000 * tbl_Aggregate_TD_9773538_output.getInt64(0, 0)))) {
            int32_t _c_customer_sk3632_t = tbl_Aggregate_TD_9394832_output.getInt32(i, 0);
            tbl_Filter_TD_8479531_output.setInt32(r, 0, _c_customer_sk3632_t);
            r++;
        }
    }
    tbl_Filter_TD_8479531_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8479531_output #Row: " << tbl_Filter_TD_8479531_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8727146(Table &tbl_SerializeFromObject_TD_9246457_input, Table &tbl_Filter_TD_8727146_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(c_customer_sk#3650))
    // Input: ListBuffer(c_customer_sk#3650, c_first_name#3658, c_last_name#3659)
    // Output: ListBuffer(c_customer_sk#3650, c_first_name#3658, c_last_name#3659)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9246457_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk3650 = tbl_SerializeFromObject_TD_9246457_input.getInt32(i, 0);
        if (_c_customer_sk3650!= 0) {
            int32_t _c_customer_sk3650_t = tbl_SerializeFromObject_TD_9246457_input.getInt32(i, 0);
            tbl_Filter_TD_8727146_output.setInt32(r, 0, _c_customer_sk3650_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name3658_t = tbl_SerializeFromObject_TD_9246457_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_8727146_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name3658_t);
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name3659_t = tbl_SerializeFromObject_TD_9246457_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_8727146_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name3659_t);
            r++;
        }
    }
    tbl_Filter_TD_8727146_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8727146_output #Row: " << tbl_Filter_TD_8727146_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8434144(Table &tbl_Aggregate_TD_9241296_output, Table &tbl_Aggregate_TD_9707922_output, Table &tbl_Filter_TD_8434144_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ssales#3556) AND (cast(ssales#3556 as decimal(38,8)) > CheckOverflow((0.950000 * promote_precision(cast(scalar-subquery#3557 [] as decimal(32,6)))), DecimalType(38,8), true))))
    // Input: ListBuffer(c_customer_sk#3632, ssales#3556)
    // Output: ListBuffer(c_customer_sk#3632)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_9241296_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ssales3556 = tbl_Aggregate_TD_9241296_output.getInt64(i, 1);
        if ((_ssales3556!= 0) && (_ssales3556 > (0.950000 * tbl_Aggregate_TD_9707922_output.getInt64(0, 0)))) {
            int32_t _c_customer_sk3632_t = tbl_Aggregate_TD_9241296_output.getInt32(i, 0);
            tbl_Filter_TD_8434144_output.setInt32(r, 0, _c_customer_sk3632_t);
            r++;
        }
    }
    tbl_Filter_TD_8434144_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8434144_output #Row: " << tbl_Filter_TD_8434144_output.getNumRow() << std::endl;
}


struct SW_JOIN_LEFTSEMI_TD_7221819_key_leftMajor {
    int32_t _c_customer_sk3696;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_7221819_key_leftMajor& other) const {
        return ((_c_customer_sk3696 == other._c_customer_sk3696));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_7221819_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_7221819_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk3696));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_7221819_payload_leftMajor {
    int32_t _c_customer_sk3696;
    std::string _c_first_name3704;
    std::string _c_last_name3705;
};
struct SW_JOIN_LEFTSEMI_TD_7221819_key_rightMajor {
    int32_t _c_customer_sk3632;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_7221819_key_rightMajor& other) const {
        return ((_c_customer_sk3632 == other._c_customer_sk3632));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_7221819_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_7221819_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk3632));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_7221819_payload_rightMajor {
    int32_t _c_customer_sk3632;
};
void SW_JOIN_LEFTSEMI_TD_7221819(Table &tbl_Filter_TD_8166631_output, Table &tbl_Filter_TD_8101406_output, Table &tbl_JOIN_LEFTSEMI_TD_7221819_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTSEMI
    // Operation: ListBuffer((c_customer_sk#3696 = c_customer_sk#3632))
    // Left Table: ListBuffer(c_customer_sk#3696, c_first_name#3704, c_last_name#3705)
    // Right Table: ListBuffer(c_customer_sk#3632)
    // Output Table: ListBuffer(c_customer_sk#3696, c_first_name#3704, c_last_name#3705)
    int left_nrow = tbl_Filter_TD_8166631_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8101406_output.getNumRow();
        std::unordered_map<SW_JOIN_LEFTSEMI_TD_7221819_key_rightMajor, SW_JOIN_LEFTSEMI_TD_7221819_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8101406_output.getNumRow();
        int nrow2 = tbl_Filter_TD_8166631_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk3632_k = tbl_Filter_TD_8101406_output.getInt32(i, 0);
            SW_JOIN_LEFTSEMI_TD_7221819_key_rightMajor keyA{_c_customer_sk3632_k};
            int32_t _c_customer_sk3632 = tbl_Filter_TD_8101406_output.getInt32(i, 0);
            SW_JOIN_LEFTSEMI_TD_7221819_payload_rightMajor payloadA{_c_customer_sk3632};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk3696_k = tbl_Filter_TD_8166631_output.getInt32(i, 0);
            auto it = ht1.find(SW_JOIN_LEFTSEMI_TD_7221819_key_rightMajor{_c_customer_sk3696_k});
            if (it != ht1.end()) {
                int32_t _c_customer_sk3696 = tbl_Filter_TD_8166631_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name3704 = tbl_Filter_TD_8166631_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name3705 = tbl_Filter_TD_8166631_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                tbl_JOIN_LEFTSEMI_TD_7221819_output.setInt32(r, 0, _c_customer_sk3696);
                tbl_JOIN_LEFTSEMI_TD_7221819_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name3704);
                tbl_JOIN_LEFTSEMI_TD_7221819_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name3705);
                r++;
            }
        }
        tbl_JOIN_LEFTSEMI_TD_7221819_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTSEMI_TD_7221819_output #Row: " << tbl_JOIN_LEFTSEMI_TD_7221819_output.getNumRow() << std::endl;
}


struct SW_JOIN_LEFTSEMI_TD_7493952_key_leftMajor {
    int32_t _c_customer_sk3650;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_7493952_key_leftMajor& other) const {
        return ((_c_customer_sk3650 == other._c_customer_sk3650));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_7493952_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_7493952_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk3650));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_7493952_payload_leftMajor {
    int32_t _c_customer_sk3650;
    std::string _c_first_name3658;
    std::string _c_last_name3659;
};
struct SW_JOIN_LEFTSEMI_TD_7493952_key_rightMajor {
    int32_t _c_customer_sk3632;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_7493952_key_rightMajor& other) const {
        return ((_c_customer_sk3632 == other._c_customer_sk3632));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_7493952_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_7493952_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk3632));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_7493952_payload_rightMajor {
    int32_t _c_customer_sk3632;
};
void SW_JOIN_LEFTSEMI_TD_7493952(Table &tbl_Filter_TD_8727146_output, Table &tbl_Filter_TD_8479531_output, Table &tbl_JOIN_LEFTSEMI_TD_7493952_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTSEMI
    // Operation: ListBuffer((c_customer_sk#3650 = c_customer_sk#3632))
    // Left Table: ListBuffer(c_customer_sk#3650, c_first_name#3658, c_last_name#3659)
    // Right Table: ListBuffer(c_customer_sk#3632)
    // Output Table: ListBuffer(c_customer_sk#3650, c_first_name#3658, c_last_name#3659)
    int left_nrow = tbl_Filter_TD_8727146_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8479531_output.getNumRow();
        std::unordered_map<SW_JOIN_LEFTSEMI_TD_7493952_key_rightMajor, SW_JOIN_LEFTSEMI_TD_7493952_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8479531_output.getNumRow();
        int nrow2 = tbl_Filter_TD_8727146_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk3632_k = tbl_Filter_TD_8479531_output.getInt32(i, 0);
            SW_JOIN_LEFTSEMI_TD_7493952_key_rightMajor keyA{_c_customer_sk3632_k};
            int32_t _c_customer_sk3632 = tbl_Filter_TD_8479531_output.getInt32(i, 0);
            SW_JOIN_LEFTSEMI_TD_7493952_payload_rightMajor payloadA{_c_customer_sk3632};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk3650_k = tbl_Filter_TD_8727146_output.getInt32(i, 0);
            auto it = ht1.find(SW_JOIN_LEFTSEMI_TD_7493952_key_rightMajor{_c_customer_sk3650_k});
            if (it != ht1.end()) {
                int32_t _c_customer_sk3650 = tbl_Filter_TD_8727146_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name3658 = tbl_Filter_TD_8727146_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name3659 = tbl_Filter_TD_8727146_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                tbl_JOIN_LEFTSEMI_TD_7493952_output.setInt32(r, 0, _c_customer_sk3650);
                tbl_JOIN_LEFTSEMI_TD_7493952_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name3658);
                tbl_JOIN_LEFTSEMI_TD_7493952_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_last_name3659);
                r++;
            }
        }
        tbl_JOIN_LEFTSEMI_TD_7493952_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTSEMI_TD_7493952_output #Row: " << tbl_JOIN_LEFTSEMI_TD_7493952_output.getNumRow() << std::endl;
}


void SW_Filter_TD_659084(Table &tbl_SerializeFromObject_TD_7703945_input, Table &tbl_Filter_TD_659084_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_year#3720) AND isnotnull(d_moy#3722)) AND ((d_year#3720 = 2000) AND (d_moy#3722 = 2))) AND isnotnull(d_date_sk#3714)))
    // Input: ListBuffer(d_date_sk#3714, d_year#3720, d_moy#3722)
    // Output: ListBuffer(d_date_sk#3714)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7703945_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3720 = tbl_SerializeFromObject_TD_7703945_input.getInt32(i, 1);
        int32_t _d_moy3722 = tbl_SerializeFromObject_TD_7703945_input.getInt32(i, 2);
        int32_t _d_date_sk3714 = tbl_SerializeFromObject_TD_7703945_input.getInt32(i, 0);
        if ((((_d_year3720!= 0) && (_d_moy3722!= 0)) && ((_d_year3720 == 2000) && (_d_moy3722 == 2))) && (_d_date_sk3714!= 0)) {
            int32_t _d_date_sk3714_t = tbl_SerializeFromObject_TD_7703945_input.getInt32(i, 0);
            tbl_Filter_TD_659084_output.setInt32(r, 0, _d_date_sk3714_t);
            r++;
        }
    }
    tbl_Filter_TD_659084_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_659084_output #Row: " << tbl_Filter_TD_659084_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6288197_key_leftMajor {
    int32_t _ws_bill_customer_sk733;
    bool operator==(const SW_JOIN_INNER_TD_6288197_key_leftMajor& other) const {
        return ((_ws_bill_customer_sk733 == other._ws_bill_customer_sk733));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6288197_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6288197_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_bill_customer_sk733));
    }
};
}
struct SW_JOIN_INNER_TD_6288197_payload_leftMajor {
    int32_t _ws_sold_date_sk729;
    int32_t _ws_bill_customer_sk733;
    int32_t _ws_quantity747;
    int64_t _ws_list_price749;
};
struct SW_JOIN_INNER_TD_6288197_key_rightMajor {
    int32_t _c_customer_sk3696;
    bool operator==(const SW_JOIN_INNER_TD_6288197_key_rightMajor& other) const {
        return ((_c_customer_sk3696 == other._c_customer_sk3696));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6288197_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6288197_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk3696));
    }
};
}
struct SW_JOIN_INNER_TD_6288197_payload_rightMajor {
    int32_t _c_customer_sk3696;
    std::string _c_first_name3704;
    std::string _c_last_name3705;
};
void SW_JOIN_INNER_TD_6288197(Table &tbl_JOIN_LEFTSEMI_TD_7552478_output, Table &tbl_JOIN_LEFTSEMI_TD_7221819_output, Table &tbl_JOIN_INNER_TD_6288197_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_bill_customer_sk#733 = c_customer_sk#3696))
    // Left Table: ListBuffer(ws_sold_date_sk#729, ws_bill_customer_sk#733, ws_quantity#747, ws_list_price#749)
    // Right Table: ListBuffer(c_customer_sk#3696, c_first_name#3704, c_last_name#3705)
    // Output Table: ListBuffer(ws_sold_date_sk#729, ws_quantity#747, ws_list_price#749, c_first_name#3704, c_last_name#3705)
    int left_nrow = tbl_JOIN_LEFTSEMI_TD_7552478_output.getNumRow();
    int right_nrow = tbl_JOIN_LEFTSEMI_TD_7221819_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6288197_key_leftMajor, SW_JOIN_INNER_TD_6288197_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_LEFTSEMI_TD_7552478_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_bill_customer_sk733_k = tbl_JOIN_LEFTSEMI_TD_7552478_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_6288197_key_leftMajor keyA{_ws_bill_customer_sk733_k};
            int32_t _ws_sold_date_sk729 = tbl_JOIN_LEFTSEMI_TD_7552478_output.getInt32(i, 0);
            int32_t _ws_bill_customer_sk733 = tbl_JOIN_LEFTSEMI_TD_7552478_output.getInt32(i, 1);
            int32_t _ws_quantity747 = tbl_JOIN_LEFTSEMI_TD_7552478_output.getInt32(i, 2);
            int64_t _ws_list_price749 = tbl_JOIN_LEFTSEMI_TD_7552478_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_6288197_payload_leftMajor payloadA{_ws_sold_date_sk729, _ws_bill_customer_sk733, _ws_quantity747, _ws_list_price749};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_LEFTSEMI_TD_7221819_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk3696_k = tbl_JOIN_LEFTSEMI_TD_7221819_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6288197_key_leftMajor{_c_customer_sk3696_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_date_sk729 = (it->second)._ws_sold_date_sk729;
                int32_t _ws_bill_customer_sk733 = (it->second)._ws_bill_customer_sk733;
                int32_t _ws_quantity747 = (it->second)._ws_quantity747;
                int64_t _ws_list_price749 = (it->second)._ws_list_price749;
                int32_t _c_customer_sk3696 = tbl_JOIN_LEFTSEMI_TD_7221819_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name3704_n = tbl_JOIN_LEFTSEMI_TD_7221819_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_first_name3704 = std::string(_c_first_name3704_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name3705_n = tbl_JOIN_LEFTSEMI_TD_7221819_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_last_name3705 = std::string(_c_last_name3705_n.data());
                tbl_JOIN_INNER_TD_6288197_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_6288197_output.setInt32(r, 1, _ws_quantity747);
                tbl_JOIN_INNER_TD_6288197_output.setInt64(r, 2, _ws_list_price749);
                tbl_JOIN_INNER_TD_6288197_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_first_name3704_n);
                tbl_JOIN_INNER_TD_6288197_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_last_name3705_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6288197_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6288197_key_rightMajor, SW_JOIN_INNER_TD_6288197_payload_rightMajor> ht1;
        int nrow1 = tbl_JOIN_LEFTSEMI_TD_7221819_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk3696_k = tbl_JOIN_LEFTSEMI_TD_7221819_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6288197_key_rightMajor keyA{_c_customer_sk3696_k};
            int32_t _c_customer_sk3696 = tbl_JOIN_LEFTSEMI_TD_7221819_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name3704_n = tbl_JOIN_LEFTSEMI_TD_7221819_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_first_name3704 = std::string(_c_first_name3704_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name3705_n = tbl_JOIN_LEFTSEMI_TD_7221819_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_last_name3705 = std::string(_c_last_name3705_n.data());
            SW_JOIN_INNER_TD_6288197_payload_rightMajor payloadA{_c_customer_sk3696, _c_first_name3704, _c_last_name3705};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_LEFTSEMI_TD_7552478_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_bill_customer_sk733_k = tbl_JOIN_LEFTSEMI_TD_7552478_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6288197_key_rightMajor{_ws_bill_customer_sk733_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk3696 = (it->second)._c_customer_sk3696;
                std::string _c_first_name3704 = (it->second)._c_first_name3704;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name3704_n{};
                memcpy(_c_first_name3704_n.data(), (_c_first_name3704).data(), (_c_first_name3704).length());
                std::string _c_last_name3705 = (it->second)._c_last_name3705;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name3705_n{};
                memcpy(_c_last_name3705_n.data(), (_c_last_name3705).data(), (_c_last_name3705).length());
                int32_t _ws_sold_date_sk729 = tbl_JOIN_LEFTSEMI_TD_7552478_output.getInt32(i, 0);
                int32_t _ws_bill_customer_sk733 = tbl_JOIN_LEFTSEMI_TD_7552478_output.getInt32(i, 1);
                int32_t _ws_quantity747 = tbl_JOIN_LEFTSEMI_TD_7552478_output.getInt32(i, 2);
                int64_t _ws_list_price749 = tbl_JOIN_LEFTSEMI_TD_7552478_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_6288197_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_first_name3704_n);
                tbl_JOIN_INNER_TD_6288197_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_last_name3705_n);
                tbl_JOIN_INNER_TD_6288197_output.setInt32(r, 0, _ws_sold_date_sk729);
                tbl_JOIN_INNER_TD_6288197_output.setInt32(r, 1, _ws_quantity747);
                tbl_JOIN_INNER_TD_6288197_output.setInt64(r, 2, _ws_list_price749);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6288197_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6288197_output #Row: " << tbl_JOIN_INNER_TD_6288197_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6729719(Table &tbl_SerializeFromObject_TD_7253164_input, Table &tbl_Filter_TD_6729719_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_year#3674) AND isnotnull(d_moy#3676)) AND ((d_year#3674 = 2000) AND (d_moy#3676 = 2))) AND isnotnull(d_date_sk#3668)))
    // Input: ListBuffer(d_date_sk#3668, d_year#3674, d_moy#3676)
    // Output: ListBuffer(d_date_sk#3668)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7253164_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3674 = tbl_SerializeFromObject_TD_7253164_input.getInt32(i, 1);
        int32_t _d_moy3676 = tbl_SerializeFromObject_TD_7253164_input.getInt32(i, 2);
        int32_t _d_date_sk3668 = tbl_SerializeFromObject_TD_7253164_input.getInt32(i, 0);
        if ((((_d_year3674!= 0) && (_d_moy3676!= 0)) && ((_d_year3674 == 2000) && (_d_moy3676 == 2))) && (_d_date_sk3668!= 0)) {
            int32_t _d_date_sk3668_t = tbl_SerializeFromObject_TD_7253164_input.getInt32(i, 0);
            tbl_Filter_TD_6729719_output.setInt32(r, 0, _d_date_sk3668_t);
            r++;
        }
    }
    tbl_Filter_TD_6729719_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6729719_output #Row: " << tbl_Filter_TD_6729719_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6832049_key_leftMajor {
    int32_t _cs_bill_customer_sk1107;
    bool operator==(const SW_JOIN_INNER_TD_6832049_key_leftMajor& other) const {
        return ((_cs_bill_customer_sk1107 == other._cs_bill_customer_sk1107));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6832049_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6832049_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_bill_customer_sk1107));
    }
};
}
struct SW_JOIN_INNER_TD_6832049_payload_leftMajor {
    int32_t _cs_sold_date_sk1104;
    int32_t _cs_bill_customer_sk1107;
    int32_t _cs_quantity1122;
    int64_t _cs_list_price1124;
};
struct SW_JOIN_INNER_TD_6832049_key_rightMajor {
    int32_t _c_customer_sk3650;
    bool operator==(const SW_JOIN_INNER_TD_6832049_key_rightMajor& other) const {
        return ((_c_customer_sk3650 == other._c_customer_sk3650));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6832049_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6832049_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk3650));
    }
};
}
struct SW_JOIN_INNER_TD_6832049_payload_rightMajor {
    int32_t _c_customer_sk3650;
    std::string _c_first_name3658;
    std::string _c_last_name3659;
};
void SW_JOIN_INNER_TD_6832049(Table &tbl_JOIN_LEFTSEMI_TD_7619982_output, Table &tbl_JOIN_LEFTSEMI_TD_7493952_output, Table &tbl_JOIN_INNER_TD_6832049_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_bill_customer_sk#1107 = c_customer_sk#3650))
    // Left Table: ListBuffer(cs_sold_date_sk#1104, cs_bill_customer_sk#1107, cs_quantity#1122, cs_list_price#1124)
    // Right Table: ListBuffer(c_customer_sk#3650, c_first_name#3658, c_last_name#3659)
    // Output Table: ListBuffer(cs_sold_date_sk#1104, cs_quantity#1122, cs_list_price#1124, c_first_name#3658, c_last_name#3659)
    int left_nrow = tbl_JOIN_LEFTSEMI_TD_7619982_output.getNumRow();
    int right_nrow = tbl_JOIN_LEFTSEMI_TD_7493952_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6832049_key_leftMajor, SW_JOIN_INNER_TD_6832049_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_LEFTSEMI_TD_7619982_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_bill_customer_sk1107_k = tbl_JOIN_LEFTSEMI_TD_7619982_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_6832049_key_leftMajor keyA{_cs_bill_customer_sk1107_k};
            int32_t _cs_sold_date_sk1104 = tbl_JOIN_LEFTSEMI_TD_7619982_output.getInt32(i, 0);
            int32_t _cs_bill_customer_sk1107 = tbl_JOIN_LEFTSEMI_TD_7619982_output.getInt32(i, 1);
            int32_t _cs_quantity1122 = tbl_JOIN_LEFTSEMI_TD_7619982_output.getInt32(i, 2);
            int64_t _cs_list_price1124 = tbl_JOIN_LEFTSEMI_TD_7619982_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_6832049_payload_leftMajor payloadA{_cs_sold_date_sk1104, _cs_bill_customer_sk1107, _cs_quantity1122, _cs_list_price1124};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_LEFTSEMI_TD_7493952_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk3650_k = tbl_JOIN_LEFTSEMI_TD_7493952_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6832049_key_leftMajor{_c_customer_sk3650_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk1104 = (it->second)._cs_sold_date_sk1104;
                int32_t _cs_bill_customer_sk1107 = (it->second)._cs_bill_customer_sk1107;
                int32_t _cs_quantity1122 = (it->second)._cs_quantity1122;
                int64_t _cs_list_price1124 = (it->second)._cs_list_price1124;
                int32_t _c_customer_sk3650 = tbl_JOIN_LEFTSEMI_TD_7493952_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name3658_n = tbl_JOIN_LEFTSEMI_TD_7493952_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _c_first_name3658 = std::string(_c_first_name3658_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name3659_n = tbl_JOIN_LEFTSEMI_TD_7493952_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _c_last_name3659 = std::string(_c_last_name3659_n.data());
                tbl_JOIN_INNER_TD_6832049_output.setInt32(r, 0, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_6832049_output.setInt32(r, 1, _cs_quantity1122);
                tbl_JOIN_INNER_TD_6832049_output.setInt64(r, 2, _cs_list_price1124);
                tbl_JOIN_INNER_TD_6832049_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_first_name3658_n);
                tbl_JOIN_INNER_TD_6832049_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_last_name3659_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6832049_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6832049_key_rightMajor, SW_JOIN_INNER_TD_6832049_payload_rightMajor> ht1;
        int nrow1 = tbl_JOIN_LEFTSEMI_TD_7493952_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk3650_k = tbl_JOIN_LEFTSEMI_TD_7493952_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6832049_key_rightMajor keyA{_c_customer_sk3650_k};
            int32_t _c_customer_sk3650 = tbl_JOIN_LEFTSEMI_TD_7493952_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name3658_n = tbl_JOIN_LEFTSEMI_TD_7493952_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _c_first_name3658 = std::string(_c_first_name3658_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name3659_n = tbl_JOIN_LEFTSEMI_TD_7493952_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _c_last_name3659 = std::string(_c_last_name3659_n.data());
            SW_JOIN_INNER_TD_6832049_payload_rightMajor payloadA{_c_customer_sk3650, _c_first_name3658, _c_last_name3659};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_LEFTSEMI_TD_7619982_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_bill_customer_sk1107_k = tbl_JOIN_LEFTSEMI_TD_7619982_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6832049_key_rightMajor{_cs_bill_customer_sk1107_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk3650 = (it->second)._c_customer_sk3650;
                std::string _c_first_name3658 = (it->second)._c_first_name3658;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name3658_n{};
                memcpy(_c_first_name3658_n.data(), (_c_first_name3658).data(), (_c_first_name3658).length());
                std::string _c_last_name3659 = (it->second)._c_last_name3659;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name3659_n{};
                memcpy(_c_last_name3659_n.data(), (_c_last_name3659).data(), (_c_last_name3659).length());
                int32_t _cs_sold_date_sk1104 = tbl_JOIN_LEFTSEMI_TD_7619982_output.getInt32(i, 0);
                int32_t _cs_bill_customer_sk1107 = tbl_JOIN_LEFTSEMI_TD_7619982_output.getInt32(i, 1);
                int32_t _cs_quantity1122 = tbl_JOIN_LEFTSEMI_TD_7619982_output.getInt32(i, 2);
                int64_t _cs_list_price1124 = tbl_JOIN_LEFTSEMI_TD_7619982_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_6832049_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_first_name3658_n);
                tbl_JOIN_INNER_TD_6832049_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 4, _c_last_name3659_n);
                tbl_JOIN_INNER_TD_6832049_output.setInt32(r, 0, _cs_sold_date_sk1104);
                tbl_JOIN_INNER_TD_6832049_output.setInt32(r, 1, _cs_quantity1122);
                tbl_JOIN_INNER_TD_6832049_output.setInt64(r, 2, _cs_list_price1124);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6832049_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6832049_output #Row: " << tbl_JOIN_INNER_TD_6832049_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_514082_key_leftMajor {
    int32_t _ws_sold_date_sk729;
    bool operator==(const SW_JOIN_INNER_TD_514082_key_leftMajor& other) const {
        return ((_ws_sold_date_sk729 == other._ws_sold_date_sk729));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_514082_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_514082_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_sold_date_sk729));
    }
};
}
struct SW_JOIN_INNER_TD_514082_payload_leftMajor {
    int32_t _ws_sold_date_sk729;
    int32_t _ws_quantity747;
    int64_t _ws_list_price749;
    std::string _c_first_name3704;
    std::string _c_last_name3705;
};
struct SW_JOIN_INNER_TD_514082_key_rightMajor {
    int32_t _d_date_sk3714;
    bool operator==(const SW_JOIN_INNER_TD_514082_key_rightMajor& other) const {
        return ((_d_date_sk3714 == other._d_date_sk3714));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_514082_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_514082_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk3714));
    }
};
}
struct SW_JOIN_INNER_TD_514082_payload_rightMajor {
    int32_t _d_date_sk3714;
};
void SW_JOIN_INNER_TD_514082(Table &tbl_JOIN_INNER_TD_6288197_output, Table &tbl_Filter_TD_659084_output, Table &tbl_JOIN_INNER_TD_514082_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_sold_date_sk#729 = d_date_sk#3714))
    // Left Table: ListBuffer(ws_sold_date_sk#729, ws_quantity#747, ws_list_price#749, c_first_name#3704, c_last_name#3705)
    // Right Table: ListBuffer(d_date_sk#3714)
    // Output Table: ListBuffer(ws_quantity#747, ws_list_price#749, c_first_name#3704, c_last_name#3705)
    int left_nrow = tbl_JOIN_INNER_TD_6288197_output.getNumRow();
    int right_nrow = tbl_Filter_TD_659084_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_514082_key_leftMajor, SW_JOIN_INNER_TD_514082_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_6288197_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_sold_date_sk729_k = tbl_JOIN_INNER_TD_6288197_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_514082_key_leftMajor keyA{_ws_sold_date_sk729_k};
            int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_6288197_output.getInt32(i, 0);
            int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_6288197_output.getInt32(i, 1);
            int64_t _ws_list_price749 = tbl_JOIN_INNER_TD_6288197_output.getInt64(i, 2);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name3704_n = tbl_JOIN_INNER_TD_6288197_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_first_name3704 = std::string(_c_first_name3704_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name3705_n = tbl_JOIN_INNER_TD_6288197_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_last_name3705 = std::string(_c_last_name3705_n.data());
            SW_JOIN_INNER_TD_514082_payload_leftMajor payloadA{_ws_sold_date_sk729, _ws_quantity747, _ws_list_price749, _c_first_name3704, _c_last_name3705};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_659084_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk3714_k = tbl_Filter_TD_659084_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_514082_key_leftMajor{_d_date_sk3714_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_sold_date_sk729 = (it->second)._ws_sold_date_sk729;
                int32_t _ws_quantity747 = (it->second)._ws_quantity747;
                int64_t _ws_list_price749 = (it->second)._ws_list_price749;
                std::string _c_first_name3704 = (it->second)._c_first_name3704;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name3704_n{};
                memcpy(_c_first_name3704_n.data(), (_c_first_name3704).data(), (_c_first_name3704).length());
                std::string _c_last_name3705 = (it->second)._c_last_name3705;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name3705_n{};
                memcpy(_c_last_name3705_n.data(), (_c_last_name3705).data(), (_c_last_name3705).length());
                int32_t _d_date_sk3714 = tbl_Filter_TD_659084_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_514082_output.setInt32(r, 0, _ws_quantity747);
                tbl_JOIN_INNER_TD_514082_output.setInt64(r, 1, _ws_list_price749);
                tbl_JOIN_INNER_TD_514082_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name3704_n);
                tbl_JOIN_INNER_TD_514082_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name3705_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_514082_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_514082_key_rightMajor, SW_JOIN_INNER_TD_514082_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_659084_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk3714_k = tbl_Filter_TD_659084_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_514082_key_rightMajor keyA{_d_date_sk3714_k};
            int32_t _d_date_sk3714 = tbl_Filter_TD_659084_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_514082_payload_rightMajor payloadA{_d_date_sk3714};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_6288197_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_sold_date_sk729_k = tbl_JOIN_INNER_TD_6288197_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_514082_key_rightMajor{_ws_sold_date_sk729_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk3714 = (it->second)._d_date_sk3714;
                int32_t _ws_sold_date_sk729 = tbl_JOIN_INNER_TD_6288197_output.getInt32(i, 0);
                int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_6288197_output.getInt32(i, 1);
                int64_t _ws_list_price749 = tbl_JOIN_INNER_TD_6288197_output.getInt64(i, 2);
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name3704_n = tbl_JOIN_INNER_TD_6288197_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_first_name3704 = std::string(_c_first_name3704_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name3705_n = tbl_JOIN_INNER_TD_6288197_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_last_name3705 = std::string(_c_last_name3705_n.data());
                tbl_JOIN_INNER_TD_514082_output.setInt32(r, 0, _ws_quantity747);
                tbl_JOIN_INNER_TD_514082_output.setInt64(r, 1, _ws_list_price749);
                tbl_JOIN_INNER_TD_514082_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name3704_n);
                tbl_JOIN_INNER_TD_514082_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name3705_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_514082_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_514082_output #Row: " << tbl_JOIN_INNER_TD_514082_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5393483_key_leftMajor {
    int32_t _cs_sold_date_sk1104;
    bool operator==(const SW_JOIN_INNER_TD_5393483_key_leftMajor& other) const {
        return ((_cs_sold_date_sk1104 == other._cs_sold_date_sk1104));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5393483_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5393483_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._cs_sold_date_sk1104));
    }
};
}
struct SW_JOIN_INNER_TD_5393483_payload_leftMajor {
    int32_t _cs_sold_date_sk1104;
    int32_t _cs_quantity1122;
    int64_t _cs_list_price1124;
    std::string _c_first_name3658;
    std::string _c_last_name3659;
};
struct SW_JOIN_INNER_TD_5393483_key_rightMajor {
    int32_t _d_date_sk3668;
    bool operator==(const SW_JOIN_INNER_TD_5393483_key_rightMajor& other) const {
        return ((_d_date_sk3668 == other._d_date_sk3668));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5393483_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5393483_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk3668));
    }
};
}
struct SW_JOIN_INNER_TD_5393483_payload_rightMajor {
    int32_t _d_date_sk3668;
};
void SW_JOIN_INNER_TD_5393483(Table &tbl_JOIN_INNER_TD_6832049_output, Table &tbl_Filter_TD_6729719_output, Table &tbl_JOIN_INNER_TD_5393483_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((cs_sold_date_sk#1104 = d_date_sk#3668))
    // Left Table: ListBuffer(cs_sold_date_sk#1104, cs_quantity#1122, cs_list_price#1124, c_first_name#3658, c_last_name#3659)
    // Right Table: ListBuffer(d_date_sk#3668)
    // Output Table: ListBuffer(cs_quantity#1122, cs_list_price#1124, c_first_name#3658, c_last_name#3659)
    int left_nrow = tbl_JOIN_INNER_TD_6832049_output.getNumRow();
    int right_nrow = tbl_Filter_TD_6729719_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5393483_key_leftMajor, SW_JOIN_INNER_TD_5393483_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_6832049_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _cs_sold_date_sk1104_k = tbl_JOIN_INNER_TD_6832049_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5393483_key_leftMajor keyA{_cs_sold_date_sk1104_k};
            int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_6832049_output.getInt32(i, 0);
            int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_6832049_output.getInt32(i, 1);
            int64_t _cs_list_price1124 = tbl_JOIN_INNER_TD_6832049_output.getInt64(i, 2);
            std::array<char, TPCDS_READ_MAX + 1> _c_first_name3658_n = tbl_JOIN_INNER_TD_6832049_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _c_first_name3658 = std::string(_c_first_name3658_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _c_last_name3659_n = tbl_JOIN_INNER_TD_6832049_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
            std::string _c_last_name3659 = std::string(_c_last_name3659_n.data());
            SW_JOIN_INNER_TD_5393483_payload_leftMajor payloadA{_cs_sold_date_sk1104, _cs_quantity1122, _cs_list_price1124, _c_first_name3658, _c_last_name3659};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6729719_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk3668_k = tbl_Filter_TD_6729719_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5393483_key_leftMajor{_d_date_sk3668_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _cs_sold_date_sk1104 = (it->second)._cs_sold_date_sk1104;
                int32_t _cs_quantity1122 = (it->second)._cs_quantity1122;
                int64_t _cs_list_price1124 = (it->second)._cs_list_price1124;
                std::string _c_first_name3658 = (it->second)._c_first_name3658;
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name3658_n{};
                memcpy(_c_first_name3658_n.data(), (_c_first_name3658).data(), (_c_first_name3658).length());
                std::string _c_last_name3659 = (it->second)._c_last_name3659;
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name3659_n{};
                memcpy(_c_last_name3659_n.data(), (_c_last_name3659).data(), (_c_last_name3659).length());
                int32_t _d_date_sk3668 = tbl_Filter_TD_6729719_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_5393483_output.setInt32(r, 0, _cs_quantity1122);
                tbl_JOIN_INNER_TD_5393483_output.setInt64(r, 1, _cs_list_price1124);
                tbl_JOIN_INNER_TD_5393483_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name3658_n);
                tbl_JOIN_INNER_TD_5393483_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name3659_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5393483_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5393483_key_rightMajor, SW_JOIN_INNER_TD_5393483_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_6729719_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk3668_k = tbl_Filter_TD_6729719_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5393483_key_rightMajor keyA{_d_date_sk3668_k};
            int32_t _d_date_sk3668 = tbl_Filter_TD_6729719_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5393483_payload_rightMajor payloadA{_d_date_sk3668};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_6832049_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _cs_sold_date_sk1104_k = tbl_JOIN_INNER_TD_6832049_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5393483_key_rightMajor{_cs_sold_date_sk1104_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk3668 = (it->second)._d_date_sk3668;
                int32_t _cs_sold_date_sk1104 = tbl_JOIN_INNER_TD_6832049_output.getInt32(i, 0);
                int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_6832049_output.getInt32(i, 1);
                int64_t _cs_list_price1124 = tbl_JOIN_INNER_TD_6832049_output.getInt64(i, 2);
                std::array<char, TPCDS_READ_MAX + 1> _c_first_name3658_n = tbl_JOIN_INNER_TD_6832049_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _c_first_name3658 = std::string(_c_first_name3658_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _c_last_name3659_n = tbl_JOIN_INNER_TD_6832049_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
                std::string _c_last_name3659 = std::string(_c_last_name3659_n.data());
                tbl_JOIN_INNER_TD_5393483_output.setInt32(r, 0, _cs_quantity1122);
                tbl_JOIN_INNER_TD_5393483_output.setInt64(r, 1, _cs_list_price1124);
                tbl_JOIN_INNER_TD_5393483_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _c_first_name3658_n);
                tbl_JOIN_INNER_TD_5393483_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _c_last_name3659_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5393483_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5393483_output #Row: " << tbl_JOIN_INNER_TD_5393483_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_4296780_key {
    std::string _c_last_name3705;
    std::string _c_first_name3704;
    bool operator==(const SW_Aggregate_TD_4296780_key& other) const { return (_c_last_name3705 == other._c_last_name3705) && (_c_first_name3704 == other._c_first_name3704); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_4296780_key> {
    std::size_t operator() (const SW_Aggregate_TD_4296780_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._c_last_name3705)) + (hash<string>()(k._c_first_name3704));
    }
};
}
struct SW_Aggregate_TD_4296780_payload {
    int64_t _sales3547_sum_0;
};
void SW_Aggregate_TD_4296780(Table &tbl_JOIN_INNER_TD_514082_output, Table &tbl_Aggregate_TD_4296780_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_last_name#3705, c_first_name#3704, sum(CheckOverflow((promote_precision(cast(cast(ws_quantity#747 as decimal(10,0)) as decimal(12,2))) * promote_precision(cast(ws_list_price#749 as decimal(12,2)))), DecimalType(18,2), true)) AS sales#3547)
    // Input: ListBuffer(ws_quantity#747, ws_list_price#749, c_first_name#3704, c_last_name#3705)
    // Output: ListBuffer(c_last_name#3705, c_first_name#3704, sales#3547)
    std::unordered_map<SW_Aggregate_TD_4296780_key, SW_Aggregate_TD_4296780_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_514082_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_quantity747 = tbl_JOIN_INNER_TD_514082_output.getInt32(i, 0);
        int64_t _ws_list_price749 = tbl_JOIN_INNER_TD_514082_output.getInt64(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name3704 = tbl_JOIN_INNER_TD_514082_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name3705 = tbl_JOIN_INNER_TD_514082_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        SW_Aggregate_TD_4296780_key k{std::string(_c_last_name3705.data()), std::string(_c_first_name3704.data())};
        int64_t _sales3547_sum_0 = (_ws_quantity747 * _ws_list_price749);
        SW_Aggregate_TD_4296780_payload p{_sales3547_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._sales3547_sum_0 + _sales3547_sum_0;
            p._sales3547_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name3705{};
        memcpy(_c_last_name3705.data(), ((it.first)._c_last_name3705).data(), ((it.first)._c_last_name3705).length());
        tbl_Aggregate_TD_4296780_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name3705);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name3704{};
        memcpy(_c_first_name3704.data(), ((it.first)._c_first_name3704).data(), ((it.first)._c_first_name3704).length());
        tbl_Aggregate_TD_4296780_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name3704);
        int64_t _sales3547 = (it.second)._sales3547_sum_0;
        tbl_Aggregate_TD_4296780_output.setInt64(r, 2, _sales3547);
        ++r;
    }
    tbl_Aggregate_TD_4296780_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_4296780_output #Row: " << tbl_Aggregate_TD_4296780_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_4622735_key {
    std::string _c_last_name3659;
    std::string _c_first_name3658;
    bool operator==(const SW_Aggregate_TD_4622735_key& other) const { return (_c_last_name3659 == other._c_last_name3659) && (_c_first_name3658 == other._c_first_name3658); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_4622735_key> {
    std::size_t operator() (const SW_Aggregate_TD_4622735_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._c_last_name3659)) + (hash<string>()(k._c_first_name3658));
    }
};
}
struct SW_Aggregate_TD_4622735_payload {
    int64_t _sales3544_sum_0;
};
void SW_Aggregate_TD_4622735(Table &tbl_JOIN_INNER_TD_5393483_output, Table &tbl_Aggregate_TD_4622735_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(c_last_name#3659, c_first_name#3658, sum(CheckOverflow((promote_precision(cast(cast(cs_quantity#1122 as decimal(10,0)) as decimal(12,2))) * promote_precision(cast(cs_list_price#1124 as decimal(12,2)))), DecimalType(18,2), true)) AS sales#3544)
    // Input: ListBuffer(cs_quantity#1122, cs_list_price#1124, c_first_name#3658, c_last_name#3659)
    // Output: ListBuffer(c_last_name#3659, c_first_name#3658, sales#3544)
    std::unordered_map<SW_Aggregate_TD_4622735_key, SW_Aggregate_TD_4622735_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_5393483_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_quantity1122 = tbl_JOIN_INNER_TD_5393483_output.getInt32(i, 0);
        int64_t _cs_list_price1124 = tbl_JOIN_INNER_TD_5393483_output.getInt64(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name3658 = tbl_JOIN_INNER_TD_5393483_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name3659 = tbl_JOIN_INNER_TD_5393483_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        SW_Aggregate_TD_4622735_key k{std::string(_c_last_name3659.data()), std::string(_c_first_name3658.data())};
        int64_t _sales3544_sum_0 = (_cs_quantity1122 * _cs_list_price1124);
        SW_Aggregate_TD_4622735_payload p{_sales3544_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._sales3544_sum_0 + _sales3544_sum_0;
            p._sales3544_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name3659{};
        memcpy(_c_last_name3659.data(), ((it.first)._c_last_name3659).data(), ((it.first)._c_last_name3659).length());
        tbl_Aggregate_TD_4622735_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name3659);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name3658{};
        memcpy(_c_first_name3658.data(), ((it.first)._c_first_name3658).data(), ((it.first)._c_first_name3658).length());
        tbl_Aggregate_TD_4622735_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name3658);
        int64_t _sales3544 = (it.second)._sales3544_sum_0;
        tbl_Aggregate_TD_4622735_output.setInt64(r, 2, _sales3544);
        ++r;
    }
    tbl_Aggregate_TD_4622735_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_4622735_output #Row: " << tbl_Aggregate_TD_4622735_output.getNumRow() << std::endl;
}

void SW_Union_TD_3362723(Table &tbl_Aggregate_TD_4622735_output, Table &tbl_Aggregate_TD_4296780_output, Table &tbl_Union_TD_3362723_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Union
    // Operation: ListBuffer(List(UNION))
    // Output Table: ListBuffer(c_last_name#3659, c_first_name#3658, sales#3544)
    int r = 0;
    int row0 = tbl_Aggregate_TD_4622735_output.getNumRow();
    for (int i = 0; i < row0; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name3659_n = tbl_Union_TD_3362723_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_Union_TD_3362723_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name3659_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name3658_n = tbl_Union_TD_3362723_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_Union_TD_3362723_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name3658_n);
        tbl_Union_TD_3362723_output.setInt32(r, 2, tbl_Aggregate_TD_4622735_output.getInt64(i, 2));
        ++r;
    }
    int row1 = tbl_Aggregate_TD_4296780_output.getNumRow();
    for (int i = 0; i < row1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name3705_n = tbl_Union_TD_3362723_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_Union_TD_3362723_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name3705_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name3704_n = tbl_Union_TD_3362723_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_Union_TD_3362723_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name3704_n);
        tbl_Union_TD_3362723_output.setInt32(r, 2, tbl_Aggregate_TD_4296780_output.getInt64(i, 2));
        ++r;
    }
    tbl_Union_TD_3362723_output.setNumRow(r);
    std::cout << "tbl_Union_TD_3362723_output #Row: " << tbl_Union_TD_3362723_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2281265(Table &tbl_Union_TD_3362723_output, Table &tbl_Sort_TD_2281265_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(c_last_name#3659 ASC NULLS FIRST, c_first_name#3658 ASC NULLS FIRST, sales#3544 ASC NULLS FIRST)
    // Input: ListBuffer(c_last_name#3659, c_first_name#3658, sales#3544)
    // Output: ListBuffer(c_last_name#3659, c_first_name#3658, sales#3544)
    struct SW_Sort_TD_2281265Row {
        std::string _c_last_name3659;
        std::string _c_first_name3658;
        int64_t _sales3544;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2281265Row& a, const SW_Sort_TD_2281265Row& b) const { return 
 (a._c_last_name3659 < b._c_last_name3659) || 
 ((a._c_last_name3659 == b._c_last_name3659) && (a._c_first_name3658 < b._c_first_name3658)) || 
 ((a._c_last_name3659 == b._c_last_name3659) && (a._c_first_name3658 == b._c_first_name3658) && (a._sales3544 < b._sales3544)); 
}
    }SW_Sort_TD_2281265_order; 

    int nrow1 = tbl_Union_TD_3362723_output.getNumRow();
    std::vector<SW_Sort_TD_2281265Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name3659 = tbl_Union_TD_3362723_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name3658 = tbl_Union_TD_3362723_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        int64_t _sales3544 = tbl_Union_TD_3362723_output.getInt64(i, 2);
        SW_Sort_TD_2281265Row t = {std::string(_c_last_name3659.data()),std::string(_c_first_name3658.data()),_sales3544};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2281265_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name3659{};
        memcpy(_c_last_name3659.data(), (it._c_last_name3659).data(), (it._c_last_name3659).length());
        tbl_Sort_TD_2281265_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _c_last_name3659);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name3658{};
        memcpy(_c_first_name3658.data(), (it._c_first_name3658).data(), (it._c_first_name3658).length());
        tbl_Sort_TD_2281265_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _c_first_name3658);
        tbl_Sort_TD_2281265_output.setInt64(r, 2, it._sales3544);
        ++r;
    }
    tbl_Sort_TD_2281265_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2281265_output #Row: " << tbl_Sort_TD_2281265_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1536848(Table &tbl_Sort_TD_2281265_output, Table &tbl_LocalLimit_TD_1536848_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(c_last_name#3659, c_first_name#3658, sales#3544)
    // Output: ListBuffer(c_last_name#3659, c_first_name#3658, sales#3544)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name3659_n = tbl_Sort_TD_2281265_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1536848_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name3659_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name3658_n = tbl_Sort_TD_2281265_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_1536848_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name3658_n);
        tbl_LocalLimit_TD_1536848_output.setInt64(r, 2, tbl_Sort_TD_2281265_output.getInt64(i, 2));
        r++;
    }
    tbl_LocalLimit_TD_1536848_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1536848_output #Row: " << tbl_LocalLimit_TD_1536848_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0220815(Table &tbl_LocalLimit_TD_1536848_output, Table &tbl_GlobalLimit_TD_0220815_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(c_last_name#3659, c_first_name#3658, sales#3544)
    // Output: ListBuffer(c_last_name#3659, c_first_name#3658, sales#3544)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _c_last_name3659_n = tbl_LocalLimit_TD_1536848_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0220815_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _c_last_name3659_n);
        std::array<char, TPCDS_READ_MAX + 1> _c_first_name3658_n = tbl_LocalLimit_TD_1536848_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_0220815_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _c_first_name3658_n);
        tbl_GlobalLimit_TD_0220815_output.setInt64(r, 2, tbl_LocalLimit_TD_1536848_output.getInt64(i, 2));
        r++;
    }
    tbl_GlobalLimit_TD_0220815_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0220815_output #Row: " << tbl_GlobalLimit_TD_0220815_output.getNumRow() << std::endl;
}

