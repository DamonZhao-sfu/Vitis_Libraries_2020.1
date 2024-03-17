#include <regex> 
#include <stdint.h> 
#include "utils.hpp"

void SW_Filter_TD_7990412(Table &tbl_SerializeFromObject_TD_8140664_input, Table &tbl_Filter_TD_7990412_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((((((i_category#3559 = Women) AND (((((i_color#3564 = powder) OR (i_color#3564 = khaki)) AND ((i_units#3565 = Ounce) OR (i_units#3565 = Oz))) AND ((i_size#3562 = medium) OR (i_size#3562 = extra large))) OR ((((i_color#3564 = brown) OR (i_color#3564 = honeydew)) AND ((i_units#3565 = Bunch) OR (i_units#3565 = Ton))) AND ((i_size#3562 = N/A) OR (i_size#3562 = small))))) OR ((i_category#3559 = Men) AND (((((i_color#3564 = floral) OR (i_color#3564 = deep)) AND ((i_units#3565 = N/A) OR (i_units#3565 = Dozen))) AND ((i_size#3562 = petite) OR (i_size#3562 = large))) OR ((((i_color#3564 = light) OR (i_color#3564 = cornflower)) AND ((i_units#3565 = Box) OR (i_units#3565 = Pound))) AND ((i_size#3562 = medium) OR (i_size#3562 = extra large)))))) OR (((i_category#3559 = Women) AND (((((i_color#3564 = midnight) OR (i_color#3564 = snow)) AND ((i_units#3565 = Pallet) OR (i_units#3565 = Gross))) AND ((i_size#3562 = medium) OR (i_size#3562 = extra large))) OR ((((i_color#3564 = cyan) OR (i_color#3564 = papaya)) AND ((i_units#3565 = Cup) OR (i_units#3565 = Dram))) AND ((i_size#3562 = N/A) OR (i_size#3562 = small))))) OR ((i_category#3559 = Men) AND (((((i_color#3564 = orange) OR (i_color#3564 = frosted)) AND ((i_units#3565 = Each) OR (i_units#3565 = Tbl))) AND ((i_size#3562 = petite) OR (i_size#3562 = large))) OR ((((i_color#3564 = forest) OR (i_color#3564 = ghost)) AND ((i_units#3565 = Lb) OR (i_units#3565 = Bundle))) AND ((i_size#3562 = medium) OR (i_size#3562 = extra large))))))) AND isnotnull(i_manufact#3561)))
    // Input: ListBuffer(i_manufact#3561, i_category#3559, i_color#3564, i_units#3565, i_size#3562)
    // Output: ListBuffer(i_manufact#3561)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_8140664_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_category3559 = tbl_SerializeFromObject_TD_8140664_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
        std::array<char, TPCDS_READ_MAX + 1> _i_color3564 = tbl_SerializeFromObject_TD_8140664_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _i_units3565 = tbl_SerializeFromObject_TD_8140664_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 3);
        std::array<char, TPCDS_READ_MAX + 1> _i_size3562 = tbl_SerializeFromObject_TD_8140664_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 4);
        std::array<char, TPCDS_READ_MAX + 1> _i_manufact3561 = tbl_SerializeFromObject_TD_8140664_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        if (((((std::string(_i_category3559.data()) == "Women") && (((((std::string(_i_color3564.data()) == "powder") || (std::string(_i_color3564.data()) == "khaki")) && ((std::string(_i_units3565.data()) == "Ounce") || (std::string(_i_units3565.data()) == "Oz"))) && ((std::string(_i_size3562.data()) == "medium") || (std::string(_i_size3562.data()) == "extra large"))) || ((((std::string(_i_color3564.data()) == "brown") || (std::string(_i_color3564.data()) == "honeydew")) && ((std::string(_i_units3565.data()) == "Bunch") || (std::string(_i_units3565.data()) == "Ton"))) && ((std::string(_i_size3562.data()) == "N/A") || (std::string(_i_size3562.data()) == "small"))))) || ((std::string(_i_category3559.data()) == "Men") && (((((std::string(_i_color3564.data()) == "floral") || (std::string(_i_color3564.data()) == "deep")) && ((std::string(_i_units3565.data()) == "N/A") || (std::string(_i_units3565.data()) == "Dozen"))) && ((std::string(_i_size3562.data()) == "petite") || (std::string(_i_size3562.data()) == "large"))) || ((((std::string(_i_color3564.data()) == "light") || (std::string(_i_color3564.data()) == "cornflower")) && ((std::string(_i_units3565.data()) == "Box") || (std::string(_i_units3565.data()) == "Pound"))) && ((std::string(_i_size3562.data()) == "medium") || (std::string(_i_size3562.data()) == "extra large")))))) || (((std::string(_i_category3559.data()) == "Women") && (((((std::string(_i_color3564.data()) == "midnight") || (std::string(_i_color3564.data()) == "snow")) && ((std::string(_i_units3565.data()) == "Pallet") || (std::string(_i_units3565.data()) == "Gross"))) && ((std::string(_i_size3562.data()) == "medium") || (std::string(_i_size3562.data()) == "extra large"))) || ((((std::string(_i_color3564.data()) == "cyan") || (std::string(_i_color3564.data()) == "papaya")) && ((std::string(_i_units3565.data()) == "Cup") || (std::string(_i_units3565.data()) == "Dram"))) && ((std::string(_i_size3562.data()) == "N/A") || (std::string(_i_size3562.data()) == "small"))))) || ((std::string(_i_category3559.data()) == "Men") && (((((std::string(_i_color3564.data()) == "orange") || (std::string(_i_color3564.data()) == "frosted")) && ((std::string(_i_units3565.data()) == "Each") || (std::string(_i_units3565.data()) == "Tbl"))) && ((std::string(_i_size3562.data()) == "petite") || (std::string(_i_size3562.data()) == "large"))) || ((((std::string(_i_color3564.data()) == "forest") || (std::string(_i_color3564.data()) == "ghost")) && ((std::string(_i_units3565.data()) == "Lb") || (std::string(_i_units3565.data()) == "Bundle"))) && ((std::string(_i_size3562.data()) == "medium") || (std::string(_i_size3562.data()) == "extra large"))))))) && _i_manufact3561.data() != "NULL") {
            std::array<char, TPCDS_READ_MAX + 1> _i_manufact3561_t = tbl_SerializeFromObject_TD_8140664_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            tbl_Filter_TD_7990412_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_manufact3561_t);
            r++;
        }
    }
    tbl_Filter_TD_7990412_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_7990412_output #Row: " << tbl_Filter_TD_7990412_output.getNumRow() << std::endl;
}

typedef std::string SW_Aggregate_TD_6957621_key;
struct SW_Aggregate_TD_6957621_payload {
    int64_t _item_cnt3544L_count_0;
};
void SW_Aggregate_TD_6957621(Table &tbl_Filter_TD_7990412_output, Table &tbl_Aggregate_TD_6957621_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(i_manufact#3561, count(1) AS item_cnt#3544L)
    // Input: ListBuffer(i_manufact#3561)
    // Output: ListBuffer(item_cnt#3544L, i_manufact#3561)
    std::unordered_map<SW_Aggregate_TD_6957621_key, SW_Aggregate_TD_6957621_payload> ht1;
    int nrow1 = tbl_Filter_TD_7990412_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_manufact3561 = tbl_Filter_TD_7990412_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        SW_Aggregate_TD_6957621_key k = std::string(_i_manufact3561.data());
        int64_t _item_cnt3544L_count_0 = 1 != 0 ? 1 : 0;
        SW_Aggregate_TD_6957621_payload p{_item_cnt3544L_count_0};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            int64_t count_0 = (it->second)._item_cnt3544L_count_0 + _item_cnt3544L_count_0;
            p._item_cnt3544L_count_0 = count_0;
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _i_manufact3561{};
        memcpy(_i_manufact3561.data(), (it.first).data(), (it.first).length());
        tbl_Aggregate_TD_6957621_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_manufact3561);
        int64_t _item_cnt3544L = (it.second)._item_cnt3544L_count_0;
        tbl_Aggregate_TD_6957621_output.setInt64(r, 0, _item_cnt3544L);
        ++r;
    }
    tbl_Aggregate_TD_6957621_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_6957621_output #Row: " << tbl_Aggregate_TD_6957621_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5935086(Table &tbl_Aggregate_TD_6957621_output, Table &tbl_Filter_TD_5935086_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer((item_cnt#3544L > 0))
    // Input: ListBuffer(item_cnt#3544L, i_manufact#3561)
    // Output: ListBuffer(i_manufact#3561)
    int r = 0;
    int nrow1 = tbl_Aggregate_TD_6957621_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int64_t _item_cnt3544L = tbl_Aggregate_TD_6957621_output.getInt64(i, 0);
        if (_item_cnt3544L > 0) {
            std::array<char, TPCDS_READ_MAX + 1> _i_manufact3561_t = tbl_Aggregate_TD_6957621_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_5935086_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_manufact3561_t);
            r++;
        }
    }
    tbl_Filter_TD_5935086_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5935086_output #Row: " << tbl_Filter_TD_5935086_output.getNumRow() << std::endl;
}

