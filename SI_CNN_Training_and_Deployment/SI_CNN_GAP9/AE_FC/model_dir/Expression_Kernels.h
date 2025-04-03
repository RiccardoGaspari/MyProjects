#ifndef FCAUTOENCODER_BASIC_KERNELS_H
#define FCAUTOENCODER_BASIC_KERNELS_H
#include "at_api.h"
#include "DspLib.h"
#include "at_api.h"

typedef struct {
    unsigned int I0;
    unsigned char *__restrict__  expr_0_in_0;
    signed char *__restrict__  expr_0_in_1;
    signed char *__restrict__  expr_0_in_2;
    unsigned char *__restrict__  expr_0_out_0;
} s27_kernel_args_t;


void s27_kernel(s27_kernel_args_t *Args);


#endif // FCAUTOENCODER_BASIC_KERNELS_H