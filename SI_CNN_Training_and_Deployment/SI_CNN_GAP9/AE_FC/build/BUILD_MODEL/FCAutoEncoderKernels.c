#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#include "FCAutoEncoderKernels.h"
#ifdef __EMUL__
unsigned int __L3_Read, __L3_Write, __L2_Read, __L2_Write;
#endif
L1_CL_MEM AT_L1_POINTER FCAutoEncoder_L1_Memory;
L2_MEM AT_L2_POINTER FCAutoEncoder_L2_Memory;
L2_MEM AT_L2_POINTER FCAutoEncoder_L2_Memory_Dyn;
static AT_DEFAULTFLASH_FS_T DefaultFlash;
void  S3__encoder_encoder_net_encoder_net_0_Gemm_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos,
		unsigned char * __restrict__ SigmoidLUT_u8)

{
	/* Shared L1: 101012 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerLinear_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_Filter;
	unsigned int _SN_Filter;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1][D1 Dim: Init: 256, Tiled: 3][D0 Dim: Init: 512, Tiled: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 512 )[D0, [0 x 512, 512]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 512, 512]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Filter, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 512 (Total Size: 131072 )[D1, [2 x 49152, 32768]][D0, [0 x 49152, 49152]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [2 x 49152, 32768]][D0, [0 x 49152, 49152]]
		Tile0: [0, 49152, 49152], Tile1: [49152, 49152, 49152], Tile2; [98304, 32768, 32768]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 3 logical tiles, 1 physical tiles
			@ 98816 (Total Size: 1024 )[D1, [2 x 384, 256]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [2 x 384, 256]]
		Tile0: [0, 1024, 1024], Tile1: [0, 1024, 1024], Tile2; [0, 1024, 1024]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 3 logical tiles, 1 physical tiles
			@ 99840 (Total Size: 256 )[D1, [2 x 96, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [2 x 96, 64]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 3 logical tiles, 1 physical tiles
			@ 100096 (Total Size: 256 )[D1, [2 x 96, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [2 x 96, 64]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 3 logical tiles, 1 physical tiles
			@ 100352 (Total Size: 256 )[D1, [2 x 96, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [2 x 96, 64]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 100608 (Total Size: 20 )[Tile0, 1:[1x1], 20]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 20]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	Ker Arg: BuffOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 100628 (Total Size: 256 )[Tile0, 1:[32x1], 8]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[32x1], 8]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: SigmoidLUT_u8, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 100884 (Total Size: 128 )[Tile0, 1:[128x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[128x1], 1]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (signed char * __restrict__) (FCAutoEncoder_L1_Memory+0);
	KerArg2->Bias = (int * __restrict__) (FCAutoEncoder_L1_Memory+98816);
	KerArg2->Out = (int * __restrict__) (FCAutoEncoder_L1_Memory+99840);
	KerArg2->Scale = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+100096);
	KerArg2->ScaleN = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+100352);
	KerArg2->Tile_InFeat = (unsigned short int) (512);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (62947575);
	KerArg2->BuffOut = (int * __restrict__) (FCAutoEncoder_L1_Memory+100628);
	KerArg2->Infos = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+100608);
	KerArg2->Extra = (void * __restrict__) (FCAutoEncoder_L1_Memory+100884);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+512+0), 49152, 0, DmaR_Evt1);
	_N_Filter=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+98816), 1024, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+0), 512, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+100096), 256, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+100352), 256, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) SigmoidLUT_u8+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+100884), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+100608), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		for (D1Ind=0; D1Ind<3; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
			int D1Ind_Last = (D1Ind==2), D1Ind_NextLast = ((D1Ind+1)==2);
			/*================================= Prepare Tiles ===================================*/
			_SN_Filter = 0;
			if (!(D1Ind_Last)) {
				_N_Filter = _N_Filter + (49152); _SN_Filter = (((D1Ind_NextLast)?32768:49152)); 
			} else if (!(1)) {
				_N_Filter = _N_Filter + (-98304); _SN_Filter = (49152); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Filter */
			if (_SN_Filter) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+_N_Filter), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+512+49152*((D1Ind_Total+1)%2)),
						1*(_SN_Filter), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->Filter = (unsigned short * __restrict__) (FCAutoEncoder_L1_Memory+512+49152*((D1Ind_Total)%2));
				KerArg2->Bias = (int * __restrict__) (FCAutoEncoder_L1_Memory+98816+((D1Ind)*384));
				KerArg2->Out = (int * __restrict__) (FCAutoEncoder_L1_Memory+99840+((D1Ind)*96));
				KerArg2->Scale = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+100096+((D1Ind)*96));
				KerArg2->ScaleN = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+100352+((D1Ind)*96));
				KerArg2->Tile_OutFeat = (unsigned short int) ((D1Ind_Last)?64:96);
				KerArg2->W_Offset = (int) (((int *)(FCAutoEncoder_L1_Memory+100608))[4]);
				AT_FORK_CC(gap_ncore(), (void *) KerLinear_8aSigmoid_NE16, (void *) KerArg2);
				__CALL(KerLinear_8aSigmoid_NE16, KerArg2);
			} /* End iteration on D0 */
			/*================================= Update Arg Pipeline =============================*/
			/*============================= End Update Arg Pipeline =============================*/
		} /* End iteration on D1 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+99840), 256, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
	/*====================== Call Kernel LOC_EPILOG =========================*/
	NE16_Disable(
	);
}
void  S6__encoder_encoder_net_encoder_net_3_Gemm_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos,
		unsigned char * __restrict__ SigmoidLUT_u8)

