#include <stdint.h>
#include <stdio.h>
#include "AutoTilerLib.h"
#include "CNN_Generators_SQ8.h"
#include "CNN_Generators.h"
#include "CNN_Generators_NE16.h"

#include "CNN_Copy_Generators.h"

void load_expressions_kernels() {
    LibKernelTemplate(
        "s27_kernel_args_t",
        CArgs(5,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned char *__restrict__ ", "expr_0_in_0"),
            TCArg("signed char *__restrict__ ", "expr_0_in_1"),
            TCArg("signed char *__restrict__ ", "expr_0_in_2"),
            TCArg("unsigned char *__restrict__ ", "expr_0_out_0")
        )
    );
    
    LibKernel(
        "s27_kernel",
        CALL_PARALLEL,
        0,
        "s27_kernel_args_t",
        0
    );
}



int s27_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (512,) spaces: ((0,),) 
        // parametric_spaces: ((0,),) 
        // exterior_shape: (512.0,) 
        KernelIterSpace(2, IterParSpace(KER_ITER_D0, 512, 8), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(4,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_0_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_0_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_0_in_2"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_0_out_0")
        ),
        Calls(1,
            Call("s27_kernel", LOC_D0,
                Bindings(5,
                    K_ArgPar("expr_0_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_Arg("expr_0_in_0", KER_ARG_TILE),
                    K_Arg("expr_0_in_1", KER_ARG_TILE),
                    K_Arg("expr_0_in_2", KER_ARG_TILE),
                    K_Arg("expr_0_out_0", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_0_out_0 axes: (0,)
        // var: expr_0_in_0 axes: (0,)
        // var: expr_0_in_1 axes: (0,)
        // var: expr_0_in_2 axes: (0,)
        KerArgs(4,
            KerArg("expr_0_out_0", KerArgSpace(1, KER_ITER_D0), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_0_out_0"),
            KerArg("expr_0_in_0",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_0_in_0"),
            KerArg("expr_0_in_1",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_0_in_1"),
            KerArg("expr_0_in_2",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_0_in_2")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 1024, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 2048, 0);
        AddKernelArgDimExplicit(Name, "expr_0_in_0", ARG_INT,  2, 512, 1);
        AddKernelArgDimExplicit(Name, "expr_0_in_1", ARG_INT,  2, 512, 1);
        AddKernelArgDimExplicit(Name, "expr_0_in_2", ARG_INT,  2, 512, 1);
        AddKernelArgDimExplicit(Name, "expr_0_out_0", ARG_INT, 2, 512, 1);
    }
    return (Kernel!=0);
}

void FCAutoEncoderModel(unsigned int L1Memory, unsigned int L2Memory, unsigned int L3Memory, unsigned int L3Flash)
{
    KernelOper_T Cop = KOP_CONV;

    // SetKernelOpts(KER_OPT_NONE, KER_OPT_BUFFER_PROMOTE);
    SetSymbolDynamics();

    SetUsedFilesNames(0, 7, "at_api.h", "FCAutoEncoder.h", "CNN_BasicKernels_SQ8.h", "CNN_BasicKernels.h", "CNN_BasicKernels_NE16.h", "CNN_BasicKernels_SQ8.h", "Expression_Kernels.h");
    SetGeneratedFilesNames("FCAutoEncoderKernels.c", "FCAutoEncoderKernels.h");
    AT_SetGraphCtrl(AT_GRAPH_MONITOR_CYCLES, AT_OPT_ON);
    AT_SetGraphCtrl(AT_GRAPH_PRODUCE_NODE_NAMES, AT_OPT_ON);
    AT_SetGraphCtrl(AT_GRAPH_PRODUCE_OPERINFOS, AT_OPT_ON);
    AT_SetGraphCtrl(AT_GRAPH_DUMP_TENSOR, AT_OPT_VAL(7));

    SetMemoryDeviceInfos(4,
        AT_MEM_L1, L1Memory, "FCAutoEncoder_L1_Memory", 0, 0,
        AT_MEM_L2, L2Memory, "FCAutoEncoder_L2_Memory", 0, 1,
        AT_MEM_L3_DEFAULTRAM, L3Memory, "FCAutoEncoder_L3_Memory", 0, 0,
        AT_MEM_L3_DEFAULTFLASH, L3Flash, "FCAutoEncoder_L3_Flash", "FCAutoEncoder_L3_Flash_Const.dat", 0
    );

    LoadCNN_SQ8_Library();
    LoadCNNLibrary();
    LoadCNN_NE16_SQ8_Library();
    load_expressions_kernels();

    CNN_GenControl_T gen_ctrl_S3__encoder_encoder_net_encoder_net_0_Gemm_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S3__encoder_encoder_net_encoder_net_0_Gemm_fusion);
    CNN_ExtraActivationArgs_T gen_ctrl_S3__encoder_encoder_net_encoder_net_0_Gemm_fusion_extra_activation_args = {1, {{"SigmoidLUT_u8", 128, -1}}};
    CNN_SetGenCtrl(&gen_ctrl_S3__encoder_encoder_net_encoder_net_0_Gemm_fusion, "EXTRA_ACTIVATION_ARGS", &gen_ctrl_S3__encoder_encoder_net_encoder_net_0_Gemm_fusion_extra_activation_args);
    // generator for _encoder_encoder_net_encoder_net_0_Gemm_fusion
    CNN_LinearAct_NE16("S3__encoder_encoder_net_encoder_net_0_Gemm_fusion", &gen_ctrl_S3__encoder_encoder_net_encoder_net_0_Gemm_fusion,
                       -1, -1, 4, 1, 8,
                       512, 256, KOP_LINEAR, KOP_SIGMOID);
    
    CNN_GenControl_T gen_ctrl_S6__encoder_encoder_net_encoder_net_3_Gemm_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S6__encoder_encoder_net_encoder_net_3_Gemm_fusion);
    CNN_ExtraActivationArgs_T gen_ctrl_S6__encoder_encoder_net_encoder_net_3_Gemm_fusion_extra_activation_args = {1, {{"SigmoidLUT_u8", 128, -1}}};
    CNN_SetGenCtrl(&gen_ctrl_S6__encoder_encoder_net_encoder_net_3_Gemm_fusion, "EXTRA_ACTIVATION_ARGS", &gen_ctrl_S6__encoder_encoder_net_encoder_net_3_Gemm_fusion_extra_activation_args);
    // generator for _encoder_encoder_net_encoder_net_3_Gemm_fusion
    CNN_LinearAct_NE16("S6__encoder_encoder_net_encoder_net_3_Gemm_fusion", &gen_ctrl_S6__encoder_encoder_net_encoder_net_3_Gemm_fusion,
                       -1, -1, 4, 1, 8,
                       256, 128, KOP_LINEAR, KOP_SIGMOID);
    
    CNN_GenControl_T gen_ctrl_S9__encoder_encoder_net_encoder_net_6_Gemm_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S9__encoder_encoder_net_encoder_net_6_Gemm_fusion);
    CNN_ExtraActivationArgs_T gen_ctrl_S9__encoder_encoder_net_encoder_net_6_Gemm_fusion_extra_activation_args = {1, {{"SigmoidLUT_u8", 128, -1}}};
    CNN_SetGenCtrl(&gen_ctrl_S9__encoder_encoder_net_encoder_net_6_Gemm_fusion, "EXTRA_ACTIVATION_ARGS", &gen_ctrl_S9__encoder_encoder_net_encoder_net_6_Gemm_fusion_extra_activation_args);
    // generator for _encoder_encoder_net_encoder_net_6_Gemm_fusion
    CNN_LinearAct_NE16("S9__encoder_encoder_net_encoder_net_6_Gemm_fusion", &gen_ctrl_S9__encoder_encoder_net_encoder_net_6_Gemm_fusion,
                       -1, -1, 4, 1, 8,
                       128, 64, KOP_LINEAR, KOP_SIGMOID);
    
    CNN_GenControl_T gen_ctrl_S12__encoder_encoder_net_encoder_net_9_Gemm_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S12__encoder_encoder_net_encoder_net_9_Gemm_fusion);
    CNN_ExtraActivationArgs_T gen_ctrl_S12__encoder_encoder_net_encoder_net_9_Gemm_fusion_extra_activation_args = {1, {{"SigmoidLUT_u8", 128, -1}}};
    CNN_SetGenCtrl(&gen_ctrl_S12__encoder_encoder_net_encoder_net_9_Gemm_fusion, "EXTRA_ACTIVATION_ARGS", &gen_ctrl_S12__encoder_encoder_net_encoder_net_9_Gemm_fusion_extra_activation_args);
    // generator for _encoder_encoder_net_encoder_net_9_Gemm_fusion
    CNN_LinearAct_NE16("S12__encoder_encoder_net_encoder_net_9_Gemm_fusion", &gen_ctrl_S12__encoder_encoder_net_encoder_net_9_Gemm_fusion,
                       -1, -1, 4, 1, 8,
                       64, 32, KOP_LINEAR, KOP_SIGMOID);
    
    CNN_GenControl_T gen_ctrl_S15__decoder_decoder_net_decoder_net_0_Gemm_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S15__decoder_decoder_net_decoder_net_0_Gemm_fusion);
    CNN_ExtraActivationArgs_T gen_ctrl_S15__decoder_decoder_net_decoder_net_0_Gemm_fusion_extra_activation_args = {1, {{"SigmoidLUT_u8", 128, -1}}};
    CNN_SetGenCtrl(&gen_ctrl_S15__decoder_decoder_net_decoder_net_0_Gemm_fusion, "EXTRA_ACTIVATION_ARGS", &gen_ctrl_S15__decoder_decoder_net_decoder_net_0_Gemm_fusion_extra_activation_args);
    // generator for _decoder_decoder_net_decoder_net_0_Gemm_fusion
    CNN_LinearAct_NE16("S15__decoder_decoder_net_decoder_net_0_Gemm_fusion", &gen_ctrl_S15__decoder_decoder_net_decoder_net_0_Gemm_fusion,
                       -1, -1, 4, 1, 8,
                       32, 64, KOP_LINEAR, KOP_SIGMOID);
    
    CNN_GenControl_T gen_ctrl_S18__decoder_decoder_net_decoder_net_3_Gemm_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S18__decoder_decoder_net_decoder_net_3_Gemm_fusion);
    CNN_ExtraActivationArgs_T gen_ctrl_S18__decoder_decoder_net_decoder_net_3_Gemm_fusion_extra_activation_args = {1, {{"SigmoidLUT_u8", 128, -1}}};
    CNN_SetGenCtrl(&gen_ctrl_S18__decoder_decoder_net_decoder_net_3_Gemm_fusion, "EXTRA_ACTIVATION_ARGS", &gen_ctrl_S18__decoder_decoder_net_decoder_net_3_Gemm_fusion_extra_activation_args);
    // generator for _decoder_decoder_net_decoder_net_3_Gemm_fusion
    CNN_LinearAct_NE16("S18__decoder_decoder_net_decoder_net_3_Gemm_fusion", &gen_ctrl_S18__decoder_decoder_net_decoder_net_3_Gemm_fusion,
                       -1, -1, 4, 1, 8,
                       64, 128, KOP_LINEAR, KOP_SIGMOID);
    
    CNN_GenControl_T gen_ctrl_S21__decoder_decoder_net_decoder_net_6_Gemm_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S21__decoder_decoder_net_decoder_net_6_Gemm_fusion);
    CNN_ExtraActivationArgs_T gen_ctrl_S21__decoder_decoder_net_decoder_net_6_Gemm_fusion_extra_activation_args = {1, {{"SigmoidLUT_u8", 128, -1}}};
    CNN_SetGenCtrl(&gen_ctrl_S21__decoder_decoder_net_decoder_net_6_Gemm_fusion, "EXTRA_ACTIVATION_ARGS", &gen_ctrl_S21__decoder_decoder_net_decoder_net_6_Gemm_fusion_extra_activation_args);
    // generator for _decoder_decoder_net_decoder_net_6_Gemm_fusion
    CNN_LinearAct_NE16("S21__decoder_decoder_net_decoder_net_6_Gemm_fusion", &gen_ctrl_S21__decoder_decoder_net_decoder_net_6_Gemm_fusion,
                       -1, -1, 4, 1, 8,
                       128, 256, KOP_LINEAR, KOP_SIGMOID);
    
    CNN_GenControl_T gen_ctrl_S24__decoder_decoder_net_decoder_net_9_Gemm_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S24__decoder_decoder_net_decoder_net_9_Gemm_fusion);
    CNN_ExtraActivationArgs_T gen_ctrl_S24__decoder_decoder_net_decoder_net_9_Gemm_fusion_extra_activation_args = {1, {{"SigmoidLUT_u8", 128, -1}}};
    CNN_SetGenCtrl(&gen_ctrl_S24__decoder_decoder_net_decoder_net_9_Gemm_fusion, "EXTRA_ACTIVATION_ARGS", &gen_ctrl_S24__decoder_decoder_net_decoder_net_9_Gemm_fusion_extra_activation_args);
    // generator for _decoder_decoder_net_decoder_net_9_Gemm_fusion
    CNN_LinearAct_NE16("S24__decoder_decoder_net_decoder_net_9_Gemm_fusion", &gen_ctrl_S24__decoder_decoder_net_decoder_net_9_Gemm_fusion,
                       -1, -1, 4, 1, 8,
                       256, 512, KOP_LINEAR, KOP_SIGMOID);
    
    
    // generator for expr_0
    s27_kernel_gen("S27_expr_0");
    

#define GRAPH
#ifdef GRAPH
    CreateGraph("FCAutoEncoderCNN",
        /* Arguments either passed or globals */
            CArgs(45,
                TCArgInfo("unsigned char * __restrict__", "Input_1", ARG_SCOPE_ARG, ARG_DIR_IN, AT_MEM_L2, AT_MEM_L2, 0),
                TCArgInfo("unsigned char * __restrict__", "_encoder_encoder_net_encoder_net_0_gemm_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_encoder_encoder_net_encoder_net_0_gemm_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "_encoder_encoder_net_encoder_net_0_gemm_biases", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_encoder_encoder_net_encoder_net_0_gemm_biases.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S3_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S3_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S3_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S3_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.04875 out: 0.00392  actscale: [129] actscalen: [6] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [127] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S3_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S3_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_encoder_encoder_net_encoder_net_3_gemm_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_encoder_encoder_net_encoder_net_3_gemm_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "_encoder_encoder_net_encoder_net_3_gemm_biases", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_encoder_encoder_net_encoder_net_3_gemm_biases.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S6_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S6_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S6_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S6_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.04875 out: 0.00392  actscale: [129] actscalen: [6] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [0] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S6_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S6_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_encoder_encoder_net_encoder_net_6_gemm_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_encoder_encoder_net_encoder_net_6_gemm_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "_encoder_encoder_net_encoder_net_6_gemm_biases", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_encoder_encoder_net_encoder_net_6_gemm_biases.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S9_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S9_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S9_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S9_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.04875 out: 0.00392  actscale: [129] actscalen: [6] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [0] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S9_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S9_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_encoder_encoder_net_encoder_net_9_gemm_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_encoder_encoder_net_encoder_net_9_gemm_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "_encoder_encoder_net_encoder_net_9_gemm_biases", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_encoder_encoder_net_encoder_net_9_gemm_biases.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S12_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S12_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S12_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S12_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.04875 out: 0.00392  actscale: [129] actscalen: [6] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [0] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S12_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S12_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_decoder_decoder_net_decoder_net_0_gemm_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_decoder_decoder_net_decoder_net_0_gemm_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "_decoder_decoder_net_decoder_net_0_gemm_biases", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_decoder_decoder_net_decoder_net_0_gemm_biases.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S15_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S15_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S15_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S15_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.04875 out: 0.00392  actscale: [129] actscalen: [6] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [0] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S15_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S15_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_decoder_decoder_net_decoder_net_3_gemm_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_decoder_decoder_net_decoder_net_3_gemm_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "_decoder_decoder_net_decoder_net_3_gemm_biases", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_decoder_decoder_net_decoder_net_3_gemm_biases.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S18_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S18_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S18_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S18_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.04875 out: 0.00392  actscale: [129] actscalen: [6] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [0] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S18_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S18_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_decoder_decoder_net_decoder_net_6_gemm_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_decoder_decoder_net_decoder_net_6_gemm_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "_decoder_decoder_net_decoder_net_6_gemm_biases", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_decoder_decoder_net_decoder_net_6_gemm_biases.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S21_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S21_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S21_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S21_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.04875 out: 0.00392  actscale: [129] actscalen: [6] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [0] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S21_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S21_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_decoder_decoder_net_decoder_net_9_gemm_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_decoder_decoder_net_decoder_net_9_gemm_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "_decoder_decoder_net_decoder_net_9_gemm_biases", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_decoder_decoder_net_decoder_net_9_gemm_biases.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S24_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S24_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S24_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S24_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.04875 out: 0.00392  actscale: [129] actscalen: [6] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [0] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S24_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S24_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "_decoder_decoder_net_decoder_net_11_batchnormalization_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_decoder_decoder_net_decoder_net_11_batchnormalization_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "_decoder_decoder_net_decoder_net_11_batchnormalization_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_decoder_decoder_net_decoder_net_11_batchnormalization_bias.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "SigmoidLUT_u8", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("SigmoidLUT_u8.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "Output_1", ARG_SCOPE_ARG, ARG_DIR_OUT, AT_MEM_L2, AT_MEM_L2, 0)
            ),
        /* Locals, allocated dynamically */
        CArgs(8,
            TCArgInfo("unsigned char * __restrict__", "S3_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S6_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S9_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S12_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S15_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S18_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S21_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S24_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0)
        )
    );



    // Node _encoder_encoder_net_encoder_net_0_Gemm inq -0.99<(u8-127.00)*0.00781013<1.00 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.00392157<1.00
    AddNode("S3__encoder_encoder_net_encoder_net_0_Gemm_fusion",
        Bindings(8,
            GNodeArg(GNA_IN, "Input_1", 0),
            GNodeArg(GNA_IN, "_encoder_encoder_net_encoder_net_0_gemm_weights", 0),
            GNodeArg(GNA_IN, "_encoder_encoder_net_encoder_net_0_gemm_biases", 0),
            GNodeArg(GNA_OUT, "S3_Output", 0),
            GNodeArg(GNA_IN, "S3_Mul_scale", 0),
            GNodeArg(GNA_IN, "S3_Mul_shift", 0),
            GNodeArg(GNA_IN, "S3_Infos", 0),
            GNodeArg(GNA_IN, "SigmoidLUT_u8", 0)
        )
    );
    // Node _encoder_encoder_net_encoder_net_3_Gemm inq 0.00<(u8-0.00)*0.00392157<1.00 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.00392157<1.00
    AddNode("S6__encoder_encoder_net_encoder_net_3_Gemm_fusion",
        Bindings(8,
            GNodeArg(GNA_IN, "S3_Output", 0),
            GNodeArg(GNA_IN, "_encoder_encoder_net_encoder_net_3_gemm_weights", 0),
            GNodeArg(GNA_IN, "_encoder_encoder_net_encoder_net_3_gemm_biases", 0),
            GNodeArg(GNA_OUT, "S6_Output", 0),
            GNodeArg(GNA_IN, "S6_Mul_scale", 0),
            GNodeArg(GNA_IN, "S6_Mul_shift", 0),
            GNodeArg(GNA_IN, "S6_Infos", 0),
            GNodeArg(GNA_IN, "SigmoidLUT_u8", 0)
        )
    );
    // Node _encoder_encoder_net_encoder_net_6_Gemm inq 0.00<(u8-0.00)*0.00392157<1.00 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.00392157<1.00
    AddNode("S9__encoder_encoder_net_encoder_net_6_Gemm_fusion",
        Bindings(8,
            GNodeArg(GNA_IN, "S6_Output", 0),
            GNodeArg(GNA_IN, "_encoder_encoder_net_encoder_net_6_gemm_weights", 0),
            GNodeArg(GNA_IN, "_encoder_encoder_net_encoder_net_6_gemm_biases", 0),
            GNodeArg(GNA_OUT, "S9_Output", 0),
            GNodeArg(GNA_IN, "S9_Mul_scale", 0),
            GNodeArg(GNA_IN, "S9_Mul_shift", 0),
            GNodeArg(GNA_IN, "S9_Infos", 0),
            GNodeArg(GNA_IN, "SigmoidLUT_u8", 0)
        )
    );
    // Node _encoder_encoder_net_encoder_net_9_Gemm inq 0.00<(u8-0.00)*0.00392157<1.00 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.00392157<1.00
    AddNode("S12__encoder_encoder_net_encoder_net_9_Gemm_fusion",
        Bindings(8,
            GNodeArg(GNA_IN, "S9_Output", 0),
            GNodeArg(GNA_IN, "_encoder_encoder_net_encoder_net_9_gemm_weights", 0),
            GNodeArg(GNA_IN, "_encoder_encoder_net_encoder_net_9_gemm_biases", 0),
            GNodeArg(GNA_OUT, "S12_Output", 0),
            GNodeArg(GNA_IN, "S12_Mul_scale", 0),
            GNodeArg(GNA_IN, "S12_Mul_shift", 0),
            GNodeArg(GNA_IN, "S12_Infos", 0),
            GNodeArg(GNA_IN, "SigmoidLUT_u8", 0)
        )
    );
    // Node _decoder_decoder_net_decoder_net_0_Gemm inq 0.00<(u8-0.00)*0.00392157<1.00 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.00392157<1.00
    AddNode("S15__decoder_decoder_net_decoder_net_0_Gemm_fusion",
        Bindings(8,
            GNodeArg(GNA_IN, "S12_Output", 0),
            GNodeArg(GNA_IN, "_decoder_decoder_net_decoder_net_0_gemm_weights", 0),
            GNodeArg(GNA_IN, "_decoder_decoder_net_decoder_net_0_gemm_biases", 0),
            GNodeArg(GNA_OUT, "S15_Output", 0),
            GNodeArg(GNA_IN, "S15_Mul_scale", 0),
            GNodeArg(GNA_IN, "S15_Mul_shift", 0),
            GNodeArg(GNA_IN, "S15_Infos", 0),
            GNodeArg(GNA_IN, "SigmoidLUT_u8", 0)
        )
    );
    // Node _decoder_decoder_net_decoder_net_3_Gemm inq 0.00<(u8-0.00)*0.00392157<1.00 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.00392157<1.00
    AddNode("S18__decoder_decoder_net_decoder_net_3_Gemm_fusion",
        Bindings(8,
            GNodeArg(GNA_IN, "S15_Output", 0),
            GNodeArg(GNA_IN, "_decoder_decoder_net_decoder_net_3_gemm_weights", 0),
            GNodeArg(GNA_IN, "_decoder_decoder_net_decoder_net_3_gemm_biases", 0),
            GNodeArg(GNA_OUT, "S18_Output", 0),
            GNodeArg(GNA_IN, "S18_Mul_scale", 0),
            GNodeArg(GNA_IN, "S18_Mul_shift", 0),
            GNodeArg(GNA_IN, "S18_Infos", 0),
            GNodeArg(GNA_IN, "SigmoidLUT_u8", 0)
        )
    );
    // Node _decoder_decoder_net_decoder_net_6_Gemm inq 0.00<(u8-0.00)*0.00392157<1.00 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.00392157<1.00
    AddNode("S21__decoder_decoder_net_decoder_net_6_Gemm_fusion",
        Bindings(8,
            GNodeArg(GNA_IN, "S18_Output", 0),
            GNodeArg(GNA_IN, "_decoder_decoder_net_decoder_net_6_gemm_weights", 0),
            GNodeArg(GNA_IN, "_decoder_decoder_net_decoder_net_6_gemm_biases", 0),
            GNodeArg(GNA_OUT, "S21_Output", 0),
            GNodeArg(GNA_IN, "S21_Mul_scale", 0),
            GNodeArg(GNA_IN, "S21_Mul_shift", 0),
            GNodeArg(GNA_IN, "S21_Infos", 0),
            GNodeArg(GNA_IN, "SigmoidLUT_u8", 0)
        )
    );
    // Node _decoder_decoder_net_decoder_net_9_Gemm inq 0.00<(u8-0.00)*0.00392157<1.00 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.00392157<1.00
    AddNode("S24__decoder_decoder_net_decoder_net_9_Gemm_fusion",
        Bindings(8,
            GNodeArg(GNA_IN, "S21_Output", 0),
            GNodeArg(GNA_IN, "_decoder_decoder_net_decoder_net_9_gemm_weights", 0),
            GNodeArg(GNA_IN, "_decoder_decoder_net_decoder_net_9_gemm_biases", 0),
            GNodeArg(GNA_OUT, "S24_Output", 0),
            GNodeArg(GNA_IN, "S24_Mul_scale", 0),
            GNodeArg(GNA_IN, "S24_Mul_shift", 0),
            GNodeArg(GNA_IN, "S24_Infos", 0),
            GNodeArg(GNA_IN, "SigmoidLUT_u8", 0)
        )
    );
    // Node expr_0 in_qs [0.00<(u8-0.00)*0.00392157<1.00,-1.01<(i8-0.00)*0.00787398<1.00,-1.01<(i8-0.00)*0.00787402<1.00] out_qs [-0.72<(u8-128.00)*0.00560141<0.71 forced]
    AddNode("S27_expr_0",
        Bindings(4,
            GNodeArg(GNA_IN, "S24_Output", 0),
            GNodeArg(GNA_IN, "_decoder_decoder_net_decoder_net_11_batchnormalization_scale", 0),
            GNodeArg(GNA_IN, "_decoder_decoder_net_decoder_net_11_batchnormalization_bias", 0),
            GNodeArg(GNA_OUT, "Output_1", 0)
        )
    );
    CloseGraph();
#endif
}

int main(int argc, char **argv)

{
    if (TilerParseOptions(argc, argv)) {
            printf("Failed to initialize or incorrect output arguments directory.\n"); return 1;
    }
    FCAutoEncoderModel(128000, 1300000, 8000000, 64*1024*1024);
    GenerateTilingCode();
    return 0;
}
