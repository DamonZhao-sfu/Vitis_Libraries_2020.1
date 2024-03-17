#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_10761658(Table &tbl_SerializeFromObject_TD_11660686_input, Table &tbl_Filter_TD_10761658_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_month_seq#3651) AND ((d_month_seq#3651 >= 1200) AND (d_month_seq#3651 <= 1211))) AND isnotnull(d_date_sk#3648)))
    // Input: ListBuffer(d_date_sk#3648, d_date#3650, d_month_seq#3651)
    // Output: ListBuffer(d_date_sk#3648, d_date#3650)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11660686_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_month_seq3651 = tbl_SerializeFromObject_TD_11660686_input.getInt32(i, 2);
        int32_t _d_date_sk3648 = tbl_SerializeFromObject_TD_11660686_input.getInt32(i, 0);
        if (((_d_month_seq3651!= 0) && ((_d_month_seq3651 >= 1200) && (_d_month_seq3651 <= 1211))) && (_d_date_sk3648!= 0)) {
            int32_t _d_date_sk3648_t = tbl_SerializeFromObject_TD_11660686_input.getInt32(i, 0);
            tbl_Filter_TD_10761658_output.setInt32(r, 0, _d_date_sk3648_t);
            int32_t _d_date3650_t = tbl_SerializeFromObject_TD_11660686_input.getInt32(i, 1);
            tbl_Filter_TD_10761658_output.setInt32(r, 1, _d_date3650_t);
            r++;
        }
    }
    tbl_Filter_TD_10761658_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10761658_output #Row: " << tbl_Filter_TD_10761658_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10836943(Table &tbl_SerializeFromObject_TD_11858691_input, Table &tbl_Filter_TD_10836943_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ss_item_sk#1208) AND isnotnull(ss_sold_date_sk#1206)))
    // Input: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_sales_price#1219)
    // Output: ListBuffer(ss_sold_date_sk#1206, ss_item_sk#1208, ss_sales_price#1219)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11858691_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_item_sk1208 = tbl_SerializeFromObject_TD_11858691_input.getInt32(i, 1);
        int32_t _ss_sold_date_sk1206 = tbl_SerializeFromObject_TD_11858691_input.getInt32(i, 0);
        if ((_ss_item_sk1208!= 0) && (_ss_sold_date_sk1206!= 0)) {
            int32_t _ss_sold_date_sk1206_t = tbl_SerializeFromObject_TD_11858691_input.getInt32(i, 0);
            tbl_Filter_TD_10836943_output.setInt32(r, 0, _ss_sold_date_sk1206_t);
            int32_t _ss_item_sk1208_t = tbl_SerializeFromObject_TD_11858691_input.getInt32(i, 1);
            tbl_Filter_TD_10836943_output.setInt32(r, 1, _ss_item_sk1208_t);
            int64_t _ss_sales_price1219_t = tbl_SerializeFromObject_TD_11858691_input.getInt64(i, 2);
            tbl_Filter_TD_10836943_output.setInt64(r, 2, _ss_sales_price1219_t);
            r++;
        }
    }
    tbl_Filter_TD_10836943_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10836943_output #Row: " << tbl_Filter_TD_10836943_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10732262(Table &tbl_SerializeFromObject_TD_11356790_input, Table &tbl_Filter_TD_10732262_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_month_seq#123) AND ((d_month_seq#123 >= 1200) AND (d_month_seq#123 <= 1211))) AND isnotnull(d_date_sk#120)))
    // Input: ListBuffer(d_date_sk#120, d_date#122, d_month_seq#123)
    // Output: ListBuffer(d_date_sk#120, d_date#122)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11356790_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_month_seq123 = tbl_SerializeFromObject_TD_11356790_input.getInt32(i, 2);
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_11356790_input.getInt32(i, 0);
        if (((_d_month_seq123!= 0) && ((_d_month_seq123 >= 1200) && (_d_month_seq123 <= 1211))) && (_d_date_sk120!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_11356790_input.getInt32(i, 0);
            tbl_Filter_TD_10732262_output.setInt32(r, 0, _d_date_sk120_t);
            int32_t _d_date122_t = tbl_SerializeFromObject_TD_11356790_input.getInt32(i, 1);
            tbl_Filter_TD_10732262_output.setInt32(r, 1, _d_date122_t);
            r++;
        }
    }
    tbl_Filter_TD_10732262_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10732262_output #Row: " << tbl_Filter_TD_10732262_output.getNumRow() << std::endl;
}

