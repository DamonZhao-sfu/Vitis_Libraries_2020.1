#include <regex> 
#include <stdint.h> 

void SW_Filter_TD_665(Table &tbl_SerializeFromObject_TD_7265_input, Table &tbl_Filter_TD_665_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((l_shipdate#87 >= 1) AND (l_shipdate#87 < 4)))
    // Input: ListBuffer(l_suppkey#79, l_extendedprice#82, l_discount#83, l_shipdate#87)
    // Output: ListBuffer(l_suppkey#79, l_extendedprice#82, l_discount#83)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7265_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _l_shipdate87 = tbl_SerializeFromObject_TD_7265_input.getInt32(i, 3);
        if ((_l_shipdate87 >= 19960101) && (_l_shipdate87 < 19960401)) {
            int32_t _l_suppkey79_t = tbl_SerializeFromObject_TD_7265_input.getInt32(i, 0);
            tbl_Filter_TD_665_output.setInt32(r, 0, _l_suppkey79_t);
            int32_t _l_extendedprice82_t = tbl_SerializeFromObject_TD_7265_input.getInt32(i, 1);
            tbl_Filter_TD_665_output.setInt32(r, 1, _l_extendedprice82_t);
            int32_t _l_discount83_t = tbl_SerializeFromObject_TD_7265_input.getInt32(i, 2);
            tbl_Filter_TD_665_output.setInt32(r, 2, _l_discount83_t);
            r++;
        }
    }
    tbl_Filter_TD_665_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_665_output #Row: " << tbl_Filter_TD_665_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_5138_consolidate(Table *tbl_Aggregate_TD_5138_output_preprocess, Table &tbl_Aggregate_TD_5138_output, int hpTimes) {
    int nrow = 0;
    for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
        int nrow_p = tbl_Aggregate_TD_5138_output_preprocess[p_idx].getNumRow();
        for (int r(0); r<nrow_p; ++r) {
            int64_t _total_revenue1476L = tbl_Aggregate_TD_5138_output_preprocess[p_idx].combineInt64(r, 8, 0);
            tbl_Aggregate_TD_5138_output.setInt64(r, 0, _total_revenue1476L);
        }
        nrow += nrow_p;
    }
    tbl_Aggregate_TD_5138_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_5138_output #Row: " << tbl_Aggregate_TD_5138_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_4652(Table &tbl_Aggregate_TD_5138_output, Table &tbl_Aggregate_TD_4652_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(max(total_revenue#1476L) AS max(total_revenue)#1478L)
    // Input: ListBuffer(total_revenue#1476L)
    // Output: ListBuffer(max(total_revenue)#1478L)
    int64_t max_0 = 0;
    int nrow1 = tbl_Aggregate_TD_5138_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _total_revenue1476L = tbl_Aggregate_TD_5138_output.getInt64(i, 0);
        int64_t _maxtotal_revenue1478L_max_0 = _total_revenue1476L;
        max_0 = max_0 < _maxtotal_revenue1478L_max_0 ? _maxtotal_revenue1478L_max_0 : max_0;
    }

    int r = 0;
    int64_t _maxtotal_revenue1478L = max_0;
    tbl_Aggregate_TD_4652_output.setInt64(r++, 0, _maxtotal_revenue1478L);
    tbl_Aggregate_TD_4652_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_4652_output #Row: " << tbl_Aggregate_TD_4652_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_4225_consolidate(Table *tbl_Aggregate_TD_4225_output_preprocess, Table &tbl_Aggregate_TD_4225_output, int hpTimes) {
    int nrow = 0;
for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
    int nrow_p = tbl_Aggregate_TD_4225_output_preprocess[p_idx].getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        int32_t _l_suppkey79 = tbl_Aggregate_TD_4225_output_preprocess[p_idx].getInt32(r, 7);
        tbl_Aggregate_TD_4225_output.setInt32(r, 0, _l_suppkey79);
        int64_t _l_discount1474L = tbl_Aggregate_TD_4225_output_preprocess[p_idx].combineInt64(r, 8, 0);
        tbl_Aggregate_TD_4225_output.setInt64(r, 1, _l_discount1474L);
    }
    nrow += nrow_p;
}
    tbl_Aggregate_TD_4225_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_4225_output #Row: " << tbl_Aggregate_TD_4225_output.getNumRow() << std::endl;
}

void SW_Filter_TD_2964(Table &tbl_Aggregate_TD_4225_output, Table &tbl_Aggregate_TD_4652_output, Table &tbl_Filter_TD_2964_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(sum((l_extendedprice * (1 - l_discount)))#1474L) AND (sum((l_extendedprice * (1 - l_discount)))#1474L = scalar-subquery#1472 [])))
    // Input: ListBuffer(l_suppkey#79, sum((l_extendedprice * (1 - l_discount)))#1474L)
    // Output: ListBuffer(supplier_no#1475, total_revenue#1476L)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_4225_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _l_discount1474L = tbl_Aggregate_TD_4225_output.getInt64(i, 1);
        if ((1) && (_l_discount1474L == tbl_Aggregate_TD_4652_output.getInt64(0, 0))) {
            int32_t _supplier_no1475_t = tbl_Aggregate_TD_4225_output.getInt32(i, 0);
            tbl_Filter_TD_2964_output.setInt32(r, 0, _supplier_no1475_t);
            int64_t _total_revenue1476L_t = tbl_Aggregate_TD_4225_output.getInt64(i, 1);
            tbl_Filter_TD_2964_output.setInt64(r, 1, _total_revenue1476L_t);
            r++;
        }
    }
    tbl_Filter_TD_2964_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_2964_output #Row: " << tbl_Filter_TD_2964_output.getNumRow() << std::endl;
}