void SW_Filter_TD_5361033(Table &tbl_SerializeFromObject_TD_6141526_input, Table &tbl_Filter_TD_5361033_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Filter
    // Operation: ListBuffer(((isnotnull(i_manufact_id#241) AND ((i_manufact_id#241 >= 738) AND (i_manufact_id#241 <= 778))) AND isnotnull(i_manufact#242)))
    // Input: ListBuffer(i_manufact#242, i_product_name#249, i_manufact_id#241)
    // Output: ListBuffer(i_manufact#242, i_product_name#249)
    int r = 0;
    int nrow1 = tbl_SerializeFromObject_TD_6141526_input.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        int32_t _i_manufact_id241 = tbl_SerializeFromObject_TD_6141526_input.getInt32(i, 2);
        std::array<char, TPCDS_READ_MAX + 1> _i_manufact242 = tbl_SerializeFromObject_TD_6141526_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        if (((_i_manufact_id241!= 0) && ((_i_manufact_id241 >= 738) && (_i_manufact_id241 <= 778))) && _i_manufact242.data() != "NULL") {
            std::array<char, TPCDS_READ_MAX + 1> _i_manufact242_t = tbl_SerializeFromObject_TD_6141526_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            tbl_Filter_TD_5361033_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_manufact242_t);
            std::array<char, TPCDS_READ_MAX + 1> _i_product_name249_t = tbl_SerializeFromObject_TD_6141526_input.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            tbl_Filter_TD_5361033_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 1, _i_product_name249_t);
            r++;
        }
    }
    tbl_Filter_TD_5361033_output.setNumRow(r);
    std::cout << "tbl_Filter_TD_5361033_output #Row: " << tbl_Filter_TD_5361033_output.getNumRow() << std::endl;
}

