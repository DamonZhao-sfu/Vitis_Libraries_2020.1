#include <regex> 
#include <stdint.h> 

void SW_Filter_TD_7132(Table &tbl_SerializeFromObject_TD_8698_input, Table &tbl_Filter_TD_7132_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(p_name#259) AND StartsWith(p_name#259, blush)))
    // Input: ListBuffer(p_partkey#258, p_name#259)
    // Output: ListBuffer(p_partkey#258)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8698_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_P_NAME_LEN + 1> _p_name259 = tbl_SerializeFromObject_TD_8698_input.getcharN<char, TPCH_READ_P_NAME_LEN + 1>(i, 1);
        if ((1) && (std::string(_p_name259.data()).find("blush")==0)) {
            int32_t _p_partkey258_t = tbl_SerializeFromObject_TD_8698_input.getInt32(i, 0);
            tbl_Filter_TD_7132_output.setInt32(r, 0, _p_partkey258_t);
            r++;
        }
    }
    tbl_Filter_TD_7132_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7132_output #Row: " << tbl_Filter_TD_7132_output.getNumRow() << std::endl;
}

void SW_Filter_TD_793(Table &tbl_SerializeFromObject_TD_8100_input, Table &tbl_Filter_TD_793_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((l_shipdate#87 >= 19950101) AND (l_shipdate#87 < 19960101)))
    // Input: ListBuffer(l_partkey#78, l_suppkey#79, l_quantity#81, l_shipdate#87)
    // Output: ListBuffer(l_partkey#78, l_suppkey#79, l_quantity#81)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8100_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _l_shipdate87 = tbl_SerializeFromObject_TD_8100_input.getInt32(i, 3);
        if ((_l_shipdate87 >= 19950101) && (_l_shipdate87 < 19960101)) {
            int32_t _l_partkey78_t = tbl_SerializeFromObject_TD_8100_input.getInt32(i, 0);
            tbl_Filter_TD_793_output.setInt32(r, 0, _l_partkey78_t);
            int32_t _l_suppkey79_t = tbl_SerializeFromObject_TD_8100_input.getInt32(i, 1);
            tbl_Filter_TD_793_output.setInt32(r, 1, _l_suppkey79_t);
            int32_t _l_quantity81_t = tbl_SerializeFromObject_TD_8100_input.getInt32(i, 2);
            tbl_Filter_TD_793_output.setInt32(r, 2, _l_quantity81_t);
            r++;
        }
    }
    tbl_Filter_TD_793_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_793_output #Row: " << tbl_Filter_TD_793_output.getNumRow() << std::endl;
}


void SW_Aggregate_TD_5593_consolidate(Table *tbl_Aggregate_TD_5593_output_preprocess, Table &tbl_Aggregate_TD_5593_output, int hpTimes) {
    int nrow = 0;
for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
    int nrow_p = tbl_Aggregate_TD_5593_output_preprocess[p_idx].getNumRow();
    for (int r(0); r<nrow_p; ++r) {
        // Error: unsupported data type - revisit cpu/fpga determination logic - DecimalType(22,1) - default to IntegerType
        int32_t _suml_quantity498 = tbl_Aggregate_TD_5593_output_preprocess[p_idx].getInt32(r, 0);
        tbl_Aggregate_TD_5593_output.setInt32(r, 0, _suml_quantity498);
        int32_t _l_partkey78 = tbl_Aggregate_TD_5593_output_preprocess[p_idx].getInt32(r, 7);
        tbl_Aggregate_TD_5593_output.setInt32(r, 1, _l_partkey78);
        int32_t _l_suppkey79 = tbl_Aggregate_TD_5593_output_preprocess[p_idx].getInt32(r, 6);
        tbl_Aggregate_TD_5593_output.setInt32(r, 2, _l_suppkey79);
    }
    nrow += nrow_p;
}
    tbl_Aggregate_TD_5593_output.setNumRow(nrow);
    std::cout << "tbl_Aggregate_TD_5593_output #Row: " << tbl_Aggregate_TD_5593_output.getNumRow() << std::endl;
}



