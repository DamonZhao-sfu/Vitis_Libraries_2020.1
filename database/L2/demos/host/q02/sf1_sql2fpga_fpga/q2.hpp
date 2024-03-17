#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_9841153(Table &tbl_SerializeFromObject_TD_10238307_input, Table &tbl_Filter_TD_9841153_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(cs_sold_date_sk#1104))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_ext_sales_price#1127)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_ext_sales_price#1127)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10238307_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_10238307_input.getInt32(i, 0);
        if (_cs_sold_date_sk1104!= 0) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_10238307_input.getInt32(i, 0);
            tbl_Filter_TD_9841153_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int64_t _cs_ext_sales_price1127_t = tbl_SerializeFromObject_TD_10238307_input.getInt64(i, 1);
            tbl_Filter_TD_9841153_output.setInt64(r, 1, _cs_ext_sales_price1127_t);
            r++;
        }
    }
    tbl_Filter_TD_9841153_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9841153_output #Row: " << tbl_Filter_TD_9841153_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9340820(Table &tbl_SerializeFromObject_TD_10802478_input, Table &tbl_Filter_TD_9340820_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ws_sold_date_sk#729))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_ext_sales_price#752)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_ext_sales_price#752)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10802478_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_10802478_input.getInt32(i, 0);
        if (_ws_sold_date_sk729!= 0) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_10802478_input.getInt32(i, 0);
            tbl_Filter_TD_9340820_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int64_t _ws_ext_sales_price752_t = tbl_SerializeFromObject_TD_10802478_input.getInt64(i, 1);
            tbl_Filter_TD_9340820_output.setInt64(r, 1, _ws_ext_sales_price752_t);
            r++;
        }
    }
    tbl_Filter_TD_9340820_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9340820_output #Row: " << tbl_Filter_TD_9340820_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9871123(Table &tbl_SerializeFromObject_TD_10396147_input, Table &tbl_Filter_TD_9871123_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(cs_sold_date_sk#1104))
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_ext_sales_price#1127)
    // Output: ListBuffer(cs_sold_date_sk#1104, cs_ext_sales_price#1127)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10396147_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_sold_date_sk1104 = tbl_SerializeFromObject_TD_10396147_input.getInt32(i, 0);
        if (_cs_sold_date_sk1104!= 0) {
            int32_t _cs_sold_date_sk1104_t = tbl_SerializeFromObject_TD_10396147_input.getInt32(i, 0);
            tbl_Filter_TD_9871123_output.setInt32(r, 0, _cs_sold_date_sk1104_t);
            int64_t _cs_ext_sales_price1127_t = tbl_SerializeFromObject_TD_10396147_input.getInt64(i, 1);
            tbl_Filter_TD_9871123_output.setInt64(r, 1, _cs_ext_sales_price1127_t);
            r++;
        }
    }
    tbl_Filter_TD_9871123_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9871123_output #Row: " << tbl_Filter_TD_9871123_output.getNumRow() << std::endl;
}

void SW_Filter_TD_9501449(Table &tbl_SerializeFromObject_TD_10510131_input, Table &tbl_Filter_TD_9501449_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(isnotnull(ws_sold_date_sk#729))
    // Input: ListBuffer(ws_sold_date_sk#729, ws_ext_sales_price#752)
    // Output: ListBuffer(ws_sold_date_sk#729, ws_ext_sales_price#752)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_10510131_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_sold_date_sk729 = tbl_SerializeFromObject_TD_10510131_input.getInt32(i, 0);
        if (_ws_sold_date_sk729!= 0) {
            int32_t _ws_sold_date_sk729_t = tbl_SerializeFromObject_TD_10510131_input.getInt32(i, 0);
            tbl_Filter_TD_9501449_output.setInt32(r, 0, _ws_sold_date_sk729_t);
            int64_t _ws_ext_sales_price752_t = tbl_SerializeFromObject_TD_10510131_input.getInt64(i, 1);
            tbl_Filter_TD_9501449_output.setInt64(r, 1, _ws_ext_sales_price752_t);
            r++;
        }
    }
    tbl_Filter_TD_9501449_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_9501449_output #Row: " << tbl_Filter_TD_9501449_output.getNumRow() << std::endl;
}

void SW_Project_TD_8854524(Table &tbl_Filter_TD_9841153_output, Table &tbl_Project_TD_8854524_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(cs_sold_date_sk#1104 AS sold_date_sk#3680, cs_ext_sales_price#1127 AS sales_price#3681)
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_ext_sales_price#1127)
    // Output: ListBuffer(sold_date_sk#3680, sales_price#3681)
    int nrow1 = tbl_Filter_TD_9841153_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_sold_date_sk1104 = tbl_Filter_TD_9841153_output.getInt32(i, 0);
        int64_t _cs_ext_sales_price1127 = tbl_Filter_TD_9841153_output.getInt64(i, 1);
        int32_t _sold_date_sk3680 = _cs_sold_date_sk1104;
        tbl_Project_TD_8854524_output.setInt32(i, 0, _sold_date_sk3680);
        int64_t _sales_price3681 = _cs_ext_sales_price1127;
        tbl_Project_TD_8854524_output.setInt64(i, 1, _sales_price3681);
    }
    tbl_Project_TD_8854524_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_8854524_output #Row: " << tbl_Project_TD_8854524_output.getNumRow() << std::endl;
}

void SW_Project_TD_8396090(Table &tbl_Filter_TD_9340820_output, Table &tbl_Project_TD_8396090_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(ws_sold_date_sk#729 AS sold_date_sk#3678, ws_ext_sales_price#752 AS sales_price#3679)
    // Input: ListBuffer(ws_sold_date_sk#729, ws_ext_sales_price#752)
    // Output: ListBuffer(sold_date_sk#3678, sales_price#3679)
    int nrow1 = tbl_Filter_TD_9340820_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_sold_date_sk729 = tbl_Filter_TD_9340820_output.getInt32(i, 0);
        int64_t _ws_ext_sales_price752 = tbl_Filter_TD_9340820_output.getInt64(i, 1);
        int32_t _sold_date_sk3678 = _ws_sold_date_sk729;
        tbl_Project_TD_8396090_output.setInt32(i, 0, _sold_date_sk3678);
        int64_t _sales_price3679 = _ws_ext_sales_price752;
        tbl_Project_TD_8396090_output.setInt64(i, 1, _sales_price3679);
    }
    tbl_Project_TD_8396090_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_8396090_output #Row: " << tbl_Project_TD_8396090_output.getNumRow() << std::endl;
}

void SW_Project_TD_8411917(Table &tbl_Filter_TD_9871123_output, Table &tbl_Project_TD_8411917_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(cs_sold_date_sk#1104 AS sold_date_sk#3680, cs_ext_sales_price#1127 AS sales_price#3681)
    // Input: ListBuffer(cs_sold_date_sk#1104, cs_ext_sales_price#1127)
    // Output: ListBuffer(sold_date_sk#3680, sales_price#3681)
    int nrow1 = tbl_Filter_TD_9871123_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _cs_sold_date_sk1104 = tbl_Filter_TD_9871123_output.getInt32(i, 0);
        int64_t _cs_ext_sales_price1127 = tbl_Filter_TD_9871123_output.getInt64(i, 1);
        int32_t _sold_date_sk3680 = _cs_sold_date_sk1104;
        tbl_Project_TD_8411917_output.setInt32(i, 0, _sold_date_sk3680);
        int64_t _sales_price3681 = _cs_ext_sales_price1127;
        tbl_Project_TD_8411917_output.setInt64(i, 1, _sales_price3681);
    }
    tbl_Project_TD_8411917_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_8411917_output #Row: " << tbl_Project_TD_8411917_output.getNumRow() << std::endl;
}

void SW_Project_TD_880677(Table &tbl_Filter_TD_9501449_output, Table &tbl_Project_TD_880677_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(ws_sold_date_sk#729 AS sold_date_sk#3678, ws_ext_sales_price#752 AS sales_price#3679)
    // Input: ListBuffer(ws_sold_date_sk#729, ws_ext_sales_price#752)
    // Output: ListBuffer(sold_date_sk#3678, sales_price#3679)
    int nrow1 = tbl_Filter_TD_9501449_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _ws_sold_date_sk729 = tbl_Filter_TD_9501449_output.getInt32(i, 0);
        int64_t _ws_ext_sales_price752 = tbl_Filter_TD_9501449_output.getInt64(i, 1);
        int32_t _sold_date_sk3678 = _ws_sold_date_sk729;
        tbl_Project_TD_880677_output.setInt32(i, 0, _sold_date_sk3678);
        int64_t _sales_price3679 = _ws_ext_sales_price752;
        tbl_Project_TD_880677_output.setInt64(i, 1, _sales_price3679);
    }
    tbl_Project_TD_880677_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_880677_output #Row: " << tbl_Project_TD_880677_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7666715(Table &tbl_SerializeFromObject_TD_8177967_input, Table &tbl_Filter_TD_7666715_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(d_date_sk#120) AND isnotnull(d_week_seq#124)))
    // Input: ListBuffer(d_date_sk#120, d_week_seq#124, d_day_name#134)
    // Output: ListBuffer(d_date_sk#120, d_week_seq#124, d_day_name#134)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8177967_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_8177967_input.getInt32(i, 0);
        int32_t _d_week_seq124 = tbl_SerializeFromObject_TD_8177967_input.getInt32(i, 1);
        if ((_d_date_sk120!= 0) && (_d_week_seq124!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_8177967_input.getInt32(i, 0);
            tbl_Filter_TD_7666715_output.setInt32(r, 0, _d_date_sk120_t);
            int32_t _d_week_seq124_t = tbl_SerializeFromObject_TD_8177967_input.getInt32(i, 1);
            tbl_Filter_TD_7666715_output.setInt32(r, 1, _d_week_seq124_t);
            std::array<char, TPCDS_READ_MAX + 1> _d_day_name134_t = tbl_SerializeFromObject_TD_8177967_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_7666715_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _d_day_name134_t);
            r++;
        }
    }
    tbl_Filter_TD_7666715_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7666715_output #Row: " << tbl_Filter_TD_7666715_output.getNumRow() << std::endl;
}