struct SW_JOIN_INNER_TD_4927887_key_leftMajor {
    std::string _i_manufact242;
    bool operator==(const SW_JOIN_INNER_TD_4927887_key_leftMajor& other) const {
        return ((_i_manufact242 == other._i_manufact242));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4927887_key_leftMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4927887_key_leftMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_manufact242));
    }
};
}
struct SW_JOIN_INNER_TD_4927887_payload_leftMajor {
    std::string _i_manufact242;
    std::string _i_product_name249;
};
struct SW_JOIN_INNER_TD_4927887_key_rightMajor {
    std::string _i_manufact3561;
    bool operator==(const SW_JOIN_INNER_TD_4927887_key_rightMajor& other) const {
        return ((_i_manufact3561 == other._i_manufact3561));
    }
};
namespace std {
template <>
struct hash<SW_JOIN_INNER_TD_4927887_key_rightMajor> {
    std::size_t operator() (const SW_JOIN_INNER_TD_4927887_key_rightMajor& k) const {
        using std::size_t;
        using std::hash;
        using std::string;
        return (hash<string>()(k._i_manufact3561));
    }
};
}
struct SW_JOIN_INNER_TD_4927887_payload_rightMajor {
    std::string _i_manufact3561;
};
void SW_JOIN_INNER_TD_4927887(Table &tbl_Filter_TD_5361033_output, Table &tbl_Filter_TD_5935086_output, Table &tbl_JOIN_INNER_TD_4927887_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: JOIN_INNER
    // Operation: ListBuffer((i_manufact#3561 = i_manufact#242))
    // Left Table: ListBuffer(i_manufact#242, i_product_name#249)
    // Right Table: ListBuffer(i_manufact#3561)
    // Output Table: ListBuffer(i_product_name#249)
    int left_nrow = tbl_Filter_TD_5361033_output.getNumRow();
    int right_nrow = tbl_Filter_TD_5935086_output.getNumRow();
    if (left_nrow < right_nrow) { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4927887_key_leftMajor, SW_JOIN_INNER_TD_4927887_payload_leftMajor> ht1;
        int nrow1 = tbl_Filter_TD_5361033_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_manufact242_k_n = tbl_Filter_TD_5361033_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_manufact242_k = std::string(_i_manufact242_k_n.data());
            SW_JOIN_INNER_TD_4927887_key_leftMajor keyA{_i_manufact242_k};
            std::array<char, TPCDS_READ_MAX + 1> _i_manufact242_n = tbl_Filter_TD_5361033_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_manufact242 = std::string(_i_manufact242_n.data());
            std::array<char, TPCDS_READ_MAX + 1> _i_product_name249_n = tbl_Filter_TD_5361033_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
            std::string _i_product_name249 = std::string(_i_product_name249_n.data());
            SW_JOIN_INNER_TD_4927887_payload_leftMajor payloadA{_i_manufact242, _i_product_name249};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5935086_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_manufact3561_k_n = tbl_Filter_TD_5935086_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_manufact3561_k = std::string(_i_manufact3561_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4927887_key_leftMajor{_i_manufact3561_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _i_manufact242 = (it->second)._i_manufact242;
                std::array<char, TPCDS_READ_MAX + 1> _i_manufact242_n{};
                memcpy(_i_manufact242_n.data(), (_i_manufact242).data(), (_i_manufact242).length());
                std::string _i_product_name249 = (it->second)._i_product_name249;
                std::array<char, TPCDS_READ_MAX + 1> _i_product_name249_n{};
                memcpy(_i_product_name249_n.data(), (_i_product_name249).data(), (_i_product_name249).length());
                std::array<char, TPCDS_READ_MAX + 1> _i_manufact3561_n = tbl_Filter_TD_5935086_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _i_manufact3561 = std::string(_i_manufact3561_n.data());
                tbl_JOIN_INNER_TD_4927887_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_product_name249_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4927887_output.setNumRow(r);
    } else { 
        std::unordered_multimap<SW_JOIN_INNER_TD_4927887_key_rightMajor, SW_JOIN_INNER_TD_4927887_payload_rightMajor> ht1;
        int nrow1 = tbl_Filter_TD_5935086_output.getNumRow();
        for (int i = 0; i < nrow1; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_manufact3561_k_n = tbl_Filter_TD_5935086_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_manufact3561_k = std::string(_i_manufact3561_k_n.data());
            SW_JOIN_INNER_TD_4927887_key_rightMajor keyA{_i_manufact3561_k};
            std::array<char, TPCDS_READ_MAX + 1> _i_manufact3561_n = tbl_Filter_TD_5935086_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_manufact3561 = std::string(_i_manufact3561_n.data());
            SW_JOIN_INNER_TD_4927887_payload_rightMajor payloadA{_i_manufact3561};
            ht1.insert(std::make_pair(keyA, payloadA));
        }
        int r = 0;
        int nrow2 = tbl_Filter_TD_5361033_output.getNumRow();
        for (int i = 0; i < nrow2; i++) {
            std::array<char, TPCDS_READ_MAX + 1> _i_manufact242_k_n = tbl_Filter_TD_5361033_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
            std::string _i_manufact242_k = std::string(_i_manufact242_k_n.data());
            auto its = ht1.equal_range(SW_JOIN_INNER_TD_4927887_key_rightMajor{_i_manufact242_k});
            auto it = its.first;
            while (it != its.second) {
                std::string _i_manufact3561 = (it->second)._i_manufact3561;
                std::array<char, TPCDS_READ_MAX + 1> _i_manufact3561_n{};
                memcpy(_i_manufact3561_n.data(), (_i_manufact3561).data(), (_i_manufact3561).length());
                std::array<char, TPCDS_READ_MAX + 1> _i_manufact242_n = tbl_Filter_TD_5361033_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
                std::string _i_manufact242 = std::string(_i_manufact242_n.data());
                std::array<char, TPCDS_READ_MAX + 1> _i_product_name249_n = tbl_Filter_TD_5361033_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 1);
                std::string _i_product_name249 = std::string(_i_product_name249_n.data());
                tbl_JOIN_INNER_TD_4927887_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_product_name249_n);
                it++;
                r++;
            }
        }
        tbl_JOIN_INNER_TD_4927887_output.setNumRow(r);
    } 
    std::cout << "tbl_JOIN_INNER_TD_4927887_output #Row: " << tbl_JOIN_INNER_TD_4927887_output.getNumRow() << std::endl;
}

