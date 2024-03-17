#include <regex> 
#include <stdint.h> 

void SW_Filter_TD_6160(Table &tbl_SerializeFromObject_TD_5811_input, Table &tbl_Filter_TD_6160_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((c_acctbal#27 > 0) AND substring(c_phone#26, 1, 2) IN (19,11,16,27,15,22,12)))
    // Input: ListBuffer(c_custkey#22, c_phone#26, c_acctbal#27)
    // Output: ListBuffer(c_acctbal#27)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5811_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_acctbal27 = tbl_SerializeFromObject_TD_5811_input.getInt32(i, 2);
        std::array<char, TPCH_READ_PHONE_LEN + 1> _c_phone26 = tbl_SerializeFromObject_TD_5811_input.getcharN<char, TPCH_READ_PHONE_LEN + 1>(i, 1);
        auto reuse_col_str_993 = std::string(_c_phone26.data()).substr(0, 2);
        if ((_c_acctbal27 > 0) && ((reuse_col_str_993 == "19") || (reuse_col_str_993 == "11") || (reuse_col_str_993 == "16") || (reuse_col_str_993 == "27") || (reuse_col_str_993 == "15") || (reuse_col_str_993 == "22") || (reuse_col_str_993 == "12") || (0))) {
            int32_t _c_acctbal27_t = tbl_SerializeFromObject_TD_5811_input.getInt32(i, 2);
            tbl_Filter_TD_6160_output.setInt32(r, 0, _c_acctbal27_t);
            r++;
        }
    }
    tbl_Filter_TD_6160_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_6160_output #Row: " << tbl_Filter_TD_6160_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_5678(Table &tbl_Filter_TD_6160_output, Table &tbl_Aggregate_TD_5678_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(avg(c_acctbal#27) AS avg(c_acctbal)#704)
    // Input: ListBuffer(c_acctbal#27)
    // Output: ListBuffer(avg(c_acctbal)#704)
    int64_t avg_0 = 0;
    int nrow1 = tbl_Filter_TD_6160_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _c_acctbal27 = tbl_Filter_TD_6160_output.getInt32(i, 0);
        int64_t _avgc_acctbal704_avg_0 = _c_acctbal27;
        avg_0 = (avg_0 + _avgc_acctbal704_avg_0);
    }
    int r = 0;
    int64_t _avgc_acctbal704 = avg_0 / nrow1;
    tbl_Aggregate_TD_5678_output.setInt64(r++, 0, _avgc_acctbal704);
    tbl_Aggregate_TD_5678_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_5678_output #Row: " << tbl_Aggregate_TD_5678_output.getNumRow() << std::endl;
}

void SW_Filter_TD_4410(Table &tbl_SerializeFromObject_TD_5811_input, Table &tbl_Aggregate_TD_5678_output, Table &tbl_Filter_TD_4410_output) {
    // StringRowIDSubstitution: true StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((substring(c_phone#26, 1, 2) IN (19,11,16,27,15,22,12) AND (cast(c_acctbal#27 as double) > scalar-subquery#698 [])))
    // Input: ListBuffer(c_custkey#22, c_phone#26, c_acctbal#27)
    // Output: ListBuffer(c_custkey#22, c_phone#26, c_acctbal#27)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_5811_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_PHONE_LEN + 1> _c_phone26 = tbl_SerializeFromObject_TD_5811_input.getcharN<char, TPCH_READ_PHONE_LEN + 1>(i, 1);
        int32_t _c_acctbal27 = tbl_SerializeFromObject_TD_5811_input.getInt32(i, 2);
        auto reuse_col_str_918 = std::string(_c_phone26.data()).substr(0, 2);
        if (((reuse_col_str_918 == "19") || (reuse_col_str_918 == "11") || (reuse_col_str_918 == "16") || (reuse_col_str_918 == "27") || (reuse_col_str_918 == "15") || (reuse_col_str_918 == "22") || (reuse_col_str_918 == "12") || (0)) && (_c_acctbal27 > tbl_Aggregate_TD_5678_output.getInt64(0, 0))) {
            int32_t _c_custkey22_t = tbl_SerializeFromObject_TD_5811_input.getInt32(i, 0);
            tbl_Filter_TD_4410_output.setInt32(r, 0, _c_custkey22_t);
            tbl_Filter_TD_4410_output.setInt32(r, 1, i);
            int32_t _c_acctbal27_t = tbl_SerializeFromObject_TD_5811_input.getInt32(i, 2);
            tbl_Filter_TD_4410_output.setInt32(r, 2, _c_acctbal27_t);
            r++;
        }
    }
    tbl_Filter_TD_4410_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_4410_output #Row: " << tbl_Filter_TD_4410_output.getNumRow() << std::endl;
}


