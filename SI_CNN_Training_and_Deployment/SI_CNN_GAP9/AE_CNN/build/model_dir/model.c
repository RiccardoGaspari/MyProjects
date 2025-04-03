#include <stdint.h>
#include <stdio.h>
#include "AutoTilerLib.h"
#include "CNN_Generators_SQ8.h"
#include "CNN_Generators.h"
#include "CNN_Generators_NE16.h"

#include "CNN_Copy_Generators.h"

void load_expressions_kernels() {
    LibKernelTemplate(
        "s11_kernel_args_t",
        CArgs(4,
            TCArg("unsigned int", "I0"),
            TCArg("signed char *__restrict__ ", "expr_0_in_0"),
            TCArg("signed char *__restrict__ ", "expr_0_in_1"),
            TCArg("signed char *__restrict__ ", "expr_0_out_0")
        )
    );
    
    LibKernel(
        "s11_kernel",
        CALL_PARALLEL,
        0,
        "s11_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s24_kernel_args_t",
        CArgs(4,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned char *__restrict__ ", "expr_1_in_0"),
            TCArg("unsigned char *__restrict__ ", "expr_1_in_1"),
            TCArg("unsigned char *__restrict__ ", "expr_1_out_0")
        )
    );
    
    LibKernel(
        "s24_kernel",
        CALL_PARALLEL,
        0,
        "s24_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s37_kernel_args_t",
        CArgs(4,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned char *__restrict__ ", "expr_2_in_0"),
            TCArg("unsigned char *__restrict__ ", "expr_2_in_1"),
            TCArg("unsigned char *__restrict__ ", "expr_2_out_0")
        )
    );
    
    LibKernel(
        "s37_kernel",
        CALL_PARALLEL,
        0,
        "s37_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s50_kernel_args_t",
        CArgs(4,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned char *__restrict__ ", "expr_3_in_0"),
            TCArg("unsigned char *__restrict__ ", "expr_3_in_1"),
            TCArg("unsigned char *__restrict__ ", "expr_3_out_0")
        )
    );
    
    LibKernel(
        "s50_kernel",
        CALL_PARALLEL,
        0,
        "s50_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s60_kernel_args_t",
        CArgs(4,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned char *__restrict__ ", "expr_4_in_0"),
            TCArg("unsigned char *__restrict__ ", "expr_4_in_1"),
            TCArg("unsigned char *__restrict__ ", "expr_4_out_0")
        )
    );
    
    LibKernel(
        "s60_kernel",
        CALL_PARALLEL,
        0,
        "s60_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s70_kernel_args_t",
        CArgs(4,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned char *__restrict__ ", "expr_5_in_0"),
            TCArg("unsigned char *__restrict__ ", "expr_5_in_1"),
            TCArg("unsigned char *__restrict__ ", "expr_5_out_0")
        )
    );
    
    LibKernel(
        "s70_kernel",
        CALL_PARALLEL,
        0,
        "s70_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s80_kernel_args_t",
        CArgs(4,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned char *__restrict__ ", "expr_6_in_0"),
            TCArg("unsigned char *__restrict__ ", "expr_6_in_1"),
            TCArg("unsigned char *__restrict__ ", "expr_6_out_0")
        )
    );
    
    LibKernel(
        "s80_kernel",
        CALL_PARALLEL,
        0,
        "s80_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s90_kernel_args_t",
        CArgs(4,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned char *__restrict__ ", "expr_7_in_0"),
            TCArg("unsigned char *__restrict__ ", "expr_7_in_1"),
            TCArg("unsigned char *__restrict__ ", "expr_7_out_0")
        )
    );
    
    LibKernel(
        "s90_kernel",
        CALL_PARALLEL,
        0,
        "s90_kernel_args_t",
        0
    );
}