typedef std::string SW_Aggregate_TD_344476_key;
struct SW_Aggregate_TD_344476_payload {
};
void SW_Aggregate_TD_344476(Table &tbl_JOIN_INNER_TD_4927887_output, Table &tbl_Aggregate_TD_344476_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Aggregate
    // Operation: ListBuffer(i_product_name#249)
    // Input: ListBuffer(i_product_name#249)
    // Output: ListBuffer(i_product_name#249)
    std::unordered_map<SW_Aggregate_TD_344476_key, SW_Aggregate_TD_344476_payload> ht1;
    int nrow1 = tbl_JOIN_INNER_TD_4927887_output.getNumRow();
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_product_name249 = tbl_JOIN_INNER_TD_4927887_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        SW_Aggregate_TD_344476_key k = std::string(_i_product_name249.data());
        SW_Aggregate_TD_344476_payload p{};
        auto it = ht1.find(k);
        if (it != ht1.end()) {
            ht1[k] = p;
        } else { 
            ht1.insert(std::make_pair(k, p));
        }
    }
    int r = 0;
    for (auto& it : ht1) {
        std::array<char, TPCDS_READ_MAX + 1> _i_product_name249{};
        memcpy(_i_product_name249.data(), (it.first).data(), (it.first).length());
        tbl_Aggregate_TD_344476_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_product_name249);
        ++r;
    }
    tbl_Aggregate_TD_344476_output.setNumRow(r);
    std::cout << "tbl_Aggregate_TD_344476_output #Row: " << tbl_Aggregate_TD_344476_output.getNumRow() << std::endl;
}

