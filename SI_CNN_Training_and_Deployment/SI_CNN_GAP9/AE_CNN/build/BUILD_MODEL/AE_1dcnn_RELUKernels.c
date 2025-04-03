#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#include "AE_1dcnn_RELUKernels.h"
#ifdef __EMUL__
unsigned int __L3_Read, __L3_Write, __L2_Read, __L2_Write;
#endif
L1_CL_MEM AT_L1_POINTER AE_1dcnn_RELU_L1_Memory;
L2_MEM AT_L2_POINTER AE_1dcnn_RELU_L2_Memory;
L2_MEM AT_L2_POINTER AE_1dcnn_RELU_L2_Memory_Dyn;
static AT_DEFAULTFLASH_FS_T DefaultFlash;
void  S4__encoder_conv_conv_0_backbone_backbone_0_backbone_0_0_Conv_fusion(
		signed char * __restrict__ In,
		signed char * __restrict__ Filter,
		int * __restrict__ Bias,
		signed char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 3616 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;
	KerConv_SQ8_T S_KerArg1, *KerArg1 = &S_KerArg1;
	KerConvLinReduct_SQ8_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1][D0 Dim: Init: 1, Tiled: 1]
	Ker Arg: PermOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 512 (Total Size: 512 )[D0, [0 x 512, 512]][Tile0, 1:[512x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[512x1], 1][D0, [0 x 512, 512]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 512 )[Tile0, 1:[512x1], 1][D0, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[512x1], 1][D0, [0 x 1, 1]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1024 (Total Size: 4 )[D0, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 4, 4]]
		Tile0: [0, 4, 4], Tile1: [0, 4, 4], Tile2; [0, 4, 4]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1028 (Total Size: 1 )[D0, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 1, 1]]
		Tile0: [0, 1, 1], Tile1: [0, 1, 1], Tile2; [0, 1, 1]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1032 (Total Size: 1 )[D0, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 1, 1]]
		Tile0: [0, 1, 1], Tile1: [0, 1, 1], Tile2; [0, 1, 1]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1036 (Total Size: 3 )[D0, [0 x 3, 3]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 3, 3]]
		Tile0: [0, 3, 3], Tile1: [0, 3, 3], Tile2; [0, 3, 3]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1040 (Total Size: 512 )[Tile0, 1:[512x1], 1][D0, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[512x1], 1][D0, [0 x 1, 1]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: ConvOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1552 (Total Size: 2048 )[Tile0, 1:[512x1], 4][D0, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[512x1], 4][D0, [0 x 4, 4]]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3600 (Total Size: 13 )[Tile0, 1:[1x1], 13]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 13]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (void *__restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg0->Out = (void *__restrict__) (AE_1dcnn_RELU_L1_Memory+512);
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (512);
	KerArg0->H = (unsigned short int) (1);
	KerArg1->In = (signed char * __restrict__) (AE_1dcnn_RELU_L1_Memory+512);
	KerArg1->W = (unsigned short int) (512);
	KerArg1->UsedW = (unsigned short int) (512);
	KerArg1->H = (unsigned short int) (1);
	KerArg1->InFeatures = (unsigned short int) (1);
	KerArg1->OutFeatures = (unsigned short int) (1);
	KerArg1->TotalInFeatures = (unsigned short int) (1);
	KerArg1->Filter = (signed char * __restrict__) (AE_1dcnn_RELU_L1_Memory+1036);
	KerArg1->Bias = (signed char * __restrict__) (AE_1dcnn_RELU_L1_Memory+1024);
	KerArg1->Out = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+1552);
	KerArg1->Pad = (v4s) ((v4s){1,1,0,0});
	KerArg1->ExplPad = (unsigned char) (0);
	KerArg2->In = (int *__restrict__) (AE_1dcnn_RELU_L1_Memory+1552);
	KerArg2->Out = (void *__restrict__) (AE_1dcnn_RELU_L1_Memory+1040);
	KerArg2->Feat = (unsigned short int) (1);
	KerArg2->W = (unsigned short int) (512);
	KerArg2->H = (unsigned short int) (1);
	KerArg2->Scale = (unsigned char *__restrict__) (AE_1dcnn_RELU_L1_Memory+1028);
	KerArg2->ScaleN = (unsigned char *__restrict__) (AE_1dcnn_RELU_L1_Memory+1032);
	KerArg2->Infos = (signed char *__restrict__) (AE_1dcnn_RELU_L1_Memory+3600);
	KerArg2->Extra = (void *) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+0), 512, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+3600), 13, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1024), 4, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1036), 3, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1028), 1, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1032), 1, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		{ /* Single iteration on D0 */
			int D0Ind_Last = 1;
			/*====================== Call Kernel LOC_D0 =========================*/
			AT_FORK(gap_ncore(), (void *) CNN_MatPermHWC2CHW_fps, (void *) KerArg0);
			__CALL(CNN_MatPermHWC2CHW_fps, KerArg0);
			KerArg1->UsedH = (unsigned short int) (1);
			KerArg1->NormBias = (unsigned char) (((char *)(AE_1dcnn_RELU_L1_Memory+3600))[8]);
			AT_FORK(gap_ncore(), (void *) KerParConvDW3x1Stride1x1B32_SQ8, (void *) KerArg1);
			__CALL(KerParConvDW3x1Stride1x1B32_SQ8, KerArg1);
			AT_FORK(gap_ncore(), (void *) KerParReduct_CC_CHW2HWC_ReLU_SQ8, (void *) KerArg2);
			__CALL(KerParReduct_CC_CHW2HWC_ReLU_SQ8, KerArg2);
		} /* End iteration on D0 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1040), 512, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S7__encoder_conv_conv_0_backbone_backbone_1_backbone_1_0_Conv_fusion(
		signed char * __restrict__ In,
		signed char * __restrict__ Filter,
		int * __restrict__ Bias,
		signed char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 3616 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;
	KerConv_SQ8_T S_KerArg1, *KerArg1 = &S_KerArg1;
	KerConvLinReduct_SQ8_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1][D0 Dim: Init: 1, Tiled: 1]
	Ker Arg: PermOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 512 (Total Size: 512 )[D0, [0 x 512, 512]][Tile0, 1:[512x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[512x1], 1][D0, [0 x 512, 512]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 512 )[Tile0, 1:[512x1], 1][D0, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[512x1], 1][D0, [0 x 1, 1]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1024 (Total Size: 4 )[D0, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 4, 4]]
		Tile0: [0, 4, 4], Tile1: [0, 4, 4], Tile2; [0, 4, 4]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1028 (Total Size: 1 )[D0, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 1, 1]]
		Tile0: [0, 1, 1], Tile1: [0, 1, 1], Tile2; [0, 1, 1]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1032 (Total Size: 1 )[D0, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 1, 1]]
		Tile0: [0, 1, 1], Tile1: [0, 1, 1], Tile2; [0, 1, 1]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1036 (Total Size: 3 )[D0, [0 x 3, 3]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 3, 3]]
		Tile0: [0, 3, 3], Tile1: [0, 3, 3], Tile2; [0, 3, 3]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1040 (Total Size: 512 )[Tile0, 1:[512x1], 1][D0, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[512x1], 1][D0, [0 x 1, 1]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: ConvOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1552 (Total Size: 2048 )[Tile0, 1:[512x1], 4][D0, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[512x1], 4][D0, [0 x 4, 4]]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3600 (Total Size: 13 )[Tile0, 1:[1x1], 13]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 13]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (void *__restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg0->Out = (void *__restrict__) (AE_1dcnn_RELU_L1_Memory+512);
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (512);
	KerArg0->H = (unsigned short int) (1);
	KerArg1->In = (signed char * __restrict__) (AE_1dcnn_RELU_L1_Memory+512);
	KerArg1->W = (unsigned short int) (512);
	KerArg1->UsedW = (unsigned short int) (512);
	KerArg1->H = (unsigned short int) (1);
	KerArg1->InFeatures = (unsigned short int) (1);
	KerArg1->OutFeatures = (unsigned short int) (1);
	KerArg1->TotalInFeatures = (unsigned short int) (1);
	KerArg1->Filter = (signed char * __restrict__) (AE_1dcnn_RELU_L1_Memory+1036);
	KerArg1->Bias = (signed char * __restrict__) (AE_1dcnn_RELU_L1_Memory+1024);
	KerArg1->Out = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+1552);
	KerArg1->Pad = (v4s) ((v4s){1,1,0,0});
	KerArg1->ExplPad = (unsigned char) (0);
	KerArg2->In = (int *__restrict__) (AE_1dcnn_RELU_L1_Memory+1552);
	KerArg2->Out = (void *__restrict__) (AE_1dcnn_RELU_L1_Memory+1040);
	KerArg2->Feat = (unsigned short int) (1);
	KerArg2->W = (unsigned short int) (512);
	KerArg2->H = (unsigned short int) (1);
	KerArg2->Scale = (unsigned char *__restrict__) (AE_1dcnn_RELU_L1_Memory+1028);
	KerArg2->ScaleN = (unsigned char *__restrict__) (AE_1dcnn_RELU_L1_Memory+1032);
	KerArg2->Infos = (signed char *__restrict__) (AE_1dcnn_RELU_L1_Memory+3600);
	KerArg2->Extra = (void *) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+0), 512, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+3600), 13, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1024), 4, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1036), 3, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1028), 1, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1032), 1, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		{ /* Single iteration on D0 */
			int D0Ind_Last = 1;
			/*====================== Call Kernel LOC_D0 =========================*/
			AT_FORK(gap_ncore(), (void *) CNN_MatPermHWC2CHW_fps, (void *) KerArg0);
			__CALL(CNN_MatPermHWC2CHW_fps, KerArg0);
			KerArg1->UsedH = (unsigned short int) (1);
			KerArg1->NormBias = (unsigned char) (((char *)(AE_1dcnn_RELU_L1_Memory+3600))[8]);
			AT_FORK(gap_ncore(), (void *) KerParConvDW3x1Stride1x1B32_SQ8, (void *) KerArg1);
			__CALL(KerParConvDW3x1Stride1x1B32_SQ8, KerArg1);
			AT_FORK(gap_ncore(), (void *) KerParReduct_CC_CHW2HWC_SQ8, (void *) KerArg2);
			__CALL(KerParReduct_CC_CHW2HWC_SQ8, KerArg2);
		} /* End iteration on D0 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1040), 512, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S10__encoder_conv_conv_0_projection_Conv(
		signed char * __restrict__ In,
		signed char * __restrict__ Filter,
		int * __restrict__ Bias,
		signed char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 3616 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;
	KerConv_SQ8_T S_KerArg1, *KerArg1 = &S_KerArg1;
	KerConvLinReduct_SQ8_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1][D0 Dim: Init: 1, Tiled: 1]
	Ker Arg: PermOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 512 (Total Size: 512 )[D0, [0 x 512, 512]][Tile0, 1:[512x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[512x1], 1][D0, [0 x 512, 512]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 512 )[Tile0, 1:[512x1], 1][D0, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[512x1], 1][D0, [0 x 1, 1]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1024 (Total Size: 4 )[D0, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 4, 4]]
		Tile0: [0, 4, 4], Tile1: [0, 4, 4], Tile2; [0, 4, 4]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1028 (Total Size: 1 )[D0, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 1, 1]]
		Tile0: [0, 1, 1], Tile1: [0, 1, 1], Tile2; [0, 1, 1]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1032 (Total Size: 1 )[D0, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 1, 1]]
		Tile0: [0, 1, 1], Tile1: [0, 1, 1], Tile2; [0, 1, 1]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1036 (Total Size: 1 )[D0, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 1, 1]]
		Tile0: [0, 1, 1], Tile1: [0, 1, 1], Tile2; [0, 1, 1]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1040 (Total Size: 512 )[Tile0, 1:[512x1], 1][D0, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[512x1], 1][D0, [0 x 1, 1]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: ConvOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1552 (Total Size: 2048 )[Tile0, 1:[512x1], 4][D0, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[512x1], 4][D0, [0 x 4, 4]]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3600 (Total Size: 13 )[Tile0, 1:[1x1], 13]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 13]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (void *__restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg0->Out = (void *__restrict__) (AE_1dcnn_RELU_L1_Memory+512);
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (512);
	KerArg0->H = (unsigned short int) (1);
	KerArg1->In = (signed char * __restrict__) (AE_1dcnn_RELU_L1_Memory+512);
	KerArg1->W = (unsigned short int) (512);
	KerArg1->UsedW = (unsigned short int) (512);
	KerArg1->H = (unsigned short int) (1);
	KerArg1->InFeatures = (unsigned short int) (1);
	KerArg1->OutFeatures = (unsigned short int) (1);
	KerArg1->TotalInFeatures = (unsigned short int) (1);
	KerArg1->Filter = (signed char * __restrict__) (AE_1dcnn_RELU_L1_Memory+1036);
	KerArg1->Bias = (signed char * __restrict__) (AE_1dcnn_RELU_L1_Memory+1024);
	KerArg1->Out = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+1552);
	KerArg1->Pad = (v4s) 0;
	KerArg1->ExplPad = (unsigned char) (0);
	KerArg2->In = (int *__restrict__) (AE_1dcnn_RELU_L1_Memory+1552);
	KerArg2->Out = (void *__restrict__) (AE_1dcnn_RELU_L1_Memory+1040);
	KerArg2->Feat = (unsigned short int) (1);
	KerArg2->W = (unsigned short int) (512);
	KerArg2->H = (unsigned short int) (1);
	KerArg2->Scale = (unsigned char *__restrict__) (AE_1dcnn_RELU_L1_Memory+1028);
	KerArg2->ScaleN = (unsigned char *__restrict__) (AE_1dcnn_RELU_L1_Memory+1032);
	KerArg2->Infos = (signed char *__restrict__) (AE_1dcnn_RELU_L1_Memory+3600);
	KerArg2->Extra = (void *) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+0), 512, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+3600), 13, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1024), 4, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1028), 1, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1032), 1, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1036), 1, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Filter */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		{ /* Single iteration on D0 */
			int D0Ind_Last = 1;
			/*====================== Call Kernel LOC_D0 =========================*/
			AT_FORK(gap_ncore(), (void *) CNN_MatPermHWC2CHW_fps, (void *) KerArg0);
			__CALL(CNN_MatPermHWC2CHW_fps, KerArg0);
			KerArg1->UsedH = (unsigned short int) (1);
			KerArg1->NormBias = (unsigned char) (((char *)(AE_1dcnn_RELU_L1_Memory+3600))[8]);
			AT_FORK(gap_ncore(), (void *) KerParConvDW1x1Stride1B32_SQ8, (void *) KerArg1);
			__CALL(KerParConvDW1x1Stride1B32_SQ8, KerArg1);
			AT_FORK(gap_ncore(), (void *) KerParReduct_CC_CHW2HWC_SQ8, (void *) KerArg2);
			__CALL(KerParReduct_CC_CHW2HWC_SQ8, KerArg2);
		} /* End iteration on D0 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1040), 512, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S11_expr_0(
		signed char * __restrict__ expr_0_in_0,
		signed char * __restrict__ expr_0_in_1,
		signed char * __restrict__ expr_0_out_0)

{
	/* Shared L1: 1536 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	s11_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 512, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_0_out_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 512 )[D0, [0 x 512, 512]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 512, 512]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: expr_0_in_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 512 (Total Size: 512 )[D0, [0 x 512, 512]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 512, 512]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: expr_0_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1024 (Total Size: 512 )[D0, [0 x 512, 512]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 512, 512]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (512);
	KerArg0->expr_0_in_0 = (signed char *__restrict__ ) (AE_1dcnn_RELU_L1_Memory+512);
	KerArg0->expr_0_in_1 = (signed char *__restrict__ ) (AE_1dcnn_RELU_L1_Memory+1024);
	KerArg0->expr_0_out_0 = (signed char *__restrict__ ) (AE_1dcnn_RELU_L1_Memory+0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_0_in_0+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+512), 512, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_0_in_1+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1024), 512, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_0_in_1 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_D0 =========================*/
		AT_FORK(gap_ncore(), (void *) s11_kernel, (void *) KerArg0);
		__CALL(s11_kernel, KerArg0);
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_0_out_0+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+0), 512, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write expr_0_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S14__encoder_conv_conv_0_downsampling_Conv(
		signed char * __restrict__ In,
		signed char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 2340 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;
	KerConv_SQ8_T S_KerArg1, *KerArg1 = &S_KerArg1;
	KerConvLinReduct_SQ8_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1][D0 Dim: Init: 1, Tiled: 1]
	Ker Arg: PermOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 512 (Total Size: 512 )[D0, [0 x 512, 512]][Tile0, 1:[512x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[512x1], 1][D0, [0 x 512, 512]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 512 )[Tile0, 1:[512x1], 1][D0, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[512x1], 1][D0, [0 x 1, 1]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1024 (Total Size: 4 )[D0, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 4, 4]]
		Tile0: [0, 4, 4], Tile1: [0, 4, 4], Tile2; [0, 4, 4]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1028 (Total Size: 1 )[D0, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 1, 1]]
		Tile0: [0, 1, 1], Tile1: [0, 1, 1], Tile2; [0, 1, 1]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1032 (Total Size: 1 )[D0, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 1, 1]]
		Tile0: [0, 1, 1], Tile1: [0, 1, 1], Tile2; [0, 1, 1]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1036 (Total Size: 7 )[D0, [0 x 7, 7]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 7, 7]]
		Tile0: [0, 7, 7], Tile1: [0, 7, 7], Tile2; [0, 7, 7]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1044 (Total Size: 256 )[Tile0, 1:[256x1], 1][D0, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[256x1], 1][D0, [0 x 1, 1]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: ConvOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1300 (Total Size: 1024 )[Tile0, 1:[256x1], 4][D0, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[256x1], 4][D0, [0 x 4, 4]]
		Tile0: [0, 1024, 1024], Tile1: [0, 1024, 1024], Tile2; [0, 1024, 1024]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2324 (Total Size: 13 )[Tile0, 1:[1x1], 13]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 13]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (void *__restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg0->Out = (void *__restrict__) (AE_1dcnn_RELU_L1_Memory+512);
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (512);
	KerArg0->H = (unsigned short int) (1);
	KerArg1->In = (signed char * __restrict__) (AE_1dcnn_RELU_L1_Memory+512);
	KerArg1->W = (unsigned short int) (512);
	KerArg1->UsedW = (unsigned short int) (512);
	KerArg1->H = (unsigned short int) (1);
	KerArg1->InFeatures = (unsigned short int) (1);
	KerArg1->OutFeatures = (unsigned short int) (1);
	KerArg1->TotalInFeatures = (unsigned short int) (1);
	KerArg1->Filter = (signed char * __restrict__) (AE_1dcnn_RELU_L1_Memory+1036);
	KerArg1->Bias = (signed char * __restrict__) (AE_1dcnn_RELU_L1_Memory+1024);
	KerArg1->Out = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+1300);
	KerArg1->Pad = (v4s) ((v4s){3,2,0,0});
	KerArg1->ExplPad = (unsigned char) (1);
	KerArg1->N = (unsigned short) (7);
	KerArg1->S = (unsigned char) (2);
	KerArg1->Ny = (unsigned short) (1);
	KerArg1->Sy = (unsigned char) (1);
	KerArg2->In = (int *__restrict__) (AE_1dcnn_RELU_L1_Memory+1300);
	KerArg2->Out = (void *__restrict__) (AE_1dcnn_RELU_L1_Memory+1044);
	KerArg2->Feat = (unsigned short int) (1);
	KerArg2->W = (unsigned short int) (256);
	KerArg2->H = (unsigned short int) (1);
	KerArg2->Scale = (unsigned char *__restrict__) (AE_1dcnn_RELU_L1_Memory+1028);
	KerArg2->ScaleN = (unsigned char *__restrict__) (AE_1dcnn_RELU_L1_Memory+1032);
	KerArg2->Infos = (signed char *__restrict__) (AE_1dcnn_RELU_L1_Memory+2324);
	KerArg2->Extra = (void *) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+0), 512, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+2324), 13, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1036), 7, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1024), 4, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1028), 1, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1032), 1, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		{ /* Single iteration on D0 */
			int D0Ind_Last = 1;
			/*====================== Call Kernel LOC_D0 =========================*/
			AT_FORK(gap_ncore(), (void *) CNN_MatPermHWC2CHW_fps, (void *) KerArg0);
			__CALL(CNN_MatPermHWC2CHW_fps, KerArg0);
			KerArg1->UsedH = (unsigned short int) (1);
			KerArg1->NormBias = (unsigned char) (((char *)(AE_1dcnn_RELU_L1_Memory+2324))[8]);
			AT_FORK(gap_ncore(), (void *) KerParConvDWNxMStrideSxSyB32_SQ8, (void *) KerArg1);
			__CALL(KerParConvDWNxMStrideSxSyB32_SQ8, KerArg1);
			AT_FORK(gap_ncore(), (void *) KerParReduct_CC_CHW2HWC_USQ8, (void *) KerArg2);
			__CALL(KerParReduct_CC_CHW2HWC_USQ8, KerArg2);
		} /* End iteration on D0 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1044), 256, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S17__encoder_conv_conv_1_backbone_backbone_0_backbone_0_0_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 892 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 2, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 1, Tiled: 1]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 54 )[Tile0, 1:[54x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[54x1], 1]
		Tile0: [0, 54, 54], Tile1: [0, 54, 54], Tile2; [0, 54, 54]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 56 (Total Size: 256 )[Tile0, 1:[256x1], 1][D0, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[256x1], 1][D0, [0 x 1, 1]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 312 (Total Size: 8 )[D1, [0 x 8, 8]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 8, 8]]
		Tile0: [0, 8, 8], Tile1: [0, 8, 8], Tile2; [0, 8, 8]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 320 (Total Size: 2 )[D1, [0 x 2, 2]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2, 2]]
		Tile0: [0, 2, 2], Tile1: [0, 2, 2], Tile2; [0, 2, 2]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 324 (Total Size: 2 )[D1, [0 x 2, 2]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2, 2]]
		Tile0: [0, 2, 2], Tile1: [0, 2, 2], Tile2; [0, 2, 2]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 328 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 360 (Total Size: 512 )[Tile0, 1:[256x1], 2][D1, [0 x 2, 2]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2, 2]][Tile0, 1:[256x1], 2]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 872 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+56);
	KerArg2->ColBuff = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (AE_1dcnn_RELU_L1_Memory+328);
	KerArg2->Bias = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+312);
	KerArg2->Out = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+360);
	KerArg2->Scale = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+320);
	KerArg2->ScaleN = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+324);
	KerArg2->Tile_InFeat = (unsigned short int) (1);
	KerArg2->TotalInFeatures = (unsigned short int) (1);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (256);
	KerArg2->Tile_OutFeat = (unsigned short int) (2);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (256);
	KerArg2->Pad_Val = (unsigned short int) (66);
	KerArg2->Pad = (v4s) ((v4s){1,1,0,0});
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->FirstTile = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (3);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+56), 256, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+328), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+872), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+312), 8, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+320), 2, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+324), 2, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->W_Offset = (int) (((int *)(AE_1dcnn_RELU_L1_Memory+872))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+360), 512, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S20__encoder_conv_conv_1_backbone_backbone_1_backbone_1_0_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 1200 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 2, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 2, Tiled: 1]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 108 )[Tile0, 1:[108x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[108x1], 1]
		Tile0: [0, 108, 108], Tile1: [0, 108, 108], Tile2; [0, 108, 108]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 108 (Total Size: 512 )[Tile0, 1:[256x1], 2][D0, [0 x 2, 2]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[256x1], 2][D0, [0 x 2, 2]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 620 (Total Size: 8 )[D1, [0 x 8, 8]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 8, 8]]
		Tile0: [0, 8, 8], Tile1: [0, 8, 8], Tile2; [0, 8, 8]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 628 (Total Size: 2 )[D1, [0 x 2, 2]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2, 2]]
		Tile0: [0, 2, 2], Tile1: [0, 2, 2], Tile2; [0, 2, 2]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 632 (Total Size: 2 )[D1, [0 x 2, 2]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2, 2]]
		Tile0: [0, 2, 2], Tile1: [0, 2, 2], Tile2; [0, 2, 2]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 636 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 668 (Total Size: 512 )[Tile0, 1:[256x1], 2][D1, [0 x 2, 2]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2, 2]][Tile0, 1:[256x1], 2]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1180 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+108);
	KerArg2->ColBuff = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (AE_1dcnn_RELU_L1_Memory+636);
	KerArg2->Bias = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+620);
	KerArg2->Out = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+668);
	KerArg2->Scale = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+628);
	KerArg2->ScaleN = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+632);
	KerArg2->Tile_InFeat = (unsigned short int) (2);
	KerArg2->TotalInFeatures = (unsigned short int) (2);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (256);
	KerArg2->Tile_OutFeat = (unsigned short int) (2);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (256);
	KerArg2->Pad_Val = (unsigned short int) (0);
	KerArg2->Pad = (v4s) ((v4s){1,1,0,0});
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->FirstTile = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (3);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+108), 512, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+636), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1180), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+620), 8, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+628), 2, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+632), 2, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->W_Offset = (int) (((int *)(AE_1dcnn_RELU_L1_Memory+1180))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+668), 512, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S23__encoder_conv_conv_1_projection_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 836 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 2, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 1, Tiled: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 256 )[Tile0, 1:[256x1], 1][D0, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[256x1], 1][D0, [0 x 1, 1]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 256 (Total Size: 8 )[D1, [0 x 8, 8]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 8, 8]]
		Tile0: [0, 8, 8], Tile1: [0, 8, 8], Tile2; [0, 8, 8]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 264 (Total Size: 2 )[D1, [0 x 2, 2]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2, 2]]
		Tile0: [0, 2, 2], Tile1: [0, 2, 2], Tile2; [0, 2, 2]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 268 (Total Size: 2 )[D1, [0 x 2, 2]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2, 2]]
		Tile0: [0, 2, 2], Tile1: [0, 2, 2], Tile2; [0, 2, 2]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 272 (Total Size: 32 )[D1, [0 x 32, 32]][D0, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]][D0, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 304 (Total Size: 512 )[Tile0, 1:[256x1], 2][D1, [0 x 2, 2]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2, 2]][Tile0, 1:[256x1], 2]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 816 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+0), 256, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+272), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+816), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+256), 8, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+264), 2, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+268), 2, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerConv1x1_SmallHW_Stride1_NE16Seq(
					(unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+0),  // In
					(unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+304),  // Out
					(int * __restrict__) (AE_1dcnn_RELU_L1_Memory+256),  // Bias
					(unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+272),  // Filter
					(unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+264),  // Scale
					(unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+268),  // ScaleN
					(unsigned int) (((1) % (16))?(((1) / (16)) + (1)):((1) / (16))),  // Nb_KI
					(unsigned int) (((1) % (16))?((1) % (16)):(16)),  // Rem_KI
					(unsigned int) (((2) % (32))?(((2) / (32)) + (1)):((2) / (32))),  // Nb_KO
					(unsigned int) (((2) % (32))?((2) % (32)):(32)),  // Rem_KO
					(unsigned int) (((1) * (256)) / (3)),  // Nb_HO
					(unsigned int) (((1) * (256)) % (3)),  // Rem_HO
					(unsigned int) (0),  // Nb_WO
					(unsigned int) (0),  // Rem_WO
					(unsigned int) (0),  // Rem_HI
					(unsigned int) (0),  // Rem_WI
					(unsigned int) ((1) * (1)),  // InD0
					(unsigned int) (((1) * (256)) * (1)),  // InD1
					(unsigned int) (0),  // InD2
					(unsigned int) (16),  // WD0
					(unsigned int) (0),  // WD1
					(unsigned int) (0),  // WD2
					(unsigned int) (0),  // OutD0
					(unsigned int) ((2) * (1)),  // OutD1
					(unsigned int) (0),  // OutD2
					(v4s) 0,  // Pad
					(unsigned int) (66),  // PadVal
					(unsigned int) (((int *)(AE_1dcnn_RELU_L1_Memory+816))[4]),  // WOffset
					(unsigned char) ((1)),  // LastD0
					(unsigned char) ((1)),  // FirstD0
					(unsigned int) (50364503)  // NE16JobCfg
				);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+304), 512, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S24_expr_1(
		unsigned char * __restrict__ expr_1_in_0,
		unsigned char * __restrict__ expr_1_in_1,
		unsigned char * __restrict__ expr_1_out_0)

{
	/* Shared L1: 1536 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	s24_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 512, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_1_out_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 512 )[D0, [0 x 512, 512]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 512, 512]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: expr_1_in_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 512 (Total Size: 512 )[D0, [0 x 512, 512]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 512, 512]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: expr_1_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1024 (Total Size: 512 )[D0, [0 x 512, 512]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 512, 512]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (512);
	KerArg0->expr_1_in_0 = (unsigned char *__restrict__ ) (AE_1dcnn_RELU_L1_Memory+512);
	KerArg0->expr_1_in_1 = (unsigned char *__restrict__ ) (AE_1dcnn_RELU_L1_Memory+1024);
	KerArg0->expr_1_out_0 = (unsigned char *__restrict__ ) (AE_1dcnn_RELU_L1_Memory+0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_1_in_0+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+512), 512, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_1_in_1+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1024), 512, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_1_in_1 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_D0 =========================*/
		AT_FORK(gap_ncore(), (void *) s24_kernel, (void *) KerArg0);
		__CALL(s24_kernel, KerArg0);
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_1_out_0+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+0), 512, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write expr_1_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S27__encoder_conv_conv_1_downsampling_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 1088 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 2, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 2, Tiled: 1]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 252 )[Tile0, 1:[252x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[252x1], 1]
		Tile0: [0, 252, 252], Tile1: [0, 252, 252], Tile2; [0, 252, 252]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 252 (Total Size: 512 )[Tile0, 1:[256x1], 2][D0, [0 x 2, 2]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[256x1], 2][D0, [0 x 2, 2]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 764 (Total Size: 8 )[D1, [0 x 8, 8]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 8, 8]]
		Tile0: [0, 8, 8], Tile1: [0, 8, 8], Tile2; [0, 8, 8]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 772 (Total Size: 2 )[D1, [0 x 2, 2]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2, 2]]
		Tile0: [0, 2, 2], Tile1: [0, 2, 2], Tile2; [0, 2, 2]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 776 (Total Size: 2 )[D1, [0 x 2, 2]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2, 2]]
		Tile0: [0, 2, 2], Tile1: [0, 2, 2], Tile2; [0, 2, 2]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 780 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 812 (Total Size: 256 )[Tile0, 1:[128x1], 2][D1, [0 x 2, 2]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2, 2]][Tile0, 1:[128x1], 2]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1068 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+252);
	KerArg2->ColBuff = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (AE_1dcnn_RELU_L1_Memory+780);
	KerArg2->Bias = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+764);
	KerArg2->Out = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+812);
	KerArg2->Scale = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+772);
	KerArg2->ScaleN = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+776);
	KerArg2->Tile_InFeat = (unsigned short int) (2);
	KerArg2->TotalInFeatures = (unsigned short int) (2);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (256);
	KerArg2->Tile_OutFeat = (unsigned short int) (2);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (128);
	KerArg2->Pad_Val = (unsigned short int) (156);
	KerArg2->Pad = (v4s) ((v4s){3,2,0,0});
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->FirstTile = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (7);
	KerArg2->Sx = (unsigned short) (2);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+252), 512, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+780), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1068), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+764), 8, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+772), 2, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+776), 2, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->W_Offset = (int) (((int *)(AE_1dcnn_RELU_L1_Memory+1068))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+812), 256, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S30__encoder_conv_conv_2_backbone_backbone_0_backbone_0_0_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 984 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 4, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 2, Tiled: 1]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 108 )[Tile0, 1:[108x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[108x1], 1]
		Tile0: [0, 108, 108], Tile1: [0, 108, 108], Tile2; [0, 108, 108]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 108 (Total Size: 256 )[Tile0, 1:[128x1], 2][D0, [0 x 2, 2]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[128x1], 2][D0, [0 x 2, 2]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 364 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 380 (Total Size: 4 )[D1, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 4, 4]]
		Tile0: [0, 4, 4], Tile1: [0, 4, 4], Tile2; [0, 4, 4]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 384 (Total Size: 4 )[D1, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 4, 4]]
		Tile0: [0, 4, 4], Tile1: [0, 4, 4], Tile2; [0, 4, 4]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 388 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 452 (Total Size: 512 )[Tile0, 1:[128x1], 4][D1, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 4, 4]][Tile0, 1:[128x1], 4]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 964 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+108);
	KerArg2->ColBuff = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (AE_1dcnn_RELU_L1_Memory+388);
	KerArg2->Bias = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+364);
	KerArg2->Out = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+452);
	KerArg2->Scale = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+380);
	KerArg2->ScaleN = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+384);
	KerArg2->Tile_InFeat = (unsigned short int) (2);
	KerArg2->TotalInFeatures = (unsigned short int) (2);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (128);
	KerArg2->Tile_OutFeat = (unsigned short int) (4);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (128);
	KerArg2->Pad_Val = (unsigned short int) (220);
	KerArg2->Pad = (v4s) ((v4s){1,1,0,0});
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->FirstTile = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (3);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+108), 256, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+388), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+964), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+364), 16, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+380), 4, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+384), 4, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->W_Offset = (int) (((int *)(AE_1dcnn_RELU_L1_Memory+964))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+452), 512, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S33__encoder_conv_conv_2_backbone_backbone_1_backbone_1_0_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 1348 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 4, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 4, Tiled: 1]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 216 )[Tile0, 1:[216x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[216x1], 1]
		Tile0: [0, 216, 216], Tile1: [0, 216, 216], Tile2; [0, 216, 216]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 216 (Total Size: 512 )[Tile0, 1:[128x1], 4][D0, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[128x1], 4][D0, [0 x 4, 4]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 728 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 744 (Total Size: 4 )[D1, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 4, 4]]
		Tile0: [0, 4, 4], Tile1: [0, 4, 4], Tile2; [0, 4, 4]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 748 (Total Size: 4 )[D1, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 4, 4]]
		Tile0: [0, 4, 4], Tile1: [0, 4, 4], Tile2; [0, 4, 4]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 752 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 816 (Total Size: 512 )[Tile0, 1:[128x1], 4][D1, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 4, 4]][Tile0, 1:[128x1], 4]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1328 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+216);
	KerArg2->ColBuff = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (AE_1dcnn_RELU_L1_Memory+752);
	KerArg2->Bias = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+728);
	KerArg2->Out = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+816);
	KerArg2->Scale = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+744);
	KerArg2->ScaleN = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+748);
	KerArg2->Tile_InFeat = (unsigned short int) (4);
	KerArg2->TotalInFeatures = (unsigned short int) (4);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (128);
	KerArg2->Tile_OutFeat = (unsigned short int) (4);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (128);
	KerArg2->Pad_Val = (unsigned short int) (0);
	KerArg2->Pad = (v4s) ((v4s){1,1,0,0});
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->FirstTile = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (3);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+216), 512, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+752), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1328), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+728), 16, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+744), 4, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+748), 4, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->W_Offset = (int) (((int *)(AE_1dcnn_RELU_L1_Memory+1328))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+816), 512, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S36__encoder_conv_conv_2_projection_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 876 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 4, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 2, Tiled: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 256 )[Tile0, 1:[128x1], 2][D0, [0 x 2, 2]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[128x1], 2][D0, [0 x 2, 2]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 256 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 272 (Total Size: 4 )[D1, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 4, 4]]
		Tile0: [0, 4, 4], Tile1: [0, 4, 4], Tile2; [0, 4, 4]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 276 (Total Size: 4 )[D1, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 4, 4]]
		Tile0: [0, 4, 4], Tile1: [0, 4, 4], Tile2; [0, 4, 4]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 280 (Total Size: 64 )[D1, [0 x 64, 64]][D0, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]][D0, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 344 (Total Size: 512 )[Tile0, 1:[128x1], 4][D1, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 4, 4]][Tile0, 1:[128x1], 4]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 856 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+0), 256, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+280), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+856), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+256), 16, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+272), 4, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+276), 4, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerConv1x1_SmallHW_Stride1_NE16Seq(
					(unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+0),  // In
					(unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+344),  // Out
					(int * __restrict__) (AE_1dcnn_RELU_L1_Memory+256),  // Bias
					(unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+280),  // Filter
					(unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+272),  // Scale
					(unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+276),  // ScaleN
					(unsigned int) (((2) % (16))?(((2) / (16)) + (1)):((2) / (16))),  // Nb_KI
					(unsigned int) (((2) % (16))?((2) % (16)):(16)),  // Rem_KI
					(unsigned int) (((4) % (32))?(((4) / (32)) + (1)):((4) / (32))),  // Nb_KO
					(unsigned int) (((4) % (32))?((4) % (32)):(32)),  // Rem_KO
					(unsigned int) (((1) * (128)) / (3)),  // Nb_HO
					(unsigned int) (((1) * (128)) % (3)),  // Rem_HO
					(unsigned int) (0),  // Nb_WO
					(unsigned int) (0),  // Rem_WO
					(unsigned int) (0),  // Rem_HI
					(unsigned int) (0),  // Rem_WI
					(unsigned int) ((2) * (1)),  // InD0
					(unsigned int) (((2) * (128)) * (1)),  // InD1
					(unsigned int) (0),  // InD2
					(unsigned int) (16),  // WD0
					(unsigned int) (0),  // WD1
					(unsigned int) (0),  // WD2
					(unsigned int) (0),  // OutD0
					(unsigned int) ((4) * (1)),  // OutD1
					(unsigned int) (0),  // OutD2
					(v4s) 0,  // Pad
					(unsigned int) (220),  // PadVal
					(unsigned int) (((int *)(AE_1dcnn_RELU_L1_Memory+856))[4]),  // WOffset
					(unsigned char) ((1)),  // LastD0
					(unsigned char) ((1)),  // FirstD0
					(unsigned int) (50364503)  // NE16JobCfg
				);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+344), 512, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S37_expr_2(
		unsigned char * __restrict__ expr_2_in_0,
		unsigned char * __restrict__ expr_2_in_1,
		unsigned char * __restrict__ expr_2_out_0)

