
#ifndef _TPCDS_READ_H
#define _TPCDS_READ_H

#include <cstdio>
#include <istream>
#include <ostream>
#include <vector>

#include <stdint.h>
typedef int32_t TPCDS_INT;

// #define TPCH_READ_PHONE_LEN 15
// #define TPCH_READ_C_NAME_LEN 18
// #define TPCH_READ_C_ADDR_MAX 40
// #define TPCH_READ_MAXAGG_LEN 20
// #define TPCH_READ_C_CMNT_MAX 117
// #define TPCH_READ_DATE_LEN 13
// #define TPCH_READ_O_CLRK_LEN 15
// #define TPCH_READ_O_CMNT_MAX 79
// #define TPCH_READ_L_CMNT_MAX 44
// #define TPCH_READ_NATION_LEN 25
// #define TPCH_READ_N_CMNT_MAX 152
// #define TPCH_READ_REGION_LEN 25
// #define TPCH_READ_R_CMNT_MAX 152
// #define TPCH_READ_PS_CMNT_MAX 199
// #define TPCH_READ_S_NAME_LEN 25
// #define TPCH_READ_S_ADDR_MAX 40
// #define TPCH_READ_S_CMNT_MAX 101
// #define TPCH_READ_P_NAME_LEN 55
// #define TPCH_READ_P_MFG_LEN 25
// #define TPCH_READ_P_BRND_LEN 10
// #define TPCH_READ_P_TYPE_LEN 25
// #define TPCH_READ_P_CNTR_LEN 10
// #define TPCH_READ_P_CMNT_MAX 23

#define TPCDS_READ_MAX 50
#define TPCDS_READ_I_BRAND_MAX 30

// #define SF1_LINEITEM 6001215
// #define SF1_ORDERS 1500000
// #define SF1_NATION 25
// #define SF1_PART 200000
// #define SF1_PARTSUPP 800000
// #define SF1_REGION 5
// #define SF1_CUSTOMER 150000
// #define SF1_SUPPLIER 10000


/* tpch_read.h provide read interface to access .tbl of TPC-H.
 * There're 8 kinds of .tbl files and tpch_read.h offers Read Row and Read Column.
 *
 * class d_long_tpcds is wrapper of "long". class template d_string_tpcds is wrapper of "char[]".
 * They both have overload operator << and >> to facilitate input and output.
 * d_money_tpcds is wrapper of "long", too. it storage money in cent.
 * d_string_tpcds's member "char data[num]" contains effective chars(num-1 chars,at most), ending with '\0'.
 * d_string_tpcds's member "int len" indicate effective number of chars, including spaces.
 *
 * xxx_t is "Row" of the tbl file. and xxx_t_col is "Column" of the tbl file.
 * xxx_t_col stores each column in tbl in an vector, along with "long volumn" and "long count".
 * "long volumn" indicates the size of vector, "long count" indicates effective number of record in vector.
 * member function change_volumn is to resize each vector.
 * operator << will output effective data, keep the remaining data.
 * operator >> will overwrite its data from the begining and stop when it's fullfilled or runout of data.
 * "long count" will equals to "long volumn" or num of records.
 * */

class d_long_tpcds {
   public:
    TPCDS_INT data;

    d_long_tpcds() : data(0) {}

    operator TPCDS_INT() const { return data; }

    friend std::ostream& operator<<(std::ostream& output, d_long_tpcds& source) {
        output << (source.data) << '|';
        return output;
    }

    friend std::istream& operator>>(std::istream& input, d_long_tpcds& target) {
        input >> (target.data);
        input.get();
        return input;
    }
};

class d_date_tpcds {
   public:
    TPCDS_INT data;

    d_date_tpcds() : data(0) {}

    operator TPCDS_INT() const { return data; }

    friend std::ostream& operator<<(std::ostream& output, d_date_tpcds& source) {
        int year, month, day;
        year = source.data / 10000;
        month = (source.data % 10000) / 100;
        day = source.data % 100;
        output << year << '-';
        if (month < 10) {
            output << '0';
        }
        output << month << '-';
        if (day < 10) {
            output << '0';
        }
        output << day << '|';
        return output;
    }

    friend std::istream& operator>>(std::istream& input, d_date_tpcds& target) {
        int year, month, day;
        input >> year;
        if (year == 0) {
            target.data = 0;
        } else {
            input.get();
            input >> month;
            input.get();
            input >> day;
            input.get();
            target.data = year * 10000 + month * 100 + day;
        }
        return input;
    }
};

class d_money_tpcds {
   public:
    TPCDS_INT data;

    d_money_tpcds() : data(0) {}

    operator TPCDS_INT() const { return data; }

    friend std::ostream& operator<<(std::ostream& output, d_money_tpcds& source) {
        TPCDS_INT cents, dollars;
        cents = source.data;
        if (cents < 0) {
            output << '.';
            cents = -cents;
        }
        dollars = cents / 100;
        cents %= 100;
        output << dollars << '.';
        if (cents < 10) {
            output << '0';
        }
        output << cents << '|';
        return output;
    }

    /*friend std::istream& operator>>(std::istream& input, d_money_tpcds& target) {
        TPCDS_INT cents, dollars;
        input >> dollars;
        input.get();
        input >> cents;
        input.get();
        if (dollars < 0) {
            target.data = -((-dollars) * 100 + cents);
        } else {
            target.data = dollars * 100 + cents;
        }
        return input;
    }*/
    friend std::istream& operator>>(std::istream& input, d_money_tpcds& target) {
        TPCDS_INT cents, dollars;
        char prefix = input.get();
        if (prefix == '-') {
            input >> dollars;
            input.get();
        } else if (prefix > 0 && prefix < 127) {
            dollars = prefix - '0';
            char nextchar = input.get();
            //          printf("%c\n",prefix);
            //         printf("%d\n",nextchar);
            while (nextchar != '.') {
                if (nextchar == '|') {
                    if (prefix == '-') {
                        target.data = -(dollars * 100);
                    } else {
                        target.data = dollars * 100;
                    }
                    return input;
                }
                dollars = 10 * dollars + (nextchar - '0');
                nextchar = input.get();
            }
        }
        input >> cents;
        input.get();
        if (prefix == '-') {
            target.data = -(dollars * 100 + cents);
        } else {
            target.data = dollars * 100 + cents;
        }
        //        printf("%d\n",target.data);
        return input;
    }
};

template <long num>
class d_string_tpcds {
   public:
    char data[num];
    int len;

    d_string_tpcds() : len(0) {}

    friend std::ostream& operator<<(std::ostream& output, d_string_tpcds<num>& source) {
        long i;
        for (i = 0; i < source.len; i++) {
            output.put(source.data[i]);
        }
        output.put('|');
        return output;
    }

    friend std::istream& operator>>(std::istream& input, d_string_tpcds<num>& target) {
        char tmp;
        int i;
        for (i = 0; i < num; i++) {
            tmp = input.get();
            if (tmp != '|') {
                target.data[i] = tmp;
            } else {
                target.data[i] = '\0';
                break;
            }
        }
        target.len = i;
        if (i == num) {
            target.data[num - 1] = '\0';
        }
        for (; i < num; i++) {
            target.data[i] = '\0';
        }
        return input;
    }
};



class item_t {
   public:
    d_long_tpcds i_item_sk;
    d_string_tpcds<TPCDS_READ_MAX + 1>i_item_id;
    d_string_tpcds<TPCDS_READ_MAX + 1> i_rec_start_date;
    d_string_tpcds<TPCDS_READ_MAX + 1> i_rec_end_date;
    d_string_tpcds<TPCDS_READ_MAX + 1>i_item_desc;
    d_money_tpcds i_current_price ; //decimal(7,2)
    d_money_tpcds i_wholesale_cost; //decimal(7,2)
    d_long_tpcds i_brand_id;
    d_string_tpcds<TPCDS_READ_MAX + 1> i_brand;
    d_long_tpcds i_class_id;
    d_string_tpcds<TPCDS_READ_MAX + 1> i_class;
    d_long_tpcds i_category_id;
    d_string_tpcds<TPCDS_READ_MAX + 1> i_category;
    d_long_tpcds i_manufact_id;
    d_string_tpcds<TPCDS_READ_MAX + 1> i_manufact;
    d_string_tpcds<TPCDS_READ_MAX + 1> i_size;
    d_string_tpcds<TPCDS_READ_MAX + 1> i_formulation;
    d_string_tpcds<TPCDS_READ_MAX + 1> i_color;
    d_string_tpcds<TPCDS_READ_MAX + 1> i_units;
    d_string_tpcds<TPCDS_READ_MAX + 1> i_container;
    d_long_tpcds i_manager_id;
    d_string_tpcds<TPCDS_READ_MAX + 1> i_product_name;

    friend std::ostream& operator<<(std::ostream& output, item_t& source) {
        output << source.i_item_sk << source.i_item_id << source.i_rec_start_date << source.i_rec_end_date 
                << source.i_item_desc << source.i_current_price << source.i_wholesale_cost << source.i_brand_id 
                << source.i_brand << source.i_class_id << source.i_class << source.i_category_id << source.i_category 
                << source.i_manufact_id << source.i_manufact << source.i_size << source.i_formulation << source.i_color 
                << source.i_units << source.i_container << source.i_manager_id << source.i_product_name << std::endl;
        return output;
    }

    friend std::istream& operator>>(std::istream& input, item_t& target) {
        input >> target.i_item_sk >> target.i_item_id >> target.i_rec_start_date >> target.i_rec_end_date >> 
                target.i_item_desc >> target.i_current_price >> target.i_wholesale_cost >> target.i_brand_id >> 
                target.i_brand >> target.i_class_id >> target.i_class >> target.i_category_id >> target.i_category >> 
                target.i_manufact_id >> target.i_manufact >> target.i_size >> target.i_formulation >> target.i_color >> 
                target.i_units >> target.i_container >> target.i_manager_id >> target.i_product_name;
        input.get();
        return input;
    }
};

class item_t_col {
   public:
    long volumn;
    long count;
    std::vector<d_long_tpcds > i_item_sk;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1>> i_item_id;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > i_rec_start_date;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > i_rec_end_date;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1>> i_item_desc;
    std::vector<d_long_tpcds > i_current_price ; //decimal(7, 2)
    std::vector<d_long_tpcds > i_wholesale_cost; //decimal(7, 2)
    std::vector<d_long_tpcds > i_brand_id;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > i_brand;
    std::vector<d_long_tpcds > i_class_id;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > i_class;
    std::vector<d_long_tpcds > i_category_id;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > i_category;
    std::vector<d_long_tpcds > i_manufact_id;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > i_manufact;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > i_size;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > i_formulation;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > i_color;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > i_units;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > i_container;
    std::vector<d_long_tpcds > i_manager_id;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > i_product_name;


    item_t_col() : volumn(0), count(0) {}
    void change_volumn(long ss) {
        volumn = ss;
        count = 0;
        i_item_sk.resize(ss);
        i_item_id.resize(ss);
        i_rec_start_date.resize(ss);
        i_rec_end_date.resize(ss);
        i_item_desc.resize(ss);
        i_current_price .resize(ss);
        i_wholesale_cost.resize(ss);
        i_brand_id.resize(ss);
        i_brand.resize(ss);
        i_class_id.resize(ss);
        i_class.resize(ss);
        i_category_id.resize(ss);
        i_category.resize(ss);
        i_manufact_id.resize(ss);
        i_manufact.resize(ss);
        i_size.resize(ss);
        i_formulation.resize(ss);
        i_color.resize(ss);
        i_units.resize(ss);
        i_container.resize(ss);
        i_manager_id.resize(ss);
        i_product_name.resize(ss);
    }

    friend std::ostream& operator<<(std::ostream& output, item_t_col& source) {
        for (int i = 0; i < source.count; i++) {
            output << source.i_item_sk[i] << source.i_item_id[i] << source.i_rec_start_date[i] << source.i_rec_end_date[i] 
                    << source.i_item_desc[i] << source.i_current_price[i] << source.i_wholesale_cost[i] << source.i_brand_id[i] 
                    << source.i_brand[i] << source.i_class_id[i] << source.i_class[i] << source.i_category_id[i] << source.i_category[i] 
                    << source.i_manufact_id[i] << source.i_manufact[i] << source.i_size[i] << source.i_formulation[i] << source.i_color[i] 
                    << source.i_units[i] << source.i_container[i] << source.i_manager_id[i] << source.i_product_name[i] << std::endl;
        }
        return output;
    }

    friend std::istream& operator>>(std::istream& input, item_t_col& target) {
        for (int i = 0; i < target.volumn; i++) {
            if (input.peek() == EOF) {
                target.count = i;
                return input;
            }

            input >> target.i_item_sk[i] >> target.i_item_id[i] >> target.i_rec_start_date[i] >> target.i_rec_end_date[i] >> 
                    target.i_item_desc[i] >> target.i_current_price[i] >> target.i_wholesale_cost[i] >> target.i_brand_id[i] >> 
                    target.i_brand[i] >> target.i_class_id[i] >> target.i_class[i] >> target.i_category_id[i] >> target.i_category[i] >> 
                    target.i_manufact_id[i] >> target.i_manufact[i] >> target.i_size[i] >> target.i_formulation[i] >> target.i_color[i] >> 
                    target.i_units[i] >> target.i_container[i] >> target.i_manager_id[i] >> target.i_product_name[i];

            input.get();
        }
        target.count = target.volumn;
        return input;
    }
};