void SW_Sort_TD_2224667(Table &tbl_Aggregate_TD_344476_output, Table &tbl_Sort_TD_2224667_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: Sort
    // Operation: ListBuffer(i_product_name#249 ASC NULLS FIRST)
    // Input: ListBuffer(i_product_name#249)
    // Output: ListBuffer(i_product_name#249)
    struct SW_Sort_TD_2224667Row {
        std::string _i_product_name249;
    }; 

    struct {
        bool operator()(const SW_Sort_TD_2224667Row& a, const SW_Sort_TD_2224667Row& b) const { return 
 (a._i_product_name249 < b._i_product_name249); 
}
    }SW_Sort_TD_2224667_order; 

    int nrow1 = tbl_Aggregate_TD_344476_output.getNumRow();
    std::vector<SW_Sort_TD_2224667Row> rows;
    for (int i = 0; i < nrow1; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_product_name249 = tbl_Aggregate_TD_344476_output.getcharN<char, TPCDS_READ_MAX +1>(i, 0);
        SW_Sort_TD_2224667Row t = {std::string(_i_product_name249.data())};
        rows.push_back(t);
    }
    std::sort(rows.begin(), rows.end(), SW_Sort_TD_2224667_order);
    int r = 0;
    for (auto& it : rows) {
        std::array<char, TPCDS_READ_MAX + 1> _i_product_name249{};
        memcpy(_i_product_name249.data(), (it._i_product_name249).data(), (it._i_product_name249).length());
        tbl_Sort_TD_2224667_output.setcharN<char, TPCDS_READ_MAX +1>(r, 0, _i_product_name249);
        ++r;
    }
    tbl_Sort_TD_2224667_output.setNumRow(r);
    std::cout << "tbl_Sort_TD_2224667_output #Row: " << tbl_Sort_TD_2224667_output.getNumRow() << std::endl;
}

void SW_LocalLimit_TD_1722381(Table &tbl_Sort_TD_2224667_output, Table &tbl_LocalLimit_TD_1722381_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: LocalLimit
    // Operation: ListBuffer(locallimit)
    // Input: ListBuffer(i_product_name#249)
    // Output: ListBuffer(i_product_name#249)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_product_name249_n = tbl_Sort_TD_2224667_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_LocalLimit_TD_1722381_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_product_name249_n);
        r++;
    }
    tbl_LocalLimit_TD_1722381_output.setNumRow(r);
    std::cout << "tbl_LocalLimit_TD_1722381_output #Row: " << tbl_LocalLimit_TD_1722381_output.getNumRow() << std::endl;
}

void SW_GlobalLimit_TD_0845238(Table &tbl_LocalLimit_TD_1722381_output, Table &tbl_GlobalLimit_TD_0845238_output) {
    // StringRowIDSubstitution: false StringRowIDBackSubstitution: false
    // Supported operation: GlobalLimit
    // Operation: ListBuffer(globallimit)
    // Input: ListBuffer(i_product_name#249)
    // Output: ListBuffer(i_product_name#249)
    int r = 0;
    int nrow = 100;
    for (int i = 0; i < nrow; i++) {
        std::array<char, TPCDS_READ_MAX + 1> _i_product_name249_n = tbl_LocalLimit_TD_1722381_output.getcharN<char, TPCDS_READ_MAX + 1>(i, 0);
        tbl_GlobalLimit_TD_0845238_output.setcharN<char, TPCDS_READ_MAX + 1>(r, 0, _i_product_name249_n);
        r++;
    }
    tbl_GlobalLimit_TD_0845238_output.setNumRow(r);
    std::cout << "tbl_GlobalLimit_TD_0845238_output #Row: " << tbl_GlobalLimit_TD_0845238_output.getNumRow() << std::endl;
}

