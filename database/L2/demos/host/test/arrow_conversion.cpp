#include "table_dt.hpp" 
#include "utils.hpp" 
#include "tpch_read_2.hpp" 
#include "tpcds_read.hpp" 
#include "gqe_api.hpp" 


int main(int argc, const char* argv[]) { 

    Table tbl_SerializeFromObject_TD_10543223_input;
    tbl_SerializeFromObject_TD_10543223_input = Table("warehouse", warehouse_n, 2, in_dir, "orc");
    tbl_SerializeFromObject_TD_10543223_input.addCol("w_warehouse_sk", 4);
    tbl_SerializeFromObject_TD_10543223_input.addCol("w_warehouse_name", TPCDS_READ_MAX+1);
    tbl_SerializeFromObject_TD_10543223_input.allocateHost();
    tbl_SerializeFromObject_TD_10543223_input.loadHost();
}