class store_sales_t {
   public:
    d_long_tpcds ss_sold_date_sk;       //Int, //bigint,
    d_long_tpcds ss_sold_time_sk;       //Int, //bigint,
    d_long_tpcds ss_item_sk;            //Int, //bigint,
    d_long_tpcds ss_customer_sk;        //Int, //bigint,
    d_long_tpcds ss_cdemo_sk;           //Int, //bigint,
    d_long_tpcds ss_hdemo_sk;           //Int, //bigint,
    d_long_tpcds ss_addr_sk;            //Int, //bigint,
    d_long_tpcds ss_store_sk;           //Int, //bigint,
    d_long_tpcds ss_promo_sk;           //Int, //bigint,
    d_long_tpcds ss_ticket_number;      //Int, //bigint,
    d_long_tpcds ss_quantity;           //Int,
    d_money_tpcds ss_wholesale_cost;     //Int, //decimal(7,2),
    d_money_tpcds ss_list_price;         //Int, //decimal(7,2),
    d_money_tpcds ss_sales_price;        //Int, //decimal(7,2),
    d_money_tpcds ss_ext_discount_amt;   //Int, //decimal(7,2),
    d_money_tpcds ss_ext_sales_price;    //Int, //decimal(7,2),
    d_money_tpcds ss_ext_wholesale_cost; //Int, //decimal(7,2),
    d_money_tpcds ss_ext_list_price;     //Int, //decimal(7,2),
    d_money_tpcds ss_ext_tax;            //Int, //decimal(7,2),
    d_money_tpcds ss_coupon_amt;         //Int, //decimal(7,2),
    d_money_tpcds ss_net_paid;           //Int, //decimal(7,2),
    d_money_tpcds ss_net_paid_inc_tax;   //Int, //decimal(7,2),
    d_money_tpcds ss_net_profit;         //Int  //decimal(7,2)

    friend std::ostream& operator<<(std::ostream& output, store_sales_t& source) {
        output << source.ss_sold_date_sk << source.ss_sold_time_sk << source.ss_item_sk << source.ss_customer_sk 
                << source.ss_cdemo_sk << source.ss_hdemo_sk << source.ss_addr_sk << source.ss_store_sk << source.ss_promo_sk 
                << source.ss_ticket_number << source.ss_quantity << source.ss_wholesale_cost << source.ss_list_price 
                << source.ss_sales_price << source.ss_ext_discount_amt << source.ss_ext_sales_price << source.ss_ext_wholesale_cost 
                << source.ss_ext_list_price << source.ss_ext_tax << source.ss_coupon_amt << source.ss_net_paid 
                << source.ss_net_paid_inc_tax << source.ss_net_profit << std::endl;
        return output;
    }

    friend std::istream& operator>>(std::istream& input, store_sales_t& target) {
        input >> target.ss_sold_date_sk >> target.ss_sold_time_sk >> target.ss_item_sk >> target.ss_customer_sk >> target.ss_cdemo_sk >> target.ss_hdemo_sk >> target.ss_addr_sk >> 
                target.ss_store_sk >> target.ss_promo_sk >> target.ss_ticket_number >> target.ss_quantity >> target.ss_wholesale_cost >> target.ss_list_price >> target.ss_sales_price >> 
                target.ss_ext_discount_amt >> target.ss_ext_sales_price >> target.ss_ext_wholesale_cost >> target.ss_ext_list_price >> target.ss_ext_tax >> target.ss_coupon_amt >> 
                target.ss_net_paid >> target.ss_net_paid_inc_tax >> target.ss_net_profit;
        input.get();
        return input;
    }
};

class store_sales_t_col {
   public:
    long volumn;
    long count;
    std::vector<d_long_tpcds > ss_sold_date_sk;       //Int, //bigint,
    std::vector<d_long_tpcds > ss_sold_time_sk;       //Int, //bigint,
    std::vector<d_long_tpcds > ss_item_sk;            //Int, //bigint,
    std::vector<d_long_tpcds > ss_customer_sk;        //Int, //bigint,
    std::vector<d_long_tpcds > ss_cdemo_sk;           //Int, //bigint,
    std::vector<d_long_tpcds > ss_hdemo_sk;           //Int, //bigint,
    std::vector<d_long_tpcds > ss_addr_sk;            //Int, //bigint,
    std::vector<d_long_tpcds > ss_store_sk;           //Int, //bigint,
    std::vector<d_long_tpcds > ss_promo_sk;           //Int, //bigint,
    std::vector<d_long_tpcds > ss_ticket_number;      //Int, //bigint,
    std::vector<d_long_tpcds > ss_quantity;           //Int,
    std::vector<d_money_tpcds > ss_wholesale_cost;     //Int, //decimal(7,2),
    std::vector<d_money_tpcds > ss_list_price;         //Int, //decimal(7,2),
    std::vector<d_money_tpcds > ss_sales_price;        //Int, //decimal(7,2),
    std::vector<d_money_tpcds > ss_ext_discount_amt;   //Int, //decimal(7,2),
    std::vector<d_money_tpcds > ss_ext_sales_price;    //Int, //decimal(7,2),
    std::vector<d_money_tpcds > ss_ext_wholesale_cost; //Int, //decimal(7,2),
    std::vector<d_money_tpcds > ss_ext_list_price;     //Int, //decimal(7,2),
    std::vector<d_money_tpcds > ss_ext_tax;            //Int, //decimal(7,2),
    std::vector<d_money_tpcds > ss_coupon_amt;         //Int, //decimal(7,2),
    std::vector<d_money_tpcds > ss_net_paid;           //Int, //decimal(7,2),
    std::vector<d_money_tpcds > ss_net_paid_inc_tax;   //Int, //decimal(7,2),
    std::vector<d_money_tpcds > ss_net_profit;         //Int  //decimal(7,2)

    store_sales_t_col() : volumn(0), count(0) {}
    void change_volumn(long ss) {
        volumn = ss;
        count = 0;
        ss_sold_date_sk.resize(ss);
        ss_sold_time_sk.resize(ss);
        ss_item_sk.resize(ss);
        ss_customer_sk.resize(ss);
        ss_cdemo_sk.resize(ss);
        ss_hdemo_sk.resize(ss);
        ss_addr_sk.resize(ss);
        ss_store_sk.resize(ss);
        ss_promo_sk.resize(ss);
        ss_ticket_number.resize(ss);
        ss_quantity.resize(ss);
        ss_wholesale_cost.resize(ss);
        ss_list_price.resize(ss);
        ss_sales_price.resize(ss);
        ss_ext_discount_amt.resize(ss);
        ss_ext_sales_price.resize(ss);
        ss_ext_wholesale_cost.resize(ss);
        ss_ext_list_price.resize(ss);
        ss_ext_tax.resize(ss);
        ss_coupon_amt.resize(ss);
        ss_net_paid.resize(ss);
        ss_net_paid_inc_tax.resize(ss);
        ss_net_profit.resize(ss);
    }

    friend std::ostream& operator<<(std::ostream& output, store_sales_t_col& source) {
        for (int i = 0; i < source.count; i++) {
            output << source.ss_sold_date_sk[i] << source.ss_sold_time_sk[i] << source.ss_item_sk[i] << source.ss_customer_sk[i] 
                << source.ss_cdemo_sk[i] << source.ss_hdemo_sk[i] << source.ss_addr_sk[i] << source.ss_store_sk[i] << source.ss_promo_sk[i] 
                << source.ss_ticket_number[i] << source.ss_quantity[i] << source.ss_wholesale_cost[i] << source.ss_list_price[i] 
                << source.ss_sales_price[i] << source.ss_ext_discount_amt[i] << source.ss_ext_sales_price[i] << source.ss_ext_wholesale_cost[i] 
                << source.ss_ext_list_price[i] << source.ss_ext_tax[i] << source.ss_coupon_amt[i] << source.ss_net_paid[i] 
                << source.ss_net_paid_inc_tax[i] << source.ss_net_profit[i] << std::endl;
        }
        return output;
    }

    friend std::istream& operator>>(std::istream& input, store_sales_t_col& target) {
        for (int i = 0; i < target.volumn; i++) {
            if (input.peek() == EOF) {
                target.count = i;
                return input;
            }
            input >> target.ss_sold_date_sk[i] >> target.ss_sold_time_sk[i] >> target.ss_item_sk[i] >> target.ss_customer_sk[i] >> target.ss_cdemo_sk[i] >> target.ss_hdemo_sk[i] >> target.ss_addr_sk[i] >> 
                target.ss_store_sk[i] >> target.ss_promo_sk[i] >> target.ss_ticket_number[i] >> target.ss_quantity[i] >> target.ss_wholesale_cost[i] >> target.ss_list_price[i] >> target.ss_sales_price[i] >> 
                target.ss_ext_discount_amt[i] >> target.ss_ext_sales_price[i] >> target.ss_ext_wholesale_cost[i] >> target.ss_ext_list_price[i] >> target.ss_ext_tax[i] >> target.ss_coupon_amt[i] >> 
                target.ss_net_paid[i] >> target.ss_net_paid_inc_tax[i] >> target.ss_net_profit[i];
            input.get();
        }
        target.count = target.volumn;
        return input;
    }
};

class date_dim_t {
   public:
    d_long_tpcds d_date_sk;
    d_string_tpcds<TPCDS_READ_MAX + 1> d_date_id;
    d_date_tpcds d_date;
    d_long_tpcds d_month_seq;
    d_long_tpcds d_week_seq;
    d_long_tpcds d_quarter_seq;
    d_long_tpcds d_year;
    d_long_tpcds d_dow;
    d_long_tpcds d_moy;
    d_long_tpcds d_dom;
    d_long_tpcds d_qoy;
    d_long_tpcds d_fy_year;
    d_long_tpcds d_fy_quarter_seq;
    d_long_tpcds d_fy_week_seq;
    d_string_tpcds<TPCDS_READ_MAX + 1> d_day_name;
    d_string_tpcds<TPCDS_READ_MAX + 1> d_quarter_name;
    d_string_tpcds<TPCDS_READ_MAX + 1> d_holiday;
    d_string_tpcds<TPCDS_READ_MAX + 1> d_weekend;
    d_string_tpcds<TPCDS_READ_MAX + 1> d_following_holiday;
    d_long_tpcds d_first_dom;
    d_long_tpcds d_last_dom;
    d_long_tpcds d_same_day_ly;
    d_long_tpcds d_same_day_lq;
    d_string_tpcds<TPCDS_READ_MAX + 1> d_current_day;
    d_string_tpcds<TPCDS_READ_MAX + 1> d_current_week;
    d_string_tpcds<TPCDS_READ_MAX + 1> d_current_month;
    d_string_tpcds<TPCDS_READ_MAX + 1> d_current_quarter;
    d_string_tpcds<TPCDS_READ_MAX + 1> d_current_year;

    friend std::ostream& operator<<(std::ostream& output, date_dim_t& source) {
        output << source.d_date_sk << source.d_date_id << source.d_date << source.d_month_seq << source.d_week_seq 
                << source.d_quarter_seq << source.d_year << source.d_dow << source.d_moy << source.d_dom << source.d_qoy 
                << source.d_fy_year << source.d_fy_quarter_seq << source.d_fy_week_seq << source.d_day_name 
                << source.d_quarter_name << source.d_holiday << source.d_weekend << source.d_following_holiday 
                << source.d_first_dom << source.d_last_dom << source.d_same_day_ly << source.d_same_day_lq << source.d_current_day 
                << source.d_current_week << source.d_current_month << source.d_current_quarter << source.d_current_year << std::endl;
        return output;
    }

    friend std::istream& operator>>(std::istream& input, date_dim_t& target) {
        input >> target.d_date_sk >> target.d_date_id >> target.d_date >> target.d_month_seq >> target.d_week_seq >> 
                target.d_quarter_seq >> target.d_year >> target.d_dow >> target.d_moy >> target.d_dom >> target.d_qoy >> 
                target.d_fy_year >> target.d_fy_quarter_seq >> target.d_fy_week_seq >> target.d_day_name >> target.d_quarter_name >> 
                target.d_holiday >> target.d_weekend >> target.d_following_holiday >> target.d_first_dom >> target.d_last_dom >> 
                target.d_same_day_ly >> target.d_same_day_lq >> target.d_current_day >> target.d_current_week >> target.d_current_month >> 
                target.d_current_quarter >> target.d_current_year;
        input.get();
        return input;
    }
};