void SW_Union_TD_728800(Table &tbl_Project_TD_8396090_output, Table &tbl_Project_TD_8854524_output, Table &tbl_Union_TD_728800_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Union
    // Operation: ListBuffer(List(UNION))
    // Output Table: ListBuffer(sold_date_sk#3678, sales_price#3679)
    int r = 0;
    int row0 = tbl_Project_TD_8396090_output.getNumRow();
    for (int i = 0; i < row0; i++) {
        tbl_Union_TD_728800_output.setInt32(r, 0, tbl_Project_TD_8396090_output.getInt32(i, 0));
        tbl_Union_TD_728800_output.setInt32(r, 1, tbl_Project_TD_8396090_output.getInt64(i, 1));
        ++r;
    }
    int row1 = tbl_Project_TD_8854524_output.getNumRow();
    for (int i = 0; i < row1; i++) {
        tbl_Union_TD_728800_output.setInt32(r, 0, tbl_Project_TD_8854524_output.getInt32(i, 0));
        tbl_Union_TD_728800_output.setInt32(r, 1, tbl_Project_TD_8854524_output.getInt64(i, 1));
        ++r;
    }
    tbl_Union_TD_728800_output.setNumRow(r);
    std::cout << "tbl_Union_TD_728800_output #Row: " << tbl_Union_TD_728800_output.getNumRow() << std::endl;
}

