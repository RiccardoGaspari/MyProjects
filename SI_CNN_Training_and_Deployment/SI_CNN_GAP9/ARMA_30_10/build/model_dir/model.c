#include <stdint.h>
#include <stdio.h>
#include "AutoTilerLib.h"
#include "CNN_Generators_SQ8.h"
#include "CNN_Generators.h"
#include "CNN_Generators_NE16.h"

#include "CNN_Copy_Generators.h"

void load_expressions_kernels() {
}





void ARMA_30_10_Bin_AllModel(unsigned int L1Memory, unsigned int L2Memory, unsigned int L3Memory, unsigned int L3Flash)
{
    KernelOper_T Cop = KOP_CONV;

    // SetKernelOpts(KER_OPT_NONE, KER_OPT_BUFFER_PROMOTE);
    SetSymbolDynamics();

    SetUsedFilesNames(0, 6, "at_api.h", "ARMA_30_10_Bin_All.h", "CNN_BasicKernels_SQ8.h", "CNN_BasicKernels.h", "CNN_BasicKernels_NE16.h", "Expression_Kernels.h");
    SetGeneratedFilesNames("ARMA_30_10_Bin_AllKernels.c", "ARMA_30_10_Bin_AllKernels.h");
    AT_SetGraphCtrl(AT_GRAPH_MONITOR_CYCLES, AT_OPT_ON);
    AT_SetGraphCtrl(AT_GRAPH_PRODUCE_NODE_NAMES, AT_OPT_ON);
    AT_SetGraphCtrl(AT_GRAPH_PRODUCE_OPERINFOS, AT_OPT_ON);

    SetMemoryDeviceInfos(4,
        AT_MEM_L1, L1Memory, "ARMA_30_10_Bin_All_L1_Memory", 0, 0,
        AT_MEM_L2, L2Memory, "ARMA_30_10_Bin_All_L2_Memory", 0, 1,
        AT_MEM_L3_DEFAULTRAM, L3Memory, "ARMA_30_10_Bin_All_L3_Memory", 0, 0,
        AT_MEM_L3_DEFAULTFLASH, L3Flash, "ARMA_30_10_Bin_All_L3_Flash", "ARMA_30_10_Bin_All_L3_Flash_Const.dat", 0
    );

    LoadCNN_SQ8_Library();
    LoadCNNLibrary();
    LoadCNN_NE16_SQ8_Library();
    LoadCNN_Copy_Library();
    load_expressions_kernels();

    CNN_GenControl_T gen_ctrl_S3_ARMA_30_10_Bin_All_conv2d_Conv2D_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S3_ARMA_30_10_Bin_All_conv2d_Conv2D_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S3_ARMA_30_10_Bin_All_conv2d_Conv2D_fusion, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S3_ARMA_30_10_Bin_All_conv2d_Conv2D_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S3_ARMA_30_10_Bin_All_conv2d_Conv2D_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for ARMA_30_10_Bin_All_conv2d_Conv2D_fusion
    CNN_ConvolutionNE16("S3_ARMA_30_10_Bin_All_conv2d_Conv2D_fusion", &gen_ctrl_S3_ARMA_30_10_Bin_All_conv2d_Conv2D_fusion,
                        -1, -1, 4, 1, 8,
                        1, 30, 1, 20,
                        KOP_CONV, 1, 3, 1, 1, 1, 1, 1, 120,
                        KOP_MAXPOOL, 1, 1, 1, 1, 2, 2, 0,
                        KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S6_ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S6_ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S6_ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S6_ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S6_ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(1));
    // generator for ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion
    CNN_ConvolutionNE16("S6_ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion", &gen_ctrl_S6_ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion,
                        -1, 1, 4, 1, 8,
                        30, 10, 1, 10,
                        KOP_CONV, 1, 3, 1, 1, 1, 1, 1, 0,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_RELU);
    
    CNN_GenControl_T gen_ctrl_S7_ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion_trans_out0;
    CNN_InitGenCtrl(&gen_ctrl_S7_ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion_trans_out0);
    CNN_SetGenCtrl(&gen_ctrl_S7_ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion_trans_out0, "ARG_DTYPE", AT_OPT_VAL(ARG_INT));
    
    // generator for ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion_trans_out0 Transpose 10x1x10 -> 10x10x1 ((1, 0))
    CNN_MatTranspose("S7_ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion_trans_out0", &gen_ctrl_S7_ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion_trans_out0, 1,
                      1, 10, 10, KOP_MATTRANSP);
    
    // generator for ARMA_30_10_Bin_All_global_average_pooling2d_Mean
    CNN_GlobalPoolAct_SQ8("S9_ARMA_30_10_Bin_All_global_average_pooling2d_Mean", 0,
                          10, 5, 2,
                          KOP_GLOBAL_AVGPOOL, KOP_NONE);
    
    
    // generator for ARMA_30_10_Bin_All_global_average_pooling2d_Mean_qout0
    CNN_Convert("S10_ARMA_30_10_Bin_All_global_average_pooling2d_Mean_qout0", 1, -1, 10, KOP_CONVERT_FP_FP_SCALE);
    
    // generator for ARMA_30_10_Bin_All_dense_MatMul
    CNN_LinearAct_NE16("S13_ARMA_30_10_Bin_All_dense_MatMul", 0,
                       -1, 1, 4, 1, 8,
                       10, 2, KOP_LINEAR, KOP_NONE);
    
    // generator for ARMA_30_10_Bin_All_dense_Softmax
    CNN_SoftMax_SQ8("S15_ARMA_30_10_Bin_All_dense_Softmax", 0, 2, KOP_SOFTMAX);
    

#define GRAPH
#ifdef GRAPH
    CreateGraph("ARMA_30_10_Bin_AllCNN",
        /* Arguments either passed or globals */
            CArgs(20,
                TCArgInfo("unsigned char * __restrict__", "Input_1", ARG_SCOPE_ARG, ARG_DIR_IN, AT_MEM_L2, AT_MEM_L2, 0),
                TCArgInfo("unsigned char * __restrict__", "Arma_30_10_bin_all_conv2d_conv2d_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("Arma_30_10_bin_all_conv2d_conv2d_weights.tensor", 1, 1, 8, 0, 90)),
                TCArgInfo("signed int * __restrict__", "Arma_30_10_bin_all_conv2d_conv2d_biases", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Arma_30_10_bin_all_conv2d_conv2d_biases.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S3_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S3_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S3_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S3_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.00130 out: 0.00130  actscale: [1] actscalen: [0] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [120] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S3_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S3_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "Arma_30_10_bin_all_conv2d_1_conv2d_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("Arma_30_10_bin_all_conv2d_1_conv2d_weights.tensor", 1, 1, 8, 0, 900)),
                TCArgInfo("signed int * __restrict__", "Arma_30_10_bin_all_conv2d_1_conv2d_biases", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Arma_30_10_bin_all_conv2d_1_conv2d_biases.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S6_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S6_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S6_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S6_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.00216 out: 0.00216  actscale: [1] actscalen: [0] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [0] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S6_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S6_Infos.tensor", 1, 1, 8, 0)),
                // no activation ACTSCALE: 0 ACTSCALEN: 0 GLOBAL_SUM_SCALE: [73] GLOBAL_SUM_SCALEN: [11]
                TCArgInfo("signed char * __restrict__", "S9_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S9_Infos.tensor", 1, 1, 8, 0)),
                // in q: -0.06<(i8-0.00)*0.00047490<0.06 out_q: 0.00<(u8-0.00)*0.00023652<0.06
                TCArgInfo("signed char * __restrict__", "S10_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S10_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "Arma_30_10_bin_all_dense_matmul_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Arma_30_10_bin_all_dense_matmul_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "Arma_30_10_bin_all_dense_matmul_biases", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Arma_30_10_bin_all_dense_matmul_biases.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S13_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S13_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S13_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S13_Mul_shift.tensor", 1, 1, 8, 0)),
                // no activation BIASN: 0 PRENORM: 0 NE16_PADVAL: [0] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S13_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S13_Infos.tensor", 1, 1, 8, 0)),
                // in: 0.00098 out: 0.00003  BIASL_SM: [5]
                TCArgInfo("signed char * __restrict__", "S15_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S15_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed short * __restrict__", "Output_1", ARG_SCOPE_ARG, ARG_DIR_OUT, AT_MEM_L2, AT_MEM_L2, 0)
            ),
        /* Locals, allocated dynamically */
        CArgs(6,
            TCArgInfo("unsigned char * __restrict__", "S3_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S6_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S7_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S9_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S10_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S13_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0)
        )
    );



    // Node S3_ARMA_30_10_Bin_All_conv2d_Conv2D_fusion inq -0.86<(u8-120.00)*0.00717856<0.97 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.00129761<0.33 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S3_ARMA_30_10_Bin_All_conv2d_Conv2D_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "Input_1", 0),
            GNodeArg(GNA_IN, "Arma_30_10_bin_all_conv2d_conv2d_weights", 0),
            GNodeArg(GNA_IN, "Arma_30_10_bin_all_conv2d_conv2d_biases", 0),
            GNodeArg(GNA_OUT, "S3_Output", 0),
            GNodeArg(GNA_IN, "S3_Mul_scale", 0),
            GNodeArg(GNA_IN, "S3_Mul_shift", 0),
            GNodeArg(GNA_IN, "S3_Infos", 0)
        )
    );
    // Node S6_ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion inq 0.00<(u8-0.00)*0.00129761<0.33 weightsq chan<(u8-128.00)*chan<chan outq -0.28<(i8-0.00)*0.00216005<0.27 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S6_ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S3_Output", 0),
            GNodeArg(GNA_IN, "Arma_30_10_bin_all_conv2d_1_conv2d_weights", 0),
            GNodeArg(GNA_IN, "Arma_30_10_bin_all_conv2d_1_conv2d_biases", 0),
            GNodeArg(GNA_OUT, "S6_Output", 0),
            GNodeArg(GNA_IN, "S6_Mul_scale", 0),
            GNodeArg(GNA_IN, "S6_Mul_shift", 0),
            GNodeArg(GNA_IN, "S6_Infos", 0)
        )
    );
    // Node ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion_trans_out0 inq -0.28<(i8-0.00)*0.00216005<0.27 outq -0.28<(i8-0.00)*0.00216005<0.27
    AddNode("S7_ARMA_30_10_Bin_All_conv2d_1_Conv2D_fusion_trans_out0",
        Bindings(2,
            GNodeArg(GNA_IN, "S6_Output", 0),
            GNodeArg(GNA_OUT, "S7_Output", 0)
        )
    );
    // Node ARMA_30_10_Bin_All_global_average_pooling2d_Mean inq -0.28<(i8-0.00)*0.00216005<0.27 outq -0.06<(i8-0.00)*0.00047490<0.06
    AddNode("S9_ARMA_30_10_Bin_All_global_average_pooling2d_Mean",
        Bindings(3,
            GNodeArg(GNA_IN, "S7_Output", 0),
            GNodeArg(GNA_OUT, "S9_Output", 0),
            GNodeArg(GNA_IN, "S9_Infos", 0)
        )
    );
    // Node ARMA_30_10_Bin_All_global_average_pooling2d_Mean_qout0 inq -0.06<(i8-0.00)*0.00047490<0.06 outq 0.00<(u8-0.00)*0.00023652<0.06
    AddNode("S10_ARMA_30_10_Bin_All_global_average_pooling2d_Mean_qout0",
        Bindings(3,
            GNodeArg(GNA_IN, "S9_Output", 0),
            GNodeArg(GNA_OUT, "S10_Output", 0),
            GNodeArg(GNA_IN, "S10_Infos", 0)
        )
    );
    // Node ARMA_30_10_Bin_All_dense_MatMul inq 0.00<(u8-0.00)*0.00023652<0.06 weightsq chan<(u8-128.00)*chan<chan outq -0.12<(i8-0.00)*0.00097656<0.12 forced
    AddNode("S13_ARMA_30_10_Bin_All_dense_MatMul",
        Bindings(7,
            GNodeArg(GNA_IN, "S10_Output", 0),
            GNodeArg(GNA_IN, "Arma_30_10_bin_all_dense_matmul_weights", 0),
            GNodeArg(GNA_IN, "Arma_30_10_bin_all_dense_matmul_biases", 0),
            GNodeArg(GNA_OUT, "S13_Output", 0),
            GNodeArg(GNA_IN, "S13_Mul_scale", 0),
            GNodeArg(GNA_IN, "S13_Mul_shift", 0),
            GNodeArg(GNA_IN, "S13_Infos", 0)
        )
    );
    // Node ARMA_30_10_Bin_All_dense_Softmax inq -0.12<(i8-0.00)*0.00097656<0.12 forced outq -1.00<(i16-0.00)*0.00003052<1.00
    AddNode("S15_ARMA_30_10_Bin_All_dense_Softmax",
        Bindings(3,
            GNodeArg(GNA_IN, "S13_Output", 0),
            GNodeArg(GNA_OUT, "Output_1", 0),
            GNodeArg(GNA_IN, "S15_Infos", 0)
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
    ARMA_30_10_Bin_AllModel(128000, 1300000, 8000000, 64*1024*1024);
    GenerateTilingCode();
    return 0;
}
