#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_7643535(Table &tbl_SerializeFromObject_TD_8212594_input, Table &tbl_Filter_TD_7643535_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_category#3873))
    // Input: ListBuffer(i_current_price#3866, i_category#3873)
    // Output: ListBuffer(i_current_price#3866, i_category#3873)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8212594_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category3873 = tbl_SerializeFromObject_TD_8212594_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        if (_i_category3873.data() != "NULL") {
            int64_t _i_current_price3866_t = tbl_SerializeFromObject_TD_8212594_input.getInt64(i, 0);
            tbl_Filter_TD_7643535_output.setInt64(r, 0, _i_current_price3866_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_category3873_t = tbl_SerializeFromObject_TD_8212594_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_7643535_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category3873_t);
            r++;
        }
    }
    tbl_Filter_TD_7643535_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7643535_output #Row: " << tbl_Filter_TD_7643535_output.getNumRow() << std::endl;
}

void SW_Filter_TD_761648(Table &tbl_SerializeFromObject_TD_8183182_input, Table &tbl_Filter_TD_761648_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3839) AND isnotnull(d_moy#3841)) AND ((d_year#3839 = 2001) AND (d_moy#3841 = 1))))
    // Input: ListBuffer(d_month_seq#3836, d_year#3839, d_moy#3841)
    // Output: ListBuffer(d_month_seq#3836)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8183182_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3839 = tbl_SerializeFromObject_TD_8183182_input.getInt32(i, 1);
        int32_t _d_moy3841 = tbl_SerializeFromObject_TD_8183182_input.getInt32(i, 2);
        if (((_d_year3839!= 0) && (_d_moy3841!= 0)) && ((_d_year3839 == 2001) && (_d_moy3841 == 1))) {
            int32_t _d_month_seq3836_t = tbl_SerializeFromObject_TD_8183182_input.getInt32(i, 0);
            tbl_Filter_TD_761648_output.setInt32(r, 0, _d_month_seq3836_t);
            r++;
        }
    }
    tbl_Filter_TD_761648_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_761648_output #Row: " << tbl_Filter_TD_761648_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7189205(Table &tbl_SerializeFromObject_TD_8566050_input, Table &tbl_Filter_TD_7189205_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(c_current_addr_sk#4) AND isnotnull(c_customer_sk#0)))
    // Input: ListBuffer(c_customer_sk#0, c_current_addr_sk#4)
    // Output: ListBuffer(c_customer_sk#0, c_current_addr_sk#4)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8566050_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_current_addr_sk4 = tbl_SerializeFromObject_TD_8566050_input.getInt32(i, 1);
        int32_t _c_customer_sk0 = tbl_SerializeFromObject_TD_8566050_input.getInt32(i, 0);
        if ((_c_current_addr_sk4!= 0) && (_c_customer_sk0!= 0)) {
            int32_t _c_customer_sk0_t = tbl_SerializeFromObject_TD_8566050_input.getInt32(i, 0);
            tbl_Filter_TD_7189205_output.setInt32(r, 0, _c_customer_sk0_t);
            int32_t _c_current_addr_sk4_t = tbl_SerializeFromObject_TD_8566050_input.getInt32(i, 1);
            tbl_Filter_TD_7189205_output.setInt32(r, 1, _c_current_addr_sk4_t);
            r++;
        }
    }
    tbl_Filter_TD_7189205_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7189205_output #Row: " << tbl_Filter_TD_7189205_output.getNumRow() << std::endl;
}

void SW_Filter_TD_792899(Table &tbl_SerializeFromObject_TD_8824865_input, Table &tbl_Filter_TD_792899_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ca_address_sk#54))
    // Input: ListBuffer(ca_address_sk#54, ca_state#62)
    // Output: ListBuffer(ca_address_sk#54, ca_state#62)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8824865_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ca_address_sk54 = tbl_SerializeFromObject_TD_8824865_input.getInt32(i, 0);
        if (_ca_address_sk54!= 0) {
            int32_t _ca_address_sk54_t = tbl_SerializeFromObject_TD_8824865_input.getInt32(i, 0);
            tbl_Filter_TD_792899_output.setInt32(r, 0, _ca_address_sk54_t);
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_t = tbl_SerializeFromObject_TD_8824865_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_792899_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _ca_state62_t);
            r++;
        }
    }
    tbl_Filter_TD_792899_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_792899_output #Row: " << tbl_Filter_TD_792899_output.getNumRow() << std::endl;
}

