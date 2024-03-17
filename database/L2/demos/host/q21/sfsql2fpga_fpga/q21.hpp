#include <regex> 
#include <stdint.h> 

void SW_Filter_TD_8663(Table &tbl_SerializeFromObject_TD_9185_input, Table &tbl_Filter_TD_8663_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((l_receiptdate#89 > l_commitdate#88))
    // Input: ListBuffer(l_orderkey#77, l_suppkey#79, l_receiptdate#89, l_commitdate#88)
    // Output: ListBuffer(l_orderkey#77, l_suppkey#79)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9185_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _l_receiptdate89 = tbl_SerializeFromObject_TD_9185_input.getInt32(i, 2);
        int32_t _l_commitdate88 = tbl_SerializeFromObject_TD_9185_input.getInt32(i, 3);
        if (_l_receiptdate89 > _l_commitdate88) {
            int32_t _l_orderkey77_t = tbl_SerializeFromObject_TD_9185_input.getInt32(i, 0);
            tbl_Filter_TD_8663_output.setInt32(r, 0, _l_orderkey77_t);
            int32_t _l_suppkey79_t = tbl_SerializeFromObject_TD_9185_input.getInt32(i, 1);
            tbl_Filter_TD_8663_output.setInt32(r, 1, _l_suppkey79_t);
            r++;
        }
    }
    tbl_Filter_TD_8663_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8663_output #Row: " << tbl_Filter_TD_8663_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7542(Table &tbl_SerializeFromObject_TD_9185_input, Table &tbl_Filter_TD_7542_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((l_receiptdate#89 > l_commitdate#88))
    // Input: ListBuffer(l_orderkey#77, l_suppkey#79, l_receiptdate#89, l_commitdate#88)
    // Output: ListBuffer(l_orderkey#77#672, l_suppkey#79#674)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9185_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _l_receiptdate89 = tbl_SerializeFromObject_TD_9185_input.getInt32(i, 2);
        int32_t _l_commitdate88 = tbl_SerializeFromObject_TD_9185_input.getInt32(i, 3);
        if (_l_receiptdate89 > _l_commitdate88) {
            int32_t _l_orderkey77672_t = tbl_SerializeFromObject_TD_9185_input.getInt32(i, 0);
            tbl_Filter_TD_7542_output.setInt32(r, 0, _l_orderkey77672_t);
            int32_t _l_suppkey79674_t = tbl_SerializeFromObject_TD_9185_input.getInt32(i, 1);
            tbl_Filter_TD_7542_output.setInt32(r, 1, _l_suppkey79674_t);
            r++;
        }
    }
    tbl_Filter_TD_7542_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7542_output #Row: " << tbl_Filter_TD_7542_output.getNumRow() << std::endl;
}



void SW_Filter_TD_3318(Table &tbl_SerializeFromObject_TD_4429_input, Table &tbl_Filter_TD_3318_output) {
    // StringRowIDSubstitution: true StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(n_name#145) AND (n_name#145 = JAPAN)))
    // Input: ListBuffer(n_nationkey#144, n_name#145)
    // Output: ListBuffer(n_nationkey#144)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_4429_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_NATION_LEN + 1> _n_name145 = tbl_SerializeFromObject_TD_4429_input.getcharN<char, TPCH_READ_NATION_LEN + 1>(i, 1);
        if ((1) && (std::string(_n_name145.data()) == "JAPAN")) {
            int32_t _n_nationkey144_t = tbl_SerializeFromObject_TD_4429_input.getInt32(i, 0);
            tbl_Filter_TD_3318_output.setInt32(r, 0, _n_nationkey144_t);
            r++;
        }
    }
    tbl_Filter_TD_3318_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_3318_output #Row: " << tbl_Filter_TD_3318_output.getNumRow() << std::endl;
}




void SW_Filter_TD_3939(Table &tbl_SerializeFromObject_TD_5636_input, Table &tbl_Filter_TD_3939_output) {
    // StringRowIDSubstitution: true StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((o_orderstatus#209 = 70))
    // Input: ListBuffer(o_orderkey#207, o_orderstatus#209)
    // Output: ListBuffer(o_orderkey#207)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5636_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _o_orderstatus209 = tbl_SerializeFromObject_TD_5636_input.getInt32(i, 1);
        if (_o_orderstatus209 == 70) {
            int32_t _o_orderkey207_t = tbl_SerializeFromObject_TD_5636_input.getInt32(i, 0);
            tbl_Filter_TD_3939_output.setInt32(r, 0, _o_orderkey207_t);
            r++;
        }
    }
    tbl_Filter_TD_3939_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_3939_output #Row: " << tbl_Filter_TD_3939_output.getNumRow() << std::endl;
}


