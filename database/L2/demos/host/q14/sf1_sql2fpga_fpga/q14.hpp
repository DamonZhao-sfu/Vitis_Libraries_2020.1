#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_23349407(Table &tbl_SerializeFromObject_TD_24971676_input, Table &tbl_Filter_TD_23349407_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#3592))
    // Input: ListBuffer(i_item_sk#3592, i_brand_id#3599, i_class_id#3601, i_category_id#3603)
    // Output: ListBuffer(i_item_sk#3592, i_brand_id#3599, i_class_id#3601, i_category_id#3603)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_24971676_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk3592 = tbl_SerializeFromObject_TD_24971676_input.getInt32(i, 0);
        if (_i_item_sk3592!= 0) {
            int32_t _i_item_sk3592_t = tbl_SerializeFromObject_TD_24971676_input.getInt32(i, 0);
            tbl_Filter_TD_23349407_output.setInt32(r, 0, _i_item_sk3592_t);
            int32_t _i_brand_id3599_t = tbl_SerializeFromObject_TD_24971676_input.getInt32(i, 1);
            tbl_Filter_TD_23349407_output.setInt32(r, 1, _i_brand_id3599_t);
            int32_t _i_class_id3601_t = tbl_SerializeFromObject_TD_24971676_input.getInt32(i, 2);
            tbl_Filter_TD_23349407_output.setInt32(r, 2, _i_class_id3601_t);
            int32_t _i_category_id3603_t = tbl_SerializeFromObject_TD_24971676_input.getInt32(i, 3);
            tbl_Filter_TD_23349407_output.setInt32(r, 3, _i_category_id3603_t);
            r++;
        }
    }
    tbl_Filter_TD_23349407_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_23349407_output #Row: " << tbl_Filter_TD_23349407_output.getNumRow() << std::endl;
}

void SW_Filter_TD_23442461(Table &tbl_SerializeFromObject_TD_24812778_input, Table &tbl_Filter_TD_23442461_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cs_item_sk#1119) AND isnotnull(cs_sold_date_sk#1104)))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_24812778_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_item_sk1119 = tbl_SerializeFromObject_TD_24812778_input.getInt32(i, 1);
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_24812778_input.getInt32(i, 0);
        if ((_cs_item_sk1119!= 0) && (_cs_sold_date_sk1104!= 0)) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_24812778_input.getInt32(i, 0);
            tbl_Filter_TD_23442461_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int32_t _cs_item_sk1119_t = tbl_SerializeFromObject_TD_24812778_input.getInt32(i, 1);
            tbl_Filter_TD_23442461_output.setInt32(r, 1, _cs_item_sk1119_t);
            r++;
        }
    }
    tbl_Filter_TD_23442461_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_23442461_output #Row: " << tbl_Filter_TD_23442461_output.getNumRow() << std::endl;
}

void SW_Filter_TD_23105158(Table &tbl_SerializeFromObject_TD_24284321_input, Table &tbl_Filter_TD_23105158_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#3592))
    // Input: ListBuffer(i_item_sk#3592, i_brand_id#3599, i_class_id#3601, i_category_id#3603)
    // Output: ListBuffer(i_item_sk#3592, i_brand_id#3599, i_class_id#3601, i_category_id#3603)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_24284321_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk3592 = tbl_SerializeFromObject_TD_24284321_input.getInt32(i, 0);
        if (_i_item_sk3592!= 0) {
            int32_t _i_item_sk3592_t = tbl_SerializeFromObject_TD_24284321_input.getInt32(i, 0);
            tbl_Filter_TD_23105158_output.setInt32(r, 0, _i_item_sk3592_t);
            int32_t _i_brand_id3599_t = tbl_SerializeFromObject_TD_24284321_input.getInt32(i, 1);
            tbl_Filter_TD_23105158_output.setInt32(r, 1, _i_brand_id3599_t);
            int32_t _i_class_id3601_t = tbl_SerializeFromObject_TD_24284321_input.getInt32(i, 2);
            tbl_Filter_TD_23105158_output.setInt32(r, 2, _i_class_id3601_t);
            int32_t _i_category_id3603_t = tbl_SerializeFromObject_TD_24284321_input.getInt32(i, 3);
            tbl_Filter_TD_23105158_output.setInt32(r, 3, _i_category_id3603_t);
            r++;
        }
    }
    tbl_Filter_TD_23105158_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_23105158_output #Row: " << tbl_Filter_TD_23105158_output.getNumRow() << std::endl;
}

void SW_Filter_TD_23333336(Table &tbl_SerializeFromObject_TD_24734524_input, Table &tbl_Filter_TD_23333336_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cs_item_sk#1119) AND isnotnull(cs_sold_date_sk#1104)))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_24734524_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_item_sk1119 = tbl_SerializeFromObject_TD_24734524_input.getInt32(i, 1);
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_24734524_input.getInt32(i, 0);
        if ((_cs_item_sk1119!= 0) && (_cs_sold_date_sk1104!= 0)) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_24734524_input.getInt32(i, 0);
            tbl_Filter_TD_23333336_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int32_t _cs_item_sk1119_t = tbl_SerializeFromObject_TD_24734524_input.getInt32(i, 1);
            tbl_Filter_TD_23333336_output.setInt32(r, 1, _cs_item_sk1119_t);
            r++;
        }
    }
    tbl_Filter_TD_23333336_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_23333336_output #Row: " << tbl_Filter_TD_23333336_output.getNumRow() << std::endl;
}

void SW_Filter_TD_23838234(Table &tbl_SerializeFromObject_TD_24309543_input, Table &tbl_Filter_TD_23838234_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#3592))
    // Input: ListBuffer(i_item_sk#3592, i_brand_id#3599, i_class_id#3601, i_category_id#3603)
    // Output: ListBuffer(i_item_sk#3592, i_brand_id#3599, i_class_id#3601, i_category_id#3603)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_24309543_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk3592 = tbl_SerializeFromObject_TD_24309543_input.getInt32(i, 0);
        if (_i_item_sk3592!= 0) {
            int32_t _i_item_sk3592_t = tbl_SerializeFromObject_TD_24309543_input.getInt32(i, 0);
            tbl_Filter_TD_23838234_output.setInt32(r, 0, _i_item_sk3592_t);
            int32_t _i_brand_id3599_t = tbl_SerializeFromObject_TD_24309543_input.getInt32(i, 1);
            tbl_Filter_TD_23838234_output.setInt32(r, 1, _i_brand_id3599_t);
            int32_t _i_class_id3601_t = tbl_SerializeFromObject_TD_24309543_input.getInt32(i, 2);
            tbl_Filter_TD_23838234_output.setInt32(r, 2, _i_class_id3601_t);
            int32_t _i_category_id3603_t = tbl_SerializeFromObject_TD_24309543_input.getInt32(i, 3);
            tbl_Filter_TD_23838234_output.setInt32(r, 3, _i_category_id3603_t);
            r++;
        }
    }
    tbl_Filter_TD_23838234_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_23838234_output #Row: " << tbl_Filter_TD_23838234_output.getNumRow() << std::endl;
}

void SW_Filter_TD_23479638(Table &tbl_SerializeFromObject_TD_24307570_input, Table &tbl_Filter_TD_23479638_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cs_item_sk#1119) AND isnotnull(cs_sold_date_sk#1104)))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_24307570_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_item_sk1119 = tbl_SerializeFromObject_TD_24307570_input.getInt32(i, 1);
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_24307570_input.getInt32(i, 0);
        if ((_cs_item_sk1119!= 0) && (_cs_sold_date_sk1104!= 0)) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_24307570_input.getInt32(i, 0);
            tbl_Filter_TD_23479638_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int32_t _cs_item_sk1119_t = tbl_SerializeFromObject_TD_24307570_input.getInt32(i, 1);
            tbl_Filter_TD_23479638_output.setInt32(r, 1, _cs_item_sk1119_t);
            r++;
        }
    }
    tbl_Filter_TD_23479638_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_23479638_output #Row: " << tbl_Filter_TD_23479638_output.getNumRow() << std::endl;
}

void SW_Filter_TD_23868792(Table &tbl_SerializeFromObject_TD_24920896_input, Table &tbl_Filter_TD_23868792_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#3592))
    // Input: ListBuffer(i_item_sk#3592, i_brand_id#3599, i_class_id#3601, i_category_id#3603)
    // Output: ListBuffer(i_item_sk#3592, i_brand_id#3599, i_class_id#3601, i_category_id#3603)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_24920896_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk3592 = tbl_SerializeFromObject_TD_24920896_input.getInt32(i, 0);
        if (_i_item_sk3592!= 0) {
            int32_t _i_item_sk3592_t = tbl_SerializeFromObject_TD_24920896_input.getInt32(i, 0);
            tbl_Filter_TD_23868792_output.setInt32(r, 0, _i_item_sk3592_t);
            int32_t _i_brand_id3599_t = tbl_SerializeFromObject_TD_24920896_input.getInt32(i, 1);
            tbl_Filter_TD_23868792_output.setInt32(r, 1, _i_brand_id3599_t);
            int32_t _i_class_id3601_t = tbl_SerializeFromObject_TD_24920896_input.getInt32(i, 2);
            tbl_Filter_TD_23868792_output.setInt32(r, 2, _i_class_id3601_t);
            int32_t _i_category_id3603_t = tbl_SerializeFromObject_TD_24920896_input.getInt32(i, 3);
            tbl_Filter_TD_23868792_output.setInt32(r, 3, _i_category_id3603_t);
            r++;
        }
    }
    tbl_Filter_TD_23868792_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_23868792_output #Row: " << tbl_Filter_TD_23868792_output.getNumRow() << std::endl;
}

void SW_Filter_TD_23317888(Table &tbl_SerializeFromObject_TD_2482288_input, Table &tbl_Filter_TD_23317888_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cs_item_sk#1119) AND isnotnull(cs_sold_date_sk#1104)))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_2482288_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_item_sk1119 = tbl_SerializeFromObject_TD_2482288_input.getInt32(i, 1);
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_2482288_input.getInt32(i, 0);
        if ((_cs_item_sk1119!= 0) && (_cs_sold_date_sk1104!= 0)) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_2482288_input.getInt32(i, 0);
            tbl_Filter_TD_23317888_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int32_t _cs_item_sk1119_t = tbl_SerializeFromObject_TD_2482288_input.getInt32(i, 1);
            tbl_Filter_TD_23317888_output.setInt32(r, 1, _cs_item_sk1119_t);
            r++;
        }
    }
    tbl_Filter_TD_23317888_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_23317888_output #Row: " << tbl_Filter_TD_23317888_output.getNumRow() << std::endl;
}

void SW_Filter_TD_23862712(Table &tbl_SerializeFromObject_TD_24871770_input, Table &tbl_Filter_TD_23862712_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#3592))
    // Input: ListBuffer(i_item_sk#3592, i_brand_id#3599, i_class_id#3601, i_category_id#3603)
    // Output: ListBuffer(i_item_sk#3592, i_brand_id#3599, i_class_id#3601, i_category_id#3603)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_24871770_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk3592 = tbl_SerializeFromObject_TD_24871770_input.getInt32(i, 0);
        if (_i_item_sk3592!= 0) {
            int32_t _i_item_sk3592_t = tbl_SerializeFromObject_TD_24871770_input.getInt32(i, 0);
            tbl_Filter_TD_23862712_output.setInt32(r, 0, _i_item_sk3592_t);
            int32_t _i_brand_id3599_t = tbl_SerializeFromObject_TD_24871770_input.getInt32(i, 1);
            tbl_Filter_TD_23862712_output.setInt32(r, 1, _i_brand_id3599_t);
            int32_t _i_class_id3601_t = tbl_SerializeFromObject_TD_24871770_input.getInt32(i, 2);
            tbl_Filter_TD_23862712_output.setInt32(r, 2, _i_class_id3601_t);
            int32_t _i_category_id3603_t = tbl_SerializeFromObject_TD_24871770_input.getInt32(i, 3);
            tbl_Filter_TD_23862712_output.setInt32(r, 3, _i_category_id3603_t);
            r++;
        }
    }
    tbl_Filter_TD_23862712_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_23862712_output #Row: " << tbl_Filter_TD_23862712_output.getNumRow() << std::endl;
}

void SW_Filter_TD_23696158(Table &tbl_SerializeFromObject_TD_247778_input, Table &tbl_Filter_TD_23696158_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cs_item_sk#1119) AND isnotnull(cs_sold_date_sk#1104)))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_247778_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_item_sk1119 = tbl_SerializeFromObject_TD_247778_input.getInt32(i, 1);
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_247778_input.getInt32(i, 0);
        if ((_cs_item_sk1119!= 0) && (_cs_sold_date_sk1104!= 0)) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_247778_input.getInt32(i, 0);
            tbl_Filter_TD_23696158_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int32_t _cs_item_sk1119_t = tbl_SerializeFromObject_TD_247778_input.getInt32(i, 1);
            tbl_Filter_TD_23696158_output.setInt32(r, 1, _cs_item_sk1119_t);
            r++;
        }
    }
    tbl_Filter_TD_23696158_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_23696158_output #Row: " << tbl_Filter_TD_23696158_output.getNumRow() << std::endl;
}

void SW_Filter_TD_23842051(Table &tbl_SerializeFromObject_TD_24767316_input, Table &tbl_Filter_TD_23842051_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#3592))
    // Input: ListBuffer(i_item_sk#3592, i_brand_id#3599, i_class_id#3601, i_category_id#3603)
    // Output: ListBuffer(i_item_sk#3592, i_brand_id#3599, i_class_id#3601, i_category_id#3603)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_24767316_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk3592 = tbl_SerializeFromObject_TD_24767316_input.getInt32(i, 0);
        if (_i_item_sk3592!= 0) {
            int32_t _i_item_sk3592_t = tbl_SerializeFromObject_TD_24767316_input.getInt32(i, 0);
            tbl_Filter_TD_23842051_output.setInt32(r, 0, _i_item_sk3592_t);
            int32_t _i_brand_id3599_t = tbl_SerializeFromObject_TD_24767316_input.getInt32(i, 1);
            tbl_Filter_TD_23842051_output.setInt32(r, 1, _i_brand_id3599_t);
            int32_t _i_class_id3601_t = tbl_SerializeFromObject_TD_24767316_input.getInt32(i, 2);
            tbl_Filter_TD_23842051_output.setInt32(r, 2, _i_class_id3601_t);
            int32_t _i_category_id3603_t = tbl_SerializeFromObject_TD_24767316_input.getInt32(i, 3);
            tbl_Filter_TD_23842051_output.setInt32(r, 3, _i_category_id3603_t);
            r++;
        }
    }
    tbl_Filter_TD_23842051_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_23842051_output #Row: " << tbl_Filter_TD_23842051_output.getNumRow() << std::endl;
}

void SW_Filter_TD_23888245(Table &tbl_SerializeFromObject_TD_24342171_input, Table &tbl_Filter_TD_23888245_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cs_item_sk#1119) AND isnotnull(cs_sold_date_sk#1104)))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_item_sk#1119)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_24342171_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_item_sk1119 = tbl_SerializeFromObject_TD_24342171_input.getInt32(i, 1);
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_24342171_input.getInt32(i, 0);
        if ((_cs_item_sk1119!= 0) && (_cs_sold_date_sk1104!= 0)) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_24342171_input.getInt32(i, 0);
            tbl_Filter_TD_23888245_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int32_t _cs_item_sk1119_t = tbl_SerializeFromObject_TD_24342171_input.getInt32(i, 1);
            tbl_Filter_TD_23888245_output.setInt32(r, 1, _cs_item_sk1119_t);
            r++;
        }
    }
    tbl_Filter_TD_23888245_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_23888245_output #Row: " << tbl_Filter_TD_23888245_output.getNumRow() << std::endl;
}

void SW_Filter_TD_22982273(Table &tbl_SerializeFromObject_TD_23579867_input, Table &tbl_Filter_TD_22982273_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3620) AND ((d_year#3620 >= 1999) AND (d_year#3620 <= 2001))) AND isnotnull(d_date_sk#3614)))
    // Input: ListBuffer(d_date_sk#3614, d_year#3620)
    // Output: ListBuffer(d_date_sk#3614)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_23579867_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3620 = tbl_SerializeFromObject_TD_23579867_input.getInt32(i, 1);
        int32_t _d_date_sk3614 = tbl_SerializeFromObject_TD_23579867_input.getInt32(i, 0);
        if (((_d_year3620!= 0) && ((_d_year3620 >= 1999) && (_d_year3620 <= 2001))) && (_d_date_sk3614!= 0)) {
            int32_t _d_date_sk3614_t = tbl_SerializeFromObject_TD_23579867_input.getInt32(i, 0);
            tbl_Filter_TD_22982273_output.setInt32(r, 0, _d_date_sk3614_t);
            r++;
        }
    }
    tbl_Filter_TD_22982273_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_22982273_output #Row: " << tbl_Filter_TD_22982273_output.getNumRow() << std::endl;
}


void SW_Filter_TD_22544734(Table &tbl_SerializeFromObject_TD_23752200_input, Table &tbl_Filter_TD_22544734_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3620) AND ((d_year#3620 >= 1999) AND (d_year#3620 <= 2001))) AND isnotnull(d_date_sk#3614)))
    // Input: ListBuffer(d_date_sk#3614, d_year#3620)
    // Output: ListBuffer(d_date_sk#3614)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_23752200_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3620 = tbl_SerializeFromObject_TD_23752200_input.getInt32(i, 1);
        int32_t _d_date_sk3614 = tbl_SerializeFromObject_TD_23752200_input.getInt32(i, 0);
        if (((_d_year3620!= 0) && ((_d_year3620 >= 1999) && (_d_year3620 <= 2001))) && (_d_date_sk3614!= 0)) {
            int32_t _d_date_sk3614_t = tbl_SerializeFromObject_TD_23752200_input.getInt32(i, 0);
            tbl_Filter_TD_22544734_output.setInt32(r, 0, _d_date_sk3614_t);
            r++;
        }
    }
    tbl_Filter_TD_22544734_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_22544734_output #Row: " << tbl_Filter_TD_22544734_output.getNumRow() << std::endl;
}


void SW_Filter_TD_22492360(Table &tbl_SerializeFromObject_TD_2370374_input, Table &tbl_Filter_TD_22492360_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3620) AND ((d_year#3620 >= 1999) AND (d_year#3620 <= 2001))) AND isnotnull(d_date_sk#3614)))
    // Input: ListBuffer(d_date_sk#3614, d_year#3620)
    // Output: ListBuffer(d_date_sk#3614)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_2370374_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3620 = tbl_SerializeFromObject_TD_2370374_input.getInt32(i, 1);
        int32_t _d_date_sk3614 = tbl_SerializeFromObject_TD_2370374_input.getInt32(i, 0);
        if (((_d_year3620!= 0) && ((_d_year3620 >= 1999) && (_d_year3620 <= 2001))) && (_d_date_sk3614!= 0)) {
            int32_t _d_date_sk3614_t = tbl_SerializeFromObject_TD_2370374_input.getInt32(i, 0);
            tbl_Filter_TD_22492360_output.setInt32(r, 0, _d_date_sk3614_t);
            r++;
        }
    }
    tbl_Filter_TD_22492360_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_22492360_output #Row: " << tbl_Filter_TD_22492360_output.getNumRow() << std::endl;
}


void SW_Filter_TD_22136789(Table &tbl_SerializeFromObject_TD_23377033_input, Table &tbl_Filter_TD_22136789_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3620) AND ((d_year#3620 >= 1999) AND (d_year#3620 <= 2001))) AND isnotnull(d_date_sk#3614)))
    // Input: ListBuffer(d_date_sk#3614, d_year#3620)
    // Output: ListBuffer(d_date_sk#3614)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_23377033_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3620 = tbl_SerializeFromObject_TD_23377033_input.getInt32(i, 1);
        int32_t _d_date_sk3614 = tbl_SerializeFromObject_TD_23377033_input.getInt32(i, 0);
        if (((_d_year3620!= 0) && ((_d_year3620 >= 1999) && (_d_year3620 <= 2001))) && (_d_date_sk3614!= 0)) {
            int32_t _d_date_sk3614_t = tbl_SerializeFromObject_TD_23377033_input.getInt32(i, 0);
            tbl_Filter_TD_22136789_output.setInt32(r, 0, _d_date_sk3614_t);
            r++;
        }
    }
    tbl_Filter_TD_22136789_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_22136789_output #Row: " << tbl_Filter_TD_22136789_output.getNumRow() << std::endl;
}


void SW_Filter_TD_22375974(Table &tbl_SerializeFromObject_TD_2354405_input, Table &tbl_Filter_TD_22375974_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3620) AND ((d_year#3620 >= 1999) AND (d_year#3620 <= 2001))) AND isnotnull(d_date_sk#3614)))
    // Input: ListBuffer(d_date_sk#3614, d_year#3620)
    // Output: ListBuffer(d_date_sk#3614)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_2354405_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3620 = tbl_SerializeFromObject_TD_2354405_input.getInt32(i, 1);
        int32_t _d_date_sk3614 = tbl_SerializeFromObject_TD_2354405_input.getInt32(i, 0);
        if (((_d_year3620!= 0) && ((_d_year3620 >= 1999) && (_d_year3620 <= 2001))) && (_d_date_sk3614!= 0)) {
            int32_t _d_date_sk3614_t = tbl_SerializeFromObject_TD_2354405_input.getInt32(i, 0);
            tbl_Filter_TD_22375974_output.setInt32(r, 0, _d_date_sk3614_t);
            r++;
        }
    }
    tbl_Filter_TD_22375974_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_22375974_output #Row: " << tbl_Filter_TD_22375974_output.getNumRow() << std::endl;
}


void SW_Filter_TD_22325271(Table &tbl_SerializeFromObject_TD_23588620_input, Table &tbl_Filter_TD_22325271_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3620) AND ((d_year#3620 >= 1999) AND (d_year#3620 <= 2001))) AND isnotnull(d_date_sk#3614)))
    // Input: ListBuffer(d_date_sk#3614, d_year#3620)
    // Output: ListBuffer(d_date_sk#3614)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_23588620_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3620 = tbl_SerializeFromObject_TD_23588620_input.getInt32(i, 1);
        int32_t _d_date_sk3614 = tbl_SerializeFromObject_TD_23588620_input.getInt32(i, 0);
        if (((_d_year3620!= 0) && ((_d_year3620 >= 1999) && (_d_year3620 <= 2001))) && (_d_date_sk3614!= 0)) {
            int32_t _d_date_sk3614_t = tbl_SerializeFromObject_TD_23588620_input.getInt32(i, 0);
            tbl_Filter_TD_22325271_output.setInt32(r, 0, _d_date_sk3614_t);
            r++;
        }
    }
    tbl_Filter_TD_22325271_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_22325271_output #Row: " << tbl_Filter_TD_22325271_output.getNumRow() << std::endl;
}



void SW_Filter_TD_21974028(Table &tbl_SerializeFromObject_TD_22523954_input, Table &tbl_Filter_TD_21974028_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(i_item_sk#3570) AND ((isnotnull(i_brand_id#3577) AND isnotnull(i_class_id#3579)) AND isnotnull(i_category_id#3581))))
    // Input: ListBuffer(i_item_sk#3570, i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    // Output: ListBuffer(i_item_sk#3570, i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_22523954_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk3570 = tbl_SerializeFromObject_TD_22523954_input.getInt32(i, 0);
        int32_t _i_brand_id3577 = tbl_SerializeFromObject_TD_22523954_input.getInt32(i, 1);
        int32_t _i_class_id3579 = tbl_SerializeFromObject_TD_22523954_input.getInt32(i, 2);
        int32_t _i_category_id3581 = tbl_SerializeFromObject_TD_22523954_input.getInt32(i, 3);
        if ((_i_item_sk3570!= 0) && (((_i_brand_id3577!= 0) && (_i_class_id3579!= 0)) && (_i_category_id3581!= 0))) {
            int32_t _i_item_sk3570_t = tbl_SerializeFromObject_TD_22523954_input.getInt32(i, 0);
            tbl_Filter_TD_21974028_output.setInt32(r, 0, _i_item_sk3570_t);
            int32_t _i_brand_id3577_t = tbl_SerializeFromObject_TD_22523954_input.getInt32(i, 1);
            tbl_Filter_TD_21974028_output.setInt32(r, 1, _i_brand_id3577_t);
            int32_t _i_class_id3579_t = tbl_SerializeFromObject_TD_22523954_input.getInt32(i, 2);
            tbl_Filter_TD_21974028_output.setInt32(r, 2, _i_class_id3579_t);
            int32_t _i_category_id3581_t = tbl_SerializeFromObject_TD_22523954_input.getInt32(i, 3);
            tbl_Filter_TD_21974028_output.setInt32(r, 3, _i_category_id3581_t);
            r++;
        }
    }
    tbl_Filter_TD_21974028_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_21974028_output #Row: " << tbl_Filter_TD_21974028_output.getNumRow() << std::endl;
}


void SW_Filter_TD_21732416(Table &tbl_SerializeFromObject_TD_22107187_input, Table &tbl_Filter_TD_21732416_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(i_item_sk#3570) AND ((isnotnull(i_brand_id#3577) AND isnotnull(i_class_id#3579)) AND isnotnull(i_category_id#3581))))
    // Input: ListBuffer(i_item_sk#3570, i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    // Output: ListBuffer(i_item_sk#3570, i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_22107187_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk3570 = tbl_SerializeFromObject_TD_22107187_input.getInt32(i, 0);
        int32_t _i_brand_id3577 = tbl_SerializeFromObject_TD_22107187_input.getInt32(i, 1);
        int32_t _i_class_id3579 = tbl_SerializeFromObject_TD_22107187_input.getInt32(i, 2);
        int32_t _i_category_id3581 = tbl_SerializeFromObject_TD_22107187_input.getInt32(i, 3);
        if ((_i_item_sk3570!= 0) && (((_i_brand_id3577!= 0) && (_i_class_id3579!= 0)) && (_i_category_id3581!= 0))) {
            int32_t _i_item_sk3570_t = tbl_SerializeFromObject_TD_22107187_input.getInt32(i, 0);
            tbl_Filter_TD_21732416_output.setInt32(r, 0, _i_item_sk3570_t);
            int32_t _i_brand_id3577_t = tbl_SerializeFromObject_TD_22107187_input.getInt32(i, 1);
            tbl_Filter_TD_21732416_output.setInt32(r, 1, _i_brand_id3577_t);
            int32_t _i_class_id3579_t = tbl_SerializeFromObject_TD_22107187_input.getInt32(i, 2);
            tbl_Filter_TD_21732416_output.setInt32(r, 2, _i_class_id3579_t);
            int32_t _i_category_id3581_t = tbl_SerializeFromObject_TD_22107187_input.getInt32(i, 3);
            tbl_Filter_TD_21732416_output.setInt32(r, 3, _i_category_id3581_t);
            r++;
        }
    }
    tbl_Filter_TD_21732416_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_21732416_output #Row: " << tbl_Filter_TD_21732416_output.getNumRow() << std::endl;
}


void SW_Filter_TD_21687708(Table &tbl_SerializeFromObject_TD_22532022_input, Table &tbl_Filter_TD_21687708_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(i_item_sk#3570) AND ((isnotnull(i_brand_id#3577) AND isnotnull(i_class_id#3579)) AND isnotnull(i_category_id#3581))))
    // Input: ListBuffer(i_item_sk#3570, i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    // Output: ListBuffer(i_item_sk#3570, i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_22532022_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk3570 = tbl_SerializeFromObject_TD_22532022_input.getInt32(i, 0);
        int32_t _i_brand_id3577 = tbl_SerializeFromObject_TD_22532022_input.getInt32(i, 1);
        int32_t _i_class_id3579 = tbl_SerializeFromObject_TD_22532022_input.getInt32(i, 2);
        int32_t _i_category_id3581 = tbl_SerializeFromObject_TD_22532022_input.getInt32(i, 3);
        if ((_i_item_sk3570!= 0) && (((_i_brand_id3577!= 0) && (_i_class_id3579!= 0)) && (_i_category_id3581!= 0))) {
            int32_t _i_item_sk3570_t = tbl_SerializeFromObject_TD_22532022_input.getInt32(i, 0);
            tbl_Filter_TD_21687708_output.setInt32(r, 0, _i_item_sk3570_t);
            int32_t _i_brand_id3577_t = tbl_SerializeFromObject_TD_22532022_input.getInt32(i, 1);
            tbl_Filter_TD_21687708_output.setInt32(r, 1, _i_brand_id3577_t);
            int32_t _i_class_id3579_t = tbl_SerializeFromObject_TD_22532022_input.getInt32(i, 2);
            tbl_Filter_TD_21687708_output.setInt32(r, 2, _i_class_id3579_t);
            int32_t _i_category_id3581_t = tbl_SerializeFromObject_TD_22532022_input.getInt32(i, 3);
            tbl_Filter_TD_21687708_output.setInt32(r, 3, _i_category_id3581_t);
            r++;
        }
    }
    tbl_Filter_TD_21687708_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_21687708_output #Row: " << tbl_Filter_TD_21687708_output.getNumRow() << std::endl;
}


void SW_Filter_TD_21676370(Table &tbl_SerializeFromObject_TD_2279688_input, Table &tbl_Filter_TD_21676370_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(i_item_sk#3570) AND ((isnotnull(i_brand_id#3577) AND isnotnull(i_class_id#3579)) AND isnotnull(i_category_id#3581))))
    // Input: ListBuffer(i_item_sk#3570, i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    // Output: ListBuffer(i_item_sk#3570, i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_2279688_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk3570 = tbl_SerializeFromObject_TD_2279688_input.getInt32(i, 0);
        int32_t _i_brand_id3577 = tbl_SerializeFromObject_TD_2279688_input.getInt32(i, 1);
        int32_t _i_class_id3579 = tbl_SerializeFromObject_TD_2279688_input.getInt32(i, 2);
        int32_t _i_category_id3581 = tbl_SerializeFromObject_TD_2279688_input.getInt32(i, 3);
        if ((_i_item_sk3570!= 0) && (((_i_brand_id3577!= 0) && (_i_class_id3579!= 0)) && (_i_category_id3581!= 0))) {
            int32_t _i_item_sk3570_t = tbl_SerializeFromObject_TD_2279688_input.getInt32(i, 0);
            tbl_Filter_TD_21676370_output.setInt32(r, 0, _i_item_sk3570_t);
            int32_t _i_brand_id3577_t = tbl_SerializeFromObject_TD_2279688_input.getInt32(i, 1);
            tbl_Filter_TD_21676370_output.setInt32(r, 1, _i_brand_id3577_t);
            int32_t _i_class_id3579_t = tbl_SerializeFromObject_TD_2279688_input.getInt32(i, 2);
            tbl_Filter_TD_21676370_output.setInt32(r, 2, _i_class_id3579_t);
            int32_t _i_category_id3581_t = tbl_SerializeFromObject_TD_2279688_input.getInt32(i, 3);
            tbl_Filter_TD_21676370_output.setInt32(r, 3, _i_category_id3581_t);
            r++;
        }
    }
    tbl_Filter_TD_21676370_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_21676370_output #Row: " << tbl_Filter_TD_21676370_output.getNumRow() << std::endl;
}


void SW_Filter_TD_21296131(Table &tbl_SerializeFromObject_TD_22554494_input, Table &tbl_Filter_TD_21296131_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(i_item_sk#3570) AND ((isnotnull(i_brand_id#3577) AND isnotnull(i_class_id#3579)) AND isnotnull(i_category_id#3581))))
    // Input: ListBuffer(i_item_sk#3570, i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    // Output: ListBuffer(i_item_sk#3570, i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_22554494_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk3570 = tbl_SerializeFromObject_TD_22554494_input.getInt32(i, 0);
        int32_t _i_brand_id3577 = tbl_SerializeFromObject_TD_22554494_input.getInt32(i, 1);
        int32_t _i_class_id3579 = tbl_SerializeFromObject_TD_22554494_input.getInt32(i, 2);
        int32_t _i_category_id3581 = tbl_SerializeFromObject_TD_22554494_input.getInt32(i, 3);
        if ((_i_item_sk3570!= 0) && (((_i_brand_id3577!= 0) && (_i_class_id3579!= 0)) && (_i_category_id3581!= 0))) {
            int32_t _i_item_sk3570_t = tbl_SerializeFromObject_TD_22554494_input.getInt32(i, 0);
            tbl_Filter_TD_21296131_output.setInt32(r, 0, _i_item_sk3570_t);
            int32_t _i_brand_id3577_t = tbl_SerializeFromObject_TD_22554494_input.getInt32(i, 1);
            tbl_Filter_TD_21296131_output.setInt32(r, 1, _i_brand_id3577_t);
            int32_t _i_class_id3579_t = tbl_SerializeFromObject_TD_22554494_input.getInt32(i, 2);
            tbl_Filter_TD_21296131_output.setInt32(r, 2, _i_class_id3579_t);
            int32_t _i_category_id3581_t = tbl_SerializeFromObject_TD_22554494_input.getInt32(i, 3);
            tbl_Filter_TD_21296131_output.setInt32(r, 3, _i_category_id3581_t);
            r++;
        }
    }
    tbl_Filter_TD_21296131_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_21296131_output #Row: " << tbl_Filter_TD_21296131_output.getNumRow() << std::endl;
}


void SW_Filter_TD_21245151(Table &tbl_SerializeFromObject_TD_22822938_input, Table &tbl_Filter_TD_21245151_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(i_item_sk#3570) AND ((isnotnull(i_brand_id#3577) AND isnotnull(i_class_id#3579)) AND isnotnull(i_category_id#3581))))
    // Input: ListBuffer(i_item_sk#3570, i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    // Output: ListBuffer(i_item_sk#3570, i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_22822938_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk3570 = tbl_SerializeFromObject_TD_22822938_input.getInt32(i, 0);
        int32_t _i_brand_id3577 = tbl_SerializeFromObject_TD_22822938_input.getInt32(i, 1);
        int32_t _i_class_id3579 = tbl_SerializeFromObject_TD_22822938_input.getInt32(i, 2);
        int32_t _i_category_id3581 = tbl_SerializeFromObject_TD_22822938_input.getInt32(i, 3);
        if ((_i_item_sk3570!= 0) && (((_i_brand_id3577!= 0) && (_i_class_id3579!= 0)) && (_i_category_id3581!= 0))) {
            int32_t _i_item_sk3570_t = tbl_SerializeFromObject_TD_22822938_input.getInt32(i, 0);
            tbl_Filter_TD_21245151_output.setInt32(r, 0, _i_item_sk3570_t);
            int32_t _i_brand_id3577_t = tbl_SerializeFromObject_TD_22822938_input.getInt32(i, 1);
            tbl_Filter_TD_21245151_output.setInt32(r, 1, _i_brand_id3577_t);
            int32_t _i_class_id3579_t = tbl_SerializeFromObject_TD_22822938_input.getInt32(i, 2);
            tbl_Filter_TD_21245151_output.setInt32(r, 2, _i_class_id3579_t);
            int32_t _i_category_id3581_t = tbl_SerializeFromObject_TD_22822938_input.getInt32(i, 3);
            tbl_Filter_TD_21245151_output.setInt32(r, 3, _i_category_id3581_t);
            r++;
        }
    }
    tbl_Filter_TD_21245151_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_21245151_output #Row: " << tbl_Filter_TD_21245151_output.getNumRow() << std::endl;
}