class date_dim_t_col {
   public:
    long volumn;
    long count;
    std::vector<d_long_tpcds > d_date_sk;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > d_date_id;
    std::vector<d_date_tpcds > d_date;
    std::vector<d_long_tpcds > d_month_seq;
    std::vector<d_long_tpcds > d_week_seq;
    std::vector<d_long_tpcds > d_quarter_seq;
    std::vector<d_long_tpcds > d_year;
    std::vector<d_long_tpcds > d_dow;
    std::vector<d_long_tpcds > d_moy;
    std::vector<d_long_tpcds > d_dom;
    std::vector<d_long_tpcds > d_qoy;
    std::vector<d_long_tpcds > d_fy_year;
    std::vector<d_long_tpcds > d_fy_quarter_seq;
    std::vector<d_long_tpcds > d_fy_week_seq;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > d_day_name;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > d_quarter_name;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > d_holiday;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > d_weekend;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > d_following_holiday;
    std::vector<d_long_tpcds > d_first_dom;
    std::vector<d_long_tpcds > d_last_dom;
    std::vector<d_long_tpcds > d_same_day_ly;
    std::vector<d_long_tpcds > d_same_day_lq;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > d_current_day;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > d_current_week;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > d_current_month;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > d_current_quarter;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > d_current_year;

    date_dim_t_col() : volumn(0), count(0) {}
    void change_volumn(long ss) {
        volumn = ss;
        count = 0;
        d_date_sk.resize(ss);
        d_date_id.resize(ss);
        d_date.resize(ss);
        d_month_seq.resize(ss);
        d_week_seq.resize(ss);
        d_quarter_seq.resize(ss);
        d_year.resize(ss);
        d_dow.resize(ss);
        d_moy.resize(ss);
        d_dom.resize(ss);
        d_qoy.resize(ss);
        d_fy_year.resize(ss);
        d_fy_quarter_seq.resize(ss);
        d_fy_week_seq.resize(ss);
        d_day_name.resize(ss);
        d_quarter_name.resize(ss);
        d_holiday.resize(ss);
        d_weekend.resize(ss);
        d_following_holiday.resize(ss);
        d_first_dom.resize(ss);
        d_last_dom.resize(ss);
        d_same_day_ly.resize(ss);
        d_same_day_lq.resize(ss);
        d_current_day.resize(ss);
        d_current_week.resize(ss);
        d_current_month.resize(ss);
        d_current_quarter.resize(ss);
        d_current_year.resize(ss);
    }

    friend std::ostream& operator<<(std::ostream& output, date_dim_t_col& source) {
        for (int i = 0; i < source.count; i++) {
            output << source.d_date_sk[i] << source.d_date_id[i] << source.d_date[i] << source.d_month_seq[i] << source.d_week_seq[i] 
                << source.d_quarter_seq[i] << source.d_year[i] << source.d_dow[i] << source.d_moy[i] << source.d_dom[i] << source.d_qoy[i] 
                << source.d_fy_year[i] << source.d_fy_quarter_seq[i] << source.d_fy_week_seq[i] << source.d_day_name[i] 
                << source.d_quarter_name[i] << source.d_holiday[i] << source.d_weekend[i] << source.d_following_holiday[i] 
                << source.d_first_dom[i] << source.d_last_dom[i] << source.d_same_day_ly[i] << source.d_same_day_lq[i] << source.d_current_day[i] 
                << source.d_current_week[i] << source.d_current_month[i] << source.d_current_quarter[i] << source.d_current_year[i] << std::endl;
        }
        return output;
    }

    friend std::istream& operator>>(std::istream& input, date_dim_t_col& target) {
        for (int i = 0; i < target.volumn; i++) {
            if (input.peek() == EOF) {
                target.count = i;
                return input;
            }
            input >> target.d_date_sk[i] >> target.d_date_id[i] >> target.d_date[i] >> target.d_month_seq[i] >> target.d_week_seq[i] >> 
                target.d_quarter_seq[i] >> target.d_year[i] >> target.d_dow[i] >> target.d_moy[i] >> target.d_dom[i] >> target.d_qoy[i] >> 
                target.d_fy_year[i] >> target.d_fy_quarter_seq[i] >> target.d_fy_week_seq[i] >> target.d_day_name[i] >> target.d_quarter_name[i] >> 
                target.d_holiday[i] >> target.d_weekend[i] >> target.d_following_holiday[i] >> target.d_first_dom[i] >> target.d_last_dom[i] >> 
                target.d_same_day_ly[i] >> target.d_same_day_lq[i] >> target.d_current_day[i] >> target.d_current_week[i] >> target.d_current_month[i] >> 
                target.d_current_quarter[i] >> target.d_current_year[i];
            input.get();
        }
        target.count = target.volumn;
        return input;
    }
};

class customer_demographics_t {
   public:
        d_long_tpcds cd_demo_sk;
        d_string_tpcds<TPCDS_READ_MAX + 1> cd_gender;
        d_string_tpcds<TPCDS_READ_MAX + 1> cd_marital_status;
        d_string_tpcds<TPCDS_READ_MAX + 1> cd_education_status;
        d_long_tpcds cd_purchase_estimate;
        d_string_tpcds<TPCDS_READ_MAX + 1> cd_credit_rating;
        d_long_tpcds cd_dep_count;
        d_long_tpcds cd_dep_employed_count;
        d_long_tpcds cd_dep_college_count;

    friend std::ostream& operator<<(std::ostream& output, customer_demographics_t& source) {
        output << source.cd_demo_sk << source.cd_gender << source.cd_marital_status 
                << source.cd_education_status << source.cd_purchase_estimate 
                << source.cd_credit_rating << source.cd_dep_count << source.cd_dep_employed_count 
                << source.cd_dep_college_count << std::endl;
        return output;
    }

    friend std::istream& operator>>(std::istream& input, customer_demographics_t& target) {
        input >> target.cd_demo_sk >> target.cd_gender >> target.cd_marital_status >> 
                target.cd_education_status >> target.cd_purchase_estimate >> 
                target.cd_credit_rating >> target.cd_dep_count >> target.cd_dep_employed_count >> target.cd_dep_college_count;
        input.get();
        return input;
    }
};

class customer_demographics_t_col {
   public:
    long volumn;
    long count;
    std::vector<d_long_tpcds > cd_demo_sk;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > cd_gender;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > cd_marital_status;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > cd_education_status;
    std::vector<d_long_tpcds > cd_purchase_estimate;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > cd_credit_rating;
    std::vector<d_long_tpcds > cd_dep_count;
    std::vector<d_long_tpcds > cd_dep_employed_count;
    std::vector<d_long_tpcds > cd_dep_college_count;

    customer_demographics_t_col() : volumn(0), count(0) {}
    void change_volumn(long ss) {
        volumn = ss;
        count = 0;
        cd_demo_sk.resize(ss);
        cd_gender.resize(ss);
        cd_marital_status.resize(ss);
        cd_education_status.resize(ss);
        cd_purchase_estimate.resize(ss);
        cd_credit_rating.resize(ss);
        cd_dep_count.resize(ss);
        cd_dep_employed_count.resize(ss);
        cd_dep_college_count.resize(ss);
    }

    friend std::ostream& operator<<(std::ostream& output, customer_demographics_t_col& source) {
        for (int i = 0; i < source.count; i++) {
            output << source.cd_demo_sk[i] << source.cd_gender[i] << source.cd_marital_status[i] 
                << source.cd_education_status[i] << source.cd_purchase_estimate[i] 
                << source.cd_credit_rating[i] << source.cd_dep_count[i] << source.cd_dep_employed_count[i] 
                << source.cd_dep_college_count[i] << std::endl;
        }
        return output;
    }

    friend std::istream& operator>>(std::istream& input, customer_demographics_t_col& target) {
        for (int i = 0; i < target.volumn; i++) {
            if (input.peek() == EOF) {
                target.count = i;
                return input;
            }

            input >> target.cd_demo_sk[i] >> target.cd_gender[i] >> target.cd_marital_status[i] >> target.cd_education_status[i] >> 
                    target.cd_purchase_estimate[i] >> target.cd_credit_rating[i] >> target.cd_dep_count[i] >> target.cd_dep_employed_count[i] >> 
                    target.cd_dep_college_count[i];
            input.get();
        }
        target.count = target.volumn;
        return input;
    }
};

class promotion_t {
   public:
        d_long_tpcds p_promo_sk;
        d_string_tpcds<TPCDS_READ_MAX + 1> p_promo_id;
        d_long_tpcds p_start_date_sk;
        d_long_tpcds p_end_date_sk;
        d_long_tpcds p_item_sk;
        d_money_tpcds p_cost;
        d_long_tpcds p_response_target;
        d_string_tpcds<TPCDS_READ_MAX + 1> p_promo_name;
        d_string_tpcds<TPCDS_READ_MAX + 1> p_channel_dmail;
        d_string_tpcds<TPCDS_READ_MAX + 1> p_channel_email;
        d_string_tpcds<TPCDS_READ_MAX + 1> p_channel_catalog;
        d_string_tpcds<TPCDS_READ_MAX + 1> p_channel_tv;
        d_string_tpcds<TPCDS_READ_MAX + 1> p_channel_radio;
        d_string_tpcds<TPCDS_READ_MAX + 1> p_channel_press;
        d_string_tpcds<TPCDS_READ_MAX + 1> p_channel_event;
        d_string_tpcds<TPCDS_READ_MAX + 1> p_channel_demo;
        d_string_tpcds<TPCDS_READ_MAX + 1> p_channel_details;
        d_string_tpcds<TPCDS_READ_MAX + 1> p_purpose;
        d_string_tpcds<TPCDS_READ_MAX + 1> p_discount_active;

    friend std::ostream& operator<<(std::ostream& output, promotion_t& source) {
        output << source.p_promo_sk << source.p_promo_id << source.p_start_date_sk 
                << source.p_end_date_sk << source.p_item_sk << source.p_cost 
                << source.p_response_target << source.p_promo_name << source.p_channel_dmail 
                << source.p_channel_email << source.p_channel_catalog << source.p_channel_tv 
                << source.p_channel_radio << source.p_channel_press << source.p_channel_event 
                << source.p_channel_demo << source.p_channel_details << source.p_purpose 
                << source.p_discount_active << std::endl;
        return output;
    }

    friend std::istream& operator>>(std::istream& input, promotion_t& target) {
        input >> target.p_promo_sk >> target.p_promo_id >> target.p_start_date_sk >> 
                target.p_end_date_sk >> target.p_item_sk >> target.p_cost >> target.p_response_target >> 
                target.p_promo_name >> target.p_channel_dmail >> target.p_channel_email >> 
                target.p_channel_catalog >> target.p_channel_tv >> target.p_channel_radio >> 
                target.p_channel_press >> target.p_channel_event >> target.p_channel_demo >> 
                target.p_channel_details >> target.p_purpose >> target.p_discount_active;
        input.get();
        return input;
    }
};

class promotion_t_col {
   public:
    long volumn;
    long count;
    std::vector<d_long_tpcds > p_promo_sk;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > p_promo_id;
    std::vector<d_long_tpcds > p_start_date_sk;
    std::vector<d_long_tpcds > p_end_date_sk;
    std::vector<d_long_tpcds > p_item_sk;
    std::vector<d_money_tpcds > p_cost;
    std::vector<d_long_tpcds > p_response_target;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > p_promo_name;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > p_channel_dmail;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > p_channel_email;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > p_channel_catalog;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > p_channel_tv;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > p_channel_radio;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > p_channel_press;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > p_channel_event;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > p_channel_demo;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > p_channel_details;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > p_purpose;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > p_discount_active;

    promotion_t_col() : volumn(0), count(0) {}
    void change_volumn(long ss) {
        volumn = ss;
        count = 0;
        p_promo_sk.resize(ss);
        p_promo_id.resize(ss);
        p_start_date_sk.resize(ss);
        p_end_date_sk.resize(ss);
        p_item_sk.resize(ss);
        p_cost.resize(ss);
        p_response_target.resize(ss);
        p_promo_name.resize(ss);
        p_channel_dmail.resize(ss);
        p_channel_email.resize(ss);
        p_channel_catalog.resize(ss);
        p_channel_tv.resize(ss);
        p_channel_radio.resize(ss);
        p_channel_press.resize(ss);
        p_channel_event.resize(ss);
        p_channel_demo.resize(ss);
        p_channel_details.resize(ss);
        p_purpose.resize(ss);
        p_discount_active.resize(ss);
    }

    friend std::ostream& operator<<(std::ostream& output, promotion_t_col& source) {
        for (int i = 0; i < source.count; i++) {
            output << source.p_promo_sk[i] << source.p_promo_id[i] << source.p_start_date_sk[i] 
                << source.p_end_date_sk[i] << source.p_item_sk[i] << source.p_cost[i] 
                << source.p_response_target[i] << source.p_promo_name[i] << source.p_channel_dmail[i] 
                << source.p_channel_email[i] << source.p_channel_catalog[i] << source.p_channel_tv[i] 
                << source.p_channel_radio[i] << source.p_channel_press[i] << source.p_channel_event[i] 
                << source.p_channel_demo[i] << source.p_channel_details[i] << source.p_purpose[i] 
                << source.p_discount_active[i] << std::endl;
        }
        return output;
    }

