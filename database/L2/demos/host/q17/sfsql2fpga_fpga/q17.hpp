#include <regex> 
#include <stdint.h> 

void SW_Filter_TD_34(Table &tbl_SerializeFromObject_TD_478_input, Table &tbl_Filter_TD_34_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(p_brand#261) AND isnotnull(p_container#264)) AND ((p_brand#261 = Brand#21) AND (p_container#264 = WRAP BAG))))
    // Input: ListBuffer(p_partkey#258, p_brand#261, p_container#264)
    // Output: ListBuffer(p_partkey#258)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_478_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_P_BRND_LEN + 1> _p_brand261 = tbl_SerializeFromObject_TD_478_input.getcharN<char, TPCH_READ_P_BRND_LEN + 1>(i, 1);
        std::array<char, TPCH_READ_P_CNTR_LEN + 1> _p_container264 = tbl_SerializeFromObject_TD_478_input.getcharN<char, TPCH_READ_P_CNTR_LEN + 1>(i, 2);
        if (((1) && (1)) && ((std::string(_p_brand261.data()) == "Brand#21") && (std::string(_p_container264.data()) == "WRAP BAG"))) {
            int32_t _p_partkey258_t = tbl_SerializeFromObject_TD_478_input.getInt32(i, 0);
            tbl_Filter_TD_34_output.setInt32(r, 0, _p_partkey258_t);
            r++;
        }
    }
    tbl_Filter_TD_34_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_34_output #Row: " << tbl_Filter_TD_34_output.getNumRow() << std::endl;
}

typedef int32_t SW_Aggregate_TD_3446_key;
struct SW_Aggregate_TD_3446_payload {
    int64_t _avgl_quantity1673_avg_0;
    int32_t _l_partkey781723;
};
void SW_Aggregate_TD_3446(Table &tbl_SerializeFromObject_TD_4124_input, Table &tbl_Aggregate_TD_3446_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(l_partkey#78, (0.2 * avg(l_quantity#81)) AS (0.2 * avg(l_quantity))#1673, l_partkey#78 AS l_partkey#78#1723)
    // Input: ListBuffer(l_partkey#78, l_quantity#81)
    // Output: ListBuffer((0.2 * avg(l_quantity))#1673, l_partkey#78#1723)
    std::unordered_map<SW_Aggregate_TD_3446_key, SW_Aggregate_TD_3446_payload> ht1;
    int nrow1 = tbl_SerializeFromObject_TD_4124_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _l_partkey78 = tbl_SerializeFromObject_TD_4124_input.getInt32(i, 0);
        int32_t _l_quantity81 = tbl_SerializeFromObject_TD_4124_input.getInt32(i, 1);
        SW_Aggregate_TD_3446_key k = _l_partkey78;
        int64_t _avgl_quantity1673_avg_0 = _l_quantity81;
        int32_t _l_partkey781723 = _l_partkey78;
        SW_Aggregate_TD_3446_payload p{_avgl_quantity1673_avg_0, _l_partkey781723};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t avg_0 = ((it->second)._avgl_quantity1673_avg_0 + _avgl_quantity1673_avg_0);
            p._avgl_quantity1673_avg_0 = avg_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        // _l_partkey78 not required in the output table
        int64_t _avgl_quantity1673 = (0.2 * (it.second)._avgl_quantity1673_avg_0 / nrow1);
        tbl_Aggregate_TD_3446_output.setInt64(r, 0, _avgl_quantity1673);
        tbl_Aggregate_TD_3446_output.setInt32(r, 1, (it.second)._l_partkey781723);
        ++r;
    }
    tbl_Aggregate_TD_3446_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_3446_output #Row: " << tbl_Aggregate_TD_3446_output.getNumRow() << std::endl;
}


