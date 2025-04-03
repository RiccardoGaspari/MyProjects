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
void s27_kernel(s27_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned char *__restrict__  expr_0_in_0 = Args->expr_0_in_0; // (512,) uint8 1.004 Q8
    signed char *__restrict__  expr_0_in_1 = Args->expr_0_in_1; // (512,) int8 1.008 Q7
    signed char *__restrict__  expr_0_in_2 = Args->expr_0_in_2; // (512,) int8 1.008 Q7
    unsigned char *__restrict__  expr_0_out_0 = Args->expr_0_out_0; // (512,) (uint8-128) 1.434 Q8
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (512,) var shapes:
    // expr_0_out_0: (512,) expr_0_in_0: (512,) expr_0_in_1: (512,)
    // expr_0_in_2: (512,)
    // Iteration reduced to spaces ((0,),)
    // Fixed spaces ()
    // Parameteric spaces ((0,),)
    // Paralelized space (0,)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_0_in_0: uint8 1.004 Q8 expr_0_in_1: int8 1.008 Q7
        // expr_0_in_2: int8 1.008 Q7
        // expr_0_out_0 = Cast(Clip(Sub(Norm(Mul(Add(Mul(Cast(expr_0_in_0, int32), Cast(expr_0_in_1, int32)), Mul(Cast(expr_0_in_2, int32), [255])), [181]), [15]), [-128]), 0, 255), uint8)
        // scale clip and cast - int32 2.024 Q16 -> (uint8-128) 1.434 Q8
        expr_0_out_0[i0] = ((unsigned char)gap_clipu(((gap_roundnorm_reg((((((int)expr_0_in_0[i0])*((int)expr_0_in_1[i0]))+(((int)expr_0_in_2[i0])*(255)))*(181)), ((unsigned char)15))-(-128))), (((signed char)8))));
    }
    gap_waitbarrier(0);
}


#pragma GCC diagnostic pop