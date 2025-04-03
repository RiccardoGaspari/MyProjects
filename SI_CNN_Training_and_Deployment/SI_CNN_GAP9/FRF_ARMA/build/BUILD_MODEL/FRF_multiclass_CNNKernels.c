#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#include "FRF_multiclass_CNNKernels.h"
#ifdef __EMUL__
unsigned int __L3_Read, __L3_Write, __L2_Read, __L2_Write;
#endif
L1_CL_MEM AT_L1_POINTER FRF_multiclass_CNN_L1_Memory;
L2_MEM AT_L2_POINTER FRF_multiclass_CNN_L2_Memory;
L2_MEM AT_L2_POINTER FRF_multiclass_CNN_L2_Memory_Dyn;
static AT_DEFAULTFLASH_FS_T DefaultFlash;
void  S4__conv1_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 14352 bytes, L2 buffer: 0 bytes */
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
		[D1 Dim: Init: 16, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 1, Tiled: 1]
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
			@ 56 (Total Size: 819 )[Tile0, 1:[819x1], 1][D0, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[819x1], 1][D0, [0 x 1, 1]]
		Tile0: [0, 819, 819], Tile1: [0, 819, 819], Tile2; [0, 819, 819]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 876 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 940 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 956 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 972 (Total Size: 256 )[D1, [0 x 256, 256]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 256, 256]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1228 (Total Size: 13104 )[Tile0, 1:[819x1], 16][D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]][Tile0, 1:[819x1], 16]
		Tile0: [0, 13104, 13104], Tile1: [0, 13104, 13104], Tile2; [0, 13104, 13104]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 14332 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+56);
	KerArg2->ColBuff = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (FRF_multiclass_CNN_L1_Memory+972);
	KerArg2->Bias = (int * __restrict__) (FRF_multiclass_CNN_L1_Memory+876);
	KerArg2->Out = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+1228);
	KerArg2->Scale = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+940);
	KerArg2->ScaleN = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+956);
	KerArg2->Tile_InFeat = (unsigned short int) (1);
	KerArg2->TotalInFeatures = (unsigned short int) (1);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (819);
	KerArg2->Tile_OutFeat = (unsigned short int) (16);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (819);
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
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+56), 819, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+972), 256, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+876), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+14332), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+940), 16, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+956), 16, 0, 0);
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
				KerArg2->W_Offset = (int) (((int *)(FRF_multiclass_CNN_L1_Memory+14332))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+1228), 13104, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S7__conv2_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115572 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;
	Ker_MM_Pool_USQ8_T S_KerArg3, *KerArg3 = &S_KerArg3;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last, D1Ind_NextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _N_In;
	unsigned int _SN_In;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 32, Tiled: 1][Tile0 Dim: 2][D0 Dim: Init: 16, Tiled: 1]
	Ker Arg: Out, Tiled Space: D1
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 2 logical tiles, 2 physical tiles
			@ 96736 (Total Size: 13088 )[Tile0, 2:[1x294, 1x115], 32][D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]][Tile0, 2:[1x294], 32]
		Tile0: [0, 9408, 9408], Tile1: [9408, 3680, 3680], Tile2; [0, 9408, 9408]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 2 physical tiles
			@ 864 (Total Size: 13104 )[Tile0, 2:[1x589, 1x232], 16][D0, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 2:[1x589, 1x232], 16][D0, [0 x 16, 16]]
		Tile0: [0, 9424, 9424], Tile1: [9392, 3712, 3712], Tile2; [0, 9424, 9424]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 19744 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 19872 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 19904 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 19936 (Total Size: 1536 )[D1, [0 x 1536, 1536]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 1536, 1536]]
		Tile0: [0, 1536, 1536], Tile1: [0, 1536, 1536], Tile2; [0, 1536, 1536]
	Ker Arg: ConvOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			@ 21472 (Total Size: 104832 )[Tile0, 2:[1x588, 1x230], 128][D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]][Tile0, 2:[1x588], 128]
		Tile0: [0, 75264, 75264], Tile1: [0, 75264, 75264], Tile2; [0, 75264, 75264]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			@ 0 (Total Size: 864 )[Tile0, 2:[1x864, 1x864], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 2:[1x864, 1x864], 1]
		Tile0: [0, 864, 864], Tile1: [0, 864, 864], Tile2; [0, 864, 864]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			@ 115552 (Total Size: 20 )[Tile0, 2:[1x20, 1x20], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 2:[1x20, 1x20], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->ColBuff = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (FRF_multiclass_CNN_L1_Memory+19936);
	KerArg2->Bias = (int * __restrict__) (FRF_multiclass_CNN_L1_Memory+19744);
	KerArg2->Out = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+21472);
	KerArg2->Scale = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+19872);
	KerArg2->ScaleN = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+19904);
	KerArg2->Tile_InFeat = (unsigned short int) (16);
	KerArg2->TotalInFeatures = (unsigned short int) (16);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_OutFeat = (unsigned short int) (32);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Pad_Val = (unsigned short int) (0);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (3);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (1);
	KerArg3->In = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+21472);
	KerArg3->H = (unsigned short int) (1);
	KerArg3->Fx = (unsigned short int) (2);
	KerArg3->Fy = (unsigned short int) (1);
	KerArg3->Sx = (unsigned char) (2);
	KerArg3->Sy = (unsigned char) (1);
	KerArg3->Pad = (v4s) 0;
	KerArg3->Feat = (unsigned short int) (32);
	KerArg3->Ho = (unsigned short int) (1);
	KerArg3->Infos = (signed char * __restrict__) (FRF_multiclass_CNN_L1_Memory+115552);
	KerArg3->Extra = (void *) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+864+0), 9424, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=9408;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+19936), 1536, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+19744), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+19872), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+19904), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+115552), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1, D1Ind_NextLast = 1;
		for (T0Ind=0; T0Ind<2; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==1), T0Ind_NextLast = ((T0Ind+1)==1);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (9408-(16*(T0Ind==0))); _SN_In = (((1)?232:590)*(16)); 
			} else if (!(1)) {
				_N_In = _N_In + (-9392); _SN_In = (590*(16)); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+864+9440*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->In = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+864+9440*((T0Ind_Total)%2));
				KerArg2->Tile_InW = (unsigned short int) (((T0Ind_Last)?232:590)-1*(T0Ind==0));
				KerArg2->Tile_OutW = (unsigned short int) ((T0Ind_Last)?230:588);
				KerArg2->Pad = (v4s) ((v4s){1*(T0Ind==0),0*(T0Ind_Last),0,0});
				KerArg2->FirstTile = (unsigned char) ((T0Ind==0));
				KerArg2->W_Offset = (int) (((int *)(FRF_multiclass_CNN_L1_Memory+115552))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
			/*====================== Call Kernel LOC_D0_EPILOG =========================*/
			KerArg3->W = (unsigned short int) ((T0Ind_Last)?230:588);
			KerArg3->FirstTile = (unsigned char) ((T0Ind==0));
			KerArg3->Out = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+96736+9408*((T0Ind_Total)%2));
			KerArg3->Wo = (unsigned short int) ((T0Ind_Last)?115:294);
			AT_FORK(gap_ncore(), (void *) KerParMaxPoolNxMStrideSxSy_HWC_USQ8, (void *) KerArg3);
			__CALL(KerParMaxPoolNxMStrideSxSy_HWC_USQ8, KerArg3);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+96736+9408*((T0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (9408); _SC_Out = (((1)?115:294)*(32)); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S10__conv3_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 31188 bytes, L2 buffer: 0 bytes */
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
			@ 1728 (Total Size: 13088 )[Tile0, 1:[409x1], 32][D0, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[409x1], 32][D0, [0 x 32, 32]]
		Tile0: [0, 13088, 13088], Tile1: [0, 13088, 13088], Tile2; [0, 13088, 13088]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 14816 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 14944 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 14976 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 15008 (Total Size: 3072 )[D1, [0 x 3072, 3072]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 3072, 3072]]
		Tile0: [0, 3072, 3072], Tile1: [0, 3072, 3072], Tile2; [0, 3072, 3072]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 18080 (Total Size: 13088 )[Tile0, 1:[409x1], 32][D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]][Tile0, 1:[409x1], 32]
		Tile0: [0, 13088, 13088], Tile1: [0, 13088, 13088], Tile2; [0, 13088, 13088]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 31168 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+1728);
	KerArg2->ColBuff = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (FRF_multiclass_CNN_L1_Memory+15008);
	KerArg2->Bias = (int * __restrict__) (FRF_multiclass_CNN_L1_Memory+14816);
	KerArg2->Out = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+18080);
	KerArg2->Scale = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+14944);
	KerArg2->ScaleN = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+14976);
	KerArg2->Tile_InFeat = (unsigned short int) (32);
	KerArg2->TotalInFeatures = (unsigned short int) (32);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (409);
	KerArg2->Tile_OutFeat = (unsigned short int) (32);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (409);
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
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+1728), 13088, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+15008), 3072, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+14816), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+14944), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+14976), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+31168), 20, 0, 0);
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
				KerArg2->W_Offset = (int) (((int *)(FRF_multiclass_CNN_L1_Memory+31168))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+18080), 13088, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S13__conv4_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 86772 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;
	Ker_MM_Pool_USQ8_T S_KerArg3, *KerArg3 = &S_KerArg3;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _LP_Out, _LC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 64, Tiled: 2][Tile0 Dim: 1][D0 Dim: Init: 32, Tiled: 1]
	Ker Arg: ConvOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			@ 21344 (Total Size: 104704 )[Tile0, 1:[409x1], 256][D1, [1 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [1 x 128, 128]][Tile0, 1:[409x1, 409x1], 256]
		Tile0: [0, 52352, 128], Tile1: [0, 52352, 128], Tile2; [0, 52352, 128]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 1728 (Total Size: 13088 )[Tile0, 1:[409x1], 32][D0, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[409x1], 32][D0, [0 x 32, 32]]
		Tile0: [0, 13088, 13088], Tile1: [0, 13088, 13088], Tile2; [0, 13088, 13088]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			@ 14816 (Total Size: 256 )[D1, [1 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [1 x 128, 128]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			@ 15072 (Total Size: 64 )[D1, [1 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [1 x 32, 32]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			@ 15136 (Total Size: 64 )[D1, [1 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [1 x 32, 32]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			@ 15200 (Total Size: 6144 )[D1, [1 x 3072, 3072]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [1 x 3072, 3072]]
		Tile0: [0, 6144, 6144], Tile1: [0, 6144, 6144], Tile2; [0, 6144, 6144]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 1728 )[Tile0, 1:[1728x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1728x1], 1]
		Tile0: [0, 1728, 1728], Tile1: [0, 1728, 1728], Tile2; [0, 1728, 1728]
	Ker Arg: Out, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 2 physical tiles
			@ 73696 (Total Size: 13056 )[Tile0, 1:[204x1], 64][D1, [1 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [1 x 32, 32]][Tile0, 1:[204x1, 204x1], 64]
		Tile0: [0, 6528, 32], Tile1: [32, 6528, 32], Tile2; [0, 6528, 32]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 86752 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+1728);
	KerArg2->ColBuff = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+0);
	KerArg2->Out = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+21344);
	KerArg2->Tile_InFeat = (unsigned short int) (32);
	KerArg2->TotalInFeatures = (unsigned short int) (32);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (409);
	KerArg2->Tile_OutFeat = (unsigned short int) (32);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (409);
	KerArg2->Pad_Val = (unsigned short int) (0);
	KerArg2->Pad = (v4s) ((v4s){1,0,0,0});
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->FirstTile = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (3);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (0);
	KerArg3->In = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+21344);
	KerArg3->W = (unsigned short int) (409);
	KerArg3->H = (unsigned short int) (1);
	KerArg3->Fx = (unsigned short int) (2);
	KerArg3->Fy = (unsigned short int) (1);
	KerArg3->Sx = (unsigned char) (2);
	KerArg3->Sy = (unsigned char) (1);
	KerArg3->FirstTile = (unsigned char) ((1));
	KerArg3->Pad = (v4s) 0;
	KerArg3->Feat = (unsigned short int) (32);
	KerArg3->Wo = (unsigned short int) (204);
	KerArg3->Ho = (unsigned short int) (1);
	KerArg3->Infos = (signed char * __restrict__) (FRF_multiclass_CNN_L1_Memory+86752);
	KerArg3->Extra = (void *) (0);
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=6528; _LC_Out=32;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+1728), 13088, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+15200), 6144, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+14816), 256, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+15072), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+15136), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+86752), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	for (D1Ind=0; D1Ind<2; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
		int D1Ind_Last = (D1Ind==1), D1Ind_NextLast = ((D1Ind+1)==1);
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->Filter = (unsigned short * __restrict__) (FRF_multiclass_CNN_L1_Memory+15200+((D1Ind)*3072));
				KerArg2->Bias = (int * __restrict__) (FRF_multiclass_CNN_L1_Memory+14816+((D1Ind)*128));
				KerArg2->Scale = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+15072+((D1Ind)*32));
				KerArg2->ScaleN = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+15136+((D1Ind)*32));
				KerArg2->W_Offset = (int) (((int *)(FRF_multiclass_CNN_L1_Memory+86752))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
			/*====================== Call Kernel LOC_D0_EPILOG =========================*/
			KerArg3->Out = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+73696+6528*((D1Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) KerParMaxPoolNxMStrideSxSy_HWC_USQ8, (void *) KerArg3);
			__CALL(KerParMaxPoolNxMStrideSxSy_HWC_USQ8, KerArg3);
		} /* End iteration on Tile0 */
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+73696+6528*((D1Ind_Total)%2)),
				_SC_Out, 64, _LC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_Out = _SC_Out;_LP_Out = _LC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(D1Ind_Last)) {
			_C_Out = _C_Out + (32); _LC_Out = (32); _SC_Out = (204*_LC_Out); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S16__conv5_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 67988 bytes, L2 buffer: 0 bytes */
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
		[D1 Dim: Init: 128, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 64, Tiled: 1]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 3456 )[Tile0, 1:[3456x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[3456x1], 1]
		Tile0: [0, 3456, 3456], Tile1: [0, 3456, 3456], Tile2; [0, 3456, 3456]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3456 (Total Size: 13056 )[Tile0, 1:[204x1], 64][D0, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[204x1], 64][D0, [0 x 64, 64]]
		Tile0: [0, 13056, 13056], Tile1: [0, 13056, 13056], Tile2; [0, 13056, 13056]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 16512 (Total Size: 512 )[D1, [0 x 512, 512]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 512, 512]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 17024 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 17152 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 17280 (Total Size: 24576 )[D1, [0 x 24576, 24576]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 24576, 24576]]
		Tile0: [0, 24576, 24576], Tile1: [0, 24576, 24576], Tile2; [0, 24576, 24576]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 41856 (Total Size: 26112 )[Tile0, 1:[204x1], 128][D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]][Tile0, 1:[204x1], 128]
		Tile0: [0, 26112, 26112], Tile1: [0, 26112, 26112], Tile2; [0, 26112, 26112]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 67968 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+3456);
	KerArg2->ColBuff = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (FRF_multiclass_CNN_L1_Memory+17280);
	KerArg2->Bias = (int * __restrict__) (FRF_multiclass_CNN_L1_Memory+16512);
	KerArg2->Out = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+41856);
	KerArg2->Scale = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+17024);
	KerArg2->ScaleN = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+17152);
	KerArg2->Tile_InFeat = (unsigned short int) (64);
	KerArg2->TotalInFeatures = (unsigned short int) (64);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (204);
	KerArg2->Tile_OutFeat = (unsigned short int) (128);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (204);
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
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+17280), 24576, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+3456), 13056, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+16512), 512, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+17024), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+17152), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+67968), 20, 0, 0);
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
				KerArg2->W_Offset = (int) (((int *)(FRF_multiclass_CNN_L1_Memory+67968))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+41856), 26112, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S19__conv6_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 114708 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;
	Ker_MM_Pool_USQ8_T S_KerArg3, *KerArg3 = &S_KerArg3;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last, D1Ind_NextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _N_In;
	unsigned int _SN_In;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 128, Tiled: 1][Tile0 Dim: 4][D0 Dim: Init: 128, Tiled: 1]
	Ker Arg: Out, Tiled Space: D1
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 4 logical tiles, 4 physical tiles
			@ 106496 (Total Size: 13056 )[Tile0, 4:[1x32, 2:1x32, 1x6], 128][D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]][Tile0, 4:[1x32], 128]
		Tile0: [0, 4096, 4096], Tile1: [4096, 4096, 4096], Tile2; [8192, 4096, 4096]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 4 logical tiles, 4 physical tiles
			@ 6912 (Total Size: 26112 )[Tile0, 4:[1x65, 2:1x66, 1x13], 128][D0, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 4:[1x65, 2:1x66, 1x13], 128][D0, [0 x 128, 128]]
		Tile0: [0, 8320, 8320], Tile1: [8064, 8448, 8448], Tile2; [16256, 8448, 8448]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 23808 (Total Size: 512 )[D1, [0 x 512, 512]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 512, 512]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 24320 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 24448 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 24576 (Total Size: 49152 )[D1, [0 x 49152, 49152]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 49152, 49152]]
		Tile0: [0, 49152, 49152], Tile1: [0, 49152, 49152], Tile2; [0, 49152, 49152]
	Ker Arg: ConvOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 4 logical tiles, 1 physical tiles
			@ 73728 (Total Size: 104448 )[Tile0, 4:[1x64, 2:1x64, 1x12], 512][D1, [0 x 512, 512]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 512, 512]][Tile0, 4:[1x64], 512]
		Tile0: [0, 32768, 32768], Tile1: [0, 32768, 32768], Tile2; [0, 32768, 32768]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 4 logical tiles, 1 physical tiles
			@ 0 (Total Size: 6912 )[Tile0, 4:[1x6912, 2:1x6912, 1x6912], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 4:[1x6912, 2:1x6912, 1x6912], 1]
		Tile0: [0, 6912, 6912], Tile1: [0, 6912, 6912], Tile2; [0, 6912, 6912]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 4 logical tiles, 1 physical tiles
			@ 114688 (Total Size: 20 )[Tile0, 4:[1x20, 2:1x20, 1x20], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 4:[1x20, 2:1x20, 1x20], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->ColBuff = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (FRF_multiclass_CNN_L1_Memory+24576);
	KerArg2->Bias = (int * __restrict__) (FRF_multiclass_CNN_L1_Memory+23808);
	KerArg2->Out = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+73728);
	KerArg2->Scale = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+24320);
	KerArg2->ScaleN = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+24448);
	KerArg2->Tile_InFeat = (unsigned short int) (128);
	KerArg2->TotalInFeatures = (unsigned short int) (128);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_OutFeat = (unsigned short int) (128);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Pad_Val = (unsigned short int) (0);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (3);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (1);
	KerArg3->In = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+73728);
	KerArg3->H = (unsigned short int) (1);
	KerArg3->Fx = (unsigned short int) (2);
	KerArg3->Fy = (unsigned short int) (1);
	KerArg3->Sx = (unsigned char) (2);
	KerArg3->Sy = (unsigned char) (1);
	KerArg3->Pad = (v4s) 0;
	KerArg3->Feat = (unsigned short int) (128);
	KerArg3->Ho = (unsigned short int) (1);
	KerArg3->Infos = (signed char * __restrict__) (FRF_multiclass_CNN_L1_Memory+114688);
	KerArg3->Extra = (void *) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+6912+0), 8320, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=4096;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+24576), 49152, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+23808), 512, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+24320), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+24448), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+114688), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1, D1Ind_NextLast = 1;
		for (T0Ind=0; T0Ind<4; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==3), T0Ind_NextLast = ((T0Ind+1)==3);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (8192-(128*(T0Ind==0))); _SN_In = (((T0Ind_NextLast)?14:66)*(128)); 
			} else if (!(1)) {
				_N_In = _N_In + (-24448); _SN_In = (66*(128)); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+6912+8448*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->In = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+6912+8448*((T0Ind_Total)%2));
				KerArg2->Tile_InW = (unsigned short int) (((T0Ind_Last)?13:66)-1*(T0Ind==0));
				KerArg2->Tile_OutW = (unsigned short int) ((T0Ind_Last)?12:64);
				KerArg2->Pad = (v4s) ((v4s){1*(T0Ind==0),1*(T0Ind_Last),0,0});
				KerArg2->FirstTile = (unsigned char) ((T0Ind==0));
				KerArg2->W_Offset = (int) (((int *)(FRF_multiclass_CNN_L1_Memory+114688))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
			/*====================== Call Kernel LOC_D0_EPILOG =========================*/
			KerArg3->W = (unsigned short int) ((T0Ind_Last)?12:64);
			KerArg3->FirstTile = (unsigned char) ((T0Ind==0));
			KerArg3->Out = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+106496+4096*((T0Ind_Total)%2));
			KerArg3->Wo = (unsigned short int) ((T0Ind_Last)?6:32);
			AT_FORK(gap_ncore(), (void *) KerParMaxPoolNxMStrideSxSy_HWC_USQ8, (void *) KerArg3);
			__CALL(KerParMaxPoolNxMStrideSxSy_HWC_USQ8, KerArg3);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+106496+4096*((T0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (4096); _SC_Out = (((T0Ind_NextLast)?6:32)*(128)); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S22__conv7_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 83732 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _LP_Out, _LC_Out;
	unsigned int _N_Filter;
	unsigned int _SN_Filter;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 256, Tiled: 4][Tile0 Dim: 1][D0 Dim: Init: 128, Tiled: 1]
	Ker Arg: Out, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 4 logical tiles, 4 physical tiles
			@ 70656 (Total Size: 26112 )[Tile0, 1:[102x1], 256][D1, [3 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [3 x 64, 64]][Tile0, 1:[102x1, 2:102x1, 102x1], 256]
		Tile0: [0, 6528, 64], Tile1: [64, 6528, 64], Tile2; [128, 6528, 64]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6912 (Total Size: 13056 )[Tile0, 1:[102x1], 128][D0, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[102x1], 128][D0, [0 x 128, 128]]
		Tile0: [0, 13056, 13056], Tile1: [0, 13056, 13056], Tile2; [0, 13056, 13056]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 4 logical tiles, 1 physical tiles
			@ 19968 (Total Size: 1024 )[D1, [3 x 256, 256]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [3 x 256, 256]]
		Tile0: [0, 1024, 1024], Tile1: [0, 1024, 1024], Tile2; [0, 1024, 1024]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 4 logical tiles, 1 physical tiles
			@ 20992 (Total Size: 256 )[D1, [3 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [3 x 64, 64]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 4 logical tiles, 1 physical tiles
			@ 21248 (Total Size: 256 )[D1, [3 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [3 x 64, 64]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Filter, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 4 logical tiles, 4 physical tiles
			@ 21504 (Total Size: 98304 )[D1, [3 x 24576, 24576]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [3 x 24576, 24576]]
		Tile0: [0, 24576, 24576], Tile1: [24576, 24576, 24576], Tile2; [49152, 24576, 24576]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 6912 )[Tile0, 1:[6912x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[6912x1], 1]
		Tile0: [0, 6912, 6912], Tile1: [0, 6912, 6912], Tile2; [0, 6912, 6912]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 83712 (Total Size: 20 )[Tile0, 1:[20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+6912);
	KerArg2->ColBuff = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+0);
	KerArg2->Tile_InFeat = (unsigned short int) (128);
	KerArg2->TotalInFeatures = (unsigned short int) (128);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_InW = (unsigned short int) (102);
	KerArg2->Tile_OutFeat = (unsigned short int) (64);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (102);
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
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+21504+0), 24576, 0, DmaR_Evt1);
	_N_Filter=0;
	_C_Out=0; _SC_Out=6528; _LC_Out=64;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+6912), 13056, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+19968), 1024, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+20992), 256, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+21248), 256, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+83712), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	for (D1Ind=0; D1Ind<4; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
		int D1Ind_Last = (D1Ind==3), D1Ind_NextLast = ((D1Ind+1)==3);
		/*================================= Prepare Tiles ===================================*/
		_SN_Filter = 0;
		if (!(D1Ind_Last)) {
			_N_Filter = _N_Filter + (24576); _SN_Filter = (24576); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Filter */
		if (_SN_Filter) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+_N_Filter), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+21504+24576*((D1Ind_Total+1)%2)),
					1*(_SN_Filter), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->Filter = (unsigned short * __restrict__) (FRF_multiclass_CNN_L1_Memory+21504+24576*((D1Ind_Total)%2));
				KerArg2->Bias = (int * __restrict__) (FRF_multiclass_CNN_L1_Memory+19968+((D1Ind)*256));
				KerArg2->Out = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+70656+6528*((D1Ind_Total)%2));
				KerArg2->Scale = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+20992+((D1Ind)*64));
				KerArg2->ScaleN = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+21248+((D1Ind)*64));
				KerArg2->W_Offset = (int) (((int *)(FRF_multiclass_CNN_L1_Memory+83712))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on Tile0 */
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+70656+6528*((D1Ind_Total)%2)),
				_SC_Out, 256, _LC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_Out = _SC_Out;_LP_Out = _LC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(D1Ind_Last)) {
			_C_Out = _C_Out + (64); _LC_Out = (64); _SC_Out = (102*_LC_Out); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S25__conv8_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		signed char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115604 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaR_Evt3, *DmaR_Evt3 = &_DmaR_Evt3;
	AT_L2_EVENT _DmaR_Evt4, *DmaR_Evt4 = &_DmaR_Evt4;
	AT_L2_EVENT _DmaR_Evt5, *DmaR_Evt5 = &_DmaR_Evt5;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt6, *DmaR_Evt6 = &_DmaR_Evt6;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;
	Ker_MM_Pool_SQ8_T S_KerArg3, *KerArg3 = &S_KerArg3;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _N_Bias;
	unsigned int _SN_Bias;
	unsigned int _N_Scale;
	unsigned int _SN_Scale;
	unsigned int _N_ScaleN;
	unsigned int _SN_ScaleN;
	unsigned int _N_Filter;
	unsigned int _SN_Filter;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 256, Tiled: 4][Tile0 Dim: 51][D0 Dim: Init: 256, Tiled: 1]
	Ker Arg: Out, Tiled Space: D1
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 204 logical tiles, 204 physical tiles
			@ 115456 (Total Size: 13056 )[Tile0, 51:[1x1, 49:1x1, 1x1], 256][D1, [3 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [3 x 64, 64]][Tile0, 51:[1x1, 2:1x1, 1x1], 256]
		Tile0: [0, 64, 64], Tile1: [256, 64, 64], Tile2; [512, 64, 64]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 51 logical tiles, 51 physical tiles
			@ 13824 (Total Size: 26112 )[Tile0, 51:[1x3, 49:1x4, 1x3], 256][D0, [0 x 256, 256]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 51:[1x3, 49:1x4, 1x3], 256][D0, [0 x 256, 256]]
		Tile0: [0, 768, 768], Tile1: [256, 1024, 1024], Tile2; [768, 1024, 1024]
	Ker Arg: Bias, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 4 logical tiles, 4 physical tiles
			@ 15872 (Total Size: 1024 )[D1, [3 x 256, 256]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [3 x 256, 256]]
		Tile0: [0, 256, 256], Tile1: [256, 256, 256], Tile2; [512, 256, 256]
	Ker Arg: Scale, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 4 logical tiles, 4 physical tiles
			@ 16384 (Total Size: 256 )[D1, [3 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [3 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [64, 64, 64], Tile2; [128, 64, 64]
	Ker Arg: ScaleN, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 4 logical tiles, 4 physical tiles
			@ 16512 (Total Size: 256 )[D1, [3 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [3 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [64, 64, 64], Tile2; [128, 64, 64]
	Ker Arg: Filter, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 4 logical tiles, 4 physical tiles
			@ 16640 (Total Size: 196608 )[D1, [3 x 49152, 49152]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [3 x 49152, 49152]]
		Tile0: [0, 49152, 49152], Tile1: [49152, 49152, 49152], Tile2; [98304, 49152, 49152]
	Ker Arg: ConvOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 204 logical tiles, 1 physical tiles
			@ 114944 (Total Size: 104448 )[Tile0, 51:[1x2, 49:1x2, 1x2], 1024][D1, [3 x 256, 256]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [3 x 256, 256]][Tile0, 51:[1x2, 2:1x2, 1x2], 1024]
		Tile0: [0, 512, 256], Tile1: [0, 512, 256], Tile2; [0, 512, 256]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 51 logical tiles, 1 physical tiles
			@ 0 (Total Size: 13824 )[Tile0, 51:[1x13824, 49:1x13824, 1x13824], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 51:[1x13824, 49:1x13824, 1x13824], 1]
		Tile0: [0, 13824, 13824], Tile1: [0, 13824, 13824], Tile2; [0, 13824, 13824]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 51 logical tiles, 1 physical tiles
			@ 115584 (Total Size: 20 )[Tile0, 51:[1x20, 49:1x20, 1x20], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 51:[1x20, 49:1x20, 1x20], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->ColBuff = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+0);
	KerArg2->Out = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+114944);
	KerArg2->Tile_InFeat = (unsigned short int) (256);
	KerArg2->TotalInFeatures = (unsigned short int) (256);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_OutFeat = (unsigned short int) (64);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (2);
	KerArg2->Pad_Val = (unsigned short int) (0);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (3);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (1);
	KerArg3->In = (signed char * __restrict__) (FRF_multiclass_CNN_L1_Memory+114944);
	KerArg3->W = (unsigned short int) (2);
	KerArg3->H = (unsigned short int) (1);
	KerArg3->Fx = (unsigned short int) (2);
	KerArg3->Fy = (unsigned short int) (1);
	KerArg3->Sx = (unsigned char) (2);
	KerArg3->Sy = (unsigned char) (1);
	KerArg3->Pad = (v4s) 0;
	KerArg3->Feat = (unsigned short int) (64);
	KerArg3->Wo = (unsigned short int) (1);
	KerArg3->Ho = (unsigned short int) (1);
	KerArg3->Infos = (signed char * __restrict__) (FRF_multiclass_CNN_L1_Memory+115584);
	KerArg3->Extra = (void *) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+16640+0), 49152, 0, DmaR_Evt1);
	_N_Filter=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+13824+0), 768, 0, DmaR_Evt2);
	_N_In=0;
	_C_Out=0; _SC_Out=64;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+15872+0), 256, 0, DmaR_Evt3);
	_N_Bias=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+16384+0), 64, 0, DmaR_Evt4);
	_N_Scale=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+16512+0), 64, 0, DmaR_Evt5);
	_N_ScaleN=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+115584), 20, 0, DmaR_Evt6);
	AT_L2_WAIT(0, DmaR_Evt6); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	for (D1Ind=0; D1Ind<4; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
		int D1Ind_Last = (D1Ind==3), D1Ind_NextLast = ((D1Ind+1)==3);
		/*================================= Prepare Tiles ===================================*/
		_SN_Bias = 0;
		if (!(D1Ind_Last)) {
			_N_Bias = _N_Bias + (256); _SN_Bias = (256); 
		}
		_SN_Scale = 0;
		if (!(D1Ind_Last)) {
			_N_Scale = _N_Scale + (64); _SN_Scale = (64); 
		}
		_SN_ScaleN = 0;
		if (!(D1Ind_Last)) {
			_N_ScaleN = _N_ScaleN + (64); _SN_ScaleN = (64); 
		}
		_SN_Filter = 0;
		if (!(D1Ind_Last)) {
			_N_Filter = _N_Filter + (49152); _SN_Filter = (49152); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt3); /* Wait previous DMA read Bias */
		if (_SN_Bias) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Bias+_N_Bias), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+15872+256*((D1Ind_Total+1)%2)),
					1*(_SN_Bias), 0, DmaR_Evt3);
		}
		AT_L2_WAIT(0, DmaR_Evt4); /* Wait previous DMA read Scale */
		if (_SN_Scale) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Scale+_N_Scale), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+16384+64*((D1Ind_Total+1)%2)),
					1*(_SN_Scale), 0, DmaR_Evt4);
		}
		AT_L2_WAIT(0, DmaR_Evt5); /* Wait previous DMA read ScaleN */
		if (_SN_ScaleN) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+_N_ScaleN), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+16512+64*((D1Ind_Total+1)%2)),
					1*(_SN_ScaleN), 0, DmaR_Evt5);
		}
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Filter */
		if (_SN_Filter) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+_N_Filter), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+16640+49152*((D1Ind_Total+1)%2)),
					1*(_SN_Filter), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		for (T0Ind=0; T0Ind<51; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==50), T0Ind_NextLast = ((T0Ind+1)==50);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (512-(256*(T0Ind==0))); _SN_In = (4*(256)); 
			} else if (!(D1Ind_Last)) {
				_N_In = _N_In + (-25344); _SN_In = (4*(256)); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+13824+1024*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt2);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->In = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+13824+1024*((T0Ind_Total)%2));
				KerArg2->Filter = (unsigned short * __restrict__) (FRF_multiclass_CNN_L1_Memory+16640+49152*((D1Ind_Total)%2));
				KerArg2->Bias = (int * __restrict__) (FRF_multiclass_CNN_L1_Memory+15872+256*((D1Ind_Total)%2));
				KerArg2->Scale = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+16384+64*((D1Ind_Total)%2));
				KerArg2->ScaleN = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+16512+64*((D1Ind_Total)%2));
				KerArg2->Tile_InW = (unsigned short int) (4-1*(T0Ind==0)-1*(T0Ind_Last));
				KerArg2->Pad = (v4s) ((v4s){1*(T0Ind==0),1*(T0Ind_Last),0,0});
				KerArg2->FirstTile = (unsigned char) ((T0Ind==0));
				KerArg2->W_Offset = (int) (((int *)(FRF_multiclass_CNN_L1_Memory+115584))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
			/*====================== Call Kernel LOC_D0_EPILOG =========================*/
			KerArg3->FirstTile = (unsigned char) ((T0Ind==0));
			KerArg3->Out = (signed char * __restrict__) (FRF_multiclass_CNN_L1_Memory+115456+64*((T0Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) KerParMaxPoolNxMStrideSxSy_HWC_ReLU_SQ8, (void *) KerArg3);
			__CALL(KerParMaxPoolNxMStrideSxSy_HWC_ReLU_SQ8, KerArg3);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+115456+64*((T0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (256); _SC_Out = (1*(64)); 
			} else if (!(D1Ind_Last)) {
				_C_Out = _C_Out + (64)+(-12800); _SC_Out = (1*(64)); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
		/*================================= Update Arg Pipeline =============================*/
		/*============================= End Update Arg Pipeline =============================*/
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S26__global_avg_pool_GlobalAveragePool_trans(
		signed char * __restrict__ In,
		signed char * __restrict__ Out)

{
	/* Shared L1: 26112 bytes, L2 buffer: 0 bytes */
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
			@ 0 (Total Size: 13056 )[D0, [0 x 13056, 13056]][Tile0, 1:[256x51], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 13056, 13056]][Tile0, 1:[256x51], 1]
		Tile0: [0, 13056, 13056], Tile1: [0, 13056, 13056], Tile2; [0, 13056, 13056]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 13056 (Total Size: 13056 )[D0, [0 x 13056, 13056]][Tile0, 1:[256x51], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 13056, 13056]][Tile0, 1:[256x51], 1]
		Tile0: [0, 13056, 13056], Tile1: [0, 13056, 13056], Tile2; [0, 13056, 13056]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (void *__restrict__) (FRF_multiclass_CNN_L1_Memory+0);
	KerArg0->Out = (void *__restrict__) (FRF_multiclass_CNN_L1_Memory+13056);
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (256);
	KerArg0->H = (unsigned short int) (51);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+0), 13056, 0, DmaR_Evt1);
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
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+13056), 13056, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S27__global_avg_pool_GlobalAveragePool(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 13328 bytes, L2 buffer: 0 bytes */
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
			@ 0 (Total Size: 13056 )[Tile0, 1:[51x256], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[51x256], 1]
		Tile0: [0, 13056, 13056], Tile1: [0, 13056, 13056], Tile2; [0, 13056, 13056]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 13056 (Total Size: 256 )[Tile0, 1:[1x256], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x256], 1]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 13312 (Total Size: 13 )[Tile0, 1:[13x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[13x1], 1]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (void * __restrict__) (FRF_multiclass_CNN_L1_Memory+0);
	KerArg0->W = (unsigned short int) (17);
	KerArg0->H = (unsigned short int) (3);
	KerArg0->Feat = (unsigned short int) (256);
	KerArg0->Out = (int * __restrict__) (FRF_multiclass_CNN_L1_Memory+13056);
	KerArg0->DoScale = (unsigned char) (1);
	KerArg0->Infos = (void * __restrict__) (FRF_multiclass_CNN_L1_Memory+13312);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+0), 13056, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+13312), 13, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		/*====================== Call Kernel LOC_LOOP =========================*/
		AT_FORK(gap_ncore(), (void *) KerParGlobalAvgPoolFullFeat_SQ8, (void *) KerArg0);
		__CALL(KerParGlobalAvgPoolFullFeat_SQ8, KerArg0);
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+13056), 256, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S28__global_avg_pool_GlobalAveragePool_qout0(
		signed char * __restrict__ In,
		unsigned char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 520 bytes, L2 buffer: 0 bytes */
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
		[Tile0 Dim: 1][D0 Dim: Init: 256, Tiled: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 256 )[D0, [0 x 256, 256]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 256, 256]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 256 (Total Size: 256 )[D0, [0 x 256, 256]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 256, 256]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 512 (Total Size: 8 )[Tile0, 1:[1x1], 8]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 8]
		Tile0: [0, 8, 8], Tile1: [0, 8, 8], Tile2; [0, 8, 8]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (signed char *__restrict__) (FRF_multiclass_CNN_L1_Memory+0);
	KerArg0->Out = (unsigned char *__restrict__) (FRF_multiclass_CNN_L1_Memory+256);
	KerArg0->W = (unsigned short int) (256);
	KerArg0->H = (unsigned short int) (1);
	KerArg0->Infos = (signed char *__restrict__) (FRF_multiclass_CNN_L1_Memory+512);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+0), 256, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+512), 8, 0, 0);
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
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+256), 256, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S31__fc_Gemm(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		signed char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 2912 bytes, L2 buffer: 0 bytes */
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
		[Tile0 Dim: 1][D1 Dim: Init: 10, Tiled: 1][D0 Dim: Init: 256, Tiled: 1]
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
			@ 256 (Total Size: 2560 )[D1, [0 x 2560, 2560]][D0, [0 x 2560, 2560]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2560, 2560]][D0, [0 x 2560, 2560]]
		Tile0: [0, 2560, 2560], Tile1: [0, 2560, 2560], Tile2; [0, 2560, 2560]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2816 (Total Size: 40 )[D1, [0 x 40, 40]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 40, 40]]
		Tile0: [0, 40, 40], Tile1: [0, 40, 40], Tile2; [0, 40, 40]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2856 (Total Size: 10 )[D1, [0 x 10, 10]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 10, 10]]
		Tile0: [0, 10, 10], Tile1: [0, 10, 10], Tile2; [0, 10, 10]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2868 (Total Size: 10 )[D1, [0 x 10, 10]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 10, 10]]
		Tile0: [0, 10, 10], Tile1: [0, 10, 10], Tile2; [0, 10, 10]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2880 (Total Size: 10 )[D1, [0 x 10, 10]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 10, 10]]
		Tile0: [0, 10, 10], Tile1: [0, 10, 10], Tile2; [0, 10, 10]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2892 (Total Size: 20 )[Tile0, 1:[1x1], 20]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 20]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (signed char * __restrict__) (FRF_multiclass_CNN_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (FRF_multiclass_CNN_L1_Memory+256);
	KerArg2->Bias = (int * __restrict__) (FRF_multiclass_CNN_L1_Memory+2816);
	KerArg2->Out = (int * __restrict__) (FRF_multiclass_CNN_L1_Memory+2856);
	KerArg2->Scale = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+2868);
	KerArg2->ScaleN = (unsigned char * __restrict__) (FRF_multiclass_CNN_L1_Memory+2880);
	KerArg2->Tile_InFeat = (unsigned short int) (256);
	KerArg2->Tile_OutFeat = (unsigned short int) (10);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (58753271);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+256), 2560, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+0), 256, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+2816), 40, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+2892), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+2868), 10, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+2880), 10, 0, 0);
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
				KerArg2->W_Offset = (int) (((int *)(FRF_multiclass_CNN_L1_Memory+2892))[4]);
				KerLinear_8a_NE16(KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on D1 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+2856), 10, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
	/*====================== Call Kernel LOC_EPILOG =========================*/
	NE16_Disable(
	);
}
void  S33__Softmax(
		signed char * __restrict__ In,
		short int * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 48 bytes, L2 buffer: 0 bytes */
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
			@ 0 (Total Size: 10 )[Tile0, 1:[10x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[10x1], 1]
		Tile0: [0, 10, 10], Tile1: [0, 10, 10], Tile2; [0, 10, 10]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 12 (Total Size: 13 )[Tile0, 1:[13x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[13x1], 1]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 28 (Total Size: 20 )[Tile0, 1:[10x1], 2]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[10x1], 2]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (signed char *__restrict__) (FRF_multiclass_CNN_L1_Memory+0);
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->N = (unsigned short int) (10);
	KerArg0->Out = (short int *__restrict__) (FRF_multiclass_CNN_L1_Memory+28);
	KerArg0->Infos = (signed char *__restrict__) (FRF_multiclass_CNN_L1_Memory+12);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+12), 13, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+0), 10, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->Norm = (unsigned short int) (((char *)(FRF_multiclass_CNN_L1_Memory+12))[0]);
		AT_FORK(gap_ncore(), (void *) KerParSoftMax_SQ8, (void *) KerArg0);
		__CALL(KerParSoftMax_SQ8, KerArg0);
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) FRF_multiclass_CNN_L1_Memory+28), 20, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
#pragma GCC diagnostic pop
int  FRF_multiclass_CNNCNN_Construct()

