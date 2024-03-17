#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_8265674(Table &tbl_SerializeFromObject_TD_962216_input, Table &tbl_Filter_TD_8265674_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_month_seq#123) AND ((d_month_seq#123 >= 1200) AND (d_month_seq#123 <= 1211))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_month_seq#123)
    // Output: ListBuffer(d_date_sk#120)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_962216_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_month_seq123 = tbl_SerializeFromObject_TD_962216_input.getInt32(i, 1);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_962216_input.getInt32(i, 0);
        if (((_d_month_seq123!= 0) && ((_d_month_seq123 >= 1200) && (_d_month_seq123 <= 1211))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_962216_input.getInt32(i, 0);
            tbl_Filter_TD_8265674_output.setInt32(r, 0, _d_date_sk120_t);
            r++;
        }
    }
    tbl_Filter_TD_8265674_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8265674_output #Row: " << tbl_Filter_TD_8265674_output.getNumRow() << std::endl;
}

void SW_Filter_TD_8251406(Table &tbl_SerializeFromObject_TD_9429991_input, Table &tbl_Filter_TD_8251406_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_sold_date_sk#729) AND isnotnull(ws_item_sk#732)))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_net_paid#758)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_net_paid#758)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9429991_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_9429991_input.getInt32(i, 0);
        int32_t _ws_item_sk732 = tbl_SerializeFromObject_TD_9429991_input.getInt32(i, 1);
        if ((_ws_sold_date_sk729!= 0) && (_ws_item_sk732!= 0)) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_9429991_input.getInt32(i, 0);
            tbl_Filter_TD_8251406_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_item_sk732_t = tbl_SerializeFromObject_TD_9429991_input.getInt32(i, 1);
            tbl_Filter_TD_8251406_output.setInt32(r, 1, _ws_item_sk732_t);
            int64_t _ws_net_paid758_t = tbl_SerializeFromObject_TD_9429991_input.getInt64(i, 2);
            tbl_Filter_TD_8251406_output.setInt64(r, 2, _ws_net_paid758_t);
            r++;
        }
    }
    tbl_Filter_TD_8251406_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8251406_output #Row: " << tbl_Filter_TD_8251406_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7847500(Table &tbl_SerializeFromObject_TD_8301945_input, Table &tbl_Filter_TD_7847500_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(i_item_sk#228))
    // Input: ListBuffer(i_item_sk#228, i_class#238, i_category#240)
    // Output: ListBuffer(i_item_sk#228, i_class#238, i_category#240)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8301945_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_item_sk228 = tbl_SerializeFromObject_TD_8301945_input.getInt32(i, 0);
        if (_i_item_sk228!= 0) {
            int32_t _i_item_sk228_t = tbl_SerializeFromObject_TD_8301945_input.getInt32(i, 0);
            tbl_Filter_TD_7847500_output.setInt32(r, 0, _i_item_sk228_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_class238_t = tbl_SerializeFromObject_TD_8301945_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_7847500_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_class238_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_t = tbl_SerializeFromObject_TD_8301945_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_7847500_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_category240_t);
            r++;
        }
    }
    tbl_Filter_TD_7847500_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7847500_output #Row: " << tbl_Filter_TD_7847500_output.getNumRow() << std::endl;
}