{
	/* Shared L1: 34324 bytes, L2 buffer: 0 bytes */
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
		[Tile0 Dim: 1][D1 Dim: Init: 128, Tiled: 1][D0 Dim: Init: 256, Tiled: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 256 )[D0, [0 x 256, 256]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 256, 256]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 256 (Total Size: 32768 )[D1, [0 x 32768, 32768]][D0, [0 x 32768, 32768]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32768, 32768]][D0, [0 x 32768, 32768]]
		Tile0: [0, 32768, 32768], Tile1: [0, 32768, 32768], Tile2; [0, 32768, 32768]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 33024 (Total Size: 512 )[D1, [0 x 512, 512]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 512, 512]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 33536 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 33664 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 33792 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 33920 (Total Size: 20 )[Tile0, 1:[1x1], 20]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 20]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	Ker Arg: BuffOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 33940 (Total Size: 256 )[Tile0, 1:[32x1], 8]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[32x1], 8]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: SigmoidLUT_u8, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 34196 (Total Size: 128 )[Tile0, 1:[128x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[128x1], 1]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (signed char * __restrict__) (FCAutoEncoder_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (FCAutoEncoder_L1_Memory+256);
	KerArg2->Bias = (int * __restrict__) (FCAutoEncoder_L1_Memory+33024);
	KerArg2->Out = (int * __restrict__) (FCAutoEncoder_L1_Memory+33536);
	KerArg2->Scale = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+33664);
	KerArg2->ScaleN = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+33792);
	KerArg2->Tile_InFeat = (unsigned short int) (256);
	KerArg2->Tile_OutFeat = (unsigned short int) (128);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (62947575);
	KerArg2->BuffOut = (int * __restrict__) (FCAutoEncoder_L1_Memory+33940);
	KerArg2->Infos = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+33920);
	KerArg2->Extra = (void * __restrict__) (FCAutoEncoder_L1_Memory+34196);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+256), 32768, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+33024), 512, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+0), 256, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+33664), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+33792), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) SigmoidLUT_u8+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+34196), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+33920), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
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
				KerArg2->W_Offset = (int) (((int *)(FCAutoEncoder_L1_Memory+33920))[4]);
				AT_FORK_CC(gap_ncore(), (void *) KerLinear_8aSigmoid_NE16, (void *) KerArg2);
				__CALL(KerLinear_8aSigmoid_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on D1 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+33536), 128, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
	/*====================== Call Kernel LOC_EPILOG =========================*/
	NE16_Disable(
	);
}
void  S9__encoder_encoder_net_encoder_net_6_Gemm_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos,
		unsigned char * __restrict__ SigmoidLUT_u8)

{
	/* Shared L1: 9172 bytes, L2 buffer: 0 bytes */
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
		[Tile0 Dim: 1][D1 Dim: Init: 64, Tiled: 1][D0 Dim: Init: 128, Tiled: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 128 )[D0, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 128 (Total Size: 8192 )[D1, [0 x 8192, 8192]][D0, [0 x 8192, 8192]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 8192, 8192]][D0, [0 x 8192, 8192]]
		Tile0: [0, 8192, 8192], Tile1: [0, 8192, 8192], Tile2; [0, 8192, 8192]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 8320 (Total Size: 256 )[D1, [0 x 256, 256]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 256, 256]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 8576 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 8640 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 8704 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 8768 (Total Size: 20 )[Tile0, 1:[1x1], 20]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 20]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	Ker Arg: BuffOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 8788 (Total Size: 256 )[Tile0, 1:[32x1], 8]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[32x1], 8]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: SigmoidLUT_u8, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 9044 (Total Size: 128 )[Tile0, 1:[128x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[128x1], 1]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (signed char * __restrict__) (FCAutoEncoder_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (FCAutoEncoder_L1_Memory+128);
	KerArg2->Bias = (int * __restrict__) (FCAutoEncoder_L1_Memory+8320);
	KerArg2->Out = (int * __restrict__) (FCAutoEncoder_L1_Memory+8576);
	KerArg2->Scale = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+8640);
	KerArg2->ScaleN = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+8704);
	KerArg2->Tile_InFeat = (unsigned short int) (128);
	KerArg2->Tile_OutFeat = (unsigned short int) (64);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (62947575);
	KerArg2->BuffOut = (int * __restrict__) (FCAutoEncoder_L1_Memory+8788);
	KerArg2->Infos = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+8768);
	KerArg2->Extra = (void * __restrict__) (FCAutoEncoder_L1_Memory+9044);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+128), 8192, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+8320), 256, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+0), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) SigmoidLUT_u8+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+9044), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+8640), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+8704), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+8768), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
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
				KerArg2->W_Offset = (int) (((int *)(FCAutoEncoder_L1_Memory+8768))[4]);
				AT_FORK_CC(gap_ncore(), (void *) KerLinear_8aSigmoid_NE16, (void *) KerArg2);
				__CALL(KerLinear_8aSigmoid_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on D1 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+8576), 64, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
	/*====================== Call Kernel LOC_EPILOG =========================*/
	NE16_Disable(
	);
}
void  S12__encoder_encoder_net_encoder_net_9_Gemm_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos,
		unsigned char * __restrict__ SigmoidLUT_u8)