void SW_Filter_TD_10345630(Table &tbl_SerializeFromObject_TD_11561049_input, Table &tbl_Filter_TD_10345630_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(ws_item_sk#732) AND isnotnull(ws_sold_date_sk#729)))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_sales_price#750)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_item_sk#732, ws_sales_price#750)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_11561049_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_item_sk732 = tbl_SerializeFromObject_TD_11561049_input.getInt32(i, 1);
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_11561049_input.getInt32(i, 0);
        if ((_ws_item_sk732!= 0) && (_ws_sold_date_sk729!= 0)) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_11561049_input.getInt32(i, 0);
            tbl_Filter_TD_10345630_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int32_t _ws_item_sk732_t = tbl_SerializeFromObject_TD_11561049_input.getInt32(i, 1);
            tbl_Filter_TD_10345630_output.setInt32(r, 1, _ws_item_sk732_t);
            int64_t _ws_sales_price750_t = tbl_SerializeFromObject_TD_11561049_input.getInt64(i, 2);
            tbl_Filter_TD_10345630_output.setInt64(r, 2, _ws_sales_price750_t);
            r++;
        }
    }
    tbl_Filter_TD_10345630_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_10345630_output #Row: " << tbl_Filter_TD_10345630_output.getNumRow() << std::endl;
}



struct SW_Aggregate_TD_8426435_key {
    int32_t _ss_item_sk1208;
    int32_t _d_date3650;
    bool operator==(const SW_Aggregate_TD_8426435_key& other) const { return (_ss_item_sk1208 == other._ss_item_sk1208) && (_d_date3650 == other._d_date3650); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_8426435_key> {
    std::size_t operator() (const SW_Aggregate_TD_8426435_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ss_item_sk1208)) + (hash<int32_t>()(k._d_date3650));
    }
};
}
struct SW_Aggregate_TD_8426435_payload {
    int32_t _item_sk3646;
    int64_t __w03681_sum_0;
};
void SW_Aggregate_TD_8426435(Table &tbl_JOIN_INNER_TD_9238506_output, Table &tbl_Aggregate_TD_8426435_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(ss_item_sk#1208, d_date#3650, ss_item_sk#1208 AS item_sk#3646, MakeDecimal(sum(UnscaledValue(ss_sales_price#1219)),17,2) AS _w0#3681)
    // Input: ListBuffer(ss_item_sk#1208, ss_sales_price#1219, d_date#3650)
    // Output: ListBuffer(item_sk#3646, d_date#3650, _w0#3681, ss_item_sk#1208)
    std::unordered_map<SW_Aggregate_TD_8426435_key, SW_Aggregate_TD_8426435_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_9238506_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ss_item_sk1208 = tbl_JOIN_INNER_TD_9238506_output.getInt32(i, 0);
        int64_t _ss_sales_price1219 = tbl_JOIN_INNER_TD_9238506_output.getInt64(i, 1);
        int32_t _d_date3650 = tbl_JOIN_INNER_TD_9238506_output.getInt32(i, 2);
        SW_Aggregate_TD_8426435_key k{_ss_item_sk1208, _d_date3650};
        int32_t _item_sk3646 = _ss_item_sk1208;
        int64_t __w03681_sum_0 = _ss_sales_price1219;
        SW_Aggregate_TD_8426435_payload p{_item_sk3646, __w03681_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second).__w03681_sum_0 + __w03681_sum_0;
            p.__w03681_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        tbl_Aggregate_TD_8426435_output.setInt32(r, 3, (it.first)._ss_item_sk1208);
        tbl_Aggregate_TD_8426435_output.setInt32(r, 1, (it.first)._d_date3650);
        tbl_Aggregate_TD_8426435_output.setInt32(r, 0, (it.second)._item_sk3646);
        int64_t __w03681 = (it.second).__w03681_sum_0;
        tbl_Aggregate_TD_8426435_output.setInt64(r, 2, __w03681);
        ++r;
    }
    tbl_Aggregate_TD_8426435_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_8426435_output #Row: " << tbl_Aggregate_TD_8426435_output.getNumRow() << std::endl;
}