typedef std::string SW_Aggregate_TD_6617436_key;
struct SW_Aggregate_TD_6617436_payload {
    int64_t _avgi_current_price3832_avg_0;
};
void SW_Aggregate_TD_6617436(Table &tbl_Filter_TD_7643535_output, Table &tbl_Aggregate_TD_6617436_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(i_category#3873, cast((avg(UnscaledValue(i_current_price#3866)) / 100.0) as decimal(11,6)) AS avg(i_current_price)#3832)
    // Input: ListBuffer(i_current_price#3866, i_category#3873)
    // Output: ListBuffer(avg(i_current_price)#3832, i_category#3873)
    std::unordered_map<SW_Aggregate_TD_6617436_key, SW_Aggregate_TD_6617436_payload> ht1;
    int nrow1 = tbl_Filter_TD_7643535_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _i_current_price3866 = tbl_Filter_TD_7643535_output.getInt64(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_category3873 = tbl_Filter_TD_7643535_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        SW_Aggregate_TD_6617436_key k = std::string(_i_category3873.data());
        int64_t _avgi_current_price3832_avg_0 = _i_current_price3866;
        SW_Aggregate_TD_6617436_payload p{_avgi_current_price3832_avg_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t avg_0 = ((it->second)._avgi_current_price3832_avg_0 + _avgi_current_price3832_avg_0);
            p._avgi_current_price3832_avg_0 = avg_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category3873{};
        memcpy(_i_category3873.data(), (it.first).data(), (it.first).length());
        tbl_Aggregate_TD_6617436_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category3873);
        int64_t _avgi_current_price3832 = ((it.second)._avgi_current_price3832_avg_0 / nrow1 / 100.0);
        tbl_Aggregate_TD_6617436_output.setInt64(r, 0, _avgi_current_price3832);
        ++r;
    }
    tbl_Aggregate_TD_6617436_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_6617436_output #Row: " << tbl_Aggregate_TD_6617436_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6759273(Table &tbl_SerializeFromObject_TD_765730_input, Table &tbl_Filter_TD_6759273_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(i_current_price#233) AND isnotnull(i_item_sk#228)))
    // Input: ListBuffer(i_item_sk#228, i_current_price#233, i_category#240)
    // Output: ListBuffer(i_item_sk#228, i_current_price#233, i_category#240)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_765730_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _i_current_price233 = tbl_SerializeFromObject_TD_765730_input.getInt64(i, 1);
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_765730_input.getInt32(i, 0);
        if ((_i_current_price233!= 0) && (_i_item_sk228!= 0)) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_765730_input.getInt32(i, 0);
            tbl_Filter_TD_6759273_output.setInt32(r, 0, _i_item_sk228_t);
            int64_t _i_current_price233_t = tbl_SerializeFromObject_TD_765730_input.getInt64(i, 1);
            tbl_Filter_TD_6759273_output.setInt64(r, 1, _i_current_price233_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_t = tbl_SerializeFromObject_TD_765730_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_6759273_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_category240_t);
            r++;
        }
    }
    tbl_Filter_TD_6759273_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6759273_output #Row: " << tbl_Filter_TD_6759273_output.getNumRow() << std::endl;
}

typedef int32_t SW_Aggregate_TD_6589217_key;
struct SW_Aggregate_TD_6589217_payload {
};
void SW_Aggregate_TD_6589217(Table &tbl_Filter_TD_761648_output, Table &tbl_Aggregate_TD_6589217_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(d_month_seq#3836)
    // Input: ListBuffer(d_month_seq#3836)
    // Output: ListBuffer(d_month_seq#3836)
    std::unordered_map<SW_Aggregate_TD_6589217_key, SW_Aggregate_TD_6589217_payload> ht1;
    int nrow1 = tbl_Filter_TD_761648_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_month_seq3836 = tbl_Filter_TD_761648_output.getInt32(i, 0);
        SW_Aggregate_TD_6589217_key k = _d_month_seq3836;
        SW_Aggregate_TD_6589217_payload p{};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        tbl_Aggregate_TD_6589217_output.setInt32(r, 0, (it.first));
        ++r;
    }
    tbl_Aggregate_TD_6589217_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_6589217_output #Row: " << tbl_Aggregate_TD_6589217_output.getNumRow() << std::endl;
}

