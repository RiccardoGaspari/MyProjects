#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#include "ARMA_30_10_Bin_AllKernels.h"
#ifdef __EMUL__
unsigned int __L3_Read, __L3_Write, __L2_Read, __L2_Write;
#endif
L1_CL_MEM AT_L1_POINTER ARMA_30_10_Bin_All_L1_Memory;
L2_MEM AT_L2_POINTER ARMA_30_10_Bin_All_L2_Memory;
L2_MEM AT_L2_POINTER ARMA_30_10_Bin_All_L2_Memory_Dyn;
static AT_DEFAULTFLASH_FS_T DefaultFlash;
void  S3_ARMA_30_10_Bin_All_conv2d_Conv2D_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 3460 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;
	Ker_MM_Pool_USQ8_T S_KerArg3, *KerArg3 = &S_KerArg3;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 30, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 1, Tiled: 1]
	Ker Arg: ConvOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 740 (Total Size: 2400 )[Tile0, 1:[1x19], 120][D1, [0 x 120, 120]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 120, 120]][Tile0, 1:[1x19], 120]
		Tile0: [0, 2280, 2280], Tile1: [0, 2280, 2280], Tile2; [0, 2280, 2280]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 56 (Total Size: 20 )[Tile0, 1:[1x20], 1][D0, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x20], 1][D0, [0 x 1, 1]]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 76 (Total Size: 120 )[D1, [0 x 120, 120]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 120, 120]]
		Tile0: [0, 120, 120], Tile1: [0, 120, 120], Tile2; [0, 120, 120]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 196 (Total Size: 30 )[D1, [0 x 30, 30]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 30, 30]]
		Tile0: [0, 30, 30], Tile1: [0, 30, 30], Tile2; [0, 30, 30]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 228 (Total Size: 30 )[D1, [0 x 30, 30]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 30, 30]]
		Tile0: [0, 30, 30], Tile1: [0, 30, 30], Tile2; [0, 30, 30]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 260 (Total Size: 480 )[D1, [0 x 480, 480]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 480, 480]]
		Tile0: [0, 480, 480], Tile1: [0, 480, 480], Tile2; [0, 480, 480]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 54 )[Tile0, 1:[54x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[54x1], 1]
		Tile0: [0, 54, 54], Tile1: [0, 54, 54], Tile2; [0, 54, 54]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3140 (Total Size: 300 )[Tile0, 1:[1x10], 30][D1, [0 x 30, 30]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 30, 30]][Tile0, 1:[1x10], 30]
		Tile0: [0, 300, 300], Tile1: [0, 300, 300], Tile2; [0, 300, 300]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3440 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+56);
	KerArg2->ColBuff = (unsigned char * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+260);
	KerArg2->Bias = (int * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+76);
	KerArg2->Out = (unsigned char * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+740);
	KerArg2->Scale = (unsigned char * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+196);
	KerArg2->ScaleN = (unsigned char * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+228);
	KerArg2->Tile_InFeat = (unsigned short int) (1);
	KerArg2->TotalInFeatures = (unsigned short int) (1);
	KerArg2->Tile_InH = (unsigned short int) (20);
	KerArg2->Tile_InW = (unsigned short int) (1);
	KerArg2->Tile_OutFeat = (unsigned short int) (30);
	KerArg2->Tile_OutH = (unsigned short int) (19);
	KerArg2->Tile_OutW = (unsigned short int) (1);
	KerArg2->Pad_Val = (unsigned short int) (120);
	KerArg2->Pad = (v4s) ((v4s){0,0,1,0});
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->FirstTile = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (1);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Fy = (unsigned char) (3);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (0);
	KerArg3->In = (unsigned char * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+740);
	KerArg3->W = (unsigned short int) (1);
	KerArg3->H = (unsigned short int) (19);
	KerArg3->Fx = (unsigned short int) (1);
	KerArg3->Fy = (unsigned short int) (1);
	KerArg3->Sx = (unsigned char) (2);
	KerArg3->Sy = (unsigned char) (2);
	KerArg3->FirstTile = (unsigned char) ((1));
	KerArg3->Pad = (v4s) 0;
	KerArg3->Out = (unsigned char * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+3140);
	KerArg3->Feat = (unsigned short int) (30);
	KerArg3->Wo = (unsigned short int) (1);
	KerArg3->Ho = (unsigned short int) (10);
	KerArg3->Infos = (signed char * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+3440);
	KerArg3->Extra = (void *) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+260), 480, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+76), 120, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+196), 30, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+228), 30, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+56), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+3440), 20, 0, 0);
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
				KerArg2->W_Offset = (int) (((int *)(ARMA_30_10_Bin_All_L1_Memory+3440))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv2DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv2DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
			/*====================== Call Kernel LOC_D0_EPILOG =========================*/
			AT_FORK(gap_ncore(), (void *) KerParMaxPoolNxMStrideSxSy_HWC_USQ8, (void *) KerArg3);
			__CALL(KerParMaxPoolNxMStrideSxSy_HWC_USQ8, KerArg3);
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+3140), 300, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S6_ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		signed char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 3064 bytes, L2 buffer: 0 bytes */
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
		[D1 Dim: Init: 10, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 30, Tiled: 1]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 1620 )[Tile0, 1:[1620x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1620x1], 1]
		Tile0: [0, 1620, 1620], Tile1: [0, 1620, 1620], Tile2; [0, 1620, 1620]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1620 (Total Size: 300 )[Tile0, 1:[1x10], 30][D0, [0 x 30, 30]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x10], 30][D0, [0 x 30, 30]]
		Tile0: [0, 300, 300], Tile1: [0, 300, 300], Tile2; [0, 300, 300]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1920 (Total Size: 40 )[D1, [0 x 40, 40]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 40, 40]]
		Tile0: [0, 40, 40], Tile1: [0, 40, 40], Tile2; [0, 40, 40]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1960 (Total Size: 10 )[D1, [0 x 10, 10]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 10, 10]]
		Tile0: [0, 10, 10], Tile1: [0, 10, 10], Tile2; [0, 10, 10]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1972 (Total Size: 10 )[D1, [0 x 10, 10]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 10, 10]]
		Tile0: [0, 10, 10], Tile1: [0, 10, 10], Tile2; [0, 10, 10]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1984 (Total Size: 960 )[D1, [0 x 960, 960]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 960, 960]]
		Tile0: [0, 960, 960], Tile1: [0, 960, 960], Tile2; [0, 960, 960]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2944 (Total Size: 100 )[Tile0, 1:[1x10], 10][D1, [0 x 10, 10]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 10, 10]][Tile0, 1:[1x10], 10]
		Tile0: [0, 100, 100], Tile1: [0, 100, 100], Tile2; [0, 100, 100]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3044 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+1620);
	KerArg2->ColBuff = (unsigned char * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+1984);
	KerArg2->Bias = (int * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+1920);
	KerArg2->Out = (unsigned char * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+2944);
	KerArg2->Scale = (unsigned char * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+1960);
	KerArg2->ScaleN = (unsigned char * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+1972);
	KerArg2->Tile_InFeat = (unsigned short int) (30);
	KerArg2->TotalInFeatures = (unsigned short int) (30);
	KerArg2->Tile_InH = (unsigned short int) (10);
	KerArg2->Tile_InW = (unsigned short int) (1);
	KerArg2->Tile_OutFeat = (unsigned short int) (10);
	KerArg2->Tile_OutH = (unsigned short int) (10);
	KerArg2->Tile_OutW = (unsigned short int) (1);
	KerArg2->Pad_Val = (unsigned short int) (0);
	KerArg2->Pad = (v4s) ((v4s){0,0,1,1});
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->FirstTile = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (1);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Fy = (unsigned char) (3);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+1984), 960, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+1620), 300, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+1920), 40, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+3044), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+1960), 10, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+1972), 10, 0, 0);
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
				KerArg2->W_Offset = (int) (((int *)(ARMA_30_10_Bin_All_L1_Memory+3044))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv2DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv2DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+2944), 100, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S7_ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion_trans_out0(
		signed char * __restrict__ In,
		signed char * __restrict__ Out)

