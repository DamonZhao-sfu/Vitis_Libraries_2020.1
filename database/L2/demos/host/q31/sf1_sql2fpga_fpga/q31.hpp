#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_10959900(Table &tbl_SerializeFromObject_TD_11452411_input, Table &tbl_Filter_TD_10959900_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_qoy#4327) AND isnotnull(d_year#4323)) AND ((d_qoy#4327 = 2) AND (d_year#4323 = 2000))) AND isnotnull(d_date_sk#4317)))
    // Input: ListBuffer(d_date_sk#4317, d_year#4323, d_qoy#4327)
    // Output: ListBuffer(d_date_sk#4317, d_year#4323, d_qoy#4327)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11452411_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_qoy4327 = tbl_SerializeFromObject_TD_11452411_input.getInt32(i, 2);
        int32_t _d_year4323 = tbl_SerializeFromObject_TD_11452411_input.getInt32(i, 1);
        int32_t _d_date_sk4317 = tbl_SerializeFromObject_TD_11452411_input.getInt32(i, 0);
        if ((((_d_qoy4327!= 0) && (_d_year4323!= 0)) && ((_d_qoy4327 == 2) && (_d_year4323 == 2000))) && (_d_date_sk4317!= 0)) {
            int32_t _d_date_sk4317_t = tbl_SerializeFromObject_TD_11452411_input.getInt32(i, 0);
            tbl_Filter_TD_10959900_output.setInt32(r, 0, _d_date_sk4317_t);
            int32_t _d_year4323_t = tbl_SerializeFromObject_TD_11452411_input.getInt32(i, 1);
            tbl_Filter_TD_10959900_output.setInt32(r, 1, _d_year4323_t);
            int32_t _d_qoy4327_t = tbl_SerializeFromObject_TD_11452411_input.getInt32(i, 2);
            tbl_Filter_TD_10959900_output.setInt32(r, 2, _d_qoy4327_t);
            r++;
        }
    }
    tbl_Filter_TD_10959900_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10959900_output #Row: " << tbl_Filter_TD_10959900_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10946768(Table &tbl_SerializeFromObject_TD_11334014_input, Table &tbl_Filter_TD_10946768_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_sold_date_sk#4294) AND isnotnull(ss_addr_sk#4300)))
    // Input: ListBuffer(ss_sold_date_sk#4294, ss_addr_sk#4300, ss_ext_sales_price#4309)
    // Output: ListBuffer(ss_sold_date_sk#4294, ss_addr_sk#4300, ss_ext_sales_price#4309)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11334014_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk4294 = tbl_SerializeFromObject_TD_11334014_input.getInt32(i, 0);
        int32_t _ss_addr_sk4300 = tbl_SerializeFromObject_TD_11334014_input.getInt32(i, 1);
        if ((_ss_sold_date_sk4294!= 0) && (_ss_addr_sk4300!= 0)) {
            int32_t _ss_sold_date_sk4294_t = tbl_SerializeFromObject_TD_11334014_input.getInt32(i, 0);
            tbl_Filter_TD_10946768_output.setInt32(r, 0, _ss_sold_date_sk4294_t);
            int32_t _ss_addr_sk4300_t = tbl_SerializeFromObject_TD_11334014_input.getInt32(i, 1);
            tbl_Filter_TD_10946768_output.setInt32(r, 1, _ss_addr_sk4300_t);
            int64_t _ss_ext_sales_price4309_t = tbl_SerializeFromObject_TD_11334014_input.getInt64(i, 2);
            tbl_Filter_TD_10946768_output.setInt64(r, 2, _ss_ext_sales_price4309_t);
            r++;
        }
    }
    tbl_Filter_TD_10946768_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10946768_output #Row: " << tbl_Filter_TD_10946768_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10222848(Table &tbl_SerializeFromObject_TD_11404989_input, Table &tbl_Filter_TD_10222848_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_qoy#130) AND isnotnull(d_year#126)) AND ((d_qoy#130 = 1) AND (d_year#126 = 2000))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126, d_qoy#130)
    // Output: ListBuffer(d_date_sk#120, d_year#126, d_qoy#130)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11404989_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_qoy130 = tbl_SerializeFromObject_TD_11404989_input.getInt32(i, 2);
        int32_t _d_year126 = tbl_SerializeFromObject_TD_11404989_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_11404989_input.getInt32(i, 0);
        if ((((_d_qoy130!= 0) && (_d_year126!= 0)) && ((_d_qoy130 == 1) && (_d_year126 == 2000))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_11404989_input.getInt32(i, 0);
            tbl_Filter_TD_10222848_output.setInt32(r, 0, _d_date_sk120_t);
            int32_t _d_year126_t = tbl_SerializeFromObject_TD_11404989_input.getInt32(i, 1);
            tbl_Filter_TD_10222848_output.setInt32(r, 1, _d_year126_t);
            int32_t _d_qoy130_t = tbl_SerializeFromObject_TD_11404989_input.getInt32(i, 2);
            tbl_Filter_TD_10222848_output.setInt32(r, 2, _d_qoy130_t);
            r++;
        }
    }
    tbl_Filter_TD_10222848_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10222848_output #Row: " << tbl_Filter_TD_10222848_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10907178(Table &tbl_SerializeFromObject_TD_1126797_input, Table &tbl_Filter_TD_10907178_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_sold_date_sk#1206) AND isnotnull(ss_addr_sk#1212)))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_addr_sk#1212, ss_ext_sales_price#1221)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_addr_sk#1212, ss_ext_sales_price#1221)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1126797_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_1126797_input.getInt32(i, 0);
        int32_t _ss_addr_sk1212 = tbl_SerializeFromObject_TD_1126797_input.getInt32(i, 1);
        if ((_ss_sold_date_sk1206!= 0) && (_ss_addr_sk1212!= 0)) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_1126797_input.getInt32(i, 0);
            tbl_Filter_TD_10907178_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_addr_sk1212_t = tbl_SerializeFromObject_TD_1126797_input.getInt32(i, 1);
            tbl_Filter_TD_10907178_output.setInt32(r, 1, _ss_addr_sk1212_t);
            int64_t _ss_ext_sales_price1221_t = tbl_SerializeFromObject_TD_1126797_input.getInt64(i, 2);
            tbl_Filter_TD_10907178_output.setInt64(r, 2, _ss_ext_sales_price1221_t);
            r++;
        }
    }
    tbl_Filter_TD_10907178_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10907178_output #Row: " << tbl_Filter_TD_10907178_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9611663(Table &tbl_SerializeFromObject_TD_10307863_input, Table &tbl_Filter_TD_9611663_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_qoy#4392) AND isnotnull(d_year#4388)) AND ((d_qoy#4392 = 3) AND (d_year#4388 = 2000))) AND isnotnull(d_date_sk#4382)))
    // Input: ListBuffer(d_date_sk#4382, d_year#4388, d_qoy#4392)
    // Output: ListBuffer(d_date_sk#4382, d_year#4388, d_qoy#4392)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10307863_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_qoy4392 = tbl_SerializeFromObject_TD_10307863_input.getInt32(i, 2);
        int32_t _d_year4388 = tbl_SerializeFromObject_TD_10307863_input.getInt32(i, 1);
        int32_t _d_date_sk4382 = tbl_SerializeFromObject_TD_10307863_input.getInt32(i, 0);
        if ((((_d_qoy4392!= 0) && (_d_year4388!= 0)) && ((_d_qoy4392 == 3) && (_d_year4388 == 2000))) && (_d_date_sk4382!= 0)) {
            int32_t _d_date_sk4382_t = tbl_SerializeFromObject_TD_10307863_input.getInt32(i, 0);
            tbl_Filter_TD_9611663_output.setInt32(r, 0, _d_date_sk4382_t);
            int32_t _d_year4388_t = tbl_SerializeFromObject_TD_10307863_input.getInt32(i, 1);
            tbl_Filter_TD_9611663_output.setInt32(r, 1, _d_year4388_t);
            int32_t _d_qoy4392_t = tbl_SerializeFromObject_TD_10307863_input.getInt32(i, 2);
            tbl_Filter_TD_9611663_output.setInt32(r, 2, _d_qoy4392_t);
            r++;
        }
    }
    tbl_Filter_TD_9611663_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9611663_output #Row: " << tbl_Filter_TD_9611663_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9673388(Table &tbl_SerializeFromObject_TD_1089102_input, Table &tbl_Filter_TD_9673388_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_sold_date_sk#4359) AND isnotnull(ss_addr_sk#4365)))
    // Input: ListBuffer(ss_sold_date_sk#4359, ss_addr_sk#4365, ss_ext_sales_price#4374)
    // Output: ListBuffer(ss_sold_date_sk#4359, ss_addr_sk#4365, ss_ext_sales_price#4374)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_1089102_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_sold_date_sk4359 = tbl_SerializeFromObject_TD_1089102_input.getInt32(i, 0);
        int32_t _ss_addr_sk4365 = tbl_SerializeFromObject_TD_1089102_input.getInt32(i, 1);
        if ((_ss_sold_date_sk4359!= 0) && (_ss_addr_sk4365!= 0)) {
            int32_t _ss_sold_date_sk4359_t = tbl_SerializeFromObject_TD_1089102_input.getInt32(i, 0);
            tbl_Filter_TD_9673388_output.setInt32(r, 0, _ss_sold_date_sk4359_t);
            int32_t _ss_addr_sk4365_t = tbl_SerializeFromObject_TD_1089102_input.getInt32(i, 1);
            tbl_Filter_TD_9673388_output.setInt32(r, 1, _ss_addr_sk4365_t);
            int64_t _ss_ext_sales_price4374_t = tbl_SerializeFromObject_TD_1089102_input.getInt64(i, 2);
            tbl_Filter_TD_9673388_output.setInt64(r, 2, _ss_ext_sales_price4374_t);
            r++;
        }
    }
    tbl_Filter_TD_9673388_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9673388_output #Row: " << tbl_Filter_TD_9673388_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9281970(Table &tbl_SerializeFromObject_TD_10148362_input, Table &tbl_Filter_TD_9281970_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ca_address_sk#4345) AND isnotnull(ca_county#4352)))
    // Input: ListBuffer(ca_address_sk#4345, ca_county#4352)
    // Output: ListBuffer(ca_address_sk#4345, ca_county#4352)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10148362_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ca_address_sk4345 = tbl_SerializeFromObject_TD_10148362_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _ca_county4352 = tbl_SerializeFromObject_TD_10148362_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_ca_address_sk4345!= 0) && _ca_county4352.data() != "NULL") {
            int32_t _ca_address_sk4345_t = tbl_SerializeFromObject_TD_10148362_input.getInt32(i, 0);
            tbl_Filter_TD_9281970_output.setInt32(r, 0, _ca_address_sk4345_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_county4352_t = tbl_SerializeFromObject_TD_10148362_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_9281970_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_county4352_t);
            r++;
        }
    }
    tbl_Filter_TD_9281970_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9281970_output #Row: " << tbl_Filter_TD_9281970_output.getNumRow() << std::endl;
}


void SW_Filter_TD_9913508(Table &tbl_SerializeFromObject_TD_10128076_input, Table &tbl_Filter_TD_9913508_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ca_address_sk#54) AND isnotnull(ca_county#61)))
    // Input: ListBuffer(ca_address_sk#54, ca_county#61)
    // Output: ListBuffer(ca_address_sk#54, ca_county#61)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10128076_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ca_address_sk54 = tbl_SerializeFromObject_TD_10128076_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _ca_county61 = tbl_SerializeFromObject_TD_10128076_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_ca_address_sk54!= 0) && _ca_county61.data() != "NULL") {
            int32_t _ca_address_sk54_t = tbl_SerializeFromObject_TD_10128076_input.getInt32(i, 0);
            tbl_Filter_TD_9913508_output.setInt32(r, 0, _ca_address_sk54_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_county61_t = tbl_SerializeFromObject_TD_10128076_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_9913508_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_county61_t);
            r++;
        }
    }
    tbl_Filter_TD_9913508_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9913508_output #Row: " << tbl_Filter_TD_9913508_output.getNumRow() << std::endl;
}


void SW_Filter_TD_8273211(Table &tbl_SerializeFromObject_TD_9849394_input, Table &tbl_Filter_TD_8273211_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_qoy#3560) AND isnotnull(d_year#3556)) AND ((d_qoy#3560 = 1) AND (d_year#3556 = 2000))) AND isnotnull(d_date_sk#3550)))
    // Input: ListBuffer(d_date_sk#3550, d_year#3556, d_qoy#3560)
    // Output: ListBuffer(d_date_sk#3550, d_year#3556, d_qoy#3560)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9849394_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_qoy3560 = tbl_SerializeFromObject_TD_9849394_input.getInt32(i, 2);
        int32_t _d_year3556 = tbl_SerializeFromObject_TD_9849394_input.getInt32(i, 1);
        int32_t _d_date_sk3550 = tbl_SerializeFromObject_TD_9849394_input.getInt32(i, 0);
        if ((((_d_qoy3560!= 0) && (_d_year3556!= 0)) && ((_d_qoy3560 == 1) && (_d_year3556 == 2000))) && (_d_date_sk3550!= 0)) {
            int32_t _d_date_sk3550_t = tbl_SerializeFromObject_TD_9849394_input.getInt32(i, 0);
            tbl_Filter_TD_8273211_output.setInt32(r, 0, _d_date_sk3550_t);
            int32_t _d_year3556_t = tbl_SerializeFromObject_TD_9849394_input.getInt32(i, 1);
            tbl_Filter_TD_8273211_output.setInt32(r, 1, _d_year3556_t);
            int32_t _d_qoy3560_t = tbl_SerializeFromObject_TD_9849394_input.getInt32(i, 2);
            tbl_Filter_TD_8273211_output.setInt32(r, 2, _d_qoy3560_t);
            r++;
        }
    }
    tbl_Filter_TD_8273211_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8273211_output #Row: " << tbl_Filter_TD_8273211_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8645917(Table &tbl_SerializeFromObject_TD_9345771_input, Table &tbl_Filter_TD_8645917_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_sold_date_sk#729) AND isnotnull(ws_bill_addr_sk#736)))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_bill_addr_sk#736, ws_ext_sales_price#752)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_bill_addr_sk#736, ws_ext_sales_price#752)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9345771_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_9345771_input.getInt32(i, 0);
        int32_t _ws_bill_addr_sk736 = tbl_SerializeFromObject_TD_9345771_input.getInt32(i, 1);
        if ((_ws_sold_date_sk729!= 0) && (_ws_bill_addr_sk736!= 0)) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_9345771_input.getInt32(i, 0);
            tbl_Filter_TD_8645917_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_bill_addr_sk736_t = tbl_SerializeFromObject_TD_9345771_input.getInt32(i, 1);
            tbl_Filter_TD_8645917_output.setInt32(r, 1, _ws_bill_addr_sk736_t);
            int64_t _ws_ext_sales_price752_t = tbl_SerializeFromObject_TD_9345771_input.getInt64(i, 2);
            tbl_Filter_TD_8645917_output.setInt64(r, 2, _ws_ext_sales_price752_t);
            r++;
        }
    }
    tbl_Filter_TD_8645917_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8645917_output #Row: " << tbl_Filter_TD_8645917_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8760047(Table &tbl_SerializeFromObject_TD_9124573_input, Table &tbl_Filter_TD_8760047_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ca_address_sk#4410) AND isnotnull(ca_county#4417)))
    // Input: ListBuffer(ca_address_sk#4410, ca_county#4417)
    // Output: ListBuffer(ca_address_sk#4410, ca_county#4417)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9124573_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ca_address_sk4410 = tbl_SerializeFromObject_TD_9124573_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _ca_county4417 = tbl_SerializeFromObject_TD_9124573_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_ca_address_sk4410!= 0) && _ca_county4417.data() != "NULL") {
            int32_t _ca_address_sk4410_t = tbl_SerializeFromObject_TD_9124573_input.getInt32(i, 0);
            tbl_Filter_TD_8760047_output.setInt32(r, 0, _ca_address_sk4410_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_county4417_t = tbl_SerializeFromObject_TD_9124573_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_8760047_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_county4417_t);
            r++;
        }
    }
    tbl_Filter_TD_8760047_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8760047_output #Row: " << tbl_Filter_TD_8760047_output.getNumRow() << std::endl;
}