{
	/* Shared L1: 1536 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	s37_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 512, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_2_out_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 512 )[D0, [0 x 512, 512]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 512, 512]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: expr_2_in_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 512 (Total Size: 512 )[D0, [0 x 512, 512]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 512, 512]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: expr_2_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1024 (Total Size: 512 )[D0, [0 x 512, 512]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 512, 512]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (512);
	KerArg0->expr_2_in_0 = (unsigned char *__restrict__ ) (AE_1dcnn_RELU_L1_Memory+512);
	KerArg0->expr_2_in_1 = (unsigned char *__restrict__ ) (AE_1dcnn_RELU_L1_Memory+1024);
	KerArg0->expr_2_out_0 = (unsigned char *__restrict__ ) (AE_1dcnn_RELU_L1_Memory+0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_2_in_0+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+512), 512, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_2_in_1+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1024), 512, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_2_in_1 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_D0 =========================*/
		AT_FORK(gap_ncore(), (void *) s37_kernel, (void *) KerArg0);
		__CALL(s37_kernel, KerArg0);
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_2_out_0+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+0), 512, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write expr_2_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S40__encoder_conv_conv_2_downsampling_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 1444 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 4, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 4, Tiled: 1]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 504 )[Tile0, 1:[504x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[504x1], 1]
		Tile0: [0, 504, 504], Tile1: [0, 504, 504], Tile2; [0, 504, 504]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 504 (Total Size: 512 )[Tile0, 1:[128x1], 4][D0, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[128x1], 4][D0, [0 x 4, 4]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1016 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1032 (Total Size: 4 )[D1, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 4, 4]]
		Tile0: [0, 4, 4], Tile1: [0, 4, 4], Tile2; [0, 4, 4]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1036 (Total Size: 4 )[D1, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 4, 4]]
		Tile0: [0, 4, 4], Tile1: [0, 4, 4], Tile2; [0, 4, 4]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1040 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1168 (Total Size: 256 )[Tile0, 1:[64x1], 4][D1, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 4, 4]][Tile0, 1:[64x1], 4]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1424 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+504);
	KerArg2->ColBuff = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (AE_1dcnn_RELU_L1_Memory+1040);
	KerArg2->Bias = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+1016);
	KerArg2->Out = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+1168);
	KerArg2->Scale = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+1032);
	KerArg2->ScaleN = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+1036);
	KerArg2->Tile_InFeat = (unsigned short int) (4);
	KerArg2->TotalInFeatures = (unsigned short int) (4);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (128);
	KerArg2->Tile_OutFeat = (unsigned short int) (4);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (64);
	KerArg2->Pad_Val = (unsigned short int) (252);
	KerArg2->Pad = (v4s) ((v4s){3,2,0,0});
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->FirstTile = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (7);
	KerArg2->Sx = (unsigned short) (2);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+504), 512, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1040), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1424), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1016), 16, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1032), 4, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1036), 4, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->W_Offset = (int) (((int *)(AE_1dcnn_RELU_L1_Memory+1424))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1168), 256, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S43__encoder_conv_conv_3_backbone_backbone_0_backbone_0_0_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 3244 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 32, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 4, Tiled: 1]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 216 )[Tile0, 1:[216x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[216x1], 1]
		Tile0: [0, 216, 216], Tile1: [0, 216, 216], Tile2; [0, 216, 216]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 216 (Total Size: 256 )[Tile0, 1:[64x1], 4][D0, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[64x1], 4][D0, [0 x 4, 4]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 472 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 600 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 632 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 664 (Total Size: 512 )[D1, [0 x 512, 512]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 512, 512]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1176 (Total Size: 2048 )[Tile0, 1:[64x1], 32][D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]][Tile0, 1:[64x1], 32]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3224 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+216);
	KerArg2->ColBuff = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (AE_1dcnn_RELU_L1_Memory+664);
	KerArg2->Bias = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+472);
	KerArg2->Out = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+1176);
	KerArg2->Scale = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+600);
	KerArg2->ScaleN = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+632);
	KerArg2->Tile_InFeat = (unsigned short int) (4);
	KerArg2->TotalInFeatures = (unsigned short int) (4);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (64);
	KerArg2->Tile_OutFeat = (unsigned short int) (32);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (64);
	KerArg2->Pad_Val = (unsigned short int) (255);
	KerArg2->Pad = (v4s) ((v4s){1,1,0,0});
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->FirstTile = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (3);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+664), 512, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+216), 256, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+472), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+600), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+632), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+3224), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->W_Offset = (int) (((int *)(AE_1dcnn_RELU_L1_Memory+3224))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1176), 2048, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S46__encoder_conv_conv_3_backbone_backbone_1_backbone_1_0_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 9108 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 32, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 32, Tiled: 1]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 1728 )[Tile0, 1:[1728x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1728x1], 1]
		Tile0: [0, 1728, 1728], Tile1: [0, 1728, 1728], Tile2; [0, 1728, 1728]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1728 (Total Size: 2048 )[Tile0, 1:[64x1], 32][D0, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[64x1], 32][D0, [0 x 32, 32]]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3776 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3904 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3936 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3968 (Total Size: 3072 )[D1, [0 x 3072, 3072]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 3072, 3072]]
		Tile0: [0, 3072, 3072], Tile1: [0, 3072, 3072], Tile2; [0, 3072, 3072]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 7040 (Total Size: 2048 )[Tile0, 1:[64x1], 32][D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]][Tile0, 1:[64x1], 32]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 9088 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+1728);
	KerArg2->ColBuff = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (AE_1dcnn_RELU_L1_Memory+3968);
	KerArg2->Bias = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+3776);
	KerArg2->Out = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+7040);
	KerArg2->Scale = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+3904);
	KerArg2->ScaleN = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+3936);
	KerArg2->Tile_InFeat = (unsigned short int) (32);
	KerArg2->TotalInFeatures = (unsigned short int) (32);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (64);
	KerArg2->Tile_OutFeat = (unsigned short int) (32);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (64);
	KerArg2->Pad_Val = (unsigned short int) (0);
	KerArg2->Pad = (v4s) ((v4s){1,1,0,0});
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->FirstTile = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (3);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+3968), 3072, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1728), 2048, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+3776), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+3904), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+3936), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+9088), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->W_Offset = (int) (((int *)(AE_1dcnn_RELU_L1_Memory+9088))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+7040), 2048, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S49__encoder_conv_conv_3_projection_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 3028 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 32, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 4, Tiled: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 256 )[Tile0, 1:[64x1], 4][D0, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[64x1], 4][D0, [0 x 4, 4]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 256 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 384 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 416 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 448 (Total Size: 512 )[D1, [0 x 128, 128]][D0, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]][D0, [0 x 16, 16]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 960 (Total Size: 2048 )[Tile0, 1:[64x1], 32][D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]][Tile0, 1:[64x1], 32]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3008 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+448), 512, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+0), 256, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+256), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+384), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+416), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+3008), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerConv1x1_SmallHW_Stride1_NE16Seq(
					(unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+0),  // In
					(unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+960),  // Out
					(int * __restrict__) (AE_1dcnn_RELU_L1_Memory+256),  // Bias
					(unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+448),  // Filter
					(unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+384),  // Scale
					(unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+416),  // ScaleN
					(unsigned int) (((4) % (16))?(((4) / (16)) + (1)):((4) / (16))),  // Nb_KI
					(unsigned int) (((4) % (16))?((4) % (16)):(16)),  // Rem_KI
					(unsigned int) (((32) % (32))?(((32) / (32)) + (1)):((32) / (32))),  // Nb_KO
					(unsigned int) (((32) % (32))?((32) % (32)):(32)),  // Rem_KO
					(unsigned int) (((1) * (64)) / (3)),  // Nb_HO
					(unsigned int) (((1) * (64)) % (3)),  // Rem_HO
					(unsigned int) (0),  // Nb_WO
					(unsigned int) (0),  // Rem_WO
					(unsigned int) (0),  // Rem_HI
					(unsigned int) (0),  // Rem_WI
					(unsigned int) ((4) * (1)),  // InD0
					(unsigned int) (((4) * (64)) * (1)),  // InD1
					(unsigned int) (0),  // InD2
					(unsigned int) (16),  // WD0
					(unsigned int) (0),  // WD1
					(unsigned int) (0),  // WD2
					(unsigned int) (0),  // OutD0
					(unsigned int) ((32) * (1)),  // OutD1
					(unsigned int) (0),  // OutD2
					(v4s) 0,  // Pad
					(unsigned int) (255),  // PadVal
					(unsigned int) (((int *)(AE_1dcnn_RELU_L1_Memory+3008))[4]),  // WOffset
					(unsigned char) ((1)),  // LastD0
					(unsigned char) ((1)),  // FirstD0
					(unsigned int) (50364503)  // NE16JobCfg
				);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+960), 2048, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S50_expr_3(
		unsigned char * __restrict__ expr_3_in_0,
		unsigned char * __restrict__ expr_3_in_1,
		unsigned char * __restrict__ expr_3_out_0)