struct SW_Aggregate_TD_8282744_key {
    int32_t _ws_item_sk732;
    int32_t _d_date122;
    bool operator==(const SW_Aggregate_TD_8282744_key& other) const { return (_ws_item_sk732 == other._ws_item_sk732) && (_d_date122 == other._d_date122); }
};
namespace std {
template <>
struct hash<SW_Aggregate_TD_8282744_key> {
    std::size_t operator() (const SW_Aggregate_TD_8282744_key& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ws_item_sk732)) + (hash<int32_t>()(k._d_date122));
    }
};
}
struct SW_Aggregate_TD_8282744_payload {
    int32_t _item_sk3644;
    int64_t __w03680_sum_0;
};
void SW_Aggregate_TD_8282744(Table &tbl_JOIN_INNER_TD_9717571_output, Table &tbl_Aggregate_TD_8282744_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(ws_item_sk#732, d_date#122, ws_item_sk#732 AS item_sk#3644, MakeDecimal(sum(UnscaledValue(ws_sales_price#750)),17,2) AS _w0#3680)
    // Input: ListBuffer(ws_item_sk#732, ws_sales_price#750, d_date#122)
    // Output: ListBuffer(item_sk#3644, d_date#122, _w0#3680, ws_item_sk#732)
    std::unordered_map<SW_Aggregate_TD_8282744_key, SW_Aggregate_TD_8282744_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_9717571_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_item_sk732 = tbl_JOIN_INNER_TD_9717571_output.getInt32(i, 0);
        int64_t _ws_sales_price750 = tbl_JOIN_INNER_TD_9717571_output.getInt64(i, 1);
        int32_t _d_date122 = tbl_JOIN_INNER_TD_9717571_output.getInt32(i, 2);
        SW_Aggregate_TD_8282744_key k{_ws_item_sk732, _d_date122};
        int32_t _item_sk3644 = _ws_item_sk732;
        int64_t __w03680_sum_0 = _ws_sales_price750;
        SW_Aggregate_TD_8282744_payload p{_item_sk3644, __w03680_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second).__w03680_sum_0 + __w03680_sum_0;
            p.__w03680_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        tbl_Aggregate_TD_8282744_output.setInt32(r, 3, (it.first)._ws_item_sk732);
        tbl_Aggregate_TD_8282744_output.setInt32(r, 1, (it.first)._d_date122);
        tbl_Aggregate_TD_8282744_output.setInt32(r, 0, (it.second)._item_sk3644);
        int64_t __w03680 = (it.second).__w03680_sum_0;
        tbl_Aggregate_TD_8282744_output.setInt64(r, 2, __w03680);
        ++r;
    }
    tbl_Aggregate_TD_8282744_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_8282744_output #Row: " << tbl_Aggregate_TD_8282744_output.getNumRow() << std::endl;
}