{
	int Error;

	AT_DEFAULTFLASH_FS_CONF_T DefaultFlashConf;
	AT_DEFAULTFLASH_FS_CONF_INIT(&DefaultFlashConf, AT_MEM_L3_DEFAULTFLASH, 0);
	AT_DEFAULTFLASH_FS_OPEN(&DefaultFlash, &DefaultFlashConf, 0, "FRF_multiclass_CNN_L3_Flash_Const.dat", &Error);
	if (Error) return AT_FLASH_OPEN_ERROR;

	FRF_multiclass_CNN_L2_Memory = (AT_L2_POINTER) AT_L2_ALLOC(0, 387964);
	if (FRF_multiclass_CNN_L2_Memory == 0) return AT_L2_OPEN_ERROR;
	FRF_multiclass_CNN_L2_Memory_Dyn = (AT_L2_POINTER) AT_L2_ALLOC(0, 52256);
	if (FRF_multiclass_CNN_L2_Memory_Dyn == 0) return AT_L2_OPEN_ERROR;
	FRF_multiclass_CNN_L1_Memory = (AT_L1_POINTER) AT_L1_ALLOC(0, 115604);
	if (FRF_multiclass_CNN_L1_Memory == 0) return AT_L1_OPEN_ERROR;
	AT_DEFAULTFLASH_FS_FC_EVENT _UchanHF1, *UchanHF1 = &_UchanHF1;
	/* Static Moving _conv1_conv_weights, size 256 from DefaultFlash at 385024 to (size 256) L2 at 385024..385279 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 385024), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 385024), 256, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__conv_101, size 64 from DefaultFlash at 387328 to (size 64) L2 at 387328..387391 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387328), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387328), 64, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S4_Mul_scale, size 16 from DefaultFlash at 387868 to (size 16) L2 at 387868..387883 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387868), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387868), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S4_Mul_shift, size 16 from DefaultFlash at 387884 to (size 16) L2 at 387884..387899 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387884), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387884), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S4_Infos, size 20 from DefaultFlash at 387688 to (size 20) L2 at 387688..387707 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387688), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387688), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _conv2_conv_weights, size 1536 from DefaultFlash at 380416 to (size 1536) L2 at 380416..381951 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 380416), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 380416), 1536, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__conv_104, size 128 from DefaultFlash at 386560 to (size 128) L2 at 386560..386687 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 386560), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 386560), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S7_Mul_scale, size 32 from DefaultFlash at 387560 to (size 32) L2 at 387560..387591 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387560), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387560), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S7_Mul_shift, size 32 from DefaultFlash at 387592 to (size 32) L2 at 387592..387623 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387592), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387592), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S7_Infos, size 20 from DefaultFlash at 387708 to (size 20) L2 at 387708..387727 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387708), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387708), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _conv3_conv_weights, size 3072 from DefaultFlash at 374784 to (size 3072) L2 at 374784..377855 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 374784), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 374784), 3072, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__conv_107, size 128 from DefaultFlash at 386688 to (size 128) L2 at 386688..386815 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 386688), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 386688), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S10_Mul_scale, size 32 from DefaultFlash at 387624 to (size 32) L2 at 387624..387655 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387624), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387624), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S10_Mul_shift, size 32 from DefaultFlash at 387656 to (size 32) L2 at 387656..387687 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387656), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387656), 32, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S10_Infos, size 20 from DefaultFlash at 387728 to (size 20) L2 at 387728..387747 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387728), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387728), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _conv4_conv_weights, size 6144 from DefaultFlash at 368640 to (size 6144) L2 at 368640..374783 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 368640), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 368640), 6144, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__conv_110, size 256 from DefaultFlash at 385280 to (size 256) L2 at 385280..385535 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 385280), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 385280), 256, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S13_Mul_scale, size 64 from DefaultFlash at 387392 to (size 64) L2 at 387392..387455 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387392), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387392), 64, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S13_Mul_shift, size 64 from DefaultFlash at 387456 to (size 64) L2 at 387456..387519 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387456), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387456), 64, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S13_Infos, size 20 from DefaultFlash at 387748 to (size 20) L2 at 387748..387767 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387748), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387748), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _conv5_conv_weights, size 24576 from DefaultFlash at 344064 to (size 24576) L2 at 344064..368639 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 344064), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 344064), 24576, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__conv_113, size 512 from DefaultFlash at 384000 to (size 512) L2 at 384000..384511 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 384000), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 384000), 512, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S16_Mul_scale, size 128 from DefaultFlash at 386816 to (size 128) L2 at 386816..386943 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 386816), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 386816), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S16_Mul_shift, size 128 from DefaultFlash at 386944 to (size 128) L2 at 386944..387071 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 386944), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 386944), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S16_Infos, size 20 from DefaultFlash at 387768 to (size 20) L2 at 387768..387787 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387768), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387768), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _conv6_conv_weights, size 49152 from DefaultFlash at 294912 to (size 49152) L2 at 294912..344063 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 294912), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 294912), 49152, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__conv_116, size 512 from DefaultFlash at 384512 to (size 512) L2 at 384512..385023 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 384512), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 384512), 512, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S19_Mul_scale, size 128 from DefaultFlash at 387072 to (size 128) L2 at 387072..387199 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387072), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387072), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S19_Mul_shift, size 128 from DefaultFlash at 387200 to (size 128) L2 at 387200..387327 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387200), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387200), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S19_Infos, size 20 from DefaultFlash at 387788 to (size 20) L2 at 387788..387807 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387788), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387788), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _conv7_conv_weights, size 98304 from DefaultFlash at 196608 to (size 98304) L2 at 196608..294911 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 196608), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 196608), 98304, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__conv_119, size 1024 from DefaultFlash at 381952 to (size 1024) L2 at 381952..382975 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 381952), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 381952), 1024, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S22_Mul_scale, size 256 from DefaultFlash at 385536 to (size 256) L2 at 385536..385791 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 385536), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 385536), 256, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S22_Mul_shift, size 256 from DefaultFlash at 385792 to (size 256) L2 at 385792..386047 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 385792), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 385792), 256, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S22_Infos, size 20 from DefaultFlash at 387808 to (size 20) L2 at 387808..387827 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387808), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387808), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _conv8_conv_weights, size 196608 from DefaultFlash at 0 to (size 196608) L2 at 0..196607 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 0), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 0), 196608, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__conv_122, size 1024 from DefaultFlash at 382976 to (size 1024) L2 at 382976..383999 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 382976), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 382976), 1024, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S25_Mul_scale, size 256 from DefaultFlash at 386048 to (size 256) L2 at 386048..386303 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 386048), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 386048), 256, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S25_Mul_shift, size 256 from DefaultFlash at 386304 to (size 256) L2 at 386304..386559 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 386304), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 386304), 256, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S25_Infos, size 20 from DefaultFlash at 387828 to (size 20) L2 at 387828..387847 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387828), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387828), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S27_Infos, size 13 from DefaultFlash at 387900 to (size 13) L2 at 387900..387912 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387900), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387900), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S28_Infos, size 8 from DefaultFlash at 387956 to (size 8) L2 at 387956..387963 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387956), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387956), 8, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _fc_gemm_weights, size 2560 from DefaultFlash at 377856 to (size 2560) L2 at 377856..380415 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 377856), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 377856), 2560, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _fc_gemm_biases, size 40 from DefaultFlash at 387520 to (size 40) L2 at 387520..387559 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387520), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387520), 40, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S31_Mul_scale, size 10 from DefaultFlash at 387932 to (size 10) L2 at 387932..387941 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387932), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387932), 10, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S31_Mul_shift, size 10 from DefaultFlash at 387944 to (size 10) L2 at 387944..387953 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387944), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387944), 10, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S31_Infos, size 20 from DefaultFlash at 387848 to (size 20) L2 at 387848..387867 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387848), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387848), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S33_Infos, size 13 from DefaultFlash at 387916 to (size 13) L2 at 387916..387928 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) FRF_multiclass_CNN_L3_Flash + 387916), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) FRF_multiclass_CNN_L2_Memory + 387916), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	return AT_NO_ERROR;
}
void FRF_multiclass_CNNCNN_ConstructCluster()

{
}
int  FRF_multiclass_CNNCNN_Destruct()

{
	AT_L2_FREE(0, FRF_multiclass_CNN_L2_Memory_Dyn, 52256);
	AT_L2_FREE(0, FRF_multiclass_CNN_L2_Memory, 387964);
	AT_L1_FREE(0, FRF_multiclass_CNN_L1_Memory, 115604);
	AT_DEFAULTFLASH_FS_CLOSE(&DefaultFlash);
	return 0;
}
int FRF_multiclass_CNNCNN_Memory(AT_MEM_TYPE Which)

{
	switch (Which) {
		case AT_L1_MEM:     return 115604; /* L1 Memory */
		case AT_L2_MEM:     return 387964; /* L2 Memory, permanent */
		case AT_L2_DYN_MEM: return 52256; /* L2 Memory, dynamic */
		case AT_L3_MEM:     return 0; /* L3 Memory, permanent */
		case AT_L3_DYN_MEM: return 0; /* L3 Memory, dynamic */
		default:            return 0;
	}
}
unsigned int AT_GraphPerf[14];
unsigned int AT_GraphPerf_CNN_Total = 0;
unsigned int AT_GraphOperInfosNames[14] = {
	39312,
	1284160,
	1256448,
	2539008,
	5013504,
	10053120,
	10027008,
	20093184,
	13056,
	13056,
	256,
	2560,
	10,
	0,
};
char *AT_GraphNodeNames[14] = {
	"S4__conv1_Conv_fusion",
	"S7__conv2_Conv_fusion",
	"S10__conv3_Conv_fusion",
	"S13__conv4_Conv_fusion",
	"S16__conv5_Conv_fusion",
	"S19__conv6_Conv_fusion",
	"S22__conv7_Conv_fusion",
	"S25__conv8_Conv_fusion",
	"S26__global_avg_pool_GlobalAveragePool_trans",
	"S27__global_avg_pool_GlobalAveragePool",
	"S28__global_avg_pool_GlobalAveragePool_qout0",
	"S31__fc_Gemm",
	"S33__Softmax",
	"IO_Wait",
};
int  FRF_multiclass_CNNCNN(
		unsigned char * __restrict__ Input_1,
		signed short * __restrict__ Output_1)