{
	/* Shared L1: 6144 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	s50_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 2048, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_3_out_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 2048 )[D0, [0 x 2048, 2048]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 2048, 2048]]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: expr_3_in_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2048 (Total Size: 2048 )[D0, [0 x 2048, 2048]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 2048, 2048]]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: expr_3_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 4096 (Total Size: 2048 )[D0, [0 x 2048, 2048]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 2048, 2048]]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (2048);
	KerArg0->expr_3_in_0 = (unsigned char *__restrict__ ) (AE_1dcnn_RELU_L1_Memory+2048);
	KerArg0->expr_3_in_1 = (unsigned char *__restrict__ ) (AE_1dcnn_RELU_L1_Memory+4096);
	KerArg0->expr_3_out_0 = (unsigned char *__restrict__ ) (AE_1dcnn_RELU_L1_Memory+0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_3_in_0+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+2048), 2048, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_3_in_1+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+4096), 2048, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_3_in_1 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_D0 =========================*/
		AT_FORK(gap_ncore(), (void *) s50_kernel, (void *) KerArg0);
		__CALL(s50_kernel, KerArg0);
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_3_out_0+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+0), 2048, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write expr_3_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S53__encoder_conv_conv_3_downsampling_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 14484 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 32, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 32, Tiled: 1]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 4032 )[Tile0, 1:[4032x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[4032x1], 1]
		Tile0: [0, 4032, 4032], Tile1: [0, 4032, 4032], Tile2; [0, 4032, 4032]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 4032 (Total Size: 2048 )[Tile0, 1:[64x1], 32][D0, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[64x1], 32][D0, [0 x 32, 32]]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6080 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6208 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6240 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6272 (Total Size: 7168 )[D1, [0 x 7168, 7168]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 7168, 7168]]
		Tile0: [0, 7168, 7168], Tile1: [0, 7168, 7168], Tile2; [0, 7168, 7168]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 13440 (Total Size: 1024 )[Tile0, 1:[32x1], 32][D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]][Tile0, 1:[32x1], 32]
		Tile0: [0, 1024, 1024], Tile1: [0, 1024, 1024], Tile2; [0, 1024, 1024]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 14464 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+4032);
	KerArg2->ColBuff = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (AE_1dcnn_RELU_L1_Memory+6272);
	KerArg2->Bias = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+6080);
	KerArg2->Out = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+13440);
	KerArg2->Scale = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+6208);
	KerArg2->ScaleN = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+6240);
	KerArg2->Tile_InFeat = (unsigned short int) (32);
	KerArg2->TotalInFeatures = (unsigned short int) (32);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (64);
	KerArg2->Tile_OutFeat = (unsigned short int) (32);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (32);
	KerArg2->Pad_Val = (unsigned short int) (108);
	KerArg2->Pad = (v4s) ((v4s){3,2,0,0});
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->FirstTile = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (7);
	KerArg2->Sx = (unsigned short) (2);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+6272), 7168, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+4032), 2048, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+6080), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+6208), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+6240), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+14464), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->W_Offset = (int) (((int *)(AE_1dcnn_RELU_L1_Memory+14464))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+13440), 1024, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S56__decoder_deconv_deconv_0_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 7060 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 32, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 32, Tiled: 1]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 1728 )[Tile0, 1:[1728x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1728x1], 1]
		Tile0: [0, 1728, 1728], Tile1: [0, 1728, 1728], Tile2; [0, 1728, 1728]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1728 (Total Size: 1024 )[Tile0, 1:[32x1], 32][D0, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[32x1], 32][D0, [0 x 32, 32]]
		Tile0: [0, 1024, 1024], Tile1: [0, 1024, 1024], Tile2; [0, 1024, 1024]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2752 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2880 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2912 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2944 (Total Size: 3072 )[D1, [0 x 3072, 3072]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 3072, 3072]]
		Tile0: [0, 3072, 3072], Tile1: [0, 3072, 3072], Tile2; [0, 3072, 3072]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6016 (Total Size: 1024 )[Tile0, 1:[32x1], 32][D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]][Tile0, 1:[32x1], 32]
		Tile0: [0, 1024, 1024], Tile1: [0, 1024, 1024], Tile2; [0, 1024, 1024]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 7040 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+1728);
	KerArg2->ColBuff = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (AE_1dcnn_RELU_L1_Memory+2944);
	KerArg2->Bias = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+2752);
	KerArg2->Out = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+6016);
	KerArg2->Scale = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+2880);
	KerArg2->ScaleN = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+2912);
	KerArg2->Tile_InFeat = (unsigned short int) (32);
	KerArg2->TotalInFeatures = (unsigned short int) (32);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (32);
	KerArg2->Tile_OutFeat = (unsigned short int) (32);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (32);
	KerArg2->Pad_Val = (unsigned short int) (128);
	KerArg2->Pad = (v4s) ((v4s){1,1,0,0});
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->FirstTile = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (3);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+2944), 3072, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1728), 1024, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+2752), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+2880), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+2912), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+7040), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->W_Offset = (int) (((int *)(AE_1dcnn_RELU_L1_Memory+7040))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+6016), 1024, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S59__decoder_deconv_deconv_0_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 7060 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 32, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 32, Tiled: 1]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 1728 )[Tile0, 1:[1728x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1728x1], 1]
		Tile0: [0, 1728, 1728], Tile1: [0, 1728, 1728], Tile2; [0, 1728, 1728]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1728 (Total Size: 1024 )[Tile0, 1:[32x1], 32][D0, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[32x1], 32][D0, [0 x 32, 32]]
		Tile0: [0, 1024, 1024], Tile1: [0, 1024, 1024], Tile2; [0, 1024, 1024]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2752 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2880 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2912 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2944 (Total Size: 3072 )[D1, [0 x 3072, 3072]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 3072, 3072]]
		Tile0: [0, 3072, 3072], Tile1: [0, 3072, 3072], Tile2; [0, 3072, 3072]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6016 (Total Size: 1024 )[Tile0, 1:[32x1], 32][D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]][Tile0, 1:[32x1], 32]
		Tile0: [0, 1024, 1024], Tile1: [0, 1024, 1024], Tile2; [0, 1024, 1024]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 7040 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+1728);
	KerArg2->ColBuff = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (AE_1dcnn_RELU_L1_Memory+2944);
	KerArg2->Bias = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+2752);
	KerArg2->Out = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+6016);
	KerArg2->Scale = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+2880);
	KerArg2->ScaleN = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+2912);
	KerArg2->Tile_InFeat = (unsigned short int) (32);
	KerArg2->TotalInFeatures = (unsigned short int) (32);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (32);
	KerArg2->Tile_OutFeat = (unsigned short int) (32);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (32);
	KerArg2->Pad_Val = (unsigned short int) (0);
	KerArg2->Pad = (v4s) ((v4s){1,1,0,0});
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->FirstTile = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (3);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+2944), 3072, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1728), 1024, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+2752), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+2880), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+2912), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+7040), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->W_Offset = (int) (((int *)(AE_1dcnn_RELU_L1_Memory+7040))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+6016), 1024, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S60_expr_4(
		unsigned char * __restrict__ expr_4_in_0,
		unsigned char * __restrict__ expr_4_in_1,
		unsigned char * __restrict__ expr_4_out_0)