{
	/* Shared L1: 2740 bytes, L2 buffer: 0 bytes */
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
		[Tile0 Dim: 1][D1 Dim: Init: 32, Tiled: 1][D0 Dim: Init: 64, Tiled: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 64 )[D0, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 64 (Total Size: 2048 )[D1, [0 x 2048, 2048]][D0, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2048, 2048]][D0, [0 x 64, 64]]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2112 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2240 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2272 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2304 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2336 (Total Size: 20 )[Tile0, 1:[1x1], 20]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 20]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	Ker Arg: BuffOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2356 (Total Size: 256 )[Tile0, 1:[32x1], 8]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[32x1], 8]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: SigmoidLUT_u8, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2612 (Total Size: 128 )[Tile0, 1:[128x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[128x1], 1]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (signed char * __restrict__) (FCAutoEncoder_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (FCAutoEncoder_L1_Memory+64);
	KerArg2->Bias = (int * __restrict__) (FCAutoEncoder_L1_Memory+2112);
	KerArg2->Out = (int * __restrict__) (FCAutoEncoder_L1_Memory+2240);
	KerArg2->Scale = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+2272);
	KerArg2->ScaleN = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+2304);
	KerArg2->Tile_InFeat = (unsigned short int) (64);
	KerArg2->Tile_OutFeat = (unsigned short int) (32);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (62947575);
	KerArg2->BuffOut = (int * __restrict__) (FCAutoEncoder_L1_Memory+2356);
	KerArg2->Infos = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+2336);
	KerArg2->Extra = (void * __restrict__) (FCAutoEncoder_L1_Memory+2612);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+64), 2048, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+2112), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) SigmoidLUT_u8+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+2612), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+0), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+2272), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+2304), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+2336), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
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
				KerArg2->W_Offset = (int) (((int *)(FCAutoEncoder_L1_Memory+2336))[4]);
				AT_FORK_CC(gap_ncore(), (void *) KerLinear_8aSigmoid_NE16, (void *) KerArg2);
				__CALL(KerLinear_8aSigmoid_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on D1 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+2240), 32, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
	/*====================== Call Kernel LOC_EPILOG =========================*/
	NE16_Disable(
	);
}
void  S15__decoder_decoder_net_decoder_net_0_Gemm_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos,
		unsigned char * __restrict__ SigmoidLUT_u8)

{
	/* Shared L1: 2932 bytes, L2 buffer: 0 bytes */
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
		[Tile0 Dim: 1][D1 Dim: Init: 64, Tiled: 1][D0 Dim: Init: 32, Tiled: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 32 )[D0, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 32 (Total Size: 2048 )[D1, [0 x 2048, 2048]][D0, [0 x 2048, 2048]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2048, 2048]][D0, [0 x 2048, 2048]]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2080 (Total Size: 256 )[D1, [0 x 256, 256]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 256, 256]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2336 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2400 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2464 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2528 (Total Size: 20 )[Tile0, 1:[1x1], 20]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 20]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	Ker Arg: BuffOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2548 (Total Size: 256 )[Tile0, 1:[32x1], 8]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[32x1], 8]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: SigmoidLUT_u8, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2804 (Total Size: 128 )[Tile0, 1:[128x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[128x1], 1]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (signed char * __restrict__) (FCAutoEncoder_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (FCAutoEncoder_L1_Memory+32);
	KerArg2->Bias = (int * __restrict__) (FCAutoEncoder_L1_Memory+2080);
	KerArg2->Out = (int * __restrict__) (FCAutoEncoder_L1_Memory+2336);
	KerArg2->Scale = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+2400);
	KerArg2->ScaleN = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+2464);
	KerArg2->Tile_InFeat = (unsigned short int) (32);
	KerArg2->Tile_OutFeat = (unsigned short int) (64);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (62947575);
	KerArg2->BuffOut = (int * __restrict__) (FCAutoEncoder_L1_Memory+2548);
	KerArg2->Infos = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+2528);
	KerArg2->Extra = (void * __restrict__) (FCAutoEncoder_L1_Memory+2804);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+32), 2048, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+2080), 256, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) SigmoidLUT_u8+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+2804), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+2400), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+2464), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+0), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+2528), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
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
				KerArg2->W_Offset = (int) (((int *)(FCAutoEncoder_L1_Memory+2528))[4]);
				AT_FORK_CC(gap_ncore(), (void *) KerLinear_8aSigmoid_NE16, (void *) KerArg2);
				__CALL(KerLinear_8aSigmoid_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on D1 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+2336), 64, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
	/*====================== Call Kernel LOC_EPILOG =========================*/
	NE16_Disable(
	);
}
void  S18__decoder_decoder_net_decoder_net_3_Gemm_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos,
		unsigned char * __restrict__ SigmoidLUT_u8)

