#
# Copyright 2019 Xilinx, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# -----------------------------------------------------------------------------
#                          project common settings

MK_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
CUR_DIR := $(patsubst %/,%,$(dir $(MK_PATH)))
CUR_DIR ?= $(CUR_DIR)
ORC_INSTALL_DIR := /localhdd/hza215/orc/ORC-1.9.0-SNAPSHOT-Linux
GCC_INSTALL_DIR := /localhdd/hza215/gcc-9.5.0/gcc-9.5.0/usr/local/lib64
ARROW_INCLUDE_DIR := /localhdd/hza215/bin/include
ARROW_INSTALL_DIR := /localhdd/hza215/bin/lib
.SECONDEXPANSION:

# -----------------------------------------------------------------------------
#                            common setup

.PHONY: help

help::
	@echo ""
	@echo "Makefile Usage:"
	@echo ""
	@echo "  make run TARGET=<sw_emu|hw_emu|hw>"
	@echo "      Command to build xclbin files to be used in demos"
	@echo ""
	@echo "  make run TARGET=<sw_emu|hw_emu|hw> TB=<Q1|Q2|...> MODE=<FPGA|CPU>"
	@echo "      Command to run a specific demo."
	@echo ""
	@echo "  make clean "
	@echo "      Command to remove the generated non-hardware files."
	@echo ""

# Target check
TARGET ?= sw_emu
ifeq ($(filter $(TARGET),sw_emu hw_emu hw),)
$(error TARGET is not sw_emu, hw_emu or hw)
endif

.PHONY: all
all: host

DEVICE ?= xilinx_u280_xdma_201920_3
ifneq ($(findstring u280, $(DEVICE)), u280)
$(error [ERROR]: This project is not supported for $(DEVICE).)
endif


HOST_ARCH := x86
include $(CUR_DIR)/utils.mk

XDEVICE := $(basename $(notdir $(firstword $(XPLATFORM))))

# -----------------------------------------------------------------------------
# data creation and other user targets

#DATA_STAMP := $(CUR_DIR)/db_data/dat$(SF)/.stamp
#$(DATA_STAMP):make -C $(CUR_DIR)/db_data

#.PHONY: data
#data: $(DATA_STAMP)

# -----------------------------------------------------------------------------
# kernel setup

# override the default and use a user provide path
XCLBIN_FILE_H = $(CUR_DIR)/build_join_partition/xclbin_$(XDEVICE)_$(TARGET)/gqe_join.xclbin
XCLBIN_FILE_A = $(CUR_DIR)/build_aggr_partition/xclbin_$(XDEVICE)_$(TARGET)/gqe_aggr.xclbin

$(XCLBIN_FILE_H):
	make -C $(CUR_DIR)/build_join_partition xclbin
$(XCLBIN_FILE_A):
	make -C $(CUR_DIR)/build_aggr_partition xclbin

xclbin: $(XCLBIN_FILE_A) $(XCLBIN_FILE_H) 

# -----------------------------------------------------------------------------
# host setup

XFLIB_DIR = $(abspath $(CUR_DIR)/../..)
SRC_BASE_DIR = $(XFLIB_DIR)/L2/demos/host

MODE ?= FPGA
SF ?= 1
TEST ?= XILINX

ifeq ($(MODE),CPU)
  # TB_DIR = cpu
  ifeq ($(TEST),XILINX)
    TB_DIR = cpu
  else ifeq ($(TEST),SQL2FPGA)
    TB_DIR = sfsql2fpga_cpu
  endif
else ifeq ($(MODE),FPGA)
ifeq ($(SF),1)
  ifeq ($(TEST),XILINX)
    TB_DIR = sf1_fpga
  else ifeq ($(TEST),SQL2FPGA)
    TB_DIR = sf1_sql2fpga_fpga
  endif
else ifeq ($(SF),30)
  ifeq ($(TEST),XILINX)
    # TB_DIR = sf1_fpga
    TB_DIR = sf30_fpga
  else ifeq ($(TEST),SQL2FPGA)
    TB_DIR = sfsql2fpga_fpga
  endif
else
  $(error Scale factor other than 1 and 30 is not supported in host code)
endif # SF
else
  $(error Please set MODE as either 'fpga' or 'cpu')
endif # MODE

TB ?= Q1
DATAPATH = /localhdd/hza215/spark_benchmark/tpcds/orc
HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH)  -c $(SF) -b 0