    friend std::istream& operator>>(std::istream& input, promotion_t_col& target) {
        for (int i = 0; i < target.volumn; i++) {
            if (input.peek() == EOF) {
                target.count = i;
                return input;
            }
            input >> target.p_promo_sk[i] >> target.p_promo_id[i] >> target.p_start_date_sk[i] >> 
                    target.p_end_date_sk[i] >> target.p_item_sk[i] >> target.p_cost[i] >> target.p_response_target[i] >> 
                    target.p_promo_name[i] >> target.p_channel_dmail[i] >> target.p_channel_email[i] >> 
                    target.p_channel_catalog[i] >> target.p_channel_tv[i] >> target.p_channel_radio[i] >> 
                    target.p_channel_press[i] >> target.p_channel_event[i] >> target.p_channel_demo[i] >> 
                    target.p_channel_details[i] >> target.p_purpose[i] >> target.p_discount_active[i];
            input.get();
        }
        target.count = target.volumn;
        return input;
    }
};

class household_demographics_t {
   public:
        d_long_tpcds hd_demo_sk;
        d_long_tpcds hd_income_band_sk;
        d_string_tpcds<TPCDS_READ_MAX + 1> hd_buy_potential;
        d_long_tpcds hd_dep_count;
        d_long_tpcds hd_vehicle_count;

    friend std::ostream& operator<<(std::ostream& output, household_demographics_t& source) {
        output << source.hd_demo_sk << source.hd_income_band_sk << source.hd_buy_potential << source.hd_dep_count << source.hd_vehicle_count << std::endl;
        return output;
    }

    friend std::istream& operator>>(std::istream& input, household_demographics_t& target) {
        input >> target.hd_demo_sk >> target.hd_income_band_sk >> target.hd_buy_potential >> target.hd_dep_count >> target.hd_vehicle_count;
        input.get();
        return input;
    }
};

class household_demographics_t_col {
   public:
    long volumn;
    long count;
    std::vector<d_long_tpcds > hd_demo_sk;
    std::vector<d_long_tpcds > hd_income_band_sk;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > hd_buy_potential;
    std::vector<d_long_tpcds > hd_dep_count;
    std::vector<d_long_tpcds > hd_vehicle_count;

    household_demographics_t_col() : volumn(0), count(0) {}
    void change_volumn(long ss) {
        volumn = ss;
        count = 0;
        hd_demo_sk.resize(ss);
        hd_income_band_sk.resize(ss);
        hd_buy_potential.resize(ss);
        hd_dep_count.resize(ss);
        hd_vehicle_count.resize(ss);
    }

    friend std::ostream& operator<<(std::ostream& output, household_demographics_t_col& source) {
        for (int i = 0; i < source.count; i++) {
            output << source.hd_demo_sk[i] << source.hd_income_band_sk[i] << source.hd_buy_potential[i] << source.hd_dep_count[i] << source.hd_vehicle_count[i] << std::endl;
        }
        return output;
    }

    friend std::istream& operator>>(std::istream& input, household_demographics_t_col& target) {
        for (int i = 0; i < target.volumn; i++) {
            if (input.peek() == EOF) {
                target.count = i;
                return input;
            }
            input >> target.hd_demo_sk[i] >> target.hd_income_band_sk[i] >> target.hd_buy_potential[i] >> target.hd_dep_count[i] >> target.hd_vehicle_count[i];
            input.get();
        }
        target.count = target.volumn;
        return input;
    }
};

class time_dim_t {
   public:
        d_long_tpcds t_time_sk;
        d_string_tpcds<TPCDS_READ_MAX + 1> t_time_id;
        d_long_tpcds t_time;
        d_long_tpcds t_hour;
        d_long_tpcds t_minute;
        d_long_tpcds t_second;
        d_string_tpcds<TPCDS_READ_MAX + 1> t_am_pm;
        d_string_tpcds<TPCDS_READ_MAX + 1> t_shift;
        d_string_tpcds<TPCDS_READ_MAX + 1> t_sub_shift;
        d_string_tpcds<TPCDS_READ_MAX + 1> t_meal_time;

    friend std::ostream& operator<<(std::ostream& output, time_dim_t& source) {
        output << source.t_time_sk << source.t_time_id << source.t_time << source.t_hour 
                << source.t_minute << source.t_second << source.t_am_pm << source.t_shift 
                << source.t_sub_shift << source.t_meal_time << std::endl;
        return output;
    }

    friend std::istream& operator>>(std::istream& input, time_dim_t& target) {
        input >> target.t_time_sk >> target.t_time_id >> target.t_time >> 
                target.t_hour >> target.t_minute >> target.t_second >> 
                target.t_am_pm >> target.t_shift >> target.t_sub_shift >> 
                target.t_meal_time;
        input.get();
        return input;
    }
};

class time_dim_t_col {
   public:
    long volumn;
    long count;
    std::vector<d_long_tpcds > t_time_sk;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > t_time_id;
    std::vector<d_long_tpcds > t_time;
    std::vector<d_long_tpcds > t_hour;
    std::vector<d_long_tpcds > t_minute;
    std::vector<d_long_tpcds > t_second;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > t_am_pm;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > t_shift;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > t_sub_shift;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > t_meal_time;

    time_dim_t_col() : volumn(0), count(0) {}
    void change_volumn(long ss) {
        volumn = ss;
        count = 0;
        t_time_sk.resize(ss);
        t_time_id.resize(ss);
        t_time.resize(ss);
        t_hour.resize(ss);
        t_minute.resize(ss);
        t_second.resize(ss);
        t_am_pm.resize(ss);
        t_shift.resize(ss);
        t_sub_shift.resize(ss);
        t_meal_time.resize(ss);
    }

    friend std::ostream& operator<<(std::ostream& output, time_dim_t_col& source) {
        for (int i = 0; i < source.count; i++) {
            output << source.t_time_sk[i] << source.t_time_id[i] << source.t_time[i] << source.t_hour[i] 
                << source.t_minute[i] << source.t_second[i] << source.t_am_pm[i] << source.t_shift[i] 
                << source.t_sub_shift[i] << source.t_meal_time[i] << std::endl;
        }
        return output;
    }

    friend std::istream& operator>>(std::istream& input, time_dim_t_col& target) {
        for (int i = 0; i < target.volumn; i++) {
            if (input.peek() == EOF) {
                target.count = i;
                return input;
            }
            input >> target.t_time_sk[i] >> target.t_time_id[i] >> target.t_time[i] >> 
                    target.t_hour[i] >> target.t_minute[i] >> target.t_second[i] >> 
                    target.t_am_pm[i] >> target.t_shift[i] >> target.t_sub_shift[i] >> 
                    target.t_meal_time[i];
            input.get();
        }
        target.count = target.volumn;
        return input;
    }
};

class store_t {
   public:
        d_long_tpcds s_store_sk;
        d_string_tpcds<TPCDS_READ_MAX + 1> s_store_id;
        d_string_tpcds<TPCDS_READ_MAX + 1> s_rec_start_date;
        d_string_tpcds<TPCDS_READ_MAX + 1> s_rec_end_date;
        d_long_tpcds s_closed_date_sk;
        d_string_tpcds<TPCDS_READ_MAX + 1> s_store_name;
        d_long_tpcds s_number_employees;
        d_long_tpcds s_floor_space;
        d_string_tpcds<TPCDS_READ_MAX + 1> s_hours;
        d_string_tpcds<TPCDS_READ_MAX + 1> s_manager;
        d_long_tpcds s_market_id;
        d_string_tpcds<TPCDS_READ_MAX + 1> s_geography_class;
        d_string_tpcds<TPCDS_READ_MAX + 1> s_market_desc;
        d_string_tpcds<TPCDS_READ_MAX + 1> s_market_manager;
        d_long_tpcds s_division_id;
        d_string_tpcds<TPCDS_READ_MAX + 1> s_division_name;
        d_long_tpcds s_company_id;
        d_string_tpcds<TPCDS_READ_MAX + 1> s_company_name;
        d_string_tpcds<TPCDS_READ_MAX + 1> s_street_number;
        d_string_tpcds<TPCDS_READ_MAX + 1> s_street_name;
        d_string_tpcds<TPCDS_READ_MAX + 1> s_street_type;
        d_string_tpcds<TPCDS_READ_MAX + 1> s_suite_number;
        d_string_tpcds<TPCDS_READ_MAX + 1> s_city;
        d_string_tpcds<TPCDS_READ_MAX + 1> s_county;
        d_string_tpcds<TPCDS_READ_MAX + 1> s_state;
        d_string_tpcds<TPCDS_READ_MAX + 1> s_zip;
        d_string_tpcds<TPCDS_READ_MAX + 1> s_country;
        d_money_tpcds s_gmt_offset;
        d_money_tpcds s_tax_precentage;

    friend std::ostream& operator<<(std::ostream& output, store_t& source) {
        output << source.s_store_sk << source.s_store_id << source.s_rec_start_date << source.s_rec_end_date << source.s_closed_date_sk 
                << source.s_store_name << source.s_number_employees << source.s_floor_space << source.s_hours << source.s_manager 
                << source.s_market_id << source.s_geography_class << source.s_market_desc << source.s_market_manager << source.s_division_id 
                << source.s_division_name << source.s_company_id << source.s_company_name << source.s_street_number << source.s_street_name 
                << source.s_street_type << source.s_suite_number << source.s_city << source.s_county << source.s_state << source.s_zip 
                << source.s_country << source.s_gmt_offset << source.s_tax_precentage << std::endl;
        return output;
    }

    friend std::istream& operator>>(std::istream& input, store_t& target) {
        input >> target.s_store_sk >> target.s_store_id >> target.s_rec_start_date >> target.s_rec_end_date >> target.s_closed_date_sk >> 
                target.s_store_name >> target.s_number_employees >> target.s_floor_space >> target.s_hours >> target.s_manager >> 
                target.s_market_id >> target.s_geography_class >> target.s_market_desc >> target.s_market_manager >> target.s_division_id >> 
                target.s_division_name >> target.s_company_id >> target.s_company_name >> target.s_street_number >> target.s_street_name >> 
                target.s_street_type >> target.s_suite_number >> target.s_city >> target.s_county >> target.s_state >> target.s_zip >> 
                target.s_country >> target.s_gmt_offset >> target.s_tax_precentage;
        input.get();
        return input;
    }
};

class store_t_col {
   public:
    long volumn;
    long count;
    std::vector<d_long_tpcds > s_store_sk;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > s_store_id;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > s_rec_start_date;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > s_rec_end_date;
    std::vector<d_long_tpcds > s_closed_date_sk;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > s_store_name;
    std::vector<d_long_tpcds > s_number_employees;
    std::vector<d_long_tpcds > s_floor_space;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > s_hours;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > s_manager;
    std::vector<d_long_tpcds > s_market_id;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > s_geography_class;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > s_market_desc;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > s_market_manager;
    std::vector<d_long_tpcds > s_division_id;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > s_division_name;
    std::vector<d_long_tpcds > s_company_id;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > s_company_name;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > s_street_number;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > s_street_name;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > s_street_type;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > s_suite_number;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > s_city;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > s_county;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > s_state;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > s_zip;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > s_country;
    std::vector<d_money_tpcds > s_gmt_offset;
    std::vector<d_money_tpcds > s_tax_precentage;

    store_t_col() : volumn(0), count(0) {}
    void change_volumn(long ss) {
        volumn = ss;
        count = 0;
        s_store_sk.resize(ss);
        s_store_id.resize(ss);
        s_rec_start_date.resize(ss);
        s_rec_end_date.resize(ss);
        s_closed_date_sk.resize(ss);
        s_store_name.resize(ss);
        s_number_employees.resize(ss);
        s_floor_space.resize(ss);
        s_hours.resize(ss);
        s_manager.resize(ss);
        s_market_id.resize(ss);
        s_geography_class.resize(ss);
        s_market_desc.resize(ss);
        s_market_manager.resize(ss);
        s_division_id.resize(ss);
        s_division_name.resize(ss);
        s_company_id.resize(ss);
        s_company_name.resize(ss);
        s_street_number.resize(ss);
        s_street_name.resize(ss);
        s_street_type.resize(ss);
        s_suite_number.resize(ss);
        s_city.resize(ss);
        s_county.resize(ss);
        s_state.resize(ss);
        s_zip.resize(ss);
        s_country.resize(ss);
        s_gmt_offset.resize(ss);
        s_tax_precentage.resize(ss);
    }

    friend std::ostream& operator<<(std::ostream& output, store_t_col& source) {
        for (int i = 0; i < source.count; i++) {
            output << source.s_store_sk[i] << source.s_store_id[i] << source.s_rec_start_date[i] << source.s_rec_end_date[i] << source.s_closed_date_sk[i] 
                    << source.s_store_name[i] << source.s_number_employees[i] << source.s_floor_space[i] << source.s_hours[i] << source.s_manager[i] 
                    << source.s_market_id[i] << source.s_geography_class[i] << source.s_market_desc[i] << source.s_market_manager[i] << source.s_division_id[i] 
                    << source.s_division_name[i] << source.s_company_id[i] << source.s_company_name[i] << source.s_street_number[i] << source.s_street_name[i] 
                    << source.s_street_type[i] << source.s_suite_number[i] << source.s_city[i] << source.s_county[i] << source.s_state[i] << source.s_zip[i] 
                    << source.s_country[i] << source.s_gmt_offset[i] << source.s_tax_precentage[i] << std::endl;
        }
        return output;
    }