{
	/* Shared L1: 9556 bytes, L2 buffer: 0 bytes */
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
		[Tile0 Dim: 1][D1 Dim: Init: 128, Tiled: 1][D0 Dim: Init: 64, Tiled: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 64 )[D0, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 64 (Total Size: 8192 )[D1, [0 x 8192, 8192]][D0, [0 x 8192, 8192]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 8192, 8192]][D0, [0 x 8192, 8192]]
		Tile0: [0, 8192, 8192], Tile1: [0, 8192, 8192], Tile2; [0, 8192, 8192]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 8256 (Total Size: 512 )[D1, [0 x 512, 512]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 512, 512]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 8768 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 8896 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 9024 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 9152 (Total Size: 20 )[Tile0, 1:[1x1], 20]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 20]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	Ker Arg: BuffOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 9172 (Total Size: 256 )[Tile0, 1:[32x1], 8]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[32x1], 8]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: SigmoidLUT_u8, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 9428 (Total Size: 128 )[Tile0, 1:[128x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[128x1], 1]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (signed char * __restrict__) (FCAutoEncoder_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (FCAutoEncoder_L1_Memory+64);
	KerArg2->Bias = (int * __restrict__) (FCAutoEncoder_L1_Memory+8256);
	KerArg2->Out = (int * __restrict__) (FCAutoEncoder_L1_Memory+8768);
	KerArg2->Scale = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+8896);
	KerArg2->ScaleN = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+9024);
	KerArg2->Tile_InFeat = (unsigned short int) (64);
	KerArg2->Tile_OutFeat = (unsigned short int) (128);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (62947575);
	KerArg2->BuffOut = (int * __restrict__) (FCAutoEncoder_L1_Memory+9172);
	KerArg2->Infos = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+9152);
	KerArg2->Extra = (void * __restrict__) (FCAutoEncoder_L1_Memory+9428);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+64), 8192, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+8256), 512, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+8896), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+9024), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) SigmoidLUT_u8+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+9428), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+0), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+9152), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
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
				KerArg2->W_Offset = (int) (((int *)(FCAutoEncoder_L1_Memory+9152))[4]);
				AT_FORK_CC(gap_ncore(), (void *) KerLinear_8aSigmoid_NE16, (void *) KerArg2);
				__CALL(KerLinear_8aSigmoid_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on D1 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+8768), 128, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
	/*====================== Call Kernel LOC_EPILOG =========================*/
	NE16_Disable(
	);
}
void  S21__decoder_decoder_net_decoder_net_6_Gemm_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos,
		unsigned char * __restrict__ SigmoidLUT_u8)

{
	/* Shared L1: 35092 bytes, L2 buffer: 0 bytes */
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
		[Tile0 Dim: 1][D1 Dim: Init: 256, Tiled: 1][D0 Dim: Init: 128, Tiled: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 128 )[D0, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 128 (Total Size: 32768 )[D1, [0 x 32768, 32768]][D0, [0 x 32768, 32768]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32768, 32768]][D0, [0 x 32768, 32768]]
		Tile0: [0, 32768, 32768], Tile1: [0, 32768, 32768], Tile2; [0, 32768, 32768]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 32896 (Total Size: 1024 )[D1, [0 x 1024, 1024]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 1024, 1024]]
		Tile0: [0, 1024, 1024], Tile1: [0, 1024, 1024], Tile2; [0, 1024, 1024]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 33920 (Total Size: 256 )[D1, [0 x 256, 256]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 256, 256]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 34176 (Total Size: 256 )[D1, [0 x 256, 256]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 256, 256]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 34432 (Total Size: 256 )[D1, [0 x 256, 256]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 256, 256]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 34688 (Total Size: 20 )[Tile0, 1:[1x1], 20]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 20]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	Ker Arg: BuffOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 34708 (Total Size: 256 )[Tile0, 1:[32x1], 8]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[32x1], 8]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: SigmoidLUT_u8, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 34964 (Total Size: 128 )[Tile0, 1:[128x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[128x1], 1]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (signed char * __restrict__) (FCAutoEncoder_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (FCAutoEncoder_L1_Memory+128);
	KerArg2->Bias = (int * __restrict__) (FCAutoEncoder_L1_Memory+32896);
	KerArg2->Out = (int * __restrict__) (FCAutoEncoder_L1_Memory+33920);
	KerArg2->Scale = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+34176);
	KerArg2->ScaleN = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+34432);
	KerArg2->Tile_InFeat = (unsigned short int) (128);
	KerArg2->Tile_OutFeat = (unsigned short int) (256);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (62947575);
	KerArg2->BuffOut = (int * __restrict__) (FCAutoEncoder_L1_Memory+34708);
	KerArg2->Infos = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+34688);
	KerArg2->Extra = (void * __restrict__) (FCAutoEncoder_L1_Memory+34964);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+128), 32768, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+32896), 1024, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+34176), 256, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+34432), 256, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+0), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) SigmoidLUT_u8+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+34964), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+34688), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
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
				KerArg2->W_Offset = (int) (((int *)(FCAutoEncoder_L1_Memory+34688))[4]);
				AT_FORK_CC(gap_ncore(), (void *) KerLinear_8aSigmoid_NE16, (void *) KerArg2);
				__CALL(KerLinear_8aSigmoid_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on D1 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+33920), 256, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
	/*====================== Call Kernel LOC_EPILOG =========================*/
	NE16_Disable(
	);
}
void  S24__decoder_decoder_net_decoder_net_9_Gemm_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos,
		unsigned char * __restrict__ SigmoidLUT_u8)