struct SW_JOIN_INNER_TD_8914256_key_leftMajor {
    int32_t _ss_addr_sk4300;
    bool operator==(const SW_JOIN_INNER_TD_8914256_key_leftMajor& other) const {
        return ((_ss_addr_sk4300 == other._ss_addr_sk4300));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8914256_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8914256_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_addr_sk4300));
    }
};
}
struct SW_JOIN_INNER_TD_8914256_payload_leftMajor {
    int32_t _ss_addr_sk4300;
    int64_t _ss_ext_sales_price4309;
    int32_t _d_year4323;
    int32_t _d_qoy4327;
};
struct SW_JOIN_INNER_TD_8914256_key_rightMajor {
    int32_t _ca_address_sk4345;
    bool operator==(const SW_JOIN_INNER_TD_8914256_key_rightMajor& other) const {
        return ((_ca_address_sk4345 == other._ca_address_sk4345));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8914256_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8914256_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk4345));
    }
};
}
struct SW_JOIN_INNER_TD_8914256_payload_rightMajor {
    int32_t _ca_address_sk4345;
    std::string _ca_county4352;
};
void SW_JOIN_INNER_TD_8914256(Table &tbl_JOIN_INNER_TD_9874636_output, Table &tbl_Filter_TD_9281970_output, Table &tbl_JOIN_INNER_TD_8914256_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_addr_sk#4300 = ca_address_sk#4345))
    // Left Table: ListBuffer(ss_addr_sk#4300, ss_ext_sales_price#4309, d_year#4323, d_qoy#4327)
    // Right Table: ListBuffer(ca_address_sk#4345, ca_county#4352)
    // Output Table: ListBuffer(ss_ext_sales_price#4309, d_year#4323, d_qoy#4327, ca_county#4352)
    int left_nrow = tbl_JOIN_INNER_TD_9874636_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9281970_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8914256_key_leftMajor, SW_JOIN_INNER_TD_8914256_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_9874636_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_addr_sk4300_k = tbl_JOIN_INNER_TD_9874636_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8914256_key_leftMajor keyA{_ss_addr_sk4300_k};
            int32_t _ss_addr_sk4300 = tbl_JOIN_INNER_TD_9874636_output.getInt32(i, 0);
            int64_t _ss_ext_sales_price4309 = tbl_JOIN_INNER_TD_9874636_output.getInt64(i, 1);
            int32_t _d_year4323 = tbl_JOIN_INNER_TD_9874636_output.getInt32(i, 2);
            int32_t _d_qoy4327 = tbl_JOIN_INNER_TD_9874636_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_8914256_payload_leftMajor payloadA{_ss_addr_sk4300, _ss_ext_sales_price4309, _d_year4323, _d_qoy4327};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9281970_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk4345_k = tbl_Filter_TD_9281970_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8914256_key_leftMajor{_ca_address_sk4345_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_addr_sk4300 = (it->second)._ss_addr_sk4300;
                int64_t _ss_ext_sales_price4309 = (it->second)._ss_ext_sales_price4309;
                int32_t _d_year4323 = (it->second)._d_year4323;
                int32_t _d_qoy4327 = (it->second)._d_qoy4327;
                int32_t _ca_address_sk4345 = tbl_Filter_TD_9281970_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_county4352_n = tbl_Filter_TD_9281970_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_county4352 = std::string(_ca_county4352_n.data());
                tbl_JOIN_INNER_TD_8914256_output.setInt64(r, 0, _ss_ext_sales_price4309);
                tbl_JOIN_INNER_TD_8914256_output.setInt32(r, 1, _d_year4323);
                tbl_JOIN_INNER_TD_8914256_output.setInt32(r, 2, _d_qoy4327);
                tbl_JOIN_INNER_TD_8914256_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_county4352_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8914256_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8914256_key_rightMajor, SW_JOIN_INNER_TD_8914256_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9281970_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk4345_k = tbl_Filter_TD_9281970_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8914256_key_rightMajor keyA{_ca_address_sk4345_k};
            int32_t _ca_address_sk4345 = tbl_Filter_TD_9281970_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_county4352_n = tbl_Filter_TD_9281970_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_county4352 = std::string(_ca_county4352_n.data());
            SW_JOIN_INNER_TD_8914256_payload_rightMajor payloadA{_ca_address_sk4345, _ca_county4352};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_9874636_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_addr_sk4300_k = tbl_JOIN_INNER_TD_9874636_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8914256_key_rightMajor{_ss_addr_sk4300_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk4345 = (it->second)._ca_address_sk4345;
                std::string _ca_county4352 = (it->second)._ca_county4352;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county4352_n{};
                memcpy(_ca_county4352_n.data(), (_ca_county4352).data(), (_ca_county4352).length());
                int32_t _ss_addr_sk4300 = tbl_JOIN_INNER_TD_9874636_output.getInt32(i, 0);
                int64_t _ss_ext_sales_price4309 = tbl_JOIN_INNER_TD_9874636_output.getInt64(i, 1);
                int32_t _d_year4323 = tbl_JOIN_INNER_TD_9874636_output.getInt32(i, 2);
                int32_t _d_qoy4327 = tbl_JOIN_INNER_TD_9874636_output.getInt32(i, 3);
                tbl_JOIN_INNER_TD_8914256_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_county4352_n);
                tbl_JOIN_INNER_TD_8914256_output.setInt64(r, 0, _ss_ext_sales_price4309);
                tbl_JOIN_INNER_TD_8914256_output.setInt32(r, 1, _d_year4323);
                tbl_JOIN_INNER_TD_8914256_output.setInt32(r, 2, _d_qoy4327);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8914256_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8914256_output #Row: " << tbl_JOIN_INNER_TD_8914256_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8588441_key_leftMajor {
    int32_t _ss_addr_sk1212;
    bool operator==(const SW_JOIN_INNER_TD_8588441_key_leftMajor& other) const {
        return ((_ss_addr_sk1212 == other._ss_addr_sk1212));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8588441_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8588441_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_addr_sk1212));
    }
};
}
struct SW_JOIN_INNER_TD_8588441_payload_leftMajor {
    int32_t _ss_addr_sk1212;
    int64_t _ss_ext_sales_price1221;
    int32_t _d_year126;
    int32_t _d_qoy130;
};
struct SW_JOIN_INNER_TD_8588441_key_rightMajor {
    int32_t _ca_address_sk54;
    bool operator==(const SW_JOIN_INNER_TD_8588441_key_rightMajor& other) const {
        return ((_ca_address_sk54 == other._ca_address_sk54));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8588441_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8588441_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk54));
    }
};
}
struct SW_JOIN_INNER_TD_8588441_payload_rightMajor {
    int32_t _ca_address_sk54;
    std::string _ca_county61;
};
void SW_JOIN_INNER_TD_8588441(Table &tbl_JOIN_INNER_TD_9888218_output, Table &tbl_Filter_TD_9913508_output, Table &tbl_JOIN_INNER_TD_8588441_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_addr_sk#1212 = ca_address_sk#54))
    // Left Table: ListBuffer(ss_addr_sk#1212, ss_ext_sales_price#1221, d_year#126, d_qoy#130)
    // Right Table: ListBuffer(ca_address_sk#54, ca_county#61)
    // Output Table: ListBuffer(ss_ext_sales_price#1221, d_year#126, d_qoy#130, ca_county#61)
    int left_nrow = tbl_JOIN_INNER_TD_9888218_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9913508_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8588441_key_leftMajor, SW_JOIN_INNER_TD_8588441_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_9888218_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_addr_sk1212_k = tbl_JOIN_INNER_TD_9888218_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8588441_key_leftMajor keyA{_ss_addr_sk1212_k};
            int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_9888218_output.getInt32(i, 0);
            int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_9888218_output.getInt64(i, 1);
            int32_t _d_year126 = tbl_JOIN_INNER_TD_9888218_output.getInt32(i, 2);
            int32_t _d_qoy130 = tbl_JOIN_INNER_TD_9888218_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_8588441_payload_leftMajor payloadA{_ss_addr_sk1212, _ss_ext_sales_price1221, _d_year126, _d_qoy130};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9913508_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_9913508_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8588441_key_leftMajor{_ca_address_sk54_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_addr_sk1212 = (it->second)._ss_addr_sk1212;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int32_t _d_year126 = (it->second)._d_year126;
                int32_t _d_qoy130 = (it->second)._d_qoy130;
                int32_t _ca_address_sk54 = tbl_Filter_TD_9913508_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n = tbl_Filter_TD_9913508_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_county61 = std::string(_ca_county61_n.data());
                tbl_JOIN_INNER_TD_8588441_output.setInt64(r, 0, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_8588441_output.setInt32(r, 1, _d_year126);
                tbl_JOIN_INNER_TD_8588441_output.setInt32(r, 2, _d_qoy130);
                tbl_JOIN_INNER_TD_8588441_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_county61_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8588441_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8588441_key_rightMajor, SW_JOIN_INNER_TD_8588441_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9913508_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_9913508_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8588441_key_rightMajor keyA{_ca_address_sk54_k};
            int32_t _ca_address_sk54 = tbl_Filter_TD_9913508_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n = tbl_Filter_TD_9913508_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_county61 = std::string(_ca_county61_n.data());
            SW_JOIN_INNER_TD_8588441_payload_rightMajor payloadA{_ca_address_sk54, _ca_county61};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_9888218_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_addr_sk1212_k = tbl_JOIN_INNER_TD_9888218_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8588441_key_rightMajor{_ss_addr_sk1212_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk54 = (it->second)._ca_address_sk54;
                std::string _ca_county61 = (it->second)._ca_county61;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n{};
                memcpy(_ca_county61_n.data(), (_ca_county61).data(), (_ca_county61).length());
                int32_t _ss_addr_sk1212 = tbl_JOIN_INNER_TD_9888218_output.getInt32(i, 0);
                int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_9888218_output.getInt64(i, 1);
                int32_t _d_year126 = tbl_JOIN_INNER_TD_9888218_output.getInt32(i, 2);
                int32_t _d_qoy130 = tbl_JOIN_INNER_TD_9888218_output.getInt32(i, 3);
                tbl_JOIN_INNER_TD_8588441_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_county61_n);
                tbl_JOIN_INNER_TD_8588441_output.setInt64(r, 0, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_8588441_output.setInt32(r, 1, _d_year126);
                tbl_JOIN_INNER_TD_8588441_output.setInt32(r, 2, _d_qoy130);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8588441_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8588441_output #Row: " << tbl_JOIN_INNER_TD_8588441_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7752021(Table &tbl_SerializeFromObject_TD_8558338_input, Table &tbl_Filter_TD_7752021_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_qoy#4468) AND isnotnull(d_year#4464)) AND ((d_qoy#4468 = 2) AND (d_year#4464 = 2000))) AND isnotnull(d_date_sk#4458)))
    // Input: ListBuffer(d_date_sk#4458, d_year#4464, d_qoy#4468)
    // Output: ListBuffer(d_date_sk#4458, d_year#4464, d_qoy#4468)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8558338_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_qoy4468 = tbl_SerializeFromObject_TD_8558338_input.getInt32(i, 2);
        int32_t _d_year4464 = tbl_SerializeFromObject_TD_8558338_input.getInt32(i, 1);
        int32_t _d_date_sk4458 = tbl_SerializeFromObject_TD_8558338_input.getInt32(i, 0);
        if ((((_d_qoy4468!= 0) && (_d_year4464!= 0)) && ((_d_qoy4468 == 2) && (_d_year4464 == 2000))) && (_d_date_sk4458!= 0)) {
            int32_t _d_date_sk4458_t = tbl_SerializeFromObject_TD_8558338_input.getInt32(i, 0);
            tbl_Filter_TD_7752021_output.setInt32(r, 0, _d_date_sk4458_t);
            int32_t _d_year4464_t = tbl_SerializeFromObject_TD_8558338_input.getInt32(i, 1);
            tbl_Filter_TD_7752021_output.setInt32(r, 1, _d_year4464_t);
            int32_t _d_qoy4468_t = tbl_SerializeFromObject_TD_8558338_input.getInt32(i, 2);
            tbl_Filter_TD_7752021_output.setInt32(r, 2, _d_qoy4468_t);
            r++;
        }
    }
    tbl_Filter_TD_7752021_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7752021_output #Row: " << tbl_Filter_TD_7752021_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7224122(Table &tbl_SerializeFromObject_TD_8224831_input, Table &tbl_Filter_TD_7224122_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_sold_date_sk#4424) AND isnotnull(ws_bill_addr_sk#4431)))
    // Input: ListBuffer(ws_sold_date_sk#4424, ws_bill_addr_sk#4431, ws_ext_sales_price#4447)
    // Output: ListBuffer(ws_sold_date_sk#4424, ws_bill_addr_sk#4431, ws_ext_sales_price#4447)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8224831_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_sold_date_sk4424 = tbl_SerializeFromObject_TD_8224831_input.getInt32(i, 0);
        int32_t _ws_bill_addr_sk4431 = tbl_SerializeFromObject_TD_8224831_input.getInt32(i, 1);
        if ((_ws_sold_date_sk4424!= 0) && (_ws_bill_addr_sk4431!= 0)) {
            int32_t _ws_sold_date_sk4424_t = tbl_SerializeFromObject_TD_8224831_input.getInt32(i, 0);
            tbl_Filter_TD_7224122_output.setInt32(r, 0, _ws_sold_date_sk4424_t);
            int32_t _ws_bill_addr_sk4431_t = tbl_SerializeFromObject_TD_8224831_input.getInt32(i, 1);
            tbl_Filter_TD_7224122_output.setInt32(r, 1, _ws_bill_addr_sk4431_t);
            int64_t _ws_ext_sales_price4447_t = tbl_SerializeFromObject_TD_8224831_input.getInt64(i, 2);
            tbl_Filter_TD_7224122_output.setInt64(r, 2, _ws_ext_sales_price4447_t);
            r++;
        }
    }
    tbl_Filter_TD_7224122_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7224122_output #Row: " << tbl_Filter_TD_7224122_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7689133(Table &tbl_SerializeFromObject_TD_8113542_input, Table &tbl_Filter_TD_7689133_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ca_address_sk#3578) AND isnotnull(ca_county#3585)))
    // Input: ListBuffer(ca_address_sk#3578, ca_county#3585)
    // Output: ListBuffer(ca_address_sk#3578, ca_county#3585)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8113542_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ca_address_sk3578 = tbl_SerializeFromObject_TD_8113542_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _ca_county3585 = tbl_SerializeFromObject_TD_8113542_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_ca_address_sk3578!= 0) && _ca_county3585.data() != "NULL") {
            int32_t _ca_address_sk3578_t = tbl_SerializeFromObject_TD_8113542_input.getInt32(i, 0);
            tbl_Filter_TD_7689133_output.setInt32(r, 0, _ca_address_sk3578_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_county3585_t = tbl_SerializeFromObject_TD_8113542_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_7689133_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_county3585_t);
            r++;
        }
    }
    tbl_Filter_TD_7689133_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7689133_output #Row: " << tbl_Filter_TD_7689133_output.getNumRow() << std::endl;
}