ifeq ($(TB),Q1)
  EXE_NAME = test_q1_$(MODE)_$(SF)
  SRCS = test_q1.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q01/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_A) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH)  -c $(SF) -p 22 -b 0
else ifeq ($(TB),Q2)
  EXE_NAME = test_q2_$(MODE)_$(SF)
  SRCS = test_q2.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q02/$(TB_DIR)
else ifeq ($(TB),Q3)
  EXE_NAME = test_q3_$(MODE)_$(SF)
  SRCS = test_q3.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q03/$(TB_DIR)
else ifeq ($(TB),Qop)
  EXE_NAME = test_qop_$(MODE)_$(SF)
  SRCS = test_qop.cpp
  SRC_DIR = $(SRC_BASE_DIR)/qop/$(TB_DIR)  
else ifeq ($(TB),Q4)
  EXE_NAME = test_q4_$(MODE)_$(SF)
  SRCS = test_q4.cpp
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH)  -c $(SF) -p 22 -b 0
  SRC_DIR = $(SRC_BASE_DIR)/q04/$(TB_DIR)
else ifeq ($(TB),Q5)
  EXE_NAME = test_q5_$(MODE)_$(SF)
  SRCS = test_q5.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q05/$(TB_DIR)
else ifeq ($(TB),Q6)
  EXE_NAME = test_q6_$(MODE)_$(SF)
  SRCS = test_q6.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q06/$(TB_DIR)
else ifeq ($(TB),Q7)
  EXE_NAME = test_q7_$(MODE)_$(SF)
  SRCS = test_q7.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q07/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH)  -c $(SF) -b 0 -p 8
else ifeq ($(TB),Q8)
  EXE_NAME = test_q8_$(MODE)_$(SF)
  SRCS = test_q8.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q08/$(TB_DIR)
else ifeq ($(TB),Q9)
  EXE_NAME = test_q9_$(MODE)_$(SF)
  SRCS = test_q9.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q09/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH)  -c $(SF) -b 0 -p 32
else ifeq ($(TB),Q10)
  EXE_NAME = test_q10_$(MODE)_$(SF)
  SRCS = test_q10.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q10/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH)  -c $(SF)
else ifeq ($(TB),Q11)
  EXE_NAME = test_q11_$(MODE)_$(SF)
  SRCS = test_q11.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q11/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH)  -c $(SF)
else ifeq ($(TB),Q12)
  EXE_NAME = test_q12_$(MODE)_$(SF)
  SRCS = test_q12.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q12/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH)  -c $(SF) -b 0 -p 23
else ifeq ($(TB),Q13)
  EXE_NAME = test_q13_$(MODE)_$(SF)
  SRCS = test_q13.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q13/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_A) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH)  -c $(SF) -pa 18 -ph 32
else ifeq ($(TB),Q14)
  EXE_NAME = test_q14_$(MODE)_$(SF)
  SRCS = test_q14.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q14/$(TB_DIR)
else ifeq ($(TB),Q15)
  EXE_NAME = test_q15_$(MODE)_$(SF)
  SRCS = test_q15.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q15/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_A) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH)  -c $(SF) -p 22 -b 0
else ifeq ($(TB),Q16)
  EXE_NAME = test_q16_$(MODE)_$(SF)
  SRCS = test_q16.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q16/$(TB_DIR)
else ifeq ($(TB),Q17)
  EXE_NAME = test_q17_$(MODE)_$(SF)
  SRCS = test_q17.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q17/$(TB_DIR)
else ifeq ($(TB),Q18)
  EXE_NAME = test_q18_$(MODE)_$(SF)
  SRCS = test_q18.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q18/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH)  -c $(SF) -p 20
else ifeq ($(TB),Q19)
  EXE_NAME = test_q19_$(MODE)_$(SF)
  SRCS = test_q19.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q19/$(TB_DIR)
else ifeq ($(TB),Q20)
  EXE_NAME = test_q20_$(MODE)_$(SF)
  SRCS = test_q20.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q20/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 22
else ifeq ($(TB),Q21)
  EXE_NAME = test_q21_$(MODE)_$(SF)
  SRCS = test_q21.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q21/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH)  -c $(SF) -p 64
else ifeq ($(TB),Q22)
  EXE_NAME = test_q22_$(MODE)_$(SF)
  SRCS = test_q22.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q22/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH)  -c $(SF) -p 16