{
	/* Shared L1: 102548 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerLinear_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_Filter;
	unsigned int _SN_Filter;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1][D1 Dim: Init: 512, Tiled: 3][D0 Dim: Init: 256, Tiled: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 256 )[D0, [0 x 256, 256]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 256, 256]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Filter, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 256 (Total Size: 131072 )[D1, [2 x 49152, 32768]][D0, [0 x 49152, 49152]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [2 x 49152, 32768]][D0, [0 x 49152, 49152]]
		Tile0: [0, 49152, 49152], Tile1: [49152, 49152, 49152], Tile2; [98304, 32768, 32768]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 3 logical tiles, 1 physical tiles
			@ 98560 (Total Size: 2048 )[D1, [2 x 768, 512]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [2 x 768, 512]]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 3 logical tiles, 1 physical tiles
			@ 100608 (Total Size: 512 )[D1, [2 x 192, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [2 x 192, 128]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 3 logical tiles, 1 physical tiles
			@ 101120 (Total Size: 512 )[D1, [2 x 192, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [2 x 192, 128]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 3 logical tiles, 1 physical tiles
			@ 101632 (Total Size: 512 )[D1, [2 x 192, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [2 x 192, 128]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 102144 (Total Size: 20 )[Tile0, 1:[1x1], 20]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 20]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	Ker Arg: BuffOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 102164 (Total Size: 256 )[Tile0, 1:[32x1], 8]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[32x1], 8]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: SigmoidLUT_u8, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 102420 (Total Size: 128 )[Tile0, 1:[128x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[128x1], 1]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (signed char * __restrict__) (FCAutoEncoder_L1_Memory+0);
	KerArg2->Bias = (int * __restrict__) (FCAutoEncoder_L1_Memory+98560);
	KerArg2->Out = (int * __restrict__) (FCAutoEncoder_L1_Memory+100608);
	KerArg2->Scale = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+101120);
	KerArg2->ScaleN = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+101632);
	KerArg2->Tile_InFeat = (unsigned short int) (256);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (62947575);
	KerArg2->BuffOut = (int * __restrict__) (FCAutoEncoder_L1_Memory+102164);
	KerArg2->Infos = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+102144);
	KerArg2->Extra = (void * __restrict__) (FCAutoEncoder_L1_Memory+102420);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+256+0), 49152, 0, DmaR_Evt1);
	_N_Filter=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+98560), 2048, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+101120), 512, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+101632), 512, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+0), 256, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) SigmoidLUT_u8+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+102420), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+102144), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		for (D1Ind=0; D1Ind<3; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
			int D1Ind_Last = (D1Ind==2), D1Ind_NextLast = ((D1Ind+1)==2);
			/*================================= Prepare Tiles ===================================*/
			_SN_Filter = 0;
			if (!(D1Ind_Last)) {
				_N_Filter = _N_Filter + (49152); _SN_Filter = (((D1Ind_NextLast)?32768:49152)); 
			} else if (!(1)) {
				_N_Filter = _N_Filter + (-98304); _SN_Filter = (49152); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Filter */
			if (_SN_Filter) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+_N_Filter), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+256+49152*((D1Ind_Total+1)%2)),
						1*(_SN_Filter), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->Filter = (unsigned short * __restrict__) (FCAutoEncoder_L1_Memory+256+49152*((D1Ind_Total)%2));
				KerArg2->Bias = (int * __restrict__) (FCAutoEncoder_L1_Memory+98560+((D1Ind)*768));
				KerArg2->Out = (int * __restrict__) (FCAutoEncoder_L1_Memory+100608+((D1Ind)*192));
				KerArg2->Scale = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+101120+((D1Ind)*192));
				KerArg2->ScaleN = (unsigned char * __restrict__) (FCAutoEncoder_L1_Memory+101632+((D1Ind)*192));
				KerArg2->Tile_OutFeat = (unsigned short int) ((D1Ind_Last)?128:192);
				KerArg2->W_Offset = (int) (((int *)(FCAutoEncoder_L1_Memory+102144))[4]);
				AT_FORK_CC(gap_ncore(), (void *) KerLinear_8aSigmoid_NE16, (void *) KerArg2);
				__CALL(KerLinear_8aSigmoid_NE16, KerArg2);
			} /* End iteration on D0 */
			/*================================= Update Arg Pipeline =============================*/
			/*============================= End Update Arg Pipeline =============================*/
		} /* End iteration on D1 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+100608), 512, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
	/*====================== Call Kernel LOC_EPILOG =========================*/
	NE16_Disable(
	);
}
void  S27_expr_0(
		unsigned char * __restrict__ expr_0_in_0,
		signed char * __restrict__ expr_0_in_1,
		signed char * __restrict__ expr_0_in_2,
		unsigned char * __restrict__ expr_0_out_0)

{
	/* Shared L1: 2048 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	s27_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

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
	Ker Arg: expr_0_in_2, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1536 (Total Size: 512 )[D0, [0 x 512, 512]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 512, 512]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (512);
	KerArg0->expr_0_in_0 = (unsigned char *__restrict__ ) (FCAutoEncoder_L1_Memory+512);
	KerArg0->expr_0_in_1 = (signed char *__restrict__ ) (FCAutoEncoder_L1_Memory+1024);
	KerArg0->expr_0_in_2 = (signed char *__restrict__ ) (FCAutoEncoder_L1_Memory+1536);
	KerArg0->expr_0_out_0 = (unsigned char *__restrict__ ) (FCAutoEncoder_L1_Memory+0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_0_in_0+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+512), 512, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_0_in_1+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+1024), 512, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_0_in_2+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+1536), 512, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_0_in_2 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_D0 =========================*/
		AT_FORK(gap_ncore(), (void *) s27_kernel, (void *) KerArg0);
		__CALL(s27_kernel, KerArg0);
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_0_out_0+0), ((AT_L2_INT_ADDR_TYPE) FCAutoEncoder_L1_Memory+0), 512, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write expr_0_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
#pragma GCC diagnostic pop
int  FCAutoEncoderCNN_Construct()