void SW_Filter_TD_7212909(Table &tbl_SerializeFromObject_TD_874855_input, Table &tbl_Filter_TD_7212909_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((isnotnull(d_date_sk#120) AND isnotnull(d_week_seq#124)))
    // Input: ListBuffer(d_date_sk#120, d_week_seq#124, d_day_name#134)
    // Output: ListBuffer(d_date_sk#120, d_week_seq#124, d_day_name#134)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_874855_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_date_sk120 = tbl_SerializeFromObject_TD_874855_input.getInt32(i, 0);
        int32_t _d_week_seq124 = tbl_SerializeFromObject_TD_874855_input.getInt32(i, 1);
        if ((_d_date_sk120!= 0) && (_d_week_seq124!= 0)) {
            int32_t _d_date_sk120_t = tbl_SerializeFromObject_TD_874855_input.getInt32(i, 0);
            tbl_Filter_TD_7212909_output.setInt32(r, 0, _d_date_sk120_t);
            int32_t _d_week_seq124_t = tbl_SerializeFromObject_TD_874855_input.getInt32(i, 1);
            tbl_Filter_TD_7212909_output.setInt32(r, 1, _d_week_seq124_t);
            std::array<char, TPCDS_READ_MAX + 1> _d_day_name134_t = tbl_SerializeFromObject_TD_874855_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            tbl_Filter_TD_7212909_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _d_day_name134_t);
            r++;
        }
    }
    tbl_Filter_TD_7212909_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7212909_output #Row: " << tbl_Filter_TD_7212909_output.getNumRow() << std::endl;
}

void SW_Union_TD_7159974(Table &tbl_Project_TD_880677_output, Table &tbl_Project_TD_8411917_output, Table &tbl_Union_TD_7159974_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Union
    // Operation: ListBuffer(List(UNION))
    // Output Table: ListBuffer(sold_date_sk#3678, sales_price#3679)
    int r = 0;
    int row0 = tbl_Project_TD_880677_output.getNumRow();
    for (int i = 0; i < row0; i++) {
        tbl_Union_TD_7159974_output.setInt32(r, 0, tbl_Project_TD_880677_output.getInt32(i, 0));
        tbl_Union_TD_7159974_output.setInt32(r, 1, tbl_Project_TD_880677_output.getInt64(i, 1));
        ++r;
    }
    int row1 = tbl_Project_TD_8411917_output.getNumRow();
    for (int i = 0; i < row1; i++) {
        tbl_Union_TD_7159974_output.setInt32(r, 0, tbl_Project_TD_8411917_output.getInt32(i, 0));
        tbl_Union_TD_7159974_output.setInt32(r, 1, tbl_Project_TD_8411917_output.getInt64(i, 1));
        ++r;
    }
    tbl_Union_TD_7159974_output.setNumRow(r);
    std::cout << "tbl_Union_TD_7159974_output #Row: " << tbl_Union_TD_7159974_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6479048_key_leftMajor {
    int32_t _sold_date_sk3678;
    bool operator==(const SW_JOIN_INNER_TD_6479048_key_leftMajor& other) const {
        return ((_sold_date_sk3678 == other._sold_date_sk3678));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6479048_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6479048_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._sold_date_sk3678));
    }
};
}
struct SW_JOIN_INNER_TD_6479048_payload_leftMajor {
    int32_t _sold_date_sk3678;
    int64_t _sales_price3679;
};
struct SW_JOIN_INNER_TD_6479048_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_6479048_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6479048_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6479048_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_6479048_payload_rightMajor {
    int32_t _d_date_sk120;
    int32_t _d_week_seq124;
    std::string _d_day_name134;
};
void SW_JOIN_INNER_TD_6479048(Table &tbl_Union_TD_728800_output, Table &tbl_Filter_TD_7666715_output, Table &tbl_JOIN_INNER_TD_6479048_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((d_date_sk#120 = sold_date_sk#3678))
    // Left Table: ListBuffer(sold_date_sk#3678, sales_price#3679)
    // Right Table: ListBuffer(d_date_sk#120, d_week_seq#124, d_day_name#134)
    // Output Table: ListBuffer(sales_price#3679, d_week_seq#124, d_day_name#134)
    int left_nrow = tbl_Union_TD_728800_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7666715_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6479048_key_leftMajor, SW_JOIN_INNER_TD_6479048_payload_leftMajor> ht1;
        int nrow1 = tbl_Union_TD_728800_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _sold_date_sk3678_k = tbl_Union_TD_728800_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6479048_key_leftMajor keyA{_sold_date_sk3678_k};
            int32_t _sold_date_sk3678 = tbl_Union_TD_728800_output.getInt32(i, 0);
            int64_t _sales_price3679 = tbl_Union_TD_728800_output.getInt64(i, 1);
            SW_JOIN_INNER_TD_6479048_payload_leftMajor payloadA{_sold_date_sk3678, _sales_price3679};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7666715_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_7666715_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6479048_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _sold_date_sk3678 = (it->second)._sold_date_sk3678;
                int64_t _sales_price3679 = (it->second)._sales_price3679;
                int32_t _d_date_sk120 = tbl_Filter_TD_7666715_output.getInt32(i, 0);
                int32_t _d_week_seq124 = tbl_Filter_TD_7666715_output.getInt32(i, 1);
                std::array<char, TPCDS_READ_MAX + 1> _d_day_name134_n = tbl_Filter_TD_7666715_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _d_day_name134 = std::string(_d_day_name134_n.data());
                tbl_JOIN_INNER_TD_6479048_output.setInt64(r, 0, _sales_price3679);
                tbl_JOIN_INNER_TD_6479048_output.setInt32(r, 1, _d_week_seq124);
                tbl_JOIN_INNER_TD_6479048_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _d_day_name134_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6479048_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6479048_key_rightMajor, SW_JOIN_INNER_TD_6479048_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7666715_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_7666715_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6479048_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_7666715_output.getInt32(i, 0);
            int32_t _d_week_seq124 = tbl_Filter_TD_7666715_output.getInt32(i, 1);
            std::array<char, TPCDS_READ_MAX + 1> _d_day_name134_n = tbl_Filter_TD_7666715_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _d_day_name134 = std::string(_d_day_name134_n.data());
            SW_JOIN_INNER_TD_6479048_payload_rightMajor payloadA{_d_date_sk120, _d_week_seq124, _d_day_name134};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Union_TD_728800_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _sold_date_sk3678_k = tbl_Union_TD_728800_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6479048_key_rightMajor{_sold_date_sk3678_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _d_week_seq124 = (it->second)._d_week_seq124;
                std::string _d_day_name134 = (it->second)._d_day_name134;
                std::array<char, TPCDS_READ_MAX + 1> _d_day_name134_n{};
                memcpy(_d_day_name134_n.data(), (_d_day_name134).data(), (_d_day_name134).length());
                int32_t _sold_date_sk3678 = tbl_Union_TD_728800_output.getInt32(i, 0);
                int64_t _sales_price3679 = tbl_Union_TD_728800_output.getInt64(i, 1);
                tbl_JOIN_INNER_TD_6479048_output.setInt32(r, 1, _d_week_seq124);
                tbl_JOIN_INNER_TD_6479048_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _d_day_name134_n);
                tbl_JOIN_INNER_TD_6479048_output.setInt64(r, 0, _sales_price3679);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6479048_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6479048_output #Row: " << tbl_JOIN_INNER_TD_6479048_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_6614106_key_leftMajor {
    int32_t _sold_date_sk3678;
    bool operator==(const SW_JOIN_INNER_TD_6614106_key_leftMajor& other) const {
        return ((_sold_date_sk3678 == other._sold_date_sk3678));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6614106_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6614106_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._sold_date_sk3678));
    }
};
}
struct SW_JOIN_INNER_TD_6614106_payload_leftMajor {
    int32_t _sold_date_sk3678;
    int64_t _sales_price3679;
};
struct SW_JOIN_INNER_TD_6614106_key_rightMajor {
    int32_t _d_date_sk120;
    bool operator==(const SW_JOIN_INNER_TD_6614106_key_rightMajor& other) const {
        return ((_d_date_sk120 == other._d_date_sk120));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_6614106_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_6614106_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_date_sk120));
    }
};
}
struct SW_JOIN_INNER_TD_6614106_payload_rightMajor {
    int32_t _d_date_sk120;
    int32_t _d_week_seq124;
    std::string _d_day_name134;
};
void SW_JOIN_INNER_TD_6614106(Table &tbl_Union_TD_7159974_output, Table &tbl_Filter_TD_7212909_output, Table &tbl_JOIN_INNER_TD_6614106_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((d_date_sk#120 = sold_date_sk#3678))
    // Left Table: ListBuffer(sold_date_sk#3678, sales_price#3679)
    // Right Table: ListBuffer(d_date_sk#120, d_week_seq#124, d_day_name#134)
    // Output Table: ListBuffer(sales_price#3679, d_week_seq#124, d_day_name#134)
    int left_nrow = tbl_Union_TD_7159974_output.getNumRow();
    int right_nrow = tbl_Filter_TD_7212909_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6614106_key_leftMajor, SW_JOIN_INNER_TD_6614106_payload_leftMajor> ht1;
        int nrow1 = tbl_Union_TD_7159974_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _sold_date_sk3678_k = tbl_Union_TD_7159974_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6614106_key_leftMajor keyA{_sold_date_sk3678_k};
            int32_t _sold_date_sk3678 = tbl_Union_TD_7159974_output.getInt32(i, 0);
            int64_t _sales_price3679 = tbl_Union_TD_7159974_output.getInt64(i, 1);
            SW_JOIN_INNER_TD_6614106_payload_leftMajor payloadA{_sold_date_sk3678, _sales_price3679};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_7212909_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_7212909_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6614106_key_leftMajor{_d_date_sk120_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _sold_date_sk3678 = (it->second)._sold_date_sk3678;
                int64_t _sales_price3679 = (it->second)._sales_price3679;
                int32_t _d_date_sk120 = tbl_Filter_TD_7212909_output.getInt32(i, 0);
                int32_t _d_week_seq124 = tbl_Filter_TD_7212909_output.getInt32(i, 1);
                std::array<char, TPCDS_READ_MAX + 1> _d_day_name134_n = tbl_Filter_TD_7212909_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
                std::string _d_day_name134 = std::string(_d_day_name134_n.data());
                tbl_JOIN_INNER_TD_6614106_output.setInt64(r, 0, _sales_price3679);
                tbl_JOIN_INNER_TD_6614106_output.setInt32(r, 1, _d_week_seq124);
                tbl_JOIN_INNER_TD_6614106_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _d_day_name134_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6614106_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_6614106_key_rightMajor, SW_JOIN_INNER_TD_6614106_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_7212909_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_date_sk120_k = tbl_Filter_TD_7212909_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_6614106_key_rightMajor keyA{_d_date_sk120_k};
            int32_t _d_date_sk120 = tbl_Filter_TD_7212909_output.getInt32(i, 0);
            int32_t _d_week_seq124 = tbl_Filter_TD_7212909_output.getInt32(i, 1);
            std::array<char, TPCDS_READ_MAX + 1> _d_day_name134_n = tbl_Filter_TD_7212909_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
            std::string _d_day_name134 = std::string(_d_day_name134_n.data());
            SW_JOIN_INNER_TD_6614106_payload_rightMajor payloadA{_d_date_sk120, _d_week_seq124, _d_day_name134};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Union_TD_7159974_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _sold_date_sk3678_k = tbl_Union_TD_7159974_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_6614106_key_rightMajor{_sold_date_sk3678_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_date_sk120 = (it->second)._d_date_sk120;
                int32_t _d_week_seq124 = (it->second)._d_week_seq124;
                std::string _d_day_name134 = (it->second)._d_day_name134;
                std::array<char, TPCDS_READ_MAX + 1> _d_day_name134_n{};
                memcpy(_d_day_name134_n.data(), (_d_day_name134).data(), (_d_day_name134).length());
                int32_t _sold_date_sk3678 = tbl_Union_TD_7159974_output.getInt32(i, 0);
                int64_t _sales_price3679 = tbl_Union_TD_7159974_output.getInt64(i, 1);
                tbl_JOIN_INNER_TD_6614106_output.setInt32(r, 1, _d_week_seq124);
                tbl_JOIN_INNER_TD_6614106_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 2, _d_day_name134_n);
                tbl_JOIN_INNER_TD_6614106_output.setInt64(r, 0, _sales_price3679);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_6614106_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_6614106_output #Row: " << tbl_JOIN_INNER_TD_6614106_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5146130(Table &tbl_SerializeFromObject_TD_693662_input, Table &tbl_Filter_TD_5146130_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3723) AND (d_year#3723 = 2002)) AND isnotnull(d_week_seq#3721)))
    // Input: ListBuffer(d_week_seq#3721, d_year#3723)
    // Output: ListBuffer(d_week_seq#3721)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_693662_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3723 = tbl_SerializeFromObject_TD_693662_input.getInt32(i, 1);
        int32_t _d_week_seq3721 = tbl_SerializeFromObject_TD_693662_input.getInt32(i, 0);
        if (((_d_year3723!= 0) && (_d_year3723 == 2002)) && (_d_week_seq3721!= 0)) {
            int32_t _d_week_seq3721_t = tbl_SerializeFromObject_TD_693662_input.getInt32(i, 0);
            tbl_Filter_TD_5146130_output.setInt32(r, 0, _d_week_seq3721_t);
            r++;
        }
    }
    tbl_Filter_TD_5146130_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5146130_output #Row: " << tbl_Filter_TD_5146130_output.getNumRow() << std::endl;
}

typedef int32_t SW_Aggregate_TD_5941078_key;
struct SW_Aggregate_TD_5941078_payload {
    int64_t _sun_sales3682_sum_0;
    int64_t _mon_sales3683_sum_1;
    int64_t _tue_sales3684_sum_2;
    int64_t _wed_sales3685_sum_3;
    int64_t _thu_sales3686_sum_4;
    int64_t _fri_sales3687_sum_5;
    int64_t _sat_sales3688_sum_6;
};
void SW_Aggregate_TD_5941078(Table &tbl_JOIN_INNER_TD_6479048_output, Table &tbl_Aggregate_TD_5941078_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(d_week_seq#124, MakeDecimal(sum(UnscaledValue(CASE WHEN (d_day_name#134 = Sunday) THEN sales_price#3679 END)),17,2) AS sun_sales#3682, MakeDecimal(sum(UnscaledValue(CASE WHEN (d_day_name#134 = Monday) THEN sales_price#3679 END)),17,2) AS mon_sales#3683, MakeDecimal(sum(UnscaledValue(CASE WHEN (d_day_name#134 = Tuesday) THEN sales_price#3679 END)),17,2) AS tue_sales#3684, MakeDecimal(sum(UnscaledValue(CASE WHEN (d_day_name#134 = Wednesday) THEN sales_price#3679 END)),17,2) AS wed_sales#3685, MakeDecimal(sum(UnscaledValue(CASE WHEN (d_day_name#134 = Thursday) THEN sales_price#3679 END)),17,2) AS thu_sales#3686, MakeDecimal(sum(UnscaledValue(CASE WHEN (d_day_name#134 = Friday) THEN sales_price#3679 END)),17,2) AS fri_sales#3687, MakeDecimal(sum(UnscaledValue(CASE WHEN (d_day_name#134 = Saturday) THEN sales_price#3679 END)),17,2) AS sat_sales#3688)
    // Input: ListBuffer(sales_price#3679, d_week_seq#124, d_day_name#134)
    // Output: ListBuffer(d_week_seq#124, sun_sales#3682, mon_sales#3683, tue_sales#3684, wed_sales#3685, thu_sales#3686, fri_sales#3687, sat_sales#3688)
    std::unordered_map<SW_Aggregate_TD_5941078_key, SW_Aggregate_TD_5941078_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_6479048_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sales_price3679 = tbl_JOIN_INNER_TD_6479048_output.getInt64(i, 0);
        int32_t _d_week_seq124 = tbl_JOIN_INNER_TD_6479048_output.getInt32(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _d_day_name134 = tbl_JOIN_INNER_TD_6479048_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        SW_Aggregate_TD_5941078_key k = _d_week_seq124;
        int64_t _sun_sales3682_sum_0 = (std::string(_d_day_name134.data()) == "Sunday") ? _sales_price3679 : 1;
        int64_t _mon_sales3683_sum_1 = (std::string(_d_day_name134.data()) == "Monday") ? _sales_price3679 : 1;
        int64_t _tue_sales3684_sum_2 = (std::string(_d_day_name134.data()) == "Tuesday") ? _sales_price3679 : 1;
        int64_t _wed_sales3685_sum_3 = (std::string(_d_day_name134.data()) == "Wednesday") ? _sales_price3679 : 1;
        int64_t _thu_sales3686_sum_4 = (std::string(_d_day_name134.data()) == "Thursday") ? _sales_price3679 : 1;
        int64_t _fri_sales3687_sum_5 = (std::string(_d_day_name134.data()) == "Friday") ? _sales_price3679 : 1;
        int64_t _sat_sales3688_sum_6 = (std::string(_d_day_name134.data()) == "Saturday") ? _sales_price3679 : 1;
        SW_Aggregate_TD_5941078_payload p{_sun_sales3682_sum_0, _mon_sales3683_sum_1, _tue_sales3684_sum_2, _wed_sales3685_sum_3, _thu_sales3686_sum_4, _fri_sales3687_sum_5, _sat_sales3688_sum_6};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._sun_sales3682_sum_0 + _sun_sales3682_sum_0;
            p._sun_sales3682_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._mon_sales3683_sum_1 + _mon_sales3683_sum_1;
            p._mon_sales3683_sum_1 = sum_1;
            int64_t sum_2 = (it->second)._tue_sales3684_sum_2 + _tue_sales3684_sum_2;
            p._tue_sales3684_sum_2 = sum_2;
            int64_t sum_3 = (it->second)._wed_sales3685_sum_3 + _wed_sales3685_sum_3;
            p._wed_sales3685_sum_3 = sum_3;
            int64_t sum_4 = (it->second)._thu_sales3686_sum_4 + _thu_sales3686_sum_4;
            p._thu_sales3686_sum_4 = sum_4;
            int64_t sum_5 = (it->second)._fri_sales3687_sum_5 + _fri_sales3687_sum_5;
            p._fri_sales3687_sum_5 = sum_5;
            int64_t sum_6 = (it->second)._sat_sales3688_sum_6 + _sat_sales3688_sum_6;
            p._sat_sales3688_sum_6 = sum_6;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        tbl_Aggregate_TD_5941078_output.setInt32(r, 0, (it.first));
        int64_t _sun_sales3682 = (it.second)._sun_sales3682_sum_0;
        tbl_Aggregate_TD_5941078_output.setInt64(r, 1, _sun_sales3682);
        int64_t _mon_sales3683 = (it.second)._mon_sales3683_sum_1;
        tbl_Aggregate_TD_5941078_output.setInt64(r, 2, _mon_sales3683);
        int64_t _tue_sales3684 = (it.second)._tue_sales3684_sum_2;
        tbl_Aggregate_TD_5941078_output.setInt64(r, 3, _tue_sales3684);
        int64_t _wed_sales3685 = (it.second)._wed_sales3685_sum_3;
        tbl_Aggregate_TD_5941078_output.setInt64(r, 4, _wed_sales3685);
        int64_t _thu_sales3686 = (it.second)._thu_sales3686_sum_4;
        tbl_Aggregate_TD_5941078_output.setInt64(r, 5, _thu_sales3686);
        int64_t _fri_sales3687 = (it.second)._fri_sales3687_sum_5;
        tbl_Aggregate_TD_5941078_output.setInt64(r, 6, _fri_sales3687);
        int64_t _sat_sales3688 = (it.second)._sat_sales3688_sum_6;
        tbl_Aggregate_TD_5941078_output.setInt64(r, 7, _sat_sales3688);
        ++r;
    }
    tbl_Aggregate_TD_5941078_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_5941078_output #Row: " << tbl_Aggregate_TD_5941078_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5955066(Table &tbl_SerializeFromObject_TD_6582006_input, Table &tbl_Filter_TD_5955066_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(d_year#3695) AND (d_year#3695 = 2001)) AND isnotnull(d_week_seq#3693)))
    // Input: ListBuffer(d_week_seq#3693, d_year#3695)
    // Output: ListBuffer(d_week_seq#3693)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6582006_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_year3695 = tbl_SerializeFromObject_TD_6582006_input.getInt32(i, 1);
        int32_t _d_week_seq3693 = tbl_SerializeFromObject_TD_6582006_input.getInt32(i, 0);
        if (((_d_year3695!= 0) && (_d_year3695 == 2001)) && (_d_week_seq3693!= 0)) {
            int32_t _d_week_seq3693_t = tbl_SerializeFromObject_TD_6582006_input.getInt32(i, 0);
            tbl_Filter_TD_5955066_output.setInt32(r, 0, _d_week_seq3693_t);
            r++;
        }
    }
    tbl_Filter_TD_5955066_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5955066_output #Row: " << tbl_Filter_TD_5955066_output.getNumRow() << std::endl;
}

typedef int32_t SW_Aggregate_TD_5928393_key;
struct SW_Aggregate_TD_5928393_payload {
    int64_t _sun_sales3682_sum_0;
    int64_t _mon_sales3683_sum_1;
    int64_t _tue_sales3684_sum_2;
    int64_t _wed_sales3685_sum_3;
    int64_t _thu_sales3686_sum_4;
    int64_t _fri_sales3687_sum_5;
    int64_t _sat_sales3688_sum_6;
};
void SW_Aggregate_TD_5928393(Table &tbl_JOIN_INNER_TD_6614106_output, Table &tbl_Aggregate_TD_5928393_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(d_week_seq#124, MakeDecimal(sum(UnscaledValue(CASE WHEN (d_day_name#134 = Sunday) THEN sales_price#3679 END)),17,2) AS sun_sales#3682, MakeDecimal(sum(UnscaledValue(CASE WHEN (d_day_name#134 = Monday) THEN sales_price#3679 END)),17,2) AS mon_sales#3683, MakeDecimal(sum(UnscaledValue(CASE WHEN (d_day_name#134 = Tuesday) THEN sales_price#3679 END)),17,2) AS tue_sales#3684, MakeDecimal(sum(UnscaledValue(CASE WHEN (d_day_name#134 = Wednesday) THEN sales_price#3679 END)),17,2) AS wed_sales#3685, MakeDecimal(sum(UnscaledValue(CASE WHEN (d_day_name#134 = Thursday) THEN sales_price#3679 END)),17,2) AS thu_sales#3686, MakeDecimal(sum(UnscaledValue(CASE WHEN (d_day_name#134 = Friday) THEN sales_price#3679 END)),17,2) AS fri_sales#3687, MakeDecimal(sum(UnscaledValue(CASE WHEN (d_day_name#134 = Saturday) THEN sales_price#3679 END)),17,2) AS sat_sales#3688)
    // Input: ListBuffer(sales_price#3679, d_week_seq#124, d_day_name#134)
    // Output: ListBuffer(d_week_seq#124, sun_sales#3682, mon_sales#3683, tue_sales#3684, wed_sales#3685, thu_sales#3686, fri_sales#3687, sat_sales#3688)
    std::unordered_map<SW_Aggregate_TD_5928393_key, SW_Aggregate_TD_5928393_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_6614106_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _sales_price3679 = tbl_JOIN_INNER_TD_6614106_output.getInt64(i, 0);
        int32_t _d_week_seq124 = tbl_JOIN_INNER_TD_6614106_output.getInt32(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _d_day_name134 = tbl_JOIN_INNER_TD_6614106_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        SW_Aggregate_TD_5928393_key k = _d_week_seq124;
        int64_t _sun_sales3682_sum_0 = (std::string(_d_day_name134.data()) == "Sunday") ? _sales_price3679 : 1;
        int64_t _mon_sales3683_sum_1 = (std::string(_d_day_name134.data()) == "Monday") ? _sales_price3679 : 1;
        int64_t _tue_sales3684_sum_2 = (std::string(_d_day_name134.data()) == "Tuesday") ? _sales_price3679 : 1;
        int64_t _wed_sales3685_sum_3 = (std::string(_d_day_name134.data()) == "Wednesday") ? _sales_price3679 : 1;
        int64_t _thu_sales3686_sum_4 = (std::string(_d_day_name134.data()) == "Thursday") ? _sales_price3679 : 1;
        int64_t _fri_sales3687_sum_5 = (std::string(_d_day_name134.data()) == "Friday") ? _sales_price3679 : 1;
        int64_t _sat_sales3688_sum_6 = (std::string(_d_day_name134.data()) == "Saturday") ? _sales_price3679 : 1;
        SW_Aggregate_TD_5928393_payload p{_sun_sales3682_sum_0, _mon_sales3683_sum_1, _tue_sales3684_sum_2, _wed_sales3685_sum_3, _thu_sales3686_sum_4, _fri_sales3687_sum_5, _sat_sales3688_sum_6};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t sum_0 = (it->second)._sun_sales3682_sum_0 + _sun_sales3682_sum_0;
            p._sun_sales3682_sum_0 = sum_0;
            int64_t sum_1 = (it->second)._mon_sales3683_sum_1 + _mon_sales3683_sum_1;
            p._mon_sales3683_sum_1 = sum_1;
            int64_t sum_2 = (it->second)._tue_sales3684_sum_2 + _tue_sales3684_sum_2;
            p._tue_sales3684_sum_2 = sum_2;
            int64_t sum_3 = (it->second)._wed_sales3685_sum_3 + _wed_sales3685_sum_3;
            p._wed_sales3685_sum_3 = sum_3;
            int64_t sum_4 = (it->second)._thu_sales3686_sum_4 + _thu_sales3686_sum_4;
            p._thu_sales3686_sum_4 = sum_4;
            int64_t sum_5 = (it->second)._fri_sales3687_sum_5 + _fri_sales3687_sum_5;
            p._fri_sales3687_sum_5 = sum_5;
            int64_t sum_6 = (it->second)._sat_sales3688_sum_6 + _sat_sales3688_sum_6;
            p._sat_sales3688_sum_6 = sum_6;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        tbl_Aggregate_TD_5928393_output.setInt32(r, 0, (it.first));
        int64_t _sun_sales3682 = (it.second)._sun_sales3682_sum_0;
        tbl_Aggregate_TD_5928393_output.setInt64(r, 1, _sun_sales3682);
        int64_t _mon_sales3683 = (it.second)._mon_sales3683_sum_1;
        tbl_Aggregate_TD_5928393_output.setInt64(r, 2, _mon_sales3683);
        int64_t _tue_sales3684 = (it.second)._tue_sales3684_sum_2;
        tbl_Aggregate_TD_5928393_output.setInt64(r, 3, _tue_sales3684);
        int64_t _wed_sales3685 = (it.second)._wed_sales3685_sum_3;
        tbl_Aggregate_TD_5928393_output.setInt64(r, 4, _wed_sales3685);
        int64_t _thu_sales3686 = (it.second)._thu_sales3686_sum_4;
        tbl_Aggregate_TD_5928393_output.setInt64(r, 5, _thu_sales3686);
        int64_t _fri_sales3687 = (it.second)._fri_sales3687_sum_5;
        tbl_Aggregate_TD_5928393_output.setInt64(r, 6, _fri_sales3687);
        int64_t _sat_sales3688 = (it.second)._sat_sales3688_sum_6;
        tbl_Aggregate_TD_5928393_output.setInt64(r, 7, _sat_sales3688);
        ++r;
    }
    tbl_Aggregate_TD_5928393_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_5928393_output #Row: " << tbl_Aggregate_TD_5928393_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4804647_key_leftMajor {
    int32_t _d_week_seq124;
    bool operator==(const SW_JOIN_INNER_TD_4804647_key_leftMajor& other) const {
        return ((_d_week_seq124 == other._d_week_seq124));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4804647_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4804647_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_week_seq124));
    }
};
}
struct SW_JOIN_INNER_TD_4804647_payload_leftMajor {
    int32_t _d_week_seq124;
    int64_t _sun_sales3682;
    int64_t _mon_sales3683;
    int64_t _tue_sales3684;
    int64_t _wed_sales3685;
    int64_t _thu_sales3686;
    int64_t _fri_sales3687;
    int64_t _sat_sales3688;
};
struct SW_JOIN_INNER_TD_4804647_key_rightMajor {
    int32_t _d_week_seq3721;
    bool operator==(const SW_JOIN_INNER_TD_4804647_key_rightMajor& other) const {
        return ((_d_week_seq3721 == other._d_week_seq3721));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4804647_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4804647_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_week_seq3721));
    }
};
}
struct SW_JOIN_INNER_TD_4804647_payload_rightMajor {
    int32_t _d_week_seq3721;
};
void SW_JOIN_INNER_TD_4804647(Table &tbl_Aggregate_TD_5941078_output, Table &tbl_Filter_TD_5146130_output, Table &tbl_JOIN_INNER_TD_4804647_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((d_week_seq#3721 = d_week_seq#124))
    // Left Table: ListBuffer(d_week_seq#124, sun_sales#3682, mon_sales#3683, tue_sales#3684, wed_sales#3685, thu_sales#3686, fri_sales#3687, sat_sales#3688)
    // Right Table: ListBuffer(d_week_seq#3721)
    // Output Table: ListBuffer(d_week_seq#124, sun_sales#3682, mon_sales#3683, tue_sales#3684, wed_sales#3685, thu_sales#3686, fri_sales#3687, sat_sales#3688)
    int left_nrow = tbl_Aggregate_TD_5941078_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5146130_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4804647_key_leftMajor, SW_JOIN_INNER_TD_4804647_payload_leftMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_5941078_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_week_seq124_k = tbl_Aggregate_TD_5941078_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4804647_key_leftMajor keyA{_d_week_seq124_k};
            int32_t _d_week_seq124 = tbl_Aggregate_TD_5941078_output.getInt32(i, 0);
            int64_t _sun_sales3682 = tbl_Aggregate_TD_5941078_output.getInt64(i, 1);
            int64_t _mon_sales3683 = tbl_Aggregate_TD_5941078_output.getInt64(i, 2);
            int64_t _tue_sales3684 = tbl_Aggregate_TD_5941078_output.getInt64(i, 3);
            int64_t _wed_sales3685 = tbl_Aggregate_TD_5941078_output.getInt64(i, 4);
            int64_t _thu_sales3686 = tbl_Aggregate_TD_5941078_output.getInt64(i, 5);
            int64_t _fri_sales3687 = tbl_Aggregate_TD_5941078_output.getInt64(i, 6);
            int64_t _sat_sales3688 = tbl_Aggregate_TD_5941078_output.getInt64(i, 7);
            SW_JOIN_INNER_TD_4804647_payload_leftMajor payloadA{_d_week_seq124, _sun_sales3682, _mon_sales3683, _tue_sales3684, _wed_sales3685, _thu_sales3686, _fri_sales3687, _sat_sales3688};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5146130_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_week_seq3721_k = tbl_Filter_TD_5146130_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4804647_key_leftMajor{_d_week_seq3721_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_week_seq124 = (it->second)._d_week_seq124;
                int64_t _sun_sales3682 = (it->second)._sun_sales3682;
                int64_t _mon_sales3683 = (it->second)._mon_sales3683;
                int64_t _tue_sales3684 = (it->second)._tue_sales3684;
                int64_t _wed_sales3685 = (it->second)._wed_sales3685;
                int64_t _thu_sales3686 = (it->second)._thu_sales3686;
                int64_t _fri_sales3687 = (it->second)._fri_sales3687;
                int64_t _sat_sales3688 = (it->second)._sat_sales3688;
                int32_t _d_week_seq3721 = tbl_Filter_TD_5146130_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_4804647_output.setInt32(r, 0, _d_week_seq124);
                tbl_JOIN_INNER_TD_4804647_output.setInt64(r, 1, _sun_sales3682);
                tbl_JOIN_INNER_TD_4804647_output.setInt64(r, 2, _mon_sales3683);
                tbl_JOIN_INNER_TD_4804647_output.setInt64(r, 3, _tue_sales3684);
                tbl_JOIN_INNER_TD_4804647_output.setInt64(r, 4, _wed_sales3685);
                tbl_JOIN_INNER_TD_4804647_output.setInt64(r, 5, _thu_sales3686);
                tbl_JOIN_INNER_TD_4804647_output.setInt64(r, 6, _fri_sales3687);
                tbl_JOIN_INNER_TD_4804647_output.setInt64(r, 7, _sat_sales3688);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4804647_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4804647_key_rightMajor, SW_JOIN_INNER_TD_4804647_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5146130_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_week_seq3721_k = tbl_Filter_TD_5146130_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4804647_key_rightMajor keyA{_d_week_seq3721_k};
            int32_t _d_week_seq3721 = tbl_Filter_TD_5146130_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4804647_payload_rightMajor payloadA{_d_week_seq3721};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_5941078_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_week_seq124_k = tbl_Aggregate_TD_5941078_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4804647_key_rightMajor{_d_week_seq124_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_week_seq3721 = (it->second)._d_week_seq3721;
                int32_t _d_week_seq124 = tbl_Aggregate_TD_5941078_output.getInt32(i, 0);
                int64_t _sun_sales3682 = tbl_Aggregate_TD_5941078_output.getInt64(i, 1);
                int64_t _mon_sales3683 = tbl_Aggregate_TD_5941078_output.getInt64(i, 2);
                int64_t _tue_sales3684 = tbl_Aggregate_TD_5941078_output.getInt64(i, 3);
                int64_t _wed_sales3685 = tbl_Aggregate_TD_5941078_output.getInt64(i, 4);
                int64_t _thu_sales3686 = tbl_Aggregate_TD_5941078_output.getInt64(i, 5);
                int64_t _fri_sales3687 = tbl_Aggregate_TD_5941078_output.getInt64(i, 6);
                int64_t _sat_sales3688 = tbl_Aggregate_TD_5941078_output.getInt64(i, 7);
                tbl_JOIN_INNER_TD_4804647_output.setInt32(r, 0, _d_week_seq124);
                tbl_JOIN_INNER_TD_4804647_output.setInt64(r, 1, _sun_sales3682);
                tbl_JOIN_INNER_TD_4804647_output.setInt64(r, 2, _mon_sales3683);
                tbl_JOIN_INNER_TD_4804647_output.setInt64(r, 3, _tue_sales3684);
                tbl_JOIN_INNER_TD_4804647_output.setInt64(r, 4, _wed_sales3685);
                tbl_JOIN_INNER_TD_4804647_output.setInt64(r, 5, _thu_sales3686);
                tbl_JOIN_INNER_TD_4804647_output.setInt64(r, 6, _fri_sales3687);
                tbl_JOIN_INNER_TD_4804647_output.setInt64(r, 7, _sat_sales3688);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4804647_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4804647_output #Row: " << tbl_JOIN_INNER_TD_4804647_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4970008_key_leftMajor {
    int32_t _d_week_seq124;
    bool operator==(const SW_JOIN_INNER_TD_4970008_key_leftMajor& other) const {
        return ((_d_week_seq124 == other._d_week_seq124));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4970008_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4970008_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_week_seq124));
    }
};
}
struct SW_JOIN_INNER_TD_4970008_payload_leftMajor {
    int32_t _d_week_seq124;
    int64_t _sun_sales3682;
    int64_t _mon_sales3683;
    int64_t _tue_sales3684;
    int64_t _wed_sales3685;
    int64_t _thu_sales3686;
    int64_t _fri_sales3687;
    int64_t _sat_sales3688;
};
struct SW_JOIN_INNER_TD_4970008_key_rightMajor {
    int32_t _d_week_seq3693;
    bool operator==(const SW_JOIN_INNER_TD_4970008_key_rightMajor& other) const {
        return ((_d_week_seq3693 == other._d_week_seq3693));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4970008_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4970008_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_week_seq3693));
    }
};
}
struct SW_JOIN_INNER_TD_4970008_payload_rightMajor {
    int32_t _d_week_seq3693;
};
void SW_JOIN_INNER_TD_4970008(Table &tbl_Aggregate_TD_5928393_output, Table &tbl_Filter_TD_5955066_output, Table &tbl_JOIN_INNER_TD_4970008_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((d_week_seq#3693 = d_week_seq#124))
    // Left Table: ListBuffer(d_week_seq#124, sun_sales#3682, mon_sales#3683, tue_sales#3684, wed_sales#3685, thu_sales#3686, fri_sales#3687, sat_sales#3688)
    // Right Table: ListBuffer(d_week_seq#3693)
    // Output Table: ListBuffer(d_week_seq#124, sun_sales#3682, mon_sales#3683, tue_sales#3684, wed_sales#3685, thu_sales#3686, fri_sales#3687, sat_sales#3688)
    int left_nrow = tbl_Aggregate_TD_5928393_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5955066_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4970008_key_leftMajor, SW_JOIN_INNER_TD_4970008_payload_leftMajor> ht1;
        int nrow1 = tbl_Aggregate_TD_5928393_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_week_seq124_k = tbl_Aggregate_TD_5928393_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4970008_key_leftMajor keyA{_d_week_seq124_k};
            int32_t _d_week_seq124 = tbl_Aggregate_TD_5928393_output.getInt32(i, 0);
            int64_t _sun_sales3682 = tbl_Aggregate_TD_5928393_output.getInt64(i, 1);
            int64_t _mon_sales3683 = tbl_Aggregate_TD_5928393_output.getInt64(i, 2);
            int64_t _tue_sales3684 = tbl_Aggregate_TD_5928393_output.getInt64(i, 3);
            int64_t _wed_sales3685 = tbl_Aggregate_TD_5928393_output.getInt64(i, 4);
            int64_t _thu_sales3686 = tbl_Aggregate_TD_5928393_output.getInt64(i, 5);
            int64_t _fri_sales3687 = tbl_Aggregate_TD_5928393_output.getInt64(i, 6);
            int64_t _sat_sales3688 = tbl_Aggregate_TD_5928393_output.getInt64(i, 7);
            SW_JOIN_INNER_TD_4970008_payload_leftMajor payloadA{_d_week_seq124, _sun_sales3682, _mon_sales3683, _tue_sales3684, _wed_sales3685, _thu_sales3686, _fri_sales3687, _sat_sales3688};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5955066_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_week_seq3693_k = tbl_Filter_TD_5955066_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4970008_key_leftMajor{_d_week_seq3693_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_week_seq124 = (it->second)._d_week_seq124;
                int64_t _sun_sales3682 = (it->second)._sun_sales3682;
                int64_t _mon_sales3683 = (it->second)._mon_sales3683;
                int64_t _tue_sales3684 = (it->second)._tue_sales3684;
                int64_t _wed_sales3685 = (it->second)._wed_sales3685;
                int64_t _thu_sales3686 = (it->second)._thu_sales3686;
                int64_t _fri_sales3687 = (it->second)._fri_sales3687;
                int64_t _sat_sales3688 = (it->second)._sat_sales3688;
                int32_t _d_week_seq3693 = tbl_Filter_TD_5955066_output.getInt32(i, 0);
                tbl_JOIN_INNER_TD_4970008_output.setInt32(r, 0, _d_week_seq124);
                tbl_JOIN_INNER_TD_4970008_output.setInt64(r, 1, _sun_sales3682);
                tbl_JOIN_INNER_TD_4970008_output.setInt64(r, 2, _mon_sales3683);
                tbl_JOIN_INNER_TD_4970008_output.setInt64(r, 3, _tue_sales3684);
                tbl_JOIN_INNER_TD_4970008_output.setInt64(r, 4, _wed_sales3685);
                tbl_JOIN_INNER_TD_4970008_output.setInt64(r, 5, _thu_sales3686);
                tbl_JOIN_INNER_TD_4970008_output.setInt64(r, 6, _fri_sales3687);
                tbl_JOIN_INNER_TD_4970008_output.setInt64(r, 7, _sat_sales3688);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4970008_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4970008_key_rightMajor, SW_JOIN_INNER_TD_4970008_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5955066_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_week_seq3693_k = tbl_Filter_TD_5955066_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4970008_key_rightMajor keyA{_d_week_seq3693_k};
            int32_t _d_week_seq3693 = tbl_Filter_TD_5955066_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_4970008_payload_rightMajor payloadA{_d_week_seq3693};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Aggregate_TD_5928393_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_week_seq124_k = tbl_Aggregate_TD_5928393_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4970008_key_rightMajor{_d_week_seq124_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_week_seq3693 = (it->second)._d_week_seq3693;
                int32_t _d_week_seq124 = tbl_Aggregate_TD_5928393_output.getInt32(i, 0);
                int64_t _sun_sales3682 = tbl_Aggregate_TD_5928393_output.getInt64(i, 1);
                int64_t _mon_sales3683 = tbl_Aggregate_TD_5928393_output.getInt64(i, 2);
                int64_t _tue_sales3684 = tbl_Aggregate_TD_5928393_output.getInt64(i, 3);
                int64_t _wed_sales3685 = tbl_Aggregate_TD_5928393_output.getInt64(i, 4);
                int64_t _thu_sales3686 = tbl_Aggregate_TD_5928393_output.getInt64(i, 5);
                int64_t _fri_sales3687 = tbl_Aggregate_TD_5928393_output.getInt64(i, 6);
                int64_t _sat_sales3688 = tbl_Aggregate_TD_5928393_output.getInt64(i, 7);
                tbl_JOIN_INNER_TD_4970008_output.setInt32(r, 0, _d_week_seq124);
                tbl_JOIN_INNER_TD_4970008_output.setInt64(r, 1, _sun_sales3682);
                tbl_JOIN_INNER_TD_4970008_output.setInt64(r, 2, _mon_sales3683);
                tbl_JOIN_INNER_TD_4970008_output.setInt64(r, 3, _tue_sales3684);
                tbl_JOIN_INNER_TD_4970008_output.setInt64(r, 4, _wed_sales3685);
                tbl_JOIN_INNER_TD_4970008_output.setInt64(r, 5, _thu_sales3686);
                tbl_JOIN_INNER_TD_4970008_output.setInt64(r, 6, _fri_sales3687);
                tbl_JOIN_INNER_TD_4970008_output.setInt64(r, 7, _sat_sales3688);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4970008_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4970008_output #Row: " << tbl_JOIN_INNER_TD_4970008_output.getNumRow() << std::endl;
}

void SW_Project_TD_3531034(Table &tbl_JOIN_INNER_TD_4804647_output, Table &tbl_Project_TD_3531034_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(d_week_seq#124 AS d_week_seq2#3670, sun_sales#3682 AS sun_sales2#3671, mon_sales#3683 AS mon_sales2#3672, tue_sales#3684 AS tue_sales2#3673, wed_sales#3685 AS wed_sales2#3674, thu_sales#3686 AS thu_sales2#3675, fri_sales#3687 AS fri_sales2#3676, sat_sales#3688 AS sat_sales2#3677)
    // Input: ListBuffer(d_week_seq#124, sun_sales#3682, mon_sales#3683, tue_sales#3684, wed_sales#3685, thu_sales#3686, fri_sales#3687, sat_sales#3688)
    // Output: ListBuffer(d_week_seq2#3670, sun_sales2#3671, mon_sales2#3672, tue_sales2#3673, wed_sales2#3674, thu_sales2#3675, fri_sales2#3676, sat_sales2#3677)
    int nrow1 = tbl_JOIN_INNER_TD_4804647_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_week_seq124 = tbl_JOIN_INNER_TD_4804647_output.getInt32(i, 0);
        int64_t _sun_sales3682 = tbl_JOIN_INNER_TD_4804647_output.getInt64(i, 1);
        int64_t _mon_sales3683 = tbl_JOIN_INNER_TD_4804647_output.getInt64(i, 2);
        int64_t _tue_sales3684 = tbl_JOIN_INNER_TD_4804647_output.getInt64(i, 3);
        int64_t _wed_sales3685 = tbl_JOIN_INNER_TD_4804647_output.getInt64(i, 4);
        int64_t _thu_sales3686 = tbl_JOIN_INNER_TD_4804647_output.getInt64(i, 5);
        int64_t _fri_sales3687 = tbl_JOIN_INNER_TD_4804647_output.getInt64(i, 6);
        int64_t _sat_sales3688 = tbl_JOIN_INNER_TD_4804647_output.getInt64(i, 7);
        int32_t _d_week_seq23670 = _d_week_seq124;
        tbl_Project_TD_3531034_output.setInt32(i, 0, _d_week_seq23670);
        int64_t _sun_sales23671 = _sun_sales3682;
        tbl_Project_TD_3531034_output.setInt64(i, 1, _sun_sales23671);
        int64_t _mon_sales23672 = _mon_sales3683;
        tbl_Project_TD_3531034_output.setInt64(i, 2, _mon_sales23672);
        int64_t _tue_sales23673 = _tue_sales3684;
        tbl_Project_TD_3531034_output.setInt64(i, 3, _tue_sales23673);
        int64_t _wed_sales23674 = _wed_sales3685;
        tbl_Project_TD_3531034_output.setInt64(i, 4, _wed_sales23674);
        int64_t _thu_sales23675 = _thu_sales3686;
        tbl_Project_TD_3531034_output.setInt64(i, 5, _thu_sales23675);
        int64_t _fri_sales23676 = _fri_sales3687;
        tbl_Project_TD_3531034_output.setInt64(i, 6, _fri_sales23676);
        int64_t _sat_sales23677 = _sat_sales3688;
        tbl_Project_TD_3531034_output.setInt64(i, 7, _sat_sales23677);
    }
    tbl_Project_TD_3531034_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_3531034_output #Row: " << tbl_Project_TD_3531034_output.getNumRow() << std::endl;
}

void SW_Project_TD_3759542(Table &tbl_JOIN_INNER_TD_4970008_output, Table &tbl_Project_TD_3759542_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(d_week_seq#124 AS d_week_seq1#3662, sun_sales#3682 AS sun_sales1#3663, mon_sales#3683 AS mon_sales1#3664, tue_sales#3684 AS tue_sales1#3665, wed_sales#3685 AS wed_sales1#3666, thu_sales#3686 AS thu_sales1#3667, fri_sales#3687 AS fri_sales1#3668, sat_sales#3688 AS sat_sales1#3669)
    // Input: ListBuffer(d_week_seq#124, sun_sales#3682, mon_sales#3683, tue_sales#3684, wed_sales#3685, thu_sales#3686, fri_sales#3687, sat_sales#3688)
    // Output: ListBuffer(d_week_seq1#3662, sun_sales1#3663, mon_sales1#3664, tue_sales1#3665, wed_sales1#3666, thu_sales1#3667, fri_sales1#3668, sat_sales1#3669)
    int nrow1 = tbl_JOIN_INNER_TD_4970008_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_week_seq124 = tbl_JOIN_INNER_TD_4970008_output.getInt32(i, 0);
        int64_t _sun_sales3682 = tbl_JOIN_INNER_TD_4970008_output.getInt64(i, 1);
        int64_t _mon_sales3683 = tbl_JOIN_INNER_TD_4970008_output.getInt64(i, 2);
        int64_t _tue_sales3684 = tbl_JOIN_INNER_TD_4970008_output.getInt64(i, 3);
        int64_t _wed_sales3685 = tbl_JOIN_INNER_TD_4970008_output.getInt64(i, 4);
        int64_t _thu_sales3686 = tbl_JOIN_INNER_TD_4970008_output.getInt64(i, 5);
        int64_t _fri_sales3687 = tbl_JOIN_INNER_TD_4970008_output.getInt64(i, 6);
        int64_t _sat_sales3688 = tbl_JOIN_INNER_TD_4970008_output.getInt64(i, 7);
        int32_t _d_week_seq13662 = _d_week_seq124;
        tbl_Project_TD_3759542_output.setInt32(i, 0, _d_week_seq13662);
        int64_t _sun_sales13663 = _sun_sales3682;
        tbl_Project_TD_3759542_output.setInt64(i, 1, _sun_sales13663);
        int64_t _mon_sales13664 = _mon_sales3683;
        tbl_Project_TD_3759542_output.setInt64(i, 2, _mon_sales13664);
        int64_t _tue_sales13665 = _tue_sales3684;
        tbl_Project_TD_3759542_output.setInt64(i, 3, _tue_sales13665);
        int64_t _wed_sales13666 = _wed_sales3685;
        tbl_Project_TD_3759542_output.setInt64(i, 4, _wed_sales13666);
        int64_t _thu_sales13667 = _thu_sales3686;
        tbl_Project_TD_3759542_output.setInt64(i, 5, _thu_sales13667);
        int64_t _fri_sales13668 = _fri_sales3687;
        tbl_Project_TD_3759542_output.setInt64(i, 6, _fri_sales13668);
        int64_t _sat_sales13669 = _sat_sales3688;
        tbl_Project_TD_3759542_output.setInt64(i, 7, _sat_sales13669);
    }
    tbl_Project_TD_3759542_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_3759542_output #Row: " << tbl_Project_TD_3759542_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_2353970_key_leftMajor {
    int32_t _d_week_seq13662;
    bool operator==(const SW_JOIN_INNER_TD_2353970_key_leftMajor& other) const {
        return ((_d_week_seq13662 == other._d_week_seq13662));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_2353970_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_2353970_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_week_seq13662));
    }
};
}
struct SW_JOIN_INNER_TD_2353970_payload_leftMajor {
    int32_t _d_week_seq13662;
    int64_t _sun_sales13663;
    int64_t _mon_sales13664;
    int64_t _tue_sales13665;
    int64_t _wed_sales13666;
    int64_t _thu_sales13667;
    int64_t _fri_sales13668;
    int64_t _sat_sales13669;
};
struct SW_JOIN_INNER_TD_2353970_key_rightMajor {
    int32_t _d_week_seq23670;
    bool operator==(const SW_JOIN_INNER_TD_2353970_key_rightMajor& other) const {
        return ((_d_week_seq23670 == other._d_week_seq23670));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_2353970_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_2353970_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<int32_t>()(k._d_week_seq23670));
    }
};
}
struct SW_JOIN_INNER_TD_2353970_payload_rightMajor {
    int32_t _d_week_seq23670;
    int64_t _sun_sales23671;
    int64_t _mon_sales23672;
    int64_t _tue_sales23673;
    int64_t _wed_sales23674;
    int64_t _thu_sales23675;
    int64_t _fri_sales23676;
    int64_t _sat_sales23677;
};
void SW_JOIN_INNER_TD_2353970(Table &tbl_Project_TD_3759542_output, Table &tbl_Project_TD_3531034_output, Table &tbl_JOIN_INNER_TD_2353970_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((d_week_seq1#3662 = (d_week_seq2#3670 - 53)))
    // Left Table: ListBuffer(d_week_seq1#3662, sun_sales1#3663, mon_sales1#3664, tue_sales1#3665, wed_sales1#3666, thu_sales1#3667, fri_sales1#3668, sat_sales1#3669)
    // Right Table: ListBuffer(d_week_seq2#3670, sun_sales2#3671, mon_sales2#3672, tue_sales2#3673, wed_sales2#3674, thu_sales2#3675, fri_sales2#3676, sat_sales2#3677)
    // Output Table: ListBuffer(d_week_seq1#3662, sun_sales1#3663, sun_sales2#3671, mon_sales1#3664, mon_sales2#3672, tue_sales1#3665, tue_sales2#3673, wed_sales1#3666, wed_sales2#3674, thu_sales1#3667, thu_sales2#3675, fri_sales1#3668, fri_sales2#3676, sat_sales1#3669, sat_sales2#3677)
    int left_nrow = tbl_Project_TD_3759542_output.getNumRow();
    int right_nrow = tbl_Project_TD_3531034_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_2353970_key_leftMajor, SW_JOIN_INNER_TD_2353970_payload_leftMajor> ht1;
        int nrow1 = tbl_Project_TD_3759542_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_week_seq13662_k = tbl_Project_TD_3759542_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_2353970_key_leftMajor keyA{_d_week_seq13662_k};
            int32_t _d_week_seq13662 = tbl_Project_TD_3759542_output.getInt32(i, 0);
            int64_t _sun_sales13663 = tbl_Project_TD_3759542_output.getInt64(i, 1);
            int64_t _mon_sales13664 = tbl_Project_TD_3759542_output.getInt64(i, 2);
            int64_t _tue_sales13665 = tbl_Project_TD_3759542_output.getInt64(i, 3);
            int64_t _wed_sales13666 = tbl_Project_TD_3759542_output.getInt64(i, 4);
            int64_t _thu_sales13667 = tbl_Project_TD_3759542_output.getInt64(i, 5);
            int64_t _fri_sales13668 = tbl_Project_TD_3759542_output.getInt64(i, 6);
            int64_t _sat_sales13669 = tbl_Project_TD_3759542_output.getInt64(i, 7);
            SW_JOIN_INNER_TD_2353970_payload_leftMajor payloadA{_d_week_seq13662, _sun_sales13663, _mon_sales13664, _tue_sales13665, _wed_sales13666, _thu_sales13667, _fri_sales13668, _sat_sales13669};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Project_TD_3531034_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_week_seq23670_k = tbl_Project_TD_3531034_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_2353970_key_leftMajor{_d_week_seq23670_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_week_seq13662 = (it->second)._d_week_seq13662;
                int64_t _sun_sales13663 = (it->second)._sun_sales13663;
                int64_t _mon_sales13664 = (it->second)._mon_sales13664;
                int64_t _tue_sales13665 = (it->second)._tue_sales13665;
                int64_t _wed_sales13666 = (it->second)._wed_sales13666;
                int64_t _thu_sales13667 = (it->second)._thu_sales13667;
                int64_t _fri_sales13668 = (it->second)._fri_sales13668;
                int64_t _sat_sales13669 = (it->second)._sat_sales13669;
                int32_t _d_week_seq23670 = tbl_Project_TD_3531034_output.getInt32(i, 0);
                int64_t _sun_sales23671 = tbl_Project_TD_3531034_output.getInt64(i, 1);
                int64_t _mon_sales23672 = tbl_Project_TD_3531034_output.getInt64(i, 2);
                int64_t _tue_sales23673 = tbl_Project_TD_3531034_output.getInt64(i, 3);
                int64_t _wed_sales23674 = tbl_Project_TD_3531034_output.getInt64(i, 4);
                int64_t _thu_sales23675 = tbl_Project_TD_3531034_output.getInt64(i, 5);
                int64_t _fri_sales23676 = tbl_Project_TD_3531034_output.getInt64(i, 6);
                int64_t _sat_sales23677 = tbl_Project_TD_3531034_output.getInt64(i, 7);
                if (_d_week_seq13662 == (_d_week_seq23670 - 53)) {
                    tbl_JOIN_INNER_TD_2353970_output.setInt32(r, 0, _d_week_seq13662);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 1, _sun_sales13663);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 3, _mon_sales13664);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 5, _tue_sales13665);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 7, _wed_sales13666);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 9, _thu_sales13667);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 11, _fri_sales13668);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 13, _sat_sales13669);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 2, _sun_sales23671);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 4, _mon_sales23672);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 6, _tue_sales23673);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 8, _wed_sales23674);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 10, _thu_sales23675);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 12, _fri_sales23676);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 14, _sat_sales23677);
                    r++;
                }
                it++;
            }
        }
        tbl_JOIN_INNER_TD_2353970_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_2353970_key_rightMajor, SW_JOIN_INNER_TD_2353970_payload_rightMajor> ht1;
        int nrow1 = tbl_Project_TD_3531034_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            int32_t _d_week_seq23670_k = tbl_Project_TD_3531034_output.getInt32(i, 0);
            SW_JOIN_INNER_TD_2353970_key_rightMajor keyA{_d_week_seq23670_k};
            int32_t _d_week_seq23670 = tbl_Project_TD_3531034_output.getInt32(i, 0);
            int64_t _sun_sales23671 = tbl_Project_TD_3531034_output.getInt64(i, 1);
            int64_t _mon_sales23672 = tbl_Project_TD_3531034_output.getInt64(i, 2);
            int64_t _tue_sales23673 = tbl_Project_TD_3531034_output.getInt64(i, 3);
            int64_t _wed_sales23674 = tbl_Project_TD_3531034_output.getInt64(i, 4);
            int64_t _thu_sales23675 = tbl_Project_TD_3531034_output.getInt64(i, 5);
            int64_t _fri_sales23676 = tbl_Project_TD_3531034_output.getInt64(i, 6);
            int64_t _sat_sales23677 = tbl_Project_TD_3531034_output.getInt64(i, 7);
            SW_JOIN_INNER_TD_2353970_payload_rightMajor payloadA{_d_week_seq23670, _sun_sales23671, _mon_sales23672, _tue_sales23673, _wed_sales23674, _thu_sales23675, _fri_sales23676, _sat_sales23677};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Project_TD_3759542_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            int32_t _d_week_seq13662_k = tbl_Project_TD_3759542_output.getInt32(i, 0);
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_2353970_key_rightMajor{_d_week_seq13662_k});
            auto it = its.first;
            while (it != its.second) {
                int32_t _d_week_seq23670 = (it->second)._d_week_seq23670;
                int64_t _sun_sales23671 = (it->second)._sun_sales23671;
                int64_t _mon_sales23672 = (it->second)._mon_sales23672;
                int64_t _tue_sales23673 = (it->second)._tue_sales23673;
                int64_t _wed_sales23674 = (it->second)._wed_sales23674;
                int64_t _thu_sales23675 = (it->second)._thu_sales23675;
                int64_t _fri_sales23676 = (it->second)._fri_sales23676;
                int64_t _sat_sales23677 = (it->second)._sat_sales23677;
                int32_t _d_week_seq13662 = tbl_Project_TD_3759542_output.getInt32(i, 0);
                int64_t _sun_sales13663 = tbl_Project_TD_3759542_output.getInt64(i, 1);
                int64_t _mon_sales13664 = tbl_Project_TD_3759542_output.getInt64(i, 2);
                int64_t _tue_sales13665 = tbl_Project_TD_3759542_output.getInt64(i, 3);
                int64_t _wed_sales13666 = tbl_Project_TD_3759542_output.getInt64(i, 4);
                int64_t _thu_sales13667 = tbl_Project_TD_3759542_output.getInt64(i, 5);
                int64_t _fri_sales13668 = tbl_Project_TD_3759542_output.getInt64(i, 6);
                int64_t _sat_sales13669 = tbl_Project_TD_3759542_output.getInt64(i, 7);
                if (_d_week_seq13662 == (_d_week_seq23670 - 53)) {
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 2, _sun_sales23671);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 4, _mon_sales23672);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 6, _tue_sales23673);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 8, _wed_sales23674);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 10, _thu_sales23675);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 12, _fri_sales23676);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 14, _sat_sales23677);
                    tbl_JOIN_INNER_TD_2353970_output.setInt32(r, 0, _d_week_seq13662);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 1, _sun_sales13663);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 3, _mon_sales13664);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 5, _tue_sales13665);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 7, _wed_sales13666);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 9, _thu_sales13667);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 11, _fri_sales13668);
                    tbl_JOIN_INNER_TD_2353970_output.setInt64(r, 13, _sat_sales13669);
                    r++;
                }
                it++;
            }
        }
        tbl_JOIN_INNER_TD_2353970_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_2353970_output #Row: " << tbl_JOIN_INNER_TD_2353970_output.getNumRow() << std::endl;
}