{
	/* Shared L1: 200 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 1][Tile0 Dim: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 100 )[D0, [0 x 100, 100]][Tile0, 1:[10x10], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 100, 100]][Tile0, 1:[10x10], 1]
		Tile0: [0, 100, 100], Tile1: [0, 100, 100], Tile2; [0, 100, 100]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 100 (Total Size: 100 )[D0, [0 x 100, 100]][Tile0, 1:[10x10], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 100, 100]][Tile0, 1:[10x10], 1]
		Tile0: [0, 100, 100], Tile1: [0, 100, 100], Tile2; [0, 100, 100]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (void *__restrict__) (ARMA_30_10_Bin_All_L1_Memory+0);
	KerArg0->Out = (void *__restrict__) (ARMA_30_10_Bin_All_L1_Memory+100);
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (10);
	KerArg0->H = (unsigned short int) (10);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+0), 100, 0, DmaR_Evt1);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			/*====================== Call Kernel LOC_LOOP =========================*/
			AT_FORK(gap_ncore(), (void *) CNN_Transpose_fps, (void *) KerArg0);
			__CALL(CNN_Transpose_fps, KerArg0);
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+100), 100, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S9_ARMA_30_10_Bin_All_global_average_pooling2d_Mean(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 128 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerGlobalPool_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 100 )[Tile0, 1:[10x10], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[10x10], 1]
		Tile0: [0, 100, 100], Tile1: [0, 100, 100], Tile2; [0, 100, 100]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 100 (Total Size: 10 )[Tile0, 1:[1x10], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x10], 1]
		Tile0: [0, 10, 10], Tile1: [0, 10, 10], Tile2; [0, 10, 10]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 112 (Total Size: 13 )[Tile0, 1:[13x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[13x1], 1]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (void * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+0);
	KerArg0->W = (unsigned short int) (5);
	KerArg0->H = (unsigned short int) (2);
	KerArg0->Feat = (unsigned short int) (10);
	KerArg0->Out = (int * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+100);
	KerArg0->DoScale = (unsigned char) (1);
	KerArg0->Infos = (void * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+112);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+0), 100, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+112), 13, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		/*====================== Call Kernel LOC_LOOP =========================*/
		AT_FORK(gap_ncore(), (void *) KerParGlobalAvgPoolFullFeat_SQ8, (void *) KerArg0);
		__CALL(KerParGlobalAvgPoolFullFeat_SQ8, KerArg0);
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+100), 10, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S10_ARMA_30_10_Bin_All_global_average_pooling2d_Mean_qout0(
		signed char * __restrict__ In,
		unsigned char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 32 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	CNN_FpsUFps_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1][D0 Dim: Init: 10, Tiled: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 10 )[D0, [0 x 10, 10]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 10, 10]]
		Tile0: [0, 10, 10], Tile1: [0, 10, 10], Tile2; [0, 10, 10]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 12 (Total Size: 10 )[D0, [0 x 10, 10]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 10, 10]]
		Tile0: [0, 10, 10], Tile1: [0, 10, 10], Tile2; [0, 10, 10]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 24 (Total Size: 8 )[Tile0, 1:[1x1], 8]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 8]
		Tile0: [0, 8, 8], Tile1: [0, 8, 8], Tile2; [0, 8, 8]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (signed char *__restrict__) (ARMA_30_10_Bin_All_L1_Memory+0);
	KerArg0->Out = (unsigned char *__restrict__) (ARMA_30_10_Bin_All_L1_Memory+12);
	KerArg0->W = (unsigned short int) (10);
	KerArg0->H = (unsigned short int) (1);
	KerArg0->Infos = (signed char *__restrict__) (ARMA_30_10_Bin_All_L1_Memory+24);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+0), 10, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+24), 8, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		{ /* Single iteration on D0 */
			int D0Ind_Last = 1;
			/*====================== Call Kernel LOC_D0 =========================*/
			AT_FORK(gap_ncore(), (void *) CNN_FpsUFpsScaled, (void *) KerArg0);
			__CALL(CNN_FpsUFpsScaled, KerArg0);
		} /* End iteration on D0 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+12), 10, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S13_ARMA_30_10_Bin_All_dense_MatMul(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		signed char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 88 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerLinear_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	int D1Ind, D1Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1][D1 Dim: Init: 2, Tiled: 1][D0 Dim: Init: 10, Tiled: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 16 )[D0, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 16, 16]]
		Tile0: [0, 10, 10], Tile1: [0, 10, 10], Tile2; [0, 10, 10]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 16 (Total Size: 32 )[D1, [0 x 32, 32]][D0, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]][D0, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 48 (Total Size: 8 )[D1, [0 x 8, 8]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 8, 8]]
		Tile0: [0, 8, 8], Tile1: [0, 8, 8], Tile2; [0, 8, 8]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 56 (Total Size: 2 )[D1, [0 x 2, 2]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2, 2]]
		Tile0: [0, 2, 2], Tile1: [0, 2, 2], Tile2; [0, 2, 2]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 60 (Total Size: 2 )[D1, [0 x 2, 2]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2, 2]]
		Tile0: [0, 2, 2], Tile1: [0, 2, 2], Tile2; [0, 2, 2]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 64 (Total Size: 2 )[D1, [0 x 2, 2]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2, 2]]
		Tile0: [0, 2, 2], Tile1: [0, 2, 2], Tile2; [0, 2, 2]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 68 (Total Size: 20 )[Tile0, 1:[1x1], 20]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 20]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (signed char * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+16);
	KerArg2->Bias = (int * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+48);
	KerArg2->Out = (int * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+56);
	KerArg2->Scale = (unsigned char * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+60);
	KerArg2->ScaleN = (unsigned char * __restrict__) (ARMA_30_10_Bin_All_L1_Memory+64);
	KerArg2->Tile_InFeat = (unsigned short int) (10);
	KerArg2->Tile_OutFeat = (unsigned short int) (2);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (58753271);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+16), 32, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+68), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+0), 16, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+48), 8, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+60), 2, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+64), 2, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		{ /* Single iteration on D1 */
			int D1Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->W_Offset = (int) (((int *)(ARMA_30_10_Bin_All_L1_Memory+68))[4]);
				KerLinear_8a_NE16(KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on D1 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+56), 2, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
	/*====================== Call Kernel LOC_EPILOG =========================*/
	NE16_Disable(
	);
}
void  S15_ARMA_30_10_Bin_All_dense_Softmax(
		signed char * __restrict__ In,
		short int * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 24 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerSoftMax_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 2 )[Tile0, 1:[2x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[2x1], 1]
		Tile0: [0, 2, 2], Tile1: [0, 2, 2], Tile2; [0, 2, 2]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 4 (Total Size: 13 )[Tile0, 1:[13x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[13x1], 1]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 20 (Total Size: 4 )[Tile0, 1:[2x1], 2]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[2x1], 2]
		Tile0: [0, 4, 4], Tile1: [0, 4, 4], Tile2; [0, 4, 4]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (signed char *__restrict__) (ARMA_30_10_Bin_All_L1_Memory+0);
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->N = (unsigned short int) (2);
	KerArg0->Out = (short int *__restrict__) (ARMA_30_10_Bin_All_L1_Memory+20);
	KerArg0->Infos = (signed char *__restrict__) (ARMA_30_10_Bin_All_L1_Memory+4);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+4), 13, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+0), 2, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->Norm = (unsigned short int) (((char *)(ARMA_30_10_Bin_All_L1_Memory+4))[0]);
		AT_FORK(gap_ncore(), (void *) KerParSoftMax_SQ8, (void *) KerArg0);
		__CALL(KerParSoftMax_SQ8, KerArg0);
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L1_Memory+20), 4, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
#pragma GCC diagnostic pop
int  ARMA_30_10_Bin_AllCNN_Construct()