{
	int Error;

	AT_DEFAULTFLASH_FS_CONF_T DefaultFlashConf;
	AT_DEFAULTFLASH_FS_CONF_INIT(&DefaultFlashConf, AT_MEM_L3_DEFAULTFLASH, 0);
	AT_DEFAULTFLASH_FS_OPEN(&DefaultFlash, &DefaultFlashConf, 0, "FCAutoEncoder_L3_Flash_Const.dat", &Error);
	if (Error) return AT_FLASH_OPEN_ERROR;

	FCAutoEncoder_L2_Memory = (AT_L2_POINTER) AT_L2_ALLOC(0, 358112);
	if (FCAutoEncoder_L2_Memory == 0) return AT_L2_OPEN_ERROR;
	FCAutoEncoder_L2_Memory_Dyn = (AT_L2_POINTER) AT_L2_ALLOC(0, 768);
	if (FCAutoEncoder_L2_Memory_Dyn == 0) return AT_L2_OPEN_ERROR;
	FCAutoEncoder_L1_Memory = (AT_L1_POINTER) AT_L1_ALLOC(0, 115340);
	if (FCAutoEncoder_L1_Memory == 0) return AT_L1_OPEN_ERROR;
	AT_DEFAULTFLASH_FS_FC_EVENT _UchanHF1, *UchanHF1 = &_UchanHF1;
	/* Static Moving _encoder_encoder_net_encoder_net_0_gemm_weights, size 131072 from DefaultFlash at 128 to (size 131072) L2 at 128..131199 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 128), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 128), 131072, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _encoder_encoder_net_encoder_net_0_gemm_biases, size 1024 from DefaultFlash at 350336 to (size 1024) L2 at 350336..351359 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 350336), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 350336), 1024, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S3_Mul_scale, size 256 from DefaultFlash at 355456 to (size 256) L2 at 355456..355711 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 355456), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 355456), 256, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S3_Mul_shift, size 256 from DefaultFlash at 355712 to (size 256) L2 at 355712..355967 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 355712), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 355712), 256, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S3_Infos, size 20 from DefaultFlash at 357952 to (size 20) L2 at 357952..357971 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 357952), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 357952), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _encoder_encoder_net_encoder_net_3_gemm_weights, size 32768 from DefaultFlash at 262272 to (size 32768) L2 at 262272..295039 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 262272), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 262272), 32768, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _encoder_encoder_net_encoder_net_3_gemm_biases, size 512 from DefaultFlash at 352384 to (size 512) L2 at 352384..352895 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 352384), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 352384), 512, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S6_Mul_scale, size 128 from DefaultFlash at 356992 to (size 128) L2 at 356992..357119 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 356992), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 356992), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S6_Mul_shift, size 128 from DefaultFlash at 357120 to (size 128) L2 at 357120..357247 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 357120), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 357120), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S6_Infos, size 20 from DefaultFlash at 357972 to (size 20) L2 at 357972..357991 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 357972), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 357972), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _encoder_encoder_net_encoder_net_6_gemm_weights, size 8192 from DefaultFlash at 327808 to (size 8192) L2 at 327808..335999 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 327808), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 327808), 8192, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _encoder_encoder_net_encoder_net_6_gemm_biases, size 256 from DefaultFlash at 355968 to (size 256) L2 at 355968..356223 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 355968), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 355968), 256, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S9_Mul_scale, size 64 from DefaultFlash at 357632 to (size 64) L2 at 357632..357695 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 357632), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 357632), 64, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S9_Mul_shift, size 64 from DefaultFlash at 357696 to (size 64) L2 at 357696..357759 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 357696), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 357696), 64, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S9_Infos, size 20 from DefaultFlash at 357992 to (size 20) L2 at 357992..358011 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 357992), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 357992), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _encoder_encoder_net_encoder_net_9_gemm_weights, size 2048 from DefaultFlash at 344192 to (size 2048) L2 at 344192..346239 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 344192), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 344192), 2048, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _encoder_encoder_net_encoder_net_9_gemm_biases, size 128 from DefaultFlash at 357248 to (size 128) L2 at 357248..357375 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 357248), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 357248), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S12_Mul_scale, size 32 from DefaultFlash at 357888 to (size 32) L2 at 357888..357919 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 357888), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 357888), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S12_Mul_shift, size 32 from DefaultFlash at 357920 to (size 32) L2 at 357920..357951 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 357920), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 357920), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S12_Infos, size 20 from DefaultFlash at 358012 to (size 20) L2 at 358012..358031 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 358012), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 358012), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _decoder_decoder_net_decoder_net_0_gemm_weights, size 2048 from DefaultFlash at 346240 to (size 2048) L2 at 346240..348287 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 346240), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 346240), 2048, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _decoder_decoder_net_decoder_net_0_gemm_biases, size 256 from DefaultFlash at 356224 to (size 256) L2 at 356224..356479 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 356224), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 356224), 256, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S15_Mul_scale, size 64 from DefaultFlash at 357760 to (size 64) L2 at 357760..357823 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 357760), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 357760), 64, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S15_Mul_shift, size 64 from DefaultFlash at 357824 to (size 64) L2 at 357824..357887 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 357824), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 357824), 64, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S15_Infos, size 20 from DefaultFlash at 358032 to (size 20) L2 at 358032..358051 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 358032), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 358032), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _decoder_decoder_net_decoder_net_3_gemm_weights, size 8192 from DefaultFlash at 336000 to (size 8192) L2 at 336000..344191 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 336000), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 336000), 8192, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _decoder_decoder_net_decoder_net_3_gemm_biases, size 512 from DefaultFlash at 352896 to (size 512) L2 at 352896..353407 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 352896), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 352896), 512, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S18_Mul_scale, size 128 from DefaultFlash at 357376 to (size 128) L2 at 357376..357503 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 357376), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 357376), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S18_Mul_shift, size 128 from DefaultFlash at 357504 to (size 128) L2 at 357504..357631 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 357504), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 357504), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S18_Infos, size 20 from DefaultFlash at 358052 to (size 20) L2 at 358052..358071 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 358052), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 358052), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _decoder_decoder_net_decoder_net_6_gemm_weights, size 32768 from DefaultFlash at 295040 to (size 32768) L2 at 295040..327807 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 295040), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 295040), 32768, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _decoder_decoder_net_decoder_net_6_gemm_biases, size 1024 from DefaultFlash at 351360 to (size 1024) L2 at 351360..352383 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 351360), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 351360), 1024, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S21_Mul_scale, size 256 from DefaultFlash at 356480 to (size 256) L2 at 356480..356735 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 356480), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 356480), 256, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S21_Mul_shift, size 256 from DefaultFlash at 356736 to (size 256) L2 at 356736..356991 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 356736), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 356736), 256, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S21_Infos, size 20 from DefaultFlash at 358072 to (size 20) L2 at 358072..358091 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 358072), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 358072), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _decoder_decoder_net_decoder_net_9_gemm_weights, size 131072 from DefaultFlash at 131200 to (size 131072) L2 at 131200..262271 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 131200), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 131200), 131072, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _decoder_decoder_net_decoder_net_9_gemm_biases, size 2048 from DefaultFlash at 348288 to (size 2048) L2 at 348288..350335 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 348288), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 348288), 2048, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S24_Mul_scale, size 512 from DefaultFlash at 353408 to (size 512) L2 at 353408..353919 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 353408), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 353408), 512, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S24_Mul_shift, size 512 from DefaultFlash at 353920 to (size 512) L2 at 353920..354431 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 353920), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 353920), 512, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S24_Infos, size 20 from DefaultFlash at 358092 to (size 20) L2 at 358092..358111 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 358092), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 358092), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _decoder_decoder_net_decoder_net_11_batchnormalization_scale, size 512 from DefaultFlash at 354432 to (size 512) L2 at 354432..354943 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 354432), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 354432), 512, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _decoder_decoder_net_decoder_net_11_batchnormalization_bias, size 512 from DefaultFlash at 354944 to (size 512) L2 at 354944..355455 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 354944), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 354944), 512, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving SigmoidLUT_u8, size 128 from DefaultFlash at 0 to (size 128) L2 at 0..127 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FCAutoEncoder_L3_Flash + 0), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FCAutoEncoder_L2_Memory + 0), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	return AT_NO_ERROR;
}
void FCAutoEncoderCNN_ConstructCluster()

{
}
int  FCAutoEncoderCNN_Destruct()

{
	AT_L2_FREE(0, FCAutoEncoder_L2_Memory_Dyn, 768);
	AT_L2_FREE(0, FCAutoEncoder_L2_Memory, 358112);
	AT_L1_FREE(0, FCAutoEncoder_L1_Memory, 115340);
	AT_DEFAULTFLASH_FS_CLOSE(&DefaultFlash);
	return 0;
}
int FCAutoEncoderCNN_Memory(AT_MEM_TYPE Which)

{
	switch (Which) {
		case AT_L1_MEM:     return 115340; /* L1 Memory */
		case AT_L2_MEM:     return 358112; /* L2 Memory, permanent */
		case AT_L2_DYN_MEM: return 768; /* L2 Memory, dynamic */
		case AT_L3_MEM:     return 0; /* L3 Memory, permanent */
		case AT_L3_DYN_MEM: return 0; /* L3 Memory, dynamic */
		default:            return 0;
	}
}
unsigned int AT_GraphPerf[10];
unsigned int AT_GraphPerf_CNN_Total = 0;
unsigned int AT_GraphOperInfosNames[10] = {
	131328,
	32896,
	8256,
	2080,
	2112,
	8320,
	33024,
	131584,
	1024,
	0,
};
char *AT_GraphNodeNames[10] = {
	"S3__encoder_encoder_net_encoder_net_0_Gemm_fusion",
	"S6__encoder_encoder_net_encoder_net_3_Gemm_fusion",
	"S9__encoder_encoder_net_encoder_net_6_Gemm_fusion",
	"S12__encoder_encoder_net_encoder_net_9_Gemm_fusion",
	"S15__decoder_decoder_net_decoder_net_0_Gemm_fusion",
	"S18__decoder_decoder_net_decoder_net_3_Gemm_fusion",
	"S21__decoder_decoder_net_decoder_net_6_Gemm_fusion",
	"S24__decoder_decoder_net_decoder_net_9_Gemm_fusion",
	"S27_expr_0",
	"IO_Wait",
};
int  FCAutoEncoderCNN(
		unsigned char * __restrict__ Input_1,
		unsigned char * __restrict__ Output_1)

