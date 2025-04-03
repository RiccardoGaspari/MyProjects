#include <stdint.h>
#include <stdio.h>
#include "AutoTilerLib.h"
#include "CNN_Generators_SQ8.h"
#include "CNN_Generators.h"
#include "CNN_Generators_NE16.h"

#include "CNN_Copy_Generators.h"

void load_expressions_kernels() {
}





void FRF_multiclass_CNNModel(unsigned int L1Memory, unsigned int L2Memory, unsigned int L3Memory, unsigned int L3Flash)
{
    KernelOper_T Cop = KOP_CONV;

    // SetKernelOpts(KER_OPT_NONE, KER_OPT_BUFFER_PROMOTE);
    SetSymbolDynamics();

    SetUsedFilesNames(0, 6, "at_api.h", "FRF_multiclass_CNN.h", "CNN_BasicKernels_SQ8.h", "CNN_BasicKernels.h", "CNN_BasicKernels_NE16.h", "Expression_Kernels.h");
    SetGeneratedFilesNames("FRF_multiclass_CNNKernels.c", "FRF_multiclass_CNNKernels.h");
    AT_SetGraphCtrl(AT_GRAPH_MONITOR_CYCLES, AT_OPT_ON);
    AT_SetGraphCtrl(AT_GRAPH_PRODUCE_NODE_NAMES, AT_OPT_ON);
    AT_SetGraphCtrl(AT_GRAPH_PRODUCE_OPERINFOS, AT_OPT_ON);

    SetMemoryDeviceInfos(4,
        AT_MEM_L1, L1Memory, "FRF_multiclass_CNN_L1_Memory", 0, 0,
        AT_MEM_L2, L2Memory, "FRF_multiclass_CNN_L2_Memory", 0, 1,
        AT_MEM_L3_DEFAULTRAM, L3Memory, "FRF_multiclass_CNN_L3_Memory", 0, 0,
        AT_MEM_L3_DEFAULTFLASH, L3Flash, "FRF_multiclass_CNN_L3_Flash", "FRF_multiclass_CNN_L3_Flash_Const.dat", 0
    );

    LoadCNN_SQ8_Library();
    LoadCNNLibrary();
    LoadCNN_NE16_SQ8_Library();
    LoadCNN_Copy_Library();
    load_expressions_kernels();

    CNN_GenControl_T gen_ctrl_S4__conv1_Conv_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S4__conv1_Conv_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S4__conv1_Conv_fusion, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S4__conv1_Conv_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S4__conv1_Conv_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _conv1_Conv_fusion
    CNN_ConvolutionNE16("S4__conv1_Conv_fusion", &gen_ctrl_S4__conv1_Conv_fusion,
                        -1, -1, 4, 1, 8,
                        1, 16, 819, 1,
                        KOP_CONV, 3, 1, 1, 1, 1, 1, 1, 128,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S7__conv2_Conv_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S7__conv2_Conv_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S7__conv2_Conv_fusion, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S7__conv2_Conv_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S7__conv2_Conv_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _conv2_Conv_fusion
    CNN_ConvolutionNE16("S7__conv2_Conv_fusion", &gen_ctrl_S7__conv2_Conv_fusion,
                        -1, -1, 4, 1, 8,
                        16, 32, 819, 1,
                        KOP_CONV, 3, 1, 1, 1, 1, 1, 1, 0,
                        KOP_MAXPOOL, 2, 1, 1, 1, 2, 1, 0,
                        KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S10__conv3_Conv_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S10__conv3_Conv_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S10__conv3_Conv_fusion, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S10__conv3_Conv_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S10__conv3_Conv_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _conv3_Conv_fusion
    CNN_ConvolutionNE16("S10__conv3_Conv_fusion", &gen_ctrl_S10__conv3_Conv_fusion,
                        -1, -1, 4, 1, 8,
                        32, 32, 409, 1,
                        KOP_CONV, 3, 1, 1, 1, 1, 1, 1, 0,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S13__conv4_Conv_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S13__conv4_Conv_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S13__conv4_Conv_fusion, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S13__conv4_Conv_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S13__conv4_Conv_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _conv4_Conv_fusion
    CNN_ConvolutionNE16("S13__conv4_Conv_fusion", &gen_ctrl_S13__conv4_Conv_fusion,
                        -1, -1, 4, 1, 8,
                        32, 64, 409, 1,
                        KOP_CONV, 3, 1, 1, 1, 1, 1, 1, 0,
                        KOP_MAXPOOL, 2, 1, 1, 1, 2, 1, 0,
                        KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S16__conv5_Conv_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S16__conv5_Conv_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S16__conv5_Conv_fusion, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S16__conv5_Conv_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S16__conv5_Conv_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _conv5_Conv_fusion
    CNN_ConvolutionNE16("S16__conv5_Conv_fusion", &gen_ctrl_S16__conv5_Conv_fusion,
                        -1, -1, 4, 1, 8,
                        64, 128, 204, 1,
                        KOP_CONV, 3, 1, 1, 1, 1, 1, 1, 0,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S19__conv6_Conv_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S19__conv6_Conv_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S19__conv6_Conv_fusion, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S19__conv6_Conv_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S19__conv6_Conv_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _conv6_Conv_fusion
    CNN_ConvolutionNE16("S19__conv6_Conv_fusion", &gen_ctrl_S19__conv6_Conv_fusion,
                        -1, -1, 4, 1, 8,
                        128, 128, 204, 1,
                        KOP_CONV, 3, 1, 1, 1, 1, 1, 1, 0,
                        KOP_MAXPOOL, 2, 1, 1, 1, 2, 1, 0,
                        KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S22__conv7_Conv_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S22__conv7_Conv_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S22__conv7_Conv_fusion, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S22__conv7_Conv_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S22__conv7_Conv_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _conv7_Conv_fusion
    CNN_ConvolutionNE16("S22__conv7_Conv_fusion", &gen_ctrl_S22__conv7_Conv_fusion,
                        -1, -1, 4, 1, 8,
                        128, 256, 102, 1,
                        KOP_CONV, 3, 1, 1, 1, 1, 1, 1, 0,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S25__conv8_Conv_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S25__conv8_Conv_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S25__conv8_Conv_fusion, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S25__conv8_Conv_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S25__conv8_Conv_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(1));
    // generator for _conv8_Conv_fusion
    CNN_ConvolutionNE16("S25__conv8_Conv_fusion", &gen_ctrl_S25__conv8_Conv_fusion,
                        -1, 1, 4, 1, 8,
                        256, 256, 102, 1,
                        KOP_CONV, 3, 1, 1, 1, 1, 1, 1, 0,
                        KOP_MAXPOOL, 2, 1, 1, 1, 2, 1, 0,
                        KOP_RELU);
    
    CNN_GenControl_T gen_ctrl_S26__global_avg_pool_GlobalAveragePool_trans;
    CNN_InitGenCtrl(&gen_ctrl_S26__global_avg_pool_GlobalAveragePool_trans);
    CNN_SetGenCtrl(&gen_ctrl_S26__global_avg_pool_GlobalAveragePool_trans, "ARG_DTYPE", AT_OPT_VAL(ARG_INT));
    
    // generator for _global_avg_pool_GlobalAveragePool_trans Transpose 1x51x256 -> 1x256x51 ((1, 0))
    CNN_MatTranspose("S26__global_avg_pool_GlobalAveragePool_trans", &gen_ctrl_S26__global_avg_pool_GlobalAveragePool_trans, 1,
                      1, 256, 51, KOP_MATTRANSP);
    
    // generator for _global_avg_pool_GlobalAveragePool
    CNN_GlobalPoolAct_SQ8("S27__global_avg_pool_GlobalAveragePool", 0,
                          256, 17, 3,
                          KOP_GLOBAL_AVGPOOL, KOP_NONE);
    
    
    // generator for _global_avg_pool_GlobalAveragePool_qout0
    CNN_Convert("S28__global_avg_pool_GlobalAveragePool_qout0", 1, -1, 256, KOP_CONVERT_FP_FP_SCALE);
    
    // generator for _fc_Gemm
    CNN_LinearAct_NE16("S31__fc_Gemm", 0,
                       -1, 1, 4, 1, 8,
                       256, 10, KOP_LINEAR, KOP_NONE);
    
    // generator for _Softmax
    CNN_SoftMax_SQ8("S33__Softmax", 0, 10, KOP_SOFTMAX);
    

#define GRAPH
#ifdef GRAPH
    CreateGraph("FRF_multiclass_CNNCNN",
        /* Arguments either passed or globals */
            CArgs(50,
                TCArgInfo("unsigned char * __restrict__", "Input_1", ARG_SCOPE_ARG, ARG_DIR_IN, AT_MEM_L2, AT_MEM_L2, 0),
                TCArgInfo("unsigned char * __restrict__", "_conv1_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_conv1_conv_weights.tensor", 1, 1, 8, 0, 48)),
                TCArgInfo("signed int * __restrict__", "Constant_onnx__conv_101", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__conv_101.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S4_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S4_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S4_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S4_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.01058 out: 0.01058  actscale: [1] actscalen: [0] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [128] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S4_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S4_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_conv2_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_conv2_conv_weights.tensor", 1, 1, 8, 0, 1536)),
                TCArgInfo("signed int * __restrict__", "Constant_onnx__conv_104", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__conv_104.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S7_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S7_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S7_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S7_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.02529 out: 0.02529  actscale: [1] actscalen: [0] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [0] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S7_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S7_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_conv3_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_conv3_conv_weights.tensor", 1, 1, 8, 0, 3072)),
                TCArgInfo("signed int * __restrict__", "Constant_onnx__conv_107", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__conv_107.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S10_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S10_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S10_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S10_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.06247 out: 0.06247  actscale: [1] actscalen: [0] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [0] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S10_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S10_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_conv4_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_conv4_conv_weights.tensor", 1, 1, 8, 0, 6144)),
                TCArgInfo("signed int * __restrict__", "Constant_onnx__conv_110", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__conv_110.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S13_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S13_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S13_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S13_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.07246 out: 0.07246  actscale: [1] actscalen: [0] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [0] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S13_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S13_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_conv5_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_conv5_conv_weights.tensor", 1, 1, 8, 0, 24576)),
                TCArgInfo("signed int * __restrict__", "Constant_onnx__conv_113", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__conv_113.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S16_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S16_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S16_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S16_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.07654 out: 0.07654  actscale: [1] actscalen: [0] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [0] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S16_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S16_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_conv6_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_conv6_conv_weights.tensor", 1, 1, 8, 0, 49152)),
                TCArgInfo("signed int * __restrict__", "Constant_onnx__conv_116", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__conv_116.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S19_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S19_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S19_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S19_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.10548 out: 0.10548  actscale: [1] actscalen: [0] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [0] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S19_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S19_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_conv7_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_conv7_conv_weights.tensor", 1, 1, 8, 0, 98304)),
                TCArgInfo("signed int * __restrict__", "Constant_onnx__conv_119", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__conv_119.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S22_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S22_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S22_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S22_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.03016 out: 0.03016  actscale: [1] actscalen: [0] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [0] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S22_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S22_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_conv8_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_conv8_conv_weights.tensor", 1, 1, 8, 0, 196608)),
                TCArgInfo("signed int * __restrict__", "Constant_onnx__conv_122", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__conv_122.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S25_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S25_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S25_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S25_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.04857 out: 0.04857  actscale: [1] actscalen: [0] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [0] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S25_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S25_Infos.tensor", 1, 1, 8, 0)),
                // no activation ACTSCALE: 0 ACTSCALEN: 0 GLOBAL_SUM_SCALE: [247] GLOBAL_SUM_SCALEN: [13]
                TCArgInfo("signed char * __restrict__", "S27_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S27_Infos.tensor", 1, 1, 8, 0)),
                // in q: -1.61<(i8-0.00)*0.01256547<1.60 out_q: 0.00<(u8-0.00)*0.00625810<1.60
                TCArgInfo("signed char * __restrict__", "S28_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S28_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_fc_gemm_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_fc_gemm_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "_fc_gemm_biases", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_fc_gemm_biases.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S31_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S31_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S31_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S31_Mul_shift.tensor", 1, 1, 8, 0)),
                // no activation BIASN: 0 PRENORM: 0 NE16_PADVAL: [0] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S31_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S31_Infos.tensor", 1, 1, 8, 0)),
                // in: 0.25000 out: 0.00003  BIASL_SM: [13]
                TCArgInfo("signed char * __restrict__", "S33_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S33_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed short * __restrict__", "Output_1", ARG_SCOPE_ARG, ARG_DIR_OUT, AT_MEM_L2, AT_MEM_L2, 0)
            ),
        /* Locals, allocated dynamically */
        CArgs(12,
            TCArgInfo("unsigned char * __restrict__", "S4_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S7_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S10_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S13_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S16_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S19_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S22_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S25_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S26_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S27_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S28_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S31_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0)
        )
    );



    // Node S4__conv1_Conv_fusion inq -1.00<(u8-128.00)*0.00780913<0.99 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.01058419<2.70 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S4__conv1_Conv_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "Input_1", 0),
            GNodeArg(GNA_IN, "_conv1_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_onnx__conv_101", 0),
            GNodeArg(GNA_OUT, "S4_Output", 0),
            GNodeArg(GNA_IN, "S4_Mul_scale", 0),
            GNodeArg(GNA_IN, "S4_Mul_shift", 0),
            GNodeArg(GNA_IN, "S4_Infos", 0)
        )
    );
    // Node S7__conv2_Conv_fusion inq 0.00<(u8-0.00)*0.01058419<2.70 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.02528531<6.45 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S7__conv2_Conv_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S4_Output", 0),
            GNodeArg(GNA_IN, "_conv2_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_onnx__conv_104", 0),
            GNodeArg(GNA_OUT, "S7_Output", 0),
            GNodeArg(GNA_IN, "S7_Mul_scale", 0),
            GNodeArg(GNA_IN, "S7_Mul_shift", 0),
            GNodeArg(GNA_IN, "S7_Infos", 0)
        )
    );
    // Node S10__conv3_Conv_fusion inq 0.00<(u8-0.00)*0.02528531<6.45 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.06247253<15.93 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S10__conv3_Conv_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S7_Output", 0),
            GNodeArg(GNA_IN, "_conv3_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_onnx__conv_107", 0),
            GNodeArg(GNA_OUT, "S10_Output", 0),
            GNodeArg(GNA_IN, "S10_Mul_scale", 0),
            GNodeArg(GNA_IN, "S10_Mul_shift", 0),
            GNodeArg(GNA_IN, "S10_Infos", 0)
        )
    );
    // Node S13__conv4_Conv_fusion inq 0.00<(u8-0.00)*0.06247253<15.93 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.07246014<18.48 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S13__conv4_Conv_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S10_Output", 0),
            GNodeArg(GNA_IN, "_conv4_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_onnx__conv_110", 0),
            GNodeArg(GNA_OUT, "S13_Output", 0),
            GNodeArg(GNA_IN, "S13_Mul_scale", 0),
            GNodeArg(GNA_IN, "S13_Mul_shift", 0),
            GNodeArg(GNA_IN, "S13_Infos", 0)
        )
    );
    // Node S16__conv5_Conv_fusion inq 0.00<(u8-0.00)*0.07246014<18.48 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.07653864<19.52 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S16__conv5_Conv_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S13_Output", 0),
            GNodeArg(GNA_IN, "_conv5_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_onnx__conv_113", 0),
            GNodeArg(GNA_OUT, "S16_Output", 0),
            GNodeArg(GNA_IN, "S16_Mul_scale", 0),
            GNodeArg(GNA_IN, "S16_Mul_shift", 0),
            GNodeArg(GNA_IN, "S16_Infos", 0)
        )
    );
    // Node S19__conv6_Conv_fusion inq 0.00<(u8-0.00)*0.07653864<19.52 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.10548495<26.90 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S19__conv6_Conv_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S16_Output", 0),
            GNodeArg(GNA_IN, "_conv6_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_onnx__conv_116", 0),
            GNodeArg(GNA_OUT, "S19_Output", 0),
            GNodeArg(GNA_IN, "S19_Mul_scale", 0),
            GNodeArg(GNA_IN, "S19_Mul_shift", 0),
            GNodeArg(GNA_IN, "S19_Infos", 0)
        )
    );
    // Node S22__conv7_Conv_fusion inq 0.00<(u8-0.00)*0.10548495<26.90 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.03015973<7.69 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S22__conv7_Conv_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S19_Output", 0),
            GNodeArg(GNA_IN, "_conv7_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_onnx__conv_119", 0),
            GNodeArg(GNA_OUT, "S22_Output", 0),
            GNodeArg(GNA_IN, "S22_Mul_scale", 0),
            GNodeArg(GNA_IN, "S22_Mul_shift", 0),
            GNodeArg(GNA_IN, "S22_Infos", 0)
        )
    );
    // Node S25__conv8_Conv_fusion inq 0.00<(u8-0.00)*0.03015973<7.69 weightsq chan<(u8-128.00)*chan<chan outq -6.22<(i8-0.00)*0.04857406<6.17 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S25__conv8_Conv_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S22_Output", 0),
            GNodeArg(GNA_IN, "_conv8_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_onnx__conv_122", 0),
            GNodeArg(GNA_OUT, "S25_Output", 0),
            GNodeArg(GNA_IN, "S25_Mul_scale", 0),
            GNodeArg(GNA_IN, "S25_Mul_shift", 0),
            GNodeArg(GNA_IN, "S25_Infos", 0)
        )
    );
    // Node _global_avg_pool_GlobalAveragePool_trans inq -6.22<(i8-0.00)*0.04857406<6.17 outq -6.22<(i8-0.00)*0.04857406<6.17
    AddNode("S26__global_avg_pool_GlobalAveragePool_trans",
        Bindings(2,
            GNodeArg(GNA_IN, "S25_Output", 0),
            GNodeArg(GNA_OUT, "S26_Output", 0)
        )
    );
    // Node _global_avg_pool_GlobalAveragePool inq -6.22<(i8-0.00)*0.04857406<6.17 outq -1.61<(i8-0.00)*0.01256547<1.60
    AddNode("S27__global_avg_pool_GlobalAveragePool",
        Bindings(3,
            GNodeArg(GNA_IN, "S26_Output", 0),
            GNodeArg(GNA_OUT, "S27_Output", 0),
            GNodeArg(GNA_IN, "S27_Infos", 0)
        )
    );
    // Node _global_avg_pool_GlobalAveragePool_qout0 inq -1.61<(i8-0.00)*0.01256547<1.60 outq 0.00<(u8-0.00)*0.00625810<1.60
    AddNode("S28__global_avg_pool_GlobalAveragePool_qout0",
        Bindings(3,
            GNodeArg(GNA_IN, "S27_Output", 0),
            GNodeArg(GNA_OUT, "S28_Output", 0),
            GNodeArg(GNA_IN, "S28_Infos", 0)
        )
    );
    // Node _fc_Gemm inq 0.00<(u8-0.00)*0.00625810<1.60 weightsq chan<(u8-128.00)*chan<chan outq -32.00<(i8-0.00)*0.25000000<31.75 forced
    AddNode("S31__fc_Gemm",
        Bindings(7,
            GNodeArg(GNA_IN, "S28_Output", 0),
            GNodeArg(GNA_IN, "_fc_gemm_weights", 0),
            GNodeArg(GNA_IN, "_fc_gemm_biases", 0),
            GNodeArg(GNA_OUT, "S31_Output", 0),
            GNodeArg(GNA_IN, "S31_Mul_scale", 0),
            GNodeArg(GNA_IN, "S31_Mul_shift", 0),
            GNodeArg(GNA_IN, "S31_Infos", 0)
        )
    );
    // Node _Softmax inq -32.00<(i8-0.00)*0.25000000<31.75 forced outq -1.00<(i16-0.00)*0.00003052<1.00
    AddNode("S33__Softmax",
        Bindings(3,
            GNodeArg(GNA_IN, "S31_Output", 0),
            GNodeArg(GNA_OUT, "Output_1", 0),
            GNodeArg(GNA_IN, "S33_Infos", 0)
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
    FRF_multiclass_CNNModel(128000, 1300000, 8000000, 64*1024*1024);
    GenerateTilingCode();
    return 0;
}
