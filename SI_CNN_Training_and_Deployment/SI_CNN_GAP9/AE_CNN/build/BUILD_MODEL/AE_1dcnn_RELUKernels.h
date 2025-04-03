#ifndef __AE_1DCNN_RELUKERNEL_H__
#define __AE_1DCNN_RELUKERNEL_H__

#include "AutoTilerLibTypes.h"
#include "at_api.h"
#include "AE_1dcnn_RELU.h"
#include "CNN_BasicKernels_SQ8.h"
#include "CNN_BasicKernels.h"
#include "CNN_BasicKernels_NE16.h"
#include "Expression_Kernels.h"
#define _AE_1dcnn_RELU_L1_Memory_SIZE 14484
#define _AE_1dcnn_RELU_L2_Memory_SIZE 45940
#define _AE_1dcnn_RELU_L2_Memory_Dyn_SIZE 12288
extern char *AE_1dcnn_RELU_L1_Memory; /* Size given for generation: 115712 bytes, used: 14484 bytes */
extern char *AE_1dcnn_RELU_L2_Memory; /* Size used for generation (static): 45940 bytes */
extern char *AE_1dcnn_RELU_L2_Memory_Dyn; /* Size used for generation (dynamic): 12288 bytes */
extern void S4__encoder_conv_conv_0_backbone_backbone_0_backbone_0_0_Conv_fusion(
		signed char * __restrict__ In,
		signed char * __restrict__ Filter,
		int * __restrict__ Bias,
		signed char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S7__encoder_conv_conv_0_backbone_backbone_1_backbone_1_0_Conv_fusion(
		signed char * __restrict__ In,
		signed char * __restrict__ Filter,
		int * __restrict__ Bias,
		signed char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S10__encoder_conv_conv_0_projection_Conv(
		signed char * __restrict__ In,
		signed char * __restrict__ Filter,
		int * __restrict__ Bias,
		signed char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S11_expr_0(
		signed char * __restrict__ expr_0_in_0,
		signed char * __restrict__ expr_0_in_1,
		signed char * __restrict__ expr_0_out_0);
extern void S14__encoder_conv_conv_0_downsampling_Conv(
		signed char * __restrict__ In,
		signed char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S17__encoder_conv_conv_1_backbone_backbone_0_backbone_0_0_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S20__encoder_conv_conv_1_backbone_backbone_1_backbone_1_0_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S23__encoder_conv_conv_1_projection_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S24_expr_1(
		unsigned char * __restrict__ expr_1_in_0,
		unsigned char * __restrict__ expr_1_in_1,
		unsigned char * __restrict__ expr_1_out_0);
extern void S27__encoder_conv_conv_1_downsampling_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S30__encoder_conv_conv_2_backbone_backbone_0_backbone_0_0_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S33__encoder_conv_conv_2_backbone_backbone_1_backbone_1_0_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S36__encoder_conv_conv_2_projection_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S37_expr_2(
		unsigned char * __restrict__ expr_2_in_0,
		unsigned char * __restrict__ expr_2_in_1,
		unsigned char * __restrict__ expr_2_out_0);
extern void S40__encoder_conv_conv_2_downsampling_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S43__encoder_conv_conv_3_backbone_backbone_0_backbone_0_0_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S46__encoder_conv_conv_3_backbone_backbone_1_backbone_1_0_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S49__encoder_conv_conv_3_projection_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S50_expr_3(
		unsigned char * __restrict__ expr_3_in_0,
		unsigned char * __restrict__ expr_3_in_1,
		unsigned char * __restrict__ expr_3_out_0);
extern void S53__encoder_conv_conv_3_downsampling_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S56__decoder_deconv_deconv_0_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S59__decoder_deconv_deconv_0_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S60_expr_4(
		unsigned char * __restrict__ expr_4_in_0,
		unsigned char * __restrict__ expr_4_in_1,
		unsigned char * __restrict__ expr_4_out_0);
extern void S63__decoder_deconv_deconv_0_upsampling_ConvTranspose(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S66__decoder_deconv_deconv_1_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S69__decoder_deconv_deconv_1_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S70_expr_5(
		unsigned char * __restrict__ expr_5_in_0,
		unsigned char * __restrict__ expr_5_in_1,
		unsigned char * __restrict__ expr_5_out_0);
extern void S73__decoder_deconv_deconv_1_upsampling_ConvTranspose(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S76__decoder_deconv_deconv_2_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S79__decoder_deconv_deconv_2_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S80_expr_6(
		unsigned char * __restrict__ expr_6_in_0,
		unsigned char * __restrict__ expr_6_in_1,
		unsigned char * __restrict__ expr_6_out_0);
extern void S83__decoder_deconv_deconv_2_upsampling_ConvTranspose(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S86__decoder_deconv_deconv_3_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S89__decoder_deconv_deconv_3_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S90_expr_7(
		unsigned char * __restrict__ expr_7_in_0,
		unsigned char * __restrict__ expr_7_in_1,
		unsigned char * __restrict__ expr_7_out_0);
extern void S93__decoder_deconv_deconv_3_upsampling_ConvTranspose(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S96__decoder_deconv_deconv_4_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern int AE_1dcnn_RELUCNN_Construct();
extern void AE_1dcnn_RELUCNN_ConstructCluster();
extern int AE_1dcnn_RELUCNN_Destruct();
extern int AE_1dcnn_RELUCNN_Memory(AT_MEM_TYPE Which);
extern int AE_1dcnn_RELUCNN(
		signed char * __restrict__ Input_1,
		unsigned char * __restrict__ Output_1);
extern unsigned int AT_GraphPerf[38];
extern unsigned int AT_GraphPerf_CNN_Total;
extern char * AT_GraphNodeNames[38];
extern unsigned int AT_GraphOperInfosNames[38];
#endif