{
	/* Shared L1: 3072 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	s60_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 1024, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_4_out_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 1024 )[D0, [0 x 1024, 1024]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 1024, 1024]]
		Tile0: [0, 1024, 1024], Tile1: [0, 1024, 1024], Tile2; [0, 1024, 1024]
	Ker Arg: expr_4_in_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1024 (Total Size: 1024 )[D0, [0 x 1024, 1024]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 1024, 1024]]
		Tile0: [0, 1024, 1024], Tile1: [0, 1024, 1024], Tile2; [0, 1024, 1024]
	Ker Arg: expr_4_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2048 (Total Size: 1024 )[D0, [0 x 1024, 1024]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 1024, 1024]]
		Tile0: [0, 1024, 1024], Tile1: [0, 1024, 1024], Tile2; [0, 1024, 1024]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (1024);
	KerArg0->expr_4_in_0 = (unsigned char *__restrict__ ) (AE_1dcnn_RELU_L1_Memory+1024);
	KerArg0->expr_4_in_1 = (unsigned char *__restrict__ ) (AE_1dcnn_RELU_L1_Memory+2048);
	KerArg0->expr_4_out_0 = (unsigned char *__restrict__ ) (AE_1dcnn_RELU_L1_Memory+0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_4_in_0+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1024), 1024, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_4_in_1+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+2048), 1024, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_4_in_1 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_D0 =========================*/
		AT_FORK(gap_ncore(), (void *) s60_kernel, (void *) KerArg0);
		__CALL(s60_kernel, KerArg0);
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_4_out_0+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+0), 1024, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write expr_4_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S63__decoder_deconv_deconv_0_upsampling_ConvTranspose(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 9684 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 32, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 32, Tiled: 1]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 2304 )[Tile0, 1:[2304x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[2304x1], 1]
		Tile0: [0, 2304, 2304], Tile1: [0, 2304, 2304], Tile2; [0, 2304, 2304]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2304 (Total Size: 1024 )[Tile0, 1:[32x1], 32][D0, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[32x1], 32][D0, [0 x 32, 32]]
		Tile0: [0, 1024, 1024], Tile1: [0, 1024, 1024], Tile2; [0, 1024, 1024]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3328 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3456 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3488 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3520 (Total Size: 4096 )[D1, [0 x 4096, 4096]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 4096, 4096]]
		Tile0: [0, 4096, 4096], Tile1: [0, 4096, 4096], Tile2; [0, 4096, 4096]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 7616 (Total Size: 2048 )[Tile0, 1:[64x1], 32][D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]][Tile0, 1:[64x1], 32]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 9664 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+2304);
	KerArg2->ColBuff = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (AE_1dcnn_RELU_L1_Memory+3520);
	KerArg2->Bias = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+3328);
	KerArg2->Out = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+7616);
	KerArg2->Scale = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+3456);
	KerArg2->ScaleN = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+3488);
	KerArg2->Tile_InFeat = (unsigned short int) (32);
	KerArg2->TotalInFeatures = (unsigned short int) (32);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (32);
	KerArg2->Tile_OutFeat = (unsigned short int) (32);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (64);
	KerArg2->Pad_Val = (unsigned short int) (118);
	KerArg2->Pad = (v4s) ((v4s){2,2,0,0});
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->FirstTile = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (4);
	KerArg2->Sx = (unsigned short) (2);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+3520), 4096, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+2304), 1024, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+3328), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+3456), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+3488), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+9664), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->W_Offset = (int) (((int *)(AE_1dcnn_RELU_L1_Memory+9664))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_TransposedConv1D_NE16, (void *) KerArg2);
				__CALL(Ker_MM_TransposedConv1D_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+7616), 2048, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S66__decoder_deconv_deconv_1_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 9108 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 32, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 32, Tiled: 1]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 1728 )[Tile0, 1:[1728x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1728x1], 1]
		Tile0: [0, 1728, 1728], Tile1: [0, 1728, 1728], Tile2; [0, 1728, 1728]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1728 (Total Size: 2048 )[Tile0, 1:[64x1], 32][D0, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[64x1], 32][D0, [0 x 32, 32]]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3776 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3904 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3936 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3968 (Total Size: 3072 )[D1, [0 x 3072, 3072]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 3072, 3072]]
		Tile0: [0, 3072, 3072], Tile1: [0, 3072, 3072], Tile2; [0, 3072, 3072]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 7040 (Total Size: 2048 )[Tile0, 1:[64x1], 32][D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]][Tile0, 1:[64x1], 32]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 9088 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+1728);
	KerArg2->ColBuff = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (AE_1dcnn_RELU_L1_Memory+3968);
	KerArg2->Bias = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+3776);
	KerArg2->Out = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+7040);
	KerArg2->Scale = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+3904);
	KerArg2->ScaleN = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+3936);
	KerArg2->Tile_InFeat = (unsigned short int) (32);
	KerArg2->TotalInFeatures = (unsigned short int) (32);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (64);
	KerArg2->Tile_OutFeat = (unsigned short int) (32);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (64);
	KerArg2->Pad_Val = (unsigned short int) (138);
	KerArg2->Pad = (v4s) ((v4s){1,1,0,0});
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->FirstTile = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (3);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+3968), 3072, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1728), 2048, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+3776), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+3904), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+3936), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+9088), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->W_Offset = (int) (((int *)(AE_1dcnn_RELU_L1_Memory+9088))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+7040), 2048, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S69__decoder_deconv_deconv_1_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 9108 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 32, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 32, Tiled: 1]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 1728 )[Tile0, 1:[1728x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1728x1], 1]
		Tile0: [0, 1728, 1728], Tile1: [0, 1728, 1728], Tile2; [0, 1728, 1728]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1728 (Total Size: 2048 )[Tile0, 1:[64x1], 32][D0, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[64x1], 32][D0, [0 x 32, 32]]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3776 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3904 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3936 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3968 (Total Size: 3072 )[D1, [0 x 3072, 3072]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 3072, 3072]]
		Tile0: [0, 3072, 3072], Tile1: [0, 3072, 3072], Tile2; [0, 3072, 3072]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 7040 (Total Size: 2048 )[Tile0, 1:[64x1], 32][D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]][Tile0, 1:[64x1], 32]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 9088 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+1728);
	KerArg2->ColBuff = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (AE_1dcnn_RELU_L1_Memory+3968);
	KerArg2->Bias = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+3776);
	KerArg2->Out = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+7040);
	KerArg2->Scale = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+3904);
	KerArg2->ScaleN = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+3936);
	KerArg2->Tile_InFeat = (unsigned short int) (32);
	KerArg2->TotalInFeatures = (unsigned short int) (32);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (64);
	KerArg2->Tile_OutFeat = (unsigned short int) (32);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (64);
	KerArg2->Pad_Val = (unsigned short int) (0);
	KerArg2->Pad = (v4s) ((v4s){1,1,0,0});
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->FirstTile = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (3);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+3968), 3072, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1728), 2048, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+3776), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+3904), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+3936), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+9088), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->W_Offset = (int) (((int *)(AE_1dcnn_RELU_L1_Memory+9088))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+7040), 2048, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S70_expr_5(
		unsigned char * __restrict__ expr_5_in_0,
		unsigned char * __restrict__ expr_5_in_1,
		unsigned char * __restrict__ expr_5_out_0)