struct SW_JOIN_LEFTSEMI_TD_20570380_key_leftMajor {
    int32_t _i_brand_id3577;
    int32_t _i_class_id3579;
    int32_t _i_category_id3581;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_20570380_key_leftMajor& other) const {
        return ((_i_brand_id3577 == other._i_brand_id3577) && (_i_class_id3579 == other._i_class_id3579) && (_i_category_id3581 == other._i_category_id3581));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_20570380_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_20570380_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id3577)) + (hash<int32_t>()(k._i_class_id3579)) + (hash<int32_t>()(k._i_category_id3581));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_20570380_payload_leftMajor {
    int32_t _i_item_sk3570;
    int32_t _i_brand_id3577;
    int32_t _i_class_id3579;
    int32_t _i_category_id3581;
};
struct SW_JOIN_LEFTSEMI_TD_20570380_key_rightMajor {
    int32_t _i_brand_id3599;
    int32_t _i_class_id3601;
    int32_t _i_category_id3603;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_20570380_key_rightMajor& other) const {
        return ((_i_brand_id3599 == other._i_brand_id3599) && (_i_class_id3601 == other._i_class_id3601) && (_i_category_id3603 == other._i_category_id3603));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_20570380_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_20570380_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id3599)) + (hash<int32_t>()(k._i_class_id3601)) + (hash<int32_t>()(k._i_category_id3603));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_20570380_payload_rightMajor {
    int32_t _i_brand_id3599;
    int32_t _i_class_id3601;
    int32_t _i_category_id3603;
};
void SW_JOIN_LEFTSEMI_TD_20570380(Table &tbl_Filter_TD_21974028_output, Table &tbl_JOIN_INNER_TD_2171179_output, Table &tbl_JOIN_LEFTSEMI_TD_20570380_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTSEMI
    // Operation: ListBuffer((((i_brand_id#3577 <=> i_brand_id#3599) AND (i_class_id#3579 <=> i_class_id#3601)) AND (i_category_id#3581 <=> i_category_id#3603)))
    // Left Table: ListBuffer(i_item_sk#3570, i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    // Right Table: ListBuffer(i_brand_id#3599, i_class_id#3601, i_category_id#3603)
    // Output Table: ListBuffer(i_item_sk#3570, i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    int left_nrow = tbl_Filter_TD_21974028_output.getNumRow();
    int right_nrow = tbl_JOIN_INNER_TD_2171179_output.getNumRow();
        std::unordered_map<SW_JOIN_LEFTSEMI_TD_20570380_key_rightMajor, SW_JOIN_LEFTSEMI_TD_20570380_payload_rightMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_2171179_output.getNumRow();
        int nrow2 = tbl_Filter_TD_21974028_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_brand_id3599_k = tbl_JOIN_INNER_TD_2171179_output.getInt32(i, 0);
            int32_t _i_class_id3601_k = tbl_JOIN_INNER_TD_2171179_output.getInt32(i, 1);
            int32_t _i_category_id3603_k = tbl_JOIN_INNER_TD_2171179_output.getInt32(i, 2);
            SW_JOIN_LEFTSEMI_TD_20570380_key_rightMajor keyA{_i_brand_id3599_k, _i_class_id3601_k, _i_category_id3603_k};
            int32_t _i_brand_id3599 = tbl_JOIN_INNER_TD_2171179_output.getInt32(i, 0);
            int32_t _i_class_id3601 = tbl_JOIN_INNER_TD_2171179_output.getInt32(i, 1);
            int32_t _i_category_id3603 = tbl_JOIN_INNER_TD_2171179_output.getInt32(i, 2);
            SW_JOIN_LEFTSEMI_TD_20570380_payload_rightMajor payloadA{_i_brand_id3599, _i_class_id3601, _i_category_id3603};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_brand_id3577_k = tbl_Filter_TD_21974028_output.getInt32(i, 1);
            int32_t _i_class_id3579_k = tbl_Filter_TD_21974028_output.getInt32(i, 2);
            int32_t _i_category_id3581_k = tbl_Filter_TD_21974028_output.getInt32(i, 3);
            auto it = ht1.find(SW_JOIN_LEFTSEMI_TD_20570380_key_rightMajor{_i_brand_id3577_k, _i_class_id3579_k, _i_category_id3581_k});
            if (it != ht1.end()) {
                int32_t _i_item_sk3570 = tbl_Filter_TD_21974028_output.getInt32(i, 0);
                int32_t _i_brand_id3577 = tbl_Filter_TD_21974028_output.getInt32(i, 1);
                int32_t _i_class_id3579 = tbl_Filter_TD_21974028_output.getInt32(i, 2);
                int32_t _i_category_id3581 = tbl_Filter_TD_21974028_output.getInt32(i, 3);
                tbl_JOIN_LEFTSEMI_TD_20570380_output.setInt32(r, 0, _i_item_sk3570);
                tbl_JOIN_LEFTSEMI_TD_20570380_output.setInt32(r, 1, _i_brand_id3577);
                tbl_JOIN_LEFTSEMI_TD_20570380_output.setInt32(r, 2, _i_class_id3579);
                tbl_JOIN_LEFTSEMI_TD_20570380_output.setInt32(r, 3, _i_category_id3581);
                r++;
            }
        }
        tbl_JOIN_LEFTSEMI_TD_20570380_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTSEMI_TD_20570380_output #Row: " << tbl_JOIN_LEFTSEMI_TD_20570380_output.getNumRow() << std::endl;
}

void SW_Filter_TD_20668439(Table &tbl_SerializeFromObject_TD_21838887_input, Table &tbl_Filter_TD_20668439_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_item_sk#1208) AND isnotnull(ss_sold_date_sk#1206)))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_21838887_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_21838887_input.getInt32(i, 1);
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_21838887_input.getInt32(i, 0);
        if ((_ss_item_sk1208!= 0) && (_ss_sold_date_sk1206!= 0)) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_21838887_input.getInt32(i, 0);
            tbl_Filter_TD_20668439_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_21838887_input.getInt32(i, 1);
            tbl_Filter_TD_20668439_output.setInt32(r, 1, _ss_item_sk1208_t);
            r++;
        }
    }
    tbl_Filter_TD_20668439_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_20668439_output #Row: " << tbl_Filter_TD_20668439_output.getNumRow() << std::endl;
}

struct SW_JOIN_LEFTSEMI_TD_20456054_key_leftMajor {
    int32_t _i_brand_id3577;
    int32_t _i_class_id3579;
    int32_t _i_category_id3581;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_20456054_key_leftMajor& other) const {
        return ((_i_brand_id3577 == other._i_brand_id3577) && (_i_class_id3579 == other._i_class_id3579) && (_i_category_id3581 == other._i_category_id3581));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_20456054_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_20456054_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id3577)) + (hash<int32_t>()(k._i_class_id3579)) + (hash<int32_t>()(k._i_category_id3581));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_20456054_payload_leftMajor {
    int32_t _i_item_sk3570;
    int32_t _i_brand_id3577;
    int32_t _i_class_id3579;
    int32_t _i_category_id3581;
};
struct SW_JOIN_LEFTSEMI_TD_20456054_key_rightMajor {
    int32_t _i_brand_id3599;
    int32_t _i_class_id3601;
    int32_t _i_category_id3603;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_20456054_key_rightMajor& other) const {
        return ((_i_brand_id3599 == other._i_brand_id3599) && (_i_class_id3601 == other._i_class_id3601) && (_i_category_id3603 == other._i_category_id3603));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_20456054_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_20456054_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id3599)) + (hash<int32_t>()(k._i_class_id3601)) + (hash<int32_t>()(k._i_category_id3603));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_20456054_payload_rightMajor {
    int32_t _i_brand_id3599;
    int32_t _i_class_id3601;
    int32_t _i_category_id3603;
};
void SW_JOIN_LEFTSEMI_TD_20456054(Table &tbl_Filter_TD_21732416_output, Table &tbl_JOIN_INNER_TD_21260962_output, Table &tbl_JOIN_LEFTSEMI_TD_20456054_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTSEMI
    // Operation: ListBuffer((((i_brand_id#3577 <=> i_brand_id#3599) AND (i_class_id#3579 <=> i_class_id#3601)) AND (i_category_id#3581 <=> i_category_id#3603)))
    // Left Table: ListBuffer(i_item_sk#3570, i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    // Right Table: ListBuffer(i_brand_id#3599, i_class_id#3601, i_category_id#3603)
    // Output Table: ListBuffer(i_item_sk#3570, i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    int left_nrow = tbl_Filter_TD_21732416_output.getNumRow();
    int right_nrow = tbl_JOIN_INNER_TD_21260962_output.getNumRow();
        std::unordered_map<SW_JOIN_LEFTSEMI_TD_20456054_key_rightMajor, SW_JOIN_LEFTSEMI_TD_20456054_payload_rightMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_21260962_output.getNumRow();
        int nrow2 = tbl_Filter_TD_21732416_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_brand_id3599_k = tbl_JOIN_INNER_TD_21260962_output.getInt32(i, 0);
            int32_t _i_class_id3601_k = tbl_JOIN_INNER_TD_21260962_output.getInt32(i, 1);
            int32_t _i_category_id3603_k = tbl_JOIN_INNER_TD_21260962_output.getInt32(i, 2);
            SW_JOIN_LEFTSEMI_TD_20456054_key_rightMajor keyA{_i_brand_id3599_k, _i_class_id3601_k, _i_category_id3603_k};
            int32_t _i_brand_id3599 = tbl_JOIN_INNER_TD_21260962_output.getInt32(i, 0);
            int32_t _i_class_id3601 = tbl_JOIN_INNER_TD_21260962_output.getInt32(i, 1);
            int32_t _i_category_id3603 = tbl_JOIN_INNER_TD_21260962_output.getInt32(i, 2);
            SW_JOIN_LEFTSEMI_TD_20456054_payload_rightMajor payloadA{_i_brand_id3599, _i_class_id3601, _i_category_id3603};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_brand_id3577_k = tbl_Filter_TD_21732416_output.getInt32(i, 1);
            int32_t _i_class_id3579_k = tbl_Filter_TD_21732416_output.getInt32(i, 2);
            int32_t _i_category_id3581_k = tbl_Filter_TD_21732416_output.getInt32(i, 3);
            auto it = ht1.find(SW_JOIN_LEFTSEMI_TD_20456054_key_rightMajor{_i_brand_id3577_k, _i_class_id3579_k, _i_category_id3581_k});
            if (it != ht1.end()) {
                int32_t _i_item_sk3570 = tbl_Filter_TD_21732416_output.getInt32(i, 0);
                int32_t _i_brand_id3577 = tbl_Filter_TD_21732416_output.getInt32(i, 1);
                int32_t _i_class_id3579 = tbl_Filter_TD_21732416_output.getInt32(i, 2);
                int32_t _i_category_id3581 = tbl_Filter_TD_21732416_output.getInt32(i, 3);
                tbl_JOIN_LEFTSEMI_TD_20456054_output.setInt32(r, 0, _i_item_sk3570);
                tbl_JOIN_LEFTSEMI_TD_20456054_output.setInt32(r, 1, _i_brand_id3577);
                tbl_JOIN_LEFTSEMI_TD_20456054_output.setInt32(r, 2, _i_class_id3579);
                tbl_JOIN_LEFTSEMI_TD_20456054_output.setInt32(r, 3, _i_category_id3581);
                r++;
            }
        }
        tbl_JOIN_LEFTSEMI_TD_20456054_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTSEMI_TD_20456054_output #Row: " << tbl_JOIN_LEFTSEMI_TD_20456054_output.getNumRow() << std::endl;
}

void SW_Filter_TD_20737170(Table &tbl_SerializeFromObject_TD_21116880_input, Table &tbl_Filter_TD_20737170_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_item_sk#1208) AND isnotnull(ss_sold_date_sk#1206)))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_21116880_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_21116880_input.getInt32(i, 1);
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_21116880_input.getInt32(i, 0);
        if ((_ss_item_sk1208!= 0) && (_ss_sold_date_sk1206!= 0)) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_21116880_input.getInt32(i, 0);
            tbl_Filter_TD_20737170_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_21116880_input.getInt32(i, 1);
            tbl_Filter_TD_20737170_output.setInt32(r, 1, _ss_item_sk1208_t);
            r++;
        }
    }
    tbl_Filter_TD_20737170_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_20737170_output #Row: " << tbl_Filter_TD_20737170_output.getNumRow() << std::endl;
}

struct SW_JOIN_LEFTSEMI_TD_20912143_key_leftMajor {
    int32_t _i_brand_id3577;
    int32_t _i_class_id3579;
    int32_t _i_category_id3581;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_20912143_key_leftMajor& other) const {
        return ((_i_brand_id3577 == other._i_brand_id3577) && (_i_class_id3579 == other._i_class_id3579) && (_i_category_id3581 == other._i_category_id3581));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_20912143_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_20912143_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id3577)) + (hash<int32_t>()(k._i_class_id3579)) + (hash<int32_t>()(k._i_category_id3581));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_20912143_payload_leftMajor {
    int32_t _i_item_sk3570;
    int32_t _i_brand_id3577;
    int32_t _i_class_id3579;
    int32_t _i_category_id3581;
};
struct SW_JOIN_LEFTSEMI_TD_20912143_key_rightMajor {
    int32_t _i_brand_id3599;
    int32_t _i_class_id3601;
    int32_t _i_category_id3603;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_20912143_key_rightMajor& other) const {
        return ((_i_brand_id3599 == other._i_brand_id3599) && (_i_class_id3601 == other._i_class_id3601) && (_i_category_id3603 == other._i_category_id3603));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_20912143_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_20912143_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id3599)) + (hash<int32_t>()(k._i_class_id3601)) + (hash<int32_t>()(k._i_category_id3603));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_20912143_payload_rightMajor {
    int32_t _i_brand_id3599;
    int32_t _i_class_id3601;
    int32_t _i_category_id3603;
};
void SW_JOIN_LEFTSEMI_TD_20912143(Table &tbl_Filter_TD_21687708_output, Table &tbl_JOIN_INNER_TD_21591695_output, Table &tbl_JOIN_LEFTSEMI_TD_20912143_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTSEMI
    // Operation: ListBuffer((((i_brand_id#3577 <=> i_brand_id#3599) AND (i_class_id#3579 <=> i_class_id#3601)) AND (i_category_id#3581 <=> i_category_id#3603)))
    // Left Table: ListBuffer(i_item_sk#3570, i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    // Right Table: ListBuffer(i_brand_id#3599, i_class_id#3601, i_category_id#3603)
    // Output Table: ListBuffer(i_item_sk#3570, i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    int left_nrow = tbl_Filter_TD_21687708_output.getNumRow();
    int right_nrow = tbl_JOIN_INNER_TD_21591695_output.getNumRow();
        std::unordered_map<SW_JOIN_LEFTSEMI_TD_20912143_key_rightMajor, SW_JOIN_LEFTSEMI_TD_20912143_payload_rightMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_21591695_output.getNumRow();
        int nrow2 = tbl_Filter_TD_21687708_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_brand_id3599_k = tbl_JOIN_INNER_TD_21591695_output.getInt32(i, 0);
            int32_t _i_class_id3601_k = tbl_JOIN_INNER_TD_21591695_output.getInt32(i, 1);
            int32_t _i_category_id3603_k = tbl_JOIN_INNER_TD_21591695_output.getInt32(i, 2);
            SW_JOIN_LEFTSEMI_TD_20912143_key_rightMajor keyA{_i_brand_id3599_k, _i_class_id3601_k, _i_category_id3603_k};
            int32_t _i_brand_id3599 = tbl_JOIN_INNER_TD_21591695_output.getInt32(i, 0);
            int32_t _i_class_id3601 = tbl_JOIN_INNER_TD_21591695_output.getInt32(i, 1);
            int32_t _i_category_id3603 = tbl_JOIN_INNER_TD_21591695_output.getInt32(i, 2);
            SW_JOIN_LEFTSEMI_TD_20912143_payload_rightMajor payloadA{_i_brand_id3599, _i_class_id3601, _i_category_id3603};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_brand_id3577_k = tbl_Filter_TD_21687708_output.getInt32(i, 1);
            int32_t _i_class_id3579_k = tbl_Filter_TD_21687708_output.getInt32(i, 2);
            int32_t _i_category_id3581_k = tbl_Filter_TD_21687708_output.getInt32(i, 3);
            auto it = ht1.find(SW_JOIN_LEFTSEMI_TD_20912143_key_rightMajor{_i_brand_id3577_k, _i_class_id3579_k, _i_category_id3581_k});
            if (it != ht1.end()) {
                int32_t _i_item_sk3570 = tbl_Filter_TD_21687708_output.getInt32(i, 0);
                int32_t _i_brand_id3577 = tbl_Filter_TD_21687708_output.getInt32(i, 1);
                int32_t _i_class_id3579 = tbl_Filter_TD_21687708_output.getInt32(i, 2);
                int32_t _i_category_id3581 = tbl_Filter_TD_21687708_output.getInt32(i, 3);
                tbl_JOIN_LEFTSEMI_TD_20912143_output.setInt32(r, 0, _i_item_sk3570);
                tbl_JOIN_LEFTSEMI_TD_20912143_output.setInt32(r, 1, _i_brand_id3577);
                tbl_JOIN_LEFTSEMI_TD_20912143_output.setInt32(r, 2, _i_class_id3579);
                tbl_JOIN_LEFTSEMI_TD_20912143_output.setInt32(r, 3, _i_category_id3581);
                r++;
            }
        }
        tbl_JOIN_LEFTSEMI_TD_20912143_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTSEMI_TD_20912143_output #Row: " << tbl_JOIN_LEFTSEMI_TD_20912143_output.getNumRow() << std::endl;
}

void SW_Filter_TD_20965663(Table &tbl_SerializeFromObject_TD_21762309_input, Table &tbl_Filter_TD_20965663_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_item_sk#1208) AND isnotnull(ss_sold_date_sk#1206)))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_21762309_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_21762309_input.getInt32(i, 1);
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_21762309_input.getInt32(i, 0);
        if ((_ss_item_sk1208!= 0) && (_ss_sold_date_sk1206!= 0)) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_21762309_input.getInt32(i, 0);
            tbl_Filter_TD_20965663_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_21762309_input.getInt32(i, 1);
            tbl_Filter_TD_20965663_output.setInt32(r, 1, _ss_item_sk1208_t);
            r++;
        }
    }
    tbl_Filter_TD_20965663_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_20965663_output #Row: " << tbl_Filter_TD_20965663_output.getNumRow() << std::endl;
}

struct SW_JOIN_LEFTSEMI_TD_20173689_key_leftMajor {
    int32_t _i_brand_id3577;
    int32_t _i_class_id3579;
    int32_t _i_category_id3581;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_20173689_key_leftMajor& other) const {
        return ((_i_brand_id3577 == other._i_brand_id3577) && (_i_class_id3579 == other._i_class_id3579) && (_i_category_id3581 == other._i_category_id3581));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_20173689_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_20173689_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id3577)) + (hash<int32_t>()(k._i_class_id3579)) + (hash<int32_t>()(k._i_category_id3581));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_20173689_payload_leftMajor {
    int32_t _i_item_sk3570;
    int32_t _i_brand_id3577;
    int32_t _i_class_id3579;
    int32_t _i_category_id3581;
};
struct SW_JOIN_LEFTSEMI_TD_20173689_key_rightMajor {
    int32_t _i_brand_id3599;
    int32_t _i_class_id3601;
    int32_t _i_category_id3603;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_20173689_key_rightMajor& other) const {
        return ((_i_brand_id3599 == other._i_brand_id3599) && (_i_class_id3601 == other._i_class_id3601) && (_i_category_id3603 == other._i_category_id3603));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_20173689_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_20173689_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id3599)) + (hash<int32_t>()(k._i_class_id3601)) + (hash<int32_t>()(k._i_category_id3603));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_20173689_payload_rightMajor {
    int32_t _i_brand_id3599;
    int32_t _i_class_id3601;
    int32_t _i_category_id3603;
};
void SW_JOIN_LEFTSEMI_TD_20173689(Table &tbl_Filter_TD_21676370_output, Table &tbl_JOIN_INNER_TD_21337322_output, Table &tbl_JOIN_LEFTSEMI_TD_20173689_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTSEMI
    // Operation: ListBuffer((((i_brand_id#3577 <=> i_brand_id#3599) AND (i_class_id#3579 <=> i_class_id#3601)) AND (i_category_id#3581 <=> i_category_id#3603)))
    // Left Table: ListBuffer(i_item_sk#3570, i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    // Right Table: ListBuffer(i_brand_id#3599, i_class_id#3601, i_category_id#3603)
    // Output Table: ListBuffer(i_item_sk#3570, i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    int left_nrow = tbl_Filter_TD_21676370_output.getNumRow();
    int right_nrow = tbl_JOIN_INNER_TD_21337322_output.getNumRow();
        std::unordered_map<SW_JOIN_LEFTSEMI_TD_20173689_key_rightMajor, SW_JOIN_LEFTSEMI_TD_20173689_payload_rightMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_21337322_output.getNumRow();
        int nrow2 = tbl_Filter_TD_21676370_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_brand_id3599_k = tbl_JOIN_INNER_TD_21337322_output.getInt32(i, 0);
            int32_t _i_class_id3601_k = tbl_JOIN_INNER_TD_21337322_output.getInt32(i, 1);
            int32_t _i_category_id3603_k = tbl_JOIN_INNER_TD_21337322_output.getInt32(i, 2);
            SW_JOIN_LEFTSEMI_TD_20173689_key_rightMajor keyA{_i_brand_id3599_k, _i_class_id3601_k, _i_category_id3603_k};
            int32_t _i_brand_id3599 = tbl_JOIN_INNER_TD_21337322_output.getInt32(i, 0);
            int32_t _i_class_id3601 = tbl_JOIN_INNER_TD_21337322_output.getInt32(i, 1);
            int32_t _i_category_id3603 = tbl_JOIN_INNER_TD_21337322_output.getInt32(i, 2);
            SW_JOIN_LEFTSEMI_TD_20173689_payload_rightMajor payloadA{_i_brand_id3599, _i_class_id3601, _i_category_id3603};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_brand_id3577_k = tbl_Filter_TD_21676370_output.getInt32(i, 1);
            int32_t _i_class_id3579_k = tbl_Filter_TD_21676370_output.getInt32(i, 2);
            int32_t _i_category_id3581_k = tbl_Filter_TD_21676370_output.getInt32(i, 3);
            auto it = ht1.find(SW_JOIN_LEFTSEMI_TD_20173689_key_rightMajor{_i_brand_id3577_k, _i_class_id3579_k, _i_category_id3581_k});
            if (it != ht1.end()) {
                int32_t _i_item_sk3570 = tbl_Filter_TD_21676370_output.getInt32(i, 0);
                int32_t _i_brand_id3577 = tbl_Filter_TD_21676370_output.getInt32(i, 1);
                int32_t _i_class_id3579 = tbl_Filter_TD_21676370_output.getInt32(i, 2);
                int32_t _i_category_id3581 = tbl_Filter_TD_21676370_output.getInt32(i, 3);
                tbl_JOIN_LEFTSEMI_TD_20173689_output.setInt32(r, 0, _i_item_sk3570);
                tbl_JOIN_LEFTSEMI_TD_20173689_output.setInt32(r, 1, _i_brand_id3577);
                tbl_JOIN_LEFTSEMI_TD_20173689_output.setInt32(r, 2, _i_class_id3579);
                tbl_JOIN_LEFTSEMI_TD_20173689_output.setInt32(r, 3, _i_category_id3581);
                r++;
            }
        }
        tbl_JOIN_LEFTSEMI_TD_20173689_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTSEMI_TD_20173689_output #Row: " << tbl_JOIN_LEFTSEMI_TD_20173689_output.getNumRow() << std::endl;
}

void SW_Filter_TD_20622373(Table &tbl_SerializeFromObject_TD_21828662_input, Table &tbl_Filter_TD_20622373_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_item_sk#1208) AND isnotnull(ss_sold_date_sk#1206)))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_21828662_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_21828662_input.getInt32(i, 1);
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_21828662_input.getInt32(i, 0);
        if ((_ss_item_sk1208!= 0) && (_ss_sold_date_sk1206!= 0)) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_21828662_input.getInt32(i, 0);
            tbl_Filter_TD_20622373_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_21828662_input.getInt32(i, 1);
            tbl_Filter_TD_20622373_output.setInt32(r, 1, _ss_item_sk1208_t);
            r++;
        }
    }
    tbl_Filter_TD_20622373_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_20622373_output #Row: " << tbl_Filter_TD_20622373_output.getNumRow() << std::endl;
}

struct SW_JOIN_LEFTSEMI_TD_20529163_key_leftMajor {
    int32_t _i_brand_id3577;
    int32_t _i_class_id3579;
    int32_t _i_category_id3581;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_20529163_key_leftMajor& other) const {
        return ((_i_brand_id3577 == other._i_brand_id3577) && (_i_class_id3579 == other._i_class_id3579) && (_i_category_id3581 == other._i_category_id3581));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_20529163_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_20529163_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id3577)) + (hash<int32_t>()(k._i_class_id3579)) + (hash<int32_t>()(k._i_category_id3581));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_20529163_payload_leftMajor {
    int32_t _i_item_sk3570;
    int32_t _i_brand_id3577;
    int32_t _i_class_id3579;
    int32_t _i_category_id3581;
};
struct SW_JOIN_LEFTSEMI_TD_20529163_key_rightMajor {
    int32_t _i_brand_id3599;
    int32_t _i_class_id3601;
    int32_t _i_category_id3603;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_20529163_key_rightMajor& other) const {
        return ((_i_brand_id3599 == other._i_brand_id3599) && (_i_class_id3601 == other._i_class_id3601) && (_i_category_id3603 == other._i_category_id3603));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_20529163_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_20529163_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id3599)) + (hash<int32_t>()(k._i_class_id3601)) + (hash<int32_t>()(k._i_category_id3603));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_20529163_payload_rightMajor {
    int32_t _i_brand_id3599;
    int32_t _i_class_id3601;
    int32_t _i_category_id3603;
};
void SW_JOIN_LEFTSEMI_TD_20529163(Table &tbl_Filter_TD_21296131_output, Table &tbl_JOIN_INNER_TD_21313777_output, Table &tbl_JOIN_LEFTSEMI_TD_20529163_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTSEMI
    // Operation: ListBuffer((((i_brand_id#3577 <=> i_brand_id#3599) AND (i_class_id#3579 <=> i_class_id#3601)) AND (i_category_id#3581 <=> i_category_id#3603)))
    // Left Table: ListBuffer(i_item_sk#3570, i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    // Right Table: ListBuffer(i_brand_id#3599, i_class_id#3601, i_category_id#3603)
    // Output Table: ListBuffer(i_item_sk#3570, i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    int left_nrow = tbl_Filter_TD_21296131_output.getNumRow();
    int right_nrow = tbl_JOIN_INNER_TD_21313777_output.getNumRow();
        std::unordered_map<SW_JOIN_LEFTSEMI_TD_20529163_key_rightMajor, SW_JOIN_LEFTSEMI_TD_20529163_payload_rightMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_21313777_output.getNumRow();
        int nrow2 = tbl_Filter_TD_21296131_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_brand_id3599_k = tbl_JOIN_INNER_TD_21313777_output.getInt32(i, 0);
            int32_t _i_class_id3601_k = tbl_JOIN_INNER_TD_21313777_output.getInt32(i, 1);
            int32_t _i_category_id3603_k = tbl_JOIN_INNER_TD_21313777_output.getInt32(i, 2);
            SW_JOIN_LEFTSEMI_TD_20529163_key_rightMajor keyA{_i_brand_id3599_k, _i_class_id3601_k, _i_category_id3603_k};
            int32_t _i_brand_id3599 = tbl_JOIN_INNER_TD_21313777_output.getInt32(i, 0);
            int32_t _i_class_id3601 = tbl_JOIN_INNER_TD_21313777_output.getInt32(i, 1);
            int32_t _i_category_id3603 = tbl_JOIN_INNER_TD_21313777_output.getInt32(i, 2);
            SW_JOIN_LEFTSEMI_TD_20529163_payload_rightMajor payloadA{_i_brand_id3599, _i_class_id3601, _i_category_id3603};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_brand_id3577_k = tbl_Filter_TD_21296131_output.getInt32(i, 1);
            int32_t _i_class_id3579_k = tbl_Filter_TD_21296131_output.getInt32(i, 2);
            int32_t _i_category_id3581_k = tbl_Filter_TD_21296131_output.getInt32(i, 3);
            auto it = ht1.find(SW_JOIN_LEFTSEMI_TD_20529163_key_rightMajor{_i_brand_id3577_k, _i_class_id3579_k, _i_category_id3581_k});
            if (it != ht1.end()) {
                int32_t _i_item_sk3570 = tbl_Filter_TD_21296131_output.getInt32(i, 0);
                int32_t _i_brand_id3577 = tbl_Filter_TD_21296131_output.getInt32(i, 1);
                int32_t _i_class_id3579 = tbl_Filter_TD_21296131_output.getInt32(i, 2);
                int32_t _i_category_id3581 = tbl_Filter_TD_21296131_output.getInt32(i, 3);
                tbl_JOIN_LEFTSEMI_TD_20529163_output.setInt32(r, 0, _i_item_sk3570);
                tbl_JOIN_LEFTSEMI_TD_20529163_output.setInt32(r, 1, _i_brand_id3577);
                tbl_JOIN_LEFTSEMI_TD_20529163_output.setInt32(r, 2, _i_class_id3579);
                tbl_JOIN_LEFTSEMI_TD_20529163_output.setInt32(r, 3, _i_category_id3581);
                r++;
            }
        }
        tbl_JOIN_LEFTSEMI_TD_20529163_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTSEMI_TD_20529163_output #Row: " << tbl_JOIN_LEFTSEMI_TD_20529163_output.getNumRow() << std::endl;
}

void SW_Filter_TD_20114114(Table &tbl_SerializeFromObject_TD_21970253_input, Table &tbl_Filter_TD_20114114_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_item_sk#1208) AND isnotnull(ss_sold_date_sk#1206)))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_21970253_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_21970253_input.getInt32(i, 1);
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_21970253_input.getInt32(i, 0);
        if ((_ss_item_sk1208!= 0) && (_ss_sold_date_sk1206!= 0)) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_21970253_input.getInt32(i, 0);
            tbl_Filter_TD_20114114_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_21970253_input.getInt32(i, 1);
            tbl_Filter_TD_20114114_output.setInt32(r, 1, _ss_item_sk1208_t);
            r++;
        }
    }
    tbl_Filter_TD_20114114_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_20114114_output #Row: " << tbl_Filter_TD_20114114_output.getNumRow() << std::endl;
}

struct SW_JOIN_LEFTSEMI_TD_20691722_key_leftMajor {
    int32_t _i_brand_id3577;
    int32_t _i_class_id3579;
    int32_t _i_category_id3581;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_20691722_key_leftMajor& other) const {
        return ((_i_brand_id3577 == other._i_brand_id3577) && (_i_class_id3579 == other._i_class_id3579) && (_i_category_id3581 == other._i_category_id3581));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_20691722_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_20691722_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id3577)) + (hash<int32_t>()(k._i_class_id3579)) + (hash<int32_t>()(k._i_category_id3581));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_20691722_payload_leftMajor {
    int32_t _i_item_sk3570;
    int32_t _i_brand_id3577;
    int32_t _i_class_id3579;
    int32_t _i_category_id3581;
};
struct SW_JOIN_LEFTSEMI_TD_20691722_key_rightMajor {
    int32_t _i_brand_id3599;
    int32_t _i_class_id3601;
    int32_t _i_category_id3603;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_20691722_key_rightMajor& other) const {
        return ((_i_brand_id3599 == other._i_brand_id3599) && (_i_class_id3601 == other._i_class_id3601) && (_i_category_id3603 == other._i_category_id3603));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_20691722_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_20691722_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id3599)) + (hash<int32_t>()(k._i_class_id3601)) + (hash<int32_t>()(k._i_category_id3603));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_20691722_payload_rightMajor {
    int32_t _i_brand_id3599;
    int32_t _i_class_id3601;
    int32_t _i_category_id3603;
};
void SW_JOIN_LEFTSEMI_TD_20691722(Table &tbl_Filter_TD_21245151_output, Table &tbl_JOIN_INNER_TD_21828706_output, Table &tbl_JOIN_LEFTSEMI_TD_20691722_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTSEMI
    // Operation: ListBuffer((((i_brand_id#3577 <=> i_brand_id#3599) AND (i_class_id#3579 <=> i_class_id#3601)) AND (i_category_id#3581 <=> i_category_id#3603)))
    // Left Table: ListBuffer(i_item_sk#3570, i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    // Right Table: ListBuffer(i_brand_id#3599, i_class_id#3601, i_category_id#3603)
    // Output Table: ListBuffer(i_item_sk#3570, i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    int left_nrow = tbl_Filter_TD_21245151_output.getNumRow();
    int right_nrow = tbl_JOIN_INNER_TD_21828706_output.getNumRow();
        std::unordered_map<SW_JOIN_LEFTSEMI_TD_20691722_key_rightMajor, SW_JOIN_LEFTSEMI_TD_20691722_payload_rightMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_21828706_output.getNumRow();
        int nrow2 = tbl_Filter_TD_21245151_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_brand_id3599_k = tbl_JOIN_INNER_TD_21828706_output.getInt32(i, 0);
            int32_t _i_class_id3601_k = tbl_JOIN_INNER_TD_21828706_output.getInt32(i, 1);
            int32_t _i_category_id3603_k = tbl_JOIN_INNER_TD_21828706_output.getInt32(i, 2);
            SW_JOIN_LEFTSEMI_TD_20691722_key_rightMajor keyA{_i_brand_id3599_k, _i_class_id3601_k, _i_category_id3603_k};
            int32_t _i_brand_id3599 = tbl_JOIN_INNER_TD_21828706_output.getInt32(i, 0);
            int32_t _i_class_id3601 = tbl_JOIN_INNER_TD_21828706_output.getInt32(i, 1);
            int32_t _i_category_id3603 = tbl_JOIN_INNER_TD_21828706_output.getInt32(i, 2);
            SW_JOIN_LEFTSEMI_TD_20691722_payload_rightMajor payloadA{_i_brand_id3599, _i_class_id3601, _i_category_id3603};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_brand_id3577_k = tbl_Filter_TD_21245151_output.getInt32(i, 1);
            int32_t _i_class_id3579_k = tbl_Filter_TD_21245151_output.getInt32(i, 2);
            int32_t _i_category_id3581_k = tbl_Filter_TD_21245151_output.getInt32(i, 3);
            auto it = ht1.find(SW_JOIN_LEFTSEMI_TD_20691722_key_rightMajor{_i_brand_id3577_k, _i_class_id3579_k, _i_category_id3581_k});
            if (it != ht1.end()) {
                int32_t _i_item_sk3570 = tbl_Filter_TD_21245151_output.getInt32(i, 0);
                int32_t _i_brand_id3577 = tbl_Filter_TD_21245151_output.getInt32(i, 1);
                int32_t _i_class_id3579 = tbl_Filter_TD_21245151_output.getInt32(i, 2);
                int32_t _i_category_id3581 = tbl_Filter_TD_21245151_output.getInt32(i, 3);
                tbl_JOIN_LEFTSEMI_TD_20691722_output.setInt32(r, 0, _i_item_sk3570);
                tbl_JOIN_LEFTSEMI_TD_20691722_output.setInt32(r, 1, _i_brand_id3577);
                tbl_JOIN_LEFTSEMI_TD_20691722_output.setInt32(r, 2, _i_class_id3579);
                tbl_JOIN_LEFTSEMI_TD_20691722_output.setInt32(r, 3, _i_category_id3581);
                r++;
            }
        }
        tbl_JOIN_LEFTSEMI_TD_20691722_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTSEMI_TD_20691722_output #Row: " << tbl_JOIN_LEFTSEMI_TD_20691722_output.getNumRow() << std::endl;
}

