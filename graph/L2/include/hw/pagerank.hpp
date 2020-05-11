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

/**
 * @file pagerank.hpp
 * @brief  This files contains implementation of PageRank
 */

#ifndef XF_GRAPH_PR_H
#define XF_GRAPH_PR_H

#ifndef __SYNTHESIS__
#include <iostream>
#endif

#include "hls_math.h"
#include <hls_stream.h>

#include "xf_utils_hw/axi_to_stream.hpp"
#include "xf_utils_hw/cache.hpp"
#include "calc_degree.hpp"

#define _Width 512
typedef ap_uint<_Width> buffT;

namespace xf {
namespace graph {
namespace internal {
namespace pagerank {
// clang-format off
template <typename T, int rowTemplate, int UN>
void vecSub(int nrows, hls::stream<buffT>& pingStrm, hls::stream<buffT>& pongStrm, hls::stream<T> subStream[UN]) {
// clang-format on
#pragma HLS inline off
    const int size = sizeof(T) * 8;
    const int size2 = sizeof(T) * 4;
    const int wN = UN;
    const int iteration = (nrows + wN - 1) / wN;
    for (int i = 0; i < iteration; ++i) {
// clang-format off
#pragma HLS loop_tripcount min = 3700000/8 avg = 3700000/8 max = 3700000/8
// clang-format on
#pragma HLS pipeline II = 1
        buffT tmpA, tmpB;
        tmpA = pingStrm.read();
        tmpB = pongStrm.read();
        for (int k = 0; k < wN; ++k) {
#pragma HLS loop_tripcount min = 8 avg = 8 max = 8
#pragma HLS unroll factor = wN
            int index = i * wN + k;
            if (index < nrows) {
                ap_ufixed<size, size2> tmp1, tmp2;
                tmp1.range(size - 1, 0) = tmpA.range(size * (k + 1) - 1, size * k);
                tmp2.range(size - 1, 0) = tmpB.range(size * (k + 1) - 1, size * k);
                T tmpVal = hls::abs(tmp1 - tmp2);
                subStream[k].write(tmpVal);
            }
        }
    }
}

template <typename T, int UN>
void convergenceCal(int nrows, T tol, bool& converged, hls::stream<T> subStream[UN]) {
#pragma HLS inline off
    const int wN = UN;
    const int iteration = (nrows + wN - 1) / wN;
    bool converg[UN] = {1};
    for (int k = 0; k < wN; ++k) {
#pragma HLS loop_tripcount min = 8 avg = 8 max = 8
#pragma HLS pipeline II = 1
        converg[k] = 1;
    }
#pragma HLS array_partition variable = converg dim = 0 complete
    for (int i = 0; i < iteration; ++i) {
// clang-format off
#pragma HLS loop_tripcount min = 3700000/8 avg = 3700000/8 max = 3700000/8
// clang-format on
#pragma HLS pipeline II = 1
        for (int k = 0; k < wN; ++k) {
#pragma HLS loop_tripcount min = 8 avg = 8 max = 8
#pragma HLS unroll factor = wN
            int index = i * wN + k;
            if (index < nrows) {
                T val = subStream[k].read();
                if (val > tol) {
                    converg[k] = 0;
                }
            }
        }
    }
    for (int k = 0; k < wN; ++k) {
#pragma HLS loop_tripcount min = 8 avg = 8 max = 8
#pragma HLS pipeline II = 1
        if (converg[k] == 0) {
            converged = 0;
        }
    }
}

#ifndef __SYNTHESIS__
template <typename T, int rowTemplate>
void calConvergence(int nrows, T tol, bool& converged, buffT* bufferPing, buffT* bufferPong) {
#else
template <typename T, int rowTemplate>
void calConvergence(int nrows, T tol, bool& converged, buffT bufferPing[rowTemplate], buffT bufferPong[rowTemplate]) {
#endif
#pragma HLS inline off
#pragma HLS dataflow

    const int wN = (sizeof(T) == 4) ? 16 : 8;
    const int BURST_LENTH = 32;
    const int iteration = (nrows + wN - 1) / wN;
    int extra = iteration * wN - nrows;

    hls::stream<T> subStream[wN];
    // clang-format off
    hls::stream<buffT> pingStrm;
    hls::stream<buffT> pongStrm;
// clang-format on
#pragma HLS stream depth = 16 variable = subStream
#pragma HLS stream depth = 16 variable = pingStrm
#pragma HLS stream depth = 16 variable = pongStrm
#pragma HLS resource variable = subStream core = FIFO_LUTRAM
#pragma HLS resource variable = pingStrm core = FIFO_LUTRAM
#pragma HLS resource variable = pongStrm core = FIFO_LUTRAM
    xf::graph::internal::burstRead2Strm<buffT>(iteration, bufferPing, pingStrm);
    xf::graph::internal::burstRead2Strm<buffT>(iteration, bufferPong, pongStrm);
    vecSub<T, rowTemplate, wN>(nrows, pingStrm, pongStrm, subStream);
    convergenceCal<T, wN>(nrows, tol, converged, subStream);
}

template <typename T>
void calculateMul(int nnz, hls::stream<T>& inStrm, hls::stream<T>& cntStrm, hls::stream<T>& mulStrm) {
#pragma HLS inline off
    for (int i = 0; i < nnz; ++i) {
#pragma HLS loop_tripcount min = 16500000 avg = 16500000 max = 16500000
#pragma HLS pipeline II = 1
        T tmp1 = inStrm.read();
        T tmp2 = cntStrm.read();
        mulStrm.write(tmp1 * tmp2);
    }
}

template <typename T>
void adderUn(ap_uint<32> distance, T adder, ap_uint<1> flag, hls::stream<T>& splitStrm, T& outSum) {
#pragma HLS inline off
    if ((distance == 0) && (flag == 0)) {
        outSum = adder;
    } else if ((distance == 0) && (flag == 1)) {
        outSum = 0;
    } else if ((distance == 0) && (flag == 1)) {
    } else {
        T tmp = adder;
        const int II1 = (sizeof(T) == 8) ? 6 : 5;
        for (int i = 0; i < distance; ++i) {
#pragma HLS loop_tripcount min = 5 avg = 5 max = 5
#pragma HLS pipeline II = II1
            tmp += splitStrm.read();
        }
        outSum = tmp;
    }
}

// clang-format off
template <typename T, int unrollNm, int widthOr>
void adderPart11(int nrows,
                 hls::stream<ap_uint<widthOr> >& offsetStrm,
                 hls::stream<ap_uint<32> >& distStrm2,
                 hls::stream<ap_uint<1> > flagUnStrm[unrollNm]){
// clang-format on
#pragma HLS inline off
    ap_uint<32> counter1[unrollNm];
#pragma HLS array_partition variable = counter1 dim = 0 complete
    ap_uint<32> prev = 0;
    int iteration = (nrows + unrollNm - 1) / unrollNm;
    ap_uint<32> tmpVal[unrollNm];
#pragma HLS array_partition variable = tmpVal dim = 0 complete
    ap_uint<32> valP = prev;
    ap_uint<widthOr> tmp;
    for (int i = 0; i < iteration; ++i) {
// clang-format off
#pragma HLS loop_tripcount min = 3700000/unrollNm avg = 3700000/unrollNm max = 3700000/unrollNm
        // clang-format on
        for (int k = 0; k < unrollNm; ++k) {
#pragma HLS pipeline II = 1
            int index = i * unrollNm + k;
            if (index < nrows) {
                if (k == 0) {
                    tmp = offsetStrm.read();
                    valP = prev;
                }
                tmpVal[k].range(31, 0) = tmp.range(32 * (k + 1) - 1, 32 * k);
                ap_uint<1> flag = (tmpVal[k] == 0xffffffff) ? 1 : 0;
                flagUnStrm[k].write(flag);
                if (tmpVal[k] == 0xffffffff) {
                    counter1[k] = 0;
                } else if ((i == 0) && (k == 0)) {
                    counter1[k] = tmpVal[k];
                } else if ((i != 0) && (k == 0)) {
                    counter1[k] = tmpVal[k] - prev;
                } else {
                    counter1[k] = tmpVal[k] - valP;
                }
                distStrm2.write(counter1[k]);
                if (tmpVal[k] != 0xffffffff) {
                    valP = tmpVal[k];
                }
            }
            if (k == unrollNm - 1) {
                prev = valP;
            }
        }
    }
}

// clang-format off
template <int unrollNm>
void adderPart13(int nrows,
                 int iteration,
                 int nnz,
                 hls::stream<ap_uint<1> > flagUnStrm[unrollNm],
                 hls::stream<ap_uint<1> > flagUnStrm2[unrollNm]) {
// clang-format on
#pragma HLS inline off
Loop_iter:
    for (int i = 0; i < iteration; ++i) {
// clang-format off
#pragma HLS loop_tripcount min = 3700000/unrollNm avg = 3700000/unrollNm max = 3700000/unrollNm
    // clang-format on
    Loop_unroll:
        for (int k = 0; k < unrollNm; ++k) {
#pragma HLS loop_tripcount min = unrollNm avg = unrollNm max = unrollNm
            int index = i * unrollNm + k;
            if (index < nrows) {
                ap_uint<1> fflag = flagUnStrm[k].read();
                flagUnStrm2[k].write(fflag);
            }
        }
    }
}

// clang-format off
template <typename T, int unrollNm, int unrollBin>
void adderPart12(int nrows,
                 int nnz,
                 hls::stream<ap_uint<32> >& distStrm,
                 hls::stream<T>& mulStrm,
                 hls::stream<T> tmpStrm[unrollNm],
                 hls::stream<ap_uint<1> > distEStrm[unrollNm]){
// clang-format on
#pragma HLS inline off
    ap_uint<unrollBin> k = 0;
    int cntRow = 0;
    int distance = distStrm.read();
    while (cntRow < nrows) {
#pragma HLS loop_tripcount min = 16500000 avg = 16500000 max = 16500000
#pragma HLS pipeline II = 1
        if ((cntRow == nrows - 1) && (distance == 0)) {
            distEStrm[k].write(1);
            cntRow++;
        } else if (distance == 0) {
            distEStrm[k].write(1);
            k++;
            distance = distStrm.read();
            cntRow++;
        } else {
            T tmp = mulStrm.read();
            tmpStrm[k].write(tmp);
            distEStrm[k].write(0);
            distance--;
        }
    }
}

// clang-format off
template <typename T, int unrollNm>
void adderWrapper(int k,
                  int nrows,
                  int iteration,
                  T adder,
                  hls::stream<ap_uint<1> >& distEStrm,
                  hls::stream<ap_uint<1> >& flagStrm,
                  hls::stream<T>& tmpStrm,
                  hls::stream<T>& outStrm) {
// clang-format on
#pragma HLS inline off
    for (int i = 0; i < iteration; ++i) {
// clang-format off
#pragma HLS loop_tripcount min = 3700000/unrollNm avg = 3700000/unrollNm max = 3700000/unrollNm
        // clang-format on
        int index = i * unrollNm + k;
        if (index < nrows) {
            ap_uint<1> flag = flagStrm.read();
            T outSum = (flag) ? 0 : adder;
            while (!distEStrm.read()) {
#pragma HLS loop_tripcount min = 1 avg = 5 max = 5
#pragma HLS pipeline II = 5
                outSum += tmpStrm.read();
            }
            outStrm.write(outSum);
        }
    }
}

// clang-format off
template <typename T, int unrollNm>
void adderPart2(int nrows,
                int iteration,
                T adder,
                hls::stream<ap_uint<1> > distEStrm[unrollNm],
                hls::stream<ap_uint<1> > flagUnStrm2[unrollNm],
                hls::stream<T> tmpStrm[unrollNm],
                hls::stream<T> outStrm[unrollNm]) {
// clang-format on
#pragma HLS inline off
#pragma HLS dataflow

Loop_adder2:
    for (int k = 0; k < unrollNm; ++k) {
#pragma HLS unroll factor = unrollNm
        adderWrapper<T, unrollNm>(k, nrows, iteration, adder, distEStrm[k], flagUnStrm2[k], tmpStrm[k], outStrm[k]);
    }
}

// clang-format off
template <typename T, int rowTemplate, int unrollNm, int unrollBin>
void combineStrm512(int nrows, hls::stream<T> outStrm[unrollNm], hls::stream<buffT>& outStrm2) {
// clang-format on
#pragma HLS inline off
    ap_uint<unrollBin> cnt = 0;
    const int size = sizeof(T) * 8;
    const int size2 = sizeof(T) * 4;
    const int wN = (sizeof(T) == 4) ? 16 : 8;
    const int iteration = (nrows + wN - 1) / wN;
    buffT tmp = 0;
    for (int i = 0; i < iteration; ++i) {
// clang-format off
#pragma HLS loop_tripcount min = 3700000/8 avg = 3700000/8 max = 3700000/8
        // clang-format on
        for (int k = 0; k < wN; ++k) {
#pragma HLS pipeline II = 1
#pragma HLS loop_tripcount min = 8 avg = 8 max = 8
            int index = i * wN + k;
            if (index < nrows) {
                ap_ufixed<size, size2> tmp1 = outStrm[cnt].read();
                tmp.range(size * (k + 1) - 1, size * k) = tmp1.range(size - 1, 0);
                cnt++;
            }
            if (k == wN - 1) {
                outStrm2.write(tmp);
            }
        }
    }
}

#ifndef __SYNTHESIS__
template <typename T, int rowTemplate>
void writeOut(int nrows, hls::stream<buffT>& outStrm2, buffT* bufferWrite) {
#else
template <typename T, int rowTemplate>
void writeOut(int nrows, hls::stream<buffT>& outStrm2, buffT bufferWrite[rowTemplate]) {
#endif
#pragma HLS inline off
    const int wN = (sizeof(T) == 4) ? 16 : 8;
    const int iteration = (nrows + wN - 1) / wN;
    for (int i = 0; i < iteration; ++i) {
// clang-format off
#pragma HLS loop_tripcount min = 3700000/8 avg = 3700000/8 max = 3700000/8
// clang-format on
#pragma HLS pipeline II = 1
        bufferWrite[i] = outStrm2.read();
    }
}

template <typename T>
void transfer(int nnz,
              hls::stream<ap_uint<8 * sizeof(T)> >& cntStrm2,
              hls::stream<ap_uint<8 * sizeof(T)> >& pingStrm2,
              hls::stream<T>& cntStrm,
              hls::stream<T>& pingStrm) {
#pragma HLS inline off
    for (int i = 0; i < nnz; ++i) {
#pragma HLS loop_tripcount min = 16500000 avg = 16500000 max = 16500000
#pragma HLS pipeline II = 1
        ap_ufixed<64, 32> tmp, tmp0;
        ap_uint<64> ttm, ttm0;
        ttm = cntStrm2.read();
        ttm0 = pingStrm2.read();
        tmp.range(63, 0) = ttm.range(63, 0);
        tmp0.range(63, 0) = ttm0.range(63, 0);
        cntStrm.write(tmp.to_double());
        pingStrm.write(tmp0.to_double());
    }
}

#ifndef __SYNTHESIS__
template <int BURST_LENTH,
          typename T,
          int rowTemplate,
          int NNZTemplate,
          int unrollNm,
          int unrollBin,
          int widthOr,
          int uramRow,
          int groupUramPart,
          int dataOneLine,
          int addrWidth,
          int usURAM>
void dataFlowPart(
    int nrows,
    int nnz,
    T adder,
    xf::common::utils_hw::cache<ap_uint<64>, uramRow, groupUramPart, dataOneLine, addrWidth, usURAM, usURAM, usURAM>&
        cache0,
    buffT* indices,
    buffT* cntVal,
    ap_uint<widthOr>* order,
    buffT* buffPing,
    buffT* buffPong) {
#else
template <int BURST_LENTH,
          typename T,
          int rowTemplate,
          int NNZTemplate,
          int unrollNm,
          int unrollBin,
          int widthOr,
          int uramRow,
          int groupUramPart,
          int dataOneLine,
          int addrWidth,
          int usURAM>
void dataFlowPart(
    int nrows,
    int nnz,
    T adder,
    xf::common::utils_hw::cache<ap_uint<64>, uramRow, groupUramPart, dataOneLine, addrWidth, usURAM, usURAM, usURAM>&
        cache0,
    buffT indices[NNZTemplate],
    buffT cntVal[rowTemplate],
    ap_uint<widthOr> order[rowTemplate / unrollNm],
    buffT buffPing[rowTemplate],
    buffT buffPong[rowTemplate]) {
#endif
#pragma HLS inline off
#pragma HLS dataflow
    const int iteration = (sizeof(T) == 8) ? (nrows + 7) / 8 : (nrows + 15) / 16;
    // clang-format off
    hls::stream<ap_uint<32> > indiceStrm("indiceStrm");
    hls::stream<ap_uint<widthOr> > offsetStrm("offsetStrm");
    hls::stream<T> pingStrm("pingStrm");
    hls::stream<ap_uint<sizeof(T) * 8> > pingTmp("pingTmp");
    hls::stream<ap_uint<sizeof(T) * 8> > cntTmp("pingTmp");
    hls::stream<ap_uint<32> > distStrm;
    hls::stream<T> cntStrm("cntStrm");
    hls::stream<T> mulStrm("mulStrm");
    hls::stream<ap_uint<1> > flagUnStrm[unrollNm];
    hls::stream<T> outStrm[unrollNm];
    hls::stream<buffT> outStrm2;
    hls::stream<T> tmpStrm[unrollNm];
// clang-format on
#pragma HLS stream depth = 4096 variable = tmpStrm
#pragma HLS stream depth = 16 variable = mulStr
#pragma HLS stream depth = 16 variable = flagUnStrm
#pragma HLS stream depth = 16 variable = indiceStrm
#pragma HLS stream depth = 16 variable = offsetStrm
#pragma HLS stream depth = 16 variable = pingStrm
#pragma HLS stream depth = 16 variable = pingTmp
#pragma HLS stream depth = 16 variable = cntTmp
#pragma HLS stream depth = 16 variable = distStrm
#pragma HLS stream depth = 16 variable = cntStrm
#pragma HLS stream depth = 16 variable = outStrm
#pragma HLS stream depth = 16 variable = outStrm2
#pragma HLS resource variable = flagUnStrm core = FIFO_LUTRAM
#pragma HLS resource variable = distStrm core = FIFO_LUTRAM
#pragma HLS resource variable = mulStrm core = FIFO_LUTRAM
#pragma HLS resource variable = indiceStrm core = FIFO_LUTRAM
#pragma HLS resource variable = offsetStrm core = FIFO_LUTRAM
#pragma HLS resource variable = pingStrm core = FIFO_LUTRAM
#pragma HLS resource variable = pingTmp core = FIFO_LUTRAM
#pragma HLS resource variable = cntTmp core = FIFO_LUTRAM
#pragma HLS resource variable = cntStrm core = FIFO_LUTRAM
#pragma HLS resource variable = outStrm core = FIFO_LUTRAM
#pragma HLS resource variable = outStrm2 core = FIFO_LUTRAM
    hls::stream<ap_uint<1> > flagUnStrm2[unrollNm];
    hls::stream<ap_uint<1> > distEStrm[unrollNm];
#pragma HLS stream depth = 4096 variable = flagUnStrm2
#pragma HLS stream depth = 4096 variable = distEStrm
#pragma HLS resource variable = flagUnStrm2 core = FIFO_LUTRAM
#pragma HLS resource variable = distEStrm core = FIFO_LUTRAM

    hls::stream<ap_uint<64> > pingStrm2("pingStrm");
    hls::stream<ap_uint<64> > cntStrm2("cntStrm");
#pragma HLS stream depth = 16 variable = pingStrm2
#pragma HLS resource variable = pingStrm2 core = FIFO_LUTRAM
#pragma HLS stream depth = 16 variable = cntStrm2
#pragma HLS resource variable = cntStrm2 core = FIFO_LUTRAM

    xf::common::utils_hw::axiToStream<BURST_LENTH, _Width, ap_uint<32> >(indices, nnz, indiceStrm);
    cache0.readOnly(nnz, buffPing, cntVal, indiceStrm, cntStrm2, pingStrm2);
    transfer<T>(nnz, cntStrm2, pingStrm2, cntStrm, pingStrm);
    calculateMul<T>(nnz, pingStrm, cntStrm, mulStrm);
    // clang-format off
    xf::graph::internal::burstRead2Strm<ap_uint<widthOr> >(iteration, order, offsetStrm);
    // clang-format on
    adderPart11<T, unrollNm, widthOr>(nrows, offsetStrm, distStrm, flagUnStrm);
    adderPart12<T, unrollNm, unrollBin>(nrows, nnz, distStrm, mulStrm, tmpStrm, distEStrm);
    adderPart13<unrollNm>(nrows, iteration, nnz, flagUnStrm, flagUnStrm2);
    adderPart2<T, unrollNm>(nrows, iteration, adder, distEStrm, flagUnStrm2, tmpStrm, outStrm);
    combineStrm512<T, rowTemplate, unrollNm, unrollBin>(nrows, outStrm, outStrm2);
    writeOut<T, rowTemplate>(nrows, outStrm2, buffPong);
}

#ifndef __SYNTHESIS__
template <int BURST_LENTH,
          typename T,
          int rowTemplate,
          int NNZTemplate,
          int unrollNm,
          int unrollBin,
          int widthOr,
          int uramRow,
          int groupUramPart,
          int dataOneLine,
          int addrWidth,
          int usURAM>
void dataFlowWrapper(
    int nrows,
    int nnz,
    ap_uint<1>& share,
    T adder,
    xf::common::utils_hw::cache<ap_uint<64>, uramRow, groupUramPart, dataOneLine, addrWidth, usURAM, usURAM, usURAM>&
        cache0,
    buffT* indices,
    buffT* cntVal,
    ap_uint<widthOr>* order,
    buffT* buffPing,
    buffT* buffPong) {
#else
template <int BURST_LENTH,
          typename T,
          int rowTemplate,
          int NNZTemplate,
          int unrollNm,
          int unrollBin,
          int widthOr,
          int uramRow,
          int groupUramPart,
          int dataOneLine,
          int addrWidth,
          int usURAM>
void dataFlowWrapper(
    int nrows,
    int nnz,
    ap_uint<1>& share,
    T adder,
    xf::common::utils_hw::cache<ap_uint<64>, uramRow, groupUramPart, dataOneLine, addrWidth, usURAM, usURAM, usURAM>&
        cache0,
    buffT indices[NNZTemplate],
    buffT cntVal[rowTemplate],
    ap_uint<widthOr> order[rowTemplate / unrollNm],
    buffT buffPing[rowTemplate],
    buffT buffPong[rowTemplate]) {
#endif
#pragma HLS inline off
    cache0.initDualOffChip();
    if (share) {
        dataFlowPart<BURST_LENTH, T, rowTemplate, NNZTemplate, unrollNm, unrollBin, widthOr, uramRow, groupUramPart,
                     dataOneLine, addrWidth, usURAM>(nrows, nnz, adder, cache0, indices, cntVal, order, buffPing,
                                                     buffPong);
    } else {
        dataFlowPart<BURST_LENTH, T, rowTemplate, NNZTemplate, unrollNm, unrollBin, widthOr, uramRow, groupUramPart,
                     dataOneLine, addrWidth, usURAM>(nrows, nnz, adder, cache0, indices, cntVal, order, buffPong,
                                                     buffPing);
    }
    share++;
}

#ifndef __SYNTHESIS__
template <int BURST_LENTH,
          typename T,
          int rowTemplate,
          int NNZTemplate,
          int unrollNm,
          int unrollBin,
          int widthOr,
          int uramRow,
          int groupUramPart,
          int dataOneLine,
          int addrWidth,
          int usURAM>
void dataFlowTop(
    int nrows,
    int nnz,
    ap_uint<1>& share,
    T adder,
    xf::common::utils_hw::cache<ap_uint<64>, uramRow, groupUramPart, dataOneLine, addrWidth, usURAM, usURAM, usURAM>&
        cache0,
    buffT* indices,
    buffT* cntVal,
    ap_uint<widthOr>* order,
    buffT* buffPing,
    buffT* buffPong,
    T tol,
    bool& converged) {
#else
template <int BURST_LENTH,
          typename T,
          int rowTemplate,
          int NNZTemplate,
          int unrollNm,
          int unrollBin,
          int widthOr,
          int uramRow,
          int groupUramPart,
          int dataOneLine,
          int addrWidth,
          int usURAM>
void dataFlowTop(
    int nrows,
    int nnz,
    ap_uint<1>& share,
    T adder,
    xf::common::utils_hw::cache<ap_uint<64>, uramRow, groupUramPart, dataOneLine, addrWidth, usURAM, usURAM, usURAM>&
        cache0,
    buffT indices[NNZTemplate],
    buffT cntVal[rowTemplate],
    ap_uint<widthOr> order[rowTemplate / unrollNm],
    buffT buffPing[rowTemplate],
    buffT buffPong[rowTemplate],
    T tol,
    bool& converged) {
#endif
#pragma HLS inline off
    dataFlowWrapper<BURST_LENTH, T, rowTemplate, NNZTemplate, unrollNm, unrollBin, widthOr, uramRow, groupUramPart,
                    dataOneLine, addrWidth, usURAM>(nrows, nnz, share, adder, cache0, indices, cntVal, order, buffPing,
                                                    buffPong);
    calConvergence<T, rowTemplate>(nrows, tol, converged, buffPing, buffPong);
}

template <typename T, int SIZE, int UN>
void adderV1(int nrows, hls::stream<buffT>& prStrm, hls::stream<T> addT[UN]) {
    const int wN = UN;
    const int iteration = (nrows + wN - 1) / wN;
    for (int i = 0; i < iteration; ++i) {
#pragma HLS pipeline II = 1
// clang-format off
#pragma HLS loop_tripcount min = 3700000/wN avg = 3700000/wN max = 3700000/wN
        // clang-format on
        buffT tmp1 = prStrm.read();
        for (int k = 0; k < wN; ++k) {
#pragma HLS unroll factor = wN
            int index = i * wN + k;
            if (index < nrows) {
                ap_ufixed<SIZE, SIZE / 2> tmp;
                tmp.range(SIZE - 1, 0) = tmp1.range(SIZE * (k + 1) - 1, SIZE * k);
                addT[k].write((T)tmp);
            }
        }
    }
}

template <typename T, int UN>
void adderV3(T sum[UN], T& divider) {
#pragma HLS inline off
    T tmp1, tmp2, tmp3, tmp4, tmp5, tmp6;
    T tmp7, tmp8, tmp9, tmp10, tmp11, tmp12, tmp13, tmp14;
    tmp1 = sum[0] + sum[1];
    tmp2 = sum[2] + sum[3];
    tmp3 = sum[4] + sum[5];
    tmp4 = sum[6] + sum[7];
    tmp9 = tmp1 + tmp2;
    tmp10 = tmp3 + tmp4;
    tmp13 = tmp10 + tmp9;
    if (UN == 16) {
        tmp5 = sum[8] + sum[9];
        tmp6 = sum[10] + sum[11];
        tmp7 = sum[12] + sum[13];
        tmp8 = sum[14] + sum[15];
        tmp11 = tmp5 + tmp6;
        tmp12 = tmp7 + tmp8;
        tmp14 = tmp12 + tmp11;
        divider = tmp13 + tmp14;
    } else if (UN == 8) {
        divider = tmp13;
    }
}

template <typename T, int UN>
void adderSingle(int k, int nrows, int iteration, hls::stream<T>& addT, T& sum) {
#pragma HLS inline off
    const int II1 = (sizeof(T) == 8) ? 6 : 5;
    const int wN = UN;
    T tmp[16] = {0.0};
#pragma HLS resource variable = tmp core = RAM_2P_LUTRAM
    ap_uint<4> cnt = 0;
    for (int i = 0; i < iteration; ++i) {
// clang-format off
#pragma HLS loop_tripcount min = 3700000/wN avg = 3700000/wN max = 3700000/wN
// clang-format on
#pragma HLS dependence variable = tmp inter false
#pragma HLS pipeline II = 1
        int index = i * UN + k;
        if (index < nrows) {
            tmp[cnt] += addT.read();
            cnt++;
        }
    }
    adderV3<T, 16>(tmp, sum);
}

template <typename T, int SIZE, int UN>
void adderV2(int nrows, hls::stream<T> addT[UN], T sum[UN]) {
#pragma HLS inline off
    const int wN = UN;
    const int iteration = (nrows + wN - 1) / wN;
    for (int k = 0; k < 8; ++k) {
#pragma HLS unroll factor = 8
        adderSingle<T, UN>(k, nrows, iteration, addT[k], sum[k]);
    }
}

#ifndef __SYNTHESIS__
template <typename T, int rowTemplate, int UN>
void dataFlowDive(int nrows, buffT* buffPing, T* sum) {
#else
template <typename T, int rowTemplate, int UN>
void dataFlowDive(int nrows, buffT buffPing[rowTemplate], T sum[UN]) {
#endif
#pragma HLS inline off
#pragma HLS dataflow
    const int BURST_LENTH = 32;
    const int size0 = sizeof(T) * 8;
    int iteration = (nrows + UN - 1) / UN;
    hls::stream<buffT> prStrm("prStrm");
#pragma HLS stream depth = 8 variable = prStrm
    hls::stream<T> addT[UN];
#pragma HLS stream depth = 8 variable = addT
#pragma HLS resource variable = prStrm core = FIFO_LUTRAM
#pragma HLS resource variable = addT core = FIFO_LUTRAM
    xf::graph::internal::burstRead2Strm<buffT>(iteration, buffPing, prStrm);
    adderV1<T, size0, UN>(nrows, prStrm, addT);
    adderV2<T, size0, UN>(nrows, addT, sum);
}

#ifndef __SYNTHESIS__
template <typename T, int rowTemplate, int SIZE, int UN>
void dividers(int iteration, T divider, hls::stream<buffT>& prStrm, buffT* pagerank) {
#else
template <typename T, int rowTemplate, int SIZE, int UN>
void dividers(int iteration, T divider, hls::stream<buffT>& prStrm, buffT pagerank[rowTemplate]) {
#endif
#pragma HLS inline off
    const int wN = UN;
    buffT tmp1;
    buffT tmp2;
    for (int i = 0; i < iteration; ++i) {
// clang-format off
#pragma HLS loop_tripcount min = 3700000/8 avg = 3700000/8 max = 3700000/8
// clang-format on
#pragma HLS pipeline II = 1
        for (int k = 0; k < UN; ++k) {
            if (k == 0) {
                tmp1 = prStrm.read();
            }
            ap_ufixed<SIZE, SIZE / 2> tmp;
            ap_ufixed<SIZE, SIZE / 2> tmp0;
            tmp.range(SIZE - 1, 0) = tmp1.range(SIZE * (k + 1) - 1, SIZE * k);
            tmp0 = ((T)tmp) / divider;
            tmp2.range(SIZE * (k + 1) - 1, SIZE * k) = tmp0.range(SIZE - 1, 0);
            if (k == UN - 1) {
                pagerank[i] = tmp2;
            }
        }
    }
}

#ifndef __SYNTHESIS__
template <typename T, int rowTemplate>
void divideVal(int nrows, T divider, buffT* buffPing, buffT* pagerank) {
#else
template <typename T, int rowTemplate>
void divideVal(int nrows, T divider, buffT buffPing[rowTemplate], buffT pagerank[rowTemplate]) {
#endif
#pragma HLS inline off
#pragma HLS dataflow
    const int BURST_LENTH = 32;
    const int size0 = sizeof(T) * 8;
    const int wN = (sizeof(T) == 4) ? 16 : 8;
    const int iteration = (nrows + wN - 1) / wN;
    hls::stream<buffT> prStrm("prStrm");
#pragma HLS stream depth = 8 variable = prStrm
#pragma HLS resource variable = prStrm core = FIFO_LUTRAM
    xf::graph::internal::burstRead2Strm<buffT>(iteration, buffPing, prStrm);
    dividers<T, rowTemplate, size0, wN>(iteration, divider, prStrm, pagerank);
}

// clang-format off
template <typename T, int widthOr>
void preWrite32(int nrows,
                T alpha,
                T& randomProbability,
                hls::stream<buffT>& csrDegree,
                hls::stream<buffT>& cscOffset,
                hls::stream<buffT>& pongStrm,
                hls::stream<buffT>& cntStrm,
                hls::stream<ap_uint<widthOr> >& orderStrm) {
// clang-format on
#pragma HLS inline off
    const int unroll2 = 16;
    ap_uint<32> tVal = 0xffffffff;
    int realNrows = nrows;
    randomProbability = 1.0 / realNrows;
    const int sizeT = 32;
    const int sizeT2 = 16;
    ap_uint<32> tmpCSCPre = 0;
    int iteration = (nrows + 15) / 16;
    for (int i = 0; i < iteration; ++i) {
// clang-format off
#pragma HLS loop_tripcount min = 3700000/16 avg = 3700000/16 max = 3700000/16
// clang-format on
#pragma HLS pipeline II = 1
        buffT tmpOffset = cscOffset.read();
        buffT tmpDgree = csrDegree.read();
        buffT pongTmp;
        buffT cntTmp;
        buffT pongTmp1;
        buffT cntTmp1;
        ap_uint<widthOr> orderTmp;
        ap_uint<sizeT> pongT[unroll2];
        ap_uint<sizeT> cntT[unroll2];
        ap_uint<32> orderT[unroll2];
#pragma HLS array_partition variable = pongT dim = 0 complete
#pragma HLS array_partition variable = cntT dim = 0 complete
#pragma HLS array_partition variable = orderT dim = 0 complete
        for (int k = 0; k < unroll2; ++k) {
#pragma HLS loop_tripcount min = unroll2 avg = unroll2 max = unroll2
#pragma HLS unroll factor = unroll2
            int index = i * unroll2 + k;
            if (index < nrows) {
                ap_uint<32> cntCSR, cntCSC;
                cntCSR = tmpDgree.range(32 * (k + 1) - 1, 32 * k);
                ap_uint<32> tmpCSC = tmpOffset.range(32 * (k + 1) - 1, 32 * k);
                if (k == 0) {
                    cntCSC = tmpCSC - tmpCSCPre;
                } else {
                    cntCSC = tmpCSC - tmpOffset.range(32 * k - 1, 32 * (k - 1));
                }
                if (k == unroll2 - 1) {
                    tmpCSCPre = tmpCSC;
                }
                if ((cntCSR == 0) && (cntCSC == 0)) {
                    pongT[k] = 0;
                    orderT[k] = tVal;
                } else {
                    ap_ufixed<sizeT, sizeT2> tTmp = randomProbability;
                    pongT[k] = tTmp.range(sizeT - 1, 0);
                    orderT[k] = tmpCSC;
                }
                if (cntCSR != 0) {
                    ap_ufixed<sizeT, sizeT2> tTmp2 = alpha / cntCSR;
                    cntT[k] = tTmp2.range(sizeT - 1, 0);
                } else {
                    cntT[k] = 0;
                }
            }
        }
        for (int k = 0; k < unroll2; ++k) {
#pragma HLS unroll factor = unroll2
            orderTmp.range(32 * (k + 1) - 1, 32 * k) = orderT[k].range(31, 0);
            pongTmp.range(sizeT * (k + 1) - 1, sizeT * k) = pongT[k].range(sizeT - 1, 0);
            cntTmp.range(sizeT * (k + 1) - 1, sizeT * k) = cntT[k].range(sizeT - 1, 0);
        }
        pongStrm.write(pongTmp);
        cntStrm.write(cntTmp);
        orderStrm.write(orderTmp);
    }
}

// clang-format off
template <typename T, int widthOr>
void preWrite64(int nrows,
                T alpha,
                T& randomProbability,
                hls::stream<buffT>& csrDegree,
                hls::stream<buffT>& cscOffset,
                hls::stream<buffT>& pongStrm,
                hls::stream<buffT>& cntStrm,
                hls::stream<ap_uint<widthOr> >& orderStrm) {
// clang-format on
#pragma HLS inline off
    const int unroll2 = 8;
    ap_uint<32> tVal = 0xffffffff;
    int realNrows = nrows;
    randomProbability = 1.0 / realNrows;
    const int sizeT = 64;
    const int sizeT2 = 32;
    ap_uint<32> tmpCSCPre = 0;
    int iteration = (nrows + 7) / 8;
    ap_uint<1> cnt = 0;
    int offs = 256;
    buffT tmpOffset;
    buffT tmpDgree;
    for (int i = 0; i < iteration; ++i) {
// clang-format off
#pragma HLS loop_tripcount min = 3700000/8 avg = 3700000/8 max = 3700000/8
// clang-format on
#pragma HLS pipeline II = 1

        if (cnt == 0) {
            tmpOffset = cscOffset.read();
            tmpDgree = csrDegree.read();
        }
        buffT pongTmp;
        buffT cntTmp;
        buffT pongTmp1;
        buffT cntTmp1;
        ap_uint<widthOr> orderTmp;
        ap_uint<sizeT> pongT[unroll2];
        ap_uint<sizeT> cntT[unroll2];
        ap_uint<32> orderT[unroll2];
#pragma HLS array_partition variable = pongT dim = 0 complete
#pragma HLS array_partition variable = cntT dim = 0 complete
#pragma HLS array_partition variable = orderT dim = 0 complete
        for (int k = 0; k < unroll2; ++k) {
#pragma HLS loop_tripcount min = unroll2 avg = unroll2 max = unroll2
#pragma HLS unroll factor = unroll2
            int index = i * unroll2 + k;
            if (index < nrows) {
                ap_uint<32> cntCSR, cntCSC;
                ap_uint<32> tmpCSC;
                if (cnt == 0) {
                    offs = 0;
                } else {
                    offs = 256;
                }
                cntCSR = tmpDgree.range(32 * (k + 1) - 1 + offs, 32 * k + offs);
                tmpCSC = tmpOffset.range(32 * (k + 1) - 1 + offs, 32 * k + offs);
                if ((k == 0) && (cnt == 0)) {
                    cntCSC = tmpCSC - tmpCSCPre;
                } else {
                    cntCSC = tmpCSC - tmpOffset.range(32 * k - 1 + offs, 32 * (k - 1) + offs);
                }
                if ((k == unroll2 - 1) && (cnt == 1)) {
                    tmpCSCPre = tmpCSC;
                }
                if ((cntCSR == 0) && (cntCSC == 0)) {
                    pongT[k] = 0;
                    orderT[k] = tVal;
                } else {
                    ap_ufixed<sizeT, sizeT2> tTmp = randomProbability;
                    pongT[k] = tTmp.range(sizeT - 1, 0);
                    orderT[k] = tmpCSC;
                }
                if (cntCSR != 0) {
                    ap_ufixed<sizeT, sizeT2> tTmp2 = alpha / cntCSR;
                    cntT[k] = tTmp2.range(sizeT - 1, 0);
                } else {
                    cntT[k] = 0;
                }
            }
        }
        for (int k = 0; k < unroll2; ++k) {
#pragma HLS unroll factor = unroll2
            orderTmp.range(32 * (k + 1) - 1, 32 * k) = orderT[k].range(31, 0);
            pongTmp.range(sizeT * (k + 1) - 1, sizeT * k) = pongT[k].range(sizeT - 1, 0);
            cntTmp.range(sizeT * (k + 1) - 1, sizeT * k) = cntT[k].range(sizeT - 1, 0);
        }
        cnt++;
        pongStrm.write(pongTmp);
        cntStrm.write(cntTmp);
        orderStrm.write(orderTmp);
    }
}

// clang-format off
template <typename T, int widthOr>
void preWrite(int nrows,
              T alpha,
              T& randomProbability,
              hls::stream<buffT>& csrDegree,
              hls::stream<buffT>& cscOffset,
              hls::stream<buffT>& pongStrm,
              hls::stream<buffT>& cntStrm,
              hls::stream<ap_uint<widthOr> >& orderStrm) {
// clang-format on
#pragma HLS inline off
    const int size0 = sizeof(T);
    if (size0 == 4) {
        preWrite32<T>(nrows, alpha, randomProbability, csrDegree, cscOffset, pongStrm, cntStrm, orderStrm);
    } else if (size0 == 8) {
        preWrite64<T>(nrows, alpha, randomProbability, csrDegree, cscOffset, pongStrm, cntStrm, orderStrm);
    }
}

template <typename T>
void combine512(int nrows, hls::stream<buffT> pingStrm[2], hls::stream<buffT>& pingStrm2) {
#pragma HLS inline off
    int iteration = (nrows + 15) / 16;
    int cnt = 0;
    for (int i = 0; i < iteration; ++i) {
// clang-format off
#pragma HLS loop_tripcount min = 3700000/16 avg = 3700000/16 max = 3700000/16
// clang-format on
#pragma HLS pipeline II = 1
        if (sizeof(T) == 4) {
            pingStrm2.write(pingStrm[0].read());
        } else if (sizeof(T) == 8) {
            if (cnt * 8 < nrows) {
                pingStrm2.write(pingStrm[0].read());
            }
            if (cnt * 8 + 8 < nrows) {
                pingStrm2.write(pingStrm[1].read());
            }
            cnt++;
        }
        cnt++;
    }
}

// clang-format off
#ifndef __SYNTHESIS__
template <typename T, int rowTemplate, int widthOr>
void writeOutDDROrder(int nrows, hls::stream<ap_uint<widthOr> >& orderStrm, ap_uint<widthOr>* orderUnroll) {
#else
template <typename T, int rowTemplate, int widthOr>
void writeOutDDROrder(int nrows, hls::stream<ap_uint<widthOr> >& orderStrm, ap_uint<widthOr> orderUnroll[rowTemplate]) {
// clang-format off
#endif
#pragma HLS inline off
    const int iteration = (sizeof(T) == 8) ? (nrows + 7) / 8 : (nrows + 15) / 16;
    for (int i = 0; i < iteration; ++i) {
// clang-format off
#pragma HLS loop_tripcount min = 3700000/8 avg = 3700000/8 max = 3700000/8
// clang-format on
#pragma HLS pipeline II = 1
        orderUnroll[i] = orderStrm.read();
    }
}

#ifndef __SYNTHESIS__
template <typename T, int rowTemplate>
void writeOutDDR(
    int nrows, hls::stream<buffT>& cntStrm, hls::stream<buffT>& pongStrm, buffT* cntValFull, buffT* buffPong) {
#else
template <typename T, int rowTemplate>
void writeOutDDR(int nrows,
                 hls::stream<buffT>& cntStrm,
                 hls::stream<buffT>& pongStrm,
                 buffT cntValFull[rowTemplate],
                 buffT buffPong[rowTemplate]) {
#endif
#pragma HLS inline off
    const int iteration = (sizeof(T) == 8) ? (nrows + 7) / 8 : (nrows + 15) / 16;
    for (int i = 0; i < iteration; ++i) {
// clang-format off
#pragma HLS loop_tripcount min = 3700000/8 avg = 3700000/8 max = 3700000/8
// clang-format on
#pragma HLS pipeline II = 1
        buffPong[i] = pongStrm.read();
        cntValFull[i] = cntStrm.read();
    }
}

#ifndef __SYNTHESIS__
template <typename T, int BURST_LENTH, int rowTemplate, int NNZTemplate, int widthOr>
void initDDR(int nrows,
             int nnz,
             T alpha,
             T& randomProbability,
             buffT* degreeCSR,
             buffT* offsetCSC,
             buffT* cntValFull,
             buffT* buffPong,
             ap_uint<widthOr>* orderUnroll) {
#else
template <typename T, int BURST_LENTH, int rowTemplate, int NNZTemplate, int widthOr>
void initDDR(int nrows,
             int nnz,
             T alpha,
             T& randomProbability,
             buffT degreeCSR[rowTemplate],
             buffT offsetCSC[rowTemplate],
             buffT cntValFull[rowTemplate],
             buffT buffPong[rowTemplate],
             ap_uint<widthOr> orderUnroll[rowTemplate]) {
#endif
#pragma HLS inline off
#pragma HLS dataflow
    hls::stream<buffT> csrDegree("csrDegree");
#pragma HLS stream depth = 8 variable = csrDegree
    hls::stream<buffT> cscOffset("cscOffset");
#pragma HLS stream depth = 8 variable = cscOffset
    hls::stream<buffT> pongStrm;
#pragma HLS stream depth = 8 variable = pongStrm
    hls::stream<buffT> cntStrm;
#pragma HLS stream depth = 8 variable = cntStrm
    hls::stream<ap_uint<widthOr> > orderStrm;
#pragma HLS stream depth = 8 variable = orderStrm
#pragma HLS resource variable = csrDegree core = FIFO_LUTRAM
#pragma HLS resource variable = cscOffset core = FIFO_LUTRAM
#pragma HLS resource variable = pongStrm core = FIFO_LUTRAM
#pragma HLS resource variable = cntStrm core = FIFO_LUTRAM
#pragma HLS resource variable = orderStrm core = FIFO_LUTRAM
    const int wN = 16;
    const int iteration = (nrows + wN - 1) / wN;
    const int extra = iteration * wN - nrows;
    xf::graph::internal::axiToCharStream<BURST_LENTH, _Width, buffT>(degreeCSR, csrDegree, 4 * (nrows + extra));
    xf::graph::internal::axiToCharStream<BURST_LENTH, _Width, buffT>(offsetCSC, cscOffset, 4 * (nrows + extra), 4);
    preWrite<T, widthOr>(nrows, alpha, randomProbability, csrDegree, cscOffset, pongStrm, cntStrm, orderStrm);
    writeOutDDR<T, rowTemplate>(nrows, cntStrm, pongStrm, cntValFull, buffPong);
    writeOutDDROrder<T, rowTemplate, widthOr>(nrows, orderStrm, orderUnroll);
}
} // namespace pagerank
} // namespace internal

template <typename T,
          int rowTemplate,
          int NNZTemplate,
          int unrollBin,
          int widthOr,
          int uramRowBin,
          int dataOneLineBin,
          int usURAM>
void pageRankCore(int nrows,
                  int nnz,
                  buffT* pagerank,
                  buffT* buffPing,
                  buffT* buffPong,
                  ap_uint<widthOr>* order,
                  buffT* indices,
                  buffT* cntVal,
                  T randomProbability,
                  T alpha = 0.85,
                  T tolerance = 1e-4,
                  int maxIter = 200) {
    const int dataUramNmBin = 0;
    const int dataOneLine = 1 << dataOneLineBin;  // double 8 : float 16
    const int uramRow = 1 << uramRowBin;          // 4096
    const int groupUramPart = 1 << dataUramNmBin; // 8 = 2^3
    const int addrWidth = 32;
    const int unrollFactor = 1;

    const int BURST_LENTH = 32;
    const int TYPE_LENGTH = sizeof(T) * 8;
    int maxIt;
    T tol;
    int returnVal = 0;
    const int unrollNm = 1 << unrollBin;

    if (maxIter > 0)
        maxIt = maxIter;
    else
        maxIt = 500;

    if (tolerance == 0.0f)
        tol = 1.0E-6f;
    else if (tolerance < 1.0f && tolerance > 0.0f)
        tol = tolerance;
    else
        returnVal = 1;

    if (alpha <= 0.0f || alpha >= 1.0f) returnVal = -1;

    ap_uint<1> share = 0;

    T adder = 1 - alpha;

    bool converged = false;

    int iterator = 0;

    xf::common::utils_hw::cache<ap_uint<64>, uramRow, groupUramPart, dataOneLine, addrWidth, usURAM, usURAM, usURAM>
        cache0;
    while (!converged && iterator < maxIt) {
#pragma HLS loop_tripcount min = 16 avg = 16 max = 16
        iterator++;
        converged = 1;
        internal::pagerank::dataFlowTop<BURST_LENTH, T, rowTemplate, NNZTemplate, unrollNm, unrollBin, widthOr, uramRow,
                                        groupUramPart, dataOneLine, addrWidth, usURAM>(
            nrows, nnz, share, adder, cache0, indices, cntVal, order, buffPing, buffPong, tol, converged);
    }

    T divider;
    T sum[unrollNm] = {0.0};
#pragma HLS array_partition variable = sum dim = 0 complete
    if (share) {
        internal::pagerank::dataFlowDive<T, rowTemplate, unrollNm>(nrows, buffPing, sum);
        internal::pagerank::adderV3<T, unrollNm>(sum, divider);
        internal::pagerank::divideVal<T, rowTemplate>(nrows, divider, buffPing, pagerank);
    } else {
        internal::pagerank::dataFlowDive<T, rowTemplate, unrollNm>(nrows, buffPong, sum);
        internal::pagerank::adderV3<T, unrollNm>(sum, divider);
        internal::pagerank::divideVal<T, rowTemplate>(nrows, divider, buffPong, pagerank);
    }
}

/**
 * @brief pagerank algorithm is implemented
 *
 * @tparam T date type, double or float
 * @tparam MAXVERTEX CSC/CSR data vertex(offset) array maxsize
 * @tparam MAXEDGE CSC/CSR data edge(indice) array maxsize
 * @tparam LOG2UNROLL log2 of unroll number, due to DDR limit, best LOG2UNROLL is 3
 * @tparam WIDTHOR order array bandwidth, it's 256 in our case
 * @tparam LOG2CACHEDEPTH log2(cache depth), the onchip memory for cache is 512 bit x CACHEDEPTH (512 bit x
 * 2^LOG2CACHEDEPTH)
 * @tparam LOG2DATAPERCACHELINECORE param for module pageRankCore, log2 of number of data in one 512bit (64 byte), for
 * double, it's log2(64/sizeof(double)) = 3, for float, it's log2(64/sizeof(float)) = 4
 * @tparam LOG2DATAPERCACHELINEDEGREE param for module calduDegree, log2 of number of data in one 512bit (64 byte), for
 * double, it's log2(64/sizeof(double)) = 3, for float, it's log2(64/sizeof(float)) = 4
 * @tparam RAMTYPE flag to tell use URAM LUTRAM or BRAM, 0 : LUTRAM, 1 : URAM, 2 : BRAM
 *
 * @param numVertex CSR/CSC data offsets number
 * @param numEdge CSR/CSC data indices number
 * @param pagerank output pagerank value
 * @param degreeCSR temporary internal degree value
 * @param offsetCSC temporary internal offset value
 * @param indexCSC CSR/CSC data indice array
 * @param cntValFull temporary internal initialized mulplier values, length equals to numVertex
 * @param buffPing ping array to keep temporary pagerank value
 * @param buffPong pong array to keep temporary pagerank value
 * @param orderUnroll temporary internal order array to keep initialized offset values
 * @param alpha damping factor, normally 0.85
 * @param tolerance converge tolerance
 * @param numIter max iteration
 */

template <typename T,
          int MAXVERTEX,
          int MAXEDGE,
          int LOG2UNROLL,
          int WIDTHOR,
          int LOG2CACHEDEPTH,
          int LOG2DATAPERCACHELINECORE,
          int LOG2DATAPERCACHELINEDEGREE,
          int RAMTYPE>
void pageRankTop(int numVertex,
                 int numEdge,
                 ap_uint<512>* pagerank,
                 ap_uint<512>* degreeCSR,
                 ap_uint<512>* offsetCSC,
                 ap_uint<512>* indexCSC,
                 ap_uint<512>* cntValFull,
                 ap_uint<512>* buffPing,
                 ap_uint<512>* buffPong,
                 ap_uint<WIDTHOR>* orderUnroll,
                 T alpha = 0.85,
                 T tolerance = 1e-4,
                 int numIter = 200) {
    const int BURST_LENTH = 32;
    xf::graph::calcuDegree<MAXVERTEX, MAXEDGE, LOG2CACHEDEPTH, LOG2DATAPERCACHELINEDEGREE, RAMTYPE>(
        numVertex, numEdge, indexCSC, degreeCSR);
    T randomProbability[1];
    internal::pagerank::initDDR<T, BURST_LENTH, MAXVERTEX, MAXEDGE, WIDTHOR>(
        numVertex, numEdge, alpha, randomProbability[0], degreeCSR, offsetCSC, cntValFull, buffPong, orderUnroll);
    pageRankCore<T, MAXVERTEX, MAXEDGE, LOG2UNROLL, WIDTHOR, LOG2CACHEDEPTH, LOG2DATAPERCACHELINECORE, RAMTYPE>(
        numVertex, numEdge, pagerank, buffPing, buffPong, orderUnroll, indexCSC, cntValFull, randomProbability[0],
        alpha, tolerance, numIter);
}

} // namespace graph
} // namespace xf
#endif //#ifndef VT_GRAPH_PR_H