{
	/* Shared L1: 6144 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	s70_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 2048, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_5_out_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 2048 )[D0, [0 x 2048, 2048]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 2048, 2048]]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: expr_5_in_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2048 (Total Size: 2048 )[D0, [0 x 2048, 2048]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 2048, 2048]]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: expr_5_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 4096 (Total Size: 2048 )[D0, [0 x 2048, 2048]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 2048, 2048]]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (2048);
	KerArg0->expr_5_in_0 = (unsigned char *__restrict__ ) (AE_1dcnn_RELU_L1_Memory+2048);
	KerArg0->expr_5_in_1 = (unsigned char *__restrict__ ) (AE_1dcnn_RELU_L1_Memory+4096);
	KerArg0->expr_5_out_0 = (unsigned char *__restrict__ ) (AE_1dcnn_RELU_L1_Memory+0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_5_in_0+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+2048), 2048, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_5_in_1+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+4096), 2048, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_5_in_1 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_D0 =========================*/
		AT_FORK(gap_ncore(), (void *) s70_kernel, (void *) KerArg0);
		__CALL(s70_kernel, KerArg0);
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_5_out_0+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+0), 2048, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write expr_5_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S73__decoder_deconv_deconv_1_upsampling_ConvTranspose(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 12756 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 32, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 32, Tiled: 1]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 2304 )[Tile0, 1:[2304x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[2304x1], 1]
		Tile0: [0, 2304, 2304], Tile1: [0, 2304, 2304], Tile2; [0, 2304, 2304]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2304 (Total Size: 2048 )[Tile0, 1:[64x1], 32][D0, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[64x1], 32][D0, [0 x 32, 32]]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 4352 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 4480 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 4512 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 4544 (Total Size: 4096 )[D1, [0 x 4096, 4096]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 4096, 4096]]
		Tile0: [0, 4096, 4096], Tile1: [0, 4096, 4096], Tile2; [0, 4096, 4096]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 8640 (Total Size: 4096 )[Tile0, 1:[128x1], 32][D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]][Tile0, 1:[128x1], 32]
		Tile0: [0, 4096, 4096], Tile1: [0, 4096, 4096], Tile2; [0, 4096, 4096]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 12736 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+2304);
	KerArg2->ColBuff = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (AE_1dcnn_RELU_L1_Memory+4544);
	KerArg2->Bias = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+4352);
	KerArg2->Out = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+8640);
	KerArg2->Scale = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+4480);
	KerArg2->ScaleN = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+4512);
	KerArg2->Tile_InFeat = (unsigned short int) (32);
	KerArg2->TotalInFeatures = (unsigned short int) (32);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (64);
	KerArg2->Tile_OutFeat = (unsigned short int) (32);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (128);
	KerArg2->Pad_Val = (unsigned short int) (111);
	KerArg2->Pad = (v4s) ((v4s){2,2,0,0});
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->FirstTile = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (4);
	KerArg2->Sx = (unsigned short) (2);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+4544), 4096, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+2304), 2048, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+4352), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+4480), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+4512), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+12736), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->W_Offset = (int) (((int *)(AE_1dcnn_RELU_L1_Memory+12736))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_TransposedConv1D_NE16, (void *) KerArg2);
				__CALL(Ker_MM_TransposedConv1D_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+8640), 4096, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S76__decoder_deconv_deconv_2_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 13204 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 32, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 32, Tiled: 1]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 1728 )[Tile0, 1:[1728x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1728x1], 1]
		Tile0: [0, 1728, 1728], Tile1: [0, 1728, 1728], Tile2; [0, 1728, 1728]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1728 (Total Size: 4096 )[Tile0, 1:[128x1], 32][D0, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[128x1], 32][D0, [0 x 32, 32]]
		Tile0: [0, 4096, 4096], Tile1: [0, 4096, 4096], Tile2; [0, 4096, 4096]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5824 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5952 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5984 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6016 (Total Size: 3072 )[D1, [0 x 3072, 3072]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 3072, 3072]]
		Tile0: [0, 3072, 3072], Tile1: [0, 3072, 3072], Tile2; [0, 3072, 3072]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 9088 (Total Size: 4096 )[Tile0, 1:[128x1], 32][D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]][Tile0, 1:[128x1], 32]
		Tile0: [0, 4096, 4096], Tile1: [0, 4096, 4096], Tile2; [0, 4096, 4096]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 13184 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+1728);
	KerArg2->ColBuff = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (AE_1dcnn_RELU_L1_Memory+6016);
	KerArg2->Bias = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+5824);
	KerArg2->Out = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+9088);
	KerArg2->Scale = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+5952);
	KerArg2->ScaleN = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+5984);
	KerArg2->Tile_InFeat = (unsigned short int) (32);
	KerArg2->TotalInFeatures = (unsigned short int) (32);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (128);
	KerArg2->Tile_OutFeat = (unsigned short int) (32);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (128);
	KerArg2->Pad_Val = (unsigned short int) (147);
	KerArg2->Pad = (v4s) ((v4s){1,1,0,0});
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->FirstTile = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (3);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1728), 4096, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+6016), 3072, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+5824), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+5952), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+5984), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+13184), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->W_Offset = (int) (((int *)(AE_1dcnn_RELU_L1_Memory+13184))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+9088), 4096, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S79__decoder_deconv_deconv_2_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 13204 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 32, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 32, Tiled: 1]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 1728 )[Tile0, 1:[1728x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1728x1], 1]
		Tile0: [0, 1728, 1728], Tile1: [0, 1728, 1728], Tile2; [0, 1728, 1728]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1728 (Total Size: 4096 )[Tile0, 1:[128x1], 32][D0, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[128x1], 32][D0, [0 x 32, 32]]
		Tile0: [0, 4096, 4096], Tile1: [0, 4096, 4096], Tile2; [0, 4096, 4096]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5824 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5952 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5984 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6016 (Total Size: 3072 )[D1, [0 x 3072, 3072]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 3072, 3072]]
		Tile0: [0, 3072, 3072], Tile1: [0, 3072, 3072], Tile2; [0, 3072, 3072]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 9088 (Total Size: 4096 )[Tile0, 1:[128x1], 32][D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]][Tile0, 1:[128x1], 32]
		Tile0: [0, 4096, 4096], Tile1: [0, 4096, 4096], Tile2; [0, 4096, 4096]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 13184 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+1728);
	KerArg2->ColBuff = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (AE_1dcnn_RELU_L1_Memory+6016);
	KerArg2->Bias = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+5824);
	KerArg2->Out = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+9088);
	KerArg2->Scale = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+5952);
	KerArg2->ScaleN = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+5984);
	KerArg2->Tile_InFeat = (unsigned short int) (32);
	KerArg2->TotalInFeatures = (unsigned short int) (32);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (128);
	KerArg2->Tile_OutFeat = (unsigned short int) (32);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (128);
	KerArg2->Pad_Val = (unsigned short int) (0);
	KerArg2->Pad = (v4s) ((v4s){1,1,0,0});
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->FirstTile = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (3);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1728), 4096, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+6016), 3072, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+5824), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+5952), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+5984), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+13184), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->W_Offset = (int) (((int *)(AE_1dcnn_RELU_L1_Memory+13184))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+9088), 4096, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S80_expr_6(
		unsigned char * __restrict__ expr_6_in_0,
		unsigned char * __restrict__ expr_6_in_1,
		unsigned char * __restrict__ expr_6_out_0)

{
	/* Shared L1: 12288 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	s80_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 4096, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_6_out_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 4096 )[D0, [0 x 4096, 4096]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 4096, 4096]]
		Tile0: [0, 4096, 4096], Tile1: [0, 4096, 4096], Tile2; [0, 4096, 4096]
	Ker Arg: expr_6_in_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 4096 (Total Size: 4096 )[D0, [0 x 4096, 4096]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 4096, 4096]]
		Tile0: [0, 4096, 4096], Tile1: [0, 4096, 4096], Tile2; [0, 4096, 4096]
	Ker Arg: expr_6_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 8192 (Total Size: 4096 )[D0, [0 x 4096, 4096]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 4096, 4096]]
		Tile0: [0, 4096, 4096], Tile1: [0, 4096, 4096], Tile2; [0, 4096, 4096]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (4096);
	KerArg0->expr_6_in_0 = (unsigned char *__restrict__ ) (AE_1dcnn_RELU_L1_Memory+4096);
	KerArg0->expr_6_in_1 = (unsigned char *__restrict__ ) (AE_1dcnn_RELU_L1_Memory+8192);
	KerArg0->expr_6_out_0 = (unsigned char *__restrict__ ) (AE_1dcnn_RELU_L1_Memory+0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_6_in_0+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+4096), 4096, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_6_in_1+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+8192), 4096, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_6_in_1 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_D0 =========================*/
		AT_FORK(gap_ncore(), (void *) s80_kernel, (void *) KerArg0);
		__CALL(s80_kernel, KerArg0);
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_6_out_0+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+0), 4096, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write expr_6_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S83__decoder_deconv_deconv_2_upsampling_ConvTranspose(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 12660 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 16, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 32, Tiled: 1]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 2304 )[Tile0, 1:[2304x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[2304x1], 1]
		Tile0: [0, 2304, 2304], Tile1: [0, 2304, 2304], Tile2; [0, 2304, 2304]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2304 (Total Size: 4096 )[Tile0, 1:[128x1], 32][D0, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[128x1], 32][D0, [0 x 32, 32]]
		Tile0: [0, 4096, 4096], Tile1: [0, 4096, 4096], Tile2; [0, 4096, 4096]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6400 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6464 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6480 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6496 (Total Size: 2048 )[D1, [0 x 2048, 2048]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2048, 2048]]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 8544 (Total Size: 4096 )[Tile0, 1:[256x1], 16][D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]][Tile0, 1:[256x1], 16]
		Tile0: [0, 4096, 4096], Tile1: [0, 4096, 4096], Tile2; [0, 4096, 4096]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 12640 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+2304);
	KerArg2->ColBuff = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (AE_1dcnn_RELU_L1_Memory+6496);
	KerArg2->Bias = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+6400);
	KerArg2->Out = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+8544);
	KerArg2->Scale = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+6464);
	KerArg2->ScaleN = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+6480);
	KerArg2->Tile_InFeat = (unsigned short int) (32);
	KerArg2->TotalInFeatures = (unsigned short int) (32);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (128);
	KerArg2->Tile_OutFeat = (unsigned short int) (16);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (256);
	KerArg2->Pad_Val = (unsigned short int) (115);
	KerArg2->Pad = (v4s) ((v4s){2,2,0,0});
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->FirstTile = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (4);
	KerArg2->Sx = (unsigned short) (2);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+2304), 4096, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+6496), 2048, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+6400), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+12640), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+6464), 16, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+6480), 16, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->W_Offset = (int) (((int *)(AE_1dcnn_RELU_L1_Memory+12640))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_TransposedConv1D_NE16, (void *) KerArg2);
				__CALL(Ker_MM_TransposedConv1D_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+8544), 4096, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S86__decoder_deconv_deconv_3_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 9940 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 16, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 16, Tiled: 1]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 864 )[Tile0, 1:[864x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[864x1], 1]
		Tile0: [0, 864, 864], Tile1: [0, 864, 864], Tile2; [0, 864, 864]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 864 (Total Size: 4096 )[Tile0, 1:[256x1], 16][D0, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[256x1], 16][D0, [0 x 16, 16]]
		Tile0: [0, 4096, 4096], Tile1: [0, 4096, 4096], Tile2; [0, 4096, 4096]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 4960 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5024 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5040 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5056 (Total Size: 768 )[D1, [0 x 768, 768]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 768, 768]]
		Tile0: [0, 768, 768], Tile1: [0, 768, 768], Tile2; [0, 768, 768]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5824 (Total Size: 4096 )[Tile0, 1:[256x1], 16][D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]][Tile0, 1:[256x1], 16]
		Tile0: [0, 4096, 4096], Tile1: [0, 4096, 4096], Tile2; [0, 4096, 4096]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 9920 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+864);
	KerArg2->ColBuff = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (AE_1dcnn_RELU_L1_Memory+5056);
	KerArg2->Bias = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+4960);
	KerArg2->Out = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+5824);
	KerArg2->Scale = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+5024);
	KerArg2->ScaleN = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+5040);
	KerArg2->Tile_InFeat = (unsigned short int) (16);
	KerArg2->TotalInFeatures = (unsigned short int) (16);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (256);
	KerArg2->Tile_OutFeat = (unsigned short int) (16);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (256);
	KerArg2->Pad_Val = (unsigned short int) (114);
	KerArg2->Pad = (v4s) ((v4s){1,1,0,0});
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->FirstTile = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (3);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+864), 4096, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+5056), 768, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+4960), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+9920), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+5024), 16, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+5040), 16, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->W_Offset = (int) (((int *)(AE_1dcnn_RELU_L1_Memory+9920))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+5824), 4096, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S89__decoder_deconv_deconv_3_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 9940 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 16, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 16, Tiled: 1]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 864 )[Tile0, 1:[864x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[864x1], 1]
		Tile0: [0, 864, 864], Tile1: [0, 864, 864], Tile2; [0, 864, 864]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 864 (Total Size: 4096 )[Tile0, 1:[256x1], 16][D0, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[256x1], 16][D0, [0 x 16, 16]]
		Tile0: [0, 4096, 4096], Tile1: [0, 4096, 4096], Tile2; [0, 4096, 4096]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 4960 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5024 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5040 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5056 (Total Size: 768 )[D1, [0 x 768, 768]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 768, 768]]
		Tile0: [0, 768, 768], Tile1: [0, 768, 768], Tile2; [0, 768, 768]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5824 (Total Size: 4096 )[Tile0, 1:[256x1], 16][D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]][Tile0, 1:[256x1], 16]
		Tile0: [0, 4096, 4096], Tile1: [0, 4096, 4096], Tile2; [0, 4096, 4096]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 9920 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+864);
	KerArg2->ColBuff = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (AE_1dcnn_RELU_L1_Memory+5056);
	KerArg2->Bias = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+4960);
	KerArg2->Out = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+5824);
	KerArg2->Scale = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+5024);
	KerArg2->ScaleN = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+5040);
	KerArg2->Tile_InFeat = (unsigned short int) (16);
	KerArg2->TotalInFeatures = (unsigned short int) (16);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (256);
	KerArg2->Tile_OutFeat = (unsigned short int) (16);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (256);
	KerArg2->Pad_Val = (unsigned short int) (0);
	KerArg2->Pad = (v4s) ((v4s){1,1,0,0});
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->FirstTile = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (3);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+864), 4096, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+5056), 768, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+4960), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+9920), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+5024), 16, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+5040), 16, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->W_Offset = (int) (((int *)(AE_1dcnn_RELU_L1_Memory+9920))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+5824), 4096, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S90_expr_7(
		unsigned char * __restrict__ expr_7_in_0,
		unsigned char * __restrict__ expr_7_in_1,
		unsigned char * __restrict__ expr_7_out_0)