struct SW_JOIN_INNER_TD_7452580_key_leftMajor {
    int32_t _ss_addr_sk4365;
    bool operator==(const SW_JOIN_INNER_TD_7452580_key_leftMajor& other) const {
        return ((_ss_addr_sk4365 == other._ss_addr_sk4365));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7452580_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7452580_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_addr_sk4365));
    }
};
}
struct SW_JOIN_INNER_TD_7452580_payload_leftMajor {
    int32_t _ss_addr_sk4365;
    int64_t _ss_ext_sales_price4374;
    int32_t _d_year4388;
    int32_t _d_qoy4392;
};
struct SW_JOIN_INNER_TD_7452580_key_rightMajor {
    int32_t _ca_address_sk4410;
    bool operator==(const SW_JOIN_INNER_TD_7452580_key_rightMajor& other) const {
        return ((_ca_address_sk4410 == other._ca_address_sk4410));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7452580_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7452580_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk4410));
    }
};
}
struct SW_JOIN_INNER_TD_7452580_payload_rightMajor {
    int32_t _ca_address_sk4410;
    std::string _ca_county4417;
};
void SW_JOIN_INNER_TD_7452580(Table &tbl_JOIN_INNER_TD_8666731_output, Table &tbl_Filter_TD_8760047_output, Table &tbl_JOIN_INNER_TD_7452580_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_addr_sk#4365 = ca_address_sk#4410))
    // Left Table: ListBuffer(ss_addr_sk#4365, ss_ext_sales_price#4374, d_year#4388, d_qoy#4392)
    // Right Table: ListBuffer(ca_address_sk#4410, ca_county#4417)
    // Output Table: ListBuffer(ss_ext_sales_price#4374, d_year#4388, d_qoy#4392, ca_county#4417)
    int left_nrow = tbl_JOIN_INNER_TD_8666731_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8760047_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7452580_key_leftMajor, SW_JOIN_INNER_TD_7452580_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_8666731_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_addr_sk4365_k = tbl_JOIN_INNER_TD_8666731_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7452580_key_leftMajor keyA{_ss_addr_sk4365_k};
            int32_t _ss_addr_sk4365 = tbl_JOIN_INNER_TD_8666731_output.getInt32(i, 0);
            int64_t _ss_ext_sales_price4374 = tbl_JOIN_INNER_TD_8666731_output.getInt64(i, 1);
            int32_t _d_year4388 = tbl_JOIN_INNER_TD_8666731_output.getInt32(i, 2);
            int32_t _d_qoy4392 = tbl_JOIN_INNER_TD_8666731_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_7452580_payload_leftMajor payloadA{_ss_addr_sk4365, _ss_ext_sales_price4374, _d_year4388, _d_qoy4392};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8760047_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk4410_k = tbl_Filter_TD_8760047_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7452580_key_leftMajor{_ca_address_sk4410_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_addr_sk4365 = (it->second)._ss_addr_sk4365;
                int64_t _ss_ext_sales_price4374 = (it->second)._ss_ext_sales_price4374;
                int32_t _d_year4388 = (it->second)._d_year4388;
                int32_t _d_qoy4392 = (it->second)._d_qoy4392;
                int32_t _ca_address_sk4410 = tbl_Filter_TD_8760047_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_county4417_n = tbl_Filter_TD_8760047_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_county4417 = std::string(_ca_county4417_n.data());
                tbl_JOIN_INNER_TD_7452580_output.setInt64(r, 0, _ss_ext_sales_price4374);
                tbl_JOIN_INNER_TD_7452580_output.setInt32(r, 1, _d_year4388);
                tbl_JOIN_INNER_TD_7452580_output.setInt32(r, 2, _d_qoy4392);
                tbl_JOIN_INNER_TD_7452580_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_county4417_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7452580_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7452580_key_rightMajor, SW_JOIN_INNER_TD_7452580_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8760047_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk4410_k = tbl_Filter_TD_8760047_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7452580_key_rightMajor keyA{_ca_address_sk4410_k};
            int32_t _ca_address_sk4410 = tbl_Filter_TD_8760047_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_county4417_n = tbl_Filter_TD_8760047_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_county4417 = std::string(_ca_county4417_n.data());
            SW_JOIN_INNER_TD_7452580_payload_rightMajor payloadA{_ca_address_sk4410, _ca_county4417};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_8666731_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_addr_sk4365_k = tbl_JOIN_INNER_TD_8666731_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7452580_key_rightMajor{_ss_addr_sk4365_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk4410 = (it->second)._ca_address_sk4410;
                std::string _ca_county4417 = (it->second)._ca_county4417;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county4417_n{};
                memcpy(_ca_county4417_n.data(), (_ca_county4417).data(), (_ca_county4417).length());
                int32_t _ss_addr_sk4365 = tbl_JOIN_INNER_TD_8666731_output.getInt32(i, 0);
                int64_t _ss_ext_sales_price4374 = tbl_JOIN_INNER_TD_8666731_output.getInt64(i, 1);
                int32_t _d_year4388 = tbl_JOIN_INNER_TD_8666731_output.getInt32(i, 2);
                int32_t _d_qoy4392 = tbl_JOIN_INNER_TD_8666731_output.getInt32(i, 3);
                tbl_JOIN_INNER_TD_7452580_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_county4417_n);
                tbl_JOIN_INNER_TD_7452580_output.setInt64(r, 0, _ss_ext_sales_price4374);
                tbl_JOIN_INNER_TD_7452580_output.setInt32(r, 1, _d_year4388);
                tbl_JOIN_INNER_TD_7452580_output.setInt32(r, 2, _d_qoy4392);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7452580_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7452580_output #Row: " << tbl_JOIN_INNER_TD_7452580_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_7282392_key {
    std::string _ca_county4352;
    int32_t _d_qoy4327;
    int32_t _d_year4323;
    bool operator==(const SW_Aggregate_TD_7282392_key& other) const { return (_ca_county4352 == other._ca_county4352) && (_d_qoy4327 == other._d_qoy4327) && (_d_year4323 == other._d_year4323); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_7282392_key> {
    std::size_t operator() (const SW_Aggregate_TD_7282392_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._ca_county4352)) + (hash<int32_t>()(k._d_qoy4327)) + (hash<int32_t>()(k._d_year4323));
    }
};
}
struct SW_Aggregate_TD_7282392_payload {
    int64_t _store_sales3596_sum_0;
};
void SW_Aggregate_TD_7282392(Table &tbl_JOIN_INNER_TD_8914256_output, Table &tbl_Aggregate_TD_7282392_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(ca_county#4352, d_qoy#4327, d_year#4323, MakeDecimal(sum(UnscaledValue(ss_ext_sales_price#4309)),17,2) AS store_sales#3596)
    // Input: ListBuffer(ss_ext_sales_price#4309, d_year#4323, d_qoy#4327, ca_county#4352)
    // Output: ListBuffer(ca_county#4352, store_sales#3596)
    std::unordered_map<SW_Aggregate_TD_7282392_key, SW_Aggregate_TD_7282392_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_8914256_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ss_ext_sales_price4309 = tbl_JOIN_INNER_TD_8914256_output.getInt64(i, 0);
        int32_t _d_year4323 = tbl_JOIN_INNER_TD_8914256_output.getInt32(i, 1);
        int32_t _d_qoy4327 = tbl_JOIN_INNER_TD_8914256_output.getInt32(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _ca_county4352 = tbl_JOIN_INNER_TD_8914256_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        SW_Aggregate_TD_7282392_key k{std::string(_ca_county4352.data()), _d_qoy4327, _d_year4323};
        int64_t _store_sales3596_sum_0 = _ss_ext_sales_price4309;
        SW_Aggregate_TD_7282392_payload p{_store_sales3596_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._store_sales3596_sum_0 + _store_sales3596_sum_0;
            p._store_sales3596_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_county4352{};
        memcpy(_ca_county4352.data(), ((it.first)._ca_county4352).data(), ((it.first)._ca_county4352).length());
        tbl_Aggregate_TD_7282392_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_county4352);
        // _d_qoy4327 not required in the output table
        // _d_year4323 not required in the output table
        int64_t _store_sales3596 = (it.second)._store_sales3596_sum_0;
        tbl_Aggregate_TD_7282392_output.setInt64(r, 1, _store_sales3596);
        ++r;
    }
    tbl_Aggregate_TD_7282392_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_7282392_output #Row: " << tbl_Aggregate_TD_7282392_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_7393156_key {
    std::string _ca_county61;
    int32_t _d_qoy130;
    int32_t _d_year126;
    bool operator==(const SW_Aggregate_TD_7393156_key& other) const { return (_ca_county61 == other._ca_county61) && (_d_qoy130 == other._d_qoy130) && (_d_year126 == other._d_year126); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_7393156_key> {
    std::size_t operator() (const SW_Aggregate_TD_7393156_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._ca_county61)) + (hash<int32_t>()(k._d_qoy130)) + (hash<int32_t>()(k._d_year126));
    }
};
}
struct SW_Aggregate_TD_7393156_payload {
    int64_t _store_sales3548_sum_0;
};
void SW_Aggregate_TD_7393156(Table &tbl_JOIN_INNER_TD_8588441_output, Table &tbl_Aggregate_TD_7393156_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(ca_county#61, d_qoy#130, d_year#126, MakeDecimal(sum(UnscaledValue(ss_ext_sales_price#1221)),17,2) AS store_sales#3548)
    // Input: ListBuffer(ss_ext_sales_price#1221, d_year#126, d_qoy#130, ca_county#61)
    // Output: ListBuffer(ca_county#61, d_year#126, store_sales#3548)
    std::unordered_map<SW_Aggregate_TD_7393156_key, SW_Aggregate_TD_7393156_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_8588441_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_8588441_output.getInt64(i, 0);
        int32_t _d_year126 = tbl_JOIN_INNER_TD_8588441_output.getInt32(i, 1);
        int32_t _d_qoy130 = tbl_JOIN_INNER_TD_8588441_output.getInt32(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _ca_county61 = tbl_JOIN_INNER_TD_8588441_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        SW_Aggregate_TD_7393156_key k{std::string(_ca_county61.data()), _d_qoy130, _d_year126};
        int64_t _store_sales3548_sum_0 = _ss_ext_sales_price1221;
        SW_Aggregate_TD_7393156_payload p{_store_sales3548_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._store_sales3548_sum_0 + _store_sales3548_sum_0;
            p._store_sales3548_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_county61{};
        memcpy(_ca_county61.data(), ((it.first)._ca_county61).data(), ((it.first)._ca_county61).length());
        tbl_Aggregate_TD_7393156_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_county61);
        // _d_qoy130 not required in the output table
        tbl_Aggregate_TD_7393156_output.setInt32(r, 1, (it.first)._d_year126);
        int64_t _store_sales3548 = (it.second)._store_sales3548_sum_0;
        tbl_Aggregate_TD_7393156_output.setInt64(r, 2, _store_sales3548);
        ++r;
    }
    tbl_Aggregate_TD_7393156_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_7393156_output #Row: " << tbl_Aggregate_TD_7393156_output.getNumRow() << std::endl;
}

void SW_Filter_TD_694516(Table &tbl_SerializeFromObject_TD_7421218_input, Table &tbl_Filter_TD_694516_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_qoy#4544) AND isnotnull(d_year#4540)) AND ((d_qoy#4544 = 3) AND (d_year#4540 = 2000))) AND isnotnull(d_date_sk#4534)))
    // Input: ListBuffer(d_date_sk#4534, d_year#4540, d_qoy#4544)
    // Output: ListBuffer(d_date_sk#4534, d_year#4540, d_qoy#4544)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7421218_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_qoy4544 = tbl_SerializeFromObject_TD_7421218_input.getInt32(i, 2);
        int32_t _d_year4540 = tbl_SerializeFromObject_TD_7421218_input.getInt32(i, 1);
        int32_t _d_date_sk4534 = tbl_SerializeFromObject_TD_7421218_input.getInt32(i, 0);
        if ((((_d_qoy4544!= 0) && (_d_year4540!= 0)) && ((_d_qoy4544 == 3) && (_d_year4540 == 2000))) && (_d_date_sk4534!= 0)) {
            int32_t _d_date_sk4534_t = tbl_SerializeFromObject_TD_7421218_input.getInt32(i, 0);
            tbl_Filter_TD_694516_output.setInt32(r, 0, _d_date_sk4534_t);
            int32_t _d_year4540_t = tbl_SerializeFromObject_TD_7421218_input.getInt32(i, 1);
            tbl_Filter_TD_694516_output.setInt32(r, 1, _d_year4540_t);
            int32_t _d_qoy4544_t = tbl_SerializeFromObject_TD_7421218_input.getInt32(i, 2);
            tbl_Filter_TD_694516_output.setInt32(r, 2, _d_qoy4544_t);
            r++;
        }
    }
    tbl_Filter_TD_694516_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_694516_output #Row: " << tbl_Filter_TD_694516_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6875471(Table &tbl_SerializeFromObject_TD_7110449_input, Table &tbl_Filter_TD_6875471_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_sold_date_sk#4500) AND isnotnull(ws_bill_addr_sk#4507)))
    // Input: ListBuffer(ws_sold_date_sk#4500, ws_bill_addr_sk#4507, ws_ext_sales_price#4523)
    // Output: ListBuffer(ws_sold_date_sk#4500, ws_bill_addr_sk#4507, ws_ext_sales_price#4523)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7110449_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_sold_date_sk4500 = tbl_SerializeFromObject_TD_7110449_input.getInt32(i, 0);
        int32_t _ws_bill_addr_sk4507 = tbl_SerializeFromObject_TD_7110449_input.getInt32(i, 1);
        if ((_ws_sold_date_sk4500!= 0) && (_ws_bill_addr_sk4507!= 0)) {
            int32_t _ws_sold_date_sk4500_t = tbl_SerializeFromObject_TD_7110449_input.getInt32(i, 0);
            tbl_Filter_TD_6875471_output.setInt32(r, 0, _ws_sold_date_sk4500_t);
            int32_t _ws_bill_addr_sk4507_t = tbl_SerializeFromObject_TD_7110449_input.getInt32(i, 1);
            tbl_Filter_TD_6875471_output.setInt32(r, 1, _ws_bill_addr_sk4507_t);
            int64_t _ws_ext_sales_price4523_t = tbl_SerializeFromObject_TD_7110449_input.getInt64(i, 2);
            tbl_Filter_TD_6875471_output.setInt64(r, 2, _ws_ext_sales_price4523_t);
            r++;
        }
    }
    tbl_Filter_TD_6875471_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6875471_output #Row: " << tbl_Filter_TD_6875471_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6936522(Table &tbl_SerializeFromObject_TD_7451227_input, Table &tbl_Filter_TD_6936522_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ca_address_sk#4486) AND isnotnull(ca_county#4493)))
    // Input: ListBuffer(ca_address_sk#4486, ca_county#4493)
    // Output: ListBuffer(ca_address_sk#4486, ca_county#4493)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7451227_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ca_address_sk4486 = tbl_SerializeFromObject_TD_7451227_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _ca_county4493 = tbl_SerializeFromObject_TD_7451227_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_ca_address_sk4486!= 0) && _ca_county4493.data() != "NULL") {
            int32_t _ca_address_sk4486_t = tbl_SerializeFromObject_TD_7451227_input.getInt32(i, 0);
            tbl_Filter_TD_6936522_output.setInt32(r, 0, _ca_address_sk4486_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_county4493_t = tbl_SerializeFromObject_TD_7451227_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_6936522_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_county4493_t);
            r++;
        }
    }
    tbl_Filter_TD_6936522_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6936522_output #Row: " << tbl_Filter_TD_6936522_output.getNumRow() << std::endl;
}


