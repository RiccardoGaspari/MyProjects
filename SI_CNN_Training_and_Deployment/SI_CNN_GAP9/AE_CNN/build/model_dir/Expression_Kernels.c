#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wpointer-sign"
#pragma GCC diagnostic ignored "-Wsign-compare"
#include "Expression_Kernels.h"

static int CoreCountDynamic = 1;
static int ActiveCore = gap_ncore();

static inline unsigned int __attribute__((always_inline)) ChunkSize(unsigned int X)

{
	unsigned int NCore;
	unsigned int Log2Core;
	unsigned int Chunk;

	if (CoreCountDynamic) NCore = ActiveCore; else NCore = gap_ncore();
	Log2Core = gap_fl1(NCore);
	Chunk = (X>>Log2Core) + ((X&(NCore-1))!=0);
	return Chunk;
}

#ifndef AT_NORM
#define AT_NORM(x, n)   gap_roundnorm_reg((x), (n))
#endif
#define ATLShift(x, n)  ((x) << (n))

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void s11_kernel(s11_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    signed char *__restrict__  expr_0_in_0 = Args->expr_0_in_0; // (1, 512, 1) (int8-127) 0.340 Q7
    signed char *__restrict__  expr_0_in_1 = Args->expr_0_in_1; // (1, 512, 1) (int8--128) 0.502 Q7
    signed char *__restrict__  expr_0_out_0 = Args->expr_0_out_0; // (1, 512, 1) int8 0.678 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 512, 1) var shapes:
    // expr_0_out_0: (1, 512, 1) expr_0_in_0: (1, 512, 1) expr_0_in_1: (1, 512,
    // 1)
    // Iteration reduced to spaces ((1,),)
    // Fixed spaces ()
    // Parameteric spaces ((1,),)
    // Paralelized space (1,)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_0_in_0: (int8-127) 0.340 Q7 expr_0_in_1: (int8--128)
        // 0.502 Q7
        // expr_0_out_0 = Cast(Clip(Sub(Norm(Mul(Add(Cast(expr_0_in_0, int32), Norm(Mul(Cast(expr_0_in_1, int32), [189]), [7])), [129]), [8]), [-31]), -128, 127), int8)
        // _encoder_conv_conv_0_Add scale arg 0 (no zp adj) - (int8-127) 0.340 Q7 -> (int32-127) 0.681 Q8
        int _SYMBOL_Cast24 = ((int)expr_0_in_0[i0]);
        // scale clip and cast - (int32--62) 1.361 Q9 -> int8 0.678 Q7
        expr_0_out_0[i0] = ((signed char)gap_clip(((gap_roundnorm_reg(((_SYMBOL_Cast24+gap_roundnorm_reg((((int)expr_0_in_1[i0])*(189)), ((unsigned char)7)))*(129)), ((unsigned char)8))-(-31))), (((signed char)7))));
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void s24_kernel(s24_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned char *__restrict__  expr_1_in_0 = Args->expr_1_in_0; // (1, 256, 2) (uint8-179) 1.211 Q8
    unsigned char *__restrict__  expr_1_in_1 = Args->expr_1_in_1; // (1, 256, 2) uint8 0.244 Q8
    unsigned char *__restrict__  expr_1_out_0 = Args->expr_1_out_0; // (1, 256, 2) (uint8-156) 0.493 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 256, 2) var shapes:
    // expr_1_out_0: (1, 256, 2) expr_1_in_0: (1, 256, 2) expr_1_in_1: (1, 256,
    // 2)
    // Iteration reduced to spaces ((1, 2),)
    // Fixed spaces ()
    // Parameteric spaces ((1, 2),)
    // Paralelized space (1, 2)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_1_in_0: (uint8-179) 1.211 Q8 expr_1_in_1: uint8 0.244 Q8
        // expr_1_out_0 = Cast(Clip(Sub(Norm(Mul(Add(Norm(Mul(Cast(expr_1_in_0, int32), [159]), [5]), Cast(expr_1_in_1, int32)), [253]), [10]), [64]), 0, 255), uint8)
        // _encoder_conv_conv_1_Add scale arg 1 (no zp adj) - uint8 0.244 Q8 -> int32 1.949 Q11
        int _SYMBOL_Cast4 = ((int)expr_1_in_1[i0]);
        // scale clip and cast - (int32-889) 3.897 Q12 -> (uint8-156) 0.493 Q7
        expr_1_out_0[i0] = ((unsigned char)gap_clipu(((gap_roundnorm_reg(((gap_roundnorm_reg((((int)expr_1_in_0[i0])*(159)), ((unsigned char)5))+_SYMBOL_Cast4)*(253)), ((unsigned char)10))-(64))), (((signed char)8))));
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void s37_kernel(s37_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned char *__restrict__  expr_2_in_0 = Args->expr_2_in_0; // (1, 128, 4) (uint8-255) 0.625 Q8
    unsigned char *__restrict__  expr_2_in_1 = Args->expr_2_in_1; // (1, 128, 4) uint8 0.099 Q8
    unsigned char *__restrict__  expr_2_out_0 = Args->expr_2_out_0; // (1, 128, 4) (uint8-252) 0.299 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 128, 4) var shapes:
    // expr_2_out_0: (1, 128, 4) expr_2_in_0: (1, 128, 4) expr_2_in_1: (1, 128,
    // 4)
    // Iteration reduced to spaces ((1, 2),)
    // Fixed spaces ()
    // Parameteric spaces ((1, 2),)
    // Paralelized space (1, 2)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_2_in_0: (uint8-255) 0.625 Q8 expr_2_in_1: uint8 0.099 Q8
        // expr_2_out_0 = Cast(Clip(Sub(Norm(Mul(Add(Norm(Mul(Cast(expr_2_in_0, int32), [202]), [5]), Cast(expr_2_in_1, int32)), [170]), [10]), [15]), 0, 255), uint8)
        // _encoder_conv_conv_2_Add scale arg 1 (no zp adj) - uint8 0.099 Q8 -> int32 0.793 Q11
        int _SYMBOL_Cast7 = ((int)expr_2_in_1[i0]);
        // scale clip and cast - (int32-1610) 1.586 Q12 -> (uint8-252) 0.299 Q7
        expr_2_out_0[i0] = ((unsigned char)gap_clipu(((gap_roundnorm_reg(((gap_roundnorm_reg((((int)expr_2_in_0[i0])*(202)), ((unsigned char)5))+_SYMBOL_Cast7)*(170)), ((unsigned char)10))-(15))), (((signed char)8))));
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void s50_kernel(s50_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned char *__restrict__  expr_3_in_0 = Args->expr_3_in_0; // (1, 64, 32) (uint8-116) 1.040 Q8
    unsigned char *__restrict__  expr_3_in_1 = Args->expr_3_in_1; // (1, 64, 32) uint8 0.182 Q8
    unsigned char *__restrict__  expr_3_out_0 = Args->expr_3_out_0; // (1, 64, 32) (uint8-108) 0.537 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 64, 32) var shapes:
    // expr_3_out_0: (1, 64, 32) expr_3_in_0: (1, 64, 32) expr_3_in_1: (1, 64,
    // 32)
    // Iteration reduced to spaces ((1, 2),)
    // Fixed spaces ()
    // Parameteric spaces ((1, 2),)
    // Paralelized space (1, 2)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_3_in_0: (uint8-116) 1.040 Q8 expr_3_in_1: uint8 0.182 Q8
        // expr_3_out_0 = Cast(Clip(Sub(Norm(Mul(Add(Norm(Mul(Cast(expr_3_in_0, int32), [183]), [5]), Cast(expr_3_in_1, int32)), [173]), [10]), [4]), 0, 255), uint8)
        // _encoder_conv_conv_3_Add scale arg 1 (no zp adj) - uint8 0.182 Q8 -> int32 1.453 Q11
        int _SYMBOL_Cast10 = ((int)expr_3_in_1[i0]);
        // scale clip and cast - (int32-663) 2.907 Q12 -> (uint8-108) 0.537 Q7
        expr_3_out_0[i0] = ((unsigned char)gap_clipu(((gap_roundnorm_reg(((gap_roundnorm_reg((((int)expr_3_in_0[i0])*(183)), ((unsigned char)5))+_SYMBOL_Cast10)*(173)), ((unsigned char)10))-(4))), (((signed char)8))));
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void s60_kernel(s60_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned char *__restrict__  expr_4_in_0 = Args->expr_4_in_0; // (1, 32, 32) uint8 0.143 Q8
    unsigned char *__restrict__  expr_4_in_1 = Args->expr_4_in_1; // (1, 32, 32) (uint8-128) 0.599 Q8
    unsigned char *__restrict__  expr_4_out_0 = Args->expr_4_out_0; // (1, 32, 32) (uint8-118) 0.326 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 32, 32) var shapes:
    // expr_4_out_0: (1, 32, 32) expr_4_in_0: (1, 32, 32) expr_4_in_1: (1, 32,
    // 32)
    // Iteration reduced to spaces ((1, 2),)
    // Fixed spaces ()
    // Parameteric spaces ((1, 2),)
    // Paralelized space (1, 2)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_4_in_0: uint8 0.143 Q8 expr_4_in_1: (uint8-128) 0.599 Q8
        // expr_4_out_0 = Cast(Clip(Norm(Mul(Add(Cast(expr_4_in_0, int32), Norm(Mul(Cast(expr_4_in_1, int32), [134]), [5])), [225]), [10]), 0, 255), uint8)
        // _decoder_deconv_deconv_0_Add scale arg 0 (no zp adj) - uint8 0.143 Q8 -> int32 1.144 Q11
        int _SYMBOL_Cast12 = ((int)expr_4_in_0[i0]);
        // scale clip and cast - (int32-536) 2.287 Q12 -> (uint8-118) 0.326 Q7
        expr_4_out_0[i0] = ((unsigned char)gap_clipu((gap_roundnorm_reg(((_SYMBOL_Cast12+gap_roundnorm_reg((((int)expr_4_in_1[i0])*(134)), ((unsigned char)5)))*(225)), ((unsigned char)10))), (((signed char)8))));
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void s70_kernel(s70_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned char *__restrict__  expr_5_in_0 = Args->expr_5_in_0; // (1, 64, 32) uint8 0.163 Q8
    unsigned char *__restrict__  expr_5_in_1 = Args->expr_5_in_1; // (1, 64, 32) (uint8-138) 0.388 Q8
    unsigned char *__restrict__  expr_5_out_0 = Args->expr_5_out_0; // (1, 64, 32) (uint8-111) 0.242 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 64, 32) var shapes:
    // expr_5_out_0: (1, 64, 32) expr_5_in_0: (1, 64, 32) expr_5_in_1: (1, 64,
    // 32)
    // Iteration reduced to spaces ((1, 2),)
    // Fixed spaces ()
    // Parameteric spaces ((1, 2),)
    // Paralelized space (1, 2)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_5_in_0: uint8 0.163 Q8 expr_5_in_1: (uint8-138) 0.388 Q8
        // expr_5_out_0 = Cast(Clip(Norm(Mul(Add(Cast(expr_5_in_0, int32), Norm(Mul(Cast(expr_5_in_1, int32), [153]), [6])), [172]), [9]), 0, 255), uint8)
        // _decoder_deconv_deconv_1_Add scale arg 0 (no zp adj) - uint8 0.163 Q8 -> int32 0.650 Q10
        int _SYMBOL_Cast15 = ((int)expr_5_in_0[i0]);
        // scale clip and cast - (int32-330) 1.301 Q11 -> (uint8-111) 0.242 Q7
        expr_5_out_0[i0] = ((unsigned char)gap_clipu((gap_roundnorm_reg(((_SYMBOL_Cast15+gap_roundnorm_reg((((int)expr_5_in_1[i0])*(153)), ((unsigned char)6)))*(172)), ((unsigned char)9))), (((signed char)8))));
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void s80_kernel(s80_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned char *__restrict__  expr_6_in_0 = Args->expr_6_in_0; // (1, 128, 32) uint8 0.131 Q8
    unsigned char *__restrict__  expr_6_in_1 = Args->expr_6_in_1; // (1, 128, 32) (uint8-147) 0.338 Q8
    unsigned char *__restrict__  expr_6_out_0 = Args->expr_6_out_0; // (1, 128, 32) (uint8-115) 0.215 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 128, 32) var shapes:
    // expr_6_out_0: (1, 128, 32) expr_6_in_0: (1, 128, 32) expr_6_in_1: (1,
    // 128, 32)
    // Iteration reduced to spaces ((1, 2),)
    // Fixed spaces ()
    // Parameteric spaces ((1, 2),)
    // Paralelized space (1, 2)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_6_in_0: uint8 0.131 Q8 expr_6_in_1: (uint8-147) 0.338 Q8
        // expr_6_out_0 = Cast(Clip(Norm(Mul(Add(Cast(expr_6_in_0, int32), Norm(Mul(Cast(expr_6_in_1, int32), [166]), [6])), [155]), [9]), 0, 255), uint8)
        // _decoder_deconv_deconv_2_Add scale arg 0 (no zp adj) - uint8 0.131 Q8 -> int32 0.522 Q10
        int _SYMBOL_Cast18 = ((int)expr_6_in_0[i0]);
        // scale clip and cast - (int32-381) 1.044 Q11 -> (uint8-115) 0.215 Q7
        expr_6_out_0[i0] = ((unsigned char)gap_clipu((gap_roundnorm_reg(((_SYMBOL_Cast18+gap_roundnorm_reg((((int)expr_6_in_1[i0])*(166)), ((unsigned char)6)))*(155)), ((unsigned char)9))), (((signed char)8))));
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void s90_kernel(s90_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned char *__restrict__  expr_7_in_0 = Args->expr_7_in_0; // (1, 256, 16) uint8 0.163 Q8
    unsigned char *__restrict__  expr_7_in_1 = Args->expr_7_in_1; // (1, 256, 16) (uint8-114) 0.376 Q8
    unsigned char *__restrict__  expr_7_out_0 = Args->expr_7_out_0; // (1, 256, 16) (uint8-60) 0.189 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 256, 16) var shapes:
    // expr_7_out_0: (1, 256, 16) expr_7_in_0: (1, 256, 16) expr_7_in_1: (1,
    // 256, 16)
    // Iteration reduced to spaces ((1, 2),)
    // Fixed spaces ()
    // Parameteric spaces ((1, 2),)
    // Paralelized space (1, 2)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_7_in_0: uint8 0.163 Q8 expr_7_in_1: (uint8-114) 0.376 Q8
        // expr_7_out_0 = Cast(Clip(Sub(Norm(Mul(Add(Cast(expr_7_in_0, int32), Norm(Mul(Cast(expr_7_in_1, int32), [148]), [6])), [221]), [9]), [54]), 0, 255), uint8)
        // _decoder_deconv_deconv_3_Add scale arg 0 (no zp adj) - uint8 0.163 Q8 -> int32 0.652 Q10
        int _SYMBOL_Cast21 = ((int)expr_7_in_0[i0]);
        // scale clip and cast - (int32-264) 1.303 Q11 -> (uint8-60) 0.189 Q7
        expr_7_out_0[i0] = ((unsigned char)gap_clipu(((gap_roundnorm_reg(((_SYMBOL_Cast21+gap_roundnorm_reg((((int)expr_7_in_1[i0])*(148)), ((unsigned char)6)))*(221)), ((unsigned char)9))-(54))), (((signed char)8))));
    }
    gap_waitbarrier(0);
}


#pragma GCC diagnostic pop