void SW_Project_TD_1645820(Table &tbl_JOIN_INNER_TD_2353970_output, Table &tbl_Project_TD_1645820_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Project
    // Operation: ListBuffer(round(CheckOverflow((promote_precision(sun_sales1#3663) / promote_precision(sun_sales2#3671)), DecimalType(37,20), true), 2) AS round((sun_sales1 / sun_sales2), 2)#3752, round(CheckOverflow((promote_precision(mon_sales1#3664) / promote_precision(mon_sales2#3672)), DecimalType(37,20), true), 2) AS round((mon_sales1 / mon_sales2), 2)#3753, round(CheckOverflow((promote_precision(tue_sales1#3665) / promote_precision(tue_sales2#3673)), DecimalType(37,20), true), 2) AS round((tue_sales1 / tue_sales2), 2)#3754, round(CheckOverflow((promote_precision(wed_sales1#3666) / promote_precision(wed_sales2#3674)), DecimalType(37,20), true), 2) AS round((wed_sales1 / wed_sales2), 2)#3755, round(CheckOverflow((promote_precision(thu_sales1#3667) / promote_precision(thu_sales2#3675)), DecimalType(37,20), true), 2) AS round((thu_sales1 / thu_sales2), 2)#3756, round(CheckOverflow((promote_precision(fri_sales1#3668) / promote_precision(fri_sales2#3676)), DecimalType(37,20), true), 2) AS round((fri_sales1 / fri_sales2), 2)#3757, round(CheckOverflow((promote_precision(sat_sales1#3669) / promote_precision(sat_sales2#3677)), DecimalType(37,20), true), 2) AS round((sat_sales1 / sat_sales2), 2)#3758)
    // Input: ListBuffer(d_week_seq1#3662, sun_sales1#3663, sun_sales2#3671, mon_sales1#3664, mon_sales2#3672, tue_sales1#3665, tue_sales2#3673, wed_sales1#3666, wed_sales2#3674, thu_sales1#3667, thu_sales2#3675, fri_sales1#3668, fri_sales2#3676, sat_sales1#3669, sat_sales2#3677)
    // Output: ListBuffer(d_week_seq1#3662, round((sun_sales1 / sun_sales2), 2)#3752, round((mon_sales1 / mon_sales2), 2)#3753, round((tue_sales1 / tue_sales2), 2)#3754, round((wed_sales1 / wed_sales2), 2)#3755, round((thu_sales1 / thu_sales2), 2)#3756, round((fri_sales1 / fri_sales2), 2)#3757, round((sat_sales1 / sat_sales2), 2)#3758)
    int nrow1 = tbl_JOIN_INNER_TD_2353970_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_week_seq13662 = tbl_JOIN_INNER_TD_2353970_output.getInt32(i, 0);
        int64_t _sun_sales13663 = tbl_JOIN_INNER_TD_2353970_output.getInt64(i, 1);
        int64_t _sun_sales23671 = tbl_JOIN_INNER_TD_2353970_output.getInt64(i, 2);
        int64_t _mon_sales13664 = tbl_JOIN_INNER_TD_2353970_output.getInt64(i, 3);
        int64_t _mon_sales23672 = tbl_JOIN_INNER_TD_2353970_output.getInt64(i, 4);
        int64_t _tue_sales13665 = tbl_JOIN_INNER_TD_2353970_output.getInt64(i, 5);
        int64_t _tue_sales23673 = tbl_JOIN_INNER_TD_2353970_output.getInt64(i, 6);
        int64_t _wed_sales13666 = tbl_JOIN_INNER_TD_2353970_output.getInt64(i, 7);
        int64_t _wed_sales23674 = tbl_JOIN_INNER_TD_2353970_output.getInt64(i, 8);
        int64_t _thu_sales13667 = tbl_JOIN_INNER_TD_2353970_output.getInt64(i, 9);
        int64_t _thu_sales23675 = tbl_JOIN_INNER_TD_2353970_output.getInt64(i, 10);
        int64_t _fri_sales13668 = tbl_JOIN_INNER_TD_2353970_output.getInt64(i, 11);
        int64_t _fri_sales23676 = tbl_JOIN_INNER_TD_2353970_output.getInt64(i, 12);
        int64_t _sat_sales13669 = tbl_JOIN_INNER_TD_2353970_output.getInt64(i, 13);
        int64_t _sat_sales23677 = tbl_JOIN_INNER_TD_2353970_output.getInt64(i, 14);
        int64_t _23752 = (_sun_sales13663 / _sun_sales23671);
        tbl_Project_TD_1645820_output.setInt64(i, 1, _23752);
        int64_t _23753 = (_mon_sales13664 / _mon_sales23672);
        tbl_Project_TD_1645820_output.setInt64(i, 2, _23753);
        int64_t _23754 = (_tue_sales13665 / _tue_sales23673);
        tbl_Project_TD_1645820_output.setInt64(i, 3, _23754);
        int64_t _23755 = (_wed_sales13666 / _wed_sales23674);
        tbl_Project_TD_1645820_output.setInt64(i, 4, _23755);
        int64_t _23756 = (_thu_sales13667 / _thu_sales23675);
        tbl_Project_TD_1645820_output.setInt64(i, 5, _23756);
        int64_t _23757 = (_fri_sales13668 / _fri_sales23676);
        tbl_Project_TD_1645820_output.setInt64(i, 6, _23757);
        int64_t _23758 = (_sat_sales13669 / _sat_sales23677);
        tbl_Project_TD_1645820_output.setInt64(i, 7, _23758);
        tbl_Project_TD_1645820_output.setInt32(i, 0, _d_week_seq13662);
    }
    tbl_Project_TD_1645820_output.setNumRow(nrow1);
    std::cout << "tbl_Project_TD_1645820_output #Row: " << tbl_Project_TD_1645820_output.getNumRow() << std::endl;
}