    friend std::istream& operator>>(std::istream& input, store_t_col& target) {
        for (int i = 0; i < target.volumn; i++) {
            if (input.peek() == EOF) {
                target.count = i;
                return input;
            }
            input >> target.s_store_sk[i] >> target.s_store_id[i] >> target.s_rec_start_date[i] >> target.s_rec_end_date[i] >> target.s_closed_date_sk[i] >> 
                    target.s_store_name[i] >> target.s_number_employees[i] >> target.s_floor_space[i] >> target.s_hours[i] >> target.s_manager[i] >> 
                    target.s_market_id[i] >> target.s_geography_class[i] >> target.s_market_desc[i] >> target.s_market_manager[i] >> target.s_division_id[i] >> 
                    target.s_division_name[i] >> target.s_company_id[i] >> target.s_company_name[i] >> target.s_street_number[i] >> target.s_street_name[i] >> 
                    target.s_street_type[i] >> target.s_suite_number[i] >> target.s_city[i] >> target.s_county[i] >> target.s_state[i] >> target.s_zip[i] >> 
                    target.s_country[i] >> target.s_gmt_offset[i] >> target.s_tax_precentage[i];
            input.get();
        }
        target.count = target.volumn;
        return input;
    }
};

class catalog_sales_t {
   public:
        d_long_tpcds cs_sold_date_sk;
        d_long_tpcds cs_sold_time_sk;
        d_long_tpcds cs_ship_date_sk;
        d_long_tpcds cs_bill_customer_sk;
        d_long_tpcds cs_bill_cdemo_sk;
        d_long_tpcds cs_bill_hdemo_sk;
        d_long_tpcds cs_bill_addr_sk;
        d_long_tpcds cs_ship_customer_sk;
        d_long_tpcds cs_ship_cdemo_sk;
        d_long_tpcds cs_ship_hdemo_sk;
        d_long_tpcds cs_ship_addr_sk;
        d_long_tpcds cs_call_center_sk;
        d_long_tpcds cs_catalog_page_sk;
        d_long_tpcds cs_ship_mode_sk;
        d_long_tpcds cs_warehouse_sk;
        d_long_tpcds cs_item_sk;
        d_long_tpcds cs_promo_sk;
        d_long_tpcds cs_order_number;
        d_long_tpcds cs_quantity;
        d_money_tpcds cs_wholesale_cost;
        d_money_tpcds cs_list_price;
        d_money_tpcds cs_sales_price;
        d_money_tpcds cs_ext_discount_amt;
        d_money_tpcds cs_ext_sales_price;
        d_money_tpcds cs_ext_wholesale_cost;
        d_money_tpcds cs_ext_list_price;
        d_money_tpcds cs_ext_tax;
        d_money_tpcds cs_coupon_amt;
        d_money_tpcds cs_ext_ship_cost;
        d_money_tpcds cs_net_paid;
        d_money_tpcds cs_net_paid_inc_tax;
        d_money_tpcds cs_net_paid_inc_ship;
        d_money_tpcds cs_net_paid_inc_ship_tax;
        d_money_tpcds cs_net_profit;

    friend std::ostream& operator<<(std::ostream& output, catalog_sales_t& source) {
        output << source.cs_sold_date_sk << source.cs_sold_time_sk << source.cs_ship_date_sk 
                << source.cs_bill_customer_sk << source.cs_bill_cdemo_sk << source.cs_bill_hdemo_sk 
                << source.cs_bill_addr_sk << source.cs_ship_customer_sk << source.cs_ship_cdemo_sk 
                << source.cs_ship_hdemo_sk << source.cs_ship_addr_sk << source.cs_call_center_sk 
                << source.cs_catalog_page_sk << source.cs_ship_mode_sk << source.cs_warehouse_sk 
                << source.cs_item_sk << source.cs_promo_sk << source.cs_order_number << source.cs_quantity 
                << source.cs_wholesale_cost << source.cs_list_price << source.cs_sales_price 
                << source.cs_ext_discount_amt << source.cs_ext_sales_price << source.cs_ext_wholesale_cost 
                << source.cs_ext_list_price << source.cs_ext_tax << source.cs_coupon_amt 
                << source.cs_ext_ship_cost << source.cs_net_paid << source.cs_net_paid_inc_tax 
                << source.cs_net_paid_inc_ship << source.cs_net_paid_inc_ship_tax << source.cs_net_profit << std::endl;
        return output;
    }

    friend std::istream& operator>>(std::istream& input, catalog_sales_t& target) {
        input >> target.cs_sold_date_sk >> target.cs_sold_time_sk >> target.cs_ship_date_sk >> 
                target.cs_bill_customer_sk >> target.cs_bill_cdemo_sk >> target.cs_bill_hdemo_sk >> 
                target.cs_bill_addr_sk >> target.cs_ship_customer_sk >> target.cs_ship_cdemo_sk >> 
                target.cs_ship_hdemo_sk >> target.cs_ship_addr_sk >> target.cs_call_center_sk >> 
                target.cs_catalog_page_sk >> target.cs_ship_mode_sk >> target.cs_warehouse_sk >> 
                target.cs_item_sk >> target.cs_promo_sk >> target.cs_order_number >> target.cs_quantity >> 
                target.cs_wholesale_cost >> target.cs_list_price >> target.cs_sales_price >> 
                target.cs_ext_discount_amt >> target.cs_ext_sales_price >> target.cs_ext_wholesale_cost >> 
                target.cs_ext_list_price >> target.cs_ext_tax >> target.cs_coupon_amt >> 
                target.cs_ext_ship_cost >> target.cs_net_paid >> target.cs_net_paid_inc_tax >> 
                target.cs_net_paid_inc_ship >> target.cs_net_paid_inc_ship_tax >> target.cs_net_profit;
        input.get();
        return input;
    }
};

class catalog_sales_t_col {
   public:
    long volumn;
    long count;

    std::vector<d_long_tpcds > cs_sold_date_sk;
    std::vector<d_long_tpcds > cs_sold_time_sk;
    std::vector<d_long_tpcds > cs_ship_date_sk;
    std::vector<d_long_tpcds > cs_bill_customer_sk;
    std::vector<d_long_tpcds > cs_bill_cdemo_sk;
    std::vector<d_long_tpcds > cs_bill_hdemo_sk;
    std::vector<d_long_tpcds > cs_bill_addr_sk;
    std::vector<d_long_tpcds > cs_ship_customer_sk;
    std::vector<d_long_tpcds > cs_ship_cdemo_sk;
    std::vector<d_long_tpcds > cs_ship_hdemo_sk;
    std::vector<d_long_tpcds > cs_ship_addr_sk;
    std::vector<d_long_tpcds > cs_call_center_sk;
    std::vector<d_long_tpcds > cs_catalog_page_sk;
    std::vector<d_long_tpcds > cs_ship_mode_sk;
    std::vector<d_long_tpcds > cs_warehouse_sk;
    std::vector<d_long_tpcds > cs_item_sk;
    std::vector<d_long_tpcds > cs_promo_sk;
    std::vector<d_long_tpcds > cs_order_number;
    std::vector<d_long_tpcds > cs_quantity;
    std::vector<d_money_tpcds > cs_wholesale_cost;
    std::vector<d_money_tpcds > cs_list_price;
    std::vector<d_money_tpcds > cs_sales_price;
    std::vector<d_money_tpcds > cs_ext_discount_amt;
    std::vector<d_money_tpcds > cs_ext_sales_price;
    std::vector<d_money_tpcds > cs_ext_wholesale_cost;
    std::vector<d_money_tpcds > cs_ext_list_price;
    std::vector<d_money_tpcds > cs_ext_tax;
    std::vector<d_money_tpcds > cs_coupon_amt;
    std::vector<d_money_tpcds > cs_ext_ship_cost;
    std::vector<d_money_tpcds > cs_net_paid;
    std::vector<d_money_tpcds > cs_net_paid_inc_tax;
    std::vector<d_money_tpcds > cs_net_paid_inc_ship;
    std::vector<d_money_tpcds > cs_net_paid_inc_ship_tax;
    std::vector<d_money_tpcds > cs_net_profit;

    catalog_sales_t_col() : volumn(0), count(0) {}
    void change_volumn(long ss) {
        volumn = ss;
        count = 0;
        cs_sold_date_sk.resize(ss);
        cs_sold_time_sk.resize(ss);
        cs_ship_date_sk.resize(ss);
        cs_bill_customer_sk.resize(ss);
        cs_bill_cdemo_sk.resize(ss);
        cs_bill_hdemo_sk.resize(ss);
        cs_bill_addr_sk.resize(ss);
        cs_ship_customer_sk.resize(ss);
        cs_ship_cdemo_sk.resize(ss);
        cs_ship_hdemo_sk.resize(ss);
        cs_ship_addr_sk.resize(ss);
        cs_call_center_sk.resize(ss);
        cs_catalog_page_sk.resize(ss);
        cs_ship_mode_sk.resize(ss);
        cs_warehouse_sk.resize(ss);
        cs_item_sk.resize(ss);
        cs_promo_sk.resize(ss);
        cs_order_number.resize(ss);
        cs_quantity.resize(ss);
        cs_wholesale_cost.resize(ss);
        cs_list_price.resize(ss);
        cs_sales_price.resize(ss);
        cs_ext_discount_amt.resize(ss);
        cs_ext_sales_price.resize(ss);
        cs_ext_wholesale_cost.resize(ss);
        cs_ext_list_price.resize(ss);
        cs_ext_tax.resize(ss);
        cs_coupon_amt.resize(ss);
        cs_ext_ship_cost.resize(ss);
        cs_net_paid.resize(ss);
        cs_net_paid_inc_tax.resize(ss);
        cs_net_paid_inc_ship.resize(ss);
        cs_net_paid_inc_ship_tax.resize(ss);
        cs_net_profit.resize(ss);
    }

    friend std::ostream& operator<<(std::ostream& output, catalog_sales_t_col& source) {
        for (int i = 0; i < source.count; i++) {
            output << source.cs_sold_date_sk[i] << source.cs_sold_time_sk[i] << source.cs_ship_date_sk[i] 
                << source.cs_bill_customer_sk[i] << source.cs_bill_cdemo_sk[i] << source.cs_bill_hdemo_sk[i] 
                << source.cs_bill_addr_sk[i] << source.cs_ship_customer_sk[i] << source.cs_ship_cdemo_sk[i] 
                << source.cs_ship_hdemo_sk[i] << source.cs_ship_addr_sk[i] << source.cs_call_center_sk[i] 
                << source.cs_catalog_page_sk[i] << source.cs_ship_mode_sk[i] << source.cs_warehouse_sk[i] 
                << source.cs_item_sk[i] << source.cs_promo_sk[i] << source.cs_order_number[i] << source.cs_quantity[i] 
                << source.cs_wholesale_cost[i] << source.cs_list_price[i] << source.cs_sales_price[i] 
                << source.cs_ext_discount_amt[i] << source.cs_ext_sales_price[i] << source.cs_ext_wholesale_cost[i] 
                << source.cs_ext_list_price[i] << source.cs_ext_tax[i] << source.cs_coupon_amt[i] 
                << source.cs_ext_ship_cost[i] << source.cs_net_paid[i] << source.cs_net_paid_inc_tax[i] 
                << source.cs_net_paid_inc_ship[i] << source.cs_net_paid_inc_ship_tax[i] << source.cs_net_profit[i] << std::endl;
        }
        return output;
    }

    friend std::istream& operator>>(std::istream& input, catalog_sales_t_col& target) {
        for (int i = 0; i < target.volumn; i++) {
            if (input.peek() == EOF) {
                target.count = i;
                return input;
            }
            input >> target.cs_sold_date_sk[i] >> target.cs_sold_time_sk[i] >> target.cs_ship_date_sk[i] >> 
                    target.cs_bill_customer_sk[i] >> target.cs_bill_cdemo_sk[i] >> target.cs_bill_hdemo_sk[i] >> 
                    target.cs_bill_addr_sk[i] >> target.cs_ship_customer_sk[i] >> target.cs_ship_cdemo_sk[i] >> 
                    target.cs_ship_hdemo_sk[i] >> target.cs_ship_addr_sk[i] >> target.cs_call_center_sk[i] >> 
                    target.cs_catalog_page_sk[i] >> target.cs_ship_mode_sk[i] >> target.cs_warehouse_sk[i] >> 
                    target.cs_item_sk[i] >> target.cs_promo_sk[i] >> target.cs_order_number[i] >> target.cs_quantity[i] >> 
                    target.cs_wholesale_cost[i] >> target.cs_list_price[i] >> target.cs_sales_price[i] >> 
                    target.cs_ext_discount_amt[i] >> target.cs_ext_sales_price[i] >> target.cs_ext_wholesale_cost[i] >> 
                    target.cs_ext_list_price[i] >> target.cs_ext_tax[i] >> target.cs_coupon_amt[i] >> 
                    target.cs_ext_ship_cost[i] >> target.cs_net_paid[i] >> target.cs_net_paid_inc_tax[i] >> 
                    target.cs_net_paid_inc_ship[i] >> target.cs_net_paid_inc_ship_tax[i] >> target.cs_net_profit[i];
            input.get();
        }
        target.count = target.volumn;
        return input;
    }
};

