#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#include "ARMA_50_30_Bin_AllKernels.h"
#ifdef __EMUL__
unsigned int __L3_Read, __L3_Write, __L2_Read, __L2_Write;
#endif
L1_CL_MEM AT_L1_POINTER ARMA_50_30_Bin_All_L1_Memory;
L2_MEM AT_L2_POINTER ARMA_50_30_Bin_All_L2_Memory;
L2_MEM AT_L2_POINTER ARMA_50_30_Bin_All_L2_Memory_Dyn;
static AT_DEFAULTFLASH_FS_T DefaultFlash;
void  S3_ARMA_50_30_Bin_All_conv2d_Conv2D_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 5700 bytes, L2 buffer: 0 bytes */
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
		[D1 Dim: Init: 50, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 1, Tiled: 1]
	Ker Arg: ConvOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1180 (Total Size: 4000 )[Tile0, 1:[1x19], 200][D1, [0 x 200, 200]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 200, 200]][Tile0, 1:[1x19], 200]
		Tile0: [0, 3800, 3800], Tile1: [0, 3800, 3800], Tile2; [0, 3800, 3800]
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
			@ 76 (Total Size: 200 )[D1, [0 x 200, 200]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 200, 200]]
		Tile0: [0, 200, 200], Tile1: [0, 200, 200], Tile2; [0, 200, 200]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 276 (Total Size: 50 )[D1, [0 x 50, 50]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 50, 50]]
		Tile0: [0, 50, 50], Tile1: [0, 50, 50], Tile2; [0, 50, 50]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 328 (Total Size: 50 )[D1, [0 x 50, 50]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 50, 50]]
		Tile0: [0, 50, 50], Tile1: [0, 50, 50], Tile2; [0, 50, 50]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 380 (Total Size: 800 )[D1, [0 x 800, 800]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 800, 800]]
		Tile0: [0, 800, 800], Tile1: [0, 800, 800], Tile2; [0, 800, 800]
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
			@ 5180 (Total Size: 500 )[Tile0, 1:[1x10], 50][D1, [0 x 50, 50]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 50, 50]][Tile0, 1:[1x10], 50]
		Tile0: [0, 500, 500], Tile1: [0, 500, 500], Tile2; [0, 500, 500]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5680 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+56);
	KerArg2->ColBuff = (unsigned char * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+380);
	KerArg2->Bias = (int * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+76);
	KerArg2->Out = (unsigned char * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+1180);
	KerArg2->Scale = (unsigned char * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+276);
	KerArg2->ScaleN = (unsigned char * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+328);
	KerArg2->Tile_InFeat = (unsigned short int) (1);
	KerArg2->TotalInFeatures = (unsigned short int) (1);
	KerArg2->Tile_InH = (unsigned short int) (20);
	KerArg2->Tile_InW = (unsigned short int) (1);
	KerArg2->Tile_OutFeat = (unsigned short int) (50);
	KerArg2->Tile_OutH = (unsigned short int) (19);
	KerArg2->Tile_OutW = (unsigned short int) (1);
	KerArg2->Pad_Val = (unsigned short int) (135);
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
	KerArg3->In = (unsigned char * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+1180);
	KerArg3->W = (unsigned short int) (1);
	KerArg3->H = (unsigned short int) (19);
	KerArg3->Fx = (unsigned short int) (1);
	KerArg3->Fy = (unsigned short int) (1);
	KerArg3->Sx = (unsigned char) (2);
	KerArg3->Sy = (unsigned char) (2);
	KerArg3->FirstTile = (unsigned char) ((1));
	KerArg3->Pad = (v4s) 0;
	KerArg3->Out = (unsigned char * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+5180);
	KerArg3->Feat = (unsigned short int) (50);
	KerArg3->Wo = (unsigned short int) (1);
	KerArg3->Ho = (unsigned short int) (10);
	KerArg3->Infos = (signed char * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+5680);
	KerArg3->Extra = (void *) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+380), 800, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+76), 200, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+276), 50, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+328), 50, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+56), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+5680), 20, 0, 0);
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
				KerArg2->W_Offset = (int) (((int *)(ARMA_50_30_Bin_All_L1_Memory+5680))[4]);
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
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+5180), 500, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S6_ARMA_50_30_Bin_All_conv2d_1_Conv2D_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		signed char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 8504 bytes, L2 buffer: 0 bytes */
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
		[D1 Dim: Init: 30, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 50, Tiled: 1]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 2700 )[Tile0, 1:[2700x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[2700x1], 1]
		Tile0: [0, 2700, 2700], Tile1: [0, 2700, 2700], Tile2; [0, 2700, 2700]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2700 (Total Size: 500 )[Tile0, 1:[1x10], 50][D0, [0 x 50, 50]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x10], 50][D0, [0 x 50, 50]]
		Tile0: [0, 500, 500], Tile1: [0, 500, 500], Tile2; [0, 500, 500]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3200 (Total Size: 120 )[D1, [0 x 120, 120]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 120, 120]]
		Tile0: [0, 120, 120], Tile1: [0, 120, 120], Tile2; [0, 120, 120]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3320 (Total Size: 30 )[D1, [0 x 30, 30]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 30, 30]]
		Tile0: [0, 30, 30], Tile1: [0, 30, 30], Tile2; [0, 30, 30]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3352 (Total Size: 30 )[D1, [0 x 30, 30]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 30, 30]]
		Tile0: [0, 30, 30], Tile1: [0, 30, 30], Tile2; [0, 30, 30]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3384 (Total Size: 4800 )[D1, [0 x 4800, 4800]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 4800, 4800]]
		Tile0: [0, 4800, 4800], Tile1: [0, 4800, 4800], Tile2; [0, 4800, 4800]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 8184 (Total Size: 300 )[Tile0, 1:[1x10], 30][D1, [0 x 30, 30]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 30, 30]][Tile0, 1:[1x10], 30]
		Tile0: [0, 300, 300], Tile1: [0, 300, 300], Tile2; [0, 300, 300]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 8484 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+2700);
	KerArg2->ColBuff = (unsigned char * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+3384);
	KerArg2->Bias = (int * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+3200);
	KerArg2->Out = (unsigned char * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+8184);
	KerArg2->Scale = (unsigned char * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+3320);
	KerArg2->ScaleN = (unsigned char * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+3352);
	KerArg2->Tile_InFeat = (unsigned short int) (50);
	KerArg2->TotalInFeatures = (unsigned short int) (50);
	KerArg2->Tile_InH = (unsigned short int) (10);
	KerArg2->Tile_InW = (unsigned short int) (1);
	KerArg2->Tile_OutFeat = (unsigned short int) (30);
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
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+3384), 4800, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+2700), 500, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+3200), 120, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+3320), 30, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+3352), 30, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+8484), 20, 0, 0);
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
				KerArg2->W_Offset = (int) (((int *)(ARMA_50_30_Bin_All_L1_Memory+8484))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv2DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv2DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+8184), 300, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S7_ARMA_50_30_Bin_All_conv2d_1_Conv2D_fusion_trans_out0(
		signed char * __restrict__ In,
		signed char * __restrict__ Out)