{
	int Error;

	AT_DEFAULTFLASH_FS_CONF_T DefaultFlashConf;
	AT_DEFAULTFLASH_FS_CONF_INIT(&DefaultFlashConf, AT_MEM_L3_DEFAULTFLASH, 0);
	AT_DEFAULTFLASH_FS_OPEN(&DefaultFlash, &DefaultFlashConf, 0, "ARMA_30_10_Bin_All_L3_Flash_Const.dat", &Error);
	if (Error) return AT_FLASH_OPEN_ERROR;

	ARMA_30_10_Bin_All_L2_Memory = (AT_L2_POINTER) AT_L2_ALLOC(0, 1836);
	if (ARMA_30_10_Bin_All_L2_Memory == 0) return AT_L2_OPEN_ERROR;
	ARMA_30_10_Bin_All_L2_Memory_Dyn = (AT_L2_POINTER) AT_L2_ALLOC(0, 400);
	if (ARMA_30_10_Bin_All_L2_Memory_Dyn == 0) return AT_L2_OPEN_ERROR;
	ARMA_30_10_Bin_All_L1_Memory = (AT_L1_POINTER) AT_L1_ALLOC(0, 3460);
	if (ARMA_30_10_Bin_All_L1_Memory == 0) return AT_L1_OPEN_ERROR;
	AT_DEFAULTFLASH_FS_FC_EVENT _UchanHF1, *UchanHF1 = &_UchanHF1;
	/* Static Moving Arma_30_10_bin_all_conv2d_conv2d_weights, size 480 from DefaultFlash at 960 to (size 480) L2 at 960..1439 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_30_10_Bin_All_L3_Flash + 960), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L2_Memory + 960), 480, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Arma_30_10_bin_all_conv2d_conv2d_biases, size 120 from DefaultFlash at 1440 to (size 120) L2 at 1440..1559 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_30_10_Bin_All_L3_Flash + 1440), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L2_Memory + 1440), 120, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S3_Mul_scale, size 30 from DefaultFlash at 1600 to (size 30) L2 at 1600..1629 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_30_10_Bin_All_L3_Flash + 1600), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L2_Memory + 1600), 30, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S3_Mul_shift, size 30 from DefaultFlash at 1632 to (size 30) L2 at 1632..1661 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_30_10_Bin_All_L3_Flash + 1632), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L2_Memory + 1632), 30, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S3_Infos, size 20 from DefaultFlash at 1696 to (size 20) L2 at 1696..1715 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_30_10_Bin_All_L3_Flash + 1696), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L2_Memory + 1696), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Arma_30_10_bin_all_conv2d_1_conv2d_weights, size 960 from DefaultFlash at 0 to (size 960) L2 at 0..959 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_30_10_Bin_All_L3_Flash + 0), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L2_Memory + 0), 960, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Arma_30_10_bin_all_conv2d_1_conv2d_biases, size 40 from DefaultFlash at 1560 to (size 40) L2 at 1560..1599 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_30_10_Bin_All_L3_Flash + 1560), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L2_Memory + 1560), 40, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S6_Mul_scale, size 10 from DefaultFlash at 1788 to (size 10) L2 at 1788..1797 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_30_10_Bin_All_L3_Flash + 1788), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L2_Memory + 1788), 10, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S6_Mul_shift, size 10 from DefaultFlash at 1800 to (size 10) L2 at 1800..1809 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_30_10_Bin_All_L3_Flash + 1800), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L2_Memory + 1800), 10, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S6_Infos, size 20 from DefaultFlash at 1716 to (size 20) L2 at 1716..1735 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_30_10_Bin_All_L3_Flash + 1716), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L2_Memory + 1716), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S9_Infos, size 13 from DefaultFlash at 1756 to (size 13) L2 at 1756..1768 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_30_10_Bin_All_L3_Flash + 1756), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L2_Memory + 1756), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S10_Infos, size 8 from DefaultFlash at 1812 to (size 8) L2 at 1812..1819 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_30_10_Bin_All_L3_Flash + 1812), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L2_Memory + 1812), 8, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Arma_30_10_bin_all_dense_matmul_weights, size 32 from DefaultFlash at 1664 to (size 32) L2 at 1664..1695 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_30_10_Bin_All_L3_Flash + 1664), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L2_Memory + 1664), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Arma_30_10_bin_all_dense_matmul_biases, size 8 from DefaultFlash at 1820 to (size 8) L2 at 1820..1827 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_30_10_Bin_All_L3_Flash + 1820), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L2_Memory + 1820), 8, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S13_Mul_scale, size 2 from DefaultFlash at 1828 to (size 2) L2 at 1828..1829 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_30_10_Bin_All_L3_Flash + 1828), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L2_Memory + 1828), 2, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S13_Mul_shift, size 2 from DefaultFlash at 1832 to (size 2) L2 at 1832..1833 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_30_10_Bin_All_L3_Flash + 1832), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L2_Memory + 1832), 2, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S13_Infos, size 20 from DefaultFlash at 1736 to (size 20) L2 at 1736..1755 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_30_10_Bin_All_L3_Flash + 1736), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L2_Memory + 1736), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S15_Infos, size 13 from DefaultFlash at 1772 to (size 13) L2 at 1772..1784 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_30_10_Bin_All_L3_Flash + 1772), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_30_10_Bin_All_L2_Memory + 1772), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	return AT_NO_ERROR;
}
void ARMA_30_10_Bin_AllCNN_ConstructCluster()

{
}
int  ARMA_30_10_Bin_AllCNN_Destruct()

{
	AT_L2_FREE(0, ARMA_30_10_Bin_All_L2_Memory_Dyn, 400);
	AT_L2_FREE(0, ARMA_30_10_Bin_All_L2_Memory, 1836);
	AT_L1_FREE(0, ARMA_30_10_Bin_All_L1_Memory, 3460);
	AT_DEFAULTFLASH_FS_CLOSE(&DefaultFlash);
	return 0;
}
int ARMA_30_10_Bin_AllCNN_Memory(AT_MEM_TYPE Which)

{
	switch (Which) {
		case AT_L1_MEM:     return 3460; /* L1 Memory */
		case AT_L2_MEM:     return 1836; /* L2 Memory, permanent */
		case AT_L2_DYN_MEM: return 400; /* L2 Memory, dynamic */
		case AT_L3_MEM:     return 0; /* L3 Memory, permanent */
		case AT_L3_DYN_MEM: return 0; /* L3 Memory, dynamic */
		default:            return 0;
	}
}
unsigned int AT_GraphPerf[8];
unsigned int AT_GraphPerf_CNN_Total = 0;
unsigned int AT_GraphOperInfosNames[8] = {
	2100,
	9100,
	100,
	100,
	10,
	20,
	2,
	0,
};
char *AT_GraphNodeNames[8] = {
	"S3_ARMA_30_10_Bin_All_conv2d_Conv2D_fusion",
	"S6_ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion",
	"S7_ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion_trans_out0",
	"S9_ARMA_30_10_Bin_All_global_average_pooling2d_Mean",
	"S10_ARMA_30_10_Bin_All_global_average_pooling2d_Mean_qout0",
	"S13_ARMA_30_10_Bin_All_dense_MatMul",
	"S15_ARMA_30_10_Bin_All_dense_Softmax",
	"IO_Wait",
};
int  ARMA_30_10_Bin_AllCNN(
		unsigned char * __restrict__ Input_1,
		signed short * __restrict__ Output_1)

