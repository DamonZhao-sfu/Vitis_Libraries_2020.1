#include <regex> 
#include <stdint.h> 

void SW_Filter_TD_393(Table &tbl_SerializeFromObject_TD_4563_input, Table &tbl_Filter_TD_393_output) {
    // StringRowIDSubstitution: true StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((((l_shipmode#91 IN (TRUCK,MAIL) AND (l_commitdate#88 < l_receiptdate#89)) AND (l_shipdate#87 < l_commitdate#88)) AND (l_receiptdate#89 >= 19970101)) AND (l_receiptdate#89 < 19980101)))
    // Input: ListBuffer(l_orderkey#77, l_shipmode#91, l_commitdate#88, l_receiptdate#89, l_shipdate#87)
    // Output: ListBuffer(l_orderkey#77, l_shipmode#91)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_4563_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_MAXAGG_LEN + 1> _l_shipmode91 = tbl_SerializeFromObject_TD_4563_input.getcharN<char, TPCH_READ_MAXAGG_LEN + 1>(i, 1);
        int32_t _l_commitdate88 = tbl_SerializeFromObject_TD_4563_input.getInt32(i, 2);
        int32_t _l_receiptdate89 = tbl_SerializeFromObject_TD_4563_input.getInt32(i, 3);
        int32_t _l_shipdate87 = tbl_SerializeFromObject_TD_4563_input.getInt32(i, 4);
        auto reuse_col_str_387 = std::string(_l_shipmode91.data());
        if ((((((reuse_col_str_387 == "TRUCK") || (reuse_col_str_387 == "MAIL") || (0)) && (_l_commitdate88 < _l_receiptdate89)) && (_l_shipdate87 < _l_commitdate88)) && (_l_receiptdate89 >= 19970101)) && (_l_receiptdate89 < 19980101)) {
            int32_t _l_orderkey77_t = tbl_SerializeFromObject_TD_4563_input.getInt32(i, 0);
            tbl_Filter_TD_393_output.setInt32(r, 0, _l_orderkey77_t);
            tbl_Filter_TD_393_output.setInt32(r, 1, i);
            r++;
        }
    }
    tbl_Filter_TD_393_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_393_output #Row: " << tbl_Filter_TD_393_output.getNumRow() << std::endl;
}


typedef std::string SW_Aggregate_TD_1399_key;
struct SW_Aggregate_TD_1399_payload {
    int64_t _high_line_count1318L_sum_0;
    int64_t _low_line_count1319L_sum_1;
};
void SW_Aggregate_TD_1399(Table *tbl_JOIN_INNER_TD_2407_output, Table &tbl_SerializeFromObject_TD_3642_input, Table &tbl_SerializeFromObject_TD_4563_input, Table &tbl_Aggregate_TD_1399_output, int hpTimes) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: true
    // Supported operation: Aggregate
    // Operation: ListBuffer(l_shipmode#91, sum(CASE WHEN ((o_orderpriority#212 = 1-URGENT) OR (o_orderpriority#212 = 2-HIGH)) THEN 1 ELSE 0 END) AS high_line_count#1318L, sum(CASE WHEN (NOT (o_orderpriority#212 = 1-URGENT) AND NOT (o_orderpriority#212 = 2-HIGH)) THEN 1 ELSE 0 END) AS low_line_count#1319L)
    // Input: ListBuffer(o_orderpriority#212, l_shipmode#91)
    // Output: ListBuffer(l_shipmode#91, high_line_count#1318L, low_line_count#1319L)
    std::unordered_map<SW_Aggregate_TD_1399_key, SW_Aggregate_TD_1399_payload> ht1;