else ifeq ($(TB),Q23)
  EXE_NAME = test_q23_$(MODE)_$(SF)
  SRCS = test_q23.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q23/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH)  -c $(SF) -p 16  
else ifeq ($(TB),Q24)
  EXE_NAME = test_q24_$(MODE)_$(SF)
  SRCS = test_q24.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q24/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q25)
  EXE_NAME = test_q25_$(MODE)_$(SF)
  SRCS = test_q25.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q25/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q26)
  EXE_NAME = test_q26_$(MODE)_$(SF)
  SRCS = test_q26.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q26/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q27)
  EXE_NAME = test_q27_$(MODE)_$(SF)
  SRCS = test_q27.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q27/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q28)
  EXE_NAME = test_q28_$(MODE)_$(SF)
  SRCS = test_q28.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q28/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q29)
  EXE_NAME = test_q29_$(MODE)_$(SF)
  SRCS = test_q29.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q29/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q30)
  EXE_NAME = test_q30_$(MODE)_$(SF)
  SRCS = test_q30.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q30/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q31)
  EXE_NAME = test_q31_$(MODE)_$(SF)
  SRCS = test_q31.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q31/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q32)
  EXE_NAME = test_q32_$(MODE)_$(SF)
  SRCS = test_q32.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q32/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q33)
  EXE_NAME = test_q33_$(MODE)_$(SF)
  SRCS = test_q33.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q33/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q34)
  EXE_NAME = test_q34_$(MODE)_$(SF)
  SRCS = test_q34.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q34/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q35)
  EXE_NAME = test_q35_$(MODE)_$(SF)
  SRCS = test_q35.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q35/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q36)
  EXE_NAME = test_q36_$(MODE)_$(SF)
  SRCS = test_q36.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q36/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q37)
  EXE_NAME = test_q37_$(MODE)_$(SF)
  SRCS = test_q37.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q37/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q38)
  EXE_NAME = test_q38_$(MODE)_$(SF)
  SRCS = test_q38.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q38/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q39)
  EXE_NAME = test_q39_$(MODE)_$(SF)
  SRCS = test_q39.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q39/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q40)
  EXE_NAME = test_q40_$(MODE)_$(SF)
  SRCS = test_q40.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q40/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q41)
  EXE_NAME = test_q41_$(MODE)_$(SF)
  SRCS = test_q41.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q41/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q42)
  EXE_NAME = test_q42_$(MODE)_$(SF)
  SRCS = test_q42.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q42/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q43)
  EXE_NAME = test_q43_$(MODE)_$(SF)
  SRCS = test_q43.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q43/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q44)
  EXE_NAME = test_q44_$(MODE)_$(SF)
  SRCS = test_q44.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q44/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q45)
  EXE_NAME = test_q45_$(MODE)_$(SF)
  SRCS = test_q45.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q45/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q46)
  EXE_NAME = test_q46_$(MODE)_$(SF)
  SRCS = test_q46.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q46/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q47)
  EXE_NAME = test_q47_$(MODE)_$(SF)
  SRCS = test_q47.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q47/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q48)
  EXE_NAME = test_q48_$(MODE)_$(SF)
  SRCS = test_q48.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q48/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q49)
  EXE_NAME = test_q49_$(MODE)_$(SF)
  SRCS = test_q49.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q49/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q50)
  EXE_NAME = test_q50_$(MODE)_$(SF)
  SRCS = test_q50.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q50/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q51)
  EXE_NAME = test_q51_$(MODE)_$(SF)
  SRCS = test_q51.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q51/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q52)
  EXE_NAME = test_q52_$(MODE)_$(SF)
  SRCS = test_q52.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q52/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q53)
  EXE_NAME = test_q53_$(MODE)_$(SF)
  SRCS = test_q53.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q53/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q54)
  EXE_NAME = test_q54_$(MODE)_$(SF)
  SRCS = test_q54.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q54/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q55)
  EXE_NAME = test_q55_$(MODE)_$(SF)
  SRCS = test_q55.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q55/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q56)
  EXE_NAME = test_q56_$(MODE)_$(SF)
  SRCS = test_q56.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q56/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q57)
  EXE_NAME = test_q57_$(MODE)_$(SF)
  SRCS = test_q57.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q57/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q58)
  EXE_NAME = test_q58_$(MODE)_$(SF)
  SRCS = test_q58.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q58/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q59)
  EXE_NAME = test_q59_$(MODE)_$(SF)
  SRCS = test_q59.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q59/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q60)
  EXE_NAME = test_q60_$(MODE)_$(SF)
  SRCS = test_q60.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q60/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q61)
  EXE_NAME = test_q61_$(MODE)_$(SF)
  SRCS = test_q61.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q61/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q62)
  EXE_NAME = test_q62_$(MODE)_$(SF)
  SRCS = test_q62.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q62/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q63)
  EXE_NAME = test_q63_$(MODE)_$(SF)
  SRCS = test_q63.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q63/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q64)
  EXE_NAME = test_q64_$(MODE)_$(SF)
  SRCS = test_q64.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q64/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q65)
  EXE_NAME = test_q65_$(MODE)_$(SF)
  SRCS = test_q65.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q65/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q66)
  EXE_NAME = test_q66_$(MODE)_$(SF)
  SRCS = test_q66.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q66/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q67)
  EXE_NAME = test_q67_$(MODE)_$(SF)
  SRCS = test_q67.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q67/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q68)
  EXE_NAME = test_q68_$(MODE)_$(SF)
  SRCS = test_q68.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q68/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q69)
  EXE_NAME = test_q69_$(MODE)_$(SF)
  SRCS = test_q69.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q69/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q70)
  EXE_NAME = test_q70_$(MODE)_$(SF)
  SRCS = test_q70.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q70/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q71)
  EXE_NAME = test_q71_$(MODE)_$(SF)
  SRCS = test_q71.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q71/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q72)
  EXE_NAME = test_q72_$(MODE)_$(SF)
  SRCS = test_q72.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q72/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q73)
  EXE_NAME = test_q73_$(MODE)_$(SF)
  SRCS = test_q73.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q73/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q74)
  EXE_NAME = test_q74_$(MODE)_$(SF)
  SRCS = test_q74.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q74/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q75)
  EXE_NAME = test_q75_$(MODE)_$(SF)
  SRCS = test_q75.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q75/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q76)
  EXE_NAME = test_q76_$(MODE)_$(SF)
  SRCS = test_q76.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q76/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q77)
  EXE_NAME = test_q77_$(MODE)_$(SF)
  SRCS = test_q77.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q77/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q78)
  EXE_NAME = test_q78_$(MODE)_$(SF)
  SRCS = test_q78.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q78/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q79)
  EXE_NAME = test_q79_$(MODE)_$(SF)
  SRCS = test_q79.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q79/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q80)
  EXE_NAME = test_q80_$(MODE)_$(SF)
  SRCS = test_q80.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q80/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q81)
  EXE_NAME = test_q81_$(MODE)_$(SF)
  SRCS = test_q81.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q81/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q82)
  EXE_NAME = test_q82_$(MODE)_$(SF)
  SRCS = test_q82.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q82/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q83)
  EXE_NAME = test_q83_$(MODE)_$(SF)
  SRCS = test_q83.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q83/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q84)
  EXE_NAME = test_q84_$(MODE)_$(SF)
  SRCS = test_q84.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q84/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q85)
  EXE_NAME = test_q85_$(MODE)_$(SF)
  SRCS = test_q85.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q85/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q86)
  EXE_NAME = test_q86_$(MODE)_$(SF)
  SRCS = test_q86.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q86/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q87)
  EXE_NAME = test_q87_$(MODE)_$(SF)
  SRCS = test_q87.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q87/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q88)
  EXE_NAME = test_q88_$(MODE)_$(SF)
  SRCS = test_q88.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q88/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q89)
  EXE_NAME = test_q89_$(MODE)_$(SF)
  SRCS = test_q89.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q89/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q90)
  EXE_NAME = test_q90_$(MODE)_$(SF)
  SRCS = test_q90.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q90/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q91)
  EXE_NAME = test_q91_$(MODE)_$(SF)
  SRCS = test_q91.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q91/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q92)
  EXE_NAME = test_q92_$(MODE)_$(SF)
  SRCS = test_q92.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q92/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q93)
  EXE_NAME = test_q93_$(MODE)_$(SF)
  SRCS = test_q93.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q93/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q94)
  EXE_NAME = test_q94_$(MODE)_$(SF)
  SRCS = test_q94.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q94/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q95)
  EXE_NAME = test_q95_$(MODE)_$(SF)
  SRCS = test_q95.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q95/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q96)
  EXE_NAME = test_q96_$(MODE)_$(SF)
  SRCS = test_q96.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q96/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q97)
  EXE_NAME = test_q97_$(MODE)_$(SF)
  SRCS = test_q97.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q97/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q98)
  EXE_NAME = test_q98_$(MODE)_$(SF)
  SRCS = test_q98.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q98/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