class store_returns_t {
   public:
    d_long_tpcds sr_returned_date_sk;
    d_long_tpcds sr_return_time_sk;
    d_long_tpcds sr_item_sk;
    d_long_tpcds sr_customer_sk;
    d_long_tpcds sr_cdemo_sk;
    d_long_tpcds sr_hdemo_sk;
    d_long_tpcds sr_addr_sk;
    d_long_tpcds sr_store_sk;
    d_long_tpcds sr_reason_sk;
    d_long_tpcds sr_ticket_number;
    d_long_tpcds sr_return_quantity;
    d_money_tpcds sr_return_amt;
    d_money_tpcds sr_return_tax;
    d_money_tpcds sr_return_amt_inc_tax;
    d_money_tpcds sr_fee;
    d_money_tpcds sr_return_ship_cost;
    d_money_tpcds sr_refunded_cash;
    d_money_tpcds sr_reversed_charge;
    d_money_tpcds sr_store_credit;
    d_money_tpcds sr_net_loss;

    friend std::ostream& operator<<(std::ostream& output, store_returns_t& source) {
        output << source.sr_returned_date_sk << source.sr_return_time_sk << source.sr_item_sk 
                << source.sr_customer_sk << source.sr_cdemo_sk << source.sr_hdemo_sk 
                << source.sr_addr_sk << source.sr_store_sk << source.sr_reason_sk 
                << source.sr_ticket_number << source.sr_return_quantity << source.sr_return_amt 
                << source.sr_return_tax << source.sr_return_amt_inc_tax << source.sr_fee 
                << source.sr_return_ship_cost << source.sr_refunded_cash << source.sr_reversed_charge 
                << source.sr_store_credit << source.sr_net_loss << std::endl;
        return output;
    }

    friend std::istream& operator>>(std::istream& input, store_returns_t& target) {
        input >> target.sr_returned_date_sk >> target.sr_return_time_sk >> target.sr_item_sk >> 
                target.sr_customer_sk >> target.sr_cdemo_sk >> target.sr_hdemo_sk >> 
                target.sr_addr_sk >> target.sr_store_sk >> target.sr_reason_sk >> 
                target.sr_ticket_number >> target.sr_return_quantity >> target.sr_return_amt >> 
                target.sr_return_tax >> target.sr_return_amt_inc_tax >> target.sr_fee >> 
                target.sr_return_ship_cost >> target.sr_refunded_cash >> target.sr_reversed_charge >> 
                target.sr_store_credit >> target.sr_net_loss;
        input.get();
        return input;
    }
};

class store_returns_t_col {
   public:
    long volumn;
    long count;
    std::vector<d_long_tpcds > sr_returned_date_sk;
    std::vector<d_long_tpcds > sr_return_time_sk;
    std::vector<d_long_tpcds > sr_item_sk;
    std::vector<d_long_tpcds > sr_customer_sk;
    std::vector<d_long_tpcds > sr_cdemo_sk;
    std::vector<d_long_tpcds > sr_hdemo_sk;
    std::vector<d_long_tpcds > sr_addr_sk;
    std::vector<d_long_tpcds > sr_store_sk;
    std::vector<d_long_tpcds > sr_reason_sk;
    std::vector<d_long_tpcds > sr_ticket_number;
    std::vector<d_long_tpcds > sr_return_quantity;
    std::vector<d_money_tpcds > sr_return_amt;
    std::vector<d_money_tpcds > sr_return_tax;
    std::vector<d_money_tpcds > sr_return_amt_inc_tax;
    std::vector<d_money_tpcds > sr_fee;
    std::vector<d_money_tpcds > sr_return_ship_cost;
    std::vector<d_money_tpcds > sr_refunded_cash;
    std::vector<d_money_tpcds > sr_reversed_charge;
    std::vector<d_money_tpcds > sr_store_credit;
    std::vector<d_money_tpcds > sr_net_loss;

    store_returns_t_col() : volumn(0), count(0) {}
    void change_volumn(long ss) {
        volumn = ss;
        count = 0;
        sr_returned_date_sk.resize(ss);
        sr_return_time_sk.resize(ss);
        sr_item_sk.resize(ss);
        sr_customer_sk.resize(ss);
        sr_cdemo_sk.resize(ss);
        sr_hdemo_sk.resize(ss);
        sr_addr_sk.resize(ss);
        sr_store_sk.resize(ss);
        sr_reason_sk.resize(ss);
        sr_ticket_number.resize(ss);
        sr_return_quantity.resize(ss);
        sr_return_amt.resize(ss);
        sr_return_tax.resize(ss);
        sr_return_amt_inc_tax.resize(ss);
        sr_fee.resize(ss);
        sr_return_ship_cost.resize(ss);
        sr_refunded_cash.resize(ss);
        sr_reversed_charge.resize(ss);
        sr_store_credit.resize(ss);
        sr_net_loss.resize(ss);
    }

    friend std::ostream& operator<<(std::ostream& output, store_returns_t_col& source) {
        for (int i = 0; i < source.count; i++) {
            output << source.sr_returned_date_sk[i] << source.sr_return_time_sk[i] << source.sr_item_sk[i] 
                    << source.sr_customer_sk[i] << source.sr_cdemo_sk[i] << source.sr_hdemo_sk[i] 
                    << source.sr_addr_sk[i] << source.sr_store_sk[i] << source.sr_reason_sk[i] 
                    << source.sr_ticket_number[i] << source.sr_return_quantity[i] << source.sr_return_amt[i] 
                    << source.sr_return_tax[i] << source.sr_return_amt_inc_tax[i] << source.sr_fee[i] 
                    << source.sr_return_ship_cost[i] << source.sr_refunded_cash[i] << source.sr_reversed_charge[i] 
                    << source.sr_store_credit[i] << source.sr_net_loss[i] << std::endl;
        }
        return output;
    }

    friend std::istream& operator>>(std::istream& input, store_returns_t_col& target) {
        for (int i = 0; i < target.volumn; i++) {
            if (input.peek() == EOF) {
                target.count = i;
                return input;
            }
            input >> target.sr_returned_date_sk[i] >> target.sr_return_time_sk[i] >> target.sr_item_sk[i] >> 
                    target.sr_customer_sk[i] >> target.sr_cdemo_sk[i] >> target.sr_hdemo_sk[i] >> 
                    target.sr_addr_sk[i] >> target.sr_store_sk[i] >> target.sr_reason_sk[i] >> 
                    target.sr_ticket_number[i] >> target.sr_return_quantity[i] >> target.sr_return_amt[i] >> 
                    target.sr_return_tax[i] >> target.sr_return_amt_inc_tax[i] >> target.sr_fee[i] >> 
                    target.sr_return_ship_cost[i] >> target.sr_refunded_cash[i] >> target.sr_reversed_charge[i] >> 
                    target.sr_store_credit[i] >> target.sr_net_loss[i];
            input.get();
        }
        target.count = target.volumn;
        return input;
    }
};

class customer_tpcds_t {
   public:
        d_long_tpcds c_customer_sk;
        d_string_tpcds<TPCDS_READ_MAX + 1> c_customer_id;
        d_long_tpcds c_current_cdemo_sk;
        d_long_tpcds c_current_hdemo_sk;
        d_long_tpcds c_current_addr_sk;
        d_long_tpcds c_first_shipto_date_sk;
        d_long_tpcds c_first_sales_date_sk;
        d_string_tpcds<TPCDS_READ_MAX + 1> c_salutation;
        d_string_tpcds<TPCDS_READ_MAX + 1> c_first_name;
        d_string_tpcds<TPCDS_READ_MAX + 1> c_last_name;
        d_string_tpcds<TPCDS_READ_MAX + 1> c_preferred_cust_flag;
        d_long_tpcds c_birth_day;
        d_long_tpcds c_birth_month;
        d_long_tpcds c_birth_year;
        d_string_tpcds<TPCDS_READ_MAX + 1> c_birth_country;
        d_string_tpcds<TPCDS_READ_MAX + 1> c_login;
        d_string_tpcds<TPCDS_READ_MAX + 1> c_email_address;
        d_string_tpcds<TPCDS_READ_MAX + 1> c_last_review_date;

    friend std::ostream& operator<<(std::ostream& output, customer_tpcds_t& source) {
        output << source.c_customer_sk << source.c_customer_id << source.c_current_cdemo_sk 
                << source.c_current_hdemo_sk << source.c_current_addr_sk << source.c_first_shipto_date_sk 
                << source.c_first_sales_date_sk << source.c_salutation << source.c_first_name << source.c_last_name 
                << source.c_preferred_cust_flag << source.c_birth_day << source.c_birth_month << source.c_birth_year 
                << source.c_birth_country << source.c_login << source.c_email_address << source.c_last_review_date << std::endl;
        return output;
    }

    friend std::istream& operator>>(std::istream& input, customer_tpcds_t& target) {
        input >> target.c_customer_sk >> target.c_customer_id >> target.c_current_cdemo_sk >> target.c_current_hdemo_sk >> 
                target.c_current_addr_sk >> target.c_first_shipto_date_sk >> target.c_first_sales_date_sk >> target.c_salutation >> 
                target.c_first_name >> target.c_last_name >> target.c_preferred_cust_flag >> target.c_birth_day >> target.c_birth_month >> 
                target.c_birth_year >> target.c_birth_country >> target.c_login >> target.c_email_address >> target.c_last_review_date;
        input.get();
        return input;
    }
};

class customer_tpcds_t_col {
   public:
    long volumn;
    long count;
    std::vector<d_long_tpcds > c_customer_sk;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > c_customer_id;
    std::vector<d_long_tpcds > c_current_cdemo_sk;
    std::vector<d_long_tpcds > c_current_hdemo_sk;
    std::vector<d_long_tpcds > c_current_addr_sk;
    std::vector<d_long_tpcds > c_first_shipto_date_sk;
    std::vector<d_long_tpcds > c_first_sales_date_sk;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > c_salutation;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > c_first_name;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > c_last_name;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > c_preferred_cust_flag;
    std::vector<d_long_tpcds > c_birth_day;
    std::vector<d_long_tpcds > c_birth_month;
    std::vector<d_long_tpcds > c_birth_year;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > c_birth_country;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > c_login;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > c_email_address;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > c_last_review_date;

    customer_tpcds_t_col() : volumn(0), count(0) {}
    void change_volumn(long ss) {
        volumn = ss;
        count = 0;
        c_customer_sk.resize(ss);
        c_customer_id.resize(ss);
        c_current_cdemo_sk.resize(ss);
        c_current_hdemo_sk.resize(ss);
        c_current_addr_sk.resize(ss);
        c_first_shipto_date_sk.resize(ss);
        c_first_sales_date_sk.resize(ss);
        c_salutation.resize(ss);
        c_first_name.resize(ss);
        c_last_name.resize(ss);
        c_preferred_cust_flag.resize(ss);
        c_birth_day.resize(ss);
        c_birth_month.resize(ss);
        c_birth_year.resize(ss);
        c_birth_country.resize(ss);
        c_login.resize(ss);
        c_email_address.resize(ss);
        c_last_review_date.resize(ss);
    }

    friend std::ostream& operator<<(std::ostream& output, customer_tpcds_t_col& source) {
        for (int i = 0; i < source.count; i++) {
            output << source.c_customer_sk[i] << source.c_customer_id[i] << source.c_current_cdemo_sk[i] 
                    << source.c_current_hdemo_sk[i] << source.c_current_addr_sk[i] << source.c_first_shipto_date_sk[i] 
                    << source.c_first_sales_date_sk[i] << source.c_salutation[i] << source.c_first_name[i] << source.c_last_name[i] 
                    << source.c_preferred_cust_flag[i] << source.c_birth_day[i] << source.c_birth_month[i] << source.c_birth_year[i] 
                    << source.c_birth_country[i] << source.c_login[i] << source.c_email_address[i] << source.c_last_review_date[i] << std::endl;
        }
        return output;
    }

    friend std::istream& operator>>(std::istream& input, customer_tpcds_t_col& target) {
        for (int i = 0; i < target.volumn; i++) {
            if (input.peek() == EOF) {
                target.count = i;
                return input;
            }
            input >> target.c_customer_sk[i] >> target.c_customer_id[i] >> target.c_current_cdemo_sk[i] >> target.c_current_hdemo_sk[i] >> 
                    target.c_current_addr_sk[i] >> target.c_first_shipto_date_sk[i] >> target.c_first_sales_date_sk[i] >> target.c_salutation[i] >> 
                    target.c_first_name[i] >> target.c_last_name[i] >> target.c_preferred_cust_flag[i] >> target.c_birth_day[i] >> target.c_birth_month[i] >> 
                    target.c_birth_year[i] >> target.c_birth_country[i] >> target.c_login[i] >> target.c_email_address[i] >> target.c_last_review_date[i];
            input.get();
        }
        target.count = target.volumn;
        return input;
    }
};

