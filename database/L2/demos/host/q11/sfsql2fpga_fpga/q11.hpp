#include <regex> 
#include <stdint.h> 

void SW_Filter_TD_4867(Table &tbl_SerializeFromObject_TD_5250_input, Table &tbl_Filter_TD_4867_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(n_name#145) AND (n_name#145 = IRAN)))
    // Input: ListBuffer(n_nationkey#144, n_name#145)
    // Output: ListBuffer(n_nationkey#144)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5250_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_NATION_LEN + 1> _n_name145 = tbl_SerializeFromObject_TD_5250_input.getcharN<char, TPCH_READ_NATION_LEN + 1>(i, 1);
        if ((1) && (std::string(_n_name145.data()) == "IRAN")) {
            int32_t _n_nationkey144_t = tbl_SerializeFromObject_TD_5250_input.getInt32(i, 0);
            tbl_Filter_TD_4867_output.setInt32(r, 0, _n_nationkey144_t);
            r++;
        }
    }
    tbl_Filter_TD_4867_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4867_output #Row: " << tbl_Filter_TD_4867_output.getNumRow() << std::endl;
}



void SW_Aggregate_TD_2714(Table &tbl_JOIN_INNER_TD_4990_output, Table &tbl_Aggregate_TD_2714_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(CheckOverflow((promote_precision(cast(cast(sum((ps_supplycost#308 * ps_availqty#307)) as decimal(20,0)) as decimal(30,10))) * 0.0001000000), DecimalType(31,10), true) AS (sum((ps_supplycost * ps_availqty)) * 0.0001000000)#1160)
    // Input: ListBuffer(ps_partkey#305, ps_availqty#307, ps_supplycost#308)
    // Output: ListBuffer((sum((ps_supplycost * ps_availqty)) * 0.0001000000)#1160)
    int64_t sum_0 = 0;
    int nrow1 = tbl_JOIN_INNER_TD_4990_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ps_partkey305 = tbl_JOIN_INNER_TD_4990_output.getInt32(i, 0);
        int32_t _ps_availqty307 = tbl_JOIN_INNER_TD_4990_output.getInt32(i, 1);
        int32_t _ps_supplycost308 = tbl_JOIN_INNER_TD_4990_output.getInt32(i, 2);
        int64_t _000010000001160_sum_0 = (_ps_supplycost308 * _ps_availqty307);
        sum_0 += _000010000001160_sum_0;
    }
    int r = 0;
    int64_t _000010000001160 = (sum_0 * 0.0001000000);
    tbl_Aggregate_TD_2714_output.setInt64(r++, 0, _000010000001160);
    tbl_Aggregate_TD_2714_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_2714_output #Row: " << tbl_Aggregate_TD_2714_output.getNumRow() << std::endl;
}

typedef int32_t SW_Aggregate_TD_2411_key;
struct SW_Aggregate_TD_2411_payload {
    int64_t _value1156L_sum_0;
};
void SW_Aggregate_TD_2411(Table &tbl_JOIN_INNER_TD_4990_output, Table &tbl_Aggregate_TD_2411_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(ps_partkey#305, sum((ps_supplycost#308 * ps_availqty#307)) AS value#1156L)
    // Input: ListBuffer(ps_partkey#305, ps_availqty#307, ps_supplycost#308)
    // Output: ListBuffer(ps_partkey#305, value#1156L)
    std::unordered_map<SW_Aggregate_TD_2411_key, SW_Aggregate_TD_2411_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_4990_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ps_partkey305 = tbl_JOIN_INNER_TD_4990_output.getInt32(i, 0);
        int32_t _ps_availqty307 = tbl_JOIN_INNER_TD_4990_output.getInt32(i, 1);
        int32_t _ps_supplycost308 = tbl_JOIN_INNER_TD_4990_output.getInt32(i, 2);
        SW_Aggregate_TD_2411_key k = _ps_partkey305;
        int64_t _value1156L_sum_0 = (_ps_supplycost308 * _ps_availqty307);
        SW_Aggregate_TD_2411_payload p{_value1156L_sum_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._value1156L_sum_0 + _value1156L_sum_0;
            p._value1156L_sum_0 = sum_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        tbl_Aggregate_TD_2411_output.setInt32(r, 0, (it.first));
        int64_t _value1156L = (it.second)._value1156L_sum_0;
        tbl_Aggregate_TD_2411_output.setInt64(r, 1, _value1156L);
        ++r;
    }
    tbl_Aggregate_TD_2411_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_2411_output #Row: " << tbl_Aggregate_TD_2411_output.getNumRow() << std::endl;
}

void SW_Filter_TD_1880(Table &tbl_Aggregate_TD_2411_output, Table &tbl_Aggregate_TD_2714_output, Table &tbl_Filter_TD_1880_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(value#1156L) AND (cast(cast(value#1156L as decimal(20,0)) as decimal(31,10)) > scalar-subquery#1157 [])))
    // Input: ListBuffer(ps_partkey#305, value#1156L)
    // Output: ListBuffer(ps_partkey#305, value#1156L)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_2411_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _value1156L = tbl_Aggregate_TD_2411_output.getInt64(i, 1);
        if ((1) && (_value1156L > tbl_Aggregate_TD_2714_output.getInt64(0, 0))) {
            int32_t _ps_partkey305_t = tbl_Aggregate_TD_2411_output.getInt32(i, 0);
            tbl_Filter_TD_1880_output.setInt32(r, 0, _ps_partkey305_t);
            int64_t _value1156L_t = tbl_Aggregate_TD_2411_output.getInt64(i, 1);
            tbl_Filter_TD_1880_output.setInt64(r, 1, _value1156L_t);
            r++;
        }
    }
    tbl_Filter_TD_1880_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_1880_output #Row: " << tbl_Filter_TD_1880_output.getNumRow() << std::endl;
}

void SW_Sort_TD_0107(Table &tbl_Filter_TD_1880_output, Table &tbl_Sort_TD_0107_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(value#1156L DESC NULLS LAST)
    // Input: ListBuffer(ps_partkey#305, value#1156L)
    // Output: ListBuffer(ps_partkey#305, value#1156L)
    struct SW_Sort_TD_0107Row {
        int32_t _ps_partkey305;
        int64_t _value1156L;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_0107Row& a, const SW_Sort_TD_0107Row& b) const { return 
 (a._value1156L > b._value1156L); 
}
    }SW_Sort_TD_0107_order; 

    int nrow1 = tbl_Filter_TD_1880_output.getNumRow();
    std::vector<SW_Sort_TD_0107Row> rows;
    for (int i = 0; i < nrow1; i++) {
        int32_t _ps_partkey305 = tbl_Filter_TD_1880_output.getInt32(i, 0);
        int64_t _value1156L = tbl_Filter_TD_1880_output.getInt64(i, 1);
        SW_Sort_TD_0107Row t = {_ps_partkey305,_value1156L};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_0107_order);
    int r = 0;
    for (auto& it : rows) {
        tbl_Sort_TD_0107_output.setInt32(r, 0, it._ps_partkey305);
        tbl_Sort_TD_0107_output.setInt64(r, 1, it._value1156L);
        if (r < 10) {
            std::cout << it._ps_partkey305 << " " << it._value1156L << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_0107_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_0107_output #Row: " << tbl_Sort_TD_0107_output.getNumRow() << std::endl;
}