void SW_Filter_TD_20407832(Table &tbl_SerializeFromObject_TD_2130558_input, Table &tbl_Filter_TD_20407832_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_item_sk#1208) AND isnotnull(ss_sold_date_sk#1206)))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_2130558_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_2130558_input.getInt32(i, 1);
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_2130558_input.getInt32(i, 0);
        if ((_ss_item_sk1208!= 0) && (_ss_sold_date_sk1206!= 0)) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_2130558_input.getInt32(i, 0);
            tbl_Filter_TD_20407832_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_2130558_input.getInt32(i, 1);
            tbl_Filter_TD_20407832_output.setInt32(r, 1, _ss_item_sk1208_t);
            r++;
        }
    }
    tbl_Filter_TD_20407832_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_20407832_output #Row: " << tbl_Filter_TD_20407832_output.getNumRow() << std::endl;
}

void SW_Filter_TD_19760561(Table &tbl_SerializeFromObject_TD_20885820_input, Table &tbl_Filter_TD_19760561_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#126) AND ((d_year#126 >= 1999) AND (d_year#126 <= 2001))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_20885820_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_20885820_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_20885820_input.getInt32(i, 0);
        if (((_d_year126!= 0) && ((_d_year126 >= 1999) && (_d_year126 <= 2001))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_20885820_input.getInt32(i, 0);
            tbl_Filter_TD_19760561_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_19760561_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_19760561_output #Row: " << tbl_Filter_TD_19760561_output.getNumRow() << std::endl;
}


void SW_Filter_TD_19411522(Table &tbl_SerializeFromObject_TD_20528877_input, Table &tbl_Filter_TD_19411522_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#126) AND ((d_year#126 >= 1999) AND (d_year#126 <= 2001))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_20528877_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_20528877_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_20528877_input.getInt32(i, 0);
        if (((_d_year126!= 0) && ((_d_year126 >= 1999) && (_d_year126 <= 2001))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_20528877_input.getInt32(i, 0);
            tbl_Filter_TD_19411522_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_19411522_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_19411522_output #Row: " << tbl_Filter_TD_19411522_output.getNumRow() << std::endl;
}


void SW_Filter_TD_19678522(Table &tbl_SerializeFromObject_TD_20532517_input, Table &tbl_Filter_TD_19678522_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#126) AND ((d_year#126 >= 1999) AND (d_year#126 <= 2001))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_20532517_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_20532517_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_20532517_input.getInt32(i, 0);
        if (((_d_year126!= 0) && ((_d_year126 >= 1999) && (_d_year126 <= 2001))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_20532517_input.getInt32(i, 0);
            tbl_Filter_TD_19678522_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_19678522_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_19678522_output #Row: " << tbl_Filter_TD_19678522_output.getNumRow() << std::endl;
}


void SW_Filter_TD_19242098(Table &tbl_SerializeFromObject_TD_20859528_input, Table &tbl_Filter_TD_19242098_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#126) AND ((d_year#126 >= 1999) AND (d_year#126 <= 2001))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_20859528_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_20859528_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_20859528_input.getInt32(i, 0);
        if (((_d_year126!= 0) && ((_d_year126 >= 1999) && (_d_year126 <= 2001))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_20859528_input.getInt32(i, 0);
            tbl_Filter_TD_19242098_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_19242098_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_19242098_output #Row: " << tbl_Filter_TD_19242098_output.getNumRow() << std::endl;
}


void SW_Filter_TD_19499063(Table &tbl_SerializeFromObject_TD_20414810_input, Table &tbl_Filter_TD_19499063_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#126) AND ((d_year#126 >= 1999) AND (d_year#126 <= 2001))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_20414810_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_20414810_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_20414810_input.getInt32(i, 0);
        if (((_d_year126!= 0) && ((_d_year126 >= 1999) && (_d_year126 <= 2001))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_20414810_input.getInt32(i, 0);
            tbl_Filter_TD_19499063_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_19499063_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_19499063_output #Row: " << tbl_Filter_TD_19499063_output.getNumRow() << std::endl;
}


void SW_Filter_TD_1916763(Table &tbl_SerializeFromObject_TD_20851208_input, Table &tbl_Filter_TD_1916763_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#126) AND ((d_year#126 >= 1999) AND (d_year#126 <= 2001))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_20851208_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_20851208_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_20851208_input.getInt32(i, 0);
        if (((_d_year126!= 0) && ((_d_year126 >= 1999) && (_d_year126 <= 2001))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_20851208_input.getInt32(i, 0);
            tbl_Filter_TD_1916763_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_1916763_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1916763_output #Row: " << tbl_Filter_TD_1916763_output.getNumRow() << std::endl;
}


void SW_Filter_TD_18236759(Table &tbl_SerializeFromObject_TD_19598746_input, Table &tbl_Filter_TD_18236759_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#3642))
    // Input: ListBuffer(i_item_sk#3642, i_brand_id#3649, i_class_id#3651, i_category_id#3653)
    // Output: ListBuffer(i_item_sk#3642, i_brand_id#3649, i_class_id#3651, i_category_id#3653)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_19598746_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk3642 = tbl_SerializeFromObject_TD_19598746_input.getInt32(i, 0);
        if (_i_item_sk3642!= 0) {
            int32_t _i_item_sk3642_t = tbl_SerializeFromObject_TD_19598746_input.getInt32(i, 0);
            tbl_Filter_TD_18236759_output.setInt32(r, 0, _i_item_sk3642_t);
            int32_t _i_brand_id3649_t = tbl_SerializeFromObject_TD_19598746_input.getInt32(i, 1);
            tbl_Filter_TD_18236759_output.setInt32(r, 1, _i_brand_id3649_t);
            int32_t _i_class_id3651_t = tbl_SerializeFromObject_TD_19598746_input.getInt32(i, 2);
            tbl_Filter_TD_18236759_output.setInt32(r, 2, _i_class_id3651_t);
            int32_t _i_category_id3653_t = tbl_SerializeFromObject_TD_19598746_input.getInt32(i, 3);
            tbl_Filter_TD_18236759_output.setInt32(r, 3, _i_category_id3653_t);
            r++;
        }
    }
    tbl_Filter_TD_18236759_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_18236759_output #Row: " << tbl_Filter_TD_18236759_output.getNumRow() << std::endl;
}

void SW_Filter_TD_18210056(Table &tbl_SerializeFromObject_TD_19140662_input, Table &tbl_Filter_TD_18210056_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_item_sk#732) AND isnotnull(ws_sold_date_sk#729)))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_19140662_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_item_sk732 = tbl_SerializeFromObject_TD_19140662_input.getInt32(i, 1);
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_19140662_input.getInt32(i, 0);
        if ((_ws_item_sk732!= 0) && (_ws_sold_date_sk729!= 0)) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_19140662_input.getInt32(i, 0);
            tbl_Filter_TD_18210056_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_item_sk732_t = tbl_SerializeFromObject_TD_19140662_input.getInt32(i, 1);
            tbl_Filter_TD_18210056_output.setInt32(r, 1, _ws_item_sk732_t);
            r++;
        }
    }
    tbl_Filter_TD_18210056_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_18210056_output #Row: " << tbl_Filter_TD_18210056_output.getNumRow() << std::endl;
}


void SW_Filter_TD_18159057(Table &tbl_SerializeFromObject_TD_19676025_input, Table &tbl_Filter_TD_18159057_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#3642))
    // Input: ListBuffer(i_item_sk#3642, i_brand_id#3649, i_class_id#3651, i_category_id#3653)
    // Output: ListBuffer(i_item_sk#3642, i_brand_id#3649, i_class_id#3651, i_category_id#3653)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_19676025_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk3642 = tbl_SerializeFromObject_TD_19676025_input.getInt32(i, 0);
        if (_i_item_sk3642!= 0) {
            int32_t _i_item_sk3642_t = tbl_SerializeFromObject_TD_19676025_input.getInt32(i, 0);
            tbl_Filter_TD_18159057_output.setInt32(r, 0, _i_item_sk3642_t);
            int32_t _i_brand_id3649_t = tbl_SerializeFromObject_TD_19676025_input.getInt32(i, 1);
            tbl_Filter_TD_18159057_output.setInt32(r, 1, _i_brand_id3649_t);
            int32_t _i_class_id3651_t = tbl_SerializeFromObject_TD_19676025_input.getInt32(i, 2);
            tbl_Filter_TD_18159057_output.setInt32(r, 2, _i_class_id3651_t);
            int32_t _i_category_id3653_t = tbl_SerializeFromObject_TD_19676025_input.getInt32(i, 3);
            tbl_Filter_TD_18159057_output.setInt32(r, 3, _i_category_id3653_t);
            r++;
        }
    }
    tbl_Filter_TD_18159057_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_18159057_output #Row: " << tbl_Filter_TD_18159057_output.getNumRow() << std::endl;
}

void SW_Filter_TD_18366123(Table &tbl_SerializeFromObject_TD_19269409_input, Table &tbl_Filter_TD_18366123_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_item_sk#732) AND isnotnull(ws_sold_date_sk#729)))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_19269409_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_item_sk732 = tbl_SerializeFromObject_TD_19269409_input.getInt32(i, 1);
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_19269409_input.getInt32(i, 0);
        if ((_ws_item_sk732!= 0) && (_ws_sold_date_sk729!= 0)) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_19269409_input.getInt32(i, 0);
            tbl_Filter_TD_18366123_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_item_sk732_t = tbl_SerializeFromObject_TD_19269409_input.getInt32(i, 1);
            tbl_Filter_TD_18366123_output.setInt32(r, 1, _ws_item_sk732_t);
            r++;
        }
    }
    tbl_Filter_TD_18366123_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_18366123_output #Row: " << tbl_Filter_TD_18366123_output.getNumRow() << std::endl;
}


void SW_Filter_TD_18622677(Table &tbl_SerializeFromObject_TD_1951940_input, Table &tbl_Filter_TD_18622677_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#3642))
    // Input: ListBuffer(i_item_sk#3642, i_brand_id#3649, i_class_id#3651, i_category_id#3653)
    // Output: ListBuffer(i_item_sk#3642, i_brand_id#3649, i_class_id#3651, i_category_id#3653)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1951940_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk3642 = tbl_SerializeFromObject_TD_1951940_input.getInt32(i, 0);
        if (_i_item_sk3642!= 0) {
            int32_t _i_item_sk3642_t = tbl_SerializeFromObject_TD_1951940_input.getInt32(i, 0);
            tbl_Filter_TD_18622677_output.setInt32(r, 0, _i_item_sk3642_t);
            int32_t _i_brand_id3649_t = tbl_SerializeFromObject_TD_1951940_input.getInt32(i, 1);
            tbl_Filter_TD_18622677_output.setInt32(r, 1, _i_brand_id3649_t);
            int32_t _i_class_id3651_t = tbl_SerializeFromObject_TD_1951940_input.getInt32(i, 2);
            tbl_Filter_TD_18622677_output.setInt32(r, 2, _i_class_id3651_t);
            int32_t _i_category_id3653_t = tbl_SerializeFromObject_TD_1951940_input.getInt32(i, 3);
            tbl_Filter_TD_18622677_output.setInt32(r, 3, _i_category_id3653_t);
            r++;
        }
    }
    tbl_Filter_TD_18622677_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_18622677_output #Row: " << tbl_Filter_TD_18622677_output.getNumRow() << std::endl;
}

void SW_Filter_TD_18928901(Table &tbl_SerializeFromObject_TD_1935011_input, Table &tbl_Filter_TD_18928901_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_item_sk#732) AND isnotnull(ws_sold_date_sk#729)))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1935011_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_item_sk732 = tbl_SerializeFromObject_TD_1935011_input.getInt32(i, 1);
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_1935011_input.getInt32(i, 0);
        if ((_ws_item_sk732!= 0) && (_ws_sold_date_sk729!= 0)) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_1935011_input.getInt32(i, 0);
            tbl_Filter_TD_18928901_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_item_sk732_t = tbl_SerializeFromObject_TD_1935011_input.getInt32(i, 1);
            tbl_Filter_TD_18928901_output.setInt32(r, 1, _ws_item_sk732_t);
            r++;
        }
    }
    tbl_Filter_TD_18928901_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_18928901_output #Row: " << tbl_Filter_TD_18928901_output.getNumRow() << std::endl;
}


void SW_Filter_TD_18747642(Table &tbl_SerializeFromObject_TD_19152934_input, Table &tbl_Filter_TD_18747642_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#3642))
    // Input: ListBuffer(i_item_sk#3642, i_brand_id#3649, i_class_id#3651, i_category_id#3653)
    // Output: ListBuffer(i_item_sk#3642, i_brand_id#3649, i_class_id#3651, i_category_id#3653)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_19152934_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk3642 = tbl_SerializeFromObject_TD_19152934_input.getInt32(i, 0);
        if (_i_item_sk3642!= 0) {
            int32_t _i_item_sk3642_t = tbl_SerializeFromObject_TD_19152934_input.getInt32(i, 0);
            tbl_Filter_TD_18747642_output.setInt32(r, 0, _i_item_sk3642_t);
            int32_t _i_brand_id3649_t = tbl_SerializeFromObject_TD_19152934_input.getInt32(i, 1);
            tbl_Filter_TD_18747642_output.setInt32(r, 1, _i_brand_id3649_t);
            int32_t _i_class_id3651_t = tbl_SerializeFromObject_TD_19152934_input.getInt32(i, 2);
            tbl_Filter_TD_18747642_output.setInt32(r, 2, _i_class_id3651_t);
            int32_t _i_category_id3653_t = tbl_SerializeFromObject_TD_19152934_input.getInt32(i, 3);
            tbl_Filter_TD_18747642_output.setInt32(r, 3, _i_category_id3653_t);
            r++;
        }
    }
    tbl_Filter_TD_18747642_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_18747642_output #Row: " << tbl_Filter_TD_18747642_output.getNumRow() << std::endl;
}

void SW_Filter_TD_18422323(Table &tbl_SerializeFromObject_TD_19824818_input, Table &tbl_Filter_TD_18422323_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_item_sk#732) AND isnotnull(ws_sold_date_sk#729)))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_19824818_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_item_sk732 = tbl_SerializeFromObject_TD_19824818_input.getInt32(i, 1);
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_19824818_input.getInt32(i, 0);
        if ((_ws_item_sk732!= 0) && (_ws_sold_date_sk729!= 0)) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_19824818_input.getInt32(i, 0);
            tbl_Filter_TD_18422323_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_item_sk732_t = tbl_SerializeFromObject_TD_19824818_input.getInt32(i, 1);
            tbl_Filter_TD_18422323_output.setInt32(r, 1, _ws_item_sk732_t);
            r++;
        }
    }
    tbl_Filter_TD_18422323_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_18422323_output #Row: " << tbl_Filter_TD_18422323_output.getNumRow() << std::endl;
}


void SW_Filter_TD_18958911(Table &tbl_SerializeFromObject_TD_19639173_input, Table &tbl_Filter_TD_18958911_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#3642))
    // Input: ListBuffer(i_item_sk#3642, i_brand_id#3649, i_class_id#3651, i_category_id#3653)
    // Output: ListBuffer(i_item_sk#3642, i_brand_id#3649, i_class_id#3651, i_category_id#3653)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_19639173_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk3642 = tbl_SerializeFromObject_TD_19639173_input.getInt32(i, 0);
        if (_i_item_sk3642!= 0) {
            int32_t _i_item_sk3642_t = tbl_SerializeFromObject_TD_19639173_input.getInt32(i, 0);
            tbl_Filter_TD_18958911_output.setInt32(r, 0, _i_item_sk3642_t);
            int32_t _i_brand_id3649_t = tbl_SerializeFromObject_TD_19639173_input.getInt32(i, 1);
            tbl_Filter_TD_18958911_output.setInt32(r, 1, _i_brand_id3649_t);
            int32_t _i_class_id3651_t = tbl_SerializeFromObject_TD_19639173_input.getInt32(i, 2);
            tbl_Filter_TD_18958911_output.setInt32(r, 2, _i_class_id3651_t);
            int32_t _i_category_id3653_t = tbl_SerializeFromObject_TD_19639173_input.getInt32(i, 3);
            tbl_Filter_TD_18958911_output.setInt32(r, 3, _i_category_id3653_t);
            r++;
        }
    }
    tbl_Filter_TD_18958911_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_18958911_output #Row: " << tbl_Filter_TD_18958911_output.getNumRow() << std::endl;
}

void SW_Filter_TD_18539150(Table &tbl_SerializeFromObject_TD_19405845_input, Table &tbl_Filter_TD_18539150_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_item_sk#732) AND isnotnull(ws_sold_date_sk#729)))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_19405845_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_item_sk732 = tbl_SerializeFromObject_TD_19405845_input.getInt32(i, 1);
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_19405845_input.getInt32(i, 0);
        if ((_ws_item_sk732!= 0) && (_ws_sold_date_sk729!= 0)) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_19405845_input.getInt32(i, 0);
            tbl_Filter_TD_18539150_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_item_sk732_t = tbl_SerializeFromObject_TD_19405845_input.getInt32(i, 1);
            tbl_Filter_TD_18539150_output.setInt32(r, 1, _ws_item_sk732_t);
            r++;
        }
    }
    tbl_Filter_TD_18539150_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_18539150_output #Row: " << tbl_Filter_TD_18539150_output.getNumRow() << std::endl;
}


void SW_Filter_TD_18141982(Table &tbl_SerializeFromObject_TD_19664414_input, Table &tbl_Filter_TD_18141982_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#3642))
    // Input: ListBuffer(i_item_sk#3642, i_brand_id#3649, i_class_id#3651, i_category_id#3653)
    // Output: ListBuffer(i_item_sk#3642, i_brand_id#3649, i_class_id#3651, i_category_id#3653)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_19664414_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk3642 = tbl_SerializeFromObject_TD_19664414_input.getInt32(i, 0);
        if (_i_item_sk3642!= 0) {
            int32_t _i_item_sk3642_t = tbl_SerializeFromObject_TD_19664414_input.getInt32(i, 0);
            tbl_Filter_TD_18141982_output.setInt32(r, 0, _i_item_sk3642_t);
            int32_t _i_brand_id3649_t = tbl_SerializeFromObject_TD_19664414_input.getInt32(i, 1);
            tbl_Filter_TD_18141982_output.setInt32(r, 1, _i_brand_id3649_t);
            int32_t _i_class_id3651_t = tbl_SerializeFromObject_TD_19664414_input.getInt32(i, 2);
            tbl_Filter_TD_18141982_output.setInt32(r, 2, _i_class_id3651_t);
            int32_t _i_category_id3653_t = tbl_SerializeFromObject_TD_19664414_input.getInt32(i, 3);
            tbl_Filter_TD_18141982_output.setInt32(r, 3, _i_category_id3653_t);
            r++;
        }
    }
    tbl_Filter_TD_18141982_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_18141982_output #Row: " << tbl_Filter_TD_18141982_output.getNumRow() << std::endl;
}

void SW_Filter_TD_18315894(Table &tbl_SerializeFromObject_TD_19897474_input, Table &tbl_Filter_TD_18315894_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_item_sk#732) AND isnotnull(ws_sold_date_sk#729)))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_19897474_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_item_sk732 = tbl_SerializeFromObject_TD_19897474_input.getInt32(i, 1);
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_19897474_input.getInt32(i, 0);
        if ((_ws_item_sk732!= 0) && (_ws_sold_date_sk729!= 0)) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_19897474_input.getInt32(i, 0);
            tbl_Filter_TD_18315894_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_item_sk732_t = tbl_SerializeFromObject_TD_19897474_input.getInt32(i, 1);
            tbl_Filter_TD_18315894_output.setInt32(r, 1, _ws_item_sk732_t);
            r++;
        }
    }
    tbl_Filter_TD_18315894_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_18315894_output #Row: " << tbl_Filter_TD_18315894_output.getNumRow() << std::endl;
}


void SW_Filter_TD_1711206(Table &tbl_SerializeFromObject_TD_1880109_input, Table &tbl_Filter_TD_1711206_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3670) AND ((d_year#3670 >= 1999) AND (d_year#3670 <= 2001))) AND isnotnull(d_date_sk#3664)))
    // Input: ListBuffer(d_date_sk#3664, d_year#3670)
    // Output: ListBuffer(d_date_sk#3664)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1880109_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3670 = tbl_SerializeFromObject_TD_1880109_input.getInt32(i, 1);
        int32_t _d_date_sk3664 = tbl_SerializeFromObject_TD_1880109_input.getInt32(i, 0);
        if (((_d_year3670!= 0) && ((_d_year3670 >= 1999) && (_d_year3670 <= 2001))) && (_d_date_sk3664!= 0)) {
            int32_t _d_date_sk3664_t = tbl_SerializeFromObject_TD_1880109_input.getInt32(i, 0);
            tbl_Filter_TD_1711206_output.setInt32(r, 0, _d_date_sk3664_t);
            r++;
        }
    }
    tbl_Filter_TD_1711206_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1711206_output #Row: " << tbl_Filter_TD_1711206_output.getNumRow() << std::endl;
}


void SW_Project_TD_17699011(Table &tbl_JOIN_INNER_TD_18139123_output, Table &tbl_Project_TD_17699011_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(i_brand_id#3577 AS brand_id#3559, i_class_id#3579 AS class_id#3560, i_category_id#3581 AS category_id#3561)
    // Input: ListBuffer(i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    // Output: ListBuffer(brand_id#3559, class_id#3560, category_id#3561)
    int nrow1 = tbl_JOIN_INNER_TD_18139123_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_brand_id3577 = tbl_JOIN_INNER_TD_18139123_output.getInt32(i, 0);
        int32_t _i_class_id3579 = tbl_JOIN_INNER_TD_18139123_output.getInt32(i, 1);
        int32_t _i_category_id3581 = tbl_JOIN_INNER_TD_18139123_output.getInt32(i, 2);
        int32_t _brand_id3559 = _i_brand_id3577;
        tbl_Project_TD_17699011_output.setInt32(i, 0, _brand_id3559);
        int32_t _class_id3560 = _i_class_id3579;
        tbl_Project_TD_17699011_output.setInt32(i, 1, _class_id3560);
        int32_t _category_id3561 = _i_category_id3581;
        tbl_Project_TD_17699011_output.setInt32(i, 2, _category_id3561);
    }
    tbl_Project_TD_17699011_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_17699011_output #Row: " << tbl_Project_TD_17699011_output.getNumRow() << std::endl;
}

void SW_Filter_TD_1765439(Table &tbl_SerializeFromObject_TD_18350237_input, Table &tbl_Filter_TD_1765439_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3670) AND ((d_year#3670 >= 1999) AND (d_year#3670 <= 2001))) AND isnotnull(d_date_sk#3664)))
    // Input: ListBuffer(d_date_sk#3664, d_year#3670)
    // Output: ListBuffer(d_date_sk#3664)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_18350237_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3670 = tbl_SerializeFromObject_TD_18350237_input.getInt32(i, 1);
        int32_t _d_date_sk3664 = tbl_SerializeFromObject_TD_18350237_input.getInt32(i, 0);
        if (((_d_year3670!= 0) && ((_d_year3670 >= 1999) && (_d_year3670 <= 2001))) && (_d_date_sk3664!= 0)) {
            int32_t _d_date_sk3664_t = tbl_SerializeFromObject_TD_18350237_input.getInt32(i, 0);
            tbl_Filter_TD_1765439_output.setInt32(r, 0, _d_date_sk3664_t);
            r++;
        }
    }
    tbl_Filter_TD_1765439_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1765439_output #Row: " << tbl_Filter_TD_1765439_output.getNumRow() << std::endl;
}


void SW_Project_TD_17261037(Table &tbl_JOIN_INNER_TD_18655864_output, Table &tbl_Project_TD_17261037_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(i_brand_id#3577 AS brand_id#3559, i_class_id#3579 AS class_id#3560, i_category_id#3581 AS category_id#3561)
    // Input: ListBuffer(i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    // Output: ListBuffer(brand_id#3559, class_id#3560, category_id#3561)
    int nrow1 = tbl_JOIN_INNER_TD_18655864_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_brand_id3577 = tbl_JOIN_INNER_TD_18655864_output.getInt32(i, 0);
        int32_t _i_class_id3579 = tbl_JOIN_INNER_TD_18655864_output.getInt32(i, 1);
        int32_t _i_category_id3581 = tbl_JOIN_INNER_TD_18655864_output.getInt32(i, 2);
        int32_t _brand_id3559 = _i_brand_id3577;
        tbl_Project_TD_17261037_output.setInt32(i, 0, _brand_id3559);
        int32_t _class_id3560 = _i_class_id3579;
        tbl_Project_TD_17261037_output.setInt32(i, 1, _class_id3560);
        int32_t _category_id3561 = _i_category_id3581;
        tbl_Project_TD_17261037_output.setInt32(i, 2, _category_id3561);
    }
    tbl_Project_TD_17261037_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_17261037_output #Row: " << tbl_Project_TD_17261037_output.getNumRow() << std::endl;
}

void SW_Filter_TD_17279511(Table &tbl_SerializeFromObject_TD_18747302_input, Table &tbl_Filter_TD_17279511_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3670) AND ((d_year#3670 >= 1999) AND (d_year#3670 <= 2001))) AND isnotnull(d_date_sk#3664)))
    // Input: ListBuffer(d_date_sk#3664, d_year#3670)
    // Output: ListBuffer(d_date_sk#3664)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_18747302_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3670 = tbl_SerializeFromObject_TD_18747302_input.getInt32(i, 1);
        int32_t _d_date_sk3664 = tbl_SerializeFromObject_TD_18747302_input.getInt32(i, 0);
        if (((_d_year3670!= 0) && ((_d_year3670 >= 1999) && (_d_year3670 <= 2001))) && (_d_date_sk3664!= 0)) {
            int32_t _d_date_sk3664_t = tbl_SerializeFromObject_TD_18747302_input.getInt32(i, 0);
            tbl_Filter_TD_17279511_output.setInt32(r, 0, _d_date_sk3664_t);
            r++;
        }
    }
    tbl_Filter_TD_17279511_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_17279511_output #Row: " << tbl_Filter_TD_17279511_output.getNumRow() << std::endl;
}


void SW_Project_TD_17756468(Table &tbl_JOIN_INNER_TD_18444991_output, Table &tbl_Project_TD_17756468_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(i_brand_id#3577 AS brand_id#3559, i_class_id#3579 AS class_id#3560, i_category_id#3581 AS category_id#3561)
    // Input: ListBuffer(i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    // Output: ListBuffer(brand_id#3559, class_id#3560, category_id#3561)
    int nrow1 = tbl_JOIN_INNER_TD_18444991_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_brand_id3577 = tbl_JOIN_INNER_TD_18444991_output.getInt32(i, 0);
        int32_t _i_class_id3579 = tbl_JOIN_INNER_TD_18444991_output.getInt32(i, 1);
        int32_t _i_category_id3581 = tbl_JOIN_INNER_TD_18444991_output.getInt32(i, 2);
        int32_t _brand_id3559 = _i_brand_id3577;
        tbl_Project_TD_17756468_output.setInt32(i, 0, _brand_id3559);
        int32_t _class_id3560 = _i_class_id3579;
        tbl_Project_TD_17756468_output.setInt32(i, 1, _class_id3560);
        int32_t _category_id3561 = _i_category_id3581;
        tbl_Project_TD_17756468_output.setInt32(i, 2, _category_id3561);
    }
    tbl_Project_TD_17756468_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_17756468_output #Row: " << tbl_Project_TD_17756468_output.getNumRow() << std::endl;
}

void SW_Filter_TD_17152018(Table &tbl_SerializeFromObject_TD_18188928_input, Table &tbl_Filter_TD_17152018_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3670) AND ((d_year#3670 >= 1999) AND (d_year#3670 <= 2001))) AND isnotnull(d_date_sk#3664)))
    // Input: ListBuffer(d_date_sk#3664, d_year#3670)
    // Output: ListBuffer(d_date_sk#3664)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_18188928_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3670 = tbl_SerializeFromObject_TD_18188928_input.getInt32(i, 1);
        int32_t _d_date_sk3664 = tbl_SerializeFromObject_TD_18188928_input.getInt32(i, 0);
        if (((_d_year3670!= 0) && ((_d_year3670 >= 1999) && (_d_year3670 <= 2001))) && (_d_date_sk3664!= 0)) {
            int32_t _d_date_sk3664_t = tbl_SerializeFromObject_TD_18188928_input.getInt32(i, 0);
            tbl_Filter_TD_17152018_output.setInt32(r, 0, _d_date_sk3664_t);
            r++;
        }
    }
    tbl_Filter_TD_17152018_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_17152018_output #Row: " << tbl_Filter_TD_17152018_output.getNumRow() << std::endl;
}


void SW_Project_TD_172220(Table &tbl_JOIN_INNER_TD_18545866_output, Table &tbl_Project_TD_172220_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(i_brand_id#3577 AS brand_id#3559, i_class_id#3579 AS class_id#3560, i_category_id#3581 AS category_id#3561)
    // Input: ListBuffer(i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    // Output: ListBuffer(brand_id#3559, class_id#3560, category_id#3561)
    int nrow1 = tbl_JOIN_INNER_TD_18545866_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_brand_id3577 = tbl_JOIN_INNER_TD_18545866_output.getInt32(i, 0);
        int32_t _i_class_id3579 = tbl_JOIN_INNER_TD_18545866_output.getInt32(i, 1);
        int32_t _i_category_id3581 = tbl_JOIN_INNER_TD_18545866_output.getInt32(i, 2);
        int32_t _brand_id3559 = _i_brand_id3577;
        tbl_Project_TD_172220_output.setInt32(i, 0, _brand_id3559);
        int32_t _class_id3560 = _i_class_id3579;
        tbl_Project_TD_172220_output.setInt32(i, 1, _class_id3560);
        int32_t _category_id3561 = _i_category_id3581;
        tbl_Project_TD_172220_output.setInt32(i, 2, _category_id3561);
    }
    tbl_Project_TD_172220_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_172220_output #Row: " << tbl_Project_TD_172220_output.getNumRow() << std::endl;
}

void SW_Filter_TD_17427123(Table &tbl_SerializeFromObject_TD_1862858_input, Table &tbl_Filter_TD_17427123_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3670) AND ((d_year#3670 >= 1999) AND (d_year#3670 <= 2001))) AND isnotnull(d_date_sk#3664)))
    // Input: ListBuffer(d_date_sk#3664, d_year#3670)
    // Output: ListBuffer(d_date_sk#3664)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1862858_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3670 = tbl_SerializeFromObject_TD_1862858_input.getInt32(i, 1);
        int32_t _d_date_sk3664 = tbl_SerializeFromObject_TD_1862858_input.getInt32(i, 0);
        if (((_d_year3670!= 0) && ((_d_year3670 >= 1999) && (_d_year3670 <= 2001))) && (_d_date_sk3664!= 0)) {
            int32_t _d_date_sk3664_t = tbl_SerializeFromObject_TD_1862858_input.getInt32(i, 0);
            tbl_Filter_TD_17427123_output.setInt32(r, 0, _d_date_sk3664_t);
            r++;
        }
    }
    tbl_Filter_TD_17427123_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_17427123_output #Row: " << tbl_Filter_TD_17427123_output.getNumRow() << std::endl;
}


void SW_Project_TD_17892184(Table &tbl_JOIN_INNER_TD_18427104_output, Table &tbl_Project_TD_17892184_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(i_brand_id#3577 AS brand_id#3559, i_class_id#3579 AS class_id#3560, i_category_id#3581 AS category_id#3561)
    // Input: ListBuffer(i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    // Output: ListBuffer(brand_id#3559, class_id#3560, category_id#3561)
    int nrow1 = tbl_JOIN_INNER_TD_18427104_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_brand_id3577 = tbl_JOIN_INNER_TD_18427104_output.getInt32(i, 0);
        int32_t _i_class_id3579 = tbl_JOIN_INNER_TD_18427104_output.getInt32(i, 1);
        int32_t _i_category_id3581 = tbl_JOIN_INNER_TD_18427104_output.getInt32(i, 2);
        int32_t _brand_id3559 = _i_brand_id3577;
        tbl_Project_TD_17892184_output.setInt32(i, 0, _brand_id3559);
        int32_t _class_id3560 = _i_class_id3579;
        tbl_Project_TD_17892184_output.setInt32(i, 1, _class_id3560);
        int32_t _category_id3561 = _i_category_id3581;
        tbl_Project_TD_17892184_output.setInt32(i, 2, _category_id3561);
    }
    tbl_Project_TD_17892184_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_17892184_output #Row: " << tbl_Project_TD_17892184_output.getNumRow() << std::endl;
}

void SW_Filter_TD_17275840(Table &tbl_SerializeFromObject_TD_18771902_input, Table &tbl_Filter_TD_17275840_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3670) AND ((d_year#3670 >= 1999) AND (d_year#3670 <= 2001))) AND isnotnull(d_date_sk#3664)))
    // Input: ListBuffer(d_date_sk#3664, d_year#3670)
    // Output: ListBuffer(d_date_sk#3664)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_18771902_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3670 = tbl_SerializeFromObject_TD_18771902_input.getInt32(i, 1);
        int32_t _d_date_sk3664 = tbl_SerializeFromObject_TD_18771902_input.getInt32(i, 0);
        if (((_d_year3670!= 0) && ((_d_year3670 >= 1999) && (_d_year3670 <= 2001))) && (_d_date_sk3664!= 0)) {
            int32_t _d_date_sk3664_t = tbl_SerializeFromObject_TD_18771902_input.getInt32(i, 0);
            tbl_Filter_TD_17275840_output.setInt32(r, 0, _d_date_sk3664_t);
            r++;
        }
    }
    tbl_Filter_TD_17275840_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_17275840_output #Row: " << tbl_Filter_TD_17275840_output.getNumRow() << std::endl;
}


void SW_Project_TD_17766216(Table &tbl_JOIN_INNER_TD_18358162_output, Table &tbl_Project_TD_17766216_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(i_brand_id#3577 AS brand_id#3559, i_class_id#3579 AS class_id#3560, i_category_id#3581 AS category_id#3561)
    // Input: ListBuffer(i_brand_id#3577, i_class_id#3579, i_category_id#3581)
    // Output: ListBuffer(brand_id#3559, class_id#3560, category_id#3561)
    int nrow1 = tbl_JOIN_INNER_TD_18358162_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_brand_id3577 = tbl_JOIN_INNER_TD_18358162_output.getInt32(i, 0);
        int32_t _i_class_id3579 = tbl_JOIN_INNER_TD_18358162_output.getInt32(i, 1);
        int32_t _i_category_id3581 = tbl_JOIN_INNER_TD_18358162_output.getInt32(i, 2);
        int32_t _brand_id3559 = _i_brand_id3577;
        tbl_Project_TD_17766216_output.setInt32(i, 0, _brand_id3559);
        int32_t _class_id3560 = _i_class_id3579;
        tbl_Project_TD_17766216_output.setInt32(i, 1, _class_id3560);
        int32_t _category_id3561 = _i_category_id3581;
        tbl_Project_TD_17766216_output.setInt32(i, 2, _category_id3561);
    }
    tbl_Project_TD_17766216_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_17766216_output #Row: " << tbl_Project_TD_17766216_output.getNumRow() << std::endl;
}


void SW_Aggregate_TD_16229259_consolidate(Table &tbl_Aggregate_TD_16229259_output_preprocess, Table &tbl_Aggregate_TD_16229259_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_16229259_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _brand_id3559 = tbl_Aggregate_TD_16229259_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_16229259_output.setInt32(r, 0, _brand_id3559);
        int32_t _class_id3560 = tbl_Aggregate_TD_16229259_output_preprocess.getInt32(r, 6);
        tbl_Aggregate_TD_16229259_output.setInt32(r, 1, _class_id3560);
        int32_t _category_id3561 = tbl_Aggregate_TD_16229259_output_preprocess.getInt32(r, 5);
        tbl_Aggregate_TD_16229259_output.setInt32(r, 2, _category_id3561);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_16229259_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_16229259_output #Row: " << tbl_Aggregate_TD_16229259_output.getNumRow() << std::endl;
}