void SW_Window_TD_7799101(Table &tbl_Aggregate_TD_8426435_output, Table &tbl_Window_TD_7799101_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Window
    // Operation: ListBuffer(sum(_w0#3681) windowspecdefinition(ss_item_sk#1208, d_date#3650 ASC NULLS FIRST, specifiedwindowframe(RowFrame, unboundedpreceding$(), currentrow$())) AS cume_sales#3647)
    // Input: ListBuffer(item_sk#3646, d_date#3650, _w0#3681, ss_item_sk#1208)
    // Output: ListBuffer(item_sk#3646, d_date#3650, _w0#3681, ss_item_sk#1208, cume_sales#3647)
    struct SW_Window_TD_7799101Row {
        int32_t _item_sk3646;
        int32_t _d_date3650;
        int64_t __w03681;
        int32_t _ss_item_sk1208;
    }; 

    int nrow = tbl_Aggregate_TD_8426435_output.getNumRow();
    std::vector<SW_Window_TD_7799101Row> rows0;
    int r = 0;
    for (int i = 0; i < nrow; i++) {
        int32_t _item_sk3646 = tbl_Aggregate_TD_8426435_output.getInt32(i, 0);
        tbl_Window_TD_7799101_output.setInt32(r, 0,_item_sk3646);
        int32_t _d_date3650 = tbl_Aggregate_TD_8426435_output.getInt32(i, 1);
        tbl_Window_TD_7799101_output.setInt32(r, 1,_d_date3650);
        int64_t __w03681 = tbl_Aggregate_TD_8426435_output.getInt64(i, 2);
        tbl_Window_TD_7799101_output.setInt64(r, 2,__w03681);
        int32_t _ss_item_sk1208 = tbl_Aggregate_TD_8426435_output.getInt32(i, 3);
        tbl_Window_TD_7799101_output.setInt32(r, 3,_ss_item_sk1208);
        r++;
        SW_Window_TD_7799101Row t = {_item_sk3646,_d_date3650,__w03681,_ss_item_sk1208};
        rows0.push_back(t);
    }
    struct {
        bool operator()(const SW_Window_TD_7799101Row& a, const SW_Window_TD_7799101Row& b) const { return 
(a._ss_item_sk1208 < b._ss_item_sk1208) || 
 ((a._ss_item_sk1208 == b._ss_item_sk1208) && (a._d_date3650 < b._d_date3650)); 
}
    }SW_Window_TD_7799101_order0; 

    std::sort(rows0.begin(), rows0.end(), SW_Window_TD_7799101_order0);
    int64_t sum0 = 0;
    int32_t current_ss_item_sk12080 = std::numeric_limits<int32_t>::min();
    for (auto& it : rows0) {
        if (current_ss_item_sk12080 != it._ss_item_sk1208) {
            sum0 = 0;
            current_ss_item_sk12080 = it._ss_item_sk1208;
        }
        sum0 += it.__w03681;
        tbl_Window_TD_7799101_output.setInt64(r, 4, sum0 );
    }
    tbl_Window_TD_7799101_output.setNumRow(r);
    std::cout << "tbl_Window_TD_7799101_output #Row: " << tbl_Window_TD_7799101_output.getNumRow() << std::endl;
}

void SW_Window_TD_7855870(Table &tbl_Aggregate_TD_8282744_output, Table &tbl_Window_TD_7855870_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Window
    // Operation: ListBuffer(sum(_w0#3680) windowspecdefinition(ws_item_sk#732, d_date#122 ASC NULLS FIRST, specifiedwindowframe(RowFrame, unboundedpreceding$(), currentrow$())) AS cume_sales#3645)
    // Input: ListBuffer(item_sk#3644, d_date#122, _w0#3680, ws_item_sk#732)
    // Output: ListBuffer(item_sk#3644, d_date#122, _w0#3680, ws_item_sk#732, cume_sales#3645)
    struct SW_Window_TD_7855870Row {
        int32_t _item_sk3644;
        int32_t _d_date122;
        int64_t __w03680;
        int32_t _ws_item_sk732;
    }; 

    int nrow = tbl_Aggregate_TD_8282744_output.getNumRow();
    std::vector<SW_Window_TD_7855870Row> rows0;
    int r = 0;
    for (int i = 0; i < nrow; i++) {
        int32_t _item_sk3644 = tbl_Aggregate_TD_8282744_output.getInt32(i, 0);
        tbl_Window_TD_7855870_output.setInt32(r, 0,_item_sk3644);
        int32_t _d_date122 = tbl_Aggregate_TD_8282744_output.getInt32(i, 1);
        tbl_Window_TD_7855870_output.setInt32(r, 1,_d_date122);
        int64_t __w03680 = tbl_Aggregate_TD_8282744_output.getInt64(i, 2);
        tbl_Window_TD_7855870_output.setInt64(r, 2,__w03680);
        int32_t _ws_item_sk732 = tbl_Aggregate_TD_8282744_output.getInt32(i, 3);
        tbl_Window_TD_7855870_output.setInt32(r, 3,_ws_item_sk732);
        r++;
        SW_Window_TD_7855870Row t = {_item_sk3644,_d_date122,__w03680,_ws_item_sk732};
        rows0.push_back(t);
    }
    struct {
        bool operator()(const SW_Window_TD_7855870Row& a, const SW_Window_TD_7855870Row& b) const { return 
(a._ws_item_sk732 < b._ws_item_sk732) || 
 ((a._ws_item_sk732 == b._ws_item_sk732) && (a._d_date122 < b._d_date122)); 
}
    }SW_Window_TD_7855870_order0; 

    std::sort(rows0.begin(), rows0.end(), SW_Window_TD_7855870_order0);
    int64_t sum0 = 0;
    int32_t current_ws_item_sk7320 = std::numeric_limits<int32_t>::min();
    for (auto& it : rows0) {
        if (current_ws_item_sk7320 != it._ws_item_sk732) {
            sum0 = 0;
            current_ws_item_sk7320 = it._ws_item_sk732;
        }
        sum0 += it.__w03680;
        tbl_Window_TD_7855870_output.setInt64(r, 4, sum0 );
    }
    tbl_Window_TD_7855870_output.setNumRow(r);
    std::cout << "tbl_Window_TD_7855870_output #Row: " << tbl_Window_TD_7855870_output.getNumRow() << std::endl;
}