else ifeq ($(TB),Q99)
  EXE_NAME = test_q99_$(MODE)_$(SF)
  SRCS = test_q99.cpp
  SRC_DIR = $(SRC_BASE_DIR)/q99/$(TB_DIR)
  HOST_ARGS = -xclbin $(XCLBIN_FILE_H) -xclbin_a $(XCLBIN_FILE_A) -xclbin_h $(XCLBIN_FILE_H) -in $(DATAPATH) -c $(SF) -p 16
endif

test_q1_EXTRA_HDRS += $(SRC_DIR)/q1.hpp

test_q2_EXTRA_HDRS += $(SRC_DIR)/q2.hpp

test_q3_EXTRA_HDRS += $(SRC_DIR)/q3.hpp

test_q4_EXTRA_HDRS += $(SRC_DIR)/q4.hpp

test_q5_EXTRA_HDRS += $(SRC_DIR)/q5.hpp

test_q6_EXTRA_HDRS += $(SRC_DIR)/q6.hpp

test_q7_EXTRA_HDRS += $(SRC_DIR)/q7.hpp

test_q8_EXTRA_HDRS += $(SRC_DIR)/q8.hpp

test_q9_EXTRA_HDRS += $(SRC_DIR)/q9.hpp

test_q10_EXTRA_HDRS += $(SRC_DIR)/q10.hpp