void SW_Aggregate_TD_16101055_consolidate(Table &tbl_Aggregate_TD_16101055_output_preprocess, Table &tbl_Aggregate_TD_16101055_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_16101055_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _brand_id3559 = tbl_Aggregate_TD_16101055_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_16101055_output.setInt32(r, 0, _brand_id3559);
        int32_t _class_id3560 = tbl_Aggregate_TD_16101055_output_preprocess.getInt32(r, 6);
        tbl_Aggregate_TD_16101055_output.setInt32(r, 1, _class_id3560);
        int32_t _category_id3561 = tbl_Aggregate_TD_16101055_output_preprocess.getInt32(r, 5);
        tbl_Aggregate_TD_16101055_output.setInt32(r, 2, _category_id3561);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_16101055_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_16101055_output #Row: " << tbl_Aggregate_TD_16101055_output.getNumRow() << std::endl;
}


void SW_Aggregate_TD_16462930_consolidate(Table &tbl_Aggregate_TD_16462930_output_preprocess, Table &tbl_Aggregate_TD_16462930_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_16462930_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _brand_id3559 = tbl_Aggregate_TD_16462930_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_16462930_output.setInt32(r, 0, _brand_id3559);
        int32_t _class_id3560 = tbl_Aggregate_TD_16462930_output_preprocess.getInt32(r, 6);
        tbl_Aggregate_TD_16462930_output.setInt32(r, 1, _class_id3560);
        int32_t _category_id3561 = tbl_Aggregate_TD_16462930_output_preprocess.getInt32(r, 5);
        tbl_Aggregate_TD_16462930_output.setInt32(r, 2, _category_id3561);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_16462930_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_16462930_output #Row: " << tbl_Aggregate_TD_16462930_output.getNumRow() << std::endl;
}


void SW_Aggregate_TD_16175048_consolidate(Table &tbl_Aggregate_TD_16175048_output_preprocess, Table &tbl_Aggregate_TD_16175048_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_16175048_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _brand_id3559 = tbl_Aggregate_TD_16175048_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_16175048_output.setInt32(r, 0, _brand_id3559);
        int32_t _class_id3560 = tbl_Aggregate_TD_16175048_output_preprocess.getInt32(r, 6);
        tbl_Aggregate_TD_16175048_output.setInt32(r, 1, _class_id3560);
        int32_t _category_id3561 = tbl_Aggregate_TD_16175048_output_preprocess.getInt32(r, 5);
        tbl_Aggregate_TD_16175048_output.setInt32(r, 2, _category_id3561);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_16175048_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_16175048_output #Row: " << tbl_Aggregate_TD_16175048_output.getNumRow() << std::endl;
}


void SW_Aggregate_TD_16321961_consolidate(Table &tbl_Aggregate_TD_16321961_output_preprocess, Table &tbl_Aggregate_TD_16321961_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_16321961_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _brand_id3559 = tbl_Aggregate_TD_16321961_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_16321961_output.setInt32(r, 0, _brand_id3559);
        int32_t _class_id3560 = tbl_Aggregate_TD_16321961_output_preprocess.getInt32(r, 6);
        tbl_Aggregate_TD_16321961_output.setInt32(r, 1, _class_id3560);
        int32_t _category_id3561 = tbl_Aggregate_TD_16321961_output_preprocess.getInt32(r, 5);
        tbl_Aggregate_TD_16321961_output.setInt32(r, 2, _category_id3561);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_16321961_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_16321961_output #Row: " << tbl_Aggregate_TD_16321961_output.getNumRow() << std::endl;
}


void SW_Aggregate_TD_16766232_consolidate(Table &tbl_Aggregate_TD_16766232_output_preprocess, Table &tbl_Aggregate_TD_16766232_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_16766232_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _brand_id3559 = tbl_Aggregate_TD_16766232_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_16766232_output.setInt32(r, 0, _brand_id3559);
        int32_t _class_id3560 = tbl_Aggregate_TD_16766232_output_preprocess.getInt32(r, 6);
        tbl_Aggregate_TD_16766232_output.setInt32(r, 1, _class_id3560);
        int32_t _category_id3561 = tbl_Aggregate_TD_16766232_output_preprocess.getInt32(r, 5);
        tbl_Aggregate_TD_16766232_output.setInt32(r, 2, _category_id3561);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_16766232_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_16766232_output #Row: " << tbl_Aggregate_TD_16766232_output.getNumRow() << std::endl;
}

struct SW_JOIN_LEFTSEMI_TD_15479748_key_leftMajor {
    int32_t _brand_id3559;
    int32_t _class_id3560;
    int32_t _category_id3561;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_15479748_key_leftMajor& other) const {
        return ((_brand_id3559 == other._brand_id3559) && (_class_id3560 == other._class_id3560) && (_category_id3561 == other._category_id3561));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_15479748_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_15479748_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._brand_id3559)) + (hash<int32_t>()(k._class_id3560)) + (hash<int32_t>()(k._category_id3561));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_15479748_payload_leftMajor {
    int32_t _brand_id3559;
    int32_t _class_id3560;
    int32_t _category_id3561;
};
struct SW_JOIN_LEFTSEMI_TD_15479748_key_rightMajor {
    int32_t _i_brand_id3649;
    int32_t _i_class_id3651;
    int32_t _i_category_id3653;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_15479748_key_rightMajor& other) const {
        return ((_i_brand_id3649 == other._i_brand_id3649) && (_i_class_id3651 == other._i_class_id3651) && (_i_category_id3653 == other._i_category_id3653));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_15479748_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_15479748_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id3649)) + (hash<int32_t>()(k._i_class_id3651)) + (hash<int32_t>()(k._i_category_id3653));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_15479748_payload_rightMajor {
    int32_t _i_brand_id3649;
    int32_t _i_class_id3651;
    int32_t _i_category_id3653;
};
void SW_JOIN_LEFTSEMI_TD_15479748(Table &tbl_Aggregate_TD_16229259_output, Table &tbl_JOIN_INNER_TD_16535521_output, Table &tbl_JOIN_LEFTSEMI_TD_15479748_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTSEMI
    // Operation: ListBuffer((((brand_id#3559 <=> i_brand_id#3649) AND (class_id#3560 <=> i_class_id#3651)) AND (category_id#3561 <=> i_category_id#3653)))
    // Left Table: ListBuffer(brand_id#3559, class_id#3560, category_id#3561)
    // Right Table: ListBuffer(i_brand_id#3649, i_class_id#3651, i_category_id#3653)
    // Output Table: ListBuffer(brand_id#3559, class_id#3560, category_id#3561)
    int left_nrow = tbl_Aggregate_TD_16229259_output.getNumRow();
    int right_nrow = tbl_JOIN_INNER_TD_16535521_output.getNumRow();
        std::unordered_map<SW_JOIN_LEFTSEMI_TD_15479748_key_rightMajor, SW_JOIN_LEFTSEMI_TD_15479748_payload_rightMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_16535521_output.getNumRow();
        int nrow2 = tbl_Aggregate_TD_16229259_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_brand_id3649_k = tbl_JOIN_INNER_TD_16535521_output.getInt32(i, 0);
            int32_t _i_class_id3651_k = tbl_JOIN_INNER_TD_16535521_output.getInt32(i, 1);
            int32_t _i_category_id3653_k = tbl_JOIN_INNER_TD_16535521_output.getInt32(i, 2);
            SW_JOIN_LEFTSEMI_TD_15479748_key_rightMajor keyA{_i_brand_id3649_k, _i_class_id3651_k, _i_category_id3653_k};
            int32_t _i_brand_id3649 = tbl_JOIN_INNER_TD_16535521_output.getInt32(i, 0);
            int32_t _i_class_id3651 = tbl_JOIN_INNER_TD_16535521_output.getInt32(i, 1);
            int32_t _i_category_id3653 = tbl_JOIN_INNER_TD_16535521_output.getInt32(i, 2);
            SW_JOIN_LEFTSEMI_TD_15479748_payload_rightMajor payloadA{_i_brand_id3649, _i_class_id3651, _i_category_id3653};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        for (int i = 0; i < nrow2; i++) {
            int32_t _brand_id3559_k = tbl_Aggregate_TD_16229259_output.getInt32(i, 0);
            int32_t _class_id3560_k = tbl_Aggregate_TD_16229259_output.getInt32(i, 1);
            int32_t _category_id3561_k = tbl_Aggregate_TD_16229259_output.getInt32(i, 2);
            auto it = ht1.find(SW_JOIN_LEFTSEMI_TD_15479748_key_rightMajor{_brand_id3559_k, _class_id3560_k, _category_id3561_k});
            if (it != ht1.end()) {
                int32_t _brand_id3559 = tbl_Aggregate_TD_16229259_output.getInt32(i, 0);
                int32_t _class_id3560 = tbl_Aggregate_TD_16229259_output.getInt32(i, 1);
                int32_t _category_id3561 = tbl_Aggregate_TD_16229259_output.getInt32(i, 2);
                tbl_JOIN_LEFTSEMI_TD_15479748_output.setInt32(r, 0, _brand_id3559);
                tbl_JOIN_LEFTSEMI_TD_15479748_output.setInt32(r, 1, _class_id3560);
                tbl_JOIN_LEFTSEMI_TD_15479748_output.setInt32(r, 2, _category_id3561);
                r++;
            }
        }
        tbl_JOIN_LEFTSEMI_TD_15479748_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTSEMI_TD_15479748_output #Row: " << tbl_JOIN_LEFTSEMI_TD_15479748_output.getNumRow() << std::endl;
}

struct SW_JOIN_LEFTSEMI_TD_15252593_key_leftMajor {
    int32_t _brand_id3559;
    int32_t _class_id3560;
    int32_t _category_id3561;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_15252593_key_leftMajor& other) const {
        return ((_brand_id3559 == other._brand_id3559) && (_class_id3560 == other._class_id3560) && (_category_id3561 == other._category_id3561));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_15252593_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_15252593_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._brand_id3559)) + (hash<int32_t>()(k._class_id3560)) + (hash<int32_t>()(k._category_id3561));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_15252593_payload_leftMajor {
    int32_t _brand_id3559;
    int32_t _class_id3560;
    int32_t _category_id3561;
};
struct SW_JOIN_LEFTSEMI_TD_15252593_key_rightMajor {
    int32_t _i_brand_id3649;
    int32_t _i_class_id3651;
    int32_t _i_category_id3653;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_15252593_key_rightMajor& other) const {
        return ((_i_brand_id3649 == other._i_brand_id3649) && (_i_class_id3651 == other._i_class_id3651) && (_i_category_id3653 == other._i_category_id3653));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_15252593_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_15252593_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id3649)) + (hash<int32_t>()(k._i_class_id3651)) + (hash<int32_t>()(k._i_category_id3653));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_15252593_payload_rightMajor {
    int32_t _i_brand_id3649;
    int32_t _i_class_id3651;
    int32_t _i_category_id3653;
};
void SW_JOIN_LEFTSEMI_TD_15252593(Table &tbl_Aggregate_TD_16101055_output, Table &tbl_JOIN_INNER_TD_16750275_output, Table &tbl_JOIN_LEFTSEMI_TD_15252593_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTSEMI
    // Operation: ListBuffer((((brand_id#3559 <=> i_brand_id#3649) AND (class_id#3560 <=> i_class_id#3651)) AND (category_id#3561 <=> i_category_id#3653)))
    // Left Table: ListBuffer(brand_id#3559, class_id#3560, category_id#3561)
    // Right Table: ListBuffer(i_brand_id#3649, i_class_id#3651, i_category_id#3653)
    // Output Table: ListBuffer(brand_id#3559, class_id#3560, category_id#3561)
    int left_nrow = tbl_Aggregate_TD_16101055_output.getNumRow();
    int right_nrow = tbl_JOIN_INNER_TD_16750275_output.getNumRow();
        std::unordered_map<SW_JOIN_LEFTSEMI_TD_15252593_key_rightMajor, SW_JOIN_LEFTSEMI_TD_15252593_payload_rightMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_16750275_output.getNumRow();
        int nrow2 = tbl_Aggregate_TD_16101055_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_brand_id3649_k = tbl_JOIN_INNER_TD_16750275_output.getInt32(i, 0);
            int32_t _i_class_id3651_k = tbl_JOIN_INNER_TD_16750275_output.getInt32(i, 1);
            int32_t _i_category_id3653_k = tbl_JOIN_INNER_TD_16750275_output.getInt32(i, 2);
            SW_JOIN_LEFTSEMI_TD_15252593_key_rightMajor keyA{_i_brand_id3649_k, _i_class_id3651_k, _i_category_id3653_k};
            int32_t _i_brand_id3649 = tbl_JOIN_INNER_TD_16750275_output.getInt32(i, 0);
            int32_t _i_class_id3651 = tbl_JOIN_INNER_TD_16750275_output.getInt32(i, 1);
            int32_t _i_category_id3653 = tbl_JOIN_INNER_TD_16750275_output.getInt32(i, 2);
            SW_JOIN_LEFTSEMI_TD_15252593_payload_rightMajor payloadA{_i_brand_id3649, _i_class_id3651, _i_category_id3653};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        for (int i = 0; i < nrow2; i++) {
            int32_t _brand_id3559_k = tbl_Aggregate_TD_16101055_output.getInt32(i, 0);
            int32_t _class_id3560_k = tbl_Aggregate_TD_16101055_output.getInt32(i, 1);
            int32_t _category_id3561_k = tbl_Aggregate_TD_16101055_output.getInt32(i, 2);
            auto it = ht1.find(SW_JOIN_LEFTSEMI_TD_15252593_key_rightMajor{_brand_id3559_k, _class_id3560_k, _category_id3561_k});
            if (it != ht1.end()) {
                int32_t _brand_id3559 = tbl_Aggregate_TD_16101055_output.getInt32(i, 0);
                int32_t _class_id3560 = tbl_Aggregate_TD_16101055_output.getInt32(i, 1);
                int32_t _category_id3561 = tbl_Aggregate_TD_16101055_output.getInt32(i, 2);
                tbl_JOIN_LEFTSEMI_TD_15252593_output.setInt32(r, 0, _brand_id3559);
                tbl_JOIN_LEFTSEMI_TD_15252593_output.setInt32(r, 1, _class_id3560);
                tbl_JOIN_LEFTSEMI_TD_15252593_output.setInt32(r, 2, _category_id3561);
                r++;
            }
        }
        tbl_JOIN_LEFTSEMI_TD_15252593_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTSEMI_TD_15252593_output #Row: " << tbl_JOIN_LEFTSEMI_TD_15252593_output.getNumRow() << std::endl;
}

struct SW_JOIN_LEFTSEMI_TD_15585882_key_leftMajor {
    int32_t _brand_id3559;
    int32_t _class_id3560;
    int32_t _category_id3561;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_15585882_key_leftMajor& other) const {
        return ((_brand_id3559 == other._brand_id3559) && (_class_id3560 == other._class_id3560) && (_category_id3561 == other._category_id3561));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_15585882_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_15585882_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._brand_id3559)) + (hash<int32_t>()(k._class_id3560)) + (hash<int32_t>()(k._category_id3561));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_15585882_payload_leftMajor {
    int32_t _brand_id3559;
    int32_t _class_id3560;
    int32_t _category_id3561;
};
struct SW_JOIN_LEFTSEMI_TD_15585882_key_rightMajor {
    int32_t _i_brand_id3649;
    int32_t _i_class_id3651;
    int32_t _i_category_id3653;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_15585882_key_rightMajor& other) const {
        return ((_i_brand_id3649 == other._i_brand_id3649) && (_i_class_id3651 == other._i_class_id3651) && (_i_category_id3653 == other._i_category_id3653));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_15585882_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_15585882_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id3649)) + (hash<int32_t>()(k._i_class_id3651)) + (hash<int32_t>()(k._i_category_id3653));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_15585882_payload_rightMajor {
    int32_t _i_brand_id3649;
    int32_t _i_class_id3651;
    int32_t _i_category_id3653;
};
void SW_JOIN_LEFTSEMI_TD_15585882(Table &tbl_Aggregate_TD_16462930_output, Table &tbl_JOIN_INNER_TD_16836657_output, Table &tbl_JOIN_LEFTSEMI_TD_15585882_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTSEMI
    // Operation: ListBuffer((((brand_id#3559 <=> i_brand_id#3649) AND (class_id#3560 <=> i_class_id#3651)) AND (category_id#3561 <=> i_category_id#3653)))
    // Left Table: ListBuffer(brand_id#3559, class_id#3560, category_id#3561)
    // Right Table: ListBuffer(i_brand_id#3649, i_class_id#3651, i_category_id#3653)
    // Output Table: ListBuffer(brand_id#3559, class_id#3560, category_id#3561)
    int left_nrow = tbl_Aggregate_TD_16462930_output.getNumRow();
    int right_nrow = tbl_JOIN_INNER_TD_16836657_output.getNumRow();
        std::unordered_map<SW_JOIN_LEFTSEMI_TD_15585882_key_rightMajor, SW_JOIN_LEFTSEMI_TD_15585882_payload_rightMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_16836657_output.getNumRow();
        int nrow2 = tbl_Aggregate_TD_16462930_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_brand_id3649_k = tbl_JOIN_INNER_TD_16836657_output.getInt32(i, 0);
            int32_t _i_class_id3651_k = tbl_JOIN_INNER_TD_16836657_output.getInt32(i, 1);
            int32_t _i_category_id3653_k = tbl_JOIN_INNER_TD_16836657_output.getInt32(i, 2);
            SW_JOIN_LEFTSEMI_TD_15585882_key_rightMajor keyA{_i_brand_id3649_k, _i_class_id3651_k, _i_category_id3653_k};
            int32_t _i_brand_id3649 = tbl_JOIN_INNER_TD_16836657_output.getInt32(i, 0);
            int32_t _i_class_id3651 = tbl_JOIN_INNER_TD_16836657_output.getInt32(i, 1);
            int32_t _i_category_id3653 = tbl_JOIN_INNER_TD_16836657_output.getInt32(i, 2);
            SW_JOIN_LEFTSEMI_TD_15585882_payload_rightMajor payloadA{_i_brand_id3649, _i_class_id3651, _i_category_id3653};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        for (int i = 0; i < nrow2; i++) {
            int32_t _brand_id3559_k = tbl_Aggregate_TD_16462930_output.getInt32(i, 0);
            int32_t _class_id3560_k = tbl_Aggregate_TD_16462930_output.getInt32(i, 1);
            int32_t _category_id3561_k = tbl_Aggregate_TD_16462930_output.getInt32(i, 2);
            auto it = ht1.find(SW_JOIN_LEFTSEMI_TD_15585882_key_rightMajor{_brand_id3559_k, _class_id3560_k, _category_id3561_k});
            if (it != ht1.end()) {
                int32_t _brand_id3559 = tbl_Aggregate_TD_16462930_output.getInt32(i, 0);
                int32_t _class_id3560 = tbl_Aggregate_TD_16462930_output.getInt32(i, 1);
                int32_t _category_id3561 = tbl_Aggregate_TD_16462930_output.getInt32(i, 2);
                tbl_JOIN_LEFTSEMI_TD_15585882_output.setInt32(r, 0, _brand_id3559);
                tbl_JOIN_LEFTSEMI_TD_15585882_output.setInt32(r, 1, _class_id3560);
                tbl_JOIN_LEFTSEMI_TD_15585882_output.setInt32(r, 2, _category_id3561);
                r++;
            }
        }
        tbl_JOIN_LEFTSEMI_TD_15585882_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTSEMI_TD_15585882_output #Row: " << tbl_JOIN_LEFTSEMI_TD_15585882_output.getNumRow() << std::endl;
}

struct SW_JOIN_LEFTSEMI_TD_15882654_key_leftMajor {
    int32_t _brand_id3559;
    int32_t _class_id3560;
    int32_t _category_id3561;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_15882654_key_leftMajor& other) const {
        return ((_brand_id3559 == other._brand_id3559) && (_class_id3560 == other._class_id3560) && (_category_id3561 == other._category_id3561));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_15882654_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_15882654_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._brand_id3559)) + (hash<int32_t>()(k._class_id3560)) + (hash<int32_t>()(k._category_id3561));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_15882654_payload_leftMajor {
    int32_t _brand_id3559;
    int32_t _class_id3560;
    int32_t _category_id3561;
};
struct SW_JOIN_LEFTSEMI_TD_15882654_key_rightMajor {
    int32_t _i_brand_id3649;
    int32_t _i_class_id3651;
    int32_t _i_category_id3653;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_15882654_key_rightMajor& other) const {
        return ((_i_brand_id3649 == other._i_brand_id3649) && (_i_class_id3651 == other._i_class_id3651) && (_i_category_id3653 == other._i_category_id3653));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_15882654_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_15882654_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id3649)) + (hash<int32_t>()(k._i_class_id3651)) + (hash<int32_t>()(k._i_category_id3653));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_15882654_payload_rightMajor {
    int32_t _i_brand_id3649;
    int32_t _i_class_id3651;
    int32_t _i_category_id3653;
};
void SW_JOIN_LEFTSEMI_TD_15882654(Table &tbl_Aggregate_TD_16175048_output, Table &tbl_JOIN_INNER_TD_1658217_output, Table &tbl_JOIN_LEFTSEMI_TD_15882654_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTSEMI
    // Operation: ListBuffer((((brand_id#3559 <=> i_brand_id#3649) AND (class_id#3560 <=> i_class_id#3651)) AND (category_id#3561 <=> i_category_id#3653)))
    // Left Table: ListBuffer(brand_id#3559, class_id#3560, category_id#3561)
    // Right Table: ListBuffer(i_brand_id#3649, i_class_id#3651, i_category_id#3653)
    // Output Table: ListBuffer(brand_id#3559, class_id#3560, category_id#3561)
    int left_nrow = tbl_Aggregate_TD_16175048_output.getNumRow();
    int right_nrow = tbl_JOIN_INNER_TD_1658217_output.getNumRow();
        std::unordered_map<SW_JOIN_LEFTSEMI_TD_15882654_key_rightMajor, SW_JOIN_LEFTSEMI_TD_15882654_payload_rightMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_1658217_output.getNumRow();
        int nrow2 = tbl_Aggregate_TD_16175048_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_brand_id3649_k = tbl_JOIN_INNER_TD_1658217_output.getInt32(i, 0);
            int32_t _i_class_id3651_k = tbl_JOIN_INNER_TD_1658217_output.getInt32(i, 1);
            int32_t _i_category_id3653_k = tbl_JOIN_INNER_TD_1658217_output.getInt32(i, 2);
            SW_JOIN_LEFTSEMI_TD_15882654_key_rightMajor keyA{_i_brand_id3649_k, _i_class_id3651_k, _i_category_id3653_k};
            int32_t _i_brand_id3649 = tbl_JOIN_INNER_TD_1658217_output.getInt32(i, 0);
            int32_t _i_class_id3651 = tbl_JOIN_INNER_TD_1658217_output.getInt32(i, 1);
            int32_t _i_category_id3653 = tbl_JOIN_INNER_TD_1658217_output.getInt32(i, 2);
            SW_JOIN_LEFTSEMI_TD_15882654_payload_rightMajor payloadA{_i_brand_id3649, _i_class_id3651, _i_category_id3653};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        for (int i = 0; i < nrow2; i++) {
            int32_t _brand_id3559_k = tbl_Aggregate_TD_16175048_output.getInt32(i, 0);
            int32_t _class_id3560_k = tbl_Aggregate_TD_16175048_output.getInt32(i, 1);
            int32_t _category_id3561_k = tbl_Aggregate_TD_16175048_output.getInt32(i, 2);
            auto it = ht1.find(SW_JOIN_LEFTSEMI_TD_15882654_key_rightMajor{_brand_id3559_k, _class_id3560_k, _category_id3561_k});
            if (it != ht1.end()) {
                int32_t _brand_id3559 = tbl_Aggregate_TD_16175048_output.getInt32(i, 0);
                int32_t _class_id3560 = tbl_Aggregate_TD_16175048_output.getInt32(i, 1);
                int32_t _category_id3561 = tbl_Aggregate_TD_16175048_output.getInt32(i, 2);
                tbl_JOIN_LEFTSEMI_TD_15882654_output.setInt32(r, 0, _brand_id3559);
                tbl_JOIN_LEFTSEMI_TD_15882654_output.setInt32(r, 1, _class_id3560);
                tbl_JOIN_LEFTSEMI_TD_15882654_output.setInt32(r, 2, _category_id3561);
                r++;
            }
        }
        tbl_JOIN_LEFTSEMI_TD_15882654_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTSEMI_TD_15882654_output #Row: " << tbl_JOIN_LEFTSEMI_TD_15882654_output.getNumRow() << std::endl;
}

struct SW_JOIN_LEFTSEMI_TD_159523_key_leftMajor {
    int32_t _brand_id3559;
    int32_t _class_id3560;
    int32_t _category_id3561;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_159523_key_leftMajor& other) const {
        return ((_brand_id3559 == other._brand_id3559) && (_class_id3560 == other._class_id3560) && (_category_id3561 == other._category_id3561));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_159523_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_159523_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._brand_id3559)) + (hash<int32_t>()(k._class_id3560)) + (hash<int32_t>()(k._category_id3561));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_159523_payload_leftMajor {
    int32_t _brand_id3559;
    int32_t _class_id3560;
    int32_t _category_id3561;
};
struct SW_JOIN_LEFTSEMI_TD_159523_key_rightMajor {
    int32_t _i_brand_id3649;
    int32_t _i_class_id3651;
    int32_t _i_category_id3653;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_159523_key_rightMajor& other) const {
        return ((_i_brand_id3649 == other._i_brand_id3649) && (_i_class_id3651 == other._i_class_id3651) && (_i_category_id3653 == other._i_category_id3653));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_159523_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_159523_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id3649)) + (hash<int32_t>()(k._i_class_id3651)) + (hash<int32_t>()(k._i_category_id3653));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_159523_payload_rightMajor {
    int32_t _i_brand_id3649;
    int32_t _i_class_id3651;
    int32_t _i_category_id3653;
};
void SW_JOIN_LEFTSEMI_TD_159523(Table &tbl_Aggregate_TD_16321961_output, Table &tbl_JOIN_INNER_TD_16220267_output, Table &tbl_JOIN_LEFTSEMI_TD_159523_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTSEMI
    // Operation: ListBuffer((((brand_id#3559 <=> i_brand_id#3649) AND (class_id#3560 <=> i_class_id#3651)) AND (category_id#3561 <=> i_category_id#3653)))
    // Left Table: ListBuffer(brand_id#3559, class_id#3560, category_id#3561)
    // Right Table: ListBuffer(i_brand_id#3649, i_class_id#3651, i_category_id#3653)
    // Output Table: ListBuffer(brand_id#3559, class_id#3560, category_id#3561)
    int left_nrow = tbl_Aggregate_TD_16321961_output.getNumRow();
    int right_nrow = tbl_JOIN_INNER_TD_16220267_output.getNumRow();
        std::unordered_map<SW_JOIN_LEFTSEMI_TD_159523_key_rightMajor, SW_JOIN_LEFTSEMI_TD_159523_payload_rightMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_16220267_output.getNumRow();
        int nrow2 = tbl_Aggregate_TD_16321961_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_brand_id3649_k = tbl_JOIN_INNER_TD_16220267_output.getInt32(i, 0);
            int32_t _i_class_id3651_k = tbl_JOIN_INNER_TD_16220267_output.getInt32(i, 1);
            int32_t _i_category_id3653_k = tbl_JOIN_INNER_TD_16220267_output.getInt32(i, 2);
            SW_JOIN_LEFTSEMI_TD_159523_key_rightMajor keyA{_i_brand_id3649_k, _i_class_id3651_k, _i_category_id3653_k};
            int32_t _i_brand_id3649 = tbl_JOIN_INNER_TD_16220267_output.getInt32(i, 0);
            int32_t _i_class_id3651 = tbl_JOIN_INNER_TD_16220267_output.getInt32(i, 1);
            int32_t _i_category_id3653 = tbl_JOIN_INNER_TD_16220267_output.getInt32(i, 2);
            SW_JOIN_LEFTSEMI_TD_159523_payload_rightMajor payloadA{_i_brand_id3649, _i_class_id3651, _i_category_id3653};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        for (int i = 0; i < nrow2; i++) {
            int32_t _brand_id3559_k = tbl_Aggregate_TD_16321961_output.getInt32(i, 0);
            int32_t _class_id3560_k = tbl_Aggregate_TD_16321961_output.getInt32(i, 1);
            int32_t _category_id3561_k = tbl_Aggregate_TD_16321961_output.getInt32(i, 2);
            auto it = ht1.find(SW_JOIN_LEFTSEMI_TD_159523_key_rightMajor{_brand_id3559_k, _class_id3560_k, _category_id3561_k});
            if (it != ht1.end()) {
                int32_t _brand_id3559 = tbl_Aggregate_TD_16321961_output.getInt32(i, 0);
                int32_t _class_id3560 = tbl_Aggregate_TD_16321961_output.getInt32(i, 1);
                int32_t _category_id3561 = tbl_Aggregate_TD_16321961_output.getInt32(i, 2);
                tbl_JOIN_LEFTSEMI_TD_159523_output.setInt32(r, 0, _brand_id3559);
                tbl_JOIN_LEFTSEMI_TD_159523_output.setInt32(r, 1, _class_id3560);
                tbl_JOIN_LEFTSEMI_TD_159523_output.setInt32(r, 2, _category_id3561);
                r++;
            }
        }
        tbl_JOIN_LEFTSEMI_TD_159523_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTSEMI_TD_159523_output #Row: " << tbl_JOIN_LEFTSEMI_TD_159523_output.getNumRow() << std::endl;
}

struct SW_JOIN_LEFTSEMI_TD_15943669_key_leftMajor {
    int32_t _brand_id3559;
    int32_t _class_id3560;
    int32_t _category_id3561;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_15943669_key_leftMajor& other) const {
        return ((_brand_id3559 == other._brand_id3559) && (_class_id3560 == other._class_id3560) && (_category_id3561 == other._category_id3561));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_15943669_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_15943669_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._brand_id3559)) + (hash<int32_t>()(k._class_id3560)) + (hash<int32_t>()(k._category_id3561));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_15943669_payload_leftMajor {
    int32_t _brand_id3559;
    int32_t _class_id3560;
    int32_t _category_id3561;
};
struct SW_JOIN_LEFTSEMI_TD_15943669_key_rightMajor {
    int32_t _i_brand_id3649;
    int32_t _i_class_id3651;
    int32_t _i_category_id3653;
    bool operator==(const SW_JOIN_LEFTSEMI_TD_15943669_key_rightMajor& other) const {
        return ((_i_brand_id3649 == other._i_brand_id3649) && (_i_class_id3651 == other._i_class_id3651) && (_i_category_id3653 == other._i_category_id3653));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTSEMI_TD_15943669_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_LEFTSEMI_TD_15943669_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id3649)) + (hash<int32_t>()(k._i_class_id3651)) + (hash<int32_t>()(k._i_category_id3653));
    }
};
}
struct SW_JOIN_LEFTSEMI_TD_15943669_payload_rightMajor {
    int32_t _i_brand_id3649;
    int32_t _i_class_id3651;
    int32_t _i_category_id3653;
};
void SW_JOIN_LEFTSEMI_TD_15943669(Table &tbl_Aggregate_TD_16766232_output, Table &tbl_JOIN_INNER_TD_16204576_output, Table &tbl_JOIN_LEFTSEMI_TD_15943669_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTSEMI
    // Operation: ListBuffer((((brand_id#3559 <=> i_brand_id#3649) AND (class_id#3560 <=> i_class_id#3651)) AND (category_id#3561 <=> i_category_id#3653)))
    // Left Table: ListBuffer(brand_id#3559, class_id#3560, category_id#3561)
    // Right Table: ListBuffer(i_brand_id#3649, i_class_id#3651, i_category_id#3653)
    // Output Table: ListBuffer(brand_id#3559, class_id#3560, category_id#3561)
    int left_nrow = tbl_Aggregate_TD_16766232_output.getNumRow();
    int right_nrow = tbl_JOIN_INNER_TD_16204576_output.getNumRow();
        std::unordered_map<SW_JOIN_LEFTSEMI_TD_15943669_key_rightMajor, SW_JOIN_LEFTSEMI_TD_15943669_payload_rightMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_16204576_output.getNumRow();
        int nrow2 = tbl_Aggregate_TD_16766232_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_brand_id3649_k = tbl_JOIN_INNER_TD_16204576_output.getInt32(i, 0);
            int32_t _i_class_id3651_k = tbl_JOIN_INNER_TD_16204576_output.getInt32(i, 1);
            int32_t _i_category_id3653_k = tbl_JOIN_INNER_TD_16204576_output.getInt32(i, 2);
            SW_JOIN_LEFTSEMI_TD_15943669_key_rightMajor keyA{_i_brand_id3649_k, _i_class_id3651_k, _i_category_id3653_k};
            int32_t _i_brand_id3649 = tbl_JOIN_INNER_TD_16204576_output.getInt32(i, 0);
            int32_t _i_class_id3651 = tbl_JOIN_INNER_TD_16204576_output.getInt32(i, 1);
            int32_t _i_category_id3653 = tbl_JOIN_INNER_TD_16204576_output.getInt32(i, 2);
            SW_JOIN_LEFTSEMI_TD_15943669_payload_rightMajor payloadA{_i_brand_id3649, _i_class_id3651, _i_category_id3653};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        for (int i = 0; i < nrow2; i++) {
            int32_t _brand_id3559_k = tbl_Aggregate_TD_16766232_output.getInt32(i, 0);
            int32_t _class_id3560_k = tbl_Aggregate_TD_16766232_output.getInt32(i, 1);
            int32_t _category_id3561_k = tbl_Aggregate_TD_16766232_output.getInt32(i, 2);
            auto it = ht1.find(SW_JOIN_LEFTSEMI_TD_15943669_key_rightMajor{_brand_id3559_k, _class_id3560_k, _category_id3561_k});
            if (it != ht1.end()) {
                int32_t _brand_id3559 = tbl_Aggregate_TD_16766232_output.getInt32(i, 0);
                int32_t _class_id3560 = tbl_Aggregate_TD_16766232_output.getInt32(i, 1);
                int32_t _category_id3561 = tbl_Aggregate_TD_16766232_output.getInt32(i, 2);
                tbl_JOIN_LEFTSEMI_TD_15943669_output.setInt32(r, 0, _brand_id3559);
                tbl_JOIN_LEFTSEMI_TD_15943669_output.setInt32(r, 1, _class_id3560);
                tbl_JOIN_LEFTSEMI_TD_15943669_output.setInt32(r, 2, _category_id3561);
                r++;
            }
        }
        tbl_JOIN_LEFTSEMI_TD_15943669_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTSEMI_TD_15943669_output #Row: " << tbl_JOIN_LEFTSEMI_TD_15943669_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_14466509_consolidate(Table &tbl_Aggregate_TD_14466509_output_preprocess, Table &tbl_Aggregate_TD_14466509_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_14466509_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _brand_id3559 = tbl_Aggregate_TD_14466509_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_14466509_output.setInt32(r, 0, _brand_id3559);
        int32_t _class_id3560 = tbl_Aggregate_TD_14466509_output_preprocess.getInt32(r, 6);
        tbl_Aggregate_TD_14466509_output.setInt32(r, 1, _class_id3560);
        int32_t _category_id3561 = tbl_Aggregate_TD_14466509_output_preprocess.getInt32(r, 5);
        tbl_Aggregate_TD_14466509_output.setInt32(r, 2, _category_id3561);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_14466509_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_14466509_output #Row: " << tbl_Aggregate_TD_14466509_output.getNumRow() << std::endl;
}