{
	/* Shared L1: 12288 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	s90_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 4096, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_7_out_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 4096 )[D0, [0 x 4096, 4096]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 4096, 4096]]
		Tile0: [0, 4096, 4096], Tile1: [0, 4096, 4096], Tile2; [0, 4096, 4096]
	Ker Arg: expr_7_in_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 4096 (Total Size: 4096 )[D0, [0 x 4096, 4096]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 4096, 4096]]
		Tile0: [0, 4096, 4096], Tile1: [0, 4096, 4096], Tile2; [0, 4096, 4096]
	Ker Arg: expr_7_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 8192 (Total Size: 4096 )[D0, [0 x 4096, 4096]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 4096, 4096]]
		Tile0: [0, 4096, 4096], Tile1: [0, 4096, 4096], Tile2; [0, 4096, 4096]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (4096);
	KerArg0->expr_7_in_0 = (unsigned char *__restrict__ ) (AE_1dcnn_RELU_L1_Memory+4096);
	KerArg0->expr_7_in_1 = (unsigned char *__restrict__ ) (AE_1dcnn_RELU_L1_Memory+8192);
	KerArg0->expr_7_out_0 = (unsigned char *__restrict__ ) (AE_1dcnn_RELU_L1_Memory+0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_7_in_0+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+4096), 4096, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_7_in_1+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+8192), 4096, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_7_in_1 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_D0 =========================*/
		AT_FORK(gap_ncore(), (void *) s90_kernel, (void *) KerArg0);
		__CALL(s90_kernel, KerArg0);
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_7_out_0+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+0), 4096, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write expr_7_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S93__decoder_deconv_deconv_3_upsampling_ConvTranspose(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 9924 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 8, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 16, Tiled: 1]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 1152 )[Tile0, 1:[1152x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1152x1], 1]
		Tile0: [0, 1152, 1152], Tile1: [0, 1152, 1152], Tile2; [0, 1152, 1152]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1152 (Total Size: 4096 )[Tile0, 1:[256x1], 16][D0, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[256x1], 16][D0, [0 x 16, 16]]
		Tile0: [0, 4096, 4096], Tile1: [0, 4096, 4096], Tile2; [0, 4096, 4096]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5248 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5280 (Total Size: 8 )[D1, [0 x 8, 8]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 8, 8]]
		Tile0: [0, 8, 8], Tile1: [0, 8, 8], Tile2; [0, 8, 8]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5288 (Total Size: 8 )[D1, [0 x 8, 8]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 8, 8]]
		Tile0: [0, 8, 8], Tile1: [0, 8, 8], Tile2; [0, 8, 8]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5296 (Total Size: 512 )[D1, [0 x 512, 512]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 512, 512]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5808 (Total Size: 4096 )[Tile0, 1:[512x1], 8][D1, [0 x 8, 8]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 8, 8]][Tile0, 1:[512x1], 8]
		Tile0: [0, 4096, 4096], Tile1: [0, 4096, 4096], Tile2; [0, 4096, 4096]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 9904 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+1152);
	KerArg2->ColBuff = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (AE_1dcnn_RELU_L1_Memory+5296);
	KerArg2->Bias = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+5248);
	KerArg2->Out = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+5808);
	KerArg2->Scale = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+5280);
	KerArg2->ScaleN = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+5288);
	KerArg2->Tile_InFeat = (unsigned short int) (16);
	KerArg2->TotalInFeatures = (unsigned short int) (16);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (256);
	KerArg2->Tile_OutFeat = (unsigned short int) (8);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (512);
	KerArg2->Pad_Val = (unsigned short int) (60);
	KerArg2->Pad = (v4s) ((v4s){2,2,0,0});
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->FirstTile = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (4);
	KerArg2->Sx = (unsigned short) (2);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1152), 4096, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+5296), 512, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+5248), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+9904), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+5280), 8, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+5288), 8, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->W_Offset = (int) (((int *)(AE_1dcnn_RELU_L1_Memory+9904))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_TransposedConv1D_NE16, (void *) KerArg2);
				__CALL(Ker_MM_TransposedConv1D_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+5808), 4096, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S96__decoder_deconv_deconv_4_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 5712 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 1, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 8, Tiled: 1]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 1008 )[Tile0, 1:[1008x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1008x1], 1]
		Tile0: [0, 1008, 1008], Tile1: [0, 1008, 1008], Tile2; [0, 1008, 1008]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1008 (Total Size: 4096 )[Tile0, 1:[512x1], 8][D0, [0 x 8, 8]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[512x1], 8][D0, [0 x 8, 8]]
		Tile0: [0, 4096, 4096], Tile1: [0, 4096, 4096], Tile2; [0, 4096, 4096]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5104 (Total Size: 4 )[D1, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 4, 4]]
		Tile0: [0, 4, 4], Tile1: [0, 4, 4], Tile2; [0, 4, 4]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5108 (Total Size: 1 )[D1, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 1, 1]]
		Tile0: [0, 1, 1], Tile1: [0, 1, 1], Tile2; [0, 1, 1]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5112 (Total Size: 1 )[D1, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 1, 1]]
		Tile0: [0, 1, 1], Tile1: [0, 1, 1], Tile2; [0, 1, 1]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5116 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5180 (Total Size: 512 )[Tile0, 1:[512x1], 1][D1, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 1, 1]][Tile0, 1:[512x1], 1]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5692 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+1008);
	KerArg2->ColBuff = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (AE_1dcnn_RELU_L1_Memory+5116);
	KerArg2->Bias = (int * __restrict__) (AE_1dcnn_RELU_L1_Memory+5104);
	KerArg2->Out = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+5180);
	KerArg2->Scale = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+5108);
	KerArg2->ScaleN = (unsigned char * __restrict__) (AE_1dcnn_RELU_L1_Memory+5112);
	KerArg2->Tile_InFeat = (unsigned short int) (8);
	KerArg2->TotalInFeatures = (unsigned short int) (8);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (512);
	KerArg2->Tile_OutFeat = (unsigned short int) (1);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (512);
	KerArg2->Pad_Val = (unsigned short int) (134);
	KerArg2->Pad = (v4s) ((v4s){3,3,0,0});
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->FirstTile = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (7);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+1008), 4096, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+5116), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+5692), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+5104), 4, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+5108), 1, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+5112), 1, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->W_Offset = (int) (((int *)(AE_1dcnn_RELU_L1_Memory+5692))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) AE_1dcnn_RELU_L1_Memory+5180), 512, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
#pragma GCC diagnostic pop
int  AE_1dcnn_RELUCNN_Construct()