struct SW_JOIN_INNER_TD_6834355_key_leftMajor {
    int32_t _ws_bill_addr_sk736;
    bool operator==(const SW_JOIN_INNER_TD_6834355_key_leftMajor& other) const {
        return ((_ws_bill_addr_sk736 == other._ws_bill_addr_sk736));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6834355_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6834355_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_bill_addr_sk736));
    }
};
}
struct SW_JOIN_INNER_TD_6834355_payload_leftMajor {
    int32_t _ws_bill_addr_sk736;
    int64_t _ws_ext_sales_price752;
    int32_t _d_year3556;
    int32_t _d_qoy3560;
};
struct SW_JOIN_INNER_TD_6834355_key_rightMajor {
    int32_t _ca_address_sk3578;
    bool operator==(const SW_JOIN_INNER_TD_6834355_key_rightMajor& other) const {
        return ((_ca_address_sk3578 == other._ca_address_sk3578));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6834355_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6834355_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk3578));
    }
};
}
struct SW_JOIN_INNER_TD_6834355_payload_rightMajor {
    int32_t _ca_address_sk3578;
    std::string _ca_county3585;
};
void SW_JOIN_INNER_TD_6834355(Table &tbl_JOIN_INNER_TD_7616985_output, Table &tbl_Filter_TD_7689133_output, Table &tbl_JOIN_INNER_TD_6834355_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_bill_addr_sk#736 = ca_address_sk#3578))
    // Left Table: ListBuffer(ws_bill_addr_sk#736, ws_ext_sales_price#752, d_year#3556, d_qoy#3560)
    // Right Table: ListBuffer(ca_address_sk#3578, ca_county#3585)
    // Output Table: ListBuffer(ws_ext_sales_price#752, d_year#3556, d_qoy#3560, ca_county#3585)
    int left_nrow = tbl_JOIN_INNER_TD_7616985_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7689133_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6834355_key_leftMajor, SW_JOIN_INNER_TD_6834355_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7616985_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_bill_addr_sk736_k = tbl_JOIN_INNER_TD_7616985_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6834355_key_leftMajor keyA{_ws_bill_addr_sk736_k};
            int32_t _ws_bill_addr_sk736 = tbl_JOIN_INNER_TD_7616985_output.getInt32(i, 0);
            int64_t _ws_ext_sales_price752 = tbl_JOIN_INNER_TD_7616985_output.getInt64(i, 1);
            int32_t _d_year3556 = tbl_JOIN_INNER_TD_7616985_output.getInt32(i, 2);
            int32_t _d_qoy3560 = tbl_JOIN_INNER_TD_7616985_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_6834355_payload_leftMajor payloadA{_ws_bill_addr_sk736, _ws_ext_sales_price752, _d_year3556, _d_qoy3560};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7689133_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk3578_k = tbl_Filter_TD_7689133_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6834355_key_leftMajor{_ca_address_sk3578_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_bill_addr_sk736 = (it->second)._ws_bill_addr_sk736;
                int64_t _ws_ext_sales_price752 = (it->second)._ws_ext_sales_price752;
                int32_t _d_year3556 = (it->second)._d_year3556;
                int32_t _d_qoy3560 = (it->second)._d_qoy3560;
                int32_t _ca_address_sk3578 = tbl_Filter_TD_7689133_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_county3585_n = tbl_Filter_TD_7689133_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_county3585 = std::string(_ca_county3585_n.data());
                tbl_JOIN_INNER_TD_6834355_output.setInt64(r, 0, _ws_ext_sales_price752);
                tbl_JOIN_INNER_TD_6834355_output.setInt32(r, 1, _d_year3556);
                tbl_JOIN_INNER_TD_6834355_output.setInt32(r, 2, _d_qoy3560);
                tbl_JOIN_INNER_TD_6834355_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_county3585_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6834355_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6834355_key_rightMajor, SW_JOIN_INNER_TD_6834355_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7689133_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk3578_k = tbl_Filter_TD_7689133_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6834355_key_rightMajor keyA{_ca_address_sk3578_k};
            int32_t _ca_address_sk3578 = tbl_Filter_TD_7689133_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_county3585_n = tbl_Filter_TD_7689133_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_county3585 = std::string(_ca_county3585_n.data());
            SW_JOIN_INNER_TD_6834355_payload_rightMajor payloadA{_ca_address_sk3578, _ca_county3585};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7616985_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_bill_addr_sk736_k = tbl_JOIN_INNER_TD_7616985_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6834355_key_rightMajor{_ws_bill_addr_sk736_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk3578 = (it->second)._ca_address_sk3578;
                std::string _ca_county3585 = (it->second)._ca_county3585;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county3585_n{};
                memcpy(_ca_county3585_n.data(), (_ca_county3585).data(), (_ca_county3585).length());
                int32_t _ws_bill_addr_sk736 = tbl_JOIN_INNER_TD_7616985_output.getInt32(i, 0);
                int64_t _ws_ext_sales_price752 = tbl_JOIN_INNER_TD_7616985_output.getInt64(i, 1);
                int32_t _d_year3556 = tbl_JOIN_INNER_TD_7616985_output.getInt32(i, 2);
                int32_t _d_qoy3560 = tbl_JOIN_INNER_TD_7616985_output.getInt32(i, 3);
                tbl_JOIN_INNER_TD_6834355_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_county3585_n);
                tbl_JOIN_INNER_TD_6834355_output.setInt64(r, 0, _ws_ext_sales_price752);
                tbl_JOIN_INNER_TD_6834355_output.setInt32(r, 1, _d_year3556);
                tbl_JOIN_INNER_TD_6834355_output.setInt32(r, 2, _d_qoy3560);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6834355_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6834355_output #Row: " << tbl_JOIN_INNER_TD_6834355_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_6401051_key {
    std::string _ca_county4417;
    int32_t _d_qoy4392;
    int32_t _d_year4388;
    bool operator==(const SW_Aggregate_TD_6401051_key& other) const { return (_ca_county4417 == other._ca_county4417) && (_d_qoy4392 == other._d_qoy4392) && (_d_year4388 == other._d_year4388); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_6401051_key> {
    std::size_t operator() (const SW_Aggregate_TD_6401051_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._ca_county4417)) + (hash<int32_t>()(k._d_qoy4392)) + (hash<int32_t>()(k._d_year4388));
    }
};
}
struct SW_Aggregate_TD_6401051_payload {
    int64_t _store_sales3600_sum_0;
};
void SW_Aggregate_TD_6401051(Table &tbl_JOIN_INNER_TD_7452580_output, Table &tbl_Aggregate_TD_6401051_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(ca_county#4417, d_qoy#4392, d_year#4388, MakeDecimal(sum(UnscaledValue(ss_ext_sales_price#4374)),17,2) AS store_sales#3600)
    // Input: ListBuffer(ss_ext_sales_price#4374, d_year#4388, d_qoy#4392, ca_county#4417)
    // Output: ListBuffer(ca_county#4417, store_sales#3600)
    std::unordered_map<SW_Aggregate_TD_6401051_key, SW_Aggregate_TD_6401051_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_7452580_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ss_ext_sales_price4374 = tbl_JOIN_INNER_TD_7452580_output.getInt64(i, 0);
        int32_t _d_year4388 = tbl_JOIN_INNER_TD_7452580_output.getInt32(i, 1);
        int32_t _d_qoy4392 = tbl_JOIN_INNER_TD_7452580_output.getInt32(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _ca_county4417 = tbl_JOIN_INNER_TD_7452580_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        SW_Aggregate_TD_6401051_key k{std::string(_ca_county4417.data()), _d_qoy4392, _d_year4388};
        int64_t _store_sales3600_sum_0 = _ss_ext_sales_price4374;
        SW_Aggregate_TD_6401051_payload p{_store_sales3600_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._store_sales3600_sum_0 + _store_sales3600_sum_0;
            p._store_sales3600_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_county4417{};
        memcpy(_ca_county4417.data(), ((it.first)._ca_county4417).data(), ((it.first)._ca_county4417).length());
        tbl_Aggregate_TD_6401051_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_county4417);
        // _d_qoy4392 not required in the output table
        // _d_year4388 not required in the output table
        int64_t _store_sales3600 = (it.second)._store_sales3600_sum_0;
        tbl_Aggregate_TD_6401051_output.setInt64(r, 1, _store_sales3600);
        ++r;
    }
    tbl_Aggregate_TD_6401051_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_6401051_output #Row: " << tbl_Aggregate_TD_6401051_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6883781_key_leftMajor {
    std::string _ca_county61;
    bool operator==(const SW_JOIN_INNER_TD_6883781_key_leftMajor& other) const {
        return ((_ca_county61 == other._ca_county61));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6883781_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6883781_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._ca_county61));
    }
};
}
struct SW_JOIN_INNER_TD_6883781_payload_leftMajor {
    std::string _ca_county61;
    int32_t _d_year126;
    int64_t _store_sales3548;
};
struct SW_JOIN_INNER_TD_6883781_key_rightMajor {
    std::string _ca_county4352;
    bool operator==(const SW_JOIN_INNER_TD_6883781_key_rightMajor& other) const {
        return ((_ca_county4352 == other._ca_county4352));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6883781_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6883781_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._ca_county4352));
    }
};
}
struct SW_JOIN_INNER_TD_6883781_payload_rightMajor {
    std::string _ca_county4352;
    int64_t _store_sales3596;
};
void SW_JOIN_INNER_TD_6883781(Table &tbl_Aggregate_TD_7393156_output, Table &tbl_Aggregate_TD_7282392_output, Table &tbl_JOIN_INNER_TD_6883781_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ca_county#61 = ca_county#4352))
    // Left Table: ListBuffer(ca_county#61, d_year#126, store_sales#3548)
    // Right Table: ListBuffer(ca_county#4352, store_sales#3596)
    // Output Table: ListBuffer(ca_county#61, d_year#126, store_sales#3548, ca_county#4352, store_sales#3596)
    int left_nrow = tbl_Aggregate_TD_7393156_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_7282392_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6883781_key_leftMajor, SW_JOIN_INNER_TD_6883781_payload_leftMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_7393156_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ca_county61_k_n = tbl_Aggregate_TD_7393156_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_county61_k = std::string(_ca_county61_k_n.data());
            SW_JOIN_INNER_TD_6883781_key_leftMajor keyA{_ca_county61_k};
            std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n = tbl_Aggregate_TD_7393156_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_county61 = std::string(_ca_county61_n.data());
            int32_t _d_year126 = tbl_Aggregate_TD_7393156_output.getInt32(i, 1);
            int64_t _store_sales3548 = tbl_Aggregate_TD_7393156_output.getInt64(i, 2);
            SW_JOIN_INNER_TD_6883781_payload_leftMajor payloadA{_ca_county61, _d_year126, _store_sales3548};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_7282392_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ca_county4352_k_n = tbl_Aggregate_TD_7282392_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_county4352_k = std::string(_ca_county4352_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6883781_key_leftMajor{_ca_county4352_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _ca_county61 = (it->second)._ca_county61;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n{};
                memcpy(_ca_county61_n.data(), (_ca_county61).data(), (_ca_county61).length());
                int32_t _d_year126 = (it->second)._d_year126;
                int64_t _store_sales3548 = (it->second)._store_sales3548;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county4352_n = tbl_Aggregate_TD_7282392_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _ca_county4352 = std::string(_ca_county4352_n.data());
                int64_t _store_sales3596 = tbl_Aggregate_TD_7282392_output.getInt64(i, 1);
                tbl_JOIN_INNER_TD_6883781_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_county61_n);
                tbl_JOIN_INNER_TD_6883781_output.setInt32(r, 1, _d_year126);
                tbl_JOIN_INNER_TD_6883781_output.setInt64(r, 2, _store_sales3548);
                tbl_JOIN_INNER_TD_6883781_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_county4352_n);
                tbl_JOIN_INNER_TD_6883781_output.setInt64(r, 4, _store_sales3596);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6883781_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6883781_key_rightMajor, SW_JOIN_INNER_TD_6883781_payload_rightMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_7282392_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ca_county4352_k_n = tbl_Aggregate_TD_7282392_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_county4352_k = std::string(_ca_county4352_k_n.data());
            SW_JOIN_INNER_TD_6883781_key_rightMajor keyA{_ca_county4352_k};
            std::array<char, TPCDS_READ_MAX + 1> _ca_county4352_n = tbl_Aggregate_TD_7282392_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_county4352 = std::string(_ca_county4352_n.data());
            int64_t _store_sales3596 = tbl_Aggregate_TD_7282392_output.getInt64(i, 1);
            SW_JOIN_INNER_TD_6883781_payload_rightMajor payloadA{_ca_county4352, _store_sales3596};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_7393156_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ca_county61_k_n = tbl_Aggregate_TD_7393156_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_county61_k = std::string(_ca_county61_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6883781_key_rightMajor{_ca_county61_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _ca_county4352 = (it->second)._ca_county4352;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county4352_n{};
                memcpy(_ca_county4352_n.data(), (_ca_county4352).data(), (_ca_county4352).length());
                int64_t _store_sales3596 = (it->second)._store_sales3596;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n = tbl_Aggregate_TD_7393156_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _ca_county61 = std::string(_ca_county61_n.data());
                int32_t _d_year126 = tbl_Aggregate_TD_7393156_output.getInt32(i, 1);
                int64_t _store_sales3548 = tbl_Aggregate_TD_7393156_output.getInt64(i, 2);
                tbl_JOIN_INNER_TD_6883781_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_county4352_n);
                tbl_JOIN_INNER_TD_6883781_output.setInt64(r, 4, _store_sales3596);
                tbl_JOIN_INNER_TD_6883781_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_county61_n);
                tbl_JOIN_INNER_TD_6883781_output.setInt32(r, 1, _d_year126);
                tbl_JOIN_INNER_TD_6883781_output.setInt64(r, 2, _store_sales3548);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6883781_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6883781_output #Row: " << tbl_JOIN_INNER_TD_6883781_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5427652(Table &tbl_SerializeFromObject_TD_6872052_input, Table &tbl_Filter_TD_5427652_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ca_address_sk#4562) AND isnotnull(ca_county#4569)))
    // Input: ListBuffer(ca_address_sk#4562, ca_county#4569)
    // Output: ListBuffer(ca_address_sk#4562, ca_county#4569)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6872052_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ca_address_sk4562 = tbl_SerializeFromObject_TD_6872052_input.getInt32(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _ca_county4569 = tbl_SerializeFromObject_TD_6872052_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if ((_ca_address_sk4562!= 0) && _ca_county4569.data() != "NULL") {
            int32_t _ca_address_sk4562_t = tbl_SerializeFromObject_TD_6872052_input.getInt32(i, 0);
            tbl_Filter_TD_5427652_output.setInt32(r, 0, _ca_address_sk4562_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_county4569_t = tbl_SerializeFromObject_TD_6872052_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_5427652_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_county4569_t);
            r++;
        }
    }
    tbl_Filter_TD_5427652_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5427652_output #Row: " << tbl_Filter_TD_5427652_output.getNumRow() << std::endl;
}