test_q11_EXTRA_HDRS += $(SRC_DIR)/q11.hpp

test_q12_EXTRA_HDRS += $(SRC_DIR)/q12.hpp

test_q13_EXTRA_HDRS += $(SRC_DIR)/q13.hpp

test_q14_EXTRA_HDRS += $(SRC_DIR)/q14.hpp

test_q15_EXTRA_HDRS += $(SRC_DIR)/q15.hpp

test_q16_EXTRA_HDRS += $(SRC_DIR)/q16.hpp

test_q17_EXTRA_HDRS += $(SRC_DIR)/q17.hpp

test_q18_EXTRA_HDRS += $(SRC_DIR)/q18.hpp

test_q19_EXTRA_HDRS += $(SRC_DIR)/q19.hpp

test_q20_EXTRA_HDRS += $(SRC_DIR)/q20.hpp

test_q21_EXTRA_HDRS += $(SRC_DIR)/q21.hpp

test_q22_EXTRA_HDRS += $(SRC_DIR)/q22.hpp

test_q23_EXTRA_HDRS += $(SRC_DIR)/q23.hpp

CXXFLAGS += -D XDEVICE=$(XDEVICE) -I$(XFLIB_DIR)/L1/include/hw -I$(XFLIB_DIR)/L3/include/sw -I$(JNI_INCLUDE) -I$(JNI_INCLUDE)/linux/ -I$(SRC_BASE_DIR) -g 
CXXFLAGS += -I$(ORC_INSTALL_DIR)/include
CXXFLAGS += -I$(ARROW_INCLUDE_DIR)
# EXTRA_OBJS is cannot be compiled from SRC_DIR, user should provide the rule
EXTRA_OBJS += xcl2

EXT_DIR = $(XFLIB_DIR)/ext
xcl2_SRCS = $(EXT_DIR)/xcl2/xcl2.cpp
xcl2_HDRS = $(EXT_DIR)/xcl2/xcl2.hpp
xcl2_CXXFLAGS = -I$(EXT_DIR)/xcl2
CXXFLAGS += $(xcl2_CXXFLAGS)


.PHONY: debugvar
debugvar:
	@echo $(EXE_NAME)
	@echo $(EXE_FILE)

BIN_DIR_SUFFIX := _$(MODE)_$(SF)_$(XDEVICE)

# -----------------------------------------------------------------------------

# MK_INC_BEGIN vitis_host_rules.mk

OBJ_DIR_BASE ?= obj
BIN_DIR_BASE ?= bin

BIN_DIR_SUFFIX ?= _$(XDEVICE)

OBJ_DIR = $(CUR_DIR)/$(OBJ_DIR_BASE)$(BIN_DIR_SUFFIX)
BIN_DIR = $(CUR_DIR)/$(BIN_DIR_BASE)$(BIN_DIR_SUFFIX)