{
	/* Shared L1: 600 bytes, L2 buffer: 0 bytes */
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
			@ 0 (Total Size: 300 )[D0, [0 x 300, 300]][Tile0, 1:[30x10], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 300, 300]][Tile0, 1:[30x10], 1]
		Tile0: [0, 300, 300], Tile1: [0, 300, 300], Tile2; [0, 300, 300]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 300 (Total Size: 300 )[D0, [0 x 300, 300]][Tile0, 1:[30x10], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 300, 300]][Tile0, 1:[30x10], 1]
		Tile0: [0, 300, 300], Tile1: [0, 300, 300], Tile2; [0, 300, 300]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (void *__restrict__) (ARMA_50_30_Bin_All_L1_Memory+0);
	KerArg0->Out = (void *__restrict__) (ARMA_50_30_Bin_All_L1_Memory+300);
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (30);
	KerArg0->H = (unsigned short int) (10);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+0), 300, 0, DmaR_Evt1);
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
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+300), 300, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S9_ARMA_50_30_Bin_All_global_average_pooling2d_Mean(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 348 bytes, L2 buffer: 0 bytes */
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
			@ 0 (Total Size: 300 )[Tile0, 1:[10x30], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[10x30], 1]
		Tile0: [0, 300, 300], Tile1: [0, 300, 300], Tile2; [0, 300, 300]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 300 (Total Size: 30 )[Tile0, 1:[1x30], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x30], 1]
		Tile0: [0, 30, 30], Tile1: [0, 30, 30], Tile2; [0, 30, 30]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 332 (Total Size: 13 )[Tile0, 1:[13x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[13x1], 1]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (void * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+0);
	KerArg0->W = (unsigned short int) (5);
	KerArg0->H = (unsigned short int) (2);
	KerArg0->Feat = (unsigned short int) (30);
	KerArg0->Out = (int * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+300);
	KerArg0->DoScale = (unsigned char) (1);
	KerArg0->Infos = (void * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+332);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+0), 300, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+332), 13, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		/*====================== Call Kernel LOC_LOOP =========================*/
		AT_FORK(gap_ncore(), (void *) KerParGlobalAvgPoolFullFeat_SQ8, (void *) KerArg0);
		__CALL(KerParGlobalAvgPoolFullFeat_SQ8, KerArg0);
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+300), 30, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S10_ARMA_50_30_Bin_All_global_average_pooling2d_Mean_qout0(
		signed char * __restrict__ In,
		unsigned char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 72 bytes, L2 buffer: 0 bytes */
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
		[Tile0 Dim: 1][D0 Dim: Init: 30, Tiled: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 30 )[D0, [0 x 30, 30]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 30, 30]]
		Tile0: [0, 30, 30], Tile1: [0, 30, 30], Tile2; [0, 30, 30]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 32 (Total Size: 30 )[D0, [0 x 30, 30]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 30, 30]]
		Tile0: [0, 30, 30], Tile1: [0, 30, 30], Tile2; [0, 30, 30]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 64 (Total Size: 8 )[Tile0, 1:[1x1], 8]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 8]
		Tile0: [0, 8, 8], Tile1: [0, 8, 8], Tile2; [0, 8, 8]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (signed char *__restrict__) (ARMA_50_30_Bin_All_L1_Memory+0);
	KerArg0->Out = (unsigned char *__restrict__) (ARMA_50_30_Bin_All_L1_Memory+32);
	KerArg0->W = (unsigned short int) (30);
	KerArg0->H = (unsigned short int) (1);
	KerArg0->Infos = (signed char *__restrict__) (ARMA_50_30_Bin_All_L1_Memory+64);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+0), 30, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+64), 8, 0, 0);
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
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+32), 30, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S13_ARMA_50_30_Bin_All_dense_MatMul(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		signed char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 136 bytes, L2 buffer: 0 bytes */
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
		[Tile0 Dim: 1][D1 Dim: Init: 2, Tiled: 1][D0 Dim: Init: 30, Tiled: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 32 )[D0, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 32, 32]]
		Tile0: [0, 30, 30], Tile1: [0, 30, 30], Tile2; [0, 30, 30]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 32 (Total Size: 64 )[D1, [0 x 64, 64]][D0, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]][D0, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 96 (Total Size: 8 )[D1, [0 x 8, 8]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 8, 8]]
		Tile0: [0, 8, 8], Tile1: [0, 8, 8], Tile2; [0, 8, 8]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 104 (Total Size: 2 )[D1, [0 x 2, 2]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2, 2]]
		Tile0: [0, 2, 2], Tile1: [0, 2, 2], Tile2; [0, 2, 2]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 108 (Total Size: 2 )[D1, [0 x 2, 2]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2, 2]]
		Tile0: [0, 2, 2], Tile1: [0, 2, 2], Tile2; [0, 2, 2]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 112 (Total Size: 2 )[D1, [0 x 2, 2]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2, 2]]
		Tile0: [0, 2, 2], Tile1: [0, 2, 2], Tile2; [0, 2, 2]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 116 (Total Size: 20 )[Tile0, 1:[1x1], 20]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 20]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (signed char * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+32);
	KerArg2->Bias = (int * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+96);
	KerArg2->Out = (int * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+104);
	KerArg2->Scale = (unsigned char * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+108);
	KerArg2->ScaleN = (unsigned char * __restrict__) (ARMA_50_30_Bin_All_L1_Memory+112);
	KerArg2->Tile_InFeat = (unsigned short int) (30);
	KerArg2->Tile_OutFeat = (unsigned short int) (2);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (58753271);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+32), 64, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+0), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+116), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+96), 8, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+108), 2, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+112), 2, 0, 0);
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
				KerArg2->W_Offset = (int) (((int *)(ARMA_50_30_Bin_All_L1_Memory+116))[4]);
				KerLinear_8a_NE16(KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on D1 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+104), 2, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
	/*====================== Call Kernel LOC_EPILOG =========================*/
	NE16_Disable(
	);
}
void  S15_ARMA_50_30_Bin_All_dense_Softmax(
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
	KerArg0->In = (signed char *__restrict__) (ARMA_50_30_Bin_All_L1_Memory+0);
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->N = (unsigned short int) (2);
	KerArg0->Out = (short int *__restrict__) (ARMA_50_30_Bin_All_L1_Memory+20);
	KerArg0->Infos = (signed char *__restrict__) (ARMA_50_30_Bin_All_L1_Memory+4);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+4), 13, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+0), 2, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->Norm = (unsigned short int) (((char *)(ARMA_50_30_Bin_All_L1_Memory+4))[0]);
		AT_FORK(gap_ncore(), (void *) KerParSoftMax_SQ8, (void *) KerArg0);
		__CALL(KerParSoftMax_SQ8, KerArg0);
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L1_Memory+20), 4, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
#pragma GCC diagnostic pop
int  ARMA_50_30_Bin_AllCNN_Construct()