int s11_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 512, 1) spaces: ((1,),) 
        // parametric_spaces: ((1,),) 
        // exterior_shape: (512.0,) 
        KernelIterSpace(2, IterParSpace(KER_ITER_D0, 512, 8), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(3,
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_0_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_0_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_0_out_0")
        ),
        Calls(1,
            Call("s11_kernel", LOC_D0,
                Bindings(4,
                    K_ArgPar("expr_0_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_Arg("expr_0_in_0", KER_ARG_TILE),
                    K_Arg("expr_0_in_1", KER_ARG_TILE),
                    K_Arg("expr_0_out_0", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_0_out_0 axes: (0,)
        // var: expr_0_in_0 axes: (0,)
        // var: expr_0_in_1 axes: (0,)
        KerArgs(3,
            KerArg("expr_0_out_0", KerArgSpace(1, KER_ITER_D0), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_0_out_0"),
            KerArg("expr_0_in_0",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_0_in_0"),
            KerArg("expr_0_in_1",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_0_in_1")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 512, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 1536, 0);
        AddKernelArgDimExplicit(Name, "expr_0_in_0", ARG_INT,  3, 512, 1, 1);
        AddKernelArgDimExplicit(Name, "expr_0_in_1", ARG_INT,  3, 512, 1, 1);
        AddKernelArgDimExplicit(Name, "expr_0_out_0", ARG_INT, 3, 512, 1, 1);
    }
    return (Kernel!=0);
}
int s24_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 256, 2) spaces: ((1, 2),) 
        // parametric_spaces: ((1, 2),) 
        // exterior_shape: (512.0,) 
        KernelIterSpace(2, IterParSpace(KER_ITER_D0, 512, 8), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(3,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_1_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_1_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_1_out_0")
        ),
        Calls(1,
            Call("s24_kernel", LOC_D0,
                Bindings(4,
                    K_ArgPar("expr_1_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_Arg("expr_1_in_0", KER_ARG_TILE),
                    K_Arg("expr_1_in_1", KER_ARG_TILE),
                    K_Arg("expr_1_out_0", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_1_out_0 axes: (0,)
        // var: expr_1_in_0 axes: (0,)
        // var: expr_1_in_1 axes: (0,)
        KerArgs(3,
            KerArg("expr_1_out_0", KerArgSpace(1, KER_ITER_D0), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_1_out_0"),
            KerArg("expr_1_in_0",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_1_in_0"),
            KerArg("expr_1_in_1",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_1_in_1")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 512, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 1536, 0);
        AddKernelArgDimExplicit(Name, "expr_1_in_0", ARG_INT,  3, 256, 2, 1);
        AddKernelArgDimExplicit(Name, "expr_1_in_1", ARG_INT,  3, 256, 2, 1);
        AddKernelArgDimExplicit(Name, "expr_1_out_0", ARG_INT, 3, 256, 2, 1);
    }
    return (Kernel!=0);
}
int s37_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 128, 4) spaces: ((1, 2),) 
        // parametric_spaces: ((1, 2),) 
        // exterior_shape: (512.0,) 
        KernelIterSpace(2, IterParSpace(KER_ITER_D0, 512, 8), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(3,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_2_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_2_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_2_out_0")
        ),
        Calls(1,
            Call("s37_kernel", LOC_D0,
                Bindings(4,
                    K_ArgPar("expr_2_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_Arg("expr_2_in_0", KER_ARG_TILE),
                    K_Arg("expr_2_in_1", KER_ARG_TILE),
                    K_Arg("expr_2_out_0", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_2_out_0 axes: (0,)
        // var: expr_2_in_0 axes: (0,)
        // var: expr_2_in_1 axes: (0,)
        KerArgs(3,
            KerArg("expr_2_out_0", KerArgSpace(1, KER_ITER_D0), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_2_out_0"),
            KerArg("expr_2_in_0",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_2_in_0"),
            KerArg("expr_2_in_1",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_2_in_1")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 512, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 1536, 0);
        AddKernelArgDimExplicit(Name, "expr_2_in_0", ARG_INT,  3, 128, 4, 1);
        AddKernelArgDimExplicit(Name, "expr_2_in_1", ARG_INT,  3, 128, 4, 1);
        AddKernelArgDimExplicit(Name, "expr_2_out_0", ARG_INT, 3, 128, 4, 1);
    }
    return (Kernel!=0);
}
int s50_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 64, 32) spaces: ((1, 2),) 
        // parametric_spaces: ((1, 2),) 
        // exterior_shape: (2048.0,) 
        KernelIterSpace(2, IterParSpace(KER_ITER_D0, 2048, 8), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(3,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_3_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_3_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_3_out_0")
        ),
        Calls(1,
            Call("s50_kernel", LOC_D0,
                Bindings(4,
                    K_ArgPar("expr_3_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_Arg("expr_3_in_0", KER_ARG_TILE),
                    K_Arg("expr_3_in_1", KER_ARG_TILE),
                    K_Arg("expr_3_out_0", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_3_out_0 axes: (0,)
        // var: expr_3_in_0 axes: (0,)
        // var: expr_3_in_1 axes: (0,)
        KerArgs(3,
            KerArg("expr_3_out_0", KerArgSpace(1, KER_ITER_D0), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_3_out_0"),
            KerArg("expr_3_in_0",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_3_in_0"),
            KerArg("expr_3_in_1",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_3_in_1")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 2048, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 6144, 0);
        AddKernelArgDimExplicit(Name, "expr_3_in_0", ARG_INT,  3, 64, 32, 1);
        AddKernelArgDimExplicit(Name, "expr_3_in_1", ARG_INT,  3, 64, 32, 1);
        AddKernelArgDimExplicit(Name, "expr_3_out_0", ARG_INT, 3, 64, 32, 1);
    }
    return (Kernel!=0);
}
int s60_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 32, 32) spaces: ((1, 2),) 
        // parametric_spaces: ((1, 2),) 
        // exterior_shape: (1024.0,) 
        KernelIterSpace(2, IterParSpace(KER_ITER_D0, 1024, 8), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(3,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_4_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_4_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_4_out_0")
        ),
        Calls(1,
            Call("s60_kernel", LOC_D0,
                Bindings(4,
                    K_ArgPar("expr_4_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_Arg("expr_4_in_0", KER_ARG_TILE),
                    K_Arg("expr_4_in_1", KER_ARG_TILE),
                    K_Arg("expr_4_out_0", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_4_out_0 axes: (0,)
        // var: expr_4_in_0 axes: (0,)
        // var: expr_4_in_1 axes: (0,)
        KerArgs(3,
            KerArg("expr_4_out_0", KerArgSpace(1, KER_ITER_D0), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_4_out_0"),
            KerArg("expr_4_in_0",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_4_in_0"),
            KerArg("expr_4_in_1",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_4_in_1")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 1024, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 3072, 0);
        AddKernelArgDimExplicit(Name, "expr_4_in_0", ARG_INT,  3, 32, 32, 1);
        AddKernelArgDimExplicit(Name, "expr_4_in_1", ARG_INT,  3, 32, 32, 1);
        AddKernelArgDimExplicit(Name, "expr_4_out_0", ARG_INT, 3, 32, 32, 1);
    }
    return (Kernel!=0);
}
int s70_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 64, 32) spaces: ((1, 2),) 
        // parametric_spaces: ((1, 2),) 
        // exterior_shape: (2048.0,) 
        KernelIterSpace(2, IterParSpace(KER_ITER_D0, 2048, 8), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(3,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_5_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_5_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_5_out_0")
        ),
        Calls(1,
            Call("s70_kernel", LOC_D0,
                Bindings(4,
                    K_ArgPar("expr_5_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_Arg("expr_5_in_0", KER_ARG_TILE),
                    K_Arg("expr_5_in_1", KER_ARG_TILE),
                    K_Arg("expr_5_out_0", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_5_out_0 axes: (0,)
        // var: expr_5_in_0 axes: (0,)
        // var: expr_5_in_1 axes: (0,)
        KerArgs(3,
            KerArg("expr_5_out_0", KerArgSpace(1, KER_ITER_D0), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_5_out_0"),
            KerArg("expr_5_in_0",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_5_in_0"),
            KerArg("expr_5_in_1",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_5_in_1")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 2048, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 6144, 0);
        AddKernelArgDimExplicit(Name, "expr_5_in_0", ARG_INT,  3, 64, 32, 1);
        AddKernelArgDimExplicit(Name, "expr_5_in_1", ARG_INT,  3, 64, 32, 1);
        AddKernelArgDimExplicit(Name, "expr_5_out_0", ARG_INT, 3, 64, 32, 1);
    }
    return (Kernel!=0);
}
int s80_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 128, 32) spaces: ((1, 2),) 
        // parametric_spaces: ((1, 2),) 
        // exterior_shape: (4096.0,) 
        KernelIterSpace(2, IterParSpace(KER_ITER_D0, 4096, 8), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(3,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_6_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_6_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_6_out_0")
        ),
        Calls(1,
            Call("s80_kernel", LOC_D0,
                Bindings(4,
                    K_ArgPar("expr_6_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_Arg("expr_6_in_0", KER_ARG_TILE),
                    K_Arg("expr_6_in_1", KER_ARG_TILE),
                    K_Arg("expr_6_out_0", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_6_out_0 axes: (0,)
        // var: expr_6_in_0 axes: (0,)
        // var: expr_6_in_1 axes: (0,)
        KerArgs(3,
            KerArg("expr_6_out_0", KerArgSpace(1, KER_ITER_D0), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_6_out_0"),
            KerArg("expr_6_in_0",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_6_in_0"),
            KerArg("expr_6_in_1",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_6_in_1")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 4096, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 12288, 0);
        AddKernelArgDimExplicit(Name, "expr_6_in_0", ARG_INT,  3, 128, 32, 1);
        AddKernelArgDimExplicit(Name, "expr_6_in_1", ARG_INT,  3, 128, 32, 1);
        AddKernelArgDimExplicit(Name, "expr_6_out_0", ARG_INT, 3, 128, 32, 1);
    }
    return (Kernel!=0);
}
int s90_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 256, 16) spaces: ((1, 2),) 
        // parametric_spaces: ((1, 2),) 
        // exterior_shape: (4096.0,) 
        KernelIterSpace(2, IterParSpace(KER_ITER_D0, 4096, 8), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(3,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_7_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_7_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_7_out_0")
        ),
        Calls(1,
            Call("s90_kernel", LOC_D0,
                Bindings(4,
                    K_ArgPar("expr_7_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_Arg("expr_7_in_0", KER_ARG_TILE),
                    K_Arg("expr_7_in_1", KER_ARG_TILE),
                    K_Arg("expr_7_out_0", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_7_out_0 axes: (0,)
        // var: expr_7_in_0 axes: (0,)
        // var: expr_7_in_1 axes: (0,)
        KerArgs(3,
            KerArg("expr_7_out_0", KerArgSpace(1, KER_ITER_D0), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_7_out_0"),
            KerArg("expr_7_in_0",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_7_in_0"),
            KerArg("expr_7_in_1",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_7_in_1")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 4096, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 12288, 0);
        AddKernelArgDimExplicit(Name, "expr_7_in_0", ARG_INT,  3, 256, 16, 1);
        AddKernelArgDimExplicit(Name, "expr_7_in_1", ARG_INT,  3, 256, 16, 1);
        AddKernelArgDimExplicit(Name, "expr_7_out_0", ARG_INT, 3, 256, 16, 1);
    }
    return (Kernel!=0);
}

void AE_1dcnn_RELUModel(unsigned int L1Memory, unsigned int L2Memory, unsigned int L3Memory, unsigned int L3Flash)
{
    KernelOper_T Cop = KOP_CONV;

    // SetKernelOpts(KER_OPT_NONE, KER_OPT_BUFFER_PROMOTE);
    SetSymbolDynamics();

    SetUsedFilesNames(0, 7, "at_api.h", "AE_1dcnn_RELU.h", "CNN_BasicKernels_SQ8.h", "CNN_BasicKernels.h", "CNN_BasicKernels_NE16.h", "CNN_BasicKernels_SQ8.h", "Expression_Kernels.h");
    SetGeneratedFilesNames("AE_1dcnn_RELUKernels.c", "AE_1dcnn_RELUKernels.h");
    AT_SetGraphCtrl(AT_GRAPH_MONITOR_CYCLES, AT_OPT_ON);
    AT_SetGraphCtrl(AT_GRAPH_PRODUCE_NODE_NAMES, AT_OPT_ON);
    AT_SetGraphCtrl(AT_GRAPH_PRODUCE_OPERINFOS, AT_OPT_ON);

    SetMemoryDeviceInfos(4,
        AT_MEM_L1, L1Memory, "AE_1dcnn_RELU_L1_Memory", 0, 0,
        AT_MEM_L2, L2Memory, "AE_1dcnn_RELU_L2_Memory", 0, 1,
        AT_MEM_L3_DEFAULTRAM, L3Memory, "AE_1dcnn_RELU_L3_Memory", 0, 0,
        AT_MEM_L3_DEFAULTFLASH, L3Flash, "AE_1dcnn_RELU_L3_Flash", "AE_1dcnn_RELU_L3_Flash_Const.dat", 0
    );

    LoadCNN_SQ8_Library();
    LoadCNNLibrary();
    LoadCNN_NE16_SQ8_Library();
    load_expressions_kernels();

    CNN_GenControl_T gen_ctrl_S4__encoder_conv_conv_0_backbone_backbone_0_backbone_0_0_Conv_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S4__encoder_conv_conv_0_backbone_backbone_0_backbone_0_0_Conv_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S4__encoder_conv_conv_0_backbone_backbone_0_backbone_0_0_Conv_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S4__encoder_conv_conv_0_backbone_backbone_0_backbone_0_0_Conv_fusion, "HWC", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S4__encoder_conv_conv_0_backbone_backbone_0_backbone_0_0_Conv_fusion, "INPUT_DATASIZE", AT_OPT_VAL(1));
    // generator for _encoder_conv_conv_0_backbone_backbone_0_backbone_0_0_Conv_fusion
    CNN_ConvolutionPoolAct_SQ8("S4__encoder_conv_conv_0_backbone_backbone_0_backbone_0_0_Conv_fusion", &gen_ctrl_S4__encoder_conv_conv_0_backbone_backbone_0_backbone_0_0_Conv_fusion,
                               4, 1,
                               1, 1, 512, 1,
                               KOP_CONV_DW, 3, 1, 1, 1, 1, 1, 1,
                               KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                               KOP_RELU);
    
    CNN_GenControl_T gen_ctrl_S7__encoder_conv_conv_0_backbone_backbone_1_backbone_1_0_Conv_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S7__encoder_conv_conv_0_backbone_backbone_1_backbone_1_0_Conv_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S7__encoder_conv_conv_0_backbone_backbone_1_backbone_1_0_Conv_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S7__encoder_conv_conv_0_backbone_backbone_1_backbone_1_0_Conv_fusion, "HWC", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S7__encoder_conv_conv_0_backbone_backbone_1_backbone_1_0_Conv_fusion, "INPUT_DATASIZE", AT_OPT_VAL(1));
    // generator for _encoder_conv_conv_0_backbone_backbone_1_backbone_1_0_Conv_fusion
    CNN_ConvolutionPoolAct_SQ8("S7__encoder_conv_conv_0_backbone_backbone_1_backbone_1_0_Conv_fusion", &gen_ctrl_S7__encoder_conv_conv_0_backbone_backbone_1_backbone_1_0_Conv_fusion,
                               4, 1,
                               1, 1, 512, 1,
                               KOP_CONV_DW, 3, 1, 1, 1, 1, 1, 1,
                               KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                               KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S10__encoder_conv_conv_0_projection_Conv;
    CNN_InitGenCtrl(&gen_ctrl_S10__encoder_conv_conv_0_projection_Conv);
    CNN_SetGenCtrl(&gen_ctrl_S10__encoder_conv_conv_0_projection_Conv, "HWC", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S10__encoder_conv_conv_0_projection_Conv, "INPUT_DATASIZE", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S10__encoder_conv_conv_0_projection_Conv, "OUTPUT_DATASIZE", AT_OPT_VAL(1));
    // generator for _encoder_conv_conv_0_projection_Conv
    CNN_ConvolutionPoolAct_SQ8("S10__encoder_conv_conv_0_projection_Conv", &gen_ctrl_S10__encoder_conv_conv_0_projection_Conv,
                               4, 1,
                               1, 1, 512, 1,
                               KOP_CONV_DW, 1, 1, 1, 1, 1, 1, 0,
                               KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                               KOP_NONE);
    
    
    // generator for expr_0
    s11_kernel_gen("S11_expr_0");
    
    CNN_GenControl_T gen_ctrl_S14__encoder_conv_conv_0_downsampling_Conv;
    CNN_InitGenCtrl(&gen_ctrl_S14__encoder_conv_conv_0_downsampling_Conv);
    CNN_SetGenCtrl(&gen_ctrl_S14__encoder_conv_conv_0_downsampling_Conv, "HWC", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S14__encoder_conv_conv_0_downsampling_Conv, "INPUT_DATASIZE", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S14__encoder_conv_conv_0_downsampling_Conv, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _encoder_conv_conv_0_downsampling_Conv
    CNN_ConvolutionPoolAct_SQ8("S14__encoder_conv_conv_0_downsampling_Conv", &gen_ctrl_S14__encoder_conv_conv_0_downsampling_Conv,
                               4, 1,
                               1, 1, 512, 1,
                               KOP_CONV_DW, 7, 1, 1, 1, 2, 1, -771,
                               KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                               KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S17__encoder_conv_conv_1_backbone_backbone_0_backbone_0_0_Conv_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S17__encoder_conv_conv_1_backbone_backbone_0_backbone_0_0_Conv_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S17__encoder_conv_conv_1_backbone_backbone_0_backbone_0_0_Conv_fusion, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S17__encoder_conv_conv_1_backbone_backbone_0_backbone_0_0_Conv_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S17__encoder_conv_conv_1_backbone_backbone_0_backbone_0_0_Conv_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _encoder_conv_conv_1_backbone_backbone_0_backbone_0_0_Conv_fusion
    CNN_ConvolutionNE16("S17__encoder_conv_conv_1_backbone_backbone_0_backbone_0_0_Conv_fusion", &gen_ctrl_S17__encoder_conv_conv_1_backbone_backbone_0_backbone_0_0_Conv_fusion,
                        -1, -1, 4, 1, 8,
                        1, 2, 256, 1,
                        KOP_CONV, 3, 1, 1, 1, 1, 1, 1, 66,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S20__encoder_conv_conv_1_backbone_backbone_1_backbone_1_0_Conv_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S20__encoder_conv_conv_1_backbone_backbone_1_backbone_1_0_Conv_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S20__encoder_conv_conv_1_backbone_backbone_1_backbone_1_0_Conv_fusion, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S20__encoder_conv_conv_1_backbone_backbone_1_backbone_1_0_Conv_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S20__encoder_conv_conv_1_backbone_backbone_1_backbone_1_0_Conv_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _encoder_conv_conv_1_backbone_backbone_1_backbone_1_0_Conv_fusion
    CNN_ConvolutionNE16("S20__encoder_conv_conv_1_backbone_backbone_1_backbone_1_0_Conv_fusion", &gen_ctrl_S20__encoder_conv_conv_1_backbone_backbone_1_backbone_1_0_Conv_fusion,
                        -1, -1, 4, 1, 8,
                        2, 2, 256, 1,
                        KOP_CONV, 3, 1, 1, 1, 1, 1, 1, 0,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S23__encoder_conv_conv_1_projection_Conv;
    CNN_InitGenCtrl(&gen_ctrl_S23__encoder_conv_conv_1_projection_Conv);
    CNN_SetGenCtrl(&gen_ctrl_S23__encoder_conv_conv_1_projection_Conv, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S23__encoder_conv_conv_1_projection_Conv, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _encoder_conv_conv_1_projection_Conv
    CNN_ConvolutionNE16("S23__encoder_conv_conv_1_projection_Conv", &gen_ctrl_S23__encoder_conv_conv_1_projection_Conv,
                        -1, -1, 4, 1, 8,
                        1, 2, 256, 1,
                        KOP_CONV, 1, 1, 1, 1, 1, 1, 0, 66,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    
    
    // generator for expr_1
    s24_kernel_gen("S24_expr_1");
    
    CNN_GenControl_T gen_ctrl_S27__encoder_conv_conv_1_downsampling_Conv;
    CNN_InitGenCtrl(&gen_ctrl_S27__encoder_conv_conv_1_downsampling_Conv);
    CNN_SetGenCtrl(&gen_ctrl_S27__encoder_conv_conv_1_downsampling_Conv, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S27__encoder_conv_conv_1_downsampling_Conv, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S27__encoder_conv_conv_1_downsampling_Conv, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _encoder_conv_conv_1_downsampling_Conv
    CNN_ConvolutionNE16("S27__encoder_conv_conv_1_downsampling_Conv", &gen_ctrl_S27__encoder_conv_conv_1_downsampling_Conv,
                        -1, -1, 4, 1, 8,
                        2, 2, 256, 1,
                        KOP_CONV, 7, 1, 1, 1, 2, 1, -771, 156,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S30__encoder_conv_conv_2_backbone_backbone_0_backbone_0_0_Conv_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S30__encoder_conv_conv_2_backbone_backbone_0_backbone_0_0_Conv_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S30__encoder_conv_conv_2_backbone_backbone_0_backbone_0_0_Conv_fusion, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S30__encoder_conv_conv_2_backbone_backbone_0_backbone_0_0_Conv_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S30__encoder_conv_conv_2_backbone_backbone_0_backbone_0_0_Conv_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _encoder_conv_conv_2_backbone_backbone_0_backbone_0_0_Conv_fusion
    CNN_ConvolutionNE16("S30__encoder_conv_conv_2_backbone_backbone_0_backbone_0_0_Conv_fusion", &gen_ctrl_S30__encoder_conv_conv_2_backbone_backbone_0_backbone_0_0_Conv_fusion,
                        -1, -1, 4, 1, 8,
                        2, 4, 128, 1,
                        KOP_CONV, 3, 1, 1, 1, 1, 1, 1, 220,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S33__encoder_conv_conv_2_backbone_backbone_1_backbone_1_0_Conv_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S33__encoder_conv_conv_2_backbone_backbone_1_backbone_1_0_Conv_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S33__encoder_conv_conv_2_backbone_backbone_1_backbone_1_0_Conv_fusion, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S33__encoder_conv_conv_2_backbone_backbone_1_backbone_1_0_Conv_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S33__encoder_conv_conv_2_backbone_backbone_1_backbone_1_0_Conv_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _encoder_conv_conv_2_backbone_backbone_1_backbone_1_0_Conv_fusion
    CNN_ConvolutionNE16("S33__encoder_conv_conv_2_backbone_backbone_1_backbone_1_0_Conv_fusion", &gen_ctrl_S33__encoder_conv_conv_2_backbone_backbone_1_backbone_1_0_Conv_fusion,
                        -1, -1, 4, 1, 8,
                        4, 4, 128, 1,
                        KOP_CONV, 3, 1, 1, 1, 1, 1, 1, 0,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S36__encoder_conv_conv_2_projection_Conv;
    CNN_InitGenCtrl(&gen_ctrl_S36__encoder_conv_conv_2_projection_Conv);
    CNN_SetGenCtrl(&gen_ctrl_S36__encoder_conv_conv_2_projection_Conv, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S36__encoder_conv_conv_2_projection_Conv, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _encoder_conv_conv_2_projection_Conv
    CNN_ConvolutionNE16("S36__encoder_conv_conv_2_projection_Conv", &gen_ctrl_S36__encoder_conv_conv_2_projection_Conv,
                        -1, -1, 4, 1, 8,
                        2, 4, 128, 1,
                        KOP_CONV, 1, 1, 1, 1, 1, 1, 0, 220,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    
    
    // generator for expr_2
    s37_kernel_gen("S37_expr_2");
    
    CNN_GenControl_T gen_ctrl_S40__encoder_conv_conv_2_downsampling_Conv;
    CNN_InitGenCtrl(&gen_ctrl_S40__encoder_conv_conv_2_downsampling_Conv);
    CNN_SetGenCtrl(&gen_ctrl_S40__encoder_conv_conv_2_downsampling_Conv, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S40__encoder_conv_conv_2_downsampling_Conv, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S40__encoder_conv_conv_2_downsampling_Conv, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _encoder_conv_conv_2_downsampling_Conv
    CNN_ConvolutionNE16("S40__encoder_conv_conv_2_downsampling_Conv", &gen_ctrl_S40__encoder_conv_conv_2_downsampling_Conv,
                        -1, -1, 4, 1, 8,
                        4, 4, 128, 1,
                        KOP_CONV, 7, 1, 1, 1, 2, 1, -771, 252,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S43__encoder_conv_conv_3_backbone_backbone_0_backbone_0_0_Conv_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S43__encoder_conv_conv_3_backbone_backbone_0_backbone_0_0_Conv_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S43__encoder_conv_conv_3_backbone_backbone_0_backbone_0_0_Conv_fusion, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S43__encoder_conv_conv_3_backbone_backbone_0_backbone_0_0_Conv_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S43__encoder_conv_conv_3_backbone_backbone_0_backbone_0_0_Conv_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _encoder_conv_conv_3_backbone_backbone_0_backbone_0_0_Conv_fusion
    CNN_ConvolutionNE16("S43__encoder_conv_conv_3_backbone_backbone_0_backbone_0_0_Conv_fusion", &gen_ctrl_S43__encoder_conv_conv_3_backbone_backbone_0_backbone_0_0_Conv_fusion,
                        -1, -1, 4, 1, 8,
                        4, 32, 64, 1,
                        KOP_CONV, 3, 1, 1, 1, 1, 1, 1, 255,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S46__encoder_conv_conv_3_backbone_backbone_1_backbone_1_0_Conv_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S46__encoder_conv_conv_3_backbone_backbone_1_backbone_1_0_Conv_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S46__encoder_conv_conv_3_backbone_backbone_1_backbone_1_0_Conv_fusion, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S46__encoder_conv_conv_3_backbone_backbone_1_backbone_1_0_Conv_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S46__encoder_conv_conv_3_backbone_backbone_1_backbone_1_0_Conv_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _encoder_conv_conv_3_backbone_backbone_1_backbone_1_0_Conv_fusion
    CNN_ConvolutionNE16("S46__encoder_conv_conv_3_backbone_backbone_1_backbone_1_0_Conv_fusion", &gen_ctrl_S46__encoder_conv_conv_3_backbone_backbone_1_backbone_1_0_Conv_fusion,
                        -1, -1, 4, 1, 8,
                        32, 32, 64, 1,
                        KOP_CONV, 3, 1, 1, 1, 1, 1, 1, 0,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S49__encoder_conv_conv_3_projection_Conv;
    CNN_InitGenCtrl(&gen_ctrl_S49__encoder_conv_conv_3_projection_Conv);
    CNN_SetGenCtrl(&gen_ctrl_S49__encoder_conv_conv_3_projection_Conv, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S49__encoder_conv_conv_3_projection_Conv, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _encoder_conv_conv_3_projection_Conv
    CNN_ConvolutionNE16("S49__encoder_conv_conv_3_projection_Conv", &gen_ctrl_S49__encoder_conv_conv_3_projection_Conv,
                        -1, -1, 4, 1, 8,
                        4, 32, 64, 1,
                        KOP_CONV, 1, 1, 1, 1, 1, 1, 0, 255,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    
    
    // generator for expr_3
    s50_kernel_gen("S50_expr_3");
    
    CNN_GenControl_T gen_ctrl_S53__encoder_conv_conv_3_downsampling_Conv;
    CNN_InitGenCtrl(&gen_ctrl_S53__encoder_conv_conv_3_downsampling_Conv);
    CNN_SetGenCtrl(&gen_ctrl_S53__encoder_conv_conv_3_downsampling_Conv, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S53__encoder_conv_conv_3_downsampling_Conv, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S53__encoder_conv_conv_3_downsampling_Conv, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _encoder_conv_conv_3_downsampling_Conv
    CNN_ConvolutionNE16("S53__encoder_conv_conv_3_downsampling_Conv", &gen_ctrl_S53__encoder_conv_conv_3_downsampling_Conv,
                        -1, -1, 4, 1, 8,
                        32, 32, 64, 1,
                        KOP_CONV, 7, 1, 1, 1, 2, 1, -771, 108,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S56__decoder_deconv_deconv_0_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S56__decoder_deconv_deconv_0_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S56__decoder_deconv_deconv_0_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S56__decoder_deconv_deconv_0_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S56__decoder_deconv_deconv_0_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _decoder_deconv_deconv_0_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion
    CNN_ConvolutionNE16("S56__decoder_deconv_deconv_0_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion", &gen_ctrl_S56__decoder_deconv_deconv_0_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion,
                        -1, -1, 4, 1, 8,
                        32, 32, 32, 1,
                        KOP_CONV, 3, 1, 1, 1, 1, 1, 1, 128,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S59__decoder_deconv_deconv_0_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S59__decoder_deconv_deconv_0_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S59__decoder_deconv_deconv_0_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S59__decoder_deconv_deconv_0_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S59__decoder_deconv_deconv_0_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _decoder_deconv_deconv_0_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion
    CNN_ConvolutionNE16("S59__decoder_deconv_deconv_0_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion", &gen_ctrl_S59__decoder_deconv_deconv_0_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion,
                        -1, -1, 4, 1, 8,
                        32, 32, 32, 1,
                        KOP_CONV, 3, 1, 1, 1, 1, 1, 1, 0,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    
    
    // generator for expr_4
    s60_kernel_gen("S60_expr_4");
    
    CNN_GenControl_T gen_ctrl_S63__decoder_deconv_deconv_0_upsampling_ConvTranspose;
    CNN_InitGenCtrl(&gen_ctrl_S63__decoder_deconv_deconv_0_upsampling_ConvTranspose);
    CNN_SetGenCtrl(&gen_ctrl_S63__decoder_deconv_deconv_0_upsampling_ConvTranspose, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S63__decoder_deconv_deconv_0_upsampling_ConvTranspose, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _decoder_deconv_deconv_0_upsampling_ConvTranspose
    CNN_ConvTransposedAct_NE16("S63__decoder_deconv_deconv_0_upsampling_ConvTranspose", &gen_ctrl_S63__decoder_deconv_deconv_0_upsampling_ConvTranspose,
                                /* Data Sizes: In, Out, Bias, Scale, Filter (Bits) */
                                -1, -1, 4, 1, 8,
                                /* InFeat, OutFeat, InW, InH */
                                 32, 32, 32, 1,
                                /* Conv, Fcx, Fcy, Dcx, Dcy, Scx, Scy, */
                                 KOP_TRANSPOSED_CONV, 4, 1, 1, 1, 2, 1, 118,
                                /* OutPadW, OutPadH, PadL, PadR, PadT, PadB, */
                                 0, 0, 1, 1, 0, 0,
                                 KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S66__decoder_deconv_deconv_1_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S66__decoder_deconv_deconv_1_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S66__decoder_deconv_deconv_1_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S66__decoder_deconv_deconv_1_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S66__decoder_deconv_deconv_1_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _decoder_deconv_deconv_1_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion
    CNN_ConvolutionNE16("S66__decoder_deconv_deconv_1_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion", &gen_ctrl_S66__decoder_deconv_deconv_1_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion,
                        -1, -1, 4, 1, 8,
                        32, 32, 64, 1,
                        KOP_CONV, 3, 1, 1, 1, 1, 1, 1, 138,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S69__decoder_deconv_deconv_1_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S69__decoder_deconv_deconv_1_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S69__decoder_deconv_deconv_1_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S69__decoder_deconv_deconv_1_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S69__decoder_deconv_deconv_1_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _decoder_deconv_deconv_1_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion
    CNN_ConvolutionNE16("S69__decoder_deconv_deconv_1_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion", &gen_ctrl_S69__decoder_deconv_deconv_1_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion,
                        -1, -1, 4, 1, 8,
                        32, 32, 64, 1,
                        KOP_CONV, 3, 1, 1, 1, 1, 1, 1, 0,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    
    
    // generator for expr_5
    s70_kernel_gen("S70_expr_5");
    
    CNN_GenControl_T gen_ctrl_S73__decoder_deconv_deconv_1_upsampling_ConvTranspose;
    CNN_InitGenCtrl(&gen_ctrl_S73__decoder_deconv_deconv_1_upsampling_ConvTranspose);
    CNN_SetGenCtrl(&gen_ctrl_S73__decoder_deconv_deconv_1_upsampling_ConvTranspose, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S73__decoder_deconv_deconv_1_upsampling_ConvTranspose, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _decoder_deconv_deconv_1_upsampling_ConvTranspose
    CNN_ConvTransposedAct_NE16("S73__decoder_deconv_deconv_1_upsampling_ConvTranspose", &gen_ctrl_S73__decoder_deconv_deconv_1_upsampling_ConvTranspose,
                                /* Data Sizes: In, Out, Bias, Scale, Filter (Bits) */
                                -1, -1, 4, 1, 8,
                                /* InFeat, OutFeat, InW, InH */
                                 32, 32, 64, 1,
                                /* Conv, Fcx, Fcy, Dcx, Dcy, Scx, Scy, */
                                 KOP_TRANSPOSED_CONV, 4, 1, 1, 1, 2, 1, 111,
                                /* OutPadW, OutPadH, PadL, PadR, PadT, PadB, */
                                 0, 0, 1, 1, 0, 0,
                                 KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S76__decoder_deconv_deconv_2_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S76__decoder_deconv_deconv_2_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S76__decoder_deconv_deconv_2_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S76__decoder_deconv_deconv_2_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S76__decoder_deconv_deconv_2_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _decoder_deconv_deconv_2_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion
    CNN_ConvolutionNE16("S76__decoder_deconv_deconv_2_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion", &gen_ctrl_S76__decoder_deconv_deconv_2_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion,
                        -1, -1, 4, 1, 8,
                        32, 32, 128, 1,
                        KOP_CONV, 3, 1, 1, 1, 1, 1, 1, 147,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S79__decoder_deconv_deconv_2_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S79__decoder_deconv_deconv_2_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S79__decoder_deconv_deconv_2_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S79__decoder_deconv_deconv_2_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S79__decoder_deconv_deconv_2_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _decoder_deconv_deconv_2_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion
    CNN_ConvolutionNE16("S79__decoder_deconv_deconv_2_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion", &gen_ctrl_S79__decoder_deconv_deconv_2_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion,
                        -1, -1, 4, 1, 8,
                        32, 32, 128, 1,
                        KOP_CONV, 3, 1, 1, 1, 1, 1, 1, 0,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    
    
    // generator for expr_6
    s80_kernel_gen("S80_expr_6");
    
    CNN_GenControl_T gen_ctrl_S83__decoder_deconv_deconv_2_upsampling_ConvTranspose;
    CNN_InitGenCtrl(&gen_ctrl_S83__decoder_deconv_deconv_2_upsampling_ConvTranspose);
    CNN_SetGenCtrl(&gen_ctrl_S83__decoder_deconv_deconv_2_upsampling_ConvTranspose, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S83__decoder_deconv_deconv_2_upsampling_ConvTranspose, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _decoder_deconv_deconv_2_upsampling_ConvTranspose
    CNN_ConvTransposedAct_NE16("S83__decoder_deconv_deconv_2_upsampling_ConvTranspose", &gen_ctrl_S83__decoder_deconv_deconv_2_upsampling_ConvTranspose,
                                /* Data Sizes: In, Out, Bias, Scale, Filter (Bits) */
                                -1, -1, 4, 1, 8,
                                /* InFeat, OutFeat, InW, InH */
                                 32, 16, 128, 1,
                                /* Conv, Fcx, Fcy, Dcx, Dcy, Scx, Scy, */
                                 KOP_TRANSPOSED_CONV, 4, 1, 1, 1, 2, 1, 115,
                                /* OutPadW, OutPadH, PadL, PadR, PadT, PadB, */
                                 0, 0, 1, 1, 0, 0,
                                 KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S86__decoder_deconv_deconv_3_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S86__decoder_deconv_deconv_3_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S86__decoder_deconv_deconv_3_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S86__decoder_deconv_deconv_3_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S86__decoder_deconv_deconv_3_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _decoder_deconv_deconv_3_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion
    CNN_ConvolutionNE16("S86__decoder_deconv_deconv_3_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion", &gen_ctrl_S86__decoder_deconv_deconv_3_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion,
                        -1, -1, 4, 1, 8,
                        16, 16, 256, 1,
                        KOP_CONV, 3, 1, 1, 1, 1, 1, 1, 114,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S89__decoder_deconv_deconv_3_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S89__decoder_deconv_deconv_3_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S89__decoder_deconv_deconv_3_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S89__decoder_deconv_deconv_3_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S89__decoder_deconv_deconv_3_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _decoder_deconv_deconv_3_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion
    CNN_ConvolutionNE16("S89__decoder_deconv_deconv_3_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion", &gen_ctrl_S89__decoder_deconv_deconv_3_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion,
                        -1, -1, 4, 1, 8,
                        16, 16, 256, 1,
                        KOP_CONV, 3, 1, 1, 1, 1, 1, 1, 0,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    
    
    // generator for expr_7
    s90_kernel_gen("S90_expr_7");
    
    CNN_GenControl_T gen_ctrl_S93__decoder_deconv_deconv_3_upsampling_ConvTranspose;
    CNN_InitGenCtrl(&gen_ctrl_S93__decoder_deconv_deconv_3_upsampling_ConvTranspose);
    CNN_SetGenCtrl(&gen_ctrl_S93__decoder_deconv_deconv_3_upsampling_ConvTranspose, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S93__decoder_deconv_deconv_3_upsampling_ConvTranspose, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _decoder_deconv_deconv_3_upsampling_ConvTranspose
    CNN_ConvTransposedAct_NE16("S93__decoder_deconv_deconv_3_upsampling_ConvTranspose", &gen_ctrl_S93__decoder_deconv_deconv_3_upsampling_ConvTranspose,
                                /* Data Sizes: In, Out, Bias, Scale, Filter (Bits) */
                                -1, -1, 4, 1, 8,
                                /* InFeat, OutFeat, InW, InH */
                                 16, 8, 256, 1,
                                /* Conv, Fcx, Fcy, Dcx, Dcy, Scx, Scy, */
                                 KOP_TRANSPOSED_CONV, 4, 1, 1, 1, 2, 1, 60,
                                /* OutPadW, OutPadH, PadL, PadR, PadT, PadB, */
                                 0, 0, 1, 1, 0, 0,
                                 KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S96__decoder_deconv_deconv_4_Conv;
    CNN_InitGenCtrl(&gen_ctrl_S96__decoder_deconv_deconv_4_Conv);
    CNN_SetGenCtrl(&gen_ctrl_S96__decoder_deconv_deconv_4_Conv, "ENABLEIM2COL", AT_OPT_VAL(1));
    CNN_SetGenCtrl(&gen_ctrl_S96__decoder_deconv_deconv_4_Conv, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S96__decoder_deconv_deconv_4_Conv, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _decoder_deconv_deconv_4_Conv
    CNN_ConvolutionNE16("S96__decoder_deconv_deconv_4_Conv", &gen_ctrl_S96__decoder_deconv_deconv_4_Conv,
                        -1, -1, 4, 1, 8,
                        8, 1, 512, 1,
                        KOP_CONV, 7, 1, 1, 1, 1, 1, 1, 134,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    

#define GRAPH
#ifdef GRAPH
    CreateGraph("AE_1dcnn_RELUCNN",
        /* Arguments either passed or globals */
            CArgs(147,
                TCArgInfo("signed char * __restrict__", "Input_1", ARG_SCOPE_ARG, ARG_DIR_IN, AT_MEM_L2, AT_MEM_L2, 0),
                TCArgInfo("signed char * __restrict__", "_encoder_conv_conv_0_backbone_backbone_0_backbone_0_0_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_encoder_conv_conv_0_backbone_backbone_0_backbone_0_0_conv_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "Constant_onnx__conv_212", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__conv_212.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S4_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S4_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S4_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S4_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.00835 out: 0.00835  actscale: [1] actscalen: [0] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0
                TCArgInfo("signed char * __restrict__", "S4_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S4_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "_encoder_conv_conv_0_backbone_backbone_1_backbone_1_0_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_encoder_conv_conv_0_backbone_backbone_1_backbone_1_0_conv_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "Constant_onnx__conv_215", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__conv_215.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S7_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S7_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S7_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S7_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.00392 out: 0.00392  actscale: [1] actscalen: [0] a0: [-128] b0: 0 c0: 0 BIASN: 0 PRENORM: 0
                TCArgInfo("signed char * __restrict__", "S7_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S7_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "_encoder_conv_conv_0_projection_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_encoder_conv_conv_0_projection_conv_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "Constant_encoder_conv_0_projection_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_encoder_conv_0_projection_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S10_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S10_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S10_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S10_Mul_shift.tensor", 1, 1, 8, 0)),
                // no activation BIASN: 0 PRENORM: 0
                TCArgInfo("signed char * __restrict__", "S10_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S10_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "_encoder_conv_conv_0_downsampling_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_encoder_conv_conv_0_downsampling_conv_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "Constant_encoder_conv_0_downsampling_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_encoder_conv_0_downsampling_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S14_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S14_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S14_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S14_Mul_shift.tensor", 1, 1, 8, 0)),
                // no activation BIASN: 0 PRENORM: 0
                TCArgInfo("signed char * __restrict__", "S14_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S14_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_encoder_conv_conv_1_backbone_backbone_0_backbone_0_0_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_encoder_conv_conv_1_backbone_backbone_0_backbone_0_0_conv_weights.tensor", 1, 1, 8, 0, 6)),
                TCArgInfo("signed int * __restrict__", "Constant_onnx__conv_218", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__conv_218.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S17_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S17_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S17_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S17_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.00045 out: 0.00045  actscale: [1] actscalen: [0] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [66] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S17_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S17_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_encoder_conv_conv_1_backbone_backbone_1_backbone_1_0_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_encoder_conv_conv_1_backbone_backbone_1_backbone_1_0_conv_weights.tensor", 1, 1, 8, 0, 12)),
                TCArgInfo("signed int * __restrict__", "Constant_onnx__conv_221", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__conv_221.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S20_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S20_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S20_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S20_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.00095 out: 0.00095  actscale: [1] actscalen: [0] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [0] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S20_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S20_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_encoder_conv_conv_1_projection_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_encoder_conv_conv_1_projection_conv_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "Constant_encoder_conv_1_projection_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_encoder_conv_1_projection_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S23_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S23_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S23_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S23_Mul_shift.tensor", 1, 1, 8, 0)),
                // no activation BIASN: 0 PRENORM: 0 NE16_PADVAL: [66] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S23_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S23_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_encoder_conv_conv_1_downsampling_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_encoder_conv_conv_1_downsampling_conv_weights.tensor", 1, 1, 8, 0, 28)),
                TCArgInfo("signed int * __restrict__", "Constant_encoder_conv_1_downsampling_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_encoder_conv_1_downsampling_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S27_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S27_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S27_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S27_Mul_shift.tensor", 1, 1, 8, 0)),
                // no activation BIASN: 0 PRENORM: 0 NE16_PADVAL: [156] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S27_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S27_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_encoder_conv_conv_2_backbone_backbone_0_backbone_0_0_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_encoder_conv_conv_2_backbone_backbone_0_backbone_0_0_conv_weights.tensor", 1, 1, 8, 0, 24)),
                TCArgInfo("signed int * __restrict__", "Constant_onnx__conv_224", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__conv_224.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S30_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S30_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S30_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S30_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.00011 out: 0.00011  actscale: [1] actscalen: [0] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [220] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S30_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S30_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_encoder_conv_conv_2_backbone_backbone_1_backbone_1_0_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_encoder_conv_conv_2_backbone_backbone_1_backbone_1_0_conv_weights.tensor", 1, 1, 8, 0, 48)),
                TCArgInfo("signed int * __restrict__", "Constant_onnx__conv_227", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__conv_227.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S33_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S33_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S33_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S33_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.00039 out: 0.00039  actscale: [1] actscalen: [0] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [0] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S33_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S33_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_encoder_conv_conv_2_projection_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_encoder_conv_conv_2_projection_conv_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "Constant_encoder_conv_2_projection_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_encoder_conv_2_projection_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S36_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S36_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S36_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S36_Mul_shift.tensor", 1, 1, 8, 0)),
                // no activation BIASN: 0 PRENORM: 0 NE16_PADVAL: [220] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S36_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S36_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_encoder_conv_conv_2_downsampling_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_encoder_conv_conv_2_downsampling_conv_weights.tensor", 1, 1, 8, 0, 112)),
                TCArgInfo("signed int * __restrict__", "Constant_encoder_conv_2_downsampling_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_encoder_conv_2_downsampling_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S40_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S40_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S40_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S40_Mul_shift.tensor", 1, 1, 8, 0)),
                // no activation BIASN: 0 PRENORM: 0 NE16_PADVAL: [252] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S40_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S40_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_encoder_conv_conv_3_backbone_backbone_0_backbone_0_0_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_encoder_conv_conv_3_backbone_backbone_0_backbone_0_0_conv_weights.tensor", 1, 1, 8, 0, 384)),
                TCArgInfo("signed int * __restrict__", "Constant_onnx__conv_230", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__conv_230.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S43_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S43_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S43_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S43_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.00158 out: 0.00158  actscale: [1] actscalen: [0] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [255] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S43_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S43_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_encoder_conv_conv_3_backbone_backbone_1_backbone_1_0_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_encoder_conv_conv_3_backbone_backbone_1_backbone_1_0_conv_weights.tensor", 1, 1, 8, 0, 3072)),
                TCArgInfo("signed int * __restrict__", "Constant_onnx__conv_233", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__conv_233.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S46_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S46_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S46_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S46_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.00071 out: 0.00071  actscale: [1] actscalen: [0] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [0] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S46_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S46_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_encoder_conv_conv_3_projection_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_encoder_conv_conv_3_projection_conv_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "Constant_encoder_conv_3_projection_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_encoder_conv_3_projection_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S49_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S49_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S49_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S49_Mul_shift.tensor", 1, 1, 8, 0)),
                // no activation BIASN: 0 PRENORM: 0 NE16_PADVAL: [255] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S49_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S49_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_encoder_conv_conv_3_downsampling_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_encoder_conv_conv_3_downsampling_conv_weights.tensor", 1, 1, 8, 0, 7168)),
                TCArgInfo("signed int * __restrict__", "Constant_encoder_conv_3_downsampling_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_encoder_conv_3_downsampling_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S53_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S53_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S53_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S53_Mul_shift.tensor", 1, 1, 8, 0)),
                // no activation BIASN: 0 PRENORM: 0 NE16_PADVAL: [108] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S53_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S53_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_decoder_deconv_deconv_0_backbone_backbone_0_backbone_0_0_convtranspose_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_decoder_deconv_deconv_0_backbone_backbone_0_backbone_0_0_convtranspose_weights.tensor", 1, 1, 8, 0, 3072)),
                TCArgInfo("signed int * __restrict__", "Constant_decoder_deconv_0_backbone_0_0_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_decoder_deconv_0_backbone_0_0_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S56_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S56_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S56_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S56_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.00070 out: 0.00070  actscale: [1] actscalen: [0] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [128] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S56_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S56_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_decoder_deconv_deconv_0_backbone_backbone_1_backbone_1_0_convtranspose_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_decoder_deconv_deconv_0_backbone_backbone_1_backbone_1_0_convtranspose_weights.tensor", 1, 1, 8, 0, 3072)),
                TCArgInfo("signed int * __restrict__", "Constant_decoder_deconv_0_backbone_1_0_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_decoder_deconv_0_backbone_1_0_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S59_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S59_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S59_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S59_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.00056 out: 0.00056  actscale: [1] actscalen: [0] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [0] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S59_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S59_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_decoder_deconv_deconv_0_upsampling_convtranspose_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_decoder_deconv_deconv_0_upsampling_convtranspose_weights.tensor", 1, 1, 8, 0, 4096)),
                TCArgInfo("signed int * __restrict__", "Constant_decoder_deconv_0_upsampling_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_decoder_deconv_0_upsampling_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S63_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S63_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S63_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S63_Mul_shift.tensor", 1, 1, 8, 0)),
                // no activation BIASN: 0 PRENORM: 0 NE16_PADVAL: [118] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S63_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S63_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_decoder_deconv_deconv_1_backbone_backbone_0_backbone_0_0_convtranspose_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_decoder_deconv_deconv_1_backbone_backbone_0_backbone_0_0_convtranspose_weights.tensor", 1, 1, 8, 0, 3072)),
                TCArgInfo("signed int * __restrict__", "Constant_decoder_deconv_1_backbone_0_0_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_decoder_deconv_1_backbone_0_0_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S66_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S66_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S66_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S66_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.00091 out: 0.00091  actscale: [1] actscalen: [0] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [138] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S66_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S66_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_decoder_deconv_deconv_1_backbone_backbone_1_backbone_1_0_convtranspose_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_decoder_deconv_deconv_1_backbone_backbone_1_backbone_1_0_convtranspose_weights.tensor", 1, 1, 8, 0, 3072)),
                TCArgInfo("signed int * __restrict__", "Constant_decoder_deconv_1_backbone_1_0_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_decoder_deconv_1_backbone_1_0_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S69_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S69_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S69_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S69_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.00064 out: 0.00064  actscale: [1] actscalen: [0] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [0] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S69_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S69_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_decoder_deconv_deconv_1_upsampling_convtranspose_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_decoder_deconv_deconv_1_upsampling_convtranspose_weights.tensor", 1, 1, 8, 0, 4096)),
                TCArgInfo("signed int * __restrict__", "Constant_decoder_deconv_1_upsampling_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_decoder_deconv_1_upsampling_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S73_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S73_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S73_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S73_Mul_shift.tensor", 1, 1, 8, 0)),
                // no activation BIASN: 0 PRENORM: 0 NE16_PADVAL: [111] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S73_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S73_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_decoder_deconv_deconv_2_backbone_backbone_0_backbone_0_0_convtranspose_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_decoder_deconv_deconv_2_backbone_backbone_0_backbone_0_0_convtranspose_weights.tensor", 1, 1, 8, 0, 3072)),
                TCArgInfo("signed int * __restrict__", "Constant_decoder_deconv_2_backbone_0_0_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_decoder_deconv_2_backbone_0_0_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S76_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S76_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S76_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S76_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.00066 out: 0.00066  actscale: [1] actscalen: [0] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [147] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S76_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S76_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_decoder_deconv_deconv_2_backbone_backbone_1_backbone_1_0_convtranspose_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_decoder_deconv_deconv_2_backbone_backbone_1_backbone_1_0_convtranspose_weights.tensor", 1, 1, 8, 0, 3072)),
                TCArgInfo("signed int * __restrict__", "Constant_decoder_deconv_2_backbone_1_0_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_decoder_deconv_2_backbone_1_0_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S79_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S79_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S79_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S79_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.00051 out: 0.00051  actscale: [1] actscalen: [0] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [0] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S79_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S79_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_decoder_deconv_deconv_2_upsampling_convtranspose_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_decoder_deconv_deconv_2_upsampling_convtranspose_weights.tensor", 1, 1, 8, 0, 2048)),
                TCArgInfo("signed int * __restrict__", "Constant_decoder_deconv_2_upsampling_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_decoder_deconv_2_upsampling_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S83_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S83_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S83_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S83_Mul_shift.tensor", 1, 1, 8, 0)),
                // no activation BIASN: 0 PRENORM: 0 NE16_PADVAL: [115] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S83_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S83_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_decoder_deconv_deconv_3_backbone_backbone_0_backbone_0_0_convtranspose_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_decoder_deconv_deconv_3_backbone_backbone_0_backbone_0_0_convtranspose_weights.tensor", 1, 1, 8, 0, 768)),
                TCArgInfo("signed int * __restrict__", "Constant_decoder_deconv_3_backbone_0_0_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_decoder_deconv_3_backbone_0_0_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S86_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S86_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S86_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S86_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.00054 out: 0.00054  actscale: [1] actscalen: [0] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [114] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S86_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S86_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_decoder_deconv_deconv_3_backbone_backbone_1_backbone_1_0_convtranspose_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_decoder_deconv_deconv_3_backbone_backbone_1_backbone_1_0_convtranspose_weights.tensor", 1, 1, 8, 0, 768)),
                TCArgInfo("signed int * __restrict__", "Constant_decoder_deconv_3_backbone_1_0_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_decoder_deconv_3_backbone_1_0_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S89_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S89_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S89_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S89_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.00064 out: 0.00064  actscale: [1] actscalen: [0] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [0] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S89_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S89_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_decoder_deconv_deconv_3_upsampling_convtranspose_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_decoder_deconv_deconv_3_upsampling_convtranspose_weights.tensor", 1, 1, 8, 0, 512)),
                TCArgInfo("signed int * __restrict__", "Constant_decoder_deconv_3_upsampling_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_decoder_deconv_3_upsampling_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S93_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S93_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S93_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S93_Mul_shift.tensor", 1, 1, 8, 0)),
                // no activation BIASN: 0 PRENORM: 0 NE16_PADVAL: [60] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S93_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S93_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_decoder_deconv_deconv_4_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfoExpKerSize("_decoder_deconv_deconv_4_conv_weights.tensor", 1, 1, 8, 0, 56)),
                TCArgInfo("signed int * __restrict__", "Constant_decoder_deconv_4_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_decoder_deconv_4_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S96_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S96_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S96_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S96_Mul_shift.tensor", 1, 1, 8, 0)),
                // no activation BIASN: 0 PRENORM: 0 NE16_PADVAL: [134] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S96_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S96_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "Output_1", ARG_SCOPE_ARG, ARG_DIR_OUT, AT_MEM_L2, AT_MEM_L2, 0)
            ),
        /* Locals, allocated dynamically */
        CArgs(36,
            TCArgInfo("signed char * __restrict__", "S4_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S7_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S10_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S11_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S14_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S17_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S20_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S23_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S24_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S27_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S30_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S33_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S36_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S37_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S40_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S43_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S46_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S49_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S50_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S53_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S56_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S59_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S60_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S63_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S66_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S69_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S70_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S73_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S76_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S79_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S80_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S83_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S86_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S89_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S90_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S93_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0)
        )
    );



    // Node S4__encoder_conv_conv_0_backbone_backbone_0_backbone_0_0_Conv_fusion inq -1.01<(i8-0.00)*0.00785808<1.00 forced weightsq -0.48<(i8-0.00)*0.00376900<0.48 outq -1.07<(i8-0.00)*0.00834958<1.06 forced biasesq -63602.30<(i32-0.00)*0.00002962<63602.30
    AddNode("S4__encoder_conv_conv_0_backbone_backbone_0_backbone_0_0_Conv_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "Input_1", 0),
            GNodeArg(GNA_IN, "_encoder_conv_conv_0_backbone_backbone_0_backbone_0_0_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_onnx__conv_212", 0),
            GNodeArg(GNA_OUT, "S4_Output", 0),
            GNodeArg(GNA_IN, "S4_Mul_scale", 0),
            GNodeArg(GNA_IN, "S4_Mul_shift", 0),
            GNodeArg(GNA_IN, "S4_Infos", 0)
        )
    );
    // Node S7__encoder_conv_conv_0_backbone_backbone_1_backbone_1_0_Conv_fusion inq -1.07<(i8-0.00)*0.00834958<1.06 forced weightsq -0.31<(i8-0.00)*0.00245083<0.31 outq 0.00<(i8--128.00)*0.00392157<1.00 biasesq -43944.89<(i32-0.00)*0.00002046<43944.89
    AddNode("S7__encoder_conv_conv_0_backbone_backbone_1_backbone_1_0_Conv_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S4_Output", 0),
            GNodeArg(GNA_IN, "_encoder_conv_conv_0_backbone_backbone_1_backbone_1_0_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_onnx__conv_215", 0),
            GNodeArg(GNA_OUT, "S7_Output", 0),
            GNodeArg(GNA_IN, "S7_Mul_scale", 0),
            GNodeArg(GNA_IN, "S7_Mul_shift", 0),
            GNodeArg(GNA_IN, "S7_Infos", 0)
        )
    );
    // Node S10__encoder_conv_conv_0_projection_Conv inq -1.01<(i8-0.00)*0.00785808<1.00 forced weightsq -0.02<(i8-0.00)*0.00013640<0.02 outq -0.68<(i8-127.00)*0.00265822<0.00 biasesq -2301.79<(i32-0.00)*0.00000107<2301.79
    AddNode("S10__encoder_conv_conv_0_projection_Conv",
        Bindings(7,
            GNodeArg(GNA_IN, "Input_1", 0),
            GNodeArg(GNA_IN, "_encoder_conv_conv_0_projection_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_encoder_conv_0_projection_bias", 0),
            GNodeArg(GNA_OUT, "S10_Output", 0),
            GNodeArg(GNA_IN, "S10_Mul_scale", 0),
            GNodeArg(GNA_IN, "S10_Mul_shift", 0),
            GNodeArg(GNA_IN, "S10_Infos", 0)
        )
    );
    // Node expr_0 in_qs [-0.68<(i8-127.00)*0.00265822<0.00,0.00<(i8--128.00)*0.00392157<1.00] out_qs [-0.68<(i8-0.00)*0.00529567<0.67 forced]
    AddNode("S11_expr_0",
        Bindings(3,
            GNodeArg(GNA_IN, "S10_Output", 0),
            GNodeArg(GNA_IN, "S7_Output", 0),
            GNodeArg(GNA_OUT, "S11_Output", 0)
        )
    );
    // Node S14__encoder_conv_conv_0_downsampling_Conv inq -0.68<(i8-0.00)*0.00529567<0.67 forced weightsq -0.35<(i8-0.00)*0.00277704<0.35 outq -0.15<(u8-66.00)*0.00227927<0.43 biasesq -31581.44<(i32-0.00)*0.00001471<31581.44
    AddNode("S14__encoder_conv_conv_0_downsampling_Conv",
        Bindings(7,
            GNodeArg(GNA_IN, "S11_Output", 0),
            GNodeArg(GNA_IN, "_encoder_conv_conv_0_downsampling_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_encoder_conv_0_downsampling_bias", 0),
            GNodeArg(GNA_OUT, "S14_Output", 0),
            GNodeArg(GNA_IN, "S14_Mul_scale", 0),
            GNodeArg(GNA_IN, "S14_Mul_shift", 0),
            GNodeArg(GNA_IN, "S14_Infos", 0)
        )
    );
    // Node S17__encoder_conv_conv_1_backbone_backbone_0_backbone_0_0_Conv_fusion inq -0.15<(u8-66.00)*0.00227927<0.43 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.00044567<0.11 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S17__encoder_conv_conv_1_backbone_backbone_0_backbone_0_0_Conv_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S14_Output", 0),
            GNodeArg(GNA_IN, "_encoder_conv_conv_1_backbone_backbone_0_backbone_0_0_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_onnx__conv_218", 0),
            GNodeArg(GNA_OUT, "S17_Output", 0),
            GNodeArg(GNA_IN, "S17_Mul_scale", 0),
            GNodeArg(GNA_IN, "S17_Mul_shift", 0),
            GNodeArg(GNA_IN, "S17_Infos", 0)
        )
    );
    // Node S20__encoder_conv_conv_1_backbone_backbone_1_backbone_1_0_Conv_fusion inq 0.00<(u8-0.00)*0.00044567<0.11 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.00095148<0.24 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S20__encoder_conv_conv_1_backbone_backbone_1_backbone_1_0_Conv_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S17_Output", 0),
            GNodeArg(GNA_IN, "_encoder_conv_conv_1_backbone_backbone_1_backbone_1_0_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_onnx__conv_221", 0),
            GNodeArg(GNA_OUT, "S20_Output", 0),
            GNodeArg(GNA_IN, "S20_Mul_scale", 0),
            GNodeArg(GNA_IN, "S20_Mul_shift", 0),
            GNodeArg(GNA_IN, "S20_Infos", 0)
        )
    );
    // Node S23__encoder_conv_conv_1_projection_Conv inq -0.15<(u8-66.00)*0.00227927<0.43 weightsq chan<(u8-128.00)*chan<chan outq -0.85<(u8-179.00)*0.00473216<0.36 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S23__encoder_conv_conv_1_projection_Conv",
        Bindings(7,
            GNodeArg(GNA_IN, "S14_Output", 0),
            GNodeArg(GNA_IN, "_encoder_conv_conv_1_projection_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_encoder_conv_1_projection_bias", 0),
            GNodeArg(GNA_OUT, "S23_Output", 0),
            GNodeArg(GNA_IN, "S23_Mul_scale", 0),
            GNodeArg(GNA_IN, "S23_Mul_shift", 0),
            GNodeArg(GNA_IN, "S23_Infos", 0)
        )
    );
    // Node expr_1 in_qs [-0.85<(u8-179.00)*0.00473216<0.36,0.00<(u8-0.00)*0.00095148<0.24] out_qs [-0.60<(u8-156.00)*0.00385173<0.38]
    AddNode("S24_expr_1",
        Bindings(3,
            GNodeArg(GNA_IN, "S23_Output", 0),
            GNodeArg(GNA_IN, "S20_Output", 0),
            GNodeArg(GNA_OUT, "S24_Output", 0)
        )
    );
    // Node S27__encoder_conv_conv_1_downsampling_Conv inq -0.60<(u8-156.00)*0.00385173<0.38 weightsq chan<(u8-128.00)*chan<chan outq -0.53<(u8-220.00)*0.00240915<0.08 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S27__encoder_conv_conv_1_downsampling_Conv",
        Bindings(7,
            GNodeArg(GNA_IN, "S24_Output", 0),
            GNodeArg(GNA_IN, "_encoder_conv_conv_1_downsampling_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_encoder_conv_1_downsampling_bias", 0),
            GNodeArg(GNA_OUT, "S27_Output", 0),
            GNodeArg(GNA_IN, "S27_Mul_scale", 0),
            GNodeArg(GNA_IN, "S27_Mul_shift", 0),
            GNodeArg(GNA_IN, "S27_Infos", 0)
        )
    );
    // Node S30__encoder_conv_conv_2_backbone_backbone_0_backbone_0_0_Conv_fusion inq -0.53<(u8-220.00)*0.00240915<0.08 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.00010992<0.03 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S30__encoder_conv_conv_2_backbone_backbone_0_backbone_0_0_Conv_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S27_Output", 0),
            GNodeArg(GNA_IN, "_encoder_conv_conv_2_backbone_backbone_0_backbone_0_0_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_onnx__conv_224", 0),
            GNodeArg(GNA_OUT, "S30_Output", 0),
            GNodeArg(GNA_IN, "S30_Mul_scale", 0),
            GNodeArg(GNA_IN, "S30_Mul_shift", 0),
            GNodeArg(GNA_IN, "S30_Infos", 0)
        )
    );
    // Node S33__encoder_conv_conv_2_backbone_backbone_1_backbone_1_0_Conv_fusion inq 0.00<(u8-0.00)*0.00010992<0.03 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.00038712<0.10 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S33__encoder_conv_conv_2_backbone_backbone_1_backbone_1_0_Conv_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S30_Output", 0),
            GNodeArg(GNA_IN, "_encoder_conv_conv_2_backbone_backbone_1_backbone_1_0_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_onnx__conv_227", 0),
            GNodeArg(GNA_OUT, "S33_Output", 0),
            GNodeArg(GNA_IN, "S33_Mul_scale", 0),
            GNodeArg(GNA_IN, "S33_Mul_shift", 0),
            GNodeArg(GNA_IN, "S33_Infos", 0)
        )
    );
    // Node S36__encoder_conv_conv_2_projection_Conv inq -0.53<(u8-220.00)*0.00240915<0.08 weightsq chan<(u8-128.00)*chan<chan outq -0.62<(u8-255.00)*0.00244083<0.00 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S36__encoder_conv_conv_2_projection_Conv",
        Bindings(7,
            GNodeArg(GNA_IN, "S27_Output", 0),
            GNodeArg(GNA_IN, "_encoder_conv_conv_2_projection_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_encoder_conv_2_projection_bias", 0),
            GNodeArg(GNA_OUT, "S36_Output", 0),
            GNodeArg(GNA_IN, "S36_Mul_scale", 0),
            GNodeArg(GNA_IN, "S36_Mul_shift", 0),
            GNodeArg(GNA_IN, "S36_Infos", 0)
        )
    );
    // Node expr_2 in_qs [-0.62<(u8-255.00)*0.00244083<0.00,0.00<(u8-0.00)*0.00038712<0.10] out_qs [-0.59<(u8-252.00)*0.00233837<0.01]
    AddNode("S37_expr_2",
        Bindings(3,
            GNodeArg(GNA_IN, "S36_Output", 0),
            GNodeArg(GNA_IN, "S33_Output", 0),
            GNodeArg(GNA_OUT, "S37_Output", 0)
        )
    );
    // Node S40__encoder_conv_conv_2_downsampling_Conv inq -0.59<(u8-252.00)*0.00233837<0.01 weightsq chan<(u8-128.00)*chan<chan outq -0.41<(u8-255.00)*0.00161723<0.00 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S40__encoder_conv_conv_2_downsampling_Conv",
        Bindings(7,
            GNodeArg(GNA_IN, "S37_Output", 0),
            GNodeArg(GNA_IN, "_encoder_conv_conv_2_downsampling_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_encoder_conv_2_downsampling_bias", 0),
            GNodeArg(GNA_OUT, "S40_Output", 0),
            GNodeArg(GNA_IN, "S40_Mul_scale", 0),
            GNodeArg(GNA_IN, "S40_Mul_shift", 0),
            GNodeArg(GNA_IN, "S40_Infos", 0)
        )
    );
    // Node S43__encoder_conv_conv_3_backbone_backbone_0_backbone_0_0_Conv_fusion inq -0.41<(u8-255.00)*0.00161723<0.00 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.00157719<0.40 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S43__encoder_conv_conv_3_backbone_backbone_0_backbone_0_0_Conv_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S40_Output", 0),
            GNodeArg(GNA_IN, "_encoder_conv_conv_3_backbone_backbone_0_backbone_0_0_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_onnx__conv_230", 0),
            GNodeArg(GNA_OUT, "S43_Output", 0),
            GNodeArg(GNA_IN, "S43_Mul_scale", 0),
            GNodeArg(GNA_IN, "S43_Mul_shift", 0),
            GNodeArg(GNA_IN, "S43_Infos", 0)
        )
    );
    // Node S46__encoder_conv_conv_3_backbone_backbone_1_backbone_1_0_Conv_fusion inq 0.00<(u8-0.00)*0.00157719<0.40 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.00070964<0.18 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S46__encoder_conv_conv_3_backbone_backbone_1_backbone_1_0_Conv_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S43_Output", 0),
            GNodeArg(GNA_IN, "_encoder_conv_conv_3_backbone_backbone_1_backbone_1_0_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_onnx__conv_233", 0),
            GNodeArg(GNA_OUT, "S46_Output", 0),
            GNodeArg(GNA_IN, "S46_Mul_scale", 0),
            GNodeArg(GNA_IN, "S46_Mul_shift", 0),
            GNodeArg(GNA_IN, "S46_Infos", 0)
        )
    );
    // Node S49__encoder_conv_conv_3_projection_Conv inq -0.41<(u8-255.00)*0.00161723<0.00 weightsq chan<(u8-128.00)*chan<chan outq -0.47<(u8-116.00)*0.00406415<0.56 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S49__encoder_conv_conv_3_projection_Conv",
        Bindings(7,
            GNodeArg(GNA_IN, "S40_Output", 0),
            GNodeArg(GNA_IN, "_encoder_conv_conv_3_projection_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_encoder_conv_3_projection_bias", 0),
            GNodeArg(GNA_OUT, "S49_Output", 0),
            GNodeArg(GNA_IN, "S49_Mul_scale", 0),
            GNodeArg(GNA_IN, "S49_Mul_shift", 0),
            GNodeArg(GNA_IN, "S49_Infos", 0)
        )
    );
    // Node expr_3 in_qs [-0.47<(u8-116.00)*0.00406415<0.56,0.00<(u8-0.00)*0.00070964<0.18] out_qs [-0.45<(u8-108.00)*0.00419197<0.62]
    AddNode("S50_expr_3",
        Bindings(3,
            GNodeArg(GNA_IN, "S49_Output", 0),
            GNodeArg(GNA_IN, "S46_Output", 0),
            GNodeArg(GNA_OUT, "S50_Output", 0)
        )
    );
    // Node S53__encoder_conv_conv_3_downsampling_Conv inq -0.45<(u8-108.00)*0.00419197<0.62 weightsq chan<(u8-128.00)*chan<chan outq -0.30<(u8-128.00)*0.00234143<0.30 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S53__encoder_conv_conv_3_downsampling_Conv",
        Bindings(7,
            GNodeArg(GNA_IN, "S50_Output", 0),
            GNodeArg(GNA_IN, "_encoder_conv_conv_3_downsampling_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_encoder_conv_3_downsampling_bias", 0),
            GNodeArg(GNA_OUT, "S53_Output", 0),
            GNodeArg(GNA_IN, "S53_Mul_scale", 0),
            GNodeArg(GNA_IN, "S53_Mul_shift", 0),
            GNodeArg(GNA_IN, "S53_Infos", 0)
        )
    );
    // Node S56__decoder_deconv_deconv_0_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion inq -0.30<(u8-128.00)*0.00234143<0.30 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.00070316<0.18 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S56__decoder_deconv_deconv_0_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S53_Output", 0),
            GNodeArg(GNA_IN, "_decoder_deconv_deconv_0_backbone_backbone_0_backbone_0_0_convtranspose_weights", 0),
            GNodeArg(GNA_IN, "Constant_decoder_deconv_0_backbone_0_0_bias", 0),
            GNodeArg(GNA_OUT, "S56_Output", 0),
            GNodeArg(GNA_IN, "S56_Mul_scale", 0),
            GNodeArg(GNA_IN, "S56_Mul_shift", 0),
            GNodeArg(GNA_IN, "S56_Infos", 0)
        )
    );
    // Node S59__decoder_deconv_deconv_0_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion inq 0.00<(u8-0.00)*0.00070316<0.18 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.00055840<0.14 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S59__decoder_deconv_deconv_0_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S56_Output", 0),
            GNodeArg(GNA_IN, "_decoder_deconv_deconv_0_backbone_backbone_1_backbone_1_0_convtranspose_weights", 0),
            GNodeArg(GNA_IN, "Constant_decoder_deconv_0_backbone_1_0_bias", 0),
            GNodeArg(GNA_OUT, "S59_Output", 0),
            GNodeArg(GNA_IN, "S59_Mul_scale", 0),
            GNodeArg(GNA_IN, "S59_Mul_shift", 0),
            GNodeArg(GNA_IN, "S59_Infos", 0)
        )
    );
    // Node expr_4 in_qs [0.00<(u8-0.00)*0.00055840<0.14,-0.30<(u8-128.00)*0.00234143<0.30] out_qs [-0.30<(u8-118.00)*0.00254510<0.35]
    AddNode("S60_expr_4",
        Bindings(3,
            GNodeArg(GNA_IN, "S59_Output", 0),
            GNodeArg(GNA_IN, "S53_Output", 0),
            GNodeArg(GNA_OUT, "S60_Output", 0)
        )
    );
    // Node S63__decoder_deconv_deconv_0_upsampling_ConvTranspose inq -0.30<(u8-118.00)*0.00254510<0.35 weightsq chan<(u8-128.00)*chan<chan outq -0.21<(u8-138.00)*0.00151480<0.18 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S63__decoder_deconv_deconv_0_upsampling_ConvTranspose",
        Bindings(7,
            GNodeArg(GNA_IN, "S60_Output", 0),
            GNodeArg(GNA_IN, "_decoder_deconv_deconv_0_upsampling_convtranspose_weights", 0),
            GNodeArg(GNA_IN, "Constant_decoder_deconv_0_upsampling_bias", 0),
            GNodeArg(GNA_OUT, "S63_Output", 0),
            GNodeArg(GNA_IN, "S63_Mul_scale", 0),
            GNodeArg(GNA_IN, "S63_Mul_shift", 0),
            GNodeArg(GNA_IN, "S63_Infos", 0)
        )
    );
    // Node S66__decoder_deconv_deconv_1_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion inq -0.21<(u8-138.00)*0.00151480<0.18 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.00091154<0.23 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S66__decoder_deconv_deconv_1_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S63_Output", 0),
            GNodeArg(GNA_IN, "_decoder_deconv_deconv_1_backbone_backbone_0_backbone_0_0_convtranspose_weights", 0),
            GNodeArg(GNA_IN, "Constant_decoder_deconv_1_backbone_0_0_bias", 0),
            GNodeArg(GNA_OUT, "S66_Output", 0),
            GNodeArg(GNA_IN, "S66_Mul_scale", 0),
            GNodeArg(GNA_IN, "S66_Mul_shift", 0),
            GNodeArg(GNA_IN, "S66_Infos", 0)
        )
    );
    // Node S69__decoder_deconv_deconv_1_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion inq 0.00<(u8-0.00)*0.00091154<0.23 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.00063524<0.16 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S69__decoder_deconv_deconv_1_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S66_Output", 0),
            GNodeArg(GNA_IN, "_decoder_deconv_deconv_1_backbone_backbone_1_backbone_1_0_convtranspose_weights", 0),
            GNodeArg(GNA_IN, "Constant_decoder_deconv_1_backbone_1_0_bias", 0),
            GNodeArg(GNA_OUT, "S69_Output", 0),
            GNodeArg(GNA_IN, "S69_Mul_scale", 0),
            GNodeArg(GNA_IN, "S69_Mul_shift", 0),
            GNodeArg(GNA_IN, "S69_Infos", 0)
        )
    );
    // Node expr_5 in_qs [0.00<(u8-0.00)*0.00063524<0.16,-0.21<(u8-138.00)*0.00151480<0.18] out_qs [-0.21<(u8-111.00)*0.00188717<0.27]
    AddNode("S70_expr_5",
        Bindings(3,
            GNodeArg(GNA_IN, "S69_Output", 0),
            GNodeArg(GNA_IN, "S63_Output", 0),
            GNodeArg(GNA_OUT, "S70_Output", 0)
        )
    );
    // Node S73__decoder_deconv_deconv_1_upsampling_ConvTranspose inq -0.21<(u8-111.00)*0.00188717<0.27 weightsq chan<(u8-128.00)*chan<chan outq -0.19<(u8-147.00)*0.00132005<0.14 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S73__decoder_deconv_deconv_1_upsampling_ConvTranspose",
        Bindings(7,
            GNodeArg(GNA_IN, "S70_Output", 0),
            GNodeArg(GNA_IN, "_decoder_deconv_deconv_1_upsampling_convtranspose_weights", 0),
            GNodeArg(GNA_IN, "Constant_decoder_deconv_1_upsampling_bias", 0),
            GNodeArg(GNA_OUT, "S73_Output", 0),
            GNodeArg(GNA_IN, "S73_Mul_scale", 0),
            GNodeArg(GNA_IN, "S73_Mul_shift", 0),
            GNodeArg(GNA_IN, "S73_Infos", 0)
        )
    );
    // Node S76__decoder_deconv_deconv_2_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion inq -0.19<(u8-147.00)*0.00132005<0.14 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.00066239<0.17 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S76__decoder_deconv_deconv_2_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S73_Output", 0),
            GNodeArg(GNA_IN, "_decoder_deconv_deconv_2_backbone_backbone_0_backbone_0_0_convtranspose_weights", 0),
            GNodeArg(GNA_IN, "Constant_decoder_deconv_2_backbone_0_0_bias", 0),
            GNodeArg(GNA_OUT, "S76_Output", 0),
            GNodeArg(GNA_IN, "S76_Mul_scale", 0),
            GNodeArg(GNA_IN, "S76_Mul_shift", 0),
            GNodeArg(GNA_IN, "S76_Infos", 0)
        )
    );
    // Node S79__decoder_deconv_deconv_2_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion inq 0.00<(u8-0.00)*0.00066239<0.17 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.00050997<0.13 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S79__decoder_deconv_deconv_2_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S76_Output", 0),
            GNodeArg(GNA_IN, "_decoder_deconv_deconv_2_backbone_backbone_1_backbone_1_0_convtranspose_weights", 0),
            GNodeArg(GNA_IN, "Constant_decoder_deconv_2_backbone_1_0_bias", 0),
            GNodeArg(GNA_OUT, "S79_Output", 0),
            GNodeArg(GNA_IN, "S79_Mul_scale", 0),
            GNodeArg(GNA_IN, "S79_Mul_shift", 0),
            GNodeArg(GNA_IN, "S79_Infos", 0)
        )
    );
    // Node expr_6 in_qs [0.00<(u8-0.00)*0.00050997<0.13,-0.19<(u8-147.00)*0.00132005<0.14] out_qs [-0.19<(u8-115.00)*0.00168168<0.24]
    AddNode("S80_expr_6",
        Bindings(3,
            GNodeArg(GNA_IN, "S79_Output", 0),
            GNodeArg(GNA_IN, "S73_Output", 0),
            GNodeArg(GNA_OUT, "S80_Output", 0)
        )
    );
    // Node S83__decoder_deconv_deconv_2_upsampling_ConvTranspose inq -0.19<(u8-115.00)*0.00168168<0.24 weightsq chan<(u8-128.00)*chan<chan outq -0.17<(u8-114.00)*0.00147038<0.21 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S83__decoder_deconv_deconv_2_upsampling_ConvTranspose",
        Bindings(7,
            GNodeArg(GNA_IN, "S80_Output", 0),
            GNodeArg(GNA_IN, "_decoder_deconv_deconv_2_upsampling_convtranspose_weights", 0),
            GNodeArg(GNA_IN, "Constant_decoder_deconv_2_upsampling_bias", 0),
            GNodeArg(GNA_OUT, "S83_Output", 0),
            GNodeArg(GNA_IN, "S83_Mul_scale", 0),
            GNodeArg(GNA_IN, "S83_Mul_shift", 0),
            GNodeArg(GNA_IN, "S83_Infos", 0)
        )
    );
    // Node S86__decoder_deconv_deconv_3_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion inq -0.17<(u8-114.00)*0.00147038<0.21 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.00054036<0.14 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S86__decoder_deconv_deconv_3_backbone_backbone_0_backbone_0_0_ConvTranspose_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S83_Output", 0),
            GNodeArg(GNA_IN, "_decoder_deconv_deconv_3_backbone_backbone_0_backbone_0_0_convtranspose_weights", 0),
            GNodeArg(GNA_IN, "Constant_decoder_deconv_3_backbone_0_0_bias", 0),
            GNodeArg(GNA_OUT, "S86_Output", 0),
            GNodeArg(GNA_IN, "S86_Mul_scale", 0),
            GNodeArg(GNA_IN, "S86_Mul_shift", 0),
            GNodeArg(GNA_IN, "S86_Infos", 0)
        )
    );
    // Node S89__decoder_deconv_deconv_3_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion inq 0.00<(u8-0.00)*0.00054036<0.14 weightsq chan<(u8-128.00)*chan<chan outq 0.00<(u8-0.00)*0.00063630<0.16 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S89__decoder_deconv_deconv_3_backbone_backbone_1_backbone_1_0_ConvTranspose_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S86_Output", 0),
            GNodeArg(GNA_IN, "_decoder_deconv_deconv_3_backbone_backbone_1_backbone_1_0_convtranspose_weights", 0),
            GNodeArg(GNA_IN, "Constant_decoder_deconv_3_backbone_1_0_bias", 0),
            GNodeArg(GNA_OUT, "S89_Output", 0),
            GNodeArg(GNA_IN, "S89_Mul_scale", 0),
            GNodeArg(GNA_IN, "S89_Mul_shift", 0),
            GNodeArg(GNA_IN, "S89_Infos", 0)
        )
    );
    // Node expr_7 in_qs [0.00<(u8-0.00)*0.00063630<0.16,-0.17<(u8-114.00)*0.00147038<0.21] out_qs [-0.09<(u8-60.00)*0.00147497<0.29]
    AddNode("S90_expr_7",
        Bindings(3,
            GNodeArg(GNA_IN, "S89_Output", 0),
            GNodeArg(GNA_IN, "S83_Output", 0),
            GNodeArg(GNA_OUT, "S90_Output", 0)
        )
    );
    // Node S93__decoder_deconv_deconv_3_upsampling_ConvTranspose inq -0.09<(u8-60.00)*0.00147497<0.29 weightsq chan<(u8-128.00)*chan<chan outq -0.26<(u8-134.00)*0.00191524<0.23 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S93__decoder_deconv_deconv_3_upsampling_ConvTranspose",
        Bindings(7,
            GNodeArg(GNA_IN, "S90_Output", 0),
            GNodeArg(GNA_IN, "_decoder_deconv_deconv_3_upsampling_convtranspose_weights", 0),
            GNodeArg(GNA_IN, "Constant_decoder_deconv_3_upsampling_bias", 0),
            GNodeArg(GNA_OUT, "S93_Output", 0),
            GNodeArg(GNA_IN, "S93_Mul_scale", 0),
            GNodeArg(GNA_IN, "S93_Mul_shift", 0),
            GNodeArg(GNA_IN, "S93_Infos", 0)
        )
    );
    // Node S96__decoder_deconv_deconv_4_Conv inq -0.26<(u8-134.00)*0.00191524<0.23 weightsq -0.13<(u8-128.00)*0.00104405<0.13 outq -0.13<(u8-128.00)*0.00100147<0.13 forced biasesq -4294.12<(i32-0.00)*0.00000200<4294.12
    AddNode("S96__decoder_deconv_deconv_4_Conv",
        Bindings(7,
            GNodeArg(GNA_IN, "S93_Output", 0),
            GNodeArg(GNA_IN, "_decoder_deconv_deconv_4_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_decoder_deconv_4_bias", 0),
            GNodeArg(GNA_OUT, "Output_1", 0),
            GNodeArg(GNA_IN, "S96_Mul_scale", 0),
            GNodeArg(GNA_IN, "S96_Mul_shift", 0),
            GNodeArg(GNA_IN, "S96_Infos", 0)
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
    AE_1dcnn_RELUModel(128000, 1300000, 8000000, 64*1024*1024);
    GenerateTilingCode();
    return 0;
}