void SW_Filter_TD_14522120(Table &tbl_SerializeFromObject_TD_15607458_input, Table &tbl_Filter_TD_14522120_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(i_brand_id#235) AND isnotnull(i_class_id#237)) AND isnotnull(i_category_id#239)))
    // Input: ListBuffer(i_item_sk#228, i_brand_id#235, i_class_id#237, i_category_id#239)
    // Output: ListBuffer(i_item_sk#228, i_brand_id#235, i_class_id#237, i_category_id#239)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_15607458_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_brand_id235 = tbl_SerializeFromObject_TD_15607458_input.getInt32(i, 1);
        int32_t _i_class_id237 = tbl_SerializeFromObject_TD_15607458_input.getInt32(i, 2);
        int32_t _i_category_id239 = tbl_SerializeFromObject_TD_15607458_input.getInt32(i, 3);
        if (((_i_brand_id235!= 0) && (_i_class_id237!= 0)) && (_i_category_id239!= 0)) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_15607458_input.getInt32(i, 0);
            tbl_Filter_TD_14522120_output.setInt32(r, 0, _i_item_sk228_t);
            int32_t _i_brand_id235_t = tbl_SerializeFromObject_TD_15607458_input.getInt32(i, 1);
            tbl_Filter_TD_14522120_output.setInt32(r, 1, _i_brand_id235_t);
            int32_t _i_class_id237_t = tbl_SerializeFromObject_TD_15607458_input.getInt32(i, 2);
            tbl_Filter_TD_14522120_output.setInt32(r, 2, _i_class_id237_t);
            int32_t _i_category_id239_t = tbl_SerializeFromObject_TD_15607458_input.getInt32(i, 3);
            tbl_Filter_TD_14522120_output.setInt32(r, 3, _i_category_id239_t);
            r++;
        }
    }
    tbl_Filter_TD_14522120_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_14522120_output #Row: " << tbl_Filter_TD_14522120_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_14777245_consolidate(Table &tbl_Aggregate_TD_14777245_output_preprocess, Table &tbl_Aggregate_TD_14777245_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_14777245_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _brand_id3559 = tbl_Aggregate_TD_14777245_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_14777245_output.setInt32(r, 0, _brand_id3559);
        int32_t _class_id3560 = tbl_Aggregate_TD_14777245_output_preprocess.getInt32(r, 6);
        tbl_Aggregate_TD_14777245_output.setInt32(r, 1, _class_id3560);
        int32_t _category_id3561 = tbl_Aggregate_TD_14777245_output_preprocess.getInt32(r, 5);
        tbl_Aggregate_TD_14777245_output.setInt32(r, 2, _category_id3561);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_14777245_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_14777245_output #Row: " << tbl_Aggregate_TD_14777245_output.getNumRow() << std::endl;
}

void SW_Filter_TD_14478762(Table &tbl_SerializeFromObject_TD_15483949_input, Table &tbl_Filter_TD_14478762_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(i_brand_id#235) AND isnotnull(i_class_id#237)) AND isnotnull(i_category_id#239)))
    // Input: ListBuffer(i_item_sk#228, i_brand_id#235, i_class_id#237, i_category_id#239)
    // Output: ListBuffer(i_item_sk#228, i_brand_id#235, i_class_id#237, i_category_id#239)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_15483949_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_brand_id235 = tbl_SerializeFromObject_TD_15483949_input.getInt32(i, 1);
        int32_t _i_class_id237 = tbl_SerializeFromObject_TD_15483949_input.getInt32(i, 2);
        int32_t _i_category_id239 = tbl_SerializeFromObject_TD_15483949_input.getInt32(i, 3);
        if (((_i_brand_id235!= 0) && (_i_class_id237!= 0)) && (_i_category_id239!= 0)) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_15483949_input.getInt32(i, 0);
            tbl_Filter_TD_14478762_output.setInt32(r, 0, _i_item_sk228_t);
            int32_t _i_brand_id235_t = tbl_SerializeFromObject_TD_15483949_input.getInt32(i, 1);
            tbl_Filter_TD_14478762_output.setInt32(r, 1, _i_brand_id235_t);
            int32_t _i_class_id237_t = tbl_SerializeFromObject_TD_15483949_input.getInt32(i, 2);
            tbl_Filter_TD_14478762_output.setInt32(r, 2, _i_class_id237_t);
            int32_t _i_category_id239_t = tbl_SerializeFromObject_TD_15483949_input.getInt32(i, 3);
            tbl_Filter_TD_14478762_output.setInt32(r, 3, _i_category_id239_t);
            r++;
        }
    }
    tbl_Filter_TD_14478762_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_14478762_output #Row: " << tbl_Filter_TD_14478762_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_14860614_consolidate(Table &tbl_Aggregate_TD_14860614_output_preprocess, Table &tbl_Aggregate_TD_14860614_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_14860614_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _brand_id3559 = tbl_Aggregate_TD_14860614_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_14860614_output.setInt32(r, 0, _brand_id3559);
        int32_t _class_id3560 = tbl_Aggregate_TD_14860614_output_preprocess.getInt32(r, 6);
        tbl_Aggregate_TD_14860614_output.setInt32(r, 1, _class_id3560);
        int32_t _category_id3561 = tbl_Aggregate_TD_14860614_output_preprocess.getInt32(r, 5);
        tbl_Aggregate_TD_14860614_output.setInt32(r, 2, _category_id3561);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_14860614_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_14860614_output #Row: " << tbl_Aggregate_TD_14860614_output.getNumRow() << std::endl;
}

void SW_Filter_TD_14848004(Table &tbl_SerializeFromObject_TD_15484522_input, Table &tbl_Filter_TD_14848004_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(i_brand_id#235) AND isnotnull(i_class_id#237)) AND isnotnull(i_category_id#239)))
    // Input: ListBuffer(i_item_sk#228, i_brand_id#235, i_class_id#237, i_category_id#239)
    // Output: ListBuffer(i_item_sk#228, i_brand_id#235, i_class_id#237, i_category_id#239)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_15484522_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_brand_id235 = tbl_SerializeFromObject_TD_15484522_input.getInt32(i, 1);
        int32_t _i_class_id237 = tbl_SerializeFromObject_TD_15484522_input.getInt32(i, 2);
        int32_t _i_category_id239 = tbl_SerializeFromObject_TD_15484522_input.getInt32(i, 3);
        if (((_i_brand_id235!= 0) && (_i_class_id237!= 0)) && (_i_category_id239!= 0)) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_15484522_input.getInt32(i, 0);
            tbl_Filter_TD_14848004_output.setInt32(r, 0, _i_item_sk228_t);
            int32_t _i_brand_id235_t = tbl_SerializeFromObject_TD_15484522_input.getInt32(i, 1);
            tbl_Filter_TD_14848004_output.setInt32(r, 1, _i_brand_id235_t);
            int32_t _i_class_id237_t = tbl_SerializeFromObject_TD_15484522_input.getInt32(i, 2);
            tbl_Filter_TD_14848004_output.setInt32(r, 2, _i_class_id237_t);
            int32_t _i_category_id239_t = tbl_SerializeFromObject_TD_15484522_input.getInt32(i, 3);
            tbl_Filter_TD_14848004_output.setInt32(r, 3, _i_category_id239_t);
            r++;
        }
    }
    tbl_Filter_TD_14848004_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_14848004_output #Row: " << tbl_Filter_TD_14848004_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_14638386_consolidate(Table &tbl_Aggregate_TD_14638386_output_preprocess, Table &tbl_Aggregate_TD_14638386_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_14638386_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _brand_id3559 = tbl_Aggregate_TD_14638386_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_14638386_output.setInt32(r, 0, _brand_id3559);
        int32_t _class_id3560 = tbl_Aggregate_TD_14638386_output_preprocess.getInt32(r, 6);
        tbl_Aggregate_TD_14638386_output.setInt32(r, 1, _class_id3560);
        int32_t _category_id3561 = tbl_Aggregate_TD_14638386_output_preprocess.getInt32(r, 5);
        tbl_Aggregate_TD_14638386_output.setInt32(r, 2, _category_id3561);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_14638386_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_14638386_output #Row: " << tbl_Aggregate_TD_14638386_output.getNumRow() << std::endl;
}

void SW_Filter_TD_14898662(Table &tbl_SerializeFromObject_TD_15105589_input, Table &tbl_Filter_TD_14898662_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(i_brand_id#235) AND isnotnull(i_class_id#237)) AND isnotnull(i_category_id#239)))
    // Input: ListBuffer(i_item_sk#228, i_brand_id#235, i_class_id#237, i_category_id#239)
    // Output: ListBuffer(i_item_sk#228, i_brand_id#235, i_class_id#237, i_category_id#239)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_15105589_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_brand_id235 = tbl_SerializeFromObject_TD_15105589_input.getInt32(i, 1);
        int32_t _i_class_id237 = tbl_SerializeFromObject_TD_15105589_input.getInt32(i, 2);
        int32_t _i_category_id239 = tbl_SerializeFromObject_TD_15105589_input.getInt32(i, 3);
        if (((_i_brand_id235!= 0) && (_i_class_id237!= 0)) && (_i_category_id239!= 0)) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_15105589_input.getInt32(i, 0);
            tbl_Filter_TD_14898662_output.setInt32(r, 0, _i_item_sk228_t);
            int32_t _i_brand_id235_t = tbl_SerializeFromObject_TD_15105589_input.getInt32(i, 1);
            tbl_Filter_TD_14898662_output.setInt32(r, 1, _i_brand_id235_t);
            int32_t _i_class_id237_t = tbl_SerializeFromObject_TD_15105589_input.getInt32(i, 2);
            tbl_Filter_TD_14898662_output.setInt32(r, 2, _i_class_id237_t);
            int32_t _i_category_id239_t = tbl_SerializeFromObject_TD_15105589_input.getInt32(i, 3);
            tbl_Filter_TD_14898662_output.setInt32(r, 3, _i_category_id239_t);
            r++;
        }
    }
    tbl_Filter_TD_14898662_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_14898662_output #Row: " << tbl_Filter_TD_14898662_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_14348578_consolidate(Table &tbl_Aggregate_TD_14348578_output_preprocess, Table &tbl_Aggregate_TD_14348578_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_14348578_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _brand_id3559 = tbl_Aggregate_TD_14348578_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_14348578_output.setInt32(r, 0, _brand_id3559);
        int32_t _class_id3560 = tbl_Aggregate_TD_14348578_output_preprocess.getInt32(r, 6);
        tbl_Aggregate_TD_14348578_output.setInt32(r, 1, _class_id3560);
        int32_t _category_id3561 = tbl_Aggregate_TD_14348578_output_preprocess.getInt32(r, 5);
        tbl_Aggregate_TD_14348578_output.setInt32(r, 2, _category_id3561);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_14348578_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_14348578_output #Row: " << tbl_Aggregate_TD_14348578_output.getNumRow() << std::endl;
}

void SW_Filter_TD_14868558(Table &tbl_SerializeFromObject_TD_15345652_input, Table &tbl_Filter_TD_14868558_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(i_brand_id#235) AND isnotnull(i_class_id#237)) AND isnotnull(i_category_id#239)))
    // Input: ListBuffer(i_item_sk#228, i_brand_id#235, i_class_id#237, i_category_id#239)
    // Output: ListBuffer(i_item_sk#228, i_brand_id#235, i_class_id#237, i_category_id#239)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_15345652_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_brand_id235 = tbl_SerializeFromObject_TD_15345652_input.getInt32(i, 1);
        int32_t _i_class_id237 = tbl_SerializeFromObject_TD_15345652_input.getInt32(i, 2);
        int32_t _i_category_id239 = tbl_SerializeFromObject_TD_15345652_input.getInt32(i, 3);
        if (((_i_brand_id235!= 0) && (_i_class_id237!= 0)) && (_i_category_id239!= 0)) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_15345652_input.getInt32(i, 0);
            tbl_Filter_TD_14868558_output.setInt32(r, 0, _i_item_sk228_t);
            int32_t _i_brand_id235_t = tbl_SerializeFromObject_TD_15345652_input.getInt32(i, 1);
            tbl_Filter_TD_14868558_output.setInt32(r, 1, _i_brand_id235_t);
            int32_t _i_class_id237_t = tbl_SerializeFromObject_TD_15345652_input.getInt32(i, 2);
            tbl_Filter_TD_14868558_output.setInt32(r, 2, _i_class_id237_t);
            int32_t _i_category_id239_t = tbl_SerializeFromObject_TD_15345652_input.getInt32(i, 3);
            tbl_Filter_TD_14868558_output.setInt32(r, 3, _i_category_id239_t);
            r++;
        }
    }
    tbl_Filter_TD_14868558_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_14868558_output #Row: " << tbl_Filter_TD_14868558_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_14920013_consolidate(Table &tbl_Aggregate_TD_14920013_output_preprocess, Table &tbl_Aggregate_TD_14920013_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_14920013_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _brand_id3559 = tbl_Aggregate_TD_14920013_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_14920013_output.setInt32(r, 0, _brand_id3559);
        int32_t _class_id3560 = tbl_Aggregate_TD_14920013_output_preprocess.getInt32(r, 6);
        tbl_Aggregate_TD_14920013_output.setInt32(r, 1, _class_id3560);
        int32_t _category_id3561 = tbl_Aggregate_TD_14920013_output_preprocess.getInt32(r, 5);
        tbl_Aggregate_TD_14920013_output.setInt32(r, 2, _category_id3561);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_14920013_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_14920013_output #Row: " << tbl_Aggregate_TD_14920013_output.getNumRow() << std::endl;
}