{
	int Error;

	AT_DEFAULTFLASH_FS_CONF_T DefaultFlashConf;
	AT_DEFAULTFLASH_FS_CONF_INIT(&DefaultFlashConf, AT_MEM_L3_DEFAULTFLASH, 0);
	AT_DEFAULTFLASH_FS_OPEN(&DefaultFlash, &DefaultFlashConf, 0, "AE_1dcnn_RELU_L3_Flash_Const.dat", &Error);
	if (Error) return AT_FLASH_OPEN_ERROR;

	AE_1dcnn_RELU_L2_Memory = (AT_L2_POINTER) AT_L2_ALLOC(0, 45940);
	if (AE_1dcnn_RELU_L2_Memory == 0) return AT_L2_OPEN_ERROR;
	AE_1dcnn_RELU_L2_Memory_Dyn = (AT_L2_POINTER) AT_L2_ALLOC(0, 12288);
	if (AE_1dcnn_RELU_L2_Memory_Dyn == 0) return AT_L2_OPEN_ERROR;
	AE_1dcnn_RELU_L1_Memory = (AT_L1_POINTER) AT_L1_ALLOC(0, 14484);
	if (AE_1dcnn_RELU_L1_Memory == 0) return AT_L1_OPEN_ERROR;
	AT_DEFAULTFLASH_FS_FC_EVENT _UchanHF1, *UchanHF1 = &_UchanHF1;
	/* Static Moving _encoder_conv_conv_0_backbone_backbone_0_backbone_0_0_conv_weights, size 3 from DefaultFlash at 45804 to (size 3) L2 at 45804..45806 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45804), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45804), 3, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__conv_212, size 4 from DefaultFlash at 45808 to (size 4) L2 at 45808..45811 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45808), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45808), 4, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S4_Mul_scale, size 1 from DefaultFlash at 45812 to (size 1) L2 at 45812..45812 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45812), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45812), 1, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S4_Mul_shift, size 1 from DefaultFlash at 45816 to (size 1) L2 at 45816..45816 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45816), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45816), 1, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S4_Infos, size 13 from DefaultFlash at 45524 to (size 13) L2 at 45524..45536 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45524), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45524), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _encoder_conv_conv_0_backbone_backbone_1_backbone_1_0_conv_weights, size 3 from DefaultFlash at 45820 to (size 3) L2 at 45820..45822 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45820), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45820), 3, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__conv_215, size 4 from DefaultFlash at 45824 to (size 4) L2 at 45824..45827 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45824), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45824), 4, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S7_Mul_scale, size 1 from DefaultFlash at 45828 to (size 1) L2 at 45828..45828 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45828), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45828), 1, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S7_Mul_shift, size 1 from DefaultFlash at 45832 to (size 1) L2 at 45832..45832 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45832), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45832), 1, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S7_Infos, size 13 from DefaultFlash at 45540 to (size 13) L2 at 45540..45552 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45540), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45540), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _encoder_conv_conv_0_projection_conv_weights, size 1 from DefaultFlash at 45836 to (size 1) L2 at 45836..45836 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45836), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45836), 1, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_encoder_conv_0_projection_bias, size 4 from DefaultFlash at 45840 to (size 4) L2 at 45840..45843 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45840), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45840), 4, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S10_Mul_scale, size 1 from DefaultFlash at 45844 to (size 1) L2 at 45844..45844 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45844), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45844), 1, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S10_Mul_shift, size 1 from DefaultFlash at 45848 to (size 1) L2 at 45848..45848 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45848), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45848), 1, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S10_Infos, size 13 from DefaultFlash at 45556 to (size 13) L2 at 45556..45568 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45556), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45556), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _encoder_conv_conv_0_downsampling_conv_weights, size 7 from DefaultFlash at 45748 to (size 7) L2 at 45748..45754 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45748), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45748), 7, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_encoder_conv_0_downsampling_bias, size 4 from DefaultFlash at 45852 to (size 4) L2 at 45852..45855 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45852), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45852), 4, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S14_Mul_scale, size 1 from DefaultFlash at 45856 to (size 1) L2 at 45856..45856 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45856), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45856), 1, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S14_Mul_shift, size 1 from DefaultFlash at 45860 to (size 1) L2 at 45860..45860 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45860), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45860), 1, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S14_Infos, size 13 from DefaultFlash at 45572 to (size 13) L2 at 45572..45584 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45572), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45572), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _encoder_conv_conv_1_backbone_backbone_0_backbone_0_0_conv_weights, size 32 from DefaultFlash at 44096 to (size 32) L2 at 44096..44127 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44096), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44096), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__conv_218, size 8 from DefaultFlash at 45756 to (size 8) L2 at 45756..45763 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45756), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45756), 8, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S17_Mul_scale, size 2 from DefaultFlash at 45864 to (size 2) L2 at 45864..45865 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45864), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45864), 2, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S17_Mul_shift, size 2 from DefaultFlash at 45868 to (size 2) L2 at 45868..45869 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45868), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45868), 2, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S17_Infos, size 20 from DefaultFlash at 45024 to (size 20) L2 at 45024..45043 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45024), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45024), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _encoder_conv_conv_1_backbone_backbone_1_backbone_1_0_conv_weights, size 32 from DefaultFlash at 44128 to (size 32) L2 at 44128..44159 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44128), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44128), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__conv_221, size 8 from DefaultFlash at 45764 to (size 8) L2 at 45764..45771 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45764), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45764), 8, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S20_Mul_scale, size 2 from DefaultFlash at 45872 to (size 2) L2 at 45872..45873 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45872), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45872), 2, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S20_Mul_shift, size 2 from DefaultFlash at 45876 to (size 2) L2 at 45876..45877 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45876), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45876), 2, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S20_Infos, size 20 from DefaultFlash at 45044 to (size 20) L2 at 45044..45063 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45044), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45044), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _encoder_conv_conv_1_projection_conv_weights, size 32 from DefaultFlash at 44160 to (size 32) L2 at 44160..44191 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44160), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44160), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_encoder_conv_1_projection_bias, size 8 from DefaultFlash at 45772 to (size 8) L2 at 45772..45779 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45772), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45772), 8, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S23_Mul_scale, size 2 from DefaultFlash at 45880 to (size 2) L2 at 45880..45881 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45880), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45880), 2, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S23_Mul_shift, size 2 from DefaultFlash at 45884 to (size 2) L2 at 45884..45885 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45884), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45884), 2, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S23_Infos, size 20 from DefaultFlash at 45064 to (size 20) L2 at 45064..45083 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45064), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45064), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _encoder_conv_conv_1_downsampling_conv_weights, size 32 from DefaultFlash at 44192 to (size 32) L2 at 44192..44223 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44192), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44192), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_encoder_conv_1_downsampling_bias, size 8 from DefaultFlash at 45780 to (size 8) L2 at 45780..45787 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45780), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45780), 8, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S27_Mul_scale, size 2 from DefaultFlash at 45888 to (size 2) L2 at 45888..45889 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45888), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45888), 2, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S27_Mul_shift, size 2 from DefaultFlash at 45892 to (size 2) L2 at 45892..45893 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45892), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45892), 2, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S27_Infos, size 20 from DefaultFlash at 45084 to (size 20) L2 at 45084..45103 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45084), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45084), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _encoder_conv_conv_2_backbone_backbone_0_backbone_0_0_conv_weights, size 64 from DefaultFlash at 43648 to (size 64) L2 at 43648..43711 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 43648), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 43648), 64, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__conv_224, size 16 from DefaultFlash at 45588 to (size 16) L2 at 45588..45603 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45588), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45588), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S30_Mul_scale, size 4 from DefaultFlash at 45896 to (size 4) L2 at 45896..45899 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45896), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45896), 4, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S30_Mul_shift, size 4 from DefaultFlash at 45900 to (size 4) L2 at 45900..45903 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45900), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45900), 4, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S30_Infos, size 20 from DefaultFlash at 45104 to (size 20) L2 at 45104..45123 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45104), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45104), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _encoder_conv_conv_2_backbone_backbone_1_backbone_1_0_conv_weights, size 64 from DefaultFlash at 43712 to (size 64) L2 at 43712..43775 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 43712), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 43712), 64, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__conv_227, size 16 from DefaultFlash at 45604 to (size 16) L2 at 45604..45619 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45604), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45604), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S33_Mul_scale, size 4 from DefaultFlash at 45904 to (size 4) L2 at 45904..45907 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45904), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45904), 4, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S33_Mul_shift, size 4 from DefaultFlash at 45908 to (size 4) L2 at 45908..45911 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45908), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45908), 4, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S33_Infos, size 20 from DefaultFlash at 45124 to (size 20) L2 at 45124..45143 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45124), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45124), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _encoder_conv_conv_2_projection_conv_weights, size 64 from DefaultFlash at 43776 to (size 64) L2 at 43776..43839 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 43776), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 43776), 64, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_encoder_conv_2_projection_bias, size 16 from DefaultFlash at 45620 to (size 16) L2 at 45620..45635 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45620), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45620), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S36_Mul_scale, size 4 from DefaultFlash at 45912 to (size 4) L2 at 45912..45915 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45912), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45912), 4, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S36_Mul_shift, size 4 from DefaultFlash at 45916 to (size 4) L2 at 45916..45919 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45916), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45916), 4, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S36_Infos, size 20 from DefaultFlash at 45144 to (size 20) L2 at 45144..45163 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45144), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45144), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _encoder_conv_conv_2_downsampling_conv_weights, size 128 from DefaultFlash at 41984 to (size 128) L2 at 41984..42111 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 41984), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 41984), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_encoder_conv_2_downsampling_bias, size 16 from DefaultFlash at 45636 to (size 16) L2 at 45636..45651 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45636), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45636), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S40_Mul_scale, size 4 from DefaultFlash at 45920 to (size 4) L2 at 45920..45923 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45920), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45920), 4, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S40_Mul_shift, size 4 from DefaultFlash at 45924 to (size 4) L2 at 45924..45927 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45924), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45924), 4, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S40_Infos, size 20 from DefaultFlash at 45164 to (size 20) L2 at 45164..45183 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45164), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45164), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _encoder_conv_conv_3_backbone_backbone_0_backbone_0_0_conv_weights, size 512 from DefaultFlash at 40448 to (size 512) L2 at 40448..40959 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 40448), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 40448), 512, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__conv_230, size 128 from DefaultFlash at 42112 to (size 128) L2 at 42112..42239 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 42112), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 42112), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S43_Mul_scale, size 32 from DefaultFlash at 44224 to (size 32) L2 at 44224..44255 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44224), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44224), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S43_Mul_shift, size 32 from DefaultFlash at 44256 to (size 32) L2 at 44256..44287 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44256), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44256), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S43_Infos, size 20 from DefaultFlash at 45184 to (size 20) L2 at 45184..45203 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45184), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45184), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _encoder_conv_conv_3_backbone_backbone_1_backbone_1_0_conv_weights, size 3072 from DefaultFlash at 15360 to (size 3072) L2 at 15360..18431 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 15360), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 15360), 3072, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__conv_233, size 128 from DefaultFlash at 42240 to (size 128) L2 at 42240..42367 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 42240), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 42240), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S46_Mul_scale, size 32 from DefaultFlash at 44288 to (size 32) L2 at 44288..44319 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44288), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44288), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S46_Mul_shift, size 32 from DefaultFlash at 44320 to (size 32) L2 at 44320..44351 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44320), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44320), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S46_Infos, size 20 from DefaultFlash at 45204 to (size 20) L2 at 45204..45223 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45204), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45204), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _encoder_conv_conv_3_projection_conv_weights, size 512 from DefaultFlash at 40960 to (size 512) L2 at 40960..41471 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 40960), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 40960), 512, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_encoder_conv_3_projection_bias, size 128 from DefaultFlash at 42368 to (size 128) L2 at 42368..42495 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 42368), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 42368), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S49_Mul_scale, size 32 from DefaultFlash at 44352 to (size 32) L2 at 44352..44383 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44352), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44352), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S49_Mul_shift, size 32 from DefaultFlash at 44384 to (size 32) L2 at 44384..44415 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44384), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44384), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S49_Infos, size 20 from DefaultFlash at 45224 to (size 20) L2 at 45224..45243 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45224), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45224), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _encoder_conv_conv_3_downsampling_conv_weights, size 7168 from DefaultFlash at 0 to (size 7168) L2 at 0..7167 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 0), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 0), 7168, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_encoder_conv_3_downsampling_bias, size 128 from DefaultFlash at 42496 to (size 128) L2 at 42496..42623 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 42496), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 42496), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S53_Mul_scale, size 32 from DefaultFlash at 44416 to (size 32) L2 at 44416..44447 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44416), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44416), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S53_Mul_shift, size 32 from DefaultFlash at 44448 to (size 32) L2 at 44448..44479 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44448), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44448), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S53_Infos, size 20 from DefaultFlash at 45244 to (size 20) L2 at 45244..45263 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45244), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45244), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _decoder_deconv_deconv_0_backbone_backbone_0_backbone_0_0_convtranspose_weights, size 3072 from DefaultFlash at 18432 to (size 3072) L2 at 18432..21503 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 18432), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 18432), 3072, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_decoder_deconv_0_backbone_0_0_bias, size 128 from DefaultFlash at 42624 to (size 128) L2 at 42624..42751 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 42624), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 42624), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S56_Mul_scale, size 32 from DefaultFlash at 44480 to (size 32) L2 at 44480..44511 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44480), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44480), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S56_Mul_shift, size 32 from DefaultFlash at 44512 to (size 32) L2 at 44512..44543 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44512), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44512), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S56_Infos, size 20 from DefaultFlash at 45264 to (size 20) L2 at 45264..45283 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45264), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45264), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _decoder_deconv_deconv_0_backbone_backbone_1_backbone_1_0_convtranspose_weights, size 3072 from DefaultFlash at 21504 to (size 3072) L2 at 21504..24575 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 21504), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 21504), 3072, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_decoder_deconv_0_backbone_1_0_bias, size 128 from DefaultFlash at 42752 to (size 128) L2 at 42752..42879 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 42752), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 42752), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S59_Mul_scale, size 32 from DefaultFlash at 44544 to (size 32) L2 at 44544..44575 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44544), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44544), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S59_Mul_shift, size 32 from DefaultFlash at 44576 to (size 32) L2 at 44576..44607 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44576), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44576), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S59_Infos, size 20 from DefaultFlash at 45284 to (size 20) L2 at 45284..45303 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45284), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45284), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _decoder_deconv_deconv_0_upsampling_convtranspose_weights, size 4096 from DefaultFlash at 7168 to (size 4096) L2 at 7168..11263 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 7168), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 7168), 4096, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_decoder_deconv_0_upsampling_bias, size 128 from DefaultFlash at 42880 to (size 128) L2 at 42880..43007 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 42880), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 42880), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S63_Mul_scale, size 32 from DefaultFlash at 44608 to (size 32) L2 at 44608..44639 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44608), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44608), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S63_Mul_shift, size 32 from DefaultFlash at 44640 to (size 32) L2 at 44640..44671 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44640), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44640), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S63_Infos, size 20 from DefaultFlash at 45304 to (size 20) L2 at 45304..45323 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45304), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45304), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _decoder_deconv_deconv_1_backbone_backbone_0_backbone_0_0_convtranspose_weights, size 3072 from DefaultFlash at 24576 to (size 3072) L2 at 24576..27647 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 24576), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 24576), 3072, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_decoder_deconv_1_backbone_0_0_bias, size 128 from DefaultFlash at 43008 to (size 128) L2 at 43008..43135 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 43008), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 43008), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S66_Mul_scale, size 32 from DefaultFlash at 44672 to (size 32) L2 at 44672..44703 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44672), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44672), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S66_Mul_shift, size 32 from DefaultFlash at 44704 to (size 32) L2 at 44704..44735 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44704), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44704), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S66_Infos, size 20 from DefaultFlash at 45324 to (size 20) L2 at 45324..45343 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45324), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45324), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _decoder_deconv_deconv_1_backbone_backbone_1_backbone_1_0_convtranspose_weights, size 3072 from DefaultFlash at 27648 to (size 3072) L2 at 27648..30719 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 27648), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 27648), 3072, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_decoder_deconv_1_backbone_1_0_bias, size 128 from DefaultFlash at 43136 to (size 128) L2 at 43136..43263 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 43136), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 43136), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S69_Mul_scale, size 32 from DefaultFlash at 44736 to (size 32) L2 at 44736..44767 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44736), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44736), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S69_Mul_shift, size 32 from DefaultFlash at 44768 to (size 32) L2 at 44768..44799 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44768), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44768), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S69_Infos, size 20 from DefaultFlash at 45344 to (size 20) L2 at 45344..45363 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45344), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45344), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _decoder_deconv_deconv_1_upsampling_convtranspose_weights, size 4096 from DefaultFlash at 11264 to (size 4096) L2 at 11264..15359 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 11264), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 11264), 4096, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_decoder_deconv_1_upsampling_bias, size 128 from DefaultFlash at 43264 to (size 128) L2 at 43264..43391 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 43264), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 43264), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S73_Mul_scale, size 32 from DefaultFlash at 44800 to (size 32) L2 at 44800..44831 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44800), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44800), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S73_Mul_shift, size 32 from DefaultFlash at 44832 to (size 32) L2 at 44832..44863 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44832), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44832), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S73_Infos, size 20 from DefaultFlash at 45364 to (size 20) L2 at 45364..45383 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45364), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45364), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _decoder_deconv_deconv_2_backbone_backbone_0_backbone_0_0_convtranspose_weights, size 3072 from DefaultFlash at 30720 to (size 3072) L2 at 30720..33791 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 30720), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 30720), 3072, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_decoder_deconv_2_backbone_0_0_bias, size 128 from DefaultFlash at 43392 to (size 128) L2 at 43392..43519 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 43392), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 43392), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S76_Mul_scale, size 32 from DefaultFlash at 44864 to (size 32) L2 at 44864..44895 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44864), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44864), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S76_Mul_shift, size 32 from DefaultFlash at 44896 to (size 32) L2 at 44896..44927 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44896), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44896), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S76_Infos, size 20 from DefaultFlash at 45384 to (size 20) L2 at 45384..45403 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45384), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45384), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _decoder_deconv_deconv_2_backbone_backbone_1_backbone_1_0_convtranspose_weights, size 3072 from DefaultFlash at 33792 to (size 3072) L2 at 33792..36863 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 33792), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 33792), 3072, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_decoder_deconv_2_backbone_1_0_bias, size 128 from DefaultFlash at 43520 to (size 128) L2 at 43520..43647 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 43520), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 43520), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S79_Mul_scale, size 32 from DefaultFlash at 44928 to (size 32) L2 at 44928..44959 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44928), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44928), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S79_Mul_shift, size 32 from DefaultFlash at 44960 to (size 32) L2 at 44960..44991 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44960), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44960), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S79_Infos, size 20 from DefaultFlash at 45404 to (size 20) L2 at 45404..45423 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45404), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45404), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _decoder_deconv_deconv_2_upsampling_convtranspose_weights, size 2048 from DefaultFlash at 36864 to (size 2048) L2 at 36864..38911 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 36864), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 36864), 2048, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_decoder_deconv_2_upsampling_bias, size 64 from DefaultFlash at 43840 to (size 64) L2 at 43840..43903 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 43840), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 43840), 64, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S83_Mul_scale, size 16 from DefaultFlash at 45652 to (size 16) L2 at 45652..45667 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45652), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45652), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S83_Mul_shift, size 16 from DefaultFlash at 45668 to (size 16) L2 at 45668..45683 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45668), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45668), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S83_Infos, size 20 from DefaultFlash at 45424 to (size 20) L2 at 45424..45443 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45424), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45424), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _decoder_deconv_deconv_3_backbone_backbone_0_backbone_0_0_convtranspose_weights, size 768 from DefaultFlash at 38912 to (size 768) L2 at 38912..39679 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 38912), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 38912), 768, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_decoder_deconv_3_backbone_0_0_bias, size 64 from DefaultFlash at 43904 to (size 64) L2 at 43904..43967 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 43904), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 43904), 64, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S86_Mul_scale, size 16 from DefaultFlash at 45684 to (size 16) L2 at 45684..45699 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45684), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45684), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S86_Mul_shift, size 16 from DefaultFlash at 45700 to (size 16) L2 at 45700..45715 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45700), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45700), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S86_Infos, size 20 from DefaultFlash at 45444 to (size 20) L2 at 45444..45463 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45444), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45444), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _decoder_deconv_deconv_3_backbone_backbone_1_backbone_1_0_convtranspose_weights, size 768 from DefaultFlash at 39680 to (size 768) L2 at 39680..40447 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 39680), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 39680), 768, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_decoder_deconv_3_backbone_1_0_bias, size 64 from DefaultFlash at 43968 to (size 64) L2 at 43968..44031 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 43968), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 43968), 64, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S89_Mul_scale, size 16 from DefaultFlash at 45716 to (size 16) L2 at 45716..45731 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45716), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45716), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S89_Mul_shift, size 16 from DefaultFlash at 45732 to (size 16) L2 at 45732..45747 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45732), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45732), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S89_Infos, size 20 from DefaultFlash at 45464 to (size 20) L2 at 45464..45483 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45464), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45464), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _decoder_deconv_deconv_3_upsampling_convtranspose_weights, size 512 from DefaultFlash at 41472 to (size 512) L2 at 41472..41983 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 41472), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 41472), 512, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_decoder_deconv_3_upsampling_bias, size 32 from DefaultFlash at 44992 to (size 32) L2 at 44992..45023 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44992), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44992), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S93_Mul_scale, size 8 from DefaultFlash at 45788 to (size 8) L2 at 45788..45795 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45788), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45788), 8, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S93_Mul_shift, size 8 from DefaultFlash at 45796 to (size 8) L2 at 45796..45803 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45796), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45796), 8, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S93_Infos, size 20 from DefaultFlash at 45484 to (size 20) L2 at 45484..45503 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45484), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45484), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _decoder_deconv_deconv_4_conv_weights, size 64 from DefaultFlash at 44032 to (size 64) L2 at 44032..44095 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 44032), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 44032), 64, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_decoder_deconv_4_bias, size 4 from DefaultFlash at 45928 to (size 4) L2 at 45928..45931 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45928), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45928), 4, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S96_Mul_scale, size 1 from DefaultFlash at 45932 to (size 1) L2 at 45932..45932 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45932), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45932), 1, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S96_Mul_shift, size 1 from DefaultFlash at 45936 to (size 1) L2 at 45936..45936 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45936), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45936), 1, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S96_Infos, size 20 from DefaultFlash at 45504 to (size 20) L2 at 45504..45523 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) AE_1dcnn_RELU_L3_Flash + 45504), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) AE_1dcnn_RELU_L2_Memory + 45504), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	return AT_NO_ERROR;
}
void AE_1dcnn_RELUCNN_ConstructCluster()

{
}
int  AE_1dcnn_RELUCNN_Destruct()

{
	AT_L2_FREE(0, AE_1dcnn_RELU_L2_Memory_Dyn, 12288);
	AT_L2_FREE(0, AE_1dcnn_RELU_L2_Memory, 45940);
	AT_L1_FREE(0, AE_1dcnn_RELU_L1_Memory, 14484);
	AT_DEFAULTFLASH_FS_CLOSE(&DefaultFlash);
	return 0;
}
int AE_1dcnn_RELUCNN_Memory(AT_MEM_TYPE Which)

{
	switch (Which) {
		case AT_L1_MEM:     return 14484; /* L1 Memory */
		case AT_L2_MEM:     return 45940; /* L2 Memory, permanent */
		case AT_L2_DYN_MEM: return 12288; /* L2 Memory, dynamic */
		case AT_L3_MEM:     return 0; /* L3 Memory, permanent */
		case AT_L3_DYN_MEM: return 0; /* L3 Memory, dynamic */
		default:            return 0;
	}
}
unsigned int AT_GraphPerf[38];
unsigned int AT_GraphPerf_CNN_Total = 0;
unsigned int AT_GraphOperInfosNames[38] = {
	512,
	2048,
	1536,
	512,
	1792,
	1536,
	3072,
	512,
	512,
	3584,
	3072,
	6144,
	1024,
	512,
	7168,
	8192,
	24576,
	196608,
	2048,
	229376,
	98304,
	98304,
	1024,
	262144,
	196608,
	196608,
	2048,
	524288,
	393216,
	393216,
	4096,
	524288,
	196608,
	196608,
	4096,
	262144,
	28672,
	0,
};
char *AT_GraphNodeNames[38] = {
	"S10__encoder_conv_conv_0_projection_Conv",
	"S4__encoder_conv_conv_0_backbone_backbone_0_backbone_0_0_Conv_fusion",
	"S7__encoder_conv_conv_0_backbone_backbone_1_backbone_1_0_Conv_fusion",
	"S11_expr_0",
	"S14__encoder_conv_conv_0_downsampling_Conv",
	"S17__encoder_conv_conv_1_backbone_backbone_0_backbone_0_0_Conv_fusion",
	"S20__encoder_conv_conv_1_backbone_backbone_1_backbone_1_0_Conv_fusion",
	"S23__encoder_conv_conv_1_projection_Conv",
	"S24_expr_1",
	"S27__encoder_conv_conv_1_downsampling_Conv",
	"S30__encoder_conv_conv_2_backbone_backbone_0_backbone_0_0_Conv_fusion",
	"S33__encoder_conv_conv_2_backbone_backbone_1_backbone_1_0_Conv_fusion",
	"S36__encoder_conv_conv_2_projection_Conv",
	"S37_expr_2",
	"S40__encoder_conv_conv_2_downsampling_Conv",
	"S49__encoder_conv_conv_3_projection_Conv",
	"S43__encoder_conv_conv_3_backbone_backbone_0_backbone_0_0_Conv_fusion",
	"S46__encoder_conv_conv_3_backbone_backbone_1_backbone_1_0_Conv_fusion",
	"S50_expr_3",
	"S53__encoder_conv_conv_3_downsampling_Conv",
	"S56__decoder_deconv_deconv_0_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion",
	"S59__decoder_deconv_deconv_0_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion",
	"S60_expr_4",
	"S63__decoder_deconv_deconv_0_upsampling_ConvTranspose",
	"S66__decoder_deconv_deconv_1_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion",
	"S69__decoder_deconv_deconv_1_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion",
	"S70_expr_5",
	"S73__decoder_deconv_deconv_1_upsampling_ConvTranspose",
	"S76__decoder_deconv_deconv_2_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion",
	"S79__decoder_deconv_deconv_2_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion",
	"S80_expr_6",
	"S83__decoder_deconv_deconv_2_upsampling_ConvTranspose",
	"S86__decoder_deconv_deconv_3_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion",
	"S89__decoder_deconv_deconv_3_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion",
	"S90_expr_7",
	"S93__decoder_deconv_deconv_3_upsampling_ConvTranspose",
	"S96__decoder_deconv_deconv_4_Conv",
	"IO_Wait",
};
int  AE_1dcnn_RELUCNN(
		signed char * __restrict__ Input_1,
		unsigned char * __restrict__ Output_1)