CXXFLAGS += -std=c++17 -O2 -g -w -fPIC \
	-I$(SRC_DIR) -I$(XILINX_XRT)/include -I$(XILINX_VIVADO)/include \
	-Wall -Wno-unknown-pragmas -Wno-unused-label -pthread
# CFLAGS +=
LDFLAGS += -pthread -L$(XILINX_XRT)/lib -lxilinxopencl
LDFLAGS += -L$(XILINX_VIVADO)/lnx64/tools/fpo_v7_0 -Wl,--as-needed -lgmp -lmpfr \
	   -lIp_floating_point_v7_0_bitacc_cmodel
#LDFLAGS += -L$(GCC_INSTALL_DIR) -Wl,-rpath=$(GCC_INSTALL_DIR)
LDFLAGS += -L$(ORC_INSTALL_DIR)/lib -lorc -lprotobuf -lsnappy -lz -llz4 -lzstd
LDFLAGS += -L$(ARROW_INSTALL_DIR) -larrow
OBJ_FILES = $(foreach s,$(SRCS),$(OBJ_DIR)/$(basename $(s)).o)

define host_hdr_dep
$(1)_HDRS := $$(wildcard $(SRC_DIR)/$(1).h $(SRC_DIR)/$(1).hpp)
$(1)_HDRS += $$($(1)_EXTRA_HDRS)
endef

$(foreach s,$(SRCS),$(eval $(call host_hdr_dep,$(basename $(s)))))

$(OBJ_DIR)/%.o: CXXFLAGS += $($(*)_CXXFLAGS)

$(OBJ_FILES): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $$($$(*)_HDRS) | check_vpp check_xrt check_platform
	@echo -e "----\nCompiling object $*..."
	mkdir -p $(@D)
	$(CXX) -o $@ -c $< $(CXXFLAGS)

EXTRA_OBJ_FILES = $(foreach f,$(EXTRA_OBJS),$(OBJ_DIR)/$(f).o)

$(EXTRA_OBJ_FILES): $(OBJ_DIR)/%.o: $$($$(*)_SRCS) $$($$(*)_HDRS) | check_vpp check_xrt check_platform
	@echo -e "----\nCompiling extra object $@..."
	mkdir -p $(@D)
	$(CXX) -o $@ -c $< $(CXXFLAGS)

EXE_EXT ?= exe
EXE_FILE ?= $(BIN_DIR)/$(EXE_NAME)$(if $(EXE_EXT),.,)$(EXE_EXT)

$(EXE_FILE): $(OBJ_FILES) $(EXTRA_OBJ_FILES) | check_vpp check_xrt check_platform
	@echo -e "----\nCompiling host $(notdir $@)..."
	mkdir -p $(BIN_DIR)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)

.PHONY: host
host: check_vpp check_xrt check_platform $(EXE_FILE)

# MK_INC_END vitis_host_rules.mk

# -----------------------------------------------------------------------------
#                                clean up

clean:
ifneq ($(OBJ_DIR_BASE),)
	rm -rf $(OBJ_DIR_BASE)*
endif
ifneq ($(BIN_DIR_BASE),)
	rm -rf $(BIN_DIR_BASE)*
endif

cleanall: clean
	rm -rf  $(DATA_STAMP)

# -----------------------------------------------------------------------------
#                                simulation run

$(BIN_#IR)/emconfig.json :
	emconfigutil --platform $(XPLATFORM) --od $(BIN_DIR) --nd 2

ifeq ($(TARGET),sw_emu)
EMU_MODE = export XCL_EMULATION_MODE=sw_emu
EMU_CONFIG = $(BIN_DIR)/emconfig.json
else ifeq ($(TARGET),hw_emu)
EMU_MODE = export XCL_EMULATION_MODE=hw_emu
EMU_CONFIG = $(BIN_DIR)/emconfig.json
else ifeq ($(TARGET),hw)
EMU_MODE = echo "TARGET=hw"
EMU_CONFIG =
endif

.PHONY: run run_sw_emu run_hw_emu run_hw check

run_sw_emu:
	make TARGET=sw_emu run

run_hw_emu:
	make TARGET=hw_emu run

run_hw:
	make TARGET=hw run

run: host xclbin $(EMU_CONFIG) $(DATA_STAMP)
	export LD_LIBRARY_PATH=$(GCC_INSTALL_DIR):$$LD_LIBRARY_PATH; \
  $(EMU_MODE); \
	$(EXE_FILE) $(HOST_ARGS)

check: run