void SW_Filter_TD_14647634(Table &tbl_SerializeFromObject_TD_15115399_input, Table &tbl_Filter_TD_14647634_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(i_brand_id#235) AND isnotnull(i_class_id#237)) AND isnotnull(i_category_id#239)))
    // Input: ListBuffer(i_item_sk#228, i_brand_id#235, i_class_id#237, i_category_id#239)
    // Output: ListBuffer(i_item_sk#228, i_brand_id#235, i_class_id#237, i_category_id#239)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_15115399_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_brand_id235 = tbl_SerializeFromObject_TD_15115399_input.getInt32(i, 1);
        int32_t _i_class_id237 = tbl_SerializeFromObject_TD_15115399_input.getInt32(i, 2);
        int32_t _i_category_id239 = tbl_SerializeFromObject_TD_15115399_input.getInt32(i, 3);
        if (((_i_brand_id235!= 0) && (_i_class_id237!= 0)) && (_i_category_id239!= 0)) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_15115399_input.getInt32(i, 0);
            tbl_Filter_TD_14647634_output.setInt32(r, 0, _i_item_sk228_t);
            int32_t _i_brand_id235_t = tbl_SerializeFromObject_TD_15115399_input.getInt32(i, 1);
            tbl_Filter_TD_14647634_output.setInt32(r, 1, _i_brand_id235_t);
            int32_t _i_class_id237_t = tbl_SerializeFromObject_TD_15115399_input.getInt32(i, 2);
            tbl_Filter_TD_14647634_output.setInt32(r, 2, _i_class_id237_t);
            int32_t _i_category_id239_t = tbl_SerializeFromObject_TD_15115399_input.getInt32(i, 3);
            tbl_Filter_TD_14647634_output.setInt32(r, 3, _i_category_id239_t);
            r++;
        }
    }
    tbl_Filter_TD_14647634_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_14647634_output #Row: " << tbl_Filter_TD_14647634_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_13612839_key_leftMajor {
    int32_t _i_brand_id235;
    int32_t _i_class_id237;
    int32_t _i_category_id239;
    bool operator==(const SW_JOIN_INNER_TD_13612839_key_leftMajor& other) const {
        return ((_i_brand_id235 == other._i_brand_id235) && (_i_class_id237 == other._i_class_id237) && (_i_category_id239 == other._i_category_id239));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_13612839_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_13612839_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id235)) + (hash<int32_t>()(k._i_class_id237)) + (hash<int32_t>()(k._i_category_id239));
    }
};
}
struct SW_JOIN_INNER_TD_13612839_payload_leftMajor {
    int32_t _i_item_sk228;
    int32_t _i_brand_id235;
    int32_t _i_class_id237;
    int32_t _i_category_id239;
};
struct SW_JOIN_INNER_TD_13612839_key_rightMajor {
    int32_t _brand_id3559;
    int32_t _class_id3560;
    int32_t _category_id3561;
    bool operator==(const SW_JOIN_INNER_TD_13612839_key_rightMajor& other) const {
        return ((_brand_id3559 == other._brand_id3559) && (_class_id3560 == other._class_id3560) && (_category_id3561 == other._category_id3561));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_13612839_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_13612839_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._brand_id3559)) + (hash<int32_t>()(k._class_id3560)) + (hash<int32_t>()(k._category_id3561));
    }
};
}
struct SW_JOIN_INNER_TD_13612839_payload_rightMajor {
    int32_t _brand_id3559;
    int32_t _class_id3560;
    int32_t _category_id3561;
};
void SW_JOIN_INNER_TD_13612839(Table &tbl_Filter_TD_14522120_output, Table &tbl_Aggregate_TD_14466509_output, Table &tbl_JOIN_INNER_TD_13612839_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((((i_brand_id#235 = brand_id#3559) AND (i_class_id#237 = class_id#3560)) AND (i_category_id#239 = category_id#3561)))
    // Left Table: ListBuffer(i_item_sk#228, i_brand_id#235, i_class_id#237, i_category_id#239)
    // Right Table: ListBuffer(brand_id#3559, class_id#3560, category_id#3561)
    // Output Table: ListBuffer(i_item_sk#228)
    int left_nrow = tbl_Filter_TD_14522120_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_14466509_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_13612839_key_leftMajor, SW_JOIN_INNER_TD_13612839_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_14522120_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_brand_id235_k = tbl_Filter_TD_14522120_output.getInt32(i, 1);
            int32_t _i_class_id237_k = tbl_Filter_TD_14522120_output.getInt32(i, 2);
            int32_t _i_category_id239_k = tbl_Filter_TD_14522120_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_13612839_key_leftMajor keyA{_i_brand_id235_k, _i_class_id237_k, _i_category_id239_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_14522120_output.getInt32(i, 0);
            int32_t _i_brand_id235 = tbl_Filter_TD_14522120_output.getInt32(i, 1);
            int32_t _i_class_id237 = tbl_Filter_TD_14522120_output.getInt32(i, 2);
            int32_t _i_category_id239 = tbl_Filter_TD_14522120_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_13612839_payload_leftMajor payloadA{_i_item_sk228, _i_brand_id235, _i_class_id237, _i_category_id239};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_14466509_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _brand_id3559_k = tbl_Aggregate_TD_14466509_output.getInt32(i, 0);
            int32_t _class_id3560_k = tbl_Aggregate_TD_14466509_output.getInt32(i, 1);
            int32_t _category_id3561_k = tbl_Aggregate_TD_14466509_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_13612839_key_leftMajor{_brand_id3559_k, _class_id3560_k, _category_id3561_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                int32_t _i_brand_id235 = (it->second)._i_brand_id235;
                int32_t _i_class_id237 = (it->second)._i_class_id237;
                int32_t _i_category_id239 = (it->second)._i_category_id239;
                int32_t _brand_id3559 = tbl_Aggregate_TD_14466509_output.getInt32(i, 0);
                int32_t _class_id3560 = tbl_Aggregate_TD_14466509_output.getInt32(i, 1);
                int32_t _category_id3561 = tbl_Aggregate_TD_14466509_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_13612839_output.setInt32(r, 0, _i_item_sk228);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_13612839_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_13612839_key_rightMajor, SW_JOIN_INNER_TD_13612839_payload_rightMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_14466509_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _brand_id3559_k = tbl_Aggregate_TD_14466509_output.getInt32(i, 0);
            int32_t _class_id3560_k = tbl_Aggregate_TD_14466509_output.getInt32(i, 1);
            int32_t _category_id3561_k = tbl_Aggregate_TD_14466509_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_13612839_key_rightMajor keyA{_brand_id3559_k, _class_id3560_k, _category_id3561_k};
            int32_t _brand_id3559 = tbl_Aggregate_TD_14466509_output.getInt32(i, 0);
            int32_t _class_id3560 = tbl_Aggregate_TD_14466509_output.getInt32(i, 1);
            int32_t _category_id3561 = tbl_Aggregate_TD_14466509_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_13612839_payload_rightMajor payloadA{_brand_id3559, _class_id3560, _category_id3561};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_14522120_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_brand_id235_k = tbl_Filter_TD_14522120_output.getInt32(i, 1);
            int32_t _i_class_id237_k = tbl_Filter_TD_14522120_output.getInt32(i, 2);
            int32_t _i_category_id239_k = tbl_Filter_TD_14522120_output.getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_13612839_key_rightMajor{_i_brand_id235_k, _i_class_id237_k, _i_category_id239_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _brand_id3559 = (it->second)._brand_id3559;
                int32_t _class_id3560 = (it->second)._class_id3560;
                int32_t _category_id3561 = (it->second)._category_id3561;
                int32_t _i_item_sk228 = tbl_Filter_TD_14522120_output.getInt32(i, 0);
                int32_t _i_brand_id235 = tbl_Filter_TD_14522120_output.getInt32(i, 1);
                int32_t _i_class_id237 = tbl_Filter_TD_14522120_output.getInt32(i, 2);
                int32_t _i_category_id239 = tbl_Filter_TD_14522120_output.getInt32(i, 3);
                tbl_JOIN_INNER_TD_13612839_output.setInt32(r, 0, _i_item_sk228);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_13612839_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_13612839_output #Row: " << tbl_JOIN_INNER_TD_13612839_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_13751698_key_leftMajor {
    int32_t _i_brand_id235;
    int32_t _i_class_id237;
    int32_t _i_category_id239;
    bool operator==(const SW_JOIN_INNER_TD_13751698_key_leftMajor& other) const {
        return ((_i_brand_id235 == other._i_brand_id235) && (_i_class_id237 == other._i_class_id237) && (_i_category_id239 == other._i_category_id239));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_13751698_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_13751698_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id235)) + (hash<int32_t>()(k._i_class_id237)) + (hash<int32_t>()(k._i_category_id239));
    }
};
}
struct SW_JOIN_INNER_TD_13751698_payload_leftMajor {
    int32_t _i_item_sk228;
    int32_t _i_brand_id235;
    int32_t _i_class_id237;
    int32_t _i_category_id239;
};
struct SW_JOIN_INNER_TD_13751698_key_rightMajor {
    int32_t _brand_id3559;
    int32_t _class_id3560;
    int32_t _category_id3561;
    bool operator==(const SW_JOIN_INNER_TD_13751698_key_rightMajor& other) const {
        return ((_brand_id3559 == other._brand_id3559) && (_class_id3560 == other._class_id3560) && (_category_id3561 == other._category_id3561));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_13751698_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_13751698_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._brand_id3559)) + (hash<int32_t>()(k._class_id3560)) + (hash<int32_t>()(k._category_id3561));
    }
};
}
struct SW_JOIN_INNER_TD_13751698_payload_rightMajor {
    int32_t _brand_id3559;
    int32_t _class_id3560;
    int32_t _category_id3561;
};
void SW_JOIN_INNER_TD_13751698(Table &tbl_Filter_TD_14478762_output, Table &tbl_Aggregate_TD_14777245_output, Table &tbl_JOIN_INNER_TD_13751698_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((((i_brand_id#235 = brand_id#3559) AND (i_class_id#237 = class_id#3560)) AND (i_category_id#239 = category_id#3561)))
    // Left Table: ListBuffer(i_item_sk#228, i_brand_id#235, i_class_id#237, i_category_id#239)
    // Right Table: ListBuffer(brand_id#3559, class_id#3560, category_id#3561)
    // Output Table: ListBuffer(i_item_sk#228)
    int left_nrow = tbl_Filter_TD_14478762_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_14777245_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_13751698_key_leftMajor, SW_JOIN_INNER_TD_13751698_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_14478762_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_brand_id235_k = tbl_Filter_TD_14478762_output.getInt32(i, 1);
            int32_t _i_class_id237_k = tbl_Filter_TD_14478762_output.getInt32(i, 2);
            int32_t _i_category_id239_k = tbl_Filter_TD_14478762_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_13751698_key_leftMajor keyA{_i_brand_id235_k, _i_class_id237_k, _i_category_id239_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_14478762_output.getInt32(i, 0);
            int32_t _i_brand_id235 = tbl_Filter_TD_14478762_output.getInt32(i, 1);
            int32_t _i_class_id237 = tbl_Filter_TD_14478762_output.getInt32(i, 2);
            int32_t _i_category_id239 = tbl_Filter_TD_14478762_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_13751698_payload_leftMajor payloadA{_i_item_sk228, _i_brand_id235, _i_class_id237, _i_category_id239};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_14777245_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _brand_id3559_k = tbl_Aggregate_TD_14777245_output.getInt32(i, 0);
            int32_t _class_id3560_k = tbl_Aggregate_TD_14777245_output.getInt32(i, 1);
            int32_t _category_id3561_k = tbl_Aggregate_TD_14777245_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_13751698_key_leftMajor{_brand_id3559_k, _class_id3560_k, _category_id3561_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                int32_t _i_brand_id235 = (it->second)._i_brand_id235;
                int32_t _i_class_id237 = (it->second)._i_class_id237;
                int32_t _i_category_id239 = (it->second)._i_category_id239;
                int32_t _brand_id3559 = tbl_Aggregate_TD_14777245_output.getInt32(i, 0);
                int32_t _class_id3560 = tbl_Aggregate_TD_14777245_output.getInt32(i, 1);
                int32_t _category_id3561 = tbl_Aggregate_TD_14777245_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_13751698_output.setInt32(r, 0, _i_item_sk228);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_13751698_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_13751698_key_rightMajor, SW_JOIN_INNER_TD_13751698_payload_rightMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_14777245_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _brand_id3559_k = tbl_Aggregate_TD_14777245_output.getInt32(i, 0);
            int32_t _class_id3560_k = tbl_Aggregate_TD_14777245_output.getInt32(i, 1);
            int32_t _category_id3561_k = tbl_Aggregate_TD_14777245_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_13751698_key_rightMajor keyA{_brand_id3559_k, _class_id3560_k, _category_id3561_k};
            int32_t _brand_id3559 = tbl_Aggregate_TD_14777245_output.getInt32(i, 0);
            int32_t _class_id3560 = tbl_Aggregate_TD_14777245_output.getInt32(i, 1);
            int32_t _category_id3561 = tbl_Aggregate_TD_14777245_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_13751698_payload_rightMajor payloadA{_brand_id3559, _class_id3560, _category_id3561};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_14478762_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_brand_id235_k = tbl_Filter_TD_14478762_output.getInt32(i, 1);
            int32_t _i_class_id237_k = tbl_Filter_TD_14478762_output.getInt32(i, 2);
            int32_t _i_category_id239_k = tbl_Filter_TD_14478762_output.getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_13751698_key_rightMajor{_i_brand_id235_k, _i_class_id237_k, _i_category_id239_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _brand_id3559 = (it->second)._brand_id3559;
                int32_t _class_id3560 = (it->second)._class_id3560;
                int32_t _category_id3561 = (it->second)._category_id3561;
                int32_t _i_item_sk228 = tbl_Filter_TD_14478762_output.getInt32(i, 0);
                int32_t _i_brand_id235 = tbl_Filter_TD_14478762_output.getInt32(i, 1);
                int32_t _i_class_id237 = tbl_Filter_TD_14478762_output.getInt32(i, 2);
                int32_t _i_category_id239 = tbl_Filter_TD_14478762_output.getInt32(i, 3);
                tbl_JOIN_INNER_TD_13751698_output.setInt32(r, 0, _i_item_sk228);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_13751698_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_13751698_output #Row: " << tbl_JOIN_INNER_TD_13751698_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_13120860_key_leftMajor {
    int32_t _i_brand_id235;
    int32_t _i_class_id237;
    int32_t _i_category_id239;
    bool operator==(const SW_JOIN_INNER_TD_13120860_key_leftMajor& other) const {
        return ((_i_brand_id235 == other._i_brand_id235) && (_i_class_id237 == other._i_class_id237) && (_i_category_id239 == other._i_category_id239));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_13120860_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_13120860_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id235)) + (hash<int32_t>()(k._i_class_id237)) + (hash<int32_t>()(k._i_category_id239));
    }
};
}
struct SW_JOIN_INNER_TD_13120860_payload_leftMajor {
    int32_t _i_item_sk228;
    int32_t _i_brand_id235;
    int32_t _i_class_id237;
    int32_t _i_category_id239;
};
struct SW_JOIN_INNER_TD_13120860_key_rightMajor {
    int32_t _brand_id3559;
    int32_t _class_id3560;
    int32_t _category_id3561;
    bool operator==(const SW_JOIN_INNER_TD_13120860_key_rightMajor& other) const {
        return ((_brand_id3559 == other._brand_id3559) && (_class_id3560 == other._class_id3560) && (_category_id3561 == other._category_id3561));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_13120860_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_13120860_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._brand_id3559)) + (hash<int32_t>()(k._class_id3560)) + (hash<int32_t>()(k._category_id3561));
    }
};
}
struct SW_JOIN_INNER_TD_13120860_payload_rightMajor {
    int32_t _brand_id3559;
    int32_t _class_id3560;
    int32_t _category_id3561;
};
void SW_JOIN_INNER_TD_13120860(Table &tbl_Filter_TD_14848004_output, Table &tbl_Aggregate_TD_14860614_output, Table &tbl_JOIN_INNER_TD_13120860_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((((i_brand_id#235 = brand_id#3559) AND (i_class_id#237 = class_id#3560)) AND (i_category_id#239 = category_id#3561)))
    // Left Table: ListBuffer(i_item_sk#228, i_brand_id#235, i_class_id#237, i_category_id#239)
    // Right Table: ListBuffer(brand_id#3559, class_id#3560, category_id#3561)
    // Output Table: ListBuffer(i_item_sk#228)
    int left_nrow = tbl_Filter_TD_14848004_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_14860614_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_13120860_key_leftMajor, SW_JOIN_INNER_TD_13120860_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_14848004_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_brand_id235_k = tbl_Filter_TD_14848004_output.getInt32(i, 1);
            int32_t _i_class_id237_k = tbl_Filter_TD_14848004_output.getInt32(i, 2);
            int32_t _i_category_id239_k = tbl_Filter_TD_14848004_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_13120860_key_leftMajor keyA{_i_brand_id235_k, _i_class_id237_k, _i_category_id239_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_14848004_output.getInt32(i, 0);
            int32_t _i_brand_id235 = tbl_Filter_TD_14848004_output.getInt32(i, 1);
            int32_t _i_class_id237 = tbl_Filter_TD_14848004_output.getInt32(i, 2);
            int32_t _i_category_id239 = tbl_Filter_TD_14848004_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_13120860_payload_leftMajor payloadA{_i_item_sk228, _i_brand_id235, _i_class_id237, _i_category_id239};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_14860614_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _brand_id3559_k = tbl_Aggregate_TD_14860614_output.getInt32(i, 0);
            int32_t _class_id3560_k = tbl_Aggregate_TD_14860614_output.getInt32(i, 1);
            int32_t _category_id3561_k = tbl_Aggregate_TD_14860614_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_13120860_key_leftMajor{_brand_id3559_k, _class_id3560_k, _category_id3561_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                int32_t _i_brand_id235 = (it->second)._i_brand_id235;
                int32_t _i_class_id237 = (it->second)._i_class_id237;
                int32_t _i_category_id239 = (it->second)._i_category_id239;
                int32_t _brand_id3559 = tbl_Aggregate_TD_14860614_output.getInt32(i, 0);
                int32_t _class_id3560 = tbl_Aggregate_TD_14860614_output.getInt32(i, 1);
                int32_t _category_id3561 = tbl_Aggregate_TD_14860614_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_13120860_output.setInt32(r, 0, _i_item_sk228);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_13120860_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_13120860_key_rightMajor, SW_JOIN_INNER_TD_13120860_payload_rightMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_14860614_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _brand_id3559_k = tbl_Aggregate_TD_14860614_output.getInt32(i, 0);
            int32_t _class_id3560_k = tbl_Aggregate_TD_14860614_output.getInt32(i, 1);
            int32_t _category_id3561_k = tbl_Aggregate_TD_14860614_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_13120860_key_rightMajor keyA{_brand_id3559_k, _class_id3560_k, _category_id3561_k};
            int32_t _brand_id3559 = tbl_Aggregate_TD_14860614_output.getInt32(i, 0);
            int32_t _class_id3560 = tbl_Aggregate_TD_14860614_output.getInt32(i, 1);
            int32_t _category_id3561 = tbl_Aggregate_TD_14860614_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_13120860_payload_rightMajor payloadA{_brand_id3559, _class_id3560, _category_id3561};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_14848004_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_brand_id235_k = tbl_Filter_TD_14848004_output.getInt32(i, 1);
            int32_t _i_class_id237_k = tbl_Filter_TD_14848004_output.getInt32(i, 2);
            int32_t _i_category_id239_k = tbl_Filter_TD_14848004_output.getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_13120860_key_rightMajor{_i_brand_id235_k, _i_class_id237_k, _i_category_id239_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _brand_id3559 = (it->second)._brand_id3559;
                int32_t _class_id3560 = (it->second)._class_id3560;
                int32_t _category_id3561 = (it->second)._category_id3561;
                int32_t _i_item_sk228 = tbl_Filter_TD_14848004_output.getInt32(i, 0);
                int32_t _i_brand_id235 = tbl_Filter_TD_14848004_output.getInt32(i, 1);
                int32_t _i_class_id237 = tbl_Filter_TD_14848004_output.getInt32(i, 2);
                int32_t _i_category_id239 = tbl_Filter_TD_14848004_output.getInt32(i, 3);
                tbl_JOIN_INNER_TD_13120860_output.setInt32(r, 0, _i_item_sk228);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_13120860_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_13120860_output #Row: " << tbl_JOIN_INNER_TD_13120860_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_13106114_key_leftMajor {
    int32_t _i_brand_id235;
    int32_t _i_class_id237;
    int32_t _i_category_id239;
    bool operator==(const SW_JOIN_INNER_TD_13106114_key_leftMajor& other) const {
        return ((_i_brand_id235 == other._i_brand_id235) && (_i_class_id237 == other._i_class_id237) && (_i_category_id239 == other._i_category_id239));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_13106114_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_13106114_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id235)) + (hash<int32_t>()(k._i_class_id237)) + (hash<int32_t>()(k._i_category_id239));
    }
};
}
struct SW_JOIN_INNER_TD_13106114_payload_leftMajor {
    int32_t _i_item_sk228;
    int32_t _i_brand_id235;
    int32_t _i_class_id237;
    int32_t _i_category_id239;
};
struct SW_JOIN_INNER_TD_13106114_key_rightMajor {
    int32_t _brand_id3559;
    int32_t _class_id3560;
    int32_t _category_id3561;
    bool operator==(const SW_JOIN_INNER_TD_13106114_key_rightMajor& other) const {
        return ((_brand_id3559 == other._brand_id3559) && (_class_id3560 == other._class_id3560) && (_category_id3561 == other._category_id3561));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_13106114_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_13106114_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._brand_id3559)) + (hash<int32_t>()(k._class_id3560)) + (hash<int32_t>()(k._category_id3561));
    }
};
}
struct SW_JOIN_INNER_TD_13106114_payload_rightMajor {
    int32_t _brand_id3559;
    int32_t _class_id3560;
    int32_t _category_id3561;
};
void SW_JOIN_INNER_TD_13106114(Table &tbl_Filter_TD_14898662_output, Table &tbl_Aggregate_TD_14638386_output, Table &tbl_JOIN_INNER_TD_13106114_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((((i_brand_id#235 = brand_id#3559) AND (i_class_id#237 = class_id#3560)) AND (i_category_id#239 = category_id#3561)))
    // Left Table: ListBuffer(i_item_sk#228, i_brand_id#235, i_class_id#237, i_category_id#239)
    // Right Table: ListBuffer(brand_id#3559, class_id#3560, category_id#3561)
    // Output Table: ListBuffer(i_item_sk#228)
    int left_nrow = tbl_Filter_TD_14898662_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_14638386_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_13106114_key_leftMajor, SW_JOIN_INNER_TD_13106114_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_14898662_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_brand_id235_k = tbl_Filter_TD_14898662_output.getInt32(i, 1);
            int32_t _i_class_id237_k = tbl_Filter_TD_14898662_output.getInt32(i, 2);
            int32_t _i_category_id239_k = tbl_Filter_TD_14898662_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_13106114_key_leftMajor keyA{_i_brand_id235_k, _i_class_id237_k, _i_category_id239_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_14898662_output.getInt32(i, 0);
            int32_t _i_brand_id235 = tbl_Filter_TD_14898662_output.getInt32(i, 1);
            int32_t _i_class_id237 = tbl_Filter_TD_14898662_output.getInt32(i, 2);
            int32_t _i_category_id239 = tbl_Filter_TD_14898662_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_13106114_payload_leftMajor payloadA{_i_item_sk228, _i_brand_id235, _i_class_id237, _i_category_id239};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_14638386_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _brand_id3559_k = tbl_Aggregate_TD_14638386_output.getInt32(i, 0);
            int32_t _class_id3560_k = tbl_Aggregate_TD_14638386_output.getInt32(i, 1);
            int32_t _category_id3561_k = tbl_Aggregate_TD_14638386_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_13106114_key_leftMajor{_brand_id3559_k, _class_id3560_k, _category_id3561_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                int32_t _i_brand_id235 = (it->second)._i_brand_id235;
                int32_t _i_class_id237 = (it->second)._i_class_id237;
                int32_t _i_category_id239 = (it->second)._i_category_id239;
                int32_t _brand_id3559 = tbl_Aggregate_TD_14638386_output.getInt32(i, 0);
                int32_t _class_id3560 = tbl_Aggregate_TD_14638386_output.getInt32(i, 1);
                int32_t _category_id3561 = tbl_Aggregate_TD_14638386_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_13106114_output.setInt32(r, 0, _i_item_sk228);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_13106114_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_13106114_key_rightMajor, SW_JOIN_INNER_TD_13106114_payload_rightMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_14638386_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _brand_id3559_k = tbl_Aggregate_TD_14638386_output.getInt32(i, 0);
            int32_t _class_id3560_k = tbl_Aggregate_TD_14638386_output.getInt32(i, 1);
            int32_t _category_id3561_k = tbl_Aggregate_TD_14638386_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_13106114_key_rightMajor keyA{_brand_id3559_k, _class_id3560_k, _category_id3561_k};
            int32_t _brand_id3559 = tbl_Aggregate_TD_14638386_output.getInt32(i, 0);
            int32_t _class_id3560 = tbl_Aggregate_TD_14638386_output.getInt32(i, 1);
            int32_t _category_id3561 = tbl_Aggregate_TD_14638386_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_13106114_payload_rightMajor payloadA{_brand_id3559, _class_id3560, _category_id3561};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_14898662_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_brand_id235_k = tbl_Filter_TD_14898662_output.getInt32(i, 1);
            int32_t _i_class_id237_k = tbl_Filter_TD_14898662_output.getInt32(i, 2);
            int32_t _i_category_id239_k = tbl_Filter_TD_14898662_output.getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_13106114_key_rightMajor{_i_brand_id235_k, _i_class_id237_k, _i_category_id239_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _brand_id3559 = (it->second)._brand_id3559;
                int32_t _class_id3560 = (it->second)._class_id3560;
                int32_t _category_id3561 = (it->second)._category_id3561;
                int32_t _i_item_sk228 = tbl_Filter_TD_14898662_output.getInt32(i, 0);
                int32_t _i_brand_id235 = tbl_Filter_TD_14898662_output.getInt32(i, 1);
                int32_t _i_class_id237 = tbl_Filter_TD_14898662_output.getInt32(i, 2);
                int32_t _i_category_id239 = tbl_Filter_TD_14898662_output.getInt32(i, 3);
                tbl_JOIN_INNER_TD_13106114_output.setInt32(r, 0, _i_item_sk228);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_13106114_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_13106114_output #Row: " << tbl_JOIN_INNER_TD_13106114_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_13970301_key_leftMajor {
    int32_t _i_brand_id235;
    int32_t _i_class_id237;
    int32_t _i_category_id239;
    bool operator==(const SW_JOIN_INNER_TD_13970301_key_leftMajor& other) const {
        return ((_i_brand_id235 == other._i_brand_id235) && (_i_class_id237 == other._i_class_id237) && (_i_category_id239 == other._i_category_id239));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_13970301_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_13970301_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id235)) + (hash<int32_t>()(k._i_class_id237)) + (hash<int32_t>()(k._i_category_id239));
    }
};
}
struct SW_JOIN_INNER_TD_13970301_payload_leftMajor {
    int32_t _i_item_sk228;
    int32_t _i_brand_id235;
    int32_t _i_class_id237;
    int32_t _i_category_id239;
};
struct SW_JOIN_INNER_TD_13970301_key_rightMajor {
    int32_t _brand_id3559;
    int32_t _class_id3560;
    int32_t _category_id3561;
    bool operator==(const SW_JOIN_INNER_TD_13970301_key_rightMajor& other) const {
        return ((_brand_id3559 == other._brand_id3559) && (_class_id3560 == other._class_id3560) && (_category_id3561 == other._category_id3561));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_13970301_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_13970301_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._brand_id3559)) + (hash<int32_t>()(k._class_id3560)) + (hash<int32_t>()(k._category_id3561));
    }
};
}
struct SW_JOIN_INNER_TD_13970301_payload_rightMajor {
    int32_t _brand_id3559;
    int32_t _class_id3560;
    int32_t _category_id3561;
};
void SW_JOIN_INNER_TD_13970301(Table &tbl_Filter_TD_14868558_output, Table &tbl_Aggregate_TD_14348578_output, Table &tbl_JOIN_INNER_TD_13970301_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((((i_brand_id#235 = brand_id#3559) AND (i_class_id#237 = class_id#3560)) AND (i_category_id#239 = category_id#3561)))
    // Left Table: ListBuffer(i_item_sk#228, i_brand_id#235, i_class_id#237, i_category_id#239)
    // Right Table: ListBuffer(brand_id#3559, class_id#3560, category_id#3561)
    // Output Table: ListBuffer(i_item_sk#228)
    int left_nrow = tbl_Filter_TD_14868558_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_14348578_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_13970301_key_leftMajor, SW_JOIN_INNER_TD_13970301_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_14868558_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_brand_id235_k = tbl_Filter_TD_14868558_output.getInt32(i, 1);
            int32_t _i_class_id237_k = tbl_Filter_TD_14868558_output.getInt32(i, 2);
            int32_t _i_category_id239_k = tbl_Filter_TD_14868558_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_13970301_key_leftMajor keyA{_i_brand_id235_k, _i_class_id237_k, _i_category_id239_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_14868558_output.getInt32(i, 0);
            int32_t _i_brand_id235 = tbl_Filter_TD_14868558_output.getInt32(i, 1);
            int32_t _i_class_id237 = tbl_Filter_TD_14868558_output.getInt32(i, 2);
            int32_t _i_category_id239 = tbl_Filter_TD_14868558_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_13970301_payload_leftMajor payloadA{_i_item_sk228, _i_brand_id235, _i_class_id237, _i_category_id239};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_14348578_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _brand_id3559_k = tbl_Aggregate_TD_14348578_output.getInt32(i, 0);
            int32_t _class_id3560_k = tbl_Aggregate_TD_14348578_output.getInt32(i, 1);
            int32_t _category_id3561_k = tbl_Aggregate_TD_14348578_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_13970301_key_leftMajor{_brand_id3559_k, _class_id3560_k, _category_id3561_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                int32_t _i_brand_id235 = (it->second)._i_brand_id235;
                int32_t _i_class_id237 = (it->second)._i_class_id237;
                int32_t _i_category_id239 = (it->second)._i_category_id239;
                int32_t _brand_id3559 = tbl_Aggregate_TD_14348578_output.getInt32(i, 0);
                int32_t _class_id3560 = tbl_Aggregate_TD_14348578_output.getInt32(i, 1);
                int32_t _category_id3561 = tbl_Aggregate_TD_14348578_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_13970301_output.setInt32(r, 0, _i_item_sk228);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_13970301_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_13970301_key_rightMajor, SW_JOIN_INNER_TD_13970301_payload_rightMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_14348578_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _brand_id3559_k = tbl_Aggregate_TD_14348578_output.getInt32(i, 0);
            int32_t _class_id3560_k = tbl_Aggregate_TD_14348578_output.getInt32(i, 1);
            int32_t _category_id3561_k = tbl_Aggregate_TD_14348578_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_13970301_key_rightMajor keyA{_brand_id3559_k, _class_id3560_k, _category_id3561_k};
            int32_t _brand_id3559 = tbl_Aggregate_TD_14348578_output.getInt32(i, 0);
            int32_t _class_id3560 = tbl_Aggregate_TD_14348578_output.getInt32(i, 1);
            int32_t _category_id3561 = tbl_Aggregate_TD_14348578_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_13970301_payload_rightMajor payloadA{_brand_id3559, _class_id3560, _category_id3561};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_14868558_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_brand_id235_k = tbl_Filter_TD_14868558_output.getInt32(i, 1);
            int32_t _i_class_id237_k = tbl_Filter_TD_14868558_output.getInt32(i, 2);
            int32_t _i_category_id239_k = tbl_Filter_TD_14868558_output.getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_13970301_key_rightMajor{_i_brand_id235_k, _i_class_id237_k, _i_category_id239_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _brand_id3559 = (it->second)._brand_id3559;
                int32_t _class_id3560 = (it->second)._class_id3560;
                int32_t _category_id3561 = (it->second)._category_id3561;
                int32_t _i_item_sk228 = tbl_Filter_TD_14868558_output.getInt32(i, 0);
                int32_t _i_brand_id235 = tbl_Filter_TD_14868558_output.getInt32(i, 1);
                int32_t _i_class_id237 = tbl_Filter_TD_14868558_output.getInt32(i, 2);
                int32_t _i_category_id239 = tbl_Filter_TD_14868558_output.getInt32(i, 3);
                tbl_JOIN_INNER_TD_13970301_output.setInt32(r, 0, _i_item_sk228);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_13970301_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_13970301_output #Row: " << tbl_JOIN_INNER_TD_13970301_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_13718401_key_leftMajor {
    int32_t _i_brand_id235;
    int32_t _i_class_id237;
    int32_t _i_category_id239;
    bool operator==(const SW_JOIN_INNER_TD_13718401_key_leftMajor& other) const {
        return ((_i_brand_id235 == other._i_brand_id235) && (_i_class_id237 == other._i_class_id237) && (_i_category_id239 == other._i_category_id239));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_13718401_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_13718401_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_brand_id235)) + (hash<int32_t>()(k._i_class_id237)) + (hash<int32_t>()(k._i_category_id239));
    }
};
}
struct SW_JOIN_INNER_TD_13718401_payload_leftMajor {
    int32_t _i_item_sk228;
    int32_t _i_brand_id235;
    int32_t _i_class_id237;
    int32_t _i_category_id239;
};
struct SW_JOIN_INNER_TD_13718401_key_rightMajor {
    int32_t _brand_id3559;
    int32_t _class_id3560;
    int32_t _category_id3561;
    bool operator==(const SW_JOIN_INNER_TD_13718401_key_rightMajor& other) const {
        return ((_brand_id3559 == other._brand_id3559) && (_class_id3560 == other._class_id3560) && (_category_id3561 == other._category_id3561));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_13718401_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_13718401_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._brand_id3559)) + (hash<int32_t>()(k._class_id3560)) + (hash<int32_t>()(k._category_id3561));
    }
};
}
struct SW_JOIN_INNER_TD_13718401_payload_rightMajor {
    int32_t _brand_id3559;
    int32_t _class_id3560;
    int32_t _category_id3561;
};
void SW_JOIN_INNER_TD_13718401(Table &tbl_Filter_TD_14647634_output, Table &tbl_Aggregate_TD_14920013_output, Table &tbl_JOIN_INNER_TD_13718401_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((((i_brand_id#235 = brand_id#3559) AND (i_class_id#237 = class_id#3560)) AND (i_category_id#239 = category_id#3561)))
    // Left Table: ListBuffer(i_item_sk#228, i_brand_id#235, i_class_id#237, i_category_id#239)
    // Right Table: ListBuffer(brand_id#3559, class_id#3560, category_id#3561)
    // Output Table: ListBuffer(i_item_sk#228)
    int left_nrow = tbl_Filter_TD_14647634_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_14920013_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_13718401_key_leftMajor, SW_JOIN_INNER_TD_13718401_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_14647634_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_brand_id235_k = tbl_Filter_TD_14647634_output.getInt32(i, 1);
            int32_t _i_class_id237_k = tbl_Filter_TD_14647634_output.getInt32(i, 2);
            int32_t _i_category_id239_k = tbl_Filter_TD_14647634_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_13718401_key_leftMajor keyA{_i_brand_id235_k, _i_class_id237_k, _i_category_id239_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_14647634_output.getInt32(i, 0);
            int32_t _i_brand_id235 = tbl_Filter_TD_14647634_output.getInt32(i, 1);
            int32_t _i_class_id237 = tbl_Filter_TD_14647634_output.getInt32(i, 2);
            int32_t _i_category_id239 = tbl_Filter_TD_14647634_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_13718401_payload_leftMajor payloadA{_i_item_sk228, _i_brand_id235, _i_class_id237, _i_category_id239};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_14920013_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _brand_id3559_k = tbl_Aggregate_TD_14920013_output.getInt32(i, 0);
            int32_t _class_id3560_k = tbl_Aggregate_TD_14920013_output.getInt32(i, 1);
            int32_t _category_id3561_k = tbl_Aggregate_TD_14920013_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_13718401_key_leftMajor{_brand_id3559_k, _class_id3560_k, _category_id3561_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                int32_t _i_brand_id235 = (it->second)._i_brand_id235;
                int32_t _i_class_id237 = (it->second)._i_class_id237;
                int32_t _i_category_id239 = (it->second)._i_category_id239;
                int32_t _brand_id3559 = tbl_Aggregate_TD_14920013_output.getInt32(i, 0);
                int32_t _class_id3560 = tbl_Aggregate_TD_14920013_output.getInt32(i, 1);
                int32_t _category_id3561 = tbl_Aggregate_TD_14920013_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_13718401_output.setInt32(r, 0, _i_item_sk228);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_13718401_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_13718401_key_rightMajor, SW_JOIN_INNER_TD_13718401_payload_rightMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_14920013_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _brand_id3559_k = tbl_Aggregate_TD_14920013_output.getInt32(i, 0);
            int32_t _class_id3560_k = tbl_Aggregate_TD_14920013_output.getInt32(i, 1);
            int32_t _category_id3561_k = tbl_Aggregate_TD_14920013_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_13718401_key_rightMajor keyA{_brand_id3559_k, _class_id3560_k, _category_id3561_k};
            int32_t _brand_id3559 = tbl_Aggregate_TD_14920013_output.getInt32(i, 0);
            int32_t _class_id3560 = tbl_Aggregate_TD_14920013_output.getInt32(i, 1);
            int32_t _category_id3561 = tbl_Aggregate_TD_14920013_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_13718401_payload_rightMajor payloadA{_brand_id3559, _class_id3560, _category_id3561};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_14647634_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_brand_id235_k = tbl_Filter_TD_14647634_output.getInt32(i, 1);
            int32_t _i_class_id237_k = tbl_Filter_TD_14647634_output.getInt32(i, 2);
            int32_t _i_category_id239_k = tbl_Filter_TD_14647634_output.getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_13718401_key_rightMajor{_i_brand_id235_k, _i_class_id237_k, _i_category_id239_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _brand_id3559 = (it->second)._brand_id3559;
                int32_t _class_id3560 = (it->second)._class_id3560;
                int32_t _category_id3561 = (it->second)._category_id3561;
                int32_t _i_item_sk228 = tbl_Filter_TD_14647634_output.getInt32(i, 0);
                int32_t _i_brand_id235 = tbl_Filter_TD_14647634_output.getInt32(i, 1);
                int32_t _i_class_id237 = tbl_Filter_TD_14647634_output.getInt32(i, 2);
                int32_t _i_category_id239 = tbl_Filter_TD_14647634_output.getInt32(i, 3);
                tbl_JOIN_INNER_TD_13718401_output.setInt32(r, 0, _i_item_sk228);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_13718401_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_13718401_output #Row: " << tbl_JOIN_INNER_TD_13718401_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12710146(Table &tbl_SerializeFromObject_TD_13195344_input, Table &tbl_Filter_TD_12710146_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3845) AND ((d_year#3845 >= 1999) AND (d_year#3845 <= 2001))) AND isnotnull(d_date_sk#3839)))
    // Input: ListBuffer(d_date_sk#3839, d_year#3845)
    // Output: ListBuffer(d_date_sk#3839)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13195344_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3845 = tbl_SerializeFromObject_TD_13195344_input.getInt32(i, 1);
        int32_t _d_date_sk3839 = tbl_SerializeFromObject_TD_13195344_input.getInt32(i, 0);
        if (((_d_year3845!= 0) && ((_d_year3845 >= 1999) && (_d_year3845 <= 2001))) && (_d_date_sk3839!= 0)) {
            int32_t _d_date_sk3839_t = tbl_SerializeFromObject_TD_13195344_input.getInt32(i, 0);
            tbl_Filter_TD_12710146_output.setInt32(r, 0, _d_date_sk3839_t);
            r++;
        }
    }
    tbl_Filter_TD_12710146_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12710146_output #Row: " << tbl_Filter_TD_12710146_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12636443(Table &tbl_SerializeFromObject_TD_13949288_input, Table &tbl_Filter_TD_12636443_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ws_sold_date_sk#3805))
    // Input: ListBuffer(ws_sold_date_sk#3805, ws_quantity#3823, ws_list_price#3825)
    // Output: ListBuffer(ws_sold_date_sk#3805, ws_quantity#3823, ws_list_price#3825)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13949288_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_sold_date_sk3805 = tbl_SerializeFromObject_TD_13949288_input.getInt32(i, 0);
        if (_ws_sold_date_sk3805!= 0) {
            int32_t _ws_sold_date_sk3805_t = tbl_SerializeFromObject_TD_13949288_input.getInt32(i, 0);
            tbl_Filter_TD_12636443_output.setInt32(r, 0, _ws_sold_date_sk3805_t);
            int32_t _ws_quantity3823_t = tbl_SerializeFromObject_TD_13949288_input.getInt32(i, 1);
            tbl_Filter_TD_12636443_output.setInt32(r, 1, _ws_quantity3823_t);
            int64_t _ws_list_price3825_t = tbl_SerializeFromObject_TD_13949288_input.getInt64(i, 2);
            tbl_Filter_TD_12636443_output.setInt64(r, 2, _ws_list_price3825_t);
            r++;
        }
    }
    tbl_Filter_TD_12636443_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12636443_output #Row: " << tbl_Filter_TD_12636443_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12720110(Table &tbl_SerializeFromObject_TD_13372367_input, Table &tbl_Filter_TD_12720110_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3783) AND ((d_year#3783 >= 1999) AND (d_year#3783 <= 2001))) AND isnotnull(d_date_sk#3777)))
    // Input: ListBuffer(d_date_sk#3777, d_year#3783)
    // Output: ListBuffer(d_date_sk#3777)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13372367_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3783 = tbl_SerializeFromObject_TD_13372367_input.getInt32(i, 1);
        int32_t _d_date_sk3777 = tbl_SerializeFromObject_TD_13372367_input.getInt32(i, 0);
        if (((_d_year3783!= 0) && ((_d_year3783 >= 1999) && (_d_year3783 <= 2001))) && (_d_date_sk3777!= 0)) {
            int32_t _d_date_sk3777_t = tbl_SerializeFromObject_TD_13372367_input.getInt32(i, 0);
            tbl_Filter_TD_12720110_output.setInt32(r, 0, _d_date_sk3777_t);
            r++;
        }
    }
    tbl_Filter_TD_12720110_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12720110_output #Row: " << tbl_Filter_TD_12720110_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12654986(Table &tbl_SerializeFromObject_TD_13809606_input, Table &tbl_Filter_TD_12654986_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(cs_sold_date_sk#3743))
    // Input: ListBuffer(cs_sold_date_sk#3743, cs_quantity#3761, cs_list_price#3763)
    // Output: ListBuffer(cs_sold_date_sk#3743, cs_quantity#3761, cs_list_price#3763)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13809606_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_sold_date_sk3743 = tbl_SerializeFromObject_TD_13809606_input.getInt32(i, 0);
        if (_cs_sold_date_sk3743!= 0) {
            int32_t _cs_sold_date_sk3743_t = tbl_SerializeFromObject_TD_13809606_input.getInt32(i, 0);
            tbl_Filter_TD_12654986_output.setInt32(r, 0, _cs_sold_date_sk3743_t);
            int32_t _cs_quantity3761_t = tbl_SerializeFromObject_TD_13809606_input.getInt32(i, 1);
            tbl_Filter_TD_12654986_output.setInt32(r, 1, _cs_quantity3761_t);
            int64_t _cs_list_price3763_t = tbl_SerializeFromObject_TD_13809606_input.getInt64(i, 2);
            tbl_Filter_TD_12654986_output.setInt64(r, 2, _cs_list_price3763_t);
            r++;
        }
    }
    tbl_Filter_TD_12654986_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12654986_output #Row: " << tbl_Filter_TD_12654986_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12494876(Table &tbl_SerializeFromObject_TD_13600303_input, Table &tbl_Filter_TD_12494876_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3721) AND ((d_year#3721 >= 1999) AND (d_year#3721 <= 2001))) AND isnotnull(d_date_sk#3715)))
    // Input: ListBuffer(d_date_sk#3715, d_year#3721)
    // Output: ListBuffer(d_date_sk#3715)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13600303_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3721 = tbl_SerializeFromObject_TD_13600303_input.getInt32(i, 1);
        int32_t _d_date_sk3715 = tbl_SerializeFromObject_TD_13600303_input.getInt32(i, 0);
        if (((_d_year3721!= 0) && ((_d_year3721 >= 1999) && (_d_year3721 <= 2001))) && (_d_date_sk3715!= 0)) {
            int32_t _d_date_sk3715_t = tbl_SerializeFromObject_TD_13600303_input.getInt32(i, 0);
            tbl_Filter_TD_12494876_output.setInt32(r, 0, _d_date_sk3715_t);
            r++;
        }
    }
    tbl_Filter_TD_12494876_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12494876_output #Row: " << tbl_Filter_TD_12494876_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12834434(Table &tbl_SerializeFromObject_TD_13253711_input, Table &tbl_Filter_TD_12834434_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ss_sold_date_sk#3692))
    // Input: ListBuffer(ss_sold_date_sk#3692, ss_quantity#3702, ss_list_price#3704)
    // Output: ListBuffer(ss_sold_date_sk#3692, ss_quantity#3702, ss_list_price#3704)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13253711_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk3692 = tbl_SerializeFromObject_TD_13253711_input.getInt32(i, 0);
        if (_ss_sold_date_sk3692!= 0) {
            int32_t _ss_sold_date_sk3692_t = tbl_SerializeFromObject_TD_13253711_input.getInt32(i, 0);
            tbl_Filter_TD_12834434_output.setInt32(r, 0, _ss_sold_date_sk3692_t);
            int32_t _ss_quantity3702_t = tbl_SerializeFromObject_TD_13253711_input.getInt32(i, 1);
            tbl_Filter_TD_12834434_output.setInt32(r, 1, _ss_quantity3702_t);
            int64_t _ss_list_price3704_t = tbl_SerializeFromObject_TD_13253711_input.getInt64(i, 2);
            tbl_Filter_TD_12834434_output.setInt64(r, 2, _ss_list_price3704_t);
            r++;
        }
    }
    tbl_Filter_TD_12834434_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12834434_output #Row: " << tbl_Filter_TD_12834434_output.getNumRow() << std::endl;
}

void SW_Project_TD_12926731(Table &tbl_JOIN_INNER_TD_13612839_output, Table &tbl_Project_TD_12926731_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(i_item_sk#228 AS ss_item_sk#3562)
    // Input: ListBuffer(i_item_sk#228)
    // Output: ListBuffer(ss_item_sk#3562)
    int nrow1 = tbl_JOIN_INNER_TD_13612839_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk228 = tbl_JOIN_INNER_TD_13612839_output.getInt32(i, 0);
        int32_t _ss_item_sk3562 = _i_item_sk228;
        tbl_Project_TD_12926731_output.setInt32(i, 0, _ss_item_sk3562);
    }
    tbl_Project_TD_12926731_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_12926731_output #Row: " << tbl_Project_TD_12926731_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12103855(Table &tbl_SerializeFromObject_TD_1313870_input, Table &tbl_Filter_TD_12103855_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#4058))
    // Input: ListBuffer(i_item_sk#4058, i_brand_id#4065, i_class_id#4067, i_category_id#4069)
    // Output: ListBuffer(i_item_sk#4058, i_brand_id#4065, i_class_id#4067, i_category_id#4069)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1313870_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk4058 = tbl_SerializeFromObject_TD_1313870_input.getInt32(i, 0);
        if (_i_item_sk4058!= 0) {
            int32_t _i_item_sk4058_t = tbl_SerializeFromObject_TD_1313870_input.getInt32(i, 0);
            tbl_Filter_TD_12103855_output.setInt32(r, 0, _i_item_sk4058_t);
            int32_t _i_brand_id4065_t = tbl_SerializeFromObject_TD_1313870_input.getInt32(i, 1);
            tbl_Filter_TD_12103855_output.setInt32(r, 1, _i_brand_id4065_t);
            int32_t _i_class_id4067_t = tbl_SerializeFromObject_TD_1313870_input.getInt32(i, 2);
            tbl_Filter_TD_12103855_output.setInt32(r, 2, _i_class_id4067_t);
            int32_t _i_category_id4069_t = tbl_SerializeFromObject_TD_1313870_input.getInt32(i, 3);
            tbl_Filter_TD_12103855_output.setInt32(r, 3, _i_category_id4069_t);
            r++;
        }
    }
    tbl_Filter_TD_12103855_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12103855_output #Row: " << tbl_Filter_TD_12103855_output.getNumRow() << std::endl;
}

void SW_Project_TD_12194295(Table &tbl_JOIN_INNER_TD_13751698_output, Table &tbl_Project_TD_12194295_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(i_item_sk#228 AS ss_item_sk#3562)
    // Input: ListBuffer(i_item_sk#228)
    // Output: ListBuffer(ss_item_sk#3562)
    int nrow1 = tbl_JOIN_INNER_TD_13751698_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk228 = tbl_JOIN_INNER_TD_13751698_output.getInt32(i, 0);
        int32_t _ss_item_sk3562 = _i_item_sk228;
        tbl_Project_TD_12194295_output.setInt32(i, 0, _ss_item_sk3562);
    }
    tbl_Project_TD_12194295_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_12194295_output #Row: " << tbl_Project_TD_12194295_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12729285(Table &tbl_SerializeFromObject_TD_13374742_input, Table &tbl_Filter_TD_12729285_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_item_sk#4027) AND isnotnull(ws_sold_date_sk#4024)))
    // Input: ListBuffer(ws_sold_date_sk#4024, ws_item_sk#4027, ws_quantity#4042, ws_list_price#4044)
    // Output: ListBuffer(ws_sold_date_sk#4024, ws_item_sk#4027, ws_quantity#4042, ws_list_price#4044)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13374742_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_item_sk4027 = tbl_SerializeFromObject_TD_13374742_input.getInt32(i, 1);
        int32_t _ws_sold_date_sk4024 = tbl_SerializeFromObject_TD_13374742_input.getInt32(i, 0);
        if ((_ws_item_sk4027!= 0) && (_ws_sold_date_sk4024!= 0)) {
            int32_t _ws_sold_date_sk4024_t = tbl_SerializeFromObject_TD_13374742_input.getInt32(i, 0);
            tbl_Filter_TD_12729285_output.setInt32(r, 0, _ws_sold_date_sk4024_t);
            int32_t _ws_item_sk4027_t = tbl_SerializeFromObject_TD_13374742_input.getInt32(i, 1);
            tbl_Filter_TD_12729285_output.setInt32(r, 1, _ws_item_sk4027_t);
            int32_t _ws_quantity4042_t = tbl_SerializeFromObject_TD_13374742_input.getInt32(i, 2);
            tbl_Filter_TD_12729285_output.setInt32(r, 2, _ws_quantity4042_t);
            int64_t _ws_list_price4044_t = tbl_SerializeFromObject_TD_13374742_input.getInt64(i, 3);
            tbl_Filter_TD_12729285_output.setInt64(r, 3, _ws_list_price4044_t);
            r++;
        }
    }
    tbl_Filter_TD_12729285_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12729285_output #Row: " << tbl_Filter_TD_12729285_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12107269(Table &tbl_SerializeFromObject_TD_13364984_input, Table &tbl_Filter_TD_12107269_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3845) AND ((d_year#3845 >= 1999) AND (d_year#3845 <= 2001))) AND isnotnull(d_date_sk#3839)))
    // Input: ListBuffer(d_date_sk#3839, d_year#3845)
    // Output: ListBuffer(d_date_sk#3839)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13364984_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3845 = tbl_SerializeFromObject_TD_13364984_input.getInt32(i, 1);
        int32_t _d_date_sk3839 = tbl_SerializeFromObject_TD_13364984_input.getInt32(i, 0);
        if (((_d_year3845!= 0) && ((_d_year3845 >= 1999) && (_d_year3845 <= 2001))) && (_d_date_sk3839!= 0)) {
            int32_t _d_date_sk3839_t = tbl_SerializeFromObject_TD_13364984_input.getInt32(i, 0);
            tbl_Filter_TD_12107269_output.setInt32(r, 0, _d_date_sk3839_t);
            r++;
        }
    }
    tbl_Filter_TD_12107269_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12107269_output #Row: " << tbl_Filter_TD_12107269_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12165896(Table &tbl_SerializeFromObject_TD_13705858_input, Table &tbl_Filter_TD_12165896_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ws_sold_date_sk#3805))
    // Input: ListBuffer(ws_sold_date_sk#3805, ws_quantity#3823, ws_list_price#3825)
    // Output: ListBuffer(ws_sold_date_sk#3805, ws_quantity#3823, ws_list_price#3825)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13705858_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_sold_date_sk3805 = tbl_SerializeFromObject_TD_13705858_input.getInt32(i, 0);
        if (_ws_sold_date_sk3805!= 0) {
            int32_t _ws_sold_date_sk3805_t = tbl_SerializeFromObject_TD_13705858_input.getInt32(i, 0);
            tbl_Filter_TD_12165896_output.setInt32(r, 0, _ws_sold_date_sk3805_t);
            int32_t _ws_quantity3823_t = tbl_SerializeFromObject_TD_13705858_input.getInt32(i, 1);
            tbl_Filter_TD_12165896_output.setInt32(r, 1, _ws_quantity3823_t);
            int64_t _ws_list_price3825_t = tbl_SerializeFromObject_TD_13705858_input.getInt64(i, 2);
            tbl_Filter_TD_12165896_output.setInt64(r, 2, _ws_list_price3825_t);
            r++;
        }
    }
    tbl_Filter_TD_12165896_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12165896_output #Row: " << tbl_Filter_TD_12165896_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12487816(Table &tbl_SerializeFromObject_TD_13767968_input, Table &tbl_Filter_TD_12487816_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3783) AND ((d_year#3783 >= 1999) AND (d_year#3783 <= 2001))) AND isnotnull(d_date_sk#3777)))
    // Input: ListBuffer(d_date_sk#3777, d_year#3783)
    // Output: ListBuffer(d_date_sk#3777)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13767968_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3783 = tbl_SerializeFromObject_TD_13767968_input.getInt32(i, 1);
        int32_t _d_date_sk3777 = tbl_SerializeFromObject_TD_13767968_input.getInt32(i, 0);
        if (((_d_year3783!= 0) && ((_d_year3783 >= 1999) && (_d_year3783 <= 2001))) && (_d_date_sk3777!= 0)) {
            int32_t _d_date_sk3777_t = tbl_SerializeFromObject_TD_13767968_input.getInt32(i, 0);
            tbl_Filter_TD_12487816_output.setInt32(r, 0, _d_date_sk3777_t);
            r++;
        }
    }
    tbl_Filter_TD_12487816_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12487816_output #Row: " << tbl_Filter_TD_12487816_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12316192(Table &tbl_SerializeFromObject_TD_13982163_input, Table &tbl_Filter_TD_12316192_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(cs_sold_date_sk#3743))
    // Input: ListBuffer(cs_sold_date_sk#3743, cs_quantity#3761, cs_list_price#3763)
    // Output: ListBuffer(cs_sold_date_sk#3743, cs_quantity#3761, cs_list_price#3763)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13982163_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_sold_date_sk3743 = tbl_SerializeFromObject_TD_13982163_input.getInt32(i, 0);
        if (_cs_sold_date_sk3743!= 0) {
            int32_t _cs_sold_date_sk3743_t = tbl_SerializeFromObject_TD_13982163_input.getInt32(i, 0);
            tbl_Filter_TD_12316192_output.setInt32(r, 0, _cs_sold_date_sk3743_t);
            int32_t _cs_quantity3761_t = tbl_SerializeFromObject_TD_13982163_input.getInt32(i, 1);
            tbl_Filter_TD_12316192_output.setInt32(r, 1, _cs_quantity3761_t);
            int64_t _cs_list_price3763_t = tbl_SerializeFromObject_TD_13982163_input.getInt64(i, 2);
            tbl_Filter_TD_12316192_output.setInt64(r, 2, _cs_list_price3763_t);
            r++;
        }
    }
    tbl_Filter_TD_12316192_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12316192_output #Row: " << tbl_Filter_TD_12316192_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12447959(Table &tbl_SerializeFromObject_TD_13942167_input, Table &tbl_Filter_TD_12447959_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3721) AND ((d_year#3721 >= 1999) AND (d_year#3721 <= 2001))) AND isnotnull(d_date_sk#3715)))
    // Input: ListBuffer(d_date_sk#3715, d_year#3721)
    // Output: ListBuffer(d_date_sk#3715)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13942167_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3721 = tbl_SerializeFromObject_TD_13942167_input.getInt32(i, 1);
        int32_t _d_date_sk3715 = tbl_SerializeFromObject_TD_13942167_input.getInt32(i, 0);
        if (((_d_year3721!= 0) && ((_d_year3721 >= 1999) && (_d_year3721 <= 2001))) && (_d_date_sk3715!= 0)) {
            int32_t _d_date_sk3715_t = tbl_SerializeFromObject_TD_13942167_input.getInt32(i, 0);
            tbl_Filter_TD_12447959_output.setInt32(r, 0, _d_date_sk3715_t);
            r++;
        }
    }
    tbl_Filter_TD_12447959_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12447959_output #Row: " << tbl_Filter_TD_12447959_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12427481(Table &tbl_SerializeFromObject_TD_1362574_input, Table &tbl_Filter_TD_12427481_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ss_sold_date_sk#3692))
    // Input: ListBuffer(ss_sold_date_sk#3692, ss_quantity#3702, ss_list_price#3704)
    // Output: ListBuffer(ss_sold_date_sk#3692, ss_quantity#3702, ss_list_price#3704)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1362574_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk3692 = tbl_SerializeFromObject_TD_1362574_input.getInt32(i, 0);
        if (_ss_sold_date_sk3692!= 0) {
            int32_t _ss_sold_date_sk3692_t = tbl_SerializeFromObject_TD_1362574_input.getInt32(i, 0);
            tbl_Filter_TD_12427481_output.setInt32(r, 0, _ss_sold_date_sk3692_t);
            int32_t _ss_quantity3702_t = tbl_SerializeFromObject_TD_1362574_input.getInt32(i, 1);
            tbl_Filter_TD_12427481_output.setInt32(r, 1, _ss_quantity3702_t);
            int64_t _ss_list_price3704_t = tbl_SerializeFromObject_TD_1362574_input.getInt64(i, 2);
            tbl_Filter_TD_12427481_output.setInt64(r, 2, _ss_list_price3704_t);
            r++;
        }
    }
    tbl_Filter_TD_12427481_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12427481_output #Row: " << tbl_Filter_TD_12427481_output.getNumRow() << std::endl;
}

