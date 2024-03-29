#!/bin/bash
gadmin stop -fy
gadmin start -fy
time gsql schema_xgraph.gsql
time gsql load_xgraph.gsql
time gsql base.gsql
time gsql query.gsql
time gsql -g xgraph "set query_timeout=240000000 run query cosinesim_ss_tg(\"$PWD/tg.txt\")"
time gsql -g xgraph "set query_timeout=240000000 run query loadgraph_cosinesim_ss_fpga()"
time gsql -g xgraph "set query_timeout=240000000 run query cosinesim_ss_fpga(\"$PWD/fpga1.txt\", \"$PWD/fpga2.txt\")"
time gsql -g xgraph "set query_timeout=240000000 run query close_fpga()"