void SW_Filter_TD_639923(Table &tbl_SerializeFromObject_TD_771679_input, Table &tbl_Filter_TD_639923_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_customer_sk#1209) AND (isnotnull(ss_sold_date_sk#1206) AND isnotnull(ss_item_sk#1208))))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_771679_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_customer_sk1209 = tbl_SerializeFromObject_TD_771679_input.getInt32(i, 2);
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_771679_input.getInt32(i, 0);
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_771679_input.getInt32(i, 1);
        if ((_ss_customer_sk1209!= 0) && ((_ss_sold_date_sk1206!= 0) && (_ss_item_sk1208!= 0))) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_771679_input.getInt32(i, 0);
            tbl_Filter_TD_639923_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_771679_input.getInt32(i, 1);
            tbl_Filter_TD_639923_output.setInt32(r, 1, _ss_item_sk1208_t);
            int32_t _ss_customer_sk1209_t = tbl_SerializeFromObject_TD_771679_input.getInt32(i, 2);
            tbl_Filter_TD_639923_output.setInt32(r, 2, _ss_customer_sk1209_t);
            r++;
        }
    }
    tbl_Filter_TD_639923_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_639923_output #Row: " << tbl_Filter_TD_639923_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6919996_key_leftMajor {
    int32_t _ca_address_sk54;
    bool operator==(const SW_JOIN_INNER_TD_6919996_key_leftMajor& other) const {
        return ((_ca_address_sk54 == other._ca_address_sk54));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6919996_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6919996_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk54));
    }
};
}
struct SW_JOIN_INNER_TD_6919996_payload_leftMajor {
    int32_t _ca_address_sk54;
    std::string _ca_state62;
};
struct SW_JOIN_INNER_TD_6919996_key_rightMajor {
    int32_t _c_current_addr_sk4;
    bool operator==(const SW_JOIN_INNER_TD_6919996_key_rightMajor& other) const {
        return ((_c_current_addr_sk4 == other._c_current_addr_sk4));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6919996_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6919996_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_current_addr_sk4));
    }
};
}
struct SW_JOIN_INNER_TD_6919996_payload_rightMajor {
    int32_t _c_customer_sk0;
    int32_t _c_current_addr_sk4;
};
void SW_JOIN_INNER_TD_6919996(Table &tbl_Filter_TD_792899_output, Table &tbl_Filter_TD_7189205_output, Table &tbl_JOIN_INNER_TD_6919996_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ca_address_sk#54 = c_current_addr_sk#4))
    // Left Table: ListBuffer(ca_address_sk#54, ca_state#62)
    // Right Table: ListBuffer(c_customer_sk#0, c_current_addr_sk#4)
    // Output Table: ListBuffer(ca_state#62, c_customer_sk#0)
    int left_nrow = tbl_Filter_TD_792899_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7189205_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6919996_key_leftMajor, SW_JOIN_INNER_TD_6919996_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_792899_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_792899_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6919996_key_leftMajor keyA{_ca_address_sk54_k};
            int32_t _ca_address_sk54 = tbl_Filter_TD_792899_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_Filter_TD_792899_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _ca_state62 = std::string(_ca_state62_n.data());
            SW_JOIN_INNER_TD_6919996_payload_leftMajor payloadA{_ca_address_sk54, _ca_state62};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7189205_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_current_addr_sk4_k = tbl_Filter_TD_7189205_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6919996_key_leftMajor{_c_current_addr_sk4_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk54 = (it->second)._ca_address_sk54;
                std::string _ca_state62 = (it->second)._ca_state62;
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n{};
                memcpy(_ca_state62_n.data(), (_ca_state62).data(), (_ca_state62).length());
                int32_t _c_customer_sk0 = tbl_Filter_TD_7189205_output.getInt32(i, 0);
                int32_t _c_current_addr_sk4 = tbl_Filter_TD_7189205_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_6919996_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_state62_n);
                tbl_JOIN_INNER_TD_6919996_output.setInt32(r, 1, _c_customer_sk0);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6919996_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6919996_key_rightMajor, SW_JOIN_INNER_TD_6919996_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7189205_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_current_addr_sk4_k = tbl_Filter_TD_7189205_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_6919996_key_rightMajor keyA{_c_current_addr_sk4_k};
            int32_t _c_customer_sk0 = tbl_Filter_TD_7189205_output.getInt32(i, 0);
            int32_t _c_current_addr_sk4 = tbl_Filter_TD_7189205_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_6919996_payload_rightMajor payloadA{_c_customer_sk0, _c_current_addr_sk4};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_792899_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_792899_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6919996_key_rightMajor{_ca_address_sk54_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk0 = (it->second)._c_customer_sk0;
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                int32_t _ca_address_sk54 = tbl_Filter_TD_792899_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_Filter_TD_792899_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _ca_state62 = std::string(_ca_state62_n.data());
                tbl_JOIN_INNER_TD_6919996_output.setInt32(r, 1, _c_customer_sk0);
                tbl_JOIN_INNER_TD_6919996_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_state62_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6919996_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6919996_output #Row: " << tbl_JOIN_INNER_TD_6919996_output.getNumRow() << std::endl;
}

struct SW_JOIN_LEFTOUTER_TD_5823126_key {
    std::string _i_category3873;
    bool operator==(const SW_JOIN_LEFTOUTER_TD_5823126_key& other) const {
        return ((_i_category3873 == other._i_category3873));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_LEFTOUTER_TD_5823126_key> {
    std::size_t operator() (const SW_JOIN_LEFTOUTER_TD_5823126_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_category3873));
    }
};
}
struct SW_JOIN_LEFTOUTER_TD_5823126_payload {
    int64_t _avgi_current_price3832;
    std::string _i_category3873;
};
void SW_JOIN_LEFTOUTER_TD_5823126(Table &tbl_Filter_TD_6759273_output, Table &tbl_Aggregate_TD_6617436_output, Table &tbl_JOIN_LEFTOUTER_TD_5823126_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_LEFTOUTER
    // Operation: ListBuffer((i_category#3873 = i_category#240))
    // Left Table: ListBuffer(i_item_sk#228, i_current_price#233, i_category#240)
    // Right Table: ListBuffer(avg(i_current_price)#3832, i_category#3873)
    // Output Table: ListBuffer(i_item_sk#228, i_current_price#233, avg(i_current_price)#3832)
    std::unordered_multimap<SW_JOIN_LEFTOUTER_TD_5823126_key, SW_JOIN_LEFTOUTER_TD_5823126_payload> ht1;
    int nrow1 = tbl_Aggregate_TD_6617436_output.getNumRow();
    int nrow2 = tbl_Filter_TD_6759273_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category3873_k_n = tbl_Aggregate_TD_6617436_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::string _i_category3873_k = std::string(_i_category3873_k_n.data());
        SW_JOIN_LEFTOUTER_TD_5823126_key keyA{_i_category3873_k};
        int64_t _avgi_current_price3832 = tbl_Aggregate_TD_6617436_output.getInt64(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_category3873_n = tbl_Aggregate_TD_6617436_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::string _i_category3873 = std::string(_i_category3873_n.data());
        SW_JOIN_LEFTOUTER_TD_5823126_payload payloadA{_avgi_current_price3832, _i_category3873};
        ht1.insert(std::make_pair(keyA, payloadA));
    }
    int r = 0;
    for (int i = 0; i < nrow2; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category240_k_n = tbl_Filter_TD_6759273_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::string _i_category240_k = std::string(_i_category240_k_n.data());
        auto it = ht1.find(SW_JOIN_LEFTOUTER_TD_5823126_key{_i_category240_k});
        int32_t _i_item_sk228 = tbl_Filter_TD_6759273_output.getInt32(i, 0);
        int64_t _i_current_price233 = tbl_Filter_TD_6759273_output.getInt64(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _i_category240 = tbl_Filter_TD_6759273_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        if (it != ht1.end()) {
            auto its = ht1.equal_range(SW_JOIN_LEFTOUTER_TD_5823126_key{_i_category240_k});
            auto it_it = its.first;
            while (it_it != its.second) {
                int64_t _avgi_current_price3832 = (it_it->second)._avgi_current_price3832;
                std::string _i_category3873_n = (it_it->second)._i_category3873;
                std::array<char, TPCDS_READ_MAX + 1> _i_category3873{};
                memcpy(_i_category3873.data(), (_i_category3873_n).data(), (_i_category3873_n).length());
                tbl_JOIN_LEFTOUTER_TD_5823126_output.setInt64(r, 2, _avgi_current_price3832);
                tbl_JOIN_LEFTOUTER_TD_5823126_output.setInt32(r, 0, _i_item_sk228);
                tbl_JOIN_LEFTOUTER_TD_5823126_output.setInt64(r, 1, _i_current_price233);
                it_it++;
                r++;
            }
        } else {
            tbl_JOIN_LEFTOUTER_TD_5823126_output.setInt32(r, 0, _i_item_sk228);
            tbl_JOIN_LEFTOUTER_TD_5823126_output.setInt64(r, 1, _i_current_price233);
            r++;
        }
    }
    tbl_JOIN_LEFTOUTER_TD_5823126_output.setNumRow(r);
    std::cout << "tbl_JOIN_LEFTOUTER_TD_5823126_output #Row: " << tbl_JOIN_LEFTOUTER_TD_5823126_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5911680(Table &tbl_SerializeFromObject_TD_6747453_input, Table &tbl_Aggregate_TD_6589217_output, Table &tbl_Filter_TD_5911680_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_month_seq#123) AND (d_month_seq#123 = scalar-subquery#3828 [])) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_month_seq#123)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6747453_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_month_seq123 = tbl_SerializeFromObject_TD_6747453_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_6747453_input.getInt32(i, 0);
        if (((_d_month_seq123!= 0) && isElementExistsInTable(tbl_Aggregate_TD_6589217_output,_d_month_seq123)) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_6747453_input.getInt32(i, 0);
            tbl_Filter_TD_5911680_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_5911680_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5911680_output #Row: " << tbl_Filter_TD_5911680_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5146300_key_leftMajor {
    int32_t _c_customer_sk0;
    bool operator==(const SW_JOIN_INNER_TD_5146300_key_leftMajor& other) const {
        return ((_c_customer_sk0 == other._c_customer_sk0));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5146300_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5146300_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk0));
    }
};
}
struct SW_JOIN_INNER_TD_5146300_payload_leftMajor {
    std::string _ca_state62;
    int32_t _c_customer_sk0;
};
struct SW_JOIN_INNER_TD_5146300_key_rightMajor {
    int32_t _ss_customer_sk1209;
    bool operator==(const SW_JOIN_INNER_TD_5146300_key_rightMajor& other) const {
        return ((_ss_customer_sk1209 == other._ss_customer_sk1209));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5146300_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5146300_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_customer_sk1209));
    }
};
}
struct SW_JOIN_INNER_TD_5146300_payload_rightMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_item_sk1208;
    int32_t _ss_customer_sk1209;
};
void SW_JOIN_INNER_TD_5146300(Table &tbl_JOIN_INNER_TD_6919996_output, Table &tbl_Filter_TD_639923_output, Table &tbl_JOIN_INNER_TD_5146300_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((c_customer_sk#0 = ss_customer_sk#1209))
    // Left Table: ListBuffer(ca_state#62, c_customer_sk#0)
    // Right Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209)
    // Output Table: ListBuffer(ca_state#62, ss_sold_date_sk#1206, ss_item_sk#1208)
    int left_nrow = tbl_JOIN_INNER_TD_6919996_output.getNumRow();
    int right_nrow = tbl_Filter_TD_639923_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5146300_key_leftMajor, SW_JOIN_INNER_TD_5146300_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_6919996_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk0_k = tbl_JOIN_INNER_TD_6919996_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_5146300_key_leftMajor keyA{_c_customer_sk0_k};
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_JOIN_INNER_TD_6919996_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_state62 = std::string(_ca_state62_n.data());
            int32_t _c_customer_sk0 = tbl_JOIN_INNER_TD_6919996_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_5146300_payload_leftMajor payloadA{_ca_state62, _c_customer_sk0};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_639923_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_customer_sk1209_k = tbl_Filter_TD_639923_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5146300_key_leftMajor{_ss_customer_sk1209_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _ca_state62 = (it->second)._ca_state62;
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n{};
                memcpy(_ca_state62_n.data(), (_ca_state62).data(), (_ca_state62).length());
                int32_t _c_customer_sk0 = (it->second)._c_customer_sk0;
                int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_639923_output.getInt32(i, 0);
                int32_t _ss_item_sk1208 = tbl_Filter_TD_639923_output.getInt32(i, 1);
                int32_t _ss_customer_sk1209 = tbl_Filter_TD_639923_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_5146300_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_state62_n);
                tbl_JOIN_INNER_TD_5146300_output.setInt32(r, 1, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_5146300_output.setInt32(r, 2, _ss_item_sk1208);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5146300_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5146300_key_rightMajor, SW_JOIN_INNER_TD_5146300_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_639923_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_customer_sk1209_k = tbl_Filter_TD_639923_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_5146300_key_rightMajor keyA{_ss_customer_sk1209_k};
            int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_639923_output.getInt32(i, 0);
            int32_t _ss_item_sk1208 = tbl_Filter_TD_639923_output.getInt32(i, 1);
            int32_t _ss_customer_sk1209 = tbl_Filter_TD_639923_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_5146300_payload_rightMajor payloadA{_ss_sold_date_sk1206, _ss_item_sk1208, _ss_customer_sk1209};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_6919996_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk0_k = tbl_JOIN_INNER_TD_6919996_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5146300_key_rightMajor{_c_customer_sk0_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_JOIN_INNER_TD_6919996_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _ca_state62 = std::string(_ca_state62_n.data());
                int32_t _c_customer_sk0 = tbl_JOIN_INNER_TD_6919996_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_5146300_output.setInt32(r, 1, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_5146300_output.setInt32(r, 2, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_5146300_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_state62_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5146300_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5146300_output #Row: " << tbl_JOIN_INNER_TD_5146300_output.getNumRow() << std::endl;
}

void SW_Filter_TD_4334129(Table &tbl_JOIN_LEFTOUTER_TD_5823126_output, Table &tbl_Filter_TD_4334129_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((cast(i_current_price#233 as decimal(14,7)) > CheckOverflow((1.200000 * promote_precision(avg(i_current_price)#3832)), DecimalType(14,7), true)))
    // Input: ListBuffer(i_item_sk#228, i_current_price#233, avg(i_current_price)#3832)
    // Output: ListBuffer(i_item_sk#228)
    int r = 0;
    int nrow1 = tbl_JOIN_LEFTOUTER_TD_5823126_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _i_current_price233 = tbl_JOIN_LEFTOUTER_TD_5823126_output.getInt64(i, 1);
        int64_t _avgi_current_price3832 = tbl_JOIN_LEFTOUTER_TD_5823126_output.getInt64(i, 2);
        if (_i_current_price233 > (1.200000 * _avgi_current_price3832)) {
            int32_t _i_item_sk228_t = tbl_JOIN_LEFTOUTER_TD_5823126_output.getInt32(i, 0);
            tbl_Filter_TD_4334129_output.setInt32(r, 0, _i_item_sk228_t);
            r++;
        }
    }
    tbl_Filter_TD_4334129_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4334129_output #Row: " << tbl_Filter_TD_4334129_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_443036_key_leftMajor {
    int32_t _ss_sold_date_sk1206;
    bool operator==(const SW_JOIN_INNER_TD_443036_key_leftMajor& other) const {
        return ((_ss_sold_date_sk1206 == other._ss_sold_date_sk1206));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_443036_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_443036_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_sold_date_sk1206));
    }
};
}
struct SW_JOIN_INNER_TD_443036_payload_leftMajor {
    std::string _ca_state62;
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_item_sk1208;
};
struct SW_JOIN_INNER_TD_443036_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_443036_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_443036_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_443036_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_443036_payload_rightMajor {
    int32_t _d_date_sk120;
};
void SW_JOIN_INNER_TD_443036(Table &tbl_JOIN_INNER_TD_5146300_output, Table &tbl_Filter_TD_5911680_output, Table &tbl_JOIN_INNER_TD_443036_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#1206 = d_date_sk#120))
    // Left Table: ListBuffer(ca_state#62, ss_sold_date_sk#1206, ss_item_sk#1208)
    // Right Table: ListBuffer(d_date_sk#120)
    // Output Table: ListBuffer(ca_state#62, ss_item_sk#1208)
    int left_nrow = tbl_JOIN_INNER_TD_5146300_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5911680_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_443036_key_leftMajor, SW_JOIN_INNER_TD_443036_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_5146300_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_JOIN_INNER_TD_5146300_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_443036_key_leftMajor keyA{_ss_sold_date_sk1206_k};
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_JOIN_INNER_TD_5146300_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_state62 = std::string(_ca_state62_n.data());
            int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_5146300_output.getInt32(i, 1);
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_5146300_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_443036_payload_leftMajor payloadA{_ca_state62, _ss_sold_date_sk1206, _ss_item_sk1208};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5911680_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_5911680_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_443036_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _ca_state62 = (it->second)._ca_state62;
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n{};
                memcpy(_ca_state62_n.data(), (_ca_state62).data(), (_ca_state62).length());
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _d_date_sk120 = tbl_Filter_TD_5911680_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_443036_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_state62_n);
                tbl_JOIN_INNER_TD_443036_output.setInt32(r, 1, _ss_item_sk1208);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_443036_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_443036_key_rightMajor, SW_JOIN_INNER_TD_443036_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5911680_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_5911680_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_443036_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_5911680_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_443036_payload_rightMajor payloadA{_d_date_sk120};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_5146300_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_JOIN_INNER_TD_5146300_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_443036_key_rightMajor{_ss_sold_date_sk1206_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_JOIN_INNER_TD_5146300_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _ca_state62 = std::string(_ca_state62_n.data());
                int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_5146300_output.getInt32(i, 1);
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_5146300_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_443036_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_state62_n);
                tbl_JOIN_INNER_TD_443036_output.setInt32(r, 1, _ss_item_sk1208);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_443036_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_443036_output #Row: " << tbl_JOIN_INNER_TD_443036_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_3934585_key_leftMajor {
    int32_t _ss_item_sk1208;
    bool operator==(const SW_JOIN_INNER_TD_3934585_key_leftMajor& other) const {
        return ((_ss_item_sk1208 == other._ss_item_sk1208));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3934585_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3934585_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk1208));
    }
};
}
struct SW_JOIN_INNER_TD_3934585_payload_leftMajor {
    std::string _ca_state62;
    int32_t _ss_item_sk1208;
};
struct SW_JOIN_INNER_TD_3934585_key_rightMajor {
    int32_t _i_item_sk228;
    bool operator==(const SW_JOIN_INNER_TD_3934585_key_rightMajor& other) const {
        return ((_i_item_sk228 == other._i_item_sk228));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3934585_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3934585_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk228));
    }
};
}
struct SW_JOIN_INNER_TD_3934585_payload_rightMajor {
    int32_t _i_item_sk228;
};
void SW_JOIN_INNER_TD_3934585(Table &tbl_JOIN_INNER_TD_443036_output, Table &tbl_Filter_TD_4334129_output, Table &tbl_JOIN_INNER_TD_3934585_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_item_sk#1208 = i_item_sk#228))
    // Left Table: ListBuffer(ca_state#62, ss_item_sk#1208)
    // Right Table: ListBuffer(i_item_sk#228)
    // Output Table: ListBuffer(ca_state#62)
    int left_nrow = tbl_JOIN_INNER_TD_443036_output.getNumRow();
    int right_nrow = tbl_Filter_TD_4334129_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3934585_key_leftMajor, SW_JOIN_INNER_TD_3934585_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_443036_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_443036_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_3934585_key_leftMajor keyA{_ss_item_sk1208_k};
            std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_JOIN_INNER_TD_443036_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _ca_state62 = std::string(_ca_state62_n.data());
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_443036_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_3934585_payload_leftMajor payloadA{_ca_state62, _ss_item_sk1208};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_4334129_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_4334129_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3934585_key_leftMajor{_i_item_sk228_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _ca_state62 = (it->second)._ca_state62;
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n{};
                memcpy(_ca_state62_n.data(), (_ca_state62).data(), (_ca_state62).length());
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _i_item_sk228 = tbl_Filter_TD_4334129_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_3934585_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_state62_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3934585_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3934585_key_rightMajor, SW_JOIN_INNER_TD_3934585_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_4334129_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_4334129_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3934585_key_rightMajor keyA{_i_item_sk228_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_4334129_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3934585_payload_rightMajor payloadA{_i_item_sk228};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_443036_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_443036_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3934585_key_rightMajor{_ss_item_sk1208_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                std::array<char, TPCDS_READ_MAX + 1> _ca_state62_n = tbl_JOIN_INNER_TD_443036_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _ca_state62 = std::string(_ca_state62_n.data());
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_443036_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_3934585_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _ca_state62_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3934585_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_3934585_output #Row: " << tbl_JOIN_INNER_TD_3934585_output.getNumRow() << std::endl;
}

typedef std::string SW_Aggregate_TD_2916649_key;
struct SW_Aggregate_TD_2916649_payload {
    std::string _state3826;
    int64_t _cnt3827L_count_0;
};
void SW_Aggregate_TD_2916649(Table &tbl_JOIN_INNER_TD_3934585_output, Table &tbl_Aggregate_TD_2916649_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(ca_state#62, ca_state#62 AS state#3826, count(1) AS cnt#3827L)
    // Input: ListBuffer(ca_state#62)
    // Output: ListBuffer(state#3826, cnt#3827L)
    std::unordered_map<SW_Aggregate_TD_2916649_key, SW_Aggregate_TD_2916649_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_3934585_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _ca_state62 = tbl_JOIN_INNER_TD_3934585_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        SW_Aggregate_TD_2916649_key k = std::string(_ca_state62.data());
        std::array<char, TPCDS_READ_MAX + 1> _state3826 = _ca_state62;
        int64_t _cnt3827L_count_0 = 1 != 0 ? 1 : 0;
        SW_Aggregate_TD_2916649_payload p{std::string(_state3826.data()), _cnt3827L_count_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t count_0 = (it->second)._cnt3827L_count_0 + _cnt3827L_count_0;
            p._cnt3827L_count_0 = count_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _ca_state62 not required in the output table
        std::array<char, TPCDS_READ_MAX + 1> _state3826_n{};
        memcpy(_state3826_n.data(), (it.second)._state3826.data(), (it.second)._state3826.length());
        tbl_Aggregate_TD_2916649_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _state3826_n);
        int64_t _cnt3827L = (it.second)._cnt3827L_count_0;
        tbl_Aggregate_TD_2916649_output.setInt64(r, 1, _cnt3827L);
        ++r;
    }
    tbl_Aggregate_TD_2916649_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_2916649_output #Row: " << tbl_Aggregate_TD_2916649_output.getNumRow() << std::endl;
}

void SW_Filter_TD_1801776(Table &tbl_Aggregate_TD_2916649_output, Table &tbl_Filter_TD_1801776_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((cnt#3827L >= 10))
    // Input: ListBuffer(state#3826, cnt#3827L)
    // Output: ListBuffer(state#3826, cnt#3827L)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_2916649_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _cnt3827L = tbl_Aggregate_TD_2916649_output.getInt64(i, 1);
        if (_cnt3827L >= 10) {
            std::array<char, TPCDS_READ_MAX + 1> _state3826_t = tbl_Aggregate_TD_2916649_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            tbl_Filter_TD_1801776_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _state3826_t);
            int64_t _cnt3827L_t = tbl_Aggregate_TD_2916649_output.getInt64(i, 1);
            tbl_Filter_TD_1801776_output.setInt64(r, 1, _cnt3827L_t);
            r++;
        }
    }
    tbl_Filter_TD_1801776_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1801776_output #Row: " << tbl_Filter_TD_1801776_output.getNumRow() << std::endl;
}

void SW_Sort_TD_0329279(Table &tbl_Filter_TD_1801776_output, Table &tbl_Sort_TD_0329279_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(cnt#3827L ASC NULLS FIRST)
    // Input: ListBuffer(state#3826, cnt#3827L)
    // Output: ListBuffer(state#3826, cnt#3827L)
    struct SW_Sort_TD_0329279Row {
        std::string _state3826;
        int64_t _cnt3827L;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_0329279Row& a, const SW_Sort_TD_0329279Row& b) const { return 
 (a._cnt3827L < b._cnt3827L); 
}
    }SW_Sort_TD_0329279_order; 

    int nrow1 = tbl_Filter_TD_1801776_output.getNumRow();
    std::vector<SW_Sort_TD_0329279Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _state3826 = tbl_Filter_TD_1801776_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        int64_t _cnt3827L = tbl_Filter_TD_1801776_output.getInt64(i, 1);
        SW_Sort_TD_0329279Row t = {std::string(_state3826.data()),_cnt3827L};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_0329279_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _state3826{};
        memcpy(_state3826.data(), (it._state3826).data(), (it._state3826).length());
        tbl_Sort_TD_0329279_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _state3826);
        tbl_Sort_TD_0329279_output.setInt64(r, 1, it._cnt3827L);
        if (r < 10) {
            std::cout << (it._state3826).data() << " " << it._cnt3827L << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_0329279_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_0329279_output #Row: " << tbl_Sort_TD_0329279_output.getNumRow() << std::endl;
}