void SW_Project_TD_12709199(Table &tbl_JOIN_INNER_TD_13120860_output, Table &tbl_Project_TD_12709199_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(i_item_sk#228 AS ss_item_sk#3562)
    // Input: ListBuffer(i_item_sk#228)
    // Output: ListBuffer(ss_item_sk#3562)
    int nrow1 = tbl_JOIN_INNER_TD_13120860_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk228 = tbl_JOIN_INNER_TD_13120860_output.getInt32(i, 0);
        int32_t _ss_item_sk3562 = _i_item_sk228;
        tbl_Project_TD_12709199_output.setInt32(i, 0, _ss_item_sk3562);
    }
    tbl_Project_TD_12709199_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_12709199_output #Row: " << tbl_Project_TD_12709199_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12159634(Table &tbl_SerializeFromObject_TD_13622359_input, Table &tbl_Filter_TD_12159634_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#3974))
    // Input: ListBuffer(i_item_sk#3974, i_brand_id#3981, i_class_id#3983, i_category_id#3985)
    // Output: ListBuffer(i_item_sk#3974, i_brand_id#3981, i_class_id#3983, i_category_id#3985)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13622359_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk3974 = tbl_SerializeFromObject_TD_13622359_input.getInt32(i, 0);
        if (_i_item_sk3974!= 0) {
            int32_t _i_item_sk3974_t = tbl_SerializeFromObject_TD_13622359_input.getInt32(i, 0);
            tbl_Filter_TD_12159634_output.setInt32(r, 0, _i_item_sk3974_t);
            int32_t _i_brand_id3981_t = tbl_SerializeFromObject_TD_13622359_input.getInt32(i, 1);
            tbl_Filter_TD_12159634_output.setInt32(r, 1, _i_brand_id3981_t);
            int32_t _i_class_id3983_t = tbl_SerializeFromObject_TD_13622359_input.getInt32(i, 2);
            tbl_Filter_TD_12159634_output.setInt32(r, 2, _i_class_id3983_t);
            int32_t _i_category_id3985_t = tbl_SerializeFromObject_TD_13622359_input.getInt32(i, 3);
            tbl_Filter_TD_12159634_output.setInt32(r, 3, _i_category_id3985_t);
            r++;
        }
    }
    tbl_Filter_TD_12159634_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12159634_output #Row: " << tbl_Filter_TD_12159634_output.getNumRow() << std::endl;
}

void SW_Project_TD_12663626(Table &tbl_JOIN_INNER_TD_13106114_output, Table &tbl_Project_TD_12663626_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(i_item_sk#228 AS ss_item_sk#3562)
    // Input: ListBuffer(i_item_sk#228)
    // Output: ListBuffer(ss_item_sk#3562)
    int nrow1 = tbl_JOIN_INNER_TD_13106114_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk228 = tbl_JOIN_INNER_TD_13106114_output.getInt32(i, 0);
        int32_t _ss_item_sk3562 = _i_item_sk228;
        tbl_Project_TD_12663626_output.setInt32(i, 0, _ss_item_sk3562);
    }
    tbl_Project_TD_12663626_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_12663626_output #Row: " << tbl_Project_TD_12663626_output.getNumRow() << std::endl;
}

void SW_Filter_TD_1296220(Table &tbl_SerializeFromObject_TD_13617981_input, Table &tbl_Filter_TD_1296220_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(cs_item_sk#3955) AND isnotnull(cs_sold_date_sk#3940)))
    // Input: ListBuffer(cs_sold_date_sk#3940, cs_item_sk#3955, cs_quantity#3958, cs_list_price#3960)
    // Output: ListBuffer(cs_sold_date_sk#3940, cs_item_sk#3955, cs_quantity#3958, cs_list_price#3960)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13617981_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_item_sk3955 = tbl_SerializeFromObject_TD_13617981_input.getInt32(i, 1);
        int32_t _cs_sold_date_sk3940 = tbl_SerializeFromObject_TD_13617981_input.getInt32(i, 0);
        if ((_cs_item_sk3955!= 0) && (_cs_sold_date_sk3940!= 0)) {
            int32_t _cs_sold_date_sk3940_t = tbl_SerializeFromObject_TD_13617981_input.getInt32(i, 0);
            tbl_Filter_TD_1296220_output.setInt32(r, 0, _cs_sold_date_sk3940_t);
            int32_t _cs_item_sk3955_t = tbl_SerializeFromObject_TD_13617981_input.getInt32(i, 1);
            tbl_Filter_TD_1296220_output.setInt32(r, 1, _cs_item_sk3955_t);
            int32_t _cs_quantity3958_t = tbl_SerializeFromObject_TD_13617981_input.getInt32(i, 2);
            tbl_Filter_TD_1296220_output.setInt32(r, 2, _cs_quantity3958_t);
            int64_t _cs_list_price3960_t = tbl_SerializeFromObject_TD_13617981_input.getInt64(i, 3);
            tbl_Filter_TD_1296220_output.setInt64(r, 3, _cs_list_price3960_t);
            r++;
        }
    }
    tbl_Filter_TD_1296220_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1296220_output #Row: " << tbl_Filter_TD_1296220_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12412741(Table &tbl_SerializeFromObject_TD_13600448_input, Table &tbl_Filter_TD_12412741_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3845) AND ((d_year#3845 >= 1999) AND (d_year#3845 <= 2001))) AND isnotnull(d_date_sk#3839)))
    // Input: ListBuffer(d_date_sk#3839, d_year#3845)
    // Output: ListBuffer(d_date_sk#3839)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13600448_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3845 = tbl_SerializeFromObject_TD_13600448_input.getInt32(i, 1);
        int32_t _d_date_sk3839 = tbl_SerializeFromObject_TD_13600448_input.getInt32(i, 0);
        if (((_d_year3845!= 0) && ((_d_year3845 >= 1999) && (_d_year3845 <= 2001))) && (_d_date_sk3839!= 0)) {
            int32_t _d_date_sk3839_t = tbl_SerializeFromObject_TD_13600448_input.getInt32(i, 0);
            tbl_Filter_TD_12412741_output.setInt32(r, 0, _d_date_sk3839_t);
            r++;
        }
    }
    tbl_Filter_TD_12412741_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12412741_output #Row: " << tbl_Filter_TD_12412741_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12233294(Table &tbl_SerializeFromObject_TD_13738389_input, Table &tbl_Filter_TD_12233294_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ws_sold_date_sk#3805))
    // Input: ListBuffer(ws_sold_date_sk#3805, ws_quantity#3823, ws_list_price#3825)
    // Output: ListBuffer(ws_sold_date_sk#3805, ws_quantity#3823, ws_list_price#3825)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13738389_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_sold_date_sk3805 = tbl_SerializeFromObject_TD_13738389_input.getInt32(i, 0);
        if (_ws_sold_date_sk3805!= 0) {
            int32_t _ws_sold_date_sk3805_t = tbl_SerializeFromObject_TD_13738389_input.getInt32(i, 0);
            tbl_Filter_TD_12233294_output.setInt32(r, 0, _ws_sold_date_sk3805_t);
            int32_t _ws_quantity3823_t = tbl_SerializeFromObject_TD_13738389_input.getInt32(i, 1);
            tbl_Filter_TD_12233294_output.setInt32(r, 1, _ws_quantity3823_t);
            int64_t _ws_list_price3825_t = tbl_SerializeFromObject_TD_13738389_input.getInt64(i, 2);
            tbl_Filter_TD_12233294_output.setInt64(r, 2, _ws_list_price3825_t);
            r++;
        }
    }
    tbl_Filter_TD_12233294_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12233294_output #Row: " << tbl_Filter_TD_12233294_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12845654(Table &tbl_SerializeFromObject_TD_13317537_input, Table &tbl_Filter_TD_12845654_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3783) AND ((d_year#3783 >= 1999) AND (d_year#3783 <= 2001))) AND isnotnull(d_date_sk#3777)))
    // Input: ListBuffer(d_date_sk#3777, d_year#3783)
    // Output: ListBuffer(d_date_sk#3777)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13317537_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3783 = tbl_SerializeFromObject_TD_13317537_input.getInt32(i, 1);
        int32_t _d_date_sk3777 = tbl_SerializeFromObject_TD_13317537_input.getInt32(i, 0);
        if (((_d_year3783!= 0) && ((_d_year3783 >= 1999) && (_d_year3783 <= 2001))) && (_d_date_sk3777!= 0)) {
            int32_t _d_date_sk3777_t = tbl_SerializeFromObject_TD_13317537_input.getInt32(i, 0);
            tbl_Filter_TD_12845654_output.setInt32(r, 0, _d_date_sk3777_t);
            r++;
        }
    }
    tbl_Filter_TD_12845654_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12845654_output #Row: " << tbl_Filter_TD_12845654_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12532106(Table &tbl_SerializeFromObject_TD_13318292_input, Table &tbl_Filter_TD_12532106_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(cs_sold_date_sk#3743))
    // Input: ListBuffer(cs_sold_date_sk#3743, cs_quantity#3761, cs_list_price#3763)
    // Output: ListBuffer(cs_sold_date_sk#3743, cs_quantity#3761, cs_list_price#3763)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13318292_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_sold_date_sk3743 = tbl_SerializeFromObject_TD_13318292_input.getInt32(i, 0);
        if (_cs_sold_date_sk3743!= 0) {
            int32_t _cs_sold_date_sk3743_t = tbl_SerializeFromObject_TD_13318292_input.getInt32(i, 0);
            tbl_Filter_TD_12532106_output.setInt32(r, 0, _cs_sold_date_sk3743_t);
            int32_t _cs_quantity3761_t = tbl_SerializeFromObject_TD_13318292_input.getInt32(i, 1);
            tbl_Filter_TD_12532106_output.setInt32(r, 1, _cs_quantity3761_t);
            int64_t _cs_list_price3763_t = tbl_SerializeFromObject_TD_13318292_input.getInt64(i, 2);
            tbl_Filter_TD_12532106_output.setInt64(r, 2, _cs_list_price3763_t);
            r++;
        }
    }
    tbl_Filter_TD_12532106_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12532106_output #Row: " << tbl_Filter_TD_12532106_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12444102(Table &tbl_SerializeFromObject_TD_13238644_input, Table &tbl_Filter_TD_12444102_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3721) AND ((d_year#3721 >= 1999) AND (d_year#3721 <= 2001))) AND isnotnull(d_date_sk#3715)))
    // Input: ListBuffer(d_date_sk#3715, d_year#3721)
    // Output: ListBuffer(d_date_sk#3715)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13238644_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3721 = tbl_SerializeFromObject_TD_13238644_input.getInt32(i, 1);
        int32_t _d_date_sk3715 = tbl_SerializeFromObject_TD_13238644_input.getInt32(i, 0);
        if (((_d_year3721!= 0) && ((_d_year3721 >= 1999) && (_d_year3721 <= 2001))) && (_d_date_sk3715!= 0)) {
            int32_t _d_date_sk3715_t = tbl_SerializeFromObject_TD_13238644_input.getInt32(i, 0);
            tbl_Filter_TD_12444102_output.setInt32(r, 0, _d_date_sk3715_t);
            r++;
        }
    }
    tbl_Filter_TD_12444102_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12444102_output #Row: " << tbl_Filter_TD_12444102_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12232366(Table &tbl_SerializeFromObject_TD_13811252_input, Table &tbl_Filter_TD_12232366_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ss_sold_date_sk#3692))
    // Input: ListBuffer(ss_sold_date_sk#3692, ss_quantity#3702, ss_list_price#3704)
    // Output: ListBuffer(ss_sold_date_sk#3692, ss_quantity#3702, ss_list_price#3704)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13811252_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk3692 = tbl_SerializeFromObject_TD_13811252_input.getInt32(i, 0);
        if (_ss_sold_date_sk3692!= 0) {
            int32_t _ss_sold_date_sk3692_t = tbl_SerializeFromObject_TD_13811252_input.getInt32(i, 0);
            tbl_Filter_TD_12232366_output.setInt32(r, 0, _ss_sold_date_sk3692_t);
            int32_t _ss_quantity3702_t = tbl_SerializeFromObject_TD_13811252_input.getInt32(i, 1);
            tbl_Filter_TD_12232366_output.setInt32(r, 1, _ss_quantity3702_t);
            int64_t _ss_list_price3704_t = tbl_SerializeFromObject_TD_13811252_input.getInt64(i, 2);
            tbl_Filter_TD_12232366_output.setInt64(r, 2, _ss_list_price3704_t);
            r++;
        }
    }
    tbl_Filter_TD_12232366_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12232366_output #Row: " << tbl_Filter_TD_12232366_output.getNumRow() << std::endl;
}

void SW_Project_TD_12731159(Table &tbl_JOIN_INNER_TD_13970301_output, Table &tbl_Project_TD_12731159_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(i_item_sk#228 AS ss_item_sk#3562)
    // Input: ListBuffer(i_item_sk#228)
    // Output: ListBuffer(ss_item_sk#3562)
    int nrow1 = tbl_JOIN_INNER_TD_13970301_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk228 = tbl_JOIN_INNER_TD_13970301_output.getInt32(i, 0);
        int32_t _ss_item_sk3562 = _i_item_sk228;
        tbl_Project_TD_12731159_output.setInt32(i, 0, _ss_item_sk3562);
    }
    tbl_Project_TD_12731159_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_12731159_output #Row: " << tbl_Project_TD_12731159_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12203568(Table &tbl_SerializeFromObject_TD_13240654_input, Table &tbl_Filter_TD_12203568_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#3890))
    // Input: ListBuffer(i_item_sk#3890, i_brand_id#3897, i_class_id#3899, i_category_id#3901)
    // Output: ListBuffer(i_item_sk#3890, i_brand_id#3897, i_class_id#3899, i_category_id#3901)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13240654_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk3890 = tbl_SerializeFromObject_TD_13240654_input.getInt32(i, 0);
        if (_i_item_sk3890!= 0) {
            int32_t _i_item_sk3890_t = tbl_SerializeFromObject_TD_13240654_input.getInt32(i, 0);
            tbl_Filter_TD_12203568_output.setInt32(r, 0, _i_item_sk3890_t);
            int32_t _i_brand_id3897_t = tbl_SerializeFromObject_TD_13240654_input.getInt32(i, 1);
            tbl_Filter_TD_12203568_output.setInt32(r, 1, _i_brand_id3897_t);
            int32_t _i_class_id3899_t = tbl_SerializeFromObject_TD_13240654_input.getInt32(i, 2);
            tbl_Filter_TD_12203568_output.setInt32(r, 2, _i_class_id3899_t);
            int32_t _i_category_id3901_t = tbl_SerializeFromObject_TD_13240654_input.getInt32(i, 3);
            tbl_Filter_TD_12203568_output.setInt32(r, 3, _i_category_id3901_t);
            r++;
        }
    }
    tbl_Filter_TD_12203568_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12203568_output #Row: " << tbl_Filter_TD_12203568_output.getNumRow() << std::endl;
}

void SW_Project_TD_12766769(Table &tbl_JOIN_INNER_TD_13718401_output, Table &tbl_Project_TD_12766769_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(i_item_sk#228 AS ss_item_sk#3562)
    // Input: ListBuffer(i_item_sk#228)
    // Output: ListBuffer(ss_item_sk#3562)
    int nrow1 = tbl_JOIN_INNER_TD_13718401_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk228 = tbl_JOIN_INNER_TD_13718401_output.getInt32(i, 0);
        int32_t _ss_item_sk3562 = _i_item_sk228;
        tbl_Project_TD_12766769_output.setInt32(i, 0, _ss_item_sk3562);
    }
    tbl_Project_TD_12766769_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_12766769_output #Row: " << tbl_Project_TD_12766769_output.getNumRow() << std::endl;
}

void SW_Filter_TD_12453434(Table &tbl_SerializeFromObject_TD_13713550_input, Table &tbl_Filter_TD_12453434_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_item_sk#3869) AND isnotnull(ss_sold_date_sk#3867)))
    // Input: ListBuffer(ss_sold_date_sk#3867, ss_item_sk#3869, ss_quantity#3877, ss_list_price#3879)
    // Output: ListBuffer(ss_sold_date_sk#3867, ss_item_sk#3869, ss_quantity#3877, ss_list_price#3879)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_13713550_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_item_sk3869 = tbl_SerializeFromObject_TD_13713550_input.getInt32(i, 1);
        int32_t _ss_sold_date_sk3867 = tbl_SerializeFromObject_TD_13713550_input.getInt32(i, 0);
        if ((_ss_item_sk3869!= 0) && (_ss_sold_date_sk3867!= 0)) {
            int32_t _ss_sold_date_sk3867_t = tbl_SerializeFromObject_TD_13713550_input.getInt32(i, 0);
            tbl_Filter_TD_12453434_output.setInt32(r, 0, _ss_sold_date_sk3867_t);
            int32_t _ss_item_sk3869_t = tbl_SerializeFromObject_TD_13713550_input.getInt32(i, 1);
            tbl_Filter_TD_12453434_output.setInt32(r, 1, _ss_item_sk3869_t);
            int32_t _ss_quantity3877_t = tbl_SerializeFromObject_TD_13713550_input.getInt32(i, 2);
            tbl_Filter_TD_12453434_output.setInt32(r, 2, _ss_quantity3877_t);
            int64_t _ss_list_price3879_t = tbl_SerializeFromObject_TD_13713550_input.getInt64(i, 3);
            tbl_Filter_TD_12453434_output.setInt64(r, 3, _ss_list_price3879_t);
            r++;
        }
    }
    tbl_Filter_TD_12453434_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_12453434_output #Row: " << tbl_Filter_TD_12453434_output.getNumRow() << std::endl;
}
















void SW_Project_TD_10691020(Table &tbl_JOIN_INNER_TD_11193557_output, Table &tbl_Project_TD_10691020_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(ws_quantity#3823 AS quantity#3567, ws_list_price#3825 AS list_price#3568)
    // Input: ListBuffer(ws_quantity#3823, ws_list_price#3825)
    // Output: ListBuffer(quantity#3567, list_price#3568)
    int nrow1 = tbl_JOIN_INNER_TD_11193557_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_quantity3823 = tbl_JOIN_INNER_TD_11193557_output.getInt32(i, 0);
        int64_t _ws_list_price3825 = tbl_JOIN_INNER_TD_11193557_output.getInt64(i, 1);
        int32_t _quantity3567 = _ws_quantity3823;
        tbl_Project_TD_10691020_output.setInt32(i, 0, _quantity3567);
        int64_t _list_price3568 = _ws_list_price3825;
        tbl_Project_TD_10691020_output.setInt64(i, 1, _list_price3568);
    }
    tbl_Project_TD_10691020_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_10691020_output #Row: " << tbl_Project_TD_10691020_output.getNumRow() << std::endl;
}

void SW_Project_TD_10310564(Table &tbl_JOIN_INNER_TD_11224861_output, Table &tbl_Project_TD_10310564_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(cs_quantity#3761 AS quantity#3565, cs_list_price#3763 AS list_price#3566)
    // Input: ListBuffer(cs_quantity#3761, cs_list_price#3763)
    // Output: ListBuffer(quantity#3565, list_price#3566)
    int nrow1 = tbl_JOIN_INNER_TD_11224861_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_quantity3761 = tbl_JOIN_INNER_TD_11224861_output.getInt32(i, 0);
        int64_t _cs_list_price3763 = tbl_JOIN_INNER_TD_11224861_output.getInt64(i, 1);
        int32_t _quantity3565 = _cs_quantity3761;
        tbl_Project_TD_10310564_output.setInt32(i, 0, _quantity3565);
        int64_t _list_price3566 = _cs_list_price3763;
        tbl_Project_TD_10310564_output.setInt64(i, 1, _list_price3566);
    }
    tbl_Project_TD_10310564_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_10310564_output #Row: " << tbl_Project_TD_10310564_output.getNumRow() << std::endl;
}

void SW_Project_TD_10700623(Table &tbl_JOIN_INNER_TD_11715413_output, Table &tbl_Project_TD_10700623_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(ss_quantity#3702 AS quantity#3563, ss_list_price#3704 AS list_price#3564)
    // Input: ListBuffer(ss_quantity#3702, ss_list_price#3704)
    // Output: ListBuffer(quantity#3563, list_price#3564)
    int nrow1 = tbl_JOIN_INNER_TD_11715413_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_quantity3702 = tbl_JOIN_INNER_TD_11715413_output.getInt32(i, 0);
        int64_t _ss_list_price3704 = tbl_JOIN_INNER_TD_11715413_output.getInt64(i, 1);
        int32_t _quantity3563 = _ss_quantity3702;
        tbl_Project_TD_10700623_output.setInt32(i, 0, _quantity3563);
        int64_t _list_price3564 = _ss_list_price3704;
        tbl_Project_TD_10700623_output.setInt64(i, 1, _list_price3564);
    }
    tbl_Project_TD_10700623_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_10700623_output #Row: " << tbl_Project_TD_10700623_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10977537(Table &tbl_SerializeFromObject_TD_1136270_input, Table &tbl_Filter_TD_10977537_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_year#4086) AND isnotnull(d_moy#4088)) AND ((d_year#4086 = 2001) AND (d_moy#4088 = 11))) AND isnotnull(d_date_sk#4080)))
    // Input: ListBuffer(d_date_sk#4080, d_year#4086, d_moy#4088)
    // Output: ListBuffer(d_date_sk#4080)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1136270_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year4086 = tbl_SerializeFromObject_TD_1136270_input.getInt32(i, 1);
        int32_t _d_moy4088 = tbl_SerializeFromObject_TD_1136270_input.getInt32(i, 2);
        int32_t _d_date_sk4080 = tbl_SerializeFromObject_TD_1136270_input.getInt32(i, 0);
        if ((((_d_year4086!= 0) && (_d_moy4088!= 0)) && ((_d_year4086 == 2001) && (_d_moy4088 == 11))) && (_d_date_sk4080!= 0)) {
            int32_t _d_date_sk4080_t = tbl_SerializeFromObject_TD_1136270_input.getInt32(i, 0);
            tbl_Filter_TD_10977537_output.setInt32(r, 0, _d_date_sk4080_t);
            r++;
        }
    }
    tbl_Filter_TD_10977537_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10977537_output #Row: " << tbl_Filter_TD_10977537_output.getNumRow() << std::endl;
}


void SW_Project_TD_10491074(Table &tbl_JOIN_INNER_TD_11431867_output, Table &tbl_Project_TD_10491074_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(ws_quantity#3823 AS quantity#3567, ws_list_price#3825 AS list_price#3568)
    // Input: ListBuffer(ws_quantity#3823, ws_list_price#3825)
    // Output: ListBuffer(quantity#3567, list_price#3568)
    int nrow1 = tbl_JOIN_INNER_TD_11431867_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_quantity3823 = tbl_JOIN_INNER_TD_11431867_output.getInt32(i, 0);
        int64_t _ws_list_price3825 = tbl_JOIN_INNER_TD_11431867_output.getInt64(i, 1);
        int32_t _quantity3567 = _ws_quantity3823;
        tbl_Project_TD_10491074_output.setInt32(i, 0, _quantity3567);
        int64_t _list_price3568 = _ws_list_price3825;
        tbl_Project_TD_10491074_output.setInt64(i, 1, _list_price3568);
    }
    tbl_Project_TD_10491074_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_10491074_output #Row: " << tbl_Project_TD_10491074_output.getNumRow() << std::endl;
}

void SW_Project_TD_10444406(Table &tbl_JOIN_INNER_TD_11342139_output, Table &tbl_Project_TD_10444406_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(cs_quantity#3761 AS quantity#3565, cs_list_price#3763 AS list_price#3566)
    // Input: ListBuffer(cs_quantity#3761, cs_list_price#3763)
    // Output: ListBuffer(quantity#3565, list_price#3566)
    int nrow1 = tbl_JOIN_INNER_TD_11342139_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_quantity3761 = tbl_JOIN_INNER_TD_11342139_output.getInt32(i, 0);
        int64_t _cs_list_price3763 = tbl_JOIN_INNER_TD_11342139_output.getInt64(i, 1);
        int32_t _quantity3565 = _cs_quantity3761;
        tbl_Project_TD_10444406_output.setInt32(i, 0, _quantity3565);
        int64_t _list_price3566 = _cs_list_price3763;
        tbl_Project_TD_10444406_output.setInt64(i, 1, _list_price3566);
    }
    tbl_Project_TD_10444406_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_10444406_output #Row: " << tbl_Project_TD_10444406_output.getNumRow() << std::endl;
}

void SW_Project_TD_10421651(Table &tbl_JOIN_INNER_TD_11928461_output, Table &tbl_Project_TD_10421651_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(ss_quantity#3702 AS quantity#3563, ss_list_price#3704 AS list_price#3564)
    // Input: ListBuffer(ss_quantity#3702, ss_list_price#3704)
    // Output: ListBuffer(quantity#3563, list_price#3564)
    int nrow1 = tbl_JOIN_INNER_TD_11928461_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_quantity3702 = tbl_JOIN_INNER_TD_11928461_output.getInt32(i, 0);
        int64_t _ss_list_price3704 = tbl_JOIN_INNER_TD_11928461_output.getInt64(i, 1);
        int32_t _quantity3563 = _ss_quantity3702;
        tbl_Project_TD_10421651_output.setInt32(i, 0, _quantity3563);
        int64_t _list_price3564 = _ss_list_price3704;
        tbl_Project_TD_10421651_output.setInt64(i, 1, _list_price3564);
    }
    tbl_Project_TD_10421651_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_10421651_output #Row: " << tbl_Project_TD_10421651_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10882635(Table &tbl_SerializeFromObject_TD_11655055_input, Table &tbl_Filter_TD_10882635_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_year#4002) AND isnotnull(d_moy#4004)) AND ((d_year#4002 = 2001) AND (d_moy#4004 = 11))) AND isnotnull(d_date_sk#3996)))
    // Input: ListBuffer(d_date_sk#3996, d_year#4002, d_moy#4004)
    // Output: ListBuffer(d_date_sk#3996)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11655055_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year4002 = tbl_SerializeFromObject_TD_11655055_input.getInt32(i, 1);
        int32_t _d_moy4004 = tbl_SerializeFromObject_TD_11655055_input.getInt32(i, 2);
        int32_t _d_date_sk3996 = tbl_SerializeFromObject_TD_11655055_input.getInt32(i, 0);
        if ((((_d_year4002!= 0) && (_d_moy4004!= 0)) && ((_d_year4002 == 2001) && (_d_moy4004 == 11))) && (_d_date_sk3996!= 0)) {
            int32_t _d_date_sk3996_t = tbl_SerializeFromObject_TD_11655055_input.getInt32(i, 0);
            tbl_Filter_TD_10882635_output.setInt32(r, 0, _d_date_sk3996_t);
            r++;
        }
    }
    tbl_Filter_TD_10882635_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10882635_output #Row: " << tbl_Filter_TD_10882635_output.getNumRow() << std::endl;
}


void SW_Project_TD_107330(Table &tbl_JOIN_INNER_TD_11628615_output, Table &tbl_Project_TD_107330_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(ws_quantity#3823 AS quantity#3567, ws_list_price#3825 AS list_price#3568)
    // Input: ListBuffer(ws_quantity#3823, ws_list_price#3825)
    // Output: ListBuffer(quantity#3567, list_price#3568)
    int nrow1 = tbl_JOIN_INNER_TD_11628615_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_quantity3823 = tbl_JOIN_INNER_TD_11628615_output.getInt32(i, 0);
        int64_t _ws_list_price3825 = tbl_JOIN_INNER_TD_11628615_output.getInt64(i, 1);
        int32_t _quantity3567 = _ws_quantity3823;
        tbl_Project_TD_107330_output.setInt32(i, 0, _quantity3567);
        int64_t _list_price3568 = _ws_list_price3825;
        tbl_Project_TD_107330_output.setInt64(i, 1, _list_price3568);
    }
    tbl_Project_TD_107330_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_107330_output #Row: " << tbl_Project_TD_107330_output.getNumRow() << std::endl;
}

void SW_Project_TD_10483803(Table &tbl_JOIN_INNER_TD_11573385_output, Table &tbl_Project_TD_10483803_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(cs_quantity#3761 AS quantity#3565, cs_list_price#3763 AS list_price#3566)
    // Input: ListBuffer(cs_quantity#3761, cs_list_price#3763)
    // Output: ListBuffer(quantity#3565, list_price#3566)
    int nrow1 = tbl_JOIN_INNER_TD_11573385_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_quantity3761 = tbl_JOIN_INNER_TD_11573385_output.getInt32(i, 0);
        int64_t _cs_list_price3763 = tbl_JOIN_INNER_TD_11573385_output.getInt64(i, 1);
        int32_t _quantity3565 = _cs_quantity3761;
        tbl_Project_TD_10483803_output.setInt32(i, 0, _quantity3565);
        int64_t _list_price3566 = _cs_list_price3763;
        tbl_Project_TD_10483803_output.setInt64(i, 1, _list_price3566);
    }
    tbl_Project_TD_10483803_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_10483803_output #Row: " << tbl_Project_TD_10483803_output.getNumRow() << std::endl;
}

void SW_Project_TD_10854693(Table &tbl_JOIN_INNER_TD_11442545_output, Table &tbl_Project_TD_10854693_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(ss_quantity#3702 AS quantity#3563, ss_list_price#3704 AS list_price#3564)
    // Input: ListBuffer(ss_quantity#3702, ss_list_price#3704)
    // Output: ListBuffer(quantity#3563, list_price#3564)
    int nrow1 = tbl_JOIN_INNER_TD_11442545_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_quantity3702 = tbl_JOIN_INNER_TD_11442545_output.getInt32(i, 0);
        int64_t _ss_list_price3704 = tbl_JOIN_INNER_TD_11442545_output.getInt64(i, 1);
        int32_t _quantity3563 = _ss_quantity3702;
        tbl_Project_TD_10854693_output.setInt32(i, 0, _quantity3563);
        int64_t _list_price3564 = _ss_list_price3704;
        tbl_Project_TD_10854693_output.setInt64(i, 1, _list_price3564);
    }
    tbl_Project_TD_10854693_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_10854693_output #Row: " << tbl_Project_TD_10854693_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10836594(Table &tbl_SerializeFromObject_TD_11656695_input, Table &tbl_Filter_TD_10836594_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_year#3918) AND isnotnull(d_moy#3920)) AND ((d_year#3918 = 2001) AND (d_moy#3920 = 11))) AND isnotnull(d_date_sk#3912)))
    // Input: ListBuffer(d_date_sk#3912, d_year#3918, d_moy#3920)
    // Output: ListBuffer(d_date_sk#3912)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11656695_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3918 = tbl_SerializeFromObject_TD_11656695_input.getInt32(i, 1);
        int32_t _d_moy3920 = tbl_SerializeFromObject_TD_11656695_input.getInt32(i, 2);
        int32_t _d_date_sk3912 = tbl_SerializeFromObject_TD_11656695_input.getInt32(i, 0);
        if ((((_d_year3918!= 0) && (_d_moy3920!= 0)) && ((_d_year3918 == 2001) && (_d_moy3920 == 11))) && (_d_date_sk3912!= 0)) {
            int32_t _d_date_sk3912_t = tbl_SerializeFromObject_TD_11656695_input.getInt32(i, 0);
            tbl_Filter_TD_10836594_output.setInt32(r, 0, _d_date_sk3912_t);
            r++;
        }
    }
    tbl_Filter_TD_10836594_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10836594_output #Row: " << tbl_Filter_TD_10836594_output.getNumRow() << std::endl;
}


void SW_Union_TD_9474313(Table &tbl_Project_TD_10700623_output, Table &tbl_Project_TD_10310564_output, Table &tbl_Project_TD_10691020_output, Table &tbl_Union_TD_9474313_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Union
    // Operation: ListBuffer(List(UNION))
    // Output Table: ListBuffer(quantity#3563, list_price#3564)
    int r = 0;
    int row0 = tbl_Project_TD_10700623_output.getNumRow();
    for (int i = 0; i < row0; i++) {
        tbl_Union_TD_9474313_output.setInt32(r, 0, tbl_Project_TD_10700623_output.getInt32(i, 0));
        tbl_Union_TD_9474313_output.setInt32(r, 1, tbl_Project_TD_10700623_output.getInt64(i, 1));
        ++r;
    }
    int row1 = tbl_Project_TD_10310564_output.getNumRow();
    for (int i = 0; i < row1; i++) {
        tbl_Union_TD_9474313_output.setInt32(r, 0, tbl_Project_TD_10310564_output.getInt32(i, 0));
        tbl_Union_TD_9474313_output.setInt32(r, 1, tbl_Project_TD_10310564_output.getInt64(i, 1));
        ++r;
    }
    int row2 = tbl_Project_TD_10691020_output.getNumRow();
    for (int i = 0; i < row2; i++) {
        tbl_Union_TD_9474313_output.setInt32(r, 0, tbl_Project_TD_10691020_output.getInt32(i, 0));
        tbl_Union_TD_9474313_output.setInt32(r, 1, tbl_Project_TD_10691020_output.getInt64(i, 1));
        ++r;
    }
    tbl_Union_TD_9474313_output.setNumRow(r);
    std::cout << "tbl_Union_TD_9474313_output #Row: " << tbl_Union_TD_9474313_output.getNumRow() << std::endl;
}


void SW_Union_TD_995342(Table &tbl_Project_TD_10421651_output, Table &tbl_Project_TD_10444406_output, Table &tbl_Project_TD_10491074_output, Table &tbl_Union_TD_995342_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Union
    // Operation: ListBuffer(List(UNION))
    // Output Table: ListBuffer(quantity#3563, list_price#3564)
    int r = 0;
    int row0 = tbl_Project_TD_10421651_output.getNumRow();
    for (int i = 0; i < row0; i++) {
        tbl_Union_TD_995342_output.setInt32(r, 0, tbl_Project_TD_10421651_output.getInt32(i, 0));
        tbl_Union_TD_995342_output.setInt32(r, 1, tbl_Project_TD_10421651_output.getInt64(i, 1));
        ++r;
    }
    int row1 = tbl_Project_TD_10444406_output.getNumRow();
    for (int i = 0; i < row1; i++) {
        tbl_Union_TD_995342_output.setInt32(r, 0, tbl_Project_TD_10444406_output.getInt32(i, 0));
        tbl_Union_TD_995342_output.setInt32(r, 1, tbl_Project_TD_10444406_output.getInt64(i, 1));
        ++r;
    }
    int row2 = tbl_Project_TD_10491074_output.getNumRow();
    for (int i = 0; i < row2; i++) {
        tbl_Union_TD_995342_output.setInt32(r, 0, tbl_Project_TD_10491074_output.getInt32(i, 0));
        tbl_Union_TD_995342_output.setInt32(r, 1, tbl_Project_TD_10491074_output.getInt64(i, 1));
        ++r;
    }
    tbl_Union_TD_995342_output.setNumRow(r);
    std::cout << "tbl_Union_TD_995342_output #Row: " << tbl_Union_TD_995342_output.getNumRow() << std::endl;
}