void SW_Sort_TD_0638674(Table &tbl_Project_TD_1645820_output, Table &tbl_Sort_TD_0638674_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(d_week_seq1#3662 ASC NULLS FIRST)
    // Input: ListBuffer(d_week_seq1#3662, round((sun_sales1 / sun_sales2), 2)#3752, round((mon_sales1 / mon_sales2), 2)#3753, round((tue_sales1 / tue_sales2), 2)#3754, round((wed_sales1 / wed_sales2), 2)#3755, round((thu_sales1 / thu_sales2), 2)#3756, round((fri_sales1 / fri_sales2), 2)#3757, round((sat_sales1 / sat_sales2), 2)#3758)
    // Output: ListBuffer(d_week_seq1#3662, round((sun_sales1 / sun_sales2), 2)#3752, round((mon_sales1 / mon_sales2), 2)#3753, round((tue_sales1 / tue_sales2), 2)#3754, round((wed_sales1 / wed_sales2), 2)#3755, round((thu_sales1 / thu_sales2), 2)#3756, round((fri_sales1 / fri_sales2), 2)#3757, round((sat_sales1 / sat_sales2), 2)#3758)
    struct SW_Sort_TD_0638674Row {
        int32_t _d_week_seq13662;
        int64_t _23752;
        int64_t _23753;
        int64_t _23754;
        int64_t _23755;
        int64_t _23756;
        int64_t _23757;
        int64_t _23758;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_0638674Row& a, const SW_Sort_TD_0638674Row& b) const { return 
 (a._d_week_seq13662 < b._d_week_seq13662); 
}
    }SW_Sort_TD_0638674_order; 

    int nrow1 = tbl_Project_TD_1645820_output.getNumRow();
    std::vector<SW_Sort_TD_0638674Row> rows;
    for (int i = 0; i < nrow1; i++) {
        int32_t _d_week_seq13662 = tbl_Project_TD_1645820_output.getInt32(i, 0);
        int64_t _23752 = tbl_Project_TD_1645820_output.getInt64(i, 1);
        int64_t _23753 = tbl_Project_TD_1645820_output.getInt64(i, 2);
        int64_t _23754 = tbl_Project_TD_1645820_output.getInt64(i, 3);
        int64_t _23755 = tbl_Project_TD_1645820_output.getInt64(i, 4);
        int64_t _23756 = tbl_Project_TD_1645820_output.getInt64(i, 5);
        int64_t _23757 = tbl_Project_TD_1645820_output.getInt64(i, 6);
        int64_t _23758 = tbl_Project_TD_1645820_output.getInt64(i, 7);
        SW_Sort_TD_0638674Row t = {_d_week_seq13662,_23752,_23753,_23754,_23755,_23756,_23757,_23758};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_0638674_order);
    int r = 0;
    for (auto& it : rows) {
        tbl_Sort_TD_0638674_output.setInt32(r, 0, it._d_week_seq13662);
        tbl_Sort_TD_0638674_output.setInt64(r, 1, it._23752);
        tbl_Sort_TD_0638674_output.setInt64(r, 2, it._23753);
        tbl_Sort_TD_0638674_output.setInt64(r, 3, it._23754);
        tbl_Sort_TD_0638674_output.setInt64(r, 4, it._23755);
        tbl_Sort_TD_0638674_output.setInt64(r, 5, it._23756);
        tbl_Sort_TD_0638674_output.setInt64(r, 6, it._23757);
        tbl_Sort_TD_0638674_output.setInt64(r, 7, it._23758);
        if (r < 10) {
            std::cout << it._d_week_seq13662 << " " << it._23752 << " " << it._23753 << " " << it._23754 << " " << it._23755 << " " << it._23756 << " " << it._23757 << " " << it._23758 << " " << std::endl;
        }
        ++r;
    }
    tbl_Sort_TD_0638674_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_0638674_output #Row: " << tbl_Sort_TD_0638674_output.getNumRow() << std::endl;
}