for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
    int nrow1 = tbl_JOIN_INNER_TD_2407_output[p_idx].getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_MAXAGG_LEN + 1> _o_orderpriority212 = tbl_SerializeFromObject_TD_3642_input.getcharN<char, TPCH_READ_MAXAGG_LEN + 1>(tbl_JOIN_INNER_TD_2407_output[p_idx].getInt32(i, 0), 1);
        std::array<char, TPCH_READ_MAXAGG_LEN + 1> _l_shipmode91 = tbl_SerializeFromObject_TD_4563_input.getcharN<char, TPCH_READ_MAXAGG_LEN + 1>(tbl_JOIN_INNER_TD_2407_output[p_idx].getInt32(i, 1), 1);
        SW_Aggregate_TD_1399_key k = std::string(_l_shipmode91.data());
        int64_t _high_line_count1318L_sum_0 = ((std::string(_o_orderpriority212.data()) == "1-URGENT") || (std::string(_o_orderpriority212.data()) == "2-HIGH")) ? 1 : 0;
        int64_t _low_line_count1319L_sum_1 = (!((std::string(_o_orderpriority212.data()) == "1-URGENT")) && !((std::string(_o_orderpriority212.data()) == "2-HIGH"))) ? 1 : 0;
        SW_Aggregate_TD_1399_payload p{_high_line_count1318L_sum_0, _low_line_count1319L_sum_1};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._high_line_count1318L_sum_0 + _high_line_count1318L_sum_0;
            p._high_line_count1318L_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._low_line_count1319L_sum_1 + _low_line_count1319L_sum_1;
            p._low_line_count1319L_sum_1 = sum_1;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
}
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCH_READ_MAXAGG_LEN + 1> _l_shipmode91{};
        memcpy(_l_shipmode91.data(), (it.first).data(), (it.first).length());
        tbl_Aggregate_TD_1399_output.setcharN<char, TPCH_READ_MAXAGG_LEN + 1>(r, 0, _l_shipmode91);
        int64_t _high_line_count1318L = (it.second)._high_line_count1318L_sum_0;
        tbl_Aggregate_TD_1399_output.setInt64(r, 1, _high_line_count1318L);
        int64_t _low_line_count1319L = (it.second)._low_line_count1319L_sum_1;
        tbl_Aggregate_TD_1399_output.setInt64(r, 2, _low_line_count1319L);
        ++r;
    }
    tbl_Aggregate_TD_1399_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_1399_output #Row: " << tbl_Aggregate_TD_1399_output.getNumRow() << std::endl;
}

void SW_Sort_TD_0753(Table &tbl_Aggregate_TD_1399_output, Table &tbl_Sort_TD_0753_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(l_shipmode#91 ASC NULLS FIRST)
    // Input: ListBuffer(l_shipmode#91, high_line_count#1318L, low_line_count#1319L)
    // Output: ListBuffer(l_shipmode#91, high_line_count#1318L, low_line_count#1319L)
    struct SW_Sort_TD_0753Row {
        std::string _l_shipmode91;
        int64_t _high_line_count1318L;
        int64_t _low_line_count1319L;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_0753Row& a, const SW_Sort_TD_0753Row& b) const { return 
 (a._l_shipmode91 < b._l_shipmode91); 
}
    }SW_Sort_TD_0753_order; 

    int nrow1 = tbl_Aggregate_TD_1399_output.getNumRow();
    std::vector<SW_Sort_TD_0753Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_MAXAGG_LEN + 1> _l_shipmode91 = tbl_Aggregate_TD_1399_output.getcharN<char, TPCH_READ_MAXAGG_LEN +1>(i, 0);
        int64_t _high_line_count1318L = tbl_Aggregate_TD_1399_output.getInt64(i, 1);
        int64_t _low_line_count1319L = tbl_Aggregate_TD_1399_output.getInt64(i, 2);
        SW_Sort_TD_0753Row t = {std::string(_l_shipmode91.data()),_high_line_count1318L,_low_line_count1319L};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_0753_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCH_READ_MAXAGG_LEN + 1> _l_shipmode91{};
        memcpy(_l_shipmode91.data(), (it._l_shipmode91).data(), (it._l_shipmode91).length());
        tbl_Sort_TD_0753_output.setcharN<char, TPCH_READ_MAXAGG_LEN +1>(r, 0, _l_shipmode91);
        tbl_Sort_TD_0753_output.setInt64(r, 1, it._high_line_count1318L);
        tbl_Sort_TD_0753_output.setInt64(r, 2, it._low_line_count1319L);
        if (r < 10) {
            std::cout << (it._l_shipmode91).data() << " " << it._high_line_count1318L << " " << it._low_line_count1319L << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_0753_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_0753_output #Row: " << tbl_Sort_TD_0753_output.getNumRow() << std::endl;
}

