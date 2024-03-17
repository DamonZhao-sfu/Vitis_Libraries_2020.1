#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_9779445(Table &tbl_SerializeFromObject_TD_10504956_input, Table &tbl_Filter_TD_9779445_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(s_store_sk#378))
    // Input: ListBuffer(s_store_sk#378)
    // Output: ListBuffer(s_store_sk#378)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10504956_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _s_store_sk378 = tbl_SerializeFromObject_TD_10504956_input.getInt32(i, 0);
        if (_s_store_sk378!= 0) {
            int32_t _s_store_sk378_t = tbl_SerializeFromObject_TD_10504956_input.getInt32(i, 0);
            tbl_Filter_TD_9779445_output.setInt32(r, 0, _s_store_sk378_t);
            r++;
        }
    }
    tbl_Filter_TD_9779445_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9779445_output #Row: " << tbl_Filter_TD_9779445_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9580451(Table &tbl_SerializeFromObject_TD_10851664_input, Table &tbl_Filter_TD_9580451_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(ss_store_sk#1213) AND isnotnull(ss_promo_sk#1214)) AND ((isnotnull(ss_sold_date_sk#1206) AND isnotnull(ss_customer_sk#1209)) AND isnotnull(ss_item_sk#1208))))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209, ss_store_sk#1213, ss_promo_sk#1214, ss_ext_sales_price#1221)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209, ss_store_sk#1213, ss_promo_sk#1214, ss_ext_sales_price#1221)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10851664_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_store_sk1213 = tbl_SerializeFromObject_TD_10851664_input.getInt32(i, 3);
        int32_t _ss_promo_sk1214 = tbl_SerializeFromObject_TD_10851664_input.getInt32(i, 4);
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_10851664_input.getInt32(i, 0);
        int32_t _ss_customer_sk1209 = tbl_SerializeFromObject_TD_10851664_input.getInt32(i, 2);
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_10851664_input.getInt32(i, 1);
        if (((_ss_store_sk1213!= 0) && (_ss_promo_sk1214!= 0)) && (((_ss_sold_date_sk1206!= 0) && (_ss_customer_sk1209!= 0)) && (_ss_item_sk1208!= 0))) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_10851664_input.getInt32(i, 0);
            tbl_Filter_TD_9580451_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_10851664_input.getInt32(i, 1);
            tbl_Filter_TD_9580451_output.setInt32(r, 1, _ss_item_sk1208_t);
            int32_t _ss_customer_sk1209_t = tbl_SerializeFromObject_TD_10851664_input.getInt32(i, 2);
            tbl_Filter_TD_9580451_output.setInt32(r, 2, _ss_customer_sk1209_t);
            int32_t _ss_store_sk1213_t = tbl_SerializeFromObject_TD_10851664_input.getInt32(i, 3);
            tbl_Filter_TD_9580451_output.setInt32(r, 3, _ss_store_sk1213_t);
            int32_t _ss_promo_sk1214_t = tbl_SerializeFromObject_TD_10851664_input.getInt32(i, 4);
            tbl_Filter_TD_9580451_output.setInt32(r, 4, _ss_promo_sk1214_t);
            int64_t _ss_ext_sales_price1221_t = tbl_SerializeFromObject_TD_10851664_input.getInt64(i, 5);
            tbl_Filter_TD_9580451_output.setInt64(r, 5, _ss_ext_sales_price1221_t);
            r++;
        }
    }
    tbl_Filter_TD_9580451_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9580451_output #Row: " << tbl_Filter_TD_9580451_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8202988(Table &tbl_SerializeFromObject_TD_9382655_input, Table &tbl_Filter_TD_8202988_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(s_store_sk#3745))
    // Input: ListBuffer(s_store_sk#3745)
    // Output: ListBuffer(s_store_sk#3745)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9382655_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _s_store_sk3745 = tbl_SerializeFromObject_TD_9382655_input.getInt32(i, 0);
        if (_s_store_sk3745!= 0) {
            int32_t _s_store_sk3745_t = tbl_SerializeFromObject_TD_9382655_input.getInt32(i, 0);
            tbl_Filter_TD_8202988_output.setInt32(r, 0, _s_store_sk3745_t);
            r++;
        }
    }
    tbl_Filter_TD_8202988_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8202988_output #Row: " << tbl_Filter_TD_8202988_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8713340(Table &tbl_SerializeFromObject_TD_9961376_input, Table &tbl_Filter_TD_8713340_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_store_sk#3729) AND ((isnotnull(ss_sold_date_sk#3722) AND isnotnull(ss_customer_sk#3725)) AND isnotnull(ss_item_sk#3724))))
    // Input: ListBuffer(ss_sold_date_sk#3722, ss_item_sk#3724, ss_customer_sk#3725, ss_store_sk#3729, ss_ext_sales_price#3737)
    // Output: ListBuffer(ss_sold_date_sk#3722, ss_item_sk#3724, ss_customer_sk#3725, ss_store_sk#3729, ss_ext_sales_price#3737)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9961376_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_store_sk3729 = tbl_SerializeFromObject_TD_9961376_input.getInt32(i, 3);
        int32_t _ss_sold_date_sk3722 = tbl_SerializeFromObject_TD_9961376_input.getInt32(i, 0);
        int32_t _ss_customer_sk3725 = tbl_SerializeFromObject_TD_9961376_input.getInt32(i, 2);
        int32_t _ss_item_sk3724 = tbl_SerializeFromObject_TD_9961376_input.getInt32(i, 1);
        if ((_ss_store_sk3729!= 0) && (((_ss_sold_date_sk3722!= 0) && (_ss_customer_sk3725!= 0)) && (_ss_item_sk3724!= 0))) {
            int32_t _ss_sold_date_sk3722_t = tbl_SerializeFromObject_TD_9961376_input.getInt32(i, 0);
            tbl_Filter_TD_8713340_output.setInt32(r, 0, _ss_sold_date_sk3722_t);
            int32_t _ss_item_sk3724_t = tbl_SerializeFromObject_TD_9961376_input.getInt32(i, 1);
            tbl_Filter_TD_8713340_output.setInt32(r, 1, _ss_item_sk3724_t);
            int32_t _ss_customer_sk3725_t = tbl_SerializeFromObject_TD_9961376_input.getInt32(i, 2);
            tbl_Filter_TD_8713340_output.setInt32(r, 2, _ss_customer_sk3725_t);
            int32_t _ss_store_sk3729_t = tbl_SerializeFromObject_TD_9961376_input.getInt32(i, 3);
            tbl_Filter_TD_8713340_output.setInt32(r, 3, _ss_store_sk3729_t);
            int64_t _ss_ext_sales_price3737_t = tbl_SerializeFromObject_TD_9961376_input.getInt64(i, 4);
            tbl_Filter_TD_8713340_output.setInt64(r, 4, _ss_ext_sales_price3737_t);
            r++;
        }
    }
    tbl_Filter_TD_8713340_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8713340_output #Row: " << tbl_Filter_TD_8713340_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8191688(Table &tbl_SerializeFromObject_TD_9939005_input, Table &tbl_Filter_TD_8191688_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((((p_channel_dmail#302 = Y) OR (p_channel_email#303 = Y)) OR (p_channel_tv#305 = Y)) AND isnotnull(p_promo_sk#294)))
    // Input: ListBuffer(p_promo_sk#294, p_channel_dmail#302, p_channel_email#303, p_channel_tv#305)
    // Output: ListBuffer(p_promo_sk#294)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9939005_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _p_channel_dmail302 = tbl_SerializeFromObject_TD_9939005_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _p_channel_email303 = tbl_SerializeFromObject_TD_9939005_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _p_channel_tv305 = tbl_SerializeFromObject_TD_9939005_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        int32_t _p_promo_sk294 = tbl_SerializeFromObject_TD_9939005_input.getInt32(i, 0);
        if ((((std::string(_p_channel_dmail302.data()) == "Y") || (std::string(_p_channel_email303.data()) == "Y")) || (std::string(_p_channel_tv305.data()) == "Y")) && (_p_promo_sk294!= 0)) {
            int32_t _p_promo_sk294_t = tbl_SerializeFromObject_TD_9939005_input.getInt32(i, 0);
            tbl_Filter_TD_8191688_output.setInt32(r, 0, _p_promo_sk294_t);
            r++;
        }
    }
    tbl_Filter_TD_8191688_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8191688_output #Row: " << tbl_Filter_TD_8191688_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_8567840_key_leftMajor {
    int32_t _ss_store_sk1213;
    bool operator==(const SW_JOIN_INNER_TD_8567840_key_leftMajor& other) const {
        return ((_ss_store_sk1213 == other._ss_store_sk1213));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8567840_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8567840_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_store_sk1213));
    }
};
}
struct SW_JOIN_INNER_TD_8567840_payload_leftMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_item_sk1208;
    int32_t _ss_customer_sk1209;
    int32_t _ss_store_sk1213;
    int32_t _ss_promo_sk1214;
    int64_t _ss_ext_sales_price1221;
};
struct SW_JOIN_INNER_TD_8567840_key_rightMajor {
    int32_t _s_store_sk378;
    bool operator==(const SW_JOIN_INNER_TD_8567840_key_rightMajor& other) const {
        return ((_s_store_sk378 == other._s_store_sk378));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_8567840_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_8567840_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_store_sk378));
    }
};
}
struct SW_JOIN_INNER_TD_8567840_payload_rightMajor {
    int32_t _s_store_sk378;
};
void SW_JOIN_INNER_TD_8567840(Table &tbl_Filter_TD_9580451_output, Table &tbl_Filter_TD_9779445_output, Table &tbl_JOIN_INNER_TD_8567840_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_store_sk#1213 = s_store_sk#378))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209, ss_store_sk#1213, ss_promo_sk#1214, ss_ext_sales_price#1221)
    // Right Table: ListBuffer(s_store_sk#378)
    // Output Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209, ss_promo_sk#1214, ss_ext_sales_price#1221)
    int left_nrow = tbl_Filter_TD_9580451_output.getNumRow();
    int right_nrow = tbl_Filter_TD_9779445_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8567840_key_leftMajor, SW_JOIN_INNER_TD_8567840_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_9580451_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_store_sk1213_k = tbl_Filter_TD_9580451_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_8567840_key_leftMajor keyA{_ss_store_sk1213_k};
            int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_9580451_output.getInt32(i, 0);
            int32_t _ss_item_sk1208 = tbl_Filter_TD_9580451_output.getInt32(i, 1);
            int32_t _ss_customer_sk1209 = tbl_Filter_TD_9580451_output.getInt32(i, 2);
            int32_t _ss_store_sk1213 = tbl_Filter_TD_9580451_output.getInt32(i, 3);
            int32_t _ss_promo_sk1214 = tbl_Filter_TD_9580451_output.getInt32(i, 4);
            int64_t _ss_ext_sales_price1221 = tbl_Filter_TD_9580451_output.getInt64(i, 5);
            SW_JOIN_INNER_TD_8567840_payload_leftMajor payloadA{_ss_sold_date_sk1206, _ss_item_sk1208, _ss_customer_sk1209, _ss_store_sk1213, _ss_promo_sk1214, _ss_ext_sales_price1221};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9779445_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_9779445_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8567840_key_leftMajor{_s_store_sk378_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                int32_t _ss_store_sk1213 = (it->second)._ss_store_sk1213;
                int32_t _ss_promo_sk1214 = (it->second)._ss_promo_sk1214;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int32_t _s_store_sk378 = tbl_Filter_TD_9779445_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_8567840_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_8567840_output.setInt32(r, 1, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_8567840_output.setInt32(r, 2, _ss_customer_sk1209);
                tbl_JOIN_INNER_TD_8567840_output.setInt32(r, 3, _ss_promo_sk1214);
                tbl_JOIN_INNER_TD_8567840_output.setInt64(r, 4, _ss_ext_sales_price1221);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8567840_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_8567840_key_rightMajor, SW_JOIN_INNER_TD_8567840_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_9779445_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_store_sk378_k = tbl_Filter_TD_9779445_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8567840_key_rightMajor keyA{_s_store_sk378_k};
            int32_t _s_store_sk378 = tbl_Filter_TD_9779445_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_8567840_payload_rightMajor payloadA{_s_store_sk378};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_9580451_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_store_sk1213_k = tbl_Filter_TD_9580451_output.getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_8567840_key_rightMajor{_ss_store_sk1213_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _s_store_sk378 = (it->second)._s_store_sk378;
                int32_t _ss_sold_date_sk1206 = tbl_Filter_TD_9580451_output.getInt32(i, 0);
                int32_t _ss_item_sk1208 = tbl_Filter_TD_9580451_output.getInt32(i, 1);
                int32_t _ss_customer_sk1209 = tbl_Filter_TD_9580451_output.getInt32(i, 2);
                int32_t _ss_store_sk1213 = tbl_Filter_TD_9580451_output.getInt32(i, 3);
                int32_t _ss_promo_sk1214 = tbl_Filter_TD_9580451_output.getInt32(i, 4);
                int64_t _ss_ext_sales_price1221 = tbl_Filter_TD_9580451_output.getInt64(i, 5);
                tbl_JOIN_INNER_TD_8567840_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_8567840_output.setInt32(r, 1, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_8567840_output.setInt32(r, 2, _ss_customer_sk1209);
                tbl_JOIN_INNER_TD_8567840_output.setInt32(r, 3, _ss_promo_sk1214);
                tbl_JOIN_INNER_TD_8567840_output.setInt64(r, 4, _ss_ext_sales_price1221);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_8567840_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_8567840_output #Row: " << tbl_JOIN_INNER_TD_8567840_output.getNumRow() << std::endl;
}

void SW_Filter_TD_77755(Table &tbl_SerializeFromObject_TD_8285486_input, Table &tbl_Filter_TD_77755_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_year#3780) AND isnotnull(d_moy#3782)) AND ((d_year#3780 = 1998) AND (d_moy#3782 = 11))) AND isnotnull(d_date_sk#3774)))
    // Input: ListBuffer(d_date_sk#3774, d_year#3780, d_moy#3782)
    // Output: ListBuffer(d_date_sk#3774)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8285486_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3780 = tbl_SerializeFromObject_TD_8285486_input.getInt32(i, 1);
        int32_t _d_moy3782 = tbl_SerializeFromObject_TD_8285486_input.getInt32(i, 2);
        int32_t _d_date_sk3774 = tbl_SerializeFromObject_TD_8285486_input.getInt32(i, 0);
        if ((((_d_year3780!= 0) && (_d_moy3782!= 0)) && ((_d_year3780 == 1998) && (_d_moy3782 == 11))) && (_d_date_sk3774!= 0)) {
            int32_t _d_date_sk3774_t = tbl_SerializeFromObject_TD_8285486_input.getInt32(i, 0);
            tbl_Filter_TD_77755_output.setInt32(r, 0, _d_date_sk3774_t);
            r++;
        }
    }
    tbl_Filter_TD_77755_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_77755_output #Row: " << tbl_Filter_TD_77755_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_721842_key_leftMajor {
    int32_t _ss_store_sk3729;
    bool operator==(const SW_JOIN_INNER_TD_721842_key_leftMajor& other) const {
        return ((_ss_store_sk3729 == other._ss_store_sk3729));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_721842_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_721842_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_store_sk3729));
    }
};
}
struct SW_JOIN_INNER_TD_721842_payload_leftMajor {
    int32_t _ss_sold_date_sk3722;
    int32_t _ss_item_sk3724;
    int32_t _ss_customer_sk3725;
    int32_t _ss_store_sk3729;
    int64_t _ss_ext_sales_price3737;
};
struct SW_JOIN_INNER_TD_721842_key_rightMajor {
    int32_t _s_store_sk3745;
    bool operator==(const SW_JOIN_INNER_TD_721842_key_rightMajor& other) const {
        return ((_s_store_sk3745 == other._s_store_sk3745));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_721842_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_721842_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_store_sk3745));
    }
};
}
struct SW_JOIN_INNER_TD_721842_payload_rightMajor {
    int32_t _s_store_sk3745;
};
void SW_JOIN_INNER_TD_721842(Table &tbl_Filter_TD_8713340_output, Table &tbl_Filter_TD_8202988_output, Table &tbl_JOIN_INNER_TD_721842_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_store_sk#3729 = s_store_sk#3745))
    // Left Table: ListBuffer(ss_sold_date_sk#3722, ss_item_sk#3724, ss_customer_sk#3725, ss_store_sk#3729, ss_ext_sales_price#3737)
    // Right Table: ListBuffer(s_store_sk#3745)
    // Output Table: ListBuffer(ss_sold_date_sk#3722, ss_item_sk#3724, ss_customer_sk#3725, ss_ext_sales_price#3737)
    int left_nrow = tbl_Filter_TD_8713340_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8202988_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_721842_key_leftMajor, SW_JOIN_INNER_TD_721842_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_8713340_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_store_sk3729_k = tbl_Filter_TD_8713340_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_721842_key_leftMajor keyA{_ss_store_sk3729_k};
            int32_t _ss_sold_date_sk3722 = tbl_Filter_TD_8713340_output.getInt32(i, 0);
            int32_t _ss_item_sk3724 = tbl_Filter_TD_8713340_output.getInt32(i, 1);
            int32_t _ss_customer_sk3725 = tbl_Filter_TD_8713340_output.getInt32(i, 2);
            int32_t _ss_store_sk3729 = tbl_Filter_TD_8713340_output.getInt32(i, 3);
            int64_t _ss_ext_sales_price3737 = tbl_Filter_TD_8713340_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_721842_payload_leftMajor payloadA{_ss_sold_date_sk3722, _ss_item_sk3724, _ss_customer_sk3725, _ss_store_sk3729, _ss_ext_sales_price3737};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8202988_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_store_sk3745_k = tbl_Filter_TD_8202988_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_721842_key_leftMajor{_s_store_sk3745_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk3722 = (it->second)._ss_sold_date_sk3722;
                int32_t _ss_item_sk3724 = (it->second)._ss_item_sk3724;
                int32_t _ss_customer_sk3725 = (it->second)._ss_customer_sk3725;
                int32_t _ss_store_sk3729 = (it->second)._ss_store_sk3729;
                int64_t _ss_ext_sales_price3737 = (it->second)._ss_ext_sales_price3737;
                int32_t _s_store_sk3745 = tbl_Filter_TD_8202988_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_721842_output.setInt32(r, 0, _ss_sold_date_sk3722);
                tbl_JOIN_INNER_TD_721842_output.setInt32(r, 1, _ss_item_sk3724);
                tbl_JOIN_INNER_TD_721842_output.setInt32(r, 2, _ss_customer_sk3725);
                tbl_JOIN_INNER_TD_721842_output.setInt64(r, 3, _ss_ext_sales_price3737);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_721842_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_721842_key_rightMajor, SW_JOIN_INNER_TD_721842_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8202988_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_store_sk3745_k = tbl_Filter_TD_8202988_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_721842_key_rightMajor keyA{_s_store_sk3745_k};
            int32_t _s_store_sk3745 = tbl_Filter_TD_8202988_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_721842_payload_rightMajor payloadA{_s_store_sk3745};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8713340_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_store_sk3729_k = tbl_Filter_TD_8713340_output.getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_721842_key_rightMajor{_ss_store_sk3729_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _s_store_sk3745 = (it->second)._s_store_sk3745;
                int32_t _ss_sold_date_sk3722 = tbl_Filter_TD_8713340_output.getInt32(i, 0);
                int32_t _ss_item_sk3724 = tbl_Filter_TD_8713340_output.getInt32(i, 1);
                int32_t _ss_customer_sk3725 = tbl_Filter_TD_8713340_output.getInt32(i, 2);
                int32_t _ss_store_sk3729 = tbl_Filter_TD_8713340_output.getInt32(i, 3);
                int64_t _ss_ext_sales_price3737 = tbl_Filter_TD_8713340_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_721842_output.setInt32(r, 0, _ss_sold_date_sk3722);
                tbl_JOIN_INNER_TD_721842_output.setInt32(r, 1, _ss_item_sk3724);
                tbl_JOIN_INNER_TD_721842_output.setInt32(r, 2, _ss_customer_sk3725);
                tbl_JOIN_INNER_TD_721842_output.setInt64(r, 3, _ss_ext_sales_price3737);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_721842_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_721842_output #Row: " << tbl_JOIN_INNER_TD_721842_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7892130(Table &tbl_SerializeFromObject_TD_8833837_input, Table &tbl_Filter_TD_7892130_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((isnotnull(d_year#126) AND isnotnull(d_moy#128)) AND ((d_year#126 = 1998) AND (d_moy#128 = 11))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_year#126, d_moy#128)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8833837_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year126 = tbl_SerializeFromObject_TD_8833837_input.getInt32(i, 1);
        int32_t _d_moy128 = tbl_SerializeFromObject_TD_8833837_input.getInt32(i, 2);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_8833837_input.getInt32(i, 0);
        if ((((_d_year126!= 0) && (_d_moy128!= 0)) && ((_d_year126 == 1998) && (_d_moy128 == 11))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_8833837_input.getInt32(i, 0);
            tbl_Filter_TD_7892130_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_7892130_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7892130_output #Row: " << tbl_Filter_TD_7892130_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_7792795_key_leftMajor {
    int32_t _ss_promo_sk1214;
    bool operator==(const SW_JOIN_INNER_TD_7792795_key_leftMajor& other) const {
        return ((_ss_promo_sk1214 == other._ss_promo_sk1214));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7792795_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7792795_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_promo_sk1214));
    }
};
}
struct SW_JOIN_INNER_TD_7792795_payload_leftMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_item_sk1208;
    int32_t _ss_customer_sk1209;
    int32_t _ss_promo_sk1214;
    int64_t _ss_ext_sales_price1221;
};
struct SW_JOIN_INNER_TD_7792795_key_rightMajor {
    int32_t _p_promo_sk294;
    bool operator==(const SW_JOIN_INNER_TD_7792795_key_rightMajor& other) const {
        return ((_p_promo_sk294 == other._p_promo_sk294));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_7792795_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_7792795_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._p_promo_sk294));
    }
};
}
struct SW_JOIN_INNER_TD_7792795_payload_rightMajor {
    int32_t _p_promo_sk294;
};
void SW_JOIN_INNER_TD_7792795(Table &tbl_JOIN_INNER_TD_8567840_output, Table &tbl_Filter_TD_8191688_output, Table &tbl_JOIN_INNER_TD_7792795_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_promo_sk#1214 = p_promo_sk#294))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209, ss_promo_sk#1214, ss_ext_sales_price#1221)
    // Right Table: ListBuffer(p_promo_sk#294)
    // Output Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209, ss_ext_sales_price#1221)
    int left_nrow = tbl_JOIN_INNER_TD_8567840_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8191688_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7792795_key_leftMajor, SW_JOIN_INNER_TD_7792795_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_8567840_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_promo_sk1214_k = tbl_JOIN_INNER_TD_8567840_output.getInt32(i, 3);
            SW_JOIN_INNER_TD_7792795_key_leftMajor keyA{_ss_promo_sk1214_k};
            int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_8567840_output.getInt32(i, 0);
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_8567840_output.getInt32(i, 1);
            int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_8567840_output.getInt32(i, 2);
            int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_8567840_output.getInt32(i, 3);
            int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_8567840_output.getInt64(i, 4);
            SW_JOIN_INNER_TD_7792795_payload_leftMajor payloadA{_ss_sold_date_sk1206, _ss_item_sk1208, _ss_customer_sk1209, _ss_promo_sk1214, _ss_ext_sales_price1221};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8191688_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _p_promo_sk294_k = tbl_Filter_TD_8191688_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7792795_key_leftMajor{_p_promo_sk294_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                int32_t _ss_promo_sk1214 = (it->second)._ss_promo_sk1214;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int32_t _p_promo_sk294 = tbl_Filter_TD_8191688_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_7792795_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_7792795_output.setInt32(r, 1, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_7792795_output.setInt32(r, 2, _ss_customer_sk1209);
                tbl_JOIN_INNER_TD_7792795_output.setInt64(r, 3, _ss_ext_sales_price1221);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7792795_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_7792795_key_rightMajor, SW_JOIN_INNER_TD_7792795_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8191688_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _p_promo_sk294_k = tbl_Filter_TD_8191688_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7792795_key_rightMajor keyA{_p_promo_sk294_k};
            int32_t _p_promo_sk294 = tbl_Filter_TD_8191688_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_7792795_payload_rightMajor payloadA{_p_promo_sk294};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_8567840_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_promo_sk1214_k = tbl_JOIN_INNER_TD_8567840_output.getInt32(i, 3);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_7792795_key_rightMajor{_ss_promo_sk1214_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _p_promo_sk294 = (it->second)._p_promo_sk294;
                int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_8567840_output.getInt32(i, 0);
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_8567840_output.getInt32(i, 1);
                int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_8567840_output.getInt32(i, 2);
                int32_t _ss_promo_sk1214 = tbl_JOIN_INNER_TD_8567840_output.getInt32(i, 3);
                int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_8567840_output.getInt64(i, 4);
                tbl_JOIN_INNER_TD_7792795_output.setInt32(r, 0, _ss_sold_date_sk1206);
                tbl_JOIN_INNER_TD_7792795_output.setInt32(r, 1, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_7792795_output.setInt32(r, 2, _ss_customer_sk1209);
                tbl_JOIN_INNER_TD_7792795_output.setInt64(r, 3, _ss_ext_sales_price1221);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_7792795_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_7792795_output #Row: " << tbl_JOIN_INNER_TD_7792795_output.getNumRow() << std::endl;
}

void SW_Filter_TD_656333(Table &tbl_SerializeFromObject_TD_7846787_input, Table &tbl_Filter_TD_656333_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(c_customer_sk#3802) AND isnotnull(c_current_addr_sk#3806)))
    // Input: ListBuffer(c_customer_sk#3802, c_current_addr_sk#3806)
    // Output: ListBuffer(c_customer_sk#3802, c_current_addr_sk#3806)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7846787_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk3802 = tbl_SerializeFromObject_TD_7846787_input.getInt32(i, 0);
        int32_t _c_current_addr_sk3806 = tbl_SerializeFromObject_TD_7846787_input.getInt32(i, 1);
        if ((_c_customer_sk3802!= 0) && (_c_current_addr_sk3806!= 0)) {
            int32_t _c_customer_sk3802_t = tbl_SerializeFromObject_TD_7846787_input.getInt32(i, 0);
            tbl_Filter_TD_656333_output.setInt32(r, 0, _c_customer_sk3802_t);
            int32_t _c_current_addr_sk3806_t = tbl_SerializeFromObject_TD_7846787_input.getInt32(i, 1);
            tbl_Filter_TD_656333_output.setInt32(r, 1, _c_current_addr_sk3806_t);
            r++;
        }
    }
    tbl_Filter_TD_656333_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_656333_output #Row: " << tbl_Filter_TD_656333_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6149111_key_leftMajor {
    int32_t _ss_sold_date_sk3722;
    bool operator==(const SW_JOIN_INNER_TD_6149111_key_leftMajor& other) const {
        return ((_ss_sold_date_sk3722 == other._ss_sold_date_sk3722));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6149111_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6149111_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_sold_date_sk3722));
    }
};
}
struct SW_JOIN_INNER_TD_6149111_payload_leftMajor {
    int32_t _ss_sold_date_sk3722;
    int32_t _ss_item_sk3724;
    int32_t _ss_customer_sk3725;
    int64_t _ss_ext_sales_price3737;
};
struct SW_JOIN_INNER_TD_6149111_key_rightMajor {
    int32_t _d_date_sk3774;
    bool operator==(const SW_JOIN_INNER_TD_6149111_key_rightMajor& other) const {
        return ((_d_date_sk3774 == other._d_date_sk3774));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6149111_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6149111_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk3774));
    }
};
}
struct SW_JOIN_INNER_TD_6149111_payload_rightMajor {
    int32_t _d_date_sk3774;
};
void SW_JOIN_INNER_TD_6149111(Table &tbl_JOIN_INNER_TD_721842_output, Table &tbl_Filter_TD_77755_output, Table &tbl_JOIN_INNER_TD_6149111_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#3722 = d_date_sk#3774))
    // Left Table: ListBuffer(ss_sold_date_sk#3722, ss_item_sk#3724, ss_customer_sk#3725, ss_ext_sales_price#3737)
    // Right Table: ListBuffer(d_date_sk#3774)
    // Output Table: ListBuffer(ss_item_sk#3724, ss_customer_sk#3725, ss_ext_sales_price#3737)
    int left_nrow = tbl_JOIN_INNER_TD_721842_output.getNumRow();
    int right_nrow = tbl_Filter_TD_77755_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6149111_key_leftMajor, SW_JOIN_INNER_TD_6149111_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_721842_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_sold_date_sk3722_k = tbl_JOIN_INNER_TD_721842_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6149111_key_leftMajor keyA{_ss_sold_date_sk3722_k};
            int32_t _ss_sold_date_sk3722 = tbl_JOIN_INNER_TD_721842_output.getInt32(i, 0);
            int32_t _ss_item_sk3724 = tbl_JOIN_INNER_TD_721842_output.getInt32(i, 1);
            int32_t _ss_customer_sk3725 = tbl_JOIN_INNER_TD_721842_output.getInt32(i, 2);
            int64_t _ss_ext_sales_price3737 = tbl_JOIN_INNER_TD_721842_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_6149111_payload_leftMajor payloadA{_ss_sold_date_sk3722, _ss_item_sk3724, _ss_customer_sk3725, _ss_ext_sales_price3737};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_77755_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk3774_k = tbl_Filter_TD_77755_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6149111_key_leftMajor{_d_date_sk3774_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk3722 = (it->second)._ss_sold_date_sk3722;
                int32_t _ss_item_sk3724 = (it->second)._ss_item_sk3724;
                int32_t _ss_customer_sk3725 = (it->second)._ss_customer_sk3725;
                int64_t _ss_ext_sales_price3737 = (it->second)._ss_ext_sales_price3737;
                int32_t _d_date_sk3774 = tbl_Filter_TD_77755_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_6149111_output.setInt32(r, 0, _ss_item_sk3724);
                tbl_JOIN_INNER_TD_6149111_output.setInt32(r, 1, _ss_customer_sk3725);
                tbl_JOIN_INNER_TD_6149111_output.setInt64(r, 2, _ss_ext_sales_price3737);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6149111_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6149111_key_rightMajor, SW_JOIN_INNER_TD_6149111_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_77755_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk3774_k = tbl_Filter_TD_77755_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6149111_key_rightMajor keyA{_d_date_sk3774_k};
            int32_t _d_date_sk3774 = tbl_Filter_TD_77755_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6149111_payload_rightMajor payloadA{_d_date_sk3774};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_721842_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_sold_date_sk3722_k = tbl_JOIN_INNER_TD_721842_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6149111_key_rightMajor{_ss_sold_date_sk3722_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk3774 = (it->second)._d_date_sk3774;
                int32_t _ss_sold_date_sk3722 = tbl_JOIN_INNER_TD_721842_output.getInt32(i, 0);
                int32_t _ss_item_sk3724 = tbl_JOIN_INNER_TD_721842_output.getInt32(i, 1);
                int32_t _ss_customer_sk3725 = tbl_JOIN_INNER_TD_721842_output.getInt32(i, 2);
                int64_t _ss_ext_sales_price3737 = tbl_JOIN_INNER_TD_721842_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_6149111_output.setInt32(r, 0, _ss_item_sk3724);
                tbl_JOIN_INNER_TD_6149111_output.setInt32(r, 1, _ss_customer_sk3725);
                tbl_JOIN_INNER_TD_6149111_output.setInt64(r, 2, _ss_ext_sales_price3737);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6149111_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6149111_output #Row: " << tbl_JOIN_INNER_TD_6149111_output.getNumRow() << std::endl;
}

void SW_Filter_TD_6785245(Table &tbl_SerializeFromObject_TD_7302846_input, Table &tbl_Filter_TD_6785245_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(c_customer_sk#0) AND isnotnull(c_current_addr_sk#4)))
    // Input: ListBuffer(c_customer_sk#0, c_current_addr_sk#4)
    // Output: ListBuffer(c_customer_sk#0, c_current_addr_sk#4)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7302846_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_customer_sk0 = tbl_SerializeFromObject_TD_7302846_input.getInt32(i, 0);
        int32_t _c_current_addr_sk4 = tbl_SerializeFromObject_TD_7302846_input.getInt32(i, 1);
        if ((_c_customer_sk0!= 0) && (_c_current_addr_sk4!= 0)) {
            int32_t _c_customer_sk0_t = tbl_SerializeFromObject_TD_7302846_input.getInt32(i, 0);
            tbl_Filter_TD_6785245_output.setInt32(r, 0, _c_customer_sk0_t);
            int32_t _c_current_addr_sk4_t = tbl_SerializeFromObject_TD_7302846_input.getInt32(i, 1);
            tbl_Filter_TD_6785245_output.setInt32(r, 1, _c_current_addr_sk4_t);
            r++;
        }
    }
    tbl_Filter_TD_6785245_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6785245_output #Row: " << tbl_Filter_TD_6785245_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6370860_key_leftMajor {
    int32_t _ss_sold_date_sk1206;
    bool operator==(const SW_JOIN_INNER_TD_6370860_key_leftMajor& other) const {
        return ((_ss_sold_date_sk1206 == other._ss_sold_date_sk1206));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6370860_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6370860_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_sold_date_sk1206));
    }
};
}
struct SW_JOIN_INNER_TD_6370860_payload_leftMajor {
    int32_t _ss_sold_date_sk1206;
    int32_t _ss_item_sk1208;
    int32_t _ss_customer_sk1209;
    int64_t _ss_ext_sales_price1221;
};
struct SW_JOIN_INNER_TD_6370860_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_6370860_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6370860_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6370860_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_6370860_payload_rightMajor {
    int32_t _d_date_sk120;
};
void SW_JOIN_INNER_TD_6370860(Table &tbl_JOIN_INNER_TD_7792795_output, Table &tbl_Filter_TD_7892130_output, Table &tbl_JOIN_INNER_TD_6370860_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_sold_date_sk#1206 = d_date_sk#120))
    // Left Table: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_customer_sk#1209, ss_ext_sales_price#1221)
    // Right Table: ListBuffer(d_date_sk#120)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_customer_sk#1209, ss_ext_sales_price#1221)
    int left_nrow = tbl_JOIN_INNER_TD_7792795_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7892130_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6370860_key_leftMajor, SW_JOIN_INNER_TD_6370860_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7792795_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_JOIN_INNER_TD_7792795_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6370860_key_leftMajor keyA{_ss_sold_date_sk1206_k};
            int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_7792795_output.getInt32(i, 0);
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_7792795_output.getInt32(i, 1);
            int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_7792795_output.getInt32(i, 2);
            int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_7792795_output.getInt64(i, 3);
            SW_JOIN_INNER_TD_6370860_payload_leftMajor payloadA{_ss_sold_date_sk1206, _ss_item_sk1208, _ss_customer_sk1209, _ss_ext_sales_price1221};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7892130_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_7892130_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6370860_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_sold_date_sk1206 = (it->second)._ss_sold_date_sk1206;
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int32_t _d_date_sk120 = tbl_Filter_TD_7892130_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_6370860_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_6370860_output.setInt32(r, 1, _ss_customer_sk1209);
                tbl_JOIN_INNER_TD_6370860_output.setInt64(r, 2, _ss_ext_sales_price1221);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6370860_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6370860_key_rightMajor, SW_JOIN_INNER_TD_6370860_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7892130_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_7892130_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6370860_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_7892130_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6370860_payload_rightMajor payloadA{_d_date_sk120};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7792795_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_sold_date_sk1206_k = tbl_JOIN_INNER_TD_7792795_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6370860_key_rightMajor{_ss_sold_date_sk1206_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _ss_sold_date_sk1206 = tbl_JOIN_INNER_TD_7792795_output.getInt32(i, 0);
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_7792795_output.getInt32(i, 1);
                int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_7792795_output.getInt32(i, 2);
                int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_7792795_output.getInt64(i, 3);
                tbl_JOIN_INNER_TD_6370860_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_6370860_output.setInt32(r, 1, _ss_customer_sk1209);
                tbl_JOIN_INNER_TD_6370860_output.setInt64(r, 2, _ss_ext_sales_price1221);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6370860_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6370860_output #Row: " << tbl_JOIN_INNER_TD_6370860_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5282555(Table &tbl_SerializeFromObject_TD_6566856_input, Table &tbl_Filter_TD_5282555_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ca_address_sk#3820))
    // Input: ListBuffer(ca_address_sk#3820)
    // Output: ListBuffer(ca_address_sk#3820)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6566856_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ca_address_sk3820 = tbl_SerializeFromObject_TD_6566856_input.getInt32(i, 0);
        if (_ca_address_sk3820!= 0) {
            int32_t _ca_address_sk3820_t = tbl_SerializeFromObject_TD_6566856_input.getInt32(i, 0);
            tbl_Filter_TD_5282555_output.setInt32(r, 0, _ca_address_sk3820_t);
            r++;
        }
    }
    tbl_Filter_TD_5282555_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5282555_output #Row: " << tbl_Filter_TD_5282555_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5966274_key_leftMajor {
    int32_t _ss_customer_sk3725;
    bool operator==(const SW_JOIN_INNER_TD_5966274_key_leftMajor& other) const {
        return ((_ss_customer_sk3725 == other._ss_customer_sk3725));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5966274_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5966274_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_customer_sk3725));
    }
};
}
struct SW_JOIN_INNER_TD_5966274_payload_leftMajor {
    int32_t _ss_item_sk3724;
    int32_t _ss_customer_sk3725;
    int64_t _ss_ext_sales_price3737;
};
struct SW_JOIN_INNER_TD_5966274_key_rightMajor {
    int32_t _c_customer_sk3802;
    bool operator==(const SW_JOIN_INNER_TD_5966274_key_rightMajor& other) const {
        return ((_c_customer_sk3802 == other._c_customer_sk3802));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5966274_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5966274_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk3802));
    }
};
}
struct SW_JOIN_INNER_TD_5966274_payload_rightMajor {
    int32_t _c_customer_sk3802;
    int32_t _c_current_addr_sk3806;
};
void SW_JOIN_INNER_TD_5966274(Table &tbl_JOIN_INNER_TD_6149111_output, Table &tbl_Filter_TD_656333_output, Table &tbl_JOIN_INNER_TD_5966274_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_customer_sk#3725 = c_customer_sk#3802))
    // Left Table: ListBuffer(ss_item_sk#3724, ss_customer_sk#3725, ss_ext_sales_price#3737)
    // Right Table: ListBuffer(c_customer_sk#3802, c_current_addr_sk#3806)
    // Output Table: ListBuffer(ss_item_sk#3724, ss_ext_sales_price#3737, c_current_addr_sk#3806)
    int left_nrow = tbl_JOIN_INNER_TD_6149111_output.getNumRow();
    int right_nrow = tbl_Filter_TD_656333_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5966274_key_leftMajor, SW_JOIN_INNER_TD_5966274_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_6149111_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_customer_sk3725_k = tbl_JOIN_INNER_TD_6149111_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_5966274_key_leftMajor keyA{_ss_customer_sk3725_k};
            int32_t _ss_item_sk3724 = tbl_JOIN_INNER_TD_6149111_output.getInt32(i, 0);
            int32_t _ss_customer_sk3725 = tbl_JOIN_INNER_TD_6149111_output.getInt32(i, 1);
            int64_t _ss_ext_sales_price3737 = tbl_JOIN_INNER_TD_6149111_output.getInt64(i, 2);
            SW_JOIN_INNER_TD_5966274_payload_leftMajor payloadA{_ss_item_sk3724, _ss_customer_sk3725, _ss_ext_sales_price3737};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_656333_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk3802_k = tbl_Filter_TD_656333_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5966274_key_leftMajor{_c_customer_sk3802_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk3724 = (it->second)._ss_item_sk3724;
                int32_t _ss_customer_sk3725 = (it->second)._ss_customer_sk3725;
                int64_t _ss_ext_sales_price3737 = (it->second)._ss_ext_sales_price3737;
                int32_t _c_customer_sk3802 = tbl_Filter_TD_656333_output.getInt32(i, 0);
                int32_t _c_current_addr_sk3806 = tbl_Filter_TD_656333_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_5966274_output.setInt32(r, 0, _ss_item_sk3724);
                tbl_JOIN_INNER_TD_5966274_output.setInt64(r, 1, _ss_ext_sales_price3737);
                tbl_JOIN_INNER_TD_5966274_output.setInt32(r, 2, _c_current_addr_sk3806);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5966274_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5966274_key_rightMajor, SW_JOIN_INNER_TD_5966274_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_656333_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk3802_k = tbl_Filter_TD_656333_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5966274_key_rightMajor keyA{_c_customer_sk3802_k};
            int32_t _c_customer_sk3802 = tbl_Filter_TD_656333_output.getInt32(i, 0);
            int32_t _c_current_addr_sk3806 = tbl_Filter_TD_656333_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_5966274_payload_rightMajor payloadA{_c_customer_sk3802, _c_current_addr_sk3806};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_6149111_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_customer_sk3725_k = tbl_JOIN_INNER_TD_6149111_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5966274_key_rightMajor{_ss_customer_sk3725_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk3802 = (it->second)._c_customer_sk3802;
                int32_t _c_current_addr_sk3806 = (it->second)._c_current_addr_sk3806;
                int32_t _ss_item_sk3724 = tbl_JOIN_INNER_TD_6149111_output.getInt32(i, 0);
                int32_t _ss_customer_sk3725 = tbl_JOIN_INNER_TD_6149111_output.getInt32(i, 1);
                int64_t _ss_ext_sales_price3737 = tbl_JOIN_INNER_TD_6149111_output.getInt64(i, 2);
                tbl_JOIN_INNER_TD_5966274_output.setInt32(r, 2, _c_current_addr_sk3806);
                tbl_JOIN_INNER_TD_5966274_output.setInt32(r, 0, _ss_item_sk3724);
                tbl_JOIN_INNER_TD_5966274_output.setInt64(r, 1, _ss_ext_sales_price3737);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5966274_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5966274_output #Row: " << tbl_JOIN_INNER_TD_5966274_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5522498(Table &tbl_SerializeFromObject_TD_6784548_input, Table &tbl_Filter_TD_5522498_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ca_address_sk#54))
    // Input: ListBuffer(ca_address_sk#54)
    // Output: ListBuffer(ca_address_sk#54)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6784548_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ca_address_sk54 = tbl_SerializeFromObject_TD_6784548_input.getInt32(i, 0);
        if (_ca_address_sk54!= 0) {
            int32_t _ca_address_sk54_t = tbl_SerializeFromObject_TD_6784548_input.getInt32(i, 0);
            tbl_Filter_TD_5522498_output.setInt32(r, 0, _ca_address_sk54_t);
            r++;
        }
    }
    tbl_Filter_TD_5522498_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5522498_output #Row: " << tbl_Filter_TD_5522498_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_5241017_key_leftMajor {
    int32_t _ss_customer_sk1209;
    bool operator==(const SW_JOIN_INNER_TD_5241017_key_leftMajor& other) const {
        return ((_ss_customer_sk1209 == other._ss_customer_sk1209));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5241017_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5241017_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_customer_sk1209));
    }
};
}
struct SW_JOIN_INNER_TD_5241017_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int32_t _ss_customer_sk1209;
    int64_t _ss_ext_sales_price1221;
};
struct SW_JOIN_INNER_TD_5241017_key_rightMajor {
    int32_t _c_customer_sk0;
    bool operator==(const SW_JOIN_INNER_TD_5241017_key_rightMajor& other) const {
        return ((_c_customer_sk0 == other._c_customer_sk0));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_5241017_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_5241017_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_customer_sk0));
    }
};
}
struct SW_JOIN_INNER_TD_5241017_payload_rightMajor {
    int32_t _c_customer_sk0;
    int32_t _c_current_addr_sk4;
};
void SW_JOIN_INNER_TD_5241017(Table &tbl_JOIN_INNER_TD_6370860_output, Table &tbl_Filter_TD_6785245_output, Table &tbl_JOIN_INNER_TD_5241017_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_customer_sk#1209 = c_customer_sk#0))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_customer_sk#1209, ss_ext_sales_price#1221)
    // Right Table: ListBuffer(c_customer_sk#0, c_current_addr_sk#4)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_ext_sales_price#1221, c_current_addr_sk#4)
    int left_nrow = tbl_JOIN_INNER_TD_6370860_output.getNumRow();
    int right_nrow = tbl_Filter_TD_6785245_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5241017_key_leftMajor, SW_JOIN_INNER_TD_5241017_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_6370860_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_customer_sk1209_k = tbl_JOIN_INNER_TD_6370860_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_5241017_key_leftMajor keyA{_ss_customer_sk1209_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_6370860_output.getInt32(i, 0);
            int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_6370860_output.getInt32(i, 1);
            int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_6370860_output.getInt64(i, 2);
            SW_JOIN_INNER_TD_5241017_payload_leftMajor payloadA{_ss_item_sk1208, _ss_customer_sk1209, _ss_ext_sales_price1221};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_6785245_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_6785245_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5241017_key_leftMajor{_c_customer_sk0_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int32_t _ss_customer_sk1209 = (it->second)._ss_customer_sk1209;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int32_t _c_customer_sk0 = tbl_Filter_TD_6785245_output.getInt32(i, 0);
                int32_t _c_current_addr_sk4 = tbl_Filter_TD_6785245_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_5241017_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_5241017_output.setInt64(r, 1, _ss_ext_sales_price1221);
                tbl_JOIN_INNER_TD_5241017_output.setInt32(r, 2, _c_current_addr_sk4);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5241017_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_5241017_key_rightMajor, SW_JOIN_INNER_TD_5241017_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_6785245_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_customer_sk0_k = tbl_Filter_TD_6785245_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_5241017_key_rightMajor keyA{_c_customer_sk0_k};
            int32_t _c_customer_sk0 = tbl_Filter_TD_6785245_output.getInt32(i, 0);
            int32_t _c_current_addr_sk4 = tbl_Filter_TD_6785245_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_5241017_payload_rightMajor payloadA{_c_customer_sk0, _c_current_addr_sk4};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_6370860_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_customer_sk1209_k = tbl_JOIN_INNER_TD_6370860_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_5241017_key_rightMajor{_ss_customer_sk1209_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _c_customer_sk0 = (it->second)._c_customer_sk0;
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_6370860_output.getInt32(i, 0);
                int32_t _ss_customer_sk1209 = tbl_JOIN_INNER_TD_6370860_output.getInt32(i, 1);
                int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_6370860_output.getInt64(i, 2);
                tbl_JOIN_INNER_TD_5241017_output.setInt32(r, 2, _c_current_addr_sk4);
                tbl_JOIN_INNER_TD_5241017_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_5241017_output.setInt64(r, 1, _ss_ext_sales_price1221);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_5241017_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_5241017_output #Row: " << tbl_JOIN_INNER_TD_5241017_output.getNumRow() << std::endl;
}

void SW_Filter_TD_4540377(Table &tbl_SerializeFromObject_TD_5169601_input, Table &tbl_Filter_TD_4540377_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(i_category#3845) AND (i_category#3845 = Jewelry)) AND isnotnull(i_item_sk#3833)))
    // Input: ListBuffer(i_item_sk#3833, i_category#3845)
    // Output: ListBuffer(i_item_sk#3833)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5169601_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category3845 = tbl_SerializeFromObject_TD_5169601_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _i_item_sk3833 = tbl_SerializeFromObject_TD_5169601_input.getInt32(i, 0);
        if (((_i_category3845.data() != "NULL") && (std::string(_i_category3845.data()) == "Jewelry")) && (_i_item_sk3833!= 0)) {
            int32_t _i_item_sk3833_t = tbl_SerializeFromObject_TD_5169601_input.getInt32(i, 0);
            tbl_Filter_TD_4540377_output.setInt32(r, 0, _i_item_sk3833_t);
            r++;
        }
    }
    tbl_Filter_TD_4540377_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4540377_output #Row: " << tbl_Filter_TD_4540377_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4283852_key_leftMajor {
    int32_t _c_current_addr_sk3806;
    bool operator==(const SW_JOIN_INNER_TD_4283852_key_leftMajor& other) const {
        return ((_c_current_addr_sk3806 == other._c_current_addr_sk3806));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4283852_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4283852_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_current_addr_sk3806));
    }
};
}
struct SW_JOIN_INNER_TD_4283852_payload_leftMajor {
    int32_t _ss_item_sk3724;
    int64_t _ss_ext_sales_price3737;
    int32_t _c_current_addr_sk3806;
};
struct SW_JOIN_INNER_TD_4283852_key_rightMajor {
    int32_t _ca_address_sk3820;
    bool operator==(const SW_JOIN_INNER_TD_4283852_key_rightMajor& other) const {
        return ((_ca_address_sk3820 == other._ca_address_sk3820));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4283852_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4283852_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk3820));
    }
};
}
struct SW_JOIN_INNER_TD_4283852_payload_rightMajor {
    int32_t _ca_address_sk3820;
};
void SW_JOIN_INNER_TD_4283852(Table &tbl_JOIN_INNER_TD_5966274_output, Table &tbl_Filter_TD_5282555_output, Table &tbl_JOIN_INNER_TD_4283852_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ca_address_sk#3820 = c_current_addr_sk#3806))
    // Left Table: ListBuffer(ss_item_sk#3724, ss_ext_sales_price#3737, c_current_addr_sk#3806)
    // Right Table: ListBuffer(ca_address_sk#3820)
    // Output Table: ListBuffer(ss_item_sk#3724, ss_ext_sales_price#3737)
    int left_nrow = tbl_JOIN_INNER_TD_5966274_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5282555_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4283852_key_leftMajor, SW_JOIN_INNER_TD_4283852_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_5966274_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_current_addr_sk3806_k = tbl_JOIN_INNER_TD_5966274_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_4283852_key_leftMajor keyA{_c_current_addr_sk3806_k};
            int32_t _ss_item_sk3724 = tbl_JOIN_INNER_TD_5966274_output.getInt32(i, 0);
            int64_t _ss_ext_sales_price3737 = tbl_JOIN_INNER_TD_5966274_output.getInt64(i, 1);
            int32_t _c_current_addr_sk3806 = tbl_JOIN_INNER_TD_5966274_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_4283852_payload_leftMajor payloadA{_ss_item_sk3724, _ss_ext_sales_price3737, _c_current_addr_sk3806};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5282555_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk3820_k = tbl_Filter_TD_5282555_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4283852_key_leftMajor{_ca_address_sk3820_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk3724 = (it->second)._ss_item_sk3724;
                int64_t _ss_ext_sales_price3737 = (it->second)._ss_ext_sales_price3737;
                int32_t _c_current_addr_sk3806 = (it->second)._c_current_addr_sk3806;
                int32_t _ca_address_sk3820 = tbl_Filter_TD_5282555_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_4283852_output.setInt32(r, 0, _ss_item_sk3724);
                tbl_JOIN_INNER_TD_4283852_output.setInt64(r, 1, _ss_ext_sales_price3737);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4283852_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4283852_key_rightMajor, SW_JOIN_INNER_TD_4283852_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5282555_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk3820_k = tbl_Filter_TD_5282555_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4283852_key_rightMajor keyA{_ca_address_sk3820_k};
            int32_t _ca_address_sk3820 = tbl_Filter_TD_5282555_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4283852_payload_rightMajor payloadA{_ca_address_sk3820};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_5966274_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_current_addr_sk3806_k = tbl_JOIN_INNER_TD_5966274_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4283852_key_rightMajor{_c_current_addr_sk3806_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk3820 = (it->second)._ca_address_sk3820;
                int32_t _ss_item_sk3724 = tbl_JOIN_INNER_TD_5966274_output.getInt32(i, 0);
                int64_t _ss_ext_sales_price3737 = tbl_JOIN_INNER_TD_5966274_output.getInt64(i, 1);
                int32_t _c_current_addr_sk3806 = tbl_JOIN_INNER_TD_5966274_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_4283852_output.setInt32(r, 0, _ss_item_sk3724);
                tbl_JOIN_INNER_TD_4283852_output.setInt64(r, 1, _ss_ext_sales_price3737);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4283852_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4283852_output #Row: " << tbl_JOIN_INNER_TD_4283852_output.getNumRow() << std::endl;
}

void SW_Filter_TD_4121212(Table &tbl_SerializeFromObject_TD_5542235_input, Table &tbl_Filter_TD_4121212_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(i_category#240) AND (i_category#240 = Jewelry)) AND isnotnull(i_item_sk#228)))
    // Input: ListBuffer(i_item_sk#228, i_category#240)
    // Output: ListBuffer(i_item_sk#228)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5542235_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category240 = tbl_SerializeFromObject_TD_5542235_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_5542235_input.getInt32(i, 0);
        if (((_i_category240.data() != "NULL") && (std::string(_i_category240.data()) == "Jewelry")) && (_i_item_sk228!= 0)) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_5542235_input.getInt32(i, 0);
            tbl_Filter_TD_4121212_output.setInt32(r, 0, _i_item_sk228_t);
            r++;
        }
    }
    tbl_Filter_TD_4121212_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4121212_output #Row: " << tbl_Filter_TD_4121212_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4146508_key_leftMajor {
    int32_t _c_current_addr_sk4;
    bool operator==(const SW_JOIN_INNER_TD_4146508_key_leftMajor& other) const {
        return ((_c_current_addr_sk4 == other._c_current_addr_sk4));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4146508_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4146508_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._c_current_addr_sk4));
    }
};
}
struct SW_JOIN_INNER_TD_4146508_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int64_t _ss_ext_sales_price1221;
    int32_t _c_current_addr_sk4;
};
struct SW_JOIN_INNER_TD_4146508_key_rightMajor {
    int32_t _ca_address_sk54;
    bool operator==(const SW_JOIN_INNER_TD_4146508_key_rightMajor& other) const {
        return ((_ca_address_sk54 == other._ca_address_sk54));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4146508_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4146508_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ca_address_sk54));
    }
};
}
struct SW_JOIN_INNER_TD_4146508_payload_rightMajor {
    int32_t _ca_address_sk54;
};
void SW_JOIN_INNER_TD_4146508(Table &tbl_JOIN_INNER_TD_5241017_output, Table &tbl_Filter_TD_5522498_output, Table &tbl_JOIN_INNER_TD_4146508_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ca_address_sk#54 = c_current_addr_sk#4))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_ext_sales_price#1221, c_current_addr_sk#4)
    // Right Table: ListBuffer(ca_address_sk#54)
    // Output Table: ListBuffer(ss_item_sk#1208, ss_ext_sales_price#1221)
    int left_nrow = tbl_JOIN_INNER_TD_5241017_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5522498_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4146508_key_leftMajor, SW_JOIN_INNER_TD_4146508_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_5241017_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _c_current_addr_sk4_k = tbl_JOIN_INNER_TD_5241017_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_4146508_key_leftMajor keyA{_c_current_addr_sk4_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_5241017_output.getInt32(i, 0);
            int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_5241017_output.getInt64(i, 1);
            int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_5241017_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_4146508_payload_leftMajor payloadA{_ss_item_sk1208, _ss_ext_sales_price1221, _c_current_addr_sk4};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5522498_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_5522498_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4146508_key_leftMajor{_ca_address_sk54_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int32_t _c_current_addr_sk4 = (it->second)._c_current_addr_sk4;
                int32_t _ca_address_sk54 = tbl_Filter_TD_5522498_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_4146508_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_4146508_output.setInt64(r, 1, _ss_ext_sales_price1221);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4146508_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4146508_key_rightMajor, SW_JOIN_INNER_TD_4146508_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5522498_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ca_address_sk54_k = tbl_Filter_TD_5522498_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4146508_key_rightMajor keyA{_ca_address_sk54_k};
            int32_t _ca_address_sk54 = tbl_Filter_TD_5522498_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4146508_payload_rightMajor payloadA{_ca_address_sk54};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_5241017_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _c_current_addr_sk4_k = tbl_JOIN_INNER_TD_5241017_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4146508_key_rightMajor{_c_current_addr_sk4_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ca_address_sk54 = (it->second)._ca_address_sk54;
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_5241017_output.getInt32(i, 0);
                int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_5241017_output.getInt64(i, 1);
                int32_t _c_current_addr_sk4 = tbl_JOIN_INNER_TD_5241017_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_4146508_output.setInt32(r, 0, _ss_item_sk1208);
                tbl_JOIN_INNER_TD_4146508_output.setInt64(r, 1, _ss_ext_sales_price1221);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4146508_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4146508_output #Row: " << tbl_JOIN_INNER_TD_4146508_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_3519817_key_leftMajor {
    int32_t _ss_item_sk3724;
    bool operator==(const SW_JOIN_INNER_TD_3519817_key_leftMajor& other) const {
        return ((_ss_item_sk3724 == other._ss_item_sk3724));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3519817_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3519817_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk3724));
    }
};
}
struct SW_JOIN_INNER_TD_3519817_payload_leftMajor {
    int32_t _ss_item_sk3724;
    int64_t _ss_ext_sales_price3737;
};
struct SW_JOIN_INNER_TD_3519817_key_rightMajor {
    int32_t _i_item_sk3833;
    bool operator==(const SW_JOIN_INNER_TD_3519817_key_rightMajor& other) const {
        return ((_i_item_sk3833 == other._i_item_sk3833));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_3519817_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_3519817_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk3833));
    }
};
}
struct SW_JOIN_INNER_TD_3519817_payload_rightMajor {
    int32_t _i_item_sk3833;
};
void SW_JOIN_INNER_TD_3519817(Table &tbl_JOIN_INNER_TD_4283852_output, Table &tbl_Filter_TD_4540377_output, Table &tbl_JOIN_INNER_TD_3519817_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_item_sk#3724 = i_item_sk#3833))
    // Left Table: ListBuffer(ss_item_sk#3724, ss_ext_sales_price#3737)
    // Right Table: ListBuffer(i_item_sk#3833)
    // Output Table: ListBuffer(ss_ext_sales_price#3737)
    int left_nrow = tbl_JOIN_INNER_TD_4283852_output.getNumRow();
    int right_nrow = tbl_Filter_TD_4540377_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3519817_key_leftMajor, SW_JOIN_INNER_TD_3519817_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_4283852_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk3724_k = tbl_JOIN_INNER_TD_4283852_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3519817_key_leftMajor keyA{_ss_item_sk3724_k};
            int32_t _ss_item_sk3724 = tbl_JOIN_INNER_TD_4283852_output.getInt32(i, 0);
            int64_t _ss_ext_sales_price3737 = tbl_JOIN_INNER_TD_4283852_output.getInt64(i, 1);
            SW_JOIN_INNER_TD_3519817_payload_leftMajor payloadA{_ss_item_sk3724, _ss_ext_sales_price3737};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_4540377_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk3833_k = tbl_Filter_TD_4540377_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3519817_key_leftMajor{_i_item_sk3833_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk3724 = (it->second)._ss_item_sk3724;
                int64_t _ss_ext_sales_price3737 = (it->second)._ss_ext_sales_price3737;
                int32_t _i_item_sk3833 = tbl_Filter_TD_4540377_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_3519817_output.setInt64(r, 0, _ss_ext_sales_price3737);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3519817_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_3519817_key_rightMajor, SW_JOIN_INNER_TD_3519817_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_4540377_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk3833_k = tbl_Filter_TD_4540377_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3519817_key_rightMajor keyA{_i_item_sk3833_k};
            int32_t _i_item_sk3833 = tbl_Filter_TD_4540377_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_3519817_payload_rightMajor payloadA{_i_item_sk3833};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_4283852_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk3724_k = tbl_JOIN_INNER_TD_4283852_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_3519817_key_rightMajor{_ss_item_sk3724_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk3833 = (it->second)._i_item_sk3833;
                int32_t _ss_item_sk3724 = tbl_JOIN_INNER_TD_4283852_output.getInt32(i, 0);
                int64_t _ss_ext_sales_price3737 = tbl_JOIN_INNER_TD_4283852_output.getInt64(i, 1);
                tbl_JOIN_INNER_TD_3519817_output.setInt64(r, 0, _ss_ext_sales_price3737);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_3519817_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_3519817_output #Row: " << tbl_JOIN_INNER_TD_3519817_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_362046_key_leftMajor {
    int32_t _ss_item_sk1208;
    bool operator==(const SW_JOIN_INNER_TD_362046_key_leftMajor& other) const {
        return ((_ss_item_sk1208 == other._ss_item_sk1208));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_362046_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_362046_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk1208));
    }
};
}
struct SW_JOIN_INNER_TD_362046_payload_leftMajor {
    int32_t _ss_item_sk1208;
    int64_t _ss_ext_sales_price1221;
};
struct SW_JOIN_INNER_TD_362046_key_rightMajor {
    int32_t _i_item_sk228;
    bool operator==(const SW_JOIN_INNER_TD_362046_key_rightMajor& other) const {
        return ((_i_item_sk228 == other._i_item_sk228));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_362046_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_362046_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk228));
    }
};
}
struct SW_JOIN_INNER_TD_362046_payload_rightMajor {
    int32_t _i_item_sk228;
};
void SW_JOIN_INNER_TD_362046(Table &tbl_JOIN_INNER_TD_4146508_output, Table &tbl_Filter_TD_4121212_output, Table &tbl_JOIN_INNER_TD_362046_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((ss_item_sk#1208 = i_item_sk#228))
    // Left Table: ListBuffer(ss_item_sk#1208, ss_ext_sales_price#1221)
    // Right Table: ListBuffer(i_item_sk#228)
    // Output Table: ListBuffer(ss_ext_sales_price#1221)
    int left_nrow = tbl_JOIN_INNER_TD_4146508_output.getNumRow();
    int right_nrow = tbl_Filter_TD_4121212_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_362046_key_leftMajor, SW_JOIN_INNER_TD_362046_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_4146508_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_4146508_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_362046_key_leftMajor keyA{_ss_item_sk1208_k};
            int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_4146508_output.getInt32(i, 0);
            int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_4146508_output.getInt64(i, 1);
            SW_JOIN_INNER_TD_362046_payload_leftMajor payloadA{_ss_item_sk1208, _ss_ext_sales_price1221};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_4121212_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_4121212_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_362046_key_leftMajor{_i_item_sk228_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ss_item_sk1208 = (it->second)._ss_item_sk1208;
                int64_t _ss_ext_sales_price1221 = (it->second)._ss_ext_sales_price1221;
                int32_t _i_item_sk228 = tbl_Filter_TD_4121212_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_362046_output.setInt64(r, 0, _ss_ext_sales_price1221);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_362046_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_362046_key_rightMajor, SW_JOIN_INNER_TD_362046_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_4121212_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_4121212_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_362046_key_rightMajor keyA{_i_item_sk228_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_4121212_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_362046_payload_rightMajor payloadA{_i_item_sk228};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_4146508_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ss_item_sk1208_k = tbl_JOIN_INNER_TD_4146508_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_362046_key_rightMajor{_ss_item_sk1208_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_4146508_output.getInt32(i, 0);
                int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_4146508_output.getInt64(i, 1);
                tbl_JOIN_INNER_TD_362046_output.setInt64(r, 0, _ss_ext_sales_price1221);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_362046_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_362046_output #Row: " << tbl_JOIN_INNER_TD_362046_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_2866432(Table &tbl_JOIN_INNER_TD_3519817_output, Table &tbl_Aggregate_TD_2866432_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(MakeDecimal(sum(UnscaledValue(ss_ext_sales_price#3737)),17,2) AS total#3721)
    // Input: ListBuffer(ss_ext_sales_price#3737)
    // Output: ListBuffer(total#3721)
    int64_t sum_0 = 0;
    int nrow1 = tbl_JOIN_INNER_TD_3519817_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ss_ext_sales_price3737 = tbl_JOIN_INNER_TD_3519817_output.getInt64(i, 0);
        int64_t _total3721_sum_0 = _ss_ext_sales_price3737;
        sum_0 += _total3721_sum_0;
    }
    int r = 0;
    int64_t _total3721 = sum_0;
    tbl_Aggregate_TD_2866432_output.setInt64(r++, 0, _total3721);
    tbl_Aggregate_TD_2866432_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_2866432_output #Row: " << tbl_Aggregate_TD_2866432_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_2869480(Table &tbl_JOIN_INNER_TD_362046_output, Table &tbl_Aggregate_TD_2869480_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(MakeDecimal(sum(UnscaledValue(ss_ext_sales_price#1221)),17,2) AS promotions#3720)
    // Input: ListBuffer(ss_ext_sales_price#1221)
    // Output: ListBuffer(promotions#3720)
    int64_t sum_0 = 0;
    int nrow1 = tbl_JOIN_INNER_TD_362046_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ss_ext_sales_price1221 = tbl_JOIN_INNER_TD_362046_output.getInt64(i, 0);
        int64_t _promotions3720_sum_0 = _ss_ext_sales_price1221;
        sum_0 += _promotions3720_sum_0;
    }
    int r = 0;
    int64_t _promotions3720 = sum_0;
    tbl_Aggregate_TD_2869480_output.setInt64(r++, 0, _promotions3720);
    tbl_Aggregate_TD_2869480_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_2869480_output #Row: " << tbl_Aggregate_TD_2869480_output.getNumRow() << std::endl;
}

void SW_JOIN_CROSS_TD_1666977(Table &tbl_Aggregate_TD_2869480_output, Table &tbl_Aggregate_TD_2866432_output, Table &tbl_JOIN_CROSS_TD_1666977_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_CROSS
    // Operation: ListBuffer(JOIN_CROSS)
    // Left Table: ListBuffer(promotions#3720)
    // Right Table: ListBuffer(total#3721)
    // Output Table: ListBuffer(promotions#3720, total#3721)
    int left_nrow = tbl_Aggregate_TD_2869480_output.getNumRow();
    int right_nrow = tbl_Aggregate_TD_2866432_output.getNumRow();
    long r = 0;
    for (int i = 0; i < left_nrow; i++) {
        for (int j = 0; j < right_nrow; j++) {
            tbl_JOIN_CROSS_TD_1666977_output.setInt64(r, 0, tbl_Aggregate_TD_2869480_output.getInt64(i, 0));
            tbl_JOIN_CROSS_TD_1666977_output.setInt64(r, 1, tbl_Aggregate_TD_2866432_output.getInt64(j, 0));
            ++r;
        }
    }
    tbl_JOIN_CROSS_TD_1666977_output.setNumRow(r);
    std::cout << "tbl_JOIN_CROSS_TD_1666977_output #Row: " << tbl_JOIN_CROSS_TD_1666977_output.getNumRow() << std::endl;
}

void SW_Project_TD_0192533(Table &tbl_JOIN_CROSS_TD_1666977_output, Table &tbl_Project_TD_0192533_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(CheckOverflow((promote_precision(CheckOverflow((promote_precision(promotions#3720) / promote_precision(total#3721)), DecimalType(37,20), true)) * 100.00000000000000000000), DecimalType(38,17), true) AS ((promotions / total) * 100)#3857)
    // Input: ListBuffer(promotions#3720, total#3721)
    // Output: ListBuffer(promotions#3720, total#3721, ((promotions / total) * 100)#3857)
    int nrow1 = tbl_JOIN_CROSS_TD_1666977_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _promotions3720 = tbl_JOIN_CROSS_TD_1666977_output.getInt64(i, 0);
        int64_t _total3721 = tbl_JOIN_CROSS_TD_1666977_output.getInt64(i, 1);
        int64_t _1003857 = ((_promotions3720 / _total3721) * 100.00000000000000000000);
        tbl_Project_TD_0192533_output.setInt64(i, 2, _1003857);
        tbl_Project_TD_0192533_output.setInt64(i, 0, _promotions3720);
        tbl_Project_TD_0192533_output.setInt64(i, 1, _total3721);
    }
    tbl_Project_TD_0192533_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_0192533_output #Row: " << tbl_Project_TD_0192533_output.getNumRow() << std::endl;
}