{
	unsigned int Start_IO;
	AT_GraphPerf_CNN_Total = gap_cl_readhwtimer();
	AT_GraphPerf[0] = gap_cl_readhwtimer();
	AT_GraphPerf[9] = 0;
	S3__encoder_encoder_net_encoder_net_0_Gemm_fusion(
		((unsigned char * __restrict__) Input_1), /* In */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory+128)), /* Filter */
		((signed int * __restrict__) (FCAutoEncoder_L2_Memory+350336)), /* Bias */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory+355456)), /* Scale */
		((signed char * __restrict__) (FCAutoEncoder_L2_Memory+355712)), /* ScaleN */
		((signed char * __restrict__) (FCAutoEncoder_L2_Memory+357952)), /* Infos */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory+0)) /* SigmoidLUT_u8 */
	);
	AT_GraphPerf[0] = gap_cl_readhwtimer() - AT_GraphPerf[0];
	AT_GraphPerf[1] = gap_cl_readhwtimer();
	S6__encoder_encoder_net_encoder_net_3_Gemm_fusion(
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory+262272)), /* Filter */
		((signed int * __restrict__) (FCAutoEncoder_L2_Memory+352384)), /* Bias */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory_Dyn+256)), /* Out */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory+356992)), /* Scale */
		((signed char * __restrict__) (FCAutoEncoder_L2_Memory+357120)), /* ScaleN */
		((signed char * __restrict__) (FCAutoEncoder_L2_Memory+357972)), /* Infos */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory+0)) /* SigmoidLUT_u8 */
	);
	AT_GraphPerf[1] = gap_cl_readhwtimer() - AT_GraphPerf[1];
	AT_GraphPerf[2] = gap_cl_readhwtimer();
	S9__encoder_encoder_net_encoder_net_6_Gemm_fusion(
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory_Dyn+256)), /* In */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory+327808)), /* Filter */
		((signed int * __restrict__) (FCAutoEncoder_L2_Memory+355968)), /* Bias */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory+357632)), /* Scale */
		((signed char * __restrict__) (FCAutoEncoder_L2_Memory+357696)), /* ScaleN */
		((signed char * __restrict__) (FCAutoEncoder_L2_Memory+357992)), /* Infos */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory+0)) /* SigmoidLUT_u8 */
	);
	AT_GraphPerf[2] = gap_cl_readhwtimer() - AT_GraphPerf[2];
	AT_GraphPerf[3] = gap_cl_readhwtimer();
	S12__encoder_encoder_net_encoder_net_9_Gemm_fusion(
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory+344192)), /* Filter */
		((signed int * __restrict__) (FCAutoEncoder_L2_Memory+357248)), /* Bias */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory_Dyn+64)), /* Out */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory+357888)), /* Scale */
		((signed char * __restrict__) (FCAutoEncoder_L2_Memory+357920)), /* ScaleN */
		((signed char * __restrict__) (FCAutoEncoder_L2_Memory+358012)), /* Infos */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory+0)) /* SigmoidLUT_u8 */
	);
	AT_GraphPerf[3] = gap_cl_readhwtimer() - AT_GraphPerf[3];
	AT_GraphPerf[4] = gap_cl_readhwtimer();
	S15__decoder_decoder_net_decoder_net_0_Gemm_fusion(
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory_Dyn+64)), /* In */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory+346240)), /* Filter */
		((signed int * __restrict__) (FCAutoEncoder_L2_Memory+356224)), /* Bias */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory+357760)), /* Scale */
		((signed char * __restrict__) (FCAutoEncoder_L2_Memory+357824)), /* ScaleN */
		((signed char * __restrict__) (FCAutoEncoder_L2_Memory+358032)), /* Infos */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory+0)) /* SigmoidLUT_u8 */
	);
	AT_GraphPerf[4] = gap_cl_readhwtimer() - AT_GraphPerf[4];
	AT_GraphPerf[5] = gap_cl_readhwtimer();
	S18__decoder_decoder_net_decoder_net_3_Gemm_fusion(
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory+336000)), /* Filter */
		((signed int * __restrict__) (FCAutoEncoder_L2_Memory+352896)), /* Bias */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory_Dyn+64)), /* Out */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory+357376)), /* Scale */
		((signed char * __restrict__) (FCAutoEncoder_L2_Memory+357504)), /* ScaleN */
		((signed char * __restrict__) (FCAutoEncoder_L2_Memory+358052)), /* Infos */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory+0)) /* SigmoidLUT_u8 */
	);
	AT_GraphPerf[5] = gap_cl_readhwtimer() - AT_GraphPerf[5];
	AT_GraphPerf[6] = gap_cl_readhwtimer();
	S21__decoder_decoder_net_decoder_net_6_Gemm_fusion(
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory_Dyn+64)), /* In */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory+295040)), /* Filter */
		((signed int * __restrict__) (FCAutoEncoder_L2_Memory+351360)), /* Bias */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory_Dyn+512)), /* Out */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory+356480)), /* Scale */
		((signed char * __restrict__) (FCAutoEncoder_L2_Memory+356736)), /* ScaleN */
		((signed char * __restrict__) (FCAutoEncoder_L2_Memory+358072)), /* Infos */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory+0)) /* SigmoidLUT_u8 */
	);
	AT_GraphPerf[6] = gap_cl_readhwtimer() - AT_GraphPerf[6];
	AT_GraphPerf[7] = gap_cl_readhwtimer();
	S24__decoder_decoder_net_decoder_net_9_Gemm_fusion(
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory_Dyn+512)), /* In */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory+131200)), /* Filter */
		((signed int * __restrict__) (FCAutoEncoder_L2_Memory+348288)), /* Bias */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory+353408)), /* Scale */
		((signed char * __restrict__) (FCAutoEncoder_L2_Memory+353920)), /* ScaleN */
		((signed char * __restrict__) (FCAutoEncoder_L2_Memory+358092)), /* Infos */
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory+0)) /* SigmoidLUT_u8 */
	);
	AT_GraphPerf[7] = gap_cl_readhwtimer() - AT_GraphPerf[7];
	AT_GraphPerf[8] = gap_cl_readhwtimer();
	S27_expr_0(
		((unsigned char * __restrict__) (FCAutoEncoder_L2_Memory_Dyn+0)), /* expr_0_in_0 */
		((signed char * __restrict__) (FCAutoEncoder_L2_Memory+354432)), /* expr_0_in_1 */
		((signed char * __restrict__) (FCAutoEncoder_L2_Memory+354944)), /* expr_0_in_2 */
		((unsigned char * __restrict__) Output_1) /* expr_0_out_0 */
	);
	AT_GraphPerf[8] = gap_cl_readhwtimer() - AT_GraphPerf[8];
	AT_GraphPerf_CNN_Total = gap_cl_readhwtimer() - AT_GraphPerf_CNN_Total;
	return 0;
}