struct SW_JOIN_INNER_TD_6755077_key_leftMajor {
    int32_t _ws_item_sk732;
    bool operator==(const SW_JOIN_INNER_TD_6755077_key_leftMajor& other) const {
        return ((_ws_item_sk732 == other._ws_item_sk732));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6755077_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6755077_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_item_sk732));
    }
};
}
struct SW_JOIN_INNER_TD_6755077_payload_leftMajor {
    int32_t _ws_item_sk732;
    int64_t _ws_net_paid758;
};
struct SW_JOIN_INNER_TD_6755077_key_rightMajor {
    int32_t _i_item_sk228;
    bool operator==(const SW_JOIN_INNER_TD_6755077_key_rightMajor& other) const {
        return ((_i_item_sk228 == other._i_item_sk228));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6755077_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6755077_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._i_item_sk228));
    }
};
}
struct SW_JOIN_INNER_TD_6755077_payload_rightMajor {
    int32_t _i_item_sk228;
    std::string _i_class238;
    std::string _i_category240;
};
void SW_JOIN_INNER_TD_6755077(Table &tbl_JOIN_INNER_TD_7959031_output, Table &tbl_Filter_TD_7847500_output, Table &tbl_JOIN_INNER_TD_6755077_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((i_item_sk#228 = ws_item_sk#732))
    // Left Table: ListBuffer(ws_item_sk#732, ws_net_paid#758)
    // Right Table: ListBuffer(i_item_sk#228, i_class#238, i_category#240)
    // Output Table: ListBuffer(ws_net_paid#758, i_category#240, i_class#238)
    int left_nrow = tbl_JOIN_INNER_TD_7959031_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7847500_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6755077_key_leftMajor, SW_JOIN_INNER_TD_6755077_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_7959031_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ws_item_sk732_k = tbl_JOIN_INNER_TD_7959031_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6755077_key_leftMajor keyA{_ws_item_sk732_k};
            int32_t _ws_item_sk732 = tbl_JOIN_INNER_TD_7959031_output.getInt32(i, 0);
            int64_t _ws_net_paid758 = tbl_JOIN_INNER_TD_7959031_output.getInt64(i, 1);
            SW_JOIN_INNER_TD_6755077_payload_leftMajor payloadA{_ws_item_sk732, _ws_net_paid758};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7847500_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_7847500_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6755077_key_leftMajor{_i_item_sk228_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _ws_item_sk732 = (it->second)._ws_item_sk732;
                int64_t _ws_net_paid758 = (it->second)._ws_net_paid758;
                int32_t _i_item_sk228 = tbl_Filter_TD_7847500_output.getInt32(i, 0);
                std::array<char, TPCDS_READ_MAX + 1> _i_class238_n = tbl_Filter_TD_7847500_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_class238 = std::string(_i_class238_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_Filter_TD_7847500_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _i_category240 = std::string(_i_category240_n.data());
                tbl_JOIN_INNER_TD_6755077_output.setInt64(r, 0, _ws_net_paid758);
                tbl_JOIN_INNER_TD_6755077_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_class238_n);
                tbl_JOIN_INNER_TD_6755077_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category240_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6755077_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6755077_key_rightMajor, SW_JOIN_INNER_TD_6755077_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7847500_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _i_item_sk228_k = tbl_Filter_TD_7847500_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6755077_key_rightMajor keyA{_i_item_sk228_k};
            int32_t _i_item_sk228 = tbl_Filter_TD_7847500_output.getInt32(i, 0);
            std::array<char, TPCDS_READ_MAX + 1> _i_class238_n = tbl_Filter_TD_7847500_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_class238 = std::string(_i_class238_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_category240_n = tbl_Filter_TD_7847500_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _i_category240 = std::string(_i_category240_n.data());
            SW_JOIN_INNER_TD_6755077_payload_rightMajor payloadA{_i_item_sk228, _i_class238, _i_category240};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_7959031_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ws_item_sk732_k = tbl_JOIN_INNER_TD_7959031_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6755077_key_rightMajor{_ws_item_sk732_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _i_item_sk228 = (it->second)._i_item_sk228;
                std::string _i_class238 = (it->second)._i_class238;
                std::array<char, TPCDS_READ_MAX + 1> _i_class238_n{};
                memcpy(_i_class238_n.data(), (_i_class238).data(), (_i_class238).length());
                std::string _i_category240 = (it->second)._i_category240;
                std::array<char, TPCDS_READ_MAX + 1> _i_category240_n{};
                memcpy(_i_category240_n.data(), (_i_category240).data(), (_i_category240).length());
                int32_t _ws_item_sk732 = tbl_JOIN_INNER_TD_7959031_output.getInt32(i, 0);
                int64_t _ws_net_paid758 = tbl_JOIN_INNER_TD_7959031_output.getInt64(i, 1);
                tbl_JOIN_INNER_TD_6755077_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_class238_n);
                tbl_JOIN_INNER_TD_6755077_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category240_n);
                tbl_JOIN_INNER_TD_6755077_output.setInt64(r, 0, _ws_net_paid758);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6755077_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6755077_output #Row: " << tbl_JOIN_INNER_TD_6755077_output.getNumRow() << std::endl;
}

void SW_Expand_TD_5234627(Table &tbl_JOIN_INNER_TD_6755077_output, Table &tbl_Expand_TD_5234627_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Expand
    // Operation: ListBuffer(Expand)
    // Input: ListBuffer(ws_net_paid#758, i_category#240, i_class#238)
    // Output: ListBuffer(ws_net_paid#758, i_category#3554, i_class#3555, spark_grouping_id#3553L)
    std::cout << "tbl_Expand_TD_5234627_output #Row: " << tbl_Expand_TD_5234627_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_4765968_key {
    std::string _i_category3554;
    std::string _i_class3555;
    int64_t _spark_grouping_id3553L;
    bool operator==(const SW_Aggregate_TD_4765968_key& other) const { return (_i_category3554 == other._i_category3554) && (_i_class3555 == other._i_class3555) && (_spark_grouping_id3553L == other._spark_grouping_id3553L); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_4765968_key> {
    std::size_t operator() (const SW_Aggregate_TD_4765968_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_category3554)) + (hash<string>()(k._i_class3555)) + (hash<int64_t>()(k._spark_grouping_id3553L));
    }
};
}
struct SW_Aggregate_TD_4765968_payload {
    int64_t _total_sum3544_sum_0;
    int32_t _lochierarchy3545;
    int32_t __w13568;
    std::string __w23569;
    int64_t __w33570_sum_1;
};
void SW_Aggregate_TD_4765968(Table &tbl_Expand_TD_5234627_output, Table &tbl_Aggregate_TD_4765968_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(i_category#3554, i_class#3555, spark_grouping_id#3553L, MakeDecimal(sum(UnscaledValue(ws_net_paid#758)),17,2) AS total_sum#3544, (cast((shiftright(spark_grouping_id#3553L, 1) & 1) as tinyint) + cast((shiftright(spark_grouping_id#3553L, 0) & 1) as tinyint)) AS lochierarchy#3545, (cast((shiftright(spark_grouping_id#3553L, 1) & 1) as tinyint) + cast((shiftright(spark_grouping_id#3553L, 0) & 1) as tinyint)) AS _w1#3568, CASE WHEN (cast((shiftright(spark_grouping_id#3553L, 0) & 1) as tinyint) = 0) THEN i_category#3554 END AS _w2#3569, MakeDecimal(sum(UnscaledValue(ws_net_paid#758)),17,2) AS _w3#3570)
    // Input: ListBuffer(ws_net_paid#758, i_category#3554, i_class#3555, spark_grouping_id#3553L)
    // Output: ListBuffer(total_sum#3544, i_category#3554, i_class#3555, lochierarchy#3545, _w1#3568, _w2#3569, _w3#3570)
    std::unordered_map<SW_Aggregate_TD_4765968_key, SW_Aggregate_TD_4765968_payload> ht1;
    int nrow1 = tbl_Expand_TD_5234627_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _ws_net_paid758 = tbl_Expand_TD_5234627_output.getInt64(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_category3554 = tbl_Expand_TD_5234627_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _i_class3555 = tbl_Expand_TD_5234627_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        int64_t _spark_grouping_id3553L = tbl_Expand_TD_5234627_output.getInt64(i, 3);
        SW_Aggregate_TD_4765968_key k{std::string(_i_category3554.data()), std::string(_i_class3555.data()), _spark_grouping_id3553L};
        int64_t _total_sum3544_sum_0 = _ws_net_paid758;
        int32_t _lochierarchy3545 = (_spark_grouping_id3553L + _spark_grouping_id3553L);
        int32_t __w13568 = (_spark_grouping_id3553L + _spark_grouping_id3553L);
        std::array<char, TPCDS_READ_MAX + 1> __w23569 = (_spark_grouping_id3553L == 0) ? _i_category3554 : 1;
        int64_t __w33570_sum_1 = _ws_net_paid758;
        SW_Aggregate_TD_4765968_payload p{_total_sum3544_sum_0, _lochierarchy3545, __w13568, std::string(__w23569.data()), __w33570_sum_1};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._total_sum3544_sum_0 + _total_sum3544_sum_0;
            p._total_sum3544_sum_0 = sum_0;
            int64_t sum_1 = (it->second).__w33570_sum_1 + __w33570_sum_1;
            p.__w33570_sum_1 = sum_1;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category3554{};
        memcpy(_i_category3554.data(), ((it.first)._i_category3554).data(), ((it.first)._i_category3554).length());
        tbl_Aggregate_TD_4765968_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category3554);
        std::array<char, TPCDS_READ_MAX + 1> _i_class3555{};
        memcpy(_i_class3555.data(), ((it.first)._i_class3555).data(), ((it.first)._i_class3555).length());
        tbl_Aggregate_TD_4765968_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_class3555);
        // _spark_grouping_id3553L not required in the output table
        int64_t _total_sum3544 = (it.second)._total_sum3544_sum_0;
        tbl_Aggregate_TD_4765968_output.setInt64(r, 0, _total_sum3544);
        tbl_Aggregate_TD_4765968_output.setInt32(r, 3, (it.second)._lochierarchy3545);
        tbl_Aggregate_TD_4765968_output.setInt32(r, 4, (it.second).__w13568);
        tbl_Aggregate_TD_4765968_output.setInt64(r, 5, (it.second).__w23569);
        int64_t __w33570 = (it.second).__w33570_sum_1;
        tbl_Aggregate_TD_4765968_output.setInt64(r, 6, __w33570);
        ++r;
    }
    tbl_Aggregate_TD_4765968_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_4765968_output #Row: " << tbl_Aggregate_TD_4765968_output.getNumRow() << std::endl;
}

void SW_Window_TD_3229898(Table &tbl_Aggregate_TD_4765968_output, Table &tbl_Window_TD_3229898_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Window
    // Operation: ListBuffer(rank(_w3#3570) windowspecdefinition(_w1#3568, _w2#3569, _w3#3570 DESC NULLS LAST, specifiedwindowframe(RowFrame, unboundedpreceding$(), currentrow$())) AS rank_within_parent#3546)
    // Input: ListBuffer(total_sum#3544, i_category#3554, i_class#3555, lochierarchy#3545, _w1#3568, _w2#3569, _w3#3570)
    // Output: ListBuffer(total_sum#3544, i_category#3554, i_class#3555, lochierarchy#3545, _w1#3568, _w2#3569, _w3#3570, rank_within_parent#3546)
    struct SW_Window_TD_3229898Row {
        int64_t _total_sum3544;
        std::string _i_category3554;
        std::string _i_class3555;
        int32_t _lochierarchy3545;
        int32_t __w13568;
        int64_t __w23569;
        int64_t __w33570;
    }; 

    int nrow = tbl_Aggregate_TD_4765968_output.getNumRow();
    std::vector<SW_Window_TD_3229898Row> rows0;
    int r = 0;
    for (int i = 0; i < nrow; i++) {
        int64_t _total_sum3544 = tbl_Aggregate_TD_4765968_output.getInt64(i, 0);
        tbl_Window_TD_3229898_output.setInt64(r, 0,_total_sum3544);
        std::array<char, TPCDS_READ_MAX + 1> _i_category3554 = tbl_Aggregate_TD_4765968_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        tbl_Window_TD_3229898_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _i_category3554);
        std::array<char, TPCDS_READ_MAX + 1> _i_class3555 = tbl_Aggregate_TD_4765968_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        tbl_Window_TD_3229898_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _i_class3555);
        int32_t _lochierarchy3545 = tbl_Aggregate_TD_4765968_output.getInt32(i, 3);
        tbl_Window_TD_3229898_output.setInt32(r, 3,_lochierarchy3545);
        int32_t __w13568 = tbl_Aggregate_TD_4765968_output.getInt32(i, 4);
        tbl_Window_TD_3229898_output.setInt32(r, 4,__w13568);
        int64_t __w23569 = tbl_Aggregate_TD_4765968_output.getInt64(i, 5);
        tbl_Window_TD_3229898_output.setInt64(r, 5,__w23569);
        int64_t __w33570 = tbl_Aggregate_TD_4765968_output.getInt64(i, 6);
        tbl_Window_TD_3229898_output.setInt64(r, 6,__w33570);
        r++;
        SW_Window_TD_3229898Row t = {_total_sum3544,std::string(_i_category3554.data()),std::string(_i_class3555.data()),_lochierarchy3545,__w13568,__w23569,__w33570};
        rows0.push_back(t);
    }
    struct {
        bool operator()(const SW_Window_TD_3229898Row& a, const SW_Window_TD_3229898Row& b) const { return 
(a.__w13568 < b.__w13568) || 
 ((a.__w13568 == b.__w13568) && (a.__w23569 < b.__w23569)) || 
 ((a.__w13568 == b.__w13568) && (a.__w23569 == b.__w23569) && (a.__w33570 > b.__w33570)); 
}
    }SW_Window_TD_3229898_order0; 

    std::sort(rows0.begin(), rows0.end(), SW_Window_TD_3229898_order0);
    std::vector<int32_t> ranks0(rows0.size(), 0);
    int32_t currentRank0 = 0;
    int32_t currentPartitionCount0 = 1;
    bool isSamePartition0 = true;
    bool isSameOrderKey0 = true;
    if (!rows0.empty()) {;
      ranks0[0] = ++currentRank0;
    };
    for (int i = 1; i< rows0.size(); i++) {
        isSamePartition0 = ( rows0[i].__w13568 == rows0[i-1].__w13568 && rows0[i].__w23569 == rows0[i-1].__w23569);
        isSameOrderKey0 = ( rows0[i].__w33570 == rows0[i-1].__w33570);
        currentPartitionCount0++;
        if (isSamePartition0&& !isSameOrderKey0) {
            currentRank0 = currentPartitionCount0;
        } else if (!isSamePartition0) {
            currentPartitionCount0 = 1;
            currentRank0 = currentPartitionCount0;
        }
        ranks0[i] = currentRank0;
    }
    for (int i = 0; i< nrow; i++) {
        tbl_Window_TD_3229898_output.setInt32(r, 7, ranks0[i]);
    }
    tbl_Window_TD_3229898_output.setNumRow(r);
    std::cout << "tbl_Window_TD_3229898_output #Row: " << tbl_Window_TD_3229898_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2561917(Table &tbl_Window_TD_3229898_output, Table &tbl_Sort_TD_2561917_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(lochierarchy#3545 DESC NULLS LAST, rank_within_parent#3546 ASC NULLS FIRST)
    // Input: ListBuffer(total_sum#3544, i_category#3554, i_class#3555, lochierarchy#3545, _w1#3568, _w2#3569, _w3#3570, rank_within_parent#3546)
    // Output: ListBuffer(total_sum#3544, i_category#3554, i_class#3555, lochierarchy#3545, rank_within_parent#3546)
    struct SW_Sort_TD_2561917Row {
        int64_t _total_sum3544;
        std::string _i_category3554;
        std::string _i_class3555;
        int32_t _lochierarchy3545;
        int32_t __w13568;
        int64_t __w23569;
        int64_t __w33570;
        int32_t _rank_within_parent3546;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2561917Row& a, const SW_Sort_TD_2561917Row& b) const { return 
 (a._lochierarchy3545 > b._lochierarchy3545) || 
 ((a._lochierarchy3545 == b._lochierarchy3545) && (a._rank_within_parent3546 < b._rank_within_parent3546)); 
}
    }SW_Sort_TD_2561917_order; 

    int nrow1 = tbl_Window_TD_3229898_output.getNumRow();
    std::vector<SW_Sort_TD_2561917Row> rows;
    for (int i = 0; i < nrow1; i++) {
        int64_t _total_sum3544 = tbl_Window_TD_3229898_output.getInt64(i, 0);
        std::array<char, TPCDS_READ_MAX + 1> _i_category3554 = tbl_Window_TD_3229898_output.getcharN<char, TPCDS_READ_MAX +1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _i_class3555 = tbl_Window_TD_3229898_output.getcharN<char, TPCDS_READ_MAX +1>(i, 2);
        int32_t _lochierarchy3545 = tbl_Window_TD_3229898_output.getInt32(i, 3);
        int32_t __w13568 = tbl_Window_TD_3229898_output.getInt32(i, 4);
        int64_t __w23569 = tbl_Window_TD_3229898_output.getInt64(i, 5);
        int64_t __w33570 = tbl_Window_TD_3229898_output.getInt64(i, 6);
        int32_t _rank_within_parent3546 = tbl_Window_TD_3229898_output.getInt32(i, 7);
        SW_Sort_TD_2561917Row t = {_total_sum3544,std::string(_i_category3554.data()),std::string(_i_class3555.data()),_lochierarchy3545,__w13568,__w23569,__w33570,_rank_within_parent3546};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2561917_order);
    int r = 0;
    for (auto& it : rows) {
        tbl_Sort_TD_2561917_output.setInt64(r, 0, it._total_sum3544);
        std::array<char, TPCDS_READ_MAX + 1> _i_category3554{};
        memcpy(_i_category3554.data(), (it._i_category3554).data(), (it._i_category3554).length());
        tbl_Sort_TD_2561917_output.setcharN<char, TPCDS_READ_MAX +1>(r, 1, _i_category3554);
        std::array<char, TPCDS_READ_MAX + 1> _i_class3555{};
        memcpy(_i_class3555.data(), (it._i_class3555).data(), (it._i_class3555).length());
        tbl_Sort_TD_2561917_output.setcharN<char, TPCDS_READ_MAX +1>(r, 2, _i_class3555);
        tbl_Sort_TD_2561917_output.setInt32(r, 3, it._lochierarchy3545);
        tbl_Sort_TD_2561917_output.setInt32(r, 4, it._rank_within_parent3546);
        ++r;
    }
    tbl_Sort_TD_2561917_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2561917_output #Row: " << tbl_Sort_TD_2561917_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1613268(Table &tbl_Sort_TD_2561917_output, Table &tbl_LocalLimit_TD_1613268_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(total_sum#3544, i_category#3554, i_class#3555, lochierarchy#3545, rank_within_parent#3546)
    // Output: ListBuffer(total_sum#3544, i_category#3554, i_class#3555, lochierarchy#3545, rank_within_parent#3546)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        tbl_LocalLimit_TD_1613268_output.setInt64(r, 0, tbl_Sort_TD_2561917_output.getInt64(i, 0));
        std::array<char, TPCDS_READ_MAX + 1> _i_category3554_n = tbl_Sort_TD_2561917_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_LocalLimit_TD_1613268_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category3554_n);
        std::array<char, TPCDS_READ_MAX + 1> _i_class3555_n = tbl_Sort_TD_2561917_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_LocalLimit_TD_1613268_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_class3555_n);
        tbl_LocalLimit_TD_1613268_output.setInt32(r, 3, tbl_Sort_TD_2561917_output.getInt32(i, 3));
        tbl_LocalLimit_TD_1613268_output.setInt32(r, 4, tbl_Sort_TD_2561917_output.getInt32(i, 4));
        r++;
    }
    tbl_LocalLimit_TD_1613268_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1613268_output #Row: " << tbl_LocalLimit_TD_1613268_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0847510(Table &tbl_LocalLimit_TD_1613268_output, Table &tbl_GlobalLimit_TD_0847510_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(total_sum#3544, i_category#3554, i_class#3555, lochierarchy#3545, rank_within_parent#3546)
    // Output: ListBuffer(total_sum#3544, i_category#3554, i_class#3555, lochierarchy#3545, rank_within_parent#3546)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        tbl_GlobalLimit_TD_0847510_output.setInt64(r, 0, tbl_LocalLimit_TD_1613268_output.getInt64(i, 0));
        std::array<char, TPCDS_READ_MAX + 1> _i_category3554_n = tbl_LocalLimit_TD_1613268_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        tbl_GlobalLimit_TD_0847510_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_category3554_n);
        std::array<char, TPCDS_READ_MAX + 1> _i_class3555_n = tbl_LocalLimit_TD_1613268_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        tbl_GlobalLimit_TD_0847510_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _i_class3555_n);
        tbl_GlobalLimit_TD_0847510_output.setInt32(r, 3, tbl_LocalLimit_TD_1613268_output.getInt32(i, 3));
        tbl_GlobalLimit_TD_0847510_output.setInt32(r, 4, tbl_LocalLimit_TD_1613268_output.getInt32(i, 4));
        r++;
    }
    tbl_GlobalLimit_TD_0847510_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0847510_output #Row: " << tbl_GlobalLimit_TD_0847510_output.getNumRow() << std::endl;
}

