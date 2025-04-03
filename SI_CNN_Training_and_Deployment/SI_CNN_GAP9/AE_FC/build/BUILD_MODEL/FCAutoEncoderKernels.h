#ifndef __FCAUTOENCODERKERNEL_H__
#define __FCAUTOENCODERKERNEL_H__

#include "AutoTilerLibTypes.h"
#include "at_api.h"
#include "FCAutoEncoder.h"
#include "CNN_BasicKernels_SQ8.h"
#include "CNN_BasicKernels.h"
#include "CNN_BasicKernels_NE16.h"
#include "Expression_Kernels.h"
#define _FCAutoEncoder_L1_Memory_SIZE 115340
#define _FCAutoEncoder_L2_Memory_SIZE 358112
#define _FCAutoEncoder_L2_Memory_Dyn_SIZE 768
extern char *FCAutoEncoder_L1_Memory; /* Size given for generation: 115712 bytes, used: 115340 bytes */
extern char *FCAutoEncoder_L2_Memory; /* Size used for generation (static): 358112 bytes */
extern char *FCAutoEncoder_L2_Memory_Dyn; /* Size used for generation (dynamic): 768 bytes */
extern void S3__encoder_encoder_net_encoder_net_0_Gemm_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos,
		unsigned char * __restrict__ SigmoidLUT_u8);
extern void S6__encoder_encoder_net_encoder_net_3_Gemm_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos,
		unsigned char * __restrict__ SigmoidLUT_u8);
extern void S9__encoder_encoder_net_encoder_net_6_Gemm_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos,
		unsigned char * __restrict__ SigmoidLUT_u8);
extern void S12__encoder_encoder_net_encoder_net_9_Gemm_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos,
		unsigned char * __restrict__ SigmoidLUT_u8);
extern void S15__decoder_decoder_net_decoder_net_0_Gemm_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos,
		unsigned char * __restrict__ SigmoidLUT_u8);
extern void S18__decoder_decoder_net_decoder_net_3_Gemm_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos,
		unsigned char * __restrict__ SigmoidLUT_u8);
extern void S21__decoder_decoder_net_decoder_net_6_Gemm_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos,
		unsigned char * __restrict__ SigmoidLUT_u8);
extern void S24__decoder_decoder_net_decoder_net_9_Gemm_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos,
		unsigned char * __restrict__ SigmoidLUT_u8);
extern void S27_expr_0(
		unsigned char * __restrict__ expr_0_in_0,
		signed char * __restrict__ expr_0_in_1,
		signed char * __restrict__ expr_0_in_2,
		unsigned char * __restrict__ expr_0_out_0);
extern int FCAutoEncoderCNN_Construct();
extern void FCAutoEncoderCNN_ConstructCluster();
extern int FCAutoEncoderCNN_Destruct();
extern int FCAutoEncoderCNN_Memory(AT_MEM_TYPE Which);
extern int FCAutoEncoderCNN(
		unsigned char * __restrict__ Input_1,
		unsigned char * __restrict__ Output_1);
extern unsigned int AT_GraphPerf[10];
extern unsigned int AT_GraphPerf_CNN_Total;
extern char * AT_GraphNodeNames[10];
extern unsigned int AT_GraphOperInfosNames[10];
#endif