struct SW_JOIN_INNER_TD_1700_key_leftMajor {
    int32_t _p_partkey258;
    bool operator==(const SW_JOIN_INNER_TD_1700_key_leftMajor& other) const {
        return ((_p_partkey258 == other._p_partkey258));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_1700_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_1700_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._p_partkey258));
    }
};
}
struct SW_JOIN_INNER_TD_1700_payload_leftMajor {
    int32_t _l_quantity81;
    int32_t _l_extendedprice82;
    int32_t _p_partkey258;
};
struct SW_JOIN_INNER_TD_1700_key_rightMajor {
    int32_t _l_partkey781723;
    bool operator==(const SW_JOIN_INNER_TD_1700_key_rightMajor& other) const {
        return ((_l_partkey781723 == other._l_partkey781723));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_1700_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_1700_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._l_partkey781723));
    }
};
}
struct SW_JOIN_INNER_TD_1700_payload_rightMajor {
    int64_t _avgl_quantity1673;
    int32_t _l_partkey781723;
};
void SW_JOIN_INNER_TD_1700(Table *tbl_JOIN_INNER_TD_2677_output, Table &tbl_Aggregate_TD_3446_output, Table &tbl_JOIN_INNER_TD_1700_output, int hpTimes) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((cast(l_quantity#81 as double) < (0.2 * avg(l_quantity))#1673) AND (l_partkey#78#1723 = p_partkey#258)))
    // Left Table: ListBuffer(l_quantity#81, l_extendedprice#82, p_partkey#258)
    // Right Table: ListBuffer((0.2 * avg(l_quantity))#1673, l_partkey#78#1723)
    // Output Table: ListBuffer(l_extendedprice#82)
    int left_nrow = tbl_JOIN_INNER_TD_2677_output[0].getNumRow();
    int right_nrow = tbl_Aggregate_TD_3446_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_1700_key_leftMajor, SW_JOIN_INNER_TD_1700_payload_leftMajor> ht1;
    for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
        int nrow1 = tbl_JOIN_INNER_TD_2677_output[p_idx].getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _p_partkey258_k = tbl_JOIN_INNER_TD_2677_output[p_idx].getInt32(i, 2);
            SW_JOIN_INNER_TD_1700_key_leftMajor keyA{_p_partkey258_k};
            int32_t _l_quantity81 = tbl_JOIN_INNER_TD_2677_output[p_idx].getInt32(i, 0);
            int32_t _l_extendedprice82 = tbl_JOIN_INNER_TD_2677_output[p_idx].getInt32(i, 1);
            int32_t _p_partkey258 = tbl_JOIN_INNER_TD_2677_output[p_idx].getInt32(i, 2);
            SW_JOIN_INNER_TD_1700_payload_leftMajor payloadA{_l_quantity81, _l_extendedprice82, _p_partkey258};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
    }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_3446_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _l_partkey781723_k = tbl_Aggregate_TD_3446_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_1700_key_leftMajor{_l_partkey781723_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _l_quantity81 = (it->second)._l_quantity81;
                int32_t _l_extendedprice82 = (it->second)._l_extendedprice82;
                int32_t _p_partkey258 = (it->second)._p_partkey258;
                int64_t _avgl_quantity1673 = tbl_Aggregate_TD_3446_output.getInt64(i, 0);
                int32_t _l_partkey781723 = tbl_Aggregate_TD_3446_output.getInt32(i, 1);
                if (_l_quantity81 < _avgl_quantity1673) {
                    tbl_JOIN_INNER_TD_1700_output.setInt32(r, 0, _l_extendedprice82);
                    r++;
                }
                it++;
            }
        }
        tbl_JOIN_INNER_TD_1700_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_1700_key_rightMajor, SW_JOIN_INNER_TD_1700_payload_rightMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_3446_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _l_partkey781723_k = tbl_Aggregate_TD_3446_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_1700_key_rightMajor keyA{_l_partkey781723_k};
            int64_t _avgl_quantity1673 = tbl_Aggregate_TD_3446_output.getInt64(i, 0);
            int32_t _l_partkey781723 = tbl_Aggregate_TD_3446_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_1700_payload_rightMajor payloadA{_avgl_quantity1673, _l_partkey781723};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
    for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
        int nrow2 = tbl_JOIN_INNER_TD_2677_output[p_idx].getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _p_partkey258_k = tbl_JOIN_INNER_TD_2677_output[p_idx].getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_1700_key_rightMajor{_p_partkey258_k});
            auto it = its.first;
            while (it != its.second) {
                int64_t _avgl_quantity1673 = (it->second)._avgl_quantity1673;
                int32_t _l_partkey781723 = (it->second)._l_partkey781723;
                int32_t _l_quantity81 = tbl_JOIN_INNER_TD_2677_output[p_idx].getInt32(i, 0);
                int32_t _l_extendedprice82 = tbl_JOIN_INNER_TD_2677_output[p_idx].getInt32(i, 1);
                int32_t _p_partkey258 = tbl_JOIN_INNER_TD_2677_output[p_idx].getInt32(i, 2);
                if (_l_quantity81 < _avgl_quantity1673) {
                    tbl_JOIN_INNER_TD_1700_output.setInt32(r, 0, _l_extendedprice82);
                    r++;
                }
                it++;
            }
        }
    }
        tbl_JOIN_INNER_TD_1700_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_1700_output #Row: " << tbl_JOIN_INNER_TD_1700_output.getNumRow() << std::endl;
}

void SW_Aggregate_TD_0696(Table &tbl_JOIN_INNER_TD_1700_output, Table &tbl_Aggregate_TD_0696_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(CheckOverflow((promote_precision(cast(cast(sum(l_extendedprice#82) as decimal(20,0)) as decimal(21,1))) / 7.0), DecimalType(27,6), true) AS avg_yearly#1670)
    // Input: ListBuffer(l_extendedprice#82)
    // Output: ListBuffer(avg_yearly#1670)
    int64_t sum_0 = 0;
    int nrow1 = tbl_JOIN_INNER_TD_1700_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _l_extendedprice82 = tbl_JOIN_INNER_TD_1700_output.getInt32(i, 0);
        int64_t _avg_yearly1670_sum_0 = _l_extendedprice82;
        sum_0 += _avg_yearly1670_sum_0;
    }
    int r = 0;
    int64_t _avg_yearly1670 = (sum_0 / 7.0);
    tbl_Aggregate_TD_0696_output.setInt64(r++, 0, _avg_yearly1670);
    tbl_Aggregate_TD_0696_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_0696_output #Row: " << tbl_Aggregate_TD_0696_output.getNumRow() << std::endl;
}