struct SW_JOIN_INNER_TD_5780330_key_leftMajor {
    int32_t _ws_bill_addr_sk4431;
    bool operator==(const SW_JOIN_INNER_TD_5780330_key_leftMajor& other) const {
        return ((_ws_bill_addr_sk4431 == other._ws_bill_addr_sk4431));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5780330_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5780330_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_bill_addr_sk4431));
    }
};
}
struct SW_JOIN_INNER_TD_5780330_payload_leftMajor {
    int32_t _ws_bill_addr_sk4431;
    int64_t _ws_ext_sales_price4447;
    int32_t _d_year4464;
    int32_t _d_qoy4468;
};
struct SW_JOIN_INNER_TD_5780330_key_rightMajor {
    int32_t _ca_address_sk4486;
    bool operator==(const SW_JOIN_INNER_TD_5780330_key_rightMajor& other) const {
        return ((_ca_address_sk4486 == other._ca_address_sk4486));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5780330_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5780330_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk4486));
    }
};
}
struct SW_JOIN_INNER_TD_5780330_payload_rightMajor {
    int32_t _ca_address_sk4486;
    std::string _ca_county4493;
};
void SW_JOIN_INNER_TD_5780330(Table &tbl_JOIN_INNER_TD_6513082_output, Table &tbl_Filter_TD_6936522_output, Table &tbl_JOIN_INNER_TD_5780330_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_bill_addr_sk#4431 = ca_address_sk#4486))
    // Left Table: ListBuffer(ws_bill_addr_sk#4431, ws_ext_sales_price#4447, d_year#4464, d_qoy#4468)
    // Right Table: ListBuffer(ca_address_sk#4486, ca_county#4493)
    // Output Table: ListBuffer(ws_ext_sales_price#4447, d_year#4464, d_qoy#4468, ca_county#4493)
    int left_nrow = tbl_JOIN_INNER_TD_6513082_output.getNumRow();
    int right_nrow = tbl_Filter_TD_6936522_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5780330_key_leftMajor, SW_JOIN_INNER_TD_5780330_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_6513082_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_bill_addr_sk4431_k = tbl_JOIN_INNER_TD_6513082_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5780330_key_leftMajor keyA{_ws_bill_addr_sk4431_k};
            int32_t _ws_bill_addr_sk4431 = tbl_JOIN_INNER_TD_6513082_output.getInt32(i, 0);
            int64_t _ws_ext_sales_price4447 = tbl_JOIN_INNER_TD_6513082_output.getInt64(i, 1);
            int32_t _d_year4464 = tbl_JOIN_INNER_TD_6513082_output.getInt32(i, 2);
            int32_t _d_qoy4468 = tbl_JOIN_INNER_TD_6513082_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_5780330_payload_leftMajor payloadA{_ws_bill_addr_sk4431, _ws_ext_sales_price4447, _d_year4464, _d_qoy4468};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6936522_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk4486_k = tbl_Filter_TD_6936522_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5780330_key_leftMajor{_ca_address_sk4486_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_bill_addr_sk4431 = (it->second)._ws_bill_addr_sk4431;
                int64_t _ws_ext_sales_price4447 = (it->second)._ws_ext_sales_price4447;
                int32_t _d_year4464 = (it->second)._d_year4464;
                int32_t _d_qoy4468 = (it->second)._d_qoy4468;
                int32_t _ca_address_sk4486 = tbl_Filter_TD_6936522_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_county4493_n = tbl_Filter_TD_6936522_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_county4493 = std::string(_ca_county4493_n.data());
                tbl_JOIN_INNER_TD_5780330_output.setInt64(r, 0, _ws_ext_sales_price4447);
                tbl_JOIN_INNER_TD_5780330_output.setInt32(r, 1, _d_year4464);
                tbl_JOIN_INNER_TD_5780330_output.setInt32(r, 2, _d_qoy4468);
                tbl_JOIN_INNER_TD_5780330_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_county4493_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5780330_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5780330_key_rightMajor, SW_JOIN_INNER_TD_5780330_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_6936522_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk4486_k = tbl_Filter_TD_6936522_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5780330_key_rightMajor keyA{_ca_address_sk4486_k};
            int32_t _ca_address_sk4486 = tbl_Filter_TD_6936522_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_county4493_n = tbl_Filter_TD_6936522_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_county4493 = std::string(_ca_county4493_n.data());
            SW_JOIN_INNER_TD_5780330_payload_rightMajor payloadA{_ca_address_sk4486, _ca_county4493};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_6513082_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_bill_addr_sk4431_k = tbl_JOIN_INNER_TD_6513082_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5780330_key_rightMajor{_ws_bill_addr_sk4431_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk4486 = (it->second)._ca_address_sk4486;
                std::string _ca_county4493 = (it->second)._ca_county4493;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county4493_n{};
                memcpy(_ca_county4493_n.data(), (_ca_county4493).data(), (_ca_county4493).length());
                int32_t _ws_bill_addr_sk4431 = tbl_JOIN_INNER_TD_6513082_output.getInt32(i, 0);
                int64_t _ws_ext_sales_price4447 = tbl_JOIN_INNER_TD_6513082_output.getInt64(i, 1);
                int32_t _d_year4464 = tbl_JOIN_INNER_TD_6513082_output.getInt32(i, 2);
                int32_t _d_qoy4468 = tbl_JOIN_INNER_TD_6513082_output.getInt32(i, 3);
                tbl_JOIN_INNER_TD_5780330_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_county4493_n);
                tbl_JOIN_INNER_TD_5780330_output.setInt64(r, 0, _ws_ext_sales_price4447);
                tbl_JOIN_INNER_TD_5780330_output.setInt32(r, 1, _d_year4464);
                tbl_JOIN_INNER_TD_5780330_output.setInt32(r, 2, _d_qoy4468);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5780330_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5780330_output #Row: " << tbl_JOIN_INNER_TD_5780330_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_5281409_key {
    std::string _ca_county3585;
    int32_t _d_qoy3560;
    int32_t _d_year3556;
    bool operator==(const SW_Aggregate_TD_5281409_key& other) const { return (_ca_county3585 == other._ca_county3585) && (_d_qoy3560 == other._d_qoy3560) && (_d_year3556 == other._d_year3556); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_5281409_key> {
    std::size_t operator() (const SW_Aggregate_TD_5281409_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._ca_county3585)) + (hash<int32_t>()(k._d_qoy3560)) + (hash<int32_t>()(k._d_year3556));
    }
};
}
struct SW_Aggregate_TD_5281409_payload {
    int64_t _web_sales3549_sum_0;
};
void SW_Aggregate_TD_5281409(Table &tbl_JOIN_INNER_TD_6834355_output, Table &tbl_Aggregate_TD_5281409_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(ca_county#3585, d_qoy#3560, d_year#3556, MakeDecimal(sum(UnscaledValue(ws_ext_sales_price#752)),17,2) AS web_sales#3549)
    // Input: ListBuffer(ws_ext_sales_price#752, d_year#3556, d_qoy#3560, ca_county#3585)
    // Output: ListBuffer(ca_county#3585, web_sales#3549)
    std::unordered_map<SW_Aggregate_TD_5281409_key, SW_Aggregate_TD_5281409_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_6834355_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ws_ext_sales_price752 = tbl_JOIN_INNER_TD_6834355_output.getInt64(i, 0);
        int32_t _d_year3556 = tbl_JOIN_INNER_TD_6834355_output.getInt32(i, 1);
        int32_t _d_qoy3560 = tbl_JOIN_INNER_TD_6834355_output.getInt32(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _ca_county3585 = tbl_JOIN_INNER_TD_6834355_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        SW_Aggregate_TD_5281409_key k{std::string(_ca_county3585.data()), _d_qoy3560, _d_year3556};
        int64_t _web_sales3549_sum_0 = _ws_ext_sales_price752;
        SW_Aggregate_TD_5281409_payload p{_web_sales3549_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._web_sales3549_sum_0 + _web_sales3549_sum_0;
            p._web_sales3549_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_county3585{};
        memcpy(_ca_county3585.data(), ((it.first)._ca_county3585).data(), ((it.first)._ca_county3585).length());
        tbl_Aggregate_TD_5281409_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_county3585);
        // _d_qoy3560 not required in the output table
        // _d_year3556 not required in the output table
        int64_t _web_sales3549 = (it.second)._web_sales3549_sum_0;
        tbl_Aggregate_TD_5281409_output.setInt64(r, 1, _web_sales3549);
        ++r;
    }
    tbl_Aggregate_TD_5281409_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_5281409_output #Row: " << tbl_Aggregate_TD_5281409_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_56034_key_leftMajor {
    std::string _ca_county4352;
    bool operator==(const SW_JOIN_INNER_TD_56034_key_leftMajor& other) const {
        return ((_ca_county4352 == other._ca_county4352));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_56034_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_56034_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._ca_county4352));
    }
};
}
struct SW_JOIN_INNER_TD_56034_payload_leftMajor {
    std::string _ca_county61;
    int32_t _d_year126;
    int64_t _store_sales3548;
    std::string _ca_county4352;
    int64_t _store_sales3596;
};
struct SW_JOIN_INNER_TD_56034_key_rightMajor {
    std::string _ca_county4417;
    bool operator==(const SW_JOIN_INNER_TD_56034_key_rightMajor& other) const {
        return ((_ca_county4417 == other._ca_county4417));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_56034_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_56034_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._ca_county4417));
    }
};
}
struct SW_JOIN_INNER_TD_56034_payload_rightMajor {
    std::string _ca_county4417;
    int64_t _store_sales3600;
};
void SW_JOIN_INNER_TD_56034(Table &tbl_JOIN_INNER_TD_6883781_output, Table &tbl_Aggregate_TD_6401051_output, Table &tbl_JOIN_INNER_TD_56034_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ca_county#4352 = ca_county#4417))
    // Left Table: ListBuffer(ca_county#61, d_year#126, store_sales#3548, ca_county#4352, store_sales#3596)
    // Right Table: ListBuffer(ca_county#4417, store_sales#3600)
    // Output Table: ListBuffer(ca_county#61, d_year#126, store_sales#3548, store_sales#3596, store_sales#3600)
    int left_nrow = tbl_JOIN_INNER_TD_6883781_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_6401051_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_56034_key_leftMajor, SW_JOIN_INNER_TD_56034_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_6883781_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ca_county4352_k_n = tbl_JOIN_INNER_TD_6883781_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _ca_county4352_k = std::string(_ca_county4352_k_n.data());
            SW_JOIN_INNER_TD_56034_key_leftMajor keyA{_ca_county4352_k};
            std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n = tbl_JOIN_INNER_TD_6883781_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_county61 = std::string(_ca_county61_n.data());
            int32_t _d_year126 = tbl_JOIN_INNER_TD_6883781_output.getInt32(i, 1);
            int64_t _store_sales3548 = tbl_JOIN_INNER_TD_6883781_output.getInt64(i, 2);
            std::array<char, TPCDS_READ_MAX + 1> _ca_county4352_n = tbl_JOIN_INNER_TD_6883781_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _ca_county4352 = std::string(_ca_county4352_n.data());
            int64_t _store_sales3596 = tbl_JOIN_INNER_TD_6883781_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_56034_payload_leftMajor payloadA{_ca_county61, _d_year126, _store_sales3548, _ca_county4352, _store_sales3596};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_6401051_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ca_county4417_k_n = tbl_Aggregate_TD_6401051_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_county4417_k = std::string(_ca_county4417_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_56034_key_leftMajor{_ca_county4417_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _ca_county61 = (it->second)._ca_county61;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n{};
                memcpy(_ca_county61_n.data(), (_ca_county61).data(), (_ca_county61).length());
                int32_t _d_year126 = (it->second)._d_year126;
                int64_t _store_sales3548 = (it->second)._store_sales3548;
                std::string _ca_county4352 = (it->second)._ca_county4352;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county4352_n{};
                memcpy(_ca_county4352_n.data(), (_ca_county4352).data(), (_ca_county4352).length());
                int64_t _store_sales3596 = (it->second)._store_sales3596;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county4417_n = tbl_Aggregate_TD_6401051_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _ca_county4417 = std::string(_ca_county4417_n.data());
                int64_t _store_sales3600 = tbl_Aggregate_TD_6401051_output.getInt64(i, 1);
                tbl_JOIN_INNER_TD_56034_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_county61_n);
                tbl_JOIN_INNER_TD_56034_output.setInt32(r, 1, _d_year126);
                tbl_JOIN_INNER_TD_56034_output.setInt64(r, 2, _store_sales3548);
                tbl_JOIN_INNER_TD_56034_output.setInt64(r, 3, _store_sales3596);
                tbl_JOIN_INNER_TD_56034_output.setInt64(r, 4, _store_sales3600);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_56034_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_56034_key_rightMajor, SW_JOIN_INNER_TD_56034_payload_rightMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_6401051_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ca_county4417_k_n = tbl_Aggregate_TD_6401051_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_county4417_k = std::string(_ca_county4417_k_n.data());
            SW_JOIN_INNER_TD_56034_key_rightMajor keyA{_ca_county4417_k};
            std::array<char, TPCDS_READ_MAX + 1> _ca_county4417_n = tbl_Aggregate_TD_6401051_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_county4417 = std::string(_ca_county4417_n.data());
            int64_t _store_sales3600 = tbl_Aggregate_TD_6401051_output.getInt64(i, 1);
            SW_JOIN_INNER_TD_56034_payload_rightMajor payloadA{_ca_county4417, _store_sales3600};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_6883781_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ca_county4352_k_n = tbl_JOIN_INNER_TD_6883781_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
            std::string _ca_county4352_k = std::string(_ca_county4352_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_56034_key_rightMajor{_ca_county4352_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _ca_county4417 = (it->second)._ca_county4417;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county4417_n{};
                memcpy(_ca_county4417_n.data(), (_ca_county4417).data(), (_ca_county4417).length());
                int64_t _store_sales3600 = (it->second)._store_sales3600;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n = tbl_JOIN_INNER_TD_6883781_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _ca_county61 = std::string(_ca_county61_n.data());
                int32_t _d_year126 = tbl_JOIN_INNER_TD_6883781_output.getInt32(i, 1);
                int64_t _store_sales3548 = tbl_JOIN_INNER_TD_6883781_output.getInt64(i, 2);
                std::array<char, TPCDS_READ_MAX + 1> _ca_county4352_n = tbl_JOIN_INNER_TD_6883781_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
                std::string _ca_county4352 = std::string(_ca_county4352_n.data());
                int64_t _store_sales3596 = tbl_JOIN_INNER_TD_6883781_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_56034_output.setInt64(r, 4, _store_sales3600);
                tbl_JOIN_INNER_TD_56034_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_county61_n);
                tbl_JOIN_INNER_TD_56034_output.setInt32(r, 1, _d_year126);
                tbl_JOIN_INNER_TD_56034_output.setInt64(r, 2, _store_sales3548);
                tbl_JOIN_INNER_TD_56034_output.setInt64(r, 3, _store_sales3596);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_56034_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_56034_output #Row: " << tbl_JOIN_INNER_TD_56034_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_412391_key_leftMajor {
    int32_t _ws_bill_addr_sk4507;
    bool operator==(const SW_JOIN_INNER_TD_412391_key_leftMajor& other) const {
        return ((_ws_bill_addr_sk4507 == other._ws_bill_addr_sk4507));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_412391_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_412391_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_bill_addr_sk4507));
    }
};
}
struct SW_JOIN_INNER_TD_412391_payload_leftMajor {
    int32_t _ws_bill_addr_sk4507;
    int64_t _ws_ext_sales_price4523;
    int32_t _d_year4540;
    int32_t _d_qoy4544;
};
struct SW_JOIN_INNER_TD_412391_key_rightMajor {
    int32_t _ca_address_sk4562;
    bool operator==(const SW_JOIN_INNER_TD_412391_key_rightMajor& other) const {
        return ((_ca_address_sk4562 == other._ca_address_sk4562));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_412391_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_412391_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk4562));
    }
};
}
struct SW_JOIN_INNER_TD_412391_payload_rightMajor {
    int32_t _ca_address_sk4562;
    std::string _ca_county4569;
};
void SW_JOIN_INNER_TD_412391(Table &tbl_JOIN_INNER_TD_5648307_output, Table &tbl_Filter_TD_5427652_output, Table &tbl_JOIN_INNER_TD_412391_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ws_bill_addr_sk#4507 = ca_address_sk#4562))
    // Left Table: ListBuffer(ws_bill_addr_sk#4507, ws_ext_sales_price#4523, d_year#4540, d_qoy#4544)
    // Right Table: ListBuffer(ca_address_sk#4562, ca_county#4569)
    // Output Table: ListBuffer(ws_ext_sales_price#4523, d_year#4540, d_qoy#4544, ca_county#4569)
    int left_nrow = tbl_JOIN_INNER_TD_5648307_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5427652_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_412391_key_leftMajor, SW_JOIN_INNER_TD_412391_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_5648307_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_bill_addr_sk4507_k = tbl_JOIN_INNER_TD_5648307_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_412391_key_leftMajor keyA{_ws_bill_addr_sk4507_k};
            int32_t _ws_bill_addr_sk4507 = tbl_JOIN_INNER_TD_5648307_output.getInt32(i, 0);
            int64_t _ws_ext_sales_price4523 = tbl_JOIN_INNER_TD_5648307_output.getInt64(i, 1);
            int32_t _d_year4540 = tbl_JOIN_INNER_TD_5648307_output.getInt32(i, 2);
            int32_t _d_qoy4544 = tbl_JOIN_INNER_TD_5648307_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_412391_payload_leftMajor payloadA{_ws_bill_addr_sk4507, _ws_ext_sales_price4523, _d_year4540, _d_qoy4544};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5427652_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk4562_k = tbl_Filter_TD_5427652_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_412391_key_leftMajor{_ca_address_sk4562_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_bill_addr_sk4507 = (it->second)._ws_bill_addr_sk4507;
                int64_t _ws_ext_sales_price4523 = (it->second)._ws_ext_sales_price4523;
                int32_t _d_year4540 = (it->second)._d_year4540;
                int32_t _d_qoy4544 = (it->second)._d_qoy4544;
                int32_t _ca_address_sk4562 = tbl_Filter_TD_5427652_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_county4569_n = tbl_Filter_TD_5427652_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_county4569 = std::string(_ca_county4569_n.data());
                tbl_JOIN_INNER_TD_412391_output.setInt64(r, 0, _ws_ext_sales_price4523);
                tbl_JOIN_INNER_TD_412391_output.setInt32(r, 1, _d_year4540);
                tbl_JOIN_INNER_TD_412391_output.setInt32(r, 2, _d_qoy4544);
                tbl_JOIN_INNER_TD_412391_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_county4569_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_412391_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_412391_key_rightMajor, SW_JOIN_INNER_TD_412391_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5427652_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk4562_k = tbl_Filter_TD_5427652_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_412391_key_rightMajor keyA{_ca_address_sk4562_k};
            int32_t _ca_address_sk4562 = tbl_Filter_TD_5427652_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_county4569_n = tbl_Filter_TD_5427652_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_county4569 = std::string(_ca_county4569_n.data());
            SW_JOIN_INNER_TD_412391_payload_rightMajor payloadA{_ca_address_sk4562, _ca_county4569};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_5648307_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_bill_addr_sk4507_k = tbl_JOIN_INNER_TD_5648307_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_412391_key_rightMajor{_ws_bill_addr_sk4507_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk4562 = (it->second)._ca_address_sk4562;
                std::string _ca_county4569 = (it->second)._ca_county4569;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county4569_n{};
                memcpy(_ca_county4569_n.data(), (_ca_county4569).data(), (_ca_county4569).length());
                int32_t _ws_bill_addr_sk4507 = tbl_JOIN_INNER_TD_5648307_output.getInt32(i, 0);
                int64_t _ws_ext_sales_price4523 = tbl_JOIN_INNER_TD_5648307_output.getInt64(i, 1);
                int32_t _d_year4540 = tbl_JOIN_INNER_TD_5648307_output.getInt32(i, 2);
                int32_t _d_qoy4544 = tbl_JOIN_INNER_TD_5648307_output.getInt32(i, 3);
                tbl_JOIN_INNER_TD_412391_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 3, _ca_county4569_n);
                tbl_JOIN_INNER_TD_412391_output.setInt64(r, 0, _ws_ext_sales_price4523);
                tbl_JOIN_INNER_TD_412391_output.setInt32(r, 1, _d_year4540);
                tbl_JOIN_INNER_TD_412391_output.setInt32(r, 2, _d_qoy4544);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_412391_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_412391_output #Row: " << tbl_JOIN_INNER_TD_412391_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_4174487_key {
    std::string _ca_county4493;
    int32_t _d_qoy4468;
    int32_t _d_year4464;
    bool operator==(const SW_Aggregate_TD_4174487_key& other) const { return (_ca_county4493 == other._ca_county4493) && (_d_qoy4468 == other._d_qoy4468) && (_d_year4464 == other._d_year4464); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_4174487_key> {
    std::size_t operator() (const SW_Aggregate_TD_4174487_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._ca_county4493)) + (hash<int32_t>()(k._d_qoy4468)) + (hash<int32_t>()(k._d_year4464));
    }
};
}
struct SW_Aggregate_TD_4174487_payload {
    int64_t _web_sales3604_sum_0;
};
void SW_Aggregate_TD_4174487(Table &tbl_JOIN_INNER_TD_5780330_output, Table &tbl_Aggregate_TD_4174487_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(ca_county#4493, d_qoy#4468, d_year#4464, MakeDecimal(sum(UnscaledValue(ws_ext_sales_price#4447)),17,2) AS web_sales#3604)
    // Input: ListBuffer(ws_ext_sales_price#4447, d_year#4464, d_qoy#4468, ca_county#4493)
    // Output: ListBuffer(ca_county#4493, web_sales#3604)
    std::unordered_map<SW_Aggregate_TD_4174487_key, SW_Aggregate_TD_4174487_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_5780330_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ws_ext_sales_price4447 = tbl_JOIN_INNER_TD_5780330_output.getInt64(i, 0);
        int32_t _d_year4464 = tbl_JOIN_INNER_TD_5780330_output.getInt32(i, 1);
        int32_t _d_qoy4468 = tbl_JOIN_INNER_TD_5780330_output.getInt32(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _ca_county4493 = tbl_JOIN_INNER_TD_5780330_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        SW_Aggregate_TD_4174487_key k{std::string(_ca_county4493.data()), _d_qoy4468, _d_year4464};
        int64_t _web_sales3604_sum_0 = _ws_ext_sales_price4447;
        SW_Aggregate_TD_4174487_payload p{_web_sales3604_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._web_sales3604_sum_0 + _web_sales3604_sum_0;
            p._web_sales3604_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_county4493{};
        memcpy(_ca_county4493.data(), ((it.first)._ca_county4493).data(), ((it.first)._ca_county4493).length());
        tbl_Aggregate_TD_4174487_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_county4493);
        // _d_qoy4468 not required in the output table
        // _d_year4464 not required in the output table
        int64_t _web_sales3604 = (it.second)._web_sales3604_sum_0;
        tbl_Aggregate_TD_4174487_output.setInt64(r, 1, _web_sales3604);
        ++r;
    }
    tbl_Aggregate_TD_4174487_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_4174487_output #Row: " << tbl_Aggregate_TD_4174487_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4757004_key_leftMajor {
    std::string _ca_county61;
    bool operator==(const SW_JOIN_INNER_TD_4757004_key_leftMajor& other) const {
        return ((_ca_county61 == other._ca_county61));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4757004_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4757004_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._ca_county61));
    }
};
}
struct SW_JOIN_INNER_TD_4757004_payload_leftMajor {
    std::string _ca_county61;
    int32_t _d_year126;
    int64_t _store_sales3548;
    int64_t _store_sales3596;
    int64_t _store_sales3600;
};
struct SW_JOIN_INNER_TD_4757004_key_rightMajor {
    std::string _ca_county3585;
    bool operator==(const SW_JOIN_INNER_TD_4757004_key_rightMajor& other) const {
        return ((_ca_county3585 == other._ca_county3585));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4757004_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4757004_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._ca_county3585));
    }
};
}
struct SW_JOIN_INNER_TD_4757004_payload_rightMajor {
    std::string _ca_county3585;
    int64_t _web_sales3549;
};
void SW_JOIN_INNER_TD_4757004(Table &tbl_JOIN_INNER_TD_56034_output, Table &tbl_Aggregate_TD_5281409_output, Table &tbl_JOIN_INNER_TD_4757004_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ca_county#61 = ca_county#3585))
    // Left Table: ListBuffer(ca_county#61, d_year#126, store_sales#3548, store_sales#3596, store_sales#3600)
    // Right Table: ListBuffer(ca_county#3585, web_sales#3549)
    // Output Table: ListBuffer(ca_county#61, d_year#126, store_sales#3548, store_sales#3596, store_sales#3600, ca_county#3585, web_sales#3549)
    int left_nrow = tbl_JOIN_INNER_TD_56034_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_5281409_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4757004_key_leftMajor, SW_JOIN_INNER_TD_4757004_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_56034_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ca_county61_k_n = tbl_JOIN_INNER_TD_56034_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_county61_k = std::string(_ca_county61_k_n.data());
            SW_JOIN_INNER_TD_4757004_key_leftMajor keyA{_ca_county61_k};
            std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n = tbl_JOIN_INNER_TD_56034_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_county61 = std::string(_ca_county61_n.data());
            int32_t _d_year126 = tbl_JOIN_INNER_TD_56034_output.getInt32(i, 1);
            int64_t _store_sales3548 = tbl_JOIN_INNER_TD_56034_output.getInt64(i, 2);
            int64_t _store_sales3596 = tbl_JOIN_INNER_TD_56034_output.getInt64(i, 3);
            int64_t _store_sales3600 = tbl_JOIN_INNER_TD_56034_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_4757004_payload_leftMajor payloadA{_ca_county61, _d_year126, _store_sales3548, _store_sales3596, _store_sales3600};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_5281409_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ca_county3585_k_n = tbl_Aggregate_TD_5281409_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_county3585_k = std::string(_ca_county3585_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4757004_key_leftMajor{_ca_county3585_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _ca_county61 = (it->second)._ca_county61;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n{};
                memcpy(_ca_county61_n.data(), (_ca_county61).data(), (_ca_county61).length());
                int32_t _d_year126 = (it->second)._d_year126;
                int64_t _store_sales3548 = (it->second)._store_sales3548;
                int64_t _store_sales3596 = (it->second)._store_sales3596;
                int64_t _store_sales3600 = (it->second)._store_sales3600;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county3585_n = tbl_Aggregate_TD_5281409_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _ca_county3585 = std::string(_ca_county3585_n.data());
                int64_t _web_sales3549 = tbl_Aggregate_TD_5281409_output.getInt64(i, 1);
                tbl_JOIN_INNER_TD_4757004_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_county61_n);
                tbl_JOIN_INNER_TD_4757004_output.setInt32(r, 1, _d_year126);
                tbl_JOIN_INNER_TD_4757004_output.setInt64(r, 2, _store_sales3548);
                tbl_JOIN_INNER_TD_4757004_output.setInt64(r, 3, _store_sales3596);
                tbl_JOIN_INNER_TD_4757004_output.setInt64(r, 4, _store_sales3600);
                tbl_JOIN_INNER_TD_4757004_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _ca_county3585_n);
                tbl_JOIN_INNER_TD_4757004_output.setInt64(r, 6, _web_sales3549);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4757004_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4757004_key_rightMajor, SW_JOIN_INNER_TD_4757004_payload_rightMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_5281409_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ca_county3585_k_n = tbl_Aggregate_TD_5281409_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_county3585_k = std::string(_ca_county3585_k_n.data());
            SW_JOIN_INNER_TD_4757004_key_rightMajor keyA{_ca_county3585_k};
            std::array<char, TPCDS_READ_MAX + 1> _ca_county3585_n = tbl_Aggregate_TD_5281409_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_county3585 = std::string(_ca_county3585_n.data());
            int64_t _web_sales3549 = tbl_Aggregate_TD_5281409_output.getInt64(i, 1);
            SW_JOIN_INNER_TD_4757004_payload_rightMajor payloadA{_ca_county3585, _web_sales3549};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_56034_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ca_county61_k_n = tbl_JOIN_INNER_TD_56034_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_county61_k = std::string(_ca_county61_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4757004_key_rightMajor{_ca_county61_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _ca_county3585 = (it->second)._ca_county3585;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county3585_n{};
                memcpy(_ca_county3585_n.data(), (_ca_county3585).data(), (_ca_county3585).length());
                int64_t _web_sales3549 = (it->second)._web_sales3549;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n = tbl_JOIN_INNER_TD_56034_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _ca_county61 = std::string(_ca_county61_n.data());
                int32_t _d_year126 = tbl_JOIN_INNER_TD_56034_output.getInt32(i, 1);
                int64_t _store_sales3548 = tbl_JOIN_INNER_TD_56034_output.getInt64(i, 2);
                int64_t _store_sales3596 = tbl_JOIN_INNER_TD_56034_output.getInt64(i, 3);
                int64_t _store_sales3600 = tbl_JOIN_INNER_TD_56034_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_4757004_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _ca_county3585_n);
                tbl_JOIN_INNER_TD_4757004_output.setInt64(r, 6, _web_sales3549);
                tbl_JOIN_INNER_TD_4757004_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_county61_n);
                tbl_JOIN_INNER_TD_4757004_output.setInt32(r, 1, _d_year126);
                tbl_JOIN_INNER_TD_4757004_output.setInt64(r, 2, _store_sales3548);
                tbl_JOIN_INNER_TD_4757004_output.setInt64(r, 3, _store_sales3596);
                tbl_JOIN_INNER_TD_4757004_output.setInt64(r, 4, _store_sales3600);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4757004_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4757004_output #Row: " << tbl_JOIN_INNER_TD_4757004_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_3361928_key {
    std::string _ca_county4569;
    int32_t _d_qoy4544;
    int32_t _d_year4540;
    bool operator==(const SW_Aggregate_TD_3361928_key& other) const { return (_ca_county4569 == other._ca_county4569) && (_d_qoy4544 == other._d_qoy4544) && (_d_year4540 == other._d_year4540); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_3361928_key> {
    std::size_t operator() (const SW_Aggregate_TD_3361928_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._ca_county4569)) + (hash<int32_t>()(k._d_qoy4544)) + (hash<int32_t>()(k._d_year4540));
    }
};
}
struct SW_Aggregate_TD_3361928_payload {
    int64_t _web_sales3608_sum_0;
};
void SW_Aggregate_TD_3361928(Table &tbl_JOIN_INNER_TD_412391_output, Table &tbl_Aggregate_TD_3361928_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(ca_county#4569, d_qoy#4544, d_year#4540, MakeDecimal(sum(UnscaledValue(ws_ext_sales_price#4523)),17,2) AS web_sales#3608)
    // Input: ListBuffer(ws_ext_sales_price#4523, d_year#4540, d_qoy#4544, ca_county#4569)
    // Output: ListBuffer(ca_county#4569, web_sales#3608)
    std::unordered_map<SW_Aggregate_TD_3361928_key, SW_Aggregate_TD_3361928_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_412391_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ws_ext_sales_price4523 = tbl_JOIN_INNER_TD_412391_output.getInt64(i, 0);
        int32_t _d_year4540 = tbl_JOIN_INNER_TD_412391_output.getInt32(i, 1);
        int32_t _d_qoy4544 = tbl_JOIN_INNER_TD_412391_output.getInt32(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _ca_county4569 = tbl_JOIN_INNER_TD_412391_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        SW_Aggregate_TD_3361928_key k{std::string(_ca_county4569.data()), _d_qoy4544, _d_year4540};
        int64_t _web_sales3608_sum_0 = _ws_ext_sales_price4523;
        SW_Aggregate_TD_3361928_payload p{_web_sales3608_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._web_sales3608_sum_0 + _web_sales3608_sum_0;
            p._web_sales3608_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_county4569{};
        memcpy(_ca_county4569.data(), ((it.first)._ca_county4569).data(), ((it.first)._ca_county4569).length());
        tbl_Aggregate_TD_3361928_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_county4569);
        // _d_qoy4544 not required in the output table
        // _d_year4540 not required in the output table
        int64_t _web_sales3608 = (it.second)._web_sales3608_sum_0;
        tbl_Aggregate_TD_3361928_output.setInt64(r, 1, _web_sales3608);
        ++r;
    }
    tbl_Aggregate_TD_3361928_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_3361928_output #Row: " << tbl_Aggregate_TD_3361928_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_3159277_key_leftMajor {
    std::string _ca_county3585;
    bool operator==(const SW_JOIN_INNER_TD_3159277_key_leftMajor& other) const {
        return ((_ca_county3585 == other._ca_county3585));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3159277_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3159277_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._ca_county3585));
    }
};
}
struct SW_JOIN_INNER_TD_3159277_payload_leftMajor {
    std::string _ca_county61;
    int32_t _d_year126;
    int64_t _store_sales3548;
    int64_t _store_sales3596;
    int64_t _store_sales3600;
    std::string _ca_county3585;
    int64_t _web_sales3549;
};
struct SW_JOIN_INNER_TD_3159277_key_rightMajor {
    std::string _ca_county4493;
    bool operator==(const SW_JOIN_INNER_TD_3159277_key_rightMajor& other) const {
        return ((_ca_county4493 == other._ca_county4493));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3159277_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3159277_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._ca_county4493));
    }
};
}
struct SW_JOIN_INNER_TD_3159277_payload_rightMajor {
    std::string _ca_county4493;
    int64_t _web_sales3604;
};
void SW_JOIN_INNER_TD_3159277(Table &tbl_JOIN_INNER_TD_4757004_output, Table &tbl_Aggregate_TD_4174487_output, Table &tbl_JOIN_INNER_TD_3159277_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((ca_county#3585 = ca_county#4493) AND (CASE WHEN (web_sales#3549 > 0.00) THEN CheckOverflow((promote_precision(web_sales#3604) / promote_precision(web_sales#3549)), DecimalType(37,20), true) END > CASE WHEN (store_sales#3548 > 0.00) THEN CheckOverflow((promote_precision(store_sales#3596) / promote_precision(store_sales#3548)), DecimalType(37,20), true) END)))
    // Left Table: ListBuffer(ca_county#61, d_year#126, store_sales#3548, store_sales#3596, store_sales#3600, ca_county#3585, web_sales#3549)
    // Right Table: ListBuffer(ca_county#4493, web_sales#3604)
    // Output Table: ListBuffer(ca_county#61, d_year#126, store_sales#3548, store_sales#3596, store_sales#3600, ca_county#3585, web_sales#3549, web_sales#3604)
    int left_nrow = tbl_JOIN_INNER_TD_4757004_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_4174487_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3159277_key_leftMajor, SW_JOIN_INNER_TD_3159277_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_4757004_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ca_county3585_k_n = tbl_JOIN_INNER_TD_4757004_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _ca_county3585_k = std::string(_ca_county3585_k_n.data());
            SW_JOIN_INNER_TD_3159277_key_leftMajor keyA{_ca_county3585_k};
            std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n = tbl_JOIN_INNER_TD_4757004_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_county61 = std::string(_ca_county61_n.data());
            int32_t _d_year126 = tbl_JOIN_INNER_TD_4757004_output.getInt32(i, 1);
            int64_t _store_sales3548 = tbl_JOIN_INNER_TD_4757004_output.getInt64(i, 2);
            int64_t _store_sales3596 = tbl_JOIN_INNER_TD_4757004_output.getInt64(i, 3);
            int64_t _store_sales3600 = tbl_JOIN_INNER_TD_4757004_output.getInt64(i, 4);
            std::array<char, TPCDS_READ_MAX + 1> _ca_county3585_n = tbl_JOIN_INNER_TD_4757004_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _ca_county3585 = std::string(_ca_county3585_n.data());
            int64_t _web_sales3549 = tbl_JOIN_INNER_TD_4757004_output.getInt64(i, 6);
            SW_JOIN_INNER_TD_3159277_payload_leftMajor payloadA{_ca_county61, _d_year126, _store_sales3548, _store_sales3596, _store_sales3600, _ca_county3585, _web_sales3549};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_4174487_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ca_county4493_k_n = tbl_Aggregate_TD_4174487_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_county4493_k = std::string(_ca_county4493_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3159277_key_leftMajor{_ca_county4493_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _ca_county61 = (it->second)._ca_county61;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n{};
                memcpy(_ca_county61_n.data(), (_ca_county61).data(), (_ca_county61).length());
                int32_t _d_year126 = (it->second)._d_year126;
                int64_t _store_sales3548 = (it->second)._store_sales3548;
                int64_t _store_sales3596 = (it->second)._store_sales3596;
                int64_t _store_sales3600 = (it->second)._store_sales3600;
                std::string _ca_county3585 = (it->second)._ca_county3585;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county3585_n{};
                memcpy(_ca_county3585_n.data(), (_ca_county3585).data(), (_ca_county3585).length());
                int64_t _web_sales3549 = (it->second)._web_sales3549;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county4493_n = tbl_Aggregate_TD_4174487_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _ca_county4493 = std::string(_ca_county4493_n.data());
                int64_t _web_sales3604 = tbl_Aggregate_TD_4174487_output.getInt64(i, 1);
                tbl_JOIN_INNER_TD_3159277_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_county61_n);
                tbl_JOIN_INNER_TD_3159277_output.setInt32(r, 1, _d_year126);
                tbl_JOIN_INNER_TD_3159277_output.setInt64(r, 2, _store_sales3548);
                tbl_JOIN_INNER_TD_3159277_output.setInt64(r, 3, _store_sales3596);
                tbl_JOIN_INNER_TD_3159277_output.setInt64(r, 4, _store_sales3600);
                tbl_JOIN_INNER_TD_3159277_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _ca_county3585_n);
                tbl_JOIN_INNER_TD_3159277_output.setInt64(r, 6, _web_sales3549);
                tbl_JOIN_INNER_TD_3159277_output.setInt64(r, 7, _web_sales3604);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3159277_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3159277_key_rightMajor, SW_JOIN_INNER_TD_3159277_payload_rightMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_4174487_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ca_county4493_k_n = tbl_Aggregate_TD_4174487_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_county4493_k = std::string(_ca_county4493_k_n.data());
            SW_JOIN_INNER_TD_3159277_key_rightMajor keyA{_ca_county4493_k};
            std::array<char, TPCDS_READ_MAX + 1> _ca_county4493_n = tbl_Aggregate_TD_4174487_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_county4493 = std::string(_ca_county4493_n.data());
            int64_t _web_sales3604 = tbl_Aggregate_TD_4174487_output.getInt64(i, 1);
            SW_JOIN_INNER_TD_3159277_payload_rightMajor payloadA{_ca_county4493, _web_sales3604};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_4757004_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ca_county3585_k_n = tbl_JOIN_INNER_TD_4757004_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _ca_county3585_k = std::string(_ca_county3585_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3159277_key_rightMajor{_ca_county3585_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _ca_county4493 = (it->second)._ca_county4493;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county4493_n{};
                memcpy(_ca_county4493_n.data(), (_ca_county4493).data(), (_ca_county4493).length());
                int64_t _web_sales3604 = (it->second)._web_sales3604;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n = tbl_JOIN_INNER_TD_4757004_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _ca_county61 = std::string(_ca_county61_n.data());
                int32_t _d_year126 = tbl_JOIN_INNER_TD_4757004_output.getInt32(i, 1);
                int64_t _store_sales3548 = tbl_JOIN_INNER_TD_4757004_output.getInt64(i, 2);
                int64_t _store_sales3596 = tbl_JOIN_INNER_TD_4757004_output.getInt64(i, 3);
                int64_t _store_sales3600 = tbl_JOIN_INNER_TD_4757004_output.getInt64(i, 4);
                std::array<char, TPCDS_READ_MAX + 1> _ca_county3585_n = tbl_JOIN_INNER_TD_4757004_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _ca_county3585 = std::string(_ca_county3585_n.data());
                int64_t _web_sales3549 = tbl_JOIN_INNER_TD_4757004_output.getInt64(i, 6);
                tbl_JOIN_INNER_TD_3159277_output.setInt64(r, 7, _web_sales3604);
                tbl_JOIN_INNER_TD_3159277_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_county61_n);
                tbl_JOIN_INNER_TD_3159277_output.setInt32(r, 1, _d_year126);
                tbl_JOIN_INNER_TD_3159277_output.setInt64(r, 2, _store_sales3548);
                tbl_JOIN_INNER_TD_3159277_output.setInt64(r, 3, _store_sales3596);
                tbl_JOIN_INNER_TD_3159277_output.setInt64(r, 4, _store_sales3600);
                tbl_JOIN_INNER_TD_3159277_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 5, _ca_county3585_n);
                tbl_JOIN_INNER_TD_3159277_output.setInt64(r, 6, _web_sales3549);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3159277_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_3159277_output #Row: " << tbl_JOIN_INNER_TD_3159277_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_2833924_key_leftMajor {
    std::string _ca_county3585;
    bool operator==(const SW_JOIN_INNER_TD_2833924_key_leftMajor& other) const {
        return ((_ca_county3585 == other._ca_county3585));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_2833924_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_2833924_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._ca_county3585));
    }
};
}
struct SW_JOIN_INNER_TD_2833924_payload_leftMajor {
    std::string _ca_county61;
    int32_t _d_year126;
    int64_t _store_sales3548;
    int64_t _store_sales3596;
    int64_t _store_sales3600;
    std::string _ca_county3585;
    int64_t _web_sales3549;
    int64_t _web_sales3604;
};
struct SW_JOIN_INNER_TD_2833924_key_rightMajor {
    std::string _ca_county4569;
    bool operator==(const SW_JOIN_INNER_TD_2833924_key_rightMajor& other) const {
        return ((_ca_county4569 == other._ca_county4569));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_2833924_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_2833924_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._ca_county4569));
    }
};
}
struct SW_JOIN_INNER_TD_2833924_payload_rightMajor {
    std::string _ca_county4569;
    int64_t _web_sales3608;
};
void SW_JOIN_INNER_TD_2833924(Table &tbl_JOIN_INNER_TD_3159277_output, Table &tbl_Aggregate_TD_3361928_output, Table &tbl_JOIN_INNER_TD_2833924_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((ca_county#3585 = ca_county#4569) AND (CASE WHEN (web_sales#3604 > 0.00) THEN CheckOverflow((promote_precision(web_sales#3608) / promote_precision(web_sales#3604)), DecimalType(37,20), true) END > CASE WHEN (store_sales#3596 > 0.00) THEN CheckOverflow((promote_precision(store_sales#3600) / promote_precision(store_sales#3596)), DecimalType(37,20), true) END)))
    // Left Table: ListBuffer(ca_county#61, d_year#126, store_sales#3548, store_sales#3596, store_sales#3600, ca_county#3585, web_sales#3549, web_sales#3604)
    // Right Table: ListBuffer(ca_county#4569, web_sales#3608)
    // Output Table: ListBuffer(ca_county#61, d_year#126, web_sales#3604, web_sales#3549, store_sales#3596, store_sales#3548, web_sales#3608, store_sales#3600)
    int left_nrow = tbl_JOIN_INNER_TD_3159277_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_3361928_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_2833924_key_leftMajor, SW_JOIN_INNER_TD_2833924_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_3159277_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ca_county3585_k_n = tbl_JOIN_INNER_TD_3159277_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _ca_county3585_k = std::string(_ca_county3585_k_n.data());
            SW_JOIN_INNER_TD_2833924_key_leftMajor keyA{_ca_county3585_k};
            std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n = tbl_JOIN_INNER_TD_3159277_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_county61 = std::string(_ca_county61_n.data());
            int32_t _d_year126 = tbl_JOIN_INNER_TD_3159277_output.getInt32(i, 1);
            int64_t _store_sales3548 = tbl_JOIN_INNER_TD_3159277_output.getInt64(i, 2);
            int64_t _store_sales3596 = tbl_JOIN_INNER_TD_3159277_output.getInt64(i, 3);
            int64_t _store_sales3600 = tbl_JOIN_INNER_TD_3159277_output.getInt64(i, 4);
            std::array<char, TPCDS_READ_MAX + 1> _ca_county3585_n = tbl_JOIN_INNER_TD_3159277_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _ca_county3585 = std::string(_ca_county3585_n.data());
            int64_t _web_sales3549 = tbl_JOIN_INNER_TD_3159277_output.getInt64(i, 6);
            int64_t _web_sales3604 = tbl_JOIN_INNER_TD_3159277_output.getInt64(i, 7);
            SW_JOIN_INNER_TD_2833924_payload_leftMajor payloadA{_ca_county61, _d_year126, _store_sales3548, _store_sales3596, _store_sales3600, _ca_county3585, _web_sales3549, _web_sales3604};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_3361928_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ca_county4569_k_n = tbl_Aggregate_TD_3361928_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_county4569_k = std::string(_ca_county4569_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_2833924_key_leftMajor{_ca_county4569_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _ca_county61 = (it->second)._ca_county61;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n{};
                memcpy(_ca_county61_n.data(), (_ca_county61).data(), (_ca_county61).length());
                int32_t _d_year126 = (it->second)._d_year126;
                int64_t _store_sales3548 = (it->second)._store_sales3548;
                int64_t _store_sales3596 = (it->second)._store_sales3596;
                int64_t _store_sales3600 = (it->second)._store_sales3600;
                std::string _ca_county3585 = (it->second)._ca_county3585;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county3585_n{};
                memcpy(_ca_county3585_n.data(), (_ca_county3585).data(), (_ca_county3585).length());
                int64_t _web_sales3549 = (it->second)._web_sales3549;
                int64_t _web_sales3604 = (it->second)._web_sales3604;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county4569_n = tbl_Aggregate_TD_3361928_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _ca_county4569 = std::string(_ca_county4569_n.data());
                int64_t _web_sales3608 = tbl_Aggregate_TD_3361928_output.getInt64(i, 1);
                tbl_JOIN_INNER_TD_2833924_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_county61_n);
                tbl_JOIN_INNER_TD_2833924_output.setInt32(r, 1, _d_year126);
                tbl_JOIN_INNER_TD_2833924_output.setInt64(r, 5, _store_sales3548);
                tbl_JOIN_INNER_TD_2833924_output.setInt64(r, 4, _store_sales3596);
                tbl_JOIN_INNER_TD_2833924_output.setInt64(r, 7, _store_sales3600);
                tbl_JOIN_INNER_TD_2833924_output.setInt64(r, 3, _web_sales3549);
                tbl_JOIN_INNER_TD_2833924_output.setInt64(r, 2, _web_sales3604);
                tbl_JOIN_INNER_TD_2833924_output.setInt64(r, 6, _web_sales3608);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_2833924_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_2833924_key_rightMajor, SW_JOIN_INNER_TD_2833924_payload_rightMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_3361928_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ca_county4569_k_n = tbl_Aggregate_TD_3361928_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_county4569_k = std::string(_ca_county4569_k_n.data());
            SW_JOIN_INNER_TD_2833924_key_rightMajor keyA{_ca_county4569_k};
            std::array<char, TPCDS_READ_MAX + 1> _ca_county4569_n = tbl_Aggregate_TD_3361928_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_county4569 = std::string(_ca_county4569_n.data());
            int64_t _web_sales3608 = tbl_Aggregate_TD_3361928_output.getInt64(i, 1);
            SW_JOIN_INNER_TD_2833924_payload_rightMajor payloadA{_ca_county4569, _web_sales3608};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_3159277_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _ca_county3585_k_n = tbl_JOIN_INNER_TD_3159277_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
            std::string _ca_county3585_k = std::string(_ca_county3585_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_2833924_key_rightMajor{_ca_county3585_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _ca_county4569 = (it->second)._ca_county4569;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county4569_n{};
                memcpy(_ca_county4569_n.data(), (_ca_county4569).data(), (_ca_county4569).length());
                int64_t _web_sales3608 = (it->second)._web_sales3608;
                std::array<char, TPCDS_READ_MAX + 1> _ca_county61_n = tbl_JOIN_INNER_TD_3159277_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _ca_county61 = std::string(_ca_county61_n.data());
                int32_t _d_year126 = tbl_JOIN_INNER_TD_3159277_output.getInt32(i, 1);
                int64_t _store_sales3548 = tbl_JOIN_INNER_TD_3159277_output.getInt64(i, 2);
                int64_t _store_sales3596 = tbl_JOIN_INNER_TD_3159277_output.getInt64(i, 3);
                int64_t _store_sales3600 = tbl_JOIN_INNER_TD_3159277_output.getInt64(i, 4);
                std::array<char, TPCDS_READ_MAX + 1> _ca_county3585_n = tbl_JOIN_INNER_TD_3159277_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 5);
                std::string _ca_county3585 = std::string(_ca_county3585_n.data());
                int64_t _web_sales3549 = tbl_JOIN_INNER_TD_3159277_output.getInt64(i, 6);
                int64_t _web_sales3604 = tbl_JOIN_INNER_TD_3159277_output.getInt64(i, 7);
                tbl_JOIN_INNER_TD_2833924_output.setInt64(r, 6, _web_sales3608);
                tbl_JOIN_INNER_TD_2833924_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_county61_n);
                tbl_JOIN_INNER_TD_2833924_output.setInt32(r, 1, _d_year126);
                tbl_JOIN_INNER_TD_2833924_output.setInt64(r, 5, _store_sales3548);
                tbl_JOIN_INNER_TD_2833924_output.setInt64(r, 4, _store_sales3596);
                tbl_JOIN_INNER_TD_2833924_output.setInt64(r, 7, _store_sales3600);
                tbl_JOIN_INNER_TD_2833924_output.setInt64(r, 3, _web_sales3549);
                tbl_JOIN_INNER_TD_2833924_output.setInt64(r, 2, _web_sales3604);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_2833924_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_2833924_output #Row: " << tbl_JOIN_INNER_TD_2833924_output.getNumRow() << std::endl;
}

void SW_Project_TD_1506350(Table &tbl_JOIN_INNER_TD_2833924_output, Table &tbl_Project_TD_1506350_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(CheckOverflow((promote_precision(web_sales#3604) / promote_precision(web_sales#3549)), DecimalType(37,20), true) AS web_q1_q2_increase#3544, CheckOverflow((promote_precision(store_sales#3596) / promote_precision(store_sales#3548)), DecimalType(37,20), true) AS store_q1_q2_increase#3545, CheckOverflow((promote_precision(web_sales#3608) / promote_precision(web_sales#3604)), DecimalType(37,20), true) AS web_q2_q3_increase#3546, CheckOverflow((promote_precision(store_sales#3600) / promote_precision(store_sales#3596)), DecimalType(37,20), true) AS store_q2_q3_increase#3547)
    // Input: ListBuffer(ca_county#61, d_year#126, web_sales#3604, web_sales#3549, store_sales#3596, store_sales#3548, web_sales#3608, store_sales#3600)
    // Output: ListBuffer(ca_county#61, d_year#126, web_q1_q2_increase#3544, store_q1_q2_increase#3545, web_q2_q3_increase#3546, store_q2_q3_increase#3547)
    int nrow1 = tbl_JOIN_INNER_TD_2833924_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_county61 = tbl_JOIN_INNER_TD_2833924_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        int32_t _d_year126 = tbl_JOIN_INNER_TD_2833924_output.getInt32(i, 1);
        int64_t _web_sales3604 = tbl_JOIN_INNER_TD_2833924_output.getInt64(i, 2);
        int64_t _web_sales3549 = tbl_JOIN_INNER_TD_2833924_output.getInt64(i, 3);
        int64_t _store_sales3596 = tbl_JOIN_INNER_TD_2833924_output.getInt64(i, 4);
        int64_t _store_sales3548 = tbl_JOIN_INNER_TD_2833924_output.getInt64(i, 5);
        int64_t _web_sales3608 = tbl_JOIN_INNER_TD_2833924_output.getInt64(i, 6);
        int64_t _store_sales3600 = tbl_JOIN_INNER_TD_2833924_output.getInt64(i, 7);
        int64_t _web_q1_q2_increase3544 = (_web_sales3604 / _web_sales3549);
        tbl_Project_TD_1506350_output.setInt64(i, 2, _web_q1_q2_increase3544);
        int64_t _store_q1_q2_increase3545 = (_store_sales3596 / _store_sales3548);
        tbl_Project_TD_1506350_output.setInt64(i, 3, _store_q1_q2_increase3545);
        int64_t _web_q2_q3_increase3546 = (_web_sales3608 / _web_sales3604);
        tbl_Project_TD_1506350_output.setInt64(i, 4, _web_q2_q3_increase3546);
        int64_t _store_q2_q3_increase3547 = (_store_sales3600 / _store_sales3596);
        tbl_Project_TD_1506350_output.setInt64(i, 5, _store_q2_q3_increase3547);
        tbl_Project_TD_1506350_output.setcharN<char, TPCDS_READ_MAX + 1>(i, 0, _ca_county61);
        tbl_Project_TD_1506350_output.setInt32(i, 1, _d_year126);
    }
    tbl_Project_TD_1506350_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_1506350_output #Row: " << tbl_Project_TD_1506350_output.getNumRow() << std::endl;
}

void SW_Sort_TD_0853836(Table &tbl_Project_TD_1506350_output, Table &tbl_Sort_TD_0853836_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(ca_county#61 ASC NULLS FIRST)
    // Input: ListBuffer(ca_county#61, d_year#126, web_q1_q2_increase#3544, store_q1_q2_increase#3545, web_q2_q3_increase#3546, store_q2_q3_increase#3547)
    // Output: ListBuffer(ca_county#61, d_year#126, web_q1_q2_increase#3544, store_q1_q2_increase#3545, web_q2_q3_increase#3546, store_q2_q3_increase#3547)
    struct SW_Sort_TD_0853836Row {
        std::string _ca_county61;
        int32_t _d_year126;
        int64_t _web_q1_q2_increase3544;
        int64_t _store_q1_q2_increase3545;
        int64_t _web_q2_q3_increase3546;
        int64_t _store_q2_q3_increase3547;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_0853836Row& a, const SW_Sort_TD_0853836Row& b) const { return 
 (a._ca_county61 < b._ca_county61); 
}
    }SW_Sort_TD_0853836_order; 

    int nrow1 = tbl_Project_TD_1506350_output.getNumRow();
    std::vector<SW_Sort_TD_0853836Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_county61 = tbl_Project_TD_1506350_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        int32_t _d_year126 = tbl_Project_TD_1506350_output.getInt32(i, 1);
        int64_t _web_q1_q2_increase3544 = tbl_Project_TD_1506350_output.getInt64(i, 2);
        int64_t _store_q1_q2_increase3545 = tbl_Project_TD_1506350_output.getInt64(i, 3);
        int64_t _web_q2_q3_increase3546 = tbl_Project_TD_1506350_output.getInt64(i, 4);
        int64_t _store_q2_q3_increase3547 = tbl_Project_TD_1506350_output.getInt64(i, 5);
        SW_Sort_TD_0853836Row t = {std::string(_ca_county61.data()),_d_year126,_web_q1_q2_increase3544,_store_q1_q2_increase3545,_web_q2_q3_increase3546,_store_q2_q3_increase3547};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_0853836_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_county61{};
        memcpy(_ca_county61.data(), (it._ca_county61).data(), (it._ca_county61).length());
        tbl_Sort_TD_0853836_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _ca_county61);
        tbl_Sort_TD_0853836_output.setInt32(r, 1, it._d_year126);
        tbl_Sort_TD_0853836_output.setInt64(r, 2, it._web_q1_q2_increase3544);
        tbl_Sort_TD_0853836_output.setInt64(r, 3, it._store_q1_q2_increase3545);
        tbl_Sort_TD_0853836_output.setInt64(r, 4, it._web_q2_q3_increase3546);
        tbl_Sort_TD_0853836_output.setInt64(r, 5, it._store_q2_q3_increase3547);
        if (r < 10) {
            std::cout << (it._ca_county61).data() << " " << it._d_year126 << " " << it._web_q1_q2_increase3544 << " " << it._store_q1_q2_increase3545 << " " << it._web_q2_q3_increase3546 << " " << it._store_q2_q3_increase3547 << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_0853836_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_0853836_output #Row: " << tbl_Sort_TD_0853836_output.getNumRow() << std::endl;
}

