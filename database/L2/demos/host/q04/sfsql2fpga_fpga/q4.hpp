#include <regex> 
#include <stdint.h> 

void SW_Filter_TD_3817(Table &tbl_SerializeFromObject_TD_4898_input, Table &tbl_Filter_TD_3817_output) {
    // StringRowIDSubstitution: true StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((l_commitdate#88 < l_receiptdate#89))
    // Input: ListBuffer(l_orderkey#77, l_commitdate#88, l_receiptdate#89)
    // Output: ListBuffer(l_orderkey#77)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_4898_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _l_commitdate88 = tbl_SerializeFromObject_TD_4898_input.getInt32(i, 1);
        int32_t _l_receiptdate89 = tbl_SerializeFromObject_TD_4898_input.getInt32(i, 2);
        if (_l_commitdate88 < _l_receiptdate89) {
            int32_t _l_orderkey77_t = tbl_SerializeFromObject_TD_4898_input.getInt32(i, 0);
            tbl_Filter_TD_3817_output.setInt32(r, 0, _l_orderkey77_t);
            r++;
        }
    }
    tbl_Filter_TD_3817_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_3817_output #Row: " << tbl_Filter_TD_3817_output.getNumRow() << std::endl;
}

void SW_Filter_TD_3999(Table &tbl_SerializeFromObject_TD_42_input_stringRowIDSubstitute, Table &tbl_Filter_TD_3999_output) {
    // StringRowIDSubstitution: true StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((o_orderdate#211 >= 19930701) AND (o_orderdate#211 < 19931001)))
    // Input: ListBuffer(o_orderkey#207, o_orderpriority#212, o_orderdate#211)
    // Output: ListBuffer(o_orderkey#207, o_orderpriority#212)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_42_input_stringRowIDSubstitute.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _o_orderdate211 = tbl_SerializeFromObject_TD_42_input_stringRowIDSubstitute.getInt32(i, 2);
        if ((_o_orderdate211 >= 19930701) && (_o_orderdate211 < 19931001)) {
            int32_t _o_orderkey207_t = tbl_SerializeFromObject_TD_42_input_stringRowIDSubstitute.getInt32(i, 0);
            tbl_Filter_TD_3999_output.setInt32(r, 0, _o_orderkey207_t);
            tbl_Filter_TD_3999_output.setInt32(r, 1, i);
            r++;
        }
    }
    tbl_Filter_TD_3999_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_3999_output #Row: " << tbl_Filter_TD_3999_output.getNumRow() << std::endl;
}


typedef std::string SW_Aggregate_TD_1487_key;
struct SW_Aggregate_TD_1487_payload {
    int64_t _order_count759L_count_0;
};
void SW_Aggregate_TD_1487(Table *tbl_JOIN_LEFTSEMI_TD_2622_output, Table &tbl_SerializeFromObject_TD_42_input, Table &tbl_SerializeFromObject_TD_4898_input, Table &tbl_Aggregate_TD_1487_output, int hpTimes) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: true
    // Supported operation: Aggregate
    // Operation: ListBuffer(o_orderpriority#212, count(1) AS order_count#759L)
    // Input: ListBuffer(o_orderpriority#212)
    // Output: ListBuffer(o_orderpriority#212, order_count#759L)
    std::unordered_map<SW_Aggregate_TD_1487_key, SW_Aggregate_TD_1487_payload> ht1;
for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
    int nrow1 = tbl_JOIN_LEFTSEMI_TD_2622_output[p_idx].getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_MAXAGG_LEN + 1> _o_orderpriority212 = tbl_SerializeFromObject_TD_42_input.getcharN<char, TPCH_READ_MAXAGG_LEN + 1>(tbl_JOIN_LEFTSEMI_TD_2622_output[p_idx].getInt32(i, 0), 1);
        SW_Aggregate_TD_1487_key k = std::string(_o_orderpriority212.data());
        int64_t _order_count759L_count_0 = 1 != 0 ? 1 : 0;
        SW_Aggregate_TD_1487_payload p{_order_count759L_count_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t count_0 = (it->second)._order_count759L_count_0 + _order_count759L_count_0;
            p._order_count759L_count_0 = count_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
}
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCH_READ_MAXAGG_LEN + 1> _o_orderpriority212{};
        memcpy(_o_orderpriority212.data(), (it.first).data(), (it.first).length());
        tbl_Aggregate_TD_1487_output.setcharN<char, TPCH_READ_MAXAGG_LEN + 1>(r, 0, _o_orderpriority212);
        int64_t _order_count759L = (it.second)._order_count759L_count_0;
        tbl_Aggregate_TD_1487_output.setInt64(r, 1, _order_count759L);
        ++r;
    }
    tbl_Aggregate_TD_1487_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_1487_output #Row: " << tbl_Aggregate_TD_1487_output.getNumRow() << std::endl;
}

void SW_Sort_TD_0712(Table &tbl_Aggregate_TD_1487_output, Table &tbl_Sort_TD_0712_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(o_orderpriority#212 ASC NULLS FIRST)
    // Input: ListBuffer(o_orderpriority#212, order_count#759L)
    // Output: ListBuffer(o_orderpriority#212, order_count#759L)
    struct SW_Sort_TD_0712Row {
        std::string _o_orderpriority212;
        int64_t _order_count759L;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_0712Row& a, const SW_Sort_TD_0712Row& b) const { return 
 (a._o_orderpriority212 < b._o_orderpriority212); 
}
    }SW_Sort_TD_0712_order; 

    int nrow1 = tbl_Aggregate_TD_1487_output.getNumRow();
    std::vector<SW_Sort_TD_0712Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_MAXAGG_LEN + 1> _o_orderpriority212 = tbl_Aggregate_TD_1487_output.getcharN<char, TPCH_READ_MAXAGG_LEN +1>(i, 0);
        int64_t _order_count759L = tbl_Aggregate_TD_1487_output.getInt64(i, 1);
        SW_Sort_TD_0712Row t = {std::string(_o_orderpriority212.data()),_order_count759L};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_0712_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCH_READ_MAXAGG_LEN + 1> _o_orderpriority212{};
        memcpy(_o_orderpriority212.data(), (it._o_orderpriority212).data(), (it._o_orderpriority212).length());
        tbl_Sort_TD_0712_output.setcharN<char, TPCH_READ_MAXAGG_LEN +1>(r, 0, _o_orderpriority212);
        tbl_Sort_TD_0712_output.setInt64(r, 1, it._order_count759L);
        if (r < 10) {
            std::cout << (it._o_orderpriority212).data() << " " << it._order_count759L << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_0712_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_0712_output #Row: " << tbl_Sort_TD_0712_output.getNumRow() << std::endl;
}