{
	int Error;

	AT_DEFAULTFLASH_FS_CONF_T DefaultFlashConf;
	AT_DEFAULTFLASH_FS_CONF_INIT(&DefaultFlashConf, AT_MEM_L3_DEFAULTFLASH, 0);
	AT_DEFAULTFLASH_FS_OPEN(&DefaultFlash, &DefaultFlashConf, 0, "ARMA_50_30_Bin_All_L3_Flash_Const.dat", &Error);
	if (Error) return AT_FLASH_OPEN_ERROR;

	ARMA_50_30_Bin_All_L2_Memory = (AT_L2_POINTER) AT_L2_ALLOC(0, 6268);
	if (ARMA_50_30_Bin_All_L2_Memory == 0) return AT_L2_OPEN_ERROR;
	ARMA_50_30_Bin_All_L2_Memory_Dyn = (AT_L2_POINTER) AT_L2_ALLOC(0, 800);
	if (ARMA_50_30_Bin_All_L2_Memory_Dyn == 0) return AT_L2_OPEN_ERROR;
	ARMA_50_30_Bin_All_L1_Memory = (AT_L1_POINTER) AT_L1_ALLOC(0, 8504);
	if (ARMA_50_30_Bin_All_L1_Memory == 0) return AT_L1_OPEN_ERROR;
	AT_DEFAULTFLASH_FS_FC_EVENT _UchanHF1, *UchanHF1 = &_UchanHF1;
	/* Static Moving Arma_50_30_bin_all_conv2d_conv2d_weights, size 800 from DefaultFlash at 4800 to (size 800) L2 at 4800..5599 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_50_30_Bin_All_L3_Flash + 4800), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L2_Memory + 4800), 800, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Arma_50_30_bin_all_conv2d_conv2d_biases, size 200 from DefaultFlash at 5600 to (size 200) L2 at 5600..5799 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_50_30_Bin_All_L3_Flash + 5600), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L2_Memory + 5600), 200, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S3_Mul_scale, size 50 from DefaultFlash at 5984 to (size 50) L2 at 5984..6033 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_50_30_Bin_All_L3_Flash + 5984), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L2_Memory + 5984), 50, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S3_Mul_shift, size 50 from DefaultFlash at 6036 to (size 50) L2 at 6036..6085 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_50_30_Bin_All_L3_Flash + 6036), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L2_Memory + 6036), 50, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S3_Infos, size 20 from DefaultFlash at 6152 to (size 20) L2 at 6152..6171 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_50_30_Bin_All_L3_Flash + 6152), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L2_Memory + 6152), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Arma_50_30_bin_all_conv2d_1_conv2d_weights, size 4800 from DefaultFlash at 0 to (size 4800) L2 at 0..4799 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_50_30_Bin_All_L3_Flash + 0), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L2_Memory + 0), 4800, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Arma_50_30_bin_all_conv2d_1_conv2d_biases, size 120 from DefaultFlash at 5800 to (size 120) L2 at 5800..5919 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_50_30_Bin_All_L3_Flash + 5800), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L2_Memory + 5800), 120, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S6_Mul_scale, size 30 from DefaultFlash at 6088 to (size 30) L2 at 6088..6117 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_50_30_Bin_All_L3_Flash + 6088), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L2_Memory + 6088), 30, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S6_Mul_shift, size 30 from DefaultFlash at 6120 to (size 30) L2 at 6120..6149 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_50_30_Bin_All_L3_Flash + 6120), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L2_Memory + 6120), 30, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S6_Infos, size 20 from DefaultFlash at 6172 to (size 20) L2 at 6172..6191 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_50_30_Bin_All_L3_Flash + 6172), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L2_Memory + 6172), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S9_Infos, size 13 from DefaultFlash at 6212 to (size 13) L2 at 6212..6224 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_50_30_Bin_All_L3_Flash + 6212), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L2_Memory + 6212), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S10_Infos, size 8 from DefaultFlash at 6244 to (size 8) L2 at 6244..6251 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_50_30_Bin_All_L3_Flash + 6244), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L2_Memory + 6244), 8, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Arma_50_30_bin_all_dense_matmul_weights, size 64 from DefaultFlash at 5920 to (size 64) L2 at 5920..5983 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_50_30_Bin_All_L3_Flash + 5920), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L2_Memory + 5920), 64, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Arma_50_30_bin_all_dense_matmul_biases, size 8 from DefaultFlash at 6252 to (size 8) L2 at 6252..6259 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_50_30_Bin_All_L3_Flash + 6252), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L2_Memory + 6252), 8, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S13_Mul_scale, size 2 from DefaultFlash at 6260 to (size 2) L2 at 6260..6261 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_50_30_Bin_All_L3_Flash + 6260), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L2_Memory + 6260), 2, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S13_Mul_shift, size 2 from DefaultFlash at 6264 to (size 2) L2 at 6264..6265 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_50_30_Bin_All_L3_Flash + 6264), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L2_Memory + 6264), 2, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S13_Infos, size 20 from DefaultFlash at 6192 to (size 20) L2 at 6192..6211 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_50_30_Bin_All_L3_Flash + 6192), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L2_Memory + 6192), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S15_Infos, size 13 from DefaultFlash at 6228 to (size 13) L2 at 6228..6240 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) ARMA_50_30_Bin_All_L3_Flash + 6228), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) ARMA_50_30_Bin_All_L2_Memory + 6228), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	return AT_NO_ERROR;
}
void ARMA_50_30_Bin_AllCNN_ConstructCluster()

{
}
int  ARMA_50_30_Bin_AllCNN_Destruct()

{
	AT_L2_FREE(0, ARMA_50_30_Bin_All_L2_Memory_Dyn, 800);
	AT_L2_FREE(0, ARMA_50_30_Bin_All_L2_Memory, 6268);
	AT_L1_FREE(0, ARMA_50_30_Bin_All_L1_Memory, 8504);
	AT_DEFAULTFLASH_FS_CLOSE(&DefaultFlash);
	return 0;
}
int ARMA_50_30_Bin_AllCNN_Memory(AT_MEM_TYPE Which)

{
	switch (Which) {
		case AT_L1_MEM:     return 8504; /* L1 Memory */
		case AT_L2_MEM:     return 6268; /* L2 Memory, permanent */
		case AT_L2_DYN_MEM: return 800; /* L2 Memory, dynamic */
		case AT_L3_MEM:     return 0; /* L3 Memory, permanent */
		case AT_L3_DYN_MEM: return 0; /* L3 Memory, dynamic */
		default:            return 0;
	}
}
unsigned int AT_GraphPerf[8];
unsigned int AT_GraphPerf_CNN_Total = 0;
unsigned int AT_GraphOperInfosNames[8] = {
	3500,
	45300,
	300,
	300,
	30,
	60,
	2,
	0,
};
char *AT_GraphNodeNames[8] = {
	"S3_ARMA_50_30_Bin_All_conv2d_Conv2D_fusion",
	"S6_ARMA_50_30_Bin_All_conv2d_1_Conv2D_fusion",
	"S7_ARMA_50_30_Bin_All_conv2d_1_Conv2D_fusion_trans_out0",
	"S9_ARMA_50_30_Bin_All_global_average_pooling2d_Mean",
	"S10_ARMA_50_30_Bin_All_global_average_pooling2d_Mean_qout0",
	"S13_ARMA_50_30_Bin_All_dense_MatMul",
	"S15_ARMA_50_30_Bin_All_dense_Softmax",
	"IO_Wait",
};
int  ARMA_50_30_Bin_AllCNN(
		unsigned char * __restrict__ Input_1,
		signed short * __restrict__ Output_1)