void SW_Filter_TD_220(Table &tbl_SerializeFromObject_TD_3494_input, Table &tbl_Filter_TD_220_output) {
    // StringRowIDSubstitution: true StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(n_name#145) AND (n_name#145 = INDONESIA)))
    // Input: ListBuffer(n_nationkey#144, n_name#145)
    // Output: ListBuffer(n_nationkey#144)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_3494_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_NATION_LEN + 1> _n_name145 = tbl_SerializeFromObject_TD_3494_input.getcharN<char, TPCH_READ_NATION_LEN + 1>(i, 1);
        if ((1) && (std::string(_n_name145.data()) == "INDONESIA")) {
            int32_t _n_nationkey144_t = tbl_SerializeFromObject_TD_3494_input.getInt32(i, 0);
            tbl_Filter_TD_220_output.setInt32(r, 0, _n_nationkey144_t);
            r++;
        }
    }
    tbl_Filter_TD_220_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_220_output #Row: " << tbl_Filter_TD_220_output.getNumRow() << std::endl;
}



void SW_Sort_TD_0524(Table *tbl_JOIN_INNER_TD_164_output, Table &tbl_SerializeFromObject_TD_3506_input, Table &tbl_SerializeFromObject_TD_3494_input, Table &tbl_Sort_TD_0524_output, int hpTimes) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: true
    // Supported operation: Sort
    // Operation: ListBuffer(s_name#343 ASC NULLS FIRST)
    // Input: ListBuffer(s_name#343, s_address#344)
    // Output: ListBuffer(s_name#343, s_address#344)
    struct SW_Sort_TD_0524Row {
        std::string _s_name343;
        std::string _s_address344;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_0524Row& a, const SW_Sort_TD_0524Row& b) const { return 
 (a._s_name343 < b._s_name343); 
}
    }SW_Sort_TD_0524_order; 
    
    std::vector<SW_Sort_TD_0524Row> rows;

    for (int t=0;t<hpTimes;t++) {
        int nrow1 = tbl_JOIN_INNER_TD_164_output[t].getNumRow();
        for (int i = 0; i < nrow1; i+1+) {
            std::array<char, TPCH_READ_S_NAME_LEN + 1> _s_name343 = tbl_SerializeFromObject_TD_3506_input.getcharN<char, TPCH_READ_S_NAME_LEN + 1>(tbl_JOIN_INNER_TD_164_output[t].getInt32(i, 0), 1);
            std::array<char, TPCH_READ_S_ADDR_MAX + 1> _s_address344 = tbl_SerializeFromObject_TD_3506_input.getcharN<char, TPCH_READ_S_ADDR_MAX + 1>(tbl_JOIN_INNER_TD_164_output[t].getInt32(i, 1), 2);
            SW_Sort_TD_0524Row t = {std::string(_s_name343.data()),std::string(_s_address344.data())};
            rows.push_back(t);
        }
    }

    std::sort(rows.begin(), rows.end(), SW_Sort_TD_0524_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCH_READ_S_NAME_LEN + 1> _s_name343{};
        memcpy(_s_name343.data(), (it._s_name343).data(), (it._s_name343).length());
        tbl_Sort_TD_0524_output.setcharN<char, TPCH_READ_S_NAME_LEN +1>(r, 0, _s_name343);
        std::array<char, TPCH_READ_S_ADDR_MAX + 1> _s_address344{};
        memcpy(_s_address344.data(), (it._s_address344).data(), (it._s_address344).length());
        tbl_Sort_TD_0524_output.setcharN<char, TPCH_READ_S_ADDR_MAX +1>(r, 1, _s_address344);
        if (r < 10) {
            std::cout << (it._s_name343).data() << " " << (it._s_address344).data() << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_0524_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_0524_output #Row: " << tbl_Sort_TD_0524_output.getNumRow() << std::endl;
}