{
	unsigned int Start_IO;
	AT_GraphPerf_CNN_Total = gap_cl_readhwtimer();
	AT_GraphPerf[0] = gap_cl_readhwtimer();
	AT_GraphPerf[37] = 0;
	S10__encoder_conv_conv_0_projection_Conv(
		((signed char * __restrict__) Input_1), /* In */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45836)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+45840)), /* Bias */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+1024)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45844)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45848)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45556)) /* Infos */
	);
	AT_GraphPerf[0] = gap_cl_readhwtimer() - AT_GraphPerf[0];
	AT_GraphPerf[1] = gap_cl_readhwtimer();
	S4__encoder_conv_conv_0_backbone_backbone_0_backbone_0_0_Conv_fusion(
		((signed char * __restrict__) Input_1), /* In */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45804)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+45808)), /* Bias */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45812)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45816)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45524)) /* Infos */
	);
	AT_GraphPerf[1] = gap_cl_readhwtimer() - AT_GraphPerf[1];
	AT_GraphPerf[2] = gap_cl_readhwtimer();
	S7__encoder_conv_conv_0_backbone_backbone_1_backbone_1_0_Conv_fusion(
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* In */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45820)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+45824)), /* Bias */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+512)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45828)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45832)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45540)) /* Infos */
	);
	AT_GraphPerf[2] = gap_cl_readhwtimer() - AT_GraphPerf[2];
	AT_GraphPerf[3] = gap_cl_readhwtimer();
	S11_expr_0(
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+1024)), /* expr_0_in_0 */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+512)), /* expr_0_in_1 */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)) /* expr_0_out_0 */
	);
	AT_GraphPerf[3] = gap_cl_readhwtimer() - AT_GraphPerf[3];
	AT_GraphPerf[4] = gap_cl_readhwtimer();
	S14__encoder_conv_conv_0_downsampling_Conv(
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* In */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45748)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+45852)), /* Bias */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+512)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45856)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45860)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45572)) /* Infos */
	);
	AT_GraphPerf[4] = gap_cl_readhwtimer() - AT_GraphPerf[4];
	AT_GraphPerf[5] = gap_cl_readhwtimer();
	S17__encoder_conv_conv_1_backbone_backbone_0_backbone_0_0_Conv_fusion(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+512)), /* In */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44096)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+45756)), /* Bias */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45864)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45868)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45024)) /* Infos */
	);
	AT_GraphPerf[5] = gap_cl_readhwtimer() - AT_GraphPerf[5];
	AT_GraphPerf[6] = gap_cl_readhwtimer();
	S20__encoder_conv_conv_1_backbone_backbone_1_backbone_1_0_Conv_fusion(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44128)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+45764)), /* Bias */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+1024)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45872)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45876)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45044)) /* Infos */
	);
	AT_GraphPerf[6] = gap_cl_readhwtimer() - AT_GraphPerf[6];
	AT_GraphPerf[7] = gap_cl_readhwtimer();
	S23__encoder_conv_conv_1_projection_Conv(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+512)), /* In */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44160)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+45772)), /* Bias */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45880)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45884)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45064)) /* Infos */
	);
	AT_GraphPerf[7] = gap_cl_readhwtimer() - AT_GraphPerf[7];
	AT_GraphPerf[8] = gap_cl_readhwtimer();
	S24_expr_1(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* expr_1_in_0 */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+1024)), /* expr_1_in_1 */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+512)) /* expr_1_out_0 */
	);
	AT_GraphPerf[8] = gap_cl_readhwtimer() - AT_GraphPerf[8];
	AT_GraphPerf[9] = gap_cl_readhwtimer();
	S27__encoder_conv_conv_1_downsampling_Conv(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+512)), /* In */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44192)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+45780)), /* Bias */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+1024)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45888)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45892)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45084)) /* Infos */
	);
	AT_GraphPerf[9] = gap_cl_readhwtimer() - AT_GraphPerf[9];
	AT_GraphPerf[10] = gap_cl_readhwtimer();
	S30__encoder_conv_conv_2_backbone_backbone_0_backbone_0_0_Conv_fusion(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+1024)), /* In */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+43648)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+45588)), /* Bias */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45896)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45900)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45104)) /* Infos */
	);
	AT_GraphPerf[10] = gap_cl_readhwtimer() - AT_GraphPerf[10];
	AT_GraphPerf[11] = gap_cl_readhwtimer();
	S33__encoder_conv_conv_2_backbone_backbone_1_backbone_1_0_Conv_fusion(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+43712)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+45604)), /* Bias */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+1280)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45904)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45908)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45124)) /* Infos */
	);
	AT_GraphPerf[11] = gap_cl_readhwtimer() - AT_GraphPerf[11];
	AT_GraphPerf[12] = gap_cl_readhwtimer();
	S36__encoder_conv_conv_2_projection_Conv(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+1024)), /* In */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+43776)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+45620)), /* Bias */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45912)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45916)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45144)) /* Infos */
	);
	AT_GraphPerf[12] = gap_cl_readhwtimer() - AT_GraphPerf[12];
	AT_GraphPerf[13] = gap_cl_readhwtimer();
	S37_expr_2(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* expr_2_in_0 */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+1280)), /* expr_2_in_1 */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+512)) /* expr_2_out_0 */
	);
	AT_GraphPerf[13] = gap_cl_readhwtimer() - AT_GraphPerf[13];
	AT_GraphPerf[14] = gap_cl_readhwtimer();
	S40__encoder_conv_conv_2_downsampling_Conv(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+512)), /* In */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+41984)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+45636)), /* Bias */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45920)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45924)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45164)) /* Infos */
	);
	AT_GraphPerf[14] = gap_cl_readhwtimer() - AT_GraphPerf[14];
	AT_GraphPerf[15] = gap_cl_readhwtimer();
	S49__encoder_conv_conv_3_projection_Conv(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+40960)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+42368)), /* Bias */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+4096)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44352)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44384)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45224)) /* Infos */
	);
	AT_GraphPerf[15] = gap_cl_readhwtimer() - AT_GraphPerf[15];
	AT_GraphPerf[16] = gap_cl_readhwtimer();
	S43__encoder_conv_conv_3_backbone_backbone_0_backbone_0_0_Conv_fusion(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+40448)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+42112)), /* Bias */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+2048)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44224)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44256)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45184)) /* Infos */
	);
	AT_GraphPerf[16] = gap_cl_readhwtimer() - AT_GraphPerf[16];
	AT_GraphPerf[17] = gap_cl_readhwtimer();
	S46__encoder_conv_conv_3_backbone_backbone_1_backbone_1_0_Conv_fusion(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+2048)), /* In */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+15360)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+42240)), /* Bias */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44288)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44320)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45204)) /* Infos */
	);
	AT_GraphPerf[17] = gap_cl_readhwtimer() - AT_GraphPerf[17];
	AT_GraphPerf[18] = gap_cl_readhwtimer();
	S50_expr_3(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+4096)), /* expr_3_in_0 */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* expr_3_in_1 */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+2048)) /* expr_3_out_0 */
	);
	AT_GraphPerf[18] = gap_cl_readhwtimer() - AT_GraphPerf[18];
	AT_GraphPerf[19] = gap_cl_readhwtimer();
	S53__encoder_conv_conv_3_downsampling_Conv(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+2048)), /* In */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+0)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+42496)), /* Bias */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44416)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44448)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45244)) /* Infos */
	);
	AT_GraphPerf[19] = gap_cl_readhwtimer() - AT_GraphPerf[19];
	AT_GraphPerf[20] = gap_cl_readhwtimer();
	S56__decoder_deconv_deconv_0_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+18432)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+42624)), /* Bias */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+1024)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44480)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44512)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45264)) /* Infos */
	);
	AT_GraphPerf[20] = gap_cl_readhwtimer() - AT_GraphPerf[20];
	AT_GraphPerf[21] = gap_cl_readhwtimer();
	S59__decoder_deconv_deconv_0_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+1024)), /* In */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+21504)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+42752)), /* Bias */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+3072)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44544)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44576)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45284)) /* Infos */
	);
	AT_GraphPerf[21] = gap_cl_readhwtimer() - AT_GraphPerf[21];
	AT_GraphPerf[22] = gap_cl_readhwtimer();
	S60_expr_4(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+3072)), /* expr_4_in_0 */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* expr_4_in_1 */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+2048)) /* expr_4_out_0 */
	);
	AT_GraphPerf[22] = gap_cl_readhwtimer() - AT_GraphPerf[22];
	AT_GraphPerf[23] = gap_cl_readhwtimer();
	S63__decoder_deconv_deconv_0_upsampling_ConvTranspose(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+2048)), /* In */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+7168)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+42880)), /* Bias */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44608)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44640)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45304)) /* Infos */
	);
	AT_GraphPerf[23] = gap_cl_readhwtimer() - AT_GraphPerf[23];
	AT_GraphPerf[24] = gap_cl_readhwtimer();
	S66__decoder_deconv_deconv_1_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+24576)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+43008)), /* Bias */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+2048)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44672)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44704)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45324)) /* Infos */
	);
	AT_GraphPerf[24] = gap_cl_readhwtimer() - AT_GraphPerf[24];
	AT_GraphPerf[25] = gap_cl_readhwtimer();
	S69__decoder_deconv_deconv_1_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+2048)), /* In */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+27648)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+43136)), /* Bias */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+4096)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44736)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44768)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45344)) /* Infos */
	);
	AT_GraphPerf[25] = gap_cl_readhwtimer() - AT_GraphPerf[25];
	AT_GraphPerf[26] = gap_cl_readhwtimer();
	S70_expr_5(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+4096)), /* expr_5_in_0 */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* expr_5_in_1 */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+2048)) /* expr_5_out_0 */
	);
	AT_GraphPerf[26] = gap_cl_readhwtimer() - AT_GraphPerf[26];
	AT_GraphPerf[27] = gap_cl_readhwtimer();
	S73__decoder_deconv_deconv_1_upsampling_ConvTranspose(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+2048)), /* In */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+11264)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+43264)), /* Bias */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+8192)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44800)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44832)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45364)) /* Infos */
	);
	AT_GraphPerf[27] = gap_cl_readhwtimer() - AT_GraphPerf[27];
	AT_GraphPerf[28] = gap_cl_readhwtimer();
	S76__decoder_deconv_deconv_2_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+8192)), /* In */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+30720)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+43392)), /* Bias */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44864)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44896)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45384)) /* Infos */
	);
	AT_GraphPerf[28] = gap_cl_readhwtimer() - AT_GraphPerf[28];
	AT_GraphPerf[29] = gap_cl_readhwtimer();
	S79__decoder_deconv_deconv_2_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+33792)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+43520)), /* Bias */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+4096)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44928)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44960)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45404)) /* Infos */
	);
	AT_GraphPerf[29] = gap_cl_readhwtimer() - AT_GraphPerf[29];
	AT_GraphPerf[30] = gap_cl_readhwtimer();
	S80_expr_6(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+4096)), /* expr_6_in_0 */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+8192)), /* expr_6_in_1 */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)) /* expr_6_out_0 */
	);
	AT_GraphPerf[30] = gap_cl_readhwtimer() - AT_GraphPerf[30];
	AT_GraphPerf[31] = gap_cl_readhwtimer();
	S83__decoder_deconv_deconv_2_upsampling_ConvTranspose(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+36864)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+43840)), /* Bias */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+4096)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45652)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45668)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45424)) /* Infos */
	);
	AT_GraphPerf[31] = gap_cl_readhwtimer() - AT_GraphPerf[31];
	AT_GraphPerf[32] = gap_cl_readhwtimer();
	S86__decoder_deconv_deconv_3_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+4096)), /* In */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+38912)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+43904)), /* Bias */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45684)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45700)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45444)) /* Infos */
	);
	AT_GraphPerf[32] = gap_cl_readhwtimer() - AT_GraphPerf[32];
	AT_GraphPerf[33] = gap_cl_readhwtimer();
	S89__decoder_deconv_deconv_3_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+39680)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+43968)), /* Bias */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+8192)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45716)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45732)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45464)) /* Infos */
	);
	AT_GraphPerf[33] = gap_cl_readhwtimer() - AT_GraphPerf[33];
	AT_GraphPerf[34] = gap_cl_readhwtimer();
	S90_expr_7(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+8192)), /* expr_7_in_0 */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+4096)), /* expr_7_in_1 */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)) /* expr_7_out_0 */
	);
	AT_GraphPerf[34] = gap_cl_readhwtimer() - AT_GraphPerf[34];
	AT_GraphPerf[35] = gap_cl_readhwtimer();
	S93__decoder_deconv_deconv_3_upsampling_ConvTranspose(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+41472)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+44992)), /* Bias */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+4096)), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45788)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45796)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45484)) /* Infos */
	);
	AT_GraphPerf[35] = gap_cl_readhwtimer() - AT_GraphPerf[35];
	AT_GraphPerf[36] = gap_cl_readhwtimer();
	S96__decoder_deconv_deconv_4_Conv(
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory_Dyn+4096)), /* In */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+44032)), /* Filter */
		((signed int * __restrict__) (AE_1dcnn_RELU_L2_Memory+45928)), /* Bias */
		((unsigned char * __restrict__) Output_1), /* Out */
		((unsigned char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45932)), /* Scale */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45936)), /* ScaleN */
		((signed char * __restrict__) (AE_1dcnn_RELU_L2_Memory+45504)) /* Infos */
	);
	AT_GraphPerf[36] = gap_cl_readhwtimer() - AT_GraphPerf[36];
	AT_GraphPerf_CNN_Total = gap_cl_readhwtimer() - AT_GraphPerf_CNN_Total;
	return 0;
}