class customer_address_t {
   public:
        d_long_tpcds ca_address_sk;
        d_string_tpcds<TPCDS_READ_MAX + 1> ca_address_id;
        d_string_tpcds<TPCDS_READ_MAX + 1> ca_street_number;
        d_string_tpcds<TPCDS_READ_MAX + 1> ca_street_name;
        d_string_tpcds<TPCDS_READ_MAX + 1> ca_street_type;
        d_string_tpcds<TPCDS_READ_MAX + 1> ca_suite_number;
        d_string_tpcds<TPCDS_READ_MAX + 1> ca_city;
        d_string_tpcds<TPCDS_READ_MAX + 1> ca_county;
        d_string_tpcds<TPCDS_READ_MAX + 1> ca_state;
        d_string_tpcds<TPCDS_READ_MAX + 1> ca_zip;
        d_string_tpcds<TPCDS_READ_MAX + 1> ca_country;
        d_long_tpcds ca_gmt_offset;
        d_string_tpcds<TPCDS_READ_MAX + 1> ca_location_type;

    friend std::ostream& operator<<(std::ostream& output, customer_address_t& source) {
        output << source.ca_address_sk << source.ca_address_id << source.ca_street_number << source.ca_street_name 
                << source.ca_street_type << source.ca_suite_number << source.ca_city << source.ca_county << source.ca_state 
                << source.ca_zip << source.ca_country << source.ca_gmt_offset << source.ca_location_type << std::endl;
        return output;
    }

    friend std::istream& operator>>(std::istream& input, customer_address_t& target) {
        input >> target.ca_address_sk >> target.ca_address_id >> target.ca_street_number >> 
                target.ca_street_name >> target.ca_street_type >> target.ca_suite_number >> 
                target.ca_city >> target.ca_county >> target.ca_state >> target.ca_zip >> 
                target.ca_country >> target.ca_gmt_offset >> target.ca_location_type;
        input.get();
        return input;
    }
};

class customer_address_t_col {
   public:
    long volumn;
    long count;
    std::vector<d_long_tpcds > ca_address_sk;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > ca_address_id;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > ca_street_number;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > ca_street_name;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > ca_street_type;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > ca_suite_number;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > ca_city;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > ca_county;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > ca_state;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > ca_zip;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > ca_country;
    std::vector<d_long_tpcds > ca_gmt_offset;
    std::vector<d_string_tpcds<TPCDS_READ_MAX + 1> > ca_location_type;

    customer_address_t_col() : volumn(0), count(0) {}
    void change_volumn(long ss) {
        volumn = ss;
        count = 0;
        ca_address_sk.resize(ss);
        ca_address_id.resize(ss);
        ca_street_number.resize(ss);
        ca_street_name.resize(ss);
        ca_street_type.resize(ss);
        ca_suite_number.resize(ss);
        ca_city.resize(ss);
        ca_county.resize(ss);
        ca_state.resize(ss);
        ca_zip.resize(ss);
        ca_country.resize(ss);
        ca_gmt_offset.resize(ss);
        ca_location_type.resize(ss);
    }

    friend std::ostream& operator<<(std::ostream& output, customer_address_t_col& source) {
        for (int i = 0; i < source.count; i++) {
            output << source.ca_address_sk[i] << source.ca_address_id[i] << source.ca_street_number[i] << source.ca_street_name[i] 
                    << source.ca_street_type[i] << source.ca_suite_number[i] << source.ca_city[i] << source.ca_county[i] << source.ca_state[i] 
                    << source.ca_zip[i] << source.ca_country[i] << source.ca_gmt_offset[i] << source.ca_location_type[i] << std::endl;
        }
        return output;
    }

    friend std::istream& operator>>(std::istream& input, customer_address_t_col& target) {
        for (int i = 0; i < target.volumn; i++) {
            if (input.peek() == EOF) {
                target.count = i;
                return input;
            }
            input >> target.ca_address_sk[i] >> target.ca_address_id[i] >> target.ca_street_number[i] >> 
                    target.ca_street_name[i] >> target.ca_street_type[i] >> target.ca_suite_number[i] >> 
                    target.ca_city[i] >> target.ca_county[i] >> target.ca_state[i] >> target.ca_zip[i] >> 
                    target.ca_country[i] >> target.ca_gmt_offset[i] >> target.ca_location_type[i];
            input.get();
        }
        target.count = target.volumn;
        return input;
    }
};