{
	unsigned int Start_IO;
	AT_GraphPerf_CNN_Total = gap_cl_readhwtimer();
	AT_GraphPerf[0] = gap_cl_readhwtimer();
	AT_GraphPerf[13] = 0;
	S4__conv1_Conv_fusion(
		((unsigned char * __restrict__) Input_1), /* In */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory+385024)), /* Filter */
		((signed int * __restrict__) (FRF_multiclass_CNN_L2_Memory+387328)), /* Bias */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory_Dyn+13088)), /* Out */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory+387868)), /* Scale */
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory+387884)), /* ScaleN */
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory+387688)) /* Infos */
	);
	AT_GraphPerf[0] = gap_cl_readhwtimer() - AT_GraphPerf[0];
	AT_GraphPerf[1] = gap_cl_readhwtimer();
	S7__conv2_Conv_fusion(
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory_Dyn+13088)), /* In */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory+380416)), /* Filter */
		((signed int * __restrict__) (FRF_multiclass_CNN_L2_Memory+386560)), /* Bias */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory+387560)), /* Scale */
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory+387592)), /* ScaleN */
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory+387708)) /* Infos */
	);
	AT_GraphPerf[1] = gap_cl_readhwtimer() - AT_GraphPerf[1];
	AT_GraphPerf[2] = gap_cl_readhwtimer();
	S10__conv3_Conv_fusion(
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory+374784)), /* Filter */
		((signed int * __restrict__) (FRF_multiclass_CNN_L2_Memory+386688)), /* Bias */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory_Dyn+39168)), /* Out */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory+387624)), /* Scale */
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory+387656)), /* ScaleN */
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory+387728)) /* Infos */
	);
	AT_GraphPerf[2] = gap_cl_readhwtimer() - AT_GraphPerf[2];
	AT_GraphPerf[3] = gap_cl_readhwtimer();
	S13__conv4_Conv_fusion(
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory_Dyn+39168)), /* In */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory+368640)), /* Filter */
		((signed int * __restrict__) (FRF_multiclass_CNN_L2_Memory+385280)), /* Bias */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory_Dyn+26112)), /* Out */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory+387392)), /* Scale */
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory+387456)), /* ScaleN */
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory+387748)) /* Infos */
	);
	AT_GraphPerf[3] = gap_cl_readhwtimer() - AT_GraphPerf[3];
	AT_GraphPerf[4] = gap_cl_readhwtimer();
	S16__conv5_Conv_fusion(
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory_Dyn+26112)), /* In */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory+344064)), /* Filter */
		((signed int * __restrict__) (FRF_multiclass_CNN_L2_Memory+384000)), /* Bias */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory+386816)), /* Scale */
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory+386944)), /* ScaleN */
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory+387768)) /* Infos */
	);
	AT_GraphPerf[4] = gap_cl_readhwtimer() - AT_GraphPerf[4];
	AT_GraphPerf[5] = gap_cl_readhwtimer();
	S19__conv6_Conv_fusion(
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory+294912)), /* Filter */
		((signed int * __restrict__) (FRF_multiclass_CNN_L2_Memory+384512)), /* Bias */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory_Dyn+26112)), /* Out */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory+387072)), /* Scale */
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory+387200)), /* ScaleN */
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory+387788)) /* Infos */
	);
	AT_GraphPerf[5] = gap_cl_readhwtimer() - AT_GraphPerf[5];
	AT_GraphPerf[6] = gap_cl_readhwtimer();
	S22__conv7_Conv_fusion(
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory_Dyn+26112)), /* In */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory+196608)), /* Filter */
		((signed int * __restrict__) (FRF_multiclass_CNN_L2_Memory+381952)), /* Bias */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory+385536)), /* Scale */
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory+385792)), /* ScaleN */
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory+387808)) /* Infos */
	);
	AT_GraphPerf[6] = gap_cl_readhwtimer() - AT_GraphPerf[6];
	AT_GraphPerf[7] = gap_cl_readhwtimer();
	S25__conv8_Conv_fusion(
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory+0)), /* Filter */
		((signed int * __restrict__) (FRF_multiclass_CNN_L2_Memory+382976)), /* Bias */
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory_Dyn+26112)), /* Out */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory+386048)), /* Scale */
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory+386304)), /* ScaleN */
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory+387828)) /* Infos */
	);
	AT_GraphPerf[7] = gap_cl_readhwtimer() - AT_GraphPerf[7];
	AT_GraphPerf[8] = gap_cl_readhwtimer();
	S26__global_avg_pool_GlobalAveragePool_trans(
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory_Dyn+26112)), /* In */
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory_Dyn+0)) /* Out */
	);
	AT_GraphPerf[8] = gap_cl_readhwtimer() - AT_GraphPerf[8];
	AT_GraphPerf[9] = gap_cl_readhwtimer();
	S27__global_avg_pool_GlobalAveragePool(
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory_Dyn+0)), /* In */
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory_Dyn+13056)), /* Out */
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory+387900)) /* Infos */
	);
	AT_GraphPerf[9] = gap_cl_readhwtimer() - AT_GraphPerf[9];
	AT_GraphPerf[10] = gap_cl_readhwtimer();
	S28__global_avg_pool_GlobalAveragePool_qout0(
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory_Dyn+13056)), /* In */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory_Dyn+12)), /* Out */
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory+387956)) /* Infos */
	);
	AT_GraphPerf[10] = gap_cl_readhwtimer() - AT_GraphPerf[10];
	AT_GraphPerf[11] = gap_cl_readhwtimer();
	S31__fc_Gemm(
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory_Dyn+12)), /* In */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory+377856)), /* Filter */
		((signed int * __restrict__) (FRF_multiclass_CNN_L2_Memory+387520)), /* Bias */
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (FRF_multiclass_CNN_L2_Memory+387932)), /* Scale */
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory+387944)), /* ScaleN */
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory+387848)) /* Infos */
	);
	AT_GraphPerf[11] = gap_cl_readhwtimer() - AT_GraphPerf[11];
	AT_GraphPerf[12] = gap_cl_readhwtimer();
	S33__Softmax(
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory_Dyn+0)), /* In */
		((signed short * __restrict__) Output_1), /* Out */
		((signed char * __restrict__) (FRF_multiclass_CNN_L2_Memory+387916)) /* Infos */
	);
	AT_GraphPerf[12] = gap_cl_readhwtimer() - AT_GraphPerf[12];
	AT_GraphPerf_CNN_Total = gap_cl_readhwtimer() - AT_GraphPerf_CNN_Total;
	return 0;
}
