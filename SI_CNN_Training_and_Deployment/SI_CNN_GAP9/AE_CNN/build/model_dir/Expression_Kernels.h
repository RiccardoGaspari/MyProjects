#ifndef AE_1DCNN_RELU_BASIC_KERNELS_H
#define AE_1DCNN_RELU_BASIC_KERNELS_H
#include "at_api.h"
#include "DspLib.h"
#include "at_api.h"

typedef struct {
    unsigned int I0;
    signed char *__restrict__  expr_0_in_0;
    signed char *__restrict__  expr_0_in_1;
    signed char *__restrict__  expr_0_out_0;
} s11_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned char *__restrict__  expr_1_in_0;
    unsigned char *__restrict__  expr_1_in_1;
    unsigned char *__restrict__  expr_1_out_0;
} s24_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned char *__restrict__  expr_2_in_0;
    unsigned char *__restrict__  expr_2_in_1;
    unsigned char *__restrict__  expr_2_out_0;
} s37_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned char *__restrict__  expr_3_in_0;
    unsigned char *__restrict__  expr_3_in_1;
    unsigned char *__restrict__  expr_3_out_0;
} s50_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned char *__restrict__  expr_4_in_0;
    unsigned char *__restrict__  expr_4_in_1;
    unsigned char *__restrict__  expr_4_out_0;
} s60_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned char *__restrict__  expr_5_in_0;
    unsigned char *__restrict__  expr_5_in_1;
    unsigned char *__restrict__  expr_5_out_0;
} s70_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned char *__restrict__  expr_6_in_0;
    unsigned char *__restrict__  expr_6_in_1;
    unsigned char *__restrict__  expr_6_out_0;
} s80_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned char *__restrict__  expr_7_in_0;
    unsigned char *__restrict__  expr_7_in_1;
    unsigned char *__restrict__  expr_7_out_0;
} s90_kernel_args_t;


void s11_kernel(s11_kernel_args_t *Args);

void s24_kernel(s24_kernel_args_t *Args);

void s37_kernel(s37_kernel_args_t *Args);

void s50_kernel(s50_kernel_args_t *Args);

void s60_kernel(s60_kernel_args_t *Args);

void s70_kernel(s70_kernel_args_t *Args);

void s80_kernel(s80_kernel_args_t *Args);

void s90_kernel(s90_kernel_args_t *Args);


#endif // AE_1DCNN_RELU_BASIC_KERNELS_H