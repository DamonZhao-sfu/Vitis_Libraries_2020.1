#include <regex> 
#include <stdint.h> 

void SW_Filter_TD_8820(Table &tbl_SerializeFromObject_TD_9414_input, Table &tbl_Filter_TD_8820_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(r_name#175) AND (r_name#175 = AMERICA)))
    // Input: ListBuffer(r_regionkey#174, r_name#175)
    // Output: ListBuffer(r_regionkey#174)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_9414_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_REGION_LEN + 1> _r_name175 = tbl_SerializeFromObject_TD_9414_input.getcharN<char, TPCH_READ_REGION_LEN + 1>(i, 1);
        if ((1) && (std::string(_r_name175.data()) == "AMERICA")) {
            int32_t _r_regionkey174_t = tbl_SerializeFromObject_TD_9414_input.getInt32(i, 0);
            tbl_Filter_TD_8820_output.setInt32(r, 0, _r_regionkey174_t);
            r++;
        }
    }
    tbl_Filter_TD_8820_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_8820_output #Row: " << tbl_Filter_TD_8820_output.getNumRow() << std::endl;
}




void SW_Filter_TD_616(Table &tbl_SerializeFromObject_TD_7652_input, Table &tbl_Filter_TD_616_output) {
    // StringRowIDSubstitution: true StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(p_type#262) AND ((p_size#263 = 19) AND EndsWith(p_type#262, NICKEL))))
    // Input: ListBuffer(p_partkey#258, p_mfgr#260, p_type#262, p_size#263)
    // Output: ListBuffer(p_partkey#258, p_mfgr#260)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_7652_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCH_READ_P_TYPE_LEN + 1> _p_type262 = tbl_SerializeFromObject_TD_7652_input.getcharN<char, TPCH_READ_P_TYPE_LEN + 1>(i, 2);
        int32_t _p_size263 = tbl_SerializeFromObject_TD_7652_input.getInt32(i, 3);
        if ((1) && ((_p_size263 == 19) && (std::string(_p_type262.data()).find("NICKEL")==std::string(_p_type262.data()).length() - 6))) {
            int32_t _p_partkey258_t = tbl_SerializeFromObject_TD_7652_input.getInt32(i, 0);
            tbl_Filter_TD_616_output.setInt32(r, 0, _p_partkey258_t);
            tbl_Filter_TD_616_output.setInt32(r, 1, i);
            r++;
        }
    }
    tbl_Filter_TD_616_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_616_output #Row: " << tbl_Filter_TD_616_output.getNumRow() << std::endl;
}