{
	unsigned int Start_IO;
	AT_GraphPerf_CNN_Total = gap_cl_readhwtimer();
	AT_GraphPerf[0] = gap_cl_readhwtimer();
	AT_GraphPerf[7] = 0;
	S3_ARMA_30_10_Bin_All_conv2d_Conv2D_fusion(
		((unsigned char * __restrict__) Input_1), /* In */
		((unsigned char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory+960)), /* Filter */
		((signed int * __restrict__) (ARMA_30_10_Bin_All_L2_Memory+1440)), /* Bias */
		((unsigned char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory_Dyn+100)), /* Out */
		((unsigned char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory+1600)), /* Scale */
		((signed char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory+1632)), /* ScaleN */
		((signed char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory+1696)) /* Infos */
	);
	AT_GraphPerf[0] = gap_cl_readhwtimer() - AT_GraphPerf[0];
	AT_GraphPerf[1] = gap_cl_readhwtimer();
	S6_ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion(
		((unsigned char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory_Dyn+100)), /* In */
		((unsigned char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory+0)), /* Filter */
		((signed int * __restrict__) (ARMA_30_10_Bin_All_L2_Memory+1560)), /* Bias */
		((signed char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory+1788)), /* Scale */
		((signed char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory+1800)), /* ScaleN */
		((signed char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory+1716)) /* Infos */
	);
	AT_GraphPerf[1] = gap_cl_readhwtimer() - AT_GraphPerf[1];
	AT_GraphPerf[2] = gap_cl_readhwtimer();
	S7_ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion_trans_out0(
		((signed char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory_Dyn+0)), /* In */
		((signed char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory_Dyn+100)) /* Out */
	);
	AT_GraphPerf[2] = gap_cl_readhwtimer() - AT_GraphPerf[2];
	AT_GraphPerf[3] = gap_cl_readhwtimer();
	S9_ARMA_30_10_Bin_All_global_average_pooling2d_Mean(
		((signed char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory_Dyn+100)), /* In */
		((signed char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory_Dyn+0)), /* Out */
		((signed char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory+1756)) /* Infos */
	);
	AT_GraphPerf[3] = gap_cl_readhwtimer() - AT_GraphPerf[3];
	AT_GraphPerf[4] = gap_cl_readhwtimer();
	S10_ARMA_30_10_Bin_All_global_average_pooling2d_Mean_qout0(
		((signed char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory_Dyn+12)), /* Out */
		((signed char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory+1812)) /* Infos */
	);
	AT_GraphPerf[4] = gap_cl_readhwtimer() - AT_GraphPerf[4];
	AT_GraphPerf[5] = gap_cl_readhwtimer();
	S13_ARMA_30_10_Bin_All_dense_MatMul(
		((unsigned char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory_Dyn+12)), /* In */
		((unsigned char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory+1664)), /* Filter */
		((signed int * __restrict__) (ARMA_30_10_Bin_All_L2_Memory+1820)), /* Bias */
		((signed char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory+1828)), /* Scale */
		((signed char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory+1832)), /* ScaleN */
		((signed char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory+1736)) /* Infos */
	);
	AT_GraphPerf[5] = gap_cl_readhwtimer() - AT_GraphPerf[5];
	AT_GraphPerf[6] = gap_cl_readhwtimer();
	S15_ARMA_30_10_Bin_All_dense_Softmax(
		((signed char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory_Dyn+0)), /* In */
		((signed short * __restrict__) Output_1), /* Out */
		((signed char * __restrict__) (ARMA_30_10_Bin_All_L2_Memory+1772)) /* Infos */
	);
	AT_GraphPerf[6] = gap_cl_readhwtimer() - AT_GraphPerf[6];
	AT_GraphPerf_CNN_Total = gap_cl_readhwtimer() - AT_GraphPerf_CNN_Total;
	return 0;
}