typedef std::string SW_Aggregate_TD_1327_key;
struct SW_Aggregate_TD_1327_payload {
    int64_t _numwait559L_count_0;
};
void SW_Aggregate_TD_1327(Table *tbl_JOIN_INNER_TD_2550_output, Table &tbl_SerializeFromObject_TD_5636_input, Table &tbl_SerializeFromObject_TD_5610_input, Table &tbl_SerializeFromObject_TD_4429_input, Table &tbl_Aggregate_TD_1327_output, int hpTimes) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: true
    // Supported operation: Aggregate
    // Operation: ListBuffer(s_name#343, count(1) AS numwait#559L)
    // Input: ListBuffer(s_name#343)
    // Output: ListBuffer(s_name#343, numwait#559L)
    std::unordered_map<SW_Aggregate_TD_1327_key, SW_Aggregate_TD_1327_payload> ht1;
for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
    int nrow1 = tbl_JOIN_INNER_TD_2550_output[p_idx].getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_S_NAME_LEN + 1> _s_name343 = tbl_SerializeFromObject_TD_5610_input.getcharN<char, TPCH_READ_S_NAME_LEN + 1>(tbl_JOIN_INNER_TD_2550_output[p_idx].getInt32(i, 0), 1);
        SW_Aggregate_TD_1327_key k = std::string(_s_name343.data());
        int64_t _numwait559L_count_0 = 1 != 0 ? 1 : 0;
        SW_Aggregate_TD_1327_payload p{_numwait559L_count_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t count_0 = (it->second)._numwait559L_count_0 + _numwait559L_count_0;
            p._numwait559L_count_0 = count_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
}
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCH_READ_S_NAME_LEN + 1> _s_name343{};
        memcpy(_s_name343.data(), (it.first).data(), (it.first).length());
        tbl_Aggregate_TD_1327_output.setcharN<char, TPCH_READ_S_NAME_LEN + 1>(r, 0, _s_name343);
        int64_t _numwait559L = (it.second)._numwait559L_count_0;
        tbl_Aggregate_TD_1327_output.setInt64(r, 1, _numwait559L);
        ++r;
    }
    tbl_Aggregate_TD_1327_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_1327_output #Row: " << tbl_Aggregate_TD_1327_output.getNumRow() << std::endl;
}

void SW_Sort_TD_0354(Table &tbl_Aggregate_TD_1327_output, Table &tbl_Sort_TD_0354_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(numwait#559L DESC NULLS LAST, s_name#343 ASC NULLS FIRST)
    // Input: ListBuffer(s_name#343, numwait#559L)
    // Output: ListBuffer(s_name#343, numwait#559L)
    struct SW_Sort_TD_0354Row {
        std::string _s_name343;
        int64_t _numwait559L;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_0354Row& a, const SW_Sort_TD_0354Row& b) const { return 
 (a._numwait559L > b._numwait559L) || 
 ((a._numwait559L == b._numwait559L) && (a._s_name343 < b._s_name343)); 
}
    }SW_Sort_TD_0354_order; 

    int nrow1 = tbl_Aggregate_TD_1327_output.getNumRow();
    std::vector<SW_Sort_TD_0354Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_S_NAME_LEN + 1> _s_name343 = tbl_Aggregate_TD_1327_output.getcharN<char, TPCH_READ_S_NAME_LEN +1>(i, 0);
        int64_t _numwait559L = tbl_Aggregate_TD_1327_output.getInt64(i, 1);
        SW_Sort_TD_0354Row t = {std::string(_s_name343.data()),_numwait559L};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_0354_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCH_READ_S_NAME_LEN + 1> _s_name343{};
        memcpy(_s_name343.data(), (it._s_name343).data(), (it._s_name343).length());
        tbl_Sort_TD_0354_output.setcharN<char, TPCH_READ_S_NAME_LEN +1>(r, 0, _s_name343);
        tbl_Sort_TD_0354_output.setInt64(r, 1, it._numwait559L);
        if (r < 10) {
            std::cout << (it._s_name343).data() << " " << it._numwait559L << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_0354_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_0354_output #Row: " << tbl_Sort_TD_0354_output.getNumRow() << std::endl;
}