void SW_Project_TD_2712(Table *tbl_JOIN_LEFTANTI_TD_3178_output, Table &tbl_SerializeFromObject_TD_5811_input, Table &tbl_Project_TD_2712_output, int hpTimes) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: true
    // Supported operation: Project
    // Operation: ListBuffer(substring(c_phone#26, 1, 2) AS cntrycode#697)
    // Input: ListBuffer(c_phone#26, c_acctbal#27)
    // Output: ListBuffer(cntrycode#697, c_acctbal#27)
    int totalRow = 0;
    for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
        int nrow1 = tbl_JOIN_LEFTANTI_TD_3178_output[p_idx].getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCH_READ_PHONE_LEN + 1> _c_phone26 = tbl_SerializeFromObject_TD_5811_input.getcharN<char, TPCH_READ_PHONE_LEN + 1>(tbl_JOIN_LEFTANTI_TD_3178_output[p_idx].getInt32(i, 0), 1);
            int32_t _c_acctbal27 = tbl_JOIN_LEFTANTI_TD_3178_output[p_idx].getInt32(i, 1);
            std::string _cntrycode697_str = std::string(_c_phone26.data()).substr(0, 2);
            std::array<char, TPCH_READ_REGION_LEN + 1> _cntrycode697{};
            memcpy(_cntrycode697.data(), _cntrycode697_str.data(), (_cntrycode697_str).length());
            tbl_Project_TD_2712_output.setcharN<char, TPCH_READ_REGION_LEN + 1>(i, 0, _cntrycode697);
            tbl_Project_TD_2712_output.setInt32(i, 1, _c_acctbal27);
        }
        totalRow += nrow1;
    }
    tbl_Project_TD_2712_output.setNumRow(totalRow);

    std::cout << "tbl_Project_TD_2712_output #Row: " << tbl_Project_TD_2712_output.getNumRow() << std::endl;
}

typedef std::string SW_Aggregate_TD_1795_key;
struct SW_Aggregate_TD_1795_payload {
    int64_t _numcust700L_count_0;
    int64_t _totacctbal701L_sum_1;
};
void SW_Aggregate_TD_1795(Table &tbl_Project_TD_2712_output, Table &tbl_Aggregate_TD_1795_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(cntrycode#697, count(1) AS numcust#700L, sum(c_acctbal#27) AS totacctbal#701L)
    // Input: ListBuffer(cntrycode#697, c_acctbal#27)
    // Output: ListBuffer(cntrycode#697, numcust#700L, totacctbal#701L)
    std::unordered_map<SW_Aggregate_TD_1795_key, SW_Aggregate_TD_1795_payload> ht1;
    int nrow1 = tbl_Project_TD_2712_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_REGION_LEN + 1> _cntrycode697 = tbl_Project_TD_2712_output.getcharN<char, TPCH_READ_REGION_LEN + 1>(i, 0);
        int32_t _c_acctbal27 = tbl_Project_TD_2712_output.getInt32(i, 1);
        SW_Aggregate_TD_1795_key k = std::string(_cntrycode697.data());
        int64_t _numcust700L_count_0 = 1 != 0 ? 1 : 0;
        int64_t _totacctbal701L_sum_1 = _c_acctbal27;
        SW_Aggregate_TD_1795_payload p{_numcust700L_count_0, _totacctbal701L_sum_1};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t count_0 = (it->second)._numcust700L_count_0 + _numcust700L_count_0;
            p._numcust700L_count_0 = count_0;
            int64_t sum_1 = (it->second)._totacctbal701L_sum_1 + _totacctbal701L_sum_1;
            p._totacctbal701L_sum_1 = sum_1;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCH_READ_REGION_LEN + 1> _cntrycode697{};
        memcpy(_cntrycode697.data(), (it.first).data(), (it.first).length());
        tbl_Aggregate_TD_1795_output.setcharN<char, TPCH_READ_REGION_LEN + 1>(r, 0, _cntrycode697);
        int64_t _numcust700L = (it.second)._numcust700L_count_0;
        tbl_Aggregate_TD_1795_output.setInt64(r, 1, _numcust700L);
        int64_t _totacctbal701L = (it.second)._totacctbal701L_sum_1;
        tbl_Aggregate_TD_1795_output.setInt64(r, 2, _totacctbal701L);
        ++r;
    }
    tbl_Aggregate_TD_1795_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_1795_output #Row: " << tbl_Aggregate_TD_1795_output.getNumRow() << std::endl;
}

void SW_Sort_TD_0764(Table &tbl_Aggregate_TD_1795_output, Table &tbl_Sort_TD_0764_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(cntrycode#697 ASC NULLS FIRST)
    // Input: ListBuffer(cntrycode#697, numcust#700L, totacctbal#701L)
    // Output: ListBuffer(cntrycode#697, numcust#700L, totacctbal#701L)
    struct SW_Sort_TD_0764Row {
        std::string _cntrycode697;
        int64_t _numcust700L;
        int64_t _totacctbal701L;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_0764Row& a, const SW_Sort_TD_0764Row& b) const { return 
 (a._cntrycode697 < b._cntrycode697); 
}
    }SW_Sort_TD_0764_order; 

    int nrow1 = tbl_Aggregate_TD_1795_output.getNumRow();
    std::vector<SW_Sort_TD_0764Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_REGION_LEN + 1> _cntrycode697 = tbl_Aggregate_TD_1795_output.getcharN<char, TPCH_READ_REGION_LEN +1>(i, 0);
        int64_t _numcust700L = tbl_Aggregate_TD_1795_output.getInt64(i, 1);
        int64_t _totacctbal701L = tbl_Aggregate_TD_1795_output.getInt64(i, 2);
        SW_Sort_TD_0764Row t = {std::string(_cntrycode697.data()),_numcust700L,_totacctbal701L};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_0764_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCH_READ_REGION_LEN + 1> _cntrycode697{};
        memcpy(_cntrycode697.data(), (it._cntrycode697).data(), (it._cntrycode697).length());
        tbl_Sort_TD_0764_output.setcharN<char, TPCH_READ_REGION_LEN +1>(r, 0, _cntrycode697);
        tbl_Sort_TD_0764_output.setInt64(r, 1, it._numcust700L);
        tbl_Sort_TD_0764_output.setInt64(r, 2, it._totacctbal701L);
        if (r < 10) {
            std::cout << (it._cntrycode697).data() << " " << it._numcust700L << " " << it._totacctbal701L << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_0764_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_0764_output #Row: " << tbl_Sort_TD_0764_output.getNumRow() << std::endl;
}