void SW_Sort_TD_0471(Table *tbl_JOIN_INNER_TD_191_output_array_partition, Table &tbl_SerializeFromObject_TD_2243_input, Table &tbl_Sort_TD_0471_output, int hpTimes) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: true
    // Supported operation: Sort
    // Operation: ListBuffer(s_suppkey#342 ASC NULLS FIRST)
    // Input: ListBuffer(s_suppkey#342, s_name#343, s_address#344, s_phone#346, total_revenue#1476L)
    // Output: ListBuffer(s_suppkey#342, s_name#343, s_address#344, s_phone#346, total_revenue#1476L)
    struct SW_Sort_TD_0471Row {
        int32_t _s_suppkey342;
        std::string _s_name343;
        std::string _s_address344;
        std::string _s_phone346;
        int64_t _total_revenue1476L;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_0471Row& a, const SW_Sort_TD_0471Row& b) const { return 
 (a._s_suppkey342 < b._s_suppkey342); 
}
    }SW_Sort_TD_0471_order; 
    std::vector<SW_Sort_TD_0471Row> rows;
    for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
        int nrow1 = tbl_JOIN_INNER_TD_191_output_array_partition[p_idx].getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_suppkey342 = tbl_JOIN_INNER_TD_191_output_array_partition[p_idx].getInt32(i, 0);
            std::array<char, TPCH_READ_S_NAME_LEN + 1> _s_name343 = tbl_SerializeFromObject_TD_2243_input.getcharN<char, TPCH_READ_S_NAME_LEN + 1>(tbl_JOIN_INNER_TD_191_output_array_partition[p_idx].getInt32(i, 1), 1);
            std::array<char, TPCH_READ_S_ADDR_MAX + 1> _s_address344 = tbl_SerializeFromObject_TD_2243_input.getcharN<char, TPCH_READ_S_ADDR_MAX + 1>(tbl_JOIN_INNER_TD_191_output_array_partition[p_idx].getInt32(i, 2), 2);
            std::array<char, TPCH_READ_PHONE_LEN + 1> _s_phone346 = tbl_SerializeFromObject_TD_2243_input.getcharN<char, TPCH_READ_PHONE_LEN + 1>(tbl_JOIN_INNER_TD_191_output_array_partition[p_idx].getInt32(i, 3), 3);
            int64_t _total_revenue1476L = tbl_JOIN_INNER_TD_191_output_array_partition[p_idx].getInt64(i, 4);
            SW_Sort_TD_0471Row t = {_s_suppkey342,std::string(_s_name343.data()),std::string(_s_address344.data()),std::string(_s_phone346.data()),_total_revenue1476L};
            rows.push_back(t);
        }
    }
   
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_0471_order);
    int r = 0;
    std::cout << "number of rows" << rows.size() << std::endl;
    for (auto& it : rows) {
        tbl_Sort_TD_0471_output.setInt32(r, 0, it._s_suppkey342);
        std::array<char, TPCH_READ_S_NAME_LEN + 1> _s_name343{};
        memcpy(_s_name343.data(), (it._s_name343).data(), (it._s_name343).length());
        tbl_Sort_TD_0471_output.setcharN<char, TPCH_READ_S_NAME_LEN +1>(r, 1, _s_name343);
        std::array<char, TPCH_READ_S_ADDR_MAX + 1> _s_address344{};
        memcpy(_s_address344.data(), (it._s_address344).data(), (it._s_address344).length());
        tbl_Sort_TD_0471_output.setcharN<char, TPCH_READ_S_ADDR_MAX +1>(r, 2, _s_address344);
        std::array<char, TPCH_READ_PHONE_LEN + 1> _s_phone346{};
        memcpy(_s_phone346.data(), (it._s_phone346).data(), (it._s_phone346).length());
        tbl_Sort_TD_0471_output.setcharN<char, TPCH_READ_PHONE_LEN +1>(r, 3, _s_phone346);
        tbl_Sort_TD_0471_output.setInt64(r, 4, it._total_revenue1476L);
        if (r < 10) {
            std::cout << it._s_suppkey342 << " " << (it._s_name343).data() << " " << (it._s_address344).data() << " " << (it._s_phone346).data() << " " << it._total_revenue1476L << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_0471_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_0471_output #Row: " << tbl_Sort_TD_0471_output.getNumRow() << std::endl;
}

