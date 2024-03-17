/*
 * Copyright 2019 Xilinx, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "tpch_read_2.hpp"
#include "tpcds_read.hpp"
#include "utils.hpp"

#include <cstdio>
#include <fstream>
// C++11 thread
#include <thread>
#include <cstring>

// ------------------------------------------------------------

template <typename T>
void read_tbl(std::string _path, std::vector<T>& _vec) {
    std::ifstream ifs;
    ifs.open(_path, std::ios_base::in);
    if (!ifs) {
        printf("ERROR: %s cannot ben opened for read.\n", _path.c_str());
        return;
    }
    // read data line
    int count = 0;
    while (ifs) {
count += 1;
        T t;
        ifs >> t;
        if (ifs) {
            _vec.push_back(t);
        }
    }
    printf("File read row count: %d \n", count);
    ifs.close();
    printf("INFO: Loaded %s from disk.\n", _path.c_str());
}

// ------------------------------------------------------------

void columnize_r(region_t* buf_r,
                 size_t nrow, //
                 TPCH_INT* col_r_regionkey,
                 std::vector<std::array<char, TPCH_READ_REGION_LEN + 1> >& col_r_name,
                 std::vector<std::array<char, TPCH_READ_R_CMNT_MAX + 1> >& col_r_comment) {
    for (size_t i = 0; i < nrow; ++i) {
        col_r_regionkey[i] = buf_r[i].regionkey;
        memcpy(col_r_name[i].data(), buf_r[i].name.data, TPCH_READ_REGION_LEN + 1);
        memcpy(col_r_comment[i].data(), buf_r[i].comment.data, TPCH_READ_R_CMNT_MAX + 1);
    }
}

void columnize_n(nation_t* buf_n,
                 size_t nrow, //
                 TPCH_INT* col_n_nationkey,
                 TPCH_INT* col_n_regionkey,
                 std::vector<std::array<char, TPCH_READ_NATION_LEN + 1> >& col_n_name,
                 std::vector<std::array<char, TPCH_READ_N_CMNT_MAX + 1> >& col_n_comment) {
    for (size_t i = 0; i < nrow; ++i) {
        col_n_nationkey[i] = buf_n[i].nationkey;
        col_n_regionkey[i] = buf_n[i].regionkey;
        memcpy(col_n_name[i].data(), buf_n[i].name.data, TPCH_READ_NATION_LEN + 1);
        memcpy(col_n_comment[i].data(), buf_n[i].name.data, TPCH_READ_N_CMNT_MAX + 1);
    }
}

void columnize_c(customer_t* buf_c,
                 size_t nrow, //
                 TPCH_INT* col_c_custkey,
                 std::vector<std::array<char, TPCH_READ_C_NAME_LEN + 1> >& col_c_name,
                 std::vector<std::array<char, TPCH_READ_S_ADDR_MAX + 1> >& col_c_address,
                 TPCH_INT* col_c_nationkey,
                 std::vector<std::array<char, TPCH_READ_PHONE_LEN + 1> >& col_c_phone,
                 TPCH_INT* col_c_acctbal,
                 std::vector<std::array<char, TPCH_READ_MAXAGG_LEN + 1> >& col_c_mktsegment,
                 std::vector<std::array<char, TPCH_READ_C_CMNT_MAX + 1> >& col_c_comment) {
    for (size_t i = 0; i < nrow; ++i) {
        col_c_custkey[i] = buf_c[i].custkey;
        col_c_nationkey[i] = buf_c[i].nationkey;
        col_c_acctbal[i] = buf_c[i].acctbal;
        memcpy(col_c_mktsegment[i].data(), buf_c[i].mktsegment.data, TPCH_READ_MAXAGG_LEN + 1);
        memcpy(col_c_name[i].data(), buf_c[i].name.data, TPCH_READ_C_NAME_LEN + 1);
        memcpy(col_c_address[i].data(), buf_c[i].address.data, TPCH_READ_S_ADDR_MAX + 1);
        memcpy(col_c_phone[i].data(), buf_c[i].phone.data, TPCH_READ_PHONE_LEN + 1);
        memcpy(col_c_comment[i].data(), buf_c[i].comment.data, TPCH_READ_C_CMNT_MAX + 1);
    }
}

void columnize_o(orders_t* buf_o,
                 size_t nrow, //
                 TPCH_INT* col_o_orderkey,
                 TPCH_INT* col_o_custkey,
                 TPCH_INT* col_o_orderstatus,
                 TPCH_INT* col_o_totalprice,
                 TPCH_INT* col_o_orderdate,
                 std::vector<std::array<char, TPCH_READ_MAXAGG_LEN + 1> >& col_o_orderpriority,
                 std::vector<std::array<char, TPCH_READ_O_CLRK_LEN + 1> >& col_o_clerk,
                 TPCH_INT* col_o_shippriority,
                 std::vector<std::array<char, TPCH_READ_O_CMNT_MAX + 1> >& col_o_comment) {
    for (size_t i = 0; i < nrow; ++i) {
        col_o_orderkey[i] = buf_o[i].orderkey;
        col_o_custkey[i] = buf_o[i].custkey;
        col_o_orderstatus[i] = buf_o[i].orderstatus.data[0];
        col_o_totalprice[i] = buf_o[i].totalprice;
        col_o_orderdate[i] = buf_o[i].orderdate;
        memcpy(col_o_orderpriority[i].data(), buf_o[i].orderpriority.data, TPCH_READ_MAXAGG_LEN + 1);
        memcpy(col_o_clerk[i].data(), buf_o[i].clerk.data, TPCH_READ_O_CLRK_LEN + 1);
        col_o_shippriority[i] = buf_o[i].shippriority;
        memcpy(col_o_comment[i].data(), buf_o[i].comment.data, TPCH_READ_O_CMNT_MAX + 1);
    }
}

void columnize_l(lineitem_t* buf_l,
                 size_t nrow, //
                 TPCH_INT* col_l_orderkey,
                 TPCH_INT* col_l_partkey,
                 TPCH_INT* col_l_suppkey,
                 TPCH_INT* col_l_linenumber,
                 TPCH_INT* col_l_quantity,
                 TPCH_INT* col_l_extendedprice,
                 TPCH_INT* col_l_discount,
                 TPCH_INT* col_l_tax,
                 TPCH_INT* col_l_returnflag,
                 TPCH_INT* col_l_linestatus,
                 TPCH_INT* col_l_shipdate,
                 TPCH_INT* col_l_commitdate,
                 TPCH_INT* col_l_receiptdate,
                 std::vector<std::array<char, TPCH_READ_MAXAGG_LEN + 1> >& col_l_shipinstruct,
                 std::vector<std::array<char, TPCH_READ_MAXAGG_LEN + 1> >& col_l_shipmode,
                 std::vector<std::array<char, TPCH_READ_L_CMNT_MAX + 1> >& col_l_comment) {
    for (size_t i = 0; i < nrow; ++i) {
        col_l_orderkey[i] = buf_l[i].orderkey;
        col_l_partkey[i] = buf_l[i].partkey;
        col_l_suppkey[i] = buf_l[i].suppkey;
        col_l_linenumber[i] = buf_l[i].linenumber;
        col_l_quantity[i] = buf_l[i].quantity;
        col_l_extendedprice[i] = buf_l[i].extendedprice;
        col_l_discount[i] = buf_l[i].discount;
        col_l_tax[i] = buf_l[i].tax;
        col_l_linestatus[i] = (int)buf_l[i].linestatus.data[0];
        col_l_returnflag[i] = (int)buf_l[i].returnflag.data[0];
        col_l_shipdate[i] = buf_l[i].shipdate;
        col_l_commitdate[i] = buf_l[i].commitdate;
        col_l_receiptdate[i] = buf_l[i].receiptdate;
        memcpy(col_l_shipinstruct[i].data(), buf_l[i].shipinstruct.data, TPCH_READ_MAXAGG_LEN + 1);
        memcpy(col_l_shipmode[i].data(), buf_l[i].shipmode.data, TPCH_READ_MAXAGG_LEN + 1);
        memcpy(col_l_comment[i].data(), buf_l[i].comment.data, TPCH_READ_L_CMNT_MAX + 1);
    }
}

void columnize_s(supplier_t* buf_s,
                 size_t nrow, //
                 TPCH_INT* col_s_suppkey,
                 std::vector<std::array<char, TPCH_READ_S_NAME_LEN + 1> >& col_s_name,
                 std::vector<std::array<char, TPCH_READ_S_ADDR_MAX + 1> >& col_s_address,
                 TPCH_INT* col_s_nationkey,
                 std::vector<std::array<char, TPCH_READ_PHONE_LEN + 1> >& col_s_phone,
                 TPCH_INT* col_s_acctbal,
                 std::vector<std::array<char, TPCH_READ_S_CMNT_MAX + 1> >& col_s_comment) {
    for (size_t i = 0; i < nrow; ++i) {
        col_s_suppkey[i] = buf_s[i].suppkey;
        memcpy(col_s_name[i].data(), buf_s[i].name.data, TPCH_READ_S_NAME_LEN + 1);
        memcpy(col_s_address[i].data(), buf_s[i].address.data, TPCH_READ_S_ADDR_MAX + 1);
        col_s_nationkey[i] = buf_s[i].nationkey;
        memcpy(col_s_phone[i].data(), buf_s[i].phone.data, TPCH_READ_PHONE_LEN + 1);
        col_s_acctbal[i] = buf_s[i].acctbal;
        memcpy(col_s_comment[i].data(), buf_s[i].comment.data, TPCH_READ_S_CMNT_MAX + 1);
    }
}

void columnize_p(part_t* buf_p,
                 size_t nrow, //
                 TPCH_INT* col_p_partkey,
                 std::vector<std::array<char, TPCH_READ_P_NAME_LEN + 1> >& col_p_name,
                 std::vector<std::array<char, TPCH_READ_P_MFG_LEN + 1> >& col_p_mfgr,
                 std::vector<std::array<char, TPCH_READ_P_BRND_LEN + 1> >& col_p_brand,
                 std::vector<std::array<char, TPCH_READ_P_TYPE_LEN + 1> >& col_p_type,
                 TPCH_INT* col_p_size,
                 std::vector<std::array<char, TPCH_READ_P_CNTR_LEN + 1> >& col_p_container,
                 TPCH_INT* col_p_retailprice,
                 std::vector<std::array<char, TPCH_READ_P_CMNT_MAX + 1> >& col_p_comment) {
    for (size_t i = 0; i < nrow; ++i) {
        col_p_partkey[i] = buf_p[i].partkey;
        memcpy(col_p_name[i].data(), buf_p[i].name.data, TPCH_READ_P_NAME_LEN + 1);
        memcpy(col_p_mfgr[i].data(), buf_p[i].mfgr.data, TPCH_READ_P_MFG_LEN + 1);
        memcpy(col_p_brand[i].data(), buf_p[i].brand.data, TPCH_READ_P_BRND_LEN + 1);
        memcpy(col_p_type[i].data(), buf_p[i].type.data, TPCH_READ_P_TYPE_LEN + 1);
        col_p_size[i] = buf_p[i].size;
        memcpy(col_p_container[i].data(), buf_p[i].container.data, TPCH_READ_P_CNTR_LEN + 1);

        col_p_retailprice[i] = buf_p[i].retailprice;
        memcpy(col_p_comment[i].data(), buf_p[i].comment.data, TPCH_READ_P_CMNT_MAX + 1);
    }
}

void columnize_ps(partsupp_t* buf_ps,
                  size_t nrow, //
                  TPCH_INT* col_ps_partkey,
                  TPCH_INT* col_ps_suppkey,
                  TPCH_INT* col_ps_availqty,
                  TPCH_INT* col_ps_supplycost,
                  std::vector<std::array<char, TPCH_READ_PS_CMNT_MAX + 1> >& col_ps_comment) {
    for (size_t i = 0; i < nrow; ++i) {
        col_ps_partkey[i] = buf_ps[i].partkey;
        col_ps_suppkey[i] = buf_ps[i].suppkey;
        col_ps_availqty[i] = buf_ps[i].availqty;
        col_ps_supplycost[i] = buf_ps[i].supplycost;
        memcpy(col_ps_comment[i].data(), buf_ps[i].comment.data, TPCH_READ_PS_CMNT_MAX + 1);
    }
}

void columnize_i_tpcds(item_t* buf_i_tpcds,
                    size_t nrow, //
                    TPCDS_INT* col_i_item_sk,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_i_item_id,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_i_rec_start_date,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_i_rec_end_date,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_i_item_desc,
                    TPCDS_INT* col_i_current_price,
                    TPCDS_INT* col_i_wholesale_cost,
                    TPCDS_INT* col_i_brand_id,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_i_brand,
                    TPCDS_INT* col_i_class_id,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_i_class,
                    TPCDS_INT* col_i_category_id,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_i_category,
                    TPCDS_INT* col_i_manufact_id,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_i_manufact,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_i_size,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_i_formulation,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_i_color,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_i_units,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_i_container,
                    TPCDS_INT* col_i_manager_id,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_i_product_name) {
    for (size_t i = 0; i < nrow; ++i) {
        col_i_item_sk[i] = buf_i_tpcds[i].i_item_sk;
        memcpy(col_i_item_id[i].data(), buf_i_tpcds[i].i_item_id.data, TPCDS_READ_MAX + 1);
        memcpy(col_i_rec_start_date[i].data(), buf_i_tpcds[i].i_rec_start_date.data, TPCDS_READ_MAX + 1);
        memcpy(col_i_rec_end_date[i].data(), buf_i_tpcds[i].i_rec_end_date.data, TPCDS_READ_MAX + 1);
        memcpy(col_i_item_desc[i].data(), buf_i_tpcds[i].i_item_desc.data, TPCDS_READ_MAX + 1);
        col_i_current_price[i] = buf_i_tpcds[i].i_current_price;
        col_i_wholesale_cost[i] = buf_i_tpcds[i].i_wholesale_cost;
        col_i_brand_id[i] = buf_i_tpcds[i].i_brand_id;
        memcpy(col_i_brand[i].data(), buf_i_tpcds[i].i_brand.data, TPCDS_READ_MAX + 1);
        col_i_class_id[i] = buf_i_tpcds[i].i_class_id;
        memcpy(col_i_class[i].data(), buf_i_tpcds[i].i_class.data, TPCDS_READ_MAX + 1);
        col_i_category_id[i] = buf_i_tpcds[i].i_category_id;
        memcpy(col_i_category[i].data(), buf_i_tpcds[i].i_category.data, TPCDS_READ_MAX + 1);
        col_i_manufact_id[i] = buf_i_tpcds[i].i_manufact_id;
        memcpy(col_i_manufact[i].data(), buf_i_tpcds[i].i_manufact.data, TPCDS_READ_MAX + 1);
        memcpy(col_i_size[i].data(), buf_i_tpcds[i].i_size.data, TPCDS_READ_MAX + 1);
        memcpy(col_i_formulation[i].data(), buf_i_tpcds[i].i_formulation.data, TPCDS_READ_MAX + 1);
        memcpy(col_i_color[i].data(), buf_i_tpcds[i].i_color.data, TPCDS_READ_MAX + 1);
        memcpy(col_i_units[i].data(), buf_i_tpcds[i].i_units.data, TPCDS_READ_MAX + 1);
        memcpy(col_i_container[i].data(), buf_i_tpcds[i].i_container.data, TPCDS_READ_MAX + 1);
        col_i_manager_id[i] = buf_i_tpcds[i].i_manager_id;
        memcpy(col_i_product_name[i].data(), buf_i_tpcds[i].i_product_name.data, TPCDS_READ_MAX + 1);
    }
}

void columnize_ss_tpcds(store_sales_t* buf_ss_tpcds,
                    size_t nrow, //
                    TPCDS_INT* col_ss_sold_date_sk,       //Int, //bigint,
                    TPCDS_INT* col_ss_sold_time_sk,       //Int, //bigint,
                    TPCDS_INT* col_ss_item_sk,            //Int, //bigint,
                    TPCDS_INT* col_ss_customer_sk,        //Int, //bigint,
                    TPCDS_INT* col_ss_cdemo_sk,           //Int, //bigint,
                    TPCDS_INT* col_ss_hdemo_sk,           //Int, //bigint,
                    TPCDS_INT* col_ss_addr_sk,            //Int, //bigint,
                    TPCDS_INT* col_ss_store_sk,           //Int, //bigint,
                    TPCDS_INT* col_ss_promo_sk,           //Int, //bigint,
                    TPCDS_INT* col_ss_ticket_number,      //Int, //bigint,
                    TPCDS_INT* col_ss_quantity,           //Int,
                    TPCDS_INT* col_ss_wholesale_cost,     //Int, //decimal(7,2),
                    TPCDS_INT* col_ss_list_price,         //Int, //decimal(7,2),
                    TPCDS_INT* col_ss_sales_price,        //Int, //decimal(7,2),
                    TPCDS_INT* col_ss_ext_discount_amt,   //Int, //decimal(7,2),
                    TPCDS_INT* col_ss_ext_sales_price,    //Int, //decimal(7,2),
                    TPCDS_INT* col_ss_ext_wholesale_cost, //Int, //decimal(7,2),
                    TPCDS_INT* col_ss_ext_list_price,     //Int, //decimal(7,2),
                    TPCDS_INT* col_ss_ext_tax,            //Int, //decimal(7,2),
                    TPCDS_INT* col_ss_coupon_amt,         //Int, //decimal(7,2),
                    TPCDS_INT* col_ss_net_paid,           //Int, //decimal(7,2),
                    TPCDS_INT* col_ss_net_paid_inc_tax,   //Int, //decimal(7,2),
                    TPCDS_INT* col_ss_net_profit          //Int  //decimal(7,2)
                    ) {
    for (size_t i = 0; i < nrow; ++i) {
        col_ss_sold_date_sk[i] = buf_ss_tpcds[i].ss_sold_date_sk;
        col_ss_sold_time_sk[i] = buf_ss_tpcds[i].ss_sold_time_sk;
        col_ss_item_sk[i] = buf_ss_tpcds[i].ss_item_sk;
        col_ss_customer_sk[i] = buf_ss_tpcds[i].ss_customer_sk;
        col_ss_cdemo_sk[i] = buf_ss_tpcds[i].ss_cdemo_sk;
        col_ss_hdemo_sk[i] = buf_ss_tpcds[i].ss_hdemo_sk;
        col_ss_addr_sk[i] = buf_ss_tpcds[i].ss_addr_sk;
        col_ss_store_sk[i] = buf_ss_tpcds[i].ss_store_sk;
        col_ss_promo_sk[i] = buf_ss_tpcds[i].ss_promo_sk;
        col_ss_ticket_number[i] = buf_ss_tpcds[i].ss_ticket_number;
        col_ss_quantity[i] = buf_ss_tpcds[i].ss_quantity;
        col_ss_wholesale_cost[i] = buf_ss_tpcds[i].ss_wholesale_cost;
        col_ss_list_price[i] = buf_ss_tpcds[i].ss_list_price;
        col_ss_sales_price[i] = buf_ss_tpcds[i].ss_sales_price;
        col_ss_ext_discount_amt[i] = buf_ss_tpcds[i].ss_ext_discount_amt;
        col_ss_ext_sales_price[i] = buf_ss_tpcds[i].ss_ext_sales_price;
        col_ss_ext_wholesale_cost[i] = buf_ss_tpcds[i].ss_ext_wholesale_cost;
        col_ss_ext_list_price[i] = buf_ss_tpcds[i].ss_ext_list_price;
        col_ss_ext_tax[i] = buf_ss_tpcds[i].ss_ext_tax;
        col_ss_coupon_amt[i] = buf_ss_tpcds[i].ss_coupon_amt;
        col_ss_net_paid[i] = buf_ss_tpcds[i].ss_net_paid;
        col_ss_net_paid_inc_tax[i] = buf_ss_tpcds[i].ss_net_paid_inc_tax;
        col_ss_net_profit[i] = buf_ss_tpcds[i].ss_net_profit;
    }
}

void columnize_d_tpcds(date_dim_t* buf_d_tpcds,
                    size_t nrow, //
                    TPCDS_INT* col_d_date_sk,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_d_date_id,
                    TPCDS_INT* col_d_date,
                    TPCDS_INT* col_d_month_seq,
                    TPCDS_INT* col_d_week_seq,
                    TPCDS_INT* col_d_quarter_seq,
                    TPCDS_INT* col_d_year,
                    TPCDS_INT* col_d_dow,
                    TPCDS_INT* col_d_moy,
                    TPCDS_INT* col_d_dom,
                    TPCDS_INT* col_d_qoy,
                    TPCDS_INT* col_d_fy_year,
                    TPCDS_INT* col_d_fy_quarter_seq,
                    TPCDS_INT* col_d_fy_week_seq,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_d_day_name,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_d_quarter_name,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_d_holiday,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_d_weekend,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_d_following_holiday,
                    TPCDS_INT* col_d_first_dom,
                    TPCDS_INT* col_d_last_dom,
                    TPCDS_INT* col_d_same_day_ly,
                    TPCDS_INT* col_d_same_day_lq,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_d_current_day,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_d_current_week,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_d_current_month,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_d_current_quarter,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_d_current_year) {
    for (size_t i = 0; i < nrow; ++i) {
        col_d_date_sk[i] = buf_d_tpcds[i].d_date_sk;
        memcpy(col_d_date_id[i].data(), buf_d_tpcds[i].d_date_id.data, TPCDS_READ_MAX + 1);
        col_d_date[i] = buf_d_tpcds[i].d_date;
        col_d_month_seq[i] = buf_d_tpcds[i].d_month_seq;
        col_d_week_seq[i] = buf_d_tpcds[i].d_week_seq;
        col_d_quarter_seq[i] = buf_d_tpcds[i].d_quarter_seq;
        col_d_year[i] = buf_d_tpcds[i].d_year;
        col_d_dow[i] = buf_d_tpcds[i].d_dow;
        col_d_moy[i] = buf_d_tpcds[i].d_moy;
        col_d_dom[i] = buf_d_tpcds[i].d_dom;
        col_d_qoy[i] = buf_d_tpcds[i].d_qoy;
        col_d_fy_year[i] = buf_d_tpcds[i].d_fy_year;
        col_d_fy_quarter_seq[i] = buf_d_tpcds[i].d_fy_quarter_seq;
        col_d_fy_week_seq[i] = buf_d_tpcds[i].d_fy_week_seq;
        memcpy(col_d_day_name[i].data(), buf_d_tpcds[i].d_day_name.data, TPCDS_READ_MAX + 1);
        memcpy(col_d_quarter_name[i].data(), buf_d_tpcds[i].d_quarter_name.data, TPCDS_READ_MAX + 1);
        memcpy(col_d_holiday[i].data(), buf_d_tpcds[i].d_holiday.data, TPCDS_READ_MAX + 1);
        memcpy(col_d_weekend[i].data(), buf_d_tpcds[i].d_weekend.data, TPCDS_READ_MAX + 1);
        memcpy(col_d_following_holiday[i].data(), buf_d_tpcds[i].d_following_holiday.data, TPCDS_READ_MAX + 1);
        col_d_first_dom[i] = buf_d_tpcds[i].d_first_dom;
        col_d_last_dom[i] = buf_d_tpcds[i].d_last_dom;
        col_d_same_day_ly[i] = buf_d_tpcds[i].d_same_day_ly;
        col_d_same_day_lq[i] = buf_d_tpcds[i].d_same_day_lq;
        memcpy(col_d_current_day[i].data(), buf_d_tpcds[i].d_current_day.data, TPCDS_READ_MAX + 1);
        memcpy(col_d_current_week[i].data(), buf_d_tpcds[i].d_current_week.data, TPCDS_READ_MAX + 1);
        memcpy(col_d_current_month[i].data(), buf_d_tpcds[i].d_current_month.data, TPCDS_READ_MAX + 1);
        memcpy(col_d_current_quarter[i].data(), buf_d_tpcds[i].d_current_quarter.data, TPCDS_READ_MAX + 1);
        memcpy(col_d_current_year[i].data(), buf_d_tpcds[i].d_current_year.data, TPCDS_READ_MAX + 1);
    }
}

void columnize_cd_tpcds(customer_demographics_t* buf_cd_tpcds,
                    size_t nrow, //
                    TPCDS_INT* col_cd_demo_sk,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_cd_gender,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_cd_marital_status,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_cd_education_status,
                    TPCDS_INT* col_cd_purchase_estimate,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_cd_credit_rating,
                    TPCDS_INT* col_cd_dep_count,
                    TPCDS_INT* col_cd_dep_employed_count,
                    TPCDS_INT* col_cd_dep_college_count) {
    for (size_t i = 0; i < nrow; ++i) {
        col_cd_demo_sk[i] = buf_cd_tpcds[i].cd_demo_sk;
        memcpy(col_cd_gender[i].data(), buf_cd_tpcds[i].cd_gender.data, TPCDS_READ_MAX + 1);
        memcpy(col_cd_marital_status[i].data(), buf_cd_tpcds[i].cd_marital_status.data, TPCDS_READ_MAX + 1);
        memcpy(col_cd_education_status[i].data(), buf_cd_tpcds[i].cd_education_status.data, TPCDS_READ_MAX + 1);
        col_cd_purchase_estimate[i] = buf_cd_tpcds[i].cd_purchase_estimate;
        memcpy(col_cd_credit_rating[i].data(), buf_cd_tpcds[i].cd_credit_rating.data, TPCDS_READ_MAX + 1);
        col_cd_dep_count[i] = buf_cd_tpcds[i].cd_dep_count;
        col_cd_dep_employed_count[i] = buf_cd_tpcds[i].cd_dep_employed_count;
        col_cd_dep_college_count[i] = buf_cd_tpcds[i].cd_dep_college_count;
    }
}

void columnize_p_tpcds(promotion_t* buf_p_tpcds,
                    size_t nrow, //
                    TPCDS_INT* col_p_promo_sk,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_p_promo_id,
                    TPCDS_INT* col_p_start_date_sk,
                    TPCDS_INT* col_p_end_date_sk,
                    TPCDS_INT* col_p_item_sk,
                    TPCDS_INT* col_p_cost,
                    TPCDS_INT* col_p_response_target,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_p_promo_name,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_p_channel_dmail,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_p_channel_email,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_p_channel_catalog,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_p_channel_tv,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_p_channel_radio,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_p_channel_press,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_p_channel_event,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_p_channel_demo,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_p_channel_details,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_p_purpose,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_p_discount_active) {
    for (size_t i = 0; i < nrow; ++i) {
        col_p_promo_sk[i] = buf_p_tpcds[i].p_promo_sk;
        memcpy(col_p_promo_id[i].data(), buf_p_tpcds[i].p_promo_id.data, TPCDS_READ_MAX + 1);
        col_p_start_date_sk[i] = buf_p_tpcds[i].p_start_date_sk;
        col_p_end_date_sk[i] = buf_p_tpcds[i].p_end_date_sk;
        col_p_item_sk[i] = buf_p_tpcds[i].p_item_sk;
        col_p_cost[i] = buf_p_tpcds[i].p_cost;
        col_p_response_target[i] = buf_p_tpcds[i].p_response_target;
        memcpy(col_p_promo_name[i].data(), buf_p_tpcds[i].p_promo_name.data, TPCDS_READ_MAX + 1);
        memcpy(col_p_channel_dmail[i].data(), buf_p_tpcds[i].p_channel_dmail.data, TPCDS_READ_MAX + 1);
        memcpy(col_p_channel_email[i].data(), buf_p_tpcds[i].p_channel_email.data, TPCDS_READ_MAX + 1);
        memcpy(col_p_channel_catalog[i].data(), buf_p_tpcds[i].p_channel_catalog.data, TPCDS_READ_MAX + 1);
        memcpy(col_p_channel_tv[i].data(), buf_p_tpcds[i].p_channel_tv.data, TPCDS_READ_MAX + 1);
        memcpy(col_p_channel_radio[i].data(), buf_p_tpcds[i].p_channel_radio.data, TPCDS_READ_MAX + 1);
        memcpy(col_p_channel_press[i].data(), buf_p_tpcds[i].p_channel_press.data, TPCDS_READ_MAX + 1);
        memcpy(col_p_channel_event[i].data(), buf_p_tpcds[i].p_channel_event.data, TPCDS_READ_MAX + 1);
        memcpy(col_p_channel_demo[i].data(), buf_p_tpcds[i].p_channel_demo.data, TPCDS_READ_MAX + 1);
        memcpy(col_p_channel_details[i].data(), buf_p_tpcds[i].p_channel_details.data, TPCDS_READ_MAX + 1);
        memcpy(col_p_purpose[i].data(), buf_p_tpcds[i].p_purpose.data, TPCDS_READ_MAX + 1);
        memcpy(col_p_discount_active[i].data(), buf_p_tpcds[i].p_discount_active.data, TPCDS_READ_MAX + 1);
    }
}

void columnize_hd_tpcds(household_demographics_t* buf_hd_tpcds,
                    size_t nrow, //
                    TPCDS_INT* col_hd_demo_sk,
                    TPCDS_INT* col_hd_income_band_sk,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_hd_buy_potential,
                    TPCDS_INT* col_hd_dep_count,
                    TPCDS_INT* col_hd_vehicle_count) {
    for (size_t i = 0; i < nrow; ++i) {
        col_hd_demo_sk[i] = buf_hd_tpcds[i].hd_demo_sk;
        col_hd_income_band_sk[i] = buf_hd_tpcds[i].hd_income_band_sk;
        memcpy(col_hd_buy_potential[i].data(), buf_hd_tpcds[i].hd_buy_potential.data, TPCDS_READ_MAX + 1);
        col_hd_dep_count[i] = buf_hd_tpcds[i].hd_dep_count;
        col_hd_vehicle_count[i] = buf_hd_tpcds[i].hd_vehicle_count;
    }
}

void columnize_t_tpcds(time_dim_t* buf_t_tpcds,
                    size_t nrow, //
                    TPCDS_INT* col_t_time_sk,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_t_time_id,
                    TPCDS_INT* col_t_time,
                    TPCDS_INT* col_t_hour,
                    TPCDS_INT* col_t_minute,
                    TPCDS_INT* col_t_second,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_t_am_pm,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_t_shift,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_t_sub_shift,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_t_meal_time) {
    for (size_t i = 0; i < nrow; ++i) {
        col_t_time_sk[i] = buf_t_tpcds[i].t_time_sk;
        memcpy(col_t_time_id[i].data(), buf_t_tpcds[i].t_time_id.data, TPCDS_READ_MAX + 1);
        col_t_time[i] = buf_t_tpcds[i].t_time;
        col_t_hour[i] = buf_t_tpcds[i].t_hour;
        col_t_minute[i] = buf_t_tpcds[i].t_minute;
        col_t_second[i] = buf_t_tpcds[i].t_second;
        memcpy(col_t_am_pm[i].data(), buf_t_tpcds[i].t_am_pm.data, TPCDS_READ_MAX + 1);
        memcpy(col_t_shift[i].data(), buf_t_tpcds[i].t_shift.data, TPCDS_READ_MAX + 1);
        memcpy(col_t_sub_shift[i].data(), buf_t_tpcds[i].t_sub_shift.data, TPCDS_READ_MAX + 1);
        memcpy(col_t_meal_time[i].data(), buf_t_tpcds[i].t_meal_time.data, TPCDS_READ_MAX + 1);
    }
}

void columnize_s_tpcds(store_t* buf_s_tpcds,
                    size_t nrow, //
                    TPCDS_INT* col_s_store_sk,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_s_store_id,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_s_rec_start_date,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_s_rec_end_date,
                    TPCDS_INT* col_s_closed_date_sk,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_s_store_name,
                    TPCDS_INT* col_s_number_employees,
                    TPCDS_INT* col_s_floor_space,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_s_hours,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_s_manager,
                    TPCDS_INT* col_s_market_id,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_s_geography_class,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_s_market_desc,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_s_market_manager,
                    TPCDS_INT* col_s_division_id,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_s_division_name,
                    TPCDS_INT* col_s_company_id,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_s_company_name,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_s_street_number,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_s_street_name,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_s_street_type,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_s_suite_number,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_s_city,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_s_county,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_s_state,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_s_zip,
                    std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_s_country,
                    TPCDS_INT* col_s_gmt_offset,
                    TPCDS_INT* col_s_tax_precentage) {
    for (size_t i = 0; i < nrow; ++i) {
        col_s_store_sk[i] = buf_s_tpcds[i].s_store_sk;
        memcpy(col_s_store_id[i].data(), buf_s_tpcds[i].s_store_id.data, TPCDS_READ_MAX + 1);
        memcpy(col_s_rec_start_date[i].data(), buf_s_tpcds[i].s_rec_start_date.data, TPCDS_READ_MAX + 1);
        memcpy(col_s_rec_end_date[i].data(), buf_s_tpcds[i].s_rec_end_date.data, TPCDS_READ_MAX + 1);
        col_s_closed_date_sk[i] = buf_s_tpcds[i].s_closed_date_sk;
        memcpy(col_s_store_name[i].data(), buf_s_tpcds[i].s_store_name.data, TPCDS_READ_MAX + 1);
        col_s_number_employees[i] = buf_s_tpcds[i].s_number_employees;
        col_s_floor_space[i] = buf_s_tpcds[i].s_floor_space;
        memcpy(col_s_hours[i].data(), buf_s_tpcds[i].s_hours.data, TPCDS_READ_MAX + 1);
        memcpy(col_s_manager[i].data(), buf_s_tpcds[i].s_manager.data, TPCDS_READ_MAX + 1);
        col_s_market_id[i] = buf_s_tpcds[i].s_market_id;
        memcpy(col_s_geography_class[i].data(), buf_s_tpcds[i].s_geography_class.data, TPCDS_READ_MAX + 1);
        memcpy(col_s_market_desc[i].data(), buf_s_tpcds[i].s_market_desc.data, TPCDS_READ_MAX + 1);
        memcpy(col_s_market_manager[i].data(), buf_s_tpcds[i].s_market_manager.data, TPCDS_READ_MAX + 1);
        col_s_division_id[i] = buf_s_tpcds[i].s_division_id;
        memcpy(col_s_division_name[i].data(), buf_s_tpcds[i].s_division_name.data, TPCDS_READ_MAX + 1);
        col_s_company_id[i] = buf_s_tpcds[i].s_company_id;
        memcpy(col_s_company_name[i].data(), buf_s_tpcds[i].s_company_name.data, TPCDS_READ_MAX + 1);
        memcpy(col_s_street_number[i].data(), buf_s_tpcds[i].s_street_number.data, TPCDS_READ_MAX + 1);
        memcpy(col_s_street_name[i].data(), buf_s_tpcds[i].s_street_name.data, TPCDS_READ_MAX + 1);
        memcpy(col_s_street_type[i].data(), buf_s_tpcds[i].s_street_type.data, TPCDS_READ_MAX + 1);
        memcpy(col_s_suite_number[i].data(), buf_s_tpcds[i].s_suite_number.data, TPCDS_READ_MAX + 1);
        memcpy(col_s_city[i].data(), buf_s_tpcds[i].s_city.data, TPCDS_READ_MAX + 1);
        memcpy(col_s_county[i].data(), buf_s_tpcds[i].s_county.data, TPCDS_READ_MAX + 1);
        memcpy(col_s_state[i].data(), buf_s_tpcds[i].s_state.data, TPCDS_READ_MAX + 1);
        memcpy(col_s_zip[i].data(), buf_s_tpcds[i].s_zip.data, TPCDS_READ_MAX + 1);
        memcpy(col_s_country[i].data(), buf_s_tpcds[i].s_country.data, TPCDS_READ_MAX + 1);
        col_s_gmt_offset[i] = buf_s_tpcds[i].s_gmt_offset;
        col_s_tax_precentage[i] = buf_s_tpcds[i].s_tax_precentage;
    }
}

void columnize_cs_tpcds(catalog_sales_t* buf_cs_tpcds,
                        size_t nrow, //
                        TPCDS_INT* col_cs_sold_date_sk,
                        TPCDS_INT* col_cs_sold_time_sk,
                        TPCDS_INT* col_cs_ship_date_sk,
                        TPCDS_INT* col_cs_bill_customer_sk,
                        TPCDS_INT* col_cs_bill_cdemo_sk,
                        TPCDS_INT* col_cs_bill_hdemo_sk,
                        TPCDS_INT* col_cs_bill_addr_sk,
                        TPCDS_INT* col_cs_ship_customer_sk,
                        TPCDS_INT* col_cs_ship_cdemo_sk,
                        TPCDS_INT* col_cs_ship_hdemo_sk,
                        TPCDS_INT* col_cs_ship_addr_sk,
                        TPCDS_INT* col_cs_call_center_sk,
                        TPCDS_INT* col_cs_catalog_page_sk,
                        TPCDS_INT* col_cs_ship_mode_sk,
                        TPCDS_INT* col_cs_warehouse_sk,
                        TPCDS_INT* col_cs_item_sk,
                        TPCDS_INT* col_cs_promo_sk,
                        TPCDS_INT* col_cs_order_number,
                        TPCDS_INT* col_cs_quantity,
                        TPCDS_INT* col_cs_wholesale_cost,
                        TPCDS_INT* col_cs_list_price,
                        TPCDS_INT* col_cs_sales_price,
                        TPCDS_INT* col_cs_ext_discount_amt,
                        TPCDS_INT* col_cs_ext_sales_price,
                        TPCDS_INT* col_cs_ext_wholesale_cost,
                        TPCDS_INT* col_cs_ext_list_price,
                        TPCDS_INT* col_cs_ext_tax,
                        TPCDS_INT* col_cs_coupon_amt,
                        TPCDS_INT* col_cs_ext_ship_cost,
                        TPCDS_INT* col_cs_net_paid,
                        TPCDS_INT* col_cs_net_paid_inc_tax,
                        TPCDS_INT* col_cs_net_paid_inc_ship,
                        TPCDS_INT* col_cs_net_paid_inc_ship_tax,
                        TPCDS_INT* col_cs_net_profit) {
    for (size_t i = 0; i < nrow; ++i) {
        col_cs_sold_date_sk[i] = buf_cs_tpcds[i].cs_sold_date_sk;
        col_cs_sold_time_sk[i] = buf_cs_tpcds[i].cs_sold_time_sk;
        col_cs_ship_date_sk[i] = buf_cs_tpcds[i].cs_ship_date_sk;
        col_cs_bill_customer_sk[i] = buf_cs_tpcds[i].cs_bill_customer_sk;
        col_cs_bill_cdemo_sk[i] = buf_cs_tpcds[i].cs_bill_cdemo_sk;
        col_cs_bill_hdemo_sk[i] = buf_cs_tpcds[i].cs_bill_hdemo_sk;
        col_cs_bill_addr_sk[i] = buf_cs_tpcds[i].cs_bill_addr_sk;
        col_cs_ship_customer_sk[i] = buf_cs_tpcds[i].cs_ship_customer_sk;
        col_cs_ship_cdemo_sk[i] = buf_cs_tpcds[i].cs_ship_cdemo_sk;
        col_cs_ship_hdemo_sk[i] = buf_cs_tpcds[i].cs_ship_hdemo_sk;
        col_cs_ship_addr_sk[i] = buf_cs_tpcds[i].cs_ship_addr_sk;
        col_cs_call_center_sk[i] = buf_cs_tpcds[i].cs_call_center_sk;
        col_cs_catalog_page_sk[i] = buf_cs_tpcds[i].cs_catalog_page_sk;
        col_cs_ship_mode_sk[i] = buf_cs_tpcds[i].cs_ship_mode_sk;
        col_cs_warehouse_sk[i] = buf_cs_tpcds[i].cs_warehouse_sk;
        col_cs_item_sk[i] = buf_cs_tpcds[i].cs_item_sk;
        col_cs_promo_sk[i] = buf_cs_tpcds[i].cs_promo_sk;
        col_cs_order_number[i] = buf_cs_tpcds[i].cs_order_number;
        col_cs_quantity[i] = buf_cs_tpcds[i].cs_quantity;
        col_cs_wholesale_cost[i] = buf_cs_tpcds[i].cs_wholesale_cost;
        col_cs_list_price[i] = buf_cs_tpcds[i].cs_list_price;
        col_cs_sales_price[i] = buf_cs_tpcds[i].cs_sales_price;
        col_cs_ext_discount_amt[i] = buf_cs_tpcds[i].cs_ext_discount_amt;
        col_cs_ext_sales_price[i] = buf_cs_tpcds[i].cs_ext_sales_price;
        col_cs_ext_wholesale_cost[i] = buf_cs_tpcds[i].cs_ext_wholesale_cost;
        col_cs_ext_list_price[i] = buf_cs_tpcds[i].cs_ext_list_price;
        col_cs_ext_tax[i] = buf_cs_tpcds[i].cs_ext_tax;
        col_cs_coupon_amt[i] = buf_cs_tpcds[i].cs_coupon_amt;
        col_cs_ext_ship_cost[i] = buf_cs_tpcds[i].cs_ext_ship_cost;
        col_cs_net_paid[i] = buf_cs_tpcds[i].cs_net_paid;
        col_cs_net_paid_inc_tax[i] = buf_cs_tpcds[i].cs_net_paid_inc_tax;
        col_cs_net_paid_inc_ship[i] = buf_cs_tpcds[i].cs_net_paid_inc_ship;
        col_cs_net_paid_inc_ship_tax[i] = buf_cs_tpcds[i].cs_net_paid_inc_ship_tax;
        col_cs_net_profit[i] = buf_cs_tpcds[i].cs_net_profit;
    }
}

void columnize_sr_tpcds(store_returns_t* buf_sr_tpcds,
                        size_t nrow, //
                        TPCDS_INT* col_sr_returned_date_sk,
                        TPCDS_INT* col_sr_return_time_sk,
                        TPCDS_INT* col_sr_item_sk,
                        TPCDS_INT* col_sr_customer_sk,
                        TPCDS_INT* col_sr_cdemo_sk,
                        TPCDS_INT* col_sr_hdemo_sk,
                        TPCDS_INT* col_sr_addr_sk,
                        TPCDS_INT* col_sr_store_sk,
                        TPCDS_INT* col_sr_reason_sk,
                        TPCDS_INT* col_sr_ticket_number,
                        TPCDS_INT* col_sr_return_quantity,
                        TPCDS_INT* col_sr_return_amt,
                        TPCDS_INT* col_sr_return_tax,
                        TPCDS_INT* col_sr_return_amt_inc_tax,
                        TPCDS_INT* col_sr_fee,
                        TPCDS_INT* col_sr_return_ship_cost,
                        TPCDS_INT* col_sr_refunded_cash,
                        TPCDS_INT* col_sr_reversed_charge,
                        TPCDS_INT* col_sr_store_credit,
                        TPCDS_INT* col_sr_net_loss) {
    for (size_t i = 0; i < nrow; ++i) {
        col_sr_returned_date_sk[i] = buf_sr_tpcds[i].sr_returned_date_sk;
        col_sr_return_time_sk[i] = buf_sr_tpcds[i].sr_return_time_sk;
        col_sr_item_sk[i] = buf_sr_tpcds[i].sr_item_sk;
        col_sr_customer_sk[i] = buf_sr_tpcds[i].sr_customer_sk;
        col_sr_cdemo_sk[i] = buf_sr_tpcds[i].sr_cdemo_sk;
        col_sr_hdemo_sk[i] = buf_sr_tpcds[i].sr_hdemo_sk;
        col_sr_addr_sk[i] = buf_sr_tpcds[i].sr_addr_sk;
        col_sr_store_sk[i] = buf_sr_tpcds[i].sr_store_sk;
        col_sr_reason_sk[i] = buf_sr_tpcds[i].sr_reason_sk;
        col_sr_ticket_number[i] = buf_sr_tpcds[i].sr_ticket_number;
        col_sr_return_quantity[i] = buf_sr_tpcds[i].sr_return_quantity;
        col_sr_return_amt[i] = buf_sr_tpcds[i].sr_return_amt;
        col_sr_return_tax[i] = buf_sr_tpcds[i].sr_return_tax;
        col_sr_return_amt_inc_tax[i] = buf_sr_tpcds[i].sr_return_amt_inc_tax;
        col_sr_fee[i] = buf_sr_tpcds[i].sr_fee;
        col_sr_return_ship_cost[i] = buf_sr_tpcds[i].sr_return_ship_cost;
        col_sr_refunded_cash[i] = buf_sr_tpcds[i].sr_refunded_cash;
        col_sr_reversed_charge[i] = buf_sr_tpcds[i].sr_reversed_charge;
        col_sr_store_credit[i] = buf_sr_tpcds[i].sr_store_credit;
        col_sr_net_loss[i] = buf_sr_tpcds[i].sr_net_loss;
    }
}

void columnize_c_tpcds(customer_tpcds_t* buf_c_tpcds,
                        size_t nrow, //
                        TPCDS_INT* col_c_customer_sk,
                        std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_c_customer_id,
                        TPCDS_INT* col_c_current_cdemo_sk,
                        TPCDS_INT* col_c_current_hdemo_sk,
                        TPCDS_INT* col_c_current_addr_sk,
                        TPCDS_INT* col_c_first_shipto_date_sk,
                        TPCDS_INT* col_c_first_sales_date_sk,
                        std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_c_salutation,
                        std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_c_first_name,
                        std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_c_last_name,
                        std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_c_preferred_cust_flag,
                        TPCDS_INT* col_c_birth_day,
                        TPCDS_INT* col_c_birth_month,
                        TPCDS_INT* col_c_birth_year,
                        std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_c_birth_country,
                        std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_c_login,
                        std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_c_email_address,
                        std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_c_last_review_date) {
    for (size_t i = 0; i < nrow; ++i) {
        col_c_customer_sk[i] = buf_c_tpcds[i].c_customer_sk;
        memcpy(col_c_customer_id[i].data(), buf_c_tpcds[i].c_customer_id.data, TPCDS_READ_MAX + 1) ;
        col_c_current_cdemo_sk[i] = buf_c_tpcds[i].c_current_cdemo_sk;
        col_c_current_hdemo_sk[i] = buf_c_tpcds[i].c_current_hdemo_sk;
        col_c_current_addr_sk[i] = buf_c_tpcds[i].c_current_addr_sk;
        col_c_first_shipto_date_sk[i] = buf_c_tpcds[i].c_first_shipto_date_sk;
        col_c_first_sales_date_sk[i] = buf_c_tpcds[i].c_first_sales_date_sk;
        memcpy(col_c_salutation[i].data(), buf_c_tpcds[i].c_salutation.data, TPCDS_READ_MAX + 1) ;
        memcpy(col_c_first_name[i].data(), buf_c_tpcds[i].c_first_name.data, TPCDS_READ_MAX + 1) ;
        memcpy(col_c_last_name[i].data(), buf_c_tpcds[i].c_last_name.data, TPCDS_READ_MAX + 1) ;
        memcpy(col_c_preferred_cust_flag[i].data(), buf_c_tpcds[i].c_preferred_cust_flag.data, TPCDS_READ_MAX + 1) ;
        col_c_birth_day[i] = buf_c_tpcds[i].c_birth_day;
        col_c_birth_month[i] = buf_c_tpcds[i].c_birth_month;
        col_c_birth_year[i] = buf_c_tpcds[i].c_birth_year;
        memcpy(col_c_birth_country[i].data(), buf_c_tpcds[i].c_birth_country.data, TPCDS_READ_MAX + 1) ;
        memcpy(col_c_login[i].data(), buf_c_tpcds[i].c_login.data, TPCDS_READ_MAX + 1) ;
        memcpy(col_c_email_address[i].data(), buf_c_tpcds[i].c_email_address.data, TPCDS_READ_MAX + 1) ;
        memcpy(col_c_last_review_date[i].data(), buf_c_tpcds[i].c_last_review_date.data, TPCDS_READ_MAX + 1) ;
    }
}

void columnize_ca_tpcds(customer_address_t* buf_ca_tpcds,
                        size_t nrow, //
                        TPCDS_INT* col_ca_address_sk,
                        std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_ca_address_id,
                        std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_ca_street_number,
                        std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_ca_street_name,
                        std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_ca_street_type,
                        std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_ca_suite_number,
                        std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_ca_city,
                        std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_ca_county,
                        std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_ca_state,
                        std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_ca_zip,
                        std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_ca_country,
                        TPCDS_INT* col_ca_gmt_offset,
                        std::vector<std::array<char, TPCDS_READ_MAX + 1> >& col_ca_location_type) {
    for (size_t i = 0; i < nrow; ++i) {
        col_ca_address_sk[i] = buf_ca_tpcds[i].ca_address_sk;
        memcpy(col_ca_address_id[i].data(), buf_ca_tpcds[i].ca_address_id.data, TPCDS_READ_MAX + 1);
        memcpy(col_ca_street_number[i].data(), buf_ca_tpcds[i].ca_street_number.data, TPCDS_READ_MAX + 1);
        memcpy(col_ca_street_name[i].data(), buf_ca_tpcds[i].ca_street_name.data, TPCDS_READ_MAX + 1);
        memcpy(col_ca_street_type[i].data(), buf_ca_tpcds[i].ca_street_type.data, TPCDS_READ_MAX + 1);
        memcpy(col_ca_suite_number[i].data(), buf_ca_tpcds[i].ca_suite_number.data, TPCDS_READ_MAX + 1);
        memcpy(col_ca_city[i].data(), buf_ca_tpcds[i].ca_city.data, TPCDS_READ_MAX + 1);
        memcpy(col_ca_county[i].data(), buf_ca_tpcds[i].ca_county.data, TPCDS_READ_MAX + 1);
        memcpy(col_ca_state[i].data(), buf_ca_tpcds[i].ca_state.data, TPCDS_READ_MAX + 1);
        memcpy(col_ca_zip[i].data(), buf_ca_tpcds[i].ca_zip.data, TPCDS_READ_MAX + 1);
        memcpy(col_ca_country[i].data(), buf_ca_tpcds[i].ca_country.data, TPCDS_READ_MAX + 1);
        col_ca_gmt_offset[i] = buf_ca_tpcds[i].ca_gmt_offset;
        memcpy(col_ca_location_type[i].data(), buf_ca_tpcds[i].ca_location_type.data, TPCDS_READ_MAX + 1);
    }
}

// ------------------------------------------------------------

// template <typename T, std::enable_if<std::is_integral<T>::value, int>::type = 0>
template <typename T>
int write_to_file(const std::string& fn, const std::vector<T>& d) {
    FILE* f = fopen(fn.c_str(), "wb");
    if (!f) {
        printf("ERROR: %s cannot be opened for write.\n", fn.c_str());
        return 1;
    }
    int n = fwrite(d.data(), sizeof(T), d.size(), f);
    fclose(f);
    return n;
}

template <int N>
int write_to_file(const std::string& fn, const std::vector<std::array<char, N> >& d) {
    FILE* f = fopen(fn.c_str(), "wb");
    if (!f) {
        printf("ERROR: %s cannot be opened for write.\n", fn.c_str());
        return 1;
    }
    int n = 0;
    for (int i = 0; i < d.size(); ++i) {
        n += fwrite(d[i].data(), N, 1, f);
    }
    fclose(f);
    return n;
}

int main(int argc, const char* argv[]) {
    // cmd arg parser.
    ArgParser parser(argc, argv);

    int err = 0;

    std::string in_dir = ".";
    parser.getCmdOption("-in", in_dir);
    if (!is_dir(in_dir)) {
        printf("ERROR: \"%s\" is not a directory!\n", in_dir.c_str());
        ++err;
    }

    std::string r_path = in_dir + "/region.tbl";
    if (!is_file(r_path)) {
        printf("ERROR: \"%s\" is not a file!\n", r_path.c_str());
        ++err;
    }
    std::string n_path = in_dir + "/nation.tbl";
    if (!is_file(n_path)) {
        printf("ERROR: \"%s\" is not a file!\n", n_path.c_str());
        ++err;
    }
    std::string c_path = in_dir + "/customer.tbl";
    if (!is_file(c_path)) {
        printf("ERROR: \"%s\" is not a file!\n", c_path.c_str());
        ++err;
    }
    std::string o_path = in_dir + "/orders.tbl";
    if (!is_file(o_path)) {
        printf("ERROR: \"%s\" is not a file!\n", o_path.c_str());
        ++err;
    }
    std::string l_path = in_dir + "/lineitem.tbl";
    if (!is_file(l_path)) {
        printf("ERROR: \"%s\" is not a file!\n", l_path.c_str());
        ++err;
    }
    std::string s_path = in_dir + "/supplier.tbl";
    if (!is_file(s_path)) {
        printf("ERROR: \"%s\" is not a file!\n", s_path.c_str());
        ++err;
    }
    std::string p_path = in_dir + "/part.tbl";
    if (!is_file(p_path)) {
        printf("ERROR: \"%s\" is not a file!\n", p_path.c_str());
        ++err;
    }
    std::string ps_path = in_dir + "/partsupp.tbl";
    if (!is_file(ps_path)) {
        printf("ERROR: \"%s\" is not a file!\n", ps_path.c_str());
        ++err;
    }

    std::string out_dir = ".";
    parser.getCmdOption("-out", out_dir);
    if (!is_dir(out_dir)) {
        printf("ERROR: \"%s\" is not a directory!\n", out_dir.c_str());
        ++err;
    }

    if (err) return err;

    // set up input data and buffers
    std::vector<region_t> r_vec;
    std::vector<nation_t> n_vec;
    std::vector<customer_t> c_vec;
    std::vector<orders_t> o_vec;
    std::vector<lineitem_t> l_vec;
    std::vector<supplier_t> s_vec;
    std::vector<part_t> p_vec;
    std::vector<partsupp_t> ps_vec;

    std::thread r_thread;
    std::thread n_thread;
    std::thread c_thread;
    std::thread o_thread;
    std::thread l_thread;
    std::thread s_thread;
    std::thread p_thread;
    std::thread ps_thread;

    struct timeval tv0, tv1;
    int usec;

    gettimeofday(&tv0, 0);

    // r_thread = std::thread(read_tbl<region_t>, r_path, std::ref(r_vec));
    // n_thread = std::thread(read_tbl<nation_t>, n_path, std::ref(n_vec));
    // c_thread = std::thread(read_tbl<customer_t>, c_path, std::ref(c_vec));
    // o_thread = std::thread(read_tbl<orders_t>, o_path, std::ref(o_vec));
    // l_thread = std::thread(read_tbl<lineitem_t>, l_path, std::ref(l_vec));
    // s_thread = std::thread(read_tbl<supplier_t>, s_path, std::ref(s_vec));
    // p_thread = std::thread(read_tbl<part_t>, p_path, std::ref(p_vec));
    ps_thread = std::thread(read_tbl<partsupp_t>, ps_path, std::ref(ps_vec));

    // r_thread.join();
    // n_thread.join();
    // c_thread.join();
    // o_thread.join();
    // l_thread.join();
    // s_thread.join();
    // p_thread.join();
    ps_thread.join();

    gettimeofday(&tv1, 0);
    usec = tvdiff(&tv0, &tv1);
    printf("Time to load table: %d usec.\n", usec);

    size_t r_nrow = r_vec.size();
    std::vector<TPCH_INT> col_r_regionkey(r_nrow);
    std::vector<std::array<char, TPCH_READ_REGION_LEN + 1> > col_r_name(r_nrow);
    std::vector<std::array<char, TPCH_READ_N_CMNT_MAX + 1> > col_r_comment(r_nrow);

    size_t n_nrow = n_vec.size();
    std::vector<TPCH_INT> col_n_nationkey(n_nrow);
    std::vector<TPCH_INT> col_n_regionkey(n_nrow);
    std::vector<std::array<char, TPCH_READ_NATION_LEN + 1> > col_n_name(n_nrow);
    std::vector<std::array<char, TPCH_READ_N_CMNT_MAX + 1> > col_n_comment(n_nrow);

    size_t c_nrow = c_vec.size();
    std::vector<TPCH_INT> col_c_custkey(c_nrow);
    std::vector<TPCH_INT> col_c_nationkey(c_nrow);
    std::vector<std::array<char, TPCH_READ_MAXAGG_LEN + 1> > col_c_mktsegment(c_nrow);
    std::vector<std::array<char, TPCH_READ_C_NAME_LEN + 1> > col_c_name(c_nrow);
    std::vector<TPCH_INT> col_c_acctbal(c_nrow);
    std::vector<std::array<char, TPCH_READ_S_ADDR_MAX + 1> > col_c_address(c_nrow);
    std::vector<std::array<char, TPCH_READ_PHONE_LEN + 1> > col_c_phone(c_nrow);
    std::vector<std::array<char, TPCH_READ_C_CMNT_MAX + 1> > col_c_comment(c_nrow);

    size_t o_nrow = o_vec.size();
    std::vector<TPCH_INT> col_o_orderkey(o_nrow);
    std::vector<TPCH_INT> col_o_custkey(o_nrow);
    std::vector<TPCH_INT> col_o_orderstatus(o_nrow);
    std::vector<TPCH_INT> col_o_totalprice(o_nrow);
    std::vector<TPCH_INT> col_o_orderdate(o_nrow);
    std::vector<std::array<char, TPCH_READ_MAXAGG_LEN + 1> > col_o_orderpriority(o_nrow);
    std::vector<std::array<char, TPCH_READ_O_CLRK_LEN + 1> > col_o_clerk(o_nrow);
    std::vector<TPCH_INT> col_o_shippriority(o_nrow);
    std::vector<std::array<char, TPCH_READ_O_CMNT_MAX + 1> > col_o_comment(o_nrow);

    size_t l_nrow = l_vec.size();
    std::vector<TPCH_INT> col_l_orderkey(l_nrow);
    std::vector<TPCH_INT> col_l_partkey(l_nrow);
    std::vector<TPCH_INT> col_l_suppkey(l_nrow);
    std::vector<TPCH_INT> col_l_linenumber(l_nrow);
    std::vector<TPCH_INT> col_l_quantity(l_nrow);
    std::vector<TPCH_INT> col_l_extendedprice(l_nrow);
    std::vector<TPCH_INT> col_l_discount(l_nrow);
    std::vector<TPCH_INT> col_l_tax(l_nrow);
    std::vector<TPCH_INT> col_l_returnflag(l_nrow);
    std::vector<TPCH_INT> col_l_linestatus(l_nrow);
    std::vector<TPCH_INT> col_l_shipdate(l_nrow);
    std::vector<TPCH_INT> col_l_commitdate(l_nrow);
    std::vector<TPCH_INT> col_l_receiptdate(l_nrow);
    std::vector<std::array<char, TPCH_READ_MAXAGG_LEN + 1> > col_l_shipinstruct(l_nrow);
    std::vector<std::array<char, TPCH_READ_MAXAGG_LEN + 1> > col_l_shipmode(l_nrow);
    std::vector<std::array<char, TPCH_READ_L_CMNT_MAX + 1> > col_l_comment(l_nrow);

    size_t s_nrow = s_vec.size();
    std::vector<TPCH_INT> col_s_suppkey(s_nrow);
    std::vector<std::array<char, TPCH_READ_S_NAME_LEN + 1> > col_s_name(s_nrow);
    std::vector<std::array<char, TPCH_READ_S_ADDR_MAX + 1> > col_s_address(s_nrow);
    std::vector<TPCH_INT> col_s_nationkey(s_nrow);
    std::vector<std::array<char, TPCH_READ_PHONE_LEN + 1> > col_s_phone(s_nrow);
    std::vector<TPCH_INT> col_s_acctbal(s_nrow);
    std::vector<std::array<char, TPCH_READ_S_CMNT_MAX + 1> > col_s_comment(s_nrow);

    size_t p_nrow = p_vec.size();
    std::vector<TPCH_INT> col_p_partkey(p_nrow);
    std::vector<std::array<char, TPCH_READ_P_NAME_LEN + 1> > col_p_name(p_nrow);
    std::vector<std::array<char, TPCH_READ_P_MFG_LEN + 1> > col_p_mfgr(p_nrow);
    std::vector<std::array<char, TPCH_READ_P_BRND_LEN + 1> > col_p_brand(p_nrow);
    std::vector<std::array<char, TPCH_READ_P_TYPE_LEN + 1> > col_p_type(p_nrow);
    std::vector<TPCH_INT> col_p_size(p_nrow);
    std::vector<std::array<char, TPCH_READ_P_CNTR_LEN + 1> > col_p_container(p_nrow);
    std::vector<TPCH_INT> col_p_retailprice(p_nrow);
    std::vector<std::array<char, TPCH_READ_P_CMNT_MAX + 1> > col_p_comment(p_nrow);

    size_t ps_nrow = ps_vec.size();
    std::vector<TPCH_INT> col_ps_partkey(ps_nrow);
    std::vector<TPCH_INT> col_ps_suppkey(ps_nrow);
    std::vector<TPCH_INT> col_ps_availqty(ps_nrow);
    std::vector<TPCH_INT> col_ps_supplycost(ps_nrow);
    std::vector<std::array<char, TPCH_READ_PS_CMNT_MAX + 1> > col_ps_comment(ps_nrow);

    // start timing and launch threads.
    // ************************************************************

    gettimeofday(&tv0, 0);

    r_thread = std::thread(columnize_r, r_vec.data(), r_nrow, col_r_regionkey.data(), std::ref(col_r_name),
                           std::ref(col_r_comment));

    n_thread = std::thread(columnize_n, n_vec.data(), n_nrow, col_n_nationkey.data(), col_n_regionkey.data(),
                           std::ref(col_n_name), std::ref(col_n_comment));

    c_thread = std::thread(columnize_c, c_vec.data(), c_nrow, col_c_custkey.data(), std::ref(col_c_name),
                           std::ref(col_c_address), col_c_nationkey.data(), std::ref(col_c_phone), col_c_acctbal.data(),
                           std::ref(col_c_mktsegment), std::ref(col_c_comment));

    o_thread = std::thread(columnize_o, o_vec.data(), o_nrow, col_o_orderkey.data(), col_o_custkey.data(),
                           col_o_orderstatus.data(), col_o_totalprice.data(), col_o_orderdate.data(),
                           std::ref(col_o_orderpriority), std::ref(col_o_clerk), col_o_shippriority.data(),
                           std::ref(col_o_comment));

    l_thread =
        std::thread(columnize_l, l_vec.data(), l_nrow, col_l_orderkey.data(), col_l_partkey.data(),
                    col_l_suppkey.data(), col_l_linenumber.data(), col_l_quantity.data(), col_l_extendedprice.data(),
                    col_l_discount.data(), col_l_tax.data(), col_l_returnflag.data(), col_l_linestatus.data(),
                    col_l_shipdate.data(), col_l_commitdate.data(), col_l_receiptdate.data(),
                    std::ref(col_l_shipinstruct), std::ref(col_l_shipmode), std::ref(col_l_comment));

    s_thread = std::thread(columnize_s, s_vec.data(), s_nrow, col_s_suppkey.data(), std::ref(col_s_name),
                           std::ref(col_s_address), col_s_nationkey.data(), std::ref(col_s_phone), col_s_acctbal.data(),
                           std::ref(col_s_comment));

    p_thread = std::thread(columnize_p, p_vec.data(), p_nrow, col_p_partkey.data(), std::ref(col_p_name),
                           std::ref(col_p_mfgr), std::ref(col_p_brand), std::ref(col_p_type), col_p_size.data(),
                           std::ref(col_p_container), col_p_retailprice.data(), std::ref(col_p_comment));

printf("ALEC PRINT: %lu\n", ps_vec.size());
    ps_thread = std::thread(columnize_ps, ps_vec.data(), ps_nrow, col_ps_partkey.data(), col_ps_suppkey.data(),
                            col_ps_availqty.data(), col_ps_supplycost.data(), std::ref(col_ps_comment));

    r_thread.join();
    n_thread.join();
    c_thread.join();
    o_thread.join();
    l_thread.join();
    s_thread.join();
    p_thread.join();
    ps_thread.join();

    //Alec-added TPC-DS START
    // Item table
    std::string i_path_tpcds = in_dir + "/item.tbl";
    if (!is_file(i_path_tpcds)) {
        printf("ERROR: \"%s\" is not a file!\n", i_path_tpcds.c_str());
        ++err;
    }
    std::vector<item_t> i_vec_tpcds;
    std::thread i_thread_tpcds;
    i_thread_tpcds = std::thread(read_tbl<item_t>, i_path_tpcds, std::ref(i_vec_tpcds));
    i_thread_tpcds.join();
    
    size_t i_nrow_tpcds = i_vec_tpcds.size();
    std::vector<TPCDS_INT> col_i_item_sk(i_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_i_item_id(i_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_i_rec_start_date(i_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_i_rec_end_date(i_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_i_item_desc(i_nrow_tpcds);
    std::vector<TPCDS_INT> col_i_current_price(i_nrow_tpcds);
    std::vector<TPCDS_INT> col_i_wholesale_cost(i_nrow_tpcds);
    std::vector<TPCDS_INT> col_i_brand_id(i_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_i_brand(i_nrow_tpcds);
    std::vector<TPCDS_INT> col_i_class_id(i_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_i_class(i_nrow_tpcds);
    std::vector<TPCDS_INT> col_i_category_id(i_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_i_category(i_nrow_tpcds);
    std::vector<TPCDS_INT> col_i_manufact_id(i_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_i_manufact(i_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_i_size(i_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_i_formulation(i_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_i_color(i_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_i_units(i_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_i_container(i_nrow_tpcds);
    std::vector<TPCDS_INT> col_i_manager_id(i_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_i_product_name(i_nrow_tpcds);

    printf("ALEC PRINT: %lu\n", i_vec_tpcds.size());

    i_thread_tpcds = std::thread(columnize_i_tpcds, i_vec_tpcds.data(), i_nrow_tpcds, 
                                col_i_item_sk.data(), std::ref(col_i_item_id), std::ref(col_i_rec_start_date), std::ref(col_i_rec_end_date), std::ref(col_i_item_desc), col_i_current_price.data(),
                                col_i_wholesale_cost.data(), col_i_brand_id.data(), std::ref(col_i_brand), col_i_class_id.data(), std::ref(col_i_class), col_i_category_id.data(), 
                                std::ref(col_i_category), col_i_manufact_id.data(), std::ref(col_i_manufact), std::ref(col_i_size), std::ref(col_i_formulation), std::ref(col_i_color), 
                                std::ref(col_i_units), std::ref(col_i_container), col_i_manager_id.data(), std::ref(col_i_product_name));
    i_thread_tpcds.join();

    write_to_file(out_dir + "/i_item_sk.dat", col_i_item_sk); 
    write_to_file(out_dir + "/i_item_id.dat", col_i_item_id); 
    write_to_file(out_dir + "/i_rec_start_date.dat", col_i_rec_start_date); 
    write_to_file(out_dir + "/i_rec_end_date.dat", col_i_rec_end_date); 
    write_to_file(out_dir + "/i_item_desc.dat", col_i_item_desc); 
    write_to_file(out_dir + "/i_current_price.dat", col_i_current_price); 
    write_to_file(out_dir + "/i_wholesale_cost.dat", col_i_wholesale_cost); 
    write_to_file(out_dir + "/i_brand_id.dat", col_i_brand_id); 
    write_to_file(out_dir + "/i_brand.dat", col_i_brand); 
    write_to_file(out_dir + "/i_class_id.dat", col_i_class_id); 
    write_to_file(out_dir + "/i_class.dat", col_i_class); 
    write_to_file(out_dir + "/i_category_id.dat", col_i_category_id); 
    write_to_file(out_dir + "/i_category.dat", col_i_category); 
    write_to_file(out_dir + "/i_manufact_id.dat", col_i_manufact_id); 
    write_to_file(out_dir + "/i_manufact.dat", col_i_manufact); 
    write_to_file(out_dir + "/i_size.dat", col_i_size); 
    write_to_file(out_dir + "/i_formulation.dat", col_i_formulation); 
    write_to_file(out_dir + "/i_color.dat", col_i_color); 
    write_to_file(out_dir + "/i_units.dat", col_i_units); 
    write_to_file(out_dir + "/i_container.dat", col_i_container); 
    write_to_file(out_dir + "/i_manager_id.dat", col_i_manager_id); 
    write_to_file(out_dir + "/i_product_name.dat", col_i_product_name); 

    // Store sales table
    std::string ss_path_tpcds = in_dir + "/store_sales.tbl";
    if (!is_file(ss_path_tpcds)) {
        printf("ERROR: \"%s\" is not a file!\n", ss_path_tpcds.c_str());
        ++err;
    }
    std::vector<store_sales_t> ss_vec_tpcds;
    std::thread ss_thread_tpcds;
    ss_thread_tpcds = std::thread(read_tbl<store_sales_t>, ss_path_tpcds, std::ref(ss_vec_tpcds));
    ss_thread_tpcds.join();
    
    size_t ss_nrow_tpcds = ss_vec_tpcds.size();

    std::vector<TPCDS_INT > col_ss_sold_date_sk(ss_nrow_tpcds);
    std::vector<TPCDS_INT > col_ss_sold_time_sk(ss_nrow_tpcds);
    std::vector<TPCDS_INT > col_ss_item_sk(ss_nrow_tpcds);
    std::vector<TPCDS_INT > col_ss_customer_sk(ss_nrow_tpcds);
    std::vector<TPCDS_INT > col_ss_cdemo_sk(ss_nrow_tpcds);
    std::vector<TPCDS_INT > col_ss_hdemo_sk(ss_nrow_tpcds);
    std::vector<TPCDS_INT > col_ss_addr_sk(ss_nrow_tpcds);
    std::vector<TPCDS_INT > col_ss_store_sk(ss_nrow_tpcds);
    std::vector<TPCDS_INT > col_ss_promo_sk(ss_nrow_tpcds);
    std::vector<TPCDS_INT > col_ss_ticket_number(ss_nrow_tpcds);
    std::vector<TPCDS_INT > col_ss_quantity(ss_nrow_tpcds);
    std::vector<TPCDS_INT > col_ss_wholesale_cost(ss_nrow_tpcds);
    std::vector<TPCDS_INT > col_ss_list_price(ss_nrow_tpcds);
    std::vector<TPCDS_INT > col_ss_sales_price(ss_nrow_tpcds);
    std::vector<TPCDS_INT > col_ss_ext_discount_amt(ss_nrow_tpcds);
    std::vector<TPCDS_INT > col_ss_ext_sales_price(ss_nrow_tpcds);
    std::vector<TPCDS_INT > col_ss_ext_wholesale_cost(ss_nrow_tpcds);
    std::vector<TPCDS_INT > col_ss_ext_list_price(ss_nrow_tpcds);
    std::vector<TPCDS_INT > col_ss_ext_tax(ss_nrow_tpcds);
    std::vector<TPCDS_INT > col_ss_coupon_amt(ss_nrow_tpcds);
    std::vector<TPCDS_INT > col_ss_net_paid(ss_nrow_tpcds);
    std::vector<TPCDS_INT > col_ss_net_paid_inc_tax(ss_nrow_tpcds);
    std::vector<TPCDS_INT > col_ss_net_profit(ss_nrow_tpcds);

    printf("ALEC PRINT: %lu\n", ss_vec_tpcds.size());

    ss_thread_tpcds = std::thread(columnize_ss_tpcds, ss_vec_tpcds.data(), ss_nrow_tpcds, 
                                col_ss_sold_date_sk.data(), col_ss_sold_time_sk.data(), col_ss_item_sk.data(), col_ss_customer_sk.data(), col_ss_cdemo_sk.data(), col_ss_hdemo_sk.data(), 
                                col_ss_addr_sk.data(), col_ss_store_sk.data(), col_ss_promo_sk.data(), col_ss_ticket_number.data(), col_ss_quantity.data(), col_ss_wholesale_cost.data(), 
                                col_ss_list_price.data(), col_ss_sales_price.data(), col_ss_ext_discount_amt.data(), col_ss_ext_sales_price.data(), col_ss_ext_wholesale_cost.data(), 
                                col_ss_ext_list_price.data(), col_ss_ext_tax.data(), col_ss_coupon_amt.data(), col_ss_net_paid.data(), col_ss_net_paid_inc_tax.data(), col_ss_net_profit.data());
    ss_thread_tpcds.join();

    write_to_file(out_dir + "/ss_sold_date_sk.dat", col_ss_sold_date_sk);
    write_to_file(out_dir + "/ss_sold_time_sk.dat", col_ss_sold_time_sk);
    write_to_file(out_dir + "/ss_item_sk.dat", col_ss_item_sk);
    write_to_file(out_dir + "/ss_customer_sk.dat", col_ss_customer_sk);
    write_to_file(out_dir + "/ss_cdemo_sk.dat", col_ss_cdemo_sk);
    write_to_file(out_dir + "/ss_hdemo_sk.dat", col_ss_hdemo_sk);
    write_to_file(out_dir + "/ss_addr_sk.dat", col_ss_addr_sk);
    write_to_file(out_dir + "/ss_store_sk.dat", col_ss_store_sk);
    write_to_file(out_dir + "/ss_promo_sk.dat", col_ss_promo_sk);
    write_to_file(out_dir + "/ss_ticket_number.dat", col_ss_ticket_number);
    write_to_file(out_dir + "/ss_quantity.dat", col_ss_quantity);
    write_to_file(out_dir + "/ss_wholesale_cost.dat", col_ss_wholesale_cost);
    write_to_file(out_dir + "/ss_list_price.dat", col_ss_list_price);
    write_to_file(out_dir + "/ss_sales_price.dat", col_ss_sales_price);
    write_to_file(out_dir + "/ss_ext_discount_amt.dat", col_ss_ext_discount_amt);
    write_to_file(out_dir + "/ss_ext_sales_price.dat", col_ss_ext_sales_price);
    write_to_file(out_dir + "/ss_ext_wholesale_cost.dat", col_ss_ext_wholesale_cost);
    write_to_file(out_dir + "/ss_ext_list_price.dat", col_ss_ext_list_price);
    write_to_file(out_dir + "/ss_ext_tax.dat", col_ss_ext_tax);
    write_to_file(out_dir + "/ss_coupon_amt.dat", col_ss_coupon_amt);
    write_to_file(out_dir + "/ss_net_paid.dat", col_ss_net_paid);
    write_to_file(out_dir + "/ss_net_paid_inc_tax.dat", col_ss_net_paid_inc_tax);
    write_to_file(out_dir + "/ss_net_profit.dat", col_ss_net_profit);

    // Date_dim table
    std::string d_path_tpcds = in_dir + "/date_dim.tbl";
    if (!is_file(d_path_tpcds)) {
        printf("ERROR: \"%s\" is not a file!\n", d_path_tpcds.c_str());
        ++err;
    }
    std::vector<date_dim_t> d_vec_tpcds;
    std::thread d_thread_tpcds;
    d_thread_tpcds = std::thread(read_tbl<date_dim_t>, d_path_tpcds, std::ref(d_vec_tpcds));
    d_thread_tpcds.join();
    
    size_t d_nrow_tpcds = d_vec_tpcds.size();

    std::vector<TPCDS_INT > col_d_date_sk(d_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_d_date_id(d_nrow_tpcds);
    std::vector<TPCDS_INT > col_d_date(d_nrow_tpcds);
    std::vector<TPCDS_INT > col_d_month_seq(d_nrow_tpcds);
    std::vector<TPCDS_INT > col_d_week_seq(d_nrow_tpcds);
    std::vector<TPCDS_INT > col_d_quarter_seq(d_nrow_tpcds);
    std::vector<TPCDS_INT > col_d_year(d_nrow_tpcds);
    std::vector<TPCDS_INT > col_d_dow(d_nrow_tpcds);
    std::vector<TPCDS_INT > col_d_moy(d_nrow_tpcds);
    std::vector<TPCDS_INT > col_d_dom(d_nrow_tpcds);
    std::vector<TPCDS_INT > col_d_qoy(d_nrow_tpcds);
    std::vector<TPCDS_INT > col_d_fy_year(d_nrow_tpcds);
    std::vector<TPCDS_INT > col_d_fy_quarter_seq(d_nrow_tpcds);
    std::vector<TPCDS_INT > col_d_fy_week_seq(d_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_d_day_name(d_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_d_quarter_name(d_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_d_holiday(d_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_d_weekend(d_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_d_following_holiday(d_nrow_tpcds);
    std::vector<TPCDS_INT > col_d_first_dom(d_nrow_tpcds);
    std::vector<TPCDS_INT > col_d_last_dom(d_nrow_tpcds);
    std::vector<TPCDS_INT > col_d_same_day_ly(d_nrow_tpcds);
    std::vector<TPCDS_INT > col_d_same_day_lq(d_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_d_current_day(d_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_d_current_week(d_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_d_current_month(d_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_d_current_quarter(d_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_d_current_year(d_nrow_tpcds);

    printf("ALEC PRINT: %lu\n", d_vec_tpcds.size());

    d_thread_tpcds = std::thread(columnize_d_tpcds, d_vec_tpcds.data(), d_nrow_tpcds, 
                                col_d_date_sk.data(), std::ref(col_d_date_id), col_d_date.data(), col_d_month_seq.data(), col_d_week_seq.data(), col_d_quarter_seq.data(), col_d_year.data(), 
                                col_d_dow.data(), col_d_moy.data(), col_d_dom.data(), col_d_qoy.data(), col_d_fy_year.data(), col_d_fy_quarter_seq.data(), col_d_fy_week_seq.data(), 
                                std::ref(col_d_day_name), std::ref(col_d_quarter_name), std::ref(col_d_holiday), std::ref(col_d_weekend), std::ref(col_d_following_holiday), col_d_first_dom.data(), 
                                col_d_last_dom.data(), col_d_same_day_ly.data(), col_d_same_day_lq.data(), std::ref(col_d_current_day), std::ref(col_d_current_week), std::ref(col_d_current_month), 
                                std::ref(col_d_current_quarter), std::ref(col_d_current_year));
    d_thread_tpcds.join();

    write_to_file(out_dir + "/d_date_sk.dat",  col_d_date_sk);
    write_to_file(out_dir + "/d_date_id.dat",  col_d_date_id);
    write_to_file(out_dir + "/d_date.dat",  col_d_date);
    write_to_file(out_dir + "/d_month_seq.dat",  col_d_month_seq);
    write_to_file(out_dir + "/d_week_seq.dat",  col_d_week_seq);
    write_to_file(out_dir + "/d_quarter_seq.dat",  col_d_quarter_seq);
    write_to_file(out_dir + "/d_year.dat",  col_d_year);
    write_to_file(out_dir + "/d_dow.dat",  col_d_dow);
    write_to_file(out_dir + "/d_moy.dat",  col_d_moy);
    write_to_file(out_dir + "/d_dom.dat",  col_d_dom);
    write_to_file(out_dir + "/d_qoy.dat",  col_d_qoy);
    write_to_file(out_dir + "/d_fy_year.dat",  col_d_fy_year);
    write_to_file(out_dir + "/d_fy_quarter_seq.dat",  col_d_fy_quarter_seq);
    write_to_file(out_dir + "/d_fy_week_seq.dat",  col_d_fy_week_seq);
    write_to_file(out_dir + "/d_day_name.dat",  col_d_day_name);
    write_to_file(out_dir + "/d_quarter_name.dat",  col_d_quarter_name);
    write_to_file(out_dir + "/d_holiday.dat",  col_d_holiday);
    write_to_file(out_dir + "/d_weekend.dat",  col_d_weekend);
    write_to_file(out_dir + "/d_following_holiday.dat",  col_d_following_holiday);
    write_to_file(out_dir + "/d_first_dom.dat",  col_d_first_dom);
    write_to_file(out_dir + "/d_last_dom.dat",  col_d_last_dom);
    write_to_file(out_dir + "/d_same_day_ly.dat",  col_d_same_day_ly);
    write_to_file(out_dir + "/d_same_day_lq.dat",  col_d_same_day_lq);
    write_to_file(out_dir + "/d_current_day.dat",  col_d_current_day);
    write_to_file(out_dir + "/d_current_week.dat",  col_d_current_week);
    write_to_file(out_dir + "/d_current_month.dat",  col_d_current_month);
    write_to_file(out_dir + "/d_current_quarter.dat",  col_d_current_quarter);
    write_to_file(out_dir + "/d_current_year.dat",  col_d_current_year);

    // customer_demographics_t table
// columnize_cd_tpcds
    std::string cd_path_tpcds = in_dir + "/customer_demographics.tbl";
    if (!is_file(cd_path_tpcds)) {
        printf("ERROR: \"%s\" is not a file!\n", cd_path_tpcds.c_str());
        ++err;
    }
    std::vector<customer_demographics_t> cd_vec_tpcds;
    std::thread cd_thread_tpcds;
    cd_thread_tpcds = std::thread(read_tbl<customer_demographics_t>, cd_path_tpcds, std::ref(cd_vec_tpcds));
    cd_thread_tpcds.join();
    
    size_t cd_nrow_tpcds = cd_vec_tpcds.size();

    std::vector<TPCDS_INT > col_cd_demo_sk(cd_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_cd_gender(cd_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_cd_marital_status(cd_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_cd_education_status(cd_nrow_tpcds);
    std::vector<TPCDS_INT > col_cd_purchase_estimate(cd_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_cd_credit_rating(cd_nrow_tpcds);
    std::vector<TPCDS_INT > col_cd_dep_count(cd_nrow_tpcds);
    std::vector<TPCDS_INT > col_cd_dep_employed_count(cd_nrow_tpcds);
    std::vector<TPCDS_INT > col_cd_dep_college_count(cd_nrow_tpcds);

    printf("ALEC PRINT: %lu\n", cd_vec_tpcds.size());

    cd_thread_tpcds = std::thread(columnize_cd_tpcds, cd_vec_tpcds.data(), cd_nrow_tpcds, 
                                col_cd_demo_sk.data(), std::ref(col_cd_gender), std::ref(col_cd_marital_status), 
                                std::ref(col_cd_education_status), col_cd_purchase_estimate.data(), std::ref(col_cd_credit_rating), 
                                col_cd_dep_count.data(), col_cd_dep_employed_count.data(), col_cd_dep_college_count.data());
    cd_thread_tpcds.join();

    write_to_file(out_dir + "/cd_demo_sk.dat", col_cd_demo_sk);
    write_to_file(out_dir + "/cd_gender.dat", col_cd_gender);
    write_to_file(out_dir + "/cd_marital_status.dat", col_cd_marital_status);
    write_to_file(out_dir + "/cd_education_status.dat", col_cd_education_status);
    write_to_file(out_dir + "/cd_purchase_estimate.dat", col_cd_purchase_estimate);
    write_to_file(out_dir + "/cd_credit_rating.dat", col_cd_credit_rating);
    write_to_file(out_dir + "/cd_dep_count.dat", col_cd_dep_count);
    write_to_file(out_dir + "/cd_dep_employed_count.dat", col_cd_dep_employed_count);
    write_to_file(out_dir + "/cd_dep_college_count.dat", col_cd_dep_college_count);

    // promotion_t table
// columnize_p_tpcds
    std::string p_path_tpcds = in_dir + "/promotion.tbl";
    if (!is_file(p_path_tpcds)) {
        printf("ERROR: \"%s\" is not a file!\n", p_path_tpcds.c_str());
        ++err;
    }
    std::vector<promotion_t> p_vec_tpcds;
    std::thread p_thread_tpcds;
    p_thread_tpcds = std::thread(read_tbl<promotion_t>, p_path_tpcds, std::ref(p_vec_tpcds));
    p_thread_tpcds.join();
    
    size_t p_nrow_tpcds = p_vec_tpcds.size();

    std::vector<TPCDS_INT > col_p_promo_sk(p_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_p_promo_id(p_nrow_tpcds); 
    std::vector<TPCDS_INT > col_p_start_date_sk(p_nrow_tpcds);
    std::vector<TPCDS_INT > col_p_end_date_sk(p_nrow_tpcds);
    std::vector<TPCDS_INT > col_p_item_sk(p_nrow_tpcds);
    std::vector<TPCDS_INT > col_p_cost(p_nrow_tpcds);
    std::vector<TPCDS_INT > col_p_response_target(p_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_p_promo_name(p_nrow_tpcds); 
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_p_channel_dmail(p_nrow_tpcds); 
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_p_channel_email(p_nrow_tpcds); 
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_p_channel_catalog(p_nrow_tpcds); 
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_p_channel_tv(p_nrow_tpcds); 
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_p_channel_radio(p_nrow_tpcds); 
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_p_channel_press(p_nrow_tpcds); 
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_p_channel_event(p_nrow_tpcds); 
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_p_channel_demo(p_nrow_tpcds); 
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_p_channel_details(p_nrow_tpcds); 
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_p_purpose(p_nrow_tpcds); 
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_p_discount_active(p_nrow_tpcds);

    printf("ALEC PRINT: %lu\n", p_vec_tpcds.size());

    p_thread_tpcds = std::thread(columnize_p_tpcds, p_vec_tpcds.data(), p_nrow_tpcds, 
                                col_p_promo_sk.data(), std::ref(col_p_promo_id), col_p_start_date_sk.data(), col_p_end_date_sk.data(), 
                                col_p_item_sk.data(), col_p_cost.data(), col_p_response_target.data(), std::ref(col_p_promo_name), 
                                std::ref(col_p_channel_dmail), std::ref(col_p_channel_email), std::ref(col_p_channel_catalog), std::ref(col_p_channel_tv), 
                                std::ref(col_p_channel_radio), std::ref(col_p_channel_press), std::ref(col_p_channel_event), std::ref(col_p_channel_demo), 
                                std::ref(col_p_channel_details), std::ref(col_p_purpose), std::ref(col_p_discount_active));
    
    p_thread_tpcds.join();

    write_to_file(out_dir + "/p_promo_sk.dat", col_p_promo_sk);
    write_to_file(out_dir + "/p_promo_id.dat", col_p_promo_id);
    write_to_file(out_dir + "/p_start_date_sk.dat", col_p_start_date_sk);
    write_to_file(out_dir + "/p_end_date_sk.dat", col_p_end_date_sk);
    write_to_file(out_dir + "/p_item_sk.dat", col_p_item_sk);
    write_to_file(out_dir + "/p_cost.dat", col_p_cost);
    write_to_file(out_dir + "/p_response_target.dat", col_p_response_target);
    write_to_file(out_dir + "/p_promo_name.dat", col_p_promo_name);
    write_to_file(out_dir + "/p_channel_dmail.dat", col_p_channel_dmail);
    write_to_file(out_dir + "/p_channel_email.dat", col_p_channel_email);
    write_to_file(out_dir + "/p_channel_catalog.dat", col_p_channel_catalog);
    write_to_file(out_dir + "/p_channel_tv.dat", col_p_channel_tv);
    write_to_file(out_dir + "/p_channel_radio.dat", col_p_channel_radio);
    write_to_file(out_dir + "/p_channel_press.dat", col_p_channel_press);
    write_to_file(out_dir + "/p_channel_event.dat", col_p_channel_event);
    write_to_file(out_dir + "/p_channel_demo.dat", col_p_channel_demo);
    write_to_file(out_dir + "/p_channel_details.dat", col_p_channel_details);
    write_to_file(out_dir + "/p_purpose.dat", col_p_purpose);
    write_to_file(out_dir + "/p_discount_active.dat", col_p_discount_active);

    // household_demographics_t table
// columnize_hd_tpcds
    std::string hd_path_tpcds = in_dir + "/household_demographics.tbl";
    if (!is_file(hd_path_tpcds)) {
        printf("ERROR: \"%s\" is not a file!\n", hd_path_tpcds.c_str());
        ++err;
    }
    std::vector<household_demographics_t> hd_vec_tpcds;
    std::thread hd_thread_tpcds;
    hd_thread_tpcds = std::thread(read_tbl<household_demographics_t>, hd_path_tpcds, std::ref(hd_vec_tpcds));
    hd_thread_tpcds.join();
    
    size_t hd_nrow_tpcds = hd_vec_tpcds.size();

    std::vector<TPCDS_INT > col_hd_demo_sk(hd_nrow_tpcds);
    std::vector<TPCDS_INT > col_hd_income_band_sk(hd_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_hd_buy_potential(hd_nrow_tpcds);
    std::vector<TPCDS_INT > col_hd_dep_count(hd_nrow_tpcds);
    std::vector<TPCDS_INT > col_hd_vehicle_count(hd_nrow_tpcds);

    printf("ALEC PRINT: %lu\n", hd_vec_tpcds.size());

    hd_thread_tpcds = std::thread(columnize_hd_tpcds, hd_vec_tpcds.data(), hd_nrow_tpcds, 
                                    col_hd_demo_sk.data(), col_hd_income_band_sk.data(), std::ref(col_hd_buy_potential), col_hd_dep_count.data(), col_hd_vehicle_count.data());

    hd_thread_tpcds.join();

    write_to_file(out_dir + "/hd_demo_sk.dat", col_hd_demo_sk);
    write_to_file(out_dir + "/hd_income_band_sk.dat", col_hd_income_band_sk);
    write_to_file(out_dir + "/hd_buy_potential.dat", col_hd_buy_potential);
    write_to_file(out_dir + "/hd_dep_count.dat", col_hd_dep_count);
    write_to_file(out_dir + "/hd_vehicle_count.dat", col_hd_vehicle_count);

    // time_dim_t table
// columnize_t_tpcds
    std::string t_path_tpcds = in_dir + "/time_dim.tbl";
    if (!is_file(t_path_tpcds)) {
        printf("ERROR: \"%s\" is not a file!\n", t_path_tpcds.c_str());
        ++err;
    }
    std::vector<time_dim_t> t_vec_tpcds;
    std::thread t_thread_tpcds;
    t_thread_tpcds = std::thread(read_tbl<time_dim_t>, t_path_tpcds, std::ref(t_vec_tpcds));
    t_thread_tpcds.join();
    
    size_t t_nrow_tpcds = t_vec_tpcds.size();

    std::vector<TPCDS_INT > col_t_time_sk(t_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_t_time_id(t_nrow_tpcds);
    std::vector<TPCDS_INT > col_t_time(t_nrow_tpcds);
    std::vector<TPCDS_INT > col_t_hour(t_nrow_tpcds);
    std::vector<TPCDS_INT > col_t_minute(t_nrow_tpcds);
    std::vector<TPCDS_INT > col_t_second(t_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_t_am_pm(t_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_t_shift(t_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_t_sub_shift(t_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_t_meal_time(t_nrow_tpcds);

    printf("ALEC PRINT: %lu\n", t_vec_tpcds.size());

    t_thread_tpcds = std::thread(columnize_t_tpcds, t_vec_tpcds.data(), t_nrow_tpcds,
                                    col_t_time_sk.data(), std::ref(col_t_time_id), col_t_time.data(), 
                                    col_t_hour.data(), col_t_minute.data(), col_t_second.data(), std::ref(col_t_am_pm), 
                                    std::ref(col_t_shift), std::ref(col_t_sub_shift), std::ref(col_t_meal_time));

    t_thread_tpcds.join();

    write_to_file(out_dir + "/t_time_sk.dat", col_t_time_sk);
    write_to_file(out_dir + "/t_time_id.dat", col_t_time_id);
    write_to_file(out_dir + "/t_time.dat", col_t_time);
    write_to_file(out_dir + "/t_hour.dat", col_t_hour);
    write_to_file(out_dir + "/t_minute.dat", col_t_minute);
    write_to_file(out_dir + "/t_second.dat", col_t_second);
    write_to_file(out_dir + "/t_am_pm.dat", col_t_am_pm);
    write_to_file(out_dir + "/t_shift.dat", col_t_shift);
    write_to_file(out_dir + "/t_sub_shift.dat", col_t_sub_shift);
    write_to_file(out_dir + "/t_meal_time.dat", col_t_meal_time);

    // store_t table
// columnize_s_tpcds
    std::string s_path_tpcds = in_dir + "/store.tbl";
    if (!is_file(s_path_tpcds)) {
        printf("ERROR: \"%s\" is not a file!\n", s_path_tpcds.c_str());
        ++err;
    }
    std::vector<store_t> s_vec_tpcds;
    std::thread s_thread_tpcds;
    s_thread_tpcds = std::thread(read_tbl<store_t>, s_path_tpcds, std::ref(s_vec_tpcds));
    s_thread_tpcds.join();
    
    size_t s_nrow_tpcds = s_vec_tpcds.size();

    std::vector<TPCDS_INT > col_s_store_sk(s_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_s_store_id(s_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_s_rec_start_date(s_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_s_rec_end_date(s_nrow_tpcds);
    std::vector<TPCDS_INT > col_s_closed_date_sk(s_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_s_store_name(s_nrow_tpcds);
    std::vector<TPCDS_INT > col_s_number_employees(s_nrow_tpcds);
    std::vector<TPCDS_INT > col_s_floor_space(s_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_s_hours(s_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_s_manager(s_nrow_tpcds);
    std::vector<TPCDS_INT > col_s_market_id(s_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_s_geography_class(s_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_s_market_desc(s_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_s_market_manager(s_nrow_tpcds);
    std::vector<TPCDS_INT > col_s_division_id(s_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_s_division_name(s_nrow_tpcds);
    std::vector<TPCDS_INT > col_s_company_id(s_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_s_company_name(s_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_s_street_number(s_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_s_street_name(s_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_s_street_type(s_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_s_suite_number(s_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_s_city(s_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_s_county(s_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_s_state(s_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_s_zip(s_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_s_country(s_nrow_tpcds);
    std::vector<TPCDS_INT > col_s_gmt_offset(s_nrow_tpcds);
    std::vector<TPCDS_INT > col_s_tax_precentage(s_nrow_tpcds);

    printf("ALEC PRINT: %lu\n", s_vec_tpcds.size());

    s_thread_tpcds = std::thread(columnize_s_tpcds, s_vec_tpcds.data(), s_nrow_tpcds,
                                col_s_store_sk.data(), std::ref(col_s_store_id), std::ref(col_s_rec_start_date), 
                                std::ref(col_s_rec_end_date), col_s_closed_date_sk.data(), std::ref(col_s_store_name), 
                                col_s_number_employees.data(), col_s_floor_space.data(), std::ref(col_s_hours), 
                                std::ref(col_s_manager), col_s_market_id.data(), std::ref(col_s_geography_class), 
                                std::ref(col_s_market_desc), std::ref(col_s_market_manager), col_s_division_id.data(), 
                                std::ref(col_s_division_name), col_s_company_id.data(), std::ref(col_s_company_name), 
                                std::ref(col_s_street_number), std::ref(col_s_street_name), std::ref(col_s_street_type), 
                                std::ref(col_s_suite_number), std::ref(col_s_city), std::ref(col_s_county), 
                                std::ref(col_s_state), std::ref(col_s_zip), std::ref(col_s_country), 
                                col_s_gmt_offset.data(), col_s_tax_precentage.data());

    s_thread_tpcds.join();

    write_to_file(out_dir + "/s_store_sk.dat", col_s_store_sk);
    write_to_file(out_dir + "/s_store_id.dat", col_s_store_id);
    write_to_file(out_dir + "/s_rec_start_date.dat", col_s_rec_start_date);
    write_to_file(out_dir + "/s_rec_end_date.dat", col_s_rec_end_date);
    write_to_file(out_dir + "/s_closed_date_sk.dat", col_s_closed_date_sk);
    write_to_file(out_dir + "/s_store_name.dat", col_s_store_name);
    write_to_file(out_dir + "/s_number_employees.dat", col_s_number_employees);
    write_to_file(out_dir + "/s_floor_space.dat", col_s_floor_space);
    write_to_file(out_dir + "/s_hours.dat", col_s_hours);
    write_to_file(out_dir + "/s_manager.dat", col_s_manager);
    write_to_file(out_dir + "/s_market_id.dat", col_s_market_id);
    write_to_file(out_dir + "/s_geography_class.dat", col_s_geography_class);
    write_to_file(out_dir + "/s_market_desc.dat", col_s_market_desc);
    write_to_file(out_dir + "/s_market_manager.dat", col_s_market_manager);
    write_to_file(out_dir + "/s_division_id.dat", col_s_division_id);
    write_to_file(out_dir + "/s_division_name.dat", col_s_division_name);
    write_to_file(out_dir + "/s_company_id.dat", col_s_company_id);
    write_to_file(out_dir + "/s_company_name.dat", col_s_company_name);
    write_to_file(out_dir + "/s_street_number.dat", col_s_street_number);
    write_to_file(out_dir + "/s_street_name.dat", col_s_street_name);
    write_to_file(out_dir + "/s_street_type.dat", col_s_street_type);
    write_to_file(out_dir + "/s_suite_number.dat", col_s_suite_number);
    write_to_file(out_dir + "/s_city.dat", col_s_city);
    write_to_file(out_dir + "/s_county.dat", col_s_county);
    write_to_file(out_dir + "/s_state.dat", col_s_state);
    write_to_file(out_dir + "/s_zip.dat", col_s_zip);
    write_to_file(out_dir + "/s_country.dat", col_s_country);
    write_to_file(out_dir + "/s_gmt_offset.dat", col_s_gmt_offset);
    write_to_file(out_dir + "/s_tax_precentage.dat", col_s_tax_precentage);

    // catalog_sales_t table
// columnize_cs_tpcds
    std::string cs_path_tpcds = in_dir + "/catalog_sales.tbl";
    if (!is_file(cs_path_tpcds)) {
        printf("ERROR: \"%s\" is not a file!\n", cs_path_tpcds.c_str());
        ++err;
    }
    std::vector<catalog_sales_t> cs_vec_tpcds;
    std::thread cs_thread_tpcds;
    cs_thread_tpcds = std::thread(read_tbl<catalog_sales_t>, cs_path_tpcds, std::ref(cs_vec_tpcds));
    cs_thread_tpcds.join();
    
    size_t cs_nrow_tpcds = cs_vec_tpcds.size();

    std::vector<TPCDS_INT > col_cs_sold_date_sk(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_sold_time_sk(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_ship_date_sk(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_bill_customer_sk(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_bill_cdemo_sk(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_bill_hdemo_sk(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_bill_addr_sk(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_ship_customer_sk(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_ship_cdemo_sk(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_ship_hdemo_sk(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_ship_addr_sk(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_call_center_sk(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_catalog_page_sk(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_ship_mode_sk(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_warehouse_sk(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_item_sk(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_promo_sk(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_order_number(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_quantity(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_wholesale_cost(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_list_price(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_sales_price(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_ext_discount_amt(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_ext_sales_price(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_ext_wholesale_cost(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_ext_list_price(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_ext_tax(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_coupon_amt(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_ext_ship_cost(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_net_paid(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_net_paid_inc_tax(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_net_paid_inc_ship(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_net_paid_inc_ship_tax(cs_nrow_tpcds);
    std::vector<TPCDS_INT > col_cs_net_profit(cs_nrow_tpcds);

    printf("ALEC PRINT: %lu\n", cs_vec_tpcds.size());

    cs_thread_tpcds = std::thread(columnize_cs_tpcds, cs_vec_tpcds.data(), cs_nrow_tpcds,
                                    col_cs_sold_date_sk.data(), col_cs_sold_time_sk.data(), col_cs_ship_date_sk.data(), col_cs_bill_customer_sk.data(), 
                                    col_cs_bill_cdemo_sk.data(), col_cs_bill_hdemo_sk.data(), col_cs_bill_addr_sk.data(), col_cs_ship_customer_sk.data(), 
                                    col_cs_ship_cdemo_sk.data(), col_cs_ship_hdemo_sk.data(), col_cs_ship_addr_sk.data(), col_cs_call_center_sk.data(), 
                                    col_cs_catalog_page_sk.data(), col_cs_ship_mode_sk.data(), col_cs_warehouse_sk.data(), col_cs_item_sk.data(), 
                                    col_cs_promo_sk.data(), col_cs_order_number.data(), col_cs_quantity.data(), col_cs_wholesale_cost.data(), 
                                    col_cs_list_price.data(), col_cs_sales_price.data(), col_cs_ext_discount_amt.data(), col_cs_ext_sales_price.data(), 
                                    col_cs_ext_wholesale_cost.data(), col_cs_ext_list_price.data(), col_cs_ext_tax.data(), col_cs_coupon_amt.data(), 
                                    col_cs_ext_ship_cost.data(), col_cs_net_paid.data(), col_cs_net_paid_inc_tax.data(), col_cs_net_paid_inc_ship.data(), 
                                    col_cs_net_paid_inc_ship_tax.data(), col_cs_net_profit.data());

    cs_thread_tpcds.join();

    write_to_file(out_dir + "/cs_sold_date_sk.dat", col_cs_sold_date_sk);
    write_to_file(out_dir + "/cs_sold_time_sk.dat", col_cs_sold_time_sk);
    write_to_file(out_dir + "/cs_ship_date_sk.dat", col_cs_ship_date_sk);
    write_to_file(out_dir + "/cs_bill_customer_sk.dat", col_cs_bill_customer_sk);
    write_to_file(out_dir + "/cs_bill_cdemo_sk.dat", col_cs_bill_cdemo_sk);
    write_to_file(out_dir + "/cs_bill_hdemo_sk.dat", col_cs_bill_hdemo_sk);
    write_to_file(out_dir + "/cs_bill_addr_sk.dat", col_cs_bill_addr_sk);
    write_to_file(out_dir + "/cs_ship_customer_sk.dat", col_cs_ship_customer_sk);
    write_to_file(out_dir + "/cs_ship_cdemo_sk.dat", col_cs_ship_cdemo_sk);
    write_to_file(out_dir + "/cs_ship_hdemo_sk.dat", col_cs_ship_hdemo_sk);
    write_to_file(out_dir + "/cs_ship_addr_sk.dat", col_cs_ship_addr_sk);
    write_to_file(out_dir + "/cs_call_center_sk.dat", col_cs_call_center_sk);
    write_to_file(out_dir + "/cs_catalog_page_sk.dat", col_cs_catalog_page_sk);
    write_to_file(out_dir + "/cs_ship_mode_sk.dat", col_cs_ship_mode_sk);
    write_to_file(out_dir + "/cs_warehouse_sk.dat", col_cs_warehouse_sk);
    write_to_file(out_dir + "/cs_item_sk.dat", col_cs_item_sk);
    write_to_file(out_dir + "/cs_promo_sk.dat", col_cs_promo_sk);
    write_to_file(out_dir + "/cs_order_number.dat", col_cs_order_number);
    write_to_file(out_dir + "/cs_quantity.dat", col_cs_quantity);
    write_to_file(out_dir + "/cs_wholesale_cost.dat", col_cs_wholesale_cost);
    write_to_file(out_dir + "/cs_list_price.dat", col_cs_list_price);
    write_to_file(out_dir + "/cs_sales_price.dat", col_cs_sales_price);
    write_to_file(out_dir + "/cs_ext_discount_amt.dat", col_cs_ext_discount_amt);
    write_to_file(out_dir + "/cs_ext_sales_price.dat", col_cs_ext_sales_price);
    write_to_file(out_dir + "/cs_ext_wholesale_cost.dat", col_cs_ext_wholesale_cost);
    write_to_file(out_dir + "/cs_ext_list_price.dat", col_cs_ext_list_price);
    write_to_file(out_dir + "/cs_ext_tax.dat", col_cs_ext_tax);
    write_to_file(out_dir + "/cs_coupon_amt.dat", col_cs_coupon_amt);
    write_to_file(out_dir + "/cs_ext_ship_cost.dat", col_cs_ext_ship_cost);
    write_to_file(out_dir + "/cs_net_paid.dat", col_cs_net_paid);
    write_to_file(out_dir + "/cs_net_paid_inc_tax.dat", col_cs_net_paid_inc_tax);
    write_to_file(out_dir + "/cs_net_paid_inc_ship.dat", col_cs_net_paid_inc_ship);
    write_to_file(out_dir + "/cs_net_paid_inc_ship_tax.dat", col_cs_net_paid_inc_ship_tax);
    write_to_file(out_dir + "/cs_net_profit.dat", col_cs_net_profit);
    
    // store_returns_t table
// columnize_sr_tpcds
    std::string sr_path_tpcds = in_dir + "/store_returns.tbl";
    if (!is_file(sr_path_tpcds)) {
        printf("ERROR: \"%s\" is not a file!\n", sr_path_tpcds.c_str());
        ++err;
    }
    std::vector<store_returns_t> sr_vec_tpcds;
    std::thread sr_thread_tpcds;
    sr_thread_tpcds = std::thread(read_tbl<store_returns_t>, sr_path_tpcds, std::ref(sr_vec_tpcds));
    sr_thread_tpcds.join();
    
    size_t sr_nrow_tpcds = sr_vec_tpcds.size();

    std::vector<TPCDS_INT > col_sr_returned_date_sk(sr_nrow_tpcds);
    std::vector<TPCDS_INT > col_sr_return_time_sk(sr_nrow_tpcds);
    std::vector<TPCDS_INT > col_sr_item_sk(sr_nrow_tpcds);
    std::vector<TPCDS_INT > col_sr_customer_sk(sr_nrow_tpcds);
    std::vector<TPCDS_INT > col_sr_cdemo_sk(sr_nrow_tpcds);
    std::vector<TPCDS_INT > col_sr_hdemo_sk(sr_nrow_tpcds);
    std::vector<TPCDS_INT > col_sr_addr_sk(sr_nrow_tpcds);
    std::vector<TPCDS_INT > col_sr_store_sk(sr_nrow_tpcds);
    std::vector<TPCDS_INT > col_sr_reason_sk(sr_nrow_tpcds);
    std::vector<TPCDS_INT > col_sr_ticket_number(sr_nrow_tpcds);
    std::vector<TPCDS_INT > col_sr_return_quantity(sr_nrow_tpcds);
    std::vector<TPCDS_INT > col_sr_return_amt(sr_nrow_tpcds);
    std::vector<TPCDS_INT > col_sr_return_tax(sr_nrow_tpcds);
    std::vector<TPCDS_INT > col_sr_return_amt_inc_tax(sr_nrow_tpcds);
    std::vector<TPCDS_INT > col_sr_fee(sr_nrow_tpcds);
    std::vector<TPCDS_INT > col_sr_return_ship_cost(sr_nrow_tpcds);
    std::vector<TPCDS_INT > col_sr_refunded_cash(sr_nrow_tpcds);
    std::vector<TPCDS_INT > col_sr_reversed_charge(sr_nrow_tpcds);
    std::vector<TPCDS_INT > col_sr_store_credit(sr_nrow_tpcds);
    std::vector<TPCDS_INT > col_sr_net_loss(sr_nrow_tpcds);

    printf("ALEC PRINT: %lu\n", sr_vec_tpcds.size());

    sr_thread_tpcds = std::thread(columnize_sr_tpcds, sr_vec_tpcds.data(), sr_nrow_tpcds,
                                    col_sr_returned_date_sk.data(), col_sr_return_time_sk.data(), col_sr_item_sk.data(), 
                                    col_sr_customer_sk.data(), col_sr_cdemo_sk.data(), col_sr_hdemo_sk.data(), 
                                    col_sr_addr_sk.data(), col_sr_store_sk.data(), col_sr_reason_sk.data(), 
                                    col_sr_ticket_number.data(), col_sr_return_quantity.data(), col_sr_return_amt.data(), 
                                    col_sr_return_tax.data(), col_sr_return_amt_inc_tax.data(), col_sr_fee.data(), 
                                    col_sr_return_ship_cost.data(), col_sr_refunded_cash.data(), col_sr_reversed_charge.data(), 
                                    col_sr_store_credit.data(), col_sr_net_loss.data());

    sr_thread_tpcds.join();

    write_to_file(out_dir + "/sr_returned_date_sk.dat", col_sr_returned_date_sk);
    write_to_file(out_dir + "/sr_return_time_sk.dat", col_sr_return_time_sk);
    write_to_file(out_dir + "/sr_item_sk.dat", col_sr_item_sk);
    write_to_file(out_dir + "/sr_customer_sk.dat", col_sr_customer_sk);
    write_to_file(out_dir + "/sr_cdemo_sk.dat", col_sr_cdemo_sk);
    write_to_file(out_dir + "/sr_hdemo_sk.dat", col_sr_hdemo_sk);
    write_to_file(out_dir + "/sr_addr_sk.dat", col_sr_addr_sk);
    write_to_file(out_dir + "/sr_store_sk.dat", col_sr_store_sk);
    write_to_file(out_dir + "/sr_reason_sk.dat", col_sr_reason_sk);
    write_to_file(out_dir + "/sr_ticket_number.dat", col_sr_ticket_number);
    write_to_file(out_dir + "/sr_return_quantity.dat", col_sr_return_quantity);
    write_to_file(out_dir + "/sr_return_amt.dat", col_sr_return_amt);
    write_to_file(out_dir + "/sr_return_tax.dat", col_sr_return_tax);
    write_to_file(out_dir + "/sr_return_amt_inc_tax.dat", col_sr_return_amt_inc_tax);
    write_to_file(out_dir + "/sr_fee.dat", col_sr_fee);
    write_to_file(out_dir + "/sr_return_ship_cost.dat", col_sr_return_ship_cost);
    write_to_file(out_dir + "/sr_refunded_cash.dat", col_sr_refunded_cash);
    write_to_file(out_dir + "/sr_reversed_charge.dat", col_sr_reversed_charge);
    write_to_file(out_dir + "/sr_store_credit.dat", col_sr_store_credit);
    write_to_file(out_dir + "/sr_net_loss.dat", col_sr_net_loss);

    // customer_tpcds_t table
// columnize_c_tpcds
    std::string c_path_tpcds = in_dir + "/customer.dat";
    if (!is_file(c_path_tpcds)) {
        printf("ERROR: \"%s\" is not a file!\n", c_path_tpcds.c_str());
        ++err;
    }
    std::vector<customer_tpcds_t> c_vec_tpcds;
    std::thread c_thread_tpcds;
    c_thread_tpcds = std::thread(read_tbl<customer_tpcds_t>, c_path_tpcds, std::ref(c_vec_tpcds));
    c_thread_tpcds.join();
    
    size_t c_nrow_tpcds = c_vec_tpcds.size();

    std::vector<TPCDS_INT > col_c_customer_sk(c_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_c_customer_id(c_nrow_tpcds);
    std::vector<TPCDS_INT > col_c_current_cdemo_sk(c_nrow_tpcds);
    std::vector<TPCDS_INT > col_c_current_hdemo_sk(c_nrow_tpcds);
    std::vector<TPCDS_INT > col_c_current_addr_sk(c_nrow_tpcds);
    std::vector<TPCDS_INT > col_c_first_shipto_date_sk(c_nrow_tpcds);
    std::vector<TPCDS_INT > col_c_first_sales_date_sk(c_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_c_salutation(c_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_c_first_name(c_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_c_last_name(c_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_c_preferred_cust_flag(c_nrow_tpcds);
    std::vector<TPCDS_INT > col_c_birth_day(c_nrow_tpcds);
    std::vector<TPCDS_INT > col_c_birth_month(c_nrow_tpcds);
    std::vector<TPCDS_INT > col_c_birth_year(c_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_c_birth_country(c_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_c_login(c_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_c_email_address(c_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_c_last_review_date(c_nrow_tpcds);

    printf("ALEC PRINT: %lu\n", c_vec_tpcds.size());

    c_thread_tpcds = std::thread(columnize_c_tpcds, c_vec_tpcds.data(), c_nrow_tpcds, 
                                col_c_customer_sk.data(), std::ref(col_c_customer_id), col_c_current_cdemo_sk.data(), 
                                col_c_current_hdemo_sk.data(), col_c_current_addr_sk.data(), col_c_first_shipto_date_sk.data(), 
                                col_c_first_sales_date_sk.data(), std::ref(col_c_salutation), std::ref(col_c_first_name), 
                                std::ref(col_c_last_name), std::ref(col_c_preferred_cust_flag), col_c_birth_day.data(), 
                                col_c_birth_month.data(), col_c_birth_year.data(), std::ref(col_c_birth_country), 
                                std::ref(col_c_login), std::ref(col_c_email_address), std::ref(col_c_last_review_date));

    c_thread_tpcds.join();

    write_to_file(out_dir + "/c_customer_sk.dat", col_c_customer_sk);
    write_to_file(out_dir + "/c_customer_id.dat", col_c_customer_id);
    write_to_file(out_dir + "/c_current_cdemo_sk.dat", col_c_current_cdemo_sk);
    write_to_file(out_dir + "/c_current_hdemo_sk.dat", col_c_current_hdemo_sk);
    write_to_file(out_dir + "/c_current_addr_sk.dat", col_c_current_addr_sk);
    write_to_file(out_dir + "/c_first_shipto_date_sk.dat", col_c_first_shipto_date_sk);
    write_to_file(out_dir + "/c_first_sales_date_sk.dat", col_c_first_sales_date_sk);
    write_to_file(out_dir + "/c_salutation.dat", col_c_salutation);
    write_to_file(out_dir + "/c_first_name.dat", col_c_first_name);
    write_to_file(out_dir + "/c_last_name.dat", col_c_last_name);
    write_to_file(out_dir + "/c_preferred_cust_flag.dat", col_c_preferred_cust_flag);
    write_to_file(out_dir + "/c_birth_day.dat", col_c_birth_day);
    write_to_file(out_dir + "/c_birth_month.dat", col_c_birth_month);
    write_to_file(out_dir + "/c_birth_year.dat", col_c_birth_year);
    write_to_file(out_dir + "/c_birth_country.dat", col_c_birth_country);
    write_to_file(out_dir + "/c_login.dat", col_c_login);
    write_to_file(out_dir + "/c_email_address.dat", col_c_email_address);
    write_to_file(out_dir + "/c_last_review_date.dat", col_c_last_review_date);

    // customer_address_t table
// columnize_ca_tpcds
    std::string ca_path_tpcds = in_dir + "/customer_address.dat";
    if (!is_file(ca_path_tpcds)) {
        printf("ERROR: \"%s\" is not a file!\n", ca_path_tpcds.c_str());
        ++err;
    }
    std::vector<customer_address_t> ca_vec_tpcds;
    std::thread ca_thread_tpcds;
    ca_thread_tpcds = std::thread(read_tbl<customer_address_t>, ca_path_tpcds, std::ref(ca_vec_tpcds));
    ca_thread_tpcds.join();
    
    size_t ca_nrow_tpcds = ca_vec_tpcds.size();

    std::vector<TPCDS_INT > col_ca_address_sk(ca_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_ca_address_id(ca_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_ca_street_number(ca_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_ca_street_name(ca_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_ca_street_type(ca_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_ca_suite_number(ca_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_ca_city(ca_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_ca_county(ca_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_ca_state(ca_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_ca_zip(ca_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_ca_country(ca_nrow_tpcds);
    std::vector<TPCDS_INT > col_ca_gmt_offset(ca_nrow_tpcds);
    std::vector<std::array<char, TPCDS_READ_MAX + 1> > col_ca_location_type(ca_nrow_tpcds);

    printf("ALEC PRINT: %lu\n", ca_vec_tpcds.size());

    ca_thread_tpcds = std::thread(columnize_ca_tpcds, ca_vec_tpcds.data(), ca_nrow_tpcds,
                                col_ca_address_sk.data(), std::ref(col_ca_address_id), std::ref(col_ca_street_number), 
                                std::ref(col_ca_street_name), std::ref(col_ca_street_type), std::ref(col_ca_suite_number), 
                                std::ref(col_ca_city), std::ref(col_ca_county), std::ref(col_ca_state), std::ref(col_ca_zip), 
                                std::ref(col_ca_country), col_ca_gmt_offset.data(), std::ref(col_ca_location_type));

    ca_thread_tpcds.join();

    write_to_file(out_dir + "/ca_address_sk.dat", col_ca_address_sk);
    write_to_file(out_dir + "/ca_address_id.dat", col_ca_address_id);
    write_to_file(out_dir + "/ca_street_number.dat", col_ca_street_number);
    write_to_file(out_dir + "/ca_street_name.dat", col_ca_street_name);
    write_to_file(out_dir + "/ca_street_type.dat", col_ca_street_type);
    write_to_file(out_dir + "/ca_suite_number.dat", col_ca_suite_number);
    write_to_file(out_dir + "/ca_city.dat", col_ca_city);
    write_to_file(out_dir + "/ca_county.dat", col_ca_county);
    write_to_file(out_dir + "/ca_state.dat", col_ca_state);
    write_to_file(out_dir + "/ca_zip.dat", col_ca_zip);
    write_to_file(out_dir + "/ca_country.dat", col_ca_country);
    write_to_file(out_dir + "/ca_gmt_offset.dat", col_ca_gmt_offset);
    write_to_file(out_dir + "/ca_location_type.dat", col_ca_location_type);
    //Alec-added TPC-DS END

    gettimeofday(&tv1, 0);
    usec = tvdiff(&tv0, &tv1);
    printf("Time to columnize tables: %d usec.\n", usec);

    // ************************************************************
    // done and write data to file.

    write_to_file(out_dir + "/r_regionkey.dat", col_r_regionkey);
    write_to_file(out_dir + "/r_name.dat", col_r_name);
    write_to_file(out_dir + "/r_comment.dat", col_r_comment);

    write_to_file(out_dir + "/n_nationkey.dat", col_n_nationkey);
    write_to_file(out_dir + "/n_regionkey.dat", col_n_regionkey);
    write_to_file(out_dir + "/n_name.dat", col_n_name);
    write_to_file(out_dir + "/n_comment.dat", col_n_comment);

    write_to_file(out_dir + "/c_custkey.dat", col_c_custkey);
    write_to_file(out_dir + "/c_name.dat", col_c_name);
    write_to_file(out_dir + "/c_address.dat", col_c_address);
    write_to_file(out_dir + "/c_nationkey.dat", col_c_nationkey);
    write_to_file(out_dir + "/c_phone.dat", col_c_phone);
    write_to_file(out_dir + "/c_acctbal.dat", col_c_acctbal);
    write_to_file(out_dir + "/c_mktsegment.dat", col_c_mktsegment);
    write_to_file(out_dir + "/c_comment.dat", col_c_comment);

    write_to_file(out_dir + "/o_orderkey.dat", col_o_orderkey);
    write_to_file(out_dir + "/o_custkey.dat", col_o_custkey);
    write_to_file(out_dir + "/o_orderstatus.dat", col_o_orderstatus);
    write_to_file(out_dir + "/o_totalprice.dat", col_o_totalprice);
    write_to_file(out_dir + "/o_orderdate.dat", col_o_orderdate);
    write_to_file(out_dir + "/o_orderpriority.dat", col_o_orderpriority);
    write_to_file(out_dir + "/o_clerk.dat", col_o_clerk);
    write_to_file(out_dir + "/o_shippriority.dat", col_o_shippriority);
    write_to_file(out_dir + "/o_comment.dat", col_o_comment);

    write_to_file(out_dir + "/l_orderkey.dat", col_l_orderkey);
    write_to_file(out_dir + "/l_partkey.dat", col_l_partkey);
    write_to_file(out_dir + "/l_suppkey.dat", col_l_suppkey);
    write_to_file(out_dir + "/l_linenumber.dat", col_l_linenumber);
    write_to_file(out_dir + "/l_quantity.dat", col_l_quantity);
    write_to_file(out_dir + "/l_extendedprice.dat", col_l_extendedprice);
    write_to_file(out_dir + "/l_discount.dat", col_l_discount);
    write_to_file(out_dir + "/l_tax.dat", col_l_tax);
    write_to_file(out_dir + "/l_returnflag.dat", col_l_returnflag);
    write_to_file(out_dir + "/l_linestatus.dat", col_l_linestatus);
    write_to_file(out_dir + "/l_shipdate.dat", col_l_shipdate);
    write_to_file(out_dir + "/l_commitdate.dat", col_l_commitdate);
    write_to_file(out_dir + "/l_receiptdate.dat", col_l_receiptdate);
    write_to_file(out_dir + "/l_shipinstruct.dat", col_l_shipinstruct);
    write_to_file(out_dir + "/l_shipmode.dat", col_l_shipmode);
    write_to_file(out_dir + "/l_comment.dat", col_l_comment);

    write_to_file(out_dir + "/s_suppkey.dat", col_s_suppkey);
    write_to_file(out_dir + "/s_name.dat", col_s_name);
    write_to_file(out_dir + "/s_address.dat", col_s_address);
    write_to_file(out_dir + "/s_nationkey.dat", col_s_nationkey);
    write_to_file(out_dir + "/s_phone.dat", col_s_phone);
    write_to_file(out_dir + "/s_acctbal.dat", col_s_acctbal);
    write_to_file(out_dir + "/s_comment.dat", col_s_comment);

    write_to_file(out_dir + "/p_partkey.dat", col_p_partkey);
    write_to_file(out_dir + "/p_name.dat", col_p_name);
    write_to_file(out_dir + "/p_mfgr.dat", col_p_mfgr);
    write_to_file(out_dir + "/p_brand.dat", col_p_brand);
    write_to_file(out_dir + "/p_type.dat", col_p_type);
    write_to_file(out_dir + "/p_size.dat", col_p_size);
    write_to_file(out_dir + "/p_container.dat", col_p_container);
    write_to_file(out_dir + "/p_retailprice.dat", col_p_retailprice);
    write_to_file(out_dir + "/p_comment.dat", col_p_comment);

    write_to_file(out_dir + "/ps_partkey.dat", col_ps_partkey);
    write_to_file(out_dir + "/ps_suppkey.dat", col_ps_suppkey);
    write_to_file(out_dir + "/ps_availqty.dat", col_ps_availqty);
    write_to_file(out_dir + "/ps_supplycost.dat", col_ps_supplycost);
    write_to_file(out_dir + "/ps_comment.dat", col_ps_comment);

    return 0;
}
