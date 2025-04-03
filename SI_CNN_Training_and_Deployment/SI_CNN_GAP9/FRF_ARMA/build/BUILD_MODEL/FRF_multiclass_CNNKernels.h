#ifndef __FRF_MULTICLASS_CNNKERNEL_H__
#define __FRF_MULTICLASS_CNNKERNEL_H__

#include "AutoTilerLibTypes.h"
#include "at_api.h"
#include "FRF_multiclass_CNN.h"
#include "CNN_BasicKernels_SQ8.h"
#include "CNN_BasicKernels.h"
#include "CNN_BasicKernels_NE16.h"
#include "Expression_Kernels.h"
#define _FRF_multiclass_CNN_L1_Memory_SIZE 115604
#define _FRF_multiclass_CNN_L2_Memory_SIZE 387964
#define _FRF_multiclass_CNN_L2_Memory_Dyn_SIZE 52256
extern char *FRF_multiclass_CNN_L1_Memory; /* Size given for generation: 115712 bytes, used: 115604 bytes */
extern char *FRF_multiclass_CNN_L2_Memory; /* Size used for generation (static): 387964 bytes */
extern char *FRF_multiclass_CNN_L2_Memory_Dyn; /* Size used for generation (dynamic): 52256 bytes */
extern void S4__conv1_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S7__conv2_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S10__conv3_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S13__conv4_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S16__conv5_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S19__conv6_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S22__conv7_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S25__conv8_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		signed char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S26__global_avg_pool_GlobalAveragePool_trans(
		signed char * __restrict__ In,
		signed char * __restrict__ Out);
extern void S27__global_avg_pool_GlobalAveragePool(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void S28__global_avg_pool_GlobalAveragePool_qout0(
		signed char * __restrict__ In,
		unsigned char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void S31__fc_Gemm(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		signed char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S33__Softmax(
		signed char * __restrict__ In,
		short int * __restrict__ Out,
		signed char * __restrict__ Infos);
extern int FRF_multiclass_CNNCNN_Construct();
extern void FRF_multiclass_CNNCNN_ConstructCluster();
extern int FRF_multiclass_CNNCNN_Destruct();
extern int FRF_multiclass_CNNCNN_Memory(AT_MEM_TYPE Which);
extern int FRF_multiclass_CNNCNN(
		unsigned char * __restrict__ Input_1,
		signed short * __restrict__ Output_1);
extern unsigned int AT_GraphPerf[14];
extern unsigned int AT_GraphPerf_CNN_Total;
extern char * AT_GraphNodeNames[14];
extern unsigned int AT_GraphOperInfosNames[14];
#endif