typedef int32_t SW_Aggregate_TD_6211_key;
struct SW_Aggregate_TD_6211_payload {
    int32_t _minps_supplycost579_min_0;
    int32_t _ps_partkey305675;
};
void SW_Aggregate_TD_6211(Table *tbl_JOIN_INNER_TD_586_output, Table &tbl_Aggregate_TD_6211_output, int hpTimes) {
    // StringRowIDSubstitution: true StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(ps_partkey#305, min(ps_supplycost#308) AS min(ps_supplycost)#579, ps_partkey#305 AS ps_partkey#305#675)
    // Input: ListBuffer(p_partkey#258, p_mfgr#260, ps_suppkey#306, ps_supplycost#308, ps_partkey#305)
    // Output: ListBuffer(min(ps_supplycost)#579, ps_partkey#305#675)
    std::unordered_map<SW_Aggregate_TD_6211_key, SW_Aggregate_TD_6211_payload> ht1;
for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
    int nrow1 = tbl_JOIN_INNER_TD_586_output[p_idx].getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _p_partkey258 = tbl_JOIN_INNER_TD_586_output[p_idx].getInt32(i, 0);
        int32_t _p_mfgr260 = tbl_JOIN_INNER_TD_586_output[p_idx].getInt32(i, 1);
        int32_t _ps_suppkey306 = tbl_JOIN_INNER_TD_586_output[p_idx].getInt32(i, 2);
        int32_t _ps_supplycost308 = tbl_JOIN_INNER_TD_586_output[p_idx].getInt32(i, 3);
        int32_t _ps_partkey305 = tbl_JOIN_INNER_TD_586_output[p_idx].getInt32(i, 4);
        SW_Aggregate_TD_6211_key k = _ps_partkey305;
        int32_t _minps_supplycost579_min_0 = _ps_supplycost308;
        int32_t _ps_partkey305675 = _ps_partkey305;
        SW_Aggregate_TD_6211_payload p{_minps_supplycost579_min_0, _ps_partkey305675};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int32_t min_0 = (it->second)._minps_supplycost579_min_0 > _minps_supplycost579_min_0 ? _minps_supplycost579_min_0 : (it->second)._minps_supplycost579_min_0;
            p._minps_supplycost579_min_0 = min_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
}
    int r = 0;
    for (auto& it : ht1) {
        // _ps_partkey305 not required in the output table
        int32_t _minps_supplycost579 = (it.second)._minps_supplycost579_min_0;
        tbl_Aggregate_TD_6211_output.setInt32(r, 0, _minps_supplycost579);
        tbl_Aggregate_TD_6211_output.setInt32(r, 1, (it.second)._ps_partkey305675);
        ++r;
    }
    tbl_Aggregate_TD_6211_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_6211_output #Row: " << tbl_Aggregate_TD_6211_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4801_key_leftMajor {
    int32_t _ps_supplycost308;
    int32_t _p_partkey258;
    bool operator==(const SW_JOIN_INNER_TD_4801_key_leftMajor& other) const {
        return ((_ps_supplycost308 == other._ps_supplycost308) && (_p_partkey258 == other._p_partkey258));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4801_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4801_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ps_supplycost308)) + (hash<int32_t>()(k._p_partkey258));
    }
};
}
struct SW_JOIN_INNER_TD_4801_payload_leftMajor {
    int32_t _p_partkey258;
    int32_t _p_mfgr260;
    int32_t _ps_suppkey306;
    int32_t _ps_supplycost308;
    int32_t _ps_partkey305;
};
struct SW_JOIN_INNER_TD_4801_key_rightMajor {
    int32_t _minps_supplycost579;
    int32_t _ps_partkey305675;
    bool operator==(const SW_JOIN_INNER_TD_4801_key_rightMajor& other) const {
        return ((_minps_supplycost579 == other._minps_supplycost579) && (_ps_partkey305675 == other._ps_partkey305675));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4801_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4801_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._minps_supplycost579)) + (hash<int32_t>()(k._ps_partkey305675));
    }
};
}
struct SW_JOIN_INNER_TD_4801_payload_rightMajor {
    int32_t _minps_supplycost579;
    int32_t _ps_partkey305675;
};
void SW_JOIN_INNER_TD_4801(Table *tbl_JOIN_INNER_TD_586_output, Table &tbl_Aggregate_TD_6211_output, Table &tbl_JOIN_INNER_TD_4801_output, int hpTimes) {
    // StringRowIDSubstitution: true StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer(((ps_supplycost#308 = min(ps_supplycost)#579) AND (p_partkey#258 = ps_partkey#305#675)))
    // Left Table: ListBuffer(p_partkey#258, p_mfgr#260, ps_suppkey#306, ps_supplycost#308, ps_partkey#305)
    // Right Table: ListBuffer(min(ps_supplycost)#579, ps_partkey#305#675)
    // Output Table: ListBuffer(p_partkey#258, p_mfgr#260, ps_suppkey#306)
    int left_nrow = tbl_JOIN_INNER_TD_586_output[0].getNumRow();
    int right_nrow = tbl_Aggregate_TD_6211_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4801_key_leftMajor, SW_JOIN_INNER_TD_4801_payload_leftMajor> ht1;
    for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
        int nrow1 = tbl_JOIN_INNER_TD_586_output[p_idx].getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ps_supplycost308_k = tbl_JOIN_INNER_TD_586_output[p_idx].getInt32(i, 3);
            int32_t _p_partkey258_k = tbl_JOIN_INNER_TD_586_output[p_idx].getInt32(i, 0);
            SW_JOIN_INNER_TD_4801_key_leftMajor keyA{_ps_supplycost308_k, _p_partkey258_k};
            int32_t _p_partkey258 = tbl_JOIN_INNER_TD_586_output[p_idx].getInt32(i, 0);
            int32_t _p_mfgr260 = tbl_JOIN_INNER_TD_586_output[p_idx].getInt32(i, 1);
            int32_t _ps_suppkey306 = tbl_JOIN_INNER_TD_586_output[p_idx].getInt32(i, 2);
            int32_t _ps_supplycost308 = tbl_JOIN_INNER_TD_586_output[p_idx].getInt32(i, 3);
            int32_t _ps_partkey305 = tbl_JOIN_INNER_TD_586_output[p_idx].getInt32(i, 4);
            SW_JOIN_INNER_TD_4801_payload_leftMajor payloadA{_p_partkey258, _p_mfgr260, _ps_suppkey306, _ps_supplycost308, _ps_partkey305};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
    }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_6211_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _minps_supplycost579_k = tbl_Aggregate_TD_6211_output.getInt32(i, 0);
            int32_t _ps_partkey305675_k = tbl_Aggregate_TD_6211_output.getInt32(i, 1);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4801_key_leftMajor{_minps_supplycost579_k, _ps_partkey305675_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _p_partkey258 = (it->second)._p_partkey258;
                int32_t _p_mfgr260 = (it->second)._p_mfgr260;
                int32_t _ps_suppkey306 = (it->second)._ps_suppkey306;
                int32_t _ps_supplycost308 = (it->second)._ps_supplycost308;
                int32_t _ps_partkey305 = (it->second)._ps_partkey305;
                int32_t _minps_supplycost579 = tbl_Aggregate_TD_6211_output.getInt32(i, 0);
                int32_t _ps_partkey305675 = tbl_Aggregate_TD_6211_output.getInt32(i, 1);
                tbl_JOIN_INNER_TD_4801_output.setInt32(r, 0, _p_partkey258);
                tbl_JOIN_INNER_TD_4801_output.setInt32(r, 1, _p_mfgr260);
                tbl_JOIN_INNER_TD_4801_output.setInt32(r, 2, _ps_suppkey306);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4801_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4801_key_rightMajor, SW_JOIN_INNER_TD_4801_payload_rightMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_6211_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _minps_supplycost579_k = tbl_Aggregate_TD_6211_output.getInt32(i, 0);
            int32_t _ps_partkey305675_k = tbl_Aggregate_TD_6211_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_4801_key_rightMajor keyA{_minps_supplycost579_k, _ps_partkey305675_k};
            int32_t _minps_supplycost579 = tbl_Aggregate_TD_6211_output.getInt32(i, 0);
            int32_t _ps_partkey305675 = tbl_Aggregate_TD_6211_output.getInt32(i, 1);
            SW_JOIN_INNER_TD_4801_payload_rightMajor payloadA{_minps_supplycost579, _ps_partkey305675};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
    for (int p_idx = 0; p_idx < hpTimes; p_idx++) {
        int nrow2 = tbl_JOIN_INNER_TD_586_output[p_idx].getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ps_supplycost308_k = tbl_JOIN_INNER_TD_586_output[p_idx].getInt32(i, 3);
            int32_t _p_partkey258_k = tbl_JOIN_INNER_TD_586_output[p_idx].getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4801_key_rightMajor{_ps_supplycost308_k, _p_partkey258_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _minps_supplycost579 = (it->second)._minps_supplycost579;
                int32_t _ps_partkey305675 = (it->second)._ps_partkey305675;
                int32_t _p_partkey258 = tbl_JOIN_INNER_TD_586_output[p_idx].getInt32(i, 0);
                int32_t _p_mfgr260 = tbl_JOIN_INNER_TD_586_output[p_idx].getInt32(i, 1);
                int32_t _ps_suppkey306 = tbl_JOIN_INNER_TD_586_output[p_idx].getInt32(i, 2);
                int32_t _ps_supplycost308 = tbl_JOIN_INNER_TD_586_output[p_idx].getInt32(i, 3);
                int32_t _ps_partkey305 = tbl_JOIN_INNER_TD_586_output[p_idx].getInt32(i, 4);
                tbl_JOIN_INNER_TD_4801_output.setInt32(r, 0, _p_partkey258);
                tbl_JOIN_INNER_TD_4801_output.setInt32(r, 1, _p_mfgr260);
                tbl_JOIN_INNER_TD_4801_output.setInt32(r, 2, _ps_suppkey306);
                it++;
                r++;
            }
        }
    }
        tbl_JOIN_INNER_TD_4801_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4801_output #Row: " << tbl_JOIN_INNER_TD_4801_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_391_key_leftMajor {
    int32_t _ps_suppkey306;
    bool operator==(const SW_JOIN_INNER_TD_391_key_leftMajor& other) const {
        return ((_ps_suppkey306 == other._ps_suppkey306));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_391_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_391_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._ps_suppkey306));
    }
};
}
struct SW_JOIN_INNER_TD_391_payload_leftMajor {
    int32_t _p_partkey258;
    int32_t _p_mfgr260;
    int32_t _ps_suppkey306;
};
struct SW_JOIN_INNER_TD_391_key_rightMajor {
    int32_t _s_suppkey342;
    bool operator==(const SW_JOIN_INNER_TD_391_key_rightMajor& other) const {
        return ((_s_suppkey342 == other._s_suppkey342));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_391_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_391_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_suppkey342));
    }
};
}
struct SW_JOIN_INNER_TD_391_payload_rightMajor {
    int32_t _s_suppkey342;
    int32_t _s_name343;
    int32_t _s_address344;
    int32_t _s_nationkey345;
    int32_t _s_phone346;
    int32_t _s_acctbal347;
    int32_t _s_comment348;
};
void SW_JOIN_INNER_TD_391(Table &tbl_JOIN_INNER_TD_4801_output, Table &tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute, Table &tbl_JOIN_INNER_TD_391_output) {
    // StringRowIDSubstitution: true StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((s_suppkey#342 = ps_suppkey#306))
    // Left Table: ListBuffer(p_partkey#258, p_mfgr#260, ps_suppkey#306)
    // Right Table: ListBuffer(s_suppkey#342, s_name#343, s_address#344, s_nationkey#345, s_phone#346, s_acctbal#347, s_comment#348)
    // Output Table: ListBuffer(p_partkey#258, p_mfgr#260, s_name#343, s_address#344, s_nationkey#345, s_phone#346, s_acctbal#347, s_comment#348)
    int left_nrow = tbl_JOIN_INNER_TD_4801_output.getNumRow();
    int right_nrow = tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_391_key_leftMajor, SW_JOIN_INNER_TD_391_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_4801_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _ps_suppkey306_k = tbl_JOIN_INNER_TD_4801_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_391_key_leftMajor keyA{_ps_suppkey306_k};
            int32_t _p_partkey258 = tbl_JOIN_INNER_TD_4801_output.getInt32(i, 0);
            int32_t _p_mfgr260 = tbl_JOIN_INNER_TD_4801_output.getInt32(i, 1);
            int32_t _ps_suppkey306 = tbl_JOIN_INNER_TD_4801_output.getInt32(i, 2);
            SW_JOIN_INNER_TD_391_payload_leftMajor payloadA{_p_partkey258, _p_mfgr260, _ps_suppkey306};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_suppkey342_k = tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_391_key_leftMajor{_s_suppkey342_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _p_partkey258 = (it->second)._p_partkey258;
                int32_t _p_mfgr260 = (it->second)._p_mfgr260;
                int32_t _ps_suppkey306 = (it->second)._ps_suppkey306;
                int32_t _s_suppkey342 = tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.getInt32(i, 0);
                int32_t _s_name343 = tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.getInt32(i, 1);
                int32_t _s_address344 = tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.getInt32(i, 2);
                int32_t _s_nationkey345 = tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.getInt32(i, 3);
                int32_t _s_phone346 = tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.getInt32(i, 4);
                int32_t _s_acctbal347 = tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.getInt32(i, 5);
                int32_t _s_comment348 = tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.getInt32(i, 6);
                tbl_JOIN_INNER_TD_391_output.setInt32(r, 0, _p_partkey258);
                tbl_JOIN_INNER_TD_391_output.setInt32(r, 1, _p_mfgr260);
                tbl_JOIN_INNER_TD_391_output.setInt32(r, 2, _s_name343);
                tbl_JOIN_INNER_TD_391_output.setInt32(r, 3, _s_address344);
                tbl_JOIN_INNER_TD_391_output.setInt32(r, 4, _s_nationkey345);
                tbl_JOIN_INNER_TD_391_output.setInt32(r, 5, _s_phone346);
                tbl_JOIN_INNER_TD_391_output.setInt32(r, 6, _s_acctbal347);
                tbl_JOIN_INNER_TD_391_output.setInt32(r, 7, _s_comment348);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_391_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_391_key_rightMajor, SW_JOIN_INNER_TD_391_payload_rightMajor> ht1;
        int nrow1 = tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_suppkey342_k = tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.getInt32(i, 0);
            SW_JOIN_INNER_TD_391_key_rightMajor keyA{_s_suppkey342_k};
            int32_t _s_suppkey342 = tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.getInt32(i, 0);
            int32_t _s_name343 = tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.getInt32(i, 1);
            int32_t _s_address344 = tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.getInt32(i, 2);
            int32_t _s_nationkey345 = tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.getInt32(i, 3);
            int32_t _s_phone346 = tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.getInt32(i, 4);
            int32_t _s_acctbal347 = tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.getInt32(i, 5);
            int32_t _s_comment348 = tbl_SerializeFromObject_TD_4939_input_stringRowIDSubstitute.getInt32(i, 6);
            SW_JOIN_INNER_TD_391_payload_rightMajor payloadA{_s_suppkey342, _s_name343, _s_address344, _s_nationkey345, _s_phone346, _s_acctbal347, _s_comment348};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_4801_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _ps_suppkey306_k = tbl_JOIN_INNER_TD_4801_output.getInt32(i, 2);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_391_key_rightMajor{_ps_suppkey306_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _s_suppkey342 = (it->second)._s_suppkey342;
                int32_t _s_name343 = (it->second)._s_name343;
                int32_t _s_address344 = (it->second)._s_address344;
                int32_t _s_nationkey345 = (it->second)._s_nationkey345;
                int32_t _s_phone346 = (it->second)._s_phone346;
                int32_t _s_acctbal347 = (it->second)._s_acctbal347;
                int32_t _s_comment348 = (it->second)._s_comment348;
                int32_t _p_partkey258 = tbl_JOIN_INNER_TD_4801_output.getInt32(i, 0);
                int32_t _p_mfgr260 = tbl_JOIN_INNER_TD_4801_output.getInt32(i, 1);
                int32_t _ps_suppkey306 = tbl_JOIN_INNER_TD_4801_output.getInt32(i, 2);
                tbl_JOIN_INNER_TD_391_output.setInt32(r, 2, _s_name343);
                tbl_JOIN_INNER_TD_391_output.setInt32(r, 3, _s_address344);
                tbl_JOIN_INNER_TD_391_output.setInt32(r, 4, _s_nationkey345);
                tbl_JOIN_INNER_TD_391_output.setInt32(r, 5, _s_phone346);
                tbl_JOIN_INNER_TD_391_output.setInt32(r, 6, _s_acctbal347);
                tbl_JOIN_INNER_TD_391_output.setInt32(r, 7, _s_comment348);
                tbl_JOIN_INNER_TD_391_output.setInt32(r, 0, _p_partkey258);
                tbl_JOIN_INNER_TD_391_output.setInt32(r, 1, _p_mfgr260);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_391_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_391_output #Row: " << tbl_JOIN_INNER_TD_391_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_2303_key_leftMajor {
    int32_t _s_nationkey345;
    bool operator==(const SW_JOIN_INNER_TD_2303_key_leftMajor& other) const {
        return ((_s_nationkey345 == other._s_nationkey345));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_2303_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_2303_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._s_nationkey345));
    }
};
}
struct SW_JOIN_INNER_TD_2303_payload_leftMajor {
    int32_t _p_partkey258;
    int32_t _p_mfgr260;
    int32_t _s_name343;
    int32_t _s_address344;
    int32_t _s_nationkey345;
    int32_t _s_phone346;
    int32_t _s_acctbal347;
    int32_t _s_comment348;
};
struct SW_JOIN_INNER_TD_2303_key_rightMajor {
    int32_t _n_nationkey144;
    bool operator==(const SW_JOIN_INNER_TD_2303_key_rightMajor& other) const {
        return ((_n_nationkey144 == other._n_nationkey144));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_2303_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_2303_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._n_nationkey144));
    }
};
}
struct SW_JOIN_INNER_TD_2303_payload_rightMajor {
    int32_t _n_nationkey144;
    int32_t _n_name145;
    int32_t _n_regionkey146;
};
void SW_JOIN_INNER_TD_2303(Table &tbl_JOIN_INNER_TD_391_output, Table &tbl_SerializeFromObject_TD_3496_input_stringRowIDSubstitute, Table &tbl_JOIN_INNER_TD_2303_output) {
    // StringRowIDSubstitution: true StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((s_nationkey#345 = n_nationkey#144))
    // Left Table: ListBuffer(p_partkey#258, p_mfgr#260, s_name#343, s_address#344, s_nationkey#345, s_phone#346, s_acctbal#347, s_comment#348)
    // Right Table: ListBuffer(n_nationkey#144, n_name#145, n_regionkey#146)
    // Output Table: ListBuffer(p_partkey#258, p_mfgr#260, s_name#343, s_address#344, s_phone#346, s_acctbal#347, s_comment#348, n_name#145, n_regionkey#146)
    int left_nrow = tbl_JOIN_INNER_TD_391_output.getNumRow();
    int right_nrow = tbl_SerializeFromObject_TD_3496_input_stringRowIDSubstitute.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_2303_key_leftMajor, SW_JOIN_INNER_TD_2303_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_391_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _s_nationkey345_k = tbl_JOIN_INNER_TD_391_output.getInt32(i, 4);
            SW_JOIN_INNER_TD_2303_key_leftMajor keyA{_s_nationkey345_k};
            int32_t _p_partkey258 = tbl_JOIN_INNER_TD_391_output.getInt32(i, 0);
            int32_t _p_mfgr260 = tbl_JOIN_INNER_TD_391_output.getInt32(i, 1);
            int32_t _s_name343 = tbl_JOIN_INNER_TD_391_output.getInt32(i, 2);
            int32_t _s_address344 = tbl_JOIN_INNER_TD_391_output.getInt32(i, 3);
            int32_t _s_nationkey345 = tbl_JOIN_INNER_TD_391_output.getInt32(i, 4);
            int32_t _s_phone346 = tbl_JOIN_INNER_TD_391_output.getInt32(i, 5);
            int32_t _s_acctbal347 = tbl_JOIN_INNER_TD_391_output.getInt32(i, 6);
            int32_t _s_comment348 = tbl_JOIN_INNER_TD_391_output.getInt32(i, 7);
            SW_JOIN_INNER_TD_2303_payload_leftMajor payloadA{_p_partkey258, _p_mfgr260, _s_name343, _s_address344, _s_nationkey345, _s_phone346, _s_acctbal347, _s_comment348};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_SerializeFromObject_TD_3496_input_stringRowIDSubstitute.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _n_nationkey144_k = tbl_SerializeFromObject_TD_3496_input_stringRowIDSubstitute.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_2303_key_leftMajor{_n_nationkey144_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _p_partkey258 = (it->second)._p_partkey258;
                int32_t _p_mfgr260 = (it->second)._p_mfgr260;
                int32_t _s_name343 = (it->second)._s_name343;
                int32_t _s_address344 = (it->second)._s_address344;
                int32_t _s_nationkey345 = (it->second)._s_nationkey345;
                int32_t _s_phone346 = (it->second)._s_phone346;
                int32_t _s_acctbal347 = (it->second)._s_acctbal347;
                int32_t _s_comment348 = (it->second)._s_comment348;
                int32_t _n_nationkey144 = tbl_SerializeFromObject_TD_3496_input_stringRowIDSubstitute.getInt32(i, 0);
                int32_t _n_name145 = tbl_SerializeFromObject_TD_3496_input_stringRowIDSubstitute.getInt32(i, 1);
                int32_t _n_regionkey146 = tbl_SerializeFromObject_TD_3496_input_stringRowIDSubstitute.getInt32(i, 2);
                tbl_JOIN_INNER_TD_2303_output.setInt32(r, 0, _p_partkey258);
                tbl_JOIN_INNER_TD_2303_output.setInt32(r, 1, _p_mfgr260);
                tbl_JOIN_INNER_TD_2303_output.setInt32(r, 2, _s_name343);
                tbl_JOIN_INNER_TD_2303_output.setInt32(r, 3, _s_address344);
                tbl_JOIN_INNER_TD_2303_output.setInt32(r, 4, _s_phone346);
                tbl_JOIN_INNER_TD_2303_output.setInt32(r, 5, _s_acctbal347);
                tbl_JOIN_INNER_TD_2303_output.setInt32(r, 6, _s_comment348);
                tbl_JOIN_INNER_TD_2303_output.setInt32(r, 7, _n_name145);
                tbl_JOIN_INNER_TD_2303_output.setInt32(r, 8, _n_regionkey146);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_2303_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_2303_key_rightMajor, SW_JOIN_INNER_TD_2303_payload_rightMajor> ht1;
        int nrow1 = tbl_SerializeFromObject_TD_3496_input_stringRowIDSubstitute.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _n_nationkey144_k = tbl_SerializeFromObject_TD_3496_input_stringRowIDSubstitute.getInt32(i, 0);
            SW_JOIN_INNER_TD_2303_key_rightMajor keyA{_n_nationkey144_k};
            int32_t _n_nationkey144 = tbl_SerializeFromObject_TD_3496_input_stringRowIDSubstitute.getInt32(i, 0);
            int32_t _n_name145 = tbl_SerializeFromObject_TD_3496_input_stringRowIDSubstitute.getInt32(i, 1);
            int32_t _n_regionkey146 = tbl_SerializeFromObject_TD_3496_input_stringRowIDSubstitute.getInt32(i, 2);
            SW_JOIN_INNER_TD_2303_payload_rightMajor payloadA{_n_nationkey144, _n_name145, _n_regionkey146};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_391_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _s_nationkey345_k = tbl_JOIN_INNER_TD_391_output.getInt32(i, 4);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_2303_key_rightMajor{_s_nationkey345_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _n_nationkey144 = (it->second)._n_nationkey144;
                int32_t _n_name145 = (it->second)._n_name145;
                int32_t _n_regionkey146 = (it->second)._n_regionkey146;
                int32_t _p_partkey258 = tbl_JOIN_INNER_TD_391_output.getInt32(i, 0);
                int32_t _p_mfgr260 = tbl_JOIN_INNER_TD_391_output.getInt32(i, 1);
                int32_t _s_name343 = tbl_JOIN_INNER_TD_391_output.getInt32(i, 2);
                int32_t _s_address344 = tbl_JOIN_INNER_TD_391_output.getInt32(i, 3);
                int32_t _s_nationkey345 = tbl_JOIN_INNER_TD_391_output.getInt32(i, 4);
                int32_t _s_phone346 = tbl_JOIN_INNER_TD_391_output.getInt32(i, 5);
                int32_t _s_acctbal347 = tbl_JOIN_INNER_TD_391_output.getInt32(i, 6);
                int32_t _s_comment348 = tbl_JOIN_INNER_TD_391_output.getInt32(i, 7);
                tbl_JOIN_INNER_TD_2303_output.setInt32(r, 7, _n_name145);
                tbl_JOIN_INNER_TD_2303_output.setInt32(r, 8, _n_regionkey146);
                tbl_JOIN_INNER_TD_2303_output.setInt32(r, 0, _p_partkey258);
                tbl_JOIN_INNER_TD_2303_output.setInt32(r, 1, _p_mfgr260);
                tbl_JOIN_INNER_TD_2303_output.setInt32(r, 2, _s_name343);
                tbl_JOIN_INNER_TD_2303_output.setInt32(r, 3, _s_address344);
                tbl_JOIN_INNER_TD_2303_output.setInt32(r, 4, _s_phone346);
                tbl_JOIN_INNER_TD_2303_output.setInt32(r, 5, _s_acctbal347);
                tbl_JOIN_INNER_TD_2303_output.setInt32(r, 6, _s_comment348);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_2303_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_2303_output #Row: " << tbl_JOIN_INNER_TD_2303_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_1293_key_leftMajor {
    int32_t _n_regionkey146;
    bool operator==(const SW_JOIN_INNER_TD_1293_key_leftMajor& other) const {
        return ((_n_regionkey146 == other._n_regionkey146));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_1293_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_1293_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._n_regionkey146));
    }
};
}
struct SW_JOIN_INNER_TD_1293_payload_leftMajor {
    int32_t _p_partkey258;
    int32_t _p_mfgr260;
    int32_t _s_name343;
    int32_t _s_address344;
    int32_t _s_phone346;
    int32_t _s_acctbal347;
    int32_t _s_comment348;
    int32_t _n_name145;
    int32_t _n_regionkey146;
};
struct SW_JOIN_INNER_TD_1293_key_rightMajor {
    int32_t _r_regionkey174;
    bool operator==(const SW_JOIN_INNER_TD_1293_key_rightMajor& other) const {
        return ((_r_regionkey174 == other._r_regionkey174));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_1293_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_1293_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._r_regionkey174));
    }
};
}
struct SW_JOIN_INNER_TD_1293_payload_rightMajor {
    int32_t _r_regionkey174;
};
void SW_JOIN_INNER_TD_1293(Table &tbl_JOIN_INNER_TD_2303_output, Table &tbl_Filter_TD_8820_output, Table &tbl_JOIN_INNER_TD_1293_output) {
    // StringRowIDSubstitution: true StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((n_regionkey#146 = r_regionkey#174))
    // Left Table: ListBuffer(p_partkey#258, p_mfgr#260, s_name#343, s_address#344, s_phone#346, s_acctbal#347, s_comment#348, n_name#145, n_regionkey#146)
    // Right Table: ListBuffer(r_regionkey#174)
    // Output Table: ListBuffer(s_acctbal#347, s_name#343, n_name#145, p_partkey#258, p_mfgr#260, s_address#344, s_phone#346, s_comment#348)
    int left_nrow = tbl_JOIN_INNER_TD_2303_output.getNumRow();
    int right_nrow = tbl_Filter_TD_8820_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_1293_key_leftMajor, SW_JOIN_INNER_TD_1293_payload_leftMajor> ht1;
        int nrow1 = tbl_JOIN_INNER_TD_2303_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _n_regionkey146_k = tbl_JOIN_INNER_TD_2303_output.getInt32(i, 8);
            SW_JOIN_INNER_TD_1293_key_leftMajor keyA{_n_regionkey146_k};
            int32_t _p_partkey258 = tbl_JOIN_INNER_TD_2303_output.getInt32(i, 0);
            int32_t _p_mfgr260 = tbl_JOIN_INNER_TD_2303_output.getInt32(i, 1);
            int32_t _s_name343 = tbl_JOIN_INNER_TD_2303_output.getInt32(i, 2);
            int32_t _s_address344 = tbl_JOIN_INNER_TD_2303_output.getInt32(i, 3);
            int32_t _s_phone346 = tbl_JOIN_INNER_TD_2303_output.getInt32(i, 4);
            int32_t _s_acctbal347 = tbl_JOIN_INNER_TD_2303_output.getInt32(i, 5);
            int32_t _s_comment348 = tbl_JOIN_INNER_TD_2303_output.getInt32(i, 6);
            int32_t _n_name145 = tbl_JOIN_INNER_TD_2303_output.getInt32(i, 7);
            int32_t _n_regionkey146 = tbl_JOIN_INNER_TD_2303_output.getInt32(i, 8);
            SW_JOIN_INNER_TD_1293_payload_leftMajor payloadA{_p_partkey258, _p_mfgr260, _s_name343, _s_address344, _s_phone346, _s_acctbal347, _s_comment348, _n_name145, _n_regionkey146};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_8820_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _r_regionkey174_k = tbl_Filter_TD_8820_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_1293_key_leftMajor{_r_regionkey174_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _p_partkey258 = (it->second)._p_partkey258;
                int32_t _p_mfgr260 = (it->second)._p_mfgr260;
                int32_t _s_name343 = (it->second)._s_name343;
                int32_t _s_address344 = (it->second)._s_address344;
                int32_t _s_phone346 = (it->second)._s_phone346;
                int32_t _s_acctbal347 = (it->second)._s_acctbal347;
                int32_t _s_comment348 = (it->second)._s_comment348;
                int32_t _n_name145 = (it->second)._n_name145;
                int32_t _n_regionkey146 = (it->second)._n_regionkey146;
                int32_t _r_regionkey174 = tbl_Filter_TD_8820_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_1293_output.setInt32(r, 3, _p_partkey258);
                tbl_JOIN_INNER_TD_1293_output.setInt32(r, 4, _p_mfgr260);
                tbl_JOIN_INNER_TD_1293_output.setInt32(r, 1, _s_name343);
                tbl_JOIN_INNER_TD_1293_output.setInt32(r, 5, _s_address344);
                tbl_JOIN_INNER_TD_1293_output.setInt32(r, 6, _s_phone346);
                tbl_JOIN_INNER_TD_1293_output.setInt32(r, 0, _s_acctbal347);
                tbl_JOIN_INNER_TD_1293_output.setInt32(r, 7, _s_comment348);
                tbl_JOIN_INNER_TD_1293_output.setInt32(r, 2, _n_name145);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_1293_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_1293_key_rightMajor, SW_JOIN_INNER_TD_1293_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_8820_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _r_regionkey174_k = tbl_Filter_TD_8820_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_1293_key_rightMajor keyA{_r_regionkey174_k};
            int32_t _r_regionkey174 = tbl_Filter_TD_8820_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_1293_payload_rightMajor payloadA{_r_regionkey174};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_JOIN_INNER_TD_2303_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _n_regionkey146_k = tbl_JOIN_INNER_TD_2303_output.getInt32(i, 8);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_1293_key_rightMajor{_n_regionkey146_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _r_regionkey174 = (it->second)._r_regionkey174;
                int32_t _p_partkey258 = tbl_JOIN_INNER_TD_2303_output.getInt32(i, 0);
                int32_t _p_mfgr260 = tbl_JOIN_INNER_TD_2303_output.getInt32(i, 1);
                int32_t _s_name343 = tbl_JOIN_INNER_TD_2303_output.getInt32(i, 2);
                int32_t _s_address344 = tbl_JOIN_INNER_TD_2303_output.getInt32(i, 3);
                int32_t _s_phone346 = tbl_JOIN_INNER_TD_2303_output.getInt32(i, 4);
                int32_t _s_acctbal347 = tbl_JOIN_INNER_TD_2303_output.getInt32(i, 5);
                int32_t _s_comment348 = tbl_JOIN_INNER_TD_2303_output.getInt32(i, 6);
                int32_t _n_name145 = tbl_JOIN_INNER_TD_2303_output.getInt32(i, 7);
                int32_t _n_regionkey146 = tbl_JOIN_INNER_TD_2303_output.getInt32(i, 8);
                tbl_JOIN_INNER_TD_1293_output.setInt32(r, 3, _p_partkey258);
                tbl_JOIN_INNER_TD_1293_output.setInt32(r, 4, _p_mfgr260);
                tbl_JOIN_INNER_TD_1293_output.setInt32(r, 1, _s_name343);
                tbl_JOIN_INNER_TD_1293_output.setInt32(r, 5, _s_address344);
                tbl_JOIN_INNER_TD_1293_output.setInt32(r, 6, _s_phone346);
                tbl_JOIN_INNER_TD_1293_output.setInt32(r, 0, _s_acctbal347);
                tbl_JOIN_INNER_TD_1293_output.setInt32(r, 7, _s_comment348);
                tbl_JOIN_INNER_TD_1293_output.setInt32(r, 2, _n_name145);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_1293_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_1293_output #Row: " << tbl_JOIN_INNER_TD_1293_output.getNumRow() << std::endl;
}

void SW_Sort_TD_0435(Table &tbl_JOIN_INNER_TD_1293_output, Table &tbl_SerializeFromObject_TD_7652_input, Table &tbl_SerializeFromObject_TD_4939_input, Table &tbl_SerializeFromObject_TD_3496_input, Table &tbl_Sort_TD_0435_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: true
    // Supported operation: Sort
    // Operation: ListBuffer(s_acctbal#347 DESC NULLS LAST, n_name#145 ASC NULLS FIRST, s_name#343 ASC NULLS FIRST, p_partkey#258 ASC NULLS FIRST)
    // Input: ListBuffer(s_acctbal#347, s_name#343, n_name#145, p_partkey#258, p_mfgr#260, s_address#344, s_phone#346, s_comment#348)
    // Output: ListBuffer(s_acctbal#347, s_name#343, n_name#145, p_partkey#258, p_mfgr#260, s_address#344, s_phone#346, s_comment#348)
    struct SW_Sort_TD_0435Row {
        int32_t _s_acctbal347;
        std::string _s_name343;
        std::string _n_name145;
        int32_t _p_partkey258;
        std::string _p_mfgr260;
        std::string _s_address344;
        std::string _s_phone346;
        std::string _s_comment348;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_0435Row& a, const SW_Sort_TD_0435Row& b) const { return 
 (a._s_acctbal347 > b._s_acctbal347) || 
 ((a._s_acctbal347 == b._s_acctbal347) && (a._n_name145 < b._n_name145)) || 
 ((a._s_acctbal347 == b._s_acctbal347) && (a._n_name145 == b._n_name145) && (a._s_name343 < b._s_name343)) || 
 ((a._s_acctbal347 == b._s_acctbal347) && (a._n_name145 == b._n_name145) && (a._s_name343 == b._s_name343) && (a._p_partkey258 < b._p_partkey258)); 
}
    }SW_Sort_TD_0435_order; 

    int nrow1 = tbl_JOIN_INNER_TD_1293_output.getNumRow();
    std::vector<SW_Sort_TD_0435Row> rows;
    for (int i = 0; i < nrow1; i++) {
        int32_t _s_acctbal347 = tbl_JOIN_INNER_TD_1293_output.getInt32(i, 0);
        std::array<char, TPCH_READ_S_NAME_LEN + 1> _s_name343 = tbl_SerializeFromObject_TD_4939_input.getcharN<char, TPCH_READ_S_NAME_LEN + 1>(tbl_JOIN_INNER_TD_1293_output.getInt32(i, 1), 1);
        std::array<char, TPCH_READ_NATION_LEN + 1> _n_name145 = tbl_SerializeFromObject_TD_3496_input.getcharN<char, TPCH_READ_NATION_LEN + 1>(tbl_JOIN_INNER_TD_1293_output.getInt32(i, 2), 1);
        int32_t _p_partkey258 = tbl_JOIN_INNER_TD_1293_output.getInt32(i, 3);
        std::array<char, TPCH_READ_P_MFG_LEN + 1> _p_mfgr260 = tbl_SerializeFromObject_TD_7652_input.getcharN<char, TPCH_READ_P_MFG_LEN + 1>(tbl_JOIN_INNER_TD_1293_output.getInt32(i, 4), 1);
        std::array<char, TPCH_READ_S_ADDR_MAX + 1> _s_address344 = tbl_SerializeFromObject_TD_4939_input.getcharN<char, TPCH_READ_S_ADDR_MAX + 1>(tbl_JOIN_INNER_TD_1293_output.getInt32(i, 5), 2);
        std::array<char, TPCH_READ_PHONE_LEN + 1> _s_phone346 = tbl_SerializeFromObject_TD_4939_input.getcharN<char, TPCH_READ_PHONE_LEN + 1>(tbl_JOIN_INNER_TD_1293_output.getInt32(i, 6), 4);
        std::array<char, TPCH_READ_S_CMNT_MAX + 1> _s_comment348 = tbl_SerializeFromObject_TD_4939_input.getcharN<char, TPCH_READ_S_CMNT_MAX + 1>(tbl_JOIN_INNER_TD_1293_output.getInt32(i, 7), 6);
        SW_Sort_TD_0435Row t = {_s_acctbal347,std::string(_s_name343.data()),std::string(_n_name145.data()),_p_partkey258,std::string(_p_mfgr260.data()),std::string(_s_address344.data()),std::string(_s_phone346.data()),std::string(_s_comment348.data())};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_0435_order);
    int r = 0;
    for (auto& it : rows) {
        tbl_Sort_TD_0435_output.setInt32(r, 0, it._s_acctbal347);
        std::array<char, TPCH_READ_S_NAME_LEN + 1> _s_name343{};
        memcpy(_s_name343.data(), (it._s_name343).data(), (it._s_name343).length());
        tbl_Sort_TD_0435_output.setcharN<char, TPCH_READ_S_NAME_LEN +1>(r, 1, _s_name343);
        std::array<char, TPCH_READ_NATION_LEN + 1> _n_name145{};
        memcpy(_n_name145.data(), (it._n_name145).data(), (it._n_name145).length());
        tbl_Sort_TD_0435_output.setcharN<char, TPCH_READ_NATION_LEN +1>(r, 2, _n_name145);
        tbl_Sort_TD_0435_output.setInt32(r, 3, it._p_partkey258);
        std::array<char, TPCH_READ_P_MFG_LEN + 1> _p_mfgr260{};
        memcpy(_p_mfgr260.data(), (it._p_mfgr260).data(), (it._p_mfgr260).length());
        tbl_Sort_TD_0435_output.setcharN<char, TPCH_READ_P_MFG_LEN +1>(r, 4, _p_mfgr260);
        std::array<char, TPCH_READ_S_ADDR_MAX + 1> _s_address344{};
        memcpy(_s_address344.data(), (it._s_address344).data(), (it._s_address344).length());
        tbl_Sort_TD_0435_output.setcharN<char, TPCH_READ_S_ADDR_MAX +1>(r, 5, _s_address344);
        std::array<char, TPCH_READ_PHONE_LEN + 1> _s_phone346{};
        memcpy(_s_phone346.data(), (it._s_phone346).data(), (it._s_phone346).length());
        tbl_Sort_TD_0435_output.setcharN<char, TPCH_READ_PHONE_LEN +1>(r, 6, _s_phone346);
        std::array<char, TPCH_READ_S_CMNT_MAX + 1> _s_comment348{};
        memcpy(_s_comment348.data(), (it._s_comment348).data(), (it._s_comment348).length());
        tbl_Sort_TD_0435_output.setcharN<char, TPCH_READ_S_CMNT_MAX +1>(r, 7, _s_comment348);
        if (r < 10) {
            std::cout << it._s_acctbal347 << " " << (it._s_name343).data() << " " << (it._n_name145).data() << " " << it._p_partkey258 << " " << (it._p_mfgr260).data() << " " << (it._s_address344).data() << " " << (it._s_phone346).data() << " " << (it._s_comment348).data() << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_0435_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_0435_output #Row: " << tbl_Sort_TD_0435_output.getNumRow() << std::endl;
}