void SW_Project_TD_5156260(Table &tbl_JOIN_FULLOUTER_TD_6746405_output, Table &tbl_Project_TD_5156260_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(CASE WHEN isnotnull(item_sk#3644) THEN item_sk#3644 ELSE item_sk#3646 END AS item_sk#3638, CASE WHEN isnotnull(d_date#122) THEN d_date#122 ELSE d_date#3650 END AS d_date#3639, cume_sales#3645 AS web_sales#3640, cume_sales#3647 AS store_sales#3641)
    // Input: ListBuffer(item_sk#3644, item_sk#3646, d_date#122, d_date#3650, cume_sales#3645, cume_sales#3647)
    // Output: ListBuffer(item_sk#3638, d_date#3639, web_sales#3640, store_sales#3641)
    int nrow1 = tbl_JOIN_FULLOUTER_TD_6746405_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _item_sk3644 = tbl_JOIN_FULLOUTER_TD_6746405_output.getInt32(i, 0);
        int32_t _item_sk3646 = tbl_JOIN_FULLOUTER_TD_6746405_output.getInt32(i, 1);
        int32_t _d_date122 = tbl_JOIN_FULLOUTER_TD_6746405_output.getInt32(i, 2);
        int32_t _d_date3650 = tbl_JOIN_FULLOUTER_TD_6746405_output.getInt32(i, 3);
        int64_t _cume_sales3645 = tbl_JOIN_FULLOUTER_TD_6746405_output.getInt64(i, 4);
        int64_t _cume_sales3647 = tbl_JOIN_FULLOUTER_TD_6746405_output.getInt64(i, 5);
        int32_t _item_sk3638 = _item_sk3644 ? _item_sk3644 : _item_sk3646;
        tbl_Project_TD_5156260_output.setInt32(i, 0, _item_sk3638);
        int32_t _d_date3639 = _d_date122 ? _d_date122 : _d_date3650;
        tbl_Project_TD_5156260_output.setInt32(i, 1, _d_date3639);
        int64_t _web_sales3640 = _cume_sales3645;
        tbl_Project_TD_5156260_output.setInt64(i, 2, _web_sales3640);
        int64_t _store_sales3641 = _cume_sales3647;
        tbl_Project_TD_5156260_output.setInt64(i, 3, _store_sales3641);
    }
    tbl_Project_TD_5156260_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_5156260_output #Row: " << tbl_Project_TD_5156260_output.getNumRow() << std::endl;
}

void SW_Window_TD_4307433(Table &tbl_Project_TD_5156260_output, Table &tbl_Window_TD_4307433_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Window
    // Operation: ListBuffer(max(web_sales#3640) windowspecdefinition(item_sk#3638, d_date#3639 ASC NULLS FIRST, specifiedwindowframe(RowFrame, unboundedpreceding$(), currentrow$())) AS web_cumulative#3642, max(store_sales#3641) windowspecdefinition(item_sk#3638, d_date#3639 ASC NULLS FIRST, specifiedwindowframe(RowFrame, unboundedpreceding$(), currentrow$())) AS store_cumulative#3643)
    // Input: ListBuffer(item_sk#3638, d_date#3639, web_sales#3640, store_sales#3641)
    // Output: ListBuffer(item_sk#3638, d_date#3639, web_sales#3640, store_sales#3641, web_cumulative#3642, store_cumulative#3643)
    struct SW_Window_TD_4307433Row {
        int32_t _item_sk3638;
        int32_t _d_date3639;
        int64_t _web_sales3640;
        int64_t _store_sales3641;
    }; 

    int nrow = tbl_Project_TD_5156260_output.getNumRow();
    std::vector<SW_Window_TD_4307433Row> rows0;
    std::vector<SW_Window_TD_4307433Row> rows1;
    int r = 0;
    for (int i = 0; i < nrow; i++) {
        int32_t _item_sk3638 = tbl_Project_TD_5156260_output.getInt32(i, 0);
        tbl_Window_TD_4307433_output.setInt32(r, 0,_item_sk3638);
        int32_t _d_date3639 = tbl_Project_TD_5156260_output.getInt32(i, 1);
        tbl_Window_TD_4307433_output.setInt32(r, 1,_d_date3639);
        int64_t _web_sales3640 = tbl_Project_TD_5156260_output.getInt64(i, 2);
        tbl_Window_TD_4307433_output.setInt64(r, 2,_web_sales3640);
        int64_t _store_sales3641 = tbl_Project_TD_5156260_output.getInt64(i, 3);
        tbl_Window_TD_4307433_output.setInt64(r, 3,_store_sales3641);
        r++;
        SW_Window_TD_4307433Row t = {_item_sk3638,_d_date3639,_web_sales3640,_store_sales3641};
        rows0.push_back(t);
        rows1.push_back(t);
    }
    struct {
        bool operator()(const SW_Window_TD_4307433Row& a, const SW_Window_TD_4307433Row& b) const { return 
(a._item_sk3638 < b._item_sk3638) || 
 ((a._item_sk3638 == b._item_sk3638) && (a._d_date3639 < b._d_date3639)); 
}
    }SW_Window_TD_4307433_order0; 

    std::sort(rows0.begin(), rows0.end(), SW_Window_TD_4307433_order0);
    int64_t max0 = std::numeric_limits<int>::min();
    int32_t current_item_sk36380 = std::numeric_limits<int32_t>::min();
    for (auto& it : rows0) {
        if (current_item_sk36380 != it._item_sk3638) {
            max0 = std::numeric_limits<int>::min();
            current_item_sk36380 = it._item_sk3638;
        }
        tbl_Window_TD_4307433_output.setInt64(r, 4, max0 < it._web_sales3640 ? it._web_sales3640 : max0);
    }
    struct {
        bool operator()(const SW_Window_TD_4307433Row& a, const SW_Window_TD_4307433Row& b) const { return 
(a._item_sk3638 < b._item_sk3638) || 
 ((a._item_sk3638 == b._item_sk3638) && (a._d_date3639 < b._d_date3639)); 
}
    }SW_Window_TD_4307433_order1; 

    std::sort(rows1.begin(), rows1.end(), SW_Window_TD_4307433_order1);
    int64_t max1 = std::numeric_limits<int>::min();
    int32_t current_item_sk36381 = std::numeric_limits<int32_t>::min();
    for (auto& it : rows1) {
        if (current_item_sk36381 != it._item_sk3638) {
            max1 = std::numeric_limits<int>::min();
            current_item_sk36381 = it._item_sk3638;
        }
        tbl_Window_TD_4307433_output.setInt64(r, 4, max1 < it._store_sales3641 ? it._store_sales3641 : max1);
    }
    tbl_Window_TD_4307433_output.setNumRow(r);
    std::cout << "tbl_Window_TD_4307433_output #Row: " << tbl_Window_TD_4307433_output.getNumRow() << std::endl;
}

void SW_Filter_TD_3873404(Table &tbl_Window_TD_4307433_output, Table &tbl_Filter_TD_3873404_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(web_cumulative#3642) AND isnotnull(store_cumulative#3643)) AND (web_cumulative#3642 > store_cumulative#3643)))
    // Input: ListBuffer(item_sk#3638, d_date#3639, web_sales#3640, store_sales#3641, web_cumulative#3642, store_cumulative#3643)
    // Output: ListBuffer(item_sk#3638, d_date#3639, web_sales#3640, store_sales#3641, web_cumulative#3642, store_cumulative#3643)
    int r = 0;
    int nrow1 = tbl_Window_TD_4307433_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _web_cumulative3642 = tbl_Window_TD_4307433_output.getInt64(i, 4);
        int64_t _store_cumulative3643 = tbl_Window_TD_4307433_output.getInt64(i, 5);
        if (((_web_cumulative3642!= 0) && (_store_cumulative3643!= 0)) && (_web_cumulative3642 > _store_cumulative3643)) {
            int32_t _item_sk3638_t = tbl_Window_TD_4307433_output.getInt32(i, 0);
            tbl_Filter_TD_3873404_output.setInt32(r, 0, _item_sk3638_t);
            int32_t _d_date3639_t = tbl_Window_TD_4307433_output.getInt32(i, 1);
            tbl_Filter_TD_3873404_output.setInt32(r, 1, _d_date3639_t);
            int64_t _web_sales3640_t = tbl_Window_TD_4307433_output.getInt64(i, 2);
            tbl_Filter_TD_3873404_output.setInt64(r, 2, _web_sales3640_t);
            int64_t _store_sales3641_t = tbl_Window_TD_4307433_output.getInt64(i, 3);
            tbl_Filter_TD_3873404_output.setInt64(r, 3, _store_sales3641_t);
            int64_t _web_cumulative3642_t = tbl_Window_TD_4307433_output.getInt64(i, 4);
            tbl_Filter_TD_3873404_output.setInt64(r, 4, _web_cumulative3642_t);
            int64_t _store_cumulative3643_t = tbl_Window_TD_4307433_output.getInt64(i, 5);
            tbl_Filter_TD_3873404_output.setInt64(r, 5, _store_cumulative3643_t);
            r++;
        }
    }
    tbl_Filter_TD_3873404_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_3873404_output #Row: " << tbl_Filter_TD_3873404_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2689516(Table &tbl_Filter_TD_3873404_output, Table &tbl_Sort_TD_2689516_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(item_sk#3638 ASC NULLS FIRST, d_date#3639 ASC NULLS FIRST)
    // Input: ListBuffer(item_sk#3638, d_date#3639, web_sales#3640, store_sales#3641, web_cumulative#3642, store_cumulative#3643)
    // Output: ListBuffer(item_sk#3638, d_date#3639, web_sales#3640, store_sales#3641, web_cumulative#3642, store_cumulative#3643)
    struct SW_Sort_TD_2689516Row {
        int32_t _item_sk3638;
        int32_t _d_date3639;
        int64_t _web_sales3640;
        int64_t _store_sales3641;
        int64_t _web_cumulative3642;
        int64_t _store_cumulative3643;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2689516Row& a, const SW_Sort_TD_2689516Row& b) const { return 
 (a._item_sk3638 < b._item_sk3638) || 
 ((a._item_sk3638 == b._item_sk3638) && (a._d_date3639 < b._d_date3639)); 
}
    }SW_Sort_TD_2689516_order; 

    int nrow1 = tbl_Filter_TD_3873404_output.getNumRow();
    std::vector<SW_Sort_TD_2689516Row> rows;
    for (int i = 0; i < nrow1; i++) {
        int32_t _item_sk3638 = tbl_Filter_TD_3873404_output.getInt32(i, 0);
        int32_t _d_date3639 = tbl_Filter_TD_3873404_output.getInt32(i, 1);
        int64_t _web_sales3640 = tbl_Filter_TD_3873404_output.getInt64(i, 2);
        int64_t _store_sales3641 = tbl_Filter_TD_3873404_output.getInt64(i, 3);
        int64_t _web_cumulative3642 = tbl_Filter_TD_3873404_output.getInt64(i, 4);
        int64_t _store_cumulative3643 = tbl_Filter_TD_3873404_output.getInt64(i, 5);
        SW_Sort_TD_2689516Row t = {_item_sk3638,_d_date3639,_web_sales3640,_store_sales3641,_web_cumulative3642,_store_cumulative3643};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2689516_order);
    int r = 0;
    for (auto& it : rows) {
        tbl_Sort_TD_2689516_output.setInt32(r, 0, it._item_sk3638);
        tbl_Sort_TD_2689516_output.setInt32(r, 1, it._d_date3639);
        tbl_Sort_TD_2689516_output.setInt64(r, 2, it._web_sales3640);
        tbl_Sort_TD_2689516_output.setInt64(r, 3, it._store_sales3641);
        tbl_Sort_TD_2689516_output.setInt64(r, 4, it._web_cumulative3642);
        tbl_Sort_TD_2689516_output.setInt64(r, 5, it._store_cumulative3643);
        ++r;
    }
    tbl_Sort_TD_2689516_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2689516_output #Row: " << tbl_Sort_TD_2689516_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_178420(Table &tbl_Sort_TD_2689516_output, Table &tbl_LocalLimit_TD_178420_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(item_sk#3638, d_date#3639, web_sales#3640, store_sales#3641, web_cumulative#3642, store_cumulative#3643)
    // Output: ListBuffer(item_sk#3638, d_date#3639, web_sales#3640, store_sales#3641, web_cumulative#3642, store_cumulative#3643)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        tbl_LocalLimit_TD_178420_output.setInt32(r, 0, tbl_Sort_TD_2689516_output.getInt32(i, 0));
        tbl_LocalLimit_TD_178420_output.setInt32(r, 1, tbl_Sort_TD_2689516_output.getInt32(i, 1));
        tbl_LocalLimit_TD_178420_output.setInt64(r, 2, tbl_Sort_TD_2689516_output.getInt64(i, 2));
        tbl_LocalLimit_TD_178420_output.setInt64(r, 3, tbl_Sort_TD_2689516_output.getInt64(i, 3));
        tbl_LocalLimit_TD_178420_output.setInt64(r, 4, tbl_Sort_TD_2689516_output.getInt64(i, 4));
        tbl_LocalLimit_TD_178420_output.setInt64(r, 5, tbl_Sort_TD_2689516_output.getInt64(i, 5));
        r++;
    }
    tbl_LocalLimit_TD_178420_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_178420_output #Row: " << tbl_LocalLimit_TD_178420_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_01307(Table &tbl_LocalLimit_TD_178420_output, Table &tbl_GlobalLimit_TD_01307_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(item_sk#3638, d_date#3639, web_sales#3640, store_sales#3641, web_cumulative#3642, store_cumulative#3643)
    // Output: ListBuffer(item_sk#3638, d_date#3639, web_sales#3640, store_sales#3641, web_cumulative#3642, store_cumulative#3643)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        tbl_GlobalLimit_TD_01307_output.setInt32(r, 0, tbl_LocalLimit_TD_178420_output.getInt32(i, 0));
        tbl_GlobalLimit_TD_01307_output.setInt32(r, 1, tbl_LocalLimit_TD_178420_output.getInt32(i, 1));
        tbl_GlobalLimit_TD_01307_output.setInt64(r, 2, tbl_LocalLimit_TD_178420_output.getInt64(i, 2));
        tbl_GlobalLimit_TD_01307_output.setInt64(r, 3, tbl_LocalLimit_TD_178420_output.getInt64(i, 3));
        tbl_GlobalLimit_TD_01307_output.setInt64(r, 4, tbl_LocalLimit_TD_178420_output.getInt64(i, 4));
        tbl_GlobalLimit_TD_01307_output.setInt64(r, 5, tbl_LocalLimit_TD_178420_output.getInt64(i, 5));
        r++;
    }
    tbl_GlobalLimit_TD_01307_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_01307_output #Row: " << tbl_GlobalLimit_TD_01307_output.getNumRow() << std::endl;
}