/*
class customer_t {
   public:
    d_long_tpcds custkey;
    d_string_tpcds<TPCH_READ_C_NAME_LEN + 1> name;
    d_string_tpcds<TPCH_READ_C_ADDR_MAX + 1> address;
    d_long_tpcds nationkey;
    d_string_tpcds<TPCH_READ_PHONE_LEN + 1> phone;
    d_money_tpcds acctbal;
    d_string_tpcds<TPCH_READ_MAXAGG_LEN + 1> mktsegment;
    d_string_tpcds<TPCH_READ_C_CMNT_MAX + 1> comment;

    friend std::ostream& operator<<(std::ostream& output, customer_t& source) {
        output << source.custkey << source.name << source.address << source.nationkey << source.phone << source.acctbal
               << source.mktsegment << source.comment << std::endl;
        return output;
    }

    friend std::istream& operator>>(std::istream& input, customer_t& target) {
        input >> target.custkey >> target.name >> target.address >> target.nationkey >> target.phone >>
            target.acctbal >> target.mktsegment >> target.comment;
        input.get();
        return input;
    }
};

class customer_t_col {
   public:
    long volumn;
    long count;
    std::vector<d_long_tpcds> custkey;
    std::vector<d_string_tpcds<TPCH_READ_C_NAME_LEN + 1> > name;
    std::vector<d_string_tpcds<TPCH_READ_C_ADDR_MAX + 1> > address;
    std::vector<d_long_tpcds> nationkey;
    std::vector<d_string_tpcds<TPCH_READ_PHONE_LEN + 1> > phone;
    std::vector<d_money_tpcds> acctbal;
    std::vector<d_string_tpcds<TPCH_READ_MAXAGG_LEN + 1> > mktsegment;
    std::vector<d_string_tpcds<TPCH_READ_C_CMNT_MAX + 1> > comment;

    customer_t_col() : volumn(0), count(0) {}
    void change_volumn(long ss) {
        volumn = ss;
        count = 0;
        custkey.resize(ss);
        name.resize(ss);
        address.resize(ss);
        nationkey.resize(ss);
        phone.resize(ss);
        acctbal.resize(ss);
        mktsegment.resize(ss);
        comment.resize(ss);
    }

    friend std::ostream& operator<<(std::ostream& output, customer_t_col& source) {
        for (int i = 0; i < source.count; i++) {
            output << source.custkey[i] << source.name[i] << source.address[i] << source.nationkey[i] << source.phone[i]
                   << source.acctbal[i] << source.mktsegment[i] << source.comment[i] << std::endl;
        }
        return output;
    }

    friend std::istream& operator>>(std::istream& input, customer_t_col& target) {
        for (int i = 0; i < target.volumn; i++) {
            if (input.peek() == EOF) {
                target.count = i;
                return input;
            }
            input >> target.custkey[i] >> target.name[i] >> target.address[i] >> target.nationkey[i] >>
                target.phone[i] >> target.acctbal[i] >> target.mktsegment[i] >> target.comment[i];
            input.get();
        }
        target.count = target.volumn;
        return input;
    }
};

class orders_t {
   public:
    d_long_tpcds orderkey;
    d_long_tpcds custkey;
    d_string_tpcds<2> orderstatus;
    d_money_tpcds totalprice;
    d_date_tpcds orderdate;
    d_string_tpcds<TPCH_READ_MAXAGG_LEN + 1> orderpriority;
    d_string_tpcds<TPCH_READ_O_CLRK_LEN + 1> clerk;
    d_long_tpcds shippriority;
    d_string_tpcds<TPCH_READ_O_CMNT_MAX + 1> comment;

    friend std::ostream& operator<<(std::ostream& output, orders_t& source) {
        output << source.orderkey << source.custkey << source.orderstatus << source.totalprice << source.orderdate
               << source.orderpriority << source.clerk << source.shippriority << source.comment << std::endl;
        return output;
    }

    friend std::istream& operator>>(std::istream& input, orders_t& target) {
        input >> target.orderkey >> target.custkey >> target.orderstatus >> target.totalprice >> target.orderdate >>
            target.orderpriority >> target.clerk >> target.shippriority >> target.comment;
        input.get();
        return input;
    }
};

class orders_t_col {
   public:
    long volumn;
    long count;
    std::vector<d_long_tpcds> orderkey;
    std::vector<d_long_tpcds> custkey;
    std::vector<d_string_tpcds<2> > orderstatus;
    std::vector<d_money_tpcds> totalprice;
    std::vector<d_date_tpcds> orderdate;
    std::vector<d_string_tpcds<TPCH_READ_MAXAGG_LEN + 1> > orderpriority;
    std::vector<d_string_tpcds<TPCH_READ_O_CLRK_LEN + 1> > clerk;
    std::vector<d_long_tpcds> shippriority;
    std::vector<d_string_tpcds<TPCH_READ_O_CMNT_MAX + 1> > comment;

    orders_t_col() : volumn(0), count(0) {}
    void change_volumn(long ss) {
        volumn = ss;
        count = 0;
        orderkey.resize(ss);
        custkey.resize(ss);
        orderstatus.resize(ss);
        totalprice.resize(ss);
        orderdate.resize(ss);
        orderpriority.resize(ss);
        clerk.resize(ss);
        shippriority.resize(ss);
        comment.resize(ss);
    }

    friend std::ostream& operator<<(std::ostream& output, orders_t_col& source) {
        for (int i = 0; i < source.count; i++) {
            output << source.orderkey[i] << source.custkey[i] << source.orderstatus[i] << source.totalprice[i]
                   << source.orderdate[i] << source.orderpriority[i] << source.clerk[i] << source.shippriority[i]
                   << source.comment[i] << std::endl;
        }
        return output;
    }

    friend std::istream& operator>>(std::istream& input, orders_t_col& target) {
        for (int i = 0; i < target.volumn; i++) {
            if (input.peek() == EOF) {
                target.count = i;
                return input;
            }
            input >> target.orderkey[i] >> target.custkey[i] >> target.orderstatus[i] >> target.totalprice[i] >>
                target.orderdate[i] >> target.orderpriority[i] >> target.clerk[i] >> target.shippriority[i] >>
                target.comment[i];
            input.get();
        }
        target.count = target.volumn;
        return input;
    }
};

class lineitem_t {
   public:
    d_long_tpcds orderkey;
    d_long_tpcds partkey;
    d_long_tpcds suppkey;
    d_long_tpcds linenumber;
    d_long_tpcds quantity;
    d_money_tpcds extendedprice;
    d_money_tpcds discount;
    d_money_tpcds tax;
    d_string_tpcds<2> returnflag;
    d_string_tpcds<2> linestatus;
    d_date_tpcds shipdate;
    d_date_tpcds commitdate;
    d_date_tpcds receiptdate;
    d_string_tpcds<TPCH_READ_MAXAGG_LEN + 1> shipinstruct;
    d_string_tpcds<TPCH_READ_MAXAGG_LEN + 1> shipmode;
    d_string_tpcds<TPCH_READ_L_CMNT_MAX + 1> comment;

    friend std::ostream& operator<<(std::ostream& output, lineitem_t& source) {
        output << source.orderkey << source.partkey << source.suppkey << source.linenumber << source.quantity
               << source.extendedprice << source.discount << source.tax << source.returnflag << source.linestatus
               << source.shipdate << source.commitdate << source.receiptdate << source.shipinstruct << source.shipmode
               << source.comment << std::endl;
        return output;
    }

    friend std::istream& operator>>(std::istream& input, lineitem_t& target) {
        input >> target.orderkey >> target.partkey >> target.suppkey >> target.linenumber >> target.quantity >>
            target.extendedprice >> target.discount >> target.tax >> target.returnflag >> target.linestatus >>
            target.shipdate >> target.commitdate >> target.receiptdate >> target.shipinstruct >> target.shipmode >>
            target.comment;
        input.get();
        return input;
    }
};

class lineitem_t_col {
   public:
    long volumn;
    long count;
    std::vector<d_long_tpcds> orderkey;
    std::vector<d_long_tpcds> partkey;
    std::vector<d_long_tpcds> suppkey;
    std::vector<d_long_tpcds> linenumber;
    std::vector<d_long_tpcds> quantity;
    std::vector<d_money_tpcds> extendedprice;
    std::vector<d_money_tpcds> discount;
    std::vector<d_money_tpcds> tax;
    std::vector<d_string_tpcds<2> > returnflag;
    std::vector<d_string_tpcds<2> > linestatus;
    std::vector<d_date_tpcds> commitdate;
    std::vector<d_date_tpcds> shipdate;
    std::vector<d_date_tpcds> receiptdate;
    std::vector<d_string_tpcds<TPCH_READ_MAXAGG_LEN + 1> > shipinstruct;
    std::vector<d_string_tpcds<TPCH_READ_MAXAGG_LEN + 1> > shipmode;
    std::vector<d_string_tpcds<TPCH_READ_L_CMNT_MAX + 1> > comment;

    lineitem_t_col() : volumn(0), count(0) {}
    void change_volumn(long ss) {
        volumn = ss;
        count = 0;
        orderkey.resize(ss);
        partkey.resize(ss);
        suppkey.resize(ss);
        linenumber.resize(ss);
        quantity.resize(ss);
        extendedprice.resize(ss);
        discount.resize(ss);
        tax.resize(ss);
        returnflag.resize(ss);
        linestatus.resize(ss);
        commitdate.resize(ss);
        shipdate.resize(ss);
        receiptdate.resize(ss);
        shipinstruct.resize(ss);
        shipmode.resize(ss);
        comment.resize(ss);
    }

    friend std::ostream& operator<<(std::ostream& output, lineitem_t_col& source) {
        for (int i = 0; i < source.count; i++) {
            output << source.orderkey[i] << source.partkey[i] << source.suppkey[i] << source.linenumber[i]
                   << source.quantity[i] << source.extendedprice[i] << source.discount[i] << source.tax[i]
                   << source.returnflag[i] << source.linestatus[i] << source.shipdate[i] << source.commitdate[i]
                   << source.receiptdate[i] << source.shipinstruct[i] << source.shipmode[i] << source.comment[i]
                   << std::endl;
        }
        return output;
    }

    friend std::istream& operator>>(std::istream& input, lineitem_t_col& target) {
        for (int i = 0; i < target.volumn; i++) {
            if (input.peek() == EOF) {
                target.count = i;
                return input;
            }
            input >> target.orderkey[i] >> target.partkey[i] >> target.suppkey[i] >> target.linenumber[i] >>
                target.quantity[i] >> target.extendedprice[i] >> target.discount[i] >> target.tax[i] >>
                target.returnflag[i] >> target.linestatus[i] >> target.shipdate[i] >> target.commitdate[i] >>
                target.receiptdate[i] >> target.shipinstruct[i] >> target.shipmode[i] >> target.comment[i];
            input.get();
        }
        target.count = target.volumn;
        return input;
    }
};

class nation_t {
   public:
    d_long_tpcds nationkey;
    d_string_tpcds<TPCH_READ_NATION_LEN + 1> name;
    d_long_tpcds regionkey;
    d_string_tpcds<TPCH_READ_N_CMNT_MAX + 1> comment;

    friend std::ostream& operator<<(std::ostream& output, nation_t& source) {
        output << source.nationkey << source.name << source.regionkey << source.comment << std::endl;
        return output;
    }

    friend std::istream& operator>>(std::istream& input, nation_t& target) {
        input >> target.nationkey >> target.name >> target.regionkey >> target.comment;
        input.get();
        return input;
    }
};

class nation_t_col {
   public:
    long volumn;
    long count;
    std::vector<d_long_tpcds> nationkey;
    std::vector<d_string_tpcds<TPCH_READ_NATION_LEN + 1> > name;
    std::vector<d_long_tpcds> regionkey;
    std::vector<d_string_tpcds<TPCH_READ_N_CMNT_MAX + 1> > comment;

    nation_t_col() : volumn(0), count(0) {}
    void change_volumn(long ss) {
        volumn = ss;
        count = 0;
        nationkey.resize(ss);
        name.resize(ss);
        regionkey.resize(ss);
        comment.resize(ss);
    }

    friend std::ostream& operator<<(std::ostream& output, nation_t_col& source) {
        for (int i = 0; i < source.count; i++) {
            output << source.nationkey[i] << source.name[i] << source.regionkey[i] << source.comment[i] << std::endl;
        }
        return output;
    }

    friend std::istream& operator>>(std::istream& input, nation_t_col& target) {
        for (int i = 0; i < target.volumn; i++) {
            if (input.peek() == EOF) {
                target.count = i;
                return input;
            }
            input >> target.nationkey[i] >> target.name[i] >> target.regionkey[i] >> target.comment[i];
            input.get();
        }
        target.count = target.volumn;
        return input;
    }
};

class region_t {
   public:
    d_long_tpcds regionkey;
    d_string_tpcds<TPCH_READ_REGION_LEN + 1> name;
    d_string_tpcds<TPCH_READ_R_CMNT_MAX + 1> comment;

    friend std::ostream& operator<<(std::ostream& output, region_t& source) {
        output << source.regionkey << source.name << source.comment << std::endl;
        return output;
    }

    friend std::istream& operator>>(std::istream& input, region_t& target) {
        input >> target.regionkey >> target.name >> target.comment;
        input.get();
        return input;
    }
};

class region_t_col {
   public:
    long volumn;
    long count;
    std::vector<d_long_tpcds> regionkey;
    std::vector<d_string_tpcds<TPCH_READ_REGION_LEN + 1> > name;
    std::vector<d_string_tpcds<TPCH_READ_R_CMNT_MAX + 1> > comment;

    region_t_col() : volumn(0), count(0) {}
    void change_volumn(long ss) {
        volumn = ss;
        count = 0;
        regionkey.resize(ss);
        name.resize(ss);
        comment.resize(ss);
    }

    friend std::ostream& operator<<(std::ostream& output, region_t_col& source) {
        for (int i = 0; i < source.count; i++) {
            output << source.regionkey[i] << source.name[i] << source.comment[i] << std::endl;
        }
        return output;
    }

    friend std::istream& operator>>(std::istream& input, region_t_col& target) {
        for (int i = 0; i < target.volumn; i++) {
            if (input.peek() == EOF) {
                target.count = i;
                return input;
            }
            input >> target.regionkey[i] >> target.name[i] >> target.comment[i];
            input.get();
        }
        target.count = target.volumn;
        return input;
    }
};

class partsupp_t {
   public:
    d_long_tpcds partkey;
    d_long_tpcds suppkey;
    d_long_tpcds availqty;
    d_money_tpcds supplycost;
    d_string_tpcds<TPCH_READ_PS_CMNT_MAX + 1> comment;

    friend std::ostream& operator<<(std::ostream& output, partsupp_t& source) {
        output << source.partkey << source.suppkey << source.availqty << source.supplycost << source.comment
               << std::endl;
        return output;
    }

    friend std::istream& operator>>(std::istream& input, partsupp_t& target) {
        input >> target.partkey >> target.suppkey >> target.availqty >> target.supplycost >> target.comment;
        input.get();
        return input;
    }
};

class partsupp_t_col {
   public:
    long volumn;
    long count;
    std::vector<d_long_tpcds> partkey;
    std::vector<d_long_tpcds> suppkey;
    std::vector<d_long_tpcds> availqty;
    std::vector<d_money_tpcds> supplycost;
    std::vector<d_string_tpcds<TPCH_READ_PS_CMNT_MAX + 1> > comment;

    partsupp_t_col() : volumn(0), count(0) {}
    void change_volumn(long ss) {
        volumn = ss;
        count = 0;
        partkey.resize(ss);
        suppkey.resize(ss);
        availqty.resize(ss);
        supplycost.resize(ss);
        comment.resize(ss);
    }

    friend std::ostream& operator<<(std::ostream& output, partsupp_t_col& source) {
        for (int i = 0; i < source.count; i++) {
            output << source.partkey[i] << source.suppkey[i] << source.availqty[i] << source.supplycost[i]
                   << source.comment[i] << std::endl;
        }
        return output;
    }

    friend std::istream& operator>>(std::istream& input, partsupp_t_col& target) {
        for (int i = 0; i < target.volumn; i++) {
            if (input.peek() == EOF) {
                target.count = i;
                return input;
            }
            input >> target.partkey[i] >> target.suppkey[i] >> target.availqty[i] >> target.supplycost[i] >>
                target.comment[i];
            input.get();
        }
        target.count = target.volumn;
        return input;
    }
};

class supplier_t {
   public:
    d_long_tpcds suppkey;
    d_string_tpcds<TPCH_READ_S_NAME_LEN + 1> name;
    d_string_tpcds<TPCH_READ_S_ADDR_MAX + 1> address;
    d_long_tpcds nationkey;
    d_string_tpcds<TPCH_READ_PHONE_LEN + 1> phone;
    d_money_tpcds acctbal;
    d_string_tpcds<TPCH_READ_S_CMNT_MAX + 1> comment;

    friend std::ostream& operator<<(std::ostream& output, supplier_t& source) {
        output << source.suppkey << source.name << source.address << source.nationkey << source.phone << source.acctbal
               << source.comment << std::endl;
        return output;
    }

    friend std::istream& operator>>(std::istream& input, supplier_t& target) {
        input >> target.suppkey >> target.name >> target.address >> target.nationkey >> target.phone >>
            target.acctbal >> target.comment;
        input.get();
        return input;
    }
};

class supplier_t_col {
   public:
    long volumn;
    long count;
    std::vector<d_long_tpcds> suppkey;
    std::vector<d_string_tpcds<TPCH_READ_S_NAME_LEN + 1> > name;
    std::vector<d_string_tpcds<TPCH_READ_S_ADDR_MAX + 1> > address;
    std::vector<d_long_tpcds> nationkey;
    std::vector<d_string_tpcds<TPCH_READ_PHONE_LEN + 1> > phone;
    std::vector<d_money_tpcds> acctbal;
    std::vector<d_string_tpcds<TPCH_READ_S_CMNT_MAX + 1> > comment;

    supplier_t_col() : volumn(0), count(0) {}
    void change_volumn(long ss) {
        volumn = ss;
        count = 0;
        suppkey.resize(ss);
        name.resize(ss);
        address.resize(ss);
        nationkey.resize(ss);
        phone.resize(ss);
        acctbal.resize(ss);
        comment.resize(ss);
    }

    friend std::ostream& operator<<(std::ostream& output, supplier_t_col& source) {
        for (int i = 0; i < source.count; i++) {
            output << source.suppkey[i] << source.name[i] << source.address[i] << source.nationkey[i] << source.phone[i]
                   << source.acctbal[i] << source.comment[i] << std::endl;
        }
        return output;
    }

    friend std::istream& operator>>(std::istream& input, supplier_t_col& target) {
        for (int i = 0; i < target.volumn; i++) {
            if (input.peek() == EOF) {
                target.count = i;
                return input;
            }
            input >> target.suppkey[i] >> target.name[i] >> target.address[i] >> target.nationkey[i] >>
                target.phone[i] >> target.acctbal[i] >> target.comment[i];
        }
        target.count = target.volumn;
        return input;
    }
};

class part_t {
   public:
    d_long_tpcds partkey;
    d_string_tpcds<TPCH_READ_P_NAME_LEN + 1> name;
    d_string_tpcds<TPCH_READ_P_MFG_LEN + 1> mfgr;
    d_string_tpcds<TPCH_READ_P_BRND_LEN + 1> brand;
    d_string_tpcds<TPCH_READ_P_TYPE_LEN + 1> type;
    d_long_tpcds size;
    d_string_tpcds<TPCH_READ_P_CNTR_LEN + 1> container;
    d_money_tpcds retailprice;
    d_string_tpcds<TPCH_READ_P_CMNT_MAX + 1> comment;

    friend std::ostream& operator<<(std::ostream& output, part_t& source) {
        output << source.partkey << source.name << source.mfgr << source.brand << source.type << source.size
               << source.container << source.retailprice << source.comment << std::endl;
        return output;
    }

    friend std::istream& operator>>(std::istream& input, part_t& target) {
        input >> target.partkey >> target.name >> target.mfgr >> target.brand >> target.type >> target.size >>
            target.container >> target.retailprice >> target.comment;
        input.get();
        return input;
    }
};

class part_t_col {
   public:
    long volumn;
    long count;
    std::vector<d_long_tpcds> partkey;
    std::vector<d_string_tpcds<TPCH_READ_P_NAME_LEN + 1> > name;
    std::vector<d_string_tpcds<TPCH_READ_P_MFG_LEN + 1> > mfgr;
    std::vector<d_string_tpcds<TPCH_READ_P_BRND_LEN + 1> > brand;
    std::vector<d_string_tpcds<TPCH_READ_P_TYPE_LEN + 1> > type;
    std::vector<d_long_tpcds> size;
    std::vector<d_string_tpcds<TPCH_READ_P_CNTR_LEN + 1> > container;
    std::vector<d_money_tpcds> retailprice;
    std::vector<d_string_tpcds<TPCH_READ_P_CMNT_MAX + 1> > comment;

    part_t_col() : volumn(0), count(0) {}
    void change_volumn(long ss) {
        volumn = ss;
        count = 0;
        partkey.resize(ss);
        name.resize(ss);
        mfgr.resize(ss);
        brand.resize(ss);
        type.resize(ss);
        size.resize(ss);
        container.resize(ss);
        retailprice.resize(ss);
        comment.resize(ss);
    }

    friend std::ostream& operator<<(std::ostream& output, part_t_col& source) {
        for (int i = 0; i < source.count; i++) {
            output << source.partkey[i] << source.name[i] << source.mfgr[i] << source.brand[i] << source.type[i]
                   << source.size[i] << source.container[i] << source.retailprice[i] << source.comment[i] << std::endl;
        }
        return output;
    }

    friend std::istream& operator>>(std::istream& input, part_t_col& target) {
        for (int i = 0; i < target.volumn; i++) {
            if (input.peek() == EOF) {
                target.count = i;
                return input;
            }
            input >> target.partkey[i] >> target.name[i] >> target.mfgr[i] >> target.brand[i] >> target.type[i] >>
                target.size[i] >> target.container[i] >> target.retailprice[i] >> target.comment[i];
        }
        target.count = target.volumn;
        return input;
    }
};
*/

#endif