{
	unsigned int Start_IO;
	AT_GraphPerf_CNN_Total = gap_cl_readhwtimer();
	AT_GraphPerf[0] = gap_cl_readhwtimer();
	AT_GraphPerf[7] = 0;
	S3_ARMA_50_30_Bin_All_conv2d_Conv2D_fusion(
		((unsigned char * __restrict__) Input_1), /* In */
		((unsigned char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory+4800)), /* Filter */
		((signed int * __restrict__) (ARMA_50_30_Bin_All_L2_Memory+5600)), /* Bias */
		((unsigned char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory_Dyn+300)), /* Out */
		((unsigned char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory+5984)), /* Scale */
		((signed char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory+6036)), /* ScaleN */
		((signed char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory+6152)) /* Infos */
	);
	AT_GraphPerf[0] = gap_cl_readhwtimer() - AT_GraphPerf[0];
	AT_GraphPerf[1] = gap_cl_readhwtimer();
	S6_ARMA_50_30_Bin_All_conv2d_1_Conv2D_fusion(
		((unsigned char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory_Dyn+300)), /* In */
		((unsigned char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory+0)), /* Filter */
		((signed int * __restrict__) (ARMA_50_30_Bin_All_L2_Memory+5800)), /* Bias */
		((signed char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory+6088)), /* Scale */
		((signed char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory+6120)), /* ScaleN */
		((signed char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory+6172)) /* Infos */
	);
	AT_GraphPerf[1] = gap_cl_readhwtimer() - AT_GraphPerf[1];
	AT_GraphPerf[2] = gap_cl_readhwtimer();
	S7_ARMA_50_30_Bin_All_conv2d_1_Conv2D_fusion_trans_out0(
		((signed char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory_Dyn+0)), /* In */
		((signed char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory_Dyn+300)) /* Out */
	);
	AT_GraphPerf[2] = gap_cl_readhwtimer() - AT_GraphPerf[2];
	AT_GraphPerf[3] = gap_cl_readhwtimer();
	S9_ARMA_50_30_Bin_All_global_average_pooling2d_Mean(
		((signed char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory_Dyn+300)), /* In */
		((signed char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory_Dyn+0)), /* Out */
		((signed char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory+6212)) /* Infos */
	);
	AT_GraphPerf[3] = gap_cl_readhwtimer() - AT_GraphPerf[3];
	AT_GraphPerf[4] = gap_cl_readhwtimer();
	S10_ARMA_50_30_Bin_All_global_average_pooling2d_Mean_qout0(
		((signed char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory_Dyn+32)), /* Out */
		((signed char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory+6244)) /* Infos */
	);
	AT_GraphPerf[4] = gap_cl_readhwtimer() - AT_GraphPerf[4];
	AT_GraphPerf[5] = gap_cl_readhwtimer();
	S13_ARMA_50_30_Bin_All_dense_MatMul(
		((unsigned char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory_Dyn+32)), /* In */
		((unsigned char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory+5920)), /* Filter */
		((signed int * __restrict__) (ARMA_50_30_Bin_All_L2_Memory+6252)), /* Bias */
		((signed char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory+6260)), /* Scale */
		((signed char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory+6264)), /* ScaleN */
		((signed char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory+6192)) /* Infos */
	);
	AT_GraphPerf[5] = gap_cl_readhwtimer() - AT_GraphPerf[5];
	AT_GraphPerf[6] = gap_cl_readhwtimer();
	S15_ARMA_50_30_Bin_All_dense_Softmax(
		((signed char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory_Dyn+0)), /* In */
		((signed short * __restrict__) Output_1), /* Out */
		((signed char * __restrict__) (ARMA_50_30_Bin_All_L2_Memory+6228)) /* Infos */
	);
	AT_GraphPerf[6] = gap_cl_readhwtimer() - AT_GraphPerf[6];
	AT_GraphPerf_CNN_Total = gap_cl_readhwtimer() - AT_GraphPerf_CNN_Total;
	return 0;
}
