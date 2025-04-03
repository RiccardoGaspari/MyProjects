#ifndef __ARMA_30_10_BIN_ALLKERNEL_H__
#define __ARMA_30_10_BIN_ALLKERNEL_H__

#include "AutoTilerLibTypes.h"
#include "at_api.h"
#include "ARMA_30_10_Bin_All.h"
#include "CNN_BasicKernels_SQ8.h"
#include "CNN_BasicKernels.h"
#include "CNN_BasicKernels_NE16.h"
#include "Expression_Kernels.h"
#define _ARMA_30_10_Bin_All_L1_Memory_SIZE 3460
#define _ARMA_30_10_Bin_All_L2_Memory_SIZE 1836
#define _ARMA_30_10_Bin_All_L2_Memory_Dyn_SIZE 400
extern char *ARMA_30_10_Bin_All_L1_Memory; /* Size given for generation: 115712 bytes, used: 3460 bytes */
extern char *ARMA_30_10_Bin_All_L2_Memory; /* Size used for generation (static): 1836 bytes */
extern char *ARMA_30_10_Bin_All_L2_Memory_Dyn; /* Size used for generation (dynamic): 400 bytes */
extern void S3_ARMA_30_10_Bin_All_conv2d_Conv2D_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S6_ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		signed char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S7_ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion_trans_out0(
		signed char * __restrict__ In,
		signed char * __restrict__ Out);
extern void S9_ARMA_30_10_Bin_All_global_average_pooling2d_Mean(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void S10_ARMA_30_10_Bin_All_global_average_pooling2d_Mean_qout0(
		signed char * __restrict__ In,
		unsigned char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void S13_ARMA_30_10_Bin_All_dense_MatMul(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		signed char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S15_ARMA_30_10_Bin_All_dense_Softmax(
		signed char * __restrict__ In,
		short int * __restrict__ Out,
		signed char * __restrict__ Infos);
extern int ARMA_30_10_Bin_AllCNN_Construct();
extern void ARMA_30_10_Bin_AllCNN_ConstructCluster();
extern int ARMA_30_10_Bin_AllCNN_Destruct();
extern int ARMA_30_10_Bin_AllCNN_Memory(AT_MEM_TYPE Which);
extern int ARMA_30_10_Bin_AllCNN(
		unsigned char * __restrict__ Input_1,
		signed short * __restrict__ Output_1);
extern unsigned int AT_GraphPerf[8];
extern unsigned int AT_GraphPerf_CNN_Total;
extern char * AT_GraphNodeNames[8];
extern unsigned int AT_GraphOperInfosNames[8];
#endif