void SW_Union_TD_9880851(Table &tbl_Project_TD_10854693_output, Table &tbl_Project_TD_10483803_output, Table &tbl_Project_TD_107330_output, Table &tbl_Union_TD_9880851_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Union
    // Operation: ListBuffer(List(UNION))
    // Output Table: ListBuffer(quantity#3563, list_price#3564)
    int r = 0;
    int row0 = tbl_Project_TD_10854693_output.getNumRow();
    for (int i = 0; i < row0; i++) {
        tbl_Union_TD_9880851_output.setInt32(r, 0, tbl_Project_TD_10854693_output.getInt32(i, 0));
        tbl_Union_TD_9880851_output.setInt32(r, 1, tbl_Project_TD_10854693_output.getInt64(i, 1));
        ++r;
    }
    int row1 = tbl_Project_TD_10483803_output.getNumRow();
    for (int i = 0; i < row1; i++) {
        tbl_Union_TD_9880851_output.setInt32(r, 0, tbl_Project_TD_10483803_output.getInt32(i, 0));
        tbl_Union_TD_9880851_output.setInt32(r, 1, tbl_Project_TD_10483803_output.getInt64(i, 1));
        ++r;
    }
    int row2 = tbl_Project_TD_107330_output.getNumRow();
    for (int i = 0; i < row2; i++) {
        tbl_Union_TD_9880851_output.setInt32(r, 0, tbl_Project_TD_107330_output.getInt32(i, 0));
        tbl_Union_TD_9880851_output.setInt32(r, 1, tbl_Project_TD_107330_output.getInt64(i, 1));
        ++r;
    }
    tbl_Union_TD_9880851_output.setNumRow(r);
    std::cout << "tbl_Union_TD_9880851_output #Row: " << tbl_Union_TD_9880851_output.getNumRow() << std::endl;
}


void SW_Aggregate_TD_8159324(Table &tbl_Union_TD_9474313_output, Table &tbl_Aggregate_TD_8159324_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(avg(CheckOverflow((promote_precision(cast(cast(quantity#3563 as decimal(10,0)) as decimal(12,2))) * promote_precision(cast(list_price#3564 as decimal(12,2)))), DecimalType(18,2), true)) AS average_sales#3569)
    // Input: ListBuffer(quantity#3563, list_price#3564)
    // Output: ListBuffer(average_sales#3569)
    int64_t avg_0 = 0;
    int nrow1 = tbl_Union_TD_9474313_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _quantity3563 = tbl_Union_TD_9474313_output.getInt32(i, 0);
        int64_t _list_price3564 = tbl_Union_TD_9474313_output.getInt64(i, 1);
        int64_t _average_sales3569_avg_0 = (_quantity3563 * _list_price3564);
        avg_0 = (avg_0 + _average_sales3569_avg_0);
    }
    int r = 0;
    int64_t _average_sales3569 = avg_0 / nrow1;
    tbl_Aggregate_TD_8159324_output.setInt64(r++, 0, _average_sales3569);
    tbl_Aggregate_TD_8159324_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_8159324_output #Row: " << tbl_Aggregate_TD_8159324_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_8510274_consolidate(Table &tbl_Aggregate_TD_8510274_output_preprocess, Table &tbl_Aggregate_TD_8510274_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_8510274_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _i_brand_id4065 = tbl_Aggregate_TD_8510274_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_8510274_output.setInt32(r, 0, _i_brand_id4065);
        int32_t _i_class_id4067 = tbl_Aggregate_TD_8510274_output_preprocess.getInt32(r, 6);
        tbl_Aggregate_TD_8510274_output.setInt32(r, 1, _i_class_id4067);
        int32_t _i_category_id4069 = tbl_Aggregate_TD_8510274_output_preprocess.getInt32(r, 5);
        tbl_Aggregate_TD_8510274_output.setInt32(r, 2, _i_category_id4069);
        int64_t _sales3555 = tbl_Aggregate_TD_8510274_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_8510274_output.setInt64(r, 3, _sales3555);
        int32_t _number_sales3556L = tbl_Aggregate_TD_8510274_output_preprocess.getInt32(r, 1);
        tbl_Aggregate_TD_8510274_output.setInt32(r, 4, _number_sales3556L);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_8510274_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_8510274_output #Row: " << tbl_Aggregate_TD_8510274_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_8662688(Table &tbl_Union_TD_995342_output, Table &tbl_Aggregate_TD_8662688_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(avg(CheckOverflow((promote_precision(cast(cast(quantity#3563 as decimal(10,0)) as decimal(12,2))) * promote_precision(cast(list_price#3564 as decimal(12,2)))), DecimalType(18,2), true)) AS average_sales#3569)
    // Input: ListBuffer(quantity#3563, list_price#3564)
    // Output: ListBuffer(average_sales#3569)
    int64_t avg_0 = 0;
    int nrow1 = tbl_Union_TD_995342_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _quantity3563 = tbl_Union_TD_995342_output.getInt32(i, 0);
        int64_t _list_price3564 = tbl_Union_TD_995342_output.getInt64(i, 1);
        int64_t _average_sales3569_avg_0 = (_quantity3563 * _list_price3564);
        avg_0 = (avg_0 + _average_sales3569_avg_0);
    }
    int r = 0;
    int64_t _average_sales3569 = avg_0 / nrow1;
    tbl_Aggregate_TD_8662688_output.setInt64(r++, 0, _average_sales3569);
    tbl_Aggregate_TD_8662688_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_8662688_output #Row: " << tbl_Aggregate_TD_8662688_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_8502236_consolidate(Table &tbl_Aggregate_TD_8502236_output_preprocess, Table &tbl_Aggregate_TD_8502236_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_8502236_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _i_brand_id3981 = tbl_Aggregate_TD_8502236_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_8502236_output.setInt32(r, 0, _i_brand_id3981);
        int32_t _i_class_id3983 = tbl_Aggregate_TD_8502236_output_preprocess.getInt32(r, 6);
        tbl_Aggregate_TD_8502236_output.setInt32(r, 1, _i_class_id3983);
        int32_t _i_category_id3985 = tbl_Aggregate_TD_8502236_output_preprocess.getInt32(r, 5);
        tbl_Aggregate_TD_8502236_output.setInt32(r, 2, _i_category_id3985);
        int64_t _sales3550 = tbl_Aggregate_TD_8502236_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_8502236_output.setInt64(r, 3, _sales3550);
        int32_t _number_sales3551L = tbl_Aggregate_TD_8502236_output_preprocess.getInt32(r, 1);
        tbl_Aggregate_TD_8502236_output.setInt32(r, 4, _number_sales3551L);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_8502236_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_8502236_output #Row: " << tbl_Aggregate_TD_8502236_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_8535179(Table &tbl_Union_TD_9880851_output, Table &tbl_Aggregate_TD_8535179_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(avg(CheckOverflow((promote_precision(cast(cast(quantity#3563 as decimal(10,0)) as decimal(12,2))) * promote_precision(cast(list_price#3564 as decimal(12,2)))), DecimalType(18,2), true)) AS average_sales#3569)
    // Input: ListBuffer(quantity#3563, list_price#3564)
    // Output: ListBuffer(average_sales#3569)
    int64_t avg_0 = 0;
    int nrow1 = tbl_Union_TD_9880851_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _quantity3563 = tbl_Union_TD_9880851_output.getInt32(i, 0);
        int64_t _list_price3564 = tbl_Union_TD_9880851_output.getInt64(i, 1);
        int64_t _average_sales3569_avg_0 = (_quantity3563 * _list_price3564);
        avg_0 = (avg_0 + _average_sales3569_avg_0);
    }
    int r = 0;
    int64_t _average_sales3569 = avg_0 / nrow1;
    tbl_Aggregate_TD_8535179_output.setInt64(r++, 0, _average_sales3569);
    tbl_Aggregate_TD_8535179_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_8535179_output #Row: " << tbl_Aggregate_TD_8535179_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_8700013_consolidate(Table &tbl_Aggregate_TD_8700013_output_preprocess, Table &tbl_Aggregate_TD_8700013_output) {
    int nrow = 0;
    int nrow_p = tbl_Aggregate_TD_8700013_output_preprocess.getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _i_brand_id3897 = tbl_Aggregate_TD_8700013_output_preprocess.getInt32(r, 7);
        tbl_Aggregate_TD_8700013_output.setInt32(r, 0, _i_brand_id3897);
        int32_t _i_class_id3899 = tbl_Aggregate_TD_8700013_output_preprocess.getInt32(r, 6);
        tbl_Aggregate_TD_8700013_output.setInt32(r, 1, _i_class_id3899);
        int32_t _i_category_id3901 = tbl_Aggregate_TD_8700013_output_preprocess.getInt32(r, 5);
        tbl_Aggregate_TD_8700013_output.setInt32(r, 2, _i_category_id3901);
        int64_t _sales3545 = tbl_Aggregate_TD_8700013_output_preprocess.combineInt64(r, 8, 0);
        tbl_Aggregate_TD_8700013_output.setInt64(r, 3, _sales3545);
        int32_t _number_sales3546L = tbl_Aggregate_TD_8700013_output_preprocess.getInt32(r, 1);
        tbl_Aggregate_TD_8700013_output.setInt32(r, 4, _number_sales3546L);
    }
    nrow += nrow_p;
    tbl_Aggregate_TD_8700013_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_8700013_output #Row: " << tbl_Aggregate_TD_8700013_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7291623(Table &tbl_Aggregate_TD_8510274_output, Table &tbl_Aggregate_TD_8159324_output, Table &tbl_Filter_TD_7291623_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(sales#3555) AND (cast(sales#3555 as decimal(32,6)) > cast(scalar-subquery#3558 [] as decimal(32,6)))))
    // Input: ListBuffer(i_brand_id#4065, i_class_id#4067, i_category_id#4069, sales#3555, number_sales#3556L)
    // Output: ListBuffer(sales#3555, number_sales#3556L, i_brand_id#4065, i_class_id#4067, i_category_id#4069)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_8510274_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sales3555 = tbl_Aggregate_TD_8510274_output.getInt64(i, 3);
        if ((_sales3555!= 0) && (_sales3555 > tbl_Aggregate_TD_8159324_output.getInt64(0, 0))) {
            int64_t _sales3555_t = tbl_Aggregate_TD_8510274_output.getInt64(i, 3);
            tbl_Filter_TD_7291623_output.setInt64(r, 0, _sales3555_t);
            int64_t _number_sales3556L_t = tbl_Aggregate_TD_8510274_output.getInt64(i, 4);
            tbl_Filter_TD_7291623_output.setInt64(r, 1, _number_sales3556L_t);
            int32_t _i_brand_id4065_t = tbl_Aggregate_TD_8510274_output.getInt32(i, 0);
            tbl_Filter_TD_7291623_output.setInt32(r, 2, _i_brand_id4065_t);
            int32_t _i_class_id4067_t = tbl_Aggregate_TD_8510274_output.getInt32(i, 1);
            tbl_Filter_TD_7291623_output.setInt32(r, 3, _i_class_id4067_t);
            int32_t _i_category_id4069_t = tbl_Aggregate_TD_8510274_output.getInt32(i, 2);
            tbl_Filter_TD_7291623_output.setInt32(r, 4, _i_category_id4069_t);
            r++;
        }
    }
    tbl_Filter_TD_7291623_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7291623_output #Row: " << tbl_Filter_TD_7291623_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7337245(Table &tbl_Aggregate_TD_8502236_output, Table &tbl_Aggregate_TD_8662688_output, Table &tbl_Filter_TD_7337245_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(sales#3550) AND (cast(sales#3550 as decimal(32,6)) > cast(scalar-subquery#3553 [] as decimal(32,6)))))
    // Input: ListBuffer(i_brand_id#3981, i_class_id#3983, i_category_id#3985, sales#3550, number_sales#3551L)
    // Output: ListBuffer(sales#3550, number_sales#3551L, i_brand_id#3981, i_class_id#3983, i_category_id#3985)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_8502236_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sales3550 = tbl_Aggregate_TD_8502236_output.getInt64(i, 3);
        if ((_sales3550!= 0) && (_sales3550 > tbl_Aggregate_TD_8662688_output.getInt64(0, 0))) {
            int64_t _sales3550_t = tbl_Aggregate_TD_8502236_output.getInt64(i, 3);
            tbl_Filter_TD_7337245_output.setInt64(r, 0, _sales3550_t);
            int64_t _number_sales3551L_t = tbl_Aggregate_TD_8502236_output.getInt64(i, 4);
            tbl_Filter_TD_7337245_output.setInt64(r, 1, _number_sales3551L_t);
            int32_t _i_brand_id3981_t = tbl_Aggregate_TD_8502236_output.getInt32(i, 0);
            tbl_Filter_TD_7337245_output.setInt32(r, 2, _i_brand_id3981_t);
            int32_t _i_class_id3983_t = tbl_Aggregate_TD_8502236_output.getInt32(i, 1);
            tbl_Filter_TD_7337245_output.setInt32(r, 3, _i_class_id3983_t);
            int32_t _i_category_id3985_t = tbl_Aggregate_TD_8502236_output.getInt32(i, 2);
            tbl_Filter_TD_7337245_output.setInt32(r, 4, _i_category_id3985_t);
            r++;
        }
    }
    tbl_Filter_TD_7337245_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7337245_output #Row: " << tbl_Filter_TD_7337245_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7684612(Table &tbl_Aggregate_TD_8700013_output, Table &tbl_Aggregate_TD_8535179_output, Table &tbl_Filter_TD_7684612_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(sales#3545) AND (cast(sales#3545 as decimal(32,6)) > cast(scalar-subquery#3548 [] as decimal(32,6)))))
    // Input: ListBuffer(i_brand_id#3897, i_class_id#3899, i_category_id#3901, sales#3545, number_sales#3546L)
    // Output: ListBuffer(sales#3545, number_sales#3546L, i_brand_id#3897, i_class_id#3899, i_category_id#3901)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_8700013_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sales3545 = tbl_Aggregate_TD_8700013_output.getInt64(i, 3);
        if ((_sales3545!= 0) && (_sales3545 > tbl_Aggregate_TD_8535179_output.getInt64(0, 0))) {
            int64_t _sales3545_t = tbl_Aggregate_TD_8700013_output.getInt64(i, 3);
            tbl_Filter_TD_7684612_output.setInt64(r, 0, _sales3545_t);
            int64_t _number_sales3546L_t = tbl_Aggregate_TD_8700013_output.getInt64(i, 4);
            tbl_Filter_TD_7684612_output.setInt64(r, 1, _number_sales3546L_t);
            int32_t _i_brand_id3897_t = tbl_Aggregate_TD_8700013_output.getInt32(i, 0);
            tbl_Filter_TD_7684612_output.setInt32(r, 2, _i_brand_id3897_t);
            int32_t _i_class_id3899_t = tbl_Aggregate_TD_8700013_output.getInt32(i, 1);
            tbl_Filter_TD_7684612_output.setInt32(r, 3, _i_class_id3899_t);
            int32_t _i_category_id3901_t = tbl_Aggregate_TD_8700013_output.getInt32(i, 2);
            tbl_Filter_TD_7684612_output.setInt32(r, 4, _i_category_id3901_t);
            r++;
        }
    }
    tbl_Filter_TD_7684612_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7684612_output #Row: " << tbl_Filter_TD_7684612_output.getNumRow() << std::endl;
}

void SW_Project_TD_6774559(Table &tbl_Filter_TD_7291623_output, Table &tbl_Project_TD_6774559_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(web AS channel#4540)
    // Input: ListBuffer(sales#3555, number_sales#3556L, i_brand_id#4065, i_class_id#4067, i_category_id#4069)
    // Output: ListBuffer(sales#3555, number_sales#3556L, channel#4540, i_brand_id#4065, i_class_id#4067, i_category_id#4069)
    int nrow1 = tbl_Filter_TD_7291623_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sales3555 = tbl_Filter_TD_7291623_output.getInt64(i, 0);
        int64_t _number_sales3556L = tbl_Filter_TD_7291623_output.getInt64(i, 1);
        int32_t _i_brand_id4065 = tbl_Filter_TD_7291623_output.getInt32(i, 2);
        int32_t _i_class_id4067 = tbl_Filter_TD_7291623_output.getInt32(i, 3);
        int32_t _i_category_id4069 = tbl_Filter_TD_7291623_output.getInt32(i, 4);
        std::string _channel4540_str = "web";
        std::array<char, TPCDS_READ_MAX + 1> _channel4540{};
        memcpy(_channel4540.data(), _channel4540_str.data(), (_channel4540_str).length());
        tbl_Project_TD_6774559_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 2, _channel4540);
        tbl_Project_TD_6774559_output.setInt64(i, 0, _sales3555);
        tbl_Project_TD_6774559_output.setInt64(i, 1, _number_sales3556L);
        tbl_Project_TD_6774559_output.setInt32(i, 3, _i_brand_id4065);
        tbl_Project_TD_6774559_output.setInt32(i, 4, _i_class_id4067);
        tbl_Project_TD_6774559_output.setInt32(i, 5, _i_category_id4069);
    }
    tbl_Project_TD_6774559_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_6774559_output #Row: " << tbl_Project_TD_6774559_output.getNumRow() << std::endl;
}

void SW_Project_TD_6966471(Table &tbl_Filter_TD_7337245_output, Table &tbl_Project_TD_6966471_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(catalog AS channel#4536)
    // Input: ListBuffer(sales#3550, number_sales#3551L, i_brand_id#3981, i_class_id#3983, i_category_id#3985)
    // Output: ListBuffer(sales#3550, number_sales#3551L, channel#4536, i_brand_id#3981, i_class_id#3983, i_category_id#3985)
    int nrow1 = tbl_Filter_TD_7337245_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sales3550 = tbl_Filter_TD_7337245_output.getInt64(i, 0);
        int64_t _number_sales3551L = tbl_Filter_TD_7337245_output.getInt64(i, 1);
        int32_t _i_brand_id3981 = tbl_Filter_TD_7337245_output.getInt32(i, 2);
        int32_t _i_class_id3983 = tbl_Filter_TD_7337245_output.getInt32(i, 3);
        int32_t _i_category_id3985 = tbl_Filter_TD_7337245_output.getInt32(i, 4);
        std::string _channel4536_str = "catalog";
        std::array<char, TPCDS_READ_MAX + 1> _channel4536{};
        memcpy(_channel4536.data(), _channel4536_str.data(), (_channel4536_str).length());
        tbl_Project_TD_6966471_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 2, _channel4536);
        tbl_Project_TD_6966471_output.setInt64(i, 0, _sales3550);
        tbl_Project_TD_6966471_output.setInt64(i, 1, _number_sales3551L);
        tbl_Project_TD_6966471_output.setInt32(i, 3, _i_brand_id3981);
        tbl_Project_TD_6966471_output.setInt32(i, 4, _i_class_id3983);
        tbl_Project_TD_6966471_output.setInt32(i, 5, _i_category_id3985);
    }
    tbl_Project_TD_6966471_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_6966471_output #Row: " << tbl_Project_TD_6966471_output.getNumRow() << std::endl;
}

void SW_Project_TD_6999961(Table &tbl_Filter_TD_7684612_output, Table &tbl_Project_TD_6999961_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(store AS channel#4134)
    // Input: ListBuffer(sales#3545, number_sales#3546L, i_brand_id#3897, i_class_id#3899, i_category_id#3901)
    // Output: ListBuffer(sales#3545, number_sales#3546L, channel#4134, i_brand_id#3897, i_class_id#3899, i_category_id#3901)
    int nrow1 = tbl_Filter_TD_7684612_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sales3545 = tbl_Filter_TD_7684612_output.getInt64(i, 0);
        int64_t _number_sales3546L = tbl_Filter_TD_7684612_output.getInt64(i, 1);
        int32_t _i_brand_id3897 = tbl_Filter_TD_7684612_output.getInt32(i, 2);
        int32_t _i_class_id3899 = tbl_Filter_TD_7684612_output.getInt32(i, 3);
        int32_t _i_category_id3901 = tbl_Filter_TD_7684612_output.getInt32(i, 4);
        std::string _channel4134_str = "store";
        std::array<char, TPCDS_READ_MAX + 1> _channel4134{};
        memcpy(_channel4134.data(), _channel4134_str.data(), (_channel4134_str).length());
        tbl_Project_TD_6999961_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 2, _channel4134);
        tbl_Project_TD_6999961_output.setInt64(i, 0, _sales3545);
        tbl_Project_TD_6999961_output.setInt64(i, 1, _number_sales3546L);
        tbl_Project_TD_6999961_output.setInt32(i, 3, _i_brand_id3897);
        tbl_Project_TD_6999961_output.setInt32(i, 4, _i_class_id3899);
        tbl_Project_TD_6999961_output.setInt32(i, 5, _i_category_id3901);
    }
    tbl_Project_TD_6999961_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_6999961_output #Row: " << tbl_Project_TD_6999961_output.getNumRow() << std::endl;
}

void SW_Union_TD_5503078(Table &tbl_Project_TD_6999961_output, Table &tbl_Project_TD_6966471_output, Table &tbl_Project_TD_6774559_output, Table &tbl_Union_TD_5503078_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Union
    // Operation: ListBuffer(List(UNION))
    // Output Table: ListBuffer(sales#3545, number_sales#3546L, channel#4134, i_brand_id#3897, i_class_id#3899, i_category_id#3901)
    int r = 0;
    int row0 = tbl_Project_TD_6999961_output.getNumRow();
    for (int i = 0; i < row0; i++) {
        tbl_Union_TD_5503078_output.setInt32(r, 0, tbl_Project_TD_6999961_output.getInt64(i, 0));
        tbl_Union_TD_5503078_output.setInt32(r, 1, tbl_Project_TD_6999961_output.getInt64(i, 1));
        std::array<char, TPCDS_READ_MAX + 1> _channel4134_n = tbl_Union_TD_5503078_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_Union_TD_5503078_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _channel4134_n);
        tbl_Union_TD_5503078_output.setInt32(r, 3, tbl_Project_TD_6999961_output.getInt32(i, 3));
        tbl_Union_TD_5503078_output.setInt32(r, 4, tbl_Project_TD_6999961_output.getInt32(i, 4));
        tbl_Union_TD_5503078_output.setInt32(r, 5, tbl_Project_TD_6999961_output.getInt32(i, 5));
        ++r;
    }
    int row1 = tbl_Project_TD_6966471_output.getNumRow();
    for (int i = 0; i < row1; i++) {
        tbl_Union_TD_5503078_output.setInt32(r, 0, tbl_Project_TD_6966471_output.getInt64(i, 0));
        tbl_Union_TD_5503078_output.setInt32(r, 1, tbl_Project_TD_6966471_output.getInt64(i, 1));
        std::array<char, TPCDS_READ_MAX + 1> _channel4536_n = tbl_Union_TD_5503078_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_Union_TD_5503078_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _channel4536_n);
        tbl_Union_TD_5503078_output.setInt32(r, 3, tbl_Project_TD_6966471_output.getInt32(i, 3));
        tbl_Union_TD_5503078_output.setInt32(r, 4, tbl_Project_TD_6966471_output.getInt32(i, 4));
        tbl_Union_TD_5503078_output.setInt32(r, 5, tbl_Project_TD_6966471_output.getInt32(i, 5));
        ++r;
    }
    int row2 = tbl_Project_TD_6774559_output.getNumRow();
    for (int i = 0; i < row2; i++) {
        tbl_Union_TD_5503078_output.setInt32(r, 0, tbl_Project_TD_6774559_output.getInt64(i, 0));
        tbl_Union_TD_5503078_output.setInt32(r, 1, tbl_Project_TD_6774559_output.getInt64(i, 1));
        std::array<char, TPCDS_READ_MAX + 1> _channel4540_n = tbl_Union_TD_5503078_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_Union_TD_5503078_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _channel4540_n);
        tbl_Union_TD_5503078_output.setInt32(r, 3, tbl_Project_TD_6774559_output.getInt32(i, 3));
        tbl_Union_TD_5503078_output.setInt32(r, 4, tbl_Project_TD_6774559_output.getInt32(i, 4));
        tbl_Union_TD_5503078_output.setInt32(r, 5, tbl_Project_TD_6774559_output.getInt32(i, 5));
        ++r;
    }
    tbl_Union_TD_5503078_output.setNumRow(r);
    std::cout << "tbl_Union_TD_5503078_output #Row: " << tbl_Union_TD_5503078_output.getNumRow() << std::endl;
}

void SW_Expand_TD_4952896(Table &tbl_Union_TD_5503078_output, Table &tbl_Expand_TD_4952896_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Expand
    // Operation: ListBuffer(Expand)
    // Input: ListBuffer(sales#3545, number_sales#3546L, channel#4134, i_brand_id#3897, i_class_id#3899, i_category_id#3901)
    // Output: ListBuffer(sales#3545, number_sales#3546L, channel#4139, i_brand_id#4140, i_class_id#4141, i_category_id#4142, spark_grouping_id#4138L)
    std::cout << "tbl_Expand_TD_4952896_output #Row: " << tbl_Expand_TD_4952896_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_3511232_key {
    std::string _channel4139;
    int32_t _i_brand_id4140;
    int32_t _i_class_id4141;
    int32_t _i_category_id4142;
    int64_t _spark_grouping_id4138L;
    bool operator==(const SW_Aggregate_TD_3511232_key& other) const { return (_channel4139 == other._channel4139) && (_i_brand_id4140 == other._i_brand_id4140) && (_i_class_id4141 == other._i_class_id4141) && (_i_category_id4142 == other._i_category_id4142) && (_spark_grouping_id4138L == other._spark_grouping_id4138L); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_3511232_key> {
    std::size_t operator() (const SW_Aggregate_TD_3511232_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._channel4139)) + (hash<int32_t>()(k._i_brand_id4140)) + (hash<int32_t>()(k._i_class_id4141)) + (hash<int32_t>()(k._i_category_id4142)) + (hash<int64_t>()(k._spark_grouping_id4138L));
    }
};
}
struct SW_Aggregate_TD_3511232_payload {
    int64_t _sumsales4129_sum_0;
    int64_t _sumnumber_sales4130L_sum_1;
};
void SW_Aggregate_TD_3511232(Table &tbl_Expand_TD_4952896_output, Table &tbl_Aggregate_TD_3511232_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(channel#4139, i_brand_id#4140, i_class_id#4141, i_category_id#4142, spark_grouping_id#4138L, sum(sales#3545) AS sum(sales)#4129, sum(number_sales#3546L) AS sum(number_sales)#4130L)
    // Input: ListBuffer(sales#3545, number_sales#3546L, channel#4139, i_brand_id#4140, i_class_id#4141, i_category_id#4142, spark_grouping_id#4138L)
    // Output: ListBuffer(channel#4139, i_brand_id#4140, i_class_id#4141, i_category_id#4142, sum(sales)#4129, sum(number_sales)#4130L)
    std::unordered_map<SW_Aggregate_TD_3511232_key, SW_Aggregate_TD_3511232_payload> ht1;
    int nrow1 = tbl_Expand_TD_4952896_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sales3545 = tbl_Expand_TD_4952896_output.getInt64(i, 0);
        int64_t _number_sales3546L = tbl_Expand_TD_4952896_output.getInt64(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _channel4139 = tbl_Expand_TD_4952896_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        int32_t _i_brand_id4140 = tbl_Expand_TD_4952896_output.getInt32(i, 3);
        int32_t _i_class_id4141 = tbl_Expand_TD_4952896_output.getInt32(i, 4);
        int32_t _i_category_id4142 = tbl_Expand_TD_4952896_output.getInt32(i, 5);
        int64_t _spark_grouping_id4138L = tbl_Expand_TD_4952896_output.getInt64(i, 6);
        SW_Aggregate_TD_3511232_key k{std::string(_channel4139.data()), _i_brand_id4140, _i_class_id4141, _i_category_id4142, _spark_grouping_id4138L};
        int64_t _sumsales4129_sum_0 = _sales3545;
        int64_t _sumnumber_sales4130L_sum_1 = _number_sales3546L;
        SW_Aggregate_TD_3511232_payload p{_sumsales4129_sum_0, _sumnumber_sales4130L_sum_1};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._sumsales4129_sum_0 + _sumsales4129_sum_0;
            p._sumsales4129_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._sumnumber_sales4130L_sum_1 + _sumnumber_sales4130L_sum_1;
            p._sumnumber_sales4130L_sum_1 = sum_1;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _channel4139{};
        memcpy(_channel4139.data(), ((it.first)._channel4139).data(), ((it.first)._channel4139).length());
        tbl_Aggregate_TD_3511232_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _channel4139);
        tbl_Aggregate_TD_3511232_output.setInt32(r, 1, (it.first)._i_brand_id4140);
        tbl_Aggregate_TD_3511232_output.setInt32(r, 2, (it.first)._i_class_id4141);
        tbl_Aggregate_TD_3511232_output.setInt32(r, 3, (it.first)._i_category_id4142);
        // _spark_grouping_id4138L not required in the output table
        int64_t _sumsales4129 = (it.second)._sumsales4129_sum_0;
        tbl_Aggregate_TD_3511232_output.setInt64(r, 4, _sumsales4129);
        int64_t _sumnumber_sales4130L = (it.second)._sumnumber_sales4130L_sum_1;
        tbl_Aggregate_TD_3511232_output.setInt64(r, 5, _sumnumber_sales4130L);
        ++r;
    }
    tbl_Aggregate_TD_3511232_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_3511232_output #Row: " << tbl_Aggregate_TD_3511232_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2796771(Table &tbl_Aggregate_TD_3511232_output, Table &tbl_Sort_TD_2796771_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(channel#4139 ASC NULLS FIRST, i_brand_id#4140 ASC NULLS FIRST, i_class_id#4141 ASC NULLS FIRST, i_category_id#4142 ASC NULLS FIRST)
    // Input: ListBuffer(channel#4139, i_brand_id#4140, i_class_id#4141, i_category_id#4142, sum(sales)#4129, sum(number_sales)#4130L)
    // Output: ListBuffer(channel#4139, i_brand_id#4140, i_class_id#4141, i_category_id#4142, sum(sales)#4129, sum(number_sales)#4130L)
    struct SW_Sort_TD_2796771Row {
        std::string _channel4139;
        int32_t _i_brand_id4140;
        int32_t _i_class_id4141;
        int32_t _i_category_id4142;
        int64_t _sumsales4129;
        int64_t _sumnumber_sales4130L;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2796771Row& a, const SW_Sort_TD_2796771Row& b) const { return 
 (a._channel4139 < b._channel4139) || 
 ((a._channel4139 == b._channel4139) && (a._i_brand_id4140 < b._i_brand_id4140)) || 
 ((a._channel4139 == b._channel4139) && (a._i_brand_id4140 == b._i_brand_id4140) && (a._i_class_id4141 < b._i_class_id4141)) || 
 ((a._channel4139 == b._channel4139) && (a._i_brand_id4140 == b._i_brand_id4140) && (a._i_class_id4141 == b._i_class_id4141) && (a._i_category_id4142 < b._i_category_id4142)); 
}
    }SW_Sort_TD_2796771_order; 

    int nrow1 = tbl_Aggregate_TD_3511232_output.getNumRow();
    std::vector<SW_Sort_TD_2796771Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _channel4139 = tbl_Aggregate_TD_3511232_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        int32_t _i_brand_id4140 = tbl_Aggregate_TD_3511232_output.getInt32(i, 1);
        int32_t _i_class_id4141 = tbl_Aggregate_TD_3511232_output.getInt32(i, 2);
        int32_t _i_category_id4142 = tbl_Aggregate_TD_3511232_output.getInt32(i, 3);
        int64_t _sumsales4129 = tbl_Aggregate_TD_3511232_output.getInt64(i, 4);
        int64_t _sumnumber_sales4130L = tbl_Aggregate_TD_3511232_output.getInt64(i, 5);
        SW_Sort_TD_2796771Row t = {std::string(_channel4139.data()),_i_brand_id4140,_i_class_id4141,_i_category_id4142,_sumsales4129,_sumnumber_sales4130L};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2796771_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _channel4139{};
        memcpy(_channel4139.data(), (it._channel4139).data(), (it._channel4139).length());
        tbl_Sort_TD_2796771_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _channel4139);
        tbl_Sort_TD_2796771_output.setInt32(r, 1, it._i_brand_id4140);
        tbl_Sort_TD_2796771_output.setInt32(r, 2, it._i_class_id4141);
        tbl_Sort_TD_2796771_output.setInt32(r, 3, it._i_category_id4142);
        tbl_Sort_TD_2796771_output.setInt64(r, 4, it._sumsales4129);
        tbl_Sort_TD_2796771_output.setInt64(r, 5, it._sumnumber_sales4130L);
        ++r;
    }
    tbl_Sort_TD_2796771_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2796771_output #Row: " << tbl_Sort_TD_2796771_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_117337(Table &tbl_Sort_TD_2796771_output, Table &tbl_LocalLimit_TD_117337_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(channel#4139, i_brand_id#4140, i_class_id#4141, i_category_id#4142, sum(sales)#4129, sum(number_sales)#4130L)
    // Output: ListBuffer(channel#4139, i_brand_id#4140, i_class_id#4141, i_category_id#4142, sum(sales)#4129, sum(number_sales)#4130L)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _channel4139_n = tbl_Sort_TD_2796771_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_117337_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _channel4139_n);
        tbl_LocalLimit_TD_117337_output.setInt32(r, 1, tbl_Sort_TD_2796771_output.getInt32(i, 1));
        tbl_LocalLimit_TD_117337_output.setInt32(r, 2, tbl_Sort_TD_2796771_output.getInt32(i, 2));
        tbl_LocalLimit_TD_117337_output.setInt32(r, 3, tbl_Sort_TD_2796771_output.getInt32(i, 3));
        tbl_LocalLimit_TD_117337_output.setInt64(r, 4, tbl_Sort_TD_2796771_output.getInt64(i, 4));
        tbl_LocalLimit_TD_117337_output.setInt64(r, 5, tbl_Sort_TD_2796771_output.getInt64(i, 5));
        r++;
    }
    tbl_LocalLimit_TD_117337_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_117337_output #Row: " << tbl_LocalLimit_TD_117337_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0824750(Table &tbl_LocalLimit_TD_117337_output, Table &tbl_GlobalLimit_TD_0824750_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(channel#4139, i_brand_id#4140, i_class_id#4141, i_category_id#4142, sum(sales)#4129, sum(number_sales)#4130L)
    // Output: ListBuffer(channel#4139, i_brand_id#4140, i_class_id#4141, i_category_id#4142, sum(sales)#4129, sum(number_sales)#4130L)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _channel4139_n = tbl_LocalLimit_TD_117337_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0824750_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _channel4139_n);
        tbl_GlobalLimit_TD_0824750_output.setInt32(r, 1, tbl_LocalLimit_TD_117337_output.getInt32(i, 1));
        tbl_GlobalLimit_TD_0824750_output.setInt32(r, 2, tbl_LocalLimit_TD_117337_output.getInt32(i, 2));
        tbl_GlobalLimit_TD_0824750_output.setInt32(r, 3, tbl_LocalLimit_TD_117337_output.getInt32(i, 3));
        tbl_GlobalLimit_TD_0824750_output.setInt64(r, 4, tbl_LocalLimit_TD_117337_output.getInt64(i, 4));
        tbl_GlobalLimit_TD_0824750_output.setInt64(r, 5, tbl_LocalLimit_TD_117337_output.getInt64(i, 5));
        r++;
    }
    tbl_GlobalLimit_TD_0824750_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0824750_output #Row: " << tbl_GlobalLimit_TD_0824750_output.getNumRow() << std::endl;
}

